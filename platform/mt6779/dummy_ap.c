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
//#define CTP_ENV
#ifndef CTP_ENV
/* Note: Pleae enable DUMMY_AP option at rule.mk if hope to use this function */
#include <platform/boot_mode.h>
#include <debug.h>
#include <dev/uart.h>
#include <platform/mtk_key.h>
#include <target/cust_key.h>
#include <platform/mt_gpio.h>
#include <sys/types.h>
#include <debug.h>
#include <err.h>
#include <reg.h>
#include <string.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_irq.h>
#include <platform/mt_pmic.h>
#include <platform/timer.h>
#include <sys/types.h>
#include <arch/ops.h>
#include <platform/mt_pmic.h>
#include <platform/upmu_common.h>
#include <platform/upmu_hw.h>
#include <platform/spm.h>
#else
/*CTP environment*/
#include <gpio.h>
#include <barriers.h>
#include <sync_write.h>
#include <upmu_hw.h>
#include <mt_spm_reg.h>
#include <mt_spm_mtcmos.h>
#include <efuse.h>

#define dprintf(CRITICAL, fmt, args...) dbg_print("[MD]: "fmt, ##args)
static void let_md_go(int md_id);
static void config_md_boot_env(int md_id, int boot_mode);
#endif	/*CTP_ENV*/

//------- feature option part ---------------------------------------
//#define DEFAULT_META
#define ENABLE_MD_RESET_SPM
//#define ENABLE_MD_RESET_RGU
//#define IGNORE_MD_WDT
//#define IGNORE_MD1_WDT
//#define IGNORE_MD2_WDT
//#define NO_UNGATE_MD

//------- enum and macro part ---------------------------------------
enum {
	MD_SYS1 = 0,
	MD_SYS2,
	MD_SYS3,
	MD_SYS4,
};

enum {
	AP_ONLY = -1,
	MD1_ONLY = 0,
	MD2_ONLY,
	MD1_MD2,
};

#define ccci_write32(b, a, v)           DRV_WriteReg32((b)+(a), (v))
#define ccci_read32(b, a)               DRV_Reg32((b)+(a))
#define ccci_write16(b, a, v)           DRV_WriteReg16((b)+(a), (v))
#define ccci_read16(b, a)               DRV_Reg16((b)+(a))
#define ccci_write8(b, a, v)            DRV_WriteReg8((b)+(a), (v))
#define ccci_read8(b, a)                DRV_Reg8((b)+(a))

struct sram_cfg {
	unsigned int offset;
	unsigned int start_bit;
	unsigned int end_bit;
};


//------- IRQ ID part ---------------------------------------
#define GIC_PRIVATE_SIGNALS (32)
#define MT_MD_WDT1_IRQ_ID   (77+GIC_PRIVATE_SIGNALS)


//------- register part ---------------------------------------
#define MD1_BUS_PROTECT_SET   (0x100012A0)
#define MD1_BUS_PROTECT_CLR   (0x100012A4)
#define MD1_BUS_PROTECT_STA   (0x10001228)
#define MD1_BUS_PROTECT1_SET  (0x100012A8)
#define MD1_BUS_PROTECT1_CLR  (0x100012AC)
#define MD1_BUS_PROTECT1_STA  (0x10001258)
#define PROTECTION_BITMASK 	((0x1 << 3)|(0x1 << 4)|(0x1 << 7)) // bit 3,4,7
#define PROTECTION1_BITMASK 	(0x1 << 6) // bit 6

#define MD1_BOOT_VECTOR_EN   (0x20000024)
#define MD1_META_FLAG        (0x20000010)

#define TOPRGU_BASE            (0x10007000)
#define TOP_RGU_WDT_MODE       (0x0)
#define TOP_RGU_WDT_SWRST      (0x14)
#define TOP_RGU_WDT_SWSYSRST   (0x18)
#define TOP_RGU_WDT_NONRST_REG (0x20)
#define TOP_RGU_LATCH_CONTROL  (0x44)
#define MD1_SYS (1 << 7)

#define UNLOCK_KEY (0x88000000)

#define MD_USB_INTERRUPT_MUX 0x10000280

/* MD RGU PCore
#define BASE_ADDR_MDRSTCTL   0x200F0000
#define MD_RGU_BASE          (BASE_ADDR_MDRSTCTL + 0x100)
#define WDT_MD_MODE          (0x0)
#define WDT_MD_MODE_KEY      (0x55000030)
*/
#define PLL_TYPE    (volatile kal_uint32 *)
// AP view
#define BASE_MADDR_APMIXEDSYS     (0x1000C000)
#define BASE_MADDR_MDTOP_PLLMIXED (0x20140000)
#define BASE_MADDR_MDTOP_CLKSW    (0x20150000)


#define UINT32P         (volatile unsigned int *)

#define SLEEP_BASE         (0x10006000)
#define POWERON_CONFIG_EN  (UINT32P (SLEEP_BASE+0x0))
#define SPM_POWER_ON_VAL1  (UINT32P (SLEEP_BASE+0x8))

#define INFRACFG_AO_BASE    (0x10001000)
#define INFRA_TOPAXI_PROTECTEN_1_SET (0x2A8)
#define INFRA_TOPAXI_PROTECTEN_1_CLR (0x2AC)
#define INFRA_MISC2             (0xF0C)

#define INFRA_SEC_BASE   (0x1001a000)
#define MD_BROM_0     (0x824)
#define MD_BROM_1     (0x828)
#define MD_BROM_2     (0x82C)
#define MD_BROM_3     (0x830)

//------- GPIO part ---------------------------------------
#define GPIO_MAGIC		(0x80000000)
// -- UART
#define NO_NEED_UART_CONFIG
#ifndef NO_NEED_UART_CONFIG
#define UART1_TX_GPIO_ID (GPIO54 | GPIO_MAGIC)
#define UART1_RX_GPIO_ID (GPIO53 | GPIO_MAGIC)
#define UART2_TX_GPIO_ID (GPIO149 | GPIO_MAGIC)
#define UART2_RX_GPIO_ID (GPIO147 | GPIO_MAGIC)
#define UART3_TX_GPIO_ID (GPIO48 | GPIO_MAGIC)
#define UART3_RX_GPIO_ID (GPIO47 | GPIO_MAGIC)
#define UART4_TX_GPIO_ID (GPIO50 | GPIO_MAGIC)
#define UART4_RX_GPIO_ID (GPIO49 | GPIO_MAGIC)
#endif

//------- code part ---------------------------------------
static unsigned int img_load_flag = 0;

#ifndef CTP_ENV
extern BOOT_ARGUMENT    *g_boot_arg;
extern char *ld_md_errno_to_str(int errno);

static int meta_detection(void)
{
	int boot_mode;
#ifdef DEFAULT_META
	boot_mode = 1;
	return boot_mode;
#endif
	boot_mode = 0;
	if (g_boot_arg->boot_mode != NORMAL_BOOT)
		boot_mode = 1;
	dprintf(CRITICAL, "Meta mode: %d, boot_mode: %d\n", boot_mode, g_boot_arg->boot_mode);
	return boot_mode;
}

void md_wdt_init(void)
{
	if (img_load_flag & (1 << MD_SYS1)) {
		mt_irq_set_sens(MT_MD_WDT1_IRQ_ID, MT65xx_EDGE_SENSITIVE);
		mt_irq_set_polarity(MT_MD_WDT1_IRQ_ID, MT65xx_POLARITY_LOW);
		mt_irq_unmask(MT_MD_WDT1_IRQ_ID);
	}
}

#endif	//#ifndef CTP_ENV

void md_uart_config(int type_id, int boot_mode)
{
#ifndef NO_NEED_UART_CONFIG
	switch (type_id) {
		case AP_ONLY: // for AP only
			dprintf(CRITICAL, "md_uart_config:%d, UART1->AP_0, UART2->N/A, UART3->MD1_0, UART4->MD1\n", type_id);
			// same as dws initial setting
				mt_set_gpio_mode(UART1_TX_GPIO_ID, GPIO_MODE_01);
				mt_set_gpio_mode(UART1_RX_GPIO_ID, GPIO_MODE_01);
				mt_set_gpio_mode(UART3_TX_GPIO_ID, GPIO_MODE_04);
				mt_set_gpio_mode(UART3_RX_GPIO_ID, GPIO_MODE_04);
			break;
		case MD1_ONLY: // for AP & MD1
		case MD2_ONLY: // for AP & C2K
		case MD1_MD2: // for both MD1 and C2K
			if (boot_mode) {
				dprintf(CRITICAL, "md_uart_config:%d, UART3->MD1_0, UART1->AP_0, UART2->NA/A, UART4->MD1\n", type_id);
				mt_set_gpio_mode(UART1_TX_GPIO_ID, GPIO_MODE_01);
				mt_set_gpio_mode(UART1_RX_GPIO_ID, GPIO_MODE_01);
				mt_set_gpio_mode(UART3_TX_GPIO_ID, GPIO_MODE_04);
				mt_set_gpio_mode(UART3_RX_GPIO_ID, GPIO_MODE_04);

			}
			break;
		default:
			break;
	}
#endif
}

void bus_protection_en(int md_id)
{
	if (md_id == MD_SYS1) {
		/* enable protection for MD1 */
		dprintf(CRITICAL, "enable protection for md\n");
		DRV_WriteReg32(MD1_BUS_PROTECT_SET, PROTECTION_BITMASK);
		DRV_WriteReg32(MD1_BUS_PROTECT1_SET, PROTECTION1_BITMASK);
		/* poll protection ready */
		dprintf(CRITICAL, "wait protection ....\n");
		while ((DRV_Reg32(MD1_BUS_PROTECT_STA)&PROTECTION_BITMASK) != PROTECTION_BITMASK) {
			dprintf(CRITICAL, "0x%x\n", DRV_Reg32(MD1_BUS_PROTECT_STA));
		}
		dprintf(CRITICAL, "wait protection1 ....\n");
		while ((DRV_Reg32(MD1_BUS_PROTECT1_STA)&PROTECTION1_BITMASK) != PROTECTION1_BITMASK) {
			dprintf(CRITICAL, "0x%x\n", DRV_Reg32(MD1_BUS_PROTECT1_STA));
		}
		dprintf(CRITICAL, "protection enable done\n");
		return;
	}
}

void bus_protection_diable(int md_id)
{
	if (md_id == MD_SYS1) {
		/* enable protection for MD1 */
		dprintf(CRITICAL, "disable protection for md\n");
		DRV_WriteReg32(MD1_BUS_PROTECT_CLR, PROTECTION_BITMASK);
		DRV_WriteReg32(MD1_BUS_PROTECT1_CLR, PROTECTION1_BITMASK);
		/* poll protection ready */
		dprintf(CRITICAL, "wait protection disable....\n");
		while ((DRV_Reg32(MD1_BUS_PROTECT_STA)&PROTECTION_BITMASK) != 0x00000000) {
			dprintf(CRITICAL, "0x%x\n", DRV_Reg32(MD1_BUS_PROTECT_STA));
		}
		dprintf(CRITICAL, "wait protection1 disable....\n");
		while ((DRV_Reg32(MD1_BUS_PROTECT1_STA)&PROTECTION1_BITMASK) != 0x00000000) {
			dprintf(CRITICAL, "0x%x\n", DRV_Reg32(MD1_BUS_PROTECT1_STA));
		}

		dprintf(CRITICAL, "protection disable done\n");
		return;
	}
}

int md_common_setting()
{
	unsigned int reg_value;

	// MD srcclkena setting: [7:4]=4'h0110, [3:0]=4'h1101
	reg_value = ccci_read32(INFRACFG_AO_BASE, INFRA_MISC2);
	reg_value &= ~(0xFF);
	reg_value |= 0x21;
	ccci_write32(INFRACFG_AO_BASE, INFRA_MISC2, reg_value);
	dprintf(CRITICAL, "MD srcclkena setting:0x%x\n", ccci_read32(INFRACFG_AO_BASE, INFRA_MISC2));

	return 0;
}

static void config_md_boot_env(int md_id, int boot_mode)
{
	spm_write(POWERON_CONFIG_EN, 0x0B160001);
	spm_write(SPM_POWER_ON_VAL1, 0x80215830);
	dprintf(CRITICAL, "md_srclkena done!\n");

	spm_mtcmos_ctrl_md1(STA_POWER_ON);
	dprintf(CRITICAL, "MD1 MTCMOS power on done!\n");

	bypass_md_boot_rom();
}

static void let_md_go(int md_id)
{
	switch (md_id) {
		case MD_SYS1:
			/* step 8: trigger modem SW to run */
#ifndef NO_UNGATE_MD
			ccci_write32(MD1_BOOT_VECTOR_EN, 0, 1);
#else
			dprintf(CRITICAL, "do not let MD1 go\n");
#endif
			break;
		default:
			break;
	}
}

void md_wdt_irq_handler(unsigned int irq)
{

	//spm_mtcmos_ctrl_audio(STA_POWER_DOWN);
	//dprintf(CRITICAL, "turn off audio.\n");
#if defined(ENABLE_MD_RESET_SPM) || defined(ENABLE_MD_RESET_RGU)
	unsigned int reg_value = 0;
	unsigned int cnt = ccci_read32(TOPRGU_BASE, TOP_RGU_WDT_NONRST_REG);

	// update counter
	ccci_write32(TOPRGU_BASE, TOP_RGU_WDT_NONRST_REG, cnt + 1);
	// reset UART config
	md_uart_config(AP_ONLY, 0);
	dprintf(CRITICAL, "\n\n\n\nCurrent wdt cnt:%d\n", cnt + 1);

	if (irq == MT_MD_WDT1_IRQ_ID) {
#ifdef ENABLE_MD_RESET_SPM
		dprintf(CRITICAL, "MD1 power off\n");
		spm_mtcmos_ctrl_md1(STA_POWER_DOWN);
		mdelay(5);
		config_md_boot_env(MD_SYS1, 0);
#endif
#ifdef ENABLE_MD_RESET_RGU
		dprintf(CRITICAL, "MD1 reset\n");

		bus_protection_en(0);
		ccci_write32(TOPRGU_BASE, TOP_RGU_WDT_SWSYSRST,
			(ccci_read32(TOPRGU_BASE, TOP_RGU_WDT_SWSYSRST) | UNLOCK_KEY) | MD1_SYS);
		mdelay(5);
		ccci_write32(TOPRGU_BASE, TOP_RGU_WDT_SWSYSRST,
			(ccci_read32(TOPRGU_BASE, TOP_RGU_WDT_SWSYSRST) | UNLOCK_KEY) & (~MD1_SYS));
		bus_protection_diable(0);
#endif
		let_md_go(MD_SYS1);
	}

#if 1
	dprintf(CRITICAL, "Config UART after MD WDT! %d\n", cnt+1);
	if ((img_load_flag&((1 << MD_SYS1) | (1 << MD_SYS3))) == ((1 << MD_SYS1) | (1 << MD_SYS3))) {
		md_uart_config(MD1_MD2, 0);
	} else if (img_load_flag & (1 << MD_SYS1)) {
		md_uart_config(MD1_ONLY, 0);
	} else if (img_load_flag & (1 << MD_SYS3)) {
		md_uart_config(MD2_ONLY, 0);
	}
#endif
#else
	md_uart_config(AP_ONLY, 0);
	dprintf(CRITICAL, "Get MD WDT irq, STA:%x!!\n", ccci_read32(MD_RGU_BASE, 0xC));
#ifdef IGNORE_MD_WDT
	dprintf(CRITICAL, "ignore MD WDT\n");
#else
	dprintf(CRITICAL, "whole system reboot\n");
	ccci_write32(TOPRGU_BASE, TOP_RGU_LATCH_CONTROL, 0x95000000);
	ccci_write32(TOPRGU_BASE, TOP_RGU_WDT_MODE, 0x22000004);
	ccci_write32(TOPRGU_BASE, TOP_RGU_WDT_SWRST, 0x1209);
	while (1);
#endif
#endif
	//spm_mtcmos_ctrl_audio(STA_POWER_ON);
	//dprintf(CRITICAL, "turn on audio.\n");
}

int dummy_ap_irq_helper(unsigned int irq)
{
	switch (irq) {
	case MT_MD_WDT1_IRQ_ID:
		if (img_load_flag &(1 << MD_SYS1)) {
#ifndef IGNORE_MD1_WDT
			md_wdt_irq_handler(MT_MD_WDT1_IRQ_ID);
#else
			dprintf(CRITICAL, "ignore MD1 WDT\n");
#endif
		}
		return 1;
	default:
		break;
}

	return 0;
}

#define BRINGUP_BYPASS_BROM /* bypass brom */
int bypass_md_boot_rom(void)
{
#ifdef BRINGUP_BYPASS_BROM
	#define MDPERIMISC_BASE    (0x20060000)
		/* Change boot slave jump address */
		// unlock to write boot slave jump address
		ccci_write32(MDPERIMISC_BASE, 0x10C, 0x5500);
		// write 0x0 to boot slave jump address
		ccci_write32(MDPERIMISC_BASE, 0x104, 0x0);
		// update boot slave jump address
		ccci_write32(MDPERIMISC_BASE, 0x108, 0x1);
		return 0;
#else
		return -1;
#endif
}
#if 0//ndef CTP_ENV
int md_brom_boot(int boot_mode)
{
	int ret = -1;
	int i;

	config_md_boot_env(MD_SYS1, boot_mode);
	let_md_go(MD_SYS1);

	for (i = 0; i < 200; i++) {
		if ((ccci_read32(INFRA_SEC_BASE, MD_BROM_0) == 1) &&
			(ccci_read32(INFRA_SEC_BASE, MD_BROM_1) == 1) &&
			(ccci_read32(INFRA_SEC_BASE, MD_BROM_2) == 1) &&
			(ccci_read32(INFRA_SEC_BASE, MD_BROM_3) == 1)) {
			dprintf(CRITICAL, "BROM success!!\n");
			 spm_mtcmos_ctrl_md1(STA_POWER_DOWN);
			//mdelay(5); no need
			ret = 0;
			break;
		}
		mdelay(10);
	}

	if (ret) {
		dprintf(CRITICAL, "BROM Failed: 0x%x, 0x%x, 0x%x, 0x%x\n",
			ccci_read32(INFRA_SEC_BASE, MD_BROM_0),
			ccci_read32(INFRA_SEC_BASE, MD_BROM_1),
			ccci_read32(INFRA_SEC_BASE, MD_BROM_2),
			ccci_read32(INFRA_SEC_BASE, MD_BROM_3));
		if (bypass_md_boot_rom() >= 0)
			let_md_go(MD_SYS1);
	}
	return ret;
}
#endif
void dummy_ap_boot_up_md(int md_ld_flag)
{
	int boot_mode = 0;
	int i = 0;
	int ret;

	img_load_flag = (unsigned int)md_ld_flag;

	// reinit UART, overwrite DWS setting
	md_uart_config(AP_ONLY, 0);

	// Disable AP WDT
	*(volatile unsigned int *)(TOPRGU_BASE) = 0x22000000;

	dprintf(CRITICAL, "Welcome to use dummy AP!\n");

	dprintf(CRITICAL, "load flag for dummy AP: %x\n", img_load_flag);
#ifndef	CTP_ENV
	if (img_load_flag == 0) {
		dprintf(CRITICAL, "no MD loaded for dummy AP\n");
		ret = get_md_err_from_lk_info(MD_SYS1);
		dprintf(CRITICAL, "hint for MD1 errno: %x, %s\n", ret, ld_md_errno_to_str(-ret));
		ret = get_md_err_from_lk_info(MD_SYS3);
		dprintf(CRITICAL, "hint for MD3 errno: %x, %s\n", ret, ld_md_errno_to_str(-ret));
		dprintf(CRITICAL, "stop.....\n");
		while (1);
	}

	if (img_load_flag & (1 << MD_SYS1)) {
		dprintf(CRITICAL, "MD1 loaded");
		ret = get_md_err_from_lk_info(MD_SYS1);
		if (ret < 0) {
			dprintf(CRITICAL, "MD1 load image has error, errno:%s", ld_md_errno_to_str(-ret));
			while (1);
		}
	}
	// 2, Check boot Mode

	// 3, MD WDT ISR init
	dprintf(CRITICAL, "Init MD WDT\n");
	md_wdt_init();
#endif

	// 6. Switch UART
	dprintf(CRITICAL, "Switch UART!\n");
	md_uart_config(MD1_ONLY, boot_mode);	// 4. Common setting for all MD

	dprintf(CRITICAL, "MD%d Enabled\n", i+1);
	md_common_setting();
#if 0//ndef CTP_ENV
	ret = md_brom_boot(boot_mode);
	if ( ret == 0)
#endif
	 {
		config_md_boot_env(MD_SYS1, boot_mode);
		let_md_go(MD_SYS1);
	}

#ifndef CTP_ENV
	dprintf(CRITICAL, "enter while(1), ^O^!!!!!!!!!\n");
	while (1);
#endif
}
