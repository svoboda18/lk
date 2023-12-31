/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#ifdef MTK_GPT_SCHEME_SUPPORT
#include <platform/partition.h>
#else
#include <mt_partition.h>
#endif
#ifdef MTK_PARTITION_COMMON
#include <env.h>
#else
#include <platform/env.h>
#endif
#include <platform/mtk_wdt.h>

#include "aee.h"
#include "mrdump_private.h"

#include <efi.h>
#include <pal_log.h>
#include <lib/crc.h>
#include <part_interface.h>
#include <dev/aee_platform_debug.h>

#ifndef min
#define min(x, y)   (x < y ? x : y)
#endif

#define BLKSIZE		 4096
#define MAX_CONTINUE	 16			 // only 1MB memory for lk
#define EXSPACE		 (BLKSIZE*MAX_CONTINUE)  // Expect continue space
#define DATA_SIZE_MIN  5368709120                // 5GB
#define BYTE_SIZE_16MB 16777216

/*For gpt update*/
extern part_t *partition;
extern int gpt_partition_table_update(const char *arg, void *data, unsigned sz);
extern int read_gpt(part_t *part);

struct mrdump_part_handle {
	struct mrdump_dev *dumpdev;
	uint64_t filesize;
	uint64_t woffset;
	int midx;
	uint8_t data[EXSPACE];
};

// Store data and write when buffer(handle's data) full
// return left length to avoid recursive call. --> turn to for loop
static int Do_Store_or_Write(struct mrdump_part_handle *handle, uint8_t *buf, uint32_t Length)
{
	unsigned int leftspace, mylen, reval;

	leftspace = EXSPACE - handle->midx;

	// Check Length
	if (Length > leftspace) {
		mylen = leftspace;
		reval = Length - leftspace;
	} else {
		mylen = Length;
		reval = 0;
	}

	// Store
	while (mylen > 0) {
		handle->data[handle->midx] = *buf;
		handle->midx++;
		buf++;
		mylen--;
	}

	// Write
	if (handle->midx == EXSPACE) {
		if (!handle->dumpdev->write(handle->dumpdev, handle->woffset, handle->data, EXSPACE)) {
			voprintf_error(" SDCard: Write dump data failed.\n");
			return -1;
		}

		handle->woffset = handle->woffset + EXSPACE;
		handle->midx = 0;
	}
	return reval;
}

static int lba_write_cb(void *opaque_handle, void *buf, int size)
{
	unsigned int	len, moves;
	int			 ret;
	uint8_t		 *Ptr;

	struct mrdump_part_handle *handle = opaque_handle;

	handle->filesize += size;

	// End of File, write the left Data in handle data buffer...
	if ((buf == NULL) && (size == 0)) {
		if (!handle->dumpdev->write(handle->dumpdev, handle->woffset, handle->data, handle->midx)) {
			voprintf_error(" SDCard: Write dump data failed.\n");
			return -1;
		}
		return 0;
	}

	// buf should not be NULL if not EOF
	if (buf == NULL)
		return -1;

	// process of Store and write
	len = size;
	ret = len;
	Ptr = (uint8_t *)buf;
	while (1) {
		ret = Do_Store_or_Write(handle, Ptr, len);
		if (ret < 0) {
			voprintf_error(" SDCard: Store and Write failed.\n");
			return -1;
		} else if (ret==0) {
			break;
		} else {
			moves = len - ret;
			Ptr  += moves;
			len   = ret;
		}
	}
	return size;
}

int mrdump_partition_output(const struct mrdump_control_block *mrdump_cb, const struct kzip_addlist *memlist, struct mrdump_dev *mrdump_dev)
{
	uint8_t InfoHeader[MRDUMP_PAF_TOTAL_SIZE];
	unsigned int mycrc;
	u64 mrdump_total_sect;
	part_dev_t *dev = mt_part_get_device();

	if (mrdump_dev == NULL) {
		return -1;
	}

	voprintf_info("Output to dynmaic Partition %s\n", mrdump_dev->name);

	mrdump_total_sect = partition_get_size_by_name("mrdump") / dev->blkdev->blksz;
	if (mrdump_total_sect == (BYTE_SIZE_16MB / dev->blkdev->blksz)) {
		voprintf_error("mrdump partition only 16MB\n");
		return -1;
	}

	// pre-work for dynamic partition header
	bzero(InfoHeader, sizeof(InfoHeader));

	if (!mrdump_dev->read(mrdump_dev, 0ULL, (uint8_t *)InfoHeader, sizeof(InfoHeader))) {
		voprintf_error(" SDCard: Reading InfoHeader failed.\n");
		return -1;
	}

	struct mrdump_part_handle *handle = memalign(16, sizeof(struct mrdump_part_handle));
	if (handle == NULL) {
		voprintf_error("No enough memory.\n");
		return -1;
	}
	memset(handle, 0, sizeof(struct mrdump_part_handle));
	handle->dumpdev = mrdump_dev;

	// Mark coredump as ULLONG_MAX to verify the unknown interrupt case during dumping data
	*(uint64_t *)(InfoHeader + MRDUMP_PAF_COREDUMPSIZE) = ULLONG_MAX;

	//calculate the CRC
	mycrc = crc32(0L, NULL, 0);
	*(uint32_t *)(InfoHeader + MRDUMP_PAF_CRC32) = crc32(mycrc, (const unsigned char*)InfoHeader, MRDUMP_LBA_DATAONLY);

	//update the coredump size and CRC
	if (!handle->dumpdev->write(handle->dumpdev, 0ULL, (uint8_t *)InfoHeader, sizeof(InfoHeader))) {
			voprintf_error(" SDCard: Write InfoHeader error.\n");
			free(handle);
			return -1;
	}

	// Starting Dumping Data
	handle->woffset = BLKSIZE;
	mtk_wdt_restart();

	bool ok = true;
	mtk_wdt_restart();

	struct kzip_file *zf = kzip_open(handle, lba_write_cb);
	if (zf != NULL) {
		if (!kzip_add_file(zf, memlist, "SYS_COREDUMP")) {
			ok = false;
		}
		mtk_wdt_restart();
		kzip_close(zf);
		lba_write_cb(handle, NULL, 0); /* really write onto emmc of the last part */
	} else {
		ok = false;
	}

	if (!ok) {
		free(handle);
		return -1;
	}

	voprintf_info(" Zip COREDUMP size is: %lld\n", handle->filesize);

	// Record File Size...
	*(uint64_t *)(InfoHeader + MRDUMP_PAF_COREDUMPSIZE) = handle->filesize;

	mycrc = crc32(0L, NULL, 0);
	*(uint32_t *)(InfoHeader + MRDUMP_PAF_CRC32) = crc32(mycrc, (const unsigned char*)InfoHeader, MRDUMP_LBA_DATAONLY);

	if (!handle->dumpdev->write(handle->dumpdev, 0ULL, (uint8_t *)InfoHeader, sizeof(InfoHeader))) {
		voprintf_error(" SDCard: Write InfoHeader error.\n");
		free(handle);
		return -1;
	}
	free(handle);

	mtk_wdt_restart();
	mrdump_status_ok("OUTPUT:%s\nMODE:%s\n", "PARTITION_DATA", mrdump_mode2string(mrdump_cb->crash_record.reboot_mode));

	return 0;
}

/*
 ********** Definition of GPT buffer **********
 */
static void w2s(u8 *dst, int dst_max, u16 *src, int src_max)
{
	int i = 0;
	int len = min(src_max, dst_max - 1);

	while (i < len) {
		if (!src[i]) {
			break;
		}
		dst[i] = src[i] & 0xFF;
		i++;
	}

	dst[i] = 0;

	return;
}

static int read_data(u8 *buf, u32 part_id, u64 lba, u64 size)
{
	int err;
	part_dev_t *dev;

	dev = mt_part_get_device();
	if (!dev) {
		pal_log_err("%s: read data, err(no dev)\n", __func__);
		return 1;
	}

	err = dev->read(dev, lba * dev->blkdev->blksz, buf, (int)size, part_id);
	if (err != (int)size) {
		pal_log_err("%s: read data, err(%d)\n", __func__, err);
		return err;
	}

	return 0;
}

static int write_data(u64 lba, u8 *buf, u64 size, u32 part_id)
{
	int err;
	part_dev_t *dev;

	dev = mt_part_get_device();
	if (!dev) {
		pal_log_err("%s: write data, err(no dev)\n", __func__);
		return 1;
	}
	err = dev->write(dev, buf, lba * dev->blkdev->blksz, (int)size, part_id);
	if (err != (int)size) {
		pal_log_err("%s: write data, err(%d)\n", __func__, err);
		return err;
	}

	return 0;
}

static int mrdump_get_part_index(const char *part_name)
{
	int index;
#ifdef MTK_AB_OTA_UPDATER
	int predef_part_num = 3; // preloader, preloader_a, preloader_b
#else
	int predef_part_num = 1; // preloader
#endif
	index = partition_get_index_by_name(part_name) - predef_part_num;

	if (index < 0)
		return -1;
	else
		return index;
}

/*
 * method=0 : mean reduce mrdump patition to SIZE_16MB
 * method=1 : mean extend mrdump partition to DRAM_SIZE + SIZE_16MB
 */
int mrdump_gpt_resize(int method)
{
	int err;
	uint8_t data_name[PART_META_INFO_NAMELEN];
	uint8_t mrdump_name[PART_META_INFO_NAMELEN];
	u32 part_id, gpt_entries_size;
	int data_index, mrdump_index;
	part_dev_t *dev = mt_part_get_device();
	gpt_entry *entries;
	u64 total_dump_size = physical_memory_size();
	u64 dram_total_sect = total_dump_size / dev->blkdev->blksz;
	u64 data_total_sect, mrdump_total_sect;
	u64 sz;
	u8 *data;

	part_id = dev->blkdev->part_user;
	gpt_entries_size = sizeof(gpt_entry) * PART_MAX_COUNT;
	sz = dev->blkdev->blksz + gpt_entries_size;
	data = (u8 *)malloc(sz);
	if (data == NULL) {
		voprintf_error("%s: malloc return NULL\n", __func__);
		return -1;
	}
	/* get gpt header + entries */
	err = read_data(data, part_id, 1, sz);
	if (err) {
		voprintf_error("%s: read entries(part_id=%d), err(%d)\n",
				__func__, part_id, err);
		free(data);
		return err;
	}

	/* parse pgpt entries */
	entries = (gpt_entry *)(data + dev->blkdev->blksz);

	mrdump_index = mrdump_get_part_index("mrdump");
	if (mrdump_index < 0) {
		voprintf_error("%s: Can't get mrdump partition index\n", __func__);
		goto fail;
	}
	w2s(mrdump_name, PART_META_INFO_NAMELEN, entries[mrdump_index].partition_name, GPT_ENTRY_NAME_LEN);

	data_index = mrdump_get_part_index("userdata");
	if (data_index < 0) {
		voprintf_error("%s: Can't get userdata partition index\n", __func__);
		goto fail;
	}
	w2s(data_name, PART_META_INFO_NAMELEN, entries[data_index].partition_name, GPT_ENTRY_NAME_LEN);

	/* resize policy
	 * method = 0
	 *	1. set mrdump partition to 16MB when it's size !=16MB
		   and extend data partition
	 * method = 1
	 * 	1. data total size should be large or equal to DATA_SIZE_MIN
	 * 	2. only do extend when mrdump total size less than DRAM size + 16MB
	 * 	3. must meet 1. and 2. requirement
	 */
	data_total_sect = partition_get_size_by_name("userdata") / dev->blkdev->blksz;
	mrdump_total_sect = partition_get_size_by_name("mrdump") / dev->blkdev->blksz;

	if (method == 0) {
		if (mrdump_total_sect == (BYTE_SIZE_16MB / dev->blkdev->blksz)) {
                        voprintf_error("mrdump partition already resized to 16MB\n");
                        goto fail;
		}

		if (mrdump_total_sect != dram_total_sect + (BYTE_SIZE_16MB / dev->blkdev->blksz)) {
			voprintf_error("Unknown mrdump partition size (0x%llx)\n", mrdump_total_sect);
                        goto fail;
		}

		entries[data_index].ending_lba = entries[data_index].ending_lba + dram_total_sect;
		entries[mrdump_index].starting_lba = entries[mrdump_index].starting_lba + dram_total_sect;

	}
	else if (method == 1) {
		if ((data_total_sect - dram_total_sect) < (DATA_SIZE_MIN / dev->blkdev->blksz)) {
			voprintf_error("mrdump partition can't do resize (0x%llx < 0x%lx)\n",(data_total_sect - dram_total_sect), (DATA_SIZE_MIN / dev->blkdev->blksz));
			goto fail;
		}

		if (mrdump_total_sect >= dram_total_sect + (BYTE_SIZE_16MB / dev->blkdev->blksz)) {
			voprintf_error("mrdump partition already resized\n");
			goto fail;
		}
	        /* Update data.ending_lba and mrdump.starting_lba */
		entries[data_index].ending_lba = entries[data_index].ending_lba - dram_total_sect;
		entries[mrdump_index].starting_lba = entries[mrdump_index].starting_lba - dram_total_sect;

	}
	else {
		voprintf_error("unknown mrdump partition resize method (%d)\n", method);
		goto fail;
	}

	/* Update primary and secondary gpt */
	err = gpt_partition_table_update("gpt", data, sz);
	if (err) {
		voprintf_error("gpt_partition_table_update failed\n");
		goto fail;
	}

	/* re-init partition table afster update pmbor, pgpt and sgpt */
	read_gpt(partition);

	/* erase data partition */
	if (method == 1)
		partition_erase("userdata");

fail:
	/* Free data buffers after using it */
	free(data);

	return 0;
}

void mrdump_partition_resize(void)
{
	if (mrdump_get_part_index("mrdump") != -1) {
		pal_log_err("mrdump_partition_resize: start resize mrdump partition\n");
		if (mrdump_get_default_output_device() == MRDUMP_DEV_PARTITION)
			mrdump_gpt_resize(1);
		else
			mrdump_gpt_resize(0);
	}
	else
		pal_log_err("%s: mrdump doesn't exist\n", __func__);
}
