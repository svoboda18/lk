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

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <video.h>
#include <verified_boot_common.h>
#include <dm_verity_status.h>

#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mtk_wdt.h>
#include <platform/mt_gpt.h>
#include <platform/vboot_keypad.h>
#include <pal_log.h>
#include <bootargs.h>
#include <recovery.h>

#define DM_VERITY_ERROR_WAIT_TIME (30000)

unsigned int g_verity_mode = VERITY_MODE_RESTART;

static void show_dm_verity_error(void)
{
	const char *title_msg = "dm-verity error\n\n";
	unsigned int wait_time = 0;

	video_clean_screen();
	video_set_cursor(video_get_rows() / 2, 0);
	video_printf(title_msg);
	video_printf("Android system on your device is corrupted.\n");
	video_printf("Please confirm whether you want to boot in\n");
	video_printf("EIO mode or RESTART mode. System will boot with\n");
	video_printf("RESTART mode automatically after 30 seconds\n");
	video_printf("(Volume UP)   : EIO mode.\n\n");
	video_printf("(Volume Down) : RESTART mode.\n\n");

	while (wait_time < DM_VERITY_ERROR_WAIT_TIME) {
		mtk_wdt_restart();
		if (mtk_detect_key(VBOOT_KEYPAD_VOL_UP)) {
			g_verity_mode = VERITY_MODE_EIO;
			break;
		} else if (mtk_detect_key(VBOOT_KEYPAD_VOL_DOWN)) {
			g_verity_mode = VERITY_MODE_RESTART;
			break;
		} else {
			/* ignore */
		}
		mdelay(100);
		wait_time += 100;
	}

	return;
}

void dm_verity_handler(uint32_t hashtree_error_mode)
{
	uint32_t status = 0;
	BOOL ota_result = FALSE;

	PAL_UNUSED_PARAM(hashtree_error_mode);

	get_dm_verity_status(&status);

	ota_result = check_ota_result();
	if (ota_result == TRUE) {
		pal_log_info("first boot after OTA.\n");
		clear_dm_verity_status();
		ota_result = clear_ota_result();
		if (ota_result != TRUE)
			pal_log_err("fail to clear ota result.\n");
		status = 0;
	}

	if (status) {
		show_dm_verity_error();
		if (g_verity_mode == VERITY_MODE_RESTART)
			cmdline_append("androidboot.veritymode=enforcing");
		else if (g_verity_mode == VERITY_MODE_EIO)
			cmdline_append("androidboot.veritymode=eio");
		else
			cmdline_append("androidboot.veritymode=enforcing");
		/* we don't clear dm-verity error currently */
	} else
		cmdline_append("androidboot.veritymode=enforcing");

	return;
}

