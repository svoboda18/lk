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
#define MT_MD_WDT1_IRQ_ID   (227+GIC_PRIVATE_SIGNALS)


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

// MD RGU PCore
#define BASE_ADDR_MDRSTCTL   0x200F0000
#define MD_RGU_BASE          (BASE_ADDR_MDRSTCTL + 0x100)
#define WDT_MD_MODE          (0x0)
#define WDT_MD_MODE_KEY      (0x55000030)

#define PLL_TYPE    (volatile kal_uint32 *)
// AP view
#define BASE_MADDR_APMIXEDSYS     (0x1000C000)
#define BASE_MADDR_MDTOP_PLLMIXED (0x20140000)
#define BASE_MADDR_MDTOP_CLKSW    (0x20150000)

#define REG_APMIXEDSYS_AP_PLL_CON0	    (PLL_TYPE(BASE_MADDR_APMIXEDSYS+0x0))

#define REG_MDTOP_PLLMIXED_PLL_VERSION              (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED))
#define REG_MDTOP_PLLMIXED_DCXO_PLL_SETTLE_CTL	    (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x4))
#define REG_MDTOP_PLLMIXED_PLL_ON_CTL               (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x10))
#define REG_MDTOP_PLLMIXED_PLL_SW_CTL0              (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x14))
#define REG_MDTOP_PLLMIXED_MDMCUPLL_CTL0            (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x40))
#define REG_MDTOP_PLLMIXED_MDVDSPPLL_CTL0           (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x48))
#define REG_MDTOP_PLLMIXED_MDBRPPLL_CTL0            (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x50))
#define REG_MDTOP_PLLMIXED_MDTXPLL_CTL0             (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x58))
#define REG_MDTOP_PLLMIXED_MDBPIPLL_CTL0            (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x60))
#define REG_MDTOP_PLLMIXED_MDBPIPLL_CTL1            (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x64))
#define REG_MDTOP_PLLMIXED_MDPLL_CTL0               (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x100))
#define REG_MDTOP_PLLMIXED_MDPLL_CTL1               (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x104))
#define REG_MDTOP_PLLMIXED_MDPLL_CTL2               (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x108))
#define REG_MDTOP_PLLMIXED_PLL_HP_RDY_IRQ           (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x314))
#define REG_MDTOP_PLLMIXED_PLL_HP_RDY_IRQ_MASK      (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0x318))
#define REG_MDTOP_PLLMIXED_MDMCUPLL_STS             (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0xC00))
#define REG_MDTOP_PLLMIXED_PLL_DUMMY                (PLL_TYPE(BASE_MADDR_MDTOP_PLLMIXED+0xF00))

#define REG_MDTOP_CLKSW_CLKON_CTL                   (PLL_TYPE(BASE_MADDR_MDTOP_CLKSW+0x20))
#define REG_MDTOP_CLKSW_CLKSEL_CTL                  (PLL_TYPE(BASE_MADDR_MDTOP_CLKSW+0x24))
#define REG_MDTOP_CLKSW_SDF_CK_CTL                  (PLL_TYPE(BASE_MADDR_MDTOP_CLKSW+0x28))
#define REG_MDTOP_CLKSW_MDSYS_BUS_FLEXCKGEN_STS     (PLL_TYPE(BASE_MADDR_MDTOP_CLKSW+0x84))

#define MD_PLL_MAGIC_NUM 0x62930000

#define APMIXED_BASE        (BASE_MADDR_APMIXEDSYS)
#define AP_PLL_CON0         (0x0)
#define AP_PLL_CON1         (0x4)
#define MDPLL_CON0          (0x3A0)
#define MDPLL_CON3          (0x3AC)

#define UINT32P         (volatile unsigned int *)

#define SLEEP_BASE         (0x10006000)
#define POWERON_CONFIG_EN  (UINT32P (SLEEP_BASE+0x0))
#define SPM_POWER_ON_VAL1  (UINT32P (SLEEP_BASE+0x8))

#define INFRACFG_AO_BASE    (0x10001000)
#define INFRA_TOPAXI_PROTECTEN_1_SET (0x2A8)
#define INFRA_TOPAXI_PROTECTEN_1_CLR (0x2AC)
#define INFRA_MISC2             (0xF0C)


//------- GPIO part ---------------------------------------
#define GPIO_MAGIC		(0x80000000)
#if 0 // no need sim setting
// -- SIM1
#define SIM1_SIO_GPIO_ID    (GPIO40 | GPIO_MAGIC)
#define SIM1_SRST_GPIO_ID   (GPIO39 | GPIO_MAGIC)
#define SIM1_SCLK_GPIO_ID   (GPIO38 | GPIO_MAGIC)
//#define SIM1_HOT_PLUG_GPIO_ID   (GPIO38 | GPIO_MAGIC)
// -- SIM2
#define SIM2_SIO_GPIO_ID    (GPIO35 | GPIO_MAGIC)
#define SIM2_SRST_GPIO_ID   (GPIO36 | GPIO_MAGIC)
#define SIM2_SCLK_GPIO_ID   (GPIO37 | GPIO_MAGIC)
//#define SIM2_HOT_PLUG_GPIO_ID   (GPIO39 | GPIO_MAGIC)
#endif
// -- UART
#define NO_NEED_UART_CONFIG
#ifndef NO_NEED_UART_CONFIG
#define UART1_TX_GPIO_ID (GPIO20 | GPIO_MAGIC)
#define UART1_RX_GPIO_ID (GPIO21 | GPIO_MAGIC)
#define UART2_TX_GPIO_ID (GPIO21 | GPIO_MAGIC)
#define UART2_RX_GPIO_ID (GPIO20 | GPIO_MAGIC)
#define UART3_TX_GPIO_ID (GPIO27 | GPIO_MAGIC)
#define UART3_RX_GPIO_ID (GPIO28 | GPIO_MAGIC)
#define UART4_TX_GPIO_ID (GPIO28 | GPIO_MAGIC)
#define UART4_RX_GPIO_ID (GPIO27 | GPIO_MAGIC)
#endif

//------- code part ---------------------------------------
static unsigned int img_load_flag = 0;
#if 0 // no need sim setting
static void md_gpio_get(GPIO_PIN pin, char *tag);
static void md_gpio_set(GPIO_PIN pin, GPIO_MODE mode, GPIO_DIR dir, GPIO_OUT out, GPIO_PULL_EN pull_en, GPIO_PULL pull, GPIO_SMT smt);
#endif

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

#if 0 // no need sim setting
static void md_gpio_config(unsigned int boot_mode_case)
{
	switch (boot_mode_case) {
		case MD1_ONLY:
#if 1 // same as dws initial setting
			//SIM1=> MD1 SIM1IF
			mt_set_gpio_mode(SIM1_SCLK_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM1_SRST_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM1_SIO_GPIO_ID, GPIO_MODE_01);
			//mt_set_gpio_mode(SIM1_HOT_PLUG_GPIO_ID, GPIO_MODE_01);
			//SIM2=> MD1 SIM2IF
			mt_set_gpio_mode(SIM2_SCLK_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM2_SRST_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM2_SIO_GPIO_ID, GPIO_MODE_01);
			//mt_set_gpio_mode(SIM2_HOT_PLUG_GPIO_ID, GPIO_MODE_01);
#endif
			break;
		default:
			break;
	}

	md_gpio_get(SIM1_SCLK_GPIO_ID, "sclk");
	md_gpio_get(SIM1_SRST_GPIO_ID, "srst");
	md_gpio_get(SIM1_SIO_GPIO_ID, "sio");
	//md_gpio_get(SIM1_HOT_PLUG_GPIO_ID, "hp");
	md_gpio_get(SIM2_SCLK_GPIO_ID, "sclk2");
	md_gpio_get(SIM2_SRST_GPIO_ID, "srst2");
	md_gpio_get(SIM2_SIO_GPIO_ID, "sio2");
	//md_gpio_get(SIM2_HOT_PLUG_GPIO_ID, "hp2");
}
#endif
#endif	//#ifndef CTP_ENV
#if 0 // no need sim setting
static void md_gpio_get(GPIO_PIN pin, char *tag)
{
	pin |= GPIO_MAGIC;
	dprintf(CRITICAL, "GPIO(0x%X)(%s): mode=%d,dir=%d,in=%d,out=%d,pull_en=%d,pull_sel=%d,smt=%d\n",
	        pin, tag,
	        mt_get_gpio_mode(pin),
	        mt_get_gpio_dir(pin),
	        mt_get_gpio_in(pin),
	        mt_get_gpio_out(pin),
	        mt_get_gpio_pull_enable(pin),
	        mt_get_gpio_pull_select(pin),
	        mt_get_gpio_smt(pin));
}

static void md_gpio_set(GPIO_PIN pin, GPIO_MODE mode, GPIO_DIR dir, GPIO_OUT out, GPIO_PULL_EN pull_en, GPIO_PULL pull, GPIO_SMT smt)
{
	pin |= GPIO_MAGIC;
	mt_set_gpio_mode(pin, mode);
	if (dir != GPIO_DIR_UNSUPPORTED)
		mt_set_gpio_dir(pin, dir);

	if (dir == GPIO_DIR_OUT) {
		mt_set_gpio_out(pin, out);
	}
	if (dir == GPIO_DIR_IN) {
		mt_set_gpio_smt(pin, smt);
	}
	if (pull_en != GPIO_PULL_EN_UNSUPPORTED) {
		mt_set_gpio_pull_enable(pin, pull_en);
		mt_set_gpio_pull_select(pin, pull);
	}
	md_gpio_get(pin, "-");
}
#endif

void md_uart_config(int type_id, int boot_mode)
{
#ifndef NO_NEED_UART_CONFIG
	switch (type_id) {
		case AP_ONLY: // for AP only
			dprintf(CRITICAL, "md_uart_config:%d, UART1->AP_0, UART2->N/A, UART3->MD1_0, UART4->N/A\n", type_id);
			// same as dws initial setting
				mt_set_gpio_mode(UART1_TX_GPIO_ID, GPIO_MODE_01);
				mt_set_gpio_mode(UART1_RX_GPIO_ID, GPIO_MODE_01);
				mt_set_gpio_mode(UART3_TX_GPIO_ID, GPIO_MODE_06);
				mt_set_gpio_mode(UART3_RX_GPIO_ID, GPIO_MODE_06);
			break;
		case MD1_ONLY: // for AP & MD1
		case MD2_ONLY: // for AP & C2K
		case MD1_MD2: // for both MD1 and C2K
			if (boot_mode) {
				dprintf(CRITICAL, "md_uart_config:%d, UART3->MD1_0, UART1->AP_0, UART2->NA/A, UART4->N/A\n", type_id);
				mt_set_gpio_mode(UART1_TX_GPIO_ID, GPIO_MODE_01);
				mt_set_gpio_mode(UART1_RX_GPIO_ID, GPIO_MODE_01);
				mt_set_gpio_mode(UART3_TX_GPIO_ID, GPIO_MODE_06);
				mt_set_gpio_mode(UART3_RX_GPIO_ID, GPIO_MODE_06);

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

#define INFRA_AO_BASE_LOCAL	0x10001000
#define INFRA_AP2MD_DUMMY_REG	0x370
#define INFRA_AP2MD_DUMMY_BIT	0

#define	INFRA_MD2PERI_PROT_EN	0x250
#define	INFRA_MD2PERI_PROT_RDY	0x258
#define	INFRA_MD2PERI_PROT_BIT	6

#define	INFRA_PERI2MD_PROT_EN	0x220
#define	INFRA_PERI2MD_PROT_RDY	0x228
#define	INFRA_PERI2MD_PROT_BIT	7

static void md1_pre_access_md_reg(void)
{
	unsigned int reg_val;
	unsigned int infra_ao_base = INFRA_AO_BASE_LOCAL;

	/*clear dummy reg flag to access modem reg*/
	reg_val = ccci_read32(infra_ao_base, INFRA_AP2MD_DUMMY_REG);
	reg_val &= (~(0x1 << INFRA_AP2MD_DUMMY_BIT));
	ccci_write32(infra_ao_base, INFRA_AP2MD_DUMMY_REG, reg_val);

	dprintf(CRITICAL, "pre: ap2md dummy reg 0x%X: 0x%X\n", INFRA_AO_BASE_LOCAL + INFRA_AP2MD_DUMMY_REG,
		ccci_read32(infra_ao_base, INFRA_AP2MD_DUMMY_REG));

	/*disable MD to AP*/
	reg_val = ccci_read32(infra_ao_base, INFRA_MD2PERI_PROT_EN);
	reg_val |= (0x1 << INFRA_MD2PERI_PROT_BIT);
	ccci_write32(infra_ao_base, INFRA_MD2PERI_PROT_EN, reg_val);
	while ((ccci_read32(infra_ao_base, INFRA_MD2PERI_PROT_RDY) & (0x1 << INFRA_MD2PERI_PROT_BIT))
			!= (0x1 << INFRA_MD2PERI_PROT_BIT))
		;
	dprintf(CRITICAL, "md2peri: en[0x%X], rdy[0x%X]\n",
		ccci_read32(infra_ao_base, INFRA_MD2PERI_PROT_EN),
		ccci_read32(infra_ao_base, INFRA_MD2PERI_PROT_RDY));
}

static void md1_post_access_md_reg(void)
{
	unsigned int reg_val;
	unsigned int infra_ao_base = INFRA_AO_BASE_LOCAL;

	/*disable AP to MD*/
	reg_val = ccci_read32(infra_ao_base, INFRA_PERI2MD_PROT_EN);
	reg_val |= (0x1 << INFRA_PERI2MD_PROT_BIT);
	ccci_write32(infra_ao_base, INFRA_PERI2MD_PROT_EN, reg_val);

	while ((ccci_read32(infra_ao_base, INFRA_PERI2MD_PROT_RDY) & (0x1 << INFRA_PERI2MD_PROT_BIT))
			!= (0x1 << INFRA_PERI2MD_PROT_BIT))
		;
	dprintf(CRITICAL, "peri2md: en[0x%X], rdy[0x%X]\n",
		ccci_read32(infra_ao_base, INFRA_PERI2MD_PROT_EN),
		ccci_read32(infra_ao_base, INFRA_PERI2MD_PROT_RDY));

	/*enable MD to AP*/
	reg_val = ccci_read32(infra_ao_base, INFRA_MD2PERI_PROT_EN);
	reg_val &= (~(0x1 << INFRA_MD2PERI_PROT_BIT));
	ccci_write32(infra_ao_base, INFRA_MD2PERI_PROT_EN, reg_val);

	while ((ccci_read32(infra_ao_base, INFRA_MD2PERI_PROT_RDY) & (0x1 << INFRA_MD2PERI_PROT_BIT)))
		;
	dprintf(CRITICAL, "md2peri: en[0x%X], rdy[0x%X]\n",
		ccci_read32(infra_ao_base, INFRA_MD2PERI_PROT_EN),
		ccci_read32(infra_ao_base, INFRA_MD2PERI_PROT_RDY));

	/*set dummy reg flag and let md access AP*/
	reg_val = ccci_read32(infra_ao_base, INFRA_AP2MD_DUMMY_REG);
	reg_val |= (0x1 << INFRA_AP2MD_DUMMY_BIT);
	ccci_write32(infra_ao_base, INFRA_AP2MD_DUMMY_REG, reg_val);
	dprintf(CRITICAL, "post: ap2md dummy reg 0x%X: 0x%X\n", INFRA_AO_BASE_LOCAL + INFRA_AP2MD_DUMMY_REG,
		ccci_read32(infra_ao_base, INFRA_AP2MD_DUMMY_REG));
}

void pmic_init_sequence(void)
{
	dprintf(CRITICAL, "pmic_init_sequence skipped!\n");
}

static void md1_pmic_setting(void)
{
#ifndef CTP_ENV
	dprintf(CRITICAL, "md1_pmic_setting start!\n");
	vmd1_pmic_setting_on();
	dprintf(CRITICAL, "md1_pmic_setting done!\n");
#else
	// assume set in preloader
	dprintf(CRITICAL, "md1_pmic_setting skipped!\n");
#endif
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

	// clear MSDC0 interrupt as it's also connected to MD side
	//ccci_write32(0x1124000C, 0, 0xFFFFFFFF);

	pmic_init_sequence();

	return 0;
}

void md_common_pll_init(void)
{
	// initial CLKSQ_LPF
	ccci_write32(APMIXED_BASE, AP_PLL_CON0, ccci_read32(APMIXED_BASE, AP_PLL_CON0) | (0x1 << 1));
	udelay(100);
}

void md1_pll_init(void)
{
	md_common_pll_init();

	dprintf(CRITICAL, "Read MD PLL version:0x%x(@0x%x)\n", *REG_MDTOP_PLLMIXED_PLL_VERSION, (unsigned int)REG_MDTOP_PLLMIXED_PLL_VERSION);

	// Default md_srclkena_ack settle time = 136T 32K
	//*REG_MDTOP_PLLMIXED_DCXO_PLL_SETTLE_CTL = 0x02020E88;

	*REG_MDTOP_PLLMIXED_MDBPIPLL_CTL0  = 0x80118000; // fixed 606MHz(/4), 260MHz(/7)         /* Fvco = 1820M */
	*REG_MDTOP_PLLMIXED_MDTXPLL_CTL0   = 0x800B8A00; // 300MHz                               /* Fvco = 1200M */
	*REG_MDTOP_PLLMIXED_MDBRPPLL_CTL0  = 0x80114E00; // 300MHz                               /* Fvco = 1800M */
	*REG_MDTOP_PLLMIXED_MDVDSPPLL_CTL0 = 0x80114E00; // 450MHz                               /* Fvco = 1800M */
	*REG_MDTOP_PLLMIXED_MDMCUPLL_CTL0  = 0x800B8A00; // 600MHz                               /* Fvco = 1200M */

	/*
	* Polling until MDMCUPLL complete frequency adjustment
	* Once MDMCUPLL complete, other PLL should complete too
	*/
	while ((*REG_MDTOP_PLLMIXED_MDMCUPLL_STS >> 14) & 0x1) {};

	//In L17, MDPLL should be turn-on first manually, since first calabration requires longer time (100us).
	 /*TINFO="MDSYS_INIT: MDPLL_208M_OUT_EN off"*/
	*REG_MDTOP_PLLMIXED_MDPLL_CTL2 &= ~(0x10000);
	/*TINFO="MDSYS_INIT: SW Force ON MDPLL"*/
	*REG_MDTOP_PLLMIXED_PLL_SW_CTL0 = 0x10000;
	*REG_MDTOP_PLLMIXED_PLL_SW_CTL0 = 0x10001;
	/*TINFO="MDSYS_INIT: Wait at least 100us"*/
	udelay(100);//Wait 100 us

	/*TINFO="MDSYS_INIT: SW Force OFF MDPLL"*/
	*REG_MDTOP_PLLMIXED_PLL_SW_CTL0 = 0x10000;
	*REG_MDTOP_PLLMIXED_PLL_SW_CTL0 = 0x0;
	/*TINFO="MDSYS_INIT: MDPLL_208M_OUT_EN on"*/
	*REG_MDTOP_PLLMIXED_MDPLL_CTL2 |=  0x10000;
	/*TINFO="MDSYS_INIT: Wait 1us"*/
	udelay(1);//Wait 1 us

	/*TINFO="MDSYS_INIT: Disable AUTOK_EN, MDPLL settle time is 20us NOW (AUTOK_EN can only be setting when MDPLL_EN is OFF, so we add 1us to avoid signals competition)"*/
	*REG_MDTOP_PLLMIXED_MDPLL_CTL1 &= ~(0x4000000);
	/*TINFO="MDSYS_INIT: Wait 1us"*/
	udelay(1);//Wait 1 us

	/* Force TXPLL ON due to TOPSM couldn't enable this PLL by default, TXPLL would be disable after DVFS Init.
	other PLL ON controlled by HW" */
	*REG_MDTOP_PLLMIXED_PLL_ON_CTL = 0x100010;

	/*
	* Wait MD bus clock ready
	* Once MD bus ready, other clock should be ready too
	* In FPGA, the following status checking must be removed since there is no flex ck gen in FPGA.
	*/
	while ((*REG_MDTOP_CLKSW_MDSYS_BUS_FLEXCKGEN_STS & 0x8000) != 0x8000) {};

	// Switch MDMCU & MD BUS clock to PLL frequency
	*REG_MDTOP_CLKSW_CLKSEL_CTL |= 0x3;

	// Switch all clock to PLL frequency
	*REG_MDTOP_CLKSW_CLKSEL_CTL |= 0x58103FC;

	// Switch SDF clock to PLL frequency
	*REG_MDTOP_CLKSW_SDF_CK_CTL |= 0x10;

	// Turn off all SW clock request, except ATB
	*REG_MDTOP_CLKSW_CLKON_CTL = 0x1;

	// Clear PLL ADJ RDY IRQ fired by initial period adjustment
	*REG_MDTOP_PLLMIXED_PLL_HP_RDY_IRQ = 0xFFFF;

	// Mask all PLL ADJ RDY IRQ
	*REG_MDTOP_PLLMIXED_PLL_HP_RDY_IRQ_MASK = 0xFFFF;

	// Make a record that means MD pll has been initialized.
	/* Note: We use "MD_PLL_MAGIC_NUM|0x1" to know PLL init in MD C code.
		If AP init PLL, it would be "MD_PLL_MAGIC_NUM". */
	*REG_MDTOP_PLLMIXED_PLL_DUMMY = (MD_PLL_MAGIC_NUM);

	dprintf(CRITICAL, "md1_pll_init done!\n");
}

#define INFRA_AO_TOP_CLK_GEN	0x10000000
#define MD_CLK_GATING_UNGATE  (0)

void md1_boot(int boot_mode)
{
	unsigned int reg_value;

	//Clear BIT8 and BIT9 to ungate MD1 32K and 26M
	reg_value = ccci_read32(INFRA_AO_TOP_CLK_GEN, MD_CLK_GATING_UNGATE);
	reg_value &= ~(0x300);
	ccci_write32(INFRA_AO_TOP_CLK_GEN, MD_CLK_GATING_UNGATE, reg_value);

	// step 1: configure modem related buck
	md1_pmic_setting();

	dprintf(CRITICAL, "Spare3 0x11f1004c val:0x%x\n", *((volatile unsigned int*)0x11f1004c) );

	// step 2: Power on MTCMOS
	spm_mtcmos_ctrl_md1(STA_POWER_ON);
	dprintf(CRITICAL, "MD1 MTCMOS power on done!\n");
	md1_pre_access_md_reg();

	// step 5: configure md_srclkena setting
	// INFRA_MISC2 already finished in md_common_setting()
	// SRCLKEN_O1 force on
	spm_write(POWERON_CONFIG_EN, 0x0B160001);
	spm_write(SPM_POWER_ON_VAL1, 0x00215830);
	dprintf(CRITICAL, "md_srclkena done!\n");

	// step 6: configure PLL setting
	md1_pll_init();

	// step 7: disabel MD WDT
#if !defined(ENABLE_MD_RESET_SPM) && !defined(ENABLE_MD_RESET_RGU)
	ccci_write32(MD_RGU_BASE, WDT_MD_MODE, WDT_MD_MODE_KEY); // disable MD WDT & MD AUX_WDT
#endif

	// step+: set META Register
	if (boot_mode) {
		reg_value = DRV_Reg32(MD1_META_FLAG);
		DRV_WriteReg32(MD1_META_FLAG, (reg_value | 0x1));
	}

}

static void config_md_boot_env(int md_id, int boot_mode)
{
	switch (md_id) {
		case MD_SYS1:
			md1_boot(boot_mode);
			break;
		default:
			break;
	}
}

static void let_md_go(int md_id)
{
	switch (md_id) {
		case MD_SYS1:
			/* step 8: trigger modem SW to run */
#ifndef NO_UNGATE_MD
			ccci_write32(MD1_BOOT_VECTOR_EN, 0, 1);
			md1_post_access_md_reg();
#else
			md1_post_access_md_reg();
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
		/* gating md related clock */
		reg_value = ccci_read32(INFRA_AO_TOP_CLK_GEN, MD_CLK_GATING_UNGATE);
		reg_value |= (0x300);
		ccci_write32(INFRA_AO_TOP_CLK_GEN, MD_CLK_GATING_UNGATE, reg_value);
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

void dummy_ap_boot_up_md(int md_ld_flag)
{
	int boot_mode = 0;
	int i;
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
#if 0 // no need sim setting
	// 1, Setup special GPIO request (RF/SIM/UART ... etc)
	dprintf(CRITICAL, "Configure GPIO!\n");
	if ((img_load_flag&((1 << MD_SYS1) | (1 << MD_SYS3))) == ((1 << MD_SYS1) | (1 << MD_SYS3))) {
		md_gpio_config(MD1_MD2);
	} else if (img_load_flag & (1 << MD_SYS1)) {
		md_gpio_config(MD1_ONLY);
	} else if (img_load_flag & (1 << MD_SYS3)) {
		md_gpio_config(MD2_ONLY);
	}
#endif
	// 2, Check boot Mode
	boot_mode = meta_detection();

	dprintf(CRITICAL, "Get boot mode is %d\n", boot_mode);

	// 3, MD WDT ISR init
	dprintf(CRITICAL, "Init MD WDT\n");
	md_wdt_init();
#endif

	// 4. Common setting for all MD
	md_common_setting();

	// 5. Setup per-MD env before boot up MD
	for (i=0; i<3; i++) {
		if (img_load_flag & (1 << i)) {
			dprintf(CRITICAL, "MD%d Enabled\n", i+1);
			config_md_boot_env(i, boot_mode);
		}
	}

	// 6. Switch UART
	dprintf(CRITICAL, "Switch UART!\n");
	if ((img_load_flag&((1 << MD_SYS1) | (1 << MD_SYS3))) == ((1 << MD_SYS1) | (1 << MD_SYS3))) {
		md_uart_config(MD1_MD2, boot_mode);
	} else if (img_load_flag & (1 << MD_SYS1)) {
		md_uart_config(MD1_ONLY, boot_mode);
	} else if (img_load_flag & (1 << MD_SYS3)) {
		md_uart_config(MD2_ONLY, boot_mode);
	}

	for (i=0; i<3; i++) {
		if (img_load_flag & (1 << i)) {
			dprintf(CRITICAL, "Trigger MD%d run\n", i+1);
			let_md_go(i);
		}
	}

	//spm_mtcmos_ctrl_audio(STA_POWER_ON);
	//dprintf(CRITICAL, "turn on audio.\n");
#ifndef CTP_ENV
	dprintf(CRITICAL, "enter while(1), ^O^!!!!!!!!!\n");
	while (1);
#endif
}
