/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2017. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */
#include <platform/mt_gpio.h>

#if !defined(FPGA_PLATFORM) && !defined(USE_DTB_NO_DWS)
#include <cust_power.h>
#include <cust_gpio_boot.h>
#endif

#include <platform/mt_reg_base.h>

#include <debug.h>
#define GPIO_INIT_DEBUG
/*----------------------------------------------------------------------------*/
#define GPIOTAG "[GPIO] "
#define GPIODBG(fmt, arg...)    dprintf(INFO, GPIOTAG "%s: " fmt, __FUNCTION__ ,##arg)
#define GPIOERR(fmt, arg...)    dprintf(INFO, GPIOTAG "%s: " fmt, __FUNCTION__ ,##arg)
#define GPIOVER(fmt, arg...)    dprintf(INFO, GPIOTAG "%s: " fmt, __FUNCTION__ ,##arg)

#define GPIO_WR32(addr, data)   DRV_WriteReg32(addr,data)
#define GPIO_RD32(addr)         DRV_Reg32(addr)

#define ADDR_BIT 0
#define VAL_BIT  1
#define MASK_BIT 2
/*----------------------------------------------------------------------------*/
#ifdef FPGA_PLATFORM
void mt_gpio_set_default(void)
{
	return;
}
#else

#include <platform/gpio_init.h>

#ifdef USE_DTB_NO_DWS
#include <libfdt.h>
#include <lk_builtin_dtb.h>
extern void msdc_gpio_and_pad_init_by_id(int id);
#define ELEMENTS_PER_GPIO       7
#define GPIO_DT_NODE_NAME       "/gpio@10005000"
#define GPIO_DT_NODE_PROP_NAME  "gpio_init_default"
int mt_gpio_get_default_chip_from_dtb(void)
{
	int off = fdt_path_offset(get_lk_overlayed_dtb(), GPIO_DT_NODE_NAME);
	unsigned int *data;
	int len = 0, pin, j;

	dprintf(INFO, "[GPIO] Found " GPIO_DT_NODE_NAME "at offset %d\n", off);
	if (off < 0) {
		dprintf(CRITICAL, "[GPIO] Failed to find " GPIO_DT_NODE_NAME " in dtb\n");
		return -1;
	} else {
		data = (unsigned int *)fdt_getprop(get_lk_overlayed_dtb(), off, GPIO_DT_NODE_PROP_NAME, &len);
		if (len <= 0 || !data) {
			dprintf(CRITICAL, "[GPIO] Fail to found property " GPIO_DT_NODE_PROP_NAME "\n");
			return -1;
		}
		dprintf(INFO, "[GPIO] Found perperty at 0x%08x, len %d\n", (unsigned int)data, len);
	}

	if ((len > 0) && ((len % ELEMENTS_PER_GPIO) == 0)) {
		len /= (ELEMENTS_PER_GPIO * 4); //Per element use 4 bytes */
		for (j = 0; j < len; j++) {
			pin = fdt32_to_cpu(*data);

			if (pin >= MT_GPIO_BASE_MAX) {
				data += 7;
				continue;
			}

			data++;
			gpio_array[pin].mode = (unsigned char) fdt32_to_cpu(*data);

			data++;
			gpio_array[pin].dir = (unsigned char) fdt32_to_cpu(*data);

			data++;
			gpio_array[pin].dataout = (unsigned char) fdt32_to_cpu(*data);

			data++;
			gpio_array[pin].pullen = (unsigned char) fdt32_to_cpu(*data);

			data++;
			gpio_array[pin].pull = (unsigned char) fdt32_to_cpu(*data);

			data++;
			gpio_array[pin].smt = (unsigned char) fdt32_to_cpu(*data);

			data++;

			#if 0
			dprintf(INFO, "GPIO: %d %d %d %d %d %d %d\n",
				pin,
				gpio_array[pin].mode,
				gpio_array[pin].dir,
				gpio_array[pin].dataout,
				gpio_array[pin].pullen,
				gpio_array[pin].pull,
				gpio_array[pin].smt
				);
			#endif
		}
	}

	return 0;
}
#endif

void mt_gpio_set_default_chip(void)
{
	unsigned pin = 0;

#ifdef USE_DTB_NO_DWS
	if (mt_gpio_get_default_chip_from_dtb() < 0)
		return;
#endif

	for (pin = 0; pin < MT_GPIO_BASE_MAX; pin++) {
		if (pin>=122 && pin<=133) continue;

		/* set GPIOx_MODE*/
		mt_set_gpio_mode(0x80000000 + pin , gpio_array[pin].mode);

		/* set GPIOx_DIR*/
		if (gpio_array[pin].dir != 0xFF)
			mt_set_gpio_dir(0x80000000 + pin, gpio_array[pin].dir);

		/* set GPIOx_PULL*/
		if (gpio_array[pin].pull != 0xFF)
			mt_set_gpio_pull_select(0x80000000 + pin, gpio_array[pin].pull);

		/* set GPIOx_PULLEN*/
		if (gpio_array[pin].pullen != 0xFF)
			mt_set_gpio_pull_enable(0x80000000 + pin , gpio_array[pin].pullen);

		/* set GPIOx_DATAOUT*/
		if (gpio_array[pin].dataout != 0xFF)
			mt_set_gpio_out(0x80000000 + pin, gpio_array[pin].dataout);

		/* set GPIO0_SMT */
		if (gpio_array[pin].smt != 0xFF)
			mt_set_gpio_smt(0x80000000 + pin, gpio_array[pin].smt);
	}
}
void mt_gpio_set_driving(void)
{
#if 0
	u32 val;
	u32 mask;

	/* [MT6571] for MD BSI request */
	mask = 0x3000;
	val = GPIO_RD32(IO_CFG_T_BASE+0xF0);
	val &= ~(mask);
	val |= (0x0000 & mask);
	GPIO_WR32(IO_CFG_T_BASE+0xF0, val);
	/* [MT6571] end */

	/* [MT6571] for desense request (AUD IO) */
	mask = 0x30;
	val = GPIO_RD32(IO_CFG_L_BASE+0xA0);
	val &= ~(mask);
	val |= (0x00 & mask);
	GPIO_WR32(IO_CFG_L_BASE+0xA0, val);
	/* [MT6571] end */
#endif
}
void mt_gpio_set_power(u8 mc1_power,u8 mc2_power, u8 sim1_power, u8 sim2_power)
{
#if 0
	u32 reg=0;

	//sim1
	if (sim1_power == GPIO_VIO28) {

		reg = GPIO_RD32(IOCFG_0_BASE+0x050);
		//reg |= (0x6000);
		GPIO_WR32(IOCFG_0_BASE+0x0c28, reg);
	} else {
		reg = GPIO_RD32(IOCFG_0_BASE+0x050);
		reg &= ~(0x3f<<12);
		GPIO_WR32(IOCFG_0_BASE+0x050, reg);
	}
	//sim2
	if (sim2_power == GPIO_VIO28) {

		reg = GPIO_RD32(IOCFG_0_BASE+0x050);
		//reg |= 0x0c;
		GPIO_WR32(IOCFG_0_BASE+0x050, reg);
	} else {
		reg = GPIO_RD32(IOCFG_0_BASE+0x050);
		reg &= ~(0x3f<<6);
		GPIO_WR32(IOCFG_0_BASE+0x050, reg);
	}
#endif
}

/*FIX ME: create a customized file for platform-specific operations */
void mt_gpio_set_avoid_leakage(void)
{
#if 0
#ifdef MTK_EMMC_SUPPORT
	GPIO_WR32(IO_CFG_B_BASE+0x58, 0x220000);
#endif
#endif
}

void mt_gpio_set_default(void)
{
	//mt_gpio_set_avoid_leakage();
	mt_gpio_set_default_chip();
	//mt_gpio_set_driving();
	//mt_gpio_set_power();
	return;
}
/*----------------------------------------------------------------------------*/
#if CHECK_POINT_TEST
#if defined(GPIO_INIT_DEBUG)
static GPIO_REGS saved;
#endif

void mt_gpio_checkpoint_save(void)
{
#if defined(GPIO_INIT_DEBUG)
	GPIO_REGS *pReg = (GPIO_REGS*)(GPIO_BASE);
	GPIO_REGS *cur = &saved;
	int idx;

	memset(cur, 0x00, sizeof(*cur));
	for (idx = 0; idx < sizeof(pReg->dir)/sizeof(pReg->dir[0]); idx++)
		cur->dir[idx].val = GPIO_RD32(&pReg->dir[idx]);
	#if 0
	for (idx = 0; idx < sizeof(pReg->pullen)/sizeof(pReg->pullen[0]); idx++)
		cur->pullen[idx].val = GPIO_RD32(&pReg->pullen[idx]);
	for (idx = 0; idx < sizeof(pReg->pullsel)/sizeof(pReg->pullsel[0]); idx++)
		cur->pullsel[idx].val =GPIO_RD32(&pReg->pullsel[idx]);
	#endif
	for (idx = 0; idx < sizeof(pReg->dout)/sizeof(pReg->dout[0]); idx++)
		cur->dout[idx].val = GPIO_RD32(&pReg->dout[idx]);
	for (idx = 0; idx < sizeof(pReg->mode)/sizeof(pReg->mode[0]); idx++)
		cur->mode[idx].val = GPIO_RD32(&pReg->mode[idx]);
#endif
}
/*----------------------------------------------------------------------------*/
EXPORT_SYMBOL(mt_gpio_checkpoint_save);
/*----------------------------------------------------------------------------*/
void mt_gpio_dump_diff(GPIO_REGS* pre, GPIO_REGS* cur)
{
#if defined(GPIO_INIT_DEBUG)
	GPIO_REGS *pReg = (GPIO_REGS*)(GPIO_BASE);
	int idx;
	unsigned char* p = (unsigned char*)pre;
	unsigned char* q = (unsigned char*)cur;

	GPIOVER("------ dumping difference between %p and %p ------\n", pre, cur);
	for (idx = 0; idx < sizeof(pReg->dir)/sizeof(pReg->dir[0]); idx++) {
		if (pre->dir[idx].val != cur->dir[idx].val)
			GPIOVER("diff: dir[%2d]    : 0x%08X <=> 0x%08X\n", idx, pre->dir[idx].val, cur->dir[idx].val);
	}
	#if 0
	for (idx = 0; idx < sizeof(pReg->pullen)/sizeof(pReg->pullen[0]); idx++) {
		if (pre->pullen[idx].val != cur->pullen[idx].val)
			GPIOVER("diff: pullen[%2d] : 0x%08X <=> 0x%08X\n", idx, pre->pullen[idx].val, cur->pullen[idx].val);
	}
	for (idx = 0; idx < sizeof(pReg->pullsel)/sizeof(pReg->pullsel[0]); idx++) {
		if (pre->pullsel[idx].val != cur->pullsel[idx].val)
			GPIOVER("diff: pullsel[%2d]: 0x%08X <=> 0x%08X\n", idx, pre->pullsel[idx].val, cur->pullsel[idx].val);
	}
	#endif
	for (idx = 0; idx < sizeof(pReg->dout)/sizeof(pReg->dout[0]); idx++) {
		if (pre->dout[idx].val != cur->dout[idx].val)
			GPIOVER("diff: dout[%2d]   : 0x%08X <=> 0x%08X\n", idx, pre->dout[idx].val, cur->dout[idx].val);
	}
	for (idx = 0; idx < sizeof(pReg->mode)/sizeof(pReg->mode[0]); idx++) {
		if (pre->mode[idx].val != cur->mode[idx].val)
			GPIOVER("diff: mode[%2d]   : 0x%08X <=> 0x%08X\n", idx, pre->mode[idx].val, cur->mode[idx].val);
	}

	for (idx = 0; idx < sizeof(*pre); idx++) {
		if (p[idx] != q[idx])
			GPIOVER("diff: raw[%2d]: 0x%02X <=> 0x%02X\n", idx, p[idx], q[idx]);
	}
	GPIOVER("memcmp(%p, %p, %d) = %d\n", p, q, sizeof(*pre), memcmp(p, q, sizeof(*pre)));
	GPIOVER("------ dumping difference end --------------------------------\n");
#endif
}
/*----------------------------------------------------------------------------*/
void mt_gpio_checkpoint_compare(void)
{
#if defined(GPIO_INIT_DEBUG)
	GPIO_REGS *pReg = (GPIO_REGS*)(GPIO_BASE);
	GPIO_REGS latest;
	GPIO_REGS *cur = &latest;
	int idx;

	memset(cur, 0x00, sizeof(*cur));
	for (idx = 0; idx < sizeof(pReg->dir)/sizeof(pReg->dir[0]); idx++)
		cur->dir[idx].val = GPIO_RD32(&pReg->dir[idx]);
	#if 0
	for (idx = 0; idx < sizeof(pReg->pullen)/sizeof(pReg->pullen[0]); idx++)
		cur->pullen[idx].val = GPIO_RD32(&pReg->pullen[idx]);
	for (idx = 0; idx < sizeof(pReg->pullsel)/sizeof(pReg->pullsel[0]); idx++)
		cur->pullsel[idx].val =GPIO_RD32(&pReg->pullsel[idx]);
	#endif
	for (idx = 0; idx < sizeof(pReg->dout)/sizeof(pReg->dout[0]); idx++)
		cur->dout[idx].val = GPIO_RD32(&pReg->dout[idx]);
	for (idx = 0; idx < sizeof(pReg->mode)/sizeof(pReg->mode[0]); idx++)
		cur->mode[idx].val = GPIO_RD32(&pReg->mode[idx]);

	//mt_gpio_dump_diff(&latest, &saved);
	//GPIODBG("memcmp(%p, %p, %d) = %d\n", &latest, &saved, sizeof(GPIO_REGS), memcmp(&latest, &saved, sizeof(GPIO_REGS)));
	if (memcmp(&latest, &saved, sizeof(GPIO_REGS))) {
		GPIODBG("checkpoint compare fail!!\n");
		GPIODBG("dump checkpoint....\n");
		//mt_gpio_dump(&saved);
		GPIODBG("\n\n");
		GPIODBG("dump current state\n");
		//mt_gpio_dump(&latest);
		GPIODBG("\n\n");
		mt_gpio_dump_diff(&saved, &latest);
		//WARN_ON(1);
	} else {
		GPIODBG("checkpoint compare success!!\n");
	}
#endif
}
/*----------------------------------------------------------------------------*/
EXPORT_SYMBOL(mt_gpio_checkpoint_compare);
/*----------------------------------------------------------------------------*/
#endif
#endif
