/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
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

#include <pal_log.h>
#include <pal_typedefs.h>
#include <platform/verified_boot.h>
#include <stdlib.h>
#include <string.h>
#include <verified_boot_common.h>
#include <dev/mrdump.h>

/* mrdump flow in dconfig */
#if MTK_MRDUMP_SUPPORT == 2

#define DCONFIG_PART "boot_para"
#define DCONFIG_1STIMG_NAME "dconfig"
#define DCONFIG_HEADER_SIZE 512
#define DCONFIG_PLENV_SIZE 1024

#ifdef MTK_SECURITY_SW_SUPPORT
static uint8_t socid_chip[SOC_ID_LEN] = {0};
#endif

#define PLENV_SIG_SIZE 8
#define PLENV_MRDUMP_STR "mrdump_enable=yes"
#define PLENV_MRDUMP_LEN 18

extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);

static int mrdump_get_socid_cert(void)
{
	uint8_t *dconfig_hdr = NULL;
	uint8_t *plenv = NULL;
	int len = 0;

#ifdef MTK_SECURITY_SW_SUPPORT
	uint32_t sec_ret = sec_img_auth_init(DCONFIG_PART, DCONFIG_1STIMG_NAME,
					     GET_SOCID_FROM_CERT2);
	if (sec_ret) {
		pal_log_err("%s: dconfig image auth init failed (0x%x)\n", __func__, sec_ret);
		return MRDUMP_SEC_IMG_AUTH_INIT_ERROR;
	}
#endif

	dconfig_hdr = malloc(DCONFIG_HEADER_SIZE + DCONFIG_PLENV_SIZE);
	if (dconfig_hdr == NULL) {
		pal_log_err("%s: not enough memory\n", __func__);
		return MRDUMP_DCONFIG_MALLOC_ERROR;
	}

	len = mboot_common_load_part(DCONFIG_PART, DCONFIG_1STIMG_NAME,
				     (unsigned long)dconfig_hdr);
	if (len <= 0) {
		pal_log_err("%s: partition_read failed, return value %d\n", __func__, len);
		free(dconfig_hdr);
		return MRDUMP_MBOOT_LOAD_PART_ERROR;
	}

#ifdef MTK_SECURITY_SW_SUPPORT
	sec_ret = sec_img_auth(dconfig_hdr, len);
	if (sec_ret) {
		pal_log_err("%s: dconfig image verify failed (0x%x)\n", __func__, sec_ret);
		free(dconfig_hdr);
		return MRDUMP_DCONFIG_IMG_VERIFY_ERROR;
	}

	uint8_t socid_cert[SOC_ID_LEN] = {0};
	sec_ret = get_socid_cert(socid_cert, SOC_ID_LEN);
	if (sec_ret) {
		pal_log_err("%s: unable to get socid from certed image (0x%x)\n", __func__, sec_ret);
		free(dconfig_hdr);
		return MRDUMP_DCONFIG_SOCID_CERT_ERROR;
	}

	if (strncmp((char *)socid_chip, (char *)socid_cert, SOC_ID_LEN) != 0) {
		pal_log_err("%s: socid mismatched\n", __func__);
		free(dconfig_hdr);
		return MRDUMP_DCNFIG_SOCID_MISMATCH;
	}
#endif

	char *mrdump_enable_str = (char *)dconfig_hdr + DCONFIG_HEADER_SIZE + PLENV_SIG_SIZE;
	if (strncmp(mrdump_enable_str, PLENV_MRDUMP_STR, PLENV_MRDUMP_LEN) != 0) {
		pal_log_err("%s: not a valid mrdump enabled image\n", __func__);
		free(dconfig_hdr);
		return MRDUMP_NOT_VALID_IMG;
	}

	pal_log_info("mrdump_get_socid_cert done.\n");
	free(dconfig_hdr);
	return MRDUMP_SUCCESS_ENABLE;
}

int mrdump_check_enable(void)
{
#ifndef MTK_SECURITY_SW_SUPPORT
	return 0;
#else
	uint32_t sec_ret = get_socid_chip(socid_chip, SOC_ID_LEN);

	if (sec_ret) {
		pal_log_err("%s: unable to get socid from chip (0x%x)\n", __func__, sec_ret);
		return MRDUMP_NO_SOCID_FROM_CHIP;
	}

	return (mrdump_get_socid_cert());
#endif
}

/* mrdump flow not in dconfig */
#elif MTK_MRDUMP_SUPPORT == 1

int mrdump_check_enable(void)
{
	return MRDUMP_ALWAYS_ENABLE;
}

#else

#error Unknown MTK_MRDUMP_SUPPORT value

#endif
