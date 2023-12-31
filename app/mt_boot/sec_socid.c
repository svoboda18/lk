/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2019. All rights reserved.
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


#include <platform/mt_typedefs.h>
#include "sec_unlock.h"
#include "fastboot.h"
#include <video.h>
#include <string.h>
#include <debug.h>
#include <printf.h>
#include <verified_boot_common.h>
#include <verified_boot_error.h>
#include <boot_mode.h>
#include <pal_log.h>

extern BOOT_ARGUMENT *g_boot_arg;

static char int_to_str(char c)
{
	if (c <= 9)
		return (c + 48);

	return (c - 9) + 64;
}

uint32_t get_socid_chip(uint8_t *socid, uint32_t len)
{
	uint32_t ret = 0;

#ifdef MTK_SEC_SOCID_SUPPORT

	if (socid == NULL || g_boot_arg == NULL) {
		ret = ERR_VB_INVALID_ADDR;
		goto end;
	}

	memcpy(socid, g_boot_arg->socid, len);
#else
	if (socid == NULL) {
		ret = ERR_VB_INVALID_ADDR;
		goto end;
	}

	memset(socid, 0x0, len);
#endif

end:
	return ret;
}

void fastboot_get_socid(const char *arg, void *data, unsigned sz)
{
	uint32_t ret = 0;
	uint32_t i, j;
	char msg[128] = {0};
	char socid[SOC_ID_LEN] = {0};
	char socid_first_half[SOC_ID_LEN + 1] = {0};
	char socid_second_half[SOC_ID_LEN + 1] = {0};

	ret = get_socid_chip((uint8_t *)socid, SOC_ID_LEN);
	if (ret)
		goto end;

	/* separate 64 characters into two lines in order to fit fastboot
	 * message length.
	 */
	for (i = 0, j = 0; i < SOC_ID_LEN && j < (SOC_ID_LEN / 2); i += 2, j++) {
		socid_first_half[i] = int_to_str((socid[j] & 0xF0) >> 4);
		socid_first_half[i + 1] = int_to_str(socid[j] & 0x0F);
	}
	socid_first_half[SOC_ID_LEN] = '\0';

	for (i = 0, j = (SOC_ID_LEN / 2); i < SOC_ID_LEN && j < SOC_ID_LEN; i += 2, j++) {
		socid_second_half[i] = int_to_str((socid[j] & 0xF0) >> 4);
		socid_second_half[i + 1] = int_to_str(socid[j] & 0x0F);
	}
	socid_second_half[SOC_ID_LEN] = '\0';

	fastboot_info("dump socid...");
	fastboot_info(socid_first_half);
	fastboot_info(socid_second_half);
	fastboot_info("finish dump");

end:
	if (ret) {
		sprintf(msg, "\nget_socid failed - Err:0x%x \n", ret);
		fastboot_fail(msg);
	} else
		fastboot_okay("");
	return;
}

