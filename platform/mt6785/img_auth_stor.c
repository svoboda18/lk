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
#include <platform/sec_status.h>
#include <platform/sec_export.h>
#include <platform/sec_policy.h>
#include <platform/verified_boot.h>
#include <profiling.h>
#include <part_status.h>
#include <verified_boot_common.h>
#include <pal_log.h>
#include <part_interface.h>
#include <pal_typedefs.h>

#define MOD                             "SBC"
#define SEC_UNUSED(x)   (void)x

extern void mtk_wdt_restart(void);

int img_auth_stor(char *part_name, char *img_name, uint32_t feature_mask)
{
	int ret = B_OK;
	unsigned int policy_entry_idx = 0;
	unsigned int img_auth_required = 0;

	/* partition does not exist, so we don't do verification */
	if (PART_OK != partition_exists(part_name)) {
		dprintf(CRITICAL, "[%s] %s does not exist, bypass\n", MOD, part_name);
		return B_OK;
	}

	seclib_image_buf_init();

	PROFILING_START("img_auth_stor");

	policy_entry_idx = get_policy_entry_idx(part_name);
	img_auth_required = get_vfy_policy(policy_entry_idx);

	if (img_auth_required) {
		mtk_wdt_restart();
		ret = sec_img_auth_init(part_name, img_name, 0);
		if (B_OK != ret) {
			pal_log_err("Verified boot is enabled.\n");
			pal_log_err("Please download %s image with corret signature or disable verified boot.\n", img_name);
			goto fail;
		}

#ifdef MTK_SECURITY_ANTI_ROLLBACK
		if (feature_mask & SEC_FEATURE_MASK_ANTIROLLBACK) {
			ret = sec_rollback_check(1);
			if (B_OK != ret)
				goto fail;
		}
#else
		SEC_UNUSED(feature_mask);
#endif
		mtk_wdt_restart();
		ret = sec_img_auth_stor(part_name, img_name);
		if (B_OK != ret)
			goto fail;
	}

	PROFILING_END();

	seclib_image_buf_free();

	return B_OK;

fail:
	dprintf(CRITICAL, "[%s] Fail (0x%x)\n", MOD, ret);
	return ret;
}

