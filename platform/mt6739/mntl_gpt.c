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
#include <debug.h>

char *part_entry;
GuidPartitionTableHeader_t pgpt_header;

static int mt_get_sector_size(int *sector_size)
{
	*sector_size = 4096;
    return 0;
}

static int mt_gpt_get_part_entry(struct mntl_handler *mntl, int sector_size)
{
	char *ptr = NULL;
	int ret;
	struct mntl_scatter_list list[2];
	uint64_t len = 2 * sector_size;

	dprintf(CRITICAL, "len %llu\n", len);
	ptr = (char *)malloc(len);
	if (ptr == NULL) {
		dprintf(CRITICAL, "malloc fail\n");
		return 1;
	}

	list[0].address = ptr;
	list[0].size = len;
	list[1].size = 0;
	ret = mntl_read(mntl, 0, &list);
	if (ret < 0) {
		dprintf(CRITICAL, "read sector fail\n");
		free(ptr);
		return 1;
	}
	memcpy(&pgpt_header, &ptr[sector_size], sizeof(pgpt_header));
	free(ptr);

	dprintf(CRITICAL, "PGPT:\n");
	dprintf(CRITICAL, "Header CRC=%u\n", (unsigned int)pgpt_header.HeaderCRC32);
	dprintf(CRITICAL, "Header Size=%d\n", pgpt_header.HeaderSize);
	dprintf(CRITICAL, "Current LBA=%llu\n", pgpt_header.MyLBA);
	dprintf(CRITICAL, "Backup LBA=%llu\n", pgpt_header.AlternateLBA);
	dprintf(CRITICAL, "First usable LBA=%llu\n", pgpt_header.FirstUsableLBA);
	dprintf(CRITICAL, "Last usable LBA=%llu\n", pgpt_header.LastUsableLBA);
	dprintf(CRITICAL, "Starting PE LBA=%llu\n", pgpt_header.PartitionEntryLBA);
	dprintf(CRITICAL, "Number of PE=%d\n", pgpt_header.NumberOfPartitionEntries);
	dprintf(CRITICAL, "Size of PE=%d\n", pgpt_header.SizeOfPartitionEntry);
	dprintf(CRITICAL, "PE CRC=%u\n", pgpt_header.PartitionEntryArrayCRC32);

	len = ((uint64_t) pgpt_header.NumberOfPartitionEntries * (uint64_t)pgpt_header.SizeOfPartitionEntry);
	len = (len / sector_size + 1) * sector_size;	/* align multiple of sector_size */
	if ((len >> 32) > 0) {
		dprintf(CRITICAL, "currently, we do not support allocate buffer size larger than 32-bit\n");
		return 1;
	}
	part_entry = (char *)malloc(len);

	if (part_entry == NULL) {
		dprintf(CRITICAL, "malloc fail\n");
		return 1;
	}

	list[0].address = part_entry;
	list[0].size = len;
	list[1].size = 0;
	ret = mntl_read(mntl, pgpt_header.PartitionEntryLBA, &list);
	if (ret < 0){
		dprintf(CRITICAL, "read PE fail\n");
		free(part_entry);
		part_entry = NULL;
		return 1;
	}

	return 0;
}

int mntl_gpt_init(struct mntl_handler *mntl)
{
	GuidPartitionEntry_t *pe;
	int sector_size = 0;
	int i = 0;

	dprintf(CRITICAL, "read gpt start!\n");
	// get sector size
	if (mt_get_sector_size(&sector_size) != 0) {
		dprintf(CRITICAL, "Get sector size fail!\n");
		return 1;
	}

	// read partition entry
	if (mt_gpt_get_part_entry(mntl, sector_size) > 0) {
		dprintf(CRITICAL, "Get partition entry fail!\n");
		return 1;
	}
	dprintf(CRITICAL, "First usable LBA=%llu\n", pgpt_header.FirstUsableLBA);

	pe = (GuidPartitionEntry_t *)part_entry;

	for (i = 0; i < pgpt_header.NumberOfPartitionEntries; i++, pe++) {
		unsigned int j;
		char name[37];
		dprintf(CRITICAL, "Partition Entry %d\n", i + 1);
		dprintf(CRITICAL, "\tFirst LBA=%llu\n", pe->StartingLBA);
		dprintf(CRITICAL, "\tLast LBA=%llu\n", pe->EndingLBA);
		for (j = 0; j < 72 / sizeof(efi_char16_t); j++) {
			name[j] = (uint16_t)pe->PartitionName[j];
		}
		name[j] = 0;
		dprintf(CRITICAL, "\tName=%s\n", name);
	}

	return 0;
}

int mntl_read_gpt(char *part_name, uint64_t *StartLBA, uint64_t *EndLBA)
{
	GuidPartitionEntry_t *pe;
	int i = 0;

	pe = (GuidPartitionEntry_t *)part_entry;
	for (i = 0; i < pgpt_header.NumberOfPartitionEntries; i++, pe++) {
		unsigned int j;
		char name[37];
		for (j = 0; j < 72 / sizeof(efi_char16_t); j++) {
			name[j] = (uint16_t)pe->PartitionName[j];
		}
		name[j] = 0;
		dprintf(CRITICAL, "\tName=%s\n", name);
		if (!strcmp(name,part_name)) {
			dprintf(CRITICAL, "Partition Entry %d\n", i + 1);
			dprintf(CRITICAL, "\tFirst LBA=%llu\n", pe->StartingLBA);
			dprintf(CRITICAL, "\tLast LBA=%llu\n", pe->EndingLBA);
			*StartLBA = pe->StartingLBA;
			*EndLBA = pe->EndingLBA;
			break;
		}
	}

	if (i == pgpt_header.NumberOfPartitionEntries) {
		dprintf(CRITICAL, "Cannot find partition %s\n", part_name);
		return 1;
	}

	return 0;
}
