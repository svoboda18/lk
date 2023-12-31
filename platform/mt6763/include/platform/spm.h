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

#define SPM_REG(offset)         (SPM_BASE + offset)
#define POWERON_CONFIG_EN           SPM_REG(0x000)
#define PWR_STATUS       SPM_REG(0x0180)
#define PWR_STATUS_2ND       SPM_REG(0x0184)
#define MD_EXTRA_PWR_CON       SPM_REG(0x0398)
#define MD1_PWR_CON       SPM_REG(0x0320)
#define MD_SRAM_ISO_CON     SPM_REG(0x0394)
#define AUDIO_PWR_CON      SPM_REG(0x314)

#define INFRACFG_REG(offset)		(INFRACFG_AO_BASE + offset)
#define INFRA_TOPAXI_PROTECTEN   INFRACFG_REG(0x0220)
#define INFRA_TOPAXI_PROTECTEN_STA1   INFRACFG_REG(0x0228)
#define INFRA_TOPAXI_PROTECTEN_1   INFRACFG_REG(0x0250)
#define INFRA_TOPAXI_PROTECTEN_STA1_1   INFRACFG_REG(0x0258)




#define CKGEN_REG(offset)		(CKSYS_BASE + offset)
#define CLK_MODE   CKGEN_REG(0x0000)

/**************************************
 * Macro and Inline
 **************************************/
#define spm_read(addr)          DRV_Reg32(addr)
#define spm_write(addr, val)        DRV_WriteReg32(addr, val)

#define  SPM_PROJECT_CODE    0xB16

/* Define MTCMOS power control */
#define PWR_RST_B                        (0x1 << 0)
#define PWR_ISO                          (0x1 << 1)
#define PWR_ON                           (0x1 << 2)
#define PWR_ON_2ND                       (0x1 << 3)
#define PWR_CLK_DIS                      (0x1 << 4)
#define SRAM_CKISO                       (0x1 << 5)
#define SRAM_ISOINT_B                    (0x1 << 6)
#define SLPB_CLAMP                       (0x1 << 7)

/* Define MTCMOS Power Status Mask */
#define MD1_PWR_STA_MASK                 (0x1 << 0)
#define AUDIO_PWR_STA_MASK               (0x1 << 24)

/* Define MTCMOS Bus Protect Mask */
#define MD1_PROT_BIT_MASK                ((0x1 << 3) \
					  |(0x1 << 4) \
					  |(0x1 << 7))
#define MD1_PROT_BIT_ACK_MASK            ((0x1 << 3) \
					  |(0x1 << 4) \
					  |(0x1 << 7))
#define MD1_PROT_BIT_2ND_MASK            ((0x1 << 6))
#define MD1_PROT_BIT_ACK_2ND_MASK        ((0x1 << 6))
/* Define Non-CPU SRAM Mask */
#define MD1_SRAM_PDN                     (0x1 << 8)
#define MD1_SRAM_PDN_ACK                 (0x0 << 12)
#define MD1_SRAM_PDN_ACK_BIT0            (0x1 << 12)
#define AUDIO_SRAM_PDN                   (0xF << 8)
#define AUDIO_SRAM_PDN_ACK               (0xF << 12)
#define AUDIO_SRAM_PDN_ACK_BIT0          (0x1 << 12)
#define AUDIO_SRAM_PDN_ACK_BIT1          (0x1 << 13)
#define AUDIO_SRAM_PDN_ACK_BIT2          (0x1 << 14)
#define AUDIO_SRAM_PDN_ACK_BIT3          (0x1 << 15)

#define STA_POWER_DOWN  0
#define STA_POWER_ON    1

extern int spm_mtcmos_ctrl_md1(int state);
extern int spm_mtcmos_ctrl_audio(int state);


#endif
