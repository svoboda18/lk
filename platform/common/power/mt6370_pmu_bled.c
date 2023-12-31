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

#include <platform/mt_typedefs.h>
#include <platform/mt_i2c.h>
#include <platform/errno.h>
#include <libfdt.h>
#include <printf.h>
#include <string.h>
#include <lk_builtin_dtb.h>
#include "mt6370_pmu_bled.h"
#include "mtk_charger.h"

#define MT6370_PMU_BLED_LK_DRV_VERSION "1.0.3_MTK"

static struct mt_i2c_t i2c = {
	.id = I2C5,
	.addr = MT6370_SLAVE_ADDR,
	.mode = FS_MODE,
	.speed = 400,
	.pushpull = false,
};

struct mt6370_bled_config_t {
	u8 addr;
	u8 val;
};

static struct mt6370_bled_config_t mt6370_bled_settings[] = {
	{.addr = 0xA1, .val = 0x89},
	{.addr = 0xA2, .val = 0x04},
	{.addr = 0xA3, .val = 0x00},
	{.addr = 0xA4, .val = 0x00},
	{.addr = 0xA5, .val = 0x00},
	{.addr = 0xA6, .val = 0x00},
	{.addr = 0xA7, .val = 0x00},
	{.addr = 0xA0, .val = 0x42},
	{.addr = 0xAD, .val = 0x00},
};

/* 6370 default pwm setting, used when dts not found */
static struct mt6370_bled_config_t mt6370_bled_settings_default_pwm[] = {
	{.addr = 0xA1, .val = 0xED},
	{.addr = 0xA2, .val = 0xB4},
	{.addr = 0xA3, .val = 0x30},
	{.addr = 0xA4, .val = 0x07},
	{.addr = 0xA5, .val = 0x3F},
	{.addr = 0xA6, .val = 0x00},
	{.addr = 0xA7, .val = 0x08},
	{.addr = 0xA0, .val = 0x7E},
	{.addr = 0xAD, .val = 0x00},
};

/* ========================= */
/* I2C operations */
/* ========================= */
static int mt6370_i2c_read_byte(struct mt_i2c_t *i2c, u8 cmd, u8 *data)
{
	int ret = 0;
	u8 reg_data = cmd;

	ret = i2c_write_read(i2c, &reg_data, 1, 1);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CR[0x%02X] fail(%d)\n",
				  __func__, cmd, ret);
	else {
		dprintf(INFO, "%s: I2CR[0x%02X] = 0x%02X\n",
			      __func__, cmd, reg_data);
		*data = reg_data;
	}

	return ret;
}

static int mt6370_i2c_write_byte(struct mt_i2c_t *i2c, u8 cmd, u8 data)
{
	int ret = 0;
	u8 write_buf[2] = {cmd, data};

	ret = i2c_write(i2c, write_buf, 2);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CW[0x%02X] = 0x%02X fail(%d)\n",
				  __func__, cmd, data, ret);
	else
		dprintf(INFO, "%s: I2CW[0x%02X] = 0x%02X\n",
			      __func__, cmd, data);

	return ret;
}

static void mt6370_bled_parse_dt(void *fdt)
{
	int ret = 0, offset = 0, sub_offset = 0;
	u32 val = 0;
	u8 vendor_id = 0;

	offset = fdt_node_offset_by_compatible(fdt, -1, "mediatek,subpmic_pmu");
	sub_offset = fdt_parent_offset(fdt, offset);
	if (offset >= 0 && sub_offset >= 0) {
		val = chr_fdt_getprop_u32(fdt, sub_offset, "id");
		if (val) {
			i2c.id = val;
			dprintf(CRITICAL, "%s: subpmic_pmu id = %d\n",
					  __func__, i2c.id);
		}
	}

	offset = fdt_path_offset(fdt, "/mt6370_pmu_dts");
	sub_offset = fdt_subnode_offset(fdt, offset, "bled");
	if (offset >= 0 && sub_offset >= 0) {
		val = chr_fdt_getprop_bool(fdt, sub_offset, "mt,ext_en_pin");
		dprintf(INFO, "[LEDS] mt,ext_en_pin val = %d\n", val);
		if (val) {
			mt6370_bled_settings[7].val &= ~(MT6370_BLED_EN | MT6370_BLED_EXTEN);
			mt6370_bled_settings[7].val |= MT6370_BLED_EXTEN;
		}
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,chan_en");
		dprintf(INFO, "[LEDS] mt,chan_en val = %d\n", val);
		if (val)
			mt6370_bled_settings[7].val |= (val << MT6370_BLED_CHANENSHFT);
		val = chr_fdt_getprop_bool(fdt, sub_offset, "mt,map_linear");
		dprintf(INFO, "[LEDS] mt,map_linear = %d\n", val);
		if (!val)
			mt6370_bled_settings[7].val &= ~(MT6370_BLED_MAPLINEAR);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,bl_ovp_level");
		dprintf(INFO, "[LEDS] mt,bl_ovp_level = %d\n", val);
		if (val)
			mt6370_bled_settings[0].val |= (val << MT6370_BLED_OVPSHFT);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,bl_ocp_level");
		dprintf(INFO, "[LEDS] mt,bl_ocp_level = %d\n", val);
		if (val)
			mt6370_bled_settings[0].val |= (val << MT6370_BLED_OCPSHFT);
		val = chr_fdt_getprop_bool(fdt, sub_offset, "mt,use_pwm");
		dprintf(INFO, "[LEDS] mt,use_pwm = %d\n", val);
		if (val)
			mt6370_bled_settings[1].val |= (val << MT6370_BLED_PWMSHIFT);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,pwm_fsample");
		dprintf(INFO, "[LEDS] mt,pwm_fsample = %d\n", val);
		if (val)
			mt6370_bled_settings[1].val |= (val << MT6370_BLED_PWMFSHFT);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,pwm_deglitch");
		dprintf(INFO, "[LEDS] mt,pwm_deglitch = %d\n", val);
		if (val)
			mt6370_bled_settings[1].val |= (val << MT6370_BLED_PWMDSHFT);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,pwm_hys_en");
		dprintf(INFO, "[LEDS] mt,pwm_hys_en = %d\n", val);
		if (!val)
			mt6370_bled_settings[1].val &= ~(MT6370_BLED_PWMHE);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,pwm_hys");
		dprintf(INFO, "[LEDS] mt,pwm_hys = %d\n", val);
		if (val)
			mt6370_bled_settings[1].val |= (val << MT6370_BLED_PWMHSHFT);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,bled_ramptime");
		dprintf(INFO, "[LEDS] mt,bled_ramptime = %d\n", val);
		if (val)
			mt6370_bled_settings[2].val |= (val << MT6370_BLED_RAMPTSHFT);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,bled_flash_ramp");
		dprintf(INFO, "[LEDS] mt,bled_flash_ramp = %d\n", val);
		if (val)
			mt6370_bled_settings[6].val |= (val << MT6370_BLFLRAMP_SHFT);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,max_bled_brightness");
		dprintf(INFO, "[LEDS] mt,max_bled_brightness = %d\n", val);
		if (val) {
			val = ((u64)val * 255) >> 8;
			mt6370_bled_settings[3].val |= (val & 0x7);
			mt6370_bled_settings[4].val |= ((val >> 3) & 0xFF);
		}
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,bled_curr_scale");
		dprintf(INFO, "[LEDS] mt,bled_curr_scale = %d\n", val);
		if (val)
			mt6370_bled_settings[8].val |= (val << MT6370_BLED_CURR_SCALESHFT);
		val = chr_fdt_getprop_u32(fdt, sub_offset, "mt,pwm_lpf_coef");
		dprintf(INFO, "[LEDS] mt,pwm_lpf_coef = %d\n", val);
		if (val)
			mt6370_bled_settings[8].val |= (val << MT6370_PWM_LPF_COEFSHFT);
		val = chr_fdt_getprop_bool(fdt, sub_offset, "mt,pwm_lpf_en");
		dprintf(INFO, "[LEDS] mt,pwm_lpf_en = %d\n", val);
		if (val)
			mt6370_bled_settings[8].val |= (val << MT6370_PWM_LPF_ENSHFT);
		val = chr_fdt_getprop_bool(fdt, sub_offset, "mt,bled_curr_mode");
		dprintf(INFO, "[LEDS] mt,bled_curr_mode = %d\n", val);
		if (val)
			mt6370_bled_settings[8].val |= (val << MT6370_BLED_CURR_MODESHFT);
	} else {
		memcpy(mt6370_bled_settings, mt6370_bled_settings_default_pwm, sizeof(mt6370_bled_settings));
		dprintf(CRITICAL, "[LEDS] cannot read settings from dts, using default setting\n");
	}

	ret = mt6370_i2c_read_byte(&i2c, MT6370_PMU_REG_DEVINFO, &vendor_id);
	if (ret != I2C_OK)
		return;
	vendor_id &= 0xF0;
	if (vendor_id == MT6372_VENDOR_ID || vendor_id == MT6372C_VENDOR_ID)
		mt6370_bled_settings[3].val <<= 3;
}

int mt6370_bled_probe(void)
{
	int ret = 0;
	u32 i = 0;

	dprintf(INFO, "%s: (%s)\n", __func__, MT6370_PMU_BLED_LK_DRV_VERSION);

	mt6370_bled_parse_dt(get_lk_overlayed_dtb());
	for (i = 0; i < ARRAY_SIZE(mt6370_bled_settings); i++) {
		ret = mt6370_i2c_write_byte(&i2c, mt6370_bled_settings[i].addr,
					    mt6370_bled_settings[i].val);
		if (ret != I2C_OK)
			break;
	}

	return ret;
}

/*
 * Release Note
 * 1.0.3
 * (1) Move the driver to the common directory
 *
 * 1.0.2
 * (1) Decrease I2C speed from 3400Hz to 400Hz
 *
 * 1.0.1
 * (1) Add support for MT6372
 *
 * 1.0.0
 * (1) Initial release
 */
