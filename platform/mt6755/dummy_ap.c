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
#include <platform/pmic_wrap_init.h>

//=====================================================================
// Feature option switch part
//=====================================================================
#define THIS_IS_EVB
#define BOTH_MD_ON
//#define DEFAULT_META
//#define ENABLE_MD_RESET_SPM
//#define ENABLE_MD_RESET_RGU
#define IGNORE_MD_WDT
//#define IGNORE_MD1_WDT
//#define IGNORE_MD2_WDT
//#define ALWAYS_META
#define AP_MD_SAME_UART

#ifdef ENABLE_MD_RESET_SPM
#include <platform/spm.h>
#endif


enum {
	MD_SYS1 = 0,
	MD_SYS2,
	MD_SYS3,
	MD_SYS4,
};

//------- IRQ ID part ---------------------------------------
#define GIC_PRIVATE_SIGNALS (32)
#define MT_MD_WDT1_IRQ_ID   (223+GIC_PRIVATE_SIGNALS)
#define MT_MD_WDT2_IRQ_ID   (220+GIC_PRIVATE_SIGNALS)

// C2K_CONFIG (0x10001360)
#define  AP_C2K_CONFIG (0x10001360)

// AP RGU
#define TOP_RGU_WDT_MODE (TOPRGU_BASE+0x0)
#define TOP_RGU_WDT_SWRST (TOPRGU_BASE+0x14)
#define TOP_RGU_WDT_SWSYSRST (TOPRGU_BASE+0x18)
#define TOP_RGU_WDT_NONRST_REG (TOPRGU_BASE+0x20)

// MD RGU PCore
#define MD_WDT_BASE (0x200F0000)  // P Core 0x55000000
#define MD_WDT_STA  (MD_WDT_BASE+0x0C)

// MD RGU L1 Core
#define MD_L1WDT_BASE (0x26010000) //2200//L Core

#define PLL_TYPE    (volatile unsigned int *)

#define MD_CLKSW_BASE           (0x20150000)
#define MD_GLOBAL_CON_DCM_BASE      (0x20130000)
#define PSMCU_MISC_BASE         (0x20200000)
#define MD_PERI_MISC_BASE       (0x20060000)
#define MDL1A0_BASE         (0x260F0000)
#define BASE_ADDR_MDTOP_PLLMIXED    (0x20140000)
#define BASE_ADDR_MDSYS_CLKCTL      (0x20120000)
#define L1_BASE_MADDR_MDL1_CONF     (0x260F0000)

#define R_CLKSEL_CTL            (PLL_TYPE(MD_CLKSW_BASE+0x0024))
#define R_FLEXCKGEN_SEL0        (PLL_TYPE(MD_CLKSW_BASE+0x0028))
#define R_FLEXCKGEN_SEL1        (PLL_TYPE(MD_CLKSW_BASE+0x002C))
#define R_FLEXCKGEN_SEL2        (PLL_TYPE(MD_CLKSW_BASE+0x0044))

#define R_PLL_STS           (PLL_TYPE(MD_CLKSW_BASE+0x0040))

#define R_FLEXCKGEN_STS0        (PLL_TYPE(MD_CLKSW_BASE+0x0030))
#define R_FLEXCKGEN_STS1        (PLL_TYPE(MD_CLKSW_BASE+0x0034))
#define R_FLEXCKGEN_STS2        (PLL_TYPE(MD_CLKSW_BASE+0x0048))

/*PSMCU DCM*/
#define R_PSMCU_DCM_CTL0        (PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x0010))
#define R_PSMCU_DCM_CTL1        (PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x0014))

#define R_ARM7_DCM_CTL0         (PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x0020))
#define R_ARM7_DCM_CTL1         (PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x0024))
#define MD_GLOBAL_CON_DUMMY     (PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x1000))
#define MD_PLL_MAGIC_NUM        (0x67550000)

#define R_DCM_SHR_SET_CTL       (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x0004))
#define R_LTEL2_BUS_DCM_CTL     (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x0010))
#define R_MDDMA_BUS_DCM_CTL     (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x0014))
#define R_MDREG_BUS_DCM_CTL     (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x0018))
#define R_MODULE_BUS2X_DCM_CTL      (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x001C))
#define R_MODULE_BUS1X_DCM_CTL      (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x0020))
#define R_MDINFRA_CKEN          (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x0044))
#define R_MDPERI_CKEN           (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x0048))
#define R_MDPERI_DCM_MASK       (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x0064))

#define R_PSMCU_AO_CLK_CTL      (PLL_TYPE(BASE_ADDR_MDSYS_CLKCTL+0x00C0))

#define R_L1_PMS            (PLL_TYPE(MD_PERI_MISC_BASE+0x00C4))


#define REG_DCM_PLLCK_SEL       (PLL_TYPE(MDL1A0_BASE+0x0188))
#define R_L1MCU_PWR_AWARE       (PLL_TYPE(MDL1A0_BASE+0x0190))
#define R_L1AO_PWR_AWARE        (PLL_TYPE(MDL1A0_BASE+0x0194))
#define R_BUSL2DCM_CON3         (PLL_TYPE(MDL1A0_BASE+0x0198))
#define R_L1MCU_DCM_CON2        (PLL_TYPE(MDL1A0_BASE+0x0184))
#define R_L1MCU_DCM_CON         (PLL_TYPE(MDL1A0_BASE+0x0180))

// C2K boot
#define UINT32P         (volatile unsigned int *)
#define SLEEP_BASE      (0x10006000)
#define APMIXED_BASE        (0x1000C000)
#define TOPRGU_BASE     (0x10007000)
#define INFRACFG_AO_BASE    (0x10001000)
#define C2KSYS_BASE     (0x38000000)
#define C2K_CGBR1                (UINT32P (C2KSYS_BASE+0x0200B004))
#define WDT_SWSYSRST             (UINT32P (TOPRGU_BASE+0x018))
#define INFRA_TOPAXI_PROTECTEN_1 (UINT32P (INFRACFG_AO_BASE+0x250))
#define C2K_SPM_CTRL             (UINT32P (INFRACFG_AO_BASE+0x368))
#define C2K_STATUS               (UINT32P (INFRACFG_AO_BASE+0x364))
#define POWERON_CONFIG_EN        (UINT32P (SLEEP_BASE+0x000))
#define C2K_PWR_CON              (UINT32P (SLEEP_BASE+0x328))
#define PWR_STATUS               (UINT32P (SLEEP_BASE+0x180))
#define PWR_STATUS_2ND           (UINT32P (SLEEP_BASE+0x184))
#define INFRA_MISC2     (UINT32P (INFRACFG_AO_BASE+0xF0C))
#define AP_PLL_CON0     (UINT32P (APMIXED_BASE+0x0))
#define PWR_RST_B     0
#define PWR_ISO       1
#define PWR_ON        2
#define PWR_ON_2ND    3
#define PWR_CLK_DIS   4
#define C2K          28

#define C2K_MAGIC_NUM 0xC275
#define INFRACFG_AO_BASE (0x10001000)
#define UINT16P      volatile unsigned short *
#define UINT32P      (volatile unsigned int *)
#define C2KSYS_BASE (0x38000000)
#define C2K_SBC_KEY0    (UINT32P(INFRACFG_AO_BASE+0x8B0))
#define C2K_SBC_KEY1    (UINT32P(INFRACFG_AO_BASE+0x8B4))
#define C2K_SBC_KEY2    (UINT32P(INFRACFG_AO_BASE+0x8B8))
#define C2K_SBC_KEY3    (UINT32P(INFRACFG_AO_BASE+0x8BC))
#define C2K_SBC_KEY4    (UINT32P(INFRACFG_AO_BASE+0x8C0))
#define C2K_SBC_KEY5    (UINT32P(INFRACFG_AO_BASE+0x8C4))
#define C2K_SBC_KEY6    (UINT32P(INFRACFG_AO_BASE+0x8C8))
#define C2K_SBC_KEY7    (UINT32P(INFRACFG_AO_BASE+0x8CC))
#define C2K_SBC_KEY_LOCK        (UINT32P(INFRACFG_AO_BASE+0x8D0))
#define C2K_CONFIG      (UINT32P(INFRACFG_AO_BASE+0x360))
#define C2K_C2K_PLL_CON3        (UINT32P(C2KSYS_BASE+0x02013008))
#define C2K_C2K_PLL_CON2        (UINT32P(C2KSYS_BASE+0x02013004))
#define C2K_C2K_PLLTD_CON0      (UINT32P(C2KSYS_BASE+0x02013074))
#define C2K_CLK_CTRL9   (UINT32P(C2KSYS_BASE+0x0200029C))
#define C2K_CLK_CTRL4   (UINT32P(C2KSYS_BASE+0x02000010))
#define C2K_CG_ARM_AMBA_CLKSEL  (UINT32P(C2KSYS_BASE+0x02000234))
#define C2K_C2K_C2KPLL1_CON0    (UINT32P(C2KSYS_BASE+0x02013018))
#define C2K_C2K_CPPLL_CON0      (UINT32P(C2KSYS_BASE+0x02013040))
#define C2K_C2K_DSPPLL_CON0     (UINT32P(C2KSYS_BASE+0x02013050))
#define C2K 28

#define MDPLL1_CON0              (UINT32P (APMIXED_BASE+0x02C8))

// SIM GPIO setcion
// -- SIM1
#define SIM1_SIO_GPIO_ID    (41)
#define SIM1_SRST_GPIO_ID   (40)
#define SIM1_SCLK_GPIO_ID   (39)
#define SIM1_HOT_PLUG_GPIO_ID   (46)
// -- SIM2
#define SIM2_SIO_GPIO_ID    (36)
#define SIM2_SRST_GPIO_ID   (37)
#define SIM2_SCLK_GPIO_ID   (38)
#define SIM2_HOT_PLUG_GPIO_ID   (45)
// -- Connection


extern BOOT_ARGUMENT    *g_boot_arg;
static unsigned int img_load_flag = 0;


void pmic_init_sequence(void);
void md_uart_config(int md_id, int boot_mode);
void md1_pll_init(void);
void md1_pmic_setting(void);

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
	dprintf(ALWAYS, "Meta mode: %d, boot_mode: %d\n", boot_mode, g_boot_arg->boot_mode);
	return boot_mode;
}

static void md_gpio_get(GPIO_PIN pin, char *tag)
{
	dprintf(ALWAYS, "GPIO(%X)(%s): mode=%d,dir=%d,in=%d,out=%d,pull_en=%d,pull_sel=%d,smt=%d\n",
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

static void md_gpio_config(unsigned int boot_mode_case)
{
	// init sim1
	mt_set_gpio_dir(SIM1_SCLK_GPIO_ID, GPIO_DIR_OUT);
	mt_set_gpio_dir(SIM1_SRST_GPIO_ID, GPIO_DIR_OUT);
	mt_set_gpio_pull_enable(SIM1_SIO_GPIO_ID, GPIO_PULL_ENABLE);
	mt_set_gpio_pull_select(SIM1_SIO_GPIO_ID, GPIO_PULL_UP);
	mt_set_gpio_dir(SIM1_SIO_GPIO_ID, GPIO_DIR_IN);
	mt_set_gpio_pull_enable(SIM1_HOT_PLUG_GPIO_ID, GPIO_PULL_ENABLE);
	mt_set_gpio_pull_select(SIM1_HOT_PLUG_GPIO_ID, GPIO_PULL_UP);
	mt_set_gpio_dir(SIM1_HOT_PLUG_GPIO_ID, GPIO_DIR_IN);
	// init sim2
	mt_set_gpio_dir(SIM2_SCLK_GPIO_ID, GPIO_DIR_OUT);
	mt_set_gpio_dir(SIM2_SRST_GPIO_ID, GPIO_DIR_OUT);
	mt_set_gpio_pull_enable(SIM2_SIO_GPIO_ID, GPIO_PULL_ENABLE);
	mt_set_gpio_pull_select(SIM2_SIO_GPIO_ID, GPIO_PULL_UP);
	mt_set_gpio_dir(SIM2_SIO_GPIO_ID, GPIO_DIR_IN);
	mt_set_gpio_pull_enable(SIM2_HOT_PLUG_GPIO_ID, GPIO_PULL_ENABLE);
	mt_set_gpio_pull_select(SIM2_HOT_PLUG_GPIO_ID, GPIO_PULL_UP);
	mt_set_gpio_dir(SIM2_HOT_PLUG_GPIO_ID, GPIO_DIR_IN);

	//  md_gpio_set(GPIO96, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO39, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO40, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO41, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO38, GPIO_MODE_06, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO37, GPIO_MODE_06, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO36, GPIO_MODE_06, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO46, GPIO_MODE_01, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO45, GPIO_MODE_01, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);

	md_gpio_set(GPIO13, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO14, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO15, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO16, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);

	md_gpio_set(GPIO27, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO28, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO34, GPIO_MODE_06, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO30, GPIO_MODE_06, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO33, GPIO_MODE_06, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO32, GPIO_MODE_06, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO35, GPIO_MODE_06, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO31, GPIO_MODE_06, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO110, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO108, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO111, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO107, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO8, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO18, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ONE, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO17, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO25, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ONE, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO26, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO116, GPIO_MODE_00, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);

	md_gpio_set(GPIO82, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO81, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO80, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO79, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO62, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO61, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO60, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO59, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO58, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO57, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO56, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO55, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO54, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO53, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO52, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO51, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO90, GPIO_MODE_02, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO89, GPIO_MODE_02, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO88, GPIO_MODE_02, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO87, GPIO_MODE_02, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO86, GPIO_MODE_02, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO85, GPIO_MODE_02, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO84, GPIO_MODE_02, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO83, GPIO_MODE_02, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO159, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO160, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO69, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO68, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO67, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO66, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO65, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO64, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO63, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO78, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO77, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO76, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO75, GPIO_MODE_01, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);

//	md_gpio_set(GPIO51, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO52, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO53, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO54, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);

//	md_gpio_set(GPIO107, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO108, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO161, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO109, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO110, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO111, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO42, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO43, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO157, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO44, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO158, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);

//	md_gpio_set(GPIO17, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO18, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO19, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO20, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO21, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO22, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO23, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO24, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
//	md_gpio_set(GPIO25, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);

	switch (boot_mode_case) {
		case 0:
			//SIM1=> MD1 SIM1IF
			mt_set_gpio_mode(SIM1_SCLK_GPIO_ID, 1);
			mt_set_gpio_mode(SIM1_SRST_GPIO_ID, 1);
			mt_set_gpio_mode(SIM1_SIO_GPIO_ID, 1);
			mt_set_gpio_mode(SIM1_HOT_PLUG_GPIO_ID, 1);
			//SIM2=> MD1 SIM2IF
			mt_set_gpio_mode(SIM2_SCLK_GPIO_ID, 1);
			mt_set_gpio_mode(SIM2_SRST_GPIO_ID, 1);
			mt_set_gpio_mode(SIM2_SIO_GPIO_ID, 1);
			mt_set_gpio_mode(SIM2_HOT_PLUG_GPIO_ID, 1);
			break;
		case 1:
			//SIM1=> MD2 UIM0IF
			mt_set_gpio_mode(SIM1_SCLK_GPIO_ID, 5);
			mt_set_gpio_mode(SIM1_SRST_GPIO_ID, 5);
			mt_set_gpio_mode(SIM1_SIO_GPIO_ID, 5);
			mt_set_gpio_mode(SIM1_HOT_PLUG_GPIO_ID, 1);
			//SIM2=> MD2 UIM1IF
			mt_set_gpio_mode(SIM2_SCLK_GPIO_ID, 6);
			mt_set_gpio_mode(SIM2_SRST_GPIO_ID, 6);
			mt_set_gpio_mode(SIM2_SIO_GPIO_ID, 6);
			mt_set_gpio_mode(SIM2_HOT_PLUG_GPIO_ID, 1);
			break;
		case 2:
			//SIM1=> MD1 SIM1IF
			mt_set_gpio_mode(SIM1_SCLK_GPIO_ID, 1);
			mt_set_gpio_mode(SIM1_SRST_GPIO_ID, 1);
			mt_set_gpio_mode(SIM1_SIO_GPIO_ID, 1);
			mt_set_gpio_mode(SIM1_HOT_PLUG_GPIO_ID, 1);
			//SIM2=> MD2 UIM0IF
			mt_set_gpio_mode(SIM2_SCLK_GPIO_ID, 5);
			mt_set_gpio_mode(SIM2_SRST_GPIO_ID, 5);
			mt_set_gpio_mode(SIM2_SIO_GPIO_ID, 5);
			mt_set_gpio_mode(SIM2_HOT_PLUG_GPIO_ID, 1);
			break;
		default:
			break;
	}

	md_gpio_get(SIM1_SCLK_GPIO_ID, "sclk");
	md_gpio_get(SIM1_SRST_GPIO_ID, "srst");
	md_gpio_get(SIM1_SIO_GPIO_ID, "sio");
	md_gpio_get(SIM1_HOT_PLUG_GPIO_ID, "hp");
	md_gpio_get(SIM2_SCLK_GPIO_ID, "sclk2");
	md_gpio_get(SIM2_SRST_GPIO_ID, "srst2");
	md_gpio_get(SIM2_SIO_GPIO_ID, "sio2");
	md_gpio_get(SIM2_HOT_PLUG_GPIO_ID, "hp2");


}

static void md_power_up_mtcmos(unsigned int boot_md_id)
{
#ifdef ENABLE_MD_RESET_SPM
	switch (boot_md_id) {
		case MD_SYS1:
			spm_mtcmos_ctrl_mdsys1(STA_POWER_ON);
			break;

		case MD_SYS3
				spm_mtcmos_ctrl_mdsys2(STA_POWER_ON);
			break;
		default:
			break;
	}
#endif
}

static void c2k_boot(int boot_mode);

void md_uart_config(int type_id, int boot_mode)
{
	switch (type_id) {
		case -1: // for AP only
			dprintf(ALWAYS, "md_uart_config:%d, UART1->[AP], UART2->AP, UART3->XXX, UART4->C2K\n", type_id);
			mt_set_gpio_mode(105, 1); //URXD0 / MD_URXD0
			mt_set_gpio_mode(106, 1); //UTXD0 / MD_UTXD0
			mt_set_gpio_mode(19, 2); //URXD1
			mt_set_gpio_mode(20, 2); //UTXD1
			//mt_set_gpio_mode(13, 4); //C2K_URXD0
			//mt_set_gpio_mode(14, 4); //C2K_UTXD0
			//mt_set_gpio_mode(17, 5); //C2K_URXD0
			//mt_set_gpio_mode(18, 5); //C2K_UTXD0
			break;
		case 0: // for AP & MD1
		case 1: // for AP & MD2201
			if (boot_mode==0) { // Normal boot
				dprintf(ALWAYS, "[Normal]md_uart_config:%d, UART1->[MD1], UART2->AP, UART3->XXX, UART4->C2K\n", type_id);
#ifdef AP_MD_SAME_UART
				mt_set_gpio_mode(105, 1);//3); //URXD0 / MD_URXD0
				mt_set_gpio_mode(106, 1);//3); //UTXD0 / MD_UTXD0
				mt_set_gpio_mode(13, 0); //URXD0 / MD_URXD0
				mt_set_gpio_mode(14, 0); //UTXD0 / MD_UTXD0
#else
				mt_set_gpio_mode(105, 1); //URXD0 / MD_URXD0
				mt_set_gpio_mode(106, 1); //UTXD0 / MD_UTXD0
				mt_set_gpio_mode(13, 4); //URXD0 / MD_URXD0
				mt_set_gpio_mode(14, 4); //UTXD0 / MD_UTXD0
#endif
				//mt_set_gpio_mode(105, 1); //URXD0 / MD_URXD0
				//mt_set_gpio_mode(106, 1); //UTXD0 / MD_UTXD0
				mt_set_gpio_mode(19, 2); //URXD1
				mt_set_gpio_mode(20, 2); //UTXD1
				//mt_set_gpio_mode(13, 4); //C2K_URXD0
				//mt_set_gpio_mode(14, 4); //C2K_UTXD0
				//mt_set_gpio_mode(17, 5); //C2K_URXD0
				//mt_set_gpio_mode(18, 5); //C2K_UTXD0
			} else {
				dprintf(ALWAYS, "[Meta]md_uart_config:%d, UART1->[MD1], UART2->AP, UART3->XXX, UART4->C2K\n", type_id);
				mt_set_gpio_mode(105, 3); //URXD0 / MD_URXD0
				mt_set_gpio_mode(106, 3); //UTXD0 / MD_UTXD0
				mt_set_gpio_mode(13, 0); //URXD0 / MD_URXD0
				mt_set_gpio_mode(14, 0); //UTXD0 / MD_UTXD0
				//mt_set_gpio_mode(105, 1); //URXD0 / MD_URXD0
				//mt_set_gpio_mode(106, 1); //UTXD0 / MD_UTXD0
				mt_set_gpio_mode(19, 2); //URXD1
				mt_set_gpio_mode(20, 2); //UTXD1
				//mt_set_gpio_mode(13, 4); //C2K_URXD0
				//mt_set_gpio_mode(14, 4); //C2K_UTXD0
				//mt_set_gpio_mode(17, 5); //C2K_URXD0
				//mt_set_gpio_mode(18, 5); //C2K_UTXD0
			}
			break;
		case 2: // for both MD1 and MD2
			dprintf(ALWAYS, "md_uart_config:%d, UART1->[MD1], UART2->AP, UART3->XXX, UART4->C2K\n", type_id);
			mt_set_gpio_mode(105, 3); //URXD0 / MD_URXD0
			mt_set_gpio_mode(106, 3); //UTXD0 / MD_UTXD0
			mt_set_gpio_mode(13, 0); //MD_URXD0 ==> MD1
			mt_set_gpio_mode(14, 0); //MD_UTXD0 ==> MD1
			mt_set_gpio_mode(19, 2); //URXD1
			mt_set_gpio_mode(20, 2); //UTXD1
		//mt_set_gpio_mode(13, 4); //C2K_URXD0
		//mt_set_gpio_mode(14, 4); //C2K_UTXD0
		//mt_set_gpio_mode(17, 5); //C2K_URXD0
		//mt_set_gpio_mode(18, 5); //C2K_UTXD0
		default:
			break;
	}
}

static void let_md_go(int md_id)
{
	unsigned int reg_val;
	switch (md_id) {
		case MD_SYS1:
			// Trigger MD run
			DRV_WriteReg32(0x20000024, 1);
			break;
		case MD_SYS3:
			DRV_WriteReg32(AP_C2K_CONFIG, DRV_Reg32(AP_C2K_CONFIG)|(1<<3));
			/* AP release C2K ARM core to let C2K go */
			reg_val = DRV_Reg32(C2K_CONFIG);
			reg_val &= ~(0x1 << 1);
			DRV_WriteReg32(C2K_CONFIG, reg_val);
			break;
		default:
			break;
	}
}


int md_common_setting(int boot_md_comb)
{
	unsigned int reg_value;
	// step 3: MD srcclkena setting
	if ((boot_md_comb&((1<<MD_SYS1)|(1<<MD_SYS3)))==(1<<MD_SYS1))
		*((volatile unsigned int*)0x10001000+0xF0C) = 0x29;
	else {
		reg_value = *((volatile unsigned int*)0x10001000+0xF0C);
		reg_value &= 0x6D;
		reg_value |= 0x29;
		*((volatile unsigned int*)0x10001000+0xF0C) = reg_value;
	}
	dprintf(ALWAYS, "MD srcclkena setting:0x%x\n", *((volatile unsigned int*)0x10001000+0xF0C));
	return 0;
}
static void config_md_boot_env(int md_id, int boot_mode)
{
	unsigned int reg_value;

	switch (md_id) {
		case MD_SYS1:
			// step 0: PMIC setting
			md1_pmic_setting();
			// step 1: Power on MTCMOS
			md_power_up_mtcmos(md_id);

			// Temp Setting:
			// Request by Yuyang Hsiao and Adder
			DRV_WriteReg32(0x10006008,0x215830);

			// step 2: pll init
			md1_pll_init();
			// step 3: set META Register
			if (boot_mode) {
				reg_value = DRV_Reg32(0x20000010);
				DRV_WriteReg32(0x20000010, (reg_value |0x1)); // Bit0, Meta mode flag, this need sync with MD init owner
			}

			// step 4: Disabel MD WDT
			//  -- PCore
			//DRV_WriteReg32(MD_WDT_BASE, 0x55000000);
			//  -- MD RGU L1 Core
			//DRV_WriteReg32(MD_L1WDT_BASE ,0x2200); //L Core

			break;
		case MD_SYS3:
			pmic_init_sequence();
			c2k_boot(boot_mode);
			break;
		default:
			break;
	}

	// Configure DAP for ICE to connect to MD
	dprintf(ALWAYS, "Configure DAP for ICE to connect to MD!\n");
}


void md_wdt_init(void)
{
	if (img_load_flag &(1<<MD_SYS1)) {
		mt_irq_set_sens(MT_MD_WDT1_IRQ_ID, MT65xx_EDGE_SENSITIVE);
		mt_irq_set_polarity(MT_MD_WDT1_IRQ_ID, MT65xx_POLARITY_LOW);
		mt_irq_unmask(MT_MD_WDT1_IRQ_ID);
	}
	if (img_load_flag &(1<<MD_SYS3)) {
		mt_irq_set_sens(MT_MD_WDT2_IRQ_ID, MT65xx_EDGE_SENSITIVE);
		mt_irq_set_polarity(MT_MD_WDT2_IRQ_ID, MT65xx_POLARITY_LOW);
		mt_irq_unmask(MT_MD_WDT2_IRQ_ID);
	}
}

extern char *ld_md_errno_to_str(int errno);
void dummy_ap_boot_up_md(int md_ld_flag)
{
	int boot_mode;
	int i;
	int ret;
	img_load_flag = (unsigned int)md_ld_flag;

	// reinit UART, overwrite DWS setting
	md_uart_config(-1, 0);

	// Disable AP WDT
	*(volatile unsigned int *)(TOPRGU_BASE) = 0x22000000;

	dprintf(ALWAYS, "Welcome to use dummy AP!\n");

	dprintf(ALWAYS, "load flag for dummy AP: %x\n", img_load_flag);
	if (img_load_flag == 0) {
		dprintf(ALWAYS, "no MD loaded for dummy AP\n");
		ret = get_md_err_from_lk_info(MD_SYS1);
		dprintf(ALWAYS, "hint for MD1 errno: %x, %s\n", ret, ld_md_errno_to_str(-ret));
		ret = get_md_err_from_lk_info(MD_SYS3);
		dprintf(ALWAYS, "hint for MD3 errno: %x\n", ret, ld_md_errno_to_str(-ret));
		dprintf(ALWAYS, "stop.....\n");
		while (1);
	}

	if (img_load_flag & (1<<MD_SYS1)) {
		dprintf(ALWAYS, "MD1 loaded");
		ret = get_md_err_from_lk_info(MD_SYS1);
		if (ret < 0) {
			dprintf(ALWAYS, "MD1 load image has error, errno:%s", ld_md_errno_to_str(-ret));
			while (1);
		}
	}
	if (img_load_flag & (1<<MD_SYS3)) {
		dprintf(ALWAYS, "MD3 loaded");
		ret = get_md_err_from_lk_info(MD_SYS3);
		if (ret < 0) {
			dprintf(ALWAYS, "MD3 load image has error, errno:%s", ld_md_errno_to_str(-ret));
			while (1);
		}
	}

	// 1, Setup special GPIO request (RF/SIM/UART ... etc)
	dprintf(ALWAYS, "Configure GPIO!\n");
	if ((img_load_flag&((1<<MD_SYS1)|(1<<MD_SYS3))) == ((1<<MD_SYS1)|(1<<MD_SYS3))) {
		md_gpio_config(2);
	} else if (img_load_flag & (1<<MD_SYS1)) {
		md_gpio_config(0);
	} else if (img_load_flag & (1<<MD_SYS3)) {
		md_gpio_config(1);
	}

	// 2, Check boot Mode
	boot_mode = meta_detection();

	dprintf(ALWAYS, "Get boot mode is %d\n", boot_mode);

	// 3, MD WDT ISR init
	dprintf(ALWAYS, "Init MD WDT\n");
	md_wdt_init();

	// 4. Common Env setting
	md_common_setting(img_load_flag);

	// 5. Setup per-MD env before boot up MD
	for (i=0; i<3; i++) {
		if (img_load_flag & (1<<i)) {
			dprintf(ALWAYS, "MD%d Enabled\n", i+1);
			config_md_boot_env(i, boot_mode);
		}
	}

	// 6, Switch UART
	dprintf(ALWAYS, "Switch UART!\n");
	if ((img_load_flag&((1<<MD_SYS1)|(1<<MD_SYS3))) == ((1<<MD_SYS1)|(1<<MD_SYS3))) {
		md_uart_config(2, boot_mode);
	} else if (img_load_flag & (1<<MD_SYS1)) {
		md_uart_config(0, boot_mode);
	} else if (img_load_flag & (1<<MD_SYS3)) {
		md_uart_config(1, boot_mode);
	}

	for (i=0; i<3; i++) {
		if (img_load_flag & (1<<i)) {
			dprintf(ALWAYS, "Trigger MD%d run\n", i+1);
			let_md_go(i);
		}
	}

	dprintf(ALWAYS, "enter while(1), ^O^!!!!!!!!!\n");
	while (1);
}

void bus_protection_en(int md_id)
{
	if (md_id == MD_SYS1) {
		/* enable protection for MD1 */
		dprintf(ALWAYS, "enable protection for md\n");
		DRV_WriteReg32(0x10001250, 0x003F0000);
		/* Polling protection ready */
		dprintf(ALWAYS, "wait protection ....\n");
		while ((DRV_Reg32(0x10001258)&0x003F0000) != 0x003F0000);
		dprintf(ALWAYS, "protection done\n");
		return;
	}
}

void bus_protection_diable(int md_id)
{
	if (md_id == MD_SYS1) {
		/* enable protection for MD1 */
		dprintf(ALWAYS, "disable protection for md\n");
		DRV_WriteReg32(0x10001250, 0x00000000);
		/* Polling protection ready */
		dprintf(ALWAYS, "wait protection disable....\n");
		while ((DRV_Reg32(0x10001258)&0x003F0000) != 0x00000000);
		dprintf(ALWAYS, "protection disable done\n");
		return;
	}
}


void md_wdt_irq_handler(unsigned int irq)
{
	unsigned int reg_value;

#if defined(ENABLE_MD_RESET_SPM) || defined(ENABLE_MD_RESET_RGU)
	// update counter
	unsigned int cnt = *(volatile unsigned int *)(TOP_RGU_WDT_NONRST_REG);
	*(volatile unsigned int *)(TOP_RGU_WDT_NONRST_REG) = cnt+1;
	// reset UART config
	md_uart_config(-1, 0);
	dprintf(ALWAYS, "\n\n\n\nCurrent wdt cnt:%d\n", cnt+1);

	if (irq == MT_MD_WDT1_IRQ_ID) {
#ifdef ENABLE_MD_RESET_SPM
		dprintf(ALWAYS, "MD1 power off\n");
		spm_mtcmos_ctrl_mdsys1(STA_POWER_DOWN);
		mdelay(5);
#endif
#ifdef ENABLE_MD_RESET_RGU
		dprintf(ALWAYS, "MD1 reset\n");

		bus_protection_en(0);
		reg_value = *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST);
		*((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST) = reg_value|0x88000000|(0x1<<7);
		mdelay(5);
		reg_value = *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST);
		*((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST) = (reg_value|0x88000000)&(~(0x1<<7));
		bus_protection_diable(0);
#endif
		config_md_boot_env(MD_SYS1, 0);
		let_md_go(MD_SYS1);
	}
	if (irq == MT_MD_WDT2_IRQ_ID) {
#ifdef ENABLE_MD_RESET_SPM
		dprintf(ALWAYS, "MD2 power off\n");
		spm_mtcmos_ctrl_mdsys2(STA_POWER_DOWN);
		mdelay(5);
#endif
#ifdef ENABLE_MD_RESET_RGU
		dprintf(ALWAYS, "MD2 reset\n");
		reg_value = *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST);
		*((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST) = reg_value|0x88000000|(0x1<<15);
		mdelay(5);
		reg_value = *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST);
		*((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST) = (reg_value|0x88000000)&(~(0x1<<15));
#endif
		config_md_boot_env(MD_SYS3, 0);
		let_md_go(MD_SYS3);
	}

#if 1
	dprintf(ALWAYS, "Config UART after MD WDT! %d\n", cnt+1);
	if ((img_load_flag&((1<<MD_SYS1)|(1<<MD_SYS3))) == ((1<<MD_SYS1)|(1<<MD_SYS3))) {
		md_uart_config(2, 0);
	} else if (img_load_flag & (1<<MD_SYS1)) {
		md_uart_config(0, 0);
	} else if (img_load_flag & (1<<MD_SYS3)) {
		md_uart_config(2, 0);
	}
#endif
#else
	md_uart_config(-1, 0);
	dprintf(ALWAYS, "Get MD WDT irq, STA:%x!!\n", *((volatile unsigned int*)(MD_WDT_STA)));
#ifdef IGNORE_MD_WDT
	dprintf(ALWAYS, "ignore MD WDT\n");
#else
	dprintf(ALWAYS, "whole system reboot\n");
	*(volatile unsigned int *)(TOP_RGU_WDT_MODE) = 0x22000000;
	*(volatile unsigned int *)(TOP_RGU_WDT_SWRST) = 0x1209;
	while (1);
#endif
#endif
}

int dummy_ap_irq_helper(unsigned int irq)
{
	switch (irq) {
		case MT_MD_WDT1_IRQ_ID:
			if (img_load_flag &(1<<MD_SYS1)) {
#ifndef IGNORE_MD1_WDT
				md_wdt_irq_handler(MT_MD_WDT1_IRQ_ID);
#else
				dprintf(ALWAYS, "ignore MD1 WDT\n");
#endif
			}
			return 1;
		case MT_MD_WDT2_IRQ_ID:
			if (img_load_flag &(1<<MD_SYS3)) {
#ifndef IGNORE_MD2_WDT
				md_wdt_irq_handler(MT_MD_WDT2_IRQ_ID);
#else
				dprintf(ALWAYS, "ignore MD2 WDT\n");
#endif
			}
			return 1;
		default:
			break;
	}

	return 0;
}

void pmic_init_sequence(void)
{
	// Copy from Jade kernel code: alps\kernel-3.10\drivers\misc\mediatek\power\mt6755 =====
	// provided by Argus
	pmic_config_interface(0x8,0x1,0x1,0);
	pmic_config_interface(0xA,0x1,0x1,1);
	pmic_config_interface(0xA,0x1,0x1,2);
	pmic_config_interface(0xA,0x1,0x1,3);
	pmic_config_interface(0xA,0x1,0x1,4);
	pmic_config_interface(0xA,0x1,0x1,5);
	pmic_config_interface(0xA,0x1,0x1,7);
	pmic_config_interface(0xA,0x1,0x1,8);
	pmic_config_interface(0xA,0x1,0x1,10);
	pmic_config_interface(0xA,0x1,0x1,11);
	pmic_config_interface(0xA,0x1,0x1,12);
	pmic_config_interface(0xA,0x1,0x1,13);
	pmic_config_interface(0xA,0x1,0x1,14);
	pmic_config_interface(0xA,0x1,0x1,15);
	pmic_config_interface(0x18,0x1,0x1,5);
	pmic_config_interface(0x1C,0x1,0x1,7);
	pmic_config_interface(0x1E,0x1,0x1,0);
	pmic_config_interface(0x1E,0x1,0x1,1);
	pmic_config_interface(0x2C,0x1,0x1,15);
	pmic_config_interface(0x32,0x1,0x1,2);
	pmic_config_interface(0x32,0x1,0x1,3);
	pmic_config_interface(0x204,0x1,0x1,4);
	pmic_config_interface(0x204,0x1,0x1,5);
	pmic_config_interface(0x204,0x1,0x1,6);
	pmic_config_interface(0x226,0x1,0x1,0);
	pmic_config_interface(0x228,0x1,0x1,0);
	pmic_config_interface(0x228,0x1,0x1,1);
	pmic_config_interface(0x228,0x1,0x1,2);
	pmic_config_interface(0x228,0x1,0x1,3);
	pmic_config_interface(0x240,0x1,0x1,2);
	pmic_config_interface(0x240,0x1,0x1,3);
	pmic_config_interface(0x246,0x1,0x1,13);
	pmic_config_interface(0x246,0x1,0x1,14);
	pmic_config_interface(0x25E,0x1,0x1,9);
	pmic_config_interface(0x282,0x0,0x1,10);
	pmic_config_interface(0x282,0x0,0x1,11);
	pmic_config_interface(0x410,0x8,0x3F,8);
	pmic_config_interface(0x414,0x3,0x3,4);
	pmic_config_interface(0x436,0x0,0x3,2);
	pmic_config_interface(0x450,0xF,0xF,11);
	pmic_config_interface(0x452,0x1,0x1,3);
	pmic_config_interface(0x45C,0x1,0x1,1);
	pmic_config_interface(0x45E,0x400,0xFFFF,0);
	pmic_config_interface(0x464,0xF,0xF,11);
	pmic_config_interface(0x466,0x1,0x1,3);
	pmic_config_interface(0x470,0x1,0x1,1);
	pmic_config_interface(0x472,0x400,0xFFFF,0);
	pmic_config_interface(0x478,0xF,0xF,11);
	pmic_config_interface(0x47A,0x2,0x7,6);
	pmic_config_interface(0x47E,0x1,0x1,1);
	pmic_config_interface(0x480,0x1,0x7,4);
	pmic_config_interface(0x484,0x1,0x1,1);
	pmic_config_interface(0x48C,0xF,0xF,11);
	pmic_config_interface(0x48E,0x2,0x7,6);
	pmic_config_interface(0x492,0x1,0x1,1);
	pmic_config_interface(0x494,0x1,0x7,4);
	pmic_config_interface(0x498,0x1,0x1,1);
	pmic_config_interface(0x4A0,0xF,0xF,11);
	pmic_config_interface(0x4A2,0x2,0x7,6);
	pmic_config_interface(0x4A6,0x1,0x1,1);
	pmic_config_interface(0x4A8,0x1,0x7,4);
	pmic_config_interface(0x4AC,0x1,0x1,1);
	pmic_config_interface(0x4B6,0x4,0x7,6);
	pmic_config_interface(0x4C2,0x10,0xFFFF,0);
	pmic_config_interface(0x4CE,0x1,0x1,1);
	pmic_config_interface(0x4D0,0x1,0x7,4);
	pmic_config_interface(0x4DC,0x3,0x3,0);
	pmic_config_interface(0x4DC,0x0,0x1,10);
	pmic_config_interface(0x4E0,0x0,0x3,14);
	pmic_config_interface(0x4E2,0x81,0xFF,8);
	pmic_config_interface(0x600,0x1,0x1,1);
	pmic_config_interface(0x606,0x11,0x7F,0);
	pmic_config_interface(0x606,0x4,0x7F,8);
	pmic_config_interface(0x60C,0x10,0x7F,0);
	pmic_config_interface(0x612,0x3,0x3,0);
	pmic_config_interface(0x612,0x1,0x1,8);
	pmic_config_interface(0x61A,0x11,0x7F,0);
	pmic_config_interface(0x61A,0x4,0x7F,8);
	pmic_config_interface(0x620,0x10,0x7F,0);
	pmic_config_interface(0x626,0x3,0x3,0);
	pmic_config_interface(0x626,0x1,0x1,8);
	pmic_config_interface(0x628,0x1,0x1,1);
	pmic_config_interface(0x62E,0x11,0x7F,0);
	pmic_config_interface(0x62E,0x4,0x7F,8);
	//if (mt_get_chip_sw_ver() == CHIP_SW_VER_02) // For E2 code
	//    ret = pmic_config_interface(0x632,0x30,0x7F,0);
	pmic_config_interface(0x634,0x10,0x7F,0);
	pmic_config_interface(0x63A,0x3,0x3,0);
	pmic_config_interface(0x63A,0x1,0x3,4);
	pmic_config_interface(0x63A,0x1,0x1,8);
	pmic_config_interface(0x63C,0x1,0x1,1);
	pmic_config_interface(0x642,0x11,0x7F,0);
	pmic_config_interface(0x642,0x4,0x7F,8);
	pmic_config_interface(0x646,0x30,0x7F,0);
	pmic_config_interface(0x648,0x10,0x7F,0);
	pmic_config_interface(0x64E,0x3,0x3,0);
	pmic_config_interface(0x64E,0x1,0x3,4);
	pmic_config_interface(0x64E,0x1,0x1,8);
	pmic_config_interface(0x650,0x1,0x1,1);
	pmic_config_interface(0x656,0x11,0x7F,0);
	pmic_config_interface(0x656,0x4,0x7F,8);
	pmic_config_interface(0x65A,0x40,0x7F,0);
	pmic_config_interface(0x65C,0x10,0x7F,0);
	pmic_config_interface(0x662,0x3,0x3,0);
	pmic_config_interface(0x662,0x1,0x3,4);
	pmic_config_interface(0x662,0x1,0x1,8);
	pmic_config_interface(0x676,0x1,0x1,8);
	pmic_config_interface(0x68A,0x1,0x1,8);
	pmic_config_interface(0x692,0x0,0x7F,0);
	pmic_config_interface(0x692,0x1,0x7F,8);
	pmic_config_interface(0x69E,0x0,0x3,0);
	pmic_config_interface(0x6A0,0x1,0x1,1);
	pmic_config_interface(0x6A6,0x11,0x7F,0);
	pmic_config_interface(0x6A6,0x4,0x7F,8);
	pmic_config_interface(0x6AC,0x35,0x7F,0);
	pmic_config_interface(0x6B2,0x3,0x3,0);
	pmic_config_interface(0x6B2,0x1,0x3,4);
	pmic_config_interface(0x6B2,0x1,0x1,8);
	pmic_config_interface(0xA02,0x1,0x1,9);
	pmic_config_interface(0xA04,0x1,0x1,3);
	pmic_config_interface(0xA04,0x0,0x7,11);
	pmic_config_interface(0xA06,0x1,0x1,9);
	pmic_config_interface(0xA08,0x1,0x1,3);
	pmic_config_interface(0xA08,0x1,0x7,11);
	pmic_config_interface(0xA0A,0x1,0x1,9);
	pmic_config_interface(0xA0E,0x1,0x1,9);
	pmic_config_interface(0xA14,0x1,0x1,9);
	pmic_config_interface(0xA18,0x1,0x1,9);
	pmic_config_interface(0xA1E,0x1,0x1,9);
	pmic_config_interface(0xA24,0x1,0x1,9);
	pmic_config_interface(0xA2A,0x1,0x1,9);
	pmic_config_interface(0xA30,0x1,0x1,9);
	pmic_config_interface(0xA36,0x1,0x1,9);
	pmic_config_interface(0xA3C,0x1,0x1,9);
	pmic_config_interface(0xA42,0x1,0x1,9);
	pmic_config_interface(0xA46,0x1,0x1,3);
	pmic_config_interface(0xA46,0x1,0x7,11);
	pmic_config_interface(0xA48,0x1,0x1,9);
	pmic_config_interface(0xA4E,0x1,0x1,9);
	pmic_config_interface(0xA54,0x1,0x1,9);
	pmic_config_interface(0xA5A,0x1,0x1,9);
	pmic_config_interface(0xA60,0x1,0x1,9);
	pmic_config_interface(0xA66,0x1,0x1,9);
	pmic_config_interface(0xA68,0x1,0x1,3);
	pmic_config_interface(0xA68,0x1,0x7,11);
	pmic_config_interface(0xA6A,0x1,0x1,9);
	pmic_config_interface(0xA70,0x1,0x1,9);
	pmic_config_interface(0xA74,0x1,0x1,1);
	pmic_config_interface(0xA74,0x1,0x1,2);
	pmic_config_interface(0xA74,0x0,0x1,3);
	pmic_config_interface(0xA74,0x0,0x7,5);
	pmic_config_interface(0xA76,0x1,0x1,9);
	pmic_config_interface(0xA7C,0x1,0x1,9);
	pmic_config_interface(0xA82,0x1,0x1,9);
	pmic_config_interface(0xA86,0x0,0x1,3);
	pmic_config_interface(0xA88,0x1,0x1,9);
	pmic_config_interface(0xA8E,0x1,0x1,9);
	pmic_config_interface(0xA94,0x1,0x1,9);
	pmic_config_interface(0xA9E,0x1,0x1,9);
	pmic_config_interface(0xAAC,0x1,0x1,9);
	pmic_config_interface(0xB10,0x2,0x7,8);
	pmic_config_interface(0xB24,0xF0,0xFF,2);
	pmic_config_interface(0xCC4,0x1,0x1,8);
	pmic_config_interface(0xCC4,0x1,0x1,9);
	pmic_config_interface(0xCC8,0x1F,0xFFFF,0);
	pmic_config_interface(0xCCA,0x14,0xFF,0);
	pmic_config_interface(0xCCC,0xFF,0xFF,8);
	pmic_config_interface(0xCE2,0x1,0x7FFF,0);
	pmic_config_interface(0xCE4,0xBCAC,0xFFFF,0);
	pmic_config_interface(0xEA2,0x0,0x1,13);
	pmic_config_interface(0xEA2,0x0,0x1,14);
	pmic_config_interface(0xEA2,0x0,0x1,15);
	pmic_config_interface(0xEAA,0x83,0xFFF,0);
	pmic_config_interface(0xEAA,0x1,0x1,13);
	pmic_config_interface(0xEAA,0x1,0x1,15);
	pmic_config_interface(0xEB2,0x1,0x3,4);
	pmic_config_interface(0xEB2,0x3,0x3,6);
	pmic_config_interface(0xEB2,0x1,0x3,8);
	pmic_config_interface(0xEB2,0x1,0x3,10);
	pmic_config_interface(0xEB2,0x1,0x3,12);
	pmic_config_interface(0xEB2,0x2,0x3,14);
	pmic_config_interface(0xEB4,0x1,0x3,0);
	pmic_config_interface(0xEB4,0x1,0x3,2);
	pmic_config_interface(0xEB4,0x1,0x3,4);
	pmic_config_interface(0xEB4,0x3,0x3,6);
	pmic_config_interface(0xEC6,0x1,0x1,14);
	pmic_config_interface(0xF16,0x40,0x3FF,0);
	pmic_config_interface(0xF16,0x1,0x1,15);
	pmic_config_interface(0xF1C,0x40,0x3FF,0);
	pmic_config_interface(0xF1C,0x1,0x1,15);
	pmic_config_interface(0xF20,0x1,0x1,2);
	pmic_config_interface(0xF7A,0xB,0xF,4);
	pmic_config_interface(0xF84,0x4,0xF,1);
	pmic_config_interface(0xF92,0x3,0xF,0);
	pmic_config_interface(0xFA0,0x1,0x1,1);
	pmic_config_interface(0xFA4,0x0,0x7,4);
	pmic_config_interface(0xFAA,0x1,0x1,2);
	pmic_config_interface(0xFAA,0x1,0x1,6);
	pmic_config_interface(0xFAA,0x1,0x1,7);
}

//=============================================
// MD1 PMIC setting
void md1_pmic_setting(void)
{
	pmic_config_interface(MT6351_PMIC_BUCK_VSRAM_MD_VOSEL_ON, 0x40, 0x7F, 0); //E1 1.0V; offset:0x65A
	pmic_config_interface(MT6351_PMIC_BUCK_VMODEM_VOSEL_ON, 0x40, 0x7F, 0); // 1.0V; offset: 0x632
	pmic_config_interface(MT6351_PMIC_BUCK_VSRAM_MD_VOSEL_CTRL, 1, 1, 1); // HW mode, bit[1]; offset: 0x650
	pmic_config_interface(MT6351_PMIC_BUCK_VMD1_VOSEL_CTRL, 1, 1, 1); // HW mode, bit[1]; offset: 0x63C
	pmic_config_interface(MT6351_PMIC_BUCK_VMODEM_VOSEL_CTRL, 1, 1, 1); // HW mode, bit[1]; offset: 0x628
}

//=============================================
// MD1 pll init
void md1_pll_on(void)
{
	dprintf(ALWAYS, "md1_pll_on\n");
	/* Make md1 208M CG off, switch to software mode */
	*((volatile unsigned int *)0x20150020) |= (0x1<<26); /* turn off mdpll1 cg */
	*((volatile unsigned int *)0x20140010) |= (0x1<<16); /* let mdpll on ctrl into software mode */
	*((volatile unsigned int *)0x20140014) |= (0x1<<16); /* let mdpll enable into software mode */

	/* Turn on 208M */
	*MDPLL1_CON0 |= 0x00000001;
	DRV_WriteReg32(AP_PLL_CON0, (DRV_Reg32(AP_PLL_CON0)|(0x1<<1)));

	udelay(200);

	/* close 208M and autoK */
	*MDPLL1_CON0 &= 0xfffffffe;
	*MDPLL1_CON0 &= 0xffffff7f;

	*((volatile unsigned int *)0x20140010) &= ~(0x1<<16); /* let mdpll on ctrl into hardware mode */
	*((volatile unsigned int *)0x20140014) &= ~(0x1<<16); /* let mdpll enable into hardware mode */
	*((volatile unsigned int *)0x20150020) &= ~(0x1<<26); /* turn on mdpll1 cg */

	*MDPLL1_CON0 &= 0xfffffdff; /* set mdpll control by md1 and c2k */
}

void md1_pll_init(void)
{

	md1_pll_on();

	//enable L1 permission
	*R_L1_PMS |= 0x7;

	// modify PSMCU2EMI bus divider from 3 to 4.
	*R_PSMCU_AO_CLK_CTL = *R_PSMCU_AO_CLK_CTL | 0x83;

	*R_L1MCU_PWR_AWARE |=   (1<<16); //lock dcm bus
	*R_L1AO_PWR_AWARE |=    (1<<16); //lock dcm bus
	//busL2 DCM div 8/normal div 1/ clkslow_en/clock from PLL /debounce enable/ debounce time 7T
	//*R_BUSL2DCM_CON3  = 0x0001FDE7; //L2DCM L1BUS div 16  v1.5
	//*R_BUSL2DCM_CON3  = 0x1001FDE7; //toggle setting // V1.5
	//*R_L1MCU_DCM_CON  = 0x0003FDE7; // DCM div 16/normal div 1/clkslow_en/ clock from PLL / dcm enable /debounce enable /debounce time 15T // V1.5
	*R_BUSL2DCM_CON3  = 0x0000FDE7; //L2DCM L1BUS div 16
	*R_BUSL2DCM_CON3  = 0x1000FDE7; //toggle setting
	*R_L1MCU_DCM_CON  = 0x0001FDE7; // DCM div 8/normal div 1/clkslow_en/ clock from PLL / dcm enable /debounce enable /debounce time 15T
	*R_L1MCU_DCM_CON2 = 0x00000000; //DCM config toggle = 0
	*R_L1MCU_DCM_CON2 = 0x80000000; //DCM config toggle  = 1 / old
	//*R_L1MCU_DCM_CON2 = 0x90000000; //DCM config toggle  = 1 /
	//*R_L1MCU_PWR_AWARE &= (1<<16); //un-lock dcm bus
	//*R_L1AO_PWR_AWARE &=  (1<<16); //un-lock dcm bus

	/*Wait PSMCU PLL ready*/
	dprintf(ALWAYS, "Wait PSMCU PLL ready\n");
	while ((*R_PLL_STS & 0x1) !=0x1);           // Bit  0: PSMCUPLL_RDY
	dprintf(ALWAYS, "Got it\n");
	/*Switch clock, 0: 26MHz, 1: PLL*/
	*R_CLKSEL_CTL |=0x2;                    // Bit  17: RF1_CKSEL
	// Bit  16: INTF_CKSEL
	// Bit  15: MD2G_CKSEL
	// Bit  14: DFE_CKSEL
	// Bit  13: CMP_CKSEL
	// Bit  12: ICC_CKSEL
	// Bit  11: IMC_CKSEL
	// Bit  10: EQ_CKSEL
	// Bit  9: BRP_CKSEL
	// Bit  8: L1MCU_CKSEL
	// Bit  6-5: ATB_SRC_CKSEL
	// Bit  4: ATB_CKSEL
	// Bit  3: DBG_CKSEL
	// Bit  2: ARM7_CKSEL
	// Bit  1: PSMCU_CKSEL
	// Bit  0: BUS_CKSEL

	/*Wait L1MCU PLL ready*/
	dprintf(ALWAYS, "Wait L1MCU PLL ready\n");
	while ((*R_PLL_STS & 0x2) != 0x2);          // Bit  1: L1MCUPLL_RDY
	dprintf(ALWAYS, "Got it\n");
	*R_CLKSEL_CTL |= 0x100;                 // Bit  8: L1MCU_CK = L1MCUPLL

	/*DFE/CMP/ICC/IMC clock src select*/
	*R_FLEXCKGEN_SEL1 = 0x30302020;                 // Bit 29-28 DFE_CLK src = DFEPLL
	// Bit 21-20 CMP_CLK src = DFEPLL
	// Bit 13-12 ICC_CLK src = IMCPLL
	// Bit 5-4   IMC_CLK src = IMCPLL


	/*IMC/MD2G clock src select */
	*R_FLEXCKGEN_SEL2 = 0x00002030;          // Bit 13-12 INTF_CLK src = IMCPLL
	// Bit 5-4  MD2G_CLK src = DFEPLL

	/*Wait DFE/IMC PLL ready*/
	dprintf(ALWAYS, "Wait DFE/IMC PLL ready\n");
	while ((*R_PLL_STS & 0x90) !=0x90);           // Bit  7: DFEPLL_RDY
	// Bit  4: IMCPLL_RDY
	dprintf(ALWAYS, "done\n");

	/*Wait L1SYS clock ready*/
	dprintf(ALWAYS, "Wait L1SYS clock ready\n");
	while ((*R_FLEXCKGEN_STS0 & 0x80800000) != 0x80800000); // Bit  31: EQ_CK_RDY
	// Bit  23: BRP_CK_RDY
	dprintf(ALWAYS, "Done\n");

	dprintf(ALWAYS, "Wait R_FLEXCKGEN_STS1 & 0x80808080 ready\n");
	while ((*R_FLEXCKGEN_STS1 & 0x80808080) != 0x80808080); // Bit  31: DFE_CK_RDY
	// Bit  23: CMP_CK_RDY
	// Bit  15: ICC_CK_RDY
	// Bit  7:  IMC_CK_RDY
	dprintf(ALWAYS, "Done\n");

	dprintf(ALWAYS, "Wait R_FLEXCKGEN_STS2 & 0x8080 ready\n");
	while ((*R_FLEXCKGEN_STS2 & 0x8080) != 0x8080);     // Bit  15: INTF_CK_RDY
	// Bit  23: MD2G_CK_RDY
	dprintf(ALWAYS, "Done\n");

	/*Switch L1SYS clock to PLL clock*/
	*R_CLKSEL_CTL |=0x3fe00;

	/*MD BUS/ARM7 clock src select */
	*R_FLEXCKGEN_SEL0 = 0x30203031;             // Bit  29-28: EQ_CLK src = EQPLL
	// Bit  26-24: EQ+DIVSEL, divided-by bit[2:0]+1
	// Bit  21-20: BRP_CLK src = IMCPLL
	// Bit  13-12: ARM7_CLK src = DFEPLL
	// Bit  5-4: BUS_CLK src = EQPLL
	// Bit  2-0: BUS_DIVSEL, divided-by bit[2:0]+1

	*MD_GLOBAL_CON_DUMMY = MD_PLL_MAGIC_NUM;

	*REG_DCM_PLLCK_SEL |= (1<<7);     // Bit  7: 0: clock do not from PLL, 1: clock from PLL

	// wait DCM config done, then switch BUS clock src to PLL
	dprintf(ALWAYS, "wait DCM config done\n");
	while ((*R_FLEXCKGEN_STS0 & 0x80) !=0x80);        // Bit  7: BUS_CK_RDY
	dprintf(ALWAYS, "done\n");
	*R_CLKSEL_CTL |=0x1;                                // Bit  1: BUS_CLK = EQPLL/2
}

//===========================================================
void c2k_boot(int boot_mode)
{
	unsigned int reg_value;

#if 1
	/* C2K CONFIGURE addr: 0x10001360 , Make C2K boot from 0 address at DRAM*/
	reg_value =*((volatile unsigned int*)0x10001360);
	reg_value &= (~(7<<8));
	reg_value |= (5<<8);
	*((volatile unsigned int*)0x10001360) = reg_value;
	dprintf(ALWAYS, "C2K[0x10001360]%x\n", *((volatile unsigned int*)0x10001360));
#endif

	/* Power on  C2K MTCMOS */
	/* Turn On SPM Reg Key*/
	*POWERON_CONFIG_EN = 0x0b160001;
	*C2K_PWR_CON |= (0x1 << PWR_ON);           // Assert pwr_on
	*C2K_PWR_CON |= (0x1 << PWR_ON_2ND);         // Assert pwr_on_2nd

	dprintf(ALWAYS, "C2K, wait PWR_SATUS and PWR_STATUS_2ND\n");
	while (
	    ((*PWR_STATUS & (0x1 << C2K)) != (0x1 << C2K)) ||
	    ((*PWR_STATUS_2ND & (0x1 << C2K)) != (0x1 << C2K))
	); // waiting for power ready
	dprintf(ALWAYS, "done\n");

	*C2K_PWR_CON &= ~(0x1 << PWR_CLK_DIS);       // Release clk_dis
	*C2K_PWR_CON &= ~(0x1 << PWR_ISO);           // Release pwr_iso
	*C2K_PWR_CON |= (0x1 << PWR_RST_B);          // Release pwr_rst_b

	/* AP config srcclkena selection mask (INFRA_AO, SLEEP_CON  register) */
	/* INFRA_MISC2 0x10001F0C */
	*INFRA_MISC2 |= 0x44;

	/* AP config ClkSQ register (APMixedsys register) */
	/* CLKSQ_LPF_EN (AP_PLL_CON0[1]) set to 1, @ 0x1000C000*/
	*AP_PLL_CON0 |= (0x1 << 1);

	/* AP Hold C2K ARM core */
	*C2K_CONFIG |= 0x1 << 1;

	/* AP_REQ_C2K, AP wakeup C2k */
	/* Enable C2K to Control MDPLL1 */
	*MDPLL1_CON0 &= 0XFFFFFDFF;
	/* Make sure release C2KSYS Reset */
	reg_value = *WDT_SWSYSRST;
	reg_value |= 0x88000000;
	reg_value &= ~(0x1<<15);
	*WDT_SWSYSRST = reg_value;

	/* AP Wakeup C2KSYS */
	*C2K_SPM_CTRL |= 0x1 << 1;
	dprintf(ALWAYS, "Wait C2K_STATUS\n");
	while (((*C2K_STATUS >> 1) & 0x1) == 0);
	dprintf(ALWAYS, "done\n");
	*C2K_SPM_CTRL &= ~(0x1 << 1);
	*INFRA_TOPAXI_PROTECTEN_1 &= 0xFE3FFFFF;
	/* Waiting for C2KSYS Bus ready for operation */
	dprintf(ALWAYS, "Waiting for C2KSYS Bus ready for operation\n");
	do {
		reg_value = *C2K_CGBR1;
	} while (reg_value != 0xFE8);
	dprintf(ALWAYS, "Done\n");

	/* C2K PLL init */
	*(UINT16P)C2K_C2K_PLL_CON3 = 0x8805; // CPPLL/DSPPLL ISO_EN -> hw mode
	*(UINT16P)C2K_C2K_PLL_CON3 = 0x0005; // CPPLL/DSPPLL PWR_ON -> hw mode
	*(UINT16P)C2K_C2K_PLL_CON3 = 0x0001; // MDPLL1 EN -> hw mode
	*(UINT16P)C2K_C2K_PLL_CON2 = 0x0000; // CPPLL/DSPPLL/C2KPLL_SUBPLL1/2 EN -> hw mode
	*(UINT16P)C2K_C2K_PLLTD_CON0 = 0x0010;//  bp_pll_dly -> 0

	*(UINT16P)C2K_C2K_CPPLL_CON0 |= 1 << 15;
	*(UINT16P)C2K_C2K_DSPPLL_CON0 |= 1 << 15;
	*(UINT16P)C2K_C2K_C2KPLL1_CON0 |= 1 << 15;

	/* Wait 20us */
	udelay(20);

	*(UINT16P)C2K_CG_ARM_AMBA_CLKSEL = 0xC124;
	*(UINT16P)C2K_CLK_CTRL4 = 0x8e43;
	*(UINT16P)C2K_CLK_CTRL9 = 0xA207;
}

