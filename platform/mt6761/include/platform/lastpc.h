/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
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
#define DFD_REG_LENGTH              64
#define DFD_SW_V3_WA

#define ENABLE_RETURN_STACK

struct bit_pair {
	unsigned int raw_offset;
	unsigned int bit_offset;
	unsigned int inv;
};

struct reg_collector {
	struct bit_pair bit_pairs[DFD_REG_LENGTH];
};
struct little_core_spec {
	struct reg_collector spmc_power_state;
	struct reg_collector pc;
	struct reg_collector sp32;
	struct reg_collector fp32;
	struct reg_collector fp64;
	struct reg_collector sp_EL0;
	struct reg_collector sp_EL1;
	struct reg_collector sp_EL2;
	struct reg_collector sp_EL3;
	struct reg_collector elr_EL1;
	struct reg_collector elr_EL2;
	struct reg_collector elr_EL3;
	struct reg_collector raw_pc;
	struct reg_collector pc_iss;
	struct reg_collector full_pc_wr;
	struct reg_collector full_pc_ex1;
	struct reg_collector full_pc_ex2;
	struct reg_collector return_Stack_pointer;
	struct reg_collector return_Stack0;
	struct reg_collector return_Stack1;
	struct reg_collector return_Stack2;
	struct reg_collector return_Stack3;
	struct reg_collector return_Stack4;
	struct reg_collector return_Stack5;
	struct reg_collector return_Stack6;
	struct reg_collector return_Stack7;
};

struct big_core_spec {
	struct reg_collector edpcsr;
	struct reg_collector spmc_power_state;
	struct reg_collector i0_valid;
	struct reg_collector i0_pc;
	struct reg_collector i1_valid;
	struct reg_collector i1_pc;
	struct reg_collector last_branch;
	struct reg_collector sram_wr_ptr;
	struct reg_collector return_Stack_pointer;
	struct reg_collector return_Stack0;
	struct reg_collector return_Stack1;
	struct reg_collector return_Stack2;
	struct reg_collector return_Stack3;
	struct reg_collector return_Stack4;
	struct reg_collector return_Stack5;
	struct reg_collector return_Stack6;
	struct reg_collector return_Stack7;
};

struct power_spec {
	struct reg_collector power_state;
};
/* TODO dump l2 parity from DFD */
#if 0
struct mcusys_spec mcusys {
	struct reg_collector M0_AR_Pending_Counter;
	struct reg_collector M0_AW_Pending_Counter;
	struct reg_collector M1_AR_Pending_Counter;
	struct reg_collector M1_AW_Pending_Counter;
	struct reg_collector M2_AR_Pending_Counter;
	struct reg_collector M2_AW_Pending_Counter;
	struct reg_collector S0_AR_Pending_Counter;
	struct reg_collector S0_AW_Pending_Counter;
	struct reg_collector S1_AR_Pending_Counter;
	struct reg_collector S1_AW_Pending_Counter;
	struct reg_collector S2_AR_Pending_Counter;
	struct reg_collector S2_AW_Pending_Counter;
	struct reg_collector S3_AR_Pending_Counter;
	struct reg_collector S3_AW_Pending_Counter;
	struct reg_collector S4_AR_Pending_Counter;
	struct reg_collector S4_AW_Pending_Counter;
	struct reg_collector mp0_parity_err;
	struct reg_collector mp0_parity_index;
	struct reg_collector mp0_parity_banks;
	struct reg_collector mp0_parity_err_count;
	struct reg_collector mp1_parity_err;
	struct reg_collector mp1_parity_index;
	struct reg_collector mp1_parity_banks;
	struct reg_collector mp1_parity_err_count;
	struct reg_collector mp2_parity_err;
	struct reg_collector mp2_parity_index;
	struct reg_collector mp2_parity_banks;
	struct reg_collector mp2_parity_err_count;
};
#endif
struct power_spec spmc_power_state[] = {
	{
			.power_state = {{
			{    0, 0,0}, /* core0 power_state bit0 */
			{    0,10,0}, /* core0 power_state bit1 */
			{    0, 0,2}, /* core0 power_state bit2 */
			{    0, 0,2}, /* core0 power_state bit3 */
			{    0, 0,2}, /* core0 power_state bit4 */
			{    0, 0,2}, /* core0 power_state bit5 */
			{    0, 0,2}, /* core0 power_state bit6 */
			{    0, 0,2}, /* core0 power_state bit7 */
			{    0, 0,2}, /* core0 power_state bit8 */
			{    0, 0,2}, /* core0 power_state bit9 */
			{    0, 0,2}, /* core0 power_state bit10 */
			{    0, 0,2}, /* core0 power_state bit11 */
			{    0, 0,2}, /* core0 power_state bit12 */
			{    0, 0,2}, /* core0 power_state bit13 */
			{    0, 0,2}, /* core0 power_state bit14 */
			{    0, 0,2}, /* core0 power_state bit15 */
			{    0, 0,2}, /* core0 power_state bit16 */
			{    0, 0,2}, /* core0 power_state bit17 */
			{    0, 0,2}, /* core0 power_state bit18 */
			{    0, 0,2}, /* core0 power_state bit19 */
			{    0, 0,2}, /* core0 power_state bit20 */
			{    0, 0,2}, /* core0 power_state bit21 */
			{    0, 0,2}, /* core0 power_state bit22 */
			{    0, 0,2}, /* core0 power_state bit23 */
			{    0, 0,2}, /* core0 power_state bit24 */
			{    0, 0,2}, /* core0 power_state bit25 */
			{    0, 0,2}, /* core0 power_state bit26 */
			{    0, 0,2}, /* core0 power_state bit27 */
			{    0, 0,2}, /* core0 power_state bit28 */
			{    0, 0,2}, /* core0 power_state bit29 */
			{    0, 0,2}, /* core0 power_state bit30 */
			{    0, 0,2}, /* core0 power_state bit31 */
			{    0, 0,2}, /* core0 power_state bit32 */
			{    0, 0,2}, /* core0 power_state bit33 */
			{    0, 0,2}, /* core0 power_state bit34 */
			{    0, 0,2}, /* core0 power_state bit35 */
			{    0, 0,2}, /* core0 power_state bit36 */
			{    0, 0,2}, /* core0 power_state bit37 */
			{    0, 0,2}, /* core0 power_state bit38 */
			{    0, 0,2}, /* core0 power_state bit39 */
			{    0, 0,2}, /* core0 power_state bit40 */
			{    0, 0,2}, /* core0 power_state bit41 */
			{    0, 0,2}, /* core0 power_state bit42 */
			{    0, 0,2}, /* core0 power_state bit43 */
			{    0, 0,2}, /* core0 power_state bit44 */
			{    0, 0,2}, /* core0 power_state bit45 */
			{    0, 0,2}, /* core0 power_state bit46 */
			{    0, 0,2}, /* core0 power_state bit47 */
			{    0, 0,2}, /* core0 power_state bit48 */
			{    0, 0,2}, /* core0 power_state bit49 */
			{    0, 0,2}, /* core0 power_state bit50 */
			{    0, 0,2}, /* core0 power_state bit51 */
			{    0, 0,2}, /* core0 power_state bit52 */
			{    0, 0,2}, /* core0 power_state bit53 */
			{    0, 0,2}, /* core0 power_state bit54 */
			{    0, 0,2}, /* core0 power_state bit55 */
			{    0, 0,2}, /* core0 power_state bit56 */
			{    0, 0,2}, /* core0 power_state bit57 */
			{    0, 0,2}, /* core0 power_state bit58 */
			{    0, 0,2}, /* core0 power_state bit59 */
			{    0, 0,2}, /* core0 power_state bit60 */
			{    0, 0,2}, /* core0 power_state bit61 */
			{    0, 0,2}, /* core0 power_state bit62 */
			{    0, 0,2}, /* core0 power_state bit63 */
			}},
	},
	{	/* core 1 */
			.power_state = {{
			{    0, 1,0}, /* core1 power_state bit0 */
			{    0,11,0}, /* core1 power_state bit1 */
			{    0, 0,2}, /* core1 power_state bit2 */
			{    0, 0,2}, /* core1 power_state bit3 */
			{    0, 0,2}, /* core1 power_state bit4 */
			{    0, 0,2}, /* core1 power_state bit5 */
			{    0, 0,2}, /* core1 power_state bit6 */
			{    0, 0,2}, /* core1 power_state bit7 */
			{    0, 0,2}, /* core1 power_state bit8 */
			{    0, 0,2}, /* core1 power_state bit9 */
			{    0, 0,2}, /* core1 power_state bit10 */
			{    0, 0,2}, /* core1 power_state bit11 */
			{    0, 0,2}, /* core1 power_state bit12 */
			{    0, 0,2}, /* core1 power_state bit13 */
			{    0, 0,2}, /* core1 power_state bit14 */
			{    0, 0,2}, /* core1 power_state bit15 */
			{    0, 0,2}, /* core1 power_state bit16 */
			{    0, 0,2}, /* core1 power_state bit17 */
			{    0, 0,2}, /* core1 power_state bit18 */
			{    0, 0,2}, /* core1 power_state bit19 */
			{    0, 0,2}, /* core1 power_state bit20 */
			{    0, 0,2}, /* core1 power_state bit21 */
			{    0, 0,2}, /* core1 power_state bit22 */
			{    0, 0,2}, /* core1 power_state bit23 */
			{    0, 0,2}, /* core1 power_state bit24 */
			{    0, 0,2}, /* core1 power_state bit25 */
			{    0, 0,2}, /* core1 power_state bit26 */
			{    0, 0,2}, /* core1 power_state bit27 */
			{    0, 0,2}, /* core1 power_state bit28 */
			{    0, 0,2}, /* core1 power_state bit29 */
			{    0, 0,2}, /* core1 power_state bit30 */
			{    0, 0,2}, /* core1 power_state bit31 */
			{    0, 0,2}, /* core1 power_state bit32 */
			{    0, 0,2}, /* core1 power_state bit33 */
			{    0, 0,2}, /* core1 power_state bit34 */
			{    0, 0,2}, /* core1 power_state bit35 */
			{    0, 0,2}, /* core1 power_state bit36 */
			{    0, 0,2}, /* core1 power_state bit37 */
			{    0, 0,2}, /* core1 power_state bit38 */
			{    0, 0,2}, /* core1 power_state bit39 */
			{    0, 0,2}, /* core1 power_state bit40 */
			{    0, 0,2}, /* core1 power_state bit41 */
			{    0, 0,2}, /* core1 power_state bit42 */
			{    0, 0,2}, /* core1 power_state bit43 */
			{    0, 0,2}, /* core1 power_state bit44 */
			{    0, 0,2}, /* core1 power_state bit45 */
			{    0, 0,2}, /* core1 power_state bit46 */
			{    0, 0,2}, /* core1 power_state bit47 */
			{    0, 0,2}, /* core1 power_state bit48 */
			{    0, 0,2}, /* core1 power_state bit49 */
			{    0, 0,2}, /* core1 power_state bit50 */
			{    0, 0,2}, /* core1 power_state bit51 */
			{    0, 0,2}, /* core1 power_state bit52 */
			{    0, 0,2}, /* core1 power_state bit53 */
			{    0, 0,2}, /* core1 power_state bit54 */
			{    0, 0,2}, /* core1 power_state bit55 */
			{    0, 0,2}, /* core1 power_state bit56 */
			{    0, 0,2}, /* core1 power_state bit57 */
			{    0, 0,2}, /* core1 power_state bit58 */
			{    0, 0,2}, /* core1 power_state bit59 */
			{    0, 0,2}, /* core1 power_state bit60 */
			{    0, 0,2}, /* core1 power_state bit61 */
			{    0, 0,2}, /* core1 power_state bit62 */
			{    0, 0,2}, /* core1 power_state bit63 */
			}},
	},
	{	/* core 2 */
			.power_state = {{
			{    0, 2,0}, /* core2 power_state bit0 */
			{    0,12,0}, /* core2 power_state bit1 */
			{    0, 0,2}, /* core2 power_state bit2 */
			{    0, 0,2}, /* core2 power_state bit3 */
			{    0, 0,2}, /* core2 power_state bit4 */
			{    0, 0,2}, /* core2 power_state bit5 */
			{    0, 0,2}, /* core2 power_state bit6 */
			{    0, 0,2}, /* core2 power_state bit7 */
			{    0, 0,2}, /* core2 power_state bit8 */
			{    0, 0,2}, /* core2 power_state bit9 */
			{    0, 0,2}, /* core2 power_state bit10 */
			{    0, 0,2}, /* core2 power_state bit11 */
			{    0, 0,2}, /* core2 power_state bit12 */
			{    0, 0,2}, /* core2 power_state bit13 */
			{    0, 0,2}, /* core2 power_state bit14 */
			{    0, 0,2}, /* core2 power_state bit15 */
			{    0, 0,2}, /* core2 power_state bit16 */
			{    0, 0,2}, /* core2 power_state bit17 */
			{    0, 0,2}, /* core2 power_state bit18 */
			{    0, 0,2}, /* core2 power_state bit19 */
			{    0, 0,2}, /* core2 power_state bit20 */
			{    0, 0,2}, /* core2 power_state bit21 */
			{    0, 0,2}, /* core2 power_state bit22 */
			{    0, 0,2}, /* core2 power_state bit23 */
			{    0, 0,2}, /* core2 power_state bit24 */
			{    0, 0,2}, /* core2 power_state bit25 */
			{    0, 0,2}, /* core2 power_state bit26 */
			{    0, 0,2}, /* core2 power_state bit27 */
			{    0, 0,2}, /* core2 power_state bit28 */
			{    0, 0,2}, /* core2 power_state bit29 */
			{    0, 0,2}, /* core2 power_state bit30 */
			{    0, 0,2}, /* core2 power_state bit31 */
			{    0, 0,2}, /* core2 power_state bit32 */
			{    0, 0,2}, /* core2 power_state bit33 */
			{    0, 0,2}, /* core2 power_state bit34 */
			{    0, 0,2}, /* core2 power_state bit35 */
			{    0, 0,2}, /* core2 power_state bit36 */
			{    0, 0,2}, /* core2 power_state bit37 */
			{    0, 0,2}, /* core2 power_state bit38 */
			{    0, 0,2}, /* core2 power_state bit39 */
			{    0, 0,2}, /* core2 power_state bit40 */
			{    0, 0,2}, /* core2 power_state bit41 */
			{    0, 0,2}, /* core2 power_state bit42 */
			{    0, 0,2}, /* core2 power_state bit43 */
			{    0, 0,2}, /* core2 power_state bit44 */
			{    0, 0,2}, /* core2 power_state bit45 */
			{    0, 0,2}, /* core2 power_state bit46 */
			{    0, 0,2}, /* core2 power_state bit47 */
			{    0, 0,2}, /* core2 power_state bit48 */
			{    0, 0,2}, /* core2 power_state bit49 */
			{    0, 0,2}, /* core2 power_state bit50 */
			{    0, 0,2}, /* core2 power_state bit51 */
			{    0, 0,2}, /* core2 power_state bit52 */
			{    0, 0,2}, /* core2 power_state bit53 */
			{    0, 0,2}, /* core2 power_state bit54 */
			{    0, 0,2}, /* core2 power_state bit55 */
			{    0, 0,2}, /* core2 power_state bit56 */
			{    0, 0,2}, /* core2 power_state bit57 */
			{    0, 0,2}, /* core2 power_state bit58 */
			{    0, 0,2}, /* core2 power_state bit59 */
			{    0, 0,2}, /* core2 power_state bit60 */
			{    0, 0,2}, /* core2 power_state bit61 */
			{    0, 0,2}, /* core2 power_state bit62 */
			{    0, 0,2}, /* core2 power_state bit63 */
			}},
	},
	{	/* core 3 */
			.power_state = {{
			{    0, 3,0}, /* core3 power_state bit0 */
			{    0,13,0}, /* core3 power_state bit1 */
			{    0, 0,2}, /* core3 power_state bit2 */
			{    0, 0,2}, /* core3 power_state bit3 */
			{    0, 0,2}, /* core3 power_state bit4 */
			{    0, 0,2}, /* core3 power_state bit5 */
			{    0, 0,2}, /* core3 power_state bit6 */
			{    0, 0,2}, /* core3 power_state bit7 */
			{    0, 0,2}, /* core3 power_state bit8 */
			{    0, 0,2}, /* core3 power_state bit9 */
			{    0, 0,2}, /* core3 power_state bit10 */
			{    0, 0,2}, /* core3 power_state bit11 */
			{    0, 0,2}, /* core3 power_state bit12 */
			{    0, 0,2}, /* core3 power_state bit13 */
			{    0, 0,2}, /* core3 power_state bit14 */
			{    0, 0,2}, /* core3 power_state bit15 */
			{    0, 0,2}, /* core3 power_state bit16 */
			{    0, 0,2}, /* core3 power_state bit17 */
			{    0, 0,2}, /* core3 power_state bit18 */
			{    0, 0,2}, /* core3 power_state bit19 */
			{    0, 0,2}, /* core3 power_state bit20 */
			{    0, 0,2}, /* core3 power_state bit21 */
			{    0, 0,2}, /* core3 power_state bit22 */
			{    0, 0,2}, /* core3 power_state bit23 */
			{    0, 0,2}, /* core3 power_state bit24 */
			{    0, 0,2}, /* core3 power_state bit25 */
			{    0, 0,2}, /* core3 power_state bit26 */
			{    0, 0,2}, /* core3 power_state bit27 */
			{    0, 0,2}, /* core3 power_state bit28 */
			{    0, 0,2}, /* core3 power_state bit29 */
			{    0, 0,2}, /* core3 power_state bit30 */
			{    0, 0,2}, /* core3 power_state bit31 */
			{    0, 0,2}, /* core3 power_state bit32 */
			{    0, 0,2}, /* core3 power_state bit33 */
			{    0, 0,2}, /* core3 power_state bit34 */
			{    0, 0,2}, /* core3 power_state bit35 */
			{    0, 0,2}, /* core3 power_state bit36 */
			{    0, 0,2}, /* core3 power_state bit37 */
			{    0, 0,2}, /* core3 power_state bit38 */
			{    0, 0,2}, /* core3 power_state bit39 */
			{    0, 0,2}, /* core3 power_state bit40 */
			{    0, 0,2}, /* core3 power_state bit41 */
			{    0, 0,2}, /* core3 power_state bit42 */
			{    0, 0,2}, /* core3 power_state bit43 */
			{    0, 0,2}, /* core3 power_state bit44 */
			{    0, 0,2}, /* core3 power_state bit45 */
			{    0, 0,2}, /* core3 power_state bit46 */
			{    0, 0,2}, /* core3 power_state bit47 */
			{    0, 0,2}, /* core3 power_state bit48 */
			{    0, 0,2}, /* core3 power_state bit49 */
			{    0, 0,2}, /* core3 power_state bit50 */
			{    0, 0,2}, /* core3 power_state bit51 */
			{    0, 0,2}, /* core3 power_state bit52 */
			{    0, 0,2}, /* core3 power_state bit53 */
			{    0, 0,2}, /* core3 power_state bit54 */
			{    0, 0,2}, /* core3 power_state bit55 */
			{    0, 0,2}, /* core3 power_state bit56 */
			{    0, 0,2}, /* core3 power_state bit57 */
			{    0, 0,2}, /* core3 power_state bit58 */
			{    0, 0,2}, /* core3 power_state bit59 */
			{    0, 0,2}, /* core3 power_state bit60 */
			{    0, 0,2}, /* core3 power_state bit61 */
			{    0, 0,2}, /* core3 power_state bit62 */
			{    0, 0,2}, /* core3 power_state bit63 */
			}},
	},
};
/* TODO dump CCI pending drom DFD */
#if 0
struct mcusys_spec mcusys[] = {
	{		/* core 0 */ 
			.M0_AR_Pending_Counter = {{
			{ 2191,19,0}, /* core0 M0_AR_Pending_Counter bit0 */
			{ 2190,19,0}, /* core0 M0_AR_Pending_Counter bit1 */
			{  355,19,0}, /* core0 M0_AR_Pending_Counter bit2 */
			{  354,19,0}, /* core0 M0_AR_Pending_Counter bit3 */
			{ 2017,19,0}, /* core0 M0_AR_Pending_Counter bit4 */
			{ 2016,19,0}, /* core0 M0_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit63 */
			}},
			.M2_AR_Pending_Counter = {{
			{ 2031,19,0}, /* core0 M2_AR_Pending_Counter bit0 */
			{ 2030,19,0}, /* core0 M2_AR_Pending_Counter bit1 */
			{ 2029,19,0}, /* core0 M2_AR_Pending_Counter bit2 */
			{ 2028,19,0}, /* core0 M2_AR_Pending_Counter bit3 */
			{ 2027,19,0}, /* core0 M2_AR_Pending_Counter bit4 */
			{ 2026,19,0}, /* core0 M2_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit63 */
			}},
			.M0_AW_Pending_Counter = {{
			{ 2019,19,0}, /* core0 M0_AW_Pending_Counter bit0 */
			{ 2018,19,0}, /* core0 M0_AW_Pending_Counter bit1 */
			{ 2021,19,0}, /* core0 M0_AW_Pending_Counter bit2 */
			{ 2020,19,0}, /* core0 M0_AW_Pending_Counter bit3 */
			{ 2023,19,0}, /* core0 M0_AW_Pending_Counter bit4 */
			{ 2022,19,0}, /* core0 M0_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit63 */
			}},
			.M2_AW_Pending_Counter = {{
			{ 2047,19,0}, /* core0 M2_AW_Pending_Counter bit0 */
			{ 2046,19,0}, /* core0 M2_AW_Pending_Counter bit1 */
			{ 2045,19,0}, /* core0 M2_AW_Pending_Counter bit2 */
			{ 2044,19,0}, /* core0 M2_AW_Pending_Counter bit3 */
			{ 2043,19,0}, /* core0 M2_AW_Pending_Counter bit4 */
			{ 2042,19,0}, /* core0 M2_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit63 */
			}},
			.S4_AR_Pending_Counter = {{
			{ 2641,19,0}, /* core0 S4_AR_Pending_Counter bit0 */
			{ 2640,19,0}, /* core0 S4_AR_Pending_Counter bit1 */
			{ 1745,14,0}, /* core0 S4_AR_Pending_Counter bit2 */
			{ 1744,14,0}, /* core0 S4_AR_Pending_Counter bit3 */
			{ 1743,14,0}, /* core0 S4_AR_Pending_Counter bit4 */
			{ 1742,14,0}, /* core0 S4_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit63 */
			}},
			.S4_AW_Pending_Counter = {{
			{ 2639,19,0}, /* core0 S4_AW_Pending_Counter bit0 */
			{ 2638,19,0}, /* core0 S4_AW_Pending_Counter bit1 */
			{ 2637,19,0}, /* core0 S4_AW_Pending_Counter bit2 */
			{ 2636,19,0}, /* core0 S4_AW_Pending_Counter bit3 */
			{ 2635,19,0}, /* core0 S4_AW_Pending_Counter bit4 */
			{ 2634,19,0}, /* core0 S4_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit63 */
			}},
			.S4_AC_Pending_Counter = {{
			{   34,18,0}, /* core0 S4_AC_Pending_Counter bit0 */
			{   37,18,0}, /* core0 S4_AC_Pending_Counter bit1 */
			{ 1746,14,0}, /* core0 S4_AC_Pending_Counter bit2 */
			{   36,18,0}, /* core0 S4_AC_Pending_Counter bit3 */
			{   35,18,0}, /* core0 S4_AC_Pending_Counter bit4 */
			{   33,18,0}, /* core0 S4_AC_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S4_AC_Pending_Counter bit63 */
			}},
			.mp0_parity_err = {{
			{ 1678,13,0}, /* core0 mp0_parity_err bit0 */
			{    0, 0,2}, /* core0 mp0_parity_err bit1 */
			{    0, 0,2}, /* core0 mp0_parity_err bit2 */
			{    0, 0,2}, /* core0 mp0_parity_err bit3 */
			{    0, 0,2}, /* core0 mp0_parity_err bit4 */
			{    0, 0,2}, /* core0 mp0_parity_err bit5 */
			{    0, 0,2}, /* core0 mp0_parity_err bit6 */
			{    0, 0,2}, /* core0 mp0_parity_err bit7 */
			{    0, 0,2}, /* core0 mp0_parity_err bit8 */
			{    0, 0,2}, /* core0 mp0_parity_err bit9 */
			{    0, 0,2}, /* core0 mp0_parity_err bit10 */
			{    0, 0,2}, /* core0 mp0_parity_err bit11 */
			{    0, 0,2}, /* core0 mp0_parity_err bit12 */
			{    0, 0,2}, /* core0 mp0_parity_err bit13 */
			{    0, 0,2}, /* core0 mp0_parity_err bit14 */
			{    0, 0,2}, /* core0 mp0_parity_err bit15 */
			{    0, 0,2}, /* core0 mp0_parity_err bit16 */
			{    0, 0,2}, /* core0 mp0_parity_err bit17 */
			{    0, 0,2}, /* core0 mp0_parity_err bit18 */
			{    0, 0,2}, /* core0 mp0_parity_err bit19 */
			{    0, 0,2}, /* core0 mp0_parity_err bit20 */
			{    0, 0,2}, /* core0 mp0_parity_err bit21 */
			{    0, 0,2}, /* core0 mp0_parity_err bit22 */
			{    0, 0,2}, /* core0 mp0_parity_err bit23 */
			{    0, 0,2}, /* core0 mp0_parity_err bit24 */
			{    0, 0,2}, /* core0 mp0_parity_err bit25 */
			{    0, 0,2}, /* core0 mp0_parity_err bit26 */
			{    0, 0,2}, /* core0 mp0_parity_err bit27 */
			{    0, 0,2}, /* core0 mp0_parity_err bit28 */
			{    0, 0,2}, /* core0 mp0_parity_err bit29 */
			{    0, 0,2}, /* core0 mp0_parity_err bit30 */
			{    0, 0,2}, /* core0 mp0_parity_err bit31 */
			{    0, 0,2}, /* core0 mp0_parity_err bit32 */
			{    0, 0,2}, /* core0 mp0_parity_err bit33 */
			{    0, 0,2}, /* core0 mp0_parity_err bit34 */
			{    0, 0,2}, /* core0 mp0_parity_err bit35 */
			{    0, 0,2}, /* core0 mp0_parity_err bit36 */
			{    0, 0,2}, /* core0 mp0_parity_err bit37 */
			{    0, 0,2}, /* core0 mp0_parity_err bit38 */
			{    0, 0,2}, /* core0 mp0_parity_err bit39 */
			{    0, 0,2}, /* core0 mp0_parity_err bit40 */
			{    0, 0,2}, /* core0 mp0_parity_err bit41 */
			{    0, 0,2}, /* core0 mp0_parity_err bit42 */
			{    0, 0,2}, /* core0 mp0_parity_err bit43 */
			{    0, 0,2}, /* core0 mp0_parity_err bit44 */
			{    0, 0,2}, /* core0 mp0_parity_err bit45 */
			{    0, 0,2}, /* core0 mp0_parity_err bit46 */
			{    0, 0,2}, /* core0 mp0_parity_err bit47 */
			{    0, 0,2}, /* core0 mp0_parity_err bit48 */
			{    0, 0,2}, /* core0 mp0_parity_err bit49 */
			{    0, 0,2}, /* core0 mp0_parity_err bit50 */
			{    0, 0,2}, /* core0 mp0_parity_err bit51 */
			{    0, 0,2}, /* core0 mp0_parity_err bit52 */
			{    0, 0,2}, /* core0 mp0_parity_err bit53 */
			{    0, 0,2}, /* core0 mp0_parity_err bit54 */
			{    0, 0,2}, /* core0 mp0_parity_err bit55 */
			{    0, 0,2}, /* core0 mp0_parity_err bit56 */
			{    0, 0,2}, /* core0 mp0_parity_err bit57 */
			{    0, 0,2}, /* core0 mp0_parity_err bit58 */
			{    0, 0,2}, /* core0 mp0_parity_err bit59 */
			{    0, 0,2}, /* core0 mp0_parity_err bit60 */
			{    0, 0,2}, /* core0 mp0_parity_err bit61 */
			{    0, 0,2}, /* core0 mp0_parity_err bit62 */
			{    0, 0,2}, /* core0 mp0_parity_err bit63 */
			}},
			.mp0_parity_index = {{
			{ 2730,13,0}, /* core0 mp0_parity_index bit0 */
			{ 2727,13,0}, /* core0 mp0_parity_index bit1 */
			{ 2738,13,0}, /* core0 mp0_parity_index bit2 */
			{ 1677,13,0}, /* core0 mp0_parity_index bit3 */
			{ 1818,13,0}, /* core0 mp0_parity_index bit4 */
			{ 1676,13,0}, /* core0 mp0_parity_index bit5 */
			{ 1815,13,0}, /* core0 mp0_parity_index bit6 */
			{ 1675,13,0}, /* core0 mp0_parity_index bit7 */
			{ 1816,13,0}, /* core0 mp0_parity_index bit8 */
			{ 1817,13,0}, /* core0 mp0_parity_index bit9 */
			{ 2735,13,0}, /* core0 mp0_parity_index bit10 */
			{ 2731,13,0}, /* core0 mp0_parity_index bit11 */
			{ 2722,13,0}, /* core0 mp0_parity_index bit12 */
			{ 2732,13,0}, /* core0 mp0_parity_index bit13 */
			{ 2741,13,0}, /* core0 mp0_parity_index bit14 */
			{    0, 0,2}, /* core0 mp0_parity_index bit15 */
			{    0, 0,2}, /* core0 mp0_parity_index bit16 */
			{    0, 0,2}, /* core0 mp0_parity_index bit17 */
			{    0, 0,2}, /* core0 mp0_parity_index bit18 */
			{    0, 0,2}, /* core0 mp0_parity_index bit19 */
			{    0, 0,2}, /* core0 mp0_parity_index bit20 */
			{    0, 0,2}, /* core0 mp0_parity_index bit21 */
			{    0, 0,2}, /* core0 mp0_parity_index bit22 */
			{    0, 0,2}, /* core0 mp0_parity_index bit23 */
			{    0, 0,2}, /* core0 mp0_parity_index bit24 */
			{    0, 0,2}, /* core0 mp0_parity_index bit25 */
			{    0, 0,2}, /* core0 mp0_parity_index bit26 */
			{    0, 0,2}, /* core0 mp0_parity_index bit27 */
			{    0, 0,2}, /* core0 mp0_parity_index bit28 */
			{    0, 0,2}, /* core0 mp0_parity_index bit29 */
			{    0, 0,2}, /* core0 mp0_parity_index bit30 */
			{    0, 0,2}, /* core0 mp0_parity_index bit31 */
			{    0, 0,2}, /* core0 mp0_parity_index bit32 */
			{    0, 0,2}, /* core0 mp0_parity_index bit33 */
			{    0, 0,2}, /* core0 mp0_parity_index bit34 */
			{    0, 0,2}, /* core0 mp0_parity_index bit35 */
			{    0, 0,2}, /* core0 mp0_parity_index bit36 */
			{    0, 0,2}, /* core0 mp0_parity_index bit37 */
			{    0, 0,2}, /* core0 mp0_parity_index bit38 */
			{    0, 0,2}, /* core0 mp0_parity_index bit39 */
			{    0, 0,2}, /* core0 mp0_parity_index bit40 */
			{    0, 0,2}, /* core0 mp0_parity_index bit41 */
			{    0, 0,2}, /* core0 mp0_parity_index bit42 */
			{    0, 0,2}, /* core0 mp0_parity_index bit43 */
			{    0, 0,2}, /* core0 mp0_parity_index bit44 */
			{    0, 0,2}, /* core0 mp0_parity_index bit45 */
			{    0, 0,2}, /* core0 mp0_parity_index bit46 */
			{    0, 0,2}, /* core0 mp0_parity_index bit47 */
			{    0, 0,2}, /* core0 mp0_parity_index bit48 */
			{    0, 0,2}, /* core0 mp0_parity_index bit49 */
			{    0, 0,2}, /* core0 mp0_parity_index bit50 */
			{    0, 0,2}, /* core0 mp0_parity_index bit51 */
			{    0, 0,2}, /* core0 mp0_parity_index bit52 */
			{    0, 0,2}, /* core0 mp0_parity_index bit53 */
			{    0, 0,2}, /* core0 mp0_parity_index bit54 */
			{    0, 0,2}, /* core0 mp0_parity_index bit55 */
			{    0, 0,2}, /* core0 mp0_parity_index bit56 */
			{    0, 0,2}, /* core0 mp0_parity_index bit57 */
			{    0, 0,2}, /* core0 mp0_parity_index bit58 */
			{    0, 0,2}, /* core0 mp0_parity_index bit59 */
			{    0, 0,2}, /* core0 mp0_parity_index bit60 */
			{    0, 0,2}, /* core0 mp0_parity_index bit61 */
			{    0, 0,2}, /* core0 mp0_parity_index bit62 */
			{    0, 0,2}, /* core0 mp0_parity_index bit63 */
			}},
			.mp0_parity_banks = {{
			{ 2734,13,0}, /* core0 mp0_parity_banks bit0 */
			{ 2736,13,0}, /* core0 mp0_parity_banks bit1 */
			{ 2740,13,0}, /* core0 mp0_parity_banks bit2 */
			{ 2742,13,0}, /* core0 mp0_parity_banks bit3 */
			{ 2739,13,0}, /* core0 mp0_parity_banks bit4 */
			{ 2729,13,0}, /* core0 mp0_parity_banks bit5 */
			{ 2744,13,0}, /* core0 mp0_parity_banks bit6 */
			{ 2745,13,0}, /* core0 mp0_parity_banks bit7 */
			{ 2743,13,0}, /* core0 mp0_parity_banks bit8 */
			{ 2724,13,0}, /* core0 mp0_parity_banks bit9 */
			{ 2728,13,0}, /* core0 mp0_parity_banks bit10 */
			{ 2723,13,0}, /* core0 mp0_parity_banks bit11 */
			{ 2721,13,0}, /* core0 mp0_parity_banks bit12 */
			{ 2737,13,0}, /* core0 mp0_parity_banks bit13 */
			{ 2726,13,0}, /* core0 mp0_parity_banks bit14 */
			{ 2725,13,0}, /* core0 mp0_parity_banks bit15 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit16 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit17 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit18 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit19 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit20 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit21 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit22 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit23 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit24 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit25 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit26 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit27 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit28 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit29 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit30 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit31 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit32 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit33 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit34 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit35 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit36 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit37 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit38 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit39 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit40 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit41 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit42 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit43 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit44 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit45 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit46 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit47 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit48 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit49 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit50 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit51 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit52 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit53 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit54 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit55 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit56 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit57 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit58 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit59 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit60 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit61 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit62 */
			{    0, 0,2}, /* core0 mp0_parity_banks bit63 */
			}},
			.mp0_parity_err_count = {{
			{ 2718,13,0}, /* core0 mp0_parity_err_count bit0 */
			{ 2719,13,0}, /* core0 mp0_parity_err_count bit1 */
			{ 2720,13,0}, /* core0 mp0_parity_err_count bit2 */
			{ 2715,13,0}, /* core0 mp0_parity_err_count bit3 */
			{ 2714,13,0}, /* core0 mp0_parity_err_count bit4 */
			{ 2717,13,0}, /* core0 mp0_parity_err_count bit5 */
			{ 2746,13,0}, /* core0 mp0_parity_err_count bit6 */
			{ 2716,13,0}, /* core0 mp0_parity_err_count bit7 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit8 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit9 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit10 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit11 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit12 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit13 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit14 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit15 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit16 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit17 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit18 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit19 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit20 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit21 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit22 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit23 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit24 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit25 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit26 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit27 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit28 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit29 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit30 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit31 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit32 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit33 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit34 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit35 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit36 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit37 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit38 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit39 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit40 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit41 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit42 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit43 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit44 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit45 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit46 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit47 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit48 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit49 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit50 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit51 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit52 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit53 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit54 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit55 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit56 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit57 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit58 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit59 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit60 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit61 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit62 */
			{    0, 0,2}, /* core0 mp0_parity_err_count bit63 */
			}},
	},
}; 
#endif
struct little_core_spec little_core[] = {
	{		/* core 0 */
			.pc = {{
			{   37, 0,0}, /* core0 pc bit0 */
			{  105, 0,0}, /* core0 pc bit1 */
			{   28, 0,0}, /* core0 pc bit2 */
			{   67, 0,0}, /* core0 pc bit3 */
			{   66, 0,0}, /* core0 pc bit4 */
			{   65, 0,0}, /* core0 pc bit5 */
			{  104, 0,0}, /* core0 pc bit6 */
			{   34, 0,0}, /* core0 pc bit7 */
			{   33, 0,0}, /* core0 pc bit8 */
			{   32, 0,0}, /* core0 pc bit9 */
			{   55, 0,0}, /* core0 pc bit10 */
			{   54, 0,0}, /* core0 pc bit11 */
			{   53, 0,0}, /* core0 pc bit12 */
			{   52, 0,0}, /* core0 pc bit13 */
			{   36, 0,0}, /* core0 pc bit14 */
			{   51, 0,0}, /* core0 pc bit15 */
			{   50, 0,0}, /* core0 pc bit16 */
			{   49, 0,0}, /* core0 pc bit17 */
			{   48, 0,0}, /* core0 pc bit18 */
			{ 2483, 0,0}, /* core0 pc bit19 */
			{   64, 0,0}, /* core0 pc bit20 */
			{   43, 0,0}, /* core0 pc bit21 */
			{   42, 0,0}, /* core0 pc bit22 */
			{   41, 0,0}, /* core0 pc bit23 */
			{   40, 0,0}, /* core0 pc bit24 */
			{   47, 0,0}, /* core0 pc bit25 */
			{   46, 0,0}, /* core0 pc bit26 */
			{   45, 0,0}, /* core0 pc bit27 */
			{   44, 0,0}, /* core0 pc bit28 */
			{ 2479, 0,0}, /* core0 pc bit29 */
			{ 2478, 0,0}, /* core0 pc bit30 */
			{  119, 0,0}, /* core0 pc bit31 */
			{12041, 0,0}, /* core0 pc bit32 */
			{12040, 0,0}, /* core0 pc bit33 */
			{12039, 0,0}, /* core0 pc bit34 */
			{12038, 0,0}, /* core0 pc bit35 */
			{10951, 0,0}, /* core0 pc bit36 */
			{10950, 0,0}, /* core0 pc bit37 */
			{10949, 0,0}, /* core0 pc bit38 */
			{10948, 0,0}, /* core0 pc bit39 */
			{  146, 0,0}, /* core0 pc bit40 */
			{12113, 0,0}, /* core0 pc bit41 */
			{10955, 0,0}, /* core0 pc bit42 */
			{  145, 0,0}, /* core0 pc bit43 */
			{10954, 0,0}, /* core0 pc bit44 */
			{10953, 0,0}, /* core0 pc bit45 */
			{10952, 0,0}, /* core0 pc bit46 */
			{12105, 0,0}, /* core0 pc bit47 */
			{  144, 0,0}, /* core0 pc bit48 */
			{12104, 0,0}, /* core0 pc bit49 */
			{12103, 0,0}, /* core0 pc bit50 */
			{12112, 0,0}, /* core0 pc bit51 */
			{12111, 0,0}, /* core0 pc bit52 */
			{12102, 0,0}, /* core0 pc bit53 */
			{12109, 0,0}, /* core0 pc bit54 */
			{12108, 0,0}, /* core0 pc bit55 */
			{12107, 0,0}, /* core0 pc bit56 */
			{12106, 0,0}, /* core0 pc bit57 */
			{10959, 0,0}, /* core0 pc bit58 */
			{10958, 0,0}, /* core0 pc bit59 */
			{12110, 0,0}, /* core0 pc bit60 */
			{10957, 0,0}, /* core0 pc bit61 */
			{10956, 0,0}, /* core0 pc bit62 */
			{ 2717, 0,0}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{  221, 1,0}, /* core0 sp32 bit0 */
			{  191, 1,0}, /* core0 sp32 bit1 */
			{  117, 1,0}, /* core0 sp32 bit2 */
			{  113, 1,0}, /* core0 sp32 bit3 */
			{  111, 1,0}, /* core0 sp32 bit4 */
			{   71, 1,0}, /* core0 sp32 bit5 */
			{  123, 1,0}, /* core0 sp32 bit6 */
			{  114, 1,0}, /* core0 sp32 bit7 */
			{  119, 1,0}, /* core0 sp32 bit8 */
			{  107, 1,0}, /* core0 sp32 bit9 */
			{   14, 1,0}, /* core0 sp32 bit10 */
			{  124, 1,0}, /* core0 sp32 bit11 */
			{   72, 1,0}, /* core0 sp32 bit12 */
			{  121, 1,0}, /* core0 sp32 bit13 */
			{   70, 1,0}, /* core0 sp32 bit14 */
			{  112, 1,0}, /* core0 sp32 bit15 */
			{  122, 1,0}, /* core0 sp32 bit16 */
			{  192, 1,0}, /* core0 sp32 bit17 */
			{  118, 1,0}, /* core0 sp32 bit18 */
			{  120, 1,0}, /* core0 sp32 bit19 */
			{  131, 1,0}, /* core0 sp32 bit20 */
			{   15, 1,0}, /* core0 sp32 bit21 */
			{  125, 1,0}, /* core0 sp32 bit22 */
			{  115, 1,0}, /* core0 sp32 bit23 */
			{  132, 1,0}, /* core0 sp32 bit24 */
			{   11, 1,0}, /* core0 sp32 bit25 */
			{   17, 1,0}, /* core0 sp32 bit26 */
			{   10, 1,0}, /* core0 sp32 bit27 */
			{  158, 1,0}, /* core0 sp32 bit28 */
			{   16, 1,0}, /* core0 sp32 bit29 */
			{  194, 1,0}, /* core0 sp32 bit30 */
			{  175, 1,0}, /* core0 sp32 bit31 */
			{ 2071, 1,0}, /* core0 sp32 bit32 */
			{ 2072, 1,0}, /* core0 sp32 bit33 */
			{ 2075, 1,0}, /* core0 sp32 bit34 */
			{ 2059, 1,0}, /* core0 sp32 bit35 */
			{ 2077, 1,0}, /* core0 sp32 bit36 */
			{ 2073, 1,0}, /* core0 sp32 bit37 */
			{ 1999, 1,0}, /* core0 sp32 bit38 */
			{ 2074, 1,0}, /* core0 sp32 bit39 */
			{ 2016, 1,0}, /* core0 sp32 bit40 */
			{ 2000, 1,0}, /* core0 sp32 bit41 */
			{ 1997, 1,0}, /* core0 sp32 bit42 */
			{ 1996, 1,0}, /* core0 sp32 bit43 */
			{ 1998, 1,0}, /* core0 sp32 bit44 */
			{ 1991, 1,0}, /* core0 sp32 bit45 */
			{ 2007, 1,0}, /* core0 sp32 bit46 */
			{ 2316, 1,0}, /* core0 sp32 bit47 */
			{ 7943, 0,0}, /* core0 sp32 bit48 */
			{ 7946, 0,0}, /* core0 sp32 bit49 */
			{ 7975, 0,0}, /* core0 sp32 bit50 */
			{ 7952, 0,0}, /* core0 sp32 bit51 */
			{ 7950, 0,0}, /* core0 sp32 bit52 */
			{ 7944, 0,0}, /* core0 sp32 bit53 */
			{ 7947, 0,0}, /* core0 sp32 bit54 */
			{ 7976, 0,0}, /* core0 sp32 bit55 */
			{ 7949, 0,0}, /* core0 sp32 bit56 */
			{ 7953, 0,0}, /* core0 sp32 bit57 */
			{ 7951, 0,0}, /* core0 sp32 bit58 */
			{ 7954, 0,0}, /* core0 sp32 bit59 */
			{ 7948, 0,0}, /* core0 sp32 bit60 */
			{ 7958, 0,0}, /* core0 sp32 bit61 */
			{ 7945, 0,0}, /* core0 sp32 bit62 */
			{ 1993, 1,0}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{  248, 0,0}, /* core0 fp32 bit0 */
			{  247, 0,0}, /* core0 fp32 bit1 */
			{  253, 0,0}, /* core0 fp32 bit2 */
			{  364, 0,0}, /* core0 fp32 bit3 */
			{  356, 0,0}, /* core0 fp32 bit4 */
			{  246, 0,0}, /* core0 fp32 bit5 */
			{  384, 0,0}, /* core0 fp32 bit6 */
			{  385, 0,0}, /* core0 fp32 bit7 */
			{  258, 0,0}, /* core0 fp32 bit8 */
			{  254, 0,0}, /* core0 fp32 bit9 */
			{  257, 0,0}, /* core0 fp32 bit10 */
			{  392, 0,0}, /* core0 fp32 bit11 */
			{  255, 0,0}, /* core0 fp32 bit12 */
			{  391, 0,0}, /* core0 fp32 bit13 */
			{  387, 0,0}, /* core0 fp32 bit14 */
			{  256, 0,0}, /* core0 fp32 bit15 */
			{  388, 0,0}, /* core0 fp32 bit16 */
			{  354, 0,0}, /* core0 fp32 bit17 */
			{  363, 0,0}, /* core0 fp32 bit18 */
			{  368, 0,0}, /* core0 fp32 bit19 */
			{  335, 0,0}, /* core0 fp32 bit20 */
			{  366, 0,0}, /* core0 fp32 bit21 */
			{  341, 0,0}, /* core0 fp32 bit22 */
			{  339, 0,0}, /* core0 fp32 bit23 */
			{  340, 0,0}, /* core0 fp32 bit24 */
			{  367, 0,0}, /* core0 fp32 bit25 */
			{  337, 0,0}, /* core0 fp32 bit26 */
			{  369, 0,0}, /* core0 fp32 bit27 */
			{  370, 0,0}, /* core0 fp32 bit28 */
			{  336, 0,0}, /* core0 fp32 bit29 */
			{  338, 0,0}, /* core0 fp32 bit30 */
			{  358, 0,0}, /* core0 fp32 bit31 */
			{ 2368, 1,0}, /* core0 fp32 bit32 */
			{ 2381, 1,0}, /* core0 fp32 bit33 */
			{ 2370, 1,0}, /* core0 fp32 bit34 */
			{ 2371, 1,0}, /* core0 fp32 bit35 */
			{ 2386, 1,0}, /* core0 fp32 bit36 */
			{ 2380, 1,0}, /* core0 fp32 bit37 */
			{ 2336, 1,0}, /* core0 fp32 bit38 */
			{ 2379, 1,0}, /* core0 fp32 bit39 */
			{ 2335, 1,0}, /* core0 fp32 bit40 */
			{ 2346, 1,0}, /* core0 fp32 bit41 */
			{ 2339, 1,0}, /* core0 fp32 bit42 */
			{ 2330, 1,0}, /* core0 fp32 bit43 */
			{ 2334, 1,0}, /* core0 fp32 bit44 */
			{ 2345, 1,0}, /* core0 fp32 bit45 */
			{ 2387, 1,0}, /* core0 fp32 bit46 */
			{ 8052, 0,0}, /* core0 fp32 bit47 */
			{ 8054, 0,0}, /* core0 fp32 bit48 */
			{ 2488, 1,0}, /* core0 fp32 bit49 */
			{ 2493, 1,0}, /* core0 fp32 bit50 */
			{ 2506, 1,0}, /* core0 fp32 bit51 */
			{ 2495, 1,0}, /* core0 fp32 bit52 */
			{ 2508, 1,0}, /* core0 fp32 bit53 */
			{ 8051, 0,0}, /* core0 fp32 bit54 */
			{ 2497, 1,0}, /* core0 fp32 bit55 */
			{ 8055, 0,0}, /* core0 fp32 bit56 */
			{ 2498, 1,0}, /* core0 fp32 bit57 */
			{ 8053, 0,0}, /* core0 fp32 bit58 */
			{ 8056, 0,0}, /* core0 fp32 bit59 */
			{ 2492, 1,0}, /* core0 fp32 bit60 */
			{ 2487, 1,0}, /* core0 fp32 bit61 */
			{ 2496, 1,0}, /* core0 fp32 bit62 */
			{ 7942, 0,0}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{  209, 1,0}, /* core0 fp64 bit0 */
			{   50, 1,0}, /* core0 fp64 bit1 */
			{   45, 1,0}, /* core0 fp64 bit2 */
			{  210, 1,0}, /* core0 fp64 bit3 */
			{   58, 1,0}, /* core0 fp64 bit4 */
			{   46, 1,0}, /* core0 fp64 bit5 */
			{  205, 1,0}, /* core0 fp64 bit6 */
			{  213, 1,0}, /* core0 fp64 bit7 */
			{   59, 1,0}, /* core0 fp64 bit8 */
			{  217, 1,0}, /* core0 fp64 bit9 */
			{  207, 1,0}, /* core0 fp64 bit10 */
			{   77, 1,0}, /* core0 fp64 bit11 */
			{  197, 1,0}, /* core0 fp64 bit12 */
			{  200, 1,0}, /* core0 fp64 bit13 */
			{  206, 1,0}, /* core0 fp64 bit14 */
			{  204, 1,0}, /* core0 fp64 bit15 */
			{  199, 1,0}, /* core0 fp64 bit16 */
			{  224, 1,0}, /* core0 fp64 bit17 */
			{  198, 1,0}, /* core0 fp64 bit18 */
			{   83, 1,0}, /* core0 fp64 bit19 */
			{  223, 1,0}, /* core0 fp64 bit20 */
			{  226, 1,0}, /* core0 fp64 bit21 */
			{   61, 1,0}, /* core0 fp64 bit22 */
			{   81, 1,0}, /* core0 fp64 bit23 */
			{   84, 1,0}, /* core0 fp64 bit24 */
			{   80, 1,0}, /* core0 fp64 bit25 */
			{   82, 1,0}, /* core0 fp64 bit26 */
			{   85, 1,0}, /* core0 fp64 bit27 */
			{   78, 1,0}, /* core0 fp64 bit28 */
			{  225, 1,0}, /* core0 fp64 bit29 */
			{   79, 1,0}, /* core0 fp64 bit30 */
			{  215, 1,0}, /* core0 fp64 bit31 */
			{ 1708, 1,0}, /* core0 fp64 bit32 */
			{ 1676, 1,0}, /* core0 fp64 bit33 */
			{ 1677, 1,0}, /* core0 fp64 bit34 */
			{ 1707, 1,0}, /* core0 fp64 bit35 */
			{ 1668, 1,0}, /* core0 fp64 bit36 */
			{ 1675, 1,0}, /* core0 fp64 bit37 */
			{ 1593, 1,0}, /* core0 fp64 bit38 */
			{ 1709, 1,0}, /* core0 fp64 bit39 */
			{ 1594, 1,0}, /* core0 fp64 bit40 */
			{ 1592, 1,0}, /* core0 fp64 bit41 */
			{ 1657, 1,0}, /* core0 fp64 bit42 */
			{ 1589, 1,0}, /* core0 fp64 bit43 */
			{ 1632, 1,0}, /* core0 fp64 bit44 */
			{ 1590, 1,0}, /* core0 fp64 bit45 */
			{ 1591, 1,0}, /* core0 fp64 bit46 */
			{ 3287, 1,0}, /* core0 fp64 bit47 */
			{ 3373, 1,0}, /* core0 fp64 bit48 */
			{ 3292, 1,0}, /* core0 fp64 bit49 */
			{ 3375, 1,0}, /* core0 fp64 bit50 */
			{ 3374, 1,0}, /* core0 fp64 bit51 */
			{ 3286, 1,0}, /* core0 fp64 bit52 */
			{ 3294, 1,0}, /* core0 fp64 bit53 */
			{ 3366, 1,0}, /* core0 fp64 bit54 */
			{ 3371, 1,0}, /* core0 fp64 bit55 */
			{ 3297, 1,0}, /* core0 fp64 bit56 */
			{ 3365, 1,0}, /* core0 fp64 bit57 */
			{ 3376, 1,0}, /* core0 fp64 bit58 */
			{ 3296, 1,0}, /* core0 fp64 bit59 */
			{ 3369, 1,0}, /* core0 fp64 bit60 */
			{ 3372, 1,0}, /* core0 fp64 bit61 */
			{ 3368, 1,0}, /* core0 fp64 bit62 */
			{ 1631, 1,0}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{   56, 1,0}, /* core0 sp_EL0 bit0 */
			{   47, 1,0}, /* core0 sp_EL0 bit1 */
			{   49, 1,0}, /* core0 sp_EL0 bit2 */
			{   48, 1,0}, /* core0 sp_EL0 bit3 */
			{   53, 1,0}, /* core0 sp_EL0 bit4 */
			{   52, 1,0}, /* core0 sp_EL0 bit5 */
			{ 1254, 1,0}, /* core0 sp_EL0 bit6 */
			{ 1277, 1,0}, /* core0 sp_EL0 bit7 */
			{   41, 1,0}, /* core0 sp_EL0 bit8 */
			{ 1300, 1,0}, /* core0 sp_EL0 bit9 */
			{   44, 1,0}, /* core0 sp_EL0 bit10 */
			{   40, 1,0}, /* core0 sp_EL0 bit11 */
			{   43, 1,0}, /* core0 sp_EL0 bit12 */
			{   57, 1,0}, /* core0 sp_EL0 bit13 */
			{ 1273, 1,0}, /* core0 sp_EL0 bit14 */
			{   51, 1,0}, /* core0 sp_EL0 bit15 */
			{   42, 1,0}, /* core0 sp_EL0 bit16 */
			{   22, 1,0}, /* core0 sp_EL0 bit17 */
			{   60, 1,0}, /* core0 sp_EL0 bit18 */
			{   39, 1,0}, /* core0 sp_EL0 bit19 */
			{ 1338, 1,0}, /* core0 sp_EL0 bit20 */
			{ 1247, 1,0}, /* core0 sp_EL0 bit21 */
			{ 1350, 1,0}, /* core0 sp_EL0 bit22 */
			{ 1332, 1,0}, /* core0 sp_EL0 bit23 */
			{ 1253, 1,0}, /* core0 sp_EL0 bit24 */
			{ 1252, 1,0}, /* core0 sp_EL0 bit25 */
			{ 1333, 1,0}, /* core0 sp_EL0 bit26 */
			{ 1335, 1,0}, /* core0 sp_EL0 bit27 */
			{ 1347, 1,0}, /* core0 sp_EL0 bit28 */
			{ 1251, 1,0}, /* core0 sp_EL0 bit29 */
			{ 1349, 1,0}, /* core0 sp_EL0 bit30 */
			{ 1257, 1,0}, /* core0 sp_EL0 bit31 */
			{ 1060, 1,0}, /* core0 sp_EL0 bit32 */
			{ 1719, 1,0}, /* core0 sp_EL0 bit33 */
			{ 1700, 1,0}, /* core0 sp_EL0 bit34 */
			{ 1701, 1,0}, /* core0 sp_EL0 bit35 */
			{ 1655, 1,0}, /* core0 sp_EL0 bit36 */
			{ 1059, 1,0}, /* core0 sp_EL0 bit37 */
			{ 1653, 1,0}, /* core0 sp_EL0 bit38 */
			{ 1704, 1,0}, /* core0 sp_EL0 bit39 */
			{ 1634, 1,0}, /* core0 sp_EL0 bit40 */
			{ 1637, 1,0}, /* core0 sp_EL0 bit41 */
			{ 1687, 1,0}, /* core0 sp_EL0 bit42 */
			{ 1633, 1,0}, /* core0 sp_EL0 bit43 */
			{ 1651, 1,0}, /* core0 sp_EL0 bit44 */
			{ 1636, 1,0}, /* core0 sp_EL0 bit45 */
			{ 1587, 1,0}, /* core0 sp_EL0 bit46 */
			{ 3370, 1,0}, /* core0 sp_EL0 bit47 */
			{ 3347, 1,0}, /* core0 sp_EL0 bit48 */
			{ 3345, 1,0}, /* core0 sp_EL0 bit49 */
			{ 3349, 1,0}, /* core0 sp_EL0 bit50 */
			{ 3354, 1,0}, /* core0 sp_EL0 bit51 */
			{ 3343, 1,0}, /* core0 sp_EL0 bit52 */
			{ 3341, 1,0}, /* core0 sp_EL0 bit53 */
			{ 3351, 1,0}, /* core0 sp_EL0 bit54 */
			{ 3344, 1,0}, /* core0 sp_EL0 bit55 */
			{ 3337, 1,0}, /* core0 sp_EL0 bit56 */
			{ 3346, 1,0}, /* core0 sp_EL0 bit57 */
			{ 3338, 1,0}, /* core0 sp_EL0 bit58 */
			{ 3342, 1,0}, /* core0 sp_EL0 bit59 */
			{ 3340, 1,0}, /* core0 sp_EL0 bit60 */
			{ 3353, 1,0}, /* core0 sp_EL0 bit61 */
			{ 3339, 1,0}, /* core0 sp_EL0 bit62 */
			{ 1658, 1,0}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{  208, 1,0}, /* core0 sp_EL1 bit0 */
			{  202, 1,0}, /* core0 sp_EL1 bit1 */
			{  211, 1,0}, /* core0 sp_EL1 bit2 */
			{  201, 1,0}, /* core0 sp_EL1 bit3 */
			{   89, 1,0}, /* core0 sp_EL1 bit4 */
			{  212, 1,0}, /* core0 sp_EL1 bit5 */
			{  138, 1,0}, /* core0 sp_EL1 bit6 */
			{   68, 1,0}, /* core0 sp_EL1 bit7 */
			{   69, 1,0}, /* core0 sp_EL1 bit8 */
			{  196, 1,0}, /* core0 sp_EL1 bit9 */
			{   76, 1,0}, /* core0 sp_EL1 bit10 */
			{  218, 1,0}, /* core0 sp_EL1 bit11 */
			{   13, 1,0}, /* core0 sp_EL1 bit12 */
			{  195, 1,0}, /* core0 sp_EL1 bit13 */
			{   12, 1,0}, /* core0 sp_EL1 bit14 */
			{  220, 1,0}, /* core0 sp_EL1 bit15 */
			{  219, 1,0}, /* core0 sp_EL1 bit16 */
			{   75, 1,0}, /* core0 sp_EL1 bit17 */
			{   19, 1,0}, /* core0 sp_EL1 bit18 */
			{  133, 1,0}, /* core0 sp_EL1 bit19 */
			{  136, 1,0}, /* core0 sp_EL1 bit20 */
			{   73, 1,0}, /* core0 sp_EL1 bit21 */
			{  141, 1,0}, /* core0 sp_EL1 bit22 */
			{  137, 1,0}, /* core0 sp_EL1 bit23 */
			{  139, 1,0}, /* core0 sp_EL1 bit24 */
			{  135, 1,0}, /* core0 sp_EL1 bit25 */
			{  222, 1,0}, /* core0 sp_EL1 bit26 */
			{   86, 1,0}, /* core0 sp_EL1 bit27 */
			{  134, 1,0}, /* core0 sp_EL1 bit28 */
			{   74, 1,0}, /* core0 sp_EL1 bit29 */
			{  116, 1,0}, /* core0 sp_EL1 bit30 */
			{   88, 1,0}, /* core0 sp_EL1 bit31 */
			{ 1697, 1,0}, /* core0 sp_EL1 bit32 */
			{ 1695, 1,0}, /* core0 sp_EL1 bit33 */
			{ 1698, 1,0}, /* core0 sp_EL1 bit34 */
			{ 1696, 1,0}, /* core0 sp_EL1 bit35 */
			{ 1679, 1,0}, /* core0 sp_EL1 bit36 */
			{ 1699, 1,0}, /* core0 sp_EL1 bit37 */
			{ 1684, 1,0}, /* core0 sp_EL1 bit38 */
			{ 1694, 1,0}, /* core0 sp_EL1 bit39 */
			{ 1656, 1,0}, /* core0 sp_EL1 bit40 */
			{ 1686, 1,0}, /* core0 sp_EL1 bit41 */
			{ 1678, 1,0}, /* core0 sp_EL1 bit42 */
			{ 1680, 1,0}, /* core0 sp_EL1 bit43 */
			{ 1691, 1,0}, /* core0 sp_EL1 bit44 */
			{ 1586, 1,0}, /* core0 sp_EL1 bit45 */
			{ 1685, 1,0}, /* core0 sp_EL1 bit46 */
			{ 1035, 1,0}, /* core0 sp_EL1 bit47 */
			{ 3288, 1,0}, /* core0 sp_EL1 bit48 */
			{ 1034, 1,0}, /* core0 sp_EL1 bit49 */
			{ 3285, 1,0}, /* core0 sp_EL1 bit50 */
			{ 3289, 1,0}, /* core0 sp_EL1 bit51 */
			{ 3268, 1,0}, /* core0 sp_EL1 bit52 */
			{ 1019, 1,0}, /* core0 sp_EL1 bit53 */
			{ 1023, 1,0}, /* core0 sp_EL1 bit54 */
			{ 3290, 1,0}, /* core0 sp_EL1 bit55 */
			{ 3295, 1,0}, /* core0 sp_EL1 bit56 */
			{ 3302, 1,0}, /* core0 sp_EL1 bit57 */
			{ 3293, 1,0}, /* core0 sp_EL1 bit58 */
			{ 3283, 1,0}, /* core0 sp_EL1 bit59 */
			{ 3299, 1,0}, /* core0 sp_EL1 bit60 */
			{ 3291, 1,0}, /* core0 sp_EL1 bit61 */
			{ 1020, 1,0}, /* core0 sp_EL1 bit62 */
			{ 1693, 1,0}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 1307, 1,0}, /* core0 sp_EL2 bit0 */
			{ 1283, 1,0}, /* core0 sp_EL2 bit1 */
			{ 1308, 1,0}, /* core0 sp_EL2 bit2 */
			{ 1255, 1,0}, /* core0 sp_EL2 bit3 */
			{ 1265, 1,0}, /* core0 sp_EL2 bit4 */
			{ 1256, 1,0}, /* core0 sp_EL2 bit5 */
			{ 1280, 1,0}, /* core0 sp_EL2 bit6 */
			{ 1278, 1,0}, /* core0 sp_EL2 bit7 */
			{ 1303, 1,0}, /* core0 sp_EL2 bit8 */
			{ 1285, 1,0}, /* core0 sp_EL2 bit9 */
			{ 1313, 1,0}, /* core0 sp_EL2 bit10 */
			{ 1302, 1,0}, /* core0 sp_EL2 bit11 */
			{ 1310, 1,0}, /* core0 sp_EL2 bit12 */
			{ 1304, 1,0}, /* core0 sp_EL2 bit13 */
			{ 1275, 1,0}, /* core0 sp_EL2 bit14 */
			{ 1312, 1,0}, /* core0 sp_EL2 bit15 */
			{ 1311, 1,0}, /* core0 sp_EL2 bit16 */
			{ 1258, 1,0}, /* core0 sp_EL2 bit17 */
			{ 1250, 1,0}, /* core0 sp_EL2 bit18 */
			{ 1368, 1,0}, /* core0 sp_EL2 bit19 */
			{ 1369, 1,0}, /* core0 sp_EL2 bit20 */
			{ 1358, 1,0}, /* core0 sp_EL2 bit21 */
			{ 1361, 1,0}, /* core0 sp_EL2 bit22 */
			{ 1375, 1,0}, /* core0 sp_EL2 bit23 */
			{ 1374, 1,0}, /* core0 sp_EL2 bit24 */
			{ 1370, 1,0}, /* core0 sp_EL2 bit25 */
			{ 1372, 1,0}, /* core0 sp_EL2 bit26 */
			{ 1371, 1,0}, /* core0 sp_EL2 bit27 */
			{ 1376, 1,0}, /* core0 sp_EL2 bit28 */
			{ 1373, 1,0}, /* core0 sp_EL2 bit29 */
			{ 1367, 1,0}, /* core0 sp_EL2 bit30 */
			{ 1264, 1,0}, /* core0 sp_EL2 bit31 */
			{ 1042, 1,0}, /* core0 sp_EL2 bit32 */
			{ 1047, 1,0}, /* core0 sp_EL2 bit33 */
			{ 1043, 1,0}, /* core0 sp_EL2 bit34 */
			{ 1041, 1,0}, /* core0 sp_EL2 bit35 */
			{ 1046, 1,0}, /* core0 sp_EL2 bit36 */
			{ 1040, 1,0}, /* core0 sp_EL2 bit37 */
			{ 1088, 1,0}, /* core0 sp_EL2 bit38 */
			{ 1050, 1,0}, /* core0 sp_EL2 bit39 */
			{ 1090, 1,0}, /* core0 sp_EL2 bit40 */
			{ 1084, 1,0}, /* core0 sp_EL2 bit41 */
			{ 1087, 1,0}, /* core0 sp_EL2 bit42 */
			{ 1089, 1,0}, /* core0 sp_EL2 bit43 */
			{ 1091, 1,0}, /* core0 sp_EL2 bit44 */
			{ 1092, 1,0}, /* core0 sp_EL2 bit45 */
			{ 1081, 1,0}, /* core0 sp_EL2 bit46 */
			{ 3180, 1,0}, /* core0 sp_EL2 bit47 */
			{ 3190, 1,0}, /* core0 sp_EL2 bit48 */
			{ 3183, 1,0}, /* core0 sp_EL2 bit49 */
			{ 3194, 1,0}, /* core0 sp_EL2 bit50 */
			{ 3192, 1,0}, /* core0 sp_EL2 bit51 */
			{ 3195, 1,0}, /* core0 sp_EL2 bit52 */
			{ 3197, 1,0}, /* core0 sp_EL2 bit53 */
			{ 3182, 1,0}, /* core0 sp_EL2 bit54 */
			{ 3186, 1,0}, /* core0 sp_EL2 bit55 */
			{ 3193, 1,0}, /* core0 sp_EL2 bit56 */
			{ 3185, 1,0}, /* core0 sp_EL2 bit57 */
			{ 3189, 1,0}, /* core0 sp_EL2 bit58 */
			{ 3181, 1,0}, /* core0 sp_EL2 bit59 */
			{ 3196, 1,0}, /* core0 sp_EL2 bit60 */
			{ 3230, 1,0}, /* core0 sp_EL2 bit61 */
			{ 3191, 1,0}, /* core0 sp_EL2 bit62 */
			{ 1036, 1,0}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 1550, 1,0}, /* core0 sp_EL3 bit0 */
			{ 1270, 1,0}, /* core0 sp_EL3 bit1 */
			{ 1271, 1,0}, /* core0 sp_EL3 bit2 */
			{ 1551, 1,0}, /* core0 sp_EL3 bit3 */
			{ 1268, 1,0}, /* core0 sp_EL3 bit4 */
			{ 1267, 1,0}, /* core0 sp_EL3 bit5 */
			{ 1323, 1,0}, /* core0 sp_EL3 bit6 */
			{ 1322, 1,0}, /* core0 sp_EL3 bit7 */
			{ 1318, 1,0}, /* core0 sp_EL3 bit8 */
			{ 1319, 1,0}, /* core0 sp_EL3 bit9 */
			{ 1315, 1,0}, /* core0 sp_EL3 bit10 */
			{ 1004, 1,0}, /* core0 sp_EL3 bit11 */
			{ 1317, 1,0}, /* core0 sp_EL3 bit12 */
			{ 1316, 1,0}, /* core0 sp_EL3 bit13 */
			{ 1321, 1,0}, /* core0 sp_EL3 bit14 */
			{ 1320, 1,0}, /* core0 sp_EL3 bit15 */
			{ 1324, 1,0}, /* core0 sp_EL3 bit16 */
			{ 1552, 1,0}, /* core0 sp_EL3 bit17 */
			{ 1549, 1,0}, /* core0 sp_EL3 bit18 */
			{ 1579, 1,0}, /* core0 sp_EL3 bit19 */
			{ 1571, 1,0}, /* core0 sp_EL3 bit20 */
			{ 1575, 1,0}, /* core0 sp_EL3 bit21 */
			{ 1580, 1,0}, /* core0 sp_EL3 bit22 */
			{ 1570, 1,0}, /* core0 sp_EL3 bit23 */
			{ 1574, 1,0}, /* core0 sp_EL3 bit24 */
			{ 1578, 1,0}, /* core0 sp_EL3 bit25 */
			{ 1573, 1,0}, /* core0 sp_EL3 bit26 */
			{ 1569, 1,0}, /* core0 sp_EL3 bit27 */
			{ 1577, 1,0}, /* core0 sp_EL3 bit28 */
			{ 1572, 1,0}, /* core0 sp_EL3 bit29 */
			{ 1576, 1,0}, /* core0 sp_EL3 bit30 */
			{ 1269, 1,0}, /* core0 sp_EL3 bit31 */
			{ 1054, 1,0}, /* core0 sp_EL3 bit32 */
			{ 1051, 1,0}, /* core0 sp_EL3 bit33 */
			{ 1052, 1,0}, /* core0 sp_EL3 bit34 */
			{ 1062, 1,0}, /* core0 sp_EL3 bit35 */
			{ 1071, 1,0}, /* core0 sp_EL3 bit36 */
			{ 1063, 1,0}, /* core0 sp_EL3 bit37 */
			{ 1056, 1,0}, /* core0 sp_EL3 bit38 */
			{ 1064, 1,0}, /* core0 sp_EL3 bit39 */
			{ 1085, 1,0}, /* core0 sp_EL3 bit40 */
			{ 1083, 1,0}, /* core0 sp_EL3 bit41 */
			{ 1072, 1,0}, /* core0 sp_EL3 bit42 */
			{ 1080, 1,0}, /* core0 sp_EL3 bit43 */
			{ 1086, 1,0}, /* core0 sp_EL3 bit44 */
			{ 1079, 1,0}, /* core0 sp_EL3 bit45 */
			{ 1082, 1,0}, /* core0 sp_EL3 bit46 */
			{ 3318, 1,0}, /* core0 sp_EL3 bit47 */
			{ 3176, 1,0}, /* core0 sp_EL3 bit48 */
			{ 3320, 1,0}, /* core0 sp_EL3 bit49 */
			{ 3325, 1,0}, /* core0 sp_EL3 bit50 */
			{ 3321, 1,0}, /* core0 sp_EL3 bit51 */
			{ 3317, 1,0}, /* core0 sp_EL3 bit52 */
			{ 3358, 1,0}, /* core0 sp_EL3 bit53 */
			{ 3319, 1,0}, /* core0 sp_EL3 bit54 */
			{ 3313, 1,0}, /* core0 sp_EL3 bit55 */
			{ 3324, 1,0}, /* core0 sp_EL3 bit56 */
			{ 3314, 1,0}, /* core0 sp_EL3 bit57 */
			{ 3356, 1,0}, /* core0 sp_EL3 bit58 */
			{ 3357, 1,0}, /* core0 sp_EL3 bit59 */
			{ 3315, 1,0}, /* core0 sp_EL3 bit60 */
			{ 3316, 1,0}, /* core0 sp_EL3 bit61 */
			{ 3322, 1,0}, /* core0 sp_EL3 bit62 */
			{ 1053, 1,0}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{   54, 1,0}, /* core0 elr_EL1 bit0 */
			{   55, 1,0}, /* core0 elr_EL1 bit1 */
			{ 1001, 1,0}, /* core0 elr_EL1 bit2 */
			{ 1000, 1,0}, /* core0 elr_EL1 bit3 */
			{ 1263, 1,0}, /* core0 elr_EL1 bit4 */
			{ 1286, 1,0}, /* core0 elr_EL1 bit5 */
			{ 1287, 1,0}, /* core0 elr_EL1 bit6 */
			{ 1276, 1,0}, /* core0 elr_EL1 bit7 */
			{ 1301, 1,0}, /* core0 elr_EL1 bit8 */
			{ 1289, 1,0}, /* core0 elr_EL1 bit9 */
			{ 1002, 1,0}, /* core0 elr_EL1 bit10 */
			{ 1290, 1,0}, /* core0 elr_EL1 bit11 */
			{ 1291, 1,0}, /* core0 elr_EL1 bit12 */
			{  999, 1,0}, /* core0 elr_EL1 bit13 */
			{ 1314, 1,0}, /* core0 elr_EL1 bit14 */
			{ 1003, 1,0}, /* core0 elr_EL1 bit15 */
			{ 1288, 1,0}, /* core0 elr_EL1 bit16 */
			{ 1274, 1,0}, /* core0 elr_EL1 bit17 */
			{ 1331, 1,0}, /* core0 elr_EL1 bit18 */
			{ 1346, 1,0}, /* core0 elr_EL1 bit19 */
			{ 1339, 1,0}, /* core0 elr_EL1 bit20 */
			{ 1343, 1,0}, /* core0 elr_EL1 bit21 */
			{ 1348, 1,0}, /* core0 elr_EL1 bit22 */
			{ 1352, 1,0}, /* core0 elr_EL1 bit23 */
			{ 1341, 1,0}, /* core0 elr_EL1 bit24 */
			{ 1342, 1,0}, /* core0 elr_EL1 bit25 */
			{ 1248, 1,0}, /* core0 elr_EL1 bit26 */
			{ 1340, 1,0}, /* core0 elr_EL1 bit27 */
			{ 1351, 1,0}, /* core0 elr_EL1 bit28 */
			{ 1334, 1,0}, /* core0 elr_EL1 bit29 */
			{ 1337, 1,0}, /* core0 elr_EL1 bit30 */
			{ 1266, 1,0}, /* core0 elr_EL1 bit31 */
			{ 1749, 1,0}, /* core0 elr_EL1 bit32 */
			{ 1750, 1,0}, /* core0 elr_EL1 bit33 */
			{ 1757, 1,0}, /* core0 elr_EL1 bit34 */
			{ 1752, 1,0}, /* core0 elr_EL1 bit35 */
			{ 1744, 1,0}, /* core0 elr_EL1 bit36 */
			{ 1748, 1,0}, /* core0 elr_EL1 bit37 */
			{ 1767, 1,0}, /* core0 elr_EL1 bit38 */
			{ 1751, 1,0}, /* core0 elr_EL1 bit39 */
			{ 1795, 1,0}, /* core0 elr_EL1 bit40 */
			{ 1746, 1,0}, /* core0 elr_EL1 bit41 */
			{ 1745, 1,0}, /* core0 elr_EL1 bit42 */
			{ 1769, 1,0}, /* core0 elr_EL1 bit43 */
			{ 1796, 1,0}, /* core0 elr_EL1 bit44 */
			{ 1797, 1,0}, /* core0 elr_EL1 bit45 */
			{ 1768, 1,0}, /* core0 elr_EL1 bit46 */
			{ 7297, 0,0}, /* core0 elr_EL1 bit47 */
			{ 7284, 0,0}, /* core0 elr_EL1 bit48 */
			{ 7285, 0,0}, /* core0 elr_EL1 bit49 */
			{ 7283, 0,0}, /* core0 elr_EL1 bit50 */
			{ 7290, 0,0}, /* core0 elr_EL1 bit51 */
			{ 7292, 0,0}, /* core0 elr_EL1 bit52 */
			{ 7296, 0,0}, /* core0 elr_EL1 bit53 */
			{ 7293, 0,0}, /* core0 elr_EL1 bit54 */
			{ 7286, 0,0}, /* core0 elr_EL1 bit55 */
			{ 7979, 0,0}, /* core0 elr_EL1 bit56 */
			{ 7288, 0,0}, /* core0 elr_EL1 bit57 */
			{ 7294, 0,0}, /* core0 elr_EL1 bit58 */
			{ 7287, 0,0}, /* core0 elr_EL1 bit59 */
			{ 7289, 0,0}, /* core0 elr_EL1 bit60 */
			{ 7291, 0,0}, /* core0 elr_EL1 bit61 */
			{ 7295, 0,0}, /* core0 elr_EL1 bit62 */
			{ 1759, 1,0}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{  275, 0,0}, /* core0 elr_EL2 bit0 */
			{  393, 0,0}, /* core0 elr_EL2 bit1 */
			{  276, 0,0}, /* core0 elr_EL2 bit2 */
			{  360, 0,0}, /* core0 elr_EL2 bit3 */
			{  292, 0,0}, /* core0 elr_EL2 bit4 */
			{  281, 0,0}, /* core0 elr_EL2 bit5 */
			{  280, 0,0}, /* core0 elr_EL2 bit6 */
			{  282, 0,0}, /* core0 elr_EL2 bit7 */
			{  398, 0,0}, /* core0 elr_EL2 bit8 */
			{  397, 0,0}, /* core0 elr_EL2 bit9 */
			{  396, 0,0}, /* core0 elr_EL2 bit10 */
			{  399, 0,0}, /* core0 elr_EL2 bit11 */
			{  400, 0,0}, /* core0 elr_EL2 bit12 */
			{  401, 0,0}, /* core0 elr_EL2 bit13 */
			{  285, 0,0}, /* core0 elr_EL2 bit14 */
			{  395, 0,0}, /* core0 elr_EL2 bit15 */
			{  394, 0,0}, /* core0 elr_EL2 bit16 */
			{  283, 0,0}, /* core0 elr_EL2 bit17 */
			{  284, 0,0}, /* core0 elr_EL2 bit18 */
			{  381, 0,0}, /* core0 elr_EL2 bit19 */
			{  382, 0,0}, /* core0 elr_EL2 bit20 */
			{  377, 0,0}, /* core0 elr_EL2 bit21 */
			{  371, 0,0}, /* core0 elr_EL2 bit22 */
			{  379, 0,0}, /* core0 elr_EL2 bit23 */
			{  372, 0,0}, /* core0 elr_EL2 bit24 */
			{  374, 0,0}, /* core0 elr_EL2 bit25 */
			{  378, 0,0}, /* core0 elr_EL2 bit26 */
			{  375, 0,0}, /* core0 elr_EL2 bit27 */
			{  376, 0,0}, /* core0 elr_EL2 bit28 */
			{  373, 0,0}, /* core0 elr_EL2 bit29 */
			{  380, 0,0}, /* core0 elr_EL2 bit30 */
			{  291, 0,0}, /* core0 elr_EL2 bit31 */
			{ 1039, 1,0}, /* core0 elr_EL2 bit32 */
			{ 1044, 1,0}, /* core0 elr_EL2 bit33 */
			{ 1038, 1,0}, /* core0 elr_EL2 bit34 */
			{ 1037, 1,0}, /* core0 elr_EL2 bit35 */
			{ 1662, 1,0}, /* core0 elr_EL2 bit36 */
			{ 1045, 1,0}, /* core0 elr_EL2 bit37 */
			{ 1074, 1,0}, /* core0 elr_EL2 bit38 */
			{ 1061, 1,0}, /* core0 elr_EL2 bit39 */
			{ 1076, 1,0}, /* core0 elr_EL2 bit40 */
			{ 1069, 1,0}, /* core0 elr_EL2 bit41 */
			{ 1075, 1,0}, /* core0 elr_EL2 bit42 */
			{ 1070, 1,0}, /* core0 elr_EL2 bit43 */
			{ 1077, 1,0}, /* core0 elr_EL2 bit44 */
			{ 1078, 1,0}, /* core0 elr_EL2 bit45 */
			{ 1073, 1,0}, /* core0 elr_EL2 bit46 */
			{ 3348, 1,0}, /* core0 elr_EL2 bit47 */
			{ 3328, 1,0}, /* core0 elr_EL2 bit48 */
			{ 3334, 1,0}, /* core0 elr_EL2 bit49 */
			{ 3336, 1,0}, /* core0 elr_EL2 bit50 */
			{ 3352, 1,0}, /* core0 elr_EL2 bit51 */
			{ 3168, 1,0}, /* core0 elr_EL2 bit52 */
			{ 3172, 1,0}, /* core0 elr_EL2 bit53 */
			{ 3331, 1,0}, /* core0 elr_EL2 bit54 */
			{ 3335, 1,0}, /* core0 elr_EL2 bit55 */
			{ 3326, 1,0}, /* core0 elr_EL2 bit56 */
			{ 3329, 1,0}, /* core0 elr_EL2 bit57 */
			{ 3355, 1,0}, /* core0 elr_EL2 bit58 */
			{ 3327, 1,0}, /* core0 elr_EL2 bit59 */
			{ 3330, 1,0}, /* core0 elr_EL2 bit60 */
			{ 3332, 1,0}, /* core0 elr_EL2 bit61 */
			{ 3333, 1,0}, /* core0 elr_EL2 bit62 */
			{ 1055, 1,0}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 2940, 1,0}, /* core0 elr_EL3 bit0 */
			{ 2887, 1,0}, /* core0 elr_EL3 bit1 */
			{ 2886, 1,0}, /* core0 elr_EL3 bit2 */
			{ 2892, 1,0}, /* core0 elr_EL3 bit3 */
			{ 2880, 1,0}, /* core0 elr_EL3 bit4 */
			{ 2878, 1,0}, /* core0 elr_EL3 bit5 */
			{ 2944, 1,0}, /* core0 elr_EL3 bit6 */
			{ 2885, 1,0}, /* core0 elr_EL3 bit7 */
			{ 2900, 1,0}, /* core0 elr_EL3 bit8 */
			{ 2899, 1,0}, /* core0 elr_EL3 bit9 */
			{ 2897, 1,0}, /* core0 elr_EL3 bit10 */
			{ 2938, 1,0}, /* core0 elr_EL3 bit11 */
			{ 2896, 1,0}, /* core0 elr_EL3 bit12 */
			{ 2942, 1,0}, /* core0 elr_EL3 bit13 */
			{ 2895, 1,0}, /* core0 elr_EL3 bit14 */
			{ 2937, 1,0}, /* core0 elr_EL3 bit15 */
			{ 2939, 1,0}, /* core0 elr_EL3 bit16 */
			{ 2881, 1,0}, /* core0 elr_EL3 bit17 */
			{ 2945, 1,0}, /* core0 elr_EL3 bit18 */
			{ 2955, 1,0}, /* core0 elr_EL3 bit19 */
			{ 2962, 1,0}, /* core0 elr_EL3 bit20 */
			{ 2957, 1,0}, /* core0 elr_EL3 bit21 */
			{ 2970, 1,0}, /* core0 elr_EL3 bit22 */
			{ 2963, 1,0}, /* core0 elr_EL3 bit23 */
			{ 2971, 1,0}, /* core0 elr_EL3 bit24 */
			{ 2956, 1,0}, /* core0 elr_EL3 bit25 */
			{ 2961, 1,0}, /* core0 elr_EL3 bit26 */
			{ 2960, 1,0}, /* core0 elr_EL3 bit27 */
			{ 2958, 1,0}, /* core0 elr_EL3 bit28 */
			{ 2959, 1,0}, /* core0 elr_EL3 bit29 */
			{ 2954, 1,0}, /* core0 elr_EL3 bit30 */
			{ 2879, 1,0}, /* core0 elr_EL3 bit31 */
			{ 1048, 1,0}, /* core0 elr_EL3 bit32 */
			{ 1049, 1,0}, /* core0 elr_EL3 bit33 */
			{ 2069, 1,0}, /* core0 elr_EL3 bit34 */
			{ 2061, 1,0}, /* core0 elr_EL3 bit35 */
			{ 1772, 1,0}, /* core0 elr_EL3 bit36 */
			{ 2063, 1,0}, /* core0 elr_EL3 bit37 */
			{ 1774, 1,0}, /* core0 elr_EL3 bit38 */
			{ 2064, 1,0}, /* core0 elr_EL3 bit39 */
			{ 1773, 1,0}, /* core0 elr_EL3 bit40 */
			{ 1788, 1,0}, /* core0 elr_EL3 bit41 */
			{ 1785, 1,0}, /* core0 elr_EL3 bit42 */
			{ 1786, 1,0}, /* core0 elr_EL3 bit43 */
			{ 1787, 1,0}, /* core0 elr_EL3 bit44 */
			{ 1789, 1,0}, /* core0 elr_EL3 bit45 */
			{ 1778, 1,0}, /* core0 elr_EL3 bit46 */
			{ 3220, 1,0}, /* core0 elr_EL3 bit47 */
			{ 7965, 1,0}, /* core0 elr_EL3 bit48 */
			{ 7960, 1,0}, /* core0 elr_EL3 bit49 */
			{ 3223, 1,0}, /* core0 elr_EL3 bit50 */
			{ 7972, 1,0}, /* core0 elr_EL3 bit51 */
			{ 7973, 1,0}, /* core0 elr_EL3 bit52 */
			{ 3221, 1,0}, /* core0 elr_EL3 bit53 */
			{ 3226, 1,0}, /* core0 elr_EL3 bit54 */
			{ 7958, 1,0}, /* core0 elr_EL3 bit55 */
			{ 7966, 1,0}, /* core0 elr_EL3 bit56 */
			{ 7959, 1,0}, /* core0 elr_EL3 bit57 */
			{ 7963, 1,0}, /* core0 elr_EL3 bit58 */
			{ 7961, 1,0}, /* core0 elr_EL3 bit59 */
			{ 7962, 1,0}, /* core0 elr_EL3 bit60 */
			{ 3224, 1,0}, /* core0 elr_EL3 bit61 */
			{ 3225, 1,0}, /* core0 elr_EL3 bit62 */
			{ 1779, 1,0}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 7402, 0,0}, /* core0 raw_pc bit0 */
			{ 5743, 1,0}, /* core0 raw_pc bit1 */
			{ 5742, 1,0}, /* core0 raw_pc bit2 */
			{ 7399, 0,0}, /* core0 raw_pc bit3 */
			{ 7401, 0,0}, /* core0 raw_pc bit4 */
			{ 7400, 0,0}, /* core0 raw_pc bit5 */
			{ 7404, 0,0}, /* core0 raw_pc bit6 */
			{ 9616, 0,0}, /* core0 raw_pc bit7 */
			{ 9615, 0,0}, /* core0 raw_pc bit8 */
			{ 9614, 0,0}, /* core0 raw_pc bit9 */
			{ 9613, 0,0}, /* core0 raw_pc bit10 */
			{ 9620, 0,0}, /* core0 raw_pc bit11 */
			{ 9619, 0,0}, /* core0 raw_pc bit12 */
			{ 9618, 0,0}, /* core0 raw_pc bit13 */
			{ 9617, 0,0}, /* core0 raw_pc bit14 */
			{ 9624, 0,0}, /* core0 raw_pc bit15 */
			{ 9623, 0,0}, /* core0 raw_pc bit16 */
			{ 9622, 0,0}, /* core0 raw_pc bit17 */
			{ 9621, 0,0}, /* core0 raw_pc bit18 */
			{10437, 0,0}, /* core0 raw_pc bit19 */
			{10436, 0,0}, /* core0 raw_pc bit20 */
			{10435, 0,0}, /* core0 raw_pc bit21 */
			{10434, 0,0}, /* core0 raw_pc bit22 */
			{10441, 0,0}, /* core0 raw_pc bit23 */
			{10440, 0,0}, /* core0 raw_pc bit24 */
			{10439, 0,0}, /* core0 raw_pc bit25 */
			{10438, 0,0}, /* core0 raw_pc bit26 */
			{10445, 0,0}, /* core0 raw_pc bit27 */
			{10444, 0,0}, /* core0 raw_pc bit28 */
			{10443, 0,0}, /* core0 raw_pc bit29 */
			{10442, 0,0}, /* core0 raw_pc bit30 */
			{ 9347, 0,0}, /* core0 raw_pc bit31 */
			{ 9346, 0,0}, /* core0 raw_pc bit32 */
			{ 9345, 0,0}, /* core0 raw_pc bit33 */
			{ 9344, 0,0}, /* core0 raw_pc bit34 */
			{ 9351, 0,0}, /* core0 raw_pc bit35 */
			{ 9350, 0,0}, /* core0 raw_pc bit36 */
			{ 9349, 0,0}, /* core0 raw_pc bit37 */
			{ 5234, 1,0}, /* core0 raw_pc bit38 */
			{ 9646, 0,0}, /* core0 raw_pc bit39 */
			{ 9645, 0,0}, /* core0 raw_pc bit40 */
			{ 9348, 0,0}, /* core0 raw_pc bit41 */
			{ 9648, 0,0}, /* core0 raw_pc bit42 */
			{ 9647, 0,0}, /* core0 raw_pc bit43 */
			{ 9644, 0,0}, /* core0 raw_pc bit44 */
			{ 9643, 0,0}, /* core0 raw_pc bit45 */
			{ 5232, 1,0}, /* core0 raw_pc bit46 */
			{ 5233, 1,0}, /* core0 raw_pc bit47 */
			{    0, 0,2}, /* core0 raw_pc bit48 */
			{    0, 0,2}, /* core0 raw_pc bit49 */
			{    0, 0,2}, /* core0 raw_pc bit50 */
			{    0, 0,2}, /* core0 raw_pc bit51 */
			{    0, 0,2}, /* core0 raw_pc bit52 */
			{    0, 0,2}, /* core0 raw_pc bit53 */
			{    0, 0,2}, /* core0 raw_pc bit54 */
			{    0, 0,2}, /* core0 raw_pc bit55 */
			{    0, 0,2}, /* core0 raw_pc bit56 */
			{    0, 0,2}, /* core0 raw_pc bit57 */
			{    0, 0,2}, /* core0 raw_pc bit58 */
			{    0, 0,2}, /* core0 raw_pc bit59 */
			{    0, 0,2}, /* core0 raw_pc bit60 */
			{    0, 0,2}, /* core0 raw_pc bit61 */
			{    0, 0,2}, /* core0 raw_pc bit62 */
			{    0, 0,2}, /* core0 raw_pc bit63 */
			}},
			.pc_iss = {{
			{ 9507, 0,0}, /* core0 pc_iss bit0 */
			{ 9506, 0,0}, /* core0 pc_iss bit1 */
			{ 9505, 0,0}, /* core0 pc_iss bit2 */
			{ 9513, 0,0}, /* core0 pc_iss bit3 */
			{ 9512, 0,0}, /* core0 pc_iss bit4 */
			{ 9503, 0,0}, /* core0 pc_iss bit5 */
			{ 9502, 0,0}, /* core0 pc_iss bit6 */
			{ 9504, 0,0}, /* core0 pc_iss bit7 */
			{ 9626, 0,0}, /* core0 pc_iss bit8 */
			{ 9625, 0,0}, /* core0 pc_iss bit9 */
			{ 9509, 0,0}, /* core0 pc_iss bit10 */
			{ 9634, 0,0}, /* core0 pc_iss bit11 */
			{ 9633, 0,0}, /* core0 pc_iss bit12 */
			{ 9331, 0,0}, /* core0 pc_iss bit13 */
			{ 5360, 1,0}, /* core0 pc_iss bit14 */
			{ 9630, 0,0}, /* core0 pc_iss bit15 */
			{ 9629, 0,0}, /* core0 pc_iss bit16 */
			{ 9511, 0,0}, /* core0 pc_iss bit17 */
			{ 9510, 0,0}, /* core0 pc_iss bit18 */
			{ 9628, 0,0}, /* core0 pc_iss bit19 */
			{ 9508, 0,0}, /* core0 pc_iss bit20 */
			{ 9627, 0,0}, /* core0 pc_iss bit21 */
			{ 9632, 0,0}, /* core0 pc_iss bit22 */
			{ 9330, 0,0}, /* core0 pc_iss bit23 */
			{ 5363, 1,0}, /* core0 pc_iss bit24 */
			{ 9329, 0,0}, /* core0 pc_iss bit25 */
			{ 9328, 0,0}, /* core0 pc_iss bit26 */
			{ 9631, 0,0}, /* core0 pc_iss bit27 */
			{ 5361, 1,0}, /* core0 pc_iss bit28 */
			{ 9636, 0,0}, /* core0 pc_iss bit29 */
			{ 9635, 0,0}, /* core0 pc_iss bit30 */
			{ 5362, 1,0}, /* core0 pc_iss bit31 */
			{ 9656, 0,0}, /* core0 pc_iss bit32 */
			{ 9391, 0,0}, /* core0 pc_iss bit33 */
			{ 9655, 0,0}, /* core0 pc_iss bit34 */
			{ 9654, 0,0}, /* core0 pc_iss bit35 */
			{ 9653, 0,0}, /* core0 pc_iss bit36 */
			{ 9390, 0,0}, /* core0 pc_iss bit37 */
			{ 9389, 0,0}, /* core0 pc_iss bit38 */
			{ 5248, 1,0}, /* core0 pc_iss bit39 */
			{ 9652, 0,0}, /* core0 pc_iss bit40 */
			{ 9388, 0,0}, /* core0 pc_iss bit41 */
			{ 5250, 1,0}, /* core0 pc_iss bit42 */
			{ 9387, 0,0}, /* core0 pc_iss bit43 */
			{ 9651, 0,0}, /* core0 pc_iss bit44 */
			{ 9650, 0,0}, /* core0 pc_iss bit45 */
			{ 5246, 1,0}, /* core0 pc_iss bit46 */
			{ 9649, 0,0}, /* core0 pc_iss bit47 */
			{ 5249, 1,0}, /* core0 pc_iss bit48 */
			{ 9386, 0,0}, /* core0 pc_iss bit49 */
			{ 5245, 1,0}, /* core0 pc_iss bit50 */
			{ 5247, 1,0}, /* core0 pc_iss bit51 */
			{ 5243, 1,0}, /* core0 pc_iss bit52 */
			{ 5235, 1,0}, /* core0 pc_iss bit53 */
			{ 5244, 1,0}, /* core0 pc_iss bit54 */
			{ 9385, 0,0}, /* core0 pc_iss bit55 */
			{ 5241, 1,0}, /* core0 pc_iss bit56 */
			{ 5242, 1,0}, /* core0 pc_iss bit57 */
			{ 5236, 1,0}, /* core0 pc_iss bit58 */
			{ 9384, 0,0}, /* core0 pc_iss bit59 */
			{ 5237, 1,0}, /* core0 pc_iss bit60 */
			{ 5238, 1,0}, /* core0 pc_iss bit61 */
			{ 5239, 1,0}, /* core0 pc_iss bit62 */
			{ 5240, 1,0}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 7403, 0,0}, /* core0 full_pc_wr bit0 */
			{    0, 0,2}, /* core0 full_pc_wr bit1 */
			{    0, 0,2}, /* core0 full_pc_wr bit2 */
			{    0, 0,2}, /* core0 full_pc_wr bit3 */
			{    0, 0,2}, /* core0 full_pc_wr bit4 */
			{    0, 0,2}, /* core0 full_pc_wr bit5 */
			{    0, 0,2}, /* core0 full_pc_wr bit6 */
			{    0, 0,2}, /* core0 full_pc_wr bit7 */
			{    0, 0,2}, /* core0 full_pc_wr bit8 */
			{    0, 0,2}, /* core0 full_pc_wr bit9 */
			{    0, 0,2}, /* core0 full_pc_wr bit10 */
			{    0, 0,2}, /* core0 full_pc_wr bit11 */
			{    0, 0,2}, /* core0 full_pc_wr bit12 */
			{    0, 0,2}, /* core0 full_pc_wr bit13 */
			{    0, 0,2}, /* core0 full_pc_wr bit14 */
			{    0, 0,2}, /* core0 full_pc_wr bit15 */
			{    0, 0,2}, /* core0 full_pc_wr bit16 */
			{    0, 0,2}, /* core0 full_pc_wr bit17 */
			{    0, 0,2}, /* core0 full_pc_wr bit18 */
			{    0, 0,2}, /* core0 full_pc_wr bit19 */
			{    0, 0,2}, /* core0 full_pc_wr bit20 */
			{    0, 0,2}, /* core0 full_pc_wr bit21 */
			{    0, 0,2}, /* core0 full_pc_wr bit22 */
			{    0, 0,2}, /* core0 full_pc_wr bit23 */
			{    0, 0,2}, /* core0 full_pc_wr bit24 */
			{    0, 0,2}, /* core0 full_pc_wr bit25 */
			{    0, 0,2}, /* core0 full_pc_wr bit26 */
			{    0, 0,2}, /* core0 full_pc_wr bit27 */
			{    0, 0,2}, /* core0 full_pc_wr bit28 */
			{    0, 0,2}, /* core0 full_pc_wr bit29 */
			{    0, 0,2}, /* core0 full_pc_wr bit30 */
			{    0, 0,2}, /* core0 full_pc_wr bit31 */
			{    0, 0,2}, /* core0 full_pc_wr bit32 */
			{    0, 0,2}, /* core0 full_pc_wr bit33 */
			{    0, 0,2}, /* core0 full_pc_wr bit34 */
			{    0, 0,2}, /* core0 full_pc_wr bit35 */
			{    0, 0,2}, /* core0 full_pc_wr bit36 */
			{    0, 0,2}, /* core0 full_pc_wr bit37 */
			{    0, 0,2}, /* core0 full_pc_wr bit38 */
			{    0, 0,2}, /* core0 full_pc_wr bit39 */
			{    0, 0,2}, /* core0 full_pc_wr bit40 */
			{    0, 0,2}, /* core0 full_pc_wr bit41 */
			{    0, 0,2}, /* core0 full_pc_wr bit42 */
			{    0, 0,2}, /* core0 full_pc_wr bit43 */
			{    0, 0,2}, /* core0 full_pc_wr bit44 */
			{    0, 0,2}, /* core0 full_pc_wr bit45 */
			{    0, 0,2}, /* core0 full_pc_wr bit46 */
			{    0, 0,2}, /* core0 full_pc_wr bit47 */
			{    0, 0,2}, /* core0 full_pc_wr bit48 */
			{    0, 0,2}, /* core0 full_pc_wr bit49 */
			{    0, 0,2}, /* core0 full_pc_wr bit50 */
			{    0, 0,2}, /* core0 full_pc_wr bit51 */
			{    0, 0,2}, /* core0 full_pc_wr bit52 */
			{    0, 0,2}, /* core0 full_pc_wr bit53 */
			{    0, 0,2}, /* core0 full_pc_wr bit54 */
			{    0, 0,2}, /* core0 full_pc_wr bit55 */
			{    0, 0,2}, /* core0 full_pc_wr bit56 */
			{    0, 0,2}, /* core0 full_pc_wr bit57 */
			{    0, 0,2}, /* core0 full_pc_wr bit58 */
			{    0, 0,2}, /* core0 full_pc_wr bit59 */
			{    0, 0,2}, /* core0 full_pc_wr bit60 */
			{    0, 0,2}, /* core0 full_pc_wr bit61 */
			{    0, 0,2}, /* core0 full_pc_wr bit62 */
			{    0, 0,2}, /* core0 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{ 5400, 1,0}, /* core0 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{ 7406, 0,0}, /* core0 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{16329, 1,0}, /* core0 return_Stack_pointer bit0 */
			{14948, 1,0}, /* core0 return_Stack_pointer bit1 */
			{16328, 1,0}, /* core0 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{16729, 1,0}, /* core0 return_Stack0 bit0 */
			{16728, 1,0}, /* core0 return_Stack0 bit1 */
			{16727, 1,0}, /* core0 return_Stack0 bit2 */
			{16726, 1,0}, /* core0 return_Stack0 bit3 */
			{16721, 1,0}, /* core0 return_Stack0 bit4 */
			{16720, 1,0}, /* core0 return_Stack0 bit5 */
			{16719, 1,0}, /* core0 return_Stack0 bit6 */
			{16718, 1,0}, /* core0 return_Stack0 bit7 */
			{12983, 1,0}, /* core0 return_Stack0 bit8 */
			{12982, 1,0}, /* core0 return_Stack0 bit9 */
			{12981, 1,0}, /* core0 return_Stack0 bit10 */
			{12980, 1,0}, /* core0 return_Stack0 bit11 */
			{16789, 1,0}, /* core0 return_Stack0 bit12 */
			{16788, 1,0}, /* core0 return_Stack0 bit13 */
			{16787, 1,0}, /* core0 return_Stack0 bit14 */
			{16786, 1,0}, /* core0 return_Stack0 bit15 */
			{16725, 1,0}, /* core0 return_Stack0 bit16 */
			{16724, 1,0}, /* core0 return_Stack0 bit17 */
			{16723, 1,0}, /* core0 return_Stack0 bit18 */
			{16722, 1,0}, /* core0 return_Stack0 bit19 */
			{13019, 1,0}, /* core0 return_Stack0 bit20 */
			{13018, 1,0}, /* core0 return_Stack0 bit21 */
			{13017, 1,0}, /* core0 return_Stack0 bit22 */
			{13016, 1,0}, /* core0 return_Stack0 bit23 */
			{13092, 1,0}, /* core0 return_Stack0 bit24 */
			{13091, 1,0}, /* core0 return_Stack0 bit25 */
			{13090, 1,0}, /* core0 return_Stack0 bit26 */
			{13089, 1,0}, /* core0 return_Stack0 bit27 */
			{13040, 1,0}, /* core0 return_Stack0 bit28 */
			{13039, 1,0}, /* core0 return_Stack0 bit29 */
			{13038, 1,0}, /* core0 return_Stack0 bit30 */
			{13037, 1,0}, /* core0 return_Stack0 bit31 */
			{13052, 1,0}, /* core0 return_Stack0 bit32 */
			{13051, 1,0}, /* core0 return_Stack0 bit33 */
			{13050, 1,0}, /* core0 return_Stack0 bit34 */
			{13049, 1,0}, /* core0 return_Stack0 bit35 */
			{13072, 1,0}, /* core0 return_Stack0 bit36 */
			{13071, 1,0}, /* core0 return_Stack0 bit37 */
			{13070, 1,0}, /* core0 return_Stack0 bit38 */
			{13069, 1,0}, /* core0 return_Stack0 bit39 */
			{13064, 1,0}, /* core0 return_Stack0 bit40 */
			{13063, 1,0}, /* core0 return_Stack0 bit41 */
			{13062, 1,0}, /* core0 return_Stack0 bit42 */
			{13061, 1,0}, /* core0 return_Stack0 bit43 */
			{13068, 1,0}, /* core0 return_Stack0 bit44 */
			{13067, 1,0}, /* core0 return_Stack0 bit45 */
			{13066, 1,0}, /* core0 return_Stack0 bit46 */
			{13065, 1,0}, /* core0 return_Stack0 bit47 */
			{13036, 1,0}, /* core0 return_Stack0 bit48 */
			{    0, 0,2}, /* core0 return_Stack0 bit49 */
			{    0, 0,2}, /* core0 return_Stack0 bit50 */
			{    0, 0,2}, /* core0 return_Stack0 bit51 */
			{    0, 0,2}, /* core0 return_Stack0 bit52 */
			{    0, 0,2}, /* core0 return_Stack0 bit53 */
			{    0, 0,2}, /* core0 return_Stack0 bit54 */
			{    0, 0,2}, /* core0 return_Stack0 bit55 */
			{    0, 0,2}, /* core0 return_Stack0 bit56 */
			{    0, 0,2}, /* core0 return_Stack0 bit57 */
			{    0, 0,2}, /* core0 return_Stack0 bit58 */
			{    0, 0,2}, /* core0 return_Stack0 bit59 */
			{    0, 0,2}, /* core0 return_Stack0 bit60 */
			{    0, 0,2}, /* core0 return_Stack0 bit61 */
			{    0, 0,2}, /* core0 return_Stack0 bit62 */
			{    0, 0,2}, /* core0 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{16705, 1,0}, /* core0 return_Stack1 bit0 */
			{16704, 1,0}, /* core0 return_Stack1 bit1 */
			{16703, 1,0}, /* core0 return_Stack1 bit2 */
			{16702, 1,0}, /* core0 return_Stack1 bit3 */
			{16701, 1,0}, /* core0 return_Stack1 bit4 */
			{16700, 1,0}, /* core0 return_Stack1 bit5 */
			{16699, 1,0}, /* core0 return_Stack1 bit6 */
			{16698, 1,0}, /* core0 return_Stack1 bit7 */
			{12995, 1,0}, /* core0 return_Stack1 bit8 */
			{12994, 1,0}, /* core0 return_Stack1 bit9 */
			{12993, 1,0}, /* core0 return_Stack1 bit10 */
			{12992, 1,0}, /* core0 return_Stack1 bit11 */
			{16761, 1,0}, /* core0 return_Stack1 bit12 */
			{16760, 1,0}, /* core0 return_Stack1 bit13 */
			{16759, 1,0}, /* core0 return_Stack1 bit14 */
			{16758, 1,0}, /* core0 return_Stack1 bit15 */
			{16753, 1,0}, /* core0 return_Stack1 bit16 */
			{16752, 1,0}, /* core0 return_Stack1 bit17 */
			{16751, 1,0}, /* core0 return_Stack1 bit18 */
			{16750, 1,0}, /* core0 return_Stack1 bit19 */
			{16765, 1,0}, /* core0 return_Stack1 bit20 */
			{16764, 1,0}, /* core0 return_Stack1 bit21 */
			{16763, 1,0}, /* core0 return_Stack1 bit22 */
			{16762, 1,0}, /* core0 return_Stack1 bit23 */
			{16773, 1,0}, /* core0 return_Stack1 bit24 */
			{16772, 1,0}, /* core0 return_Stack1 bit25 */
			{16771, 1,0}, /* core0 return_Stack1 bit26 */
			{16770, 1,0}, /* core0 return_Stack1 bit27 */
			{16777, 1,0}, /* core0 return_Stack1 bit28 */
			{16776, 1,0}, /* core0 return_Stack1 bit29 */
			{16775, 1,0}, /* core0 return_Stack1 bit30 */
			{16774, 1,0}, /* core0 return_Stack1 bit31 */
			{12963, 1,0}, /* core0 return_Stack1 bit32 */
			{12962, 1,0}, /* core0 return_Stack1 bit33 */
			{12961, 1,0}, /* core0 return_Stack1 bit34 */
			{12960, 1,0}, /* core0 return_Stack1 bit35 */
			{12929, 1,0}, /* core0 return_Stack1 bit36 */
			{12928, 1,0}, /* core0 return_Stack1 bit37 */
			{12927, 1,0}, /* core0 return_Stack1 bit38 */
			{12926, 1,0}, /* core0 return_Stack1 bit39 */
			{12941, 1,0}, /* core0 return_Stack1 bit40 */
			{12940, 1,0}, /* core0 return_Stack1 bit41 */
			{12939, 1,0}, /* core0 return_Stack1 bit42 */
			{12938, 1,0}, /* core0 return_Stack1 bit43 */
			{12937, 1,0}, /* core0 return_Stack1 bit44 */
			{12936, 1,0}, /* core0 return_Stack1 bit45 */
			{12935, 1,0}, /* core0 return_Stack1 bit46 */
			{12934, 1,0}, /* core0 return_Stack1 bit47 */
			{14950, 1,0}, /* core0 return_Stack1 bit48 */
			{    0, 0,2}, /* core0 return_Stack1 bit49 */
			{    0, 0,2}, /* core0 return_Stack1 bit50 */
			{    0, 0,2}, /* core0 return_Stack1 bit51 */
			{    0, 0,2}, /* core0 return_Stack1 bit52 */
			{    0, 0,2}, /* core0 return_Stack1 bit53 */
			{    0, 0,2}, /* core0 return_Stack1 bit54 */
			{    0, 0,2}, /* core0 return_Stack1 bit55 */
			{    0, 0,2}, /* core0 return_Stack1 bit56 */
			{    0, 0,2}, /* core0 return_Stack1 bit57 */
			{    0, 0,2}, /* core0 return_Stack1 bit58 */
			{    0, 0,2}, /* core0 return_Stack1 bit59 */
			{    0, 0,2}, /* core0 return_Stack1 bit60 */
			{    0, 0,2}, /* core0 return_Stack1 bit61 */
			{    0, 0,2}, /* core0 return_Stack1 bit62 */
			{    0, 0,2}, /* core0 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{12987, 1,0}, /* core0 return_Stack2 bit0 */
			{12986, 1,0}, /* core0 return_Stack2 bit1 */
			{12985, 1,0}, /* core0 return_Stack2 bit2 */
			{12984, 1,0}, /* core0 return_Stack2 bit3 */
			{16669, 1,0}, /* core0 return_Stack2 bit4 */
			{16668, 1,0}, /* core0 return_Stack2 bit5 */
			{16667, 1,0}, /* core0 return_Stack2 bit6 */
			{16666, 1,0}, /* core0 return_Stack2 bit7 */
			{16685, 1,0}, /* core0 return_Stack2 bit8 */
			{16684, 1,0}, /* core0 return_Stack2 bit9 */
			{16683, 1,0}, /* core0 return_Stack2 bit10 */
			{16682, 1,0}, /* core0 return_Stack2 bit11 */
			{16677, 1,0}, /* core0 return_Stack2 bit12 */
			{16676, 1,0}, /* core0 return_Stack2 bit13 */
			{16675, 1,0}, /* core0 return_Stack2 bit14 */
			{16674, 1,0}, /* core0 return_Stack2 bit15 */
			{16673, 1,0}, /* core0 return_Stack2 bit16 */
			{16672, 1,0}, /* core0 return_Stack2 bit17 */
			{16671, 1,0}, /* core0 return_Stack2 bit18 */
			{16670, 1,0}, /* core0 return_Stack2 bit19 */
			{16657, 1,0}, /* core0 return_Stack2 bit20 */
			{16656, 1,0}, /* core0 return_Stack2 bit21 */
			{16655, 1,0}, /* core0 return_Stack2 bit22 */
			{16654, 1,0}, /* core0 return_Stack2 bit23 */
			{16653, 1,0}, /* core0 return_Stack2 bit24 */
			{16652, 1,0}, /* core0 return_Stack2 bit25 */
			{16651, 1,0}, /* core0 return_Stack2 bit26 */
			{16650, 1,0}, /* core0 return_Stack2 bit27 */
			{16645, 1,0}, /* core0 return_Stack2 bit28 */
			{16644, 1,0}, /* core0 return_Stack2 bit29 */
			{16643, 1,0}, /* core0 return_Stack2 bit30 */
			{16642, 1,0}, /* core0 return_Stack2 bit31 */
			{16633, 1,0}, /* core0 return_Stack2 bit32 */
			{16632, 1,0}, /* core0 return_Stack2 bit33 */
			{16631, 1,0}, /* core0 return_Stack2 bit34 */
			{16630, 1,0}, /* core0 return_Stack2 bit35 */
			{16625, 1,0}, /* core0 return_Stack2 bit36 */
			{16624, 1,0}, /* core0 return_Stack2 bit37 */
			{16623, 1,0}, /* core0 return_Stack2 bit38 */
			{16622, 1,0}, /* core0 return_Stack2 bit39 */
			{16629, 1,0}, /* core0 return_Stack2 bit40 */
			{16628, 1,0}, /* core0 return_Stack2 bit41 */
			{16627, 1,0}, /* core0 return_Stack2 bit42 */
			{16626, 1,0}, /* core0 return_Stack2 bit43 */
			{16637, 1,0}, /* core0 return_Stack2 bit44 */
			{16636, 1,0}, /* core0 return_Stack2 bit45 */
			{16635, 1,0}, /* core0 return_Stack2 bit46 */
			{16634, 1,0}, /* core0 return_Stack2 bit47 */
			{14952, 1,0}, /* core0 return_Stack2 bit48 */
			{    0, 0,2}, /* core0 return_Stack2 bit49 */
			{    0, 0,2}, /* core0 return_Stack2 bit50 */
			{    0, 0,2}, /* core0 return_Stack2 bit51 */
			{    0, 0,2}, /* core0 return_Stack2 bit52 */
			{    0, 0,2}, /* core0 return_Stack2 bit53 */
			{    0, 0,2}, /* core0 return_Stack2 bit54 */
			{    0, 0,2}, /* core0 return_Stack2 bit55 */
			{    0, 0,2}, /* core0 return_Stack2 bit56 */
			{    0, 0,2}, /* core0 return_Stack2 bit57 */
			{    0, 0,2}, /* core0 return_Stack2 bit58 */
			{    0, 0,2}, /* core0 return_Stack2 bit59 */
			{    0, 0,2}, /* core0 return_Stack2 bit60 */
			{    0, 0,2}, /* core0 return_Stack2 bit61 */
			{    0, 0,2}, /* core0 return_Stack2 bit62 */
			{    0, 0,2}, /* core0 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{16697, 1,0}, /* core0 return_Stack3 bit0 */
			{16696, 1,0}, /* core0 return_Stack3 bit1 */
			{16695, 1,0}, /* core0 return_Stack3 bit2 */
			{16694, 1,0}, /* core0 return_Stack3 bit3 */
			{16665, 1,0}, /* core0 return_Stack3 bit4 */
			{16664, 1,0}, /* core0 return_Stack3 bit5 */
			{16663, 1,0}, /* core0 return_Stack3 bit6 */
			{16662, 1,0}, /* core0 return_Stack3 bit7 */
			{16693, 1,0}, /* core0 return_Stack3 bit8 */
			{16692, 1,0}, /* core0 return_Stack3 bit9 */
			{16691, 1,0}, /* core0 return_Stack3 bit10 */
			{16690, 1,0}, /* core0 return_Stack3 bit11 */
			{16681, 1,0}, /* core0 return_Stack3 bit12 */
			{16680, 1,0}, /* core0 return_Stack3 bit13 */
			{16679, 1,0}, /* core0 return_Stack3 bit14 */
			{16678, 1,0}, /* core0 return_Stack3 bit15 */
			{16689, 1,0}, /* core0 return_Stack3 bit16 */
			{16688, 1,0}, /* core0 return_Stack3 bit17 */
			{16687, 1,0}, /* core0 return_Stack3 bit18 */
			{16686, 1,0}, /* core0 return_Stack3 bit19 */
			{16661, 1,0}, /* core0 return_Stack3 bit20 */
			{16660, 1,0}, /* core0 return_Stack3 bit21 */
			{16659, 1,0}, /* core0 return_Stack3 bit22 */
			{16658, 1,0}, /* core0 return_Stack3 bit23 */
			{16641, 1,0}, /* core0 return_Stack3 bit24 */
			{16640, 1,0}, /* core0 return_Stack3 bit25 */
			{16639, 1,0}, /* core0 return_Stack3 bit26 */
			{16638, 1,0}, /* core0 return_Stack3 bit27 */
			{16649, 1,0}, /* core0 return_Stack3 bit28 */
			{16648, 1,0}, /* core0 return_Stack3 bit29 */
			{16647, 1,0}, /* core0 return_Stack3 bit30 */
			{16646, 1,0}, /* core0 return_Stack3 bit31 */
			{12959, 1,0}, /* core0 return_Stack3 bit32 */
			{12958, 1,0}, /* core0 return_Stack3 bit33 */
			{12957, 1,0}, /* core0 return_Stack3 bit34 */
			{12956, 1,0}, /* core0 return_Stack3 bit35 */
			{12951, 1,0}, /* core0 return_Stack3 bit36 */
			{12950, 1,0}, /* core0 return_Stack3 bit37 */
			{12949, 1,0}, /* core0 return_Stack3 bit38 */
			{12948, 1,0}, /* core0 return_Stack3 bit39 */
			{12945, 1,0}, /* core0 return_Stack3 bit40 */
			{12944, 1,0}, /* core0 return_Stack3 bit41 */
			{12943, 1,0}, /* core0 return_Stack3 bit42 */
			{12942, 1,0}, /* core0 return_Stack3 bit43 */
			{12955, 1,0}, /* core0 return_Stack3 bit44 */
			{12954, 1,0}, /* core0 return_Stack3 bit45 */
			{12953, 1,0}, /* core0 return_Stack3 bit46 */
			{12952, 1,0}, /* core0 return_Stack3 bit47 */
			{14949, 1,0}, /* core0 return_Stack3 bit48 */
			{    0, 0,2}, /* core0 return_Stack3 bit49 */
			{    0, 0,2}, /* core0 return_Stack3 bit50 */
			{    0, 0,2}, /* core0 return_Stack3 bit51 */
			{    0, 0,2}, /* core0 return_Stack3 bit52 */
			{    0, 0,2}, /* core0 return_Stack3 bit53 */
			{    0, 0,2}, /* core0 return_Stack3 bit54 */
			{    0, 0,2}, /* core0 return_Stack3 bit55 */
			{    0, 0,2}, /* core0 return_Stack3 bit56 */
			{    0, 0,2}, /* core0 return_Stack3 bit57 */
			{    0, 0,2}, /* core0 return_Stack3 bit58 */
			{    0, 0,2}, /* core0 return_Stack3 bit59 */
			{    0, 0,2}, /* core0 return_Stack3 bit60 */
			{    0, 0,2}, /* core0 return_Stack3 bit61 */
			{    0, 0,2}, /* core0 return_Stack3 bit62 */
			{    0, 0,2}, /* core0 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{13011, 1,0}, /* core0 return_Stack4 bit0 */
			{13010, 1,0}, /* core0 return_Stack4 bit1 */
			{13009, 1,0}, /* core0 return_Stack4 bit2 */
			{13008, 1,0}, /* core0 return_Stack4 bit3 */
			{13003, 1,0}, /* core0 return_Stack4 bit4 */
			{13002, 1,0}, /* core0 return_Stack4 bit5 */
			{13001, 1,0}, /* core0 return_Stack4 bit6 */
			{13000, 1,0}, /* core0 return_Stack4 bit7 */
			{12979, 1,0}, /* core0 return_Stack4 bit8 */
			{12978, 1,0}, /* core0 return_Stack4 bit9 */
			{12977, 1,0}, /* core0 return_Stack4 bit10 */
			{12976, 1,0}, /* core0 return_Stack4 bit11 */
			{12975, 1,0}, /* core0 return_Stack4 bit12 */
			{12974, 1,0}, /* core0 return_Stack4 bit13 */
			{12973, 1,0}, /* core0 return_Stack4 bit14 */
			{12972, 1,0}, /* core0 return_Stack4 bit15 */
			{13015, 1,0}, /* core0 return_Stack4 bit16 */
			{13014, 1,0}, /* core0 return_Stack4 bit17 */
			{13013, 1,0}, /* core0 return_Stack4 bit18 */
			{13012, 1,0}, /* core0 return_Stack4 bit19 */
			{13023, 1,0}, /* core0 return_Stack4 bit20 */
			{13022, 1,0}, /* core0 return_Stack4 bit21 */
			{13021, 1,0}, /* core0 return_Stack4 bit22 */
			{13020, 1,0}, /* core0 return_Stack4 bit23 */
			{13088, 1,0}, /* core0 return_Stack4 bit24 */
			{13087, 1,0}, /* core0 return_Stack4 bit25 */
			{13086, 1,0}, /* core0 return_Stack4 bit26 */
			{13085, 1,0}, /* core0 return_Stack4 bit27 */
			{16309, 1,0}, /* core0 return_Stack4 bit28 */
			{16308, 1,0}, /* core0 return_Stack4 bit29 */
			{16307, 1,0}, /* core0 return_Stack4 bit30 */
			{16306, 1,0}, /* core0 return_Stack4 bit31 */
			{13080, 1,0}, /* core0 return_Stack4 bit32 */
			{13079, 1,0}, /* core0 return_Stack4 bit33 */
			{13078, 1,0}, /* core0 return_Stack4 bit34 */
			{13077, 1,0}, /* core0 return_Stack4 bit35 */
			{18841, 0,0}, /* core0 return_Stack4 bit36 */
			{18840, 0,0}, /* core0 return_Stack4 bit37 */
			{18839, 0,0}, /* core0 return_Stack4 bit38 */
			{18838, 0,0}, /* core0 return_Stack4 bit39 */
			{18837, 0,0}, /* core0 return_Stack4 bit40 */
			{18836, 0,0}, /* core0 return_Stack4 bit41 */
			{18835, 0,0}, /* core0 return_Stack4 bit42 */
			{18834, 0,0}, /* core0 return_Stack4 bit43 */
			{18845, 0,0}, /* core0 return_Stack4 bit44 */
			{18844, 0,0}, /* core0 return_Stack4 bit45 */
			{18843, 0,0}, /* core0 return_Stack4 bit46 */
			{18842, 0,0}, /* core0 return_Stack4 bit47 */
			{14567, 1,0}, /* core0 return_Stack4 bit48 */
			{    0, 0,2}, /* core0 return_Stack4 bit49 */
			{    0, 0,2}, /* core0 return_Stack4 bit50 */
			{    0, 0,2}, /* core0 return_Stack4 bit51 */
			{    0, 0,2}, /* core0 return_Stack4 bit52 */
			{    0, 0,2}, /* core0 return_Stack4 bit53 */
			{    0, 0,2}, /* core0 return_Stack4 bit54 */
			{    0, 0,2}, /* core0 return_Stack4 bit55 */
			{    0, 0,2}, /* core0 return_Stack4 bit56 */
			{    0, 0,2}, /* core0 return_Stack4 bit57 */
			{    0, 0,2}, /* core0 return_Stack4 bit58 */
			{    0, 0,2}, /* core0 return_Stack4 bit59 */
			{    0, 0,2}, /* core0 return_Stack4 bit60 */
			{    0, 0,2}, /* core0 return_Stack4 bit61 */
			{    0, 0,2}, /* core0 return_Stack4 bit62 */
			{    0, 0,2}, /* core0 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{16717, 1,0}, /* core0 return_Stack5 bit0 */
			{16716, 1,0}, /* core0 return_Stack5 bit1 */
			{16715, 1,0}, /* core0 return_Stack5 bit2 */
			{16714, 1,0}, /* core0 return_Stack5 bit3 */
			{16709, 1,0}, /* core0 return_Stack5 bit4 */
			{16708, 1,0}, /* core0 return_Stack5 bit5 */
			{16707, 1,0}, /* core0 return_Stack5 bit6 */
			{16706, 1,0}, /* core0 return_Stack5 bit7 */
			{12991, 1,0}, /* core0 return_Stack5 bit8 */
			{12990, 1,0}, /* core0 return_Stack5 bit9 */
			{12989, 1,0}, /* core0 return_Stack5 bit10 */
			{12988, 1,0}, /* core0 return_Stack5 bit11 */
			{16757, 1,0}, /* core0 return_Stack5 bit12 */
			{16756, 1,0}, /* core0 return_Stack5 bit13 */
			{16755, 1,0}, /* core0 return_Stack5 bit14 */
			{16754, 1,0}, /* core0 return_Stack5 bit15 */
			{16749, 1,0}, /* core0 return_Stack5 bit16 */
			{16748, 1,0}, /* core0 return_Stack5 bit17 */
			{16747, 1,0}, /* core0 return_Stack5 bit18 */
			{16746, 1,0}, /* core0 return_Stack5 bit19 */
			{16769, 1,0}, /* core0 return_Stack5 bit20 */
			{16768, 1,0}, /* core0 return_Stack5 bit21 */
			{16767, 1,0}, /* core0 return_Stack5 bit22 */
			{16766, 1,0}, /* core0 return_Stack5 bit23 */
			{12971, 1,0}, /* core0 return_Stack5 bit24 */
			{12970, 1,0}, /* core0 return_Stack5 bit25 */
			{12969, 1,0}, /* core0 return_Stack5 bit26 */
			{12968, 1,0}, /* core0 return_Stack5 bit27 */
			{12967, 1,0}, /* core0 return_Stack5 bit28 */
			{12966, 1,0}, /* core0 return_Stack5 bit29 */
			{12965, 1,0}, /* core0 return_Stack5 bit30 */
			{12964, 1,0}, /* core0 return_Stack5 bit31 */
			{13056, 1,0}, /* core0 return_Stack5 bit32 */
			{13055, 1,0}, /* core0 return_Stack5 bit33 */
			{13054, 1,0}, /* core0 return_Stack5 bit34 */
			{13053, 1,0}, /* core0 return_Stack5 bit35 */
			{12925, 1,0}, /* core0 return_Stack5 bit36 */
			{12924, 1,0}, /* core0 return_Stack5 bit37 */
			{12923, 1,0}, /* core0 return_Stack5 bit38 */
			{12922, 1,0}, /* core0 return_Stack5 bit39 */
			{12921, 1,0}, /* core0 return_Stack5 bit40 */
			{12920, 1,0}, /* core0 return_Stack5 bit41 */
			{12919, 1,0}, /* core0 return_Stack5 bit42 */
			{12918, 1,0}, /* core0 return_Stack5 bit43 */
			{12933, 1,0}, /* core0 return_Stack5 bit44 */
			{12932, 1,0}, /* core0 return_Stack5 bit45 */
			{12931, 1,0}, /* core0 return_Stack5 bit46 */
			{12930, 1,0}, /* core0 return_Stack5 bit47 */
			{14951, 1,0}, /* core0 return_Stack5 bit48 */
			{    0, 0,2}, /* core0 return_Stack5 bit49 */
			{    0, 0,2}, /* core0 return_Stack5 bit50 */
			{    0, 0,2}, /* core0 return_Stack5 bit51 */
			{    0, 0,2}, /* core0 return_Stack5 bit52 */
			{    0, 0,2}, /* core0 return_Stack5 bit53 */
			{    0, 0,2}, /* core0 return_Stack5 bit54 */
			{    0, 0,2}, /* core0 return_Stack5 bit55 */
			{    0, 0,2}, /* core0 return_Stack5 bit56 */
			{    0, 0,2}, /* core0 return_Stack5 bit57 */
			{    0, 0,2}, /* core0 return_Stack5 bit58 */
			{    0, 0,2}, /* core0 return_Stack5 bit59 */
			{    0, 0,2}, /* core0 return_Stack5 bit60 */
			{    0, 0,2}, /* core0 return_Stack5 bit61 */
			{    0, 0,2}, /* core0 return_Stack5 bit62 */
			{    0, 0,2}, /* core0 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{16737, 1,0}, /* core0 return_Stack6 bit0 */
			{16736, 1,0}, /* core0 return_Stack6 bit1 */
			{16735, 1,0}, /* core0 return_Stack6 bit2 */
			{16734, 1,0}, /* core0 return_Stack6 bit3 */
			{13007, 1,0}, /* core0 return_Stack6 bit4 */
			{13006, 1,0}, /* core0 return_Stack6 bit5 */
			{13005, 1,0}, /* core0 return_Stack6 bit6 */
			{13004, 1,0}, /* core0 return_Stack6 bit7 */
			{12999, 1,0}, /* core0 return_Stack6 bit8 */
			{12998, 1,0}, /* core0 return_Stack6 bit9 */
			{12997, 1,0}, /* core0 return_Stack6 bit10 */
			{12996, 1,0}, /* core0 return_Stack6 bit11 */
			{16781, 1,0}, /* core0 return_Stack6 bit12 */
			{16780, 1,0}, /* core0 return_Stack6 bit13 */
			{16779, 1,0}, /* core0 return_Stack6 bit14 */
			{16778, 1,0}, /* core0 return_Stack6 bit15 */
			{16793, 1,0}, /* core0 return_Stack6 bit16 */
			{16792, 1,0}, /* core0 return_Stack6 bit17 */
			{16791, 1,0}, /* core0 return_Stack6 bit18 */
			{16790, 1,0}, /* core0 return_Stack6 bit19 */
			{13027, 1,0}, /* core0 return_Stack6 bit20 */
			{13026, 1,0}, /* core0 return_Stack6 bit21 */
			{13025, 1,0}, /* core0 return_Stack6 bit22 */
			{13024, 1,0}, /* core0 return_Stack6 bit23 */
			{13096, 1,0}, /* core0 return_Stack6 bit24 */
			{13095, 1,0}, /* core0 return_Stack6 bit25 */
			{13094, 1,0}, /* core0 return_Stack6 bit26 */
			{13093, 1,0}, /* core0 return_Stack6 bit27 */
			{13031, 1,0}, /* core0 return_Stack6 bit28 */
			{13030, 1,0}, /* core0 return_Stack6 bit29 */
			{13029, 1,0}, /* core0 return_Stack6 bit30 */
			{13028, 1,0}, /* core0 return_Stack6 bit31 */
			{13048, 1,0}, /* core0 return_Stack6 bit32 */
			{13047, 1,0}, /* core0 return_Stack6 bit33 */
			{13046, 1,0}, /* core0 return_Stack6 bit34 */
			{13045, 1,0}, /* core0 return_Stack6 bit35 */
			{13084, 1,0}, /* core0 return_Stack6 bit36 */
			{13083, 1,0}, /* core0 return_Stack6 bit37 */
			{13082, 1,0}, /* core0 return_Stack6 bit38 */
			{13081, 1,0}, /* core0 return_Stack6 bit39 */
			{12909, 1,0}, /* core0 return_Stack6 bit40 */
			{12908, 1,0}, /* core0 return_Stack6 bit41 */
			{12907, 1,0}, /* core0 return_Stack6 bit42 */
			{12906, 1,0}, /* core0 return_Stack6 bit43 */
			{13076, 1,0}, /* core0 return_Stack6 bit44 */
			{13075, 1,0}, /* core0 return_Stack6 bit45 */
			{13074, 1,0}, /* core0 return_Stack6 bit46 */
			{13073, 1,0}, /* core0 return_Stack6 bit47 */
			{14568, 1,0}, /* core0 return_Stack6 bit48 */
			{    0, 0,2}, /* core0 return_Stack6 bit49 */
			{    0, 0,2}, /* core0 return_Stack6 bit50 */
			{    0, 0,2}, /* core0 return_Stack6 bit51 */
			{    0, 0,2}, /* core0 return_Stack6 bit52 */
			{    0, 0,2}, /* core0 return_Stack6 bit53 */
			{    0, 0,2}, /* core0 return_Stack6 bit54 */
			{    0, 0,2}, /* core0 return_Stack6 bit55 */
			{    0, 0,2}, /* core0 return_Stack6 bit56 */
			{    0, 0,2}, /* core0 return_Stack6 bit57 */
			{    0, 0,2}, /* core0 return_Stack6 bit58 */
			{    0, 0,2}, /* core0 return_Stack6 bit59 */
			{    0, 0,2}, /* core0 return_Stack6 bit60 */
			{    0, 0,2}, /* core0 return_Stack6 bit61 */
			{    0, 0,2}, /* core0 return_Stack6 bit62 */
			{    0, 0,2}, /* core0 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{16733, 1,0}, /* core0 return_Stack7 bit0 */
			{16732, 1,0}, /* core0 return_Stack7 bit1 */
			{16731, 1,0}, /* core0 return_Stack7 bit2 */
			{16730, 1,0}, /* core0 return_Stack7 bit3 */
			{16713, 1,0}, /* core0 return_Stack7 bit4 */
			{16712, 1,0}, /* core0 return_Stack7 bit5 */
			{16711, 1,0}, /* core0 return_Stack7 bit6 */
			{16710, 1,0}, /* core0 return_Stack7 bit7 */
			{16745, 1,0}, /* core0 return_Stack7 bit8 */
			{16744, 1,0}, /* core0 return_Stack7 bit9 */
			{16743, 1,0}, /* core0 return_Stack7 bit10 */
			{16742, 1,0}, /* core0 return_Stack7 bit11 */
			{16785, 1,0}, /* core0 return_Stack7 bit12 */
			{16784, 1,0}, /* core0 return_Stack7 bit13 */
			{16783, 1,0}, /* core0 return_Stack7 bit14 */
			{16782, 1,0}, /* core0 return_Stack7 bit15 */
			{16741, 1,0}, /* core0 return_Stack7 bit16 */
			{16740, 1,0}, /* core0 return_Stack7 bit17 */
			{16739, 1,0}, /* core0 return_Stack7 bit18 */
			{16738, 1,0}, /* core0 return_Stack7 bit19 */
			{16801, 1,0}, /* core0 return_Stack7 bit20 */
			{16800, 1,0}, /* core0 return_Stack7 bit21 */
			{16799, 1,0}, /* core0 return_Stack7 bit22 */
			{16798, 1,0}, /* core0 return_Stack7 bit23 */
			{16797, 1,0}, /* core0 return_Stack7 bit24 */
			{16796, 1,0}, /* core0 return_Stack7 bit25 */
			{16795, 1,0}, /* core0 return_Stack7 bit26 */
			{16794, 1,0}, /* core0 return_Stack7 bit27 */
			{13035, 1,0}, /* core0 return_Stack7 bit28 */
			{13034, 1,0}, /* core0 return_Stack7 bit29 */
			{13033, 1,0}, /* core0 return_Stack7 bit30 */
			{13032, 1,0}, /* core0 return_Stack7 bit31 */
			{13044, 1,0}, /* core0 return_Stack7 bit32 */
			{13043, 1,0}, /* core0 return_Stack7 bit33 */
			{13042, 1,0}, /* core0 return_Stack7 bit34 */
			{13041, 1,0}, /* core0 return_Stack7 bit35 */
			{12913, 1,0}, /* core0 return_Stack7 bit36 */
			{12912, 1,0}, /* core0 return_Stack7 bit37 */
			{12911, 1,0}, /* core0 return_Stack7 bit38 */
			{12910, 1,0}, /* core0 return_Stack7 bit39 */
			{12917, 1,0}, /* core0 return_Stack7 bit40 */
			{12916, 1,0}, /* core0 return_Stack7 bit41 */
			{12915, 1,0}, /* core0 return_Stack7 bit42 */
			{12914, 1,0}, /* core0 return_Stack7 bit43 */
			{13060, 1,0}, /* core0 return_Stack7 bit44 */
			{13059, 1,0}, /* core0 return_Stack7 bit45 */
			{13058, 1,0}, /* core0 return_Stack7 bit46 */
			{13057, 1,0}, /* core0 return_Stack7 bit47 */
			{14569, 1,0}, /* core0 return_Stack7 bit48 */
			{    0, 0,2}, /* core0 return_Stack7 bit49 */
			{    0, 0,2}, /* core0 return_Stack7 bit50 */
			{    0, 0,2}, /* core0 return_Stack7 bit51 */
			{    0, 0,2}, /* core0 return_Stack7 bit52 */
			{    0, 0,2}, /* core0 return_Stack7 bit53 */
			{    0, 0,2}, /* core0 return_Stack7 bit54 */
			{    0, 0,2}, /* core0 return_Stack7 bit55 */
			{    0, 0,2}, /* core0 return_Stack7 bit56 */
			{    0, 0,2}, /* core0 return_Stack7 bit57 */
			{    0, 0,2}, /* core0 return_Stack7 bit58 */
			{    0, 0,2}, /* core0 return_Stack7 bit59 */
			{    0, 0,2}, /* core0 return_Stack7 bit60 */
			{    0, 0,2}, /* core0 return_Stack7 bit61 */
			{    0, 0,2}, /* core0 return_Stack7 bit62 */
			{    0, 0,2}, /* core0 return_Stack7 bit63 */
			}},
	},
	{		/* core 1 */
			.pc = {{
			{   37, 2,0}, /* core1 pc bit0 */
			{  105, 2,0}, /* core1 pc bit1 */
			{   28, 2,0}, /* core1 pc bit2 */
			{   67, 2,0}, /* core1 pc bit3 */
			{   66, 2,0}, /* core1 pc bit4 */
			{   65, 2,0}, /* core1 pc bit5 */
			{  104, 2,0}, /* core1 pc bit6 */
			{   34, 2,0}, /* core1 pc bit7 */
			{   33, 2,0}, /* core1 pc bit8 */
			{   32, 2,0}, /* core1 pc bit9 */
			{   55, 2,0}, /* core1 pc bit10 */
			{   54, 2,0}, /* core1 pc bit11 */
			{   53, 2,0}, /* core1 pc bit12 */
			{   52, 2,0}, /* core1 pc bit13 */
			{   36, 2,0}, /* core1 pc bit14 */
			{   51, 2,0}, /* core1 pc bit15 */
			{   50, 2,0}, /* core1 pc bit16 */
			{   49, 2,0}, /* core1 pc bit17 */
			{   48, 2,0}, /* core1 pc bit18 */
			{ 2483, 2,0}, /* core1 pc bit19 */
			{   64, 2,0}, /* core1 pc bit20 */
			{   43, 2,0}, /* core1 pc bit21 */
			{   42, 2,0}, /* core1 pc bit22 */
			{   41, 2,0}, /* core1 pc bit23 */
			{   40, 2,0}, /* core1 pc bit24 */
			{   47, 2,0}, /* core1 pc bit25 */
			{   46, 2,0}, /* core1 pc bit26 */
			{   45, 2,0}, /* core1 pc bit27 */
			{   44, 2,0}, /* core1 pc bit28 */
			{ 2479, 2,0}, /* core1 pc bit29 */
			{ 2478, 2,0}, /* core1 pc bit30 */
			{  119, 2,0}, /* core1 pc bit31 */
			{12041, 2,0}, /* core1 pc bit32 */
			{12040, 2,0}, /* core1 pc bit33 */
			{12039, 2,0}, /* core1 pc bit34 */
			{12038, 2,0}, /* core1 pc bit35 */
			{10951, 2,0}, /* core1 pc bit36 */
			{10950, 2,0}, /* core1 pc bit37 */
			{10949, 2,0}, /* core1 pc bit38 */
			{10948, 2,0}, /* core1 pc bit39 */
			{  146, 2,0}, /* core1 pc bit40 */
			{12113, 2,0}, /* core1 pc bit41 */
			{10955, 2,0}, /* core1 pc bit42 */
			{  145, 2,0}, /* core1 pc bit43 */
			{10954, 2,0}, /* core1 pc bit44 */
			{10953, 2,0}, /* core1 pc bit45 */
			{10952, 2,0}, /* core1 pc bit46 */
			{12105, 2,0}, /* core1 pc bit47 */
			{  144, 2,0}, /* core1 pc bit48 */
			{12104, 2,0}, /* core1 pc bit49 */
			{12103, 2,0}, /* core1 pc bit50 */
			{12112, 2,0}, /* core1 pc bit51 */
			{12111, 2,0}, /* core1 pc bit52 */
			{12102, 2,0}, /* core1 pc bit53 */
			{12109, 2,0}, /* core1 pc bit54 */
			{12108, 2,0}, /* core1 pc bit55 */
			{12107, 2,0}, /* core1 pc bit56 */
			{12106, 2,0}, /* core1 pc bit57 */
			{10959, 2,0}, /* core1 pc bit58 */
			{10958, 2,0}, /* core1 pc bit59 */
			{12110, 2,0}, /* core1 pc bit60 */
			{10957, 2,0}, /* core1 pc bit61 */
			{10956, 2,0}, /* core1 pc bit62 */
			{ 2717, 2,0}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{  221, 3,0}, /* core1 sp32 bit0 */
			{  191, 3,0}, /* core1 sp32 bit1 */
			{  117, 3,0}, /* core1 sp32 bit2 */
			{  113, 3,0}, /* core1 sp32 bit3 */
			{  111, 3,0}, /* core1 sp32 bit4 */
			{   71, 3,0}, /* core1 sp32 bit5 */
			{  123, 3,0}, /* core1 sp32 bit6 */
			{  114, 3,0}, /* core1 sp32 bit7 */
			{  119, 3,0}, /* core1 sp32 bit8 */
			{  107, 3,0}, /* core1 sp32 bit9 */
			{   14, 3,0}, /* core1 sp32 bit10 */
			{  124, 3,0}, /* core1 sp32 bit11 */
			{   72, 3,0}, /* core1 sp32 bit12 */
			{  121, 3,0}, /* core1 sp32 bit13 */
			{   70, 3,0}, /* core1 sp32 bit14 */
			{  112, 3,0}, /* core1 sp32 bit15 */
			{  122, 3,0}, /* core1 sp32 bit16 */
			{  192, 3,0}, /* core1 sp32 bit17 */
			{  118, 3,0}, /* core1 sp32 bit18 */
			{  120, 3,0}, /* core1 sp32 bit19 */
			{  131, 3,0}, /* core1 sp32 bit20 */
			{   15, 3,0}, /* core1 sp32 bit21 */
			{  125, 3,0}, /* core1 sp32 bit22 */
			{  115, 3,0}, /* core1 sp32 bit23 */
			{  132, 3,0}, /* core1 sp32 bit24 */
			{   11, 3,0}, /* core1 sp32 bit25 */
			{   17, 3,0}, /* core1 sp32 bit26 */
			{   10, 3,0}, /* core1 sp32 bit27 */
			{  158, 3,0}, /* core1 sp32 bit28 */
			{   16, 3,0}, /* core1 sp32 bit29 */
			{  194, 3,0}, /* core1 sp32 bit30 */
			{  175, 3,0}, /* core1 sp32 bit31 */
			{ 2071, 3,0}, /* core1 sp32 bit32 */
			{ 2072, 3,0}, /* core1 sp32 bit33 */
			{ 2075, 3,0}, /* core1 sp32 bit34 */
			{ 2059, 3,0}, /* core1 sp32 bit35 */
			{ 2077, 3,0}, /* core1 sp32 bit36 */
			{ 2073, 3,0}, /* core1 sp32 bit37 */
			{ 1999, 3,0}, /* core1 sp32 bit38 */
			{ 2074, 3,0}, /* core1 sp32 bit39 */
			{ 2016, 3,0}, /* core1 sp32 bit40 */
			{ 2000, 3,0}, /* core1 sp32 bit41 */
			{ 1997, 3,0}, /* core1 sp32 bit42 */
			{ 1996, 3,0}, /* core1 sp32 bit43 */
			{ 1998, 3,0}, /* core1 sp32 bit44 */
			{ 1991, 3,0}, /* core1 sp32 bit45 */
			{ 2007, 3,0}, /* core1 sp32 bit46 */
			{ 2316, 3,0}, /* core1 sp32 bit47 */
			{ 7943, 2,0}, /* core1 sp32 bit48 */
			{ 7946, 2,0}, /* core1 sp32 bit49 */
			{ 7975, 2,0}, /* core1 sp32 bit50 */
			{ 7952, 2,0}, /* core1 sp32 bit51 */
			{ 7950, 2,0}, /* core1 sp32 bit52 */
			{ 7944, 2,0}, /* core1 sp32 bit53 */
			{ 7947, 2,0}, /* core1 sp32 bit54 */
			{ 7976, 2,0}, /* core1 sp32 bit55 */
			{ 7949, 2,0}, /* core1 sp32 bit56 */
			{ 7953, 2,0}, /* core1 sp32 bit57 */
			{ 7951, 2,0}, /* core1 sp32 bit58 */
			{ 7954, 2,0}, /* core1 sp32 bit59 */
			{ 7948, 2,0}, /* core1 sp32 bit60 */
			{ 7958, 2,0}, /* core1 sp32 bit61 */
			{ 7945, 2,0}, /* core1 sp32 bit62 */
			{ 1993, 3,0}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{  248, 2,0}, /* core1 fp32 bit0 */
			{  247, 2,0}, /* core1 fp32 bit1 */
			{  253, 2,0}, /* core1 fp32 bit2 */
			{  364, 2,0}, /* core1 fp32 bit3 */
			{  356, 2,0}, /* core1 fp32 bit4 */
			{  246, 2,0}, /* core1 fp32 bit5 */
			{  384, 2,0}, /* core1 fp32 bit6 */
			{  385, 2,0}, /* core1 fp32 bit7 */
			{  258, 2,0}, /* core1 fp32 bit8 */
			{  254, 2,0}, /* core1 fp32 bit9 */
			{  257, 2,0}, /* core1 fp32 bit10 */
			{  392, 2,0}, /* core1 fp32 bit11 */
			{  255, 2,0}, /* core1 fp32 bit12 */
			{  391, 2,0}, /* core1 fp32 bit13 */
			{  387, 2,0}, /* core1 fp32 bit14 */
			{  256, 2,0}, /* core1 fp32 bit15 */
			{  388, 2,0}, /* core1 fp32 bit16 */
			{  354, 2,0}, /* core1 fp32 bit17 */
			{  363, 2,0}, /* core1 fp32 bit18 */
			{  368, 2,0}, /* core1 fp32 bit19 */
			{  335, 2,0}, /* core1 fp32 bit20 */
			{  366, 2,0}, /* core1 fp32 bit21 */
			{  341, 2,0}, /* core1 fp32 bit22 */
			{  339, 2,0}, /* core1 fp32 bit23 */
			{  340, 2,0}, /* core1 fp32 bit24 */
			{  367, 2,0}, /* core1 fp32 bit25 */
			{  337, 2,0}, /* core1 fp32 bit26 */
			{  369, 2,0}, /* core1 fp32 bit27 */
			{  370, 2,0}, /* core1 fp32 bit28 */
			{  336, 2,0}, /* core1 fp32 bit29 */
			{  338, 2,0}, /* core1 fp32 bit30 */
			{  358, 2,0}, /* core1 fp32 bit31 */
			{ 2368, 3,0}, /* core1 fp32 bit32 */
			{ 2381, 3,0}, /* core1 fp32 bit33 */
			{ 2370, 3,0}, /* core1 fp32 bit34 */
			{ 2371, 3,0}, /* core1 fp32 bit35 */
			{ 2386, 3,0}, /* core1 fp32 bit36 */
			{ 2380, 3,0}, /* core1 fp32 bit37 */
			{ 2336, 3,0}, /* core1 fp32 bit38 */
			{ 2379, 3,0}, /* core1 fp32 bit39 */
			{ 2335, 3,0}, /* core1 fp32 bit40 */
			{ 2346, 3,0}, /* core1 fp32 bit41 */
			{ 2339, 3,0}, /* core1 fp32 bit42 */
			{ 2330, 3,0}, /* core1 fp32 bit43 */
			{ 2334, 3,0}, /* core1 fp32 bit44 */
			{ 2345, 3,0}, /* core1 fp32 bit45 */
			{ 2387, 3,0}, /* core1 fp32 bit46 */
			{ 8052, 2,0}, /* core1 fp32 bit47 */
			{ 8054, 2,0}, /* core1 fp32 bit48 */
			{ 2488, 3,0}, /* core1 fp32 bit49 */
			{ 2493, 3,0}, /* core1 fp32 bit50 */
			{ 2506, 3,0}, /* core1 fp32 bit51 */
			{ 2495, 3,0}, /* core1 fp32 bit52 */
			{ 2508, 3,0}, /* core1 fp32 bit53 */
			{ 8051, 2,0}, /* core1 fp32 bit54 */
			{ 2497, 3,0}, /* core1 fp32 bit55 */
			{ 8055, 2,0}, /* core1 fp32 bit56 */
			{ 2498, 3,0}, /* core1 fp32 bit57 */
			{ 8053, 2,0}, /* core1 fp32 bit58 */
			{ 8056, 2,0}, /* core1 fp32 bit59 */
			{ 2492, 3,0}, /* core1 fp32 bit60 */
			{ 2487, 3,0}, /* core1 fp32 bit61 */
			{ 2496, 3,0}, /* core1 fp32 bit62 */
			{ 7942, 2,0}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{  209, 3,0}, /* core1 fp64 bit0 */
			{   50, 3,0}, /* core1 fp64 bit1 */
			{   45, 3,0}, /* core1 fp64 bit2 */
			{  210, 3,0}, /* core1 fp64 bit3 */
			{   58, 3,0}, /* core1 fp64 bit4 */
			{   46, 3,0}, /* core1 fp64 bit5 */
			{  205, 3,0}, /* core1 fp64 bit6 */
			{  213, 3,0}, /* core1 fp64 bit7 */
			{   59, 3,0}, /* core1 fp64 bit8 */
			{  217, 3,0}, /* core1 fp64 bit9 */
			{  207, 3,0}, /* core1 fp64 bit10 */
			{   77, 3,0}, /* core1 fp64 bit11 */
			{  197, 3,0}, /* core1 fp64 bit12 */
			{  200, 3,0}, /* core1 fp64 bit13 */
			{  206, 3,0}, /* core1 fp64 bit14 */
			{  204, 3,0}, /* core1 fp64 bit15 */
			{  199, 3,0}, /* core1 fp64 bit16 */
			{  224, 3,0}, /* core1 fp64 bit17 */
			{  198, 3,0}, /* core1 fp64 bit18 */
			{   83, 3,0}, /* core1 fp64 bit19 */
			{  223, 3,0}, /* core1 fp64 bit20 */
			{  226, 3,0}, /* core1 fp64 bit21 */
			{   61, 3,0}, /* core1 fp64 bit22 */
			{   81, 3,0}, /* core1 fp64 bit23 */
			{   84, 3,0}, /* core1 fp64 bit24 */
			{   80, 3,0}, /* core1 fp64 bit25 */
			{   82, 3,0}, /* core1 fp64 bit26 */
			{   85, 3,0}, /* core1 fp64 bit27 */
			{   78, 3,0}, /* core1 fp64 bit28 */
			{  225, 3,0}, /* core1 fp64 bit29 */
			{   79, 3,0}, /* core1 fp64 bit30 */
			{  215, 3,0}, /* core1 fp64 bit31 */
			{ 1708, 3,0}, /* core1 fp64 bit32 */
			{ 1676, 3,0}, /* core1 fp64 bit33 */
			{ 1677, 3,0}, /* core1 fp64 bit34 */
			{ 1707, 3,0}, /* core1 fp64 bit35 */
			{ 1668, 3,0}, /* core1 fp64 bit36 */
			{ 1675, 3,0}, /* core1 fp64 bit37 */
			{ 1593, 3,0}, /* core1 fp64 bit38 */
			{ 1709, 3,0}, /* core1 fp64 bit39 */
			{ 1594, 3,0}, /* core1 fp64 bit40 */
			{ 1592, 3,0}, /* core1 fp64 bit41 */
			{ 1657, 3,0}, /* core1 fp64 bit42 */
			{ 1589, 3,0}, /* core1 fp64 bit43 */
			{ 1632, 3,0}, /* core1 fp64 bit44 */
			{ 1590, 3,0}, /* core1 fp64 bit45 */
			{ 1591, 3,0}, /* core1 fp64 bit46 */
			{ 3287, 3,0}, /* core1 fp64 bit47 */
			{ 3373, 3,0}, /* core1 fp64 bit48 */
			{ 3292, 3,0}, /* core1 fp64 bit49 */
			{ 3375, 3,0}, /* core1 fp64 bit50 */
			{ 3374, 3,0}, /* core1 fp64 bit51 */
			{ 3286, 3,0}, /* core1 fp64 bit52 */
			{ 3294, 3,0}, /* core1 fp64 bit53 */
			{ 3366, 3,0}, /* core1 fp64 bit54 */
			{ 3371, 3,0}, /* core1 fp64 bit55 */
			{ 3297, 3,0}, /* core1 fp64 bit56 */
			{ 3365, 3,0}, /* core1 fp64 bit57 */
			{ 3376, 3,0}, /* core1 fp64 bit58 */
			{ 3296, 3,0}, /* core1 fp64 bit59 */
			{ 3369, 3,0}, /* core1 fp64 bit60 */
			{ 3372, 3,0}, /* core1 fp64 bit61 */
			{ 3368, 3,0}, /* core1 fp64 bit62 */
			{ 1631, 3,0}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{   56, 3,0}, /* core1 sp_EL0 bit0 */
			{   47, 3,0}, /* core1 sp_EL0 bit1 */
			{   49, 3,0}, /* core1 sp_EL0 bit2 */
			{   48, 3,0}, /* core1 sp_EL0 bit3 */
			{   53, 3,0}, /* core1 sp_EL0 bit4 */
			{   52, 3,0}, /* core1 sp_EL0 bit5 */
			{ 1254, 3,0}, /* core1 sp_EL0 bit6 */
			{ 1277, 3,0}, /* core1 sp_EL0 bit7 */
			{   41, 3,0}, /* core1 sp_EL0 bit8 */
			{ 1300, 3,0}, /* core1 sp_EL0 bit9 */
			{   44, 3,0}, /* core1 sp_EL0 bit10 */
			{   40, 3,0}, /* core1 sp_EL0 bit11 */
			{   43, 3,0}, /* core1 sp_EL0 bit12 */
			{   57, 3,0}, /* core1 sp_EL0 bit13 */
			{ 1273, 3,0}, /* core1 sp_EL0 bit14 */
			{   51, 3,0}, /* core1 sp_EL0 bit15 */
			{   42, 3,0}, /* core1 sp_EL0 bit16 */
			{   22, 3,0}, /* core1 sp_EL0 bit17 */
			{   60, 3,0}, /* core1 sp_EL0 bit18 */
			{   39, 3,0}, /* core1 sp_EL0 bit19 */
			{ 1338, 3,0}, /* core1 sp_EL0 bit20 */
			{ 1247, 3,0}, /* core1 sp_EL0 bit21 */
			{ 1350, 3,0}, /* core1 sp_EL0 bit22 */
			{ 1332, 3,0}, /* core1 sp_EL0 bit23 */
			{ 1253, 3,0}, /* core1 sp_EL0 bit24 */
			{ 1252, 3,0}, /* core1 sp_EL0 bit25 */
			{ 1333, 3,0}, /* core1 sp_EL0 bit26 */
			{ 1335, 3,0}, /* core1 sp_EL0 bit27 */
			{ 1347, 3,0}, /* core1 sp_EL0 bit28 */
			{ 1251, 3,0}, /* core1 sp_EL0 bit29 */
			{ 1349, 3,0}, /* core1 sp_EL0 bit30 */
			{ 1257, 3,0}, /* core1 sp_EL0 bit31 */
			{ 1060, 3,0}, /* core1 sp_EL0 bit32 */
			{ 1719, 3,0}, /* core1 sp_EL0 bit33 */
			{ 1700, 3,0}, /* core1 sp_EL0 bit34 */
			{ 1701, 3,0}, /* core1 sp_EL0 bit35 */
			{ 1655, 3,0}, /* core1 sp_EL0 bit36 */
			{ 1059, 3,0}, /* core1 sp_EL0 bit37 */
			{ 1653, 3,0}, /* core1 sp_EL0 bit38 */
			{ 1704, 3,0}, /* core1 sp_EL0 bit39 */
			{ 1634, 3,0}, /* core1 sp_EL0 bit40 */
			{ 1637, 3,0}, /* core1 sp_EL0 bit41 */
			{ 1687, 3,0}, /* core1 sp_EL0 bit42 */
			{ 1633, 3,0}, /* core1 sp_EL0 bit43 */
			{ 1651, 3,0}, /* core1 sp_EL0 bit44 */
			{ 1636, 3,0}, /* core1 sp_EL0 bit45 */
			{ 1587, 3,0}, /* core1 sp_EL0 bit46 */
			{ 3370, 3,0}, /* core1 sp_EL0 bit47 */
			{ 3347, 3,0}, /* core1 sp_EL0 bit48 */
			{ 3345, 3,0}, /* core1 sp_EL0 bit49 */
			{ 3349, 3,0}, /* core1 sp_EL0 bit50 */
			{ 3354, 3,0}, /* core1 sp_EL0 bit51 */
			{ 3343, 3,0}, /* core1 sp_EL0 bit52 */
			{ 3341, 3,0}, /* core1 sp_EL0 bit53 */
			{ 3351, 3,0}, /* core1 sp_EL0 bit54 */
			{ 3344, 3,0}, /* core1 sp_EL0 bit55 */
			{ 3337, 3,0}, /* core1 sp_EL0 bit56 */
			{ 3346, 3,0}, /* core1 sp_EL0 bit57 */
			{ 3338, 3,0}, /* core1 sp_EL0 bit58 */
			{ 3342, 3,0}, /* core1 sp_EL0 bit59 */
			{ 3340, 3,0}, /* core1 sp_EL0 bit60 */
			{ 3353, 3,0}, /* core1 sp_EL0 bit61 */
			{ 3339, 3,0}, /* core1 sp_EL0 bit62 */
			{ 1658, 3,0}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{  208, 3,0}, /* core1 sp_EL1 bit0 */
			{  202, 3,0}, /* core1 sp_EL1 bit1 */
			{  211, 3,0}, /* core1 sp_EL1 bit2 */
			{  201, 3,0}, /* core1 sp_EL1 bit3 */
			{   89, 3,0}, /* core1 sp_EL1 bit4 */
			{  212, 3,0}, /* core1 sp_EL1 bit5 */
			{  138, 3,0}, /* core1 sp_EL1 bit6 */
			{   68, 3,0}, /* core1 sp_EL1 bit7 */
			{   69, 3,0}, /* core1 sp_EL1 bit8 */
			{  196, 3,0}, /* core1 sp_EL1 bit9 */
			{   76, 3,0}, /* core1 sp_EL1 bit10 */
			{  218, 3,0}, /* core1 sp_EL1 bit11 */
			{   13, 3,0}, /* core1 sp_EL1 bit12 */
			{  195, 3,0}, /* core1 sp_EL1 bit13 */
			{   12, 3,0}, /* core1 sp_EL1 bit14 */
			{  220, 3,0}, /* core1 sp_EL1 bit15 */
			{  219, 3,0}, /* core1 sp_EL1 bit16 */
			{   75, 3,0}, /* core1 sp_EL1 bit17 */
			{   19, 3,0}, /* core1 sp_EL1 bit18 */
			{  133, 3,0}, /* core1 sp_EL1 bit19 */
			{  136, 3,0}, /* core1 sp_EL1 bit20 */
			{   73, 3,0}, /* core1 sp_EL1 bit21 */
			{  141, 3,0}, /* core1 sp_EL1 bit22 */
			{  137, 3,0}, /* core1 sp_EL1 bit23 */
			{  139, 3,0}, /* core1 sp_EL1 bit24 */
			{  135, 3,0}, /* core1 sp_EL1 bit25 */
			{  222, 3,0}, /* core1 sp_EL1 bit26 */
			{   86, 3,0}, /* core1 sp_EL1 bit27 */
			{  134, 3,0}, /* core1 sp_EL1 bit28 */
			{   74, 3,0}, /* core1 sp_EL1 bit29 */
			{  116, 3,0}, /* core1 sp_EL1 bit30 */
			{   88, 3,0}, /* core1 sp_EL1 bit31 */
			{ 1697, 3,0}, /* core1 sp_EL1 bit32 */
			{ 1695, 3,0}, /* core1 sp_EL1 bit33 */
			{ 1698, 3,0}, /* core1 sp_EL1 bit34 */
			{ 1696, 3,0}, /* core1 sp_EL1 bit35 */
			{ 1679, 3,0}, /* core1 sp_EL1 bit36 */
			{ 1699, 3,0}, /* core1 sp_EL1 bit37 */
			{ 1684, 3,0}, /* core1 sp_EL1 bit38 */
			{ 1694, 3,0}, /* core1 sp_EL1 bit39 */
			{ 1656, 3,0}, /* core1 sp_EL1 bit40 */
			{ 1686, 3,0}, /* core1 sp_EL1 bit41 */
			{ 1678, 3,0}, /* core1 sp_EL1 bit42 */
			{ 1680, 3,0}, /* core1 sp_EL1 bit43 */
			{ 1691, 3,0}, /* core1 sp_EL1 bit44 */
			{ 1586, 3,0}, /* core1 sp_EL1 bit45 */
			{ 1685, 3,0}, /* core1 sp_EL1 bit46 */
			{ 1035, 3,0}, /* core1 sp_EL1 bit47 */
			{ 3288, 3,0}, /* core1 sp_EL1 bit48 */
			{ 1034, 3,0}, /* core1 sp_EL1 bit49 */
			{ 3285, 3,0}, /* core1 sp_EL1 bit50 */
			{ 3289, 3,0}, /* core1 sp_EL1 bit51 */
			{ 3268, 3,0}, /* core1 sp_EL1 bit52 */
			{ 1019, 3,0}, /* core1 sp_EL1 bit53 */
			{ 1023, 3,0}, /* core1 sp_EL1 bit54 */
			{ 3290, 3,0}, /* core1 sp_EL1 bit55 */
			{ 3295, 3,0}, /* core1 sp_EL1 bit56 */
			{ 3302, 3,0}, /* core1 sp_EL1 bit57 */
			{ 3293, 3,0}, /* core1 sp_EL1 bit58 */
			{ 3283, 3,0}, /* core1 sp_EL1 bit59 */
			{ 3299, 3,0}, /* core1 sp_EL1 bit60 */
			{ 3291, 3,0}, /* core1 sp_EL1 bit61 */
			{ 1020, 3,0}, /* core1 sp_EL1 bit62 */
			{ 1693, 3,0}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 1307, 3,0}, /* core1 sp_EL2 bit0 */
			{ 1283, 3,0}, /* core1 sp_EL2 bit1 */
			{ 1308, 3,0}, /* core1 sp_EL2 bit2 */
			{ 1255, 3,0}, /* core1 sp_EL2 bit3 */
			{ 1265, 3,0}, /* core1 sp_EL2 bit4 */
			{ 1256, 3,0}, /* core1 sp_EL2 bit5 */
			{ 1280, 3,0}, /* core1 sp_EL2 bit6 */
			{ 1278, 3,0}, /* core1 sp_EL2 bit7 */
			{ 1303, 3,0}, /* core1 sp_EL2 bit8 */
			{ 1285, 3,0}, /* core1 sp_EL2 bit9 */
			{ 1313, 3,0}, /* core1 sp_EL2 bit10 */
			{ 1302, 3,0}, /* core1 sp_EL2 bit11 */
			{ 1310, 3,0}, /* core1 sp_EL2 bit12 */
			{ 1304, 3,0}, /* core1 sp_EL2 bit13 */
			{ 1275, 3,0}, /* core1 sp_EL2 bit14 */
			{ 1312, 3,0}, /* core1 sp_EL2 bit15 */
			{ 1311, 3,0}, /* core1 sp_EL2 bit16 */
			{ 1258, 3,0}, /* core1 sp_EL2 bit17 */
			{ 1250, 3,0}, /* core1 sp_EL2 bit18 */
			{ 1368, 3,0}, /* core1 sp_EL2 bit19 */
			{ 1369, 3,0}, /* core1 sp_EL2 bit20 */
			{ 1358, 3,0}, /* core1 sp_EL2 bit21 */
			{ 1361, 3,0}, /* core1 sp_EL2 bit22 */
			{ 1375, 3,0}, /* core1 sp_EL2 bit23 */
			{ 1374, 3,0}, /* core1 sp_EL2 bit24 */
			{ 1370, 3,0}, /* core1 sp_EL2 bit25 */
			{ 1372, 3,0}, /* core1 sp_EL2 bit26 */
			{ 1371, 3,0}, /* core1 sp_EL2 bit27 */
			{ 1376, 3,0}, /* core1 sp_EL2 bit28 */
			{ 1373, 3,0}, /* core1 sp_EL2 bit29 */
			{ 1367, 3,0}, /* core1 sp_EL2 bit30 */
			{ 1264, 3,0}, /* core1 sp_EL2 bit31 */
			{ 1042, 3,0}, /* core1 sp_EL2 bit32 */
			{ 1047, 3,0}, /* core1 sp_EL2 bit33 */
			{ 1043, 3,0}, /* core1 sp_EL2 bit34 */
			{ 1041, 3,0}, /* core1 sp_EL2 bit35 */
			{ 1046, 3,0}, /* core1 sp_EL2 bit36 */
			{ 1040, 3,0}, /* core1 sp_EL2 bit37 */
			{ 1088, 3,0}, /* core1 sp_EL2 bit38 */
			{ 1050, 3,0}, /* core1 sp_EL2 bit39 */
			{ 1090, 3,0}, /* core1 sp_EL2 bit40 */
			{ 1084, 3,0}, /* core1 sp_EL2 bit41 */
			{ 1087, 3,0}, /* core1 sp_EL2 bit42 */
			{ 1089, 3,0}, /* core1 sp_EL2 bit43 */
			{ 1091, 3,0}, /* core1 sp_EL2 bit44 */
			{ 1092, 3,0}, /* core1 sp_EL2 bit45 */
			{ 1081, 3,0}, /* core1 sp_EL2 bit46 */
			{ 3180, 3,0}, /* core1 sp_EL2 bit47 */
			{ 3190, 3,0}, /* core1 sp_EL2 bit48 */
			{ 3183, 3,0}, /* core1 sp_EL2 bit49 */
			{ 3194, 3,0}, /* core1 sp_EL2 bit50 */
			{ 3192, 3,0}, /* core1 sp_EL2 bit51 */
			{ 3195, 3,0}, /* core1 sp_EL2 bit52 */
			{ 3197, 3,0}, /* core1 sp_EL2 bit53 */
			{ 3182, 3,0}, /* core1 sp_EL2 bit54 */
			{ 3186, 3,0}, /* core1 sp_EL2 bit55 */
			{ 3193, 3,0}, /* core1 sp_EL2 bit56 */
			{ 3185, 3,0}, /* core1 sp_EL2 bit57 */
			{ 3189, 3,0}, /* core1 sp_EL2 bit58 */
			{ 3181, 3,0}, /* core1 sp_EL2 bit59 */
			{ 3196, 3,0}, /* core1 sp_EL2 bit60 */
			{ 3230, 3,0}, /* core1 sp_EL2 bit61 */
			{ 3191, 3,0}, /* core1 sp_EL2 bit62 */
			{ 1036, 3,0}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 1550, 3,0}, /* core1 sp_EL3 bit0 */
			{ 1270, 3,0}, /* core1 sp_EL3 bit1 */
			{ 1271, 3,0}, /* core1 sp_EL3 bit2 */
			{ 1551, 3,0}, /* core1 sp_EL3 bit3 */
			{ 1268, 3,0}, /* core1 sp_EL3 bit4 */
			{ 1267, 3,0}, /* core1 sp_EL3 bit5 */
			{ 1323, 3,0}, /* core1 sp_EL3 bit6 */
			{ 1322, 3,0}, /* core1 sp_EL3 bit7 */
			{ 1318, 3,0}, /* core1 sp_EL3 bit8 */
			{ 1319, 3,0}, /* core1 sp_EL3 bit9 */
			{ 1315, 3,0}, /* core1 sp_EL3 bit10 */
			{ 1004, 3,0}, /* core1 sp_EL3 bit11 */
			{ 1317, 3,0}, /* core1 sp_EL3 bit12 */
			{ 1316, 3,0}, /* core1 sp_EL3 bit13 */
			{ 1321, 3,0}, /* core1 sp_EL3 bit14 */
			{ 1320, 3,0}, /* core1 sp_EL3 bit15 */
			{ 1324, 3,0}, /* core1 sp_EL3 bit16 */
			{ 1552, 3,0}, /* core1 sp_EL3 bit17 */
			{ 1549, 3,0}, /* core1 sp_EL3 bit18 */
			{ 1579, 3,0}, /* core1 sp_EL3 bit19 */
			{ 1571, 3,0}, /* core1 sp_EL3 bit20 */
			{ 1575, 3,0}, /* core1 sp_EL3 bit21 */
			{ 1580, 3,0}, /* core1 sp_EL3 bit22 */
			{ 1570, 3,0}, /* core1 sp_EL3 bit23 */
			{ 1574, 3,0}, /* core1 sp_EL3 bit24 */
			{ 1578, 3,0}, /* core1 sp_EL3 bit25 */
			{ 1573, 3,0}, /* core1 sp_EL3 bit26 */
			{ 1569, 3,0}, /* core1 sp_EL3 bit27 */
			{ 1577, 3,0}, /* core1 sp_EL3 bit28 */
			{ 1572, 3,0}, /* core1 sp_EL3 bit29 */
			{ 1576, 3,0}, /* core1 sp_EL3 bit30 */
			{ 1269, 3,0}, /* core1 sp_EL3 bit31 */
			{ 1054, 3,0}, /* core1 sp_EL3 bit32 */
			{ 1051, 3,0}, /* core1 sp_EL3 bit33 */
			{ 1052, 3,0}, /* core1 sp_EL3 bit34 */
			{ 1062, 3,0}, /* core1 sp_EL3 bit35 */
			{ 1071, 3,0}, /* core1 sp_EL3 bit36 */
			{ 1063, 3,0}, /* core1 sp_EL3 bit37 */
			{ 1056, 3,0}, /* core1 sp_EL3 bit38 */
			{ 1064, 3,0}, /* core1 sp_EL3 bit39 */
			{ 1085, 3,0}, /* core1 sp_EL3 bit40 */
			{ 1083, 3,0}, /* core1 sp_EL3 bit41 */
			{ 1072, 3,0}, /* core1 sp_EL3 bit42 */
			{ 1080, 3,0}, /* core1 sp_EL3 bit43 */
			{ 1086, 3,0}, /* core1 sp_EL3 bit44 */
			{ 1079, 3,0}, /* core1 sp_EL3 bit45 */
			{ 1082, 3,0}, /* core1 sp_EL3 bit46 */
			{ 3318, 3,0}, /* core1 sp_EL3 bit47 */
			{ 3176, 3,0}, /* core1 sp_EL3 bit48 */
			{ 3320, 3,0}, /* core1 sp_EL3 bit49 */
			{ 3325, 3,0}, /* core1 sp_EL3 bit50 */
			{ 3321, 3,0}, /* core1 sp_EL3 bit51 */
			{ 3317, 3,0}, /* core1 sp_EL3 bit52 */
			{ 3358, 3,0}, /* core1 sp_EL3 bit53 */
			{ 3319, 3,0}, /* core1 sp_EL3 bit54 */
			{ 3313, 3,0}, /* core1 sp_EL3 bit55 */
			{ 3324, 3,0}, /* core1 sp_EL3 bit56 */
			{ 3314, 3,0}, /* core1 sp_EL3 bit57 */
			{ 3356, 3,0}, /* core1 sp_EL3 bit58 */
			{ 3357, 3,0}, /* core1 sp_EL3 bit59 */
			{ 3315, 3,0}, /* core1 sp_EL3 bit60 */
			{ 3316, 3,0}, /* core1 sp_EL3 bit61 */
			{ 3322, 3,0}, /* core1 sp_EL3 bit62 */
			{ 1053, 3,0}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{   54, 3,0}, /* core1 elr_EL1 bit0 */
			{   55, 3,0}, /* core1 elr_EL1 bit1 */
			{ 1001, 3,0}, /* core1 elr_EL1 bit2 */
			{ 1000, 3,0}, /* core1 elr_EL1 bit3 */
			{ 1263, 3,0}, /* core1 elr_EL1 bit4 */
			{ 1286, 3,0}, /* core1 elr_EL1 bit5 */
			{ 1287, 3,0}, /* core1 elr_EL1 bit6 */
			{ 1276, 3,0}, /* core1 elr_EL1 bit7 */
			{ 1301, 3,0}, /* core1 elr_EL1 bit8 */
			{ 1289, 3,0}, /* core1 elr_EL1 bit9 */
			{ 1002, 3,0}, /* core1 elr_EL1 bit10 */
			{ 1290, 3,0}, /* core1 elr_EL1 bit11 */
			{ 1291, 3,0}, /* core1 elr_EL1 bit12 */
			{  999, 3,0}, /* core1 elr_EL1 bit13 */
			{ 1314, 3,0}, /* core1 elr_EL1 bit14 */
			{ 1003, 3,0}, /* core1 elr_EL1 bit15 */
			{ 1288, 3,0}, /* core1 elr_EL1 bit16 */
			{ 1274, 3,0}, /* core1 elr_EL1 bit17 */
			{ 1331, 3,0}, /* core1 elr_EL1 bit18 */
			{ 1346, 3,0}, /* core1 elr_EL1 bit19 */
			{ 1339, 3,0}, /* core1 elr_EL1 bit20 */
			{ 1343, 3,0}, /* core1 elr_EL1 bit21 */
			{ 1348, 3,0}, /* core1 elr_EL1 bit22 */
			{ 1352, 3,0}, /* core1 elr_EL1 bit23 */
			{ 1341, 3,0}, /* core1 elr_EL1 bit24 */
			{ 1342, 3,0}, /* core1 elr_EL1 bit25 */
			{ 1248, 3,0}, /* core1 elr_EL1 bit26 */
			{ 1340, 3,0}, /* core1 elr_EL1 bit27 */
			{ 1351, 3,0}, /* core1 elr_EL1 bit28 */
			{ 1334, 3,0}, /* core1 elr_EL1 bit29 */
			{ 1337, 3,0}, /* core1 elr_EL1 bit30 */
			{ 1266, 3,0}, /* core1 elr_EL1 bit31 */
			{ 1749, 3,0}, /* core1 elr_EL1 bit32 */
			{ 1750, 3,0}, /* core1 elr_EL1 bit33 */
			{ 1757, 3,0}, /* core1 elr_EL1 bit34 */
			{ 1752, 3,0}, /* core1 elr_EL1 bit35 */
			{ 1744, 3,0}, /* core1 elr_EL1 bit36 */
			{ 1748, 3,0}, /* core1 elr_EL1 bit37 */
			{ 1767, 3,0}, /* core1 elr_EL1 bit38 */
			{ 1751, 3,0}, /* core1 elr_EL1 bit39 */
			{ 1795, 3,0}, /* core1 elr_EL1 bit40 */
			{ 1746, 3,0}, /* core1 elr_EL1 bit41 */
			{ 1745, 3,0}, /* core1 elr_EL1 bit42 */
			{ 1769, 3,0}, /* core1 elr_EL1 bit43 */
			{ 1796, 3,0}, /* core1 elr_EL1 bit44 */
			{ 1797, 3,0}, /* core1 elr_EL1 bit45 */
			{ 1768, 3,0}, /* core1 elr_EL1 bit46 */
			{ 7297, 2,0}, /* core1 elr_EL1 bit47 */
			{ 7284, 2,0}, /* core1 elr_EL1 bit48 */
			{ 7285, 2,0}, /* core1 elr_EL1 bit49 */
			{ 7283, 2,0}, /* core1 elr_EL1 bit50 */
			{ 7290, 2,0}, /* core1 elr_EL1 bit51 */
			{ 7292, 2,0}, /* core1 elr_EL1 bit52 */
			{ 7296, 2,0}, /* core1 elr_EL1 bit53 */
			{ 7293, 2,0}, /* core1 elr_EL1 bit54 */
			{ 7286, 2,0}, /* core1 elr_EL1 bit55 */
			{ 7979, 2,0}, /* core1 elr_EL1 bit56 */
			{ 7288, 2,0}, /* core1 elr_EL1 bit57 */
			{ 7294, 2,0}, /* core1 elr_EL1 bit58 */
			{ 7287, 2,0}, /* core1 elr_EL1 bit59 */
			{ 7289, 2,0}, /* core1 elr_EL1 bit60 */
			{ 7291, 2,0}, /* core1 elr_EL1 bit61 */
			{ 7295, 2,0}, /* core1 elr_EL1 bit62 */
			{ 1759, 3,0}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{  275, 2,0}, /* core1 elr_EL2 bit0 */
			{  393, 2,0}, /* core1 elr_EL2 bit1 */
			{  276, 2,0}, /* core1 elr_EL2 bit2 */
			{  360, 2,0}, /* core1 elr_EL2 bit3 */
			{  292, 2,0}, /* core1 elr_EL2 bit4 */
			{  281, 2,0}, /* core1 elr_EL2 bit5 */
			{  280, 2,0}, /* core1 elr_EL2 bit6 */
			{  282, 2,0}, /* core1 elr_EL2 bit7 */
			{  398, 2,0}, /* core1 elr_EL2 bit8 */
			{  397, 2,0}, /* core1 elr_EL2 bit9 */
			{  396, 2,0}, /* core1 elr_EL2 bit10 */
			{  399, 2,0}, /* core1 elr_EL2 bit11 */
			{  400, 2,0}, /* core1 elr_EL2 bit12 */
			{  401, 2,0}, /* core1 elr_EL2 bit13 */
			{  285, 2,0}, /* core1 elr_EL2 bit14 */
			{  395, 2,0}, /* core1 elr_EL2 bit15 */
			{  394, 2,0}, /* core1 elr_EL2 bit16 */
			{  283, 2,0}, /* core1 elr_EL2 bit17 */
			{  284, 2,0}, /* core1 elr_EL2 bit18 */
			{  381, 2,0}, /* core1 elr_EL2 bit19 */
			{  382, 2,0}, /* core1 elr_EL2 bit20 */
			{  377, 2,0}, /* core1 elr_EL2 bit21 */
			{  371, 2,0}, /* core1 elr_EL2 bit22 */
			{  379, 2,0}, /* core1 elr_EL2 bit23 */
			{  372, 2,0}, /* core1 elr_EL2 bit24 */
			{  374, 2,0}, /* core1 elr_EL2 bit25 */
			{  378, 2,0}, /* core1 elr_EL2 bit26 */
			{  375, 2,0}, /* core1 elr_EL2 bit27 */
			{  376, 2,0}, /* core1 elr_EL2 bit28 */
			{  373, 2,0}, /* core1 elr_EL2 bit29 */
			{  380, 2,0}, /* core1 elr_EL2 bit30 */
			{  291, 2,0}, /* core1 elr_EL2 bit31 */
			{ 1039, 3,0}, /* core1 elr_EL2 bit32 */
			{ 1044, 3,0}, /* core1 elr_EL2 bit33 */
			{ 1038, 3,0}, /* core1 elr_EL2 bit34 */
			{ 1037, 3,0}, /* core1 elr_EL2 bit35 */
			{ 1662, 3,0}, /* core1 elr_EL2 bit36 */
			{ 1045, 3,0}, /* core1 elr_EL2 bit37 */
			{ 1074, 3,0}, /* core1 elr_EL2 bit38 */
			{ 1061, 3,0}, /* core1 elr_EL2 bit39 */
			{ 1076, 3,0}, /* core1 elr_EL2 bit40 */
			{ 1069, 3,0}, /* core1 elr_EL2 bit41 */
			{ 1075, 3,0}, /* core1 elr_EL2 bit42 */
			{ 1070, 3,0}, /* core1 elr_EL2 bit43 */
			{ 1077, 3,0}, /* core1 elr_EL2 bit44 */
			{ 1078, 3,0}, /* core1 elr_EL2 bit45 */
			{ 1073, 3,0}, /* core1 elr_EL2 bit46 */
			{ 3348, 3,0}, /* core1 elr_EL2 bit47 */
			{ 3328, 3,0}, /* core1 elr_EL2 bit48 */
			{ 3334, 3,0}, /* core1 elr_EL2 bit49 */
			{ 3336, 3,0}, /* core1 elr_EL2 bit50 */
			{ 3352, 3,0}, /* core1 elr_EL2 bit51 */
			{ 3168, 3,0}, /* core1 elr_EL2 bit52 */
			{ 3172, 3,0}, /* core1 elr_EL2 bit53 */
			{ 3331, 3,0}, /* core1 elr_EL2 bit54 */
			{ 3335, 3,0}, /* core1 elr_EL2 bit55 */
			{ 3326, 3,0}, /* core1 elr_EL2 bit56 */
			{ 3329, 3,0}, /* core1 elr_EL2 bit57 */
			{ 3355, 3,0}, /* core1 elr_EL2 bit58 */
			{ 3327, 3,0}, /* core1 elr_EL2 bit59 */
			{ 3330, 3,0}, /* core1 elr_EL2 bit60 */
			{ 3332, 3,0}, /* core1 elr_EL2 bit61 */
			{ 3333, 3,0}, /* core1 elr_EL2 bit62 */
			{ 1055, 3,0}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 2940, 3,0}, /* core1 elr_EL3 bit0 */
			{ 2887, 3,0}, /* core1 elr_EL3 bit1 */
			{ 2886, 3,0}, /* core1 elr_EL3 bit2 */
			{ 2892, 3,0}, /* core1 elr_EL3 bit3 */
			{ 2880, 3,0}, /* core1 elr_EL3 bit4 */
			{ 2878, 3,0}, /* core1 elr_EL3 bit5 */
			{ 2944, 3,0}, /* core1 elr_EL3 bit6 */
			{ 2885, 3,0}, /* core1 elr_EL3 bit7 */
			{ 2900, 3,0}, /* core1 elr_EL3 bit8 */
			{ 2899, 3,0}, /* core1 elr_EL3 bit9 */
			{ 2897, 3,0}, /* core1 elr_EL3 bit10 */
			{ 2938, 3,0}, /* core1 elr_EL3 bit11 */
			{ 2896, 3,0}, /* core1 elr_EL3 bit12 */
			{ 2942, 3,0}, /* core1 elr_EL3 bit13 */
			{ 2895, 3,0}, /* core1 elr_EL3 bit14 */
			{ 2937, 3,0}, /* core1 elr_EL3 bit15 */
			{ 2939, 3,0}, /* core1 elr_EL3 bit16 */
			{ 2881, 3,0}, /* core1 elr_EL3 bit17 */
			{ 2945, 3,0}, /* core1 elr_EL3 bit18 */
			{ 2955, 3,0}, /* core1 elr_EL3 bit19 */
			{ 2962, 3,0}, /* core1 elr_EL3 bit20 */
			{ 2957, 3,0}, /* core1 elr_EL3 bit21 */
			{ 2970, 3,0}, /* core1 elr_EL3 bit22 */
			{ 2963, 3,0}, /* core1 elr_EL3 bit23 */
			{ 2971, 3,0}, /* core1 elr_EL3 bit24 */
			{ 2956, 3,0}, /* core1 elr_EL3 bit25 */
			{ 2961, 3,0}, /* core1 elr_EL3 bit26 */
			{ 2960, 3,0}, /* core1 elr_EL3 bit27 */
			{ 2958, 3,0}, /* core1 elr_EL3 bit28 */
			{ 2959, 3,0}, /* core1 elr_EL3 bit29 */
			{ 2954, 3,0}, /* core1 elr_EL3 bit30 */
			{ 2879, 3,0}, /* core1 elr_EL3 bit31 */
			{ 1048, 3,0}, /* core1 elr_EL3 bit32 */
			{ 1049, 3,0}, /* core1 elr_EL3 bit33 */
			{ 2069, 3,0}, /* core1 elr_EL3 bit34 */
			{ 2061, 3,0}, /* core1 elr_EL3 bit35 */
			{ 1772, 3,0}, /* core1 elr_EL3 bit36 */
			{ 2063, 3,0}, /* core1 elr_EL3 bit37 */
			{ 1774, 3,0}, /* core1 elr_EL3 bit38 */
			{ 2064, 3,0}, /* core1 elr_EL3 bit39 */
			{ 1773, 3,0}, /* core1 elr_EL3 bit40 */
			{ 1788, 3,0}, /* core1 elr_EL3 bit41 */
			{ 1785, 3,0}, /* core1 elr_EL3 bit42 */
			{ 1786, 3,0}, /* core1 elr_EL3 bit43 */
			{ 1787, 3,0}, /* core1 elr_EL3 bit44 */
			{ 1789, 3,0}, /* core1 elr_EL3 bit45 */
			{ 1778, 3,0}, /* core1 elr_EL3 bit46 */
			{ 3220, 3,0}, /* core1 elr_EL3 bit47 */
			{ 7965, 3,0}, /* core1 elr_EL3 bit48 */
			{ 7960, 3,0}, /* core1 elr_EL3 bit49 */
			{ 3223, 3,0}, /* core1 elr_EL3 bit50 */
			{ 7972, 3,0}, /* core1 elr_EL3 bit51 */
			{ 7973, 3,0}, /* core1 elr_EL3 bit52 */
			{ 3221, 3,0}, /* core1 elr_EL3 bit53 */
			{ 3226, 3,0}, /* core1 elr_EL3 bit54 */
			{ 7958, 3,0}, /* core1 elr_EL3 bit55 */
			{ 7966, 3,0}, /* core1 elr_EL3 bit56 */
			{ 7959, 3,0}, /* core1 elr_EL3 bit57 */
			{ 7963, 3,0}, /* core1 elr_EL3 bit58 */
			{ 7961, 3,0}, /* core1 elr_EL3 bit59 */
			{ 7962, 3,0}, /* core1 elr_EL3 bit60 */
			{ 3224, 3,0}, /* core1 elr_EL3 bit61 */
			{ 3225, 3,0}, /* core1 elr_EL3 bit62 */
			{ 1779, 3,0}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 7402, 2,0}, /* core1 raw_pc bit0 */
			{ 5743, 3,0}, /* core1 raw_pc bit1 */
			{ 5742, 3,0}, /* core1 raw_pc bit2 */
			{ 7399, 2,0}, /* core1 raw_pc bit3 */
			{ 7401, 2,0}, /* core1 raw_pc bit4 */
			{ 7400, 2,0}, /* core1 raw_pc bit5 */
			{ 7404, 2,0}, /* core1 raw_pc bit6 */
			{ 9616, 2,0}, /* core1 raw_pc bit7 */
			{ 9615, 2,0}, /* core1 raw_pc bit8 */
			{ 9614, 2,0}, /* core1 raw_pc bit9 */
			{ 9613, 2,0}, /* core1 raw_pc bit10 */
			{ 9620, 2,0}, /* core1 raw_pc bit11 */
			{ 9619, 2,0}, /* core1 raw_pc bit12 */
			{ 9618, 2,0}, /* core1 raw_pc bit13 */
			{ 9617, 2,0}, /* core1 raw_pc bit14 */
			{ 9624, 2,0}, /* core1 raw_pc bit15 */
			{ 9623, 2,0}, /* core1 raw_pc bit16 */
			{ 9622, 2,0}, /* core1 raw_pc bit17 */
			{ 9621, 2,0}, /* core1 raw_pc bit18 */
			{10437, 2,0}, /* core1 raw_pc bit19 */
			{10436, 2,0}, /* core1 raw_pc bit20 */
			{10435, 2,0}, /* core1 raw_pc bit21 */
			{10434, 2,0}, /* core1 raw_pc bit22 */
			{10441, 2,0}, /* core1 raw_pc bit23 */
			{10440, 2,0}, /* core1 raw_pc bit24 */
			{10439, 2,0}, /* core1 raw_pc bit25 */
			{10438, 2,0}, /* core1 raw_pc bit26 */
			{10445, 2,0}, /* core1 raw_pc bit27 */
			{10444, 2,0}, /* core1 raw_pc bit28 */
			{10443, 2,0}, /* core1 raw_pc bit29 */
			{10442, 2,0}, /* core1 raw_pc bit30 */
			{ 9347, 2,0}, /* core1 raw_pc bit31 */
			{ 9346, 2,0}, /* core1 raw_pc bit32 */
			{ 9345, 2,0}, /* core1 raw_pc bit33 */
			{ 9344, 2,0}, /* core1 raw_pc bit34 */
			{ 9351, 2,0}, /* core1 raw_pc bit35 */
			{ 9350, 2,0}, /* core1 raw_pc bit36 */
			{ 9349, 2,0}, /* core1 raw_pc bit37 */
			{ 5234, 3,0}, /* core1 raw_pc bit38 */
			{ 9646, 2,0}, /* core1 raw_pc bit39 */
			{ 9645, 2,0}, /* core1 raw_pc bit40 */
			{ 9348, 2,0}, /* core1 raw_pc bit41 */
			{ 9648, 2,0}, /* core1 raw_pc bit42 */
			{ 9647, 2,0}, /* core1 raw_pc bit43 */
			{ 9644, 2,0}, /* core1 raw_pc bit44 */
			{ 9643, 2,0}, /* core1 raw_pc bit45 */
			{ 5232, 3,0}, /* core1 raw_pc bit46 */
			{ 5233, 3,0}, /* core1 raw_pc bit47 */
			{    0, 0,2}, /* core1 raw_pc bit48 */
			{    0, 0,2}, /* core1 raw_pc bit49 */
			{    0, 0,2}, /* core1 raw_pc bit50 */
			{    0, 0,2}, /* core1 raw_pc bit51 */
			{    0, 0,2}, /* core1 raw_pc bit52 */
			{    0, 0,2}, /* core1 raw_pc bit53 */
			{    0, 0,2}, /* core1 raw_pc bit54 */
			{    0, 0,2}, /* core1 raw_pc bit55 */
			{    0, 0,2}, /* core1 raw_pc bit56 */
			{    0, 0,2}, /* core1 raw_pc bit57 */
			{    0, 0,2}, /* core1 raw_pc bit58 */
			{    0, 0,2}, /* core1 raw_pc bit59 */
			{    0, 0,2}, /* core1 raw_pc bit60 */
			{    0, 0,2}, /* core1 raw_pc bit61 */
			{    0, 0,2}, /* core1 raw_pc bit62 */
			{    0, 0,2}, /* core1 raw_pc bit63 */
			}},
			.pc_iss = {{
			{ 9507, 2,0}, /* core1 pc_iss bit0 */
			{ 9506, 2,0}, /* core1 pc_iss bit1 */
			{ 9505, 2,0}, /* core1 pc_iss bit2 */
			{ 9513, 2,0}, /* core1 pc_iss bit3 */
			{ 9512, 2,0}, /* core1 pc_iss bit4 */
			{ 9503, 2,0}, /* core1 pc_iss bit5 */
			{ 9502, 2,0}, /* core1 pc_iss bit6 */
			{ 9504, 2,0}, /* core1 pc_iss bit7 */
			{ 9626, 2,0}, /* core1 pc_iss bit8 */
			{ 9625, 2,0}, /* core1 pc_iss bit9 */
			{ 9509, 2,0}, /* core1 pc_iss bit10 */
			{ 9634, 2,0}, /* core1 pc_iss bit11 */
			{ 9633, 2,0}, /* core1 pc_iss bit12 */
			{ 9331, 2,0}, /* core1 pc_iss bit13 */
			{ 5360, 3,0}, /* core1 pc_iss bit14 */
			{ 9630, 2,0}, /* core1 pc_iss bit15 */
			{ 9629, 2,0}, /* core1 pc_iss bit16 */
			{ 9511, 2,0}, /* core1 pc_iss bit17 */
			{ 9510, 2,0}, /* core1 pc_iss bit18 */
			{ 9628, 2,0}, /* core1 pc_iss bit19 */
			{ 9508, 2,0}, /* core1 pc_iss bit20 */
			{ 9627, 2,0}, /* core1 pc_iss bit21 */
			{ 9632, 2,0}, /* core1 pc_iss bit22 */
			{ 9330, 2,0}, /* core1 pc_iss bit23 */
			{ 5363, 3,0}, /* core1 pc_iss bit24 */
			{ 9329, 2,0}, /* core1 pc_iss bit25 */
			{ 9328, 2,0}, /* core1 pc_iss bit26 */
			{ 9631, 2,0}, /* core1 pc_iss bit27 */
			{ 5361, 3,0}, /* core1 pc_iss bit28 */
			{ 9636, 2,0}, /* core1 pc_iss bit29 */
			{ 9635, 2,0}, /* core1 pc_iss bit30 */
			{ 5362, 3,0}, /* core1 pc_iss bit31 */
			{ 9656, 2,0}, /* core1 pc_iss bit32 */
			{ 9391, 2,0}, /* core1 pc_iss bit33 */
			{ 9655, 2,0}, /* core1 pc_iss bit34 */
			{ 9654, 2,0}, /* core1 pc_iss bit35 */
			{ 9653, 2,0}, /* core1 pc_iss bit36 */
			{ 9390, 2,0}, /* core1 pc_iss bit37 */
			{ 9389, 2,0}, /* core1 pc_iss bit38 */
			{ 5248, 3,0}, /* core1 pc_iss bit39 */
			{ 9652, 2,0}, /* core1 pc_iss bit40 */
			{ 9388, 2,0}, /* core1 pc_iss bit41 */
			{ 5250, 3,0}, /* core1 pc_iss bit42 */
			{ 9387, 2,0}, /* core1 pc_iss bit43 */
			{ 9651, 2,0}, /* core1 pc_iss bit44 */
			{ 9650, 2,0}, /* core1 pc_iss bit45 */
			{ 5246, 3,0}, /* core1 pc_iss bit46 */
			{ 9649, 2,0}, /* core1 pc_iss bit47 */
			{ 5249, 3,0}, /* core1 pc_iss bit48 */
			{ 9386, 2,0}, /* core1 pc_iss bit49 */
			{ 5245, 3,0}, /* core1 pc_iss bit50 */
			{ 5247, 3,0}, /* core1 pc_iss bit51 */
			{ 5243, 3,0}, /* core1 pc_iss bit52 */
			{ 5235, 3,0}, /* core1 pc_iss bit53 */
			{ 5244, 3,0}, /* core1 pc_iss bit54 */
			{ 9385, 2,0}, /* core1 pc_iss bit55 */
			{ 5241, 3,0}, /* core1 pc_iss bit56 */
			{ 5242, 3,0}, /* core1 pc_iss bit57 */
			{ 5236, 3,0}, /* core1 pc_iss bit58 */
			{ 9384, 2,0}, /* core1 pc_iss bit59 */
			{ 5237, 3,0}, /* core1 pc_iss bit60 */
			{ 5238, 3,0}, /* core1 pc_iss bit61 */
			{ 5239, 3,0}, /* core1 pc_iss bit62 */
			{ 5240, 3,0}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 7403, 2,0}, /* core1 full_pc_wr bit0 */
			{    0, 0,2}, /* core1 full_pc_wr bit1 */
			{    0, 0,2}, /* core1 full_pc_wr bit2 */
			{    0, 0,2}, /* core1 full_pc_wr bit3 */
			{    0, 0,2}, /* core1 full_pc_wr bit4 */
			{    0, 0,2}, /* core1 full_pc_wr bit5 */
			{    0, 0,2}, /* core1 full_pc_wr bit6 */
			{    0, 0,2}, /* core1 full_pc_wr bit7 */
			{    0, 0,2}, /* core1 full_pc_wr bit8 */
			{    0, 0,2}, /* core1 full_pc_wr bit9 */
			{    0, 0,2}, /* core1 full_pc_wr bit10 */
			{    0, 0,2}, /* core1 full_pc_wr bit11 */
			{    0, 0,2}, /* core1 full_pc_wr bit12 */
			{    0, 0,2}, /* core1 full_pc_wr bit13 */
			{    0, 0,2}, /* core1 full_pc_wr bit14 */
			{    0, 0,2}, /* core1 full_pc_wr bit15 */
			{    0, 0,2}, /* core1 full_pc_wr bit16 */
			{    0, 0,2}, /* core1 full_pc_wr bit17 */
			{    0, 0,2}, /* core1 full_pc_wr bit18 */
			{    0, 0,2}, /* core1 full_pc_wr bit19 */
			{    0, 0,2}, /* core1 full_pc_wr bit20 */
			{    0, 0,2}, /* core1 full_pc_wr bit21 */
			{    0, 0,2}, /* core1 full_pc_wr bit22 */
			{    0, 0,2}, /* core1 full_pc_wr bit23 */
			{    0, 0,2}, /* core1 full_pc_wr bit24 */
			{    0, 0,2}, /* core1 full_pc_wr bit25 */
			{    0, 0,2}, /* core1 full_pc_wr bit26 */
			{    0, 0,2}, /* core1 full_pc_wr bit27 */
			{    0, 0,2}, /* core1 full_pc_wr bit28 */
			{    0, 0,2}, /* core1 full_pc_wr bit29 */
			{    0, 0,2}, /* core1 full_pc_wr bit30 */
			{    0, 0,2}, /* core1 full_pc_wr bit31 */
			{    0, 0,2}, /* core1 full_pc_wr bit32 */
			{    0, 0,2}, /* core1 full_pc_wr bit33 */
			{    0, 0,2}, /* core1 full_pc_wr bit34 */
			{    0, 0,2}, /* core1 full_pc_wr bit35 */
			{    0, 0,2}, /* core1 full_pc_wr bit36 */
			{    0, 0,2}, /* core1 full_pc_wr bit37 */
			{    0, 0,2}, /* core1 full_pc_wr bit38 */
			{    0, 0,2}, /* core1 full_pc_wr bit39 */
			{    0, 0,2}, /* core1 full_pc_wr bit40 */
			{    0, 0,2}, /* core1 full_pc_wr bit41 */
			{    0, 0,2}, /* core1 full_pc_wr bit42 */
			{    0, 0,2}, /* core1 full_pc_wr bit43 */
			{    0, 0,2}, /* core1 full_pc_wr bit44 */
			{    0, 0,2}, /* core1 full_pc_wr bit45 */
			{    0, 0,2}, /* core1 full_pc_wr bit46 */
			{    0, 0,2}, /* core1 full_pc_wr bit47 */
			{    0, 0,2}, /* core1 full_pc_wr bit48 */
			{    0, 0,2}, /* core1 full_pc_wr bit49 */
			{    0, 0,2}, /* core1 full_pc_wr bit50 */
			{    0, 0,2}, /* core1 full_pc_wr bit51 */
			{    0, 0,2}, /* core1 full_pc_wr bit52 */
			{    0, 0,2}, /* core1 full_pc_wr bit53 */
			{    0, 0,2}, /* core1 full_pc_wr bit54 */
			{    0, 0,2}, /* core1 full_pc_wr bit55 */
			{    0, 0,2}, /* core1 full_pc_wr bit56 */
			{    0, 0,2}, /* core1 full_pc_wr bit57 */
			{    0, 0,2}, /* core1 full_pc_wr bit58 */
			{    0, 0,2}, /* core1 full_pc_wr bit59 */
			{    0, 0,2}, /* core1 full_pc_wr bit60 */
			{    0, 0,2}, /* core1 full_pc_wr bit61 */
			{    0, 0,2}, /* core1 full_pc_wr bit62 */
			{    0, 0,2}, /* core1 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{ 5400, 3,0}, /* core1 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{ 7406, 2,0}, /* core1 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{16329, 3,0}, /* core1 return_Stack_pointer bit0 */
			{14948, 3,0}, /* core1 return_Stack_pointer bit1 */
			{16328, 3,0}, /* core1 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{16729, 3,0}, /* core1 return_Stack0 bit0 */
			{16728, 3,0}, /* core1 return_Stack0 bit1 */
			{16727, 3,0}, /* core1 return_Stack0 bit2 */
			{16726, 3,0}, /* core1 return_Stack0 bit3 */
			{16721, 3,0}, /* core1 return_Stack0 bit4 */
			{16720, 3,0}, /* core1 return_Stack0 bit5 */
			{16719, 3,0}, /* core1 return_Stack0 bit6 */
			{16718, 3,0}, /* core1 return_Stack0 bit7 */
			{12983, 3,0}, /* core1 return_Stack0 bit8 */
			{12982, 3,0}, /* core1 return_Stack0 bit9 */
			{12981, 3,0}, /* core1 return_Stack0 bit10 */
			{12980, 3,0}, /* core1 return_Stack0 bit11 */
			{16789, 3,0}, /* core1 return_Stack0 bit12 */
			{16788, 3,0}, /* core1 return_Stack0 bit13 */
			{16787, 3,0}, /* core1 return_Stack0 bit14 */
			{16786, 3,0}, /* core1 return_Stack0 bit15 */
			{16725, 3,0}, /* core1 return_Stack0 bit16 */
			{16724, 3,0}, /* core1 return_Stack0 bit17 */
			{16723, 3,0}, /* core1 return_Stack0 bit18 */
			{16722, 3,0}, /* core1 return_Stack0 bit19 */
			{13019, 3,0}, /* core1 return_Stack0 bit20 */
			{13018, 3,0}, /* core1 return_Stack0 bit21 */
			{13017, 3,0}, /* core1 return_Stack0 bit22 */
			{13016, 3,0}, /* core1 return_Stack0 bit23 */
			{13092, 3,0}, /* core1 return_Stack0 bit24 */
			{13091, 3,0}, /* core1 return_Stack0 bit25 */
			{13090, 3,0}, /* core1 return_Stack0 bit26 */
			{13089, 3,0}, /* core1 return_Stack0 bit27 */
			{13040, 3,0}, /* core1 return_Stack0 bit28 */
			{13039, 3,0}, /* core1 return_Stack0 bit29 */
			{13038, 3,0}, /* core1 return_Stack0 bit30 */
			{13037, 3,0}, /* core1 return_Stack0 bit31 */
			{13052, 3,0}, /* core1 return_Stack0 bit32 */
			{13051, 3,0}, /* core1 return_Stack0 bit33 */
			{13050, 3,0}, /* core1 return_Stack0 bit34 */
			{13049, 3,0}, /* core1 return_Stack0 bit35 */
			{13072, 3,0}, /* core1 return_Stack0 bit36 */
			{13071, 3,0}, /* core1 return_Stack0 bit37 */
			{13070, 3,0}, /* core1 return_Stack0 bit38 */
			{13069, 3,0}, /* core1 return_Stack0 bit39 */
			{13064, 3,0}, /* core1 return_Stack0 bit40 */
			{13063, 3,0}, /* core1 return_Stack0 bit41 */
			{13062, 3,0}, /* core1 return_Stack0 bit42 */
			{13061, 3,0}, /* core1 return_Stack0 bit43 */
			{13068, 3,0}, /* core1 return_Stack0 bit44 */
			{13067, 3,0}, /* core1 return_Stack0 bit45 */
			{13066, 3,0}, /* core1 return_Stack0 bit46 */
			{13065, 3,0}, /* core1 return_Stack0 bit47 */
			{13036, 3,0}, /* core1 return_Stack0 bit48 */
			{    0, 0,2}, /* core1 return_Stack0 bit49 */
			{    0, 0,2}, /* core1 return_Stack0 bit50 */
			{    0, 0,2}, /* core1 return_Stack0 bit51 */
			{    0, 0,2}, /* core1 return_Stack0 bit52 */
			{    0, 0,2}, /* core1 return_Stack0 bit53 */
			{    0, 0,2}, /* core1 return_Stack0 bit54 */
			{    0, 0,2}, /* core1 return_Stack0 bit55 */
			{    0, 0,2}, /* core1 return_Stack0 bit56 */
			{    0, 0,2}, /* core1 return_Stack0 bit57 */
			{    0, 0,2}, /* core1 return_Stack0 bit58 */
			{    0, 0,2}, /* core1 return_Stack0 bit59 */
			{    0, 0,2}, /* core1 return_Stack0 bit60 */
			{    0, 0,2}, /* core1 return_Stack0 bit61 */
			{    0, 0,2}, /* core1 return_Stack0 bit62 */
			{    0, 0,2}, /* core1 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{16705, 3,0}, /* core1 return_Stack1 bit0 */
			{16704, 3,0}, /* core1 return_Stack1 bit1 */
			{16703, 3,0}, /* core1 return_Stack1 bit2 */
			{16702, 3,0}, /* core1 return_Stack1 bit3 */
			{16701, 3,0}, /* core1 return_Stack1 bit4 */
			{16700, 3,0}, /* core1 return_Stack1 bit5 */
			{16699, 3,0}, /* core1 return_Stack1 bit6 */
			{16698, 3,0}, /* core1 return_Stack1 bit7 */
			{12995, 3,0}, /* core1 return_Stack1 bit8 */
			{12994, 3,0}, /* core1 return_Stack1 bit9 */
			{12993, 3,0}, /* core1 return_Stack1 bit10 */
			{12992, 3,0}, /* core1 return_Stack1 bit11 */
			{16761, 3,0}, /* core1 return_Stack1 bit12 */
			{16760, 3,0}, /* core1 return_Stack1 bit13 */
			{16759, 3,0}, /* core1 return_Stack1 bit14 */
			{16758, 3,0}, /* core1 return_Stack1 bit15 */
			{16753, 3,0}, /* core1 return_Stack1 bit16 */
			{16752, 3,0}, /* core1 return_Stack1 bit17 */
			{16751, 3,0}, /* core1 return_Stack1 bit18 */
			{16750, 3,0}, /* core1 return_Stack1 bit19 */
			{16765, 3,0}, /* core1 return_Stack1 bit20 */
			{16764, 3,0}, /* core1 return_Stack1 bit21 */
			{16763, 3,0}, /* core1 return_Stack1 bit22 */
			{16762, 3,0}, /* core1 return_Stack1 bit23 */
			{16773, 3,0}, /* core1 return_Stack1 bit24 */
			{16772, 3,0}, /* core1 return_Stack1 bit25 */
			{16771, 3,0}, /* core1 return_Stack1 bit26 */
			{16770, 3,0}, /* core1 return_Stack1 bit27 */
			{16777, 3,0}, /* core1 return_Stack1 bit28 */
			{16776, 3,0}, /* core1 return_Stack1 bit29 */
			{16775, 3,0}, /* core1 return_Stack1 bit30 */
			{16774, 3,0}, /* core1 return_Stack1 bit31 */
			{12963, 3,0}, /* core1 return_Stack1 bit32 */
			{12962, 3,0}, /* core1 return_Stack1 bit33 */
			{12961, 3,0}, /* core1 return_Stack1 bit34 */
			{12960, 3,0}, /* core1 return_Stack1 bit35 */
			{12929, 3,0}, /* core1 return_Stack1 bit36 */
			{12928, 3,0}, /* core1 return_Stack1 bit37 */
			{12927, 3,0}, /* core1 return_Stack1 bit38 */
			{12926, 3,0}, /* core1 return_Stack1 bit39 */
			{12941, 3,0}, /* core1 return_Stack1 bit40 */
			{12940, 3,0}, /* core1 return_Stack1 bit41 */
			{12939, 3,0}, /* core1 return_Stack1 bit42 */
			{12938, 3,0}, /* core1 return_Stack1 bit43 */
			{12937, 3,0}, /* core1 return_Stack1 bit44 */
			{12936, 3,0}, /* core1 return_Stack1 bit45 */
			{12935, 3,0}, /* core1 return_Stack1 bit46 */
			{12934, 3,0}, /* core1 return_Stack1 bit47 */
			{14950, 3,0}, /* core1 return_Stack1 bit48 */
			{    0, 0,2}, /* core1 return_Stack1 bit49 */
			{    0, 0,2}, /* core1 return_Stack1 bit50 */
			{    0, 0,2}, /* core1 return_Stack1 bit51 */
			{    0, 0,2}, /* core1 return_Stack1 bit52 */
			{    0, 0,2}, /* core1 return_Stack1 bit53 */
			{    0, 0,2}, /* core1 return_Stack1 bit54 */
			{    0, 0,2}, /* core1 return_Stack1 bit55 */
			{    0, 0,2}, /* core1 return_Stack1 bit56 */
			{    0, 0,2}, /* core1 return_Stack1 bit57 */
			{    0, 0,2}, /* core1 return_Stack1 bit58 */
			{    0, 0,2}, /* core1 return_Stack1 bit59 */
			{    0, 0,2}, /* core1 return_Stack1 bit60 */
			{    0, 0,2}, /* core1 return_Stack1 bit61 */
			{    0, 0,2}, /* core1 return_Stack1 bit62 */
			{    0, 0,2}, /* core1 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{12987, 3,0}, /* core1 return_Stack2 bit0 */
			{12986, 3,0}, /* core1 return_Stack2 bit1 */
			{12985, 3,0}, /* core1 return_Stack2 bit2 */
			{12984, 3,0}, /* core1 return_Stack2 bit3 */
			{16669, 3,0}, /* core1 return_Stack2 bit4 */
			{16668, 3,0}, /* core1 return_Stack2 bit5 */
			{16667, 3,0}, /* core1 return_Stack2 bit6 */
			{16666, 3,0}, /* core1 return_Stack2 bit7 */
			{16685, 3,0}, /* core1 return_Stack2 bit8 */
			{16684, 3,0}, /* core1 return_Stack2 bit9 */
			{16683, 3,0}, /* core1 return_Stack2 bit10 */
			{16682, 3,0}, /* core1 return_Stack2 bit11 */
			{16677, 3,0}, /* core1 return_Stack2 bit12 */
			{16676, 3,0}, /* core1 return_Stack2 bit13 */
			{16675, 3,0}, /* core1 return_Stack2 bit14 */
			{16674, 3,0}, /* core1 return_Stack2 bit15 */
			{16673, 3,0}, /* core1 return_Stack2 bit16 */
			{16672, 3,0}, /* core1 return_Stack2 bit17 */
			{16671, 3,0}, /* core1 return_Stack2 bit18 */
			{16670, 3,0}, /* core1 return_Stack2 bit19 */
			{16657, 3,0}, /* core1 return_Stack2 bit20 */
			{16656, 3,0}, /* core1 return_Stack2 bit21 */
			{16655, 3,0}, /* core1 return_Stack2 bit22 */
			{16654, 3,0}, /* core1 return_Stack2 bit23 */
			{16653, 3,0}, /* core1 return_Stack2 bit24 */
			{16652, 3,0}, /* core1 return_Stack2 bit25 */
			{16651, 3,0}, /* core1 return_Stack2 bit26 */
			{16650, 3,0}, /* core1 return_Stack2 bit27 */
			{16645, 3,0}, /* core1 return_Stack2 bit28 */
			{16644, 3,0}, /* core1 return_Stack2 bit29 */
			{16643, 3,0}, /* core1 return_Stack2 bit30 */
			{16642, 3,0}, /* core1 return_Stack2 bit31 */
			{16633, 3,0}, /* core1 return_Stack2 bit32 */
			{16632, 3,0}, /* core1 return_Stack2 bit33 */
			{16631, 3,0}, /* core1 return_Stack2 bit34 */
			{16630, 3,0}, /* core1 return_Stack2 bit35 */
			{16625, 3,0}, /* core1 return_Stack2 bit36 */
			{16624, 3,0}, /* core1 return_Stack2 bit37 */
			{16623, 3,0}, /* core1 return_Stack2 bit38 */
			{16622, 3,0}, /* core1 return_Stack2 bit39 */
			{16629, 3,0}, /* core1 return_Stack2 bit40 */
			{16628, 3,0}, /* core1 return_Stack2 bit41 */
			{16627, 3,0}, /* core1 return_Stack2 bit42 */
			{16626, 3,0}, /* core1 return_Stack2 bit43 */
			{16637, 3,0}, /* core1 return_Stack2 bit44 */
			{16636, 3,0}, /* core1 return_Stack2 bit45 */
			{16635, 3,0}, /* core1 return_Stack2 bit46 */
			{16634, 3,0}, /* core1 return_Stack2 bit47 */
			{14952, 3,0}, /* core1 return_Stack2 bit48 */
			{    0, 0,2}, /* core1 return_Stack2 bit49 */
			{    0, 0,2}, /* core1 return_Stack2 bit50 */
			{    0, 0,2}, /* core1 return_Stack2 bit51 */
			{    0, 0,2}, /* core1 return_Stack2 bit52 */
			{    0, 0,2}, /* core1 return_Stack2 bit53 */
			{    0, 0,2}, /* core1 return_Stack2 bit54 */
			{    0, 0,2}, /* core1 return_Stack2 bit55 */
			{    0, 0,2}, /* core1 return_Stack2 bit56 */
			{    0, 0,2}, /* core1 return_Stack2 bit57 */
			{    0, 0,2}, /* core1 return_Stack2 bit58 */
			{    0, 0,2}, /* core1 return_Stack2 bit59 */
			{    0, 0,2}, /* core1 return_Stack2 bit60 */
			{    0, 0,2}, /* core1 return_Stack2 bit61 */
			{    0, 0,2}, /* core1 return_Stack2 bit62 */
			{    0, 0,2}, /* core1 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{16697, 3,0}, /* core1 return_Stack3 bit0 */
			{16696, 3,0}, /* core1 return_Stack3 bit1 */
			{16695, 3,0}, /* core1 return_Stack3 bit2 */
			{16694, 3,0}, /* core1 return_Stack3 bit3 */
			{16665, 3,0}, /* core1 return_Stack3 bit4 */
			{16664, 3,0}, /* core1 return_Stack3 bit5 */
			{16663, 3,0}, /* core1 return_Stack3 bit6 */
			{16662, 3,0}, /* core1 return_Stack3 bit7 */
			{16693, 3,0}, /* core1 return_Stack3 bit8 */
			{16692, 3,0}, /* core1 return_Stack3 bit9 */
			{16691, 3,0}, /* core1 return_Stack3 bit10 */
			{16690, 3,0}, /* core1 return_Stack3 bit11 */
			{16681, 3,0}, /* core1 return_Stack3 bit12 */
			{16680, 3,0}, /* core1 return_Stack3 bit13 */
			{16679, 3,0}, /* core1 return_Stack3 bit14 */
			{16678, 3,0}, /* core1 return_Stack3 bit15 */
			{16689, 3,0}, /* core1 return_Stack3 bit16 */
			{16688, 3,0}, /* core1 return_Stack3 bit17 */
			{16687, 3,0}, /* core1 return_Stack3 bit18 */
			{16686, 3,0}, /* core1 return_Stack3 bit19 */
			{16661, 3,0}, /* core1 return_Stack3 bit20 */
			{16660, 3,0}, /* core1 return_Stack3 bit21 */
			{16659, 3,0}, /* core1 return_Stack3 bit22 */
			{16658, 3,0}, /* core1 return_Stack3 bit23 */
			{16641, 3,0}, /* core1 return_Stack3 bit24 */
			{16640, 3,0}, /* core1 return_Stack3 bit25 */
			{16639, 3,0}, /* core1 return_Stack3 bit26 */
			{16638, 3,0}, /* core1 return_Stack3 bit27 */
			{16649, 3,0}, /* core1 return_Stack3 bit28 */
			{16648, 3,0}, /* core1 return_Stack3 bit29 */
			{16647, 3,0}, /* core1 return_Stack3 bit30 */
			{16646, 3,0}, /* core1 return_Stack3 bit31 */
			{12959, 3,0}, /* core1 return_Stack3 bit32 */
			{12958, 3,0}, /* core1 return_Stack3 bit33 */
			{12957, 3,0}, /* core1 return_Stack3 bit34 */
			{12956, 3,0}, /* core1 return_Stack3 bit35 */
			{12951, 3,0}, /* core1 return_Stack3 bit36 */
			{12950, 3,0}, /* core1 return_Stack3 bit37 */
			{12949, 3,0}, /* core1 return_Stack3 bit38 */
			{12948, 3,0}, /* core1 return_Stack3 bit39 */
			{12945, 3,0}, /* core1 return_Stack3 bit40 */
			{12944, 3,0}, /* core1 return_Stack3 bit41 */
			{12943, 3,0}, /* core1 return_Stack3 bit42 */
			{12942, 3,0}, /* core1 return_Stack3 bit43 */
			{12955, 3,0}, /* core1 return_Stack3 bit44 */
			{12954, 3,0}, /* core1 return_Stack3 bit45 */
			{12953, 3,0}, /* core1 return_Stack3 bit46 */
			{12952, 3,0}, /* core1 return_Stack3 bit47 */
			{14949, 3,0}, /* core1 return_Stack3 bit48 */
			{    0, 0,2}, /* core1 return_Stack3 bit49 */
			{    0, 0,2}, /* core1 return_Stack3 bit50 */
			{    0, 0,2}, /* core1 return_Stack3 bit51 */
			{    0, 0,2}, /* core1 return_Stack3 bit52 */
			{    0, 0,2}, /* core1 return_Stack3 bit53 */
			{    0, 0,2}, /* core1 return_Stack3 bit54 */
			{    0, 0,2}, /* core1 return_Stack3 bit55 */
			{    0, 0,2}, /* core1 return_Stack3 bit56 */
			{    0, 0,2}, /* core1 return_Stack3 bit57 */
			{    0, 0,2}, /* core1 return_Stack3 bit58 */
			{    0, 0,2}, /* core1 return_Stack3 bit59 */
			{    0, 0,2}, /* core1 return_Stack3 bit60 */
			{    0, 0,2}, /* core1 return_Stack3 bit61 */
			{    0, 0,2}, /* core1 return_Stack3 bit62 */
			{    0, 0,2}, /* core1 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{13011, 3,0}, /* core1 return_Stack4 bit0 */
			{13010, 3,0}, /* core1 return_Stack4 bit1 */
			{13009, 3,0}, /* core1 return_Stack4 bit2 */
			{13008, 3,0}, /* core1 return_Stack4 bit3 */
			{13003, 3,0}, /* core1 return_Stack4 bit4 */
			{13002, 3,0}, /* core1 return_Stack4 bit5 */
			{13001, 3,0}, /* core1 return_Stack4 bit6 */
			{13000, 3,0}, /* core1 return_Stack4 bit7 */
			{12979, 3,0}, /* core1 return_Stack4 bit8 */
			{12978, 3,0}, /* core1 return_Stack4 bit9 */
			{12977, 3,0}, /* core1 return_Stack4 bit10 */
			{12976, 3,0}, /* core1 return_Stack4 bit11 */
			{12975, 3,0}, /* core1 return_Stack4 bit12 */
			{12974, 3,0}, /* core1 return_Stack4 bit13 */
			{12973, 3,0}, /* core1 return_Stack4 bit14 */
			{12972, 3,0}, /* core1 return_Stack4 bit15 */
			{13015, 3,0}, /* core1 return_Stack4 bit16 */
			{13014, 3,0}, /* core1 return_Stack4 bit17 */
			{13013, 3,0}, /* core1 return_Stack4 bit18 */
			{13012, 3,0}, /* core1 return_Stack4 bit19 */
			{13023, 3,0}, /* core1 return_Stack4 bit20 */
			{13022, 3,0}, /* core1 return_Stack4 bit21 */
			{13021, 3,0}, /* core1 return_Stack4 bit22 */
			{13020, 3,0}, /* core1 return_Stack4 bit23 */
			{13088, 3,0}, /* core1 return_Stack4 bit24 */
			{13087, 3,0}, /* core1 return_Stack4 bit25 */
			{13086, 3,0}, /* core1 return_Stack4 bit26 */
			{13085, 3,0}, /* core1 return_Stack4 bit27 */
			{16309, 3,0}, /* core1 return_Stack4 bit28 */
			{16308, 3,0}, /* core1 return_Stack4 bit29 */
			{16307, 3,0}, /* core1 return_Stack4 bit30 */
			{16306, 3,0}, /* core1 return_Stack4 bit31 */
			{13080, 3,0}, /* core1 return_Stack4 bit32 */
			{13079, 3,0}, /* core1 return_Stack4 bit33 */
			{13078, 3,0}, /* core1 return_Stack4 bit34 */
			{13077, 3,0}, /* core1 return_Stack4 bit35 */
			{18841, 2,0}, /* core1 return_Stack4 bit36 */
			{18840, 2,0}, /* core1 return_Stack4 bit37 */
			{18839, 2,0}, /* core1 return_Stack4 bit38 */
			{18838, 2,0}, /* core1 return_Stack4 bit39 */
			{18837, 2,0}, /* core1 return_Stack4 bit40 */
			{18836, 2,0}, /* core1 return_Stack4 bit41 */
			{18835, 2,0}, /* core1 return_Stack4 bit42 */
			{18834, 2,0}, /* core1 return_Stack4 bit43 */
			{18845, 2,0}, /* core1 return_Stack4 bit44 */
			{18844, 2,0}, /* core1 return_Stack4 bit45 */
			{18843, 2,0}, /* core1 return_Stack4 bit46 */
			{18842, 2,0}, /* core1 return_Stack4 bit47 */
			{14567, 3,0}, /* core1 return_Stack4 bit48 */
			{    0, 0,2}, /* core1 return_Stack4 bit49 */
			{    0, 0,2}, /* core1 return_Stack4 bit50 */
			{    0, 0,2}, /* core1 return_Stack4 bit51 */
			{    0, 0,2}, /* core1 return_Stack4 bit52 */
			{    0, 0,2}, /* core1 return_Stack4 bit53 */
			{    0, 0,2}, /* core1 return_Stack4 bit54 */
			{    0, 0,2}, /* core1 return_Stack4 bit55 */
			{    0, 0,2}, /* core1 return_Stack4 bit56 */
			{    0, 0,2}, /* core1 return_Stack4 bit57 */
			{    0, 0,2}, /* core1 return_Stack4 bit58 */
			{    0, 0,2}, /* core1 return_Stack4 bit59 */
			{    0, 0,2}, /* core1 return_Stack4 bit60 */
			{    0, 0,2}, /* core1 return_Stack4 bit61 */
			{    0, 0,2}, /* core1 return_Stack4 bit62 */
			{    0, 0,2}, /* core1 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{16717, 3,0}, /* core1 return_Stack5 bit0 */
			{16716, 3,0}, /* core1 return_Stack5 bit1 */
			{16715, 3,0}, /* core1 return_Stack5 bit2 */
			{16714, 3,0}, /* core1 return_Stack5 bit3 */
			{16709, 3,0}, /* core1 return_Stack5 bit4 */
			{16708, 3,0}, /* core1 return_Stack5 bit5 */
			{16707, 3,0}, /* core1 return_Stack5 bit6 */
			{16706, 3,0}, /* core1 return_Stack5 bit7 */
			{12991, 3,0}, /* core1 return_Stack5 bit8 */
			{12990, 3,0}, /* core1 return_Stack5 bit9 */
			{12989, 3,0}, /* core1 return_Stack5 bit10 */
			{12988, 3,0}, /* core1 return_Stack5 bit11 */
			{16757, 3,0}, /* core1 return_Stack5 bit12 */
			{16756, 3,0}, /* core1 return_Stack5 bit13 */
			{16755, 3,0}, /* core1 return_Stack5 bit14 */
			{16754, 3,0}, /* core1 return_Stack5 bit15 */
			{16749, 3,0}, /* core1 return_Stack5 bit16 */
			{16748, 3,0}, /* core1 return_Stack5 bit17 */
			{16747, 3,0}, /* core1 return_Stack5 bit18 */
			{16746, 3,0}, /* core1 return_Stack5 bit19 */
			{16769, 3,0}, /* core1 return_Stack5 bit20 */
			{16768, 3,0}, /* core1 return_Stack5 bit21 */
			{16767, 3,0}, /* core1 return_Stack5 bit22 */
			{16766, 3,0}, /* core1 return_Stack5 bit23 */
			{12971, 3,0}, /* core1 return_Stack5 bit24 */
			{12970, 3,0}, /* core1 return_Stack5 bit25 */
			{12969, 3,0}, /* core1 return_Stack5 bit26 */
			{12968, 3,0}, /* core1 return_Stack5 bit27 */
			{12967, 3,0}, /* core1 return_Stack5 bit28 */
			{12966, 3,0}, /* core1 return_Stack5 bit29 */
			{12965, 3,0}, /* core1 return_Stack5 bit30 */
			{12964, 3,0}, /* core1 return_Stack5 bit31 */
			{13056, 3,0}, /* core1 return_Stack5 bit32 */
			{13055, 3,0}, /* core1 return_Stack5 bit33 */
			{13054, 3,0}, /* core1 return_Stack5 bit34 */
			{13053, 3,0}, /* core1 return_Stack5 bit35 */
			{12925, 3,0}, /* core1 return_Stack5 bit36 */
			{12924, 3,0}, /* core1 return_Stack5 bit37 */
			{12923, 3,0}, /* core1 return_Stack5 bit38 */
			{12922, 3,0}, /* core1 return_Stack5 bit39 */
			{12921, 3,0}, /* core1 return_Stack5 bit40 */
			{12920, 3,0}, /* core1 return_Stack5 bit41 */
			{12919, 3,0}, /* core1 return_Stack5 bit42 */
			{12918, 3,0}, /* core1 return_Stack5 bit43 */
			{12933, 3,0}, /* core1 return_Stack5 bit44 */
			{12932, 3,0}, /* core1 return_Stack5 bit45 */
			{12931, 3,0}, /* core1 return_Stack5 bit46 */
			{12930, 3,0}, /* core1 return_Stack5 bit47 */
			{14951, 3,0}, /* core1 return_Stack5 bit48 */
			{    0, 0,2}, /* core1 return_Stack5 bit49 */
			{    0, 0,2}, /* core1 return_Stack5 bit50 */
			{    0, 0,2}, /* core1 return_Stack5 bit51 */
			{    0, 0,2}, /* core1 return_Stack5 bit52 */
			{    0, 0,2}, /* core1 return_Stack5 bit53 */
			{    0, 0,2}, /* core1 return_Stack5 bit54 */
			{    0, 0,2}, /* core1 return_Stack5 bit55 */
			{    0, 0,2}, /* core1 return_Stack5 bit56 */
			{    0, 0,2}, /* core1 return_Stack5 bit57 */
			{    0, 0,2}, /* core1 return_Stack5 bit58 */
			{    0, 0,2}, /* core1 return_Stack5 bit59 */
			{    0, 0,2}, /* core1 return_Stack5 bit60 */
			{    0, 0,2}, /* core1 return_Stack5 bit61 */
			{    0, 0,2}, /* core1 return_Stack5 bit62 */
			{    0, 0,2}, /* core1 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{16737, 3,0}, /* core1 return_Stack6 bit0 */
			{16736, 3,0}, /* core1 return_Stack6 bit1 */
			{16735, 3,0}, /* core1 return_Stack6 bit2 */
			{16734, 3,0}, /* core1 return_Stack6 bit3 */
			{13007, 3,0}, /* core1 return_Stack6 bit4 */
			{13006, 3,0}, /* core1 return_Stack6 bit5 */
			{13005, 3,0}, /* core1 return_Stack6 bit6 */
			{13004, 3,0}, /* core1 return_Stack6 bit7 */
			{12999, 3,0}, /* core1 return_Stack6 bit8 */
			{12998, 3,0}, /* core1 return_Stack6 bit9 */
			{12997, 3,0}, /* core1 return_Stack6 bit10 */
			{12996, 3,0}, /* core1 return_Stack6 bit11 */
			{16781, 3,0}, /* core1 return_Stack6 bit12 */
			{16780, 3,0}, /* core1 return_Stack6 bit13 */
			{16779, 3,0}, /* core1 return_Stack6 bit14 */
			{16778, 3,0}, /* core1 return_Stack6 bit15 */
			{16793, 3,0}, /* core1 return_Stack6 bit16 */
			{16792, 3,0}, /* core1 return_Stack6 bit17 */
			{16791, 3,0}, /* core1 return_Stack6 bit18 */
			{16790, 3,0}, /* core1 return_Stack6 bit19 */
			{13027, 3,0}, /* core1 return_Stack6 bit20 */
			{13026, 3,0}, /* core1 return_Stack6 bit21 */
			{13025, 3,0}, /* core1 return_Stack6 bit22 */
			{13024, 3,0}, /* core1 return_Stack6 bit23 */
			{13096, 3,0}, /* core1 return_Stack6 bit24 */
			{13095, 3,0}, /* core1 return_Stack6 bit25 */
			{13094, 3,0}, /* core1 return_Stack6 bit26 */
			{13093, 3,0}, /* core1 return_Stack6 bit27 */
			{13031, 3,0}, /* core1 return_Stack6 bit28 */
			{13030, 3,0}, /* core1 return_Stack6 bit29 */
			{13029, 3,0}, /* core1 return_Stack6 bit30 */
			{13028, 3,0}, /* core1 return_Stack6 bit31 */
			{13048, 3,0}, /* core1 return_Stack6 bit32 */
			{13047, 3,0}, /* core1 return_Stack6 bit33 */
			{13046, 3,0}, /* core1 return_Stack6 bit34 */
			{13045, 3,0}, /* core1 return_Stack6 bit35 */
			{13084, 3,0}, /* core1 return_Stack6 bit36 */
			{13083, 3,0}, /* core1 return_Stack6 bit37 */
			{13082, 3,0}, /* core1 return_Stack6 bit38 */
			{13081, 3,0}, /* core1 return_Stack6 bit39 */
			{12909, 3,0}, /* core1 return_Stack6 bit40 */
			{12908, 3,0}, /* core1 return_Stack6 bit41 */
			{12907, 3,0}, /* core1 return_Stack6 bit42 */
			{12906, 3,0}, /* core1 return_Stack6 bit43 */
			{13076, 3,0}, /* core1 return_Stack6 bit44 */
			{13075, 3,0}, /* core1 return_Stack6 bit45 */
			{13074, 3,0}, /* core1 return_Stack6 bit46 */
			{13073, 3,0}, /* core1 return_Stack6 bit47 */
			{14568, 3,0}, /* core1 return_Stack6 bit48 */
			{    0, 0,2}, /* core1 return_Stack6 bit49 */
			{    0, 0,2}, /* core1 return_Stack6 bit50 */
			{    0, 0,2}, /* core1 return_Stack6 bit51 */
			{    0, 0,2}, /* core1 return_Stack6 bit52 */
			{    0, 0,2}, /* core1 return_Stack6 bit53 */
			{    0, 0,2}, /* core1 return_Stack6 bit54 */
			{    0, 0,2}, /* core1 return_Stack6 bit55 */
			{    0, 0,2}, /* core1 return_Stack6 bit56 */
			{    0, 0,2}, /* core1 return_Stack6 bit57 */
			{    0, 0,2}, /* core1 return_Stack6 bit58 */
			{    0, 0,2}, /* core1 return_Stack6 bit59 */
			{    0, 0,2}, /* core1 return_Stack6 bit60 */
			{    0, 0,2}, /* core1 return_Stack6 bit61 */
			{    0, 0,2}, /* core1 return_Stack6 bit62 */
			{    0, 0,2}, /* core1 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{16733, 3,0}, /* core1 return_Stack7 bit0 */
			{16732, 3,0}, /* core1 return_Stack7 bit1 */
			{16731, 3,0}, /* core1 return_Stack7 bit2 */
			{16730, 3,0}, /* core1 return_Stack7 bit3 */
			{16713, 3,0}, /* core1 return_Stack7 bit4 */
			{16712, 3,0}, /* core1 return_Stack7 bit5 */
			{16711, 3,0}, /* core1 return_Stack7 bit6 */
			{16710, 3,0}, /* core1 return_Stack7 bit7 */
			{16745, 3,0}, /* core1 return_Stack7 bit8 */
			{16744, 3,0}, /* core1 return_Stack7 bit9 */
			{16743, 3,0}, /* core1 return_Stack7 bit10 */
			{16742, 3,0}, /* core1 return_Stack7 bit11 */
			{16785, 3,0}, /* core1 return_Stack7 bit12 */
			{16784, 3,0}, /* core1 return_Stack7 bit13 */
			{16783, 3,0}, /* core1 return_Stack7 bit14 */
			{16782, 3,0}, /* core1 return_Stack7 bit15 */
			{16741, 3,0}, /* core1 return_Stack7 bit16 */
			{16740, 3,0}, /* core1 return_Stack7 bit17 */
			{16739, 3,0}, /* core1 return_Stack7 bit18 */
			{16738, 3,0}, /* core1 return_Stack7 bit19 */
			{16801, 3,0}, /* core1 return_Stack7 bit20 */
			{16800, 3,0}, /* core1 return_Stack7 bit21 */
			{16799, 3,0}, /* core1 return_Stack7 bit22 */
			{16798, 3,0}, /* core1 return_Stack7 bit23 */
			{16797, 3,0}, /* core1 return_Stack7 bit24 */
			{16796, 3,0}, /* core1 return_Stack7 bit25 */
			{16795, 3,0}, /* core1 return_Stack7 bit26 */
			{16794, 3,0}, /* core1 return_Stack7 bit27 */
			{13035, 3,0}, /* core1 return_Stack7 bit28 */
			{13034, 3,0}, /* core1 return_Stack7 bit29 */
			{13033, 3,0}, /* core1 return_Stack7 bit30 */
			{13032, 3,0}, /* core1 return_Stack7 bit31 */
			{13044, 3,0}, /* core1 return_Stack7 bit32 */
			{13043, 3,0}, /* core1 return_Stack7 bit33 */
			{13042, 3,0}, /* core1 return_Stack7 bit34 */
			{13041, 3,0}, /* core1 return_Stack7 bit35 */
			{12913, 3,0}, /* core1 return_Stack7 bit36 */
			{12912, 3,0}, /* core1 return_Stack7 bit37 */
			{12911, 3,0}, /* core1 return_Stack7 bit38 */
			{12910, 3,0}, /* core1 return_Stack7 bit39 */
			{12917, 3,0}, /* core1 return_Stack7 bit40 */
			{12916, 3,0}, /* core1 return_Stack7 bit41 */
			{12915, 3,0}, /* core1 return_Stack7 bit42 */
			{12914, 3,0}, /* core1 return_Stack7 bit43 */
			{13060, 3,0}, /* core1 return_Stack7 bit44 */
			{13059, 3,0}, /* core1 return_Stack7 bit45 */
			{13058, 3,0}, /* core1 return_Stack7 bit46 */
			{13057, 3,0}, /* core1 return_Stack7 bit47 */
			{14569, 3,0}, /* core1 return_Stack7 bit48 */
			{    0, 0,2}, /* core1 return_Stack7 bit49 */
			{    0, 0,2}, /* core1 return_Stack7 bit50 */
			{    0, 0,2}, /* core1 return_Stack7 bit51 */
			{    0, 0,2}, /* core1 return_Stack7 bit52 */
			{    0, 0,2}, /* core1 return_Stack7 bit53 */
			{    0, 0,2}, /* core1 return_Stack7 bit54 */
			{    0, 0,2}, /* core1 return_Stack7 bit55 */
			{    0, 0,2}, /* core1 return_Stack7 bit56 */
			{    0, 0,2}, /* core1 return_Stack7 bit57 */
			{    0, 0,2}, /* core1 return_Stack7 bit58 */
			{    0, 0,2}, /* core1 return_Stack7 bit59 */
			{    0, 0,2}, /* core1 return_Stack7 bit60 */
			{    0, 0,2}, /* core1 return_Stack7 bit61 */
			{    0, 0,2}, /* core1 return_Stack7 bit62 */
			{    0, 0,2}, /* core1 return_Stack7 bit63 */
			}},
	},
	{		/* core 2 */
			.pc = {{
			{   37, 4,0}, /* core2 pc bit0 */
			{  105, 4,0}, /* core2 pc bit1 */
			{   28, 4,0}, /* core2 pc bit2 */
			{   67, 4,0}, /* core2 pc bit3 */
			{   66, 4,0}, /* core2 pc bit4 */
			{   65, 4,0}, /* core2 pc bit5 */
			{  104, 4,0}, /* core2 pc bit6 */
			{   34, 4,0}, /* core2 pc bit7 */
			{   33, 4,0}, /* core2 pc bit8 */
			{   32, 4,0}, /* core2 pc bit9 */
			{   55, 4,0}, /* core2 pc bit10 */
			{   54, 4,0}, /* core2 pc bit11 */
			{   53, 4,0}, /* core2 pc bit12 */
			{   52, 4,0}, /* core2 pc bit13 */
			{   36, 4,0}, /* core2 pc bit14 */
			{   51, 4,0}, /* core2 pc bit15 */
			{   50, 4,0}, /* core2 pc bit16 */
			{   49, 4,0}, /* core2 pc bit17 */
			{   48, 4,0}, /* core2 pc bit18 */
			{ 2483, 4,0}, /* core2 pc bit19 */
			{   64, 4,0}, /* core2 pc bit20 */
			{   43, 4,0}, /* core2 pc bit21 */
			{   42, 4,0}, /* core2 pc bit22 */
			{   41, 4,0}, /* core2 pc bit23 */
			{   40, 4,0}, /* core2 pc bit24 */
			{   47, 4,0}, /* core2 pc bit25 */
			{   46, 4,0}, /* core2 pc bit26 */
			{   45, 4,0}, /* core2 pc bit27 */
			{   44, 4,0}, /* core2 pc bit28 */
			{ 2479, 4,0}, /* core2 pc bit29 */
			{ 2478, 4,0}, /* core2 pc bit30 */
			{  119, 4,0}, /* core2 pc bit31 */
			{12041, 4,0}, /* core2 pc bit32 */
			{12040, 4,0}, /* core2 pc bit33 */
			{12039, 4,0}, /* core2 pc bit34 */
			{12038, 4,0}, /* core2 pc bit35 */
			{10951, 4,0}, /* core2 pc bit36 */
			{10950, 4,0}, /* core2 pc bit37 */
			{10949, 4,0}, /* core2 pc bit38 */
			{10948, 4,0}, /* core2 pc bit39 */
			{  146, 4,0}, /* core2 pc bit40 */
			{12113, 4,0}, /* core2 pc bit41 */
			{10955, 4,0}, /* core2 pc bit42 */
			{  145, 4,0}, /* core2 pc bit43 */
			{10954, 4,0}, /* core2 pc bit44 */
			{10953, 4,0}, /* core2 pc bit45 */
			{10952, 4,0}, /* core2 pc bit46 */
			{12105, 4,0}, /* core2 pc bit47 */
			{  144, 4,0}, /* core2 pc bit48 */
			{12104, 4,0}, /* core2 pc bit49 */
			{12103, 4,0}, /* core2 pc bit50 */
			{12112, 4,0}, /* core2 pc bit51 */
			{12111, 4,0}, /* core2 pc bit52 */
			{12102, 4,0}, /* core2 pc bit53 */
			{12109, 4,0}, /* core2 pc bit54 */
			{12108, 4,0}, /* core2 pc bit55 */
			{12107, 4,0}, /* core2 pc bit56 */
			{12106, 4,0}, /* core2 pc bit57 */
			{10959, 4,0}, /* core2 pc bit58 */
			{10958, 4,0}, /* core2 pc bit59 */
			{12110, 4,0}, /* core2 pc bit60 */
			{10957, 4,0}, /* core2 pc bit61 */
			{10956, 4,0}, /* core2 pc bit62 */
			{ 2717, 4,0}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{  221, 5,0}, /* core2 sp32 bit0 */
			{  191, 5,0}, /* core2 sp32 bit1 */
			{  117, 5,0}, /* core2 sp32 bit2 */
			{  113, 5,0}, /* core2 sp32 bit3 */
			{  111, 5,0}, /* core2 sp32 bit4 */
			{   71, 5,0}, /* core2 sp32 bit5 */
			{  123, 5,0}, /* core2 sp32 bit6 */
			{  114, 5,0}, /* core2 sp32 bit7 */
			{  119, 5,0}, /* core2 sp32 bit8 */
			{  107, 5,0}, /* core2 sp32 bit9 */
			{   14, 5,0}, /* core2 sp32 bit10 */
			{  124, 5,0}, /* core2 sp32 bit11 */
			{   72, 5,0}, /* core2 sp32 bit12 */
			{  121, 5,0}, /* core2 sp32 bit13 */
			{   70, 5,0}, /* core2 sp32 bit14 */
			{  112, 5,0}, /* core2 sp32 bit15 */
			{  122, 5,0}, /* core2 sp32 bit16 */
			{  192, 5,0}, /* core2 sp32 bit17 */
			{  118, 5,0}, /* core2 sp32 bit18 */
			{  120, 5,0}, /* core2 sp32 bit19 */
			{  131, 5,0}, /* core2 sp32 bit20 */
			{   15, 5,0}, /* core2 sp32 bit21 */
			{  125, 5,0}, /* core2 sp32 bit22 */
			{  115, 5,0}, /* core2 sp32 bit23 */
			{  132, 5,0}, /* core2 sp32 bit24 */
			{   11, 5,0}, /* core2 sp32 bit25 */
			{   17, 5,0}, /* core2 sp32 bit26 */
			{   10, 5,0}, /* core2 sp32 bit27 */
			{  158, 5,0}, /* core2 sp32 bit28 */
			{   16, 5,0}, /* core2 sp32 bit29 */
			{  194, 5,0}, /* core2 sp32 bit30 */
			{  175, 5,0}, /* core2 sp32 bit31 */
			{ 2071, 5,0}, /* core2 sp32 bit32 */
			{ 2072, 5,0}, /* core2 sp32 bit33 */
			{ 2075, 5,0}, /* core2 sp32 bit34 */
			{ 2059, 5,0}, /* core2 sp32 bit35 */
			{ 2077, 5,0}, /* core2 sp32 bit36 */
			{ 2073, 5,0}, /* core2 sp32 bit37 */
			{ 1999, 5,0}, /* core2 sp32 bit38 */
			{ 2074, 5,0}, /* core2 sp32 bit39 */
			{ 2016, 5,0}, /* core2 sp32 bit40 */
			{ 2000, 5,0}, /* core2 sp32 bit41 */
			{ 1997, 5,0}, /* core2 sp32 bit42 */
			{ 1996, 5,0}, /* core2 sp32 bit43 */
			{ 1998, 5,0}, /* core2 sp32 bit44 */
			{ 1991, 5,0}, /* core2 sp32 bit45 */
			{ 2007, 5,0}, /* core2 sp32 bit46 */
			{ 2316, 5,0}, /* core2 sp32 bit47 */
			{ 7943, 4,0}, /* core2 sp32 bit48 */
			{ 7946, 4,0}, /* core2 sp32 bit49 */
			{ 7975, 4,0}, /* core2 sp32 bit50 */
			{ 7952, 4,0}, /* core2 sp32 bit51 */
			{ 7950, 4,0}, /* core2 sp32 bit52 */
			{ 7944, 4,0}, /* core2 sp32 bit53 */
			{ 7947, 4,0}, /* core2 sp32 bit54 */
			{ 7976, 4,0}, /* core2 sp32 bit55 */
			{ 7949, 4,0}, /* core2 sp32 bit56 */
			{ 7953, 4,0}, /* core2 sp32 bit57 */
			{ 7951, 4,0}, /* core2 sp32 bit58 */
			{ 7954, 4,0}, /* core2 sp32 bit59 */
			{ 7948, 4,0}, /* core2 sp32 bit60 */
			{ 7958, 4,0}, /* core2 sp32 bit61 */
			{ 7945, 4,0}, /* core2 sp32 bit62 */
			{ 1993, 5,0}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{  248, 4,0}, /* core2 fp32 bit0 */
			{  247, 4,0}, /* core2 fp32 bit1 */
			{  253, 4,0}, /* core2 fp32 bit2 */
			{  364, 4,0}, /* core2 fp32 bit3 */
			{  356, 4,0}, /* core2 fp32 bit4 */
			{  246, 4,0}, /* core2 fp32 bit5 */
			{  384, 4,0}, /* core2 fp32 bit6 */
			{  385, 4,0}, /* core2 fp32 bit7 */
			{  258, 4,0}, /* core2 fp32 bit8 */
			{  254, 4,0}, /* core2 fp32 bit9 */
			{  257, 4,0}, /* core2 fp32 bit10 */
			{  392, 4,0}, /* core2 fp32 bit11 */
			{  255, 4,0}, /* core2 fp32 bit12 */
			{  391, 4,0}, /* core2 fp32 bit13 */
			{  387, 4,0}, /* core2 fp32 bit14 */
			{  256, 4,0}, /* core2 fp32 bit15 */
			{  388, 4,0}, /* core2 fp32 bit16 */
			{  354, 4,0}, /* core2 fp32 bit17 */
			{  363, 4,0}, /* core2 fp32 bit18 */
			{  368, 4,0}, /* core2 fp32 bit19 */
			{  335, 4,0}, /* core2 fp32 bit20 */
			{  366, 4,0}, /* core2 fp32 bit21 */
			{  341, 4,0}, /* core2 fp32 bit22 */
			{  339, 4,0}, /* core2 fp32 bit23 */
			{  340, 4,0}, /* core2 fp32 bit24 */
			{  367, 4,0}, /* core2 fp32 bit25 */
			{  337, 4,0}, /* core2 fp32 bit26 */
			{  369, 4,0}, /* core2 fp32 bit27 */
			{  370, 4,0}, /* core2 fp32 bit28 */
			{  336, 4,0}, /* core2 fp32 bit29 */
			{  338, 4,0}, /* core2 fp32 bit30 */
			{  358, 4,0}, /* core2 fp32 bit31 */
			{ 2368, 5,0}, /* core2 fp32 bit32 */
			{ 2381, 5,0}, /* core2 fp32 bit33 */
			{ 2370, 5,0}, /* core2 fp32 bit34 */
			{ 2371, 5,0}, /* core2 fp32 bit35 */
			{ 2386, 5,0}, /* core2 fp32 bit36 */
			{ 2380, 5,0}, /* core2 fp32 bit37 */
			{ 2336, 5,0}, /* core2 fp32 bit38 */
			{ 2379, 5,0}, /* core2 fp32 bit39 */
			{ 2335, 5,0}, /* core2 fp32 bit40 */
			{ 2346, 5,0}, /* core2 fp32 bit41 */
			{ 2339, 5,0}, /* core2 fp32 bit42 */
			{ 2330, 5,0}, /* core2 fp32 bit43 */
			{ 2334, 5,0}, /* core2 fp32 bit44 */
			{ 2345, 5,0}, /* core2 fp32 bit45 */
			{ 2387, 5,0}, /* core2 fp32 bit46 */
			{ 8052, 4,0}, /* core2 fp32 bit47 */
			{ 8054, 4,0}, /* core2 fp32 bit48 */
			{ 2488, 5,0}, /* core2 fp32 bit49 */
			{ 2493, 5,0}, /* core2 fp32 bit50 */
			{ 2506, 5,0}, /* core2 fp32 bit51 */
			{ 2495, 5,0}, /* core2 fp32 bit52 */
			{ 2508, 5,0}, /* core2 fp32 bit53 */
			{ 8051, 4,0}, /* core2 fp32 bit54 */
			{ 2497, 5,0}, /* core2 fp32 bit55 */
			{ 8055, 4,0}, /* core2 fp32 bit56 */
			{ 2498, 5,0}, /* core2 fp32 bit57 */
			{ 8053, 4,0}, /* core2 fp32 bit58 */
			{ 8056, 4,0}, /* core2 fp32 bit59 */
			{ 2492, 5,0}, /* core2 fp32 bit60 */
			{ 2487, 5,0}, /* core2 fp32 bit61 */
			{ 2496, 5,0}, /* core2 fp32 bit62 */
			{ 7942, 4,0}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{  209, 5,0}, /* core2 fp64 bit0 */
			{   50, 5,0}, /* core2 fp64 bit1 */
			{   45, 5,0}, /* core2 fp64 bit2 */
			{  210, 5,0}, /* core2 fp64 bit3 */
			{   58, 5,0}, /* core2 fp64 bit4 */
			{   46, 5,0}, /* core2 fp64 bit5 */
			{  205, 5,0}, /* core2 fp64 bit6 */
			{  213, 5,0}, /* core2 fp64 bit7 */
			{   59, 5,0}, /* core2 fp64 bit8 */
			{  217, 5,0}, /* core2 fp64 bit9 */
			{  207, 5,0}, /* core2 fp64 bit10 */
			{   77, 5,0}, /* core2 fp64 bit11 */
			{  197, 5,0}, /* core2 fp64 bit12 */
			{  200, 5,0}, /* core2 fp64 bit13 */
			{  206, 5,0}, /* core2 fp64 bit14 */
			{  204, 5,0}, /* core2 fp64 bit15 */
			{  199, 5,0}, /* core2 fp64 bit16 */
			{  224, 5,0}, /* core2 fp64 bit17 */
			{  198, 5,0}, /* core2 fp64 bit18 */
			{   83, 5,0}, /* core2 fp64 bit19 */
			{  223, 5,0}, /* core2 fp64 bit20 */
			{  226, 5,0}, /* core2 fp64 bit21 */
			{   61, 5,0}, /* core2 fp64 bit22 */
			{   81, 5,0}, /* core2 fp64 bit23 */
			{   84, 5,0}, /* core2 fp64 bit24 */
			{   80, 5,0}, /* core2 fp64 bit25 */
			{   82, 5,0}, /* core2 fp64 bit26 */
			{   85, 5,0}, /* core2 fp64 bit27 */
			{   78, 5,0}, /* core2 fp64 bit28 */
			{  225, 5,0}, /* core2 fp64 bit29 */
			{   79, 5,0}, /* core2 fp64 bit30 */
			{  215, 5,0}, /* core2 fp64 bit31 */
			{ 1708, 5,0}, /* core2 fp64 bit32 */
			{ 1676, 5,0}, /* core2 fp64 bit33 */
			{ 1677, 5,0}, /* core2 fp64 bit34 */
			{ 1707, 5,0}, /* core2 fp64 bit35 */
			{ 1668, 5,0}, /* core2 fp64 bit36 */
			{ 1675, 5,0}, /* core2 fp64 bit37 */
			{ 1593, 5,0}, /* core2 fp64 bit38 */
			{ 1709, 5,0}, /* core2 fp64 bit39 */
			{ 1594, 5,0}, /* core2 fp64 bit40 */
			{ 1592, 5,0}, /* core2 fp64 bit41 */
			{ 1657, 5,0}, /* core2 fp64 bit42 */
			{ 1589, 5,0}, /* core2 fp64 bit43 */
			{ 1632, 5,0}, /* core2 fp64 bit44 */
			{ 1590, 5,0}, /* core2 fp64 bit45 */
			{ 1591, 5,0}, /* core2 fp64 bit46 */
			{ 3287, 5,0}, /* core2 fp64 bit47 */
			{ 3373, 5,0}, /* core2 fp64 bit48 */
			{ 3292, 5,0}, /* core2 fp64 bit49 */
			{ 3375, 5,0}, /* core2 fp64 bit50 */
			{ 3374, 5,0}, /* core2 fp64 bit51 */
			{ 3286, 5,0}, /* core2 fp64 bit52 */
			{ 3294, 5,0}, /* core2 fp64 bit53 */
			{ 3366, 5,0}, /* core2 fp64 bit54 */
			{ 3371, 5,0}, /* core2 fp64 bit55 */
			{ 3297, 5,0}, /* core2 fp64 bit56 */
			{ 3365, 5,0}, /* core2 fp64 bit57 */
			{ 3376, 5,0}, /* core2 fp64 bit58 */
			{ 3296, 5,0}, /* core2 fp64 bit59 */
			{ 3369, 5,0}, /* core2 fp64 bit60 */
			{ 3372, 5,0}, /* core2 fp64 bit61 */
			{ 3368, 5,0}, /* core2 fp64 bit62 */
			{ 1631, 5,0}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{   56, 5,0}, /* core2 sp_EL0 bit0 */
			{   47, 5,0}, /* core2 sp_EL0 bit1 */
			{   49, 5,0}, /* core2 sp_EL0 bit2 */
			{   48, 5,0}, /* core2 sp_EL0 bit3 */
			{   53, 5,0}, /* core2 sp_EL0 bit4 */
			{   52, 5,0}, /* core2 sp_EL0 bit5 */
			{ 1254, 5,0}, /* core2 sp_EL0 bit6 */
			{ 1277, 5,0}, /* core2 sp_EL0 bit7 */
			{   41, 5,0}, /* core2 sp_EL0 bit8 */
			{ 1300, 5,0}, /* core2 sp_EL0 bit9 */
			{   44, 5,0}, /* core2 sp_EL0 bit10 */
			{   40, 5,0}, /* core2 sp_EL0 bit11 */
			{   43, 5,0}, /* core2 sp_EL0 bit12 */
			{   57, 5,0}, /* core2 sp_EL0 bit13 */
			{ 1273, 5,0}, /* core2 sp_EL0 bit14 */
			{   51, 5,0}, /* core2 sp_EL0 bit15 */
			{   42, 5,0}, /* core2 sp_EL0 bit16 */
			{   22, 5,0}, /* core2 sp_EL0 bit17 */
			{   60, 5,0}, /* core2 sp_EL0 bit18 */
			{   39, 5,0}, /* core2 sp_EL0 bit19 */
			{ 1338, 5,0}, /* core2 sp_EL0 bit20 */
			{ 1247, 5,0}, /* core2 sp_EL0 bit21 */
			{ 1350, 5,0}, /* core2 sp_EL0 bit22 */
			{ 1332, 5,0}, /* core2 sp_EL0 bit23 */
			{ 1253, 5,0}, /* core2 sp_EL0 bit24 */
			{ 1252, 5,0}, /* core2 sp_EL0 bit25 */
			{ 1333, 5,0}, /* core2 sp_EL0 bit26 */
			{ 1335, 5,0}, /* core2 sp_EL0 bit27 */
			{ 1347, 5,0}, /* core2 sp_EL0 bit28 */
			{ 1251, 5,0}, /* core2 sp_EL0 bit29 */
			{ 1349, 5,0}, /* core2 sp_EL0 bit30 */
			{ 1257, 5,0}, /* core2 sp_EL0 bit31 */
			{ 1060, 5,0}, /* core2 sp_EL0 bit32 */
			{ 1719, 5,0}, /* core2 sp_EL0 bit33 */
			{ 1700, 5,0}, /* core2 sp_EL0 bit34 */
			{ 1701, 5,0}, /* core2 sp_EL0 bit35 */
			{ 1655, 5,0}, /* core2 sp_EL0 bit36 */
			{ 1059, 5,0}, /* core2 sp_EL0 bit37 */
			{ 1653, 5,0}, /* core2 sp_EL0 bit38 */
			{ 1704, 5,0}, /* core2 sp_EL0 bit39 */
			{ 1634, 5,0}, /* core2 sp_EL0 bit40 */
			{ 1637, 5,0}, /* core2 sp_EL0 bit41 */
			{ 1687, 5,0}, /* core2 sp_EL0 bit42 */
			{ 1633, 5,0}, /* core2 sp_EL0 bit43 */
			{ 1651, 5,0}, /* core2 sp_EL0 bit44 */
			{ 1636, 5,0}, /* core2 sp_EL0 bit45 */
			{ 1587, 5,0}, /* core2 sp_EL0 bit46 */
			{ 3370, 5,0}, /* core2 sp_EL0 bit47 */
			{ 3347, 5,0}, /* core2 sp_EL0 bit48 */
			{ 3345, 5,0}, /* core2 sp_EL0 bit49 */
			{ 3349, 5,0}, /* core2 sp_EL0 bit50 */
			{ 3354, 5,0}, /* core2 sp_EL0 bit51 */
			{ 3343, 5,0}, /* core2 sp_EL0 bit52 */
			{ 3341, 5,0}, /* core2 sp_EL0 bit53 */
			{ 3351, 5,0}, /* core2 sp_EL0 bit54 */
			{ 3344, 5,0}, /* core2 sp_EL0 bit55 */
			{ 3337, 5,0}, /* core2 sp_EL0 bit56 */
			{ 3346, 5,0}, /* core2 sp_EL0 bit57 */
			{ 3338, 5,0}, /* core2 sp_EL0 bit58 */
			{ 3342, 5,0}, /* core2 sp_EL0 bit59 */
			{ 3340, 5,0}, /* core2 sp_EL0 bit60 */
			{ 3353, 5,0}, /* core2 sp_EL0 bit61 */
			{ 3339, 5,0}, /* core2 sp_EL0 bit62 */
			{ 1658, 5,0}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{  208, 5,0}, /* core2 sp_EL1 bit0 */
			{  202, 5,0}, /* core2 sp_EL1 bit1 */
			{  211, 5,0}, /* core2 sp_EL1 bit2 */
			{  201, 5,0}, /* core2 sp_EL1 bit3 */
			{   89, 5,0}, /* core2 sp_EL1 bit4 */
			{  212, 5,0}, /* core2 sp_EL1 bit5 */
			{  138, 5,0}, /* core2 sp_EL1 bit6 */
			{   68, 5,0}, /* core2 sp_EL1 bit7 */
			{   69, 5,0}, /* core2 sp_EL1 bit8 */
			{  196, 5,0}, /* core2 sp_EL1 bit9 */
			{   76, 5,0}, /* core2 sp_EL1 bit10 */
			{  218, 5,0}, /* core2 sp_EL1 bit11 */
			{   13, 5,0}, /* core2 sp_EL1 bit12 */
			{  195, 5,0}, /* core2 sp_EL1 bit13 */
			{   12, 5,0}, /* core2 sp_EL1 bit14 */
			{  220, 5,0}, /* core2 sp_EL1 bit15 */
			{  219, 5,0}, /* core2 sp_EL1 bit16 */
			{   75, 5,0}, /* core2 sp_EL1 bit17 */
			{   19, 5,0}, /* core2 sp_EL1 bit18 */
			{  133, 5,0}, /* core2 sp_EL1 bit19 */
			{  136, 5,0}, /* core2 sp_EL1 bit20 */
			{   73, 5,0}, /* core2 sp_EL1 bit21 */
			{  141, 5,0}, /* core2 sp_EL1 bit22 */
			{  137, 5,0}, /* core2 sp_EL1 bit23 */
			{  139, 5,0}, /* core2 sp_EL1 bit24 */
			{  135, 5,0}, /* core2 sp_EL1 bit25 */
			{  222, 5,0}, /* core2 sp_EL1 bit26 */
			{   86, 5,0}, /* core2 sp_EL1 bit27 */
			{  134, 5,0}, /* core2 sp_EL1 bit28 */
			{   74, 5,0}, /* core2 sp_EL1 bit29 */
			{  116, 5,0}, /* core2 sp_EL1 bit30 */
			{   88, 5,0}, /* core2 sp_EL1 bit31 */
			{ 1697, 5,0}, /* core2 sp_EL1 bit32 */
			{ 1695, 5,0}, /* core2 sp_EL1 bit33 */
			{ 1698, 5,0}, /* core2 sp_EL1 bit34 */
			{ 1696, 5,0}, /* core2 sp_EL1 bit35 */
			{ 1679, 5,0}, /* core2 sp_EL1 bit36 */
			{ 1699, 5,0}, /* core2 sp_EL1 bit37 */
			{ 1684, 5,0}, /* core2 sp_EL1 bit38 */
			{ 1694, 5,0}, /* core2 sp_EL1 bit39 */
			{ 1656, 5,0}, /* core2 sp_EL1 bit40 */
			{ 1686, 5,0}, /* core2 sp_EL1 bit41 */
			{ 1678, 5,0}, /* core2 sp_EL1 bit42 */
			{ 1680, 5,0}, /* core2 sp_EL1 bit43 */
			{ 1691, 5,0}, /* core2 sp_EL1 bit44 */
			{ 1586, 5,0}, /* core2 sp_EL1 bit45 */
			{ 1685, 5,0}, /* core2 sp_EL1 bit46 */
			{ 1035, 5,0}, /* core2 sp_EL1 bit47 */
			{ 3288, 5,0}, /* core2 sp_EL1 bit48 */
			{ 1034, 5,0}, /* core2 sp_EL1 bit49 */
			{ 3285, 5,0}, /* core2 sp_EL1 bit50 */
			{ 3289, 5,0}, /* core2 sp_EL1 bit51 */
			{ 3268, 5,0}, /* core2 sp_EL1 bit52 */
			{ 1019, 5,0}, /* core2 sp_EL1 bit53 */
			{ 1023, 5,0}, /* core2 sp_EL1 bit54 */
			{ 3290, 5,0}, /* core2 sp_EL1 bit55 */
			{ 3295, 5,0}, /* core2 sp_EL1 bit56 */
			{ 3302, 5,0}, /* core2 sp_EL1 bit57 */
			{ 3293, 5,0}, /* core2 sp_EL1 bit58 */
			{ 3283, 5,0}, /* core2 sp_EL1 bit59 */
			{ 3299, 5,0}, /* core2 sp_EL1 bit60 */
			{ 3291, 5,0}, /* core2 sp_EL1 bit61 */
			{ 1020, 5,0}, /* core2 sp_EL1 bit62 */
			{ 1693, 5,0}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 1307, 5,0}, /* core2 sp_EL2 bit0 */
			{ 1283, 5,0}, /* core2 sp_EL2 bit1 */
			{ 1308, 5,0}, /* core2 sp_EL2 bit2 */
			{ 1255, 5,0}, /* core2 sp_EL2 bit3 */
			{ 1265, 5,0}, /* core2 sp_EL2 bit4 */
			{ 1256, 5,0}, /* core2 sp_EL2 bit5 */
			{ 1280, 5,0}, /* core2 sp_EL2 bit6 */
			{ 1278, 5,0}, /* core2 sp_EL2 bit7 */
			{ 1303, 5,0}, /* core2 sp_EL2 bit8 */
			{ 1285, 5,0}, /* core2 sp_EL2 bit9 */
			{ 1313, 5,0}, /* core2 sp_EL2 bit10 */
			{ 1302, 5,0}, /* core2 sp_EL2 bit11 */
			{ 1310, 5,0}, /* core2 sp_EL2 bit12 */
			{ 1304, 5,0}, /* core2 sp_EL2 bit13 */
			{ 1275, 5,0}, /* core2 sp_EL2 bit14 */
			{ 1312, 5,0}, /* core2 sp_EL2 bit15 */
			{ 1311, 5,0}, /* core2 sp_EL2 bit16 */
			{ 1258, 5,0}, /* core2 sp_EL2 bit17 */
			{ 1250, 5,0}, /* core2 sp_EL2 bit18 */
			{ 1368, 5,0}, /* core2 sp_EL2 bit19 */
			{ 1369, 5,0}, /* core2 sp_EL2 bit20 */
			{ 1358, 5,0}, /* core2 sp_EL2 bit21 */
			{ 1361, 5,0}, /* core2 sp_EL2 bit22 */
			{ 1375, 5,0}, /* core2 sp_EL2 bit23 */
			{ 1374, 5,0}, /* core2 sp_EL2 bit24 */
			{ 1370, 5,0}, /* core2 sp_EL2 bit25 */
			{ 1372, 5,0}, /* core2 sp_EL2 bit26 */
			{ 1371, 5,0}, /* core2 sp_EL2 bit27 */
			{ 1376, 5,0}, /* core2 sp_EL2 bit28 */
			{ 1373, 5,0}, /* core2 sp_EL2 bit29 */
			{ 1367, 5,0}, /* core2 sp_EL2 bit30 */
			{ 1264, 5,0}, /* core2 sp_EL2 bit31 */
			{ 1042, 5,0}, /* core2 sp_EL2 bit32 */
			{ 1047, 5,0}, /* core2 sp_EL2 bit33 */
			{ 1043, 5,0}, /* core2 sp_EL2 bit34 */
			{ 1041, 5,0}, /* core2 sp_EL2 bit35 */
			{ 1046, 5,0}, /* core2 sp_EL2 bit36 */
			{ 1040, 5,0}, /* core2 sp_EL2 bit37 */
			{ 1088, 5,0}, /* core2 sp_EL2 bit38 */
			{ 1050, 5,0}, /* core2 sp_EL2 bit39 */
			{ 1090, 5,0}, /* core2 sp_EL2 bit40 */
			{ 1084, 5,0}, /* core2 sp_EL2 bit41 */
			{ 1087, 5,0}, /* core2 sp_EL2 bit42 */
			{ 1089, 5,0}, /* core2 sp_EL2 bit43 */
			{ 1091, 5,0}, /* core2 sp_EL2 bit44 */
			{ 1092, 5,0}, /* core2 sp_EL2 bit45 */
			{ 1081, 5,0}, /* core2 sp_EL2 bit46 */
			{ 3180, 5,0}, /* core2 sp_EL2 bit47 */
			{ 3190, 5,0}, /* core2 sp_EL2 bit48 */
			{ 3183, 5,0}, /* core2 sp_EL2 bit49 */
			{ 3194, 5,0}, /* core2 sp_EL2 bit50 */
			{ 3192, 5,0}, /* core2 sp_EL2 bit51 */
			{ 3195, 5,0}, /* core2 sp_EL2 bit52 */
			{ 3197, 5,0}, /* core2 sp_EL2 bit53 */
			{ 3182, 5,0}, /* core2 sp_EL2 bit54 */
			{ 3186, 5,0}, /* core2 sp_EL2 bit55 */
			{ 3193, 5,0}, /* core2 sp_EL2 bit56 */
			{ 3185, 5,0}, /* core2 sp_EL2 bit57 */
			{ 3189, 5,0}, /* core2 sp_EL2 bit58 */
			{ 3181, 5,0}, /* core2 sp_EL2 bit59 */
			{ 3196, 5,0}, /* core2 sp_EL2 bit60 */
			{ 3230, 5,0}, /* core2 sp_EL2 bit61 */
			{ 3191, 5,0}, /* core2 sp_EL2 bit62 */
			{ 1036, 5,0}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 1550, 5,0}, /* core2 sp_EL3 bit0 */
			{ 1270, 5,0}, /* core2 sp_EL3 bit1 */
			{ 1271, 5,0}, /* core2 sp_EL3 bit2 */
			{ 1551, 5,0}, /* core2 sp_EL3 bit3 */
			{ 1268, 5,0}, /* core2 sp_EL3 bit4 */
			{ 1267, 5,0}, /* core2 sp_EL3 bit5 */
			{ 1323, 5,0}, /* core2 sp_EL3 bit6 */
			{ 1322, 5,0}, /* core2 sp_EL3 bit7 */
			{ 1318, 5,0}, /* core2 sp_EL3 bit8 */
			{ 1319, 5,0}, /* core2 sp_EL3 bit9 */
			{ 1315, 5,0}, /* core2 sp_EL3 bit10 */
			{ 1004, 5,0}, /* core2 sp_EL3 bit11 */
			{ 1317, 5,0}, /* core2 sp_EL3 bit12 */
			{ 1316, 5,0}, /* core2 sp_EL3 bit13 */
			{ 1321, 5,0}, /* core2 sp_EL3 bit14 */
			{ 1320, 5,0}, /* core2 sp_EL3 bit15 */
			{ 1324, 5,0}, /* core2 sp_EL3 bit16 */
			{ 1552, 5,0}, /* core2 sp_EL3 bit17 */
			{ 1549, 5,0}, /* core2 sp_EL3 bit18 */
			{ 1579, 5,0}, /* core2 sp_EL3 bit19 */
			{ 1571, 5,0}, /* core2 sp_EL3 bit20 */
			{ 1575, 5,0}, /* core2 sp_EL3 bit21 */
			{ 1580, 5,0}, /* core2 sp_EL3 bit22 */
			{ 1570, 5,0}, /* core2 sp_EL3 bit23 */
			{ 1574, 5,0}, /* core2 sp_EL3 bit24 */
			{ 1578, 5,0}, /* core2 sp_EL3 bit25 */
			{ 1573, 5,0}, /* core2 sp_EL3 bit26 */
			{ 1569, 5,0}, /* core2 sp_EL3 bit27 */
			{ 1577, 5,0}, /* core2 sp_EL3 bit28 */
			{ 1572, 5,0}, /* core2 sp_EL3 bit29 */
			{ 1576, 5,0}, /* core2 sp_EL3 bit30 */
			{ 1269, 5,0}, /* core2 sp_EL3 bit31 */
			{ 1054, 5,0}, /* core2 sp_EL3 bit32 */
			{ 1051, 5,0}, /* core2 sp_EL3 bit33 */
			{ 1052, 5,0}, /* core2 sp_EL3 bit34 */
			{ 1062, 5,0}, /* core2 sp_EL3 bit35 */
			{ 1071, 5,0}, /* core2 sp_EL3 bit36 */
			{ 1063, 5,0}, /* core2 sp_EL3 bit37 */
			{ 1056, 5,0}, /* core2 sp_EL3 bit38 */
			{ 1064, 5,0}, /* core2 sp_EL3 bit39 */
			{ 1085, 5,0}, /* core2 sp_EL3 bit40 */
			{ 1083, 5,0}, /* core2 sp_EL3 bit41 */
			{ 1072, 5,0}, /* core2 sp_EL3 bit42 */
			{ 1080, 5,0}, /* core2 sp_EL3 bit43 */
			{ 1086, 5,0}, /* core2 sp_EL3 bit44 */
			{ 1079, 5,0}, /* core2 sp_EL3 bit45 */
			{ 1082, 5,0}, /* core2 sp_EL3 bit46 */
			{ 3318, 5,0}, /* core2 sp_EL3 bit47 */
			{ 3176, 5,0}, /* core2 sp_EL3 bit48 */
			{ 3320, 5,0}, /* core2 sp_EL3 bit49 */
			{ 3325, 5,0}, /* core2 sp_EL3 bit50 */
			{ 3321, 5,0}, /* core2 sp_EL3 bit51 */
			{ 3317, 5,0}, /* core2 sp_EL3 bit52 */
			{ 3358, 5,0}, /* core2 sp_EL3 bit53 */
			{ 3319, 5,0}, /* core2 sp_EL3 bit54 */
			{ 3313, 5,0}, /* core2 sp_EL3 bit55 */
			{ 3324, 5,0}, /* core2 sp_EL3 bit56 */
			{ 3314, 5,0}, /* core2 sp_EL3 bit57 */
			{ 3356, 5,0}, /* core2 sp_EL3 bit58 */
			{ 3357, 5,0}, /* core2 sp_EL3 bit59 */
			{ 3315, 5,0}, /* core2 sp_EL3 bit60 */
			{ 3316, 5,0}, /* core2 sp_EL3 bit61 */
			{ 3322, 5,0}, /* core2 sp_EL3 bit62 */
			{ 1053, 5,0}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{   54, 5,0}, /* core2 elr_EL1 bit0 */
			{   55, 5,0}, /* core2 elr_EL1 bit1 */
			{ 1001, 5,0}, /* core2 elr_EL1 bit2 */
			{ 1000, 5,0}, /* core2 elr_EL1 bit3 */
			{ 1263, 5,0}, /* core2 elr_EL1 bit4 */
			{ 1286, 5,0}, /* core2 elr_EL1 bit5 */
			{ 1287, 5,0}, /* core2 elr_EL1 bit6 */
			{ 1276, 5,0}, /* core2 elr_EL1 bit7 */
			{ 1301, 5,0}, /* core2 elr_EL1 bit8 */
			{ 1289, 5,0}, /* core2 elr_EL1 bit9 */
			{ 1002, 5,0}, /* core2 elr_EL1 bit10 */
			{ 1290, 5,0}, /* core2 elr_EL1 bit11 */
			{ 1291, 5,0}, /* core2 elr_EL1 bit12 */
			{  999, 5,0}, /* core2 elr_EL1 bit13 */
			{ 1314, 5,0}, /* core2 elr_EL1 bit14 */
			{ 1003, 5,0}, /* core2 elr_EL1 bit15 */
			{ 1288, 5,0}, /* core2 elr_EL1 bit16 */
			{ 1274, 5,0}, /* core2 elr_EL1 bit17 */
			{ 1331, 5,0}, /* core2 elr_EL1 bit18 */
			{ 1346, 5,0}, /* core2 elr_EL1 bit19 */
			{ 1339, 5,0}, /* core2 elr_EL1 bit20 */
			{ 1343, 5,0}, /* core2 elr_EL1 bit21 */
			{ 1348, 5,0}, /* core2 elr_EL1 bit22 */
			{ 1352, 5,0}, /* core2 elr_EL1 bit23 */
			{ 1341, 5,0}, /* core2 elr_EL1 bit24 */
			{ 1342, 5,0}, /* core2 elr_EL1 bit25 */
			{ 1248, 5,0}, /* core2 elr_EL1 bit26 */
			{ 1340, 5,0}, /* core2 elr_EL1 bit27 */
			{ 1351, 5,0}, /* core2 elr_EL1 bit28 */
			{ 1334, 5,0}, /* core2 elr_EL1 bit29 */
			{ 1337, 5,0}, /* core2 elr_EL1 bit30 */
			{ 1266, 5,0}, /* core2 elr_EL1 bit31 */
			{ 1749, 5,0}, /* core2 elr_EL1 bit32 */
			{ 1750, 5,0}, /* core2 elr_EL1 bit33 */
			{ 1757, 5,0}, /* core2 elr_EL1 bit34 */
			{ 1752, 5,0}, /* core2 elr_EL1 bit35 */
			{ 1744, 5,0}, /* core2 elr_EL1 bit36 */
			{ 1748, 5,0}, /* core2 elr_EL1 bit37 */
			{ 1767, 5,0}, /* core2 elr_EL1 bit38 */
			{ 1751, 5,0}, /* core2 elr_EL1 bit39 */
			{ 1795, 5,0}, /* core2 elr_EL1 bit40 */
			{ 1746, 5,0}, /* core2 elr_EL1 bit41 */
			{ 1745, 5,0}, /* core2 elr_EL1 bit42 */
			{ 1769, 5,0}, /* core2 elr_EL1 bit43 */
			{ 1796, 5,0}, /* core2 elr_EL1 bit44 */
			{ 1797, 5,0}, /* core2 elr_EL1 bit45 */
			{ 1768, 5,0}, /* core2 elr_EL1 bit46 */
			{ 7297, 4,0}, /* core2 elr_EL1 bit47 */
			{ 7284, 4,0}, /* core2 elr_EL1 bit48 */
			{ 7285, 4,0}, /* core2 elr_EL1 bit49 */
			{ 7283, 4,0}, /* core2 elr_EL1 bit50 */
			{ 7290, 4,0}, /* core2 elr_EL1 bit51 */
			{ 7292, 4,0}, /* core2 elr_EL1 bit52 */
			{ 7296, 4,0}, /* core2 elr_EL1 bit53 */
			{ 7293, 4,0}, /* core2 elr_EL1 bit54 */
			{ 7286, 4,0}, /* core2 elr_EL1 bit55 */
			{ 7979, 4,0}, /* core2 elr_EL1 bit56 */
			{ 7288, 4,0}, /* core2 elr_EL1 bit57 */
			{ 7294, 4,0}, /* core2 elr_EL1 bit58 */
			{ 7287, 4,0}, /* core2 elr_EL1 bit59 */
			{ 7289, 4,0}, /* core2 elr_EL1 bit60 */
			{ 7291, 4,0}, /* core2 elr_EL1 bit61 */
			{ 7295, 4,0}, /* core2 elr_EL1 bit62 */
			{ 1759, 5,0}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{  275, 4,0}, /* core2 elr_EL2 bit0 */
			{  393, 4,0}, /* core2 elr_EL2 bit1 */
			{  276, 4,0}, /* core2 elr_EL2 bit2 */
			{  360, 4,0}, /* core2 elr_EL2 bit3 */
			{  292, 4,0}, /* core2 elr_EL2 bit4 */
			{  281, 4,0}, /* core2 elr_EL2 bit5 */
			{  280, 4,0}, /* core2 elr_EL2 bit6 */
			{  282, 4,0}, /* core2 elr_EL2 bit7 */
			{  398, 4,0}, /* core2 elr_EL2 bit8 */
			{  397, 4,0}, /* core2 elr_EL2 bit9 */
			{  396, 4,0}, /* core2 elr_EL2 bit10 */
			{  399, 4,0}, /* core2 elr_EL2 bit11 */
			{  400, 4,0}, /* core2 elr_EL2 bit12 */
			{  401, 4,0}, /* core2 elr_EL2 bit13 */
			{  285, 4,0}, /* core2 elr_EL2 bit14 */
			{  395, 4,0}, /* core2 elr_EL2 bit15 */
			{  394, 4,0}, /* core2 elr_EL2 bit16 */
			{  283, 4,0}, /* core2 elr_EL2 bit17 */
			{  284, 4,0}, /* core2 elr_EL2 bit18 */
			{  381, 4,0}, /* core2 elr_EL2 bit19 */
			{  382, 4,0}, /* core2 elr_EL2 bit20 */
			{  377, 4,0}, /* core2 elr_EL2 bit21 */
			{  371, 4,0}, /* core2 elr_EL2 bit22 */
			{  379, 4,0}, /* core2 elr_EL2 bit23 */
			{  372, 4,0}, /* core2 elr_EL2 bit24 */
			{  374, 4,0}, /* core2 elr_EL2 bit25 */
			{  378, 4,0}, /* core2 elr_EL2 bit26 */
			{  375, 4,0}, /* core2 elr_EL2 bit27 */
			{  376, 4,0}, /* core2 elr_EL2 bit28 */
			{  373, 4,0}, /* core2 elr_EL2 bit29 */
			{  380, 4,0}, /* core2 elr_EL2 bit30 */
			{  291, 4,0}, /* core2 elr_EL2 bit31 */
			{ 1039, 5,0}, /* core2 elr_EL2 bit32 */
			{ 1044, 5,0}, /* core2 elr_EL2 bit33 */
			{ 1038, 5,0}, /* core2 elr_EL2 bit34 */
			{ 1037, 5,0}, /* core2 elr_EL2 bit35 */
			{ 1662, 5,0}, /* core2 elr_EL2 bit36 */
			{ 1045, 5,0}, /* core2 elr_EL2 bit37 */
			{ 1074, 5,0}, /* core2 elr_EL2 bit38 */
			{ 1061, 5,0}, /* core2 elr_EL2 bit39 */
			{ 1076, 5,0}, /* core2 elr_EL2 bit40 */
			{ 1069, 5,0}, /* core2 elr_EL2 bit41 */
			{ 1075, 5,0}, /* core2 elr_EL2 bit42 */
			{ 1070, 5,0}, /* core2 elr_EL2 bit43 */
			{ 1077, 5,0}, /* core2 elr_EL2 bit44 */
			{ 1078, 5,0}, /* core2 elr_EL2 bit45 */
			{ 1073, 5,0}, /* core2 elr_EL2 bit46 */
			{ 3348, 5,0}, /* core2 elr_EL2 bit47 */
			{ 3328, 5,0}, /* core2 elr_EL2 bit48 */
			{ 3334, 5,0}, /* core2 elr_EL2 bit49 */
			{ 3336, 5,0}, /* core2 elr_EL2 bit50 */
			{ 3352, 5,0}, /* core2 elr_EL2 bit51 */
			{ 3168, 5,0}, /* core2 elr_EL2 bit52 */
			{ 3172, 5,0}, /* core2 elr_EL2 bit53 */
			{ 3331, 5,0}, /* core2 elr_EL2 bit54 */
			{ 3335, 5,0}, /* core2 elr_EL2 bit55 */
			{ 3326, 5,0}, /* core2 elr_EL2 bit56 */
			{ 3329, 5,0}, /* core2 elr_EL2 bit57 */
			{ 3355, 5,0}, /* core2 elr_EL2 bit58 */
			{ 3327, 5,0}, /* core2 elr_EL2 bit59 */
			{ 3330, 5,0}, /* core2 elr_EL2 bit60 */
			{ 3332, 5,0}, /* core2 elr_EL2 bit61 */
			{ 3333, 5,0}, /* core2 elr_EL2 bit62 */
			{ 1055, 5,0}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 2940, 5,0}, /* core2 elr_EL3 bit0 */
			{ 2887, 5,0}, /* core2 elr_EL3 bit1 */
			{ 2886, 5,0}, /* core2 elr_EL3 bit2 */
			{ 2892, 5,0}, /* core2 elr_EL3 bit3 */
			{ 2880, 5,0}, /* core2 elr_EL3 bit4 */
			{ 2878, 5,0}, /* core2 elr_EL3 bit5 */
			{ 2944, 5,0}, /* core2 elr_EL3 bit6 */
			{ 2885, 5,0}, /* core2 elr_EL3 bit7 */
			{ 2900, 5,0}, /* core2 elr_EL3 bit8 */
			{ 2899, 5,0}, /* core2 elr_EL3 bit9 */
			{ 2897, 5,0}, /* core2 elr_EL3 bit10 */
			{ 2938, 5,0}, /* core2 elr_EL3 bit11 */
			{ 2896, 5,0}, /* core2 elr_EL3 bit12 */
			{ 2942, 5,0}, /* core2 elr_EL3 bit13 */
			{ 2895, 5,0}, /* core2 elr_EL3 bit14 */
			{ 2937, 5,0}, /* core2 elr_EL3 bit15 */
			{ 2939, 5,0}, /* core2 elr_EL3 bit16 */
			{ 2881, 5,0}, /* core2 elr_EL3 bit17 */
			{ 2945, 5,0}, /* core2 elr_EL3 bit18 */
			{ 2955, 5,0}, /* core2 elr_EL3 bit19 */
			{ 2962, 5,0}, /* core2 elr_EL3 bit20 */
			{ 2957, 5,0}, /* core2 elr_EL3 bit21 */
			{ 2970, 5,0}, /* core2 elr_EL3 bit22 */
			{ 2963, 5,0}, /* core2 elr_EL3 bit23 */
			{ 2971, 5,0}, /* core2 elr_EL3 bit24 */
			{ 2956, 5,0}, /* core2 elr_EL3 bit25 */
			{ 2961, 5,0}, /* core2 elr_EL3 bit26 */
			{ 2960, 5,0}, /* core2 elr_EL3 bit27 */
			{ 2958, 5,0}, /* core2 elr_EL3 bit28 */
			{ 2959, 5,0}, /* core2 elr_EL3 bit29 */
			{ 2954, 5,0}, /* core2 elr_EL3 bit30 */
			{ 2879, 5,0}, /* core2 elr_EL3 bit31 */
			{ 1048, 5,0}, /* core2 elr_EL3 bit32 */
			{ 1049, 5,0}, /* core2 elr_EL3 bit33 */
			{ 2069, 5,0}, /* core2 elr_EL3 bit34 */
			{ 2061, 5,0}, /* core2 elr_EL3 bit35 */
			{ 1772, 5,0}, /* core2 elr_EL3 bit36 */
			{ 2063, 5,0}, /* core2 elr_EL3 bit37 */
			{ 1774, 5,0}, /* core2 elr_EL3 bit38 */
			{ 2064, 5,0}, /* core2 elr_EL3 bit39 */
			{ 1773, 5,0}, /* core2 elr_EL3 bit40 */
			{ 1788, 5,0}, /* core2 elr_EL3 bit41 */
			{ 1785, 5,0}, /* core2 elr_EL3 bit42 */
			{ 1786, 5,0}, /* core2 elr_EL3 bit43 */
			{ 1787, 5,0}, /* core2 elr_EL3 bit44 */
			{ 1789, 5,0}, /* core2 elr_EL3 bit45 */
			{ 1778, 5,0}, /* core2 elr_EL3 bit46 */
			{ 3220, 5,0}, /* core2 elr_EL3 bit47 */
			{ 7965, 5,0}, /* core2 elr_EL3 bit48 */
			{ 7960, 5,0}, /* core2 elr_EL3 bit49 */
			{ 3223, 5,0}, /* core2 elr_EL3 bit50 */
			{ 7972, 5,0}, /* core2 elr_EL3 bit51 */
			{ 7973, 5,0}, /* core2 elr_EL3 bit52 */
			{ 3221, 5,0}, /* core2 elr_EL3 bit53 */
			{ 3226, 5,0}, /* core2 elr_EL3 bit54 */
			{ 7958, 5,0}, /* core2 elr_EL3 bit55 */
			{ 7966, 5,0}, /* core2 elr_EL3 bit56 */
			{ 7959, 5,0}, /* core2 elr_EL3 bit57 */
			{ 7963, 5,0}, /* core2 elr_EL3 bit58 */
			{ 7961, 5,0}, /* core2 elr_EL3 bit59 */
			{ 7962, 5,0}, /* core2 elr_EL3 bit60 */
			{ 3224, 5,0}, /* core2 elr_EL3 bit61 */
			{ 3225, 5,0}, /* core2 elr_EL3 bit62 */
			{ 1779, 5,0}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 7402, 4,0}, /* core2 raw_pc bit0 */
			{ 5743, 5,0}, /* core2 raw_pc bit1 */
			{ 5742, 5,0}, /* core2 raw_pc bit2 */
			{ 7399, 4,0}, /* core2 raw_pc bit3 */
			{ 7401, 4,0}, /* core2 raw_pc bit4 */
			{ 7400, 4,0}, /* core2 raw_pc bit5 */
			{ 7404, 4,0}, /* core2 raw_pc bit6 */
			{ 9616, 4,0}, /* core2 raw_pc bit7 */
			{ 9615, 4,0}, /* core2 raw_pc bit8 */
			{ 9614, 4,0}, /* core2 raw_pc bit9 */
			{ 9613, 4,0}, /* core2 raw_pc bit10 */
			{ 9620, 4,0}, /* core2 raw_pc bit11 */
			{ 9619, 4,0}, /* core2 raw_pc bit12 */
			{ 9618, 4,0}, /* core2 raw_pc bit13 */
			{ 9617, 4,0}, /* core2 raw_pc bit14 */
			{ 9624, 4,0}, /* core2 raw_pc bit15 */
			{ 9623, 4,0}, /* core2 raw_pc bit16 */
			{ 9622, 4,0}, /* core2 raw_pc bit17 */
			{ 9621, 4,0}, /* core2 raw_pc bit18 */
			{10437, 4,0}, /* core2 raw_pc bit19 */
			{10436, 4,0}, /* core2 raw_pc bit20 */
			{10435, 4,0}, /* core2 raw_pc bit21 */
			{10434, 4,0}, /* core2 raw_pc bit22 */
			{10441, 4,0}, /* core2 raw_pc bit23 */
			{10440, 4,0}, /* core2 raw_pc bit24 */
			{10439, 4,0}, /* core2 raw_pc bit25 */
			{10438, 4,0}, /* core2 raw_pc bit26 */
			{10445, 4,0}, /* core2 raw_pc bit27 */
			{10444, 4,0}, /* core2 raw_pc bit28 */
			{10443, 4,0}, /* core2 raw_pc bit29 */
			{10442, 4,0}, /* core2 raw_pc bit30 */
			{ 9347, 4,0}, /* core2 raw_pc bit31 */
			{ 9346, 4,0}, /* core2 raw_pc bit32 */
			{ 9345, 4,0}, /* core2 raw_pc bit33 */
			{ 9344, 4,0}, /* core2 raw_pc bit34 */
			{ 9351, 4,0}, /* core2 raw_pc bit35 */
			{ 9350, 4,0}, /* core2 raw_pc bit36 */
			{ 9349, 4,0}, /* core2 raw_pc bit37 */
			{ 5234, 5,0}, /* core2 raw_pc bit38 */
			{ 9646, 4,0}, /* core2 raw_pc bit39 */
			{ 9645, 4,0}, /* core2 raw_pc bit40 */
			{ 9348, 4,0}, /* core2 raw_pc bit41 */
			{ 9648, 4,0}, /* core2 raw_pc bit42 */
			{ 9647, 4,0}, /* core2 raw_pc bit43 */
			{ 9644, 4,0}, /* core2 raw_pc bit44 */
			{ 9643, 4,0}, /* core2 raw_pc bit45 */
			{ 5232, 5,0}, /* core2 raw_pc bit46 */
			{ 5233, 5,0}, /* core2 raw_pc bit47 */
			{    0, 0,2}, /* core2 raw_pc bit48 */
			{    0, 0,2}, /* core2 raw_pc bit49 */
			{    0, 0,2}, /* core2 raw_pc bit50 */
			{    0, 0,2}, /* core2 raw_pc bit51 */
			{    0, 0,2}, /* core2 raw_pc bit52 */
			{    0, 0,2}, /* core2 raw_pc bit53 */
			{    0, 0,2}, /* core2 raw_pc bit54 */
			{    0, 0,2}, /* core2 raw_pc bit55 */
			{    0, 0,2}, /* core2 raw_pc bit56 */
			{    0, 0,2}, /* core2 raw_pc bit57 */
			{    0, 0,2}, /* core2 raw_pc bit58 */
			{    0, 0,2}, /* core2 raw_pc bit59 */
			{    0, 0,2}, /* core2 raw_pc bit60 */
			{    0, 0,2}, /* core2 raw_pc bit61 */
			{    0, 0,2}, /* core2 raw_pc bit62 */
			{    0, 0,2}, /* core2 raw_pc bit63 */
			}},
			.pc_iss = {{
			{ 9507, 4,0}, /* core2 pc_iss bit0 */
			{ 9506, 4,0}, /* core2 pc_iss bit1 */
			{ 9505, 4,0}, /* core2 pc_iss bit2 */
			{ 9513, 4,0}, /* core2 pc_iss bit3 */
			{ 9512, 4,0}, /* core2 pc_iss bit4 */
			{ 9503, 4,0}, /* core2 pc_iss bit5 */
			{ 9502, 4,0}, /* core2 pc_iss bit6 */
			{ 9504, 4,0}, /* core2 pc_iss bit7 */
			{ 9626, 4,0}, /* core2 pc_iss bit8 */
			{ 9625, 4,0}, /* core2 pc_iss bit9 */
			{ 9509, 4,0}, /* core2 pc_iss bit10 */
			{ 9634, 4,0}, /* core2 pc_iss bit11 */
			{ 9633, 4,0}, /* core2 pc_iss bit12 */
			{ 9331, 4,0}, /* core2 pc_iss bit13 */
			{ 5360, 5,0}, /* core2 pc_iss bit14 */
			{ 9630, 4,0}, /* core2 pc_iss bit15 */
			{ 9629, 4,0}, /* core2 pc_iss bit16 */
			{ 9511, 4,0}, /* core2 pc_iss bit17 */
			{ 9510, 4,0}, /* core2 pc_iss bit18 */
			{ 9628, 4,0}, /* core2 pc_iss bit19 */
			{ 9508, 4,0}, /* core2 pc_iss bit20 */
			{ 9627, 4,0}, /* core2 pc_iss bit21 */
			{ 9632, 4,0}, /* core2 pc_iss bit22 */
			{ 9330, 4,0}, /* core2 pc_iss bit23 */
			{ 5363, 5,0}, /* core2 pc_iss bit24 */
			{ 9329, 4,0}, /* core2 pc_iss bit25 */
			{ 9328, 4,0}, /* core2 pc_iss bit26 */
			{ 9631, 4,0}, /* core2 pc_iss bit27 */
			{ 5361, 5,0}, /* core2 pc_iss bit28 */
			{ 9636, 4,0}, /* core2 pc_iss bit29 */
			{ 9635, 4,0}, /* core2 pc_iss bit30 */
			{ 5362, 5,0}, /* core2 pc_iss bit31 */
			{ 9656, 4,0}, /* core2 pc_iss bit32 */
			{ 9391, 4,0}, /* core2 pc_iss bit33 */
			{ 9655, 4,0}, /* core2 pc_iss bit34 */
			{ 9654, 4,0}, /* core2 pc_iss bit35 */
			{ 9653, 4,0}, /* core2 pc_iss bit36 */
			{ 9390, 4,0}, /* core2 pc_iss bit37 */
			{ 9389, 4,0}, /* core2 pc_iss bit38 */
			{ 5248, 5,0}, /* core2 pc_iss bit39 */
			{ 9652, 4,0}, /* core2 pc_iss bit40 */
			{ 9388, 4,0}, /* core2 pc_iss bit41 */
			{ 5250, 5,0}, /* core2 pc_iss bit42 */
			{ 9387, 4,0}, /* core2 pc_iss bit43 */
			{ 9651, 4,0}, /* core2 pc_iss bit44 */
			{ 9650, 4,0}, /* core2 pc_iss bit45 */
			{ 5246, 5,0}, /* core2 pc_iss bit46 */
			{ 9649, 4,0}, /* core2 pc_iss bit47 */
			{ 5249, 5,0}, /* core2 pc_iss bit48 */
			{ 9386, 4,0}, /* core2 pc_iss bit49 */
			{ 5245, 5,0}, /* core2 pc_iss bit50 */
			{ 5247, 5,0}, /* core2 pc_iss bit51 */
			{ 5243, 5,0}, /* core2 pc_iss bit52 */
			{ 5235, 5,0}, /* core2 pc_iss bit53 */
			{ 5244, 5,0}, /* core2 pc_iss bit54 */
			{ 9385, 4,0}, /* core2 pc_iss bit55 */
			{ 5241, 5,0}, /* core2 pc_iss bit56 */
			{ 5242, 5,0}, /* core2 pc_iss bit57 */
			{ 5236, 5,0}, /* core2 pc_iss bit58 */
			{ 9384, 4,0}, /* core2 pc_iss bit59 */
			{ 5237, 5,0}, /* core2 pc_iss bit60 */
			{ 5238, 5,0}, /* core2 pc_iss bit61 */
			{ 5239, 5,0}, /* core2 pc_iss bit62 */
			{ 5240, 5,0}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 7403, 4,0}, /* core2 full_pc_wr bit0 */
			{    0, 0,2}, /* core2 full_pc_wr bit1 */
			{    0, 0,2}, /* core2 full_pc_wr bit2 */
			{    0, 0,2}, /* core2 full_pc_wr bit3 */
			{    0, 0,2}, /* core2 full_pc_wr bit4 */
			{    0, 0,2}, /* core2 full_pc_wr bit5 */
			{    0, 0,2}, /* core2 full_pc_wr bit6 */
			{    0, 0,2}, /* core2 full_pc_wr bit7 */
			{    0, 0,2}, /* core2 full_pc_wr bit8 */
			{    0, 0,2}, /* core2 full_pc_wr bit9 */
			{    0, 0,2}, /* core2 full_pc_wr bit10 */
			{    0, 0,2}, /* core2 full_pc_wr bit11 */
			{    0, 0,2}, /* core2 full_pc_wr bit12 */
			{    0, 0,2}, /* core2 full_pc_wr bit13 */
			{    0, 0,2}, /* core2 full_pc_wr bit14 */
			{    0, 0,2}, /* core2 full_pc_wr bit15 */
			{    0, 0,2}, /* core2 full_pc_wr bit16 */
			{    0, 0,2}, /* core2 full_pc_wr bit17 */
			{    0, 0,2}, /* core2 full_pc_wr bit18 */
			{    0, 0,2}, /* core2 full_pc_wr bit19 */
			{    0, 0,2}, /* core2 full_pc_wr bit20 */
			{    0, 0,2}, /* core2 full_pc_wr bit21 */
			{    0, 0,2}, /* core2 full_pc_wr bit22 */
			{    0, 0,2}, /* core2 full_pc_wr bit23 */
			{    0, 0,2}, /* core2 full_pc_wr bit24 */
			{    0, 0,2}, /* core2 full_pc_wr bit25 */
			{    0, 0,2}, /* core2 full_pc_wr bit26 */
			{    0, 0,2}, /* core2 full_pc_wr bit27 */
			{    0, 0,2}, /* core2 full_pc_wr bit28 */
			{    0, 0,2}, /* core2 full_pc_wr bit29 */
			{    0, 0,2}, /* core2 full_pc_wr bit30 */
			{    0, 0,2}, /* core2 full_pc_wr bit31 */
			{    0, 0,2}, /* core2 full_pc_wr bit32 */
			{    0, 0,2}, /* core2 full_pc_wr bit33 */
			{    0, 0,2}, /* core2 full_pc_wr bit34 */
			{    0, 0,2}, /* core2 full_pc_wr bit35 */
			{    0, 0,2}, /* core2 full_pc_wr bit36 */
			{    0, 0,2}, /* core2 full_pc_wr bit37 */
			{    0, 0,2}, /* core2 full_pc_wr bit38 */
			{    0, 0,2}, /* core2 full_pc_wr bit39 */
			{    0, 0,2}, /* core2 full_pc_wr bit40 */
			{    0, 0,2}, /* core2 full_pc_wr bit41 */
			{    0, 0,2}, /* core2 full_pc_wr bit42 */
			{    0, 0,2}, /* core2 full_pc_wr bit43 */
			{    0, 0,2}, /* core2 full_pc_wr bit44 */
			{    0, 0,2}, /* core2 full_pc_wr bit45 */
			{    0, 0,2}, /* core2 full_pc_wr bit46 */
			{    0, 0,2}, /* core2 full_pc_wr bit47 */
			{    0, 0,2}, /* core2 full_pc_wr bit48 */
			{    0, 0,2}, /* core2 full_pc_wr bit49 */
			{    0, 0,2}, /* core2 full_pc_wr bit50 */
			{    0, 0,2}, /* core2 full_pc_wr bit51 */
			{    0, 0,2}, /* core2 full_pc_wr bit52 */
			{    0, 0,2}, /* core2 full_pc_wr bit53 */
			{    0, 0,2}, /* core2 full_pc_wr bit54 */
			{    0, 0,2}, /* core2 full_pc_wr bit55 */
			{    0, 0,2}, /* core2 full_pc_wr bit56 */
			{    0, 0,2}, /* core2 full_pc_wr bit57 */
			{    0, 0,2}, /* core2 full_pc_wr bit58 */
			{    0, 0,2}, /* core2 full_pc_wr bit59 */
			{    0, 0,2}, /* core2 full_pc_wr bit60 */
			{    0, 0,2}, /* core2 full_pc_wr bit61 */
			{    0, 0,2}, /* core2 full_pc_wr bit62 */
			{    0, 0,2}, /* core2 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{ 5400, 5,0}, /* core2 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{ 7406, 4,0}, /* core2 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{16329, 5,0}, /* core2 return_Stack_pointer bit0 */
			{14948, 5,0}, /* core2 return_Stack_pointer bit1 */
			{16328, 5,0}, /* core2 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{16729, 5,0}, /* core2 return_Stack0 bit0 */
			{16728, 5,0}, /* core2 return_Stack0 bit1 */
			{16727, 5,0}, /* core2 return_Stack0 bit2 */
			{16726, 5,0}, /* core2 return_Stack0 bit3 */
			{16721, 5,0}, /* core2 return_Stack0 bit4 */
			{16720, 5,0}, /* core2 return_Stack0 bit5 */
			{16719, 5,0}, /* core2 return_Stack0 bit6 */
			{16718, 5,0}, /* core2 return_Stack0 bit7 */
			{12983, 5,0}, /* core2 return_Stack0 bit8 */
			{12982, 5,0}, /* core2 return_Stack0 bit9 */
			{12981, 5,0}, /* core2 return_Stack0 bit10 */
			{12980, 5,0}, /* core2 return_Stack0 bit11 */
			{16789, 5,0}, /* core2 return_Stack0 bit12 */
			{16788, 5,0}, /* core2 return_Stack0 bit13 */
			{16787, 5,0}, /* core2 return_Stack0 bit14 */
			{16786, 5,0}, /* core2 return_Stack0 bit15 */
			{16725, 5,0}, /* core2 return_Stack0 bit16 */
			{16724, 5,0}, /* core2 return_Stack0 bit17 */
			{16723, 5,0}, /* core2 return_Stack0 bit18 */
			{16722, 5,0}, /* core2 return_Stack0 bit19 */
			{13019, 5,0}, /* core2 return_Stack0 bit20 */
			{13018, 5,0}, /* core2 return_Stack0 bit21 */
			{13017, 5,0}, /* core2 return_Stack0 bit22 */
			{13016, 5,0}, /* core2 return_Stack0 bit23 */
			{13092, 5,0}, /* core2 return_Stack0 bit24 */
			{13091, 5,0}, /* core2 return_Stack0 bit25 */
			{13090, 5,0}, /* core2 return_Stack0 bit26 */
			{13089, 5,0}, /* core2 return_Stack0 bit27 */
			{13040, 5,0}, /* core2 return_Stack0 bit28 */
			{13039, 5,0}, /* core2 return_Stack0 bit29 */
			{13038, 5,0}, /* core2 return_Stack0 bit30 */
			{13037, 5,0}, /* core2 return_Stack0 bit31 */
			{13052, 5,0}, /* core2 return_Stack0 bit32 */
			{13051, 5,0}, /* core2 return_Stack0 bit33 */
			{13050, 5,0}, /* core2 return_Stack0 bit34 */
			{13049, 5,0}, /* core2 return_Stack0 bit35 */
			{13072, 5,0}, /* core2 return_Stack0 bit36 */
			{13071, 5,0}, /* core2 return_Stack0 bit37 */
			{13070, 5,0}, /* core2 return_Stack0 bit38 */
			{13069, 5,0}, /* core2 return_Stack0 bit39 */
			{13064, 5,0}, /* core2 return_Stack0 bit40 */
			{13063, 5,0}, /* core2 return_Stack0 bit41 */
			{13062, 5,0}, /* core2 return_Stack0 bit42 */
			{13061, 5,0}, /* core2 return_Stack0 bit43 */
			{13068, 5,0}, /* core2 return_Stack0 bit44 */
			{13067, 5,0}, /* core2 return_Stack0 bit45 */
			{13066, 5,0}, /* core2 return_Stack0 bit46 */
			{13065, 5,0}, /* core2 return_Stack0 bit47 */
			{13036, 5,0}, /* core2 return_Stack0 bit48 */
			{    0, 0,2}, /* core2 return_Stack0 bit49 */
			{    0, 0,2}, /* core2 return_Stack0 bit50 */
			{    0, 0,2}, /* core2 return_Stack0 bit51 */
			{    0, 0,2}, /* core2 return_Stack0 bit52 */
			{    0, 0,2}, /* core2 return_Stack0 bit53 */
			{    0, 0,2}, /* core2 return_Stack0 bit54 */
			{    0, 0,2}, /* core2 return_Stack0 bit55 */
			{    0, 0,2}, /* core2 return_Stack0 bit56 */
			{    0, 0,2}, /* core2 return_Stack0 bit57 */
			{    0, 0,2}, /* core2 return_Stack0 bit58 */
			{    0, 0,2}, /* core2 return_Stack0 bit59 */
			{    0, 0,2}, /* core2 return_Stack0 bit60 */
			{    0, 0,2}, /* core2 return_Stack0 bit61 */
			{    0, 0,2}, /* core2 return_Stack0 bit62 */
			{    0, 0,2}, /* core2 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{16705, 5,0}, /* core2 return_Stack1 bit0 */
			{16704, 5,0}, /* core2 return_Stack1 bit1 */
			{16703, 5,0}, /* core2 return_Stack1 bit2 */
			{16702, 5,0}, /* core2 return_Stack1 bit3 */
			{16701, 5,0}, /* core2 return_Stack1 bit4 */
			{16700, 5,0}, /* core2 return_Stack1 bit5 */
			{16699, 5,0}, /* core2 return_Stack1 bit6 */
			{16698, 5,0}, /* core2 return_Stack1 bit7 */
			{12995, 5,0}, /* core2 return_Stack1 bit8 */
			{12994, 5,0}, /* core2 return_Stack1 bit9 */
			{12993, 5,0}, /* core2 return_Stack1 bit10 */
			{12992, 5,0}, /* core2 return_Stack1 bit11 */
			{16761, 5,0}, /* core2 return_Stack1 bit12 */
			{16760, 5,0}, /* core2 return_Stack1 bit13 */
			{16759, 5,0}, /* core2 return_Stack1 bit14 */
			{16758, 5,0}, /* core2 return_Stack1 bit15 */
			{16753, 5,0}, /* core2 return_Stack1 bit16 */
			{16752, 5,0}, /* core2 return_Stack1 bit17 */
			{16751, 5,0}, /* core2 return_Stack1 bit18 */
			{16750, 5,0}, /* core2 return_Stack1 bit19 */
			{16765, 5,0}, /* core2 return_Stack1 bit20 */
			{16764, 5,0}, /* core2 return_Stack1 bit21 */
			{16763, 5,0}, /* core2 return_Stack1 bit22 */
			{16762, 5,0}, /* core2 return_Stack1 bit23 */
			{16773, 5,0}, /* core2 return_Stack1 bit24 */
			{16772, 5,0}, /* core2 return_Stack1 bit25 */
			{16771, 5,0}, /* core2 return_Stack1 bit26 */
			{16770, 5,0}, /* core2 return_Stack1 bit27 */
			{16777, 5,0}, /* core2 return_Stack1 bit28 */
			{16776, 5,0}, /* core2 return_Stack1 bit29 */
			{16775, 5,0}, /* core2 return_Stack1 bit30 */
			{16774, 5,0}, /* core2 return_Stack1 bit31 */
			{12963, 5,0}, /* core2 return_Stack1 bit32 */
			{12962, 5,0}, /* core2 return_Stack1 bit33 */
			{12961, 5,0}, /* core2 return_Stack1 bit34 */
			{12960, 5,0}, /* core2 return_Stack1 bit35 */
			{12929, 5,0}, /* core2 return_Stack1 bit36 */
			{12928, 5,0}, /* core2 return_Stack1 bit37 */
			{12927, 5,0}, /* core2 return_Stack1 bit38 */
			{12926, 5,0}, /* core2 return_Stack1 bit39 */
			{12941, 5,0}, /* core2 return_Stack1 bit40 */
			{12940, 5,0}, /* core2 return_Stack1 bit41 */
			{12939, 5,0}, /* core2 return_Stack1 bit42 */
			{12938, 5,0}, /* core2 return_Stack1 bit43 */
			{12937, 5,0}, /* core2 return_Stack1 bit44 */
			{12936, 5,0}, /* core2 return_Stack1 bit45 */
			{12935, 5,0}, /* core2 return_Stack1 bit46 */
			{12934, 5,0}, /* core2 return_Stack1 bit47 */
			{14950, 5,0}, /* core2 return_Stack1 bit48 */
			{    0, 0,2}, /* core2 return_Stack1 bit49 */
			{    0, 0,2}, /* core2 return_Stack1 bit50 */
			{    0, 0,2}, /* core2 return_Stack1 bit51 */
			{    0, 0,2}, /* core2 return_Stack1 bit52 */
			{    0, 0,2}, /* core2 return_Stack1 bit53 */
			{    0, 0,2}, /* core2 return_Stack1 bit54 */
			{    0, 0,2}, /* core2 return_Stack1 bit55 */
			{    0, 0,2}, /* core2 return_Stack1 bit56 */
			{    0, 0,2}, /* core2 return_Stack1 bit57 */
			{    0, 0,2}, /* core2 return_Stack1 bit58 */
			{    0, 0,2}, /* core2 return_Stack1 bit59 */
			{    0, 0,2}, /* core2 return_Stack1 bit60 */
			{    0, 0,2}, /* core2 return_Stack1 bit61 */
			{    0, 0,2}, /* core2 return_Stack1 bit62 */
			{    0, 0,2}, /* core2 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{12987, 5,0}, /* core2 return_Stack2 bit0 */
			{12986, 5,0}, /* core2 return_Stack2 bit1 */
			{12985, 5,0}, /* core2 return_Stack2 bit2 */
			{12984, 5,0}, /* core2 return_Stack2 bit3 */
			{16669, 5,0}, /* core2 return_Stack2 bit4 */
			{16668, 5,0}, /* core2 return_Stack2 bit5 */
			{16667, 5,0}, /* core2 return_Stack2 bit6 */
			{16666, 5,0}, /* core2 return_Stack2 bit7 */
			{16685, 5,0}, /* core2 return_Stack2 bit8 */
			{16684, 5,0}, /* core2 return_Stack2 bit9 */
			{16683, 5,0}, /* core2 return_Stack2 bit10 */
			{16682, 5,0}, /* core2 return_Stack2 bit11 */
			{16677, 5,0}, /* core2 return_Stack2 bit12 */
			{16676, 5,0}, /* core2 return_Stack2 bit13 */
			{16675, 5,0}, /* core2 return_Stack2 bit14 */
			{16674, 5,0}, /* core2 return_Stack2 bit15 */
			{16673, 5,0}, /* core2 return_Stack2 bit16 */
			{16672, 5,0}, /* core2 return_Stack2 bit17 */
			{16671, 5,0}, /* core2 return_Stack2 bit18 */
			{16670, 5,0}, /* core2 return_Stack2 bit19 */
			{16657, 5,0}, /* core2 return_Stack2 bit20 */
			{16656, 5,0}, /* core2 return_Stack2 bit21 */
			{16655, 5,0}, /* core2 return_Stack2 bit22 */
			{16654, 5,0}, /* core2 return_Stack2 bit23 */
			{16653, 5,0}, /* core2 return_Stack2 bit24 */
			{16652, 5,0}, /* core2 return_Stack2 bit25 */
			{16651, 5,0}, /* core2 return_Stack2 bit26 */
			{16650, 5,0}, /* core2 return_Stack2 bit27 */
			{16645, 5,0}, /* core2 return_Stack2 bit28 */
			{16644, 5,0}, /* core2 return_Stack2 bit29 */
			{16643, 5,0}, /* core2 return_Stack2 bit30 */
			{16642, 5,0}, /* core2 return_Stack2 bit31 */
			{16633, 5,0}, /* core2 return_Stack2 bit32 */
			{16632, 5,0}, /* core2 return_Stack2 bit33 */
			{16631, 5,0}, /* core2 return_Stack2 bit34 */
			{16630, 5,0}, /* core2 return_Stack2 bit35 */
			{16625, 5,0}, /* core2 return_Stack2 bit36 */
			{16624, 5,0}, /* core2 return_Stack2 bit37 */
			{16623, 5,0}, /* core2 return_Stack2 bit38 */
			{16622, 5,0}, /* core2 return_Stack2 bit39 */
			{16629, 5,0}, /* core2 return_Stack2 bit40 */
			{16628, 5,0}, /* core2 return_Stack2 bit41 */
			{16627, 5,0}, /* core2 return_Stack2 bit42 */
			{16626, 5,0}, /* core2 return_Stack2 bit43 */
			{16637, 5,0}, /* core2 return_Stack2 bit44 */
			{16636, 5,0}, /* core2 return_Stack2 bit45 */
			{16635, 5,0}, /* core2 return_Stack2 bit46 */
			{16634, 5,0}, /* core2 return_Stack2 bit47 */
			{14952, 5,0}, /* core2 return_Stack2 bit48 */
			{    0, 0,2}, /* core2 return_Stack2 bit49 */
			{    0, 0,2}, /* core2 return_Stack2 bit50 */
			{    0, 0,2}, /* core2 return_Stack2 bit51 */
			{    0, 0,2}, /* core2 return_Stack2 bit52 */
			{    0, 0,2}, /* core2 return_Stack2 bit53 */
			{    0, 0,2}, /* core2 return_Stack2 bit54 */
			{    0, 0,2}, /* core2 return_Stack2 bit55 */
			{    0, 0,2}, /* core2 return_Stack2 bit56 */
			{    0, 0,2}, /* core2 return_Stack2 bit57 */
			{    0, 0,2}, /* core2 return_Stack2 bit58 */
			{    0, 0,2}, /* core2 return_Stack2 bit59 */
			{    0, 0,2}, /* core2 return_Stack2 bit60 */
			{    0, 0,2}, /* core2 return_Stack2 bit61 */
			{    0, 0,2}, /* core2 return_Stack2 bit62 */
			{    0, 0,2}, /* core2 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{16697, 5,0}, /* core2 return_Stack3 bit0 */
			{16696, 5,0}, /* core2 return_Stack3 bit1 */
			{16695, 5,0}, /* core2 return_Stack3 bit2 */
			{16694, 5,0}, /* core2 return_Stack3 bit3 */
			{16665, 5,0}, /* core2 return_Stack3 bit4 */
			{16664, 5,0}, /* core2 return_Stack3 bit5 */
			{16663, 5,0}, /* core2 return_Stack3 bit6 */
			{16662, 5,0}, /* core2 return_Stack3 bit7 */
			{16693, 5,0}, /* core2 return_Stack3 bit8 */
			{16692, 5,0}, /* core2 return_Stack3 bit9 */
			{16691, 5,0}, /* core2 return_Stack3 bit10 */
			{16690, 5,0}, /* core2 return_Stack3 bit11 */
			{16681, 5,0}, /* core2 return_Stack3 bit12 */
			{16680, 5,0}, /* core2 return_Stack3 bit13 */
			{16679, 5,0}, /* core2 return_Stack3 bit14 */
			{16678, 5,0}, /* core2 return_Stack3 bit15 */
			{16689, 5,0}, /* core2 return_Stack3 bit16 */
			{16688, 5,0}, /* core2 return_Stack3 bit17 */
			{16687, 5,0}, /* core2 return_Stack3 bit18 */
			{16686, 5,0}, /* core2 return_Stack3 bit19 */
			{16661, 5,0}, /* core2 return_Stack3 bit20 */
			{16660, 5,0}, /* core2 return_Stack3 bit21 */
			{16659, 5,0}, /* core2 return_Stack3 bit22 */
			{16658, 5,0}, /* core2 return_Stack3 bit23 */
			{16641, 5,0}, /* core2 return_Stack3 bit24 */
			{16640, 5,0}, /* core2 return_Stack3 bit25 */
			{16639, 5,0}, /* core2 return_Stack3 bit26 */
			{16638, 5,0}, /* core2 return_Stack3 bit27 */
			{16649, 5,0}, /* core2 return_Stack3 bit28 */
			{16648, 5,0}, /* core2 return_Stack3 bit29 */
			{16647, 5,0}, /* core2 return_Stack3 bit30 */
			{16646, 5,0}, /* core2 return_Stack3 bit31 */
			{12959, 5,0}, /* core2 return_Stack3 bit32 */
			{12958, 5,0}, /* core2 return_Stack3 bit33 */
			{12957, 5,0}, /* core2 return_Stack3 bit34 */
			{12956, 5,0}, /* core2 return_Stack3 bit35 */
			{12951, 5,0}, /* core2 return_Stack3 bit36 */
			{12950, 5,0}, /* core2 return_Stack3 bit37 */
			{12949, 5,0}, /* core2 return_Stack3 bit38 */
			{12948, 5,0}, /* core2 return_Stack3 bit39 */
			{12945, 5,0}, /* core2 return_Stack3 bit40 */
			{12944, 5,0}, /* core2 return_Stack3 bit41 */
			{12943, 5,0}, /* core2 return_Stack3 bit42 */
			{12942, 5,0}, /* core2 return_Stack3 bit43 */
			{12955, 5,0}, /* core2 return_Stack3 bit44 */
			{12954, 5,0}, /* core2 return_Stack3 bit45 */
			{12953, 5,0}, /* core2 return_Stack3 bit46 */
			{12952, 5,0}, /* core2 return_Stack3 bit47 */
			{14949, 5,0}, /* core2 return_Stack3 bit48 */
			{    0, 0,2}, /* core2 return_Stack3 bit49 */
			{    0, 0,2}, /* core2 return_Stack3 bit50 */
			{    0, 0,2}, /* core2 return_Stack3 bit51 */
			{    0, 0,2}, /* core2 return_Stack3 bit52 */
			{    0, 0,2}, /* core2 return_Stack3 bit53 */
			{    0, 0,2}, /* core2 return_Stack3 bit54 */
			{    0, 0,2}, /* core2 return_Stack3 bit55 */
			{    0, 0,2}, /* core2 return_Stack3 bit56 */
			{    0, 0,2}, /* core2 return_Stack3 bit57 */
			{    0, 0,2}, /* core2 return_Stack3 bit58 */
			{    0, 0,2}, /* core2 return_Stack3 bit59 */
			{    0, 0,2}, /* core2 return_Stack3 bit60 */
			{    0, 0,2}, /* core2 return_Stack3 bit61 */
			{    0, 0,2}, /* core2 return_Stack3 bit62 */
			{    0, 0,2}, /* core2 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{13011, 5,0}, /* core2 return_Stack4 bit0 */
			{13010, 5,0}, /* core2 return_Stack4 bit1 */
			{13009, 5,0}, /* core2 return_Stack4 bit2 */
			{13008, 5,0}, /* core2 return_Stack4 bit3 */
			{13003, 5,0}, /* core2 return_Stack4 bit4 */
			{13002, 5,0}, /* core2 return_Stack4 bit5 */
			{13001, 5,0}, /* core2 return_Stack4 bit6 */
			{13000, 5,0}, /* core2 return_Stack4 bit7 */
			{12979, 5,0}, /* core2 return_Stack4 bit8 */
			{12978, 5,0}, /* core2 return_Stack4 bit9 */
			{12977, 5,0}, /* core2 return_Stack4 bit10 */
			{12976, 5,0}, /* core2 return_Stack4 bit11 */
			{12975, 5,0}, /* core2 return_Stack4 bit12 */
			{12974, 5,0}, /* core2 return_Stack4 bit13 */
			{12973, 5,0}, /* core2 return_Stack4 bit14 */
			{12972, 5,0}, /* core2 return_Stack4 bit15 */
			{13015, 5,0}, /* core2 return_Stack4 bit16 */
			{13014, 5,0}, /* core2 return_Stack4 bit17 */
			{13013, 5,0}, /* core2 return_Stack4 bit18 */
			{13012, 5,0}, /* core2 return_Stack4 bit19 */
			{13023, 5,0}, /* core2 return_Stack4 bit20 */
			{13022, 5,0}, /* core2 return_Stack4 bit21 */
			{13021, 5,0}, /* core2 return_Stack4 bit22 */
			{13020, 5,0}, /* core2 return_Stack4 bit23 */
			{13088, 5,0}, /* core2 return_Stack4 bit24 */
			{13087, 5,0}, /* core2 return_Stack4 bit25 */
			{13086, 5,0}, /* core2 return_Stack4 bit26 */
			{13085, 5,0}, /* core2 return_Stack4 bit27 */
			{16309, 5,0}, /* core2 return_Stack4 bit28 */
			{16308, 5,0}, /* core2 return_Stack4 bit29 */
			{16307, 5,0}, /* core2 return_Stack4 bit30 */
			{16306, 5,0}, /* core2 return_Stack4 bit31 */
			{13080, 5,0}, /* core2 return_Stack4 bit32 */
			{13079, 5,0}, /* core2 return_Stack4 bit33 */
			{13078, 5,0}, /* core2 return_Stack4 bit34 */
			{13077, 5,0}, /* core2 return_Stack4 bit35 */
			{18841, 4,0}, /* core2 return_Stack4 bit36 */
			{18840, 4,0}, /* core2 return_Stack4 bit37 */
			{18839, 4,0}, /* core2 return_Stack4 bit38 */
			{18838, 4,0}, /* core2 return_Stack4 bit39 */
			{18837, 4,0}, /* core2 return_Stack4 bit40 */
			{18836, 4,0}, /* core2 return_Stack4 bit41 */
			{18835, 4,0}, /* core2 return_Stack4 bit42 */
			{18834, 4,0}, /* core2 return_Stack4 bit43 */
			{18845, 4,0}, /* core2 return_Stack4 bit44 */
			{18844, 4,0}, /* core2 return_Stack4 bit45 */
			{18843, 4,0}, /* core2 return_Stack4 bit46 */
			{18842, 4,0}, /* core2 return_Stack4 bit47 */
			{14567, 5,0}, /* core2 return_Stack4 bit48 */
			{    0, 0,2}, /* core2 return_Stack4 bit49 */
			{    0, 0,2}, /* core2 return_Stack4 bit50 */
			{    0, 0,2}, /* core2 return_Stack4 bit51 */
			{    0, 0,2}, /* core2 return_Stack4 bit52 */
			{    0, 0,2}, /* core2 return_Stack4 bit53 */
			{    0, 0,2}, /* core2 return_Stack4 bit54 */
			{    0, 0,2}, /* core2 return_Stack4 bit55 */
			{    0, 0,2}, /* core2 return_Stack4 bit56 */
			{    0, 0,2}, /* core2 return_Stack4 bit57 */
			{    0, 0,2}, /* core2 return_Stack4 bit58 */
			{    0, 0,2}, /* core2 return_Stack4 bit59 */
			{    0, 0,2}, /* core2 return_Stack4 bit60 */
			{    0, 0,2}, /* core2 return_Stack4 bit61 */
			{    0, 0,2}, /* core2 return_Stack4 bit62 */
			{    0, 0,2}, /* core2 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{16717, 5,0}, /* core2 return_Stack5 bit0 */
			{16716, 5,0}, /* core2 return_Stack5 bit1 */
			{16715, 5,0}, /* core2 return_Stack5 bit2 */
			{16714, 5,0}, /* core2 return_Stack5 bit3 */
			{16709, 5,0}, /* core2 return_Stack5 bit4 */
			{16708, 5,0}, /* core2 return_Stack5 bit5 */
			{16707, 5,0}, /* core2 return_Stack5 bit6 */
			{16706, 5,0}, /* core2 return_Stack5 bit7 */
			{12991, 5,0}, /* core2 return_Stack5 bit8 */
			{12990, 5,0}, /* core2 return_Stack5 bit9 */
			{12989, 5,0}, /* core2 return_Stack5 bit10 */
			{12988, 5,0}, /* core2 return_Stack5 bit11 */
			{16757, 5,0}, /* core2 return_Stack5 bit12 */
			{16756, 5,0}, /* core2 return_Stack5 bit13 */
			{16755, 5,0}, /* core2 return_Stack5 bit14 */
			{16754, 5,0}, /* core2 return_Stack5 bit15 */
			{16749, 5,0}, /* core2 return_Stack5 bit16 */
			{16748, 5,0}, /* core2 return_Stack5 bit17 */
			{16747, 5,0}, /* core2 return_Stack5 bit18 */
			{16746, 5,0}, /* core2 return_Stack5 bit19 */
			{16769, 5,0}, /* core2 return_Stack5 bit20 */
			{16768, 5,0}, /* core2 return_Stack5 bit21 */
			{16767, 5,0}, /* core2 return_Stack5 bit22 */
			{16766, 5,0}, /* core2 return_Stack5 bit23 */
			{12971, 5,0}, /* core2 return_Stack5 bit24 */
			{12970, 5,0}, /* core2 return_Stack5 bit25 */
			{12969, 5,0}, /* core2 return_Stack5 bit26 */
			{12968, 5,0}, /* core2 return_Stack5 bit27 */
			{12967, 5,0}, /* core2 return_Stack5 bit28 */
			{12966, 5,0}, /* core2 return_Stack5 bit29 */
			{12965, 5,0}, /* core2 return_Stack5 bit30 */
			{12964, 5,0}, /* core2 return_Stack5 bit31 */
			{13056, 5,0}, /* core2 return_Stack5 bit32 */
			{13055, 5,0}, /* core2 return_Stack5 bit33 */
			{13054, 5,0}, /* core2 return_Stack5 bit34 */
			{13053, 5,0}, /* core2 return_Stack5 bit35 */
			{12925, 5,0}, /* core2 return_Stack5 bit36 */
			{12924, 5,0}, /* core2 return_Stack5 bit37 */
			{12923, 5,0}, /* core2 return_Stack5 bit38 */
			{12922, 5,0}, /* core2 return_Stack5 bit39 */
			{12921, 5,0}, /* core2 return_Stack5 bit40 */
			{12920, 5,0}, /* core2 return_Stack5 bit41 */
			{12919, 5,0}, /* core2 return_Stack5 bit42 */
			{12918, 5,0}, /* core2 return_Stack5 bit43 */
			{12933, 5,0}, /* core2 return_Stack5 bit44 */
			{12932, 5,0}, /* core2 return_Stack5 bit45 */
			{12931, 5,0}, /* core2 return_Stack5 bit46 */
			{12930, 5,0}, /* core2 return_Stack5 bit47 */
			{14951, 5,0}, /* core2 return_Stack5 bit48 */
			{    0, 0,2}, /* core2 return_Stack5 bit49 */
			{    0, 0,2}, /* core2 return_Stack5 bit50 */
			{    0, 0,2}, /* core2 return_Stack5 bit51 */
			{    0, 0,2}, /* core2 return_Stack5 bit52 */
			{    0, 0,2}, /* core2 return_Stack5 bit53 */
			{    0, 0,2}, /* core2 return_Stack5 bit54 */
			{    0, 0,2}, /* core2 return_Stack5 bit55 */
			{    0, 0,2}, /* core2 return_Stack5 bit56 */
			{    0, 0,2}, /* core2 return_Stack5 bit57 */
			{    0, 0,2}, /* core2 return_Stack5 bit58 */
			{    0, 0,2}, /* core2 return_Stack5 bit59 */
			{    0, 0,2}, /* core2 return_Stack5 bit60 */
			{    0, 0,2}, /* core2 return_Stack5 bit61 */
			{    0, 0,2}, /* core2 return_Stack5 bit62 */
			{    0, 0,2}, /* core2 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{16737, 5,0}, /* core2 return_Stack6 bit0 */
			{16736, 5,0}, /* core2 return_Stack6 bit1 */
			{16735, 5,0}, /* core2 return_Stack6 bit2 */
			{16734, 5,0}, /* core2 return_Stack6 bit3 */
			{13007, 5,0}, /* core2 return_Stack6 bit4 */
			{13006, 5,0}, /* core2 return_Stack6 bit5 */
			{13005, 5,0}, /* core2 return_Stack6 bit6 */
			{13004, 5,0}, /* core2 return_Stack6 bit7 */
			{12999, 5,0}, /* core2 return_Stack6 bit8 */
			{12998, 5,0}, /* core2 return_Stack6 bit9 */
			{12997, 5,0}, /* core2 return_Stack6 bit10 */
			{12996, 5,0}, /* core2 return_Stack6 bit11 */
			{16781, 5,0}, /* core2 return_Stack6 bit12 */
			{16780, 5,0}, /* core2 return_Stack6 bit13 */
			{16779, 5,0}, /* core2 return_Stack6 bit14 */
			{16778, 5,0}, /* core2 return_Stack6 bit15 */
			{16793, 5,0}, /* core2 return_Stack6 bit16 */
			{16792, 5,0}, /* core2 return_Stack6 bit17 */
			{16791, 5,0}, /* core2 return_Stack6 bit18 */
			{16790, 5,0}, /* core2 return_Stack6 bit19 */
			{13027, 5,0}, /* core2 return_Stack6 bit20 */
			{13026, 5,0}, /* core2 return_Stack6 bit21 */
			{13025, 5,0}, /* core2 return_Stack6 bit22 */
			{13024, 5,0}, /* core2 return_Stack6 bit23 */
			{13096, 5,0}, /* core2 return_Stack6 bit24 */
			{13095, 5,0}, /* core2 return_Stack6 bit25 */
			{13094, 5,0}, /* core2 return_Stack6 bit26 */
			{13093, 5,0}, /* core2 return_Stack6 bit27 */
			{13031, 5,0}, /* core2 return_Stack6 bit28 */
			{13030, 5,0}, /* core2 return_Stack6 bit29 */
			{13029, 5,0}, /* core2 return_Stack6 bit30 */
			{13028, 5,0}, /* core2 return_Stack6 bit31 */
			{13048, 5,0}, /* core2 return_Stack6 bit32 */
			{13047, 5,0}, /* core2 return_Stack6 bit33 */
			{13046, 5,0}, /* core2 return_Stack6 bit34 */
			{13045, 5,0}, /* core2 return_Stack6 bit35 */
			{13084, 5,0}, /* core2 return_Stack6 bit36 */
			{13083, 5,0}, /* core2 return_Stack6 bit37 */
			{13082, 5,0}, /* core2 return_Stack6 bit38 */
			{13081, 5,0}, /* core2 return_Stack6 bit39 */
			{12909, 5,0}, /* core2 return_Stack6 bit40 */
			{12908, 5,0}, /* core2 return_Stack6 bit41 */
			{12907, 5,0}, /* core2 return_Stack6 bit42 */
			{12906, 5,0}, /* core2 return_Stack6 bit43 */
			{13076, 5,0}, /* core2 return_Stack6 bit44 */
			{13075, 5,0}, /* core2 return_Stack6 bit45 */
			{13074, 5,0}, /* core2 return_Stack6 bit46 */
			{13073, 5,0}, /* core2 return_Stack6 bit47 */
			{14568, 5,0}, /* core2 return_Stack6 bit48 */
			{    0, 0,2}, /* core2 return_Stack6 bit49 */
			{    0, 0,2}, /* core2 return_Stack6 bit50 */
			{    0, 0,2}, /* core2 return_Stack6 bit51 */
			{    0, 0,2}, /* core2 return_Stack6 bit52 */
			{    0, 0,2}, /* core2 return_Stack6 bit53 */
			{    0, 0,2}, /* core2 return_Stack6 bit54 */
			{    0, 0,2}, /* core2 return_Stack6 bit55 */
			{    0, 0,2}, /* core2 return_Stack6 bit56 */
			{    0, 0,2}, /* core2 return_Stack6 bit57 */
			{    0, 0,2}, /* core2 return_Stack6 bit58 */
			{    0, 0,2}, /* core2 return_Stack6 bit59 */
			{    0, 0,2}, /* core2 return_Stack6 bit60 */
			{    0, 0,2}, /* core2 return_Stack6 bit61 */
			{    0, 0,2}, /* core2 return_Stack6 bit62 */
			{    0, 0,2}, /* core2 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{16733, 5,0}, /* core2 return_Stack7 bit0 */
			{16732, 5,0}, /* core2 return_Stack7 bit1 */
			{16731, 5,0}, /* core2 return_Stack7 bit2 */
			{16730, 5,0}, /* core2 return_Stack7 bit3 */
			{16713, 5,0}, /* core2 return_Stack7 bit4 */
			{16712, 5,0}, /* core2 return_Stack7 bit5 */
			{16711, 5,0}, /* core2 return_Stack7 bit6 */
			{16710, 5,0}, /* core2 return_Stack7 bit7 */
			{16745, 5,0}, /* core2 return_Stack7 bit8 */
			{16744, 5,0}, /* core2 return_Stack7 bit9 */
			{16743, 5,0}, /* core2 return_Stack7 bit10 */
			{16742, 5,0}, /* core2 return_Stack7 bit11 */
			{16785, 5,0}, /* core2 return_Stack7 bit12 */
			{16784, 5,0}, /* core2 return_Stack7 bit13 */
			{16783, 5,0}, /* core2 return_Stack7 bit14 */
			{16782, 5,0}, /* core2 return_Stack7 bit15 */
			{16741, 5,0}, /* core2 return_Stack7 bit16 */
			{16740, 5,0}, /* core2 return_Stack7 bit17 */
			{16739, 5,0}, /* core2 return_Stack7 bit18 */
			{16738, 5,0}, /* core2 return_Stack7 bit19 */
			{16801, 5,0}, /* core2 return_Stack7 bit20 */
			{16800, 5,0}, /* core2 return_Stack7 bit21 */
			{16799, 5,0}, /* core2 return_Stack7 bit22 */
			{16798, 5,0}, /* core2 return_Stack7 bit23 */
			{16797, 5,0}, /* core2 return_Stack7 bit24 */
			{16796, 5,0}, /* core2 return_Stack7 bit25 */
			{16795, 5,0}, /* core2 return_Stack7 bit26 */
			{16794, 5,0}, /* core2 return_Stack7 bit27 */
			{13035, 5,0}, /* core2 return_Stack7 bit28 */
			{13034, 5,0}, /* core2 return_Stack7 bit29 */
			{13033, 5,0}, /* core2 return_Stack7 bit30 */
			{13032, 5,0}, /* core2 return_Stack7 bit31 */
			{13044, 5,0}, /* core2 return_Stack7 bit32 */
			{13043, 5,0}, /* core2 return_Stack7 bit33 */
			{13042, 5,0}, /* core2 return_Stack7 bit34 */
			{13041, 5,0}, /* core2 return_Stack7 bit35 */
			{12913, 5,0}, /* core2 return_Stack7 bit36 */
			{12912, 5,0}, /* core2 return_Stack7 bit37 */
			{12911, 5,0}, /* core2 return_Stack7 bit38 */
			{12910, 5,0}, /* core2 return_Stack7 bit39 */
			{12917, 5,0}, /* core2 return_Stack7 bit40 */
			{12916, 5,0}, /* core2 return_Stack7 bit41 */
			{12915, 5,0}, /* core2 return_Stack7 bit42 */
			{12914, 5,0}, /* core2 return_Stack7 bit43 */
			{13060, 5,0}, /* core2 return_Stack7 bit44 */
			{13059, 5,0}, /* core2 return_Stack7 bit45 */
			{13058, 5,0}, /* core2 return_Stack7 bit46 */
			{13057, 5,0}, /* core2 return_Stack7 bit47 */
			{14569, 5,0}, /* core2 return_Stack7 bit48 */
			{    0, 0,2}, /* core2 return_Stack7 bit49 */
			{    0, 0,2}, /* core2 return_Stack7 bit50 */
			{    0, 0,2}, /* core2 return_Stack7 bit51 */
			{    0, 0,2}, /* core2 return_Stack7 bit52 */
			{    0, 0,2}, /* core2 return_Stack7 bit53 */
			{    0, 0,2}, /* core2 return_Stack7 bit54 */
			{    0, 0,2}, /* core2 return_Stack7 bit55 */
			{    0, 0,2}, /* core2 return_Stack7 bit56 */
			{    0, 0,2}, /* core2 return_Stack7 bit57 */
			{    0, 0,2}, /* core2 return_Stack7 bit58 */
			{    0, 0,2}, /* core2 return_Stack7 bit59 */
			{    0, 0,2}, /* core2 return_Stack7 bit60 */
			{    0, 0,2}, /* core2 return_Stack7 bit61 */
			{    0, 0,2}, /* core2 return_Stack7 bit62 */
			{    0, 0,2}, /* core2 return_Stack7 bit63 */
			}},
	},
	{		/* core 3 */
			.pc = {{
			{   37, 6,0}, /* core3 pc bit0 */
			{  105, 6,0}, /* core3 pc bit1 */
			{   28, 6,0}, /* core3 pc bit2 */
			{   67, 6,0}, /* core3 pc bit3 */
			{   66, 6,0}, /* core3 pc bit4 */
			{   65, 6,0}, /* core3 pc bit5 */
			{  104, 6,0}, /* core3 pc bit6 */
			{   34, 6,0}, /* core3 pc bit7 */
			{   33, 6,0}, /* core3 pc bit8 */
			{   32, 6,0}, /* core3 pc bit9 */
			{   55, 6,0}, /* core3 pc bit10 */
			{   54, 6,0}, /* core3 pc bit11 */
			{   53, 6,0}, /* core3 pc bit12 */
			{   52, 6,0}, /* core3 pc bit13 */
			{   36, 6,0}, /* core3 pc bit14 */
			{   51, 6,0}, /* core3 pc bit15 */
			{   50, 6,0}, /* core3 pc bit16 */
			{   49, 6,0}, /* core3 pc bit17 */
			{   48, 6,0}, /* core3 pc bit18 */
			{ 2483, 6,0}, /* core3 pc bit19 */
			{   64, 6,0}, /* core3 pc bit20 */
			{   43, 6,0}, /* core3 pc bit21 */
			{   42, 6,0}, /* core3 pc bit22 */
			{   41, 6,0}, /* core3 pc bit23 */
			{   40, 6,0}, /* core3 pc bit24 */
			{   47, 6,0}, /* core3 pc bit25 */
			{   46, 6,0}, /* core3 pc bit26 */
			{   45, 6,0}, /* core3 pc bit27 */
			{   44, 6,0}, /* core3 pc bit28 */
			{ 2479, 6,0}, /* core3 pc bit29 */
			{ 2478, 6,0}, /* core3 pc bit30 */
			{  119, 6,0}, /* core3 pc bit31 */
			{12041, 6,0}, /* core3 pc bit32 */
			{12040, 6,0}, /* core3 pc bit33 */
			{12039, 6,0}, /* core3 pc bit34 */
			{12038, 6,0}, /* core3 pc bit35 */
			{10951, 6,0}, /* core3 pc bit36 */
			{10950, 6,0}, /* core3 pc bit37 */
			{10949, 6,0}, /* core3 pc bit38 */
			{10948, 6,0}, /* core3 pc bit39 */
			{  146, 6,0}, /* core3 pc bit40 */
			{12113, 6,0}, /* core3 pc bit41 */
			{10955, 6,0}, /* core3 pc bit42 */
			{  145, 6,0}, /* core3 pc bit43 */
			{10954, 6,0}, /* core3 pc bit44 */
			{10953, 6,0}, /* core3 pc bit45 */
			{10952, 6,0}, /* core3 pc bit46 */
			{12105, 6,0}, /* core3 pc bit47 */
			{  144, 6,0}, /* core3 pc bit48 */
			{12104, 6,0}, /* core3 pc bit49 */
			{12103, 6,0}, /* core3 pc bit50 */
			{12112, 6,0}, /* core3 pc bit51 */
			{12111, 6,0}, /* core3 pc bit52 */
			{12102, 6,0}, /* core3 pc bit53 */
			{12109, 6,0}, /* core3 pc bit54 */
			{12108, 6,0}, /* core3 pc bit55 */
			{12107, 6,0}, /* core3 pc bit56 */
			{12106, 6,0}, /* core3 pc bit57 */
			{10959, 6,0}, /* core3 pc bit58 */
			{10958, 6,0}, /* core3 pc bit59 */
			{12110, 6,0}, /* core3 pc bit60 */
			{10957, 6,0}, /* core3 pc bit61 */
			{10956, 6,0}, /* core3 pc bit62 */
			{ 2717, 6,0}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{  221, 7,0}, /* core3 sp32 bit0 */
			{  191, 7,0}, /* core3 sp32 bit1 */
			{  117, 7,0}, /* core3 sp32 bit2 */
			{  113, 7,0}, /* core3 sp32 bit3 */
			{  111, 7,0}, /* core3 sp32 bit4 */
			{   71, 7,0}, /* core3 sp32 bit5 */
			{  123, 7,0}, /* core3 sp32 bit6 */
			{  114, 7,0}, /* core3 sp32 bit7 */
			{  119, 7,0}, /* core3 sp32 bit8 */
			{  107, 7,0}, /* core3 sp32 bit9 */
			{   14, 7,0}, /* core3 sp32 bit10 */
			{  124, 7,0}, /* core3 sp32 bit11 */
			{   72, 7,0}, /* core3 sp32 bit12 */
			{  121, 7,0}, /* core3 sp32 bit13 */
			{   70, 7,0}, /* core3 sp32 bit14 */
			{  112, 7,0}, /* core3 sp32 bit15 */
			{  122, 7,0}, /* core3 sp32 bit16 */
			{  192, 7,0}, /* core3 sp32 bit17 */
			{  118, 7,0}, /* core3 sp32 bit18 */
			{  120, 7,0}, /* core3 sp32 bit19 */
			{  131, 7,0}, /* core3 sp32 bit20 */
			{   15, 7,0}, /* core3 sp32 bit21 */
			{  125, 7,0}, /* core3 sp32 bit22 */
			{  115, 7,0}, /* core3 sp32 bit23 */
			{  132, 7,0}, /* core3 sp32 bit24 */
			{   11, 7,0}, /* core3 sp32 bit25 */
			{   17, 7,0}, /* core3 sp32 bit26 */
			{   10, 7,0}, /* core3 sp32 bit27 */
			{  158, 7,0}, /* core3 sp32 bit28 */
			{   16, 7,0}, /* core3 sp32 bit29 */
			{  194, 7,0}, /* core3 sp32 bit30 */
			{  175, 7,0}, /* core3 sp32 bit31 */
			{ 2071, 7,0}, /* core3 sp32 bit32 */
			{ 2072, 7,0}, /* core3 sp32 bit33 */
			{ 2075, 7,0}, /* core3 sp32 bit34 */
			{ 2059, 7,0}, /* core3 sp32 bit35 */
			{ 2077, 7,0}, /* core3 sp32 bit36 */
			{ 2073, 7,0}, /* core3 sp32 bit37 */
			{ 1999, 7,0}, /* core3 sp32 bit38 */
			{ 2074, 7,0}, /* core3 sp32 bit39 */
			{ 2016, 7,0}, /* core3 sp32 bit40 */
			{ 2000, 7,0}, /* core3 sp32 bit41 */
			{ 1997, 7,0}, /* core3 sp32 bit42 */
			{ 1996, 7,0}, /* core3 sp32 bit43 */
			{ 1998, 7,0}, /* core3 sp32 bit44 */
			{ 1991, 7,0}, /* core3 sp32 bit45 */
			{ 2007, 7,0}, /* core3 sp32 bit46 */
			{ 2316, 7,0}, /* core3 sp32 bit47 */
			{ 7943, 6,0}, /* core3 sp32 bit48 */
			{ 7946, 6,0}, /* core3 sp32 bit49 */
			{ 7975, 6,0}, /* core3 sp32 bit50 */
			{ 7952, 6,0}, /* core3 sp32 bit51 */
			{ 7950, 6,0}, /* core3 sp32 bit52 */
			{ 7944, 6,0}, /* core3 sp32 bit53 */
			{ 7947, 6,0}, /* core3 sp32 bit54 */
			{ 7976, 6,0}, /* core3 sp32 bit55 */
			{ 7949, 6,0}, /* core3 sp32 bit56 */
			{ 7953, 6,0}, /* core3 sp32 bit57 */
			{ 7951, 6,0}, /* core3 sp32 bit58 */
			{ 7954, 6,0}, /* core3 sp32 bit59 */
			{ 7948, 6,0}, /* core3 sp32 bit60 */
			{ 7958, 6,0}, /* core3 sp32 bit61 */
			{ 7945, 6,0}, /* core3 sp32 bit62 */
			{ 1993, 7,0}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{  248, 6,0}, /* core3 fp32 bit0 */
			{  247, 6,0}, /* core3 fp32 bit1 */
			{  253, 6,0}, /* core3 fp32 bit2 */
			{  364, 6,0}, /* core3 fp32 bit3 */
			{  356, 6,0}, /* core3 fp32 bit4 */
			{  246, 6,0}, /* core3 fp32 bit5 */
			{  384, 6,0}, /* core3 fp32 bit6 */
			{  385, 6,0}, /* core3 fp32 bit7 */
			{  258, 6,0}, /* core3 fp32 bit8 */
			{  254, 6,0}, /* core3 fp32 bit9 */
			{  257, 6,0}, /* core3 fp32 bit10 */
			{  392, 6,0}, /* core3 fp32 bit11 */
			{  255, 6,0}, /* core3 fp32 bit12 */
			{  391, 6,0}, /* core3 fp32 bit13 */
			{  387, 6,0}, /* core3 fp32 bit14 */
			{  256, 6,0}, /* core3 fp32 bit15 */
			{  388, 6,0}, /* core3 fp32 bit16 */
			{  354, 6,0}, /* core3 fp32 bit17 */
			{  363, 6,0}, /* core3 fp32 bit18 */
			{  368, 6,0}, /* core3 fp32 bit19 */
			{  335, 6,0}, /* core3 fp32 bit20 */
			{  366, 6,0}, /* core3 fp32 bit21 */
			{  341, 6,0}, /* core3 fp32 bit22 */
			{  339, 6,0}, /* core3 fp32 bit23 */
			{  340, 6,0}, /* core3 fp32 bit24 */
			{  367, 6,0}, /* core3 fp32 bit25 */
			{  337, 6,0}, /* core3 fp32 bit26 */
			{  369, 6,0}, /* core3 fp32 bit27 */
			{  370, 6,0}, /* core3 fp32 bit28 */
			{  336, 6,0}, /* core3 fp32 bit29 */
			{  338, 6,0}, /* core3 fp32 bit30 */
			{  358, 6,0}, /* core3 fp32 bit31 */
			{ 2368, 7,0}, /* core3 fp32 bit32 */
			{ 2381, 7,0}, /* core3 fp32 bit33 */
			{ 2370, 7,0}, /* core3 fp32 bit34 */
			{ 2371, 7,0}, /* core3 fp32 bit35 */
			{ 2386, 7,0}, /* core3 fp32 bit36 */
			{ 2380, 7,0}, /* core3 fp32 bit37 */
			{ 2336, 7,0}, /* core3 fp32 bit38 */
			{ 2379, 7,0}, /* core3 fp32 bit39 */
			{ 2335, 7,0}, /* core3 fp32 bit40 */
			{ 2346, 7,0}, /* core3 fp32 bit41 */
			{ 2339, 7,0}, /* core3 fp32 bit42 */
			{ 2330, 7,0}, /* core3 fp32 bit43 */
			{ 2334, 7,0}, /* core3 fp32 bit44 */
			{ 2345, 7,0}, /* core3 fp32 bit45 */
			{ 2387, 7,0}, /* core3 fp32 bit46 */
			{ 8052, 6,0}, /* core3 fp32 bit47 */
			{ 8054, 6,0}, /* core3 fp32 bit48 */
			{ 2488, 7,0}, /* core3 fp32 bit49 */
			{ 2493, 7,0}, /* core3 fp32 bit50 */
			{ 2506, 7,0}, /* core3 fp32 bit51 */
			{ 2495, 7,0}, /* core3 fp32 bit52 */
			{ 2508, 7,0}, /* core3 fp32 bit53 */
			{ 8051, 6,0}, /* core3 fp32 bit54 */
			{ 2497, 7,0}, /* core3 fp32 bit55 */
			{ 8055, 6,0}, /* core3 fp32 bit56 */
			{ 2498, 7,0}, /* core3 fp32 bit57 */
			{ 8053, 6,0}, /* core3 fp32 bit58 */
			{ 8056, 6,0}, /* core3 fp32 bit59 */
			{ 2492, 7,0}, /* core3 fp32 bit60 */
			{ 2487, 7,0}, /* core3 fp32 bit61 */
			{ 2496, 7,0}, /* core3 fp32 bit62 */
			{ 7942, 6,0}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{  209, 7,0}, /* core3 fp64 bit0 */
			{   50, 7,0}, /* core3 fp64 bit1 */
			{   45, 7,0}, /* core3 fp64 bit2 */
			{  210, 7,0}, /* core3 fp64 bit3 */
			{   58, 7,0}, /* core3 fp64 bit4 */
			{   46, 7,0}, /* core3 fp64 bit5 */
			{  205, 7,0}, /* core3 fp64 bit6 */
			{  213, 7,0}, /* core3 fp64 bit7 */
			{   59, 7,0}, /* core3 fp64 bit8 */
			{  217, 7,0}, /* core3 fp64 bit9 */
			{  207, 7,0}, /* core3 fp64 bit10 */
			{   77, 7,0}, /* core3 fp64 bit11 */
			{  197, 7,0}, /* core3 fp64 bit12 */
			{  200, 7,0}, /* core3 fp64 bit13 */
			{  206, 7,0}, /* core3 fp64 bit14 */
			{  204, 7,0}, /* core3 fp64 bit15 */
			{  199, 7,0}, /* core3 fp64 bit16 */
			{  224, 7,0}, /* core3 fp64 bit17 */
			{  198, 7,0}, /* core3 fp64 bit18 */
			{   83, 7,0}, /* core3 fp64 bit19 */
			{  223, 7,0}, /* core3 fp64 bit20 */
			{  226, 7,0}, /* core3 fp64 bit21 */
			{   61, 7,0}, /* core3 fp64 bit22 */
			{   81, 7,0}, /* core3 fp64 bit23 */
			{   84, 7,0}, /* core3 fp64 bit24 */
			{   80, 7,0}, /* core3 fp64 bit25 */
			{   82, 7,0}, /* core3 fp64 bit26 */
			{   85, 7,0}, /* core3 fp64 bit27 */
			{   78, 7,0}, /* core3 fp64 bit28 */
			{  225, 7,0}, /* core3 fp64 bit29 */
			{   79, 7,0}, /* core3 fp64 bit30 */
			{  215, 7,0}, /* core3 fp64 bit31 */
			{ 1708, 7,0}, /* core3 fp64 bit32 */
			{ 1676, 7,0}, /* core3 fp64 bit33 */
			{ 1677, 7,0}, /* core3 fp64 bit34 */
			{ 1707, 7,0}, /* core3 fp64 bit35 */
			{ 1668, 7,0}, /* core3 fp64 bit36 */
			{ 1675, 7,0}, /* core3 fp64 bit37 */
			{ 1593, 7,0}, /* core3 fp64 bit38 */
			{ 1709, 7,0}, /* core3 fp64 bit39 */
			{ 1594, 7,0}, /* core3 fp64 bit40 */
			{ 1592, 7,0}, /* core3 fp64 bit41 */
			{ 1657, 7,0}, /* core3 fp64 bit42 */
			{ 1589, 7,0}, /* core3 fp64 bit43 */
			{ 1632, 7,0}, /* core3 fp64 bit44 */
			{ 1590, 7,0}, /* core3 fp64 bit45 */
			{ 1591, 7,0}, /* core3 fp64 bit46 */
			{ 3287, 7,0}, /* core3 fp64 bit47 */
			{ 3373, 7,0}, /* core3 fp64 bit48 */
			{ 3292, 7,0}, /* core3 fp64 bit49 */
			{ 3375, 7,0}, /* core3 fp64 bit50 */
			{ 3374, 7,0}, /* core3 fp64 bit51 */
			{ 3286, 7,0}, /* core3 fp64 bit52 */
			{ 3294, 7,0}, /* core3 fp64 bit53 */
			{ 3366, 7,0}, /* core3 fp64 bit54 */
			{ 3371, 7,0}, /* core3 fp64 bit55 */
			{ 3297, 7,0}, /* core3 fp64 bit56 */
			{ 3365, 7,0}, /* core3 fp64 bit57 */
			{ 3376, 7,0}, /* core3 fp64 bit58 */
			{ 3296, 7,0}, /* core3 fp64 bit59 */
			{ 3369, 7,0}, /* core3 fp64 bit60 */
			{ 3372, 7,0}, /* core3 fp64 bit61 */
			{ 3368, 7,0}, /* core3 fp64 bit62 */
			{ 1631, 7,0}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{   56, 7,0}, /* core3 sp_EL0 bit0 */
			{   47, 7,0}, /* core3 sp_EL0 bit1 */
			{   49, 7,0}, /* core3 sp_EL0 bit2 */
			{   48, 7,0}, /* core3 sp_EL0 bit3 */
			{   53, 7,0}, /* core3 sp_EL0 bit4 */
			{   52, 7,0}, /* core3 sp_EL0 bit5 */
			{ 1254, 7,0}, /* core3 sp_EL0 bit6 */
			{ 1277, 7,0}, /* core3 sp_EL0 bit7 */
			{   41, 7,0}, /* core3 sp_EL0 bit8 */
			{ 1300, 7,0}, /* core3 sp_EL0 bit9 */
			{   44, 7,0}, /* core3 sp_EL0 bit10 */
			{   40, 7,0}, /* core3 sp_EL0 bit11 */
			{   43, 7,0}, /* core3 sp_EL0 bit12 */
			{   57, 7,0}, /* core3 sp_EL0 bit13 */
			{ 1273, 7,0}, /* core3 sp_EL0 bit14 */
			{   51, 7,0}, /* core3 sp_EL0 bit15 */
			{   42, 7,0}, /* core3 sp_EL0 bit16 */
			{   22, 7,0}, /* core3 sp_EL0 bit17 */
			{   60, 7,0}, /* core3 sp_EL0 bit18 */
			{   39, 7,0}, /* core3 sp_EL0 bit19 */
			{ 1338, 7,0}, /* core3 sp_EL0 bit20 */
			{ 1247, 7,0}, /* core3 sp_EL0 bit21 */
			{ 1350, 7,0}, /* core3 sp_EL0 bit22 */
			{ 1332, 7,0}, /* core3 sp_EL0 bit23 */
			{ 1253, 7,0}, /* core3 sp_EL0 bit24 */
			{ 1252, 7,0}, /* core3 sp_EL0 bit25 */
			{ 1333, 7,0}, /* core3 sp_EL0 bit26 */
			{ 1335, 7,0}, /* core3 sp_EL0 bit27 */
			{ 1347, 7,0}, /* core3 sp_EL0 bit28 */
			{ 1251, 7,0}, /* core3 sp_EL0 bit29 */
			{ 1349, 7,0}, /* core3 sp_EL0 bit30 */
			{ 1257, 7,0}, /* core3 sp_EL0 bit31 */
			{ 1060, 7,0}, /* core3 sp_EL0 bit32 */
			{ 1719, 7,0}, /* core3 sp_EL0 bit33 */
			{ 1700, 7,0}, /* core3 sp_EL0 bit34 */
			{ 1701, 7,0}, /* core3 sp_EL0 bit35 */
			{ 1655, 7,0}, /* core3 sp_EL0 bit36 */
			{ 1059, 7,0}, /* core3 sp_EL0 bit37 */
			{ 1653, 7,0}, /* core3 sp_EL0 bit38 */
			{ 1704, 7,0}, /* core3 sp_EL0 bit39 */
			{ 1634, 7,0}, /* core3 sp_EL0 bit40 */
			{ 1637, 7,0}, /* core3 sp_EL0 bit41 */
			{ 1687, 7,0}, /* core3 sp_EL0 bit42 */
			{ 1633, 7,0}, /* core3 sp_EL0 bit43 */
			{ 1651, 7,0}, /* core3 sp_EL0 bit44 */
			{ 1636, 7,0}, /* core3 sp_EL0 bit45 */
			{ 1587, 7,0}, /* core3 sp_EL0 bit46 */
			{ 3370, 7,0}, /* core3 sp_EL0 bit47 */
			{ 3347, 7,0}, /* core3 sp_EL0 bit48 */
			{ 3345, 7,0}, /* core3 sp_EL0 bit49 */
			{ 3349, 7,0}, /* core3 sp_EL0 bit50 */
			{ 3354, 7,0}, /* core3 sp_EL0 bit51 */
			{ 3343, 7,0}, /* core3 sp_EL0 bit52 */
			{ 3341, 7,0}, /* core3 sp_EL0 bit53 */
			{ 3351, 7,0}, /* core3 sp_EL0 bit54 */
			{ 3344, 7,0}, /* core3 sp_EL0 bit55 */
			{ 3337, 7,0}, /* core3 sp_EL0 bit56 */
			{ 3346, 7,0}, /* core3 sp_EL0 bit57 */
			{ 3338, 7,0}, /* core3 sp_EL0 bit58 */
			{ 3342, 7,0}, /* core3 sp_EL0 bit59 */
			{ 3340, 7,0}, /* core3 sp_EL0 bit60 */
			{ 3353, 7,0}, /* core3 sp_EL0 bit61 */
			{ 3339, 7,0}, /* core3 sp_EL0 bit62 */
			{ 1658, 7,0}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{  208, 7,0}, /* core3 sp_EL1 bit0 */
			{  202, 7,0}, /* core3 sp_EL1 bit1 */
			{  211, 7,0}, /* core3 sp_EL1 bit2 */
			{  201, 7,0}, /* core3 sp_EL1 bit3 */
			{   89, 7,0}, /* core3 sp_EL1 bit4 */
			{  212, 7,0}, /* core3 sp_EL1 bit5 */
			{  138, 7,0}, /* core3 sp_EL1 bit6 */
			{   68, 7,0}, /* core3 sp_EL1 bit7 */
			{   69, 7,0}, /* core3 sp_EL1 bit8 */
			{  196, 7,0}, /* core3 sp_EL1 bit9 */
			{   76, 7,0}, /* core3 sp_EL1 bit10 */
			{  218, 7,0}, /* core3 sp_EL1 bit11 */
			{   13, 7,0}, /* core3 sp_EL1 bit12 */
			{  195, 7,0}, /* core3 sp_EL1 bit13 */
			{   12, 7,0}, /* core3 sp_EL1 bit14 */
			{  220, 7,0}, /* core3 sp_EL1 bit15 */
			{  219, 7,0}, /* core3 sp_EL1 bit16 */
			{   75, 7,0}, /* core3 sp_EL1 bit17 */
			{   19, 7,0}, /* core3 sp_EL1 bit18 */
			{  133, 7,0}, /* core3 sp_EL1 bit19 */
			{  136, 7,0}, /* core3 sp_EL1 bit20 */
			{   73, 7,0}, /* core3 sp_EL1 bit21 */
			{  141, 7,0}, /* core3 sp_EL1 bit22 */
			{  137, 7,0}, /* core3 sp_EL1 bit23 */
			{  139, 7,0}, /* core3 sp_EL1 bit24 */
			{  135, 7,0}, /* core3 sp_EL1 bit25 */
			{  222, 7,0}, /* core3 sp_EL1 bit26 */
			{   86, 7,0}, /* core3 sp_EL1 bit27 */
			{  134, 7,0}, /* core3 sp_EL1 bit28 */
			{   74, 7,0}, /* core3 sp_EL1 bit29 */
			{  116, 7,0}, /* core3 sp_EL1 bit30 */
			{   88, 7,0}, /* core3 sp_EL1 bit31 */
			{ 1697, 7,0}, /* core3 sp_EL1 bit32 */
			{ 1695, 7,0}, /* core3 sp_EL1 bit33 */
			{ 1698, 7,0}, /* core3 sp_EL1 bit34 */
			{ 1696, 7,0}, /* core3 sp_EL1 bit35 */
			{ 1679, 7,0}, /* core3 sp_EL1 bit36 */
			{ 1699, 7,0}, /* core3 sp_EL1 bit37 */
			{ 1684, 7,0}, /* core3 sp_EL1 bit38 */
			{ 1694, 7,0}, /* core3 sp_EL1 bit39 */
			{ 1656, 7,0}, /* core3 sp_EL1 bit40 */
			{ 1686, 7,0}, /* core3 sp_EL1 bit41 */
			{ 1678, 7,0}, /* core3 sp_EL1 bit42 */
			{ 1680, 7,0}, /* core3 sp_EL1 bit43 */
			{ 1691, 7,0}, /* core3 sp_EL1 bit44 */
			{ 1586, 7,0}, /* core3 sp_EL1 bit45 */
			{ 1685, 7,0}, /* core3 sp_EL1 bit46 */
			{ 1035, 7,0}, /* core3 sp_EL1 bit47 */
			{ 3288, 7,0}, /* core3 sp_EL1 bit48 */
			{ 1034, 7,0}, /* core3 sp_EL1 bit49 */
			{ 3285, 7,0}, /* core3 sp_EL1 bit50 */
			{ 3289, 7,0}, /* core3 sp_EL1 bit51 */
			{ 3268, 7,0}, /* core3 sp_EL1 bit52 */
			{ 1019, 7,0}, /* core3 sp_EL1 bit53 */
			{ 1023, 7,0}, /* core3 sp_EL1 bit54 */
			{ 3290, 7,0}, /* core3 sp_EL1 bit55 */
			{ 3295, 7,0}, /* core3 sp_EL1 bit56 */
			{ 3302, 7,0}, /* core3 sp_EL1 bit57 */
			{ 3293, 7,0}, /* core3 sp_EL1 bit58 */
			{ 3283, 7,0}, /* core3 sp_EL1 bit59 */
			{ 3299, 7,0}, /* core3 sp_EL1 bit60 */
			{ 3291, 7,0}, /* core3 sp_EL1 bit61 */
			{ 1020, 7,0}, /* core3 sp_EL1 bit62 */
			{ 1693, 7,0}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 1307, 7,0}, /* core3 sp_EL2 bit0 */
			{ 1283, 7,0}, /* core3 sp_EL2 bit1 */
			{ 1308, 7,0}, /* core3 sp_EL2 bit2 */
			{ 1255, 7,0}, /* core3 sp_EL2 bit3 */
			{ 1265, 7,0}, /* core3 sp_EL2 bit4 */
			{ 1256, 7,0}, /* core3 sp_EL2 bit5 */
			{ 1280, 7,0}, /* core3 sp_EL2 bit6 */
			{ 1278, 7,0}, /* core3 sp_EL2 bit7 */
			{ 1303, 7,0}, /* core3 sp_EL2 bit8 */
			{ 1285, 7,0}, /* core3 sp_EL2 bit9 */
			{ 1313, 7,0}, /* core3 sp_EL2 bit10 */
			{ 1302, 7,0}, /* core3 sp_EL2 bit11 */
			{ 1310, 7,0}, /* core3 sp_EL2 bit12 */
			{ 1304, 7,0}, /* core3 sp_EL2 bit13 */
			{ 1275, 7,0}, /* core3 sp_EL2 bit14 */
			{ 1312, 7,0}, /* core3 sp_EL2 bit15 */
			{ 1311, 7,0}, /* core3 sp_EL2 bit16 */
			{ 1258, 7,0}, /* core3 sp_EL2 bit17 */
			{ 1250, 7,0}, /* core3 sp_EL2 bit18 */
			{ 1368, 7,0}, /* core3 sp_EL2 bit19 */
			{ 1369, 7,0}, /* core3 sp_EL2 bit20 */
			{ 1358, 7,0}, /* core3 sp_EL2 bit21 */
			{ 1361, 7,0}, /* core3 sp_EL2 bit22 */
			{ 1375, 7,0}, /* core3 sp_EL2 bit23 */
			{ 1374, 7,0}, /* core3 sp_EL2 bit24 */
			{ 1370, 7,0}, /* core3 sp_EL2 bit25 */
			{ 1372, 7,0}, /* core3 sp_EL2 bit26 */
			{ 1371, 7,0}, /* core3 sp_EL2 bit27 */
			{ 1376, 7,0}, /* core3 sp_EL2 bit28 */
			{ 1373, 7,0}, /* core3 sp_EL2 bit29 */
			{ 1367, 7,0}, /* core3 sp_EL2 bit30 */
			{ 1264, 7,0}, /* core3 sp_EL2 bit31 */
			{ 1042, 7,0}, /* core3 sp_EL2 bit32 */
			{ 1047, 7,0}, /* core3 sp_EL2 bit33 */
			{ 1043, 7,0}, /* core3 sp_EL2 bit34 */
			{ 1041, 7,0}, /* core3 sp_EL2 bit35 */
			{ 1046, 7,0}, /* core3 sp_EL2 bit36 */
			{ 1040, 7,0}, /* core3 sp_EL2 bit37 */
			{ 1088, 7,0}, /* core3 sp_EL2 bit38 */
			{ 1050, 7,0}, /* core3 sp_EL2 bit39 */
			{ 1090, 7,0}, /* core3 sp_EL2 bit40 */
			{ 1084, 7,0}, /* core3 sp_EL2 bit41 */
			{ 1087, 7,0}, /* core3 sp_EL2 bit42 */
			{ 1089, 7,0}, /* core3 sp_EL2 bit43 */
			{ 1091, 7,0}, /* core3 sp_EL2 bit44 */
			{ 1092, 7,0}, /* core3 sp_EL2 bit45 */
			{ 1081, 7,0}, /* core3 sp_EL2 bit46 */
			{ 3180, 7,0}, /* core3 sp_EL2 bit47 */
			{ 3190, 7,0}, /* core3 sp_EL2 bit48 */
			{ 3183, 7,0}, /* core3 sp_EL2 bit49 */
			{ 3194, 7,0}, /* core3 sp_EL2 bit50 */
			{ 3192, 7,0}, /* core3 sp_EL2 bit51 */
			{ 3195, 7,0}, /* core3 sp_EL2 bit52 */
			{ 3197, 7,0}, /* core3 sp_EL2 bit53 */
			{ 3182, 7,0}, /* core3 sp_EL2 bit54 */
			{ 3186, 7,0}, /* core3 sp_EL2 bit55 */
			{ 3193, 7,0}, /* core3 sp_EL2 bit56 */
			{ 3185, 7,0}, /* core3 sp_EL2 bit57 */
			{ 3189, 7,0}, /* core3 sp_EL2 bit58 */
			{ 3181, 7,0}, /* core3 sp_EL2 bit59 */
			{ 3196, 7,0}, /* core3 sp_EL2 bit60 */
			{ 3230, 7,0}, /* core3 sp_EL2 bit61 */
			{ 3191, 7,0}, /* core3 sp_EL2 bit62 */
			{ 1036, 7,0}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 1550, 7,0}, /* core3 sp_EL3 bit0 */
			{ 1270, 7,0}, /* core3 sp_EL3 bit1 */
			{ 1271, 7,0}, /* core3 sp_EL3 bit2 */
			{ 1551, 7,0}, /* core3 sp_EL3 bit3 */
			{ 1268, 7,0}, /* core3 sp_EL3 bit4 */
			{ 1267, 7,0}, /* core3 sp_EL3 bit5 */
			{ 1323, 7,0}, /* core3 sp_EL3 bit6 */
			{ 1322, 7,0}, /* core3 sp_EL3 bit7 */
			{ 1318, 7,0}, /* core3 sp_EL3 bit8 */
			{ 1319, 7,0}, /* core3 sp_EL3 bit9 */
			{ 1315, 7,0}, /* core3 sp_EL3 bit10 */
			{ 1004, 7,0}, /* core3 sp_EL3 bit11 */
			{ 1317, 7,0}, /* core3 sp_EL3 bit12 */
			{ 1316, 7,0}, /* core3 sp_EL3 bit13 */
			{ 1321, 7,0}, /* core3 sp_EL3 bit14 */
			{ 1320, 7,0}, /* core3 sp_EL3 bit15 */
			{ 1324, 7,0}, /* core3 sp_EL3 bit16 */
			{ 1552, 7,0}, /* core3 sp_EL3 bit17 */
			{ 1549, 7,0}, /* core3 sp_EL3 bit18 */
			{ 1579, 7,0}, /* core3 sp_EL3 bit19 */
			{ 1571, 7,0}, /* core3 sp_EL3 bit20 */
			{ 1575, 7,0}, /* core3 sp_EL3 bit21 */
			{ 1580, 7,0}, /* core3 sp_EL3 bit22 */
			{ 1570, 7,0}, /* core3 sp_EL3 bit23 */
			{ 1574, 7,0}, /* core3 sp_EL3 bit24 */
			{ 1578, 7,0}, /* core3 sp_EL3 bit25 */
			{ 1573, 7,0}, /* core3 sp_EL3 bit26 */
			{ 1569, 7,0}, /* core3 sp_EL3 bit27 */
			{ 1577, 7,0}, /* core3 sp_EL3 bit28 */
			{ 1572, 7,0}, /* core3 sp_EL3 bit29 */
			{ 1576, 7,0}, /* core3 sp_EL3 bit30 */
			{ 1269, 7,0}, /* core3 sp_EL3 bit31 */
			{ 1054, 7,0}, /* core3 sp_EL3 bit32 */
			{ 1051, 7,0}, /* core3 sp_EL3 bit33 */
			{ 1052, 7,0}, /* core3 sp_EL3 bit34 */
			{ 1062, 7,0}, /* core3 sp_EL3 bit35 */
			{ 1071, 7,0}, /* core3 sp_EL3 bit36 */
			{ 1063, 7,0}, /* core3 sp_EL3 bit37 */
			{ 1056, 7,0}, /* core3 sp_EL3 bit38 */
			{ 1064, 7,0}, /* core3 sp_EL3 bit39 */
			{ 1085, 7,0}, /* core3 sp_EL3 bit40 */
			{ 1083, 7,0}, /* core3 sp_EL3 bit41 */
			{ 1072, 7,0}, /* core3 sp_EL3 bit42 */
			{ 1080, 7,0}, /* core3 sp_EL3 bit43 */
			{ 1086, 7,0}, /* core3 sp_EL3 bit44 */
			{ 1079, 7,0}, /* core3 sp_EL3 bit45 */
			{ 1082, 7,0}, /* core3 sp_EL3 bit46 */
			{ 3318, 7,0}, /* core3 sp_EL3 bit47 */
			{ 3176, 7,0}, /* core3 sp_EL3 bit48 */
			{ 3320, 7,0}, /* core3 sp_EL3 bit49 */
			{ 3325, 7,0}, /* core3 sp_EL3 bit50 */
			{ 3321, 7,0}, /* core3 sp_EL3 bit51 */
			{ 3317, 7,0}, /* core3 sp_EL3 bit52 */
			{ 3358, 7,0}, /* core3 sp_EL3 bit53 */
			{ 3319, 7,0}, /* core3 sp_EL3 bit54 */
			{ 3313, 7,0}, /* core3 sp_EL3 bit55 */
			{ 3324, 7,0}, /* core3 sp_EL3 bit56 */
			{ 3314, 7,0}, /* core3 sp_EL3 bit57 */
			{ 3356, 7,0}, /* core3 sp_EL3 bit58 */
			{ 3357, 7,0}, /* core3 sp_EL3 bit59 */
			{ 3315, 7,0}, /* core3 sp_EL3 bit60 */
			{ 3316, 7,0}, /* core3 sp_EL3 bit61 */
			{ 3322, 7,0}, /* core3 sp_EL3 bit62 */
			{ 1053, 7,0}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{   54, 7,0}, /* core3 elr_EL1 bit0 */
			{   55, 7,0}, /* core3 elr_EL1 bit1 */
			{ 1001, 7,0}, /* core3 elr_EL1 bit2 */
			{ 1000, 7,0}, /* core3 elr_EL1 bit3 */
			{ 1263, 7,0}, /* core3 elr_EL1 bit4 */
			{ 1286, 7,0}, /* core3 elr_EL1 bit5 */
			{ 1287, 7,0}, /* core3 elr_EL1 bit6 */
			{ 1276, 7,0}, /* core3 elr_EL1 bit7 */
			{ 1301, 7,0}, /* core3 elr_EL1 bit8 */
			{ 1289, 7,0}, /* core3 elr_EL1 bit9 */
			{ 1002, 7,0}, /* core3 elr_EL1 bit10 */
			{ 1290, 7,0}, /* core3 elr_EL1 bit11 */
			{ 1291, 7,0}, /* core3 elr_EL1 bit12 */
			{  999, 7,0}, /* core3 elr_EL1 bit13 */
			{ 1314, 7,0}, /* core3 elr_EL1 bit14 */
			{ 1003, 7,0}, /* core3 elr_EL1 bit15 */
			{ 1288, 7,0}, /* core3 elr_EL1 bit16 */
			{ 1274, 7,0}, /* core3 elr_EL1 bit17 */
			{ 1331, 7,0}, /* core3 elr_EL1 bit18 */
			{ 1346, 7,0}, /* core3 elr_EL1 bit19 */
			{ 1339, 7,0}, /* core3 elr_EL1 bit20 */
			{ 1343, 7,0}, /* core3 elr_EL1 bit21 */
			{ 1348, 7,0}, /* core3 elr_EL1 bit22 */
			{ 1352, 7,0}, /* core3 elr_EL1 bit23 */
			{ 1341, 7,0}, /* core3 elr_EL1 bit24 */
			{ 1342, 7,0}, /* core3 elr_EL1 bit25 */
			{ 1248, 7,0}, /* core3 elr_EL1 bit26 */
			{ 1340, 7,0}, /* core3 elr_EL1 bit27 */
			{ 1351, 7,0}, /* core3 elr_EL1 bit28 */
			{ 1334, 7,0}, /* core3 elr_EL1 bit29 */
			{ 1337, 7,0}, /* core3 elr_EL1 bit30 */
			{ 1266, 7,0}, /* core3 elr_EL1 bit31 */
			{ 1749, 7,0}, /* core3 elr_EL1 bit32 */
			{ 1750, 7,0}, /* core3 elr_EL1 bit33 */
			{ 1757, 7,0}, /* core3 elr_EL1 bit34 */
			{ 1752, 7,0}, /* core3 elr_EL1 bit35 */
			{ 1744, 7,0}, /* core3 elr_EL1 bit36 */
			{ 1748, 7,0}, /* core3 elr_EL1 bit37 */
			{ 1767, 7,0}, /* core3 elr_EL1 bit38 */
			{ 1751, 7,0}, /* core3 elr_EL1 bit39 */
			{ 1795, 7,0}, /* core3 elr_EL1 bit40 */
			{ 1746, 7,0}, /* core3 elr_EL1 bit41 */
			{ 1745, 7,0}, /* core3 elr_EL1 bit42 */
			{ 1769, 7,0}, /* core3 elr_EL1 bit43 */
			{ 1796, 7,0}, /* core3 elr_EL1 bit44 */
			{ 1797, 7,0}, /* core3 elr_EL1 bit45 */
			{ 1768, 7,0}, /* core3 elr_EL1 bit46 */
			{ 7297, 6,0}, /* core3 elr_EL1 bit47 */
			{ 7284, 6,0}, /* core3 elr_EL1 bit48 */
			{ 7285, 6,0}, /* core3 elr_EL1 bit49 */
			{ 7283, 6,0}, /* core3 elr_EL1 bit50 */
			{ 7290, 6,0}, /* core3 elr_EL1 bit51 */
			{ 7292, 6,0}, /* core3 elr_EL1 bit52 */
			{ 7296, 6,0}, /* core3 elr_EL1 bit53 */
			{ 7293, 6,0}, /* core3 elr_EL1 bit54 */
			{ 7286, 6,0}, /* core3 elr_EL1 bit55 */
			{ 7979, 6,0}, /* core3 elr_EL1 bit56 */
			{ 7288, 6,0}, /* core3 elr_EL1 bit57 */
			{ 7294, 6,0}, /* core3 elr_EL1 bit58 */
			{ 7287, 6,0}, /* core3 elr_EL1 bit59 */
			{ 7289, 6,0}, /* core3 elr_EL1 bit60 */
			{ 7291, 6,0}, /* core3 elr_EL1 bit61 */
			{ 7295, 6,0}, /* core3 elr_EL1 bit62 */
			{ 1759, 7,0}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{  275, 6,0}, /* core3 elr_EL2 bit0 */
			{  393, 6,0}, /* core3 elr_EL2 bit1 */
			{  276, 6,0}, /* core3 elr_EL2 bit2 */
			{  360, 6,0}, /* core3 elr_EL2 bit3 */
			{  292, 6,0}, /* core3 elr_EL2 bit4 */
			{  281, 6,0}, /* core3 elr_EL2 bit5 */
			{  280, 6,0}, /* core3 elr_EL2 bit6 */
			{  282, 6,0}, /* core3 elr_EL2 bit7 */
			{  398, 6,0}, /* core3 elr_EL2 bit8 */
			{  397, 6,0}, /* core3 elr_EL2 bit9 */
			{  396, 6,0}, /* core3 elr_EL2 bit10 */
			{  399, 6,0}, /* core3 elr_EL2 bit11 */
			{  400, 6,0}, /* core3 elr_EL2 bit12 */
			{  401, 6,0}, /* core3 elr_EL2 bit13 */
			{  285, 6,0}, /* core3 elr_EL2 bit14 */
			{  395, 6,0}, /* core3 elr_EL2 bit15 */
			{  394, 6,0}, /* core3 elr_EL2 bit16 */
			{  283, 6,0}, /* core3 elr_EL2 bit17 */
			{  284, 6,0}, /* core3 elr_EL2 bit18 */
			{  381, 6,0}, /* core3 elr_EL2 bit19 */
			{  382, 6,0}, /* core3 elr_EL2 bit20 */
			{  377, 6,0}, /* core3 elr_EL2 bit21 */
			{  371, 6,0}, /* core3 elr_EL2 bit22 */
			{  379, 6,0}, /* core3 elr_EL2 bit23 */
			{  372, 6,0}, /* core3 elr_EL2 bit24 */
			{  374, 6,0}, /* core3 elr_EL2 bit25 */
			{  378, 6,0}, /* core3 elr_EL2 bit26 */
			{  375, 6,0}, /* core3 elr_EL2 bit27 */
			{  376, 6,0}, /* core3 elr_EL2 bit28 */
			{  373, 6,0}, /* core3 elr_EL2 bit29 */
			{  380, 6,0}, /* core3 elr_EL2 bit30 */
			{  291, 6,0}, /* core3 elr_EL2 bit31 */
			{ 1039, 7,0}, /* core3 elr_EL2 bit32 */
			{ 1044, 7,0}, /* core3 elr_EL2 bit33 */
			{ 1038, 7,0}, /* core3 elr_EL2 bit34 */
			{ 1037, 7,0}, /* core3 elr_EL2 bit35 */
			{ 1662, 7,0}, /* core3 elr_EL2 bit36 */
			{ 1045, 7,0}, /* core3 elr_EL2 bit37 */
			{ 1074, 7,0}, /* core3 elr_EL2 bit38 */
			{ 1061, 7,0}, /* core3 elr_EL2 bit39 */
			{ 1076, 7,0}, /* core3 elr_EL2 bit40 */
			{ 1069, 7,0}, /* core3 elr_EL2 bit41 */
			{ 1075, 7,0}, /* core3 elr_EL2 bit42 */
			{ 1070, 7,0}, /* core3 elr_EL2 bit43 */
			{ 1077, 7,0}, /* core3 elr_EL2 bit44 */
			{ 1078, 7,0}, /* core3 elr_EL2 bit45 */
			{ 1073, 7,0}, /* core3 elr_EL2 bit46 */
			{ 3348, 7,0}, /* core3 elr_EL2 bit47 */
			{ 3328, 7,0}, /* core3 elr_EL2 bit48 */
			{ 3334, 7,0}, /* core3 elr_EL2 bit49 */
			{ 3336, 7,0}, /* core3 elr_EL2 bit50 */
			{ 3352, 7,0}, /* core3 elr_EL2 bit51 */
			{ 3168, 7,0}, /* core3 elr_EL2 bit52 */
			{ 3172, 7,0}, /* core3 elr_EL2 bit53 */
			{ 3331, 7,0}, /* core3 elr_EL2 bit54 */
			{ 3335, 7,0}, /* core3 elr_EL2 bit55 */
			{ 3326, 7,0}, /* core3 elr_EL2 bit56 */
			{ 3329, 7,0}, /* core3 elr_EL2 bit57 */
			{ 3355, 7,0}, /* core3 elr_EL2 bit58 */
			{ 3327, 7,0}, /* core3 elr_EL2 bit59 */
			{ 3330, 7,0}, /* core3 elr_EL2 bit60 */
			{ 3332, 7,0}, /* core3 elr_EL2 bit61 */
			{ 3333, 7,0}, /* core3 elr_EL2 bit62 */
			{ 1055, 7,0}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 2940, 7,0}, /* core3 elr_EL3 bit0 */
			{ 2887, 7,0}, /* core3 elr_EL3 bit1 */
			{ 2886, 7,0}, /* core3 elr_EL3 bit2 */
			{ 2892, 7,0}, /* core3 elr_EL3 bit3 */
			{ 2880, 7,0}, /* core3 elr_EL3 bit4 */
			{ 2878, 7,0}, /* core3 elr_EL3 bit5 */
			{ 2944, 7,0}, /* core3 elr_EL3 bit6 */
			{ 2885, 7,0}, /* core3 elr_EL3 bit7 */
			{ 2900, 7,0}, /* core3 elr_EL3 bit8 */
			{ 2899, 7,0}, /* core3 elr_EL3 bit9 */
			{ 2897, 7,0}, /* core3 elr_EL3 bit10 */
			{ 2938, 7,0}, /* core3 elr_EL3 bit11 */
			{ 2896, 7,0}, /* core3 elr_EL3 bit12 */
			{ 2942, 7,0}, /* core3 elr_EL3 bit13 */
			{ 2895, 7,0}, /* core3 elr_EL3 bit14 */
			{ 2937, 7,0}, /* core3 elr_EL3 bit15 */
			{ 2939, 7,0}, /* core3 elr_EL3 bit16 */
			{ 2881, 7,0}, /* core3 elr_EL3 bit17 */
			{ 2945, 7,0}, /* core3 elr_EL3 bit18 */
			{ 2955, 7,0}, /* core3 elr_EL3 bit19 */
			{ 2962, 7,0}, /* core3 elr_EL3 bit20 */
			{ 2957, 7,0}, /* core3 elr_EL3 bit21 */
			{ 2970, 7,0}, /* core3 elr_EL3 bit22 */
			{ 2963, 7,0}, /* core3 elr_EL3 bit23 */
			{ 2971, 7,0}, /* core3 elr_EL3 bit24 */
			{ 2956, 7,0}, /* core3 elr_EL3 bit25 */
			{ 2961, 7,0}, /* core3 elr_EL3 bit26 */
			{ 2960, 7,0}, /* core3 elr_EL3 bit27 */
			{ 2958, 7,0}, /* core3 elr_EL3 bit28 */
			{ 2959, 7,0}, /* core3 elr_EL3 bit29 */
			{ 2954, 7,0}, /* core3 elr_EL3 bit30 */
			{ 2879, 7,0}, /* core3 elr_EL3 bit31 */
			{ 1048, 7,0}, /* core3 elr_EL3 bit32 */
			{ 1049, 7,0}, /* core3 elr_EL3 bit33 */
			{ 2069, 7,0}, /* core3 elr_EL3 bit34 */
			{ 2061, 7,0}, /* core3 elr_EL3 bit35 */
			{ 1772, 7,0}, /* core3 elr_EL3 bit36 */
			{ 2063, 7,0}, /* core3 elr_EL3 bit37 */
			{ 1774, 7,0}, /* core3 elr_EL3 bit38 */
			{ 2064, 7,0}, /* core3 elr_EL3 bit39 */
			{ 1773, 7,0}, /* core3 elr_EL3 bit40 */
			{ 1788, 7,0}, /* core3 elr_EL3 bit41 */
			{ 1785, 7,0}, /* core3 elr_EL3 bit42 */
			{ 1786, 7,0}, /* core3 elr_EL3 bit43 */
			{ 1787, 7,0}, /* core3 elr_EL3 bit44 */
			{ 1789, 7,0}, /* core3 elr_EL3 bit45 */
			{ 1778, 7,0}, /* core3 elr_EL3 bit46 */
			{ 3220, 7,0}, /* core3 elr_EL3 bit47 */
			{ 7965, 7,0}, /* core3 elr_EL3 bit48 */
			{ 7960, 7,0}, /* core3 elr_EL3 bit49 */
			{ 3223, 7,0}, /* core3 elr_EL3 bit50 */
			{ 7972, 7,0}, /* core3 elr_EL3 bit51 */
			{ 7973, 7,0}, /* core3 elr_EL3 bit52 */
			{ 3221, 7,0}, /* core3 elr_EL3 bit53 */
			{ 3226, 7,0}, /* core3 elr_EL3 bit54 */
			{ 7958, 7,0}, /* core3 elr_EL3 bit55 */
			{ 7966, 7,0}, /* core3 elr_EL3 bit56 */
			{ 7959, 7,0}, /* core3 elr_EL3 bit57 */
			{ 7963, 7,0}, /* core3 elr_EL3 bit58 */
			{ 7961, 7,0}, /* core3 elr_EL3 bit59 */
			{ 7962, 7,0}, /* core3 elr_EL3 bit60 */
			{ 3224, 7,0}, /* core3 elr_EL3 bit61 */
			{ 3225, 7,0}, /* core3 elr_EL3 bit62 */
			{ 1779, 7,0}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 7402, 6,0}, /* core3 raw_pc bit0 */
			{ 5743, 7,0}, /* core3 raw_pc bit1 */
			{ 5742, 7,0}, /* core3 raw_pc bit2 */
			{ 7399, 6,0}, /* core3 raw_pc bit3 */
			{ 7401, 6,0}, /* core3 raw_pc bit4 */
			{ 7400, 6,0}, /* core3 raw_pc bit5 */
			{ 7404, 6,0}, /* core3 raw_pc bit6 */
			{ 9616, 6,0}, /* core3 raw_pc bit7 */
			{ 9615, 6,0}, /* core3 raw_pc bit8 */
			{ 9614, 6,0}, /* core3 raw_pc bit9 */
			{ 9613, 6,0}, /* core3 raw_pc bit10 */
			{ 9620, 6,0}, /* core3 raw_pc bit11 */
			{ 9619, 6,0}, /* core3 raw_pc bit12 */
			{ 9618, 6,0}, /* core3 raw_pc bit13 */
			{ 9617, 6,0}, /* core3 raw_pc bit14 */
			{ 9624, 6,0}, /* core3 raw_pc bit15 */
			{ 9623, 6,0}, /* core3 raw_pc bit16 */
			{ 9622, 6,0}, /* core3 raw_pc bit17 */
			{ 9621, 6,0}, /* core3 raw_pc bit18 */
			{10437, 6,0}, /* core3 raw_pc bit19 */
			{10436, 6,0}, /* core3 raw_pc bit20 */
			{10435, 6,0}, /* core3 raw_pc bit21 */
			{10434, 6,0}, /* core3 raw_pc bit22 */
			{10441, 6,0}, /* core3 raw_pc bit23 */
			{10440, 6,0}, /* core3 raw_pc bit24 */
			{10439, 6,0}, /* core3 raw_pc bit25 */
			{10438, 6,0}, /* core3 raw_pc bit26 */
			{10445, 6,0}, /* core3 raw_pc bit27 */
			{10444, 6,0}, /* core3 raw_pc bit28 */
			{10443, 6,0}, /* core3 raw_pc bit29 */
			{10442, 6,0}, /* core3 raw_pc bit30 */
			{ 9347, 6,0}, /* core3 raw_pc bit31 */
			{ 9346, 6,0}, /* core3 raw_pc bit32 */
			{ 9345, 6,0}, /* core3 raw_pc bit33 */
			{ 9344, 6,0}, /* core3 raw_pc bit34 */
			{ 9351, 6,0}, /* core3 raw_pc bit35 */
			{ 9350, 6,0}, /* core3 raw_pc bit36 */
			{ 9349, 6,0}, /* core3 raw_pc bit37 */
			{ 5234, 7,0}, /* core3 raw_pc bit38 */
			{ 9646, 6,0}, /* core3 raw_pc bit39 */
			{ 9645, 6,0}, /* core3 raw_pc bit40 */
			{ 9348, 6,0}, /* core3 raw_pc bit41 */
			{ 9648, 6,0}, /* core3 raw_pc bit42 */
			{ 9647, 6,0}, /* core3 raw_pc bit43 */
			{ 9644, 6,0}, /* core3 raw_pc bit44 */
			{ 9643, 6,0}, /* core3 raw_pc bit45 */
			{ 5232, 7,0}, /* core3 raw_pc bit46 */
			{ 5233, 7,0}, /* core3 raw_pc bit47 */
			{    0, 0,2}, /* core3 raw_pc bit48 */
			{    0, 0,2}, /* core3 raw_pc bit49 */
			{    0, 0,2}, /* core3 raw_pc bit50 */
			{    0, 0,2}, /* core3 raw_pc bit51 */
			{    0, 0,2}, /* core3 raw_pc bit52 */
			{    0, 0,2}, /* core3 raw_pc bit53 */
			{    0, 0,2}, /* core3 raw_pc bit54 */
			{    0, 0,2}, /* core3 raw_pc bit55 */
			{    0, 0,2}, /* core3 raw_pc bit56 */
			{    0, 0,2}, /* core3 raw_pc bit57 */
			{    0, 0,2}, /* core3 raw_pc bit58 */
			{    0, 0,2}, /* core3 raw_pc bit59 */
			{    0, 0,2}, /* core3 raw_pc bit60 */
			{    0, 0,2}, /* core3 raw_pc bit61 */
			{    0, 0,2}, /* core3 raw_pc bit62 */
			{    0, 0,2}, /* core3 raw_pc bit63 */
			}},
			.pc_iss = {{
			{ 9507, 6,0}, /* core3 pc_iss bit0 */
			{ 9506, 6,0}, /* core3 pc_iss bit1 */
			{ 9505, 6,0}, /* core3 pc_iss bit2 */
			{ 9513, 6,0}, /* core3 pc_iss bit3 */
			{ 9512, 6,0}, /* core3 pc_iss bit4 */
			{ 9503, 6,0}, /* core3 pc_iss bit5 */
			{ 9502, 6,0}, /* core3 pc_iss bit6 */
			{ 9504, 6,0}, /* core3 pc_iss bit7 */
			{ 9626, 6,0}, /* core3 pc_iss bit8 */
			{ 9625, 6,0}, /* core3 pc_iss bit9 */
			{ 9509, 6,0}, /* core3 pc_iss bit10 */
			{ 9634, 6,0}, /* core3 pc_iss bit11 */
			{ 9633, 6,0}, /* core3 pc_iss bit12 */
			{ 9331, 6,0}, /* core3 pc_iss bit13 */
			{ 5360, 7,0}, /* core3 pc_iss bit14 */
			{ 9630, 6,0}, /* core3 pc_iss bit15 */
			{ 9629, 6,0}, /* core3 pc_iss bit16 */
			{ 9511, 6,0}, /* core3 pc_iss bit17 */
			{ 9510, 6,0}, /* core3 pc_iss bit18 */
			{ 9628, 6,0}, /* core3 pc_iss bit19 */
			{ 9508, 6,0}, /* core3 pc_iss bit20 */
			{ 9627, 6,0}, /* core3 pc_iss bit21 */
			{ 9632, 6,0}, /* core3 pc_iss bit22 */
			{ 9330, 6,0}, /* core3 pc_iss bit23 */
			{ 5363, 7,0}, /* core3 pc_iss bit24 */
			{ 9329, 6,0}, /* core3 pc_iss bit25 */
			{ 9328, 6,0}, /* core3 pc_iss bit26 */
			{ 9631, 6,0}, /* core3 pc_iss bit27 */
			{ 5361, 7,0}, /* core3 pc_iss bit28 */
			{ 9636, 6,0}, /* core3 pc_iss bit29 */
			{ 9635, 6,0}, /* core3 pc_iss bit30 */
			{ 5362, 7,0}, /* core3 pc_iss bit31 */
			{ 9656, 6,0}, /* core3 pc_iss bit32 */
			{ 9391, 6,0}, /* core3 pc_iss bit33 */
			{ 9655, 6,0}, /* core3 pc_iss bit34 */
			{ 9654, 6,0}, /* core3 pc_iss bit35 */
			{ 9653, 6,0}, /* core3 pc_iss bit36 */
			{ 9390, 6,0}, /* core3 pc_iss bit37 */
			{ 9389, 6,0}, /* core3 pc_iss bit38 */
			{ 5248, 7,0}, /* core3 pc_iss bit39 */
			{ 9652, 6,0}, /* core3 pc_iss bit40 */
			{ 9388, 6,0}, /* core3 pc_iss bit41 */
			{ 5250, 7,0}, /* core3 pc_iss bit42 */
			{ 9387, 6,0}, /* core3 pc_iss bit43 */
			{ 9651, 6,0}, /* core3 pc_iss bit44 */
			{ 9650, 6,0}, /* core3 pc_iss bit45 */
			{ 5246, 7,0}, /* core3 pc_iss bit46 */
			{ 9649, 6,0}, /* core3 pc_iss bit47 */
			{ 5249, 7,0}, /* core3 pc_iss bit48 */
			{ 9386, 6,0}, /* core3 pc_iss bit49 */
			{ 5245, 7,0}, /* core3 pc_iss bit50 */
			{ 5247, 7,0}, /* core3 pc_iss bit51 */
			{ 5243, 7,0}, /* core3 pc_iss bit52 */
			{ 5235, 7,0}, /* core3 pc_iss bit53 */
			{ 5244, 7,0}, /* core3 pc_iss bit54 */
			{ 9385, 6,0}, /* core3 pc_iss bit55 */
			{ 5241, 7,0}, /* core3 pc_iss bit56 */
			{ 5242, 7,0}, /* core3 pc_iss bit57 */
			{ 5236, 7,0}, /* core3 pc_iss bit58 */
			{ 9384, 6,0}, /* core3 pc_iss bit59 */
			{ 5237, 7,0}, /* core3 pc_iss bit60 */
			{ 5238, 7,0}, /* core3 pc_iss bit61 */
			{ 5239, 7,0}, /* core3 pc_iss bit62 */
			{ 5240, 7,0}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 7403, 6,0}, /* core3 full_pc_wr bit0 */
			{    0, 0,2}, /* core3 full_pc_wr bit1 */
			{    0, 0,2}, /* core3 full_pc_wr bit2 */
			{    0, 0,2}, /* core3 full_pc_wr bit3 */
			{    0, 0,2}, /* core3 full_pc_wr bit4 */
			{    0, 0,2}, /* core3 full_pc_wr bit5 */
			{    0, 0,2}, /* core3 full_pc_wr bit6 */
			{    0, 0,2}, /* core3 full_pc_wr bit7 */
			{    0, 0,2}, /* core3 full_pc_wr bit8 */
			{    0, 0,2}, /* core3 full_pc_wr bit9 */
			{    0, 0,2}, /* core3 full_pc_wr bit10 */
			{    0, 0,2}, /* core3 full_pc_wr bit11 */
			{    0, 0,2}, /* core3 full_pc_wr bit12 */
			{    0, 0,2}, /* core3 full_pc_wr bit13 */
			{    0, 0,2}, /* core3 full_pc_wr bit14 */
			{    0, 0,2}, /* core3 full_pc_wr bit15 */
			{    0, 0,2}, /* core3 full_pc_wr bit16 */
			{    0, 0,2}, /* core3 full_pc_wr bit17 */
			{    0, 0,2}, /* core3 full_pc_wr bit18 */
			{    0, 0,2}, /* core3 full_pc_wr bit19 */
			{    0, 0,2}, /* core3 full_pc_wr bit20 */
			{    0, 0,2}, /* core3 full_pc_wr bit21 */
			{    0, 0,2}, /* core3 full_pc_wr bit22 */
			{    0, 0,2}, /* core3 full_pc_wr bit23 */
			{    0, 0,2}, /* core3 full_pc_wr bit24 */
			{    0, 0,2}, /* core3 full_pc_wr bit25 */
			{    0, 0,2}, /* core3 full_pc_wr bit26 */
			{    0, 0,2}, /* core3 full_pc_wr bit27 */
			{    0, 0,2}, /* core3 full_pc_wr bit28 */
			{    0, 0,2}, /* core3 full_pc_wr bit29 */
			{    0, 0,2}, /* core3 full_pc_wr bit30 */
			{    0, 0,2}, /* core3 full_pc_wr bit31 */
			{    0, 0,2}, /* core3 full_pc_wr bit32 */
			{    0, 0,2}, /* core3 full_pc_wr bit33 */
			{    0, 0,2}, /* core3 full_pc_wr bit34 */
			{    0, 0,2}, /* core3 full_pc_wr bit35 */
			{    0, 0,2}, /* core3 full_pc_wr bit36 */
			{    0, 0,2}, /* core3 full_pc_wr bit37 */
			{    0, 0,2}, /* core3 full_pc_wr bit38 */
			{    0, 0,2}, /* core3 full_pc_wr bit39 */
			{    0, 0,2}, /* core3 full_pc_wr bit40 */
			{    0, 0,2}, /* core3 full_pc_wr bit41 */
			{    0, 0,2}, /* core3 full_pc_wr bit42 */
			{    0, 0,2}, /* core3 full_pc_wr bit43 */
			{    0, 0,2}, /* core3 full_pc_wr bit44 */
			{    0, 0,2}, /* core3 full_pc_wr bit45 */
			{    0, 0,2}, /* core3 full_pc_wr bit46 */
			{    0, 0,2}, /* core3 full_pc_wr bit47 */
			{    0, 0,2}, /* core3 full_pc_wr bit48 */
			{    0, 0,2}, /* core3 full_pc_wr bit49 */
			{    0, 0,2}, /* core3 full_pc_wr bit50 */
			{    0, 0,2}, /* core3 full_pc_wr bit51 */
			{    0, 0,2}, /* core3 full_pc_wr bit52 */
			{    0, 0,2}, /* core3 full_pc_wr bit53 */
			{    0, 0,2}, /* core3 full_pc_wr bit54 */
			{    0, 0,2}, /* core3 full_pc_wr bit55 */
			{    0, 0,2}, /* core3 full_pc_wr bit56 */
			{    0, 0,2}, /* core3 full_pc_wr bit57 */
			{    0, 0,2}, /* core3 full_pc_wr bit58 */
			{    0, 0,2}, /* core3 full_pc_wr bit59 */
			{    0, 0,2}, /* core3 full_pc_wr bit60 */
			{    0, 0,2}, /* core3 full_pc_wr bit61 */
			{    0, 0,2}, /* core3 full_pc_wr bit62 */
			{    0, 0,2}, /* core3 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{ 5400, 7,0}, /* core3 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{ 7406, 6,0}, /* core3 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{16329, 7,0}, /* core3 return_Stack_pointer bit0 */
			{14948, 7,0}, /* core3 return_Stack_pointer bit1 */
			{16328, 7,0}, /* core3 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{16729, 7,0}, /* core3 return_Stack0 bit0 */
			{16728, 7,0}, /* core3 return_Stack0 bit1 */
			{16727, 7,0}, /* core3 return_Stack0 bit2 */
			{16726, 7,0}, /* core3 return_Stack0 bit3 */
			{16721, 7,0}, /* core3 return_Stack0 bit4 */
			{16720, 7,0}, /* core3 return_Stack0 bit5 */
			{16719, 7,0}, /* core3 return_Stack0 bit6 */
			{16718, 7,0}, /* core3 return_Stack0 bit7 */
			{12983, 7,0}, /* core3 return_Stack0 bit8 */
			{12982, 7,0}, /* core3 return_Stack0 bit9 */
			{12981, 7,0}, /* core3 return_Stack0 bit10 */
			{12980, 7,0}, /* core3 return_Stack0 bit11 */
			{16789, 7,0}, /* core3 return_Stack0 bit12 */
			{16788, 7,0}, /* core3 return_Stack0 bit13 */
			{16787, 7,0}, /* core3 return_Stack0 bit14 */
			{16786, 7,0}, /* core3 return_Stack0 bit15 */
			{16725, 7,0}, /* core3 return_Stack0 bit16 */
			{16724, 7,0}, /* core3 return_Stack0 bit17 */
			{16723, 7,0}, /* core3 return_Stack0 bit18 */
			{16722, 7,0}, /* core3 return_Stack0 bit19 */
			{13019, 7,0}, /* core3 return_Stack0 bit20 */
			{13018, 7,0}, /* core3 return_Stack0 bit21 */
			{13017, 7,0}, /* core3 return_Stack0 bit22 */
			{13016, 7,0}, /* core3 return_Stack0 bit23 */
			{13092, 7,0}, /* core3 return_Stack0 bit24 */
			{13091, 7,0}, /* core3 return_Stack0 bit25 */
			{13090, 7,0}, /* core3 return_Stack0 bit26 */
			{13089, 7,0}, /* core3 return_Stack0 bit27 */
			{13040, 7,0}, /* core3 return_Stack0 bit28 */
			{13039, 7,0}, /* core3 return_Stack0 bit29 */
			{13038, 7,0}, /* core3 return_Stack0 bit30 */
			{13037, 7,0}, /* core3 return_Stack0 bit31 */
			{13052, 7,0}, /* core3 return_Stack0 bit32 */
			{13051, 7,0}, /* core3 return_Stack0 bit33 */
			{13050, 7,0}, /* core3 return_Stack0 bit34 */
			{13049, 7,0}, /* core3 return_Stack0 bit35 */
			{13072, 7,0}, /* core3 return_Stack0 bit36 */
			{13071, 7,0}, /* core3 return_Stack0 bit37 */
			{13070, 7,0}, /* core3 return_Stack0 bit38 */
			{13069, 7,0}, /* core3 return_Stack0 bit39 */
			{13064, 7,0}, /* core3 return_Stack0 bit40 */
			{13063, 7,0}, /* core3 return_Stack0 bit41 */
			{13062, 7,0}, /* core3 return_Stack0 bit42 */
			{13061, 7,0}, /* core3 return_Stack0 bit43 */
			{13068, 7,0}, /* core3 return_Stack0 bit44 */
			{13067, 7,0}, /* core3 return_Stack0 bit45 */
			{13066, 7,0}, /* core3 return_Stack0 bit46 */
			{13065, 7,0}, /* core3 return_Stack0 bit47 */
			{13036, 7,0}, /* core3 return_Stack0 bit48 */
			{    0, 0,2}, /* core3 return_Stack0 bit49 */
			{    0, 0,2}, /* core3 return_Stack0 bit50 */
			{    0, 0,2}, /* core3 return_Stack0 bit51 */
			{    0, 0,2}, /* core3 return_Stack0 bit52 */
			{    0, 0,2}, /* core3 return_Stack0 bit53 */
			{    0, 0,2}, /* core3 return_Stack0 bit54 */
			{    0, 0,2}, /* core3 return_Stack0 bit55 */
			{    0, 0,2}, /* core3 return_Stack0 bit56 */
			{    0, 0,2}, /* core3 return_Stack0 bit57 */
			{    0, 0,2}, /* core3 return_Stack0 bit58 */
			{    0, 0,2}, /* core3 return_Stack0 bit59 */
			{    0, 0,2}, /* core3 return_Stack0 bit60 */
			{    0, 0,2}, /* core3 return_Stack0 bit61 */
			{    0, 0,2}, /* core3 return_Stack0 bit62 */
			{    0, 0,2}, /* core3 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{16705, 7,0}, /* core3 return_Stack1 bit0 */
			{16704, 7,0}, /* core3 return_Stack1 bit1 */
			{16703, 7,0}, /* core3 return_Stack1 bit2 */
			{16702, 7,0}, /* core3 return_Stack1 bit3 */
			{16701, 7,0}, /* core3 return_Stack1 bit4 */
			{16700, 7,0}, /* core3 return_Stack1 bit5 */
			{16699, 7,0}, /* core3 return_Stack1 bit6 */
			{16698, 7,0}, /* core3 return_Stack1 bit7 */
			{12995, 7,0}, /* core3 return_Stack1 bit8 */
			{12994, 7,0}, /* core3 return_Stack1 bit9 */
			{12993, 7,0}, /* core3 return_Stack1 bit10 */
			{12992, 7,0}, /* core3 return_Stack1 bit11 */
			{16761, 7,0}, /* core3 return_Stack1 bit12 */
			{16760, 7,0}, /* core3 return_Stack1 bit13 */
			{16759, 7,0}, /* core3 return_Stack1 bit14 */
			{16758, 7,0}, /* core3 return_Stack1 bit15 */
			{16753, 7,0}, /* core3 return_Stack1 bit16 */
			{16752, 7,0}, /* core3 return_Stack1 bit17 */
			{16751, 7,0}, /* core3 return_Stack1 bit18 */
			{16750, 7,0}, /* core3 return_Stack1 bit19 */
			{16765, 7,0}, /* core3 return_Stack1 bit20 */
			{16764, 7,0}, /* core3 return_Stack1 bit21 */
			{16763, 7,0}, /* core3 return_Stack1 bit22 */
			{16762, 7,0}, /* core3 return_Stack1 bit23 */
			{16773, 7,0}, /* core3 return_Stack1 bit24 */
			{16772, 7,0}, /* core3 return_Stack1 bit25 */
			{16771, 7,0}, /* core3 return_Stack1 bit26 */
			{16770, 7,0}, /* core3 return_Stack1 bit27 */
			{16777, 7,0}, /* core3 return_Stack1 bit28 */
			{16776, 7,0}, /* core3 return_Stack1 bit29 */
			{16775, 7,0}, /* core3 return_Stack1 bit30 */
			{16774, 7,0}, /* core3 return_Stack1 bit31 */
			{12963, 7,0}, /* core3 return_Stack1 bit32 */
			{12962, 7,0}, /* core3 return_Stack1 bit33 */
			{12961, 7,0}, /* core3 return_Stack1 bit34 */
			{12960, 7,0}, /* core3 return_Stack1 bit35 */
			{12929, 7,0}, /* core3 return_Stack1 bit36 */
			{12928, 7,0}, /* core3 return_Stack1 bit37 */
			{12927, 7,0}, /* core3 return_Stack1 bit38 */
			{12926, 7,0}, /* core3 return_Stack1 bit39 */
			{12941, 7,0}, /* core3 return_Stack1 bit40 */
			{12940, 7,0}, /* core3 return_Stack1 bit41 */
			{12939, 7,0}, /* core3 return_Stack1 bit42 */
			{12938, 7,0}, /* core3 return_Stack1 bit43 */
			{12937, 7,0}, /* core3 return_Stack1 bit44 */
			{12936, 7,0}, /* core3 return_Stack1 bit45 */
			{12935, 7,0}, /* core3 return_Stack1 bit46 */
			{12934, 7,0}, /* core3 return_Stack1 bit47 */
			{14950, 7,0}, /* core3 return_Stack1 bit48 */
			{    0, 0,2}, /* core3 return_Stack1 bit49 */
			{    0, 0,2}, /* core3 return_Stack1 bit50 */
			{    0, 0,2}, /* core3 return_Stack1 bit51 */
			{    0, 0,2}, /* core3 return_Stack1 bit52 */
			{    0, 0,2}, /* core3 return_Stack1 bit53 */
			{    0, 0,2}, /* core3 return_Stack1 bit54 */
			{    0, 0,2}, /* core3 return_Stack1 bit55 */
			{    0, 0,2}, /* core3 return_Stack1 bit56 */
			{    0, 0,2}, /* core3 return_Stack1 bit57 */
			{    0, 0,2}, /* core3 return_Stack1 bit58 */
			{    0, 0,2}, /* core3 return_Stack1 bit59 */
			{    0, 0,2}, /* core3 return_Stack1 bit60 */
			{    0, 0,2}, /* core3 return_Stack1 bit61 */
			{    0, 0,2}, /* core3 return_Stack1 bit62 */
			{    0, 0,2}, /* core3 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{12987, 7,0}, /* core3 return_Stack2 bit0 */
			{12986, 7,0}, /* core3 return_Stack2 bit1 */
			{12985, 7,0}, /* core3 return_Stack2 bit2 */
			{12984, 7,0}, /* core3 return_Stack2 bit3 */
			{16669, 7,0}, /* core3 return_Stack2 bit4 */
			{16668, 7,0}, /* core3 return_Stack2 bit5 */
			{16667, 7,0}, /* core3 return_Stack2 bit6 */
			{16666, 7,0}, /* core3 return_Stack2 bit7 */
			{16685, 7,0}, /* core3 return_Stack2 bit8 */
			{16684, 7,0}, /* core3 return_Stack2 bit9 */
			{16683, 7,0}, /* core3 return_Stack2 bit10 */
			{16682, 7,0}, /* core3 return_Stack2 bit11 */
			{16677, 7,0}, /* core3 return_Stack2 bit12 */
			{16676, 7,0}, /* core3 return_Stack2 bit13 */
			{16675, 7,0}, /* core3 return_Stack2 bit14 */
			{16674, 7,0}, /* core3 return_Stack2 bit15 */
			{16673, 7,0}, /* core3 return_Stack2 bit16 */
			{16672, 7,0}, /* core3 return_Stack2 bit17 */
			{16671, 7,0}, /* core3 return_Stack2 bit18 */
			{16670, 7,0}, /* core3 return_Stack2 bit19 */
			{16657, 7,0}, /* core3 return_Stack2 bit20 */
			{16656, 7,0}, /* core3 return_Stack2 bit21 */
			{16655, 7,0}, /* core3 return_Stack2 bit22 */
			{16654, 7,0}, /* core3 return_Stack2 bit23 */
			{16653, 7,0}, /* core3 return_Stack2 bit24 */
			{16652, 7,0}, /* core3 return_Stack2 bit25 */
			{16651, 7,0}, /* core3 return_Stack2 bit26 */
			{16650, 7,0}, /* core3 return_Stack2 bit27 */
			{16645, 7,0}, /* core3 return_Stack2 bit28 */
			{16644, 7,0}, /* core3 return_Stack2 bit29 */
			{16643, 7,0}, /* core3 return_Stack2 bit30 */
			{16642, 7,0}, /* core3 return_Stack2 bit31 */
			{16633, 7,0}, /* core3 return_Stack2 bit32 */
			{16632, 7,0}, /* core3 return_Stack2 bit33 */
			{16631, 7,0}, /* core3 return_Stack2 bit34 */
			{16630, 7,0}, /* core3 return_Stack2 bit35 */
			{16625, 7,0}, /* core3 return_Stack2 bit36 */
			{16624, 7,0}, /* core3 return_Stack2 bit37 */
			{16623, 7,0}, /* core3 return_Stack2 bit38 */
			{16622, 7,0}, /* core3 return_Stack2 bit39 */
			{16629, 7,0}, /* core3 return_Stack2 bit40 */
			{16628, 7,0}, /* core3 return_Stack2 bit41 */
			{16627, 7,0}, /* core3 return_Stack2 bit42 */
			{16626, 7,0}, /* core3 return_Stack2 bit43 */
			{16637, 7,0}, /* core3 return_Stack2 bit44 */
			{16636, 7,0}, /* core3 return_Stack2 bit45 */
			{16635, 7,0}, /* core3 return_Stack2 bit46 */
			{16634, 7,0}, /* core3 return_Stack2 bit47 */
			{14952, 7,0}, /* core3 return_Stack2 bit48 */
			{    0, 0,2}, /* core3 return_Stack2 bit49 */
			{    0, 0,2}, /* core3 return_Stack2 bit50 */
			{    0, 0,2}, /* core3 return_Stack2 bit51 */
			{    0, 0,2}, /* core3 return_Stack2 bit52 */
			{    0, 0,2}, /* core3 return_Stack2 bit53 */
			{    0, 0,2}, /* core3 return_Stack2 bit54 */
			{    0, 0,2}, /* core3 return_Stack2 bit55 */
			{    0, 0,2}, /* core3 return_Stack2 bit56 */
			{    0, 0,2}, /* core3 return_Stack2 bit57 */
			{    0, 0,2}, /* core3 return_Stack2 bit58 */
			{    0, 0,2}, /* core3 return_Stack2 bit59 */
			{    0, 0,2}, /* core3 return_Stack2 bit60 */
			{    0, 0,2}, /* core3 return_Stack2 bit61 */
			{    0, 0,2}, /* core3 return_Stack2 bit62 */
			{    0, 0,2}, /* core3 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{16697, 7,0}, /* core3 return_Stack3 bit0 */
			{16696, 7,0}, /* core3 return_Stack3 bit1 */
			{16695, 7,0}, /* core3 return_Stack3 bit2 */
			{16694, 7,0}, /* core3 return_Stack3 bit3 */
			{16665, 7,0}, /* core3 return_Stack3 bit4 */
			{16664, 7,0}, /* core3 return_Stack3 bit5 */
			{16663, 7,0}, /* core3 return_Stack3 bit6 */
			{16662, 7,0}, /* core3 return_Stack3 bit7 */
			{16693, 7,0}, /* core3 return_Stack3 bit8 */
			{16692, 7,0}, /* core3 return_Stack3 bit9 */
			{16691, 7,0}, /* core3 return_Stack3 bit10 */
			{16690, 7,0}, /* core3 return_Stack3 bit11 */
			{16681, 7,0}, /* core3 return_Stack3 bit12 */
			{16680, 7,0}, /* core3 return_Stack3 bit13 */
			{16679, 7,0}, /* core3 return_Stack3 bit14 */
			{16678, 7,0}, /* core3 return_Stack3 bit15 */
			{16689, 7,0}, /* core3 return_Stack3 bit16 */
			{16688, 7,0}, /* core3 return_Stack3 bit17 */
			{16687, 7,0}, /* core3 return_Stack3 bit18 */
			{16686, 7,0}, /* core3 return_Stack3 bit19 */
			{16661, 7,0}, /* core3 return_Stack3 bit20 */
			{16660, 7,0}, /* core3 return_Stack3 bit21 */
			{16659, 7,0}, /* core3 return_Stack3 bit22 */
			{16658, 7,0}, /* core3 return_Stack3 bit23 */
			{16641, 7,0}, /* core3 return_Stack3 bit24 */
			{16640, 7,0}, /* core3 return_Stack3 bit25 */
			{16639, 7,0}, /* core3 return_Stack3 bit26 */
			{16638, 7,0}, /* core3 return_Stack3 bit27 */
			{16649, 7,0}, /* core3 return_Stack3 bit28 */
			{16648, 7,0}, /* core3 return_Stack3 bit29 */
			{16647, 7,0}, /* core3 return_Stack3 bit30 */
			{16646, 7,0}, /* core3 return_Stack3 bit31 */
			{12959, 7,0}, /* core3 return_Stack3 bit32 */
			{12958, 7,0}, /* core3 return_Stack3 bit33 */
			{12957, 7,0}, /* core3 return_Stack3 bit34 */
			{12956, 7,0}, /* core3 return_Stack3 bit35 */
			{12951, 7,0}, /* core3 return_Stack3 bit36 */
			{12950, 7,0}, /* core3 return_Stack3 bit37 */
			{12949, 7,0}, /* core3 return_Stack3 bit38 */
			{12948, 7,0}, /* core3 return_Stack3 bit39 */
			{12945, 7,0}, /* core3 return_Stack3 bit40 */
			{12944, 7,0}, /* core3 return_Stack3 bit41 */
			{12943, 7,0}, /* core3 return_Stack3 bit42 */
			{12942, 7,0}, /* core3 return_Stack3 bit43 */
			{12955, 7,0}, /* core3 return_Stack3 bit44 */
			{12954, 7,0}, /* core3 return_Stack3 bit45 */
			{12953, 7,0}, /* core3 return_Stack3 bit46 */
			{12952, 7,0}, /* core3 return_Stack3 bit47 */
			{14949, 7,0}, /* core3 return_Stack3 bit48 */
			{    0, 0,2}, /* core3 return_Stack3 bit49 */
			{    0, 0,2}, /* core3 return_Stack3 bit50 */
			{    0, 0,2}, /* core3 return_Stack3 bit51 */
			{    0, 0,2}, /* core3 return_Stack3 bit52 */
			{    0, 0,2}, /* core3 return_Stack3 bit53 */
			{    0, 0,2}, /* core3 return_Stack3 bit54 */
			{    0, 0,2}, /* core3 return_Stack3 bit55 */
			{    0, 0,2}, /* core3 return_Stack3 bit56 */
			{    0, 0,2}, /* core3 return_Stack3 bit57 */
			{    0, 0,2}, /* core3 return_Stack3 bit58 */
			{    0, 0,2}, /* core3 return_Stack3 bit59 */
			{    0, 0,2}, /* core3 return_Stack3 bit60 */
			{    0, 0,2}, /* core3 return_Stack3 bit61 */
			{    0, 0,2}, /* core3 return_Stack3 bit62 */
			{    0, 0,2}, /* core3 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{13011, 7,0}, /* core3 return_Stack4 bit0 */
			{13010, 7,0}, /* core3 return_Stack4 bit1 */
			{13009, 7,0}, /* core3 return_Stack4 bit2 */
			{13008, 7,0}, /* core3 return_Stack4 bit3 */
			{13003, 7,0}, /* core3 return_Stack4 bit4 */
			{13002, 7,0}, /* core3 return_Stack4 bit5 */
			{13001, 7,0}, /* core3 return_Stack4 bit6 */
			{13000, 7,0}, /* core3 return_Stack4 bit7 */
			{12979, 7,0}, /* core3 return_Stack4 bit8 */
			{12978, 7,0}, /* core3 return_Stack4 bit9 */
			{12977, 7,0}, /* core3 return_Stack4 bit10 */
			{12976, 7,0}, /* core3 return_Stack4 bit11 */
			{12975, 7,0}, /* core3 return_Stack4 bit12 */
			{12974, 7,0}, /* core3 return_Stack4 bit13 */
			{12973, 7,0}, /* core3 return_Stack4 bit14 */
			{12972, 7,0}, /* core3 return_Stack4 bit15 */
			{13015, 7,0}, /* core3 return_Stack4 bit16 */
			{13014, 7,0}, /* core3 return_Stack4 bit17 */
			{13013, 7,0}, /* core3 return_Stack4 bit18 */
			{13012, 7,0}, /* core3 return_Stack4 bit19 */
			{13023, 7,0}, /* core3 return_Stack4 bit20 */
			{13022, 7,0}, /* core3 return_Stack4 bit21 */
			{13021, 7,0}, /* core3 return_Stack4 bit22 */
			{13020, 7,0}, /* core3 return_Stack4 bit23 */
			{13088, 7,0}, /* core3 return_Stack4 bit24 */
			{13087, 7,0}, /* core3 return_Stack4 bit25 */
			{13086, 7,0}, /* core3 return_Stack4 bit26 */
			{13085, 7,0}, /* core3 return_Stack4 bit27 */
			{16309, 7,0}, /* core3 return_Stack4 bit28 */
			{16308, 7,0}, /* core3 return_Stack4 bit29 */
			{16307, 7,0}, /* core3 return_Stack4 bit30 */
			{16306, 7,0}, /* core3 return_Stack4 bit31 */
			{13080, 7,0}, /* core3 return_Stack4 bit32 */
			{13079, 7,0}, /* core3 return_Stack4 bit33 */
			{13078, 7,0}, /* core3 return_Stack4 bit34 */
			{13077, 7,0}, /* core3 return_Stack4 bit35 */
			{18841, 6,0}, /* core3 return_Stack4 bit36 */
			{18840, 6,0}, /* core3 return_Stack4 bit37 */
			{18839, 6,0}, /* core3 return_Stack4 bit38 */
			{18838, 6,0}, /* core3 return_Stack4 bit39 */
			{18837, 6,0}, /* core3 return_Stack4 bit40 */
			{18836, 6,0}, /* core3 return_Stack4 bit41 */
			{18835, 6,0}, /* core3 return_Stack4 bit42 */
			{18834, 6,0}, /* core3 return_Stack4 bit43 */
			{18845, 6,0}, /* core3 return_Stack4 bit44 */
			{18844, 6,0}, /* core3 return_Stack4 bit45 */
			{18843, 6,0}, /* core3 return_Stack4 bit46 */
			{18842, 6,0}, /* core3 return_Stack4 bit47 */
			{14567, 7,0}, /* core3 return_Stack4 bit48 */
			{    0, 0,2}, /* core3 return_Stack4 bit49 */
			{    0, 0,2}, /* core3 return_Stack4 bit50 */
			{    0, 0,2}, /* core3 return_Stack4 bit51 */
			{    0, 0,2}, /* core3 return_Stack4 bit52 */
			{    0, 0,2}, /* core3 return_Stack4 bit53 */
			{    0, 0,2}, /* core3 return_Stack4 bit54 */
			{    0, 0,2}, /* core3 return_Stack4 bit55 */
			{    0, 0,2}, /* core3 return_Stack4 bit56 */
			{    0, 0,2}, /* core3 return_Stack4 bit57 */
			{    0, 0,2}, /* core3 return_Stack4 bit58 */
			{    0, 0,2}, /* core3 return_Stack4 bit59 */
			{    0, 0,2}, /* core3 return_Stack4 bit60 */
			{    0, 0,2}, /* core3 return_Stack4 bit61 */
			{    0, 0,2}, /* core3 return_Stack4 bit62 */
			{    0, 0,2}, /* core3 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{16717, 7,0}, /* core3 return_Stack5 bit0 */
			{16716, 7,0}, /* core3 return_Stack5 bit1 */
			{16715, 7,0}, /* core3 return_Stack5 bit2 */
			{16714, 7,0}, /* core3 return_Stack5 bit3 */
			{16709, 7,0}, /* core3 return_Stack5 bit4 */
			{16708, 7,0}, /* core3 return_Stack5 bit5 */
			{16707, 7,0}, /* core3 return_Stack5 bit6 */
			{16706, 7,0}, /* core3 return_Stack5 bit7 */
			{12991, 7,0}, /* core3 return_Stack5 bit8 */
			{12990, 7,0}, /* core3 return_Stack5 bit9 */
			{12989, 7,0}, /* core3 return_Stack5 bit10 */
			{12988, 7,0}, /* core3 return_Stack5 bit11 */
			{16757, 7,0}, /* core3 return_Stack5 bit12 */
			{16756, 7,0}, /* core3 return_Stack5 bit13 */
			{16755, 7,0}, /* core3 return_Stack5 bit14 */
			{16754, 7,0}, /* core3 return_Stack5 bit15 */
			{16749, 7,0}, /* core3 return_Stack5 bit16 */
			{16748, 7,0}, /* core3 return_Stack5 bit17 */
			{16747, 7,0}, /* core3 return_Stack5 bit18 */
			{16746, 7,0}, /* core3 return_Stack5 bit19 */
			{16769, 7,0}, /* core3 return_Stack5 bit20 */
			{16768, 7,0}, /* core3 return_Stack5 bit21 */
			{16767, 7,0}, /* core3 return_Stack5 bit22 */
			{16766, 7,0}, /* core3 return_Stack5 bit23 */
			{12971, 7,0}, /* core3 return_Stack5 bit24 */
			{12970, 7,0}, /* core3 return_Stack5 bit25 */
			{12969, 7,0}, /* core3 return_Stack5 bit26 */
			{12968, 7,0}, /* core3 return_Stack5 bit27 */
			{12967, 7,0}, /* core3 return_Stack5 bit28 */
			{12966, 7,0}, /* core3 return_Stack5 bit29 */
			{12965, 7,0}, /* core3 return_Stack5 bit30 */
			{12964, 7,0}, /* core3 return_Stack5 bit31 */
			{13056, 7,0}, /* core3 return_Stack5 bit32 */
			{13055, 7,0}, /* core3 return_Stack5 bit33 */
			{13054, 7,0}, /* core3 return_Stack5 bit34 */
			{13053, 7,0}, /* core3 return_Stack5 bit35 */
			{12925, 7,0}, /* core3 return_Stack5 bit36 */
			{12924, 7,0}, /* core3 return_Stack5 bit37 */
			{12923, 7,0}, /* core3 return_Stack5 bit38 */
			{12922, 7,0}, /* core3 return_Stack5 bit39 */
			{12921, 7,0}, /* core3 return_Stack5 bit40 */
			{12920, 7,0}, /* core3 return_Stack5 bit41 */
			{12919, 7,0}, /* core3 return_Stack5 bit42 */
			{12918, 7,0}, /* core3 return_Stack5 bit43 */
			{12933, 7,0}, /* core3 return_Stack5 bit44 */
			{12932, 7,0}, /* core3 return_Stack5 bit45 */
			{12931, 7,0}, /* core3 return_Stack5 bit46 */
			{12930, 7,0}, /* core3 return_Stack5 bit47 */
			{14951, 7,0}, /* core3 return_Stack5 bit48 */
			{    0, 0,2}, /* core3 return_Stack5 bit49 */
			{    0, 0,2}, /* core3 return_Stack5 bit50 */
			{    0, 0,2}, /* core3 return_Stack5 bit51 */
			{    0, 0,2}, /* core3 return_Stack5 bit52 */
			{    0, 0,2}, /* core3 return_Stack5 bit53 */
			{    0, 0,2}, /* core3 return_Stack5 bit54 */
			{    0, 0,2}, /* core3 return_Stack5 bit55 */
			{    0, 0,2}, /* core3 return_Stack5 bit56 */
			{    0, 0,2}, /* core3 return_Stack5 bit57 */
			{    0, 0,2}, /* core3 return_Stack5 bit58 */
			{    0, 0,2}, /* core3 return_Stack5 bit59 */
			{    0, 0,2}, /* core3 return_Stack5 bit60 */
			{    0, 0,2}, /* core3 return_Stack5 bit61 */
			{    0, 0,2}, /* core3 return_Stack5 bit62 */
			{    0, 0,2}, /* core3 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{16737, 7,0}, /* core3 return_Stack6 bit0 */
			{16736, 7,0}, /* core3 return_Stack6 bit1 */
			{16735, 7,0}, /* core3 return_Stack6 bit2 */
			{16734, 7,0}, /* core3 return_Stack6 bit3 */
			{13007, 7,0}, /* core3 return_Stack6 bit4 */
			{13006, 7,0}, /* core3 return_Stack6 bit5 */
			{13005, 7,0}, /* core3 return_Stack6 bit6 */
			{13004, 7,0}, /* core3 return_Stack6 bit7 */
			{12999, 7,0}, /* core3 return_Stack6 bit8 */
			{12998, 7,0}, /* core3 return_Stack6 bit9 */
			{12997, 7,0}, /* core3 return_Stack6 bit10 */
			{12996, 7,0}, /* core3 return_Stack6 bit11 */
			{16781, 7,0}, /* core3 return_Stack6 bit12 */
			{16780, 7,0}, /* core3 return_Stack6 bit13 */
			{16779, 7,0}, /* core3 return_Stack6 bit14 */
			{16778, 7,0}, /* core3 return_Stack6 bit15 */
			{16793, 7,0}, /* core3 return_Stack6 bit16 */
			{16792, 7,0}, /* core3 return_Stack6 bit17 */
			{16791, 7,0}, /* core3 return_Stack6 bit18 */
			{16790, 7,0}, /* core3 return_Stack6 bit19 */
			{13027, 7,0}, /* core3 return_Stack6 bit20 */
			{13026, 7,0}, /* core3 return_Stack6 bit21 */
			{13025, 7,0}, /* core3 return_Stack6 bit22 */
			{13024, 7,0}, /* core3 return_Stack6 bit23 */
			{13096, 7,0}, /* core3 return_Stack6 bit24 */
			{13095, 7,0}, /* core3 return_Stack6 bit25 */
			{13094, 7,0}, /* core3 return_Stack6 bit26 */
			{13093, 7,0}, /* core3 return_Stack6 bit27 */
			{13031, 7,0}, /* core3 return_Stack6 bit28 */
			{13030, 7,0}, /* core3 return_Stack6 bit29 */
			{13029, 7,0}, /* core3 return_Stack6 bit30 */
			{13028, 7,0}, /* core3 return_Stack6 bit31 */
			{13048, 7,0}, /* core3 return_Stack6 bit32 */
			{13047, 7,0}, /* core3 return_Stack6 bit33 */
			{13046, 7,0}, /* core3 return_Stack6 bit34 */
			{13045, 7,0}, /* core3 return_Stack6 bit35 */
			{13084, 7,0}, /* core3 return_Stack6 bit36 */
			{13083, 7,0}, /* core3 return_Stack6 bit37 */
			{13082, 7,0}, /* core3 return_Stack6 bit38 */
			{13081, 7,0}, /* core3 return_Stack6 bit39 */
			{12909, 7,0}, /* core3 return_Stack6 bit40 */
			{12908, 7,0}, /* core3 return_Stack6 bit41 */
			{12907, 7,0}, /* core3 return_Stack6 bit42 */
			{12906, 7,0}, /* core3 return_Stack6 bit43 */
			{13076, 7,0}, /* core3 return_Stack6 bit44 */
			{13075, 7,0}, /* core3 return_Stack6 bit45 */
			{13074, 7,0}, /* core3 return_Stack6 bit46 */
			{13073, 7,0}, /* core3 return_Stack6 bit47 */
			{14568, 7,0}, /* core3 return_Stack6 bit48 */
			{    0, 0,2}, /* core3 return_Stack6 bit49 */
			{    0, 0,2}, /* core3 return_Stack6 bit50 */
			{    0, 0,2}, /* core3 return_Stack6 bit51 */
			{    0, 0,2}, /* core3 return_Stack6 bit52 */
			{    0, 0,2}, /* core3 return_Stack6 bit53 */
			{    0, 0,2}, /* core3 return_Stack6 bit54 */
			{    0, 0,2}, /* core3 return_Stack6 bit55 */
			{    0, 0,2}, /* core3 return_Stack6 bit56 */
			{    0, 0,2}, /* core3 return_Stack6 bit57 */
			{    0, 0,2}, /* core3 return_Stack6 bit58 */
			{    0, 0,2}, /* core3 return_Stack6 bit59 */
			{    0, 0,2}, /* core3 return_Stack6 bit60 */
			{    0, 0,2}, /* core3 return_Stack6 bit61 */
			{    0, 0,2}, /* core3 return_Stack6 bit62 */
			{    0, 0,2}, /* core3 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{16733, 7,0}, /* core3 return_Stack7 bit0 */
			{16732, 7,0}, /* core3 return_Stack7 bit1 */
			{16731, 7,0}, /* core3 return_Stack7 bit2 */
			{16730, 7,0}, /* core3 return_Stack7 bit3 */
			{16713, 7,0}, /* core3 return_Stack7 bit4 */
			{16712, 7,0}, /* core3 return_Stack7 bit5 */
			{16711, 7,0}, /* core3 return_Stack7 bit6 */
			{16710, 7,0}, /* core3 return_Stack7 bit7 */
			{16745, 7,0}, /* core3 return_Stack7 bit8 */
			{16744, 7,0}, /* core3 return_Stack7 bit9 */
			{16743, 7,0}, /* core3 return_Stack7 bit10 */
			{16742, 7,0}, /* core3 return_Stack7 bit11 */
			{16785, 7,0}, /* core3 return_Stack7 bit12 */
			{16784, 7,0}, /* core3 return_Stack7 bit13 */
			{16783, 7,0}, /* core3 return_Stack7 bit14 */
			{16782, 7,0}, /* core3 return_Stack7 bit15 */
			{16741, 7,0}, /* core3 return_Stack7 bit16 */
			{16740, 7,0}, /* core3 return_Stack7 bit17 */
			{16739, 7,0}, /* core3 return_Stack7 bit18 */
			{16738, 7,0}, /* core3 return_Stack7 bit19 */
			{16801, 7,0}, /* core3 return_Stack7 bit20 */
			{16800, 7,0}, /* core3 return_Stack7 bit21 */
			{16799, 7,0}, /* core3 return_Stack7 bit22 */
			{16798, 7,0}, /* core3 return_Stack7 bit23 */
			{16797, 7,0}, /* core3 return_Stack7 bit24 */
			{16796, 7,0}, /* core3 return_Stack7 bit25 */
			{16795, 7,0}, /* core3 return_Stack7 bit26 */
			{16794, 7,0}, /* core3 return_Stack7 bit27 */
			{13035, 7,0}, /* core3 return_Stack7 bit28 */
			{13034, 7,0}, /* core3 return_Stack7 bit29 */
			{13033, 7,0}, /* core3 return_Stack7 bit30 */
			{13032, 7,0}, /* core3 return_Stack7 bit31 */
			{13044, 7,0}, /* core3 return_Stack7 bit32 */
			{13043, 7,0}, /* core3 return_Stack7 bit33 */
			{13042, 7,0}, /* core3 return_Stack7 bit34 */
			{13041, 7,0}, /* core3 return_Stack7 bit35 */
			{12913, 7,0}, /* core3 return_Stack7 bit36 */
			{12912, 7,0}, /* core3 return_Stack7 bit37 */
			{12911, 7,0}, /* core3 return_Stack7 bit38 */
			{12910, 7,0}, /* core3 return_Stack7 bit39 */
			{12917, 7,0}, /* core3 return_Stack7 bit40 */
			{12916, 7,0}, /* core3 return_Stack7 bit41 */
			{12915, 7,0}, /* core3 return_Stack7 bit42 */
			{12914, 7,0}, /* core3 return_Stack7 bit43 */
			{13060, 7,0}, /* core3 return_Stack7 bit44 */
			{13059, 7,0}, /* core3 return_Stack7 bit45 */
			{13058, 7,0}, /* core3 return_Stack7 bit46 */
			{13057, 7,0}, /* core3 return_Stack7 bit47 */
			{14569, 7,0}, /* core3 return_Stack7 bit48 */
			{    0, 0,2}, /* core3 return_Stack7 bit49 */
			{    0, 0,2}, /* core3 return_Stack7 bit50 */
			{    0, 0,2}, /* core3 return_Stack7 bit51 */
			{    0, 0,2}, /* core3 return_Stack7 bit52 */
			{    0, 0,2}, /* core3 return_Stack7 bit53 */
			{    0, 0,2}, /* core3 return_Stack7 bit54 */
			{    0, 0,2}, /* core3 return_Stack7 bit55 */
			{    0, 0,2}, /* core3 return_Stack7 bit56 */
			{    0, 0,2}, /* core3 return_Stack7 bit57 */
			{    0, 0,2}, /* core3 return_Stack7 bit58 */
			{    0, 0,2}, /* core3 return_Stack7 bit59 */
			{    0, 0,2}, /* core3 return_Stack7 bit60 */
			{    0, 0,2}, /* core3 return_Stack7 bit61 */
			{    0, 0,2}, /* core3 return_Stack7 bit62 */
			{    0, 0,2}, /* core3 return_Stack7 bit63 */
			}},
	},
};

struct big_core_spec big_core[] = {
	{		/* core 4 */
	},
};
