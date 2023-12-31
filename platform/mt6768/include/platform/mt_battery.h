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

#ifndef _MT_BATTERY_LK_H_
#define _MT_BATTERY_LK_H_


/* Current related */
#define UNIT_FGCURRENT     (381470)
#define CAR_TUNE_VALUE      1000 //1.00 
#define R_FG_VALUE          50   
#define FG_METER_RESISTANCE     75

/* Gauge 0% related */
#define PMIC_MIN_VOL 34000
#define POWERON_SYSTEM_IBOOT 500        /* mA */

/* BAT TEMP related  */

#define BAT_NTC_10 1
#define BAT_NTC_47 0
#define RBAT_PULL_UP_VOLT	2800

#if (BAT_NTC_10 == 1)
#define RBAT_PULL_UP_R             24000
#endif

#if (BAT_NTC_47 == 1)
#define RBAT_PULL_UP_R             61900
#endif

#define BIF_NTC_R 16000

struct FUELGAUGE_TEMPERATURE {                                                     
        signed int BatteryTemp;
        signed int TemperatureR;
}; 

#if (BAT_NTC_10 == 1)
static struct FUELGAUGE_TEMPERATURE Fg_Temperature_Table[21] = {
		{-40, 195652},
		{-35, 148171},
		{-30, 113347},
		{-25, 87559},
		{-20, 68237},
		{-15, 53650},
		{-10, 42506},
		{-5, 33892},
		{0, 27219},
		{5, 22021},
		{10, 17926},
		{15, 14674},
		{20, 12081},
		{25, 10000},
		{30, 8315},
		{35, 6948},
		{40, 5834},
		{45, 4917},
		{50, 4161},
		{55, 3535},
		{60, 3014}
};
#endif

#if (BAT_NTC_47 == 1)
static struct FUELGAUGE_TEMPERATURE Fg_Temperature_Table[21] = {
		{-40, 1747920},
		{-35, 1245428},
		{-30, 898485},
		{-25, 655802},
		{-20, 483954},
		{-15, 360850},
		{-10, 271697},
		{-5, 206463},
		{0, 158214},
		{5, 122259},
		{10, 95227},
		{15, 74730},
		{20, 59065},
		{25, 47000},
		{30, 37643},
		{35, 30334},
		{40, 24591},
		{45, 20048},
		{50, 16433},
		{55, 13539},
		{60, 11210}
};
#endif

int fgauge_get_current(bool *fg_is_charging, int *data);
void fgauge_read_IM_current(void *data);
int dis_gm3_src_sel(bool is_dis);

#endif // _MT_BATTERY_LK_H_

