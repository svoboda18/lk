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
#include <sys/types.h>
#include <debug.h>
#include <platform/boot_mode.h>
#include <platform/mt_typedefs.h>
#include <meta.h>

/**************************************************************************
 *  CONSTANT DEFINITION
 **************************************************************************/

/**************************************************************************
 *  DEBUG FLAG
 **************************************************************************/

/**************************************************************************
 *  LOCAL VARIABLE DECLARATION
 **************************************************************************/

/**************************************************************************
 *  FUNCTION IMPLEMENTATION
 **************************************************************************/

/******************************************************************************
 * meta_detection
 *
 * DESCRIPTION:
 *   Detect META mode is on or off
 *
******************************************************************************/
BOOL meta_detection(void)
{
	int mode = 0;
	mode = g_boot_arg->boot_mode &= 0x000000FF;

	dprintf(INFO,"[META] Check meta info from pre-loader: %x, %x, %d\n", g_boot_arg->boot_mode, g_boot_arg->maggic_number, mode);

	if (g_boot_arg->maggic_number == BOOT_ARGUMENT_MAGIC) {
		if (mode == META_BOOT) {
			g_boot_mode = META_BOOT;
			return TRUE;
		} else if (mode == ADVMETA_BOOT) {
			g_boot_mode = ADVMETA_BOOT;
			return TRUE;
		} else if (mode == ATE_FACTORY_BOOT) {
			g_boot_mode = ATE_FACTORY_BOOT;
			return TRUE;
		} else if (mode == ALARM_BOOT) {
			g_boot_mode = ALARM_BOOT;
			return TRUE;
		} else if (mode == FASTBOOT) {
			g_boot_mode = FASTBOOT;
			return TRUE;
		} else if (mode == FACTORY_BOOT) {
			g_boot_mode = FACTORY_BOOT;
			return TRUE;
		} else if (mode == RECOVERY_BOOT) {
			g_boot_mode = RECOVERY_BOOT;
			return TRUE;
		} else {
			return FALSE;
		}
	}
	return FALSE;
}

