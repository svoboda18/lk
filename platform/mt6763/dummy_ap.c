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
//#include <platform/pmic_wrap_init.h>
#include <platform/spm.h>

//=====================================================================
// Feature option switch part
//=====================================================================
//#define THIS_IS_EVB
#define BOTH_MD_ON
//#define DEFAULT_META
//#define THIS_IS_PHONE
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

enum {
	AP_ONLY = -1,
	MD1_ONLY = 0,
	MD2_ONLY,
	MD1_MD2,
};

//------- IRQ ID part ---------------------------------------
#define GIC_PRIVATE_SIGNALS (32)
#define MT_MD_WDT1_IRQ_ID   (252+GIC_PRIVATE_SIGNALS)
#define MT_MD_WDT2_IRQ_ID   (249+GIC_PRIVATE_SIGNALS)

// C2K_CONFIG (0x10001360)
#define AP_C2K_CONFIG (0x10001360)

#define MD1_BUS_PROTECT_EN  (0x10001250)
#define MD1_BUS_PROTECT_STA (0x10001258)

// AP RGU
#define TOP_RGU_WDT_MODE (TOPRGU_BASE+0x0)
#define TOP_RGU_WDT_SWRST (TOPRGU_BASE+0x14)
#define TOP_RGU_WDT_SWSYSRST (TOPRGU_BASE+0x18)
#define TOP_RGU_WDT_NONRST_REG (TOPRGU_BASE+0x20)

#define MD_BOOT_VECTOR_EN 0x20000024

// MD RGU PCore
#define BASE_ADDR_MDRSTCTL   0x200f0000  /* From md, no use by AP directly */
#define L1_BASE_ADDR_L1RGU   0x26010000  /* From md, no use by AP directly  */
#define MD_RGU_BASE          (BASE_ADDR_MDRSTCTL + 0x100)  /* AP use */
#define L1_RGU_BASE          L1_BASE_ADDR_L1RGU    /* AP use */

#define REG_MDRSTCTL_WDTCR            (0x0000) /*WDT_MODE*/
#define WDT_MD_MODE                    REG_MDRSTCTL_WDTCR
#define REG_L1RSTCTL_WDT_MODE         (0x0000)

#define WDT_MD_MODE_KEY         (0x55000008)
#define L1_WDT_MD_MODE_KEY      (0x00002200)


/* MD1 PLL */
#define PLL_TYPE    (volatile unsigned int *)

#define MD_CLKSW_BASE           (0x20150000)
#define MD_GLOBAL_CON_DCM_BASE      (0x20130000)
#define PSMCU_MISC_BASE         (0x20200000)
#define MD_PERI_MISC_BASE       (0x20060000)
#define MDL1A0_BASE         (0x260F0000)
#define MDTOP_PLLMIXED_BASE     (0x20140000)
#define MDSYS_CLKCTL_BASE           (0x20120000)
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

#define R_DCM_SHR_SET_CTL       (PLL_TYPE(MDSYS_CLKCTL_BASE+0x0004))
#define R_LTEL2_BUS_DCM_CTL     (PLL_TYPE(MDSYS_CLKCTL_BASE+0x0010))
#define R_MDDMA_BUS_DCM_CTL     (PLL_TYPE(MDSYS_CLKCTL_BASE+0x0014))
#define R_MDREG_BUS_DCM_CTL     (PLL_TYPE(MDSYS_CLKCTL_BASE+0x0018))
#define R_MODULE_BUS2X_DCM_CTL      (PLL_TYPE(MDSYS_CLKCTL_BASE+0x001C))
#define R_MODULE_BUS1X_DCM_CTL      (PLL_TYPE(MDSYS_CLKCTL_BASE+0x0020))
#define R_MDINFRA_CKEN          (PLL_TYPE(MDSYS_CLKCTL_BASE+0x0044))
#define R_MDPERI_CKEN           (PLL_TYPE(MDSYS_CLKCTL_BASE+0x0048))
#define R_MDPERI_DCM_MASK       (PLL_TYPE(MDSYS_CLKCTL_BASE+0x0064))

#define R_PSMCU_AO_CLK_CTL      (PLL_TYPE(MDSYS_CLKCTL_BASE+0x00C0))

#define R_L1_PMS            (PLL_TYPE(MD_PERI_MISC_BASE+0x00C4))
#define R_PD_PSMCU_SRAM_PMS (0x0094) /*Bit 13: 1 allow to access 0x200D0000 region*/

#define REG_DCM_PLLCK_SEL       (PLL_TYPE(MDL1A0_BASE+0x0188))
#define R_L1MCU_PWR_AWARE       (PLL_TYPE(MDL1A0_BASE+0x0190))
#define R_L1AO_PWR_AWARE        (PLL_TYPE(MDL1A0_BASE+0x0194))
#define R_BUSL2DCM_CON3         (PLL_TYPE(MDL1A0_BASE+0x0198))
#define R_L1MCU_DCM_CON2        (PLL_TYPE(MDL1A0_BASE+0x0184))
#define R_L1MCU_DCM_CON         (PLL_TYPE(MDL1A0_BASE+0x0180))

/*MD PCore SRAM register*/
#define MD_SRAM_PMS_BASE    (0x20060000)
#define MD_SRAM_PMS_LEN     (0xD0)
#define MD_SRAM_MDSYS_MD_PMS        (0x80)
#define MD_SRAM_MDPERISYS1_MD_PMS   (0x84)
#define MD_SRAM_MDPERISYS2_MD_PMS   (0x88)
#define MD_SRAM_PSMCUAPB_MD_PMS     (0x8C)
#define MD_SRAM_MDSYS_AP_PMS        (0x90)
#define MD_SRAM_MDPERISYS1_AP_PMS   (0x94)
#define MD_SRAM_MDPERISYS2_AP_PMS   (0x98)
#define MD_SRAM_PSMCUAPB_AP_PMS     (0x9C)
#define MD_SRAM_MDSYS_TZ_PMS        (0xA0)
#define MD_SRAM_MDPERISYS1_TZ_PMS   (0xA4)
#define MD_SRAM_MDPERISYS2_TZ_PMS   (0xA8)
#define MD_SRAM_PSMCUAPB_TZ_PMS     (0xAC)
#define MD_SRAM_MDSYS_L1_PMS        (0xB0)
#define MD_SRAM_MDPERISYS1_L1_PMS   (0xB4)
#define MD_SRAM_MDPERISYS2_L1_PMS   (0xB8)
#define MD_SRAM_PSMCUAPB_L1_PMS     (0xBC)
#define MD_SRAM_L1SYS_PMS           (0xC4)

#define MD_SRAM_PD_PSMCUSYS_SRAM_BASE   (0x200D0100)
#define MD_SRAM_PD_PSMCUSYS_SRAM_LEN    (0x30)
#define MD_SRAM_PD_PSMCUSYS_SRAM_1      (0x14)
#define MD_SRAM_PD_PSMCUSYS_SRAM_2      (0x18)
#define MD_SRAM_PD_PSMCUSYS_SRAM_3      (0x1C)
#define MD_SRAM_PD_PSMCUSYS_SRAM_4      (0x20)


// C2K boot
#define UINT32P         (volatile unsigned int *)
#define SLEEP_BASE      (0x10006000)
#define APMIXED_BASE        (0x1000C000)
#define TOPRGU_BASE     (0x10007000)
#define INFRACFG_AO_BASE    (0x10001000)
#define C2KSYS_BASE     (0x38000000)
#define C2K_CGBR1                (UINT32P (C2KSYS_BASE+0x0200B004))
#define MDPLL1_CON0              (UINT32P (APMIXED_BASE+0x02C8))
#define WDT_SWSYSRST             (UINT32P (TOPRGU_BASE+0x018))
#define INFRA_TOPAXI_PROTECTEN_1 (UINT32P (INFRACFG_AO_BASE+0x250))
#define INFRA_TOPAXI_PROTECTSTA1_1 (UINT32P (INFRACFG_AO_BASE+0x258))
#define INFRA_TOPAXI_PROTECTEN1  ((UINT32P)(INFRACFG_AO_BASE+0x234))
#define C2K_HANDSHAKE            ((UINT32P)(INFRACFG_AO_BASE+0x368))
#define C2K_SPM_CTRL             (UINT32P (INFRACFG_AO_BASE+0x368))
#define C2K_STATUS               (UINT32P (INFRACFG_AO_BASE+0x364))
#define C2K_CONFIG               (UINT32P (INFRACFG_AO_BASE+0x360))
#define C2K_POWERON_CONFIG_EN        (UINT32P (SLEEP_BASE+0x000))
#define C2K_PWR_CON              (UINT32P (SLEEP_BASE+0x328))
#define C2K_PWR_STATUS               (UINT32P (SLEEP_BASE+0x180))
#define C2K_PWR_STATUS_2ND           (UINT32P (SLEEP_BASE+0x184))
#define INFRA_MISC2              (UINT32P (INFRACFG_AO_BASE+0xF0C))
#define AP_PLL_CON0              (UINT32P (APMIXED_BASE+0x0))
#define PWR_RST_B     (0x1 << 0)
#define PWR_ISO       (0x1 << 1)
#define PWR_ON        (0x1 << 2)
#define PWR_ON_2ND    (0x1 << 3)
#define PWR_CLK_DIS   (0x1 << 4)
#define C2K_PWR_STA_MASK    (0x1 << 28)
#define C2K_PROT_MASK       (0x7 << 22)
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
#define C2K_C2K_PLL_CON3        (UINT32P(C2KSYS_BASE+0x02013008))
#define C2K_C2K_PLL_CON2        (UINT32P(C2KSYS_BASE+0x02013004))
#define C2K_C2K_PLLTD_CON0      (UINT32P(C2KSYS_BASE+0x02013074))
#define C2K_CLK_CTRL9   (UINT32P(C2KSYS_BASE+0x0200029C))
#define C2K_CLK_CTRL4   (UINT32P(C2KSYS_BASE+0x02000010))
#define C2K_CG_ARM_AMBA_CLKSEL  (UINT32P(C2KSYS_BASE+0x02000234))
#define C2K_C2K_C2KPLL1_CON0    (UINT32P(C2KSYS_BASE+0x02013018))
#define C2K_C2K_CPPLL_CON0      (UINT32P(C2KSYS_BASE+0x02013040))
#define C2K_C2K_DSPPLL_CON0     (UINT32P(C2KSYS_BASE+0x02013050))
/* C2K end */

#define L1_C2K_CCIRQ_BASE		0x10211400
#define C2K_L1_CCIRQ_BASE		0x10213400
#define PS_C2K_CCIRQ_BASE		0x10211000
#define C2K_PS_CCIRQ_BASE		0x10213000

#define INFRA_AO_MD_SRCCLKENA                (UINT32P (INFRACFG_AO_BASE+0xF0C))

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

#define ccci_write32(b, a, v)           DRV_WriteReg32((b)+(a), v)
#define ccci_read32(b, a)               DRV_Reg32((b)+(a))


extern BOOT_ARGUMENT    *g_boot_arg;
static unsigned int img_load_flag = 0;

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

static void md_gpio_get(GPIO_PIN pin, char *tag)
{
	dprintf(CRITICAL, "GPIO(%X)(%s): mode=%d,dir=%d,in=%d,out=%d,pull_en=%d,pull_sel=%d,smt=%d\n",
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
	/* ?duplicated configure to C2K SIM ?*/
	md_gpio_set(GPIO39, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO40, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO41, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO38, GPIO_MODE_06, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO37, GPIO_MODE_06, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO36, GPIO_MODE_06, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO46, GPIO_MODE_01, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO45, GPIO_MODE_01, GPIO_DIR_IN, GPIO_OUT_ZERO, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_UNSUPPORTED);
/*
	md_gpio_set(GPIO13, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO14, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO15, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO16, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO27, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
	md_gpio_set(GPIO28, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
*/
	/*for c2k*/
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

	switch (boot_mode_case) {
		case MD1_ONLY:
			//SIM1=> MD1 SIM1IF
			mt_set_gpio_mode(SIM1_SCLK_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM1_SRST_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM1_SIO_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM1_HOT_PLUG_GPIO_ID, GPIO_MODE_01);
			//SIM2=> MD1 SIM2IF
			mt_set_gpio_mode(SIM2_SCLK_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM2_SRST_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM2_SIO_GPIO_ID, GPIO_MODE_01);
			mt_set_gpio_mode(SIM2_HOT_PLUG_GPIO_ID, GPIO_MODE_01);
			break;
		case MD2_ONLY:
			//SIM1=> MD2 UIM0IF
			mt_set_gpio_mode(SIM1_SCLK_GPIO_ID, GPIO_MODE_05);
			mt_set_gpio_mode(SIM1_SRST_GPIO_ID, GPIO_MODE_05);
			mt_set_gpio_mode(SIM1_SIO_GPIO_ID, GPIO_MODE_05);
			mt_set_gpio_mode(SIM1_HOT_PLUG_GPIO_ID, GPIO_MODE_01);
			//SIM2=> MD2 UIM1IF
			mt_set_gpio_mode(SIM2_SCLK_GPIO_ID, GPIO_MODE_06);
			mt_set_gpio_mode(SIM2_SRST_GPIO_ID, GPIO_MODE_06);
			mt_set_gpio_mode(SIM2_SIO_GPIO_ID, GPIO_MODE_06);
			mt_set_gpio_mode(SIM2_HOT_PLUG_GPIO_ID, GPIO_MODE_01);
			break;
		case MD1_MD2:
			//SIM1=> MD2 UIM0IF: SIM1 is for C2K!!
			mt_set_gpio_mode(SIM1_SCLK_GPIO_ID, GPIO_MODE_05);
			mt_set_gpio_mode(SIM1_SRST_GPIO_ID, GPIO_MODE_05);
			mt_set_gpio_mode(SIM1_SIO_GPIO_ID, GPIO_MODE_05);
			mt_set_gpio_mode(SIM1_HOT_PLUG_GPIO_ID, GPIO_MODE_01);
			//SIM2=> MD1 SIM1IF
			mt_set_gpio_mode(SIM2_SCLK_GPIO_ID, GPIO_MODE_03);
			mt_set_gpio_mode(SIM2_SRST_GPIO_ID, GPIO_MODE_03);
			mt_set_gpio_mode(SIM2_SIO_GPIO_ID, GPIO_MODE_03);
			mt_set_gpio_mode(SIM2_HOT_PLUG_GPIO_ID, GPIO_MODE_01);
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

void md_uart_config(int type_id, int boot_mode)
{
	switch (type_id) {
		case AP_ONLY: // for AP only
			dprintf(CRITICAL, "md_uart_config:%d, UART1->[AP], UART2->AP1(rework), UART3->NA, UART4->C2K\n", type_id);
			mt_set_gpio_mode(GPIO105, GPIO_MODE_01); //URXD0 / MD_URXD0
			mt_set_gpio_mode(GPIO106, GPIO_MODE_01); //UTXD0 / MD_UTXD0
			mt_set_gpio_mode(GPIO19, GPIO_MODE_02); //URXD1
			mt_set_gpio_mode(GPIO20, GPIO_MODE_02); //UTXD1
			//mt_set_gpio_mode(GPIO17, GPIO_MODE_05); //C2K_URXD0
			//mt_set_gpio_mode(GPIO18, GPIO_MODE_05); //C2K_UTXD0
			//mt_set_gpio_mode(GPIO15, GPIO_MODE_04); //MD_URXD1
			//mt_set_gpio_mode(GPIO16, GPIO_MODE_04); //MD_UTXD1
			break;
		case MD1_ONLY: // for AP & MD1
			dprintf(CRITICAL, "md_uart_config:%d, UART1->[MD1], UART2->NA, UART3->NA, UART4->C2K\n", type_id);
			mt_set_gpio_mode(GPIO105, GPIO_MODE_03);//MD_URXD0
			mt_set_gpio_mode(GPIO106, GPIO_MODE_03);//MD_UTXD0
			break;
		case MD2_ONLY: // for AP & C2K
			dprintf(CRITICAL, "md_uart_config:%d, UART1->[AP0], UART2->NA, UART3->NA, UART4->C2K\n", type_id);
			mt_set_gpio_mode(GPIO105, GPIO_MODE_01);//URXD0
			mt_set_gpio_mode(GPIO106, GPIO_MODE_01);//UTXD0
			mt_set_gpio_mode(GPIO17, GPIO_MODE_05); //C2K_URXD0
			mt_set_gpio_mode(GPIO18, GPIO_MODE_05); //C2K_UTXD0
			break;
		case MD1_MD2: // for both MD1 and MD2
			dprintf(CRITICAL, "md_uart_config:%d, UART1->[MD1], UART2->AP1, UART3->XXX, UART4->C2K\n", type_id);
			mt_set_gpio_mode(GPIO105, GPIO_MODE_03); //URXD0 / MD_URXD0
			mt_set_gpio_mode(GPIO106, GPIO_MODE_03); //UTXD0 / MD_UTXD0
			mt_set_gpio_mode(GPIO17, GPIO_MODE_05); //C2K_URXD0
			mt_set_gpio_mode(GPIO18, GPIO_MODE_05); //C2K_UTXD0
		default:
			break;
	}
}

void bus_protection_en(int md_id)
{
	if (md_id == MD_SYS1) {
		/* enable protection for MD1 */
		dprintf(CRITICAL, "enable protection for md\n");
		DRV_WriteReg32(MD1_BUS_PROTECT_EN, 0x003F0000);
		/* Polling protection ready */
		dprintf(CRITICAL, "wait protection ....\n");
		while ((DRV_Reg32(MD1_BUS_PROTECT_STA)&0x003F0000) != 0x003F0000);
		dprintf(CRITICAL, "protection done\n");
		return;
	}
}

void bus_protection_diable(int md_id)
{
	if (md_id == MD_SYS1) {
		/* enable protection for MD1 */
		dprintf(CRITICAL, "disable protection for md\n");
		DRV_WriteReg32(MD1_BUS_PROTECT_EN, 0x00000000);
		/* Polling protection ready */
		dprintf(CRITICAL, "wait protection disable....\n");
		while ((DRV_Reg32(MD1_BUS_PROTECT_STA)&0x003F0000) != 0x00000000);
		dprintf(CRITICAL, "protection disable done\n");
		return;
	}
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

void pmic_init_sequence(void)
{
	// Copy from Jade kernel code: alps\kernel-3.18\drivers\misc\mediatek\power\mt6763 =====
	unsigned int ret;

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
	pmic_config_interface(0x12,0x1,0x1,9);
	pmic_config_interface(0x12,0x1,0x1,10);
	pmic_config_interface(0x12,0x1,0x1,12);
	pmic_config_interface(0x12,0x1,0x1,13);
	pmic_config_interface(0x12,0x1,0x1,14);
	pmic_config_interface(0x18,0x1,0x1,5);
	pmic_config_interface(0x1C,0x1,0x1,7);
	pmic_config_interface(0x1E,0x1,0x1,0);
	pmic_config_interface(0x1E,0x1,0x1,1);
	pmic_config_interface(0x2C,0x1,0x1,15);
	pmic_config_interface(0x32,0x1,0x1,2);
	ret = pmic_config_interface(0x32,0x1,0x1,3); // [3:3]: RG_RST_DRVSEL; 6/1,Seven,

	ret = pmic_config_interface(0x204,0x1,0x1,4); // [4:4]: RG_SRCLKEN_IN0_HW_MODE; Juinn-Ting
	ret = pmic_config_interface(0x204,0x1,0x1,5); // [5:5]: RG_SRCLKEN_IN1_HW_MODE; Juinn-Ting
	ret = pmic_config_interface(0x204,0x1,0x1,6); // [6:6]: RG_OSC_SEL_HW_MODE; Juinn-Ting
	ret = pmic_config_interface(0x226,0x1,0x1,0); // [0:0]: RG_SMT_WDTRSTB_IN; 6/1,Seven
	ret = pmic_config_interface(0x228,0x1,0x1,0); // [0:0]: RG_SMT_SPI_CLK; 6/1,Check with Juinn-Ting
	ret = pmic_config_interface(0x228,0x1,0x1,1); // [1:1]: RG_SMT_SPI_CSN; 6/1,Check with Juinn-Ting
	ret = pmic_config_interface(0x228,0x1,0x1,2); // [2:2]: RG_SMT_SPI_MOSI; 6/1,Check with Juinn-Ting
	ret = pmic_config_interface(0x228,0x1,0x1,3); // [3:3]: RG_SMT_SPI_MISO; 6/1,Check with Juinn-Ting
	ret = pmic_config_interface(0x23A,0x0,0x1,9); // [9:9]: RG_AUXADC_SMPS_CK_PDN; 9/7 Peter SW,for AUXADC need always on
	ret = pmic_config_interface(0x23A,0x1,0x1,11); // [11:11]: RG_AUXADC_26M_CK_PDN;
	ret = pmic_config_interface(0x240,0x1,0x1,2); // [2:2]: RG_RTC_75K_CK_PDN; Juinn-Ting
	ret = pmic_config_interface(0x240,0x1,0x1,3); // [3:3]: RG_RTCDET_CK_PDN; Juinn-Ting
	ret = pmic_config_interface(0x240,0x0,0x1,10); // [10:10]: RG_AUXADC_CK_PDN;
	ret = pmic_config_interface(0x246,0x1,0x1,13); // [13:13]: RG_RTC_EOSC32_CK_PDN; Juinn-Ting(if 32 less keep default Value)
	ret = pmic_config_interface(0x246,0x1,0x1,14); // [14:14]: RG_TRIM_75K_CK_PDN; Juinn-Ting
	ret = pmic_config_interface(0x24C,0x0,0x1,2); // [2:2]: RG_EFUSE_CK_PDN;
	ret = pmic_config_interface(0x258,0x0,0x1,5); // [5:5]: RG_BUCK_VSRAM_MD_9M_CK_PDN;
	ret = pmic_config_interface(0x258,0x1,0x1,8); // [8:8]: RG_AUD18M_CK_PDN;
	ret = pmic_config_interface(0x258,0x0,0x1,14); // [14:14]: RG_BUCK_AUD_1M_CK_PDN;
	ret = pmic_config_interface(0x25E,0x1,0x1,9); // [9:9]: RG_75K_32K_SEL; Angela
	ret = pmic_config_interface(0x25E,0x0,0x1,10); // [10:10]: RG_AUXADC_CK_CKSEL;
	ret = pmic_config_interface(0x282,0x0,0x1,3); // [3:3]: RG_AUXADC_CK_PDN_HWEN; 9/7,Peter SW,For Auxadc need always on
	ret = pmic_config_interface(0x282,0x0,0x1,4); // [4:4]: RG_AUXADC_SMPS_CK_PDN_HWEN; 9/7,Peter SW,For Auxadc need always on
	ret = pmic_config_interface(0x282,0x0,0x1,10); // [10:10]: RG_AUXADC_26M_CK_PDN_HWEN; ZF
	ret = pmic_config_interface(0x282,0x0,0x1,11); // [11:11]: RG_AUXADC_CK_CKSEL_HWEN; ZF
	ret = pmic_config_interface(0x28E,0x0,0x1,4); // [4:4]: RG_AUD18M_CK_PDN_HWEN;
	ret = pmic_config_interface(0x410,0x8,0x3F,8); // [13:8]: BUCK_VPA_VOSEL_DLC001; 6/24,Paul
	ret = pmic_config_interface(0x414,0x3,0x3,4); // [5:4]: BUCK_VPA_DVS_TRANS_CTRL; 6/24,Paul
	ret = pmic_config_interface(0x422,0x1,0x1,0); // [0:0]: BUCK_VCORE_EN_OC_SDN_SEL; 12/16,Stephen VCORE OC Shutdown by test issue need disable
	ret = pmic_config_interface(0x422,0x1,0x1,1); // [1:1]: BUCK_VGPU_EN_OC_SDN_SEL; 1/6,Stephen VGPU OC Shutdown by test issue need disable
	ret = pmic_config_interface(0x422,0x1,0x1,2); // [2:2]: BUCK_VMODEM_EN_OC_SDN_SEL; 12/9,Stephen VMODEM OC Shutdown by test issue need disable
	ret = pmic_config_interface(0x422,0x1,0x1,3); // [3:3]: BUCK_VMD1_EN_OC_SDN_SEL; 12/16,Stephen VMD1 OC Shutdown by test issue need disable
	ret = pmic_config_interface(0x422,0x1,0x1,4); // [4:4]: BUCK_VSRAM_MD_EN_OC_SDN_SEL; 12/16,Stephen VSRAM_MD OC Shutdown by test issue need disable
	ret = pmic_config_interface(0x422,0x1,0x1,7); // [7:7]: BUCK_VPA_EN_OC_SDN_SEL; 9/14,Stephen PA OC Shutdown by Filed Test need disable
	ret = pmic_config_interface(0x436,0x0,0x3,2); // [3:2]: BUCK_VPA_OC_WND; 6/1 Paul

	ret = pmic_config_interface(0x44A,0x2,0x3,8); // [9:8]: RG_VCORE_VSLEEP_SEL; 3/21,TzuHeng Sleep mode voltage 0.65V
	ret = pmic_config_interface(0x44A,0x3,0x3,10); // [11:10]: RG_VGPU_VSLEEP_SEL; 3/21,TzuHeng Sleep mode voltage 0.6V
	ret = pmic_config_interface(0x44A,0x3,0x3,12); // [13:12]: RG_VSRAM_MD_VSLEEP_SEL; 3/21,TzuHeng Sleep mode voltage 0.6V
	ret = pmic_config_interface(0x44A,0x3,0x3,14); // [15:14]: RG_VMODEM_VSLEEP_SEL; 3/21,TzuHeng Sleep mode voltage 0.6V
	ret = pmic_config_interface(0x44C,0x3,0x3,0); // [1:0]: RG_VMD1_VSLEEP_SEL; 3/21,TzuHeng Sleep mode voltage 0.6V
	ret = pmic_config_interface(0x450,0xF,0xF,11); // [14:11]: RG_VCORE_CSL; 6/1,Tim,OC Level Adjust
	ret = pmic_config_interface(0x452,0x1,0x1,3); // [3:3]: RG_VCORE_ADRC_FEN; 6/1,Tim,Bandwidth Extend
	ret = pmic_config_interface(0x456,0x1,0x1,7); // [7:7]: RG_VCORE_NLIM_GATING; 8/17,Tim
	ret = pmic_config_interface(0x45C,0x1,0x1,1); // [1:1]: RG_VCORE_VDIFF_ENLOWIQ; 6/1,Tim,Ultra Low Iq
	ret = pmic_config_interface(0x45E,0x400,0xFFFF,0); // [15:0]: RG_VCORE_RSV; 6/1,Tim,Enable Pre-OC
	ret = pmic_config_interface(0x464,0xF,0xF,11); // [14:11]: RG_VGPU_CSL; 6/1,Tim,OC Level Adjust
	ret = pmic_config_interface(0x466,0x1,0x1,3); // [3:3]: RG_VGPU_ADRC_FEN; 6/1,Tim,Bandwidth Extend
	ret = pmic_config_interface(0x466,0x5,0x7,9); // [11:9]: RG_VGPU_PFMOC; 8/24,Tim PFM OC Adjust for DVS Performance
	ret = pmic_config_interface(0x46A,0x1,0x1,7); // [7:7]: RG_VGPU_NLIM_GATING; 8/17,Tim
	ret = pmic_config_interface(0x470,0x1,0x1,1); // [1:1]: RG_VGPU_VDIFF_ENLOWIQ; 6/1,Tim,Ultra Low Iq
	ret = pmic_config_interface(0x472,0x400,0xFFFF,0); // [15:0]: RG_VGPU_RSV; 6/1,Tim,Enable Pre-OC
	ret = pmic_config_interface(0x478,0x0,0x7,0); // [2:0]: RG_VSRAM_MD_RZSEL0; 2/5,Johnson Load Transient performance fine tune
	ret = pmic_config_interface(0x478,0xF,0xF,11); // [14:11]: RG_VSRAM_MD_CSL; 6/1, Johnson, OC performance fine tune
	ret = pmic_config_interface(0x47A,0x2,0x7,6); // [8:6]: RG_VSRAM_MD_PFMOC; 6/1, Johnson, PFM ripple performance fine tune
	ret = pmic_config_interface(0x47E,0x1,0x1,1); // [1:1]: RG_VSRAM_MD_NLIM_GATING; 6/24,Johnson,for transient mode transition Vo ringing, performance concern.
	ret = pmic_config_interface(0x480,0x1,0x7,4); // [6:4]: RG_VSRAM_MD_PFM_RIP; 6/1, Johnson, performance fine tune.(PFM ripple)
	ret = pmic_config_interface(0x484,0x1,0x1,1); // [1:1]: RG_VSRAM_MD_VDIFF_ENLOWIQ; 6/1, Johnson, performance improvement. (iq, mode transition and pfm ripple H/L
	ret = pmic_config_interface(0x48C,0x0,0x7,0); // [2:0]: RG_VMODEM_RZSEL0; 2/5,Johnson Load Transient performance fine tune
	ret = pmic_config_interface(0x48C,0xF,0xF,11); // [14:11]: RG_VMODEM_CSL; 6/1, Johnson, OC performance fine tune
	ret = pmic_config_interface(0x48E,0x2,0x7,6); // [8:6]: RG_VMODEM_PFMOC; 6/1, Johnson, PFM ripple performance fine tune
	ret = pmic_config_interface(0x492,0x1,0x1,1); // [1:1]: RG_VMODEM_NLIM_GATING; 6/24,Johnson,for transient mode transition Vo ringing, performance concern.
	ret = pmic_config_interface(0x494,0x1,0x7,4); // [6:4]: RG_VMODEM_PFM_RIP; 6/1, Johnson, performance fine tune.(PFM ripple)
	ret = pmic_config_interface(0x498,0x1,0x1,1); // [1:1]: RG_VMODEM_VDIFF_ENLOWIQ; 6/1, Johnson, performance improvement. (iq, mode transition and pfm ripple H/L
	ret = pmic_config_interface(0x4A0,0x0,0x7,0); // [2:0]: RG_VMD1_RZSEL0; 2/5,Johnson Load Transient performance fine tune
	ret = pmic_config_interface(0x4A0,0xF,0xF,11); // [14:11]: RG_VMD1_CSL; 6/1, Johnson, OC performance fine tune
	ret = pmic_config_interface(0x4A2,0x2,0x7,6); // [8:6]: RG_VMD1_PFMOC; 6/1, Johnson, PFM ripple performance fine tune
	ret = pmic_config_interface(0x4A6,0x1,0x1,1); // [1:1]: RG_VMD1_NLIM_GATING; 6/24,Johnson,for transient mode transition Vo ringing, performance concern.
	ret = pmic_config_interface(0x4A8,0x1,0x7,4); // [6:4]: RG_VMD1_PFM_RIP; 6/1, Johnson, performance fine tune.(PFM ripple)
	ret = pmic_config_interface(0x4AC,0x1,0x1,1); // [1:1]: RG_VMD1_VDIFF_ENLOWIQ; 6/1, Johnson, performance improvement. (iq, mode transition and pfm ripple H/L
	ret = pmic_config_interface(0x4B6,0x6,0x7,6); // [8:6]: RG_VS1_PFMOC; 7/15,Lan improve ZXOS Detect
	ret = pmic_config_interface(0x4C2,0x10,0xFFFF,0); // [15:0]: RG_VS1_RSV; 6/2, Hung Mu Chou,

	ret = pmic_config_interface(0x4C8,0xF,0xF,11); // [14:11]: RG_VS2_CSL; 7/15,Lan improve ZXOS Detect
	ret = pmic_config_interface(0x4CA,0x5,0x7,6); // [8:6]: RG_VS2_PFMOC; 7/15,Lan improve ZXOS Detect
	ret = pmic_config_interface(0x4CE,0x1,0x1,1); // [1:1]: RG_VS2_NLIM_GATING; 6/1 Lan

	ret = pmic_config_interface(0x4D0,0x1,0x7,4); // [6:4]: RG_VS2_PFM_RIP; 6/1 Lan

	ret = pmic_config_interface(0x4DC,0x3,0x3,0); // [1:0]: RG_VPA_CC; 6/24 Paul

	ret = pmic_config_interface(0x4DC,0x2,0x3,4); // [5:4]: RG_VPA_CSMIR; 8/27,Paul reduce 20% Current sensing ratio
	ret = pmic_config_interface(0x4DC,0x0,0x1,10); // [10:10]: RG_VPA_AZC_EN; 6/3,Paul
	ret = pmic_config_interface(0x4DC,0x1,0x3,14); // [15:14]: RG_VPA_RZSEL; 8/27,Paul Compensation resistance 310k>210K
	ret = pmic_config_interface(0x4E0,0x0,0x3,14); // [15:14]: RG_VPA_MIN_PK; 6/1 Paul

	ret = pmic_config_interface(0x4E2,0x88,0xFF,8); // [15:8]: RG_VPA_RSV2; 8/10,Paul, Auto Change Slope compensation
	ret = pmic_config_interface(0x600,0x1,0x1,1); // [1:1]: BUCK_VCORE_VOSEL_CTRL; 6/1,Tim,Sleep mode by HW Control
	ret = pmic_config_interface(0x606,0x11,0x7F,0); // [6:0]: BUCK_VCORE_SFCHG_FRATE; 6/1,Tim,DVS Falling Slew Rate
	ret = pmic_config_interface(0x606,0xB,0x7F,8); // [14:8]: BUCK_VCORE_SFCHG_RRATE; 16 2/26,Evan Wang,for Olympus DRAM Request
	ret = pmic_config_interface(0x60A,0x20,0x7F,0); // [6:0]: BUCK_VCORE_VOSEL_ON; 1/15,Tzu Heng Normal mode voltage for Olympus(0.8V)
	ret = pmic_config_interface(0x60C,0x8,0x7F,0); // [6:0]: BUCK_VCORE_VOSEL_SLEEP; 1/6,Tzu Heng Sleep mode voltage for Olympus(0.65V)
	ret = pmic_config_interface(0x612,0x3,0x3,0); // [1:0]: BUCK_VCORE_TRANS_TD; 6/1,Tim
	ret = pmic_config_interface(0x612,0x1,0x1,8); // [8:8]: BUCK_VCORE_VSLEEP_EN; 6/1,Tim,Sleep mode by HW Control
	ret = pmic_config_interface(0x61A,0x11,0x7F,0); // [6:0]: BUCK_VGPU_SFCHG_FRATE; 6/1,Tim,DVS Falling Slew Rate
	ret = pmic_config_interface(0x61A,0x4,0x7F,8); // [14:8]: BUCK_VGPU_SFCHG_RRATE; 6/1,Tim,DVS Rising Slew Rate
	ret = pmic_config_interface(0x620,0x0,0x7F,0); // [6:0]: BUCK_VGPU_VOSEL_SLEEP; 1/6,Tzu Heng Sleep mode voltage for Olympus(0.6V)
	ret = pmic_config_interface(0x626,0x3,0x3,0); // [1:0]: BUCK_VGPU_TRANS_TD; 6/1,Tim
	ret = pmic_config_interface(0x626,0x1,0x3,4); // [5:4]: BUCK_VGPU_TRANS_CTRL; 8/17,Tim
	ret = pmic_config_interface(0x62E,0x11,0x7F,0); // [6:0]: BUCK_VMODEM_SFCHG_FRATE; 6/1, Johnson,softchange for DVS/DVFS slew rate falling 2.0us/step
	ret = pmic_config_interface(0x62E,0x4,0x7F,8); // [14:8]: BUCK_VMODEM_SFCHG_RRATE; 6/1, Johnson,softchange for DVS/DVFS slew rate rising 0.5us/step
	ret = pmic_config_interface(0x634,0x0,0x7F,0); // [6:0]: BUCK_VMODEM_VOSEL_SLEEP; 1/6,Tzu Heng Sleep mode voltage for Olympus(0.6V)
	ret = pmic_config_interface(0x63A,0x3,0x3,0); // [1:0]: BUCK_VMODEM_TRANS_TD; 6/1, Johnson, falling for DVFS/DVS discharge extension time control
	ret = pmic_config_interface(0x63A,0x1,0x3,4); // [5:4]: BUCK_VMODEM_TRANS_CTRL; 6/1, Johnson, falling for DVFS/DVS discharge slew rate control
	ret = pmic_config_interface(0x63A,0x1,0x1,8); // [8:8]: BUCK_VMODEM_VSLEEP_EN; 6/1, Johnson, r2r power down with srclken sleep hw mode
	ret = pmic_config_interface(0x642,0x11,0x7F,0); // [6:0]: BUCK_VMD1_SFCHG_FRATE; 6/1, Johnson,softchange for DVS/DVFS slew rate falling 2.0us/step
	ret = pmic_config_interface(0x642,0x4,0x7F,8); // [14:8]: BUCK_VMD1_SFCHG_RRATE; 6/1, Johnson,softchange for DVS/DVFS slew rate rising 0.5us/step
	ret = pmic_config_interface(0x648,0x0,0x7F,0); // [6:0]: BUCK_VMD1_VOSEL_SLEEP; 1/6,Tzu Heng Sleep mode voltage for Olympus(0.6V)
	ret = pmic_config_interface(0x64E,0x3,0x3,0); // [1:0]: BUCK_VMD1_TRANS_TD; 6/1, Johnson, falling for DVFS/DVS discharge extension time control
	ret = pmic_config_interface(0x64E,0x1,0x3,4); // [5:4]: BUCK_VMD1_TRANS_CTRL; 6/1, Johnson, falling for DVFS/DVS discharge slew rate control
	ret = pmic_config_interface(0x64E,0x1,0x1,8); // [8:8]: BUCK_VMD1_VSLEEP_EN; 6/1, Johnson, r2r power down with srclken sleep hw mode, after vo sel
	ret = pmic_config_interface(0x656,0x11,0x7F,0); // [6:0]: BUCK_VSRAM_MD_SFCHG_FRATE; 6/1, Johnson,softchange for DVS/DVFS slew rate falling 2.0us/step
	ret = pmic_config_interface(0x656,0x4,0x7F,8); // [14:8]: BUCK_VSRAM_MD_SFCHG_RRATE; 6/1, Johnson,softchange for DVS/DVFS slew rate rising 0.5us/step
	ret = pmic_config_interface(0x65A,0x30,0x7F,0); // [6:0]: BUCK_VSRAM_MD_VOSEL_ON; 1/6,Tzu Heng Normal mode voltage for Olympus(0.9V)
	ret = pmic_config_interface(0x65C,0x0,0x7F,0); // [6:0]: BUCK_VSRAM_MD_VOSEL_SLEEP; 1/6,Tzu Heng Sleep mode voltage for Olympus(0.6V)
	ret = pmic_config_interface(0x662,0x3,0x3,0); // [1:0]: BUCK_VSRAM_MD_TRANS_TD; 6/1, Johnson, falling for DVFS/DVS discharge extension time control
	ret = pmic_config_interface(0x662,0x1,0x3,4); // [5:4]: BUCK_VSRAM_MD_TRANS_CTRL; 6/1, Johnson, falling for DVFS/DVS discharge slew rate control
	ret = pmic_config_interface(0x662,0x1,0x1,8); // [8:8]: BUCK_VSRAM_MD_VSLEEP_EN; 6/1, Johnson, r2r power down with srclken sleep hw mode, after vo sel
	ret = pmic_config_interface(0x676,0x1,0x1,8); // [8:8]: BUCK_VS1_VSLEEP_EN; 6/1,Lan,r2r power down with srclken sleep hw mode
	ret = pmic_config_interface(0x68A,0x1,0x1,8); // [8:8]: BUCK_VS2_VSLEEP_EN; 6/1,Lan,r2r power down with srclken sleep hw mode
	ret = pmic_config_interface(0x692,0x0,0x7F,0); // [6:0]: BUCK_VPA_SFCHG_FRATE; 6/3,Paul
	ret = pmic_config_interface(0x692,0x1,0x7F,8); // [14:8]: BUCK_VPA_SFCHG_RRATE; 6/3,Paul
	ret = pmic_config_interface(0x69E,0x0,0x3,0); // [1:0]: BUCK_VPA_TRANS_TD; 624,Paul
	ret = pmic_config_interface(0x6A0,0x1,0x1,1); // [1:1]: BUCK_VSRAM_PROC_VOSEL_CTRL; 6/5,Chia Lin
	ret = pmic_config_interface(0x6A6,0x11,0x7F,0); // [6:0]: BUCK_VSRAM_PROC_SFCHG_FRATE; 6/5,Chia Lin
	ret = pmic_config_interface(0x6A6,0x4,0x7F,8); // [14:8]: BUCK_VSRAM_PROC_SFCHG_RRATE; 6/5,Chia Lin
	ret = pmic_config_interface(0x6AC,0x0,0x7F,0); // [6:0]: BUCK_VSRAM_PROC_VOSEL_SLEEP; 1/6,Tzu Heng Sleep mode voltage for Olympus(0.6V)
	ret = pmic_config_interface(0x6B2,0x3,0x3,0); // [1:0]: BUCK_VSRAM_PROC_TRANS_TD; 6/5,Chia Lin
	ret = pmic_config_interface(0x6B2,0x1,0x3,4); // [5:4]: BUCK_VSRAM_PROC_TRANS_CTRL; 6/5,Chia Lin
	ret = pmic_config_interface(0xA00,0x1,0x1,2); // [2:2]: RG_VA18_MODE_CTRL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA00,0x0,0x7,5); // [7:5]: RG_VA18_SRCLK_MODE_SEL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA02,0x1,0x1,9); // [9:9]: RG_VA18_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA04,0x1,0x1,3); // [3:3]: RG_VTCXO24_ON_CTRL; 6/2,CW
	ret = pmic_config_interface(0xA04,0x0,0x7,11); // [13:11]: RG_VTCXO24_SRCLK_EN_SEL; 6/2,CW,RF Power Control request
	ret = pmic_config_interface(0xA06,0x1,0x1,9); // [9:9]: RG_VTCXO24_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA08,0x1,0x1,3); // [3:3]: RG_VTCXO28_ON_CTRL; 6/2,CW
	ret = pmic_config_interface(0xA08,0x1,0x7,11); // [13:11]: RG_VTCXO28_SRCLK_EN_SEL; 6/2,CW,RF Power Control request
	ret = pmic_config_interface(0xA0A,0x1,0x1,9); // [9:9]: RG_VTCXO28_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA0E,0x1,0x1,9); // [9:9]: RG_VCN28_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA14,0x1,0x1,9); // [9:9]: RG_VCAMA_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA16,0x1,0x1,2); // [2:2]: RG_VUSB33_MODE_CTRL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA16,0x0,0x7,5); // [7:5]: RG_VUSB33_SRCLK_MODE_SEL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA18,0x1,0x1,9); // [9:9]: RG_VUSB33_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA1E,0x1,0x1,9); // [9:9]: RG_VSIM1_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA24,0x1,0x1,9); // [9:9]: RG_VSIM2_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA2A,0x1,0x1,9); // [9:9]: RG_VEMC_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA30,0x1,0x1,9); // [9:9]: RG_VMCH_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA34,0x1,0x1,2); // [2:2]: RG_VIO28_MODE_CTRL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA34,0x0,0x7,5); // [7:5]: RG_VIO28_SRCLK_MODE_SEL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA36,0x1,0x1,9); // [9:9]: RG_VIO28_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA3C,0x1,0x1,9); // [9:9]: RG_VIBR_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA46,0x1,0x1,3); // [3:3]: RG_VRF18_ON_CTRL; 6/2,CW
	ret = pmic_config_interface(0xA46,0x1,0x7,11); // [13:11]: RG_VRF18_SRCLK_EN_SEL; 6/2,CW,RF Power Control request
	ret = pmic_config_interface(0xA48,0x1,0x1,9); // [9:9]: RG_VRF18_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA4C,0x1,0x1,2); // [2:2]: RG_VIO18_MODE_CTRL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA4C,0x0,0x7,5); // [7:5]: RG_VIO18_SRCLK_MODE_SEL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA4E,0x1,0x1,9); // [9:9]: RG_VIO18_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA54,0x1,0x1,9); // [9:9]: RG_VCN18_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA5A,0x1,0x1,9); // [9:9]: RG_VCAMIO_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA66,0x1,0x1,9); // [9:9]: RG_VXO22_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA68,0x1,0x1,3); // [3:3]: RG_VRF12_ON_CTRL; 6/2,CW
	ret = pmic_config_interface(0xA68,0x1,0x7,11); // [13:11]: RG_VRF12_SRCLK_EN_SEL; 6/2,CW,RF Power Control request
	ret = pmic_config_interface(0xA6E,0x1,0x1,2); // [2:2]: RG_VA10_MODE_CTRL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA6E,0x0,0x7,5); // [7:5]: RG_VA10_SRCLK_MODE_SEL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA74,0x1,0x1,1); // [1:1]: RG_VDRAM_EN; 6/5,Chia Lin Same as Fly suspend mode
	ret = pmic_config_interface(0xA74,0x1,0x1,2); // [2:2]: RG_VDRAM_MODE_CTRL; 6/5,Chia Lin Same as Fly suspend mode
	ret = pmic_config_interface(0xA74,0x0,0x1,3); // [3:3]: RG_VDRAM_ON_CTRL; 6/5,Chia Lin Same as Fly suspend mode
	ret = pmic_config_interface(0xA74,0x0,0x7,5); // [7:5]: RG_VDRAM_SRCLK_MODE_SEL; 6/5,Chia Lin Same as Fly suspend mode
	ret = pmic_config_interface(0xA7C,0x1,0x1,9); // [9:9]: RG_VMIPI_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA82,0x1,0x1,9); // [9:9]: RG_VGP3_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA86,0x0,0x1,3); // [3:3]: RG_VBIF28_ON_CTRL; 6/1,Seven,
	ret = pmic_config_interface(0xA88,0x1,0x1,9); // [9:9]: RG_VBIF28_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA8E,0x1,0x1,9); // [9:9]: RG_VEFUSE_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA94,0x1,0x1,9); // [9:9]: RG_VCN33_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xA9C,0x1,0x1,2); // [2:2]: RG_VLDO28_MODE_CTRL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA9C,0x0,0x7,5); // [7:5]: RG_VLDO28_SRCLK_MODE_SEL; 7/28 Chia Lin
	ret = pmic_config_interface(0xA9E,0x1,0x1,9); // [9:9]: RG_VLDO28_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xAAC,0x1,0x1,9); // [9:9]: RG_VMC_OCFB_EN; 6/1 Fandy

	ret = pmic_config_interface(0xB10,0x2,0x7,8); // [10:8]: RG_VA10_VOSEL; 6/8,KH for JADE VA10=1V
	ret = pmic_config_interface(0xCC4,0x1,0x1,8); // [8:8]: FG_SLP_EN; 6/1,Filby
	ret = pmic_config_interface(0xCC4,0x1,0x1,9); // [9:9]: FG_ZCV_DET_EN; 6/1,Filby
	ret = pmic_config_interface(0xCC8,0x1F,0xFFFF,0); // [15:0]: FG_SLP_CUR_TH; 6/1,Filby
	ret = pmic_config_interface(0xCCA,0x14,0xFF,0); // [7:0]: FG_SLP_TIME; 6/1,Filby
	ret = pmic_config_interface(0xCCC,0xFF,0xFF,8); // [15:8]: FG_DET_TIME; 6/1,Filby
	ret = pmic_config_interface(0xCE2,0x1,0x7FFF,0); // [14:0]: FG_ZCV_CAR_TH_33_19; 6/1,Filby
	ret = pmic_config_interface(0xCE4,0xBCAC,0xFFFF,0); // [15:0]: FG_ZCV_CAR_TH_18_03; 6/1,Filby
	ret = pmic_config_interface(0xEA2,0x0,0x1,13); // [13:13]: AUXADC_CK_AON_GPS; Check with Peter
	ret = pmic_config_interface(0xEA2,0x0,0x1,14); // [14:14]: AUXADC_CK_AON_MD; Check with Peter
	ret = pmic_config_interface(0xEA2,0x0,0x1,15); // [15:15]: AUXADC_CK_AON; Check with Peter
	ret = pmic_config_interface(0xEAA,0x83,0xFFF,0); // [11:0]: AUXADC_AVG_NUM_SEL; 6/1,Filby,Resolution Adjust
	ret = pmic_config_interface(0xEAA,0x0,0x1,13); // [13:13]: AUXADC_AVG_NUM_SEL_LBAT; 8/3,Filby,Resolution Adjust
	ret = pmic_config_interface(0xEAA,0x1,0x1,15); // [15:15]: AUXADC_AVG_NUM_SEL_WAKEUP; 6/1,Filby,Resolution Adjust
	ret = pmic_config_interface(0xEB2,0x1,0x3,4); // [5:4]: AUXADC_TRIM_CH2_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEB2,0x3,0x3,6); // [7:6]: AUXADC_TRIM_CH3_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEB2,0x1,0x3,8); // [9:8]: AUXADC_TRIM_CH4_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEB2,0x1,0x3,10); // [11:10]: AUXADC_TRIM_CH5_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEB2,0x1,0x3,12); // [13:12]: AUXADC_TRIM_CH6_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEB2,0x2,0x3,14); // [15:14]: AUXADC_TRIM_CH7_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEB4,0x1,0x3,0); // [1:0]: AUXADC_TRIM_CH8_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEB4,0x1,0x3,2); // [3:2]: AUXADC_TRIM_CH9_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEB4,0x1,0x3,4); // [5:4]: AUXADC_TRIM_CH10_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEB4,0x3,0x3,6); // [7:6]: AUXADC_TRIM_CH11_SEL; 6/1,Filby
	ret = pmic_config_interface(0xEC6,0x1,0x1,14); // [14:14]: AUXADC_START_SHADE_EN; TBD(Wei-Lin)
	ret = pmic_config_interface(0xF16,0xC,0x3FF,0); // [9:0]: AUXADC_MDBG_DET_PRD; 10/30, sw.huang
	ret = pmic_config_interface(0xF16,0x0,0x1,15); // [15:15]: AUXADC_MDBG_DET_EN; 10/30, sw.huang
	ret = pmic_config_interface(0xF1C,0xC,0x3FF,0); // [9:0]: AUXADC_MDRT_DET_PRD; 10/30, sw.huang
	ret = pmic_config_interface(0xF1C,0x1,0x1,15); // [15:15]: AUXADC_MDRT_DET_EN; 10/30, sw.huang
	ret = pmic_config_interface(0xF20,0x1,0x1,2); // [2:2]: AUXADC_MDRT_DET_WKUP_EN; 6/2,Dennis
	ret = pmic_config_interface(0xF7A,0xB,0xF,4); // [7:4]: RG_VCDT_HV_VTH; Zax: VCDT_HV_th=7V

	ret = pmic_config_interface(0xF84,0x4,0xF,1); // [4:1]: RG_VBAT_OV_VTH; Zax: 4.45V for 4.35v battery

	ret = pmic_config_interface(0xF92,0x3,0xF,0); // [3:0]: RG_CHRWDT_TD; Zax:WDT=32s
	ret = pmic_config_interface(0xFA0,0x1,0x1,1); // [1:1]: RG_BC11_RST; Zax:Disable BC1.1 timer
	ret = pmic_config_interface(0xFA4,0x0,0x7,4); // [6:4]: RG_CSDAC_STP_DEC; Zax:Reduce ICHG current ripple
	ret = pmic_config_interface(0xFAA,0x1,0x1,2); // [2:2]: RG_CSDAC_MODE; Zax:Align 6323
	ret = pmic_config_interface(0xFAA,0x1,0x1,6); // [6:6]: RG_HWCV_EN; Zax:Align 6323
	ret = pmic_config_interface(0xFAA,0x1,0x1,7); // [7:7]: RG_ULC_DET_EN; Zax: need to enable for supporting bad TA

	dprintf(CRITICAL, "pmic init ret = %u\n", ret);

}

//=============================================
// MD1 PMIC setting
// porting from vmd1_pmic_setting_on(void) in drivers/misc/mediatek/power/mt6763/pmic.c
static void md1_pmic_setting(void)
{
	/*---Configure Modem Related Buck        ---*/
	/*---Configure V_MD1 as 0.7V and HW mode ---*/
	pmic_set_register_value(MT6351_PMIC_BUCK_VMD1_VOSEL_CTRL, 1);
	pmic_set_register_value(MT6351_PMIC_BUCK_VMD1_EN, 1);
	pmic_set_register_value(MT6351_PMIC_BUCK_VMD1_VOSEL_ON, 0x10);
	pmic_set_register_value(MT6351_PMIC_BUCK_VMD1_VSLEEP_EN, 1);

	/*---configure V_MODEM as 0.8V and HW mode---*/
	pmic_set_register_value(MT6351_PMIC_BUCK_VMODEM_VOSEL_CTRL, 1);
	pmic_set_register_value(MT6351_PMIC_BUCK_VMODEM_EN, 1);
	pmic_set_register_value(MT6351_PMIC_BUCK_VMODEM_VOSEL_ON, 0x20);
	pmic_set_register_value(MT6351_PMIC_BUCK_VMODEM_VSLEEP_EN, 1);
}

static void md_power_up_mtcmos(unsigned int boot_md_id)
{
	volatile unsigned int loop = 10000;

	loop =10000;
	while (loop-->0);

	switch (boot_md_id) {
		case MD_SYS1:
#ifdef ENABLE_MD_RESET_SPM
			spm_mtcmos_ctrl_md1(STA_POWER_ON);
#else
			// default on
#endif
			break;
		case MD_SYS3:// MD2
#ifdef ENABLE_MD_RESET_SPM
			spm_mtcmos_ctrl_c2k(STA_POWER_ON);
#else
			// YP Lin will power it on in preloader
#endif
			break;
		default:
			break;
	}
}

int md_common_setting(int boot_md_comb)
{
	unsigned int reg_value;
	// step 3: MD srcclkena setting
	reg_value = *INFRA_AO_MD_SRCCLKENA;
	if ((boot_md_comb&((1<<MD_SYS1)|(1<<MD_SYS3)))==(1<<MD_SYS1)) {
		reg_value &= 0xFF;
		reg_value |= 0x29;
	} else {
		reg_value &= 0x92;
		reg_value |= 0x29;
	}
	*INFRA_AO_MD_SRCCLKENA = reg_value;

	dprintf(CRITICAL, "MD srcclkena setting:0x%x\n", *INFRA_AO_MD_SRCCLKENA);
	return 0;
}


//=============================================
// MD pll init

static void md_pll_on_1()
{
	dprintf(CRITICAL, "MD PLL on 1\n");
	/* Make md1 208M CG off, switch to software mode */
	*((volatile unsigned int *)0x20150020) |= (0x1<<26); /* turn off mdpll1 cg */
	*((volatile unsigned int *)0x20140010) |= (0x1<<16); /* let mdpll on ctrl into software mode */
	*((volatile unsigned int *)0x20140014) |= (0x1<<16); /* let mdpll enable into software mode */
}

static void md_pll_on_2()
{
	dprintf(CRITICAL, "MD PLL on 2\n");
	*((volatile unsigned int *)0x20140010) &= ~(0x1<<16); /* let mdpll on ctrl into hardware mode */
	*((volatile unsigned int *)0x20140014) &= ~(0x1<<16); /* let mdpll enable into hardware mode */
	*((volatile unsigned int *)0x20150020) &= ~(0x1<<26); /* turn on mdpll1 cg */
}


static void md1_pll_on()
{
	/* reset MDPLL1_CON0 to default value */
	*MDPLL1_CON0 = 0x446D12E0;  //Jade 0x2EE8;

	md_pll_on_1();

	/* Turn on 208M */
	*MDPLL1_CON0 |= 0x00000001;
	DRV_WriteReg32(AP_PLL_CON0, (DRV_Reg32(AP_PLL_CON0)|(0x1<<1)));

	udelay(200);

	/* close 208M and autoK */
	*MDPLL1_CON0 &= ~(0x1);
	/* *MDPLL1_CON0 &= ~(0x1<<7); */

	md_pll_on_2();
	/* If MD3 only, do nothing */

	/* set mdpll control by md1 and c2k */
	*MDPLL1_CON0 &= ~(0x1<<9);
}

void md1_pll_init(void)
{

	md1_pll_on();

	//enable L1 permission
	*R_L1_PMS |= 0x7;

	// modify PSMCU2EMI bus divider from 3 to 4.
	*R_PSMCU_AO_CLK_CTL |= 0x82;    //jade :0x83;

	*R_L1MCU_PWR_AWARE |=   (1<<16); //lock dcm bus
	*R_L1AO_PWR_AWARE |=    (1<<16); //lock dcm bus

	*R_BUSL2DCM_CON3  = 0x0000FDE7; //L2DCM L1BUS div 16
	*R_BUSL2DCM_CON3  = 0x1000FDE7; //toggle setting
	*R_L1MCU_DCM_CON  = 0x0001FDE7; // DCM div 8/normal div 1/clkslow_en/ clock from PLL / dcm enable /debounce enable /debounce time 15T
	*R_L1MCU_DCM_CON2 = 0x00000000; //DCM config toggle = 0
	*R_L1MCU_DCM_CON2 = 0x80000000; //DCM config toggle  = 1 / old

	/*Wait PSMCU PLL ready*/
	dprintf(CRITICAL, "Wait PSMCU PLL ready\n");
	while ((*R_PLL_STS & 0x1) !=0x1);           // Bit  0: PSMCUPLL_RDY
	dprintf(CRITICAL, "Got it\n");
	/*Switch clock, 0: 26MHz, 1: PLL*/
	*R_CLKSEL_CTL |= 0x2;

	/*Wait L1MCU PLL ready*/
	dprintf(CRITICAL, "Wait L1MCU PLL ready\n");
	while ((*R_PLL_STS & 0x2) != 0x2);          // Bit  1: L1MCUPLL_RDY
	dprintf(CRITICAL, "Got it\n");
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
	dprintf(CRITICAL, "Wait DFE/IMC PLL ready\n");
	while ((*R_PLL_STS & 0x90) !=0x90);           // Bit  7: DFEPLL_RDY
	// Bit  4: IMCPLL_RDY
	dprintf(CRITICAL, "done\n");

	/*Wait L1SYS clock ready*/
	dprintf(CRITICAL, "Wait L1SYS clock ready\n");
	while ((*R_FLEXCKGEN_STS0 & 0x80800000) != 0x80800000); // Bit  31: EQ_CK_RDY
	// Bit  23: BRP_CK_RDY
	dprintf(CRITICAL, "Done\n");

	dprintf(CRITICAL, "Wait R_FLEXCKGEN_STS1 & 0x80808080 ready\n");
	while ((*R_FLEXCKGEN_STS1 & 0x80808080) != 0x80808080); // Bit  31: DFE_CK_RDY
	// Bit  23: CMP_CK_RDY
	// Bit  15: ICC_CK_RDY
	// Bit  7:  IMC_CK_RDY
	dprintf(CRITICAL, "Done\n");

	dprintf(CRITICAL, "Wait R_FLEXCKGEN_STS2 & 0x8080 ready\n");
	while ((*R_FLEXCKGEN_STS2 & 0x8080) != 0x8080);     // Bit  15: INTF_CK_RDY
	// Bit  23: MD2G_CK_RDY
	dprintf(CRITICAL, "Done\n");

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
	dprintf(CRITICAL, "wait DCM config done\n");
	while ((*R_FLEXCKGEN_STS0 & 0x80) !=0x80);        // Bit  7: BUS_CK_RDY
	dprintf(CRITICAL, "done\n");
	*R_CLKSEL_CTL |=0x1;                                // Bit  1: BUS_CLK = EQPLL/2
}

/*Turn on MD pcore SRAM access permission for AP*/
static void md1_pcore_sram_pms_turn_on(void)
{
	unsigned int val = 0;
	unsigned int base = MD_SRAM_PMS_BASE;

	ccci_write32(base, MD_SRAM_MDSYS_MD_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS1_MD_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS2_MD_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_PSMCUAPB_MD_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDSYS_AP_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS1_AP_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS2_AP_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_PSMCUAPB_AP_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDSYS_TZ_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS1_TZ_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS2_TZ_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_PSMCUAPB_TZ_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDSYS_L1_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS1_L1_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS2_L1_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_PSMCUAPB_L1_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_L1SYS_PMS, 0xFFFF);
	dprintf(CRITICAL, "Enable R_PD_PSMCU_SRAM_PMS(0x%x) access\n",
	        ccci_read32(MD_PERI_MISC_BASE, R_PD_PSMCU_SRAM_PMS));
}

static void md1_pcore_sram_pms_turn_off(void)
{
	unsigned int val = 0;
	unsigned int base = MD_SRAM_PMS_BASE;

	ccci_write32(base, MD_SRAM_MDSYS_MD_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS1_MD_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS2_MD_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_PSMCUAPB_MD_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDSYS_AP_PMS, 0x0008);
	ccci_write32(base, MD_SRAM_MDPERISYS1_AP_PMS, 0x0745);
	ccci_write32(base, MD_SRAM_MDPERISYS2_AP_PMS, 0x003C);
	ccci_write32(base, MD_SRAM_PSMCUAPB_AP_PMS, 0x0064);
	ccci_write32(base, MD_SRAM_MDSYS_TZ_PMS, 0x0008);
	ccci_write32(base, MD_SRAM_MDPERISYS1_TZ_PMS, 0x0745);
	ccci_write32(base, MD_SRAM_MDPERISYS2_TZ_PMS, 0x003C);
	ccci_write32(base, MD_SRAM_PSMCUAPB_TZ_PMS, 0x0064);
	ccci_write32(base, MD_SRAM_MDSYS_L1_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS1_L1_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_MDPERISYS2_L1_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_PSMCUAPB_L1_PMS, 0xFFFF);
	ccci_write32(base, MD_SRAM_L1SYS_PMS, 0x0001);
	dprintf(CRITICAL, "disable R_PD_PSMCU_SRAM_PMS(0x%x) access\n",
	        ccci_read32(MD_PERI_MISC_BASE, R_PD_PSMCU_SRAM_PMS));
}

static void md1_pcore_sram_turn_on(void)
{
	int i;
	unsigned int val, golden_val;
	unsigned int base = MD_SRAM_PD_PSMCUSYS_SRAM_BASE;

	/*Turn on MD pcore SRAM_1(0x200D0114)*/
	golden_val = 0xFFFFFFFF;
	for (i = 31; i >= 0; i--) {
		val = (0xFFFFFFFF >> i) & golden_val;
		ccci_write32(base, MD_SRAM_PD_PSMCUSYS_SRAM_1, val);
	}
	val = ccci_read32(base, MD_SRAM_PD_PSMCUSYS_SRAM_1);
	if (val != golden_val)
		dprintf(CRITICAL, "MD_SRAM_PD_PSMCUSYS_SRAM_1 = 0x%X!= 0xFFFFFFFF\n", val);

	/*Turn on MD pcore SRAM_2(0x200D0118)*/
	golden_val = 0xFFFFFFFF;
	for (i = 31; i >= 0; i--) {
		val = (0xFFFFFFFF >> i) & golden_val;
		ccci_write32(base, MD_SRAM_PD_PSMCUSYS_SRAM_2, val);
	}
	val = ccci_read32(base, MD_SRAM_PD_PSMCUSYS_SRAM_2);
	if (val != golden_val)
		dprintf(CRITICAL, "MD_SRAM_PD_PSMCUSYS_SRAM_2 = 0x%X!= 0xFFFFFFFF\n", val);

	/*Turn on MD pcore SRAM_3(0x200D011C)*/
	golden_val = 0xFFFFFFFF;
	for (i = 31; i >= 0; i--) {
		val = (0xFFFFFFFF >> i) & golden_val;
		ccci_write32(base, MD_SRAM_PD_PSMCUSYS_SRAM_3, val);
	}
	val = ccci_read32(base, MD_SRAM_PD_PSMCUSYS_SRAM_3);
	if (val != golden_val)
		dprintf(CRITICAL, "MD_SRAM_PD_PSMCUSYS_SRAM_3 = 0x%X!= 0xFFFFFFFF\n", val);

	/*Turn on MD pcore SRAM_4(0x200D0120)*/
	golden_val = 0xFFFFFFFA;
	for (i = 31; i >= 0; i--) {
		val = (0xFFFFFFFF >> i) & golden_val;
		ccci_write32(base, MD_SRAM_PD_PSMCUSYS_SRAM_4, val);
	}
	val = ccci_read32(base, MD_SRAM_PD_PSMCUSYS_SRAM_4);
	if (val != golden_val)
		dprintf(CRITICAL, "MD_SRAM_PD_PSMCUSYS_SRAM_4 = 0x%X!= 0xFFFFFFFA\n", val);

}


static void md1_pcore_sram_on(void)
{
	dprintf(CRITICAL, "md1_pcore_sram_on enter\n");
	/*Turn on MD pcore SRAM access permission for AP*/
	md1_pcore_sram_pms_turn_on();

	/*Turn on md pcore sram by AP*/
	md1_pcore_sram_turn_on();

	/*Turn off MD pcore SRAM access permission for AP*/
	md1_pcore_sram_pms_turn_off();
	dprintf(CRITICAL, "md1_pcore_sram_on exit\n");
}


void md1_boot(int boot_mode)
{
	unsigned int reg_value;

	// step 0: PMIC setting
	md1_pmic_setting();
	dprintf(CRITICAL, "md1_pmic_setting done!\n");
	// step 1: Power on MTCMOS
	md_power_up_mtcmos(MD_SYS1);
	dprintf(CRITICAL, "md_power_up_mtcmos done!\n");

	// step 2: RF power,force SRCLKEN_O1 on, request by Yuyang Hsiao
	DRV_WriteReg32(0x10006008, 0x215830);

	// step 3: pll init for both MD, should be after MD1 power on and before MD3 boot
	md1_pll_init();

	// step 4: set META Register
	if (boot_mode) {
		reg_value = DRV_Reg32(0x20000010);
		DRV_WriteReg32(0x20000010, (reg_value |0x1)); // Bit0, Meta mode flag, this need sync with MD init owner
	}

	// step 5: Disabel MD WDT
#if !defined(ENABLE_MD_RESET_SPM) && !defined(ENABLE_MD_RESET_RGU)
	ccci_write32(MD_RGU_BASE, WDT_MD_MODE, WDT_MD_MODE_KEY);    // disable P core watchdog
	ccci_write32(L1_RGU_BASE, REG_L1RSTCTL_WDT_MODE,L1_WDT_MD_MODE_KEY);    // disable L1 core watchdog
#endif

	//step6: pcore sram on
	md1_pcore_sram_on();

}


//===========================================================
void c2k_boot(int boot_mode)
{
	unsigned int reg_value;

#if 1
	/* C2K CONFIG addr: 0x10001360 , Make C2K boot from 0 address at DRAM*/
	reg_value =*C2K_CONFIG;
	reg_value &= (~(7<<8));
	reg_value |= (5<<8);
	*C2K_CONFIG = reg_value;
	dprintf(CRITICAL, "C2K[0x10001360]%x\n", *C2K_CONFIG);
#endif

	/* Power on  C2K MTCMOS */
	/* Turn On SPM Reg Key*/
	spm_write(C2K_POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	spm_write(C2K_PWR_CON, spm_read(C2K_PWR_CON) | PWR_ON);
	spm_write(C2K_PWR_CON, spm_read(C2K_PWR_CON) | PWR_ON_2ND);

	dprintf(CRITICAL, "C2K, wait PWR_SATUS and PWR_STATUS_2ND\n");
	while (!(spm_read(C2K_PWR_STATUS) & C2K_PWR_STA_MASK)
	        || !(spm_read(C2K_PWR_STATUS_2ND) & C2K_PWR_STA_MASK)
	      ); // waiting for power ready
	dprintf(CRITICAL, "wait PWR_SATUS and PWR_STATUS_2ND done\n");

	spm_write(C2K_PWR_CON, spm_read(C2K_PWR_CON) & ~PWR_CLK_DIS);
	spm_write(C2K_PWR_CON, spm_read(C2K_PWR_CON) & ~PWR_ISO);
	spm_write(C2K_PWR_CON, spm_read(C2K_PWR_CON) | PWR_RST_B);

	// release bus protect
	spm_write(INFRA_TOPAXI_PROTECTEN_1, spm_read(INFRA_TOPAXI_PROTECTEN_1) & ~C2K_PROT_MASK);
	while (spm_read(INFRA_TOPAXI_PROTECTSTA1_1) & C2K_PROT_MASK);

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
	dprintf(CRITICAL, "Wait C2K_STATUS\n");
	while (((*C2K_STATUS >> 1) & 0x1) == 0);
	dprintf(CRITICAL, "done\n");
	*C2K_SPM_CTRL &= ~(0x1 << 1);
	*INFRA_TOPAXI_PROTECTEN_1 &= 0xFE3FFFFF;
	/* Waiting for C2KSYS Bus ready for operation */
	dprintf(CRITICAL, "Waiting for C2KSYS Bus ready for operation\n");
	do {
		reg_value = *C2K_CGBR1;
	} while (reg_value != 0xFE8);
	dprintf(CRITICAL, "Done\n");

	/* C2K PLL init */
	*(UINT16P)C2K_C2K_PLL_CON3 = 0x8805; // CPPLL/DSPPLL ISO_EN -> hw mode
	*(UINT16P)C2K_C2K_PLL_CON3 = 0x0005; // CPPLL/DSPPLL PWR_ON -> hw mode
	*(UINT16P)C2K_C2K_PLL_CON3 = 0x0001; // MDPLL1 EN -> hw mode
	*(UINT16P)C2K_C2K_PLL_CON2 = 0x0000; // CPPLL/DSPPLL/C2KPLL_SUBPLL1/2 EN -> hw mode
	*(UINT16P)C2K_C2K_PLLTD_CON0 = 0x0010;//  bp_pll_dly -> 0

	*(UINT16P)C2K_C2K_CPPLL_CON0 |= 1 << 15;
	*(UINT16P)C2K_C2K_DSPPLL_CON0 |= 1 << 15;
	/*  *(UINT16P)C2K_C2K_C2KPLL1_CON0 |= 1 << 15;  */

	/* Wait 20us */
	udelay(20);

	*(UINT16P)C2K_CG_ARM_AMBA_CLKSEL = 0xC124;
	*(UINT16P)C2K_CLK_CTRL4 = 0x8e43;
	*(UINT16P)C2K_CLK_CTRL9 = 0xA207;
}

static void config_md_boot_env(int md_id, int boot_mode)
{

	pmic_init_sequence();
	dprintf(CRITICAL, "pmic_init_sequence done!\n");
	switch (md_id) {
		case MD_SYS1:
			md1_boot(boot_mode);
			break;
		case MD_SYS3:
			c2k_boot(boot_mode);
			break;
		default:
			break;
	}

	// Configure DAP for ICE to connect to MD
	dprintf(CRITICAL, "Configure DAP for ICE to connect to MD!\n");
}

static void let_md_go(int md_id)
{
	unsigned int reg_val;
	switch (md_id) {
		case MD_SYS1:
			// Trigger MD run
			DRV_WriteReg32(MD_BOOT_VECTOR_EN, 1);
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

static void reset_ccirq_reg(void)
{
	int i;
	unsigned int ccirq_base[4];

	dprintf(CRITICAL, "reset CCIRQ\n");
	ccirq_base[0] = L1_C2K_CCIRQ_BASE;
	ccirq_base[1] = C2K_L1_CCIRQ_BASE;
	ccirq_base[2] = PS_C2K_CCIRQ_BASE;
	ccirq_base[3] = C2K_PS_CCIRQ_BASE;
	for (i = 0; i < 2; i++) {
		DRV_WriteReg32(ccirq_base[i] + 0x4, 0xA00000FF);
		DRV_WriteReg32(ccirq_base[i] + 0xC, 0xA00000FF);
	}
	for (i = 2; i < 4; i++) {
		DRV_WriteReg32(ccirq_base[i] + 0x4, 0xA00000FF);
		DRV_WriteReg32(ccirq_base[i] + 0xC, 0xA00000FF);
	}
	for (i = 0; i < 4; i++) {
		DRV_WriteReg32(ccirq_base[i] + 0x40, 0x0);
		DRV_WriteReg32(ccirq_base[i] + 0x44, 0x0);
		DRV_WriteReg32(ccirq_base[i] + 0x48, 0x0);
		DRV_WriteReg32(ccirq_base[i] + 0x4C, 0x0);
	}

}

void md_wdt_irq_handler(unsigned int irq)
{

#if defined(ENABLE_MD_RESET_SPM) || defined(ENABLE_MD_RESET_RGU)
	// update counter
	unsigned int reg_value = 0;
	unsigned int cnt = *(volatile unsigned int *)(TOP_RGU_WDT_NONRST_REG);
	*(volatile unsigned int *)(TOP_RGU_WDT_NONRST_REG) = cnt+1;
	// reset UART config
	md_uart_config(-1, 0);
	dprintf(CRITICAL, "\n\n\n\nCurrent wdt cnt:%d\n", cnt+1);

	if (irq == MT_MD_WDT1_IRQ_ID) {
#ifdef ENABLE_MD_RESET_SPM
		dprintf(CRITICAL, "MD1 power off\n");
		spm_mtcmos_ctrl_md1(STA_POWER_DOWN);
		mdelay(5);
#endif
#ifdef ENABLE_MD_RESET_RGU
		dprintf(CRITICAL, "MD1 reset\n");

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
	dprintf(CRITICAL, "MD2 power off\n");
	spm_mtcmos_ctrl_c2k(STA_POWER_DOWN);
	mdelay(5);

	reset_ccirq_reg();
#endif
#ifdef ENABLE_MD_RESET_RGU
		dprintf(CRITICAL, "MD2 reset\n");
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
	dprintf(CRITICAL, "Config UART after MD WDT! %d\n", cnt+1);
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
	dprintf(CRITICAL, "Get MD WDT irq, STA:%x!!\n", ccci_read32(MD_RGU_BASE, 0xC));
#ifdef IGNORE_MD_WDT
	dprintf(CRITICAL, "ignore MD WDT\n");
#else
	dprintf(CRITICAL, "whole system reboot\n");
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
				dprintf(CRITICAL, "ignore MD1 WDT\n");
#endif
			}
			return 1;
		case MT_MD_WDT2_IRQ_ID:
			if (img_load_flag &(1<<MD_SYS3)) {
#ifndef IGNORE_MD2_WDT
				md_wdt_irq_handler(MT_MD_WDT2_IRQ_ID);
#else
				dprintf(CRITICAL, "ignore MD2 WDT\n");
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
	int boot_mode;
	int i;
	img_load_flag = (unsigned int)md_ld_flag;

	// reinit UART, overwrite DWS setting
	md_uart_config(AP_ONLY, 0);

	// Disable AP WDT
	*(volatile unsigned int *)(TOPRGU_BASE) = 0x22000000;

	dprintf(CRITICAL, "Welcome to use dummy AP!\n");

	// 1, Setup special GPIO request (RF/SIM/UART ... etc)
	dprintf(CRITICAL, "Configure GPIO!\n");
	if ((img_load_flag&((1<<MD_SYS1)|(1<<MD_SYS3))) == ((1<<MD_SYS1)|(1<<MD_SYS3))) {
		md_gpio_config(MD1_MD2);
	} else if (img_load_flag & (1<<MD_SYS1)) {
		md_gpio_config(MD1_ONLY);
	} else if (img_load_flag & (1<<MD_SYS3)) {
		md_gpio_config(MD2_ONLY);
	}

	// 2, Check boot Mode
	boot_mode = meta_detection();

	dprintf(CRITICAL, "Get boot mode is %d\n", boot_mode);

	// 3, MD WDT ISR init
	dprintf(CRITICAL, "Init MD WDT\n");
	md_wdt_init();

	// 4. Common Env setting, srcclk
	md_common_setting(img_load_flag);

	// 5. Setup per-MD env before boot up MD
	for (i=0; i<3; i++) {
		if (img_load_flag & (1<<i)) {
			dprintf(CRITICAL, "MD%d Enabled\n", i+1);
			config_md_boot_env(i, boot_mode);
		}
	}

	// 6, Switch UART
	dprintf(CRITICAL, "Switch UART!\n");
	if ((img_load_flag&((1<<MD_SYS1)|(1<<MD_SYS3))) == ((1<<MD_SYS1)|(1<<MD_SYS3))) {
		md_uart_config(MD1_MD2, boot_mode);
	} else if (img_load_flag & (1<<MD_SYS1)) {
		md_uart_config(MD1_ONLY, boot_mode);
	} else if (img_load_flag & (1<<MD_SYS3)) {
		md_uart_config(MD2_ONLY, boot_mode);
	}

	for (i=0; i<3; i++) {
		if (img_load_flag & (1<<i)) {
			dprintf(CRITICAL, "Trigger MD%d run\n", i+1);
			let_md_go(i);
		}
	}

	dprintf(CRITICAL, "enter while(1), ^O^!!!!!!!!!\n");
	while (1);
}
