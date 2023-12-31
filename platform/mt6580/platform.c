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

#include <debug.h>
#include <stdlib.h>
#include <string.h>
#include <video.h>
#include <dev/uart.h>
#include <arch/arm.h>
#include <arch/arm/mmu.h>
#include <arch/ops.h>
#include <target/board.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_disp_drv.h>
#include <platform/disp_drv.h>
#include <platform/boot_mode.h>
#include <platform/mt_logo.h>
#include <platform/partition.h>
#include <env.h>
#include <platform/mt_gpio.h>
#include <platform/mt_pmic.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/mt_i2c.h>
#include <platform/mtk_key.h>
#include <platform/mt_rtc.h>
#include <platform/mt_leds.h>
#include <platform/upmu_common.h>
#include <platform/mtk_wdt.h>
#include <platform/boot_mode.h>
#include <platform/disp_drv_platform.h>
#include <plinfo.h>                 // for plinfo_get_brom_header_block_size()
#include <platform/l2c.h>
#include <platform/verified_boot.h>
#include <load_vfy_boot.h>
#include <pal_log.h>
#include <fdt_op.h>

#ifdef MTK_AB_OTA_UPDATER
#include "bootctrl.h"
#endif

#if defined(MTK_SECURITY_SW_SUPPORT)
#include "oemkey.h"
#endif

#ifdef MTK_SECURITY_SW_SUPPORT
extern u8 g_oemkey[OEM_PUBK_SZ];
#endif

#ifdef LK_DL_CHECK
/*block if check dl fail*/
#undef LK_DL_CHECK_BLOCK_LEVEL
#endif
//#define MT_SRAM_REPAIR_SUPPORT

extern void platform_early_init_timer();
extern void jump_da(u32 addr, u32 arg1, u32 arg2);
extern int i2c_hw_init(void);
extern int mboot_common_load_logo(unsigned long logo_addr, char *filename);
extern int sec_func_init(u64 pl_start_addr);
extern int sec_usbdl_enabled(void);
extern int sec_usbdl_verify_da(unsigned char *, unsigned int, unsigned char *,
			       unsigned int);
extern void mtk_wdt_disable(void);
extern void platform_deinit_interrupts(void);
extern int mmc_get_dl_info(void);
extern int mmc_legacy_init(int);
#ifdef MT_SRAM_REPAIR_SUPPORT
extern int repair_sram(void);
#endif
extern bool g_boot_menu;

#ifdef MTK_BATLOWV_NO_PANEL_ON_EARLY
extern kal_bool is_low_battery(kal_int32 val);
extern int hw_charging_get_charger_type(void);
#endif

void platform_uninit(void);
void config_shared_SRAM_size(void);
extern int dev_info_nr_cpu(void);

BOOT_ARGUMENT *g_boot_arg;
BOOT_ARGUMENT boot_addr;
int g_nr_bank;
BI_DRAM bi_dram[MAX_NR_BANK];
unsigned int g_fb_base;
unsigned int g_fb_size;

static int g_dram_init_ret;

enum {
	MD_SYS1 = 0,
	MD_SYS2,
	MD_SYS3,
	MD_SYS4,
};

void dump_boot_arg(void)
{
	int i, j;
	pal_log_err("==dump boot argument==\n");
	pal_log_err("BOOT_REASON: %d\n", g_boot_arg->boot_reason);
	pal_log_err("BOOT_MODE: %d\n", g_boot_arg->boot_mode);
	pal_log_err("META_COM TYPE: %d\n", g_boot_arg->meta_com_type);
	pal_log_err("META_COM ID: %d\n", g_boot_arg->meta_com_id);
	pal_log_err("META_COM PORT: %d\n", g_boot_arg->meta_uart_port);
	pal_log_err("LOG_COM PORT: %d\n", g_boot_arg->log_port);
	pal_log_err("LOG_COM BAUD: %d\n", g_boot_arg->log_baudrate);
	pal_log_err("LOG_COM EN: %d\n", g_boot_arg->log_enable);
	pal_log_err("MEM_NUM: %d\n", g_boot_arg->dram_rank_num);
	if (g_boot_arg->dram_rank_num > 4) {
		pal_log_err("MEM_NUM:%d, it's above the expectation. fix it\n",
			    g_boot_arg->dram_rank_num);
		g_boot_arg->dram_rank_num = 4;
	}
	for (i = 0; i < g_boot_arg->dram_rank_num; i++)
		pal_log_err("MEM_SIZE: 0x%x\n", g_boot_arg->dram_rank_size[i]);

	pal_log_err("mblock num: 0x%x\n", g_boot_arg->mblock_info.mblock_num);
	if (g_boot_arg->mblock_info.mblock_num > 4) {
		pal_log_err("mblock_info.mblock_num:%d, it's above the expectation. fix it\n",
			    g_boot_arg->dram_rank_num);
		g_boot_arg->mblock_info.mblock_num = 4;
	}
	for (i = 0; i < 4; i++) {
		pal_log_err("mblock start: 0x%llx\n", g_boot_arg->mblock_info.mblock[i].start);
		pal_log_err("mblock size: 0x%llx\n", g_boot_arg->mblock_info.mblock[i].size);
		pal_log_err("mblock rank: 0x%x\n", g_boot_arg->mblock_info.mblock[i].rank);
	}

	pal_log_err("orig_dram num: 0x%x\n", g_boot_arg->orig_dram_info.rank_num);
	for (i = 0; i < 4; i++) {
		pal_log_err("orig_dram start: 0x%llx\n",
			    g_boot_arg->orig_dram_info.rank_info[i].start);
		pal_log_err("orig_dram size: 0x%llx\n",
			    g_boot_arg->orig_dram_info.rank_info[i].size);
	}

	pal_log_err("lca start: 0x%llx\n", g_boot_arg->lca_reserved_mem.start);
	pal_log_err("lca size: 0x%llx\n", g_boot_arg->lca_reserved_mem.size);
	pal_log_err("tee start: 0x%llx\n", g_boot_arg->tee_reserved_mem.start);
	pal_log_err("tee size: 0x%llx\n", g_boot_arg->tee_reserved_mem.size);
	for (i = 0; i < 4; i++)
		pal_log_err("MD_INFO: 0x%x\n", g_boot_arg->md_type[i]);
	pal_log_err("BOOT_TIME: %d\n", g_boot_arg->boot_time);
	pal_log_err("DA_INFO: 0x%x\n", g_boot_arg->da_info.addr);
	pal_log_err("DA_INFO: 0x%x\n", g_boot_arg->da_info.arg1);
	pal_log_err("DA_INFO: 0x%x\n", g_boot_arg->da_info.arg2);
	pal_log_err("DA_INFO: 0x%x\n", g_boot_arg->da_info.len);
	pal_log_err("DA_INFO: 0x%x\n", g_boot_arg->da_info.sig_len);
	pal_log_err("SEC_INFO: 0x%x\n", g_boot_arg->sec_limit.magic_num);
	pal_log_err("SEC_INFO: 0x%x\n", g_boot_arg->sec_limit.forbid_mode);
	pal_log_err("PART_NUM: %d\n", g_boot_arg->part_num);
	pal_log_err("PART_INFO: 0x%x\n", g_boot_arg->part_info);
	pal_log_err("EFLAG: %d\n", g_boot_arg->e_flag);
	pal_log_err("DDR_RESERVE: %d\n", g_boot_arg->ddr_reserve_enable);
	pal_log_err("DDR_RESERVE: %d\n", g_boot_arg->ddr_reserve_success);
	pal_log_err("DRAM_BUF: %d\n", g_boot_arg->dram_buf_size);
	pal_log_err("SMC: 0x%x\n", g_boot_arg->smc_boot_opt);
	pal_log_err("SMC: 0x%x\n", g_boot_arg->lk_boot_opt);
	pal_log_err("SMC: 0x%x\n", g_boot_arg->kernel_boot_opt);
	pal_log_err("SRAM satrt: 0x%x\n", g_boot_arg->non_secure_sram_addr);
	pal_log_err("SRAM size: 0x%x\n", g_boot_arg->non_secure_sram_size);
	pal_log_err("==dump boot argument==\n");
}

void check_tag_size(int pl_tag_size, int lk_tag_size, int magic_number)
{
	if (pl_tag_size != lk_tag_size) {
		pal_log_err("tag size not match, magic number%d,PL tag size:%d, LK tag size:%d\n",
			    magic_number, pl_tag_size, lk_tag_size);
		pal_log_err("Please sync the tag structure with the preloader.\n");
		while (1);
	}
}

int dram_init(void)
{
	int i;
	struct boot_tag *tags;

	/* Get parameters from pre-loader. Get as early as possible
	 * The address of BOOT_ARGUMENT_LOCATION will be used by Linux later
	 * So copy the parameters from BOOT_ARGUMENT_LOCATION to LK's memory region
	 */
	g_boot_arg = &boot_addr;

	if (*(unsigned int *)BOOT_ARGUMENT_LOCATION == BOOT_ARGUMENT_MAGIC)
		memcpy(g_boot_arg, (void *)BOOT_ARGUMENT_LOCATION, sizeof(BOOT_ARGUMENT));

	else {
		//
		g_boot_arg->maggic_number = BOOT_ARGUMENT_MAGIC;
		for (tags = (void *)BOOT_ARGUMENT_LOCATION; tags->hdr.size;
		     tags = boot_tag_next(tags)) {
			switch (tags->hdr.tag) {
			case BOOT_TAG_BOOT_REASON:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_boot_reason),
					       tags->hdr.tag);
				g_boot_arg->boot_reason = tags->u.boot_reason.boot_reason;
				break;
			case BOOT_TAG_BOOT_MODE:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_boot_mode),
					       tags->hdr.tag);
				g_boot_arg->boot_mode = tags->u.boot_mode.boot_mode;
				break;
			case BOOT_TAG_META_COM:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_meta_com), tags->hdr.tag);
				g_boot_arg->meta_com_type = tags->u.meta_com.meta_com_type;
				g_boot_arg->meta_com_id = tags->u.meta_com.meta_com_id;
				g_boot_arg->meta_uart_port = tags->u.meta_com.meta_uart_port;
				break;
			case BOOT_TAG_LOG_COM:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_log_com), tags->hdr.tag);
				g_boot_arg->log_port = tags->u.log_com.log_port;
				g_boot_arg->log_baudrate = tags->u.log_com.log_baudrate;
				g_boot_arg->log_enable = tags->u.log_com.log_enable;
				break;
			case BOOT_TAG_MEM:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_mem), tags->hdr.tag);
				g_boot_arg->dram_rank_num = tags->u.mem.dram_rank_num;
				for (i = 0; i < tags->u.mem.dram_rank_num; i++)
					g_boot_arg->dram_rank_size[i] = tags->u.mem.dram_rank_size[i];
				g_boot_arg->mblock_info = tags->u.mem.mblock_info;
				g_boot_arg->orig_dram_info = tags->u.mem.orig_dram_info;
				g_boot_arg->lca_reserved_mem = tags->u.mem.lca_reserved_mem;
				g_boot_arg->tee_reserved_mem = tags->u.mem.tee_reserved_mem;
				break;
			case BOOT_TAG_MD_INFO:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_md_info), tags->hdr.tag);
				for (i = 0; i < 4; i++)
					g_boot_arg->md_type[i] = tags->u.md_info.md_type[i];
				break;
			case BOOT_TAG_BOOT_TIME:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_boot_time),
					       tags->hdr.tag);
				g_boot_arg->boot_time = tags->u.boot_time.boot_time;
				break;
			case BOOT_TAG_DA_INFO:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_da_info), tags->hdr.tag);
				memcpy(&g_boot_arg->da_info, &tags->u.da_info.da_info, sizeof(da_info_t));
				break;
			case BOOT_TAG_SEC_INFO:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_sec_info), tags->hdr.tag);
				memcpy(&g_boot_arg->sec_limit, &tags->u.sec_info.sec_limit, sizeof(SEC_LIMIT));
				break;
			case BOOT_TAG_PART_NUM:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_part_num), tags->hdr.tag);
				g_boot_arg->part_num = tags->u.part_num.part_num;
				break;
			case BOOT_TAG_PART_INFO:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_part_info),
					       tags->hdr.tag);
				g_boot_arg->part_info =
					tags->u.part_info.part_info;  /* only copy the pointer but the contains*/
				break;
			case BOOT_TAG_EFLAG:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_eflag), tags->hdr.tag);
				g_boot_arg->e_flag = tags->u.eflag.e_flag;
				break;
			case BOOT_TAG_DDR_RESERVE:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_ddr_reserve),
					       tags->hdr.tag);
				g_boot_arg->ddr_reserve_enable = tags->u.ddr_reserve.ddr_reserve_enable;
				g_boot_arg->ddr_reserve_success = tags->u.ddr_reserve.ddr_reserve_success;
				g_boot_arg->ddr_reserve_ready = tags->u.ddr_reserve.ddr_reserve_ready;
				break;
			case BOOT_TAG_DRAM_BUF:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_dram_buf), tags->hdr.tag);
				g_boot_arg->dram_buf_size = tags->u.dram_buf.dram_buf_size;
				break;
			case BOOT_TAG_BOOT_OPT:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_boot_opt), tags->hdr.tag);
				g_boot_arg->smc_boot_opt = tags->u.boot_opt.smc_boot_opt;
				g_boot_arg->lk_boot_opt = tags->u.boot_opt.lk_boot_opt;
				g_boot_arg->kernel_boot_opt = tags->u.boot_opt.kernel_boot_opt;
				break;
			case BOOT_TAG_SRAM_INFO:
				check_tag_size(tags->hdr.size, boot_tag_size(boot_tag_sram_info),
					       tags->hdr.tag);
				g_boot_arg->non_secure_sram_addr = tags->u.sram_info.non_secure_sram_addr;
				g_boot_arg->non_secure_sram_size = tags->u.sram_info.non_secure_sram_size;
				break;
			case BOOT_TAG_PL_VERSION:
				memcpy(&g_boot_arg->pl_version, &tags->u.pl_version.pl_version,
				       sizeof(tags->u.pl_version.pl_version));
				break;
			case BOOT_TAG_RAM_CONSOLE_INFO:
				g_boot_arg->ram_console_sram_addr = tags->u.ram_console_info.sram_addr;
				g_boot_arg->ram_console_sram_size = tags->u.ram_console_info.sram_size;
				g_boot_arg->ram_console_def_type = tags->u.ram_console_info.def_type;
				g_boot_arg->ram_console_memory_info_offset = tags->u.ram_console_info.memory_info_offset;
				break;
			default:
				break;
			}
		}
		//
	}

#ifdef MACH_FPGA
	g_nr_bank = 2;
	bi_dram[0].start = DRAM_PHY_ADDR + RIL_SIZE;
	bi_dram[0].size = (256 * 1024 * 1024) - RIL_SIZE;
	bi_dram[1].start = bi_dram[0].start + bi_dram[0].size;
	bi_dram[1].size = (256 * 1024 * 1024);
#else
	g_nr_bank = g_boot_arg->dram_rank_num;

	if (g_nr_bank == 0 || g_nr_bank > MAX_NR_BANK) {
		g_dram_init_ret = -1;
		//pal_log_err( "[LK ERROR] DRAM bank number is not correct!!!");
		//while (1) ;
		return -1;
	}

#ifndef CUSTOM_CONFIG_MAX_DRAM_SIZE
	/* return the actual DRAM info */
	bi_dram[0].start = DRAM_PHY_ADDR + RIL_SIZE;
	bi_dram[0].size = g_boot_arg->dram_rank_size[0] - RIL_SIZE;
	for (i = 1; i < g_nr_bank; i++) {
		bi_dram[i].start = bi_dram[i - 1].start + bi_dram[i - 1].size;
		bi_dram[i].size = g_boot_arg->dram_rank_size[i];
	}
//#elif (CUSTOM_CONFIG_MAX_DRAM_SIZE < 0x10000000)
//#error "DRAM size < 0x10000000" /* DRAM is less than 256MB, trigger build error */
#else
#endif

#endif

	return 0;
}

/*******************************************************
 * Routine: memory_size
 * Description: return DRAM size to LCM driver
 ******************************************************/
u64 physical_memory_size(void)
{
	int i;
	unsigned long long size = 0;

	for (i = 0; i < g_boot_arg->orig_dram_info.rank_num; i++)
		size += g_boot_arg->orig_dram_info.rank_info[i].size;

	return size;
}

u32 memory_size(void)
{
	unsigned long long size = physical_memory_size();

	while (((unsigned long long)DRAM_PHY_ADDR + size) > 0x100000000ULL)
		size -= (unsigned long long)(1024 * 1024 * 1024);

	return (unsigned int)size;
}

void sw_env()
{
#ifdef LK_DL_CHECK
#ifdef MTK_EMMC_SUPPORT
	int dl_status = 0;
	dl_status = mmc_get_dl_info();
	pal_log_info("mt65xx_sw_env--dl_status: %d\n", dl_status);
	if (dl_status != 0) {
		video_printf("=> TOOL DL image Fail!\n");
		pal_log_err("TOOL DL image Fail\n");
#ifdef LK_DL_CHECK_BLOCK_LEVEL
		pal_log_err("uboot is blocking by dl info\n");
		while (1) ;
#endif
	}
#endif
#endif

#ifndef USER_BUILD
	switch (g_boot_mode) {
	case META_BOOT:
		video_printf(" => META MODE\n");
		break;
	case FACTORY_BOOT:
		video_printf(" => FACTORY MODE\n");
		break;
	case RECOVERY_BOOT:
		video_printf(" => RECOVERY MODE\n");
		break;
	case SW_REBOOT:
		//video_printf(" => SW RESET\n");
		break;
	case NORMAL_BOOT:
		//if(g_boot_arg->boot_reason != BR_RTC && get_env("hibboot") != NULL && atoi(get_env("hibboot")) == 1)
		if (!g_boot_menu && get_env("hibboot") != NULL && atoi(get_env("hibboot")) == 1)
			video_printf(" => HIBERNATION BOOT\n");
		else
			video_printf(" => NORMAL BOOT\n");
		break;
	case ADVMETA_BOOT:
		video_printf(" => ADVANCED META MODE\n");
		break;
	case ATE_FACTORY_BOOT:
		video_printf(" => ATE FACTORY MODE\n");
		break;
#ifdef MTK_KERNEL_POWER_OFF_CHARGING
	case KERNEL_POWER_OFF_CHARGING_BOOT:
		video_printf(" => POWER OFF CHARGING MODE\n");
		break;
	case LOW_POWER_OFF_CHARGING_BOOT:
		video_printf(" => LOW POWER OFF CHARGING MODE\n");
		break;
#endif
	case ALARM_BOOT:
		video_printf(" => ALARM BOOT\n");
		break;
	case FASTBOOT:
		video_printf(" => FASTBOOT mode...\n");
		break;
	default:
		video_printf(" => UNKNOWN BOOT\n");
	}
	return;
#endif

#ifdef USER_BUILD
	if (g_boot_mode == FASTBOOT)
		video_printf(" => FASTBOOT mode...\n");
	return;
#endif
}

void platform_init_mmu_mappings(void)
{
	unsigned int addr;
	unsigned int dram_size = 0;

	dram_init();
	arm_mmu_init();
	dram_size = physical_memory_size();

	/* map dram region */
	for (addr = 0; addr < dram_size; addr += (1024 * 1024)) {
		/*virtual to physical 1-1 mapping*/
		arm_mmu_map_section(bi_dram[0].start + addr, bi_dram[0].start + addr,
				    MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | MMU_MEMORY_AP_READ_WRITE);
	}

	/* ummap TEE memory regoin */
	if (g_boot_arg->tee_reserved_mem.size != 0) {
		u64 j, k;
		k = g_boot_arg->tee_reserved_mem.start;
		j = ROUNDUP(g_boot_arg->tee_reserved_mem.size, 1024 * 1024);
		for (; j > 0; j -= (1024 * 1024)) {
			arm_mmu_map_section((uintptr_t)k, (uintptr_t)k,
					    MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | MMU_MEMORY_AP_READ_WRITE |
					    MMU_MEMORY_XN);
			k += (1024 * 1024);
		}
	}
	arch_enable_mmu();  //enable mmu after setup page table to avoid cpu prefetch which may bring on emi violation
}

/******************************************************************************
* VB: verified boot
******************************************************************************/
static void lk_vb_init(void)
{
#ifdef MTK_SECURITY_SW_SUPPORT
	u64 pl_start_addr = 0;
	plinfo_get_brom_header_block_size(&pl_start_addr);
#ifdef LK_PROFILING
	unsigned int time_vb_init = get_timer(0);
#endif  // LK_PROFILING

	/* initialize security library */
	sec_func_init(pl_start_addr);
	seclib_set_oemkey(g_oemkey, OEM_PUBK_SZ);

#ifdef LK_PROFILING
	pal_log_err("[PROFILE] vb init takes %d ms\n", (int)get_timer(time_vb_init));
#endif  // LK_PROFILING

#endif  // MTK_SECURITY_SW_SUPPORT
}


/******************************************************************************
* VB: verified boot
******************************************************************************/
static void lk_vb_flow(void)
{
#ifdef MTK_SECURITY_SW_SUPPORT
#ifdef LK_PROFILING
	unsigned int time_vb_flow = get_timer(0);
#endif  // LK_PROFILING
	if (0 != img_auth_stor(SBOOT_PART_LOGO_NAME, NULL)) {
		pal_log_err("<ASSERT> %s:line %d\n", __FILE__, __LINE__);
		while (1);
	}

	if (DTBO_FROM_STANDALONE == get_dtbo_src()) {
		if (0 != img_auth_stor(get_dtbo_part_name(), NULL)) {
			pal_log_err("<ASSERT> %s:line %d\n", __FILE__, __LINE__);
			while (1);
		}
	}
#ifdef LK_PROFILING
	pal_log_err("[PROFILE] vb flow takes %d ms\n",
		    (int)get_timer(time_vb_flow));
#endif  // LK_PROFILING
#endif  // MTK_SECURITY_SW_SUPPORT
}


/******************************************************************************
* DA: Download Agent
******************************************************************************/
static void lk_verify_da(void)
{
#ifdef MTK_SECURITY_SW_SUPPORT
	/* verify da before jumping to da*/
	if (sec_usbdl_enabled()) {
		u8	*da_addr = (u8 *)g_boot_arg->da_info.addr;
		u32 da_len	 = g_boot_arg->da_info.len;
		u32 sig_len  = g_boot_arg->da_info.sig_len;
		u8	*sig_addr = (unsigned char *)da_addr + (da_len - sig_len);

		if (da_len == 0 || sig_len == 0) {
			pal_log_info("[LK] da argument is invalid\n");
			pal_log_info("da_addr = 0x%x\n", (int)da_addr);
			pal_log_info("da_len  = 0x%x\n", da_len);
			pal_log_info("sig_len = 0x%x\n", sig_len);
		}

		if (sec_usbdl_verify_da(da_addr, (da_len - sig_len), sig_addr, sig_len)) {
			/* da verify fail */
			video_printf(" => Not authenticated tool, download stop...\n");
			while (1); /* fix me, should not be infinite loop in lk */
		}
	} else
#endif  // MTK_SECURITY_SW_SUPPORT
	{
		pal_log_info(" DA verification disabled...\n");
	}
}

void platform_init_mmu(void)
{
	unsigned long long addr;
	unsigned int vaddr;
	unsigned long long dram_size;

	/* configure available RAM banks */
	dram_init();

	dram_size = physical_memory_size();

	if (((unsigned long long)DRAM_PHY_ADDR + dram_size) <= 0x100000000ULL) {
		arm_mmu_init();
		/* map dram region */
		for (addr = 0; addr < dram_size; addr += (1024 * 1024)) {
			/*virtual to physical 1-1 mapping*/
			arm_mmu_map_section(bi_dram[0].start + addr, bi_dram[0].start + addr,
					    MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | MMU_MEMORY_AP_READ_WRITE);
		}

		/* ummap TEE memory regoin */
		if (g_boot_arg->tee_reserved_mem.size != 0) {
			u64 j, k;
			k = g_boot_arg->tee_reserved_mem.start;
			j = ROUNDUP(g_boot_arg->tee_reserved_mem.size, 1024 * 1024);
			for (; j > 0; j -= (1024 * 1024)) {
				arm_mmu_map_section((uintptr_t)k, (uintptr_t)k,
						    MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | MMU_MEMORY_AP_READ_WRITE |
						    MMU_MEMORY_XN);
				k += (1024 * 1024);
			}
		}
	} else {
		arm_mmu_lpae_init();
		/* map dram region */
		for (addr = 0; addr < dram_size;
		     addr += (unsigned long long)(1024 * 1024 * 1024)) {
			vaddr = (bi_dram[0].start + addr < 0x100000000ULL) ? (unsigned int)(
					bi_dram[0].start + addr) : (0xC0000000);
			arm_mmu_map_block(bi_dram[0].start + addr, vaddr,
					  LPAE_MMU_MEMORY_TYPE_NORMAL_WRITE_BACK);
		}
		/* ummap TEE memory regoin */
		if (g_boot_arg->tee_reserved_mem.size != 0) {
			u64 j, k;
			k = g_boot_arg->tee_reserved_mem.start;
			j = ROUNDUP(g_boot_arg->tee_reserved_mem.size, 0x40000000ULL);
			for (; j > 0; j -= 0x40000000ULL) {
				arm_mmu_map_block((uintptr_t)k, (uintptr_t)k,
						  LPAE_MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | LPAE_MMU_MEMORY_XN);
				k += 0x40000000ULL;
			}
		}
	}
	arch_enable_mmu();  //enable mmu after setup page table to avoid cpu prefetch which may bring on emi violation
}

void platform_k64_check(void)
{
	pal_log_err("kernel_boot_opt=%d\n", g_boot_arg->kernel_boot_opt);

	switch (g_boot_arg->kernel_boot_opt) {
	case BOOT_OPT_64S3:
	case BOOT_OPT_64S1:
	case BOOT_OPT_64N2:
	case BOOT_OPT_64N1:
		g_is_64bit_kernel = 1;
		pal_log_err("64Bit Kernel\n");
		break;

	case BOOT_OPT_32S3:
	case BOOT_OPT_32S1:
	case BOOT_OPT_32N2:
	case BOOT_OPT_32N1:
	/* maybe need to do something in the feature*/
	default:
		g_is_64bit_kernel = 0;
		pal_log_err("32Bit Kernel\n");
		break;
	}
}


void platform_early_init(void)
{
#ifdef MT_SRAM_REPAIR_SUPPORT
	int repair_ret;
#endif
#ifdef LK_PROFILING
#ifdef MT_SRAM_REPAIR_SUPPORT
	unsigned int time_repair_sram;
#endif
	unsigned int time_wdt_early_init;
	unsigned int time_led_init;
	unsigned int time_pmic_init;
	unsigned int time_platform_early_init;

	time_platform_early_init = get_timer(0);
#endif
	platform_init_interrupts();

	platform_early_init_timer();

#ifndef MACH_FPGA
	mt_gpio_set_default();
#endif

	/* initialize the uart */
	uart_init_early();

	platform_k64_check();

	if (g_dram_init_ret < 0) {
		pal_log_err("[LK ERROR] DRAM bank number is not correct!!!\n");
		while (1) ;
	}

	//i2c_v1_init();

#ifdef LK_PROFILING
	time_wdt_early_init = get_timer(0);
#endif
	mtk_wdt_init();
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- WDT Init  takes %d ms -------- \n",
		     (int)get_timer(time_wdt_early_init));
#endif

#ifdef MT_SRAM_REPAIR_SUPPORT
#ifdef LK_PROFILING
	time_repair_sram = get_timer(0);
#endif
	repair_ret = repair_sram();
	if (repair_ret != 0) {
		pal_log_err("Sram repair failed %d\n", repair_ret);
		while (1);
	}
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- Repair SRAM takes %d ms -------- \n",
		     (int)get_timer(time_repair_sram));
#endif
#endif

	//i2c init
	i2c_hw_init();

#ifdef MACH_FPGA
	mtk_timer_init();  // GPT4 will be initialized at PL after
	mtk_wdt_disable();  // WDT will be triggered when uncompressing linux image on FPGA
#endif



#ifndef MACH_FPGA
#ifdef LK_PROFILING
	time_led_init = get_timer(0);
#endif
	leds_init();
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- led init takes %d ms -------- \n",
		     (int)get_timer(time_led_init));
#endif
#endif
	// Workaround by Peng
	//pwrap_init_lk();
	//pwrap_init_for_early_porting();

#ifdef LK_PROFILING
	time_pmic_init = get_timer(0);
#endif
	pmic_init();
	/*
	    // Workaround by Weiqi
	    mt6331_upmu_set_rg_vgp1_en(1);
	    mt6331_upmu_set_rg_vcam_io_en(1);
	*/
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- pmic_init takes %d ms -------- \n",
		     (int)get_timer(time_pmic_init));
#endif

#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- platform_early_init takes %d ms -------- \n",
		     (int)get_timer(time_platform_early_init));
#endif
}

extern void mt65xx_bat_init(void);
#if defined (MTK_KERNEL_POWER_OFF_CHARGING)

int kernel_charging_boot(void)
{
	if ((g_boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT ||
	     g_boot_mode == LOW_POWER_OFF_CHARGING_BOOT) && upmu_is_chr_det() == KAL_TRUE) {
		pal_log_info("[%s] Kernel Power Off Charging with Charger/Usb \n", __func__);
		return  1;
	} else if ((g_boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT ||
		    g_boot_mode == LOW_POWER_OFF_CHARGING_BOOT) && upmu_is_chr_det() == KAL_FALSE) {
		pal_log_info("[%s] Kernel Power Off Charging without Charger/Usb \n", __func__);
		return -1;
	} else
		return 0;
}
#endif

void platform_init(void)
{
#ifdef MTK_SECURITY_SW_SUPPORT
	unsigned int time_security_init;
	u64 pl_start_addr = 0;
#endif
#ifdef LK_PROFILING
	unsigned int time_nand_emmc;
	unsigned int time_env;
	unsigned int time_disp_init;
	unsigned int time_load_logo;
	unsigned int time_backlight;
	unsigned int time_boot_mode;
	unsigned int time_bat_init;
	unsigned int time_RTC_boot_Check;
	unsigned int time_show_logo;
	unsigned int time_sw_env;
	unsigned int time_platform_init;

	time_platform_init = get_timer(0);
#endif

	pal_log_err(" ==LK info ==\n");
	pal_log_err(" Build time:%s, %s\n",  __DATE__, __TIME__);
	pal_log_err(" chip_code[0x%x]\n",  mt_get_chip_hw_code());
	pal_log_err(" chip_ver[0x%x]\n",   mt_get_chip_sw_ver());
	pal_log_err(" ==LK info ==\n");
	dump_boot_arg();

	pal_log_err("platform_init()\n");

#ifdef DUMMY_AP
	dummy_ap_entry();
#endif

#ifdef LK_PROFILING
	time_nand_emmc = get_timer(0);
#endif
#ifdef MTK_EMMC_SUPPORT
	mmc_legacy_init(1);
#else
	nand_init();
	nand_driver_test();
#endif
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- NAND/EMMC init takes %d ms -------- \n",
		     (int)get_timer(time_nand_emmc));
#endif

#ifdef MTK_AB_OTA_UPDATER
	/* get A/B system parameter */
	get_AB_OTA_param();
#endif

	/* The device tree should be loaded as early as possible. */
	load_device_tree();

#ifdef MTK_KERNEL_POWER_OFF_CHARGING
	if ((g_boot_arg->boot_reason == BR_USB) && (upmu_is_chr_det() == KAL_FALSE)) {
		pal_log_info("[%s] Unplugged Charger/Usb between Pre-loader and Uboot in Kernel Charging Mode, Power Off \n",
			     __func__);
		mt6575_power_off();
	}
#endif

#ifdef LK_PROFILING
	time_env = get_timer(0);
#endif
	env_init();
	print_env();
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- ENV init takes %d ms -------- \n",
		     (int)get_timer(time_env));
#endif

#ifdef LK_PROFILING
	time_disp_init = get_timer(0);
#endif

	/* initialize the frame buffet information */
#ifndef MACH_FPGA_NO_DISPLAY
	g_fb_size = mt_disp_get_vram_size();
#else
	g_fb_size = 0x1000000;
#endif
#if 0
	g_fb_base = memory_size() - g_fb_size + DRAM_PHY_ADDR;
#else

#if 0
	if (g_is_64bit_kernel) {
		g_fb_base = mblock_reserve(&g_boot_arg->mblock_info, g_fb_size, 0x200000,
					   0x100000000, RANKMAX);
		g_fb_base = ALIGN_TO(g_fb_base, 0x200000); // size 2MB align
	} else
		g_fb_base = mblock_reserve(&g_boot_arg->mblock_info, g_fb_size, 0x100000,
					   0x100000000, RANKMAX);
#else
	g_fb_base = mblock_reserve(&g_boot_arg->mblock_info, g_fb_size, 0x10000,
				   0x100000000, RANKMAX);
#endif

	if (!g_fb_base) {
		/* ERROR */
	}
#endif

	pal_log_err("FB base = 0x%x, FB size = %d\n", g_fb_base, g_fb_size);

#ifndef MACH_FPGA_NO_DISPLAY
	mt_disp_init((void *)g_fb_base);
	/* show black picture fisrtly in case of  backlight is on before nothing is drawed*/
	mt_disp_fill_rect(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT, 0x0);
	mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- disp init takes %d ms -------- \n",
		     (int)get_timer(time_disp_init));
#endif
	drv_video_init();

#endif
	/*for kpd pmic mode setting*/
	set_kpd_pmic_mode();

#ifndef MACH_FPGA
#ifdef LK_PROFILING
	time_boot_mode = get_timer(0);
#endif
	boot_mode_select();
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- boot mode select takes %d ms -------- \n",
		     (int)get_timer(time_boot_mode));
#endif
#endif

#ifdef CFG_DTB_EARLY_LOADER_SUPPORT
	/* reload dtb when boot mode = recovery */
	if ((g_boot_mode == RECOVERY_BOOT) && (get_recovery_dtbo_loaded() != 1)){
		if (bldr_load_dtb("recovery") < 0)
			dprintf(CRITICAL, "bldr_load_dtb fail\n");
	}
#endif  // CFG_DTB_EARLY_LOADER_SUPPORT

#ifndef MACH_FPGA_NO_DISPLAY
#ifdef LK_PROFILING
	time_load_logo = get_timer(0);
#endif
	mboot_common_load_logo((unsigned long)mt_get_logo_db_addr_pa(), "logo");
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- load_logo takes %d ms -------- \n",
		     (int)get_timer(time_load_logo));
#endif
#endif

	lk_vb_init();
	lk_vb_flow();
	/*Show download logo & message on screen */
	if (g_boot_arg->boot_mode == DOWNLOAD_BOOT) {
		pal_log_err("[LK] boot mode is DOWNLOAD_BOOT\n");
		lk_verify_da();

#ifndef MACH_FPGA_NO_DISPLAY
		mt_disp_show_boot_logo();
#endif
		video_printf(" => Downloading...\n");
		pal_log_err("enable backlight after show bootlogo!\n");
		mt65xx_backlight_on();

		mtk_wdt_disable(); //Disable wdt before jump to DA
		platform_uninit();
#ifdef HAVE_CACHE_PL310
		l2_disable();
#endif
		arch_disable_cache(UCACHE);
		arch_disable_mmu();
#ifdef ENABLE_L2_SHARING
		config_shared_SRAM_size();
#endif
		jump_da(g_boot_arg->da_info.addr, g_boot_arg->da_info.arg1,
			g_boot_arg->da_info.arg2);
	}

#ifdef LK_PROFILING
	time_bat_init = get_timer(0);
#endif
	mt65xx_bat_init();
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- battery init takes %d ms -------- \n",
		     (int)get_timer(time_bat_init));
#endif

#ifndef CFG_POWER_CHARGING
#ifdef LK_PROFILING
	time_RTC_boot_Check = get_timer(0);
#endif
	/* NOTE: if define CFG_POWER_CHARGING, will rtc_boot_check() in mt65xx_bat_init() */
	rtc_boot_check(false);
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- RTC boot check Init  takes %d ms -------- \n",
		     (int)get_timer(time_RTC_boot_Check));
#endif
#endif

#ifdef LK_PROFILING
	time_show_logo = get_timer(0);
#endif
#ifdef MTK_KERNEL_POWER_OFF_CHARGING
	if (kernel_charging_boot() == 1) {
#ifdef MTK_BATLOWV_NO_PANEL_ON_EARLY
		CHARGER_TYPE CHR_Type_num = CHARGER_UNKNOWN;
		CHR_Type_num = hw_charging_get_charger_type();
		if ((g_boot_mode != LOW_POWER_OFF_CHARGING_BOOT) ||
		    ((CHR_Type_num != STANDARD_HOST) && (CHR_Type_num != NONSTANDARD_CHARGER))) {
#endif
			mt_disp_power(TRUE);
			mt_disp_show_low_battery();
			mt65xx_leds_brightness_set(6, 110);
#ifdef MTK_BATLOWV_NO_PANEL_ON_EARLY
		}
#endif
	} else if (g_boot_mode != KERNEL_POWER_OFF_CHARGING_BOOT &&
		   g_boot_mode != LOW_POWER_OFF_CHARGING_BOOT) {
		if (g_boot_mode != ALARM_BOOT && (g_boot_mode != FASTBOOT)) {
#ifndef MACH_FPGA_NO_DISPLAY
			mt_disp_show_boot_logo();
#endif
		}
	}
#else
	if (g_boot_mode != ALARM_BOOT && (g_boot_mode != FASTBOOT)) {
#ifndef MACH_FPGA_NO_DISPLAY
		mt_disp_show_boot_logo();
#endif
	}
#endif
#ifdef LK_PROFILING
	time_backlight = get_timer(0);
#endif

#ifdef MTK_BATLOWV_NO_PANEL_ON_EARLY
	if (!is_low_battery(0)) {
#endif
		mt65xx_backlight_on();
#ifndef MACH_FPGA_NO_DISPLAY
		//pwm need display sof
		mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
#endif
#ifdef MTK_BATLOWV_NO_PANEL_ON_EARLY
	}
#endif

#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- backlight takes %d ms -------- \n",
		     (int)get_timer(time_backlight));
#endif

#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- show logo takes %d ms -------- \n",
		     (int)get_timer(time_show_logo));
#endif

#ifndef MACH_FPGA
#ifdef LK_PROFILING
	time_sw_env = get_timer(0);
#endif
	sw_env();
#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- sw_env takes %d ms -------- \n",
		     (int)get_timer(time_sw_env));
#endif
#endif

#ifdef LK_PROFILING
	pal_log_info("[PROFILE] ------- platform_init takes %d ms -------- \n",
		     (int)get_timer(time_platform_init));
#endif
}

void platform_uninit(void)
{
#ifndef MACH_FPGA
	leds_deinit();
#endif
	platform_deinit_interrupts();
	return;
}


int platform_skip_hibernation(void)
{
	if (g_boot_menu == true)
		return 1;

	switch (g_boot_arg->boot_reason) {
#if 0 // let schedule power on to go hiberantion bootup process
	case BR_RTC:
#endif
	case BR_WDT:
	case BR_WDT_BY_PASS_PWK:
	case BR_WDT_SW:
	case BR_WDT_HW:
		return 1;
	}

	return 0;
}

static int md1_version_rdy = 0;
static char md1_version[65];
static int md3_version_rdy = 0;
static char md3_version[65];

int ccci_get_md_version(int md_id, char buf[], int size)
{
	int ret;

	if ((md_id == MD_SYS1) && md1_version_rdy)
		return snprintf(buf, size, "%s", md1_version);
	else if ((md_id == MD_SYS3) && md3_version_rdy)
		return snprintf(md3_version, 65, "%s", md3_version);

	return -1;
}
