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

#include <string.h>

#include <pal_typedefs.h>
#include <pal_log.h>

#include <load_vfy_boot.h>
#include <bootimg.h>
#include <boot_opt.h>

#include <platform/boot_mode.h>

#define KERNEL_64_BIT "64"
#define KERNEL_32_BIT "32"
#define KERNEL_BIT_OFF (0x12)
#define BOOTOPT "bootopt="

int g_is_64bit_kernel = 0;

/* search "bootopt" string */
static int32_t get_bootopt_off(uint8_t *cmdline)
{
	int32_t i = 0;
	int32_t i_end = BOOTIMG_ARGS_SZ - 0x16;

	for (i = 0; i < i_end; i++) {
		const char *boot_opt = (const char *)&cmdline[i];
		if (0 == strncmp(boot_opt, BOOTOPT, strlen(BOOTOPT)))
			break;
	}

	if (i == i_end)
		i = -1;

	return i;
}

void platform_parse_bootopt(uint8_t *cmdline)
{
	int32_t i = 0;
	const char *kernel_bit;

	i = get_bootopt_off(cmdline);
	if (i == -1) {
		pal_log_err("Warning! No bootopt info!\n");
		return;
	}

	kernel_bit = (const char *)&cmdline[i + KERNEL_BIT_OFF];
	if (0 == strncmp(kernel_bit, KERNEL_64_BIT, strlen(KERNEL_64_BIT)))
		g_is_64bit_kernel = 1;
	else if (0 == strncmp(kernel_bit, KERNEL_32_BIT, strlen(KERNEL_32_BIT)))
		g_is_64bit_kernel = 0;

	/* no error handling when kernel bit string is not found */

	return;
}

