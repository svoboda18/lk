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
#include <stdlib.h>
#include <dev/aee_platform_debug.h>
#ifdef MTK_GPT_SCHEME_SUPPORT
#include <platform/partition.h>
#else
#include <mt_partition.h>
#endif
#include <printf.h>
#include <arch/arm/mmu.h>
#include <platform/plat_atf_dbg_info.h>
#include <part_interface.h>

unsigned int (* plat_dfd20_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_dram_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_cpu_bus_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_spm_data_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_spm_sram_data_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_atf_log_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_atf_crash_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_atf_raw_log_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_atf_rdump_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_hvfs_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
#ifdef MTK_TINYSYS_SSPM_SUPPORT
unsigned int (* plat_sspm_coredump_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_sspm_data_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_sspm_xfile_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_sspm_log_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
#endif
unsigned int (* plat_pllk_last_log_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_dur_lkdump_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_mcdi_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
#ifdef MTK_TINYSYS_SCP_SUPPORT
unsigned int (* plat_scp_coredump_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
#endif
unsigned int (* plat_infra_cg_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
#ifdef MTK_AUDIODSP_SUPPORT
unsigned int (* plat_adsp_coredump_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
#endif
#ifdef MTK_TINYSYS_MCUPM_SUPPORT
unsigned int (* plat_mcupm_coredump_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_mcupm_data_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_mcupm_xfile_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
unsigned int (* plat_mcupm_log_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
#endif
#ifdef MTK_PICACHU_SUPPORT
unsigned int (* plat_picachu_log_get)(u64 offset, int *len, CALLBACK dev_write) = NULL;
#endif

/* in case that platform didn't support platform_debug_init() */
int platform_debug_init(void) __attribute__((weak));
int platform_debug_init(void)
{
	return 0;
}

int lkdump_debug_init(void)
{
	if (g_boot_arg->boot_mode != DOWNLOAD_BOOT)
		atf_log_init();

	return platform_debug_init();
}

/* function pointer should be set after platform_debug_init() */
unsigned int kedump_plat_savelog(int condition, u64 offset, int *len, CALLBACK dev_write)
{
	switch (condition) {
		case AEE_PLAT_DFD20:
			return (!plat_dfd20_get ? 0 : plat_dfd20_get(offset, len, dev_write));
		case AEE_PLAT_DRAM:
			return (!plat_dram_get ? 0 : plat_dram_get(offset, len, dev_write));
		case AEE_PLAT_CPU_BUS:
			return (!plat_cpu_bus_get ? 0 : plat_cpu_bus_get(offset, len, dev_write));
		case AEE_PLAT_SPM_DATA:
			return (!plat_spm_data_get ? 0 : plat_spm_data_get(offset, len, dev_write));
		case AEE_PLAT_SPM_SRAM_DATA:
                        return (!plat_spm_sram_data_get ? 0 : plat_spm_sram_data_get(offset, len, dev_write));
		case AEE_PLAT_ATF_LAST_LOG:
			return (!plat_atf_log_get ? 0 : plat_atf_log_get(offset, len, dev_write));
		case AEE_PLAT_ATF_CRASH_REPORT:
			return (!plat_atf_crash_get ? 0 : plat_atf_crash_get(offset, len, dev_write));
		case AEE_PLAT_ATF_RAW_LOG:
			return (!plat_atf_raw_log_get ? 0 : plat_atf_raw_log_get(offset, len, dev_write));
		case AEE_PLAT_ATF_RDUMP_LOG:
			return (!plat_atf_rdump_get ? 0 : plat_atf_rdump_get(offset, len, dev_write));
		case AEE_PLAT_HVFS:
			return (!plat_hvfs_get ? 0 : plat_hvfs_get(offset, len, dev_write));
#ifdef MTK_TINYSYS_SSPM_SUPPORT
		case AEE_PLAT_SSPM_COREDUMP:
			return (!plat_sspm_coredump_get ? 0 : plat_sspm_coredump_get(offset, len, dev_write));
		case AEE_PLAT_SSPM_DATA:
			return (!plat_sspm_data_get ? 0 : plat_sspm_data_get(offset, len, dev_write));
		case AEE_PLAT_SSPM_XFILE:
			return (!plat_sspm_xfile_get ? 0 : plat_sspm_xfile_get(offset, len, dev_write));
		case AEE_PLAT_SSPM_LAST_LOG:
			return (!plat_sspm_log_get ? 0 : plat_sspm_log_get(offset, len, dev_write));
#endif
		case AEE_PLAT_PLLK_LAST_LOG:
			return (!plat_pllk_last_log_get ? 0 : plat_pllk_last_log_get(offset, len, dev_write));
		case AEE_PLAT_LOG_DUR_LKDUMP:
			return (!plat_dur_lkdump_get ? 0 : plat_dur_lkdump_get(offset, len, dev_write));
		case AEE_PLAT_MCDI_DATA:
			return (!plat_mcdi_get ? 0 : plat_mcdi_get(offset, len, dev_write));
#ifdef MTK_TINYSYS_SCP_SUPPORT
		case AEE_PLAT_SCP_COREDUMP:
			return (!plat_scp_coredump_get ? 0 : plat_scp_coredump_get(offset, len, dev_write));
#endif
		case AEE_PLAT_INFRA_CG:
			return (!plat_infra_cg_get ? 0 : plat_infra_cg_get(offset, len, dev_write));
#ifdef MTK_AUDIODSP_SUPPORT
		case AEE_PLAT_ADSP_COREDUMP:
			return (!plat_adsp_coredump_get ? 0 : plat_adsp_coredump_get(offset, len, dev_write));
#endif
#ifdef MTK_PICACHU_SUPPORT
		case AEE_PLAT_PICACHU_LOG:
			return (!plat_picachu_log_get ? 0 : plat_picachu_log_get(offset, len, dev_write));
#endif
		default:
			break;
	}
	return 0;
}

void mrdump_write_log(u64 offset_dst, void *data, int len)
{
	dprintf(CRITICAL, "%s: Enter\n", __func__);

	if ((offset_dst > MRDUMP_EXPDB_DRAM_KLOG_OFFSET) || (offset_dst < MRDUMP_EXPDB_BOTTOM_OFFSET)) {
		dprintf(CRITICAL, "%s: access not permitted. offset(0x%llx).\n", __func__, offset_dst);
		return;
	}

	if ((offset_dst - len) < MRDUMP_EXPDB_BOTTOM_OFFSET) {
		dprintf(CRITICAL, "%s: log size(0x%x) too big.\n", __func__, len);
		return;
	}

	int index = partition_get_index("expdb");
	part_dev_t *dev = mt_part_get_device();
	if (index == -1 || dev == NULL) {
		dprintf(CRITICAL, "%s: no %s partition[%d]\n", __func__, "expdb", index);
		return;
	}
#if defined(MTK_NEW_COMBO_EMMC_SUPPORT)  || defined(MTK_TLC_NAND_SUPPORT) || defined(MTK_MLC_NAND_SUPPORT) || defined(MTK_UFS_SUPPORT)
	int part_id = partition_get_region(index);
#endif
	u64 part_size = partition_get_size(index);
	if (part_size < offset_dst) {
		dprintf(CRITICAL, "%s: partition size(%llx) is less then reserved (%llx)\n", __func__, part_size, offset_dst);
		return;
	}
	u64 part_offset = partition_get_offset(index) + part_size - offset_dst;

	dprintf(CRITICAL, "%s: offset %lld size %lld\n", __func__, part_offset, part_size);

#if defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)
#if defined(MTK_NEW_COMBO_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)
	dev->write(dev, (uchar *)data, part_offset, len, part_id);
#else
	dev->write(dev, (uchar *)data, part_offset, len);
#endif
#else
	dev->write(dev, (uchar *)data, part_offset, len, part_id);
#endif
}

void mrdump_read_log(void *data, int len, u64 offset_src)
{
	dprintf(CRITICAL, "%s: Enter\n", __func__);

	if ((offset_src > MRDUMP_EXPDB_DRAM_KLOG_OFFSET) || (offset_src < MRDUMP_EXPDB_BOTTOM_OFFSET)) {
		dprintf(CRITICAL, "%s: access not permitted. offset(0x%llx).\n", __func__, offset_src);
		return;
	}

	if ((offset_src - len) < MRDUMP_EXPDB_BOTTOM_OFFSET) {
		dprintf(CRITICAL, "%s: log size(0x%x) too big.\n", __func__, len);
		return;
	}

	int index = partition_get_index("expdb");
	part_dev_t *dev = mt_part_get_device();
	if (index == -1 || dev == NULL) {
		dprintf(CRITICAL, "%s: no %s partition[%d]\n", __func__, "expdb", index);
		return;
	}
#if defined(MTK_NEW_COMBO_EMMC_SUPPORT) || defined(MTK_TLC_NAND_SUPPORT) || defined(MTK_MLC_NAND_SUPPORT) || defined(MTK_UFS_SUPPORT)
	int part_id = partition_get_region(index);
#endif
	u64 part_size = partition_get_size(index);
	if (part_size < offset_src) {
		dprintf(CRITICAL, "%s: partition size(%llx) is less then reserved (%llx)\n", __func__, part_size, offset_src);
		return;
	}
	u64 part_offset = partition_get_offset(index) + part_size - offset_src;

	dprintf(CRITICAL, "%s: offset %lld size %lld\n", __func__, part_offset, part_size);

#if defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)
#if defined(MTK_NEW_COMBO_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)
	dev->read(dev, part_offset, (uchar *)data, len, part_id);
#else
	dev->read(dev, part_offset, (uchar *)data, len);
#endif
#else
	dev->read(dev, part_offset, (uchar *)data, len, part_id);
#endif
}

void mrdump_read_expdb(void *data, int len, u64 offset_src)
{
	dprintf(CRITICAL, "%s: Enter\n", __func__);

	int index = partition_get_index("expdb");
	part_dev_t *dev = mt_part_get_device();
	if (index == -1 || dev == NULL) {
		dprintf(CRITICAL, "%s: no %s partition[%d]\n", __func__, "expdb", index);
		return;
	}
#if defined(MTK_NEW_COMBO_EMMC_SUPPORT) || defined(MTK_TLC_NAND_SUPPORT) || defined(MTK_MLC_NAND_SUPPORT) || defined(MTK_UFS_SUPPORT)
	int part_id = partition_get_region(index);
#endif
	u64 part_size = partition_get_size(index);
	if (part_size < offset_src) {
		dprintf(CRITICAL, "%s: partition size(%llx) is less then reserved (%llx)\n", __func__, part_size, offset_src);
		return;
	}
	if ((offset_src + len) > (part_size - MRDUMP_EXPDB_DRAM_KLOG_OFFSET)) {
		dprintf(CRITICAL, "%s: log size(0x%x) too big.\n", __func__, len);
		return;
	}
	u64 part_offset = partition_get_offset(index) + offset_src;

	dprintf(CRITICAL, "%s: offset %lld size %lld\n", __func__, part_offset, part_size);

#if defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)
#if defined(MTK_NEW_COMBO_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)
	dev->read(dev, part_offset, (uchar *)data, len, part_id);
#else
	dev->read(dev, part_offset, (uchar *)data, len);
#endif
#else
	dev->read(dev, part_offset, (uchar *)data, len, part_id);
#endif
}

