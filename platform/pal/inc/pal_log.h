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
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
 * applicable license agreements with MediaTek Inc.
 */

#ifndef __PAL_LOG_H__
#define __PAL_LOG_H__

#include <pal_typedefs.h>
#include <debug.h>

/* definitions */
#define LOG_LEVEL_ALWAYS     (0)
#define LOG_LEVEL_ERROR      (1)
#define LOG_LEVEL_WARNING    (2)
#define LOG_LEVEL_INFO       (3)
#define LOG_LEVEL_DEBUG      (4)

#define BUILD_ERR_LOG        (1)
#define BUILD_WARN_LOG       (1)
#define BUILD_INFO_LOG       (1)
#define BUILD_DEBUG_LOG      (0)

/* macros */
#if BUILD_ERR_LOG
#define pal_log_err(f, ...) do {if (get_log_level() >= LOG_LEVEL_ERROR) dprintf(CRITICAL, f, ##__VA_ARGS__);} while(0)
#else
#define pal_log_err(f, ...) do {(void)0;} while(0)
#endif

#if BUILD_WARN_LOG
#define pal_log_warn(f, ...) do {if (get_log_level() >= LOG_LEVEL_WARNING) dprintf(CRITICAL, f, ##__VA_ARGS__);} while(0)
#else
#define pal_log_warn(f, ...) do {(void)0;} while(0)
#endif

#if BUILD_INFO_LOG
#define pal_log_info(f, ...) do {if (get_log_level() >= LOG_LEVEL_INFO) dprintf(CRITICAL, f, ##__VA_ARGS__);} while(0)
#else
#define pal_log_info(f, ...) do {(void)0;} while(0)
#endif

#if BUILD_DEBUG_LOG
#define pal_log_debug(f, ...) do {if (get_log_level() >= LOG_LEVEL_DEBUG) dprintf(CRITICAL, f, ##__VA_ARGS__);} while(0)
#else
#define pal_log_debug(f, ...) do {(void)0;} while(0)
#endif

/* global variables */
/* empty */

/* functions */
uint32_t get_log_level(void);
void set_log_level(uint32_t log_level);

#endif /* __PAL_LOG_H__ */

