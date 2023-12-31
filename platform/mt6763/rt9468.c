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
#include <platform/rt9468.h>
#include <platform/mtk_charger_intf.h>
#include <printf.h>

#if !defined(CONFIG_POWER_EXT)
#include <platform/upmu_common.h>
#endif

#define RT9468_LK_DRV_VERSION "1.0.0_MTK"

/* ================= */
/* Internal variable */
/* ================= */

struct rt9468_info {
	struct mtk_charger_info mchr_info;
	struct mt_i2c_t i2c;
	int i2c_log_level;
};

enum rt9468_charging_status {
	RT9468_CHG_STATUS_READY = 0,
	RT9468_CHG_STATUS_PROGRESS,
	RT9468_CHG_STATUS_DONE,
	RT9468_CHG_STATUS_FAULT,
	RT9468_CHG_STATUS_MAX,
};

enum rt9468_iin_limit_sel {
	RT9468_IIMLMTSEL_CHR_TYPE = 1,
	RT9468_IINLMTSEL_AICR = 2,
	RT9468_IINLMTSEL_LOWER_LEVEL, /* lower of above two */
};

/* Charging status name */
static const char *rt9468_chg_status_name[RT9468_CHG_STATUS_MAX] = {
	"ready", "progress", "done", "fault",
};


/* ======================= */
/* RT9468 Register Address */
/* ======================= */


static const unsigned char rt9468_reg_addr[] = {
	RT9468_REG_CORE_CTRL0,
	RT9468_REG_CHG_CTRL1,
	RT9468_REG_CHG_CTRL2,
	RT9468_REG_CHG_CTRL3,
	RT9468_REG_CHG_CTRL4,
	RT9468_REG_CHG_CTRL5,
	RT9468_REG_CHG_CTRL6,
	RT9468_REG_CHG_CTRL7,
	RT9468_REG_CHG_CTRL8,
	RT9468_REG_CHG_CTRL9,
	RT9468_REG_CHG_CTRL10,
	RT9468_REG_CHG_CTRL11,
	RT9468_REG_CHG_CTRL12,
	RT9468_REG_CHG_CTRL13,
	RT9468_REG_CHG_CTRL14,
	RT9468_REG_CHG_CTRL15,
	RT9468_REG_CHG_CTRL16,
	RT9468_REG_CHG_ADC,
	RT9468_REG_CHG_DPDM1,
	RT9468_REG_CHG_DPDM2,
	RT9468_REG_CHG_DPDM3,
	RT9468_REG_CHG_DPDM4,
	RT9468_REG_CHG_DPDM5,
	RT9468_REG_CHG_DPDM6,
	RT9468_REG_CHG_PUMP,
	RT9468_REG_CHG_CTRL17,
	RT9468_REG_CHG_CTRL18,
	RT9468_REG_CHG_DIRCHG1,
	RT9468_REG_CHG_DIRCHG2,
	RT9468_REG_CHG_DIRCHG3,
	RT9468_REG_CHG_DPDM7,
	RT9468_REG_CHG_DPDM8,
	RT9468_REG_DEVICE_ID,
	RT9468_REG_CHG_STAT,
	RT9468_REG_CHG_NTC,
	RT9468_REG_ADC_DATA_H,
	RT9468_REG_ADC_DATA_L,
	RT9468_REG_CHG_STATC,
	RT9468_REG_CHG_FAULT,
	RT9468_REG_TS_STATC,
	RT9468_REG_CHG_IRQ1,
	RT9468_REG_CHG_IRQ2,
	RT9468_REG_CHG_IRQ3,
	RT9468_REG_DPDM_IRQ,
	RT9468_REG_CHG_IRQ5,
	RT9468_REG_CHG_STATC_CTRL,
	RT9468_REG_CHG_FAULT_CTRL,
	RT9468_REG_TS_STATC_CTRL,
	RT9468_REG_CHG_IRQ1_CTRL,
	RT9468_REG_CHG_IRQ2_CTRL,
	RT9468_REG_CHG_IRQ3_CTRL,
	RT9468_REG_DPDM_IRQ_CTRL,
	RT9468_REG_CHG_IRQ5_CTRL,
};

/* ========================= */
/* I2C operations */
/* ========================= */

static int rt9468_i2c_write_byte(struct rt9468_info *info, u8 cmd, u8 data)
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


static int rt9468_i2c_read_byte(struct rt9468_info *info, u8 cmd, u8 *data)
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

static int rt9468_i2c_test_bit(struct rt9468_info *info, u8 cmd, u8 shift)
{
	int ret = 0;
	u8 data = 0;

	ret = rt9468_i2c_read_byte(info, cmd, &data);
	if (ret != I2C_OK)
		return ret;

	ret = data & (1 << shift);

	return ret;
}

static int rt9468_i2c_update_bits(struct rt9468_info *info, u8 cmd, u8 data,
	u8 mask)
{
	int ret = 0;
	u8 reg_data = 0;

	ret = rt9468_i2c_read_byte(info, cmd, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_data = reg_data & 0xFF;
	reg_data &= ~mask;
	reg_data |= (data & mask);

	return rt9468_i2c_write_byte(info, cmd, reg_data);
}

static inline int rt9468_set_bit(struct rt9468_info *info, u8 reg, u8 mask)
{
    return rt9468_i2c_update_bits(info, reg, mask, mask);
}

static inline int rt9468_clr_bit(struct rt9468_info *info, u8 reg, u8 mask)
{
    return rt9468_i2c_update_bits(info, reg, 0x00, mask);
}

/* ================== */
/* internal functions */
/* ================== */
static int rt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg);
static int rt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr);
static int rt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr);
static int rt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg);
static int rt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr);

static u8 rt9468_find_closest_reg_value(const u32 min, const u32 max,
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

static u8 rt9468_find_closest_reg_value_via_table(const u32 *value_table,
	const u32 table_size, const u32 target_value)
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

static u32 rt9468_find_closest_real_value(const u32 min, const u32 max,
	const u32 step, const u8 reg_val)
{
	u32 ret_val = 0;

	ret_val = min + reg_val * step;
	if (ret_val > max)
		ret_val = max;

	return ret_val;
}


/* Hardware pin current limit */
static int rt9468_enable_ilim(struct rt9468_info *info, bool enable)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: enable ilim = %d\n", __func__, enable);

	ret = (enable ? rt9468_set_bit : rt9468_clr_bit)
		(info, RT9468_REG_CHG_CTRL3, RT9468_MASK_ILIM_EN);

	return ret;
}

/* Select IINLMTSEL to use AICR */
static int rt9468_select_input_current_limit(struct rt9468_info *info,
	enum rt9468_iin_limit_sel sel)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: select input current limit = %d\n",
		__func__, sel);

	ret = rt9468_i2c_update_bits(
		info,
		RT9468_REG_CHG_CTRL2,
		sel << RT9468_SHIFT_IINLMTSEL,
		RT9468_MASK_IINLMTSEL);

	return ret;
}

static int rt9468_set_battery_voreg(struct rt9468_info *info, u32 voreg)
{
	int ret = 0;
	u8 reg_voreg = 0;

	reg_voreg = rt9468_find_closest_reg_value(RT9468_BAT_VOREG_MIN,
		RT9468_BAT_VOREG_MAX, RT9468_BAT_VOREG_STEP,
		RT9468_BAT_VOREG_NUM, voreg);

	dprintf(CRITICAL, "%s: bat voreg = %d\n", __func__, voreg);

	ret = rt9468_i2c_update_bits(
		info,
		RT9468_REG_CHG_CTRL4,
		reg_voreg << RT9468_SHIFT_BAT_VOREG,
		RT9468_MASK_BAT_VOREG
	);

	return ret;
}

static int rt9468_mask_all_irq(struct rt9468_info *info)
{
	int i = 0, ret = 0;

	for (i = RT9468_REG_CHG_STATC_CTRL; i <= RT9468_REG_DPDM_IRQ_CTRL; i++) {
		ret = rt9468_i2c_write_byte(info, i, 0xFF);
		if (ret != I2C_OK)
			dprintf(CRITICAL,
				"%s: mask irq 0x%02X failed, ret = %d\n",
				__func__, i, ret);
	}

	/* This one is not continuous */
	ret = rt9468_i2c_write_byte(info, RT9468_REG_CHG_IRQ5_CTRL, 0xFF);
	dprintf(CRITICAL, "%s: mask irq 0x%02X failed, ret = %d\n",
		__func__, RT9468_REG_CHG_IRQ5_CTRL, ret);

	return ret;
}


static int rt9468_sw_init(struct rt9468_info *info)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: starts\n", __func__);

	/* Mask all irq */
	ret = rt9468_mask_all_irq(info);
	if (ret < 0)
		dprintf(CRITICAL, "%s: mask all irq failed\n", __func__);


	ret = rt9468_enable_ilim(info, false);
	if (ret < 0)
		dprintf(CRITICAL, "%s: disable ilim failed\n", __func__);

	/* Select input current limit to referenced from AICR */
	ret = rt9468_select_input_current_limit(info, RT9468_IINLMTSEL_AICR);
	if (ret < 0)
		dprintf(CRITICAL, "%s: select input current limit failed\n",
			__func__);

	ret = rt_charger_set_ichg(&info->mchr_info, 2000);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set ichg failed\n", __func__);

	ret = rt_charger_set_aicr(&info->mchr_info, 500);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set aicr failed\n", __func__);

	ret = rt_charger_set_mivr(&info->mchr_info, 4500);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set mivr failed\n", __func__);

	ret = rt9468_set_battery_voreg(info, 4350);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set voreg failed\n", __func__);

	return ret;
}

static int rt9468_get_charging_status(struct rt9468_info *info,
	enum rt9468_charging_status *chg_stat)
{
	int ret = 0;
	u8 data = 0;

	ret = rt9468_i2c_read_byte(info, RT9468_REG_CHG_STAT, &data);
	if (ret != I2C_OK)
		return ret;

	*chg_stat = (data & RT9468_MASK_CHG_STAT) >> RT9468_SHIFT_CHG_STAT;

	return ret;
}

static int rt9468_get_ieoc(struct rt9468_info *info, u32 *ieoc)
{
	int ret = 0;
	u8 reg_ieoc = 0;
	u8 data = 0;

	ret = rt9468_i2c_read_byte(info, RT9468_REG_CHG_CTRL9, &data);
	if (ret != I2C_OK)
		return ret;

	reg_ieoc = (data & RT9468_MASK_IEOC) >> RT9468_SHIFT_IEOC;
	*ieoc = rt9468_find_closest_real_value(RT9468_IEOC_MIN, RT9468_IEOC_MAX,
		RT9468_IEOC_STEP, reg_ieoc);

	return ret;
}

static bool rt9468_is_hw_exist(struct rt9468_info *info)
{
	int ret = 0;
	u8 revision = 0;
	u8 data = 0;

	ret = rt9468_i2c_read_byte(info, RT9468_REG_DEVICE_ID, &data);
	if (ret != I2C_OK)
		return false;

	revision = data & 0xFF;
	if (revision == RT9468_DEVICE_ID_E2)
		dprintf(CRITICAL, "%s: rt9468 E2 revision\n", __func__);
	else if (revision == RT9468_DEVICE_ID_E3)
		dprintf(CRITICAL, "%s: rt9468 E3 revision\n", __func__);
	else
		return false;

	info->mchr_info.device_id = revision;
	return true;
}

static int rt9468_is_charging_enable(struct rt9468_info *info, bool *enable)
{
	int ret = 0;
	u8 data = 0;

	ret = rt9468_i2c_read_byte(info, RT9468_REG_CHG_CTRL2, &data);
	if (ret != I2C_OK)
		return ret;

	if (((data & RT9468_MASK_CHG_EN) >> RT9468_SHIFT_CHG_EN) & 0xFF)
		*enable = true;
	else
		*enable = false;

	return ret;
}

static int rt9468_get_mivr(struct rt9468_info *info, u32 *mivr)
{
	int ret = 0;
	u8 reg_mivr = 0;
	u8 data = 0;

	ret = rt9468_i2c_read_byte(info, RT9468_REG_CHG_CTRL6, &data);
	if (ret != I2C_OK)
		return ret;

	reg_mivr = ((data & RT9468_MASK_MIVR) >> RT9468_SHIFT_MIVR) & 0xFF;

	*mivr = rt9468_find_closest_real_value(RT9468_MIVR_MIN, RT9468_MIVR_MAX,
		RT9468_MIVR_STEP, reg_mivr);

	return ret;
}

/* Set register's value to default */
static int rt9468_hw_init(struct rt9468_info *info)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: starts\n", __func__);

	ret = rt9468_set_bit(info, RT9468_REG_CORE_CTRL0, RT9468_MASK_RST);

	return ret;
}

/* =========================================================== */
/* The following is implementation for interface of rt_charger */
/* =========================================================== */


static int rt_charger_dump_register(struct mtk_charger_info *mchr_info)
{
	int i = 0, ret = 0;
	u32 ichg = 0, aicr = 0, mivr = 0, ieoc = 0;
	bool chg_enable = 0;
	enum rt9468_charging_status chg_status = RT9468_CHG_STATUS_READY;
	struct rt9468_info *info = (struct rt9468_info *)mchr_info;
	u8 data = 0;

	ret = rt9468_get_charging_status(info, &chg_status);
	if (chg_status == RT9468_CHG_STATUS_FAULT) {
		info->i2c_log_level = CRITICAL;
		for (i = 0; i < ARRAY_SIZE(rt9468_reg_addr); i++) {
			ret = rt9468_i2c_read_byte(info, rt9468_reg_addr[i],
				&data);
			if (ret != I2C_OK)
				return ret;
		}
	} else
		info->i2c_log_level = INFO;


	ret = rt_charger_get_ichg(&info->mchr_info, &ichg);
	ret = rt9468_get_mivr(info, &mivr);
	ret = rt_charger_get_aicr(&info->mchr_info, &aicr);
	ret = rt9468_get_ieoc(info, &ieoc);
	ret = rt9468_is_charging_enable(info, &chg_enable);

	dprintf(CRITICAL,
		"%s: ICHG = %dmA, AICR = %dmA, MIVR = %dmV, IEOC = %dmA\n",
		__func__, ichg, aicr, mivr, ieoc);

	dprintf(CRITICAL, "%s: CHG_EN = %d, CHG_STATUS = %s\n",
		__func__, chg_enable, rt9468_chg_status_name[chg_status]);

	return ret;
}

static int rt_charger_enable_charging(struct mtk_charger_info *mchr_info,
	bool enable)
{
	int ret = 0;
	struct rt9468_info *info = (struct rt9468_info *)mchr_info;

	ret = (enable ? rt9468_set_bit : rt9468_clr_bit)
		(info, RT9468_REG_CHG_CTRL2, RT9468_MASK_CHG_EN);

	return ret;
}

static int rt_charger_enable_power_path(struct mtk_charger_info *mchr_info,
	bool enable)
{
	int ret = 0;
	struct rt9468_info *info = (struct rt9468_info *)mchr_info;

	ret = (enable ? rt9468_clr_bit : rt9468_set_bit)
		(info, RT9468_REG_CHG_CTRL1, RT9468_MASK_HZ_EN);

	return ret;
}

static int rt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg)
{
	int ret = 0;
	struct rt9468_info *info = (struct rt9468_info *)mchr_info;

	/* Find corresponding reg value */
	u8 reg_ichg = rt9468_find_closest_reg_value(RT9468_ICHG_MIN,
		RT9468_ICHG_MAX, RT9468_ICHG_STEP, RT9468_ICHG_NUM, ichg);

	dprintf(CRITICAL, "%s: ichg = %d\n", __func__, ichg);

	ret = rt9468_i2c_update_bits(
		info,
		RT9468_REG_CHG_CTRL7,
		reg_ichg << RT9468_SHIFT_ICHG,
		RT9468_MASK_ICHG
	);

	return ret;
}

static int rt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr)
{
	int ret = 0;
	struct rt9468_info *info = (struct rt9468_info *)mchr_info;

	/* Find corresponding reg value */
	u8 reg_aicr = rt9468_find_closest_reg_value(RT9468_AICR_MIN,
		RT9468_AICR_MAX, RT9468_AICR_STEP, RT9468_AICR_NUM, aicr);

	dprintf(CRITICAL, "%s: aicr = %d\n", __func__, aicr);

	ret = rt9468_i2c_update_bits(
		info,
		RT9468_REG_CHG_CTRL3,
		reg_aicr << RT9468_SHIFT_AICR,
		RT9468_MASK_AICR
	);

	return ret;
}


static int rt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr)
{
	int ret = 0;
	struct rt9468_info *info = (struct rt9468_info *)mchr_info;

	/* Find corresponding reg value */
	u8 reg_mivr = rt9468_find_closest_reg_value(RT9468_MIVR_MIN,
		RT9468_MIVR_MAX, RT9468_MIVR_STEP, RT9468_MIVR_NUM, mivr);

	dprintf(CRITICAL, "%s: mivr = %d\n", __func__, mivr);

	ret = rt9468_i2c_update_bits(
		info,
		RT9468_REG_CHG_CTRL6,
		reg_mivr << RT9468_SHIFT_MIVR,
		RT9468_MASK_MIVR
	);

	return ret;
}

static int rt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg)
{
	int ret = 0;
	u8 reg_ichg = 0;
	struct rt9468_info *info = (struct rt9468_info *)mchr_info;
	u8 data = 0;

	ret = rt9468_i2c_read_byte(info, RT9468_REG_CHG_CTRL7, &data);
	if (ret != I2C_OK)
		return ret;

	reg_ichg = (data & RT9468_MASK_ICHG) >> RT9468_SHIFT_ICHG;
	*ichg = rt9468_find_closest_real_value(RT9468_ICHG_MIN,
		RT9468_ICHG_MAX, RT9468_ICHG_STEP, reg_ichg);

	return ret;
}

static int rt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr)
{
	int ret = 0;
	u8 reg_aicr = 0;
	struct rt9468_info *info = (struct rt9468_info *)mchr_info;
	u8 data = 0;

	ret = rt9468_i2c_read_byte(info, RT9468_REG_CHG_CTRL3, &data);
	if (ret != I2C_OK)
		return ret;

	reg_aicr = (data & RT9468_MASK_AICR) >> RT9468_SHIFT_AICR;
	*aicr = rt9468_find_closest_real_value(RT9468_AICR_MIN,
		RT9468_AICR_MAX, RT9468_AICR_STEP, reg_aicr);

	return ret;
}

static int rt_charger_reset_pumpx(struct mtk_charger_info *mchr_info,
	bool reset)
{
	int ret = 0;
	u32 aicr = 0;

	aicr = (reset ? 100 : 3250);
	ret = rt_charger_set_aicr(mchr_info, aicr);

	return ret;
}

static struct mtk_charger_ops rt9468_mchr_ops = {
	.dump_register = rt_charger_dump_register,
	.enable_charging = rt_charger_enable_charging,
	.get_ichg = rt_charger_get_ichg,
	.set_ichg = rt_charger_set_ichg,
	.set_aicr = rt_charger_set_aicr,
	.set_mivr = rt_charger_set_mivr,
	.enable_power_path = rt_charger_enable_power_path,
	.get_aicr = rt_charger_get_aicr,
	.reset_pumpx = rt_charger_reset_pumpx,
};

/* Info of primary charger */
static struct rt9468_info g_rt9468_info = {
	.mchr_info = {
		.name = "primary_charger",
		.alias_name = "rt9468",
		.device_id = -1,
		.mchr_ops = &rt9468_mchr_ops,
	},
	.i2c = {
		.id = I2C1,
		.addr = RT9468_SLAVE_ADDR,
		.mode = ST_MODE,
		.speed = 100,
	},
	.i2c_log_level = INFO,
};


int rt9468_probe(void)
{
	int ret = 0;

	/* Check primary charger */
	if (rt9468_is_hw_exist(&g_rt9468_info)) {
		ret = rt9468_hw_init(&g_rt9468_info);
		ret = rt9468_sw_init(&g_rt9468_info);
		mtk_charger_set_info(&(g_rt9468_info.mchr_info));
	}

	return ret;
}

