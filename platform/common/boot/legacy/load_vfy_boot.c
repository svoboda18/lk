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
#include <pal_typedefs.h>
#include <pal_assert.h>
#include <load_vfy_boot.h>
#include <boot_info.h>
#include <bootimg.h>
#ifdef MTK_GPT_SCHEME_SUPPORT
#include <platform/partition.h>
#else
#include <mt_partition.h>
#endif
#include <verified_boot_common.h>
#include <platform/verified_boot.h>
#include <target.h>
#include <mt_boot.h>
#include <part_interface.h>

#define TMPBUF_SIZE        200

#define CMDLINE_ROOT_RAM           "root=/dev/ram"
#define CMDLINE_ROOT_SYSTEM_COMMON "skip_initramfs rootwait ro init=/init"
#define CMDLINE_ROOT_SYSTEM_DM_OFF "root=PARTUUID=%s"
#define CMDLINE_ROOT_SYSTEM_DM_ON  "root=/dev/dm-0 dm=\
\"system none ro,0 1 android-verity PARTUUID=%s \""

#ifdef MTK_DM_VERITY_OFF
#define CMDLINE_ROOT_SYSTEM CMDLINE_ROOT_SYSTEM_DM_OFF
#else
#define CMDLINE_ROOT_SYSTEM CMDLINE_ROOT_SYSTEM_DM_ON
#endif

static void boot_post_processing(uint32_t bootimg_type)
{
	uint32_t hashtree_error_mode = 0;
#ifdef SYSTEM_AS_ROOT
	char vboot_cmdline[TMPBUF_SIZE] = {0};
	u8 *part_uuid = NULL;
	int lock_state = 0;

#ifdef MTK_SECURITY_SW_SUPPORT
	sec_query_device_lock(&lock_state);
#endif

	if (bootimg_type == BOOTIMG_TYPE_BOOT) {
		cmdline_append(CMDLINE_ROOT_SYSTEM_COMMON);
		part_uuid = partition_get_uuid_by_name("system");
		if (part_uuid != NULL) {
			if (DEVICE_STATE_LOCKED == lock_state) {
				snprintf(vboot_cmdline, TMPBUF_SIZE,
						CMDLINE_ROOT_SYSTEM, part_uuid);
			} else {
				snprintf(vboot_cmdline, TMPBUF_SIZE,
						CMDLINE_ROOT_SYSTEM_DM_OFF, part_uuid);
			}
			cmdline_append(vboot_cmdline);
		}
	} else
		cmdline_append(CMDLINE_ROOT_RAM);
#else
	PAL_UNUSED_PARAM(bootimg_type);
	cmdline_append(CMDLINE_ROOT_RAM);
#endif

	dm_verity_handler(hashtree_error_mode);

	return;
}

int load_vfy_boot(uint32_t bootimg_type, uint32_t addr)
{
	int ret = 0;
	char *part_name = get_bootimg_partition_name(bootimg_type);
	unsigned int kimg_load_addr = 0;

	if (NULL == part_name)
		return -1;

	if (load_bootimg_hdr(bootimg_type) != 0)
		return -2;


	kimg_load_addr = (uint32_t)target_get_scratch_address();

	switch (bootimg_type) {
		case BOOTIMG_TYPE_RECOVERY:
#ifndef RECOVERY_AS_BOOT
			ret = mboot_android_load_recoveryimg_hdr(part_name, addr);
			if (ret < 0)
				msg_header_error("Android Recovery Image");

			ret = mboot_android_load_recoveryimg(part_name, kimg_load_addr + get_page_sz());
			load_bootinfo_bootimg(kimg_load_addr);
			prepare_kernel_dtb();
			if (ret < 0)
				msg_img_error("Android Recovery Image");
			else
				set_bootimg_loaded(kimg_load_addr);

			break;
#endif
		case BOOTIMG_TYPE_BOOT:
			ret = mboot_android_load_bootimg_hdr(part_name, addr);
			if (ret < 0)
				msg_header_error("Android Boot Image");

			ret = mboot_android_load_bootimg(part_name, kimg_load_addr + get_page_sz());
			load_bootinfo_bootimg(kimg_load_addr);
			prepare_kernel_dtb();
			if (ret < 0)
				msg_img_error("Android Boot Image");
			else
				set_bootimg_loaded(kimg_load_addr);

			break;
		default:
			ret = -3;
			break;
	}

	boot_post_processing(bootimg_type);

#if defined(MTK_BUILD_DEFAULT_UNLOCK) && defined(MTK_SEC_FASTBOOT_UNLOCK_SUPPORT)
	/* unlock device */
	if (sec_set_device_lock(0) != 0)
		ret = -4;
#endif

	return ret;
}

