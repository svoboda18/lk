/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2017. All rights reserved.
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

#ifndef __MTK_DCM_AUTOGEN_H__
#define __MTK_DCM_AUTOGEN_H__

#include <mtk_dcm.h>

#undef INFRACFG_AO_BASE
#undef TOPCKGEN_AO_BASE
#undef MCUCFG_BASE
#undef DRAMC_BASE
#undef EMI_BASE
#undef CHN0_EMI_BASE
#undef EFUSEC_BASE

/* Base */
#define INFRACFG_AO_BASE 0x10001000
#define TOPCKGEN_AO_BASE 0x1001b000
#define DRAMC_BASE 0x1001d000
#define MCUCFG_BASE 0x10200000
#define EMI_BASE 0x10219000
#define CHN0_EMI_BASE 0x1021a000
#define EFUSEC_BASE 0x11c00000


/* Register Definition */
#define INFRA_BUS_DCM_CTRL (INFRACFG_AO_BASE + 0x70)
#define PERI_BUS_DCM_CTRL (INFRACFG_AO_BASE + 0x74)
#define MEM_DCM_CTRL (INFRACFG_AO_BASE + 0x78)
#define DFS_MEM_DCM_CTRL (INFRACFG_AO_BASE + 0x7c)
#define P2P_RX_CLK_ON (INFRACFG_AO_BASE + 0xa0)
#define INFRA_TOPCKGEN_DCMCTL (TOPCKGEN_AO_BASE + 0x8)
#define DRAMC_DRAMC_PD_CTRL (DRAMC_BASE + 0x1dc)
#define L2C_SRAM_CTRL (MCUCFG_BASE + 0x648)
#define CCI_CLK_CTRL (MCUCFG_BASE + 0x660)
#define BUS_FABRIC_DCM_CTRL (MCUCFG_BASE + 0x668)
#define MCU_MISC_DCM_CTRL (MCUCFG_BASE + 0x66c)
#define EMI_CONM (EMI_BASE + 0x60)
#define EMI_CONN (EMI_BASE + 0x68)
#define CHN0_EMI_CHN_EMI_CONB (CHN0_EMI_BASE + 0x8)
#define EFUSEC_DCM_ON (EFUSEC_BASE + 0x4a0)

/* INFRACFG_AO */
bool dcm_infracfg_ao_dcm_dfs_mem_ctrl_is_on(void);
void dcm_infracfg_ao_dcm_dfs_mem_ctrl(int on);
bool dcm_infracfg_ao_dcm_infra_bus_is_on(void);
void dcm_infracfg_ao_dcm_infra_bus(int on);
bool dcm_infracfg_ao_dcm_mem_ctrl_is_on(void);
void dcm_infracfg_ao_dcm_mem_ctrl(int on);
bool dcm_infracfg_ao_dcm_peri_bus_is_on(void);
void dcm_infracfg_ao_dcm_peri_bus(int on);
bool dcm_infracfg_ao_dcm_top_p2p_rx_ck_is_on(void);
void dcm_infracfg_ao_dcm_top_p2p_rx_ck(int on);
/* TOPCKGEN_AO */
bool dcm_topckgen_ao_mcu_armpll_ca7ll_is_on(void);
void dcm_topckgen_ao_mcu_armpll_ca7ll(int on);
/* DRAMC */
bool dcm_dramc_dramc_dcm_is_on(void);
void dcm_dramc_dramc_dcm(int on);
/* MCUCFG */
bool dcm_mcucfg_bus_clock_dcm_is_on(void);
void dcm_mcucfg_bus_clock_dcm(int on);
bool dcm_mcucfg_bus_fabric_dcm_is_on(void);
void dcm_mcucfg_bus_fabric_dcm(int on);
bool dcm_mcucfg_l2_shared_dcm_is_on(void);
void dcm_mcucfg_l2_shared_dcm(int on);
bool dcm_mcucfg_mcu_misc_dcm_is_on(void);
void dcm_mcucfg_mcu_misc_dcm(int on);
/* EMI */
bool dcm_emi_dcm_emi_group_is_on(void);
void dcm_emi_dcm_emi_group(int on);
/* CHN0_EMI */
bool dcm_chn0_emi_dcm_emi_group_is_on(void);
void dcm_chn0_emi_dcm_emi_group(int on);
/* EFUSEC */
bool dcm_efusec_dcm_efuse_af_is_on(void);
void dcm_efusec_dcm_efuse_af(int on);
bool dcm_efusec_dcm_efuse_bg_is_on(void);
void dcm_efusec_dcm_efuse_bg(int on);
bool dcm_efusec_dcm_efuse_common_is_on(void);
void dcm_efusec_dcm_efuse_common(int on);

#endif
