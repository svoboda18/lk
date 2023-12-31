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
#include <platform/mt_pmic.h>
#include <platform/mtk_wdt.h>
#include <platform/mt_gpt.h>

#define EFUSE_PMIC_CONTROL_ENABLE   1

/**************************************************************
 * WDT
 **************************************************************/
void efuse_wdt_restart(void)
{
    mtk_wdt_restart();
}

/****************************************************
 * Fsource
 * return 0 : success
 ****************************************************/
U32 efuse_fsource_set(void)
{
	U32 ret_val = 0;

#if EFUSE_PMIC_CONTROL_ENABLE

	/* 1.8V */
	ret_val |= pmic_config_interface((kal_uint32)(PMIC_RG_VEFUSE_VOSEL_ADDR),
            (kal_uint32)(0xC),
			(kal_uint32)(PMIC_RG_VEFUSE_VOSEL_MASK),
			(kal_uint32)(PMIC_RG_VEFUSE_VOSEL_SHIFT)
			);

    /* +0mV */
	ret_val |= pmic_config_interface((kal_uint32)(PMIC_RG_VEFUSE_VOCAL_ADDR),
            (kal_uint32)(0x0),
			(kal_uint32)(PMIC_RG_VEFUSE_VOCAL_MASK),
			(kal_uint32)(PMIC_RG_VEFUSE_VOCAL_SHIFT)
			);

	/* Fsource(VEFUSE) enabled */
	ret_val |= pmic_config_interface((kal_uint32)(PMIC_RG_LDO_VEFUSE_EN_ADDR),
			(kal_uint32)(0x1),
			(kal_uint32)(PMIC_RG_LDO_VEFUSE_EN_MASK),
			(kal_uint32)(PMIC_RG_LDO_VEFUSE_EN_SHIFT)
			);

    mdelay(10);

#endif

	return ret_val;
}

U32 efuse_fsource_close(void)
{
	U32 ret_val = 0;

#if EFUSE_PMIC_CONTROL_ENABLE

	/* Fsource(VEFUSE) disable */
	ret_val |= pmic_config_interface((kal_uint32)(PMIC_RG_LDO_VEFUSE_EN_ADDR),
			(kal_uint32)(0x0),
			(kal_uint32)(PMIC_RG_LDO_VEFUSE_EN_MASK),
			(kal_uint32)(PMIC_RG_LDO_VEFUSE_EN_SHIFT)
			);

    mdelay(10);

#endif

	return ret_val;
}

U32 efuse_fsource_is_enabled(void)
{
	U32 regVal = 0;

#if EFUSE_PMIC_CONTROL_ENABLE

    /*  Check Fsource(VEFUSE) Status */
	pmic_read_interface((kal_uint32)(PMIC_RG_LDO_VEFUSE_EN_ADDR),
			&regVal,
			(kal_uint32)(PMIC_RG_LDO_VEFUSE_EN_MASK),
			(kal_uint32)(PMIC_RG_LDO_VEFUSE_EN_SHIFT)
			);

    /* return 1 : fsource enabled
     * return 0 : fsource disabled */

#endif

	return regVal;
}

