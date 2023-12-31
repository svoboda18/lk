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
#include <platform/primary_display.h>
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
#include <platform/disp_drv_platform.h>
#include <plinfo.h>                 // for plinfo_get_brom_header_block_size()
#include <libfdt.h>
// #include <mt_gic.h>                 // for platform_init_interrupts()
#include <mt_boot.h>                // for bldr_load_dtb()
#include <platform.h>               // for platform_uninit()
#include <platform/verified_boot.h>
#include <load_vfy_boot.h>
#include <fdt_op.h>
#include <pal_assert.h>

#if defined(MTK_SECURITY_SW_SUPPORT)
#include "oemkey.h"
#endif

#if defined(MTK_AB_OTA_UPDATER)
#include <bootctrl.h>
#endif

#ifdef MTK_SECURITY_SW_SUPPORT
extern u8 g_oemkey[OEM_PUBK_SZ];
#endif

#ifdef LK_DL_CHECK
/*block if check dl fail*/
#undef LK_DL_CHECK_BLOCK_LEVEL
#endif

extern void platform_early_init_timer();
extern void jump_da(u32 addr, u32 arg1, u32 arg2);
extern int i2c_hw_init(void);
extern int mboot_common_load_logo(unsigned long logo_addr, char* filename);
extern void mtk_wdt_disable(void);
extern void platform_deinit_interrupts(void);
extern int mmc_get_dl_info(void);
extern int mmc_legacy_init(int);
extern bool g_boot_menu;

#ifdef MTK_BATLOWV_NO_PANEL_ON_EARLY
extern kal_bool is_low_battery(kal_int32 val);
extern int hw_charging_get_charger_type(void);
#endif
#ifdef MTK_MT8193_SUPPORT
extern int mt8193_init(void);
#endif
void config_shared_SRAM_size(void);
extern int dev_info_nr_cpu(void);

BOOT_ARGUMENT *g_boot_arg;
BOOT_ARGUMENT boot_addr;
int g_nr_bank;
BI_DRAM bi_dram[MAX_NR_BANK];
unsigned int g_fb_base;
unsigned int g_fb_size;
static int g_dram_init_ret;
static unsigned int bootarg_addr;
static unsigned int bootarg_size;
extern unsigned int logo_lk_t;
extern unsigned int boot_time;


/******************************************************************************
******************************************************************************/
int dram_init(void)
{
	int i;
	struct boot_tag *tags;

	/* Get parameters from pre-loader. Get as early as possible
	 * The address of BOOT_ARGUMENT_LOCATION will be used by Linux later
	 * So copy the parameters from BOOT_ARGUMENT_LOCATION to LK's memory region
	 */
	g_boot_arg = &boot_addr;
	bootarg_addr = BOOT_ARGUMENT_LOCATION;
	bootarg_size = 0;

	if (*(unsigned int *)BOOT_ARGUMENT_LOCATION == BOOT_ARGUMENT_MAGIC) {
		memcpy(g_boot_arg, (void*)BOOT_ARGUMENT_LOCATION, sizeof(BOOT_ARGUMENT));
		bootarg_size = sizeof(BOOT_ARGUMENT);
	} else {
		g_boot_arg->maggic_number = BOOT_ARGUMENT_MAGIC;
		for (tags = (void *)BOOT_ARGUMENT_LOCATION; tags->hdr.size; tags = boot_tag_next(tags)) {
			switch (tags->hdr.tag) {
				case BOOT_TAG_BOOT_REASON:
					g_boot_arg->boot_reason = tags->u.boot_reason.boot_reason;
					break;
				case BOOT_TAG_BOOT_MODE:
					g_boot_arg->boot_mode = tags->u.boot_mode.boot_mode;
					break;
				case BOOT_TAG_META_COM:
					g_boot_arg->meta_com_type = tags->u.meta_com.meta_com_type;
					g_boot_arg->meta_com_id = tags->u.meta_com.meta_com_id;
					g_boot_arg->meta_uart_port = tags->u.meta_com.meta_uart_port;
					break;
				case BOOT_TAG_LOG_COM:
					g_boot_arg->log_port = tags->u.log_com.log_port;
					g_boot_arg->log_baudrate = tags->u.log_com.log_baudrate;
					g_boot_arg->log_enable = tags->u.log_com.log_enable;
					break;
				case BOOT_TAG_MEM:
					g_boot_arg->dram_rank_num = tags->u.mem.dram_rank_num;
					for (i = 0; i < (int)(tags->u.mem.dram_rank_num); i++) {
						g_boot_arg->dram_rank_size[i] = tags->u.mem.dram_rank_size[i];
					}
					g_boot_arg->mblock_info = tags->u.mem.mblock_info;
					g_boot_arg->orig_dram_info = tags->u.mem.orig_dram_info;
					g_boot_arg->lca_reserved_mem = tags->u.mem.lca_reserved_mem;
					g_boot_arg->tee_reserved_mem = tags->u.mem.tee_reserved_mem;
					break;
				case BOOT_TAG_MD_INFO:
					for (i = 0; i < 4; i++) {
						g_boot_arg->md_type[i] = tags->u.md_info.md_type[i];
					}
					break;
				case BOOT_TAG_BOOT_TIME:
					g_boot_arg->boot_time = tags->u.boot_time.boot_time;
					break;
				case BOOT_TAG_DA_INFO:
					memcpy(&g_boot_arg->da_info, &tags->u.da_info.da_info, sizeof(da_info_t));
					break;
				case BOOT_TAG_SEC_INFO:
					memcpy(&g_boot_arg->sec_limit, &tags->u.sec_info.sec_limit, sizeof(SEC_LIMIT));
					break;
				case BOOT_TAG_PART_NUM:
					g_boot_arg->part_num = tags->u.part_num.part_num;
					break;
				case BOOT_TAG_PART_INFO:
					g_boot_arg->part_info = tags->u.part_info.part_info;  /* only copy the pointer but the contains*/
					break;
				case BOOT_TAG_EFLAG:
					g_boot_arg->e_flag = tags->u.eflag.e_flag;
					break;
				case BOOT_TAG_DDR_RESERVE:
					g_boot_arg->ddr_reserve_enable = tags->u.ddr_reserve.ddr_reserve_enable;
					g_boot_arg->ddr_reserve_success = tags->u.ddr_reserve.ddr_reserve_success;
					g_boot_arg->ddr_reserve_ready = tags->u.ddr_reserve.ddr_reserve_ready;
					break;
				case BOOT_TAG_DRAM_BUF:
					g_boot_arg->dram_buf_size = tags->u.dram_buf.dram_buf_size;
					break;
				case BOOT_TAG_SRAM_INFO:
					g_boot_arg->non_secure_sram_addr = tags->u.sram_info.non_secure_sram_addr;
					g_boot_arg->non_secure_sram_size = tags->u.sram_info.non_secure_sram_size;
					break;
				case BOOT_TAG_PTP:
					memcpy(&g_boot_arg->ptp_volt_info, &tags->u.ptp_volt.ptp_volt_info, sizeof(ptp_info_t));
					break;
				case BOOT_TAG_PL_VERSION:
					memcpy(&g_boot_arg->pl_version, &tags->u.pl_version.pl_version, sizeof(tags->u.pl_version.pl_version));
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

			bootarg_size += tags->hdr.size;
		}
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
		//dprintf(CRITICAL, "[LK ERROR] DRAM bank number is not correct!!!");
		//while (1) ;
		return -1;
	}

	/* return the actual DRAM info */
	for (i = 0; i < (int)(g_boot_arg->mblock_info.mblock_num); i++) {
		bi_dram[i].start = g_boot_arg->mblock_info.mblock[i].start;
		bi_dram[i].size = g_boot_arg->mblock_info.mblock[i].size;
	}
#endif
	return 0;
}

unsigned int platform_get_bootarg_addr(void)
{
	return bootarg_addr;
}

unsigned int platform_get_bootarg_size(void)
{
	return bootarg_size;
}

/*******************************************************
 * Routine: memory_size
 * Description: return DRAM size to LCM driver
 ******************************************************/
u64 physical_memory_size(void)
{
	int i;
	unsigned long long size = 0;

	for (i = 0; i < (int)(g_boot_arg->orig_dram_info.rank_num); i++) {
		size += g_boot_arg->orig_dram_info.rank_info[i].size;
	}

	return size;
}

u32 memory_size(void)
{
	unsigned long long size = physical_memory_size();

	while (((unsigned long long)DRAM_PHY_ADDR + size) > 0x100000000ULL) {
		size -= (unsigned long long)(1024*1024*1024);
	}

	return (unsigned int)size;
}

void sw_env()
{
#ifdef LK_DL_CHECK
#ifdef MTK_EMMC_SUPPORT
	int dl_status = 0;
	dl_status = mmc_get_dl_info();
	dprintf(INFO, "mt65xx_sw_env--dl_status: %d\n", dl_status);
	if (dl_status != 0) {
		video_printf("=> TOOL DL image Fail!\n");
		dprintf(CRITICAL, "TOOL DL image Fail\n");
#ifdef LK_DL_CHECK_BLOCK_LEVEL
		dprintf(CRITICAL, "uboot is blocking by dl info\n");
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
	for (addr = 0; addr < dram_size; addr += (1024*1024)) {
		/*virtual to physical 1-1 mapping*/
		arm_mmu_map_section(bi_dram[0].start+addr,bi_dram[0].start+addr, MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | MMU_MEMORY_AP_READ_WRITE);
	}

	/* ummap TEE memory regoin */
	if (g_boot_arg->tee_reserved_mem.size != 0) {
		u64 j, k;
		k = g_boot_arg->tee_reserved_mem.start;
		j = ROUNDUP(g_boot_arg->tee_reserved_mem.size, 1024*1024);
		for (; j > 0; j -= (1024*1024)) {
			arm_mmu_map_section((uintptr_t)k , (uintptr_t)k, MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | MMU_MEMORY_AP_READ_WRITE | MMU_MEMORY_XN);
			k += (1024*1024);
		}
	}
	arch_enable_mmu();  //enable mmu after setup page table to avoid cpu prefetch which may bring on emi violation
}


/******************************************************************************
******************************************************************************/
static void lk_set_sw_segment_code(void)
{
#if defined (MTK_EFUSE_DOWNGRADE)
	set_sw_segment_code();
#endif
}


/******************************************************************************
******************************************************************************/
static void lk_dummy_ap_entry(void)
{
#ifdef DUMMY_AP
	dummy_ap_entry();
#endif
}


/******************************************************************************
******************************************************************************/
static void lk_init_storage(void)
{
#ifdef LK_PROFILING
	unsigned int time_nand_emmc = get_timer(0);
#endif  // LK_PROFILING

#ifdef MTK_EMMC_SUPPORT
	mmc_legacy_init(1);
#else
#ifndef MACH_FPGA
	nand_init();
	nand_driver_test();
#endif  // MACH_FPGA
#endif  // MTK_EMMC_SUPPORT

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] NAND/EMMC init takes %d ms\n", (int)get_timer(time_nand_emmc));
#endif  // LK_PROFILING
}


/******************************************************************************
******************************************************************************/
static void lk_get_AB_OTA_param(void)
{
#ifdef MTK_AB_OTA_UPDATER
	/* get A/B system parameter before load dtb from boot image */
	get_AB_OTA_param();
#endif
}


/******************************************************************************
* FIXME:
* 1. Read RTC register, load "boot"/"recovery dtb according to register value.
* 2. If no RTC bit set, load "boot" dtb.
* 3. If no RTC bit set and no "boot" partition, load "recovery" dtb.
* 4. Consider to make use of (or integrate with) meta_detection(). (Optional)
******************************************************************************/
static void lk_load_device_tree(void)
{
	char *part_name = "boot";

#if !defined(NO_BOOT_MODE_SEL)
	if (Check_RTC_Recovery_Mode() || unshield_recovery_detection())
		part_name = "recovery";
	else
		part_name = "boot";
#endif

#if defined(CFG_DTB_EARLY_LOADER_SUPPORT)
	if (bldr_load_dtb(part_name) < 0)
		dprintf(CRITICAL, "Error: %s failed\n", __func__);
#endif  // CFG_DTB_EARLY_LOADER_SUPPORT
}


/******************************************************************************
******************************************************************************/
static void lk_init_leds(void)
{
#ifdef LK_PROFILING
	unsigned int time_led_init = get_timer(0);
#endif  // LK_PROFILING

#ifndef MACH_FPGA
	leds_init();
#endif

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] led init takes %d ms\n", (int)get_timer(time_led_init));
#endif  // LK_PROFILING
}


/******************************************************************************
******************************************************************************/
static void lk_init_env(void)
{
#ifdef LK_PROFILING
	unsigned int time_env = get_timer(0);
#endif  // LK_PROFILING

	env_init();
	print_env();
#ifdef MTK_USB2JTAG_SUPPORT
	extern void usb2jtag_init(void);
	usb2jtag_init();
#endif  // MTK_USB2JTAG_SUPPORT

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] ENV init takes %d ms\n", (int)get_timer(time_env));
#endif  // LK_PROFILING
}


/******************************************************************************
******************************************************************************/
static void lk_mt65xx_backlight_on(void)
{
#ifdef LK_PROFILING
	unsigned int time_backlight = get_timer(0);
#endif  // LK_PROFILING

#ifndef MACH_FPGA
	mt65xx_backlight_on();
#endif // MACH_FPGA

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] backlight takes %d ms\n", (int)get_timer(time_backlight));
#endif  // LK_PROFILING
}


/******************************************************************************
* It can be regarded that users will see the logo on the display after the
* function mt_disp_update() finishes its execution regardless video mode or
* command mode in the display driver.
******************************************************************************/
static void lk_mt_disp_update(void)
{
#ifdef LK_PROFILING
	unsigned int disp_update = get_timer(0);
#endif  // LK_PROFILING

#ifndef MACH_FPGA_NO_DISPLAY
	//pwm need display sof
	mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
#endif  // MACH_FPGA_NO_DISPLAY

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] disp_update takes %d ms\n", (int)get_timer(disp_update));
#endif  // LK_PROFILING
}


/******************************************************************************
******************************************************************************/
static void lk_init_display(void)
{
#ifdef LK_PROFILING
	unsigned int time_disp_init = get_timer(0);
#endif  // LK_PROFILING

	/* initialize the frame buffet information */
#ifndef MACH_FPGA_NO_DISPLAY
	g_fb_size = mt_disp_get_vram_size();
#else
	g_fb_size = 0x1000000;
#endif  // MACH_FPGA_NO_DISPLAY

	g_fb_base = mblock_reserve(&g_boot_arg->mblock_info, g_fb_size, 0x10000, 0x100000000, RANKMAX);
	if (!g_fb_base) {
		dprintf(CRITICAL, "Error: g_fb_base is NULL!\n");
	}
	dprintf(CRITICAL, "FB base = 0x%x, FB size = %d\n", g_fb_base, g_fb_size);

#ifndef MACH_FPGA_NO_DISPLAY
	mt_disp_init((void *)g_fb_base);
	/* show black picture fisrtly in case of  backlight is on before nothing is drawed*/
	mt_disp_fill_rect(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT, 0x0);
	lk_mt_disp_update();

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] disp init takes %d ms\n", (int)get_timer(time_disp_init));
#endif  // LK_PROFILING

	drv_video_init();
#endif  // MACH_FPGA_NO_DISPLAY
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
	dprintf(CRITICAL,"[PROFILE] vb init takes %d ms\n", (int)get_timer(time_vb_init));
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
		dprintf(CRITICAL, "<ASSERT> %s:line %d\n", __FILE__, __LINE__);
		PAL_ASSERT(0);
	}

	if (DTBO_FROM_STANDALONE == get_dtbo_src()) {
		if (0 != img_auth_stor(get_dtbo_part_name(), NULL)) {
			dprintf(CRITICAL, "<ASSERT> %s:line %d\n", __FILE__, __LINE__);
			PAL_ASSERT(0);
		}
	}
#ifdef LK_PROFILING
	dprintf(CRITICAL,"[PROFILE] vb flow takes %d ms\n", (int)get_timer(time_vb_flow));
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
		u8	*da_addr = (u8*)g_boot_arg->da_info.addr;
		u32 da_len	 = g_boot_arg->da_info.len;
		u32 sig_len  = g_boot_arg->da_info.sig_len;
		u8	*sig_addr = (unsigned char *)da_addr + (da_len - sig_len);

		if (da_len == 0 || sig_len == 0) {
			dprintf(INFO, "[LK] da argument is invalid\n");
			dprintf(INFO, "da_addr = 0x%x\n", (int)da_addr);
			dprintf(INFO, "da_len  = 0x%x\n", da_len);
			dprintf(INFO, "sig_len = 0x%x\n", sig_len);
		}

		if (sec_usbdl_verify_da(da_addr, (da_len - sig_len), sig_addr, sig_len)) {
			/* da verify fail */
			video_printf(" => Not authenticated tool, download stop...\n");
			PAL_ASSERT(0);
		}
	} else
#endif  // MTK_SECURITY_SW_SUPPORT
	{
		dprintf(INFO, " DA verification disabled...\n");
	}
}


/******************************************************************************
******************************************************************************/
static void lk_boot_mode_select(void)
{
#ifndef MACH_FPGA
#ifdef LK_PROFILING
	unsigned int time_boot_mode = get_timer(0);
#endif  // LK_PROFILING

	boot_mode_select();

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] boot mode select takes %d ms\n", (int)get_timer(time_boot_mode));
#endif  // LK_PROFILING
#endif  // MACH_FPGA
}


/******************************************************************************
******************************************************************************/
static void lk_load_logo(void)
{
#ifndef MACH_FPGA_NO_DISPLAY
#ifdef LK_PROFILING
		unsigned int time_load_logo = get_timer(0);
#endif  // LK_PROFILING

		mboot_common_load_logo((unsigned long)mt_get_logo_db_addr_pa(), "logo");

#ifdef LK_PROFILING
		dprintf(CRITICAL, "[PROFILE] load_logo takes %d ms\n", (int)get_timer(time_load_logo));
#endif  // LK_PROFILING
#endif  // MACH_FPGA_NO_DISPLAY
}


/******************************************************************************
******************************************************************************/
static void lk_display_show_logo(void)
{
#ifdef LK_PROFILING
	unsigned int time_show_logo = get_timer(0);
#endif  // LK_PROFILING

#ifndef MACH_FPGA_NO_DISPLAY
	mt_disp_show_boot_logo();
#endif // MACH_FPGA_NO_DISPLAY

	logo_lk_t = ((unsigned int)get_timer(boot_time));

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] show logo takes %d ms\n", (int)get_timer(time_show_logo));
#endif  // LK_PROFILING
}


/******************************************************************************
******************************************************************************/
static void lk_l2_disable(void)
{
#ifdef HAVE_CACHE_PL310
	l2_disable();
#endif
}


/******************************************************************************
******************************************************************************/
static void lk_config_shared_SRAM_size(void)
{
#ifdef ENABLE_L2_SHARING
	config_shared_SRAM_size();
#endif
}


extern void mt65xx_bat_init(void);  // FIXME: include the correct header file!
/******************************************************************************
******************************************************************************/
static void lk_init_battery(void)
{
#ifdef LK_PROFILING
	unsigned int time_bat_init = get_timer(0);
#endif

	mt65xx_bat_init();

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] battery init takes %d ms\n", (int)get_timer(time_bat_init));
#endif
}


/******************************************************************************
******************************************************************************/
static void lk_rtc_boot_check(bool flag)
{
#ifndef CFG_POWER_CHARGING
#ifdef LK_PROFILING
	unsigned int time_RTC_boot_Check = get_timer(0);
#endif  // LK_PROFILING

	/* NOTE: if define CFG_POWER_CHARGING, will rtc_boot_check() in mt65xx_bat_init() */
	rtc_boot_check(flag);

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] RTC boot check Init  takes %d ms\n", (int)get_timer(time_RTC_boot_Check));
#endif  // LK_PROFILING
#endif  // CFG_POWER_CHARGING
}


/******************************************************************************
******************************************************************************/
static void lk_sw_env(void)
{
#ifndef MACH_FPGA
#ifdef LK_PROFILING
	unsigned int time_sw_env = get_timer(0);
#endif  // LK_PROFILING

	sw_env();

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] sw_env takes %d ms\n", (int)get_timer(time_sw_env));
#endif  // LK_PROFILING
#endif  // MACH_FPGA
}


/******************************************************************************
******************************************************************************/
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
		for (addr = 0; addr < dram_size; addr += (1024*1024)) {
			/*virtual to physical 1-1 mapping*/
			arm_mmu_map_section(bi_dram[0].start+addr, bi_dram[0].start+addr, MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | MMU_MEMORY_AP_READ_WRITE);
		}

		/* ummap TEE memory regoin */
		if (g_boot_arg->tee_reserved_mem.size != 0) {
			u64 j, k;
			k = g_boot_arg->tee_reserved_mem.start;
			j = ROUNDUP(g_boot_arg->tee_reserved_mem.size, 1024*1024);
			for (; j > 0; j -= (1024*1024)) {
				arm_mmu_map_section((uintptr_t)k , (uintptr_t)k, MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | MMU_MEMORY_AP_READ_WRITE | MMU_MEMORY_XN);
				k += (1024*1024);
			}
		}
	} else {
		arm_mmu_lpae_init();
		/* map dram region */
		for (addr = 0; addr < dram_size; addr += (unsigned long long)(1024*1024*1024)) {
			vaddr = (bi_dram[0].start + addr < 0x100000000ULL) ? (unsigned int)(bi_dram[0].start + addr) : (0xC0000000);
			arm_mmu_map_block(bi_dram[0].start+addr, vaddr, LPAE_MMU_MEMORY_TYPE_NORMAL_WRITE_BACK);
		}
		/* ummap TEE memory regoin */
		if (g_boot_arg->tee_reserved_mem.size != 0) {
			u64 j, k;
			k = g_boot_arg->tee_reserved_mem.start;
			j = ROUNDUP(g_boot_arg->tee_reserved_mem.size, 0x40000000ULL);
			for (; j > 0; j -= 0x40000000ULL) {
				arm_mmu_map_block((uintptr_t)k , (uintptr_t)k, LPAE_MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | LPAE_MMU_MEMORY_XN);
				k += 0x40000000ULL;
			}
		}
	}
	arch_enable_mmu();  //enable mmu after setup page table to avoid cpu prefetch which may bring on emi violation
}



void platform_early_init(void)
{
#ifdef LK_PROFILING
	unsigned int time_wdt_early_init;
	unsigned int time_pmic_init;
	unsigned int time_platform_early_init;
#endif

	platform_init_interrupts();

	platform_early_init_timer();

#if defined(MACH_FPGA) || defined(SB_LK_BRINGUP)
	mtk_timer_init();  // GPT4 will be initialized at PL after
#endif

#ifdef LK_PROFILING
	time_platform_early_init = get_timer(0);
#endif

#ifndef MACH_FPGA
#ifndef DUMMY_AP
	mt_gpio_set_default();
#endif
#endif

	/* initialize the uart */
	uart_init_early();

	dprintf(SPEW, "bootarg_addr: 0x%x, bootarg_size: 0x%x\n", platform_get_bootarg_addr(), platform_get_bootarg_size());

	if (g_dram_init_ret < 0) {
		dprintf(CRITICAL, "[LK ERROR] DRAM bank number is not correct!!!\n");
		while (1) ;
	}

	//i2c_v1_init();

#ifdef LK_PROFILING
	time_wdt_early_init = get_timer(0);
#endif
	mtk_wdt_init();
#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] WDT Init  takes %d ms\n", (int)get_timer(time_wdt_early_init));
#endif

	//i2c init
	i2c_hw_init();

#if defined(MACH_FPGA) || defined(SB_LK_BRINGUP)
	//mtk_timer_init();  // GPT4 will be initialized at PL after
	mtk_wdt_disable();  // WDT will be triggered when uncompressing linux image on FPGA
	*(volatile unsigned int *)0x10212000 = 0x22000064;
#endif

#if MTK_MT8193_SUPPORT
	mt8193_init();
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
	dprintf(CRITICAL, "[PROFILE] pmic_init takes %d ms\n", (int)get_timer(time_pmic_init));
#endif

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] platform_early_init takes %d ms\n", (int)get_timer(time_platform_early_init));
#endif
}

extern bool mtk_bat_allow_backlight_enable(void);
#if defined (MTK_KERNEL_POWER_OFF_CHARGING)

int kernel_charging_boot(void)
{
	if ((g_boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT || g_boot_mode == LOW_POWER_OFF_CHARGING_BOOT) && upmu_is_chr_det() == KAL_TRUE) {
		dprintf(INFO,"[%s] Kernel Power Off Charging with Charger/Usb \n", __func__);
		return  1;
	} else if ((g_boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT || g_boot_mode == LOW_POWER_OFF_CHARGING_BOOT) && upmu_is_chr_det() == KAL_FALSE) {
		dprintf(INFO,"[%s] Kernel Power Off Charging without Charger/Usb \n", __func__);
		return -1;
	} else
		return 0;
}
#endif

#if defined (MTK_EFUSE_DOWNGRADE)
extern u32 get_devinfo_with_index(u32);
extern void set_thermal_option(u32);
int set_sw_segment_code(void)
{
    u32 segment_code = get_devinfo_with_index(47) >> 25;
    dprintf(CRITICAL, "OLD get_devinfo_with_index=0x%x\n", segment_code);
    switch(segment_code){
        case 0x52:
            set_thermal_option(0x4A);
            break;
        case 0x53:
            set_thermal_option(0x4B);
            break;
        case 0x41:
            set_thermal_option(0x49);
            break;
    }
    dprintf(CRITICAL, "NEW get_devinfo_with_index=0x%x\n", (get_devinfo_with_index(47)>>25));

    return 0;
}
#endif

void platform_init(void)
{
#ifdef LK_PROFILING
	unsigned int time_platform_init = get_timer(0);
#endif
	bool bearly_backlight_on = false;

	dprintf(CRITICAL," ==LK info ==\n");
	dprintf(CRITICAL," chip_code[0x%x]\n",  mt_get_chip_hw_code());
	dprintf(CRITICAL," chip_ver[0x%x]\n",   mt_get_chip_sw_ver());
	dprintf(CRITICAL," ==LK info ==\n");
	dprintf(CRITICAL, "platform_init()\n");

	lk_set_sw_segment_code();

	lk_dummy_ap_entry();

	lk_init_storage();

	lk_get_AB_OTA_param();

	lk_load_device_tree();

	lk_init_leds();

#ifdef MTK_KERNEL_POWER_OFF_CHARGING
	if ((g_boot_arg->boot_reason == BR_USB) && (upmu_is_chr_det() == KAL_FALSE)) {
		dprintf(INFO, "[%s] Unplugged Charger/Usb between Pre-loader and Uboot in Kernel Charging Mode, Power Off \n", __func__);
		mt6575_power_off();
	}
#endif

	lk_init_env();

	lk_init_display();

	lk_vb_init();
	lk_vb_flow();

	/*for kpd pmic mode setting*/
	set_kpd_pmic_mode();

	lk_boot_mode_select();

	/* If RECOVERY_AS_BOOT is enabled, there is no recovery partition. */
#if defined(CFG_DTB_EARLY_LOADER_SUPPORT) && !defined(RECOVERY_AS_BOOT)
	/* reload dtb when boot mode = recovery */
	if ((g_boot_mode == RECOVERY_BOOT) && (get_recovery_dtbo_loaded() != 1)){
		if (bldr_load_dtb("recovery") < 0)
			dprintf(CRITICAL, "bldr_load_dtb fail\n");
	}
#endif  // CFG_DTB_EARLY_LOADER_SUPPORT	

	lk_load_logo();

	/*Show download logo & message on screen */
	if (g_boot_arg->boot_mode == DOWNLOAD_BOOT) {
		dprintf(CRITICAL, "[LK] boot mode is DOWNLOAD_BOOT\n");
		lk_verify_da();
		lk_display_show_logo();
		video_printf(" => Downloading...\n");
		dprintf(CRITICAL, "enable backlight after show bootlogo! \n");
		lk_mt65xx_backlight_on();
		mtk_wdt_disable(); //Disable wdt before jump to DA
		platform_uninit();
		lk_l2_disable();
		arch_disable_cache(UCACHE);
		arch_disable_mmu();
		lk_config_shared_SRAM_size();
		jump_da(g_boot_arg->da_info.addr, g_boot_arg->da_info.arg1, g_boot_arg->da_info.arg2);
	}
#ifdef MTK_KERNEL_POWER_OFF_CHARGING
	else if (g_boot_mode != ALARM_BOOT && g_boot_mode != FASTBOOT && g_boot_mode != KERNEL_POWER_OFF_CHARGING_BOOT && g_boot_mode != LOW_POWER_OFF_CHARGING_BOOT && mtk_bat_allow_backlight_enable()) {
		lk_display_show_logo();
		lk_mt65xx_backlight_on();
		lk_mt_disp_update();
		bearly_backlight_on = true;
		dprintf(INFO, "backlight enabled before battery init\n");
	}
#endif  // MTK_KERNEL_POWER_OFF_CHARGING

	lk_init_battery();

	lk_rtc_boot_check(false);

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
	} else if (g_boot_mode != KERNEL_POWER_OFF_CHARGING_BOOT && g_boot_mode != LOW_POWER_OFF_CHARGING_BOOT) {
		if (g_boot_mode != ALARM_BOOT && (g_boot_mode != FASTBOOT) && !bearly_backlight_on) {
			lk_display_show_logo();
		}
	}
#else
	if (g_boot_mode != ALARM_BOOT && (g_boot_mode != FASTBOOT) && !bearly_backlight_on) {
		lk_display_show_logo();
	}
#endif  // MTK_KERNEL_POWER_OFF_CHARGING

#ifdef MTK_BATLOWV_NO_PANEL_ON_EARLY
	if (!is_low_battery(0)) {
#endif
		lk_mt65xx_backlight_on();
		lk_mt_disp_update();
#ifdef MTK_BATLOWV_NO_PANEL_ON_EARLY
	}
#endif

	lk_sw_env();

#ifdef LK_PROFILING
	dprintf(CRITICAL, "[PROFILE] platform_init takes %d ms\n", (int)get_timer(time_platform_init));
#endif
}


/******************************************************************************
******************************************************************************/
void platform_uninit(void)
{
#ifndef MACH_FPGA
	leds_deinit();
#endif
	platform_deinit_interrupts();
	return;
}

#ifdef ENABLE_L2_SHARING
#define ADDR_CA7L_CACHE_CONFIG_MP(x) (CA7MCUCFG_BASE + 0x200 * x)
#define L2C_SIZE_CFG_OFFSET  8
#define L2C_SHARE_EN_OFFSET  12
/* 4'b1111: 2048KB(not support)
 * 4'b0111: 1024KB(not support)
 * 4'b0011: 512KB
 * 4'b0001: 256KB
 * 4'b0000: 128KB (not support)
 */

int is_l2_need_config(void)
{
	volatile unsigned int cache_cfg, addr;

	addr = ADDR_CA7L_CACHE_CONFIG_MP(0);
	cache_cfg = DRV_Reg32(addr);
	cache_cfg = cache_cfg >> L2C_SIZE_CFG_OFFSET;

	/* only read 256KB need to be config.*/
	if ((cache_cfg &(0x7)) == 0x1) {
		return 1;
	}
	return 0;
}

void cluster_l2_share_enable(int cluster)
{
	volatile unsigned int cache_cfg, addr;

	addr = ADDR_CA7L_CACHE_CONFIG_MP(cluster);
	/* set L2C size to 256KB */
	cache_cfg = DRV_Reg32(addr);
	cache_cfg &= (~0x7) << L2C_SIZE_CFG_OFFSET;
	cache_cfg |= 0x1 << L2C_SIZE_CFG_OFFSET;

	/* enable L2C_share_en. Sram only for other to use*/
	cache_cfg |= (0x1 << L2C_SHARE_EN_OFFSET);
	DRV_WriteReg32(addr, cache_cfg);
}

void cluster_l2_share_disable(int cluster)
{
	volatile unsigned int cache_cfg, addr;

	addr = ADDR_CA7L_CACHE_CONFIG_MP(cluster);
	/* set L2C size to 512KB */
	cache_cfg = DRV_Reg32(addr);
	cache_cfg &= (~0x7) << L2C_SIZE_CFG_OFFSET;
	cache_cfg |= 0x3 << L2C_SIZE_CFG_OFFSET;
	DRV_WriteReg32(addr, cache_cfg);

	/* disable L2C_share_en. Sram only for cpu to use*/
	cache_cfg &= ~(0x1 << L2C_SHARE_EN_OFFSET);
	DRV_WriteReg32(addr, cache_cfg);
}

/* config L2 cache and sram to its size */
void config_L2_size(void)
{
	int cluster;

	if (is_l2_need_config()) {
		/*
		 * Becuase mcu config is protected.
		 * only can write in secutity mode
		 */

		if (dev_info_nr_cpu() == 6) {
			cluster_l2_share_disable(0);
			cluster_l2_share_enable(1);
		}

		else {
			for (cluster = 0; cluster < 2; cluster++) {
				cluster_l2_share_disable(cluster);
			}
		}
	}
}

/* config SRAM back from L2 cache for DA relocation */
void config_shared_SRAM_size(void)
{
	int cluster;

	if (is_l2_need_config()) {
		/*
		 * Becuase mcu config is protected.
		 * only can write in secutity mode
		 */

		for (cluster = 0; cluster < 2; cluster++) {
			cluster_l2_share_enable(cluster);
		}
	}
}
#endif

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
