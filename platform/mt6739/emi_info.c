/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2017. All rights reserved.
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

int set_fdt_emi_info(void *fdt)
{
	int ret = 0;
	int offset;
	unsigned int i;
	unsigned int dram_type;
	unsigned int ch_num;
	unsigned int rk_num;
	unsigned int rank_size[MAX_RK];

	if (!fdt)
		return -1;

	offset = fdt_path_offset(fdt, "/chosen");
	if (offset < 0)
		return offset;

	dram_type = cpu_to_fdt32(g_boot_arg->emi_info.dram_type);
	ch_num = cpu_to_fdt32(g_boot_arg->emi_info.ch_num);
	rk_num = cpu_to_fdt32(g_boot_arg->emi_info.rk_num);

	/* unit of rank size: 1Gb (128MB) */
	for (i = 0; i < MAX_RK; i++) {
		if (i < rk_num) {
			rank_size[i] = (g_boot_arg->emi_info.rank_size[i] >> 27) & 0xFFFFFFFF;
			rank_size[i] = cpu_to_fdt32(rank_size[i]);
		} else {
			rank_size[i] = cpu_to_fdt32(0);
		}
	}

	/* pass parameter to kernel */
	ret = fdt_setprop(fdt, offset, "emi_info,dram_type", &dram_type, sizeof(dram_type));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "emi_info,ch_num", &ch_num, sizeof(ch_num));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "emi_info,rk_num", &rk_num, sizeof(rk_num));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "emi_info,rank_size", rank_size, sizeof(rank_size));

	return ret;
}

