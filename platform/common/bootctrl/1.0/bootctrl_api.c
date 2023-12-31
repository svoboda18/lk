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
#include <part_interface.h>
#include <string.h>
#include <block_generic_interface.h>
#include <platform/mt_typedefs.h>
#include "bootctrl.h"
#include "debug.h"
#include "mmc_core.h"
#include "mmc_common_inter.h"
#include "ufs_aio_hcd.h"

#define BOOTCTR_PARTITION "para"

static const char* suffix[2] = {BOOTCTRL_SUFFIX_A, BOOTCTRL_SUFFIX_B};
static boot_ctrl_t metadata_saved;
static int metadata_read = 0;

int check_suffix_with_slot(const char *suffix)
{
    int slot = -1;

    if(suffix == NULL) {
        pal_log_err("[LK] input suffix is NULL\n");
        return -1;
    }

    if(!strcmp(suffix, BOOTCTRL_SUFFIX_A)) {
        slot = 0;
    }
    else if(!strcmp(suffix, BOOTCTRL_SUFFIX_B)) {
        slot = 1;
    }
    else {
        pal_log_err("[LK] unknow slot suffix\n");
    }

   return slot;
}

static int read_write_partition_info(boot_ctrl_t *bctrl ,int mode)
{
    ssize_t boot_ctrl_size;
    int ret = -1;
    boot_ctrl_size = sizeof(boot_ctrl_t);

    if(bctrl == NULL) {
        pal_log_err("[LK] read_write_partition_info failed, bctrl is NULL\n");
        return ret;
    }

    if(mode == READ_PARTITION) {
      if ((metadata_read)  && (metadata_saved.magic == BOOTCTRL_MAGIC)) {
        memcpy(bctrl, &metadata_saved, sizeof(boot_ctrl_t));
      }
      else {
        ret = partition_read(BOOTCTR_PARTITION, (off_t)OFFSETOF_SLOT_SUFFIX, (u8 *)bctrl, (size_t)boot_ctrl_size);
        if (ret < 0) {
            pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
            return ret;
        }
        else {
          memcpy(&metadata_saved, bctrl, sizeof(boot_ctrl_t));
          metadata_read = 1;
        }
      }
    }
    else if(mode == WRITE_PARTITION) {
        ret = partition_write(BOOTCTR_PARTITION, (off_t)OFFSETOF_SLOT_SUFFIX, (u8 *)bctrl, (size_t)boot_ctrl_size);
        if (ret < 0) {
            pal_log_err("[LK] read_write_partition_info partition_write failed, unknown mode\n");
            return ret;
        }
        else {
            metadata_read = 0;  //force to read from partition after successful partition_write()
        }
    }
    else {
        pal_log_err("[LK] unknown mode, ret: 0x%x\n", ret);
        return ret;
    }

    return 0;
}

const char *get_suffix(void)
{
    int slot = 0, ret = -1;

    boot_ctrl_t metadata;

    ret = read_write_partition_info(&metadata, READ_PARTITION);
    if (ret < 0) {
        pal_log_err("[LK] read_partition_info failed, ret: 0x%x\n", ret);
        return NULL;
    }

    if(metadata.magic != BOOTCTRL_MAGIC) {
        pal_log_err("[LK] boot_ctrl magic number is not match\n");
        return NULL;
    }
    else {
        pal_log_err("[LK] boot_ctrl magic number is match, compare priority\n");

        if(metadata.slot_info[0].priority >= metadata.slot_info[1].priority)
           slot = 0;
        else if (metadata.slot_info[0].priority < metadata.slot_info[1].priority)
           slot = 1;
    }

    return suffix[slot];
}

static int set_boot_region(int slot)
{
    int ret = -1;
    u32 boot_part = 0;

    part_dev_t *dev;

    dev = mt_part_get_device();

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
         return ret;
#endif

    return ret;
}

int set_active_slot(const char *suffix)
{
    int slot = 0 ,slot1 = 0;
    int ret = -1;
    slot_metadata_t *slotp;

    boot_ctrl_t metadata;

    slot = check_suffix_with_slot(suffix);
    if(slot == -1) {
        pal_log_err("[LK] set_active_slot failed, slot: 0x%x\n", slot);
        return -1;
    }

    if(suffix == NULL) {
        pal_log_err("[LK] input suffix is NULL\n");
        return -1;
    }

    ret = read_write_partition_info(&metadata, READ_PARTITION);
    if(ret < 0) {
        pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
        return -1;
    }

    metadata.magic = BOOTCTRL_MAGIC;

    /* Set highest priority and reset retry count */
    slotp = &metadata.slot_info[slot];
    slotp->successful_boot = 0;
    slotp->priority = 7;
    slotp->retry_count = 3;
    slotp->normal_boot = 0;

    /* Re-set arg to another slot */
    slot1 = (slot == 0) ? 1 : 0;
    slotp = &metadata.slot_info[slot1];
    slotp->successful_boot = 0;
    slotp->priority = 6;
    slotp->retry_count = 3;
    slotp->normal_boot = 0;

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
    slot_metadata_t *slotp;
    boot_ctrl_t metadata;

    slot = check_suffix_with_slot(suffix);
    if(slot == -1) {
        pal_log_err("[LK] get_retry_count failed, slot: 0x%x\n", slot);
        return 0;
    }

    ret = read_write_partition_info(&metadata, READ_PARTITION);
    if (ret < 0) {
        pal_log_err( "[LK] partition_read failed, ret: 0x%x\n", ret);
        return 0;
    }

    slotp = &metadata.slot_info[slot];
    return slotp->retry_count;
}

int set_normal_boot(const char *suffix, int boot_mode)
{
    int slot = 0, ret = -1;
    slot_metadata_t *slotp;
    boot_ctrl_t metadata;

    slot = check_suffix_with_slot(suffix);
    if(slot == -1) {
        pal_log_err("[LK] set_not_normal_boot failed, slot: 0x%x\n", slot);
        return -1;
    }

    ret = read_write_partition_info(&metadata, READ_PARTITION);
    if(ret < 0) {
        pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
        return -1;
    }

    slotp = &metadata.slot_info[slot];
    slotp->normal_boot = boot_mode;

    ret = read_write_partition_info(&metadata, WRITE_PARTITION);
    if(ret < 0) {
        pal_log_err("[LK] partition_write failed, ret: 0x%x\n", ret);
        return -1;
    }

    return 0;
}

/* Return value:
    0: phone does not boot to home screen yet
    1: phone already boots to home screen
   -1: read misc partition error
*/
int get_bootup_status(const char *suffix)
{
    int slot = 0, ret = -1;
    slot_metadata_t *slotp;
    boot_ctrl_t metadata;

    slot = check_suffix_with_slot(suffix);
    if(slot == -1) {
        pal_log_err("set_not_normal_boot failed, slot: 0x%x\n", slot);
        return -1;
    }

    ret = read_write_partition_info(&metadata, READ_PARTITION);
    if(ret < 0) {
        pal_log_err("partition_read failed, ret: 0x%x\n", ret);
        return -1;
    }

    slotp = &metadata.slot_info[slot];
    return slotp->successful_boot;
}

/* Return value:
    0: slot is unbootable , retry_count equal to 0
    1: slot is bootable , retry_count larger than 0
   -1: read misc partition error
*/
int get_bootable_status(const char *suffix)
{
    int slot = 0, ret = -1;
    slot_metadata_t *slotp;
    boot_ctrl_t metadata;

    slot = check_suffix_with_slot(suffix);
    if(slot == -1) {
        pal_log_err("set_not_normal_boot failed, slot: 0x%x\n", slot);
        return -1;
    }

    ret = read_write_partition_info(&metadata, READ_PARTITION);
    if(ret < 0) {
        pal_log_err("partition_read failed, ret: 0x%x\n", ret);
        return -1;
    }

    slotp = &metadata.slot_info[slot];
    if(slotp->priority > 0)
           return 1;

    return 0;
}
