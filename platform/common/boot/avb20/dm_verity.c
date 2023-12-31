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
#include <avb_slot_verify.h>
#include <platform/mt_pmic.h>

#define DM_VERITY_ERROR_WAIT_TIME (5000)

unsigned int g_verity_mode = VERITY_MODE_RESTART;

static void show_dm_verity_error(void)
{
	unsigned int wait_time = 0;

	video_clean_screen();
	video_set_cursor(video_get_rows() / 2, 0);
	video_printf("dm-verity corruption\n\n");
	video_printf("Your device is corrupt.\n");
	video_printf("It can't be trusted and may not work properly.\n");
	video_printf("Press power button to continue.\n");
	video_printf("Or, device will power off in %ds\n", DM_VERITY_ERROR_WAIT_TIME / 1000);

	while (wait_time < DM_VERITY_ERROR_WAIT_TIME) {
		if (mtk_detect_key(MTK_PMIC_PWR_KEY))
			return;
		mdelay(100);
		wait_time += 100;
	}
#ifndef NO_POWER_OFF
#ifdef MTK_PMIC_POWER_OFF
	mt_power_off();
#else
	mt6575_power_off();
#endif
#endif
	return;
}

void dm_verity_handler(AvbHashtreeErrorMode hashtree_error_mode)
{
#ifdef AVB_PERSIST_VALUE_SUPPORT
	if (hashtree_error_mode == AVB_HASHTREE_ERROR_MODE_EIO)
		show_dm_verity_error();
#else
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

	if (status)
		show_dm_verity_error();
#endif
	return;
}

void get_hash_tree_error_mode(uint32_t *hashtree_error_mode)
{
#ifdef AVB_PERSIST_VALUE_SUPPORT
	*hashtree_error_mode = AVB_HASHTREE_ERROR_MODE_MANAGED_RESTART_AND_EIO;
#else
	*hashtree_error_mode = AVB_HASHTREE_ERROR_MODE_RESTART_AND_INVALIDATE;
#endif
	return;
}

