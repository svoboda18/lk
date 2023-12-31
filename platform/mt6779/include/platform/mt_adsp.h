/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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

#ifndef _MT_ADSP_H_
#define _MT_ADSP_H_

#include <platform/mt_reg_base.h>

#include "memory_layout.h"

//#define FPGA_EARLY_DEVELOPMENT

/* platform dependent address */
#define ADSP_DTCM_BASE      0x10610000
#define ADSP_DTCM_SIZE      0x00008000
#define ADSP_ITCM_BASE      0x10630000
#define ADSP_ITCM_SIZE      0x00009000

#ifdef FPGA_EARLY_DEVELOPMENT
#define ADSP_DRAM_SIZE      0x282000        // sizeof(reduced sys size + IPC + Log) for logger verification due to DDR size limitation on FPGA
#define ADSP_DRAM_LIMIT     0x60000000      // address limit: easier to get memory on FPGA
#else
#define ADSP_DRAM_SIZE      (LK_ADSP_MAX_SIZE)        // mblock_reserve requires max 23MB
#define ADSP_DRAM_LIMIT     (LK_ADSP_BASE + LK_ADSP_MAX_SIZE)
#endif
#define ADSP_DRAM_ALIGN     0x1000          // kernel is page(4KB) manamgement memory


#define ADSP_MPU_INFO_SIZE             (0x20)
#define ADSP_INFO_FIRMWARE_START       (ADSP_DTCM_BASE + ADSP_DTCM_SIZE - ADSP_MPU_INFO_SIZE)
#define ADSP_INFO_FIRMWARE_SIZE        (ADSP_DTCM_BASE + ADSP_DTCM_SIZE - ADSP_MPU_INFO_SIZE + 0x04)

/* emi setting */
#define MPU_REGION_ID_ADSP_RO_MEM       (28)
#define ENABLE_ADSP_EMI_PROTECTION      (1)


/************* macro for adsp clock config ******************************/
#define CLK_CFG_10                          (TOPCKGEN_BASE + 0x00E0)
#define CLK_CFG_10_SET                      (TOPCKGEN_BASE + 0x00E4)
#define CLK_CFG_10_CLR                      (TOPCKGEN_BASE + 0x00E8)

//#define MODULE_SW_CG_3                        (INFRACFG_AO_BASE + 0x00E4)
#define MODULE_SW_CG_3_SET                  (INFRACFG_AO_BASE + 0x0C0)
#define MODULE_SW_CG_3_CLR                  (INFRACFG_AO_BASE + 0x0C4)
#define MODULE_SW_CG_3_STA                  (INFRACFG_AO_BASE + 0x0C8)

#define ADSPPLL_CON0                        (APMIXED_BASE + 0x02B0)
#define ADSPPLL_CON1                        (APMIXED_BASE + 0x02B4)
#define ADSPPLL_PWR_CON0                    (APMIXED_BASE + 0x02BC)

/* adsp CFGREG define */
#define ADSP_CFG_BASE                       0x10600000
#define ADSP_A_REBOOT                       (ADSP_CFG_BASE + 0x0000)
#define ADSP_HIFI3_IO_CONFIG                (ADSP_CFG_BASE + 0x0008)
#define ADSP_DDREN_REQ                      (ADSP_CFG_BASE + 0x0044)
#define ADSP_SPM_REQ                        (ADSP_CFG_BASE + 0x0048)
#define ADSP_SPM_ACK                        (ADSP_CFG_BASE + 0x004C)

#define ADSP_DTS_COMPATIBLE                 "mediatek,audio_dsp"

#define ADSP_MEM_RESERVED_KEY               "mediatek,reserve-memory-adsp"

/* image name definition */
#define IRAM_NAME_ADSP_A                    "hifi3_a_iram"
#define DRAM_NAME_ADSP_A                    "hifi3_a_dram"
#define FIRMWARE_NAME_ADSP_A                "hifi3_a_sram"

struct adsp_region_info_t {
	uint32_t adsp_region_start;
	uint32_t adsp_region_size;
};

unsigned int get_adsp_status(void);
void disable_adsp_hw(void);
int load_adsp(void);

#endif
