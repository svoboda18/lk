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

#include <platform/mt_i2c.h>
#include <platform/mt_gpio.h>
#include <platform/mt6311.h>
#include <printf.h>

#ifdef MACH_FPGA
#else
#include "cust_i2c.h"
#endif

/**********************************************************
  *   I2C Slave Setting
  *********************************************************/
#define mt6311_SLAVE_ADDR_WRITE   0xD6
#define mt6311_SLAVE_ADDR_Read    0xD7

/**********************************************************
  *   Global Variable
  *********************************************************/
#ifdef I2C_EXT_BUCK_CHANNEL
#define mt6311_I2C_ID I2C_EXT_BUCK_CHANNEL
#else
#define mt6311_I2C_ID I2C2
#endif

static struct mt_i2c_t mt6311_i2c;

int g_mt6311_driver_ready=0;
int g_mt6311_hw_exist=0;

#define mt6311_print(fmt, args...)   \
do {                                    \
    dprintf(CRITICAL, fmt, ##args); \
} while(0)

kal_uint32 g_mt6311_cid=0;

/**********************************************************
  *
  *   [I2C Function For Read/Write mt6311]
  *
  *********************************************************/
kal_uint32 mt6311_write_byte(kal_uint8 addr, kal_uint8 value)
{
	int ret_code = I2C_OK;
	kal_uint8 write_data[2];
	kal_uint16 len;

	write_data[0]= addr;
	write_data[1] = value;

	mt6311_i2c.id = mt6311_I2C_ID;
	/* Since i2c will left shift 1 bit, we need to set mt6311 I2C address to >>1 */
	mt6311_i2c.addr = (mt6311_SLAVE_ADDR_WRITE >> 1);
	mt6311_i2c.mode = ST_MODE;
	mt6311_i2c.speed = 100;
	mt6311_i2c.pushpull = 1;
	len = 2;

	ret_code = i2c_write(&mt6311_i2c, write_data, len);
	//mt6311_print("%s: i2c_write: ret_code: %d\n", __func__, ret_code);

	if (ret_code == 0)
		return 1; // ok
	else
		return 0; // fail
}

kal_uint32 mt6311_read_byte (kal_uint8 addr, kal_uint8 *dataBuffer)
{
	int ret_code = I2C_OK;
	kal_uint16 len;
	*dataBuffer = addr;

	mt6311_i2c.id = mt6311_I2C_ID;
	/* Since i2c will left shift 1 bit, we need to set mt6311 I2C address to >>1 */
	mt6311_i2c.addr = (mt6311_SLAVE_ADDR_WRITE >> 1);
	mt6311_i2c.mode = ST_MODE;
	mt6311_i2c.speed = 100;
	mt6311_i2c.pushpull = 1;
	len = 1;

	ret_code = i2c_write_read(&mt6311_i2c, dataBuffer, len, len);
	//mt6311_print("%s: i2c_read: ret_code: %d\n", __func__, ret_code);

	if (ret_code == 0)
		return 1; // ok
	else
		return 0; // fail
}

/**********************************************************
  *
  *   [Read / Write Function]
  *
  *********************************************************/
kal_uint32 mt6311_read_interface (kal_uint8 RegNum, kal_uint8 *val, kal_uint8 MASK, kal_uint8 SHIFT)
{
	kal_uint8 mt6311_reg = 0;
	kal_uint32 ret = 0;

	//mt6311_print("--------------------------------------------------PL\n");

	ret = mt6311_read_byte(RegNum, &mt6311_reg);
	//mt6311_print("[mt6311_read_interface] Reg[%x]=0x%x\n", RegNum, mt6311_reg);

	mt6311_reg &= (MASK << SHIFT);
	*val = (mt6311_reg >> SHIFT);
	//mt6311_print("[mt6311_read_interface] val=0x%x\n", *val);

	return ret;
}

kal_uint32 mt6311_config_interface (kal_uint8 RegNum, kal_uint8 val, kal_uint8 MASK, kal_uint8 SHIFT)
{
	kal_uint8 mt6311_reg = 0;
	kal_uint32 ret = 0;

	//mt6311_print("--------------------------------------------------PL\n");

	ret = mt6311_read_byte(RegNum, &mt6311_reg);
	//mt6311_print("[mt6311_config_interface] Reg[%x]=0x%x\n", RegNum, mt6311_reg);

	mt6311_reg &= ~(MASK << SHIFT);
	mt6311_reg |= (val << SHIFT);

	ret = mt6311_write_byte(RegNum, mt6311_reg);
	//mt6311_print("[mt6311_config_interface] write Reg[%x]=0x%x\n", RegNum, mt6311_reg);

	// Check
	//mt6311_read_byte(RegNum, &mt6311_reg);
	//mt6311_print("[mt6311_config_interface] Check Reg[%x]=0x%x\n", RegNum, mt6311_reg);

	return ret;
}

kal_uint32 mt6311_get_reg_value(kal_uint32 reg)
{
	kal_uint32 ret=0;
	kal_uint8 reg_val=0;

	ret=mt6311_read_interface( (kal_uint8) reg, &reg_val, 0xFF, 0x0);

	if (ret==0) mt6311_print("%d", ret);
	return reg_val;
}

void mt6311_dump_register(void)
{
	kal_uint8 i=0x0;
	kal_uint8 i_max=0x2;//0xD5

	for (i=0x0; i<=i_max; i++) {
		mt6311_print("[0x%x]=0x%x ", i, mt6311_get_reg_value(i));
	}
}

int get_mt6311_i2c_ch_num(void)
{
	return mt6311_I2C_ID;
}

void mt6311_hw_init(void)
{
	//in kernel
}

kal_uint8 mt6311_get_cid(void)
{
	kal_uint8 ret=0;
	kal_uint8 val=0;

	ret=mt6311_read_interface( (kal_uint8)(MT6311_CID),
	                           (&val),
	                           (kal_uint8)(MT6311_PMIC_CID_MASK),
	                           (kal_uint8)(MT6311_PMIC_CID_SHIFT)
	                         );

	if (ret==0) mt6311_print("%d", ret);
	return val;
}

kal_uint8 mt6311_get_swcid(void)
{
	kal_uint8 ret=0;
	kal_uint8 val=0;

	ret=mt6311_read_interface( (kal_uint8)(MT6311_SWCID),
	                           (&val),
	                           (kal_uint8)(MT6311_PMIC_SWCID_MASK),
	                           (kal_uint8)(MT6311_PMIC_SWCID_SHIFT)
	                         );

	if (ret==0) mt6311_print("%d", ret);
	return val;
}

kal_uint32 update_mt6311_chip_id(void)
{
	kal_uint32 id=0;
	kal_uint32 id_l=0;
	kal_uint32 id_r=0;

	id_l=mt6311_get_cid();
	id_r=mt6311_get_swcid();
	id=((id_l<<8)|(id_r));

	g_mt6311_cid=id;

	mt6311_print("[update_mt6311_chip_id] id_l=0x%x, id_r=0x%x, id=0x%x\n", id_l, id_r, id);

	return id;
}

kal_uint32 mt6311_get_chip_id(void)
{
	if (g_mt6311_cid==0)
		update_mt6311_chip_id();

	mt6311_print("[mt6311_get_chip_id] g_mt6311_cid=0x%x\n", g_mt6311_cid);

	return g_mt6311_cid;
}

void mt6311_hw_component_detect(void)
{
	update_mt6311_chip_id();

	if ( (mt6311_get_chip_id()==PMIC6311_E1_CID_CODE) ||
	        (mt6311_get_chip_id()==PMIC6311_E2_CID_CODE) ||
	        (mt6311_get_chip_id()==PMIC6311_E3_CID_CODE)
	   ) {
		g_mt6311_hw_exist=1;
	} else {
		g_mt6311_hw_exist=0;
	}
	mt6311_print("[mt6311_hw_component_detect] exist=%d\n", g_mt6311_hw_exist);
}

int is_mt6311_sw_ready(void)
{
	mt6311_print("g_mt6311_driver_ready=%d\n", g_mt6311_driver_ready);

	return g_mt6311_driver_ready;
}

int is_mt6311_exist(void)
{
	mt6311_print("g_mt6311_hw_exist=%d\n", g_mt6311_hw_exist);

	return g_mt6311_hw_exist;
}

void mt6311_driver_probe(void)
{
#ifdef I2C_EXT_BUCK_CHANNEL
	mt6311_print("[mt6311_driver_probe] LK I2C_EXT_BUCK_CHANNEL=%d.\n", I2C_EXT_BUCK_CHANNEL);
	mt6311_hw_component_detect();
	if (g_mt6311_hw_exist==1) {
		mt6311_hw_init();
		mt6311_dump_register();
	} else {
		mt6311_print("[mt6311_driver_probe] LK mt6311 is not exist\n");
	}
	g_mt6311_driver_ready=1;
#else
	mt6311_print("[mt6311_driver_probe] LK No I2C_EXT_BUCK_CHANNEL (%d)\n", mt6311_I2C_ID);
	g_mt6311_hw_exist=0;
	g_mt6311_driver_ready=1;
#endif

	mt6311_print("[mt6311_driver_probe] LK g_mt6311_hw_exist=%d, g_mt6311_driver_ready=%d!!\n",
	             g_mt6311_hw_exist, g_mt6311_driver_ready);
}
