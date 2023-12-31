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
#include <boot_info.h>
#include <load_ramdisk.h>
#include <load_vfy_boot.h>
#include <platform/memory_layout.h>
#ifdef _WIN32
#include <fcntl.h>
#else
#include <partition.h>
#include <part_status.h>
#include <part_interface.h>
#endif // _WIN32
#include <pal_assert.h>
#include <pal_typedefs.h>
#include <pal_log.h>
#include <string.h>
/*
 * Read ramdisk from partition
 * Image header is bootimg header
 */
static void partition_ramdisk_read(const char *part_name,
								uint8_t *ramdisk_buf,
								uint32_t *ramdisk_size,
								uint32_t read_max_size,
								uint32_t *ramdisk_page_align_size)
{
	struct bootimg_hdr *boot_hdr;
	ssize_t len;
	uint32_t ramdisk_start_offset;

	PAL_ASSERT(part_name);
	PAL_ASSERT(ramdisk_buf);
	PAL_ASSERT(ramdisk_size);

	boot_hdr = (struct bootimg_hdr *)malloc(sizeof(struct bootimg_hdr));
	memset(boot_hdr, 0x0, sizeof(struct bootimg_hdr));
#ifndef _WIN32
	if (partition_exists((char *)part_name) == PART_NOT_EXIST) {
		panic("%s partition does not exit!\n", part_name);
	}

	len = partition_read((char *)part_name, 0, (uchar *)boot_hdr,
			     sizeof(struct bootimg_hdr));
	if (len < 0) {
		panic("Fail to read %s partition!\n", part_name);
	}
#else
	int ramdisk_fd;

	ramdisk_fd = open(part_name, (O_RDONLY | _O_BINARY));
	if (read(ramdisk_fd, boot_hdr,
		 sizeof(struct bootimg_hdr)) != sizeof(struct bootimg_hdr)) {
		printf("cannot read %u bytes", sizeof(struct bootimg_hdr));
		goto ERROR;
	}
#endif
	ramdisk_start_offset = boot_hdr->page_sz +
			       ((boot_hdr->kernel_sz + boot_hdr->page_sz - 1) /
				boot_hdr->page_sz) *
			       boot_hdr->page_sz;
	*ramdisk_page_align_size = ((boot_hdr->ramdisk_sz + boot_hdr->page_sz - 1) /
			boot_hdr->page_sz) *
			boot_hdr->page_sz;

#ifndef _WIN32
	len = partition_read((char *)part_name, ramdisk_start_offset,
			     (uchar *) ramdisk_buf,
			     *ramdisk_page_align_size);
	if (len < 0) {
		panic("Fail to read %s partition!\n", part_name);
	}
#else
	lseek(ramdisk_fd, ramdisk_start_offset, SEEK_SET);
	len = read(ramdisk_fd, ramdisk_buf, boot_hdr->ramdisk_sz);
#endif
	*ramdisk_size = boot_hdr->ramdisk_sz;
	pal_log_err("boot_hdr->ramdisk_addr:0x%x, *ramdisk_page_align_size:%u\n",
		    (uint32_t)boot_hdr->ramdisk_addr, *ramdisk_page_align_size);
	free(boot_hdr);
#ifdef _WIN32
ERROR:
	close(ramdisk_fd);
#endif
}

/*
 * Read ramdisk from partition
 * Image header is bootimg header
 */
void vendor_ramdisk_read(ramdisk_buf_t *rd_vendor, uint32_t *ramdisk_page_align_size)
{
	partition_ramdisk_read(VENDOR_RAMDISK_PART_NAME,
			       rd_vendor->comp_buf,
			       &rd_vendor->comp_size,
			       rd_vendor->comp_max_size,
			       ramdisk_page_align_size);
}
void recovery_ramdisk_read(ramdisk_buf_t *rd_recovery, uint32_t *ramdisk_target_addr, uint32_t *ramdisk_page_align_size)
{
	partition_ramdisk_read(RECOVERY_RAMDISK_PART_NAME,
			       rd_recovery->comp_buf,
			       &rd_recovery->comp_size,
			       rd_recovery->comp_max_size,
			       ramdisk_page_align_size);
	/*
	  * Get ramdisk address from boot/recovery partition header
	  * instead of parsed from recovery-ramdisk partition.
	  */
	*ramdisk_target_addr = get_ramdisk_target_addr();
	if (*ramdisk_target_addr != LK_RAMDISK_BASE) {
		pal_log_err("[WARNING]bootimage ramdisk address:0x%x is not "
			"aligned to LK_RAMDISK_BASE:0x%x!!", *ramdisk_target_addr, LK_RAMDISK_BASE);
	}
}

