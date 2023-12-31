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
#include <string.h>
#include <lib/ramdisk_merge.h>
#include <lib/zlib.h>
#if _WIN32
#define PROFILING_START(a)
#define PROFILING_END()
#else
#include <platform/mt_gpt.h>
#include <profiling.h>
#endif // _WIN32
#include <memory_layout.h>
#include "ramdisk_merge_private.h"
#include "cpio_header.h"
#include <platform/boot_mode.h>
#include <mblock.h>

/* static function declaration */
static int validate_cpio_archive(const uint8_t *cpio_archive);
static int find_cpio_last_entry(const uint8_t *cpio_archive, const uint32_t cpio_archive_size, uint8_t **last_entry);
static void gzip_uncompressed_size(const uint8_t *gzip_stream, uint32_t gzip_size, uint32_t *uncompressed_size);
static int ramdisk_merge(ramdisk_buf_t *ramdisk1, ramdisk_buf_t *ramdisk2, ramdisk_buf_t *target_ramdisk);

#define RAMDISK_TEMP_BUF_MAX_SIZE	(100*1024*1024)
#define RAMDISK_TEMP_BUF_LIMIT		(0xc0000000)
/*
 * LK ramdisk merge deal with ramdisk create by mkbootfs.
 * cpio archive is newc format and always create TRAILER!!! as last entry.
 */

/*
    https://www.kernel.org/doc/Documentation/early-userspace/buffer-format.txt

	The full format of the initramfs buffer is defined by the following
    grammar, where:
	*	is used to indicate "0 or more occurrences of"
	(|)	indicates alternatives
	+	indicates concatenation
	GZIP()	indicates the gzip(1) of the operand
	ALGN(n)	means padding with null bytes to an n-byte boundary

	initramfs  := ("\0" | cpio_archive | cpio_gzip_archive)*

	cpio_gzip_archive := GZIP(cpio_archive)

	cpio_archive := cpio_file* + (<nothing> | cpio_trailer)

	cpio_file := ALGN(4) + cpio_header + filename + "\0" + ALGN(4) + data

	cpio_trailer := ALGN(4) + cpio_header + "TRAILER!!!\0" + ALGN(4)
*/
/* recovery_ramdisk_buf point to work buffer head */
int recovery_ramdisk_merge(ramdisk_buf_t *r_ramdisk, ramdisk_buf_t *v_ramdisk, ramdisk_buf_t *target_ramdisk,
							uint8_t *work_buf, uint8_t *work_buf_end)
{
	int     rc;
	uint8_t *work_buf_mblock;
	uint8_t *work_buf_end_mblock;
	uint64_t work_buf_size_mblock;

	gzip_uncompressed_size(r_ramdisk->comp_buf, r_ramdisk->comp_size, &r_ramdisk->decomp_max_size);
	r_ramdisk->decomp_max_size += UNCOMPRESS_GUARD_BUFFER;

	gzip_uncompressed_size(v_ramdisk->comp_buf, v_ramdisk->comp_size, &v_ramdisk->decomp_max_size);
	v_ramdisk->decomp_max_size += UNCOMPRESS_GUARD_BUFFER;
	work_buf_size_mblock = r_ramdisk->decomp_max_size + v_ramdisk->decomp_max_size;

	RM_DEBUG("real merged size:%llu\n", work_buf_size_mblock);
	if (work_buf_size_mblock > RAMDISK_TEMP_BUF_MAX_SIZE)
		RM_DEBUG("WARNING! work_buf_size_mblock size[%llu] is over %u!!\n", work_buf_size_mblock, RAMDISK_TEMP_BUF_MAX_SIZE);
	else
		work_buf_size_mblock = RAMDISK_TEMP_BUF_MAX_SIZE;

	if (work_buf_size_mblock > LK_RAMDISK_MAX_SIZE)
		panic("work_buf_size_mblock size[%llu] is not allowed over %u!!\n", work_buf_size_mblock, LK_RAMDISK_MAX_SIZE);

	/* Allocate temp buffer for ramdisk merge */
	work_buf_mblock = (uint8_t *)(uint32_t)mblock_reserve_ext(&g_boot_arg->mblock_info,
		work_buf_size_mblock, PAGE_SIZE, RAMDISK_TEMP_BUF_LIMIT,
		0, "ramdisk_merge_temp");
	if (work_buf_mblock == 0)
		panic("work_buf_mblock is not allocated successfully!!");

	work_buf_end_mblock = work_buf_mblock + work_buf_size_mblock;
	RM_DEBUG("work_buf_mblock:0x%x, work_buf_end_mblock:0x%x\n", (uint32_t)work_buf_mblock, (uint32_t)work_buf_end_mblock);

	/* cpio head needs 4 byte alignment */
	r_ramdisk->decomp_buf = (uint8_t *)ALIGN((size_t)work_buf_mblock, 4);
	v_ramdisk->decomp_buf = (uint8_t *)ALIGN((size_t)(r_ramdisk->decomp_buf + r_ramdisk->decomp_max_size), 4);
	if ((v_ramdisk->decomp_buf + v_ramdisk->decomp_max_size) >= work_buf_end_mblock) {
		DUMP_RAMDISK_STRUCT(r_ramdisk);
		DUMP_RAMDISK_STRUCT(v_ramdisk);
		assert(0);
	}
	rc = ramdisk_merge(r_ramdisk, v_ramdisk, target_ramdisk);
	/* Release temp buffer */
	mblock_create(&g_boot_arg->mblock_info,
			&g_boot_arg->orig_dram_info,
			(uint64_t)work_buf_mblock & 0xffffffff, (uint64_t)work_buf_size_mblock & 0xffffffff);
	return rc;
}

static void gzip_uncompressed_size(const uint8_t *gzip_stream, uint32_t gzip_size, uint32_t *uncompressed_size)
{
	uint8_t *gzip_ptr = (uint8_t *) gzip_stream;
	uint32_t size;
	/*
	 * The last 4 byte presents the uncompressed data size modulo 2^32.
	 * This value is not correct if uncompressed data size is larger than 4GB.
	 * However, ramdisk should be rather small so we take it as real uncompressed size.
	 */
	gzip_ptr = (gzip_ptr + gzip_size - GZIP_HEADER_UNCOMPRESSED_DATA_SIZE_OFFSET_TAIL);
	/*
     * gzip_ptr may be not 4 byte alignment. ARM needs to
     * access address natural alignment.
     */
	size = gzip_ptr[0] | gzip_ptr[1] << 8 | gzip_ptr[2] << 16 | gzip_ptr[3] << 24;

	/* In case there is a parsing error */
	if (size > LK_RAMDISK_MAX_SIZE) {
		RM_DEBUG("Uncompressed ramdisk size may be too large! %u\n", size);
		assert(0);
	}
	*uncompressed_size = size;
}

static int ramdisk_merge(ramdisk_buf_t *ramdisk1, ramdisk_buf_t *ramdisk2, ramdisk_buf_t *target_ramdisk)
{
	int rc;
	uint8_t *tail_without_last_entry;
	uint32_t total_cpio_merged_size;
	z_stream def_target;

	validate_ramdisk_buf(ramdisk1);
	/* Decompress ramdisk */
	RM_DEBUG("ramdisk1->comp_buf:0x%x, comp_size:%u\n", (uint32_t)ramdisk1->comp_buf, ramdisk1->comp_size);
	rc = gunzip(ramdisk1->comp_buf, (unsigned long *)&ramdisk1->comp_size,
				ramdisk1->decomp_buf, ramdisk1->decomp_max_size);
	assert(rc == 0);
	ramdisk1->decomp_size  = ramdisk1->comp_size;
	RM_DEBUG("ramdisk1 decompress size:%u\n", ramdisk1->decomp_size);

	/* Validate cpio format */
	rc = validate_cpio_archive(ramdisk1->decomp_buf);
	if (rc != 0) {
		RM_DEBUG("validate 1st ramdisk fail!\n");
		DUMP_RAMDISK_STRUCT(ramdisk1);
		assert(0);
	}

	/* Find ramdisk1 last cpio entry*/
	rc = find_cpio_last_entry(ramdisk1->decomp_buf, ramdisk1->decomp_size, &tail_without_last_entry);
	if (rc != 0) {
		RM_DEBUG("Fail to find cpio last entry! %d\n", rc);
		DUMP_RAMDISK_STRUCT(ramdisk1);
		assert(!rc);
	}
	ramdisk2->decomp_buf = tail_without_last_entry;
	RM_DEBUG("ramdisk2->comp_buf:0x%x, comp_size:%u\n", (uint32_t)ramdisk2->comp_buf, ramdisk2->comp_size);
	validate_ramdisk_buf(ramdisk2);
	/* Concatenate ramdisk2 to truncated ramdisk1's tail */
	rc = gunzip(ramdisk2->comp_buf, (unsigned long *)&ramdisk2->comp_size,
				ramdisk2->decomp_buf, ramdisk2->decomp_max_size);
	assert(rc == 0);
	ramdisk2->decomp_size  = ramdisk2->comp_size;
	RM_DEBUG("ramdisk2 decompress size:%u\n", ramdisk2->decomp_size);
	/* Validate cpio archive format after concat */
	rc = validate_cpio_archive(ramdisk2->decomp_buf);
	if (rc != 0) {
		RM_DEBUG("validate 2nd ramdisk fail!\n");
		DUMP_RAMDISK_STRUCT(ramdisk2);
		assert(0);
	}

	total_cpio_merged_size = (tail_without_last_entry - ramdisk1->decomp_buf) + ramdisk2->decomp_size;
	RM_DEBUG("total_cpio_merged_size:%u\n", total_cpio_merged_size);

	/* Compress merged cpio archive */
	def_target.zalloc = Z_NULL;
	def_target.zfree  = Z_NULL;
	def_target.opaque = Z_NULL;

	rc = deflateInit2 (&def_target, COMPRESSION_LEVEL, Z_DEFLATED,
							 WINDOWBITS | GZIP_ENCODING, 8,
							 Z_DEFAULT_STRATEGY);
	if (rc != 0) {
		RM_DEBUG("deflateInit2 init fail, %d\n", rc);
		DUMP_RAMDISK_STRUCT(target_ramdisk);
		assert(0);
	}

	def_target.avail_in = (uInt)total_cpio_merged_size; // size of input
	def_target.next_in = (Bytef *)ramdisk1->decomp_buf; // input char array
	def_target.avail_out = (uInt)target_ramdisk->comp_max_size; // size of output
	def_target.next_out = (Bytef *)target_ramdisk->comp_buf; // output char array
	PROFILING_START("ramdisk merge compression");
	rc = deflate(&def_target, Z_FINISH);
	PROFILING_END();
	if ((rc != Z_OK) && (rc != Z_STREAM_END)) {
		RM_DEBUG("Fail to compress merged ramdisk! result:%d\n", rc);
		DUMP_RAMDISK_STRUCT(target_ramdisk);
		assert(0);
	}

	rc = deflateEnd(&def_target);
	if (rc != Z_OK) {
		RM_DEBUG("Fail to complete merged ramdisk compression!\n");
		DUMP_RAMDISK_STRUCT(target_ramdisk);
		assert(0);
	}
	target_ramdisk->comp_size = def_target.total_out;
	RM_DEBUG("def_target.total_out:%lu\n", def_target.total_out);
	return 0;
}

/*
 *  Validate cpio format
 *  1. So far we only support new ASCII format.
 *  2. Verify cpio_archive address is four bytes alignment.
 */
static int validate_cpio_archive(const uint8_t *cpio_archive)
{
	const cpio_newc_header_t *first_entry = (const cpio_newc_header_t *) cpio_archive;
	uintptr_t   cpio_address = (uintptr_t) cpio_archive;

	if (memcmp(first_entry->c_magic, CPIO_NEW_C_MAGIC, CPIO_MAGIC_LEN) != 0)
		return -1;
	if (!IS_ALIGNED(cpio_address, CPIO_ALIGNMENT))
		return -2;
	return 0;
}

/* Find last entry from tail */
static int find_cpio_last_entry(const uint8_t *cpio_archive, const uint32_t cpio_archive_size, uint8_t **last_entry)
{
	const uint8_t *tail = (cpio_archive + (cpio_archive_size - 1));
	uint32_t    search_size = 0;

	/* Padding bytes is '\0' */
	while (*tail == 0x0) {
		tail--;
		search_size++;
	}
	if (search_size > SEARCH_FROM_TAIL_SIZE)
		return -1;
	/*
	 * Minus one is for NULL terminated string
	 * Minus another one to point to head.
	 */
	tail -= (CPIO_LAST_ENTRY_NAME_LEN - 2);
	/*
	 * The string before padding bytes should be the last entry.
	 * If not, this is invalid.
	 */
	if (memcmp(tail, (void *) CPIO_LAST_ENTRY_NAME, CPIO_LAST_ENTRY_NAME_LEN) != 0)
		return -2;

	/* cpio_file := ALGN(4) + cpio_header + filename + "\0" + ALGN(4) + data */
	tail -= sizeof(cpio_newc_header_t);
	*last_entry = (uint8_t *)tail;
	return 0;
}

void dump_ramdisk_buf(ramdisk_buf_t *ramdisk, const char *func, int line)
{
	RM_DEBUG("FUNC:%s, LINE:%d\n", func, line);
	RM_DEBUG("--------%s--------\n", __func__);
	RM_DEBUG("name:%s\n", ramdisk->name);
	RM_DEBUG("decomp_buf:0x%x\n", (uint32_t)ramdisk->decomp_buf);
	RM_DEBUG("decomp_size:%u\n", (uint32_t)ramdisk->decomp_size);
	RM_DEBUG("decomp_max_size:%u\n", (uint32_t)ramdisk->decomp_max_size);
	RM_DEBUG("comp_buf:0x%x\n", (uint32_t)ramdisk->comp_buf);
	RM_DEBUG("comp_size:%u\n", (uint32_t)ramdisk->comp_size);
	RM_DEBUG("comp_max_size:%u\n", (uint32_t)ramdisk->comp_max_size);
}
