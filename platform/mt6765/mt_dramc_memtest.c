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

#include <reg.h>
#include <debug.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <platform.h>
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <env.h>
#include <libfdt.h>

extern BOOT_ARGUMENT *g_boot_arg;

static u32 memtest_reserved[2];
#ifdef MTK_DRAMC_RSHMOO
static u32 memtest_rank, memtest_ch, memtest_byte, memtest_txvrange, memtest_txvref, memtest_delay;
static u32 memtest_ongoing, memtest_done;
#endif

#ifdef MTK_DRAMC_RSHMOO
void dramc_memtest_set_rsv(unsigned int rank, unsigned int reserved)
{
	if (rank < 2) {
		memtest_reserved[rank] = reserved;
	}
}

void dramc_memtest_set_info(unsigned int rank, unsigned int ch, unsigned int byte,
		unsigned int txvrange, unsigned int txvref, unsigned int delay,
		unsigned int ongoing, unsigned int done)
{
	memtest_rank = rank;
	memtest_ch = ch;
	memtest_byte = byte;
	memtest_txvrange = txvrange;
	memtest_txvref = txvref;
	memtest_delay = delay;
	memtest_ongoing = ongoing;
	memtest_done = done;
}
#endif

int target_fdt_dram_memtest(void *fdt)
{
#if !defined(USER_LOAD) || defined(MTK_DRAMC_RSHMOO)
	int j, nodeoffset, parentoffset, ret;
	static dt_dram_info rsv_mem_reg_property[2];
	static dt_size_info rsv_mem_size_property[2];
	dram_info_t *orig_dram_info = &g_boot_arg->orig_dram_info;
	u64 sz;
	char name[64];

	parentoffset = fdt_path_offset(fdt, "/reserved-memory");
	if (parentoffset < 0) {
		dprintf(CRITICAL, "[DRAMC] Warning: can't find reserved-memory node in device tree\n");
		return -1;
	}

	for (j = 0; (unsigned int) j < orig_dram_info->rank_num; j++) {
		sz = 0;

		if (j >= 2)
			break;

		if (!memtest_reserved[j]) {
			snprintf(name, sizeof(name), "MTK_DRAMC_MEMTEST_R%d", j);

			if (!get_env(name))
				continue;

			memtest_reserved[j] = atoi(get_env(name));
		}

		sz = (u64) memtest_reserved[j] * 1024 * 1024;

		if (j != 0 && memory_lowpwer_prev_fixup)
			memory_lowpwer_prev_fixup((u64) (orig_dram_info->rank_info[j].start + orig_dram_info->rank_info[j].size - (4 * 1024 * 1024) - sz));

		rsv_mem_reg_property[j].start_hi = cpu_to_fdt32(orig_dram_info->rank_info[j].start>>32);
		rsv_mem_reg_property[j].start_lo = cpu_to_fdt32(orig_dram_info->rank_info[j].start);
		rsv_mem_reg_property[j].size_hi = cpu_to_fdt32(orig_dram_info->rank_info[j].size>>32);
		rsv_mem_reg_property[j].size_lo = cpu_to_fdt32(orig_dram_info->rank_info[j].size);
		rsv_mem_size_property[j].size_hi = cpu_to_fdt32(sz >> 32);
		rsv_mem_size_property[j].size_lo = cpu_to_fdt32(sz);

		snprintf(name, sizeof(name), "reserve-memory-dram_r%d_memtest", j);
		dprintf(CRITICAL, "name: %s\n", name);

		nodeoffset = fdt_add_subnode(fdt, parentoffset, name);
		if (nodeoffset < 0) {
			dprintf(CRITICAL, "Warning: can't add reserved dram rank%d memtest node in device tree\n", j);
			return -1;
		}

		ret = fdt_setprop_string(fdt, nodeoffset, "compatible", name);
		if (ret) {
			dprintf(CRITICAL, "Warning: can't add compatible  in device tree\n");
			return -1;
		}

		ret = fdt_setprop(fdt, nodeoffset, "size", &rsv_mem_size_property[j], sizeof(dt_size_info));
		ret |= fdt_setprop(fdt, nodeoffset, "alignment", &rsv_mem_size_property[j], sizeof(dt_size_info));
		dprintf(INFO," memtest rsv_mem_reg_property[%d].start_hi = 0x%08X\n", j, rsv_mem_reg_property[j].start_hi);
		dprintf(INFO," memtest rsv_mem_reg_property[%d].start_lo = 0x%08X\n", j, rsv_mem_reg_property[j].start_lo);
		dprintf(INFO," memtest rsv_mem_reg_property[%d].size_hi = 0x%08X\n", j, rsv_mem_reg_property[j].size_hi);
		dprintf(INFO," memtest rsv_mem_reg_property[%d].size_lo = 0x%08X\n", j, rsv_mem_reg_property[j].size_lo);
		ret |= fdt_setprop(fdt, nodeoffset, "alloc-ranges", &rsv_mem_reg_property[j], sizeof(dt_dram_info));
		if (ret) {
			dprintf(CRITICAL, "Warning: can't setprop size, alignment and alloc-ranges in device tree\n");
			return -1;
		}
	}
#endif
#ifdef MTK_DRAMC_RSHMOO
	snprintf(name, sizeof(name), "mediatek,dram_rshmoo_info", j);
	nodeoffset = fdt_add_subnode(fdt, 0, name);
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "Warning: can't add dram rshmoo info node in device tree\n", j);
		return -1;
	}

	ret = fdt_setprop_string(fdt, nodeoffset, "compatible", name);
	if (ret) {
		dprintf(CRITICAL, "Warning: can't add compatible in device tree\n");
		return -1;
	}

	ret = fdt_setprop_u32(fdt, nodeoffset, "rank", memtest_rank);
	if (ret) {
		dprintf(CRITICAL, "Warning: can't add rank in device tree\n");
		return -1;
	}

	ret = fdt_setprop_u32(fdt, nodeoffset, "ch", memtest_ch);
	if (ret) {
		dprintf(CRITICAL, "Warning: can't add ch in device tree\n");
		return -1;
	}

	ret = fdt_setprop_u32(fdt, nodeoffset, "byte", memtest_byte);
	if (ret) {
		dprintf(CRITICAL, "Warning: can't add byte in device tree\n");
		return -1;
	}

	ret = fdt_setprop_u32(fdt, nodeoffset, "txvrange", memtest_txvrange);
	if (ret) {
		dprintf(CRITICAL, "Warning: can't add txvrange in device tree\n");
		return -1;
	}

	ret = fdt_setprop_u32(fdt, nodeoffset, "txvref", memtest_txvref);
	if (ret) {
		dprintf(CRITICAL, "Warning: can't add txvref in device tree\n");
		return -1;
	}

	ret = fdt_setprop_u32(fdt, nodeoffset, "delay", memtest_delay);
	if (ret) {
		dprintf(CRITICAL, "Warning: can't add delay in device tree\n");
		return -1;
	}

	ret = fdt_setprop_u32(fdt, nodeoffset, "ongoing", memtest_ongoing);
	if (ret) {
		dprintf(CRITICAL, "Warning: can't add ongoing in device tree\n");
		return -1;
	}

	ret = fdt_setprop_u32(fdt, nodeoffset, "done", memtest_done);
	if (ret) {
		dprintf(CRITICAL, "Warning: can't add done in device tree\n");
		return -1;
	}
#endif

	return 0;
}
