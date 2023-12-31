/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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
#include <printf.h>
#include <string.h>
#include "rt9471.h"
#include "mtk_charger_intf.h"
#include "mtk_charger.h"

#if !defined(CONFIG_POWER_EXT)
#include <platform/upmu_common.h>
#endif

#define RT9471_LK_DRV_VERSION	"1.0.1_MTK"

/* ================= */
/* Internal variable */
/* ================= */

enum rt9471_stat_idx {
	RT9471_STATIDX_STAT0 = 0,
	RT9471_STATIDX_STAT1,
	RT9471_STATIDX_STAT2,
	RT9471_STATIDX_STAT3,
	RT9471_STATIDX_MAX,
};

enum rt9471_irq_idx {
	RT9471_IRQIDX_IRQ0 = 0,
	RT9471_IRQIDX_IRQ1,
	RT9471_IRQIDX_IRQ2,
	RT9471_IRQIDX_IRQ3,
	RT9471_IRQIDX_MAX,
};

enum rt9471_ic_stat {
	RT9471_ICSTAT_SLEEP = 0,
	RT9471_ICSTAT_VBUSRDY,
	RT9471_ICSTAT_TRICKLECHG,
	RT9471_ICSTAT_PRECHG,
	RT9471_ICSTAT_FASTCHG,
	RT9471_ICSTAT_IEOC,
	RT9471_ICSTAT_BGCHG,
	RT9471_ICSTAT_CHGDONE,
	RT9471_ICSTAT_CHGFAULT,
	RT9471_ICSTAT_OTG = 15,
	RT9471_ICSTAT_MAX,
};

static const char *rt9471_ic_stat_name[RT9471_ICSTAT_MAX] = {
	"hz/sleep", "ready", "trickle-charge", "pre-charge",
	"fast-charge", "ieoc-charge", "background-charge",
	"done", "fault", "RESERVED", "RESERVED", "RESERVED",
	"RESERVED", "RESERVED", "RESERVED", "OTG",
};

enum rt9471_mivr_track {
	RT9471_MIVRTRACK_REG = 0,
	RT9471_MIVRTRACK_VBAT_200MV,
	RT9471_MIVRTRACK_VBAT_250MV,
	RT9471_MIVRTRACK_VBAT_300MV,
	RT9471_MIVRTRACK_MAX,
};

struct rt9471_desc {
	u32 ichg;
	u32 aicr;
	u32 mivr;
	u32 cv;
	u32 ieoc;
	u32 safe_tmr;
	u32 wdt;
	u32 mivr_track;
	bool en_safe_tmr;
	bool en_te;
	bool en_jeita;
	bool ceb_invert;
	bool dis_i2c_tout;
	bool en_qon_rst;
	bool auto_aicr;
};

static struct rt9471_desc rt9471_default_desc = {
	.ichg = 2000000,
	.aicr = 500000,
	.mivr = 4500000,
	.cv = 4350000,
	.ieoc = 200000,
	.safe_tmr = 10,
	.wdt = 40,
	.mivr_track = RT9471_MIVRTRACK_REG,
	.en_safe_tmr = true,
	.en_te = true,
	.en_jeita = false,
	.ceb_invert = false,
	.dis_i2c_tout = false,
	.en_qon_rst = true,
	.auto_aicr = false,
};

static const u8 rt9471_irq_maskall[RT9471_IRQIDX_MAX] = {
	0xFF, 0xFE, 0xF3, 0xE7,
};

static const u32 rt9471_wdt[] = {
	0, 40, 80, 160,
};

static const u8 rt9471_val_en_hidden_mode[] = {
	0x69, 0x96,
};

struct rt9471_chip {
	struct mtk_charger_info mchr_info;
	struct mt_i2c_t i2c;
	int i2c_log_level;
	int hidden_mode_cnt;
	struct rt9471_desc *desc;
	bool wkard_en;
	u32 mivr;
};

/* ======================= */
/* Address & Default value */
/* ======================= */

static const u8 rt9471_reg_addr[] = {
	RT9471_REG_OTGCFG,
	RT9471_REG_TOP,
	RT9471_REG_FUNCTION,
	RT9471_REG_IBUS,
	RT9471_REG_VBUS,
	RT9471_REG_PRECHG,
	RT9471_REG_REGU,
	RT9471_REG_VCHG,
	RT9471_REG_ICHG,
	RT9471_REG_CHGTIMER,
	RT9471_REG_EOC,
	RT9471_REG_INFO,
	RT9471_REG_JEITA,
	RT9471_REG_DPDMDET,
	RT9471_REG_STATUS,
	RT9471_REG_STAT0,
	RT9471_REG_STAT1,
	RT9471_REG_STAT2,
	RT9471_REG_STAT3,
	/* Skip IRQs to prevent reading clear while dumping registers */
	RT9471_REG_MASK0,
	RT9471_REG_MASK1,
	RT9471_REG_MASK2,
	RT9471_REG_MASK3,
};

/* ========================= */
/* I2C operations */
/* ========================= */

static int rt9471_i2c_write_byte(struct rt9471_chip *chip, u8 cmd, u8 data)
{
	int ret = I2C_OK;
	u8 write_buf[2] = {cmd, data};
	struct mt_i2c_t *i2c = &chip->i2c;

	ret = i2c_write(i2c, write_buf, 2);
	if (ret != I2C_OK)
		dprintf(CRITICAL,
			"%s I2CW[0x%02X] = 0x%02X fail, code = %d\n",
			__func__, cmd, data, ret);
	else
		dprintf(chip->i2c_log_level, "%s I2CW[0x%02X] = 0x%02X\n",
			__func__, cmd, data);

	return ret;
}

static int rt9471_i2c_read_byte(struct rt9471_chip *chip, u8 cmd, u8 *data)
{
	int ret = I2C_OK;
	u8 regval = cmd;
	struct mt_i2c_t *i2c = &chip->i2c;

	ret = i2c_write_read(i2c, &regval, 1, 1);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s I2CR[0x%02X] fail, code = %d\n",
			__func__, cmd, ret);
	else {
		dprintf(chip->i2c_log_level, "%s I2CR[0x%02X] = 0x%02X\n",
			__func__, cmd, regval);
		*data = regval;
	}

	return ret;
}

static int rt9471_i2c_block_write(struct rt9471_chip *chip, u8 cmd, u32 len,
				  const u8 *data)
{
	u8 write_buf[len + 1];
	struct mt_i2c_t *i2c = &chip->i2c;

	write_buf[0] = cmd;
	memcpy(&write_buf[1], data, len);

	return i2c_write(i2c, write_buf, len + 1);
}

static int rt9471_i2c_block_read(struct rt9471_chip *chip, u8 cmd, u32 len,
				 u8 *data)
{
	struct mt_i2c_t *i2c = &chip->i2c;

	data[0] = cmd;

	return i2c_write_read(i2c, data, 1, len);
}

static int rt9471_i2c_test_bit(struct rt9471_chip *chip, u8 cmd, u8 shift,
			       bool *is_one)
{
	int ret = 0;
	u8 regval = 0;

	ret = rt9471_i2c_read_byte(chip, cmd, &regval);
	if (ret != I2C_OK) {
		*is_one = false;
		return ret;
	}

	regval &= 1 << shift;
	*is_one = (regval ? true : false);

	return ret;
}

static int rt9471_i2c_update_bits(struct rt9471_chip *chip, u8 cmd, u8 data,
				  u8 mask)
{
	int ret = 0;
	u8 regval = 0;

	ret = rt9471_i2c_read_byte(chip, cmd, &regval);
	if (ret != I2C_OK)
		return ret;

	regval &= ~mask;
	regval |= (data & mask);

	return rt9471_i2c_write_byte(chip, cmd, regval);
}

static inline int rt9471_set_bit(struct rt9471_chip *chip, u8 cmd, u8 mask)
{
	return rt9471_i2c_update_bits(chip, cmd, mask, mask);
}

static inline int rt9471_clr_bit(struct rt9471_chip *chip, u8 cmd, u8 mask)
{
	return rt9471_i2c_update_bits(chip, cmd, 0x00, mask);
}

static inline u8 rt9471_closest_reg(u32 min, u32 max, u32 step, u32 target)
{
	if (target < min)
		return 0;

	if (target >= max)
		return (max - min) / step;

	return (target - min) / step;
}

static inline u8 rt9471_closest_reg_via_tbl(const u32 *tbl, u32 tbl_size,
					    u32 target)
{
	u32 i = 0;

	if (target < tbl[0])
		return 0;

	for (i = 0; i < tbl_size - 1; i++) {
		if (target >= tbl[i] && target < tbl[i + 1])
			return i;
	}

	return tbl_size - 1;
}

static inline u32 rt9471_closest_value(u32 min, u32 max, u32 step, u8 regval)
{
	u32 val = 0;

	val = min + regval * step;
	if (val > max)
		val = max;

	return val;
}

static int __rt9471_get_ic_stat(struct rt9471_chip *chip,
				enum rt9471_ic_stat *stat)
{
	int ret = 0;
	u8 regval = 0;

	ret = rt9471_i2c_read_byte(chip, RT9471_REG_STATUS, &regval);
	if (ret != I2C_OK)
		return ret;
	*stat = (regval & RT9471_ICSTAT_MASK) >> RT9471_ICSTAT_SHIFT;

	return ret;
}

static int __rt9471_get_mivr(struct rt9471_chip *chip, u32 *mivr)
{
	int ret = 0;
	u8 regval = 0;

	ret = rt9471_i2c_read_byte(chip, RT9471_REG_VBUS, &regval);
	if (ret != I2C_OK)
		return ret;

	regval = (regval & RT9471_MIVR_MASK) >> RT9471_MIVR_SHIFT;
	*mivr = rt9471_closest_value(RT9471_MIVR_MIN, RT9471_MIVR_MAX,
				     RT9471_MIVR_STEP, regval);

	return ret;
}

static int __rt9471_get_ichg(struct rt9471_chip *chip, u32 *ichg)
{
	int ret = 0;
	u8 regval = 0;

	ret = rt9471_i2c_read_byte(chip, RT9471_REG_ICHG, &regval);
	if (ret != I2C_OK)
		return ret;

	regval = (regval & RT9471_ICHG_MASK) >> RT9471_ICHG_SHIFT;
	*ichg = rt9471_closest_value(RT9471_ICHG_MIN, RT9471_ICHG_MAX,
				     RT9471_ICHG_STEP, regval);

	return ret;
}

static int __rt9471_get_aicr(struct rt9471_chip *chip, u32 *aicr)
{
	int ret = 0;
	u8 regval = 0;

	ret = rt9471_i2c_read_byte(chip, RT9471_REG_IBUS, &regval);
	if (ret != I2C_OK)
		return ret;

	regval = (regval & RT9471_AICR_MASK) >> RT9471_AICR_SHIFT;
	*aicr = rt9471_closest_value(RT9471_AICR_MIN, RT9471_AICR_MAX,
				     RT9471_AICR_STEP, regval);
	if (*aicr > RT9471_AICR_MIN && *aicr < RT9471_AICR_MAX)
		*aicr -= RT9471_AICR_STEP;

	return ret;
}

static int __rt9471_get_cv(struct rt9471_chip *chip, u32 *cv)
{
	int ret = 0;
	u8 regval = 0;

	ret = rt9471_i2c_read_byte(chip, RT9471_REG_VCHG, &regval);
	if (ret != I2C_OK)
		return ret;

	regval = (regval & RT9471_CV_MASK) >> RT9471_CV_SHIFT;
	*cv = rt9471_closest_value(RT9471_CV_MIN, RT9471_CV_MAX, RT9471_CV_STEP,
				   regval);

	return ret;
}

static int __rt9471_get_ieoc(struct rt9471_chip *chip, u32 *ieoc)
{
	int ret = 0;
	u8 regval = 0;

	ret = rt9471_i2c_read_byte(chip, RT9471_REG_EOC, &regval);
	if (ret != I2C_OK)
		return ret;

	regval = (regval & RT9471_IEOC_MASK) >> RT9471_IEOC_SHIFT;
	*ieoc = rt9471_closest_value(RT9471_IEOC_MIN, RT9471_IEOC_MAX,
				     RT9471_IEOC_STEP, regval);

	return ret;
}

static int __rt9471_is_chg_enabled(struct rt9471_chip *chip, bool *en)
{
	return rt9471_i2c_test_bit(chip, RT9471_REG_FUNCTION,
				   RT9471_CHG_EN_SHIFT, en);
}

static int __rt9471_enable_safe_tmr(struct rt9471_chip *chip, bool en)
{
	dprintf(INFO, "%s en = %d\n", __func__, en);
	return (en ? rt9471_set_bit : rt9471_clr_bit)
		(chip, RT9471_REG_CHGTIMER, RT9471_SAFETMR_EN_MASK);
}

static int __rt9471_enable_te(struct rt9471_chip *chip, bool en)
{
	dprintf(INFO, "%s en = %d\n", __func__, en);
	return (en ? rt9471_set_bit : rt9471_clr_bit)
		(chip, RT9471_REG_EOC, RT9471_TE_MASK);
}

static int __rt9471_enable_jeita(struct rt9471_chip *chip, bool en)
{
	dprintf(INFO, "%s en = %d\n", __func__, en);
	return (en ? rt9471_set_bit : rt9471_clr_bit)
		(chip, RT9471_REG_JEITA, RT9471_JEITA_EN_MASK);
}

static int __rt9471_disable_i2c_tout(struct rt9471_chip *chip, bool en)
{
	dprintf(INFO, "%s en = %d\n", __func__, en);
	return (en ? rt9471_set_bit : rt9471_clr_bit)
		(chip, RT9471_REG_TOP, RT9471_DISI2CTO_MASK);
}

static int __rt9471_enable_qon_rst(struct rt9471_chip *chip, bool en)
{
	dprintf(INFO, "%s en = %d\n", __func__, en);
	return (en ? rt9471_set_bit : rt9471_clr_bit)
		(chip, RT9471_REG_TOP, RT9471_QONRST_MASK);
}

static int __rt9471_enable_autoaicr(struct rt9471_chip *chip, bool en)
{
	dprintf(INFO, "%s en = %d\n", __func__, en);
	return (en ? rt9471_set_bit : rt9471_clr_bit)
		(chip, RT9471_REG_IBUS, RT9471_AUTOAICR_MASK);
}

static int __rt9471_enable_chg(struct rt9471_chip *chip, bool en)
{
	dprintf(INFO, "%s en = %d\n", __func__, en);
	return (en ? rt9471_set_bit : rt9471_clr_bit)
		(chip, RT9471_REG_FUNCTION, RT9471_CHG_EN_MASK);
}

static int __rt9471_set_wdt(struct rt9471_chip *chip, u32 sec)
{
	u8 regval = 0;

	/* 40s is the minimum, set to 40 except sec == 0 */
	if (sec <= 40 && sec > 0)
		sec = 40;
	regval = rt9471_closest_reg_via_tbl(rt9471_wdt, ARRAY_SIZE(rt9471_wdt),
					    sec);

	dprintf(INFO, "%s time = %d(0x%02X)\n", __func__, sec, regval);

	return rt9471_i2c_update_bits(chip, RT9471_REG_TOP,
				      regval << RT9471_WDT_SHIFT,
				      RT9471_WDT_MASK);
}

static int __rt9471_set_ichg(struct rt9471_chip *chip, u32 ichg)
{
	u8 regval = 0;

	regval = rt9471_closest_reg(RT9471_ICHG_MIN, RT9471_ICHG_MAX,
				    RT9471_ICHG_STEP, ichg);

	dprintf(INFO, "%s ichg = %d(0x%02X)\n", __func__, ichg, regval);

	return rt9471_i2c_update_bits(chip, RT9471_REG_ICHG,
				      regval << RT9471_ICHG_SHIFT,
				      RT9471_ICHG_MASK);
}

static int __rt9471_set_aicr(struct rt9471_chip *chip, u32 aicr)
{
	u8 regval = 0;

	regval = rt9471_closest_reg(RT9471_AICR_MIN, RT9471_AICR_MAX,
				    RT9471_AICR_STEP, aicr);
	/* 0 & 1 are both 50mA */
	if (aicr < RT9471_AICR_MAX)
		regval += 1;

	dprintf(INFO, "%s aicr = %d(0x%02X)\n", __func__, aicr, regval);

	return rt9471_i2c_update_bits(chip, RT9471_REG_IBUS,
				      regval << RT9471_AICR_SHIFT,
				      RT9471_AICR_MASK);
}

static int __rt9471_set_mivr(struct rt9471_chip *chip, u32 mivr)
{
	u8 regval = 0;

	regval = rt9471_closest_reg(RT9471_MIVR_MIN, RT9471_MIVR_MAX,
				    RT9471_MIVR_STEP, mivr);

	dprintf(INFO, "%s mivr = %d(0x%02X)\n", __func__, mivr, regval);

	return rt9471_i2c_update_bits(chip, RT9471_REG_VBUS,
				      regval << RT9471_MIVR_SHIFT,
				      RT9471_MIVR_MASK);
}

static int __rt9471_set_cv(struct rt9471_chip *chip, u32 cv)
{
	u8 regval = 0;

	regval = rt9471_closest_reg(RT9471_CV_MIN, RT9471_CV_MAX,
				    RT9471_CV_STEP, cv);

	dprintf(INFO, "%s cv = %d(0x%02X)\n", __func__, cv, regval);

	return rt9471_i2c_update_bits(chip, RT9471_REG_VCHG,
				      regval << RT9471_CV_SHIFT,
				      RT9471_CV_MASK);
}

static int __rt9471_set_ieoc(struct rt9471_chip *chip, u32 ieoc)
{
	u8 regval = 0;

	regval = rt9471_closest_reg(RT9471_IEOC_MIN, RT9471_IEOC_MAX,
				    RT9471_IEOC_STEP, ieoc);

	dprintf(INFO, "%s ieoc = %d(0x%02X)\n", __func__, ieoc, regval);

	return rt9471_i2c_update_bits(chip, RT9471_REG_EOC,
				      regval << RT9471_IEOC_SHIFT,
				      RT9471_IEOC_MASK);
}

static int __rt9471_set_safe_tmr(struct rt9471_chip *chip, u32 hr)
{
	u8 regval = 0;

	regval = rt9471_closest_reg(RT9471_SAFETMR_MIN, RT9471_SAFETMR_MAX,
				    RT9471_SAFETMR_STEP, hr);

	dprintf(INFO, "%s time = %d(0x%02X)\n", __func__, hr, regval);

	return rt9471_i2c_update_bits(chip, RT9471_REG_CHGTIMER,
				      regval << RT9471_SAFETMR_SHIFT,
				      RT9471_SAFETMR_MASK);
}

static int __rt9471_set_mivrtrack(struct rt9471_chip *chip, u32 mivr_track)
{
	if (mivr_track >= RT9471_MIVRTRACK_MAX)
		mivr_track = RT9471_MIVRTRACK_VBAT_300MV;

	dprintf(INFO, "%s mivrtrack = %d\n", __func__, mivr_track);

	return rt9471_i2c_update_bits(chip, RT9471_REG_VBUS,
				      mivr_track << RT9471_MIVRTRACK_SHIFT,
				      RT9471_MIVRTRACK_MASK);
}

static int __rt9471_kick_wdt(struct rt9471_chip *chip)
{
	dprintf(INFO, "%s\n", __func__);
	return rt9471_set_bit(chip, RT9471_REG_TOP, RT9471_WDTCNTRST_MASK);
}

/* ================== */
/* internal functions */
/* ================== */
static bool rt9471_is_hw_exist(struct rt9471_chip *chip)
{
	int ret = 0;
	u8 info = 0, id = 0, rev = 0;

	ret = rt9471_i2c_read_byte(chip, RT9471_REG_INFO, &info);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s get devinfo fail(%d)\n", __func__, ret);
		return false;
	}

	id = (info & RT9471_DEVID_MASK) >> RT9471_DEVID_SHIFT;
	if (id != RT9470_DEVID && id != RT9470D_DEVID &&
				  id != RT9471_DEVID && id != RT9471D_DEVID) {
		dprintf(CRITICAL, "%s incorrect devid 0x%02X\n", __func__,
			id);
		return false;
	}
	rev = (info & RT9471_DEVREV_MASK) >> RT9471_DEVREV_SHIFT;
	dprintf(INFO, "%s id = 0x%02X, rev = 0x%02X\n", __func__, id, rev);
	chip->mchr_info.device_id = rev;

	return true;
}

static int rt9471_reset_register(struct rt9471_chip *chip)
{
	dprintf(INFO, "%s\n", __func__);
	return rt9471_set_bit(chip, RT9471_REG_INFO, RT9471_REGRST_MASK);
}

static int rt9471_enable_hidden_mode(struct rt9471_chip *chip, bool en)
{
	int ret = 0;

	if (en) {
		if (chip->hidden_mode_cnt == 0) {
			ret = rt9471_i2c_block_write(chip, 0xA0,
				ARRAY_SIZE(rt9471_val_en_hidden_mode),
				rt9471_val_en_hidden_mode);
			if (ret != I2C_OK)
				goto err;
		}
		chip->hidden_mode_cnt++;
	} else {
		if (chip->hidden_mode_cnt == 1) /* last one */
			ret = rt9471_i2c_write_byte(chip, 0xA0, 0x00);
		chip->hidden_mode_cnt--;
		if (ret != I2C_OK)
			goto err;
	}
	dprintf(SPEW, "%s en = %d, cnt = %d\n", __func__,
		      en, chip->hidden_mode_cnt);
	goto out;

err:
	dprintf(CRITICAL, "%s en = %d fail(%d)\n", __func__, en, ret);
out:
	return ret;
}

static int rt9471_sw_workaround(struct rt9471_chip *chip)
{
	int ret = 0;
	u8 regval = 0, chip_rev = 0;

	dprintf(INFO, "%s\n", __func__);

	ret = rt9471_enable_hidden_mode(chip, true);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s enter hidden mode fail(%d)\n",
				  __func__, ret);
		return ret;
	}

	ret = rt9471_i2c_read_byte(chip, RT9471_REG_HIDDEN_0, &regval);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s read HIDDEN_0 fail(%d)\n",
				   __func__, ret);
		goto out;
	}
	chip_rev = (regval & RT9471_CHIP_REV_MASK) >> RT9471_CHIP_REV_SHIFT;
	dprintf(INFO, "%s chip_rev = %d\n", __func__, chip_rev);

	/* OTG load transient improvement */
	if (chip_rev <= 3)
		ret = rt9471_i2c_update_bits(chip, RT9471_REG_OTG_HDEN2, 0x10,
					     RT9471_REG_OTG_RES_COMP_MASK);

out:
	rt9471_enable_hidden_mode(chip, false);
	return ret;
}

static int rt9471_init_setting(struct rt9471_chip *chip)
{
	int ret = 0;
	struct rt9471_desc *desc = chip->desc;
	u8 evt[RT9471_IRQIDX_MAX] = {0};

	dprintf(INFO, "%s\n", __func__);

	/* Disable WDT during IRQ masked period */
	ret = __rt9471_set_wdt(chip, 0);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set wdt fail(%d)\n", __func__, ret);

	/* Mask all IRQs */
	ret = rt9471_i2c_block_write(chip, RT9471_REG_MASK0,
				     ARRAY_SIZE(rt9471_irq_maskall),
				     rt9471_irq_maskall);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s mask irq fail(%d)\n", __func__, ret);

	/* Clear all IRQs */
	ret = rt9471_i2c_block_read(chip, RT9471_REG_IRQ0, RT9471_IRQIDX_MAX,
				    evt);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s clear irq fail(%d)\n", __func__, ret);

	ret = __rt9471_set_ichg(chip, desc->ichg);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set ichg fail(%d)\n", __func__, ret);

	ret = __rt9471_set_aicr(chip, desc->aicr);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set aicr fail(%d)\n", __func__, ret);

	ret = __rt9471_set_mivr(chip, desc->mivr);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set mivr fail(%d)\n", __func__, ret);

	ret = __rt9471_set_cv(chip, desc->cv);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set cv fail(%d)\n", __func__, ret);

	ret = __rt9471_set_ieoc(chip, desc->ieoc);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set ieoc fail(%d)\n", __func__, ret);

	ret = __rt9471_set_safe_tmr(chip, desc->safe_tmr);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set safe tmr fail(%d)\n", __func__, ret);

	ret = __rt9471_set_wdt(chip, desc->wdt);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set wdt fail(%d)\n", __func__, ret);

	ret = __rt9471_set_mivrtrack(chip, desc->mivr_track);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set mivrtrack fail(%d)\n",
				  __func__, ret);

	ret = __rt9471_enable_safe_tmr(chip, desc->en_safe_tmr);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s en safe tmr fail(%d)\n", __func__, ret);

	ret = __rt9471_enable_te(chip, desc->en_te);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s en te fail(%d)\n", __func__, ret);

	ret = __rt9471_enable_jeita(chip, desc->en_jeita);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s en jeita fail(%d)\n", __func__, ret);

	ret = __rt9471_disable_i2c_tout(chip, desc->dis_i2c_tout);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s dis i2c tout fail(%d)\n", __func__, ret);

	ret = __rt9471_enable_qon_rst(chip, desc->en_qon_rst);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s en qon rst fail(%d)\n", __func__, ret);

	ret = __rt9471_enable_autoaicr(chip, desc->auto_aicr);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s en autoaicr fail(%d)\n", __func__, ret);

	ret = rt9471_sw_workaround(chip);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s set sw workaround fail(%d)\n",
				   __func__, ret);

	return 0;
}

/* =========================================================== */
/* The following is implementation for interface of rt_charger */
/* =========================================================== */

static int rt_charger_dump_register(struct mtk_charger_info *mchr_info)
{
	int ret = 0;
	u32 i = 0, ichg = 0, aicr = 0, mivr = 0, ieoc = 0, cv = 0;
	bool chg_en = 0;
	enum rt9471_ic_stat ic_stat = RT9471_ICSTAT_SLEEP;
	u8 stats[RT9471_STATIDX_MAX] = {0}, regval = 0;
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	ret = __rt9471_get_ichg(chip, &ichg);
	ret = __rt9471_get_aicr(chip, &aicr);
	ret = __rt9471_get_mivr(chip, &mivr);
	ret = __rt9471_get_ieoc(chip, &ieoc);
	ret = __rt9471_get_cv(chip, &cv);
	ret = __rt9471_is_chg_enabled(chip, &chg_en);
	ret = __rt9471_get_ic_stat(chip, &ic_stat);
	ret = rt9471_i2c_block_read(chip, RT9471_REG_STAT0, RT9471_STATIDX_MAX,
				    stats);

	if (ic_stat == RT9471_ICSTAT_CHGFAULT) {
		for (i = 0; i < ARRAY_SIZE(rt9471_reg_addr); i++) {
			ret = rt9471_i2c_read_byte(chip, rt9471_reg_addr[i],
						   &regval);
			if (ret != I2C_OK)
				continue;
			dprintf(INFO, "%s reg0x%02X = 0x%02X\n", __func__,
				      rt9471_reg_addr[i], regval);
		}
	}

	dprintf(INFO,
		 "%s ICHG = %dmA, AICR = %dmA, MIVR = %dmV\n",
		 __func__, ichg / 1000, aicr / 1000, mivr / 1000);

	dprintf(INFO, "%s IEOC = %dmA, CV = %dmV\n",
		 __func__, ieoc / 1000, cv / 1000);

	dprintf(INFO, "%s CHG_EN = %d, IC_STAT = %s\n",
		__func__, chg_en, rt9471_ic_stat_name[ic_stat]);

	dprintf(INFO,
		"%s STAT0 = 0x%02X, STAT1 = 0x%02X\n", __func__,
		stats[RT9471_STATIDX_STAT0], stats[RT9471_STATIDX_STAT1]);

	dprintf(INFO,
		"%s STAT2 = 0x%02X, STAT3 = 0x%02X\n", __func__,
		stats[RT9471_STATIDX_STAT2], stats[RT9471_STATIDX_STAT3]);

	return 0;
}

static int rt_charger_enable_charging(struct mtk_charger_info *mchr_info,
				      bool en)
{
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	return __rt9471_enable_chg(chip, en);
}

static int rt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg)
{
	int ret = 0;
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	ret = __rt9471_get_ichg(chip, ichg);
	*ichg /= 1000;	/* uA --> mA */

	return ret;
}

static int rt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg)
{
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	return __rt9471_set_ichg(chip, ichg * 1000);
}

static int rt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr)
{
	int ret = 0;
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	ret = __rt9471_get_aicr(chip, aicr);
	*aicr /= 1000;	/* uA --> mA */

	return ret;
}

static int rt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr)
{
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	return __rt9471_set_aicr(chip, aicr * 1000);
}

static int rt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr)
{
	int ret = 0;
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	ret = __rt9471_set_mivr(chip, mivr * 1000);
	if (ret == I2C_OK)
		chip->mivr = mivr * 1000;

	return ret;
}

static int rt_charger_enable_power_path(struct mtk_charger_info *mchr_info,
					bool en)
{
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;
	u32 mivr = (en ? chip->mivr : RT9471_MIVR_MAX);

	dprintf(INFO, "%s en = %d\n", __func__, en);

	return __rt9471_set_mivr(chip, mivr);
}

static int rt_charger_enable_wdt(struct mtk_charger_info *mchr_info, bool en)
{
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	return __rt9471_set_wdt(chip, en ? chip->desc->wdt : 0);
}

static int rt_charger_sw_reset(struct mtk_charger_info *mchr_info)
{
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	return rt9471_reset_register(chip);
}

static int rt_charger_reset_wdt(struct mtk_charger_info *mchr_info)
{
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;

	return __rt9471_kick_wdt(chip);
}

static inline int rt9471_fix_current_accuracy(struct rt9471_chip *chip, bool en)
{
	int ret = 0;

	if (!(chip->wkard_en ^ en))
		return 0;
	ret = rt9471_enable_hidden_mode(chip, true);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s enter hidden mode fail(%d)\n",
				  __func__, ret);
		return ret;
	}
	if (en) {
		ret = rt9471_i2c_write_byte(chip, RT9471_REG_BUCK_HDEN4, 0x77);
		if (ret != I2C_OK) {
			dprintf(CRITICAL, "%s set reg0x55 fail(%d)\n",
				__func__, ret);
			goto out;
		}
		ret = rt9471_i2c_write_byte(chip, RT9471_REG_BUCK_HDEN3, 0xC0);
		if (ret != I2C_OK) {
			dprintf(CRITICAL, "%s set reg0x54 fail(%d)\n",
				__func__, ret);
			goto out;
		}
	} else {
		ret = rt9471_i2c_write_byte(chip, RT9471_REG_BUCK_HDEN4, 0x71);
		if (ret != I2C_OK) {
			dprintf(CRITICAL, "%s set reg0x55 fail(%d)\n",
				__func__, ret);
			goto out;
		}
		ret = rt9471_i2c_write_byte(chip, RT9471_REG_BUCK_HDEN3, 0xF0);
		if (ret != I2C_OK) {
			dprintf(CRITICAL, "%s set reg0x54 fail(%d)\n",
				__func__, ret);
			goto out;
		}
	}
	chip->wkard_en = en;
out:
	rt9471_enable_hidden_mode(chip, false);
	return ret;
}

static int rt_charger_check_charging_mode(struct mtk_charger_info *mchr_info)
{
	int ret = 0;
	struct rt9471_chip *chip = (struct rt9471_chip *)mchr_info;
	static enum rt9471_ic_stat pre_stat = RT9471_ICSTAT_SLEEP;
	enum rt9471_ic_stat cur_stat = RT9471_ICSTAT_SLEEP;

	dprintf(INFO, "%s\n", __func__);

	__rt9471_kick_wdt(chip);

	ret = __rt9471_get_ic_stat(chip, &cur_stat);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s get ic stat fail(%d)\n", __func__, ret);
		return ret;
	}

	dprintf(INFO, "%s in %s stat, previously in %s stat\n", __func__,
		      rt9471_ic_stat_name[cur_stat],
		      rt9471_ic_stat_name[pre_stat]);
	if (cur_stat == pre_stat)
		return 0;
	switch (cur_stat) {
	case RT9471_ICSTAT_TRICKLECHG:
	case RT9471_ICSTAT_PRECHG:
		ret = rt9471_fix_current_accuracy(chip, true);
		if (ret != I2C_OK) {
			dprintf(CRITICAL, "%s fix current accuracy fail(%d)\n",
					  __func__, ret);
			return ret;
		}
		break;
	case RT9471_ICSTAT_CHGFAULT:
		rt_charger_dump_register(mchr_info);
	default:
		ret = rt9471_fix_current_accuracy(chip, false);
		if (ret != I2C_OK) {
			dprintf(CRITICAL, "%s fix current accuracy fail(%d)\n",
					  __func__, ret);
			return ret;
		}
		break;
	}
	pre_stat = cur_stat;

	return ret;
}

static struct mtk_charger_ops rt9471_mchr_ops = {
	.dump_register = rt_charger_dump_register,
	.enable_charging = rt_charger_enable_charging,
	.get_ichg = rt_charger_get_ichg,
	.set_ichg = rt_charger_set_ichg,
	.get_aicr = rt_charger_get_aicr,
	.set_aicr = rt_charger_set_aicr,
	.set_mivr = rt_charger_set_mivr,
	.enable_power_path = rt_charger_enable_power_path,
	.enable_wdt = rt_charger_enable_wdt,
	.reset_wdt = rt_charger_reset_wdt,
	.sw_reset = rt_charger_sw_reset,
	.check_charging_mode = rt_charger_check_charging_mode,
};

/* Info of primary charger */
static struct rt9471_chip g_rt9471_chip = {
	.mchr_info = {
		.name = "primary_charger",
		.alias_name = "rt9471",
		.device_id = -1,
		.mchr_ops = &rt9471_mchr_ops,
	},
	.i2c = {
		.id = I2C5,
		.addr = RT9471_SLAVE_ADDR,
		.mode = FS_MODE,
		.speed = 400,
	},
	.i2c_log_level = INFO,
	.hidden_mode_cnt = 0,
	.desc = &rt9471_default_desc,
	.wkard_en = false,
	.mivr = 4500000,
};

int rt9471_probe(void)
{
	int ret = 0;

	if (rt9471_is_hw_exist(&g_rt9471_chip)) {
		ret = rt9471_reset_register(&g_rt9471_chip);
		ret |= rt9471_init_setting(&g_rt9471_chip);
		mtk_charger_set_info(&g_rt9471_chip.mchr_info);
		dprintf(INFO, "%s (%s)\n", __func__, RT9471_LK_DRV_VERSION);
	}

	return ret;
}

/*
 * Revision Note
 * 1.0.1
 * (1) Kick WDT in rt_charger_check_charging_mode()
 * (2) Add support for RT9470/RT9470D
 * (3) Sync with Kernel Driver
 *
 * 1.0.0
 * (1) Support E2 chip
 */
