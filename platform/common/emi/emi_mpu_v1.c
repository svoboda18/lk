/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2017. All rights reserved.
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
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/

#include <debug.h>
#include <plat_debug_interface.h>
#include <emi/emi_mpu_v1.h>

#ifndef MTK_SMC_ID_MGMT
#define MTK_SIP_KERNEL_EMIMPU_SET	0x82000262
#define MTK_SIP_KERNEL_EMIMPU_CLEAR	0x82000263
#endif

#define DBG_EMI(x...) dprintf(INFO, x)
#ifdef MTK_SMC_ID_MGMT
#define emi_mpu_smc_set(start, end, apc) \
    mt_secure_call(MTK_SIP_KERNEL_EMIMPU_SET, start, end, apc, 0)
#define emi_mpu_smc_clear(region) \
    mt_secure_call(MTK_SIP_KERNEL_EMIMPU_CLEAR, region, 0, 0, 0)
#else
#define emi_mpu_smc_set(start, end, apc) \
    mt_secure_call(MTK_SIP_KERNEL_EMIMPU_SET, start, end, apc)
#define emi_mpu_smc_clear(region) \
    mt_secure_call(MTK_SIP_KERNEL_EMIMPU_CLEAR, region, 0, 0)
#endif
int emi_mpu_set_protection(struct emi_region_info_t *region_info)
{
	unsigned int start, end;
	int i;

	if (region_info->region >= EMI_MPU_REGION_NUM) {
		DBG_EMI("EMI MPU can not support region %u\n",
			region_info->region);
		return -1;
	}

	start = (unsigned int)(region_info->start >> EMI_MPU_ALIGN_BITS) |
		(region_info->region << 24);

	DBG_EMI("LK emi_mpu_set_protection start:%llx end=%llx region=%u ",
		region_info->start, region_info->end, region_info->region);

	for (i = EMI_MPU_DGROUP_NUM - 1; i >= 0; i--) {
		end = (unsigned int)(region_info->end >> EMI_MPU_ALIGN_BITS) |
			(i << 24);
		emi_mpu_smc_set(start, end, region_info->apc[i]);
		DBG_EMI("apc%d=%x ", i, region_info->apc[i]);
	}

	DBG_EMI("\n");

	return 0;
}

int emi_mpu_clear_protection(struct emi_region_info_t *region_info)
{
	if (region_info->region >= EMI_MPU_REGION_NUM) {
		DBG_EMI("EMI MPU can not support region %u\n",
			region_info->region);
		return -1;
	}

	emi_mpu_smc_clear(region_info->region);

	return 0;
}

