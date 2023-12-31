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

#include <sys/types.h>
#include <stdint.h>
#include <platform/partition.h>
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>
#include <libfdt.h>
#include <platform/mt_gpt.h>
#include <platform/sec_export.h>
#include <debug.h>
#include "ccci_ld_md_core.h"
#include "ccci_ld_md_errno.h"
#include <assert.h>
#include <block_generic_interface.h>
#include <video.h>
#include <platform/mtk_wdt.h>
#include <verified_boot_common.h>
#include <platform/verified_boot.h>
#define MODULE_NAME "LK_LD_MD"

/* Security policy */
#ifdef MTK_SECURITY_SW_SUPPORT
static unsigned int policy_entry_idx;
static unsigned int img_auth_required;
static unsigned int verify_hash;
static unsigned int lte_sbc_en;
static unsigned int c2k_sbc_en;
static int time_md_auth;
static int time_md_auth_init;
static unsigned int sec_feature_mask;
static int g_fill_default_pubk_hash = 0;
#endif

void md_img_check_reminder(void)
{
#ifdef MTK_SECURITY_SW_SUPPORT
	video_set_cursor(video_get_rows() / 2, 0);
	video_printf("Reminder:\n");
	video_printf("MD authentication failed.\n");
	video_printf("Please download signed MD image(-verified.img)\n");
	video_printf("or disable verified boot.\n");
	mtk_wdt_restart();
	mdelay(5000);
	mtk_wdt_restart();
#endif
}

void ccci_ld_md_sec_init(void)
{
#ifdef MTK_SECURITY_SW_SUPPORT
	policy_entry_idx = 0;
	img_auth_required = 0;
	verify_hash = 0;
	lte_sbc_en = sec_get_ltemd_sbcen();
	c2k_sbc_en = sec_get_c2kmd_sbcen();
	sec_feature_mask = 0;
#endif
}

int ccci_ld_md_sec_ptr_hdr_verify(char *partition_name, char *image_name)
{
	int ret = 0;

	ALWAYS_LOG("ptr hdr verify:partition[%s], image_name[%s]\n", partition_name, image_name);

	/* Check sec policy to see if verification is required */
#ifdef MTK_SECURITY_SW_SUPPORT
	policy_entry_idx = get_policy_entry_idx((char *)partition_name);
	ALWAYS_LOG("policy_entry_idx = %d \n", policy_entry_idx);

	img_auth_required = get_vfy_policy(policy_entry_idx);
	ALWAYS_LOG("img_auth_required = %d \n", img_auth_required);

	/* do verify md cert-chain if need */
	if (img_auth_required) {
		time_md_auth_init = get_timer(0);
#ifdef MTK_SECURITY_ANTI_ROLLBACK
		sec_feature_mask |= SEC_FEATURE_MASK_ANTIROLLBACK;
#endif
		ret = sec_img_auth_init((char *)partition_name, (char *)image_name, sec_feature_mask);

		if (0 != ret) {
			ALWAYS_LOG("img cert-chain verification fail: 0x%x\n", ret);
			md_img_check_reminder();
			assert(0);
		}
#ifdef MTK_SECURITY_ANTI_ROLLBACK
		ret = sec_rollback_check(1);
		if (0 != ret) {
			ALWAYS_LOG("Verify %s image version fail!!!!\n", image_name);
			assert(0);
		}
#endif
		ALWAYS_LOG("Verify %s cert chain cost %d ms\n", image_name, (int)get_timer(time_md_auth_init));
	} else {
		if ((0x01 == lte_sbc_en || 0x01 == c2k_sbc_en) &&
				(0 == g_fill_default_pubk_hash)) {
			ret = sec_set_md_default_pubk_hash();
			g_fill_default_pubk_hash = 1;
			if (ret) {
				ALWAYS_LOG("fail to set md1rom default key hash (0x%x)\n", ret);
				ret = 0;
			}
		}
	}
#else
#ifdef MD_RMA_SUPPORT
	ret = sec_set_md_default_pubk_hash();
	if (0 != ret) {
		ALWAYS_LOG("fail to set md default key hash (0x%x)\n", ret);
		ret = 0;
	}
#endif
#endif

	if (ret == 0)
		return 0;
	else
		return -1;
}


void ccci_ld_md_sec_image_verify(char *partition_name, char *image_name, unsigned char *mem_addr, int size)
{
#ifdef MTK_SECURITY_SW_SUPPORT
	int ret;
#endif

	ALWAYS_LOG("image verify:partition[%s], image_name[%s], addr[%p], size[0x%x]\n",
			partition_name, image_name, mem_addr, size);

#ifdef MTK_SECURITY_SW_SUPPORT
	/* Verify image hash value if needed */
	if (img_auth_required) {
		/* Verify md image hash value */
		/* When SBC_EN is fused, bypass sec_img_auth */
		verify_hash = 1;

		if (!strncmp((char const *)image_name, "md1rom",7)) {
			if (0x01 == lte_sbc_en) {
				ALWAYS_LOG("LTE now, and lte sbc en = 0x1 \n");
				/* Bypass image hash verification at AP side*/
				verify_hash = 0;
			} else
				ALWAYS_LOG("LTE now, and lte sbc en != 0x1 \n");
		}
		if (!strncmp((char const *)image_name, "md3rom",7)) {
			if (0x01 == c2k_sbc_en) {
				ALWAYS_LOG("C2K now, and c2k sbc en = 0x1 \n");
				/* Bypass image hash verification at AP side*/
				verify_hash = 0;
			} else
				ALWAYS_LOG("C2K now, and c2k sbc en != 0x1 \n");
		}
		if (1 == verify_hash) {
			time_md_auth = get_timer(0);
			ret = sec_img_auth(mem_addr, size);
			if (0 != ret) {
				ALWAYS_LOG("image hash verification fail: %d\n", ret);
				assert(0);
			}
			ALWAYS_LOG("Image hash verification success: ret = %d\n", ret);
			ALWAYS_LOG("Verify %s image hash cost %d ms\n", image_name, (int)get_timer(time_md_auth));
		}
	}
#endif
}
