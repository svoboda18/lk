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

#ifndef _bq25896_SW_H_
#define _bq25896_SW_H_

#define bq25896_CON0      0x00
#define bq25896_CON1      0x01
#define bq25896_CON2      0x02
#define bq25896_CON3      0x03
#define bq25896_CON4      0x04
#define bq25896_CON5      0x05
#define bq25896_CON6      0x06
#define bq25896_CON7     0x07
#define bq25896_CON8     0x08
#define bq25896_CON9     0x09
#define bq25896_CONA     0x0A
#define bq25896_CONB     0x0B
#define bq25896_CONC     0x0C
#define bq25896_COND     0x0D
#define bq25896_CONE     0x0E
#define bq25896_CON12     0x12
#define bq25896_CON13     0x13




#define bq25896_REG_NUM 21
#define CON1_RESET_MASK   0x1
#define CON1_RESET_SHIFT  7






//CON0
#define CON0_EN_HIZ_MASK   0x1
#define CON0_EN_HIZ_SHIFT  7

#define CON0_EN_ILIM_MASK   0x1
#define CON0_EN_ILIM_SHIFT  6

#define CON0_IINLIM_MASK   0x3F
#define CON0_IINLIM_SHIFT  0


//CON1
#define CON1_VINDPM_OS_MASK   0x1F
#define CON1_VINDPM_OS_SHIFT  0


//CON2
#define CON2_CONV_START_MASK   0x1
#define CON2_CONV_START_SHIFT  7

#define CON2_CONV_RATE_MASK   0x1
#define CON2_CONV_RATE_SHIFT  6

#define CON2_BOOST_FREQ_MASK   0x1
#define CON2_BOOST_FREQ_SHIFT  5

#define CON2_ICO_EN_MASK   0x1
#define CON2_ICO_EN_RATE_SHIFT  4

#define CON2_FORCE_DPDM_MASK   0x1
#define CON2_FORCE_DPDM_SHIFT  1

#define CON2_AUTO_DPDM_EN_MASK   0x1
#define CON2_AUTO_DPDM_EN_SHIFT  0




//CON3
#define CON3_BAT_LOADEN_MASK   0x1
#define CON3_BAT_LOADEN_SHIFT  7

#define CON3_WD_MASK   0x1
#define CON3_WD_SHIFT  6

#define CON3_OTG_CONFIG_MASK   0x1
#define CON3_OTG_CONFIG_SHIFT  5

#define CON3_CHG_CONFIG_MASK   0x1
#define CON3_CHG_CONFIG_SHIFT  4

#define CON3_SYS_V_LIMIT_MASK   0x7
#define CON3_SYS_V_LIMIT_SHIFT  1



//CON4
#define CON4_EN_PUMPX_MASK   0x1
#define CON4_EN_PUMPX_SHIFT  7

#define CON4_ICHG_MASK   0x7F
#define CON4_ICHG_SHIFT  0

//CON5
#define CON5_IPRECHG_MASK   0xF
#define CON5_IPRECHG_SHIFT  4

#define CON5_ITERM_MASK   0xF
#define CON5_ITERM_SHIFT  0



//CON6
#define CON6_2XTMR_EN_MASK   0x3F
#define CON6_2XTMR_EN_SHIFT  2

#define CON6_BATLOWV_MASK   0x1
#define CON6_BATLOWV_SHIFT  1

#define CON6_VRECHG_MASK   0x1
#define CON6_VRECHG_SHIFT  0

//CON7

#define CON7_EN_TERM_CHG_MASK   0x1
#define CON7_EN_TERM_CHG_SHIFT  7

#define CON7_STAT_DIS_MASK   0x1
#define CON7_STAT_DIS_SHIFT  6

#define CON7_WTG_TIM_SET_MASK   0x3
#define CON7_WTG_TIM_SET_SHIFT  4

#define CON7_EN_TIM_MASK   0x1
#define CON7_EN_TIMG_SHIFT  3

#define CON7_SET_CHG_TIM_MASK   0x3
#define CON7_SET_CHG_TIM_SHIFT  1

#define CON7_JEITA_ISET_MASK   0x1
#define CON7_JEITA_ISET_SHIFT  0
//CON8
#define CON8_TREG_MASK 0x3
#define CON8_TREG_SHIFT 0

#define CON8_VCLAMP_MASK 0x7
#define CON8_VCLAMP_SHIFT 2

#define CON8_BAT_COMP_MASK 0x7
#define CON8_BAT_COMP_SHIFT 5
//CON9
#define CON9_BATFET_DLY_MASK 0x1
#define CON9_BATFET_DLY_SHIFT 3

#define CON9_BATFET_RST_EN_MASK 0x1
#define CON9_BATFET_RST_EN_SHIFT 2

#define CON9_PUMPX_UP   0x1
#define CON9_PUMPX_UP_SHIFT  1

#define CON9_PUMPX_DN   0x1
#define CON9_PUMPX_DN_SHIFT  0

//CONA
#define CONA_BOOST_VLIM_MASK 0xF
#define CONA_BOOST_VLIM_SHIFT 4

#define CONA_BOOST_ILIM_MASK 0x07
#define CONA_BOOST_ILIM_SHIFT 0


//CONB

#define CONB_VBUS_STAT_MASK   0x7
#define CONB_VBUS_STAT_SHIFT  5

#define CONB_CHRG_STAT_MASK   0x3
#define CONB_CHRG_STAT_SHIFT  3

#define CONB_PG_STAT_MASK   0x1
#define CONB_PG_STAT_SHIFT  2

#define CONB_SDP_STAT_MASK   0x1
#define CONB_SDP_STAT_SHIFT  1

#define CONB_VSYS_STAT_MASK   0x1
#define CONB_VSYS_STAT_SHIFT  0


//CONC

#define CONB_WATG_STAT_MASK   0x1
#define CONB_WATG_STAT_SHIFT  7

#define CONB_BOOST_STAT_MASK   0x1
#define CONB_BOOST_STAT_SHIFT  6

/*#define CONB_CHRG_FAULT_MASK   0x3
#define CONB_CHRG_FAULT_SHIFT  4 //already define at line 175 */

#define CONB_BAT_STAT_MASK   0x1
#define CONB_BAT_STAT_SHIFT  3

//COND
#define COND_FORCE_VINDPM_MASK 0x01
#define COND_FORCE_VINDPM_SHIFT 7

#define COND_VINDPM_MASK   0x7F
#define COND_VINDPM_SHIFT  0

//CONE
#define CONE_VBAT_MASK 0x7F
#define CONE_VBAT_SHIFT 0

//CON12

#define CONB_ICHG_STAT_MASK   0x7F
#define CONB_ICHG_STAT_SHIFT  0

//CON13
#define CONB_IDPM_STAT_MASK   0x1F
#define CONB_IDPM_STAT_SHIFT  0



/**********************************************************
  *
  *   [Extern Function]
  *
  *********************************************************/
//CON0----------------------------------------------------
extern void bq25896_set_en_hiz(kal_uint32 val);
extern void bq25896_set_en_ilim(kal_uint32 val);
void  bq25896_set_iinlim(kal_uint32 val);

//CON1----------------------------------------------------
//willcai
extern void bq25896_set_vindpm(kal_uint32 val);
//

//CON2----------------------------------------------------
extern void bq25896_ADC_start(kal_uint32 val);
extern void bq25896_set_ADC_rate(kal_uint32 val);
extern void bq25896_set_ico_en_start(kal_uint32 val);
//


//CON3----------------------------------------------------
//willcai
extern void  bq25896_wd_reset(kal_uint32 val) ;
extern void  bq25896_otg_en(kal_uint32 val);
extern void  bq25896_chg_en(kal_uint32 val);
extern void  bq25896_set_sys_min(kal_uint32 val);
//


//CON4----------------------------------------------------

// willcai
extern void bq25896_en_pumpx(kal_uint32 val);
extern void bq25896_set_ichg(kal_uint32 val);

//

//CON5----------------------------------------------------

//willcai
extern void  bq25896_set_iprechg(kal_uint32 val) ;
extern void  bq25896_set_iterml(kal_uint32 val);
//


//CON6----------------------------------------------------
//willcai
extern void bq25896_set_vreg(kal_uint32 val);
extern void bq25896_set_batlowv(kal_uint32 val);
extern void bq25896_set_vrechg(kal_uint32 val);


//con7

extern void bq25896_en_term_chg(kal_uint32 val);
extern void bq25896_en_state_dis(kal_uint32 val);
extern void bq25896_set_wd_timer(kal_uint32 val);
extern void bq25896_en_chg_timer(kal_uint32 val);

extern void bq25896_set_chg_timer(kal_uint32 val);


//con8
extern void bq25896_set_thermal_regulation(kal_uint32 val);
extern void bq25896_set_VBAT_clamp(kal_uint32 val);
extern void bq25896_set_VBAT_IR_compensation(kal_uint32 val);
//con9
void bq25896_pumpx_up(kal_uint32 val);




//---------------------------------------------------------
extern void bq25896_dump_register(void);
extern kal_uint32 bq25896_reg_config_interface (kal_uint8 RegNum, kal_uint8 val);

extern kal_uint32 bq25896_read_interface (kal_uint8 RegNum, kal_uint8 *val, kal_uint8 MASK, kal_uint8 SHIFT);
extern kal_uint32 bq25896_config_interface (kal_uint8 RegNum, kal_uint8 val, kal_uint8 MASK, kal_uint8 SHIFT);
/*
*static void hw_bc11_dump_register(void);
*static void hw_bc11_init(void);
*static U32 hw_bc11_DCD(void);
*static U32 hw_bc11_stepA1(void);
*static U32 hw_bc11_stepB1(void);
*static U32 hw_bc11_stepC1(void);
*static U32 hw_bc11_stepA2(void);
*static U32 hw_bc11_stepB2(void);
*static void hw_bc11_done(void);
*/
// CONA
extern void bq25896_set_boost_ilim(kal_uint32 val);
extern void bq25896_set_boost_vlim(kal_uint32 val);

//CONB
kal_uint32 bq25896_get_vbus_state(void );
kal_uint32 bq25896_get_chrg_state(void );
kal_uint32 bq25896_get_pg_state(void );
kal_uint32 bq25896_get_sdp_state(void );
kal_uint32 bq25896_get_vsys_state(void );
kal_uint32 bq25896_get_wdt_state(void );
kal_uint32 bq25896_get_boost_state(void );
kal_uint32 bq25896_get_chrg_fault_state(void );
kal_uint32 bq25896_get_bat_state(void );
kal_uint32 bq25896_get_ichg(void );
kal_uint32 bq25896_get_idpm_state(void );

//CON0D
extern void bq25896_set_FORCE_VINDPM(kal_uint32 val);
extern void bq25896_set_VINDPM(kal_uint32 val);



//aggregated APIs
extern void bq25896_hw_init(void);
extern void bq25896_charging_enable(kal_uint32 bEnable);
extern void bq25896_dump_register(void);
extern kal_uint32 bq25896_get_chrg_stat(void);
#endif
