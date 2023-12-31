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
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <platform/mtk_wdt.h>
#include <platform/platform_debug.h>
#include "log_store_lk.h"
#include <plat_debug_interface.h>
#include <spm_common.h>
#include <reg.h>
#include <fdt.h>
#include <libfdt.h>
#include <debug.h>
#ifdef MTK_TINYSYS_SSPM_SUPPORT
#include <platform/mt_sspm.h>
#include <arch/arm/mmu.h>
#include <platform/timer.h>
#endif
#ifdef MTK_TINYSYS_SCP_SUPPORT
#include <lib/zlib.h>
#include <mt_scp.h>
#include <mt_scp_excep.h>
#endif
#ifdef MTK_AUDIODSP_SUPPORT
#include <mt_adsp.h>
#endif
#include <mtk_mcdi.h>
#include "mtk_secure_api.h"
#ifdef MTK_AB_OTA_UPDATER
#include <mt_boot.h>
#endif
#include <plat_sram_flag.h>


int plt_get_cluster_id(unsigned int cpu_id, unsigned int *core_id_in_cluster)
{
	return 0;
}

unsigned long plt_get_cpu_power_status_at_wdt(void)
{
	unsigned long bitmask = 0xff, ret;

	ret = readl(MCUCFG_BASE + cfg_pc_latch.spm_pwr_sts);
	bitmask = ret & 0xff;

	return bitmask;
}

static bool dfd_valid = false;
static bool check_dfd_valid(u32* data)
{
        if (data != NULL) {
                /*
                 * 0x0 = 16'hAA55
                 * 0x4 = 16'h0F0F
                 * 0x8 = 32’h1683-0000
                 */
                if ((((data[0] & 0xffff0000) >> 16) == 0xAA55)
                        && (((data[1] & 0xffff0000) >> 16) == 0x0F0F)
                        && data[2] == 0x16830000)
                        dfd_valid = true;
        }

        return dfd_valid;
}

void reset_snoop_filter_ctrl(void)
{
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_DFD_RESET_SNOOP_FILTER_MAGIC, 0, 0, 0);
}

static void setup_snoop_filter_ram_ctrl(void)
{
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_DFD_SETUP_SNOOP_FILTER_MAGIC, 0, 0, 0);
}

static void return_snoop_filter_ram_ctrl(void)
{
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_DFD_RETURN_SNOOP_FILTER_MAGIC, 0, 0, 0);
}

static void circular_buffer_lock(void)
{
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_CIRCULAR_BUFFER_LOCK, 0, 0, 0);
}

static void circular_buffer_unlock(void)
{
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_CIRCULAR_BUFFER_UNLOCK, 0, 0, 0);
}

unsigned int plt_get_dfd_dump_type(void)
{
	return DFD_DUMP_TO_DRAM;
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
	ret = systracker_get((void **)&buf, len, 32);
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
	int ret;
	unsigned int datasize = 0;

	/* Save dfd buffer */
	ret = dfd_get((void **)&buf, len);

	if (buf != NULL) {
		if (*len > 0)
			datasize = dev_write(buf, *len);
		dfd_put((void **)&buf);
	}

	return datasize;
}

void platform_clear_all_on_mux(void)
{
	/* clear rg_mcu_pwr_iso_dis */
	writel(readl(MCU_ALL_PWR_ON_CTRL) & ~(1 << 2), MCU_ALL_PWR_ON_CTRL);
	dsb();

	/* clear rg_mcu_pwr_on */
	writel(readl(MCU_ALL_PWR_ON_CTRL) & ~(1 << 1), MCU_ALL_PWR_ON_CTRL);
	dsb();
}

/* SPM Debug Features */
static unsigned int spm_wdt_latch_regs[] = {
	SLEEP_BASE + 0x800, /* PCM_WDT_LATCH_0 */
	SLEEP_BASE + 0x804, /* PCM_WDT_LATCH_1 */
	SLEEP_BASE + 0x808, /* PCM_WDT_LATCH_2 */
	SLEEP_BASE + 0x80C, /* PCM_WDT_LATCH_3 */
	SLEEP_BASE + 0x810, /* PCM_WDT_LATCH_4 */
	SLEEP_BASE + 0x814, /* PCM_WDT_LATCH_5 */
	SLEEP_BASE + 0x818, /* PCM_WDT_LATCH_6 */
	SLEEP_BASE + 0x81C, /* PCM_WDT_LATCH_7 */
	SLEEP_BASE + 0x820, /* PCM_WDT_LATCH_8 */
	SLEEP_BASE + 0x824, /* PCM_WDT_LATCH_9 */
	SLEEP_BASE + 0x828, /* PCM_WDT_LATCH_10 */
	SLEEP_BASE + 0x82C, /* PCM_WDT_LATCH_11 */
	SLEEP_BASE + 0x830, /* PCM_WDT_LATCH_12 */
	SLEEP_BASE + 0x834, /* PCM_WDT_LATCH_13 */
	SLEEP_BASE + 0x838, /* PCM_WDT_LATCH_14 */
	SLEEP_BASE + 0x83C, /* PCM_WDT_LATCH_15 */
	SLEEP_BASE + 0x840, /* DVFSRC_IRQ_LATCH_0 */
	SLEEP_BASE + 0x848, /* DVFSRC_IRQ_LATCH_1 */
	SLEEP_BASE + 0x850, /* DRAMC_GATING_ERR_LATCH_CH0_0 */
	SLEEP_BASE + 0x854, /* DRAMC_GATING_ERR_LATCH_CH0_1 */
	SLEEP_BASE + 0x858, /* DRAMC_GATING_ERR_LATCH_CH0_2 */
	SLEEP_BASE + 0x85C, /* DRAMC_GATING_ERR_LATCH_CH0_3 */
	SLEEP_BASE + 0x860, /* DRAMC_GATING_ERR_LATCH_CH0_4 */
	SLEEP_BASE + 0x864, /* DRAMC_GATING_ERR_LATCH_CH0_5 */
	SLEEP_BASE + 0x868, /* DRAMC_GATING_ERR_LATCH_CH0_6 */
	SLEEP_BASE + 0x86C, /* DRAMC_GATING_ERR_LATCH_CH0_7 */
	SLEEP_BASE + 0x870, /* DRAMC_GATING_ERR_LATCH_CH0_8 */
	SLEEP_BASE + 0x880, /* DRAMC_GATING_ERR_LATCH_CH1_0 */
	SLEEP_BASE + 0x884, /* DRAMC_GATING_ERR_LATCH_CH1_1 */
	SLEEP_BASE + 0x888, /* DRAMC_GATING_ERR_LATCH_CH1_2 */
	SLEEP_BASE + 0x88C, /* DRAMC_GATING_ERR_LATCH_CH1_3 */
	SLEEP_BASE + 0x890, /* DRAMC_GATING_ERR_LATCH_CH1_4 */
	SLEEP_BASE + 0x894, /* DRAMC_GATING_ERR_LATCH_CH1_5 */
	SLEEP_BASE + 0x898, /* DRAMC_GATING_ERR_LATCH_CH1_6 */
	SLEEP_BASE + 0x89C, /* DRAMC_GATING_ERR_LATCH_CH1_7 */
	SLEEP_BASE + 0x8A0, /* DRAMC_GATING_ERR_LATCH_CH1_8 */
	SLEEP_BASE + 0x8B0, /* PCM_WDT_LATCH_SPARE_0 */
	SLEEP_BASE + 0x8B4, /* PCM_WDT_LATCH_SPARE_1 */
	SLEEP_BASE + 0x8B8, /* DRAMC_GATING_ERR_LATCH_SPARE_0 */
	SLEEP_BASE + 0x8BC, /* PCM_WDT_LATCH_16 */
	SLEEP_BASE + 0x8D0, /* PCM_WDT_LATCH_17 */
	SLEEP_BASE + 0x8D4, /* PCM_WDT_LATCH_18 */
	SLEEP_BASE + 0x8D8, /* PCM_WDT_LATCH_CONN_0 */
	SLEEP_BASE + 0x8DC, /* PCM_WDT_LATCH_CONN_1 */
	SLEEP_BASE + 0x8E0, /* PCM_WDT_LATCH_CONN_2 */
};

#define DVFSRC_DUMP	(DVFSRC_BASE + 0xBF4)
#define DVFSRC_SIZE	0xE0
#define DVFSRC_LAST_L	(DVFSRC_BASE + 0xB0C)
#define DVFSRC_SRAM_DUMP (0x0011BBD0)
#define DVFSRC_SRAM_SIZE 0x10

/* need to check aee_db_file_info[] @ app/mt_boot/aee/KEDump.c */
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
	val = readl(DVFSRC_LAST_L);
	*wp += sprintf(buf + *wp,
		"DVFSRC regs(0x%x) = 0x%08x\n", DVFSRC_LAST_L, val);
	for (i = 0; i < DVFSRC_SIZE; i += 4) {
		val = readl(DVFSRC_DUMP + i);
		*wp += sprintf(buf + *wp,
			"DVFSRC regs(0x%x) = 0x%08x\n", DVFSRC_DUMP + i, val);
	}
	for (i = 0; i < DVFSRC_SRAM_SIZE; i += 4) {
		val = readl(DVFSRC_SRAM_DUMP + i);
		*wp += sprintf(buf + *wp,
			"DVFSRC regs(0x%x) = 0x%08x\n", DVFSRC_SRAM_DUMP + i, val);
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

/* SRAM for SPM */
#define SPM_SRAM_ADDRESS 0x10021000
#define SPM_SRAM_LENGTH  0x1000 /* 4K bytes */

static int plat_spm_sram_get(void **data, int *len)
{
	*data = (void *)SPM_SRAM_ADDRESS;
	*len  = SPM_SRAM_LENGTH;
	return 1;
}

static unsigned int save_spm_sram_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	if (plat_spm_sram_get((void **)&buf, len)) {
		datasize = dev_write(buf, *len);
	}

	return datasize;
}

/* FOR DRAMC data and DRAM Calibration Log
*
* This area is applied for DRAM related debug.
*/
/* DRAMC data */
#define DRAM_DEBUG_SRAM_ADDRESS 0x11D800
#define DRAM_DEBUG_SRAM_LENGTH  1024
static int plat_dram_debug_get(void **data, int *len)
{
	*data = (void *)DRAM_DEBUG_SRAM_ADDRESS;
	*len = DRAM_DEBUG_SRAM_LENGTH;
	return 1;
}

/* shared SRAM for DRAMLOG calibration log */
#define DRAM_KLOG_SRAM_ADDRESS 0x0011E000
#define DRAM_KLOG_SRAM_LENGTH  8192
#define DRAM_KLOG_VALID_ADDRESS 0x0011E00C
static int plat_dram_klog_get(void **data, int *len)
{
	*data = (void *)DRAM_KLOG_SRAM_ADDRESS;
	*len = DRAM_KLOG_SRAM_LENGTH;
	return 1;
}

static bool plat_dram_has_klog(void)
{
	if (*(volatile unsigned int*)DRAM_KLOG_VALID_ADDRESS)
		return true;

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
static unsigned int save_sspm_coredump(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int *buf = NULL;
	unsigned int datasize = 0;
	int retry = SSPM_COREDUP_RETRY;

	if (!(*(unsigned int *)SSPM_BACKUP)) {
		return 0;
	}

	do {
		buf = *(unsigned int **)(SSPM_DM_ADDR);
		*len = *(int *)SSPM_DM_SZ;
		if (*len > 0) {
			datasize = dev_write( buf, *len);
			break;
		} else {
			udelay(100);
		}
	} while ( --retry);

	buf = *(unsigned int **)(SSPM_RM_ADDR);
	*len = *(int *)SSPM_RM_SZ;
	if (*len > 0) {
		    datasize += dev_write( buf, *len);
	}

	return datasize;
}

static unsigned int save_sspm_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0, tbufl, tbufh, r, i, j;
	int length = 0;
	char dispatch;
	unsigned int ahb_status, ahb_addr_m0, ahb_addr_m1, ahb_addr_m2;

	buf = malloc(SSPM_DATA_BUF_SZ);
	if (!buf) {
		return 0;
	}

	ahb_status  = DRV_Reg32(SSPM_AHB_STATUS);
	ahb_addr_m0 = DRV_Reg32(SSPM_AHB_M0_ADDR);
	ahb_addr_m1 = DRV_Reg32(SSPM_AHB_M1_ADDR);
	ahb_addr_m2 = DRV_Reg32(SSPM_AHB_M2_ADDR);

#define CHK_PENDING(n)  ((ahb_status & (1 << (n))) == 0 )
#define CHK_MASTER(n)   ((ahb_status & (1 << (n))) != 0 )

	if (CHK_PENDING(17)) {
		/* M0 trans is pending*/
		if (((ahb_addr_m0 >= SYSRAM_START) && (ahb_addr_m0 < SYSRAM_END)) || (ahb_addr_m0 >= DRAM_START))
			dispatch = 'P'; /* Platform owner */
		else
			dispatch = 'S'; /* SSPM owner */
	} else if ((CHK_PENDING(18) && CHK_MASTER(3)) || CHK_PENDING(19)) {
		/* M1 or M2 trans is pending*/
		dispatch = 'P'; /* Platform owner */
	} else {
		dispatch = 'L'; /* To see SSPM_LAST_LOG */
	}

	memset(buf, 0, SSPM_DATA_BUF_SZ);
	length += snprintf(buf + length, (SSPM_DATA_BUF_SZ-1) - length,
		"AHB_STATUS: 0x%08x\n"
		"AHB_M0_ADDR: 0x%x\n"
		"AHB_M1_ADDR: 0x%x\n"
		"AHB_M2_ADDR: 0x%x\n"
		"LastSP: 0x%x\n"
		"LastLR: 0x%x\n"
		"LastPC: 0x%x\n"
		"Dispatch: %c\n",
		ahb_status, ahb_addr_m0, ahb_addr_m1, ahb_addr_m2,
		DRV_Reg32(SSPM_SP), DRV_Reg32(SSPM_LR), DRV_Reg32(SSPM_PC), dispatch);

	r = DRV_Reg32(SSPM_TBUF_WPTR);
	length += snprintf(buf + length, (SSPM_DATA_BUF_SZ-1) - length, "\nTBUF_WPTR=%u\n", r);

	for (i = 0, j = r; i < 16; ++i, j = (j-1) & 0xF) {
		DRV_WriteReg32(SSPM_DBG_SEL, j);
		tbufl = DRV_Reg32(SSPM_TBUFL);
		tbufh = DRV_Reg32(SSPM_TBUFH);
		length += snprintf(buf + length, (SSPM_DATA_BUF_SZ-1) - length, "%u: TBUF[%u] H=0x%x L=0x%x\n", i, j, tbufh, tbufl);
	}

	*len = length;

	if (*len > 0) {
		datasize = dev_write((unsigned int*)buf, *len);
	}

	free(buf);

	return datasize;
}

static unsigned int save_sspm_xfile(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int *buf = NULL;
	unsigned int *sspm_info = NULL;
	unsigned int datasize = 0;
    int ret;

	/* Get the information stored in *SSPM_INFO by preloader
	    struct sspm_info_t {
	        unsigned int sspm_dm_ofs;
	        unsigned int sspm_dm_sz;
	        unsigned int rd_ofs;
	        unsigned int rd_sz;
	        unsigned int xfile_addr;
	        unsigned int xfile_sz;
	    };
	*/

#ifdef MTK_3LEVEL_PAGETABLE
    ret = arch_mmu_map(ROUNDDOWN(*(uint64_t *)(SSPM_INFO), SECTION_SIZE),
            ROUNDDOWN(*(uint32_t *)(SSPM_INFO), SECTION_SIZE),
            MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
            SECTION_SIZE);

    if (ret) {
        dprintf(CRITICAL, "kedump: mmu map to 0x%llx fail(%d), SSPM dump might fail.\n",
            (unsigned long long)ROUNDDOWN(*(uint64_t *)(SSPM_INFO), SECTION_SIZE), ret);
        return 0;
    }
#endif

    sspm_info = *(unsigned int **)(SSPM_INFO);
    buf = *(unsigned int **)(sspm_info + 4);
    *len = *(int *)(sspm_info + 5);
    dprintf(CRITICAL, "sspm buf 0x%x, len:0x%x\n", *buf, *len);

	if (*len > 0) {
		datasize = dev_write( buf, *len);
	}

	return datasize;
}

static unsigned int save_sspm_last_log(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int *buf = NULL;
	unsigned int datasize = 0;

	buf = *(unsigned int **)(SSPM_LASTK_ADDR);
	*len = *(int *)SSPM_LASTK_SZ;
	if (*len > 0) {
		datasize = dev_write( buf, *len);
	}

	return datasize;
}
#endif

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

#ifdef MTK_AUDIODSP_SUPPORT
#define ADSP_EE_SIZE 0x11000 //68KB
static int adsp_crash_dump(void *crash_buffer)
{
	unsigned int offset = 0;

	if (ADSP_EE_SIZE < (ADSP_ITCM_SIZE + ADSP_DTCM_SIZE)) {
		dprintf(CRITICAL, "adsp TCM size > alloc size\n");
		return 0;
	}
	/* all TCM enable clock and release cpu reset */
	DRV_SetReg32(MODULE_SW_CG_3_CLR, 0x1<<27);
	DRV_ClrReg8(ADSP_A_REBOOT, 0x11);

	memcpy((void *)crash_buffer,
			(void *)(ADSP_ITCM_BASE), (ADSP_ITCM_SIZE));
	offset += ADSP_ITCM_SIZE;
	memcpy((void *)(crash_buffer + offset),
			(void *)(ADSP_DTCM_BASE), (ADSP_DTCM_SIZE));
	offset += ADSP_DTCM_SIZE;

	return offset;
}
static unsigned int save_adsp_coredump(u64 offset, int *len, CALLBACK dev_write)
{
	int memory_dump_size;

	unsigned char *output = malloc(ADSP_EE_SIZE);
	if (!output) {
		return 0;
	}
	memory_dump_size = adsp_crash_dump(output);

	if (memory_dump_size > ADSP_EE_SIZE) {
		dprintf(CRITICAL, "adsp memory_dump_size ERR %d\n", memory_dump_size);
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
#define HVFS_SRAM_ADDRESS 0x0011bc00
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

/* INFRA Debug Features */
static unsigned int infra_wdt_latch_regs[] = {
	INFRA_AO_MON_0,
	INFRA_AO_MON_1,
	INFRA_AO_MON_2,
	INFRA_AO_MON_3,
};


/* need to check aee_db_file_info[] @ app/mt_boot/aee/KEDump.c */
#define INFRA_DATA_BUF_LENGTH (4096)

static int infra_dump_data(char *buf, int *wp)
{
	unsigned int i;
	unsigned val;

	if (buf == NULL || wp == NULL)
		return -1;

	for (i = 0; i < (sizeof(infra_wdt_latch_regs)/sizeof(unsigned int)); i++) {
		val = readl(infra_wdt_latch_regs[i]);
		*wp += sprintf(buf + *wp,
				"INFRA CG regs(0x%x) = 0x%x\n",
				infra_wdt_latch_regs[i], val);
	}
	return 1;
}

int infra_data_get(void **data, int *len)
{
	int ret;

	*len = 0;
	*data = malloc(INFRA_DATA_BUF_LENGTH);
	if (*data == NULL)
		return 0;

	ret = infra_dump_data(*data, len);
	if (ret < 0 || *len > INFRA_DATA_BUF_LENGTH) {
		*len = (*len > INFRA_DATA_BUF_LENGTH) ? INFRA_DATA_BUF_LENGTH : *len;
		return ret;
	}

	return 1;
}

void infra_data_put(void **data)
{
	free(*data);
}

static unsigned int save_infra_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	/* Save SPM buffer */
	infra_data_get((void **)&buf, len);
	if (buf != NULL) {
		if (*len > 0)
			datasize = dev_write(buf, *len);
		infra_data_put((void **)&buf);
	}

	return datasize;
}


unsigned int plat_is_perisys_timeout(const struct plt_cfg_bus_latch *self)
{
	return (readl(PERICFG_BASE + self->perisys_offsets.bus_peri_r1) & 1);
}

unsigned int plt_infrasys_is_timeout(const struct plt_cfg_bus_latch *self)
{
	return (readl(INFRACFG_AO_BASE + self->infrasys_offsets.bus_infra_ctrl) & 1);
}

void plat_perisys_monitor_init(const struct plt_cfg_bus_latch *self)
{
	/* set PERIBUS_TIMEOUT_THRE and PERIBUS_TIMEOUT_THRE_TYPE */
	writel(self->perisys_timeout, PERICFG_BASE + self->perisys_offsets.bus_peri_r0);

	/* set PERIBUS_DBG_EN and PERIBUS_DBG_CKEN*/
	writel(0xc, PERICFG_BASE + self->perisys_offsets.bus_peri_r1);
}

int dfd_set_base_addr(void *fdt)
{
	int ret = 0;
	int offset;
	int cache_dump;
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

#ifdef MTK_DFD_ENABLE_CACHE_DUMP
	cache_dump = 1;
#else
	cache_dump = 0;
#endif
	cache_dump = cpu_to_fdt32(cache_dump);
	ret = fdt_setprop(fdt, offset, "dfd,cache_dump_support", &cache_dump, sizeof(cache_dump));
	if (ret < 0)
		return ret;

	/*
	 * write base address[31:1] from AP view to plat_sram_flag2[31:1]
	 * write base address[32:32] from AP view to plat_sram_flag2[0:0]
	 */
	plat = (DEF_PLAT_SRAM_FLAG *)get_dbg_info_base(PLAT_SRAM_FLAG_KEY);
	if (!plat) {
		dprintf(CRITICAL, "[dfd] error: plat == NULL\n");
		return -1;
	}
	plat->plat_sram_flag2 = (ap_addr & ~(0x1)) | ((ap_addr >> 32) & 0x1);

	dprintf(CRITICAL, "[dfd] plat->plat_sram_flag2 = 0x%lx, addr = 0x%llx, addr_msb = 0x%lx\n", plat->plat_sram_flag2,
			        addr, addr_msb);
	return ret;
}

/* platform initial function */
int platform_debug_init(void)
{
	/* function pointer assignment */
	plat_spm_data_get = save_spm_data;
	plat_spm_sram_data_get = save_spm_sram_data;
	plat_dram_get = save_dram_data;
	plat_cpu_bus_get = save_cpu_bus_data;
#ifdef MTK_TINYSYS_SSPM_SUPPORT
	plat_sspm_coredump_get = save_sspm_coredump;
	plat_sspm_data_get = save_sspm_data;
	plat_sspm_xfile_get = save_sspm_xfile;
	plat_sspm_log_get = save_sspm_last_log;
#endif
#ifdef MTK_TINYSYS_SCP_SUPPORT
	plat_scp_coredump_get = save_scp_coredump;
#endif
	plat_hvfs_get = save_hvfs_data;
	plat_dur_lkdump_get = save_log_dur_lkdump;
	plat_mcdi_get = save_mcdi_data;

	plat_dfd20_get = save_dfd_data;
	dfd_op.acquire_ram_control = setup_snoop_filter_ram_ctrl;
	dfd_op.release_ram_control = return_snoop_filter_ram_ctrl;
	circular_buffer_op.lock = circular_buffer_lock;
	circular_buffer_op.unlock = circular_buffer_unlock;
	dfd_op.check_dfd_valid = check_dfd_valid;

	plat_infra_cg_get = save_infra_data;
#ifdef MTK_AUDIODSP_SUPPORT
	plat_adsp_coredump_get = save_adsp_coredump;
#endif

	/* routine tasks */
	plat_write_dram_klog();

	return 1;
}
