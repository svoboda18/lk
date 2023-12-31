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

#ifndef _DDP_REG_DSI_H_
#define _DDP_REG_DSI_H_

/* from CODA */
static unsigned long const DSI_REG_BASE[2] = {DISPSYS_DSI0_BASE, DISPSYS_DSI1_BASE};

/* DSI */
#define DISP_REG_DSI_START                  (0x000UL)
#define DSI_START_FLD_VM_CMD_START                             REG_FLD_MSB_LSB(16, 16)
#define DSI_START_FLD_SKEWCAL_START                            REG_FLD_MSB_LSB(4, 4)
#define DSI_START_FLD_SLEEPOUT_START                           REG_FLD_MSB_LSB(2, 2)
#define DSI_START_FLD_DSI_START                                REG_FLD_MSB_LSB(0, 0)

#define DISP_REG_DSI_STATUS                 (0x004UL)
#define DISP_REG_DSI_INTEN                  (0x008UL)
#define DSI_INTEN_FLD_SLEEPIN_ULPS_EVENT_EN                    REG_FLD_MSB_LSB(31, 31)
#define DSI_INTEN_FLD_INP_UNFINISH_EVENT_EN                    REG_FLD_MSB_LSB(30, 30)
#define DSI_INTEN_FLD_BTA_TIMEOUT_EVENT_EN                     REG_FLD_MSB_LSB(29, 29)
#define DSI_INTEN_FLD_BUFFER_UNDERRUN_EVENT_EN                 REG_FLD_MSB_LSB(28, 28)
#define DSI_INTEN_FLD_SKEWCAL_DONE_EVENT_EN                    REG_FLD_MSB_LSB(27, 27)
#define DSI_INTEN_FLD_VM_VFP_STR_EVENT_EN                      REG_FLD_MSB_LSB(26, 26)
#define DSI_INTEN_FLD_VM_VACT_STR_EVENT_EN                     REG_FLD_MSB_LSB(25, 25)
#define DSI_INTEN_FLD_VM_VBP_STR_EVENT_EN                      REG_FLD_MSB_LSB(24, 24)
#define DSI_INTEN_FLD_TE_TIMEOUT_EVENT_EN                      REG_FLD_MSB_LSB(23, 23)
#define DSI_INTEN_FLD_SLEEPOUT_DONE_EVENT_EN                   REG_FLD_MSB_LSB(22, 22)
#define DSI_INTEN_FLD_VM_CMD_DONE_EVENT_EN                     REG_FLD_MSB_LSB(21, 21)
#define DSI_INTEN_FLD_FRAME_DONE_EVENT_EN                      REG_FLD_MSB_LSB(20, 20)
#define DSI_INTEN_FLD_VM_DONE_EVENT_EN                         REG_FLD_MSB_LSB(19, 19)
#define DSI_INTEN_FLD_TE_RDY_EVENT_EN                          REG_FLD_MSB_LSB(18, 18)
#define DSI_INTEN_FLD_CMD_DONE_EVENT_EN                        REG_FLD_MSB_LSB(17, 17)
#define DSI_INTEN_FLD_LPRX_RD_RDY_EVENT_EN                     REG_FLD_MSB_LSB(16, 16)
#define DSI_INTEN_FLD_SLEEPIN_ULPS_INT_EN                      REG_FLD_MSB_LSB(15, 15)
#define DSI_INTEN_FLD_INP_UNFINISH_INT_EN                      REG_FLD_MSB_LSB(14, 14)
#define DSI_INTEN_FLD_BTA_TIMEOUT_INT_EN                       REG_FLD_MSB_LSB(13, 13)
#define DSI_INTEN_FLD_BUFFER_UNDERRUN_INT_EN                   REG_FLD_MSB_LSB(12, 12)
#define DSI_INTEN_FLD_SKEWCAL_DONE_INT_EN                      REG_FLD_MSB_LSB(11, 11)
#define DSI_INTEN_FLD_VM_VFP_STR_INT_EN                        REG_FLD_MSB_LSB(10, 10)
#define DSI_INTEN_FLD_VM_VACT_STR_INT_EN                       REG_FLD_MSB_LSB(9, 9)
#define DSI_INTEN_FLD_VM_VBP_STR_INT_EN                        REG_FLD_MSB_LSB(8, 8)
#define DSI_INTEN_FLD_TE_TIMEOUT_INT_EN                        REG_FLD_MSB_LSB(7, 7)
#define DSI_INTEN_FLD_SLEEPOUT_DONE_INT_EN                     REG_FLD_MSB_LSB(6, 6)
#define DSI_INTEN_FLD_VM_CMD_DONE_INT_EN                       REG_FLD_MSB_LSB(5, 5)
#define DSI_INTEN_FLD_FRAME_DONE_INT_EN                        REG_FLD_MSB_LSB(4, 4)
#define DSI_INTEN_FLD_VM_DONE_INT_EN                           REG_FLD_MSB_LSB(3, 3)
#define DSI_INTEN_FLD_TE_RDY_INT_EN                            REG_FLD_MSB_LSB(2, 2)
#define DSI_INTEN_FLD_CMD_DONE_INT_EN                          REG_FLD_MSB_LSB(1, 1)
#define DSI_INTEN_FLD_LPRX_RD_RDY_INT_EN                       REG_FLD_MSB_LSB(0, 0)



#define DISP_REG_DSI_INTSTA                 (0x00CUL)
#define DSI_INTSTA_FLD_DSI_BUSY                                REG_FLD_MSB_LSB(31, 31)
#define DSI_INTSTA_FLD_SLEEPIN_ULPS_INT_EN_FLAG                REG_FLD_MSB_LSB(15, 15)
#define DSI_INTSTA_FLD_INP_UNFINISH_INT_EN_FLAG                REG_FLD_MSB_LSB(14, 14)
#define DSI_INTSTA_FLD_BTA_TIMEOUT_INT_EN_FLAG                 REG_FLD_MSB_LSB(13, 13)
#define DSI_INTSTA_FLD_BUFFER_UNDERRUN_INT_FLAG                REG_FLD_MSB_LSB(12, 12)
#define DSI_INTSTA_FLD_SKEWCAL_DONE_INT_FLAG                   REG_FLD_MSB_LSB(11, 11)
#define DSI_INTSTA_FLD_VM_VFP_STR_INT_FLAG                     REG_FLD_MSB_LSB(10, 10)
#define DSI_INTSTA_FLD_VM_VACT_STR_INT_FLAG                    REG_FLD_MSB_LSB(9, 9)
#define DSI_INTSTA_FLD_VM_VBP_STR_INT_FLAG                     REG_FLD_MSB_LSB(8, 8)
#define DSI_INTSTA_FLD_TE_TIMEOUT_INT_FLAG                     REG_FLD_MSB_LSB(7, 7)
#define DSI_INTSTA_FLD_SLEEPOUT_DONE_INT_FLAG                  REG_FLD_MSB_LSB(6, 6)
#define DSI_INTSTA_FLD_VM_CMD_DONE_INT_FLAG                    REG_FLD_MSB_LSB(5, 5)
#define DSI_INTSTA_FLD_FRAME_DONE_INT_FLAG                     REG_FLD_MSB_LSB(4, 4)
#define DSI_INTSTA_FLD_VM_DONE_INT_FLAG                        REG_FLD_MSB_LSB(3, 3)
#define DSI_INTSTA_FLD_TE_RDY_INT_FLAG                         REG_FLD_MSB_LSB(2, 2)
#define DSI_INTSTA_FLD_CMD_DONE_INT_FLAG                       REG_FLD_MSB_LSB(1, 1)
#define DSI_INTSTA_FLD_LPRX_RD_RDY_INT_FLAG                    REG_FLD_MSB_LSB(0, 0)


#define DISP_REG_DSI_COM_CON                (0x010UL)
#define DSI_COM_CON_FLD_DSI_DUAL_EN                            REG_FLD_MSB_LSB(4, 4)
#define DSI_COM_CON_FLD_DPHY_RESET                             REG_FLD_MSB_LSB(2, 2)
#define DSI_COM_CON_FLD_DSI_RESET                              REG_FLD_MSB_LSB(0, 0)


#define DISP_REG_DSI_MODE_CON               (0x014UL)
#define DSI_MODE_CON_FLD_SLEEP_MODE                            REG_FLD_MSB_LSB(20, 20)
#define DSI_MODE_CON_FLD_C2V_SWITCH_ON                         REG_FLD_MSB_LSB(19, 19)
#define DSI_MODE_CON_FLD_V2C_SWITCH_ON                         REG_FLD_MSB_LSB(18, 18)
#define DSI_MODE_CON_FLD_MIX_MODE                              REG_FLD_MSB_LSB(17, 17)
#define DSI_MODE_CON_FLD_FRAME_MODE                            REG_FLD_MSB_LSB(16, 16)
#define DSI_MODE_CON_FLD_INTERLACE_MODE                        REG_FLD_MSB_LSB(9, 8)
#define DSI_MODE_CON_FLD_MODE_CON                              REG_FLD_MSB_LSB(1, 0)


#define DISP_REG_DSI_TXRX_CON               (0x018UL)
#define DSI_TXRX_CON_FLD_BTA_TIMEOUT_CHK_EN                    REG_FLD_MSB_LSB(29, 29)
#define DSI_TXRX_CON_FLD_LP_ONLY_VBLK                          REG_FLD_MSB_LSB(28, 28)
#define DSI_TXRX_CON_FLD_RGB_PKT_CNT                           REG_FLD_MSB_LSB(27, 24)
#define DSI_TXRX_CON_FLD_EXT_TE_TIME_VM                        REG_FLD_MSB_LSB(23, 20)
#define DSI_TXRX_CON_FLD_TE_TIMEOUT_CHK_EN                     REG_FLD_MSB_LSB(19, 19)
#define DSI_TXRX_CON_FLD_TE_WITH_CMD_EN                        REG_FLD_MSB_LSB(18, 18)
#define DSI_TXRX_CON_FLD_TYPE1_BTA_SEL                         REG_FLD_MSB_LSB(17, 17)
#define DSI_TXRX_CON_FLD_HSTX_CKLP_EN                          REG_FLD_MSB_LSB(16, 16)
#define DSI_TXRX_CON_FLD_MAX_RTN_SIZE                          REG_FLD_MSB_LSB(15, 12)
#define DSI_TXRX_CON_FLD_TE_AUTO_SYNC                          REG_FLD_MSB_LSB(11, 11)
#define DSI_TXRX_CON_FLD_EXT_TE_EDGE_SEL                       REG_FLD_MSB_LSB(10, 10)
#define DSI_TXRX_CON_FLD_EXT_TE_EN                             REG_FLD_MSB_LSB(9, 9)
#define DSI_TXRX_CON_FLD_TE_FREERUN                            REG_FLD_MSB_LSB(8, 8)
#define DSI_TXRX_CON_FLD_HSTX_BLLP_EN                          REG_FLD_MSB_LSB(7, 7)
#define DSI_TXRX_CON_FLD_HSTX_DIS_EOT                          REG_FLD_MSB_LSB(6, 6)
#define DSI_TXRX_CON_FLD_LANE_NUM                              REG_FLD_MSB_LSB(5, 2)
#define DSI_TXRX_CON_FLD_VC_NUM                                REG_FLD_MSB_LSB(1, 0)


#define DISP_REG_DSI_PSCON                  (0x01CUL)
#define DSI_PSCON_FLD_CUSTOM_HEADER                            REG_FLD_MSB_LSB(31, 26)
#define DSI_PSCON_FLD_BYTE_SWAP                                REG_FLD_MSB_LSB(25, 25)
#define DSI_PSCON_FLD_RGB_SWAP                                 REG_FLD_MSB_LSB(24, 24)
#define DSI_PSCON_FLD_DSI_PS_SEL                               REG_FLD_MSB_LSB(18, 16)
#define DSI_PSCON_FLD_DSI_PS_WC                                REG_FLD_MSB_LSB(14, 0)


#define DISP_REG_DSI_VSA_NL                 (0x020UL)
#define DISP_REG_DSI_VBP_NL                 (0x024UL)
#define DISP_REG_DSI_VFP_NL                 (0x028UL)
#define DISP_REG_DSI_VACT_NL                (0x02CUL)
#define DSI_VACT_NL_FLD_VACT_NL                                REG_FLD_MSB_LSB(14, 0)


#define DISP_REG_DSI_LFR_CON                (0x030UL)
#define DSI_LFR_CON_FLD_DSI_LFR_SKIP_NUM                       REG_FLD_MSB_LSB(13, 8)
#define DSI_LFR_CON_FLD_DSI_LFR_VSE_DIS                        REG_FLD_MSB_LSB(6, 6)
#define DSI_LFR_CON_FLD_DSI_LFR_UPDATE                         REG_FLD_MSB_LSB(5, 5)
#define DSI_LFR_CON_FLD_DSI_LFR_EN                             REG_FLD_MSB_LSB(4, 4)
#define DSI_LFR_CON_FLD_DSI_LFR_TYPE                           REG_FLD_MSB_LSB(3, 2)
#define DSI_LFR_CON_FLD_DSI_LFR_MODE                           REG_FLD_MSB_LSB(1, 0)


#define DISP_REG_DSI_LFR_STA                (0x034UL)
#define DISP_REG_DSI_SIZE_CON               (0x038UL)
#define DISP_REG_DSI_VFP_EARLY_STOP         (0x03CUL)
#define DISP_REG_DSI_HSA_WC                 (0x050UL)
#define DSI_HSA_WC_FLD_DSI_HSA_WC                              REG_FLD_MSB_LSB(11, 0)

#define DISP_REG_DSI_HBP_WC                 (0x054UL)
#define DSI_HBP_WC_FLD_DSI_HBP_WC                              REG_FLD_MSB_LSB(11, 0)

#define DISP_REG_DSI_HFP_WC                 (0x058UL)
#define DSI_HFP_WC_FLD_DSI_HFP_WC                              REG_FLD_MSB_LSB(11, 0)

#define DISP_REG_DSI_BLLP_WC                (0x05CUL)
#define DSI_BLLP_WC_FLD_DSI_BLLP_WC                            REG_FLD_MSB_LSB(11, 0)

#define DISP_REG_DSI_CMDQ_CON               (0x060UL)
#define DISP_REG_DSI_HSTX_CKLP_WC             (0x064UL)
#define DISP_REG_DSI_HSTX_CKLP_WC_AUTO_RESULT (0x068UL)
#define DISP_REG_DSI_RX_DATA03               (0x074UL)
#define DISP_REG_DSI_RX_DATA47               (0x078UL)
#define DISP_REG_DSI_RX_DATA8B               (0x07CUL)
#define DISP_REG_DSI_RX_DATAC                (0x080UL)
#define DISP_REG_DSI_RX_RACK                 (0x084UL)
#define DSI_RX_RACK_FLD_RACK_BYPASS                            REG_FLD_MSB_LSB(1, 1)
#define DSI_RX_RACK_FLD_RACK                                   REG_FLD_MSB_LSB(0, 0)


#define DISP_REG_DSI_RX_TRIG_STA             (0x088UL)
#define DISP_REG_DSI_MEM_CONTI               (0x090UL)
#define DISP_REG_DSI_FRM_BC                  (0x094UL)
#define DISP_REG_DSI_V3D_CON                 (0x098UL)
#define DISP_REG_DSI_TIME_CON0               (0x0A0UL)
#define DSI_TIME_CON0_FLD_SKEWCAL_PRD                          REG_FLD_MSB_LSB(31, 16)
#define DSI_TIME_CON0_FLD_ULPS_WAKEUP_PRD                      REG_FLD_MSB_LSB(15, 0)


#define DISP_REG_DSI_TIME_CON1               (0x0A4UL)
#define DISP_REG_DSI_TIME_CON2               (0x0A8UL)
#define DISP_REG_DSI_RESERVED                (0x0F0UL)
#define DISP_REG_DSI_PHY_LCPAT               (0x100UL)


#define DISP_REG_DSI_PHY_LCCON               (0x104UL)
#define DSI_PHY_LCCON_FLD_EARLY_HS_POE                         REG_FLD_MSB_LSB(20, 16)
#define DSI_PHY_LCCON_FLD_EARLY_DRDY                           REG_FLD_MSB_LSB(12, 8)
#define DSI_PHY_LCCON_FLD_TRAIL_FIX                            REG_FLD_MSB_LSB(3, 3)
#define DSI_PHY_LCCON_FLD_LC_WAKEUP_EN                         REG_FLD_MSB_LSB(2, 2)
#define DSI_PHY_LCCON_FLD_LC_ULPM_EN                           REG_FLD_MSB_LSB(1, 1)
#define DSI_PHY_LCCON_FLD_LC_HSTX_EN                           REG_FLD_MSB_LSB(0, 0)

#define DISP_REG_DSI_PHY_LD0CON              (0x108UL)
#define DSI_PHY_LD0CON_FLD_L0_RX_FILTER_EN                     REG_FLD_MSB_LSB(4, 4)
#define DSI_PHY_LD0CON_FLD_LX_ULPM_AS_L0                       REG_FLD_MSB_LSB(3, 3)
#define DSI_PHY_LD0CON_FLD_L0_WAKEUP_EN                        REG_FLD_MSB_LSB(2, 2)
#define DSI_PHY_LD0CON_FLD_L0_ULPM_EN                          REG_FLD_MSB_LSB(1, 1)
#define DSI_PHY_LD0CON_FLD_L0_RM_TRIG_EN                       REG_FLD_MSB_LSB(0, 0)

#define DISP_REG_DSI_PHY_SYNCON              (0x10CUL)


#define DISP_REG_DSI_PHY_TIMCON0             (0x110UL)
#define DSI_PHY_TIMCON0_FLD_DA_HS_TRAIL                        REG_FLD_MSB_LSB(31, 24)
#define DSI_PHY_TIMCON0_FLD_DA_HS_ZERO                         REG_FLD_MSB_LSB(23, 16)
#define DSI_PHY_TIMCON0_FLD_DA_HS_PREP                         REG_FLD_MSB_LSB(15, 8)
#define DSI_PHY_TIMCON0_FLD_LPX                                REG_FLD_MSB_LSB(7, 0)


#define DISP_REG_DSI_PHY_TIMCON1             (0x114UL)
#define DSI_PHY_TIMCON1_FLD_DA_HS_EXIT                         REG_FLD_MSB_LSB(31, 24)
#define DSI_PHY_TIMCON1_FLD_TA_GET                             REG_FLD_MSB_LSB(23, 16)
#define DSI_PHY_TIMCON1_FLD_TA_SURE                            REG_FLD_MSB_LSB(15, 8)
#define DSI_PHY_TIMCON1_FLD_TA_GO                              REG_FLD_MSB_LSB(7, 0)

#define DISP_REG_DSI_PHY_TIMCON2             (0x118UL)
#define DSI_PHY_TIMCON2_FLD_CLK_HS_TRAIL                       REG_FLD_MSB_LSB(31, 24)
#define DSI_PHY_TIMCON2_FLD_CLK_HS_ZERO                        REG_FLD_MSB_LSB(23, 16)
#define DSI_PHY_TIMCON2_FLD_DA_HS_SYNC                         REG_FLD_MSB_LSB(15, 8)
#define DSI_PHY_TIMCON2_FLD_CONT_DET                           REG_FLD_MSB_LSB(7, 0)

#define DISP_REG_DSI_PHY_TIMCON3             (0x11CUL)
#define DSI_PHY_TIMCON3_FLD_CLK_HS_EXIT                        REG_FLD_MSB_LSB(23, 16)
#define DSI_PHY_TIMCON3_FLD_CLK_HS_POST                        REG_FLD_MSB_LSB(15, 8)
#define DSI_PHY_TIMCON3_FLD_CLK_HS_PREP                        REG_FLD_MSB_LSB(7, 0)

#define DISP_REG_DSI_VM_CMD_CON              (0x130UL)
#define DSI_VM_CMD_CON_FLD_CM_DATA_1                           REG_FLD_MSB_LSB(31, 24)
#define DSI_VM_CMD_CON_FLD_CM_DATA_0                           REG_FLD_MSB_LSB(23, 16)
#define DSI_VM_CMD_CON_FLD_CM_DATA_ID                          REG_FLD_MSB_LSB(15, 8)
#define DSI_VM_CMD_CON_FLD_TS_VFP_EN                           REG_FLD_MSB_LSB(5, 5)
#define DSI_VM_CMD_CON_FLD_TS_VBP_EN                           REG_FLD_MSB_LSB(4, 4)
#define DSI_VM_CMD_CON_FLD_TS_VSA_EN                           REG_FLD_MSB_LSB(3, 3)
#define DSI_VM_CMD_CON_FLD_TIME_SEL                            REG_FLD_MSB_LSB(2, 2)
#define DSI_VM_CMD_CON_FLD_LONG_PKT                            REG_FLD_MSB_LSB(1, 1)
#define DSI_VM_CMD_CON_FLD_VM_CMD_EN                           REG_FLD_MSB_LSB(0, 0)


#define DISP_REG_DSI_VM_CMD_DATA0            (0x134UL)
#define DISP_REG_DSI_VM_CMD_DATA4            (0x138UL)
#define DISP_REG_DSI_VM_CMD_DATA8            (0x13CUL)
#define DISP_REG_DSI_VM_CMD_DATAC            (0x140UL)
#define DISP_REG_DSI_CKSM_OUT                (0x144UL)
#define DISP_REG_DSI_STATE_DBG0              (0x148UL)
#define DISP_REG_DSI_STATE_DBG1              (0x14CUL)
#define DISP_REG_DSI_STATE_DBG2              (0x150UL)
#define DISP_REG_DSI_STATE_DBG3              (0x154UL)
#define DISP_REG_DSI_STATE_DBG4              (0x158UL)
#define DISP_REG_DSI_STATE_DBG5              (0x15CUL)
#define DISP_REG_DSI_STATE_DBG6              (0x160UL)
#define DISP_REG_DSI_STATE_DBG7              (0x164UL)
#define DISP_REG_DSI_STATE_DBG8              (0x168UL)
#define DISP_REG_DSI_STATE_DBG9              (0x16CUL)
#define DISP_REG_DSI_DEBUG_SEL               (0x170UL)
#define DISP_REG_DSI_STATE_DBG10             (0x174UL)
#define DISP_REG_DSI_BIST_PATTERN            (0x178UL)
#define DISP_REG_DSI_BIST_CON                (0x17CUL)
#define DSI_BIST_CON_FLD_BIST_TIMIING                          REG_FLD_MSB_LSB(23, 16)
#define DSI_BIST_CON_FLD_SELF_PAT_MODE                         REG_FLD_MSB_LSB(6, 6)
#define DSI_BIST_CON_FLD_BIST_HS_FREE                          REG_FLD_MSB_LSB(4, 4)
#define DSI_BIST_CON_FLD_BIST_SPECIFIED_PATTERN                REG_FLD_MSB_LSB(3, 3)
#define DSI_BIST_CON_FLD_BIST_FIX_PATTERN                      REG_FLD_MSB_LSB(2, 2)
#define DSI_BIST_CON_FLD_BIST_ENABLE                           REG_FLD_MSB_LSB(1, 1)
#define DSI_BIST_CON_FLD_BIST_MODE                             REG_FLD_MSB_LSB(0, 0)


#define DISP_REG_DSI_VM_CMD_DATA10           (0x180UL)
#define DISP_REG_DSI_VM_CMD_DATA14           (0x184UL)
#define DISP_REG_DSI_VM_CMD_DATA18           (0x188UL)
#define DISP_REG_DSI_VM_CMD_DATA1C           (0x18CUL)
#define DISP_REG_DSI_SHADOW_DEBUG            (0x190UL)
#define DSI_SHADOW_DEBUG_FLD_READ_WORKING                      REG_FLD_MSB_LSB(2, 2)
#define DSI_SHADOW_DEBUG_FLD_BYPASS_SHADOW                     REG_FLD_MSB_LSB(1, 1)
#define DSI_SHADOW_DEBUG_FLD_FORCE_COMMIT                      REG_FLD_MSB_LSB(0, 0)


#define DISP_REG_DSI_SHADOW_STA              (0x194UL)
#define DISP_REG_DSI_VM_CMD_DATA20           (0x1A0UL)
#define DISP_REG_DSI_VM_CMD_DATA24           (0x1A4UL)
#define DISP_REG_DSI_VM_CMD_DATA28           (0x1A8UL)
#define DISP_REG_DSI_VM_CMD_DATA2C           (0x1ACUL)
#define DISP_REG_DSI_VM_CMD_DATA30           (0x1B0UL)
#define DISP_REG_DSI_VM_CMD_DATA34           (0x1B4UL)
#define DISP_REG_DSI_VM_CMD_DATA38           (0x1B8UL)
#define DISP_REG_DSI_VM_CMD_DATA3C           (0x1BCUL)
#define DISP_REG_DSI_MMCLK_STALL_DBG1        (0x1C0UL)
#define DISP_REG_DSI_MMCLK_STALL_DBG2        (0x1C4UL)
#define DISP_REG_DSI_MMCLK_STALL_DBG3        (0x1C8UL)
#define DISP_REG_DSI_MMCLK_STALL_DBG4        (0x1CCUL)
#define DISP_REG_DSI_INPUT_SETTING           (0x1D0UL)
#define DISP_REG_DSI_INPUT_DEBUG             (0x1D4UL)


#define DISP_REG_DSI_CMDQ                 (0x200UL)

#define DSI_CMDQ_FLD_BYTE3                                      REG_FLD_MSB_LSB(31, 24)
#define DSI_CMDQ_FLD_BYTE2                                      REG_FLD_MSB_LSB(23, 16)
#define DSI_CMDQ_FLD_BYTE1                                      REG_FLD_MSB_LSB(15, 8)
#define DSI_CMDQ_FLD_BYTE0                                      REG_FLD_MSB_LSB(7, 0)

#define DSI_CMDQ_FLD_Data1                                      REG_FLD_MSB_LSB(31, 24)
#define DSI_CMDQ_FLD_Data0                                      REG_FLD_MSB_LSB(23, 16)
#define DSI_CMDQ_FLD_DataID                                      REG_FLD_MSB_LSB(15, 8)
#define DSI_CMDQ_FLD_CONFG                                      REG_FLD_MSB_LSB(7, 0)


/* field definition */
/* ------------------------------------------------------------- */
/* DSI */

struct DSI_START_REG {
	unsigned DSI_START:1;
	unsigned rsv_1:1;
	unsigned SLEEPOUT_START:1;
	unsigned rsv_3:1;
	unsigned SKEWCAL_START:1;
	unsigned rsv_5:11;
	unsigned VM_CMD_START:1;
	unsigned rsv_17:15;
};

struct DSI_STATUS_REG {
	unsigned rsv_0:1;
	unsigned BUF_UNDERRUN:1; /* rsv */
	unsigned rsv_2:2;
	unsigned ESC_ENTRY_ERR:1;
	unsigned ESC_SYNC_ERR:1;
	unsigned CTRL_ERR:1;
	unsigned CONTENT_ERR:1;
	unsigned rsv_8:24;
};


struct DSI_INT_ENABLE_REG {
	unsigned RD_RDY:1;
	unsigned CMD_DONE:1;
	unsigned TE_RDY:1;
	unsigned VM_DONE:1;
	unsigned FRAME_DONE:1;
	unsigned VM_CMD_DONE:1;
	unsigned SLEEPOUT_DONE:1;
	unsigned TE_TIMEOUT_INT_EN:1;
	unsigned VM_VBP_STR_INT_EN:1;
	unsigned VM_VACT_STR_INT_EN:1;
	unsigned VM_VFP_STR_INT_EN:1;
	unsigned SKEWCAL_DONE_INT_EN:1;
	unsigned BUFFER_UNDERRUN_INT_EN:1;
	unsigned BTA_TIMEOUT_INT_EN:1;
	unsigned INP_UNFINISH_INT_EN:1;
	unsigned SLEEPIN_ULPS_INT_EN:1;
	unsigned LPRX_RD_RDY_EVENT_EN:1;
	unsigned CMD_DONE_EVENT_EN:1;
	unsigned TE_RDY_EVENT_EN:1;
	unsigned VM_DONE_EVENT_EN:1;
	unsigned FRAME_DONE_EVENT_EN:1;
	unsigned VM_CMD_DONE_EVENT_EN:1;
	unsigned SLEEPOUT_DONE_EVENT_EN:1;
	unsigned TE_TIMEOUT_EVENT_EN:1;
	unsigned VM_VBP_STR_EVENT_EN:1;
	unsigned VM_VACT_STR_EVENT_EN:1;
	unsigned VM_VFP_STR_EVENT_EN:1;
	unsigned SKEWCAL_DONE_EVENT_EN:1;
	unsigned BUFFER_UNDERRUN_EVENT_EN:1;
	unsigned res_29:3; /* 3 events */
};


struct DSI_INT_STATUS_REG {
	unsigned RD_RDY:1;
	unsigned CMD_DONE:1;
	unsigned TE_RDY:1;
	unsigned VM_DONE:1;
	unsigned FRAME_DONE_INT_EN:1;
	unsigned VM_CMD_DONE:1;
	unsigned SLEEPOUT_DONE:1;
	unsigned TE_TIMEOUT_INT_EN:1;
	unsigned VM_VBP_STR_INT_EN:1;
	unsigned VM_VACT_STR_INT_EN:1;
	unsigned VM_VFP_STR_INT_EN:1;
	unsigned SKEWCAL_DONE_INT_EN:1;
	unsigned BUFFER_UNDERRUN_INT_EN:1;
	unsigned BTA_TIMEOUT_INT_EN:1;
	unsigned INP_UNFINISH_INT_EN:1;
	unsigned SLEEPIN_DONE:1;
	unsigned rsv_16:15;
	unsigned BUSY:1;
};


struct DSI_COM_CTRL_REG {
	unsigned DSI_RESET:1;
	unsigned rsv_1:1;
	unsigned DPHY_RESET:1;
	unsigned rsv_3:1;
	unsigned DSI_DUAL_EN:1;
	unsigned rsv_5:27;
};


enum DSI_MODE_CTRL {
	DSI_CMD_MODE = 0,
	DSI_SYNC_PULSE_VDO_MODE = 1,
	DSI_SYNC_EVENT_VDO_MODE = 2,
	DSI_BURST_VDO_MODE = 3
};


struct DSI_MODE_CTRL_REG {
	unsigned MODE:2;
	unsigned rsv_2:14;
	unsigned FRM_MODE:1;
	unsigned MIX_MODE:1;
	unsigned V2C_SWITCH_ON:1;
	unsigned C2V_SWITCH_ON:1;
	unsigned SLEEP_MODE:1;
	unsigned rsv_21:11;
};


enum DSI_LANE_NUM {
	ONE_LANE = 1,
	TWO_LANE = 2,
	THREE_LANE = 3,
	FOUR_LANE = 4
};


struct DSI_TXRX_CTRL_REG {
	unsigned VC_NUM:2;
	unsigned LANE_NUM:4;
	unsigned DIS_EOT:1;
	unsigned BLLP_EN:1;
	unsigned TE_FREERUN:1;
	unsigned EXT_TE_EN:1;
	unsigned EXT_TE_EDGE:1;
	unsigned TE_AUTO_SYNC:1;
	unsigned MAX_RTN_SIZE:4;
	unsigned HSTX_CKLP_EN:1;
	unsigned TYPE1_BTA_SEL:1;
	unsigned TE_WITH_CMD_EN:1;
	unsigned TE_TIMEOUT_CHK_EN:1;
	unsigned EXT_TE_TIME_VM:4;
	unsigned RGB_PKT_CNT:4;
	unsigned LP_ONLY_VBLK:1; /* bta timeout en */
	unsigned rsv_29:3;
};


enum DSI_PS_TYPE {
	PACKED_PS_16BIT_RGB565 = 0,
	LOOSELY_PS_18BIT_RGB666 = 1,
	PACKED_PS_24BIT_RGB888 = 2,
	PACKED_PS_18BIT_RGB666 = 3
};


struct DSI_PSCTRL_REG {
	unsigned DSI_PS_WC:15;
	unsigned rsv_15:1;
	unsigned DSI_PS_SEL:3;
	unsigned rsv_19:5;
	unsigned RGB_SWAP:1;
	unsigned BYTE_SWAP:1;
	unsigned CUSTOM_HEADER:6;
};


struct DSI_VSA_NL_REG {
	unsigned VSA_NL:12;
	unsigned rsv_12:20;
};


struct DSI_VBP_NL_REG {
	unsigned VBP_NL:12;
	unsigned rsv_12:20;
};


struct DSI_VFP_NL_REG {
	unsigned VFP_NL:12;
	unsigned rsv_12:20;
};


struct DSI_VACT_NL_REG {
	unsigned VACT_NL:15;
	unsigned rsv_15:17;
};

struct DSI_LFR_CON_REG {
	unsigned LFR_MODE:2;
	unsigned LFR_TYPE:2;
	unsigned LFR_EN:1;
	unsigned LFR_UPDATE:1;
	unsigned LFR_VSE_DIS:1;
	unsigned rsv_7:1;
	unsigned LFR_SKIP_NUM:6;
	unsigned rsv_14:18;
};


struct DSI_LFR_STA_REG {
	unsigned LFR_SKIP_CNT:6;
	unsigned rsv_6:2;
	unsigned LFR_SKIP_STA:1;
	unsigned rsv_9:23;
};


struct DSI_SIZE_CON_REG {
	unsigned DSI_WIDTH:15;
	unsigned rsv_15:1;
	unsigned DSI_HEIGHT:15;
	unsigned rsv_31:1;
};


struct DSI_HSA_WC_REG {
	unsigned HSA_WC:12;
	unsigned rsv_12:20;
};


struct DSI_HBP_WC_REG {
	unsigned HBP_WC:12;
	unsigned rsv_12:20;
};


struct DSI_HFP_WC_REG {
	unsigned HFP_WC:12;
	unsigned rsv_12:20;
};

struct DSI_BLLP_WC_REG {
	unsigned BLLP_WC:12;
	unsigned rsv_12:20;
};

struct DSI_CMDQ_CTRL_REG {
	unsigned CMDQ_SIZE:8;
	unsigned rsv_8:24;
};

struct DSI_HSTX_CKLP_REG {
	unsigned rsv_0:2;
	unsigned HSTX_CKLP_WC:14;
	unsigned HSTX_CKLP_WC_AUTO:1;
	unsigned rsv_17:15;
};

struct DSI_HSTX_CKLP_WC_AUTO_RESULT_REG {
	unsigned HSTX_CKLP_WC_AUTO_RESULT:16;
	unsigned rsv_16:16;
};

struct DSI_RX_DATA_REG {
	unsigned char byte0;
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
};


struct DSI_RACK_REG {
	unsigned DSI_RACK:1;
	unsigned DSI_RACK_BYPASS:1;
	unsigned rsv2:30;
};


struct DSI_TRIG_STA_REG {
	unsigned TRIG0:1;	/* remote rst */
	unsigned TRIG1:1;	/* TE */
	unsigned TRIG2:1;	/* ack */
	unsigned TRIG3:1;	/* rsv */
	unsigned RX_ULPS:1;
	unsigned DIRECTION:1;
	unsigned RX_LPDT:1;
	unsigned rsv7:1;
	unsigned RX_POINTER:4;
	unsigned rsv12:20;
};


struct DSI_MEM_CONTI_REG {
	unsigned RWMEM_CONTI:16;
	unsigned rsv16:16;
};


struct DSI_FRM_BC_REG {
	unsigned FRM_BC:21;
	unsigned rsv21:11;
};

struct DSI_3D_CON_REG {
	unsigned _3D_MODE:2;
	unsigned _3D_FMT:2;
	unsigned _3D_VSYNC:1;
	unsigned _3D_LR:1;
	unsigned rsv6:2;
	unsigned _3D_EN:1;
	unsigned rsv9:23;
};

struct DSI_TIME_CON0_REG {
	unsigned UPLS_WAKEUP_PRD:16;
	unsigned SKEWCALL_PRD:16;
};

struct DSI_TIME_CON1_REG {
	unsigned TE_TIMEOUT_PRD:16;
	unsigned PREFETCH_TIME:15;
	unsigned PREFETCH_EN:1;
};


struct DSI_PHY_LCPAT_REG {
	unsigned LC_HSTX_CK_PAT:8;
	unsigned rsv8:24;
};

struct DSI_PHY_LCCON_REG {
	unsigned LC_HS_TX_EN:1;
	unsigned LC_ULPM_EN:1;
	unsigned LC_WAKEUP_EN:1;
	unsigned rsv3:29;
};


struct DSI_PHY_LD0CON_REG {
	unsigned L0_RM_TRIG_EN:1;
	unsigned L0_ULPM_EN:1;
	unsigned L0_WAKEUP_EN:1;
	unsigned Lx_ULPM_AS_L0:1;
	unsigned L0_RX_FILTER_EN:1;
	unsigned rsv3:27;
};


struct DSI_PHY_SYNCON_REG {
	unsigned HS_SYNC_CODE:8;
	unsigned HS_SYNC_CODE2:8;
	unsigned HS_SKEWCAL_PAT:8;
	unsigned HS_DB_SYNC_EN:1;
	unsigned rsv25:7;
};


struct DSI_PHY_TIMCON0_REG {
	unsigned char LPX;
	unsigned char HS_PRPR;
	unsigned char HS_ZERO;
	unsigned char HS_TRAIL;
};


struct DSI_PHY_TIMCON1_REG {
	unsigned char TA_GO;
	unsigned char TA_SURE;
	unsigned char TA_GET;
	unsigned char DA_HS_EXIT;
};


struct DSI_PHY_TIMCON2_REG {
	unsigned char CONT_DET;
	unsigned char DA_HS_SYNC;
	unsigned char CLK_ZERO;
	unsigned char CLK_TRAIL;
};


struct DSI_PHY_TIMCON3_REG {
	unsigned char CLK_HS_PRPR;
	unsigned char CLK_HS_POST;
	unsigned char CLK_HS_EXIT;
	unsigned rsv24:8;
};


struct DSI_VM_CMD_CON_REG {
	unsigned VM_CMD_EN:1;
	unsigned LONG_PKT:1;
	unsigned TIME_SEL:1;
	unsigned TS_VSA_EN:1;
	unsigned TS_VBP_EN:1;
	unsigned TS_VFP_EN:1;
	unsigned rsv6:2;
	unsigned CM_DATA_ID:8;
	unsigned CM_DATA_0:8;
	unsigned CM_DATA_1:8;
};


struct DSI_PHY_TIMCON_REG {
	struct DSI_PHY_TIMCON0_REG CTRL0;
	struct DSI_PHY_TIMCON1_REG CTRL1;
	struct DSI_PHY_TIMCON2_REG CTRL2;
	struct DSI_PHY_TIMCON3_REG CTRL3;
};


struct DSI_CKSM_OUT_REG {
	unsigned PKT_CHECK_SUM:16;
	unsigned ACC_CHECK_SUM:16;
};


struct DSI_STATE_DBG0_REG {
	unsigned DPHY_CTL_STATE_C:9;
	unsigned rsv9:7;
	unsigned DPHY_HS_TX_STATE_C:5;
	unsigned rsv21:11;
};


struct DSI_STATE_DBG1_REG {
	unsigned CTL_STATE_C:15;
	unsigned rsv15:1;
	unsigned HS_TX_STATE_0:5;
	unsigned rsv21:3;
	unsigned ESC_STATE_0:8;
};


struct DSI_STATE_DBG2_REG {
	unsigned RX_ESC_STATE:10;
	unsigned rsv10:6;
	unsigned TA_T2R_STATE:5;
	unsigned rsv21:3;
	unsigned TA_R2T_STATE:5;
	unsigned rsv29:3;
};


struct DSI_STATE_DBG3_REG {
	unsigned CTL_STATE_1:5;
	unsigned rsv5:3;
	unsigned HS_TX_STATE_1:5;
	unsigned rsv13:3;
	unsigned CTL_STATE_2:5;
	unsigned rsv21:3;
	unsigned HS_TX_STATE_2:5;
	unsigned rsv29:3;
};


struct DSI_STATE_DBG4_REG {
	unsigned CTL_STATE_3:5;
	unsigned rsv5:3;
	unsigned HS_TX_STATE_3:5;
	unsigned rsv13:19;
};


struct DSI_STATE_DBG5_REG {
	unsigned TIMER_COUNTER:16;
	unsigned TIMER_BUSY:1;
	unsigned rsv17:11;
	unsigned WAKEUP_STATE:4;
};


struct DSI_STATE_DBG6_REG {
	unsigned CMTRL_STATE:15;
	unsigned rsv15:1;
	unsigned CMDQ_STATE:7;
	unsigned rsv23:9;
};


struct DSI_STATE_DBG7_REG {
	unsigned VMCTL_STATE:11;
	unsigned rsv11:1;
	unsigned VFP_PERIOD:1;
	unsigned VACT_PERIOD:1;
	unsigned VBP_PERIOD:1;
	unsigned VSA_PERIOD:1;
	unsigned rsv16:16;
};


struct DSI_STATE_DBG8_REG {
	unsigned WORD_COUNTER:15;
	unsigned rsv15:1;
	unsigned PREFETCH_CNT:15;
	unsigned DSI_PREFETCH_MUTEX:1;
};


struct DSI_STATE_DBG9_REG {
	unsigned LINE_COUNTER:22;
	unsigned rsv22:10;
};


struct DSI_DEBUG_SEL_REG {
	unsigned DEBUG_OUT_SEL:5;
	unsigned rsv5:3;
	unsigned CHKSUM_REC_EN:1;
	unsigned C2V_START_CON:1;
	unsigned rsv10:4;
	unsigned DYNAMIC_CG_CON:18; /* 16 */
};

struct DSI_STATE_DBG10_REG {
	unsigned LIMIT_W:15;
	unsigned rsv15:1;
	unsigned LIMIT_H:15;
	unsigned rsv31:1;
};


struct DSI_BIST_CON_REG {
	unsigned BIST_MODE:1;
	unsigned BIST_ENABLE:1;
	unsigned BIST_FIX_PATTERN:1;
	unsigned BIST_SPC_PATTERN:1;
	unsigned BIST_HS_FREE:1;
	unsigned rsv_05:1;
	unsigned SELF_PAT_MODE:1;
	unsigned rsv_07:1;
	unsigned BIST_LANE_NUM:4; /* To be confirmed */
	unsigned rsv12:4;
	unsigned BIST_TIMING:8;
	unsigned rsv24:8;
};


struct DSI_SHADOW_DEBUG_REG {
	unsigned FORCE_COMMIT:1;
	unsigned BYPASS_SHADOW:1;
	unsigned READ_WORKING:1;
	unsigned rsv3:29;
};


struct DSI_SHADOW_STA_REG {
	unsigned VACT_UPDATE_ERR:1;
	unsigned VFP_UPDATE_ERR:1;
	unsigned rsv2:30;
};


struct DSI_REGS {
	struct DSI_START_REG DSI_START;	/* 0000 */
	struct DSI_STATUS_REG DSI_STA;	/* 0004 */
	struct DSI_INT_ENABLE_REG DSI_INTEN;	/* 0008 */
	struct DSI_INT_STATUS_REG DSI_INTSTA;	/* 000C */
	struct DSI_COM_CTRL_REG DSI_COM_CTRL;	/* 0010 */
	struct DSI_MODE_CTRL_REG DSI_MODE_CTRL;	/* 0014 */
	struct DSI_TXRX_CTRL_REG DSI_TXRX_CTRL;	/* 0018 */
	struct DSI_PSCTRL_REG DSI_PSCTRL;	/* 001C */
	struct DSI_VSA_NL_REG DSI_VSA_NL;	/* 0020 */
	struct DSI_VBP_NL_REG DSI_VBP_NL;	/* 0024 */
	struct DSI_VFP_NL_REG DSI_VFP_NL;	/* 0028 */
	struct DSI_VACT_NL_REG DSI_VACT_NL;	/* 002C */
	struct DSI_LFR_CON_REG DSI_LFR_CON;	/* 0030 */
	struct DSI_LFR_STA_REG DSI_LFR_STA;	/* 0034 */
	struct DSI_SIZE_CON_REG DSI_SIZE_CON;	/* 0038 */
	UINT32 rsv_3c[5];	/* 003C..004C */
	struct DSI_HSA_WC_REG DSI_HSA_WC;	/* 0050 */
	struct DSI_HBP_WC_REG DSI_HBP_WC;	/* 0054 */
	struct DSI_HFP_WC_REG DSI_HFP_WC;	/* 0058 */
	struct DSI_BLLP_WC_REG DSI_BLLP_WC;	/* 005C */
	struct DSI_CMDQ_CTRL_REG DSI_CMDQ_SIZE;	/* 0060 */
	struct DSI_HSTX_CKLP_REG DSI_HSTX_CKL_WC;	/* 0064 */
	struct DSI_HSTX_CKLP_WC_AUTO_RESULT_REG DSI_HSTX_CKL_WC_AUTO_RESULT;	/* 0068 */
	UINT32 rsv_006C[2];	/* 006c..0070 */
	struct DSI_RX_DATA_REG DSI_RX_DATA0;	/* 0074 */
	struct DSI_RX_DATA_REG DSI_RX_DATA1;	/* 0078 */
	struct DSI_RX_DATA_REG DSI_RX_DATA2;	/* 007c */
	struct DSI_RX_DATA_REG DSI_RX_DATA3;	/* 0080 */
	struct DSI_RACK_REG DSI_RACK;	/* 0084 */
	struct DSI_TRIG_STA_REG DSI_TRIG_STA;	/* 0088 */
	UINT32 rsv_008C;	/* 008C */
	struct DSI_MEM_CONTI_REG DSI_MEM_CONTI;	/* 0090 */
	struct DSI_FRM_BC_REG DSI_FRM_BC;	/* 0094 */
	struct DSI_3D_CON_REG DSI_3D_CON;	/* 0098 */
	UINT32 rsv_009C;	/* 009c */
	struct DSI_TIME_CON0_REG DSI_TIME_CON0;	/* 00A0 */
	struct DSI_TIME_CON1_REG DSI_TIME_CON1;	/* 00A4 */

	UINT32 rsv_00A8[22];	/* 0A8..0FC */
	UINT32 DSI_PHY_PCPAT;	/* 00100 */

	struct DSI_PHY_LCCON_REG DSI_PHY_LCCON;	/* 0104 */
	struct DSI_PHY_LD0CON_REG DSI_PHY_LD0CON;	/* 0108 */
	struct DSI_PHY_SYNCON_REG DSI_PHY_SYNCON;	/* 010C */
	struct DSI_PHY_TIMCON0_REG DSI_PHY_TIMECON0;	/* 0110 */
	struct DSI_PHY_TIMCON1_REG DSI_PHY_TIMECON1;	/* 0114 */
	struct DSI_PHY_TIMCON2_REG DSI_PHY_TIMECON2;	/* 0118 */
	struct DSI_PHY_TIMCON3_REG DSI_PHY_TIMECON3;	/* 011C */
	UINT32 rsv_0120[4];	/* 0120..012c */
	struct DSI_VM_CMD_CON_REG DSI_VM_CMD_CON;	/* 0130 */
	UINT32 DSI_VM_CMD_DATA0;	/* 0134 */
	UINT32 DSI_VM_CMD_DATA4;	/* 0138 */
	UINT32 DSI_VM_CMD_DATA8;	/* 013C */
	UINT32 DSI_VM_CMD_DATAC;	/* 0140 */
	struct DSI_CKSM_OUT_REG DSI_CKSM_OUT;	/* 0144 */
	struct DSI_STATE_DBG0_REG DSI_STATE_DBG0;	/* 0148 */
	struct DSI_STATE_DBG1_REG DSI_STATE_DBG1;	/* 014C */
	struct DSI_STATE_DBG2_REG DSI_STATE_DBG2;	/* 0150 */
	struct DSI_STATE_DBG3_REG DSI_STATE_DBG3;	/* 0154 */
	struct DSI_STATE_DBG4_REG DSI_STATE_DBG4;	/* 0158 */
	struct DSI_STATE_DBG5_REG DSI_STATE_DBG5;	/* 015C */
	struct DSI_STATE_DBG6_REG DSI_STATE_DBG6;	/* 0160 */
	struct DSI_STATE_DBG7_REG DSI_STATE_DBG7;	/* 0164 */
	struct DSI_STATE_DBG8_REG DSI_STATE_DBG8;	/* 0168 */
	struct DSI_STATE_DBG9_REG DSI_STATE_DBG9;	/* 016C */
	struct DSI_DEBUG_SEL_REG DSI_DEBUG_SEL;	/* 0170 */
	struct DSI_STATE_DBG10_REG DSI_STATE_DBG10;	/* 0174 */
	UINT32 DSI_BIST_PATTERN;	/* 0178 */
	struct DSI_BIST_CON_REG DSI_BIST_CON;	/* 017C */
	UINT32 DSI_VM_CMD_DATA10;	/* 00180 */
	UINT32 DSI_VM_CMD_DATA14;	/* 00184 */
	UINT32 DSI_VM_CMD_DATA18;	/* 00188 */
	UINT32 DSI_VM_CMD_DATA1C;	/* 0018C */
	struct DSI_SHADOW_DEBUG_REG DSI_SHADOW_DEBUG;	/* 0190 */
	struct DSI_SHADOW_STA_REG DSI_SHADOW_STA;	/* 0194 */
};
struct DSI_REGS_TYPE {
	UINT32 DSI_START;	/* 0000 */
	UINT32 DSI_STA;	/* 0004 */
	UINT32 DSI_INTEN;	/* 0008 */
	UINT32 DSI_INTSTA;	/* 000C */
	UINT32 DSI_COM_CTRL;	/* 0010 */
	UINT32 DSI_MODE_CTRL;	/* 0014 */
	UINT32 DSI_TXRX_CTRL;	/* 0018 */
	UINT32 DSI_PSCTRL;	/* 001C */
	UINT32 DSI_VSA_NL;	/* 0020 */
	UINT32 DSI_VBP_NL;	/* 0024 */
	UINT32 DSI_VFP_NL;	/* 0028 */
	UINT32 DSI_VACT_NL;	/* 002C */
	UINT32 DSI_LFR_CON;	/* 0030 */
	UINT32 DSI_LFR_STA;	/* 0034 */
	UINT32 DSI_SIZE_CON;	/* 0038 */
	UINT32 rsv_3c[5];	/* 003C..004C */
	UINT32 DSI_HSA_WC;	/* 0050 */
	UINT32 DSI_HBP_WC;	/* 0054 */
	UINT32 DSI_HFP_WC;	/* 0058 */
	UINT32 DSI_BLLP_WC;	/* 005C */
	UINT32 DSI_CMDQ_SIZE;	/* 0060 */
	UINT32 DSI_HSTX_CKL_WC;	/* 0064 */
	UINT32 DSI_HSTX_CKL_WC_AUTO_RESULT;	/* 0068 */
	UINT32 rsv_006C[2];	/* 006c..0070 */
	UINT32 DSI_RX_DATA0;	/* 0074 */
	UINT32 DSI_RX_DATA1;	/* 0078 */
	UINT32 DSI_RX_DATA2;	/* 007c */
	UINT32 DSI_RX_DATA3;	/* 0080 */
	UINT32 DSI_RACK;	/* 0084 */
	UINT32 DSI_TRIG_STA;	/* 0088 */
	UINT32 rsv_008C;	/* 008C */
	UINT32 DSI_MEM_CONTI;	/* 0090 */
	UINT32 DSI_FRM_BC;	/* 0094 */
	UINT32 DSI_3D_CON;	/* 0098 */
	UINT32 rsv_009C;	/* 009c */
	UINT32 DSI_TIME_CON0;	/* 00A0 */
	UINT32 DSI_TIME_CON1;	/* 00A4 */

	UINT32 rsv_00A8[22];	/* 0A8..0FC */
	UINT32 DSI_PHY_PCPAT;	/* 00100 */

	UINT32 DSI_PHY_LCCON;	/* 0104 */
	UINT32 DSI_PHY_LD0CON;	/* 0108 */
	UINT32 DSI_PHY_SYNCON;	/* 010C */
	UINT32 DSI_PHY_TIMECON0;	/* 0110 */
	UINT32 DSI_PHY_TIMECON1;	/* 0114 */
	UINT32 DSI_PHY_TIMECON2;	/* 0118 */
	UINT32 DSI_PHY_TIMECON3;	/* 011C */
	UINT32 rsv_0120[4];	/* 0120..012c */
	UINT32 DSI_VM_CMD_CON;	/* 0130 */
	UINT32 DSI_VM_CMD_DATA0;	/* 0134 */
	UINT32 DSI_VM_CMD_DATA4;	/* 0138 */
	UINT32 DSI_VM_CMD_DATA8;	/* 013C */
	UINT32 DSI_VM_CMD_DATAC;	/* 0140 */
	UINT32 DSI_CKSM_OUT;	/* 0144 */
	UINT32 DSI_STATE_DBG0;	/* 0148 */
	UINT32 DSI_STATE_DBG1;	/* 014C */
	UINT32 DSI_STATE_DBG2;	/* 0150 */
	UINT32 DSI_STATE_DBG3;	/* 0154 */
	UINT32 DSI_STATE_DBG4;	/* 0158 */
	UINT32 DSI_STATE_DBG5;	/* 015C */
	UINT32 DSI_STATE_DBG6;	/* 0160 */
	UINT32 DSI_STATE_DBG7;	/* 0164 */
	UINT32 DSI_STATE_DBG8;	/* 0168 */
	UINT32 DSI_STATE_DBG9;	/* 016C */
	UINT32 DSI_DEBUG_SEL;	/* 0170 */
	UINT32 DSI_STATE_DBG10;	/* 0174 */
	UINT32 DSI_BIST_PATTERN;	/* 0178 */
	UINT32 DSI_BIST_CON;	/* 017C */
	UINT32 DSI_VM_CMD_DATA10;	/* 00180 */
	UINT32 DSI_VM_CMD_DATA14;	/* 00184 */
	UINT32 DSI_VM_CMD_DATA18;	/* 00188 */
	UINT32 DSI_VM_CMD_DATA1C;	/* 0018C */
	UINT32 DSI_SHADOW_DEBUG;	/* 0190 */
	UINT32 DSI_SHADOW_STA;	/* 0194 */
};
/* 0~1 TYPE ,2 BTA,3 HS, 4 CL,5 TE,6~7 RESV, 8~15 DATA_ID,16~23 DATA_0,24~31 DATA_1 */
struct DSI_CMDQ {
	unsigned char byte0;
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
};

struct DSI_CMDQ_REGS {
	struct DSI_CMDQ data[128]; /* only support 128 cmdq */
};

struct DSI_CMDQ_REGS_TYPE {
	UINT32 data[128]; /* only support 128 cmdq */
};


struct DSI_VM_CMDQ {
	unsigned char byte0;
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
};

struct DSI_VM_CMDQ_REGS {
	struct DSI_VM_CMDQ data[4];
};

#endif /* _DDP_REG_DSI_H_ */
