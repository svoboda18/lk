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

#include <printf.h>
#include <platform/mt_typedefs.h>
#include <platform/mtk_key.h>
#include <platform/boot_mode.h>
#include <platform/mt_pmic.h>
#include <platform/mt_gpio.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/sync_write.h>
#include <platform/upmu_common.h>
#include <target/cust_key.h>

extern int pmic_detect_powerkey(void);
extern int pmic_detect_homekey(void);
extern kal_uint16 pmic_get_register_value(PMU_FLAGS_LIST_ENUM flagname);
extern kal_uint16 pmic_set_register_value(PMU_FLAGS_LIST_ENUM flagname,kal_uint32 val);

void set_kpd_pmic_mode(void)
{
	return;
}

void disable_PMIC_kpd_clock(void)
{
	return;
}

void enable_PMIC_kpd_clock(void)
{
	return;
}

BOOL mtk_detect_key(unsigned short key) /* key: HW keycode */
{
#ifdef MACH_FPGA
	return FALSE;
#else

	dprintf(ALWAYS, "mtk detect key function key = %d\n", key);

	unsigned short idx, bit, din;

	if (key >= KPD_NUM_KEYS)
		return FALSE;
#if 0
	if (key % 9 == 8)
		key = 8;
#endif
	if (key == MTK_PMIC_PWR_KEY) {
		/* Power key */
		if (1 == pmic_detect_powerkey()) {
			//dbg_print ("power key is pressed\n");
			return TRUE;
		}
		return FALSE;
	}

#ifdef MTK_PMIC_RST_KEY
	if (key == MTK_PMIC_RST_KEY) {
		dprintf(INFO, "mtk detect key function pmic_detect_homekey MTK_PMIC_RST_KEY = %d\n", MTK_PMIC_RST_KEY);
		if (1 == pmic_detect_homekey()) {
			dprintf(ALWAYS, "mtk detect key function pmic_detect_homekey pressed\n");
			return TRUE;
		}
		return FALSE;
	}
#endif

	idx = key / 16;
	bit = key % 16;

	din = DRV_Reg16(KP_MEM1 + (idx << 2)) & (1U << bit);
	if (!din) {
		dprintf(ALWAYS, "key %d is pressed\n", key);
		return TRUE;
	}
	return FALSE;
#endif
}

BOOL mtk_detect_pmic_just_rst(void)
{
	kal_uint32 just_rst = 0;

	dprintf(ALWAYS, "detecting pmic just reset\n");

#if defined(PMIC_CHIP_MT6353)
	just_rst = pmic_get_register_value(PMIC_JUST_PWRKEY_RST);
#else
	just_rst = pmic_get_register_value(MT6351_PMIC_JUST_PWRKEY_RST);
#endif
	if (just_rst) {
		dprintf(ALWAYS, "Just recover from a reset\n");
#if defined(PMIC_CHIP_MT6353)
		pmic_set_register_value(PMIC_CLR_JUST_RST, 0x01);
		udelay(200);
		pmic_set_register_value(PMIC_CLR_JUST_RST, 0x0);
#else
		pmic_set_register_value(MT6351_PMIC_CLR_JUST_RST, 0x01);
		udelay(200);
		pmic_set_register_value(MT6351_PMIC_CLR_JUST_RST, 0x0);
#endif
		return TRUE;
	}
	return FALSE;
}
