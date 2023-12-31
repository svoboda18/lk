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
*/
#include <reg.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/sync_write.h>
#include <plat_debug_interface.h>
#include <latch.h>
#include "utils.h"
#include "dfd.h"

#include <debug.h>

static struct plt_cfg_cache_latch cfg_cache_latch;

static int default_lastpc_dump(const struct plt_cfg_pc_latch *self, char *buf, int *wp)
{
	unsigned int i, cpu_in_cluster = 0, cluster_id;
	unsigned int lastpc_valid_before_reboot = 1;
	unsigned long long pc_value_h, fp_value_h, sp_value_h;
	unsigned long long pc_value, fp_value, sp_value;
	unsigned long dbg_ctrl_base, dbg_flag_base;
	unsigned long cpu_power_status = 0;
	unsigned long plat_sram_flag0;

	/* mcusys registers would be corrupted by DFD */
	if (dfd_internal_dump_before_reboot()) {
		*wp += dfd_internal_dump_get_decoded_lastpc(buf + *wp, LATCH_BUF_LENGTH - *wp);
		return 1;
	}

	if (self->plat_sram_flag0) {
		/* must check lastpc_valid_before_reboot */
		plat_sram_flag0 = readl(self->plat_sram_flag0);
		lastpc_valid_before_reboot = extract_n2mbits(plat_sram_flag0, 1, 1);
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
		               "plat_sram_flag0 = 0x%lx\n(lastpc_valid=%x, lastpc_valid_before_reboot=%x)\n\n",
		               plat_sram_flag0, extract_n2mbits(plat_sram_flag0, 0, 0),
		               lastpc_valid_before_reboot);
	}

	/* get the power status information */
	cpu_power_status = plt_get_cpu_power_status_at_wdt();
	for (i = 0; i <= self->nr_max_core-1; ++i) {
		/* if lastpc_valid_before_reboot is not 1 --> only dump CPU0, skip others */
		if (lastpc_valid_before_reboot != 1 && i >= 1) {
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
			               "[LAST PC] CORE_%d PC = 0x0, FP = 0x0, SP = 0x0\n", i);
			continue;
		}

		/* if CPUX is not powered on before reboot --> skip */
		if (extract_n2mbits(cpu_power_status, i, i) == 0) {
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
			               "[LAST PC] CORE_%d PC = 0x0, FP = 0x0, SP = 0x0\n", i);
			continue;
		}

		cluster_id = plt_get_cluster_id(i, &cpu_in_cluster);
		if (cluster_id == 0) {
			/* MP0 */
			dbg_ctrl_base = MCUCFG_BASE + self->mp0_dbg_ctrl;
			dbg_flag_base = MCUCFG_BASE + self->mp0_dbg_flag;
		} else if (cluster_id == 1) {
			/* MP1 */
			dbg_ctrl_base = MCUCFG_BASE + self->mp1_dbg_ctrl;
			dbg_flag_base = MCUCFG_BASE + self->mp1_dbg_flag;
		} else
			continue;

		writel((cpu_in_cluster << 4) | 1, dbg_ctrl_base);
		pc_value_h = readl(dbg_flag_base);
		writel((cpu_in_cluster << 4) | 0, dbg_ctrl_base);
		pc_value = (pc_value_h << 32) | readl(dbg_flag_base);

		/* TODO: query kernel symbol */
		/* get the 64bit/32bit kernel information from bootopt */
		if (g_is_64bit_kernel) {
			writel((cpu_in_cluster << 4) | 5, dbg_ctrl_base);
			fp_value_h = readl(dbg_flag_base);
			writel((cpu_in_cluster << 4) | 4, dbg_ctrl_base);
			fp_value = (fp_value_h << 32) | readl(dbg_flag_base);

			writel((cpu_in_cluster << 4) | 7, dbg_ctrl_base);
			sp_value_h = readl(dbg_flag_base);
			writel((cpu_in_cluster << 4) | 6, dbg_ctrl_base);
			sp_value = (sp_value_h << 32) | readl(dbg_flag_base);

			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
			               "[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%016llx, SP = 0x%016llx\n",
			               i, pc_value, fp_value, sp_value);
		} else {
			writel((cpu_in_cluster << 4) | 2, dbg_ctrl_base);
			fp_value = readl(dbg_flag_base);

			writel((cpu_in_cluster << 4) | 3, dbg_ctrl_base);
			sp_value = readl(dbg_flag_base);

			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
			               "[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%08llx, SP = 0x%08llx\n",
			               i, pc_value, fp_value, sp_value);
		}
	}

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n");
	return 1;
}

int default_lastpc_dump_v2(const struct plt_cfg_pc_latch *self, char *buf, int *wp)
{
	unsigned int i;
	unsigned long long pc_value_h, fp_value_h, sp_value_h;
	unsigned long long pc_value, fp_value, sp_value;
	unsigned long anake_core_dbg_sel, anake_core_dbg_mon;
	unsigned long cpu_power_status = 0;

	/* mcusys registers would be corrupted by DFD */
	if (dfd_internal_dump_before_reboot()) {
		*wp += dfd_internal_dump_get_decoded_lastpc(buf + *wp, LATCH_BUF_LENGTH - *wp);
		return 1;
	}

	/* get the power status information */
	cpu_power_status = plt_get_cpu_power_status_at_wdt();
	for (i = 0; i <= self->nr_max_core - self->nr_max_big_core - 1; ++i) {
		/* if CPUX is not powered on before reboot --> skip */
		if (extract_n2mbits(cpu_power_status, i, i) == 0) {
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
			               "[LAST PC] CORE_%d PC = 0x0, FP = 0x0, SP = 0x0\n", i);
			continue;
		}

		anake_core_dbg_sel = MCUCFG_BASE + self->anake_core_dbg_sel + i * 0x800;
		anake_core_dbg_mon = MCUCFG_BASE + self->anake_core_dbg_mon + i * 0x800;

		writel(0xd, anake_core_dbg_sel);
		pc_value_h = readl(anake_core_dbg_mon);
		writel(0xc, anake_core_dbg_sel);
		pc_value = (pc_value_h << 32) | readl(anake_core_dbg_mon);

		/* get the 64bit/32bit kernel information from bootopt */
		if (g_is_64bit_kernel) {
			writel(0x9, anake_core_dbg_sel);
			fp_value_h = readl(anake_core_dbg_mon);
			writel(0x8, anake_core_dbg_sel);
			fp_value = (fp_value_h << 32) | readl(anake_core_dbg_mon);

			writel(0xb, anake_core_dbg_sel);
			sp_value_h = readl(anake_core_dbg_mon);
			writel(0xa, anake_core_dbg_sel);
			sp_value = (sp_value_h << 32) | readl(anake_core_dbg_mon);

			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
			               "[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%016llx, SP = 0x%016llx\n",
			               i, pc_value, fp_value, sp_value);
		} else {
			writel(0x8, anake_core_dbg_sel);
			fp_value = readl(anake_core_dbg_mon);

			writel(0xa, anake_core_dbg_sel);
			sp_value = readl(anake_core_dbg_mon);

			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
			               "[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%08llx, SP = 0x%08llx\n",
			               i, pc_value, fp_value, sp_value);
		}
	}

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n");
	return 1;
}

static int lastpc_dump(char *buf, int *wp)
{
	if (buf == NULL || wp == NULL)
		return -1;

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n*************************** lastpc ***************************\n");

	if (cfg_pc_latch.dump) {
		cfg_pc_latch.dump(&cfg_pc_latch, buf, wp);
	} else {
		if (cfg_pc_latch.version == LASTPC_V2)
			default_lastpc_dump_v2(&cfg_pc_latch, buf, wp);
		else
			default_lastpc_dump(&cfg_pc_latch, buf, wp);
	}

	return 1;
}

static int circular_buffer_dump(char *buf, int *wp)
{
	unsigned int i, j, cpuid;
	unsigned int lastpc_valid_before_reboot = 1;
	unsigned long addr;
	unsigned long plat_sram_flag0;
	unsigned long cpu_power_status = 0;
	unsigned long long pc, pc_h;

	if (buf == NULL || wp == NULL)
		return -1;

	if (cfg_pc_latch.nr_max_big_core == 0)
		return 0;

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
	               "\n*************************** circular buffer ***************************\n");

	if (cfg_pc_latch.plat_sram_flag0) {
		/* if lastpc_valid_before_reboot is 0 => circular buffer is invalid */
		plat_sram_flag0 = readl(cfg_pc_latch.plat_sram_flag0);
		lastpc_valid_before_reboot = extract_n2mbits(plat_sram_flag0, 1, 1);
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
		               "plat_sram_flag0 = 0x%lx\n(lastpc_valid=%x, lastpc_valid_before_reboot=%x)\n\n",
		               plat_sram_flag0, extract_n2mbits(plat_sram_flag0, 0, 0),
		               lastpc_valid_before_reboot);
	}

	if (lastpc_valid_before_reboot == 0) {
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "lastpc_valid_before_reboot is 0 => circular buffer is invalid\n\n");
		return 1;
	}

	/* get the power status information */
	cpu_power_status = plt_get_cpu_power_status_at_wdt();

	if (circular_buffer_op.unlock)
		circular_buffer_op.unlock();

	for (i = 0; i < cfg_pc_latch.nr_max_big_core; ++i) {
		cpuid = cfg_big_core[i].cpuid;
		if (extract_n2mbits(cpu_power_status, cpuid, cpuid) == 0)
			continue;

		addr = cfg_big_core[i].circular_buffer_addr;
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[CIRCULAR BUFFER: CORE_%d]\n", cpuid);
		for (j = 0; j <= cfg_big_core[i].nr_circular_buffer_entry-1; ++j) {
			if (cfg_pc_latch.version == LASTPC_V2) {
#ifdef MTK_SMC_ID_MGMT
				pc_h = mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_LASTPC_SMC_READ_ENTRY, cpuid, (j*8) + 4, 0);
				pc = (pc_h << 32) | mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_LASTPC_SMC_READ_ENTRY, cpuid, (j*8), 0);
#else
				pc_h = mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_LASTPC_SMC_READ_ENTRY, cpuid, (j*8) + 4);
				pc = (pc_h << 32) | mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_LASTPC_SMC_READ_ENTRY, cpuid, (j*8));
#endif
			} else {
				pc_h = readl(addr + (j*8) + 4);
				pc = (pc_h << 32) | readl(addr + (j*8));
			}
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "0x%016llx\n", pc);
		}
	}

	if (circular_buffer_op.lock)
		circular_buffer_op.lock();

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n");
	return 1;
}

static int default_lastbus_mcusys_dump(const struct plt_cfg_bus_latch *self,
				       char *buf, int *wp)
{
	unsigned int i;
	unsigned long meter;
	unsigned long debug_raw;
	unsigned long w_counter, r_counter, c_counter;
	unsigned long mcu_base = MCUCFG_BASE;

	/* mcusys registers would be corrupted by DFD */
	if (!dfd_internal_dump_before_reboot()) {
		for (i = 0; i <= self->num_master_port-1; ++i) {
			debug_raw = readl(mcu_base + self->mcusys_offsets.bus_mcu_m0 + 4 * i);
			meter = readl(mcu_base + self->mcusys_offsets.bus_mcu_m0_m + 4 * i);
			w_counter = meter & 0x3f;
			r_counter = (meter >> 8) & 0x3f;
			if ((w_counter != 0) || (r_counter != 0)) {

				*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[MCUSYS LAST BUS] Master %d: ", i);
				*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
				               "aw_pending_counter = 0x%02lx, ar_pending_counter = 0x%02lx\n",
				               w_counter, r_counter);
				*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "STATUS = %03lx\n", debug_raw & 0x3ff);
			}
		}

		for (i = 1; i <= self->num_slave_port-1; ++i) {
			debug_raw = readl(mcu_base + self->mcusys_offsets.bus_mcu_s1 + 4 * (i-1));
			meter = readl(mcu_base + self->mcusys_offsets.bus_mcu_s1_m + 4 * (i-1));

			w_counter = meter & 0x3f;
			r_counter = (meter >> 8) & 0x3f;
			c_counter = (meter >> 16) & 0x3f;

			if ((w_counter != 0) || (r_counter != 0) || (c_counter != 0)) {
				*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[MCUSYS LAST BUS] Slave %d: ", i);

				*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
				               "aw_pending_counter = 0x%02lx, ar_pending_counter = 0x%02lx,",
				               w_counter, r_counter);
				*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, " ac_pending_counter = 0x%02lx\n", c_counter);
				if (i <= 2)
					*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "STATUS = %04lx\n", debug_raw & 0x3fff);
				else
					*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "STATUS = %04lx\n", debug_raw & 0xffff);
			}
		}
	}else {
		*wp += sprintf(buf + *wp, "DFD triggered\nPlease refer to dfd post-processing result for MCUSYS last bus\n");
	}

	return 0;
}

static int default_lastbus_perisys_dump(const struct plt_cfg_bus_latch *self,
					char *buf, int *wp)
{
	unsigned int i;
	unsigned long peri_base = PERICFG_BASE;

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[LAST BUS] PERISYS TIMEOUT:\n");
	/* always check: not be corrupted by DFD */
	if (self->secure_perisys == 1) {
		for (i = 0; i <= self->num_perisys_mon-1; ++i)
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "PERI MON%d = %04lx\n",
#ifdef MTK_SMC_ID_MGMT
			               i, (unsigned long int)mt_secure_call(MTK_SIP_LK_LASTBUS, LASTBSU_SMC_MONITOR_GET, i, 0, 0));
#else
			               i, mt_secure_call(MTK_SIP_LK_LASTBUS, LASTBSU_SMC_MONITOR_GET, i, 0));
#endif
	} else {
		for (i = 0; i <= self->num_perisys_mon-1; ++i)
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "PERI MON%d = %04x\n",
			               i, readl(peri_base + self->perisys_offsets.bus_peri_mon + 4*i));
	}

	return 0;
}

static int default_lastbus_infrasys_dump(const struct plt_cfg_bus_latch *self,
					 char *buf, int *wp)
{
	unsigned int i;
	unsigned long infra_base = INFRACFG_AO_BASE;

	if (self->num_infrasys_mon != 0) {
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[LAST BUS] INFRASYS TIMEOUT:\n");
		for (i = 0; i <= self->num_infrasys_mon-1; ++i)
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "INFRA SNAPSHOT%d = %04x\n",
				       i, readl(infra_base + self->infrasys_offsets.bus_infra_snapshot + 4*i));
	}

	return 0;
}

static int is_perisys_timeout(const struct plt_cfg_bus_latch *self)
{
	unsigned long peri_base = PERICFG_BASE;

	if (self->perisys_ops.is_timeout)
		return self->perisys_ops.is_timeout(self);

	if (self->secure_perisys == 1)
#ifdef MTK_SMC_ID_MGMT
		return mt_secure_call(MTK_SIP_LK_LASTBUS, LASTBSU_SMC_CHECK_HANG, 0, 0, 0);
#else
		return mt_secure_call(MTK_SIP_LK_LASTBUS, LASTBSU_SMC_CHECK_HANG, 0, 0);
#endif
	else
		return (readl(peri_base + self->perisys_offsets.bus_peri_r1) & 0x1);

	return 0;
}

static int is_infrasys_timeout(const struct plt_cfg_bus_latch *self)
{
	unsigned long infra_base = INFRACFG_AO_BASE;

	if (self->infrasys_ops.is_timeout)
		return self->infrasys_ops.is_timeout(self);

	return (readl(infra_base + self->infrasys_offsets.bus_infra_ctrl) & 0xFF000000);
}

static int lastbus_dump(char *buf, int *wp)
{

	if (buf == NULL || wp == NULL)
		return -1;

	if (cfg_bus_latch.supported == 0)
		return 0;

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n*************************** lastbus ***************************\n");

	if (cfg_bus_latch.mcusys_ops.dump) {
		cfg_bus_latch.mcusys_ops.dump(&cfg_bus_latch, buf, wp);
	} else {
		default_lastbus_mcusys_dump(&cfg_bus_latch, buf, wp);
	}

	if (is_infrasys_timeout(&cfg_bus_latch)) {
		if (cfg_bus_latch.infrasys_ops.dump) {
			cfg_bus_latch.infrasys_ops.dump(&cfg_bus_latch, buf, wp);
		} else {
			default_lastbus_infrasys_dump(&cfg_bus_latch, buf, wp);
		}
	}

	if (is_perisys_timeout(&cfg_bus_latch)) {
		if (cfg_bus_latch.perisys_ops.dump) {
			cfg_bus_latch.perisys_ops.dump(&cfg_bus_latch, buf, wp);
		} else {
			default_lastbus_perisys_dump(&cfg_bus_latch, buf, wp);
		}
	}

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n");

	return 1;
}

static int l2_parity_dump(char *buf, int *wp)
{
	unsigned long ret;
	unsigned int err_found = 0;

	if (buf == NULL || wp == NULL)
		return -1;

	if (cfg_l2_parity_latch.supported != 1)
		return 0;

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n*************************** l2c parity ***************************\n");

	/* mcusys registers would be corrupted by DFD */
	if (dfd_internal_dump_before_reboot()) {
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "DFD triggered\nPlease refer to dfd post-processing result for L2C parity\n");
		return 1;
	}

	ret = readl(MCUCFG_BASE + cfg_l2_parity_latch.mp0_l2_cache_parity1_rdata);
	if (ret & 0x1) {
		/* get parity error in mp0 */
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[L2C parity] get parity error in mp0\n");
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "error count = 0x%x\n", extract_n2mbits(ret, 8, 15));
		ret = readl(MCUCFG_BASE + cfg_l2_parity_latch.mp0_l2_cache_parity2_rdata);
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "index = 0x%x\n", extract_n2mbits(ret, 0, 14));
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "bank = 0x%x\n", extract_n2mbits(ret, 16, 31));

		/* clear mcusys parity check registers */
		writel(0x0, MCUCFG_BASE + cfg_l2_parity_latch.mp0_l2_cache_parity1_rdata);

		err_found = 1;
	}

	ret = readl(MCUCFG_BASE + cfg_l2_parity_latch.mp1_l2_cache_parity1_rdata);
	if (ret & 0x1) {
		/* get parity error in mp1 */
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[L2C parity] get parity error in mp1\n");
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "error count = 0x%x\n", extract_n2mbits(ret, 8, 15));
		ret = readl(MCUCFG_BASE + cfg_l2_parity_latch.mp1_l2_cache_parity2_rdata);
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "index = 0x%x\n", extract_n2mbits(ret, 0, 14));
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "bank = 0x%x\n", extract_n2mbits(ret, 16, 31));

		/* clear mcusys parity check registers */
		writel(0x0, MCUCFG_BASE + cfg_l2_parity_latch.mp1_l2_cache_parity1_rdata);

		err_found = 1;
	}

	if (err_found == 0)
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[L2C parity] no parity error found\n");

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n");

	return 1;
}

void __attribute__((weak)) init_cfg_cache_latch(struct plt_cfg_cache_latch *p_cfg_cache_latch, unsigned int cache_level)
{
	dprintf(CRITICAL, "%s: Please implement init_cfg_cache_latch() if using MTK new cache parity design\n", __func__);
}

static int cache_latch_dump(char *buf, int *wp)
{
	unsigned int val;
	unsigned int base, leng;
	unsigned int offset;
	unsigned int cache_level, support_level;
	int err_found;

	if (buf == NULL || wp == NULL)
		return -1;

	init_cfg_cache_latch(&cfg_cache_latch, 0);
	if (cfg_cache_latch.support_level == 0)
		return 0;

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n*************************** cache parity ***************************\n");
	/* mcusys registers would be corrupted by DFD */
	if (dfd_internal_dump_before_reboot()) {
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "DFD triggered\nPlease refer to dfd post-processing result\n");
		return 1;
	}

	cache_level = 1;
	support_level = cfg_cache_latch.support_level >> 1;
	do {
		if ((support_level & 0x1) == 0)
			goto next_cache_level;

		init_cfg_cache_latch(&cfg_cache_latch, cache_level);

		if (cfg_cache_latch.ops.has_error)
			err_found = cfg_cache_latch.ops.has_error(&cfg_cache_latch);
		else {
			val = readl(MCUCFG_BASE + cfg_cache_latch.reg_info.ctrl_offset);
			err_found = (val & cfg_cache_latch.reg_info.ctrl_mask)? 1 : 0;
		}

		if (err_found) {
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
				"[L%dC parity] detect parity error!\n", cache_level);
			if (cfg_cache_latch.ops.dump)
				cfg_cache_latch.ops.dump(&cfg_cache_latch, buf, wp);
			else {
				base = MCUCFG_BASE + cfg_cache_latch.reg_info.dump_offset;
				leng = cfg_cache_latch.reg_info.dump_length;
				for (offset = 0; offset < leng; offset+=4)
					*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
						"[L%dC parity] offset 0x%08x, val 0x%08x\n",
						cache_level, (base + offset), readl(base + offset));
			}
		} else
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
				"[L%dC parity] no parity error found\n", cache_level);

		if (cfg_cache_latch.ops.reset)
			cfg_cache_latch.ops.reset(&cfg_cache_latch);

next_cache_level:
		cache_level++;
		support_level = support_level >> 1;
	} while (support_level);

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n");

	return 1;
}

static int return_stack_dump(char *buf, int *wp)
{
	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n*************************** return stack***************************\n");

	if (!dfd_internal_dump_before_reboot()) {
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "NO DFD trigger \n");
	}
	else {
		*wp += dfd_get_decoded_return_stack(buf + *wp, LATCH_BUF_LENGTH - *wp);
	}

	return 1;
}

int latch_get(void **data, int *len)
{
	int ret;
	*len = 0;
	*data = malloc(LATCH_BUF_LENGTH);
	if (*data == NULL)
		return 0;

	ret = lastpc_dump(*data, len);
	if (ret < 0 || *len > LATCH_BUF_LENGTH) {
		*len = (*len > LATCH_BUF_LENGTH) ? LATCH_BUF_LENGTH : *len;
		return ret;
	}

	ret = circular_buffer_dump(*data, len);
	if (ret < 0 || *len > LATCH_BUF_LENGTH) {
		*len = (*len > LATCH_BUF_LENGTH) ? LATCH_BUF_LENGTH : *len;
		return ret;
	}

	ret = lastbus_dump(*data, len);
	if (ret < 0 || *len > LATCH_BUF_LENGTH) {
		*len = (*len > LATCH_BUF_LENGTH) ? LATCH_BUF_LENGTH : *len;
		return ret;
	}

	ret = l2_parity_dump(*data, len);
	if (ret < 0 || *len > LATCH_BUF_LENGTH) {
		*len = (*len > LATCH_BUF_LENGTH) ? LATCH_BUF_LENGTH : *len;
		return ret;
	}

	ret = cache_latch_dump(*data, len);
	if (ret < 0 || *len > LATCH_BUF_LENGTH) {
		*len = (*len > LATCH_BUF_LENGTH) ? LATCH_BUF_LENGTH : *len;
		return ret;
	}

	ret = return_stack_dump(*data, len);
	if (ret < 0 || *len > LATCH_BUF_LENGTH) {
		*len = (*len > LATCH_BUF_LENGTH) ? LATCH_BUF_LENGTH : *len;
		return ret;
	}

	return 1;
}

void latch_put(void **data)
{
	free(*data);
}

static int default_lastbus_perisys_init(const struct plt_cfg_bus_latch *self)
{
	if (self->secure_perisys == 1)
#ifdef MTK_SMC_ID_MGMT
		mt_secure_call(MTK_SIP_LK_LASTBUS, LASTBSU_SMC_INIT,
		               self->perisys_timeout, self->perisys_enable, 0);
#else
		mt_secure_call(MTK_SIP_LK_LASTBUS, LASTBSU_SMC_INIT,
		               self->perisys_timeout, self->perisys_enable);
#endif
	else {
		writel(self->perisys_timeout, PERICFG_BASE + self->perisys_offsets.bus_peri_r0);
		writel(self->perisys_enable, PERICFG_BASE + self->perisys_offsets.bus_peri_r1);
	}

	return 0;
}

static int default_lastbus_infrasys_init(const struct plt_cfg_bus_latch *self)
{
	unsigned long addr = 0;

	if (self->num_infrasys_mon != 0) {
		addr = INFRACFG_AO_BASE + self->infrasys_offsets.bus_infra_ctrl;
		writel(self->infrasys_config, addr);
		writel(readl(addr)|self->infrasys_enable, addr);
	}

	return 0;
}

void latch_lastbus_init(void)
{
	if (cfg_bus_latch.supported == 0)
		return;

	if (cfg_bus_latch.perisys_ops.init) {
		cfg_bus_latch.perisys_ops.init(&cfg_bus_latch);
	} else {
		default_lastbus_perisys_init(&cfg_bus_latch);
	}

	if (cfg_bus_latch.infrasys_ops.init) {
		cfg_bus_latch.infrasys_ops.init(&cfg_bus_latch);
	} else {
		default_lastbus_infrasys_init(&cfg_bus_latch);
	}
}
