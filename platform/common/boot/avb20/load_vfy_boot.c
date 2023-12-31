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
#include <pal_log.h>
#include <platform/verified_boot.h>
#include <platform/boot_mode.h>
#include <platform/mtk_wdt.h>

#include <bootimg.h>
#include <load_vfy_boot.h>
#include <verified_boot_error.h>
#include <verified_boot_common.h>
#include <avb_slot_verify.h>
#include <avb_ops.h>
#include <string.h>
#include <vboot_state.h>
#include <avb_cmdline.h>
#include <libfdt.h>
#include <target.h>
#include <avb_user_verification.h>
#include <bootargs.h>
#include <preload_partition.h>
#include <mt_boot.h>
#include <boot_info.h>
#include <avb_persist.h>
#include <dm_verity_status.h>
#include <boot_opt.h>
#include <avb_RoT.h>

#define KB (1024)
#define MB (1024 * KB)
#define AVB_HEAP_SZ (100 * MB)
#define TMPBUF_SIZE (200)

#define CMDLINE_ROOT_RAM           "root=/dev/ram"
#define CMDLINE_ROOT_SYSTEM_COMMON "skip_initramfs ro rootwait init=/init"

extern BOOT_ARGUMENT *g_boot_arg;
extern AvbOps ops;

unsigned long get_timer(unsigned long base);

void *avb_heap;
uint32_t avb_heap_sz;

static const char *boot_partitions[] = {"boot", NULL};
static const char *recovery_partitions[] = {"recovery", NULL};

static uint32_t boot_partitions_sz = sizeof(boot_partitions) / sizeof(char *) - 1;
static uint32_t recovery_partitions_sz = sizeof(recovery_partitions) / sizeof(char *) - 1;

/* please keep avb_cmdline_attrs and avb_dt_attrs sync since we
 * use them for cmdline attrs to dt attrs conversion */
static const char *avb_cmdline_attrs[] = {
	"androidboot.vbmeta.hash_alg",
	"androidboot.vbmeta.size",
	"androidboot.vbmeta.digest",
	NULL
};

static const char *avb_dt_attrs[] = {
	"vbmeta.hash_alg",
	"vbmeta.size",
	"vbmeta.digest",
	NULL
};

uint32_t __attribute__((weak)) collect_rot_info(AvbSlotVerifyData *slot_data)
{
	return 0;
}

static uint32_t preload_partitions(uint32_t bootimg_type)
{
	uint32_t ret = 0;
	uint32_t i;
	/* please add load address to load_addrs[] for new partition */
	uint32_t load_addrs[] = {0};
	uint32_t load_addrs_sz = sizeof(load_addrs) / sizeof(uint32_t);

	if (bootimg_type == BOOTIMG_TYPE_BOOT && load_addrs_sz != boot_partitions_sz)
		return 0x1;
	else if (bootimg_type == BOOTIMG_TYPE_RECOVERY && load_addrs_sz != recovery_partitions_sz)
		return 0x2;

	load_addrs[0] = (uint32_t)target_get_scratch_address();

	i = 0;

	switch (bootimg_type) {
	case BOOTIMG_TYPE_RECOVERY:
#ifndef RECOVERY_AS_BOOT
		while (recovery_partitions[i] != NULL) {
			pal_log_err("preloading %s\n", recovery_partitions[i]);
			ret = preload_partition(recovery_partitions[i], load_addrs[i]);
			if (ret)
				return ret;
			i++;
		}
		break;
#endif
	case BOOTIMG_TYPE_BOOT:
		while (boot_partitions[i] != NULL) {
			pal_log_err("preloading %s\n", boot_partitions[i]);
			ret = preload_partition(boot_partitions[i], load_addrs[i]);
			if (ret)
				return ret;
			i++;
		}
		break;
	default:
		break;
	}

	return ret;
}

static uint32_t record_avb_version(AvbSlotVerifyData *slot_data)
{
	uint32_t ret = 0;

#ifdef MTK_SECURITY_ANTI_ROLLBACK
	uint32_t i = 0;
	uint64_t min_ver = 0;

	if (slot_data == NULL) {
		ret = AVB_IO_RESULT_ERROR_IO;
		goto end;
	}

	min_ver = slot_data->rollback_indexes[0];
	if (min_ver == AVB_VER_INITIAL_VALUE) {
		ret = AVB_IO_RESULT_ERROR_OOM;
		goto end;
	}

	for (i = 0; i < AVB_MAX_NUMBER_OF_ROLLBACK_INDEX_LOCATIONS; i++) {
		/* recovery otp group is not handled here */
		if (i == RECOVERY_ROLLBACK_INDEX)
			continue;
		pal_log_info("ver(%d) = %llu\n", i, slot_data->rollback_indexes[i]);
		if (slot_data->rollback_indexes[i] != AVB_VER_INITIAL_VALUE)
			if (slot_data->rollback_indexes[i] < min_ver)
				min_ver = slot_data->rollback_indexes[i];
	}

/* MTK_OTP_FRAMEWORK_V2 is used to create AVB and recovery otp field.
 * Recovery otp field is used to record recovery image version.
 * This option is designed for solving the problem that device are
 * not able to boot into recovery mode if recovery image version is
 * the minimum version in original non-secure group.
 */
#ifdef MTK_OTP_FRAMEWORK_V2
	/* write recovery image version to recovery otp field */
	if (slot_data->rollback_indexes[RECOVERY_ROLLBACK_INDEX] != AVB_VER_INITIAL_VALUE) {
		ret = set_avb_otp_ver(RECOVERY_GROUP,
			(uint32_t)slot_data->rollback_indexes[RECOVERY_ROLLBACK_INDEX]);
		if (ret)
			goto end;
	}
#else
	/* update min_ver if the recovery image version is the minimum */
	if (slot_data->rollback_indexes[RECOVERY_ROLLBACK_INDEX] != AVB_VER_INITIAL_VALUE) {
		if (slot_data->rollback_indexes[RECOVERY_ROLLBACK_INDEX] < min_ver)
			min_ver = slot_data->rollback_indexes[RECOVERY_ROLLBACK_INDEX];
	}
#endif

	pal_log_err("[avb] min_ver = %llu\n", min_ver);

	/* update AVB otp field*/
	ret = set_avb_otp_ver(AVB_GROUP, (uint32_t)min_ver);

end:
#endif
	return ret;
}

static uint32_t boot_authentication(uint32_t bootimg_type)
{
#ifdef MTK_SECURITY_SW_SUPPORT
	uint32_t policy_entry_idx = 0;
	uint32_t img_auth_required = 0;

	switch (bootimg_type) {
	case BOOTIMG_TYPE_RECOVERY:
#ifndef RECOVERY_AS_BOOT
		policy_entry_idx = get_policy_entry_idx(recovery_partitions[0]);
		break;
#endif
	case BOOTIMG_TYPE_BOOT:
		policy_entry_idx = get_policy_entry_idx(boot_partitions[0]);
		break;
	default:
		pal_log_err("[avb] invalid boot image type\n");
		return 1;
	}

	img_auth_required = get_vfy_policy(policy_entry_idx);
	pal_log_err("[avb] img_auth_required = %d\n", img_auth_required);

	return img_auth_required;
#else
	pal_log_err("[avb] img_auth_required = 0\n");
	return 0;
#endif
}

static uint32_t avb_cmdline_postprocessing(char *cmdline, void *fdt)
{
	uint32_t ret = 0;
	uint32_t i = 0;
	int nodeoffset;
	int fdt_ret = 0;
	char fdt_value[MAX_VALUE_SZ + 1] = {0};

	/* extract avb parameters from cmdline */
	for (i = 0; ; i++) {
		if (avb_cmdline_attrs[i] == NULL)
			break;
		ret = avb_extract_from_cmdline(cmdline,
					       strlen(cmdline),
					       avb_cmdline_attrs[i]);
		if (ret) {
			pal_log_err("[avb] extract %s fails\n", avb_cmdline_attrs[i]);
			return -1;
		}
	}

	/* create /firmware/android if it does not exist  */
	nodeoffset = fdt_path_offset(fdt, "/firmware/android");
	if (nodeoffset < 0) {
		nodeoffset = fdt_path_offset(fdt, "/firmware");
		if (nodeoffset < 0) {
			/* Add subnode "firmware" in root */
			nodeoffset = fdt_add_subnode(fdt, 0, "firmware");
			if (nodeoffset < 0) {
				pal_log_err("Warning: can't add firmware node in device tree\n");
				return -1;
			}
		}

		/* Add subnode "android" in "/firmware" */
		nodeoffset = fdt_add_subnode(fdt, nodeoffset, "android");
		if (nodeoffset < 0) {
			pal_log_err("Warning: can't add firmware/android node in device tree\n");
			return -1;
		}
	}

	/* set cmdline attributes to device tree */
	for (i = 0; ; i++) {
		if (avb_dt_attrs[i] == NULL)
			break;
		ret = avb_get_cmdline(avb_cmdline_attrs[i], fdt_value, MAX_VALUE_SZ);
		if (ret == STATUS_OK) {
			fdt_ret = fdt_setprop_string(fdt, nodeoffset, avb_dt_attrs[i], fdt_value);
			if (fdt_ret) {
				pal_log_err("Error: can't set property in device tree\n");
				return -1;
			}
		}

		/* we allow the case that entry is not found */
		if (ret == ERR_AVB_CMDLINE_ENTRY_NOT_FOUND)
			ret = STATUS_OK;
	}

	return ret;
}

static uint32_t boot_post_processing(AvbOps *ops, uint32_t bootimg_type,
				     AvbSlotVerifyData *slot_data)
{
	uint32_t ret = 0;
	uint32_t i = 0;
	bool out_verification_enabled = true;
#ifndef PRELOAD_PARTITION_SUPPORT
	uint32_t boot_load_addr = 0;
#endif
	char *part_name = get_bootimg_partition_name(bootimg_type);


	if (part_name == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	if (slot_data == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	ret = collect_rot_info(slot_data);
	if (ret)
		return AVB_IO_RESULT_ERROR_IO;

#ifndef PRELOAD_PARTITION_SUPPORT
	boot_load_addr = (uint32_t)target_get_scratch_address();

	/* relocate boot image from slot data to its target buffer */
	for (i = 0; i < slot_data->num_loaded_partitions; i++) {
		if (!strcmp(part_name,
			    slot_data->loaded_partitions[i].partition_name)) {
			memcpy((void *)boot_load_addr,
			       (void *)((uint8_t *)slot_data->loaded_partitions[i].data),
			       slot_data->loaded_partitions[i].data_size);
			break;
		}
	}
#endif
	load_bootinfo_bootimg((void *)boot_load_addr);
	prepare_kernel_dtb();

	if (i == slot_data->num_loaded_partitions) {
		ret = AVB_SLOT_VERIFY_RESULT_ERROR_INVALID_ARGUMENT;
		goto end;
	}

#ifdef SYSTEM_AS_ROOT
	if (bootimg_type == BOOTIMG_TYPE_BOOT) {
		cmdline_append(CMDLINE_ROOT_SYSTEM_COMMON);
		/* root file system is already in avb slot data when
		 * BOARD_BUILD_SYSTEM_ROOT_IMAGE is true, so we don't
		 * have to handle it again here.
		 */
	} else
		cmdline_append(CMDLINE_ROOT_RAM);
#else
	cmdline_append(CMDLINE_ROOT_RAM);
#endif
	if(!avb_user_verification_get(ops, "", &out_verification_enabled)) {
		pal_log_err("[avb] Fail to get verification state\n");
		out_verification_enabled = true;
	}

	if (out_verification_enabled) {
		ret = avb_cmdline_postprocessing(slot_data->cmdline, get_kernel_fdt());
		if (ret)
			goto end;
	}

	pal_log_err("[avb] cmdline = %s\n", slot_data->cmdline);
	cmdline_append(slot_data->cmdline);

	ret = write_persist_value(ops, PERSIST_PART_NAME);
	if (ret)
		goto end;

	set_bootimg_loaded(boot_load_addr);

end:
	return ret;
}

static uint32_t handle_vboot_state(uint32_t bootimg_type)
{
	uint32_t ret = STATUS_OK;
	int32_t vboot_state_ret = 0;

	/* device should not boot if any error occurs
	 * in this function
	 */

	/* be careful that error code should not be overriden by
	 * return value of the following error handling functions.
	 */
	vboot_state_ret = print_boot_state();
	if (vboot_state_ret)
		return ERR_VB_STATE_PRINT_FAIL;

	if (bootimg_type == BOOTIMG_TYPE_RECOVERY)
		vboot_state_ret = show_warning(recovery_partitions[0]);
	else if (bootimg_type == BOOTIMG_TYPE_BOOT)
		vboot_state_ret = show_warning(boot_partitions[0]);
	else
		return ERR_VB_STATE_SHOW_WARNING_FAIL;

	if (vboot_state_ret)
		return ERR_VB_STATE_SHOW_WARNING_FAIL;

	vboot_state_ret = set_boot_state_to_cmdline();
	if (vboot_state_ret)
		return ERR_VB_STATE_SET_CMDLINE_FAIL;

	return ret;
}

int load_vfy_boot(uint32_t bootimg_type, uint32_t addr)
{
	int ret = STATUS_OK;
	uint32_t img_vfy_time = 0;
	AvbSlotVerifyResult avb_ret = AVB_SLOT_VERIFY_RESULT_OK;
	AvbSlotVerifyData *slot_data = NULL;
	AvbSlotVerifyFlags avb_flag = AVB_SLOT_VERIFY_FLAGS_NONE;
	uint32_t lock_state = LKS_DEFAULT;
	uint32_t dm_status = 0;
	AvbHashtreeErrorMode hashtree_error_mode = AVB_HASHTREE_ERROR_MODE_RESTART_AND_INVALIDATE;

	img_vfy_time = get_timer(0);

	g_boot_state = BOOT_STATE_RED;

	/* heap initialization for avb */
	avb_heap_sz = AVB_HEAP_SZ;
	pal_log_debug("[avb] avb heap alloc size 0x%x\n", avb_heap_sz);
	avb_heap = (void *)(uint32_t)mblock_reserve_ext(&g_boot_arg->mblock_info,
			avb_heap_sz,
			4 * KB,
			0xc0000000,
			0,
			"avb");
	if (avb_heap == 0) {
		pal_log_err("[avb] avb heap alloc fails\n");
		avb_heap_sz = 0;
		return -1;
	} else
		pal_log_debug("[avb] avb heap alloc 0x%x\n", (uint32_t)avb_heap);

#ifdef MTK_SEC_FASTBOOT_UNLOCK_SUPPORT
#if defined(MTK_DM_VERITY_OFF) || defined(MTK_BUILD_DEFAULT_UNLOCK) || !defined(MTK_SECURITY_SW_SUPPORT)
	/* This feature is for test purpose only.
	 * we unlock device without wiping userdata, which should not
	 * happen for MP product. We do this because after userdata
	 * has been wiped, Android will fail to mount userdata and reboot
	 * to recovery to format userdata, and then reboot. If we always
	 * wipe userdata in boot process, Android will never get a properly
	 * formatted userdata.
	 */
#ifdef MTK_SECURITY_SW_SUPPORT
	/* unlock device */
	if (sec_set_device_lock(0) != 0) {
		ret = ERR_AVB_UNLOCK_DEVICE_FAILED;
		goto end;
	}
#endif

	/* disable verification */
	if (avb_user_verification_set(&ops, "", 0) != true) {
		ret = ERR_AVB_SET_VERIFICATION_FAILED;
		goto end;
	}
#endif
#endif

	if (boot_authentication(bootimg_type) == 0)
		avb_flag = AVB_SLOT_VERIFY_FLAGS_ALLOW_VERIFICATION_ERROR;

#ifdef PRELOAD_PARTITION_SUPPORT
	if (preload_partitions(bootimg_type)) {
		avb_ret = AVB_SLOT_VERIFY_RESULT_ERROR_IO;
		goto end;
	}
#endif

	get_dm_verity_status(&dm_status);
	if (dm_status)
		avb_flag |= AVB_SLOT_VERIFY_FLAGS_RESTART_CAUSED_BY_HASHTREE_CORRUPTION;

	get_hash_tree_error_mode((uint32_t *)&hashtree_error_mode);

	ret = init_persist_value(&ops, PERSIST_PART_NAME, PERSIST_VALUE_OFFSET);
	if (ret) {
		pal_log_err("init_persist_value ret = 0x%x\n", ret);
		goto end;
	}

	switch (bootimg_type) {
	case BOOTIMG_TYPE_RECOVERY:
#ifndef RECOVERY_AS_BOOT
		avb_ret = avb_slot_verify(&ops,
				      recovery_partitions,
				      "",
				      avb_flag,
				      hashtree_error_mode,
				      &slot_data);

		if (avb_flag & AVB_SLOT_VERIFY_FLAGS_ALLOW_VERIFICATION_ERROR)
			avb_ret = AVB_SLOT_VERIFY_RESULT_OK;

		if (avb_ret != AVB_SLOT_VERIFY_RESULT_OK)
			goto end;

		break;
#endif
	case BOOTIMG_TYPE_BOOT:
		avb_ret = avb_slot_verify(&ops,
				      boot_partitions,
				      "",
				      avb_flag,
				      hashtree_error_mode,
				      &slot_data);

		if (avb_flag & AVB_SLOT_VERIFY_FLAGS_ALLOW_VERIFICATION_ERROR)
			avb_ret = AVB_SLOT_VERIFY_RESULT_OK;

		if (avb_ret != AVB_SLOT_VERIFY_RESULT_OK)
			goto end;

		break;

	default:
		avb_ret = AVB_SLOT_VERIFY_RESULT_ERROR_INVALID_ARGUMENT;
		goto end;
	}

	if (avb_ret == AVB_SLOT_VERIFY_RESULT_OK) {
		ret = boot_post_processing(&ops, bootimg_type, slot_data);
		if (ret)
			goto end;

		g_boot_state = BOOT_STATE_GREEN;

#ifdef MTK_SECURITY_YELLOW_STATE_SUPPORT
		if (vb_custom_key_exist())
			g_boot_state = BOOT_STATE_YELLOW;
#endif
		if (boot_authentication(bootimg_type) != 0 &&
			g_boot_state == BOOT_STATE_GREEN) {
			ret = record_avb_version(slot_data);
			if (ret != AVB_IO_RESULT_OK) {
				pal_log_err("update avb otp version fail.\n");
				ret = AVB_IO_RESULT_OK;
			}
		}
	}

end:
	pal_log_err("[avb] boot/recovery vfy time = %d ms\n",
		    (unsigned int)get_timer(img_vfy_time));

	if (slot_data != NULL)
		hashtree_error_mode = slot_data->resolved_hashtree_error_mode;

	/* After this function call, memory is returned to lk.
	 * Please avoid using avb_heap after this function call
	 */
	mblock_create(&g_boot_arg->mblock_info,
		      &g_boot_arg->orig_dram_info,
		      (uint64_t)(uint32_t)avb_heap & 0xffffffff,
		      (uint64_t)avb_heap_sz & 0xffffffff);

	pal_log_err("[avb] avb_ret = %d\n", avb_ret);
	pal_log_err("[avb] ret = %d\n", ret);

	/* if device state is "unlocked," override
	 * boot state with "ORANGE."
	 */
#ifdef MTK_SECURITY_SW_SUPPORT
	ret = get_lock_state(&lock_state);
	if (ret == 0 && lock_state == LKS_UNLOCK)
		g_boot_state = BOOT_STATE_ORANGE;
#endif

	dm_verity_handler((uint32_t)hashtree_error_mode);

	ret = (int)handle_vboot_state(bootimg_type);
	if (ret != STATUS_OK)
		mtk_arch_reset(1);

	if (avb_ret != AVB_SLOT_VERIFY_RESULT_OK)
		ret = ERR_AVB_VERIFICAITON_FAILED;

	return ret;
}

