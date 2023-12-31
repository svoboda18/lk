/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part,
* shall be strictly prohibited.
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
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY
* ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY
* THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL
* ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
* RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*/

#include <platform/mt_typedefs.h>
#include <platform/errno.h>
#include <platform/mt_i2c.h>
#include <printf.h>
#include <debug.h>
#include <string.h>

#define CRC8_TABLE_SIZE	(256)
static u8 crc8_table[CRC8_TABLE_SIZE];

struct mt6360_pmic_info {
	struct mt_i2c_t i2c;
	int i2c_log_level;
};

static struct mt6360_pmic_info g_mpi = {
	.i2c = {
		.id = I2C5,
		.addr = 0x1a,
		.mode = FS_MODE,
		.speed = 400,
	},
	.i2c_log_level = INFO,
};

static void crc8_populate_msb(u8 table[CRC8_TABLE_SIZE], u8 polynomial)
{
	int i, j;
	const u8 msbit = 0x80;
	u8 t = msbit;

	table[0] = 0;

	for (i = 1; i < CRC8_TABLE_SIZE; i *= 2) {
		t = (t << 1) ^ (t & msbit ? polynomial : 0);
		for (j = 0; j < i; j++)
			table[i+j] = table[j]^t;
	}
}

static u8 crc8(const u8 table[CRC8_TABLE_SIZE], u8 *pdata, size_t nbytes, u8 crc)
{
	while (nbytes-- > 0)
		crc = table[(crc ^ *pdata++) & 0xff];

	return crc;
}

/* ========================= */
/* I2C operations */
/* ========================= */
static int mt6360_pmic_write_byte(struct mt6360_pmic_info *mpi, u8 addr, u8 data)
{
	struct mt_i2c_t *i2c = &mpi->i2c;
	int ret = I2C_OK;
	int len = 1;
	u8 chunk[8] = {0};

	if ((addr & 0xc0) != 0) {
		dprintf(CRITICAL, "%s: not support addr [%x]\n", __func__, addr);
		return -EINVAL;
	}
	chunk[0] = (i2c->addr & 0x7f) << 1;
	chunk[1] = (addr & 0x3f)| ((len - 1) << 6);
	memcpy(chunk + 2, &data, len);
	chunk[2+len] = crc8(crc8_table, chunk, 2+len, 0);
	ret = i2c_write(i2c, chunk+1, len+3);
	if (ret != I2C_OK)
		dprintf(CRITICAL,
			"%s: I2CW[0x%02X] = 0x%02X failed, ret = %d\n",
			__func__, addr, data, ret);
	else
		dprintf(mpi->i2c_log_level, "%s: I2CW[0x%02X] = 0x%02X\n",
			__func__, addr, data);
	return ret;
}

static int mt6360_pmic_read_byte(struct mt6360_pmic_info *mpi, u8 addr, u8 *data)
{
	struct mt_i2c_t *i2c = &mpi->i2c;
	int ret = I2C_OK;
	int len = 1;
	u8 chunk[8] = {0};
	u8 temp[2] = {0};

	chunk[0] = ((i2c->addr & 0x7f) << 1) + 1;
	chunk[1] = (addr & 0x3f) | ((len - 1) << 6);
	temp[0] = chunk[1];
	ret = i2c_write_read(i2c, &temp[0], 1, len + 1);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s: I2CR[0x%02X] failed, ret = %d\n",
			__func__, addr, ret);
		return ret;
	}
	chunk[2] = temp[0];
	chunk[3] = temp[1];
	chunk[7] = crc8(crc8_table, chunk, 2 + len, 0);
	if (chunk[2+len] != chunk[7]) {
		dprintf(CRITICAL, "%s: crc check fail\n", __func__);
		return -EINVAL;
	}
	dprintf(mpi->i2c_log_level, "%s: I2CR[0x%02X] = 0x%02X\n",
		__func__, addr, chunk[2]);
	memcpy(data, chunk+2, len);
	return ret;
}

/* ========================= */
/* GLOBAL operations */
/* ========================= */
int mt6360_pmic_enable_poweroff_seq(bool en)
{
	int i, ret = 0;
	u8 seq_delay[4] = { 0x06, 0x04, 0x00, 0x02 };

	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);
	for (i = 0; i < 4; i++) {
		ret = mt6360_pmic_write_byte(&g_mpi, 0x07 + i,
					en ? seq_delay[i] : 0x00);
		if (ret < 0) {
			dprintf(CRITICAL,
				"%s: set buck(%d) fail\n", __func__, i);
			return ret;
		}
	}
	return 0;
}

int mt6360_pmic_i2c_probe(void)
{
	dprintf(CRITICAL, "%s: ++\n", __func__);
	crc8_populate_msb(crc8_table, 0x7);
	dprintf(CRITICAL, "%s: --\n", __func__);
	return 0;
}
