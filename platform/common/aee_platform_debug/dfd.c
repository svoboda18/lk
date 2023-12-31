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

#include <debug.h>
#include <malloc.h>
#include <mt_typedefs.h>
#include <reg.h>
#include <plat_debug_interface.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <arch/arm/mmu.h>
#include "dfd.h"
#include "latch.h"
#include "utils.h"
#include <platform/lastpc.h>
#include <platform/sec_devinfo.h>
#include <platform/boot_mode.h>

#include <plat_sram_flag.h>


static unsigned int dfd_internal_dump_triggered;
static struct decoded_lastpc *lastpc;
#ifdef ENABLE_RETURN_STACK
static struct decoded_return_stack *return_stack;
#endif

u64 dfd_decode(const u64 *raw, const struct reg_collector *collector, const bool count_header_row)
{
	u64 reg = 0;
	unsigned int i = 0;
	unsigned int raw_offset = 0;
	unsigned int bit_offset = 0;
	unsigned int inv = 0;

	if (raw == NULL || collector == NULL)
		return 0;

	for (i = 0; i < DFD_REG_LENGTH; ++i) {
		if (count_header_row)
			raw_offset = collector->bit_pairs[i].raw_offset + cfg_dfd.nr_header_row;
		else
			raw_offset = collector->bit_pairs[i].raw_offset;
		bit_offset = collector->bit_pairs[i].bit_offset;
		inv = collector->bit_pairs[i].inv & 0x3;

		if (inv == 0)
			reg |= ((raw[raw_offset] & (((u64)1)<<bit_offset))>>bit_offset) << i;
		else if (inv == 1)
			reg |= ((~raw[raw_offset] & (((u64)1)<<bit_offset))>>bit_offset) << i;
		else if (inv == 2)
			reg |= ((u64)0) << i;
		else if (inv == 3)
			reg |= ((u64)1) << i;
	}

	return reg;
}

#ifdef ENABLE_RETURN_STACK
static void dfd_decode_return_stack(const u64 *dfd_raw_data)
{
	unsigned int i, j;

	if (cfg_return_stack.decode) {
		cfg_return_stack.decode(&cfg_return_stack, dfd_raw_data);
		return;
	}

	return_stack = malloc(cfg_return_stack.nr_max_core * sizeof(struct decoded_return_stack));
	for (i = 0; i < cfg_return_stack.nr_max_core; ++i) {
		return_stack[i].entry = malloc(cfg_return_stack.nr_entry * sizeof(unsigned long long));
		return_stack[i].ptr = 0;
		for (j = 0; j < cfg_return_stack.nr_entry; j++)
			return_stack[i].entry[j] = 0;
	}


	for (i = 0; i < (cfg_return_stack.nr_max_core - cfg_return_stack.nr_max_big); i++) {
		return_stack[i].ptr = dfd_decode(dfd_raw_data, &(little_core[i].return_Stack_pointer), true);
		return_stack[i].entry[0] = dfd_decode(dfd_raw_data, &(little_core[i].return_Stack0), true);
		if (return_stack[i].entry[0] & (0x1ULL << 48))
			return_stack[i].entry[0] |= (u64)0xffff000000000000;
		return_stack[i].entry[1] = dfd_decode(dfd_raw_data, &(little_core[i].return_Stack1), true);
		if (return_stack[i].entry[1] & (0x1ULL << 48))
			return_stack[i].entry[1] |= (u64)0xffff000000000000;
		return_stack[i].entry[2] = dfd_decode(dfd_raw_data, &(little_core[i].return_Stack2), true);
		if (return_stack[i].entry[2] & (0x1ULL << 48))
			return_stack[i].entry[2] |= (u64)0xffff000000000000;
		return_stack[i].entry[3] = dfd_decode(dfd_raw_data, &(little_core[i].return_Stack3), true);
		if (return_stack[i].entry[3] & (0x1ULL << 48))
			return_stack[i].entry[3] |= (u64)0xffff000000000000;
		return_stack[i].entry[4] = dfd_decode(dfd_raw_data, &(little_core[i].return_Stack4), true);
		if (return_stack[i].entry[4] & (0x1ULL << 48))
			return_stack[i].entry[4] |= (u64)0xffff000000000000;
		return_stack[i].entry[5] = dfd_decode(dfd_raw_data, &(little_core[i].return_Stack5), true);
		if (return_stack[i].entry[5] & (0x1ULL << 48))
			return_stack[i].entry[5] |= (u64)0xffff000000000000;
		return_stack[i].entry[6] = dfd_decode(dfd_raw_data, &(little_core[i].return_Stack6), true);
		if (return_stack[i].entry[6] & (0x1ULL << 48))
			return_stack[i].entry[6] |= (u64)0xffff000000000000;
		return_stack[i].entry[7] = dfd_decode(dfd_raw_data, &(little_core[i].return_Stack7), true);
		if (return_stack[i].entry[7] & (0x1ULL << 48))
			return_stack[i].entry[7] |= (u64)0xffff000000000000;
	}

	for (i = 0; i < cfg_return_stack.nr_max_big; i++) {
		return_stack[cfg_big_core[i].cpuid].ptr = dfd_decode(dfd_raw_data, &(big_core[i].return_Stack_pointer), true);
		return_stack[cfg_big_core[i].cpuid].entry[0] = dfd_decode(dfd_raw_data, &(big_core[i].return_Stack0), true);
		if (return_stack[cfg_big_core[i].cpuid].entry[0] & (0x1ULL << 48))
			return_stack[cfg_big_core[i].cpuid].entry[0] |= (u64)0xffff000000000000;
		return_stack[cfg_big_core[i].cpuid].entry[1] = dfd_decode(dfd_raw_data, &(big_core[i].return_Stack1), true);
		if (return_stack[cfg_big_core[i].cpuid].entry[1] & (0x1ULL << 48))
			return_stack[cfg_big_core[i].cpuid].entry[1] |= (u64)0xffff000000000000;
		return_stack[cfg_big_core[i].cpuid].entry[2] = dfd_decode(dfd_raw_data, &(big_core[i].return_Stack2), true);
		if (return_stack[cfg_big_core[i].cpuid].entry[2] & (0x1ULL << 48))
			return_stack[cfg_big_core[i].cpuid].entry[2] |= (u64)0xffff000000000000;
		return_stack[cfg_big_core[i].cpuid].entry[3] = dfd_decode(dfd_raw_data, &(big_core[i].return_Stack3), true);
		if (return_stack[cfg_big_core[i].cpuid].entry[3] & (0x1ULL << 48))
			return_stack[cfg_big_core[i].cpuid].entry[3] |= (u64)0xffff000000000000;
		return_stack[cfg_big_core[i].cpuid].entry[4] = dfd_decode(dfd_raw_data, &(big_core[i].return_Stack4), true);
		if (return_stack[cfg_big_core[i].cpuid].entry[4] & (0x1ULL << 48))
			return_stack[cfg_big_core[i].cpuid].entry[4] |= (u64)0xffff000000000000;
		return_stack[cfg_big_core[i].cpuid].entry[5] = dfd_decode(dfd_raw_data, &(big_core[i].return_Stack5), true);
		if (return_stack[cfg_big_core[i].cpuid].entry[5] & (0x1ULL << 48))
			return_stack[cfg_big_core[i].cpuid].entry[5] |= (u64)0xffff000000000000;
		return_stack[cfg_big_core[i].cpuid].entry[6] = dfd_decode(dfd_raw_data, &(big_core[i].return_Stack6), true);
		if (return_stack[cfg_big_core[i].cpuid].entry[6] & (0x1ULL << 48))
			return_stack[cfg_big_core[i].cpuid].entry[6] |= (u64)0xffff000000000000;
		return_stack[cfg_big_core[i].cpuid].entry[7] = dfd_decode(dfd_raw_data, &(big_core[i].return_Stack7), true);
		if (return_stack[cfg_big_core[i].cpuid].entry[7] & (0x1ULL << 48))
			return_stack[cfg_big_core[i].cpuid].entry[7] |= (u64)0xffff000000000000;
	}
}

/*
 * fills return stack into the buffer, and returns the total length we wrote
 */
unsigned int dfd_get_decoded_return_stack(char* buf, unsigned int max_buf_size)
{
	unsigned int len = 0, i;

	if (!return_stack)
		return len;
	len += snprintf(buf, max_buf_size, "DFD triggered\n\n");

	if (cfg_return_stack.dump) {
		cfg_return_stack.dump(&cfg_return_stack, buf, &len);

		return len;
	}

	for (i = 0; i < cfg_return_stack.nr_max_core; ++i) {
		len += snprintf(buf + len, max_buf_size - len, "[CORE_%d]\n", i);
		len += snprintf(buf + len, max_buf_size - len, "Top pointer : 0x%llx\n", return_stack[i].ptr);
		len += snprintf(buf + len, max_buf_size - len, "return stack0 = [<0x%016llx>]\n", return_stack[i].entry[0]);
		len += snprintf(buf + len, max_buf_size - len, "return stack1 = [<0x%016llx>]\n", return_stack[i].entry[1]);
		len += snprintf(buf + len, max_buf_size - len, "return stack2 = [<0x%016llx>]\n", return_stack[i].entry[2]);
		len += snprintf(buf + len, max_buf_size - len, "return stack3 = [<0x%016llx>]\n", return_stack[i].entry[3]);
		len += snprintf(buf + len, max_buf_size - len, "return stack4 = [<0x%016llx>]\n", return_stack[i].entry[4]);
		len += snprintf(buf + len, max_buf_size - len, "return stack5 = [<0x%016llx>]\n", return_stack[i].entry[5]);
		len += snprintf(buf + len, max_buf_size - len, "return stack6 = [<0x%016llx>]\n", return_stack[i].entry[6]);
		len += snprintf(buf + len, max_buf_size - len, "return stack7 = [<0x%016llx>]\n", return_stack[i].entry[7]);
		len += snprintf(buf + len, max_buf_size - len, "\n");
	}

	free(return_stack);

	return len;
}
#else
unsigned int dfd_get_decoded_return_stack(char* buf, unsigned int max_buf_size)
{
	return 0;
}
#endif

static void dfd_internal_dump_decode_lastpc(const u64 *dfd_raw_data)
{
	unsigned int i;
	unsigned long cpu_power_status = 0;

	lastpc = malloc(cfg_pc_latch.nr_max_core * sizeof(struct decoded_lastpc));
	for (i = 0; i < cfg_pc_latch.nr_max_core; ++i) {
		lastpc[i].power_state = 0x0;
		lastpc[i].pc = 0x0;
		lastpc[i].sp_64 = 0x0;
		lastpc[i].fp_64 = 0x0;
		lastpc[i].sp_32 = 0x0;
		lastpc[i].fp_32 = 0x0;
	}

	if (cfg_dfd.sw_version == DFD_SW_V1)
		cpu_power_status = plt_get_cpu_power_status_at_wdt();

	for (i = 0; i < cfg_pc_latch.nr_max_core - cfg_pc_latch.nr_max_big_core; ++i) {
		/* CPUX is not online on WDT */
		if (cfg_dfd.sw_version == DFD_SW_V1) {
			/* power status from SPM register */
			if (extract_n2mbits(cpu_power_status, i, i) == 0)
				continue;
		} else if (cfg_dfd.sw_version == DFD_SW_V2) {
			/* power status from DFD dump */
			lastpc[i].power_state = dfd_decode(dfd_raw_data, &(little_core[i].spmc_power_state), true);
			lastpc[i].power_state &= 0x3F;
			if (lastpc[i].power_state != DFD_CORE_PWR_ON && lastpc[i].power_state != DFD_CORE_PWR_RETENTION)
				continue;
		} else if (cfg_dfd.sw_version == DFD_SW_V3) {
			/* power status from DFD dump */
#ifdef DFD_SW_V3_WA
			/* workaround for DFD_SW_V3 */
			lastpc[i].power_state = dfd_decode(dfd_raw_data, &(spmc_power_state[i].power_state), false);
#else
			lastpc[i].power_state = 0;
#endif
			if (lastpc[i].power_state != DFD_CORE_PWR_ON && lastpc[i].power_state != DFD_CORE_PWR_RETENTION)
				continue;
		}

		lastpc[i].pc = dfd_decode(dfd_raw_data, &(little_core[i].pc), true);
		lastpc[i].sp_32 = dfd_decode(dfd_raw_data, &(little_core[i].sp32), true);
		/* TODO: select SP by cpsr */
		lastpc[i].sp_64 = dfd_decode(dfd_raw_data, &(little_core[i].sp_EL1), true);
		lastpc[i].fp_32 = dfd_decode(dfd_raw_data, &(little_core[i].fp32), true);
		lastpc[i].fp_64 = dfd_decode(dfd_raw_data, &(little_core[i].fp64), true);
	}

	if (cfg_pc_latch.nr_max_big_core == 0)
		return;

	for (i = 0; i < cfg_pc_latch.nr_max_big_core; ++i) {
		if (cfg_dfd.sw_version == DFD_SW_V1) {
			/* power status from SPM register */
			if (extract_n2mbits(cpu_power_status, cfg_big_core[i].cpuid, cfg_big_core[i].cpuid) == 0)
				continue;

			lastpc[cfg_big_core[i].cpuid].pc = dfd_decode(dfd_raw_data, &(big_core[i].edpcsr), true);
		} else if (cfg_dfd.sw_version == DFD_SW_V2) {
			/* power status from DFD dump */
			lastpc[cfg_big_core[i].cpuid].power_state = dfd_decode(dfd_raw_data, &(big_core[i].spmc_power_state), true);
			lastpc[cfg_big_core[i].cpuid].power_state &= 0x3F;

			if (lastpc[cfg_big_core[i].cpuid].power_state != DFD_CORE_PWR_ON
			        && lastpc[cfg_big_core[i].cpuid].power_state != DFD_CORE_PWR_RETENTION)
				continue;

			lastpc[cfg_big_core[i].cpuid].pc = dfd_decode(dfd_raw_data, &(big_core[i].last_branch), true);
		} else if (cfg_dfd.sw_version == DFD_SW_V3) {
			/* power status from DFD dump */
#ifdef DFD_SW_V3_WA
			lastpc[cfg_big_core[i].cpuid].power_state
				= dfd_decode(dfd_raw_data, &(spmc_power_state[cfg_big_core[i].cpuid].power_state), false);
#else
			lastpc[cfg_big_core[i].cpuid].power_state = 0;
#endif
			if (lastpc[cfg_big_core[i].cpuid].power_state != DFD_CORE_PWR_ON
			        && lastpc[cfg_big_core[i].cpuid].power_state != DFD_CORE_PWR_RETENTION)
				continue;

			lastpc[cfg_big_core[i].cpuid].pc = dfd_decode(dfd_raw_data, &(big_core[i].last_branch), true);
		}
		/* extend the high bits for PC */
		if (lastpc[cfg_big_core[i].cpuid].pc & (0x1ULL << 48))
			lastpc[cfg_big_core[i].cpuid].pc = (u64) 0xffff000000000000 | lastpc[cfg_big_core[i].cpuid].pc;
	}
}

unsigned int get_efuse_dfd_disabled(void)
{
	if(cfg_dfd.dfd_disable_bit == -1 || cfg_dfd.dfd_disable_devinfo_index == -1)
		return 0;

	return ((get_devinfo_with_index(cfg_dfd.dfd_disable_devinfo_index)
	         & (0x1 << cfg_dfd.dfd_disable_bit)) >> cfg_dfd.dfd_disable_bit);
}

extern BOOT_ARGUMENT *g_boot_arg;

static unsigned int dfd_internal_dump_check_triggered_or_not(void)
{
	DEF_PLAT_SRAM_FLAG* plat = NULL;

	if (cfg_dfd.version >= DFD_V3_0) {
		if (!get_dbg_info_base)
			return 0;
		plat = (DEF_PLAT_SRAM_FLAG *)get_dbg_info_base(PLAT_SRAM_FLAG_KEY);
		if (!plat)
			return 0;

		/* DFD triggers only if dfd_valid == 1 and efuse_dfd_disbled == 0 */
		if ((plat->plat_sram_flag1 & 0x1) && (get_efuse_dfd_disabled() == 0x0)) {
			if (g_boot_arg != NULL &&
					g_boot_arg->ddr_reserve_enable && g_boot_arg->ddr_reserve_success)
				dfd_internal_dump_triggered = 1;
			else
				dfd_internal_dump_triggered = 0;
		}
		else
			dfd_internal_dump_triggered = 0;
	} else if (cfg_dfd.version == DFD_V2_0) {
		if (get_efuse_dfd_disabled() == 0x0)
			dfd_internal_dump_triggered = 1;
		else
			dfd_internal_dump_triggered = 0;
	} else
		dfd_internal_dump_triggered = 0;

	return dfd_internal_dump_triggered;
}

/*
 * DFD internal dump before reboot implies that mcusys registers are all corrupted
 */
unsigned int dfd_internal_dump_before_reboot(void)
{
	/* for platform that is not support DFD internal dump */
	if (cfg_dfd.version < DFD_V2_0)
		return 0;

	/*
	 * check the magic pattern again,
	 * pass NULL as the parameter to get the result directly
	 */

	if (dfd_op.check_dfd_valid && dfd_internal_dump_triggered)
		return dfd_op.check_dfd_valid(NULL);

	return dfd_internal_dump_triggered;
}

/*
 * fills lastpc into the buffer, and returns the total length we wrote
 */
unsigned int dfd_internal_dump_get_decoded_lastpc(char* buf, unsigned int max_buf_size)
{
	DEF_PLAT_SRAM_FLAG* plat = NULL;
	unsigned int plat_sram_flag1, plat_sram_flag2;
	unsigned int len = 0, i;

	if (!get_dbg_info_base)
		return len;
	plat = (DEF_PLAT_SRAM_FLAG *)get_dbg_info_base(PLAT_SRAM_FLAG_KEY);
	plat_sram_flag1 = (plat == NULL)? 0 : plat->plat_sram_flag1;
	plat_sram_flag2 = (plat == NULL)? 0 : plat->plat_sram_flag2;


	len += snprintf(buf, max_buf_size, "DFD triggered\nPlease refer to dfd post-processing result for lastpc\n\n");
	len += snprintf(buf + len, max_buf_size - len, "plat_sram_flag1 = 0x%x\n(dfd_valid=%x, dfd_valid_before_reboot=%x)\n",
	                plat_sram_flag1, extract_n2mbits(plat_sram_flag1, 0, 0),
	                extract_n2mbits(plat_sram_flag1, 1, 1));
	len += snprintf(buf + len, max_buf_size - len, "plat_sram_flag2 = 0x%x\n(base address=0x%llx)\n\n",
	                plat_sram_flag2,
	                (plat_sram_flag2 & ~(0x1))|(((uint64_t)plat_sram_flag2 & 0x1) << 32));

	if (!lastpc)
		return len;

	if (g_is_64bit_kernel) {
		for (i = 0; i < cfg_pc_latch.nr_max_core; ++i)
			len += snprintf(buf + len, max_buf_size - len, "[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%016llx, SP = 0x%016llx\n",
			                i, lastpc[i].pc, lastpc[i].fp_64, lastpc[i].sp_64);
	} else {
		for (i = 0; i < cfg_pc_latch.nr_max_core; ++i)
			len += snprintf(buf + len, max_buf_size - len, "[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%08lx, SP = 0x%08lx\n",
			                i, lastpc[i].pc, lastpc[i].fp_32, lastpc[i].sp_32);
	}

	free(lastpc);

	return len;
}

int dfd_get(void **data, int *len)
{
	unsigned int i, dfd_dump_type;
	unsigned long ret, nr_bytes_remained = 0, nr_total_words, dfd_buffer_size;
	uint64_t paddr;
	vaddr_t vaddr;
	DEF_PLAT_SRAM_FLAG* plat = NULL;

	if (len == NULL || data == NULL)
		return -1;

	*len = 0;
	*data = NULL;

	if (cfg_dfd.version < DFD_V2_0)
		return 0;

	if (dfd_internal_dump_check_triggered_or_not()) {
		dfd_dump_type = plt_get_dfd_dump_type();
		if (dfd_dump_type == DFD_DUMP_TO_DRAM) {
			/*
			 * use DRAM: need mapping to scratch memory before accessing
			 * base address[31:1] from AP view => plat_sram_flag2[31:1]
			 * base address[32:32] from AP view => plat_sram_flag2[0:0]
			 */
			vaddr = SCRATCH_ADDR;

			if (!get_dbg_info_base)
				return 0;
			plat = (DEF_PLAT_SRAM_FLAG *)get_dbg_info_base(PLAT_SRAM_FLAG_KEY);
			if (!plat) {
				dprintf(CRITICAL, "[dfd] error: Can't get plat_sram_flag2\n");
				return 0;
			}

			paddr = (uint64_t)(plat->plat_sram_flag2 & ~(0x1))
			        |((uint64_t)(plat->plat_sram_flag2 & 0x1) << 32);

			if (cfg_dfd.large_buffer_length)
				arch_mmu_map(paddr, vaddr,
				             MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA, cfg_dfd.large_buffer_length);
			else
				arch_mmu_map(paddr, vaddr,
				             MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA, cfg_dfd.buffer_length);
			*data = vaddr;
		} else if (dfd_dump_type == DFD_DUMP_TO_SRAM) {
			/* use internal SRAM: no need to map */
			vaddr = cfg_dfd.buffer_addr;
			paddr = cfg_dfd.buffer_addr;

			/* allocate memory for AEE */
			*data = malloc(cfg_dfd.buffer_length);
			if (*data == NULL)
				return 0;

			nr_total_words = cfg_dfd.buffer_length / 4;
			nr_bytes_remained = cfg_dfd.buffer_length % 4;

			if (dfd_op.acquire_ram_control)
				dfd_op.acquire_ram_control();

			/* copy results */
			for (i = 0; i < nr_total_words; i++) {
				ret = readl(vaddr + i*4);
				*(char *)(*data + i*4) = extract_n2mbits(ret, 0, 7);
				*(char *)(*data + i*4 + 1) = extract_n2mbits(ret, 8, 15);
				*(char *)(*data + i*4 + 2) = extract_n2mbits(ret, 16, 23);
				*(char *)(*data + i*4 + 3) = extract_n2mbits(ret, 24, 31);
			}

			/* handle unalgiend case */
			if (nr_bytes_remained != 0) {
				dprintf(CRITICAL, "[dfd] warning: the buffer length is not aligned to 4-byte\n");
				ret = readl(vaddr + nr_total_words*4);
				for (i = 0; i < nr_bytes_remained; ++i)
					*(char *)(*data + nr_total_words*4 + i) =
					    extract_n2mbits(ret, 0 + 8*i, 7 + 8*i);
			}
		} else {
			dprintf(CRITICAL, "[dfd] dfd_dump_type is \"not support\" -> skip\n");
			return 0;
		}

		/* check pa and va */
		if (paddr == 0 || vaddr == 0) {
			dprintf(CRITICAL, "[dfd] pa or va is invalid -> skip\npa = 0x%llx, va = 0x%lx",
			        paddr, vaddr);
			return 0;
		}

		if (dfd_op.release_ram_control)
			dfd_op.release_ram_control();

#ifdef SUPPORT_CACHE_DUMP
		/* get dfd3.5 enable bit to decide dump size*/
		if (dfd_decode((u64 *) *data, &(mcusys[0].dfd_v35_enable), true)) {
			dfd_buffer_size = cfg_dfd.large_buffer_length;
		} else {
			dfd_buffer_size = cfg_dfd.buffer_length;
		}
#else
			dfd_buffer_size = cfg_dfd.buffer_length;
#endif

		dprintf(CRITICAL, "[dfd] pa = 0x%llx, va = 0x%lx, length = 0x%lx\n",
		        paddr, vaddr, dfd_buffer_size);

		/* insert chip id */
		for (i = 0; i <= 7; ++i)
			*(char *)(*data + cfg_dfd.chip_id_offset + i) = cfg_dfd.chip_id[i];
		*len = dfd_buffer_size;

		/* decode lastpc & return stack*/
		if (dfd_op.check_dfd_valid) {
			if (dfd_op.check_dfd_valid((u32 *)*data)) {
				dfd_internal_dump_decode_lastpc((u64 *)*data);
#ifdef ENABLE_RETURN_STACK
				dfd_decode_return_stack((u64 *)*data);
#endif
			}
		} else {
			dfd_internal_dump_decode_lastpc((u64 *)*data);
#ifdef ENABLE_RETURN_STACK
			dfd_decode_return_stack((u64 *)*data);
#endif
		}
		if (dfd_dump_type == DFD_DUMP_TO_DRAM) {
			if (cfg_dfd.large_buffer_length)
				arch_mmu_map(vaddr, vaddr,
					MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA, cfg_dfd.large_buffer_length);
			else
				arch_mmu_map(vaddr, vaddr,
					MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA, cfg_dfd.buffer_length);
			*data = paddr;
		}
	} else {
		/* not triggered */
		*len = 0;
	}

	if(dfd_op.setup_dfd_file_name)
		dfd_op.setup_dfd_file_name(&cfg_dfd);

	return 1;
}

void dfd_put(void **data)
{
	unsigned int dfd_dump_type;
	dfd_dump_type = plt_get_dfd_dump_type();

	if (dfd_dump_type == DFD_DUMP_TO_SRAM)
		free(*data);
}
