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
#include <assert.h>
#include <platform/sec_status.h>
#include <platform/mt_typedefs.h>
#include <platform/sec_export.h>
#include <platform/verified_boot.h>
#include <profiling.h>
#include <part_status.h>
#include <oemkey.h>
#include <pal_log.h>
#if defined(MTK_AB_OTA_UPDATER)
#include <bootctrl.h>
#endif
#define MOD "SBOOT"
#define VBOOT_PART_NAME_MAX_SZ (32)
#define RECOVERY_SEC_POLICY_IDX (0)
#define BOOT_SEC_POLICY_IDX     (1)
#define DTBO_SEC_POLICY_IDX     (2)
#define LOGO_SEC_POLICY_IDX     (3)
char *g_sec_policy_idx_table[] = {
	SBOOT_PART_RECOVERY_NAME,
	SBOOT_PART_BOOT_NAME,
	SBOOT_PART_DTBO_NAME,
	SBOOT_PART_LOGO_NAME
};
extern void mtk_wdt_restart(void);
extern unsigned char g_sec_oemkey[OEM_PUBK_SZ];
uint32_t get_policy_entry_idx(char *part_name)
{
	uint32_t idx = 0;
	uint32_t sec_policy_idx_table_sz =
		sizeof(g_sec_policy_idx_table) / sizeof(char *);
	for (idx = 0; idx < sec_policy_idx_table_sz; idx++) {
		if (0 == strncmp( part_name, g_sec_policy_idx_table[idx],
			strlen( g_sec_policy_idx_table[idx] )))
			break;
	}
	/* idx will be sec_policy_idx_table_sz if it's not found in table */
	return idx;
}
uint32_t get_vfy_policy(uint32_t policy_entry_idx)
{
	uint32_t img_auth_required = 1;
	int lock_state = DEVICE_STATE_LOCKED;
	int ret = sec_query_device_lock(&lock_state);
	switch (policy_entry_idx) {
		case RECOVERY_SEC_POLICY_IDX:
		case BOOT_SEC_POLICY_IDX:
		case DTBO_SEC_POLICY_IDX:
		case LOGO_SEC_POLICY_IDX:
		default:
			//sw security is not supported any longer
			//so lk will always use default policy
			if ( seclib_sec_boot_enabled( TRUE ) == TRUE && lock_state == DEVICE_STATE_LOCKED )
				img_auth_required = 1;
			else
				img_auth_required = 0;
	}
	return img_auth_required;
}
static unsigned int get_vfy_policy_by_name(char *part_name, char *img_name)
{
	uint32_t policy_entry_idx = 0;
	unsigned int img_auth_required = 1;
	UNUSED(img_name); /* img_name is not used, it's here for
					   interface consistency */
	policy_entry_idx = get_policy_entry_idx(part_name);
	return get_vfy_policy(policy_entry_idx);
}
int img_auth_stor(char *part_name, char *img_name)
{
	int ret = B_OK;
	unsigned int img_auth_required = 0;
	const char *ab_suffix = NULL;
	char ab_part_name[VBOOT_PART_NAME_MAX_SZ] = {0};
	unsigned int part_name_sz = 0;
	unsigned int ab_suffix_name_sz = 0;
	UNUSED(img_name); /* img_name is not used, it's here for
					   interface consistency */
	part_name_sz = strlen(part_name);
#if defined(MTK_AB_OTA_UPDATER)
	ab_suffix = get_suffix();
	if (ab_suffix != NULL)
		ab_suffix_name_sz = strlen(ab_suffix);
	/* partition name size check */
	if ((part_name_sz + ab_suffix_name_sz) > VBOOT_PART_NAME_MAX_SZ - 1)
		return INVALID_NAME_SIZE;
	/* do name translation here if AB is enabled */
	memcpy(ab_part_name, part_name, part_name_sz);
	memcpy(ab_part_name + part_name_sz, ab_suffix, ab_suffix_name_sz);
	ab_part_name[part_name_sz + ab_suffix_name_sz] = '\0';
#else
	/* although keep ab_part_name empty should work for
	 * partition_exists API, we use original partition
	 * name just in case */
	memcpy(ab_part_name, part_name, part_name_sz);
	ab_part_name[part_name_sz] = '\0';
#endif /* MTK_AB_OTA_UPDATER */
	PROFILING_START("img_auth_stor");
	seclib_image_buf_init();
	img_auth_required = get_vfy_policy_by_name(part_name, NULL);
	pal_log_err("[%s] %s img_auth_required( %d )\n", MOD, part_name, img_auth_required);
	if (img_auth_required) {
		if (PART_OK == partition_exists(ab_part_name)) {
			ret = seclib_image_check(ab_part_name, TRUE);
			if (ret)
				goto end;
		} else {
			ret = seclib_image_check(part_name, TRUE);
			if (ret)
				goto end;
		}
	}
end:
	seclib_image_buf_free();
	PROFILING_END();
	if (ret) {
		dprintf(CRITICAL, "[%s] Fail (0x%x)\n", MOD, ret);
		return ret;
	}
	return B_OK;
}
int sec_boot_check(int try_lock)
{
	int ret = B_OK;
	int sec_policy_ret = B_OK;
	sec_policy_ret = sec_policy_backup();
	if (sec_policy_ret) {
		dprintf(CRITICAL, "[%s] sec policy backup fail (0x%x)\n", MOD, sec_policy_ret);
		ret = sec_policy_ret;
		return ret;
	}
	if (try_lock) {
		sec_policy_ret = change_sec_policy(SEC_LOCK);
		if (sec_policy_ret) {
			dprintf(CRITICAL, "[%s] sec_boot_check -- fail to change sec policy\n", MOD);
			goto end;
		}
	}
	/* verify boot or recovery image according to current boot mode */
#if defined(MTK_AB_OTA_UPDATER)
	/* recovery partition does not exist when AB system is enabled */
	ret = img_auth_stor(SBOOT_PART_BOOT_NAME, NULL);
	if (B_OK != ret)
		goto end;
#else
	if (TRUE == is_recovery_mode()) {
		ret = img_auth_stor(SBOOT_PART_RECOVERY_NAME, NULL);
		if (B_OK != ret)
			goto end;
	} else {
		ret = img_auth_stor(SBOOT_PART_BOOT_NAME, NULL);
		if (B_OK != ret)
			goto end;
	}
#endif
	/* set valid public key with cert_set_pubk, which is passed into TEE */
	rev_buf(g_sec_oemkey, OEM_PUBK_SZ);
	ret = cert_set_pubk(g_sec_oemkey, OEM_PUBK_SZ);
	rev_buf(g_sec_oemkey, OEM_PUBK_SZ);
end:
	if (ret)
		dprintf(INFO, "[%s] sboot fail (0x%x)\n", MOD, ret);
	sec_policy_ret = sec_policy_restore();
	if (sec_policy_ret) {
		/* if security policy restore fails, return value will be overriden by
		 * its error code, if there's error in verification process,
		 * we can only observe them from log.
		 */
		dprintf(INFO, "[%s] sboot fail(sec_policy) (0x%x)\n", MOD, sec_policy_ret);
		ret = sec_policy_ret;
	}
	return ret;
}

