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
#include <partition_wp.h>
#include <printf.h>
#include <platform/boot_mode.h>
#include <platform/mtk_wdt.h>
#include <env.h>
#include <platform/verified_boot.h>

#include "bootctrl.h"

#define WRITE_PROTECT_PARTITION_NAME_SZ (32)

/* check if protect2 is formatted and unmounted correctly. */
static int is_fs_partition_ready_for_wp(const char *part_name)
{
	int part_index = 0;
	int part_id = 0;
	unsigned long fs_part_offset = 0;
	unsigned long fmt_offset = 0x438; /* ext4 offset where the magic exists */
	unsigned long unmount_offset = 0x460; /* check clean unmount flag */
	unsigned char ext4_magic[2] = {0x53, 0xEF};
	unsigned long read_size = 16;
	unsigned long len;
	unsigned char buf[16] = {0};
	int i = 0;
	int ret = 0;

	/* -----------------------------------  */
	/* Get Partition Offset                 */
	/* -----------------------------------  */
	part_index = partition_get_index(part_name);

	if (part_index == -1) {
		dprintf(CRITICAL, "partition not found\n");
		ret = -1;
		goto _exit;
	}

	fs_part_offset = partition_get_offset(part_index);
	/* return offset is always positivie, negative should indicate a failure.
	   this should be fixed in partition_get_offset */
	if (fs_part_offset < 0) {
		dprintf(CRITICAL, "%s offset not found\n", part_name);
		ret = -2;
		goto _exit;
	}

	dprintf(INFO, "%s off:0x%x \n", part_name, fs_part_offset);
	dprintf(INFO, "[before] buf read:0x%x, 0x%x\n", buf[0], buf[1]);
	/* ---------------------------------------- */
	/* reading data at offset 0x438 for format  */
	/* ---------------------------------------- */
	len = emmc_read(part_id, fs_part_offset + fmt_offset, buf, read_size);

	dprintf(INFO, "buf read:0x%x, 0x%x\n", buf[0], buf[1]);

	if (len != read_size) {
		dprintf(CRITICAL, "emmc_read failed!!\n");
		ret = -3;
		goto _exit;
	}

	/* ---------------------------------------- */
	/* checking magic 0xEF53 at offset 0x438    */
	/* ---------------------------------------- */
	for (i = 0 ; i < 2; i++) {
		if (ext4_magic[i] != buf[i]) {
			ret = -4;
			dprintf(CRITICAL, "%s ext4 magic not match!!\n", part_name);
			goto _exit;
		}
	}

	dprintf(INFO, "%s ext4 magic match!!\n", part_name);

	/* ----------------------------------------------- */
	/* reading data at offset 0x460 for clean unmount  */
	/* ----------------------------------------------- */
	len = emmc_read(part_id, fs_part_offset + unmount_offset, buf, read_size);

	dprintf(INFO, "buf read:0x%x, 0x%x\n", buf[0], buf[1]);

	if (len != read_size) {
		dprintf(CRITICAL, "emmc_read failed!!\n");
		ret = -5;
		goto _exit;
	}

	/* ------------------------------------------------------------------------- */
	/* checking offset 460h,  bit 2 (0x4) is clear(0) , 1 means recovery is on-going*/
	/* ------------------------------------------------------------------------- */
	if (0 == (buf[0] & 0x4))
		dprintf(INFO, "%s did not perform journal recovery !!\n", part_name);

	else {
		ret = -6;
		dprintf(CRITICAL,
			"%s is not clean-unmounted, journal recovery may not finish!!\n", part_name);
		goto _exit;
	}

_exit:
	return ret;
}

int set_write_protect(void)
{
	int err = 0;
	char *ab_suffix = NULL;
	char wp_start[WRITE_PROTECT_PARTITION_NAME_SZ] = {0};
	char wp_end[WRITE_PROTECT_PARTITION_NAME_SZ] = {0};

	ab_suffix = get_suffix();
	if (ab_suffix == NULL) {
		dprintf(CRITICAL, "[%s] AB: fetch active system failed\n", __func__);
		return -1;
	}

	if (g_boot_mode == NORMAL_BOOT) {
		dprintf(INFO, "[%s] Lock boot region \n", __func__);
		err = partition_write_prot_set("preloader", "preloader", WP_POWER_ON);

		if (err != 0) {
			dprintf(CRITICAL, "[%s] Lock boot region failed: %d\n", __func__, err);
			return err;
		}

#ifdef MTK_PERSIST_PARTITION_SUPPORT
		if (0 == is_fs_partition_ready_for_wp("persist")) {
			dprintf(CRITICAL, "[%s]: persist is fmt\n", __func__);
			snprintf(wp_start, WRITE_PROTECT_PARTITION_NAME_SZ, "persist");
		} else
			snprintf(wp_start, WRITE_PROTECT_PARTITION_NAME_SZ, "sec1");
#else
		snprintf(wp_start, WRITE_PROTECT_PARTITION_NAME_SZ, "sec1");
#endif
		snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "logo");

		dprintf(INFO, "[%s]: Lock %s->%s \n", __func__, wp_start, wp_end);
		err = partition_write_prot_set(wp_start, wp_end, WP_POWER_ON);
		if (err != 0) {
			dprintf(CRITICAL, "[%s]: Lock %s->%s failed:%d\n",
				__func__, wp_start, wp_end, err);
			return err;
		}

		memset(wp_start, 0, sizeof(char) * WRITE_PROTECT_PARTITION_NAME_SZ);
		memset(wp_end, 0, sizeof(char) * WRITE_PROTECT_PARTITION_NAME_SZ);
		snprintf(wp_start, WRITE_PROTECT_PARTITION_NAME_SZ, "md1img%s", ab_suffix);
#ifdef MTK_SECURITY_SW_SUPPORT
		if (TRUE == seclib_sec_boot_enabled(TRUE))
			snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "system%s", ab_suffix);
		else
			snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "tee%s", ab_suffix);
#else
		snprintf(wp_end, WRITE_PROTECT_PARTITION_NAME_SZ, "tee%s", ab_suffix);
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
}

