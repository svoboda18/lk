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
#include <printf.h>
#include <malloc.h>
#include <string.h>
#include <lib/crc.h>
#include <platform/mt_typedefs.h>
#include <platform/partition.h>
#include <efi.h>
#include <part_interface.h>
#include <block_generic_interface.h>
#include <pal_log.h>

#ifndef min
#define min(x, y)   (x < y ? x : y)
#endif

extern bool cmdline_append(const char *append_string);
static part_t *g_part_ptr = NULL;
u32 sgpt_partition_lba_size;
static u64 g_gpt_entry_cnt = 0;
/*
 ********** Definition of Debug Macro **********
 */
#define TAG "[GPT_LK]"

#define LEVEL_ERR   (0x0001)
#define LEVEL_INFO  (0x0004)

#define DEBUG_LEVEL (LEVEL_ERR | LEVEL_INFO)

#define efi_err(fmt, args...)   \
do {    \
    if (DEBUG_LEVEL & LEVEL_ERR) {  \
        pal_log_err(fmt, ##args); \
    }   \
} while (0)

#define efi_critical(fmt, args...)  \
do {    \
    if (DEBUG_LEVEL & LEVEL_INFO) {  \
        pal_log_err(fmt, ##args);    \
    }   \
} while (0)


/*
 ********** Definition of GPT buffer **********
 */

static u32 efi_crc32(u8 *p, u32 len)
{
	return (crc32_no_comp(~0L, p, len) ^ ~0L);  /* from zlib */
}

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

u64 get_entry_count()
{
	return g_gpt_entry_cnt;
}
extern u64 g_emmc_user_size;

u64 last_lba(u32 part_id)
{
	part_dev_t *dev;
	dev = mt_part_get_device();
	if (!dev) {
		efi_err("%s%s, err(no dev)\n", TAG, __func__);
		return 1;
	}

	/* Only support USER region now */
#if (defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT))
	if (dev->blkdev->type == BOOTDEV_SDMMC) {
		return g_emmc_user_size / dev->blkdev->blksz - 1;
	} else if (dev->blkdev->type == BOOTDEV_UFS) {
		u64 bytes;

		bytes = dev->get_part_size(dev, part_id);
		if (bytes)
			return bytes / dev->blkdev->blksz - 1;
		else
			return 0;
	}
#endif
	return 0;
}

static void set_spgt_partition_lba_size(u32 size)
{
	sgpt_partition_lba_size = size;

}

static u32 get_spgt_partition_lba_size()
{
	return sgpt_partition_lba_size;
}

static u64 get_gpt_header_last_usable_lba()
{
	part_dev_t *dev = mt_part_get_device();

	return (last_lba(dev->blkdev->part_user)-get_spgt_partition_lba_size());

}

static u32 entries_crc32;
static void set_entries_crc32(u32 crc32)
{
	entries_crc32 = crc32;
}
static u32 get_entries_crc32(void)
{
	return entries_crc32;
}

static int read_data(u8 *buf, u32 part_id, u64 lba, u64 size)
{
	int err;
	part_dev_t *dev;

	dev = mt_part_get_device();
	if (!dev) {
		efi_err("%sread data, err(no dev)\n", TAG);
		return 1;
	}

	err = dev->read(dev, lba * dev->blkdev->blksz, buf, (int)size, part_id);
	if (err != (int)size) {
		efi_err("%sread data, err(%d)\n", TAG, err);
		return err;
	}

	return 0;
}

static int write_data(u64 lba, u8 *buf, u64 size,  u32 part_id)
{
	int err;
	part_dev_t *dev;

	dev = mt_part_get_device();
	if (!dev) {
		efi_err("%swrite data, err(no dev)\n", TAG);
		return 1;
	}
	err = dev->write(dev, buf, lba * dev->blkdev->blksz, (int)size, part_id);
	if (err != (int)size) {
		efi_err("%s write data, err(%d)\n", TAG, err);
		return err;
	}

	return 0;
}

const char hex_asc[] = "0123456789abcdef";
#define hex_asc_lo(x) hex_asc[((x)&0x0f)];
#define hex_asc_hi(x) hex_asc[((x)&0xf0)>>4];
static inline char *hex_byte_pack(char *buf, u8 byte)
{
	*buf++ = hex_asc_hi(byte);
	*buf++ = hex_asc_lo(byte);
	return buf;
}

static u8 *string(u8 *buf, u8 *end, const char *s)
{
	int len, i;
	len = strnlen(s, PART_META_INFO_UUIDLEN);
	for (i = 0; i < len; ++i) {
		if (buf < end)
			*buf = *s;
		++buf;
		++s;
	}
	if (buf < end)
		*buf = 0;
	return buf;
}

static u8 *uuid_string(u8 *buf, u8 *args)
{
	/* uuid format: xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxx, which contains 16*2 + 4('-') + 1 ('\0') = 37 bytes*/
	char uuid[PART_META_INFO_UUIDLEN];
	char *p = uuid;
	int i;
	static const u8 index[16] = {3,2,1,0,5,4,7,6,8,9,10,11,12,13,14,15};
	u8 *end;

	end = buf + PART_META_INFO_UUIDLEN;
	for (i = 0; i < 16; i++) {
		p = hex_byte_pack(p, args[index[i]]);
		switch(i) {
		case 3:
		case 5:
		case 7:
		case 9:
			*p++ = '-';
			break;
		default:
			break;
		}
	}

	*p = 0;
	return string(buf, end, uuid);
}

static inline u8 *efi_guid_unparse(efi_guid_t *guid, u8 *out)
{
	if (NULL == uuid_string(out, guid->b)) {
		efi_err("parse uuid string format fail!\n");
		return NULL;
	}
	return out;
}

static int parse_gpt_header(u32 part_id, u64 header_lba, u8 *header_buf, u8 *entries_buf)
{
	int i;
	int err;
	u32 calc_crc, orig_header_crc;
	u64 entries_real_size, entries_read_size, num_block_entry;
	part_dev_t *dev = mt_part_get_device();

	gpt_header *header = (gpt_header *)header_buf;
	gpt_entry *entries = (gpt_entry *)entries_buf;

	struct part_meta_info *info;

	if (!dev) {
		efi_err("%s%s, err(no dev)\n", TAG, __func__);
		return 1;
	}

	if (g_part_ptr == NULL) {
		efi_err("%sg_part_ptr is NULL, partition table was not initialized\n", TAG);
		return 1;
	}

	if (header_buf == NULL) {
		efi_err("%sheader_buf is NULL\n", TAG);
		return 1;
	}

	if (entries_buf == NULL) {
		efi_err("%sentries_buf is NULL\n", TAG);
		return 1;
	}

	err = read_data(header_buf, part_id, header_lba, dev->blkdev->blksz);
	if (err) {
		efi_err("%sread header(part_id=%d,lba=%llx), err(%d)\n",
				TAG, part_id, header_lba, err);
		return err;
	}

	if (header->signature != GPT_HEADER_SIGNATURE) {
		efi_err("%scheck header, err(signature 0x%llx!=0x%llx)\n",
				TAG, header->signature, GPT_HEADER_SIGNATURE);
		return 1;
	}

	orig_header_crc = header->header_crc32;
	header->header_crc32 = 0;
	calc_crc = efi_crc32((u8 *)header, header->header_size);

	if (orig_header_crc != calc_crc) {
		efi_err("%scheck header, err(crc 0x%x!=0x%x(calc))\n",
				TAG, orig_header_crc, calc_crc);
		return 1;
	}

	header->header_crc32 = orig_header_crc;

	if (header->my_lba != header_lba) {
		efi_err("%scheck header, err(my_lba 0x%llx!=0x%llx)\n",
				TAG, header->my_lba, header_lba);
		return 1;
	}

	entries_real_size = (u64)header->num_partition_entries * header->sizeof_partition_entry;
	num_block_entry = (u64)(dev->blkdev->blksz / header->sizeof_partition_entry);
	entries_read_size = (u64)((header->num_partition_entries + (num_block_entry -1)) / num_block_entry) * dev->blkdev->blksz;

	err = read_data(entries_buf, part_id, header->partition_entry_lba, entries_read_size);
	if (err) {
		efi_err("%sread entries(part_id=%d,lba=%llx), err(%d)\n",
				TAG, part_id, header->partition_entry_lba, err);
		return err;
	}

	calc_crc = efi_crc32((u8 *)entries, (u32)entries_real_size);

	if (header->partition_entry_array_crc32 != calc_crc) {
		efi_err("%scheck header, err(entries crc 0x%x!=0x%x(calc))\n",
				TAG, header->partition_entry_array_crc32, calc_crc);
		return 1;
	}

	efi_critical("%s user part id = %d\n", TAG, dev->blkdev->part_user);
	for (i = 0; (u32)i < header->num_partition_entries; i++) {
		/* break if the partition entry is empty */
		if (!entries[i].starting_lba) {
			break;
		}
		g_part_ptr[i].start_sect = (unsigned long)entries[i].starting_lba;
		g_part_ptr[i].nr_sects = (unsigned long)(entries[i].ending_lba - entries[i].starting_lba + 1);
		g_part_ptr[i].part_attr = (unsigned long)entries[i].attributes;
		g_part_ptr[i].part_id = dev->blkdev->part_user;
		info = malloc(sizeof(*info));
		if (!info) {
			continue;
		}
		g_part_ptr[i].info = info;
		if ((entries[i].partition_name[0] & 0xFF00) == 0) {
			w2s(g_part_ptr[i].info->name, PART_META_INFO_NAMELEN, entries[i].partition_name, GPT_ENTRY_NAME_LEN);
		} else {
			memcpy(g_part_ptr[i].info->name, entries[i].partition_name, 64);
		}

		if (NULL == efi_guid_unparse(&entries[i].unique_partition_guid, g_part_ptr[i].info->uuid)) {
			efi_err("efi parse uuid string fail!\n");
			return 1;
		}

		efi_critical("%s[%d]name=%s, start_sect=0x%lx, nr_sects=0x%lx, uuid=%s\n", TAG, i,
			g_part_ptr[i].info ? (char *)g_part_ptr[i].info->name : "unknown",
			g_part_ptr[i].start_sect, g_part_ptr[i].nr_sects,
			g_part_ptr[i].info ? (char *)g_part_ptr[i].info->uuid : "");
	}
	// record the total entry count
	g_gpt_entry_cnt = i;
	return 0;
}


int read_gpt(part_t *part)
{
	int err;
	u64 lba;
	u8 *pgpt_header, *pgpt_entries;
	u8 *sgpt_header, *sgpt_entries;
	u32 part_id, gpt_entries_size;
	part_dev_t *dev = mt_part_get_device();
	if (!dev) {
		efi_err("%s%s, err(no dev)\n", TAG, __func__);
		return 1;
	}
	part_id = dev->blkdev->part_user;
	gpt_entries_size = sizeof(gpt_entry) * PART_MAX_COUNT;

	g_part_ptr = part;

	efi_critical("%sParsing Primary GPT now...\n", TAG);

	pgpt_header = (u8 *)malloc(dev->blkdev->blksz);
	if (!pgpt_header) {
		efi_err("%smalloc memory(pgpt header), err\n", TAG);
		goto next_try;
	}
	memset(pgpt_header, 0, dev->blkdev->blksz);

	pgpt_entries = (u8 *)malloc(gpt_entries_size);
	if (!pgpt_entries) {
		free(pgpt_header);
		efi_err("%smalloc memory(pgpt entries), err\n", TAG);
		goto next_try;
	}
	memset(pgpt_entries, 0, gpt_entries_size);

	err = parse_gpt_header(part_id, 1, pgpt_header, pgpt_entries);
	/* Free pgpt buffers after using it */
	free(pgpt_header);
	free(pgpt_entries);
	if (!err) {
		goto find;
	}

next_try:
	efi_critical("%sParsing Secondary GPT now...\n", TAG);

	sgpt_header = (u8 *)malloc(dev->blkdev->blksz);
	if (!sgpt_header) {
		efi_err("%smalloc memory(sgpt header), err\n", TAG);
		return 1;
	}
	memset(sgpt_header, 0, dev->blkdev->blksz);

	sgpt_entries = (u8 *)malloc(gpt_entries_size);
	if (!sgpt_entries) {
		free(sgpt_header);
		efi_err("%smalloc memory(sgpt entries), err\n", TAG);
		return 1;
	}
	memset(sgpt_entries, 0, gpt_entries_size);

	lba = last_lba(part_id);
	if (!lba) {
		free(sgpt_header);
		free(sgpt_entries);
		efi_err("%sFailure to find last lba.\n", TAG);
		return 1;
	}
	err = parse_gpt_header(part_id, lba, sgpt_header, sgpt_entries);
	/* Free sgpt buffers after using it */
	free(sgpt_header);
	free(sgpt_entries);
	if (!err) {
		goto find;
	}

	efi_err("%sFailure to find valid GPT.\n", TAG);
	return err;

find:
	efi_critical("%sSuccess to find valid GPT.\n", TAG);
	return 0;
}

static void pack_pmbr_data(void *ptr)
{
	pmbr *mbr = (pmbr *)ptr;
	u64 nr_sects;
	u16 nr_sects_split[2];
	u16 *nr_sects_split_ptr;
	part_dev_t *dev = mt_part_get_device();
	if (!dev) {
		efi_err("%s%s, err(no dev)\n", TAG, __func__);
		return;
	}

	nr_sects = last_lba(dev->blkdev->part_user) + 1;
	mbr->partition_record[0].sys_ind = GPT_PROTECTIVE_MBR;
	mbr->partition_record[0].start_sector = 0x1;
	/* Suffer from mbr->partition_record[0].nr_sects address not 4-byte aligned(data abort will occur if directly write u32 data), split it into two 2-byte */
	nr_sects_split[0] = ((nr_sects < 0xFFFFFFFF) ? (nr_sects - 1) : 0xFFFFFFFF) & 0xFFFF;
	nr_sects_split[1] = (((nr_sects < 0xFFFFFFFF) ? (nr_sects - 1) : 0xFFFFFFFF) >> 16) & 0xFFFF;
	nr_sects_split_ptr = (u16 *)(&((mbr->partition_record[0].nr_sects)));
	*nr_sects_split_ptr = nr_sects_split[0];
	*(nr_sects_split_ptr +1) = nr_sects_split[1];
	mbr->signature = 0xAA55;
}

static void pack_pheader_data(void *data)
{
	part_dev_t *dev = mt_part_get_device();
	if (!dev) {
		efi_err("%s%s, err(no dev)\n", TAG, __func__);
		return;
	}

	gpt_header *header = (gpt_header *)data;
	header->reserved = 0;
	header->alternate_lba = last_lba(dev->blkdev->part_user);
	header->last_usable_lba = get_gpt_header_last_usable_lba();
	header->partition_entry_array_crc32 = get_entries_crc32();
	header->header_crc32 = 0;
	header->header_crc32 = efi_crc32(data, sizeof(gpt_header));
}

static void pack_entries_data(void *data)
{
	int i;
	int nr_parts = 0;
	part_dev_t *dev = mt_part_get_device();
	gpt_entry *entries = (gpt_entry *)data;

	if (!dev) {
		efi_err("%s%s, err(no dev)\n", TAG, __func__);
		return;
	}

	//calculate how many partitions
	for (i = 0; i < PART_MAX_COUNT; i++) {
		if (!entries[i].partition_name[0]) {
			nr_parts = i;
			break;
		}
	}
	efi_err("%snumber of partitions: %d.\n", TAG, nr_parts);

	/* Update gpt entries */
	for (i = nr_parts-1; i >= 0; i--) {
		/* it's last partition (do not have reserved partition ex: no flashinfo, otp), only need to update last partition */
		/* may not go to here unless customer remove flashinfo partition */
		if (i == nr_parts-1 && !entries[i].starting_lba && !entries[i].ending_lba) {
			entries[i].ending_lba = last_lba(dev->blkdev->part_user) - get_spgt_partition_lba_size() ;
			entries[i].starting_lba = entries[i-1].ending_lba + 1;
			break;
		}

		/* Process reserved partitions(flashinfo, otp) and last partition before reserved partition(ex: userdata or intsd) */
		/* Reserved partition size is stored in ending_lba, sgpt partition size can be retrived from  get_spgt_partition_size()(stored in header->reserved)*/
		if (!entries[i].starting_lba) {
			/* it's a reserved partition and it's last partition, entries[i].ending_lba not empty(partition size is here)  */
			if (i == nr_parts-1 && entries[i].ending_lba) {
				entries[i].starting_lba = last_lba(dev->blkdev->part_user) - get_spgt_partition_lba_size() - entries[i].ending_lba + 1;
				entries[i].ending_lba = last_lba(dev->blkdev->part_user) - get_spgt_partition_lba_size() ;
			}
			/* reserved parttiion but not last one  */
			/* may not go to here uless there exists more than one reserved partitions (ex: otp + flashinfo)*/
			else if (entries[i].ending_lba) {
				entries[i].starting_lba = entries[i+1].starting_lba - entries[i].ending_lba;
				entries[i].ending_lba = entries[i+1].starting_lba - 1;
			}
			/* userdata or intsed */
			else {
				entries[i].starting_lba = entries[i-1].ending_lba + 1;
				entries[i].ending_lba = entries[i+1].starting_lba - 1;
			}

		}
	}
	set_entries_crc32(efi_crc32(data, PART_MAX_COUNT * sizeof(gpt_entry)));
}

static void pack_sheader_data(void *data)
{
	gpt_header *header = (gpt_header *)data;

	header->header_crc32 = 0;
	header->my_lba = header->alternate_lba;
	header->alternate_lba = 1;
	header->partition_entry_lba = get_gpt_header_last_usable_lba() + 1;
	header->partition_entry_array_crc32 = get_entries_crc32();
	header->header_crc32 = efi_crc32(data, sizeof(gpt_header));
}


int write_primary_gpt(void *data, unsigned sz)
{
	int err, part_entries_cnt_per_block;
	u64 pentries_write_size;
	gpt_header *header;
	gpt_entry *entries;
	pmbr *mbr;
	int with_pmbr; /* 0: data is without pmbr, 1: data is with pmbr*/
	part_dev_t *dev = mt_part_get_device();
	if (!dev) {
		efi_err("%s%s, err(no dev)\n", TAG, __func__);
		return -1;
	}

	/* fastboot PGPT image check */
	if (sz == (PART_MAX_COUNT*sizeof(gpt_entry)+dev->blkdev->blksz)) {
		with_pmbr = 0;
		mbr = NULL;
		header = (gpt_header *)data;
		entries = (gpt_entry *)(data + dev->blkdev->blksz);
	} else if (sz == (PART_MAX_COUNT*sizeof(gpt_entry)+dev->blkdev->blksz * 2)) {
		with_pmbr = 1;
		mbr = (pmbr *)data;
		header = (gpt_header *)(data + dev->blkdev->blksz);
		entries = (gpt_entry *)(data + dev->blkdev->blksz * 2);
	} else {
		err = -1;
		efi_err("[GPT_Update]PGPT size not correct, err(%d), expect: 0x%lx read: 0x%x\n", err, (PART_MAX_COUNT*sizeof(gpt_entry)+dev->blkdev->blksz), sz);
		return err;
	}

	if (header->signature != GPT_HEADER_SIGNATURE) {
		err = -1;
		efi_err("[GPT_Update] %scheck header, err(signature 0x%llx!=0x%llx)\n",
				TAG, header->signature, GPT_HEADER_SIGNATURE);
		return err;
	}

	if (!with_pmbr) {
		mbr = (pmbr *)malloc(dev->blkdev->blksz);
		if (!mbr) {
			err = -1;
			efi_err("%s malloc memory(pmbr header), err\n", TAG);
			return err;
		}
		memset(mbr, 0, dev->blkdev->blksz);
	}

	if (header->alternate_lba != last_lba(dev->blkdev->part_user)) {
		set_spgt_partition_lba_size(header->alternate_lba); //sgpt partition size is hrere
	} else {
		set_spgt_partition_lba_size(last_lba(dev->blkdev->part_user) - header->last_usable_lba);
	}

	pack_entries_data((void *)entries); //move to gpt entries
	pack_pheader_data((void *)header); //update pheader
	pack_pmbr_data((void *)mbr);

	/* Write pmbr */
	err = write_data(0, (u8 *)mbr, (u64)dev->blkdev->blksz, dev->blkdev->part_user);
	if (!with_pmbr)
		free(mbr); /* Free pmbr after use it */
	if (err) {
		efi_err("[GPT_Update]write pmbr, err(%d)\n", err);
		return err;
	}
	/* Write pheader */
	err = write_data(1, (u8 *)header, (u64)dev->blkdev->blksz, dev->blkdev->part_user);
	if (err) {
		efi_err("[GPT_Update]write pheader, err(%d)\n", err);
		return err;
	}
	/* Write gpt entries */
	part_entries_cnt_per_block = dev->blkdev->blksz / header->sizeof_partition_entry;
	pentries_write_size = (u64)((PART_MAX_COUNT + part_entries_cnt_per_block - 1) / part_entries_cnt_per_block) * dev->blkdev->blksz;
	err = write_data(2, (u8 *)entries, pentries_write_size, dev->blkdev->part_user);
	if (err) {
		efi_err("[GPT_Update]write pentries, err(%d)\n", err);
		return err;
	}
	return 0;
}

int write_secondary_gpt(void *data, unsigned sz)
{
	int err, part_entries_cnt_per_block;
	u64 pentries_write_size;
	u64 sentries_start_lba;
	gpt_header *header;
	gpt_entry *entries;
	part_dev_t *dev = mt_part_get_device();
	if (!dev) {
		efi_err("%s%s, err(no dev)\n", TAG, __func__);
		return -1;
	}

	/* fastboot PGPT image check */
	if (sz == (PART_MAX_COUNT*sizeof(gpt_entry)+dev->blkdev->blksz)) {
		header = (gpt_header *)data;
		entries = (gpt_entry *)(data + dev->blkdev->blksz);
	} else if (sz == (PART_MAX_COUNT*sizeof(gpt_entry)+dev->blkdev->blksz * 2)) {
		header = (gpt_header *)(data + dev->blkdev->blksz);
		entries = (gpt_entry *)(data + dev->blkdev->blksz * 2);
	} else {
		err = -1;
		efi_err("[GPT_Update]SGPT size not correct, err(%d), expect: 0x%lx read: 0x%x\n", err, (PART_MAX_COUNT*sizeof(gpt_entry)+dev->blkdev->blksz), sz);
		return err;
	}
	if (header->signature != GPT_HEADER_SIGNATURE) {
		err = -1;
		efi_err("[GPT_Update] %s check header, err(signature 0x%llx!=0x%llx)\n",
				TAG, header->signature, GPT_HEADER_SIGNATURE);
		return err;
	}

	pack_sheader_data(header); //update sheader

	/* Write sheader */
	err = write_data(last_lba(dev->blkdev->part_user), (u8 *)header, (u64)dev->blkdev->blksz, dev->blkdev->part_user);
	if (err) {
		efi_err("[GPT_Update]write sheader, err(%d)\n", err);
		return err;
	}
	/* Write gpt entries */
	sentries_start_lba = get_gpt_header_last_usable_lba() + 1;
	part_entries_cnt_per_block = dev->blkdev->blksz / header->sizeof_partition_entry;
	pentries_write_size = (u64)((PART_MAX_COUNT + part_entries_cnt_per_block - 1) / part_entries_cnt_per_block) * dev->blkdev->blksz;
	err = write_data(sentries_start_lba, (u8 *)entries, pentries_write_size, dev->blkdev->part_user);
	if (err) {
		efi_err("[GPT_Update]write pentries, err(%d)\n", err);
		return err;
	}
	return 0;
}

unsigned int *target_commandline_force_gpt(char *cmd)
{
	cmdline_append("gpt=1");
	return 0;
}
