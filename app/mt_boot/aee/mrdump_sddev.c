/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
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

#include <malloc.h>
#include <stddef.h>
#include <stdint.h>
#include <block_generic_interface.h>
#include <part_interface.h>
#include <part_status.h>

#include "aee.h"
#include "mrdump_private.h"

static uint64_t part_device_get_size(struct mrdump_dev *dev)
{
	if (dev == NULL) {
		voprintf_error("%s dev is NULL!\n", __func__);
		return 0;
	} else {
		return partition_get_size_by_name(dev->handle);
	}
}

static bool part_device_read(struct mrdump_dev *dev, uint64_t offset, uint8_t *buf, int32_t len)
{
	if (dev == NULL) {
		voprintf_error("%s dev is NULL!\n", __func__);
		return false;
	} else {
		return partition_read(dev->handle, offset, buf, len) == len;
	}
}

static bool part_device_write(struct mrdump_dev *dev, uint64_t offset, uint8_t *buf, int32_t len)
{
	if (dev == NULL) {
		voprintf_error("%s dev is NULL!\n", __func__);
		return false;
	} else {
		return partition_write(dev->handle, offset, buf, len) == len;
	}
}

struct mrdump_dev *mrdump_dev_blkpart(const char *partname)
{
	if (partition_exists(partname) != PART_OK) {
		voprintf_error("Can't find partition %s\n", partname);
		return NULL;
	}
        struct mrdump_dev *dev = malloc(sizeof(struct mrdump_dev));
        if (!dev) {
                voprintf_error("%s: malloc() failed!\n", __func__);
                return NULL;
        }
	voprintf_info("%s size: %llu Mb\n", partname, partition_get_size_by_name(partname) / 0x100000UL);

        dev->name = "blkpart";
        dev->handle = strdup(partname);
        dev->read = part_device_read;
        dev->write = part_device_write;
	dev->get_size = part_device_get_size;
        return dev;
}
