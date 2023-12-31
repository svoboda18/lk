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

#include <platform/mt_typedefs.h>

#define STA_POWER_DOWN	0
#define STA_POWER_ON	1

#define SPM_BASE		(0x10006000)
#define INFRACFG_AO_BASE	(0x10001000)
#define SMI_COMMON_BASE		(0x14019000)
#define INFRACFG_BASE		(0x1020E000)
#define SPM_REG(offset)         	(SPM_BASE + offset)
#define INFRACFG_REG(offset)		(INFRACFG_AO_BASE + offset)
#define SMI_COMMON_REG(offset)		(SMI_COMMON_BASE + offset)
#define INFRA_REG(offset)		(INFRACFG_BASE + offset)


#define POWERON_CONFIG_EN	SPM_REG(0x0000)
#define PWR_STATUS		SPM_REG(0x0160)
#define PWR_STATUS_2ND		SPM_REG(0x0164)

#define MD1_PWR_CON	SPM_REG(0x318)
#define CONN_PWR_CON	SPM_REG(0x320)

#define DIS_PWR_CON	SPM_REG(0x030C)
#define VEN_PWR_CON	SPM_REG(0x0304)
#define VDE_PWR_CON	SPM_REG(0x0300)
#define CAM_PWR_CON	SPM_REG(0x0324)
#define ISP_PWR_CON	SPM_REG(0x0308)
#define IPE_PWR_CON	SPM_REG(0x0350)

#define AUDIO_PWR_CON	SPM_REG(0x031C)
#define MFG0_PWR_CON	SPM_REG(0x328)
#define MFG1_PWR_CON	SPM_REG(0x32C)
#define MFG2_PWR_CON	SPM_REG(0x330)
#define MFG3_PWR_CON	SPM_REG(0x334)
#define MFG4_PWR_CON	SPM_REG(0x338)

#define VPU_VCORE_PWR_CON	SPM_REG(0x33C)
#define VPU_CONN_PWR_CON	SPM_REG(0x340)
#define VPU_CORE0_PWR_CON	SPM_REG(0x344)
#define VPU_CORE1_PWR_CON	SPM_REG(0x348)
#define VPU_CORE2_PWR_CON	SPM_REG(0x34C)

#define VPU_VCORE_SRAM_CON	SPM_REG(0x380)
#define VPU_CONN_SRAM_CON	SPM_REG(0x384)
#define VPU_CORE0_SRAM_CON	SPM_REG(0x388)
#define VPU_CORE1_SRAM_CON	SPM_REG(0x38C)
#define VPU_CORE2_SRAM_CON	SPM_REG(0x38C)

#define VPU_CORE0_SRAM_STA	SPM_REG(0x398)
#define VPU_CORE1_SRAM_STA	SPM_REG(0x39C)
#define VPU_CORE2_SRAM_STA	SPM_REG(0x3A0)

#define MD_EXT_BUCK_ISO_CON	SPM_REG(0x3B0)
#define EXT_BUCK_ISO		SPM_REG(0x3B4)

#define INFRA_TOPAXI_SI0_CTL		INFRACFG_REG(0x0200)
#define INFRA_TOPAXI_SI0_CTL_SET	INFRACFG_REG(0x03B8)
#define INFRA_TOPAXI_SI0_CTL_CLR	INFRACFG_REG(0x03BC)

#define INFRA_TOPAXI_SI2_CTL	INFRACFG_REG(0x0234)
#define INFRA_TOPAXI_PROTECTEN		INFRACFG_REG(0x0220)
#define INFRA_TOPAXI_PROTECTEN_STA0	INFRACFG_REG(0x0224)
#define INFRA_TOPAXI_PROTECTEN_STA1	INFRACFG_REG(0x0228)
#define INFRA_TOPAXI_PROTECTEN_1   INFRACFG_REG(0x0250)
#define INFRA_TOPAXI_PROTECTEN_STA0_1 INFRACFG_REG(0x0254)
#define INFRA_TOPAXI_PROTECTEN_STA1_1 INFRACFG_REG(0x0258)

#define INFRA_TOPAXI_PROTECTEN_2_SET	INFRACFG_REG(0x0714)
#define INFRA_TOPAXI_PROTECTEN_2_CLR	INFRACFG_REG(0x0718)
#define INFRA_TOPAXI_PROTECTEN_STA1_2	INFRACFG_REG(0x0724)


#define INFRA_TOPAXI_PROTECTEN_SET	INFRACFG_REG(0x02A0)
#define INFRA_TOPAXI_PROTECTEN_CLR	INFRACFG_REG(0x02A4)
#define INFRA_TOPAXI_PROTECTEN_1_SET	INFRACFG_REG(0x02A8)
#define INFRA_TOPAXI_PROTECTEN_1_CLR	INFRACFG_REG(0x02AC)

#define INFRA_TOPAXI_PROTECTEN_MM	INFRACFG_REG(0x02D0)
#define INFRA_TOPAXI_PROTECTEN_MM_SET	INFRACFG_REG(0x02D4)
#define INFRA_TOPAXI_PROTECTEN_MM_CLR	INFRACFG_REG(0x02D8)
#define INFRA_TOPAXI_PROTECTEN_MM_STA0	INFRACFG_REG(0x02E8)
#define INFRA_TOPAXI_PROTECTEN_MM_STA1	INFRACFG_REG(0x02EC)

#define INFRA_TOPAXI_PROTECTEN_MCU_SET	INFRACFG_REG(0x02C4)
#define INFRA_TOPAXI_PROTECTEN_MCU_CLR	INFRACFG_REG(0x02C8)
#define INFRA_TOPAXI_PROTECTEN_MCU_STA0	INFRACFG_REG(0x02E0)
#define INFRA_TOPAXI_PROTECTEN_MCU_STA1	INFRACFG_REG(0x02E4)
/* INFRACFG */
#define INFRA_TOPAXI_SI0_STA		INFRA_REG(0x0000)
#define INFRA_TOPAXI_SI2_STA		INFRA_REG(0x0028)
/* SMI LARB */

/* SMI COMMON */
#define SMI_COMMON_SMI_CLAMP	SMI_COMMON_REG(0x03C0)
#define SMI_COMMON_SMI_CLAMP_SET	SMI_COMMON_REG(0x03C4)
#define SMI_COMMON_SMI_CLAMP_CLR	SMI_COMMON_REG(0x03C8)


#define  SPM_PROJECT_CODE    0xB16

/* Define MBIST EFUSE control */

/* Define MTCMOS power control */
#define PWR_RST_B                        (0x1 << 0)
#define PWR_ISO                          (0x1 << 1)
#define PWR_ON                           (0x1 << 2)
#define PWR_ON_2ND                       (0x1 << 3)
#define PWR_CLK_DIS                      (0x1 << 4)
#define SRAM_CKISO                       (0x1 << 5)
#define SRAM_ISOINT_B                    (0x1 << 6)
#define DORMANT_ENABLE                   (0x1 << 6)
#define SLPB_CLAMP                       (0x1 << 7)


/* Define MTCMOS Bus Protect Mask */
#define MD1_PROT_STEP1_0_MASK            ((0x1 << 7))
#define MD1_PROT_STEP1_0_ACK_MASK        ((0x1 << 7))
#define MD1_PROT_STEP2_0_MASK            ((0x1 << 3) \
					  |(0x1 << 4))
#define MD1_PROT_STEP2_0_ACK_MASK        ((0x1 << 3) \
					  |(0x1 << 4))
#define MD1_PROT_STEP2_1_MASK            ((0x1 << 6))
#define MD1_PROT_STEP2_1_ACK_MASK        ((0x1 << 6))
#define DIS_PROT_STEP1_0_MASK            ((0x1 << 0) \
					  |(0x1 << 1) \
					  |(0x1 << 3) \
					  |(0x1 << 4) \
					  |(0x1 << 5) \
					  |(0x1 << 6))
#define DIS_PROT_STEP1_0_ACK_MASK        ((0x1 << 0) \
					  |(0x1 << 1) \
					  |(0x1 << 3) \
					  |(0x1 << 4) \
					  |(0x1 << 5) \
					  |(0x1 << 6))
#define DIS_PROT_STEP2_0_MASK            ((0x1 << 0) \
					  |(0x1 << 1) \
					  |(0x1 << 2) \
					  |(0x1 << 3) \
					  |(0x1 << 4) \
					  |(0x1 << 5) \
					  |(0x1 << 6) \
					  |(0x1 << 7))
#define DIS_PROT_STEP2_0_ACK_MASK        ((0x1 << 0) \
					  |(0x1 << 1) \
					  |(0x1 << 2) \
					  |(0x1 << 3) \
					  |(0x1 << 4) \
					  |(0x1 << 5) \
					  |(0x1 << 6) \
					  |(0x1 << 7))
#define DIS_PROT_STEP3_0_MASK            ((0x1 << 16) \
					  |(0x1 << 17))
#define DIS_PROT_STEP3_0_ACK_MASK        ((0x1 << 16) \
					  |(0x1 << 17))
#define DIS_PROT_STEP4_0_MASK            ((0x1 << 10) \
					  |(0x1 << 11))
#define DIS_PROT_STEP4_0_ACK_MASK        ((0x1 << 10) \
					  |(0x1 << 11))
#define DIS_PROT_STEP5_0_MASK            ((0x1 << 6))
#define DIS_PROT_STEP5_0_ACK_MASK        ((0x1 << 6))



/* Define MTCMOS Power Status Mask */

#define MD1_PWR_STA_MASK                 (0x1 << 0)
#define DIS_PWR_STA_MASK                 (0x1 << 3)


/* Define CPU SRAM Mask */

/* Define Non-CPU SRAM Mask */
#define DIS_SRAM_PDN                     (0x1 << 8)
#define DIS_SRAM_PDN_ACK                 (0x1 << 12)
#define DIS_SRAM_PDN_ACK_BIT0            (0x1 << 12)




/**************************************
 * Macro and Inline
 **************************************/
#define spm_read(addr)          DRV_Reg32(addr)
#define spm_write(addr, val)    DRV_WriteReg32(addr, val)

extern int spm_mtcmos_ctrl_md1(int state);
extern int spm_mtcmos_ctrl_dis(int state);

#endif
