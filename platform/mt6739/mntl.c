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


#include <platform/boot_mode.h>
#include <platform/mntl.h>
#include <platform/mntl_types.h>
#include <platform/mntl_gpt.h>
#include <stdlib.h>
#include <debug.h>

#include "sparse_format.h"

extern struct mntl_handler *mntl;

int mntl_erase(const char *arg, void *data, unsigned sz)
{
	uint64_t StartLBA = 0, EndLBA = 0;

	mntl_read_gpt(arg, &StartLBA, &EndLBA);
	mntl_discard(mntl, StartLBA, EndLBA - StartLBA + 1);

	dprintf(CRITICAL, "%s: mntl partition %s, sz %u\n",
						__FUNCTION__, arg, sz);

	return 0;
}

BOOL mntl_flash_img(const char *arg, void *data, unsigned sz)
{
	unsigned int chunk;
	unsigned int crc_value;
	uint32_t *fill_buf = NULL;
	uint32_t fill_val;
	unsigned long long chunk_data_sz;
	uint64_t chunk_sector_sz;
	sparse_header_t *sparse_header;
	chunk_header_t *chunk_header;
	uint32_t total_blocks = 0;
	uint64_t StartLBA = 0, EndLBA = 0;
	struct mntl_scatter_list list[2];
	int ret;
	int i;

	mntl_read_gpt(arg, &StartLBA, &EndLBA);

	/* Read and skip over sparse image header */
	sparse_header = (sparse_header_t *) data;
	dprintf (ALWAYS, "=== Sparse Image Header ===\n");
	dprintf (ALWAYS, "magic: 0x%x\n", sparse_header->magic);
	dprintf (ALWAYS, "major_version: 0x%x\n", sparse_header->major_version);
	dprintf (ALWAYS, "minor_version: 0x%x\n", sparse_header->minor_version);
	dprintf (ALWAYS, "file_hdr_sz: %d\n", sparse_header->file_hdr_sz);
	dprintf (ALWAYS, "chunk_hdr_sz: %d\n", sparse_header->chunk_hdr_sz);
	dprintf (ALWAYS, "blk_sz: %d\n", sparse_header->blk_sz);
	dprintf (ALWAYS, "total_blks: %d\n", sparse_header->total_blks);
	dprintf (ALWAYS, "total_chunks: %d\n", sparse_header->total_chunks);
	dprintf(ALWAYS, "Image size span 0x%llx, partition size 0x%llx\n", (unsigned long long)sparse_header->total_blks*sparse_header->blk_sz, (EndLBA - StartLBA + 1) * 4096);
	if ((unsigned long long)sparse_header->total_blks*sparse_header->blk_sz > (EndLBA - StartLBA + 1) * 4096) {
		dprintf(CRITICAL, "sparse image size span overflow.");
		return FALSE;
	}

	data += sparse_header->file_hdr_sz;
	if (sparse_header->file_hdr_sz > sizeof(sparse_header_t)) {
		/* Skip the remaining bytes in a header that is longer than
		* we expected.
		*/
		data += (sparse_header->file_hdr_sz - sizeof(sparse_header_t));
	}

	dprintf(CRITICAL, "\nWriting Flash ... ");
	/* Start processing chunks */
	for (chunk=0; chunk<sparse_header->total_chunks; chunk++) {
		/* Read and skip over chunk header */
		chunk_header = (chunk_header_t *) data;
		data += sizeof(chunk_header_t);

		/*
		dprintf (ALWAYS, "=== Chunk Header ===\n");
		dprintf (ALWAYS, "chunk_type: 0x%x\n", chunk_header->chunk_type);
		dprintf (ALWAYS, "chunk_data_sz: 0x%x\n", chunk_header->chunk_sz);
		dprintf (ALWAYS, "total_size: 0x%x\n", chunk_header->total_sz);
		*/

		if (sparse_header->chunk_hdr_sz > sizeof(chunk_header_t)) {
			/* Skip the remaining bytes in a header that is longer than
			* we expected.
			*/
			data += (sparse_header->chunk_hdr_sz - sizeof(chunk_header_t));
		}

		chunk_data_sz = (unsigned long long)(sparse_header->blk_sz&0xFFFFFFFF);
		chunk_data_sz = chunk_data_sz * chunk_header->chunk_sz;
		chunk_sector_sz = chunk_data_sz / 4096;
		switch (chunk_header->chunk_type) {
			case CHUNK_TYPE_RAW:
				if (chunk_header->total_sz != (sparse_header->chunk_hdr_sz +
				                               chunk_data_sz)) {
					dprintf(CRITICAL, "size mismatch, chunk_header->total_sz %llu total size %llu", chunk_header->total_sz,
					(sparse_header->chunk_hdr_sz + chunk_data_sz));
					return FALSE;
				}

				list[0].address = data;
				list[0].size = chunk_data_sz;
				list[1].size = 0;
				ret = mntl_write(mntl, StartLBA, &list);
				if (ret < 0) {
					dprintf(CRITICAL, "flash write failure");
					return FALSE;
				}

				data += chunk_data_sz;
				StartLBA += chunk_sector_sz;

				break;

			case CHUNK_TYPE_DONT_CARE:
				StartLBA += chunk_sector_sz;

				break;
			case CHUNK_TYPE_CRC:
				crc_value = *(unsigned int*)data;
				data += 4;
				break;

			case CHUNK_TYPE_FILL:
				dprintf (ALWAYS, "%s %d: CHUNK_TYPE_FILL=0x%x size=%d chunk_data_sz=%d\n", __FUNCTION__, __LINE__, *(uint32_t *)data, ROUNDUP(sparse_header->blk_sz, CACHE_LINE), chunk_data_sz);
				if (chunk_header->total_sz != (sparse_header->chunk_hdr_sz + sizeof(uint32_t))) {
					dprintf(CRITICAL, "Bogus chunk size for chunk type FILL");
					return FALSE;
				}

				fill_buf = (uint32_t *)memalign(CACHE_LINE, ROUNDUP(sparse_header->blk_sz, CACHE_LINE));
				if (!fill_buf) {
					dprintf(CRITICAL, "Malloc failed for: CHUNK_TYPE_FILL");
					return FALSE;
				}

				fill_val = *(uint32_t *)data;
				for (i = 0; i < (sparse_header->blk_sz / sizeof(fill_val)); i++) {
					fill_buf[i] = fill_val;
				}

				for (i = 0; i < chunk_header->chunk_sz; i++) {
					list[0].address = fill_buf;
					list[0].size = sparse_header->blk_sz;
					list[1].size = 0;
					ret = mntl_write(mntl, StartLBA, &list);
					if (ret < 0) {
						dprintf(CRITICAL, "CHUNK_TYPE_FILL flash write failure");
						free(fill_buf);
						return FALSE;
					}

					StartLBA += sparse_header->blk_sz / 4096;
				}
				free(fill_buf);

				data += 4;  //data length is 4.
				break;
			default:
				dprintf(CRITICAL, "Unknown chunk type");
				return FALSE;
		}
		dprintf(CRITICAL, "\rWrite Data", total_blocks*sparse_header->blk_sz, sparse_header->total_blks*sparse_header->blk_sz);
	}

	mntl_commit(mntl);
	dprintf(CRITICAL, "%s: mntl partition %s, sz %u, StartLBA %llu\n",
						__FUNCTION__, arg, sz, StartLBA);

	return TRUE;
}


int mntl_partition_erase(char *part_name)
{
	uint64_t StartLBA = 0, EndLBA = 0;

	mntl_read_gpt(part_name, &StartLBA, &EndLBA);
	mntl_discard(mntl, StartLBA, EndLBA - StartLBA + 1);

	dprintf(CRITICAL, "%s: mntl partition %s\n",
						__FUNCTION__, part_name);

	return 0;
}
