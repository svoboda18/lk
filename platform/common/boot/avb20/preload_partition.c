/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2015. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */
#include <pal_typedefs.h>
#include <pal_log.h>
#include <part_interface.h>
#include <preload_partition.h>
#include <string.h>

struct preload_part_t g_preload_part[MAX_PRELOAD_PART_ENTRY_NUM];
uint32_t g_preload_part_entry_num = 0;
uint32_t g_preload_part_init = 0;

static uint32_t name_compare(const char *name1, char *name2)
{
	if (strlen(name1) != strlen(name2))
		return 0xffffffff;

	return strcmp(name1, name2);
}

uint32_t preload_partition(const char *part_name, uint32_t load_addr)
{
	uint32_t ret = 0x0;
	ssize_t len;
	uint64_t part_sz;
	uint32_t i;

	if (g_preload_part_init == 0) {
		memset(g_preload_part,
				0x0,
				sizeof(struct preload_part_t) * MAX_PRELOAD_PART_ENTRY_NUM);
		g_preload_part_entry_num = 0;
		g_preload_part_init = 1;
	}

	if (g_preload_part_entry_num == MAX_PRELOAD_PART_ENTRY_NUM)
		return 0x1;

	if (partition_exists(part_name))
		return 0x2;

	/* search for entry in table, if it's done, then it's preloaded before */
	for (i = 0; i < g_preload_part_entry_num; i++) {
		if (0 == name_compare(part_name, g_preload_part[i].name) &&
		g_preload_part[i].status == PRELOAD_STATUS_OK)
			return ret;
	}

	part_sz = partition_get_size_by_name(part_name);
	if (part_sz == 0xffffffff)
		return 0x3;

	/* partition_read supports 32 bit load address now */
	if (load_addr > 0xffffffff)
		return 0x4;

	len = partition_read(part_name,
			0x0,
			(uint8_t *)((uint32_t)load_addr),
			(size_t)part_sz);
	if ((size_t)part_sz != (size_t)len)
		return 0x5;

	if (strlen(part_name) > MAX_PRELOAD_PART_NAME_SZ - 1)
		return 0x6;

	strcpy(g_preload_part[g_preload_part_entry_num].name, part_name);
	g_preload_part[g_preload_part_entry_num].status = PRELOAD_STATUS_OK;
	g_preload_part[g_preload_part_entry_num].load_addr = load_addr;
	g_preload_part[g_preload_part_entry_num].load_sz = part_sz;
	g_preload_part_entry_num++;

	return ret;
}

uint32_t get_preload_partition_addr_sz(const char *part_name, uint32_t *load_addr, uint32_t *load_sz)
{
	uint32_t ret = 0;
	uint32_t i;

	if (part_name == NULL)
		return 0x1;

	if (load_addr == NULL)
		return 0x2;

	if (load_sz == NULL)
		return 0x3;

	*load_addr = 0xffffffff;
	*load_sz = 0;

	for (i = 0; i < g_preload_part_entry_num; i++) {
		if (0 == name_compare(part_name, g_preload_part[i].name) &&
		g_preload_part[i].status == PRELOAD_STATUS_OK) {
			*load_addr = g_preload_part[i].load_addr;
			*load_sz = g_preload_part[i].load_sz;
			break;
		}
	}

	if (*load_addr == 0xffffffff || *load_sz == 0)
		ret = 0x4;

	return ret;
}

#ifdef PRELOAD_PARTITION_UT
void preload_partition_test(void)
{
	uint32_t ret = 0;
	uint32_t i;
	const char *part_list[] = {"boot", "a", "boot", "b"};
	uint32_t load_addr_list[] = {0x0, 0x1, 0x2, 0x3};
	uint32_t part_list_sz = 0;
	uint32_t load_addr_list_sz = 0;

	pal_log_err("[preload_partition_test] start\n");

	load_addr_list[0] = (uint64_t)target_get_scratch_address();

	part_list_sz = sizeof(part_list) / sizeof(char *);
	load_addr_list_sz = sizeof(load_addr_list) / sizeof(uint64_t);
	if (part_list_sz != load_addr_list_sz) {
		pal_log_err("[preload_partition_test] inconsistent setting\n");
		return;
	}

	for (i = 0; i < part_list_sz; i++) {
		ret = preload_partition(part_list[i], load_addr_list[i]);
		pal_log_err("[preload_partition_test] %s, 0x%x, ret = 0x%x\n",
			part_list[i], (uint32_t)load_addr_list[i], ret);
	}

	for (i = 0; i < g_preload_part_entry_num; i++) {
		pal_log_err("[%x] name: %s\n", i, g_preload_part[i].name);
		pal_log_err("[%x] status: 0x%x\n", i, g_preload_part[i].status);
		pal_log_err("[%x] load_addr: 0x%x\n", i, (uint32_t)g_preload_part[i].load_addr);
		pal_log_err("[%x] load_sz: 0x%x\n", i, (uint32_t)g_preload_part[i].load_sz);
	}

	pal_log_err("[preload_partition_test] end\n");

	return;
}
#endif

