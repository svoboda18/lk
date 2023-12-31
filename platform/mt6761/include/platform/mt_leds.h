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

#ifndef _MT65XX_LEDS_H
#define _MT65XX_LEDS_H

#define ISINK_CHOP_CLK
#include <cust_leds.h>
#include <platform/mt_typedefs.h>

#define ERROR_BL_LEVEL 0xFFFFFFFF

enum led_color {
	LED_RED,
	LED_GREEN,
	LED_BLUE,
};

enum led_brightness {
	LED_OFF     = 0,
	LED_HALF    = 127,
	LED_FULL    = 255,
};

typedef enum {
	ISINK_PWM_MODE = 0,
	ISINK_BREATH_MODE = 1,
	ISINK_REGISTER_MODE = 2
} MT65XX_PMIC_ISINK_MODE;

typedef enum {
	ISINK_0 = 0,  //4mA
	ISINK_1 = 1,  //8mA
	ISINK_2 = 2,  //12mA
	ISINK_3 = 3,  //16mA
	ISINK_4 = 4,  //20mA
	ISINK_5 = 5   //24mA
} MT65XX_PMIC_ISINK_STEP;

typedef enum {
	//32K clock
	ISINK_1KHZ = 0,
	ISINK_200HZ = 4,
	ISINK_5HZ = 199,
	ISINK_2HZ = 499,
	ISINK_1HZ = 999,
	ISINK_05HZ = 1999,
	ISINK_02HZ = 4999,
	ISINK_01HZ = 9999,
	//2M clock
	ISINK_2M_20KHZ = 2,
	ISINK_2M_1KHZ = 61,
	ISINK_2M_200HZ = 311,
	ISINK_2M_5HZ = 12499,
	ISINK_2M_2HZ = 31249,
	ISINK_2M_1HZ = 62499,
	/* 128K clock */
	ISINK_128K_500HZ = 0,
	ISINK_128K_256HZ = 1,
	ISINK_128K_167HZ = 2,
	ISINK_128K_128HZ = 3,
	ISINK_128K_100HZ = 4,
	ISINK_128K_83HZ = 5,
	ISINK_128K_50HZ = 9,
	ISINK_128K_17HZ = 28,
} MT65XX_PMIC_ISINK_FSEL;


#ifndef MACH_FPGA_LED_SUPPORT
int mt65xx_leds_brightness_set(enum mt65xx_led_type type, enum led_brightness level);
void leds_battery_full_charging(void);
void leds_battery_low_charging(void);
void leds_battery_medium_charging(void);
void mt65xx_backlight_on(void);
void mt65xx_backlight_off(void);
void leds_init(void);
void leds_deinit(void);
#else
static int mt65xx_leds_brightness_set(enum mt65xx_led_type type, enum led_brightness level) {return 0;}
static void leds_battery_full_charging(void) {}
static void leds_battery_low_charging(void) {}
static void leds_battery_medium_charging(void) {}
static inline void mt65xx_backlight_on(void) {}
static void mt65xx_backlight_off(void) {}
static void leds_init(void) {}
static void leds_deinit(void) {}
#endif

#endif // !_MT65XX_LEDS_H
