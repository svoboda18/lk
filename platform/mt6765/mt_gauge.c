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

#include <platform/mt_typedefs.h>                                                  
#include <platform/mt_pmic.h>                                                      
#include <platform/mt_pmic_wrap_init.h>                                            
#include <printf.h>                                                                
#include <sys/types.h>
#include <platform/mt_battery.h>
#include <mtk_battery.h>
#include <platform/upmu_common.h>

extern bool g_isbat_init;
extern bool g_fg_is_charging;
extern struct fuel_gauge_custom_data fg_cust_data;

unsigned int fg_get_data_ready_status(void)
{
	unsigned int temp_val = 0;

	pmic_read_interface(PMIC_FG_LATCHDATA_ST_ADDR, &temp_val, 0xFFFF, 0x0);

	temp_val =
	(temp_val & (PMIC_FG_LATCHDATA_ST_MASK << PMIC_FG_LATCHDATA_ST_SHIFT))
	>> PMIC_FG_LATCHDATA_ST_SHIFT;

	return temp_val;
}

void fgauge_read_IM_current(void *data)
{
	unsigned short uvalue16 = 0;
	signed int dvalue = 0;
	signed int ori_curr = 0;
	signed int curr_rfg = 0;
	long long Temp_Value = 0;

	uvalue16 = pmic_get_register_value(PMIC_FG_R_CURR);

	/*calculate the real world data    */
	dvalue = (unsigned int) uvalue16;
	if (dvalue == 0) {
		Temp_Value = (long long) dvalue;
		g_fg_is_charging = false;
	} else if (dvalue > 32767) {
		/* > 0x8000 */
		Temp_Value = (long long) (dvalue - 65535);
		Temp_Value = Temp_Value - (Temp_Value * 2);
		g_fg_is_charging = false;
	} else {
		Temp_Value = (long long) dvalue;
		g_fg_is_charging = true;
	}

	Temp_Value = Temp_Value * UNIT_FGCURRENT;
	Temp_Value = Temp_Value/100000;
	dvalue = (unsigned int) Temp_Value;

	ori_curr = dvalue;
	curr_rfg = dvalue;

	/* Auto adjust value */
	if (fg_cust_data.r_fg_value != 100) {
		dvalue = (dvalue * 100) / fg_cust_data.r_fg_value;
		curr_rfg = dvalue;
	}

	dvalue = ((dvalue * fg_cust_data.car_tune_value) / 1000);

	if (g_fg_is_charging == true) {
		dprintf(CRITICAL,"[fgauge_read_IM_current](charging)FG_CURRENT:0x%x,curr:[%d,%d,%d] mA, Rfg:%d ratio:%d\n",
			uvalue16, ori_curr, curr_rfg, dvalue, fg_cust_data.r_fg_value, fg_cust_data.car_tune_value);

	} else {
		dprintf(CRITICAL,"[fgauge_read_IM_current](discharg)FG_CURRENT:0x%x,curr:[%d,%d,%d] mA, Rfg:%d ratio:%d\n",
			uvalue16, ori_curr, curr_rfg, dvalue, fg_cust_data.r_fg_value, fg_cust_data.car_tune_value);
	}

	*(signed int *) (data) = dvalue;
}

int fgauge_get_current(bool *fg_is_charging, int *data)
{

	unsigned short uvalue16 = 0;
	signed int dvalue = 0;
	signed int curr_rfg = 0;
	signed int ori_curr = 0;
	int m = 0;
	long long Temp_Value = 0;
	int ret;


	dprintf(CRITICAL, "[fgauge_read_current]g_isbat_init:%d,cartune:%d,%d,%d\n",
		g_isbat_init, fg_cust_data.car_tune_value, fg_cust_data.r_fg_value, UNIT_FGCURRENT);

	ret = pmic_config_interface(MT6357_FGADC_CON1, 0x0001, 0x000F, 0x0);

	m = 0;

	while (fg_get_data_ready_status() == 0) {
		m++;
		if (m > 1000) {
			dprintf(CRITICAL, "[fgauge_read_current] fg_get_data_ready_status timeout 1 !%d\n", ret);
			break;
		}
	}

	uvalue16 = pmic_get_register_value(PMIC_FG_CURRENT_OUT);

	ret = pmic_config_interface(MT6357_FGADC_CON1, 0x0008, 0x000F, 0x0);
	m = 0;
		while (fg_get_data_ready_status() != 0) {
			m++;
			if (m > 1000) {
				dprintf(CRITICAL, "[fgauge_read_current] fg_get_data_ready_status timeout 2!%d\n", ret);
				break;
			}
		}

	ret = pmic_config_interface(MT6357_FGADC_CON1, 0x0000, 0x000F, 0x0);

	/*calculate the real world data    */
	dvalue = (unsigned int) uvalue16;
	if (dvalue == 0) {
		Temp_Value = (long long) dvalue;
		*fg_is_charging = false;
	} else if (dvalue > 32767) {
		/* > 0x8000 */
		Temp_Value = (long long) (dvalue - 65535);
		Temp_Value = Temp_Value - (Temp_Value * 2);
		*fg_is_charging = false;
	} else {
		Temp_Value = (long long) dvalue;
		*fg_is_charging = true;
	}

	Temp_Value = Temp_Value * UNIT_FGCURRENT;
	Temp_Value = Temp_Value / 100000;
	dvalue = (unsigned int) Temp_Value;

	ori_curr = dvalue;
	curr_rfg = dvalue;

	/* Auto adjust value */
	if (fg_cust_data.r_fg_value != 100) {
		dvalue = (dvalue * 100) / fg_cust_data.r_fg_value;
		curr_rfg = dvalue;
	}

	dvalue = ((dvalue * fg_cust_data.car_tune_value) / 1000);

	*data = dvalue;
	dprintf(CRITICAL, "[fgauge_read_current]is_charge:%d Ori_curr:0x%x,curr:[%d,%d,Final:%d] Rfg:%d ratio:%d\n",
		*fg_is_charging, uvalue16, ori_curr, curr_rfg, dvalue,
		fg_cust_data.r_fg_value, fg_cust_data.car_tune_value);

	return 0;
}

int dis_gm3_src_sel(bool is_dis)
{
	int res = Fg_Temperature_Table[0].TemperatureR;

	dprintf(INFO, "dis_gm3_src_sel = 0 , res =%d\n", res); 
	return 0;
}
