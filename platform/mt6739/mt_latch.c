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

#include <platform/mt_latch.h>

int plt_infrasys_is_timeout(const struct plt_cfg_bus_latch *self)
{
	unsigned int ctrl;

	if (!self) {
		dprintf(CRITICAL, "%s:%d: self is Null\n",
			__func__, __LINE__);
		return 0;
	}

	ctrl = readl(INFRACFG_AO_BASE +
		     self->infrasys_offsets.bus_infra_ctrl);

	return (ctrl & 0x1);
}

int plat_lastpc_dump(const struct plt_cfg_pc_latch *self, char *buf, int *wp)
{
	unsigned int i;
	unsigned int cluster, cpu_in_cluster;

	unsigned long long pc_value;
	unsigned long long fp_value;
	unsigned long long sp_value;

	unsigned long long pc_value_h;
	unsigned long long fp_value_h;
	unsigned long long sp_value_h;

	for (i = 0; i < cfg_pc_latch.nr_max_core; i++) {
		cluster = i / 4;
		cpu_in_cluster = i % 4;

		pc_value_h =
			readl(MP0_DBG_CORE0_PC_HW + (CPU_OFFSET * cpu_in_cluster) + (cluster * CLUSTER_OFFSET));
		pc_value =
			(pc_value_h << 32) |
			readl(MP0_DBG_CORE0_PC_LW + (CPU_OFFSET * cpu_in_cluster) + (cluster * CLUSTER_OFFSET));
		if (g_is_64bit_kernel) {
			fp_value_h =
				readl(MP0_DBG_CORE0_FP_ARCH64_HW + (CPU_OFFSET * cpu_in_cluster) + (cluster * CLUSTER_OFFSET));
			fp_value =
				(fp_value_h << 32) |
				readl(MP0_DBG_CORE0_FP_ARCH64_LW + (CPU_OFFSET * cpu_in_cluster) + (cluster * CLUSTER_OFFSET));
			sp_value_h =
				readl(MP0_DBG_CORE0_SP_ARCH64_HW + (CPU_OFFSET * cpu_in_cluster) + (cluster * CLUSTER_OFFSET));
			sp_value
				= (sp_value_h << 32) |
				readl(MP0_DBG_CORE0_SP_ARCH64_LW + (CPU_OFFSET * cpu_in_cluster) + (cluster * CLUSTER_OFFSET));

		}
		else {
			fp_value =
				readl(MP0_DBG_CORE0_FP_ARCH32 + (CPU_OFFSET * cpu_in_cluster) + (cluster * CLUSTER_OFFSET));
			sp_value =
				readl(MP0_DBG_CORE0_SP_ARCH32 + (CPU_OFFSET * cpu_in_cluster) + (cluster * CLUSTER_OFFSET));

		}

		/*dprintf(CRITICAL,"[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%016llx, SP = 0x%016llx\n",
				i, pc_value, fp_value, sp_value);*/
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
				"[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%016llx, SP = 0x%016llx\n",
				i, pc_value, fp_value, sp_value);
	}

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n");

	return 1;

}
int lastbus_mcusys_dump(const struct plt_cfg_bus_latch *self,
				       char *buf, int *wp)
{
	unsigned int i;
	unsigned long meter;
	unsigned long debug_raw;
	unsigned long w_counter, r_counter, c_counter;
	unsigned long mcu_base = MCUCFG_BASE;

	for (i = 0; i <= self->num_master_port-1; ++i) {
		if (self->mcusys_offsets.bus_mcu_m0 != 0xDEADBEEF)
			debug_raw = readl(mcu_base + self->mcusys_offsets.bus_mcu_m0 + 4 * i);
		else	/* not support */
			debug_raw = 0xDEADBEEF;
		meter = readl(mcu_base + self->mcusys_offsets.bus_mcu_m0_m + 4 * i);
		w_counter = meter & 0x3f;
		r_counter = (meter >> 8) & 0x3f;
		if ((w_counter != 0) || (r_counter != 0)) {

			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[LAST BUS] Master %d: ", (i * 2));
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
			               "aw_pending_counter = 0x%02lx, ar_pending_counter = 0x%02lx\n",
			               w_counter, r_counter);
			if (debug_raw != 0xDEADBEEF)
				*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "STATUS = %03lx\n", debug_raw & 0x3ff);
		}
	}

	for (i = 0; i <= self->num_slave_port-1; ++i) {
		if (self->mcusys_offsets.bus_mcu_s1 != 0xDEADBEEF)
			debug_raw = readl(mcu_base + self->mcusys_offsets.bus_mcu_s1 + 4 * i);
		else	/* not support */
			debug_raw = 0xDEADBEEF;
		meter = readl(mcu_base + self->mcusys_offsets.bus_mcu_s1_m + 4 * i);

		w_counter = meter & 0x3f;
		r_counter = (meter >> 8) & 0x3f;
		c_counter = (meter >> 16) & 0x3f;

		if ((w_counter != 0) || (r_counter != 0) || (c_counter != 0)) {
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[LAST BUS] Slave %d: ", i + 4);

			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
			               "aw_pending_counter = 0x%02lx, ar_pending_counter = 0x%02lx,",
			               w_counter, r_counter);
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, " ac_pending_counter = 0x%02lx\n", c_counter);
			if (debug_raw != 0xDEADBEEF) {
				if (i <= 2)
					*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "STATUS = %04lx\n", debug_raw & 0x3fff);
				else
					*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "STATUS = %04lx\n", debug_raw & 0xffff);
			}
		}
	}

	return 0;
}
