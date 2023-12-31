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

#include <stdlib.h>                    /* for atoi() */
#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <platform/mt_gpt.h>              // for get_timer()
#include <arch/ops.h>                     // for arch_sync_cache_range()
#include <platform/boot_mode.h>
#include <platform/verified_boot.h>
#include <verified_boot_common.h>
#include <platform/sec_policy.h>
#include <part_interface.h>
#include <env.h>
#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#include <fdt_op.h>
#endif
#include <assert.h>
#include <platform/mt_scp.h>
#include <fdt_op.h>
#if ENABLE_SCP_EMI_PROTECTION
#include <mt_emi_mpu.h>
#endif
#include <platform/errno.h>
#ifdef MTK_AB_OTA_UPDATER
#include "bootctrl.h"
#endif


#define SCP_SRAM_LOCK_REG       (*(volatile unsigned int *)(SCP_CFG_BASE + 0x0010))
#define SCP_SRAM_LOCK_UNIT      12
#define SCP_SRAM_LOCK_SHIFT     8
#define SCP_JTAG_REG            (*(volatile unsigned int *)(SCP_CFG_BASE + 0x00A0))
#define SCP_JTAG_EN             0x0000003C
#define SCP_SRAM_EN_LOCK_REG    (*(volatile unsigned int *)(SCP_CFG_BASE + 0x00DC))
#define SCP_SRAM_EN_REG         (*(volatile unsigned int *)(SCP_CFG_BASE + 0x00E0))
#define SCP_SRAM_EN_BIT         (1 << 20)
#define SCP_SRAM_PWR_REG        (*(volatile unsigned int *)(SCP_CFG_BASE + 0x402C))
#define SCP_SET_CLK_CG          (*(volatile unsigned int *)(SCP_CFG_BASE + 0x4030))


#define SCP_EFUSE_DIS_INDEX           88
#define SCP_ROM_SIZE                  88

extern void dsb(void);
extern unsigned int get_devinfo_with_index(unsigned int index);
extern u64 physical_memory_size(void);
extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);
extern void mtk_wdt_restart(void);

unsigned int get_scp_status(void);
static int verify_load_scp_image(char *part_name, void *addr);
int platform_scp_set_sram_region(int scp_A_sram_size);

#ifdef MT_DO_SUPPORT
static int load_do(char *part_name, void *do_addr);
static void save_do_addr(void *do_addr_A, void *do_addr_B);
#endif

#if defined(DEVICE_TREE_SUPPORT)
unsigned int get_scp_status(void);
unsigned int set_scp_status(unsigned int en);
int platform_fdt_scp_get_sram_size(void);
int platform_fdt_scp(void *fdt);
#else
unsigned int get_scp_status(void) { return 0; } /* return 0, if scp disable */
unsigned int set_scp_status(unsigned int en) { return 1; }  /* return 1, if fail */
int platform_fdt_scp_get_sram_size(void) { return -1; } /* return -1, if fail */
int platform_fdt_scp(void *fdt) { return 0; } /* return 0, if success */
#endif

extern BOOT_ARGUMENT *g_boot_arg;
#if defined(DEVICE_TREE_SUPPORT)
/*dts header*/
#endif
static int load_scp_status = 0;
static void *dram_addr;
static char *scp_part_name[] = {"scp1", "scp2"};

static int load_scp_image(char *part_name, char *img_name, void *addr)
{
	uint32_t sec_ret;
	uint32_t scp_vfy_time;
	int ret;
#ifdef MTK_SECURITY_SW_SUPPORT
	unsigned int policy_entry_idx = 0;
	unsigned int img_auth_required = 0;

	policy_entry_idx = get_policy_entry_idx(part_name);
	img_auth_required = get_vfy_policy(policy_entry_idx);
	/* verify cert chain of boot img */
	if (img_auth_required) {
		scp_vfy_time = get_timer(0);
		sec_ret = sec_img_auth_init(part_name, img_name, 0);
		if (sec_ret)
			return -1;
		dprintf(CRITICAL, "[SBC] image %s cert vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(scp_vfy_time));
#ifdef MTK_SECURITY_ANTI_ROLLBACK
		sec_ret = sec_rollback_check(1);
		if (sec_ret) {
			dprintf(CRITICAL, "%s ver check fail...(0x%x)\n", img_name, sec_ret);
			return -1;
		}
#endif
	}
#endif

	ret = mboot_common_load_part(part_name, img_name, (unsigned long)addr);
	dprintf(INFO, "%s(): load %s ret=%d\n", __func__, img_name, ret);
	if (ret <= 0)
		return -1;

#ifdef MTK_SECURITY_SW_SUPPORT
	if (img_auth_required) {
		scp_vfy_time = get_timer(0);
		sec_ret = sec_img_auth(addr, ret);
		if (sec_ret)
			return -1;
		dprintf(CRITICAL, "[SBC] %s vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(scp_vfy_time));
	}
#endif

	return ret;
}

static char *scp_partition_name(void)
{
	int array_size = (int)(sizeof(scp_part_name) / sizeof(scp_part_name[0]));
	int i;

	for (i = 0; i < array_size; i++) {

		/*
		 * >0: partition active
		 *  0: partition inactive
		 * -1: partition doesn't exist
		 */
		if (partition_get_active_bit_by_name(scp_part_name[i]) > 0)
			return scp_part_name[i];
	}

	dprintf(CRITICAL, "no scp partition with active bit marked, load %s\n", scp_part_name[0]);

	return scp_part_name[0];
}

int load_scp(void)
{
	int ret;
	int scp_A_sram_size = 0;
#ifdef MTK_AB_OTA_UPDATER
	#define SCP_PARTITION_NAME_SIZE    10
	char part_name[SCP_PARTITION_NAME_SIZE];
#else
	char *part_name;
#endif

	/* check if scp is turned off manually*/
	if (get_scp_status() == 0) {
		dprintf(CRITICAL, "[SCP] get_scp_status disabled\n");
		goto error;
	}

	dram_addr = (void *)(unsigned int)mblock_reserve_ext(&g_boot_arg->mblock_info,
	            SCP_DRAM_SIZE, SCP_DRAM_ALIGN, DRAM_ADDR_MAX, 0, "SCP-reserved");
	dprintf(INFO, "[SCP] %s: dram_addr=%p\n", __func__, dram_addr);
	if (dram_addr == ((void *) 0)) {
		dprintf(CRITICAL, "[SCP] mblock_reserve fail\n");
		goto error;
	}
#ifdef MTK_AB_OTA_UPDATER
	/* Compose the partition name for A/B systems. */
	strcpy (part_name,"scp");

	char *p_AB_suffix;
	int part_name_len = strlen(part_name);

	p_AB_suffix = get_suffix();

	if (p_AB_suffix) {
		strncpy((void*)&part_name[part_name_len], (void*)p_AB_suffix,
		        sizeof(part_name) - part_name_len);
	}
	part_name[sizeof(part_name) - 1] = '\0';

#else
	part_name = scp_partition_name();
#endif /* MTK_AB_OTA_UPDATER*/
	if (!part_name) {
		dprintf(CRITICAL, "[SCP]get partition failed\n");
		goto error;
	}

	scp_A_sram_size = platform_fdt_scp_get_sram_size();
	dprintf(INFO, "[SCP] part_name=%s, scp_A_sram_size=%d\n",
	        part_name, scp_A_sram_size);
	if (scp_A_sram_size < 0) {
		goto error;
	}

	ret = verify_load_scp_image(part_name, dram_addr);
	if (ret < 0) {
		goto error;
	}

#ifdef MT_DO_SUPPORT
	int fw_size;  // FIXME: fw_size is not initialized!!!
	/* load DO bin from partition to the end of scp images */
	ret = load_do(part_name, dram_addr + (size_t)fw_size);
	if (ret < 0) {
		dprintf(CRITICAL, "[DO] load DO failed\n");
		goto error;
	} else {
		dprintf(CRITICAL, "[DO] load DO done, A + B size = %d\n", ret);
	}
	/* verify DO img size*/
	if ((ret + fw_size) > SCP_DRAM_SIZE) {
		dprintf(CRITICAL, "[DO] image + DO size > reserved, size = %d\n", ret + fw_size);
		goto error;
	}
#endif

	/*clean dcache & icache before set up EMI MPU*/
	arch_sync_cache_range((addr_t)dram_addr, SCP_DRAM_SIZE);

	/*
	 * setup EMI MPU
	 * domain 0: AP
	 * domain 3: SCP
	 */
#if ENABLE_SCP_EMI_PROTECTION
	struct emi_region_info_t region_info;
	region_info.start = (unsigned long long)(unsigned int)dram_addr;
	region_info.end = (unsigned long long)(unsigned int)(dram_addr + SCP_DRAM_SIZE - 1);
	region_info.region = SCP_EMI_REGION;

	SET_ACCESS_PERMISSION(region_info.apc, UNLOCK,
	                      FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
	                      FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
	                      FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
	                      NO_PROTECTION, FORBIDDEN, FORBIDDEN, NO_PROTECTION);
	emi_mpu_set_protection(&region_info);
#endif
	dprintf(INFO, "%s(): done\n", __func__);

	load_scp_status = 1;

	return 0;

error:
	/*
	 * @ret = 0, malloc() error
	 * @ret < 0, error code from load_scp_image()
	 */
	load_scp_status = -1;

	return -1;
}

#ifdef MT_DO_SUPPORT
#define NEXT_DO_OFFSET 8 /* to prevent scp A parsing the DOs of scp B */
/*
 * Load Dynamic Object from partition to DRAM
 * @ret: > 0 : load success, return size of total loaded DO
 *       = 0 : no DO image in partition or DO DRAM addr invalid
 */
static int load_do(char *part_name, void *do_addr)
{
	int ret, total_loaded = 0;
	void *tmp;
	void *addr_A = 0;
	void *addr_B = 0;

	dprintf(CRITICAL, "[DO] try to load scp A DO to 0x%p\n", do_addr);
	ret = mboot_common_load_part(part_name, DO_NAME_SCP_A, (unsigned long)do_addr);
	if (ret >= 0) {
		addr_A = do_addr;
		total_loaded += ret;
	} else if (ret == -EINVAL) {
		dprintf(CRITICAL, "[DO] mboot_common_load_part: cannot find scp A DO\n");
	} else {
		dprintf(CRITICAL, "[DO] mboot_common_load_part: load scp A error: %d\n", ret);
	}

	tmp = do_addr + (size_t)total_loaded + NEXT_DO_OFFSET;

	dprintf(CRITICAL, "[DO] try to load scp B DO to 0x%p\n", tmp);
	ret = mboot_common_load_part(part_name, DO_NAME_SCP_B, (unsigned long)tmp);
	if (ret >= 0) {
		addr_B = tmp;
		total_loaded += ret;
	} else if (ret == -EINVAL) {
		dprintf(CRITICAL, "[DO] mboot_common_load_part: cannot find scp B DO\n");
	} else {
		dprintf(CRITICAL, "[DO] mboot_common_load_part: load scp B error: %d\n", ret);
	}

	/* save DO head addresses to device tree */
	/* NOTE: address will be 0 if the DO bin does not exist */
	save_do_addr(addr_A, addr_B);

	return total_loaded;
}
#endif

#if defined(DEVICE_TREE_SUPPORT)
int platform_fdt_scp(void *fdt)
{
	int nodeoffset;
	char *ret;

	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, "mediatek,scp");
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[SCP] %s: getting node from dtb fails\n", __func__);
		return 1; /* return 1, if fail */
	}

	if (load_scp_status <= 0)
		ret = "disabled";
	else
		ret = "okay";

	if (fdt_setprop(fdt, nodeoffset, "status", ret, strlen(ret)) < 0) {
		dprintf(CRITICAL, "[SCP] %s: set status fails\n", __func__);
		return 1; /* return 1, if fail */
	}

	dprintf(CRITICAL, "[SCP] set core status=%s\n", ret);

	return 0; /* return 0, if success */
}

/* Load SCP sram size from dts */
int platform_fdt_scp_get_sram_size(void)
{
	int nodeoffset;
	unsigned int *data = NULL;
	int len = 0;

	dprintf(INFO, "%s()\n", __func__);
	nodeoffset = fdt_node_offset_by_compatible(get_kernel_fdt(), -1, "mediatek,scp");
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[SCP] mediatek,scp not found!\n");
		return -1;  /* return -1, if fail */
	}

	data = (unsigned int *) fdt_getprop(get_kernel_fdt(), nodeoffset, "scp_sramSize", &len);
	if (data == NULL) {
		dprintf(CRITICAL, "[SCP] get scp_sramSize info fail\n");
		return -1;  /* return -1, if fail */
	}

	dprintf(INFO, "scp sram_size=%d, len=%d\n",
	        fdt32_to_cpu(*(unsigned int *)data), len);

	return fdt32_to_cpu(*(unsigned int *)data);
}

unsigned int get_scp_status(void)
{
	int scp_status;
	int nodeoffset;
	char *data = NULL;
	int len = 0;

	nodeoffset = fdt_node_offset_by_compatible(get_kernel_fdt(), -1, "mediatek,scp");
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "scp get node from dtb fail\n");
		return 0;
	}

	data = (char*)fdt_getprop(get_kernel_fdt(), nodeoffset, "status", &len);
	if (data == NULL) {
		dprintf(CRITICAL, "scp get status from dtb fail\n");
		return 0;
	}

	if (strncmp(data, "okay", len) == 0)
		scp_status = 1; /* 1 goes for "enabled" */
	else
		scp_status = 0; /* 0 goes for "disabled" */

	char *scp_env = get_env("scp");
	scp_status = (scp_env == NULL) ? scp_status : atoi(scp_env);
	dprintf(CRITICAL,"[SCP] current setting is %d.\n", scp_status);

	return scp_status;
}

unsigned int set_scp_status(unsigned int en)
{
	char *SCP_STATUS[2] = {"0","1"};

	if (set_env("scp", SCP_STATUS[en]) == 0) {
		dprintf(CRITICAL,"[SCP]set SCP %s success. Plz reboot to make it applied.\n",SCP_STATUS[en]);
		return 0; /* return 0, if success*/
	} else {
		dprintf(CRITICAL,"[SCP]set SCP %s fail.\n",SCP_STATUS[en]);
		return 1; /* return 1, if fail */
	}
}

#endif

#ifdef MT_DO_SUPPORT
void save_do_addr(void *do_addr_A, void *do_addr_B)
{
	int offset;
	u32 addr[2];

	dprintf(INFO, "%s()\n", __func__);

	offset = fdt_node_offset_by_compatible(get_kernel_fdt(), -1, "mediatek,scp");
	if (offset >= 0) {

		addr[0] = (u32)cpu_to_fdt32((u64)do_addr_A >> 32);
		addr[1] = (u32)cpu_to_fdt32(do_addr_A);
		fdt_setprop(get_kernel_fdt(), offset, "do_addr_A", addr, sizeof(u32)*2);

		addr[0] = (u32)cpu_to_fdt32((u64)do_addr_B >> 32);
		addr[1] = (u32)cpu_to_fdt32(do_addr_B);
		fdt_setprop(get_kernel_fdt(), offset, "do_addr_B", addr, sizeof(u32)*2);

		dprintf(CRITICAL, "[DO] save DO addrs to DT, A: 0x%x, B: 0x%x\n",
		        (u32)do_addr_A, (u32)do_addr_B);
	} else {
		dprintf(CRITICAL, "[DO]ERR: DT mediatek,scp not found %s\n", offset);
	}
}
#endif

/******************************************************************************
******************************************************************************/
unsigned int get_scp_log_thru_ap_uart(void)
{
	unsigned int enable = 0;
	char *env = get_env("scp_ap_uart");

	if (env == NULL) {
		dprintf(CRITICAL, "[SCP] Get SCP log thru AP UART: 0 (default)\n");
	} else {
		enable = atoi(env);
		dprintf(CRITICAL, "[SCP] Get SCP log thru AP UART: %d\n", enable);
	}
	return enable;
}


/******************************************************************************
* Caller must make sure that the argument "en" is less than 2.
******************************************************************************/
void set_scp_log_thru_ap_uart(unsigned int en)
{
	char *en_array[2] = {"0", "1"};

	if (set_env("scp_ap_uart", en_array[en]) == 0) {
		dprintf(CRITICAL, "[SCP] Set SCP log thru AP UART: %s\n", en_array[en]);
	} else {
		dprintf(CRITICAL, "[SCP] Failed to set SCP log thru AP UART to %s!\n",
			en_array[en]);
	}
}

static int verify_load_scp_image(char *part_name, void *addr)
{
	int scp_dram_use_size = 0;
	void *ld_ptr, *fw_ptr;
	uint32_t reg_temp;
	int ld_size, fw_size;
	int l1c_size;
	void *l1c_ptr, *l1c_backup_ptr = NULL;
	int scp_sram_size;
	struct scp_region_info_st *scp_region_info;

	// step 0: enable sram, enable 1 block per time
	for (reg_temp = 0xffffffff; reg_temp != 0;) {
		reg_temp = reg_temp >> 1;
		SCP_SRAM_PWR_REG = reg_temp;
	}

	/*
	 * l1c sram, 64K / tail sram, +32k
	 * L1_SRAM_PD / d_l1c_SRAM_PD / d_l1c_tag_SRAM_PD / p_l1c_SRAM_PD / p_l1c_tag_SRAM_PD
	*/
	DRV_WriteReg32(CLK_CTRL_L1_SRAM_PD, 0);
	/* TCM_TAIL_SRAM_PD */
	DRV_WriteReg32(CLK_CTRL_TCM_TAIL_SRAM_PD, 0);

	// step 1: load/verify loader
	ld_ptr = addr;
	ld_size = load_scp_image(part_name, LOADER_NAME_SCP_A, ld_ptr);
	if (ld_size <= 0) {
		dprintf(CRITICAL, "[SCP] load_scp_image fail %s\n", LOADER_NAME_SCP_A);
		return -1;
	}
	// step 2: load/verify firmware
	fw_ptr = addr + SCP_FW_OFFSET;
	fw_size = load_scp_image(part_name, FIRMWARE_NAME_SCP_A, fw_ptr);
	if (fw_size <= 0) {
		dprintf(CRITICAL, "[SCP] load_scp_image fail %s\n", FIRMWARE_NAME_SCP_A);
		return -1;
	}
	// step 3: load/verify l1c code (optional)
	l1c_ptr = addr + SCP_L1C_OFFSET;
	l1c_size = load_scp_image(part_name, L1C_NAME_SCP_A, l1c_ptr);

	if (l1c_size > 0) {
		dprintf(INFO, "[SCP] load_scp_image %s %d bytes\n", L1C_NAME_SCP_A, l1c_size);
		// step 3.1 backup l1c code
		l1c_backup_ptr = addr + SCP_L1C_BACKUO_OFFSET;
		memcpy(l1c_backup_ptr, l1c_ptr, l1c_size);
		/* Disable scp bus wt buffer */
		DRV_WriteReg32(SCP_SYS_CTRL, DRV_Reg32(SCP_SYS_CTRL)|(0x1 << AHB_SLICE_POST_WT));
#if CFG_SCP_ULTRA_SUPPORT
		DRV_WriteReg32(BUS_QOS, (0x2 << AXI_AWULTRA) | (0x2 << AXI_ARULTRA));
#endif
		/* Read the l1c setting from image in dram */
		scp_region_info = (struct scp_region_info_st*)(ld_ptr + SCP_LOADER_SIZE);
		scp_l1c_init(scp_region_info->Il1c_con, scp_region_info->Dl1c_con);
	} else {
		DRV_WriteReg32(SCP_SYS_CTRL, DRV_Reg32(SCP_SYS_CTRL)|(0x3 << BYPASS_P_L1C));
		/* scp clk gates: l1c controller */
		DRV_WriteReg32(SCP_CLR_CLK_CG, (1 << L1C_I_CTRL_CG) | (1 << L1C_D_CTRL_CG));
		dprintf(INFO, "[SCP] no l1c support\n");
	}

	//   SCP DRAM layout
	/***********************
	*     SCP loader       *
	************************
	*     SCP Firmware     *
	************************
	*     SCP L1C          *
	************************
	*     SCP DRAM backup  *
	************************/

	// step 6: copy loader to sram
	memcpy((void *) SCP_SRAM_BASE, ld_ptr, ld_size);

    // step 7: save firmware/cache info to sram
	scp_region_info = (struct scp_region_info_st*)(SCP_SRAM_BASE + SCP_LOADER_SIZE);
	scp_region_info->ap_loader_start = (uint32_t)ld_ptr;
	scp_region_info->ap_loader_size = (uint32_t)ld_size;
	scp_region_info->ap_firmware_start = (uint32_t)fw_ptr;
#if defined(DEVICE_TREE_SUPPORT)
	scp_sram_size = platform_fdt_scp_get_sram_size();
#else
	scp_sram_size = SCP_SRAM_SIZE;
#endif
	dprintf(INFO, "[SCP]sram size=%u bytes\n", scp_sram_size);
	if ( fw_size > (scp_sram_size - SCP_FW_OFFSET) ) {
		scp_region_info->ap_firmware_size =
					(scp_sram_size - SCP_FW_OFFSET
					- L1C_SIZE(scp_region_info->Il1c_con)
					- L1C_SIZE(scp_region_info->Dl1c_con));
		dprintf(INFO, "[SCP](overlay)firmware size %d bytes\n", scp_region_info->ap_firmware_size);
	} else {
		scp_region_info->ap_firmware_size = (uint32_t)fw_size;
	}

	scp_region_info->ap_dram_start = (uint32_t)l1c_ptr;
	scp_region_info->ap_dram_size = (uint32_t)l1c_size;
	scp_region_info->ap_dram_backup_start = (uint32_t)l1c_backup_ptr;
	scp_region_info->Il1c_con = (uint32_t)L1C_SEL(L1C_IL1C)->L1C_CON;
	scp_region_info->Dl1c_con = (uint32_t)L1C_SEL(L1C_DL1C)->L1C_CON;

	dprintf(INFO, "scp_region_info->ap_loader_start 0x%x\n", scp_region_info->ap_loader_start);
	dprintf(INFO, "scp_region_info->ap_loader_size 0x%x\n", scp_region_info->ap_loader_size);
	dprintf(INFO, "scp_region_info->ap_firmware_start 0x%x\n", scp_region_info->ap_firmware_start);
	dprintf(INFO, "scp_region_info->ap_firmware_size 0x%x\n", scp_region_info->ap_firmware_size);
	dprintf(INFO, "scp_region_info->ap_dram_start 0x%x\n", scp_region_info->ap_dram_start);
	dprintf(INFO, "scp_region_info->ap_dram_size 0x%x\n", scp_region_info->ap_dram_size);
	dprintf(INFO, "scp_region_info->ap_dram_backup_start 0x%x\n", scp_region_info->ap_dram_backup_start);
	dprintf(INFO, "scp_region_info->Il1c_con 0x%x\n", scp_region_info->Il1c_con);
	dprintf(INFO, "scp_region_info->Dl1c_con 0x%x\n", scp_region_info->Dl1c_con);

	dsb();

	SCP_JTAG_REG |= SCP_JTAG_EN;
	dsb();
	return scp_dram_use_size;
}

void disable_scp_hw(void)
{
	/* turn off SCP related module
	 *PDEF_SCP_SRAM_PDN = #0xffffff
	 *PDEF_SCP_CLK_SEL = #0x1
	 *PDEF_SCP_CLK_EN = #0x0
	 *PDEF_SCP_CFGREG_SW_RSTN = #0x0
	*/
	DRV_WriteReg32(SCP_CFGREG_SW_RSTN, 0x0);
	DRV_WriteReg32(SCP_SRAM_PDN, 0xFFFFFFFF); /*turn off scp sram*/
	DRV_WriteReg32(SCP_CLK_SEL, 0x1);    /*turn off scp clock*/
	DRV_WriteReg32(SCP_CLK_EN, 0x0);
	DRV_WriteReg32(CLK_CTRL_L1_SRAM_PD, 0xFFFFFFFF);
	DRV_WriteReg32(CLK_CTRL_TCM_TAIL_SRAM_PD, 0xFFFFFFFF);

	dprintf(CRITICAL, "DISABLE SCP\n");
}
