/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2016. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */
#include <stdint.h>
#include <pal_typedefs.h>
#include <pal_log.h>
#include <libavb/libavb.h>
#include <part_interface.h>
#include <string.h>
#include <platform/mt_typedefs.h>
#include <block_generic_interface.h>
#include "part_dev.h"
#include "bootctrl.h"
#include "debug.h"
#include "mmc_core.h"
#include "mmc_common_inter.h"
#include "ufs_aio_hcd.h"

#define BOOTCTR_PARTITION "misc"

static const char *suffix[2] = {BOOTCTRL_SUFFIX_A, BOOTCTRL_SUFFIX_B};
static AvbABData metadata_saved;
static int metadata_read = 0;

int check_suffix_with_slot(const char *suffix)
{
	int slot = -1;

	if (suffix == NULL) {
		pal_log_err("[LK] input suffix is NULL\n");
		return -1;
	}

	if (!strcmp(suffix, BOOTCTRL_SUFFIX_A))
		slot = 0;
	else if (!strcmp(suffix, BOOTCTRL_SUFFIX_B))
		slot = 1;
	else
		pal_log_err("[LK] unknow slot suffix\n");

	return slot;
}

static int read_write_partition_info_backup_restore_bootctrlv1(boot_ctrl_t *bctrl ,int mode,int offset)
{
	ssize_t boot_ctrl_size;
	int ret = -1;
	boot_ctrl_size = sizeof(boot_ctrl_t);

	if (bctrl == NULL) {
		pal_log_err("[LK] read_write_partition_info failed, bctrl is NULL\n");
		return ret;
	}

	if (mode == READ_PARTITION) {

			ret = partition_read(BOOTCTR_PARTITION, (off_t)OFFSETOF_SLOT_SUFFIX + offset,
					     (u8 *)bctrl, (size_t)boot_ctrl_size);
			if (ret < 0) {
				pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
				return ret;
			}
	} else if (mode == WRITE_PARTITION) {

		ret = partition_write(BOOTCTR_PARTITION, (off_t)OFFSETOF_SLOT_SUFFIX + offset,
				      (u8 *)bctrl, (size_t)boot_ctrl_size);
		if (ret < 0) {
			pal_log_err("[LK] read_write_partition_info partition_write failed, unknown mode\n");
			return ret;
		}
	} else {
		pal_log_err("[LK] unknown mode, ret: 0x%x\n", ret);
		return ret;
	}

	return 0;
}


static int read_write_partition_info(AvbABData *bctrl, int mode)
{
	ssize_t boot_ctrl_size;
	int ret = -1;
    boot_ctrl_t metadatabootctrlv1;    
	slot_metadata_t *slotp;
	boot_ctrl_size = sizeof(AvbABData);

	if (bctrl == NULL) {
		pal_log_err("[LK] read_write_partition_info failed, bctrl is NULL\n");
		return ret;
	}

	if (mode == READ_PARTITION) {
		if ((metadata_read) &&
		    (!memcmp(metadata_saved.magic, AVB_AB_MAGIC, AVB_AB_MAGIC_LEN)))
			memcpy(bctrl, &metadata_saved, sizeof(AvbABData));
		else {
			ret = partition_read(BOOTCTR_PARTITION, (off_t)OFFSETOF_SLOT_SUFFIX,
					     (u8 *)bctrl, (size_t)boot_ctrl_size);
			if (ret < 0) {
				pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
				return ret;
			} else {
				memcpy(&metadata_saved, bctrl, sizeof(AvbABData));
				metadata_read = 1;
			}
		}
	} else if (mode == WRITE_PARTITION) {
#ifdef MTK_AVB20_SUPPORT
		bctrl->crc32 = avb_htobe32(
				       avb_crc32((const uint8_t *)bctrl, sizeof(AvbABData) - sizeof(uint32_t)));
#endif
		ret = partition_write(BOOTCTR_PARTITION, (off_t)OFFSETOF_SLOT_SUFFIX,
				      (u8 *)bctrl, (size_t)boot_ctrl_size);
		if (ret < 0) {
			pal_log_err("[LK] read_write_partition_info partition_write failed, unknown mode\n");
			return ret;
		} else {
			metadata_read =
				0;  //force to read from partition after successful partition_write()
		}
	} else {
		pal_log_err("[LK] unknown mode, ret: 0x%x\n", ret);
		return ret;
	}

	return 0;
}

const char *get_suffix(void)
{
	int slot = 0, ret = -1;

	AvbABData metadata;

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] read_partition_info failed, ret: 0x%x\n", ret);
		return NULL;
	}

	if (memcmp(metadata.magic, AVB_AB_MAGIC, AVB_AB_MAGIC_LEN) != 0) {
		pal_log_err("[LK] boot_ctrl magic number is not match %s , AVB_AB_MAGIC = %s\n",
			    metadata.magic, AVB_AB_MAGIC);
		return NULL;
	} else {
		pal_log_err("[LK] boot_ctrl magic number is match, compare priority\n");

		if (metadata.slots[0].priority >= metadata.slots[1].priority)
			slot = 0;
		else if (metadata.slots[0].priority < metadata.slots[1].priority)
			slot = 1;
	}

	return suffix[slot];
}

static int set_boot_region(int slot)
{
    int ret = -1;
    u32 boot_part = 0;
    boot_ctrl_t metadatabootctrlv1;    
	slot_metadata_t *slotp;

    part_dev_t *dev;

    dev = mt_part_get_device();
	if(slot == 1)
	{
		// restore bootctrv1
		read_write_partition_info_backup_restore_bootctrlv1(&metadatabootctrlv1,READ_PARTITION,32);
		if(metadatabootctrlv1.magic == BOOTCTRL_MAGIC){
			slotp = &metadatabootctrlv1.slot_info[1];
			slotp->successful_boot = 0;
			slotp->priority = 7;
			slotp->retry_count = 3;
			slotp->normal_boot = 1;

			slotp = &metadatabootctrlv1.slot_info[0];
            slotp->successful_boot = 0;
			slotp->priority = 0;
			slotp->retry_count = 0;
			slotp->normal_boot = 0;
			read_write_partition_info_backup_restore_bootctrlv1(&metadatabootctrlv1,WRITE_PARTITION,0);
		}
    }

    if(slot == 0) {
#if defined(MTK_EMMC_SUPPORT)
        if (dev->blkdev->type == BOOTDEV_SDMMC)
            boot_part = EMMC_PART_BOOT1;
#endif
#if defined(MTK_UFS_SUPPORT)
        if (dev->blkdev->type == BOOTDEV_UFS)
            boot_part = ATTR_B_BOOT_LUN_EN_BOOT_LU_A;
#endif
    } else if(slot == 1) {
#if defined(MTK_EMMC_SUPPORT)
        if (dev->blkdev->type == BOOTDEV_SDMMC)
            boot_part = EMMC_PART_BOOT2;
#endif
#if defined(MTK_UFS_SUPPORT)
        if (dev->blkdev->type == BOOTDEV_UFS)
            boot_part = ATTR_B_BOOT_LUN_EN_BOOT_LU_B;
#endif
    }

#if defined(MTK_EMMC_SUPPORT)
        if (dev->blkdev->type == BOOTDEV_SDMMC) {
            ret = mmc_set_boot_part(boot_part);
            return ret;
        }
#endif

#if defined(MTK_UFS_SUPPORT)
         extern struct ufs_hba g_ufs_hba;
         struct ufs_hba *hba = &g_ufs_hba;
         ret = ufs_aio_set_boot_lu(hba, boot_part);
#endif

    return ret;
}

int set_active_slot(const char *suffix)
{
	int slot = 0, slot1 = 0;
	int ret = -1;
	AvbABSlotData *slotp;

	AvbABData metadata;

	slot = check_suffix_with_slot(suffix);
	if (slot == -1) {
		pal_log_err("[LK] set_active_slot failed, slot: 0x%x\n", slot);
		return -1;
	}

	if (suffix == NULL) {
		pal_log_err("[LK] input suffix is NULL\n");
		return -1;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
		return -1;
	}

	memcpy(metadata.magic, AVB_AB_MAGIC, AVB_AB_MAGIC_LEN);

	/* Set highest priority and reset retry count */
	slotp = &metadata.slots[slot];
	slotp->successful_boot = 0;
	slotp->priority = AVB_AB_MAX_PRIORITY;
	slotp->tries_remaining = AVB_AB_MAX_TRIES_REMAINING;

	/* Ensure other slot doesn't have as high a priority. */
	slot1 = (slot == 0) ? 1 : 0;
	slotp = &metadata.slots[slot1];
	if (slotp->priority == AVB_AB_MAX_PRIORITY)
		slotp->priority = AVB_AB_MAX_PRIORITY - 1;

        /* Switch boot part in boot region */
        ret = set_boot_region(slot);
        if (ret < 0) {
            pal_log_err("[LK] set boot part to slot %d fail, ret: 0x%x\n", slot, ret);
            return -1;
        }

	ret = read_write_partition_info(&metadata, WRITE_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_write failed, ret: 0x%x\n", ret);
		return -1;
	}

	return 0;
}

uint8_t get_retry_count(const char *suffix)
{
	int slot = 0;
	int ret = -1;
	AvbABData metadata;

	slot = check_suffix_with_slot(suffix);
	if (slot == -1) {
		pal_log_err("[LK] get_retry_count failed, slot: 0x%x\n", slot);
		return 0;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
		return 0;
	}

	return metadata.slots[slot].tries_remaining;
}

/* Return value:
    0: phone does not boot to home screen yet
    1: phone already boots to home screen
   -1: read misc partition error
*/
int get_bootup_status(const char *suffix)
{
	int slot = 0, ret = -1;
	AvbABData metadata;

	slot = check_suffix_with_slot(suffix);
	if (slot == -1) {
		pal_log_err("set_not_boot_mode failed, slot: 0x%x\n", slot);
		return -1;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("partition_read failed, ret: 0x%x\n", ret);
		return -1;
	}

	return metadata.slots[slot].successful_boot;
}

/* Return value:
    0: slot is unbootable , tries_remaining equal to 0
    1: slot is bootable , tries_remaining larger than 0
   -1: read misc partition error
*/
int get_bootable_status(const char *suffix)
{
	int slot = 0, ret = -1;
	AvbABData metadata;

	slot = check_suffix_with_slot(suffix);
	if (slot == -1) {
		pal_log_err("get_bootable_status failed, slot: 0x%x\n", slot);
		return -1;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("partition_read failed, ret: 0x%x\n", ret);
		return -1;
	}

	if (metadata.slots[slot].priority > 0)
		return 1;

	return 0;
}

int increase_tries_remaining(void)
{
	int slot = 0, ret = -1;
	AvbABSlotData *slotp;
	AvbABData metadata;
	const char *suffix = NULL;

	suffix = get_suffix();
	slot = check_suffix_with_slot(suffix);
	if (slot == -1) {
		pal_log_err("[LK] check_suffix_with_slot failed, slot: 0x%x\n", slot);
		return -1;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
		return -1;
	}

	slotp = &metadata.slots[slot];
	if (slotp->tries_remaining < AVB_AB_MAX_TRIES_REMAINING &&
	    slotp->tries_remaining > 0 && !slotp->successful_boot)
		slotp->tries_remaining++;

	ret = read_write_partition_info(&metadata, WRITE_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_write failed, ret: 0x%x\n", ret);
		return -1;
	}

	return 0;
}
