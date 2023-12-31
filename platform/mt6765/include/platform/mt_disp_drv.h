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

#ifndef __mt6573_DISP_DRV_H__
#define __mt6573_DISP_DRV_H__

#include <platform/mt_typedefs.h>
#include "lcm_drv.h"
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

// ---------------------------------------------------------------------------
//  UBoot Display Utility Macros
// ---------------------------------------------------------------------------

#define NOT_REFERENCED(x) {(x) = (x);}
#define msleep(x)    mdelay(x)
#define printk  printf

// ---------------------------------------------------------------------------
typedef enum {
	DISP_VERTICAL_PROG_BAR = 0,
	DISP_HORIZONTAL_PROG_BAR,
} DISP_PROG_BAR_DIRECT;





// ---------------------------------------------------------------------------
//  UBoot Display Export Functions
// ---------------------------------------------------------------------------

UINT32 mt_disp_get_vram_size(void);
void   mt_disp_init(void *lcdbase);
void   mt_disp_power(BOOL on);
void   mt_disp_update(UINT32 x, UINT32 y, UINT32 width, UINT32 height);
UINT32 mt_disp_get_lcd_time(void);
const char* mt_disp_get_lcm_id(void);
UINT32 mt_disp_get_redoffset_32bit(void);

BOOL DISP_DetectDevice(void);

// -- Utility Functions for Customization --

void*  mt_get_logo_db_addr(void);
void*  mt_get_logo_db_addr_pa(void);
void   mt_free_logo_from_mblock(void)__attribute__((weak));
void*  mt_get_fb_addr(void);
UINT32 mt_get_fb_size(void);
void*  mt_get_tempfb_addr(void);

void mt_disp_fill_rect(UINT32 left, UINT32 top,
                       UINT32 right, UINT32 bottom,
                       UINT32 color);

void mt_disp_draw_prog_bar(DISP_PROG_BAR_DIRECT direct,
                           UINT32 left, UINT32 top,
                           UINT32 right, UINT32 bottom,
                           UINT32 fgColor, UINT32 bgColor,
                           UINT32 start_div, UINT32 total_div,
                           UINT32 occupied_div);
extern UINT32 DISP_GetScreenWidth(void);
extern UINT32 DISP_GetScreenHeight(void);
#ifdef __cplusplus
}
#endif

#endif // __mt65xx_DISP_DRV_H__
