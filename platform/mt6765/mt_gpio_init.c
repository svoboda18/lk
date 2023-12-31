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


#include <platform/mt_gpio.h>

#ifndef USE_DTB_NO_DWS
#if (!defined(MACH_FPGA) || defined (FPGA_SIMULATION))
#include <cust_power.h>
#include <cust_gpio_boot.h>
#endif
#endif/* end of USE_DTB_NO_DWS */

#include <platform/mt_reg_base.h>
#include <platform/gpio_init.h>

#include <debug.h>
#define GPIO_INIT_DEBUG 1
/*----------------------------------------------------------------------------*/

#define GPIOTAG "[GPIO] "
#define GPIODBG(fmt, arg...)    dprintf(INFO, GPIOTAG "%s: " fmt, __FUNCTION__ ,##arg)
#define GPIOERR(fmt, arg...)    dprintf(CRITICAL, GPIOTAG "%s: " fmt, __FUNCTION__ ,##arg)
#define GPIOVER(fmt, arg...)    dprintf(INFO, GPIOTAG "%s: " fmt, __FUNCTION__ ,##arg)

#define GPIO_WR32(addr, data)   DRV_WriteReg32(addr,data)
#define GPIO_RD32(addr)         DRV_Reg32(addr)

#define ADDR_BIT 0
#define VAL_BIT  1
#define MASK_BIT 2
/*----------------------------------------------------------------------------*/
#if (defined(MACH_FPGA) && !defined (FPGA_SIMULATION))

void mt_gpio_set_default(void)
{
	return;
}

void mt_gpio_set_default_dump(void)
{
	return;
}

#else

void gpio_dump(void)
{
	int i = 0;

	GPIOVER("[gpio dct config] ++++++++++++++++++++++++++++\n");
	for (i = 0; i < MAX_GPIO_PIN; i++) {
		GPIOVER("gpio[%d]\n", i);
		GPIOVER("gpio[%d], mode(%x)\n", i, mt_get_gpio_mode(0x80000000 + i));
		GPIOVER("gpio[%d], dir(%x)\n", i, mt_get_gpio_dir(0x80000000 + i));
		GPIOVER("gpio[%d], pull_en(%x)\n", i, mt_get_gpio_pull_enable(0x80000000 + i));
		GPIOVER("gpio[%d], pull_sel(%x)\n", i, mt_get_gpio_pull_select(0x80000000 + i));
		GPIOVER("gpio[%d], out(%x)\n", i, mt_get_gpio_out(0x80000000 + i));
		GPIOVER("gpio[%d], smt(%x)\n", i, mt_get_gpio_smt(0x80000000 + i));
		GPIOVER("gpio[%d], ies(%x)\n", i, mt_get_gpio_ies(0x80000000 + i));
		GPIOVER("gpio[%d], in(%x)\n", i, mt_get_gpio_in(0x80000000 + i));
	}

	GPIOVER("[gpio dct config] ----------------------------\n");
}

void mt_gpio_set_default_dump(void)
{
	gpio_dump();
}

#include <platform/boot_mode.h>
#include <debug.h>
#include <stdlib.h>
#include <string.h>
#include <video.h>
#include <dev/uart.h>
#include <arch/arm.h>
#include <arch/arm/mmu.h>
#include <arch/ops.h>
#include <target/board.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_disp_drv.h>
#include <platform/disp_drv.h>
#include <platform/boot_mode.h>
#include <platform/mt_logo.h>
#include <platform/partition.h>
#include <env.h>
#include <platform/mt_gpio.h>
#include <platform/mt_pmic.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/mt_i2c.h>
#include <platform/mtk_key.h>
#include <platform/mt_rtc.h>
#include <platform/mt_leds.h>
#include <platform/upmu_common.h>
#include <platform/mtk_wdt.h>
#include <platform/disp_drv_platform.h>

#ifdef USE_DTB_NO_DWS/* for use DTB No DWS */
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
			return -2;
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

			data++;/* maybe mode=-1 */
			gpio_array[pin].mode = (char) fdt32_to_cpu(*data);

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
			dprintf(INFO, "[bxx]no dws GPIO: %d %d %d %d %d %d %d\n",
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

#ifdef FPGA_SIMULATION
	GPIOVER("gpio debug base =%x\n", GPIO_RD32(GPIO_BASE));
	memset(GPIO_BASE, 0, 4096);
#endif

#ifdef USE_DTB_NO_DWS
	if (mt_gpio_get_default_chip_from_dtb() < 0) {
		dprintf(CRITICAL, "[GPIO] gpio_get_default_chip_from_dtb Failed!\n");
		return;
	}
#endif

	for (pin = 0; pin < MT_GPIO_BASE_MAX; pin++) {
#ifdef FPGA_SIMULATION
		GPIOVER("GPIO %d dump\n", pin);
#endif

#ifdef USE_DTB_NO_DWS
#if 0
		if (gpio_array[pin].mode < 0)
			continue;/* init no cover gpios */
		else
#endif
		if (pin > 121 && pin <134)
			continue;/* skip msdc pins init GPIO122~133 */
#endif

		/* set GPIOx_MODE */
		mt_set_gpio_mode(0x80000000 + pin, gpio_array[pin].mode);

		/* set GPIOx_DIR */
		mt_set_gpio_dir(0x80000000 + pin, gpio_array[pin].dir);

		/* set GPIOx_PULLEN */
		mt_set_gpio_pull_enable(0x80000000 + pin, gpio_array[pin].pullen);

		/* set GPIOx_PULL */
		if (mt_get_gpio_pull_enable(0x80000000 + pin) == GPIO_PULL_ENABLE) {
			mt_set_gpio_pull_select(0x80000000 + pin, gpio_array[pin].pull);
		}

		/* set GPIOx_DATAOUT */
		mt_set_gpio_out(0x80000000 + pin, gpio_array[pin].dataout);

		/* set GPIOx_SMT */
		mt_set_gpio_smt(0x80000000 + pin, gpio_array[pin].smt);

#ifndef USE_DTB_NO_DWS
		/* set GPIOx_IES */
		mt_set_gpio_ies(0x80000000 + pin, gpio_array[pin].ies);
#if 0
		dprintf(INFO, "[bxx]dws-GPIO: %d %d %d %d %d %d %d\n",
				pin,
				gpio_array[pin].mode,
				gpio_array[pin].dir,
				gpio_array[pin].dataout,
				gpio_array[pin].pullen,
				gpio_array[pin].pull,
				gpio_array[pin].smt
		);
#endif
#endif

	}

/* workaround for ap spi1's gpio mode */
/*	mt_set_gpio_mode(0x80000000 + 84, GPIO_MODE_01);
	mt_set_gpio_mode(0x80000000 + 85, GPIO_MODE_01);
	mt_set_gpio_mode(0x80000000 + 86, GPIO_MODE_01);
	mt_set_gpio_mode(0x80000000 + 87, GPIO_MODE_01);
*/
#ifdef SELF_TEST
	mt_gpio_self_test();
#endif
}

void mt_gpio_set_default(void)
{

	mt_gpio_set_default_chip();
	return;
}

#ifdef SELF_TEST
int smt_test(void)
{

	int i, val;
	s32 out;
	int res;
	GPIOVER("smt_test test+++++\n");

	for (i = 0; i < MT_GPIO_EXT_MAX; i++) {
		/*prepare test */
		res = mt_set_gpio_mode(i | 0x80000000, 0);
		if (res)
			return -1;
		/*test */
		for (val = 0; val < GPIO_SMT_MAX; val++) {
			GPIOVER("test gpio[%d],smt[%d]\n", i, val);
			if (-1 == mt_set_gpio_smt(i | 0x80000000, val)) {
				GPIOERR(" set smt unsupport\n");
				continue;
			}
			if ((res = mt_set_gpio_smt(i | 0x80000000, val)) != RSUCCESS) {
				GPIOERR(" set smt[%d] fail: %d\n", val, res);
				return -1;
			}
			if (val != mt_get_gpio_smt(i | 0x80000000)) {
				GPIOERR(" get smt[%d] fail: real get %d\n", val, mt_get_gpio_smt(i | 0x80000000));
				return -1;
			}
			if (mt_get_gpio_smt(i | 0x80000000) > 1) {
				GPIOERR(" get smt[%d] value fail: real get %d\n", val, mt_get_gpio_smt(i | 0x80000000));
				return -1;
			}
		}

	}
	GPIOVER("smt_test test----- PASS!\n");
	return 0;

}

int output_test(void)
{

	int i, val;
	s32 out;
	int res;
	GPIOVER("output test+++++\n");

	for (i = 0; i < MT_GPIO_EXT_MAX; i++) {
		/*prepare test */
		res = mt_set_gpio_mode(i | 0x80000000, 0);
		if (res)
			return -1;
		res = mt_set_gpio_dir(i | 0x80000000, GPIO_DIR_OUT);
		if (res)
			return -1;
		/*test */
		for (val = 0; val < GPIO_OUT_MAX; val++) {
			GPIOVER("test gpio[%d],output[%d]\n", i, val);
			if ((res = mt_set_gpio_out(i | 0x80000000, val)) != RSUCCESS) {
				GPIOERR(" set out[%d] fail: %d\n", val, res);
				return -1;
			}
			if (val != mt_get_gpio_out(i | 0x80000000)) {
				GPIOERR(" get out[%d] fail: real get %d\n", val, mt_get_gpio_out(i | 0x80000000));
				return -1;
			}
			if (mt_get_gpio_out(i | 0x80000000) > 1) {
				GPIOERR(" get out[%d] value fail: real get %d\n", val, mt_get_gpio_out(i | 0x80000000));
				return -1;
			}
		}

	}
	GPIOVER("output test----- PASS!\n");
	return 0;

}

int direction_test(void)
{
	int i, val;
	s32 out;
	int res;
	GPIOVER("direction_test test+++++\n");
	for (i = 0; i < MT_GPIO_EXT_MAX; i++) {
		/*prepare test */
		res = mt_set_gpio_mode(i | 0x80000000, 0);
		if (res)
			return -1;

		/*test */
		for (val = 0; val < GPIO_DIR_MAX; val++) {
			GPIOVER("test gpio[%d],direction[%d]\n", i, val);
			if ((res = mt_set_gpio_dir(i | 0x80000000, val)) != RSUCCESS) {
				GPIOERR(" set direction[%d] fail: %d\n", val, res);
				return -1;
			}
			if (val != mt_get_gpio_dir(i | 0x80000000)) {
				GPIOERR(" get direction[%d] fail1 real get %d\n", val, mt_get_gpio_dir(i | 0x80000000));
				return -1;
			}
			if (mt_get_gpio_dir(i | 0x80000000) > 1) {
				GPIOERR(" get direction[%d] value fail2 real get %d\n", val,
					mt_get_gpio_dir(i | 0x80000000));
				return -1;
			}
		}

	}
	GPIOVER("direction_test----- PASS!\n");

	return 0;
}

int mode_test(void)
{
	int i, val;
	s32 out;
	int res;
	GPIOVER("mode_test test+++++\n");
	for (i = 0; i < MT_GPIO_EXT_MAX; i++) {

		/*test */
		for (val = 0; val < GPIO_MODE_MAX; val++) {
			GPIOVER("test gpio[%d],dir[%d]\n", i, val);
			if ((res = mt_set_gpio_mode(i | 0x80000000, val)) != RSUCCESS) {
				GPIOERR(" set mode[%d] fail: %d\n", val, res);
				return -1;
			}
			if (val != mt_get_gpio_mode(i | 0x80000000)) {
				GPIOERR(" get mode[%d] fail: real get %d\n", val, mt_get_gpio_mode(i | 0x80000000));
				return -1;
			}
			if (mt_get_gpio_mode(i | 0x80000000) > 7) {
				GPIOERR(" get mode[%d] value fail: real get %d\n", val,
					mt_get_gpio_mode(i | 0x80000000));
				return -1;
			}
		}

	}
	GPIOVER("mode_test----- PASS!\n");

	return 0;
}

int pullen_test(void)
{
	int i, val;
	s32 out;
	int res;
	GPIOVER("pullen_test  +++++\n");
	for (i = 0; i < MT_GPIO_EXT_MAX; i++) {
		/*prepare test */
		res = mt_set_gpio_mode(i | 0x80000000, 0);
		if (res)
			return -1;

		/*test */
		for (val = 0; val < GPIO_PULL_EN_MAX; val++) {
			GPIOVER("test gpio[%d],pullen[%d]\n", i, val);
			if (-1 == mt_set_gpio_pull_enable(i | 0x80000000, val)) {
				GPIOERR(" set pull_enable unsupport\n");
				continue;
			}
			if (GPIO_NOPULLDOWN == mt_set_gpio_pull_enable(i | 0x80000000, val)) {
				GPIOERR(" set pull_down unsupport\n");
				continue;
			}
			if (GPIO_NOPULLUP == mt_set_gpio_pull_enable(i | 0x80000000, val)) {
				GPIOERR(" set pull_up unsupport\n");
				continue;
			}
			if ((res = mt_set_gpio_pull_enable(i | 0x80000000, val)) != RSUCCESS) {
				GPIOERR(" set pull_enable[%d] fail1 %d\n", val, res);
				return -1;
			}
			if (val != mt_get_gpio_pull_enable(i | 0x80000000)) {
				GPIOERR(" get pull_enable[%d] fail2 real get %d\n", val,
					mt_get_gpio_pull_enable(i | 0x80000000));
				return -1;
			}

			if (mt_get_gpio_pull_enable(i | 0x80000000) > 1) {
				GPIOERR(" get pull_enable[%d] value fail3: real get %d\n", val,
					mt_get_gpio_pull_enable(i | 0x80000000));
				return -1;
			}
		}

	}
	GPIOVER("pullen_test----- PASS!\n");

	return 0;
}

int pullselect_test(void)
{
	int i, val;
	s32 out;
	int res;
	GPIOVER("pullselect_test  +++++\n");
	for (i = 0; i < MT_GPIO_EXT_MAX; i++) {
		/*prepare test */
		res = mt_set_gpio_mode(i | 0x80000000, 0);
		if (res)
			return -1;

		/*test */
		for (val = 0; val < GPIO_PULL_MAX; val++) {
			GPIOVER("test gpio[%d],pull_select[%d]\n", i, val);
			res = mt_set_gpio_pull_select(i | 0x80000000, val);
			if (GPIO_PULL_UNSUPPORTED == res || GPIO_NOPULLUP == res || GPIO_NOPULLDOWN == res) {
				GPIOERR(" set gpio[%d] pull_select[%d] unsupport\n", i, val);
				continue;
			}

			if ((res = mt_set_gpio_pull_select(i | 0x80000000, val)) != RSUCCESS) {
				GPIOERR(" set pull_select[%d] fail1: %d\n", val, res);
				return -1;
			}
			if (val != mt_get_gpio_pull_select(i | 0x80000000)) {
				GPIOERR(" get pull_select[%d] fail2: real get %d\n", val,
					mt_get_gpio_pull_select(i | 0x80000000));
				return -1;
			}
			if (-1 == mt_get_gpio_pull_select(i | 0x80000000)) {
				GPIOERR(" set gpio[%d] pull_select not support\n", i);
			} else if (mt_get_gpio_pull_select(i | 0x80000000) > 2) {
				GPIOERR(" get pull_select[%d] value fail: real get %d\n", val,
					mt_get_gpio_pull_select(i | 0x80000000));
				return -1;
			}
		}

	}
	GPIOVER("pullselect_test----- PASS!\n");

	return 0;
}

void mt_gpio_self_test(void)
{
	int err = 0;
	GPIOVER("GPIO self_test start\n");
	err = mode_test();
	if (err) {
		GPIOVER("GPIO self_test FAIL\n");
		return;
	}

	err = direction_test();
	if (err) {
		GPIOVER("GPIO self_test FAIL\n");
		return;
	}

	err = output_test();
	if (err) {
		GPIOVER("GPIO self_test FAIL\n");
		return;
	}

	err = smt_test();
	if (err) {
		GPIOVER("GPIO self_test FAIL\n");
		return;
	}

	err = pullen_test();
	if (err) {
		GPIOVER("GPIO self_test FAIL\n");
		return;
	}

	err = pullselect_test();
	if (err) {
		GPIOVER("GPIO self_test FAIL\n");
		return;
	}

	GPIOVER("GPIO self_test PASS\n");
}

#endif

#endif
