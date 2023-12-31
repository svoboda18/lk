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
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <lib/crc.h>
#include <lib/zutil.h>
#include <lib/zlib.h>
#include "aee.h"
#include "mrdump_private.h"

#ifdef MTK_3LEVEL_PAGETABLE
#include <stdlib.h>
#include <err.h>
#endif

#define KZIP_DEBUG(x...)

#define KDUMP_SIZE_REPORT 0x1000000
#define KDUMP_TICK_WDT 0x10000

#ifdef MRDUMP_ZIP_NO_COMPRESSION
#define KDUMP_ZLIB_LEVEL Z_NO_COMPRESSION
#else
#define KDUMP_ZLIB_LEVEL Z_BEST_SPEED
#endif

#define ZIPVERSION_NEEDED 45UL

static void putvalue(void* dest, uint64_t x, int nbByte)
{
	uint8_t *buf = (uint8_t *)dest;
	int n;
	for (n = 0; n < nbByte; n++) {
		buf[n] = (unsigned char)(x & 0xff);
		x >>= 8;
	}
#if 0
	if (x != 0) {
		/* data overflow - hack for ZIP64 */
		for (n = 0; n < nbByte; n++) {
			buf[n] = 0xff;
		}
	}
#endif
}

static int put_zip64_eoc_directory_record(uint8_t *buf, int record_num, uint64_t zip_centralheader_offset, int zip_centralheader_size)
{
	uint8_t *oldbuf = buf;
	putvalue(buf, ZIP64ENDOFCENTRALDIRMAGIC, 4);
	buf += 4;
	putvalue(buf, 44, 8); /* zip64 eoc size */
	buf += 8;
	putvalue(buf, ZIPVERSION_NEEDED, 2); /* version made by */
	buf += 2;
	putvalue(buf, ZIPVERSION_NEEDED, 2); /* version needed to extract */
	buf += 2;
	putvalue(buf, 0, 4); /* number of this disk */
	buf += 4;
	putvalue(buf, 0, 4); /* number of the disk with the start of the central directory */
	buf += 4;
	putvalue(buf, record_num, 8); /* total number of entries in the central directory on this disk */
	buf += 8;
	putvalue(buf, record_num, 8); /* total number of entries in the central directory */
	buf += 8;
	putvalue(buf, zip_centralheader_size, 8); /* size of the central directory */
	buf += 8;
	putvalue(buf, zip_centralheader_offset, 8); /* offset of start of central directory with respect to the starting disk number */
	buf += 8;
	return buf - oldbuf;
}

static int put_zip64_eoc_directory_locator(uint8_t *buf, uint64_t zip64_eoc_offset)
{
	uint8_t *oldbuf = buf;
	putvalue(buf, ZIP64ENDOFCENTRALDIRLOCATORMAGIC, 4);
	buf += 4;
	putvalue(buf, 0, 4); /* number of the disk with the start of the zip64 end of central directory */
	buf += 4;
	putvalue(buf, zip64_eoc_offset, 8); /* relative offset of the zip64 end of central directory record */
	buf += 8;
	putvalue(buf, 1, 4); /* total number of disks */
	buf += 4;
	return buf - oldbuf;
}

static int put_eoc_directory_record(uint8_t *buf, int record_num, uint64_t zip_centralheader_offset, int zip_centralheader_size)
{
	uint8_t *oldbuf = buf;
	putvalue(buf, ENDOFCENTRALDIRMAGIC, 4);
	buf += 4;
	putvalue(buf, 0, 2); /* Number of this disk */
	buf += 2;
	putvalue(buf, 0, 2); /* Disk where central directory starts */
	buf += 2;
	putvalue(buf, record_num, 2); /* Number of central directory records on this disk */
	buf += 2;
	putvalue(buf, record_num, 2); /* Total number of central directory records */
	buf += 2;
	putvalue(buf, zip_centralheader_size, 4);
	buf += 4;
	putvalue(buf, 0xffffffff, 4);
	buf += 4;
	putvalue(buf, 0, 2); /* Comment length (n) */
	buf += 2;
	return buf - oldbuf;
}

static int put_localheader(uint8_t *buf, const char *filename, int level)
{
	uint8_t *oldbuf = buf;
	putvalue(buf, LOCALHEADERMAGIC, 4);
	buf += 4;
	putvalue(buf, ZIPVERSION_NEEDED, 2);
	buf += 2;

	uint16_t flag = 0;
	if ((level==8) || (level == 9))
		flag |= 2;
	if ((level == 2))
		flag |= 4;
	if ((level == 1))
		flag |= 6;
#if 0
	if (password != NULL)
		flag |= 1;
#endif

	putvalue(buf, flag | 0x8, 2);
	buf += 2;

	putvalue(buf, Z_DEFLATED, 2);
	buf += 2;

	putvalue(buf,0UL, 4);
	buf += 4;

	// CRC / Compressed size / Uncompressed size will be filled in later and rewritten later
	putvalue(buf, 0UL, 4); /* crc 32, unknown */
	buf += 4;
	putvalue(buf, 0xFFFFFFFFUL, 4); /* compressed size, unknown */
	buf += 4;
	putvalue(buf, 0xFFFFFFFFUL, 4); /* uncompressed size, unknown */
	buf += 4;
	putvalue(buf, strlen(filename), 2); /* size of filename */
	buf += 2;
	putvalue(buf, 4 + 8 + 8, 2); /* size of extra field */
	buf += 2;

	memcpy(buf, filename, strlen(filename));
	buf += strlen(filename);

	/* ZIP64 extension */
	putvalue(buf, 0x0001, 2); /* ZIP64_EXTENSION */
	buf += 2;
	putvalue(buf, 8 + 8, 2);
	buf += 2;
	putvalue(buf, 0UL, 8);
	buf += 8;
	putvalue(buf, 0UL, 8);
	buf += 8;

	return buf - oldbuf;
}

static int put_centralheader(uint8_t *buf, const char *filename, int level, uint64_t zip_localheader_offset, uint64_t size, uint64_t uncomp_size, uint32_t crc32_value)
{
	uint8_t *oldbuf = buf;

	putvalue(buf, CENTRALHEADERMAGIC, 4);
	buf += 4;
	putvalue(buf, ZIPVERSION_NEEDED, 2);
	buf += 2;
	putvalue(buf, ZIPVERSION_NEEDED, 2);
	buf += 2;

	uint16_t flag = 0;
	if ((level==8) || (level == 9))
		flag |= 2;
	if ((level == 2))
		flag |= 4;
	if ((level == 1))
		flag |= 6;
#if 0
	if (password != NULL)
		flag |= 1;
#endif

	putvalue(buf, flag | 0x8, 2);
	buf += 2;

	putvalue(buf, Z_DEFLATED, 2);
	buf += 2;

	putvalue(buf,0UL, 4);
	buf += 4;

	// CRC / Compressed size / Uncompressed size will be filled in later and rewritten later
	putvalue(buf, crc32_value, 4); /* crc 32 */
	buf += 4;
	putvalue(buf, 0xffffffffUL, 4); /* compressed size */
	buf += 4;
	putvalue(buf, 0xffffffffUL, 4); /* uncompressed size */
	buf += 4;
	putvalue(buf, strlen(filename), 2);
	buf += 2;
	putvalue(buf, 4 + 8 + 8 + 8, 2); /* size of extra field */
	buf += 2;
	putvalue(buf, 0UL, 2); /* size of comment field */
	buf += 2;
	putvalue(buf, 0UL, 2); /* disk number */
	buf += 2;
	putvalue(buf, 0UL, 2); /* internal attributes */
	buf += 2;
	putvalue(buf, 0UL, 4); /* external file attributes */
	buf += 4;
	putvalue(buf, 0xffffffffUL, 4); /* Relative offset */
	buf += 4;
	memcpy(buf, filename, strlen(filename));
	buf += strlen(filename);

	/* ZIP64 extension */
	putvalue(buf, 0x0001, 2); /* ZIP64_EXTENSION */
	buf += 2;
	putvalue(buf, 8 + 8 + 8, 2);
	buf += 2;
	putvalue(buf, uncomp_size, 8);
	buf += 8;
	putvalue(buf, size, 8);
	buf += 8;
	putvalue(buf, zip_localheader_offset, 8);
	buf += 8;

	return buf - oldbuf;
}

static int kzip_write_current(struct kzip_file *zfile, void *buf, int len)
{
	KZIP_DEBUG("%s: write_cb %p len %d\n", __func__, zfile->write_cb, len);
	int retval = zfile->write_cb(zfile->handle, buf, len);
	if (retval > 0) {
		zfile->current_size += retval;
	}
	if ((zfile->current_size - zfile->reported_size) >= KDUMP_SIZE_REPORT) {
		vo_show_progress(zfile->current_size / 0x100000);
		zfile->reported_size = zfile->current_size;
	}
	if ((zfile->current_size - zfile->wdk_kick_size) >= KDUMP_TICK_WDT) {
		mtk_wdt_restart();
		zfile->wdk_kick_size = zfile->current_size;
	}
	return retval;
}

struct kzip_file *kzip_open(void *handle, int (*write_cb)(void *handle, void *p, int size))
{
	struct kzip_file *zf = malloc(sizeof(struct kzip_file));
	if (zf == NULL) {
		KZIP_DEBUG("%s: No enough memory\n", __func__);
		return NULL;
	}
	memset(zf, 0, sizeof(struct kzip_file));
	zf->handle = handle;
	zf->write_cb = write_cb;
	KZIP_DEBUG("%s: handle zf %p %p write_cb %p\n", __func__, zf, zf->handle, zf->write_cb);

	vo_show_progress(0);
	return zf;
}

bool kzip_close(struct kzip_file *zf)
{
	uint64_t central_header_offset = zf->current_size, zip64_eoc_offset;
	struct kzip_entry *zentries = zf->zentries;
	int num = zf->entries_num;

	int i, hsize = 0, local_hsize;
	uint8_t databuf[128];
	for (i = 0; i < num; i++) {
		local_hsize = put_centralheader(databuf, zentries[i].filename, zentries[i].level,
		                                    zentries[i].localheader_offset,
		                                    zentries[i].comp_size,
		                                    zentries[i].uncomp_size,
		                                    zentries[i].crc32);
		if (kzip_write_current(zf, databuf, local_hsize) != local_hsize) {
			goto error;
		}
		hsize += local_hsize;
	}
	voprintf_debug("%s: current_size %lld hoffset %lld\n", __func__, zf->current_size, central_header_offset);

	zip64_eoc_offset = zf->current_size;
	local_hsize = put_zip64_eoc_directory_record(databuf, num, central_header_offset, hsize);
	if ((local_hsize > 0) && (kzip_write_current(zf, databuf, local_hsize) != local_hsize)) {
		goto error;
	}

	local_hsize = put_zip64_eoc_directory_locator(databuf, zip64_eoc_offset);
	if ((local_hsize > 0) && (kzip_write_current(zf, databuf, local_hsize) != local_hsize)) {
		goto error;
	}

	local_hsize = put_eoc_directory_record(databuf, num, central_header_offset, hsize);
	if (kzip_write_current(zf, databuf, local_hsize) != local_hsize) {
		goto error;
	}
	free(zf);
	return true;
error:
	free(zf);
	return false;
}

#define CHUNK 65536

/* Compress from file source to file dest until EOF on source.
   def() returns Z_OK on success, Z_MEM_ERROR if memory could not be
   allocated for processing, Z_STREAM_ERROR if an invalid compression
   level is supplied, Z_VERSION_ERROR if the version of zlib.h and the
   version of the library linked do not match, or Z_ERRNO if there is
   an error reading or writing the files. */

static bool kzip_add_file_no_mapped(struct kzip_file *zfile, const struct kzip_addlist *memlist,
                                    int *flush, int *ret, uint8_t *in, uint8_t *out,
                                    struct kzip_entry *zentry, z_stream *strm, struct aee_timer *zip_time)
{
	uint64_t mem_size = memlist->size;
	uint8_t *memsrc = (uint8_t *)(uintptr_t)memlist->address;
	*flush = (memlist->size == 0) ? Z_FINISH : Z_NO_FLUSH;
	voprintf_debug("-- Compress memory %llx, size %llu\n",
	               memlist->address, memlist->size);

	do {
		int in_size = mem_size > CHUNK ? CHUNK : mem_size;
		memcpy(in, memsrc, in_size);
		zentry->crc32 = crc32_no_comp(zentry->crc32, in, in_size);
		memsrc += in_size;
		mem_size -= in_size;
		strm->avail_in = in_size;
		strm->next_in = in;

		/* run deflate() on input until output buffer not full, finish
		   compression if all of source has been read in */
		do {
			strm->avail_out = CHUNK;
			strm->next_out = out;
			*ret = deflate(strm, *flush);    /* no bad return value */
			assert(*ret != Z_STREAM_ERROR);  /* state not clobbered */
			int have = CHUNK - strm->avail_out;
			if (have > 0) {
				aee_timer_stop(zip_time);
				if (kzip_write_current(zfile, out, have) != have) {
					voprintf_debug("-- Compress memory %llx, error. surplus size: %u\n",
					               memlist->address, mem_size);
					return false;
				}
				aee_timer_start(zip_time);
			}
		} while (strm->avail_out == 0);
		assert(strm->avail_in == 0);     /* all input will be used */

	} while (mem_size > 0);

	voprintf_debug("-- Compress memory %llx, done. surplus size: %u\n",
	               memlist->address, mem_size);
	return true;
}

#ifndef MTK_3LEVEL_PAGETABLE
/* full mapping at LK, only one function is needed. kzip_add_file_no_mapped() */
#define kzip_add_file_do_mapped kzip_add_file_no_mapped
#else
/* LPAE, map before accessing the address of memory */
#define MAX_MAP_CNT (SECTION_SIZE/CHUNK)
#define mapflags (MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA)
static bool kzip_add_file_do_mapped(struct kzip_file *zfile, const struct kzip_addlist *memlist,
                                    int *flush, int *ret, uint8_t *in, uint8_t *out,
                                    struct kzip_entry *zentry, z_stream *strm, struct aee_timer *zip_time)
{
	/* multiple physical address mapped onto static 2MB address space. (scratch_addr) */
	int cnt = 0;
	uint64_t paddr = memlist->address;
	vaddr_t vaddr = ROUNDUP(scratch_addr(), SECTION_SIZE);
	voprintf_debug("-- map: paddr=0x%016llx, vaddr=0x%08x\n", paddr, vaddr);

	uint64_t mem_size = memlist->size;
	uint8_t *memsrc;
	*flush = (memlist->size == 0) ? Z_FINISH : Z_NO_FLUSH;
	voprintf_debug("-- Compress memory %llx, size %llu\n", memlist->address, memlist->size);

	do {
		/* arch_mmu_map by each 2MB size */
		if (cnt == 0) {
			int map_ok = arch_mmu_map(paddr, vaddr, mapflags, SECTION_SIZE);
			if (map_ok != NO_ERROR) {
				voprintf_debug("-- arch_mmu_map map error: map_ok=%d, paddr=0x%016llx, vaddr=0x%08x\n",
				               map_ok, paddr, vaddr);
				return false;
			}
			memsrc = (uint8_t *)vaddr;
		}

		int in_size = mem_size > CHUNK ? CHUNK : mem_size;
		memcpy(in, memsrc, in_size);
		zentry->crc32 = crc32_no_comp(zentry->crc32, in, in_size);
		memsrc += in_size;
		mem_size -= in_size;
		strm->avail_in = in_size;
		strm->next_in = in;

		/* run deflate() on input until output buffer not full, finish
		   compression if all of source has been read in */
		do {
			strm->avail_out = CHUNK;
			strm->next_out = out;
			*ret = deflate(strm, *flush);    /* no bad return value */
			assert(*ret != Z_STREAM_ERROR);  /* state not clobbered */
			int have = CHUNK - strm->avail_out;
			if (have > 0) {
				aee_timer_stop(zip_time);
				if (kzip_write_current(zfile, out, have) != have) {
					voprintf_debug("-- Compress memory %llx, error. surplus size: %u\n",
					               memlist->address, mem_size);
					return false;
				}
				aee_timer_start(zip_time);
			}
		} while (strm->avail_out == 0);
		assert(strm->avail_in == 0);     /* all input will be used */

		/* mod by 2MB (SECTION_SIZE) */
		cnt++;
		cnt %= MAX_MAP_CNT;
		if (cnt == 0)
			paddr += SECTION_SIZE;

	} while (mem_size > 0);

	voprintf_debug("-- Compress memory %llx, done. surplus size: %u\n", memlist->address, mem_size);
	return true;
}
#endif

static bool kzip_add_file_from_expdb(struct kzip_file *zfile, const struct kzip_addlist *addlist,
                                    int *flush, int *ret, uint8_t *in, uint8_t *out,
                                    struct kzip_entry *zentry, z_stream *strm, struct aee_timer *zip_time)
{
	uint64_t offset_src = addlist->address;
	int64_t mem_size = addlist->size;

	*flush = (addlist->size == 0) ? Z_FINISH : Z_NO_FLUSH;
	voprintf_debug("-- Compress expdb offset %llx, size %llu\n", offset_src, mem_size);

	do {
		/* read from expdb to memsrc */
		if (mem_size > CHUNK) {
			mrdump_read_expdb(in, CHUNK, offset_src);
		} else {
			mrdump_read_expdb(in, (int)mem_size, offset_src);
		}

		int in_size = mem_size > CHUNK ? CHUNK : mem_size;
		zentry->crc32 = crc32_no_comp(zentry->crc32, in, in_size);
		mem_size -= in_size;
		strm->avail_in = in_size;
		strm->next_in = in;

		/* run deflate() on input until output buffer not full, finish
		   compression if all of source has been read in */
		do {
			strm->avail_out = CHUNK;
			strm->next_out = out;
			*ret = deflate(strm, *flush);    /* no bad return value */
			assert(*ret != Z_STREAM_ERROR);  /* state not clobbered */
			int have = CHUNK - strm->avail_out;
			if (have > 0) {
				aee_timer_stop(zip_time);
				if (kzip_write_current(zfile, out, have) != have) {
					voprintf_debug("-- Compress expdb offset %llx, error. surplus size: %u\n",
					               offset_src, mem_size);
					return false;
				}
				aee_timer_start(zip_time);
			}
		} while (strm->avail_out == 0);
		assert(strm->avail_in == 0);     /* all input will be used */

		offset_src += in_size;

	} while (mem_size > 0);

	voprintf_debug("-- Compress expdb offset %llx, done. surplus size: %u\n", offset_src, mem_size);
	return true;
}

bool kzip_add_file(struct kzip_file *zfile, const struct kzip_addlist *addlist, const char *zfilename)
{
	int ret, flush;
	z_stream strm;
	struct aee_timer zip_time;

	if (zfile->entries_num >= KZIP_ENTRY_MAX) {
		voprintf_error("Too many zip entry %d\n", zfile->entries_num);
		return false;
	}

	voprintf_debug("%s: zf %p(%p) %s\n", __func__, zfile, zfile->write_cb, zfilename);
	struct kzip_entry *zentry = &zfile->zentries[zfile->entries_num++];
	zentry->filename = strdup(zfilename);
	zentry->localheader_offset = zfile->current_size;
	zentry->level = KDUMP_ZLIB_LEVEL;
	zentry->crc32 = 0xffffffffUL;

	KZIP_DEBUG("%s: write local header\n", __func__);
	uint8_t zip_localheader[128];
	int hsize = put_localheader(zip_localheader, zfilename, zentry->level);
	if (kzip_write_current(zfile, zip_localheader, hsize) != hsize) {
		return false;
	}

	KZIP_DEBUG("%s: init compressor\n", __func__);
	/* allocate deflate state */
	memset(&strm, 0, sizeof(z_stream));
	ret = deflateInit2(&strm, zentry->level, Z_DEFLATED, -MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY);
	if (ret != Z_OK) {
		voprintf_error("zlib compress init failed\n");
		return false;
	}

	uint64_t start = zfile->current_size, uncomp_size = 0;

	uint8_t *out = malloc(CHUNK);
	uint8_t *in = malloc(CHUNK);
	if ((out == NULL) || (in == NULL)) {
		voprintf_error("%s: malloc failed in %p out %p.\n", __func__, in, out);
		goto error;
	}

	aee_timer_init(&zip_time);
	aee_timer_start(&zip_time);
	do {
		switch (addlist->type) {
			case MEM_NO_MAP:
				if (kzip_add_file_no_mapped(zfile, addlist, &flush, &ret, in, out, zentry, &strm, &zip_time) == false)
					goto error;
				break;
			case MEM_DO_MAP:
				if (kzip_add_file_do_mapped(zfile, addlist, &flush, &ret, in, out, zentry, &strm, &zip_time) == false)
					goto error;
				break;
			case EXPDB_FILE:
				if (kzip_add_file_from_expdb(zfile, addlist, &flush, &ret, in, out, zentry, &strm, &zip_time) == false)
					goto error;
				break;
			default:
				goto error;
				break;
		}
		uncomp_size += addlist->size;
		addlist++;
		/* done when last data in file processed */
	} while (flush != Z_FINISH);
	assert(ret == Z_STREAM_END);        /* stream will be complete */
	aee_timer_stop(&zip_time);
	voprintf_info("Zip time: %d sec\n", zip_time.acc_ms / 1000);

	zentry->comp_size = zfile->current_size - start;
	zentry->uncomp_size = uncomp_size;
	zentry->crc32 = zentry->crc32 ^ 0xffffffffUL;

	deflateEnd(&strm);
	free(out);
	free(in);
	return true;

error:
	free(out);
	free(in);
	deflateEnd(&strm);
	return false;
}
