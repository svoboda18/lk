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

#ifndef __MTK_WDT_H__
#define __MTK_WDT_H__

#define ENABLE_WDT_MODULE       (1) // Module switch

/*
 * NO_WDT is defined in rules.mk if DEVELOP_STAGE is set
 * as FPGA.
 */
#ifndef NO_WDT
	#define WDT_ENABLED
#endif


#define MTK_WDT_BASE            TOPRGU_BASE

#define MTK_WDT_MODE            (MTK_WDT_BASE+0x0000)
#define MTK_WDT_LENGTH          (MTK_WDT_BASE+0x0004)
#define MTK_WDT_RESTART         (MTK_WDT_BASE+0x0008)
#define MTK_WDT_STATUS          (MTK_WDT_BASE+0x000C)
#define MTK_WDT_INTERVAL        (MTK_WDT_BASE+0x0010)
#define MTK_WDT_SWRST           (MTK_WDT_BASE+0x0014)
#define MTK_WDT_SWSYSRST        (MTK_WDT_BASE+0x0018)
#define MTK_WDT_NONRST_REG      (MTK_WDT_BASE+0x0020)
#define MTK_WDT_NONRST_REG2     (MTK_WDT_BASE+0x0024)
#define MTK_WDT_REQ_MODE        (MTK_WDT_BASE+0x0030)
#define MTK_WDT_REQ_IRQ_EN      (MTK_WDT_BASE+0x0034)
#define MTK_WDT_DEBUG_CTL       (MTK_WDT_BASE+0x0040)
#define MTK_WDT_LATCH_CTL		(MTK_WDT_BASE+0x0044)


/*WDT_MODE*/
#define MTK_WDT_MODE_KEYMASK        (0xff00)
#define MTK_WDT_MODE_KEY            (0x22000000)

#define MTK_WDT_MODE_DUAL_MODE      (0x0040)
#define MTK_WDT_MODE_IRQ_LEVEL_EN   (0x0020)
#define MTK_WDT_MODE_AUTO_RESTART   (0x0010) /* Reserved */
#define MTK_WDT_MODE_IRQ            (0x0008)
#define MTK_WDT_MODE_EXTEN          (0x0004)
#define MTK_WDT_MODE_EXT_POL        (0x0002)
#define MTK_WDT_MODE_ENABLE         (0x0001)

/*WDT_LENGTH*/
#define MTK_WDT_LENGTH_TIME_OUT     (0xffe0)
#define MTK_WDT_LENGTH_KEYMASK      (0x001f)
#define MTK_WDT_LENGTH_KEY      (0x0008)
#define MTK_WDT_LENGTH_CTL_KEY		(0x95<<24)

/*WDT_RESTART*/
#define MTK_WDT_RESTART_KEY     (0x1971)

/*WDT_STATUS*/
#define MTK_WDT_STATUS_HWWDT_RST    (0x80000000)
#define MTK_WDT_STATUS_SWWDT_RST    (0x40000000)
#define MTK_WDT_STATUS_IRQWDT_RST   (0x20000000)
#define MTK_WDT_STATUS_DEBUGWDT_RST (0x00080000)
#define MTK_WDT_STATUS_SPMWDT_RST   (0x0001)

/*WDT_INTERVAL*/
#define MTK_WDT_INTERNAL_KEY        (0x66000000)
#define MTK_WDT_INTERVAL_MASK       (0x0fff)

/*WDT_SWRST*/
#define MTK_WDT_SWRST_KEY       (0x1209)

/*WDT_SWSYSRST*/
#define MTK_WDT_SWSYS_RST_PWRAP_SPI_CTL_RST (0x0800)
#define MTK_WDT_SWSYS_RST_APMIXED_RST   (0x0400)
#define MTK_WDT_SWSYS_RST_MD_LITE_RST   (0x0200)
#define MTK_WDT_SWSYS_RST_INFRA_AO_RST  (0x0100)
#define MTK_WDT_SWSYS_RST_MD_RST    (0x0080)
#define MTK_WDT_SWSYS_RST_DDRPHY_RST    (0x0040)
#define MTK_WDT_SWSYS_RST_IMG_RST   (0x0020)
#define MTK_WDT_SWSYS_RST_VDEC_RST  (0x0010)
#define MTK_WDT_SWSYS_RST_VENC_RST  (0x0008)
#define MTK_WDT_SWSYS_RST_MFG_RST   (0x0004)
#define MTK_WDT_SWSYS_RST_DISP_RST  (0x0002)
#define MTK_WDT_SWSYS_RST_INFRA_RST (0x0001)
#define MTK_WDT_SWSYS_RST_KEY       (0x88000000)

/* Reboot source */
#define RGU_STAGE_MASK      (0x3)
#define RGU_STAGE_PRELOADER (0x1)
#define RGU_STAGE_LK        (0x2)
#define RGU_STAGE_KERNEL    (0x3)

/* WDT_NONRST_REG2 */
#define MTK_WDT_NONRST2_SSPM_RESET     (1 << 0)
#define MTK_WDT_NONRST2_STAGE_OFS      (30) /* 31:30: 2-bits for current stage */
#define MTK_WDT_NONRST2_LAST_STAGE_OFS (28) /* 29:28: 2-bits for last stage */
/* used for DA tool to enter fastboot via setting rgu bit */
#ifdef MTK_ENTER_FASTBOOT_VIA_RGU
	#define MTK_WDT_NONRST2_FASTBOOT (1 << 2)
#endif

/*MTK_WDT_REQ_IRQ*/
#define MTK_WDT_REQ_IRQ_KEY     (0x44000000)
#define MTK_WDT_REQ_IRQ_DEBUG_EN        (0x80000)
#define MTK_WDT_REQ_IRQ_SPM_THERMAL_EN      (0x0001)
#define MTK_WDT_REQ_IRQ_SPM_SCPSYS_EN       (0x0002)
#define MTK_WDT_REQ_IRQ_THERMAL_EN      (1<<18)

/*MTK_WDT_REQ_MODE*/
#define MTK_WDT_REQ_MODE_KEY        (0x33000000)
#define MTK_WDT_REQ_MODE_DEBUG_EN       (0x80000)
#define MTK_WDT_REQ_MODE_SPM_THERMAL        (0x0001)
#define MTK_WDT_REQ_MODE_SPM_SCPSYS     (0x0002)
#define MTK_WDT_REQ_MODE_THERMAL        (1<<18)

//MTK_WDT_DEBUG_CTL
#define MTK_DEBUG_CTL_KEY           (0x59000000)
#define MTK_RG_MCU_PWR_ON           (0x1000)
#define MTK_RG_MCU_PWR_ISO_DIS      (0x2000)

#define WDT_NORMAL_REBOOT       (0x01)
#define WDT_BY_PASS_PWK_REBOOT      (0x02)
#define WDT_NOT_WDT_REBOOT      (0x00)

typedef enum wd_swsys_reset_type {
	WD_MD_RST,
} WD_SYS_RST_TYPE;


void        mtk_wdt_disable(void);
const char *mtk_wdt_get_last_stage(void);
void        mtk_wdt_restart(void);
extern void mtk_wdt_init(void);
extern BOOL mtk_is_rgu_trigger_reset(void);
extern void mtk_arch_reset(char mode);
extern void mtk_arch_full_reset(void);
void        rgu_swsys_reset(WD_SYS_RST_TYPE reset_type);
void        rgu_release_rg_mcu_pwr_on(void);
void        rgu_release_rg_mcu_pwr_iso_dis(void);

#ifdef MTK_ENTER_FASTBOOT_VIA_RGU
int         mtk_wdt_fastboot_check(void); /* return value, 1: fastboot mode */
void        mtk_wdt_fastboot_set(int fastboot_en);
#endif

#endif   /*__MTK_WDT_H__*/
