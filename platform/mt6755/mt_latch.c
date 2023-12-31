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
#include <latch.h>
#include <debug.h>
#include <mt_reg_base.h>

int plat_lastpc_dump(const struct plt_cfg_pc_latch *self, char *buf, int *wp)
{
	unsigned int i, cpu_in_cluster = 0, cluster, addr;
	unsigned long long pc_value_h, fp_value_h, sp_value_h;
	unsigned long long pc_value, fp_value, sp_value;

	for (i = 0; i < self->nr_max_core; i++) {
		cluster = i / 4;
		cpu_in_cluster = i % 4;
		addr = MCUCFG_BASE + 0x410 + (cpu_in_cluster << 5) + (0x100 * cluster);

		if (g_is_64bit_kernel) {
			pc_value_h = readl(addr + 0x04);
			pc_value   = readl(addr + 0x00) | (pc_value_h << 32);
			fp_value_h = readl(addr + 0x14);
			fp_value   = readl(addr + 0x10) | (fp_value_h << 32);
			sp_value_h = readl(addr + 0x1C);
			sp_value   = readl(addr + 0x18) | (sp_value_h << 32);

		} else {
			pc_value = readl(addr + 0x00);
			fp_value = readl(addr + 0x08);
			sp_value = readl(addr + 0x0C);
		}

		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
				"[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%016llx, SP = 0x%016llx\n",
				i, pc_value, fp_value, sp_value);
	}

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n");
	return 1;
}
