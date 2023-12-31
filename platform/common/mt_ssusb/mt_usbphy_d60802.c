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
#include <debug.h>
#include <reg.h>
#include <platform/bitops.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <platform/timer.h>

#include <mt_ssusb_sifslv_ippc.h>
#include <mt_ssusb.h>
#include <mt_ssusbphy.h>
#include <mt_usbphy_d60802.h>
#include <mt_ssusb_usb3_mac_csr.h>

#ifdef MACH_FPGA
#define CFG_FPGA_PLATFORM   (1)
#else
#define DBG_PHY_CALIBRATION 1
#endif

#ifdef DBG_USB_PHY
#define PHY_LOG(x...) dprintf(INFO, "[USB][PHY] " x)
#else
#define PHY_LOG(x...) do{} while(0)
#endif

#define PHY_DRV_SHIFT   3
#define PHY_PHASE_SHIFT 3
#define PHY_PHASE_DRV_SHIFT 1

#if CFG_FPGA_PLATFORM
u32 u2_slew_rate_calibration_d60802(struct u3phy_info *info)
{
	u32 i = 0;
	u32 ret = 0;
	u32 u4fmout = 0;
	u32 u4tmp = 0;
#ifdef DBG_USB_PHY
	volatile u32 chkvalue;
#endif

	PHY_LOG("[USBPHY] %s starts\n", __func__);

	/* => RG_USB20_HSTX_SRCAL_EN = 1 */
	/* enable HS TX SR calibration */
	u3_phy_write_field32(((u32)&info->u2phy_regs_d->usbphyacr5),
	                     D60802_RG_USB20_HSTX_SRCAL_EN_OFST, D60802_RG_USB20_HSTX_SRCAL_EN, 1);
	mdelay(1);
#ifdef DBG_USB_PHY
	chkvalue = u3_phy_read_reg32(((u32)&info->u2phy_regs_d->usbphyacr5));
	PHY_LOG("chkvalue: %d\n", chkvalue);
#endif

	/* => RG_FRCK_EN = 1 */
	/* Enable free run clock */
	u3_phy_write_field32(((u32)&info->sifslv_fm_regs_d->fmmonr1),
	                     D60802_RG_FRCK_EN_OFST, D60802_RG_FRCK_EN, 0x1);

	/* => RG_CYCLECNT = 4 */
	/* Setting cyclecnt = 4 */
	u3_phy_write_field32(((u32)&info->sifslv_fm_regs_d->fmcr0),
	                     D60802_RG_CYCLECNT_OFST, D60802_RG_CYCLECNT, 0x4);

	/* => RG_FREQDET_EN = 1 */
	/* Enable frequency meter */
	u3_phy_write_field32(((u32)&info->sifslv_fm_regs_d->fmcr0),
	                     D60802_RG_FREQDET_EN_OFST, D60802_RG_FREQDET_EN, 0x1);

	/* wait for FM detection done, set 10ms timeout */
	for (i = 0; i < 10; i++) {
		/* => u4fmout = USB_FM_OUT */
		/* read FM_OUT */
		u4fmout = u3_phy_read_reg32(((u32)&info->sifslv_fm_regs_d->fmmonr0));
		PHY_LOG("FM_OUT value: u4fmout = %d(0x%08X)\n", u4fmout, u4fmout);

		/* check if FM detection done */
		if (u4fmout != 0) {
			ret = 0;
			PHY_LOG("FM detection done! loop = %d\n", i);
			break;
		}

		ret = 1;
		mdelay(1);
	}

	/* => RG_FREQDET_EN = 0 */
	/* disable frequency meter */
	u3_phy_write_field32(((u32)&info->sifslv_fm_regs_d->fmcr0),
	                     D60802_RG_FREQDET_EN_OFST, D60802_RG_FREQDET_EN, 0);

	/* => RG_FRCK_EN = 0 */
	/* disable free run clock */
	u3_phy_write_field32(((u32)&info->sifslv_fm_regs_d->fmmonr1),
	                     D60802_RG_FRCK_EN_OFST, D60802_RG_FRCK_EN, 0);

	/* => RG_USB20_HSTX_SRCAL_EN = 0 */
	/* disable HS TX SR calibration */
	u3_phy_write_field32(((u32)&info->u2phy_regs_d->usbphyacr0),
	                     D60802_RG_USB20_HSTX_SRCAL_EN_OFST, D60802_RG_USB20_HSTX_SRCAL_EN, 0);
	mdelay(1);

	if (u4fmout == 0) {
		u3_phy_write_field32(((u32)&info->u2phy_regs_d->usbphyacr5),
		                     D60802_RG_USB20_HSTX_SRCTRL_OFST, D60802_RG_USB20_HSTX_SRCTRL, 0x4);
		ret = 1;
	} else {
		/* set reg = (1024/FM_OUT) * 25 * 0.028 (round to the nearest digits) */
		u4tmp = (((1024 * 25 * U2_SR_COEF_D60802) / u4fmout) + 500) / 1000;
		PHY_LOG("SR calibration value u1SrCalVal = %d\n", (u8)u4tmp);
		u3_phy_write_field32(((u32)&info->u2phy_regs_d->usbphyacr5),
		                     D60802_RG_USB20_HSTX_SRCTRL_OFST, D60802_RG_USB20_HSTX_SRCTRL, u4tmp);
	}

	PHY_LOG("[USBPHY] %s ends\n", __func__);

	return ret;
}

int phy_change_pipe_phase_d60802(struct u3phy_info *info, int phy_drv, int pipe_phase)
{
	int drv_reg_value;
	int phase_reg_value;
	int temp;

	drv_reg_value = phy_drv << PHY_DRV_SHIFT;
	phase_reg_value = (pipe_phase << PHY_PHASE_SHIFT) | (phy_drv << PHY_PHASE_DRV_SHIFT);
	temp = u3_phy_read_reg8(((u32)&info->sifslv_chip_regs_d->gpio_ctla)+2);
	temp &= ~(0x3 << PHY_DRV_SHIFT);
	temp |= drv_reg_value;
	u3_phy_write_reg8(((u32)&info->sifslv_chip_regs_d->gpio_ctla)+2, temp);
	temp = u3_phy_read_reg8(((u32)&info->sifslv_chip_regs_d->gpio_ctla)+3);
	temp &= ~((0x3 << PHY_PHASE_DRV_SHIFT) | (0x1f << PHY_PHASE_SHIFT));
	temp |= phase_reg_value;
	u3_phy_write_reg8(((u32)&info->sifslv_chip_regs_d->gpio_ctla)+3, temp);

	return TRUE;
}

void phy_init_d60802(struct u3phy_info *info)
{
	//char temp;
	//volatile u32 chkvalue = 0;

	/* u2phy part */
	/* manual set U2 slew rate ctrl = 4 */
	u3_phy_write_field32(((u32)&info->u2phy_regs_d->usbphyacr5),
	                     D60802_RG_USB20_HSTX_SRCTRL_OFST, D60802_RG_USB20_HSTX_SRCTRL, 0x4);

	/* fine tune SQTH to gain margin in U2 Rx sensitivity compliance test */
	u3_phy_write_field32(((u32)&info->u2phy_regs_d->usbphyacr6),
	                     D60802_RG_USB20_SQTH_OFST, D60802_RG_USB20_SQTH, 0x4);

	/* disable VBUS CMP to save power since no OTG function */
	u3_phy_write_field32(((u32)&info->u2phy_regs_d->usbphyacr6),
	                     D60802_RG_USB20_OTG_VBUSCMP_EN_OFST, D60802_RG_USB20_OTG_VBUSCMP_EN, 1);

	/* phyd part */
	/* shorten Tx drive stable delay time from 82us -> 25us */
	u3_phy_write_field32(((u32)&info->u3phyd_regs_d->phyd_mix1),
	                     D60802_RG_SSUSB_TX_DRV_DLY_OFST, D60802_RG_SSUSB_TX_DRV_DLY, 0x13);

	/* The same Rx LFPS detect period   rxlfps_upb as A ver */
	u3_phy_write_field32(((u32)&info->u3phyd_regs_d->phyd_lfps0),
	                     D60802_RG_SSUSB_RXLFPS_UPB_OFST, D60802_RG_SSUSB_RXLFPS_UPB, 0x19);

	/* No switch to Lock 5g @tx_lfps enable */
	u3_phy_write_field32(((u32)&info->u3phyd_regs_d->phyd_lfps0),
	                     D60802_RG_SSUSB_LOCK5G_BLOCK_OFST, D60802_RG_SSUSB_LOCK5G_BLOCK, 0x1);

	/* disable DFE to improve Rx JT */
	u3_phy_write_field32(((u32)&info->u3phyd_regs_d->phyd_rx0),
	                     D60802_RG_SSUSB_RX_DFE_RST_OFST, D60802_RG_SSUSB_RX_DFE_RST, 0);

	/* calibrate CDR offset every time enter TSEQ */
	u3_phy_write_field32(((u32)&info->u3phyd_regs_d->phyd_mix2),
	                     D60802_RG_SSUSB_CDROS_EN_OFST, D60802_RG_SSUSB_CDROS_EN, 0x1);

	/* Re-Calibration after exit P3 state */
	u3_phy_write_field32(((u32)&info->u3phyd_regs_d->phyd_pll_0),
	                     D60802_RG_SSUSB_PLLBAND_RECAL_OFST, D60802_RG_SSUSB_PLLBAND_RECAL, 0x1);
	/* phyd bank2 part */
	/* Disable E-Idle Low power mode */
	u3_phy_write_field32(((u32)&info->u3phyd_bank2_regs_d->b2_phyd_top1),
	                     D60802_RG_SSUSB_FORCE_TX_EIDLE_LP_EN_OFST , D60802_RG_SSUSB_FORCE_TX_EIDLE_LP_EN, 0x1);

	u3_phy_write_field32(((u32)&info->u3phyd_bank2_regs_d->b2_phyd_top1),
	                     D60802_RG_SSUSB_TX_EIDLE_LP_EN_OFST, D60802_RG_SSUSB_TX_EIDLE_LP_EN, 0);

	/* phya part */
	/* modify Tx det Rx Vth to work around the threshold back to 200mV */
	u3_phy_write_field32(((u32)&info->u3phya_regs_d->reg5),
	                     D60802_REG5_FLD_RG_SSUSB_RXDET_VTHSEL_L_OFST, D60802_REG5_FLD_RG_SSUSB_RXDET_VTHSEL_L,0x2);

	/* modify Tx det Rx Vth to work around the threshold back to 200mV */
	u3_phy_write_field32(((u32)&info->u3phya_regs_d->reg5),
	                     D60802_REG5_FLD_RG_SSUSB_RXDET_VTHSEL_H_OFST, D60802_REG5_FLD_RG_SSUSB_RXDET_VTHSEL_H,0x2);

	/* phya da part */
	/* set to pass SSC min in electrical compliance */
	u3_phy_write_field32(((u32)&info->u3phya_da_regs_d->reg21),
	                     D60802_REG21_FLD_RG_SSUSB_PLL_SSC_DELTA_U3_OFST, D60802_REG21_FLD_RG_SSUSB_PLL_SSC_DELTA_U3,0x47);

	/* set R step 1 = 2 to improve Rx JT */
	u3_phy_write_field32(((u32)&info->u3phya_da_regs_d->reg32),
	                     D60802_REG32_FLD_RG_SSUSB_EQ_RSTEP1_U3_OFST, D60802_REG32_FLD_RG_SSUSB_EQ_RSTEP1_U3, 0x2);

	/* phy chip part */
	/* Power down bias at P3, p3 bias _pwd */

	u3_phy_write_field32(((u32)&info->sifslv_chip_regs_d->syspll1),
	                     (24), (0x1<<24), 0x1);

	/*  PIPE drv = 2 */
	u3_phy_write_reg8(((u32)&info->sifslv_chip_regs_d->gpio_ctla+2), 0x10);

	/*  PIPE phase */
	//u3_phy_write_reg8(((u32)&info->sifslv_chip_regs_d->gpio_ctla+3), 0x44);
	/* for 3.0 */
	//u3_phy_write_reg8(((u32)&info->sifslv_chip_regs_d->gpio_ctla+3), 0x8c);
	//u3_phy_write_reg8(((u32)&info->sifslv_chip_regs_d->gpio_ctla+3), 0x3D);
	u3_phy_write_reg8(((u32)&info->sifslv_chip_regs_d->gpio_ctla+3), 0x75);

	mdelay(1000);

	/* scan proper phase for ssusb */
	//mu3d_hal_phy_scan(info, 1);
	//mu3d_hal_phy_scan(info, 0);
}
#endif
