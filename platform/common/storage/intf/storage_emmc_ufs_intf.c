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

/* pal api */
#include <pal_typedefs.h>
#include <pal_assert.h>
#include <pal_log.h>

#include <part_interface.h>
#include <part_status.h>
#include <block_generic_interface.h>
#if defined(MTK_UFS_SUPPORT)
#include <ufs_aio_core.h>
#endif
#include <storage_api.h>
#include <error.h>
#include <storage_error.h>

#define MOD "storage"

ssize_t storage_read(uint32_t phys_part,
			uint64_t offset,
			uint8_t *buf,
			uint32_t size)
{
	part_dev_t *dev = NULL;
	ssize_t len;

	dev = mt_part_get_device();
	if (!dev) {
		pal_log_err("[%s]%s: get part_dev fail\n",
				PART_COMMON_TAG,
				__FUNCTION__);
		set_last_error(ERR_STORAGE_GENERAL_GET_BLOCKDEV_FAIL);
		len = -1;
		return len;
	}

	len = dev->read(dev,
			offset,
			buf,
			size,
			phys_part);

	if ((uint32_t)len != size)
		set_last_error(ERR_STORAGE_GENERAL_READ_FAIL);

	return len;
}

ssize_t storage_write(uint32_t phys_part,
			uint64_t offset,
			uint8_t *buf,
			uint32_t size)
{
	part_dev_t *dev = NULL;
	ssize_t len;

	dev = mt_part_get_device();
	if (!dev) {
		pal_log_err("[%s]%s: get part_dev fail\n",
				PART_COMMON_TAG,
				__FUNCTION__);
		set_last_error(ERR_STORAGE_GENERAL_GET_BLOCKDEV_FAIL);
		len = -1;
		return len;
	}

	len = dev->write(dev,
				buf,
				offset,
				size,
				phys_part);

	if ((uint32_t)len != size)
		set_last_error(ERR_STORAGE_GENERAL_WRITE_FAIL);

	return len;
}

int32_t storage_erase(int32_t dev_num,
			uint64_t offset,
			uint32_t size,
			uint32_t phys_part)
{
	part_dev_t *dev;
	int32_t ret = 0;

	PAL_UNUSED_PARAM(dev_num);
	dev = mt_part_get_device();
	if (!dev) {
		pal_log_err("[%s]%s: get part_dev fail\n",
				PART_COMMON_TAG,
				__FUNCTION__);
		set_last_error(ERR_STORAGE_GENERAL_GET_BLOCKDEV_FAIL);
		ret = ERR_STORAGE_GENERAL_GET_BLOCKDEV_FAIL;
		return ret;
	}

	ret = dev->erase(0, offset, (uint64_t)size, phys_part);
	if (ret)
		set_last_error(ERR_STORAGE_GENERAL_ERASE_FAIL);

	return ret;
}

int32_t storage_get_blksz(void)
{
	part_dev_t *dev;
	int32_t ret = 0;

	dev = mt_part_get_device();
	if (!dev) {
		pal_log_err("[%s]%s: get part_dev fail\n",
				PART_COMMON_TAG,
				__FUNCTION__);
		set_last_error(ERR_STORAGE_GENERAL_GET_BLOCKDEV_FAIL);
		ret = ERR_STORAGE_GENERAL_GET_BLOCKDEV_FAIL;
		return ret;
	}
	if (!dev->blkdev) {
		pal_log_err("[%s]%s: dev->blkdev is NULL\n",
				PART_COMMON_TAG,
				__FUNCTION__);
		set_last_error(ERR_STORAGE_GENERAL_GET_BLOCKDEV_FAIL);
		ret = ERR_STORAGE_GENERAL_GET_BLOCKDEV_FAIL;
		return ret;
	}

	return dev->blkdev->blksz;
}

