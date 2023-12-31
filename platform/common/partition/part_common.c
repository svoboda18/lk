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
#include <platform/mt_typedefs.h>
#ifdef MTK_GPT_SCHEME_SUPPORT
#include <platform/partition.h>
#else
#include <mt_partition.h>
#endif
#include <platform/errno.h>
#include <platform/mt_reg_base.h> // to get bootdevice base address
#include <debug.h>
#include <string.h>
#include <stdlib.h>
#include <part_interface.h>
#include <part_status.h>
#include <pal_log.h>
#include <block_generic_interface.h>
#ifdef MTK_AB_OTA_UPDATER
#include <bootctrl.h>
#endif
#if defined(MTK_UFS_SUPPORT)
#include "ufs_aio_core.h"
#endif
#if defined(MTK_EMMC_SUPPORT)
#include "mmc_core.h"
#endif


typedef struct {
	char official_name[12];
	char alt_name1[12];
	char alt_name2[12];
	char alt_name3[12];
} PART_TRANS_TBL_ENTRY;

const PART_TRANS_TBL_ENTRY g_part_name_trans_tbl[] = {
	{"misc",      "para",      "NULL",    "NULL"      },
	{"preloader", "PRELOADER", "NULL",    "NULL"      },
	{"seccfg",    "SECCFG",    "SECCNFG", "NULL"      },
	{"uboot",     "UBOOT",     "lk",      "LK"        },
	{"boot",      "BOOT",      "bootimg", "BOOTIMG"   },
	{"recovery",  "RECOVERY",  "NULL",    "NULL"      },
	{"secro",     "SECRO",     "sec_ro",  "SEC_RO"    },
	{"logo",      "LOGO",      "NULL",    "NULL"      },
	{"system",    "SYSTEM",    "android", "ANDROID"   },
	{"userdata",  "USERDATA",  "usrdata", "USRDATA"   },
	{"frp",       "FRP",       "NULL",    "NULL"      },
	{"scp1",      "SCP1",      "NULL",    "NULL"      },
	{"scp2",      "SCP2",      "NULL",    "NULL"      },
	{"odmdtbo",   "ODMDTBO",   "dtbo",    "DTBO"      },
	{"NULL",      "NULL",      "NULL",    "NULL"      },
};

#ifdef MTK_PARTITION_COMMON
int real_partition_count = 0;
part_t *g_partition_all, *partition;;
extern struct part_name_map g_part_name_map[PART_MAX_COUNT];
extern int mmc_get_boot_part(u32 *bootpart);

int partition_get_index(const char * name)
{
	int i;
#ifdef MTK_AB_OTA_UPDATER
	char last_char[2];
	const char *part_suffix;
	char alt_name[PART_META_INFO_NAMELEN + BOOTCTRL_SUFFIX_MAXLEN];
	int check_alt_name = 0;
#endif

	if (name == NULL)
		return -1;

#ifdef MTK_AB_OTA_UPDATER
	/* get_suffix will call partition_read to get para partition information, which will cause infinite function call */
	if (!strncmp(name, "para", PART_META_INFO_NAMELEN) || !strncmp(name, "misc", PART_META_INFO_NAMELEN))
		part_suffix = NULL;
	else
		part_suffix = get_suffix();

	if ((int)strlen(name) - 2 >= 0) {
		last_char[0] = name[strlen(name) - 2];
		last_char[1] = name[strlen(name) - 1];
	} else {
		memset(last_char, 0, sizeof(last_char));
	}
	if (part_suffix != NULL) {
		if (!(part_suffix[0] == last_char[0] && part_suffix[1] == last_char[1])) {
			snprintf(alt_name, PART_META_INFO_NAMELEN + BOOTCTRL_SUFFIX_MAXLEN, "%s%s", name, part_suffix);
			check_alt_name = 1;
		}
	}
#endif
	for (i = 0; i < PART_MAX_COUNT; i++) {
		if (!g_partition_all[i].info)
			continue;
		if (!strncmp(name, (const char *)g_partition_all[i].info->name, PART_META_INFO_NAMELEN)) {
			pal_log_info(PART_COMMON_TAG"[%s]find %s index %d\n", __FUNCTION__, name, i);
			return i;
		}
#ifdef MTK_AB_OTA_UPDATER
		if (check_alt_name == 1 && !strncmp(alt_name, (const char *)g_partition_all[i].info->name, PART_META_INFO_NAMELEN)) {
			pal_log_info(PART_COMMON_TAG"[%s]find %s(add suffix for %s) index %d\n", __FUNCTION__, alt_name, name, i);
			return i;
		}
#endif
	}
	return -1;
}

static int partition_map_search(const char *name)
{
	int i, ret = -1;
	char last_char[2];
	char *new_name;
	int loops = sizeof(g_part_name_map) / sizeof(struct part_name_map);

	if (name == NULL)
		return ret;

	new_name = (char *)strdup(name);
	if (new_name == NULL)
		return ret;

	if ((int)strlen(name) - 2 >= 0) {
		last_char[0] = name[strlen(name) - 2];
		last_char[1] = name[strlen(name) - 1];
	} else {
		memset(last_char, 0, sizeof(last_char));
	}

	for (i = 0; i < loops; i++) {
		if (!g_part_name_map[i].fb_name[0])
			break;
		if (!strncmp(name, g_part_name_map[i].r_name, PART_META_INFO_NAMELEN)) {
			ret = i;
			break;
		}
		if ((last_char[1] == 'a' || last_char[1] == 'b') && last_char[0] == '_') {	// AB partition
			new_name[strlen(name) - 2] = 0;
		}
		if (last_char[1] <= '9' || last_char[1] >= '0') {	// xxx_1 or xxx1 partition
			if (last_char[0] == '_') { // ends with _[1-3]
				new_name[strlen(name) - 2] = 0;
			} else {	// ends with [1-3] without _ such as tee1 and tee2
				new_name[strlen(name) - 1] = 0;
			}
		}
		if (!strncmp(new_name, g_part_name_map[i].r_name, PART_META_INFO_NAMELEN)) {
			pal_log_info(PART_COMMON_TAG"map partition %s(from %s) with %s\n", new_name, name, g_part_name_map[i].r_name);
			ret = i;
			break;
		}
	}
	free(new_name);
	return ret;
}

unsigned int partition_get_region(int index)
{
	if (index < 0 || index >= PART_MAX_COUNT)
		return -1;

	if (!g_partition_all[index].nr_sects)
		return -1;

	return g_partition_all[index].part_id;
}

int partition_get_type(int index, char **p_type)
{
	int i;

	if (index < 0 || index >= PART_MAX_COUNT)
		return -1;

	if (p_type == NULL)
		return -1;

	if (!g_partition_all[index].nr_sects)
		return -1;

	if (!g_partition_all[index].info)
		return -1;

	i = partition_map_search((const char*)g_partition_all[index].info->name);
	if (i < 0)
		return -1;
	*p_type = g_part_name_map[i].partition_type;
	return 0;
}


u64 partition_get_offset(int index)
{
	part_dev_t *dev = mt_part_get_device();
	if (!dev) {
		pal_log_err(PART_COMMON_TAG"%s, err(no dev)\n", __func__);
		return -1;
	}

	if (index < 0 || index >= PART_MAX_COUNT)
		return -1;

	if (!g_partition_all[index].nr_sects)
		return -1;

	return (u64)g_partition_all[index].start_sect * dev->blkdev->blksz;
}

u64 partition_get_size(int index)
{
	part_dev_t *dev = mt_part_get_device();
	if (!dev) {
		pal_log_err(PART_COMMON_TAG"%s, err(no dev)\n", __func__);
		return -1;
	}

	if (index < 0 || index >= PART_MAX_COUNT)
		return -1;

	if (!g_partition_all[index].nr_sects)
		return -1;

	return (u64)g_partition_all[index].nr_sects * dev->blkdev->blksz;
}

int partition_get_name(int index, char **p_name)
{
	if (index < 0 || index >= PART_MAX_COUNT)
		return -1;

	if (p_name == NULL)
		return -1;

	if (!g_partition_all[index].nr_sects)
		return -1;

	if (!g_partition_all[index].info)
		return -1;

	*p_name = (char *) g_partition_all[index].info->name;
	return 0;
}

u8* partition_get_uuid_by_name(const char *part_name)
{
	int index;

	index = partition_get_index_by_name(part_name);
	if (index == -1)
		return NULL;

	if (index < 0 || index >= PART_MAX_COUNT)
		return NULL;

	if (!g_partition_all[index].nr_sects)
		return NULL;

	return g_partition_all[index].info->uuid;
}

int partition_get_active_bit_by_name(const char *part_name)
{
	int index;

	index = partition_get_index_by_name(part_name);
	if (index == -1)
		return -1;
	return (g_partition_all[index].part_attr & PART_ATTR_LEGACY_BIOS_BOOTABLE);
}

int partition_support_erase(const char *part_name)
{
	int index;
	index = partition_get_index_by_name(part_name);
	if (index < 0 || index >= PART_MAX_COUNT)
		return PART_NOT_EXIST;
	if (!g_partition_all[index].nr_sects)
		return -1;

	if (!g_partition_all[index].info)
		return -1;

	index = partition_map_search((const char*)g_partition_all[index].info->name);
	if (index < 0)
		return -1;
	return g_part_name_map[index].is_support_erase;
}

int partition_support_flash(const char *part_name)
{
	int index;
	index = partition_get_index_by_name(part_name);
	if (index < 0 || index >= PART_MAX_COUNT)
		return PART_NOT_EXIST;

	if (!g_partition_all[index].nr_sects)
		return -1;

	if (!g_partition_all[index].info)
		return -1;

	index = partition_map_search((const char*)g_partition_all[index].info->name);
	if (index < 0)
		return -1;
	return g_part_name_map[index].is_support_dl;
}

int gpt_partition_table_update(const char *arg, void *data, unsigned sz)
{
	int err;
	/* Currently always write pgpt and sgpt to avoid misjudge of efi signature after update gpt power-loss  */
	err = write_primary_gpt(data, sz);
	if (err) {
		pal_log_err(PART_COMMON_TAG"[GPT_Update]write write_primary_gpt, err(%d)\n", err);
		return err;
	}
	err = write_secondary_gpt(data, sz);
	if (err) {
		pal_log_err(PART_COMMON_TAG"[GPT_Update]write write_secondary_gpt, err(%d)\n", err);
		return err;
	}

	return 0;
}

/**/
/*fastboot*/
/**/
unsigned int write_partition(unsigned size, unsigned char *partition)
{
	return 0;
}

#define CMDLINE_BUF_SIZE    (256)
#define BOOT_DEV_BUF_SIZE   (64)
static void partition_commandline_bootdevice(void)
{
	char cmdline_buf[CMDLINE_BUF_SIZE];
	char bootdev_buf[BOOT_DEV_BUF_SIZE];
	char *boot_device = cmdline_buf;
	int ret = 0;
	int remain = CMDLINE_BUF_SIZE;

	ret = snprintf(cmdline_buf, CMDLINE_BUF_SIZE, "androidboot.boot_devices=bootdevice");
	if (ret < 0) {
		pal_log_err(PART_COMMON_TAG"append bootdevice to command line fail\n");
		return;
	}
	remain -= ret;
#ifdef MSDC0_BASE
	ret = snprintf(bootdev_buf, BOOT_DEV_BUF_SIZE, ",%08x.mmc", MSDC0_BASE);
	if (ret < 0) {
		pal_log_err(PART_COMMON_TAG"append MSDC0_BASE(0x%08x) to command line fail\n", MSDC0_BASE);
		return;
	}
	boot_device = strncat(boot_device, bootdev_buf, remain);
	if (boot_device == NULL) {
		pal_log_err(PART_COMMON_TAG"cannot cat bootdevice %s to cmdline buffer\n", bootdev_buf);
		return;
	}
#endif
	pal_log_err(PART_COMMON_TAG"boot_device str is %s.\n", boot_device);
	cmdline_append(cmdline_buf);
}

int part_init(part_dev_t *dev)
{
	part_t *part_ptr;
	part_t *part_pgpt, *part_sgpt;
	int offset = 0;
	struct part_meta_info *info;
	pal_log_err(PART_COMMON_TAG"[partition init]\n");
#ifdef MTK_AB_OTA_UPDATER
	int predef_part_num = 3; // preloader, preloader_a, preloader_b
#else
	int predef_part_num = 1; // preloader
#endif
	part_ptr = (part_t *) calloc(PART_MAX_COUNT + predef_part_num + 2/*pgpt and spgt*/, sizeof(part_t));
	if (!part_ptr)
		return -1;

	g_partition_all = part_ptr;
	partition = part_ptr + predef_part_num + 1 /*pgpt*/;
	partition->part_id = dev->blkdev->part_user;
	read_gpt(partition);
	// add pgpt in global partition arrary
	part_pgpt = part_ptr + predef_part_num;
	part_pgpt->start_sect = 0x0;
	part_pgpt->nr_sects = partition_get_offset(predef_part_num + 1)/ dev->blkdev->blksz;
	part_pgpt->part_id = dev->blkdev->part_user;
	info = malloc(sizeof(*info));
	if (!info) {
		pal_log_err(PART_COMMON_TAG"[PART_INIT]lacking of memory\n");
		return -1;
	}
	part_pgpt->info = info;
	snprintf((char*)part_pgpt->info->name, strlen("pgpt")+1, "%s", "pgpt");
	// add sgpt in global partition arrary
	offset = get_entry_count() + predef_part_num + 1;
	part_sgpt = part_ptr + offset;
	part_sgpt->start_sect = (partition_get_offset(offset -1) + partition_get_size(offset-1))/ dev->blkdev->blksz;
	part_sgpt->nr_sects = last_lba(dev->blkdev->part_user) - part_sgpt->start_sect + 1;
	part_sgpt->part_id = dev->blkdev->part_user;
	info = malloc(sizeof(*info));
	if (!info) {
		pal_log_err(PART_COMMON_TAG"[PART_INIT]lacking of memory\n");
		return -1;
	}
	part_sgpt->info = info;
	snprintf((char*)part_sgpt->info->name, strlen("sgpt")+1, "%s", "sgpt");

	// set pre-defined partition entry for active preloader
	g_partition_all[0].start_sect = 0x0;
	g_partition_all[0].nr_sects = PART_PRELOADER_SIZE;
#if (defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT))
	if (dev->blkdev->type == BOOTDEV_SDMMC)
		mmc_get_boot_part((u32 *)&g_partition_all[0].part_id); // get active boot partition
#ifdef MTK_UFS_SUPPORT
	else if (dev->blkdev->type == BOOTDEV_UFS)
		ufs_lk_get_active_boot_part((u32 *)&g_partition_all[0].part_id);
#endif
#endif
	g_partition_all[0].info = malloc(sizeof(struct part_meta_info));
	if (g_partition_all[0].info)
		snprintf((char*)g_partition_all[0].info->name, strlen("preloader")+1, "%s", "preloader");

#ifdef MTK_AB_OTA_UPDATER
	// set pre-defined partition entry for preloader_a
	memcpy(&g_partition_all[1], &g_partition_all[0], sizeof(part_t));
#if defined(MTK_EMMC_SUPPORT)
	if (dev->blkdev->type == BOOTDEV_SDMMC)
		g_partition_all[1].part_id = EMMC_PART_BOOT1;
#endif
#if defined(MTK_UFS_SUPPORT)
	if (dev->blkdev->type == BOOTDEV_UFS)
		g_partition_all[1].part_id = UFS_LU_BOOT1;
#endif
	g_partition_all[1].info = malloc(sizeof(struct part_meta_info));
	if (g_partition_all[1].info)
		snprintf((char*)g_partition_all[1].info->name, strlen("preloader_a")+1, "%s", "preloader_a");
	// set pre-defined partition entry for preloader_b
	memcpy(&g_partition_all[2], &g_partition_all[0], sizeof(part_t));
#if defined(MTK_EMMC_SUPPORT)
	if (dev->blkdev->type == BOOTDEV_SDMMC)
		g_partition_all[2].part_id = EMMC_PART_BOOT2;
#endif
#if defined(MTK_UFS_SUPPORT)
	if (dev->blkdev->type == BOOTDEV_UFS)
		g_partition_all[2].part_id = UFS_LU_BOOT2;
#endif
	g_partition_all[2].info = malloc(sizeof(struct part_meta_info));
	if (g_partition_all[2].info)
		snprintf((char*)g_partition_all[2].info->name, strlen("preloader_b")+1, "%s", "preloader_b");
#endif

	partition_commandline_bootdevice();
	return 0;
}

void mt_part_dump(void)
{
	int i = 0;

	part_dev_t *dev = mt_part_get_device();
	if (!dev) {
		pal_log_err(PART_COMMON_TAG"%s, err(no dev)\n", __func__);
		return;
	}
	pal_log_info(PART_COMMON_TAG"Part Info.(1blk=%luB):\n", dev->blkdev->blksz);

	for (i = 0; i < real_partition_count; i++) {
		pal_log_info("[0x%016llx-0x%016llx] (%.8ld blocks): \"%s\"\n",
			(u64)g_partition_all[i].start_sect * dev->blkdev->blksz,
			(u64)(g_partition_all[i].start_sect + g_partition_all[i].nr_sects) * dev->blkdev->blksz - 1,
			g_partition_all[i].nr_sects, (g_partition_all[i].info) ? (char *)g_partition_all[i].info->name : "unknown");
	}
	pal_log_info("\n");
}

#endif // #ifdef MTK_PARTITION_COMMON

/* name: should be translated to official name first, used for backward compatible */
int partition_get_index_by_name(const char *part_name)
{
	int index = -1;
	int found = 0;
	const PART_TRANS_TBL_ENTRY *entry = g_part_name_trans_tbl;

	if (part_name == NULL)
		return index;

	/* if name matches one of the official names, use translation table */
	for (; 0 != strcmp(entry->official_name, "NULL"); entry++) {
		if (0 == strcmp(part_name, entry->official_name)) {
			found = 1;
			break;
		}
	}

	if (found) {
		index = partition_get_index(entry->official_name);
		if (index != -1)
			return index;

		/* try alt_name1 */
		index = partition_get_index(entry->alt_name1);
		if (index != -1)
			return index;

		/* try alt_name2 */
		index = partition_get_index(entry->alt_name2);
		if (index != -1)
			return index;

		/* try alt_name3 */
		index = partition_get_index(entry->alt_name3);
		if (index != -1)
			return index;
	} else {
		/* don't do name translation if name is not found in table */
		index = partition_get_index(part_name);
		if (index != -1)
			return index;
	}
	return index;
}

u64 partition_get_size_by_name(const char *part_name)
{
	int index;

	index = partition_get_index_by_name(part_name);
	return partition_get_size(index);
}

u64 partition_get_offset_by_name(const char *part_name)
{
	int index;

	index = partition_get_index_by_name(part_name);
	return partition_get_offset(index);
}


char* partition_get_real_name(const char *part_name)
{
	int index;
	char *p_name = NULL;
	index = partition_get_index_by_name(part_name);
	if (index == -1)
		return NULL;
	partition_get_name(index, &p_name);
	return p_name;
}

int partition_exists(const char *part_name)
{
	if (partition_get_index_by_name(part_name) == -1)
		return PART_NOT_EXIST;
	else
		return PART_OK;
}

int partition_get_region_by_name(const char *part_name)
{
	int index;

	index = partition_get_index_by_name(part_name);
	return partition_get_region(index);
}

int partition_get_type_by_name(const char *part_name, char **p_type)
{
	int index;

	index = partition_get_index_by_name(part_name);
	return partition_get_type(index, p_type);
}

