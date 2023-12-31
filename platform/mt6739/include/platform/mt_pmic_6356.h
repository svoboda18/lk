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

#ifndef _MT_PMIC_LK_SW_MT6356_H_
#define _MT_PMIC_LK_SW_MT6356_H_

#include <platform/mt_typedefs.h>

//==============================================================================
// PMIC Define
//==============================================================================

#define PMIC6356_E1_CID_CODE    0x5610
#define PMIC6356_E2_CID_CODE    0x5620
#define PMIC6356_E3_CID_CODE    0x5630
#define PMIC6356_E4_CID_CODE    0x5640
#define PMIC6356_E5_CID_CODE    0x5650
#define PMIC6356_E6_CID_CODE    0x5660

//#define VOLTAGE_FULL_RANGE     1800
//#define ADC_PRECISE         32768 // 10 bits

typedef enum {
	CHARGER_UNKNOWN = 0,
	STANDARD_HOST,          // USB : 450mA
	CHARGING_HOST,
	NONSTANDARD_CHARGER,    // AC : 450mA~1A
	STANDARD_CHARGER,       // AC : ~1A
	APPLE_2_1A_CHARGER,     // 2.1A apple charger
	APPLE_1_0A_CHARGER,     // 1A apple charger
	APPLE_0_5A_CHARGER,     // 0.5A apple charger
} CHARGER_TYPE;

typedef enum {
	AUXADC_LIST_BATADC,
	AUXADC_LIST_VCDT,
	AUXADC_LIST_BATTEMP,
	AUXADC_LIST_BATID,
	AUXADC_LIST_VBIF,
	AUXADC_LIST_CHIP_TEMP,
	AUXADC_LIST_DCXO,
	AUXADC_LIST_ACCDET,
	AUXADC_LIST_TSX,
	AUXADC_LIST_HPOFS_CAL,
	AUXADC_LIST_ISENSE,
} PMIC_AUXADC_LIST;

//==============================================================================
// PMIC Exported Function
//==============================================================================
extern U32 pmic_read_interface(U32 RegNum, U32 *val, U32 MASK, U32 SHIFT);
extern U32 pmic_config_interface(U32 RegNum, U32 val, U32 MASK, U32 SHIFT);
extern U32 upmu_get_reg_value(U32 reg);
extern U32 upmu_set_reg_value(U32 reg, U32 reg_val);
extern U32 pmic_IsUsbCableIn (void);
extern kal_bool upmu_is_chr_det(void);
extern int pmic_detect_powerkey(void);
extern int pmic_detect_powerkey(void);
extern void PMIC_DUMP_ALL_Register(void);
extern U32 pmic_init (void);
extern int pmic_get_auxadc_value(PMIC_AUXADC_LIST list);
extern int get_bat_sense_volt(int times);
extern int get_i_sense_volt(int times);
extern int get_charger_volt(int times);
extern int get_tbat_volt(int times);
extern CHARGER_TYPE mt_charger_type_detection(void);
extern void vibr_Enable_HW(void);
extern void vibr_Disable_HW(void);
extern U32 get_pmic_chip_version(void);
extern void pmic_cold_reset(void);
extern unsigned int pmic_power_hold(unsigned int hold);

//==============================================================================
// PMIC Status Code
//==============================================================================
#define PMIC_TEST_PASS               0x0000
#define PMIC_TEST_FAIL               0xB001
#define PMIC_EXCEED_I2C_FIFO_LENGTH  0xB002
#define PMIC_CHRDET_EXIST            0xB003
#define PMIC_CHRDET_NOT_EXIST        0xB004

//==============================================================================
// PMIC Register Index
//==============================================================================
#include "upmu_hw.h"

#endif // _MT_PMIC_LK_SW_MT6356_H_

