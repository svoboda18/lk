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
#include <malloc.h>
#include <dev/aee_platform_debug.h>
#include <arch/arm/mmu.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <platform/mtk_wdt.h>
#include <plat_debug_interface.h>
#include <spm_common.h>
#include <reg.h>
#include <fdt.h>
#include <libfdt.h>
#include <debug.h>
#include <systracker.h>
#include <utils.h>

#define LATCH_BUF_LENGTH	0x8000

static int lastpc_dump(char *buf, int *wp)
{
	unsigned int i, addr;
	unsigned long long pc_value, fp_value, sp_value;

	if (buf == NULL || wp == NULL)
		return -1;

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n*************************** lastpc ***************************\n");

	for (i = 0; i < 4; i++) {
		addr = MCUCFG_BASE + 0x300 + (i << 4);

		pc_value = readl(addr + 0x00);
		fp_value = readl(addr + 0x04);
		sp_value = readl(addr + 0x08);

		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp,
				"[LAST PC] CORE_%d PC = 0x%016llx, FP = 0x%016llx, SP = 0x%016llx\n",
				i, pc_value, fp_value, sp_value);
	}

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "\n");

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

	return 1;
}

void latch_put(void **data)
{
	free(*data);
}

static int systracker_dump(char *buf, int *wp)
{
	int i;
	unsigned int reg_value;
	unsigned int entry_valid;
	unsigned int entry_secure;
	unsigned int entry_id;
	unsigned int entry_address;
	unsigned int entry_data_size;
	unsigned int entry_burst_length;

	if (buf == NULL || wp == NULL)
		return -1;

	/* Get tracker info and save to buf */

	/* check if we got a timeout first */
	if (!(readl(BUS_DBG_CON) & BUS_DBG_CON_TIMEOUT))
		return 0;

	*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp, "\n*************************** systracker ***************************\n");

	for (i = 0; i < BUS_DBG_NUM_TRACKER; i++) {
		entry_address = readl(BUS_DBG_AR_TRACK_L(i));
		reg_value = readl(BUS_DBG_AR_TRACK_H(i));
		entry_valid = extract_n2mbits(reg_value, 19, 19);
		entry_id = extract_n2mbits(reg_value, 7, 18);
		entry_data_size = extract_n2mbits(reg_value, 4, 6);
		entry_burst_length = extract_n2mbits(reg_value, 0, 3);

		*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
		               "read entry = %d, valid = 0x%x, read id = 0x%x, address = 0x%x, data_size = 0x%x, burst_length = 0x%x\n",
		               i, entry_valid, entry_id, entry_address, entry_data_size, entry_burst_length);
	}

	for (i = 0; i < BUS_DBG_NUM_TRACKER; i++) {
		entry_address = readl(BUS_DBG_AW_TRACK_L(i));
		reg_value = readl(BUS_DBG_AW_TRACK_H(i));
		entry_valid = extract_n2mbits(reg_value, 19, 19);
		entry_id = extract_n2mbits(reg_value, 7, 18);
		entry_data_size = extract_n2mbits(reg_value, 4, 6);
		entry_burst_length = extract_n2mbits(reg_value, 0, 3);

		*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
		               "write entry = %d, valid = 0x%x, write id = 0x%x, address = 0x%x, data_size = 0x%x, burst_length = 0x%x\n",
		               i, entry_valid, entry_id, entry_address, entry_data_size, entry_burst_length);
	}

	return strlen(buf);
}

int systracker_get(void **data, int *len, unsigned int entry_num)
{
	int ret;

	*len = 0;
	*data = malloc(SYSTRACKER_BUF_LENGTH);
	if (*data == NULL)
		return 0;

	ret = systracker_dump(*data, len);
	if (ret < 0 || *len > SYSTRACKER_BUF_LENGTH) {
		*len = (*len > SYSTRACKER_BUF_LENGTH) ? SYSTRACKER_BUF_LENGTH : *len;
		return ret;
	}

	return 1;
}

void systracker_put(void **data)
{
	free(*data);
}
static unsigned int save_cpu_bus_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	int ret;
	unsigned int datasize = 0;

	/* Save latch buffer */
	ret = latch_get((void **)&buf, len);
	if (buf != NULL) {
		if (*len > 0)
			datasize = dev_write(buf, *len);
		latch_put((void **)&buf);
	}

	/* Save systracker buffer */
	ret = systracker_get((void **)&buf, len, 8);
	if (buf != NULL) {
		if (*len > 0)
			datasize += dev_write(buf, *len);
		systracker_put((void **)&buf);
	}

	return datasize;
}

/* SPM Debug Features */
static unsigned int spm_wdt_latch_regs[] = {
	SLEEP_BASE + 0xb24, /* PCM_WDT_LATCH */
};

/* need to check aee_db_file_info[] @ app/mt_boot/aee/KEDump.c */
#define SPM_DATA_BUF_LENGTH (4096)

static int spm_dump_data(char *buf, int *wp)
{
	unsigned int i;
	unsigned val;

	if (buf == NULL || wp == NULL)
		return -1;

	for (i = 0; i < (sizeof(spm_wdt_latch_regs)/sizeof(unsigned int)); i++) {
		val = readl(spm_wdt_latch_regs[i]);
		*wp += sprintf(buf + *wp,
				"SPM regs(0x%x) = 0x%x\n",
				spm_wdt_latch_regs[i], val);
	}


	if (*wp > SPM_DATA_BUF_LENGTH) {
		dprintf(CRITICAL, "[spm] out of range: 0x%x > SPM_DATA_BUF_LENGTH(0x%x)\n", *wp, SPM_DATA_BUF_LENGTH);
		assert(0);
	}

	return 1;
}

int spm_data_get(void **data, int *len)
{
	int ret;

	*len = 0;
	*data = malloc(SPM_DATA_BUF_LENGTH);
	if (*data == NULL)
		return 0;

	ret = spm_dump_data(*data, len);
	if (ret < 0 || *len > SPM_DATA_BUF_LENGTH) {
		*len = (*len > SPM_DATA_BUF_LENGTH) ? SPM_DATA_BUF_LENGTH : *len;
		return ret;
	}

	return 1;
}

void spm_data_put(void **data)
{
	free(*data);
}

static unsigned int save_spm_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	/* Save SPM buffer */
	spm_data_get((void **)&buf, len);
	if (buf != NULL) {
		if (*len > 0)
			datasize = dev_write(buf, *len);
		spm_data_put((void **)&buf);
	}

	return datasize;
}


/* platform initial function */
int platform_debug_init(void)
{
	/* function pointer assignment */
	plat_spm_data_get = save_spm_data;
	plat_cpu_bus_get = save_cpu_bus_data;
#if 0
	plat_dram_get = save_dram_data;
#ifdef MTK_TINYSYS_SSPM_SUPPORT
	plat_sspm_coredump_get = save_sspm_coredump;
	plat_sspm_data_get = save_sspm_data;
	plat_sspm_xfile_get = save_sspm_xfile;
	plat_sspm_log_get = save_sspm_last_log;
#endif
	plat_hvfs_get = save_hvfs_data;
	plat_pllk_last_log_get = save_pllk_last_log;
	plat_dur_lkdump_get = save_log_dur_lkdump;
	plat_mcdi_get = save_mcdi_data;

	plat_dfd20_get = save_dfd_data;
	dfd_op.acquire_ram_control = setup_snoop_filter_ram_ctrl;
	dfd_op.release_ram_control = return_snoop_filter_ram_ctrl;
	dfd_op.check_dfd_valid = check_dfd_valid;
	circular_buffer_op.lock = circular_buffer_lock;
	circular_buffer_op.unlock = circular_buffer_unlock;

	/* routine tasks */
	plat_write_dram_klog();
#endif
	return 1;
}
