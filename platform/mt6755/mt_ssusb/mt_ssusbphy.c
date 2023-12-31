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

#include <reg.h>
#include <platform/bitops.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <platform/timer.h>

#include <mt_ssusb.h>
#include <mt_ssusbphy.h>
#include <mt_ssusb_sifslv_ippc.h>

#if defined(CONFIG_D60802_SUPPORT)
#include <mt_usbphy_d60802.h>
#elif defined(CONFIG_E60802_SUPPORT)
#include <mt_usbphy_e60802.h>
#elif defined(CONFIG_A60810_SUPPORT)
#include <mt_usbphy_a60810.h>
#endif

/* for usb phy */
#include <mt_i2c.h>
#include <mt_ssusb_usb3_mac_csr.h>

#ifdef MACH_FPGA
#define CFG_FPGA_PLATFORM       (1)
#else
#define DBG_PHY_CALIBRATION 1
#endif

/* used by phy scan */
#define CONFIG_U3_PHY_GPIO_SUPPORT

#define USB11PHY_READ8(offset)      readb(USB11_PHY_BASE + offset)
#define USB11PHY_WRITE8(offset, value)  writeb(value, USB11_PHY_BASE+offset)
#define USB11PHY_SET8(offset, mask) USB11PHY_WRITE8(offset, USB11PHY_READ8(offset) | mask)
#define USB11PHY_CLR8(offset, mask) USB11PHY_WRITE8(offset, USB11PHY_READ8(offset) & ~mask)

#define SSUSB_PHY_BASE          (SSUSB_SIFSLV_IPPC_BASE)
//#define USB20_PHY_BASE        (USBSIF_BASE + 0x0800)
#define USB11_PHY_BASE          (USBSIF_BASE + 0x0900)
#define PERI_GLOBALCON_PDN0_SET     (PERICFG_BASE+0x008)
#define USB0_PDN            1 << 10

extern void mu3d_hal_ssusb_en(void);
extern void mu3d_hal_rst_dev(void);

#define USB_I2C_ID  I2C1    /* 0 - 6 */
#define PATH_NORMAL 0
#define PATH_PMIC   1

#define U3_PHY_PAGE     0xff
#define I2C_CHIP        0xc0

#ifdef DBG_USB_PHY
#define PHY_LOG(x...) dprintf(INFO, "[USB][PHY] " x)
#else
#define PHY_LOG(x...) do{} while(0)
#endif

#define ENTER_U0_TH         5
#define MAX_PHASE_RANGE         31
#define MAX_TIMEOUT_COUNT       100
#define DATA_DRIVING_MASK       0x06
#define MAX_DRIVING_RANGE       0x04
#define MAX_LATCH_SELECT        0x02

#define U3_PHY_I2C_PCLK_DRV_REG     0x0A
#define U3_PHY_I2C_PCLK_PHASE_REG   0x0B
#define STATE_U0_STATE          (13)
#define CLR_RECOV_CNT           (0x1 << 16) /* 16:16 */
#define CLR_LINK_ERR_CNT        (0x1 << 16) /* 16:16 */
#define STATE_DISABLE           (1)

#if CFG_FPGA_PLATFORM

static struct mt_i2c_t usb_i2c;

#define U3_PHY_I2C_DEV      0x60
static u32 usb_i2c_read8(u8 addr, u8 *databuffer)
{
	u32 ret_code = I2C_OK;
	u16 len;
	*databuffer = addr;

	usb_i2c.id = USB_I2C_ID;
	/* Since i2c will left shift 1 bit, we need to set USB I2C address to 0x60 (0xC0>>1) */
	usb_i2c.addr = 0x60;
	usb_i2c.mode = ST_MODE;
	usb_i2c.speed = 100;
	len = 1;

	ret_code = i2c_write_read(&usb_i2c, databuffer, len, len);

	return ret_code;
}

static u32 usb_i2c_write8(u8 addr, u8 value)
{
	u32 ret_code = I2C_OK;
	u8 write_data[2];
	u16 len;

	write_data[0]= addr;
	write_data[1] = value;

	usb_i2c.id = USB_I2C_ID;
	/* Since i2c will left shift 1 bit, we need to set USB I2C address to 0x60 (0xC0>>1) */
	usb_i2c.addr = 0x60;
	usb_i2c.mode = ST_MODE;
	usb_i2c.speed = 100;
	len = 2;

	ret_code = i2c_write(&usb_i2c, write_data, len);

	return ret_code;
}

static void _u3_write_bank(u32 value)
{
	usb_i2c_write8((u8)U3_PHY_PAGE, (u8)value);
}

static u32 _u3_read_reg(u32 address)
{
	u8 databuffer = 0;
	usb_i2c_read8((u8)address, &databuffer);
	return databuffer;
}

static void _u3_write_reg(u32 address, u32 value)
{
	usb_i2c_write8((u8 )address, (u8 )value);
}

u32 u3_phy_read_reg32(u32 addr)
{
	u32 bank;
	u32 addr8;
	u32 data;

	bank = (addr >> 16) & 0xff;
	addr8 = addr & 0xff;

	_u3_write_bank(bank);
	data = _u3_read_reg(addr8);
	data |= (_u3_read_reg(addr8 + 1) << 8);
	data |= (_u3_read_reg(addr8 + 2) << 16);
	data |= (_u3_read_reg(addr8 + 3) << 24);
	return data;
}

u32 u3_phy_write_reg32(u32 addr, u32 data)
{
	u32 bank;
	u32 addr8;
	u32 data_0, data_1, data_2, data_3;

	bank = (addr >> 16) & 0xff;
	addr8 = addr & 0xff;
	data_0 = data & 0xff;
	data_1 = (data >> 8) & 0xff;
	data_2 = (data >> 16) & 0xff;
	data_3 = (data >> 24) & 0xff;

	_u3_write_bank(bank);
	_u3_write_reg(addr8, data_0);
	_u3_write_reg(addr8 + 1, data_1);
	_u3_write_reg(addr8 + 2, data_2);
	_u3_write_reg(addr8 + 3, data_3);

	return 0;
}

void u3_phy_write_field32(int addr, int offset, int mask, int value)
{
	u32 cur_value;
	u32 new_value;
	cur_value = u3_phy_read_reg32(addr);
	new_value = (cur_value & (~mask)) | ((value << offset) & mask);
	//udelay(i2cdelayus);
	u3_phy_write_reg32(addr, new_value);
}

u32 u3_phy_write_reg8(u32 addr, u8 data)
{
	u32 bank;
	u32 addr8;

	PHY_LOG("addr8: %x\n", addr);
	bank = (addr >> 16) & 0xff;
	addr8 = addr & 0xff;
	_u3_write_bank(bank);
	_u3_write_reg(addr8, data);

	return 0;
}

char u3_phy_read_reg8(u32 addr)
{
	int bank;
	int addr8;
	int data;

	bank = (addr >> 16) & 0xff;
	addr8 = addr & 0xff;
	_u3_write_bank(bank);
	data = _u3_read_reg(addr8);

	return data;
}

static void mu3d_hal_pdn_dis(void)
{
	clrbits(U3D_SSUSB_IP_PW_CTRL2, SSUSB_IP_DEV_PDN);
#ifdef SUPPORT_U3
	clrbits(U3D_SSUSB_U3_CTRL_0P, (SSUSB_U3_PORT_DIS | SSUSB_U3_PORT_PDN | SSUSB_U3_PORT_U2_CG_EN));
#endif
	clrbits(U3D_SSUSB_U2_CTRL_0P, (SSUSB_U2_PORT_DIS | SSUSB_U2_PORT_PDN | SSUSB_U2_PORT_U2_CG_EN));
}

int mu3d_hal_phy_scan(struct u3phy_info *u3phy, int latch_val)
{
#ifdef CONFIG_U3_PHY_GPIO_SUPPORT
	int count, fset_phase_val, u0_count;
	u8 phase_val, driving;
	//temp, data_driving_val, clk_driving_val;

#ifdef DBG_USB_PHY
	int link_error_count, recov_cnt;
#endif

	/* disable ip power down,disable U2/U3 ip power down. */
	mu3d_hal_ssusb_en();
	mu3d_hal_pdn_dis();

#if defined(CONFIG_D60802_SUPPORT)
	phy_change_pipe_phase_d60802(u3phy, 0, 0);
#elif defined(CONFIG_E60802_SUPPORT)
	phy_change_pipe_phase_e60802(u3phy, 0, 0);
#endif

	writel(latch_val, U3D_PIPE_LATCH_SELECT); /* set tx/rx latch sel */

	driving = 2;
#if defined(CONFIG_D60802_SUPPORT)
	phy_change_pipe_phase_d60802(u3phy, driving, driving);
#elif defined(CONFIG_E60802_SUPPORT)
	phy_change_pipe_phase_e60802(u3phy, driving, driving);
#endif
	phase_val = 0;
	count = 0;
	fset_phase_val = TRUE;

	while (TRUE) {

		if (fset_phase_val) {

#if defined(CONFIG_D60802_SUPPORT)
			phy_change_pipe_phase_d60802(u3phy, driving, phase_val);
#elif defined(CONFIG_E60802_SUPPORT)
			phy_change_pipe_phase_e60802(u3phy, driving, phase_val);
#endif
			mu3d_hal_rst_dev();
			mdelay(50);
			writel(USB3_EN, U3D_USB3_CONFIG);
			writel(latch_val, U3D_PIPE_LATCH_SELECT); /* set tx/rx latch sel */
			fset_phase_val = FALSE;
			u0_count = 0;
#ifdef DBG_USB_PHY
			link_error_count = 0;
			recov_cnt = 0;
#endif
			count = 0;
		}
		mdelay(50);
		count++;

#ifdef DBG_USB_PHY
		/* read U0 recovery count */
		recov_cnt = readl(U3D_RECOVERY_COUNT);
		/* read link error count */
		link_error_count = readl(U3D_LINK_ERR_COUNT);
#endif
		/* enter U0 state */
		if ((readl(U3D_LINK_STATE_MACHINE) & LTSSM) == STATE_U0_STATE) {
			u0_count++;
		}

		/* link up */
		if (u0_count > ENTER_U0_TH) {
			mdelay(1000);//1s
#ifdef DBG_USB_PHY
			recov_cnt = readl(U3D_RECOVERY_COUNT);
			link_error_count = readl(U3D_LINK_ERR_COUNT);
#endif
			writel(CLR_RECOV_CNT, U3D_RECOVERY_COUNT); /* clear recovery count */
			writel(CLR_LINK_ERR_CNT, U3D_LINK_ERR_COUNT); /* clear link error count */
#ifdef DBG_USB_PHY
			PHY_LOG("[PASS] Link Error Count=%d, Recovery Count=%d, I2C(0x%x) : [0x%x], I2C(0x%x) : [0x%x], Reg(0x130) : [0x%x], PhaseDelay[0x%x], Driving[0x%x], Latch[0x%x]\n",
			        link_error_count, recov_cnt,
			        U3_PHY_I2C_PCLK_DRV_REG, _u3_read_reg(U3_PHY_I2C_PCLK_DRV_REG),
			        U3_PHY_I2C_PCLK_PHASE_REG, _u3_read_reg(U3_PHY_I2C_PCLK_PHASE_REG),
			        readl(U3D_PIPE_LATCH_SELECT),
			        phase_val, driving, latch_val);
#endif
			phase_val++;
			fset_phase_val = TRUE;
		} else if ((readl(U3D_LINK_STATE_MACHINE) & LTSSM) == STATE_DISABLE) { /* link fail */
			PHY_LOG("[FAIL] STATE_DISABLE, PhaseDelay[0x%x]\n", phase_val);
			phase_val++;
			fset_phase_val=TRUE;
		} else if (count > MAX_TIMEOUT_COUNT) { /* link timeout */
			PHY_LOG("[FAIL] TIMEOUT, PhaseDelay[0x%x]\n", phase_val);
			phase_val++;
			fset_phase_val = TRUE;
		}

		if (phase_val > MAX_PHASE_RANGE) {
			/* reset device */
			mu3d_hal_rst_dev();
			mdelay(50);
			/* disable ip power down, disable U2/U3 ip power down. */
			mu3d_hal_ssusb_en();
			mu3d_hal_pdn_dis();
			mdelay(10);

			break;
		}
	}
#endif /* CONFIG_U3_PHY_GPIO_SUPPORT */

	return 0;
}

void mt_usb_phy_poweron(void)
{
	static struct u3phy_info info;
#ifdef DBG_USB_PHY
	volatile u32 u3phy_version;
#endif
	info.phyd_version_addr = 0x2000e4;
#ifdef DBG_USB_PHY
	u3phy_version = u3_phy_read_reg32(info.phyd_version_addr);
	PHY_LOG("[USBPHY] Phy version is %x\n", u3phy_version);
#endif

#if defined(CONFIG_D60802_SUPPORT)
	info.u2phy_regs_d = (struct u2phy_reg_d *)0x0;
	info.u3phyd_regs_d = (struct u3phyd_reg_d *)0x100000;
	info.u3phyd_bank2_regs_d = (struct u3phyd_bank2_reg_d *)0x200000;
	info.u3phya_regs_d = (struct u3phya_reg_d *)0x300000;
	info.u3phya_da_regs_d = (struct u3phya_da_reg_d *)0x400000;
	info.sifslv_chip_regs_d = (struct sifslv_chip_reg_d *)0x500000;
	info.sifslv_fm_regs_d = (struct sifslv_fm_feg_d *)0xf00000;

	phy_init_d60802(&info);
#elif defined(CONFIG_E60802_SUPPORT)
	info.u2phy_regs_e = (struct u2phy_reg_e *)0x0;
	info.u3phyd_regs_e = (struct u3phyd_reg_e *)0x100000;
	info.u3phyd_bank2_regs_e = (struct u3phyd_bank2_reg_e *)0x200000;
	info.u3phya_regs_e = (struct u3phya_reg_e *)0x300000;
	info.u3phya_da_regs_e = (struct u3phya_da_reg_e *)0x400000;
	info.sifslv_chip_regs_e = (struct sifslv_chip_reg_e *)0x500000;
	info.sifslv_fm_regs_e = (struct sifslv_fm_feg_e *)0xf00000;

	phy_init_e60802(&info);
#endif

	/* for RF desense */
#if defined(CONFIG_D60802_SUPPORT)
	//u2_slew_rate_calibration_d60802(&info);
#elif defined(CONFIG_E60802_SUPPORT)
	//u2_slew_rate_calibration_e60802(&info);
#endif

	mu3d_hal_ssusb_en();
	mu3d_hal_rst_dev();
}

void mt_usb_phy_savecurrent(void)
{
}
void mt_usb_phy_recover(void)
{
}
void mt_usb11_phy_savecurrent(void)
{
}
#else
//#include <platform/project.h>

void switch_2_usb()
{
	clrbits(U3D_U2PHYDTM0, A60810_FORCE_UART_EN);
	clrbits(U3D_U2PHYDTM1, A60810_RG_UART_EN);
	clrbits(U3D_U2PHYACR4, A60810_RG_USB20_GPIO_CTL);
	clrbits(U3D_U2PHYACR4, A60810_USB20_GPIO_MODE);
}

void mt_usb_phy_poweron(void)
{
	/* 5, power domain iso disable */
	clrbits(U3D_USBPHYACR6, A60810_RG_USB20_ISO_EN);
	/* 6, switch to USB function */
	switch_2_usb();
	/* 7, DP/DM BC1.1 path Disable */
	clrbits(U3D_USBPHYACR6, A60810_RG_USB20_BC11_SW_EN);
	/* 8, dp_100k diable */
	clrbits(U3D_USBPHYACR4, A60810_USB20_DP_100K_EN);
	/* 9, dm_100k disable */
	clrbits(U3D_USBPHYACR4, A60810_RG_USB20_DM_100K_EN);
	/* 10, Change 100uA current switch to SSUSB */
	setbits(U3D_USBPHYACR5, A60810_RG_USB20_HS_100U_U3_EN);
	/* 11, OTG enable */
	setbits(U3D_USBPHYACR6, A60810_RG_USB20_OTG_VBUSCMP_EN);
	/* 12, Release force suspendm */
	clrbits(U3D_U2PHYDTM0, A60810_FORCE_SUSPENDM);
}

void mt_usb_phy_savecurrent(void)
{
	/* 1, switch to usb function */
	switch_2_usb();
	/* 2, let syspendm=1 */
	setbits(U3D_U2PHYDTM0, A60810_RG_SUSPENDM);
	/* 3, force_suspendm */
	setbits(U3D_U2PHYDTM0, A60810_FORCE_SUSPENDM);
	/* 4 wait for USBPLL stable */
	mdelay(2);
	/* 5 */
	setbits(U3D_U2PHYDTM0, A60810_RG_DPPULLDOWN);
	/* 6 */
	setbits(U3D_U2PHYDTM0, A60810_RG_DMPULLDOWN);
	/* 7 */
	writel((readl(U3D_U2PHYDTM0) & ~A60810_RG_XCVRSEL) | (0x1 << A60810_RG_XCVRSEL_OFST), U3D_U2PHYDTM0);
	/* 8 */
	setbits(U3D_U2PHYDTM0, A60810_RG_TERMSEL);
	/* 9 */
	clrbits(U3D_U2PHYDTM0, A60810_RG_DATAIN);
	/* 10 */
	setbits(U3D_U2PHYDTM0, A60810_FORCE_DP_PULLDOWN);
	/* 11 */
	setbits(U3D_U2PHYDTM0, A60810_FORCE_DM_PULLDOWN);
	/* 12 */
	setbits(U3D_U2PHYDTM0, A60810_FORCE_XCVRSEL);
	/* 13 */
	setbits(U3D_U2PHYDTM0, A60810_FORCE_TERMSEL);
	/* 14 */
	setbits(U3D_U2PHYDTM0, A60810_FORCE_DATAIN);
	/* 15, DP/DM BC1.1 path Disable */
	clrbits(U3D_USBPHYACR6, A60810_RG_USB20_BC11_SW_EN);
	/* 16, OTG disable */
	clrbits(U3D_USBPHYACR6, A60810_RG_USB20_OTG_VBUSCMP_EN);
	/* 17, Change 100uA current switch to USB2.0 */
	clrbits(U3D_USBPHYACR5, A60810_RG_USB20_HS_100U_U3_EN);
	/* 18, wait 800us */
	mdelay(1);
	/* 19 */
	clrbits(U3D_U2PHYDTM0, A60810_RG_SUSPENDM);
	/* 20, wait 1us */
	mdelay(1);

	clrbits(U3D_USB30_PHYA_REG0, RG_SSUSB_VUSB10_ON);
}

void setting_ref_clk_e60802(void)
{
	u32 val;

	/*
	 * Reference clock use digital P&R, instead of analog path
	 * possibly more interference
	 * ---------REG Name---------- | -----Modification---| -----Description----
	 * DA_SSUSB_XTAL_EXT_EN[1:0]   | 2'b01-->2'b10       | 0x11290c00 bit[11:10]
	 * DA_SSUSB_XTAL_RX_PWD[9:9]   | -->1'b1             | 0x11280018 bit[9]
	 */
	val = readl(U3D_U3PHYA_DA_REG0) & ~A60810_RG_SSUSB_XTAL_EXT_EN_U3;
	val |= ((0x2) << A60810_RG_SSUSB_XTAL_EXT_EN_U3_OFST) & A60810_RG_SSUSB_XTAL_EXT_EN_U3;
	writel(val, U3D_U3PHYA_DA_REG0);
	val = readl(U3D_SPLLC_XTALCTL3) & ~A60810_RG_SSUSB_XTAL_RX_PWD;
	val |= ((0x01) << A60810_RG_SSUSB_XTAL_RX_PWD_OFST) & A60810_RG_SSUSB_XTAL_RX_PWD;
	writel(val, U3D_SPLLC_XTALCTL3);

	/*
	 * ---------REG Name---------- | -----Modification---| -----Description----
	 * 1 RG_SSUSB_TX_EIDLE_CM[3:0] | 1100-->1110         | low-power E-idle common mode(650mV to 600mV)
	 *                             |                     | - 0x11290b18 bit [31:28]
	 * 2 RG_SSUSB_CDR_BIR_LTD0[4:0]| 5'b01000-->5'b01100 | Increase BW - 0x1128095c bit [12:8]
	 * 3 RG_XXX_CDR_BIR_LTD1[4:0]  | 5'b00010-->5'b00011 | Increase BW - 0x1128095c bit [28:24]
	 */
	val = readl(U3D_USB30_PHYA_REG6) & ~A60810_RG_SSUSB_TX_EIDLE_CM;
	val |= ((0xE) << A60810_RG_SSUSB_TX_EIDLE_CM_OFST) & A60810_RG_SSUSB_TX_EIDLE_CM;
	writel(val, U3D_USB30_PHYA_REG6);

	val = readl(U3D_PHYD_CDR1) & ~A60810_RG_SSUSB_CDR_BIR_LTD0;
	val |= ((0xC) << A60810_RG_SSUSB_CDR_BIR_LTD0_OFST) & A60810_RG_SSUSB_CDR_BIR_LTD0;
	writel(val, U3D_PHYD_CDR1);

	val = readl(U3D_PHYD_CDR1) & ~A60810_RG_SSUSB_CDR_BIR_LTD1;
	val |= ((0x3) << A60810_RG_SSUSB_CDR_BIR_LTD1_OFST) & A60810_RG_SSUSB_CDR_BIR_LTD1;
	writel(val, U3D_PHYD_CDR1);
}

void mt_usb_phy_recover(void)
{
#if (MACH_TYPE == 6755)
	setbits(U3D_USB30_PHYA_REG0, RG_SSUSB_VUSB10_ON);
#endif
	/* 4, power domain iso disable */
	clrbits(U3D_USBPHYACR6, A60810_RG_USB20_ISO_EN);
	/* 5, switch to usb function */
	switch_2_usb();
	/* 6, force_suspendm */
	clrbits(U3D_U2PHYDTM0, A60810_FORCE_SUSPENDM);
	/* 7 */
	clrbits(U3D_U2PHYDTM0, A60810_RG_DPPULLDOWN);
	/* 8 */
	clrbits(U3D_U2PHYDTM0, A60810_RG_DMPULLDOWN);
	/* 9 */
	clrbits(U3D_U2PHYDTM0, A60810_RG_XCVRSEL);
	/* 10 */
	clrbits(U3D_U2PHYDTM0, A60810_FORCE_TERMSEL);
	/* 11 */
	clrbits(U3D_U2PHYDTM0, A60810_RG_DATAIN);
	/* 12 */
	clrbits(U3D_U2PHYDTM0, A60810_FORCE_DP_PULLDOWN);
	/* 13 */
	clrbits(U3D_U2PHYDTM0, A60810_FORCE_DM_PULLDOWN);
	/* 14 */
	clrbits(U3D_U2PHYDTM0, A60810_FORCE_XCVRSEL);
	/* 15 */
	clrbits(U3D_U2PHYDTM0, A60810_FORCE_TERMSEL);
	/* 16 */
	clrbits(U3D_U2PHYDTM0, A60810_FORCE_DATAIN);
	/* 17, DP/DM BC1.1 path Disable */
	clrbits(U3D_USBPHYACR6, A60810_RG_USB20_BC11_SW_EN);
	/* 18, OTG enable */
	setbits(U3D_USBPHYACR6, A60810_RG_USB20_OTG_VBUSCMP_EN);
#if (MACH_TYPE == 6755)
	/* 19, Change 100uA current switch to SSUSB */
	setbits(U3D_USBPHYACR5, A60810_RG_USB20_HS_100U_U3_EN);
#endif

	setting_ref_clk_e60802();

	/* 20, wait 800us */
	mdelay(1);
}
#endif
