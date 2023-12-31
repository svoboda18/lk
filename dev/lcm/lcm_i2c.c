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
#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
#include <debug.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <platform.h>
#include <platform/mt_typedefs.h>
#include <platform/upmu_common.h>
#include <platform/upmu_hw.h>
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <cust_i2c.h>

#include "lcm_define.h"
#include "lcm_drv.h"
#include "lcm_i2c.h"


static struct mt_i2c_t tps65132_i2c;

#define LCM_I2C_ID  I2C_I2C_LCD_BIAS_CHANNEL
/* Since i2c will left shift 1 bit, we need to set FAN5405 I2C address to >>1 */
#define LCM_I2C_ADDR    (I2C_I2C_LCD_BIAS_SLAVE_7_BIT_ADDR >> 1)
#define LCM_I2C_MODE    ST_MODE
#define LCM_I2C_SPEED   100


static LCM_STATUS _lcm_i2c_check_data(char type, const LCM_DATA_T2 *t2)
{
	switch (type) {
		case LCM_I2C_WRITE:
			if (t2->cmd > 0xFF) {
				dprintf(0, "[LCM][ERROR] %s: %d \n", __func__, (unsigned int)t2->cmd);
				return LCM_STATUS_ERROR;
			}
			if (t2->data > 0xFF) {
				dprintf(0, "[LCM][ERROR] %s: %d \n", __func__, (unsigned int)t2->data);
				return LCM_STATUS_ERROR;
			}
			break;

		default:
			dprintf(0, "[LCM][ERROR] %s: %d\n", __func__, (unsigned int)type);
			return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}


static int _lcm_i2c_write_bytes(kal_uint8 addr, kal_uint8 value)
{
	kal_int32 ret_code = I2C_OK;
	kal_uint8 write_data[2];
	kal_uint16 len;

	write_data[0]= addr;
	write_data[1] = value;

	tps65132_i2c.id = LCM_I2C_ID;
	/* Since i2c will left shift 1 bit, we need to set FAN5405 I2C address to >>1 */
	tps65132_i2c.addr = LCM_I2C_ADDR;
	tps65132_i2c.mode = LCM_I2C_MODE;
	tps65132_i2c.speed = LCM_I2C_SPEED;
	len = 2;

	ret_code = i2c_write(&tps65132_i2c, write_data, len);
	if (ret_code<0)
		dprintf(0, "[LCM][ERROR] %s: %d\n", __func__, ret_code);

	return ret_code;
}


LCM_STATUS lcm_i2c_set_data(char type, const LCM_DATA_T2 *t2)
{
	kal_uint32 ret_code = I2C_OK;

	// check parameter is valid
	if (LCM_STATUS_OK == _lcm_i2c_check_data(type, t2)) {
		switch (type) {
			case LCM_I2C_WRITE:
				ret_code = _lcm_i2c_write_bytes((kal_uint8)t2->cmd, (kal_uint8)t2->data);
				break;

			default:
				dprintf(0, "[LCM][ERROR] %s: %d\n", __func__, (unsigned int)type);
				return LCM_STATUS_ERROR;
		}
	} else {
		dprintf(0, "[LCM][ERROR] %s: %d, 0x%x, 0x%x\n", __func__, (unsigned int)type, (unsigned int)t2->cmd, (unsigned int)t2->data);
		return LCM_STATUS_ERROR;
	}

	if (ret_code != I2C_OK) {
		dprintf(0, "[LCM][ERROR] %s: 0x%x, 0x%x, %d\n", __func__, (unsigned int)t2->cmd, (unsigned int)t2->data, ret_code);
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}
#endif

