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
#include <platform/rt9467.h>
#include <platform/mtk_charger_intf.h>
#include <platform/mt_gpt.h>
#include <printf.h>
#include <string.h>

#if !defined(CONFIG_POWER_EXT)
#include <platform/upmu_common.h>
#endif

#define RT9467_LK_DRV_VERSION "1.0.5_MTK"

/* ================= */
/* Internal variable */
/* ================= */

struct rt9467_info {
	struct mtk_charger_info mchr_info;
	struct mt_i2c_t i2c;
	int i2c_log_level;
	unsigned int hidden_mode_cnt;
};

static const u8 rt9467_irq_maskall_data[] = {
	0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

static const u8 rt9467_val_en_hidden_mode[] = {
	0x49, 0x32, 0xB6, 0x27, 0x48, 0x18, 0x03, 0xE2,
};

enum rt9467_irq_idx {
	RT9467_IRQIDX_CHG_STATC = 0,
	RT9467_IRQIDX_CHG_FAULT,
	RT9467_IRQIDX_TS_STATC,
	RT9467_IRQIDX_CHG_IRQ1,
	RT9467_IRQIDX_CHG_IRQ2,
	RT9467_IRQIDX_CHG_IRQ3,
	RT9467_IRQIDX_DPDM_IRQ,
	RT9467_IRQIDX_MAX,
};

enum rt9467_charging_status {
	RT9467_CHG_STATUS_READY = 0,
	RT9467_CHG_STATUS_PROGRESS,
	RT9467_CHG_STATUS_DONE,
	RT9467_CHG_STATUS_FAULT,
	RT9467_CHG_STATUS_MAX,
};

/* Charging status name */
static const char *rt9467_chg_status_name[RT9467_CHG_STATUS_MAX] = {
	"ready", "progress", "done", "fault",
};

/* ======================= */
/* Address & Default value */
/* ======================= */

static const unsigned char rt9467_reg_addr[] = {
	RT9467_REG_CORE_CTRL0,
	RT9467_REG_CHG_CTRL1,
	RT9467_REG_CHG_CTRL2,
	RT9467_REG_CHG_CTRL3,
	RT9467_REG_CHG_CTRL4,
	RT9467_REG_CHG_CTRL5,
	RT9467_REG_CHG_CTRL6,
	RT9467_REG_CHG_CTRL7,
	RT9467_REG_CHG_CTRL8,
	RT9467_REG_CHG_CTRL9,
	RT9467_REG_CHG_CTRL10,
	RT9467_REG_CHG_CTRL11,
	RT9467_REG_CHG_CTRL12,
	RT9467_REG_CHG_CTRL13,
	RT9467_REG_CHG_CTRL14,
	RT9467_REG_CHG_CTRL15,
	RT9467_REG_CHG_CTRL16,
	RT9467_REG_CHG_ADC,
	RT9467_REG_CHG_DPDM1,
	RT9467_REG_CHG_DPDM2,
	RT9467_REG_CHG_DPDM3,
	RT9467_REG_CHG_CTRL19,
	RT9467_REG_CHG_CTRL17,
	RT9467_REG_CHG_CTRL18,
	RT9467_REG_DEVICE_ID,
	RT9467_REG_CHG_STAT,
	RT9467_REG_CHG_NTC,
	RT9467_REG_ADC_DATA_H,
	RT9467_REG_ADC_DATA_L,
	RT9467_REG_CHG_STATC,
	RT9467_REG_CHG_FAULT,
	RT9467_REG_TS_STATC,
	RT9467_REG_CHG_IRQ1,
	RT9467_REG_CHG_IRQ2,
	RT9467_REG_CHG_IRQ3,
	RT9467_REG_DPDM_IRQ,
	RT9467_REG_CHG_STATC_CTRL,
	RT9467_REG_CHG_FAULT_CTRL,
	RT9467_REG_TS_STATC_CTRL,
	RT9467_REG_CHG_IRQ1_CTRL,
	RT9467_REG_CHG_IRQ2_CTRL,
	RT9467_REG_CHG_IRQ3_CTRL,
	RT9467_REG_DPDM_IRQ_CTRL,
};

enum rt9467_iin_limit_sel {
	RT9467_IINLMTSEL_3_2A = 0,
	RT9467_IINLMTSEL_CHG_TYP,
	RT9467_IINLMTSEL_AICR,
	RT9467_IINLMTSEL_LOWER_LEVEL, /* lower of above three */
};

/* ========================= */
/* I2C operations */
/* ========================= */

static int rt9467_i2c_write_byte(struct rt9467_info *info, u8 cmd, u8 data)
{
	int ret = I2C_OK;
	unsigned char write_buf[2] = {cmd, data};
	struct mt_i2c_t *i2c = &info->i2c;

	ret = i2c_write(i2c, write_buf, 2);

	if (ret != I2C_OK)
		dprintf(CRITICAL,
			"%s: I2CW[0x%02X] = 0x%02X fail, code = %d\n",
			__func__, cmd, data, ret);
	else
		dprintf(info->i2c_log_level, "%s: I2CW[0x%02X] = 0x%02X\n",
			__func__, cmd, data);

	return ret;
}

static int rt9467_i2c_read_byte(struct rt9467_info *info, u8 cmd, u8 *data)
{
	int ret = I2C_OK;
	u8 ret_data = cmd;
	struct mt_i2c_t *i2c = &info->i2c;

	ret = i2c_write_read(i2c, &ret_data, 1, 1);

	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CR[0x%02X] fail, code = %d\n",
			__func__, cmd, ret);
	else {
		dprintf(info->i2c_log_level, "%s: I2CR[0x%02X] = 0x%02X\n",
			__func__, cmd, ret_data);
		*data = ret_data;
	}

	return ret;
}

static int rt9467_i2c_block_write(struct rt9467_info *info, u8 cmd, int len,
	const u8 *data)
{
	unsigned char write_buf[len + 1];
	struct mt_i2c_t *i2c = &info->i2c;

	write_buf[0] = cmd;
	memcpy(&write_buf[1], data, len);

	return i2c_write(i2c, write_buf, len + 1);
}

static int rt9467_i2c_block_read(struct rt9467_info *info, u8 cmd, int len,
	u8 *data)
{
	struct mt_i2c_t *i2c = &info->i2c;

	data[0] = cmd;

	return i2c_write_read(i2c, data, 1, len);
}

static int rt9467_i2c_test_bit(struct rt9467_info *info, u8 cmd, u8 shift,
	bool *is_one)
{
	int ret = 0;
	u8 data = 0;

	ret = rt9467_i2c_read_byte(info, cmd, &data);
	if (ret != I2C_OK) {
		*is_one = false;
		return ret;
	}

	data &= (1 << shift);
	*is_one = (data == 0 ? false : true);

	return ret;
}

static int rt9467_i2c_update_bits(struct rt9467_info *info, u8 cmd, u8 data,
	u8 mask)
{
	int ret = 0;
	u8 reg_data = 0;

	ret = rt9467_i2c_read_byte(info, cmd, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_data = reg_data & 0xFF;
	reg_data &= ~mask;
	reg_data |= (data & mask);

	return rt9467_i2c_write_byte(info, cmd, reg_data);
}

static inline int rt9467_set_bit(struct rt9467_info *info, u8 reg, u8 mask)
{
    return rt9467_i2c_update_bits(info, reg, mask, mask);
}

static inline int rt9467_clr_bit(struct rt9467_info *info, u8 reg, u8 mask)
{
    return rt9467_i2c_update_bits(info, reg, 0x00, mask);
}

/* ================== */
/* internal functions */
/* ================== */
static int rt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg);
static int rt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr);
static int rt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr);
static int rt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg);
static int rt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr);

static inline u8 rt9467_closest_reg(u32 min, u32 max, u32 step, u32 target)
{
	/* Smaller than minimum supported value, use minimum one */
	if (target < min)
		return 0;

	/* Greater than maximum supported value, use maximum one */
	if (target >= max)
		return (max - min) / step;

	return (target - min) / step; 
}

static inline u8 rt9467_closest_reg_value_via_tbl(const u32 *tbl, u32 tbl_size,
	u32 target)
{
	u32 i = 0;

	/* Smaller than minimum supported value, use minimum one */
	if (target < tbl[0])
		return 0;

	for (i = 0; i < tbl_size - 1; i++) {
		if (target >= tbl[i] && target < tbl[i + 1])
			return i;
	}

	/* Greater than maximum supported value, use maximum one */
	return tbl_size - 1;
}

static inline u32 rt9467_closest_value(u32 min, u32 max, u32 step, u8 reg_val)
{
	u32 ret_val = 0;

	ret_val = min + reg_val * step;
	if (ret_val > max)
		ret_val = max;

	return ret_val;
}

static int rt9467_enable_hidden_mode(struct rt9467_info *info, bool en)
{
	int ret = 0;

	if (en) {
		if (info->hidden_mode_cnt == 0) {
			ret = rt9467_i2c_block_write(info, 0x70,
				ARRAY_SIZE(rt9467_val_en_hidden_mode),
				rt9467_val_en_hidden_mode);
			if (ret < 0)
				goto err;

		}
		info->hidden_mode_cnt++;
	} else {
		if (info->hidden_mode_cnt == 1) /* last one */
			ret = rt9467_i2c_write_byte(info, 0x70, 0x00);
		info->hidden_mode_cnt--;
		if (ret < 0)
			goto err;
	}
	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);
	goto out;

err:
	dprintf(CRITICAL, "%s: en = %d fail(%d)\n", __func__, en, ret);
out:
	return ret;
}

static int rt9467_enable_ilim(struct rt9467_info *info, bool en)
{
	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);

	return (en ? rt9467_set_bit : rt9467_clr_bit)
		(info, RT9467_REG_CHG_CTRL3, RT9467_MASK_ILIM_EN);
}

static int rt9467_select_input_current_limit(struct rt9467_info *info,
	enum rt9467_iin_limit_sel sel)
{
	dprintf(CRITICAL, "%s: sel = %d\n", __func__, sel);

	return rt9467_i2c_update_bits(info, RT9467_REG_CHG_CTRL2,
		sel << RT9467_SHIFT_IINLMTSEL, RT9467_MASK_IINLMTSEL);
}

static bool rt9467_is_hw_exist(struct rt9467_info *info)
{
	int ret = 0;
	u8 device_id = 0, vendor_id = 0, chip_rev = 0;

	ret = rt9467_i2c_read_byte(info, RT9467_REG_DEVICE_ID, &device_id);
	if (ret != I2C_OK)
		return false;

	vendor_id = device_id & 0xF0;
	chip_rev = device_id & 0x0F;
	if (vendor_id != RT9467_VENDOR_ID) {
		dprintf(CRITICAL, "%s: vendor id is incorrect (0x%02X)\n",
			__func__, vendor_id);
		return false;
	}
	dprintf(CRITICAL, "%s: chip rev(E%d,0x%02X)\n", __func__, chip_rev,
		chip_rev);


	info->mchr_info.device_id = chip_rev;
	return true;
}

/* Set register's value to default */
static int rt9467_reset_chip(struct rt9467_info *info)
{
	int ret = 0;

	dprintf(CRITICAL, "%s\n", __func__);

	/* Disable HZ before reset */
	ret = rt9467_clr_bit(info, RT9467_REG_CHG_CTRL1, RT9467_MASK_HZ_EN);
	if (ret < 0)
		dprintf(CRITICAL, "%s: disable hz fail\n", __func__);

	return rt9467_set_bit(info, RT9467_REG_CORE_CTRL0, RT9467_MASK_RST);
}

static int rt9467_set_battery_voreg(struct rt9467_info *info, u32 voreg)
{
	u8 reg_voreg = 0;

	reg_voreg = rt9467_closest_reg(RT9467_BAT_VOREG_MIN,
		RT9467_BAT_VOREG_MAX, RT9467_BAT_VOREG_STEP, voreg);

	dprintf(CRITICAL, "%s: bat voreg = %d\n", __func__, voreg);

	return rt9467_i2c_update_bits(info, RT9467_REG_CHG_CTRL4,
		reg_voreg << RT9467_SHIFT_BAT_VOREG, RT9467_MASK_BAT_VOREG);
}

static int rt9467_mask_all_irq(struct rt9467_info *info)
{
	return rt9467_i2c_block_write(info, RT9467_REG_CHG_STATC_CTRL,
		ARRAY_SIZE(rt9467_irq_maskall_data), rt9467_irq_maskall_data);
}

static int rt9467_enable_watchdog_timer(struct rt9467_info *info, bool en)
{
	dprintf(CRITICAL, "%s\n", __func__);
	return (en ? rt9467_set_bit : rt9467_clr_bit)
		(info, RT9467_REG_CHG_CTRL13, RT9467_MASK_WDT_EN);
}


static int rt9467_init_setting(struct rt9467_info *info)
{
	int ret = 0;
	u8 evt[RT9467_IRQIDX_MAX] = {0};

	dprintf(CRITICAL, "%s\n", __func__);

	/* Mask all IRQs */
	ret = rt9467_mask_all_irq(info);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: mask all irq fail\n", __func__);

	/* Clr evt, skip CHG_IRQ3 */
	ret = rt9467_i2c_block_read(info, RT9467_REG_CHG_STATC, 5, evt);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: read irq1 fail\n", __func__);

	ret = rt9467_i2c_block_read(info, RT9467_REG_DPDM_IRQ_CTRL, 1, &evt[6]);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: read irq2 fail\n", __func__);

	/* Select input current limit to referenced from AICR */
	ret = rt9467_select_input_current_limit(info, RT9467_IINLMTSEL_AICR);
	if (ret < 0)
		dprintf(CRITICAL, "%s: select input current limit fail\n",
			__func__);

	mdelay(150);

	/* Disable HW iinlimit, use SW */
	ret = rt9467_enable_ilim(info, false);
	if (ret < 0)
		dprintf(CRITICAL, "%s: disable ilim fail\n", __func__);

	ret = rt_charger_set_ichg(&info->mchr_info, 2000);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set ichg fail\n", __func__);

	ret = rt_charger_set_aicr(&info->mchr_info, 500);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set aicr fail\n", __func__);

	ret = rt_charger_set_mivr(&info->mchr_info, 4500);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set mivr fail\n", __func__);

	ret = rt9467_set_battery_voreg(info, 4350);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set cv fail\n", __func__);

	ret = rt9467_enable_watchdog_timer(info, true);
	if (ret < 0)
		dprintf(CRITICAL, "%s: enable wdt fail\n",__func__);

	return ret;
}

static int rt9467_get_charging_status(struct rt9467_info *info,
	enum rt9467_charging_status *chg_stat)
{
	int ret = 0;
	u8 data = 0;

	ret = rt9467_i2c_read_byte(info, RT9467_REG_CHG_STAT, &data);
	if (ret != I2C_OK)
		return ret;

	*chg_stat = (data & RT9467_MASK_CHG_STAT) >> RT9467_SHIFT_CHG_STAT;

	return ret;
}

static int rt9467_get_mivr(struct rt9467_info *info, u32 *mivr)
{
	int ret = 0;
	u8 reg_mivr = 0;
	u8 data = 0;

	ret = rt9467_i2c_read_byte(info, RT9467_REG_CHG_CTRL6, &data);
	if (ret != I2C_OK)
		return ret;
	reg_mivr = ((data & RT9467_MASK_MIVR) >> RT9467_SHIFT_MIVR) & 0xFF;

	*mivr = rt9467_closest_value(RT9467_MIVR_MIN, RT9467_MIVR_MAX,
		RT9467_MIVR_STEP, reg_mivr);

	return ret;
}

static int rt9467_is_charging_enable(struct rt9467_info *info, bool *en)
{
	return rt9467_i2c_test_bit(info, RT9467_REG_CHG_CTRL2,
		RT9467_SHIFT_CHG_EN, en);
}

static int rt9467_get_ieoc(struct rt9467_info *info, u32 *ieoc)
{
	int ret = 0;
	u8 reg_ieoc = 0;
	u8 data = 0;

	ret = rt9467_i2c_read_byte(info, RT9467_REG_CHG_CTRL9, &data);
	if (ret != I2C_OK)
		return ret;

	reg_ieoc = (data & RT9467_MASK_IEOC) >> RT9467_SHIFT_IEOC;
	*ieoc = rt9467_closest_value(RT9467_IEOC_MIN, RT9467_IEOC_MAX,
		RT9467_IEOC_STEP, reg_ieoc);

	return ret;
}

/* =========================================================== */
/* The following is implementation for interface of rt_charger */
/* =========================================================== */

static int rt_charger_dump_register(struct mtk_charger_info *mchr_info)
{
	int ret = 0;
	u32 i = 0, ichg = 0, aicr = 0, mivr = 0, ieoc = 0;
	bool chg_enable = 0;
	enum rt9467_charging_status chg_status = RT9467_CHG_STATUS_READY;
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;
	u8 data = 0;

	ret = rt9467_get_charging_status(info, &chg_status);
	if (chg_status == RT9467_CHG_STATUS_FAULT) {
		info->i2c_log_level = CRITICAL;
		for (i = 0; i < ARRAY_SIZE(rt9467_reg_addr); i++)
			ret = rt9467_i2c_read_byte(info, rt9467_reg_addr[i],
				&data);
	} else
		info->i2c_log_level = INFO;

	ret = rt_charger_get_ichg(mchr_info, &ichg);
	ret = rt9467_get_mivr(info, &mivr);
	ret = rt_charger_get_aicr(mchr_info, &aicr);
	ret = rt9467_get_ieoc(info, &ieoc);
	ret = rt9467_is_charging_enable(info, &chg_enable);

	dprintf(CRITICAL,
		"%s: ICHG = %dmA, AICR = %dmA, MIVR = %dmV, IEOC = %dmA\n",
		__func__, ichg, aicr, mivr, ieoc);

	dprintf(CRITICAL, "%s: CHG_EN = %d, CHG_STATUS = %s\n",
		__func__, chg_enable, rt9467_chg_status_name[chg_status]);

	return ret;
}

static int rt_charger_enable_charging(struct mtk_charger_info *mchr_info,
	bool en)
{
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;

	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);
	return (en ? rt9467_set_bit : rt9467_clr_bit)
		(info, RT9467_REG_CHG_CTRL2, RT9467_MASK_CHG_EN);
}

static int rt_charger_enable_power_path(struct mtk_charger_info *mchr_info,
	bool en)
{
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;
	u32 mivr = en ? 4500 : RT9467_MIVR_MAX;

	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);
	return rt_charger_set_mivr(&info->mchr_info, mivr);
}

static int rt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg)
{
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;

	/* Find corresponding reg value */
	u8 reg_ichg = rt9467_closest_reg(RT9467_ICHG_MIN, RT9467_ICHG_MAX,
		RT9467_ICHG_STEP, ichg);

	dprintf(CRITICAL, "%s: ichg = %d\n", __func__, ichg);

	return rt9467_i2c_update_bits(info, RT9467_REG_CHG_CTRL7,
		reg_ichg << RT9467_SHIFT_ICHG, RT9467_MASK_ICHG);
}

static int rt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr)
{
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;

	/* Find corresponding reg value */
	u8 reg_aicr = rt9467_closest_reg(RT9467_AICR_MIN, RT9467_AICR_MAX,
		RT9467_AICR_STEP, aicr);

	dprintf(CRITICAL, "%s: aicr = %d\n", __func__, aicr);

	return rt9467_i2c_update_bits(info, RT9467_REG_CHG_CTRL3,
		reg_aicr << RT9467_SHIFT_AICR, RT9467_MASK_AICR);
}


static int rt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr)
{
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;

	/* Find corresponding reg value */
	u8 reg_mivr = rt9467_closest_reg(RT9467_MIVR_MIN, RT9467_MIVR_MAX,
		RT9467_MIVR_STEP, mivr);

	dprintf(CRITICAL, "%s: mivr = %d\n", __func__, mivr);

	return rt9467_i2c_update_bits(info, RT9467_REG_CHG_CTRL6,
		reg_mivr << RT9467_SHIFT_MIVR, RT9467_MASK_MIVR);
}


static int rt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg)
{
	int ret = 0;
	u8 reg_ichg = 0;
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;
	u8 data = 0;

	ret = rt9467_i2c_read_byte(info, RT9467_REG_CHG_CTRL7, &data);
	if (ret != I2C_OK)
		return ret;

	reg_ichg = (data & RT9467_MASK_ICHG) >> RT9467_SHIFT_ICHG;
	*ichg = rt9467_closest_value(RT9467_ICHG_MIN, RT9467_ICHG_MAX,
		RT9467_ICHG_STEP, reg_ichg);

	return ret;
}

static int rt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr)
{
	int ret = 0;
	u8 reg_aicr = 0;
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;
	u8 data = 0;

	ret = rt9467_i2c_read_byte(info, RT9467_REG_CHG_CTRL3, &data);
	if (ret != I2C_OK)
		return ret;

	reg_aicr = (data & RT9467_MASK_AICR) >> RT9467_SHIFT_AICR;
	*aicr = rt9467_closest_value(RT9467_AICR_MIN, RT9467_AICR_MAX,
		RT9467_AICR_STEP, reg_aicr);

	return ret;
}

static int rt_charger_reset_pumpx(struct mtk_charger_info *mchr_info,
	bool reset)
{
	int ret = 0;
	u32 aicr = 0;
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;

	rt9467_enable_hidden_mode(info, true);

	ret = (reset ? rt9467_clr_bit : rt9467_set_bit)(info, 0x28, 0x80);
	aicr = (reset ? 100 : 500);
	ret = rt_charger_set_aicr(mchr_info, aicr);

	rt9467_enable_hidden_mode(info, false);
	return ret;
}

/*
 * Workaround to disable IRQ and WDT
 * In case that calling this function before charger is init,
 * use global info
 */
static int rt_charger_sw_reset(struct mtk_charger_info *mchr_info)
{
	int ret = 0;
	u8 evt[RT9467_IRQIDX_MAX] = {0};
	struct rt9467_info *info = (struct rt9467_info *)mchr_info;

	dprintf(CRITICAL, "%s: starts\n", __func__);

	/* Mask all IRQs */
	ret = rt9467_mask_all_irq(info);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: mask all irq fail\n", __func__);

	/* Clr evt, skip CHG_IRQ3 */
	ret = rt9467_i2c_block_read(info, RT9467_REG_CHG_STATC, 5, evt);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: read irq1 fail\n", __func__);

	ret = rt9467_i2c_block_read(info, RT9467_REG_DPDM_IRQ_CTRL, 1, &evt[6]);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: read irq2 fail\n", __func__);

	/* Disable WDT */
	ret = rt9467_enable_watchdog_timer(info, false);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: disable wdt fail\n", __func__);

	return ret;
}

static struct mtk_charger_ops rt9467_mchr_ops = {
	.dump_register = rt_charger_dump_register,
	.enable_charging = rt_charger_enable_charging,
	.get_ichg = rt_charger_get_ichg,
	.set_ichg = rt_charger_set_ichg,
	.set_aicr = rt_charger_set_aicr,
	.set_mivr = rt_charger_set_mivr,
	.enable_power_path = rt_charger_enable_power_path,
	.get_aicr = rt_charger_get_aicr,
	.reset_pumpx = rt_charger_reset_pumpx,
	.sw_reset = rt_charger_sw_reset,
};


/* Info of primary charger */
static struct rt9467_info g_rt9467_info = {
	.mchr_info = {
		.name = "primary_charger",
		.alias_name = "rt9467",
		.device_id = -1,
		.mchr_ops = &rt9467_mchr_ops,
	},
	.i2c = {
		.id = I2C1,
		.addr = RT9467_SLAVE_ADDR,
		.mode = ST_MODE,
		.speed = 100,
	},
	.i2c_log_level = INFO,
	.hidden_mode_cnt = 0,
};

int rt9467_probe(void)
{
	int ret = 0;

	/* Check primary charger */
	if (rt9467_is_hw_exist(&g_rt9467_info)) {
		ret = rt9467_reset_chip(&g_rt9467_info);
		ret = rt9467_init_setting(&g_rt9467_info);
		mtk_charger_set_info(&(g_rt9467_info.mchr_info));
		dprintf(CRITICAL, "%s: %s\n", __func__, RT9467_LK_DRV_VERSION);
	}

	return ret;
}

/*
 * Revision Note
 * 1.0.5
 * (1) Add i2c_block_read
 * (2) Disable HZ before reset chip
 *
 * 1.0.4
 * (1) Enable/Disable spk mode for reset PE+
 *
 * 1.0.3
 * (1) Modify rt9467_is_hw_exist, check vendor id and revision id separately
 * (2) Set MIVR to highest value as disabling power path
 * (3) Update irq mask data
 *
 * 1.0.2
 * (1) Support E4 chip
 * (2) Release sw reset interface
 */
