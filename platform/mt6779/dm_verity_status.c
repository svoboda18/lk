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

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <dm_verity_status.h>

#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <pal_typedefs.h>
#include <pal_log.h>

#define MISC_LOCK_KEY_MAGIC (0x0000ad98)

#define BOOT_MISC2_IDX      (2)
#define RSA_CON_BIT(idx)    (0x1 << idx)

#define BOOT_MISC2          (SECURITY_AO_BASE + 0x088)
#define MISC_LOCK_KEY       (SECURITY_AO_BASE + 0x100)
#define RST_CON             (SECURITY_AO_BASE + 0x108)

#define BOOT_MISC2_DM_VERITY_ERR (0x1 << 0)

#define UNIT_TEST (0)

void get_dm_verity_status(uint32_t *status)
{
	uint32_t dm_verity_state_reg = DM_VERITY_STATUS_OK;
	uint32_t seccfg_ret = 0;
	uint32_t dm_verity_state_seccfg = DM_VERITY_STATUS_OK;

	if (status == NULL)
		return;

	*status = DM_VERITY_STATUS_OK;

#ifdef MTK_SECURITY_SW_SUPPORT

	if (DRV_Reg32(BOOT_MISC2) & BOOT_MISC2_DM_VERITY_ERR) {
		dm_verity_state_reg = DM_VERITY_GENERAL_ERROR;
		*status = DM_VERITY_GENERAL_ERROR;
	}
	PAL_UNUSED_PARAM(dm_verity_state_reg);
	PAL_UNUSED_PARAM(seccfg_ret);
	PAL_UNUSED_PARAM(dm_verity_state_seccfg);

#ifndef AVB_PERSIST_VALUE_SUPPORT
	seccfg_ret = seccfg_get_dm_verity_state(&dm_verity_state_seccfg);
	if (seccfg_ret)
		dm_verity_state_seccfg = DM_VERITY_GENERAL_ERROR;

	if (dm_verity_state_reg != DM_VERITY_STATUS_OK) {
		seccfg_ret = seccfg_set_dm_verity_state(DM_VERITY_GENERAL_ERROR);
		if (seccfg_ret) {
			pal_log_err("[%s] seccfg_set_dm_verity_state fails(0x%x)\n",
					__func__, seccfg_ret);
		}
	} else if (dm_verity_state_seccfg != DM_VERITY_STATUS_OK)
		*status = DM_VERITY_GENERAL_ERROR;

#if UNIT_TEST
	/* this part should be implemented in kernel, it's here
	 * for UT purpose
	 */
	DRV_WriteReg32(MISC_LOCK_KEY, MISC_LOCK_KEY_MAGIC);
	DRV_WriteReg32(RST_CON, DRV_Reg32(RST_CON) |
			RSA_CON_BIT(BOOT_MISC2_IDX));
	DRV_WriteReg32(MISC_LOCK_KEY, 0);

	DRV_WriteReg32(BOOT_MISC2, DRV_Reg32(BOOT_MISC2) |
			BOOT_MISC2_DM_VERITY_ERR);
#endif
#endif
#endif
	return;
}

void clear_dm_verity_status(void)
{
#ifdef MTK_SECURITY_SW_SUPPORT
	uint32_t reg_val = 0;
	uint32_t seccfg_ret = 0;

	reg_val = DRV_Reg32(BOOT_MISC2);
	reg_val &= ~BOOT_MISC2_DM_VERITY_ERR;
	DRV_WriteReg32(BOOT_MISC2, reg_val);

	seccfg_ret = seccfg_set_dm_verity_state(DM_VERITY_STATUS_OK);
	if (seccfg_ret)
		pal_log_err("[%s] seccfg_get_dm_verity_state fails(0x%x)\n",
					__func__, seccfg_ret);
#endif
	return;
}

