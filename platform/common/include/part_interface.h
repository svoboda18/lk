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

#ifndef __PART_INTERFACE_H__
#define __PART_INTERFACE_H__

#include <platform/mt_typedefs.h>
#include <pal_typedefs.h>
#include <part_dev.h>
#include <part_status.h>

#define PART_COMMON_TAG "[PART_COMMON_LK]"

#if !defined MTK_PARTITION_COMMON && defined MTK_AVB20_SUPPORT
#include <partition.h>
#endif

#ifdef MTK_PARTITION_COMMON
#define PART_META_INFO_NAMELEN  64
#define PART_META_INFO_UUIDLEN  37
#define PART_ATTR_LEGACY_BIOS_BOOTABLE  (0x00000004UL) /* bit2 = active bit for OTA */

struct part_meta_info {
	uint8_t name[PART_META_INFO_NAMELEN];
	uint8_t uuid[PART_META_INFO_UUIDLEN];
};

typedef struct {
	unsigned long  start_sect;
	unsigned long  nr_sects;
	unsigned long  part_attr;
	unsigned int part_id;
	char *name;
	struct part_meta_info *info;
} part_t;

struct part_name_map {
	char fb_name[32];   /*partition name used by fastboot*/
	char r_name[32];    /*real partition name*/
	char *partition_type;   /*partition_type*/
	int partition_idx;  /*partition index*/
	int is_support_erase;   /*partition support erase in fastboot*/
	int is_support_dl;  /*partition support download in fastboot*/
};

enum {
	RAW_DATA_IMG,
	YFFS2_IMG,
	UBIFS_IMG,
	EXT4_IMG,
	FAT_IMG,
	UNKOWN_IMG,
};
#endif
/* name collision with partition_get_size, so we add "by_name" */
/* looking forward to fix this in the future */
int partition_get_index_by_name(const char *part_name);
const char* partition_get_name_by_index(int index);
u64 partition_get_size_by_name(const char *part_name);
u64 partition_get_offset_by_name(const char *part_name);
char* partition_get_real_name(const char *part_name);
int partition_get_region_by_name(const char *part_name);
int partition_get_active_bit_by_name(const char *part_name);
u8* partition_get_uuid_by_name(const char *part_name);
ssize_t partition_read(const char *part_name, off_t offset, u8* data, size_t size);
ssize_t partition_write(const char *part_name, off_t offset, u8* data, size_t size);
int partition_erase(const char *part_name);
int partition_exists(const char *part_name);
int partition_support_erase(const char *part_name);
int partition_support_flash(const char *part_name);
#ifdef MTK_PARTITION_COMMON
int part_init(part_dev_t *dev);
int partition_get_index(const char * name);
u32 partition_get_region(int index);
u64 partition_get_offset(int index);
u64 partition_get_size(int index);
int partition_get_type(int index, char **p_type);
int partition_get_name(int index, char **p_name);
int is_support_erase(int index);
int is_support_flash(int index);
u64 emmc_write(u32 region, u64 offset, void *data, u64 size);
u64 emmc_read(u32 region, u64 offset, void *data, u64 size);
int emmc_erase(u32 region, u64 offset, u64 size);
unsigned long mt_part_get_part_active_bit(part_t *part);
int write_primary_gpt(void *data, unsigned sz);
int write_secondary_gpt(void *data, unsigned sz);
int read_gpt(part_t *part);
void mt_part_dump(void);
u64 last_lba(u32 part_id);
#endif
#endif /* __PART_INTERFACE_H__ */
