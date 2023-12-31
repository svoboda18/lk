/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2019. All rights reserved.
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

*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <bootargs.h>
#include <platform/errno.h>
#include <string.h>
#include <pal_log.h>
#include <pal_assert.h>
#include <odm_mdtbo.h>
#include <ufdt_overlay.h>
#include <fdt_op.h>
#include <mt_boot.h>
#include <profiling.h>
#include <platform/verified_boot.h>
#include <part_interface.h>
#include <platform/mt_gpt.h>
#include <boot_info.h>

extern int mboot_common_load_part(char *part_name, char *img_name, uint32_t addr);

#define LK_PART_NAME "lk"
#define LK_DTB_IMG_NAME "lk_main_dtb"
#define LK_PARTITION_NAME_SIZE    5
static char lk_part_name[LK_PARTITION_NAME_SIZE] = LK_PART_NAME;
static uint32_t lk_dtb_inited;
static uint8_t lk_overlayed_dtb_addr[DTB_MAX_SIZE];
static void *selected_dtbo_addr;

static char *get_lk_part_name(void)
{
#ifdef MTK_AB_OTA_UPDATER
	static uint32_t lk_part_name_inited;
	const char *p_AB_suffix;

	if (!lk_part_name_inited){
		int part_name_len = strlen(lk_part_name);
		p_AB_suffix = get_suffix();

		if (p_AB_suffix) {
			strncpy((char *)&lk_part_name[part_name_len], (char *)p_AB_suffix,
					LK_PARTITION_NAME_SIZE - part_name_len);
		}
		lk_part_name[LK_PARTITION_NAME_SIZE - 1] = '\0';
		lk_part_name_inited = 1;
	}
#endif
	return lk_part_name;
}

static int load_lk_dtb(char *part_name, char *img_name, void *addr)
{
	uint32_t sec_ret;
	uint32_t vfy_time;
	int dtb_img_size;
#ifdef MTK_SECURITY_SW_SUPPORT
	unsigned int policy_entry_idx = 0;
	unsigned int img_auth_required = 0;

	policy_entry_idx = get_policy_entry_idx(part_name);
	img_auth_required = get_vfy_policy(policy_entry_idx);
	/* verify cert chain of boot img */
	if (img_auth_required) {
		vfy_time = get_timer(0);
		sec_ret = sec_img_auth_init(part_name, img_name, 0);
		if (sec_ret)
			return -1;
		dprintf(CRITICAL, "[SBC] image %s cert vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(vfy_time));
#ifdef MTK_SECURITY_ANTI_ROLLBACK
		sec_ret = sec_rollback_check(1);
		if (sec_ret) {
			dprintf(CRITICAL, "[SBC] image %s ver check fail...(0x%x)\n", img_name, sec_ret);
			return -1;
		}
#endif
	}
#endif

	dtb_img_size = mboot_common_load_part(part_name, img_name, (uint32_t)addr);
	dprintf(CRITICAL, "%s(): load %s dtb_img_size=%d\n", __func__, img_name, dtb_img_size);
	if (dtb_img_size <= 0)
		return -1;

#ifdef MTK_SECURITY_SW_SUPPORT
	if (img_auth_required) {
		vfy_time = get_timer(0);
		sec_ret = sec_img_auth(addr, dtb_img_size);
		if (sec_ret)
			return -1;
		dprintf(CRITICAL, "[SBC] %s vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(vfy_time));
	}
#endif

	return 0;
}

int32_t lk_dtb_init(void)
{
	int ret;
	void *dtbo_ptr;
	void *lk_main_dtb_ptr;
	void *lk_dtbo = NULL;
	uint32_t dtbo_size;
	uint32_t lk_main_dtb_size;
	uint32_t lk_overlayed_dtb_size;
	void *lk_overlayed_dtb_ptr = NULL;

	PROFILING_START("lk_dtb_init");

	lk_main_dtb_ptr = lk_overlayed_dtb_addr;
	/* search lk self-built-in dtb */
	PROFILING_START("load_lk_dtb");
	ret = load_lk_dtb(get_lk_part_name(), LK_DTB_IMG_NAME, lk_main_dtb_ptr);
	PROFILING_END();
	if (ret < 0)
		goto end;
	/* read dtbo image */
	PROFILING_START("load_dtbo_buffer");
	ret = load_dtbo_buffer(&dtbo_ptr, &dtbo_size);
	PROFILING_END();
	if (ret < 0) {
		if (dtbo_ptr)
			free(dtbo_ptr);
		goto end;
	}
	dprintf(CRITICAL,"dtbo_size : %u\n", dtbo_size);
	PROFILING_START("dtb_overlay");
	set_dtbo_load_addr((uint32_t)dtbo_ptr);
	set_dtbo_img_size(dtbo_size);
	lk_dtbo = malloc(dtbo_size);
	if (lk_dtbo == NULL) {
		ret = -1;
		goto end;
	}
	selected_dtbo_addr = dtbo_ptr;
	memcpy(lk_dtbo, dtbo_ptr, dtbo_size);
	lk_main_dtb_size = fdt_totalsize(lk_main_dtb_ptr);
	ret = dtb_overlay(lk_main_dtb_ptr, lk_main_dtb_size, lk_dtbo, dtbo_size,
		&lk_overlayed_dtb_ptr, DTB_MAX_SIZE);
	assert(ret == 0);
	if (ret < 0)
		goto end;
	lk_overlayed_dtb_size = fdt_totalsize(lk_overlayed_dtb_ptr);
	if (lk_overlayed_dtb_size > DTB_MAX_SIZE) {
		panic("lk_overlayed_dtb_size is too large:%u\n", lk_overlayed_dtb_size);
	}
	memcpy(lk_overlayed_dtb_addr, lk_overlayed_dtb_ptr, lk_overlayed_dtb_size);

	if (dtb_dconfig_overlay(lk_overlayed_dtb_addr) == FALSE) {
		panic("dconfig DT overlay failed, system not bootable\n");
	}

	lk_dtb_inited = 1;
	PROFILING_END();
end:
	if (lk_overlayed_dtb_ptr)
		free(lk_overlayed_dtb_ptr);
	if (lk_dtbo)
		free(lk_dtbo);
	PROFILING_END();
	return ret;
}

void *get_lk_overlayed_dtb(void)
{
	if (lk_dtb_inited == 0)
		panic("LK driver's overlayed dtb is not initialized!\n");

	return (void *)lk_overlayed_dtb_addr;
}
