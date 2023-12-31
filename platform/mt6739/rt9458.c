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
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <platform/rt9458.h>
#include <platform/mtk_charger_intf.h>
#include <printf.h>

#if !defined(CONFIG_POWER_EXT)
#include <platform/upmu_common.h>
#endif

#define RT9458_LK_DRV_VERSION "1.0.1_MTK"

/* ================= */
/* Internal variable */
/* ================= */

struct rt9458_info {
	struct mtk_charger_info mchr_info;
	struct mt_i2c_t i2c;
	int i2c_log_level;
};

static const unsigned char rt9458_reg_addr[] = {
	RT9458_REG_CTRL1,
	RT9458_REG_CTRL2,
	RT9458_REG_CTRL3,
	RT9458_REG_DEVID,
	RT9458_REG_CTRL4,
	RT9458_REG_CTRL5,
	RT9458_REG_CTRL6,
	RT9458_REG_CTRL7,
	RT9458_REG_IRQ1,
	RT9458_REG_IRQ2,
	RT9458_REG_IRQ3,
	RT9458_REG_MASK1,
	RT9458_REG_MASK2,
	RT9458_REG_MASK3,
	RT9458_REG_CTRL8,
};

enum rt9458_charging_status {
	RT9458_CHG_STATUS_READY = 0,
	RT9458_CHG_STATUS_PROGRESS,
	RT9458_CHG_STATUS_DONE,
	RT9458_CHG_STATUS_FAULT,
	RT9458_CHG_STATUS_MAX,
};

/* Charging status name */
static const char *rt9458_chg_status_name[RT9458_CHG_STATUS_MAX] = {
	"ready", "progress", "done", "fault",
};

/* uV, step is 20000uA except 4300000->4330000 */
static const u32 rt9458_battery_voreg[] = {
	3500000, 3520000, 3540000, 3560000, 3580000, 3600000, 3620000, 3640000,
	3660000, 3680000, 3700000, 3720000, 3740000, 3760000, 3780000, 3800000,
	3820000, 3840000, 3860000, 3880000, 3900000, 3920000, 3940000, 3960000,
	3980000, 4000000, 4020000, 4040000, 4060000, 4080000, 4100000, 4120000,
	4140000, 4160000, 4180000, 4200000, 4220000, 4240000, 4260000, 4280000,
	4300000, 4330000, 4350000, 4370000, 4390000, 4410000, 4430000, 4450000,
	4450000, 4450000, 4450000, 4450000, 4450000, 4450000, 4450000, 4450000,
	4450000, 4450000, 4450000, 4450000, 4450000, 4450000, 4450000, 4450000,
};

/* uV, step is 20000uA except 4300000->4330000 */
static const u32 rt9458_battery_vmreg[] = {
	4200000, 4220000, 4240000, 4260000, 4280000, 4300000, 4320000, 4340000,
	4360000, 4380000, 4400000, 4430000, 4450000, 4450000, 4450000, 4450000,
};


/* ========================= */
/* I2C operations */
/* ========================= */

static int rt9458_i2c_write_byte(struct rt9458_info *info, u8 cmd, u8 data)
{
	unsigned int ret = I2C_OK;
	unsigned char write_buf[2] = {cmd, data};
	struct mt_i2c_t *i2c = &info->i2c;

	ret = i2c_write(i2c, write_buf, 2);

	if (ret != I2C_OK)
		dprintf(CRITICAL,
			"%s: I2CW[0x%02X] = 0x%02X failed, code = %d\n",
			__func__, cmd, data, ret);
	else
		dprintf(info->i2c_log_level, "%s: I2CW[0x%02X] = 0x%02X\n",
			__func__, cmd, data);

	return ret;
}

static int rt9458_i2c_read_byte(struct rt9458_info *info, u8 cmd, u8 *data)
{
	int ret = I2C_OK;
	u8 ret_data = cmd;
	struct mt_i2c_t *i2c = &info->i2c;

	ret = i2c_write_read(i2c, &ret_data, 1, 1);

	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CR[0x%02X] failed, code = %d\n",
			__func__, cmd, ret);
	else {
		dprintf(info->i2c_log_level, "%s: I2CR[0x%02X] = 0x%02X\n",
			__func__, cmd, ret_data);
		*data = ret_data;
	}

	return ret;
}

static int rt9458_i2c_test_bit(struct rt9458_info *info, u8 cmd, u8 shift,
	bool *is_one)
{
	int ret = 0;
	u8 data = 0;

	ret = rt9458_i2c_read_byte(info, cmd, &data);
	if (ret != I2C_OK)
		return ret;

	data &= (1 << shift);
	*is_one = (data == 0 ? false : true);

	return ret;
}

static int rt9458_i2c_update_bits(struct rt9458_info *info, u8 cmd, u8 data,
	u8 mask)
{
	int ret = 0;
	u8 reg_data = 0;

	ret = rt9458_i2c_read_byte(info, cmd, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_data = reg_data & 0xFF;
	reg_data &= ~mask;
	reg_data |= (data & mask);

	return rt9458_i2c_write_byte(info, cmd, reg_data);
}

static inline int rt9458_set_bit(struct rt9458_info *info, u8 reg, u8 mask)
{
    return rt9458_i2c_update_bits(info, reg, mask, mask);
}

static inline int rt9458_clr_bit(struct rt9458_info *info, u8 reg, u8 mask)
{
    return rt9458_i2c_update_bits(info, reg, 0x00, mask);
}

/* ================== */
/* internal functions */
/* ================== */
static int rt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg);
static int rt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr);
static int rt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr);
static int rt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg);
static int rt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr);

static u8 rt9458_find_closest_reg_value(u32 min, u32 max,
	u32 step, u32 num, u32 target)
{
	u32 i = 0, cur_val = 0, next_val = 0;

	/* Smaller than minimum supported value, use minimum one */
	if (target < min)
		return 0;

	for (i = 0; i < num - 1; i++) {
		cur_val = min + i * step;
		next_val = cur_val + step;

		if (cur_val > max)
			cur_val = max;

		if (next_val > max)
			next_val = max;

		if (target >= cur_val && target < next_val)
			return i;
	}

	/* Greater than maximum supported value, use maximum one */
	return num - 1;
}

static u8 rt9458_find_closest_reg_value_via_table(const u32 *value_table,
	u32 table_size, u32 target_value)
{
	u32 i = 0;

	/* Smaller than minimum supported value, use minimum one */
	if (target_value < value_table[0])
		return 0;

	for (i = 0; i < table_size - 1; i++) {
		if (target_value >= value_table[i] && target_value < value_table[i + 1])
			return i;
	}

	/* Greater than maximum supported value, use maximum one */
	return table_size - 1;
}

static u32 rt9458_find_closest_real_value(u32 min, u32 max, u32 step,
	u8 reg_val)
{
	u32 ret_val = 0;

	ret_val = min + reg_val * step;
	if (ret_val > max)
		ret_val = max;

	return ret_val;
}

/*
 * internal: use AICR setting in CTRL2
 * otherwise, AICR is decided by OTG_PinP
 */
static int rt9458_set_aicr_int(struct rt9458_info *info, bool internal)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: internal = %d\n", __func__, internal);

	ret = (internal ? rt9458_set_bit : rt9458_clr_bit)
		(info, RT9458_REG_CTRL2, RT9458_MASK_AICR_INT);

	return ret;
}

static int rt9458_set_aicr_sel(struct rt9458_info *info, bool sel)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: sel = %d\n", __func__, sel);

	ret = (sel ? rt9458_set_bit : rt9458_clr_bit)
		(info, RT9458_REG_CTRL6, RT9458_MASK_AICR_SEL);

	return ret;
}

static bool rt9458_is_hw_exist(struct rt9458_info *info)
{
	int ret = 0;
	u8 vendor_id = 0, chip_rev = 0, data = 0;

	ret = rt9458_i2c_read_byte(info, RT9458_REG_DEVID, &data);
	if (ret < 0)
		return 0;

	vendor_id = data & 0xF0;
	chip_rev = data & 0x0F;
	if (vendor_id != RT9458_VENDOR_ID) {
		dprintf(CRITICAL, "%s: vendor id is incorrect (0x%02X)\n",
			__func__, vendor_id);
		return false;
	}
	dprintf(CRITICAL, "%s: chip rev (E%d, 0x%02X)\n", __func__, chip_rev,
		chip_rev);

	info->mchr_info.device_id = chip_rev;
	return true;
}

static int rt9458_enable_hz(struct rt9458_info *info, bool en)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);

	ret = (en ? rt9458_set_bit : rt9458_clr_bit)
		(info, RT9458_REG_CTRL2, RT9458_MASK_HZ_EN);

	return ret;
}

static int rt9458_reset_chip(struct rt9458_info *info)
{
	int ret = 0;

	dprintf(CRITICAL, "%s\n", __func__);

	ret = rt9458_enable_hz(info, false);
	if (ret < 0)
		dprintf(CRITICAL, "%s: disable hz fail\n", __func__);

	ret = rt9458_set_bit(info, RT9458_REG_CTRL4, RT9458_MASK_RST);

	return ret;
}

static int rt9458_set_battery_voreg(struct rt9458_info *info, u32 voreg)
{
	int ret = 0;
	u8 reg_voreg = 0;

	reg_voreg = rt9458_find_closest_reg_value_via_table(
		rt9458_battery_voreg,
		ARRAY_SIZE(rt9458_battery_voreg),
		voreg
	);

	dprintf(CRITICAL, "%s: voreg = %d(0x%02X)\n", __func__, voreg, reg_voreg);

	ret = rt9458_i2c_update_bits(
		info,
		RT9458_REG_CTRL3,
		reg_voreg << RT9458_SHIFT_VOREG,
		RT9458_MASK_VOREG
	);

	return ret;
}

static int rt9458_enable_wdt(struct rt9458_info *info, bool enable)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: enable = %d\n", __func__, enable);

	ret = (enable ? rt9458_set_bit : rt9458_clr_bit)
		(info, RT9458_REG_CTRL5, RT9458_MASK_TMR_EN);

	return ret;
}

static int rt9458_get_charging_status(struct rt9458_info *info,
	enum rt9458_charging_status *chg_stat)
{
	int ret = 0;
	u8 data = 0;

	ret = rt9458_i2c_read_byte(info, RT9458_REG_CTRL1, &data);
	if (ret < 0)
		return ret;

	*chg_stat = (data & RT9458_MASK_CHG_STAT) >> RT9458_SHIFT_CHG_STAT;

	return ret;
}

static int rt9458_enable_te(struct rt9458_info *info, bool enable)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: enable = %d\n", __func__, enable);

	ret = (enable ? rt9458_set_bit : rt9458_clr_bit)
		(info, RT9458_REG_CTRL2, RT9458_MASK_TE_EN);

	return ret;
}

static int rt9458_enable_te_shutdown(struct rt9458_info *info, bool enable)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: enable = %d\n", __func__, enable);

	ret = (enable ? rt9458_set_bit : rt9458_clr_bit)
		(info, RT9458_REG_CTRL2, RT9458_MASK_TE_SHTDM_EN);

	return ret;
}

static int rt9458_set_battery_vmreg(struct rt9458_info *info, u32 vmreg)
{
	int ret = 0;
	u8 reg_vmreg = 0;

	reg_vmreg = rt9458_find_closest_reg_value_via_table(
		rt9458_battery_vmreg,
		ARRAY_SIZE(rt9458_battery_vmreg),
		vmreg
	);

	dprintf(CRITICAL, "%s: vmreg = %d(0x%02X)\n", __func__, vmreg, reg_vmreg);

	ret = rt9458_i2c_update_bits(
		info,
		RT9458_REG_CTRL7,
		reg_vmreg << RT9458_SHIFT_VMREG,
		RT9458_MASK_VMREG
	);

	return ret;
}

static int rt9458_set_ieoc(struct rt9458_info *info, u32 ieoc)
{
	int ret = 0;

	/* Find corresponding reg value */
	u8 reg_ieoc = rt9458_find_closest_reg_value(RT9458_IEOC_MIN,
		RT9458_IEOC_MAX, RT9458_IEOC_STEP, RT9458_IEOC_NUM, ieoc);

	dprintf(CRITICAL, "%s: ieoc = %d(0x%02X)\n", __func__, ieoc, reg_ieoc);

	ret = rt9458_i2c_update_bits(
		info,
		RT9458_REG_CTRL5,
		reg_ieoc << RT9458_SHIFT_IEOC,
		RT9458_MASK_IEOC
	);

	return ret;
}

static int rt9458_get_mivr(struct rt9458_info *info, u32 *mivr)
{
	int ret = 0;
	u8 reg_mivr = 0, data = 0;

	ret = rt9458_i2c_read_byte(info, RT9458_REG_CTRL8, &data);
	if (ret < 0)
		return ret;

	reg_mivr = ((data & RT9458_MASK_MIVR) >> RT9458_SHIFT_MIVR) & 0xFF;
	*mivr = rt9458_find_closest_real_value(RT9458_MIVR_MIN, RT9458_MIVR_MAX,
		RT9458_MIVR_STEP, reg_mivr);

	return ret;
}

static int rt9458_get_ieoc(struct rt9458_info *info, u32 *ieoc)
{
	int ret = 0;
	u8 reg_ieoc = 0, data = 0;

	ret = rt9458_i2c_read_byte(info, RT9458_REG_CTRL5, &data);
	if (ret < 0)
		return ret;

	reg_ieoc = (data & RT9458_MASK_IEOC) >> RT9458_SHIFT_IEOC;
	*ieoc = rt9458_find_closest_real_value(RT9458_IEOC_MIN, RT9458_IEOC_MAX,
		RT9458_IEOC_STEP, reg_ieoc);

	return ret;
}

static int rt9458_is_charging_enable(struct rt9458_info *info, bool *enable)
{
	int ret = 0;

	ret = rt9458_i2c_test_bit(info, RT9458_REG_CTRL7, RT9458_SHIFT_CHG_EN,
		enable);

	return ret;
}


static int rt9458_init_setting(struct rt9458_info *info)
{
	int ret = 0;

	dprintf(CRITICAL, "%s\n", __func__);

	/* Set AICR to internal */
	ret = rt9458_set_aicr_int(info, true);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set AICR int failed\n", __func__);

	/* Set VMREG to maximum, uV */
	ret = rt9458_set_battery_vmreg(info, 4450000);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set vmreg failed\n", __func__);

	ret = rt9458_set_battery_voreg(info, 4350000);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set voreg failed\n", __func__);

	ret = rt_charger_set_ichg(&info->mchr_info, 1550000);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set ichg failed\n", __func__);

	ret = rt_charger_set_aicr(&info->mchr_info, 500000);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set aicr failed\n", __func__);

	ret = rt_charger_set_mivr(&info->mchr_info, 4500000);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set mivr failed\n", __func__);

	ret = rt9458_set_ieoc(info, 200000);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set ieoc failed\n", __func__);

	ret = rt9458_enable_te(info, true);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set te failed\n", __func__);

	ret = rt9458_enable_te_shutdown(info, true);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set te shutdown failed\n", __func__);

	ret = rt9458_enable_wdt(info, true);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set wdt failed\n", __func__);

	return ret;
}

/* =========================================================== */
/* The following is implementation for interface of rt_charger */
/* =========================================================== */

static int rt_charger_dump_register(struct mtk_charger_info *mchr_info)
{
	u32 i = 0;
	int ret = 0;
	u32 ichg = 0, aicr = 0, mivr = 0, ieoc = 0;
	u8 data = 0;
	bool chg_enable = 0;
	struct rt9458_info *info = (struct rt9458_info *)mchr_info;
	enum rt9458_charging_status chg_status = RT9458_CHG_STATUS_READY;

	ret = rt9458_get_charging_status(info, &chg_status);
	if (chg_status == RT9458_CHG_STATUS_FAULT) {
		for (i = 0; i < ARRAY_SIZE(rt9458_reg_addr); i++)
			ret = rt9458_i2c_read_byte(info, rt9458_reg_addr[i],
				&data);
	}

	ret = rt_charger_get_ichg(&info->mchr_info, &ichg);
	ret = rt9458_get_mivr(info, &mivr);
	ret = rt_charger_get_aicr(&info->mchr_info, &aicr);
	ret = rt9458_get_ieoc(info, &ieoc);
	ret = rt9458_is_charging_enable(info, &chg_enable);

	dprintf(CRITICAL, "%s: ICHG = %dmA, AICR = %dmA, MIVR = %dmV, IEOC = %dmA\n",
		__func__, ichg / 1000, aicr / 1000, mivr / 1000, ieoc / 1000);
	dprintf(CRITICAL, "%s: CHG_EN = %d, CHG_STATUS = %s\n",
		__func__, chg_enable, rt9458_chg_status_name[chg_status]);

	return ret;
}

static int rt_charger_enable_charging(struct mtk_charger_info *mchr_info,
	bool enable)
{
	int ret = 0;
	struct rt9458_info *info = (struct rt9458_info *)mchr_info;

	dprintf(CRITICAL, "%s: enable = %d\n", __func__, enable);

	ret = (enable ? rt9458_set_bit : rt9458_clr_bit)
		(info, RT9458_REG_CTRL7, RT9458_MASK_CHG_EN);

	return ret;
}

static int rt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg)
{
	int ret = 0;
	u8 reg_ichg = 0;
	struct rt9458_info *info = (struct rt9458_info *)mchr_info;

	/* Find corresponding reg value */
	reg_ichg = rt9458_find_closest_reg_value(RT9458_ICHG_MIN,
		RT9458_ICHG_MAX, RT9458_ICHG_STEP, RT9458_ICHG_NUM, ichg);

	dprintf(CRITICAL, "%s: ichg = %d(0x%02X)\n", __func__, ichg, reg_ichg);

	ret = rt9458_i2c_update_bits(
		info,
		RT9458_REG_CTRL6,
		reg_ichg << RT9458_SHIFT_ICHG,
		RT9458_MASK_ICHG
	);

	return ret;
}

static int rt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr)
{
	int ret = 0;
	u8 reg_aicr = 0;
	struct rt9458_info *info = (struct rt9458_info *)mchr_info;

	if (aicr < 500000) /* AICR = 100 mA */
		reg_aicr = 0x00;
	else if (aicr < 700000) { /* AICR = 500 mA */
		ret = rt9458_set_aicr_sel(info, false);
		if (ret < 0)
			return ret;
		reg_aicr = 0x01;
	} else if (aicr < 1000000) { /* AICR = 700 mA */
		ret = rt9458_set_aicr_sel(info, true);
		if (ret < 0)
			return ret;
		reg_aicr = 0x01;
	} else if (aicr == 1000000) { /* AICR = 1000mA */
		ret = rt9458_set_aicr_sel(info, false);
		if (ret < 0)
			return ret;
		reg_aicr = 0x02;
	} else /* AICR = no limit */
		reg_aicr = 0x03;

	dprintf(CRITICAL, "%s: aicr = %d(0x%02X)\n", __func__, aicr, reg_aicr);

	ret = rt9458_i2c_update_bits(
		info,
		RT9458_REG_CTRL2,
		reg_aicr << RT9458_SHIFT_AICR,
		RT9458_MASK_AICR
	);

	return ret;
}

static int rt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr)
{
	int ret = 0;
	u8 reg_mivr = 0;
	struct rt9458_info *info = (struct rt9458_info *)mchr_info;

	reg_mivr = rt9458_find_closest_reg_value(RT9458_MIVR_MIN,
		RT9458_MIVR_MAX, RT9458_MIVR_STEP, RT9458_MIVR_NUM, mivr);

	dprintf(CRITICAL, "%s: mivr = %d(0x%02X)\n", __func__, mivr, reg_mivr);

	ret = rt9458_i2c_update_bits(
		info,
		RT9458_REG_CTRL8,
		reg_mivr << RT9458_SHIFT_MIVR,
		RT9458_MASK_MIVR
	);

	return ret;
}

static int rt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg)
{
	int ret = 0;
	u8 reg_ichg = 0, data = 0;
	struct rt9458_info *info = (struct rt9458_info *)mchr_info;

	ret = rt9458_i2c_read_byte(info, RT9458_REG_CTRL6, &data);
	if (ret < 0)
		return ret;

	reg_ichg = (data & RT9458_MASK_ICHG) >> RT9458_SHIFT_ICHG;
	*ichg = rt9458_find_closest_real_value(RT9458_ICHG_MIN, RT9458_ICHG_MAX,
		RT9458_ICHG_STEP, reg_ichg);

	return ret;
}

static int rt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr)
{
	int ret = 0;
	bool aicr_sel = false;
	u8 reg_aicr = 0, data = 0;
	struct rt9458_info *info = (struct rt9458_info *)mchr_info;

	/* Read AICR sel */
	ret = rt9458_i2c_test_bit(info, RT9458_REG_CTRL6, RT9458_SHIFT_AICR_SEL,
		&aicr_sel);
	if (ret < 0)
		return ret;

	/* Read AICR */
	ret = rt9458_i2c_read_byte(info, RT9458_REG_CTRL2, &data);
	if (ret < 0)
		return ret;
	reg_aicr = ((data & RT9458_MASK_AICR) >> RT9458_SHIFT_AICR) & 0xFF;


	switch (reg_aicr) {
	case 0:
		*aicr = 100000;
		break;
	case 1:
		*aicr = aicr_sel ? 700000 : 500000;
		break;
	case 2:
		*aicr = aicr_sel ? 700000 : 1000000;
		break;
	case 3:
		*aicr = 0;
		break;
	}

	return ret;
}

static int rt_charger_enable_wdt(struct mtk_charger_info *mchr_info, bool en)
{
	struct rt9458_info *info = (struct rt9458_info *)mchr_info;
	return rt9458_enable_wdt(info, en);
}

static struct mtk_charger_ops rt9458_mchr_ops = {
	.dump_register = rt_charger_dump_register,
	.enable_charging = rt_charger_enable_charging,
	.get_ichg = rt_charger_get_ichg,
	.set_ichg = rt_charger_set_ichg,
	.set_aicr = rt_charger_set_aicr,
	.set_mivr = rt_charger_set_mivr,
	.get_aicr = rt_charger_get_aicr,
	.enable_wdt = rt_charger_enable_wdt,
};


/* Info of primary charger */
static struct rt9458_info g_rt9458_info = {
	.mchr_info = {
		.name = "primary_charger",
		.alias_name = "rt9458",
		.device_id = -1,
		.mchr_ops = &rt9458_mchr_ops,
	},
	.i2c = {
		.id = I2C1,
		.addr = RT9458_SLAVE_ADDR,
		.mode = ST_MODE,
		.speed = 100,
	},
	.i2c_log_level = INFO,
};

int rt9458_probe(void)
{
	int ret = 0;

	/* Check primary charger */
	if (rt9458_is_hw_exist(&g_rt9458_info)) {
		ret = rt9458_reset_chip(&g_rt9458_info);
		if (ret < 0)
			dprintf(CRITICAL, "%s: reset chip fail\n", __func__);
		ret = rt9458_init_setting(&g_rt9458_info);
		mtk_charger_set_info(&(g_rt9458_info.mchr_info));
		dprintf(CRITICAL, "%s: %s\n", __func__, RT9458_LK_DRV_VERSION);
	}

	return ret;
}

/*
 * Revision Note
 * 1.0.1
 * (1) Add chip reset function
 *
 * 1.0.0
 * (1) Initial release
 */
