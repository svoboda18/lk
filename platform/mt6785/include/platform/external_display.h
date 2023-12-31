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

#ifndef _EXTERNAL_DISPLAY_H_
#define _EXTERNAL_DISPLAY_H_

#include "ddp_hal.h"
#include "ddp_manager.h"

typedef enum {
	EXT_DIRECT_LINK_MODE,
	EXT_DECOUPLE_MODE,
	EXT_SINGLE_LAYER_MODE,
	EXT_DEBUG_RDMA1_DSI1_MODE
} DISP_EXTERNAL_PATH_MODE;



int external_display_init(char *lcm_name);
int external_display_config(unsigned int pa, unsigned int mva);
int external_display_suspend(void);
int external_display_resume(void);


int external_display_get_width(void);
int external_display_get_height(void);
int external_display_get_bpp(void);
int external_display_get_pages(void);

int external_display_set_overlay_layer(disp_input_config* input);
int external_display_is_alive(void);
int external_display_is_sleepd(void);
int external_display_wait_for_vsync(void);
int external_display_config_input(disp_input_config* input);
int external_display_trigger(int blocking);
int external_display_diagnose(void);
const char* external_display_get_lcm_name(void);

int external_display_get_info(void *dispif_info);
int external_display_capture_framebuffer(unsigned int *pbuf);
UINT32 EXT_DISP_GetVRamSize(void);
UINT32 EXT_DISP_GetFBRamSize(void);
UINT32 EXT_DISP_GetPages(void);
UINT32 EXT_DISP_GetScreenBpp(void);
UINT32 EXT_DISP_GetScreenWidth(void);
UINT32 EXT_DISP_GetScreenHeight(void);
UINT32 EXT_DISP_GetActiveHeight(void);
UINT32 EXT_DISP_GetActiveWidth(void);
int disp_hal_allocate_framebuffer(unsigned int pa_start, unsigned int pa_end, unsigned int* va, unsigned int* mva);
int external_display_is_video_mode(void);
int external_display_get_vsync_interval(void);
int external_display_setbacklight(unsigned int level);

#endif
