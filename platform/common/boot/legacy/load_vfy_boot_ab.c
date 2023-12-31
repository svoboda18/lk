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
#include <pal_log.h>
#include <load_vfy_boot.h>
#include <boot_info.h>
#include <bootimg.h>
#include <platform/partition.h>
#include <verified_boot_common.h>
#include <platform/verified_boot.h>
#include <target.h>
#include <mt_boot.h>
#include <part_interface.h>
#include <part_status.h>

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

/* we don't use macro SYSTEM_AS_ROOT here since it's enabled with
 * AB system by default.
 */
static void boot_post_processing(uint32_t bootimg_type)
{
	char rootfs_name[TMPBUF_SIZE] = {0};
	char vboot_cmdline[TMPBUF_SIZE] = {0};
	char vboot_cmdline_ab[TMPBUF_SIZE] = {0};
	uint8_t *part_uuid = NULL;
	int lock_state = 0;
	uint32_t hashtree_error_mode;

	sec_query_device_lock(&lock_state);
#ifdef SYSTEM_AS_ROOT
	if (bootimg_type == BOOTIMG_TYPE_BOOT) {
		cmdline_append(CMDLINE_ROOT_SYSTEM_COMMON);
		snprintf(rootfs_name, TMPBUF_SIZE, "system%s", get_suffix());
		part_uuid = partition_get_uuid_by_name(rootfs_name);
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
#endif
		cmdline_append(CMDLINE_ROOT_RAM);

	snprintf(vboot_cmdline_ab, TMPBUF_SIZE,
			"androidboot.slot_suffix=%s androidboot.slot=%s",
			get_suffix(), get_suffix() + 1);
	cmdline_append(vboot_cmdline_ab);

	/* this part may not be needed since it's already included in internal bootimg cmd */
#ifdef USER_BUILD
	cmdline_append("buildvariant=user");
#elif defined(USERDEBUG_BUILD)
	cmdline_append("buildvariant=userdebug");
#elif defined(ENG_BUILD)
	cmdline_append("buildvariant=eng");
#else
	cmdline_append("buildvariant=user");
#endif

	dm_verity_handler(hashtree_error_mode);

	return;
}

int load_vfy_boot(uint32_t bootimg_type, uint32_t addr)
{
	int ret = 0;
	char bootimg_name[16];
	unsigned int kimg_load_addr = 0;

	if (load_bootimg_hdr(bootimg_type) != 0)
		return -1;

	kimg_load_addr = (uint32_t)target_get_scratch_address();

	/* load bootimg with suffix: boot_a or boot_b */
#ifdef MTK_GPT_SCHEME_SUPPORT
	snprintf(bootimg_name, sizeof(bootimg_name), "boot%s", get_suffix());
#else
	snprintf(bootimg_name, sizeof(bootimg_name), "%s%s", PART_BOOTIMG,
			get_suffix());
#endif

	switch (bootimg_type) {
		case BOOTIMG_TYPE_RECOVERY:
		case BOOTIMG_TYPE_BOOT:
			ret = mboot_android_load_bootimg_hdr(bootimg_name, addr);
			if (ret < 0)
				msg_header_error("Android Boot Image");

			ret = mboot_android_load_bootimg(bootimg_name, kimg_load_addr + get_page_sz());
			load_bootinfo_bootimg(kimg_load_addr);
			prepare_kernel_dtb();
			if (ret < 0)
				msg_img_error("Android Boot Image");
			else
				set_bootimg_loaded(kimg_load_addr);

			break;
		default:
			ret = -2;
			break;
	}

	boot_post_processing(bootimg_type);

#if defined(MTK_BUILD_DEFAULT_UNLOCK) && defined(MTK_SEC_FASTBOOT_UNLOCK_SUPPORT)
	/* unlock device */
	if (sec_set_device_lock(0) != 0)
		ret = -3;
#endif

	return ret;
}

