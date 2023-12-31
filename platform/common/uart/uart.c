/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2017. All rights reserved.
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
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#include <debug.h>
#include <reg.h>
#include <dev/uart.h>

#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/boot_mode.h>
#include <platform/mt_gpio.h>
#include <platform/sync_write.h>
#include <string.h>
#include "mt_uart.h"
#include <mt_boot.h>
#ifndef USER_BUILD
#define UART_EARLY_CONSOLE_LEN 128
#endif

#define BOTH_EMPTY (UART_LSR_TEMT | UART_LSR_THRE)
#define UART_SET_BITS(BS,REG)       mt65xx_reg_sync_writel(DRV_Reg32(REG) | (u32)(BS), REG)
#define UART_CLR_BITS(BC,REG)       mt65xx_reg_sync_writel(DRV_Reg32(REG) & ~((u32)(BC)), REG)

#define UART_BASE(uart)                   (uart)

#define UART_RBR(uart)                    (UART_BASE(uart)+0x0)  /* Read only */
#define UART_THR(uart)                    (UART_BASE(uart)+0x0)  /* Write only */
#define UART_IER(uart)                    (UART_BASE(uart)+0x4)
#define UART_IIR(uart)                    (UART_BASE(uart)+0x8)  /* Read only */
#define UART_FCR(uart)                    (UART_BASE(uart)+0x8)  /* Write only */
#define UART_LCR(uart)                    (UART_BASE(uart)+0xc)
#define UART_MCR(uart)                    (UART_BASE(uart)+0x10)
#define UART_LSR(uart)                    (UART_BASE(uart)+0x14)
#define UART_MSR(uart)                    (UART_BASE(uart)+0x18)
#define UART_SCR(uart)                    (UART_BASE(uart)+0x1c)
#define UART_DLL(uart)                    (UART_BASE(uart)+0x0)  /* Only when LCR.DLAB = 1 */
#define UART_DLH(uart)                    (UART_BASE(uart)+0x4)  /* Only when LCR.DLAB = 1 */
#define UART_EFR(uart)                    (UART_BASE(uart)+0x8)  /* Only when LCR = 0xbf */
#define UART_XON1(uart)                   (UART_BASE(uart)+0x10) /* Only when LCR = 0xbf */
#define UART_XON2(uart)                   (UART_BASE(uart)+0x14) /* Only when LCR = 0xbf */
#define UART_XOFF1(uart)                  (UART_BASE(uart)+0x18) /* Only when LCR = 0xbf */
#define UART_XOFF2(uart)                  (UART_BASE(uart)+0x1c) /* Only when LCR = 0xbf */
#define UART_AUTOBAUD_EN(uart)            (UART_BASE(uart)+0x20)
#define UART_HIGHSPEED(uart)              (UART_BASE(uart)+0x24)
#define UART_SAMPLE_COUNT(uart)           (UART_BASE(uart)+0x28)
#define UART_SAMPLE_POINT(uart)           (UART_BASE(uart)+0x2c)
#define UART_AUTOBAUD_REG(uart)           (UART_BASE(uart)+0x30)
#define UART_RATE_FIX_AD(uart)            (UART_BASE(uart)+0x34)
#define UART_AUTOBAUD_SAMPLE(uart)        (UART_BASE(uart)+0x38)
#define UART_GUARD(uart)                  (UART_BASE(uart)+0x3c)
#define UART_ESCAPE_DAT(uart)             (UART_BASE(uart)+0x40)
#define UART_ESCAPE_EN(uart)              (UART_BASE(uart)+0x44)
#define UART_SLEEP_EN(uart)               (UART_BASE(uart)+0x48)
#define UART_VFIFO_EN(uart)               (UART_BASE(uart)+0x4c)
#define UART_RXTRI_AD(uart)               (UART_BASE(uart)+0x50)

#ifndef MACH_FPGA
#define __ENABLE_UART_LOG_SWITCH_FEATURE__
#endif

volatile unsigned int g_uart;
unsigned int g_brg;
extern u8 g_lk_final_log;

#if defined(MACH_FPGA)
#define UART_SRC_CLK CONFIG_UART_FPGA_CLK
#else
#define UART_SRC_CLK CONFIG_UART_EVB_CLK
#endif
#define CONFIG_BAUDRATE CONFIG_UART_BAUDRATE

#ifdef __ENABLE_UART_LOG_SWITCH_FEATURE__

extern BOOT_ARGUMENT *g_boot_arg;
extern bool cmdline_append(const char *append_string);
int get_uart_port_id(void)
{
	unsigned int log_port;
	unsigned int log_enable;

	log_port = g_boot_arg->log_port;
	log_enable = g_boot_arg->log_enable;
	if (log_enable != 0) {
		switch (log_port) {
			case UART1:
				return 1;
			case UART2:
				return 2;
			case UART3:
				return 3;
#ifdef AP_UART3_BASE
			case UART4:
				return 4;
#endif
			default:
				return 2;
		}
	}
	return 2;
}

int get_meta_port_id(void)
{
	unsigned int meta_port;

	meta_port = g_boot_arg->meta_uart_port;

	switch (meta_port) {
		case UART1:
			return 1;
		case UART2:
			return 2;
		case UART3:
			return 3;
#ifdef AP_UART3_BASE
		case UART4:
			return 4;
#endif
		default:
			return 1;
	}

	return 1;
}

static void change_uart_port(char * cmd_line, char new_val)
{
	int i;
	int len;
	char *ptr;
	if (NULL == cmd_line)
		return;

	len = strlen(cmd_line);
	ptr = cmd_line;

	i = strlen("ttyS");
	if (len < i)
		return;
	len = len-i;

	for (i=0; i<=len; i++) {
		if (strncmp(ptr, "ttyS", 4)==0) {
			ptr[4] = new_val; // Find and modify
			break;
		}
		ptr++;
	}
}
void custom_port_in_kernel(BOOTMODE boot_mode, char *command)
{
	if (get_uart_port_id() == 1) {
		change_uart_port(command, '0');
	} else if (get_uart_port_id() == 2) {
		change_uart_port(command, '1');
	} else if (get_uart_port_id() == 3) {
		change_uart_port(command, '2');
	} else if (get_uart_port_id() == 4) {
		change_uart_port(command, '3');
	} else {
		change_uart_port(command, '0');
	}
}

#else
int get_uart_port_id(void)
{
	// Dummy function case
	return 1;
}

int get_meta_port_id(void)
{
	// Dummy function case
	return 1;
}

void custom_port_in_kernel(BOOTMODE boot_mode, char *command)
{
	// Dummy function case
}
#endif

void uart_setbrg()
{
	unsigned int byte,speed;
	unsigned int highspeed;
	unsigned int quot, divisor, remainder;
	unsigned int uartclk;
	unsigned short data, high_speed_div, sample_count, sample_point;
	unsigned int tmp_div;

	speed = g_brg;
	uartclk = UART_SRC_CLK;
	if (speed <= 115200 ) {
		highspeed = 0;
		quot = 16;
	} else {
		highspeed = 3;
		quot = 1;
	}

	if (highspeed < 3) { /*0~2*/
		/* Set divisor DLL and DLH  */
		divisor   =  uartclk / (quot * speed);
		remainder =  uartclk % (quot * speed);

		if (remainder >= (quot / 2) * speed)
			divisor += 1;

		mt65xx_reg_sync_writew(highspeed, UART_HIGHSPEED(g_uart));
		byte = DRV_Reg32(UART_LCR(g_uart));   /* DLAB start */
		mt65xx_reg_sync_writel((byte | UART_LCR_DLAB), UART_LCR(g_uart));
		mt65xx_reg_sync_writel((divisor & 0x00ff), UART_DLL(g_uart));
		mt65xx_reg_sync_writel(((divisor >> 8)&0x00ff), UART_DLH(g_uart));
		mt65xx_reg_sync_writel(byte, UART_LCR(g_uart));   /* DLAB end */
	} else {
		data=(unsigned short)(uartclk/speed);
		high_speed_div = (data>>8) + 1; // divided by 256

		tmp_div=uartclk/(speed*high_speed_div);
		divisor =  (unsigned short)tmp_div;

		remainder = (uartclk)%(high_speed_div*speed);
		/*get (sample_count+1)*/
		if (remainder >= ((speed)*(high_speed_div))>>1)
			divisor =  (unsigned short)(tmp_div+1);
		else
			divisor =  (unsigned short)tmp_div;

		sample_count=divisor-1;

		/*get the sample point*/
		sample_point=(sample_count-1)>>1;

		/*configure register*/
		mt65xx_reg_sync_writel(highspeed, UART_HIGHSPEED(g_uart));

		byte = DRV_Reg32(UART_LCR(g_uart));    /* DLAB start */
		mt65xx_reg_sync_writel((byte | UART_LCR_DLAB), UART_LCR(g_uart));
		mt65xx_reg_sync_writel((high_speed_div & 0x00ff), UART_DLL(g_uart));
		mt65xx_reg_sync_writel(((high_speed_div >> 8)&0x00ff), UART_DLH(g_uart));
		mt65xx_reg_sync_writel(sample_count, UART_SAMPLE_COUNT(g_uart));
		mt65xx_reg_sync_writel(sample_point, UART_SAMPLE_POINT(g_uart));
		mt65xx_reg_sync_writel(byte, UART_LCR(g_uart));   /* DLAB end */
	}
}

void mtk_set_current_uart(MTK_UART uart_base)
{
	g_uart = uart_base;
}

void uart_init_early(void)
{
#ifdef __ENABLE_UART_LOG_SWITCH_FEATURE__
	if (get_uart_port_id() == 1)
		mtk_set_current_uart(UART1);
	else if (get_uart_port_id() == 2)
		mtk_set_current_uart(UART2);
	else if (get_uart_port_id() == 3)
		mtk_set_current_uart(UART3);
#ifdef AP_UART3_BASE
	else if (get_uart_port_id() == 4)
		mtk_set_current_uart(UART4);
#endif
	else
		mtk_set_current_uart(UART1);
#else
	mtk_set_current_uart(UART1);
#endif

	DRV_SetReg32(UART_FCR(g_uart), UART_FCR_FIFO_INIT); /* clear fifo */
	mt65xx_reg_sync_writew(UART_NONE_PARITY | UART_WLS_8 | UART_1_STOP, UART_LCR(g_uart));
	g_brg = CONFIG_BAUDRATE;
	uart_setbrg();
#ifndef USER_BUILD
		char cmdline[UART_EARLY_CONSOLE_LEN];
		snprintf(cmdline, UART_EARLY_CONSOLE_LEN, " earlycon=uart8250,mmio32,0x%x,",
				 g_boot_arg->log_port);
		cmdline_append(cmdline);
#endif
}

void uart_init(void)
{
}

int uart_putc(const char c )
{
	unsigned int status;
	if (g_boot_arg->log_enable == 0)
		return 0;

#ifdef USER_LOAD
	if (g_boot_arg->log_dynamic_switch == 0)
		return 0;
	if (g_lk_final_log == 0)
		return 0;
#endif

	if (c == '\n')
		mt65xx_reg_sync_writel((unsigned int)'\r', UART_THR(g_uart));

	mt65xx_reg_sync_writel((unsigned int)c, UART_THR(g_uart));
	for (;;) {
		status = DRV_Reg32(UART_LSR(g_uart));
		if ((status & BOTH_EMPTY) == BOTH_EMPTY)
			break;
	}
	return 0;
}

int uart_getc(void)  /* returns -1 if no data available */
{
	if (g_boot_arg->log_enable == 0)
		return 0;

	if (g_boot_arg->meta_log_disable != 0)
		return 0;
#ifdef USER_LOAD
	if (g_boot_arg->log_dynamic_switch == 0)
		return 0;
	if (g_lk_final_log == 0)
		return 0;
#endif

	while (!(DRV_Reg32(UART_LSR(g_uart)) & UART_LSR_DR));
	return (int)DRV_Reg32(UART_RBR(g_uart));
}

void uart_puts(const char *s)
{
	while (*s)
		uart_putc(*s++);
}

