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
#include <platform/mt_gpt.h>
#include <platform/rt5081_pmu_charger.h>
#include <platform/mtk_charger_intf.h>
#include <printf.h>
#include <string.h>

#if !defined(CONFIG_POWER_EXT)
#include <platform/upmu_common.h>
#endif

#define RT5081_PMU_CHARGER_LK_DRV_VERSION "1.0.4_MTK"

/* ================= */
/* Internal variable */
/* ================= */

struct rt5081_pmu_charger_info {
	struct mtk_charger_info mchr_info;
	struct mt_i2c_t i2c;
	int i2c_log_level;
	unsigned int hidden_mode_cnt;
};

enum rt5081_charging_status {
	RT5081_CHG_STATUS_READY = 0,
	RT5081_CHG_STATUS_PROGRESS,
	RT5081_CHG_STATUS_DONE,
	RT5081_CHG_STATUS_FAULT,
	RT5081_CHG_STATUS_MAX,
};

/* Charging status name */
static const char *rt5081_chg_status_name[RT5081_CHG_STATUS_MAX] = {
	"ready", "progress", "done", "fault",
};

static const unsigned char rt5081_reg_en_hidden_mode[] = {
	RT5081_PMU_REG_HIDDENPASCODE1,
	RT5081_PMU_REG_HIDDENPASCODE2,
	RT5081_PMU_REG_HIDDENPASCODE3,
	RT5081_PMU_REG_HIDDENPASCODE4,
};

static const unsigned char rt5081_val_en_hidden_mode[] = {
	0x96, 0x69, 0xC3, 0x3C,
};

/* ======================= */
/* Address & Default value */
/* ======================= */


static const unsigned char rt5081_chg_reg_addr[] = {
	RT5081_PMU_REG_CHGCTRL1,
	RT5081_PMU_REG_CHGCTRL2,
	RT5081_PMU_REG_CHGCTRL3,
	RT5081_PMU_REG_CHGCTRL4,
	RT5081_PMU_REG_CHGCTRL5,
	RT5081_PMU_REG_CHGCTRL6,
	RT5081_PMU_REG_CHGCTRL7,
	RT5081_PMU_REG_CHGCTRL8,
	RT5081_PMU_REG_CHGCTRL9,
	RT5081_PMU_REG_CHGCTRL10,
	RT5081_PMU_REG_CHGCTRL11,
	RT5081_PMU_REG_CHGCTRL12,
	RT5081_PMU_REG_CHGCTRL13,
	RT5081_PMU_REG_CHGCTRL14,
	RT5081_PMU_REG_CHGCTRL15,
	RT5081_PMU_REG_CHGCTRL16,
	RT5081_PMU_REG_CHGADC,
	RT5081_PMU_REG_DEVICETYPE,
	RT5081_PMU_REG_QCCTRL1,
	RT5081_PMU_REG_QCCTRL2,
	RT5081_PMU_REG_QC3P0CTRL1,
	RT5081_PMU_REG_QC3P0CTRL2,
	RT5081_PMU_REG_USBSTATUS1,
	RT5081_PMU_REG_QCSTATUS1,
	RT5081_PMU_REG_QCSTATUS2,
	RT5081_PMU_REG_CHGPUMP,
	RT5081_PMU_REG_CHGCTRL17,
	RT5081_PMU_REG_CHGCTRL18,
	RT5081_PMU_REG_CHGDIRCHG1,
	RT5081_PMU_REG_CHGDIRCHG2,
	RT5081_PMU_REG_CHGDIRCHG3,
	RT5081_PMU_REG_CHGSTAT,
	RT5081_PMU_REG_CHGNTC,
	RT5081_PMU_REG_ADCDATAH,
	RT5081_PMU_REG_ADCDATAL,
	RT5081_PMU_REG_CHGCTRL19,
	RT5081_PMU_REG_CHGSTAT1,
	RT5081_PMU_REG_CHGSTAT2,
	RT5081_PMU_REG_CHGSTAT3,
	RT5081_PMU_REG_CHGSTAT4,
	RT5081_PMU_REG_CHGSTAT5,
	RT5081_PMU_REG_CHGSTAT6,
	RT5081_PMU_REG_QCSTAT,
	RT5081_PMU_REG_DICHGSTAT,
	RT5081_PMU_REG_OVPCTRLSTAT,
};


enum rt5081_iin_limit_sel {
	RT5081_IIMLMTSEL_AICR_3250 = 0,
	RT5081_IIMLMTSEL_CHR_TYPE,
	RT5081_IINLMTSEL_AICR,
	RT5081_IINLMTSEL_LOWER_LEVEL, /* lower of above three */
};


/* ========================= */
/* I2C operations */
/* ========================= */

static int rt5081_i2c_write_byte(struct rt5081_pmu_charger_info *info, u8 cmd,
	u8 data)
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

static int rt5081_i2c_read_byte(struct rt5081_pmu_charger_info *info, u8 cmd,
	u8 *data)
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

static int rt5081_i2c_block_write(struct rt5081_pmu_charger_info *info, u8 cmd,
	int len, const u8 *data)
{
	unsigned char write_buf[len + 1];
	struct mt_i2c_t *i2c = &info->i2c;

	write_buf[0] = cmd;
	memcpy(&write_buf[1], data, len);

	return i2c_write(i2c, write_buf, len + 1);
}

static int rt5081_i2c_test_bit(struct rt5081_pmu_charger_info *info, u8 cmd,
	u8 shift)
{
	int ret = 0;
	u8 data = 0;

	ret = rt5081_i2c_read_byte(info, cmd, &data);
	if (ret != I2C_OK)
		return ret;

	ret = data & (1 << shift);

	return ret;
}

static int rt5081_i2c_update_bits(struct rt5081_pmu_charger_info *info, u8 cmd,
	u8 mask, u8 data)
{
	int ret = 0;
	u8 reg_data = 0;

	ret = rt5081_i2c_read_byte(info, cmd, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_data = reg_data & 0xFF;
	reg_data &= ~mask;
	reg_data |= (data & mask);

	return rt5081_i2c_write_byte(info, cmd, reg_data);
}

static inline int rt5081_set_bit(struct rt5081_pmu_charger_info *info, u8 reg,
	u8 mask)
{
    return rt5081_i2c_update_bits(info, reg, mask, mask);
}

static inline int rt5081_clr_bit(struct rt5081_pmu_charger_info *info, u8 reg,
	u8 mask)
{
    return rt5081_i2c_update_bits(info, reg, mask, 0x00);
}

/* ================== */
/* internal functions */
/* ================== */
static int rt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg);
static int rt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr);
static int rt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr);
static int rt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg);
static int rt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr);

static u8 rt5081_find_closest_reg_value(const u32 min, const u32 max,
	const u32 step, const u32 num, const u32 target)
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

static u8 rt5081_find_closest_reg_value_via_table(const u32 *value_table,
	const u32 table_size, const u32 target_value)
{
	u32 i = 0;

	/* Smaller than minimum supported value, use minimum one */
	if (target_value < value_table[0])
		return 0;

	for (i = 0; i < table_size - 1; i++) {
		if (target_value >= value_table[i] &&
		    target_value < value_table[i + 1])
			return i;
	}

	/* Greater than maximum supported value, use maximum one */
	return table_size - 1;
}

static u32 rt5081_find_closest_real_value(const u32 min, const u32 max,
	const u32 step, const u8 reg_val)
{
	u32 ret_val = 0;

	ret_val = min + reg_val * step;
	if (ret_val > max)
		ret_val = max;

	return ret_val;
}

static int rt5081_enable_hidden_mode(struct rt5081_pmu_charger_info *info,
	bool en)
{
	int ret = 0;

	if (en) {
		if (info->hidden_mode_cnt == 0) {
			ret = rt5081_i2c_block_write(info,
				rt5081_reg_en_hidden_mode[0],
				ARRAY_SIZE(rt5081_val_en_hidden_mode),
				rt5081_val_en_hidden_mode);
			if (ret != I2C_OK)
				goto err;
		}
		info->hidden_mode_cnt++;
	} else {
		if (info->hidden_mode_cnt == 1) /* last one */
			ret = rt5081_i2c_write_byte(info,
				rt5081_reg_en_hidden_mode[0], 0x00);
		info->hidden_mode_cnt--;
		if (ret < 0)
			goto err;
	}
	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);
	return 0;

err:
	dprintf(CRITICAL, "%s: en = %d fail(%d)\n", __func__, en, ret);
	return ret;
}


/* Hardware pin current limit */
static int rt5081_enable_ilim(struct rt5081_pmu_charger_info *info, bool enable)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: enable ilim = %d\n", __func__, enable);

	ret = (enable ? rt5081_set_bit : rt5081_clr_bit)
		(info, RT5081_PMU_REG_CHGCTRL3, RT5081_MASK_ILIM_EN);

	return ret;
}

/* Select IINLMTSEL to use AICR */
static int rt5081_select_input_current_limit(
	struct rt5081_pmu_charger_info *info, enum rt5081_iin_limit_sel sel)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: select input current limit = %d\n",
		__func__, sel);

	ret = rt5081_i2c_update_bits(
		info,
		RT5081_PMU_REG_CHGCTRL2,
		RT5081_MASK_IINLMTSEL,
		sel << RT5081_SHIFT_IINLMTSEL
	);

	return ret;
}

static bool rt5081_is_hw_exist(struct rt5081_pmu_charger_info *info)
{
	int ret = 0;
	u8 vendor_id = 0, revision = 0;
	u8 data = 0;

	ret = rt5081_i2c_read_byte(info, RT5081_PMU_REG_DEVINFO, &data);
	if (ret != I2C_OK)
		return false;

	vendor_id = data & 0xF0;
	revision = data & 0x0F;

	if (vendor_id != RT5081_VENDOR_ID) {
		dprintf(CRITICAL, "%s: vendor id is incorrect\n", __func__);
		return false;
	}
	dprintf(CRITICAL, "%s: E%d(0x%02X)\n", __func__, revision, revision);

	info->mchr_info.device_id = revision;
	return true;
}

#if 0
/* Set register's value to default */
static int rt5081_chg_reset_chip(struct rt5081_pmu_charger_info *info)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: starts\n", __func__);

	ret = rt5081_set_bit(info, RT5081_PMU_REG_CORECTRL2,
		RT5081_MASK_CHG_RST);

	return ret;
}
#endif

static int rt5081_set_battery_voreg(struct rt5081_pmu_charger_info *info,
	u32 voreg)
{
	int ret = 0;
	u8 reg_voreg = 0;

	reg_voreg = rt5081_find_closest_reg_value(RT5081_BAT_VOREG_MIN,
		RT5081_BAT_VOREG_MAX, RT5081_BAT_VOREG_STEP,
		RT5081_BAT_VOREG_NUM, voreg);

	dprintf(CRITICAL, "%s: bat voreg = %d\n", __func__, voreg);

	ret = rt5081_i2c_update_bits(
		info,
		RT5081_PMU_REG_CHGCTRL4,
		RT5081_MASK_BAT_VOREG,
		reg_voreg << RT5081_SHIFT_BAT_VOREG
	);

	return ret;
}

static inline int rt5081_enable_wdt(struct rt5081_pmu_charger_info *info,
	bool en)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);
	ret = (en ? rt5081_set_bit : rt5081_clr_bit)
		(info, RT5081_PMU_REG_CHGCTRL13, RT5081_MASK_WDT_EN);

	return ret;
}

static int rt5081_enable_jeita(struct rt5081_pmu_charger_info *info,
	bool en)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);
	ret = (en ? rt5081_set_bit : rt5081_clr_bit)
		(info, RT5081_PMU_REG_CHGCTRL16, RT5081_MASK_JEITA_EN);

	return ret;
}

static int rt5081_chg_init_setting(struct rt5081_pmu_charger_info *info)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: starts\n", __func__);

	ret = rt5081_enable_wdt(info, true);
	if (ret < 0)
		dprintf(CRITICAL, "%s: enable wdt failed\n", __func__);

	/* Select input current limit to referenced from AICR */
	ret = rt5081_select_input_current_limit(info,
		RT5081_IINLMTSEL_AICR);
	if (ret < 0)
		dprintf(CRITICAL, "%s: select input current limit failed\n",
			__func__);

	mdelay(5);

	/* Disable HW iinlimit, use SW */
	ret = rt5081_enable_ilim(info, false);
	if (ret < 0)
		dprintf(CRITICAL, "%s: disable ilim failed\n", __func__);

	ret = rt5081_enable_jeita(info, false);
	if (ret < 0)
		dprintf(CRITICAL, "%s: disable jeita failed\n", __func__);

	ret = rt_charger_set_ichg(&info->mchr_info, 2000);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set ichg failed\n", __func__);

	ret = rt_charger_set_aicr(&info->mchr_info, 500);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set aicr failed\n", __func__);

	ret = rt_charger_set_mivr(&info->mchr_info, 4500);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set mivr failed\n", __func__);

	ret = rt5081_set_battery_voreg(info, 4350);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set cv failed\n", __func__);

	return ret;
}

static int rt5081_get_charging_status(struct rt5081_pmu_charger_info *info,
	enum rt5081_charging_status *chg_stat)
{
	int ret = 0;
	u8 data = 0;

	ret = rt5081_i2c_read_byte(info, RT5081_PMU_REG_CHGSTAT, &data);
	if (ret != I2C_OK)
		return ret;

	*chg_stat = (data & RT5081_MASK_CHG_STAT) >> RT5081_SHIFT_CHG_STAT;

	return ret;
}

static int rt5081_get_mivr(struct rt5081_pmu_charger_info *info, u32 *mivr)
{
	int ret = 0;
	u8 reg_mivr = 0;
	u8 data = 0;

	ret = rt5081_i2c_read_byte(info, RT5081_PMU_REG_CHGCTRL6, &data);
	if (ret != I2C_OK)
		return ret;
	reg_mivr = ((data & RT5081_MASK_MIVR) >> RT5081_SHIFT_MIVR) & 0xFF;

	*mivr = rt5081_find_closest_real_value(RT5081_MIVR_MIN, RT5081_MIVR_MAX,
		RT5081_MIVR_STEP, reg_mivr);


	return ret;
}

static int rt5081_is_charging_enable(struct rt5081_pmu_charger_info *info, bool *enable)
{
	int ret = 0;
	u8 data = 0;

	ret = rt5081_i2c_read_byte(info, RT5081_PMU_REG_CHGCTRL2, &data);
	if (ret != I2C_OK)
		return ret;

	if (((data & RT5081_MASK_CHG_EN) >> RT5081_SHIFT_CHG_EN) & 0xFF)
		*enable = true;
	else
		*enable = false;

	return ret;
}

static int rt5081_get_ieoc(struct rt5081_pmu_charger_info *info, u32 *ieoc)
{
	int ret = 0;
	u8 reg_ieoc = 0;
	u8 data = 0;

	ret = rt5081_i2c_read_byte(info, RT5081_PMU_REG_CHGCTRL9, &data);
	if (ret != I2C_OK)
		return ret;

	reg_ieoc = (data & RT5081_MASK_IEOC) >> RT5081_SHIFT_IEOC;
	*ieoc = rt5081_find_closest_real_value(RT5081_IEOC_MIN, RT5081_IEOC_MAX,
		RT5081_IEOC_STEP, reg_ieoc);

	return ret;
}


/* =========================================================== */
/* The following is implementation for interface of rt_charger */
/* =========================================================== */


static int rt_charger_dump_register(struct mtk_charger_info *mchr_info)
{
	int ret = 0;
	u32 i = 0;
	u32 ichg = 0, aicr = 0, mivr = 0, ieoc = 0;
	bool chg_enable = 0;
	enum rt5081_charging_status chg_status = RT5081_CHG_STATUS_READY;
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;
	u8 data = 0;

	ret = rt5081_get_charging_status(info, &chg_status);
	if (chg_status == RT5081_CHG_STATUS_FAULT) {
		info->i2c_log_level = CRITICAL;
		for (i = 0; i < ARRAY_SIZE(rt5081_chg_reg_addr); i++)
			ret = rt5081_i2c_read_byte(info, rt5081_chg_reg_addr[i],
				&data);
	} else
		info->i2c_log_level = INFO;

	ret = rt_charger_get_ichg(mchr_info, &ichg);
	ret = rt5081_get_mivr(info, &mivr);
	ret = rt_charger_get_aicr(mchr_info, &aicr);
	ret = rt5081_get_ieoc(info, &ieoc);
	ret = rt5081_is_charging_enable(info, &chg_enable);

	dprintf(CRITICAL,
		"%s: ICHG = %dmA, AICR = %dmA, MIVR = %dmV, IEOC = %dmA\n",
		__func__, ichg, aicr, mivr, ieoc);

	dprintf(CRITICAL, "%s: CHG_EN = %d, CHG_STATUS = %s\n",
		__func__, chg_enable, rt5081_chg_status_name[chg_status]);

	return ret;
}

static int rt_charger_enable_charging(struct mtk_charger_info *mchr_info,
	bool enable)
{
	int ret = 0;
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;

	ret = (enable ? rt5081_set_bit : rt5081_clr_bit)
		(info, RT5081_PMU_REG_CHGCTRL2, RT5081_MASK_CHG_EN);

	return ret;
}

static int rt_charger_enable_power_path(struct mtk_charger_info *mchr_info,
	bool enable)
{
	int ret = 0;
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;

	dprintf(CRITICAL, "%s: enable = %d\n", __func__, enable);
	ret = (enable ? rt5081_clr_bit : rt5081_set_bit)
		(info, RT5081_PMU_REG_CHGCTRL1, RT5081_MASK_HZ_EN);

	return ret;
}

static int rt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg)
{
	int ret = 0;
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;

	/* Find corresponding reg value */
	u8 reg_ichg = rt5081_find_closest_reg_value(RT5081_ICHG_MIN,
		RT5081_ICHG_MAX, RT5081_ICHG_STEP, RT5081_ICHG_NUM, ichg);

	dprintf(CRITICAL, "%s: ichg = %d\n", __func__, ichg);

	ret = rt5081_i2c_update_bits(
		info,
		RT5081_PMU_REG_CHGCTRL7,
		RT5081_MASK_ICHG,
		reg_ichg << RT5081_SHIFT_ICHG
	);

	return ret;
}

static int rt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr)
{
	int ret = 0;
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;

	/* Find corresponding reg value */
	u8 reg_aicr = rt5081_find_closest_reg_value(RT5081_AICR_MIN,
		RT5081_AICR_MAX, RT5081_AICR_STEP, RT5081_AICR_NUM, aicr);

	dprintf(CRITICAL, "%s: aicr = %d\n", __func__, aicr);

	ret = rt5081_i2c_update_bits(
		info,
		RT5081_PMU_REG_CHGCTRL3,
		RT5081_MASK_AICR,
		reg_aicr << RT5081_SHIFT_AICR
	);

	return ret;
}


static int rt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr)
{
	int ret = 0;
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;

	/* Find corresponding reg value */
	u8 reg_mivr = rt5081_find_closest_reg_value(RT5081_MIVR_MIN,
		RT5081_MIVR_MAX, RT5081_MIVR_STEP, RT5081_MIVR_NUM, mivr);

	dprintf(CRITICAL, "%s: mivr = %d\n", __func__, mivr);

	ret = rt5081_i2c_update_bits(
		info,
		RT5081_PMU_REG_CHGCTRL6,
		RT5081_MASK_MIVR,
		reg_mivr << RT5081_SHIFT_MIVR
	);

	return ret;
}


static int rt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg)
{
	int ret = 0;
	u8 reg_ichg = 0;
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;
	u8 data = 0;

	ret = rt5081_i2c_read_byte(info, RT5081_PMU_REG_CHGCTRL7, &data);
	if (ret != I2C_OK)
		return ret;

	reg_ichg = (data & RT5081_MASK_ICHG) >> RT5081_SHIFT_ICHG;
	*ichg = rt5081_find_closest_real_value(RT5081_ICHG_MIN, RT5081_ICHG_MAX,
		RT5081_ICHG_STEP, reg_ichg);

	return ret;
}

static int rt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr)
{
	int ret = 0;
	u8 reg_aicr = 0;
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;
	u8 data = 0;

	ret = rt5081_i2c_read_byte(info, RT5081_PMU_REG_CHGCTRL3, &data);
	if (ret != I2C_OK)
		return ret;

	reg_aicr = (data & RT5081_MASK_AICR) >> RT5081_SHIFT_AICR;
	*aicr = rt5081_find_closest_real_value(RT5081_AICR_MIN, RT5081_AICR_MAX,
		RT5081_AICR_STEP, reg_aicr);

	return ret;
}

static int rt_charger_reset_pumpx(struct mtk_charger_info *mchr_info,
	bool reset)
{
	int ret = 0;
	u32 aicr = 0;
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;

	rt5081_enable_hidden_mode(info, true);

	ret = (reset ? rt5081_clr_bit : rt5081_set_bit)(info, 0x38, 0x80);
	aicr = (reset ? 100 : 500);
	ret = rt_charger_set_aicr(mchr_info, aicr);

	rt5081_enable_hidden_mode(info, false);
	return ret;
}

static int rt_charger_enable_wdt(struct mtk_charger_info *mchr_info, bool en)
{
	struct rt5081_pmu_charger_info *info =
		(struct rt5081_pmu_charger_info *)mchr_info;
	return rt5081_enable_wdt(info, en);
}

static struct mtk_charger_ops rt5081_mchr_ops = {
	.dump_register = rt_charger_dump_register,
	.enable_charging = rt_charger_enable_charging,
	.get_ichg = rt_charger_get_ichg,
	.set_ichg = rt_charger_set_ichg,
	.set_aicr = rt_charger_set_aicr,
	.set_mivr = rt_charger_set_mivr,
	.enable_power_path = rt_charger_enable_power_path,
	.get_aicr = rt_charger_get_aicr,
	.reset_pumpx = rt_charger_reset_pumpx,
	.enable_wdt = rt_charger_enable_wdt,
};


/* Info of primary charger */
static struct rt5081_pmu_charger_info g_rt5081_pmu_charger_info = {
	.mchr_info = {
		.name = "primary_charger",
		.device_id = -1,
		.mchr_ops = &rt5081_mchr_ops,
	},
	.i2c = {
		.id = I2C_APPM,
		.addr = RT5081_SLAVE_ADDR,
		.mode = HS_MODE,
		.speed = 3400,
	},
	.i2c_log_level = INFO,
};


int rt5081_chg_probe(void)
{
	int ret = 0;

	/* Check primary charger */
	if (rt5081_is_hw_exist(&g_rt5081_pmu_charger_info)) {
		dprintf(CRITICAL, "%s: %s\n", __func__,
			RT5081_PMU_CHARGER_LK_DRV_VERSION);
#if 0
		ret = rt5081_chg_reset_chip(&g_rt5081_pmu_charger_info);
#endif
		ret = rt5081_chg_init_setting(&g_rt5081_pmu_charger_info);
		mtk_charger_set_info(&(g_rt5081_pmu_charger_info.mchr_info));
	}

	return ret;
}

/*
 * Revision Note
 * 1.0.4
 * (1) Add enable_wdt interface
 *
 * 1.0.3
 * (1) Disable/Enable spk mode for pe+
 *
 * 1.0.2
 * (1) Modify sequence of enable_ilim & select iinlimit
 *     and add 5ms delay between these two ops
 *
 * 1.0.1
 * (1) Disable JEITA
 * (2) Enable WDT
 *
 * 1.0.0
 * (1) Initial release
 */
