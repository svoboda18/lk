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

#include <stdlib.h>
#include <string.h>
#include <platform/partition.h>
#include <partition_wp.h>
#include <printf.h>
#include <platform/boot_mode.h>
#include <platform/mtk_wdt.h>
#include <platform/sec_export.h>
#include <env.h>
#include <pal_log.h>
#include "part_interface.h"
#include "bootctrl.h"
#include <platform/verified_boot.h>
#include <part_status.h>

#define WRITE_PROTECT_PARTITION_NAME_SZ (32)

#ifdef MTK_SIM_LOCK_POWER_ON_WRITE_PROTECT
int is_protect2_ready_for_wp(void);
int sync_sml_data(void);
#endif

void set_write_protect(void)
{
	int err;
	const char *ab_suffix = NULL;
	char wp_start[WRITE_PROTECT_PARTITION_NAME_SZ] = {0};
	char wp_end[WRITE_PROTECT_PARTITION_NAME_SZ] = {0};
	char tmp_name[WRITE_PROTECT_PARTITION_NAME_SZ] = {0};
	unsigned int pl_wp = 0;
	unsigned int system_wp = 0;
	unsigned int protect2_wp = 0;
#if defined(MTK_POWER_ON_WRITE_PROTECT)
	STORAGE_WP_TYPE wp_type = WP_POWER_ON;
#if defined(MTK_UFS_AWP)
	part_dev_t *dev;

	/* eMMC keep WP_POWER_ON, UFS change to WP_PERMANENT_AWP */
	dev = mt_part_get_device();
        if (dev->blkdev->type == BOOTDEV_UFS)
		wp_type = WP_PERMANENT_AWP;
#endif
#endif

	ab_suffix = (char *)get_suffix();
	if (ab_suffix == NULL) {
		dprintf(CRITICAL, "[%s] invalid address.\n", __func__);
		return ERR_INVALID_ADDR;
	}

	/* determine write protect policy */
	if (g_boot_mode == NORMAL_BOOT) {
#ifdef MTK_SIM_LOCK_POWER_ON_WRITE_PROTECT
		int sync_ret;
#endif
		pl_wp = 1;
		system_wp = 1;
#ifdef MTK_SIM_LOCK_POWER_ON_WRITE_PROTECT
		mtk_wdt_restart();

		sync_ret = sync_sml_data();
		if (0 != sync_ret)
			pal_log_info("sml data not sync\n");
		else
			pal_log_info("sml data sync \n");

		if (0 == is_protect2_ready_for_wp())
			protect2_wp = 1;
#endif //MTK_SIM_LOCK_POWER_ON_WRITE_PROTECT
	}

#ifdef MTK_UFS_OTP
	/* group 1, OTP must in 1st entry, cannot move */
	if (ufs_lk_otp_lock_req("otp") == 1) {
		pal_log_err("[%s] Lock OTP partition ... \n", __func__);
		err = partition_write_prot_set("otp", "otp", WP_PERMANENT);
		if (err != 0)
			pal_log_err("[%s]: Lock otp failed:%d\n", __func__, err);
	} else {
		pal_log_err("[%s] No Lock OTP partition ... \n", __func__);
	}
#endif /* MTK_UFS_OTP */
	/* Set OTP only */
	if (seclib_sec_boot_enabled(TRUE) == FALSE) {
		pal_log_err("Bypass write protect! \n");
		return;
	}

#if defined(MTK_POWER_ON_WRITE_PROTECT)
	/* perform write protect operation */
	/* group 2 */
	if (pl_wp) {
		pal_log_info("[%s] Lock boot region \n", __func__);
		err = partition_write_prot_set("preloader", "preloader", wp_type);
		if (err != 0)
			pal_log_err("[%s] Lock boot region failed: %d\n", __func__, err);
	}

	/* group 3 */
	if (system_wp) {
		memset(wp_start, 0, sizeof(char) * WRITE_PROTECT_PARTITION_NAME_SZ);
		memset(wp_end, 0, sizeof(char) * WRITE_PROTECT_PARTITION_NAME_SZ);

		if (ab_suffix[1] == 'a') {
			snprintf(wp_start, WRITE_PROTECT_PARTITION_NAME_SZ, "md1img_a");
			snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "logo");
		} else {
			snprintf(wp_start, WRITE_PROTECT_PARTITION_NAME_SZ, "sec1");
			snprintf(tmp_name, WRITE_PROTECT_PARTITION_NAME_SZ, "system_b");
			if (PART_OK == partition_exists(tmp_name))
				snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "system_b");
			else
				snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "tee_b");
		}

		pal_log_info("[%s]: Lock %s->%s\n", __func__, wp_start, wp_end);
		err = partition_write_prot_set(wp_start, wp_end, wp_type);
		if (err != 0)
			pal_log_err("[%s]: Lock %s->%s failed:%d\n",
				    __func__, wp_start, wp_end, err);
	}

	/* group 4 */
	memset(wp_start, 0, sizeof(char) * WRITE_PROTECT_PARTITION_NAME_SZ);
	memset(wp_end, 0, sizeof(char) * WRITE_PROTECT_PARTITION_NAME_SZ);

	if (protect2_wp)
		snprintf(wp_start, WRITE_PROTECT_PARTITION_NAME_SZ, "protect2");
	else
		snprintf(wp_start, WRITE_PROTECT_PARTITION_NAME_SZ, "seccfg");

	snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "seccfg");

	pal_log_info("[%s] Lock %s->%s\n", __func__, wp_start, wp_end);
	err = partition_write_prot_set(wp_start, wp_end, wp_type);
	if (err != 0)
			pal_log_err("[%s]: Lock %s->%s failed:%d\n",
				    __func__, wp_start, wp_end, err);
#endif
}

void write_protect_flow(void)
{
#if !defined(MACH_FPGA)
#if defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)

#ifdef MTK_SECURITY_SW_SUPPORT
	int ret = 0;

	set_write_protect();
	pal_log_err("write protect Done! \n");

#else
	pal_log_err("Bypass write protect! \n");
#endif // MTK_SECURITY_SW_SUPPORT

#endif // defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)
#endif // !defined(MACH_FPGA)
}

