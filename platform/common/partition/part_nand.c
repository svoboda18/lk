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
#include <platform/mt_typedefs.h>
#ifdef MTK_GPT_SCHEME_SUPPORT
#include <platform/partition.h>
#else
#include <mt_partition.h>
#endif
#include <platform/errno.h>
#include <debug.h>
#include <part_interface.h>
#include <part_status.h>
#include <block_generic_interface.h>

#include <pal_log.h>
#include <pal_typedefs.h>
#include <pal_assert.h>
#include <storage_api.h>
#include <error.h>
#include <partition_error.h>

/* dummy parameter is for prameter alignment */
ssize_t partition_read(const char *part_name, off_t offset, u8* data, size_t size)
{
	ssize_t len;
	uint64_t part_addr, part_size, read_addr;
	int32_t index;

#ifdef MNTL_SUPPORT
	if (is_mntl_partition(part_name)) {
		dprintf(CRITICAL, "%s: mntl partition %s not support read\n",
						__FUNCTION__, part_name);
		return -1;
	}
#endif

	index = partition_get_index(part_name);
	if (index == -1) {
		set_last_error(ERR_PART_GENERAL_NOT_EXIST);
		len = -1;
		return len;
	}

	/* does not check part_offset here since *
	 * if it's wrong, assertion fails.       *
	 */
	part_addr = partition_get_offset(index);
	part_size = partition_get_size(index);

	if ((uint64_t) (offset + size) > part_size) {
		pal_log_err("[%s]%s: Incorrect range:\n",
				PART_COMMON_TAG,
				__FUNCTION__);
		pal_log_err("    part: %s\n", part_name);
		pal_log_err("    total: %lld\n", part_size);
		pal_log_err("    start: %lld\n", offset);
		pal_log_err("    size: %zu\n", size);
		set_last_error(ERR_PART_GENERAL_INVALID_RANGE);
		len = -1;
		return len;
	}

	read_addr = part_addr + (uint64_t)offset;

	len = storage_read(0,
				read_addr,
				(uint8_t *)data,
				(uint32_t)size);
	if (len != (ssize_t)size) {
		pal_log_err("[%s]%s: read '%s' fail\n",
				PART_COMMON_TAG,
				__FUNCTION__,
				part_name);
		pal_log_err("    expect: %zu, real: %ld\n", size, len);
		len = -1;
		return len;
	}

	return len;
}

/* dummy parameter is for prameter alignment */
ssize_t partition_write(const char *part_name, off_t offset, u8* data, size_t size)
{
	ssize_t len;
	uint64_t part_addr, part_size, write_addr;
	int32_t index;

#ifdef MNTL_SUPPORT
	if (is_mntl_partition(part_name)) {
		dprintf(CRITICAL, "%s: mntl partition %s not support write\n",
						__FUNCTION__, part_name);
		return -1;
	}
#endif

	index = partition_get_index(part_name);
	if (index == -1) {
		set_last_error(ERR_PART_GENERAL_NOT_EXIST);
		len = -1;
		return len;
	}

	/* does not check part_offset here since if it's wrong, assertion fails */
	part_addr = partition_get_offset(index);
	part_size = partition_get_size(index);
	write_addr = part_addr + (uint64_t)offset;

	if ((uint64_t)(offset + size) > part_size) {
		pal_log_err("[%s]%s: Incorrect range:\n",
				PART_COMMON_TAG,
				__FUNCTION__);
		pal_log_err("    part: %s\n", part_name);
		pal_log_err("    total: %lld\n", part_size);
		pal_log_err("    start: %lld\n", offset);
		pal_log_err("    size: %zu\n", size);
		set_last_error(ERR_PART_GENERAL_INVALID_RANGE);
		len = -1;
		return len;
	}

	if (partition_erase(part_name))
		return PART_ERASE_FAIL;

	len = storage_write(0,
				write_addr,
				(uint8_t *)data,
				(uint32_t)size);
	if (len != (int)size) {
		pal_log_err("[%s]%s: write '%s' fail\n",
				PART_COMMON_TAG,
				__FUNCTION__,
				part_name);
		pal_log_err("    expect: %zu, real: %ld\n", size, len);
		len = -1;
		return len;
	}

	return len;
}

int32_t partition_erase(const char *part_name)
{
	int32_t index;
	uint64_t erase_addr;
	uint64_t size;

#ifdef MNTL_SUPPORT
	if (is_mntl_partition(part_name)) {
		dprintf(CRITICAL, "%s: mntl partition %s erased\n",
						__FUNCTION__, part_name);
		return mntl_partition_erase(part_name);
	}
#endif

	index = partition_get_index(part_name);
	if (index == -1) {
		set_last_error(ERR_PART_GENERAL_NOT_EXIST);
		return -1;
	}

	erase_addr = partition_get_offset(index);
	size = partition_get_size(index);

	return storage_erase(0, erase_addr, size, 0);
}

