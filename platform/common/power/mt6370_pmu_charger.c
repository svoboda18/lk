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
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
 * applicable license agreements with MediaTek Inc.
 */

#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <platform/mt_gpt.h>
#include <libfdt.h>
#include <printf.h>
#include <string.h>
#include <lk_builtin_dtb.h>
#include "mt6370_pmu_charger.h"
#include "mtk_charger_intf.h"
#include "mtk_charger.h"

#define MT6370_PMU_CHARGER_LK_DRV_VERSION "1.1.6_MTK"

/* ================= */
/* Internal variable */
/* ================= */

struct mt6370_pmu_charger_info {
	struct mtk_charger_info mchr_info;
	struct mt_i2c_t i2c;
	int i2c_log_level;
	int hidden_mode_cnt;
	u8 vendor_id;
	u32 mivr;
	u32 aicr;
	u32 cv;
	u32 ichg;
	u32 ichg_dis_chg;
	bool chg_en;
};

enum mt6370_charging_status {
	MT6370_CHG_STATUS_READY = 0,
	MT6370_CHG_STATUS_PROGRESS,
	MT6370_CHG_STATUS_DONE,
	MT6370_CHG_STATUS_FAULT,
	MT6370_CHG_STATUS_MAX,
};

/* Charging status name */
static const char *mt6370_chg_status_name[MT6370_CHG_STATUS_MAX] = {
	"ready", "progress", "done", "fault",
};

static const u8 mt6370_val_en_hidden_mode[] = {
	0x96, 0x69, 0xC3, 0x3C,
};

static const u8 mt6370_val_en_test_mode[] = {
	0x69, 0x96, 0x63, 0x70,
};

/* ======================= */
/* Address & Default value */
/* ======================= */

static const u8 mt6370_chg_reg_addr[] = {
	MT6370_PMU_REG_CHGCTRL1,
	MT6370_PMU_REG_CHGCTRL2,
	MT6370_PMU_REG_CHGCTRL3,
	MT6370_PMU_REG_CHGCTRL4,
	MT6370_PMU_REG_CHGCTRL5,
	MT6370_PMU_REG_CHGCTRL6,
	MT6370_PMU_REG_CHGCTRL7,
	MT6370_PMU_REG_CHGCTRL8,
	MT6370_PMU_REG_CHGCTRL9,
	MT6370_PMU_REG_CHGCTRL10,
	MT6370_PMU_REG_CHGCTRL11,
	MT6370_PMU_REG_CHGCTRL12,
	MT6370_PMU_REG_CHGCTRL13,
	MT6370_PMU_REG_CHGCTRL14,
	MT6370_PMU_REG_CHGCTRL15,
	MT6370_PMU_REG_CHGCTRL16,
	MT6370_PMU_REG_CHGADC,
	MT6370_PMU_REG_DEVICETYPE,
	MT6370_PMU_REG_QCCTRL1,
	MT6370_PMU_REG_QCCTRL2,
	MT6370_PMU_REG_QC3P0CTRL1,
	MT6370_PMU_REG_QC3P0CTRL2,
	MT6370_PMU_REG_USBSTATUS1,
	MT6370_PMU_REG_QCSTATUS1,
	MT6370_PMU_REG_QCSTATUS2,
	MT6370_PMU_REG_CHGPUMP,
	MT6370_PMU_REG_CHGCTRL17,
	MT6370_PMU_REG_CHGCTRL18,
	MT6370_PMU_REG_CHGDIRCHG1,
	MT6370_PMU_REG_CHGDIRCHG2,
	MT6370_PMU_REG_CHGDIRCHG3,
	MT6370_PMU_REG_CHGSTAT,
	MT6370_PMU_REG_CHGNTC,
	MT6370_PMU_REG_ADCDATAH,
	MT6370_PMU_REG_ADCDATAL,
	MT6370_PMU_REG_CHGCTRL19,
	MT6370_PMU_REG_CHGSTAT1,
	MT6370_PMU_REG_CHGSTAT2,
	MT6370_PMU_REG_CHGSTAT3,
	MT6370_PMU_REG_CHGSTAT4,
	MT6370_PMU_REG_CHGSTAT5,
	MT6370_PMU_REG_CHGSTAT6,
	MT6370_PMU_REG_QCSTAT,
	MT6370_PMU_REG_DICHGSTAT,
	MT6370_PMU_REG_OVPCTRLSTAT,
};

enum mt6370_iin_limit_sel {
	MT6370_IINLMTSEL_AICR_3250 = 0,
	MT6370_IINLMTSEL_CHR_TYPE,
	MT6370_IINLMTSEL_AICR,
	MT6370_IINLMTSEL_LOWER_LEVEL, /* lower of above three */
};

/* ========================= */
/* I2C operations */
/* ========================= */
static int mt6370_i2c_read_byte(struct mt6370_pmu_charger_info *info, u8 cmd,
				u8 *data)
{
	int ret = 0;
	u8 reg_data = cmd;

	ret = i2c_write_read(&info->i2c, &reg_data, 1, 1);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CR[0x%02X] fail(%d)\n",
				  __func__, cmd, ret);
	else {
		dprintf(info->i2c_log_level, "%s: I2CR[0x%02X] = 0x%02X\n",
					     __func__, cmd, reg_data);
		*data = reg_data;
	}

	return ret;
}

static int mt6370_i2c_write_byte(struct mt6370_pmu_charger_info *info, u8 cmd,
				 u8 data)
{
	int ret = 0;
	u8 write_buf[2] = {cmd, data};

	ret = i2c_write(&info->i2c, write_buf, 2);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CW[0x%02X] = 0x%02X fail(%d)\n",
				  __func__, cmd, data, ret);
	else
		dprintf(info->i2c_log_level, "%s: I2CW[0x%02X] = 0x%02X\n",
					     __func__, cmd, data);

	return ret;
}

static int mt6370_i2c_block_read(struct mt6370_pmu_charger_info *info, u8 cmd,
				 u32 len, u8 *data)
{
	int ret = 0, i = 0;

	data[0] = cmd;

	ret = i2c_write_read(&info->i2c, data, 1, len);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CR[0x%02X..0x%02X] fail(%d)\n",
				  __func__, cmd, cmd + len - 1, ret);
	else
		for (i = 0; i <= len - 1; i++)
			dprintf(info->i2c_log_level,
				"%s: I2CR[0x%02X] = 0x%02X\n",
				__func__, cmd + i, data[i]);

	return ret;
}

static int mt6370_i2c_block_write(struct mt6370_pmu_charger_info *info, u8 cmd,
				  u32 len, const u8 *data)
{
	int ret = 0, i = 0;
	u8 write_buf[len + 1];

	write_buf[0] = cmd;
	memcpy(&write_buf[1], data, len);

	ret = i2c_write(&info->i2c, write_buf, len + 1);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s: fail(%d)\n", __func__, ret);
		for (i = 0; i <= len - 1; i++)
			dprintf(CRITICAL, "%s: I2CW[0x%02X] = 0x%02X\n",
					  __func__, cmd + i, data[i]);
	} else
		for (i = 0; i <= len - 1; i++)
			dprintf(info->i2c_log_level,
				"%s: I2CW[0x%02X] = 0x%02X\n",
				__func__, cmd + i, data[i]);

	return ret;
}

static int mt6370_i2c_update_bits(struct mt6370_pmu_charger_info *info, u8 cmd,
				  u8 mask, u8 data)
{
	int ret = 0;
	u8 reg_data = 0;

	ret = mt6370_i2c_read_byte(info, cmd, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_data &= ~mask;
	reg_data |= (data & mask);

	return mt6370_i2c_write_byte(info, cmd, reg_data);
}

static inline int mt6370_set_bit(struct mt6370_pmu_charger_info *info, u8 cmd,
				 u8 mask)
{
	return mt6370_i2c_update_bits(info, cmd, mask, mask);
}

static inline int mt6370_clr_bit(struct mt6370_pmu_charger_info *info, u8 cmd,
				 u8 mask)
{
	return mt6370_i2c_update_bits(info, cmd, mask, 0x00);
}

/* ================== */
/* internal functions */
/* ================== */
static int mt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg);
static int mt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg);
static int mt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr);
static int mt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr);
static int mt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr);

static u8 mt6370_find_closest_reg_value(const u32 min, const u32 max,
					const u32 step, u32 target)
{
	if (target < min)
		return 0;

	if (target > max)
		target = max;

	return (target - min) / step;
}

static u8 mt6370_find_closest_reg_value_via_table(const u32 *table,
						  const u32 table_size,
						  const u32 target)
{
	u32 i = 0;

	/* Smaller than minimum supported value, use minimum one */
	if (target < table[0])
		return 0;

	for (i = 0; i < table_size - 1; i++) {
		if (target >= table[i] && target < table[i + 1])
			return i;
	}

	/* Greater than maximum supported value, use maximum one */
	return table_size - 1;
}

static u32 mt6370_find_closest_real_value(const u32 min, const u32 max,
					  const u32 step, const u8 reg_val)
{
	u32 ret_val = 0;

	ret_val = min + reg_val * step;
	if (ret_val > max)
		ret_val = max;

	return ret_val;
}

static int mt6370_enable_hidden_mode(struct mt6370_pmu_charger_info *info,
				     bool en)
{
	int ret = 0;

	if (en) {
		if (info->hidden_mode_cnt == 0) {
			ret = mt6370_i2c_block_write(info,
					MT6370_PMU_REG_HIDDENPASCODE1,
					ARRAY_SIZE(mt6370_val_en_hidden_mode),
					mt6370_val_en_hidden_mode);
			if (ret != I2C_OK)
				goto err;
		}
		info->hidden_mode_cnt++;
	} else {
		if (info->hidden_mode_cnt == 1) { /* last one */
			ret = mt6370_i2c_write_byte(info,
					MT6370_PMU_REG_HIDDENPASCODE1, 0x00);
			if (ret != I2C_OK)
				goto err;
		}
		info->hidden_mode_cnt--;
	}
	dprintf(info->i2c_log_level, "%s: en = %d\n", __func__, en);
	goto out;

err:
	dprintf(CRITICAL, "%s: en = %d fail(%d)\n", __func__, en, ret);
out:
	return ret;
}

/* Hardware pin current limit */
static int mt6370_enable_ilim(struct mt6370_pmu_charger_info *info, bool en)
{
	dprintf(info->i2c_log_level, "%s: en = %d\n", __func__, en);

	return (en ? mt6370_set_bit : mt6370_clr_bit)
		(info, MT6370_PMU_REG_CHGCTRL3, MT6370_MASK_ILIM_EN);
}

/* Select IINLMTSEL to use AICR */
static int mt6370_select_input_current_limit(
	struct mt6370_pmu_charger_info *info, enum mt6370_iin_limit_sel sel)
{
	dprintf(info->i2c_log_level, "%s: sel = %d\n", __func__, sel);

	return mt6370_i2c_update_bits(info,
				      MT6370_PMU_REG_CHGCTRL2,
				      MT6370_MASK_IINLMTSEL,
				      sel << MT6370_SHIFT_IINLMTSEL);
}

static bool mt6370_is_hw_exist(struct mt6370_pmu_charger_info *info)
{
	int ret = 0;
	u8 reg_data = 0, vendor_id = 0, chip_rev = 0;

	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_DEVINFO, &reg_data);
	if (ret != I2C_OK)
		return false;

	vendor_id = reg_data & 0xF0;
	chip_rev = reg_data & 0x0F;

	switch (vendor_id) {
	case RT5081_VENDOR_ID:
	case MT6370_VENDOR_ID:
	case MT6371_VENDOR_ID:
	case MT6372_VENDOR_ID:
	case MT6372C_VENDOR_ID:
		break;
	default:
		dprintf(CRITICAL, "%s: vendor id(0x%02X) does not match\n",
				  __func__, vendor_id);
		return false;
	}
	dprintf(CRITICAL, "%s: E%d(0x%02X)\n", __func__, chip_rev, vendor_id);
	info->vendor_id = vendor_id;
	info->mchr_info.device_id = chip_rev;

	return true;
}

static int mt6370_set_battery_voreg(struct mt6370_pmu_charger_info *info,
				    u32 voreg)
{
	u8 reg_voreg = 0;

	reg_voreg = mt6370_find_closest_reg_value(MT6370_BAT_VOREG_MIN,
						  MT6370_BAT_VOREG_MAX,
						  MT6370_BAT_VOREG_STEP,
						  voreg);

	dprintf(info->i2c_log_level, "%s: bat voreg = %d(0x%02X)\n",
				     __func__, voreg, reg_voreg);

	return mt6370_i2c_update_bits(info, MT6370_PMU_REG_CHGCTRL4,
				      MT6370_MASK_BAT_VOREG,
				      reg_voreg << MT6370_SHIFT_BAT_VOREG);
}

static int mt6370_enable_wdt(struct mt6370_pmu_charger_info *info, bool en)
{
	dprintf(info->i2c_log_level, "%s: en = %d\n", __func__, en);

	return (en ? mt6370_set_bit : mt6370_clr_bit)
		(info, MT6370_PMU_REG_CHGCTRL13, MT6370_MASK_WDT_EN);
}

static int mt6370_sw_workaround(struct mt6370_pmu_charger_info *info)
{
	int ret = 0, tm_try_leave_cnt = 5;
	u8 reg_data = 0;

	dprintf(info->i2c_log_level, "%s\n", __func__);

	if (info->vendor_id != MT6371_VENDOR_ID)
		return ret;

	/* check whether trim or not */
	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_TM_INF, &reg_data);
	if (ret != I2C_OK)
		return ret;
	if (reg_data & MT6370_MASK_PMU_ID) {
		dprintf(CRITICAL, "%s: not to trim again\n", __func__);
		return ret;
	}

	/* Enter test mode */
	ret = mt6370_i2c_block_write(info, MT6370_PMU_REG_TM_PAS_CODE1,
				     ARRAY_SIZE(mt6370_val_en_test_mode),
				     mt6370_val_en_test_mode);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s: enter test mode fail(%d)\n",
				  __func__, ret);
		return ret;
	}

	udelay(500);

	ret = mt6370_i2c_write_byte(info, MT6370_PMU_REG_BANK_REG,
				    MT6370_TM_BANK_REG);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s: switch to test mode bank fail(%d)\n",
				  __func__, ret);
		goto out;
	}

	udelay(500);

	/* update icc-1A trim code */
	ret = mt6370_i2c_read_byte(info, MT6370_TM_REG_ICC_1A, &reg_data);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s: read icc trim fail(%d)\n",
				  __func__, ret);
		goto out;
	} else
		dprintf(info->i2c_log_level, "%s: TM reg0x%02X = 0x%02X\n",
					     __func__, MT6370_TM_REG_ICC_1A,
					     reg_data);

	if (reg_data + 7 > 255)
		reg_data = 255;
	else
		reg_data += 7;

	ret = mt6370_i2c_write_byte(info, MT6370_TM_REG_ICC_1A, reg_data);
	if (ret != I2C_OK) {
		dprintf(CRITICAL,
			"%s: write icc trim fail(%d)\n", __func__, ret);
		goto out;
	}

	udelay(500);

	ret = mt6370_i2c_read_byte(info, MT6370_TM_REG_ICC_1A, &reg_data);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s: read icc trim fail(%d)\n",
				  __func__, ret);
		goto out;
	} else
		dprintf(info->i2c_log_level, "%s: TM reg0x%02X = 0x%02X\n",
					     __func__, MT6370_TM_REG_ICC_1A,
					     reg_data);

	if (info->mchr_info.device_id >= 0x04)
		goto skip_pp_short_protection_threshold_trim;

	/* set pp short protection threshold to 150mV */
	ret = mt6370_i2c_update_bits(info, 0x34, 0xC0, 0x80);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: set pp short protection fail(%d)\n",
				  __func__, ret);

	udelay(500);

skip_pp_short_protection_threshold_trim:
	/* update trim complete flag */
	ret = mt6370_set_bit(info, MT6370_TM_REG_TM_INF, MT6370_MASK_TM_ID);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: update trim complete flag fail(%d)\n",
				  __func__, ret);
out:
	udelay(500);
	do {
		ret = mt6370_i2c_write_byte(info, MT6370_PMU_REG_TM_PAS_CODE1,
						  0x00);
		if (ret != I2C_OK) {
			dprintf(CRITICAL, "%s: leave test mode fail(%d)\n",
					  __func__, ret);
			tm_try_leave_cnt--;
		} else
			break;
	} while (tm_try_leave_cnt > 0);

	return ret;
}

static int mt6370_enable_jeita(struct mt6370_pmu_charger_info *info, bool en)
{
	dprintf(info->i2c_log_level, "%s: en = %d\n", __func__, en);

	return (en ? mt6370_set_bit : mt6370_clr_bit)
		(info, MT6370_PMU_REG_CHGCTRL16, MT6370_MASK_JEITA_EN);
}

static int mt6370_chg_init_setting(struct mt6370_pmu_charger_info *info)
{
	int ret = 0;

	dprintf(info->i2c_log_level, "%s: starts\n", __func__);

	ret = mt6370_enable_wdt(info, true);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: enable wdt fail(%d)\n", __func__, ret);

	ret = mt6370_sw_workaround(info);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: sw workaround fail(%d)\n",
				  __func__, ret);

	/* Select input current limit to referenced from AICR */
	ret = mt6370_select_input_current_limit(info, MT6370_IINLMTSEL_AICR);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: select input current limit fail(%d)\n",
				  __func__, ret);

	mdelay(5);

	/* Disable HW iinlimit, use SW */
	ret = mt6370_enable_ilim(info, false);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: disable ilim fail(%d)\n", __func__, ret);

	ret = mt6370_enable_jeita(info, false);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: disable jeita fail(%d)\n",
				  __func__, ret);

	ret = mt_charger_set_mivr(&info->mchr_info, info->mivr);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: set mivr fail(%d)\n", __func__, ret);

	ret = mt_charger_set_aicr(&info->mchr_info, info->aicr);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: set aicr fail(%d)\n", __func__, ret);

	ret = mt6370_set_battery_voreg(info, info->cv);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: set cv fail(%d)\n", __func__, ret);

	ret = mt_charger_set_ichg(&info->mchr_info, info->ichg);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: set ichg fail(%d)\n", __func__, ret);

	return ret;
}

static int mt6370_get_charging_status(struct mt6370_pmu_charger_info *info,
				      enum mt6370_charging_status *chg_stat)
{
	int ret = 0;
	u8 reg_data = 0;

	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_CHGSTAT, &reg_data);
	if (ret != I2C_OK)
		return ret;

	*chg_stat = (reg_data & MT6370_MASK_CHG_STAT) >> MT6370_SHIFT_CHG_STAT;

	return ret;
}

static int mt6370_get_mivr(struct mt6370_pmu_charger_info *info, u32 *mivr)
{
	int ret = 0;
	u8 reg_data = 0, reg_mivr = 0;

	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_CHGCTRL6, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_mivr = (reg_data & MT6370_MASK_MIVR) >> MT6370_SHIFT_MIVR;
	*mivr = mt6370_find_closest_real_value(MT6370_MIVR_MIN, MT6370_MIVR_MAX,
					       MT6370_MIVR_STEP, reg_mivr);

	return ret;
}

static int mt6370_is_charging_enable(struct mt6370_pmu_charger_info *info,
				     bool *en)
{
	int ret = 0;
	u8 reg_data = 0;

	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_CHGCTRL2, &reg_data);
	if (ret != I2C_OK)
		return ret;

	*en = (reg_data & MT6370_MASK_CHG_EN) ? true : false;

	return ret;
}

static int mt6370_get_ieoc(struct mt6370_pmu_charger_info *info, u32 *ieoc)
{
	int ret = 0;
	u8 reg_data = 0, reg_ieoc = 0;

	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_CHGCTRL9, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_ieoc = (reg_data & MT6370_MASK_IEOC) >> MT6370_SHIFT_IEOC;
	*ieoc = mt6370_find_closest_real_value(MT6370_IEOC_MIN, MT6370_IEOC_MAX,
					       MT6370_IEOC_STEP, reg_ieoc);

	return ret;
}

static int mt6370_get_battery_voreg(struct mt6370_pmu_charger_info *info,
				    u32 *cv)
{
	int ret = 0;
	u8 reg_data = 0, reg_cv = 0;

	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_CHGCTRL4, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_cv = (reg_data & MT6370_MASK_BAT_VOREG) >> MT6370_SHIFT_BAT_VOREG;
	*cv = mt6370_find_closest_real_value(MT6370_BAT_VOREG_MIN,
					     MT6370_BAT_VOREG_MAX,
					     MT6370_BAT_VOREG_STEP, reg_cv);

	return ret;
}

/* =========================================================== */
/* The following is implementation for interface of mt_charger */
/* =========================================================== */

static int mt_charger_dump_register(struct mtk_charger_info *mchr_info)
{
	int i = 0, ret = 0;
	u32 ichg = 0, aicr = 0, mivr = 0, ieoc = 0, cv = 0;
	bool chg_en = false;
	enum mt6370_charging_status chg_status = MT6370_CHG_STATUS_READY;
	u8 chg_stat1 = 0, chg_ctrl[2] = {0}, reg_data = 0;
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;

	ret = mt6370_get_charging_status(info, &chg_status);
	if (chg_status == MT6370_CHG_STATUS_FAULT) {
		info->i2c_log_level = CRITICAL;
		for (i = 0; i < ARRAY_SIZE(mt6370_chg_reg_addr); i++)
			ret = mt6370_i2c_read_byte(info, mt6370_chg_reg_addr[i],
						   &reg_data);
	} else
		info->i2c_log_level = INFO;

	ret = mt_charger_get_ichg(mchr_info, &ichg);
	ret = mt_charger_get_aicr(mchr_info, &aicr);
	ret = mt6370_get_mivr(info, &mivr);
	ret = mt6370_get_ieoc(info, &ieoc);
	ret = mt6370_get_battery_voreg(info, &cv);
	ret = mt6370_is_charging_enable(info, &chg_en);
	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_CHGSTAT1, &chg_stat1);
	ret = mt6370_i2c_block_read(info, MT6370_PMU_REG_CHGCTRL1,
				    sizeof(chg_ctrl), chg_ctrl);

	dprintf(CRITICAL,
	"%s: ICHG = %dmA, AICR = %dmA, MIVR = %dmV, IEOC = %dmA, CV = %dmV\n",
	__func__, ichg, aicr, mivr, ieoc, cv);

	dprintf(CRITICAL,
	"%s: CHG_EN = %d, CHG_STATUS = %s, CHG_STAT1 = 0x%02X\n",
	__func__, chg_en, mt6370_chg_status_name[chg_status], chg_stat1);

	dprintf(CRITICAL,
	"%s: CHG_CTRL1 = 0x%02X, CHG_CTRL2 = 0x%02X\n",
	__func__, chg_ctrl[0], chg_ctrl[1]);

	return ret;
}

static int mt_charger_enable_charging(struct mtk_charger_info *mchr_info,
				      bool en)
{
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;
	int ret = 0;
	u32 ichg_ramp_t = 0;

	if (info->chg_en == en) {
		dprintf(CRITICAL,
			"%s: is the same, en = %d\n", __func__, en);
		return ret;
	}
	dprintf(info->i2c_log_level, "%s: en = %d\n", __func__, en);

	/* Workaround for avoiding vsys overshoot when charge disable */
	if (!en) {
		if (info->ichg <= 500)
			goto skip_setting_ichg;
		info->ichg_dis_chg = info->ichg;
		ichg_ramp_t = (info->ichg - 500) / 50 * 2;
		/* Set ichg 500mA */
		ret = mt6370_i2c_update_bits(info,
					     MT6370_PMU_REG_CHGCTRL7,
					     MT6370_MASK_ICHG,
					     0x04 << MT6370_SHIFT_ICHG);
		if (ret != I2C_OK) {
			dprintf(CRITICAL, "%s: set ichg fail(%d)\n",
					  __func__, ret);
			return ret;
		}
		mdelay(ichg_ramp_t);
	} else {
		if (info->ichg == info->ichg_dis_chg) {
			ret = mt_charger_set_ichg(mchr_info, info->ichg);
			if (ret != I2C_OK) {
				dprintf(CRITICAL, "%s: set ichg fail(%d)\n",
						  __func__, ret);
				return ret;
			}
		}
	}
skip_setting_ichg:
	mt6370_enable_hidden_mode(info, true);

	/* Workaround for Iprechg 150mA drop to 40mA */
	if (!en) {
		ret = mt6370_clr_bit(info, MT6370_PMU_REG_CHGHIDDENCTRL9,
				     MT6370_MASK_EN_PSK);
		if (ret != I2C_OK) {
			dprintf(CRITICAL, "%s: disable psk mode fail(%d)\n",
					  __func__, ret);
			goto out;
		}
	}

	ret = (en ? mt6370_set_bit : mt6370_clr_bit)
		(info, MT6370_PMU_REG_CHGCTRL2, MT6370_MASK_CHG_EN);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s: fail(%d), en = %d\n", __func__, ret, en);
		goto out;
	}

	if (en) {
		ret = mt6370_set_bit(info, MT6370_PMU_REG_CHGHIDDENCTRL9,
				     MT6370_MASK_EN_PSK);
		if (ret != I2C_OK)
			dprintf(CRITICAL, "%s: enable psk mode fail(%d)\n",
					  __func__, ret);
	}

	info->chg_en = en;
out:
	mt6370_enable_hidden_mode(info, false);
	return ret;
}

static int mt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg)
{
	int ret = 0;
	u8 reg_data = 0, reg_ichg = 0;
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;

	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_CHGCTRL7, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_ichg = (reg_data & MT6370_MASK_ICHG) >> MT6370_SHIFT_ICHG;
	*ichg = mt6370_find_closest_real_value(MT6370_ICHG_MIN, MT6370_ICHG_MAX,
					       MT6370_ICHG_STEP, reg_ichg);

	return ret;
}

static int mt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg)
{
	int ret = 0;
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;

	u8 reg_ichg = mt6370_find_closest_reg_value(MT6370_ICHG_MIN,
						    MT6370_ICHG_MAX,
						    MT6370_ICHG_STEP, ichg);

	dprintf(info->i2c_log_level, "%s: ichg = %d(0x%02X)\n",
				     __func__, ichg, reg_ichg);

	ret = mt6370_i2c_update_bits(info, MT6370_PMU_REG_CHGCTRL7,
				     MT6370_MASK_ICHG,
				     reg_ichg << MT6370_SHIFT_ICHG);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: fail(%d)\n", __func__, ret);
	else
		info->ichg = ichg;

	return ret;
}

static int mt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr)
{
	int ret = 0;
	u8 reg_data = 0, reg_aicr = 0;
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;

	ret = mt6370_i2c_read_byte(info, MT6370_PMU_REG_CHGCTRL3, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_aicr = (reg_data & MT6370_MASK_AICR) >> MT6370_SHIFT_AICR;
	*aicr = mt6370_find_closest_real_value(MT6370_AICR_MIN, MT6370_AICR_MAX,
					       MT6370_AICR_STEP, reg_aicr);

	return ret;
}

static int mt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr)
{
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;

	u8 reg_aicr = mt6370_find_closest_reg_value(MT6370_AICR_MIN,
						    MT6370_AICR_MAX,
						    MT6370_AICR_STEP, aicr);

	dprintf(info->i2c_log_level, "%s: aicr = %d(0x%02X)\n",
				     __func__, aicr, reg_aicr);

	return mt6370_i2c_update_bits(info, MT6370_PMU_REG_CHGCTRL3,
				      MT6370_MASK_AICR,
				      reg_aicr << MT6370_SHIFT_AICR);
}

static int mt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr)
{
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;

	u8 reg_mivr = mt6370_find_closest_reg_value(MT6370_MIVR_MIN,
						    MT6370_MIVR_MAX,
						    MT6370_MIVR_STEP, mivr);

	dprintf(info->i2c_log_level, "%s: mivr = %d(0x%02X)\n",
				     __func__, mivr, reg_mivr);

	return mt6370_i2c_update_bits(info, MT6370_PMU_REG_CHGCTRL6,
				      MT6370_MASK_MIVR,
				      reg_mivr << MT6370_SHIFT_MIVR);
}

static int mt_charger_enable_power_path(struct mtk_charger_info *mchr_info,
					bool en)
{
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;

	dprintf(info->i2c_log_level, "%s: en = %d\n", __func__, en);

	return (en ? mt6370_clr_bit : mt6370_set_bit)
		(info, MT6370_PMU_REG_CHGCTRL1, MT6370_MASK_HZ_EN);
}

static int mt_charger_reset_pumpx(struct mtk_charger_info *mchr_info, bool en)
{
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;

	mt6370_enable_hidden_mode(info, true);
	(en ? mt6370_clr_bit : mt6370_set_bit)
	 (info, MT6370_PMU_REG_CHGHIDDENCTRL9, MT6370_MASK_EN_PSK);
	mt6370_enable_hidden_mode(info, false);

	return mt_charger_set_aicr(mchr_info, en ? 100 : info->aicr);
}

static int mt_charger_enable_wdt(struct mtk_charger_info *mchr_info, bool en)
{
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;
	return mt6370_enable_wdt(info, en);
}

static int mt_charger_reset_wdt(struct mtk_charger_info *mchr_info)
{
	/* Any I2C communication can kick watchdog timer */
	enum mt6370_charging_status chg_status = MT6370_CHG_STATUS_READY;
	struct mt6370_pmu_charger_info *info =
		(struct mt6370_pmu_charger_info *)mchr_info;

	return mt6370_get_charging_status(info, &chg_status);
}

static struct mtk_charger_ops mt6370_mchr_ops = {
	.dump_register = mt_charger_dump_register,
	.enable_charging = mt_charger_enable_charging,
	.get_ichg = mt_charger_get_ichg,
	.set_ichg = mt_charger_set_ichg,
	.get_aicr = mt_charger_get_aicr,
	.set_aicr = mt_charger_set_aicr,
	.set_mivr = mt_charger_set_mivr,
	.enable_power_path = mt_charger_enable_power_path,
	.reset_pumpx = mt_charger_reset_pumpx,
	.enable_wdt = mt_charger_enable_wdt,
	.reset_wdt = mt_charger_reset_wdt,
	.check_charging_mode = mt_charger_dump_register,
};

/* Info of primary charger */
static struct mt6370_pmu_charger_info g_mt6370_pmu_charger_info = {
	.mchr_info = {
		.name = "primary_charger",
		.alias_name = "mt6370_charger",
		.device_id = -1,
		.mchr_ops = &mt6370_mchr_ops,
	},
	.i2c = {
		.id = I2C5,
		.addr = MT6370_SLAVE_ADDR,
		.mode = FS_MODE,
		.speed = 400,
		.pushpull = false,
	},
	.i2c_log_level = INFO,
	.hidden_mode_cnt = 0,
	.vendor_id = 0x00,
	.mivr = 4400,
	.aicr = 500,
	.cv = 4350,
	/* Set ichg 500mA for vsys overshoot */
	.ichg = 500,
	.ichg_dis_chg = 2000,
	.chg_en = true,
};

static int mt6370_parse_dt(struct mt6370_pmu_charger_info *info)
{
	int offset = 0, sub_offset = 0;
	u32 val = 0;
	void *fdt = get_lk_overlayed_dtb();

	offset = fdt_node_offset_by_compatible(fdt, -1, "mediatek,subpmic_pmu");
	sub_offset = fdt_parent_offset(fdt, offset);
	if (offset >= 0 && sub_offset >= 0) {
		val = chr_fdt_getprop_u32(fdt, sub_offset, "id");
		if (val) {
			info->i2c.id = val;
			dprintf(CRITICAL, "%s: subpmic_pmu id = %d\n",
					  __func__, info->i2c.id);
		}
	}

	return 0;
}

int mt6370_chg_probe(void)
{
	int ret = 0;

	dprintf(INFO, "%s: (%s)\n",
		      __func__, MT6370_PMU_CHARGER_LK_DRV_VERSION);

	ret = mt6370_parse_dt(&g_mt6370_pmu_charger_info);
	if (ret < 0)
		return ret;

	if (!mt6370_is_hw_exist(&g_mt6370_pmu_charger_info))
		return -ENODEV;

	ret = mt6370_chg_init_setting(&g_mt6370_pmu_charger_info);
	if (ret != I2C_OK)
		return ret;

	ret = mtk_charger_set_info(&g_mt6370_pmu_charger_info.mchr_info);
	if (ret < 0)
		return ret;

	mt_charger_dump_register(&g_mt6370_pmu_charger_info.mchr_info);
	dprintf(INFO, "%s: successfully\n", __func__);
	return 0;
}

/*
 * Release Note
 * 1.1.6
 * (1) Merge sw workarounds into mt6370_sw_workaround()
 * (2) Do not do the workaround for VSYS overshoot if ichg <= 500mA
 *
 * 1.1.5
 * (1) Decrease I2C speed from 3400Hz to 400Hz
 * (2) Do not delay for vsys overshoot if ichg <= 500mA
 * (3) Add log for I2C block read/write
 *
 * 1.1.4
 * (1) Do not run mt6370_enable_pp_short_protect() for MT6372
 * (2) Add more information for mt_charger_dump_register()
 * (3) Increase tm_try_leave_cnt from 2 to 5
 * (4) Add more delay in test mode
 *
 * 1.1.3
 * (1) Add support for MT6372
 * (2) Add workarounds for ICHG accuracy and VSYS overshoot
 *
 * 1.1.2
 * (1) Add Iprechg 150mA drop to 40mA workaround
 *
 * 1.1.1
 * (1) Add initial setting about enable pp short protection
 * when use before MT6371 chip E4 version.
 *
 * 1.1.0
 * (1) Initial release for compatible with MT6370 & MT6371 driver.
 * (2) Move to common folder reduce porting effort.
 * (3) Parse subpmic i2c channel from dts.
 */
