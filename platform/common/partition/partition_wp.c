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

#include <pal_typedefs.h>
#include <stdint.h>
#include <printf.h>
#include <string.h>
#include <platform/errno.h>
#include <platform/partition.h>
#include "partition_wp.h"
#include <part_interface.h>
#include <part_status.h>
#include <block_generic_interface.h>
#include <storage_api.h>
#include <pal_log.h>
#include "ufs_aio_core.h"
#include "ufs_aio_rpmb.h"
#include "mmc_core.h"

#ifndef MTK_EMMC_SUPPORT
unsigned int __attribute__((weak)) mmc_set_write_protect(int dev_num,u32 partition_id,
		unsigned long blknr,u32 blkcnt,STORAGE_WP_TYPE type)
{
	pal_log_info("%s is not supported\n", __func__);
	return -ENOSYS;
}
#endif

#ifndef MTK_UFS_SUPPORT
int __attribute__((weak)) ufs_set_write_protect(int dev_num, ufs_logical_unit partition,
		unsigned long blknr,u32 blkcnt, STORAGE_WP_TYPE type)
{
	pal_log_info("%s is not supported\n", __func__);
	return -ENOSYS;
}
#endif


int partition_write_prot_set(const char *start_part_name, const char *end_part_name, STORAGE_WP_TYPE type)
{
	int err = 0, start_region, end_region;
	unsigned long nr_wp_sects, start_sect, end_sect, end_nrsects;
	int32_t blksz = storage_get_blksz();
	part_dev_t *dev;

	if (blksz == 0) {
		dprintf(CRITICAL, "[Part_WP]invalid blksz\n");
		return -EINVAL;
	}

	if (partition_exists(start_part_name) == PART_NOT_EXIST) {
		dprintf(CRITICAL, "[Part_WP]Not found start partition %s info\n", start_part_name);
		return -EINVAL;
	}

	if (partition_exists(end_part_name) == PART_NOT_EXIST) {
		dprintf(CRITICAL, "[Part_WP]Not found end partition %s info\n", end_part_name);
		return -EINVAL;
	}

	start_sect = partition_get_offset_by_name(start_part_name) / blksz;
	start_region = partition_get_region_by_name(start_part_name);
	end_sect = partition_get_offset_by_name((char *) end_part_name) / blksz;
	end_nrsects = partition_get_size_by_name((char *) end_part_name) / blksz;
	end_region = partition_get_region_by_name((char *) end_part_name);

	if (start_region != end_region) {
		dprintf(CRITICAL, "[Part_WP]WP Range(region): %d->%d\n", start_region, end_region);
		return -EINVAL;
	}

	if (start_sect > end_sect) {
		dprintf(CRITICAL, "[Part_WP]WP Range(block): 0x%lx->0x%lx\n", start_sect, end_sect);
		return -EINVAL;
	}

	nr_wp_sects = end_sect + end_nrsects - start_sect;
	dprintf(CRITICAL, "[Part_WP]WP(%s->%s): Region(%d), start_sect(0x%lx), nr_blk(0x%lx), type(%d)\n",
		start_part_name, end_part_name, start_region, start_sect, nr_wp_sects, type);

	dev = mt_part_get_device();
	if (dev->blkdev->type == BOOTDEV_SDMMC)
		err = mmc_set_write_protect(0, start_region, start_sect, nr_wp_sects, type);
	else if (dev->blkdev->type == BOOTDEV_UFS)
		err = ufs_set_write_protect(0, start_region, start_sect, nr_wp_sects, type);

	return err;
}

