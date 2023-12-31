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
#include <platform/partition.h>
#include <platform/partition_wp.h>
#include <printf.h>
#include <platform/boot_mode.h>
#include <platform/mtk_wdt.h>
#include <env.h>
#include <platform/verified_boot.h>

#define WRITE_PROTECT_PARTITION_NAME_SZ (32)

int set_write_protect(void)
{
	int err = 0;
	char wp_start[WRITE_PROTECT_PARTITION_NAME_SZ] = {0};
	char wp_end[WRITE_PROTECT_PARTITION_NAME_SZ] = {0};

	if (g_boot_mode == NORMAL_BOOT) {
		dprintf(INFO, "[%s] Lock boot region \n", __func__);
		err = partition_write_prot_set("preloader", "preloader", WP_POWER_ON);

		if (err != 0) {
			dprintf(CRITICAL, "[%s] Lock boot region failed: %d\n", __func__, err);
			return err;
		}

		snprintf(wp_start, WRITE_PROTECT_PARTITION_NAME_SZ, "oemkeystore");
#ifdef MTK_SECURITY_SW_SUPPORT
		if (TRUE == seclib_sec_boot_enabled(TRUE))
			snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "system");
		else
			snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "tee2");
#else
		snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "tee2");
#endif
		dprintf(INFO, "[%s]: Lock %s->%s\n", __func__, wp_start, wp_end);
		err = partition_write_prot_set(wp_start, wp_end, WP_POWER_ON);
		if (err != 0) {
			dprintf(CRITICAL, "[%s]: Lock %s->%s failed:%d\n",
				__func__, wp_start, wp_end, err);
			return err;
		}
	}

	dprintf(INFO, "[%s] Lock seccfg\n", __func__);
	err = partition_write_prot_set("seccfg", "seccfg", WP_POWER_ON);
	if (err != 0) {
		dprintf(CRITICAL, "[%s]: Lock seccfg failed:%d\n", __func__, err);
		return err;
	}

	return 0;
}

void write_protect_flow(void)
{
#if defined(MTK_POWER_ON_WRITE_PROTECT) && !defined(MACH_FPGA)
#if MTK_POWER_ON_WRITE_PROTECT == 1
#if defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)

	int bypass_wp = 0;
	int ret = 0;

#ifndef USER_BUILD
	bypass_wp = atoi(get_env("bypass_wp"));
	dprintf(ALWAYS, "bypass write protect flag = %d! \n", bypass_wp);
#endif

	if (!bypass_wp) {
		ret = set_write_protect();
		if (ret != 0)
			dprintf(CRITICAL, "write protect fail! \n");
		dprintf(ALWAYS, "write protect Done! \n");
	} else
		dprintf(ALWAYS, "Bypass write protect! \n");
#endif
#endif
#endif
}

