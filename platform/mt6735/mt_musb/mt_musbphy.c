/*
 * Copyright (c) 2012 MediaTek Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <debug.h>
#include <reg.h>
#include <platform/bitops.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <dev/udc.h>

/* common */
#include <mt_musb.h>

#if CFG_FPGA_PLATFORM
/* for usb phy */
#include <platform/mt_i2c.h>
#endif

#ifdef MACH_FPGA
#define CFG_FPGA_PLATFORM       (1)
#else
#define DBG_PHY_CALIBRATION 1
#endif

/* usb phy bring up */
#if CFG_FPGA_PLATFORM
#define USB_I2C_ID  I2C3    /* 0 - 6 */
#define PATH_NORMAL 0
#define PATH_PMIC   1

U32 usb_i2c_read8 (U8 addr, U8 *dataBuffer)
{
	U32 ret_code = I2C_OK;
//	U8 write_data = addr;
	U16 len;

	static struct mt_i2c_t i2c;

	i2c.id = USB_I2C_ID;
	i2c.addr = 0x60;    /* i2c API will shift-left this value to 0xc0 */
	i2c.mode = ST_MODE;
	i2c.speed = 100;
	i2c.dma_en = 0;
	len = 1;

	/* set register command */
#if 0
	ret_code = i2c_write(&i2c, &write_data, len);

	if (ret_code != len)
		return ret_code;

	ret_code = i2c_read(&i2c, dataBuffer, len);
#else
	ret_code = i2c_write_read(&i2c, dataBuffer, len, len);
#endif

	return ret_code;
}

U32 usb_i2c_write8(U8 addr, U8 value)
{
	U32 ret_code = I2C_OK;
	U8 write_data[2];
	U16 len;

	static struct mt_i2c_t i2c;

	write_data[0]= addr;
	write_data[1] = value;

	i2c.id = USB_I2C_ID;
	i2c.addr = 0x60;    /* i2c API will shift-left this value to 0xc0 */
	i2c.mode = ST_MODE;
	i2c.speed = 100;
	i2c.dma_en = 0;
	len = 2;

	ret_code = i2c_write(&i2c, write_data, len);

	return ret_code;
}

#define USBPHY_I2C_READ8(addr, buffer)  usb_i2c_read8(addr, buffer)
#define USBPHY_I2C_WRITE8(addr, value)  usb_i2c_write8(addr, value)
#endif

/* use mt_typedefs.h */
#define USBPHY_READ8(offset)        readb(USB20_PHY_BASE+offset)
#define USBPHY_WRITE8(offset, value)    writeb(value, USB20_PHY_BASE+offset)
#define USBPHY_SET8(offset, mask)   USBPHY_WRITE8(offset, (USBPHY_READ8(offset)) | (mask))
#define USBPHY_CLR8(offset, mask)   USBPHY_WRITE8(offset, (USBPHY_READ8(offset)) & (~mask))

#define USB11PHY_READ8(offset)      readb(USB11_PHY_BASE+offset)
#define USB11PHY_WRITE8(offset, value)  writeb(value, USB11_PHY_BASE+offset)
#define USB11PHY_SET8(offset, mask) USB11PHY_WRITE8(offset, (USB11PHY_READ8(offset)) | (mask))
#define USB11PHY_CLR8(offset, mask) USB11PHY_WRITE8(offset, (USB11PHY_READ8(offset)) & (~mask))

#if CFG_FPGA_PLATFORM
void mt_usb_phy_poweron(void)
{
#define PHY_DRIVING   0x3

#if defined(USB_PHY_DRIVING_TUNING)
	UINT8 usbreg8;
	unsigned int i;
#endif

	/* force_suspendm = 0 */
	USBPHY_CLR8(0x6a, 0x04);

	USBPHY_I2C_WRITE8(0xff, 0x00);
	USBPHY_I2C_WRITE8(0x61, 0x04);
	USBPHY_I2C_WRITE8(0x68, 0x00);
	USBPHY_I2C_WRITE8(0x6a, 0x00);
	USBPHY_I2C_WRITE8(0x00, 0x6e);
	USBPHY_I2C_WRITE8(0x1b, 0x0c);
	USBPHY_I2C_WRITE8(0x08, 0x44);
	USBPHY_I2C_WRITE8(0x11, 0x55);
	USBPHY_I2C_WRITE8(0x1a, 0x68);

#if defined(USB_PHY_DRIVING_TUNING)
	/* driving tuning */
	USBPHY_I2C_READ8(0xab, &usbreg8);
	usbreg8 &= ~0x3;
	usbreg8 |= PHY_DRIVING;
	USBPHY_I2C_WRITE8(0xab, usbreg8);

	for (i = 0; i < 16; i++) {
		USBPHY_I2C_READ8((0x92+i), &usbreg8);
		usbreg8 &= ~0x3;
		usbreg8 |= PHY_DRIVING;
		USBPHY_I2C_WRITE8((0x92+i), usbreg8);
	}

	USBPHY_I2C_READ8(0xbc, &usbreg8);
	usbreg8 &= ~0x3;
	usbreg8 |= PHY_DRIVING;
	USBPHY_I2C_WRITE8(0xbc, usbreg8);

	USBPHY_I2C_READ8(0xbe, &usbreg8);
	usbreg8 &= ~0x3;
	usbreg8 |= PHY_DRIVING;
	USBPHY_I2C_WRITE8(0xbe, usbreg8);

	USBPHY_I2C_READ8(0xbf, &usbreg8);
	usbreg8 &= ~0x3;
	usbreg8 |= PHY_DRIVING;
	USBPHY_I2C_WRITE8(0xbf, usbreg8);

	USBPHY_I2C_READ8(0xcd, &usbreg8);
	usbreg8 &= ~0x3;
	usbreg8 |= PHY_DRIVING;
	USBPHY_I2C_WRITE8(0xcd, usbreg8);

	USBPHY_I2C_READ8(0xf1, &usbreg8);
	usbreg8 &= ~0x3;
	usbreg8 |= PHY_DRIVING;
	USBPHY_I2C_WRITE8(0xf1, usbreg8);

	USBPHY_I2C_READ8(0xa7, &usbreg8);
	usbreg8 &= ~0x3;
	usbreg8 |= PHY_DRIVING;
	USBPHY_I2C_WRITE8(0xa7, usbreg8);

	USBPHY_I2C_READ8(0xa8, &usbreg8);
	usbreg8 &= ~0x3;
	usbreg8 |= PHY_DRIVING;
	USBPHY_I2C_WRITE8(0xa8, usbreg8);
#endif

	udelay(800);

}

void mt_usb_phy_savecurrent (void)
{
	/* no need */
}

void mt_usb_phy_recover (void)
{
	/* no need */
}

void mt_usb11_phy_savecurrent(void)
{
	/* no need */
}

void Charger_Detect_Init(void)
{
	/* no need */
}

void Charger_Detect_Release(void)
{
	/* no need */
}

#else

void mt_usb_phy_poweron(void)
{
	/*
	 * swtich to USB function.
	 * (system register, force ip into usb mode).
	 */
	USBPHY_CLR8(0x6b, 0x04);
	USBPHY_CLR8(0x6e, 0x01);
	USBPHY_CLR8(0x21, 0x03);

	/* RG_USB20_BC11_SW_EN = 1'b0 */
	USBPHY_SET8(0x22, 0x04);
	USBPHY_CLR8(0x1a, 0x80);

	/* RG_USB20_DP_100K_EN = 1'b0 */
	/* RG_USB20_DP_100K_EN = 1'b0 */
	USBPHY_CLR8(0x22, 0x03);

	/*OTG enable*/
	USBPHY_SET8(0x20, 0x10);
	/* release force suspendm */
	USBPHY_CLR8(0x6a, 0x04);

	udelay(800);

	/* force enter device mode */
	USBPHY_CLR8(0x6c, 0x10);
	USBPHY_SET8(0x6c, 0x2E);
	USBPHY_SET8(0x6d, 0x3E);

	return;
}

void mt_usb_phy_savecurrent(void)
{
	/*
	 * swtich to USB function.
	 * (system register, force ip into usb mode).
	 */
	USBPHY_CLR8(0x6b, 0x04);
	USBPHY_CLR8(0x6e, 0x01);
	USBPHY_CLR8(0x21, 0x03);

	/* release force suspendm */
	USBPHY_CLR8(0x6a, 0x04);
	USBPHY_SET8(0x68, 0x04);
	/* RG_DPPULLDOWN./RG_DMPULLDOWN. */
	USBPHY_SET8(0x68, 0xc0);
	/* RG_XCVRSEL[1:0] = 2'b01 */
	USBPHY_CLR8(0x68, 0x30);
	USBPHY_SET8(0x68, 0x10);
	/* RG_TERMSEL = 1'b1 */
	USBPHY_SET8(0x68, 0x04);
	/* RG_DATAIN[3:0] = 4'b0000 */
	USBPHY_CLR8(0x69, 0x3c);

	/*
	 * force_dp_pulldown, force_dm_pulldown,
	 * force_xcversel, force_termsel.
	 */
	USBPHY_SET8(0x6a, 0xba);

	/* RG_USB20_BC11_SW_EN = 1'b0 */
	USBPHY_CLR8(0x1a, 0x80);
	/* RG_USB20_OTG_VBUSSCMP_EN = 1'b0 */
	USBPHY_CLR8(0x1a, 0x10);

	udelay(800);

	USBPHY_CLR8(0x6a, 0x04);
	/* rg_usb20_pll_stable = 1 */
	//USBPHY_SET8(0x63, 0x02);

	udelay(1);

	/* force suspendm = 1 */
	//USBPHY_SET8(0x6a, 0x04);

	//udelay(1);

	return;
}

void mt_usb_phy_recover(void)
{

	/* clean PUPD_BIST_EN */
	/* PUPD_BIST_EN = 1'b0 */
	/* PMIC will use it to detect charger type */
	USBPHY_CLR8(0x1d, 0x10);

	/* force_uart_en = 1'b0 */
	USBPHY_CLR8(0x6b, 0x04);
	/* RG_UART_EN = 1'b0 */
	USBPHY_CLR8(0x6e, 0x01);
	/* force_uart_en = 1'b0 */
	USBPHY_CLR8(0x6a, 0x04);

	USBPHY_CLR8(0x21, 0x03);

	USBPHY_CLR8(0x68, 0xf4);

	/* RG_DATAIN[3:0] = 4'b0000 */
	USBPHY_CLR8(0x69, 0x3c);

	USBPHY_CLR8(0x6a, 0xba);

	/* RG_USB20_BC11_SW_EN = 1'b0 */
	USBPHY_CLR8(0x1a, 0x80);
	/* RG_USB20_OTG_VBUSSCMP_EN = 1'b1 */
	USBPHY_SET8(0x1a, 0x10);

	//HQA adjustment
	USBPHY_CLR8(0x18, 0x08);
	USBPHY_SET8(0x18, 0x06);

	udelay(800);

	/* force enter device mode */
	//USBPHY_CLR8(0x6c, 0x10);
	//USBPHY_SET8(0x6c, 0x2E);
	//USBPHY_SET8(0x6d, 0x3E);
}

void mt_usb11_phy_savecurrent(void)
{
#if 0
	USB11PHY_SET8(0xca, 0x10);
	USB11PHY_SET8(0xcb, 0x3c);
	USB11PHY_CLR8(0xc1, 0x08);
	USB11PHY_CLR8(0xc7, 0x06);
	USB11PHY_SET8(0xc6, 0x06);

#endif
}

void Charger_Detect_Init(void)
{
	/* RG_USB20_BC11_SW_EN = 1'b1 */
	USBPHY_SET8(0x1a, 0x80);
}

void Charger_Detect_Release(void)
{
	/* RG_USB20_BC11_SW_EN = 1'b0 */
	USBPHY_CLR8(0x1a, 0x80);
}
#endif
/* usb phy bring up end */

#if !CFG_FPGA_PLATFORM
//ALPS00427972, implement the analog register formula
void mt_usb_phy_calibraion (int case_set, int input_reg)
{
#if 0
	int temp_added=0;
	int temp_test=0;
	int temp_mask;

#if DBG_PHY_CALIBRATION
	DBG_I("%s: case_set %d, input_reg = 0x%x \n", __func__, case_set, input_reg);
#endif

	switch (case_set) {
		case 1:
			//case  1
			//If M_HW_RES3[15:13] !=0
			//RG_USB20_TERM_VREF_SEL[2:0] <= RG_USB20_TERM_VREF_SEL[2:0] + M_HW_RES3[15:13]
			temp_mask = 0x07;
			temp_test = USBPHY_READ8(0x05);
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_test = 0x%x \n", __func__, temp_test);
#endif
			temp_added = (USBPHY_READ8(0x05)& temp_mask) + input_reg;
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_added = 0x%x \n", __func__, temp_added);
#endif
			temp_added &= 0x07;
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_added = 0x%x \n", __func__, temp_added);
#endif

			USBPHY_CLR8(0x05, temp_mask);
			USBPHY_SET8(0x05, temp_added);

			temp_test = USBPHY_READ8(0x05);
#if DBG_PHY_CALIBRATION
			DBG_I("%s: final temp_test = 0x%x \n", __func__, temp_test);
#endif
			break;
		case 2:
			//case 2
			//If M_HW_RES3[12:10] !=0
			//RG_USB20_CLKREF_REF[2:0]<= RG_USB20_CLKREF_REF[2:0]+ M_HW_RES3[12:10]
			temp_mask = 0x07;

			temp_test = USBPHY_READ8(0x07);
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_test = 0x%x \n", __func__, temp_test);
#endif
			temp_added = (USBPHY_READ8(0x07)& temp_mask) + input_reg;
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_added = 0x%x \n", __func__, temp_added);
#endif
			temp_added &= 0x07;
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_added = 0x%x \n", __func__, temp_added);
#endif

			USBPHY_CLR8(0x07, temp_mask);
			USBPHY_SET8(0x07, temp_added);

			temp_test = USBPHY_READ8(0x07);
#if DBG_PHY_CALIBRATION
			DBG_I("%s: final temp_test = 0x%x \n", __func__, temp_test);
#endif
			break;
		case 3:
			//case 3
			//If M_HW_RES3[9:7] !=0
			//RG_USB20_VRT_VREF_SEL[2:0]<=RG_USB20_VRT_VREF_SEL[2:0]+ M_HW_RES3[9:7]
			temp_mask = 0x70;

			temp_test = USBPHY_READ8(0x05);
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_test = 0x%x \n", __func__, temp_test);
#endif
			temp_added = (USBPHY_READ8(0x05)& temp_mask) >> 4;
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_added = 0x%x \n", __func__, temp_added);
#endif
			temp_added += input_reg;
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_added = 0x%x \n", __func__, temp_added);
#endif
			temp_added &= 0x07;
#if DBG_PHY_CALIBRATION
			DBG_I("%s: temp_added = 0x%x \n", __func__, temp_added);
#endif

			USBPHY_CLR8(0x05, temp_mask);
			USBPHY_SET8(0x05, temp_added<<4);

			temp_test = USBPHY_READ8(0x05);
#if DBG_PHY_CALIBRATION
			DBG_I("%s: final temp_test = 0x%x \n", __func__, temp_test);
#endif
			break;
	}
#endif
}

//ALPS00427972, implement the analog register formula
#endif
