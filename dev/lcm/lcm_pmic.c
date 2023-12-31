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

#ifndef MACH_FPGA
#include <lcm_pmic.h>

#ifdef MTK_RT5081_PMU_CHARGER_SUPPORT
#include <cust_i2c.h>
	#define I2C_PMU_CHANNEL I2C_RT5081_PMU_CHANNEL
	#define I2C_PMU_SLAVE_7_BIT_ADDR I2C_RT5081_PMU_SLAVE_7_BIT_ADDR
#else
#ifdef MTK_MT6370_PMU
#include <platform/mt_pmu.h>
	#define I2C_PMU_CHANNEL I2C_SUBPMIC_PMU_CHANNEL
	#define I2C_PMU_SLAVE_7_BIT_ADDR I2C_SUBPMIC_PMU_SLAVE_7_BIT_ADDR
#endif
#endif

#if  defined(MTK_RT5081_PMU_CHARGER_SUPPORT) || defined(MTK_MT6370_PMU)
static int PMU_read_byte (kal_uint8 addr, kal_uint8 *dataBuffer)
{
	kal_uint32 ret = I2C_OK;
	kal_uint16 len;
	struct mt_i2c_t PMU_i2c;
	*dataBuffer = addr;

	PMU_i2c.id = I2C_PMU_CHANNEL;
	PMU_i2c.addr = I2C_PMU_SLAVE_7_BIT_ADDR;
	PMU_i2c.mode = ST_MODE;
	PMU_i2c.speed = 100;
	len = 1;

	ret = i2c_write_read(&PMU_i2c, dataBuffer, len, len);
	if (I2C_OK != ret)
		dprintf(1, "[LK/LCM] %s: i2c_read  failed! ret: %d\n", __func__, ret);
	return ret;
}

static int PMU_write_byte(kal_uint8 addr, kal_uint8 value)
{
	kal_uint32 ret_code = I2C_OK;
	kal_uint8 write_data[2];
	kal_uint16 len;
	struct mt_i2c_t PMU_i2c;

	write_data[0] = addr;
	write_data[1] = value;

	PMU_i2c.id = I2C_PMU_CHANNEL;
	PMU_i2c.addr = I2C_PMU_SLAVE_7_BIT_ADDR;
	PMU_i2c.mode = ST_MODE;
	PMU_i2c.speed = 100;
	len = 2;

	ret_code = i2c_write(&PMU_i2c, write_data, len);

	return ret_code;
}

int PMU_REG_MASK (kal_uint8 addr, kal_uint8 val, kal_uint8 mask)
{
	kal_uint8 PMU_reg = 0;
	kal_uint32 ret = 0;

	ret = PMU_read_byte(addr, &PMU_reg);

	PMU_reg &= ~mask;
	PMU_reg |= val;

	ret = PMU_write_byte(addr, PMU_reg);

	return ret;
}
#else
int PMU_REG_MASK (kal_uint8 addr, kal_uint8 val, kal_uint8 mask)
{
	return 0;
}

#endif
#endif
