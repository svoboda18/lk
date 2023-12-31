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
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <errno.h>
#include <lib/ramdisk_merge.h>
#include <bootimg.h>
#if _WIN32
#include <fcntl.h>
#else
#include <partition.h>
#include <part_status.h>
#include <part_interface.h>
#endif // _WIN32

#ifdef _WIN32
#define TEST_IMAGE_PATH "D:\\work\\lk\\ramdisk_merge\\test_image"
#define VENDOR_RAMDISK_IMG_NAME   "bootimghdr_ramdisk_tora.img"
#define RECOVERY_RAMDISK_IMG_NAME   "bootimghdr_ramdisk_bootimg.img"
#define TARGET_MERGED_RAMDSIK_IMG_NAME   "merged_ramdisk.img"
#define VENDOR_RAMDISK_PART_NAME   TEST_IMAGE_PATH"\\"VENDOR_RAMDISK_IMG_NAME
#define RECOVERY_RAMDISK_PART_NAME	TEST_IMAGE_PATH"\\"RECOVERY_RAMDISK_IMG_NAME
#define TARGET_MERGED_RAMDSIK_FILE  TEST_IMAGE_PATH"\\"RECOVERY_RAMDISK_IMG_NAME
#else
#define VENDOR_RAMDISK_PART_NAME	"recovery_vendor"
#define RECOVERY_RAMDISK_PART_NAME	"recovery_ramdisk"
#endif

extern void vendor_ramdisk_read(ramdisk_buf_t *rd_vendor, uint32_t *ramdisk_page_align_size);
extern void recovery_ramdisk_read(ramdisk_buf_t *rd_recovery, uint32_t *ramdisk_target_addr, uint32_t *ramdisk_page_align_size);
