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
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <platform/hl7005.h>
#include <platform/mtk_charger_intf.h>
#include <printf.h>

#if !defined(CONFIG_POWER_EXT)
#include <platform/upmu_common.h>
#endif

const unsigned int VBAT_CVTH[] = {
	3500000, 3520000, 3540000, 3560000,
	3580000, 3600000, 3620000, 3640000,
	3660000, 3680000, 3700000, 3720000,
	3740000, 3760000, 3780000, 3800000,
	3820000, 3840000, 3860000, 3880000,
	3900000, 3920000, 3940000, 3960000,
	3980000, 4000000, 4020000, 4040000,
	4060000, 4080000, 4100000, 4120000,
	4140000, 4160000, 4180000, 4200000,
	4220000, 4240000, 4260000, 4280000,
	4300000, 4320000, 4340000, 4360000,
	4380000, 4400000, 4420000, 4440000
};

const unsigned int CSTH[] = {
	55000, 65000, 75000, 85000,
	95000, 105000, 115000, 125000
};

/*hl7005 REG00 IINLIM[5:0]*/
const unsigned int INPUT_CSTH[] = {
	10000, 50000, 80000, 500000
};

/* hl7005 REG0A BOOST_LIM[2:0], mA */
const unsigned int BOOST_CURRENT_LIMIT[] = {
	500, 750, 1200, 1400, 1650, 1875, 2150,
};

#define HL7005_SLAVE_ADDR_WRITE 0xD4

unsigned int charging_value_to_parameter(const unsigned int *parameter, const unsigned int array_size,
					const unsigned int val)
{
	if (val < array_size)
		return parameter[val];
	dprintf(CRITICAL, "Can't find the parameter\n");
	return parameter[0];
}

unsigned int charging_parameter_to_value(const unsigned int *parameter, const unsigned int array_size,
					const unsigned int val)
{
	unsigned int i;

	dprintf(CRITICAL, "array_size = %d\n", array_size);

	for (i = 0; i < array_size; i++) {
		if (val == *(parameter + i))
			return i;
	}

	dprintf(CRITICAL, "NO register value match\n");
	/* TODO: ASSERT(0);	// not find the value */
	return 0;
}

static unsigned int bmt_find_closest_level(const unsigned int *pList, unsigned int number,
					 unsigned int level)
{
	unsigned int i;
	unsigned int max_value_in_last_element;

	if (pList[0] < pList[1])
		max_value_in_last_element = 1;
	else
		max_value_in_last_element = 0;

	if (max_value_in_last_element == 1) {
		for (i = (number - 1); i != 0; i--) {	/* max value in the last element */
			if (pList[i] <= level) {
				dprintf(CRITICAL, "zzf_%d<=%d, i=%d\n", pList[i], level, i);
				return pList[i];
			}
		}
		dprintf(CRITICAL, "Can't find closest level\n");
		return pList[0];
		/* return 000; */
	} else {
		for (i = 0; i < number; i++) {	/* max value in the first element */
			if (pList[i] <= level)
				return pList[i];
		}
		dprintf(CRITICAL, "Can't find closest level\n");
		return pList[number - 1];
		/* return 000; */
	}
}

unsigned char hl7005_reg[HL7005_REG_NUM] = { 0 };

#define HL7005_I2C_ID	I2C1
static struct mt_i2c_t hl7005_i2c;

u32 hl7005_write_byte(u8 addr, u8 value)
{
	u32 ret_code = I2C_OK;
	u8 write_data[2];
	u16 len;

	write_data[0]= addr;
	write_data[1] = value;
	hl7005_i2c.id = HL7005_I2C_ID;
	/* Since i2c will left shift 1 bit, we need to set hl7005 I2C address to >>1 */
	hl7005_i2c.addr = (HL7005_SLAVE_ADDR_WRITE >> 1);
	hl7005_i2c.mode = ST_MODE;
	hl7005_i2c.speed = 100;
	len = 2;
	ret_code = i2c_write(&hl7005_i2c, write_data, len);
	//dprintf(CRITICAL, "%s: i2c_write: ret_code: %d\n", __func__, ret_code);
	return ret_code;
}

u32 hl7005_read_byte(u8 addr, u8 *dataBuffer)
{
	u32 ret_code = I2C_OK;
	u16 len;
	*dataBuffer = addr;

	hl7005_i2c.id = HL7005_I2C_ID;
	/* Since i2c will left shift 1 bit, we need to set hl7005 I2C address to >>1 */
	hl7005_i2c.addr = (HL7005_SLAVE_ADDR_WRITE >> 1);
	hl7005_i2c.mode = ST_MODE;
	hl7005_i2c.speed = 100;
	len = 1;
	ret_code = i2c_write_read(&hl7005_i2c, dataBuffer, len, len);
	//dprintf(CRITICAL, "%s: i2c_read: ret_code: %d\n", __func__, ret_code);
	return ret_code;
}

unsigned int hl7005_read_interface(unsigned char reg_num, unsigned char *val, unsigned char MASK,
				  unsigned char SHIFT)
{
	unsigned char hl7005_reg = 0;
	unsigned int ret = 0;

	ret = hl7005_read_byte(reg_num, &hl7005_reg);
	dprintf(CRITICAL, "[hl7005_read_interface] Reg[%x]=0x%x\n", reg_num, hl7005_reg);
	hl7005_reg &= (MASK << SHIFT);
	*val = (hl7005_reg >> SHIFT);
	dprintf(CRITICAL, "[hl7005_read_interface] val=0x%x\n", *val);

	return ret;
}

unsigned int hl7005_config_interface(unsigned char reg_num, unsigned char val, unsigned char MASK,
					unsigned char SHIFT)
{
	unsigned char hl7005_reg = 0;
	unsigned char hl7005_reg_ori = 0;
	unsigned int ret = 0;

	ret = hl7005_read_byte(reg_num, &hl7005_reg);
	hl7005_reg_ori = hl7005_reg;
	hl7005_reg &= ~(MASK << SHIFT);
	hl7005_reg |= (val << SHIFT);
	ret = hl7005_write_byte(reg_num, hl7005_reg);

	dprintf(CRITICAL, "[hl7005_config_interface] write Reg[%x]=0x%x from 0x%x\n", reg_num,
			hl7005_reg, hl7005_reg_ori);
	/* Check */
	/* hl7005_read_byte(reg_num, &hl7005_reg); */
	/* printk("[hl7005_config_interface] Check Reg[%x]=0x%x\n", reg_num, hl7005_reg); */

	return ret;
}

/* write one register directly */
unsigned int hl7005_reg_config_interface(unsigned char reg_num, unsigned char val)
{
	unsigned char hl7005_reg = val;

	return hl7005_write_byte(reg_num, hl7005_reg);
}

void hl7005_set_tmr_rst(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON0),
				(unsigned char)(val),
				(unsigned char)(CON0_TMR_RST_MASK),
				(unsigned char)(CON0_TMR_RST_SHIFT)
				);
}

unsigned int hl7005_get_otg_status(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON0),
				(unsigned char *)(&val),
				(unsigned char)(CON0_OTG_MASK),
				(unsigned char)(CON0_OTG_SHIFT)
				);
	return val;
}

void hl7005_set_en_stat(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON0),
				(unsigned char)(val),
				(unsigned char)(CON0_EN_STAT_MASK),
				(unsigned char)(CON0_EN_STAT_SHIFT)
				);
}

unsigned int hl7005_get_chip_status(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON0),
				(unsigned char *)(&val),
				(unsigned char)(CON0_STAT_MASK),
				(unsigned char)(CON0_STAT_SHIFT)
				);
	return val;
}

unsigned int hl7005_get_boost_status(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON0),
				(unsigned char *)(&val),
				(unsigned char)(CON0_BOOST_MASK),
				(unsigned char)(CON0_BOOST_SHIFT)
				);
	return val;

}

unsigned int hl7005_get_fault_status(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON0),
				(unsigned char *)(&val),
				(unsigned char)(CON0_FAULT_MASK),
				(unsigned char)(CON0_FAULT_SHIFT)
				);
	return val;
}

void hl7005_set_input_charging_current(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON1),
				(unsigned char)(val),
				(unsigned char)(CON1_LIN_LIMIT_MASK),
				(unsigned char)(CON1_LIN_LIMIT_SHIFT)
				);
}

unsigned int hl7005_get_input_charging_current(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON1),
				(unsigned char *)(&val),
				(unsigned char)(CON1_LIN_LIMIT_MASK),
				(unsigned char)(CON1_LIN_LIMIT_SHIFT)
				);

	return val;
}

void hl7005_set_v_low(unsigned int val)
{

	hl7005_config_interface((unsigned char)(HL7005_CON1),
				(unsigned char)(val),
				(unsigned char)(CON1_LOW_V_MASK),
				(unsigned char)(CON1_LOW_V_SHIFT)
				);
}

void hl7005_set_te(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON1),
				(unsigned char)(val),
				(unsigned char)(CON1_TE_MASK),
				(unsigned char)(CON1_TE_SHIFT)
				);
}

void hl7005_set_ce(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON1),
				(unsigned char)(val),
				(unsigned char)(CON1_CE_MASK),
				(unsigned char)(CON1_CE_SHIFT)
				);
}

void hl7005_set_hz_mode(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON1),
				(unsigned char)(val),
				(unsigned char)(CON1_HZ_MODE_MASK),
				(unsigned char)(CON1_HZ_MODE_SHIFT)
				);
}

void hl7005_set_opa_mode(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON1),
				(unsigned char)(val),
				(unsigned char)(CON1_OPA_MODE_MASK),
				(unsigned char)(CON1_OPA_MODE_SHIFT)
				);
}

void hl7005_set_oreg(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON2),
				(unsigned char)(val),
				(unsigned char)(CON2_OREG_MASK),
				(unsigned char)(CON2_OREG_SHIFT)
				);
}
void hl7005_set_otg_pl(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON2),
				(unsigned char)(val),
				(unsigned char)(CON2_OTG_PL_MASK),
				(unsigned char)(CON2_OTG_PL_SHIFT)
				);
}
void hl7005_set_otg_en(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON2),
				(unsigned char)(val),
				(unsigned char)(CON2_OTG_EN_MASK),
				(unsigned char)(CON2_OTG_EN_SHIFT)
				);
}

unsigned int hl7005_get_vender_code(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON3),
				(unsigned char *)(&val),
				(unsigned char)(CON3_VENDER_CODE_MASK),
				(unsigned char)(CON3_VENDER_CODE_SHIFT)
				);
	return val;
}
unsigned int hl7005_get_pn(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON3),
				(unsigned char *)(&val),
				(unsigned char)(CON3_PIN_MASK),
				(unsigned char)(CON3_PIN_SHIFT)
				);
	return val;
}

unsigned int hl7005_get_revision(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON3),
				(unsigned char *)(&val),
				(unsigned char)(CON3_REVISION_MASK),
				(unsigned char)(CON3_REVISION_SHIFT)
				);
	return val;
}

void hl7005_set_reset(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON4),
				(unsigned char)(val),
				(unsigned char)(CON4_RESET_MASK),
				(unsigned char)(CON4_RESET_SHIFT)
				);
}

void hl7005_set_iocharge(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON4),
				(unsigned char)(val),
				(unsigned char)(CON4_I_CHR_MASK),
				(unsigned char)(CON4_I_CHR_SHIFT)
				);
}

void hl7005_set_iterm(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON4),
				(unsigned char)(val),
				(unsigned char)(CON4_I_TERM_MASK),
				(unsigned char)(CON4_I_TERM_SHIFT)
				);
}

void hl7005_set_dis_vreg(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON5),
				(unsigned char)(val),
				(unsigned char)(CON5_DIS_VREG_MASK),
				(unsigned char)(CON5_DIS_VREG_SHIFT)
				);
}

void hl7005_set_io_level(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON5),
				(unsigned char)(val),
				(unsigned char)(CON5_IO_LEVEL_MASK),
				(unsigned char)(CON5_IO_LEVEL_SHIFT)
				);
}

unsigned int hl7005_get_sp_status(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON5),
				(unsigned char *)(&val),
				(unsigned char)(CON5_SP_STATUS_MASK),
				(unsigned char)(CON5_SP_STATUS_SHIFT)
				);
	return val;
}

unsigned int hl7005_get_en_level(void)
{
	unsigned char val = 0;

	hl7005_read_interface((unsigned char)(HL7005_CON5),
				(unsigned char *)(&val),
				(unsigned char)(CON5_EN_LEVEL_MASK),
				(unsigned char)(CON5_EN_LEVEL_SHIFT)
				);
	return val;
}

void hl7005_set_vsp(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON5),
				(unsigned char)(val),
				(unsigned char)(CON5_VSP_MASK),
				(unsigned char)(CON5_VSP_SHIFT)
				);
}

void hl7005_set_i_safe(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON6),
				(unsigned char)(val),
				(unsigned char)(CON6_ISAFE_MASK),
				(unsigned char)(CON6_ISAFE_SHIFT)
				);
}

void hl7005_set_v_safe(unsigned int val)
{
	hl7005_config_interface((unsigned char)(HL7005_CON6),
				(unsigned char)(val),
				(unsigned char)(CON6_VSAFE_MASK),
				(unsigned char)(CON6_VSAFE_SHIFT)
				);
}

void hl7005_dump_register()
{
	int i;

	for (i = 0;i < HL7005_REG_NUM;i++) {
		hl7005_read_byte(i, &hl7005_reg[i]);
		dprintf(CRITICAL, "[0x%x]=0x%x ", i, hl7005_reg[i]);
	}
}


int hl7005_enable_charging(bool en)
{
	unsigned int status = 0;

	if (en) {
		hl7005_set_ce(0);
		hl7005_set_hz_mode(0);
		hl7005_set_opa_mode(0);
	} else {
		hl7005_set_ce(1);
	}

	return status;
}

static int hl7005_set_cv_voltage(u32 cv)
{
	int status = 0;
	unsigned short int array_size;
	unsigned int set_cv_voltage;
	unsigned short int register_value;
	/*static kal_int16 pre_register_value; */
	array_size = ARRAY_SIZE(VBAT_CVTH);
	/*pre_register_value = -1; */
	set_cv_voltage = bmt_find_closest_level(VBAT_CVTH, array_size, cv);

	register_value =
	charging_parameter_to_value(VBAT_CVTH, array_size, set_cv_voltage);
	dprintf(CRITICAL, "charging_set_cv_voltage register_value=0x%x %d %d\n",
	 register_value, cv, set_cv_voltage);
	hl7005_set_oreg(register_value);

	return status;
}

static int hl7005_get_current(u32 *ichg)
{
	int status = 0;
	unsigned int array_size;
	unsigned char reg_value;

	array_size = ARRAY_SIZE(CSTH);
	hl7005_read_interface(0x1, &reg_value, 0x3, 0x6);	/* IINLIM */
	*ichg = charging_value_to_parameter(CSTH, array_size, reg_value);

	return status;
}

static int hl7005_set_current(u32 current_value)
{
	unsigned int status = 0;
	unsigned int set_chr_current;
	unsigned int array_size;
	unsigned int register_value;

	if (current_value <= 35000) {
		hl7005_set_io_level(1);
	} else {
		hl7005_set_io_level(0);
		array_size = ARRAY_SIZE(CSTH);
		set_chr_current = bmt_find_closest_level(CSTH, array_size, current_value);
		register_value = charging_parameter_to_value(CSTH, array_size, set_chr_current);
		hl7005_set_iocharge(register_value);
	}

	return status;
}

static int hl7005_get_input_current(u32 *aicr)
{
	unsigned int status = 0;
	unsigned int array_size;
	unsigned int register_value;

	array_size = ARRAY_SIZE(INPUT_CSTH);
	register_value = hl7005_get_input_charging_current();
	*aicr = charging_parameter_to_value(INPUT_CSTH, array_size, register_value);

	return status;
}

static int hl7005_set_input_current(u32 current_value)
{
	unsigned int status = 0;
	unsigned int set_chr_current;
	unsigned int array_size;
	unsigned int register_value;

	if (current_value > 50000) {
		register_value = 0x3;
	} else {
		array_size = ARRAY_SIZE(INPUT_CSTH);
		set_chr_current = bmt_find_closest_level(INPUT_CSTH, array_size, current_value);
		register_value =
	 charging_parameter_to_value(INPUT_CSTH, array_size, set_chr_current);
	}

	hl7005_set_input_charging_current(register_value);

	return status;
}

static int hl7005_get_charging_status(bool *is_done)
{
	unsigned int status = 0;
	unsigned int ret_val;

	ret_val = hl7005_get_chip_status();

	if (ret_val == 0x2)
		*is_done = true;
	else
		*is_done = false;

	return status;
}

static int hl7005_reset_watch_dog_timer()
{
	hl7005_set_tmr_rst(1);
	return 0;
}

void hl7005_charging_enable(void)
{
	hl7005_reg_config_interface(0x00,0xC0);
	hl7005_reg_config_interface(0x01,0x78);
	//hl7005_reg_config_interface(0x02,0x8e);
	hl7005_reg_config_interface(0x05,0x04);
	hl7005_reg_config_interface(0x04,0x1A); //146mA
}

void hl7005_hw_init(void)
{
#if defined(HIGH_BATTERY_VOLTAGE_SUPPORT)
	dprintf(CRITICAL, "[hl7005_hw_init] (0x06,0x77)\n");
	hl7005_reg_config_interface(0x06,0x77); // set ISAFE and HW CV point (4.34)
	hl7005_reg_config_interface(0x02,0xaa); // 4.34
#else
	dprintf(CRITICAL, "[hl7005_hw_init] (0x06,0x70)\n");
	hl7005_reg_config_interface(0x06,0x70); // set ISAFE
	hl7005_reg_config_interface(0x02,0x8e); // 4.2
#endif
}

