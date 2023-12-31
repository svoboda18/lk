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
#include <stdlib.h>
#include <arch/arm/mmu.h>
#include <dev/aee_platform_debug.h>
#include <spm_common.h>
#include <platform/timer.h>
#include <platform/dram_debug.h>
#include <platform/plat_dbg_info.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <platform/mtk_wdt.h>
#include <platform/partition.h>
#include <platform/platform_debug.h>
#include "log_store_lk.h"
#include <plat_debug_interface.h>
#include <ram_console.h>
#include <reg.h>
#include <fdt.h>
#include <libfdt.h>
#include <debug.h>
#ifdef MTK_TINYSYS_SSPM_SUPPORT
#include <platform/mt_sspm.h>
#endif
#ifdef MTK_TINYSYS_SCP_SUPPORT
#include <lib/zlib.h>
#include <mt_scp.h>
#include <mt_scp_excep.h>
#endif
#include <mtk_mcdi.h>

#ifdef MTK_AB_OTA_UPDATER
#include <mt_boot.h>
#endif

#include <plat_sram_flag.h>

#include "mtk_secure_api.h"
int plt_get_cluster_id(unsigned int cpu_id, unsigned int *core_id_in_cluster)
{
	if (core_id_in_cluster == NULL)
		return -1;

	*core_id_in_cluster = (cpu_id % 4);
	return (cpu_id / 4);
}

unsigned long plt_get_cpu_power_status_at_wdt(void)
{
	unsigned long bitmask = 0, ret;

	ret = readl(SLEEP_BASE + cfg_pc_latch.spm_pwr_sts);

	/* CPU0 ~ CPU3 */
	bitmask |= (ret & (0xf << 9)) >> 9;
	/* CPU4 ~ CPU7 */
	bitmask |= (ret & (0xf << 16)) >> 12;

	return bitmask;
}

static bool dfd_valid = false;
static bool check_dfd_valid(u32* data)
{
	if (data != NULL) {
		/*
		 * 0x0 = {16’h0, 1’b0, 1’b1, 14’hx}
		 * 0x4 = {16’h0, 1’b0, 1’b1, 14’hx}
		 * 0x8 = 32’h0
		 * 0xC = 32’h0
		 * 0x10 = 32’h0
		 * 0x14 = 32’h0
		 */
		if (((data[0] & 0xffff4000) == 0x4000)
			&& ((data[1] & 0xffff4000) == 0x4000)
			&& data[2] == 0x0 && data[3] == 0x0
			&& data[4] == 0x0 && data[5] == 0x0)
			dfd_valid = true;
	}

	return dfd_valid;
}

unsigned int plt_get_dfd_dump_type(void)
{
	/* for mt6765 with DFD 3.0 -> always dump to DRAM*/
	if (cfg_dfd.version >= DFD_V3_0)
		return DFD_DUMP_TO_DRAM;
	else
		return DFD_DUMP_NOT_SUPPORT;
}

static unsigned int save_cpu_bus_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	int ret;
	unsigned int datasize = 0;

	/* Save latch buffer */
	ret = latch_get((void **)&buf, len);
	if (ret && (buf != NULL)) {
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

static unsigned int save_dfd_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	/* Save dfd buffer */
	if (dfd_get((void **)&buf, len)) {
		datasize = dev_write(buf, *len);
		dfd_put((void **)&buf);
	}

	return datasize;
}


void platform_lastpc_postinit(void)
{
	mt_secure_call(MTK_SIP_LK_LASTPC, 0, 0, 0, 0);
}

/* SPM Debug Features */
static unsigned int spm_wdt_latch_regs[] = {
	SLEEP_BASE + 0x800, /* PCM_WDT_LATCH_0 */
	SLEEP_BASE + 0x804, /* PCM_WDT_LATCH_1 */
	SLEEP_BASE + 0x808, /* PCM_WDT_LATCH_2 */
	SLEEP_BASE + 0x80c, /* PCM_WDT_LATCH_3 */
	SLEEP_BASE + 0x810, /* PCM_WDT_LATCH_4 */
	SLEEP_BASE + 0x814, /* PCM_WDT_LATCH_5 */
	SLEEP_BASE + 0x818, /* PCM_WDT_LATCH_6 */
	SLEEP_BASE + 0x81c, /* PCM_WDT_LATCH_7 */
	SLEEP_BASE + 0x820, /* PCM_WDT_LATCH_8 */
	SLEEP_BASE + 0x824, /* PCM_WDT_LATCH_9 */
	SLEEP_BASE + 0x838, /* PCM_WDT_LATCH_10 */
	SLEEP_BASE + 0x83c, /* PCM_WDT_LATCH_11 */
	SLEEP_BASE + 0x888, /* PCM_WDT_LATCH_12 */
	SLEEP_BASE + 0x88c, /* PCM_WDT_LATCH_13 */
	SLEEP_BASE + 0x828, /* WDT_LATCH_SPARE0 */
	SLEEP_BASE + 0x82c, /* WDT_LATCH_SPARE1 */
	SLEEP_BASE + 0x830, /* WDT_LATCH_SPARE2 */
	SLEEP_BASE + 0x834, /* WDT_LATCH_SPARE3 */
	SLEEP_BASE + 0x780, /* WDT_LATCH_SPARE0_FIX */
	SLEEP_BASE + 0x784, /* WDT_LATCH_SPARE1_FIX */
	SLEEP_BASE + 0x788, /* WDT_LATCH_SPARE2_FIX */
	SLEEP_BASE + 0x78C, /* WDT_LATCH_SPARE3_FIX */
	SLEEP_BASE + 0x914, /* SPM_ACK_CHK_LATCH */
	SLEEP_BASE + 0x934, /* SPM_ACK_CHK_LATCH2 */
	SLEEP_BASE + 0x954, /* SPM_ACK_CHK_LATCH3 */
	SLEEP_BASE + 0x974, /* SPM_ACK_CHK_LATCH4 */
	SLEEP_BASE + 0x840, /* DCHA_GATING_LATCH_0 */
	SLEEP_BASE + 0x844, /* DCHA_GATING_LATCH_1 */
	SLEEP_BASE + 0x848, /* DCHA_GATING_LATCH_2 */
	SLEEP_BASE + 0x84c, /* DCHA_GATING_LATCH_3 */
	SLEEP_BASE + 0x850, /* DCHA_GATING_LATCH_4 */
	SLEEP_BASE + 0x854, /* DCHA_GATING_LATCH_5 */
	SLEEP_BASE + 0x858, /* DCHA_GATING_LATCH_6 */
	SLEEP_BASE + 0x85c, /* DCHA_GATING_LATCH_7 */
	SLEEP_BASE + 0x860, /* DCHB_GATING_LATCH_0 */
	SLEEP_BASE + 0x864, /* DCHB_GATING_LATCH_1 */
	SLEEP_BASE + 0x868, /* DCHB_GATING_LATCH_2 */
	SLEEP_BASE + 0x86c, /* DCHB_GATING_LATCH_3 */
	SLEEP_BASE + 0x870, /* DCHB_GATING_LATCH_4 */
	SLEEP_BASE + 0x874, /* DCHB_GATING_LATCH_5 */
	SLEEP_BASE + 0x878, /* DCHB_GATING_LATCH_6 */
	SLEEP_BASE + 0x87c, /* DCHB_GATING_LATCH_7 */
	SLEEP_BASE + 0x880, /* DCHA_LATCH_RSV0 */
	SLEEP_BASE + 0x884, /* DCHB_LATCH_RSV0 */
	SLEEP_BASE + 0x794, /* DCHA_LATCH_RSV0_FIX */
	SLEEP_BASE + 0x79c, /* DCHB_LATCH_RSV0_FIX */
};

#define DVFSRC_DUMP	(DVFSRC_BASE + 0x400)
#define DVFSRC_SIZE	0xE0

#define SPM_DATA_BUF_LENGTH (4096)

static int spm_dump_data(char *buf, int *wp)
{
	unsigned int i;
	unsigned val;
#ifdef SPM_FW_USE_PARTITION
	char part_name[16] = "spmfw";

#ifdef MTK_AB_OTA_UPDATER
	get_AB_OTA_name((void *)&part_name, sizeof(part_name));
#endif /* MTK_AB_OTA_UPDATER */
#endif /* SPM_FW_USE_PARTITION */

	if (buf == NULL || wp == NULL)
		return -1;

	for (i = 0; i < (sizeof(spm_wdt_latch_regs)/sizeof(unsigned int)); i++) {
		val = readl(spm_wdt_latch_regs[i]);
		*wp += sprintf(buf + *wp,
				"SPM regs(0x%x) = 0x%x\n",
				spm_wdt_latch_regs[i], val);
	}

#ifdef SPM_FW_USE_PARTITION
	get_spmfw_version(part_name, "spmfw", buf, wp);
#endif /* SPM_FW_USE_PARTITION */

	for (i = 0; i < DVFSRC_SIZE; i += 4) {
		val = readl(DVFSRC_DUMP + i);
		*wp += sprintf(buf + *wp,
				"DVFSRC regs(0x%x) = 0x%08x\n", DVFSRC_DUMP + i, val);
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

/*
 * FOR DRAMC data and DRAM Calibration Log
 * This area is applied for DRAM related debug.
 */
/* DRAMC data */
static int plat_dram_debug_get(void **data, int *len)
{
	*data = (void *)DRAM_DEBUG_SRAM_ADDRESS;
	*len = DRAM_DEBUG_SRAM_LENGTH;
	return 1;
}

bool plat_boot_in_ddr_rsv(void)
{
	struct LAST_DRAMC_INFO_T *last_dramc_info;

	last_dramc_info = (struct LAST_DRAMC_INFO_T *) get_dbg_info_base(0xD8A3);

	if ((last_dramc_info->fatal_err_flag & (1 << DRAM_DEBUG_FLAG_DDR_RSV_BIT)) == 0)
		return false;
	else
		return true;
}

static int plat_dram_klog_get(void **data, int *len)
{
	*data = (void *)DRAM_KLOG_SRAM_ADDRESS;
	*len = DRAM_KLOG_SRAM_LENGTH;
	return 0;
}

static bool plat_dram_has_klog(void)
{
	/* not to overwrite klog in abnormal boot or in DDR reserve mode */
	if (ram_console_is_abnormal_boot() || plat_boot_in_ddr_rsv())
		return false;

//	if (*(volatile unsigned int*)DRAM_KLOG_VALID_ADDRESS)
//		return true;

	return false;
}

static unsigned int save_dram_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0, allsize = 0;

	if (plat_dram_debug_get((void **)&buf, len)) {
		datasize = dev_write(buf, *len);
		allsize = datasize;
	}

	if (plat_dram_klog_get((void **)&buf, len)) {
		buf = malloc(*len);
		if (buf) {
			mrdump_read_log(buf, *len, MRDUMP_EXPDB_DRAM_KLOG_OFFSET);
			datasize = dev_write(buf, *len);
			allsize += datasize;
			free(buf);
		}
	}

	return allsize;
}

#ifdef MTK_TINYSYS_SSPM_SUPPORT
#define SSPM_RETRY              10
#define SSPM_BUF_LEN           768

#define SYSRAM_START    0x40100000
#define SYSRAM_END      0x40120000
#define DRAM_START      0x80000000
#define DRAM_END        0xC0000000

#define BIT(x)          (1 << x)

enum {
	TO_PLATFORM = 0,
	TO_SSPM_OWN,
	TO_SSPM_LAST_LOG
};

static unsigned int save_sspm_coredump(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int buf = 0;
	unsigned int datasize = 0;
	int retry = SSPM_RETRY;

	if (!(*(unsigned int *)SSPM_BACKUP)) {
		return 0;
	}

	do {
		buf = *(unsigned int *)(SSPM_DM_ADDR);
		*len = *(int *)SSPM_DM_SZ;
		if ( (buf != 0) && (*len > 0) ) {
			datasize = dev_write( (unsigned int *)buf, *len);
			break;
		} else {
			udelay(100);
		}
	} while ( --retry);

	buf = *(unsigned int *)(SSPM_RM_ADDR);
	*len = *(int *)SSPM_RM_SZ;
	if ( (buf != 0) && (*len > 0) ) {
		    datasize += dev_write( (unsigned int *)buf, *len);
	}

	return datasize;
}

static unsigned int save_sspm_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	char owner[3] = {'P', 'S', 'L'};      /* Platform, SSPM, SSPM_LAST_LOG */
	unsigned int addr = 0, dispatch = 0;
	unsigned int ahb_status, ahb_addr_m0, ahb_addr_m1, ahb_addr_m2;
	unsigned int datasize = 0, tbufl, tbufh, r, i, j;
	int length = 0;

	buf = malloc(SSPM_BUF_LEN);
	if (!buf) {
		return 0;
	}

	ahb_status  = DRV_Reg32(SSPM_AHB_STATUS);
	ahb_addr_m0 = DRV_Reg32(SSPM_AHB_M0_ADDR);
	ahb_addr_m1 = DRV_Reg32(SSPM_AHB_M1_ADDR);
	ahb_addr_m2 = DRV_Reg32(SSPM_AHB_M2_ADDR);

	/* Set Auto-dispatch rule according by AHB_STATUS[13,10,5,4]. */
	if ( (ahb_status & (BIT(13) | BIT(10) | BIT(5) | BIT(4)) ) == 0x0 )
	{
		/* Bus hang issue. */
		if (ahb_status & BIT(2))        /* Master = M0 */
			addr = ahb_addr_m0;
		else if (ahb_status & BIT(3))   /* Master = M1 */
			addr = ahb_addr_m1;
		else if ((ahb_status & BIT(17)) == 0)  /* Master M2 trans is pending. */
			addr = ahb_addr_m2;

		if (((addr >= SYSRAM_START) && (addr < SYSRAM_END)) ||
		    ((addr >= DRAM_START) && (addr < DRAM_END)))
			dispatch = TO_PLATFORM;
		else
			dispatch = TO_SSPM_OWN;
	}
	else
		dispatch = TO_SSPM_LAST_LOG;

	memset(buf, 0, SSPM_BUF_LEN);
	length += snprintf(buf + length, SSPM_BUF_LEN - length,
			"STATUS: 0x%x\n"
			"M0: 0x%x\n"
			"M1: 0x%x\n"
			"M2: 0x%x\n"
			"SP: 0x%x\n"
			"LR: 0x%x\n"
			"PC: 0x%x\n"
			"Dispatch: %c\n",
			ahb_status, ahb_addr_m0, ahb_addr_m1, ahb_addr_m2,
			DRV_Reg32(SSPM_MD32_SP), DRV_Reg32(SSPM_MD32_LR),
			DRV_Reg32(SSPM_MD32_PC),
			owner[dispatch]);

	r = DRV_Reg32(SSPM_TBUF_WPTR);
	length += snprintf(buf + length, SSPM_BUF_LEN - length, "\nTBUF_WPTR=%u\n", r);

	for (i = 0, j = r; i < 16; ++i, j = (j-1) &0xF) {
		DRV_WriteReg32(SSPM_DBG_SEL, j);
		tbufl = DRV_Reg32(SSPM_TBUFL);
		tbufh = DRV_Reg32(SSPM_TBUFH);
		length += snprintf(buf + length, SSPM_BUF_LEN - length,
				"%u: TBUF=%u _H=0x%x _L=0x%x\n", i, j, tbufh, tbufl);
	}

	*len = length;

	if (*len > 0) {
		datasize = dev_write(buf, (*len > SSPM_BUF_LEN ? SSPM_BUF_LEN : *len));
	}

	free(buf);
	return datasize;
}

static unsigned int save_sspm_xfile(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int buf = 0;
	unsigned int datasize = 0;
	unsigned int sspm_info;
	int ret;

	/* Get the information stored in SSPM_INFO by preloader
	    struct sspm_info_t {
	        unsigned int sspm_dm_ofs;
	        unsigned int sspm_dm_sz;
	        unsigned int rd_ofs;
	        unsigned int rd_sz;
	        unsigned int xfile_addr;
	        unsigned int xfile_sz;
	    };
	*/
	sspm_info = *(unsigned int *)SSPM_INFO;

#ifdef MTK_3LEVEL_PAGETABLE
	ret = arch_mmu_map(ROUNDDOWN((uint64_t)sspm_info, SECTION_SIZE),
			ROUNDDOWN((uint32_t)sspm_info, SECTION_SIZE),
			MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
			SECTION_SIZE);

	if (ret) {
		dprintf(CRITICAL, "kedump: mmu map to 0x%llx fail(%d)\n",
			ROUNDDOWN((uint64_t)sspm_info, SECTION_SIZE), ret);
		return 0;
	}
#endif

	buf = *((unsigned int *)sspm_info + 4);
	*len = *((int *)sspm_info + 5);
	dprintf(CRITICAL, "buf 0x%x, len:0x%x\n", buf, *len);

	if ( (buf != 0) && (*len > 0) ) {
		datasize = dev_write( (unsigned int *)buf, *len);
	}

	return datasize;
}

static unsigned int save_sspm_last_log(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int buf = 0;
	unsigned int datasize = 0;

	buf = *(unsigned int *)(SSPM_LASTK_ADDR);
	*len = *(int *)SSPM_LASTK_SZ;
	if ( (buf != 0) && (*len > 0) ) {
		datasize = dev_write( (unsigned int *)buf, *len);
	}

	return datasize;
}
#endif  /* #ifdef MTK_TINYSYS_SSPM_SUPPORT */

#ifdef MTK_TINYSYS_SCP_SUPPORT
#define SCP_EE_SIZE 0xA0000 //640 KB
static unsigned int save_scp_coredump(u64 offset, int *len, CALLBACK dev_write)
{
	int memory_dump_size;

	unsigned char *output = malloc(SCP_EE_SIZE);
	if (!output) {
		return 0;
	}
	memory_dump_size = scp_crash_dump(output);

	if ((memory_dump_size > SCP_EE_SIZE) || (memory_dump_size <= Z_NEED_DICT)) {
		dprintf(CRITICAL, "SCP memory_dump_size ERR %d\n", memory_dump_size);
		memory_dump_size = 0;
	} else
		memory_dump_size = dev_write(output, memory_dump_size);
	free(output);
	return memory_dump_size;
}
#endif

static int plat_write_dram_klog(void)
{
	char *sram_base = NULL;
	int len = 0;

	if (plat_dram_klog_get((void **)&sram_base, (int *)&len)) {
		if (plat_dram_has_klog()) {
			mrdump_write_log(MRDUMP_EXPDB_DRAM_KLOG_OFFSET, sram_base, len);
		}
	}
	return 0;
}

/* SRAM for Hybrid CPU DVFS */
#define HVFS_SRAM_ADDRESS 0x00110800
#define HVFS_SRAM_LENGTH  0x1400	/* 5K bytes */
static int plat_hvfs_data_get(void **data, int *len)
{
	*data = (void *)HVFS_SRAM_ADDRESS;
	*len = HVFS_SRAM_LENGTH;
	return 1;
}

static unsigned int save_hvfs_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	if (plat_hvfs_data_get((void **)&buf, len)) {
		datasize = dev_write(buf, *len);
	}

	return datasize;
}

static int plat_mcdi_data_get(void **data, int *len)
{
	mcdi_setup_file_info_for_kedump();
	*data = (void *)MCDI_SRAM_ADDRESS;
	*len  = MCDI_SRAM_LENGTH;

	return 1;
}

static unsigned int save_mcdi_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	if (plat_mcdi_data_get((void **)&buf, len)) {
		datasize = dev_write(buf, *len);
	}

	return datasize;
}

static int plat_log_dur_lkdump_get(void **data, int *len)
{
    *data = (void *)current_buf_addr_get();
    *len = current_buf_pl_lk_log_size_get();
    if((*data == 0) || (*len == 0)) {
        dprintf(CRITICAL, "[LK_LOG_STORE] invalid current address or log length(addr 0x%x, len 0x%x)\n", (unsigned int)*data, (unsigned int)*len);
        return 0;
    }
    dprintf(CRITICAL, "[LK_LOG_STORE] the current buf addr is 0x%x, log len is 0x%x\n", (unsigned int)*data, (unsigned int)*len);
    return 1;
}

static unsigned int save_log_dur_lkdump(u64 offset, int *len, CALLBACK dev_write)
{
    char *buf = NULL;
    unsigned int datasize = 0;

    if (plat_log_dur_lkdump_get((void **)&buf, len)) {
        datasize = dev_write(buf, *len);
    }

    return datasize;
}

/* platform initial function */
int platform_debug_init(void)
{
	/* function pointer assignment */
	plat_spm_data_get = save_spm_data;
	plat_dram_get = save_dram_data;
	plat_hvfs_get = save_hvfs_data;
	plat_cpu_bus_get = save_cpu_bus_data;
#ifdef MTK_TINYSYS_SSPM_SUPPORT
	plat_sspm_coredump_get = save_sspm_coredump;
	plat_sspm_data_get     = save_sspm_data;
	plat_sspm_xfile_get    = save_sspm_xfile;
	plat_sspm_log_get      = save_sspm_last_log;
#endif
#ifdef MTK_TINYSYS_SCP_SUPPORT
	plat_scp_coredump_get = save_scp_coredump;
#endif
	plat_mcdi_get = save_mcdi_data;
	plat_dur_lkdump_get = save_log_dur_lkdump;

	plat_dfd20_get = save_dfd_data;
	dfd_op.check_dfd_valid = check_dfd_valid;

	/* routine tasks */
	plat_write_dram_klog();

	return 1;
}

extern int get_ccci_md_view_smem_addr_size(unsigned int user_id,
	unsigned long long *ap_addr, unsigned int *md_addr, unsigned int *size);
int dfd_set_base_addr(void *fdt)
{
	int ret = 0;
	int offset;
	u64 addr;
	unsigned int dfd_size;
	u32 addr_msb;
	unsigned int md_addr;
	unsigned long long ap_addr;
	DEF_PLAT_SRAM_FLAG *plat = NULL;

	if (!fdt)
		return -1;

	ret = get_ccci_md_view_smem_addr_size(0, &ap_addr, &md_addr, &dfd_size);
	if (ret < 0)
		return ret;

	offset = fdt_path_offset(fdt, "/chosen");
	if (offset < 0)
		return offset;

	/* pass base address to kernel */
	addr = cpu_to_fdt64(md_addr);
	ret = fdt_setprop(fdt, offset, "dfd,base_addr", &addr, sizeof(addr));
	if (ret < 0)
		return ret;

	addr_msb = cpu_to_fdt32(ap_addr);
	ret = fdt_setprop(fdt, offset, "dfd,base_addr_msb", &addr_msb, sizeof(addr_msb));
	if (ret < 0)
		return ret;

	/*
	 * write base address[31:1] from AP view to plat_sram_flag2[31:1]
	 * write base address[32:32] from AP view to plat_sram_flag2[0:0]
	 */
	plat = (DEF_PLAT_SRAM_FLAG *)get_dbg_info_base(PLAT_SRAM_FLAG_KEY);
	if (!plat)
		return -1;
	plat->plat_sram_flag2 = (ap_addr & ~(0x1)) | ((ap_addr >> 32) & 0x1);

	return ret;
}
