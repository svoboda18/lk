/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
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

#include <platform/boot_mode.h>
#include <libfdt.h>
#include <debug.h>

extern BOOT_ARGUMENT *g_boot_arg;

unsigned int get_dbg_info_base(unsigned int key)
{
	unsigned int i;

	for (i = 0; i < g_boot_arg->plat_dbg_info_max; i++) {
		if (g_boot_arg->plat_dbg_info[i].key == key)
			return g_boot_arg->plat_dbg_info[i].base;
	}

	return 0;
}

unsigned int get_dbg_info_size(unsigned int key)
{
	unsigned int i;

	for (i = 0; i < g_boot_arg->plat_dbg_info_max; i++) {
		if (g_boot_arg->plat_dbg_info[i].key == key)
			return g_boot_arg->plat_dbg_info[i].size;
	}

	return 0;
}

int set_fdt_dbg_info(void *fdt)
{
	int ret = 0;
	int offset;
	unsigned int i;
	unsigned int max;
	unsigned int key[INFO_TYPE_MAX];
	unsigned int base[INFO_TYPE_MAX];
	unsigned int size[INFO_TYPE_MAX];

	if (!fdt)
		return -1;

	offset = fdt_path_offset(fdt, "/chosen");
	if (offset < 0)
		return offset;

	if (g_boot_arg->plat_dbg_info_max > INFO_TYPE_MAX)
		dprintf(CRITICAL,"[PLAT DBG INFO] too many bootargs!\n");
	max = cpu_to_fdt32(INFO_TYPE_MAX);

	for (i = 0; i < g_boot_arg->plat_dbg_info_max; i++) {
		key[i] = cpu_to_fdt32(g_boot_arg->plat_dbg_info[i].key);
		base[i] = cpu_to_fdt32(get_dbg_info_base(g_boot_arg->plat_dbg_info[i].key));
		size[i] = cpu_to_fdt32(get_dbg_info_size(g_boot_arg->plat_dbg_info[i].key));
	}

	for (i = g_boot_arg->plat_dbg_info_max; i < INFO_TYPE_MAX; i++) {
		key[i] = cpu_to_fdt32(0);
		base[i] = cpu_to_fdt32(0);
		size[i] = cpu_to_fdt32(0);
	}

	/* pass info type max to kernel */
	ret = fdt_setprop(fdt, offset, "plat_dbg_info,max", &max, sizeof(max));
	if (ret < 0)
		return ret;

	/* pass key to kernel */
	ret = fdt_setprop(fdt, offset, "plat_dbg_info,key", key, sizeof(key));
	if (ret < 0)
		return ret;

	/* pass base address to kernel */
	ret = fdt_setprop(fdt, offset, "plat_dbg_info,base", base, sizeof(base));
	if (ret < 0)
		return ret;

	/* pass size to kernel */
	ret = fdt_setprop(fdt, offset, "plat_dbg_info,size", size, sizeof(size));

	return ret;
}

