/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */

/* MediaTek Inc. (C) 2019. All rights reserved.
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
#include <platform/errno.h>
#include <platform/mt_i2c.h>
#include <platform/timer.h>
#include <printf.h>
#include <debug.h>
#include <string.h>

#include "tcpc_subpmic.h"

#if defined(TYPEC_MT6370)
#define MT6370_REG_IDLE_CTRL		(0x9B)
#elif defined(TYPEC_MT6360)
#define MT6360_REG_MODE_CTRL2		(0x8F)
#endif

struct subpmic_typec_info {
	struct mt_i2c_t i2c;
	int i2c_log_level;
};

static struct subpmic_typec_info g_sti = {
	.i2c = {
		.id = I2C5,
		.addr = 0x4E,
		.mode = HS_MODE,
		.speed = 3400,
		.pushpull = true,
	},
	.i2c_log_level = INFO,
};

static int subpmic_typec_write_byte(struct subpmic_typec_info *sti, u8 addr,
				   u8 data)
{
	struct mt_i2c_t *i2c = &sti->i2c;
	u8 write_buf[2] = {addr, data};
	int ret = I2C_OK;

	ret = i2c_write(i2c, write_buf, 2);
	if (ret != I2C_OK)
		dprintf(CRITICAL,
			"%s: I2CW[0x%02X] = 0x%02X failed, code = %d\n",
			__func__, addr, data, ret);
	else
		dprintf(sti->i2c_log_level, "%s: I2CW[0x%02X] = 0x%02X\n",
			__func__, addr, data);
	return ret;
}

static int subpmic_typec_read_byte(struct subpmic_typec_info *sti, u8 addr,
	u8 *data)
{
	struct mt_i2c_t *i2c = &sti->i2c;
	u8 rdata = addr;
	int ret = I2C_OK;

	ret = i2c_write_read(i2c, &rdata, 1, 1);
	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CR[0x%02X] failed, code = %d\n",
			__func__, addr, ret);
	else {
		dprintf(sti->i2c_log_level, "%s: I2CR[0x%02X] = 0x%02X\n",
			__func__, addr, rdata);
		*data = rdata;
	}
	return ret;
}

static int subpmic_typec_update_bits(struct subpmic_typec_info *sti, u8 addr,
	u8 mask, u8 data)
{
	u8 rdata = 0;
	int ret = 0;

	ret = subpmic_typec_read_byte(sti, addr, &rdata);
	if (ret != I2C_OK)
		return ret;
	rdata &= ~mask;
	rdata |= (data & mask);
	return subpmic_typec_write_byte(sti, addr, rdata);
}

static inline int subpmic_typec_set_bit(struct subpmic_typec_info *sti, u8 addr,
				       u8 mask)
{
	return subpmic_typec_update_bits(sti, addr, mask, mask);
}

static inline int subpmic_typec_clr_bit(struct subpmic_typec_info *sti, u8 addr,
				       u8 mask)
{
	return subpmic_typec_update_bits(sti, addr, mask, 0);
}

int pd_reset_adapter(void)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: ++\n", __func__);
#if defined(TYPEC_MT6370)
	/* CK_300K from 320K, SHIPPING off, AUTOIDLE enable, TIMEOUT = 32ms */
	ret = subpmic_typec_write_byte(&g_sti, MT6370_REG_IDLE_CTRL, 0x3A);
#elif defined(TYPEC_MT6360)
	/* SHIPPING off, AUTOIDLE off */
	ret = subpmic_typec_write_byte(&g_sti, MT6360_REG_MODE_CTRL2, 0x22);
#endif
	if (ret < 0) {
		dprintf(CRITICAL, "%s: shipping mode off fail\n", __func__);
		goto out;
	}
	/* Set CC (open, open) */
	ret = subpmic_typec_write_byte(&g_sti, 0x1A, 0x0F);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: set cc open fail\n", __func__);
		goto out;
	}
	mdelay(300);
	/* SHIPPING on */
#if defined(TYPEC_MT6370)
	ret = subpmic_typec_write_byte(&g_sti, MT6370_REG_IDLE_CTRL, 0xC0);
#elif defined(TYPEC_MT6360)
	ret = subpmic_typec_write_byte(&g_sti, MT6360_REG_MODE_CTRL2, 0x52);
#endif
	if (ret < 0)
		dprintf(CRITICAL, "%s: shipping mode on fail\n", __func__);
out:
	dprintf(CRITICAL, "%s: --\n", __func__);
	return ret;
}
