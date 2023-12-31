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
#include <sys/types.h>
#include <stdint.h>
#include <video.h>
#ifdef MTK_GPT_SCHEME_SUPPORT
#include <platform/partition.h>
#else
#include <mt_partition.h>
#endif
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <platform/verified_boot.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>
#include <platform/mt_gpt.h>
#include <platform/sec_status.h>
#include <platform/sec_export.h>
#include <bootimg.h>
#include <part_interface.h>
#include <part_status.h>

#include <verified_boot_common.h>
#include <pal_log.h>
#include <pal_typedefs.h>
#include <vboot_state.h>

#include <platform/vboot_keypad.h>

uint32_t g_boot_state = BOOT_STATE_GREEN;

extern bool cmdline_append(const char *append_string);
extern void mtk_wdt_restart(void);

int print_boot_state(void)
{
	int ret = 0;
	switch (g_boot_state) {
	case BOOT_STATE_ORANGE:
		pal_log_err("boot state: orange\n");
		break;
	case BOOT_STATE_YELLOW:
		pal_log_err("boot state: yellow\n");
		break;
	case BOOT_STATE_RED:
		pal_log_err("boot state: red\n");
		break;
	case BOOT_STATE_GREEN:
		pal_log_err("boot state: green\n");
		break;
	default:
		pal_log_err("boot state: unknown\n");
		break;
	}

	return ret;
}

int yellow_state_warning(void)
{
	unsigned char pubk[PUBK_LEN] = {0};
	int ret = 0;

	video_clean_screen();
	video_set_cursor(video_get_rows() / 2, 0);
	video_printf("yellow state\n\n");
	video_printf("Your device has loaded a different operating system\n");
	video_printf("ID:\n");

	ret = sec_get_pubk(pubk, PUBK_LEN);
	if (ret) {
		video_printf("Cannot get custom public key, abort in 5 seconds\n");
		mtk_wdt_restart();
		mdelay(5000);
		mtk_wdt_restart();
		return -1;
	}
	video_printf("%x %x %x %x %x %x %x %x\n", pubk[0], pubk[1], pubk[2], pubk[3],
		     pubk[4], pubk[5], pubk[6], pubk[7]);
	video_printf("Yes (Volume UP)   : Confirm and Boot.\n\n");
	video_printf("No  (Volume Down) : Abort.\n\n");

	while (1) {
		mtk_wdt_restart();
		if (mtk_detect_key(VBOOT_KEYPAD_VOL_UP))
			return 0;
		else if (mtk_detect_key(VBOOT_KEYPAD_VOL_DOWN))
			return -1;
		else {
			/* ignore */
		}
	}
}

int orange_state_warning(void)
{
	int ret = 0;

	video_clean_screen();
	video_set_cursor(video_get_rows() / 2, 0);
	video_printf("Orange State\n\n");
	video_printf("Your device has been unlocked and can't be trusted\n");
	video_printf("Your device will boot in 5 seconds\n");
	mtk_wdt_restart();
	mdelay(5000);
	mtk_wdt_restart();

	return ret;
}

int red_state_warning(const char *img_name)
{
	int ret = -1;
	char show_img_name[MAX_IMG_NAME_LEN] = {0};
	int copy_len;

	if (img_name != NULL) {
		copy_len = strlen(img_name);
		if (copy_len >= MAX_IMG_NAME_LEN)
			copy_len = MAX_IMG_NAME_LEN - 1;
		if (img_name[0] == '/') {
			memcpy((show_img_name + 1), img_name, copy_len - 1);
			show_img_name[copy_len - 1] = '\0';
		} else {
			memcpy(show_img_name, img_name, copy_len);
			show_img_name[copy_len] = '\0';
		}
	}

	video_clean_screen();
	video_set_cursor(video_get_rows() / 2, 0);
	video_printf("Red State\n\n");
	video_printf("Your device has failed verification and may not\n");
	video_printf("work properly.\n");
	video_printf("Please download %s image with correct signature\n", show_img_name);
	video_printf("or disable verified boot.\n");
	video_printf("Your device will reboot in 5 seconds.\n");
	mtk_wdt_restart();
	mdelay(5000);
	mtk_wdt_restart();

	return ret;
}

int show_warning(const char *img_name)
{
	int ret = 0;
	switch (g_boot_state) {
	case BOOT_STATE_ORANGE:
		ret = orange_state_warning();
		break;
	case BOOT_STATE_YELLOW:
#ifdef MTK_SECURITY_YELLOW_STATE_SUPPORT
		ret = yellow_state_warning();
		if (0 == ret) /* user confirms to boot into yellow state */
			break;
		/* fall into red state if user refuses to enter yellow state */
#else
		ret = -1;
		/* fall into red state since yellow state is not supported */
#endif
	case BOOT_STATE_RED:
		if (img_name == NULL)
			ret = red_state_warning("UNKNOWN");
		else
			ret = red_state_warning(img_name);

		ret = -1; /* return error */
		break;
	case BOOT_STATE_GREEN:
	default:
		break;
	}

	return ret;
}

int set_boot_state_to_cmdline()
{
	int ret = 0;

#ifndef MTK_SECURITY_SW_SUPPORT
	cmdline_append("androidboot.verifiedbootstate=orange");
#else
	switch (g_boot_state) {
	case BOOT_STATE_ORANGE:
		cmdline_append("androidboot.verifiedbootstate=orange");
		break;
	case BOOT_STATE_YELLOW:
		cmdline_append("androidboot.verifiedbootstate=yellow");
		break;
	case BOOT_STATE_RED:
		cmdline_append("androidboot.verifiedbootstate=red");
		break;
	case BOOT_STATE_GREEN:
		cmdline_append("androidboot.verifiedbootstate=green");
		break;
	default:
		break;
	}
#endif

	return ret;
}

void show_sec_reminder_warning(void)
{
	video_clean_screen();
	video_set_cursor(video_get_rows() / 2, 0);
	video_printf("Your device has wrong setting and may not\n");
	video_printf("work properly\n");
	video_printf("Your device will boot in 5 seconds\n");
	mtk_wdt_restart();
	mdelay(5000);
	mtk_wdt_restart();
	return;
}

