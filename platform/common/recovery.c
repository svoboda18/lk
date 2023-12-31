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

#include <debug.h>
#include <err.h>
#include <reg.h>
#include <stdlib.h>
#include <string.h>
#include <recovery.h>
#include <platform/boot_mode.h>
#include <part_interface.h>
#include <platform/errno.h>
//#include <platform/partition.h>

#ifdef MTK_GPT_SCHEME_SUPPORT
#include <partition.h>
#else
#include <mt_partition.h>
#endif

#if !defined(MTK_EMMC_SUPPORT) && !defined(MTK_UFS_SUPPORT)
#include "nand_device_list.h"

#ifndef MTK_COMBO_NAND_SUPPORT
extern flashdev_info devinfo;
#endif
#endif

extern int mboot_recovery_load_misc(unsigned char *misc_addr, unsigned int size);

#define MODULE_NAME "[RECOVERY]"
#define MISC_PARTITION "misc"

//#define LOG_VERBOSE

#ifdef LOG_VERBOSE
static void dump_data(const char *data, int len)
{
	int pos;
	for (pos = 0; pos < len; ) {
		dprintf(INFO, "%05x: %02x", pos, data[pos]);
		for (++pos; pos < len && (pos % 24) != 0; ++pos) {
			dprintf(INFO, " %02x", data[pos]);
		}
		dprintf(INFO, "\n");
	}
}
#endif

static int mboot_recovery_set_misc(uint32_t *misc_addr, uint32_t size)
{
	long len;
	uint32_t begin;

	dprintf(INFO,"[mboot_recovery_load_misc]: size is %u\n", size);
	dprintf(INFO,"[mboot_recovery_load_misc]: misc_addr is 0x%x\n",
		(uint32_t)misc_addr);

	if (partition_exists("misc") == PART_NOT_EXIST)
		return -ENOENT;

	begin = get_timer(0);

	len = partition_write("misc", 0, (uchar *)misc_addr, (size_t)size);
	if (len < 0)
		return -EIO;

	dprintf(INFO,"[%s] Set misc partition to 0x%08x (%d bytes in %lu ms)\n",
		MODULE_NAME, (uint32_t)misc_addr, size, get_timer(begin));

	return 0;
}

BOOL recovery_set_fastboot_cmd(void)
{
	struct misc_message misc_msg;
	struct misc_message *pmisc_msg = &misc_msg;
#if !defined(MTK_EMMC_SUPPORT) && !defined(MTK_UFS_SUPPORT)
#ifndef MTK_COMBO_NAND_SUPPORT
	const unsigned int size = (devinfo.pagesize) * MISC_PAGES;
#else
	const unsigned int size = mtk_nand_page_size() * MISC_PAGES;
#endif
#else
	const unsigned int size = 2048 * MISC_PAGES;
#endif
	unsigned char *pdata;
	int ret;

	pdata = (uchar*)malloc(sizeof(uchar)*size);
	if (!pdata) {
		return FALSE;
	}

	memset(misc_msg.command, '\0', strlen("boot-fastboot") + 1);
	strncpy(misc_msg.command, "boot-fastboot", strlen("boot-fastboot"));

#if !defined(MTK_EMMC_SUPPORT) && !defined(MTK_UFS_SUPPORT) // eMMC did not need 2048 byte offset
#ifndef MTK_COMBO_NAND_SUPPORT
	memcpy(&pdata[(devinfo.pagesize) * MISC_COMMAND_PAGE], pmisc_msg, sizeof(misc_msg));
#else
	memcpy(&pdata[(mtk_nand_page_size()) * MISC_COMMAND_PAGE], pmisc_msg, sizeof(misc_msg));
#endif
#else
	memcpy(pdata, pmisc_msg, sizeof(misc_msg));
#endif

	ret = mboot_recovery_set_misc(pdata, size);
	if (ret < 0) {
		free(pdata);
		return FALSE;
	}

	free(pdata);
	return TRUE;
}

BOOL recovery_check_command_trigger(void)
{
	struct misc_message misc_msg;
	struct misc_message *pmisc_msg = &misc_msg;
#if !defined(MTK_EMMC_SUPPORT) && !defined(MTK_UFS_SUPPORT)
#ifndef MTK_COMBO_NAND_SUPPORT
	const unsigned int size = (devinfo.pagesize) * MISC_PAGES;
#else
    const unsigned int size = mtk_nand_page_size() * MISC_PAGES;
#endif
#else
	const unsigned int size = 2048 * MISC_PAGES;
#endif
	unsigned char *pdata;
	int ret;

	pdata = (uchar*)malloc(sizeof(uchar)*size);
	if (!pdata) {
		return FALSE;
	}

	ret = mboot_recovery_load_misc(pdata, size);

	if (ret < 0) {
		free(pdata);
		return FALSE;
	}

#ifdef LOG_VERBOSE
	dprintf(INFO, "\n--- get_bootloader_message ---\n");
	dump_data(pdata, size);
	dprintf(INFO, "\n");
#endif

#if !defined(MTK_EMMC_SUPPORT) && !defined(MTK_UFS_SUPPORT) // eMMC did not need 2048 byte offset
#ifndef MTK_COMBO_NAND_SUPPORT
	memcpy(pmisc_msg, &pdata[(devinfo.pagesize) * MISC_COMMAND_PAGE], sizeof(misc_msg));
#else
    memcpy(pmisc_msg, &pdata[(mtk_nand_page_size()) * MISC_COMMAND_PAGE], sizeof(misc_msg));
#endif
#else
	memcpy(pmisc_msg, pdata, sizeof(misc_msg));
#endif

#ifdef LOG_VERBOSE
	dprintf(INFO, "Boot command: %.*s\n", sizeof(misc_msg.command), misc_msg.command);
	dprintf(INFO, "Boot status: %.*s\n", sizeof(misc_msg.status), misc_msg.status);
	dprintf(INFO, "Boot message\n\"%.20s\"\n", misc_msg.recovery);
#endif

	free(pdata);

	if (strcmp(misc_msg.command, "boot-recovery")==0) {
		g_boot_mode = RECOVERY_BOOT;
		return TRUE;
	}

	if (strcmp(misc_msg.command, "boot-fastboot")==0) {
		g_boot_mode = RECOVERY_BOOT;
		return TRUE;
	}

	return FALSE;
}

BOOL check_ota_result(void)
{
    struct bootloader_message_ab ab_metadata;
    int ret = -1, result = 0;
    ssize_t result_offset;

    result_offset = sizeof(ab_metadata);

    ret = partition_read(MISC_PARTITION, (off_t)result_offset, (u8 *)&result, (size_t)sizeof(int));
    if (ret < 0) {
        dprintf(CRITICAL, "[LK] check_ota_result partition_read failed, ret: 0x%x\n", ret);
        return FALSE;
    }

        dprintf(CRITICAL, "[LK] check_ota_result = %d\n", result);
    if(result) {
        dprintf(CRITICAL, "[LK] ota-pass\n");
        return TRUE;
    } else {
        dprintf(CRITICAL, "[LK] ota-fail\n");
        return FALSE;
    }
}

BOOL clear_ota_result(void)
{
    struct bootloader_message_ab ab_metadata;
    int ret = -1, result = 0;
    ssize_t result_offset;

    result_offset = sizeof(ab_metadata);

    ret = partition_write(MISC_PARTITION, (off_t)result_offset, (u8 *)&result, (size_t)sizeof(int));
    if (ret < 0) {
        dprintf(CRITICAL, "[LK] clear_ota_result partition_write failed, ret: 0x%x\n", ret);
        return FALSE;
    }

    return TRUE;
}

#if 0
BOOL recovery_check_key_trigger(void)
{
	//wait
	ulong begin = get_timer(0);
	dprintf(INFO, "\n%s Check recovery boot\n",MODULE_NAME);
	dprintf(INFO, "%s Wait 50ms for special keys\n",MODULE_NAME);

	if (mtk_detect_pmic_just_rst()) {
		return false;
	}

#ifdef MT65XX_RECOVERY_KEY
	while (get_timer(begin)<50) {
		if (mtk_detect_key(MT65XX_RECOVERY_KEY)) {
			dprintf(CRITICAL, "%s Detect cal key\n",MODULE_NAME);
			dprintf(CRITICAL, "%s Enable recovery mode\n",MODULE_NAME);
			g_boot_mode = RECOVERY_BOOT;
			//video_printf("%s : detect recovery mode !\n",MODULE_NAME);
			return TRUE;
		}
	}
#endif

	return FALSE;
}

/**********************************************************
 * Routine: recovery_detection
 *
 * Description: check recovery mode
 *
 * Notice: the recovery bits of RTC PDN1 are set as 0x10 only if
 *          (1) user trigger factory reset
 *
 **********************************************************/
BOOL recovery_detection(void)
{
	if (Check_RTC_Recovery_Mode()) {
		g_boot_mode = RECOVERY_BOOT;
		return TRUE;
	}

#if 0
	if (recovery_check_key_trigger()) {
		return TRUE;
	}
#endif

	return recovery_check_command_trigger();

}
#endif

