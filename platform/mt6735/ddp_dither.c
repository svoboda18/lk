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
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/
#define LOG_TAG "DITHER"

#include "platform/ddp_reg.h"
#include "platform/ddp_path.h"
#include "platform/ddp_dither.h"
#include "platform/ddp_log.h"


#define DITHER_REG(reg_base, index) ((reg_base) + 0x100 + (index) * 4)

static void disp_dither_init(disp_dither_id_t id, int width, int height,
    unsigned int dither_bpp, void *cmdq)
{
    unsigned long reg_base = DISPSYS_DITHER_BASE;
    unsigned int enable;

    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 5)   , 0x00000000, ~0);
    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 6)   , 0x00003004, ~0);
    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 7)   , 0x00000000, ~0);
    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 8)   , 0x00000000, ~0);
    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 9)   , 0x00000000, ~0);
    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 10)  , 0x00000000, ~0);
    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 11)  , 0x00000000, ~0);
    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 12)  , 0x00000011, ~0);
    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 13)  , 0x00000000, ~0);
    DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 14)  , 0x00000000, ~0);

    enable = 0x1;
    if (dither_bpp == 16) { /* 565 */
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 15), 0x50500001, ~0);
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 16), 0x50504040, ~0);
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 0),  0x00000001, ~0);
    } else if (dither_bpp == 18) { /* 666 */
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 15), 0x40400001, ~0);
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 16), 0x40404040, ~0);
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 0),  0x00000001, ~0);
    } else if (dither_bpp == 24) { /* 888 */
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 15), 0x20200001, ~0);
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 16), 0x20202020, ~0);
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 0),  0x00000001, ~0);
    } else if (dither_bpp > 24) {
        DDPMSG("[DITHER] High depth LCM (bpp = %d), no dither\n", dither_bpp);
        enable = 1;
    } else {
        DDPERR("[DITHER] invalid dither bpp = %d\n", dither_bpp);
        /* Bypass dither */
        DISP_REG_MASK(cmdq, DITHER_REG(reg_base, 0), 0x00000000, ~0);
        enable = 0;
    }

    DISP_REG_MASK(cmdq, DISP_REG_DITHER_EN, enable, 0x1);
    DISP_REG_MASK(cmdq, DISP_REG_DITHER_CFG, enable << 1, 1 << 1);
    DISP_REG_SET(cmdq, DISP_REG_DITHER_SIZE, (width << 16) | height);
}


static int disp_dither_config(DISP_MODULE_ENUM module, disp_ddp_path_config* pConfig, void* cmdq)
{
    if (pConfig->dst_dirty) {
        disp_dither_init(DISP_DITHER0, pConfig->dst_w, pConfig->dst_h,
            pConfig->lcm_bpp, cmdq);
    }

    return 0;
}


static int disp_dither_bypass(DISP_MODULE_ENUM module, int bypass)
{
    int relay = 0;
    if (bypass)
        relay = 1;
        
    DISP_REG_MASK(NULL, DISP_REG_DITHER_CFG, relay, 0x1);

    DDPMSG("disp_dither_bypass(bypass = %d)", bypass); 

    return 0;
}



DDP_MODULE_DRIVER ddp_driver_dither =
{
    .config         = disp_dither_config,
    .bypass         = disp_dither_bypass
};

