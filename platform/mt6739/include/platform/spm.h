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

#ifndef _MT_SPM_
#define _MT_SPM_

#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>

#define SPM_BASE SLEEP_BASE
/**************************************
 * Define and Declare
 **************************************/
#define INFRA_TOPAXI_SI0_CTL		INFRACFG_REG(0x0200)
#define INFRA_TOPAXI_PROTECTEN		INFRACFG_REG(0x0220)
#define INFRA_TOPAXI_PROTECTEN_STA0	INFRACFG_REG(0x0224)
#define INFRA_TOPAXI_PROTECTEN_STA1	INFRACFG_REG(0x0228)
#define INFRA_TOPAXI_PROTECTEN_1	INFRACFG_REG(0x0250)
#define INFRA_TOPAXI_PROTECTEN_STA0_1	INFRACFG_REG(0x0254)
#define INFRA_TOPAXI_PROTECTEN_STA1_1	INFRACFG_REG(0x0258)
#define INFRA_TOPAXI_PROTECTEN_SET	INFRACFG_REG(0x02A0)
#define INFRA_TOPAXI_PROTECTEN_CLR	INFRACFG_REG(0x02A4)
#define INFRA_TOPAXI_PROTECTEN_1_SET	INFRACFG_REG(0x02A8)
#define INFRA_TOPAXI_PROTECTEN_1_CLR	INFRACFG_REG(0x02AC)

	/* fix with infra config address */
#define CLK_INFRACFG_BASE		(0x1020e000)
#define SPM_REG(offset)			(SPM_BASE + offset)
#define INFRACFG_REG(offset)		(INFRACFG_AO_BASE + offset)
#define INFRA_REG(offset)		(CLK_INFRACFG_BASE + offset)
#define CKGEN_REG(offset)		(CKSYS_BASE + offset)
#define CLK_MODE			CKGEN_REG(0x0000)
#define INFRA_TOPAXI_SI0_STA		INFRA_REG(0x0000)

/**************************************
 * Macro and Inline
 **************************************/
#define spm_read(addr)          DRV_Reg32(addr)
#define spm_write(addr, val)	DRV_WriteReg32(addr, val)

#define	SPM_PROJECT_CODE	0xB16
#define POWERON_CONFIG_EN	SPM_REG(0x0000)
#define SPM_POWER_ON_VAL0	SPM_REG(0x0004)
#define SPM_POWER_ON_VAL1	SPM_REG(0x0008)
#define PWR_STATUS		SPM_REG(0x0180)
#define PWR_STATUS_2ND		SPM_REG(0x0184)
#define MFG_PWR_CON		SPM_REG(0x338)
#define MFG_CORE0_PWR_CON	SPM_REG(0x33C)
#define MD1_PWR_CON		SPM_REG(0x0320)
#define CONN_PWR_CON		SPM_REG(0x032c)
#define DIS_PWR_CON		SPM_REG(0x030C)
#define ISP_PWR_CON		SPM_REG(0x0308)
#define VCODEC_PWR_CON		SPM_REG(0x0300)
#define MD_EXTRA_PWR_CON	SPM_REG(0x0398)
#define MD_SRAM_ISO_CON		SPM_REG(0x0394)


/* Define MTCMOS power control */
#define PWR_RST_B                        (0x1 << 0)
#define PWR_ISO                          (0x1 << 1)
#define PWR_ON                           (0x1 << 2)
#define PWR_ON_2ND                       (0x1 << 3)
#define PWR_CLK_DIS                      (0x1 << 4)
#define SRAM_CKISO                       (0x1 << 5)
#define MD_PWR_CLK_DIS                   (0x1 << 5)
#define SRAM_ISOINT_B                    (0x1 << 6)
#define SLPB_CLAMP                       (0x1 << 7)


/* Define MTCMOS Power Status Mask */
#define MD1_PWR_STA_MASK                 (0x1 << 0)
#define DIS_PWR_STA_MASK                 (0x1 << 3)

/* Define MTCMOS Bus Protect Mask */
#define MD1_PROT_BIT_MASK		((0x1 << 3) \
					|(0x1 << 4) \
					|(0x1 << 7))
#define MD1_PROT_BIT_ACK_MASK		((0x1 << 3) \
					|(0x1 << 4) \
					|(0x1 << 7))
#define MD1_PROT_BIT_2ND_MASK		((0x1 << 6))
#define MD1_PROT_BIT_ACK_2ND_MASK	((0x1 << 6))

#define DIS_PROT_BIT_MASK		(0x1 << 1)
#define DIS_PROT_BIT_ACK_MASK		(0x1 << 1)

/* Define Non-CPU SRAM Mask */
#define STA_POWER_DOWN		0
#define STA_POWER_ON		1
#define MD1_SRAM_PDN                     (0x1 << 6)
#define MD1_SRAM_PDN_ACK                 (0x0 << 12)
#define MD1_SRAM_PDN_ACK_BIT0            (0x1 << 12)
#define DIS_SRAM_PDN                     (0x1 << 5)
#define DIS_SRAM_PDN_ACK                 (0x1 << 6)
#define DIS_SRAM_PDN_ACK_BIT0            (0x1 << 6)

extern int spm_mtcmos_ctrl_md1(int state);
extern int spm_mtcmos_ctrl_dis(int state);


#endif
