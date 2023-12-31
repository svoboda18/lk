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
 * MediaTek Inc. (C) 2016. All rights reserved.
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
/******************************************************************************
 * MTK PMIC Wrapper Driver
 *
 * Copyright 2016 MediaTek Co.,Ltd.
 *
 * DESCRIPTION:
 *     This file provides API for other drivers to access PMIC registers
 *
 ******************************************************************************/

#include <mt_pmic_wrap_init.h>
#if (PMIC_WRAP_PRELOADER)
#elif (PMIC_WRAP_LK)
#elif (PMIC_WRAP_KERNEL)
#elif (PMIC_WRAP_CTP)
#include <gpio.h>
#include <upmu_hw.h>
#else
### Compile error, check SW ENV define
#endif


/************* marco    ******************************************************/
#if (PMIC_WRAP_PRELOADER)
#elif (PMIC_WRAP_LK)
#elif (PMIC_WRAP_KERNEL)
#elif (PMIC_WRAP_SCP)
#elif (PMIC_WRAP_CTP)
#else
### Compile error, check SW ENV define
#endif

#ifdef PMIC_WRAP_NO_PMIC
#if !(PMIC_WRAP_KERNEL)
signed int pwrap_wacs2(unsigned int  write, unsigned int  adr, unsigned int  wdata, unsigned int *rdata)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_read(unsigned int adr, unsigned int *rdata)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_write(unsigned int adr, unsigned int wdata)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}
#endif
signed int pwrap_wacs2_read(unsigned int  adr, unsigned int *rdata)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}

/* Provide PMIC write API */
signed int pwrap_wacs2_write(unsigned int  adr, unsigned int  wdata)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_read_nochk(unsigned int adr, unsigned int *rdata)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_write_nochk(unsigned int adr, unsigned int wdata)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}

/*
 *pmic_wrap init,init wrap interface
 *
 */
signed int pwrap_init(void)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_init_preloader(void)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_init_lk(void)
{
	PWRAPLOG("[PMIC_WRAP]There is no PMIC real chip, PMIC_WRAP do Nothing.\n");
	return 0;
}
#else /* #ifdef PMIC_WRAP_NO_PMIC */
/*********************start ---internal API***********************************/
static int _pwrap_timeout_ns(unsigned long long start_time_ns, unsigned long long timeout_time_ns);
static unsigned long long _pwrap_get_current_time(void);
static unsigned long long _pwrap_time2ns(unsigned long long time_us);
static void _pwrap_enable(void);
static void _pwrap_starve_set(void);
static signed int _pwrap_wacs2_nochk(unsigned int write, unsigned int adr, unsigned int wdata, unsigned int *rdata);
static signed int pwrap_wacs2_hal(unsigned int write, unsigned int adr, unsigned int wdata, unsigned int *rdata);
/*********************test API************************************************/
static inline void pwrap_dump_ap_register(void);
static unsigned int pwrap_write_test(void);
static unsigned int pwrap_read_test(void);
static signed int pwrap_reset_pattern(void);
signed int pwrap_wacs2_read(unsigned int  adr, unsigned int *rdata);
signed int pwrap_wacs2_write(unsigned int  adr, unsigned int  wdata);
static unsigned int si_sample_ctrl = 0;
struct pwrap_rc_info {
	unsigned int wacs2_cmd;
	unsigned int dcxo_en;
	unsigned int dcxo_conn_adr0;
	unsigned int dcxo_conn_wdata0;
	unsigned int dcxo_conn_adr1;
	unsigned int dcxo_conn_wdata1;
	unsigned int dcxo_nfc_adr0;
	unsigned int dcxo_nfc_wdata0;
	unsigned int dcxo_nfc_adr1;
	unsigned int dcxo_nfc_wdata1;
};
/************* end--internal API**********************************************/
/*********************** external API for pmic_wrap user ************************/
signed int pwrap_wacs2_read(unsigned int  adr, unsigned int *rdata)
{
	pwrap_wacs2(0, adr, 0, rdata);
	return 0;
}

/* Provide PMIC write API */
signed int pwrap_wacs2_write(unsigned int  adr, unsigned int  wdata)
{
#ifdef CONFIG_MTK_TINYSYS_SSPM_SUPPORT
	unsigned int flag;

	flag = WRITE_CMD | (1 << WRITE_PMIC);
	pwrap_wacs2_ipi(adr, wdata, flag);
#else
	pwrap_wacs2(1, adr, wdata, 0);
#endif
	return 0;
}

signed int pwrap_read(unsigned int adr, unsigned int *rdata)
{
	return pwrap_wacs2(0,adr,0,rdata);
}

signed int pwrap_write(unsigned int adr, unsigned int  wdata)
{
	return pwrap_wacs2(1,adr,wdata,0);
}
/******************************************************************************
 *wrapper timeout
 *****************************************************************************/
/*use the same API name with kernel driver
 *however,the timeout API in uboot use tick instead of ns
 */

#ifdef PWRAP_TIMEOUT
static unsigned long long _pwrap_get_current_time(void)
{
	return gpt4_get_current_tick();
}

static int _pwrap_timeout_ns(unsigned long long start_time_ns, unsigned long long timeout_time_ns)
{
	return gpt4_timeout_tick(start_time_ns, timeout_time_ns);
}

static unsigned long long _pwrap_time2ns(unsigned long long time_us)
{
	return gpt4_time2tick_us(time_us);
}

#else
static unsigned long long _pwrap_get_current_time(void)
{
	return 0;
}
static int _pwrap_timeout_ns(unsigned long long start_time_ns, unsigned long long elapse_time)
{
	return 0;
}

static unsigned long long _pwrap_time2ns(unsigned long long time_us)
{
	return 0;
}

#endif

/* ##################################################################### */
/* define macro and inline function (for do while loop) */
/* ##################################################################### */
typedef unsigned int(*loop_condition_fp) (unsigned int);    /* define a function pointer */

static inline unsigned int wait_for_fsm_idle(unsigned int x)
{
	return GET_WACS2_FSM(x) != WACS_FSM_IDLE;
}

static inline unsigned int wait_for_fsm_vldclr(unsigned int x)
{
	return GET_WACS2_FSM(x) != WACS_FSM_WFVLDCLR;
}

static inline unsigned int wait_for_sync(unsigned int x)
{
	return GET_SYNC_IDLE2(x) != WACS_SYNC_IDLE;
}

static inline unsigned int wait_for_idle_and_sync(unsigned int x)
{
	return (GET_WACS2_FSM(x) != WACS_FSM_IDLE) || (GET_SYNC_IDLE2(x) != WACS_SYNC_IDLE);
}

static inline unsigned int wait_for_wrap_idle(unsigned int x)
{
	return (GET_WRAP_FSM(x) != 0x0) || (GET_WRAP_CH_DLE_RESTCNT(x) != 0x0);
}

static inline unsigned int wait_for_wrap_state_idle(unsigned int x)
{
	return GET_WRAP_AG_DLE_RESTCNT(x) != 0;
}

static inline unsigned int wait_for_man_idle_and_noreq(unsigned int x)
{
	return (GET_MAN_REQ(x) != MAN_FSM_NO_REQ) || (GET_MAN_FSM(x) != MAN_FSM_IDLE);
}

static inline unsigned int wait_for_man_vldclr(unsigned int x)
{
	return GET_MAN_FSM(x) != MAN_FSM_WFVLDCLR;
}

static inline unsigned int wait_for_cipher_ready(unsigned int x)
{
	return x != 3;
}

static inline unsigned int wait_for_stdupd_idle(unsigned int x)
{
	return GET_STAUPD_FSM(x) != 0x0;
}

/**************used at _pwrap_wacs2_nochk*************************************/
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
static inline unsigned int wait_for_state_ready_init(loop_condition_fp fp, unsigned int timeout_us,
        void *wacs_register, unsigned int *read_reg)
#else
static inline unsigned int wait_for_state_ready_init(loop_condition_fp fp, unsigned int timeout_us,
        volatile unsigned int *wacs_register, unsigned int *read_reg)
#endif
{
	unsigned long long start_time_ns = 0, timeout_ns = 0;
	unsigned int reg_rdata = 0x0;

	start_time_ns = _pwrap_get_current_time();
	timeout_ns = _pwrap_time2ns(timeout_us);

	do {
		if (_pwrap_timeout_ns(start_time_ns, timeout_ns)) {
			PWRAPERR("ready_init timeout\n");
			pwrap_dump_ap_register();
			return E_PWR_WAIT_IDLE_TIMEOUT;
		}
		reg_rdata = WRAP_RD32(wacs_register);
	} while (fp(reg_rdata));

	if (read_reg)
		*read_reg = reg_rdata;

	return 0;
}

#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
static inline unsigned int wait_for_state_idle(loop_condition_fp fp, unsigned int timeout_us, void *wacs_register,
        void *wacs_vldclr_register, unsigned int *read_reg)
#else
static inline unsigned int wait_for_state_idle(loop_condition_fp fp, unsigned int timeout_us,
        volatile unsigned int *wacs_register, volatile unsigned int *wacs_vldclr_register, unsigned int *read_reg)
#endif
{
	unsigned long long start_time_ns = 0, timeout_ns = 0;
	unsigned int reg_rdata;

	start_time_ns = _pwrap_get_current_time();
	timeout_ns = _pwrap_time2ns(timeout_us);

	do {
		if (_pwrap_timeout_ns(start_time_ns, timeout_ns)) {
			PWRAPERR("state_idle timeout\n");
			pwrap_dump_ap_register();
			return E_PWR_WAIT_IDLE_TIMEOUT;
		}
		reg_rdata = WRAP_RD32(wacs_register);
		if (GET_WACS2_INIT_DONE2(reg_rdata) != WACS_INIT_DONE) {
			PWRAPERR("init isn't finished\n");
			pwrap_dump_ap_register();
			return E_PWR_NOT_INIT_DONE;
		}
		switch (GET_WACS2_FSM(reg_rdata)) {
			case WACS_FSM_WFVLDCLR:
				WRAP_WR32(wacs_vldclr_register, 1);
				PWRAPERR("WACS_FSM = VLDCLR\n");
				pwrap_dump_ap_register();
				break;
			case WACS_FSM_WFDLE:
				PWRAPERR("WACS_FSM = WFDLE\n");
				pwrap_dump_ap_register();
				break;
			case WACS_FSM_REQ:
				PWRAPERR("WACS_FSM = REQ\n");
				pwrap_dump_ap_register();
				break;
			default:
				break;
		}
	} while (fp(reg_rdata));
	if (read_reg)
		*read_reg = reg_rdata;

	return 0;
}

/**************used at pwrap_wacs2********************************************/
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
static inline unsigned int wait_for_state_ready(loop_condition_fp fp, unsigned int timeout_us, void *wacs_register,
        unsigned int *read_reg)
#else
static inline unsigned int wait_for_state_ready(loop_condition_fp fp, unsigned int timeout_us,
        volatile unsigned int *wacs_register, unsigned int *read_reg)
#endif
{
	unsigned long long start_time_ns = 0, timeout_ns = 0;
	unsigned int reg_rdata;

	start_time_ns = _pwrap_get_current_time();
	timeout_ns = _pwrap_time2ns(timeout_us);

	do {
		if (_pwrap_timeout_ns(start_time_ns, timeout_ns)) {
			PWRAPERR("state_ready timeout\n");
			pwrap_dump_ap_register();
			return E_PWR_WAIT_IDLE_TIMEOUT;
		}
		reg_rdata = WRAP_RD32(wacs_register);
		if (GET_WACS2_INIT_DONE2(reg_rdata) != WACS_INIT_DONE) {
			PWRAPERR("init isn't finished\n");
			pwrap_dump_ap_register();
			return E_PWR_NOT_INIT_DONE;
		}
	} while (fp(reg_rdata));
	if (read_reg)
		*read_reg = reg_rdata;

	return 0;
}

/******************************************************
 * Function : pwrap_wacs2()
 * Description :
 * Parameter :
 * Return :
 ******************************************************/
signed int pwrap_wacs2(unsigned int write, unsigned int adr, unsigned int wdata, unsigned int *rdata)
{
	unsigned int reg_rdata = 0;
	unsigned int wacs_write = 0;
	unsigned int wacs_adr = 0;
	unsigned int wacs_cmd = 0;
	unsigned int return_value = 0;
	signed int pwrap_ret = 0;

	/* Check argument validation */
	if ((write & ~(0x1)) != 0)
		return E_PWR_INVALID_RW;
	if ((adr & ~(0xffff)) != 0)
		return E_PWR_INVALID_ADDR;
	if ((wdata & ~(0xffff)) != 0)
		return E_PWR_INVALID_WDAT;

	/* Check IDLE & INIT_DONE in advance */
	return_value =
	    wait_for_state_idle(wait_for_fsm_idle, TIMEOUT_WAIT_IDLE, PMIC_WRAP_WACS2_RDATA,
	                        PMIC_WRAP_WACS2_VLDCLR, 0);
	if (return_value != 0) {
		PWRAPERR("fsm_idle fail,ret=%d\n", return_value);
		goto FAIL;
	}
RETRY:
	wacs_write = write << 31;
	wacs_adr = (adr >> 1) << 16;
	wacs_cmd = wacs_write | wacs_adr | wdata;

	WRAP_WR32(PMIC_WRAP_WACS2_CMD, wacs_cmd);
	if (write == 0) {
		if (rdata == NULL) {
			PWRAPERR("rdata NULL\n");
			return_value = E_PWR_INVALID_ARG;
			goto FAIL;
		}
		return_value =
		    wait_for_state_ready(wait_for_fsm_vldclr, TIMEOUT_READ, PMIC_WRAP_WACS2_RDATA,
		                         &reg_rdata);
		if (return_value != 0) {
			PWRAPERR("fsm_vldclr fail,ret=%d\n", return_value);
			return_value += 1;
			goto FAIL;
		}
		*rdata = GET_WACS2_RDATA(reg_rdata);
		WRAP_WR32(PMIC_WRAP_WACS2_VLDCLR, 1);
	}

FAIL:
	if (return_value != 0) {
		PWRAPERR("pwrap_wacs2 fail, ret=%d\n", return_value);
		pwrap_ret = pwrap_reset_pattern();
		if (pwrap_ret != 0) {
			PWRAPERR("pwrap_reset_pattern fail, ret=%x\n", pwrap_ret);
			pwrap_dump_ap_register();
		}
		else {
			dprintf(CRITICAL, PWRAPTAG "retry cmd: 0x%x, 0x%x, 0x%x\n", wacs_cmd, write, adr);
			goto RETRY;
		}
	}

	return return_value;
}


/*********************internal API for pwrap_init***************************/

/**********************************
 * Function : _pwrap_wacs2_nochk()
 * Description :
 * Parameter :
 * Return :
 ***********************************/
signed int pwrap_read_nochk(unsigned int adr, unsigned int *rdata)
{
	return _pwrap_wacs2_nochk(0, adr, 0, rdata);
}

signed int pwrap_write_nochk(unsigned int adr, unsigned int wdata)
{
	return _pwrap_wacs2_nochk(1, adr, wdata, 0);
}

static signed int _pwrap_wacs2_nochk(unsigned int write, unsigned int adr, unsigned int wdata, unsigned int *rdata)
{
	unsigned int reg_rdata = 0x0;
	unsigned int wacs_write = 0x0;
	unsigned int wacs_adr = 0x0;
	unsigned int wacs_cmd = 0x0;
	unsigned int return_value = 0x0;

	/* Check argument validation */
	if ((write & ~(0x1)) != 0)
		return E_PWR_INVALID_RW;
	if ((adr & ~(0xffff)) != 0)
		return E_PWR_INVALID_ADDR;
	if ((wdata & ~(0xffff)) != 0)
		return E_PWR_INVALID_WDAT;

	/* Check IDLE */
	return_value =
	    wait_for_state_ready_init(wait_for_fsm_idle, TIMEOUT_WAIT_IDLE, PMIC_WRAP_WACS2_RDATA, 0);
	if (return_value != 0) {
		PWRAPERR("write fail,ret=%x\n", return_value);
		return return_value;
	}

	wacs_write = write << 31;
	wacs_adr = (adr >> 1) << 16;
	wacs_cmd = wacs_write | wacs_adr | wdata;
	WRAP_WR32(PMIC_WRAP_WACS2_CMD, wacs_cmd);

	if (write == 0) {
		if (rdata == NULL) {
			PWRAPERR("rdata NULL\n");
			return_value = E_PWR_INVALID_ARG;
			return return_value;
		}
		return_value =
		    wait_for_state_ready_init(wait_for_fsm_vldclr, TIMEOUT_READ,
		                              PMIC_WRAP_WACS2_RDATA, &reg_rdata);
		if (return_value != 0) {
			PWRAPERR("fsm_vldclr fail,ret=%d\n", return_value);
			return_value += 1;
			return return_value;
		}
		*rdata = GET_WACS2_RDATA(reg_rdata);
		WRAP_WR32(PMIC_WRAP_WACS2_VLDCLR, 1);
	}

	return 0;
}

static void __pwrap_soft_reset(void)
{
	PWRAPLOG("start reset wrapper\n");
	WRAP_WR32(INFRA_GLOBALCON_RST2_SET, 0x1);
	WRAP_WR32(INFRA_GLOBALCON_RST2_CLR, 0x1);
}

static void __pwrap_spi_clk_set(void)
{
	PWRAPLOG("pwrap_spictl reset ok\n");

	/* sys_ck cg enable, turn off clock */
	WRAP_WR32(MODULE_SW_CG_0_SET, 0x0000000f);
	/* turn off clock */
	WRAP_WR32(MODULE_SW_CG_2_SET, 0x00000100);

	/* Select ULPOSC/16 Clock as SYS, TMR and SPI Clocks in SODI-3.0 and Suspend Modes */
#if !defined(CONFIG_MTK_FPGA)
	WRAP_WR32(CLK_CFG_7_CLR, 0x00000097);
	WRAP_WR32(CLK_CFG_7_SET, 0x00000003);
	WRAP_WR32(CLK_CFG_UPDATE, (0x1 << 28));
#endif

	/* Disable Clock Source Control By SPM */
	PWRAPLOG("=====PMICW_CLOCK_CTRL===== (Write before): %x\n", WRAP_RD32(PMICW_CLOCK_CTRL));
	WRAP_WR32(PMICW_CLOCK_CTRL, (WRAP_RD32(PMICW_CLOCK_CTRL) & ~(0x1 << 2)));
	PWRAPLOG("=====PMICW_CLOCK_CTRL===== (Write after): %x\n", WRAP_RD32(PMICW_CLOCK_CTRL));

	/* toggle PMIC_WRAP and pwrap_spictl reset */
	__pwrap_soft_reset();

	/*sys_ck cg enable, turn on clock*/
	WRAP_WR32(MODULE_SW_CG_0_CLR, 0x0000000f);
	/* turn on clock*/
	WRAP_WR32(MODULE_SW_CG_2_CLR, 0x00000100);
	PWRAPLOG("spi clk set ....\n");
}

static signed int _pwrap_init_dio_reset(unsigned int dio_en)
{
	unsigned int rdata = 0x0;

	WRAP_WR32(PMIC_WRAP_HPRIO_ARB_EN, 0x4); /* ONLY WACS2 */

	/* wait for WRAP_FSM idle */
	do {
		rdata = WRAP_RD32(PMIC_WRAP_WRAP_STA);
	} while((GET_WRAP_FSM(rdata) != 0x0) || (GET_WRAP_CH_DLE_RESTCNT(rdata) != 0x0));

	do {
		rdata = WRAP_RD32(PMIC_WRAP_WACS2_RDATA);
	} while ((GET_WACS2_FSM(rdata) != WACS_FSM_IDLE) || (GET_SYNC_IDLE2(rdata) != WACS_SYNC_IDLE));

#ifndef DUAL_PMICS
	WRAP_WR32(PMIC_WRAP_DIO_EN, 0x1);
#else
	WRAP_WR32(PMIC_WRAP_DIO_EN, 0x3);
#endif

	return 0;
}

static void _pwrap_InitStaUpd(void)
{

#ifndef DUAL_PMICS
	WRAP_WR32(PMIC_WRAP_STAUPD_GRPEN, 0xf5);
#else
	WRAP_WR32(PMIC_WRAP_STAUPD_GRPEN, 0xff);
#endif

#ifdef PMIC_WRAP_CRC_SUPPORT
	/* CRC */
#ifndef DUAL_PMICS
	pwrap_write_nochk(PMIC_DEW_CRC_EN_ADDR, 0x1);
	WRAP_WR32(PMIC_WRAP_CRC_EN, 0x1);
	WRAP_WR32(PMIC_WRAP_SIG_ADR, PMIC_DEW_CRC_VAL_ADDR);
#else
	pwrap_write_nochk(PMIC_DEW_CRC_EN_ADDR, 0x1);
	pwrap_write_nochk(EXT_DEW_CRC_EN, 0x1);
	WRAP_WR32(PMIC_WRAP_CRC_EN, 0x1);
	WRAP_WR32(PMIC_WRAP_SIG_ADR, (PMIC_EXT_DEW_CRC_VAL_ADDR << 16 | PMIC_DEW_CRC_VAL_ADDR));
#endif
#else
	/* Signature */
#ifndef DUAL_PMICS
	WRAP_WR32(PMIC_WRAP_SIG_MODE, 0x1);
	WRAP_WR32(PMIC_WRAP_SIG_ADR, PMIC_DEW_CRC_VAL_ADDR);
	WRAP_WR32(PMIC_WRAP_SIG_VALUE, 0x83);
#else
	WRAP_WR32(PMIC_WRAP_SIG_MODE, 0x3);
	WRAP_WR32(PMIC_WRAP_SIG_ADR, (PMIC_EXT_DEW_CRC_VAL_ADDR << 16) | PMIC_DEW_CRC_VAL_ADDR);
	WRAP_WR32(PMIC_WRAP_SIG_VALUE, (0x83 << 16) | 0x83);
#endif
#endif /* end of crc */

	WRAP_WR32(PMIC_WRAP_EINT_STA0_ADR, PMIC_CPU_INT_STA_ADDR);
#ifdef DUAL_PMICS
	WRAP_WR32(PMIC_WRAP_EINT_STA1_ADR, EXT_INT_STA);
#endif

	/* MD ADC Interface */
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_LATEST_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_WP_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_0_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_1_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_2_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_3_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_4_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_5_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_6_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_7_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_8_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_9_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_10_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_11_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_12_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_13_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_14_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_15_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_16_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_17_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_18_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_19_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_20_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_21_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_22_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_23_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_24_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_25_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_26_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_27_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_28_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_29_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_30_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIC_WRAP_MD_AUXADC_RDATA_31_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_MDRT_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);

	WRAP_WR32(PMIC_WRAP_INT_GPS_AUXADC_CMD_ADDR, (PMIC_AUXADC_RQST_DCXO_BY_GPS_ADDR << 16) + PMIC_AUXADC_RQST_CH7_ADDR);
	WRAP_WR32(PMIC_WRAP_INT_GPS_AUXADC_CMD, (0x0400 << 16) + 0x0080);
	WRAP_WR32(PMIC_WRAP_INT_GPS_AUXADC_RDATA_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_GPS_ADDR << 16) + PMIC_AUXADC_ADC_OUT_CH7_BY_AP_ADDR);

	WRAP_WR32(PMIC_WRAP_EXT_GPS_AUXADC_RDATA_ADDR, PMIC_AUXADC_ADC_OUT_MDRT_ADDR);

}

static void _pwrap_starve_set(void)
{
	WRAP_WR32(PMIC_WRAP_HARB_HPRIO, 0xf);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_0, 0x400);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_1, 0x402);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_2, 0x402);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_3, 0x40e);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_4, 0x402);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_5, 0x427);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_6, 0x427);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_7, 0x4a4);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_8, 0x413);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_9, 0x417);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_10, 0x417);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_11, 0x47b);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_12, 0x47b);
	WRAP_WR32(PMIC_WRAP_STARV_COUNTER_13, 0x45b);
}

static void _pwrap_enable(void)
{
#if (MTK_PLATFORM_MT6357)
	WRAP_WR32(PMIC_WRAP_HPRIO_ARB_EN, 0x3fd35);
#endif
	WRAP_WR32(PMIC_WRAP_WACS0_EN, 0x1);
	WRAP_WR32(PMIC_WRAP_WACS2_EN, 0x1);
	WRAP_WR32(PMIC_WRAP_WACS_P2P_EN, 0x1);
	WRAP_WR32(PMIC_WRAP_WACS_MD32_EN, 0x1);
	WRAP_WR32(PMIC_WRAP_STAUPD_CTRL, 0x5); /* 100us */
	WRAP_WR32(PMIC_WRAP_WDT_UNIT, 0xf);
	WRAP_WR32(PMIC_WRAP_WDT_SRC_EN_0, 0xffffffff);
	WRAP_WR32(PMIC_WRAP_WDT_SRC_EN_1, 0xffffffff);
	WRAP_WR32(PMIC_WRAP_TIMER_CTRL, 0x3);
	WRAP_WR32(PMIC_WRAP_INT0_EN, 0xffffffff);
	WRAP_WR32(PMIC_WRAP_INT1_EN, 0xffffdfff); /* disable Matching interrupt for bit 13 */
}

static signed int _pwrap_init_reg_clock_reset(unsigned int regck_sel)
{
	WRAP_WR32(PMIC_WRAP_EXT_CK_WRITE, 0x1);

#ifndef DUAL_PMICS
	/* Set Read Dummy Cycle Number (Slave Clock is 18MHz) */
	WRAP_WR32(PMIC_WRAP_RDDMY, 0x8);
	PWRAPLOG("NO_SLV_CLK_1M Set Read Dummy Cycle\n");
#else
	WRAP_WR32(PMIC_WRAP_RDDMY, 0x0808);
	PWRAPLOG("NO_SLV_CLK_1M Set Read Dummy Cycle dual_pmics\n");
#endif

	/* Config SPI Waveform according to reg clk */
	if (regck_sel == 1) { /* Slave Clock is 18MHz */
		/* wait data written into register => 4T_PMIC:
		 * CSHEXT_WRITE_START+EXT_CK+CSHEXT_WRITE_END+CSLEXT_START
		 */
		WRAP_WR32(PMIC_WRAP_CSHEXT_WRITE, 0x0);
		WRAP_WR32(PMIC_WRAP_CSHEXT_READ, 0x0);
		WRAP_WR32(PMIC_WRAP_CSLEXT_WRITE, 0x0);
		WRAP_WR32(PMIC_WRAP_CSLEXT_READ, 0x0200);
	} else { /*Safe Mode*/
		WRAP_WR32(PMIC_WRAP_CSHEXT_WRITE, 0x0f0f);
		WRAP_WR32(PMIC_WRAP_CSHEXT_READ, 0x0f0f);
		WRAP_WR32(PMIC_WRAP_CSLEXT_WRITE, 0x0f0f);
		WRAP_WR32(PMIC_WRAP_CSLEXT_READ, 0x0f0f);
	}

	return 0;
}

static unsigned int pwrap_read_test(void)
{
	unsigned int rdata = 0;
	unsigned int return_value = 0;
	/* Read Test */
	return_value = pwrap_wacs2_read(PMIC_DEW_READ_TEST_ADDR, &rdata);
	if (rdata != DEFAULT_VALUE_READ_TEST) {
		PWRAPERR("Error: r_rdata=0x%x, exp=0x5aa5,ret=0x%x\n", rdata, return_value);
		return E_PWR_READ_TEST_FAIL;
	}
	PWRAPLOG("Read Test pass,return_value=%d\n", return_value);

	return 0;
}
static unsigned int pwrap_write_test(void)
{
	unsigned int rdata = 0;
	unsigned int sub_return = 0;
	unsigned int sub_return1 = 0;

	/* Write test using WACS2 */
	PWRAPLOG("start pwrap_write\n");
	sub_return = pwrap_wacs2_write(PMIC_DEW_WRITE_TEST_ADDR, DEFAULT_VALUE_READ_TEST);
	PWRAPLOG("after pwrap_write\n");
	sub_return1 = pwrap_wacs2_read(PMIC_DEW_WRITE_TEST_ADDR, &rdata);
	if ((rdata != DEFAULT_VALUE_READ_TEST) || (sub_return != 0) || (sub_return1 != 0)) {
		PWRAPERR("Err:,w_rdata=0x%x,exp=0xa55a,sub_return=0x%x,sub_return1=0x%x\n", rdata, sub_return,
		         sub_return1);
		return E_PWR_INIT_WRITE_TEST;
	}
	PWRAPLOG("write Test pass\n");

	return 0;
}
static void pwrap_ut(unsigned int ut_test)
{
	switch (ut_test) {
		case 1:
			pwrap_write_test();
			break;
		case 2:
			pwrap_read_test();
			break;
		case 3:
#ifdef CONFIG_MTK_TINYSYS_SSPM_SUPPORT
			pwrap_wacs2_ipi(0x10010000 + 0xD8, 0xffffffff, (WRITE_CMD | WRITE_PMIC_WRAP));
			break;
#endif
		case 4:
			pwrap_write_nochk(PMIC_DEW_WRITE_TEST_ADDR, 0x1234);
			pwrap_write_nochk(PMIC_DEW_WRITE_TEST_ADDR, 0x4321);
			pwrap_write_nochk(PMIC_DEW_WRITE_TEST_ADDR, 0xF0F0);
			break;
		default:
			PWRAPLOG("default test.\n");
			break;
	}
}

/*-------------------pwrap debug---------------------*/
static inline void pwrap_dump_ap_register(void)
{
	unsigned int i = 0, offset = 0;
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
	unsigned int *reg_addr;
#else
	unsigned int reg_addr;
#endif
	unsigned int reg_value = 0;

	PWRAPERR("dump reg\n");
	for (i = 0; i <= PMIC_WRAP_REG_RANGE; i++) {
		reg_addr = (PMIC_WRAP_BASE + i * 4);
#if (PMIC_WRAP_KERNEL)
		reg_value = WRAP_RD32(((unsigned int *) (PMIC_WRAP_BASE + i * 4)));
#else
		reg_value = WRAP_RD32(reg_addr);
#endif
		PWRAPERR("addr:0x%x = 0x%x\n", reg_addr, reg_value);
	}

	for (i = 0; i <= 14; i++) {
		offset = 0xc00 + i * 4;
		reg_addr = (PMIC_WRAP_BASE + offset);
#if (PMIC_WRAP_KERNEL)
		reg_value = WRAP_RD32(((unsigned int *) (PMIC_WRAP_BASE + offset)));
#else
		reg_value = WRAP_RD32(reg_addr);
#endif
		PWRAPERR("addr:0x%x = 0x%x\n", reg_addr, reg_value);
	}
}

void pwrap_dump_all_register(void)
{
	pwrap_dump_ap_register();
}

static int is_pwrap_init_done(void)
{
	int ret = 0;

	ret = WRAP_RD32(PMIC_WRAP_INIT_DONE2);
	PWRAPLOG("is_pwrap_init_done %d\n", ret);
	if ((ret & 0x1) == 1)
		return 0;
	return -1;
}

signed int pwrap_init_lk(void)
{
	PWRAPFUC();
	if (0 == is_pwrap_init_done()) {
		PWRAPLOG("[PMIC_WRAP] pwrap_init already init, do nothing\n");
		return 0;
	}

	return 0;
}

static S32 _pwrap_init_sistrobe_reset(int dual_si_sample_settings)
{
	WRAP_WR32(PMIC_WRAP_SI_SAMPLE_CTRL, si_sample_ctrl);
	return 0;
}

static signed int _pwrap_reset_pattern(void)
{
	signed int sub_return = 0;
	struct pwrap_rc_info info;

	PWRAPLOG("pwrap_init_reset start!!!!!!!!!!!!!\n");
#if 0
	/* Set SoC SPI IO Driving Strength to 4 mA */
	WRAP_WR32(IOCFG_LM_DRV_CFG1_CLR, 0x3f);
	WRAP_WR32(IOCFG_LM_DRV_CFG1_SET, 0x9);

	/* Set SPI MI IO to Pull Down */
	WRAP_WR32(IOCFG_LM_PU_CFG0_CLR, (0x1 << 12));
	WRAP_WR32(IOCFG_LM_PD_CFG0_SET, (0x1 << 12));
#endif
	/* Backup PMIC Wrap key register before reset */
	si_sample_ctrl = WRAP_RD32(PMIC_WRAP_SI_SAMPLE_CTRL);
	info.wacs2_cmd = WRAP_RD32(PMIC_WRAP_WACS2_CMD);
	info.dcxo_en = WRAP_RD32(PMIC_WRAP_DCXO_ENABLE);
	info.dcxo_conn_adr0 = WRAP_RD32(PMIC_WRAP_DCXO_CONN_ADR0);
	info.dcxo_conn_wdata0 = WRAP_RD32(PMIC_WRAP_DCXO_CONN_WDATA0);
	info.dcxo_conn_adr1 = WRAP_RD32(PMIC_WRAP_DCXO_CONN_ADR1);
	info.dcxo_conn_wdata1 = WRAP_RD32(PMIC_WRAP_DCXO_CONN_WDATA1);
	info.dcxo_nfc_adr0 = WRAP_RD32(PMIC_WRAP_DCXO_NFC_ADR0);
	info.dcxo_nfc_wdata0 = WRAP_RD32(PMIC_WRAP_DCXO_NFC_WDATA0);
	info.dcxo_nfc_adr1 = WRAP_RD32(PMIC_WRAP_DCXO_NFC_ADR1);
	info.dcxo_nfc_wdata1 = WRAP_RD32(PMIC_WRAP_DCXO_NFC_WDATA1);
	PWRAPLOG("Backup pwrap key register ok\n");

	__pwrap_spi_clk_set();
	PWRAPLOG("__pwrap_spi_clk_set ok\n");

	/* Enable DCM */
	PWRAPLOG("No need to enable DCM\n");

	/* Reset SPISLV */
	PWRAPLOG("No need to reset SPISLV\n");

	/* Enable WRAP */
	WRAP_WR32(PMIC_WRAP_WRAP_EN, 0x1);

	/* Enable WACS2 */
	WRAP_WR32(PMIC_WRAP_WACS2_EN, 0x1);
	WRAP_WR32(PMIC_WRAP_HPRIO_ARB_EN, 0x4); /* ONLY WACS2 */

	PWRAPLOG("Enable WACS2 ok\n");

	/* SPI Waveform Configuration. 0:safe mode, 1:18MHz */
	sub_return = _pwrap_init_reg_clock_reset(1);
	if (sub_return != 0) {
		PWRAPERR("init_reg_clock fail, sub_return=%x\n", sub_return);
		return E_PWR_INIT_REG_CLOCK;
	}
	PWRAPLOG("_pwrap_init_reg_clock_reset ok\n");

	/* SPI Slave Configuration */
	PWRAPLOG("No need to init SPISLV\n");

	/* Enable DIO mode */
	sub_return = _pwrap_init_dio_reset(1);
	if (sub_return != 0) {
		PWRAPERR("init_dio fail, sub_return=%x\n", sub_return);
		return E_PWR_INIT_DIO;
	}
	PWRAPLOG("_pwrap_init_dio_reset ok\n");

	/* Input data calibration flow */
	sub_return = _pwrap_init_sistrobe_reset(0);
	if (sub_return != 0) {
		PWRAPERR("InitSiStrobe fail, sub_return=%x\n", sub_return);
		return E_PWR_INIT_SIDLY;
	}
	PWRAPLOG("_pwrap_init_sistrobe_reset ok\n");

	/* Status update function initialization
	* 1. Signature Checking using CRC (CRC 0 only)
	* 2. EINT update
	* 3. Read back Auxadc thermal data for GPS
	*/
	_pwrap_InitStaUpd();
	PWRAPLOG("_pwrap_InitStaUpd ok\n");

	/* PMIC_WRAP starvation setting */
	_pwrap_starve_set();
	PWRAPLOG("_pwrap_starve_set ok\n");

	/* PMIC_WRAP enables */
	_pwrap_enable();
	PWRAPLOG("_pwrap_enable ok\n");

	/* Initialization Done */
	WRAP_WR32(PMIC_WRAP_INIT_DONE0, 0x1);
	WRAP_WR32(PMIC_WRAP_INIT_DONE2, 0x1);
	WRAP_WR32(PMIC_WRAP_INIT_DONE_P2P, 0x1);
	WRAP_WR32(PMIC_WRAP_INIT_DONE_MD32, 0x1);

	/* restore key register after reset */
	WRAP_WR32(PMIC_WRAP_WACS2_CMD, info.wacs2_cmd);
	WRAP_WR32(PMIC_WRAP_DCXO_CONN_ADR0, info.dcxo_conn_adr0);
	WRAP_WR32(PMIC_WRAP_DCXO_CONN_WDATA0, info.dcxo_conn_wdata0);
	WRAP_WR32(PMIC_WRAP_DCXO_CONN_ADR1, info.dcxo_conn_adr1);
	WRAP_WR32(PMIC_WRAP_DCXO_CONN_WDATA1, info.dcxo_conn_wdata1);
	WRAP_WR32(PMIC_WRAP_DCXO_NFC_ADR0, info.dcxo_nfc_adr0);
	WRAP_WR32(PMIC_WRAP_DCXO_NFC_WDATA0, info.dcxo_nfc_wdata0);
	WRAP_WR32(PMIC_WRAP_DCXO_NFC_ADR1, info.dcxo_nfc_adr1);
	WRAP_WR32(PMIC_WRAP_DCXO_NFC_WDATA1, info.dcxo_nfc_wdata1);
	WRAP_WR32(PMIC_WRAP_DCXO_ENABLE, info.dcxo_en);
	PWRAPLOG("Restore pwrap key register ok\n");

	PWRAPLOG("pwrap_init_reset Done!!!!!!!!!\n");

	return 0;
}

static signed int pwrap_reset_pattern(void)
{
	/* SPI & WRAP Reset Pattern */
	unsigned int ret;

	ret = _pwrap_reset_pattern();
	if (ret != 0) {
		PWRAPERR("_pwrap_reset_pattern fail, ret=%x\n", ret);
		return E_PWR_INIT_RESET_SPI;
	}

	return 0;
}

#endif /*endif PMIC_WRAP_NO_PMIC */
