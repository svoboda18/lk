/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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

#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <platform/boot_mode.h>
#include <part_interface.h>
#include <pal_typedefs.h>
#include <pal_assert.h>
#include <pal_log.h>
#include <platform/verified_boot.h>
#include <env.h>
#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#include <fdt_op.h>
#endif
#include <assert.h>
#include <platform/mt_adsp.h>
#if ENABLE_ADSP_EMI_PROTECTION
#include <platform/mt_emi_mpu.h>
#endif
#include <platform/errno.h>

extern void dsb(void);
extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);
/* return 0: success */
extern int verify_load_adsp_image(char *part_name, void *addr);
extern void mtk_wdt_restart(void);
extern BOOT_ARGUMENT *g_boot_arg;
#if defined(DEVICE_TREE_SUPPORT)
/*dts header*/
#endif

static int load_adsp_status = 0;
static uint32_t adsp_dram_addr = 0;
static char *adsp_part_name = "audio_dsp";	/* name registered in partition */

static char *adsp_partition_name(void)
{
	return adsp_part_name;
}

int load_adsp_image(char *part_name, char *img_name, void *addr)
{
	int ret = 0;

#ifdef MTK_SECURITY_SW_SUPPORT
	/* we use this API because audio dsp TCM 8 byte access
	 * limitation */
	ret = img_auth_stor(part_name, img_name, 0x1);
	if (ret != 0) {
		pal_log_err("<ASSERT> %s:line %d\n", __FILE__, __LINE__);
		PAL_ASSERT(0);
	}
#endif /* MTK_SECURITY_SW_SUPPORT */

	ret = mboot_common_load_part(part_name, img_name, addr);
	if (ret <= 0)
		ret = -1;

	return ret;
}

int load_adsp(void)
{
	int ret;
	char *part_name;
	unsigned long long perm;

    /* check if adsp is turned off manually */
	if (get_adsp_status() == (unsigned int) 0) {
		dprintf(CRITICAL, "[ADSP] get_adsp_status fail\n");
		goto error;
	}

	adsp_dram_addr = (uint32_t) mblock_reserve_ext(&g_boot_arg->mblock_info, ADSP_DRAM_SIZE, ADSP_DRAM_ALIGN, ADSP_DRAM_LIMIT, 0, ADSP_MEM_RESERVED_KEY);
	if(adsp_dram_addr != LK_ADSP_BASE) {
		dprintf(CRITICAL, "[ADSP] mblock_reserve fail\n");
		goto error;
	}

	part_name = adsp_partition_name();
	if(!part_name) {
		dprintf(CRITICAL, "[ADSP]get partition failed\n");
		goto error;
	}

	/* load adsp image */
	ret = verify_load_adsp_image(part_name, (void *)adsp_dram_addr);
	if (ret < 0) {
		dprintf(CRITICAL, "[ADSP]verify %s failed, ret=%d(-1: load image fail, -5:sram size<0, -6:sram size not 32*N)\n", part_name, ret);
		goto error;
	}

#ifdef MT_DO_SUPPORT
	/* HIFI3 does not support now. */
#endif

    /* clean dcache & icache before set up EMI MPU */
    arch_sync_cache_range((addr_t)adsp_dram_addr, ADSP_DRAM_SIZE);

    /* setup EMI MPU
     * domain 0: AP
     * domain 10: ADSP
     */
#if ENABLE_ADSP_EMI_PROTECTION
	struct emi_region_info_t region_info;

	region_info.start = adsp_dram_addr;
	region_info.end = adsp_dram_addr + ADSP_DRAM_SIZE - 0x1;
	region_info.region = MPU_REGION_ID_ADSP_RO_MEM;
	SET_ACCESS_PERMISSION(region_info.apc, UNLOCK,
				  FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
				  FORBIDDEN, NO_PROTECTION, FORBIDDEN, FORBIDDEN,
				  FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
				  FORBIDDEN, FORBIDDEN, FORBIDDEN, NO_PROTECTION);
	emi_mpu_set_protection(&region_info);

#endif
    dprintf(INFO, "%s(): done\n", __func__);

    load_adsp_status = 1;
    return 0;

error:
    /*
     * @ret = 0, malloc() error
     * @ret < 0, eror code from load_adsp_image()
     */
    load_adsp_status = -1;
    return -1;
}

unsigned int get_adsp_status(void)
{
	unsigned int adsp_status;

	/*if there is no env[adsp], adsp should be still enabled*/
	adsp_status = (get_env("adsp") == NULL) ? 1 : atoi(get_env("adsp"));
	dprintf(CRITICAL,"[ADSP] current setting is %d.\n", adsp_status);
	return adsp_status;
}

unsigned int set_adsp_status(unsigned int en)
{
	char *ADSP_STATUS[2] = {"0","1"};

	get_adsp_status();
	if (set_env("adsp", ADSP_STATUS[en]) == 0) {
		dprintf(CRITICAL,"[ADSP]set ADSP %s success. Plz reboot to make it applied.\n",ADSP_STATUS[en]);
		return 0;
	} else {
		dprintf(CRITICAL,"[ADSP]set ADSP %s fail.\n",ADSP_STATUS[en]);
		return 1;
	}
}

#ifdef DEVICE_TREE_SUPPORT
int platform_fdt_adsp(void *fdt)
{
	int  nodeoffset;
	char *ret;

	dprintf(CRITICAL, "%s()\n", __func__);
	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, ADSP_DTS_COMPATIBLE);

	if (nodeoffset >= 0) {
		if (load_adsp_status <= 0)
			ret = "fail";
		else
			ret = "okay";

		dprintf(CRITICAL, "status=%s\n", ret);

		fdt_setprop(fdt, nodeoffset, "status", ret, strlen(ret));

		return 0;
	}

	return 1;

}

#if defined(DEVICE_TREE_SUPPORT)
/* Load ADSP sram size from dts */

int platform_fdt_adsp_get_sram_size(void)
{
	int nodeoffset;
	uint32_t *data = NULL;
	int len = 0;
	uint32_t sram_size = 0;
	void *kernel_fdt = get_kernel_fdt();

	if (kernel_fdt == NULL)
		panic("kernel fdt is NULL!\n");

	dprintf(INFO, "%s()\n", __func__);
	nodeoffset = fdt_node_offset_by_compatible(kernel_fdt, -1, ADSP_DTS_COMPATIBLE);
	if (nodeoffset >= 0) {
		data = (unsigned int *)fdt_getprop(kernel_fdt, nodeoffset, "adsp_sram_size", &len);
		if (data == NULL) {
			dprintf(CRITICAL, "adsp get dts info fail\n");
			return -1;
		}

		sram_size = fdt32_to_cpu(*(uint32_t *)data);
		dprintf(INFO, "adsp sram size = %d, size len = %d\n", sram_size, len);
		return sram_size;
	} else {
		dpirntf(CRITICAL, "capatible %s is not found in dts!\n", ADSP_DTS_COMPATIBLE);
	}
	return -1; /*error from fdt_node_offset_by_compatible() */
}

#endif
#endif

int verify_load_adsp_image(char *part_name, void *addr)
{
	void *sys_prog_ptr, *sys_data_ptr, *fw_ptr = NULL;
	int sys_prog_size, sys_data_size, fw_size;

	/* step 1: enable adsp clock & release CPU to access hifi3*/
	DRV_SetReg32(MODULE_SW_CG_3_CLR, 0x1<<27);
	DRV_ClrReg8(ADSP_A_REBOOT, 0x11);

	/* step 1: load/verify audio dsp iTCM */
	sys_prog_ptr = (void *)ADSP_ITCM_BASE;
	sys_prog_size = load_adsp_image(part_name, IRAM_NAME_ADSP_A, sys_prog_ptr);
	if (sys_prog_size != ADSP_ITCM_SIZE) {
		dprintf(CRITICAL, "[ADSP] load_adsp_image fail %s(addr=%x, size=%x)\n", IRAM_NAME_ADSP_A, sys_prog_ptr, sys_prog_size);
		return -1;
	} else {
		dprintf(INFO, "[ADSP] load_adsp_image success %s(%x)\n", IRAM_NAME_ADSP_A, sys_prog_ptr);
	}

	/* step 2: load/verify audio dsp dTCM */
	sys_data_ptr = (void *)ADSP_DTCM_BASE;
	sys_data_size = load_adsp_image(part_name, DRAM_NAME_ADSP_A, sys_data_ptr);
	if (sys_data_size != ADSP_DTCM_SIZE) {
		dprintf(CRITICAL, "[ADSP] load_adsp_image fail %s(addr=%x, size=%x)\n", DRAM_NAME_ADSP_A, sys_data_ptr, sys_data_size);
		return -1;
	} else {
		dprintf(INFO, "[ADSP] load_adsp_image success %s(%x)\n", DRAM_NAME_ADSP_A, sys_data_ptr);
	}

	/* step 3: enable DRAM */
    /* system has enabled DRAM for use */

	/* step 4: load/verify audio dsp dram */
	fw_ptr = addr;
	fw_size = load_adsp_image(part_name, FIRMWARE_NAME_ADSP_A, fw_ptr);
	if (fw_size <= 0) {
		dprintf(CRITICAL, "[ADSP] load_adsp_image fail %s(addr=%x, size=%x)\n", FIRMWARE_NAME_ADSP_A, fw_ptr, fw_size);
		return -1;
	} else {
		dprintf(INFO, "[ADSP] load_adsp_image success %s(%x)\n", FIRMWARE_NAME_ADSP_A, fw_ptr);
	}

	/* step 5: save adsp firmware info in dTCM */
	struct adsp_region_info_t *adsp_region_info = ADSP_INFO_FIRMWARE_START;
	memset(ADSP_INFO_FIRMWARE_START, 0xFF, ADSP_MPU_INFO_SIZE);
	adsp_region_info->adsp_region_start = (uint32_t)fw_ptr;
	adsp_region_info->adsp_region_size = (uint32_t)ADSP_DRAM_SIZE;
	dsb();

	/* FIXME: step 6: disable adsp clock */
//	DRV_SetReg32(MODULE_SW_CG_3_SET, 0x1<<27); //	Bit [27] = 1'b1 AP enable SW CG ==> Disable Hifi3 clock

	return fw_size;
}

/* adsp power off (DSP suspend) */
void disable_adsp_hw(void)
{
	DRV_ClrReg32(CLK_CFG_10, 0x7<<6);	//Hifi3 Switch clock from  ADSPPLL to 26M
	DRV_ClrReg32(ADSPPLL_CON0, 0x1<<0);	//bit[0] = 1'b0	Hifi3 disable ADSPPLL 1
	DRV_SetReg32(ADSPPLL_PWR_CON0, 0x1<<1); //bit[1] = 1'b1	Hifi3 disable ADSPPLL 2
	DRV_ClrReg32(ADSPPLL_PWR_CON0, 0x1<<0);	//bit[0] = 1'b0	Hifi3 disable ADSPPLL 3
	DRV_ClrReg32(ADSP_SPM_REQ, 0xF<<0); //bit[3:0] = 4'h0	Hifi3 enable SPM resource request (leave deepidle, enter normal, DRAM enable)
	DRV_ClrReg32(ADSP_DDREN_REQ, 0x1<<0); // bit[0] = 1'b0 	Hifi3 enable SPM resource request (leave deepidle, enter normal, DRAM enable)
	/* HIFI3 enter WFI */
	DRV_SetReg32(ADSP_HIFI3_IO_CONFIG, 0x1<<31); //Bit [31] = 1'b1	AP release Hifi3 RUNStall
	DRV_ClrReg32(MODULE_SW_CG_3_CLR, 0x1<<27); //	Bit [27] = 1'b1 AP enable SW CG ==> Disable Hifi3 clock
}

