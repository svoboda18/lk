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
#define SUPPORT_CACHE_DUMP

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
	struct reg_collector mp0_L3_parity_err;
	struct reg_collector mp0_L3_parity_index;
	struct reg_collector mp0_L3_parity_bank;
	struct reg_collector mp0_L3_parity_err_count;
	struct reg_collector mp0_L3_parity_sap;
	struct reg_collector L2_parity_err;
	struct reg_collector L2_parity_err_count;
	struct reg_collector L2_parity_index;
	struct reg_collector L2_parity_way;
	struct reg_collector L2_parity_banks;
	struct reg_collector dfd_v35_enable;
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
	struct reg_collector edpcsr;
	struct reg_collector spmc_power_state;
	struct reg_collector i0_valid;
	struct reg_collector i1_valid;
	struct reg_collector i2_valid;
	struct reg_collector i0_pc;
	struct reg_collector i1_pc;
	struct reg_collector i2_pc;
	struct reg_collector last_branch;
	struct reg_collector sram_wr_ptr_0;
	struct reg_collector sram_wr_ptr_1;
	struct reg_collector sram_wr_ptr_2;
	struct reg_collector mp0_L3_parity_err;
	struct reg_collector mp0_L3_parity_index;
	struct reg_collector mp0_L3_parity_bank;
	struct reg_collector mp0_L3_parity_err_count;
	struct reg_collector mp0_L3_parity_sap;
	struct reg_collector L2_parity_err;
	struct reg_collector L2_parity_err_count;
	struct reg_collector L2_parity_index;
	struct reg_collector L2_parity_way;
	struct reg_collector L2_parity_banks;
	struct reg_collector dfd_v35_enable;
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

struct mcusys_spec {
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
	struct reg_collector mp0_L3_parity_err;
	struct reg_collector mp0_L3_parity_index;
	struct reg_collector mp0_L3_parity_bank;
	struct reg_collector mp0_L3_parity_err_count;
	struct reg_collector mp0_L3_parity_sap;
	struct reg_collector L2_parity_err;
	struct reg_collector L2_parity_err_count;
	struct reg_collector L2_parity_index;
	struct reg_collector L2_parity_way;
	struct reg_collector L2_parity_banks;
	struct reg_collector dfd_v35_enable;
};

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
	{	/* core 4 */
			.power_state = {{
			{    0,32,0}, /* core4 power_state bit0 */
			{    0,42,0}, /* core4 power_state bit1 */
			{    0, 0,2}, /* core4 power_state bit2 */
			{    0, 0,2}, /* core4 power_state bit3 */
			{    0, 0,2}, /* core4 power_state bit4 */
			{    0, 0,2}, /* core4 power_state bit5 */
			{    0, 0,2}, /* core4 power_state bit6 */
			{    0, 0,2}, /* core4 power_state bit7 */
			{    0, 0,2}, /* core4 power_state bit8 */
			{    0, 0,2}, /* core4 power_state bit9 */
			{    0, 0,2}, /* core4 power_state bit10 */
			{    0, 0,2}, /* core4 power_state bit11 */
			{    0, 0,2}, /* core4 power_state bit12 */
			{    0, 0,2}, /* core4 power_state bit13 */
			{    0, 0,2}, /* core4 power_state bit14 */
			{    0, 0,2}, /* core4 power_state bit15 */
			{    0, 0,2}, /* core4 power_state bit16 */
			{    0, 0,2}, /* core4 power_state bit17 */
			{    0, 0,2}, /* core4 power_state bit18 */
			{    0, 0,2}, /* core4 power_state bit19 */
			{    0, 0,2}, /* core4 power_state bit20 */
			{    0, 0,2}, /* core4 power_state bit21 */
			{    0, 0,2}, /* core4 power_state bit22 */
			{    0, 0,2}, /* core4 power_state bit23 */
			{    0, 0,2}, /* core4 power_state bit24 */
			{    0, 0,2}, /* core4 power_state bit25 */
			{    0, 0,2}, /* core4 power_state bit26 */
			{    0, 0,2}, /* core4 power_state bit27 */
			{    0, 0,2}, /* core4 power_state bit28 */
			{    0, 0,2}, /* core4 power_state bit29 */
			{    0, 0,2}, /* core4 power_state bit30 */
			{    0, 0,2}, /* core4 power_state bit31 */
			{    0, 0,2}, /* core4 power_state bit32 */
			{    0, 0,2}, /* core4 power_state bit33 */
			{    0, 0,2}, /* core4 power_state bit34 */
			{    0, 0,2}, /* core4 power_state bit35 */
			{    0, 0,2}, /* core4 power_state bit36 */
			{    0, 0,2}, /* core4 power_state bit37 */
			{    0, 0,2}, /* core4 power_state bit38 */
			{    0, 0,2}, /* core4 power_state bit39 */
			{    0, 0,2}, /* core4 power_state bit40 */
			{    0, 0,2}, /* core4 power_state bit41 */
			{    0, 0,2}, /* core4 power_state bit42 */
			{    0, 0,2}, /* core4 power_state bit43 */
			{    0, 0,2}, /* core4 power_state bit44 */
			{    0, 0,2}, /* core4 power_state bit45 */
			{    0, 0,2}, /* core4 power_state bit46 */
			{    0, 0,2}, /* core4 power_state bit47 */
			{    0, 0,2}, /* core4 power_state bit48 */
			{    0, 0,2}, /* core4 power_state bit49 */
			{    0, 0,2}, /* core4 power_state bit50 */
			{    0, 0,2}, /* core4 power_state bit51 */
			{    0, 0,2}, /* core4 power_state bit52 */
			{    0, 0,2}, /* core4 power_state bit53 */
			{    0, 0,2}, /* core4 power_state bit54 */
			{    0, 0,2}, /* core4 power_state bit55 */
			{    0, 0,2}, /* core4 power_state bit56 */
			{    0, 0,2}, /* core4 power_state bit57 */
			{    0, 0,2}, /* core4 power_state bit58 */
			{    0, 0,2}, /* core4 power_state bit59 */
			{    0, 0,2}, /* core4 power_state bit60 */
			{    0, 0,2}, /* core4 power_state bit61 */
			{    0, 0,2}, /* core4 power_state bit62 */
			{    0, 0,2}, /* core4 power_state bit63 */
			}},
	},
	{	/* core 5 */
			.power_state = {{
			{    0,33,0}, /* core5 power_state bit0 */
			{    0,43,0}, /* core5 power_state bit1 */
			{    0, 0,2}, /* core5 power_state bit2 */
			{    0, 0,2}, /* core5 power_state bit3 */
			{    0, 0,2}, /* core5 power_state bit4 */
			{    0, 0,2}, /* core5 power_state bit5 */
			{    0, 0,2}, /* core5 power_state bit6 */
			{    0, 0,2}, /* core5 power_state bit7 */
			{    0, 0,2}, /* core5 power_state bit8 */
			{    0, 0,2}, /* core5 power_state bit9 */
			{    0, 0,2}, /* core5 power_state bit10 */
			{    0, 0,2}, /* core5 power_state bit11 */
			{    0, 0,2}, /* core5 power_state bit12 */
			{    0, 0,2}, /* core5 power_state bit13 */
			{    0, 0,2}, /* core5 power_state bit14 */
			{    0, 0,2}, /* core5 power_state bit15 */
			{    0, 0,2}, /* core5 power_state bit16 */
			{    0, 0,2}, /* core5 power_state bit17 */
			{    0, 0,2}, /* core5 power_state bit18 */
			{    0, 0,2}, /* core5 power_state bit19 */
			{    0, 0,2}, /* core5 power_state bit20 */
			{    0, 0,2}, /* core5 power_state bit21 */
			{    0, 0,2}, /* core5 power_state bit22 */
			{    0, 0,2}, /* core5 power_state bit23 */
			{    0, 0,2}, /* core5 power_state bit24 */
			{    0, 0,2}, /* core5 power_state bit25 */
			{    0, 0,2}, /* core5 power_state bit26 */
			{    0, 0,2}, /* core5 power_state bit27 */
			{    0, 0,2}, /* core5 power_state bit28 */
			{    0, 0,2}, /* core5 power_state bit29 */
			{    0, 0,2}, /* core5 power_state bit30 */
			{    0, 0,2}, /* core5 power_state bit31 */
			{    0, 0,2}, /* core5 power_state bit32 */
			{    0, 0,2}, /* core5 power_state bit33 */
			{    0, 0,2}, /* core5 power_state bit34 */
			{    0, 0,2}, /* core5 power_state bit35 */
			{    0, 0,2}, /* core5 power_state bit36 */
			{    0, 0,2}, /* core5 power_state bit37 */
			{    0, 0,2}, /* core5 power_state bit38 */
			{    0, 0,2}, /* core5 power_state bit39 */
			{    0, 0,2}, /* core5 power_state bit40 */
			{    0, 0,2}, /* core5 power_state bit41 */
			{    0, 0,2}, /* core5 power_state bit42 */
			{    0, 0,2}, /* core5 power_state bit43 */
			{    0, 0,2}, /* core5 power_state bit44 */
			{    0, 0,2}, /* core5 power_state bit45 */
			{    0, 0,2}, /* core5 power_state bit46 */
			{    0, 0,2}, /* core5 power_state bit47 */
			{    0, 0,2}, /* core5 power_state bit48 */
			{    0, 0,2}, /* core5 power_state bit49 */
			{    0, 0,2}, /* core5 power_state bit50 */
			{    0, 0,2}, /* core5 power_state bit51 */
			{    0, 0,2}, /* core5 power_state bit52 */
			{    0, 0,2}, /* core5 power_state bit53 */
			{    0, 0,2}, /* core5 power_state bit54 */
			{    0, 0,2}, /* core5 power_state bit55 */
			{    0, 0,2}, /* core5 power_state bit56 */
			{    0, 0,2}, /* core5 power_state bit57 */
			{    0, 0,2}, /* core5 power_state bit58 */
			{    0, 0,2}, /* core5 power_state bit59 */
			{    0, 0,2}, /* core5 power_state bit60 */
			{    0, 0,2}, /* core5 power_state bit61 */
			{    0, 0,2}, /* core5 power_state bit62 */
			{    0, 0,2}, /* core5 power_state bit63 */
			}},
	},
	{	/* core 6 */
			.power_state = {{
			{    0,34,0}, /* core6 power_state bit0 */
			{    0,44,0}, /* core6 power_state bit1 */
			{    0, 0,2}, /* core6 power_state bit2 */
			{    0, 0,2}, /* core6 power_state bit3 */
			{    0, 0,2}, /* core6 power_state bit4 */
			{    0, 0,2}, /* core6 power_state bit5 */
			{    0, 0,2}, /* core6 power_state bit6 */
			{    0, 0,2}, /* core6 power_state bit7 */
			{    0, 0,2}, /* core6 power_state bit8 */
			{    0, 0,2}, /* core6 power_state bit9 */
			{    0, 0,2}, /* core6 power_state bit10 */
			{    0, 0,2}, /* core6 power_state bit11 */
			{    0, 0,2}, /* core6 power_state bit12 */
			{    0, 0,2}, /* core6 power_state bit13 */
			{    0, 0,2}, /* core6 power_state bit14 */
			{    0, 0,2}, /* core6 power_state bit15 */
			{    0, 0,2}, /* core6 power_state bit16 */
			{    0, 0,2}, /* core6 power_state bit17 */
			{    0, 0,2}, /* core6 power_state bit18 */
			{    0, 0,2}, /* core6 power_state bit19 */
			{    0, 0,2}, /* core6 power_state bit20 */
			{    0, 0,2}, /* core6 power_state bit21 */
			{    0, 0,2}, /* core6 power_state bit22 */
			{    0, 0,2}, /* core6 power_state bit23 */
			{    0, 0,2}, /* core6 power_state bit24 */
			{    0, 0,2}, /* core6 power_state bit25 */
			{    0, 0,2}, /* core6 power_state bit26 */
			{    0, 0,2}, /* core6 power_state bit27 */
			{    0, 0,2}, /* core6 power_state bit28 */
			{    0, 0,2}, /* core6 power_state bit29 */
			{    0, 0,2}, /* core6 power_state bit30 */
			{    0, 0,2}, /* core6 power_state bit31 */
			{    0, 0,2}, /* core6 power_state bit32 */
			{    0, 0,2}, /* core6 power_state bit33 */
			{    0, 0,2}, /* core6 power_state bit34 */
			{    0, 0,2}, /* core6 power_state bit35 */
			{    0, 0,2}, /* core6 power_state bit36 */
			{    0, 0,2}, /* core6 power_state bit37 */
			{    0, 0,2}, /* core6 power_state bit38 */
			{    0, 0,2}, /* core6 power_state bit39 */
			{    0, 0,2}, /* core6 power_state bit40 */
			{    0, 0,2}, /* core6 power_state bit41 */
			{    0, 0,2}, /* core6 power_state bit42 */
			{    0, 0,2}, /* core6 power_state bit43 */
			{    0, 0,2}, /* core6 power_state bit44 */
			{    0, 0,2}, /* core6 power_state bit45 */
			{    0, 0,2}, /* core6 power_state bit46 */
			{    0, 0,2}, /* core6 power_state bit47 */
			{    0, 0,2}, /* core6 power_state bit48 */
			{    0, 0,2}, /* core6 power_state bit49 */
			{    0, 0,2}, /* core6 power_state bit50 */
			{    0, 0,2}, /* core6 power_state bit51 */
			{    0, 0,2}, /* core6 power_state bit52 */
			{    0, 0,2}, /* core6 power_state bit53 */
			{    0, 0,2}, /* core6 power_state bit54 */
			{    0, 0,2}, /* core6 power_state bit55 */
			{    0, 0,2}, /* core6 power_state bit56 */
			{    0, 0,2}, /* core6 power_state bit57 */
			{    0, 0,2}, /* core6 power_state bit58 */
			{    0, 0,2}, /* core6 power_state bit59 */
			{    0, 0,2}, /* core6 power_state bit60 */
			{    0, 0,2}, /* core6 power_state bit61 */
			{    0, 0,2}, /* core6 power_state bit62 */
			{    0, 0,2}, /* core6 power_state bit63 */
			}},
	},
	{	/* core 7 */
			.power_state = {{
			{    0,35,0}, /* core7 power_state bit0 */
			{    0,45,0}, /* core7 power_state bit1 */
			{    0, 0,2}, /* core7 power_state bit2 */
			{    0, 0,2}, /* core7 power_state bit3 */
			{    0, 0,2}, /* core7 power_state bit4 */
			{    0, 0,2}, /* core7 power_state bit5 */
			{    0, 0,2}, /* core7 power_state bit6 */
			{    0, 0,2}, /* core7 power_state bit7 */
			{    0, 0,2}, /* core7 power_state bit8 */
			{    0, 0,2}, /* core7 power_state bit9 */
			{    0, 0,2}, /* core7 power_state bit10 */
			{    0, 0,2}, /* core7 power_state bit11 */
			{    0, 0,2}, /* core7 power_state bit12 */
			{    0, 0,2}, /* core7 power_state bit13 */
			{    0, 0,2}, /* core7 power_state bit14 */
			{    0, 0,2}, /* core7 power_state bit15 */
			{    0, 0,2}, /* core7 power_state bit16 */
			{    0, 0,2}, /* core7 power_state bit17 */
			{    0, 0,2}, /* core7 power_state bit18 */
			{    0, 0,2}, /* core7 power_state bit19 */
			{    0, 0,2}, /* core7 power_state bit20 */
			{    0, 0,2}, /* core7 power_state bit21 */
			{    0, 0,2}, /* core7 power_state bit22 */
			{    0, 0,2}, /* core7 power_state bit23 */
			{    0, 0,2}, /* core7 power_state bit24 */
			{    0, 0,2}, /* core7 power_state bit25 */
			{    0, 0,2}, /* core7 power_state bit26 */
			{    0, 0,2}, /* core7 power_state bit27 */
			{    0, 0,2}, /* core7 power_state bit28 */
			{    0, 0,2}, /* core7 power_state bit29 */
			{    0, 0,2}, /* core7 power_state bit30 */
			{    0, 0,2}, /* core7 power_state bit31 */
			{    0, 0,2}, /* core7 power_state bit32 */
			{    0, 0,2}, /* core7 power_state bit33 */
			{    0, 0,2}, /* core7 power_state bit34 */
			{    0, 0,2}, /* core7 power_state bit35 */
			{    0, 0,2}, /* core7 power_state bit36 */
			{    0, 0,2}, /* core7 power_state bit37 */
			{    0, 0,2}, /* core7 power_state bit38 */
			{    0, 0,2}, /* core7 power_state bit39 */
			{    0, 0,2}, /* core7 power_state bit40 */
			{    0, 0,2}, /* core7 power_state bit41 */
			{    0, 0,2}, /* core7 power_state bit42 */
			{    0, 0,2}, /* core7 power_state bit43 */
			{    0, 0,2}, /* core7 power_state bit44 */
			{    0, 0,2}, /* core7 power_state bit45 */
			{    0, 0,2}, /* core7 power_state bit46 */
			{    0, 0,2}, /* core7 power_state bit47 */
			{    0, 0,2}, /* core7 power_state bit48 */
			{    0, 0,2}, /* core7 power_state bit49 */
			{    0, 0,2}, /* core7 power_state bit50 */
			{    0, 0,2}, /* core7 power_state bit51 */
			{    0, 0,2}, /* core7 power_state bit52 */
			{    0, 0,2}, /* core7 power_state bit53 */
			{    0, 0,2}, /* core7 power_state bit54 */
			{    0, 0,2}, /* core7 power_state bit55 */
			{    0, 0,2}, /* core7 power_state bit56 */
			{    0, 0,2}, /* core7 power_state bit57 */
			{    0, 0,2}, /* core7 power_state bit58 */
			{    0, 0,2}, /* core7 power_state bit59 */
			{    0, 0,2}, /* core7 power_state bit60 */
			{    0, 0,2}, /* core7 power_state bit61 */
			{    0, 0,2}, /* core7 power_state bit62 */
			{    0, 0,2}, /* core7 power_state bit63 */
			}},
	},
}; 

struct mcusys_spec mcusys[] = {
	{		/* core 0 */ 
			.M0_AR_Pending_Counter = {{
			{ 1736,14,0}, /* core0 M0_AR_Pending_Counter bit0 */
			{ 1735,14,0}, /* core0 M0_AR_Pending_Counter bit1 */
			{ 1734,14,0}, /* core0 M0_AR_Pending_Counter bit2 */
			{ 1733,14,0}, /* core0 M0_AR_Pending_Counter bit3 */
			{ 4199,16,0}, /* core0 M0_AR_Pending_Counter bit4 */
			{ 4198,16,0}, /* core0 M0_AR_Pending_Counter bit5 */
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
			.M1_AR_Pending_Counter = {{
			{ 1532,14,0}, /* core0 M1_AR_Pending_Counter bit0 */
			{ 1531,14,0}, /* core0 M1_AR_Pending_Counter bit1 */
			{ 1530,14,0}, /* core0 M1_AR_Pending_Counter bit2 */
			{ 1529,14,0}, /* core0 M1_AR_Pending_Counter bit3 */
			{ 4209,16,0}, /* core0 M1_AR_Pending_Counter bit4 */
			{ 4208,16,0}, /* core0 M1_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit63 */
			}},
			.M2_AR_Pending_Counter = {{
			{ 1728,14,0}, /* core0 M2_AR_Pending_Counter bit0 */
			{ 1727,14,0}, /* core0 M2_AR_Pending_Counter bit1 */
			{ 1726,14,0}, /* core0 M2_AR_Pending_Counter bit2 */
			{ 1725,14,0}, /* core0 M2_AR_Pending_Counter bit3 */
			{ 4205,16,0}, /* core0 M2_AR_Pending_Counter bit4 */
			{ 4204,16,0}, /* core0 M2_AR_Pending_Counter bit5 */
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
			{ 1732,14,0}, /* core0 M0_AW_Pending_Counter bit0 */
			{ 1731,14,0}, /* core0 M0_AW_Pending_Counter bit1 */
			{ 1730,14,0}, /* core0 M0_AW_Pending_Counter bit2 */
			{ 1729,14,0}, /* core0 M0_AW_Pending_Counter bit3 */
			{ 4201,16,0}, /* core0 M0_AW_Pending_Counter bit4 */
			{ 4200,16,0}, /* core0 M0_AW_Pending_Counter bit5 */
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
			.M1_AR_Pending_Counter = {{
			{ 1536,14,0}, /* core0 M1_AR_Pending_Counter bit0 */
			{ 1535,14,0}, /* core0 M1_AR_Pending_Counter bit1 */
			{ 1534,14,0}, /* core0 M1_AR_Pending_Counter bit2 */
			{ 1533,14,0}, /* core0 M1_AR_Pending_Counter bit3 */
			{ 4207,16,0}, /* core0 M1_AR_Pending_Counter bit4 */
			{ 4206,16,0}, /* core0 M1_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit63 */
			}},
			.M2_AW_Pending_Counter = {{
			{ 1724,14,0}, /* core0 M2_AW_Pending_Counter bit0 */
			{ 1723,14,0}, /* core0 M2_AW_Pending_Counter bit1 */
			{ 1722,14,0}, /* core0 M2_AW_Pending_Counter bit2 */
			{ 1721,14,0}, /* core0 M2_AW_Pending_Counter bit3 */
			{ 4203,16,0}, /* core0 M2_AW_Pending_Counter bit4 */
			{ 4202,16,0}, /* core0 M2_AW_Pending_Counter bit5 */
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
			{ 2305,16,0}, /* core0 S4_AR_Pending_Counter bit0 */
			{ 2306,16,0}, /* core0 S4_AR_Pending_Counter bit1 */
			{ 2307,16,0}, /* core0 S4_AR_Pending_Counter bit2 */
			{ 2308,16,0}, /* core0 S4_AR_Pending_Counter bit3 */
			{ 2309,16,0}, /* core0 S4_AR_Pending_Counter bit4 */
			{ 2310,16,0}, /* core0 S4_AR_Pending_Counter bit5 */
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
			{ 2322,16,0}, /* core0 S4_AW_Pending_Counter bit0 */
			{ 2330,16,0}, /* core0 S4_AW_Pending_Counter bit1 */
			{ 2326,16,0}, /* core0 S4_AW_Pending_Counter bit2 */
			{ 2329,16,0}, /* core0 S4_AW_Pending_Counter bit3 */
			{ 2328,16,0}, /* core0 S4_AW_Pending_Counter bit4 */
			{ 2327,16,0}, /* core0 S4_AW_Pending_Counter bit5 */
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
			.S3_AR_Pending_Counter = {{
			{ 2313,16,0}, /* core0 S3_AR_Pending_Counter bit0 */
			{ 2315,16,0}, /* core0 S3_AR_Pending_Counter bit1 */
			{ 2316,16,0}, /* core0 S3_AR_Pending_Counter bit2 */
			{ 2317,16,0}, /* core0 S3_AR_Pending_Counter bit3 */
			{ 2314,16,0}, /* core0 S3_AR_Pending_Counter bit4 */
			{ 2318,16,0}, /* core0 S3_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit63 */
			}},
			.S3_AW_Pending_Counter = {{
			{ 2331,16,0}, /* core0 S3_AW_Pending_Counter bit0 */
			{ 2332,16,0}, /* core0 S3_AW_Pending_Counter bit1 */
			{ 2333,16,0}, /* core0 S3_AW_Pending_Counter bit2 */
			{ 2334,16,0}, /* core0 S3_AW_Pending_Counter bit3 */
			{ 2336,16,0}, /* core0 S3_AW_Pending_Counter bit4 */
			{ 2335,16,0}, /* core0 S3_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit63 */
			}},
			.mp0_L3_parity_err = {{
			{  877, 5,0}, /* core0 mp0_L3_parity_err bit0 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit1 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit2 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit3 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit4 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit5 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit6 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit7 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit8 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit9 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit10 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit11 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit12 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit13 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit14 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit63 */
			}},
			.mp0_L3_parity_err_count = {{
			{ 2120, 5,0}, /* core0 mp0_L3_parity_err_count bit0 */
			{ 2119, 5,0}, /* core0 mp0_L3_parity_err_count bit1 */
			{ 2118, 5,0}, /* core0 mp0_L3_parity_err_count bit2 */
			{ 2117, 5,0}, /* core0 mp0_L3_parity_err_count bit3 */
			{ 2116, 5,0}, /* core0 mp0_L3_parity_err_count bit4 */
			{ 2115, 5,0}, /* core0 mp0_L3_parity_err_count bit5 */
			{ 2114, 5,0}, /* core0 mp0_L3_parity_err_count bit6 */
			{ 2113, 5,0}, /* core0 mp0_L3_parity_err_count bit7 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit8 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit9 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit10 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit11 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit12 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit13 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit14 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit63 */
			}},
			.mp0_L3_parity_sap = {{
			{  876, 5,0}, /* core0 mp0_L3_parity_sap bit0 */
			{  575, 7,0}, /* core0 mp0_L3_parity_sap bit1 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit2 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit3 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit4 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit5 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit6 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit7 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit8 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit9 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit10 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit11 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit12 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit13 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit14 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit63 */
			}},
			.mp0_L3_parity_index = {{
			{ 1873, 5,0}, /* core0 mp0_L3_parity_index bit0 */
			{ 1872, 5,0}, /* core0 mp0_L3_parity_index bit1 */
			{ 1871, 5,0}, /* core0 mp0_L3_parity_index bit2 */
			{ 1870, 5,0}, /* core0 mp0_L3_parity_index bit3 */
			{ 1869, 5,0}, /* core0 mp0_L3_parity_index bit4 */
			{ 1868, 5,0}, /* core0 mp0_L3_parity_index bit5 */
			{ 1867, 5,0}, /* core0 mp0_L3_parity_index bit6 */
			{ 1866, 5,0}, /* core0 mp0_L3_parity_index bit7 */
			{ 1865, 5,0}, /* core0 mp0_L3_parity_index bit8 */
			{ 1864, 5,0}, /* core0 mp0_L3_parity_index bit9 */
			{ 1863, 5,0}, /* core0 mp0_L3_parity_index bit10 */
			{ 1862, 5,0}, /* core0 mp0_L3_parity_index bit11 */
			{ 1861, 5,0}, /* core0 mp0_L3_parity_index bit12 */
			{ 1860, 5,0}, /* core0 mp0_L3_parity_index bit13 */
			{ 1859, 5,0}, /* core0 mp0_L3_parity_index bit14 */
			{ 1858, 5,0}, /* core0 mp0_L3_parity_index bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit63 */
			}},
			.mp0_L3_parity_bank = {{
			{ 1849, 5,0}, /* core0 mp0_L3_parity_bank bit0 */
			{ 1848, 5,0}, /* core0 mp0_L3_parity_bank bit1 */
			{ 1847, 5,0}, /* core0 mp0_L3_parity_bank bit2 */
			{ 1846, 5,0}, /* core0 mp0_L3_parity_bank bit3 */
			{ 1845, 5,0}, /* core0 mp0_L3_parity_bank bit4 */
			{ 1844, 5,0}, /* core0 mp0_L3_parity_bank bit5 */
			{ 1843, 5,0}, /* core0 mp0_L3_parity_bank bit6 */
			{ 1842, 5,0}, /* core0 mp0_L3_parity_bank bit7 */
			{ 1857, 5,0}, /* core0 mp0_L3_parity_bank bit8 */
			{ 1856, 5,0}, /* core0 mp0_L3_parity_bank bit9 */
			{ 1855, 5,0}, /* core0 mp0_L3_parity_bank bit10 */
			{ 1854, 5,0}, /* core0 mp0_L3_parity_bank bit11 */
			{ 1853, 5,0}, /* core0 mp0_L3_parity_bank bit12 */
			{ 1852, 5,0}, /* core0 mp0_L3_parity_bank bit13 */
			{ 1851, 5,0}, /* core0 mp0_L3_parity_bank bit14 */
			{ 1850, 5,0}, /* core0 mp0_L3_parity_bank bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit63 */
			}},
			.L2_parity_err = {{
			{ 6913, 8,0}, /* core0 L2_parity_err bit0 */
			{ 6912, 8,0}, /* core0 L2_parity_err bit1 */
			{ 6911, 8,0}, /* core0 L2_parity_err bit2 */
			{ 6910, 8,0}, /* core0 L2_parity_err bit3 */
			{ 6909, 8,0}, /* core0 L2_parity_err bit4 */
			{ 6908, 8,0}, /* core0 L2_parity_err bit5 */
			{ 6907, 8,0}, /* core0 L2_parity_err bit6 */
			{ 6906, 8,0}, /* core0 L2_parity_err bit7 */
			{    0, 0,2}, /* core0 L2_parity_err bit8 */
			{    0, 0,2}, /* core0 L2_parity_err bit9 */
			{    0, 0,2}, /* core0 L2_parity_err bit10 */
			{    0, 0,2}, /* core0 L2_parity_err bit11 */
			{    0, 0,2}, /* core0 L2_parity_err bit12 */
			{    0, 0,2}, /* core0 L2_parity_err bit13 */
			{    0, 0,2}, /* core0 L2_parity_err bit14 */
			{    0, 0,2}, /* core0 L2_parity_err bit15 */
			{    0, 0,2}, /* core0 L2_parity_err bit16 */
			{    0, 0,2}, /* core0 L2_parity_err bit17 */
			{    0, 0,2}, /* core0 L2_parity_err bit18 */
			{    0, 0,2}, /* core0 L2_parity_err bit19 */
			{    0, 0,2}, /* core0 L2_parity_err bit20 */
			{    0, 0,2}, /* core0 L2_parity_err bit21 */
			{    0, 0,2}, /* core0 L2_parity_err bit22 */
			{    0, 0,2}, /* core0 L2_parity_err bit23 */
			{    0, 0,2}, /* core0 L2_parity_err bit24 */
			{    0, 0,2}, /* core0 L2_parity_err bit25 */
			{    0, 0,2}, /* core0 L2_parity_err bit26 */
			{    0, 0,2}, /* core0 L2_parity_err bit27 */
			{    0, 0,2}, /* core0 L2_parity_err bit28 */
			{    0, 0,2}, /* core0 L2_parity_err bit29 */
			{    0, 0,2}, /* core0 L2_parity_err bit30 */
			{    0, 0,2}, /* core0 L2_parity_err bit31 */
			{    0, 0,2}, /* core0 L2_parity_err bit32 */
			{    0, 0,2}, /* core0 L2_parity_err bit33 */
			{    0, 0,2}, /* core0 L2_parity_err bit34 */
			{    0, 0,2}, /* core0 L2_parity_err bit35 */
			{    0, 0,2}, /* core0 L2_parity_err bit36 */
			{    0, 0,2}, /* core0 L2_parity_err bit37 */
			{    0, 0,2}, /* core0 L2_parity_err bit38 */
			{    0, 0,2}, /* core0 L2_parity_err bit39 */
			{    0, 0,2}, /* core0 L2_parity_err bit40 */
			{    0, 0,2}, /* core0 L2_parity_err bit41 */
			{    0, 0,2}, /* core0 L2_parity_err bit42 */
			{    0, 0,2}, /* core0 L2_parity_err bit43 */
			{    0, 0,2}, /* core0 L2_parity_err bit44 */
			{    0, 0,2}, /* core0 L2_parity_err bit45 */
			{    0, 0,2}, /* core0 L2_parity_err bit46 */
			{    0, 0,2}, /* core0 L2_parity_err bit47 */
			{    0, 0,2}, /* core0 L2_parity_err bit48 */
			{    0, 0,2}, /* core0 L2_parity_err bit49 */
			{    0, 0,2}, /* core0 L2_parity_err bit50 */
			{    0, 0,2}, /* core0 L2_parity_err bit51 */
			{    0, 0,2}, /* core0 L2_parity_err bit52 */
			{    0, 0,2}, /* core0 L2_parity_err bit53 */
			{    0, 0,2}, /* core0 L2_parity_err bit54 */
			{    0, 0,2}, /* core0 L2_parity_err bit55 */
			{    0, 0,2}, /* core0 L2_parity_err bit56 */
			{    0, 0,2}, /* core0 L2_parity_err bit57 */
			{    0, 0,2}, /* core0 L2_parity_err bit58 */
			{    0, 0,2}, /* core0 L2_parity_err bit59 */
			{    0, 0,2}, /* core0 L2_parity_err bit60 */
			{    0, 0,2}, /* core0 L2_parity_err bit61 */
			{    0, 0,2}, /* core0 L2_parity_err bit62 */
			{    0, 0,2}, /* core0 L2_parity_err bit63 */
			}},
			.dfd_v35_enable = {{
			{ 1945, 4,0}, /* core0 dfd_v35_enable bit0 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit1 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit2 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit3 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit4 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit5 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit6 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit7 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit8 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit9 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit10 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit11 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit12 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit13 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit14 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit15 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit16 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit17 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit18 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit19 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit20 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit21 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit22 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit23 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit24 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit25 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit26 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit27 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit28 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit29 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit30 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit31 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit32 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit33 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit34 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit35 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit36 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit37 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit38 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit39 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit40 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit41 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit42 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit43 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit44 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit45 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit46 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit47 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit48 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit49 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit50 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit51 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit52 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit53 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit54 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit55 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit56 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit57 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit58 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit59 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit60 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit61 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit62 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit63 */
			}},
	},
}; 

struct little_core_spec little_core[] = {
	{		/* core 0 */ 
			.pc = {{
			{  392,33,1}, /* core0 pc bit0 */
			{  391,33,1}, /* core0 pc bit1 */
			{  390,33,1}, /* core0 pc bit2 */
			{  389,33,1}, /* core0 pc bit3 */
			{  440,33,1}, /* core0 pc bit4 */
			{  416,33,1}, /* core0 pc bit5 */
			{  439,33,1}, /* core0 pc bit6 */
			{  415,33,1}, /* core0 pc bit7 */
			{  388,33,1}, /* core0 pc bit8 */
			{  414,33,1}, /* core0 pc bit9 */
			{  344,33,1}, /* core0 pc bit10 */
			{  360,33,1}, /* core0 pc bit11 */
			{  359,33,1}, /* core0 pc bit12 */
			{  358,33,1}, /* core0 pc bit13 */
			{  343,33,1}, /* core0 pc bit14 */
			{  342,33,1}, /* core0 pc bit15 */
			{  413,33,1}, /* core0 pc bit16 */
			{  296,33,1}, /* core0 pc bit17 */
			{  357,33,1}, /* core0 pc bit18 */
			{  387,33,1}, /* core0 pc bit19 */
			{  356,33,1}, /* core0 pc bit20 */
			{  355,33,1}, /* core0 pc bit21 */
			{  412,33,1}, /* core0 pc bit22 */
			{  354,33,1}, /* core0 pc bit23 */
			{  353,33,1}, /* core0 pc bit24 */
			{  376,33,1}, /* core0 pc bit25 */
			{  352,33,1}, /* core0 pc bit26 */
			{  295,33,1}, /* core0 pc bit27 */
			{  386,33,1}, /* core0 pc bit28 */
			{  341,33,1}, /* core0 pc bit29 */
			{  385,33,1}, /* core0 pc bit30 */
			{  351,33,1}, /* core0 pc bit31 */
			{  264,33,1}, /* core0 pc bit32 */
			{  112,33,1}, /* core0 pc bit33 */
			{  263,33,1}, /* core0 pc bit34 */
			{  111,33,1}, /* core0 pc bit35 */
			{  172,33,1}, /* core0 pc bit36 */
			{  180,33,1}, /* core0 pc bit37 */
			{  262,33,1}, /* core0 pc bit38 */
			{  146,33,1}, /* core0 pc bit39 */
			{  179,33,1}, /* core0 pc bit40 */
			{  145,33,1}, /* core0 pc bit41 */
			{  136,33,1}, /* core0 pc bit42 */
			{  261,33,1}, /* core0 pc bit43 */
			{  260,33,1}, /* core0 pc bit44 */
			{  259,33,1}, /* core0 pc bit45 */
			{  144,33,1}, /* core0 pc bit46 */
			{  143,33,1}, /* core0 pc bit47 */
			{  438,33,1}, /* core0 pc bit48 */
			{  110,33,1}, /* core0 pc bit49 */
			{  207,33,1}, /* core0 pc bit50 */
			{  206,33,1}, /* core0 pc bit51 */
			{  411,33,1}, /* core0 pc bit52 */
			{  205,33,1}, /* core0 pc bit53 */
			{  109,33,1}, /* core0 pc bit54 */
			{  204,33,1}, /* core0 pc bit55 */
			{  258,33,1}, /* core0 pc bit56 */
			{  203,33,1}, /* core0 pc bit57 */
			{  178,33,1}, /* core0 pc bit58 */
			{  177,33,1}, /* core0 pc bit59 */
			{  202,33,1}, /* core0 pc bit60 */
			{  201,33,1}, /* core0 pc bit61 */
			{  200,33,1}, /* core0 pc bit62 */
			{  257,33,1}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{37603,34,0}, /* core0 sp32 bit0 */
			{37602,34,0}, /* core0 sp32 bit1 */
			{28162,34,1}, /* core0 sp32 bit2 */
			{28161,34,1}, /* core0 sp32 bit3 */
			{28160,34,1}, /* core0 sp32 bit4 */
			{28092,34,1}, /* core0 sp32 bit5 */
			{28159,34,1}, /* core0 sp32 bit6 */
			{28091,34,1}, /* core0 sp32 bit7 */
			{37601,34,0}, /* core0 sp32 bit8 */
			{37600,34,0}, /* core0 sp32 bit9 */
			{28158,34,1}, /* core0 sp32 bit10 */
			{28151,34,1}, /* core0 sp32 bit11 */
			{37583,34,0}, /* core0 sp32 bit12 */
			{37582,34,0}, /* core0 sp32 bit13 */
			{37581,34,0}, /* core0 sp32 bit14 */
			{37580,34,0}, /* core0 sp32 bit15 */
			{28135,34,1}, /* core0 sp32 bit16 */
			{28150,34,1}, /* core0 sp32 bit17 */
			{28131,34,1}, /* core0 sp32 bit18 */
			{28132,34,1}, /* core0 sp32 bit19 */
			{28144,34,1}, /* core0 sp32 bit20 */
			{28133,34,1}, /* core0 sp32 bit21 */
			{31013,33,1}, /* core0 sp32 bit22 */
			{31012,33,1}, /* core0 sp32 bit23 */
			{28130,34,1}, /* core0 sp32 bit24 */
			{28134,34,1}, /* core0 sp32 bit25 */
			{31011,33,1}, /* core0 sp32 bit26 */
			{31010,33,1}, /* core0 sp32 bit27 */
			{37579,34,0}, /* core0 sp32 bit28 */
			{37578,34,0}, /* core0 sp32 bit29 */
			{37593,34,0}, /* core0 sp32 bit30 */
			{37592,34,0}, /* core0 sp32 bit31 */
			{30913,33,1}, /* core0 sp32 bit32 */
			{30912,33,1}, /* core0 sp32 bit33 */
			{30911,33,1}, /* core0 sp32 bit34 */
			{30910,33,1}, /* core0 sp32 bit35 */
			{37623,34,0}, /* core0 sp32 bit36 */
			{37622,34,0}, /* core0 sp32 bit37 */
			{28277,34,1}, /* core0 sp32 bit38 */
			{37709,34,0}, /* core0 sp32 bit39 */
			{28274,34,1}, /* core0 sp32 bit40 */
			{37611,34,0}, /* core0 sp32 bit41 */
			{37625,34,0}, /* core0 sp32 bit42 */
			{37624,34,0}, /* core0 sp32 bit43 */
			{37708,34,0}, /* core0 sp32 bit44 */
			{37711,34,0}, /* core0 sp32 bit45 */
			{37610,34,0}, /* core0 sp32 bit46 */
			{37710,34,0}, /* core0 sp32 bit47 */
			{28278,34,1}, /* core0 sp32 bit48 */
			{28300,34,1}, /* core0 sp32 bit49 */
			{28296,34,1}, /* core0 sp32 bit50 */
			{28302,34,1}, /* core0 sp32 bit51 */
			{28283,34,1}, /* core0 sp32 bit52 */
			{28170,34,1}, /* core0 sp32 bit53 */
			{28281,34,1}, /* core0 sp32 bit54 */
			{28310,34,1}, /* core0 sp32 bit55 */
			{28279,34,1}, /* core0 sp32 bit56 */
			{28301,34,1}, /* core0 sp32 bit57 */
			{28169,34,1}, /* core0 sp32 bit58 */
			{28303,34,1}, /* core0 sp32 bit59 */
			{28171,34,1}, /* core0 sp32 bit60 */
			{28168,34,1}, /* core0 sp32 bit61 */
			{28295,34,1}, /* core0 sp32 bit62 */
			{28297,34,1}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{28348,34,1}, /* core0 fp32 bit0 */
			{28349,34,1}, /* core0 fp32 bit1 */
			{37719,34,0}, /* core0 fp32 bit2 */
			{37718,34,0}, /* core0 fp32 bit3 */
			{37721,34,0}, /* core0 fp32 bit4 */
			{37720,34,0}, /* core0 fp32 bit5 */
			{28353,34,1}, /* core0 fp32 bit6 */
			{28351,34,1}, /* core0 fp32 bit7 */
			{28352,34,1}, /* core0 fp32 bit8 */
			{28350,34,1}, /* core0 fp32 bit9 */
			{37751,34,0}, /* core0 fp32 bit10 */
			{37750,34,0}, /* core0 fp32 bit11 */
			{37747,34,0}, /* core0 fp32 bit12 */
			{37746,34,0}, /* core0 fp32 bit13 */
			{31129,33,1}, /* core0 fp32 bit14 */
			{31128,33,1}, /* core0 fp32 bit15 */
			{31127,33,1}, /* core0 fp32 bit16 */
			{31126,33,1}, /* core0 fp32 bit17 */
			{37745,34,0}, /* core0 fp32 bit18 */
			{37744,34,0}, /* core0 fp32 bit19 */
			{31125,33,1}, /* core0 fp32 bit20 */
			{31124,33,1}, /* core0 fp32 bit21 */
			{28375,34,1}, /* core0 fp32 bit22 */
			{31123,33,1}, /* core0 fp32 bit23 */
			{31122,33,1}, /* core0 fp32 bit24 */
			{31121,33,1}, /* core0 fp32 bit25 */
			{31120,33,1}, /* core0 fp32 bit26 */
			{31119,33,1}, /* core0 fp32 bit27 */
			{31118,33,1}, /* core0 fp32 bit28 */
			{28374,34,1}, /* core0 fp32 bit29 */
			{37749,34,0}, /* core0 fp32 bit30 */
			{37748,34,0}, /* core0 fp32 bit31 */
			{37833,33,1}, /* core0 fp32 bit32 */
			{37832,33,1}, /* core0 fp32 bit33 */
			{37831,33,1}, /* core0 fp32 bit34 */
			{37830,33,1}, /* core0 fp32 bit35 */
			{28509,34,1}, /* core0 fp32 bit36 */
			{28510,34,1}, /* core0 fp32 bit37 */
			{37645,34,0}, /* core0 fp32 bit38 */
			{37829,33,1}, /* core0 fp32 bit39 */
			{37828,33,1}, /* core0 fp32 bit40 */
			{37644,34,0}, /* core0 fp32 bit41 */
			{37827,33,1}, /* core0 fp32 bit42 */
			{37641,34,0}, /* core0 fp32 bit43 */
			{37640,34,0}, /* core0 fp32 bit44 */
			{28508,34,1}, /* core0 fp32 bit45 */
			{28507,34,1}, /* core0 fp32 bit46 */
			{37643,34,0}, /* core0 fp32 bit47 */
			{37642,34,0}, /* core0 fp32 bit48 */
			{28511,34,1}, /* core0 fp32 bit49 */
			{28486,34,1}, /* core0 fp32 bit50 */
			{37826,33,1}, /* core0 fp32 bit51 */
			{28476,34,1}, /* core0 fp32 bit52 */
			{28472,34,1}, /* core0 fp32 bit53 */
			{28475,34,1}, /* core0 fp32 bit54 */
			{28489,34,1}, /* core0 fp32 bit55 */
			{28474,34,1}, /* core0 fp32 bit56 */
			{28453,34,1}, /* core0 fp32 bit57 */
			{28484,34,1}, /* core0 fp32 bit58 */
			{28454,34,1}, /* core0 fp32 bit59 */
			{28487,34,1}, /* core0 fp32 bit60 */
			{28488,34,1}, /* core0 fp32 bit61 */
			{28485,34,1}, /* core0 fp32 bit62 */
			{28473,34,1}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{28058,34,1}, /* core0 fp64 bit0 */
			{28057,34,1}, /* core0 fp64 bit1 */
			{28059,34,1}, /* core0 fp64 bit2 */
			{28054,34,1}, /* core0 fp64 bit3 */
			{31029,33,1}, /* core0 fp64 bit4 */
			{31028,33,1}, /* core0 fp64 bit5 */
			{31027,33,1}, /* core0 fp64 bit6 */
			{31026,33,1}, /* core0 fp64 bit7 */
			{28056,34,1}, /* core0 fp64 bit8 */
			{28055,34,1}, /* core0 fp64 bit9 */
			{37529,33,1}, /* core0 fp64 bit10 */
			{28060,34,1}, /* core0 fp64 bit11 */
			{27855,34,1}, /* core0 fp64 bit12 */
			{37528,33,1}, /* core0 fp64 bit13 */
			{37527,33,1}, /* core0 fp64 bit14 */
			{37526,33,1}, /* core0 fp64 bit15 */
			{30993,33,1}, /* core0 fp64 bit16 */
			{30992,33,1}, /* core0 fp64 bit17 */
			{37525,33,1}, /* core0 fp64 bit18 */
			{37524,33,1}, /* core0 fp64 bit19 */
			{37523,33,1}, /* core0 fp64 bit20 */
			{37522,33,1}, /* core0 fp64 bit21 */
			{30991,33,1}, /* core0 fp64 bit22 */
			{30990,33,1}, /* core0 fp64 bit23 */
			{27845,34,1}, /* core0 fp64 bit24 */
			{27843,34,1}, /* core0 fp64 bit25 */
			{27844,34,1}, /* core0 fp64 bit26 */
			{27842,34,1}, /* core0 fp64 bit27 */
			{37481,34,0}, /* core0 fp64 bit28 */
			{37480,34,0}, /* core0 fp64 bit29 */
			{37487,34,0}, /* core0 fp64 bit30 */
			{37486,34,0}, /* core0 fp64 bit31 */
			{30825,33,1}, /* core0 fp64 bit32 */
			{30837,33,1}, /* core0 fp64 bit33 */
			{30836,33,1}, /* core0 fp64 bit34 */
			{30835,33,1}, /* core0 fp64 bit35 */
			{30834,33,1}, /* core0 fp64 bit36 */
			{30824,33,1}, /* core0 fp64 bit37 */
			{30823,33,1}, /* core0 fp64 bit38 */
			{30822,33,1}, /* core0 fp64 bit39 */
			{27896,34,1}, /* core0 fp64 bit40 */
			{27982,34,1}, /* core0 fp64 bit41 */
			{37325,34,0}, /* core0 fp64 bit42 */
			{37324,34,0}, /* core0 fp64 bit43 */
			{30821,33,1}, /* core0 fp64 bit44 */
			{30820,33,1}, /* core0 fp64 bit45 */
			{27894,34,1}, /* core0 fp64 bit46 */
			{30819,33,1}, /* core0 fp64 bit47 */
			{27895,34,1}, /* core0 fp64 bit48 */
			{30818,33,1}, /* core0 fp64 bit49 */
			{30833,33,1}, /* core0 fp64 bit50 */
			{30832,33,1}, /* core0 fp64 bit51 */
			{30831,33,1}, /* core0 fp64 bit52 */
			{30830,33,1}, /* core0 fp64 bit53 */
			{30841,33,1}, /* core0 fp64 bit54 */
			{27983,34,1}, /* core0 fp64 bit55 */
			{30840,33,1}, /* core0 fp64 bit56 */
			{30839,33,1}, /* core0 fp64 bit57 */
			{27984,34,1}, /* core0 fp64 bit58 */
			{30838,33,1}, /* core0 fp64 bit59 */
			{30829,33,1}, /* core0 fp64 bit60 */
			{30828,33,1}, /* core0 fp64 bit61 */
			{30827,33,1}, /* core0 fp64 bit62 */
			{30826,33,1}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{28040,34,1}, /* core0 sp_EL0 bit0 */
			{28038,34,1}, /* core0 sp_EL0 bit1 */
			{28039,34,1}, /* core0 sp_EL0 bit2 */
			{28035,34,1}, /* core0 sp_EL0 bit3 */
			{28037,34,1}, /* core0 sp_EL0 bit4 */
			{28036,34,1}, /* core0 sp_EL0 bit5 */
			{37399,34,0}, /* core0 sp_EL0 bit6 */
			{37398,34,0}, /* core0 sp_EL0 bit7 */
			{37397,34,0}, /* core0 sp_EL0 bit8 */
			{37396,34,0}, /* core0 sp_EL0 bit9 */
			{27861,34,1}, /* core0 sp_EL0 bit10 */
			{28029,34,1}, /* core0 sp_EL0 bit11 */
			{27859,34,1}, /* core0 sp_EL0 bit12 */
			{27851,34,1}, /* core0 sp_EL0 bit13 */
			{37467,34,0}, /* core0 sp_EL0 bit14 */
			{37466,34,0}, /* core0 sp_EL0 bit15 */
			{27858,34,1}, /* core0 sp_EL0 bit16 */
			{27860,34,1}, /* core0 sp_EL0 bit17 */
			{37479,34,0}, /* core0 sp_EL0 bit18 */
			{37478,34,0}, /* core0 sp_EL0 bit19 */
			{37475,34,0}, /* core0 sp_EL0 bit20 */
			{37474,34,0}, /* core0 sp_EL0 bit21 */
			{37471,34,0}, /* core0 sp_EL0 bit22 */
			{37470,34,0}, /* core0 sp_EL0 bit23 */
			{30989,33,1}, /* core0 sp_EL0 bit24 */
			{30988,33,1}, /* core0 sp_EL0 bit25 */
			{30987,33,1}, /* core0 sp_EL0 bit26 */
			{30986,33,1}, /* core0 sp_EL0 bit27 */
			{37477,34,0}, /* core0 sp_EL0 bit28 */
			{37476,34,0}, /* core0 sp_EL0 bit29 */
			{27841,34,1}, /* core0 sp_EL0 bit30 */
			{28041,34,1}, /* core0 sp_EL0 bit31 */
			{37287,34,0}, /* core0 sp_EL0 bit32 */
			{37577,33,1}, /* core0 sp_EL0 bit33 */
			{37576,33,1}, /* core0 sp_EL0 bit34 */
			{37575,33,1}, /* core0 sp_EL0 bit35 */
			{37574,33,1}, /* core0 sp_EL0 bit36 */
			{37573,33,1}, /* core0 sp_EL0 bit37 */
			{37572,33,1}, /* core0 sp_EL0 bit38 */
			{37286,34,0}, /* core0 sp_EL0 bit39 */
			{37571,33,1}, /* core0 sp_EL0 bit40 */
			{37570,33,1}, /* core0 sp_EL0 bit41 */
			{37367,34,0}, /* core0 sp_EL0 bit42 */
			{37366,34,0}, /* core0 sp_EL0 bit43 */
			{37285,34,0}, /* core0 sp_EL0 bit44 */
			{37284,34,0}, /* core0 sp_EL0 bit45 */
			{27962,34,1}, /* core0 sp_EL0 bit46 */
			{27934,34,1}, /* core0 sp_EL0 bit47 */
			{37269,34,0}, /* core0 sp_EL0 bit48 */
			{37268,34,0}, /* core0 sp_EL0 bit49 */
			{37283,34,0}, /* core0 sp_EL0 bit50 */
			{37282,34,0}, /* core0 sp_EL0 bit51 */
			{37273,34,0}, /* core0 sp_EL0 bit52 */
			{37272,34,0}, /* core0 sp_EL0 bit53 */
			{37267,34,0}, /* core0 sp_EL0 bit54 */
			{37266,34,0}, /* core0 sp_EL0 bit55 */
			{37265,34,0}, /* core0 sp_EL0 bit56 */
			{37264,34,0}, /* core0 sp_EL0 bit57 */
			{30813,33,1}, /* core0 sp_EL0 bit58 */
			{30812,33,1}, /* core0 sp_EL0 bit59 */
			{37271,34,0}, /* core0 sp_EL0 bit60 */
			{37270,34,0}, /* core0 sp_EL0 bit61 */
			{30811,33,1}, /* core0 sp_EL0 bit62 */
			{30810,33,1}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{28034,34,1}, /* core0 sp_EL1 bit0 */
			{27881,34,1}, /* core0 sp_EL1 bit1 */
			{37395,34,0}, /* core0 sp_EL1 bit2 */
			{37394,34,0}, /* core0 sp_EL1 bit3 */
			{28032,34,1}, /* core0 sp_EL1 bit4 */
			{28033,34,1}, /* core0 sp_EL1 bit5 */
			{37393,34,0}, /* core0 sp_EL1 bit6 */
			{37392,34,0}, /* core0 sp_EL1 bit7 */
			{30569,33,1}, /* core0 sp_EL1 bit8 */
			{30568,33,1}, /* core0 sp_EL1 bit9 */
			{37465,34,0}, /* core0 sp_EL1 bit10 */
			{30567,33,1}, /* core0 sp_EL1 bit11 */
			{30566,33,1}, /* core0 sp_EL1 bit12 */
			{37464,34,0}, /* core0 sp_EL1 bit13 */
			{27863,34,1}, /* core0 sp_EL1 bit14 */
			{27864,34,1}, /* core0 sp_EL1 bit15 */
			{28030,34,1}, /* core0 sp_EL1 bit16 */
			{27862,34,1}, /* core0 sp_EL1 bit17 */
			{27836,34,1}, /* core0 sp_EL1 bit18 */
			{27839,34,1}, /* core0 sp_EL1 bit19 */
			{27838,34,1}, /* core0 sp_EL1 bit20 */
			{27837,34,1}, /* core0 sp_EL1 bit21 */
			{37493,34,0}, /* core0 sp_EL1 bit22 */
			{30597,33,1}, /* core0 sp_EL1 bit23 */
			{30596,33,1}, /* core0 sp_EL1 bit24 */
			{30595,33,1}, /* core0 sp_EL1 bit25 */
			{30594,33,1}, /* core0 sp_EL1 bit26 */
			{37492,34,0}, /* core0 sp_EL1 bit27 */
			{37495,34,0}, /* core0 sp_EL1 bit28 */
			{37494,34,0}, /* core0 sp_EL1 bit29 */
			{27840,34,1}, /* core0 sp_EL1 bit30 */
			{28031,34,1}, /* core0 sp_EL1 bit31 */
			{27935,34,1}, /* core0 sp_EL1 bit32 */
			{27963,34,1}, /* core0 sp_EL1 bit33 */
			{37365,34,0}, /* core0 sp_EL1 bit34 */
			{37364,34,0}, /* core0 sp_EL1 bit35 */
			{37363,34,0}, /* core0 sp_EL1 bit36 */
			{37362,34,0}, /* core0 sp_EL1 bit37 */
			{27966,34,1}, /* core0 sp_EL1 bit38 */
			{27931,34,1}, /* core0 sp_EL1 bit39 */
			{30653,33,1}, /* core0 sp_EL1 bit40 */
			{30652,33,1}, /* core0 sp_EL1 bit41 */
			{30651,33,1}, /* core0 sp_EL1 bit42 */
			{30650,33,1}, /* core0 sp_EL1 bit43 */
			{37279,34,0}, /* core0 sp_EL1 bit44 */
			{37278,34,0}, /* core0 sp_EL1 bit45 */
			{27964,34,1}, /* core0 sp_EL1 bit46 */
			{27933,34,1}, /* core0 sp_EL1 bit47 */
			{27932,34,1}, /* core0 sp_EL1 bit48 */
			{27965,34,1}, /* core0 sp_EL1 bit49 */
			{37281,34,0}, /* core0 sp_EL1 bit50 */
			{37280,34,0}, /* core0 sp_EL1 bit51 */
			{37275,34,0}, /* core0 sp_EL1 bit52 */
			{37274,34,0}, /* core0 sp_EL1 bit53 */
			{37263,34,0}, /* core0 sp_EL1 bit54 */
			{37262,34,0}, /* core0 sp_EL1 bit55 */
			{37261,34,0}, /* core0 sp_EL1 bit56 */
			{37260,34,0}, /* core0 sp_EL1 bit57 */
			{37349,34,0}, /* core0 sp_EL1 bit58 */
			{37348,34,0}, /* core0 sp_EL1 bit59 */
			{37353,34,0}, /* core0 sp_EL1 bit60 */
			{37352,34,0}, /* core0 sp_EL1 bit61 */
			{37277,34,0}, /* core0 sp_EL1 bit62 */
			{37276,34,0}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{28047,34,1}, /* core0 sp_EL2 bit0 */
			{28053,34,1}, /* core0 sp_EL2 bit1 */
			{28052,34,1}, /* core0 sp_EL2 bit2 */
			{28049,34,1}, /* core0 sp_EL2 bit3 */
			{28051,34,1}, /* core0 sp_EL2 bit4 */
			{28050,34,1}, /* core0 sp_EL2 bit5 */
			{28028,34,1}, /* core0 sp_EL2 bit6 */
			{28026,34,1}, /* core0 sp_EL2 bit7 */
			{28027,34,1}, /* core0 sp_EL2 bit8 */
			{28048,34,1}, /* core0 sp_EL2 bit9 */
			{27856,34,1}, /* core0 sp_EL2 bit10 */
			{28061,34,1}, /* core0 sp_EL2 bit11 */
			{27857,34,1}, /* core0 sp_EL2 bit12 */
			{27847,34,1}, /* core0 sp_EL2 bit13 */
			{27854,34,1}, /* core0 sp_EL2 bit14 */
			{37459,34,0}, /* core0 sp_EL2 bit15 */
			{37458,34,0}, /* core0 sp_EL2 bit16 */
			{27853,34,1}, /* core0 sp_EL2 bit17 */
			{37461,34,0}, /* core0 sp_EL2 bit18 */
			{37460,34,0}, /* core0 sp_EL2 bit19 */
			{27852,34,1}, /* core0 sp_EL2 bit20 */
			{27846,34,1}, /* core0 sp_EL2 bit21 */
			{30585,33,1}, /* core0 sp_EL2 bit22 */
			{30589,33,1}, /* core0 sp_EL2 bit23 */
			{30588,33,1}, /* core0 sp_EL2 bit24 */
			{30587,33,1}, /* core0 sp_EL2 bit25 */
			{30584,33,1}, /* core0 sp_EL2 bit26 */
			{30586,33,1}, /* core0 sp_EL2 bit27 */
			{30583,33,1}, /* core0 sp_EL2 bit28 */
			{37489,34,0}, /* core0 sp_EL2 bit29 */
			{37488,34,0}, /* core0 sp_EL2 bit30 */
			{30582,33,1}, /* core0 sp_EL2 bit31 */
			{37601,33,1}, /* core0 sp_EL2 bit32 */
			{30649,33,1}, /* core0 sp_EL2 bit33 */
			{30648,33,1}, /* core0 sp_EL2 bit34 */
			{30647,33,1}, /* core0 sp_EL2 bit35 */
			{30646,33,1}, /* core0 sp_EL2 bit36 */
			{37359,34,0}, /* core0 sp_EL2 bit37 */
			{37358,34,0}, /* core0 sp_EL2 bit38 */
			{37600,33,1}, /* core0 sp_EL2 bit39 */
			{37361,34,0}, /* core0 sp_EL2 bit40 */
			{37360,34,0}, /* core0 sp_EL2 bit41 */
			{30645,33,1}, /* core0 sp_EL2 bit42 */
			{30644,33,1}, /* core0 sp_EL2 bit43 */
			{37599,33,1}, /* core0 sp_EL2 bit44 */
			{37598,33,1}, /* core0 sp_EL2 bit45 */
			{30643,33,1}, /* core0 sp_EL2 bit46 */
			{37597,33,1}, /* core0 sp_EL2 bit47 */
			{37596,33,1}, /* core0 sp_EL2 bit48 */
			{30642,33,1}, /* core0 sp_EL2 bit49 */
			{37595,33,1}, /* core0 sp_EL2 bit50 */
			{37594,33,1}, /* core0 sp_EL2 bit51 */
			{37593,33,1}, /* core0 sp_EL2 bit52 */
			{37592,33,1}, /* core0 sp_EL2 bit53 */
			{27970,34,1}, /* core0 sp_EL2 bit54 */
			{37591,33,1}, /* core0 sp_EL2 bit55 */
			{27971,34,1}, /* core0 sp_EL2 bit56 */
			{37355,34,0}, /* core0 sp_EL2 bit57 */
			{37590,33,1}, /* core0 sp_EL2 bit58 */
			{37589,33,1}, /* core0 sp_EL2 bit59 */
			{37588,33,1}, /* core0 sp_EL2 bit60 */
			{37587,33,1}, /* core0 sp_EL2 bit61 */
			{37354,34,0}, /* core0 sp_EL2 bit62 */
			{37586,33,1}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{28045,34,1}, /* core0 sp_EL3 bit0 */
			{28046,34,1}, /* core0 sp_EL3 bit1 */
			{28044,34,1}, /* core0 sp_EL3 bit2 */
			{28043,34,1}, /* core0 sp_EL3 bit3 */
			{30573,33,1}, /* core0 sp_EL3 bit4 */
			{30572,33,1}, /* core0 sp_EL3 bit5 */
			{30571,33,1}, /* core0 sp_EL3 bit6 */
			{30570,33,1}, /* core0 sp_EL3 bit7 */
			{30577,33,1}, /* core0 sp_EL3 bit8 */
			{30576,33,1}, /* core0 sp_EL3 bit9 */
			{30575,33,1}, /* core0 sp_EL3 bit10 */
			{30574,33,1}, /* core0 sp_EL3 bit11 */
			{30581,33,1}, /* core0 sp_EL3 bit12 */
			{30580,33,1}, /* core0 sp_EL3 bit13 */
			{30579,33,1}, /* core0 sp_EL3 bit14 */
			{30578,33,1}, /* core0 sp_EL3 bit15 */
			{37463,34,0}, /* core0 sp_EL3 bit16 */
			{37462,34,0}, /* core0 sp_EL3 bit17 */
			{37473,34,0}, /* core0 sp_EL3 bit18 */
			{37472,34,0}, /* core0 sp_EL3 bit19 */
			{27850,34,1}, /* core0 sp_EL3 bit20 */
			{27848,34,1}, /* core0 sp_EL3 bit21 */
			{37469,34,0}, /* core0 sp_EL3 bit22 */
			{37468,34,0}, /* core0 sp_EL3 bit23 */
			{30593,33,1}, /* core0 sp_EL3 bit24 */
			{30592,33,1}, /* core0 sp_EL3 bit25 */
			{30591,33,1}, /* core0 sp_EL3 bit26 */
			{30590,33,1}, /* core0 sp_EL3 bit27 */
			{37491,34,0}, /* core0 sp_EL3 bit28 */
			{37490,34,0}, /* core0 sp_EL3 bit29 */
			{27849,34,1}, /* core0 sp_EL3 bit30 */
			{28042,34,1}, /* core0 sp_EL3 bit31 */
			{37289,34,0}, /* core0 sp_EL3 bit32 */
			{37585,33,1}, /* core0 sp_EL3 bit33 */
			{37584,33,1}, /* core0 sp_EL3 bit34 */
			{37583,33,1}, /* core0 sp_EL3 bit35 */
			{37582,33,1}, /* core0 sp_EL3 bit36 */
			{37581,33,1}, /* core0 sp_EL3 bit37 */
			{37580,33,1}, /* core0 sp_EL3 bit38 */
			{37288,34,0}, /* core0 sp_EL3 bit39 */
			{37579,33,1}, /* core0 sp_EL3 bit40 */
			{37578,33,1}, /* core0 sp_EL3 bit41 */
			{37357,34,0}, /* core0 sp_EL3 bit42 */
			{37356,34,0}, /* core0 sp_EL3 bit43 */
			{37347,34,0}, /* core0 sp_EL3 bit44 */
			{37346,34,0}, /* core0 sp_EL3 bit45 */
			{27969,34,1}, /* core0 sp_EL3 bit46 */
			{27974,34,1}, /* core0 sp_EL3 bit47 */
			{27973,34,1}, /* core0 sp_EL3 bit48 */
			{27967,34,1}, /* core0 sp_EL3 bit49 */
			{37351,34,0}, /* core0 sp_EL3 bit50 */
			{37350,34,0}, /* core0 sp_EL3 bit51 */
			{37259,34,0}, /* core0 sp_EL3 bit52 */
			{37258,34,0}, /* core0 sp_EL3 bit53 */
			{27968,34,1}, /* core0 sp_EL3 bit54 */
			{27972,34,1}, /* core0 sp_EL3 bit55 */
			{37078,34,0}, /* core0 sp_EL3 bit56 */
			{37077,34,0}, /* core0 sp_EL3 bit57 */
			{37074,34,0}, /* core0 sp_EL3 bit58 */
			{37073,34,0}, /* core0 sp_EL3 bit59 */
			{37076,34,0}, /* core0 sp_EL3 bit60 */
			{37075,34,0}, /* core0 sp_EL3 bit61 */
			{37072,34,0}, /* core0 sp_EL3 bit62 */
			{37071,34,0}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{37561,33,1}, /* core0 elr_EL1 bit0 */
			{37560,33,1}, /* core0 elr_EL1 bit1 */
			{37559,33,1}, /* core0 elr_EL1 bit2 */
			{37558,33,1}, /* core0 elr_EL1 bit3 */
			{37557,33,1}, /* core0 elr_EL1 bit4 */
			{37556,33,1}, /* core0 elr_EL1 bit5 */
			{37555,33,1}, /* core0 elr_EL1 bit6 */
			{37554,33,1}, /* core0 elr_EL1 bit7 */
			{37036,34,0}, /* core0 elr_EL1 bit8 */
			{37035,34,0}, /* core0 elr_EL1 bit9 */
			{30621,33,1}, /* core0 elr_EL1 bit10 */
			{30620,33,1}, /* core0 elr_EL1 bit11 */
			{37030,34,0}, /* core0 elr_EL1 bit12 */
			{37029,34,0}, /* core0 elr_EL1 bit13 */
			{37022,34,0}, /* core0 elr_EL1 bit14 */
			{37021,34,0}, /* core0 elr_EL1 bit15 */
			{30605,33,1}, /* core0 elr_EL1 bit16 */
			{30604,33,1}, /* core0 elr_EL1 bit17 */
			{30603,33,1}, /* core0 elr_EL1 bit18 */
			{30602,33,1}, /* core0 elr_EL1 bit19 */
			{37018,34,0}, /* core0 elr_EL1 bit20 */
			{37017,34,0}, /* core0 elr_EL1 bit21 */
			{30619,33,1}, /* core0 elr_EL1 bit22 */
			{30618,33,1}, /* core0 elr_EL1 bit23 */
			{30601,33,1}, /* core0 elr_EL1 bit24 */
			{30600,33,1}, /* core0 elr_EL1 bit25 */
			{30599,33,1}, /* core0 elr_EL1 bit26 */
			{30598,33,1}, /* core0 elr_EL1 bit27 */
			{37020,34,0}, /* core0 elr_EL1 bit28 */
			{37019,34,0}, /* core0 elr_EL1 bit29 */
			{37032,34,0}, /* core0 elr_EL1 bit30 */
			{37031,34,0}, /* core0 elr_EL1 bit31 */
			{27939,34,1}, /* core0 elr_EL1 bit32 */
			{27953,34,1}, /* core0 elr_EL1 bit33 */
			{37052,34,0}, /* core0 elr_EL1 bit34 */
			{37051,34,0}, /* core0 elr_EL1 bit35 */
			{37050,34,0}, /* core0 elr_EL1 bit36 */
			{37049,34,0}, /* core0 elr_EL1 bit37 */
			{27954,34,1}, /* core0 elr_EL1 bit38 */
			{27938,34,1}, /* core0 elr_EL1 bit39 */
			{30641,33,1}, /* core0 elr_EL1 bit40 */
			{30640,33,1}, /* core0 elr_EL1 bit41 */
			{30639,33,1}, /* core0 elr_EL1 bit42 */
			{30638,33,1}, /* core0 elr_EL1 bit43 */
			{37038,34,0}, /* core0 elr_EL1 bit44 */
			{37037,34,0}, /* core0 elr_EL1 bit45 */
			{27955,34,1}, /* core0 elr_EL1 bit46 */
			{27950,34,1}, /* core0 elr_EL1 bit47 */
			{27949,34,1}, /* core0 elr_EL1 bit48 */
			{27952,34,1}, /* core0 elr_EL1 bit49 */
			{37042,34,0}, /* core0 elr_EL1 bit50 */
			{37041,34,0}, /* core0 elr_EL1 bit51 */
			{37044,34,0}, /* core0 elr_EL1 bit52 */
			{37043,34,0}, /* core0 elr_EL1 bit53 */
			{37048,34,0}, /* core0 elr_EL1 bit54 */
			{37047,34,0}, /* core0 elr_EL1 bit55 */
			{37058,34,0}, /* core0 elr_EL1 bit56 */
			{37057,34,0}, /* core0 elr_EL1 bit57 */
			{37040,34,0}, /* core0 elr_EL1 bit58 */
			{37039,34,0}, /* core0 elr_EL1 bit59 */
			{37046,34,0}, /* core0 elr_EL1 bit60 */
			{37045,34,0}, /* core0 elr_EL1 bit61 */
			{27951,34,1}, /* core0 elr_EL1 bit62 */
			{27940,34,1}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{37553,33,1}, /* core0 elr_EL2 bit0 */
			{37552,33,1}, /* core0 elr_EL2 bit1 */
			{37551,33,1}, /* core0 elr_EL2 bit2 */
			{37550,33,1}, /* core0 elr_EL2 bit3 */
			{37549,33,1}, /* core0 elr_EL2 bit4 */
			{37548,33,1}, /* core0 elr_EL2 bit5 */
			{37547,33,1}, /* core0 elr_EL2 bit6 */
			{37546,33,1}, /* core0 elr_EL2 bit7 */
			{30629,33,1}, /* core0 elr_EL2 bit8 */
			{30628,33,1}, /* core0 elr_EL2 bit9 */
			{37537,33,1}, /* core0 elr_EL2 bit10 */
			{30627,33,1}, /* core0 elr_EL2 bit11 */
			{37536,33,1}, /* core0 elr_EL2 bit12 */
			{30626,33,1}, /* core0 elr_EL2 bit13 */
			{37535,33,1}, /* core0 elr_EL2 bit14 */
			{37534,33,1}, /* core0 elr_EL2 bit15 */
			{37533,33,1}, /* core0 elr_EL2 bit16 */
			{37532,33,1}, /* core0 elr_EL2 bit17 */
			{37531,33,1}, /* core0 elr_EL2 bit18 */
			{37530,33,1}, /* core0 elr_EL2 bit19 */
			{30609,33,1}, /* core0 elr_EL2 bit20 */
			{30608,33,1}, /* core0 elr_EL2 bit21 */
			{30607,33,1}, /* core0 elr_EL2 bit22 */
			{30606,33,1}, /* core0 elr_EL2 bit23 */
			{30613,33,1}, /* core0 elr_EL2 bit24 */
			{30612,33,1}, /* core0 elr_EL2 bit25 */
			{30611,33,1}, /* core0 elr_EL2 bit26 */
			{30610,33,1}, /* core0 elr_EL2 bit27 */
			{37024,34,0}, /* core0 elr_EL2 bit28 */
			{37023,34,0}, /* core0 elr_EL2 bit29 */
			{27873,34,1}, /* core0 elr_EL2 bit30 */
			{27878,34,1}, /* core0 elr_EL2 bit31 */
			{27943,34,1}, /* core0 elr_EL2 bit32 */
			{27956,34,1}, /* core0 elr_EL2 bit33 */
			{37054,34,0}, /* core0 elr_EL2 bit34 */
			{37053,34,0}, /* core0 elr_EL2 bit35 */
			{37056,34,0}, /* core0 elr_EL2 bit36 */
			{37055,34,0}, /* core0 elr_EL2 bit37 */
			{27957,34,1}, /* core0 elr_EL2 bit38 */
			{27942,34,1}, /* core0 elr_EL2 bit39 */
			{30637,33,1}, /* core0 elr_EL2 bit40 */
			{30636,33,1}, /* core0 elr_EL2 bit41 */
			{30635,33,1}, /* core0 elr_EL2 bit42 */
			{30634,33,1}, /* core0 elr_EL2 bit43 */
			{37070,34,0}, /* core0 elr_EL2 bit44 */
			{37069,34,0}, /* core0 elr_EL2 bit45 */
			{27958,34,1}, /* core0 elr_EL2 bit46 */
			{27948,34,1}, /* core0 elr_EL2 bit47 */
			{27947,34,1}, /* core0 elr_EL2 bit48 */
			{27959,34,1}, /* core0 elr_EL2 bit49 */
			{37066,34,0}, /* core0 elr_EL2 bit50 */
			{37065,34,0}, /* core0 elr_EL2 bit51 */
			{37062,34,0}, /* core0 elr_EL2 bit52 */
			{37061,34,0}, /* core0 elr_EL2 bit53 */
			{30633,33,1}, /* core0 elr_EL2 bit54 */
			{30632,33,1}, /* core0 elr_EL2 bit55 */
			{37060,34,0}, /* core0 elr_EL2 bit56 */
			{37059,34,0}, /* core0 elr_EL2 bit57 */
			{37068,34,0}, /* core0 elr_EL2 bit58 */
			{37067,34,0}, /* core0 elr_EL2 bit59 */
			{37064,34,0}, /* core0 elr_EL2 bit60 */
			{37063,34,0}, /* core0 elr_EL2 bit61 */
			{30631,33,1}, /* core0 elr_EL2 bit62 */
			{30630,33,1}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{37545,33,1}, /* core0 elr_EL3 bit0 */
			{37544,33,1}, /* core0 elr_EL3 bit1 */
			{37543,33,1}, /* core0 elr_EL3 bit2 */
			{37542,33,1}, /* core0 elr_EL3 bit3 */
			{37541,33,1}, /* core0 elr_EL3 bit4 */
			{37540,33,1}, /* core0 elr_EL3 bit5 */
			{37539,33,1}, /* core0 elr_EL3 bit6 */
			{37538,33,1}, /* core0 elr_EL3 bit7 */
			{37034,34,0}, /* core0 elr_EL3 bit8 */
			{37033,34,0}, /* core0 elr_EL3 bit9 */
			{30625,33,1}, /* core0 elr_EL3 bit10 */
			{30624,33,1}, /* core0 elr_EL3 bit11 */
			{30623,33,1}, /* core0 elr_EL3 bit12 */
			{30622,33,1}, /* core0 elr_EL3 bit13 */
			{37026,34,0}, /* core0 elr_EL3 bit14 */
			{37025,34,0}, /* core0 elr_EL3 bit15 */
			{37014,34,0}, /* core0 elr_EL3 bit16 */
			{37013,34,0}, /* core0 elr_EL3 bit17 */
			{27866,34,1}, /* core0 elr_EL3 bit18 */
			{27867,34,1}, /* core0 elr_EL3 bit19 */
			{30617,33,1}, /* core0 elr_EL3 bit20 */
			{30616,33,1}, /* core0 elr_EL3 bit21 */
			{30615,33,1}, /* core0 elr_EL3 bit22 */
			{30614,33,1}, /* core0 elr_EL3 bit23 */
			{27865,34,1}, /* core0 elr_EL3 bit24 */
			{27874,34,1}, /* core0 elr_EL3 bit25 */
			{37016,34,0}, /* core0 elr_EL3 bit26 */
			{37015,34,0}, /* core0 elr_EL3 bit27 */
			{37028,34,0}, /* core0 elr_EL3 bit28 */
			{37027,34,0}, /* core0 elr_EL3 bit29 */
			{27868,34,1}, /* core0 elr_EL3 bit30 */
			{27877,34,1}, /* core0 elr_EL3 bit31 */
			{30669,33,1}, /* core0 elr_EL3 bit32 */
			{30668,33,1}, /* core0 elr_EL3 bit33 */
			{30667,33,1}, /* core0 elr_EL3 bit34 */
			{30666,33,1}, /* core0 elr_EL3 bit35 */
			{30657,33,1}, /* core0 elr_EL3 bit36 */
			{30656,33,1}, /* core0 elr_EL3 bit37 */
			{30655,33,1}, /* core0 elr_EL3 bit38 */
			{30654,33,1}, /* core0 elr_EL3 bit39 */
			{37012,34,0}, /* core0 elr_EL3 bit40 */
			{37011,34,0}, /* core0 elr_EL3 bit41 */
			{27928,34,1}, /* core0 elr_EL3 bit42 */
			{27927,34,1}, /* core0 elr_EL3 bit43 */
			{30661,33,1}, /* core0 elr_EL3 bit44 */
			{30660,33,1}, /* core0 elr_EL3 bit45 */
			{30659,33,1}, /* core0 elr_EL3 bit46 */
			{30658,33,1}, /* core0 elr_EL3 bit47 */
			{30665,33,1}, /* core0 elr_EL3 bit48 */
			{30664,33,1}, /* core0 elr_EL3 bit49 */
			{30663,33,1}, /* core0 elr_EL3 bit50 */
			{30662,33,1}, /* core0 elr_EL3 bit51 */
			{30565,33,1}, /* core0 elr_EL3 bit52 */
			{30564,33,1}, /* core0 elr_EL3 bit53 */
			{30563,33,1}, /* core0 elr_EL3 bit54 */
			{30562,33,1}, /* core0 elr_EL3 bit55 */
			{37513,33,1}, /* core0 elr_EL3 bit56 */
			{37512,33,1}, /* core0 elr_EL3 bit57 */
			{37511,33,1}, /* core0 elr_EL3 bit58 */
			{37510,33,1}, /* core0 elr_EL3 bit59 */
			{37509,33,1}, /* core0 elr_EL3 bit60 */
			{37508,33,1}, /* core0 elr_EL3 bit61 */
			{37507,33,1}, /* core0 elr_EL3 bit62 */
			{37506,33,1}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31320,34,1}, /* core0 raw_pc bit0 */
			{31430,34,1}, /* core0 raw_pc bit1 */
			{32637,33,1}, /* core0 raw_pc bit2 */
			{32636,33,1}, /* core0 raw_pc bit3 */
			{32635,33,1}, /* core0 raw_pc bit4 */
			{32634,33,1}, /* core0 raw_pc bit5 */
			{31328,34,1}, /* core0 raw_pc bit6 */
			{39377,33,1}, /* core0 raw_pc bit7 */
			{39376,33,1}, /* core0 raw_pc bit8 */
			{39375,33,1}, /* core0 raw_pc bit9 */
			{39374,33,1}, /* core0 raw_pc bit10 */
			{39373,33,1}, /* core0 raw_pc bit11 */
			{39372,33,1}, /* core0 raw_pc bit12 */
			{39371,33,1}, /* core0 raw_pc bit13 */
			{39370,33,1}, /* core0 raw_pc bit14 */
			{39305,33,1}, /* core0 raw_pc bit15 */
			{39304,33,1}, /* core0 raw_pc bit16 */
			{39303,33,1}, /* core0 raw_pc bit17 */
			{39302,33,1}, /* core0 raw_pc bit18 */
			{39301,33,1}, /* core0 raw_pc bit19 */
			{39300,33,1}, /* core0 raw_pc bit20 */
			{39299,33,1}, /* core0 raw_pc bit21 */
			{39298,33,1}, /* core0 raw_pc bit22 */
			{39313,33,1}, /* core0 raw_pc bit23 */
			{39312,33,1}, /* core0 raw_pc bit24 */
			{39311,33,1}, /* core0 raw_pc bit25 */
			{39310,33,1}, /* core0 raw_pc bit26 */
			{39309,33,1}, /* core0 raw_pc bit27 */
			{39308,33,1}, /* core0 raw_pc bit28 */
			{39307,33,1}, /* core0 raw_pc bit29 */
			{39306,33,1}, /* core0 raw_pc bit30 */
			{39369,33,1}, /* core0 raw_pc bit31 */
			{39368,33,1}, /* core0 raw_pc bit32 */
			{39367,33,1}, /* core0 raw_pc bit33 */
			{39366,33,1}, /* core0 raw_pc bit34 */
			{39365,33,1}, /* core0 raw_pc bit35 */
			{39364,33,1}, /* core0 raw_pc bit36 */
			{39363,33,1}, /* core0 raw_pc bit37 */
			{39362,33,1}, /* core0 raw_pc bit38 */
			{39361,33,1}, /* core0 raw_pc bit39 */
			{39360,33,1}, /* core0 raw_pc bit40 */
			{39359,33,1}, /* core0 raw_pc bit41 */
			{39358,33,1}, /* core0 raw_pc bit42 */
			{39357,33,1}, /* core0 raw_pc bit43 */
			{39356,33,1}, /* core0 raw_pc bit44 */
			{39355,33,1}, /* core0 raw_pc bit45 */
			{39354,33,1}, /* core0 raw_pc bit46 */
			{38933,34,1}, /* core0 raw_pc bit47 */
			{38932,34,1}, /* core0 raw_pc bit48 */
			{31321,34,1}, /* core0 raw_pc bit49 */
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
			{31564,34,1}, /* core0 pc_iss bit0 */
			{31566,34,1}, /* core0 pc_iss bit1 */
			{38983,34,1}, /* core0 pc_iss bit2 */
			{38982,34,1}, /* core0 pc_iss bit3 */
			{32597,33,1}, /* core0 pc_iss bit4 */
			{32596,33,1}, /* core0 pc_iss bit5 */
			{32595,33,1}, /* core0 pc_iss bit6 */
			{32594,33,1}, /* core0 pc_iss bit7 */
			{31651,34,0}, /* core0 pc_iss bit8 */
			{31556,34,1}, /* core0 pc_iss bit9 */
			{31563,34,1}, /* core0 pc_iss bit10 */
			{31654,34,0}, /* core0 pc_iss bit11 */
			{31559,34,1}, /* core0 pc_iss bit12 */
			{31659,34,0}, /* core0 pc_iss bit13 */
			{31658,34,0}, /* core0 pc_iss bit14 */
			{31655,34,0}, /* core0 pc_iss bit15 */
			{31557,34,1}, /* core0 pc_iss bit16 */
			{31656,34,0}, /* core0 pc_iss bit17 */
			{31657,34,0}, /* core0 pc_iss bit18 */
			{31558,34,1}, /* core0 pc_iss bit19 */
			{32605,33,1}, /* core0 pc_iss bit20 */
			{32604,33,1}, /* core0 pc_iss bit21 */
			{32603,33,1}, /* core0 pc_iss bit22 */
			{32602,33,1}, /* core0 pc_iss bit23 */
			{38985,34,1}, /* core0 pc_iss bit24 */
			{38984,34,1}, /* core0 pc_iss bit25 */
			{31652,34,0}, /* core0 pc_iss bit26 */
			{31555,34,1}, /* core0 pc_iss bit27 */
			{32609,33,1}, /* core0 pc_iss bit28 */
			{32608,33,1}, /* core0 pc_iss bit29 */
			{32607,33,1}, /* core0 pc_iss bit30 */
			{32606,33,1}, /* core0 pc_iss bit31 */
			{31554,34,1}, /* core0 pc_iss bit32 */
			{31553,34,1}, /* core0 pc_iss bit33 */
			{38981,34,1}, /* core0 pc_iss bit34 */
			{38980,34,1}, /* core0 pc_iss bit35 */
			{32613,33,1}, /* core0 pc_iss bit36 */
			{32612,33,1}, /* core0 pc_iss bit37 */
			{32611,33,1}, /* core0 pc_iss bit38 */
			{32610,33,1}, /* core0 pc_iss bit39 */
			{39401,33,1}, /* core0 pc_iss bit40 */
			{39400,33,1}, /* core0 pc_iss bit41 */
			{39399,33,1}, /* core0 pc_iss bit42 */
			{39398,33,1}, /* core0 pc_iss bit43 */
			{39397,33,1}, /* core0 pc_iss bit44 */
			{39396,33,1}, /* core0 pc_iss bit45 */
			{39395,33,1}, /* core0 pc_iss bit46 */
			{39394,33,1}, /* core0 pc_iss bit47 */
			{32593,33,1}, /* core0 pc_iss bit48 */
			{32592,33,1}, /* core0 pc_iss bit49 */
			{32591,33,1}, /* core0 pc_iss bit50 */
			{32590,33,1}, /* core0 pc_iss bit51 */
			{38979,34,1}, /* core0 pc_iss bit52 */
			{38978,34,1}, /* core0 pc_iss bit53 */
			{31455,34,1}, /* core0 pc_iss bit54 */
			{31456,34,1}, /* core0 pc_iss bit55 */
			{31457,34,1}, /* core0 pc_iss bit56 */
			{31454,34,1}, /* core0 pc_iss bit57 */
			{31551,34,1}, /* core0 pc_iss bit58 */
			{31452,34,1}, /* core0 pc_iss bit59 */
			{31552,34,1}, /* core0 pc_iss bit60 */
			{31453,34,1}, /* core0 pc_iss bit61 */
			{38977,34,1}, /* core0 pc_iss bit62 */
			{38976,34,1}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31605,34,0}, /* core0 full_pc_wr bit0 */
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
			{31612,34,0}, /* core0 full_pc_ex1 bit0 */
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
			{32625,33,1}, /* core0 full_pc_ex2 bit0 */
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
			{16480,34,0}, /* core0 return_Stack_pointer bit0 */
			{16473,34,0}, /* core0 return_Stack_pointer bit1 */
			{16474,34,0}, /* core0 return_Stack_pointer bit2 */
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
			{20540,34,0}, /* core0 return_Stack0 bit0 */
			{20539,34,0}, /* core0 return_Stack0 bit1 */
			{20538,34,0}, /* core0 return_Stack0 bit2 */
			{20537,34,0}, /* core0 return_Stack0 bit3 */
			{20536,34,0}, /* core0 return_Stack0 bit4 */
			{20535,34,0}, /* core0 return_Stack0 bit5 */
			{20534,34,0}, /* core0 return_Stack0 bit6 */
			{20568,34,0}, /* core0 return_Stack0 bit7 */
			{20567,34,0}, /* core0 return_Stack0 bit8 */
			{20566,34,0}, /* core0 return_Stack0 bit9 */
			{20565,34,0}, /* core0 return_Stack0 bit10 */
			{20588,34,0}, /* core0 return_Stack0 bit11 */
			{20587,34,0}, /* core0 return_Stack0 bit12 */
			{20586,34,0}, /* core0 return_Stack0 bit13 */
			{20585,34,0}, /* core0 return_Stack0 bit14 */
			{20584,34,0}, /* core0 return_Stack0 bit15 */
			{20583,34,0}, /* core0 return_Stack0 bit16 */
			{20582,34,0}, /* core0 return_Stack0 bit17 */
			{20581,34,0}, /* core0 return_Stack0 bit18 */
			{20612,34,0}, /* core0 return_Stack0 bit19 */
			{20611,34,0}, /* core0 return_Stack0 bit20 */
			{20610,34,0}, /* core0 return_Stack0 bit21 */
			{20609,34,0}, /* core0 return_Stack0 bit22 */
			{20608,34,0}, /* core0 return_Stack0 bit23 */
			{20607,34,0}, /* core0 return_Stack0 bit24 */
			{20606,34,0}, /* core0 return_Stack0 bit25 */
			{20605,34,0}, /* core0 return_Stack0 bit26 */
			{20528,34,0}, /* core0 return_Stack0 bit27 */
			{20527,34,0}, /* core0 return_Stack0 bit28 */
			{20526,34,0}, /* core0 return_Stack0 bit29 */
			{20533,34,0}, /* core0 return_Stack0 bit30 */
			{16458,34,0}, /* core0 return_Stack0 bit31 */
			{20525,34,0}, /* core0 return_Stack0 bit32 */
			{16457,34,0}, /* core0 return_Stack0 bit33 */
			{16460,34,0}, /* core0 return_Stack0 bit34 */
			{16459,34,0}, /* core0 return_Stack0 bit35 */
			{20504,34,0}, /* core0 return_Stack0 bit36 */
			{20503,34,0}, /* core0 return_Stack0 bit37 */
			{20502,34,0}, /* core0 return_Stack0 bit38 */
			{20501,34,0}, /* core0 return_Stack0 bit39 */
			{20500,34,0}, /* core0 return_Stack0 bit40 */
			{20499,34,0}, /* core0 return_Stack0 bit41 */
			{20498,34,0}, /* core0 return_Stack0 bit42 */
			{20497,34,0}, /* core0 return_Stack0 bit43 */
			{20496,34,0}, /* core0 return_Stack0 bit44 */
			{20495,34,0}, /* core0 return_Stack0 bit45 */
			{20494,34,0}, /* core0 return_Stack0 bit46 */
			{20493,34,0}, /* core0 return_Stack0 bit47 */
			{13577,34,1}, /* core0 return_Stack0 bit48 */
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
			{20548,34,0}, /* core0 return_Stack1 bit0 */
			{20547,34,0}, /* core0 return_Stack1 bit1 */
			{20546,34,0}, /* core0 return_Stack1 bit2 */
			{20545,34,0}, /* core0 return_Stack1 bit3 */
			{20552,34,0}, /* core0 return_Stack1 bit4 */
			{20551,34,0}, /* core0 return_Stack1 bit5 */
			{20550,34,0}, /* core0 return_Stack1 bit6 */
			{20564,34,0}, /* core0 return_Stack1 bit7 */
			{20563,34,0}, /* core0 return_Stack1 bit8 */
			{20562,34,0}, /* core0 return_Stack1 bit9 */
			{20561,34,0}, /* core0 return_Stack1 bit10 */
			{20592,34,0}, /* core0 return_Stack1 bit11 */
			{20591,34,0}, /* core0 return_Stack1 bit12 */
			{20590,34,0}, /* core0 return_Stack1 bit13 */
			{20589,34,0}, /* core0 return_Stack1 bit14 */
			{20600,34,0}, /* core0 return_Stack1 bit15 */
			{20599,34,0}, /* core0 return_Stack1 bit16 */
			{20598,34,0}, /* core0 return_Stack1 bit17 */
			{20597,34,0}, /* core0 return_Stack1 bit18 */
			{20580,34,0}, /* core0 return_Stack1 bit19 */
			{20579,34,0}, /* core0 return_Stack1 bit20 */
			{20578,34,0}, /* core0 return_Stack1 bit21 */
			{20577,34,0}, /* core0 return_Stack1 bit22 */
			{20572,34,0}, /* core0 return_Stack1 bit23 */
			{20571,34,0}, /* core0 return_Stack1 bit24 */
			{20570,34,0}, /* core0 return_Stack1 bit25 */
			{20569,34,0}, /* core0 return_Stack1 bit26 */
			{20532,34,0}, /* core0 return_Stack1 bit27 */
			{20531,34,0}, /* core0 return_Stack1 bit28 */
			{20530,34,0}, /* core0 return_Stack1 bit29 */
			{20529,34,0}, /* core0 return_Stack1 bit30 */
			{20549,34,0}, /* core0 return_Stack1 bit31 */
			{13574,34,1}, /* core0 return_Stack1 bit32 */
			{20520,34,0}, /* core0 return_Stack1 bit33 */
			{20519,34,0}, /* core0 return_Stack1 bit34 */
			{20518,34,0}, /* core0 return_Stack1 bit35 */
			{20517,34,0}, /* core0 return_Stack1 bit36 */
			{20516,34,0}, /* core0 return_Stack1 bit37 */
			{20515,34,0}, /* core0 return_Stack1 bit38 */
			{20514,34,0}, /* core0 return_Stack1 bit39 */
			{20513,34,0}, /* core0 return_Stack1 bit40 */
			{20492,34,0}, /* core0 return_Stack1 bit41 */
			{20491,34,0}, /* core0 return_Stack1 bit42 */
			{20490,34,0}, /* core0 return_Stack1 bit43 */
			{20489,34,0}, /* core0 return_Stack1 bit44 */
			{20488,34,0}, /* core0 return_Stack1 bit45 */
			{20487,34,0}, /* core0 return_Stack1 bit46 */
			{20486,34,0}, /* core0 return_Stack1 bit47 */
			{20485,34,0}, /* core0 return_Stack1 bit48 */
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
			{20544,34,0}, /* core0 return_Stack2 bit0 */
			{20543,34,0}, /* core0 return_Stack2 bit1 */
			{20542,34,0}, /* core0 return_Stack2 bit2 */
			{20541,34,0}, /* core0 return_Stack2 bit3 */
			{20556,34,0}, /* core0 return_Stack2 bit4 */
			{20555,34,0}, /* core0 return_Stack2 bit5 */
			{20554,34,0}, /* core0 return_Stack2 bit6 */
			{20553,34,0}, /* core0 return_Stack2 bit7 */
			{20560,34,0}, /* core0 return_Stack2 bit8 */
			{20559,34,0}, /* core0 return_Stack2 bit9 */
			{20558,34,0}, /* core0 return_Stack2 bit10 */
			{20557,34,0}, /* core0 return_Stack2 bit11 */
			{20596,34,0}, /* core0 return_Stack2 bit12 */
			{20595,34,0}, /* core0 return_Stack2 bit13 */
			{16346,34,0}, /* core0 return_Stack2 bit14 */
			{20594,34,0}, /* core0 return_Stack2 bit15 */
			{16345,34,0}, /* core0 return_Stack2 bit16 */
			{20593,34,0}, /* core0 return_Stack2 bit17 */
			{16344,34,0}, /* core0 return_Stack2 bit18 */
			{20576,34,0}, /* core0 return_Stack2 bit19 */
			{20575,34,0}, /* core0 return_Stack2 bit20 */
			{20574,34,0}, /* core0 return_Stack2 bit21 */
			{20573,34,0}, /* core0 return_Stack2 bit22 */
			{20604,34,0}, /* core0 return_Stack2 bit23 */
			{20603,34,0}, /* core0 return_Stack2 bit24 */
			{20602,34,0}, /* core0 return_Stack2 bit25 */
			{20601,34,0}, /* core0 return_Stack2 bit26 */
			{16343,34,0}, /* core0 return_Stack2 bit27 */
			{16512,34,0}, /* core0 return_Stack2 bit28 */
			{16511,34,0}, /* core0 return_Stack2 bit29 */
			{20524,34,0}, /* core0 return_Stack2 bit30 */
			{20523,34,0}, /* core0 return_Stack2 bit31 */
			{13573,34,1}, /* core0 return_Stack2 bit32 */
			{20522,34,0}, /* core0 return_Stack2 bit33 */
			{20521,34,0}, /* core0 return_Stack2 bit34 */
			{20512,34,0}, /* core0 return_Stack2 bit35 */
			{20511,34,0}, /* core0 return_Stack2 bit36 */
			{20510,34,0}, /* core0 return_Stack2 bit37 */
			{20509,34,0}, /* core0 return_Stack2 bit38 */
			{20508,34,0}, /* core0 return_Stack2 bit39 */
			{20507,34,0}, /* core0 return_Stack2 bit40 */
			{20506,34,0}, /* core0 return_Stack2 bit41 */
			{20505,34,0}, /* core0 return_Stack2 bit42 */
			{20460,34,0}, /* core0 return_Stack2 bit43 */
			{20459,34,0}, /* core0 return_Stack2 bit44 */
			{20458,34,0}, /* core0 return_Stack2 bit45 */
			{20457,34,0}, /* core0 return_Stack2 bit46 */
			{13583,34,1}, /* core0 return_Stack2 bit47 */
			{13584,34,1}, /* core0 return_Stack2 bit48 */
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
			{20362,34,0}, /* core0 return_Stack3 bit0 */
			{20361,34,0}, /* core0 return_Stack3 bit1 */
			{20360,34,0}, /* core0 return_Stack3 bit2 */
			{20359,34,0}, /* core0 return_Stack3 bit3 */
			{20270,34,0}, /* core0 return_Stack3 bit4 */
			{20269,34,0}, /* core0 return_Stack3 bit5 */
			{20366,34,0}, /* core0 return_Stack3 bit6 */
			{20268,34,0}, /* core0 return_Stack3 bit7 */
			{20267,34,0}, /* core0 return_Stack3 bit8 */
			{20418,34,0}, /* core0 return_Stack3 bit9 */
			{20417,34,0}, /* core0 return_Stack3 bit10 */
			{20416,34,0}, /* core0 return_Stack3 bit11 */
			{20415,34,0}, /* core0 return_Stack3 bit12 */
			{16362,34,0}, /* core0 return_Stack3 bit13 */
			{16361,34,0}, /* core0 return_Stack3 bit14 */
			{16360,34,0}, /* core0 return_Stack3 bit15 */
			{16359,34,0}, /* core0 return_Stack3 bit16 */
			{16338,34,0}, /* core0 return_Stack3 bit17 */
			{16337,34,0}, /* core0 return_Stack3 bit18 */
			{16340,34,0}, /* core0 return_Stack3 bit19 */
			{16339,34,0}, /* core0 return_Stack3 bit20 */
			{16498,34,0}, /* core0 return_Stack3 bit21 */
			{16497,34,0}, /* core0 return_Stack3 bit22 */
			{16500,34,0}, /* core0 return_Stack3 bit23 */
			{16499,34,0}, /* core0 return_Stack3 bit24 */
			{16504,34,0}, /* core0 return_Stack3 bit25 */
			{16503,34,0}, /* core0 return_Stack3 bit26 */
			{16508,34,0}, /* core0 return_Stack3 bit27 */
			{16507,34,0}, /* core0 return_Stack3 bit28 */
			{16518,34,0}, /* core0 return_Stack3 bit29 */
			{20365,34,0}, /* core0 return_Stack3 bit30 */
			{20364,34,0}, /* core0 return_Stack3 bit31 */
			{16517,34,0}, /* core0 return_Stack3 bit32 */
			{20363,34,0}, /* core0 return_Stack3 bit33 */
			{20310,34,0}, /* core0 return_Stack3 bit34 */
			{20309,34,0}, /* core0 return_Stack3 bit35 */
			{20308,34,0}, /* core0 return_Stack3 bit36 */
			{20307,34,0}, /* core0 return_Stack3 bit37 */
			{20318,34,0}, /* core0 return_Stack3 bit38 */
			{20317,34,0}, /* core0 return_Stack3 bit39 */
			{20316,34,0}, /* core0 return_Stack3 bit40 */
			{20315,34,0}, /* core0 return_Stack3 bit41 */
			{20342,34,0}, /* core0 return_Stack3 bit42 */
			{20341,34,0}, /* core0 return_Stack3 bit43 */
			{20340,34,0}, /* core0 return_Stack3 bit44 */
			{20339,34,0}, /* core0 return_Stack3 bit45 */
			{16440,34,0}, /* core0 return_Stack3 bit46 */
			{16439,34,0}, /* core0 return_Stack3 bit47 */
			{13581,34,1}, /* core0 return_Stack3 bit48 */
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
			{20370,34,0}, /* core0 return_Stack4 bit0 */
			{20369,34,0}, /* core0 return_Stack4 bit1 */
			{20368,34,0}, /* core0 return_Stack4 bit2 */
			{20367,34,0}, /* core0 return_Stack4 bit3 */
			{20374,34,0}, /* core0 return_Stack4 bit4 */
			{20373,34,0}, /* core0 return_Stack4 bit5 */
			{20372,34,0}, /* core0 return_Stack4 bit6 */
			{20371,34,0}, /* core0 return_Stack4 bit7 */
			{20378,34,0}, /* core0 return_Stack4 bit8 */
			{20377,34,0}, /* core0 return_Stack4 bit9 */
			{20376,34,0}, /* core0 return_Stack4 bit10 */
			{20375,34,0}, /* core0 return_Stack4 bit11 */
			{20398,34,0}, /* core0 return_Stack4 bit12 */
			{20397,34,0}, /* core0 return_Stack4 bit13 */
			{20396,34,0}, /* core0 return_Stack4 bit14 */
			{20395,34,0}, /* core0 return_Stack4 bit15 */
			{20394,34,0}, /* core0 return_Stack4 bit16 */
			{20393,34,0}, /* core0 return_Stack4 bit17 */
			{20392,34,0}, /* core0 return_Stack4 bit18 */
			{20391,34,0}, /* core0 return_Stack4 bit19 */
			{20430,34,0}, /* core0 return_Stack4 bit20 */
			{20429,34,0}, /* core0 return_Stack4 bit21 */
			{20428,34,0}, /* core0 return_Stack4 bit22 */
			{20427,34,0}, /* core0 return_Stack4 bit23 */
			{20434,34,0}, /* core0 return_Stack4 bit24 */
			{20433,34,0}, /* core0 return_Stack4 bit25 */
			{20432,34,0}, /* core0 return_Stack4 bit26 */
			{20431,34,0}, /* core0 return_Stack4 bit27 */
			{16506,34,0}, /* core0 return_Stack4 bit28 */
			{16505,34,0}, /* core0 return_Stack4 bit29 */
			{16456,34,0}, /* core0 return_Stack4 bit30 */
			{16455,34,0}, /* core0 return_Stack4 bit31 */
			{16454,34,0}, /* core0 return_Stack4 bit32 */
			{16453,34,0}, /* core0 return_Stack4 bit33 */
			{16446,34,0}, /* core0 return_Stack4 bit34 */
			{20314,34,0}, /* core0 return_Stack4 bit35 */
			{20313,34,0}, /* core0 return_Stack4 bit36 */
			{20312,34,0}, /* core0 return_Stack4 bit37 */
			{20311,34,0}, /* core0 return_Stack4 bit38 */
			{20306,34,0}, /* core0 return_Stack4 bit39 */
			{20305,34,0}, /* core0 return_Stack4 bit40 */
			{20304,34,0}, /* core0 return_Stack4 bit41 */
			{20303,34,0}, /* core0 return_Stack4 bit42 */
			{20298,34,0}, /* core0 return_Stack4 bit43 */
			{20297,34,0}, /* core0 return_Stack4 bit44 */
			{20296,34,0}, /* core0 return_Stack4 bit45 */
			{20295,34,0}, /* core0 return_Stack4 bit46 */
			{16445,34,0}, /* core0 return_Stack4 bit47 */
			{13576,34,1}, /* core0 return_Stack4 bit48 */
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
			{16444,34,0}, /* core0 return_Stack5 bit0 */
			{20262,34,0}, /* core0 return_Stack5 bit1 */
			{16443,34,0}, /* core0 return_Stack5 bit2 */
			{16438,34,0}, /* core0 return_Stack5 bit3 */
			{20261,34,0}, /* core0 return_Stack5 bit4 */
			{20260,34,0}, /* core0 return_Stack5 bit5 */
			{20259,34,0}, /* core0 return_Stack5 bit6 */
			{20266,34,0}, /* core0 return_Stack5 bit7 */
			{20265,34,0}, /* core0 return_Stack5 bit8 */
			{20264,34,0}, /* core0 return_Stack5 bit9 */
			{20263,34,0}, /* core0 return_Stack5 bit10 */
			{16437,34,0}, /* core0 return_Stack5 bit11 */
			{20402,34,0}, /* core0 return_Stack5 bit12 */
			{20401,34,0}, /* core0 return_Stack5 bit13 */
			{20400,34,0}, /* core0 return_Stack5 bit14 */
			{20399,34,0}, /* core0 return_Stack5 bit15 */
			{16364,34,0}, /* core0 return_Stack5 bit16 */
			{16363,34,0}, /* core0 return_Stack5 bit17 */
			{16342,34,0}, /* core0 return_Stack5 bit18 */
			{16341,34,0}, /* core0 return_Stack5 bit19 */
			{20390,34,0}, /* core0 return_Stack5 bit20 */
			{20389,34,0}, /* core0 return_Stack5 bit21 */
			{20388,34,0}, /* core0 return_Stack5 bit22 */
			{20387,34,0}, /* core0 return_Stack5 bit23 */
			{20282,34,0}, /* core0 return_Stack5 bit24 */
			{20281,34,0}, /* core0 return_Stack5 bit25 */
			{20280,34,0}, /* core0 return_Stack5 bit26 */
			{20279,34,0}, /* core0 return_Stack5 bit27 */
			{16514,34,0}, /* core0 return_Stack5 bit28 */
			{16513,34,0}, /* core0 return_Stack5 bit29 */
			{16452,34,0}, /* core0 return_Stack5 bit30 */
			{20286,34,0}, /* core0 return_Stack5 bit31 */
			{16451,34,0}, /* core0 return_Stack5 bit32 */
			{20285,34,0}, /* core0 return_Stack5 bit33 */
			{20284,34,0}, /* core0 return_Stack5 bit34 */
			{20283,34,0}, /* core0 return_Stack5 bit35 */
			{20326,34,0}, /* core0 return_Stack5 bit36 */
			{20325,34,0}, /* core0 return_Stack5 bit37 */
			{20324,34,0}, /* core0 return_Stack5 bit38 */
			{20323,34,0}, /* core0 return_Stack5 bit39 */
			{20338,34,0}, /* core0 return_Stack5 bit40 */
			{20337,34,0}, /* core0 return_Stack5 bit41 */
			{20336,34,0}, /* core0 return_Stack5 bit42 */
			{20335,34,0}, /* core0 return_Stack5 bit43 */
			{20354,34,0}, /* core0 return_Stack5 bit44 */
			{20353,34,0}, /* core0 return_Stack5 bit45 */
			{20352,34,0}, /* core0 return_Stack5 bit46 */
			{20351,34,0}, /* core0 return_Stack5 bit47 */
			{13580,34,1}, /* core0 return_Stack5 bit48 */
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
			{20358,34,0}, /* core0 return_Stack6 bit0 */
			{20357,34,0}, /* core0 return_Stack6 bit1 */
			{20356,34,0}, /* core0 return_Stack6 bit2 */
			{20355,34,0}, /* core0 return_Stack6 bit3 */
			{20258,34,0}, /* core0 return_Stack6 bit4 */
			{20257,34,0}, /* core0 return_Stack6 bit5 */
			{20256,34,0}, /* core0 return_Stack6 bit6 */
			{20255,34,0}, /* core0 return_Stack6 bit7 */
			{16436,34,0}, /* core0 return_Stack6 bit8 */
			{20410,34,0}, /* core0 return_Stack6 bit9 */
			{16435,34,0}, /* core0 return_Stack6 bit10 */
			{20409,34,0}, /* core0 return_Stack6 bit11 */
			{20408,34,0}, /* core0 return_Stack6 bit12 */
			{20407,34,0}, /* core0 return_Stack6 bit13 */
			{16356,34,0}, /* core0 return_Stack6 bit14 */
			{16355,34,0}, /* core0 return_Stack6 bit15 */
			{16358,34,0}, /* core0 return_Stack6 bit16 */
			{16357,34,0}, /* core0 return_Stack6 bit17 */
			{20386,34,0}, /* core0 return_Stack6 bit18 */
			{20385,34,0}, /* core0 return_Stack6 bit19 */
			{20384,34,0}, /* core0 return_Stack6 bit20 */
			{20383,34,0}, /* core0 return_Stack6 bit21 */
			{20382,34,0}, /* core0 return_Stack6 bit22 */
			{20381,34,0}, /* core0 return_Stack6 bit23 */
			{20380,34,0}, /* core0 return_Stack6 bit24 */
			{20379,34,0}, /* core0 return_Stack6 bit25 */
			{20278,34,0}, /* core0 return_Stack6 bit26 */
			{20277,34,0}, /* core0 return_Stack6 bit27 */
			{20276,34,0}, /* core0 return_Stack6 bit28 */
			{20275,34,0}, /* core0 return_Stack6 bit29 */
			{16448,34,0}, /* core0 return_Stack6 bit30 */
			{16447,34,0}, /* core0 return_Stack6 bit31 */
			{16450,34,0}, /* core0 return_Stack6 bit32 */
			{16449,34,0}, /* core0 return_Stack6 bit33 */
			{20302,34,0}, /* core0 return_Stack6 bit34 */
			{20301,34,0}, /* core0 return_Stack6 bit35 */
			{20300,34,0}, /* core0 return_Stack6 bit36 */
			{20299,34,0}, /* core0 return_Stack6 bit37 */
			{20334,34,0}, /* core0 return_Stack6 bit38 */
			{20333,34,0}, /* core0 return_Stack6 bit39 */
			{20332,34,0}, /* core0 return_Stack6 bit40 */
			{20331,34,0}, /* core0 return_Stack6 bit41 */
			{20346,34,0}, /* core0 return_Stack6 bit42 */
			{20345,34,0}, /* core0 return_Stack6 bit43 */
			{20344,34,0}, /* core0 return_Stack6 bit44 */
			{20343,34,0}, /* core0 return_Stack6 bit45 */
			{16442,34,0}, /* core0 return_Stack6 bit46 */
			{16441,34,0}, /* core0 return_Stack6 bit47 */
			{13582,34,1}, /* core0 return_Stack6 bit48 */
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
			{20294,34,0}, /* core0 return_Stack7 bit0 */
			{20293,34,0}, /* core0 return_Stack7 bit1 */
			{20292,34,0}, /* core0 return_Stack7 bit2 */
			{20291,34,0}, /* core0 return_Stack7 bit3 */
			{20274,34,0}, /* core0 return_Stack7 bit4 */
			{20273,34,0}, /* core0 return_Stack7 bit5 */
			{20290,34,0}, /* core0 return_Stack7 bit6 */
			{20272,34,0}, /* core0 return_Stack7 bit7 */
			{20271,34,0}, /* core0 return_Stack7 bit8 */
			{20414,34,0}, /* core0 return_Stack7 bit9 */
			{20413,34,0}, /* core0 return_Stack7 bit10 */
			{20412,34,0}, /* core0 return_Stack7 bit11 */
			{20411,34,0}, /* core0 return_Stack7 bit12 */
			{20406,34,0}, /* core0 return_Stack7 bit13 */
			{20405,34,0}, /* core0 return_Stack7 bit14 */
			{20404,34,0}, /* core0 return_Stack7 bit15 */
			{20403,34,0}, /* core0 return_Stack7 bit16 */
			{20422,34,0}, /* core0 return_Stack7 bit17 */
			{20421,34,0}, /* core0 return_Stack7 bit18 */
			{20426,34,0}, /* core0 return_Stack7 bit19 */
			{20420,34,0}, /* core0 return_Stack7 bit20 */
			{20419,34,0}, /* core0 return_Stack7 bit21 */
			{20425,34,0}, /* core0 return_Stack7 bit22 */
			{20424,34,0}, /* core0 return_Stack7 bit23 */
			{20423,34,0}, /* core0 return_Stack7 bit24 */
			{16502,34,0}, /* core0 return_Stack7 bit25 */
			{16501,34,0}, /* core0 return_Stack7 bit26 */
			{16510,34,0}, /* core0 return_Stack7 bit27 */
			{16509,34,0}, /* core0 return_Stack7 bit28 */
			{16516,34,0}, /* core0 return_Stack7 bit29 */
			{16515,34,0}, /* core0 return_Stack7 bit30 */
			{20289,34,0}, /* core0 return_Stack7 bit31 */
			{13575,34,1}, /* core0 return_Stack7 bit32 */
			{20288,34,0}, /* core0 return_Stack7 bit33 */
			{20287,34,0}, /* core0 return_Stack7 bit34 */
			{20322,34,0}, /* core0 return_Stack7 bit35 */
			{20321,34,0}, /* core0 return_Stack7 bit36 */
			{20320,34,0}, /* core0 return_Stack7 bit37 */
			{20319,34,0}, /* core0 return_Stack7 bit38 */
			{20330,34,0}, /* core0 return_Stack7 bit39 */
			{20329,34,0}, /* core0 return_Stack7 bit40 */
			{20328,34,0}, /* core0 return_Stack7 bit41 */
			{20327,34,0}, /* core0 return_Stack7 bit42 */
			{20350,34,0}, /* core0 return_Stack7 bit43 */
			{20349,34,0}, /* core0 return_Stack7 bit44 */
			{20348,34,0}, /* core0 return_Stack7 bit45 */
			{20347,34,0}, /* core0 return_Stack7 bit46 */
			{13579,34,1}, /* core0 return_Stack7 bit47 */
			{13578,34,1}, /* core0 return_Stack7 bit48 */
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
			.L2_parity_err_count = {{
			{ 6977, 8,0}, /* core0 L2_parity_err_count bit0 */
			{ 6976, 8,0}, /* core0 L2_parity_err_count bit1 */
			{ 6975, 8,0}, /* core0 L2_parity_err_count bit2 */
			{ 6974, 8,0}, /* core0 L2_parity_err_count bit3 */
			{ 6973, 8,0}, /* core0 L2_parity_err_count bit4 */
			{ 6972, 8,0}, /* core0 L2_parity_err_count bit5 */
			{ 6971, 8,0}, /* core0 L2_parity_err_count bit6 */
			{ 6970, 8,0}, /* core0 L2_parity_err_count bit7 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit8 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit9 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit10 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit11 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit12 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit13 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit14 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit15 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit16 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit17 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit18 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit19 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit20 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit21 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit22 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit23 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit24 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit25 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit26 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit27 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit28 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit29 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit30 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit31 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit32 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit33 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit34 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit35 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit36 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit37 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit38 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit39 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit40 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit41 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit42 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit43 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit44 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit45 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit46 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit47 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit48 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit49 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit50 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit51 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit52 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit53 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit54 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit55 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit56 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit57 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit58 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit59 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit60 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit61 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit62 */
			{    0, 0,2}, /* core0 L2_parity_err_count bit63 */
			}},
			.L2_parity_index = {{
			{ 6921, 8,0}, /* core0 L2_parity_index bit0 */
			{ 6920, 8,0}, /* core0 L2_parity_index bit1 */
			{ 6919, 8,0}, /* core0 L2_parity_index bit2 */
			{ 6918, 8,0}, /* core0 L2_parity_index bit3 */
			{ 6917, 8,0}, /* core0 L2_parity_index bit4 */
			{ 6916, 8,0}, /* core0 L2_parity_index bit5 */
			{ 6915, 8,0}, /* core0 L2_parity_index bit6 */
			{ 6914, 8,0}, /* core0 L2_parity_index bit7 */
			{ 6772, 8,0}, /* core0 L2_parity_index bit8 */
			{ 6771, 8,0}, /* core0 L2_parity_index bit9 */
			{ 6770, 8,0}, /* core0 L2_parity_index bit10 */
			{ 6769, 8,0}, /* core0 L2_parity_index bit11 */
			{    0, 0,2}, /* core0 L2_parity_index bit12 */
			{    0, 0,2}, /* core0 L2_parity_index bit13 */
			{    0, 0,2}, /* core0 L2_parity_index bit14 */
			{    0, 0,2}, /* core0 L2_parity_index bit15 */
			{    0, 0,2}, /* core0 L2_parity_index bit16 */
			{    0, 0,2}, /* core0 L2_parity_index bit17 */
			{    0, 0,2}, /* core0 L2_parity_index bit18 */
			{    0, 0,2}, /* core0 L2_parity_index bit19 */
			{    0, 0,2}, /* core0 L2_parity_index bit20 */
			{    0, 0,2}, /* core0 L2_parity_index bit21 */
			{    0, 0,2}, /* core0 L2_parity_index bit22 */
			{    0, 0,2}, /* core0 L2_parity_index bit23 */
			{    0, 0,2}, /* core0 L2_parity_index bit24 */
			{    0, 0,2}, /* core0 L2_parity_index bit25 */
			{    0, 0,2}, /* core0 L2_parity_index bit26 */
			{    0, 0,2}, /* core0 L2_parity_index bit27 */
			{    0, 0,2}, /* core0 L2_parity_index bit28 */
			{    0, 0,2}, /* core0 L2_parity_index bit29 */
			{    0, 0,2}, /* core0 L2_parity_index bit30 */
			{    0, 0,2}, /* core0 L2_parity_index bit31 */
			{    0, 0,2}, /* core0 L2_parity_index bit32 */
			{    0, 0,2}, /* core0 L2_parity_index bit33 */
			{    0, 0,2}, /* core0 L2_parity_index bit34 */
			{    0, 0,2}, /* core0 L2_parity_index bit35 */
			{    0, 0,2}, /* core0 L2_parity_index bit36 */
			{    0, 0,2}, /* core0 L2_parity_index bit37 */
			{    0, 0,2}, /* core0 L2_parity_index bit38 */
			{    0, 0,2}, /* core0 L2_parity_index bit39 */
			{    0, 0,2}, /* core0 L2_parity_index bit40 */
			{    0, 0,2}, /* core0 L2_parity_index bit41 */
			{    0, 0,2}, /* core0 L2_parity_index bit42 */
			{    0, 0,2}, /* core0 L2_parity_index bit43 */
			{    0, 0,2}, /* core0 L2_parity_index bit44 */
			{    0, 0,2}, /* core0 L2_parity_index bit45 */
			{    0, 0,2}, /* core0 L2_parity_index bit46 */
			{    0, 0,2}, /* core0 L2_parity_index bit47 */
			{    0, 0,2}, /* core0 L2_parity_index bit48 */
			{    0, 0,2}, /* core0 L2_parity_index bit49 */
			{    0, 0,2}, /* core0 L2_parity_index bit50 */
			{    0, 0,2}, /* core0 L2_parity_index bit51 */
			{    0, 0,2}, /* core0 L2_parity_index bit52 */
			{    0, 0,2}, /* core0 L2_parity_index bit53 */
			{    0, 0,2}, /* core0 L2_parity_index bit54 */
			{    0, 0,2}, /* core0 L2_parity_index bit55 */
			{    0, 0,2}, /* core0 L2_parity_index bit56 */
			{    0, 0,2}, /* core0 L2_parity_index bit57 */
			{    0, 0,2}, /* core0 L2_parity_index bit58 */
			{    0, 0,2}, /* core0 L2_parity_index bit59 */
			{    0, 0,2}, /* core0 L2_parity_index bit60 */
			{    0, 0,2}, /* core0 L2_parity_index bit61 */
			{    0, 0,2}, /* core0 L2_parity_index bit62 */
			{    0, 0,2}, /* core0 L2_parity_index bit63 */
			}},
			.L2_parity_way = {{
			{ 6765, 8,0}, /* core0 L2_parity_way bit0 */
			{ 6465, 8,0}, /* core0 L2_parity_way bit1 */
			{    0, 0,2}, /* core0 L2_parity_way bit2 */
			{    0, 0,2}, /* core0 L2_parity_way bit3 */
			{    0, 0,2}, /* core0 L2_parity_way bit4 */
			{    0, 0,2}, /* core0 L2_parity_way bit5 */
			{    0, 0,2}, /* core0 L2_parity_way bit6 */
			{    0, 0,2}, /* core0 L2_parity_way bit7 */
			{    0, 0,2}, /* core0 L2_parity_way bit8 */
			{    0, 0,2}, /* core0 L2_parity_way bit9 */
			{    0, 0,2}, /* core0 L2_parity_way bit10 */
			{    0, 0,2}, /* core0 L2_parity_way bit11 */
			{    0, 0,2}, /* core0 L2_parity_way bit12 */
			{    0, 0,2}, /* core0 L2_parity_way bit13 */
			{    0, 0,2}, /* core0 L2_parity_way bit14 */
			{    0, 0,2}, /* core0 L2_parity_way bit15 */
			{    0, 0,2}, /* core0 L2_parity_way bit16 */
			{    0, 0,2}, /* core0 L2_parity_way bit17 */
			{    0, 0,2}, /* core0 L2_parity_way bit18 */
			{    0, 0,2}, /* core0 L2_parity_way bit19 */
			{    0, 0,2}, /* core0 L2_parity_way bit20 */
			{    0, 0,2}, /* core0 L2_parity_way bit21 */
			{    0, 0,2}, /* core0 L2_parity_way bit22 */
			{    0, 0,2}, /* core0 L2_parity_way bit23 */
			{    0, 0,2}, /* core0 L2_parity_way bit24 */
			{    0, 0,2}, /* core0 L2_parity_way bit25 */
			{    0, 0,2}, /* core0 L2_parity_way bit26 */
			{    0, 0,2}, /* core0 L2_parity_way bit27 */
			{    0, 0,2}, /* core0 L2_parity_way bit28 */
			{    0, 0,2}, /* core0 L2_parity_way bit29 */
			{    0, 0,2}, /* core0 L2_parity_way bit30 */
			{    0, 0,2}, /* core0 L2_parity_way bit31 */
			{    0, 0,2}, /* core0 L2_parity_way bit32 */
			{    0, 0,2}, /* core0 L2_parity_way bit33 */
			{    0, 0,2}, /* core0 L2_parity_way bit34 */
			{    0, 0,2}, /* core0 L2_parity_way bit35 */
			{    0, 0,2}, /* core0 L2_parity_way bit36 */
			{    0, 0,2}, /* core0 L2_parity_way bit37 */
			{    0, 0,2}, /* core0 L2_parity_way bit38 */
			{    0, 0,2}, /* core0 L2_parity_way bit39 */
			{    0, 0,2}, /* core0 L2_parity_way bit40 */
			{    0, 0,2}, /* core0 L2_parity_way bit41 */
			{    0, 0,2}, /* core0 L2_parity_way bit42 */
			{    0, 0,2}, /* core0 L2_parity_way bit43 */
			{    0, 0,2}, /* core0 L2_parity_way bit44 */
			{    0, 0,2}, /* core0 L2_parity_way bit45 */
			{    0, 0,2}, /* core0 L2_parity_way bit46 */
			{    0, 0,2}, /* core0 L2_parity_way bit47 */
			{    0, 0,2}, /* core0 L2_parity_way bit48 */
			{    0, 0,2}, /* core0 L2_parity_way bit49 */
			{    0, 0,2}, /* core0 L2_parity_way bit50 */
			{    0, 0,2}, /* core0 L2_parity_way bit51 */
			{    0, 0,2}, /* core0 L2_parity_way bit52 */
			{    0, 0,2}, /* core0 L2_parity_way bit53 */
			{    0, 0,2}, /* core0 L2_parity_way bit54 */
			{    0, 0,2}, /* core0 L2_parity_way bit55 */
			{    0, 0,2}, /* core0 L2_parity_way bit56 */
			{    0, 0,2}, /* core0 L2_parity_way bit57 */
			{    0, 0,2}, /* core0 L2_parity_way bit58 */
			{    0, 0,2}, /* core0 L2_parity_way bit59 */
			{    0, 0,2}, /* core0 L2_parity_way bit60 */
			{    0, 0,2}, /* core0 L2_parity_way bit61 */
			{    0, 0,2}, /* core0 L2_parity_way bit62 */
			{    0, 0,2}, /* core0 L2_parity_way bit63 */
			}},
			.L2_parity_banks = {{
			{ 7090, 8,0}, /* core0 L2_parity_banks bit0 */
			{ 7089, 8,0}, /* core0 L2_parity_banks bit1 */
			{ 7088, 8,0}, /* core0 L2_parity_banks bit2 */
			{ 7087, 8,0}, /* core0 L2_parity_banks bit3 */
			{ 7086, 8,0}, /* core0 L2_parity_banks bit4 */
			{ 7085, 8,0}, /* core0 L2_parity_banks bit5 */
			{ 7084, 8,0}, /* core0 L2_parity_banks bit6 */
			{ 7083, 8,0}, /* core0 L2_parity_banks bit7 */
			{ 6985, 8,0}, /* core0 L2_parity_banks bit8 */
			{ 6984, 8,0}, /* core0 L2_parity_banks bit9 */
			{ 6983, 8,0}, /* core0 L2_parity_banks bit10 */
			{ 6982, 8,0}, /* core0 L2_parity_banks bit11 */
			{ 6981, 8,0}, /* core0 L2_parity_banks bit12 */
			{ 6980, 8,0}, /* core0 L2_parity_banks bit13 */
			{ 6979, 8,0}, /* core0 L2_parity_banks bit14 */
			{ 6978, 8,0}, /* core0 L2_parity_banks bit15 */
			{    0, 0,2}, /* core0 L2_parity_banks bit16 */
			{    0, 0,2}, /* core0 L2_parity_banks bit17 */
			{    0, 0,2}, /* core0 L2_parity_banks bit18 */
			{    0, 0,2}, /* core0 L2_parity_banks bit19 */
			{    0, 0,2}, /* core0 L2_parity_banks bit20 */
			{    0, 0,2}, /* core0 L2_parity_banks bit21 */
			{    0, 0,2}, /* core0 L2_parity_banks bit22 */
			{    0, 0,2}, /* core0 L2_parity_banks bit23 */
			{    0, 0,2}, /* core0 L2_parity_banks bit24 */
			{    0, 0,2}, /* core0 L2_parity_banks bit25 */
			{    0, 0,2}, /* core0 L2_parity_banks bit26 */
			{    0, 0,2}, /* core0 L2_parity_banks bit27 */
			{    0, 0,2}, /* core0 L2_parity_banks bit28 */
			{    0, 0,2}, /* core0 L2_parity_banks bit29 */
			{    0, 0,2}, /* core0 L2_parity_banks bit30 */
			{    0, 0,2}, /* core0 L2_parity_banks bit31 */
			{    0, 0,2}, /* core0 L2_parity_banks bit32 */
			{    0, 0,2}, /* core0 L2_parity_banks bit33 */
			{    0, 0,2}, /* core0 L2_parity_banks bit34 */
			{    0, 0,2}, /* core0 L2_parity_banks bit35 */
			{    0, 0,2}, /* core0 L2_parity_banks bit36 */
			{    0, 0,2}, /* core0 L2_parity_banks bit37 */
			{    0, 0,2}, /* core0 L2_parity_banks bit38 */
			{    0, 0,2}, /* core0 L2_parity_banks bit39 */
			{    0, 0,2}, /* core0 L2_parity_banks bit40 */
			{    0, 0,2}, /* core0 L2_parity_banks bit41 */
			{    0, 0,2}, /* core0 L2_parity_banks bit42 */
			{    0, 0,2}, /* core0 L2_parity_banks bit43 */
			{    0, 0,2}, /* core0 L2_parity_banks bit44 */
			{    0, 0,2}, /* core0 L2_parity_banks bit45 */
			{    0, 0,2}, /* core0 L2_parity_banks bit46 */
			{    0, 0,2}, /* core0 L2_parity_banks bit47 */
			{    0, 0,2}, /* core0 L2_parity_banks bit48 */
			{    0, 0,2}, /* core0 L2_parity_banks bit49 */
			{    0, 0,2}, /* core0 L2_parity_banks bit50 */
			{    0, 0,2}, /* core0 L2_parity_banks bit51 */
			{    0, 0,2}, /* core0 L2_parity_banks bit52 */
			{    0, 0,2}, /* core0 L2_parity_banks bit53 */
			{    0, 0,2}, /* core0 L2_parity_banks bit54 */
			{    0, 0,2}, /* core0 L2_parity_banks bit55 */
			{    0, 0,2}, /* core0 L2_parity_banks bit56 */
			{    0, 0,2}, /* core0 L2_parity_banks bit57 */
			{    0, 0,2}, /* core0 L2_parity_banks bit58 */
			{    0, 0,2}, /* core0 L2_parity_banks bit59 */
			{    0, 0,2}, /* core0 L2_parity_banks bit60 */
			{    0, 0,2}, /* core0 L2_parity_banks bit61 */
			{    0, 0,2}, /* core0 L2_parity_banks bit62 */
			{    0, 0,2}, /* core0 L2_parity_banks bit63 */
			}},
	},
	{		/* core 1 */ 
			.pc = {{
			{  392,35,1}, /* core1 pc bit0 */
			{  391,35,1}, /* core1 pc bit1 */
			{  390,35,1}, /* core1 pc bit2 */
			{  389,35,1}, /* core1 pc bit3 */
			{  440,35,1}, /* core1 pc bit4 */
			{  416,35,1}, /* core1 pc bit5 */
			{  439,35,1}, /* core1 pc bit6 */
			{  415,35,1}, /* core1 pc bit7 */
			{  388,35,1}, /* core1 pc bit8 */
			{  414,35,1}, /* core1 pc bit9 */
			{  344,35,1}, /* core1 pc bit10 */
			{  360,35,1}, /* core1 pc bit11 */
			{  359,35,1}, /* core1 pc bit12 */
			{  358,35,1}, /* core1 pc bit13 */
			{  343,35,1}, /* core1 pc bit14 */
			{  342,35,1}, /* core1 pc bit15 */
			{  413,35,1}, /* core1 pc bit16 */
			{  296,35,1}, /* core1 pc bit17 */
			{  357,35,1}, /* core1 pc bit18 */
			{  387,35,1}, /* core1 pc bit19 */
			{  356,35,1}, /* core1 pc bit20 */
			{  355,35,1}, /* core1 pc bit21 */
			{  412,35,1}, /* core1 pc bit22 */
			{  354,35,1}, /* core1 pc bit23 */
			{  353,35,1}, /* core1 pc bit24 */
			{  376,35,1}, /* core1 pc bit25 */
			{  352,35,1}, /* core1 pc bit26 */
			{  295,35,1}, /* core1 pc bit27 */
			{  386,35,1}, /* core1 pc bit28 */
			{  341,35,1}, /* core1 pc bit29 */
			{  385,35,1}, /* core1 pc bit30 */
			{  351,35,1}, /* core1 pc bit31 */
			{  264,35,1}, /* core1 pc bit32 */
			{  112,35,1}, /* core1 pc bit33 */
			{  263,35,1}, /* core1 pc bit34 */
			{  111,35,1}, /* core1 pc bit35 */
			{  172,35,1}, /* core1 pc bit36 */
			{  180,35,1}, /* core1 pc bit37 */
			{  262,35,1}, /* core1 pc bit38 */
			{  146,35,1}, /* core1 pc bit39 */
			{  179,35,1}, /* core1 pc bit40 */
			{  145,35,1}, /* core1 pc bit41 */
			{  136,35,1}, /* core1 pc bit42 */
			{  261,35,1}, /* core1 pc bit43 */
			{  260,35,1}, /* core1 pc bit44 */
			{  259,35,1}, /* core1 pc bit45 */
			{  144,35,1}, /* core1 pc bit46 */
			{  143,35,1}, /* core1 pc bit47 */
			{  438,35,1}, /* core1 pc bit48 */
			{  110,35,1}, /* core1 pc bit49 */
			{  207,35,1}, /* core1 pc bit50 */
			{  206,35,1}, /* core1 pc bit51 */
			{  411,35,1}, /* core1 pc bit52 */
			{  205,35,1}, /* core1 pc bit53 */
			{  109,35,1}, /* core1 pc bit54 */
			{  204,35,1}, /* core1 pc bit55 */
			{  258,35,1}, /* core1 pc bit56 */
			{  203,35,1}, /* core1 pc bit57 */
			{  178,35,1}, /* core1 pc bit58 */
			{  177,35,1}, /* core1 pc bit59 */
			{  202,35,1}, /* core1 pc bit60 */
			{  201,35,1}, /* core1 pc bit61 */
			{  200,35,1}, /* core1 pc bit62 */
			{  257,35,1}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{37603,36,0}, /* core1 sp32 bit0 */
			{37602,36,0}, /* core1 sp32 bit1 */
			{28162,36,1}, /* core1 sp32 bit2 */
			{28161,36,1}, /* core1 sp32 bit3 */
			{28160,36,1}, /* core1 sp32 bit4 */
			{28092,36,1}, /* core1 sp32 bit5 */
			{28159,36,1}, /* core1 sp32 bit6 */
			{28091,36,1}, /* core1 sp32 bit7 */
			{37601,36,0}, /* core1 sp32 bit8 */
			{37600,36,0}, /* core1 sp32 bit9 */
			{28158,36,1}, /* core1 sp32 bit10 */
			{28151,36,1}, /* core1 sp32 bit11 */
			{37583,36,0}, /* core1 sp32 bit12 */
			{37582,36,0}, /* core1 sp32 bit13 */
			{37581,36,0}, /* core1 sp32 bit14 */
			{37580,36,0}, /* core1 sp32 bit15 */
			{28135,36,1}, /* core1 sp32 bit16 */
			{28150,36,1}, /* core1 sp32 bit17 */
			{28131,36,1}, /* core1 sp32 bit18 */
			{28132,36,1}, /* core1 sp32 bit19 */
			{28144,36,1}, /* core1 sp32 bit20 */
			{28133,36,1}, /* core1 sp32 bit21 */
			{31013,35,1}, /* core1 sp32 bit22 */
			{31012,35,1}, /* core1 sp32 bit23 */
			{28130,36,1}, /* core1 sp32 bit24 */
			{28134,36,1}, /* core1 sp32 bit25 */
			{31011,35,1}, /* core1 sp32 bit26 */
			{31010,35,1}, /* core1 sp32 bit27 */
			{37579,36,0}, /* core1 sp32 bit28 */
			{37578,36,0}, /* core1 sp32 bit29 */
			{37593,36,0}, /* core1 sp32 bit30 */
			{37592,36,0}, /* core1 sp32 bit31 */
			{30913,35,1}, /* core1 sp32 bit32 */
			{30912,35,1}, /* core1 sp32 bit33 */
			{30911,35,1}, /* core1 sp32 bit34 */
			{30910,35,1}, /* core1 sp32 bit35 */
			{37623,36,0}, /* core1 sp32 bit36 */
			{37622,36,0}, /* core1 sp32 bit37 */
			{28277,36,1}, /* core1 sp32 bit38 */
			{37709,36,0}, /* core1 sp32 bit39 */
			{28274,36,1}, /* core1 sp32 bit40 */
			{37611,36,0}, /* core1 sp32 bit41 */
			{37625,36,0}, /* core1 sp32 bit42 */
			{37624,36,0}, /* core1 sp32 bit43 */
			{37708,36,0}, /* core1 sp32 bit44 */
			{37711,36,0}, /* core1 sp32 bit45 */
			{37610,36,0}, /* core1 sp32 bit46 */
			{37710,36,0}, /* core1 sp32 bit47 */
			{28278,36,1}, /* core1 sp32 bit48 */
			{28300,36,1}, /* core1 sp32 bit49 */
			{28296,36,1}, /* core1 sp32 bit50 */
			{28302,36,1}, /* core1 sp32 bit51 */
			{28283,36,1}, /* core1 sp32 bit52 */
			{28170,36,1}, /* core1 sp32 bit53 */
			{28281,36,1}, /* core1 sp32 bit54 */
			{28310,36,1}, /* core1 sp32 bit55 */
			{28279,36,1}, /* core1 sp32 bit56 */
			{28301,36,1}, /* core1 sp32 bit57 */
			{28169,36,1}, /* core1 sp32 bit58 */
			{28303,36,1}, /* core1 sp32 bit59 */
			{28171,36,1}, /* core1 sp32 bit60 */
			{28168,36,1}, /* core1 sp32 bit61 */
			{28295,36,1}, /* core1 sp32 bit62 */
			{28297,36,1}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{28348,36,1}, /* core1 fp32 bit0 */
			{28349,36,1}, /* core1 fp32 bit1 */
			{37719,36,0}, /* core1 fp32 bit2 */
			{37718,36,0}, /* core1 fp32 bit3 */
			{37721,36,0}, /* core1 fp32 bit4 */
			{37720,36,0}, /* core1 fp32 bit5 */
			{28353,36,1}, /* core1 fp32 bit6 */
			{28351,36,1}, /* core1 fp32 bit7 */
			{28352,36,1}, /* core1 fp32 bit8 */
			{28350,36,1}, /* core1 fp32 bit9 */
			{37751,36,0}, /* core1 fp32 bit10 */
			{37750,36,0}, /* core1 fp32 bit11 */
			{37747,36,0}, /* core1 fp32 bit12 */
			{37746,36,0}, /* core1 fp32 bit13 */
			{31129,35,1}, /* core1 fp32 bit14 */
			{31128,35,1}, /* core1 fp32 bit15 */
			{31127,35,1}, /* core1 fp32 bit16 */
			{31126,35,1}, /* core1 fp32 bit17 */
			{37745,36,0}, /* core1 fp32 bit18 */
			{37744,36,0}, /* core1 fp32 bit19 */
			{31125,35,1}, /* core1 fp32 bit20 */
			{31124,35,1}, /* core1 fp32 bit21 */
			{28375,36,1}, /* core1 fp32 bit22 */
			{31123,35,1}, /* core1 fp32 bit23 */
			{31122,35,1}, /* core1 fp32 bit24 */
			{31121,35,1}, /* core1 fp32 bit25 */
			{31120,35,1}, /* core1 fp32 bit26 */
			{31119,35,1}, /* core1 fp32 bit27 */
			{31118,35,1}, /* core1 fp32 bit28 */
			{28374,36,1}, /* core1 fp32 bit29 */
			{37749,36,0}, /* core1 fp32 bit30 */
			{37748,36,0}, /* core1 fp32 bit31 */
			{37833,35,1}, /* core1 fp32 bit32 */
			{37832,35,1}, /* core1 fp32 bit33 */
			{37831,35,1}, /* core1 fp32 bit34 */
			{37830,35,1}, /* core1 fp32 bit35 */
			{28509,36,1}, /* core1 fp32 bit36 */
			{28510,36,1}, /* core1 fp32 bit37 */
			{37645,36,0}, /* core1 fp32 bit38 */
			{37829,35,1}, /* core1 fp32 bit39 */
			{37828,35,1}, /* core1 fp32 bit40 */
			{37644,36,0}, /* core1 fp32 bit41 */
			{37827,35,1}, /* core1 fp32 bit42 */
			{37641,36,0}, /* core1 fp32 bit43 */
			{37640,36,0}, /* core1 fp32 bit44 */
			{28508,36,1}, /* core1 fp32 bit45 */
			{28507,36,1}, /* core1 fp32 bit46 */
			{37643,36,0}, /* core1 fp32 bit47 */
			{37642,36,0}, /* core1 fp32 bit48 */
			{28511,36,1}, /* core1 fp32 bit49 */
			{28486,36,1}, /* core1 fp32 bit50 */
			{37826,35,1}, /* core1 fp32 bit51 */
			{28476,36,1}, /* core1 fp32 bit52 */
			{28472,36,1}, /* core1 fp32 bit53 */
			{28475,36,1}, /* core1 fp32 bit54 */
			{28489,36,1}, /* core1 fp32 bit55 */
			{28474,36,1}, /* core1 fp32 bit56 */
			{28453,36,1}, /* core1 fp32 bit57 */
			{28484,36,1}, /* core1 fp32 bit58 */
			{28454,36,1}, /* core1 fp32 bit59 */
			{28487,36,1}, /* core1 fp32 bit60 */
			{28488,36,1}, /* core1 fp32 bit61 */
			{28485,36,1}, /* core1 fp32 bit62 */
			{28473,36,1}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{28058,36,1}, /* core1 fp64 bit0 */
			{28057,36,1}, /* core1 fp64 bit1 */
			{28059,36,1}, /* core1 fp64 bit2 */
			{28054,36,1}, /* core1 fp64 bit3 */
			{31029,35,1}, /* core1 fp64 bit4 */
			{31028,35,1}, /* core1 fp64 bit5 */
			{31027,35,1}, /* core1 fp64 bit6 */
			{31026,35,1}, /* core1 fp64 bit7 */
			{28056,36,1}, /* core1 fp64 bit8 */
			{28055,36,1}, /* core1 fp64 bit9 */
			{37529,35,1}, /* core1 fp64 bit10 */
			{28060,36,1}, /* core1 fp64 bit11 */
			{27855,36,1}, /* core1 fp64 bit12 */
			{37528,35,1}, /* core1 fp64 bit13 */
			{37527,35,1}, /* core1 fp64 bit14 */
			{37526,35,1}, /* core1 fp64 bit15 */
			{30993,35,1}, /* core1 fp64 bit16 */
			{30992,35,1}, /* core1 fp64 bit17 */
			{37525,35,1}, /* core1 fp64 bit18 */
			{37524,35,1}, /* core1 fp64 bit19 */
			{37523,35,1}, /* core1 fp64 bit20 */
			{37522,35,1}, /* core1 fp64 bit21 */
			{30991,35,1}, /* core1 fp64 bit22 */
			{30990,35,1}, /* core1 fp64 bit23 */
			{27845,36,1}, /* core1 fp64 bit24 */
			{27843,36,1}, /* core1 fp64 bit25 */
			{27844,36,1}, /* core1 fp64 bit26 */
			{27842,36,1}, /* core1 fp64 bit27 */
			{37481,36,0}, /* core1 fp64 bit28 */
			{37480,36,0}, /* core1 fp64 bit29 */
			{37487,36,0}, /* core1 fp64 bit30 */
			{37486,36,0}, /* core1 fp64 bit31 */
			{30825,35,1}, /* core1 fp64 bit32 */
			{30837,35,1}, /* core1 fp64 bit33 */
			{30836,35,1}, /* core1 fp64 bit34 */
			{30835,35,1}, /* core1 fp64 bit35 */
			{30834,35,1}, /* core1 fp64 bit36 */
			{30824,35,1}, /* core1 fp64 bit37 */
			{30823,35,1}, /* core1 fp64 bit38 */
			{30822,35,1}, /* core1 fp64 bit39 */
			{27896,36,1}, /* core1 fp64 bit40 */
			{27982,36,1}, /* core1 fp64 bit41 */
			{37325,36,0}, /* core1 fp64 bit42 */
			{37324,36,0}, /* core1 fp64 bit43 */
			{30821,35,1}, /* core1 fp64 bit44 */
			{30820,35,1}, /* core1 fp64 bit45 */
			{27894,36,1}, /* core1 fp64 bit46 */
			{30819,35,1}, /* core1 fp64 bit47 */
			{27895,36,1}, /* core1 fp64 bit48 */
			{30818,35,1}, /* core1 fp64 bit49 */
			{30833,35,1}, /* core1 fp64 bit50 */
			{30832,35,1}, /* core1 fp64 bit51 */
			{30831,35,1}, /* core1 fp64 bit52 */
			{30830,35,1}, /* core1 fp64 bit53 */
			{30841,35,1}, /* core1 fp64 bit54 */
			{27983,36,1}, /* core1 fp64 bit55 */
			{30840,35,1}, /* core1 fp64 bit56 */
			{30839,35,1}, /* core1 fp64 bit57 */
			{27984,36,1}, /* core1 fp64 bit58 */
			{30838,35,1}, /* core1 fp64 bit59 */
			{30829,35,1}, /* core1 fp64 bit60 */
			{30828,35,1}, /* core1 fp64 bit61 */
			{30827,35,1}, /* core1 fp64 bit62 */
			{30826,35,1}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{28040,36,1}, /* core1 sp_EL0 bit0 */
			{28038,36,1}, /* core1 sp_EL0 bit1 */
			{28039,36,1}, /* core1 sp_EL0 bit2 */
			{28035,36,1}, /* core1 sp_EL0 bit3 */
			{28037,36,1}, /* core1 sp_EL0 bit4 */
			{28036,36,1}, /* core1 sp_EL0 bit5 */
			{37399,36,0}, /* core1 sp_EL0 bit6 */
			{37398,36,0}, /* core1 sp_EL0 bit7 */
			{37397,36,0}, /* core1 sp_EL0 bit8 */
			{37396,36,0}, /* core1 sp_EL0 bit9 */
			{27861,36,1}, /* core1 sp_EL0 bit10 */
			{28029,36,1}, /* core1 sp_EL0 bit11 */
			{27859,36,1}, /* core1 sp_EL0 bit12 */
			{27851,36,1}, /* core1 sp_EL0 bit13 */
			{37467,36,0}, /* core1 sp_EL0 bit14 */
			{37466,36,0}, /* core1 sp_EL0 bit15 */
			{27858,36,1}, /* core1 sp_EL0 bit16 */
			{27860,36,1}, /* core1 sp_EL0 bit17 */
			{37479,36,0}, /* core1 sp_EL0 bit18 */
			{37478,36,0}, /* core1 sp_EL0 bit19 */
			{37475,36,0}, /* core1 sp_EL0 bit20 */
			{37474,36,0}, /* core1 sp_EL0 bit21 */
			{37471,36,0}, /* core1 sp_EL0 bit22 */
			{37470,36,0}, /* core1 sp_EL0 bit23 */
			{30989,35,1}, /* core1 sp_EL0 bit24 */
			{30988,35,1}, /* core1 sp_EL0 bit25 */
			{30987,35,1}, /* core1 sp_EL0 bit26 */
			{30986,35,1}, /* core1 sp_EL0 bit27 */
			{37477,36,0}, /* core1 sp_EL0 bit28 */
			{37476,36,0}, /* core1 sp_EL0 bit29 */
			{27841,36,1}, /* core1 sp_EL0 bit30 */
			{28041,36,1}, /* core1 sp_EL0 bit31 */
			{37287,36,0}, /* core1 sp_EL0 bit32 */
			{37577,35,1}, /* core1 sp_EL0 bit33 */
			{37576,35,1}, /* core1 sp_EL0 bit34 */
			{37575,35,1}, /* core1 sp_EL0 bit35 */
			{37574,35,1}, /* core1 sp_EL0 bit36 */
			{37573,35,1}, /* core1 sp_EL0 bit37 */
			{37572,35,1}, /* core1 sp_EL0 bit38 */
			{37286,36,0}, /* core1 sp_EL0 bit39 */
			{37571,35,1}, /* core1 sp_EL0 bit40 */
			{37570,35,1}, /* core1 sp_EL0 bit41 */
			{37367,36,0}, /* core1 sp_EL0 bit42 */
			{37366,36,0}, /* core1 sp_EL0 bit43 */
			{37285,36,0}, /* core1 sp_EL0 bit44 */
			{37284,36,0}, /* core1 sp_EL0 bit45 */
			{27962,36,1}, /* core1 sp_EL0 bit46 */
			{27934,36,1}, /* core1 sp_EL0 bit47 */
			{37269,36,0}, /* core1 sp_EL0 bit48 */
			{37268,36,0}, /* core1 sp_EL0 bit49 */
			{37283,36,0}, /* core1 sp_EL0 bit50 */
			{37282,36,0}, /* core1 sp_EL0 bit51 */
			{37273,36,0}, /* core1 sp_EL0 bit52 */
			{37272,36,0}, /* core1 sp_EL0 bit53 */
			{37267,36,0}, /* core1 sp_EL0 bit54 */
			{37266,36,0}, /* core1 sp_EL0 bit55 */
			{37265,36,0}, /* core1 sp_EL0 bit56 */
			{37264,36,0}, /* core1 sp_EL0 bit57 */
			{30813,35,1}, /* core1 sp_EL0 bit58 */
			{30812,35,1}, /* core1 sp_EL0 bit59 */
			{37271,36,0}, /* core1 sp_EL0 bit60 */
			{37270,36,0}, /* core1 sp_EL0 bit61 */
			{30811,35,1}, /* core1 sp_EL0 bit62 */
			{30810,35,1}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{28034,36,1}, /* core1 sp_EL1 bit0 */
			{27881,36,1}, /* core1 sp_EL1 bit1 */
			{37395,36,0}, /* core1 sp_EL1 bit2 */
			{37394,36,0}, /* core1 sp_EL1 bit3 */
			{28032,36,1}, /* core1 sp_EL1 bit4 */
			{28033,36,1}, /* core1 sp_EL1 bit5 */
			{37393,36,0}, /* core1 sp_EL1 bit6 */
			{37392,36,0}, /* core1 sp_EL1 bit7 */
			{30569,35,1}, /* core1 sp_EL1 bit8 */
			{30568,35,1}, /* core1 sp_EL1 bit9 */
			{37465,36,0}, /* core1 sp_EL1 bit10 */
			{30567,35,1}, /* core1 sp_EL1 bit11 */
			{30566,35,1}, /* core1 sp_EL1 bit12 */
			{37464,36,0}, /* core1 sp_EL1 bit13 */
			{27863,36,1}, /* core1 sp_EL1 bit14 */
			{27864,36,1}, /* core1 sp_EL1 bit15 */
			{28030,36,1}, /* core1 sp_EL1 bit16 */
			{27862,36,1}, /* core1 sp_EL1 bit17 */
			{27836,36,1}, /* core1 sp_EL1 bit18 */
			{27839,36,1}, /* core1 sp_EL1 bit19 */
			{27838,36,1}, /* core1 sp_EL1 bit20 */
			{27837,36,1}, /* core1 sp_EL1 bit21 */
			{37493,36,0}, /* core1 sp_EL1 bit22 */
			{30597,35,1}, /* core1 sp_EL1 bit23 */
			{30596,35,1}, /* core1 sp_EL1 bit24 */
			{30595,35,1}, /* core1 sp_EL1 bit25 */
			{30594,35,1}, /* core1 sp_EL1 bit26 */
			{37492,36,0}, /* core1 sp_EL1 bit27 */
			{37495,36,0}, /* core1 sp_EL1 bit28 */
			{37494,36,0}, /* core1 sp_EL1 bit29 */
			{27840,36,1}, /* core1 sp_EL1 bit30 */
			{28031,36,1}, /* core1 sp_EL1 bit31 */
			{27935,36,1}, /* core1 sp_EL1 bit32 */
			{27963,36,1}, /* core1 sp_EL1 bit33 */
			{37365,36,0}, /* core1 sp_EL1 bit34 */
			{37364,36,0}, /* core1 sp_EL1 bit35 */
			{37363,36,0}, /* core1 sp_EL1 bit36 */
			{37362,36,0}, /* core1 sp_EL1 bit37 */
			{27966,36,1}, /* core1 sp_EL1 bit38 */
			{27931,36,1}, /* core1 sp_EL1 bit39 */
			{30653,35,1}, /* core1 sp_EL1 bit40 */
			{30652,35,1}, /* core1 sp_EL1 bit41 */
			{30651,35,1}, /* core1 sp_EL1 bit42 */
			{30650,35,1}, /* core1 sp_EL1 bit43 */
			{37279,36,0}, /* core1 sp_EL1 bit44 */
			{37278,36,0}, /* core1 sp_EL1 bit45 */
			{27964,36,1}, /* core1 sp_EL1 bit46 */
			{27933,36,1}, /* core1 sp_EL1 bit47 */
			{27932,36,1}, /* core1 sp_EL1 bit48 */
			{27965,36,1}, /* core1 sp_EL1 bit49 */
			{37281,36,0}, /* core1 sp_EL1 bit50 */
			{37280,36,0}, /* core1 sp_EL1 bit51 */
			{37275,36,0}, /* core1 sp_EL1 bit52 */
			{37274,36,0}, /* core1 sp_EL1 bit53 */
			{37263,36,0}, /* core1 sp_EL1 bit54 */
			{37262,36,0}, /* core1 sp_EL1 bit55 */
			{37261,36,0}, /* core1 sp_EL1 bit56 */
			{37260,36,0}, /* core1 sp_EL1 bit57 */
			{37349,36,0}, /* core1 sp_EL1 bit58 */
			{37348,36,0}, /* core1 sp_EL1 bit59 */
			{37353,36,0}, /* core1 sp_EL1 bit60 */
			{37352,36,0}, /* core1 sp_EL1 bit61 */
			{37277,36,0}, /* core1 sp_EL1 bit62 */
			{37276,36,0}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{28047,36,1}, /* core1 sp_EL2 bit0 */
			{28053,36,1}, /* core1 sp_EL2 bit1 */
			{28052,36,1}, /* core1 sp_EL2 bit2 */
			{28049,36,1}, /* core1 sp_EL2 bit3 */
			{28051,36,1}, /* core1 sp_EL2 bit4 */
			{28050,36,1}, /* core1 sp_EL2 bit5 */
			{28028,36,1}, /* core1 sp_EL2 bit6 */
			{28026,36,1}, /* core1 sp_EL2 bit7 */
			{28027,36,1}, /* core1 sp_EL2 bit8 */
			{28048,36,1}, /* core1 sp_EL2 bit9 */
			{27856,36,1}, /* core1 sp_EL2 bit10 */
			{28061,36,1}, /* core1 sp_EL2 bit11 */
			{27857,36,1}, /* core1 sp_EL2 bit12 */
			{27847,36,1}, /* core1 sp_EL2 bit13 */
			{27854,36,1}, /* core1 sp_EL2 bit14 */
			{37459,36,0}, /* core1 sp_EL2 bit15 */
			{37458,36,0}, /* core1 sp_EL2 bit16 */
			{27853,36,1}, /* core1 sp_EL2 bit17 */
			{37461,36,0}, /* core1 sp_EL2 bit18 */
			{37460,36,0}, /* core1 sp_EL2 bit19 */
			{27852,36,1}, /* core1 sp_EL2 bit20 */
			{27846,36,1}, /* core1 sp_EL2 bit21 */
			{30585,35,1}, /* core1 sp_EL2 bit22 */
			{30589,35,1}, /* core1 sp_EL2 bit23 */
			{30588,35,1}, /* core1 sp_EL2 bit24 */
			{30587,35,1}, /* core1 sp_EL2 bit25 */
			{30584,35,1}, /* core1 sp_EL2 bit26 */
			{30586,35,1}, /* core1 sp_EL2 bit27 */
			{30583,35,1}, /* core1 sp_EL2 bit28 */
			{37489,36,0}, /* core1 sp_EL2 bit29 */
			{37488,36,0}, /* core1 sp_EL2 bit30 */
			{30582,35,1}, /* core1 sp_EL2 bit31 */
			{37601,35,1}, /* core1 sp_EL2 bit32 */
			{30649,35,1}, /* core1 sp_EL2 bit33 */
			{30648,35,1}, /* core1 sp_EL2 bit34 */
			{30647,35,1}, /* core1 sp_EL2 bit35 */
			{30646,35,1}, /* core1 sp_EL2 bit36 */
			{37359,36,0}, /* core1 sp_EL2 bit37 */
			{37358,36,0}, /* core1 sp_EL2 bit38 */
			{37600,35,1}, /* core1 sp_EL2 bit39 */
			{37361,36,0}, /* core1 sp_EL2 bit40 */
			{37360,36,0}, /* core1 sp_EL2 bit41 */
			{30645,35,1}, /* core1 sp_EL2 bit42 */
			{30644,35,1}, /* core1 sp_EL2 bit43 */
			{37599,35,1}, /* core1 sp_EL2 bit44 */
			{37598,35,1}, /* core1 sp_EL2 bit45 */
			{30643,35,1}, /* core1 sp_EL2 bit46 */
			{37597,35,1}, /* core1 sp_EL2 bit47 */
			{37596,35,1}, /* core1 sp_EL2 bit48 */
			{30642,35,1}, /* core1 sp_EL2 bit49 */
			{37595,35,1}, /* core1 sp_EL2 bit50 */
			{37594,35,1}, /* core1 sp_EL2 bit51 */
			{37593,35,1}, /* core1 sp_EL2 bit52 */
			{37592,35,1}, /* core1 sp_EL2 bit53 */
			{27970,36,1}, /* core1 sp_EL2 bit54 */
			{37591,35,1}, /* core1 sp_EL2 bit55 */
			{27971,36,1}, /* core1 sp_EL2 bit56 */
			{37355,36,0}, /* core1 sp_EL2 bit57 */
			{37590,35,1}, /* core1 sp_EL2 bit58 */
			{37589,35,1}, /* core1 sp_EL2 bit59 */
			{37588,35,1}, /* core1 sp_EL2 bit60 */
			{37587,35,1}, /* core1 sp_EL2 bit61 */
			{37354,36,0}, /* core1 sp_EL2 bit62 */
			{37586,35,1}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{28045,36,1}, /* core1 sp_EL3 bit0 */
			{28046,36,1}, /* core1 sp_EL3 bit1 */
			{28044,36,1}, /* core1 sp_EL3 bit2 */
			{28043,36,1}, /* core1 sp_EL3 bit3 */
			{30573,35,1}, /* core1 sp_EL3 bit4 */
			{30572,35,1}, /* core1 sp_EL3 bit5 */
			{30571,35,1}, /* core1 sp_EL3 bit6 */
			{30570,35,1}, /* core1 sp_EL3 bit7 */
			{30577,35,1}, /* core1 sp_EL3 bit8 */
			{30576,35,1}, /* core1 sp_EL3 bit9 */
			{30575,35,1}, /* core1 sp_EL3 bit10 */
			{30574,35,1}, /* core1 sp_EL3 bit11 */
			{30581,35,1}, /* core1 sp_EL3 bit12 */
			{30580,35,1}, /* core1 sp_EL3 bit13 */
			{30579,35,1}, /* core1 sp_EL3 bit14 */
			{30578,35,1}, /* core1 sp_EL3 bit15 */
			{37463,36,0}, /* core1 sp_EL3 bit16 */
			{37462,36,0}, /* core1 sp_EL3 bit17 */
			{37473,36,0}, /* core1 sp_EL3 bit18 */
			{37472,36,0}, /* core1 sp_EL3 bit19 */
			{27850,36,1}, /* core1 sp_EL3 bit20 */
			{27848,36,1}, /* core1 sp_EL3 bit21 */
			{37469,36,0}, /* core1 sp_EL3 bit22 */
			{37468,36,0}, /* core1 sp_EL3 bit23 */
			{30593,35,1}, /* core1 sp_EL3 bit24 */
			{30592,35,1}, /* core1 sp_EL3 bit25 */
			{30591,35,1}, /* core1 sp_EL3 bit26 */
			{30590,35,1}, /* core1 sp_EL3 bit27 */
			{37491,36,0}, /* core1 sp_EL3 bit28 */
			{37490,36,0}, /* core1 sp_EL3 bit29 */
			{27849,36,1}, /* core1 sp_EL3 bit30 */
			{28042,36,1}, /* core1 sp_EL3 bit31 */
			{37289,36,0}, /* core1 sp_EL3 bit32 */
			{37585,35,1}, /* core1 sp_EL3 bit33 */
			{37584,35,1}, /* core1 sp_EL3 bit34 */
			{37583,35,1}, /* core1 sp_EL3 bit35 */
			{37582,35,1}, /* core1 sp_EL3 bit36 */
			{37581,35,1}, /* core1 sp_EL3 bit37 */
			{37580,35,1}, /* core1 sp_EL3 bit38 */
			{37288,36,0}, /* core1 sp_EL3 bit39 */
			{37579,35,1}, /* core1 sp_EL3 bit40 */
			{37578,35,1}, /* core1 sp_EL3 bit41 */
			{37357,36,0}, /* core1 sp_EL3 bit42 */
			{37356,36,0}, /* core1 sp_EL3 bit43 */
			{37347,36,0}, /* core1 sp_EL3 bit44 */
			{37346,36,0}, /* core1 sp_EL3 bit45 */
			{27969,36,1}, /* core1 sp_EL3 bit46 */
			{27974,36,1}, /* core1 sp_EL3 bit47 */
			{27973,36,1}, /* core1 sp_EL3 bit48 */
			{27967,36,1}, /* core1 sp_EL3 bit49 */
			{37351,36,0}, /* core1 sp_EL3 bit50 */
			{37350,36,0}, /* core1 sp_EL3 bit51 */
			{37259,36,0}, /* core1 sp_EL3 bit52 */
			{37258,36,0}, /* core1 sp_EL3 bit53 */
			{27968,36,1}, /* core1 sp_EL3 bit54 */
			{27972,36,1}, /* core1 sp_EL3 bit55 */
			{37078,36,0}, /* core1 sp_EL3 bit56 */
			{37077,36,0}, /* core1 sp_EL3 bit57 */
			{37074,36,0}, /* core1 sp_EL3 bit58 */
			{37073,36,0}, /* core1 sp_EL3 bit59 */
			{37076,36,0}, /* core1 sp_EL3 bit60 */
			{37075,36,0}, /* core1 sp_EL3 bit61 */
			{37072,36,0}, /* core1 sp_EL3 bit62 */
			{37071,36,0}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{37561,35,1}, /* core1 elr_EL1 bit0 */
			{37560,35,1}, /* core1 elr_EL1 bit1 */
			{37559,35,1}, /* core1 elr_EL1 bit2 */
			{37558,35,1}, /* core1 elr_EL1 bit3 */
			{37557,35,1}, /* core1 elr_EL1 bit4 */
			{37556,35,1}, /* core1 elr_EL1 bit5 */
			{37555,35,1}, /* core1 elr_EL1 bit6 */
			{37554,35,1}, /* core1 elr_EL1 bit7 */
			{37036,36,0}, /* core1 elr_EL1 bit8 */
			{37035,36,0}, /* core1 elr_EL1 bit9 */
			{30621,35,1}, /* core1 elr_EL1 bit10 */
			{30620,35,1}, /* core1 elr_EL1 bit11 */
			{37030,36,0}, /* core1 elr_EL1 bit12 */
			{37029,36,0}, /* core1 elr_EL1 bit13 */
			{37022,36,0}, /* core1 elr_EL1 bit14 */
			{37021,36,0}, /* core1 elr_EL1 bit15 */
			{30605,35,1}, /* core1 elr_EL1 bit16 */
			{30604,35,1}, /* core1 elr_EL1 bit17 */
			{30603,35,1}, /* core1 elr_EL1 bit18 */
			{30602,35,1}, /* core1 elr_EL1 bit19 */
			{37018,36,0}, /* core1 elr_EL1 bit20 */
			{37017,36,0}, /* core1 elr_EL1 bit21 */
			{30619,35,1}, /* core1 elr_EL1 bit22 */
			{30618,35,1}, /* core1 elr_EL1 bit23 */
			{30601,35,1}, /* core1 elr_EL1 bit24 */
			{30600,35,1}, /* core1 elr_EL1 bit25 */
			{30599,35,1}, /* core1 elr_EL1 bit26 */
			{30598,35,1}, /* core1 elr_EL1 bit27 */
			{37020,36,0}, /* core1 elr_EL1 bit28 */
			{37019,36,0}, /* core1 elr_EL1 bit29 */
			{37032,36,0}, /* core1 elr_EL1 bit30 */
			{37031,36,0}, /* core1 elr_EL1 bit31 */
			{27939,36,1}, /* core1 elr_EL1 bit32 */
			{27953,36,1}, /* core1 elr_EL1 bit33 */
			{37052,36,0}, /* core1 elr_EL1 bit34 */
			{37051,36,0}, /* core1 elr_EL1 bit35 */
			{37050,36,0}, /* core1 elr_EL1 bit36 */
			{37049,36,0}, /* core1 elr_EL1 bit37 */
			{27954,36,1}, /* core1 elr_EL1 bit38 */
			{27938,36,1}, /* core1 elr_EL1 bit39 */
			{30641,35,1}, /* core1 elr_EL1 bit40 */
			{30640,35,1}, /* core1 elr_EL1 bit41 */
			{30639,35,1}, /* core1 elr_EL1 bit42 */
			{30638,35,1}, /* core1 elr_EL1 bit43 */
			{37038,36,0}, /* core1 elr_EL1 bit44 */
			{37037,36,0}, /* core1 elr_EL1 bit45 */
			{27955,36,1}, /* core1 elr_EL1 bit46 */
			{27950,36,1}, /* core1 elr_EL1 bit47 */
			{27949,36,1}, /* core1 elr_EL1 bit48 */
			{27952,36,1}, /* core1 elr_EL1 bit49 */
			{37042,36,0}, /* core1 elr_EL1 bit50 */
			{37041,36,0}, /* core1 elr_EL1 bit51 */
			{37044,36,0}, /* core1 elr_EL1 bit52 */
			{37043,36,0}, /* core1 elr_EL1 bit53 */
			{37048,36,0}, /* core1 elr_EL1 bit54 */
			{37047,36,0}, /* core1 elr_EL1 bit55 */
			{37058,36,0}, /* core1 elr_EL1 bit56 */
			{37057,36,0}, /* core1 elr_EL1 bit57 */
			{37040,36,0}, /* core1 elr_EL1 bit58 */
			{37039,36,0}, /* core1 elr_EL1 bit59 */
			{37046,36,0}, /* core1 elr_EL1 bit60 */
			{37045,36,0}, /* core1 elr_EL1 bit61 */
			{27951,36,1}, /* core1 elr_EL1 bit62 */
			{27940,36,1}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{37553,35,1}, /* core1 elr_EL2 bit0 */
			{37552,35,1}, /* core1 elr_EL2 bit1 */
			{37551,35,1}, /* core1 elr_EL2 bit2 */
			{37550,35,1}, /* core1 elr_EL2 bit3 */
			{37549,35,1}, /* core1 elr_EL2 bit4 */
			{37548,35,1}, /* core1 elr_EL2 bit5 */
			{37547,35,1}, /* core1 elr_EL2 bit6 */
			{37546,35,1}, /* core1 elr_EL2 bit7 */
			{30629,35,1}, /* core1 elr_EL2 bit8 */
			{30628,35,1}, /* core1 elr_EL2 bit9 */
			{37537,35,1}, /* core1 elr_EL2 bit10 */
			{30627,35,1}, /* core1 elr_EL2 bit11 */
			{37536,35,1}, /* core1 elr_EL2 bit12 */
			{30626,35,1}, /* core1 elr_EL2 bit13 */
			{37535,35,1}, /* core1 elr_EL2 bit14 */
			{37534,35,1}, /* core1 elr_EL2 bit15 */
			{37533,35,1}, /* core1 elr_EL2 bit16 */
			{37532,35,1}, /* core1 elr_EL2 bit17 */
			{37531,35,1}, /* core1 elr_EL2 bit18 */
			{37530,35,1}, /* core1 elr_EL2 bit19 */
			{30609,35,1}, /* core1 elr_EL2 bit20 */
			{30608,35,1}, /* core1 elr_EL2 bit21 */
			{30607,35,1}, /* core1 elr_EL2 bit22 */
			{30606,35,1}, /* core1 elr_EL2 bit23 */
			{30613,35,1}, /* core1 elr_EL2 bit24 */
			{30612,35,1}, /* core1 elr_EL2 bit25 */
			{30611,35,1}, /* core1 elr_EL2 bit26 */
			{30610,35,1}, /* core1 elr_EL2 bit27 */
			{37024,36,0}, /* core1 elr_EL2 bit28 */
			{37023,36,0}, /* core1 elr_EL2 bit29 */
			{27873,36,1}, /* core1 elr_EL2 bit30 */
			{27878,36,1}, /* core1 elr_EL2 bit31 */
			{27943,36,1}, /* core1 elr_EL2 bit32 */
			{27956,36,1}, /* core1 elr_EL2 bit33 */
			{37054,36,0}, /* core1 elr_EL2 bit34 */
			{37053,36,0}, /* core1 elr_EL2 bit35 */
			{37056,36,0}, /* core1 elr_EL2 bit36 */
			{37055,36,0}, /* core1 elr_EL2 bit37 */
			{27957,36,1}, /* core1 elr_EL2 bit38 */
			{27942,36,1}, /* core1 elr_EL2 bit39 */
			{30637,35,1}, /* core1 elr_EL2 bit40 */
			{30636,35,1}, /* core1 elr_EL2 bit41 */
			{30635,35,1}, /* core1 elr_EL2 bit42 */
			{30634,35,1}, /* core1 elr_EL2 bit43 */
			{37070,36,0}, /* core1 elr_EL2 bit44 */
			{37069,36,0}, /* core1 elr_EL2 bit45 */
			{27958,36,1}, /* core1 elr_EL2 bit46 */
			{27948,36,1}, /* core1 elr_EL2 bit47 */
			{27947,36,1}, /* core1 elr_EL2 bit48 */
			{27959,36,1}, /* core1 elr_EL2 bit49 */
			{37066,36,0}, /* core1 elr_EL2 bit50 */
			{37065,36,0}, /* core1 elr_EL2 bit51 */
			{37062,36,0}, /* core1 elr_EL2 bit52 */
			{37061,36,0}, /* core1 elr_EL2 bit53 */
			{30633,35,1}, /* core1 elr_EL2 bit54 */
			{30632,35,1}, /* core1 elr_EL2 bit55 */
			{37060,36,0}, /* core1 elr_EL2 bit56 */
			{37059,36,0}, /* core1 elr_EL2 bit57 */
			{37068,36,0}, /* core1 elr_EL2 bit58 */
			{37067,36,0}, /* core1 elr_EL2 bit59 */
			{37064,36,0}, /* core1 elr_EL2 bit60 */
			{37063,36,0}, /* core1 elr_EL2 bit61 */
			{30631,35,1}, /* core1 elr_EL2 bit62 */
			{30630,35,1}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{37545,35,1}, /* core1 elr_EL3 bit0 */
			{37544,35,1}, /* core1 elr_EL3 bit1 */
			{37543,35,1}, /* core1 elr_EL3 bit2 */
			{37542,35,1}, /* core1 elr_EL3 bit3 */
			{37541,35,1}, /* core1 elr_EL3 bit4 */
			{37540,35,1}, /* core1 elr_EL3 bit5 */
			{37539,35,1}, /* core1 elr_EL3 bit6 */
			{37538,35,1}, /* core1 elr_EL3 bit7 */
			{37034,36,0}, /* core1 elr_EL3 bit8 */
			{37033,36,0}, /* core1 elr_EL3 bit9 */
			{30625,35,1}, /* core1 elr_EL3 bit10 */
			{30624,35,1}, /* core1 elr_EL3 bit11 */
			{30623,35,1}, /* core1 elr_EL3 bit12 */
			{30622,35,1}, /* core1 elr_EL3 bit13 */
			{37026,36,0}, /* core1 elr_EL3 bit14 */
			{37025,36,0}, /* core1 elr_EL3 bit15 */
			{37014,36,0}, /* core1 elr_EL3 bit16 */
			{37013,36,0}, /* core1 elr_EL3 bit17 */
			{27866,36,1}, /* core1 elr_EL3 bit18 */
			{27867,36,1}, /* core1 elr_EL3 bit19 */
			{30617,35,1}, /* core1 elr_EL3 bit20 */
			{30616,35,1}, /* core1 elr_EL3 bit21 */
			{30615,35,1}, /* core1 elr_EL3 bit22 */
			{30614,35,1}, /* core1 elr_EL3 bit23 */
			{27865,36,1}, /* core1 elr_EL3 bit24 */
			{27874,36,1}, /* core1 elr_EL3 bit25 */
			{37016,36,0}, /* core1 elr_EL3 bit26 */
			{37015,36,0}, /* core1 elr_EL3 bit27 */
			{37028,36,0}, /* core1 elr_EL3 bit28 */
			{37027,36,0}, /* core1 elr_EL3 bit29 */
			{27868,36,1}, /* core1 elr_EL3 bit30 */
			{27877,36,1}, /* core1 elr_EL3 bit31 */
			{30669,35,1}, /* core1 elr_EL3 bit32 */
			{30668,35,1}, /* core1 elr_EL3 bit33 */
			{30667,35,1}, /* core1 elr_EL3 bit34 */
			{30666,35,1}, /* core1 elr_EL3 bit35 */
			{30657,35,1}, /* core1 elr_EL3 bit36 */
			{30656,35,1}, /* core1 elr_EL3 bit37 */
			{30655,35,1}, /* core1 elr_EL3 bit38 */
			{30654,35,1}, /* core1 elr_EL3 bit39 */
			{37012,36,0}, /* core1 elr_EL3 bit40 */
			{37011,36,0}, /* core1 elr_EL3 bit41 */
			{27928,36,1}, /* core1 elr_EL3 bit42 */
			{27927,36,1}, /* core1 elr_EL3 bit43 */
			{30661,35,1}, /* core1 elr_EL3 bit44 */
			{30660,35,1}, /* core1 elr_EL3 bit45 */
			{30659,35,1}, /* core1 elr_EL3 bit46 */
			{30658,35,1}, /* core1 elr_EL3 bit47 */
			{30665,35,1}, /* core1 elr_EL3 bit48 */
			{30664,35,1}, /* core1 elr_EL3 bit49 */
			{30663,35,1}, /* core1 elr_EL3 bit50 */
			{30662,35,1}, /* core1 elr_EL3 bit51 */
			{30565,35,1}, /* core1 elr_EL3 bit52 */
			{30564,35,1}, /* core1 elr_EL3 bit53 */
			{30563,35,1}, /* core1 elr_EL3 bit54 */
			{30562,35,1}, /* core1 elr_EL3 bit55 */
			{37513,35,1}, /* core1 elr_EL3 bit56 */
			{37512,35,1}, /* core1 elr_EL3 bit57 */
			{37511,35,1}, /* core1 elr_EL3 bit58 */
			{37510,35,1}, /* core1 elr_EL3 bit59 */
			{37509,35,1}, /* core1 elr_EL3 bit60 */
			{37508,35,1}, /* core1 elr_EL3 bit61 */
			{37507,35,1}, /* core1 elr_EL3 bit62 */
			{37506,35,1}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31320,36,1}, /* core1 raw_pc bit0 */
			{31430,36,1}, /* core1 raw_pc bit1 */
			{32637,35,1}, /* core1 raw_pc bit2 */
			{32636,35,1}, /* core1 raw_pc bit3 */
			{32635,35,1}, /* core1 raw_pc bit4 */
			{32634,35,1}, /* core1 raw_pc bit5 */
			{31328,36,1}, /* core1 raw_pc bit6 */
			{39377,35,1}, /* core1 raw_pc bit7 */
			{39376,35,1}, /* core1 raw_pc bit8 */
			{39375,35,1}, /* core1 raw_pc bit9 */
			{39374,35,1}, /* core1 raw_pc bit10 */
			{39373,35,1}, /* core1 raw_pc bit11 */
			{39372,35,1}, /* core1 raw_pc bit12 */
			{39371,35,1}, /* core1 raw_pc bit13 */
			{39370,35,1}, /* core1 raw_pc bit14 */
			{39305,35,1}, /* core1 raw_pc bit15 */
			{39304,35,1}, /* core1 raw_pc bit16 */
			{39303,35,1}, /* core1 raw_pc bit17 */
			{39302,35,1}, /* core1 raw_pc bit18 */
			{39301,35,1}, /* core1 raw_pc bit19 */
			{39300,35,1}, /* core1 raw_pc bit20 */
			{39299,35,1}, /* core1 raw_pc bit21 */
			{39298,35,1}, /* core1 raw_pc bit22 */
			{39313,35,1}, /* core1 raw_pc bit23 */
			{39312,35,1}, /* core1 raw_pc bit24 */
			{39311,35,1}, /* core1 raw_pc bit25 */
			{39310,35,1}, /* core1 raw_pc bit26 */
			{39309,35,1}, /* core1 raw_pc bit27 */
			{39308,35,1}, /* core1 raw_pc bit28 */
			{39307,35,1}, /* core1 raw_pc bit29 */
			{39306,35,1}, /* core1 raw_pc bit30 */
			{39369,35,1}, /* core1 raw_pc bit31 */
			{39368,35,1}, /* core1 raw_pc bit32 */
			{39367,35,1}, /* core1 raw_pc bit33 */
			{39366,35,1}, /* core1 raw_pc bit34 */
			{39365,35,1}, /* core1 raw_pc bit35 */
			{39364,35,1}, /* core1 raw_pc bit36 */
			{39363,35,1}, /* core1 raw_pc bit37 */
			{39362,35,1}, /* core1 raw_pc bit38 */
			{39361,35,1}, /* core1 raw_pc bit39 */
			{39360,35,1}, /* core1 raw_pc bit40 */
			{39359,35,1}, /* core1 raw_pc bit41 */
			{39358,35,1}, /* core1 raw_pc bit42 */
			{39357,35,1}, /* core1 raw_pc bit43 */
			{39356,35,1}, /* core1 raw_pc bit44 */
			{39355,35,1}, /* core1 raw_pc bit45 */
			{39354,35,1}, /* core1 raw_pc bit46 */
			{38933,36,1}, /* core1 raw_pc bit47 */
			{38932,36,1}, /* core1 raw_pc bit48 */
			{31321,36,1}, /* core1 raw_pc bit49 */
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
			{31564,36,1}, /* core1 pc_iss bit0 */
			{31566,36,1}, /* core1 pc_iss bit1 */
			{38983,36,1}, /* core1 pc_iss bit2 */
			{38982,36,1}, /* core1 pc_iss bit3 */
			{32597,35,1}, /* core1 pc_iss bit4 */
			{32596,35,1}, /* core1 pc_iss bit5 */
			{32595,35,1}, /* core1 pc_iss bit6 */
			{32594,35,1}, /* core1 pc_iss bit7 */
			{31651,36,0}, /* core1 pc_iss bit8 */
			{31556,36,1}, /* core1 pc_iss bit9 */
			{31563,36,1}, /* core1 pc_iss bit10 */
			{31654,36,0}, /* core1 pc_iss bit11 */
			{31559,36,1}, /* core1 pc_iss bit12 */
			{31659,36,0}, /* core1 pc_iss bit13 */
			{31658,36,0}, /* core1 pc_iss bit14 */
			{31655,36,0}, /* core1 pc_iss bit15 */
			{31557,36,1}, /* core1 pc_iss bit16 */
			{31656,36,0}, /* core1 pc_iss bit17 */
			{31657,36,0}, /* core1 pc_iss bit18 */
			{31558,36,1}, /* core1 pc_iss bit19 */
			{32605,35,1}, /* core1 pc_iss bit20 */
			{32604,35,1}, /* core1 pc_iss bit21 */
			{32603,35,1}, /* core1 pc_iss bit22 */
			{32602,35,1}, /* core1 pc_iss bit23 */
			{38985,36,1}, /* core1 pc_iss bit24 */
			{38984,36,1}, /* core1 pc_iss bit25 */
			{31652,36,0}, /* core1 pc_iss bit26 */
			{31555,36,1}, /* core1 pc_iss bit27 */
			{32609,35,1}, /* core1 pc_iss bit28 */
			{32608,35,1}, /* core1 pc_iss bit29 */
			{32607,35,1}, /* core1 pc_iss bit30 */
			{32606,35,1}, /* core1 pc_iss bit31 */
			{31554,36,1}, /* core1 pc_iss bit32 */
			{31553,36,1}, /* core1 pc_iss bit33 */
			{38981,36,1}, /* core1 pc_iss bit34 */
			{38980,36,1}, /* core1 pc_iss bit35 */
			{32613,35,1}, /* core1 pc_iss bit36 */
			{32612,35,1}, /* core1 pc_iss bit37 */
			{32611,35,1}, /* core1 pc_iss bit38 */
			{32610,35,1}, /* core1 pc_iss bit39 */
			{39401,35,1}, /* core1 pc_iss bit40 */
			{39400,35,1}, /* core1 pc_iss bit41 */
			{39399,35,1}, /* core1 pc_iss bit42 */
			{39398,35,1}, /* core1 pc_iss bit43 */
			{39397,35,1}, /* core1 pc_iss bit44 */
			{39396,35,1}, /* core1 pc_iss bit45 */
			{39395,35,1}, /* core1 pc_iss bit46 */
			{39394,35,1}, /* core1 pc_iss bit47 */
			{32593,35,1}, /* core1 pc_iss bit48 */
			{32592,35,1}, /* core1 pc_iss bit49 */
			{32591,35,1}, /* core1 pc_iss bit50 */
			{32590,35,1}, /* core1 pc_iss bit51 */
			{38979,36,1}, /* core1 pc_iss bit52 */
			{38978,36,1}, /* core1 pc_iss bit53 */
			{31455,36,1}, /* core1 pc_iss bit54 */
			{31456,36,1}, /* core1 pc_iss bit55 */
			{31457,36,1}, /* core1 pc_iss bit56 */
			{31454,36,1}, /* core1 pc_iss bit57 */
			{31551,36,1}, /* core1 pc_iss bit58 */
			{31452,36,1}, /* core1 pc_iss bit59 */
			{31552,36,1}, /* core1 pc_iss bit60 */
			{31453,36,1}, /* core1 pc_iss bit61 */
			{38977,36,1}, /* core1 pc_iss bit62 */
			{38976,36,1}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31605,36,0}, /* core1 full_pc_wr bit0 */
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
			{31612,36,0}, /* core1 full_pc_ex1 bit0 */
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
			{32625,35,1}, /* core1 full_pc_ex2 bit0 */
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
			{16480,36,0}, /* core1 return_Stack_pointer bit0 */
			{16473,36,0}, /* core1 return_Stack_pointer bit1 */
			{16474,36,0}, /* core1 return_Stack_pointer bit2 */
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
			{20540,36,0}, /* core1 return_Stack0 bit0 */
			{20539,36,0}, /* core1 return_Stack0 bit1 */
			{20538,36,0}, /* core1 return_Stack0 bit2 */
			{20537,36,0}, /* core1 return_Stack0 bit3 */
			{20536,36,0}, /* core1 return_Stack0 bit4 */
			{20535,36,0}, /* core1 return_Stack0 bit5 */
			{20534,36,0}, /* core1 return_Stack0 bit6 */
			{20568,36,0}, /* core1 return_Stack0 bit7 */
			{20567,36,0}, /* core1 return_Stack0 bit8 */
			{20566,36,0}, /* core1 return_Stack0 bit9 */
			{20565,36,0}, /* core1 return_Stack0 bit10 */
			{20588,36,0}, /* core1 return_Stack0 bit11 */
			{20587,36,0}, /* core1 return_Stack0 bit12 */
			{20586,36,0}, /* core1 return_Stack0 bit13 */
			{20585,36,0}, /* core1 return_Stack0 bit14 */
			{20584,36,0}, /* core1 return_Stack0 bit15 */
			{20583,36,0}, /* core1 return_Stack0 bit16 */
			{20582,36,0}, /* core1 return_Stack0 bit17 */
			{20581,36,0}, /* core1 return_Stack0 bit18 */
			{20612,36,0}, /* core1 return_Stack0 bit19 */
			{20611,36,0}, /* core1 return_Stack0 bit20 */
			{20610,36,0}, /* core1 return_Stack0 bit21 */
			{20609,36,0}, /* core1 return_Stack0 bit22 */
			{20608,36,0}, /* core1 return_Stack0 bit23 */
			{20607,36,0}, /* core1 return_Stack0 bit24 */
			{20606,36,0}, /* core1 return_Stack0 bit25 */
			{20605,36,0}, /* core1 return_Stack0 bit26 */
			{20528,36,0}, /* core1 return_Stack0 bit27 */
			{20527,36,0}, /* core1 return_Stack0 bit28 */
			{20526,36,0}, /* core1 return_Stack0 bit29 */
			{20533,36,0}, /* core1 return_Stack0 bit30 */
			{16458,36,0}, /* core1 return_Stack0 bit31 */
			{20525,36,0}, /* core1 return_Stack0 bit32 */
			{16457,36,0}, /* core1 return_Stack0 bit33 */
			{16460,36,0}, /* core1 return_Stack0 bit34 */
			{16459,36,0}, /* core1 return_Stack0 bit35 */
			{20504,36,0}, /* core1 return_Stack0 bit36 */
			{20503,36,0}, /* core1 return_Stack0 bit37 */
			{20502,36,0}, /* core1 return_Stack0 bit38 */
			{20501,36,0}, /* core1 return_Stack0 bit39 */
			{20500,36,0}, /* core1 return_Stack0 bit40 */
			{20499,36,0}, /* core1 return_Stack0 bit41 */
			{20498,36,0}, /* core1 return_Stack0 bit42 */
			{20497,36,0}, /* core1 return_Stack0 bit43 */
			{20496,36,0}, /* core1 return_Stack0 bit44 */
			{20495,36,0}, /* core1 return_Stack0 bit45 */
			{20494,36,0}, /* core1 return_Stack0 bit46 */
			{20493,36,0}, /* core1 return_Stack0 bit47 */
			{13577,36,1}, /* core1 return_Stack0 bit48 */
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
			{20548,36,0}, /* core1 return_Stack1 bit0 */
			{20547,36,0}, /* core1 return_Stack1 bit1 */
			{20546,36,0}, /* core1 return_Stack1 bit2 */
			{20545,36,0}, /* core1 return_Stack1 bit3 */
			{20552,36,0}, /* core1 return_Stack1 bit4 */
			{20551,36,0}, /* core1 return_Stack1 bit5 */
			{20550,36,0}, /* core1 return_Stack1 bit6 */
			{20564,36,0}, /* core1 return_Stack1 bit7 */
			{20563,36,0}, /* core1 return_Stack1 bit8 */
			{20562,36,0}, /* core1 return_Stack1 bit9 */
			{20561,36,0}, /* core1 return_Stack1 bit10 */
			{20592,36,0}, /* core1 return_Stack1 bit11 */
			{20591,36,0}, /* core1 return_Stack1 bit12 */
			{20590,36,0}, /* core1 return_Stack1 bit13 */
			{20589,36,0}, /* core1 return_Stack1 bit14 */
			{20600,36,0}, /* core1 return_Stack1 bit15 */
			{20599,36,0}, /* core1 return_Stack1 bit16 */
			{20598,36,0}, /* core1 return_Stack1 bit17 */
			{20597,36,0}, /* core1 return_Stack1 bit18 */
			{20580,36,0}, /* core1 return_Stack1 bit19 */
			{20579,36,0}, /* core1 return_Stack1 bit20 */
			{20578,36,0}, /* core1 return_Stack1 bit21 */
			{20577,36,0}, /* core1 return_Stack1 bit22 */
			{20572,36,0}, /* core1 return_Stack1 bit23 */
			{20571,36,0}, /* core1 return_Stack1 bit24 */
			{20570,36,0}, /* core1 return_Stack1 bit25 */
			{20569,36,0}, /* core1 return_Stack1 bit26 */
			{20532,36,0}, /* core1 return_Stack1 bit27 */
			{20531,36,0}, /* core1 return_Stack1 bit28 */
			{20530,36,0}, /* core1 return_Stack1 bit29 */
			{20529,36,0}, /* core1 return_Stack1 bit30 */
			{20549,36,0}, /* core1 return_Stack1 bit31 */
			{13574,36,1}, /* core1 return_Stack1 bit32 */
			{20520,36,0}, /* core1 return_Stack1 bit33 */
			{20519,36,0}, /* core1 return_Stack1 bit34 */
			{20518,36,0}, /* core1 return_Stack1 bit35 */
			{20517,36,0}, /* core1 return_Stack1 bit36 */
			{20516,36,0}, /* core1 return_Stack1 bit37 */
			{20515,36,0}, /* core1 return_Stack1 bit38 */
			{20514,36,0}, /* core1 return_Stack1 bit39 */
			{20513,36,0}, /* core1 return_Stack1 bit40 */
			{20492,36,0}, /* core1 return_Stack1 bit41 */
			{20491,36,0}, /* core1 return_Stack1 bit42 */
			{20490,36,0}, /* core1 return_Stack1 bit43 */
			{20489,36,0}, /* core1 return_Stack1 bit44 */
			{20488,36,0}, /* core1 return_Stack1 bit45 */
			{20487,36,0}, /* core1 return_Stack1 bit46 */
			{20486,36,0}, /* core1 return_Stack1 bit47 */
			{20485,36,0}, /* core1 return_Stack1 bit48 */
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
			{20544,36,0}, /* core1 return_Stack2 bit0 */
			{20543,36,0}, /* core1 return_Stack2 bit1 */
			{20542,36,0}, /* core1 return_Stack2 bit2 */
			{20541,36,0}, /* core1 return_Stack2 bit3 */
			{20556,36,0}, /* core1 return_Stack2 bit4 */
			{20555,36,0}, /* core1 return_Stack2 bit5 */
			{20554,36,0}, /* core1 return_Stack2 bit6 */
			{20553,36,0}, /* core1 return_Stack2 bit7 */
			{20560,36,0}, /* core1 return_Stack2 bit8 */
			{20559,36,0}, /* core1 return_Stack2 bit9 */
			{20558,36,0}, /* core1 return_Stack2 bit10 */
			{20557,36,0}, /* core1 return_Stack2 bit11 */
			{20596,36,0}, /* core1 return_Stack2 bit12 */
			{20595,36,0}, /* core1 return_Stack2 bit13 */
			{16346,36,0}, /* core1 return_Stack2 bit14 */
			{20594,36,0}, /* core1 return_Stack2 bit15 */
			{16345,36,0}, /* core1 return_Stack2 bit16 */
			{20593,36,0}, /* core1 return_Stack2 bit17 */
			{16344,36,0}, /* core1 return_Stack2 bit18 */
			{20576,36,0}, /* core1 return_Stack2 bit19 */
			{20575,36,0}, /* core1 return_Stack2 bit20 */
			{20574,36,0}, /* core1 return_Stack2 bit21 */
			{20573,36,0}, /* core1 return_Stack2 bit22 */
			{20604,36,0}, /* core1 return_Stack2 bit23 */
			{20603,36,0}, /* core1 return_Stack2 bit24 */
			{20602,36,0}, /* core1 return_Stack2 bit25 */
			{20601,36,0}, /* core1 return_Stack2 bit26 */
			{16343,36,0}, /* core1 return_Stack2 bit27 */
			{16512,36,0}, /* core1 return_Stack2 bit28 */
			{16511,36,0}, /* core1 return_Stack2 bit29 */
			{20524,36,0}, /* core1 return_Stack2 bit30 */
			{20523,36,0}, /* core1 return_Stack2 bit31 */
			{13573,36,1}, /* core1 return_Stack2 bit32 */
			{20522,36,0}, /* core1 return_Stack2 bit33 */
			{20521,36,0}, /* core1 return_Stack2 bit34 */
			{20512,36,0}, /* core1 return_Stack2 bit35 */
			{20511,36,0}, /* core1 return_Stack2 bit36 */
			{20510,36,0}, /* core1 return_Stack2 bit37 */
			{20509,36,0}, /* core1 return_Stack2 bit38 */
			{20508,36,0}, /* core1 return_Stack2 bit39 */
			{20507,36,0}, /* core1 return_Stack2 bit40 */
			{20506,36,0}, /* core1 return_Stack2 bit41 */
			{20505,36,0}, /* core1 return_Stack2 bit42 */
			{20460,36,0}, /* core1 return_Stack2 bit43 */
			{20459,36,0}, /* core1 return_Stack2 bit44 */
			{20458,36,0}, /* core1 return_Stack2 bit45 */
			{20457,36,0}, /* core1 return_Stack2 bit46 */
			{13583,36,1}, /* core1 return_Stack2 bit47 */
			{13584,36,1}, /* core1 return_Stack2 bit48 */
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
			{20362,36,0}, /* core1 return_Stack3 bit0 */
			{20361,36,0}, /* core1 return_Stack3 bit1 */
			{20360,36,0}, /* core1 return_Stack3 bit2 */
			{20359,36,0}, /* core1 return_Stack3 bit3 */
			{20270,36,0}, /* core1 return_Stack3 bit4 */
			{20269,36,0}, /* core1 return_Stack3 bit5 */
			{20366,36,0}, /* core1 return_Stack3 bit6 */
			{20268,36,0}, /* core1 return_Stack3 bit7 */
			{20267,36,0}, /* core1 return_Stack3 bit8 */
			{20418,36,0}, /* core1 return_Stack3 bit9 */
			{20417,36,0}, /* core1 return_Stack3 bit10 */
			{20416,36,0}, /* core1 return_Stack3 bit11 */
			{20415,36,0}, /* core1 return_Stack3 bit12 */
			{16362,36,0}, /* core1 return_Stack3 bit13 */
			{16361,36,0}, /* core1 return_Stack3 bit14 */
			{16360,36,0}, /* core1 return_Stack3 bit15 */
			{16359,36,0}, /* core1 return_Stack3 bit16 */
			{16338,36,0}, /* core1 return_Stack3 bit17 */
			{16337,36,0}, /* core1 return_Stack3 bit18 */
			{16340,36,0}, /* core1 return_Stack3 bit19 */
			{16339,36,0}, /* core1 return_Stack3 bit20 */
			{16498,36,0}, /* core1 return_Stack3 bit21 */
			{16497,36,0}, /* core1 return_Stack3 bit22 */
			{16500,36,0}, /* core1 return_Stack3 bit23 */
			{16499,36,0}, /* core1 return_Stack3 bit24 */
			{16504,36,0}, /* core1 return_Stack3 bit25 */
			{16503,36,0}, /* core1 return_Stack3 bit26 */
			{16508,36,0}, /* core1 return_Stack3 bit27 */
			{16507,36,0}, /* core1 return_Stack3 bit28 */
			{16518,36,0}, /* core1 return_Stack3 bit29 */
			{20365,36,0}, /* core1 return_Stack3 bit30 */
			{20364,36,0}, /* core1 return_Stack3 bit31 */
			{16517,36,0}, /* core1 return_Stack3 bit32 */
			{20363,36,0}, /* core1 return_Stack3 bit33 */
			{20310,36,0}, /* core1 return_Stack3 bit34 */
			{20309,36,0}, /* core1 return_Stack3 bit35 */
			{20308,36,0}, /* core1 return_Stack3 bit36 */
			{20307,36,0}, /* core1 return_Stack3 bit37 */
			{20318,36,0}, /* core1 return_Stack3 bit38 */
			{20317,36,0}, /* core1 return_Stack3 bit39 */
			{20316,36,0}, /* core1 return_Stack3 bit40 */
			{20315,36,0}, /* core1 return_Stack3 bit41 */
			{20342,36,0}, /* core1 return_Stack3 bit42 */
			{20341,36,0}, /* core1 return_Stack3 bit43 */
			{20340,36,0}, /* core1 return_Stack3 bit44 */
			{20339,36,0}, /* core1 return_Stack3 bit45 */
			{16440,36,0}, /* core1 return_Stack3 bit46 */
			{16439,36,0}, /* core1 return_Stack3 bit47 */
			{13581,36,1}, /* core1 return_Stack3 bit48 */
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
			{20370,36,0}, /* core1 return_Stack4 bit0 */
			{20369,36,0}, /* core1 return_Stack4 bit1 */
			{20368,36,0}, /* core1 return_Stack4 bit2 */
			{20367,36,0}, /* core1 return_Stack4 bit3 */
			{20374,36,0}, /* core1 return_Stack4 bit4 */
			{20373,36,0}, /* core1 return_Stack4 bit5 */
			{20372,36,0}, /* core1 return_Stack4 bit6 */
			{20371,36,0}, /* core1 return_Stack4 bit7 */
			{20378,36,0}, /* core1 return_Stack4 bit8 */
			{20377,36,0}, /* core1 return_Stack4 bit9 */
			{20376,36,0}, /* core1 return_Stack4 bit10 */
			{20375,36,0}, /* core1 return_Stack4 bit11 */
			{20398,36,0}, /* core1 return_Stack4 bit12 */
			{20397,36,0}, /* core1 return_Stack4 bit13 */
			{20396,36,0}, /* core1 return_Stack4 bit14 */
			{20395,36,0}, /* core1 return_Stack4 bit15 */
			{20394,36,0}, /* core1 return_Stack4 bit16 */
			{20393,36,0}, /* core1 return_Stack4 bit17 */
			{20392,36,0}, /* core1 return_Stack4 bit18 */
			{20391,36,0}, /* core1 return_Stack4 bit19 */
			{20430,36,0}, /* core1 return_Stack4 bit20 */
			{20429,36,0}, /* core1 return_Stack4 bit21 */
			{20428,36,0}, /* core1 return_Stack4 bit22 */
			{20427,36,0}, /* core1 return_Stack4 bit23 */
			{20434,36,0}, /* core1 return_Stack4 bit24 */
			{20433,36,0}, /* core1 return_Stack4 bit25 */
			{20432,36,0}, /* core1 return_Stack4 bit26 */
			{20431,36,0}, /* core1 return_Stack4 bit27 */
			{16506,36,0}, /* core1 return_Stack4 bit28 */
			{16505,36,0}, /* core1 return_Stack4 bit29 */
			{16456,36,0}, /* core1 return_Stack4 bit30 */
			{16455,36,0}, /* core1 return_Stack4 bit31 */
			{16454,36,0}, /* core1 return_Stack4 bit32 */
			{16453,36,0}, /* core1 return_Stack4 bit33 */
			{16446,36,0}, /* core1 return_Stack4 bit34 */
			{20314,36,0}, /* core1 return_Stack4 bit35 */
			{20313,36,0}, /* core1 return_Stack4 bit36 */
			{20312,36,0}, /* core1 return_Stack4 bit37 */
			{20311,36,0}, /* core1 return_Stack4 bit38 */
			{20306,36,0}, /* core1 return_Stack4 bit39 */
			{20305,36,0}, /* core1 return_Stack4 bit40 */
			{20304,36,0}, /* core1 return_Stack4 bit41 */
			{20303,36,0}, /* core1 return_Stack4 bit42 */
			{20298,36,0}, /* core1 return_Stack4 bit43 */
			{20297,36,0}, /* core1 return_Stack4 bit44 */
			{20296,36,0}, /* core1 return_Stack4 bit45 */
			{20295,36,0}, /* core1 return_Stack4 bit46 */
			{16445,36,0}, /* core1 return_Stack4 bit47 */
			{13576,36,1}, /* core1 return_Stack4 bit48 */
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
			{16444,36,0}, /* core1 return_Stack5 bit0 */
			{20262,36,0}, /* core1 return_Stack5 bit1 */
			{16443,36,0}, /* core1 return_Stack5 bit2 */
			{16438,36,0}, /* core1 return_Stack5 bit3 */
			{20261,36,0}, /* core1 return_Stack5 bit4 */
			{20260,36,0}, /* core1 return_Stack5 bit5 */
			{20259,36,0}, /* core1 return_Stack5 bit6 */
			{20266,36,0}, /* core1 return_Stack5 bit7 */
			{20265,36,0}, /* core1 return_Stack5 bit8 */
			{20264,36,0}, /* core1 return_Stack5 bit9 */
			{20263,36,0}, /* core1 return_Stack5 bit10 */
			{16437,36,0}, /* core1 return_Stack5 bit11 */
			{20402,36,0}, /* core1 return_Stack5 bit12 */
			{20401,36,0}, /* core1 return_Stack5 bit13 */
			{20400,36,0}, /* core1 return_Stack5 bit14 */
			{20399,36,0}, /* core1 return_Stack5 bit15 */
			{16364,36,0}, /* core1 return_Stack5 bit16 */
			{16363,36,0}, /* core1 return_Stack5 bit17 */
			{16342,36,0}, /* core1 return_Stack5 bit18 */
			{16341,36,0}, /* core1 return_Stack5 bit19 */
			{20390,36,0}, /* core1 return_Stack5 bit20 */
			{20389,36,0}, /* core1 return_Stack5 bit21 */
			{20388,36,0}, /* core1 return_Stack5 bit22 */
			{20387,36,0}, /* core1 return_Stack5 bit23 */
			{20282,36,0}, /* core1 return_Stack5 bit24 */
			{20281,36,0}, /* core1 return_Stack5 bit25 */
			{20280,36,0}, /* core1 return_Stack5 bit26 */
			{20279,36,0}, /* core1 return_Stack5 bit27 */
			{16514,36,0}, /* core1 return_Stack5 bit28 */
			{16513,36,0}, /* core1 return_Stack5 bit29 */
			{16452,36,0}, /* core1 return_Stack5 bit30 */
			{20286,36,0}, /* core1 return_Stack5 bit31 */
			{16451,36,0}, /* core1 return_Stack5 bit32 */
			{20285,36,0}, /* core1 return_Stack5 bit33 */
			{20284,36,0}, /* core1 return_Stack5 bit34 */
			{20283,36,0}, /* core1 return_Stack5 bit35 */
			{20326,36,0}, /* core1 return_Stack5 bit36 */
			{20325,36,0}, /* core1 return_Stack5 bit37 */
			{20324,36,0}, /* core1 return_Stack5 bit38 */
			{20323,36,0}, /* core1 return_Stack5 bit39 */
			{20338,36,0}, /* core1 return_Stack5 bit40 */
			{20337,36,0}, /* core1 return_Stack5 bit41 */
			{20336,36,0}, /* core1 return_Stack5 bit42 */
			{20335,36,0}, /* core1 return_Stack5 bit43 */
			{20354,36,0}, /* core1 return_Stack5 bit44 */
			{20353,36,0}, /* core1 return_Stack5 bit45 */
			{20352,36,0}, /* core1 return_Stack5 bit46 */
			{20351,36,0}, /* core1 return_Stack5 bit47 */
			{13580,36,1}, /* core1 return_Stack5 bit48 */
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
			{20358,36,0}, /* core1 return_Stack6 bit0 */
			{20357,36,0}, /* core1 return_Stack6 bit1 */
			{20356,36,0}, /* core1 return_Stack6 bit2 */
			{20355,36,0}, /* core1 return_Stack6 bit3 */
			{20258,36,0}, /* core1 return_Stack6 bit4 */
			{20257,36,0}, /* core1 return_Stack6 bit5 */
			{20256,36,0}, /* core1 return_Stack6 bit6 */
			{20255,36,0}, /* core1 return_Stack6 bit7 */
			{16436,36,0}, /* core1 return_Stack6 bit8 */
			{20410,36,0}, /* core1 return_Stack6 bit9 */
			{16435,36,0}, /* core1 return_Stack6 bit10 */
			{20409,36,0}, /* core1 return_Stack6 bit11 */
			{20408,36,0}, /* core1 return_Stack6 bit12 */
			{20407,36,0}, /* core1 return_Stack6 bit13 */
			{16356,36,0}, /* core1 return_Stack6 bit14 */
			{16355,36,0}, /* core1 return_Stack6 bit15 */
			{16358,36,0}, /* core1 return_Stack6 bit16 */
			{16357,36,0}, /* core1 return_Stack6 bit17 */
			{20386,36,0}, /* core1 return_Stack6 bit18 */
			{20385,36,0}, /* core1 return_Stack6 bit19 */
			{20384,36,0}, /* core1 return_Stack6 bit20 */
			{20383,36,0}, /* core1 return_Stack6 bit21 */
			{20382,36,0}, /* core1 return_Stack6 bit22 */
			{20381,36,0}, /* core1 return_Stack6 bit23 */
			{20380,36,0}, /* core1 return_Stack6 bit24 */
			{20379,36,0}, /* core1 return_Stack6 bit25 */
			{20278,36,0}, /* core1 return_Stack6 bit26 */
			{20277,36,0}, /* core1 return_Stack6 bit27 */
			{20276,36,0}, /* core1 return_Stack6 bit28 */
			{20275,36,0}, /* core1 return_Stack6 bit29 */
			{16448,36,0}, /* core1 return_Stack6 bit30 */
			{16447,36,0}, /* core1 return_Stack6 bit31 */
			{16450,36,0}, /* core1 return_Stack6 bit32 */
			{16449,36,0}, /* core1 return_Stack6 bit33 */
			{20302,36,0}, /* core1 return_Stack6 bit34 */
			{20301,36,0}, /* core1 return_Stack6 bit35 */
			{20300,36,0}, /* core1 return_Stack6 bit36 */
			{20299,36,0}, /* core1 return_Stack6 bit37 */
			{20334,36,0}, /* core1 return_Stack6 bit38 */
			{20333,36,0}, /* core1 return_Stack6 bit39 */
			{20332,36,0}, /* core1 return_Stack6 bit40 */
			{20331,36,0}, /* core1 return_Stack6 bit41 */
			{20346,36,0}, /* core1 return_Stack6 bit42 */
			{20345,36,0}, /* core1 return_Stack6 bit43 */
			{20344,36,0}, /* core1 return_Stack6 bit44 */
			{20343,36,0}, /* core1 return_Stack6 bit45 */
			{16442,36,0}, /* core1 return_Stack6 bit46 */
			{16441,36,0}, /* core1 return_Stack6 bit47 */
			{13582,36,1}, /* core1 return_Stack6 bit48 */
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
			{20294,36,0}, /* core1 return_Stack7 bit0 */
			{20293,36,0}, /* core1 return_Stack7 bit1 */
			{20292,36,0}, /* core1 return_Stack7 bit2 */
			{20291,36,0}, /* core1 return_Stack7 bit3 */
			{20274,36,0}, /* core1 return_Stack7 bit4 */
			{20273,36,0}, /* core1 return_Stack7 bit5 */
			{20290,36,0}, /* core1 return_Stack7 bit6 */
			{20272,36,0}, /* core1 return_Stack7 bit7 */
			{20271,36,0}, /* core1 return_Stack7 bit8 */
			{20414,36,0}, /* core1 return_Stack7 bit9 */
			{20413,36,0}, /* core1 return_Stack7 bit10 */
			{20412,36,0}, /* core1 return_Stack7 bit11 */
			{20411,36,0}, /* core1 return_Stack7 bit12 */
			{20406,36,0}, /* core1 return_Stack7 bit13 */
			{20405,36,0}, /* core1 return_Stack7 bit14 */
			{20404,36,0}, /* core1 return_Stack7 bit15 */
			{20403,36,0}, /* core1 return_Stack7 bit16 */
			{20422,36,0}, /* core1 return_Stack7 bit17 */
			{20421,36,0}, /* core1 return_Stack7 bit18 */
			{20426,36,0}, /* core1 return_Stack7 bit19 */
			{20420,36,0}, /* core1 return_Stack7 bit20 */
			{20419,36,0}, /* core1 return_Stack7 bit21 */
			{20425,36,0}, /* core1 return_Stack7 bit22 */
			{20424,36,0}, /* core1 return_Stack7 bit23 */
			{20423,36,0}, /* core1 return_Stack7 bit24 */
			{16502,36,0}, /* core1 return_Stack7 bit25 */
			{16501,36,0}, /* core1 return_Stack7 bit26 */
			{16510,36,0}, /* core1 return_Stack7 bit27 */
			{16509,36,0}, /* core1 return_Stack7 bit28 */
			{16516,36,0}, /* core1 return_Stack7 bit29 */
			{16515,36,0}, /* core1 return_Stack7 bit30 */
			{20289,36,0}, /* core1 return_Stack7 bit31 */
			{13575,36,1}, /* core1 return_Stack7 bit32 */
			{20288,36,0}, /* core1 return_Stack7 bit33 */
			{20287,36,0}, /* core1 return_Stack7 bit34 */
			{20322,36,0}, /* core1 return_Stack7 bit35 */
			{20321,36,0}, /* core1 return_Stack7 bit36 */
			{20320,36,0}, /* core1 return_Stack7 bit37 */
			{20319,36,0}, /* core1 return_Stack7 bit38 */
			{20330,36,0}, /* core1 return_Stack7 bit39 */
			{20329,36,0}, /* core1 return_Stack7 bit40 */
			{20328,36,0}, /* core1 return_Stack7 bit41 */
			{20327,36,0}, /* core1 return_Stack7 bit42 */
			{20350,36,0}, /* core1 return_Stack7 bit43 */
			{20349,36,0}, /* core1 return_Stack7 bit44 */
			{20348,36,0}, /* core1 return_Stack7 bit45 */
			{20347,36,0}, /* core1 return_Stack7 bit46 */
			{13579,36,1}, /* core1 return_Stack7 bit47 */
			{13578,36,1}, /* core1 return_Stack7 bit48 */
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
			.L2_parity_err_count = {{
			{ 6937, 8,0}, /* core1 L2_parity_err_count bit0 */
			{ 6936, 8,0}, /* core1 L2_parity_err_count bit1 */
			{ 6935, 8,0}, /* core1 L2_parity_err_count bit2 */
			{ 6934, 8,0}, /* core1 L2_parity_err_count bit3 */
			{ 6933, 8,0}, /* core1 L2_parity_err_count bit4 */
			{ 6932, 8,0}, /* core1 L2_parity_err_count bit5 */
			{ 6931, 8,0}, /* core1 L2_parity_err_count bit6 */
			{ 6930, 8,0}, /* core1 L2_parity_err_count bit7 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit8 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit9 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit10 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit11 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit12 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit13 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit14 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit15 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit16 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit17 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit18 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit19 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit20 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit21 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit22 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit23 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit24 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit25 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit26 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit27 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit28 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit29 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit30 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit31 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit32 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit33 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit34 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit35 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit36 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit37 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit38 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit39 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit40 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit41 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit42 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit43 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit44 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit45 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit46 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit47 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit48 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit49 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit50 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit51 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit52 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit53 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit54 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit55 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit56 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit57 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit58 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit59 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit60 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit61 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit62 */
			{    0, 0,2}, /* core1 L2_parity_err_count bit63 */
			}},
			.L2_parity_index = {{
			{ 6700, 8,0}, /* core1 L2_parity_index bit0 */
			{ 6699, 8,0}, /* core1 L2_parity_index bit1 */
			{ 6698, 8,0}, /* core1 L2_parity_index bit2 */
			{ 6697, 8,0}, /* core1 L2_parity_index bit3 */
			{ 6696, 8,0}, /* core1 L2_parity_index bit4 */
			{ 6695, 8,0}, /* core1 L2_parity_index bit5 */
			{ 6694, 8,0}, /* core1 L2_parity_index bit6 */
			{ 6693, 8,0}, /* core1 L2_parity_index bit7 */
			{ 6724, 8,0}, /* core1 L2_parity_index bit8 */
			{ 6723, 8,0}, /* core1 L2_parity_index bit9 */
			{ 6722, 8,0}, /* core1 L2_parity_index bit10 */
			{ 6721, 8,0}, /* core1 L2_parity_index bit11 */
			{    0, 0,2}, /* core1 L2_parity_index bit12 */
			{    0, 0,2}, /* core1 L2_parity_index bit13 */
			{    0, 0,2}, /* core1 L2_parity_index bit14 */
			{    0, 0,2}, /* core1 L2_parity_index bit15 */
			{    0, 0,2}, /* core1 L2_parity_index bit16 */
			{    0, 0,2}, /* core1 L2_parity_index bit17 */
			{    0, 0,2}, /* core1 L2_parity_index bit18 */
			{    0, 0,2}, /* core1 L2_parity_index bit19 */
			{    0, 0,2}, /* core1 L2_parity_index bit20 */
			{    0, 0,2}, /* core1 L2_parity_index bit21 */
			{    0, 0,2}, /* core1 L2_parity_index bit22 */
			{    0, 0,2}, /* core1 L2_parity_index bit23 */
			{    0, 0,2}, /* core1 L2_parity_index bit24 */
			{    0, 0,2}, /* core1 L2_parity_index bit25 */
			{    0, 0,2}, /* core1 L2_parity_index bit26 */
			{    0, 0,2}, /* core1 L2_parity_index bit27 */
			{    0, 0,2}, /* core1 L2_parity_index bit28 */
			{    0, 0,2}, /* core1 L2_parity_index bit29 */
			{    0, 0,2}, /* core1 L2_parity_index bit30 */
			{    0, 0,2}, /* core1 L2_parity_index bit31 */
			{    0, 0,2}, /* core1 L2_parity_index bit32 */
			{    0, 0,2}, /* core1 L2_parity_index bit33 */
			{    0, 0,2}, /* core1 L2_parity_index bit34 */
			{    0, 0,2}, /* core1 L2_parity_index bit35 */
			{    0, 0,2}, /* core1 L2_parity_index bit36 */
			{    0, 0,2}, /* core1 L2_parity_index bit37 */
			{    0, 0,2}, /* core1 L2_parity_index bit38 */
			{    0, 0,2}, /* core1 L2_parity_index bit39 */
			{    0, 0,2}, /* core1 L2_parity_index bit40 */
			{    0, 0,2}, /* core1 L2_parity_index bit41 */
			{    0, 0,2}, /* core1 L2_parity_index bit42 */
			{    0, 0,2}, /* core1 L2_parity_index bit43 */
			{    0, 0,2}, /* core1 L2_parity_index bit44 */
			{    0, 0,2}, /* core1 L2_parity_index bit45 */
			{    0, 0,2}, /* core1 L2_parity_index bit46 */
			{    0, 0,2}, /* core1 L2_parity_index bit47 */
			{    0, 0,2}, /* core1 L2_parity_index bit48 */
			{    0, 0,2}, /* core1 L2_parity_index bit49 */
			{    0, 0,2}, /* core1 L2_parity_index bit50 */
			{    0, 0,2}, /* core1 L2_parity_index bit51 */
			{    0, 0,2}, /* core1 L2_parity_index bit52 */
			{    0, 0,2}, /* core1 L2_parity_index bit53 */
			{    0, 0,2}, /* core1 L2_parity_index bit54 */
			{    0, 0,2}, /* core1 L2_parity_index bit55 */
			{    0, 0,2}, /* core1 L2_parity_index bit56 */
			{    0, 0,2}, /* core1 L2_parity_index bit57 */
			{    0, 0,2}, /* core1 L2_parity_index bit58 */
			{    0, 0,2}, /* core1 L2_parity_index bit59 */
			{    0, 0,2}, /* core1 L2_parity_index bit60 */
			{    0, 0,2}, /* core1 L2_parity_index bit61 */
			{    0, 0,2}, /* core1 L2_parity_index bit62 */
			{    0, 0,2}, /* core1 L2_parity_index bit63 */
			}},
			.L2_parity_way = {{
			{ 6717, 8,0}, /* core1 L2_parity_way bit0 */
			{ 6467, 8,0}, /* core1 L2_parity_way bit1 */
			{    0, 0,2}, /* core1 L2_parity_way bit2 */
			{    0, 0,2}, /* core1 L2_parity_way bit3 */
			{    0, 0,2}, /* core1 L2_parity_way bit4 */
			{    0, 0,2}, /* core1 L2_parity_way bit5 */
			{    0, 0,2}, /* core1 L2_parity_way bit6 */
			{    0, 0,2}, /* core1 L2_parity_way bit7 */
			{    0, 0,2}, /* core1 L2_parity_way bit8 */
			{    0, 0,2}, /* core1 L2_parity_way bit9 */
			{    0, 0,2}, /* core1 L2_parity_way bit10 */
			{    0, 0,2}, /* core1 L2_parity_way bit11 */
			{    0, 0,2}, /* core1 L2_parity_way bit12 */
			{    0, 0,2}, /* core1 L2_parity_way bit13 */
			{    0, 0,2}, /* core1 L2_parity_way bit14 */
			{    0, 0,2}, /* core1 L2_parity_way bit15 */
			{    0, 0,2}, /* core1 L2_parity_way bit16 */
			{    0, 0,2}, /* core1 L2_parity_way bit17 */
			{    0, 0,2}, /* core1 L2_parity_way bit18 */
			{    0, 0,2}, /* core1 L2_parity_way bit19 */
			{    0, 0,2}, /* core1 L2_parity_way bit20 */
			{    0, 0,2}, /* core1 L2_parity_way bit21 */
			{    0, 0,2}, /* core1 L2_parity_way bit22 */
			{    0, 0,2}, /* core1 L2_parity_way bit23 */
			{    0, 0,2}, /* core1 L2_parity_way bit24 */
			{    0, 0,2}, /* core1 L2_parity_way bit25 */
			{    0, 0,2}, /* core1 L2_parity_way bit26 */
			{    0, 0,2}, /* core1 L2_parity_way bit27 */
			{    0, 0,2}, /* core1 L2_parity_way bit28 */
			{    0, 0,2}, /* core1 L2_parity_way bit29 */
			{    0, 0,2}, /* core1 L2_parity_way bit30 */
			{    0, 0,2}, /* core1 L2_parity_way bit31 */
			{    0, 0,2}, /* core1 L2_parity_way bit32 */
			{    0, 0,2}, /* core1 L2_parity_way bit33 */
			{    0, 0,2}, /* core1 L2_parity_way bit34 */
			{    0, 0,2}, /* core1 L2_parity_way bit35 */
			{    0, 0,2}, /* core1 L2_parity_way bit36 */
			{    0, 0,2}, /* core1 L2_parity_way bit37 */
			{    0, 0,2}, /* core1 L2_parity_way bit38 */
			{    0, 0,2}, /* core1 L2_parity_way bit39 */
			{    0, 0,2}, /* core1 L2_parity_way bit40 */
			{    0, 0,2}, /* core1 L2_parity_way bit41 */
			{    0, 0,2}, /* core1 L2_parity_way bit42 */
			{    0, 0,2}, /* core1 L2_parity_way bit43 */
			{    0, 0,2}, /* core1 L2_parity_way bit44 */
			{    0, 0,2}, /* core1 L2_parity_way bit45 */
			{    0, 0,2}, /* core1 L2_parity_way bit46 */
			{    0, 0,2}, /* core1 L2_parity_way bit47 */
			{    0, 0,2}, /* core1 L2_parity_way bit48 */
			{    0, 0,2}, /* core1 L2_parity_way bit49 */
			{    0, 0,2}, /* core1 L2_parity_way bit50 */
			{    0, 0,2}, /* core1 L2_parity_way bit51 */
			{    0, 0,2}, /* core1 L2_parity_way bit52 */
			{    0, 0,2}, /* core1 L2_parity_way bit53 */
			{    0, 0,2}, /* core1 L2_parity_way bit54 */
			{    0, 0,2}, /* core1 L2_parity_way bit55 */
			{    0, 0,2}, /* core1 L2_parity_way bit56 */
			{    0, 0,2}, /* core1 L2_parity_way bit57 */
			{    0, 0,2}, /* core1 L2_parity_way bit58 */
			{    0, 0,2}, /* core1 L2_parity_way bit59 */
			{    0, 0,2}, /* core1 L2_parity_way bit60 */
			{    0, 0,2}, /* core1 L2_parity_way bit61 */
			{    0, 0,2}, /* core1 L2_parity_way bit62 */
			{    0, 0,2}, /* core1 L2_parity_way bit63 */
			}},
			.L2_parity_banks = {{
			{ 6945, 8,0}, /* core1 L2_parity_banks bit0 */
			{ 6944, 8,0}, /* core1 L2_parity_banks bit1 */
			{ 6943, 8,0}, /* core1 L2_parity_banks bit2 */
			{ 6942, 8,0}, /* core1 L2_parity_banks bit3 */
			{ 6941, 8,0}, /* core1 L2_parity_banks bit4 */
			{ 6940, 8,0}, /* core1 L2_parity_banks bit5 */
			{ 6939, 8,0}, /* core1 L2_parity_banks bit6 */
			{ 6938, 8,0}, /* core1 L2_parity_banks bit7 */
			{ 6953, 8,0}, /* core1 L2_parity_banks bit8 */
			{ 6952, 8,0}, /* core1 L2_parity_banks bit9 */
			{ 6951, 8,0}, /* core1 L2_parity_banks bit10 */
			{ 6950, 8,0}, /* core1 L2_parity_banks bit11 */
			{ 6949, 8,0}, /* core1 L2_parity_banks bit12 */
			{ 6948, 8,0}, /* core1 L2_parity_banks bit13 */
			{ 6947, 8,0}, /* core1 L2_parity_banks bit14 */
			{ 6946, 8,0}, /* core1 L2_parity_banks bit15 */
			{    0, 0,2}, /* core1 L2_parity_banks bit16 */
			{    0, 0,2}, /* core1 L2_parity_banks bit17 */
			{    0, 0,2}, /* core1 L2_parity_banks bit18 */
			{    0, 0,2}, /* core1 L2_parity_banks bit19 */
			{    0, 0,2}, /* core1 L2_parity_banks bit20 */
			{    0, 0,2}, /* core1 L2_parity_banks bit21 */
			{    0, 0,2}, /* core1 L2_parity_banks bit22 */
			{    0, 0,2}, /* core1 L2_parity_banks bit23 */
			{    0, 0,2}, /* core1 L2_parity_banks bit24 */
			{    0, 0,2}, /* core1 L2_parity_banks bit25 */
			{    0, 0,2}, /* core1 L2_parity_banks bit26 */
			{    0, 0,2}, /* core1 L2_parity_banks bit27 */
			{    0, 0,2}, /* core1 L2_parity_banks bit28 */
			{    0, 0,2}, /* core1 L2_parity_banks bit29 */
			{    0, 0,2}, /* core1 L2_parity_banks bit30 */
			{    0, 0,2}, /* core1 L2_parity_banks bit31 */
			{    0, 0,2}, /* core1 L2_parity_banks bit32 */
			{    0, 0,2}, /* core1 L2_parity_banks bit33 */
			{    0, 0,2}, /* core1 L2_parity_banks bit34 */
			{    0, 0,2}, /* core1 L2_parity_banks bit35 */
			{    0, 0,2}, /* core1 L2_parity_banks bit36 */
			{    0, 0,2}, /* core1 L2_parity_banks bit37 */
			{    0, 0,2}, /* core1 L2_parity_banks bit38 */
			{    0, 0,2}, /* core1 L2_parity_banks bit39 */
			{    0, 0,2}, /* core1 L2_parity_banks bit40 */
			{    0, 0,2}, /* core1 L2_parity_banks bit41 */
			{    0, 0,2}, /* core1 L2_parity_banks bit42 */
			{    0, 0,2}, /* core1 L2_parity_banks bit43 */
			{    0, 0,2}, /* core1 L2_parity_banks bit44 */
			{    0, 0,2}, /* core1 L2_parity_banks bit45 */
			{    0, 0,2}, /* core1 L2_parity_banks bit46 */
			{    0, 0,2}, /* core1 L2_parity_banks bit47 */
			{    0, 0,2}, /* core1 L2_parity_banks bit48 */
			{    0, 0,2}, /* core1 L2_parity_banks bit49 */
			{    0, 0,2}, /* core1 L2_parity_banks bit50 */
			{    0, 0,2}, /* core1 L2_parity_banks bit51 */
			{    0, 0,2}, /* core1 L2_parity_banks bit52 */
			{    0, 0,2}, /* core1 L2_parity_banks bit53 */
			{    0, 0,2}, /* core1 L2_parity_banks bit54 */
			{    0, 0,2}, /* core1 L2_parity_banks bit55 */
			{    0, 0,2}, /* core1 L2_parity_banks bit56 */
			{    0, 0,2}, /* core1 L2_parity_banks bit57 */
			{    0, 0,2}, /* core1 L2_parity_banks bit58 */
			{    0, 0,2}, /* core1 L2_parity_banks bit59 */
			{    0, 0,2}, /* core1 L2_parity_banks bit60 */
			{    0, 0,2}, /* core1 L2_parity_banks bit61 */
			{    0, 0,2}, /* core1 L2_parity_banks bit62 */
			{    0, 0,2}, /* core1 L2_parity_banks bit63 */
			}},
	},
	{		/* core 2 */ 
			.pc = {{
			{  392,37,1}, /* core2 pc bit0 */
			{  391,37,1}, /* core2 pc bit1 */
			{  390,37,1}, /* core2 pc bit2 */
			{  389,37,1}, /* core2 pc bit3 */
			{  440,37,1}, /* core2 pc bit4 */
			{  416,37,1}, /* core2 pc bit5 */
			{  439,37,1}, /* core2 pc bit6 */
			{  415,37,1}, /* core2 pc bit7 */
			{  388,37,1}, /* core2 pc bit8 */
			{  414,37,1}, /* core2 pc bit9 */
			{  344,37,1}, /* core2 pc bit10 */
			{  360,37,1}, /* core2 pc bit11 */
			{  359,37,1}, /* core2 pc bit12 */
			{  358,37,1}, /* core2 pc bit13 */
			{  343,37,1}, /* core2 pc bit14 */
			{  342,37,1}, /* core2 pc bit15 */
			{  413,37,1}, /* core2 pc bit16 */
			{  296,37,1}, /* core2 pc bit17 */
			{  357,37,1}, /* core2 pc bit18 */
			{  387,37,1}, /* core2 pc bit19 */
			{  356,37,1}, /* core2 pc bit20 */
			{  355,37,1}, /* core2 pc bit21 */
			{  412,37,1}, /* core2 pc bit22 */
			{  354,37,1}, /* core2 pc bit23 */
			{  353,37,1}, /* core2 pc bit24 */
			{  376,37,1}, /* core2 pc bit25 */
			{  352,37,1}, /* core2 pc bit26 */
			{  295,37,1}, /* core2 pc bit27 */
			{  386,37,1}, /* core2 pc bit28 */
			{  341,37,1}, /* core2 pc bit29 */
			{  385,37,1}, /* core2 pc bit30 */
			{  351,37,1}, /* core2 pc bit31 */
			{  264,37,1}, /* core2 pc bit32 */
			{  112,37,1}, /* core2 pc bit33 */
			{  263,37,1}, /* core2 pc bit34 */
			{  111,37,1}, /* core2 pc bit35 */
			{  172,37,1}, /* core2 pc bit36 */
			{  180,37,1}, /* core2 pc bit37 */
			{  262,37,1}, /* core2 pc bit38 */
			{  146,37,1}, /* core2 pc bit39 */
			{  179,37,1}, /* core2 pc bit40 */
			{  145,37,1}, /* core2 pc bit41 */
			{  136,37,1}, /* core2 pc bit42 */
			{  261,37,1}, /* core2 pc bit43 */
			{  260,37,1}, /* core2 pc bit44 */
			{  259,37,1}, /* core2 pc bit45 */
			{  144,37,1}, /* core2 pc bit46 */
			{  143,37,1}, /* core2 pc bit47 */
			{  438,37,1}, /* core2 pc bit48 */
			{  110,37,1}, /* core2 pc bit49 */
			{  207,37,1}, /* core2 pc bit50 */
			{  206,37,1}, /* core2 pc bit51 */
			{  411,37,1}, /* core2 pc bit52 */
			{  205,37,1}, /* core2 pc bit53 */
			{  109,37,1}, /* core2 pc bit54 */
			{  204,37,1}, /* core2 pc bit55 */
			{  258,37,1}, /* core2 pc bit56 */
			{  203,37,1}, /* core2 pc bit57 */
			{  178,37,1}, /* core2 pc bit58 */
			{  177,37,1}, /* core2 pc bit59 */
			{  202,37,1}, /* core2 pc bit60 */
			{  201,37,1}, /* core2 pc bit61 */
			{  200,37,1}, /* core2 pc bit62 */
			{  257,37,1}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{37603,38,0}, /* core2 sp32 bit0 */
			{37602,38,0}, /* core2 sp32 bit1 */
			{28162,38,1}, /* core2 sp32 bit2 */
			{28161,38,1}, /* core2 sp32 bit3 */
			{28160,38,1}, /* core2 sp32 bit4 */
			{28092,38,1}, /* core2 sp32 bit5 */
			{28159,38,1}, /* core2 sp32 bit6 */
			{28091,38,1}, /* core2 sp32 bit7 */
			{37601,38,0}, /* core2 sp32 bit8 */
			{37600,38,0}, /* core2 sp32 bit9 */
			{28158,38,1}, /* core2 sp32 bit10 */
			{28151,38,1}, /* core2 sp32 bit11 */
			{37583,38,0}, /* core2 sp32 bit12 */
			{37582,38,0}, /* core2 sp32 bit13 */
			{37581,38,0}, /* core2 sp32 bit14 */
			{37580,38,0}, /* core2 sp32 bit15 */
			{28135,38,1}, /* core2 sp32 bit16 */
			{28150,38,1}, /* core2 sp32 bit17 */
			{28131,38,1}, /* core2 sp32 bit18 */
			{28132,38,1}, /* core2 sp32 bit19 */
			{28144,38,1}, /* core2 sp32 bit20 */
			{28133,38,1}, /* core2 sp32 bit21 */
			{31013,37,1}, /* core2 sp32 bit22 */
			{31012,37,1}, /* core2 sp32 bit23 */
			{28130,38,1}, /* core2 sp32 bit24 */
			{28134,38,1}, /* core2 sp32 bit25 */
			{31011,37,1}, /* core2 sp32 bit26 */
			{31010,37,1}, /* core2 sp32 bit27 */
			{37579,38,0}, /* core2 sp32 bit28 */
			{37578,38,0}, /* core2 sp32 bit29 */
			{37593,38,0}, /* core2 sp32 bit30 */
			{37592,38,0}, /* core2 sp32 bit31 */
			{30913,37,1}, /* core2 sp32 bit32 */
			{30912,37,1}, /* core2 sp32 bit33 */
			{30911,37,1}, /* core2 sp32 bit34 */
			{30910,37,1}, /* core2 sp32 bit35 */
			{37623,38,0}, /* core2 sp32 bit36 */
			{37622,38,0}, /* core2 sp32 bit37 */
			{28277,38,1}, /* core2 sp32 bit38 */
			{37709,38,0}, /* core2 sp32 bit39 */
			{28274,38,1}, /* core2 sp32 bit40 */
			{37611,38,0}, /* core2 sp32 bit41 */
			{37625,38,0}, /* core2 sp32 bit42 */
			{37624,38,0}, /* core2 sp32 bit43 */
			{37708,38,0}, /* core2 sp32 bit44 */
			{37711,38,0}, /* core2 sp32 bit45 */
			{37610,38,0}, /* core2 sp32 bit46 */
			{37710,38,0}, /* core2 sp32 bit47 */
			{28278,38,1}, /* core2 sp32 bit48 */
			{28300,38,1}, /* core2 sp32 bit49 */
			{28296,38,1}, /* core2 sp32 bit50 */
			{28302,38,1}, /* core2 sp32 bit51 */
			{28283,38,1}, /* core2 sp32 bit52 */
			{28170,38,1}, /* core2 sp32 bit53 */
			{28281,38,1}, /* core2 sp32 bit54 */
			{28310,38,1}, /* core2 sp32 bit55 */
			{28279,38,1}, /* core2 sp32 bit56 */
			{28301,38,1}, /* core2 sp32 bit57 */
			{28169,38,1}, /* core2 sp32 bit58 */
			{28303,38,1}, /* core2 sp32 bit59 */
			{28171,38,1}, /* core2 sp32 bit60 */
			{28168,38,1}, /* core2 sp32 bit61 */
			{28295,38,1}, /* core2 sp32 bit62 */
			{28297,38,1}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{28348,38,1}, /* core2 fp32 bit0 */
			{28349,38,1}, /* core2 fp32 bit1 */
			{37719,38,0}, /* core2 fp32 bit2 */
			{37718,38,0}, /* core2 fp32 bit3 */
			{37721,38,0}, /* core2 fp32 bit4 */
			{37720,38,0}, /* core2 fp32 bit5 */
			{28353,38,1}, /* core2 fp32 bit6 */
			{28351,38,1}, /* core2 fp32 bit7 */
			{28352,38,1}, /* core2 fp32 bit8 */
			{28350,38,1}, /* core2 fp32 bit9 */
			{37751,38,0}, /* core2 fp32 bit10 */
			{37750,38,0}, /* core2 fp32 bit11 */
			{37747,38,0}, /* core2 fp32 bit12 */
			{37746,38,0}, /* core2 fp32 bit13 */
			{31129,37,1}, /* core2 fp32 bit14 */
			{31128,37,1}, /* core2 fp32 bit15 */
			{31127,37,1}, /* core2 fp32 bit16 */
			{31126,37,1}, /* core2 fp32 bit17 */
			{37745,38,0}, /* core2 fp32 bit18 */
			{37744,38,0}, /* core2 fp32 bit19 */
			{31125,37,1}, /* core2 fp32 bit20 */
			{31124,37,1}, /* core2 fp32 bit21 */
			{28375,38,1}, /* core2 fp32 bit22 */
			{31123,37,1}, /* core2 fp32 bit23 */
			{31122,37,1}, /* core2 fp32 bit24 */
			{31121,37,1}, /* core2 fp32 bit25 */
			{31120,37,1}, /* core2 fp32 bit26 */
			{31119,37,1}, /* core2 fp32 bit27 */
			{31118,37,1}, /* core2 fp32 bit28 */
			{28374,38,1}, /* core2 fp32 bit29 */
			{37749,38,0}, /* core2 fp32 bit30 */
			{37748,38,0}, /* core2 fp32 bit31 */
			{37833,37,1}, /* core2 fp32 bit32 */
			{37832,37,1}, /* core2 fp32 bit33 */
			{37831,37,1}, /* core2 fp32 bit34 */
			{37830,37,1}, /* core2 fp32 bit35 */
			{28509,38,1}, /* core2 fp32 bit36 */
			{28510,38,1}, /* core2 fp32 bit37 */
			{37645,38,0}, /* core2 fp32 bit38 */
			{37829,37,1}, /* core2 fp32 bit39 */
			{37828,37,1}, /* core2 fp32 bit40 */
			{37644,38,0}, /* core2 fp32 bit41 */
			{37827,37,1}, /* core2 fp32 bit42 */
			{37641,38,0}, /* core2 fp32 bit43 */
			{37640,38,0}, /* core2 fp32 bit44 */
			{28508,38,1}, /* core2 fp32 bit45 */
			{28507,38,1}, /* core2 fp32 bit46 */
			{37643,38,0}, /* core2 fp32 bit47 */
			{37642,38,0}, /* core2 fp32 bit48 */
			{28511,38,1}, /* core2 fp32 bit49 */
			{28486,38,1}, /* core2 fp32 bit50 */
			{37826,37,1}, /* core2 fp32 bit51 */
			{28476,38,1}, /* core2 fp32 bit52 */
			{28472,38,1}, /* core2 fp32 bit53 */
			{28475,38,1}, /* core2 fp32 bit54 */
			{28489,38,1}, /* core2 fp32 bit55 */
			{28474,38,1}, /* core2 fp32 bit56 */
			{28453,38,1}, /* core2 fp32 bit57 */
			{28484,38,1}, /* core2 fp32 bit58 */
			{28454,38,1}, /* core2 fp32 bit59 */
			{28487,38,1}, /* core2 fp32 bit60 */
			{28488,38,1}, /* core2 fp32 bit61 */
			{28485,38,1}, /* core2 fp32 bit62 */
			{28473,38,1}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{28058,38,1}, /* core2 fp64 bit0 */
			{28057,38,1}, /* core2 fp64 bit1 */
			{28059,38,1}, /* core2 fp64 bit2 */
			{28054,38,1}, /* core2 fp64 bit3 */
			{31029,37,1}, /* core2 fp64 bit4 */
			{31028,37,1}, /* core2 fp64 bit5 */
			{31027,37,1}, /* core2 fp64 bit6 */
			{31026,37,1}, /* core2 fp64 bit7 */
			{28056,38,1}, /* core2 fp64 bit8 */
			{28055,38,1}, /* core2 fp64 bit9 */
			{37529,37,1}, /* core2 fp64 bit10 */
			{28060,38,1}, /* core2 fp64 bit11 */
			{27855,38,1}, /* core2 fp64 bit12 */
			{37528,37,1}, /* core2 fp64 bit13 */
			{37527,37,1}, /* core2 fp64 bit14 */
			{37526,37,1}, /* core2 fp64 bit15 */
			{30993,37,1}, /* core2 fp64 bit16 */
			{30992,37,1}, /* core2 fp64 bit17 */
			{37525,37,1}, /* core2 fp64 bit18 */
			{37524,37,1}, /* core2 fp64 bit19 */
			{37523,37,1}, /* core2 fp64 bit20 */
			{37522,37,1}, /* core2 fp64 bit21 */
			{30991,37,1}, /* core2 fp64 bit22 */
			{30990,37,1}, /* core2 fp64 bit23 */
			{27845,38,1}, /* core2 fp64 bit24 */
			{27843,38,1}, /* core2 fp64 bit25 */
			{27844,38,1}, /* core2 fp64 bit26 */
			{27842,38,1}, /* core2 fp64 bit27 */
			{37481,38,0}, /* core2 fp64 bit28 */
			{37480,38,0}, /* core2 fp64 bit29 */
			{37487,38,0}, /* core2 fp64 bit30 */
			{37486,38,0}, /* core2 fp64 bit31 */
			{30825,37,1}, /* core2 fp64 bit32 */
			{30837,37,1}, /* core2 fp64 bit33 */
			{30836,37,1}, /* core2 fp64 bit34 */
			{30835,37,1}, /* core2 fp64 bit35 */
			{30834,37,1}, /* core2 fp64 bit36 */
			{30824,37,1}, /* core2 fp64 bit37 */
			{30823,37,1}, /* core2 fp64 bit38 */
			{30822,37,1}, /* core2 fp64 bit39 */
			{27896,38,1}, /* core2 fp64 bit40 */
			{27982,38,1}, /* core2 fp64 bit41 */
			{37325,38,0}, /* core2 fp64 bit42 */
			{37324,38,0}, /* core2 fp64 bit43 */
			{30821,37,1}, /* core2 fp64 bit44 */
			{30820,37,1}, /* core2 fp64 bit45 */
			{27894,38,1}, /* core2 fp64 bit46 */
			{30819,37,1}, /* core2 fp64 bit47 */
			{27895,38,1}, /* core2 fp64 bit48 */
			{30818,37,1}, /* core2 fp64 bit49 */
			{30833,37,1}, /* core2 fp64 bit50 */
			{30832,37,1}, /* core2 fp64 bit51 */
			{30831,37,1}, /* core2 fp64 bit52 */
			{30830,37,1}, /* core2 fp64 bit53 */
			{30841,37,1}, /* core2 fp64 bit54 */
			{27983,38,1}, /* core2 fp64 bit55 */
			{30840,37,1}, /* core2 fp64 bit56 */
			{30839,37,1}, /* core2 fp64 bit57 */
			{27984,38,1}, /* core2 fp64 bit58 */
			{30838,37,1}, /* core2 fp64 bit59 */
			{30829,37,1}, /* core2 fp64 bit60 */
			{30828,37,1}, /* core2 fp64 bit61 */
			{30827,37,1}, /* core2 fp64 bit62 */
			{30826,37,1}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{28040,38,1}, /* core2 sp_EL0 bit0 */
			{28038,38,1}, /* core2 sp_EL0 bit1 */
			{28039,38,1}, /* core2 sp_EL0 bit2 */
			{28035,38,1}, /* core2 sp_EL0 bit3 */
			{28037,38,1}, /* core2 sp_EL0 bit4 */
			{28036,38,1}, /* core2 sp_EL0 bit5 */
			{37399,38,0}, /* core2 sp_EL0 bit6 */
			{37398,38,0}, /* core2 sp_EL0 bit7 */
			{37397,38,0}, /* core2 sp_EL0 bit8 */
			{37396,38,0}, /* core2 sp_EL0 bit9 */
			{27861,38,1}, /* core2 sp_EL0 bit10 */
			{28029,38,1}, /* core2 sp_EL0 bit11 */
			{27859,38,1}, /* core2 sp_EL0 bit12 */
			{27851,38,1}, /* core2 sp_EL0 bit13 */
			{37467,38,0}, /* core2 sp_EL0 bit14 */
			{37466,38,0}, /* core2 sp_EL0 bit15 */
			{27858,38,1}, /* core2 sp_EL0 bit16 */
			{27860,38,1}, /* core2 sp_EL0 bit17 */
			{37479,38,0}, /* core2 sp_EL0 bit18 */
			{37478,38,0}, /* core2 sp_EL0 bit19 */
			{37475,38,0}, /* core2 sp_EL0 bit20 */
			{37474,38,0}, /* core2 sp_EL0 bit21 */
			{37471,38,0}, /* core2 sp_EL0 bit22 */
			{37470,38,0}, /* core2 sp_EL0 bit23 */
			{30989,37,1}, /* core2 sp_EL0 bit24 */
			{30988,37,1}, /* core2 sp_EL0 bit25 */
			{30987,37,1}, /* core2 sp_EL0 bit26 */
			{30986,37,1}, /* core2 sp_EL0 bit27 */
			{37477,38,0}, /* core2 sp_EL0 bit28 */
			{37476,38,0}, /* core2 sp_EL0 bit29 */
			{27841,38,1}, /* core2 sp_EL0 bit30 */
			{28041,38,1}, /* core2 sp_EL0 bit31 */
			{37287,38,0}, /* core2 sp_EL0 bit32 */
			{37577,37,1}, /* core2 sp_EL0 bit33 */
			{37576,37,1}, /* core2 sp_EL0 bit34 */
			{37575,37,1}, /* core2 sp_EL0 bit35 */
			{37574,37,1}, /* core2 sp_EL0 bit36 */
			{37573,37,1}, /* core2 sp_EL0 bit37 */
			{37572,37,1}, /* core2 sp_EL0 bit38 */
			{37286,38,0}, /* core2 sp_EL0 bit39 */
			{37571,37,1}, /* core2 sp_EL0 bit40 */
			{37570,37,1}, /* core2 sp_EL0 bit41 */
			{37367,38,0}, /* core2 sp_EL0 bit42 */
			{37366,38,0}, /* core2 sp_EL0 bit43 */
			{37285,38,0}, /* core2 sp_EL0 bit44 */
			{37284,38,0}, /* core2 sp_EL0 bit45 */
			{27962,38,1}, /* core2 sp_EL0 bit46 */
			{27934,38,1}, /* core2 sp_EL0 bit47 */
			{37269,38,0}, /* core2 sp_EL0 bit48 */
			{37268,38,0}, /* core2 sp_EL0 bit49 */
			{37283,38,0}, /* core2 sp_EL0 bit50 */
			{37282,38,0}, /* core2 sp_EL0 bit51 */
			{37273,38,0}, /* core2 sp_EL0 bit52 */
			{37272,38,0}, /* core2 sp_EL0 bit53 */
			{37267,38,0}, /* core2 sp_EL0 bit54 */
			{37266,38,0}, /* core2 sp_EL0 bit55 */
			{37265,38,0}, /* core2 sp_EL0 bit56 */
			{37264,38,0}, /* core2 sp_EL0 bit57 */
			{30813,37,1}, /* core2 sp_EL0 bit58 */
			{30812,37,1}, /* core2 sp_EL0 bit59 */
			{37271,38,0}, /* core2 sp_EL0 bit60 */
			{37270,38,0}, /* core2 sp_EL0 bit61 */
			{30811,37,1}, /* core2 sp_EL0 bit62 */
			{30810,37,1}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{28034,38,1}, /* core2 sp_EL1 bit0 */
			{27881,38,1}, /* core2 sp_EL1 bit1 */
			{37395,38,0}, /* core2 sp_EL1 bit2 */
			{37394,38,0}, /* core2 sp_EL1 bit3 */
			{28032,38,1}, /* core2 sp_EL1 bit4 */
			{28033,38,1}, /* core2 sp_EL1 bit5 */
			{37393,38,0}, /* core2 sp_EL1 bit6 */
			{37392,38,0}, /* core2 sp_EL1 bit7 */
			{30569,37,1}, /* core2 sp_EL1 bit8 */
			{30568,37,1}, /* core2 sp_EL1 bit9 */
			{37465,38,0}, /* core2 sp_EL1 bit10 */
			{30567,37,1}, /* core2 sp_EL1 bit11 */
			{30566,37,1}, /* core2 sp_EL1 bit12 */
			{37464,38,0}, /* core2 sp_EL1 bit13 */
			{27863,38,1}, /* core2 sp_EL1 bit14 */
			{27864,38,1}, /* core2 sp_EL1 bit15 */
			{28030,38,1}, /* core2 sp_EL1 bit16 */
			{27862,38,1}, /* core2 sp_EL1 bit17 */
			{27836,38,1}, /* core2 sp_EL1 bit18 */
			{27839,38,1}, /* core2 sp_EL1 bit19 */
			{27838,38,1}, /* core2 sp_EL1 bit20 */
			{27837,38,1}, /* core2 sp_EL1 bit21 */
			{37493,38,0}, /* core2 sp_EL1 bit22 */
			{30597,37,1}, /* core2 sp_EL1 bit23 */
			{30596,37,1}, /* core2 sp_EL1 bit24 */
			{30595,37,1}, /* core2 sp_EL1 bit25 */
			{30594,37,1}, /* core2 sp_EL1 bit26 */
			{37492,38,0}, /* core2 sp_EL1 bit27 */
			{37495,38,0}, /* core2 sp_EL1 bit28 */
			{37494,38,0}, /* core2 sp_EL1 bit29 */
			{27840,38,1}, /* core2 sp_EL1 bit30 */
			{28031,38,1}, /* core2 sp_EL1 bit31 */
			{27935,38,1}, /* core2 sp_EL1 bit32 */
			{27963,38,1}, /* core2 sp_EL1 bit33 */
			{37365,38,0}, /* core2 sp_EL1 bit34 */
			{37364,38,0}, /* core2 sp_EL1 bit35 */
			{37363,38,0}, /* core2 sp_EL1 bit36 */
			{37362,38,0}, /* core2 sp_EL1 bit37 */
			{27966,38,1}, /* core2 sp_EL1 bit38 */
			{27931,38,1}, /* core2 sp_EL1 bit39 */
			{30653,37,1}, /* core2 sp_EL1 bit40 */
			{30652,37,1}, /* core2 sp_EL1 bit41 */
			{30651,37,1}, /* core2 sp_EL1 bit42 */
			{30650,37,1}, /* core2 sp_EL1 bit43 */
			{37279,38,0}, /* core2 sp_EL1 bit44 */
			{37278,38,0}, /* core2 sp_EL1 bit45 */
			{27964,38,1}, /* core2 sp_EL1 bit46 */
			{27933,38,1}, /* core2 sp_EL1 bit47 */
			{27932,38,1}, /* core2 sp_EL1 bit48 */
			{27965,38,1}, /* core2 sp_EL1 bit49 */
			{37281,38,0}, /* core2 sp_EL1 bit50 */
			{37280,38,0}, /* core2 sp_EL1 bit51 */
			{37275,38,0}, /* core2 sp_EL1 bit52 */
			{37274,38,0}, /* core2 sp_EL1 bit53 */
			{37263,38,0}, /* core2 sp_EL1 bit54 */
			{37262,38,0}, /* core2 sp_EL1 bit55 */
			{37261,38,0}, /* core2 sp_EL1 bit56 */
			{37260,38,0}, /* core2 sp_EL1 bit57 */
			{37349,38,0}, /* core2 sp_EL1 bit58 */
			{37348,38,0}, /* core2 sp_EL1 bit59 */
			{37353,38,0}, /* core2 sp_EL1 bit60 */
			{37352,38,0}, /* core2 sp_EL1 bit61 */
			{37277,38,0}, /* core2 sp_EL1 bit62 */
			{37276,38,0}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{28047,38,1}, /* core2 sp_EL2 bit0 */
			{28053,38,1}, /* core2 sp_EL2 bit1 */
			{28052,38,1}, /* core2 sp_EL2 bit2 */
			{28049,38,1}, /* core2 sp_EL2 bit3 */
			{28051,38,1}, /* core2 sp_EL2 bit4 */
			{28050,38,1}, /* core2 sp_EL2 bit5 */
			{28028,38,1}, /* core2 sp_EL2 bit6 */
			{28026,38,1}, /* core2 sp_EL2 bit7 */
			{28027,38,1}, /* core2 sp_EL2 bit8 */
			{28048,38,1}, /* core2 sp_EL2 bit9 */
			{27856,38,1}, /* core2 sp_EL2 bit10 */
			{28061,38,1}, /* core2 sp_EL2 bit11 */
			{27857,38,1}, /* core2 sp_EL2 bit12 */
			{27847,38,1}, /* core2 sp_EL2 bit13 */
			{27854,38,1}, /* core2 sp_EL2 bit14 */
			{37459,38,0}, /* core2 sp_EL2 bit15 */
			{37458,38,0}, /* core2 sp_EL2 bit16 */
			{27853,38,1}, /* core2 sp_EL2 bit17 */
			{37461,38,0}, /* core2 sp_EL2 bit18 */
			{37460,38,0}, /* core2 sp_EL2 bit19 */
			{27852,38,1}, /* core2 sp_EL2 bit20 */
			{27846,38,1}, /* core2 sp_EL2 bit21 */
			{30585,37,1}, /* core2 sp_EL2 bit22 */
			{30589,37,1}, /* core2 sp_EL2 bit23 */
			{30588,37,1}, /* core2 sp_EL2 bit24 */
			{30587,37,1}, /* core2 sp_EL2 bit25 */
			{30584,37,1}, /* core2 sp_EL2 bit26 */
			{30586,37,1}, /* core2 sp_EL2 bit27 */
			{30583,37,1}, /* core2 sp_EL2 bit28 */
			{37489,38,0}, /* core2 sp_EL2 bit29 */
			{37488,38,0}, /* core2 sp_EL2 bit30 */
			{30582,37,1}, /* core2 sp_EL2 bit31 */
			{37601,37,1}, /* core2 sp_EL2 bit32 */
			{30649,37,1}, /* core2 sp_EL2 bit33 */
			{30648,37,1}, /* core2 sp_EL2 bit34 */
			{30647,37,1}, /* core2 sp_EL2 bit35 */
			{30646,37,1}, /* core2 sp_EL2 bit36 */
			{37359,38,0}, /* core2 sp_EL2 bit37 */
			{37358,38,0}, /* core2 sp_EL2 bit38 */
			{37600,37,1}, /* core2 sp_EL2 bit39 */
			{37361,38,0}, /* core2 sp_EL2 bit40 */
			{37360,38,0}, /* core2 sp_EL2 bit41 */
			{30645,37,1}, /* core2 sp_EL2 bit42 */
			{30644,37,1}, /* core2 sp_EL2 bit43 */
			{37599,37,1}, /* core2 sp_EL2 bit44 */
			{37598,37,1}, /* core2 sp_EL2 bit45 */
			{30643,37,1}, /* core2 sp_EL2 bit46 */
			{37597,37,1}, /* core2 sp_EL2 bit47 */
			{37596,37,1}, /* core2 sp_EL2 bit48 */
			{30642,37,1}, /* core2 sp_EL2 bit49 */
			{37595,37,1}, /* core2 sp_EL2 bit50 */
			{37594,37,1}, /* core2 sp_EL2 bit51 */
			{37593,37,1}, /* core2 sp_EL2 bit52 */
			{37592,37,1}, /* core2 sp_EL2 bit53 */
			{27970,38,1}, /* core2 sp_EL2 bit54 */
			{37591,37,1}, /* core2 sp_EL2 bit55 */
			{27971,38,1}, /* core2 sp_EL2 bit56 */
			{37355,38,0}, /* core2 sp_EL2 bit57 */
			{37590,37,1}, /* core2 sp_EL2 bit58 */
			{37589,37,1}, /* core2 sp_EL2 bit59 */
			{37588,37,1}, /* core2 sp_EL2 bit60 */
			{37587,37,1}, /* core2 sp_EL2 bit61 */
			{37354,38,0}, /* core2 sp_EL2 bit62 */
			{37586,37,1}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{28045,38,1}, /* core2 sp_EL3 bit0 */
			{28046,38,1}, /* core2 sp_EL3 bit1 */
			{28044,38,1}, /* core2 sp_EL3 bit2 */
			{28043,38,1}, /* core2 sp_EL3 bit3 */
			{30573,37,1}, /* core2 sp_EL3 bit4 */
			{30572,37,1}, /* core2 sp_EL3 bit5 */
			{30571,37,1}, /* core2 sp_EL3 bit6 */
			{30570,37,1}, /* core2 sp_EL3 bit7 */
			{30577,37,1}, /* core2 sp_EL3 bit8 */
			{30576,37,1}, /* core2 sp_EL3 bit9 */
			{30575,37,1}, /* core2 sp_EL3 bit10 */
			{30574,37,1}, /* core2 sp_EL3 bit11 */
			{30581,37,1}, /* core2 sp_EL3 bit12 */
			{30580,37,1}, /* core2 sp_EL3 bit13 */
			{30579,37,1}, /* core2 sp_EL3 bit14 */
			{30578,37,1}, /* core2 sp_EL3 bit15 */
			{37463,38,0}, /* core2 sp_EL3 bit16 */
			{37462,38,0}, /* core2 sp_EL3 bit17 */
			{37473,38,0}, /* core2 sp_EL3 bit18 */
			{37472,38,0}, /* core2 sp_EL3 bit19 */
			{27850,38,1}, /* core2 sp_EL3 bit20 */
			{27848,38,1}, /* core2 sp_EL3 bit21 */
			{37469,38,0}, /* core2 sp_EL3 bit22 */
			{37468,38,0}, /* core2 sp_EL3 bit23 */
			{30593,37,1}, /* core2 sp_EL3 bit24 */
			{30592,37,1}, /* core2 sp_EL3 bit25 */
			{30591,37,1}, /* core2 sp_EL3 bit26 */
			{30590,37,1}, /* core2 sp_EL3 bit27 */
			{37491,38,0}, /* core2 sp_EL3 bit28 */
			{37490,38,0}, /* core2 sp_EL3 bit29 */
			{27849,38,1}, /* core2 sp_EL3 bit30 */
			{28042,38,1}, /* core2 sp_EL3 bit31 */
			{37289,38,0}, /* core2 sp_EL3 bit32 */
			{37585,37,1}, /* core2 sp_EL3 bit33 */
			{37584,37,1}, /* core2 sp_EL3 bit34 */
			{37583,37,1}, /* core2 sp_EL3 bit35 */
			{37582,37,1}, /* core2 sp_EL3 bit36 */
			{37581,37,1}, /* core2 sp_EL3 bit37 */
			{37580,37,1}, /* core2 sp_EL3 bit38 */
			{37288,38,0}, /* core2 sp_EL3 bit39 */
			{37579,37,1}, /* core2 sp_EL3 bit40 */
			{37578,37,1}, /* core2 sp_EL3 bit41 */
			{37357,38,0}, /* core2 sp_EL3 bit42 */
			{37356,38,0}, /* core2 sp_EL3 bit43 */
			{37347,38,0}, /* core2 sp_EL3 bit44 */
			{37346,38,0}, /* core2 sp_EL3 bit45 */
			{27969,38,1}, /* core2 sp_EL3 bit46 */
			{27974,38,1}, /* core2 sp_EL3 bit47 */
			{27973,38,1}, /* core2 sp_EL3 bit48 */
			{27967,38,1}, /* core2 sp_EL3 bit49 */
			{37351,38,0}, /* core2 sp_EL3 bit50 */
			{37350,38,0}, /* core2 sp_EL3 bit51 */
			{37259,38,0}, /* core2 sp_EL3 bit52 */
			{37258,38,0}, /* core2 sp_EL3 bit53 */
			{27968,38,1}, /* core2 sp_EL3 bit54 */
			{27972,38,1}, /* core2 sp_EL3 bit55 */
			{37078,38,0}, /* core2 sp_EL3 bit56 */
			{37077,38,0}, /* core2 sp_EL3 bit57 */
			{37074,38,0}, /* core2 sp_EL3 bit58 */
			{37073,38,0}, /* core2 sp_EL3 bit59 */
			{37076,38,0}, /* core2 sp_EL3 bit60 */
			{37075,38,0}, /* core2 sp_EL3 bit61 */
			{37072,38,0}, /* core2 sp_EL3 bit62 */
			{37071,38,0}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{37561,37,1}, /* core2 elr_EL1 bit0 */
			{37560,37,1}, /* core2 elr_EL1 bit1 */
			{37559,37,1}, /* core2 elr_EL1 bit2 */
			{37558,37,1}, /* core2 elr_EL1 bit3 */
			{37557,37,1}, /* core2 elr_EL1 bit4 */
			{37556,37,1}, /* core2 elr_EL1 bit5 */
			{37555,37,1}, /* core2 elr_EL1 bit6 */
			{37554,37,1}, /* core2 elr_EL1 bit7 */
			{37036,38,0}, /* core2 elr_EL1 bit8 */
			{37035,38,0}, /* core2 elr_EL1 bit9 */
			{30621,37,1}, /* core2 elr_EL1 bit10 */
			{30620,37,1}, /* core2 elr_EL1 bit11 */
			{37030,38,0}, /* core2 elr_EL1 bit12 */
			{37029,38,0}, /* core2 elr_EL1 bit13 */
			{37022,38,0}, /* core2 elr_EL1 bit14 */
			{37021,38,0}, /* core2 elr_EL1 bit15 */
			{30605,37,1}, /* core2 elr_EL1 bit16 */
			{30604,37,1}, /* core2 elr_EL1 bit17 */
			{30603,37,1}, /* core2 elr_EL1 bit18 */
			{30602,37,1}, /* core2 elr_EL1 bit19 */
			{37018,38,0}, /* core2 elr_EL1 bit20 */
			{37017,38,0}, /* core2 elr_EL1 bit21 */
			{30619,37,1}, /* core2 elr_EL1 bit22 */
			{30618,37,1}, /* core2 elr_EL1 bit23 */
			{30601,37,1}, /* core2 elr_EL1 bit24 */
			{30600,37,1}, /* core2 elr_EL1 bit25 */
			{30599,37,1}, /* core2 elr_EL1 bit26 */
			{30598,37,1}, /* core2 elr_EL1 bit27 */
			{37020,38,0}, /* core2 elr_EL1 bit28 */
			{37019,38,0}, /* core2 elr_EL1 bit29 */
			{37032,38,0}, /* core2 elr_EL1 bit30 */
			{37031,38,0}, /* core2 elr_EL1 bit31 */
			{27939,38,1}, /* core2 elr_EL1 bit32 */
			{27953,38,1}, /* core2 elr_EL1 bit33 */
			{37052,38,0}, /* core2 elr_EL1 bit34 */
			{37051,38,0}, /* core2 elr_EL1 bit35 */
			{37050,38,0}, /* core2 elr_EL1 bit36 */
			{37049,38,0}, /* core2 elr_EL1 bit37 */
			{27954,38,1}, /* core2 elr_EL1 bit38 */
			{27938,38,1}, /* core2 elr_EL1 bit39 */
			{30641,37,1}, /* core2 elr_EL1 bit40 */
			{30640,37,1}, /* core2 elr_EL1 bit41 */
			{30639,37,1}, /* core2 elr_EL1 bit42 */
			{30638,37,1}, /* core2 elr_EL1 bit43 */
			{37038,38,0}, /* core2 elr_EL1 bit44 */
			{37037,38,0}, /* core2 elr_EL1 bit45 */
			{27955,38,1}, /* core2 elr_EL1 bit46 */
			{27950,38,1}, /* core2 elr_EL1 bit47 */
			{27949,38,1}, /* core2 elr_EL1 bit48 */
			{27952,38,1}, /* core2 elr_EL1 bit49 */
			{37042,38,0}, /* core2 elr_EL1 bit50 */
			{37041,38,0}, /* core2 elr_EL1 bit51 */
			{37044,38,0}, /* core2 elr_EL1 bit52 */
			{37043,38,0}, /* core2 elr_EL1 bit53 */
			{37048,38,0}, /* core2 elr_EL1 bit54 */
			{37047,38,0}, /* core2 elr_EL1 bit55 */
			{37058,38,0}, /* core2 elr_EL1 bit56 */
			{37057,38,0}, /* core2 elr_EL1 bit57 */
			{37040,38,0}, /* core2 elr_EL1 bit58 */
			{37039,38,0}, /* core2 elr_EL1 bit59 */
			{37046,38,0}, /* core2 elr_EL1 bit60 */
			{37045,38,0}, /* core2 elr_EL1 bit61 */
			{27951,38,1}, /* core2 elr_EL1 bit62 */
			{27940,38,1}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{37553,37,1}, /* core2 elr_EL2 bit0 */
			{37552,37,1}, /* core2 elr_EL2 bit1 */
			{37551,37,1}, /* core2 elr_EL2 bit2 */
			{37550,37,1}, /* core2 elr_EL2 bit3 */
			{37549,37,1}, /* core2 elr_EL2 bit4 */
			{37548,37,1}, /* core2 elr_EL2 bit5 */
			{37547,37,1}, /* core2 elr_EL2 bit6 */
			{37546,37,1}, /* core2 elr_EL2 bit7 */
			{30629,37,1}, /* core2 elr_EL2 bit8 */
			{30628,37,1}, /* core2 elr_EL2 bit9 */
			{37537,37,1}, /* core2 elr_EL2 bit10 */
			{30627,37,1}, /* core2 elr_EL2 bit11 */
			{37536,37,1}, /* core2 elr_EL2 bit12 */
			{30626,37,1}, /* core2 elr_EL2 bit13 */
			{37535,37,1}, /* core2 elr_EL2 bit14 */
			{37534,37,1}, /* core2 elr_EL2 bit15 */
			{37533,37,1}, /* core2 elr_EL2 bit16 */
			{37532,37,1}, /* core2 elr_EL2 bit17 */
			{37531,37,1}, /* core2 elr_EL2 bit18 */
			{37530,37,1}, /* core2 elr_EL2 bit19 */
			{30609,37,1}, /* core2 elr_EL2 bit20 */
			{30608,37,1}, /* core2 elr_EL2 bit21 */
			{30607,37,1}, /* core2 elr_EL2 bit22 */
			{30606,37,1}, /* core2 elr_EL2 bit23 */
			{30613,37,1}, /* core2 elr_EL2 bit24 */
			{30612,37,1}, /* core2 elr_EL2 bit25 */
			{30611,37,1}, /* core2 elr_EL2 bit26 */
			{30610,37,1}, /* core2 elr_EL2 bit27 */
			{37024,38,0}, /* core2 elr_EL2 bit28 */
			{37023,38,0}, /* core2 elr_EL2 bit29 */
			{27873,38,1}, /* core2 elr_EL2 bit30 */
			{27878,38,1}, /* core2 elr_EL2 bit31 */
			{27943,38,1}, /* core2 elr_EL2 bit32 */
			{27956,38,1}, /* core2 elr_EL2 bit33 */
			{37054,38,0}, /* core2 elr_EL2 bit34 */
			{37053,38,0}, /* core2 elr_EL2 bit35 */
			{37056,38,0}, /* core2 elr_EL2 bit36 */
			{37055,38,0}, /* core2 elr_EL2 bit37 */
			{27957,38,1}, /* core2 elr_EL2 bit38 */
			{27942,38,1}, /* core2 elr_EL2 bit39 */
			{30637,37,1}, /* core2 elr_EL2 bit40 */
			{30636,37,1}, /* core2 elr_EL2 bit41 */
			{30635,37,1}, /* core2 elr_EL2 bit42 */
			{30634,37,1}, /* core2 elr_EL2 bit43 */
			{37070,38,0}, /* core2 elr_EL2 bit44 */
			{37069,38,0}, /* core2 elr_EL2 bit45 */
			{27958,38,1}, /* core2 elr_EL2 bit46 */
			{27948,38,1}, /* core2 elr_EL2 bit47 */
			{27947,38,1}, /* core2 elr_EL2 bit48 */
			{27959,38,1}, /* core2 elr_EL2 bit49 */
			{37066,38,0}, /* core2 elr_EL2 bit50 */
			{37065,38,0}, /* core2 elr_EL2 bit51 */
			{37062,38,0}, /* core2 elr_EL2 bit52 */
			{37061,38,0}, /* core2 elr_EL2 bit53 */
			{30633,37,1}, /* core2 elr_EL2 bit54 */
			{30632,37,1}, /* core2 elr_EL2 bit55 */
			{37060,38,0}, /* core2 elr_EL2 bit56 */
			{37059,38,0}, /* core2 elr_EL2 bit57 */
			{37068,38,0}, /* core2 elr_EL2 bit58 */
			{37067,38,0}, /* core2 elr_EL2 bit59 */
			{37064,38,0}, /* core2 elr_EL2 bit60 */
			{37063,38,0}, /* core2 elr_EL2 bit61 */
			{30631,37,1}, /* core2 elr_EL2 bit62 */
			{30630,37,1}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{37545,37,1}, /* core2 elr_EL3 bit0 */
			{37544,37,1}, /* core2 elr_EL3 bit1 */
			{37543,37,1}, /* core2 elr_EL3 bit2 */
			{37542,37,1}, /* core2 elr_EL3 bit3 */
			{37541,37,1}, /* core2 elr_EL3 bit4 */
			{37540,37,1}, /* core2 elr_EL3 bit5 */
			{37539,37,1}, /* core2 elr_EL3 bit6 */
			{37538,37,1}, /* core2 elr_EL3 bit7 */
			{37034,38,0}, /* core2 elr_EL3 bit8 */
			{37033,38,0}, /* core2 elr_EL3 bit9 */
			{30625,37,1}, /* core2 elr_EL3 bit10 */
			{30624,37,1}, /* core2 elr_EL3 bit11 */
			{30623,37,1}, /* core2 elr_EL3 bit12 */
			{30622,37,1}, /* core2 elr_EL3 bit13 */
			{37026,38,0}, /* core2 elr_EL3 bit14 */
			{37025,38,0}, /* core2 elr_EL3 bit15 */
			{37014,38,0}, /* core2 elr_EL3 bit16 */
			{37013,38,0}, /* core2 elr_EL3 bit17 */
			{27866,38,1}, /* core2 elr_EL3 bit18 */
			{27867,38,1}, /* core2 elr_EL3 bit19 */
			{30617,37,1}, /* core2 elr_EL3 bit20 */
			{30616,37,1}, /* core2 elr_EL3 bit21 */
			{30615,37,1}, /* core2 elr_EL3 bit22 */
			{30614,37,1}, /* core2 elr_EL3 bit23 */
			{27865,38,1}, /* core2 elr_EL3 bit24 */
			{27874,38,1}, /* core2 elr_EL3 bit25 */
			{37016,38,0}, /* core2 elr_EL3 bit26 */
			{37015,38,0}, /* core2 elr_EL3 bit27 */
			{37028,38,0}, /* core2 elr_EL3 bit28 */
			{37027,38,0}, /* core2 elr_EL3 bit29 */
			{27868,38,1}, /* core2 elr_EL3 bit30 */
			{27877,38,1}, /* core2 elr_EL3 bit31 */
			{30669,37,1}, /* core2 elr_EL3 bit32 */
			{30668,37,1}, /* core2 elr_EL3 bit33 */
			{30667,37,1}, /* core2 elr_EL3 bit34 */
			{30666,37,1}, /* core2 elr_EL3 bit35 */
			{30657,37,1}, /* core2 elr_EL3 bit36 */
			{30656,37,1}, /* core2 elr_EL3 bit37 */
			{30655,37,1}, /* core2 elr_EL3 bit38 */
			{30654,37,1}, /* core2 elr_EL3 bit39 */
			{37012,38,0}, /* core2 elr_EL3 bit40 */
			{37011,38,0}, /* core2 elr_EL3 bit41 */
			{27928,38,1}, /* core2 elr_EL3 bit42 */
			{27927,38,1}, /* core2 elr_EL3 bit43 */
			{30661,37,1}, /* core2 elr_EL3 bit44 */
			{30660,37,1}, /* core2 elr_EL3 bit45 */
			{30659,37,1}, /* core2 elr_EL3 bit46 */
			{30658,37,1}, /* core2 elr_EL3 bit47 */
			{30665,37,1}, /* core2 elr_EL3 bit48 */
			{30664,37,1}, /* core2 elr_EL3 bit49 */
			{30663,37,1}, /* core2 elr_EL3 bit50 */
			{30662,37,1}, /* core2 elr_EL3 bit51 */
			{30565,37,1}, /* core2 elr_EL3 bit52 */
			{30564,37,1}, /* core2 elr_EL3 bit53 */
			{30563,37,1}, /* core2 elr_EL3 bit54 */
			{30562,37,1}, /* core2 elr_EL3 bit55 */
			{37513,37,1}, /* core2 elr_EL3 bit56 */
			{37512,37,1}, /* core2 elr_EL3 bit57 */
			{37511,37,1}, /* core2 elr_EL3 bit58 */
			{37510,37,1}, /* core2 elr_EL3 bit59 */
			{37509,37,1}, /* core2 elr_EL3 bit60 */
			{37508,37,1}, /* core2 elr_EL3 bit61 */
			{37507,37,1}, /* core2 elr_EL3 bit62 */
			{37506,37,1}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31320,38,1}, /* core2 raw_pc bit0 */
			{31430,38,1}, /* core2 raw_pc bit1 */
			{32637,37,1}, /* core2 raw_pc bit2 */
			{32636,37,1}, /* core2 raw_pc bit3 */
			{32635,37,1}, /* core2 raw_pc bit4 */
			{32634,37,1}, /* core2 raw_pc bit5 */
			{31328,38,1}, /* core2 raw_pc bit6 */
			{39377,37,1}, /* core2 raw_pc bit7 */
			{39376,37,1}, /* core2 raw_pc bit8 */
			{39375,37,1}, /* core2 raw_pc bit9 */
			{39374,37,1}, /* core2 raw_pc bit10 */
			{39373,37,1}, /* core2 raw_pc bit11 */
			{39372,37,1}, /* core2 raw_pc bit12 */
			{39371,37,1}, /* core2 raw_pc bit13 */
			{39370,37,1}, /* core2 raw_pc bit14 */
			{39305,37,1}, /* core2 raw_pc bit15 */
			{39304,37,1}, /* core2 raw_pc bit16 */
			{39303,37,1}, /* core2 raw_pc bit17 */
			{39302,37,1}, /* core2 raw_pc bit18 */
			{39301,37,1}, /* core2 raw_pc bit19 */
			{39300,37,1}, /* core2 raw_pc bit20 */
			{39299,37,1}, /* core2 raw_pc bit21 */
			{39298,37,1}, /* core2 raw_pc bit22 */
			{39313,37,1}, /* core2 raw_pc bit23 */
			{39312,37,1}, /* core2 raw_pc bit24 */
			{39311,37,1}, /* core2 raw_pc bit25 */
			{39310,37,1}, /* core2 raw_pc bit26 */
			{39309,37,1}, /* core2 raw_pc bit27 */
			{39308,37,1}, /* core2 raw_pc bit28 */
			{39307,37,1}, /* core2 raw_pc bit29 */
			{39306,37,1}, /* core2 raw_pc bit30 */
			{39369,37,1}, /* core2 raw_pc bit31 */
			{39368,37,1}, /* core2 raw_pc bit32 */
			{39367,37,1}, /* core2 raw_pc bit33 */
			{39366,37,1}, /* core2 raw_pc bit34 */
			{39365,37,1}, /* core2 raw_pc bit35 */
			{39364,37,1}, /* core2 raw_pc bit36 */
			{39363,37,1}, /* core2 raw_pc bit37 */
			{39362,37,1}, /* core2 raw_pc bit38 */
			{39361,37,1}, /* core2 raw_pc bit39 */
			{39360,37,1}, /* core2 raw_pc bit40 */
			{39359,37,1}, /* core2 raw_pc bit41 */
			{39358,37,1}, /* core2 raw_pc bit42 */
			{39357,37,1}, /* core2 raw_pc bit43 */
			{39356,37,1}, /* core2 raw_pc bit44 */
			{39355,37,1}, /* core2 raw_pc bit45 */
			{39354,37,1}, /* core2 raw_pc bit46 */
			{38933,38,1}, /* core2 raw_pc bit47 */
			{38932,38,1}, /* core2 raw_pc bit48 */
			{31321,38,1}, /* core2 raw_pc bit49 */
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
			{31564,38,1}, /* core2 pc_iss bit0 */
			{31566,38,1}, /* core2 pc_iss bit1 */
			{38983,38,1}, /* core2 pc_iss bit2 */
			{38982,38,1}, /* core2 pc_iss bit3 */
			{32597,37,1}, /* core2 pc_iss bit4 */
			{32596,37,1}, /* core2 pc_iss bit5 */
			{32595,37,1}, /* core2 pc_iss bit6 */
			{32594,37,1}, /* core2 pc_iss bit7 */
			{31651,38,0}, /* core2 pc_iss bit8 */
			{31556,38,1}, /* core2 pc_iss bit9 */
			{31563,38,1}, /* core2 pc_iss bit10 */
			{31654,38,0}, /* core2 pc_iss bit11 */
			{31559,38,1}, /* core2 pc_iss bit12 */
			{31659,38,0}, /* core2 pc_iss bit13 */
			{31658,38,0}, /* core2 pc_iss bit14 */
			{31655,38,0}, /* core2 pc_iss bit15 */
			{31557,38,1}, /* core2 pc_iss bit16 */
			{31656,38,0}, /* core2 pc_iss bit17 */
			{31657,38,0}, /* core2 pc_iss bit18 */
			{31558,38,1}, /* core2 pc_iss bit19 */
			{32605,37,1}, /* core2 pc_iss bit20 */
			{32604,37,1}, /* core2 pc_iss bit21 */
			{32603,37,1}, /* core2 pc_iss bit22 */
			{32602,37,1}, /* core2 pc_iss bit23 */
			{38985,38,1}, /* core2 pc_iss bit24 */
			{38984,38,1}, /* core2 pc_iss bit25 */
			{31652,38,0}, /* core2 pc_iss bit26 */
			{31555,38,1}, /* core2 pc_iss bit27 */
			{32609,37,1}, /* core2 pc_iss bit28 */
			{32608,37,1}, /* core2 pc_iss bit29 */
			{32607,37,1}, /* core2 pc_iss bit30 */
			{32606,37,1}, /* core2 pc_iss bit31 */
			{31554,38,1}, /* core2 pc_iss bit32 */
			{31553,38,1}, /* core2 pc_iss bit33 */
			{38981,38,1}, /* core2 pc_iss bit34 */
			{38980,38,1}, /* core2 pc_iss bit35 */
			{32613,37,1}, /* core2 pc_iss bit36 */
			{32612,37,1}, /* core2 pc_iss bit37 */
			{32611,37,1}, /* core2 pc_iss bit38 */
			{32610,37,1}, /* core2 pc_iss bit39 */
			{39401,37,1}, /* core2 pc_iss bit40 */
			{39400,37,1}, /* core2 pc_iss bit41 */
			{39399,37,1}, /* core2 pc_iss bit42 */
			{39398,37,1}, /* core2 pc_iss bit43 */
			{39397,37,1}, /* core2 pc_iss bit44 */
			{39396,37,1}, /* core2 pc_iss bit45 */
			{39395,37,1}, /* core2 pc_iss bit46 */
			{39394,37,1}, /* core2 pc_iss bit47 */
			{32593,37,1}, /* core2 pc_iss bit48 */
			{32592,37,1}, /* core2 pc_iss bit49 */
			{32591,37,1}, /* core2 pc_iss bit50 */
			{32590,37,1}, /* core2 pc_iss bit51 */
			{38979,38,1}, /* core2 pc_iss bit52 */
			{38978,38,1}, /* core2 pc_iss bit53 */
			{31455,38,1}, /* core2 pc_iss bit54 */
			{31456,38,1}, /* core2 pc_iss bit55 */
			{31457,38,1}, /* core2 pc_iss bit56 */
			{31454,38,1}, /* core2 pc_iss bit57 */
			{31551,38,1}, /* core2 pc_iss bit58 */
			{31452,38,1}, /* core2 pc_iss bit59 */
			{31552,38,1}, /* core2 pc_iss bit60 */
			{31453,38,1}, /* core2 pc_iss bit61 */
			{38977,38,1}, /* core2 pc_iss bit62 */
			{38976,38,1}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31605,38,0}, /* core2 full_pc_wr bit0 */
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
			{31612,38,0}, /* core2 full_pc_ex1 bit0 */
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
			{32625,37,1}, /* core2 full_pc_ex2 bit0 */
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
			{16480,38,0}, /* core2 return_Stack_pointer bit0 */
			{16473,38,0}, /* core2 return_Stack_pointer bit1 */
			{16474,38,0}, /* core2 return_Stack_pointer bit2 */
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
			{20540,38,0}, /* core2 return_Stack0 bit0 */
			{20539,38,0}, /* core2 return_Stack0 bit1 */
			{20538,38,0}, /* core2 return_Stack0 bit2 */
			{20537,38,0}, /* core2 return_Stack0 bit3 */
			{20536,38,0}, /* core2 return_Stack0 bit4 */
			{20535,38,0}, /* core2 return_Stack0 bit5 */
			{20534,38,0}, /* core2 return_Stack0 bit6 */
			{20568,38,0}, /* core2 return_Stack0 bit7 */
			{20567,38,0}, /* core2 return_Stack0 bit8 */
			{20566,38,0}, /* core2 return_Stack0 bit9 */
			{20565,38,0}, /* core2 return_Stack0 bit10 */
			{20588,38,0}, /* core2 return_Stack0 bit11 */
			{20587,38,0}, /* core2 return_Stack0 bit12 */
			{20586,38,0}, /* core2 return_Stack0 bit13 */
			{20585,38,0}, /* core2 return_Stack0 bit14 */
			{20584,38,0}, /* core2 return_Stack0 bit15 */
			{20583,38,0}, /* core2 return_Stack0 bit16 */
			{20582,38,0}, /* core2 return_Stack0 bit17 */
			{20581,38,0}, /* core2 return_Stack0 bit18 */
			{20612,38,0}, /* core2 return_Stack0 bit19 */
			{20611,38,0}, /* core2 return_Stack0 bit20 */
			{20610,38,0}, /* core2 return_Stack0 bit21 */
			{20609,38,0}, /* core2 return_Stack0 bit22 */
			{20608,38,0}, /* core2 return_Stack0 bit23 */
			{20607,38,0}, /* core2 return_Stack0 bit24 */
			{20606,38,0}, /* core2 return_Stack0 bit25 */
			{20605,38,0}, /* core2 return_Stack0 bit26 */
			{20528,38,0}, /* core2 return_Stack0 bit27 */
			{20527,38,0}, /* core2 return_Stack0 bit28 */
			{20526,38,0}, /* core2 return_Stack0 bit29 */
			{20533,38,0}, /* core2 return_Stack0 bit30 */
			{16458,38,0}, /* core2 return_Stack0 bit31 */
			{20525,38,0}, /* core2 return_Stack0 bit32 */
			{16457,38,0}, /* core2 return_Stack0 bit33 */
			{16460,38,0}, /* core2 return_Stack0 bit34 */
			{16459,38,0}, /* core2 return_Stack0 bit35 */
			{20504,38,0}, /* core2 return_Stack0 bit36 */
			{20503,38,0}, /* core2 return_Stack0 bit37 */
			{20502,38,0}, /* core2 return_Stack0 bit38 */
			{20501,38,0}, /* core2 return_Stack0 bit39 */
			{20500,38,0}, /* core2 return_Stack0 bit40 */
			{20499,38,0}, /* core2 return_Stack0 bit41 */
			{20498,38,0}, /* core2 return_Stack0 bit42 */
			{20497,38,0}, /* core2 return_Stack0 bit43 */
			{20496,38,0}, /* core2 return_Stack0 bit44 */
			{20495,38,0}, /* core2 return_Stack0 bit45 */
			{20494,38,0}, /* core2 return_Stack0 bit46 */
			{20493,38,0}, /* core2 return_Stack0 bit47 */
			{13577,38,1}, /* core2 return_Stack0 bit48 */
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
			{20548,38,0}, /* core2 return_Stack1 bit0 */
			{20547,38,0}, /* core2 return_Stack1 bit1 */
			{20546,38,0}, /* core2 return_Stack1 bit2 */
			{20545,38,0}, /* core2 return_Stack1 bit3 */
			{20552,38,0}, /* core2 return_Stack1 bit4 */
			{20551,38,0}, /* core2 return_Stack1 bit5 */
			{20550,38,0}, /* core2 return_Stack1 bit6 */
			{20564,38,0}, /* core2 return_Stack1 bit7 */
			{20563,38,0}, /* core2 return_Stack1 bit8 */
			{20562,38,0}, /* core2 return_Stack1 bit9 */
			{20561,38,0}, /* core2 return_Stack1 bit10 */
			{20592,38,0}, /* core2 return_Stack1 bit11 */
			{20591,38,0}, /* core2 return_Stack1 bit12 */
			{20590,38,0}, /* core2 return_Stack1 bit13 */
			{20589,38,0}, /* core2 return_Stack1 bit14 */
			{20600,38,0}, /* core2 return_Stack1 bit15 */
			{20599,38,0}, /* core2 return_Stack1 bit16 */
			{20598,38,0}, /* core2 return_Stack1 bit17 */
			{20597,38,0}, /* core2 return_Stack1 bit18 */
			{20580,38,0}, /* core2 return_Stack1 bit19 */
			{20579,38,0}, /* core2 return_Stack1 bit20 */
			{20578,38,0}, /* core2 return_Stack1 bit21 */
			{20577,38,0}, /* core2 return_Stack1 bit22 */
			{20572,38,0}, /* core2 return_Stack1 bit23 */
			{20571,38,0}, /* core2 return_Stack1 bit24 */
			{20570,38,0}, /* core2 return_Stack1 bit25 */
			{20569,38,0}, /* core2 return_Stack1 bit26 */
			{20532,38,0}, /* core2 return_Stack1 bit27 */
			{20531,38,0}, /* core2 return_Stack1 bit28 */
			{20530,38,0}, /* core2 return_Stack1 bit29 */
			{20529,38,0}, /* core2 return_Stack1 bit30 */
			{20549,38,0}, /* core2 return_Stack1 bit31 */
			{13574,38,1}, /* core2 return_Stack1 bit32 */
			{20520,38,0}, /* core2 return_Stack1 bit33 */
			{20519,38,0}, /* core2 return_Stack1 bit34 */
			{20518,38,0}, /* core2 return_Stack1 bit35 */
			{20517,38,0}, /* core2 return_Stack1 bit36 */
			{20516,38,0}, /* core2 return_Stack1 bit37 */
			{20515,38,0}, /* core2 return_Stack1 bit38 */
			{20514,38,0}, /* core2 return_Stack1 bit39 */
			{20513,38,0}, /* core2 return_Stack1 bit40 */
			{20492,38,0}, /* core2 return_Stack1 bit41 */
			{20491,38,0}, /* core2 return_Stack1 bit42 */
			{20490,38,0}, /* core2 return_Stack1 bit43 */
			{20489,38,0}, /* core2 return_Stack1 bit44 */
			{20488,38,0}, /* core2 return_Stack1 bit45 */
			{20487,38,0}, /* core2 return_Stack1 bit46 */
			{20486,38,0}, /* core2 return_Stack1 bit47 */
			{20485,38,0}, /* core2 return_Stack1 bit48 */
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
			{20544,38,0}, /* core2 return_Stack2 bit0 */
			{20543,38,0}, /* core2 return_Stack2 bit1 */
			{20542,38,0}, /* core2 return_Stack2 bit2 */
			{20541,38,0}, /* core2 return_Stack2 bit3 */
			{20556,38,0}, /* core2 return_Stack2 bit4 */
			{20555,38,0}, /* core2 return_Stack2 bit5 */
			{20554,38,0}, /* core2 return_Stack2 bit6 */
			{20553,38,0}, /* core2 return_Stack2 bit7 */
			{20560,38,0}, /* core2 return_Stack2 bit8 */
			{20559,38,0}, /* core2 return_Stack2 bit9 */
			{20558,38,0}, /* core2 return_Stack2 bit10 */
			{20557,38,0}, /* core2 return_Stack2 bit11 */
			{20596,38,0}, /* core2 return_Stack2 bit12 */
			{20595,38,0}, /* core2 return_Stack2 bit13 */
			{16346,38,0}, /* core2 return_Stack2 bit14 */
			{20594,38,0}, /* core2 return_Stack2 bit15 */
			{16345,38,0}, /* core2 return_Stack2 bit16 */
			{20593,38,0}, /* core2 return_Stack2 bit17 */
			{16344,38,0}, /* core2 return_Stack2 bit18 */
			{20576,38,0}, /* core2 return_Stack2 bit19 */
			{20575,38,0}, /* core2 return_Stack2 bit20 */
			{20574,38,0}, /* core2 return_Stack2 bit21 */
			{20573,38,0}, /* core2 return_Stack2 bit22 */
			{20604,38,0}, /* core2 return_Stack2 bit23 */
			{20603,38,0}, /* core2 return_Stack2 bit24 */
			{20602,38,0}, /* core2 return_Stack2 bit25 */
			{20601,38,0}, /* core2 return_Stack2 bit26 */
			{16343,38,0}, /* core2 return_Stack2 bit27 */
			{16512,38,0}, /* core2 return_Stack2 bit28 */
			{16511,38,0}, /* core2 return_Stack2 bit29 */
			{20524,38,0}, /* core2 return_Stack2 bit30 */
			{20523,38,0}, /* core2 return_Stack2 bit31 */
			{13573,38,1}, /* core2 return_Stack2 bit32 */
			{20522,38,0}, /* core2 return_Stack2 bit33 */
			{20521,38,0}, /* core2 return_Stack2 bit34 */
			{20512,38,0}, /* core2 return_Stack2 bit35 */
			{20511,38,0}, /* core2 return_Stack2 bit36 */
			{20510,38,0}, /* core2 return_Stack2 bit37 */
			{20509,38,0}, /* core2 return_Stack2 bit38 */
			{20508,38,0}, /* core2 return_Stack2 bit39 */
			{20507,38,0}, /* core2 return_Stack2 bit40 */
			{20506,38,0}, /* core2 return_Stack2 bit41 */
			{20505,38,0}, /* core2 return_Stack2 bit42 */
			{20460,38,0}, /* core2 return_Stack2 bit43 */
			{20459,38,0}, /* core2 return_Stack2 bit44 */
			{20458,38,0}, /* core2 return_Stack2 bit45 */
			{20457,38,0}, /* core2 return_Stack2 bit46 */
			{13583,38,1}, /* core2 return_Stack2 bit47 */
			{13584,38,1}, /* core2 return_Stack2 bit48 */
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
			{20362,38,0}, /* core2 return_Stack3 bit0 */
			{20361,38,0}, /* core2 return_Stack3 bit1 */
			{20360,38,0}, /* core2 return_Stack3 bit2 */
			{20359,38,0}, /* core2 return_Stack3 bit3 */
			{20270,38,0}, /* core2 return_Stack3 bit4 */
			{20269,38,0}, /* core2 return_Stack3 bit5 */
			{20366,38,0}, /* core2 return_Stack3 bit6 */
			{20268,38,0}, /* core2 return_Stack3 bit7 */
			{20267,38,0}, /* core2 return_Stack3 bit8 */
			{20418,38,0}, /* core2 return_Stack3 bit9 */
			{20417,38,0}, /* core2 return_Stack3 bit10 */
			{20416,38,0}, /* core2 return_Stack3 bit11 */
			{20415,38,0}, /* core2 return_Stack3 bit12 */
			{16362,38,0}, /* core2 return_Stack3 bit13 */
			{16361,38,0}, /* core2 return_Stack3 bit14 */
			{16360,38,0}, /* core2 return_Stack3 bit15 */
			{16359,38,0}, /* core2 return_Stack3 bit16 */
			{16338,38,0}, /* core2 return_Stack3 bit17 */
			{16337,38,0}, /* core2 return_Stack3 bit18 */
			{16340,38,0}, /* core2 return_Stack3 bit19 */
			{16339,38,0}, /* core2 return_Stack3 bit20 */
			{16498,38,0}, /* core2 return_Stack3 bit21 */
			{16497,38,0}, /* core2 return_Stack3 bit22 */
			{16500,38,0}, /* core2 return_Stack3 bit23 */
			{16499,38,0}, /* core2 return_Stack3 bit24 */
			{16504,38,0}, /* core2 return_Stack3 bit25 */
			{16503,38,0}, /* core2 return_Stack3 bit26 */
			{16508,38,0}, /* core2 return_Stack3 bit27 */
			{16507,38,0}, /* core2 return_Stack3 bit28 */
			{16518,38,0}, /* core2 return_Stack3 bit29 */
			{20365,38,0}, /* core2 return_Stack3 bit30 */
			{20364,38,0}, /* core2 return_Stack3 bit31 */
			{16517,38,0}, /* core2 return_Stack3 bit32 */
			{20363,38,0}, /* core2 return_Stack3 bit33 */
			{20310,38,0}, /* core2 return_Stack3 bit34 */
			{20309,38,0}, /* core2 return_Stack3 bit35 */
			{20308,38,0}, /* core2 return_Stack3 bit36 */
			{20307,38,0}, /* core2 return_Stack3 bit37 */
			{20318,38,0}, /* core2 return_Stack3 bit38 */
			{20317,38,0}, /* core2 return_Stack3 bit39 */
			{20316,38,0}, /* core2 return_Stack3 bit40 */
			{20315,38,0}, /* core2 return_Stack3 bit41 */
			{20342,38,0}, /* core2 return_Stack3 bit42 */
			{20341,38,0}, /* core2 return_Stack3 bit43 */
			{20340,38,0}, /* core2 return_Stack3 bit44 */
			{20339,38,0}, /* core2 return_Stack3 bit45 */
			{16440,38,0}, /* core2 return_Stack3 bit46 */
			{16439,38,0}, /* core2 return_Stack3 bit47 */
			{13581,38,1}, /* core2 return_Stack3 bit48 */
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
			{20370,38,0}, /* core2 return_Stack4 bit0 */
			{20369,38,0}, /* core2 return_Stack4 bit1 */
			{20368,38,0}, /* core2 return_Stack4 bit2 */
			{20367,38,0}, /* core2 return_Stack4 bit3 */
			{20374,38,0}, /* core2 return_Stack4 bit4 */
			{20373,38,0}, /* core2 return_Stack4 bit5 */
			{20372,38,0}, /* core2 return_Stack4 bit6 */
			{20371,38,0}, /* core2 return_Stack4 bit7 */
			{20378,38,0}, /* core2 return_Stack4 bit8 */
			{20377,38,0}, /* core2 return_Stack4 bit9 */
			{20376,38,0}, /* core2 return_Stack4 bit10 */
			{20375,38,0}, /* core2 return_Stack4 bit11 */
			{20398,38,0}, /* core2 return_Stack4 bit12 */
			{20397,38,0}, /* core2 return_Stack4 bit13 */
			{20396,38,0}, /* core2 return_Stack4 bit14 */
			{20395,38,0}, /* core2 return_Stack4 bit15 */
			{20394,38,0}, /* core2 return_Stack4 bit16 */
			{20393,38,0}, /* core2 return_Stack4 bit17 */
			{20392,38,0}, /* core2 return_Stack4 bit18 */
			{20391,38,0}, /* core2 return_Stack4 bit19 */
			{20430,38,0}, /* core2 return_Stack4 bit20 */
			{20429,38,0}, /* core2 return_Stack4 bit21 */
			{20428,38,0}, /* core2 return_Stack4 bit22 */
			{20427,38,0}, /* core2 return_Stack4 bit23 */
			{20434,38,0}, /* core2 return_Stack4 bit24 */
			{20433,38,0}, /* core2 return_Stack4 bit25 */
			{20432,38,0}, /* core2 return_Stack4 bit26 */
			{20431,38,0}, /* core2 return_Stack4 bit27 */
			{16506,38,0}, /* core2 return_Stack4 bit28 */
			{16505,38,0}, /* core2 return_Stack4 bit29 */
			{16456,38,0}, /* core2 return_Stack4 bit30 */
			{16455,38,0}, /* core2 return_Stack4 bit31 */
			{16454,38,0}, /* core2 return_Stack4 bit32 */
			{16453,38,0}, /* core2 return_Stack4 bit33 */
			{16446,38,0}, /* core2 return_Stack4 bit34 */
			{20314,38,0}, /* core2 return_Stack4 bit35 */
			{20313,38,0}, /* core2 return_Stack4 bit36 */
			{20312,38,0}, /* core2 return_Stack4 bit37 */
			{20311,38,0}, /* core2 return_Stack4 bit38 */
			{20306,38,0}, /* core2 return_Stack4 bit39 */
			{20305,38,0}, /* core2 return_Stack4 bit40 */
			{20304,38,0}, /* core2 return_Stack4 bit41 */
			{20303,38,0}, /* core2 return_Stack4 bit42 */
			{20298,38,0}, /* core2 return_Stack4 bit43 */
			{20297,38,0}, /* core2 return_Stack4 bit44 */
			{20296,38,0}, /* core2 return_Stack4 bit45 */
			{20295,38,0}, /* core2 return_Stack4 bit46 */
			{16445,38,0}, /* core2 return_Stack4 bit47 */
			{13576,38,1}, /* core2 return_Stack4 bit48 */
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
			{16444,38,0}, /* core2 return_Stack5 bit0 */
			{20262,38,0}, /* core2 return_Stack5 bit1 */
			{16443,38,0}, /* core2 return_Stack5 bit2 */
			{16438,38,0}, /* core2 return_Stack5 bit3 */
			{20261,38,0}, /* core2 return_Stack5 bit4 */
			{20260,38,0}, /* core2 return_Stack5 bit5 */
			{20259,38,0}, /* core2 return_Stack5 bit6 */
			{20266,38,0}, /* core2 return_Stack5 bit7 */
			{20265,38,0}, /* core2 return_Stack5 bit8 */
			{20264,38,0}, /* core2 return_Stack5 bit9 */
			{20263,38,0}, /* core2 return_Stack5 bit10 */
			{16437,38,0}, /* core2 return_Stack5 bit11 */
			{20402,38,0}, /* core2 return_Stack5 bit12 */
			{20401,38,0}, /* core2 return_Stack5 bit13 */
			{20400,38,0}, /* core2 return_Stack5 bit14 */
			{20399,38,0}, /* core2 return_Stack5 bit15 */
			{16364,38,0}, /* core2 return_Stack5 bit16 */
			{16363,38,0}, /* core2 return_Stack5 bit17 */
			{16342,38,0}, /* core2 return_Stack5 bit18 */
			{16341,38,0}, /* core2 return_Stack5 bit19 */
			{20390,38,0}, /* core2 return_Stack5 bit20 */
			{20389,38,0}, /* core2 return_Stack5 bit21 */
			{20388,38,0}, /* core2 return_Stack5 bit22 */
			{20387,38,0}, /* core2 return_Stack5 bit23 */
			{20282,38,0}, /* core2 return_Stack5 bit24 */
			{20281,38,0}, /* core2 return_Stack5 bit25 */
			{20280,38,0}, /* core2 return_Stack5 bit26 */
			{20279,38,0}, /* core2 return_Stack5 bit27 */
			{16514,38,0}, /* core2 return_Stack5 bit28 */
			{16513,38,0}, /* core2 return_Stack5 bit29 */
			{16452,38,0}, /* core2 return_Stack5 bit30 */
			{20286,38,0}, /* core2 return_Stack5 bit31 */
			{16451,38,0}, /* core2 return_Stack5 bit32 */
			{20285,38,0}, /* core2 return_Stack5 bit33 */
			{20284,38,0}, /* core2 return_Stack5 bit34 */
			{20283,38,0}, /* core2 return_Stack5 bit35 */
			{20326,38,0}, /* core2 return_Stack5 bit36 */
			{20325,38,0}, /* core2 return_Stack5 bit37 */
			{20324,38,0}, /* core2 return_Stack5 bit38 */
			{20323,38,0}, /* core2 return_Stack5 bit39 */
			{20338,38,0}, /* core2 return_Stack5 bit40 */
			{20337,38,0}, /* core2 return_Stack5 bit41 */
			{20336,38,0}, /* core2 return_Stack5 bit42 */
			{20335,38,0}, /* core2 return_Stack5 bit43 */
			{20354,38,0}, /* core2 return_Stack5 bit44 */
			{20353,38,0}, /* core2 return_Stack5 bit45 */
			{20352,38,0}, /* core2 return_Stack5 bit46 */
			{20351,38,0}, /* core2 return_Stack5 bit47 */
			{13580,38,1}, /* core2 return_Stack5 bit48 */
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
			{20358,38,0}, /* core2 return_Stack6 bit0 */
			{20357,38,0}, /* core2 return_Stack6 bit1 */
			{20356,38,0}, /* core2 return_Stack6 bit2 */
			{20355,38,0}, /* core2 return_Stack6 bit3 */
			{20258,38,0}, /* core2 return_Stack6 bit4 */
			{20257,38,0}, /* core2 return_Stack6 bit5 */
			{20256,38,0}, /* core2 return_Stack6 bit6 */
			{20255,38,0}, /* core2 return_Stack6 bit7 */
			{16436,38,0}, /* core2 return_Stack6 bit8 */
			{20410,38,0}, /* core2 return_Stack6 bit9 */
			{16435,38,0}, /* core2 return_Stack6 bit10 */
			{20409,38,0}, /* core2 return_Stack6 bit11 */
			{20408,38,0}, /* core2 return_Stack6 bit12 */
			{20407,38,0}, /* core2 return_Stack6 bit13 */
			{16356,38,0}, /* core2 return_Stack6 bit14 */
			{16355,38,0}, /* core2 return_Stack6 bit15 */
			{16358,38,0}, /* core2 return_Stack6 bit16 */
			{16357,38,0}, /* core2 return_Stack6 bit17 */
			{20386,38,0}, /* core2 return_Stack6 bit18 */
			{20385,38,0}, /* core2 return_Stack6 bit19 */
			{20384,38,0}, /* core2 return_Stack6 bit20 */
			{20383,38,0}, /* core2 return_Stack6 bit21 */
			{20382,38,0}, /* core2 return_Stack6 bit22 */
			{20381,38,0}, /* core2 return_Stack6 bit23 */
			{20380,38,0}, /* core2 return_Stack6 bit24 */
			{20379,38,0}, /* core2 return_Stack6 bit25 */
			{20278,38,0}, /* core2 return_Stack6 bit26 */
			{20277,38,0}, /* core2 return_Stack6 bit27 */
			{20276,38,0}, /* core2 return_Stack6 bit28 */
			{20275,38,0}, /* core2 return_Stack6 bit29 */
			{16448,38,0}, /* core2 return_Stack6 bit30 */
			{16447,38,0}, /* core2 return_Stack6 bit31 */
			{16450,38,0}, /* core2 return_Stack6 bit32 */
			{16449,38,0}, /* core2 return_Stack6 bit33 */
			{20302,38,0}, /* core2 return_Stack6 bit34 */
			{20301,38,0}, /* core2 return_Stack6 bit35 */
			{20300,38,0}, /* core2 return_Stack6 bit36 */
			{20299,38,0}, /* core2 return_Stack6 bit37 */
			{20334,38,0}, /* core2 return_Stack6 bit38 */
			{20333,38,0}, /* core2 return_Stack6 bit39 */
			{20332,38,0}, /* core2 return_Stack6 bit40 */
			{20331,38,0}, /* core2 return_Stack6 bit41 */
			{20346,38,0}, /* core2 return_Stack6 bit42 */
			{20345,38,0}, /* core2 return_Stack6 bit43 */
			{20344,38,0}, /* core2 return_Stack6 bit44 */
			{20343,38,0}, /* core2 return_Stack6 bit45 */
			{16442,38,0}, /* core2 return_Stack6 bit46 */
			{16441,38,0}, /* core2 return_Stack6 bit47 */
			{13582,38,1}, /* core2 return_Stack6 bit48 */
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
			{20294,38,0}, /* core2 return_Stack7 bit0 */
			{20293,38,0}, /* core2 return_Stack7 bit1 */
			{20292,38,0}, /* core2 return_Stack7 bit2 */
			{20291,38,0}, /* core2 return_Stack7 bit3 */
			{20274,38,0}, /* core2 return_Stack7 bit4 */
			{20273,38,0}, /* core2 return_Stack7 bit5 */
			{20290,38,0}, /* core2 return_Stack7 bit6 */
			{20272,38,0}, /* core2 return_Stack7 bit7 */
			{20271,38,0}, /* core2 return_Stack7 bit8 */
			{20414,38,0}, /* core2 return_Stack7 bit9 */
			{20413,38,0}, /* core2 return_Stack7 bit10 */
			{20412,38,0}, /* core2 return_Stack7 bit11 */
			{20411,38,0}, /* core2 return_Stack7 bit12 */
			{20406,38,0}, /* core2 return_Stack7 bit13 */
			{20405,38,0}, /* core2 return_Stack7 bit14 */
			{20404,38,0}, /* core2 return_Stack7 bit15 */
			{20403,38,0}, /* core2 return_Stack7 bit16 */
			{20422,38,0}, /* core2 return_Stack7 bit17 */
			{20421,38,0}, /* core2 return_Stack7 bit18 */
			{20426,38,0}, /* core2 return_Stack7 bit19 */
			{20420,38,0}, /* core2 return_Stack7 bit20 */
			{20419,38,0}, /* core2 return_Stack7 bit21 */
			{20425,38,0}, /* core2 return_Stack7 bit22 */
			{20424,38,0}, /* core2 return_Stack7 bit23 */
			{20423,38,0}, /* core2 return_Stack7 bit24 */
			{16502,38,0}, /* core2 return_Stack7 bit25 */
			{16501,38,0}, /* core2 return_Stack7 bit26 */
			{16510,38,0}, /* core2 return_Stack7 bit27 */
			{16509,38,0}, /* core2 return_Stack7 bit28 */
			{16516,38,0}, /* core2 return_Stack7 bit29 */
			{16515,38,0}, /* core2 return_Stack7 bit30 */
			{20289,38,0}, /* core2 return_Stack7 bit31 */
			{13575,38,1}, /* core2 return_Stack7 bit32 */
			{20288,38,0}, /* core2 return_Stack7 bit33 */
			{20287,38,0}, /* core2 return_Stack7 bit34 */
			{20322,38,0}, /* core2 return_Stack7 bit35 */
			{20321,38,0}, /* core2 return_Stack7 bit36 */
			{20320,38,0}, /* core2 return_Stack7 bit37 */
			{20319,38,0}, /* core2 return_Stack7 bit38 */
			{20330,38,0}, /* core2 return_Stack7 bit39 */
			{20329,38,0}, /* core2 return_Stack7 bit40 */
			{20328,38,0}, /* core2 return_Stack7 bit41 */
			{20327,38,0}, /* core2 return_Stack7 bit42 */
			{20350,38,0}, /* core2 return_Stack7 bit43 */
			{20349,38,0}, /* core2 return_Stack7 bit44 */
			{20348,38,0}, /* core2 return_Stack7 bit45 */
			{20347,38,0}, /* core2 return_Stack7 bit46 */
			{13579,38,1}, /* core2 return_Stack7 bit47 */
			{13578,38,1}, /* core2 return_Stack7 bit48 */
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
			.L2_parity_err_count = {{
			{ 6969, 8,0}, /* core2 L2_parity_err_count bit0 */
			{ 6968, 8,0}, /* core2 L2_parity_err_count bit1 */
			{ 6967, 8,0}, /* core2 L2_parity_err_count bit2 */
			{ 6966, 8,0}, /* core2 L2_parity_err_count bit3 */
			{ 6965, 8,0}, /* core2 L2_parity_err_count bit4 */
			{ 6964, 8,0}, /* core2 L2_parity_err_count bit5 */
			{ 6963, 8,0}, /* core2 L2_parity_err_count bit6 */
			{ 6962, 8,0}, /* core2 L2_parity_err_count bit7 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit8 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit9 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit10 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit11 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit12 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit13 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit14 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit15 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit16 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit17 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit18 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit19 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit20 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit21 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit22 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit23 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit24 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit25 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit26 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit27 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit28 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit29 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit30 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit31 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit32 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit33 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit34 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit35 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit36 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit37 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit38 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit39 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit40 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit41 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit42 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit43 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit44 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit45 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit46 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit47 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit48 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit49 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit50 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit51 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit52 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit53 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit54 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit55 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit56 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit57 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit58 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit59 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit60 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit61 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit62 */
			{    0, 0,2}, /* core2 L2_parity_err_count bit63 */
			}},
			.L2_parity_index = {{
			{ 6684, 8,0}, /* core2 L2_parity_index bit0 */
			{ 6683, 8,0}, /* core2 L2_parity_index bit1 */
			{ 6682, 8,0}, /* core2 L2_parity_index bit2 */
			{ 6681, 8,0}, /* core2 L2_parity_index bit3 */
			{ 6680, 8,0}, /* core2 L2_parity_index bit4 */
			{ 6679, 8,0}, /* core2 L2_parity_index bit5 */
			{ 6678, 8,0}, /* core2 L2_parity_index bit6 */
			{ 6677, 8,0}, /* core2 L2_parity_index bit7 */
			{ 6692, 8,0}, /* core2 L2_parity_index bit8 */
			{ 6691, 8,0}, /* core2 L2_parity_index bit9 */
			{ 6690, 8,0}, /* core2 L2_parity_index bit10 */
			{ 6689, 8,0}, /* core2 L2_parity_index bit11 */
			{    0, 0,2}, /* core2 L2_parity_index bit12 */
			{    0, 0,2}, /* core2 L2_parity_index bit13 */
			{    0, 0,2}, /* core2 L2_parity_index bit14 */
			{    0, 0,2}, /* core2 L2_parity_index bit15 */
			{    0, 0,2}, /* core2 L2_parity_index bit16 */
			{    0, 0,2}, /* core2 L2_parity_index bit17 */
			{    0, 0,2}, /* core2 L2_parity_index bit18 */
			{    0, 0,2}, /* core2 L2_parity_index bit19 */
			{    0, 0,2}, /* core2 L2_parity_index bit20 */
			{    0, 0,2}, /* core2 L2_parity_index bit21 */
			{    0, 0,2}, /* core2 L2_parity_index bit22 */
			{    0, 0,2}, /* core2 L2_parity_index bit23 */
			{    0, 0,2}, /* core2 L2_parity_index bit24 */
			{    0, 0,2}, /* core2 L2_parity_index bit25 */
			{    0, 0,2}, /* core2 L2_parity_index bit26 */
			{    0, 0,2}, /* core2 L2_parity_index bit27 */
			{    0, 0,2}, /* core2 L2_parity_index bit28 */
			{    0, 0,2}, /* core2 L2_parity_index bit29 */
			{    0, 0,2}, /* core2 L2_parity_index bit30 */
			{    0, 0,2}, /* core2 L2_parity_index bit31 */
			{    0, 0,2}, /* core2 L2_parity_index bit32 */
			{    0, 0,2}, /* core2 L2_parity_index bit33 */
			{    0, 0,2}, /* core2 L2_parity_index bit34 */
			{    0, 0,2}, /* core2 L2_parity_index bit35 */
			{    0, 0,2}, /* core2 L2_parity_index bit36 */
			{    0, 0,2}, /* core2 L2_parity_index bit37 */
			{    0, 0,2}, /* core2 L2_parity_index bit38 */
			{    0, 0,2}, /* core2 L2_parity_index bit39 */
			{    0, 0,2}, /* core2 L2_parity_index bit40 */
			{    0, 0,2}, /* core2 L2_parity_index bit41 */
			{    0, 0,2}, /* core2 L2_parity_index bit42 */
			{    0, 0,2}, /* core2 L2_parity_index bit43 */
			{    0, 0,2}, /* core2 L2_parity_index bit44 */
			{    0, 0,2}, /* core2 L2_parity_index bit45 */
			{    0, 0,2}, /* core2 L2_parity_index bit46 */
			{    0, 0,2}, /* core2 L2_parity_index bit47 */
			{    0, 0,2}, /* core2 L2_parity_index bit48 */
			{    0, 0,2}, /* core2 L2_parity_index bit49 */
			{    0, 0,2}, /* core2 L2_parity_index bit50 */
			{    0, 0,2}, /* core2 L2_parity_index bit51 */
			{    0, 0,2}, /* core2 L2_parity_index bit52 */
			{    0, 0,2}, /* core2 L2_parity_index bit53 */
			{    0, 0,2}, /* core2 L2_parity_index bit54 */
			{    0, 0,2}, /* core2 L2_parity_index bit55 */
			{    0, 0,2}, /* core2 L2_parity_index bit56 */
			{    0, 0,2}, /* core2 L2_parity_index bit57 */
			{    0, 0,2}, /* core2 L2_parity_index bit58 */
			{    0, 0,2}, /* core2 L2_parity_index bit59 */
			{    0, 0,2}, /* core2 L2_parity_index bit60 */
			{    0, 0,2}, /* core2 L2_parity_index bit61 */
			{    0, 0,2}, /* core2 L2_parity_index bit62 */
			{    0, 0,2}, /* core2 L2_parity_index bit63 */
			}},
			.L2_parity_way = {{
			{ 6685, 8,0}, /* core2 L2_parity_way bit0 */
			{ 6463, 8,0}, /* core2 L2_parity_way bit1 */
			{    0, 0,2}, /* core2 L2_parity_way bit2 */
			{    0, 0,2}, /* core2 L2_parity_way bit3 */
			{    0, 0,2}, /* core2 L2_parity_way bit4 */
			{    0, 0,2}, /* core2 L2_parity_way bit5 */
			{    0, 0,2}, /* core2 L2_parity_way bit6 */
			{    0, 0,2}, /* core2 L2_parity_way bit7 */
			{    0, 0,2}, /* core2 L2_parity_way bit8 */
			{    0, 0,2}, /* core2 L2_parity_way bit9 */
			{    0, 0,2}, /* core2 L2_parity_way bit10 */
			{    0, 0,2}, /* core2 L2_parity_way bit11 */
			{    0, 0,2}, /* core2 L2_parity_way bit12 */
			{    0, 0,2}, /* core2 L2_parity_way bit13 */
			{    0, 0,2}, /* core2 L2_parity_way bit14 */
			{    0, 0,2}, /* core2 L2_parity_way bit15 */
			{    0, 0,2}, /* core2 L2_parity_way bit16 */
			{    0, 0,2}, /* core2 L2_parity_way bit17 */
			{    0, 0,2}, /* core2 L2_parity_way bit18 */
			{    0, 0,2}, /* core2 L2_parity_way bit19 */
			{    0, 0,2}, /* core2 L2_parity_way bit20 */
			{    0, 0,2}, /* core2 L2_parity_way bit21 */
			{    0, 0,2}, /* core2 L2_parity_way bit22 */
			{    0, 0,2}, /* core2 L2_parity_way bit23 */
			{    0, 0,2}, /* core2 L2_parity_way bit24 */
			{    0, 0,2}, /* core2 L2_parity_way bit25 */
			{    0, 0,2}, /* core2 L2_parity_way bit26 */
			{    0, 0,2}, /* core2 L2_parity_way bit27 */
			{    0, 0,2}, /* core2 L2_parity_way bit28 */
			{    0, 0,2}, /* core2 L2_parity_way bit29 */
			{    0, 0,2}, /* core2 L2_parity_way bit30 */
			{    0, 0,2}, /* core2 L2_parity_way bit31 */
			{    0, 0,2}, /* core2 L2_parity_way bit32 */
			{    0, 0,2}, /* core2 L2_parity_way bit33 */
			{    0, 0,2}, /* core2 L2_parity_way bit34 */
			{    0, 0,2}, /* core2 L2_parity_way bit35 */
			{    0, 0,2}, /* core2 L2_parity_way bit36 */
			{    0, 0,2}, /* core2 L2_parity_way bit37 */
			{    0, 0,2}, /* core2 L2_parity_way bit38 */
			{    0, 0,2}, /* core2 L2_parity_way bit39 */
			{    0, 0,2}, /* core2 L2_parity_way bit40 */
			{    0, 0,2}, /* core2 L2_parity_way bit41 */
			{    0, 0,2}, /* core2 L2_parity_way bit42 */
			{    0, 0,2}, /* core2 L2_parity_way bit43 */
			{    0, 0,2}, /* core2 L2_parity_way bit44 */
			{    0, 0,2}, /* core2 L2_parity_way bit45 */
			{    0, 0,2}, /* core2 L2_parity_way bit46 */
			{    0, 0,2}, /* core2 L2_parity_way bit47 */
			{    0, 0,2}, /* core2 L2_parity_way bit48 */
			{    0, 0,2}, /* core2 L2_parity_way bit49 */
			{    0, 0,2}, /* core2 L2_parity_way bit50 */
			{    0, 0,2}, /* core2 L2_parity_way bit51 */
			{    0, 0,2}, /* core2 L2_parity_way bit52 */
			{    0, 0,2}, /* core2 L2_parity_way bit53 */
			{    0, 0,2}, /* core2 L2_parity_way bit54 */
			{    0, 0,2}, /* core2 L2_parity_way bit55 */
			{    0, 0,2}, /* core2 L2_parity_way bit56 */
			{    0, 0,2}, /* core2 L2_parity_way bit57 */
			{    0, 0,2}, /* core2 L2_parity_way bit58 */
			{    0, 0,2}, /* core2 L2_parity_way bit59 */
			{    0, 0,2}, /* core2 L2_parity_way bit60 */
			{    0, 0,2}, /* core2 L2_parity_way bit61 */
			{    0, 0,2}, /* core2 L2_parity_way bit62 */
			{    0, 0,2}, /* core2 L2_parity_way bit63 */
			}},
			.L2_parity_banks = {{
			{ 6961, 8,0}, /* core2 L2_parity_banks bit0 */
			{ 6960, 8,0}, /* core2 L2_parity_banks bit1 */
			{ 6959, 8,0}, /* core2 L2_parity_banks bit2 */
			{ 6958, 8,0}, /* core2 L2_parity_banks bit3 */
			{ 6957, 8,0}, /* core2 L2_parity_banks bit4 */
			{ 6956, 8,0}, /* core2 L2_parity_banks bit5 */
			{ 6955, 8,0}, /* core2 L2_parity_banks bit6 */
			{ 6954, 8,0}, /* core2 L2_parity_banks bit7 */
			{ 6929, 8,0}, /* core2 L2_parity_banks bit8 */
			{ 6928, 8,0}, /* core2 L2_parity_banks bit9 */
			{ 6927, 8,0}, /* core2 L2_parity_banks bit10 */
			{ 6926, 8,0}, /* core2 L2_parity_banks bit11 */
			{ 6925, 8,0}, /* core2 L2_parity_banks bit12 */
			{ 6924, 8,0}, /* core2 L2_parity_banks bit13 */
			{ 6923, 8,0}, /* core2 L2_parity_banks bit14 */
			{ 6922, 8,0}, /* core2 L2_parity_banks bit15 */
			{    0, 0,2}, /* core2 L2_parity_banks bit16 */
			{    0, 0,2}, /* core2 L2_parity_banks bit17 */
			{    0, 0,2}, /* core2 L2_parity_banks bit18 */
			{    0, 0,2}, /* core2 L2_parity_banks bit19 */
			{    0, 0,2}, /* core2 L2_parity_banks bit20 */
			{    0, 0,2}, /* core2 L2_parity_banks bit21 */
			{    0, 0,2}, /* core2 L2_parity_banks bit22 */
			{    0, 0,2}, /* core2 L2_parity_banks bit23 */
			{    0, 0,2}, /* core2 L2_parity_banks bit24 */
			{    0, 0,2}, /* core2 L2_parity_banks bit25 */
			{    0, 0,2}, /* core2 L2_parity_banks bit26 */
			{    0, 0,2}, /* core2 L2_parity_banks bit27 */
			{    0, 0,2}, /* core2 L2_parity_banks bit28 */
			{    0, 0,2}, /* core2 L2_parity_banks bit29 */
			{    0, 0,2}, /* core2 L2_parity_banks bit30 */
			{    0, 0,2}, /* core2 L2_parity_banks bit31 */
			{    0, 0,2}, /* core2 L2_parity_banks bit32 */
			{    0, 0,2}, /* core2 L2_parity_banks bit33 */
			{    0, 0,2}, /* core2 L2_parity_banks bit34 */
			{    0, 0,2}, /* core2 L2_parity_banks bit35 */
			{    0, 0,2}, /* core2 L2_parity_banks bit36 */
			{    0, 0,2}, /* core2 L2_parity_banks bit37 */
			{    0, 0,2}, /* core2 L2_parity_banks bit38 */
			{    0, 0,2}, /* core2 L2_parity_banks bit39 */
			{    0, 0,2}, /* core2 L2_parity_banks bit40 */
			{    0, 0,2}, /* core2 L2_parity_banks bit41 */
			{    0, 0,2}, /* core2 L2_parity_banks bit42 */
			{    0, 0,2}, /* core2 L2_parity_banks bit43 */
			{    0, 0,2}, /* core2 L2_parity_banks bit44 */
			{    0, 0,2}, /* core2 L2_parity_banks bit45 */
			{    0, 0,2}, /* core2 L2_parity_banks bit46 */
			{    0, 0,2}, /* core2 L2_parity_banks bit47 */
			{    0, 0,2}, /* core2 L2_parity_banks bit48 */
			{    0, 0,2}, /* core2 L2_parity_banks bit49 */
			{    0, 0,2}, /* core2 L2_parity_banks bit50 */
			{    0, 0,2}, /* core2 L2_parity_banks bit51 */
			{    0, 0,2}, /* core2 L2_parity_banks bit52 */
			{    0, 0,2}, /* core2 L2_parity_banks bit53 */
			{    0, 0,2}, /* core2 L2_parity_banks bit54 */
			{    0, 0,2}, /* core2 L2_parity_banks bit55 */
			{    0, 0,2}, /* core2 L2_parity_banks bit56 */
			{    0, 0,2}, /* core2 L2_parity_banks bit57 */
			{    0, 0,2}, /* core2 L2_parity_banks bit58 */
			{    0, 0,2}, /* core2 L2_parity_banks bit59 */
			{    0, 0,2}, /* core2 L2_parity_banks bit60 */
			{    0, 0,2}, /* core2 L2_parity_banks bit61 */
			{    0, 0,2}, /* core2 L2_parity_banks bit62 */
			{    0, 0,2}, /* core2 L2_parity_banks bit63 */
			}},
	},
	{		/* core 3 */ 
			.pc = {{
			{  392,39,1}, /* core3 pc bit0 */
			{  391,39,1}, /* core3 pc bit1 */
			{  390,39,1}, /* core3 pc bit2 */
			{  389,39,1}, /* core3 pc bit3 */
			{  440,39,1}, /* core3 pc bit4 */
			{  416,39,1}, /* core3 pc bit5 */
			{  439,39,1}, /* core3 pc bit6 */
			{  415,39,1}, /* core3 pc bit7 */
			{  388,39,1}, /* core3 pc bit8 */
			{  414,39,1}, /* core3 pc bit9 */
			{  344,39,1}, /* core3 pc bit10 */
			{  360,39,1}, /* core3 pc bit11 */
			{  359,39,1}, /* core3 pc bit12 */
			{  358,39,1}, /* core3 pc bit13 */
			{  343,39,1}, /* core3 pc bit14 */
			{  342,39,1}, /* core3 pc bit15 */
			{  413,39,1}, /* core3 pc bit16 */
			{  296,39,1}, /* core3 pc bit17 */
			{  357,39,1}, /* core3 pc bit18 */
			{  387,39,1}, /* core3 pc bit19 */
			{  356,39,1}, /* core3 pc bit20 */
			{  355,39,1}, /* core3 pc bit21 */
			{  412,39,1}, /* core3 pc bit22 */
			{  354,39,1}, /* core3 pc bit23 */
			{  353,39,1}, /* core3 pc bit24 */
			{  376,39,1}, /* core3 pc bit25 */
			{  352,39,1}, /* core3 pc bit26 */
			{  295,39,1}, /* core3 pc bit27 */
			{  386,39,1}, /* core3 pc bit28 */
			{  341,39,1}, /* core3 pc bit29 */
			{  385,39,1}, /* core3 pc bit30 */
			{  351,39,1}, /* core3 pc bit31 */
			{  264,39,1}, /* core3 pc bit32 */
			{  112,39,1}, /* core3 pc bit33 */
			{  263,39,1}, /* core3 pc bit34 */
			{  111,39,1}, /* core3 pc bit35 */
			{  172,39,1}, /* core3 pc bit36 */
			{  180,39,1}, /* core3 pc bit37 */
			{  262,39,1}, /* core3 pc bit38 */
			{  146,39,1}, /* core3 pc bit39 */
			{  179,39,1}, /* core3 pc bit40 */
			{  145,39,1}, /* core3 pc bit41 */
			{  136,39,1}, /* core3 pc bit42 */
			{  261,39,1}, /* core3 pc bit43 */
			{  260,39,1}, /* core3 pc bit44 */
			{  259,39,1}, /* core3 pc bit45 */
			{  144,39,1}, /* core3 pc bit46 */
			{  143,39,1}, /* core3 pc bit47 */
			{  438,39,1}, /* core3 pc bit48 */
			{  110,39,1}, /* core3 pc bit49 */
			{  207,39,1}, /* core3 pc bit50 */
			{  206,39,1}, /* core3 pc bit51 */
			{  411,39,1}, /* core3 pc bit52 */
			{  205,39,1}, /* core3 pc bit53 */
			{  109,39,1}, /* core3 pc bit54 */
			{  204,39,1}, /* core3 pc bit55 */
			{  258,39,1}, /* core3 pc bit56 */
			{  203,39,1}, /* core3 pc bit57 */
			{  178,39,1}, /* core3 pc bit58 */
			{  177,39,1}, /* core3 pc bit59 */
			{  202,39,1}, /* core3 pc bit60 */
			{  201,39,1}, /* core3 pc bit61 */
			{  200,39,1}, /* core3 pc bit62 */
			{  257,39,1}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{37603,40,0}, /* core3 sp32 bit0 */
			{37602,40,0}, /* core3 sp32 bit1 */
			{28162,40,1}, /* core3 sp32 bit2 */
			{28161,40,1}, /* core3 sp32 bit3 */
			{28160,40,1}, /* core3 sp32 bit4 */
			{28092,40,1}, /* core3 sp32 bit5 */
			{28159,40,1}, /* core3 sp32 bit6 */
			{28091,40,1}, /* core3 sp32 bit7 */
			{37601,40,0}, /* core3 sp32 bit8 */
			{37600,40,0}, /* core3 sp32 bit9 */
			{28158,40,1}, /* core3 sp32 bit10 */
			{28151,40,1}, /* core3 sp32 bit11 */
			{37583,40,0}, /* core3 sp32 bit12 */
			{37582,40,0}, /* core3 sp32 bit13 */
			{37581,40,0}, /* core3 sp32 bit14 */
			{37580,40,0}, /* core3 sp32 bit15 */
			{28135,40,1}, /* core3 sp32 bit16 */
			{28150,40,1}, /* core3 sp32 bit17 */
			{28131,40,1}, /* core3 sp32 bit18 */
			{28132,40,1}, /* core3 sp32 bit19 */
			{28144,40,1}, /* core3 sp32 bit20 */
			{28133,40,1}, /* core3 sp32 bit21 */
			{31013,39,1}, /* core3 sp32 bit22 */
			{31012,39,1}, /* core3 sp32 bit23 */
			{28130,40,1}, /* core3 sp32 bit24 */
			{28134,40,1}, /* core3 sp32 bit25 */
			{31011,39,1}, /* core3 sp32 bit26 */
			{31010,39,1}, /* core3 sp32 bit27 */
			{37579,40,0}, /* core3 sp32 bit28 */
			{37578,40,0}, /* core3 sp32 bit29 */
			{37593,40,0}, /* core3 sp32 bit30 */
			{37592,40,0}, /* core3 sp32 bit31 */
			{30913,39,1}, /* core3 sp32 bit32 */
			{30912,39,1}, /* core3 sp32 bit33 */
			{30911,39,1}, /* core3 sp32 bit34 */
			{30910,39,1}, /* core3 sp32 bit35 */
			{37623,40,0}, /* core3 sp32 bit36 */
			{37622,40,0}, /* core3 sp32 bit37 */
			{28277,40,1}, /* core3 sp32 bit38 */
			{37709,40,0}, /* core3 sp32 bit39 */
			{28274,40,1}, /* core3 sp32 bit40 */
			{37611,40,0}, /* core3 sp32 bit41 */
			{37625,40,0}, /* core3 sp32 bit42 */
			{37624,40,0}, /* core3 sp32 bit43 */
			{37708,40,0}, /* core3 sp32 bit44 */
			{37711,40,0}, /* core3 sp32 bit45 */
			{37610,40,0}, /* core3 sp32 bit46 */
			{37710,40,0}, /* core3 sp32 bit47 */
			{28278,40,1}, /* core3 sp32 bit48 */
			{28300,40,1}, /* core3 sp32 bit49 */
			{28296,40,1}, /* core3 sp32 bit50 */
			{28302,40,1}, /* core3 sp32 bit51 */
			{28283,40,1}, /* core3 sp32 bit52 */
			{28170,40,1}, /* core3 sp32 bit53 */
			{28281,40,1}, /* core3 sp32 bit54 */
			{28310,40,1}, /* core3 sp32 bit55 */
			{28279,40,1}, /* core3 sp32 bit56 */
			{28301,40,1}, /* core3 sp32 bit57 */
			{28169,40,1}, /* core3 sp32 bit58 */
			{28303,40,1}, /* core3 sp32 bit59 */
			{28171,40,1}, /* core3 sp32 bit60 */
			{28168,40,1}, /* core3 sp32 bit61 */
			{28295,40,1}, /* core3 sp32 bit62 */
			{28297,40,1}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{28348,40,1}, /* core3 fp32 bit0 */
			{28349,40,1}, /* core3 fp32 bit1 */
			{37719,40,0}, /* core3 fp32 bit2 */
			{37718,40,0}, /* core3 fp32 bit3 */
			{37721,40,0}, /* core3 fp32 bit4 */
			{37720,40,0}, /* core3 fp32 bit5 */
			{28353,40,1}, /* core3 fp32 bit6 */
			{28351,40,1}, /* core3 fp32 bit7 */
			{28352,40,1}, /* core3 fp32 bit8 */
			{28350,40,1}, /* core3 fp32 bit9 */
			{37751,40,0}, /* core3 fp32 bit10 */
			{37750,40,0}, /* core3 fp32 bit11 */
			{37747,40,0}, /* core3 fp32 bit12 */
			{37746,40,0}, /* core3 fp32 bit13 */
			{31129,39,1}, /* core3 fp32 bit14 */
			{31128,39,1}, /* core3 fp32 bit15 */
			{31127,39,1}, /* core3 fp32 bit16 */
			{31126,39,1}, /* core3 fp32 bit17 */
			{37745,40,0}, /* core3 fp32 bit18 */
			{37744,40,0}, /* core3 fp32 bit19 */
			{31125,39,1}, /* core3 fp32 bit20 */
			{31124,39,1}, /* core3 fp32 bit21 */
			{28375,40,1}, /* core3 fp32 bit22 */
			{31123,39,1}, /* core3 fp32 bit23 */
			{31122,39,1}, /* core3 fp32 bit24 */
			{31121,39,1}, /* core3 fp32 bit25 */
			{31120,39,1}, /* core3 fp32 bit26 */
			{31119,39,1}, /* core3 fp32 bit27 */
			{31118,39,1}, /* core3 fp32 bit28 */
			{28374,40,1}, /* core3 fp32 bit29 */
			{37749,40,0}, /* core3 fp32 bit30 */
			{37748,40,0}, /* core3 fp32 bit31 */
			{37833,39,1}, /* core3 fp32 bit32 */
			{37832,39,1}, /* core3 fp32 bit33 */
			{37831,39,1}, /* core3 fp32 bit34 */
			{37830,39,1}, /* core3 fp32 bit35 */
			{28509,40,1}, /* core3 fp32 bit36 */
			{28510,40,1}, /* core3 fp32 bit37 */
			{37645,40,0}, /* core3 fp32 bit38 */
			{37829,39,1}, /* core3 fp32 bit39 */
			{37828,39,1}, /* core3 fp32 bit40 */
			{37644,40,0}, /* core3 fp32 bit41 */
			{37827,39,1}, /* core3 fp32 bit42 */
			{37641,40,0}, /* core3 fp32 bit43 */
			{37640,40,0}, /* core3 fp32 bit44 */
			{28508,40,1}, /* core3 fp32 bit45 */
			{28507,40,1}, /* core3 fp32 bit46 */
			{37643,40,0}, /* core3 fp32 bit47 */
			{37642,40,0}, /* core3 fp32 bit48 */
			{28511,40,1}, /* core3 fp32 bit49 */
			{28486,40,1}, /* core3 fp32 bit50 */
			{37826,39,1}, /* core3 fp32 bit51 */
			{28476,40,1}, /* core3 fp32 bit52 */
			{28472,40,1}, /* core3 fp32 bit53 */
			{28475,40,1}, /* core3 fp32 bit54 */
			{28489,40,1}, /* core3 fp32 bit55 */
			{28474,40,1}, /* core3 fp32 bit56 */
			{28453,40,1}, /* core3 fp32 bit57 */
			{28484,40,1}, /* core3 fp32 bit58 */
			{28454,40,1}, /* core3 fp32 bit59 */
			{28487,40,1}, /* core3 fp32 bit60 */
			{28488,40,1}, /* core3 fp32 bit61 */
			{28485,40,1}, /* core3 fp32 bit62 */
			{28473,40,1}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{28058,40,1}, /* core3 fp64 bit0 */
			{28057,40,1}, /* core3 fp64 bit1 */
			{28059,40,1}, /* core3 fp64 bit2 */
			{28054,40,1}, /* core3 fp64 bit3 */
			{31029,39,1}, /* core3 fp64 bit4 */
			{31028,39,1}, /* core3 fp64 bit5 */
			{31027,39,1}, /* core3 fp64 bit6 */
			{31026,39,1}, /* core3 fp64 bit7 */
			{28056,40,1}, /* core3 fp64 bit8 */
			{28055,40,1}, /* core3 fp64 bit9 */
			{37529,39,1}, /* core3 fp64 bit10 */
			{28060,40,1}, /* core3 fp64 bit11 */
			{27855,40,1}, /* core3 fp64 bit12 */
			{37528,39,1}, /* core3 fp64 bit13 */
			{37527,39,1}, /* core3 fp64 bit14 */
			{37526,39,1}, /* core3 fp64 bit15 */
			{30993,39,1}, /* core3 fp64 bit16 */
			{30992,39,1}, /* core3 fp64 bit17 */
			{37525,39,1}, /* core3 fp64 bit18 */
			{37524,39,1}, /* core3 fp64 bit19 */
			{37523,39,1}, /* core3 fp64 bit20 */
			{37522,39,1}, /* core3 fp64 bit21 */
			{30991,39,1}, /* core3 fp64 bit22 */
			{30990,39,1}, /* core3 fp64 bit23 */
			{27845,40,1}, /* core3 fp64 bit24 */
			{27843,40,1}, /* core3 fp64 bit25 */
			{27844,40,1}, /* core3 fp64 bit26 */
			{27842,40,1}, /* core3 fp64 bit27 */
			{37481,40,0}, /* core3 fp64 bit28 */
			{37480,40,0}, /* core3 fp64 bit29 */
			{37487,40,0}, /* core3 fp64 bit30 */
			{37486,40,0}, /* core3 fp64 bit31 */
			{30825,39,1}, /* core3 fp64 bit32 */
			{30837,39,1}, /* core3 fp64 bit33 */
			{30836,39,1}, /* core3 fp64 bit34 */
			{30835,39,1}, /* core3 fp64 bit35 */
			{30834,39,1}, /* core3 fp64 bit36 */
			{30824,39,1}, /* core3 fp64 bit37 */
			{30823,39,1}, /* core3 fp64 bit38 */
			{30822,39,1}, /* core3 fp64 bit39 */
			{27896,40,1}, /* core3 fp64 bit40 */
			{27982,40,1}, /* core3 fp64 bit41 */
			{37325,40,0}, /* core3 fp64 bit42 */
			{37324,40,0}, /* core3 fp64 bit43 */
			{30821,39,1}, /* core3 fp64 bit44 */
			{30820,39,1}, /* core3 fp64 bit45 */
			{27894,40,1}, /* core3 fp64 bit46 */
			{30819,39,1}, /* core3 fp64 bit47 */
			{27895,40,1}, /* core3 fp64 bit48 */
			{30818,39,1}, /* core3 fp64 bit49 */
			{30833,39,1}, /* core3 fp64 bit50 */
			{30832,39,1}, /* core3 fp64 bit51 */
			{30831,39,1}, /* core3 fp64 bit52 */
			{30830,39,1}, /* core3 fp64 bit53 */
			{30841,39,1}, /* core3 fp64 bit54 */
			{27983,40,1}, /* core3 fp64 bit55 */
			{30840,39,1}, /* core3 fp64 bit56 */
			{30839,39,1}, /* core3 fp64 bit57 */
			{27984,40,1}, /* core3 fp64 bit58 */
			{30838,39,1}, /* core3 fp64 bit59 */
			{30829,39,1}, /* core3 fp64 bit60 */
			{30828,39,1}, /* core3 fp64 bit61 */
			{30827,39,1}, /* core3 fp64 bit62 */
			{30826,39,1}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{28040,40,1}, /* core3 sp_EL0 bit0 */
			{28038,40,1}, /* core3 sp_EL0 bit1 */
			{28039,40,1}, /* core3 sp_EL0 bit2 */
			{28035,40,1}, /* core3 sp_EL0 bit3 */
			{28037,40,1}, /* core3 sp_EL0 bit4 */
			{28036,40,1}, /* core3 sp_EL0 bit5 */
			{37399,40,0}, /* core3 sp_EL0 bit6 */
			{37398,40,0}, /* core3 sp_EL0 bit7 */
			{37397,40,0}, /* core3 sp_EL0 bit8 */
			{37396,40,0}, /* core3 sp_EL0 bit9 */
			{27861,40,1}, /* core3 sp_EL0 bit10 */
			{28029,40,1}, /* core3 sp_EL0 bit11 */
			{27859,40,1}, /* core3 sp_EL0 bit12 */
			{27851,40,1}, /* core3 sp_EL0 bit13 */
			{37467,40,0}, /* core3 sp_EL0 bit14 */
			{37466,40,0}, /* core3 sp_EL0 bit15 */
			{27858,40,1}, /* core3 sp_EL0 bit16 */
			{27860,40,1}, /* core3 sp_EL0 bit17 */
			{37479,40,0}, /* core3 sp_EL0 bit18 */
			{37478,40,0}, /* core3 sp_EL0 bit19 */
			{37475,40,0}, /* core3 sp_EL0 bit20 */
			{37474,40,0}, /* core3 sp_EL0 bit21 */
			{37471,40,0}, /* core3 sp_EL0 bit22 */
			{37470,40,0}, /* core3 sp_EL0 bit23 */
			{30989,39,1}, /* core3 sp_EL0 bit24 */
			{30988,39,1}, /* core3 sp_EL0 bit25 */
			{30987,39,1}, /* core3 sp_EL0 bit26 */
			{30986,39,1}, /* core3 sp_EL0 bit27 */
			{37477,40,0}, /* core3 sp_EL0 bit28 */
			{37476,40,0}, /* core3 sp_EL0 bit29 */
			{27841,40,1}, /* core3 sp_EL0 bit30 */
			{28041,40,1}, /* core3 sp_EL0 bit31 */
			{37287,40,0}, /* core3 sp_EL0 bit32 */
			{37577,39,1}, /* core3 sp_EL0 bit33 */
			{37576,39,1}, /* core3 sp_EL0 bit34 */
			{37575,39,1}, /* core3 sp_EL0 bit35 */
			{37574,39,1}, /* core3 sp_EL0 bit36 */
			{37573,39,1}, /* core3 sp_EL0 bit37 */
			{37572,39,1}, /* core3 sp_EL0 bit38 */
			{37286,40,0}, /* core3 sp_EL0 bit39 */
			{37571,39,1}, /* core3 sp_EL0 bit40 */
			{37570,39,1}, /* core3 sp_EL0 bit41 */
			{37367,40,0}, /* core3 sp_EL0 bit42 */
			{37366,40,0}, /* core3 sp_EL0 bit43 */
			{37285,40,0}, /* core3 sp_EL0 bit44 */
			{37284,40,0}, /* core3 sp_EL0 bit45 */
			{27962,40,1}, /* core3 sp_EL0 bit46 */
			{27934,40,1}, /* core3 sp_EL0 bit47 */
			{37269,40,0}, /* core3 sp_EL0 bit48 */
			{37268,40,0}, /* core3 sp_EL0 bit49 */
			{37283,40,0}, /* core3 sp_EL0 bit50 */
			{37282,40,0}, /* core3 sp_EL0 bit51 */
			{37273,40,0}, /* core3 sp_EL0 bit52 */
			{37272,40,0}, /* core3 sp_EL0 bit53 */
			{37267,40,0}, /* core3 sp_EL0 bit54 */
			{37266,40,0}, /* core3 sp_EL0 bit55 */
			{37265,40,0}, /* core3 sp_EL0 bit56 */
			{37264,40,0}, /* core3 sp_EL0 bit57 */
			{30813,39,1}, /* core3 sp_EL0 bit58 */
			{30812,39,1}, /* core3 sp_EL0 bit59 */
			{37271,40,0}, /* core3 sp_EL0 bit60 */
			{37270,40,0}, /* core3 sp_EL0 bit61 */
			{30811,39,1}, /* core3 sp_EL0 bit62 */
			{30810,39,1}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{28034,40,1}, /* core3 sp_EL1 bit0 */
			{27881,40,1}, /* core3 sp_EL1 bit1 */
			{37395,40,0}, /* core3 sp_EL1 bit2 */
			{37394,40,0}, /* core3 sp_EL1 bit3 */
			{28032,40,1}, /* core3 sp_EL1 bit4 */
			{28033,40,1}, /* core3 sp_EL1 bit5 */
			{37393,40,0}, /* core3 sp_EL1 bit6 */
			{37392,40,0}, /* core3 sp_EL1 bit7 */
			{30569,39,1}, /* core3 sp_EL1 bit8 */
			{30568,39,1}, /* core3 sp_EL1 bit9 */
			{37465,40,0}, /* core3 sp_EL1 bit10 */
			{30567,39,1}, /* core3 sp_EL1 bit11 */
			{30566,39,1}, /* core3 sp_EL1 bit12 */
			{37464,40,0}, /* core3 sp_EL1 bit13 */
			{27863,40,1}, /* core3 sp_EL1 bit14 */
			{27864,40,1}, /* core3 sp_EL1 bit15 */
			{28030,40,1}, /* core3 sp_EL1 bit16 */
			{27862,40,1}, /* core3 sp_EL1 bit17 */
			{27836,40,1}, /* core3 sp_EL1 bit18 */
			{27839,40,1}, /* core3 sp_EL1 bit19 */
			{27838,40,1}, /* core3 sp_EL1 bit20 */
			{27837,40,1}, /* core3 sp_EL1 bit21 */
			{37493,40,0}, /* core3 sp_EL1 bit22 */
			{30597,39,1}, /* core3 sp_EL1 bit23 */
			{30596,39,1}, /* core3 sp_EL1 bit24 */
			{30595,39,1}, /* core3 sp_EL1 bit25 */
			{30594,39,1}, /* core3 sp_EL1 bit26 */
			{37492,40,0}, /* core3 sp_EL1 bit27 */
			{37495,40,0}, /* core3 sp_EL1 bit28 */
			{37494,40,0}, /* core3 sp_EL1 bit29 */
			{27840,40,1}, /* core3 sp_EL1 bit30 */
			{28031,40,1}, /* core3 sp_EL1 bit31 */
			{27935,40,1}, /* core3 sp_EL1 bit32 */
			{27963,40,1}, /* core3 sp_EL1 bit33 */
			{37365,40,0}, /* core3 sp_EL1 bit34 */
			{37364,40,0}, /* core3 sp_EL1 bit35 */
			{37363,40,0}, /* core3 sp_EL1 bit36 */
			{37362,40,0}, /* core3 sp_EL1 bit37 */
			{27966,40,1}, /* core3 sp_EL1 bit38 */
			{27931,40,1}, /* core3 sp_EL1 bit39 */
			{30653,39,1}, /* core3 sp_EL1 bit40 */
			{30652,39,1}, /* core3 sp_EL1 bit41 */
			{30651,39,1}, /* core3 sp_EL1 bit42 */
			{30650,39,1}, /* core3 sp_EL1 bit43 */
			{37279,40,0}, /* core3 sp_EL1 bit44 */
			{37278,40,0}, /* core3 sp_EL1 bit45 */
			{27964,40,1}, /* core3 sp_EL1 bit46 */
			{27933,40,1}, /* core3 sp_EL1 bit47 */
			{27932,40,1}, /* core3 sp_EL1 bit48 */
			{27965,40,1}, /* core3 sp_EL1 bit49 */
			{37281,40,0}, /* core3 sp_EL1 bit50 */
			{37280,40,0}, /* core3 sp_EL1 bit51 */
			{37275,40,0}, /* core3 sp_EL1 bit52 */
			{37274,40,0}, /* core3 sp_EL1 bit53 */
			{37263,40,0}, /* core3 sp_EL1 bit54 */
			{37262,40,0}, /* core3 sp_EL1 bit55 */
			{37261,40,0}, /* core3 sp_EL1 bit56 */
			{37260,40,0}, /* core3 sp_EL1 bit57 */
			{37349,40,0}, /* core3 sp_EL1 bit58 */
			{37348,40,0}, /* core3 sp_EL1 bit59 */
			{37353,40,0}, /* core3 sp_EL1 bit60 */
			{37352,40,0}, /* core3 sp_EL1 bit61 */
			{37277,40,0}, /* core3 sp_EL1 bit62 */
			{37276,40,0}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{28047,40,1}, /* core3 sp_EL2 bit0 */
			{28053,40,1}, /* core3 sp_EL2 bit1 */
			{28052,40,1}, /* core3 sp_EL2 bit2 */
			{28049,40,1}, /* core3 sp_EL2 bit3 */
			{28051,40,1}, /* core3 sp_EL2 bit4 */
			{28050,40,1}, /* core3 sp_EL2 bit5 */
			{28028,40,1}, /* core3 sp_EL2 bit6 */
			{28026,40,1}, /* core3 sp_EL2 bit7 */
			{28027,40,1}, /* core3 sp_EL2 bit8 */
			{28048,40,1}, /* core3 sp_EL2 bit9 */
			{27856,40,1}, /* core3 sp_EL2 bit10 */
			{28061,40,1}, /* core3 sp_EL2 bit11 */
			{27857,40,1}, /* core3 sp_EL2 bit12 */
			{27847,40,1}, /* core3 sp_EL2 bit13 */
			{27854,40,1}, /* core3 sp_EL2 bit14 */
			{37459,40,0}, /* core3 sp_EL2 bit15 */
			{37458,40,0}, /* core3 sp_EL2 bit16 */
			{27853,40,1}, /* core3 sp_EL2 bit17 */
			{37461,40,0}, /* core3 sp_EL2 bit18 */
			{37460,40,0}, /* core3 sp_EL2 bit19 */
			{27852,40,1}, /* core3 sp_EL2 bit20 */
			{27846,40,1}, /* core3 sp_EL2 bit21 */
			{30585,39,1}, /* core3 sp_EL2 bit22 */
			{30589,39,1}, /* core3 sp_EL2 bit23 */
			{30588,39,1}, /* core3 sp_EL2 bit24 */
			{30587,39,1}, /* core3 sp_EL2 bit25 */
			{30584,39,1}, /* core3 sp_EL2 bit26 */
			{30586,39,1}, /* core3 sp_EL2 bit27 */
			{30583,39,1}, /* core3 sp_EL2 bit28 */
			{37489,40,0}, /* core3 sp_EL2 bit29 */
			{37488,40,0}, /* core3 sp_EL2 bit30 */
			{30582,39,1}, /* core3 sp_EL2 bit31 */
			{37601,39,1}, /* core3 sp_EL2 bit32 */
			{30649,39,1}, /* core3 sp_EL2 bit33 */
			{30648,39,1}, /* core3 sp_EL2 bit34 */
			{30647,39,1}, /* core3 sp_EL2 bit35 */
			{30646,39,1}, /* core3 sp_EL2 bit36 */
			{37359,40,0}, /* core3 sp_EL2 bit37 */
			{37358,40,0}, /* core3 sp_EL2 bit38 */
			{37600,39,1}, /* core3 sp_EL2 bit39 */
			{37361,40,0}, /* core3 sp_EL2 bit40 */
			{37360,40,0}, /* core3 sp_EL2 bit41 */
			{30645,39,1}, /* core3 sp_EL2 bit42 */
			{30644,39,1}, /* core3 sp_EL2 bit43 */
			{37599,39,1}, /* core3 sp_EL2 bit44 */
			{37598,39,1}, /* core3 sp_EL2 bit45 */
			{30643,39,1}, /* core3 sp_EL2 bit46 */
			{37597,39,1}, /* core3 sp_EL2 bit47 */
			{37596,39,1}, /* core3 sp_EL2 bit48 */
			{30642,39,1}, /* core3 sp_EL2 bit49 */
			{37595,39,1}, /* core3 sp_EL2 bit50 */
			{37594,39,1}, /* core3 sp_EL2 bit51 */
			{37593,39,1}, /* core3 sp_EL2 bit52 */
			{37592,39,1}, /* core3 sp_EL2 bit53 */
			{27970,40,1}, /* core3 sp_EL2 bit54 */
			{37591,39,1}, /* core3 sp_EL2 bit55 */
			{27971,40,1}, /* core3 sp_EL2 bit56 */
			{37355,40,0}, /* core3 sp_EL2 bit57 */
			{37590,39,1}, /* core3 sp_EL2 bit58 */
			{37589,39,1}, /* core3 sp_EL2 bit59 */
			{37588,39,1}, /* core3 sp_EL2 bit60 */
			{37587,39,1}, /* core3 sp_EL2 bit61 */
			{37354,40,0}, /* core3 sp_EL2 bit62 */
			{37586,39,1}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{28045,40,1}, /* core3 sp_EL3 bit0 */
			{28046,40,1}, /* core3 sp_EL3 bit1 */
			{28044,40,1}, /* core3 sp_EL3 bit2 */
			{28043,40,1}, /* core3 sp_EL3 bit3 */
			{30573,39,1}, /* core3 sp_EL3 bit4 */
			{30572,39,1}, /* core3 sp_EL3 bit5 */
			{30571,39,1}, /* core3 sp_EL3 bit6 */
			{30570,39,1}, /* core3 sp_EL3 bit7 */
			{30577,39,1}, /* core3 sp_EL3 bit8 */
			{30576,39,1}, /* core3 sp_EL3 bit9 */
			{30575,39,1}, /* core3 sp_EL3 bit10 */
			{30574,39,1}, /* core3 sp_EL3 bit11 */
			{30581,39,1}, /* core3 sp_EL3 bit12 */
			{30580,39,1}, /* core3 sp_EL3 bit13 */
			{30579,39,1}, /* core3 sp_EL3 bit14 */
			{30578,39,1}, /* core3 sp_EL3 bit15 */
			{37463,40,0}, /* core3 sp_EL3 bit16 */
			{37462,40,0}, /* core3 sp_EL3 bit17 */
			{37473,40,0}, /* core3 sp_EL3 bit18 */
			{37472,40,0}, /* core3 sp_EL3 bit19 */
			{27850,40,1}, /* core3 sp_EL3 bit20 */
			{27848,40,1}, /* core3 sp_EL3 bit21 */
			{37469,40,0}, /* core3 sp_EL3 bit22 */
			{37468,40,0}, /* core3 sp_EL3 bit23 */
			{30593,39,1}, /* core3 sp_EL3 bit24 */
			{30592,39,1}, /* core3 sp_EL3 bit25 */
			{30591,39,1}, /* core3 sp_EL3 bit26 */
			{30590,39,1}, /* core3 sp_EL3 bit27 */
			{37491,40,0}, /* core3 sp_EL3 bit28 */
			{37490,40,0}, /* core3 sp_EL3 bit29 */
			{27849,40,1}, /* core3 sp_EL3 bit30 */
			{28042,40,1}, /* core3 sp_EL3 bit31 */
			{37289,40,0}, /* core3 sp_EL3 bit32 */
			{37585,39,1}, /* core3 sp_EL3 bit33 */
			{37584,39,1}, /* core3 sp_EL3 bit34 */
			{37583,39,1}, /* core3 sp_EL3 bit35 */
			{37582,39,1}, /* core3 sp_EL3 bit36 */
			{37581,39,1}, /* core3 sp_EL3 bit37 */
			{37580,39,1}, /* core3 sp_EL3 bit38 */
			{37288,40,0}, /* core3 sp_EL3 bit39 */
			{37579,39,1}, /* core3 sp_EL3 bit40 */
			{37578,39,1}, /* core3 sp_EL3 bit41 */
			{37357,40,0}, /* core3 sp_EL3 bit42 */
			{37356,40,0}, /* core3 sp_EL3 bit43 */
			{37347,40,0}, /* core3 sp_EL3 bit44 */
			{37346,40,0}, /* core3 sp_EL3 bit45 */
			{27969,40,1}, /* core3 sp_EL3 bit46 */
			{27974,40,1}, /* core3 sp_EL3 bit47 */
			{27973,40,1}, /* core3 sp_EL3 bit48 */
			{27967,40,1}, /* core3 sp_EL3 bit49 */
			{37351,40,0}, /* core3 sp_EL3 bit50 */
			{37350,40,0}, /* core3 sp_EL3 bit51 */
			{37259,40,0}, /* core3 sp_EL3 bit52 */
			{37258,40,0}, /* core3 sp_EL3 bit53 */
			{27968,40,1}, /* core3 sp_EL3 bit54 */
			{27972,40,1}, /* core3 sp_EL3 bit55 */
			{37078,40,0}, /* core3 sp_EL3 bit56 */
			{37077,40,0}, /* core3 sp_EL3 bit57 */
			{37074,40,0}, /* core3 sp_EL3 bit58 */
			{37073,40,0}, /* core3 sp_EL3 bit59 */
			{37076,40,0}, /* core3 sp_EL3 bit60 */
			{37075,40,0}, /* core3 sp_EL3 bit61 */
			{37072,40,0}, /* core3 sp_EL3 bit62 */
			{37071,40,0}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{37561,39,1}, /* core3 elr_EL1 bit0 */
			{37560,39,1}, /* core3 elr_EL1 bit1 */
			{37559,39,1}, /* core3 elr_EL1 bit2 */
			{37558,39,1}, /* core3 elr_EL1 bit3 */
			{37557,39,1}, /* core3 elr_EL1 bit4 */
			{37556,39,1}, /* core3 elr_EL1 bit5 */
			{37555,39,1}, /* core3 elr_EL1 bit6 */
			{37554,39,1}, /* core3 elr_EL1 bit7 */
			{37036,40,0}, /* core3 elr_EL1 bit8 */
			{37035,40,0}, /* core3 elr_EL1 bit9 */
			{30621,39,1}, /* core3 elr_EL1 bit10 */
			{30620,39,1}, /* core3 elr_EL1 bit11 */
			{37030,40,0}, /* core3 elr_EL1 bit12 */
			{37029,40,0}, /* core3 elr_EL1 bit13 */
			{37022,40,0}, /* core3 elr_EL1 bit14 */
			{37021,40,0}, /* core3 elr_EL1 bit15 */
			{30605,39,1}, /* core3 elr_EL1 bit16 */
			{30604,39,1}, /* core3 elr_EL1 bit17 */
			{30603,39,1}, /* core3 elr_EL1 bit18 */
			{30602,39,1}, /* core3 elr_EL1 bit19 */
			{37018,40,0}, /* core3 elr_EL1 bit20 */
			{37017,40,0}, /* core3 elr_EL1 bit21 */
			{30619,39,1}, /* core3 elr_EL1 bit22 */
			{30618,39,1}, /* core3 elr_EL1 bit23 */
			{30601,39,1}, /* core3 elr_EL1 bit24 */
			{30600,39,1}, /* core3 elr_EL1 bit25 */
			{30599,39,1}, /* core3 elr_EL1 bit26 */
			{30598,39,1}, /* core3 elr_EL1 bit27 */
			{37020,40,0}, /* core3 elr_EL1 bit28 */
			{37019,40,0}, /* core3 elr_EL1 bit29 */
			{37032,40,0}, /* core3 elr_EL1 bit30 */
			{37031,40,0}, /* core3 elr_EL1 bit31 */
			{27939,40,1}, /* core3 elr_EL1 bit32 */
			{27953,40,1}, /* core3 elr_EL1 bit33 */
			{37052,40,0}, /* core3 elr_EL1 bit34 */
			{37051,40,0}, /* core3 elr_EL1 bit35 */
			{37050,40,0}, /* core3 elr_EL1 bit36 */
			{37049,40,0}, /* core3 elr_EL1 bit37 */
			{27954,40,1}, /* core3 elr_EL1 bit38 */
			{27938,40,1}, /* core3 elr_EL1 bit39 */
			{30641,39,1}, /* core3 elr_EL1 bit40 */
			{30640,39,1}, /* core3 elr_EL1 bit41 */
			{30639,39,1}, /* core3 elr_EL1 bit42 */
			{30638,39,1}, /* core3 elr_EL1 bit43 */
			{37038,40,0}, /* core3 elr_EL1 bit44 */
			{37037,40,0}, /* core3 elr_EL1 bit45 */
			{27955,40,1}, /* core3 elr_EL1 bit46 */
			{27950,40,1}, /* core3 elr_EL1 bit47 */
			{27949,40,1}, /* core3 elr_EL1 bit48 */
			{27952,40,1}, /* core3 elr_EL1 bit49 */
			{37042,40,0}, /* core3 elr_EL1 bit50 */
			{37041,40,0}, /* core3 elr_EL1 bit51 */
			{37044,40,0}, /* core3 elr_EL1 bit52 */
			{37043,40,0}, /* core3 elr_EL1 bit53 */
			{37048,40,0}, /* core3 elr_EL1 bit54 */
			{37047,40,0}, /* core3 elr_EL1 bit55 */
			{37058,40,0}, /* core3 elr_EL1 bit56 */
			{37057,40,0}, /* core3 elr_EL1 bit57 */
			{37040,40,0}, /* core3 elr_EL1 bit58 */
			{37039,40,0}, /* core3 elr_EL1 bit59 */
			{37046,40,0}, /* core3 elr_EL1 bit60 */
			{37045,40,0}, /* core3 elr_EL1 bit61 */
			{27951,40,1}, /* core3 elr_EL1 bit62 */
			{27940,40,1}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{37553,39,1}, /* core3 elr_EL2 bit0 */
			{37552,39,1}, /* core3 elr_EL2 bit1 */
			{37551,39,1}, /* core3 elr_EL2 bit2 */
			{37550,39,1}, /* core3 elr_EL2 bit3 */
			{37549,39,1}, /* core3 elr_EL2 bit4 */
			{37548,39,1}, /* core3 elr_EL2 bit5 */
			{37547,39,1}, /* core3 elr_EL2 bit6 */
			{37546,39,1}, /* core3 elr_EL2 bit7 */
			{30629,39,1}, /* core3 elr_EL2 bit8 */
			{30628,39,1}, /* core3 elr_EL2 bit9 */
			{37537,39,1}, /* core3 elr_EL2 bit10 */
			{30627,39,1}, /* core3 elr_EL2 bit11 */
			{37536,39,1}, /* core3 elr_EL2 bit12 */
			{30626,39,1}, /* core3 elr_EL2 bit13 */
			{37535,39,1}, /* core3 elr_EL2 bit14 */
			{37534,39,1}, /* core3 elr_EL2 bit15 */
			{37533,39,1}, /* core3 elr_EL2 bit16 */
			{37532,39,1}, /* core3 elr_EL2 bit17 */
			{37531,39,1}, /* core3 elr_EL2 bit18 */
			{37530,39,1}, /* core3 elr_EL2 bit19 */
			{30609,39,1}, /* core3 elr_EL2 bit20 */
			{30608,39,1}, /* core3 elr_EL2 bit21 */
			{30607,39,1}, /* core3 elr_EL2 bit22 */
			{30606,39,1}, /* core3 elr_EL2 bit23 */
			{30613,39,1}, /* core3 elr_EL2 bit24 */
			{30612,39,1}, /* core3 elr_EL2 bit25 */
			{30611,39,1}, /* core3 elr_EL2 bit26 */
			{30610,39,1}, /* core3 elr_EL2 bit27 */
			{37024,40,0}, /* core3 elr_EL2 bit28 */
			{37023,40,0}, /* core3 elr_EL2 bit29 */
			{27873,40,1}, /* core3 elr_EL2 bit30 */
			{27878,40,1}, /* core3 elr_EL2 bit31 */
			{27943,40,1}, /* core3 elr_EL2 bit32 */
			{27956,40,1}, /* core3 elr_EL2 bit33 */
			{37054,40,0}, /* core3 elr_EL2 bit34 */
			{37053,40,0}, /* core3 elr_EL2 bit35 */
			{37056,40,0}, /* core3 elr_EL2 bit36 */
			{37055,40,0}, /* core3 elr_EL2 bit37 */
			{27957,40,1}, /* core3 elr_EL2 bit38 */
			{27942,40,1}, /* core3 elr_EL2 bit39 */
			{30637,39,1}, /* core3 elr_EL2 bit40 */
			{30636,39,1}, /* core3 elr_EL2 bit41 */
			{30635,39,1}, /* core3 elr_EL2 bit42 */
			{30634,39,1}, /* core3 elr_EL2 bit43 */
			{37070,40,0}, /* core3 elr_EL2 bit44 */
			{37069,40,0}, /* core3 elr_EL2 bit45 */
			{27958,40,1}, /* core3 elr_EL2 bit46 */
			{27948,40,1}, /* core3 elr_EL2 bit47 */
			{27947,40,1}, /* core3 elr_EL2 bit48 */
			{27959,40,1}, /* core3 elr_EL2 bit49 */
			{37066,40,0}, /* core3 elr_EL2 bit50 */
			{37065,40,0}, /* core3 elr_EL2 bit51 */
			{37062,40,0}, /* core3 elr_EL2 bit52 */
			{37061,40,0}, /* core3 elr_EL2 bit53 */
			{30633,39,1}, /* core3 elr_EL2 bit54 */
			{30632,39,1}, /* core3 elr_EL2 bit55 */
			{37060,40,0}, /* core3 elr_EL2 bit56 */
			{37059,40,0}, /* core3 elr_EL2 bit57 */
			{37068,40,0}, /* core3 elr_EL2 bit58 */
			{37067,40,0}, /* core3 elr_EL2 bit59 */
			{37064,40,0}, /* core3 elr_EL2 bit60 */
			{37063,40,0}, /* core3 elr_EL2 bit61 */
			{30631,39,1}, /* core3 elr_EL2 bit62 */
			{30630,39,1}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{37545,39,1}, /* core3 elr_EL3 bit0 */
			{37544,39,1}, /* core3 elr_EL3 bit1 */
			{37543,39,1}, /* core3 elr_EL3 bit2 */
			{37542,39,1}, /* core3 elr_EL3 bit3 */
			{37541,39,1}, /* core3 elr_EL3 bit4 */
			{37540,39,1}, /* core3 elr_EL3 bit5 */
			{37539,39,1}, /* core3 elr_EL3 bit6 */
			{37538,39,1}, /* core3 elr_EL3 bit7 */
			{37034,40,0}, /* core3 elr_EL3 bit8 */
			{37033,40,0}, /* core3 elr_EL3 bit9 */
			{30625,39,1}, /* core3 elr_EL3 bit10 */
			{30624,39,1}, /* core3 elr_EL3 bit11 */
			{30623,39,1}, /* core3 elr_EL3 bit12 */
			{30622,39,1}, /* core3 elr_EL3 bit13 */
			{37026,40,0}, /* core3 elr_EL3 bit14 */
			{37025,40,0}, /* core3 elr_EL3 bit15 */
			{37014,40,0}, /* core3 elr_EL3 bit16 */
			{37013,40,0}, /* core3 elr_EL3 bit17 */
			{27866,40,1}, /* core3 elr_EL3 bit18 */
			{27867,40,1}, /* core3 elr_EL3 bit19 */
			{30617,39,1}, /* core3 elr_EL3 bit20 */
			{30616,39,1}, /* core3 elr_EL3 bit21 */
			{30615,39,1}, /* core3 elr_EL3 bit22 */
			{30614,39,1}, /* core3 elr_EL3 bit23 */
			{27865,40,1}, /* core3 elr_EL3 bit24 */
			{27874,40,1}, /* core3 elr_EL3 bit25 */
			{37016,40,0}, /* core3 elr_EL3 bit26 */
			{37015,40,0}, /* core3 elr_EL3 bit27 */
			{37028,40,0}, /* core3 elr_EL3 bit28 */
			{37027,40,0}, /* core3 elr_EL3 bit29 */
			{27868,40,1}, /* core3 elr_EL3 bit30 */
			{27877,40,1}, /* core3 elr_EL3 bit31 */
			{30669,39,1}, /* core3 elr_EL3 bit32 */
			{30668,39,1}, /* core3 elr_EL3 bit33 */
			{30667,39,1}, /* core3 elr_EL3 bit34 */
			{30666,39,1}, /* core3 elr_EL3 bit35 */
			{30657,39,1}, /* core3 elr_EL3 bit36 */
			{30656,39,1}, /* core3 elr_EL3 bit37 */
			{30655,39,1}, /* core3 elr_EL3 bit38 */
			{30654,39,1}, /* core3 elr_EL3 bit39 */
			{37012,40,0}, /* core3 elr_EL3 bit40 */
			{37011,40,0}, /* core3 elr_EL3 bit41 */
			{27928,40,1}, /* core3 elr_EL3 bit42 */
			{27927,40,1}, /* core3 elr_EL3 bit43 */
			{30661,39,1}, /* core3 elr_EL3 bit44 */
			{30660,39,1}, /* core3 elr_EL3 bit45 */
			{30659,39,1}, /* core3 elr_EL3 bit46 */
			{30658,39,1}, /* core3 elr_EL3 bit47 */
			{30665,39,1}, /* core3 elr_EL3 bit48 */
			{30664,39,1}, /* core3 elr_EL3 bit49 */
			{30663,39,1}, /* core3 elr_EL3 bit50 */
			{30662,39,1}, /* core3 elr_EL3 bit51 */
			{30565,39,1}, /* core3 elr_EL3 bit52 */
			{30564,39,1}, /* core3 elr_EL3 bit53 */
			{30563,39,1}, /* core3 elr_EL3 bit54 */
			{30562,39,1}, /* core3 elr_EL3 bit55 */
			{37513,39,1}, /* core3 elr_EL3 bit56 */
			{37512,39,1}, /* core3 elr_EL3 bit57 */
			{37511,39,1}, /* core3 elr_EL3 bit58 */
			{37510,39,1}, /* core3 elr_EL3 bit59 */
			{37509,39,1}, /* core3 elr_EL3 bit60 */
			{37508,39,1}, /* core3 elr_EL3 bit61 */
			{37507,39,1}, /* core3 elr_EL3 bit62 */
			{37506,39,1}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31320,40,1}, /* core3 raw_pc bit0 */
			{31430,40,1}, /* core3 raw_pc bit1 */
			{32637,39,1}, /* core3 raw_pc bit2 */
			{32636,39,1}, /* core3 raw_pc bit3 */
			{32635,39,1}, /* core3 raw_pc bit4 */
			{32634,39,1}, /* core3 raw_pc bit5 */
			{31328,40,1}, /* core3 raw_pc bit6 */
			{39377,39,1}, /* core3 raw_pc bit7 */
			{39376,39,1}, /* core3 raw_pc bit8 */
			{39375,39,1}, /* core3 raw_pc bit9 */
			{39374,39,1}, /* core3 raw_pc bit10 */
			{39373,39,1}, /* core3 raw_pc bit11 */
			{39372,39,1}, /* core3 raw_pc bit12 */
			{39371,39,1}, /* core3 raw_pc bit13 */
			{39370,39,1}, /* core3 raw_pc bit14 */
			{39305,39,1}, /* core3 raw_pc bit15 */
			{39304,39,1}, /* core3 raw_pc bit16 */
			{39303,39,1}, /* core3 raw_pc bit17 */
			{39302,39,1}, /* core3 raw_pc bit18 */
			{39301,39,1}, /* core3 raw_pc bit19 */
			{39300,39,1}, /* core3 raw_pc bit20 */
			{39299,39,1}, /* core3 raw_pc bit21 */
			{39298,39,1}, /* core3 raw_pc bit22 */
			{39313,39,1}, /* core3 raw_pc bit23 */
			{39312,39,1}, /* core3 raw_pc bit24 */
			{39311,39,1}, /* core3 raw_pc bit25 */
			{39310,39,1}, /* core3 raw_pc bit26 */
			{39309,39,1}, /* core3 raw_pc bit27 */
			{39308,39,1}, /* core3 raw_pc bit28 */
			{39307,39,1}, /* core3 raw_pc bit29 */
			{39306,39,1}, /* core3 raw_pc bit30 */
			{39369,39,1}, /* core3 raw_pc bit31 */
			{39368,39,1}, /* core3 raw_pc bit32 */
			{39367,39,1}, /* core3 raw_pc bit33 */
			{39366,39,1}, /* core3 raw_pc bit34 */
			{39365,39,1}, /* core3 raw_pc bit35 */
			{39364,39,1}, /* core3 raw_pc bit36 */
			{39363,39,1}, /* core3 raw_pc bit37 */
			{39362,39,1}, /* core3 raw_pc bit38 */
			{39361,39,1}, /* core3 raw_pc bit39 */
			{39360,39,1}, /* core3 raw_pc bit40 */
			{39359,39,1}, /* core3 raw_pc bit41 */
			{39358,39,1}, /* core3 raw_pc bit42 */
			{39357,39,1}, /* core3 raw_pc bit43 */
			{39356,39,1}, /* core3 raw_pc bit44 */
			{39355,39,1}, /* core3 raw_pc bit45 */
			{39354,39,1}, /* core3 raw_pc bit46 */
			{38933,40,1}, /* core3 raw_pc bit47 */
			{38932,40,1}, /* core3 raw_pc bit48 */
			{31321,40,1}, /* core3 raw_pc bit49 */
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
			{31564,40,1}, /* core3 pc_iss bit0 */
			{31566,40,1}, /* core3 pc_iss bit1 */
			{38983,40,1}, /* core3 pc_iss bit2 */
			{38982,40,1}, /* core3 pc_iss bit3 */
			{32597,39,1}, /* core3 pc_iss bit4 */
			{32596,39,1}, /* core3 pc_iss bit5 */
			{32595,39,1}, /* core3 pc_iss bit6 */
			{32594,39,1}, /* core3 pc_iss bit7 */
			{31651,40,0}, /* core3 pc_iss bit8 */
			{31556,40,1}, /* core3 pc_iss bit9 */
			{31563,40,1}, /* core3 pc_iss bit10 */
			{31654,40,0}, /* core3 pc_iss bit11 */
			{31559,40,1}, /* core3 pc_iss bit12 */
			{31659,40,0}, /* core3 pc_iss bit13 */
			{31658,40,0}, /* core3 pc_iss bit14 */
			{31655,40,0}, /* core3 pc_iss bit15 */
			{31557,40,1}, /* core3 pc_iss bit16 */
			{31656,40,0}, /* core3 pc_iss bit17 */
			{31657,40,0}, /* core3 pc_iss bit18 */
			{31558,40,1}, /* core3 pc_iss bit19 */
			{32605,39,1}, /* core3 pc_iss bit20 */
			{32604,39,1}, /* core3 pc_iss bit21 */
			{32603,39,1}, /* core3 pc_iss bit22 */
			{32602,39,1}, /* core3 pc_iss bit23 */
			{38985,40,1}, /* core3 pc_iss bit24 */
			{38984,40,1}, /* core3 pc_iss bit25 */
			{31652,40,0}, /* core3 pc_iss bit26 */
			{31555,40,1}, /* core3 pc_iss bit27 */
			{32609,39,1}, /* core3 pc_iss bit28 */
			{32608,39,1}, /* core3 pc_iss bit29 */
			{32607,39,1}, /* core3 pc_iss bit30 */
			{32606,39,1}, /* core3 pc_iss bit31 */
			{31554,40,1}, /* core3 pc_iss bit32 */
			{31553,40,1}, /* core3 pc_iss bit33 */
			{38981,40,1}, /* core3 pc_iss bit34 */
			{38980,40,1}, /* core3 pc_iss bit35 */
			{32613,39,1}, /* core3 pc_iss bit36 */
			{32612,39,1}, /* core3 pc_iss bit37 */
			{32611,39,1}, /* core3 pc_iss bit38 */
			{32610,39,1}, /* core3 pc_iss bit39 */
			{39401,39,1}, /* core3 pc_iss bit40 */
			{39400,39,1}, /* core3 pc_iss bit41 */
			{39399,39,1}, /* core3 pc_iss bit42 */
			{39398,39,1}, /* core3 pc_iss bit43 */
			{39397,39,1}, /* core3 pc_iss bit44 */
			{39396,39,1}, /* core3 pc_iss bit45 */
			{39395,39,1}, /* core3 pc_iss bit46 */
			{39394,39,1}, /* core3 pc_iss bit47 */
			{32593,39,1}, /* core3 pc_iss bit48 */
			{32592,39,1}, /* core3 pc_iss bit49 */
			{32591,39,1}, /* core3 pc_iss bit50 */
			{32590,39,1}, /* core3 pc_iss bit51 */
			{38979,40,1}, /* core3 pc_iss bit52 */
			{38978,40,1}, /* core3 pc_iss bit53 */
			{31455,40,1}, /* core3 pc_iss bit54 */
			{31456,40,1}, /* core3 pc_iss bit55 */
			{31457,40,1}, /* core3 pc_iss bit56 */
			{31454,40,1}, /* core3 pc_iss bit57 */
			{31551,40,1}, /* core3 pc_iss bit58 */
			{31452,40,1}, /* core3 pc_iss bit59 */
			{31552,40,1}, /* core3 pc_iss bit60 */
			{31453,40,1}, /* core3 pc_iss bit61 */
			{38977,40,1}, /* core3 pc_iss bit62 */
			{38976,40,1}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31605,40,0}, /* core3 full_pc_wr bit0 */
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
			{31612,40,0}, /* core3 full_pc_ex1 bit0 */
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
			{32625,39,1}, /* core3 full_pc_ex2 bit0 */
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
			{16480,40,0}, /* core3 return_Stack_pointer bit0 */
			{16473,40,0}, /* core3 return_Stack_pointer bit1 */
			{16474,40,0}, /* core3 return_Stack_pointer bit2 */
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
			{20540,40,0}, /* core3 return_Stack0 bit0 */
			{20539,40,0}, /* core3 return_Stack0 bit1 */
			{20538,40,0}, /* core3 return_Stack0 bit2 */
			{20537,40,0}, /* core3 return_Stack0 bit3 */
			{20536,40,0}, /* core3 return_Stack0 bit4 */
			{20535,40,0}, /* core3 return_Stack0 bit5 */
			{20534,40,0}, /* core3 return_Stack0 bit6 */
			{20568,40,0}, /* core3 return_Stack0 bit7 */
			{20567,40,0}, /* core3 return_Stack0 bit8 */
			{20566,40,0}, /* core3 return_Stack0 bit9 */
			{20565,40,0}, /* core3 return_Stack0 bit10 */
			{20588,40,0}, /* core3 return_Stack0 bit11 */
			{20587,40,0}, /* core3 return_Stack0 bit12 */
			{20586,40,0}, /* core3 return_Stack0 bit13 */
			{20585,40,0}, /* core3 return_Stack0 bit14 */
			{20584,40,0}, /* core3 return_Stack0 bit15 */
			{20583,40,0}, /* core3 return_Stack0 bit16 */
			{20582,40,0}, /* core3 return_Stack0 bit17 */
			{20581,40,0}, /* core3 return_Stack0 bit18 */
			{20612,40,0}, /* core3 return_Stack0 bit19 */
			{20611,40,0}, /* core3 return_Stack0 bit20 */
			{20610,40,0}, /* core3 return_Stack0 bit21 */
			{20609,40,0}, /* core3 return_Stack0 bit22 */
			{20608,40,0}, /* core3 return_Stack0 bit23 */
			{20607,40,0}, /* core3 return_Stack0 bit24 */
			{20606,40,0}, /* core3 return_Stack0 bit25 */
			{20605,40,0}, /* core3 return_Stack0 bit26 */
			{20528,40,0}, /* core3 return_Stack0 bit27 */
			{20527,40,0}, /* core3 return_Stack0 bit28 */
			{20526,40,0}, /* core3 return_Stack0 bit29 */
			{20533,40,0}, /* core3 return_Stack0 bit30 */
			{16458,40,0}, /* core3 return_Stack0 bit31 */
			{20525,40,0}, /* core3 return_Stack0 bit32 */
			{16457,40,0}, /* core3 return_Stack0 bit33 */
			{16460,40,0}, /* core3 return_Stack0 bit34 */
			{16459,40,0}, /* core3 return_Stack0 bit35 */
			{20504,40,0}, /* core3 return_Stack0 bit36 */
			{20503,40,0}, /* core3 return_Stack0 bit37 */
			{20502,40,0}, /* core3 return_Stack0 bit38 */
			{20501,40,0}, /* core3 return_Stack0 bit39 */
			{20500,40,0}, /* core3 return_Stack0 bit40 */
			{20499,40,0}, /* core3 return_Stack0 bit41 */
			{20498,40,0}, /* core3 return_Stack0 bit42 */
			{20497,40,0}, /* core3 return_Stack0 bit43 */
			{20496,40,0}, /* core3 return_Stack0 bit44 */
			{20495,40,0}, /* core3 return_Stack0 bit45 */
			{20494,40,0}, /* core3 return_Stack0 bit46 */
			{20493,40,0}, /* core3 return_Stack0 bit47 */
			{13577,40,1}, /* core3 return_Stack0 bit48 */
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
			{20548,40,0}, /* core3 return_Stack1 bit0 */
			{20547,40,0}, /* core3 return_Stack1 bit1 */
			{20546,40,0}, /* core3 return_Stack1 bit2 */
			{20545,40,0}, /* core3 return_Stack1 bit3 */
			{20552,40,0}, /* core3 return_Stack1 bit4 */
			{20551,40,0}, /* core3 return_Stack1 bit5 */
			{20550,40,0}, /* core3 return_Stack1 bit6 */
			{20564,40,0}, /* core3 return_Stack1 bit7 */
			{20563,40,0}, /* core3 return_Stack1 bit8 */
			{20562,40,0}, /* core3 return_Stack1 bit9 */
			{20561,40,0}, /* core3 return_Stack1 bit10 */
			{20592,40,0}, /* core3 return_Stack1 bit11 */
			{20591,40,0}, /* core3 return_Stack1 bit12 */
			{20590,40,0}, /* core3 return_Stack1 bit13 */
			{20589,40,0}, /* core3 return_Stack1 bit14 */
			{20600,40,0}, /* core3 return_Stack1 bit15 */
			{20599,40,0}, /* core3 return_Stack1 bit16 */
			{20598,40,0}, /* core3 return_Stack1 bit17 */
			{20597,40,0}, /* core3 return_Stack1 bit18 */
			{20580,40,0}, /* core3 return_Stack1 bit19 */
			{20579,40,0}, /* core3 return_Stack1 bit20 */
			{20578,40,0}, /* core3 return_Stack1 bit21 */
			{20577,40,0}, /* core3 return_Stack1 bit22 */
			{20572,40,0}, /* core3 return_Stack1 bit23 */
			{20571,40,0}, /* core3 return_Stack1 bit24 */
			{20570,40,0}, /* core3 return_Stack1 bit25 */
			{20569,40,0}, /* core3 return_Stack1 bit26 */
			{20532,40,0}, /* core3 return_Stack1 bit27 */
			{20531,40,0}, /* core3 return_Stack1 bit28 */
			{20530,40,0}, /* core3 return_Stack1 bit29 */
			{20529,40,0}, /* core3 return_Stack1 bit30 */
			{20549,40,0}, /* core3 return_Stack1 bit31 */
			{13574,40,1}, /* core3 return_Stack1 bit32 */
			{20520,40,0}, /* core3 return_Stack1 bit33 */
			{20519,40,0}, /* core3 return_Stack1 bit34 */
			{20518,40,0}, /* core3 return_Stack1 bit35 */
			{20517,40,0}, /* core3 return_Stack1 bit36 */
			{20516,40,0}, /* core3 return_Stack1 bit37 */
			{20515,40,0}, /* core3 return_Stack1 bit38 */
			{20514,40,0}, /* core3 return_Stack1 bit39 */
			{20513,40,0}, /* core3 return_Stack1 bit40 */
			{20492,40,0}, /* core3 return_Stack1 bit41 */
			{20491,40,0}, /* core3 return_Stack1 bit42 */
			{20490,40,0}, /* core3 return_Stack1 bit43 */
			{20489,40,0}, /* core3 return_Stack1 bit44 */
			{20488,40,0}, /* core3 return_Stack1 bit45 */
			{20487,40,0}, /* core3 return_Stack1 bit46 */
			{20486,40,0}, /* core3 return_Stack1 bit47 */
			{20485,40,0}, /* core3 return_Stack1 bit48 */
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
			{20544,40,0}, /* core3 return_Stack2 bit0 */
			{20543,40,0}, /* core3 return_Stack2 bit1 */
			{20542,40,0}, /* core3 return_Stack2 bit2 */
			{20541,40,0}, /* core3 return_Stack2 bit3 */
			{20556,40,0}, /* core3 return_Stack2 bit4 */
			{20555,40,0}, /* core3 return_Stack2 bit5 */
			{20554,40,0}, /* core3 return_Stack2 bit6 */
			{20553,40,0}, /* core3 return_Stack2 bit7 */
			{20560,40,0}, /* core3 return_Stack2 bit8 */
			{20559,40,0}, /* core3 return_Stack2 bit9 */
			{20558,40,0}, /* core3 return_Stack2 bit10 */
			{20557,40,0}, /* core3 return_Stack2 bit11 */
			{20596,40,0}, /* core3 return_Stack2 bit12 */
			{20595,40,0}, /* core3 return_Stack2 bit13 */
			{16346,40,0}, /* core3 return_Stack2 bit14 */
			{20594,40,0}, /* core3 return_Stack2 bit15 */
			{16345,40,0}, /* core3 return_Stack2 bit16 */
			{20593,40,0}, /* core3 return_Stack2 bit17 */
			{16344,40,0}, /* core3 return_Stack2 bit18 */
			{20576,40,0}, /* core3 return_Stack2 bit19 */
			{20575,40,0}, /* core3 return_Stack2 bit20 */
			{20574,40,0}, /* core3 return_Stack2 bit21 */
			{20573,40,0}, /* core3 return_Stack2 bit22 */
			{20604,40,0}, /* core3 return_Stack2 bit23 */
			{20603,40,0}, /* core3 return_Stack2 bit24 */
			{20602,40,0}, /* core3 return_Stack2 bit25 */
			{20601,40,0}, /* core3 return_Stack2 bit26 */
			{16343,40,0}, /* core3 return_Stack2 bit27 */
			{16512,40,0}, /* core3 return_Stack2 bit28 */
			{16511,40,0}, /* core3 return_Stack2 bit29 */
			{20524,40,0}, /* core3 return_Stack2 bit30 */
			{20523,40,0}, /* core3 return_Stack2 bit31 */
			{13573,40,1}, /* core3 return_Stack2 bit32 */
			{20522,40,0}, /* core3 return_Stack2 bit33 */
			{20521,40,0}, /* core3 return_Stack2 bit34 */
			{20512,40,0}, /* core3 return_Stack2 bit35 */
			{20511,40,0}, /* core3 return_Stack2 bit36 */
			{20510,40,0}, /* core3 return_Stack2 bit37 */
			{20509,40,0}, /* core3 return_Stack2 bit38 */
			{20508,40,0}, /* core3 return_Stack2 bit39 */
			{20507,40,0}, /* core3 return_Stack2 bit40 */
			{20506,40,0}, /* core3 return_Stack2 bit41 */
			{20505,40,0}, /* core3 return_Stack2 bit42 */
			{20460,40,0}, /* core3 return_Stack2 bit43 */
			{20459,40,0}, /* core3 return_Stack2 bit44 */
			{20458,40,0}, /* core3 return_Stack2 bit45 */
			{20457,40,0}, /* core3 return_Stack2 bit46 */
			{13583,40,1}, /* core3 return_Stack2 bit47 */
			{13584,40,1}, /* core3 return_Stack2 bit48 */
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
			{20362,40,0}, /* core3 return_Stack3 bit0 */
			{20361,40,0}, /* core3 return_Stack3 bit1 */
			{20360,40,0}, /* core3 return_Stack3 bit2 */
			{20359,40,0}, /* core3 return_Stack3 bit3 */
			{20270,40,0}, /* core3 return_Stack3 bit4 */
			{20269,40,0}, /* core3 return_Stack3 bit5 */
			{20366,40,0}, /* core3 return_Stack3 bit6 */
			{20268,40,0}, /* core3 return_Stack3 bit7 */
			{20267,40,0}, /* core3 return_Stack3 bit8 */
			{20418,40,0}, /* core3 return_Stack3 bit9 */
			{20417,40,0}, /* core3 return_Stack3 bit10 */
			{20416,40,0}, /* core3 return_Stack3 bit11 */
			{20415,40,0}, /* core3 return_Stack3 bit12 */
			{16362,40,0}, /* core3 return_Stack3 bit13 */
			{16361,40,0}, /* core3 return_Stack3 bit14 */
			{16360,40,0}, /* core3 return_Stack3 bit15 */
			{16359,40,0}, /* core3 return_Stack3 bit16 */
			{16338,40,0}, /* core3 return_Stack3 bit17 */
			{16337,40,0}, /* core3 return_Stack3 bit18 */
			{16340,40,0}, /* core3 return_Stack3 bit19 */
			{16339,40,0}, /* core3 return_Stack3 bit20 */
			{16498,40,0}, /* core3 return_Stack3 bit21 */
			{16497,40,0}, /* core3 return_Stack3 bit22 */
			{16500,40,0}, /* core3 return_Stack3 bit23 */
			{16499,40,0}, /* core3 return_Stack3 bit24 */
			{16504,40,0}, /* core3 return_Stack3 bit25 */
			{16503,40,0}, /* core3 return_Stack3 bit26 */
			{16508,40,0}, /* core3 return_Stack3 bit27 */
			{16507,40,0}, /* core3 return_Stack3 bit28 */
			{16518,40,0}, /* core3 return_Stack3 bit29 */
			{20365,40,0}, /* core3 return_Stack3 bit30 */
			{20364,40,0}, /* core3 return_Stack3 bit31 */
			{16517,40,0}, /* core3 return_Stack3 bit32 */
			{20363,40,0}, /* core3 return_Stack3 bit33 */
			{20310,40,0}, /* core3 return_Stack3 bit34 */
			{20309,40,0}, /* core3 return_Stack3 bit35 */
			{20308,40,0}, /* core3 return_Stack3 bit36 */
			{20307,40,0}, /* core3 return_Stack3 bit37 */
			{20318,40,0}, /* core3 return_Stack3 bit38 */
			{20317,40,0}, /* core3 return_Stack3 bit39 */
			{20316,40,0}, /* core3 return_Stack3 bit40 */
			{20315,40,0}, /* core3 return_Stack3 bit41 */
			{20342,40,0}, /* core3 return_Stack3 bit42 */
			{20341,40,0}, /* core3 return_Stack3 bit43 */
			{20340,40,0}, /* core3 return_Stack3 bit44 */
			{20339,40,0}, /* core3 return_Stack3 bit45 */
			{16440,40,0}, /* core3 return_Stack3 bit46 */
			{16439,40,0}, /* core3 return_Stack3 bit47 */
			{13581,40,1}, /* core3 return_Stack3 bit48 */
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
			{20370,40,0}, /* core3 return_Stack4 bit0 */
			{20369,40,0}, /* core3 return_Stack4 bit1 */
			{20368,40,0}, /* core3 return_Stack4 bit2 */
			{20367,40,0}, /* core3 return_Stack4 bit3 */
			{20374,40,0}, /* core3 return_Stack4 bit4 */
			{20373,40,0}, /* core3 return_Stack4 bit5 */
			{20372,40,0}, /* core3 return_Stack4 bit6 */
			{20371,40,0}, /* core3 return_Stack4 bit7 */
			{20378,40,0}, /* core3 return_Stack4 bit8 */
			{20377,40,0}, /* core3 return_Stack4 bit9 */
			{20376,40,0}, /* core3 return_Stack4 bit10 */
			{20375,40,0}, /* core3 return_Stack4 bit11 */
			{20398,40,0}, /* core3 return_Stack4 bit12 */
			{20397,40,0}, /* core3 return_Stack4 bit13 */
			{20396,40,0}, /* core3 return_Stack4 bit14 */
			{20395,40,0}, /* core3 return_Stack4 bit15 */
			{20394,40,0}, /* core3 return_Stack4 bit16 */
			{20393,40,0}, /* core3 return_Stack4 bit17 */
			{20392,40,0}, /* core3 return_Stack4 bit18 */
			{20391,40,0}, /* core3 return_Stack4 bit19 */
			{20430,40,0}, /* core3 return_Stack4 bit20 */
			{20429,40,0}, /* core3 return_Stack4 bit21 */
			{20428,40,0}, /* core3 return_Stack4 bit22 */
			{20427,40,0}, /* core3 return_Stack4 bit23 */
			{20434,40,0}, /* core3 return_Stack4 bit24 */
			{20433,40,0}, /* core3 return_Stack4 bit25 */
			{20432,40,0}, /* core3 return_Stack4 bit26 */
			{20431,40,0}, /* core3 return_Stack4 bit27 */
			{16506,40,0}, /* core3 return_Stack4 bit28 */
			{16505,40,0}, /* core3 return_Stack4 bit29 */
			{16456,40,0}, /* core3 return_Stack4 bit30 */
			{16455,40,0}, /* core3 return_Stack4 bit31 */
			{16454,40,0}, /* core3 return_Stack4 bit32 */
			{16453,40,0}, /* core3 return_Stack4 bit33 */
			{16446,40,0}, /* core3 return_Stack4 bit34 */
			{20314,40,0}, /* core3 return_Stack4 bit35 */
			{20313,40,0}, /* core3 return_Stack4 bit36 */
			{20312,40,0}, /* core3 return_Stack4 bit37 */
			{20311,40,0}, /* core3 return_Stack4 bit38 */
			{20306,40,0}, /* core3 return_Stack4 bit39 */
			{20305,40,0}, /* core3 return_Stack4 bit40 */
			{20304,40,0}, /* core3 return_Stack4 bit41 */
			{20303,40,0}, /* core3 return_Stack4 bit42 */
			{20298,40,0}, /* core3 return_Stack4 bit43 */
			{20297,40,0}, /* core3 return_Stack4 bit44 */
			{20296,40,0}, /* core3 return_Stack4 bit45 */
			{20295,40,0}, /* core3 return_Stack4 bit46 */
			{16445,40,0}, /* core3 return_Stack4 bit47 */
			{13576,40,1}, /* core3 return_Stack4 bit48 */
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
			{16444,40,0}, /* core3 return_Stack5 bit0 */
			{20262,40,0}, /* core3 return_Stack5 bit1 */
			{16443,40,0}, /* core3 return_Stack5 bit2 */
			{16438,40,0}, /* core3 return_Stack5 bit3 */
			{20261,40,0}, /* core3 return_Stack5 bit4 */
			{20260,40,0}, /* core3 return_Stack5 bit5 */
			{20259,40,0}, /* core3 return_Stack5 bit6 */
			{20266,40,0}, /* core3 return_Stack5 bit7 */
			{20265,40,0}, /* core3 return_Stack5 bit8 */
			{20264,40,0}, /* core3 return_Stack5 bit9 */
			{20263,40,0}, /* core3 return_Stack5 bit10 */
			{16437,40,0}, /* core3 return_Stack5 bit11 */
			{20402,40,0}, /* core3 return_Stack5 bit12 */
			{20401,40,0}, /* core3 return_Stack5 bit13 */
			{20400,40,0}, /* core3 return_Stack5 bit14 */
			{20399,40,0}, /* core3 return_Stack5 bit15 */
			{16364,40,0}, /* core3 return_Stack5 bit16 */
			{16363,40,0}, /* core3 return_Stack5 bit17 */
			{16342,40,0}, /* core3 return_Stack5 bit18 */
			{16341,40,0}, /* core3 return_Stack5 bit19 */
			{20390,40,0}, /* core3 return_Stack5 bit20 */
			{20389,40,0}, /* core3 return_Stack5 bit21 */
			{20388,40,0}, /* core3 return_Stack5 bit22 */
			{20387,40,0}, /* core3 return_Stack5 bit23 */
			{20282,40,0}, /* core3 return_Stack5 bit24 */
			{20281,40,0}, /* core3 return_Stack5 bit25 */
			{20280,40,0}, /* core3 return_Stack5 bit26 */
			{20279,40,0}, /* core3 return_Stack5 bit27 */
			{16514,40,0}, /* core3 return_Stack5 bit28 */
			{16513,40,0}, /* core3 return_Stack5 bit29 */
			{16452,40,0}, /* core3 return_Stack5 bit30 */
			{20286,40,0}, /* core3 return_Stack5 bit31 */
			{16451,40,0}, /* core3 return_Stack5 bit32 */
			{20285,40,0}, /* core3 return_Stack5 bit33 */
			{20284,40,0}, /* core3 return_Stack5 bit34 */
			{20283,40,0}, /* core3 return_Stack5 bit35 */
			{20326,40,0}, /* core3 return_Stack5 bit36 */
			{20325,40,0}, /* core3 return_Stack5 bit37 */
			{20324,40,0}, /* core3 return_Stack5 bit38 */
			{20323,40,0}, /* core3 return_Stack5 bit39 */
			{20338,40,0}, /* core3 return_Stack5 bit40 */
			{20337,40,0}, /* core3 return_Stack5 bit41 */
			{20336,40,0}, /* core3 return_Stack5 bit42 */
			{20335,40,0}, /* core3 return_Stack5 bit43 */
			{20354,40,0}, /* core3 return_Stack5 bit44 */
			{20353,40,0}, /* core3 return_Stack5 bit45 */
			{20352,40,0}, /* core3 return_Stack5 bit46 */
			{20351,40,0}, /* core3 return_Stack5 bit47 */
			{13580,40,1}, /* core3 return_Stack5 bit48 */
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
			{20358,40,0}, /* core3 return_Stack6 bit0 */
			{20357,40,0}, /* core3 return_Stack6 bit1 */
			{20356,40,0}, /* core3 return_Stack6 bit2 */
			{20355,40,0}, /* core3 return_Stack6 bit3 */
			{20258,40,0}, /* core3 return_Stack6 bit4 */
			{20257,40,0}, /* core3 return_Stack6 bit5 */
			{20256,40,0}, /* core3 return_Stack6 bit6 */
			{20255,40,0}, /* core3 return_Stack6 bit7 */
			{16436,40,0}, /* core3 return_Stack6 bit8 */
			{20410,40,0}, /* core3 return_Stack6 bit9 */
			{16435,40,0}, /* core3 return_Stack6 bit10 */
			{20409,40,0}, /* core3 return_Stack6 bit11 */
			{20408,40,0}, /* core3 return_Stack6 bit12 */
			{20407,40,0}, /* core3 return_Stack6 bit13 */
			{16356,40,0}, /* core3 return_Stack6 bit14 */
			{16355,40,0}, /* core3 return_Stack6 bit15 */
			{16358,40,0}, /* core3 return_Stack6 bit16 */
			{16357,40,0}, /* core3 return_Stack6 bit17 */
			{20386,40,0}, /* core3 return_Stack6 bit18 */
			{20385,40,0}, /* core3 return_Stack6 bit19 */
			{20384,40,0}, /* core3 return_Stack6 bit20 */
			{20383,40,0}, /* core3 return_Stack6 bit21 */
			{20382,40,0}, /* core3 return_Stack6 bit22 */
			{20381,40,0}, /* core3 return_Stack6 bit23 */
			{20380,40,0}, /* core3 return_Stack6 bit24 */
			{20379,40,0}, /* core3 return_Stack6 bit25 */
			{20278,40,0}, /* core3 return_Stack6 bit26 */
			{20277,40,0}, /* core3 return_Stack6 bit27 */
			{20276,40,0}, /* core3 return_Stack6 bit28 */
			{20275,40,0}, /* core3 return_Stack6 bit29 */
			{16448,40,0}, /* core3 return_Stack6 bit30 */
			{16447,40,0}, /* core3 return_Stack6 bit31 */
			{16450,40,0}, /* core3 return_Stack6 bit32 */
			{16449,40,0}, /* core3 return_Stack6 bit33 */
			{20302,40,0}, /* core3 return_Stack6 bit34 */
			{20301,40,0}, /* core3 return_Stack6 bit35 */
			{20300,40,0}, /* core3 return_Stack6 bit36 */
			{20299,40,0}, /* core3 return_Stack6 bit37 */
			{20334,40,0}, /* core3 return_Stack6 bit38 */
			{20333,40,0}, /* core3 return_Stack6 bit39 */
			{20332,40,0}, /* core3 return_Stack6 bit40 */
			{20331,40,0}, /* core3 return_Stack6 bit41 */
			{20346,40,0}, /* core3 return_Stack6 bit42 */
			{20345,40,0}, /* core3 return_Stack6 bit43 */
			{20344,40,0}, /* core3 return_Stack6 bit44 */
			{20343,40,0}, /* core3 return_Stack6 bit45 */
			{16442,40,0}, /* core3 return_Stack6 bit46 */
			{16441,40,0}, /* core3 return_Stack6 bit47 */
			{13582,40,1}, /* core3 return_Stack6 bit48 */
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
			{20294,40,0}, /* core3 return_Stack7 bit0 */
			{20293,40,0}, /* core3 return_Stack7 bit1 */
			{20292,40,0}, /* core3 return_Stack7 bit2 */
			{20291,40,0}, /* core3 return_Stack7 bit3 */
			{20274,40,0}, /* core3 return_Stack7 bit4 */
			{20273,40,0}, /* core3 return_Stack7 bit5 */
			{20290,40,0}, /* core3 return_Stack7 bit6 */
			{20272,40,0}, /* core3 return_Stack7 bit7 */
			{20271,40,0}, /* core3 return_Stack7 bit8 */
			{20414,40,0}, /* core3 return_Stack7 bit9 */
			{20413,40,0}, /* core3 return_Stack7 bit10 */
			{20412,40,0}, /* core3 return_Stack7 bit11 */
			{20411,40,0}, /* core3 return_Stack7 bit12 */
			{20406,40,0}, /* core3 return_Stack7 bit13 */
			{20405,40,0}, /* core3 return_Stack7 bit14 */
			{20404,40,0}, /* core3 return_Stack7 bit15 */
			{20403,40,0}, /* core3 return_Stack7 bit16 */
			{20422,40,0}, /* core3 return_Stack7 bit17 */
			{20421,40,0}, /* core3 return_Stack7 bit18 */
			{20426,40,0}, /* core3 return_Stack7 bit19 */
			{20420,40,0}, /* core3 return_Stack7 bit20 */
			{20419,40,0}, /* core3 return_Stack7 bit21 */
			{20425,40,0}, /* core3 return_Stack7 bit22 */
			{20424,40,0}, /* core3 return_Stack7 bit23 */
			{20423,40,0}, /* core3 return_Stack7 bit24 */
			{16502,40,0}, /* core3 return_Stack7 bit25 */
			{16501,40,0}, /* core3 return_Stack7 bit26 */
			{16510,40,0}, /* core3 return_Stack7 bit27 */
			{16509,40,0}, /* core3 return_Stack7 bit28 */
			{16516,40,0}, /* core3 return_Stack7 bit29 */
			{16515,40,0}, /* core3 return_Stack7 bit30 */
			{20289,40,0}, /* core3 return_Stack7 bit31 */
			{13575,40,1}, /* core3 return_Stack7 bit32 */
			{20288,40,0}, /* core3 return_Stack7 bit33 */
			{20287,40,0}, /* core3 return_Stack7 bit34 */
			{20322,40,0}, /* core3 return_Stack7 bit35 */
			{20321,40,0}, /* core3 return_Stack7 bit36 */
			{20320,40,0}, /* core3 return_Stack7 bit37 */
			{20319,40,0}, /* core3 return_Stack7 bit38 */
			{20330,40,0}, /* core3 return_Stack7 bit39 */
			{20329,40,0}, /* core3 return_Stack7 bit40 */
			{20328,40,0}, /* core3 return_Stack7 bit41 */
			{20327,40,0}, /* core3 return_Stack7 bit42 */
			{20350,40,0}, /* core3 return_Stack7 bit43 */
			{20349,40,0}, /* core3 return_Stack7 bit44 */
			{20348,40,0}, /* core3 return_Stack7 bit45 */
			{20347,40,0}, /* core3 return_Stack7 bit46 */
			{13579,40,1}, /* core3 return_Stack7 bit47 */
			{13578,40,1}, /* core3 return_Stack7 bit48 */
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
			.L2_parity_err_count = {{
			{ 6813, 8,0}, /* core3 L2_parity_err_count bit0 */
			{ 6812, 8,0}, /* core3 L2_parity_err_count bit1 */
			{ 6811, 8,0}, /* core3 L2_parity_err_count bit2 */
			{ 6810, 8,0}, /* core3 L2_parity_err_count bit3 */
			{ 6809, 8,0}, /* core3 L2_parity_err_count bit4 */
			{ 6808, 8,0}, /* core3 L2_parity_err_count bit5 */
			{ 6807, 8,0}, /* core3 L2_parity_err_count bit6 */
			{ 6806, 8,0}, /* core3 L2_parity_err_count bit7 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit8 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit9 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit10 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit11 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit12 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit13 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit14 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit15 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit16 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit17 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit18 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit19 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit20 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit21 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit22 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit23 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit24 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit25 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit26 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit27 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit28 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit29 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit30 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit31 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit32 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit33 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit34 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit35 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit36 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit37 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit38 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit39 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit40 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit41 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit42 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit43 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit44 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit45 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit46 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit47 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit48 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit49 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit50 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit51 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit52 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit53 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit54 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit55 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit56 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit57 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit58 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit59 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit60 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit61 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit62 */
			{    0, 0,2}, /* core3 L2_parity_err_count bit63 */
			}},
			.L2_parity_index = {{
			{ 6644, 8,0}, /* core3 L2_parity_index bit0 */
			{ 6643, 8,0}, /* core3 L2_parity_index bit1 */
			{ 6642, 8,0}, /* core3 L2_parity_index bit2 */
			{ 6641, 8,0}, /* core3 L2_parity_index bit3 */
			{ 6640, 8,0}, /* core3 L2_parity_index bit4 */
			{ 6639, 8,0}, /* core3 L2_parity_index bit5 */
			{ 6638, 8,0}, /* core3 L2_parity_index bit6 */
			{ 6637, 8,0}, /* core3 L2_parity_index bit7 */
			{ 6652, 8,0}, /* core3 L2_parity_index bit8 */
			{ 6651, 8,0}, /* core3 L2_parity_index bit9 */
			{ 6650, 8,0}, /* core3 L2_parity_index bit10 */
			{ 6649, 8,0}, /* core3 L2_parity_index bit11 */
			{    0, 0,2}, /* core3 L2_parity_index bit12 */
			{    0, 0,2}, /* core3 L2_parity_index bit13 */
			{    0, 0,2}, /* core3 L2_parity_index bit14 */
			{    0, 0,2}, /* core3 L2_parity_index bit15 */
			{    0, 0,2}, /* core3 L2_parity_index bit16 */
			{    0, 0,2}, /* core3 L2_parity_index bit17 */
			{    0, 0,2}, /* core3 L2_parity_index bit18 */
			{    0, 0,2}, /* core3 L2_parity_index bit19 */
			{    0, 0,2}, /* core3 L2_parity_index bit20 */
			{    0, 0,2}, /* core3 L2_parity_index bit21 */
			{    0, 0,2}, /* core3 L2_parity_index bit22 */
			{    0, 0,2}, /* core3 L2_parity_index bit23 */
			{    0, 0,2}, /* core3 L2_parity_index bit24 */
			{    0, 0,2}, /* core3 L2_parity_index bit25 */
			{    0, 0,2}, /* core3 L2_parity_index bit26 */
			{    0, 0,2}, /* core3 L2_parity_index bit27 */
			{    0, 0,2}, /* core3 L2_parity_index bit28 */
			{    0, 0,2}, /* core3 L2_parity_index bit29 */
			{    0, 0,2}, /* core3 L2_parity_index bit30 */
			{    0, 0,2}, /* core3 L2_parity_index bit31 */
			{    0, 0,2}, /* core3 L2_parity_index bit32 */
			{    0, 0,2}, /* core3 L2_parity_index bit33 */
			{    0, 0,2}, /* core3 L2_parity_index bit34 */
			{    0, 0,2}, /* core3 L2_parity_index bit35 */
			{    0, 0,2}, /* core3 L2_parity_index bit36 */
			{    0, 0,2}, /* core3 L2_parity_index bit37 */
			{    0, 0,2}, /* core3 L2_parity_index bit38 */
			{    0, 0,2}, /* core3 L2_parity_index bit39 */
			{    0, 0,2}, /* core3 L2_parity_index bit40 */
			{    0, 0,2}, /* core3 L2_parity_index bit41 */
			{    0, 0,2}, /* core3 L2_parity_index bit42 */
			{    0, 0,2}, /* core3 L2_parity_index bit43 */
			{    0, 0,2}, /* core3 L2_parity_index bit44 */
			{    0, 0,2}, /* core3 L2_parity_index bit45 */
			{    0, 0,2}, /* core3 L2_parity_index bit46 */
			{    0, 0,2}, /* core3 L2_parity_index bit47 */
			{    0, 0,2}, /* core3 L2_parity_index bit48 */
			{    0, 0,2}, /* core3 L2_parity_index bit49 */
			{    0, 0,2}, /* core3 L2_parity_index bit50 */
			{    0, 0,2}, /* core3 L2_parity_index bit51 */
			{    0, 0,2}, /* core3 L2_parity_index bit52 */
			{    0, 0,2}, /* core3 L2_parity_index bit53 */
			{    0, 0,2}, /* core3 L2_parity_index bit54 */
			{    0, 0,2}, /* core3 L2_parity_index bit55 */
			{    0, 0,2}, /* core3 L2_parity_index bit56 */
			{    0, 0,2}, /* core3 L2_parity_index bit57 */
			{    0, 0,2}, /* core3 L2_parity_index bit58 */
			{    0, 0,2}, /* core3 L2_parity_index bit59 */
			{    0, 0,2}, /* core3 L2_parity_index bit60 */
			{    0, 0,2}, /* core3 L2_parity_index bit61 */
			{    0, 0,2}, /* core3 L2_parity_index bit62 */
			{    0, 0,2}, /* core3 L2_parity_index bit63 */
			}},
			.L2_parity_way = {{
			{ 6645, 8,0}, /* core3 L2_parity_way bit0 */
			{ 6507, 8,0}, /* core3 L2_parity_way bit1 */
			{    0, 0,2}, /* core3 L2_parity_way bit2 */
			{    0, 0,2}, /* core3 L2_parity_way bit3 */
			{    0, 0,2}, /* core3 L2_parity_way bit4 */
			{    0, 0,2}, /* core3 L2_parity_way bit5 */
			{    0, 0,2}, /* core3 L2_parity_way bit6 */
			{    0, 0,2}, /* core3 L2_parity_way bit7 */
			{    0, 0,2}, /* core3 L2_parity_way bit8 */
			{    0, 0,2}, /* core3 L2_parity_way bit9 */
			{    0, 0,2}, /* core3 L2_parity_way bit10 */
			{    0, 0,2}, /* core3 L2_parity_way bit11 */
			{    0, 0,2}, /* core3 L2_parity_way bit12 */
			{    0, 0,2}, /* core3 L2_parity_way bit13 */
			{    0, 0,2}, /* core3 L2_parity_way bit14 */
			{    0, 0,2}, /* core3 L2_parity_way bit15 */
			{    0, 0,2}, /* core3 L2_parity_way bit16 */
			{    0, 0,2}, /* core3 L2_parity_way bit17 */
			{    0, 0,2}, /* core3 L2_parity_way bit18 */
			{    0, 0,2}, /* core3 L2_parity_way bit19 */
			{    0, 0,2}, /* core3 L2_parity_way bit20 */
			{    0, 0,2}, /* core3 L2_parity_way bit21 */
			{    0, 0,2}, /* core3 L2_parity_way bit22 */
			{    0, 0,2}, /* core3 L2_parity_way bit23 */
			{    0, 0,2}, /* core3 L2_parity_way bit24 */
			{    0, 0,2}, /* core3 L2_parity_way bit25 */
			{    0, 0,2}, /* core3 L2_parity_way bit26 */
			{    0, 0,2}, /* core3 L2_parity_way bit27 */
			{    0, 0,2}, /* core3 L2_parity_way bit28 */
			{    0, 0,2}, /* core3 L2_parity_way bit29 */
			{    0, 0,2}, /* core3 L2_parity_way bit30 */
			{    0, 0,2}, /* core3 L2_parity_way bit31 */
			{    0, 0,2}, /* core3 L2_parity_way bit32 */
			{    0, 0,2}, /* core3 L2_parity_way bit33 */
			{    0, 0,2}, /* core3 L2_parity_way bit34 */
			{    0, 0,2}, /* core3 L2_parity_way bit35 */
			{    0, 0,2}, /* core3 L2_parity_way bit36 */
			{    0, 0,2}, /* core3 L2_parity_way bit37 */
			{    0, 0,2}, /* core3 L2_parity_way bit38 */
			{    0, 0,2}, /* core3 L2_parity_way bit39 */
			{    0, 0,2}, /* core3 L2_parity_way bit40 */
			{    0, 0,2}, /* core3 L2_parity_way bit41 */
			{    0, 0,2}, /* core3 L2_parity_way bit42 */
			{    0, 0,2}, /* core3 L2_parity_way bit43 */
			{    0, 0,2}, /* core3 L2_parity_way bit44 */
			{    0, 0,2}, /* core3 L2_parity_way bit45 */
			{    0, 0,2}, /* core3 L2_parity_way bit46 */
			{    0, 0,2}, /* core3 L2_parity_way bit47 */
			{    0, 0,2}, /* core3 L2_parity_way bit48 */
			{    0, 0,2}, /* core3 L2_parity_way bit49 */
			{    0, 0,2}, /* core3 L2_parity_way bit50 */
			{    0, 0,2}, /* core3 L2_parity_way bit51 */
			{    0, 0,2}, /* core3 L2_parity_way bit52 */
			{    0, 0,2}, /* core3 L2_parity_way bit53 */
			{    0, 0,2}, /* core3 L2_parity_way bit54 */
			{    0, 0,2}, /* core3 L2_parity_way bit55 */
			{    0, 0,2}, /* core3 L2_parity_way bit56 */
			{    0, 0,2}, /* core3 L2_parity_way bit57 */
			{    0, 0,2}, /* core3 L2_parity_way bit58 */
			{    0, 0,2}, /* core3 L2_parity_way bit59 */
			{    0, 0,2}, /* core3 L2_parity_way bit60 */
			{    0, 0,2}, /* core3 L2_parity_way bit61 */
			{    0, 0,2}, /* core3 L2_parity_way bit62 */
			{    0, 0,2}, /* core3 L2_parity_way bit63 */
			}},
			.L2_parity_banks = {{
			{ 6821, 8,0}, /* core3 L2_parity_banks bit0 */
			{ 6820, 8,0}, /* core3 L2_parity_banks bit1 */
			{ 6819, 8,0}, /* core3 L2_parity_banks bit2 */
			{ 6818, 8,0}, /* core3 L2_parity_banks bit3 */
			{ 6817, 8,0}, /* core3 L2_parity_banks bit4 */
			{ 6816, 8,0}, /* core3 L2_parity_banks bit5 */
			{ 6815, 8,0}, /* core3 L2_parity_banks bit6 */
			{ 6814, 8,0}, /* core3 L2_parity_banks bit7 */
			{ 6805, 8,0}, /* core3 L2_parity_banks bit8 */
			{ 6804, 8,0}, /* core3 L2_parity_banks bit9 */
			{ 6803, 8,0}, /* core3 L2_parity_banks bit10 */
			{ 6802, 8,0}, /* core3 L2_parity_banks bit11 */
			{ 6801, 8,0}, /* core3 L2_parity_banks bit12 */
			{ 6800, 8,0}, /* core3 L2_parity_banks bit13 */
			{ 6799, 8,0}, /* core3 L2_parity_banks bit14 */
			{ 6798, 8,0}, /* core3 L2_parity_banks bit15 */
			{    0, 0,2}, /* core3 L2_parity_banks bit16 */
			{    0, 0,2}, /* core3 L2_parity_banks bit17 */
			{    0, 0,2}, /* core3 L2_parity_banks bit18 */
			{    0, 0,2}, /* core3 L2_parity_banks bit19 */
			{    0, 0,2}, /* core3 L2_parity_banks bit20 */
			{    0, 0,2}, /* core3 L2_parity_banks bit21 */
			{    0, 0,2}, /* core3 L2_parity_banks bit22 */
			{    0, 0,2}, /* core3 L2_parity_banks bit23 */
			{    0, 0,2}, /* core3 L2_parity_banks bit24 */
			{    0, 0,2}, /* core3 L2_parity_banks bit25 */
			{    0, 0,2}, /* core3 L2_parity_banks bit26 */
			{    0, 0,2}, /* core3 L2_parity_banks bit27 */
			{    0, 0,2}, /* core3 L2_parity_banks bit28 */
			{    0, 0,2}, /* core3 L2_parity_banks bit29 */
			{    0, 0,2}, /* core3 L2_parity_banks bit30 */
			{    0, 0,2}, /* core3 L2_parity_banks bit31 */
			{    0, 0,2}, /* core3 L2_parity_banks bit32 */
			{    0, 0,2}, /* core3 L2_parity_banks bit33 */
			{    0, 0,2}, /* core3 L2_parity_banks bit34 */
			{    0, 0,2}, /* core3 L2_parity_banks bit35 */
			{    0, 0,2}, /* core3 L2_parity_banks bit36 */
			{    0, 0,2}, /* core3 L2_parity_banks bit37 */
			{    0, 0,2}, /* core3 L2_parity_banks bit38 */
			{    0, 0,2}, /* core3 L2_parity_banks bit39 */
			{    0, 0,2}, /* core3 L2_parity_banks bit40 */
			{    0, 0,2}, /* core3 L2_parity_banks bit41 */
			{    0, 0,2}, /* core3 L2_parity_banks bit42 */
			{    0, 0,2}, /* core3 L2_parity_banks bit43 */
			{    0, 0,2}, /* core3 L2_parity_banks bit44 */
			{    0, 0,2}, /* core3 L2_parity_banks bit45 */
			{    0, 0,2}, /* core3 L2_parity_banks bit46 */
			{    0, 0,2}, /* core3 L2_parity_banks bit47 */
			{    0, 0,2}, /* core3 L2_parity_banks bit48 */
			{    0, 0,2}, /* core3 L2_parity_banks bit49 */
			{    0, 0,2}, /* core3 L2_parity_banks bit50 */
			{    0, 0,2}, /* core3 L2_parity_banks bit51 */
			{    0, 0,2}, /* core3 L2_parity_banks bit52 */
			{    0, 0,2}, /* core3 L2_parity_banks bit53 */
			{    0, 0,2}, /* core3 L2_parity_banks bit54 */
			{    0, 0,2}, /* core3 L2_parity_banks bit55 */
			{    0, 0,2}, /* core3 L2_parity_banks bit56 */
			{    0, 0,2}, /* core3 L2_parity_banks bit57 */
			{    0, 0,2}, /* core3 L2_parity_banks bit58 */
			{    0, 0,2}, /* core3 L2_parity_banks bit59 */
			{    0, 0,2}, /* core3 L2_parity_banks bit60 */
			{    0, 0,2}, /* core3 L2_parity_banks bit61 */
			{    0, 0,2}, /* core3 L2_parity_banks bit62 */
			{    0, 0,2}, /* core3 L2_parity_banks bit63 */
			}},
	},
	{		/* core 4 */ 
			.pc = {{
			{  392,41,1}, /* core4 pc bit0 */
			{  391,41,1}, /* core4 pc bit1 */
			{  390,41,1}, /* core4 pc bit2 */
			{  389,41,1}, /* core4 pc bit3 */
			{  440,41,1}, /* core4 pc bit4 */
			{  416,41,1}, /* core4 pc bit5 */
			{  439,41,1}, /* core4 pc bit6 */
			{  415,41,1}, /* core4 pc bit7 */
			{  388,41,1}, /* core4 pc bit8 */
			{  414,41,1}, /* core4 pc bit9 */
			{  344,41,1}, /* core4 pc bit10 */
			{  360,41,1}, /* core4 pc bit11 */
			{  359,41,1}, /* core4 pc bit12 */
			{  358,41,1}, /* core4 pc bit13 */
			{  343,41,1}, /* core4 pc bit14 */
			{  342,41,1}, /* core4 pc bit15 */
			{  413,41,1}, /* core4 pc bit16 */
			{  296,41,1}, /* core4 pc bit17 */
			{  357,41,1}, /* core4 pc bit18 */
			{  387,41,1}, /* core4 pc bit19 */
			{  356,41,1}, /* core4 pc bit20 */
			{  355,41,1}, /* core4 pc bit21 */
			{  412,41,1}, /* core4 pc bit22 */
			{  354,41,1}, /* core4 pc bit23 */
			{  353,41,1}, /* core4 pc bit24 */
			{  376,41,1}, /* core4 pc bit25 */
			{  352,41,1}, /* core4 pc bit26 */
			{  295,41,1}, /* core4 pc bit27 */
			{  386,41,1}, /* core4 pc bit28 */
			{  341,41,1}, /* core4 pc bit29 */
			{  385,41,1}, /* core4 pc bit30 */
			{  351,41,1}, /* core4 pc bit31 */
			{  264,41,1}, /* core4 pc bit32 */
			{  112,41,1}, /* core4 pc bit33 */
			{  263,41,1}, /* core4 pc bit34 */
			{  111,41,1}, /* core4 pc bit35 */
			{  172,41,1}, /* core4 pc bit36 */
			{  180,41,1}, /* core4 pc bit37 */
			{  262,41,1}, /* core4 pc bit38 */
			{  146,41,1}, /* core4 pc bit39 */
			{  179,41,1}, /* core4 pc bit40 */
			{  145,41,1}, /* core4 pc bit41 */
			{  136,41,1}, /* core4 pc bit42 */
			{  261,41,1}, /* core4 pc bit43 */
			{  260,41,1}, /* core4 pc bit44 */
			{  259,41,1}, /* core4 pc bit45 */
			{  144,41,1}, /* core4 pc bit46 */
			{  143,41,1}, /* core4 pc bit47 */
			{  438,41,1}, /* core4 pc bit48 */
			{  110,41,1}, /* core4 pc bit49 */
			{  207,41,1}, /* core4 pc bit50 */
			{  206,41,1}, /* core4 pc bit51 */
			{  411,41,1}, /* core4 pc bit52 */
			{  205,41,1}, /* core4 pc bit53 */
			{  109,41,1}, /* core4 pc bit54 */
			{  204,41,1}, /* core4 pc bit55 */
			{  258,41,1}, /* core4 pc bit56 */
			{  203,41,1}, /* core4 pc bit57 */
			{  178,41,1}, /* core4 pc bit58 */
			{  177,41,1}, /* core4 pc bit59 */
			{  202,41,1}, /* core4 pc bit60 */
			{  201,41,1}, /* core4 pc bit61 */
			{  200,41,1}, /* core4 pc bit62 */
			{  257,41,1}, /* core4 pc bit63 */
			}},
			.sp32 = {{
			{37603,42,0}, /* core4 sp32 bit0 */
			{37602,42,0}, /* core4 sp32 bit1 */
			{28162,42,1}, /* core4 sp32 bit2 */
			{28161,42,1}, /* core4 sp32 bit3 */
			{28160,42,1}, /* core4 sp32 bit4 */
			{28092,42,1}, /* core4 sp32 bit5 */
			{28159,42,1}, /* core4 sp32 bit6 */
			{28091,42,1}, /* core4 sp32 bit7 */
			{37601,42,0}, /* core4 sp32 bit8 */
			{37600,42,0}, /* core4 sp32 bit9 */
			{28158,42,1}, /* core4 sp32 bit10 */
			{28151,42,1}, /* core4 sp32 bit11 */
			{37583,42,0}, /* core4 sp32 bit12 */
			{37582,42,0}, /* core4 sp32 bit13 */
			{37581,42,0}, /* core4 sp32 bit14 */
			{37580,42,0}, /* core4 sp32 bit15 */
			{28135,42,1}, /* core4 sp32 bit16 */
			{28150,42,1}, /* core4 sp32 bit17 */
			{28131,42,1}, /* core4 sp32 bit18 */
			{28132,42,1}, /* core4 sp32 bit19 */
			{28144,42,1}, /* core4 sp32 bit20 */
			{28133,42,1}, /* core4 sp32 bit21 */
			{31013,41,1}, /* core4 sp32 bit22 */
			{31012,41,1}, /* core4 sp32 bit23 */
			{28130,42,1}, /* core4 sp32 bit24 */
			{28134,42,1}, /* core4 sp32 bit25 */
			{31011,41,1}, /* core4 sp32 bit26 */
			{31010,41,1}, /* core4 sp32 bit27 */
			{37579,42,0}, /* core4 sp32 bit28 */
			{37578,42,0}, /* core4 sp32 bit29 */
			{37593,42,0}, /* core4 sp32 bit30 */
			{37592,42,0}, /* core4 sp32 bit31 */
			{30913,41,1}, /* core4 sp32 bit32 */
			{30912,41,1}, /* core4 sp32 bit33 */
			{30911,41,1}, /* core4 sp32 bit34 */
			{30910,41,1}, /* core4 sp32 bit35 */
			{37623,42,0}, /* core4 sp32 bit36 */
			{37622,42,0}, /* core4 sp32 bit37 */
			{28277,42,1}, /* core4 sp32 bit38 */
			{37709,42,0}, /* core4 sp32 bit39 */
			{28274,42,1}, /* core4 sp32 bit40 */
			{37611,42,0}, /* core4 sp32 bit41 */
			{37625,42,0}, /* core4 sp32 bit42 */
			{37624,42,0}, /* core4 sp32 bit43 */
			{37708,42,0}, /* core4 sp32 bit44 */
			{37711,42,0}, /* core4 sp32 bit45 */
			{37610,42,0}, /* core4 sp32 bit46 */
			{37710,42,0}, /* core4 sp32 bit47 */
			{28278,42,1}, /* core4 sp32 bit48 */
			{28300,42,1}, /* core4 sp32 bit49 */
			{28296,42,1}, /* core4 sp32 bit50 */
			{28302,42,1}, /* core4 sp32 bit51 */
			{28283,42,1}, /* core4 sp32 bit52 */
			{28170,42,1}, /* core4 sp32 bit53 */
			{28281,42,1}, /* core4 sp32 bit54 */
			{28310,42,1}, /* core4 sp32 bit55 */
			{28279,42,1}, /* core4 sp32 bit56 */
			{28301,42,1}, /* core4 sp32 bit57 */
			{28169,42,1}, /* core4 sp32 bit58 */
			{28303,42,1}, /* core4 sp32 bit59 */
			{28171,42,1}, /* core4 sp32 bit60 */
			{28168,42,1}, /* core4 sp32 bit61 */
			{28295,42,1}, /* core4 sp32 bit62 */
			{28297,42,1}, /* core4 sp32 bit63 */
			}},
			.fp32 = {{
			{28348,42,1}, /* core4 fp32 bit0 */
			{28349,42,1}, /* core4 fp32 bit1 */
			{37719,42,0}, /* core4 fp32 bit2 */
			{37718,42,0}, /* core4 fp32 bit3 */
			{37721,42,0}, /* core4 fp32 bit4 */
			{37720,42,0}, /* core4 fp32 bit5 */
			{28353,42,1}, /* core4 fp32 bit6 */
			{28351,42,1}, /* core4 fp32 bit7 */
			{28352,42,1}, /* core4 fp32 bit8 */
			{28350,42,1}, /* core4 fp32 bit9 */
			{37751,42,0}, /* core4 fp32 bit10 */
			{37750,42,0}, /* core4 fp32 bit11 */
			{37747,42,0}, /* core4 fp32 bit12 */
			{37746,42,0}, /* core4 fp32 bit13 */
			{31129,41,1}, /* core4 fp32 bit14 */
			{31128,41,1}, /* core4 fp32 bit15 */
			{31127,41,1}, /* core4 fp32 bit16 */
			{31126,41,1}, /* core4 fp32 bit17 */
			{37745,42,0}, /* core4 fp32 bit18 */
			{37744,42,0}, /* core4 fp32 bit19 */
			{31125,41,1}, /* core4 fp32 bit20 */
			{31124,41,1}, /* core4 fp32 bit21 */
			{28375,42,1}, /* core4 fp32 bit22 */
			{31123,41,1}, /* core4 fp32 bit23 */
			{31122,41,1}, /* core4 fp32 bit24 */
			{31121,41,1}, /* core4 fp32 bit25 */
			{31120,41,1}, /* core4 fp32 bit26 */
			{31119,41,1}, /* core4 fp32 bit27 */
			{31118,41,1}, /* core4 fp32 bit28 */
			{28374,42,1}, /* core4 fp32 bit29 */
			{37749,42,0}, /* core4 fp32 bit30 */
			{37748,42,0}, /* core4 fp32 bit31 */
			{37833,41,1}, /* core4 fp32 bit32 */
			{37832,41,1}, /* core4 fp32 bit33 */
			{37831,41,1}, /* core4 fp32 bit34 */
			{37830,41,1}, /* core4 fp32 bit35 */
			{28509,42,1}, /* core4 fp32 bit36 */
			{28510,42,1}, /* core4 fp32 bit37 */
			{37645,42,0}, /* core4 fp32 bit38 */
			{37829,41,1}, /* core4 fp32 bit39 */
			{37828,41,1}, /* core4 fp32 bit40 */
			{37644,42,0}, /* core4 fp32 bit41 */
			{37827,41,1}, /* core4 fp32 bit42 */
			{37641,42,0}, /* core4 fp32 bit43 */
			{37640,42,0}, /* core4 fp32 bit44 */
			{28508,42,1}, /* core4 fp32 bit45 */
			{28507,42,1}, /* core4 fp32 bit46 */
			{37643,42,0}, /* core4 fp32 bit47 */
			{37642,42,0}, /* core4 fp32 bit48 */
			{28511,42,1}, /* core4 fp32 bit49 */
			{28486,42,1}, /* core4 fp32 bit50 */
			{37826,41,1}, /* core4 fp32 bit51 */
			{28476,42,1}, /* core4 fp32 bit52 */
			{28472,42,1}, /* core4 fp32 bit53 */
			{28475,42,1}, /* core4 fp32 bit54 */
			{28489,42,1}, /* core4 fp32 bit55 */
			{28474,42,1}, /* core4 fp32 bit56 */
			{28453,42,1}, /* core4 fp32 bit57 */
			{28484,42,1}, /* core4 fp32 bit58 */
			{28454,42,1}, /* core4 fp32 bit59 */
			{28487,42,1}, /* core4 fp32 bit60 */
			{28488,42,1}, /* core4 fp32 bit61 */
			{28485,42,1}, /* core4 fp32 bit62 */
			{28473,42,1}, /* core4 fp32 bit63 */
			}},
			.fp64 = {{
			{28058,42,1}, /* core4 fp64 bit0 */
			{28057,42,1}, /* core4 fp64 bit1 */
			{28059,42,1}, /* core4 fp64 bit2 */
			{28054,42,1}, /* core4 fp64 bit3 */
			{31029,41,1}, /* core4 fp64 bit4 */
			{31028,41,1}, /* core4 fp64 bit5 */
			{31027,41,1}, /* core4 fp64 bit6 */
			{31026,41,1}, /* core4 fp64 bit7 */
			{28056,42,1}, /* core4 fp64 bit8 */
			{28055,42,1}, /* core4 fp64 bit9 */
			{37529,41,1}, /* core4 fp64 bit10 */
			{28060,42,1}, /* core4 fp64 bit11 */
			{27855,42,1}, /* core4 fp64 bit12 */
			{37528,41,1}, /* core4 fp64 bit13 */
			{37527,41,1}, /* core4 fp64 bit14 */
			{37526,41,1}, /* core4 fp64 bit15 */
			{30993,41,1}, /* core4 fp64 bit16 */
			{30992,41,1}, /* core4 fp64 bit17 */
			{37525,41,1}, /* core4 fp64 bit18 */
			{37524,41,1}, /* core4 fp64 bit19 */
			{37523,41,1}, /* core4 fp64 bit20 */
			{37522,41,1}, /* core4 fp64 bit21 */
			{30991,41,1}, /* core4 fp64 bit22 */
			{30990,41,1}, /* core4 fp64 bit23 */
			{27845,42,1}, /* core4 fp64 bit24 */
			{27843,42,1}, /* core4 fp64 bit25 */
			{27844,42,1}, /* core4 fp64 bit26 */
			{27842,42,1}, /* core4 fp64 bit27 */
			{37481,42,0}, /* core4 fp64 bit28 */
			{37480,42,0}, /* core4 fp64 bit29 */
			{37487,42,0}, /* core4 fp64 bit30 */
			{37486,42,0}, /* core4 fp64 bit31 */
			{30825,41,1}, /* core4 fp64 bit32 */
			{30837,41,1}, /* core4 fp64 bit33 */
			{30836,41,1}, /* core4 fp64 bit34 */
			{30835,41,1}, /* core4 fp64 bit35 */
			{30834,41,1}, /* core4 fp64 bit36 */
			{30824,41,1}, /* core4 fp64 bit37 */
			{30823,41,1}, /* core4 fp64 bit38 */
			{30822,41,1}, /* core4 fp64 bit39 */
			{27896,42,1}, /* core4 fp64 bit40 */
			{27982,42,1}, /* core4 fp64 bit41 */
			{37325,42,0}, /* core4 fp64 bit42 */
			{37324,42,0}, /* core4 fp64 bit43 */
			{30821,41,1}, /* core4 fp64 bit44 */
			{30820,41,1}, /* core4 fp64 bit45 */
			{27894,42,1}, /* core4 fp64 bit46 */
			{30819,41,1}, /* core4 fp64 bit47 */
			{27895,42,1}, /* core4 fp64 bit48 */
			{30818,41,1}, /* core4 fp64 bit49 */
			{30833,41,1}, /* core4 fp64 bit50 */
			{30832,41,1}, /* core4 fp64 bit51 */
			{30831,41,1}, /* core4 fp64 bit52 */
			{30830,41,1}, /* core4 fp64 bit53 */
			{30841,41,1}, /* core4 fp64 bit54 */
			{27983,42,1}, /* core4 fp64 bit55 */
			{30840,41,1}, /* core4 fp64 bit56 */
			{30839,41,1}, /* core4 fp64 bit57 */
			{27984,42,1}, /* core4 fp64 bit58 */
			{30838,41,1}, /* core4 fp64 bit59 */
			{30829,41,1}, /* core4 fp64 bit60 */
			{30828,41,1}, /* core4 fp64 bit61 */
			{30827,41,1}, /* core4 fp64 bit62 */
			{30826,41,1}, /* core4 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{28040,42,1}, /* core4 sp_EL0 bit0 */
			{28038,42,1}, /* core4 sp_EL0 bit1 */
			{28039,42,1}, /* core4 sp_EL0 bit2 */
			{28035,42,1}, /* core4 sp_EL0 bit3 */
			{28037,42,1}, /* core4 sp_EL0 bit4 */
			{28036,42,1}, /* core4 sp_EL0 bit5 */
			{37399,42,0}, /* core4 sp_EL0 bit6 */
			{37398,42,0}, /* core4 sp_EL0 bit7 */
			{37397,42,0}, /* core4 sp_EL0 bit8 */
			{37396,42,0}, /* core4 sp_EL0 bit9 */
			{27861,42,1}, /* core4 sp_EL0 bit10 */
			{28029,42,1}, /* core4 sp_EL0 bit11 */
			{27859,42,1}, /* core4 sp_EL0 bit12 */
			{27851,42,1}, /* core4 sp_EL0 bit13 */
			{37467,42,0}, /* core4 sp_EL0 bit14 */
			{37466,42,0}, /* core4 sp_EL0 bit15 */
			{27858,42,1}, /* core4 sp_EL0 bit16 */
			{27860,42,1}, /* core4 sp_EL0 bit17 */
			{37479,42,0}, /* core4 sp_EL0 bit18 */
			{37478,42,0}, /* core4 sp_EL0 bit19 */
			{37475,42,0}, /* core4 sp_EL0 bit20 */
			{37474,42,0}, /* core4 sp_EL0 bit21 */
			{37471,42,0}, /* core4 sp_EL0 bit22 */
			{37470,42,0}, /* core4 sp_EL0 bit23 */
			{30989,41,1}, /* core4 sp_EL0 bit24 */
			{30988,41,1}, /* core4 sp_EL0 bit25 */
			{30987,41,1}, /* core4 sp_EL0 bit26 */
			{30986,41,1}, /* core4 sp_EL0 bit27 */
			{37477,42,0}, /* core4 sp_EL0 bit28 */
			{37476,42,0}, /* core4 sp_EL0 bit29 */
			{27841,42,1}, /* core4 sp_EL0 bit30 */
			{28041,42,1}, /* core4 sp_EL0 bit31 */
			{37287,42,0}, /* core4 sp_EL0 bit32 */
			{37577,41,1}, /* core4 sp_EL0 bit33 */
			{37576,41,1}, /* core4 sp_EL0 bit34 */
			{37575,41,1}, /* core4 sp_EL0 bit35 */
			{37574,41,1}, /* core4 sp_EL0 bit36 */
			{37573,41,1}, /* core4 sp_EL0 bit37 */
			{37572,41,1}, /* core4 sp_EL0 bit38 */
			{37286,42,0}, /* core4 sp_EL0 bit39 */
			{37571,41,1}, /* core4 sp_EL0 bit40 */
			{37570,41,1}, /* core4 sp_EL0 bit41 */
			{37367,42,0}, /* core4 sp_EL0 bit42 */
			{37366,42,0}, /* core4 sp_EL0 bit43 */
			{37285,42,0}, /* core4 sp_EL0 bit44 */
			{37284,42,0}, /* core4 sp_EL0 bit45 */
			{27962,42,1}, /* core4 sp_EL0 bit46 */
			{27934,42,1}, /* core4 sp_EL0 bit47 */
			{37269,42,0}, /* core4 sp_EL0 bit48 */
			{37268,42,0}, /* core4 sp_EL0 bit49 */
			{37283,42,0}, /* core4 sp_EL0 bit50 */
			{37282,42,0}, /* core4 sp_EL0 bit51 */
			{37273,42,0}, /* core4 sp_EL0 bit52 */
			{37272,42,0}, /* core4 sp_EL0 bit53 */
			{37267,42,0}, /* core4 sp_EL0 bit54 */
			{37266,42,0}, /* core4 sp_EL0 bit55 */
			{37265,42,0}, /* core4 sp_EL0 bit56 */
			{37264,42,0}, /* core4 sp_EL0 bit57 */
			{30813,41,1}, /* core4 sp_EL0 bit58 */
			{30812,41,1}, /* core4 sp_EL0 bit59 */
			{37271,42,0}, /* core4 sp_EL0 bit60 */
			{37270,42,0}, /* core4 sp_EL0 bit61 */
			{30811,41,1}, /* core4 sp_EL0 bit62 */
			{30810,41,1}, /* core4 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{28034,42,1}, /* core4 sp_EL1 bit0 */
			{27881,42,1}, /* core4 sp_EL1 bit1 */
			{37395,42,0}, /* core4 sp_EL1 bit2 */
			{37394,42,0}, /* core4 sp_EL1 bit3 */
			{28032,42,1}, /* core4 sp_EL1 bit4 */
			{28033,42,1}, /* core4 sp_EL1 bit5 */
			{37393,42,0}, /* core4 sp_EL1 bit6 */
			{37392,42,0}, /* core4 sp_EL1 bit7 */
			{30569,41,1}, /* core4 sp_EL1 bit8 */
			{30568,41,1}, /* core4 sp_EL1 bit9 */
			{37465,42,0}, /* core4 sp_EL1 bit10 */
			{30567,41,1}, /* core4 sp_EL1 bit11 */
			{30566,41,1}, /* core4 sp_EL1 bit12 */
			{37464,42,0}, /* core4 sp_EL1 bit13 */
			{27863,42,1}, /* core4 sp_EL1 bit14 */
			{27864,42,1}, /* core4 sp_EL1 bit15 */
			{28030,42,1}, /* core4 sp_EL1 bit16 */
			{27862,42,1}, /* core4 sp_EL1 bit17 */
			{27836,42,1}, /* core4 sp_EL1 bit18 */
			{27839,42,1}, /* core4 sp_EL1 bit19 */
			{27838,42,1}, /* core4 sp_EL1 bit20 */
			{27837,42,1}, /* core4 sp_EL1 bit21 */
			{37493,42,0}, /* core4 sp_EL1 bit22 */
			{30597,41,1}, /* core4 sp_EL1 bit23 */
			{30596,41,1}, /* core4 sp_EL1 bit24 */
			{30595,41,1}, /* core4 sp_EL1 bit25 */
			{30594,41,1}, /* core4 sp_EL1 bit26 */
			{37492,42,0}, /* core4 sp_EL1 bit27 */
			{37495,42,0}, /* core4 sp_EL1 bit28 */
			{37494,42,0}, /* core4 sp_EL1 bit29 */
			{27840,42,1}, /* core4 sp_EL1 bit30 */
			{28031,42,1}, /* core4 sp_EL1 bit31 */
			{27935,42,1}, /* core4 sp_EL1 bit32 */
			{27963,42,1}, /* core4 sp_EL1 bit33 */
			{37365,42,0}, /* core4 sp_EL1 bit34 */
			{37364,42,0}, /* core4 sp_EL1 bit35 */
			{37363,42,0}, /* core4 sp_EL1 bit36 */
			{37362,42,0}, /* core4 sp_EL1 bit37 */
			{27966,42,1}, /* core4 sp_EL1 bit38 */
			{27931,42,1}, /* core4 sp_EL1 bit39 */
			{30653,41,1}, /* core4 sp_EL1 bit40 */
			{30652,41,1}, /* core4 sp_EL1 bit41 */
			{30651,41,1}, /* core4 sp_EL1 bit42 */
			{30650,41,1}, /* core4 sp_EL1 bit43 */
			{37279,42,0}, /* core4 sp_EL1 bit44 */
			{37278,42,0}, /* core4 sp_EL1 bit45 */
			{27964,42,1}, /* core4 sp_EL1 bit46 */
			{27933,42,1}, /* core4 sp_EL1 bit47 */
			{27932,42,1}, /* core4 sp_EL1 bit48 */
			{27965,42,1}, /* core4 sp_EL1 bit49 */
			{37281,42,0}, /* core4 sp_EL1 bit50 */
			{37280,42,0}, /* core4 sp_EL1 bit51 */
			{37275,42,0}, /* core4 sp_EL1 bit52 */
			{37274,42,0}, /* core4 sp_EL1 bit53 */
			{37263,42,0}, /* core4 sp_EL1 bit54 */
			{37262,42,0}, /* core4 sp_EL1 bit55 */
			{37261,42,0}, /* core4 sp_EL1 bit56 */
			{37260,42,0}, /* core4 sp_EL1 bit57 */
			{37349,42,0}, /* core4 sp_EL1 bit58 */
			{37348,42,0}, /* core4 sp_EL1 bit59 */
			{37353,42,0}, /* core4 sp_EL1 bit60 */
			{37352,42,0}, /* core4 sp_EL1 bit61 */
			{37277,42,0}, /* core4 sp_EL1 bit62 */
			{37276,42,0}, /* core4 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{28047,42,1}, /* core4 sp_EL2 bit0 */
			{28053,42,1}, /* core4 sp_EL2 bit1 */
			{28052,42,1}, /* core4 sp_EL2 bit2 */
			{28049,42,1}, /* core4 sp_EL2 bit3 */
			{28051,42,1}, /* core4 sp_EL2 bit4 */
			{28050,42,1}, /* core4 sp_EL2 bit5 */
			{28028,42,1}, /* core4 sp_EL2 bit6 */
			{28026,42,1}, /* core4 sp_EL2 bit7 */
			{28027,42,1}, /* core4 sp_EL2 bit8 */
			{28048,42,1}, /* core4 sp_EL2 bit9 */
			{27856,42,1}, /* core4 sp_EL2 bit10 */
			{28061,42,1}, /* core4 sp_EL2 bit11 */
			{27857,42,1}, /* core4 sp_EL2 bit12 */
			{27847,42,1}, /* core4 sp_EL2 bit13 */
			{27854,42,1}, /* core4 sp_EL2 bit14 */
			{37459,42,0}, /* core4 sp_EL2 bit15 */
			{37458,42,0}, /* core4 sp_EL2 bit16 */
			{27853,42,1}, /* core4 sp_EL2 bit17 */
			{37461,42,0}, /* core4 sp_EL2 bit18 */
			{37460,42,0}, /* core4 sp_EL2 bit19 */
			{27852,42,1}, /* core4 sp_EL2 bit20 */
			{27846,42,1}, /* core4 sp_EL2 bit21 */
			{30585,41,1}, /* core4 sp_EL2 bit22 */
			{30589,41,1}, /* core4 sp_EL2 bit23 */
			{30588,41,1}, /* core4 sp_EL2 bit24 */
			{30587,41,1}, /* core4 sp_EL2 bit25 */
			{30584,41,1}, /* core4 sp_EL2 bit26 */
			{30586,41,1}, /* core4 sp_EL2 bit27 */
			{30583,41,1}, /* core4 sp_EL2 bit28 */
			{37489,42,0}, /* core4 sp_EL2 bit29 */
			{37488,42,0}, /* core4 sp_EL2 bit30 */
			{30582,41,1}, /* core4 sp_EL2 bit31 */
			{37601,41,1}, /* core4 sp_EL2 bit32 */
			{30649,41,1}, /* core4 sp_EL2 bit33 */
			{30648,41,1}, /* core4 sp_EL2 bit34 */
			{30647,41,1}, /* core4 sp_EL2 bit35 */
			{30646,41,1}, /* core4 sp_EL2 bit36 */
			{37359,42,0}, /* core4 sp_EL2 bit37 */
			{37358,42,0}, /* core4 sp_EL2 bit38 */
			{37600,41,1}, /* core4 sp_EL2 bit39 */
			{37361,42,0}, /* core4 sp_EL2 bit40 */
			{37360,42,0}, /* core4 sp_EL2 bit41 */
			{30645,41,1}, /* core4 sp_EL2 bit42 */
			{30644,41,1}, /* core4 sp_EL2 bit43 */
			{37599,41,1}, /* core4 sp_EL2 bit44 */
			{37598,41,1}, /* core4 sp_EL2 bit45 */
			{30643,41,1}, /* core4 sp_EL2 bit46 */
			{37597,41,1}, /* core4 sp_EL2 bit47 */
			{37596,41,1}, /* core4 sp_EL2 bit48 */
			{30642,41,1}, /* core4 sp_EL2 bit49 */
			{37595,41,1}, /* core4 sp_EL2 bit50 */
			{37594,41,1}, /* core4 sp_EL2 bit51 */
			{37593,41,1}, /* core4 sp_EL2 bit52 */
			{37592,41,1}, /* core4 sp_EL2 bit53 */
			{27970,42,1}, /* core4 sp_EL2 bit54 */
			{37591,41,1}, /* core4 sp_EL2 bit55 */
			{27971,42,1}, /* core4 sp_EL2 bit56 */
			{37355,42,0}, /* core4 sp_EL2 bit57 */
			{37590,41,1}, /* core4 sp_EL2 bit58 */
			{37589,41,1}, /* core4 sp_EL2 bit59 */
			{37588,41,1}, /* core4 sp_EL2 bit60 */
			{37587,41,1}, /* core4 sp_EL2 bit61 */
			{37354,42,0}, /* core4 sp_EL2 bit62 */
			{37586,41,1}, /* core4 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{28045,42,1}, /* core4 sp_EL3 bit0 */
			{28046,42,1}, /* core4 sp_EL3 bit1 */
			{28044,42,1}, /* core4 sp_EL3 bit2 */
			{28043,42,1}, /* core4 sp_EL3 bit3 */
			{30573,41,1}, /* core4 sp_EL3 bit4 */
			{30572,41,1}, /* core4 sp_EL3 bit5 */
			{30571,41,1}, /* core4 sp_EL3 bit6 */
			{30570,41,1}, /* core4 sp_EL3 bit7 */
			{30577,41,1}, /* core4 sp_EL3 bit8 */
			{30576,41,1}, /* core4 sp_EL3 bit9 */
			{30575,41,1}, /* core4 sp_EL3 bit10 */
			{30574,41,1}, /* core4 sp_EL3 bit11 */
			{30581,41,1}, /* core4 sp_EL3 bit12 */
			{30580,41,1}, /* core4 sp_EL3 bit13 */
			{30579,41,1}, /* core4 sp_EL3 bit14 */
			{30578,41,1}, /* core4 sp_EL3 bit15 */
			{37463,42,0}, /* core4 sp_EL3 bit16 */
			{37462,42,0}, /* core4 sp_EL3 bit17 */
			{37473,42,0}, /* core4 sp_EL3 bit18 */
			{37472,42,0}, /* core4 sp_EL3 bit19 */
			{27850,42,1}, /* core4 sp_EL3 bit20 */
			{27848,42,1}, /* core4 sp_EL3 bit21 */
			{37469,42,0}, /* core4 sp_EL3 bit22 */
			{37468,42,0}, /* core4 sp_EL3 bit23 */
			{30593,41,1}, /* core4 sp_EL3 bit24 */
			{30592,41,1}, /* core4 sp_EL3 bit25 */
			{30591,41,1}, /* core4 sp_EL3 bit26 */
			{30590,41,1}, /* core4 sp_EL3 bit27 */
			{37491,42,0}, /* core4 sp_EL3 bit28 */
			{37490,42,0}, /* core4 sp_EL3 bit29 */
			{27849,42,1}, /* core4 sp_EL3 bit30 */
			{28042,42,1}, /* core4 sp_EL3 bit31 */
			{37289,42,0}, /* core4 sp_EL3 bit32 */
			{37585,41,1}, /* core4 sp_EL3 bit33 */
			{37584,41,1}, /* core4 sp_EL3 bit34 */
			{37583,41,1}, /* core4 sp_EL3 bit35 */
			{37582,41,1}, /* core4 sp_EL3 bit36 */
			{37581,41,1}, /* core4 sp_EL3 bit37 */
			{37580,41,1}, /* core4 sp_EL3 bit38 */
			{37288,42,0}, /* core4 sp_EL3 bit39 */
			{37579,41,1}, /* core4 sp_EL3 bit40 */
			{37578,41,1}, /* core4 sp_EL3 bit41 */
			{37357,42,0}, /* core4 sp_EL3 bit42 */
			{37356,42,0}, /* core4 sp_EL3 bit43 */
			{37347,42,0}, /* core4 sp_EL3 bit44 */
			{37346,42,0}, /* core4 sp_EL3 bit45 */
			{27969,42,1}, /* core4 sp_EL3 bit46 */
			{27974,42,1}, /* core4 sp_EL3 bit47 */
			{27973,42,1}, /* core4 sp_EL3 bit48 */
			{27967,42,1}, /* core4 sp_EL3 bit49 */
			{37351,42,0}, /* core4 sp_EL3 bit50 */
			{37350,42,0}, /* core4 sp_EL3 bit51 */
			{37259,42,0}, /* core4 sp_EL3 bit52 */
			{37258,42,0}, /* core4 sp_EL3 bit53 */
			{27968,42,1}, /* core4 sp_EL3 bit54 */
			{27972,42,1}, /* core4 sp_EL3 bit55 */
			{37078,42,0}, /* core4 sp_EL3 bit56 */
			{37077,42,0}, /* core4 sp_EL3 bit57 */
			{37074,42,0}, /* core4 sp_EL3 bit58 */
			{37073,42,0}, /* core4 sp_EL3 bit59 */
			{37076,42,0}, /* core4 sp_EL3 bit60 */
			{37075,42,0}, /* core4 sp_EL3 bit61 */
			{37072,42,0}, /* core4 sp_EL3 bit62 */
			{37071,42,0}, /* core4 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{37561,41,1}, /* core4 elr_EL1 bit0 */
			{37560,41,1}, /* core4 elr_EL1 bit1 */
			{37559,41,1}, /* core4 elr_EL1 bit2 */
			{37558,41,1}, /* core4 elr_EL1 bit3 */
			{37557,41,1}, /* core4 elr_EL1 bit4 */
			{37556,41,1}, /* core4 elr_EL1 bit5 */
			{37555,41,1}, /* core4 elr_EL1 bit6 */
			{37554,41,1}, /* core4 elr_EL1 bit7 */
			{37036,42,0}, /* core4 elr_EL1 bit8 */
			{37035,42,0}, /* core4 elr_EL1 bit9 */
			{30621,41,1}, /* core4 elr_EL1 bit10 */
			{30620,41,1}, /* core4 elr_EL1 bit11 */
			{37030,42,0}, /* core4 elr_EL1 bit12 */
			{37029,42,0}, /* core4 elr_EL1 bit13 */
			{37022,42,0}, /* core4 elr_EL1 bit14 */
			{37021,42,0}, /* core4 elr_EL1 bit15 */
			{30605,41,1}, /* core4 elr_EL1 bit16 */
			{30604,41,1}, /* core4 elr_EL1 bit17 */
			{30603,41,1}, /* core4 elr_EL1 bit18 */
			{30602,41,1}, /* core4 elr_EL1 bit19 */
			{37018,42,0}, /* core4 elr_EL1 bit20 */
			{37017,42,0}, /* core4 elr_EL1 bit21 */
			{30619,41,1}, /* core4 elr_EL1 bit22 */
			{30618,41,1}, /* core4 elr_EL1 bit23 */
			{30601,41,1}, /* core4 elr_EL1 bit24 */
			{30600,41,1}, /* core4 elr_EL1 bit25 */
			{30599,41,1}, /* core4 elr_EL1 bit26 */
			{30598,41,1}, /* core4 elr_EL1 bit27 */
			{37020,42,0}, /* core4 elr_EL1 bit28 */
			{37019,42,0}, /* core4 elr_EL1 bit29 */
			{37032,42,0}, /* core4 elr_EL1 bit30 */
			{37031,42,0}, /* core4 elr_EL1 bit31 */
			{27939,42,1}, /* core4 elr_EL1 bit32 */
			{27953,42,1}, /* core4 elr_EL1 bit33 */
			{37052,42,0}, /* core4 elr_EL1 bit34 */
			{37051,42,0}, /* core4 elr_EL1 bit35 */
			{37050,42,0}, /* core4 elr_EL1 bit36 */
			{37049,42,0}, /* core4 elr_EL1 bit37 */
			{27954,42,1}, /* core4 elr_EL1 bit38 */
			{27938,42,1}, /* core4 elr_EL1 bit39 */
			{30641,41,1}, /* core4 elr_EL1 bit40 */
			{30640,41,1}, /* core4 elr_EL1 bit41 */
			{30639,41,1}, /* core4 elr_EL1 bit42 */
			{30638,41,1}, /* core4 elr_EL1 bit43 */
			{37038,42,0}, /* core4 elr_EL1 bit44 */
			{37037,42,0}, /* core4 elr_EL1 bit45 */
			{27955,42,1}, /* core4 elr_EL1 bit46 */
			{27950,42,1}, /* core4 elr_EL1 bit47 */
			{27949,42,1}, /* core4 elr_EL1 bit48 */
			{27952,42,1}, /* core4 elr_EL1 bit49 */
			{37042,42,0}, /* core4 elr_EL1 bit50 */
			{37041,42,0}, /* core4 elr_EL1 bit51 */
			{37044,42,0}, /* core4 elr_EL1 bit52 */
			{37043,42,0}, /* core4 elr_EL1 bit53 */
			{37048,42,0}, /* core4 elr_EL1 bit54 */
			{37047,42,0}, /* core4 elr_EL1 bit55 */
			{37058,42,0}, /* core4 elr_EL1 bit56 */
			{37057,42,0}, /* core4 elr_EL1 bit57 */
			{37040,42,0}, /* core4 elr_EL1 bit58 */
			{37039,42,0}, /* core4 elr_EL1 bit59 */
			{37046,42,0}, /* core4 elr_EL1 bit60 */
			{37045,42,0}, /* core4 elr_EL1 bit61 */
			{27951,42,1}, /* core4 elr_EL1 bit62 */
			{27940,42,1}, /* core4 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{37553,41,1}, /* core4 elr_EL2 bit0 */
			{37552,41,1}, /* core4 elr_EL2 bit1 */
			{37551,41,1}, /* core4 elr_EL2 bit2 */
			{37550,41,1}, /* core4 elr_EL2 bit3 */
			{37549,41,1}, /* core4 elr_EL2 bit4 */
			{37548,41,1}, /* core4 elr_EL2 bit5 */
			{37547,41,1}, /* core4 elr_EL2 bit6 */
			{37546,41,1}, /* core4 elr_EL2 bit7 */
			{30629,41,1}, /* core4 elr_EL2 bit8 */
			{30628,41,1}, /* core4 elr_EL2 bit9 */
			{37537,41,1}, /* core4 elr_EL2 bit10 */
			{30627,41,1}, /* core4 elr_EL2 bit11 */
			{37536,41,1}, /* core4 elr_EL2 bit12 */
			{30626,41,1}, /* core4 elr_EL2 bit13 */
			{37535,41,1}, /* core4 elr_EL2 bit14 */
			{37534,41,1}, /* core4 elr_EL2 bit15 */
			{37533,41,1}, /* core4 elr_EL2 bit16 */
			{37532,41,1}, /* core4 elr_EL2 bit17 */
			{37531,41,1}, /* core4 elr_EL2 bit18 */
			{37530,41,1}, /* core4 elr_EL2 bit19 */
			{30609,41,1}, /* core4 elr_EL2 bit20 */
			{30608,41,1}, /* core4 elr_EL2 bit21 */
			{30607,41,1}, /* core4 elr_EL2 bit22 */
			{30606,41,1}, /* core4 elr_EL2 bit23 */
			{30613,41,1}, /* core4 elr_EL2 bit24 */
			{30612,41,1}, /* core4 elr_EL2 bit25 */
			{30611,41,1}, /* core4 elr_EL2 bit26 */
			{30610,41,1}, /* core4 elr_EL2 bit27 */
			{37024,42,0}, /* core4 elr_EL2 bit28 */
			{37023,42,0}, /* core4 elr_EL2 bit29 */
			{27873,42,1}, /* core4 elr_EL2 bit30 */
			{27878,42,1}, /* core4 elr_EL2 bit31 */
			{27943,42,1}, /* core4 elr_EL2 bit32 */
			{27956,42,1}, /* core4 elr_EL2 bit33 */
			{37054,42,0}, /* core4 elr_EL2 bit34 */
			{37053,42,0}, /* core4 elr_EL2 bit35 */
			{37056,42,0}, /* core4 elr_EL2 bit36 */
			{37055,42,0}, /* core4 elr_EL2 bit37 */
			{27957,42,1}, /* core4 elr_EL2 bit38 */
			{27942,42,1}, /* core4 elr_EL2 bit39 */
			{30637,41,1}, /* core4 elr_EL2 bit40 */
			{30636,41,1}, /* core4 elr_EL2 bit41 */
			{30635,41,1}, /* core4 elr_EL2 bit42 */
			{30634,41,1}, /* core4 elr_EL2 bit43 */
			{37070,42,0}, /* core4 elr_EL2 bit44 */
			{37069,42,0}, /* core4 elr_EL2 bit45 */
			{27958,42,1}, /* core4 elr_EL2 bit46 */
			{27948,42,1}, /* core4 elr_EL2 bit47 */
			{27947,42,1}, /* core4 elr_EL2 bit48 */
			{27959,42,1}, /* core4 elr_EL2 bit49 */
			{37066,42,0}, /* core4 elr_EL2 bit50 */
			{37065,42,0}, /* core4 elr_EL2 bit51 */
			{37062,42,0}, /* core4 elr_EL2 bit52 */
			{37061,42,0}, /* core4 elr_EL2 bit53 */
			{30633,41,1}, /* core4 elr_EL2 bit54 */
			{30632,41,1}, /* core4 elr_EL2 bit55 */
			{37060,42,0}, /* core4 elr_EL2 bit56 */
			{37059,42,0}, /* core4 elr_EL2 bit57 */
			{37068,42,0}, /* core4 elr_EL2 bit58 */
			{37067,42,0}, /* core4 elr_EL2 bit59 */
			{37064,42,0}, /* core4 elr_EL2 bit60 */
			{37063,42,0}, /* core4 elr_EL2 bit61 */
			{30631,41,1}, /* core4 elr_EL2 bit62 */
			{30630,41,1}, /* core4 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{37545,41,1}, /* core4 elr_EL3 bit0 */
			{37544,41,1}, /* core4 elr_EL3 bit1 */
			{37543,41,1}, /* core4 elr_EL3 bit2 */
			{37542,41,1}, /* core4 elr_EL3 bit3 */
			{37541,41,1}, /* core4 elr_EL3 bit4 */
			{37540,41,1}, /* core4 elr_EL3 bit5 */
			{37539,41,1}, /* core4 elr_EL3 bit6 */
			{37538,41,1}, /* core4 elr_EL3 bit7 */
			{37034,42,0}, /* core4 elr_EL3 bit8 */
			{37033,42,0}, /* core4 elr_EL3 bit9 */
			{30625,41,1}, /* core4 elr_EL3 bit10 */
			{30624,41,1}, /* core4 elr_EL3 bit11 */
			{30623,41,1}, /* core4 elr_EL3 bit12 */
			{30622,41,1}, /* core4 elr_EL3 bit13 */
			{37026,42,0}, /* core4 elr_EL3 bit14 */
			{37025,42,0}, /* core4 elr_EL3 bit15 */
			{37014,42,0}, /* core4 elr_EL3 bit16 */
			{37013,42,0}, /* core4 elr_EL3 bit17 */
			{27866,42,1}, /* core4 elr_EL3 bit18 */
			{27867,42,1}, /* core4 elr_EL3 bit19 */
			{30617,41,1}, /* core4 elr_EL3 bit20 */
			{30616,41,1}, /* core4 elr_EL3 bit21 */
			{30615,41,1}, /* core4 elr_EL3 bit22 */
			{30614,41,1}, /* core4 elr_EL3 bit23 */
			{27865,42,1}, /* core4 elr_EL3 bit24 */
			{27874,42,1}, /* core4 elr_EL3 bit25 */
			{37016,42,0}, /* core4 elr_EL3 bit26 */
			{37015,42,0}, /* core4 elr_EL3 bit27 */
			{37028,42,0}, /* core4 elr_EL3 bit28 */
			{37027,42,0}, /* core4 elr_EL3 bit29 */
			{27868,42,1}, /* core4 elr_EL3 bit30 */
			{27877,42,1}, /* core4 elr_EL3 bit31 */
			{30669,41,1}, /* core4 elr_EL3 bit32 */
			{30668,41,1}, /* core4 elr_EL3 bit33 */
			{30667,41,1}, /* core4 elr_EL3 bit34 */
			{30666,41,1}, /* core4 elr_EL3 bit35 */
			{30657,41,1}, /* core4 elr_EL3 bit36 */
			{30656,41,1}, /* core4 elr_EL3 bit37 */
			{30655,41,1}, /* core4 elr_EL3 bit38 */
			{30654,41,1}, /* core4 elr_EL3 bit39 */
			{37012,42,0}, /* core4 elr_EL3 bit40 */
			{37011,42,0}, /* core4 elr_EL3 bit41 */
			{27928,42,1}, /* core4 elr_EL3 bit42 */
			{27927,42,1}, /* core4 elr_EL3 bit43 */
			{30661,41,1}, /* core4 elr_EL3 bit44 */
			{30660,41,1}, /* core4 elr_EL3 bit45 */
			{30659,41,1}, /* core4 elr_EL3 bit46 */
			{30658,41,1}, /* core4 elr_EL3 bit47 */
			{30665,41,1}, /* core4 elr_EL3 bit48 */
			{30664,41,1}, /* core4 elr_EL3 bit49 */
			{30663,41,1}, /* core4 elr_EL3 bit50 */
			{30662,41,1}, /* core4 elr_EL3 bit51 */
			{30565,41,1}, /* core4 elr_EL3 bit52 */
			{30564,41,1}, /* core4 elr_EL3 bit53 */
			{30563,41,1}, /* core4 elr_EL3 bit54 */
			{30562,41,1}, /* core4 elr_EL3 bit55 */
			{37513,41,1}, /* core4 elr_EL3 bit56 */
			{37512,41,1}, /* core4 elr_EL3 bit57 */
			{37511,41,1}, /* core4 elr_EL3 bit58 */
			{37510,41,1}, /* core4 elr_EL3 bit59 */
			{37509,41,1}, /* core4 elr_EL3 bit60 */
			{37508,41,1}, /* core4 elr_EL3 bit61 */
			{37507,41,1}, /* core4 elr_EL3 bit62 */
			{37506,41,1}, /* core4 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31320,42,1}, /* core4 raw_pc bit0 */
			{31430,42,1}, /* core4 raw_pc bit1 */
			{32637,41,1}, /* core4 raw_pc bit2 */
			{32636,41,1}, /* core4 raw_pc bit3 */
			{32635,41,1}, /* core4 raw_pc bit4 */
			{32634,41,1}, /* core4 raw_pc bit5 */
			{31328,42,1}, /* core4 raw_pc bit6 */
			{39377,41,1}, /* core4 raw_pc bit7 */
			{39376,41,1}, /* core4 raw_pc bit8 */
			{39375,41,1}, /* core4 raw_pc bit9 */
			{39374,41,1}, /* core4 raw_pc bit10 */
			{39373,41,1}, /* core4 raw_pc bit11 */
			{39372,41,1}, /* core4 raw_pc bit12 */
			{39371,41,1}, /* core4 raw_pc bit13 */
			{39370,41,1}, /* core4 raw_pc bit14 */
			{39305,41,1}, /* core4 raw_pc bit15 */
			{39304,41,1}, /* core4 raw_pc bit16 */
			{39303,41,1}, /* core4 raw_pc bit17 */
			{39302,41,1}, /* core4 raw_pc bit18 */
			{39301,41,1}, /* core4 raw_pc bit19 */
			{39300,41,1}, /* core4 raw_pc bit20 */
			{39299,41,1}, /* core4 raw_pc bit21 */
			{39298,41,1}, /* core4 raw_pc bit22 */
			{39313,41,1}, /* core4 raw_pc bit23 */
			{39312,41,1}, /* core4 raw_pc bit24 */
			{39311,41,1}, /* core4 raw_pc bit25 */
			{39310,41,1}, /* core4 raw_pc bit26 */
			{39309,41,1}, /* core4 raw_pc bit27 */
			{39308,41,1}, /* core4 raw_pc bit28 */
			{39307,41,1}, /* core4 raw_pc bit29 */
			{39306,41,1}, /* core4 raw_pc bit30 */
			{39369,41,1}, /* core4 raw_pc bit31 */
			{39368,41,1}, /* core4 raw_pc bit32 */
			{39367,41,1}, /* core4 raw_pc bit33 */
			{39366,41,1}, /* core4 raw_pc bit34 */
			{39365,41,1}, /* core4 raw_pc bit35 */
			{39364,41,1}, /* core4 raw_pc bit36 */
			{39363,41,1}, /* core4 raw_pc bit37 */
			{39362,41,1}, /* core4 raw_pc bit38 */
			{39361,41,1}, /* core4 raw_pc bit39 */
			{39360,41,1}, /* core4 raw_pc bit40 */
			{39359,41,1}, /* core4 raw_pc bit41 */
			{39358,41,1}, /* core4 raw_pc bit42 */
			{39357,41,1}, /* core4 raw_pc bit43 */
			{39356,41,1}, /* core4 raw_pc bit44 */
			{39355,41,1}, /* core4 raw_pc bit45 */
			{39354,41,1}, /* core4 raw_pc bit46 */
			{38933,42,1}, /* core4 raw_pc bit47 */
			{38932,42,1}, /* core4 raw_pc bit48 */
			{31321,42,1}, /* core4 raw_pc bit49 */
			{    0, 0,2}, /* core4 raw_pc bit50 */
			{    0, 0,2}, /* core4 raw_pc bit51 */
			{    0, 0,2}, /* core4 raw_pc bit52 */
			{    0, 0,2}, /* core4 raw_pc bit53 */
			{    0, 0,2}, /* core4 raw_pc bit54 */
			{    0, 0,2}, /* core4 raw_pc bit55 */
			{    0, 0,2}, /* core4 raw_pc bit56 */
			{    0, 0,2}, /* core4 raw_pc bit57 */
			{    0, 0,2}, /* core4 raw_pc bit58 */
			{    0, 0,2}, /* core4 raw_pc bit59 */
			{    0, 0,2}, /* core4 raw_pc bit60 */
			{    0, 0,2}, /* core4 raw_pc bit61 */
			{    0, 0,2}, /* core4 raw_pc bit62 */
			{    0, 0,2}, /* core4 raw_pc bit63 */
			}},
			.pc_iss = {{
			{31564,42,1}, /* core4 pc_iss bit0 */
			{31566,42,1}, /* core4 pc_iss bit1 */
			{38983,42,1}, /* core4 pc_iss bit2 */
			{38982,42,1}, /* core4 pc_iss bit3 */
			{32597,41,1}, /* core4 pc_iss bit4 */
			{32596,41,1}, /* core4 pc_iss bit5 */
			{32595,41,1}, /* core4 pc_iss bit6 */
			{32594,41,1}, /* core4 pc_iss bit7 */
			{31651,42,0}, /* core4 pc_iss bit8 */
			{31556,42,1}, /* core4 pc_iss bit9 */
			{31563,42,1}, /* core4 pc_iss bit10 */
			{31654,42,0}, /* core4 pc_iss bit11 */
			{31559,42,1}, /* core4 pc_iss bit12 */
			{31659,42,0}, /* core4 pc_iss bit13 */
			{31658,42,0}, /* core4 pc_iss bit14 */
			{31655,42,0}, /* core4 pc_iss bit15 */
			{31557,42,1}, /* core4 pc_iss bit16 */
			{31656,42,0}, /* core4 pc_iss bit17 */
			{31657,42,0}, /* core4 pc_iss bit18 */
			{31558,42,1}, /* core4 pc_iss bit19 */
			{32605,41,1}, /* core4 pc_iss bit20 */
			{32604,41,1}, /* core4 pc_iss bit21 */
			{32603,41,1}, /* core4 pc_iss bit22 */
			{32602,41,1}, /* core4 pc_iss bit23 */
			{38985,42,1}, /* core4 pc_iss bit24 */
			{38984,42,1}, /* core4 pc_iss bit25 */
			{31652,42,0}, /* core4 pc_iss bit26 */
			{31555,42,1}, /* core4 pc_iss bit27 */
			{32609,41,1}, /* core4 pc_iss bit28 */
			{32608,41,1}, /* core4 pc_iss bit29 */
			{32607,41,1}, /* core4 pc_iss bit30 */
			{32606,41,1}, /* core4 pc_iss bit31 */
			{31554,42,1}, /* core4 pc_iss bit32 */
			{31553,42,1}, /* core4 pc_iss bit33 */
			{38981,42,1}, /* core4 pc_iss bit34 */
			{38980,42,1}, /* core4 pc_iss bit35 */
			{32613,41,1}, /* core4 pc_iss bit36 */
			{32612,41,1}, /* core4 pc_iss bit37 */
			{32611,41,1}, /* core4 pc_iss bit38 */
			{32610,41,1}, /* core4 pc_iss bit39 */
			{39401,41,1}, /* core4 pc_iss bit40 */
			{39400,41,1}, /* core4 pc_iss bit41 */
			{39399,41,1}, /* core4 pc_iss bit42 */
			{39398,41,1}, /* core4 pc_iss bit43 */
			{39397,41,1}, /* core4 pc_iss bit44 */
			{39396,41,1}, /* core4 pc_iss bit45 */
			{39395,41,1}, /* core4 pc_iss bit46 */
			{39394,41,1}, /* core4 pc_iss bit47 */
			{32593,41,1}, /* core4 pc_iss bit48 */
			{32592,41,1}, /* core4 pc_iss bit49 */
			{32591,41,1}, /* core4 pc_iss bit50 */
			{32590,41,1}, /* core4 pc_iss bit51 */
			{38979,42,1}, /* core4 pc_iss bit52 */
			{38978,42,1}, /* core4 pc_iss bit53 */
			{31455,42,1}, /* core4 pc_iss bit54 */
			{31456,42,1}, /* core4 pc_iss bit55 */
			{31457,42,1}, /* core4 pc_iss bit56 */
			{31454,42,1}, /* core4 pc_iss bit57 */
			{31551,42,1}, /* core4 pc_iss bit58 */
			{31452,42,1}, /* core4 pc_iss bit59 */
			{31552,42,1}, /* core4 pc_iss bit60 */
			{31453,42,1}, /* core4 pc_iss bit61 */
			{38977,42,1}, /* core4 pc_iss bit62 */
			{38976,42,1}, /* core4 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31605,42,0}, /* core4 full_pc_wr bit0 */
			{    0, 0,2}, /* core4 full_pc_wr bit1 */
			{    0, 0,2}, /* core4 full_pc_wr bit2 */
			{    0, 0,2}, /* core4 full_pc_wr bit3 */
			{    0, 0,2}, /* core4 full_pc_wr bit4 */
			{    0, 0,2}, /* core4 full_pc_wr bit5 */
			{    0, 0,2}, /* core4 full_pc_wr bit6 */
			{    0, 0,2}, /* core4 full_pc_wr bit7 */
			{    0, 0,2}, /* core4 full_pc_wr bit8 */
			{    0, 0,2}, /* core4 full_pc_wr bit9 */
			{    0, 0,2}, /* core4 full_pc_wr bit10 */
			{    0, 0,2}, /* core4 full_pc_wr bit11 */
			{    0, 0,2}, /* core4 full_pc_wr bit12 */
			{    0, 0,2}, /* core4 full_pc_wr bit13 */
			{    0, 0,2}, /* core4 full_pc_wr bit14 */
			{    0, 0,2}, /* core4 full_pc_wr bit15 */
			{    0, 0,2}, /* core4 full_pc_wr bit16 */
			{    0, 0,2}, /* core4 full_pc_wr bit17 */
			{    0, 0,2}, /* core4 full_pc_wr bit18 */
			{    0, 0,2}, /* core4 full_pc_wr bit19 */
			{    0, 0,2}, /* core4 full_pc_wr bit20 */
			{    0, 0,2}, /* core4 full_pc_wr bit21 */
			{    0, 0,2}, /* core4 full_pc_wr bit22 */
			{    0, 0,2}, /* core4 full_pc_wr bit23 */
			{    0, 0,2}, /* core4 full_pc_wr bit24 */
			{    0, 0,2}, /* core4 full_pc_wr bit25 */
			{    0, 0,2}, /* core4 full_pc_wr bit26 */
			{    0, 0,2}, /* core4 full_pc_wr bit27 */
			{    0, 0,2}, /* core4 full_pc_wr bit28 */
			{    0, 0,2}, /* core4 full_pc_wr bit29 */
			{    0, 0,2}, /* core4 full_pc_wr bit30 */
			{    0, 0,2}, /* core4 full_pc_wr bit31 */
			{    0, 0,2}, /* core4 full_pc_wr bit32 */
			{    0, 0,2}, /* core4 full_pc_wr bit33 */
			{    0, 0,2}, /* core4 full_pc_wr bit34 */
			{    0, 0,2}, /* core4 full_pc_wr bit35 */
			{    0, 0,2}, /* core4 full_pc_wr bit36 */
			{    0, 0,2}, /* core4 full_pc_wr bit37 */
			{    0, 0,2}, /* core4 full_pc_wr bit38 */
			{    0, 0,2}, /* core4 full_pc_wr bit39 */
			{    0, 0,2}, /* core4 full_pc_wr bit40 */
			{    0, 0,2}, /* core4 full_pc_wr bit41 */
			{    0, 0,2}, /* core4 full_pc_wr bit42 */
			{    0, 0,2}, /* core4 full_pc_wr bit43 */
			{    0, 0,2}, /* core4 full_pc_wr bit44 */
			{    0, 0,2}, /* core4 full_pc_wr bit45 */
			{    0, 0,2}, /* core4 full_pc_wr bit46 */
			{    0, 0,2}, /* core4 full_pc_wr bit47 */
			{    0, 0,2}, /* core4 full_pc_wr bit48 */
			{    0, 0,2}, /* core4 full_pc_wr bit49 */
			{    0, 0,2}, /* core4 full_pc_wr bit50 */
			{    0, 0,2}, /* core4 full_pc_wr bit51 */
			{    0, 0,2}, /* core4 full_pc_wr bit52 */
			{    0, 0,2}, /* core4 full_pc_wr bit53 */
			{    0, 0,2}, /* core4 full_pc_wr bit54 */
			{    0, 0,2}, /* core4 full_pc_wr bit55 */
			{    0, 0,2}, /* core4 full_pc_wr bit56 */
			{    0, 0,2}, /* core4 full_pc_wr bit57 */
			{    0, 0,2}, /* core4 full_pc_wr bit58 */
			{    0, 0,2}, /* core4 full_pc_wr bit59 */
			{    0, 0,2}, /* core4 full_pc_wr bit60 */
			{    0, 0,2}, /* core4 full_pc_wr bit61 */
			{    0, 0,2}, /* core4 full_pc_wr bit62 */
			{    0, 0,2}, /* core4 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{31612,42,0}, /* core4 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{32625,41,1}, /* core4 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{16480,42,0}, /* core4 return_Stack_pointer bit0 */
			{16473,42,0}, /* core4 return_Stack_pointer bit1 */
			{16474,42,0}, /* core4 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{20540,42,0}, /* core4 return_Stack0 bit0 */
			{20539,42,0}, /* core4 return_Stack0 bit1 */
			{20538,42,0}, /* core4 return_Stack0 bit2 */
			{20537,42,0}, /* core4 return_Stack0 bit3 */
			{20536,42,0}, /* core4 return_Stack0 bit4 */
			{20535,42,0}, /* core4 return_Stack0 bit5 */
			{20534,42,0}, /* core4 return_Stack0 bit6 */
			{20568,42,0}, /* core4 return_Stack0 bit7 */
			{20567,42,0}, /* core4 return_Stack0 bit8 */
			{20566,42,0}, /* core4 return_Stack0 bit9 */
			{20565,42,0}, /* core4 return_Stack0 bit10 */
			{20588,42,0}, /* core4 return_Stack0 bit11 */
			{20587,42,0}, /* core4 return_Stack0 bit12 */
			{20586,42,0}, /* core4 return_Stack0 bit13 */
			{20585,42,0}, /* core4 return_Stack0 bit14 */
			{20584,42,0}, /* core4 return_Stack0 bit15 */
			{20583,42,0}, /* core4 return_Stack0 bit16 */
			{20582,42,0}, /* core4 return_Stack0 bit17 */
			{20581,42,0}, /* core4 return_Stack0 bit18 */
			{20612,42,0}, /* core4 return_Stack0 bit19 */
			{20611,42,0}, /* core4 return_Stack0 bit20 */
			{20610,42,0}, /* core4 return_Stack0 bit21 */
			{20609,42,0}, /* core4 return_Stack0 bit22 */
			{20608,42,0}, /* core4 return_Stack0 bit23 */
			{20607,42,0}, /* core4 return_Stack0 bit24 */
			{20606,42,0}, /* core4 return_Stack0 bit25 */
			{20605,42,0}, /* core4 return_Stack0 bit26 */
			{20528,42,0}, /* core4 return_Stack0 bit27 */
			{20527,42,0}, /* core4 return_Stack0 bit28 */
			{20526,42,0}, /* core4 return_Stack0 bit29 */
			{20533,42,0}, /* core4 return_Stack0 bit30 */
			{16458,42,0}, /* core4 return_Stack0 bit31 */
			{20525,42,0}, /* core4 return_Stack0 bit32 */
			{16457,42,0}, /* core4 return_Stack0 bit33 */
			{16460,42,0}, /* core4 return_Stack0 bit34 */
			{16459,42,0}, /* core4 return_Stack0 bit35 */
			{20504,42,0}, /* core4 return_Stack0 bit36 */
			{20503,42,0}, /* core4 return_Stack0 bit37 */
			{20502,42,0}, /* core4 return_Stack0 bit38 */
			{20501,42,0}, /* core4 return_Stack0 bit39 */
			{20500,42,0}, /* core4 return_Stack0 bit40 */
			{20499,42,0}, /* core4 return_Stack0 bit41 */
			{20498,42,0}, /* core4 return_Stack0 bit42 */
			{20497,42,0}, /* core4 return_Stack0 bit43 */
			{20496,42,0}, /* core4 return_Stack0 bit44 */
			{20495,42,0}, /* core4 return_Stack0 bit45 */
			{20494,42,0}, /* core4 return_Stack0 bit46 */
			{20493,42,0}, /* core4 return_Stack0 bit47 */
			{13577,42,1}, /* core4 return_Stack0 bit48 */
			{    0, 0,2}, /* core4 return_Stack0 bit49 */
			{    0, 0,2}, /* core4 return_Stack0 bit50 */
			{    0, 0,2}, /* core4 return_Stack0 bit51 */
			{    0, 0,2}, /* core4 return_Stack0 bit52 */
			{    0, 0,2}, /* core4 return_Stack0 bit53 */
			{    0, 0,2}, /* core4 return_Stack0 bit54 */
			{    0, 0,2}, /* core4 return_Stack0 bit55 */
			{    0, 0,2}, /* core4 return_Stack0 bit56 */
			{    0, 0,2}, /* core4 return_Stack0 bit57 */
			{    0, 0,2}, /* core4 return_Stack0 bit58 */
			{    0, 0,2}, /* core4 return_Stack0 bit59 */
			{    0, 0,2}, /* core4 return_Stack0 bit60 */
			{    0, 0,2}, /* core4 return_Stack0 bit61 */
			{    0, 0,2}, /* core4 return_Stack0 bit62 */
			{    0, 0,2}, /* core4 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{20548,42,0}, /* core4 return_Stack1 bit0 */
			{20547,42,0}, /* core4 return_Stack1 bit1 */
			{20546,42,0}, /* core4 return_Stack1 bit2 */
			{20545,42,0}, /* core4 return_Stack1 bit3 */
			{20552,42,0}, /* core4 return_Stack1 bit4 */
			{20551,42,0}, /* core4 return_Stack1 bit5 */
			{20550,42,0}, /* core4 return_Stack1 bit6 */
			{20564,42,0}, /* core4 return_Stack1 bit7 */
			{20563,42,0}, /* core4 return_Stack1 bit8 */
			{20562,42,0}, /* core4 return_Stack1 bit9 */
			{20561,42,0}, /* core4 return_Stack1 bit10 */
			{20592,42,0}, /* core4 return_Stack1 bit11 */
			{20591,42,0}, /* core4 return_Stack1 bit12 */
			{20590,42,0}, /* core4 return_Stack1 bit13 */
			{20589,42,0}, /* core4 return_Stack1 bit14 */
			{20600,42,0}, /* core4 return_Stack1 bit15 */
			{20599,42,0}, /* core4 return_Stack1 bit16 */
			{20598,42,0}, /* core4 return_Stack1 bit17 */
			{20597,42,0}, /* core4 return_Stack1 bit18 */
			{20580,42,0}, /* core4 return_Stack1 bit19 */
			{20579,42,0}, /* core4 return_Stack1 bit20 */
			{20578,42,0}, /* core4 return_Stack1 bit21 */
			{20577,42,0}, /* core4 return_Stack1 bit22 */
			{20572,42,0}, /* core4 return_Stack1 bit23 */
			{20571,42,0}, /* core4 return_Stack1 bit24 */
			{20570,42,0}, /* core4 return_Stack1 bit25 */
			{20569,42,0}, /* core4 return_Stack1 bit26 */
			{20532,42,0}, /* core4 return_Stack1 bit27 */
			{20531,42,0}, /* core4 return_Stack1 bit28 */
			{20530,42,0}, /* core4 return_Stack1 bit29 */
			{20529,42,0}, /* core4 return_Stack1 bit30 */
			{20549,42,0}, /* core4 return_Stack1 bit31 */
			{13574,42,1}, /* core4 return_Stack1 bit32 */
			{20520,42,0}, /* core4 return_Stack1 bit33 */
			{20519,42,0}, /* core4 return_Stack1 bit34 */
			{20518,42,0}, /* core4 return_Stack1 bit35 */
			{20517,42,0}, /* core4 return_Stack1 bit36 */
			{20516,42,0}, /* core4 return_Stack1 bit37 */
			{20515,42,0}, /* core4 return_Stack1 bit38 */
			{20514,42,0}, /* core4 return_Stack1 bit39 */
			{20513,42,0}, /* core4 return_Stack1 bit40 */
			{20492,42,0}, /* core4 return_Stack1 bit41 */
			{20491,42,0}, /* core4 return_Stack1 bit42 */
			{20490,42,0}, /* core4 return_Stack1 bit43 */
			{20489,42,0}, /* core4 return_Stack1 bit44 */
			{20488,42,0}, /* core4 return_Stack1 bit45 */
			{20487,42,0}, /* core4 return_Stack1 bit46 */
			{20486,42,0}, /* core4 return_Stack1 bit47 */
			{20485,42,0}, /* core4 return_Stack1 bit48 */
			{    0, 0,2}, /* core4 return_Stack1 bit49 */
			{    0, 0,2}, /* core4 return_Stack1 bit50 */
			{    0, 0,2}, /* core4 return_Stack1 bit51 */
			{    0, 0,2}, /* core4 return_Stack1 bit52 */
			{    0, 0,2}, /* core4 return_Stack1 bit53 */
			{    0, 0,2}, /* core4 return_Stack1 bit54 */
			{    0, 0,2}, /* core4 return_Stack1 bit55 */
			{    0, 0,2}, /* core4 return_Stack1 bit56 */
			{    0, 0,2}, /* core4 return_Stack1 bit57 */
			{    0, 0,2}, /* core4 return_Stack1 bit58 */
			{    0, 0,2}, /* core4 return_Stack1 bit59 */
			{    0, 0,2}, /* core4 return_Stack1 bit60 */
			{    0, 0,2}, /* core4 return_Stack1 bit61 */
			{    0, 0,2}, /* core4 return_Stack1 bit62 */
			{    0, 0,2}, /* core4 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{20544,42,0}, /* core4 return_Stack2 bit0 */
			{20543,42,0}, /* core4 return_Stack2 bit1 */
			{20542,42,0}, /* core4 return_Stack2 bit2 */
			{20541,42,0}, /* core4 return_Stack2 bit3 */
			{20556,42,0}, /* core4 return_Stack2 bit4 */
			{20555,42,0}, /* core4 return_Stack2 bit5 */
			{20554,42,0}, /* core4 return_Stack2 bit6 */
			{20553,42,0}, /* core4 return_Stack2 bit7 */
			{20560,42,0}, /* core4 return_Stack2 bit8 */
			{20559,42,0}, /* core4 return_Stack2 bit9 */
			{20558,42,0}, /* core4 return_Stack2 bit10 */
			{20557,42,0}, /* core4 return_Stack2 bit11 */
			{20596,42,0}, /* core4 return_Stack2 bit12 */
			{20595,42,0}, /* core4 return_Stack2 bit13 */
			{16346,42,0}, /* core4 return_Stack2 bit14 */
			{20594,42,0}, /* core4 return_Stack2 bit15 */
			{16345,42,0}, /* core4 return_Stack2 bit16 */
			{20593,42,0}, /* core4 return_Stack2 bit17 */
			{16344,42,0}, /* core4 return_Stack2 bit18 */
			{20576,42,0}, /* core4 return_Stack2 bit19 */
			{20575,42,0}, /* core4 return_Stack2 bit20 */
			{20574,42,0}, /* core4 return_Stack2 bit21 */
			{20573,42,0}, /* core4 return_Stack2 bit22 */
			{20604,42,0}, /* core4 return_Stack2 bit23 */
			{20603,42,0}, /* core4 return_Stack2 bit24 */
			{20602,42,0}, /* core4 return_Stack2 bit25 */
			{20601,42,0}, /* core4 return_Stack2 bit26 */
			{16343,42,0}, /* core4 return_Stack2 bit27 */
			{16512,42,0}, /* core4 return_Stack2 bit28 */
			{16511,42,0}, /* core4 return_Stack2 bit29 */
			{20524,42,0}, /* core4 return_Stack2 bit30 */
			{20523,42,0}, /* core4 return_Stack2 bit31 */
			{13573,42,1}, /* core4 return_Stack2 bit32 */
			{20522,42,0}, /* core4 return_Stack2 bit33 */
			{20521,42,0}, /* core4 return_Stack2 bit34 */
			{20512,42,0}, /* core4 return_Stack2 bit35 */
			{20511,42,0}, /* core4 return_Stack2 bit36 */
			{20510,42,0}, /* core4 return_Stack2 bit37 */
			{20509,42,0}, /* core4 return_Stack2 bit38 */
			{20508,42,0}, /* core4 return_Stack2 bit39 */
			{20507,42,0}, /* core4 return_Stack2 bit40 */
			{20506,42,0}, /* core4 return_Stack2 bit41 */
			{20505,42,0}, /* core4 return_Stack2 bit42 */
			{20460,42,0}, /* core4 return_Stack2 bit43 */
			{20459,42,0}, /* core4 return_Stack2 bit44 */
			{20458,42,0}, /* core4 return_Stack2 bit45 */
			{20457,42,0}, /* core4 return_Stack2 bit46 */
			{13583,42,1}, /* core4 return_Stack2 bit47 */
			{13584,42,1}, /* core4 return_Stack2 bit48 */
			{    0, 0,2}, /* core4 return_Stack2 bit49 */
			{    0, 0,2}, /* core4 return_Stack2 bit50 */
			{    0, 0,2}, /* core4 return_Stack2 bit51 */
			{    0, 0,2}, /* core4 return_Stack2 bit52 */
			{    0, 0,2}, /* core4 return_Stack2 bit53 */
			{    0, 0,2}, /* core4 return_Stack2 bit54 */
			{    0, 0,2}, /* core4 return_Stack2 bit55 */
			{    0, 0,2}, /* core4 return_Stack2 bit56 */
			{    0, 0,2}, /* core4 return_Stack2 bit57 */
			{    0, 0,2}, /* core4 return_Stack2 bit58 */
			{    0, 0,2}, /* core4 return_Stack2 bit59 */
			{    0, 0,2}, /* core4 return_Stack2 bit60 */
			{    0, 0,2}, /* core4 return_Stack2 bit61 */
			{    0, 0,2}, /* core4 return_Stack2 bit62 */
			{    0, 0,2}, /* core4 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{20362,42,0}, /* core4 return_Stack3 bit0 */
			{20361,42,0}, /* core4 return_Stack3 bit1 */
			{20360,42,0}, /* core4 return_Stack3 bit2 */
			{20359,42,0}, /* core4 return_Stack3 bit3 */
			{20270,42,0}, /* core4 return_Stack3 bit4 */
			{20269,42,0}, /* core4 return_Stack3 bit5 */
			{20366,42,0}, /* core4 return_Stack3 bit6 */
			{20268,42,0}, /* core4 return_Stack3 bit7 */
			{20267,42,0}, /* core4 return_Stack3 bit8 */
			{20418,42,0}, /* core4 return_Stack3 bit9 */
			{20417,42,0}, /* core4 return_Stack3 bit10 */
			{20416,42,0}, /* core4 return_Stack3 bit11 */
			{20415,42,0}, /* core4 return_Stack3 bit12 */
			{16362,42,0}, /* core4 return_Stack3 bit13 */
			{16361,42,0}, /* core4 return_Stack3 bit14 */
			{16360,42,0}, /* core4 return_Stack3 bit15 */
			{16359,42,0}, /* core4 return_Stack3 bit16 */
			{16338,42,0}, /* core4 return_Stack3 bit17 */
			{16337,42,0}, /* core4 return_Stack3 bit18 */
			{16340,42,0}, /* core4 return_Stack3 bit19 */
			{16339,42,0}, /* core4 return_Stack3 bit20 */
			{16498,42,0}, /* core4 return_Stack3 bit21 */
			{16497,42,0}, /* core4 return_Stack3 bit22 */
			{16500,42,0}, /* core4 return_Stack3 bit23 */
			{16499,42,0}, /* core4 return_Stack3 bit24 */
			{16504,42,0}, /* core4 return_Stack3 bit25 */
			{16503,42,0}, /* core4 return_Stack3 bit26 */
			{16508,42,0}, /* core4 return_Stack3 bit27 */
			{16507,42,0}, /* core4 return_Stack3 bit28 */
			{16518,42,0}, /* core4 return_Stack3 bit29 */
			{20365,42,0}, /* core4 return_Stack3 bit30 */
			{20364,42,0}, /* core4 return_Stack3 bit31 */
			{16517,42,0}, /* core4 return_Stack3 bit32 */
			{20363,42,0}, /* core4 return_Stack3 bit33 */
			{20310,42,0}, /* core4 return_Stack3 bit34 */
			{20309,42,0}, /* core4 return_Stack3 bit35 */
			{20308,42,0}, /* core4 return_Stack3 bit36 */
			{20307,42,0}, /* core4 return_Stack3 bit37 */
			{20318,42,0}, /* core4 return_Stack3 bit38 */
			{20317,42,0}, /* core4 return_Stack3 bit39 */
			{20316,42,0}, /* core4 return_Stack3 bit40 */
			{20315,42,0}, /* core4 return_Stack3 bit41 */
			{20342,42,0}, /* core4 return_Stack3 bit42 */
			{20341,42,0}, /* core4 return_Stack3 bit43 */
			{20340,42,0}, /* core4 return_Stack3 bit44 */
			{20339,42,0}, /* core4 return_Stack3 bit45 */
			{16440,42,0}, /* core4 return_Stack3 bit46 */
			{16439,42,0}, /* core4 return_Stack3 bit47 */
			{13581,42,1}, /* core4 return_Stack3 bit48 */
			{    0, 0,2}, /* core4 return_Stack3 bit49 */
			{    0, 0,2}, /* core4 return_Stack3 bit50 */
			{    0, 0,2}, /* core4 return_Stack3 bit51 */
			{    0, 0,2}, /* core4 return_Stack3 bit52 */
			{    0, 0,2}, /* core4 return_Stack3 bit53 */
			{    0, 0,2}, /* core4 return_Stack3 bit54 */
			{    0, 0,2}, /* core4 return_Stack3 bit55 */
			{    0, 0,2}, /* core4 return_Stack3 bit56 */
			{    0, 0,2}, /* core4 return_Stack3 bit57 */
			{    0, 0,2}, /* core4 return_Stack3 bit58 */
			{    0, 0,2}, /* core4 return_Stack3 bit59 */
			{    0, 0,2}, /* core4 return_Stack3 bit60 */
			{    0, 0,2}, /* core4 return_Stack3 bit61 */
			{    0, 0,2}, /* core4 return_Stack3 bit62 */
			{    0, 0,2}, /* core4 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{20370,42,0}, /* core4 return_Stack4 bit0 */
			{20369,42,0}, /* core4 return_Stack4 bit1 */
			{20368,42,0}, /* core4 return_Stack4 bit2 */
			{20367,42,0}, /* core4 return_Stack4 bit3 */
			{20374,42,0}, /* core4 return_Stack4 bit4 */
			{20373,42,0}, /* core4 return_Stack4 bit5 */
			{20372,42,0}, /* core4 return_Stack4 bit6 */
			{20371,42,0}, /* core4 return_Stack4 bit7 */
			{20378,42,0}, /* core4 return_Stack4 bit8 */
			{20377,42,0}, /* core4 return_Stack4 bit9 */
			{20376,42,0}, /* core4 return_Stack4 bit10 */
			{20375,42,0}, /* core4 return_Stack4 bit11 */
			{20398,42,0}, /* core4 return_Stack4 bit12 */
			{20397,42,0}, /* core4 return_Stack4 bit13 */
			{20396,42,0}, /* core4 return_Stack4 bit14 */
			{20395,42,0}, /* core4 return_Stack4 bit15 */
			{20394,42,0}, /* core4 return_Stack4 bit16 */
			{20393,42,0}, /* core4 return_Stack4 bit17 */
			{20392,42,0}, /* core4 return_Stack4 bit18 */
			{20391,42,0}, /* core4 return_Stack4 bit19 */
			{20430,42,0}, /* core4 return_Stack4 bit20 */
			{20429,42,0}, /* core4 return_Stack4 bit21 */
			{20428,42,0}, /* core4 return_Stack4 bit22 */
			{20427,42,0}, /* core4 return_Stack4 bit23 */
			{20434,42,0}, /* core4 return_Stack4 bit24 */
			{20433,42,0}, /* core4 return_Stack4 bit25 */
			{20432,42,0}, /* core4 return_Stack4 bit26 */
			{20431,42,0}, /* core4 return_Stack4 bit27 */
			{16506,42,0}, /* core4 return_Stack4 bit28 */
			{16505,42,0}, /* core4 return_Stack4 bit29 */
			{16456,42,0}, /* core4 return_Stack4 bit30 */
			{16455,42,0}, /* core4 return_Stack4 bit31 */
			{16454,42,0}, /* core4 return_Stack4 bit32 */
			{16453,42,0}, /* core4 return_Stack4 bit33 */
			{16446,42,0}, /* core4 return_Stack4 bit34 */
			{20314,42,0}, /* core4 return_Stack4 bit35 */
			{20313,42,0}, /* core4 return_Stack4 bit36 */
			{20312,42,0}, /* core4 return_Stack4 bit37 */
			{20311,42,0}, /* core4 return_Stack4 bit38 */
			{20306,42,0}, /* core4 return_Stack4 bit39 */
			{20305,42,0}, /* core4 return_Stack4 bit40 */
			{20304,42,0}, /* core4 return_Stack4 bit41 */
			{20303,42,0}, /* core4 return_Stack4 bit42 */
			{20298,42,0}, /* core4 return_Stack4 bit43 */
			{20297,42,0}, /* core4 return_Stack4 bit44 */
			{20296,42,0}, /* core4 return_Stack4 bit45 */
			{20295,42,0}, /* core4 return_Stack4 bit46 */
			{16445,42,0}, /* core4 return_Stack4 bit47 */
			{13576,42,1}, /* core4 return_Stack4 bit48 */
			{    0, 0,2}, /* core4 return_Stack4 bit49 */
			{    0, 0,2}, /* core4 return_Stack4 bit50 */
			{    0, 0,2}, /* core4 return_Stack4 bit51 */
			{    0, 0,2}, /* core4 return_Stack4 bit52 */
			{    0, 0,2}, /* core4 return_Stack4 bit53 */
			{    0, 0,2}, /* core4 return_Stack4 bit54 */
			{    0, 0,2}, /* core4 return_Stack4 bit55 */
			{    0, 0,2}, /* core4 return_Stack4 bit56 */
			{    0, 0,2}, /* core4 return_Stack4 bit57 */
			{    0, 0,2}, /* core4 return_Stack4 bit58 */
			{    0, 0,2}, /* core4 return_Stack4 bit59 */
			{    0, 0,2}, /* core4 return_Stack4 bit60 */
			{    0, 0,2}, /* core4 return_Stack4 bit61 */
			{    0, 0,2}, /* core4 return_Stack4 bit62 */
			{    0, 0,2}, /* core4 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{16444,42,0}, /* core4 return_Stack5 bit0 */
			{20262,42,0}, /* core4 return_Stack5 bit1 */
			{16443,42,0}, /* core4 return_Stack5 bit2 */
			{16438,42,0}, /* core4 return_Stack5 bit3 */
			{20261,42,0}, /* core4 return_Stack5 bit4 */
			{20260,42,0}, /* core4 return_Stack5 bit5 */
			{20259,42,0}, /* core4 return_Stack5 bit6 */
			{20266,42,0}, /* core4 return_Stack5 bit7 */
			{20265,42,0}, /* core4 return_Stack5 bit8 */
			{20264,42,0}, /* core4 return_Stack5 bit9 */
			{20263,42,0}, /* core4 return_Stack5 bit10 */
			{16437,42,0}, /* core4 return_Stack5 bit11 */
			{20402,42,0}, /* core4 return_Stack5 bit12 */
			{20401,42,0}, /* core4 return_Stack5 bit13 */
			{20400,42,0}, /* core4 return_Stack5 bit14 */
			{20399,42,0}, /* core4 return_Stack5 bit15 */
			{16364,42,0}, /* core4 return_Stack5 bit16 */
			{16363,42,0}, /* core4 return_Stack5 bit17 */
			{16342,42,0}, /* core4 return_Stack5 bit18 */
			{16341,42,0}, /* core4 return_Stack5 bit19 */
			{20390,42,0}, /* core4 return_Stack5 bit20 */
			{20389,42,0}, /* core4 return_Stack5 bit21 */
			{20388,42,0}, /* core4 return_Stack5 bit22 */
			{20387,42,0}, /* core4 return_Stack5 bit23 */
			{20282,42,0}, /* core4 return_Stack5 bit24 */
			{20281,42,0}, /* core4 return_Stack5 bit25 */
			{20280,42,0}, /* core4 return_Stack5 bit26 */
			{20279,42,0}, /* core4 return_Stack5 bit27 */
			{16514,42,0}, /* core4 return_Stack5 bit28 */
			{16513,42,0}, /* core4 return_Stack5 bit29 */
			{16452,42,0}, /* core4 return_Stack5 bit30 */
			{20286,42,0}, /* core4 return_Stack5 bit31 */
			{16451,42,0}, /* core4 return_Stack5 bit32 */
			{20285,42,0}, /* core4 return_Stack5 bit33 */
			{20284,42,0}, /* core4 return_Stack5 bit34 */
			{20283,42,0}, /* core4 return_Stack5 bit35 */
			{20326,42,0}, /* core4 return_Stack5 bit36 */
			{20325,42,0}, /* core4 return_Stack5 bit37 */
			{20324,42,0}, /* core4 return_Stack5 bit38 */
			{20323,42,0}, /* core4 return_Stack5 bit39 */
			{20338,42,0}, /* core4 return_Stack5 bit40 */
			{20337,42,0}, /* core4 return_Stack5 bit41 */
			{20336,42,0}, /* core4 return_Stack5 bit42 */
			{20335,42,0}, /* core4 return_Stack5 bit43 */
			{20354,42,0}, /* core4 return_Stack5 bit44 */
			{20353,42,0}, /* core4 return_Stack5 bit45 */
			{20352,42,0}, /* core4 return_Stack5 bit46 */
			{20351,42,0}, /* core4 return_Stack5 bit47 */
			{13580,42,1}, /* core4 return_Stack5 bit48 */
			{    0, 0,2}, /* core4 return_Stack5 bit49 */
			{    0, 0,2}, /* core4 return_Stack5 bit50 */
			{    0, 0,2}, /* core4 return_Stack5 bit51 */
			{    0, 0,2}, /* core4 return_Stack5 bit52 */
			{    0, 0,2}, /* core4 return_Stack5 bit53 */
			{    0, 0,2}, /* core4 return_Stack5 bit54 */
			{    0, 0,2}, /* core4 return_Stack5 bit55 */
			{    0, 0,2}, /* core4 return_Stack5 bit56 */
			{    0, 0,2}, /* core4 return_Stack5 bit57 */
			{    0, 0,2}, /* core4 return_Stack5 bit58 */
			{    0, 0,2}, /* core4 return_Stack5 bit59 */
			{    0, 0,2}, /* core4 return_Stack5 bit60 */
			{    0, 0,2}, /* core4 return_Stack5 bit61 */
			{    0, 0,2}, /* core4 return_Stack5 bit62 */
			{    0, 0,2}, /* core4 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{20358,42,0}, /* core4 return_Stack6 bit0 */
			{20357,42,0}, /* core4 return_Stack6 bit1 */
			{20356,42,0}, /* core4 return_Stack6 bit2 */
			{20355,42,0}, /* core4 return_Stack6 bit3 */
			{20258,42,0}, /* core4 return_Stack6 bit4 */
			{20257,42,0}, /* core4 return_Stack6 bit5 */
			{20256,42,0}, /* core4 return_Stack6 bit6 */
			{20255,42,0}, /* core4 return_Stack6 bit7 */
			{16436,42,0}, /* core4 return_Stack6 bit8 */
			{20410,42,0}, /* core4 return_Stack6 bit9 */
			{16435,42,0}, /* core4 return_Stack6 bit10 */
			{20409,42,0}, /* core4 return_Stack6 bit11 */
			{20408,42,0}, /* core4 return_Stack6 bit12 */
			{20407,42,0}, /* core4 return_Stack6 bit13 */
			{16356,42,0}, /* core4 return_Stack6 bit14 */
			{16355,42,0}, /* core4 return_Stack6 bit15 */
			{16358,42,0}, /* core4 return_Stack6 bit16 */
			{16357,42,0}, /* core4 return_Stack6 bit17 */
			{20386,42,0}, /* core4 return_Stack6 bit18 */
			{20385,42,0}, /* core4 return_Stack6 bit19 */
			{20384,42,0}, /* core4 return_Stack6 bit20 */
			{20383,42,0}, /* core4 return_Stack6 bit21 */
			{20382,42,0}, /* core4 return_Stack6 bit22 */
			{20381,42,0}, /* core4 return_Stack6 bit23 */
			{20380,42,0}, /* core4 return_Stack6 bit24 */
			{20379,42,0}, /* core4 return_Stack6 bit25 */
			{20278,42,0}, /* core4 return_Stack6 bit26 */
			{20277,42,0}, /* core4 return_Stack6 bit27 */
			{20276,42,0}, /* core4 return_Stack6 bit28 */
			{20275,42,0}, /* core4 return_Stack6 bit29 */
			{16448,42,0}, /* core4 return_Stack6 bit30 */
			{16447,42,0}, /* core4 return_Stack6 bit31 */
			{16450,42,0}, /* core4 return_Stack6 bit32 */
			{16449,42,0}, /* core4 return_Stack6 bit33 */
			{20302,42,0}, /* core4 return_Stack6 bit34 */
			{20301,42,0}, /* core4 return_Stack6 bit35 */
			{20300,42,0}, /* core4 return_Stack6 bit36 */
			{20299,42,0}, /* core4 return_Stack6 bit37 */
			{20334,42,0}, /* core4 return_Stack6 bit38 */
			{20333,42,0}, /* core4 return_Stack6 bit39 */
			{20332,42,0}, /* core4 return_Stack6 bit40 */
			{20331,42,0}, /* core4 return_Stack6 bit41 */
			{20346,42,0}, /* core4 return_Stack6 bit42 */
			{20345,42,0}, /* core4 return_Stack6 bit43 */
			{20344,42,0}, /* core4 return_Stack6 bit44 */
			{20343,42,0}, /* core4 return_Stack6 bit45 */
			{16442,42,0}, /* core4 return_Stack6 bit46 */
			{16441,42,0}, /* core4 return_Stack6 bit47 */
			{13582,42,1}, /* core4 return_Stack6 bit48 */
			{    0, 0,2}, /* core4 return_Stack6 bit49 */
			{    0, 0,2}, /* core4 return_Stack6 bit50 */
			{    0, 0,2}, /* core4 return_Stack6 bit51 */
			{    0, 0,2}, /* core4 return_Stack6 bit52 */
			{    0, 0,2}, /* core4 return_Stack6 bit53 */
			{    0, 0,2}, /* core4 return_Stack6 bit54 */
			{    0, 0,2}, /* core4 return_Stack6 bit55 */
			{    0, 0,2}, /* core4 return_Stack6 bit56 */
			{    0, 0,2}, /* core4 return_Stack6 bit57 */
			{    0, 0,2}, /* core4 return_Stack6 bit58 */
			{    0, 0,2}, /* core4 return_Stack6 bit59 */
			{    0, 0,2}, /* core4 return_Stack6 bit60 */
			{    0, 0,2}, /* core4 return_Stack6 bit61 */
			{    0, 0,2}, /* core4 return_Stack6 bit62 */
			{    0, 0,2}, /* core4 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{20294,42,0}, /* core4 return_Stack7 bit0 */
			{20293,42,0}, /* core4 return_Stack7 bit1 */
			{20292,42,0}, /* core4 return_Stack7 bit2 */
			{20291,42,0}, /* core4 return_Stack7 bit3 */
			{20274,42,0}, /* core4 return_Stack7 bit4 */
			{20273,42,0}, /* core4 return_Stack7 bit5 */
			{20290,42,0}, /* core4 return_Stack7 bit6 */
			{20272,42,0}, /* core4 return_Stack7 bit7 */
			{20271,42,0}, /* core4 return_Stack7 bit8 */
			{20414,42,0}, /* core4 return_Stack7 bit9 */
			{20413,42,0}, /* core4 return_Stack7 bit10 */
			{20412,42,0}, /* core4 return_Stack7 bit11 */
			{20411,42,0}, /* core4 return_Stack7 bit12 */
			{20406,42,0}, /* core4 return_Stack7 bit13 */
			{20405,42,0}, /* core4 return_Stack7 bit14 */
			{20404,42,0}, /* core4 return_Stack7 bit15 */
			{20403,42,0}, /* core4 return_Stack7 bit16 */
			{20422,42,0}, /* core4 return_Stack7 bit17 */
			{20421,42,0}, /* core4 return_Stack7 bit18 */
			{20426,42,0}, /* core4 return_Stack7 bit19 */
			{20420,42,0}, /* core4 return_Stack7 bit20 */
			{20419,42,0}, /* core4 return_Stack7 bit21 */
			{20425,42,0}, /* core4 return_Stack7 bit22 */
			{20424,42,0}, /* core4 return_Stack7 bit23 */
			{20423,42,0}, /* core4 return_Stack7 bit24 */
			{16502,42,0}, /* core4 return_Stack7 bit25 */
			{16501,42,0}, /* core4 return_Stack7 bit26 */
			{16510,42,0}, /* core4 return_Stack7 bit27 */
			{16509,42,0}, /* core4 return_Stack7 bit28 */
			{16516,42,0}, /* core4 return_Stack7 bit29 */
			{16515,42,0}, /* core4 return_Stack7 bit30 */
			{20289,42,0}, /* core4 return_Stack7 bit31 */
			{13575,42,1}, /* core4 return_Stack7 bit32 */
			{20288,42,0}, /* core4 return_Stack7 bit33 */
			{20287,42,0}, /* core4 return_Stack7 bit34 */
			{20322,42,0}, /* core4 return_Stack7 bit35 */
			{20321,42,0}, /* core4 return_Stack7 bit36 */
			{20320,42,0}, /* core4 return_Stack7 bit37 */
			{20319,42,0}, /* core4 return_Stack7 bit38 */
			{20330,42,0}, /* core4 return_Stack7 bit39 */
			{20329,42,0}, /* core4 return_Stack7 bit40 */
			{20328,42,0}, /* core4 return_Stack7 bit41 */
			{20327,42,0}, /* core4 return_Stack7 bit42 */
			{20350,42,0}, /* core4 return_Stack7 bit43 */
			{20349,42,0}, /* core4 return_Stack7 bit44 */
			{20348,42,0}, /* core4 return_Stack7 bit45 */
			{20347,42,0}, /* core4 return_Stack7 bit46 */
			{13579,42,1}, /* core4 return_Stack7 bit47 */
			{13578,42,1}, /* core4 return_Stack7 bit48 */
			{    0, 0,2}, /* core4 return_Stack7 bit49 */
			{    0, 0,2}, /* core4 return_Stack7 bit50 */
			{    0, 0,2}, /* core4 return_Stack7 bit51 */
			{    0, 0,2}, /* core4 return_Stack7 bit52 */
			{    0, 0,2}, /* core4 return_Stack7 bit53 */
			{    0, 0,2}, /* core4 return_Stack7 bit54 */
			{    0, 0,2}, /* core4 return_Stack7 bit55 */
			{    0, 0,2}, /* core4 return_Stack7 bit56 */
			{    0, 0,2}, /* core4 return_Stack7 bit57 */
			{    0, 0,2}, /* core4 return_Stack7 bit58 */
			{    0, 0,2}, /* core4 return_Stack7 bit59 */
			{    0, 0,2}, /* core4 return_Stack7 bit60 */
			{    0, 0,2}, /* core4 return_Stack7 bit61 */
			{    0, 0,2}, /* core4 return_Stack7 bit62 */
			{    0, 0,2}, /* core4 return_Stack7 bit63 */
			}},
			.L2_parity_err_count = {{
			{ 6781, 8,0}, /* core4 L2_parity_err_count bit0 */
			{ 6780, 8,0}, /* core4 L2_parity_err_count bit1 */
			{ 6779, 8,0}, /* core4 L2_parity_err_count bit2 */
			{ 6778, 8,0}, /* core4 L2_parity_err_count bit3 */
			{ 6777, 8,0}, /* core4 L2_parity_err_count bit4 */
			{ 6776, 8,0}, /* core4 L2_parity_err_count bit5 */
			{ 6775, 8,0}, /* core4 L2_parity_err_count bit6 */
			{ 6774, 8,0}, /* core4 L2_parity_err_count bit7 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit8 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit9 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit10 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit11 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit12 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit13 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit14 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit15 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit16 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit17 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit18 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit19 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit20 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit21 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit22 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit23 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit24 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit25 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit26 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit27 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit28 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit29 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit30 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit31 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit32 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit33 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit34 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit35 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit36 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit37 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit38 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit39 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit40 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit41 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit42 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit43 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit44 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit45 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit46 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit47 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit48 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit49 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit50 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit51 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit52 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit53 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit54 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit55 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit56 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit57 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit58 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit59 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit60 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit61 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit62 */
			{    0, 0,2}, /* core4 L2_parity_err_count bit63 */
			}},
			.L2_parity_index = {{
			{ 6596, 8,0}, /* core4 L2_parity_index bit0 */
			{ 6595, 8,0}, /* core4 L2_parity_index bit1 */
			{ 6594, 8,0}, /* core4 L2_parity_index bit2 */
			{ 6593, 8,0}, /* core4 L2_parity_index bit3 */
			{ 6592, 8,0}, /* core4 L2_parity_index bit4 */
			{ 6591, 8,0}, /* core4 L2_parity_index bit5 */
			{ 6590, 8,0}, /* core4 L2_parity_index bit6 */
			{ 6589, 8,0}, /* core4 L2_parity_index bit7 */
			{ 6636, 8,0}, /* core4 L2_parity_index bit8 */
			{ 6635, 8,0}, /* core4 L2_parity_index bit9 */
			{ 6634, 8,0}, /* core4 L2_parity_index bit10 */
			{ 6633, 8,0}, /* core4 L2_parity_index bit11 */
			{    0, 0,2}, /* core4 L2_parity_index bit12 */
			{    0, 0,2}, /* core4 L2_parity_index bit13 */
			{    0, 0,2}, /* core4 L2_parity_index bit14 */
			{    0, 0,2}, /* core4 L2_parity_index bit15 */
			{    0, 0,2}, /* core4 L2_parity_index bit16 */
			{    0, 0,2}, /* core4 L2_parity_index bit17 */
			{    0, 0,2}, /* core4 L2_parity_index bit18 */
			{    0, 0,2}, /* core4 L2_parity_index bit19 */
			{    0, 0,2}, /* core4 L2_parity_index bit20 */
			{    0, 0,2}, /* core4 L2_parity_index bit21 */
			{    0, 0,2}, /* core4 L2_parity_index bit22 */
			{    0, 0,2}, /* core4 L2_parity_index bit23 */
			{    0, 0,2}, /* core4 L2_parity_index bit24 */
			{    0, 0,2}, /* core4 L2_parity_index bit25 */
			{    0, 0,2}, /* core4 L2_parity_index bit26 */
			{    0, 0,2}, /* core4 L2_parity_index bit27 */
			{    0, 0,2}, /* core4 L2_parity_index bit28 */
			{    0, 0,2}, /* core4 L2_parity_index bit29 */
			{    0, 0,2}, /* core4 L2_parity_index bit30 */
			{    0, 0,2}, /* core4 L2_parity_index bit31 */
			{    0, 0,2}, /* core4 L2_parity_index bit32 */
			{    0, 0,2}, /* core4 L2_parity_index bit33 */
			{    0, 0,2}, /* core4 L2_parity_index bit34 */
			{    0, 0,2}, /* core4 L2_parity_index bit35 */
			{    0, 0,2}, /* core4 L2_parity_index bit36 */
			{    0, 0,2}, /* core4 L2_parity_index bit37 */
			{    0, 0,2}, /* core4 L2_parity_index bit38 */
			{    0, 0,2}, /* core4 L2_parity_index bit39 */
			{    0, 0,2}, /* core4 L2_parity_index bit40 */
			{    0, 0,2}, /* core4 L2_parity_index bit41 */
			{    0, 0,2}, /* core4 L2_parity_index bit42 */
			{    0, 0,2}, /* core4 L2_parity_index bit43 */
			{    0, 0,2}, /* core4 L2_parity_index bit44 */
			{    0, 0,2}, /* core4 L2_parity_index bit45 */
			{    0, 0,2}, /* core4 L2_parity_index bit46 */
			{    0, 0,2}, /* core4 L2_parity_index bit47 */
			{    0, 0,2}, /* core4 L2_parity_index bit48 */
			{    0, 0,2}, /* core4 L2_parity_index bit49 */
			{    0, 0,2}, /* core4 L2_parity_index bit50 */
			{    0, 0,2}, /* core4 L2_parity_index bit51 */
			{    0, 0,2}, /* core4 L2_parity_index bit52 */
			{    0, 0,2}, /* core4 L2_parity_index bit53 */
			{    0, 0,2}, /* core4 L2_parity_index bit54 */
			{    0, 0,2}, /* core4 L2_parity_index bit55 */
			{    0, 0,2}, /* core4 L2_parity_index bit56 */
			{    0, 0,2}, /* core4 L2_parity_index bit57 */
			{    0, 0,2}, /* core4 L2_parity_index bit58 */
			{    0, 0,2}, /* core4 L2_parity_index bit59 */
			{    0, 0,2}, /* core4 L2_parity_index bit60 */
			{    0, 0,2}, /* core4 L2_parity_index bit61 */
			{    0, 0,2}, /* core4 L2_parity_index bit62 */
			{    0, 0,2}, /* core4 L2_parity_index bit63 */
			}},
			.L2_parity_way = {{
			{ 6629, 8,0}, /* core4 L2_parity_way bit0 */
			{ 6515, 8,0}, /* core4 L2_parity_way bit1 */
			{    0, 0,2}, /* core4 L2_parity_way bit2 */
			{    0, 0,2}, /* core4 L2_parity_way bit3 */
			{    0, 0,2}, /* core4 L2_parity_way bit4 */
			{    0, 0,2}, /* core4 L2_parity_way bit5 */
			{    0, 0,2}, /* core4 L2_parity_way bit6 */
			{    0, 0,2}, /* core4 L2_parity_way bit7 */
			{    0, 0,2}, /* core4 L2_parity_way bit8 */
			{    0, 0,2}, /* core4 L2_parity_way bit9 */
			{    0, 0,2}, /* core4 L2_parity_way bit10 */
			{    0, 0,2}, /* core4 L2_parity_way bit11 */
			{    0, 0,2}, /* core4 L2_parity_way bit12 */
			{    0, 0,2}, /* core4 L2_parity_way bit13 */
			{    0, 0,2}, /* core4 L2_parity_way bit14 */
			{    0, 0,2}, /* core4 L2_parity_way bit15 */
			{    0, 0,2}, /* core4 L2_parity_way bit16 */
			{    0, 0,2}, /* core4 L2_parity_way bit17 */
			{    0, 0,2}, /* core4 L2_parity_way bit18 */
			{    0, 0,2}, /* core4 L2_parity_way bit19 */
			{    0, 0,2}, /* core4 L2_parity_way bit20 */
			{    0, 0,2}, /* core4 L2_parity_way bit21 */
			{    0, 0,2}, /* core4 L2_parity_way bit22 */
			{    0, 0,2}, /* core4 L2_parity_way bit23 */
			{    0, 0,2}, /* core4 L2_parity_way bit24 */
			{    0, 0,2}, /* core4 L2_parity_way bit25 */
			{    0, 0,2}, /* core4 L2_parity_way bit26 */
			{    0, 0,2}, /* core4 L2_parity_way bit27 */
			{    0, 0,2}, /* core4 L2_parity_way bit28 */
			{    0, 0,2}, /* core4 L2_parity_way bit29 */
			{    0, 0,2}, /* core4 L2_parity_way bit30 */
			{    0, 0,2}, /* core4 L2_parity_way bit31 */
			{    0, 0,2}, /* core4 L2_parity_way bit32 */
			{    0, 0,2}, /* core4 L2_parity_way bit33 */
			{    0, 0,2}, /* core4 L2_parity_way bit34 */
			{    0, 0,2}, /* core4 L2_parity_way bit35 */
			{    0, 0,2}, /* core4 L2_parity_way bit36 */
			{    0, 0,2}, /* core4 L2_parity_way bit37 */
			{    0, 0,2}, /* core4 L2_parity_way bit38 */
			{    0, 0,2}, /* core4 L2_parity_way bit39 */
			{    0, 0,2}, /* core4 L2_parity_way bit40 */
			{    0, 0,2}, /* core4 L2_parity_way bit41 */
			{    0, 0,2}, /* core4 L2_parity_way bit42 */
			{    0, 0,2}, /* core4 L2_parity_way bit43 */
			{    0, 0,2}, /* core4 L2_parity_way bit44 */
			{    0, 0,2}, /* core4 L2_parity_way bit45 */
			{    0, 0,2}, /* core4 L2_parity_way bit46 */
			{    0, 0,2}, /* core4 L2_parity_way bit47 */
			{    0, 0,2}, /* core4 L2_parity_way bit48 */
			{    0, 0,2}, /* core4 L2_parity_way bit49 */
			{    0, 0,2}, /* core4 L2_parity_way bit50 */
			{    0, 0,2}, /* core4 L2_parity_way bit51 */
			{    0, 0,2}, /* core4 L2_parity_way bit52 */
			{    0, 0,2}, /* core4 L2_parity_way bit53 */
			{    0, 0,2}, /* core4 L2_parity_way bit54 */
			{    0, 0,2}, /* core4 L2_parity_way bit55 */
			{    0, 0,2}, /* core4 L2_parity_way bit56 */
			{    0, 0,2}, /* core4 L2_parity_way bit57 */
			{    0, 0,2}, /* core4 L2_parity_way bit58 */
			{    0, 0,2}, /* core4 L2_parity_way bit59 */
			{    0, 0,2}, /* core4 L2_parity_way bit60 */
			{    0, 0,2}, /* core4 L2_parity_way bit61 */
			{    0, 0,2}, /* core4 L2_parity_way bit62 */
			{    0, 0,2}, /* core4 L2_parity_way bit63 */
			}},
			.L2_parity_banks = {{
			{ 6797, 8,0}, /* core4 L2_parity_banks bit0 */
			{ 6796, 8,0}, /* core4 L2_parity_banks bit1 */
			{ 6795, 8,0}, /* core4 L2_parity_banks bit2 */
			{ 6794, 8,0}, /* core4 L2_parity_banks bit3 */
			{ 6793, 8,0}, /* core4 L2_parity_banks bit4 */
			{ 6792, 8,0}, /* core4 L2_parity_banks bit5 */
			{ 6791, 8,0}, /* core4 L2_parity_banks bit6 */
			{ 6790, 8,0}, /* core4 L2_parity_banks bit7 */
			{ 6789, 8,0}, /* core4 L2_parity_banks bit8 */
			{ 6788, 8,0}, /* core4 L2_parity_banks bit9 */
			{ 6787, 8,0}, /* core4 L2_parity_banks bit10 */
			{ 6786, 8,0}, /* core4 L2_parity_banks bit11 */
			{ 6785, 8,0}, /* core4 L2_parity_banks bit12 */
			{ 6784, 8,0}, /* core4 L2_parity_banks bit13 */
			{ 6783, 8,0}, /* core4 L2_parity_banks bit14 */
			{ 6782, 8,0}, /* core4 L2_parity_banks bit15 */
			{    0, 0,2}, /* core4 L2_parity_banks bit16 */
			{    0, 0,2}, /* core4 L2_parity_banks bit17 */
			{    0, 0,2}, /* core4 L2_parity_banks bit18 */
			{    0, 0,2}, /* core4 L2_parity_banks bit19 */
			{    0, 0,2}, /* core4 L2_parity_banks bit20 */
			{    0, 0,2}, /* core4 L2_parity_banks bit21 */
			{    0, 0,2}, /* core4 L2_parity_banks bit22 */
			{    0, 0,2}, /* core4 L2_parity_banks bit23 */
			{    0, 0,2}, /* core4 L2_parity_banks bit24 */
			{    0, 0,2}, /* core4 L2_parity_banks bit25 */
			{    0, 0,2}, /* core4 L2_parity_banks bit26 */
			{    0, 0,2}, /* core4 L2_parity_banks bit27 */
			{    0, 0,2}, /* core4 L2_parity_banks bit28 */
			{    0, 0,2}, /* core4 L2_parity_banks bit29 */
			{    0, 0,2}, /* core4 L2_parity_banks bit30 */
			{    0, 0,2}, /* core4 L2_parity_banks bit31 */
			{    0, 0,2}, /* core4 L2_parity_banks bit32 */
			{    0, 0,2}, /* core4 L2_parity_banks bit33 */
			{    0, 0,2}, /* core4 L2_parity_banks bit34 */
			{    0, 0,2}, /* core4 L2_parity_banks bit35 */
			{    0, 0,2}, /* core4 L2_parity_banks bit36 */
			{    0, 0,2}, /* core4 L2_parity_banks bit37 */
			{    0, 0,2}, /* core4 L2_parity_banks bit38 */
			{    0, 0,2}, /* core4 L2_parity_banks bit39 */
			{    0, 0,2}, /* core4 L2_parity_banks bit40 */
			{    0, 0,2}, /* core4 L2_parity_banks bit41 */
			{    0, 0,2}, /* core4 L2_parity_banks bit42 */
			{    0, 0,2}, /* core4 L2_parity_banks bit43 */
			{    0, 0,2}, /* core4 L2_parity_banks bit44 */
			{    0, 0,2}, /* core4 L2_parity_banks bit45 */
			{    0, 0,2}, /* core4 L2_parity_banks bit46 */
			{    0, 0,2}, /* core4 L2_parity_banks bit47 */
			{    0, 0,2}, /* core4 L2_parity_banks bit48 */
			{    0, 0,2}, /* core4 L2_parity_banks bit49 */
			{    0, 0,2}, /* core4 L2_parity_banks bit50 */
			{    0, 0,2}, /* core4 L2_parity_banks bit51 */
			{    0, 0,2}, /* core4 L2_parity_banks bit52 */
			{    0, 0,2}, /* core4 L2_parity_banks bit53 */
			{    0, 0,2}, /* core4 L2_parity_banks bit54 */
			{    0, 0,2}, /* core4 L2_parity_banks bit55 */
			{    0, 0,2}, /* core4 L2_parity_banks bit56 */
			{    0, 0,2}, /* core4 L2_parity_banks bit57 */
			{    0, 0,2}, /* core4 L2_parity_banks bit58 */
			{    0, 0,2}, /* core4 L2_parity_banks bit59 */
			{    0, 0,2}, /* core4 L2_parity_banks bit60 */
			{    0, 0,2}, /* core4 L2_parity_banks bit61 */
			{    0, 0,2}, /* core4 L2_parity_banks bit62 */
			{    0, 0,2}, /* core4 L2_parity_banks bit63 */
			}},
	},
	{		/* core 5 */ 
			.pc = {{
			{  392,43,1}, /* core5 pc bit0 */
			{  391,43,1}, /* core5 pc bit1 */
			{  390,43,1}, /* core5 pc bit2 */
			{  389,43,1}, /* core5 pc bit3 */
			{  440,43,1}, /* core5 pc bit4 */
			{  416,43,1}, /* core5 pc bit5 */
			{  439,43,1}, /* core5 pc bit6 */
			{  415,43,1}, /* core5 pc bit7 */
			{  388,43,1}, /* core5 pc bit8 */
			{  414,43,1}, /* core5 pc bit9 */
			{  344,43,1}, /* core5 pc bit10 */
			{  360,43,1}, /* core5 pc bit11 */
			{  359,43,1}, /* core5 pc bit12 */
			{  358,43,1}, /* core5 pc bit13 */
			{  343,43,1}, /* core5 pc bit14 */
			{  342,43,1}, /* core5 pc bit15 */
			{  413,43,1}, /* core5 pc bit16 */
			{  296,43,1}, /* core5 pc bit17 */
			{  357,43,1}, /* core5 pc bit18 */
			{  387,43,1}, /* core5 pc bit19 */
			{  356,43,1}, /* core5 pc bit20 */
			{  355,43,1}, /* core5 pc bit21 */
			{  412,43,1}, /* core5 pc bit22 */
			{  354,43,1}, /* core5 pc bit23 */
			{  353,43,1}, /* core5 pc bit24 */
			{  376,43,1}, /* core5 pc bit25 */
			{  352,43,1}, /* core5 pc bit26 */
			{  295,43,1}, /* core5 pc bit27 */
			{  386,43,1}, /* core5 pc bit28 */
			{  341,43,1}, /* core5 pc bit29 */
			{  385,43,1}, /* core5 pc bit30 */
			{  351,43,1}, /* core5 pc bit31 */
			{  264,43,1}, /* core5 pc bit32 */
			{  112,43,1}, /* core5 pc bit33 */
			{  263,43,1}, /* core5 pc bit34 */
			{  111,43,1}, /* core5 pc bit35 */
			{  172,43,1}, /* core5 pc bit36 */
			{  180,43,1}, /* core5 pc bit37 */
			{  262,43,1}, /* core5 pc bit38 */
			{  146,43,1}, /* core5 pc bit39 */
			{  179,43,1}, /* core5 pc bit40 */
			{  145,43,1}, /* core5 pc bit41 */
			{  136,43,1}, /* core5 pc bit42 */
			{  261,43,1}, /* core5 pc bit43 */
			{  260,43,1}, /* core5 pc bit44 */
			{  259,43,1}, /* core5 pc bit45 */
			{  144,43,1}, /* core5 pc bit46 */
			{  143,43,1}, /* core5 pc bit47 */
			{  438,43,1}, /* core5 pc bit48 */
			{  110,43,1}, /* core5 pc bit49 */
			{  207,43,1}, /* core5 pc bit50 */
			{  206,43,1}, /* core5 pc bit51 */
			{  411,43,1}, /* core5 pc bit52 */
			{  205,43,1}, /* core5 pc bit53 */
			{  109,43,1}, /* core5 pc bit54 */
			{  204,43,1}, /* core5 pc bit55 */
			{  258,43,1}, /* core5 pc bit56 */
			{  203,43,1}, /* core5 pc bit57 */
			{  178,43,1}, /* core5 pc bit58 */
			{  177,43,1}, /* core5 pc bit59 */
			{  202,43,1}, /* core5 pc bit60 */
			{  201,43,1}, /* core5 pc bit61 */
			{  200,43,1}, /* core5 pc bit62 */
			{  257,43,1}, /* core5 pc bit63 */
			}},
			.sp32 = {{
			{37603,44,0}, /* core5 sp32 bit0 */
			{37602,44,0}, /* core5 sp32 bit1 */
			{28162,44,1}, /* core5 sp32 bit2 */
			{28161,44,1}, /* core5 sp32 bit3 */
			{28160,44,1}, /* core5 sp32 bit4 */
			{28092,44,1}, /* core5 sp32 bit5 */
			{28159,44,1}, /* core5 sp32 bit6 */
			{28091,44,1}, /* core5 sp32 bit7 */
			{37601,44,0}, /* core5 sp32 bit8 */
			{37600,44,0}, /* core5 sp32 bit9 */
			{28158,44,1}, /* core5 sp32 bit10 */
			{28151,44,1}, /* core5 sp32 bit11 */
			{37583,44,0}, /* core5 sp32 bit12 */
			{37582,44,0}, /* core5 sp32 bit13 */
			{37581,44,0}, /* core5 sp32 bit14 */
			{37580,44,0}, /* core5 sp32 bit15 */
			{28135,44,1}, /* core5 sp32 bit16 */
			{28150,44,1}, /* core5 sp32 bit17 */
			{28131,44,1}, /* core5 sp32 bit18 */
			{28132,44,1}, /* core5 sp32 bit19 */
			{28144,44,1}, /* core5 sp32 bit20 */
			{28133,44,1}, /* core5 sp32 bit21 */
			{31013,43,1}, /* core5 sp32 bit22 */
			{31012,43,1}, /* core5 sp32 bit23 */
			{28130,44,1}, /* core5 sp32 bit24 */
			{28134,44,1}, /* core5 sp32 bit25 */
			{31011,43,1}, /* core5 sp32 bit26 */
			{31010,43,1}, /* core5 sp32 bit27 */
			{37579,44,0}, /* core5 sp32 bit28 */
			{37578,44,0}, /* core5 sp32 bit29 */
			{37593,44,0}, /* core5 sp32 bit30 */
			{37592,44,0}, /* core5 sp32 bit31 */
			{30913,43,1}, /* core5 sp32 bit32 */
			{30912,43,1}, /* core5 sp32 bit33 */
			{30911,43,1}, /* core5 sp32 bit34 */
			{30910,43,1}, /* core5 sp32 bit35 */
			{37623,44,0}, /* core5 sp32 bit36 */
			{37622,44,0}, /* core5 sp32 bit37 */
			{28277,44,1}, /* core5 sp32 bit38 */
			{37709,44,0}, /* core5 sp32 bit39 */
			{28274,44,1}, /* core5 sp32 bit40 */
			{37611,44,0}, /* core5 sp32 bit41 */
			{37625,44,0}, /* core5 sp32 bit42 */
			{37624,44,0}, /* core5 sp32 bit43 */
			{37708,44,0}, /* core5 sp32 bit44 */
			{37711,44,0}, /* core5 sp32 bit45 */
			{37610,44,0}, /* core5 sp32 bit46 */
			{37710,44,0}, /* core5 sp32 bit47 */
			{28278,44,1}, /* core5 sp32 bit48 */
			{28300,44,1}, /* core5 sp32 bit49 */
			{28296,44,1}, /* core5 sp32 bit50 */
			{28302,44,1}, /* core5 sp32 bit51 */
			{28283,44,1}, /* core5 sp32 bit52 */
			{28170,44,1}, /* core5 sp32 bit53 */
			{28281,44,1}, /* core5 sp32 bit54 */
			{28310,44,1}, /* core5 sp32 bit55 */
			{28279,44,1}, /* core5 sp32 bit56 */
			{28301,44,1}, /* core5 sp32 bit57 */
			{28169,44,1}, /* core5 sp32 bit58 */
			{28303,44,1}, /* core5 sp32 bit59 */
			{28171,44,1}, /* core5 sp32 bit60 */
			{28168,44,1}, /* core5 sp32 bit61 */
			{28295,44,1}, /* core5 sp32 bit62 */
			{28297,44,1}, /* core5 sp32 bit63 */
			}},
			.fp32 = {{
			{28348,44,1}, /* core5 fp32 bit0 */
			{28349,44,1}, /* core5 fp32 bit1 */
			{37719,44,0}, /* core5 fp32 bit2 */
			{37718,44,0}, /* core5 fp32 bit3 */
			{37721,44,0}, /* core5 fp32 bit4 */
			{37720,44,0}, /* core5 fp32 bit5 */
			{28353,44,1}, /* core5 fp32 bit6 */
			{28351,44,1}, /* core5 fp32 bit7 */
			{28352,44,1}, /* core5 fp32 bit8 */
			{28350,44,1}, /* core5 fp32 bit9 */
			{37751,44,0}, /* core5 fp32 bit10 */
			{37750,44,0}, /* core5 fp32 bit11 */
			{37747,44,0}, /* core5 fp32 bit12 */
			{37746,44,0}, /* core5 fp32 bit13 */
			{31129,43,1}, /* core5 fp32 bit14 */
			{31128,43,1}, /* core5 fp32 bit15 */
			{31127,43,1}, /* core5 fp32 bit16 */
			{31126,43,1}, /* core5 fp32 bit17 */
			{37745,44,0}, /* core5 fp32 bit18 */
			{37744,44,0}, /* core5 fp32 bit19 */
			{31125,43,1}, /* core5 fp32 bit20 */
			{31124,43,1}, /* core5 fp32 bit21 */
			{28375,44,1}, /* core5 fp32 bit22 */
			{31123,43,1}, /* core5 fp32 bit23 */
			{31122,43,1}, /* core5 fp32 bit24 */
			{31121,43,1}, /* core5 fp32 bit25 */
			{31120,43,1}, /* core5 fp32 bit26 */
			{31119,43,1}, /* core5 fp32 bit27 */
			{31118,43,1}, /* core5 fp32 bit28 */
			{28374,44,1}, /* core5 fp32 bit29 */
			{37749,44,0}, /* core5 fp32 bit30 */
			{37748,44,0}, /* core5 fp32 bit31 */
			{37833,43,1}, /* core5 fp32 bit32 */
			{37832,43,1}, /* core5 fp32 bit33 */
			{37831,43,1}, /* core5 fp32 bit34 */
			{37830,43,1}, /* core5 fp32 bit35 */
			{28509,44,1}, /* core5 fp32 bit36 */
			{28510,44,1}, /* core5 fp32 bit37 */
			{37645,44,0}, /* core5 fp32 bit38 */
			{37829,43,1}, /* core5 fp32 bit39 */
			{37828,43,1}, /* core5 fp32 bit40 */
			{37644,44,0}, /* core5 fp32 bit41 */
			{37827,43,1}, /* core5 fp32 bit42 */
			{37641,44,0}, /* core5 fp32 bit43 */
			{37640,44,0}, /* core5 fp32 bit44 */
			{28508,44,1}, /* core5 fp32 bit45 */
			{28507,44,1}, /* core5 fp32 bit46 */
			{37643,44,0}, /* core5 fp32 bit47 */
			{37642,44,0}, /* core5 fp32 bit48 */
			{28511,44,1}, /* core5 fp32 bit49 */
			{28486,44,1}, /* core5 fp32 bit50 */
			{37826,43,1}, /* core5 fp32 bit51 */
			{28476,44,1}, /* core5 fp32 bit52 */
			{28472,44,1}, /* core5 fp32 bit53 */
			{28475,44,1}, /* core5 fp32 bit54 */
			{28489,44,1}, /* core5 fp32 bit55 */
			{28474,44,1}, /* core5 fp32 bit56 */
			{28453,44,1}, /* core5 fp32 bit57 */
			{28484,44,1}, /* core5 fp32 bit58 */
			{28454,44,1}, /* core5 fp32 bit59 */
			{28487,44,1}, /* core5 fp32 bit60 */
			{28488,44,1}, /* core5 fp32 bit61 */
			{28485,44,1}, /* core5 fp32 bit62 */
			{28473,44,1}, /* core5 fp32 bit63 */
			}},
			.fp64 = {{
			{28058,44,1}, /* core5 fp64 bit0 */
			{28057,44,1}, /* core5 fp64 bit1 */
			{28059,44,1}, /* core5 fp64 bit2 */
			{28054,44,1}, /* core5 fp64 bit3 */
			{31029,43,1}, /* core5 fp64 bit4 */
			{31028,43,1}, /* core5 fp64 bit5 */
			{31027,43,1}, /* core5 fp64 bit6 */
			{31026,43,1}, /* core5 fp64 bit7 */
			{28056,44,1}, /* core5 fp64 bit8 */
			{28055,44,1}, /* core5 fp64 bit9 */
			{37529,43,1}, /* core5 fp64 bit10 */
			{28060,44,1}, /* core5 fp64 bit11 */
			{27855,44,1}, /* core5 fp64 bit12 */
			{37528,43,1}, /* core5 fp64 bit13 */
			{37527,43,1}, /* core5 fp64 bit14 */
			{37526,43,1}, /* core5 fp64 bit15 */
			{30993,43,1}, /* core5 fp64 bit16 */
			{30992,43,1}, /* core5 fp64 bit17 */
			{37525,43,1}, /* core5 fp64 bit18 */
			{37524,43,1}, /* core5 fp64 bit19 */
			{37523,43,1}, /* core5 fp64 bit20 */
			{37522,43,1}, /* core5 fp64 bit21 */
			{30991,43,1}, /* core5 fp64 bit22 */
			{30990,43,1}, /* core5 fp64 bit23 */
			{27845,44,1}, /* core5 fp64 bit24 */
			{27843,44,1}, /* core5 fp64 bit25 */
			{27844,44,1}, /* core5 fp64 bit26 */
			{27842,44,1}, /* core5 fp64 bit27 */
			{37481,44,0}, /* core5 fp64 bit28 */
			{37480,44,0}, /* core5 fp64 bit29 */
			{37487,44,0}, /* core5 fp64 bit30 */
			{37486,44,0}, /* core5 fp64 bit31 */
			{30825,43,1}, /* core5 fp64 bit32 */
			{30837,43,1}, /* core5 fp64 bit33 */
			{30836,43,1}, /* core5 fp64 bit34 */
			{30835,43,1}, /* core5 fp64 bit35 */
			{30834,43,1}, /* core5 fp64 bit36 */
			{30824,43,1}, /* core5 fp64 bit37 */
			{30823,43,1}, /* core5 fp64 bit38 */
			{30822,43,1}, /* core5 fp64 bit39 */
			{27896,44,1}, /* core5 fp64 bit40 */
			{27982,44,1}, /* core5 fp64 bit41 */
			{37325,44,0}, /* core5 fp64 bit42 */
			{37324,44,0}, /* core5 fp64 bit43 */
			{30821,43,1}, /* core5 fp64 bit44 */
			{30820,43,1}, /* core5 fp64 bit45 */
			{27894,44,1}, /* core5 fp64 bit46 */
			{30819,43,1}, /* core5 fp64 bit47 */
			{27895,44,1}, /* core5 fp64 bit48 */
			{30818,43,1}, /* core5 fp64 bit49 */
			{30833,43,1}, /* core5 fp64 bit50 */
			{30832,43,1}, /* core5 fp64 bit51 */
			{30831,43,1}, /* core5 fp64 bit52 */
			{30830,43,1}, /* core5 fp64 bit53 */
			{30841,43,1}, /* core5 fp64 bit54 */
			{27983,44,1}, /* core5 fp64 bit55 */
			{30840,43,1}, /* core5 fp64 bit56 */
			{30839,43,1}, /* core5 fp64 bit57 */
			{27984,44,1}, /* core5 fp64 bit58 */
			{30838,43,1}, /* core5 fp64 bit59 */
			{30829,43,1}, /* core5 fp64 bit60 */
			{30828,43,1}, /* core5 fp64 bit61 */
			{30827,43,1}, /* core5 fp64 bit62 */
			{30826,43,1}, /* core5 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{28040,44,1}, /* core5 sp_EL0 bit0 */
			{28038,44,1}, /* core5 sp_EL0 bit1 */
			{28039,44,1}, /* core5 sp_EL0 bit2 */
			{28035,44,1}, /* core5 sp_EL0 bit3 */
			{28037,44,1}, /* core5 sp_EL0 bit4 */
			{28036,44,1}, /* core5 sp_EL0 bit5 */
			{37399,44,0}, /* core5 sp_EL0 bit6 */
			{37398,44,0}, /* core5 sp_EL0 bit7 */
			{37397,44,0}, /* core5 sp_EL0 bit8 */
			{37396,44,0}, /* core5 sp_EL0 bit9 */
			{27861,44,1}, /* core5 sp_EL0 bit10 */
			{28029,44,1}, /* core5 sp_EL0 bit11 */
			{27859,44,1}, /* core5 sp_EL0 bit12 */
			{27851,44,1}, /* core5 sp_EL0 bit13 */
			{37467,44,0}, /* core5 sp_EL0 bit14 */
			{37466,44,0}, /* core5 sp_EL0 bit15 */
			{27858,44,1}, /* core5 sp_EL0 bit16 */
			{27860,44,1}, /* core5 sp_EL0 bit17 */
			{37479,44,0}, /* core5 sp_EL0 bit18 */
			{37478,44,0}, /* core5 sp_EL0 bit19 */
			{37475,44,0}, /* core5 sp_EL0 bit20 */
			{37474,44,0}, /* core5 sp_EL0 bit21 */
			{37471,44,0}, /* core5 sp_EL0 bit22 */
			{37470,44,0}, /* core5 sp_EL0 bit23 */
			{30989,43,1}, /* core5 sp_EL0 bit24 */
			{30988,43,1}, /* core5 sp_EL0 bit25 */
			{30987,43,1}, /* core5 sp_EL0 bit26 */
			{30986,43,1}, /* core5 sp_EL0 bit27 */
			{37477,44,0}, /* core5 sp_EL0 bit28 */
			{37476,44,0}, /* core5 sp_EL0 bit29 */
			{27841,44,1}, /* core5 sp_EL0 bit30 */
			{28041,44,1}, /* core5 sp_EL0 bit31 */
			{37287,44,0}, /* core5 sp_EL0 bit32 */
			{37577,43,1}, /* core5 sp_EL0 bit33 */
			{37576,43,1}, /* core5 sp_EL0 bit34 */
			{37575,43,1}, /* core5 sp_EL0 bit35 */
			{37574,43,1}, /* core5 sp_EL0 bit36 */
			{37573,43,1}, /* core5 sp_EL0 bit37 */
			{37572,43,1}, /* core5 sp_EL0 bit38 */
			{37286,44,0}, /* core5 sp_EL0 bit39 */
			{37571,43,1}, /* core5 sp_EL0 bit40 */
			{37570,43,1}, /* core5 sp_EL0 bit41 */
			{37367,44,0}, /* core5 sp_EL0 bit42 */
			{37366,44,0}, /* core5 sp_EL0 bit43 */
			{37285,44,0}, /* core5 sp_EL0 bit44 */
			{37284,44,0}, /* core5 sp_EL0 bit45 */
			{27962,44,1}, /* core5 sp_EL0 bit46 */
			{27934,44,1}, /* core5 sp_EL0 bit47 */
			{37269,44,0}, /* core5 sp_EL0 bit48 */
			{37268,44,0}, /* core5 sp_EL0 bit49 */
			{37283,44,0}, /* core5 sp_EL0 bit50 */
			{37282,44,0}, /* core5 sp_EL0 bit51 */
			{37273,44,0}, /* core5 sp_EL0 bit52 */
			{37272,44,0}, /* core5 sp_EL0 bit53 */
			{37267,44,0}, /* core5 sp_EL0 bit54 */
			{37266,44,0}, /* core5 sp_EL0 bit55 */
			{37265,44,0}, /* core5 sp_EL0 bit56 */
			{37264,44,0}, /* core5 sp_EL0 bit57 */
			{30813,43,1}, /* core5 sp_EL0 bit58 */
			{30812,43,1}, /* core5 sp_EL0 bit59 */
			{37271,44,0}, /* core5 sp_EL0 bit60 */
			{37270,44,0}, /* core5 sp_EL0 bit61 */
			{30811,43,1}, /* core5 sp_EL0 bit62 */
			{30810,43,1}, /* core5 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{28034,44,1}, /* core5 sp_EL1 bit0 */
			{27881,44,1}, /* core5 sp_EL1 bit1 */
			{37395,44,0}, /* core5 sp_EL1 bit2 */
			{37394,44,0}, /* core5 sp_EL1 bit3 */
			{28032,44,1}, /* core5 sp_EL1 bit4 */
			{28033,44,1}, /* core5 sp_EL1 bit5 */
			{37393,44,0}, /* core5 sp_EL1 bit6 */
			{37392,44,0}, /* core5 sp_EL1 bit7 */
			{30569,43,1}, /* core5 sp_EL1 bit8 */
			{30568,43,1}, /* core5 sp_EL1 bit9 */
			{37465,44,0}, /* core5 sp_EL1 bit10 */
			{30567,43,1}, /* core5 sp_EL1 bit11 */
			{30566,43,1}, /* core5 sp_EL1 bit12 */
			{37464,44,0}, /* core5 sp_EL1 bit13 */
			{27863,44,1}, /* core5 sp_EL1 bit14 */
			{27864,44,1}, /* core5 sp_EL1 bit15 */
			{28030,44,1}, /* core5 sp_EL1 bit16 */
			{27862,44,1}, /* core5 sp_EL1 bit17 */
			{27836,44,1}, /* core5 sp_EL1 bit18 */
			{27839,44,1}, /* core5 sp_EL1 bit19 */
			{27838,44,1}, /* core5 sp_EL1 bit20 */
			{27837,44,1}, /* core5 sp_EL1 bit21 */
			{37493,44,0}, /* core5 sp_EL1 bit22 */
			{30597,43,1}, /* core5 sp_EL1 bit23 */
			{30596,43,1}, /* core5 sp_EL1 bit24 */
			{30595,43,1}, /* core5 sp_EL1 bit25 */
			{30594,43,1}, /* core5 sp_EL1 bit26 */
			{37492,44,0}, /* core5 sp_EL1 bit27 */
			{37495,44,0}, /* core5 sp_EL1 bit28 */
			{37494,44,0}, /* core5 sp_EL1 bit29 */
			{27840,44,1}, /* core5 sp_EL1 bit30 */
			{28031,44,1}, /* core5 sp_EL1 bit31 */
			{27935,44,1}, /* core5 sp_EL1 bit32 */
			{27963,44,1}, /* core5 sp_EL1 bit33 */
			{37365,44,0}, /* core5 sp_EL1 bit34 */
			{37364,44,0}, /* core5 sp_EL1 bit35 */
			{37363,44,0}, /* core5 sp_EL1 bit36 */
			{37362,44,0}, /* core5 sp_EL1 bit37 */
			{27966,44,1}, /* core5 sp_EL1 bit38 */
			{27931,44,1}, /* core5 sp_EL1 bit39 */
			{30653,43,1}, /* core5 sp_EL1 bit40 */
			{30652,43,1}, /* core5 sp_EL1 bit41 */
			{30651,43,1}, /* core5 sp_EL1 bit42 */
			{30650,43,1}, /* core5 sp_EL1 bit43 */
			{37279,44,0}, /* core5 sp_EL1 bit44 */
			{37278,44,0}, /* core5 sp_EL1 bit45 */
			{27964,44,1}, /* core5 sp_EL1 bit46 */
			{27933,44,1}, /* core5 sp_EL1 bit47 */
			{27932,44,1}, /* core5 sp_EL1 bit48 */
			{27965,44,1}, /* core5 sp_EL1 bit49 */
			{37281,44,0}, /* core5 sp_EL1 bit50 */
			{37280,44,0}, /* core5 sp_EL1 bit51 */
			{37275,44,0}, /* core5 sp_EL1 bit52 */
			{37274,44,0}, /* core5 sp_EL1 bit53 */
			{37263,44,0}, /* core5 sp_EL1 bit54 */
			{37262,44,0}, /* core5 sp_EL1 bit55 */
			{37261,44,0}, /* core5 sp_EL1 bit56 */
			{37260,44,0}, /* core5 sp_EL1 bit57 */
			{37349,44,0}, /* core5 sp_EL1 bit58 */
			{37348,44,0}, /* core5 sp_EL1 bit59 */
			{37353,44,0}, /* core5 sp_EL1 bit60 */
			{37352,44,0}, /* core5 sp_EL1 bit61 */
			{37277,44,0}, /* core5 sp_EL1 bit62 */
			{37276,44,0}, /* core5 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{28047,44,1}, /* core5 sp_EL2 bit0 */
			{28053,44,1}, /* core5 sp_EL2 bit1 */
			{28052,44,1}, /* core5 sp_EL2 bit2 */
			{28049,44,1}, /* core5 sp_EL2 bit3 */
			{28051,44,1}, /* core5 sp_EL2 bit4 */
			{28050,44,1}, /* core5 sp_EL2 bit5 */
			{28028,44,1}, /* core5 sp_EL2 bit6 */
			{28026,44,1}, /* core5 sp_EL2 bit7 */
			{28027,44,1}, /* core5 sp_EL2 bit8 */
			{28048,44,1}, /* core5 sp_EL2 bit9 */
			{27856,44,1}, /* core5 sp_EL2 bit10 */
			{28061,44,1}, /* core5 sp_EL2 bit11 */
			{27857,44,1}, /* core5 sp_EL2 bit12 */
			{27847,44,1}, /* core5 sp_EL2 bit13 */
			{27854,44,1}, /* core5 sp_EL2 bit14 */
			{37459,44,0}, /* core5 sp_EL2 bit15 */
			{37458,44,0}, /* core5 sp_EL2 bit16 */
			{27853,44,1}, /* core5 sp_EL2 bit17 */
			{37461,44,0}, /* core5 sp_EL2 bit18 */
			{37460,44,0}, /* core5 sp_EL2 bit19 */
			{27852,44,1}, /* core5 sp_EL2 bit20 */
			{27846,44,1}, /* core5 sp_EL2 bit21 */
			{30585,43,1}, /* core5 sp_EL2 bit22 */
			{30589,43,1}, /* core5 sp_EL2 bit23 */
			{30588,43,1}, /* core5 sp_EL2 bit24 */
			{30587,43,1}, /* core5 sp_EL2 bit25 */
			{30584,43,1}, /* core5 sp_EL2 bit26 */
			{30586,43,1}, /* core5 sp_EL2 bit27 */
			{30583,43,1}, /* core5 sp_EL2 bit28 */
			{37489,44,0}, /* core5 sp_EL2 bit29 */
			{37488,44,0}, /* core5 sp_EL2 bit30 */
			{30582,43,1}, /* core5 sp_EL2 bit31 */
			{37601,43,1}, /* core5 sp_EL2 bit32 */
			{30649,43,1}, /* core5 sp_EL2 bit33 */
			{30648,43,1}, /* core5 sp_EL2 bit34 */
			{30647,43,1}, /* core5 sp_EL2 bit35 */
			{30646,43,1}, /* core5 sp_EL2 bit36 */
			{37359,44,0}, /* core5 sp_EL2 bit37 */
			{37358,44,0}, /* core5 sp_EL2 bit38 */
			{37600,43,1}, /* core5 sp_EL2 bit39 */
			{37361,44,0}, /* core5 sp_EL2 bit40 */
			{37360,44,0}, /* core5 sp_EL2 bit41 */
			{30645,43,1}, /* core5 sp_EL2 bit42 */
			{30644,43,1}, /* core5 sp_EL2 bit43 */
			{37599,43,1}, /* core5 sp_EL2 bit44 */
			{37598,43,1}, /* core5 sp_EL2 bit45 */
			{30643,43,1}, /* core5 sp_EL2 bit46 */
			{37597,43,1}, /* core5 sp_EL2 bit47 */
			{37596,43,1}, /* core5 sp_EL2 bit48 */
			{30642,43,1}, /* core5 sp_EL2 bit49 */
			{37595,43,1}, /* core5 sp_EL2 bit50 */
			{37594,43,1}, /* core5 sp_EL2 bit51 */
			{37593,43,1}, /* core5 sp_EL2 bit52 */
			{37592,43,1}, /* core5 sp_EL2 bit53 */
			{27970,44,1}, /* core5 sp_EL2 bit54 */
			{37591,43,1}, /* core5 sp_EL2 bit55 */
			{27971,44,1}, /* core5 sp_EL2 bit56 */
			{37355,44,0}, /* core5 sp_EL2 bit57 */
			{37590,43,1}, /* core5 sp_EL2 bit58 */
			{37589,43,1}, /* core5 sp_EL2 bit59 */
			{37588,43,1}, /* core5 sp_EL2 bit60 */
			{37587,43,1}, /* core5 sp_EL2 bit61 */
			{37354,44,0}, /* core5 sp_EL2 bit62 */
			{37586,43,1}, /* core5 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{28045,44,1}, /* core5 sp_EL3 bit0 */
			{28046,44,1}, /* core5 sp_EL3 bit1 */
			{28044,44,1}, /* core5 sp_EL3 bit2 */
			{28043,44,1}, /* core5 sp_EL3 bit3 */
			{30573,43,1}, /* core5 sp_EL3 bit4 */
			{30572,43,1}, /* core5 sp_EL3 bit5 */
			{30571,43,1}, /* core5 sp_EL3 bit6 */
			{30570,43,1}, /* core5 sp_EL3 bit7 */
			{30577,43,1}, /* core5 sp_EL3 bit8 */
			{30576,43,1}, /* core5 sp_EL3 bit9 */
			{30575,43,1}, /* core5 sp_EL3 bit10 */
			{30574,43,1}, /* core5 sp_EL3 bit11 */
			{30581,43,1}, /* core5 sp_EL3 bit12 */
			{30580,43,1}, /* core5 sp_EL3 bit13 */
			{30579,43,1}, /* core5 sp_EL3 bit14 */
			{30578,43,1}, /* core5 sp_EL3 bit15 */
			{37463,44,0}, /* core5 sp_EL3 bit16 */
			{37462,44,0}, /* core5 sp_EL3 bit17 */
			{37473,44,0}, /* core5 sp_EL3 bit18 */
			{37472,44,0}, /* core5 sp_EL3 bit19 */
			{27850,44,1}, /* core5 sp_EL3 bit20 */
			{27848,44,1}, /* core5 sp_EL3 bit21 */
			{37469,44,0}, /* core5 sp_EL3 bit22 */
			{37468,44,0}, /* core5 sp_EL3 bit23 */
			{30593,43,1}, /* core5 sp_EL3 bit24 */
			{30592,43,1}, /* core5 sp_EL3 bit25 */
			{30591,43,1}, /* core5 sp_EL3 bit26 */
			{30590,43,1}, /* core5 sp_EL3 bit27 */
			{37491,44,0}, /* core5 sp_EL3 bit28 */
			{37490,44,0}, /* core5 sp_EL3 bit29 */
			{27849,44,1}, /* core5 sp_EL3 bit30 */
			{28042,44,1}, /* core5 sp_EL3 bit31 */
			{37289,44,0}, /* core5 sp_EL3 bit32 */
			{37585,43,1}, /* core5 sp_EL3 bit33 */
			{37584,43,1}, /* core5 sp_EL3 bit34 */
			{37583,43,1}, /* core5 sp_EL3 bit35 */
			{37582,43,1}, /* core5 sp_EL3 bit36 */
			{37581,43,1}, /* core5 sp_EL3 bit37 */
			{37580,43,1}, /* core5 sp_EL3 bit38 */
			{37288,44,0}, /* core5 sp_EL3 bit39 */
			{37579,43,1}, /* core5 sp_EL3 bit40 */
			{37578,43,1}, /* core5 sp_EL3 bit41 */
			{37357,44,0}, /* core5 sp_EL3 bit42 */
			{37356,44,0}, /* core5 sp_EL3 bit43 */
			{37347,44,0}, /* core5 sp_EL3 bit44 */
			{37346,44,0}, /* core5 sp_EL3 bit45 */
			{27969,44,1}, /* core5 sp_EL3 bit46 */
			{27974,44,1}, /* core5 sp_EL3 bit47 */
			{27973,44,1}, /* core5 sp_EL3 bit48 */
			{27967,44,1}, /* core5 sp_EL3 bit49 */
			{37351,44,0}, /* core5 sp_EL3 bit50 */
			{37350,44,0}, /* core5 sp_EL3 bit51 */
			{37259,44,0}, /* core5 sp_EL3 bit52 */
			{37258,44,0}, /* core5 sp_EL3 bit53 */
			{27968,44,1}, /* core5 sp_EL3 bit54 */
			{27972,44,1}, /* core5 sp_EL3 bit55 */
			{37078,44,0}, /* core5 sp_EL3 bit56 */
			{37077,44,0}, /* core5 sp_EL3 bit57 */
			{37074,44,0}, /* core5 sp_EL3 bit58 */
			{37073,44,0}, /* core5 sp_EL3 bit59 */
			{37076,44,0}, /* core5 sp_EL3 bit60 */
			{37075,44,0}, /* core5 sp_EL3 bit61 */
			{37072,44,0}, /* core5 sp_EL3 bit62 */
			{37071,44,0}, /* core5 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{37561,43,1}, /* core5 elr_EL1 bit0 */
			{37560,43,1}, /* core5 elr_EL1 bit1 */
			{37559,43,1}, /* core5 elr_EL1 bit2 */
			{37558,43,1}, /* core5 elr_EL1 bit3 */
			{37557,43,1}, /* core5 elr_EL1 bit4 */
			{37556,43,1}, /* core5 elr_EL1 bit5 */
			{37555,43,1}, /* core5 elr_EL1 bit6 */
			{37554,43,1}, /* core5 elr_EL1 bit7 */
			{37036,44,0}, /* core5 elr_EL1 bit8 */
			{37035,44,0}, /* core5 elr_EL1 bit9 */
			{30621,43,1}, /* core5 elr_EL1 bit10 */
			{30620,43,1}, /* core5 elr_EL1 bit11 */
			{37030,44,0}, /* core5 elr_EL1 bit12 */
			{37029,44,0}, /* core5 elr_EL1 bit13 */
			{37022,44,0}, /* core5 elr_EL1 bit14 */
			{37021,44,0}, /* core5 elr_EL1 bit15 */
			{30605,43,1}, /* core5 elr_EL1 bit16 */
			{30604,43,1}, /* core5 elr_EL1 bit17 */
			{30603,43,1}, /* core5 elr_EL1 bit18 */
			{30602,43,1}, /* core5 elr_EL1 bit19 */
			{37018,44,0}, /* core5 elr_EL1 bit20 */
			{37017,44,0}, /* core5 elr_EL1 bit21 */
			{30619,43,1}, /* core5 elr_EL1 bit22 */
			{30618,43,1}, /* core5 elr_EL1 bit23 */
			{30601,43,1}, /* core5 elr_EL1 bit24 */
			{30600,43,1}, /* core5 elr_EL1 bit25 */
			{30599,43,1}, /* core5 elr_EL1 bit26 */
			{30598,43,1}, /* core5 elr_EL1 bit27 */
			{37020,44,0}, /* core5 elr_EL1 bit28 */
			{37019,44,0}, /* core5 elr_EL1 bit29 */
			{37032,44,0}, /* core5 elr_EL1 bit30 */
			{37031,44,0}, /* core5 elr_EL1 bit31 */
			{27939,44,1}, /* core5 elr_EL1 bit32 */
			{27953,44,1}, /* core5 elr_EL1 bit33 */
			{37052,44,0}, /* core5 elr_EL1 bit34 */
			{37051,44,0}, /* core5 elr_EL1 bit35 */
			{37050,44,0}, /* core5 elr_EL1 bit36 */
			{37049,44,0}, /* core5 elr_EL1 bit37 */
			{27954,44,1}, /* core5 elr_EL1 bit38 */
			{27938,44,1}, /* core5 elr_EL1 bit39 */
			{30641,43,1}, /* core5 elr_EL1 bit40 */
			{30640,43,1}, /* core5 elr_EL1 bit41 */
			{30639,43,1}, /* core5 elr_EL1 bit42 */
			{30638,43,1}, /* core5 elr_EL1 bit43 */
			{37038,44,0}, /* core5 elr_EL1 bit44 */
			{37037,44,0}, /* core5 elr_EL1 bit45 */
			{27955,44,1}, /* core5 elr_EL1 bit46 */
			{27950,44,1}, /* core5 elr_EL1 bit47 */
			{27949,44,1}, /* core5 elr_EL1 bit48 */
			{27952,44,1}, /* core5 elr_EL1 bit49 */
			{37042,44,0}, /* core5 elr_EL1 bit50 */
			{37041,44,0}, /* core5 elr_EL1 bit51 */
			{37044,44,0}, /* core5 elr_EL1 bit52 */
			{37043,44,0}, /* core5 elr_EL1 bit53 */
			{37048,44,0}, /* core5 elr_EL1 bit54 */
			{37047,44,0}, /* core5 elr_EL1 bit55 */
			{37058,44,0}, /* core5 elr_EL1 bit56 */
			{37057,44,0}, /* core5 elr_EL1 bit57 */
			{37040,44,0}, /* core5 elr_EL1 bit58 */
			{37039,44,0}, /* core5 elr_EL1 bit59 */
			{37046,44,0}, /* core5 elr_EL1 bit60 */
			{37045,44,0}, /* core5 elr_EL1 bit61 */
			{27951,44,1}, /* core5 elr_EL1 bit62 */
			{27940,44,1}, /* core5 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{37553,43,1}, /* core5 elr_EL2 bit0 */
			{37552,43,1}, /* core5 elr_EL2 bit1 */
			{37551,43,1}, /* core5 elr_EL2 bit2 */
			{37550,43,1}, /* core5 elr_EL2 bit3 */
			{37549,43,1}, /* core5 elr_EL2 bit4 */
			{37548,43,1}, /* core5 elr_EL2 bit5 */
			{37547,43,1}, /* core5 elr_EL2 bit6 */
			{37546,43,1}, /* core5 elr_EL2 bit7 */
			{30629,43,1}, /* core5 elr_EL2 bit8 */
			{30628,43,1}, /* core5 elr_EL2 bit9 */
			{37537,43,1}, /* core5 elr_EL2 bit10 */
			{30627,43,1}, /* core5 elr_EL2 bit11 */
			{37536,43,1}, /* core5 elr_EL2 bit12 */
			{30626,43,1}, /* core5 elr_EL2 bit13 */
			{37535,43,1}, /* core5 elr_EL2 bit14 */
			{37534,43,1}, /* core5 elr_EL2 bit15 */
			{37533,43,1}, /* core5 elr_EL2 bit16 */
			{37532,43,1}, /* core5 elr_EL2 bit17 */
			{37531,43,1}, /* core5 elr_EL2 bit18 */
			{37530,43,1}, /* core5 elr_EL2 bit19 */
			{30609,43,1}, /* core5 elr_EL2 bit20 */
			{30608,43,1}, /* core5 elr_EL2 bit21 */
			{30607,43,1}, /* core5 elr_EL2 bit22 */
			{30606,43,1}, /* core5 elr_EL2 bit23 */
			{30613,43,1}, /* core5 elr_EL2 bit24 */
			{30612,43,1}, /* core5 elr_EL2 bit25 */
			{30611,43,1}, /* core5 elr_EL2 bit26 */
			{30610,43,1}, /* core5 elr_EL2 bit27 */
			{37024,44,0}, /* core5 elr_EL2 bit28 */
			{37023,44,0}, /* core5 elr_EL2 bit29 */
			{27873,44,1}, /* core5 elr_EL2 bit30 */
			{27878,44,1}, /* core5 elr_EL2 bit31 */
			{27943,44,1}, /* core5 elr_EL2 bit32 */
			{27956,44,1}, /* core5 elr_EL2 bit33 */
			{37054,44,0}, /* core5 elr_EL2 bit34 */
			{37053,44,0}, /* core5 elr_EL2 bit35 */
			{37056,44,0}, /* core5 elr_EL2 bit36 */
			{37055,44,0}, /* core5 elr_EL2 bit37 */
			{27957,44,1}, /* core5 elr_EL2 bit38 */
			{27942,44,1}, /* core5 elr_EL2 bit39 */
			{30637,43,1}, /* core5 elr_EL2 bit40 */
			{30636,43,1}, /* core5 elr_EL2 bit41 */
			{30635,43,1}, /* core5 elr_EL2 bit42 */
			{30634,43,1}, /* core5 elr_EL2 bit43 */
			{37070,44,0}, /* core5 elr_EL2 bit44 */
			{37069,44,0}, /* core5 elr_EL2 bit45 */
			{27958,44,1}, /* core5 elr_EL2 bit46 */
			{27948,44,1}, /* core5 elr_EL2 bit47 */
			{27947,44,1}, /* core5 elr_EL2 bit48 */
			{27959,44,1}, /* core5 elr_EL2 bit49 */
			{37066,44,0}, /* core5 elr_EL2 bit50 */
			{37065,44,0}, /* core5 elr_EL2 bit51 */
			{37062,44,0}, /* core5 elr_EL2 bit52 */
			{37061,44,0}, /* core5 elr_EL2 bit53 */
			{30633,43,1}, /* core5 elr_EL2 bit54 */
			{30632,43,1}, /* core5 elr_EL2 bit55 */
			{37060,44,0}, /* core5 elr_EL2 bit56 */
			{37059,44,0}, /* core5 elr_EL2 bit57 */
			{37068,44,0}, /* core5 elr_EL2 bit58 */
			{37067,44,0}, /* core5 elr_EL2 bit59 */
			{37064,44,0}, /* core5 elr_EL2 bit60 */
			{37063,44,0}, /* core5 elr_EL2 bit61 */
			{30631,43,1}, /* core5 elr_EL2 bit62 */
			{30630,43,1}, /* core5 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{37545,43,1}, /* core5 elr_EL3 bit0 */
			{37544,43,1}, /* core5 elr_EL3 bit1 */
			{37543,43,1}, /* core5 elr_EL3 bit2 */
			{37542,43,1}, /* core5 elr_EL3 bit3 */
			{37541,43,1}, /* core5 elr_EL3 bit4 */
			{37540,43,1}, /* core5 elr_EL3 bit5 */
			{37539,43,1}, /* core5 elr_EL3 bit6 */
			{37538,43,1}, /* core5 elr_EL3 bit7 */
			{37034,44,0}, /* core5 elr_EL3 bit8 */
			{37033,44,0}, /* core5 elr_EL3 bit9 */
			{30625,43,1}, /* core5 elr_EL3 bit10 */
			{30624,43,1}, /* core5 elr_EL3 bit11 */
			{30623,43,1}, /* core5 elr_EL3 bit12 */
			{30622,43,1}, /* core5 elr_EL3 bit13 */
			{37026,44,0}, /* core5 elr_EL3 bit14 */
			{37025,44,0}, /* core5 elr_EL3 bit15 */
			{37014,44,0}, /* core5 elr_EL3 bit16 */
			{37013,44,0}, /* core5 elr_EL3 bit17 */
			{27866,44,1}, /* core5 elr_EL3 bit18 */
			{27867,44,1}, /* core5 elr_EL3 bit19 */
			{30617,43,1}, /* core5 elr_EL3 bit20 */
			{30616,43,1}, /* core5 elr_EL3 bit21 */
			{30615,43,1}, /* core5 elr_EL3 bit22 */
			{30614,43,1}, /* core5 elr_EL3 bit23 */
			{27865,44,1}, /* core5 elr_EL3 bit24 */
			{27874,44,1}, /* core5 elr_EL3 bit25 */
			{37016,44,0}, /* core5 elr_EL3 bit26 */
			{37015,44,0}, /* core5 elr_EL3 bit27 */
			{37028,44,0}, /* core5 elr_EL3 bit28 */
			{37027,44,0}, /* core5 elr_EL3 bit29 */
			{27868,44,1}, /* core5 elr_EL3 bit30 */
			{27877,44,1}, /* core5 elr_EL3 bit31 */
			{30669,43,1}, /* core5 elr_EL3 bit32 */
			{30668,43,1}, /* core5 elr_EL3 bit33 */
			{30667,43,1}, /* core5 elr_EL3 bit34 */
			{30666,43,1}, /* core5 elr_EL3 bit35 */
			{30657,43,1}, /* core5 elr_EL3 bit36 */
			{30656,43,1}, /* core5 elr_EL3 bit37 */
			{30655,43,1}, /* core5 elr_EL3 bit38 */
			{30654,43,1}, /* core5 elr_EL3 bit39 */
			{37012,44,0}, /* core5 elr_EL3 bit40 */
			{37011,44,0}, /* core5 elr_EL3 bit41 */
			{27928,44,1}, /* core5 elr_EL3 bit42 */
			{27927,44,1}, /* core5 elr_EL3 bit43 */
			{30661,43,1}, /* core5 elr_EL3 bit44 */
			{30660,43,1}, /* core5 elr_EL3 bit45 */
			{30659,43,1}, /* core5 elr_EL3 bit46 */
			{30658,43,1}, /* core5 elr_EL3 bit47 */
			{30665,43,1}, /* core5 elr_EL3 bit48 */
			{30664,43,1}, /* core5 elr_EL3 bit49 */
			{30663,43,1}, /* core5 elr_EL3 bit50 */
			{30662,43,1}, /* core5 elr_EL3 bit51 */
			{30565,43,1}, /* core5 elr_EL3 bit52 */
			{30564,43,1}, /* core5 elr_EL3 bit53 */
			{30563,43,1}, /* core5 elr_EL3 bit54 */
			{30562,43,1}, /* core5 elr_EL3 bit55 */
			{37513,43,1}, /* core5 elr_EL3 bit56 */
			{37512,43,1}, /* core5 elr_EL3 bit57 */
			{37511,43,1}, /* core5 elr_EL3 bit58 */
			{37510,43,1}, /* core5 elr_EL3 bit59 */
			{37509,43,1}, /* core5 elr_EL3 bit60 */
			{37508,43,1}, /* core5 elr_EL3 bit61 */
			{37507,43,1}, /* core5 elr_EL3 bit62 */
			{37506,43,1}, /* core5 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31320,44,1}, /* core5 raw_pc bit0 */
			{31430,44,1}, /* core5 raw_pc bit1 */
			{32637,43,1}, /* core5 raw_pc bit2 */
			{32636,43,1}, /* core5 raw_pc bit3 */
			{32635,43,1}, /* core5 raw_pc bit4 */
			{32634,43,1}, /* core5 raw_pc bit5 */
			{31328,44,1}, /* core5 raw_pc bit6 */
			{39377,43,1}, /* core5 raw_pc bit7 */
			{39376,43,1}, /* core5 raw_pc bit8 */
			{39375,43,1}, /* core5 raw_pc bit9 */
			{39374,43,1}, /* core5 raw_pc bit10 */
			{39373,43,1}, /* core5 raw_pc bit11 */
			{39372,43,1}, /* core5 raw_pc bit12 */
			{39371,43,1}, /* core5 raw_pc bit13 */
			{39370,43,1}, /* core5 raw_pc bit14 */
			{39305,43,1}, /* core5 raw_pc bit15 */
			{39304,43,1}, /* core5 raw_pc bit16 */
			{39303,43,1}, /* core5 raw_pc bit17 */
			{39302,43,1}, /* core5 raw_pc bit18 */
			{39301,43,1}, /* core5 raw_pc bit19 */
			{39300,43,1}, /* core5 raw_pc bit20 */
			{39299,43,1}, /* core5 raw_pc bit21 */
			{39298,43,1}, /* core5 raw_pc bit22 */
			{39313,43,1}, /* core5 raw_pc bit23 */
			{39312,43,1}, /* core5 raw_pc bit24 */
			{39311,43,1}, /* core5 raw_pc bit25 */
			{39310,43,1}, /* core5 raw_pc bit26 */
			{39309,43,1}, /* core5 raw_pc bit27 */
			{39308,43,1}, /* core5 raw_pc bit28 */
			{39307,43,1}, /* core5 raw_pc bit29 */
			{39306,43,1}, /* core5 raw_pc bit30 */
			{39369,43,1}, /* core5 raw_pc bit31 */
			{39368,43,1}, /* core5 raw_pc bit32 */
			{39367,43,1}, /* core5 raw_pc bit33 */
			{39366,43,1}, /* core5 raw_pc bit34 */
			{39365,43,1}, /* core5 raw_pc bit35 */
			{39364,43,1}, /* core5 raw_pc bit36 */
			{39363,43,1}, /* core5 raw_pc bit37 */
			{39362,43,1}, /* core5 raw_pc bit38 */
			{39361,43,1}, /* core5 raw_pc bit39 */
			{39360,43,1}, /* core5 raw_pc bit40 */
			{39359,43,1}, /* core5 raw_pc bit41 */
			{39358,43,1}, /* core5 raw_pc bit42 */
			{39357,43,1}, /* core5 raw_pc bit43 */
			{39356,43,1}, /* core5 raw_pc bit44 */
			{39355,43,1}, /* core5 raw_pc bit45 */
			{39354,43,1}, /* core5 raw_pc bit46 */
			{38933,44,1}, /* core5 raw_pc bit47 */
			{38932,44,1}, /* core5 raw_pc bit48 */
			{31321,44,1}, /* core5 raw_pc bit49 */
			{    0, 0,2}, /* core5 raw_pc bit50 */
			{    0, 0,2}, /* core5 raw_pc bit51 */
			{    0, 0,2}, /* core5 raw_pc bit52 */
			{    0, 0,2}, /* core5 raw_pc bit53 */
			{    0, 0,2}, /* core5 raw_pc bit54 */
			{    0, 0,2}, /* core5 raw_pc bit55 */
			{    0, 0,2}, /* core5 raw_pc bit56 */
			{    0, 0,2}, /* core5 raw_pc bit57 */
			{    0, 0,2}, /* core5 raw_pc bit58 */
			{    0, 0,2}, /* core5 raw_pc bit59 */
			{    0, 0,2}, /* core5 raw_pc bit60 */
			{    0, 0,2}, /* core5 raw_pc bit61 */
			{    0, 0,2}, /* core5 raw_pc bit62 */
			{    0, 0,2}, /* core5 raw_pc bit63 */
			}},
			.pc_iss = {{
			{31564,44,1}, /* core5 pc_iss bit0 */
			{31566,44,1}, /* core5 pc_iss bit1 */
			{38983,44,1}, /* core5 pc_iss bit2 */
			{38982,44,1}, /* core5 pc_iss bit3 */
			{32597,43,1}, /* core5 pc_iss bit4 */
			{32596,43,1}, /* core5 pc_iss bit5 */
			{32595,43,1}, /* core5 pc_iss bit6 */
			{32594,43,1}, /* core5 pc_iss bit7 */
			{31651,44,0}, /* core5 pc_iss bit8 */
			{31556,44,1}, /* core5 pc_iss bit9 */
			{31563,44,1}, /* core5 pc_iss bit10 */
			{31654,44,0}, /* core5 pc_iss bit11 */
			{31559,44,1}, /* core5 pc_iss bit12 */
			{31659,44,0}, /* core5 pc_iss bit13 */
			{31658,44,0}, /* core5 pc_iss bit14 */
			{31655,44,0}, /* core5 pc_iss bit15 */
			{31557,44,1}, /* core5 pc_iss bit16 */
			{31656,44,0}, /* core5 pc_iss bit17 */
			{31657,44,0}, /* core5 pc_iss bit18 */
			{31558,44,1}, /* core5 pc_iss bit19 */
			{32605,43,1}, /* core5 pc_iss bit20 */
			{32604,43,1}, /* core5 pc_iss bit21 */
			{32603,43,1}, /* core5 pc_iss bit22 */
			{32602,43,1}, /* core5 pc_iss bit23 */
			{38985,44,1}, /* core5 pc_iss bit24 */
			{38984,44,1}, /* core5 pc_iss bit25 */
			{31652,44,0}, /* core5 pc_iss bit26 */
			{31555,44,1}, /* core5 pc_iss bit27 */
			{32609,43,1}, /* core5 pc_iss bit28 */
			{32608,43,1}, /* core5 pc_iss bit29 */
			{32607,43,1}, /* core5 pc_iss bit30 */
			{32606,43,1}, /* core5 pc_iss bit31 */
			{31554,44,1}, /* core5 pc_iss bit32 */
			{31553,44,1}, /* core5 pc_iss bit33 */
			{38981,44,1}, /* core5 pc_iss bit34 */
			{38980,44,1}, /* core5 pc_iss bit35 */
			{32613,43,1}, /* core5 pc_iss bit36 */
			{32612,43,1}, /* core5 pc_iss bit37 */
			{32611,43,1}, /* core5 pc_iss bit38 */
			{32610,43,1}, /* core5 pc_iss bit39 */
			{39401,43,1}, /* core5 pc_iss bit40 */
			{39400,43,1}, /* core5 pc_iss bit41 */
			{39399,43,1}, /* core5 pc_iss bit42 */
			{39398,43,1}, /* core5 pc_iss bit43 */
			{39397,43,1}, /* core5 pc_iss bit44 */
			{39396,43,1}, /* core5 pc_iss bit45 */
			{39395,43,1}, /* core5 pc_iss bit46 */
			{39394,43,1}, /* core5 pc_iss bit47 */
			{32593,43,1}, /* core5 pc_iss bit48 */
			{32592,43,1}, /* core5 pc_iss bit49 */
			{32591,43,1}, /* core5 pc_iss bit50 */
			{32590,43,1}, /* core5 pc_iss bit51 */
			{38979,44,1}, /* core5 pc_iss bit52 */
			{38978,44,1}, /* core5 pc_iss bit53 */
			{31455,44,1}, /* core5 pc_iss bit54 */
			{31456,44,1}, /* core5 pc_iss bit55 */
			{31457,44,1}, /* core5 pc_iss bit56 */
			{31454,44,1}, /* core5 pc_iss bit57 */
			{31551,44,1}, /* core5 pc_iss bit58 */
			{31452,44,1}, /* core5 pc_iss bit59 */
			{31552,44,1}, /* core5 pc_iss bit60 */
			{31453,44,1}, /* core5 pc_iss bit61 */
			{38977,44,1}, /* core5 pc_iss bit62 */
			{38976,44,1}, /* core5 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31605,44,0}, /* core5 full_pc_wr bit0 */
			{    0, 0,2}, /* core5 full_pc_wr bit1 */
			{    0, 0,2}, /* core5 full_pc_wr bit2 */
			{    0, 0,2}, /* core5 full_pc_wr bit3 */
			{    0, 0,2}, /* core5 full_pc_wr bit4 */
			{    0, 0,2}, /* core5 full_pc_wr bit5 */
			{    0, 0,2}, /* core5 full_pc_wr bit6 */
			{    0, 0,2}, /* core5 full_pc_wr bit7 */
			{    0, 0,2}, /* core5 full_pc_wr bit8 */
			{    0, 0,2}, /* core5 full_pc_wr bit9 */
			{    0, 0,2}, /* core5 full_pc_wr bit10 */
			{    0, 0,2}, /* core5 full_pc_wr bit11 */
			{    0, 0,2}, /* core5 full_pc_wr bit12 */
			{    0, 0,2}, /* core5 full_pc_wr bit13 */
			{    0, 0,2}, /* core5 full_pc_wr bit14 */
			{    0, 0,2}, /* core5 full_pc_wr bit15 */
			{    0, 0,2}, /* core5 full_pc_wr bit16 */
			{    0, 0,2}, /* core5 full_pc_wr bit17 */
			{    0, 0,2}, /* core5 full_pc_wr bit18 */
			{    0, 0,2}, /* core5 full_pc_wr bit19 */
			{    0, 0,2}, /* core5 full_pc_wr bit20 */
			{    0, 0,2}, /* core5 full_pc_wr bit21 */
			{    0, 0,2}, /* core5 full_pc_wr bit22 */
			{    0, 0,2}, /* core5 full_pc_wr bit23 */
			{    0, 0,2}, /* core5 full_pc_wr bit24 */
			{    0, 0,2}, /* core5 full_pc_wr bit25 */
			{    0, 0,2}, /* core5 full_pc_wr bit26 */
			{    0, 0,2}, /* core5 full_pc_wr bit27 */
			{    0, 0,2}, /* core5 full_pc_wr bit28 */
			{    0, 0,2}, /* core5 full_pc_wr bit29 */
			{    0, 0,2}, /* core5 full_pc_wr bit30 */
			{    0, 0,2}, /* core5 full_pc_wr bit31 */
			{    0, 0,2}, /* core5 full_pc_wr bit32 */
			{    0, 0,2}, /* core5 full_pc_wr bit33 */
			{    0, 0,2}, /* core5 full_pc_wr bit34 */
			{    0, 0,2}, /* core5 full_pc_wr bit35 */
			{    0, 0,2}, /* core5 full_pc_wr bit36 */
			{    0, 0,2}, /* core5 full_pc_wr bit37 */
			{    0, 0,2}, /* core5 full_pc_wr bit38 */
			{    0, 0,2}, /* core5 full_pc_wr bit39 */
			{    0, 0,2}, /* core5 full_pc_wr bit40 */
			{    0, 0,2}, /* core5 full_pc_wr bit41 */
			{    0, 0,2}, /* core5 full_pc_wr bit42 */
			{    0, 0,2}, /* core5 full_pc_wr bit43 */
			{    0, 0,2}, /* core5 full_pc_wr bit44 */
			{    0, 0,2}, /* core5 full_pc_wr bit45 */
			{    0, 0,2}, /* core5 full_pc_wr bit46 */
			{    0, 0,2}, /* core5 full_pc_wr bit47 */
			{    0, 0,2}, /* core5 full_pc_wr bit48 */
			{    0, 0,2}, /* core5 full_pc_wr bit49 */
			{    0, 0,2}, /* core5 full_pc_wr bit50 */
			{    0, 0,2}, /* core5 full_pc_wr bit51 */
			{    0, 0,2}, /* core5 full_pc_wr bit52 */
			{    0, 0,2}, /* core5 full_pc_wr bit53 */
			{    0, 0,2}, /* core5 full_pc_wr bit54 */
			{    0, 0,2}, /* core5 full_pc_wr bit55 */
			{    0, 0,2}, /* core5 full_pc_wr bit56 */
			{    0, 0,2}, /* core5 full_pc_wr bit57 */
			{    0, 0,2}, /* core5 full_pc_wr bit58 */
			{    0, 0,2}, /* core5 full_pc_wr bit59 */
			{    0, 0,2}, /* core5 full_pc_wr bit60 */
			{    0, 0,2}, /* core5 full_pc_wr bit61 */
			{    0, 0,2}, /* core5 full_pc_wr bit62 */
			{    0, 0,2}, /* core5 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{31612,44,0}, /* core5 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{32625,43,1}, /* core5 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{16480,44,0}, /* core5 return_Stack_pointer bit0 */
			{16473,44,0}, /* core5 return_Stack_pointer bit1 */
			{16474,44,0}, /* core5 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{20540,44,0}, /* core5 return_Stack0 bit0 */
			{20539,44,0}, /* core5 return_Stack0 bit1 */
			{20538,44,0}, /* core5 return_Stack0 bit2 */
			{20537,44,0}, /* core5 return_Stack0 bit3 */
			{20536,44,0}, /* core5 return_Stack0 bit4 */
			{20535,44,0}, /* core5 return_Stack0 bit5 */
			{20534,44,0}, /* core5 return_Stack0 bit6 */
			{20568,44,0}, /* core5 return_Stack0 bit7 */
			{20567,44,0}, /* core5 return_Stack0 bit8 */
			{20566,44,0}, /* core5 return_Stack0 bit9 */
			{20565,44,0}, /* core5 return_Stack0 bit10 */
			{20588,44,0}, /* core5 return_Stack0 bit11 */
			{20587,44,0}, /* core5 return_Stack0 bit12 */
			{20586,44,0}, /* core5 return_Stack0 bit13 */
			{20585,44,0}, /* core5 return_Stack0 bit14 */
			{20584,44,0}, /* core5 return_Stack0 bit15 */
			{20583,44,0}, /* core5 return_Stack0 bit16 */
			{20582,44,0}, /* core5 return_Stack0 bit17 */
			{20581,44,0}, /* core5 return_Stack0 bit18 */
			{20612,44,0}, /* core5 return_Stack0 bit19 */
			{20611,44,0}, /* core5 return_Stack0 bit20 */
			{20610,44,0}, /* core5 return_Stack0 bit21 */
			{20609,44,0}, /* core5 return_Stack0 bit22 */
			{20608,44,0}, /* core5 return_Stack0 bit23 */
			{20607,44,0}, /* core5 return_Stack0 bit24 */
			{20606,44,0}, /* core5 return_Stack0 bit25 */
			{20605,44,0}, /* core5 return_Stack0 bit26 */
			{20528,44,0}, /* core5 return_Stack0 bit27 */
			{20527,44,0}, /* core5 return_Stack0 bit28 */
			{20526,44,0}, /* core5 return_Stack0 bit29 */
			{20533,44,0}, /* core5 return_Stack0 bit30 */
			{16458,44,0}, /* core5 return_Stack0 bit31 */
			{20525,44,0}, /* core5 return_Stack0 bit32 */
			{16457,44,0}, /* core5 return_Stack0 bit33 */
			{16460,44,0}, /* core5 return_Stack0 bit34 */
			{16459,44,0}, /* core5 return_Stack0 bit35 */
			{20504,44,0}, /* core5 return_Stack0 bit36 */
			{20503,44,0}, /* core5 return_Stack0 bit37 */
			{20502,44,0}, /* core5 return_Stack0 bit38 */
			{20501,44,0}, /* core5 return_Stack0 bit39 */
			{20500,44,0}, /* core5 return_Stack0 bit40 */
			{20499,44,0}, /* core5 return_Stack0 bit41 */
			{20498,44,0}, /* core5 return_Stack0 bit42 */
			{20497,44,0}, /* core5 return_Stack0 bit43 */
			{20496,44,0}, /* core5 return_Stack0 bit44 */
			{20495,44,0}, /* core5 return_Stack0 bit45 */
			{20494,44,0}, /* core5 return_Stack0 bit46 */
			{20493,44,0}, /* core5 return_Stack0 bit47 */
			{13577,44,1}, /* core5 return_Stack0 bit48 */
			{    0, 0,2}, /* core5 return_Stack0 bit49 */
			{    0, 0,2}, /* core5 return_Stack0 bit50 */
			{    0, 0,2}, /* core5 return_Stack0 bit51 */
			{    0, 0,2}, /* core5 return_Stack0 bit52 */
			{    0, 0,2}, /* core5 return_Stack0 bit53 */
			{    0, 0,2}, /* core5 return_Stack0 bit54 */
			{    0, 0,2}, /* core5 return_Stack0 bit55 */
			{    0, 0,2}, /* core5 return_Stack0 bit56 */
			{    0, 0,2}, /* core5 return_Stack0 bit57 */
			{    0, 0,2}, /* core5 return_Stack0 bit58 */
			{    0, 0,2}, /* core5 return_Stack0 bit59 */
			{    0, 0,2}, /* core5 return_Stack0 bit60 */
			{    0, 0,2}, /* core5 return_Stack0 bit61 */
			{    0, 0,2}, /* core5 return_Stack0 bit62 */
			{    0, 0,2}, /* core5 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{20548,44,0}, /* core5 return_Stack1 bit0 */
			{20547,44,0}, /* core5 return_Stack1 bit1 */
			{20546,44,0}, /* core5 return_Stack1 bit2 */
			{20545,44,0}, /* core5 return_Stack1 bit3 */
			{20552,44,0}, /* core5 return_Stack1 bit4 */
			{20551,44,0}, /* core5 return_Stack1 bit5 */
			{20550,44,0}, /* core5 return_Stack1 bit6 */
			{20564,44,0}, /* core5 return_Stack1 bit7 */
			{20563,44,0}, /* core5 return_Stack1 bit8 */
			{20562,44,0}, /* core5 return_Stack1 bit9 */
			{20561,44,0}, /* core5 return_Stack1 bit10 */
			{20592,44,0}, /* core5 return_Stack1 bit11 */
			{20591,44,0}, /* core5 return_Stack1 bit12 */
			{20590,44,0}, /* core5 return_Stack1 bit13 */
			{20589,44,0}, /* core5 return_Stack1 bit14 */
			{20600,44,0}, /* core5 return_Stack1 bit15 */
			{20599,44,0}, /* core5 return_Stack1 bit16 */
			{20598,44,0}, /* core5 return_Stack1 bit17 */
			{20597,44,0}, /* core5 return_Stack1 bit18 */
			{20580,44,0}, /* core5 return_Stack1 bit19 */
			{20579,44,0}, /* core5 return_Stack1 bit20 */
			{20578,44,0}, /* core5 return_Stack1 bit21 */
			{20577,44,0}, /* core5 return_Stack1 bit22 */
			{20572,44,0}, /* core5 return_Stack1 bit23 */
			{20571,44,0}, /* core5 return_Stack1 bit24 */
			{20570,44,0}, /* core5 return_Stack1 bit25 */
			{20569,44,0}, /* core5 return_Stack1 bit26 */
			{20532,44,0}, /* core5 return_Stack1 bit27 */
			{20531,44,0}, /* core5 return_Stack1 bit28 */
			{20530,44,0}, /* core5 return_Stack1 bit29 */
			{20529,44,0}, /* core5 return_Stack1 bit30 */
			{20549,44,0}, /* core5 return_Stack1 bit31 */
			{13574,44,1}, /* core5 return_Stack1 bit32 */
			{20520,44,0}, /* core5 return_Stack1 bit33 */
			{20519,44,0}, /* core5 return_Stack1 bit34 */
			{20518,44,0}, /* core5 return_Stack1 bit35 */
			{20517,44,0}, /* core5 return_Stack1 bit36 */
			{20516,44,0}, /* core5 return_Stack1 bit37 */
			{20515,44,0}, /* core5 return_Stack1 bit38 */
			{20514,44,0}, /* core5 return_Stack1 bit39 */
			{20513,44,0}, /* core5 return_Stack1 bit40 */
			{20492,44,0}, /* core5 return_Stack1 bit41 */
			{20491,44,0}, /* core5 return_Stack1 bit42 */
			{20490,44,0}, /* core5 return_Stack1 bit43 */
			{20489,44,0}, /* core5 return_Stack1 bit44 */
			{20488,44,0}, /* core5 return_Stack1 bit45 */
			{20487,44,0}, /* core5 return_Stack1 bit46 */
			{20486,44,0}, /* core5 return_Stack1 bit47 */
			{20485,44,0}, /* core5 return_Stack1 bit48 */
			{    0, 0,2}, /* core5 return_Stack1 bit49 */
			{    0, 0,2}, /* core5 return_Stack1 bit50 */
			{    0, 0,2}, /* core5 return_Stack1 bit51 */
			{    0, 0,2}, /* core5 return_Stack1 bit52 */
			{    0, 0,2}, /* core5 return_Stack1 bit53 */
			{    0, 0,2}, /* core5 return_Stack1 bit54 */
			{    0, 0,2}, /* core5 return_Stack1 bit55 */
			{    0, 0,2}, /* core5 return_Stack1 bit56 */
			{    0, 0,2}, /* core5 return_Stack1 bit57 */
			{    0, 0,2}, /* core5 return_Stack1 bit58 */
			{    0, 0,2}, /* core5 return_Stack1 bit59 */
			{    0, 0,2}, /* core5 return_Stack1 bit60 */
			{    0, 0,2}, /* core5 return_Stack1 bit61 */
			{    0, 0,2}, /* core5 return_Stack1 bit62 */
			{    0, 0,2}, /* core5 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{20544,44,0}, /* core5 return_Stack2 bit0 */
			{20543,44,0}, /* core5 return_Stack2 bit1 */
			{20542,44,0}, /* core5 return_Stack2 bit2 */
			{20541,44,0}, /* core5 return_Stack2 bit3 */
			{20556,44,0}, /* core5 return_Stack2 bit4 */
			{20555,44,0}, /* core5 return_Stack2 bit5 */
			{20554,44,0}, /* core5 return_Stack2 bit6 */
			{20553,44,0}, /* core5 return_Stack2 bit7 */
			{20560,44,0}, /* core5 return_Stack2 bit8 */
			{20559,44,0}, /* core5 return_Stack2 bit9 */
			{20558,44,0}, /* core5 return_Stack2 bit10 */
			{20557,44,0}, /* core5 return_Stack2 bit11 */
			{20596,44,0}, /* core5 return_Stack2 bit12 */
			{20595,44,0}, /* core5 return_Stack2 bit13 */
			{16346,44,0}, /* core5 return_Stack2 bit14 */
			{20594,44,0}, /* core5 return_Stack2 bit15 */
			{16345,44,0}, /* core5 return_Stack2 bit16 */
			{20593,44,0}, /* core5 return_Stack2 bit17 */
			{16344,44,0}, /* core5 return_Stack2 bit18 */
			{20576,44,0}, /* core5 return_Stack2 bit19 */
			{20575,44,0}, /* core5 return_Stack2 bit20 */
			{20574,44,0}, /* core5 return_Stack2 bit21 */
			{20573,44,0}, /* core5 return_Stack2 bit22 */
			{20604,44,0}, /* core5 return_Stack2 bit23 */
			{20603,44,0}, /* core5 return_Stack2 bit24 */
			{20602,44,0}, /* core5 return_Stack2 bit25 */
			{20601,44,0}, /* core5 return_Stack2 bit26 */
			{16343,44,0}, /* core5 return_Stack2 bit27 */
			{16512,44,0}, /* core5 return_Stack2 bit28 */
			{16511,44,0}, /* core5 return_Stack2 bit29 */
			{20524,44,0}, /* core5 return_Stack2 bit30 */
			{20523,44,0}, /* core5 return_Stack2 bit31 */
			{13573,44,1}, /* core5 return_Stack2 bit32 */
			{20522,44,0}, /* core5 return_Stack2 bit33 */
			{20521,44,0}, /* core5 return_Stack2 bit34 */
			{20512,44,0}, /* core5 return_Stack2 bit35 */
			{20511,44,0}, /* core5 return_Stack2 bit36 */
			{20510,44,0}, /* core5 return_Stack2 bit37 */
			{20509,44,0}, /* core5 return_Stack2 bit38 */
			{20508,44,0}, /* core5 return_Stack2 bit39 */
			{20507,44,0}, /* core5 return_Stack2 bit40 */
			{20506,44,0}, /* core5 return_Stack2 bit41 */
			{20505,44,0}, /* core5 return_Stack2 bit42 */
			{20460,44,0}, /* core5 return_Stack2 bit43 */
			{20459,44,0}, /* core5 return_Stack2 bit44 */
			{20458,44,0}, /* core5 return_Stack2 bit45 */
			{20457,44,0}, /* core5 return_Stack2 bit46 */
			{13583,44,1}, /* core5 return_Stack2 bit47 */
			{13584,44,1}, /* core5 return_Stack2 bit48 */
			{    0, 0,2}, /* core5 return_Stack2 bit49 */
			{    0, 0,2}, /* core5 return_Stack2 bit50 */
			{    0, 0,2}, /* core5 return_Stack2 bit51 */
			{    0, 0,2}, /* core5 return_Stack2 bit52 */
			{    0, 0,2}, /* core5 return_Stack2 bit53 */
			{    0, 0,2}, /* core5 return_Stack2 bit54 */
			{    0, 0,2}, /* core5 return_Stack2 bit55 */
			{    0, 0,2}, /* core5 return_Stack2 bit56 */
			{    0, 0,2}, /* core5 return_Stack2 bit57 */
			{    0, 0,2}, /* core5 return_Stack2 bit58 */
			{    0, 0,2}, /* core5 return_Stack2 bit59 */
			{    0, 0,2}, /* core5 return_Stack2 bit60 */
			{    0, 0,2}, /* core5 return_Stack2 bit61 */
			{    0, 0,2}, /* core5 return_Stack2 bit62 */
			{    0, 0,2}, /* core5 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{20362,44,0}, /* core5 return_Stack3 bit0 */
			{20361,44,0}, /* core5 return_Stack3 bit1 */
			{20360,44,0}, /* core5 return_Stack3 bit2 */
			{20359,44,0}, /* core5 return_Stack3 bit3 */
			{20270,44,0}, /* core5 return_Stack3 bit4 */
			{20269,44,0}, /* core5 return_Stack3 bit5 */
			{20366,44,0}, /* core5 return_Stack3 bit6 */
			{20268,44,0}, /* core5 return_Stack3 bit7 */
			{20267,44,0}, /* core5 return_Stack3 bit8 */
			{20418,44,0}, /* core5 return_Stack3 bit9 */
			{20417,44,0}, /* core5 return_Stack3 bit10 */
			{20416,44,0}, /* core5 return_Stack3 bit11 */
			{20415,44,0}, /* core5 return_Stack3 bit12 */
			{16362,44,0}, /* core5 return_Stack3 bit13 */
			{16361,44,0}, /* core5 return_Stack3 bit14 */
			{16360,44,0}, /* core5 return_Stack3 bit15 */
			{16359,44,0}, /* core5 return_Stack3 bit16 */
			{16338,44,0}, /* core5 return_Stack3 bit17 */
			{16337,44,0}, /* core5 return_Stack3 bit18 */
			{16340,44,0}, /* core5 return_Stack3 bit19 */
			{16339,44,0}, /* core5 return_Stack3 bit20 */
			{16498,44,0}, /* core5 return_Stack3 bit21 */
			{16497,44,0}, /* core5 return_Stack3 bit22 */
			{16500,44,0}, /* core5 return_Stack3 bit23 */
			{16499,44,0}, /* core5 return_Stack3 bit24 */
			{16504,44,0}, /* core5 return_Stack3 bit25 */
			{16503,44,0}, /* core5 return_Stack3 bit26 */
			{16508,44,0}, /* core5 return_Stack3 bit27 */
			{16507,44,0}, /* core5 return_Stack3 bit28 */
			{16518,44,0}, /* core5 return_Stack3 bit29 */
			{20365,44,0}, /* core5 return_Stack3 bit30 */
			{20364,44,0}, /* core5 return_Stack3 bit31 */
			{16517,44,0}, /* core5 return_Stack3 bit32 */
			{20363,44,0}, /* core5 return_Stack3 bit33 */
			{20310,44,0}, /* core5 return_Stack3 bit34 */
			{20309,44,0}, /* core5 return_Stack3 bit35 */
			{20308,44,0}, /* core5 return_Stack3 bit36 */
			{20307,44,0}, /* core5 return_Stack3 bit37 */
			{20318,44,0}, /* core5 return_Stack3 bit38 */
			{20317,44,0}, /* core5 return_Stack3 bit39 */
			{20316,44,0}, /* core5 return_Stack3 bit40 */
			{20315,44,0}, /* core5 return_Stack3 bit41 */
			{20342,44,0}, /* core5 return_Stack3 bit42 */
			{20341,44,0}, /* core5 return_Stack3 bit43 */
			{20340,44,0}, /* core5 return_Stack3 bit44 */
			{20339,44,0}, /* core5 return_Stack3 bit45 */
			{16440,44,0}, /* core5 return_Stack3 bit46 */
			{16439,44,0}, /* core5 return_Stack3 bit47 */
			{13581,44,1}, /* core5 return_Stack3 bit48 */
			{    0, 0,2}, /* core5 return_Stack3 bit49 */
			{    0, 0,2}, /* core5 return_Stack3 bit50 */
			{    0, 0,2}, /* core5 return_Stack3 bit51 */
			{    0, 0,2}, /* core5 return_Stack3 bit52 */
			{    0, 0,2}, /* core5 return_Stack3 bit53 */
			{    0, 0,2}, /* core5 return_Stack3 bit54 */
			{    0, 0,2}, /* core5 return_Stack3 bit55 */
			{    0, 0,2}, /* core5 return_Stack3 bit56 */
			{    0, 0,2}, /* core5 return_Stack3 bit57 */
			{    0, 0,2}, /* core5 return_Stack3 bit58 */
			{    0, 0,2}, /* core5 return_Stack3 bit59 */
			{    0, 0,2}, /* core5 return_Stack3 bit60 */
			{    0, 0,2}, /* core5 return_Stack3 bit61 */
			{    0, 0,2}, /* core5 return_Stack3 bit62 */
			{    0, 0,2}, /* core5 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{20370,44,0}, /* core5 return_Stack4 bit0 */
			{20369,44,0}, /* core5 return_Stack4 bit1 */
			{20368,44,0}, /* core5 return_Stack4 bit2 */
			{20367,44,0}, /* core5 return_Stack4 bit3 */
			{20374,44,0}, /* core5 return_Stack4 bit4 */
			{20373,44,0}, /* core5 return_Stack4 bit5 */
			{20372,44,0}, /* core5 return_Stack4 bit6 */
			{20371,44,0}, /* core5 return_Stack4 bit7 */
			{20378,44,0}, /* core5 return_Stack4 bit8 */
			{20377,44,0}, /* core5 return_Stack4 bit9 */
			{20376,44,0}, /* core5 return_Stack4 bit10 */
			{20375,44,0}, /* core5 return_Stack4 bit11 */
			{20398,44,0}, /* core5 return_Stack4 bit12 */
			{20397,44,0}, /* core5 return_Stack4 bit13 */
			{20396,44,0}, /* core5 return_Stack4 bit14 */
			{20395,44,0}, /* core5 return_Stack4 bit15 */
			{20394,44,0}, /* core5 return_Stack4 bit16 */
			{20393,44,0}, /* core5 return_Stack4 bit17 */
			{20392,44,0}, /* core5 return_Stack4 bit18 */
			{20391,44,0}, /* core5 return_Stack4 bit19 */
			{20430,44,0}, /* core5 return_Stack4 bit20 */
			{20429,44,0}, /* core5 return_Stack4 bit21 */
			{20428,44,0}, /* core5 return_Stack4 bit22 */
			{20427,44,0}, /* core5 return_Stack4 bit23 */
			{20434,44,0}, /* core5 return_Stack4 bit24 */
			{20433,44,0}, /* core5 return_Stack4 bit25 */
			{20432,44,0}, /* core5 return_Stack4 bit26 */
			{20431,44,0}, /* core5 return_Stack4 bit27 */
			{16506,44,0}, /* core5 return_Stack4 bit28 */
			{16505,44,0}, /* core5 return_Stack4 bit29 */
			{16456,44,0}, /* core5 return_Stack4 bit30 */
			{16455,44,0}, /* core5 return_Stack4 bit31 */
			{16454,44,0}, /* core5 return_Stack4 bit32 */
			{16453,44,0}, /* core5 return_Stack4 bit33 */
			{16446,44,0}, /* core5 return_Stack4 bit34 */
			{20314,44,0}, /* core5 return_Stack4 bit35 */
			{20313,44,0}, /* core5 return_Stack4 bit36 */
			{20312,44,0}, /* core5 return_Stack4 bit37 */
			{20311,44,0}, /* core5 return_Stack4 bit38 */
			{20306,44,0}, /* core5 return_Stack4 bit39 */
			{20305,44,0}, /* core5 return_Stack4 bit40 */
			{20304,44,0}, /* core5 return_Stack4 bit41 */
			{20303,44,0}, /* core5 return_Stack4 bit42 */
			{20298,44,0}, /* core5 return_Stack4 bit43 */
			{20297,44,0}, /* core5 return_Stack4 bit44 */
			{20296,44,0}, /* core5 return_Stack4 bit45 */
			{20295,44,0}, /* core5 return_Stack4 bit46 */
			{16445,44,0}, /* core5 return_Stack4 bit47 */
			{13576,44,1}, /* core5 return_Stack4 bit48 */
			{    0, 0,2}, /* core5 return_Stack4 bit49 */
			{    0, 0,2}, /* core5 return_Stack4 bit50 */
			{    0, 0,2}, /* core5 return_Stack4 bit51 */
			{    0, 0,2}, /* core5 return_Stack4 bit52 */
			{    0, 0,2}, /* core5 return_Stack4 bit53 */
			{    0, 0,2}, /* core5 return_Stack4 bit54 */
			{    0, 0,2}, /* core5 return_Stack4 bit55 */
			{    0, 0,2}, /* core5 return_Stack4 bit56 */
			{    0, 0,2}, /* core5 return_Stack4 bit57 */
			{    0, 0,2}, /* core5 return_Stack4 bit58 */
			{    0, 0,2}, /* core5 return_Stack4 bit59 */
			{    0, 0,2}, /* core5 return_Stack4 bit60 */
			{    0, 0,2}, /* core5 return_Stack4 bit61 */
			{    0, 0,2}, /* core5 return_Stack4 bit62 */
			{    0, 0,2}, /* core5 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{16444,44,0}, /* core5 return_Stack5 bit0 */
			{20262,44,0}, /* core5 return_Stack5 bit1 */
			{16443,44,0}, /* core5 return_Stack5 bit2 */
			{16438,44,0}, /* core5 return_Stack5 bit3 */
			{20261,44,0}, /* core5 return_Stack5 bit4 */
			{20260,44,0}, /* core5 return_Stack5 bit5 */
			{20259,44,0}, /* core5 return_Stack5 bit6 */
			{20266,44,0}, /* core5 return_Stack5 bit7 */
			{20265,44,0}, /* core5 return_Stack5 bit8 */
			{20264,44,0}, /* core5 return_Stack5 bit9 */
			{20263,44,0}, /* core5 return_Stack5 bit10 */
			{16437,44,0}, /* core5 return_Stack5 bit11 */
			{20402,44,0}, /* core5 return_Stack5 bit12 */
			{20401,44,0}, /* core5 return_Stack5 bit13 */
			{20400,44,0}, /* core5 return_Stack5 bit14 */
			{20399,44,0}, /* core5 return_Stack5 bit15 */
			{16364,44,0}, /* core5 return_Stack5 bit16 */
			{16363,44,0}, /* core5 return_Stack5 bit17 */
			{16342,44,0}, /* core5 return_Stack5 bit18 */
			{16341,44,0}, /* core5 return_Stack5 bit19 */
			{20390,44,0}, /* core5 return_Stack5 bit20 */
			{20389,44,0}, /* core5 return_Stack5 bit21 */
			{20388,44,0}, /* core5 return_Stack5 bit22 */
			{20387,44,0}, /* core5 return_Stack5 bit23 */
			{20282,44,0}, /* core5 return_Stack5 bit24 */
			{20281,44,0}, /* core5 return_Stack5 bit25 */
			{20280,44,0}, /* core5 return_Stack5 bit26 */
			{20279,44,0}, /* core5 return_Stack5 bit27 */
			{16514,44,0}, /* core5 return_Stack5 bit28 */
			{16513,44,0}, /* core5 return_Stack5 bit29 */
			{16452,44,0}, /* core5 return_Stack5 bit30 */
			{20286,44,0}, /* core5 return_Stack5 bit31 */
			{16451,44,0}, /* core5 return_Stack5 bit32 */
			{20285,44,0}, /* core5 return_Stack5 bit33 */
			{20284,44,0}, /* core5 return_Stack5 bit34 */
			{20283,44,0}, /* core5 return_Stack5 bit35 */
			{20326,44,0}, /* core5 return_Stack5 bit36 */
			{20325,44,0}, /* core5 return_Stack5 bit37 */
			{20324,44,0}, /* core5 return_Stack5 bit38 */
			{20323,44,0}, /* core5 return_Stack5 bit39 */
			{20338,44,0}, /* core5 return_Stack5 bit40 */
			{20337,44,0}, /* core5 return_Stack5 bit41 */
			{20336,44,0}, /* core5 return_Stack5 bit42 */
			{20335,44,0}, /* core5 return_Stack5 bit43 */
			{20354,44,0}, /* core5 return_Stack5 bit44 */
			{20353,44,0}, /* core5 return_Stack5 bit45 */
			{20352,44,0}, /* core5 return_Stack5 bit46 */
			{20351,44,0}, /* core5 return_Stack5 bit47 */
			{13580,44,1}, /* core5 return_Stack5 bit48 */
			{    0, 0,2}, /* core5 return_Stack5 bit49 */
			{    0, 0,2}, /* core5 return_Stack5 bit50 */
			{    0, 0,2}, /* core5 return_Stack5 bit51 */
			{    0, 0,2}, /* core5 return_Stack5 bit52 */
			{    0, 0,2}, /* core5 return_Stack5 bit53 */
			{    0, 0,2}, /* core5 return_Stack5 bit54 */
			{    0, 0,2}, /* core5 return_Stack5 bit55 */
			{    0, 0,2}, /* core5 return_Stack5 bit56 */
			{    0, 0,2}, /* core5 return_Stack5 bit57 */
			{    0, 0,2}, /* core5 return_Stack5 bit58 */
			{    0, 0,2}, /* core5 return_Stack5 bit59 */
			{    0, 0,2}, /* core5 return_Stack5 bit60 */
			{    0, 0,2}, /* core5 return_Stack5 bit61 */
			{    0, 0,2}, /* core5 return_Stack5 bit62 */
			{    0, 0,2}, /* core5 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{20358,44,0}, /* core5 return_Stack6 bit0 */
			{20357,44,0}, /* core5 return_Stack6 bit1 */
			{20356,44,0}, /* core5 return_Stack6 bit2 */
			{20355,44,0}, /* core5 return_Stack6 bit3 */
			{20258,44,0}, /* core5 return_Stack6 bit4 */
			{20257,44,0}, /* core5 return_Stack6 bit5 */
			{20256,44,0}, /* core5 return_Stack6 bit6 */
			{20255,44,0}, /* core5 return_Stack6 bit7 */
			{16436,44,0}, /* core5 return_Stack6 bit8 */
			{20410,44,0}, /* core5 return_Stack6 bit9 */
			{16435,44,0}, /* core5 return_Stack6 bit10 */
			{20409,44,0}, /* core5 return_Stack6 bit11 */
			{20408,44,0}, /* core5 return_Stack6 bit12 */
			{20407,44,0}, /* core5 return_Stack6 bit13 */
			{16356,44,0}, /* core5 return_Stack6 bit14 */
			{16355,44,0}, /* core5 return_Stack6 bit15 */
			{16358,44,0}, /* core5 return_Stack6 bit16 */
			{16357,44,0}, /* core5 return_Stack6 bit17 */
			{20386,44,0}, /* core5 return_Stack6 bit18 */
			{20385,44,0}, /* core5 return_Stack6 bit19 */
			{20384,44,0}, /* core5 return_Stack6 bit20 */
			{20383,44,0}, /* core5 return_Stack6 bit21 */
			{20382,44,0}, /* core5 return_Stack6 bit22 */
			{20381,44,0}, /* core5 return_Stack6 bit23 */
			{20380,44,0}, /* core5 return_Stack6 bit24 */
			{20379,44,0}, /* core5 return_Stack6 bit25 */
			{20278,44,0}, /* core5 return_Stack6 bit26 */
			{20277,44,0}, /* core5 return_Stack6 bit27 */
			{20276,44,0}, /* core5 return_Stack6 bit28 */
			{20275,44,0}, /* core5 return_Stack6 bit29 */
			{16448,44,0}, /* core5 return_Stack6 bit30 */
			{16447,44,0}, /* core5 return_Stack6 bit31 */
			{16450,44,0}, /* core5 return_Stack6 bit32 */
			{16449,44,0}, /* core5 return_Stack6 bit33 */
			{20302,44,0}, /* core5 return_Stack6 bit34 */
			{20301,44,0}, /* core5 return_Stack6 bit35 */
			{20300,44,0}, /* core5 return_Stack6 bit36 */
			{20299,44,0}, /* core5 return_Stack6 bit37 */
			{20334,44,0}, /* core5 return_Stack6 bit38 */
			{20333,44,0}, /* core5 return_Stack6 bit39 */
			{20332,44,0}, /* core5 return_Stack6 bit40 */
			{20331,44,0}, /* core5 return_Stack6 bit41 */
			{20346,44,0}, /* core5 return_Stack6 bit42 */
			{20345,44,0}, /* core5 return_Stack6 bit43 */
			{20344,44,0}, /* core5 return_Stack6 bit44 */
			{20343,44,0}, /* core5 return_Stack6 bit45 */
			{16442,44,0}, /* core5 return_Stack6 bit46 */
			{16441,44,0}, /* core5 return_Stack6 bit47 */
			{13582,44,1}, /* core5 return_Stack6 bit48 */
			{    0, 0,2}, /* core5 return_Stack6 bit49 */
			{    0, 0,2}, /* core5 return_Stack6 bit50 */
			{    0, 0,2}, /* core5 return_Stack6 bit51 */
			{    0, 0,2}, /* core5 return_Stack6 bit52 */
			{    0, 0,2}, /* core5 return_Stack6 bit53 */
			{    0, 0,2}, /* core5 return_Stack6 bit54 */
			{    0, 0,2}, /* core5 return_Stack6 bit55 */
			{    0, 0,2}, /* core5 return_Stack6 bit56 */
			{    0, 0,2}, /* core5 return_Stack6 bit57 */
			{    0, 0,2}, /* core5 return_Stack6 bit58 */
			{    0, 0,2}, /* core5 return_Stack6 bit59 */
			{    0, 0,2}, /* core5 return_Stack6 bit60 */
			{    0, 0,2}, /* core5 return_Stack6 bit61 */
			{    0, 0,2}, /* core5 return_Stack6 bit62 */
			{    0, 0,2}, /* core5 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{20294,44,0}, /* core5 return_Stack7 bit0 */
			{20293,44,0}, /* core5 return_Stack7 bit1 */
			{20292,44,0}, /* core5 return_Stack7 bit2 */
			{20291,44,0}, /* core5 return_Stack7 bit3 */
			{20274,44,0}, /* core5 return_Stack7 bit4 */
			{20273,44,0}, /* core5 return_Stack7 bit5 */
			{20290,44,0}, /* core5 return_Stack7 bit6 */
			{20272,44,0}, /* core5 return_Stack7 bit7 */
			{20271,44,0}, /* core5 return_Stack7 bit8 */
			{20414,44,0}, /* core5 return_Stack7 bit9 */
			{20413,44,0}, /* core5 return_Stack7 bit10 */
			{20412,44,0}, /* core5 return_Stack7 bit11 */
			{20411,44,0}, /* core5 return_Stack7 bit12 */
			{20406,44,0}, /* core5 return_Stack7 bit13 */
			{20405,44,0}, /* core5 return_Stack7 bit14 */
			{20404,44,0}, /* core5 return_Stack7 bit15 */
			{20403,44,0}, /* core5 return_Stack7 bit16 */
			{20422,44,0}, /* core5 return_Stack7 bit17 */
			{20421,44,0}, /* core5 return_Stack7 bit18 */
			{20426,44,0}, /* core5 return_Stack7 bit19 */
			{20420,44,0}, /* core5 return_Stack7 bit20 */
			{20419,44,0}, /* core5 return_Stack7 bit21 */
			{20425,44,0}, /* core5 return_Stack7 bit22 */
			{20424,44,0}, /* core5 return_Stack7 bit23 */
			{20423,44,0}, /* core5 return_Stack7 bit24 */
			{16502,44,0}, /* core5 return_Stack7 bit25 */
			{16501,44,0}, /* core5 return_Stack7 bit26 */
			{16510,44,0}, /* core5 return_Stack7 bit27 */
			{16509,44,0}, /* core5 return_Stack7 bit28 */
			{16516,44,0}, /* core5 return_Stack7 bit29 */
			{16515,44,0}, /* core5 return_Stack7 bit30 */
			{20289,44,0}, /* core5 return_Stack7 bit31 */
			{13575,44,1}, /* core5 return_Stack7 bit32 */
			{20288,44,0}, /* core5 return_Stack7 bit33 */
			{20287,44,0}, /* core5 return_Stack7 bit34 */
			{20322,44,0}, /* core5 return_Stack7 bit35 */
			{20321,44,0}, /* core5 return_Stack7 bit36 */
			{20320,44,0}, /* core5 return_Stack7 bit37 */
			{20319,44,0}, /* core5 return_Stack7 bit38 */
			{20330,44,0}, /* core5 return_Stack7 bit39 */
			{20329,44,0}, /* core5 return_Stack7 bit40 */
			{20328,44,0}, /* core5 return_Stack7 bit41 */
			{20327,44,0}, /* core5 return_Stack7 bit42 */
			{20350,44,0}, /* core5 return_Stack7 bit43 */
			{20349,44,0}, /* core5 return_Stack7 bit44 */
			{20348,44,0}, /* core5 return_Stack7 bit45 */
			{20347,44,0}, /* core5 return_Stack7 bit46 */
			{13579,44,1}, /* core5 return_Stack7 bit47 */
			{13578,44,1}, /* core5 return_Stack7 bit48 */
			{    0, 0,2}, /* core5 return_Stack7 bit49 */
			{    0, 0,2}, /* core5 return_Stack7 bit50 */
			{    0, 0,2}, /* core5 return_Stack7 bit51 */
			{    0, 0,2}, /* core5 return_Stack7 bit52 */
			{    0, 0,2}, /* core5 return_Stack7 bit53 */
			{    0, 0,2}, /* core5 return_Stack7 bit54 */
			{    0, 0,2}, /* core5 return_Stack7 bit55 */
			{    0, 0,2}, /* core5 return_Stack7 bit56 */
			{    0, 0,2}, /* core5 return_Stack7 bit57 */
			{    0, 0,2}, /* core5 return_Stack7 bit58 */
			{    0, 0,2}, /* core5 return_Stack7 bit59 */
			{    0, 0,2}, /* core5 return_Stack7 bit60 */
			{    0, 0,2}, /* core5 return_Stack7 bit61 */
			{    0, 0,2}, /* core5 return_Stack7 bit62 */
			{    0, 0,2}, /* core5 return_Stack7 bit63 */
			}},
			.L2_parity_err_count = {{
			{ 6893, 8,0}, /* core5 L2_parity_err_count bit0 */
			{ 6892, 8,0}, /* core5 L2_parity_err_count bit1 */
			{ 6891, 8,0}, /* core5 L2_parity_err_count bit2 */
			{ 6890, 8,0}, /* core5 L2_parity_err_count bit3 */
			{ 6889, 8,0}, /* core5 L2_parity_err_count bit4 */
			{ 6888, 8,0}, /* core5 L2_parity_err_count bit5 */
			{ 6887, 8,0}, /* core5 L2_parity_err_count bit6 */
			{ 6886, 8,0}, /* core5 L2_parity_err_count bit7 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit8 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit9 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit10 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit11 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit12 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit13 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit14 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit15 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit16 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit17 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit18 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit19 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit20 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit21 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit22 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit23 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit24 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit25 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit26 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit27 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit28 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit29 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit30 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit31 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit32 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit33 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit34 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit35 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit36 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit37 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit38 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit39 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit40 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit41 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit42 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit43 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit44 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit45 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit46 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit47 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit48 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit49 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit50 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit51 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit52 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit53 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit54 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit55 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit56 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit57 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit58 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit59 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit60 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit61 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit62 */
			{    0, 0,2}, /* core5 L2_parity_err_count bit63 */
			}},
			.L2_parity_index = {{
			{ 6660, 8,0}, /* core5 L2_parity_index bit0 */
			{ 6659, 8,0}, /* core5 L2_parity_index bit1 */
			{ 6658, 8,0}, /* core5 L2_parity_index bit2 */
			{ 6657, 8,0}, /* core5 L2_parity_index bit3 */
			{ 6656, 8,0}, /* core5 L2_parity_index bit4 */
			{ 6655, 8,0}, /* core5 L2_parity_index bit5 */
			{ 6654, 8,0}, /* core5 L2_parity_index bit6 */
			{ 6653, 8,0}, /* core5 L2_parity_index bit7 */
			{ 6668, 8,0}, /* core5 L2_parity_index bit8 */
			{ 6667, 8,0}, /* core5 L2_parity_index bit9 */
			{ 6666, 8,0}, /* core5 L2_parity_index bit10 */
			{ 6665, 8,0}, /* core5 L2_parity_index bit11 */
			{    0, 0,2}, /* core5 L2_parity_index bit12 */
			{    0, 0,2}, /* core5 L2_parity_index bit13 */
			{    0, 0,2}, /* core5 L2_parity_index bit14 */
			{    0, 0,2}, /* core5 L2_parity_index bit15 */
			{    0, 0,2}, /* core5 L2_parity_index bit16 */
			{    0, 0,2}, /* core5 L2_parity_index bit17 */
			{    0, 0,2}, /* core5 L2_parity_index bit18 */
			{    0, 0,2}, /* core5 L2_parity_index bit19 */
			{    0, 0,2}, /* core5 L2_parity_index bit20 */
			{    0, 0,2}, /* core5 L2_parity_index bit21 */
			{    0, 0,2}, /* core5 L2_parity_index bit22 */
			{    0, 0,2}, /* core5 L2_parity_index bit23 */
			{    0, 0,2}, /* core5 L2_parity_index bit24 */
			{    0, 0,2}, /* core5 L2_parity_index bit25 */
			{    0, 0,2}, /* core5 L2_parity_index bit26 */
			{    0, 0,2}, /* core5 L2_parity_index bit27 */
			{    0, 0,2}, /* core5 L2_parity_index bit28 */
			{    0, 0,2}, /* core5 L2_parity_index bit29 */
			{    0, 0,2}, /* core5 L2_parity_index bit30 */
			{    0, 0,2}, /* core5 L2_parity_index bit31 */
			{    0, 0,2}, /* core5 L2_parity_index bit32 */
			{    0, 0,2}, /* core5 L2_parity_index bit33 */
			{    0, 0,2}, /* core5 L2_parity_index bit34 */
			{    0, 0,2}, /* core5 L2_parity_index bit35 */
			{    0, 0,2}, /* core5 L2_parity_index bit36 */
			{    0, 0,2}, /* core5 L2_parity_index bit37 */
			{    0, 0,2}, /* core5 L2_parity_index bit38 */
			{    0, 0,2}, /* core5 L2_parity_index bit39 */
			{    0, 0,2}, /* core5 L2_parity_index bit40 */
			{    0, 0,2}, /* core5 L2_parity_index bit41 */
			{    0, 0,2}, /* core5 L2_parity_index bit42 */
			{    0, 0,2}, /* core5 L2_parity_index bit43 */
			{    0, 0,2}, /* core5 L2_parity_index bit44 */
			{    0, 0,2}, /* core5 L2_parity_index bit45 */
			{    0, 0,2}, /* core5 L2_parity_index bit46 */
			{    0, 0,2}, /* core5 L2_parity_index bit47 */
			{    0, 0,2}, /* core5 L2_parity_index bit48 */
			{    0, 0,2}, /* core5 L2_parity_index bit49 */
			{    0, 0,2}, /* core5 L2_parity_index bit50 */
			{    0, 0,2}, /* core5 L2_parity_index bit51 */
			{    0, 0,2}, /* core5 L2_parity_index bit52 */
			{    0, 0,2}, /* core5 L2_parity_index bit53 */
			{    0, 0,2}, /* core5 L2_parity_index bit54 */
			{    0, 0,2}, /* core5 L2_parity_index bit55 */
			{    0, 0,2}, /* core5 L2_parity_index bit56 */
			{    0, 0,2}, /* core5 L2_parity_index bit57 */
			{    0, 0,2}, /* core5 L2_parity_index bit58 */
			{    0, 0,2}, /* core5 L2_parity_index bit59 */
			{    0, 0,2}, /* core5 L2_parity_index bit60 */
			{    0, 0,2}, /* core5 L2_parity_index bit61 */
			{    0, 0,2}, /* core5 L2_parity_index bit62 */
			{    0, 0,2}, /* core5 L2_parity_index bit63 */
			}},
			.L2_parity_way = {{
			{ 6661, 8,0}, /* core5 L2_parity_way bit0 */
			{ 6505, 8,0}, /* core5 L2_parity_way bit1 */
			{    0, 0,2}, /* core5 L2_parity_way bit2 */
			{    0, 0,2}, /* core5 L2_parity_way bit3 */
			{    0, 0,2}, /* core5 L2_parity_way bit4 */
			{    0, 0,2}, /* core5 L2_parity_way bit5 */
			{    0, 0,2}, /* core5 L2_parity_way bit6 */
			{    0, 0,2}, /* core5 L2_parity_way bit7 */
			{    0, 0,2}, /* core5 L2_parity_way bit8 */
			{    0, 0,2}, /* core5 L2_parity_way bit9 */
			{    0, 0,2}, /* core5 L2_parity_way bit10 */
			{    0, 0,2}, /* core5 L2_parity_way bit11 */
			{    0, 0,2}, /* core5 L2_parity_way bit12 */
			{    0, 0,2}, /* core5 L2_parity_way bit13 */
			{    0, 0,2}, /* core5 L2_parity_way bit14 */
			{    0, 0,2}, /* core5 L2_parity_way bit15 */
			{    0, 0,2}, /* core5 L2_parity_way bit16 */
			{    0, 0,2}, /* core5 L2_parity_way bit17 */
			{    0, 0,2}, /* core5 L2_parity_way bit18 */
			{    0, 0,2}, /* core5 L2_parity_way bit19 */
			{    0, 0,2}, /* core5 L2_parity_way bit20 */
			{    0, 0,2}, /* core5 L2_parity_way bit21 */
			{    0, 0,2}, /* core5 L2_parity_way bit22 */
			{    0, 0,2}, /* core5 L2_parity_way bit23 */
			{    0, 0,2}, /* core5 L2_parity_way bit24 */
			{    0, 0,2}, /* core5 L2_parity_way bit25 */
			{    0, 0,2}, /* core5 L2_parity_way bit26 */
			{    0, 0,2}, /* core5 L2_parity_way bit27 */
			{    0, 0,2}, /* core5 L2_parity_way bit28 */
			{    0, 0,2}, /* core5 L2_parity_way bit29 */
			{    0, 0,2}, /* core5 L2_parity_way bit30 */
			{    0, 0,2}, /* core5 L2_parity_way bit31 */
			{    0, 0,2}, /* core5 L2_parity_way bit32 */
			{    0, 0,2}, /* core5 L2_parity_way bit33 */
			{    0, 0,2}, /* core5 L2_parity_way bit34 */
			{    0, 0,2}, /* core5 L2_parity_way bit35 */
			{    0, 0,2}, /* core5 L2_parity_way bit36 */
			{    0, 0,2}, /* core5 L2_parity_way bit37 */
			{    0, 0,2}, /* core5 L2_parity_way bit38 */
			{    0, 0,2}, /* core5 L2_parity_way bit39 */
			{    0, 0,2}, /* core5 L2_parity_way bit40 */
			{    0, 0,2}, /* core5 L2_parity_way bit41 */
			{    0, 0,2}, /* core5 L2_parity_way bit42 */
			{    0, 0,2}, /* core5 L2_parity_way bit43 */
			{    0, 0,2}, /* core5 L2_parity_way bit44 */
			{    0, 0,2}, /* core5 L2_parity_way bit45 */
			{    0, 0,2}, /* core5 L2_parity_way bit46 */
			{    0, 0,2}, /* core5 L2_parity_way bit47 */
			{    0, 0,2}, /* core5 L2_parity_way bit48 */
			{    0, 0,2}, /* core5 L2_parity_way bit49 */
			{    0, 0,2}, /* core5 L2_parity_way bit50 */
			{    0, 0,2}, /* core5 L2_parity_way bit51 */
			{    0, 0,2}, /* core5 L2_parity_way bit52 */
			{    0, 0,2}, /* core5 L2_parity_way bit53 */
			{    0, 0,2}, /* core5 L2_parity_way bit54 */
			{    0, 0,2}, /* core5 L2_parity_way bit55 */
			{    0, 0,2}, /* core5 L2_parity_way bit56 */
			{    0, 0,2}, /* core5 L2_parity_way bit57 */
			{    0, 0,2}, /* core5 L2_parity_way bit58 */
			{    0, 0,2}, /* core5 L2_parity_way bit59 */
			{    0, 0,2}, /* core5 L2_parity_way bit60 */
			{    0, 0,2}, /* core5 L2_parity_way bit61 */
			{    0, 0,2}, /* core5 L2_parity_way bit62 */
			{    0, 0,2}, /* core5 L2_parity_way bit63 */
			}},
			.L2_parity_banks = {{
			{ 6885, 8,0}, /* core5 L2_parity_banks bit0 */
			{ 6884, 8,0}, /* core5 L2_parity_banks bit1 */
			{ 6883, 8,0}, /* core5 L2_parity_banks bit2 */
			{ 6882, 8,0}, /* core5 L2_parity_banks bit3 */
			{ 6881, 8,0}, /* core5 L2_parity_banks bit4 */
			{ 6880, 8,0}, /* core5 L2_parity_banks bit5 */
			{ 6879, 8,0}, /* core5 L2_parity_banks bit6 */
			{ 6878, 8,0}, /* core5 L2_parity_banks bit7 */
			{ 6877, 8,0}, /* core5 L2_parity_banks bit8 */
			{ 6876, 8,0}, /* core5 L2_parity_banks bit9 */
			{ 6875, 8,0}, /* core5 L2_parity_banks bit10 */
			{ 6874, 8,0}, /* core5 L2_parity_banks bit11 */
			{ 6873, 8,0}, /* core5 L2_parity_banks bit12 */
			{ 6872, 8,0}, /* core5 L2_parity_banks bit13 */
			{ 6871, 8,0}, /* core5 L2_parity_banks bit14 */
			{ 6870, 8,0}, /* core5 L2_parity_banks bit15 */
			{    0, 0,2}, /* core5 L2_parity_banks bit16 */
			{    0, 0,2}, /* core5 L2_parity_banks bit17 */
			{    0, 0,2}, /* core5 L2_parity_banks bit18 */
			{    0, 0,2}, /* core5 L2_parity_banks bit19 */
			{    0, 0,2}, /* core5 L2_parity_banks bit20 */
			{    0, 0,2}, /* core5 L2_parity_banks bit21 */
			{    0, 0,2}, /* core5 L2_parity_banks bit22 */
			{    0, 0,2}, /* core5 L2_parity_banks bit23 */
			{    0, 0,2}, /* core5 L2_parity_banks bit24 */
			{    0, 0,2}, /* core5 L2_parity_banks bit25 */
			{    0, 0,2}, /* core5 L2_parity_banks bit26 */
			{    0, 0,2}, /* core5 L2_parity_banks bit27 */
			{    0, 0,2}, /* core5 L2_parity_banks bit28 */
			{    0, 0,2}, /* core5 L2_parity_banks bit29 */
			{    0, 0,2}, /* core5 L2_parity_banks bit30 */
			{    0, 0,2}, /* core5 L2_parity_banks bit31 */
			{    0, 0,2}, /* core5 L2_parity_banks bit32 */
			{    0, 0,2}, /* core5 L2_parity_banks bit33 */
			{    0, 0,2}, /* core5 L2_parity_banks bit34 */
			{    0, 0,2}, /* core5 L2_parity_banks bit35 */
			{    0, 0,2}, /* core5 L2_parity_banks bit36 */
			{    0, 0,2}, /* core5 L2_parity_banks bit37 */
			{    0, 0,2}, /* core5 L2_parity_banks bit38 */
			{    0, 0,2}, /* core5 L2_parity_banks bit39 */
			{    0, 0,2}, /* core5 L2_parity_banks bit40 */
			{    0, 0,2}, /* core5 L2_parity_banks bit41 */
			{    0, 0,2}, /* core5 L2_parity_banks bit42 */
			{    0, 0,2}, /* core5 L2_parity_banks bit43 */
			{    0, 0,2}, /* core5 L2_parity_banks bit44 */
			{    0, 0,2}, /* core5 L2_parity_banks bit45 */
			{    0, 0,2}, /* core5 L2_parity_banks bit46 */
			{    0, 0,2}, /* core5 L2_parity_banks bit47 */
			{    0, 0,2}, /* core5 L2_parity_banks bit48 */
			{    0, 0,2}, /* core5 L2_parity_banks bit49 */
			{    0, 0,2}, /* core5 L2_parity_banks bit50 */
			{    0, 0,2}, /* core5 L2_parity_banks bit51 */
			{    0, 0,2}, /* core5 L2_parity_banks bit52 */
			{    0, 0,2}, /* core5 L2_parity_banks bit53 */
			{    0, 0,2}, /* core5 L2_parity_banks bit54 */
			{    0, 0,2}, /* core5 L2_parity_banks bit55 */
			{    0, 0,2}, /* core5 L2_parity_banks bit56 */
			{    0, 0,2}, /* core5 L2_parity_banks bit57 */
			{    0, 0,2}, /* core5 L2_parity_banks bit58 */
			{    0, 0,2}, /* core5 L2_parity_banks bit59 */
			{    0, 0,2}, /* core5 L2_parity_banks bit60 */
			{    0, 0,2}, /* core5 L2_parity_banks bit61 */
			{    0, 0,2}, /* core5 L2_parity_banks bit62 */
			{    0, 0,2}, /* core5 L2_parity_banks bit63 */
			}},
	},
}; 

struct big_core_spec big_core[] = {
	{		/* core 6 */ 
			.i0_valid = {{
			{24167,48,0}, /* core6 i0_valid bit0 */
			{    0, 0,2}, /* core6 i0_valid bit1 */
			{    0, 0,2}, /* core6 i0_valid bit2 */
			{    0, 0,2}, /* core6 i0_valid bit3 */
			{    0, 0,2}, /* core6 i0_valid bit4 */
			{    0, 0,2}, /* core6 i0_valid bit5 */
			{    0, 0,2}, /* core6 i0_valid bit6 */
			{    0, 0,2}, /* core6 i0_valid bit7 */
			{    0, 0,2}, /* core6 i0_valid bit8 */
			{    0, 0,2}, /* core6 i0_valid bit9 */
			{    0, 0,2}, /* core6 i0_valid bit10 */
			{    0, 0,2}, /* core6 i0_valid bit11 */
			{    0, 0,2}, /* core6 i0_valid bit12 */
			{    0, 0,2}, /* core6 i0_valid bit13 */
			{    0, 0,2}, /* core6 i0_valid bit14 */
			{    0, 0,2}, /* core6 i0_valid bit15 */
			{    0, 0,2}, /* core6 i0_valid bit16 */
			{    0, 0,2}, /* core6 i0_valid bit17 */
			{    0, 0,2}, /* core6 i0_valid bit18 */
			{    0, 0,2}, /* core6 i0_valid bit19 */
			{    0, 0,2}, /* core6 i0_valid bit20 */
			{    0, 0,2}, /* core6 i0_valid bit21 */
			{    0, 0,2}, /* core6 i0_valid bit22 */
			{    0, 0,2}, /* core6 i0_valid bit23 */
			{    0, 0,2}, /* core6 i0_valid bit24 */
			{    0, 0,2}, /* core6 i0_valid bit25 */
			{    0, 0,2}, /* core6 i0_valid bit26 */
			{    0, 0,2}, /* core6 i0_valid bit27 */
			{    0, 0,2}, /* core6 i0_valid bit28 */
			{    0, 0,2}, /* core6 i0_valid bit29 */
			{    0, 0,2}, /* core6 i0_valid bit30 */
			{    0, 0,2}, /* core6 i0_valid bit31 */
			{    0, 0,2}, /* core6 i0_valid bit32 */
			{    0, 0,2}, /* core6 i0_valid bit33 */
			{    0, 0,2}, /* core6 i0_valid bit34 */
			{    0, 0,2}, /* core6 i0_valid bit35 */
			{    0, 0,2}, /* core6 i0_valid bit36 */
			{    0, 0,2}, /* core6 i0_valid bit37 */
			{    0, 0,2}, /* core6 i0_valid bit38 */
			{    0, 0,2}, /* core6 i0_valid bit39 */
			{    0, 0,2}, /* core6 i0_valid bit40 */
			{    0, 0,2}, /* core6 i0_valid bit41 */
			{    0, 0,2}, /* core6 i0_valid bit42 */
			{    0, 0,2}, /* core6 i0_valid bit43 */
			{    0, 0,2}, /* core6 i0_valid bit44 */
			{    0, 0,2}, /* core6 i0_valid bit45 */
			{    0, 0,2}, /* core6 i0_valid bit46 */
			{    0, 0,2}, /* core6 i0_valid bit47 */
			{    0, 0,2}, /* core6 i0_valid bit48 */
			{    0, 0,2}, /* core6 i0_valid bit49 */
			{    0, 0,2}, /* core6 i0_valid bit50 */
			{    0, 0,2}, /* core6 i0_valid bit51 */
			{    0, 0,2}, /* core6 i0_valid bit52 */
			{    0, 0,2}, /* core6 i0_valid bit53 */
			{    0, 0,2}, /* core6 i0_valid bit54 */
			{    0, 0,2}, /* core6 i0_valid bit55 */
			{    0, 0,2}, /* core6 i0_valid bit56 */
			{    0, 0,2}, /* core6 i0_valid bit57 */
			{    0, 0,2}, /* core6 i0_valid bit58 */
			{    0, 0,2}, /* core6 i0_valid bit59 */
			{    0, 0,2}, /* core6 i0_valid bit60 */
			{    0, 0,2}, /* core6 i0_valid bit61 */
			{    0, 0,2}, /* core6 i0_valid bit62 */
			{    0, 0,2}, /* core6 i0_valid bit63 */
			}},
			.i0_pc = {{
			{  578,46,0}, /* core6 i0_pc bit0 */
			{  577,46,0}, /* core6 i0_pc bit1 */
			{  575,46,0}, /* core6 i0_pc bit2 */
			{  576,46,0}, /* core6 i0_pc bit3 */
			{ 6407,45,0}, /* core6 i0_pc bit4 */
			{21066,46,0}, /* core6 i0_pc bit5 */
			{21061,46,0}, /* core6 i0_pc bit6 */
			{21065,46,0}, /* core6 i0_pc bit7 */
			{ 6405,45,0}, /* core6 i0_pc bit8 */
			{21064,46,0}, /* core6 i0_pc bit9 */
			{21052,46,0}, /* core6 i0_pc bit10 */
			{21056,46,0}, /* core6 i0_pc bit11 */
			{21060,46,0}, /* core6 i0_pc bit12 */
			{21053,46,0}, /* core6 i0_pc bit13 */
			{ 6409,45,0}, /* core6 i0_pc bit14 */
			{ 6411,45,0}, /* core6 i0_pc bit15 */
			{  581,46,0}, /* core6 i0_pc bit16 */
			{  582,46,0}, /* core6 i0_pc bit17 */
			{  580,46,0}, /* core6 i0_pc bit18 */
			{  579,46,0}, /* core6 i0_pc bit19 */
			{ 6406,45,0}, /* core6 i0_pc bit20 */
			{21063,46,0}, /* core6 i0_pc bit21 */
			{21058,46,0}, /* core6 i0_pc bit22 */
			{21057,46,0}, /* core6 i0_pc bit23 */
			{ 6404,45,0}, /* core6 i0_pc bit24 */
			{21062,46,0}, /* core6 i0_pc bit25 */
			{ 6410,45,0}, /* core6 i0_pc bit26 */
			{21051,46,0}, /* core6 i0_pc bit27 */
			{21059,46,0}, /* core6 i0_pc bit28 */
			{21054,46,0}, /* core6 i0_pc bit29 */
			{ 6408,45,0}, /* core6 i0_pc bit30 */
			{21055,46,0}, /* core6 i0_pc bit31 */
			{12198,48,0}, /* core6 i0_pc bit32 */
			{12197,48,0}, /* core6 i0_pc bit33 */
			{12204,48,0}, /* core6 i0_pc bit34 */
			{12199,48,0}, /* core6 i0_pc bit35 */
			{12215,48,0}, /* core6 i0_pc bit36 */
			{12208,48,0}, /* core6 i0_pc bit37 */
			{12210,48,0}, /* core6 i0_pc bit38 */
			{12211,48,0}, /* core6 i0_pc bit39 */
			{12196,48,0}, /* core6 i0_pc bit40 */
			{ 6419,45,0}, /* core6 i0_pc bit41 */
			{12219,48,0}, /* core6 i0_pc bit42 */
			{ 6414,45,0}, /* core6 i0_pc bit43 */
			{ 6418,45,0}, /* core6 i0_pc bit44 */
			{ 6413,45,0}, /* core6 i0_pc bit45 */
			{ 6412,45,0}, /* core6 i0_pc bit46 */
			{ 6415,45,0}, /* core6 i0_pc bit47 */
			{12201,48,0}, /* core6 i0_pc bit48 */
			{12205,48,0}, /* core6 i0_pc bit49 */
			{12200,48,0}, /* core6 i0_pc bit50 */
			{12202,48,0}, /* core6 i0_pc bit51 */
			{12212,48,0}, /* core6 i0_pc bit52 */
			{12213,48,0}, /* core6 i0_pc bit53 */
			{12214,48,0}, /* core6 i0_pc bit54 */
			{12209,48,0}, /* core6 i0_pc bit55 */
			{12206,48,0}, /* core6 i0_pc bit56 */
			{12217,48,0}, /* core6 i0_pc bit57 */
			{ 6416,45,0}, /* core6 i0_pc bit58 */
			{ 6417,45,0}, /* core6 i0_pc bit59 */
			{12216,48,0}, /* core6 i0_pc bit60 */
			{12218,48,0}, /* core6 i0_pc bit61 */
			{12203,48,0}, /* core6 i0_pc bit62 */
			{12207,48,0}, /* core6 i0_pc bit63 */
			}},
			.i1_valid = {{
			{24166,48,0}, /* core6 i1_valid bit0 */
			{    0, 0,2}, /* core6 i1_valid bit1 */
			{    0, 0,2}, /* core6 i1_valid bit2 */
			{    0, 0,2}, /* core6 i1_valid bit3 */
			{    0, 0,2}, /* core6 i1_valid bit4 */
			{    0, 0,2}, /* core6 i1_valid bit5 */
			{    0, 0,2}, /* core6 i1_valid bit6 */
			{    0, 0,2}, /* core6 i1_valid bit7 */
			{    0, 0,2}, /* core6 i1_valid bit8 */
			{    0, 0,2}, /* core6 i1_valid bit9 */
			{    0, 0,2}, /* core6 i1_valid bit10 */
			{    0, 0,2}, /* core6 i1_valid bit11 */
			{    0, 0,2}, /* core6 i1_valid bit12 */
			{    0, 0,2}, /* core6 i1_valid bit13 */
			{    0, 0,2}, /* core6 i1_valid bit14 */
			{    0, 0,2}, /* core6 i1_valid bit15 */
			{    0, 0,2}, /* core6 i1_valid bit16 */
			{    0, 0,2}, /* core6 i1_valid bit17 */
			{    0, 0,2}, /* core6 i1_valid bit18 */
			{    0, 0,2}, /* core6 i1_valid bit19 */
			{    0, 0,2}, /* core6 i1_valid bit20 */
			{    0, 0,2}, /* core6 i1_valid bit21 */
			{    0, 0,2}, /* core6 i1_valid bit22 */
			{    0, 0,2}, /* core6 i1_valid bit23 */
			{    0, 0,2}, /* core6 i1_valid bit24 */
			{    0, 0,2}, /* core6 i1_valid bit25 */
			{    0, 0,2}, /* core6 i1_valid bit26 */
			{    0, 0,2}, /* core6 i1_valid bit27 */
			{    0, 0,2}, /* core6 i1_valid bit28 */
			{    0, 0,2}, /* core6 i1_valid bit29 */
			{    0, 0,2}, /* core6 i1_valid bit30 */
			{    0, 0,2}, /* core6 i1_valid bit31 */
			{    0, 0,2}, /* core6 i1_valid bit32 */
			{    0, 0,2}, /* core6 i1_valid bit33 */
			{    0, 0,2}, /* core6 i1_valid bit34 */
			{    0, 0,2}, /* core6 i1_valid bit35 */
			{    0, 0,2}, /* core6 i1_valid bit36 */
			{    0, 0,2}, /* core6 i1_valid bit37 */
			{    0, 0,2}, /* core6 i1_valid bit38 */
			{    0, 0,2}, /* core6 i1_valid bit39 */
			{    0, 0,2}, /* core6 i1_valid bit40 */
			{    0, 0,2}, /* core6 i1_valid bit41 */
			{    0, 0,2}, /* core6 i1_valid bit42 */
			{    0, 0,2}, /* core6 i1_valid bit43 */
			{    0, 0,2}, /* core6 i1_valid bit44 */
			{    0, 0,2}, /* core6 i1_valid bit45 */
			{    0, 0,2}, /* core6 i1_valid bit46 */
			{    0, 0,2}, /* core6 i1_valid bit47 */
			{    0, 0,2}, /* core6 i1_valid bit48 */
			{    0, 0,2}, /* core6 i1_valid bit49 */
			{    0, 0,2}, /* core6 i1_valid bit50 */
			{    0, 0,2}, /* core6 i1_valid bit51 */
			{    0, 0,2}, /* core6 i1_valid bit52 */
			{    0, 0,2}, /* core6 i1_valid bit53 */
			{    0, 0,2}, /* core6 i1_valid bit54 */
			{    0, 0,2}, /* core6 i1_valid bit55 */
			{    0, 0,2}, /* core6 i1_valid bit56 */
			{    0, 0,2}, /* core6 i1_valid bit57 */
			{    0, 0,2}, /* core6 i1_valid bit58 */
			{    0, 0,2}, /* core6 i1_valid bit59 */
			{    0, 0,2}, /* core6 i1_valid bit60 */
			{    0, 0,2}, /* core6 i1_valid bit61 */
			{    0, 0,2}, /* core6 i1_valid bit62 */
			{    0, 0,2}, /* core6 i1_valid bit63 */
			}},
			.i1_pc = {{
			{ 7236,51,0}, /* core6 i1_pc bit0 */
			{12189,48,0}, /* core6 i1_pc bit1 */
			{ 7238,51,0}, /* core6 i1_pc bit2 */
			{12220,48,0}, /* core6 i1_pc bit3 */
			{12227,48,0}, /* core6 i1_pc bit4 */
			{21074,46,0}, /* core6 i1_pc bit5 */
			{25366,47,0}, /* core6 i1_pc bit6 */
			{21073,46,0}, /* core6 i1_pc bit7 */
			{ 7233,51,0}, /* core6 i1_pc bit8 */
			{21070,46,0}, /* core6 i1_pc bit9 */
			{12221,48,0}, /* core6 i1_pc bit10 */
			{12223,48,0}, /* core6 i1_pc bit11 */
			{12222,48,0}, /* core6 i1_pc bit12 */
			{21067,46,0}, /* core6 i1_pc bit13 */
			{ 1069,46,0}, /* core6 i1_pc bit14 */
			{21071,46,0}, /* core6 i1_pc bit15 */
			{ 7234,51,0}, /* core6 i1_pc bit16 */
			{ 7237,51,0}, /* core6 i1_pc bit17 */
			{ 7239,51,0}, /* core6 i1_pc bit18 */
			{ 7240,51,0}, /* core6 i1_pc bit19 */
			{12224,48,0}, /* core6 i1_pc bit20 */
			{ 1072,46,0}, /* core6 i1_pc bit21 */
			{ 1073,46,0}, /* core6 i1_pc bit22 */
			{21068,46,0}, /* core6 i1_pc bit23 */
			{ 7235,51,0}, /* core6 i1_pc bit24 */
			{21072,46,0}, /* core6 i1_pc bit25 */
			{12226,48,0}, /* core6 i1_pc bit26 */
			{ 1071,46,0}, /* core6 i1_pc bit27 */
			{12225,48,0}, /* core6 i1_pc bit28 */
			{21069,46,0}, /* core6 i1_pc bit29 */
			{ 1070,46,0}, /* core6 i1_pc bit30 */
			{ 1074,46,0}, /* core6 i1_pc bit31 */
			{12260,48,0}, /* core6 i1_pc bit32 */
			{12252,48,0}, /* core6 i1_pc bit33 */
			{12253,48,0}, /* core6 i1_pc bit34 */
			{12251,48,0}, /* core6 i1_pc bit35 */
			{12248,48,0}, /* core6 i1_pc bit36 */
			{12228,48,0}, /* core6 i1_pc bit37 */
			{ 6172,45,0}, /* core6 i1_pc bit38 */
			{ 6171,45,0}, /* core6 i1_pc bit39 */
			{12247,48,0}, /* core6 i1_pc bit40 */
			{ 6173,45,0}, /* core6 i1_pc bit41 */
			{ 6177,45,0}, /* core6 i1_pc bit42 */
			{ 6176,45,0}, /* core6 i1_pc bit43 */
			{12235,48,0}, /* core6 i1_pc bit44 */
			{ 6174,45,0}, /* core6 i1_pc bit45 */
			{ 6175,45,0}, /* core6 i1_pc bit46 */
			{ 6170,45,0}, /* core6 i1_pc bit47 */
			{12246,48,0}, /* core6 i1_pc bit48 */
			{12257,48,0}, /* core6 i1_pc bit49 */
			{12256,48,0}, /* core6 i1_pc bit50 */
			{12250,48,0}, /* core6 i1_pc bit51 */
			{12254,48,0}, /* core6 i1_pc bit52 */
			{12258,48,0}, /* core6 i1_pc bit53 */
			{12261,48,0}, /* core6 i1_pc bit54 */
			{12229,48,0}, /* core6 i1_pc bit55 */
			{12255,48,0}, /* core6 i1_pc bit56 */
			{12259,48,0}, /* core6 i1_pc bit57 */
			{12249,48,0}, /* core6 i1_pc bit58 */
			{12230,48,0}, /* core6 i1_pc bit59 */
			{12231,48,0}, /* core6 i1_pc bit60 */
			{12233,48,0}, /* core6 i1_pc bit61 */
			{12232,48,0}, /* core6 i1_pc bit62 */
			{12234,48,0}, /* core6 i1_pc bit63 */
			}},
			.i2_valid = {{
			{24168,48,0}, /* core6 i2_valid bit0 */
			{    0, 0,2}, /* core6 i2_valid bit1 */
			{    0, 0,2}, /* core6 i2_valid bit2 */
			{    0, 0,2}, /* core6 i2_valid bit3 */
			{    0, 0,2}, /* core6 i2_valid bit4 */
			{    0, 0,2}, /* core6 i2_valid bit5 */
			{    0, 0,2}, /* core6 i2_valid bit6 */
			{    0, 0,2}, /* core6 i2_valid bit7 */
			{    0, 0,2}, /* core6 i2_valid bit8 */
			{    0, 0,2}, /* core6 i2_valid bit9 */
			{    0, 0,2}, /* core6 i2_valid bit10 */
			{    0, 0,2}, /* core6 i2_valid bit11 */
			{    0, 0,2}, /* core6 i2_valid bit12 */
			{    0, 0,2}, /* core6 i2_valid bit13 */
			{    0, 0,2}, /* core6 i2_valid bit14 */
			{    0, 0,2}, /* core6 i2_valid bit15 */
			{    0, 0,2}, /* core6 i2_valid bit16 */
			{    0, 0,2}, /* core6 i2_valid bit17 */
			{    0, 0,2}, /* core6 i2_valid bit18 */
			{    0, 0,2}, /* core6 i2_valid bit19 */
			{    0, 0,2}, /* core6 i2_valid bit20 */
			{    0, 0,2}, /* core6 i2_valid bit21 */
			{    0, 0,2}, /* core6 i2_valid bit22 */
			{    0, 0,2}, /* core6 i2_valid bit23 */
			{    0, 0,2}, /* core6 i2_valid bit24 */
			{    0, 0,2}, /* core6 i2_valid bit25 */
			{    0, 0,2}, /* core6 i2_valid bit26 */
			{    0, 0,2}, /* core6 i2_valid bit27 */
			{    0, 0,2}, /* core6 i2_valid bit28 */
			{    0, 0,2}, /* core6 i2_valid bit29 */
			{    0, 0,2}, /* core6 i2_valid bit30 */
			{    0, 0,2}, /* core6 i2_valid bit31 */
			{    0, 0,2}, /* core6 i2_valid bit32 */
			{    0, 0,2}, /* core6 i2_valid bit33 */
			{    0, 0,2}, /* core6 i2_valid bit34 */
			{    0, 0,2}, /* core6 i2_valid bit35 */
			{    0, 0,2}, /* core6 i2_valid bit36 */
			{    0, 0,2}, /* core6 i2_valid bit37 */
			{    0, 0,2}, /* core6 i2_valid bit38 */
			{    0, 0,2}, /* core6 i2_valid bit39 */
			{    0, 0,2}, /* core6 i2_valid bit40 */
			{    0, 0,2}, /* core6 i2_valid bit41 */
			{    0, 0,2}, /* core6 i2_valid bit42 */
			{    0, 0,2}, /* core6 i2_valid bit43 */
			{    0, 0,2}, /* core6 i2_valid bit44 */
			{    0, 0,2}, /* core6 i2_valid bit45 */
			{    0, 0,2}, /* core6 i2_valid bit46 */
			{    0, 0,2}, /* core6 i2_valid bit47 */
			{    0, 0,2}, /* core6 i2_valid bit48 */
			{    0, 0,2}, /* core6 i2_valid bit49 */
			{    0, 0,2}, /* core6 i2_valid bit50 */
			{    0, 0,2}, /* core6 i2_valid bit51 */
			{    0, 0,2}, /* core6 i2_valid bit52 */
			{    0, 0,2}, /* core6 i2_valid bit53 */
			{    0, 0,2}, /* core6 i2_valid bit54 */
			{    0, 0,2}, /* core6 i2_valid bit55 */
			{    0, 0,2}, /* core6 i2_valid bit56 */
			{    0, 0,2}, /* core6 i2_valid bit57 */
			{    0, 0,2}, /* core6 i2_valid bit58 */
			{    0, 0,2}, /* core6 i2_valid bit59 */
			{    0, 0,2}, /* core6 i2_valid bit60 */
			{    0, 0,2}, /* core6 i2_valid bit61 */
			{    0, 0,2}, /* core6 i2_valid bit62 */
			{    0, 0,2}, /* core6 i2_valid bit63 */
			}},
			.i2_pc = {{
			{24643,47,0}, /* core6 i2_pc bit0 */
			{20391,50,0}, /* core6 i2_pc bit1 */
			{20374,50,0}, /* core6 i2_pc bit2 */
			{20373,50,0}, /* core6 i2_pc bit3 */
			{20372,50,0}, /* core6 i2_pc bit4 */
			{20392,50,0}, /* core6 i2_pc bit5 */
			{20367,50,0}, /* core6 i2_pc bit6 */
			{20393,50,0}, /* core6 i2_pc bit7 */
			{24639,47,0}, /* core6 i2_pc bit8 */
			{20369,50,0}, /* core6 i2_pc bit9 */
			{24642,47,0}, /* core6 i2_pc bit10 */
			{20368,50,0}, /* core6 i2_pc bit11 */
			{24567,47,0}, /* core6 i2_pc bit12 */
			{20390,50,0}, /* core6 i2_pc bit13 */
			{20370,50,0}, /* core6 i2_pc bit14 */
			{20371,50,0}, /* core6 i2_pc bit15 */
			{24640,47,0}, /* core6 i2_pc bit16 */
			{24645,47,0}, /* core6 i2_pc bit17 */
			{20389,50,0}, /* core6 i2_pc bit18 */
			{24570,47,0}, /* core6 i2_pc bit19 */
			{20388,50,0}, /* core6 i2_pc bit20 */
			{24641,47,0}, /* core6 i2_pc bit21 */
			{24573,47,0}, /* core6 i2_pc bit22 */
			{24644,47,0}, /* core6 i2_pc bit23 */
			{24569,47,0}, /* core6 i2_pc bit24 */
			{24566,47,0}, /* core6 i2_pc bit25 */
			{24571,47,0}, /* core6 i2_pc bit26 */
			{24568,47,0}, /* core6 i2_pc bit27 */
			{24565,47,0}, /* core6 i2_pc bit28 */
			{24574,47,0}, /* core6 i2_pc bit29 */
			{24646,47,0}, /* core6 i2_pc bit30 */
			{24572,47,0}, /* core6 i2_pc bit31 */
			{12909,48,0}, /* core6 i2_pc bit32 */
			{12894,48,0}, /* core6 i2_pc bit33 */
			{12895,48,0}, /* core6 i2_pc bit34 */
			{12907,48,0}, /* core6 i2_pc bit35 */
			{12896,48,0}, /* core6 i2_pc bit36 */
			{12908,48,0}, /* core6 i2_pc bit37 */
			{12889,48,0}, /* core6 i2_pc bit38 */
			{12905,48,0}, /* core6 i2_pc bit39 */
			{12915,48,0}, /* core6 i2_pc bit40 */
			{12902,48,0}, /* core6 i2_pc bit41 */
			{12911,48,0}, /* core6 i2_pc bit42 */
			{12916,48,0}, /* core6 i2_pc bit43 */
			{12901,48,0}, /* core6 i2_pc bit44 */
			{12890,48,0}, /* core6 i2_pc bit45 */
			{12893,48,0}, /* core6 i2_pc bit46 */
			{12912,48,0}, /* core6 i2_pc bit47 */
			{12913,48,0}, /* core6 i2_pc bit48 */
			{12921,48,0}, /* core6 i2_pc bit49 */
			{12919,48,0}, /* core6 i2_pc bit50 */
			{12892,48,0}, /* core6 i2_pc bit51 */
			{12922,48,0}, /* core6 i2_pc bit52 */
			{12891,48,0}, /* core6 i2_pc bit53 */
			{12923,48,0}, /* core6 i2_pc bit54 */
			{12910,48,0}, /* core6 i2_pc bit55 */
			{12914,48,0}, /* core6 i2_pc bit56 */
			{12920,48,0}, /* core6 i2_pc bit57 */
			{12926,48,0}, /* core6 i2_pc bit58 */
			{12904,48,0}, /* core6 i2_pc bit59 */
			{12906,48,0}, /* core6 i2_pc bit60 */
			{12924,48,0}, /* core6 i2_pc bit61 */
			{12925,48,0}, /* core6 i2_pc bit62 */
			{12903,48,0}, /* core6 i2_pc bit63 */
			}},
			.last_branch = {{
			{    0, 0,2}, /* core6 last_branch bit0 */
			{ 5460,51,0}, /* core6 last_branch bit1 */
			{ 5454,51,0}, /* core6 last_branch bit2 */
			{ 5463,51,0}, /* core6 last_branch bit3 */
			{ 5451,51,0}, /* core6 last_branch bit4 */
			{ 5452,51,0}, /* core6 last_branch bit5 */
			{16649,50,0}, /* core6 last_branch bit6 */
			{ 5453,51,0}, /* core6 last_branch bit7 */
			{16650,50,0}, /* core6 last_branch bit8 */
			{16651,50,0}, /* core6 last_branch bit9 */
			{ 5449,51,0}, /* core6 last_branch bit10 */
			{ 5448,51,0}, /* core6 last_branch bit11 */
			{16588,50,0}, /* core6 last_branch bit12 */
			{ 5456,51,0}, /* core6 last_branch bit13 */
			{ 5450,51,0}, /* core6 last_branch bit14 */
			{16644,50,0}, /* core6 last_branch bit15 */
			{16597,50,0}, /* core6 last_branch bit16 */
			{11296,51,0}, /* core6 last_branch bit17 */
			{11298,51,0}, /* core6 last_branch bit18 */
			{11302,51,0}, /* core6 last_branch bit19 */
			{11301,51,0}, /* core6 last_branch bit20 */
			{11300,51,0}, /* core6 last_branch bit21 */
			{11299,51,0}, /* core6 last_branch bit22 */
			{11295,51,0}, /* core6 last_branch bit23 */
			{16600,50,0}, /* core6 last_branch bit24 */
			{16590,50,0}, /* core6 last_branch bit25 */
			{16596,50,0}, /* core6 last_branch bit26 */
			{16595,50,0}, /* core6 last_branch bit27 */
			{16589,50,0}, /* core6 last_branch bit28 */
			{ 5459,51,0}, /* core6 last_branch bit29 */
			{ 5462,51,0}, /* core6 last_branch bit30 */
			{ 5461,51,0}, /* core6 last_branch bit31 */
			{16591,50,0}, /* core6 last_branch bit32 */
			{16601,50,0}, /* core6 last_branch bit33 */
			{16592,50,0}, /* core6 last_branch bit34 */
			{16648,50,0}, /* core6 last_branch bit35 */
			{16599,50,0}, /* core6 last_branch bit36 */
			{16593,50,0}, /* core6 last_branch bit37 */
			{ 5455,51,0}, /* core6 last_branch bit38 */
			{ 5458,51,0}, /* core6 last_branch bit39 */
			{16646,50,0}, /* core6 last_branch bit40 */
			{11297,51,0}, /* core6 last_branch bit41 */
			{16603,50,0}, /* core6 last_branch bit42 */
			{ 5457,51,0}, /* core6 last_branch bit43 */
			{16602,50,0}, /* core6 last_branch bit44 */
			{16647,50,0}, /* core6 last_branch bit45 */
			{16645,50,0}, /* core6 last_branch bit46 */
			{16594,50,0}, /* core6 last_branch bit47 */
			{16598,50,0}, /* core6 last_branch bit48 */
			{    0, 0,2}, /* core6 last_branch bit49 */
			{    0, 0,2}, /* core6 last_branch bit50 */
			{    0, 0,2}, /* core6 last_branch bit51 */
			{    0, 0,2}, /* core6 last_branch bit52 */
			{    0, 0,2}, /* core6 last_branch bit53 */
			{    0, 0,2}, /* core6 last_branch bit54 */
			{    0, 0,2}, /* core6 last_branch bit55 */
			{    0, 0,2}, /* core6 last_branch bit56 */
			{    0, 0,2}, /* core6 last_branch bit57 */
			{    0, 0,2}, /* core6 last_branch bit58 */
			{    0, 0,2}, /* core6 last_branch bit59 */
			{    0, 0,2}, /* core6 last_branch bit60 */
			{    0, 0,2}, /* core6 last_branch bit61 */
			{    0, 0,2}, /* core6 last_branch bit62 */
			{    0, 0,2}, /* core6 last_branch bit63 */
			}},
			.sram_wr_ptr_0 = {{
			{13177,47,0}, /* core6 sram_wr_ptr_0 bit0 */
			{ 6121,49,1}, /* core6 sram_wr_ptr_0 bit1 */
			{13180,47,0}, /* core6 sram_wr_ptr_0 bit2 */
			{ 3863,51,0}, /* core6 sram_wr_ptr_0 bit3 */
			{13179,47,0}, /* core6 sram_wr_ptr_0 bit4 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit5 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit6 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit7 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit8 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit9 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit10 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit11 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit12 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit13 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit14 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit15 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit16 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit17 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit18 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit19 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit20 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit21 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit22 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit23 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit24 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit25 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit26 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit27 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit28 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit29 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit30 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit31 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit32 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit33 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit34 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit35 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit36 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit37 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit38 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit39 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit40 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit41 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit42 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit43 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit44 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit45 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit46 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit47 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit48 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit49 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit50 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit51 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit52 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit53 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit54 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit55 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit56 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit57 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit58 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit59 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit60 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit61 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit62 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit63 */
			}},
			.sram_wr_ptr_1 = {{
			{13175,47,0}, /* core6 sram_wr_ptr_1 bit0 */
			{13174,47,0}, /* core6 sram_wr_ptr_1 bit1 */
			{13178,47,0}, /* core6 sram_wr_ptr_1 bit2 */
			{13173,47,0}, /* core6 sram_wr_ptr_1 bit3 */
			{13176,47,0}, /* core6 sram_wr_ptr_1 bit4 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit5 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit6 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit7 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit8 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit9 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit10 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit11 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit12 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit13 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit14 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit15 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit16 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit17 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit18 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit19 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit20 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit21 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit22 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit23 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit24 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit25 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit26 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit27 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit28 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit29 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit30 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit31 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit32 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit33 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit34 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit35 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit36 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit37 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit38 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit39 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit40 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit41 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit42 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit43 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit44 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit45 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit46 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit47 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit48 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit49 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit50 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit51 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit52 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit53 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit54 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit55 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit56 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit57 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit58 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit59 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit60 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit61 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit62 */
			{    0, 0,2}, /* core6 sram_wr_ptr_1 bit63 */
			}},
			.sram_wr_ptr_2 = {{
			{ 3859,51,0}, /* core6 sram_wr_ptr_2 bit0 */
			{ 3862,51,0}, /* core6 sram_wr_ptr_2 bit1 */
			{ 3858,51,0}, /* core6 sram_wr_ptr_2 bit2 */
			{ 3860,51,0}, /* core6 sram_wr_ptr_2 bit3 */
			{ 3861,51,0}, /* core6 sram_wr_ptr_2 bit4 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit5 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit6 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit7 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit8 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit9 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit10 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit11 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit12 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit13 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit14 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit15 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit16 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit17 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit18 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit19 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit20 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit21 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit22 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit23 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit24 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit25 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit26 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit27 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit28 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit29 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit30 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit31 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit32 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit33 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit34 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit35 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit36 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit37 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit38 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit39 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit40 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit41 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit42 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit43 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit44 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit45 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit46 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit47 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit48 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit49 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit50 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit51 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit52 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit53 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit54 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit55 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit56 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit57 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit58 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit59 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit60 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit61 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit62 */
			{    0, 0,2}, /* core6 sram_wr_ptr_2 bit63 */
			}},
			.return_Stack_pointer = {{
			{ 4320,49,1}, /* core6 return_Stack_pointer bit0 */
			{ 4318,49,1}, /* core6 return_Stack_pointer bit1 */
			{ 4319,49,1}, /* core6 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core6 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{22792,49,1}, /* core6 return_Stack0 bit0 */
			{15180,50,0}, /* core6 return_Stack0 bit1 */
			{15222,50,0}, /* core6 return_Stack0 bit2 */
			{15227,50,0}, /* core6 return_Stack0 bit3 */
			{22788,49,1}, /* core6 return_Stack0 bit4 */
			{15226,50,0}, /* core6 return_Stack0 bit5 */
			{15229,50,0}, /* core6 return_Stack0 bit6 */
			{15228,50,0}, /* core6 return_Stack0 bit7 */
			{15225,50,0}, /* core6 return_Stack0 bit8 */
			{15115,50,0}, /* core6 return_Stack0 bit9 */
			{15224,50,0}, /* core6 return_Stack0 bit10 */
			{15116,50,0}, /* core6 return_Stack0 bit11 */
			{22790,49,1}, /* core6 return_Stack0 bit12 */
			{22789,49,1}, /* core6 return_Stack0 bit13 */
			{15117,50,0}, /* core6 return_Stack0 bit14 */
			{15223,50,0}, /* core6 return_Stack0 bit15 */
			{15187,50,0}, /* core6 return_Stack0 bit16 */
			{15184,50,0}, /* core6 return_Stack0 bit17 */
			{15182,50,0}, /* core6 return_Stack0 bit18 */
			{15183,50,0}, /* core6 return_Stack0 bit19 */
			{15186,50,0}, /* core6 return_Stack0 bit20 */
			{15185,50,0}, /* core6 return_Stack0 bit21 */
			{ 3682,49,1}, /* core6 return_Stack0 bit22 */
			{ 3684,49,1}, /* core6 return_Stack0 bit23 */
			{25582,47,0}, /* core6 return_Stack0 bit24 */
			{ 3677,49,1}, /* core6 return_Stack0 bit25 */
			{ 3681,49,1}, /* core6 return_Stack0 bit26 */
			{ 3683,49,1}, /* core6 return_Stack0 bit27 */
			{ 3679,49,1}, /* core6 return_Stack0 bit28 */
			{ 3678,49,1}, /* core6 return_Stack0 bit29 */
			{ 3680,49,1}, /* core6 return_Stack0 bit30 */
			{ 3725,49,1}, /* core6 return_Stack0 bit31 */
			{22793,49,1}, /* core6 return_Stack0 bit32 */
			{22791,49,1}, /* core6 return_Stack0 bit33 */
			{ 3731,49,1}, /* core6 return_Stack0 bit34 */
			{22886,49,1}, /* core6 return_Stack0 bit35 */
			{22888,49,1}, /* core6 return_Stack0 bit36 */
			{ 3728,49,1}, /* core6 return_Stack0 bit37 */
			{ 3727,49,1}, /* core6 return_Stack0 bit38 */
			{ 3730,49,1}, /* core6 return_Stack0 bit39 */
			{22887,49,1}, /* core6 return_Stack0 bit40 */
			{ 3726,49,1}, /* core6 return_Stack0 bit41 */
			{ 3729,49,1}, /* core6 return_Stack0 bit42 */
			{22889,49,1}, /* core6 return_Stack0 bit43 */
			{22890,49,1}, /* core6 return_Stack0 bit44 */
			{ 3732,49,1}, /* core6 return_Stack0 bit45 */
			{22795,49,1}, /* core6 return_Stack0 bit46 */
			{22891,49,1}, /* core6 return_Stack0 bit47 */
			{22794,49,1}, /* core6 return_Stack0 bit48 */
			{    0, 0,2}, /* core6 return_Stack0 bit49 */
			{    0, 0,2}, /* core6 return_Stack0 bit50 */
			{    0, 0,2}, /* core6 return_Stack0 bit51 */
			{    0, 0,2}, /* core6 return_Stack0 bit52 */
			{    0, 0,2}, /* core6 return_Stack0 bit53 */
			{    0, 0,2}, /* core6 return_Stack0 bit54 */
			{    0, 0,2}, /* core6 return_Stack0 bit55 */
			{    0, 0,2}, /* core6 return_Stack0 bit56 */
			{    0, 0,2}, /* core6 return_Stack0 bit57 */
			{    0, 0,2}, /* core6 return_Stack0 bit58 */
			{    0, 0,2}, /* core6 return_Stack0 bit59 */
			{    0, 0,2}, /* core6 return_Stack0 bit60 */
			{    0, 0,2}, /* core6 return_Stack0 bit61 */
			{    0, 0,2}, /* core6 return_Stack0 bit62 */
			{    0, 0,2}, /* core6 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{22850,49,1}, /* core6 return_Stack1 bit0 */
			{15164,50,0}, /* core6 return_Stack1 bit1 */
			{ 4681,49,1}, /* core6 return_Stack1 bit2 */
			{ 4682,49,1}, /* core6 return_Stack1 bit3 */
			{15165,50,0}, /* core6 return_Stack1 bit4 */
			{15230,50,0}, /* core6 return_Stack1 bit5 */
			{ 4687,49,1}, /* core6 return_Stack1 bit6 */
			{ 4688,49,1}, /* core6 return_Stack1 bit7 */
			{ 4683,49,1}, /* core6 return_Stack1 bit8 */
			{15134,50,0}, /* core6 return_Stack1 bit9 */
			{ 4686,49,1}, /* core6 return_Stack1 bit10 */
			{15136,50,0}, /* core6 return_Stack1 bit11 */
			{15137,50,0}, /* core6 return_Stack1 bit12 */
			{15139,50,0}, /* core6 return_Stack1 bit13 */
			{15135,50,0}, /* core6 return_Stack1 bit14 */
			{ 4684,49,1}, /* core6 return_Stack1 bit15 */
			{ 4685,49,1}, /* core6 return_Stack1 bit16 */
			{15170,50,0}, /* core6 return_Stack1 bit17 */
			{15167,50,0}, /* core6 return_Stack1 bit18 */
			{15169,50,0}, /* core6 return_Stack1 bit19 */
			{15171,50,0}, /* core6 return_Stack1 bit20 */
			{15168,50,0}, /* core6 return_Stack1 bit21 */
			{ 3600,49,1}, /* core6 return_Stack1 bit22 */
			{ 3604,49,1}, /* core6 return_Stack1 bit23 */
			{ 3602,49,1}, /* core6 return_Stack1 bit24 */
			{ 3597,49,1}, /* core6 return_Stack1 bit25 */
			{ 3599,49,1}, /* core6 return_Stack1 bit26 */
			{ 3598,49,1}, /* core6 return_Stack1 bit27 */
			{ 3603,49,1}, /* core6 return_Stack1 bit28 */
			{ 3669,49,1}, /* core6 return_Stack1 bit29 */
			{ 3601,49,1}, /* core6 return_Stack1 bit30 */
			{ 3672,49,1}, /* core6 return_Stack1 bit31 */
			{22851,49,1}, /* core6 return_Stack1 bit32 */
			{15138,50,0}, /* core6 return_Stack1 bit33 */
			{ 3676,49,1}, /* core6 return_Stack1 bit34 */
			{25568,47,0}, /* core6 return_Stack1 bit35 */
			{25569,47,0}, /* core6 return_Stack1 bit36 */
			{ 3673,49,1}, /* core6 return_Stack1 bit37 */
			{ 3670,49,1}, /* core6 return_Stack1 bit38 */
			{ 3675,49,1}, /* core6 return_Stack1 bit39 */
			{22857,49,1}, /* core6 return_Stack1 bit40 */
			{ 3671,49,1}, /* core6 return_Stack1 bit41 */
			{ 3674,49,1}, /* core6 return_Stack1 bit42 */
			{22856,49,1}, /* core6 return_Stack1 bit43 */
			{22855,49,1}, /* core6 return_Stack1 bit44 */
			{18779,45,0}, /* core6 return_Stack1 bit45 */
			{22854,49,1}, /* core6 return_Stack1 bit46 */
			{22853,49,1}, /* core6 return_Stack1 bit47 */
			{22852,49,1}, /* core6 return_Stack1 bit48 */
			{    0, 0,2}, /* core6 return_Stack1 bit49 */
			{    0, 0,2}, /* core6 return_Stack1 bit50 */
			{    0, 0,2}, /* core6 return_Stack1 bit51 */
			{    0, 0,2}, /* core6 return_Stack1 bit52 */
			{    0, 0,2}, /* core6 return_Stack1 bit53 */
			{    0, 0,2}, /* core6 return_Stack1 bit54 */
			{    0, 0,2}, /* core6 return_Stack1 bit55 */
			{    0, 0,2}, /* core6 return_Stack1 bit56 */
			{    0, 0,2}, /* core6 return_Stack1 bit57 */
			{    0, 0,2}, /* core6 return_Stack1 bit58 */
			{    0, 0,2}, /* core6 return_Stack1 bit59 */
			{    0, 0,2}, /* core6 return_Stack1 bit60 */
			{    0, 0,2}, /* core6 return_Stack1 bit61 */
			{    0, 0,2}, /* core6 return_Stack1 bit62 */
			{    0, 0,2}, /* core6 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{22801,49,1}, /* core6 return_Stack2 bit0 */
			{15140,50,0}, /* core6 return_Stack2 bit1 */
			{ 3256,49,1}, /* core6 return_Stack2 bit2 */
			{ 3257,49,1}, /* core6 return_Stack2 bit3 */
			{15143,50,0}, /* core6 return_Stack2 bit4 */
			{ 3251,49,1}, /* core6 return_Stack2 bit5 */
			{15270,50,0}, /* core6 return_Stack2 bit6 */
			{ 3252,49,1}, /* core6 return_Stack2 bit7 */
			{ 3258,49,1}, /* core6 return_Stack2 bit8 */
			{ 3255,49,1}, /* core6 return_Stack2 bit9 */
			{15146,50,0}, /* core6 return_Stack2 bit10 */
			{ 3254,49,1}, /* core6 return_Stack2 bit11 */
			{22798,49,1}, /* core6 return_Stack2 bit12 */
			{22797,49,1}, /* core6 return_Stack2 bit13 */
			{ 3253,49,1}, /* core6 return_Stack2 bit14 */
			{15196,50,0}, /* core6 return_Stack2 bit15 */
			{15197,50,0}, /* core6 return_Stack2 bit16 */
			{15145,50,0}, /* core6 return_Stack2 bit17 */
			{15141,50,0}, /* core6 return_Stack2 bit18 */
			{15147,50,0}, /* core6 return_Stack2 bit19 */
			{15144,50,0}, /* core6 return_Stack2 bit20 */
			{15142,50,0}, /* core6 return_Stack2 bit21 */
			{ 3694,49,1}, /* core6 return_Stack2 bit22 */
			{ 3720,49,1}, /* core6 return_Stack2 bit23 */
			{ 3700,49,1}, /* core6 return_Stack2 bit24 */
			{ 3693,49,1}, /* core6 return_Stack2 bit25 */
			{ 3697,49,1}, /* core6 return_Stack2 bit26 */
			{ 3696,49,1}, /* core6 return_Stack2 bit27 */
			{ 3698,49,1}, /* core6 return_Stack2 bit28 */
			{ 3699,49,1}, /* core6 return_Stack2 bit29 */
			{ 3695,49,1}, /* core6 return_Stack2 bit30 */
			{ 3717,49,1}, /* core6 return_Stack2 bit31 */
			{22800,49,1}, /* core6 return_Stack2 bit32 */
			{22799,49,1}, /* core6 return_Stack2 bit33 */
			{ 3724,49,1}, /* core6 return_Stack2 bit34 */
			{22872,49,1}, /* core6 return_Stack2 bit35 */
			{22875,49,1}, /* core6 return_Stack2 bit36 */
			{ 3723,49,1}, /* core6 return_Stack2 bit37 */
			{ 3718,49,1}, /* core6 return_Stack2 bit38 */
			{ 3721,49,1}, /* core6 return_Stack2 bit39 */
			{22874,49,1}, /* core6 return_Stack2 bit40 */
			{ 3719,49,1}, /* core6 return_Stack2 bit41 */
			{ 3722,49,1}, /* core6 return_Stack2 bit42 */
			{22876,49,1}, /* core6 return_Stack2 bit43 */
			{18716,50,0}, /* core6 return_Stack2 bit44 */
			{22873,49,1}, /* core6 return_Stack2 bit45 */
			{22877,49,1}, /* core6 return_Stack2 bit46 */
			{22803,49,1}, /* core6 return_Stack2 bit47 */
			{22802,49,1}, /* core6 return_Stack2 bit48 */
			{    0, 0,2}, /* core6 return_Stack2 bit49 */
			{    0, 0,2}, /* core6 return_Stack2 bit50 */
			{    0, 0,2}, /* core6 return_Stack2 bit51 */
			{    0, 0,2}, /* core6 return_Stack2 bit52 */
			{    0, 0,2}, /* core6 return_Stack2 bit53 */
			{    0, 0,2}, /* core6 return_Stack2 bit54 */
			{    0, 0,2}, /* core6 return_Stack2 bit55 */
			{    0, 0,2}, /* core6 return_Stack2 bit56 */
			{    0, 0,2}, /* core6 return_Stack2 bit57 */
			{    0, 0,2}, /* core6 return_Stack2 bit58 */
			{    0, 0,2}, /* core6 return_Stack2 bit59 */
			{    0, 0,2}, /* core6 return_Stack2 bit60 */
			{    0, 0,2}, /* core6 return_Stack2 bit61 */
			{    0, 0,2}, /* core6 return_Stack2 bit62 */
			{    0, 0,2}, /* core6 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{22772,49,1}, /* core6 return_Stack3 bit0 */
			{15188,50,0}, /* core6 return_Stack3 bit1 */
			{15231,50,0}, /* core6 return_Stack3 bit2 */
			{15235,50,0}, /* core6 return_Stack3 bit3 */
			{15189,50,0}, /* core6 return_Stack3 bit4 */
			{15237,50,0}, /* core6 return_Stack3 bit5 */
			{15272,50,0}, /* core6 return_Stack3 bit6 */
			{15271,50,0}, /* core6 return_Stack3 bit7 */
			{15232,50,0}, /* core6 return_Stack3 bit8 */
			{ 4331,49,1}, /* core6 return_Stack3 bit9 */
			{15195,50,0}, /* core6 return_Stack3 bit10 */
			{15238,50,0}, /* core6 return_Stack3 bit11 */
			{15066,50,0}, /* core6 return_Stack3 bit12 */
			{15064,50,0}, /* core6 return_Stack3 bit13 */
			{15236,50,0}, /* core6 return_Stack3 bit14 */
			{15233,50,0}, /* core6 return_Stack3 bit15 */
			{15234,50,0}, /* core6 return_Stack3 bit16 */
			{15194,50,0}, /* core6 return_Stack3 bit17 */
			{15190,50,0}, /* core6 return_Stack3 bit18 */
			{15191,50,0}, /* core6 return_Stack3 bit19 */
			{15193,50,0}, /* core6 return_Stack3 bit20 */
			{15192,50,0}, /* core6 return_Stack3 bit21 */
			{25558,47,0}, /* core6 return_Stack3 bit22 */
			{25573,47,0}, /* core6 return_Stack3 bit23 */
			{25560,47,0}, /* core6 return_Stack3 bit24 */
			{25553,47,0}, /* core6 return_Stack3 bit25 */
			{25557,47,0}, /* core6 return_Stack3 bit26 */
			{25555,47,0}, /* core6 return_Stack3 bit27 */
			{25559,47,0}, /* core6 return_Stack3 bit28 */
			{25556,47,0}, /* core6 return_Stack3 bit29 */
			{25554,47,0}, /* core6 return_Stack3 bit30 */
			{ 3701,49,1}, /* core6 return_Stack3 bit31 */
			{22776,49,1}, /* core6 return_Stack3 bit32 */
			{15065,50,0}, /* core6 return_Stack3 bit33 */
			{25570,47,0}, /* core6 return_Stack3 bit34 */
			{22778,49,1}, /* core6 return_Stack3 bit35 */
			{ 3708,49,1}, /* core6 return_Stack3 bit36 */
			{ 3705,49,1}, /* core6 return_Stack3 bit37 */
			{ 3706,49,1}, /* core6 return_Stack3 bit38 */
			{ 3702,49,1}, /* core6 return_Stack3 bit39 */
			{25571,47,0}, /* core6 return_Stack3 bit40 */
			{ 3703,49,1}, /* core6 return_Stack3 bit41 */
			{ 3704,49,1}, /* core6 return_Stack3 bit42 */
			{22779,49,1}, /* core6 return_Stack3 bit43 */
			{22777,49,1}, /* core6 return_Stack3 bit44 */
			{ 3707,49,1}, /* core6 return_Stack3 bit45 */
			{22774,49,1}, /* core6 return_Stack3 bit46 */
			{22775,49,1}, /* core6 return_Stack3 bit47 */
			{22773,49,1}, /* core6 return_Stack3 bit48 */
			{    0, 0,2}, /* core6 return_Stack3 bit49 */
			{    0, 0,2}, /* core6 return_Stack3 bit50 */
			{    0, 0,2}, /* core6 return_Stack3 bit51 */
			{    0, 0,2}, /* core6 return_Stack3 bit52 */
			{    0, 0,2}, /* core6 return_Stack3 bit53 */
			{    0, 0,2}, /* core6 return_Stack3 bit54 */
			{    0, 0,2}, /* core6 return_Stack3 bit55 */
			{    0, 0,2}, /* core6 return_Stack3 bit56 */
			{    0, 0,2}, /* core6 return_Stack3 bit57 */
			{    0, 0,2}, /* core6 return_Stack3 bit58 */
			{    0, 0,2}, /* core6 return_Stack3 bit59 */
			{    0, 0,2}, /* core6 return_Stack3 bit60 */
			{    0, 0,2}, /* core6 return_Stack3 bit61 */
			{    0, 0,2}, /* core6 return_Stack3 bit62 */
			{    0, 0,2}, /* core6 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{22780,49,1}, /* core6 return_Stack4 bit0 */
			{15148,50,0}, /* core6 return_Stack4 bit1 */
			{15206,50,0}, /* core6 return_Stack4 bit2 */
			{15207,50,0}, /* core6 return_Stack4 bit3 */
			{15151,50,0}, /* core6 return_Stack4 bit4 */
			{19459,50,0}, /* core6 return_Stack4 bit5 */
			{19462,50,0}, /* core6 return_Stack4 bit6 */
			{15208,50,0}, /* core6 return_Stack4 bit7 */
			{15209,50,0}, /* core6 return_Stack4 bit8 */
			{15210,50,0}, /* core6 return_Stack4 bit9 */
			{15212,50,0}, /* core6 return_Stack4 bit10 */
			{19461,50,0}, /* core6 return_Stack4 bit11 */
			{22783,49,1}, /* core6 return_Stack4 bit12 */
			{22784,49,1}, /* core6 return_Stack4 bit13 */
			{19460,50,0}, /* core6 return_Stack4 bit14 */
			{15211,50,0}, /* core6 return_Stack4 bit15 */
			{15213,50,0}, /* core6 return_Stack4 bit16 */
			{15153,50,0}, /* core6 return_Stack4 bit17 */
			{15149,50,0}, /* core6 return_Stack4 bit18 */
			{15154,50,0}, /* core6 return_Stack4 bit19 */
			{15155,50,0}, /* core6 return_Stack4 bit20 */
			{15152,50,0}, /* core6 return_Stack4 bit21 */
			{25577,47,0}, /* core6 return_Stack4 bit22 */
			{ 3713,49,1}, /* core6 return_Stack4 bit23 */
			{25581,47,0}, /* core6 return_Stack4 bit24 */
			{25574,47,0}, /* core6 return_Stack4 bit25 */
			{25579,47,0}, /* core6 return_Stack4 bit26 */
			{25575,47,0}, /* core6 return_Stack4 bit27 */
			{25580,47,0}, /* core6 return_Stack4 bit28 */
			{25578,47,0}, /* core6 return_Stack4 bit29 */
			{25576,47,0}, /* core6 return_Stack4 bit30 */
			{ 3709,49,1}, /* core6 return_Stack4 bit31 */
			{22781,49,1}, /* core6 return_Stack4 bit32 */
			{22782,49,1}, /* core6 return_Stack4 bit33 */
			{22866,49,1}, /* core6 return_Stack4 bit34 */
			{22868,49,1}, /* core6 return_Stack4 bit35 */
			{ 3716,49,1}, /* core6 return_Stack4 bit36 */
			{ 3712,49,1}, /* core6 return_Stack4 bit37 */
			{ 3710,49,1}, /* core6 return_Stack4 bit38 */
			{ 3711,49,1}, /* core6 return_Stack4 bit39 */
			{22869,49,1}, /* core6 return_Stack4 bit40 */
			{ 3715,49,1}, /* core6 return_Stack4 bit41 */
			{ 3714,49,1}, /* core6 return_Stack4 bit42 */
			{22870,49,1}, /* core6 return_Stack4 bit43 */
			{22871,49,1}, /* core6 return_Stack4 bit44 */
			{22867,49,1}, /* core6 return_Stack4 bit45 */
			{22787,49,1}, /* core6 return_Stack4 bit46 */
			{22786,49,1}, /* core6 return_Stack4 bit47 */
			{22785,49,1}, /* core6 return_Stack4 bit48 */
			{    0, 0,2}, /* core6 return_Stack4 bit49 */
			{    0, 0,2}, /* core6 return_Stack4 bit50 */
			{    0, 0,2}, /* core6 return_Stack4 bit51 */
			{    0, 0,2}, /* core6 return_Stack4 bit52 */
			{    0, 0,2}, /* core6 return_Stack4 bit53 */
			{    0, 0,2}, /* core6 return_Stack4 bit54 */
			{    0, 0,2}, /* core6 return_Stack4 bit55 */
			{    0, 0,2}, /* core6 return_Stack4 bit56 */
			{    0, 0,2}, /* core6 return_Stack4 bit57 */
			{    0, 0,2}, /* core6 return_Stack4 bit58 */
			{    0, 0,2}, /* core6 return_Stack4 bit59 */
			{    0, 0,2}, /* core6 return_Stack4 bit60 */
			{    0, 0,2}, /* core6 return_Stack4 bit61 */
			{    0, 0,2}, /* core6 return_Stack4 bit62 */
			{    0, 0,2}, /* core6 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{15051,50,0}, /* core6 return_Stack5 bit0 */
			{15172,50,0}, /* core6 return_Stack5 bit1 */
			{ 3259,49,1}, /* core6 return_Stack5 bit2 */
			{ 3261,49,1}, /* core6 return_Stack5 bit3 */
			{15047,50,0}, /* core6 return_Stack5 bit4 */
			{15273,50,0}, /* core6 return_Stack5 bit5 */
			{ 3266,49,1}, /* core6 return_Stack5 bit6 */
			{ 3263,49,1}, /* core6 return_Stack5 bit7 */
			{ 3262,49,1}, /* core6 return_Stack5 bit8 */
			{ 3265,49,1}, /* core6 return_Stack5 bit9 */
			{15176,50,0}, /* core6 return_Stack5 bit10 */
			{ 3264,49,1}, /* core6 return_Stack5 bit11 */
			{15049,50,0}, /* core6 return_Stack5 bit12 */
			{15050,50,0}, /* core6 return_Stack5 bit13 */
			{15274,50,0}, /* core6 return_Stack5 bit14 */
			{ 3260,49,1}, /* core6 return_Stack5 bit15 */
			{15179,50,0}, /* core6 return_Stack5 bit16 */
			{15173,50,0}, /* core6 return_Stack5 bit17 */
			{15174,50,0}, /* core6 return_Stack5 bit18 */
			{15178,50,0}, /* core6 return_Stack5 bit19 */
			{15177,50,0}, /* core6 return_Stack5 bit20 */
			{15175,50,0}, /* core6 return_Stack5 bit21 */
			{25546,47,0}, /* core6 return_Stack5 bit22 */
			{25552,47,0}, /* core6 return_Stack5 bit23 */
			{22884,49,1}, /* core6 return_Stack5 bit24 */
			{25545,47,0}, /* core6 return_Stack5 bit25 */
			{25547,47,0}, /* core6 return_Stack5 bit26 */
			{25550,47,0}, /* core6 return_Stack5 bit27 */
			{25548,47,0}, /* core6 return_Stack5 bit28 */
			{25551,47,0}, /* core6 return_Stack5 bit29 */
			{25549,47,0}, /* core6 return_Stack5 bit30 */
			{ 3733,49,1}, /* core6 return_Stack5 bit31 */
			{15053,50,0}, /* core6 return_Stack5 bit32 */
			{15052,50,0}, /* core6 return_Stack5 bit33 */
			{ 3739,49,1}, /* core6 return_Stack5 bit34 */
			{22878,49,1}, /* core6 return_Stack5 bit35 */
			{ 3738,49,1}, /* core6 return_Stack5 bit36 */
			{ 3734,49,1}, /* core6 return_Stack5 bit37 */
			{22885,49,1}, /* core6 return_Stack5 bit38 */
			{ 3737,49,1}, /* core6 return_Stack5 bit39 */
			{22881,49,1}, /* core6 return_Stack5 bit40 */
			{ 3736,49,1}, /* core6 return_Stack5 bit41 */
			{ 3735,49,1}, /* core6 return_Stack5 bit42 */
			{22879,49,1}, /* core6 return_Stack5 bit43 */
			{22880,49,1}, /* core6 return_Stack5 bit44 */
			{ 3740,49,1}, /* core6 return_Stack5 bit45 */
			{22883,49,1}, /* core6 return_Stack5 bit46 */
			{22882,49,1}, /* core6 return_Stack5 bit47 */
			{15054,50,0}, /* core6 return_Stack5 bit48 */
			{    0, 0,2}, /* core6 return_Stack5 bit49 */
			{    0, 0,2}, /* core6 return_Stack5 bit50 */
			{    0, 0,2}, /* core6 return_Stack5 bit51 */
			{    0, 0,2}, /* core6 return_Stack5 bit52 */
			{    0, 0,2}, /* core6 return_Stack5 bit53 */
			{    0, 0,2}, /* core6 return_Stack5 bit54 */
			{    0, 0,2}, /* core6 return_Stack5 bit55 */
			{    0, 0,2}, /* core6 return_Stack5 bit56 */
			{    0, 0,2}, /* core6 return_Stack5 bit57 */
			{    0, 0,2}, /* core6 return_Stack5 bit58 */
			{    0, 0,2}, /* core6 return_Stack5 bit59 */
			{    0, 0,2}, /* core6 return_Stack5 bit60 */
			{    0, 0,2}, /* core6 return_Stack5 bit61 */
			{    0, 0,2}, /* core6 return_Stack5 bit62 */
			{    0, 0,2}, /* core6 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{22858,49,1}, /* core6 return_Stack6 bit0 */
			{15156,50,0}, /* core6 return_Stack6 bit1 */
			{15214,50,0}, /* core6 return_Stack6 bit2 */
			{15217,50,0}, /* core6 return_Stack6 bit3 */
			{15157,50,0}, /* core6 return_Stack6 bit4 */
			{19455,50,0}, /* core6 return_Stack6 bit5 */
			{15220,50,0}, /* core6 return_Stack6 bit6 */
			{15221,50,0}, /* core6 return_Stack6 bit7 */
			{15215,50,0}, /* core6 return_Stack6 bit8 */
			{19456,50,0}, /* core6 return_Stack6 bit9 */
			{15219,50,0}, /* core6 return_Stack6 bit10 */
			{19457,50,0}, /* core6 return_Stack6 bit11 */
			{ 3741,49,1}, /* core6 return_Stack6 bit12 */
			{18719,50,0}, /* core6 return_Stack6 bit13 */
			{19458,50,0}, /* core6 return_Stack6 bit14 */
			{15216,50,0}, /* core6 return_Stack6 bit15 */
			{15218,50,0}, /* core6 return_Stack6 bit16 */
			{15161,50,0}, /* core6 return_Stack6 bit17 */
			{15158,50,0}, /* core6 return_Stack6 bit18 */
			{15162,50,0}, /* core6 return_Stack6 bit19 */
			{15163,50,0}, /* core6 return_Stack6 bit20 */
			{15160,50,0}, /* core6 return_Stack6 bit21 */
			{ 3592,49,1}, /* core6 return_Stack6 bit22 */
			{ 2556,49,1}, /* core6 return_Stack6 bit23 */
			{ 3595,49,1}, /* core6 return_Stack6 bit24 */
			{ 3589,49,1}, /* core6 return_Stack6 bit25 */
			{ 3590,49,1}, /* core6 return_Stack6 bit26 */
			{ 3593,49,1}, /* core6 return_Stack6 bit27 */
			{ 3596,49,1}, /* core6 return_Stack6 bit28 */
			{ 3594,49,1}, /* core6 return_Stack6 bit29 */
			{ 3591,49,1}, /* core6 return_Stack6 bit30 */
			{ 3747,49,1}, /* core6 return_Stack6 bit31 */
			{ 3743,49,1}, /* core6 return_Stack6 bit32 */
			{ 3742,49,1}, /* core6 return_Stack6 bit33 */
			{ 3748,49,1}, /* core6 return_Stack6 bit34 */
			{22864,49,1}, /* core6 return_Stack6 bit35 */
			{ 3745,49,1}, /* core6 return_Stack6 bit36 */
			{ 2558,49,1}, /* core6 return_Stack6 bit37 */
			{ 2557,49,1}, /* core6 return_Stack6 bit38 */
			{ 2559,49,1}, /* core6 return_Stack6 bit39 */
			{22863,49,1}, /* core6 return_Stack6 bit40 */
			{ 3746,49,1}, /* core6 return_Stack6 bit41 */
			{25572,47,0}, /* core6 return_Stack6 bit42 */
			{22865,49,1}, /* core6 return_Stack6 bit43 */
			{22861,49,1}, /* core6 return_Stack6 bit44 */
			{ 3744,49,1}, /* core6 return_Stack6 bit45 */
			{22860,49,1}, /* core6 return_Stack6 bit46 */
			{22862,49,1}, /* core6 return_Stack6 bit47 */
			{22859,49,1}, /* core6 return_Stack6 bit48 */
			{    0, 0,2}, /* core6 return_Stack6 bit49 */
			{    0, 0,2}, /* core6 return_Stack6 bit50 */
			{    0, 0,2}, /* core6 return_Stack6 bit51 */
			{    0, 0,2}, /* core6 return_Stack6 bit52 */
			{    0, 0,2}, /* core6 return_Stack6 bit53 */
			{    0, 0,2}, /* core6 return_Stack6 bit54 */
			{    0, 0,2}, /* core6 return_Stack6 bit55 */
			{    0, 0,2}, /* core6 return_Stack6 bit56 */
			{    0, 0,2}, /* core6 return_Stack6 bit57 */
			{    0, 0,2}, /* core6 return_Stack6 bit58 */
			{    0, 0,2}, /* core6 return_Stack6 bit59 */
			{    0, 0,2}, /* core6 return_Stack6 bit60 */
			{    0, 0,2}, /* core6 return_Stack6 bit61 */
			{    0, 0,2}, /* core6 return_Stack6 bit62 */
			{    0, 0,2}, /* core6 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{22842,49,1}, /* core6 return_Stack7 bit0 */
			{15055,50,0}, /* core6 return_Stack7 bit1 */
			{15198,50,0}, /* core6 return_Stack7 bit2 */
			{15199,50,0}, /* core6 return_Stack7 bit3 */
			{15056,50,0}, /* core6 return_Stack7 bit4 */
			{21470,49,1}, /* core6 return_Stack7 bit5 */
			{21474,49,1}, /* core6 return_Stack7 bit6 */
			{21475,49,1}, /* core6 return_Stack7 bit7 */
			{15200,50,0}, /* core6 return_Stack7 bit8 */
			{21473,49,1}, /* core6 return_Stack7 bit9 */
			{15021,50,0}, /* core6 return_Stack7 bit10 */
			{21472,49,1}, /* core6 return_Stack7 bit11 */
			{15060,50,0}, /* core6 return_Stack7 bit12 */
			{15057,50,0}, /* core6 return_Stack7 bit13 */
			{21471,49,1}, /* core6 return_Stack7 bit14 */
			{15202,50,0}, /* core6 return_Stack7 bit15 */
			{15201,50,0}, /* core6 return_Stack7 bit16 */
			{15061,50,0}, /* core6 return_Stack7 bit17 */
			{15062,50,0}, /* core6 return_Stack7 bit18 */
			{15204,50,0}, /* core6 return_Stack7 bit19 */
			{15203,50,0}, /* core6 return_Stack7 bit20 */
			{15205,50,0}, /* core6 return_Stack7 bit21 */
			{ 3688,49,1}, /* core6 return_Stack7 bit22 */
			{ 3692,49,1}, /* core6 return_Stack7 bit23 */
			{ 3665,49,1}, /* core6 return_Stack7 bit24 */
			{ 3685,49,1}, /* core6 return_Stack7 bit25 */
			{ 3687,49,1}, /* core6 return_Stack7 bit26 */
			{ 3686,49,1}, /* core6 return_Stack7 bit27 */
			{ 3691,49,1}, /* core6 return_Stack7 bit28 */
			{ 3690,49,1}, /* core6 return_Stack7 bit29 */
			{ 3689,49,1}, /* core6 return_Stack7 bit30 */
			{ 3661,49,1}, /* core6 return_Stack7 bit31 */
			{22843,49,1}, /* core6 return_Stack7 bit32 */
			{15059,50,0}, /* core6 return_Stack7 bit33 */
			{ 3668,49,1}, /* core6 return_Stack7 bit34 */
			{13280,51,0}, /* core6 return_Stack7 bit35 */
			{25567,47,0}, /* core6 return_Stack7 bit36 */
			{ 3663,49,1}, /* core6 return_Stack7 bit37 */
			{ 3664,49,1}, /* core6 return_Stack7 bit38 */
			{ 3667,49,1}, /* core6 return_Stack7 bit39 */
			{22849,49,1}, /* core6 return_Stack7 bit40 */
			{ 3662,49,1}, /* core6 return_Stack7 bit41 */
			{ 3666,49,1}, /* core6 return_Stack7 bit42 */
			{22848,49,1}, /* core6 return_Stack7 bit43 */
			{22847,49,1}, /* core6 return_Stack7 bit44 */
			{13281,51,0}, /* core6 return_Stack7 bit45 */
			{22846,49,1}, /* core6 return_Stack7 bit46 */
			{22845,49,1}, /* core6 return_Stack7 bit47 */
			{22844,49,1}, /* core6 return_Stack7 bit48 */
			{    0, 0,2}, /* core6 return_Stack7 bit49 */
			{    0, 0,2}, /* core6 return_Stack7 bit50 */
			{    0, 0,2}, /* core6 return_Stack7 bit51 */
			{    0, 0,2}, /* core6 return_Stack7 bit52 */
			{    0, 0,2}, /* core6 return_Stack7 bit53 */
			{    0, 0,2}, /* core6 return_Stack7 bit54 */
			{    0, 0,2}, /* core6 return_Stack7 bit55 */
			{    0, 0,2}, /* core6 return_Stack7 bit56 */
			{    0, 0,2}, /* core6 return_Stack7 bit57 */
			{    0, 0,2}, /* core6 return_Stack7 bit58 */
			{    0, 0,2}, /* core6 return_Stack7 bit59 */
			{    0, 0,2}, /* core6 return_Stack7 bit60 */
			{    0, 0,2}, /* core6 return_Stack7 bit61 */
			{    0, 0,2}, /* core6 return_Stack7 bit62 */
			{    0, 0,2}, /* core6 return_Stack7 bit63 */
			}},
			.L2_parity_err_count = {{
			{ 6853, 8,0}, /* core6 L2_parity_err_count bit0 */
			{ 6852, 8,0}, /* core6 L2_parity_err_count bit1 */
			{ 6851, 8,0}, /* core6 L2_parity_err_count bit2 */
			{ 6850, 8,0}, /* core6 L2_parity_err_count bit3 */
			{ 6849, 8,0}, /* core6 L2_parity_err_count bit4 */
			{ 6848, 8,0}, /* core6 L2_parity_err_count bit5 */
			{ 6847, 8,0}, /* core6 L2_parity_err_count bit6 */
			{ 6846, 8,0}, /* core6 L2_parity_err_count bit7 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit8 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit9 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit10 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit11 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit12 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit13 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit14 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit15 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit16 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit17 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit18 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit19 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit20 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit21 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit22 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit23 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit24 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit25 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit26 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit27 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit28 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit29 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit30 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit31 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit32 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit33 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit34 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit35 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit36 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit37 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit38 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit39 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit40 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit41 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit42 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit43 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit44 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit45 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit46 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit47 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit48 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit49 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit50 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit51 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit52 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit53 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit54 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit55 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit56 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit57 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit58 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit59 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit60 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit61 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit62 */
			{    0, 0,2}, /* core6 L2_parity_err_count bit63 */
			}},
			.L2_parity_index = {{
			{ 6628, 8,0}, /* core6 L2_parity_index bit0 */
			{ 6627, 8,0}, /* core6 L2_parity_index bit1 */
			{ 6626, 8,0}, /* core6 L2_parity_index bit2 */
			{ 6625, 8,0}, /* core6 L2_parity_index bit3 */
			{ 6624, 8,0}, /* core6 L2_parity_index bit4 */
			{ 6623, 8,0}, /* core6 L2_parity_index bit5 */
			{ 6622, 8,0}, /* core6 L2_parity_index bit6 */
			{ 6621, 8,0}, /* core6 L2_parity_index bit7 */
			{ 6604, 8,0}, /* core6 L2_parity_index bit8 */
			{ 6603, 8,0}, /* core6 L2_parity_index bit9 */
			{    0, 0,2}, /* core6 L2_parity_index bit10 */
			{    0, 0,2}, /* core6 L2_parity_index bit11 */
			{    0, 0,2}, /* core6 L2_parity_index bit12 */
			{    0, 0,2}, /* core6 L2_parity_index bit13 */
			{    0, 0,2}, /* core6 L2_parity_index bit14 */
			{    0, 0,2}, /* core6 L2_parity_index bit15 */
			{    0, 0,2}, /* core6 L2_parity_index bit16 */
			{    0, 0,2}, /* core6 L2_parity_index bit17 */
			{    0, 0,2}, /* core6 L2_parity_index bit18 */
			{    0, 0,2}, /* core6 L2_parity_index bit19 */
			{    0, 0,2}, /* core6 L2_parity_index bit20 */
			{    0, 0,2}, /* core6 L2_parity_index bit21 */
			{    0, 0,2}, /* core6 L2_parity_index bit22 */
			{    0, 0,2}, /* core6 L2_parity_index bit23 */
			{    0, 0,2}, /* core6 L2_parity_index bit24 */
			{    0, 0,2}, /* core6 L2_parity_index bit25 */
			{    0, 0,2}, /* core6 L2_parity_index bit26 */
			{    0, 0,2}, /* core6 L2_parity_index bit27 */
			{    0, 0,2}, /* core6 L2_parity_index bit28 */
			{    0, 0,2}, /* core6 L2_parity_index bit29 */
			{    0, 0,2}, /* core6 L2_parity_index bit30 */
			{    0, 0,2}, /* core6 L2_parity_index bit31 */
			{    0, 0,2}, /* core6 L2_parity_index bit32 */
			{    0, 0,2}, /* core6 L2_parity_index bit33 */
			{    0, 0,2}, /* core6 L2_parity_index bit34 */
			{    0, 0,2}, /* core6 L2_parity_index bit35 */
			{    0, 0,2}, /* core6 L2_parity_index bit36 */
			{    0, 0,2}, /* core6 L2_parity_index bit37 */
			{    0, 0,2}, /* core6 L2_parity_index bit38 */
			{    0, 0,2}, /* core6 L2_parity_index bit39 */
			{    0, 0,2}, /* core6 L2_parity_index bit40 */
			{    0, 0,2}, /* core6 L2_parity_index bit41 */
			{    0, 0,2}, /* core6 L2_parity_index bit42 */
			{    0, 0,2}, /* core6 L2_parity_index bit43 */
			{    0, 0,2}, /* core6 L2_parity_index bit44 */
			{    0, 0,2}, /* core6 L2_parity_index bit45 */
			{    0, 0,2}, /* core6 L2_parity_index bit46 */
			{    0, 0,2}, /* core6 L2_parity_index bit47 */
			{    0, 0,2}, /* core6 L2_parity_index bit48 */
			{    0, 0,2}, /* core6 L2_parity_index bit49 */
			{    0, 0,2}, /* core6 L2_parity_index bit50 */
			{    0, 0,2}, /* core6 L2_parity_index bit51 */
			{    0, 0,2}, /* core6 L2_parity_index bit52 */
			{    0, 0,2}, /* core6 L2_parity_index bit53 */
			{    0, 0,2}, /* core6 L2_parity_index bit54 */
			{    0, 0,2}, /* core6 L2_parity_index bit55 */
			{    0, 0,2}, /* core6 L2_parity_index bit56 */
			{    0, 0,2}, /* core6 L2_parity_index bit57 */
			{    0, 0,2}, /* core6 L2_parity_index bit58 */
			{    0, 0,2}, /* core6 L2_parity_index bit59 */
			{    0, 0,2}, /* core6 L2_parity_index bit60 */
			{    0, 0,2}, /* core6 L2_parity_index bit61 */
			{    0, 0,2}, /* core6 L2_parity_index bit62 */
			{    0, 0,2}, /* core6 L2_parity_index bit63 */
			}},
			.L2_parity_way = {{
			{ 6597, 8,0}, /* core6 L2_parity_way bit0 */
			{ 6513, 8,0}, /* core6 L2_parity_way bit1 */
			{ 6512, 8,0}, /* core6 L2_parity_way bit2 */
			{    0, 0,2}, /* core6 L2_parity_way bit3 */
			{    0, 0,2}, /* core6 L2_parity_way bit4 */
			{    0, 0,2}, /* core6 L2_parity_way bit5 */
			{    0, 0,2}, /* core6 L2_parity_way bit6 */
			{    0, 0,2}, /* core6 L2_parity_way bit7 */
			{    0, 0,2}, /* core6 L2_parity_way bit8 */
			{    0, 0,2}, /* core6 L2_parity_way bit9 */
			{    0, 0,2}, /* core6 L2_parity_way bit10 */
			{    0, 0,2}, /* core6 L2_parity_way bit11 */
			{    0, 0,2}, /* core6 L2_parity_way bit12 */
			{    0, 0,2}, /* core6 L2_parity_way bit13 */
			{    0, 0,2}, /* core6 L2_parity_way bit14 */
			{    0, 0,2}, /* core6 L2_parity_way bit15 */
			{    0, 0,2}, /* core6 L2_parity_way bit16 */
			{    0, 0,2}, /* core6 L2_parity_way bit17 */
			{    0, 0,2}, /* core6 L2_parity_way bit18 */
			{    0, 0,2}, /* core6 L2_parity_way bit19 */
			{    0, 0,2}, /* core6 L2_parity_way bit20 */
			{    0, 0,2}, /* core6 L2_parity_way bit21 */
			{    0, 0,2}, /* core6 L2_parity_way bit22 */
			{    0, 0,2}, /* core6 L2_parity_way bit23 */
			{    0, 0,2}, /* core6 L2_parity_way bit24 */
			{    0, 0,2}, /* core6 L2_parity_way bit25 */
			{    0, 0,2}, /* core6 L2_parity_way bit26 */
			{    0, 0,2}, /* core6 L2_parity_way bit27 */
			{    0, 0,2}, /* core6 L2_parity_way bit28 */
			{    0, 0,2}, /* core6 L2_parity_way bit29 */
			{    0, 0,2}, /* core6 L2_parity_way bit30 */
			{    0, 0,2}, /* core6 L2_parity_way bit31 */
			{    0, 0,2}, /* core6 L2_parity_way bit32 */
			{    0, 0,2}, /* core6 L2_parity_way bit33 */
			{    0, 0,2}, /* core6 L2_parity_way bit34 */
			{    0, 0,2}, /* core6 L2_parity_way bit35 */
			{    0, 0,2}, /* core6 L2_parity_way bit36 */
			{    0, 0,2}, /* core6 L2_parity_way bit37 */
			{    0, 0,2}, /* core6 L2_parity_way bit38 */
			{    0, 0,2}, /* core6 L2_parity_way bit39 */
			{    0, 0,2}, /* core6 L2_parity_way bit40 */
			{    0, 0,2}, /* core6 L2_parity_way bit41 */
			{    0, 0,2}, /* core6 L2_parity_way bit42 */
			{    0, 0,2}, /* core6 L2_parity_way bit43 */
			{    0, 0,2}, /* core6 L2_parity_way bit44 */
			{    0, 0,2}, /* core6 L2_parity_way bit45 */
			{    0, 0,2}, /* core6 L2_parity_way bit46 */
			{    0, 0,2}, /* core6 L2_parity_way bit47 */
			{    0, 0,2}, /* core6 L2_parity_way bit48 */
			{    0, 0,2}, /* core6 L2_parity_way bit49 */
			{    0, 0,2}, /* core6 L2_parity_way bit50 */
			{    0, 0,2}, /* core6 L2_parity_way bit51 */
			{    0, 0,2}, /* core6 L2_parity_way bit52 */
			{    0, 0,2}, /* core6 L2_parity_way bit53 */
			{    0, 0,2}, /* core6 L2_parity_way bit54 */
			{    0, 0,2}, /* core6 L2_parity_way bit55 */
			{    0, 0,2}, /* core6 L2_parity_way bit56 */
			{    0, 0,2}, /* core6 L2_parity_way bit57 */
			{    0, 0,2}, /* core6 L2_parity_way bit58 */
			{    0, 0,2}, /* core6 L2_parity_way bit59 */
			{    0, 0,2}, /* core6 L2_parity_way bit60 */
			{    0, 0,2}, /* core6 L2_parity_way bit61 */
			{    0, 0,2}, /* core6 L2_parity_way bit62 */
			{    0, 0,2}, /* core6 L2_parity_way bit63 */
			}},
			.L2_parity_banks = {{
			{ 6861, 8,0}, /* core6 L2_parity_banks bit0 */
			{ 6860, 8,0}, /* core6 L2_parity_banks bit1 */
			{ 6859, 8,0}, /* core6 L2_parity_banks bit2 */
			{ 6858, 8,0}, /* core6 L2_parity_banks bit3 */
			{ 6857, 8,0}, /* core6 L2_parity_banks bit4 */
			{ 6856, 8,0}, /* core6 L2_parity_banks bit5 */
			{ 6855, 8,0}, /* core6 L2_parity_banks bit6 */
			{ 6854, 8,0}, /* core6 L2_parity_banks bit7 */
			{    0, 0,2}, /* core6 L2_parity_banks bit8 */
			{    0, 0,2}, /* core6 L2_parity_banks bit9 */
			{    0, 0,2}, /* core6 L2_parity_banks bit10 */
			{    0, 0,2}, /* core6 L2_parity_banks bit11 */
			{    0, 0,2}, /* core6 L2_parity_banks bit12 */
			{    0, 0,2}, /* core6 L2_parity_banks bit13 */
			{    0, 0,2}, /* core6 L2_parity_banks bit14 */
			{    0, 0,2}, /* core6 L2_parity_banks bit15 */
			{    0, 0,2}, /* core6 L2_parity_banks bit16 */
			{    0, 0,2}, /* core6 L2_parity_banks bit17 */
			{    0, 0,2}, /* core6 L2_parity_banks bit18 */
			{    0, 0,2}, /* core6 L2_parity_banks bit19 */
			{    0, 0,2}, /* core6 L2_parity_banks bit20 */
			{    0, 0,2}, /* core6 L2_parity_banks bit21 */
			{    0, 0,2}, /* core6 L2_parity_banks bit22 */
			{    0, 0,2}, /* core6 L2_parity_banks bit23 */
			{    0, 0,2}, /* core6 L2_parity_banks bit24 */
			{    0, 0,2}, /* core6 L2_parity_banks bit25 */
			{    0, 0,2}, /* core6 L2_parity_banks bit26 */
			{    0, 0,2}, /* core6 L2_parity_banks bit27 */
			{    0, 0,2}, /* core6 L2_parity_banks bit28 */
			{    0, 0,2}, /* core6 L2_parity_banks bit29 */
			{    0, 0,2}, /* core6 L2_parity_banks bit30 */
			{    0, 0,2}, /* core6 L2_parity_banks bit31 */
			{    0, 0,2}, /* core6 L2_parity_banks bit32 */
			{    0, 0,2}, /* core6 L2_parity_banks bit33 */
			{    0, 0,2}, /* core6 L2_parity_banks bit34 */
			{    0, 0,2}, /* core6 L2_parity_banks bit35 */
			{    0, 0,2}, /* core6 L2_parity_banks bit36 */
			{    0, 0,2}, /* core6 L2_parity_banks bit37 */
			{    0, 0,2}, /* core6 L2_parity_banks bit38 */
			{    0, 0,2}, /* core6 L2_parity_banks bit39 */
			{    0, 0,2}, /* core6 L2_parity_banks bit40 */
			{    0, 0,2}, /* core6 L2_parity_banks bit41 */
			{    0, 0,2}, /* core6 L2_parity_banks bit42 */
			{    0, 0,2}, /* core6 L2_parity_banks bit43 */
			{    0, 0,2}, /* core6 L2_parity_banks bit44 */
			{    0, 0,2}, /* core6 L2_parity_banks bit45 */
			{    0, 0,2}, /* core6 L2_parity_banks bit46 */
			{    0, 0,2}, /* core6 L2_parity_banks bit47 */
			{    0, 0,2}, /* core6 L2_parity_banks bit48 */
			{    0, 0,2}, /* core6 L2_parity_banks bit49 */
			{    0, 0,2}, /* core6 L2_parity_banks bit50 */
			{    0, 0,2}, /* core6 L2_parity_banks bit51 */
			{    0, 0,2}, /* core6 L2_parity_banks bit52 */
			{    0, 0,2}, /* core6 L2_parity_banks bit53 */
			{    0, 0,2}, /* core6 L2_parity_banks bit54 */
			{    0, 0,2}, /* core6 L2_parity_banks bit55 */
			{    0, 0,2}, /* core6 L2_parity_banks bit56 */
			{    0, 0,2}, /* core6 L2_parity_banks bit57 */
			{    0, 0,2}, /* core6 L2_parity_banks bit58 */
			{    0, 0,2}, /* core6 L2_parity_banks bit59 */
			{    0, 0,2}, /* core6 L2_parity_banks bit60 */
			{    0, 0,2}, /* core6 L2_parity_banks bit61 */
			{    0, 0,2}, /* core6 L2_parity_banks bit62 */
			{    0, 0,2}, /* core6 L2_parity_banks bit63 */
			}},
	},
	{		/* core 7 */ 
			.i0_valid = {{
			{24167,55,0}, /* core7 i0_valid bit0 */
			{    0, 0,2}, /* core7 i0_valid bit1 */
			{    0, 0,2}, /* core7 i0_valid bit2 */
			{    0, 0,2}, /* core7 i0_valid bit3 */
			{    0, 0,2}, /* core7 i0_valid bit4 */
			{    0, 0,2}, /* core7 i0_valid bit5 */
			{    0, 0,2}, /* core7 i0_valid bit6 */
			{    0, 0,2}, /* core7 i0_valid bit7 */
			{    0, 0,2}, /* core7 i0_valid bit8 */
			{    0, 0,2}, /* core7 i0_valid bit9 */
			{    0, 0,2}, /* core7 i0_valid bit10 */
			{    0, 0,2}, /* core7 i0_valid bit11 */
			{    0, 0,2}, /* core7 i0_valid bit12 */
			{    0, 0,2}, /* core7 i0_valid bit13 */
			{    0, 0,2}, /* core7 i0_valid bit14 */
			{    0, 0,2}, /* core7 i0_valid bit15 */
			{    0, 0,2}, /* core7 i0_valid bit16 */
			{    0, 0,2}, /* core7 i0_valid bit17 */
			{    0, 0,2}, /* core7 i0_valid bit18 */
			{    0, 0,2}, /* core7 i0_valid bit19 */
			{    0, 0,2}, /* core7 i0_valid bit20 */
			{    0, 0,2}, /* core7 i0_valid bit21 */
			{    0, 0,2}, /* core7 i0_valid bit22 */
			{    0, 0,2}, /* core7 i0_valid bit23 */
			{    0, 0,2}, /* core7 i0_valid bit24 */
			{    0, 0,2}, /* core7 i0_valid bit25 */
			{    0, 0,2}, /* core7 i0_valid bit26 */
			{    0, 0,2}, /* core7 i0_valid bit27 */
			{    0, 0,2}, /* core7 i0_valid bit28 */
			{    0, 0,2}, /* core7 i0_valid bit29 */
			{    0, 0,2}, /* core7 i0_valid bit30 */
			{    0, 0,2}, /* core7 i0_valid bit31 */
			{    0, 0,2}, /* core7 i0_valid bit32 */
			{    0, 0,2}, /* core7 i0_valid bit33 */
			{    0, 0,2}, /* core7 i0_valid bit34 */
			{    0, 0,2}, /* core7 i0_valid bit35 */
			{    0, 0,2}, /* core7 i0_valid bit36 */
			{    0, 0,2}, /* core7 i0_valid bit37 */
			{    0, 0,2}, /* core7 i0_valid bit38 */
			{    0, 0,2}, /* core7 i0_valid bit39 */
			{    0, 0,2}, /* core7 i0_valid bit40 */
			{    0, 0,2}, /* core7 i0_valid bit41 */
			{    0, 0,2}, /* core7 i0_valid bit42 */
			{    0, 0,2}, /* core7 i0_valid bit43 */
			{    0, 0,2}, /* core7 i0_valid bit44 */
			{    0, 0,2}, /* core7 i0_valid bit45 */
			{    0, 0,2}, /* core7 i0_valid bit46 */
			{    0, 0,2}, /* core7 i0_valid bit47 */
			{    0, 0,2}, /* core7 i0_valid bit48 */
			{    0, 0,2}, /* core7 i0_valid bit49 */
			{    0, 0,2}, /* core7 i0_valid bit50 */
			{    0, 0,2}, /* core7 i0_valid bit51 */
			{    0, 0,2}, /* core7 i0_valid bit52 */
			{    0, 0,2}, /* core7 i0_valid bit53 */
			{    0, 0,2}, /* core7 i0_valid bit54 */
			{    0, 0,2}, /* core7 i0_valid bit55 */
			{    0, 0,2}, /* core7 i0_valid bit56 */
			{    0, 0,2}, /* core7 i0_valid bit57 */
			{    0, 0,2}, /* core7 i0_valid bit58 */
			{    0, 0,2}, /* core7 i0_valid bit59 */
			{    0, 0,2}, /* core7 i0_valid bit60 */
			{    0, 0,2}, /* core7 i0_valid bit61 */
			{    0, 0,2}, /* core7 i0_valid bit62 */
			{    0, 0,2}, /* core7 i0_valid bit63 */
			}},
			.i0_pc = {{
			{  578,53,0}, /* core7 i0_pc bit0 */
			{  577,53,0}, /* core7 i0_pc bit1 */
			{  575,53,0}, /* core7 i0_pc bit2 */
			{  576,53,0}, /* core7 i0_pc bit3 */
			{ 6407,52,0}, /* core7 i0_pc bit4 */
			{21066,53,0}, /* core7 i0_pc bit5 */
			{21061,53,0}, /* core7 i0_pc bit6 */
			{21065,53,0}, /* core7 i0_pc bit7 */
			{ 6405,52,0}, /* core7 i0_pc bit8 */
			{21064,53,0}, /* core7 i0_pc bit9 */
			{21052,53,0}, /* core7 i0_pc bit10 */
			{21056,53,0}, /* core7 i0_pc bit11 */
			{21060,53,0}, /* core7 i0_pc bit12 */
			{21053,53,0}, /* core7 i0_pc bit13 */
			{ 6409,52,0}, /* core7 i0_pc bit14 */
			{ 6411,52,0}, /* core7 i0_pc bit15 */
			{  581,53,0}, /* core7 i0_pc bit16 */
			{  582,53,0}, /* core7 i0_pc bit17 */
			{  580,53,0}, /* core7 i0_pc bit18 */
			{  579,53,0}, /* core7 i0_pc bit19 */
			{ 6406,52,0}, /* core7 i0_pc bit20 */
			{21063,53,0}, /* core7 i0_pc bit21 */
			{21058,53,0}, /* core7 i0_pc bit22 */
			{21057,53,0}, /* core7 i0_pc bit23 */
			{ 6404,52,0}, /* core7 i0_pc bit24 */
			{21062,53,0}, /* core7 i0_pc bit25 */
			{ 6410,52,0}, /* core7 i0_pc bit26 */
			{21051,53,0}, /* core7 i0_pc bit27 */
			{21059,53,0}, /* core7 i0_pc bit28 */
			{21054,53,0}, /* core7 i0_pc bit29 */
			{ 6408,52,0}, /* core7 i0_pc bit30 */
			{21055,53,0}, /* core7 i0_pc bit31 */
			{12198,55,0}, /* core7 i0_pc bit32 */
			{12197,55,0}, /* core7 i0_pc bit33 */
			{12204,55,0}, /* core7 i0_pc bit34 */
			{12199,55,0}, /* core7 i0_pc bit35 */
			{12215,55,0}, /* core7 i0_pc bit36 */
			{12208,55,0}, /* core7 i0_pc bit37 */
			{12210,55,0}, /* core7 i0_pc bit38 */
			{12211,55,0}, /* core7 i0_pc bit39 */
			{12196,55,0}, /* core7 i0_pc bit40 */
			{ 6419,52,0}, /* core7 i0_pc bit41 */
			{12219,55,0}, /* core7 i0_pc bit42 */
			{ 6414,52,0}, /* core7 i0_pc bit43 */
			{ 6418,52,0}, /* core7 i0_pc bit44 */
			{ 6413,52,0}, /* core7 i0_pc bit45 */
			{ 6412,52,0}, /* core7 i0_pc bit46 */
			{ 6415,52,0}, /* core7 i0_pc bit47 */
			{12201,55,0}, /* core7 i0_pc bit48 */
			{12205,55,0}, /* core7 i0_pc bit49 */
			{12200,55,0}, /* core7 i0_pc bit50 */
			{12202,55,0}, /* core7 i0_pc bit51 */
			{12212,55,0}, /* core7 i0_pc bit52 */
			{12213,55,0}, /* core7 i0_pc bit53 */
			{12214,55,0}, /* core7 i0_pc bit54 */
			{12209,55,0}, /* core7 i0_pc bit55 */
			{12206,55,0}, /* core7 i0_pc bit56 */
			{12217,55,0}, /* core7 i0_pc bit57 */
			{ 6416,52,0}, /* core7 i0_pc bit58 */
			{ 6417,52,0}, /* core7 i0_pc bit59 */
			{12216,55,0}, /* core7 i0_pc bit60 */
			{12218,55,0}, /* core7 i0_pc bit61 */
			{12203,55,0}, /* core7 i0_pc bit62 */
			{12207,55,0}, /* core7 i0_pc bit63 */
			}},
			.i1_valid = {{
			{24166,55,0}, /* core7 i1_valid bit0 */
			{    0, 0,2}, /* core7 i1_valid bit1 */
			{    0, 0,2}, /* core7 i1_valid bit2 */
			{    0, 0,2}, /* core7 i1_valid bit3 */
			{    0, 0,2}, /* core7 i1_valid bit4 */
			{    0, 0,2}, /* core7 i1_valid bit5 */
			{    0, 0,2}, /* core7 i1_valid bit6 */
			{    0, 0,2}, /* core7 i1_valid bit7 */
			{    0, 0,2}, /* core7 i1_valid bit8 */
			{    0, 0,2}, /* core7 i1_valid bit9 */
			{    0, 0,2}, /* core7 i1_valid bit10 */
			{    0, 0,2}, /* core7 i1_valid bit11 */
			{    0, 0,2}, /* core7 i1_valid bit12 */
			{    0, 0,2}, /* core7 i1_valid bit13 */
			{    0, 0,2}, /* core7 i1_valid bit14 */
			{    0, 0,2}, /* core7 i1_valid bit15 */
			{    0, 0,2}, /* core7 i1_valid bit16 */
			{    0, 0,2}, /* core7 i1_valid bit17 */
			{    0, 0,2}, /* core7 i1_valid bit18 */
			{    0, 0,2}, /* core7 i1_valid bit19 */
			{    0, 0,2}, /* core7 i1_valid bit20 */
			{    0, 0,2}, /* core7 i1_valid bit21 */
			{    0, 0,2}, /* core7 i1_valid bit22 */
			{    0, 0,2}, /* core7 i1_valid bit23 */
			{    0, 0,2}, /* core7 i1_valid bit24 */
			{    0, 0,2}, /* core7 i1_valid bit25 */
			{    0, 0,2}, /* core7 i1_valid bit26 */
			{    0, 0,2}, /* core7 i1_valid bit27 */
			{    0, 0,2}, /* core7 i1_valid bit28 */
			{    0, 0,2}, /* core7 i1_valid bit29 */
			{    0, 0,2}, /* core7 i1_valid bit30 */
			{    0, 0,2}, /* core7 i1_valid bit31 */
			{    0, 0,2}, /* core7 i1_valid bit32 */
			{    0, 0,2}, /* core7 i1_valid bit33 */
			{    0, 0,2}, /* core7 i1_valid bit34 */
			{    0, 0,2}, /* core7 i1_valid bit35 */
			{    0, 0,2}, /* core7 i1_valid bit36 */
			{    0, 0,2}, /* core7 i1_valid bit37 */
			{    0, 0,2}, /* core7 i1_valid bit38 */
			{    0, 0,2}, /* core7 i1_valid bit39 */
			{    0, 0,2}, /* core7 i1_valid bit40 */
			{    0, 0,2}, /* core7 i1_valid bit41 */
			{    0, 0,2}, /* core7 i1_valid bit42 */
			{    0, 0,2}, /* core7 i1_valid bit43 */
			{    0, 0,2}, /* core7 i1_valid bit44 */
			{    0, 0,2}, /* core7 i1_valid bit45 */
			{    0, 0,2}, /* core7 i1_valid bit46 */
			{    0, 0,2}, /* core7 i1_valid bit47 */
			{    0, 0,2}, /* core7 i1_valid bit48 */
			{    0, 0,2}, /* core7 i1_valid bit49 */
			{    0, 0,2}, /* core7 i1_valid bit50 */
			{    0, 0,2}, /* core7 i1_valid bit51 */
			{    0, 0,2}, /* core7 i1_valid bit52 */
			{    0, 0,2}, /* core7 i1_valid bit53 */
			{    0, 0,2}, /* core7 i1_valid bit54 */
			{    0, 0,2}, /* core7 i1_valid bit55 */
			{    0, 0,2}, /* core7 i1_valid bit56 */
			{    0, 0,2}, /* core7 i1_valid bit57 */
			{    0, 0,2}, /* core7 i1_valid bit58 */
			{    0, 0,2}, /* core7 i1_valid bit59 */
			{    0, 0,2}, /* core7 i1_valid bit60 */
			{    0, 0,2}, /* core7 i1_valid bit61 */
			{    0, 0,2}, /* core7 i1_valid bit62 */
			{    0, 0,2}, /* core7 i1_valid bit63 */
			}},
			.i1_pc = {{
			{ 7236,58,0}, /* core7 i1_pc bit0 */
			{12189,55,0}, /* core7 i1_pc bit1 */
			{ 7238,58,0}, /* core7 i1_pc bit2 */
			{12220,55,0}, /* core7 i1_pc bit3 */
			{12227,55,0}, /* core7 i1_pc bit4 */
			{21074,53,0}, /* core7 i1_pc bit5 */
			{25366,54,0}, /* core7 i1_pc bit6 */
			{21073,53,0}, /* core7 i1_pc bit7 */
			{ 7233,58,0}, /* core7 i1_pc bit8 */
			{21070,53,0}, /* core7 i1_pc bit9 */
			{12221,55,0}, /* core7 i1_pc bit10 */
			{12223,55,0}, /* core7 i1_pc bit11 */
			{12222,55,0}, /* core7 i1_pc bit12 */
			{21067,53,0}, /* core7 i1_pc bit13 */
			{ 1069,53,0}, /* core7 i1_pc bit14 */
			{21071,53,0}, /* core7 i1_pc bit15 */
			{ 7234,58,0}, /* core7 i1_pc bit16 */
			{ 7237,58,0}, /* core7 i1_pc bit17 */
			{ 7239,58,0}, /* core7 i1_pc bit18 */
			{ 7240,58,0}, /* core7 i1_pc bit19 */
			{12224,55,0}, /* core7 i1_pc bit20 */
			{ 1072,53,0}, /* core7 i1_pc bit21 */
			{ 1073,53,0}, /* core7 i1_pc bit22 */
			{21068,53,0}, /* core7 i1_pc bit23 */
			{ 7235,58,0}, /* core7 i1_pc bit24 */
			{21072,53,0}, /* core7 i1_pc bit25 */
			{12226,55,0}, /* core7 i1_pc bit26 */
			{ 1071,53,0}, /* core7 i1_pc bit27 */
			{12225,55,0}, /* core7 i1_pc bit28 */
			{21069,53,0}, /* core7 i1_pc bit29 */
			{ 1070,53,0}, /* core7 i1_pc bit30 */
			{ 1074,53,0}, /* core7 i1_pc bit31 */
			{12260,55,0}, /* core7 i1_pc bit32 */
			{12252,55,0}, /* core7 i1_pc bit33 */
			{12253,55,0}, /* core7 i1_pc bit34 */
			{12251,55,0}, /* core7 i1_pc bit35 */
			{12248,55,0}, /* core7 i1_pc bit36 */
			{12228,55,0}, /* core7 i1_pc bit37 */
			{ 6172,52,0}, /* core7 i1_pc bit38 */
			{ 6171,52,0}, /* core7 i1_pc bit39 */
			{12247,55,0}, /* core7 i1_pc bit40 */
			{ 6173,52,0}, /* core7 i1_pc bit41 */
			{ 6177,52,0}, /* core7 i1_pc bit42 */
			{ 6176,52,0}, /* core7 i1_pc bit43 */
			{12235,55,0}, /* core7 i1_pc bit44 */
			{ 6174,52,0}, /* core7 i1_pc bit45 */
			{ 6175,52,0}, /* core7 i1_pc bit46 */
			{ 6170,52,0}, /* core7 i1_pc bit47 */
			{12246,55,0}, /* core7 i1_pc bit48 */
			{12257,55,0}, /* core7 i1_pc bit49 */
			{12256,55,0}, /* core7 i1_pc bit50 */
			{12250,55,0}, /* core7 i1_pc bit51 */
			{12254,55,0}, /* core7 i1_pc bit52 */
			{12258,55,0}, /* core7 i1_pc bit53 */
			{12261,55,0}, /* core7 i1_pc bit54 */
			{12229,55,0}, /* core7 i1_pc bit55 */
			{12255,55,0}, /* core7 i1_pc bit56 */
			{12259,55,0}, /* core7 i1_pc bit57 */
			{12249,55,0}, /* core7 i1_pc bit58 */
			{12230,55,0}, /* core7 i1_pc bit59 */
			{12231,55,0}, /* core7 i1_pc bit60 */
			{12233,55,0}, /* core7 i1_pc bit61 */
			{12232,55,0}, /* core7 i1_pc bit62 */
			{12234,55,0}, /* core7 i1_pc bit63 */
			}},
			.i2_valid = {{
			{24168,55,0}, /* core7 i2_valid bit0 */
			{    0, 0,2}, /* core7 i2_valid bit1 */
			{    0, 0,2}, /* core7 i2_valid bit2 */
			{    0, 0,2}, /* core7 i2_valid bit3 */
			{    0, 0,2}, /* core7 i2_valid bit4 */
			{    0, 0,2}, /* core7 i2_valid bit5 */
			{    0, 0,2}, /* core7 i2_valid bit6 */
			{    0, 0,2}, /* core7 i2_valid bit7 */
			{    0, 0,2}, /* core7 i2_valid bit8 */
			{    0, 0,2}, /* core7 i2_valid bit9 */
			{    0, 0,2}, /* core7 i2_valid bit10 */
			{    0, 0,2}, /* core7 i2_valid bit11 */
			{    0, 0,2}, /* core7 i2_valid bit12 */
			{    0, 0,2}, /* core7 i2_valid bit13 */
			{    0, 0,2}, /* core7 i2_valid bit14 */
			{    0, 0,2}, /* core7 i2_valid bit15 */
			{    0, 0,2}, /* core7 i2_valid bit16 */
			{    0, 0,2}, /* core7 i2_valid bit17 */
			{    0, 0,2}, /* core7 i2_valid bit18 */
			{    0, 0,2}, /* core7 i2_valid bit19 */
			{    0, 0,2}, /* core7 i2_valid bit20 */
			{    0, 0,2}, /* core7 i2_valid bit21 */
			{    0, 0,2}, /* core7 i2_valid bit22 */
			{    0, 0,2}, /* core7 i2_valid bit23 */
			{    0, 0,2}, /* core7 i2_valid bit24 */
			{    0, 0,2}, /* core7 i2_valid bit25 */
			{    0, 0,2}, /* core7 i2_valid bit26 */
			{    0, 0,2}, /* core7 i2_valid bit27 */
			{    0, 0,2}, /* core7 i2_valid bit28 */
			{    0, 0,2}, /* core7 i2_valid bit29 */
			{    0, 0,2}, /* core7 i2_valid bit30 */
			{    0, 0,2}, /* core7 i2_valid bit31 */
			{    0, 0,2}, /* core7 i2_valid bit32 */
			{    0, 0,2}, /* core7 i2_valid bit33 */
			{    0, 0,2}, /* core7 i2_valid bit34 */
			{    0, 0,2}, /* core7 i2_valid bit35 */
			{    0, 0,2}, /* core7 i2_valid bit36 */
			{    0, 0,2}, /* core7 i2_valid bit37 */
			{    0, 0,2}, /* core7 i2_valid bit38 */
			{    0, 0,2}, /* core7 i2_valid bit39 */
			{    0, 0,2}, /* core7 i2_valid bit40 */
			{    0, 0,2}, /* core7 i2_valid bit41 */
			{    0, 0,2}, /* core7 i2_valid bit42 */
			{    0, 0,2}, /* core7 i2_valid bit43 */
			{    0, 0,2}, /* core7 i2_valid bit44 */
			{    0, 0,2}, /* core7 i2_valid bit45 */
			{    0, 0,2}, /* core7 i2_valid bit46 */
			{    0, 0,2}, /* core7 i2_valid bit47 */
			{    0, 0,2}, /* core7 i2_valid bit48 */
			{    0, 0,2}, /* core7 i2_valid bit49 */
			{    0, 0,2}, /* core7 i2_valid bit50 */
			{    0, 0,2}, /* core7 i2_valid bit51 */
			{    0, 0,2}, /* core7 i2_valid bit52 */
			{    0, 0,2}, /* core7 i2_valid bit53 */
			{    0, 0,2}, /* core7 i2_valid bit54 */
			{    0, 0,2}, /* core7 i2_valid bit55 */
			{    0, 0,2}, /* core7 i2_valid bit56 */
			{    0, 0,2}, /* core7 i2_valid bit57 */
			{    0, 0,2}, /* core7 i2_valid bit58 */
			{    0, 0,2}, /* core7 i2_valid bit59 */
			{    0, 0,2}, /* core7 i2_valid bit60 */
			{    0, 0,2}, /* core7 i2_valid bit61 */
			{    0, 0,2}, /* core7 i2_valid bit62 */
			{    0, 0,2}, /* core7 i2_valid bit63 */
			}},
			.i2_pc = {{
			{24643,54,0}, /* core7 i2_pc bit0 */
			{20391,57,0}, /* core7 i2_pc bit1 */
			{20374,57,0}, /* core7 i2_pc bit2 */
			{20373,57,0}, /* core7 i2_pc bit3 */
			{20372,57,0}, /* core7 i2_pc bit4 */
			{20392,57,0}, /* core7 i2_pc bit5 */
			{20367,57,0}, /* core7 i2_pc bit6 */
			{20393,57,0}, /* core7 i2_pc bit7 */
			{24639,54,0}, /* core7 i2_pc bit8 */
			{20369,57,0}, /* core7 i2_pc bit9 */
			{24642,54,0}, /* core7 i2_pc bit10 */
			{20368,57,0}, /* core7 i2_pc bit11 */
			{24567,54,0}, /* core7 i2_pc bit12 */
			{20390,57,0}, /* core7 i2_pc bit13 */
			{20370,57,0}, /* core7 i2_pc bit14 */
			{20371,57,0}, /* core7 i2_pc bit15 */
			{24640,54,0}, /* core7 i2_pc bit16 */
			{24645,54,0}, /* core7 i2_pc bit17 */
			{20389,57,0}, /* core7 i2_pc bit18 */
			{24570,54,0}, /* core7 i2_pc bit19 */
			{20388,57,0}, /* core7 i2_pc bit20 */
			{24641,54,0}, /* core7 i2_pc bit21 */
			{24573,54,0}, /* core7 i2_pc bit22 */
			{24644,54,0}, /* core7 i2_pc bit23 */
			{24569,54,0}, /* core7 i2_pc bit24 */
			{24566,54,0}, /* core7 i2_pc bit25 */
			{24571,54,0}, /* core7 i2_pc bit26 */
			{24568,54,0}, /* core7 i2_pc bit27 */
			{24565,54,0}, /* core7 i2_pc bit28 */
			{24574,54,0}, /* core7 i2_pc bit29 */
			{24646,54,0}, /* core7 i2_pc bit30 */
			{24572,54,0}, /* core7 i2_pc bit31 */
			{12909,55,0}, /* core7 i2_pc bit32 */
			{12894,55,0}, /* core7 i2_pc bit33 */
			{12895,55,0}, /* core7 i2_pc bit34 */
			{12907,55,0}, /* core7 i2_pc bit35 */
			{12896,55,0}, /* core7 i2_pc bit36 */
			{12908,55,0}, /* core7 i2_pc bit37 */
			{12889,55,0}, /* core7 i2_pc bit38 */
			{12905,55,0}, /* core7 i2_pc bit39 */
			{12915,55,0}, /* core7 i2_pc bit40 */
			{12902,55,0}, /* core7 i2_pc bit41 */
			{12911,55,0}, /* core7 i2_pc bit42 */
			{12916,55,0}, /* core7 i2_pc bit43 */
			{12901,55,0}, /* core7 i2_pc bit44 */
			{12890,55,0}, /* core7 i2_pc bit45 */
			{12893,55,0}, /* core7 i2_pc bit46 */
			{12912,55,0}, /* core7 i2_pc bit47 */
			{12913,55,0}, /* core7 i2_pc bit48 */
			{12921,55,0}, /* core7 i2_pc bit49 */
			{12919,55,0}, /* core7 i2_pc bit50 */
			{12892,55,0}, /* core7 i2_pc bit51 */
			{12922,55,0}, /* core7 i2_pc bit52 */
			{12891,55,0}, /* core7 i2_pc bit53 */
			{12923,55,0}, /* core7 i2_pc bit54 */
			{12910,55,0}, /* core7 i2_pc bit55 */
			{12914,55,0}, /* core7 i2_pc bit56 */
			{12920,55,0}, /* core7 i2_pc bit57 */
			{12926,55,0}, /* core7 i2_pc bit58 */
			{12904,55,0}, /* core7 i2_pc bit59 */
			{12906,55,0}, /* core7 i2_pc bit60 */
			{12924,55,0}, /* core7 i2_pc bit61 */
			{12925,55,0}, /* core7 i2_pc bit62 */
			{12903,55,0}, /* core7 i2_pc bit63 */
			}},
			.last_branch = {{
			{    0, 0,2}, /* core7 last_branch bit0 */
			{ 5460,58,0}, /* core7 last_branch bit1 */
			{ 5454,58,0}, /* core7 last_branch bit2 */
			{ 5463,58,0}, /* core7 last_branch bit3 */
			{ 5451,58,0}, /* core7 last_branch bit4 */
			{ 5452,58,0}, /* core7 last_branch bit5 */
			{16649,57,0}, /* core7 last_branch bit6 */
			{ 5453,58,0}, /* core7 last_branch bit7 */
			{16650,57,0}, /* core7 last_branch bit8 */
			{16651,57,0}, /* core7 last_branch bit9 */
			{ 5449,58,0}, /* core7 last_branch bit10 */
			{ 5448,58,0}, /* core7 last_branch bit11 */
			{16588,57,0}, /* core7 last_branch bit12 */
			{ 5456,58,0}, /* core7 last_branch bit13 */
			{ 5450,58,0}, /* core7 last_branch bit14 */
			{16644,57,0}, /* core7 last_branch bit15 */
			{16597,57,0}, /* core7 last_branch bit16 */
			{11296,58,0}, /* core7 last_branch bit17 */
			{11298,58,0}, /* core7 last_branch bit18 */
			{11302,58,0}, /* core7 last_branch bit19 */
			{11301,58,0}, /* core7 last_branch bit20 */
			{11300,58,0}, /* core7 last_branch bit21 */
			{11299,58,0}, /* core7 last_branch bit22 */
			{11295,58,0}, /* core7 last_branch bit23 */
			{16600,57,0}, /* core7 last_branch bit24 */
			{16590,57,0}, /* core7 last_branch bit25 */
			{16596,57,0}, /* core7 last_branch bit26 */
			{16595,57,0}, /* core7 last_branch bit27 */
			{16589,57,0}, /* core7 last_branch bit28 */
			{ 5459,58,0}, /* core7 last_branch bit29 */
			{ 5462,58,0}, /* core7 last_branch bit30 */
			{ 5461,58,0}, /* core7 last_branch bit31 */
			{16591,57,0}, /* core7 last_branch bit32 */
			{16601,57,0}, /* core7 last_branch bit33 */
			{16592,57,0}, /* core7 last_branch bit34 */
			{16648,57,0}, /* core7 last_branch bit35 */
			{16599,57,0}, /* core7 last_branch bit36 */
			{16593,57,0}, /* core7 last_branch bit37 */
			{ 5455,58,0}, /* core7 last_branch bit38 */
			{ 5458,58,0}, /* core7 last_branch bit39 */
			{16646,57,0}, /* core7 last_branch bit40 */
			{11297,58,0}, /* core7 last_branch bit41 */
			{16603,57,0}, /* core7 last_branch bit42 */
			{ 5457,58,0}, /* core7 last_branch bit43 */
			{16602,57,0}, /* core7 last_branch bit44 */
			{16647,57,0}, /* core7 last_branch bit45 */
			{16645,57,0}, /* core7 last_branch bit46 */
			{16594,57,0}, /* core7 last_branch bit47 */
			{16598,57,0}, /* core7 last_branch bit48 */
			{    0, 0,2}, /* core7 last_branch bit49 */
			{    0, 0,2}, /* core7 last_branch bit50 */
			{    0, 0,2}, /* core7 last_branch bit51 */
			{    0, 0,2}, /* core7 last_branch bit52 */
			{    0, 0,2}, /* core7 last_branch bit53 */
			{    0, 0,2}, /* core7 last_branch bit54 */
			{    0, 0,2}, /* core7 last_branch bit55 */
			{    0, 0,2}, /* core7 last_branch bit56 */
			{    0, 0,2}, /* core7 last_branch bit57 */
			{    0, 0,2}, /* core7 last_branch bit58 */
			{    0, 0,2}, /* core7 last_branch bit59 */
			{    0, 0,2}, /* core7 last_branch bit60 */
			{    0, 0,2}, /* core7 last_branch bit61 */
			{    0, 0,2}, /* core7 last_branch bit62 */
			{    0, 0,2}, /* core7 last_branch bit63 */
			}},
			.sram_wr_ptr_0 = {{
			{13177,54,0}, /* core7 sram_wr_ptr_0 bit0 */
			{ 6121,56,1}, /* core7 sram_wr_ptr_0 bit1 */
			{13180,54,0}, /* core7 sram_wr_ptr_0 bit2 */
			{ 3863,58,0}, /* core7 sram_wr_ptr_0 bit3 */
			{13179,54,0}, /* core7 sram_wr_ptr_0 bit4 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit5 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit6 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit7 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit8 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit9 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit10 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit11 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit12 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit13 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit14 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit15 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit16 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit17 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit18 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit19 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit20 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit21 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit22 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit23 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit24 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit25 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit26 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit27 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit28 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit29 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit30 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit31 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit32 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit33 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit34 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit35 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit36 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit37 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit38 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit39 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit40 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit41 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit42 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit43 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit44 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit45 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit46 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit47 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit48 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit49 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit50 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit51 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit52 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit53 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit54 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit55 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit56 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit57 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit58 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit59 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit60 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit61 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit62 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit63 */
			}},
			.sram_wr_ptr_1 = {{
			{13175,54,0}, /* core7 sram_wr_ptr_1 bit0 */
			{13174,54,0}, /* core7 sram_wr_ptr_1 bit1 */
			{13178,54,0}, /* core7 sram_wr_ptr_1 bit2 */
			{13173,54,0}, /* core7 sram_wr_ptr_1 bit3 */
			{13176,54,0}, /* core7 sram_wr_ptr_1 bit4 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit5 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit6 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit7 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit8 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit9 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit10 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit11 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit12 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit13 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit14 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit15 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit16 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit17 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit18 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit19 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit20 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit21 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit22 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit23 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit24 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit25 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit26 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit27 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit28 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit29 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit30 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit31 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit32 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit33 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit34 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit35 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit36 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit37 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit38 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit39 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit40 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit41 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit42 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit43 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit44 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit45 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit46 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit47 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit48 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit49 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit50 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit51 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit52 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit53 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit54 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit55 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit56 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit57 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit58 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit59 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit60 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit61 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit62 */
			{    0, 0,2}, /* core7 sram_wr_ptr_1 bit63 */
			}},
			.sram_wr_ptr_2 = {{
			{ 3859,58,0}, /* core7 sram_wr_ptr_2 bit0 */
			{ 3862,58,0}, /* core7 sram_wr_ptr_2 bit1 */
			{ 3858,58,0}, /* core7 sram_wr_ptr_2 bit2 */
			{ 3860,58,0}, /* core7 sram_wr_ptr_2 bit3 */
			{ 3861,58,0}, /* core7 sram_wr_ptr_2 bit4 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit5 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit6 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit7 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit8 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit9 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit10 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit11 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit12 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit13 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit14 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit15 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit16 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit17 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit18 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit19 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit20 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit21 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit22 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit23 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit24 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit25 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit26 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit27 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit28 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit29 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit30 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit31 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit32 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit33 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit34 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit35 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit36 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit37 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit38 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit39 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit40 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit41 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit42 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit43 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit44 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit45 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit46 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit47 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit48 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit49 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit50 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit51 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit52 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit53 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit54 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit55 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit56 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit57 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit58 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit59 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit60 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit61 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit62 */
			{    0, 0,2}, /* core7 sram_wr_ptr_2 bit63 */
			}},
			.return_Stack_pointer = {{
			{ 4320,56,1}, /* core7 return_Stack_pointer bit0 */
			{ 4318,56,1}, /* core7 return_Stack_pointer bit1 */
			{ 4319,56,1}, /* core7 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core7 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{22792,56,1}, /* core7 return_Stack0 bit0 */
			{15180,57,0}, /* core7 return_Stack0 bit1 */
			{15222,57,0}, /* core7 return_Stack0 bit2 */
			{15227,57,0}, /* core7 return_Stack0 bit3 */
			{22788,56,1}, /* core7 return_Stack0 bit4 */
			{15226,57,0}, /* core7 return_Stack0 bit5 */
			{15229,57,0}, /* core7 return_Stack0 bit6 */
			{15228,57,0}, /* core7 return_Stack0 bit7 */
			{15225,57,0}, /* core7 return_Stack0 bit8 */
			{15115,57,0}, /* core7 return_Stack0 bit9 */
			{15224,57,0}, /* core7 return_Stack0 bit10 */
			{15116,57,0}, /* core7 return_Stack0 bit11 */
			{22790,56,1}, /* core7 return_Stack0 bit12 */
			{22789,56,1}, /* core7 return_Stack0 bit13 */
			{15117,57,0}, /* core7 return_Stack0 bit14 */
			{15223,57,0}, /* core7 return_Stack0 bit15 */
			{15187,57,0}, /* core7 return_Stack0 bit16 */
			{15184,57,0}, /* core7 return_Stack0 bit17 */
			{15182,57,0}, /* core7 return_Stack0 bit18 */
			{15183,57,0}, /* core7 return_Stack0 bit19 */
			{15186,57,0}, /* core7 return_Stack0 bit20 */
			{15185,57,0}, /* core7 return_Stack0 bit21 */
			{ 3682,56,1}, /* core7 return_Stack0 bit22 */
			{ 3684,56,1}, /* core7 return_Stack0 bit23 */
			{25582,54,0}, /* core7 return_Stack0 bit24 */
			{ 3677,56,1}, /* core7 return_Stack0 bit25 */
			{ 3681,56,1}, /* core7 return_Stack0 bit26 */
			{ 3683,56,1}, /* core7 return_Stack0 bit27 */
			{ 3679,56,1}, /* core7 return_Stack0 bit28 */
			{ 3678,56,1}, /* core7 return_Stack0 bit29 */
			{ 3680,56,1}, /* core7 return_Stack0 bit30 */
			{ 3725,56,1}, /* core7 return_Stack0 bit31 */
			{22793,56,1}, /* core7 return_Stack0 bit32 */
			{22791,56,1}, /* core7 return_Stack0 bit33 */
			{ 3731,56,1}, /* core7 return_Stack0 bit34 */
			{22886,56,1}, /* core7 return_Stack0 bit35 */
			{22888,56,1}, /* core7 return_Stack0 bit36 */
			{ 3728,56,1}, /* core7 return_Stack0 bit37 */
			{ 3727,56,1}, /* core7 return_Stack0 bit38 */
			{ 3730,56,1}, /* core7 return_Stack0 bit39 */
			{22887,56,1}, /* core7 return_Stack0 bit40 */
			{ 3726,56,1}, /* core7 return_Stack0 bit41 */
			{ 3729,56,1}, /* core7 return_Stack0 bit42 */
			{22889,56,1}, /* core7 return_Stack0 bit43 */
			{22890,56,1}, /* core7 return_Stack0 bit44 */
			{ 3732,56,1}, /* core7 return_Stack0 bit45 */
			{22795,56,1}, /* core7 return_Stack0 bit46 */
			{22891,56,1}, /* core7 return_Stack0 bit47 */
			{22794,56,1}, /* core7 return_Stack0 bit48 */
			{    0, 0,2}, /* core7 return_Stack0 bit49 */
			{    0, 0,2}, /* core7 return_Stack0 bit50 */
			{    0, 0,2}, /* core7 return_Stack0 bit51 */
			{    0, 0,2}, /* core7 return_Stack0 bit52 */
			{    0, 0,2}, /* core7 return_Stack0 bit53 */
			{    0, 0,2}, /* core7 return_Stack0 bit54 */
			{    0, 0,2}, /* core7 return_Stack0 bit55 */
			{    0, 0,2}, /* core7 return_Stack0 bit56 */
			{    0, 0,2}, /* core7 return_Stack0 bit57 */
			{    0, 0,2}, /* core7 return_Stack0 bit58 */
			{    0, 0,2}, /* core7 return_Stack0 bit59 */
			{    0, 0,2}, /* core7 return_Stack0 bit60 */
			{    0, 0,2}, /* core7 return_Stack0 bit61 */
			{    0, 0,2}, /* core7 return_Stack0 bit62 */
			{    0, 0,2}, /* core7 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{22850,56,1}, /* core7 return_Stack1 bit0 */
			{15164,57,0}, /* core7 return_Stack1 bit1 */
			{ 4681,56,1}, /* core7 return_Stack1 bit2 */
			{ 4682,56,1}, /* core7 return_Stack1 bit3 */
			{15165,57,0}, /* core7 return_Stack1 bit4 */
			{15230,57,0}, /* core7 return_Stack1 bit5 */
			{ 4687,56,1}, /* core7 return_Stack1 bit6 */
			{ 4688,56,1}, /* core7 return_Stack1 bit7 */
			{ 4683,56,1}, /* core7 return_Stack1 bit8 */
			{15134,57,0}, /* core7 return_Stack1 bit9 */
			{ 4686,56,1}, /* core7 return_Stack1 bit10 */
			{15136,57,0}, /* core7 return_Stack1 bit11 */
			{15137,57,0}, /* core7 return_Stack1 bit12 */
			{15139,57,0}, /* core7 return_Stack1 bit13 */
			{15135,57,0}, /* core7 return_Stack1 bit14 */
			{ 4684,56,1}, /* core7 return_Stack1 bit15 */
			{ 4685,56,1}, /* core7 return_Stack1 bit16 */
			{15170,57,0}, /* core7 return_Stack1 bit17 */
			{15167,57,0}, /* core7 return_Stack1 bit18 */
			{15169,57,0}, /* core7 return_Stack1 bit19 */
			{15171,57,0}, /* core7 return_Stack1 bit20 */
			{15168,57,0}, /* core7 return_Stack1 bit21 */
			{ 3600,56,1}, /* core7 return_Stack1 bit22 */
			{ 3604,56,1}, /* core7 return_Stack1 bit23 */
			{ 3602,56,1}, /* core7 return_Stack1 bit24 */
			{ 3597,56,1}, /* core7 return_Stack1 bit25 */
			{ 3599,56,1}, /* core7 return_Stack1 bit26 */
			{ 3598,56,1}, /* core7 return_Stack1 bit27 */
			{ 3603,56,1}, /* core7 return_Stack1 bit28 */
			{ 3669,56,1}, /* core7 return_Stack1 bit29 */
			{ 3601,56,1}, /* core7 return_Stack1 bit30 */
			{ 3672,56,1}, /* core7 return_Stack1 bit31 */
			{22851,56,1}, /* core7 return_Stack1 bit32 */
			{15138,57,0}, /* core7 return_Stack1 bit33 */
			{ 3676,56,1}, /* core7 return_Stack1 bit34 */
			{25568,54,0}, /* core7 return_Stack1 bit35 */
			{25569,54,0}, /* core7 return_Stack1 bit36 */
			{ 3673,56,1}, /* core7 return_Stack1 bit37 */
			{ 3670,56,1}, /* core7 return_Stack1 bit38 */
			{ 3675,56,1}, /* core7 return_Stack1 bit39 */
			{22857,56,1}, /* core7 return_Stack1 bit40 */
			{ 3671,56,1}, /* core7 return_Stack1 bit41 */
			{ 3674,56,1}, /* core7 return_Stack1 bit42 */
			{22856,56,1}, /* core7 return_Stack1 bit43 */
			{22855,56,1}, /* core7 return_Stack1 bit44 */
			{18779,52,0}, /* core7 return_Stack1 bit45 */
			{22854,56,1}, /* core7 return_Stack1 bit46 */
			{22853,56,1}, /* core7 return_Stack1 bit47 */
			{22852,56,1}, /* core7 return_Stack1 bit48 */
			{    0, 0,2}, /* core7 return_Stack1 bit49 */
			{    0, 0,2}, /* core7 return_Stack1 bit50 */
			{    0, 0,2}, /* core7 return_Stack1 bit51 */
			{    0, 0,2}, /* core7 return_Stack1 bit52 */
			{    0, 0,2}, /* core7 return_Stack1 bit53 */
			{    0, 0,2}, /* core7 return_Stack1 bit54 */
			{    0, 0,2}, /* core7 return_Stack1 bit55 */
			{    0, 0,2}, /* core7 return_Stack1 bit56 */
			{    0, 0,2}, /* core7 return_Stack1 bit57 */
			{    0, 0,2}, /* core7 return_Stack1 bit58 */
			{    0, 0,2}, /* core7 return_Stack1 bit59 */
			{    0, 0,2}, /* core7 return_Stack1 bit60 */
			{    0, 0,2}, /* core7 return_Stack1 bit61 */
			{    0, 0,2}, /* core7 return_Stack1 bit62 */
			{    0, 0,2}, /* core7 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{22801,56,1}, /* core7 return_Stack2 bit0 */
			{15140,57,0}, /* core7 return_Stack2 bit1 */
			{ 3256,56,1}, /* core7 return_Stack2 bit2 */
			{ 3257,56,1}, /* core7 return_Stack2 bit3 */
			{15143,57,0}, /* core7 return_Stack2 bit4 */
			{ 3251,56,1}, /* core7 return_Stack2 bit5 */
			{15270,57,0}, /* core7 return_Stack2 bit6 */
			{ 3252,56,1}, /* core7 return_Stack2 bit7 */
			{ 3258,56,1}, /* core7 return_Stack2 bit8 */
			{ 3255,56,1}, /* core7 return_Stack2 bit9 */
			{15146,57,0}, /* core7 return_Stack2 bit10 */
			{ 3254,56,1}, /* core7 return_Stack2 bit11 */
			{22798,56,1}, /* core7 return_Stack2 bit12 */
			{22797,56,1}, /* core7 return_Stack2 bit13 */
			{ 3253,56,1}, /* core7 return_Stack2 bit14 */
			{15196,57,0}, /* core7 return_Stack2 bit15 */
			{15197,57,0}, /* core7 return_Stack2 bit16 */
			{15145,57,0}, /* core7 return_Stack2 bit17 */
			{15141,57,0}, /* core7 return_Stack2 bit18 */
			{15147,57,0}, /* core7 return_Stack2 bit19 */
			{15144,57,0}, /* core7 return_Stack2 bit20 */
			{15142,57,0}, /* core7 return_Stack2 bit21 */
			{ 3694,56,1}, /* core7 return_Stack2 bit22 */
			{ 3720,56,1}, /* core7 return_Stack2 bit23 */
			{ 3700,56,1}, /* core7 return_Stack2 bit24 */
			{ 3693,56,1}, /* core7 return_Stack2 bit25 */
			{ 3697,56,1}, /* core7 return_Stack2 bit26 */
			{ 3696,56,1}, /* core7 return_Stack2 bit27 */
			{ 3698,56,1}, /* core7 return_Stack2 bit28 */
			{ 3699,56,1}, /* core7 return_Stack2 bit29 */
			{ 3695,56,1}, /* core7 return_Stack2 bit30 */
			{ 3717,56,1}, /* core7 return_Stack2 bit31 */
			{22800,56,1}, /* core7 return_Stack2 bit32 */
			{22799,56,1}, /* core7 return_Stack2 bit33 */
			{ 3724,56,1}, /* core7 return_Stack2 bit34 */
			{22872,56,1}, /* core7 return_Stack2 bit35 */
			{22875,56,1}, /* core7 return_Stack2 bit36 */
			{ 3723,56,1}, /* core7 return_Stack2 bit37 */
			{ 3718,56,1}, /* core7 return_Stack2 bit38 */
			{ 3721,56,1}, /* core7 return_Stack2 bit39 */
			{22874,56,1}, /* core7 return_Stack2 bit40 */
			{ 3719,56,1}, /* core7 return_Stack2 bit41 */
			{ 3722,56,1}, /* core7 return_Stack2 bit42 */
			{22876,56,1}, /* core7 return_Stack2 bit43 */
			{18716,57,0}, /* core7 return_Stack2 bit44 */
			{22873,56,1}, /* core7 return_Stack2 bit45 */
			{22877,56,1}, /* core7 return_Stack2 bit46 */
			{22803,56,1}, /* core7 return_Stack2 bit47 */
			{22802,56,1}, /* core7 return_Stack2 bit48 */
			{    0, 0,2}, /* core7 return_Stack2 bit49 */
			{    0, 0,2}, /* core7 return_Stack2 bit50 */
			{    0, 0,2}, /* core7 return_Stack2 bit51 */
			{    0, 0,2}, /* core7 return_Stack2 bit52 */
			{    0, 0,2}, /* core7 return_Stack2 bit53 */
			{    0, 0,2}, /* core7 return_Stack2 bit54 */
			{    0, 0,2}, /* core7 return_Stack2 bit55 */
			{    0, 0,2}, /* core7 return_Stack2 bit56 */
			{    0, 0,2}, /* core7 return_Stack2 bit57 */
			{    0, 0,2}, /* core7 return_Stack2 bit58 */
			{    0, 0,2}, /* core7 return_Stack2 bit59 */
			{    0, 0,2}, /* core7 return_Stack2 bit60 */
			{    0, 0,2}, /* core7 return_Stack2 bit61 */
			{    0, 0,2}, /* core7 return_Stack2 bit62 */
			{    0, 0,2}, /* core7 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{22772,56,1}, /* core7 return_Stack3 bit0 */
			{15188,57,0}, /* core7 return_Stack3 bit1 */
			{15231,57,0}, /* core7 return_Stack3 bit2 */
			{15235,57,0}, /* core7 return_Stack3 bit3 */
			{15189,57,0}, /* core7 return_Stack3 bit4 */
			{15237,57,0}, /* core7 return_Stack3 bit5 */
			{15272,57,0}, /* core7 return_Stack3 bit6 */
			{15271,57,0}, /* core7 return_Stack3 bit7 */
			{15232,57,0}, /* core7 return_Stack3 bit8 */
			{ 4331,56,1}, /* core7 return_Stack3 bit9 */
			{15195,57,0}, /* core7 return_Stack3 bit10 */
			{15238,57,0}, /* core7 return_Stack3 bit11 */
			{15066,57,0}, /* core7 return_Stack3 bit12 */
			{15064,57,0}, /* core7 return_Stack3 bit13 */
			{15236,57,0}, /* core7 return_Stack3 bit14 */
			{15233,57,0}, /* core7 return_Stack3 bit15 */
			{15234,57,0}, /* core7 return_Stack3 bit16 */
			{15194,57,0}, /* core7 return_Stack3 bit17 */
			{15190,57,0}, /* core7 return_Stack3 bit18 */
			{15191,57,0}, /* core7 return_Stack3 bit19 */
			{15193,57,0}, /* core7 return_Stack3 bit20 */
			{15192,57,0}, /* core7 return_Stack3 bit21 */
			{25558,54,0}, /* core7 return_Stack3 bit22 */
			{25573,54,0}, /* core7 return_Stack3 bit23 */
			{25560,54,0}, /* core7 return_Stack3 bit24 */
			{25553,54,0}, /* core7 return_Stack3 bit25 */
			{25557,54,0}, /* core7 return_Stack3 bit26 */
			{25555,54,0}, /* core7 return_Stack3 bit27 */
			{25559,54,0}, /* core7 return_Stack3 bit28 */
			{25556,54,0}, /* core7 return_Stack3 bit29 */
			{25554,54,0}, /* core7 return_Stack3 bit30 */
			{ 3701,56,1}, /* core7 return_Stack3 bit31 */
			{22776,56,1}, /* core7 return_Stack3 bit32 */
			{15065,57,0}, /* core7 return_Stack3 bit33 */
			{25570,54,0}, /* core7 return_Stack3 bit34 */
			{22778,56,1}, /* core7 return_Stack3 bit35 */
			{ 3708,56,1}, /* core7 return_Stack3 bit36 */
			{ 3705,56,1}, /* core7 return_Stack3 bit37 */
			{ 3706,56,1}, /* core7 return_Stack3 bit38 */
			{ 3702,56,1}, /* core7 return_Stack3 bit39 */
			{25571,54,0}, /* core7 return_Stack3 bit40 */
			{ 3703,56,1}, /* core7 return_Stack3 bit41 */
			{ 3704,56,1}, /* core7 return_Stack3 bit42 */
			{22779,56,1}, /* core7 return_Stack3 bit43 */
			{22777,56,1}, /* core7 return_Stack3 bit44 */
			{ 3707,56,1}, /* core7 return_Stack3 bit45 */
			{22774,56,1}, /* core7 return_Stack3 bit46 */
			{22775,56,1}, /* core7 return_Stack3 bit47 */
			{22773,56,1}, /* core7 return_Stack3 bit48 */
			{    0, 0,2}, /* core7 return_Stack3 bit49 */
			{    0, 0,2}, /* core7 return_Stack3 bit50 */
			{    0, 0,2}, /* core7 return_Stack3 bit51 */
			{    0, 0,2}, /* core7 return_Stack3 bit52 */
			{    0, 0,2}, /* core7 return_Stack3 bit53 */
			{    0, 0,2}, /* core7 return_Stack3 bit54 */
			{    0, 0,2}, /* core7 return_Stack3 bit55 */
			{    0, 0,2}, /* core7 return_Stack3 bit56 */
			{    0, 0,2}, /* core7 return_Stack3 bit57 */
			{    0, 0,2}, /* core7 return_Stack3 bit58 */
			{    0, 0,2}, /* core7 return_Stack3 bit59 */
			{    0, 0,2}, /* core7 return_Stack3 bit60 */
			{    0, 0,2}, /* core7 return_Stack3 bit61 */
			{    0, 0,2}, /* core7 return_Stack3 bit62 */
			{    0, 0,2}, /* core7 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{22780,56,1}, /* core7 return_Stack4 bit0 */
			{15148,57,0}, /* core7 return_Stack4 bit1 */
			{15206,57,0}, /* core7 return_Stack4 bit2 */
			{15207,57,0}, /* core7 return_Stack4 bit3 */
			{15151,57,0}, /* core7 return_Stack4 bit4 */
			{19459,57,0}, /* core7 return_Stack4 bit5 */
			{19462,57,0}, /* core7 return_Stack4 bit6 */
			{15208,57,0}, /* core7 return_Stack4 bit7 */
			{15209,57,0}, /* core7 return_Stack4 bit8 */
			{15210,57,0}, /* core7 return_Stack4 bit9 */
			{15212,57,0}, /* core7 return_Stack4 bit10 */
			{19461,57,0}, /* core7 return_Stack4 bit11 */
			{22783,56,1}, /* core7 return_Stack4 bit12 */
			{22784,56,1}, /* core7 return_Stack4 bit13 */
			{19460,57,0}, /* core7 return_Stack4 bit14 */
			{15211,57,0}, /* core7 return_Stack4 bit15 */
			{15213,57,0}, /* core7 return_Stack4 bit16 */
			{15153,57,0}, /* core7 return_Stack4 bit17 */
			{15149,57,0}, /* core7 return_Stack4 bit18 */
			{15154,57,0}, /* core7 return_Stack4 bit19 */
			{15155,57,0}, /* core7 return_Stack4 bit20 */
			{15152,57,0}, /* core7 return_Stack4 bit21 */
			{25577,54,0}, /* core7 return_Stack4 bit22 */
			{ 3713,56,1}, /* core7 return_Stack4 bit23 */
			{25581,54,0}, /* core7 return_Stack4 bit24 */
			{25574,54,0}, /* core7 return_Stack4 bit25 */
			{25579,54,0}, /* core7 return_Stack4 bit26 */
			{25575,54,0}, /* core7 return_Stack4 bit27 */
			{25580,54,0}, /* core7 return_Stack4 bit28 */
			{25578,54,0}, /* core7 return_Stack4 bit29 */
			{25576,54,0}, /* core7 return_Stack4 bit30 */
			{ 3709,56,1}, /* core7 return_Stack4 bit31 */
			{22781,56,1}, /* core7 return_Stack4 bit32 */
			{22782,56,1}, /* core7 return_Stack4 bit33 */
			{22866,56,1}, /* core7 return_Stack4 bit34 */
			{22868,56,1}, /* core7 return_Stack4 bit35 */
			{ 3716,56,1}, /* core7 return_Stack4 bit36 */
			{ 3712,56,1}, /* core7 return_Stack4 bit37 */
			{ 3710,56,1}, /* core7 return_Stack4 bit38 */
			{ 3711,56,1}, /* core7 return_Stack4 bit39 */
			{22869,56,1}, /* core7 return_Stack4 bit40 */
			{ 3715,56,1}, /* core7 return_Stack4 bit41 */
			{ 3714,56,1}, /* core7 return_Stack4 bit42 */
			{22870,56,1}, /* core7 return_Stack4 bit43 */
			{22871,56,1}, /* core7 return_Stack4 bit44 */
			{22867,56,1}, /* core7 return_Stack4 bit45 */
			{22787,56,1}, /* core7 return_Stack4 bit46 */
			{22786,56,1}, /* core7 return_Stack4 bit47 */
			{22785,56,1}, /* core7 return_Stack4 bit48 */
			{    0, 0,2}, /* core7 return_Stack4 bit49 */
			{    0, 0,2}, /* core7 return_Stack4 bit50 */
			{    0, 0,2}, /* core7 return_Stack4 bit51 */
			{    0, 0,2}, /* core7 return_Stack4 bit52 */
			{    0, 0,2}, /* core7 return_Stack4 bit53 */
			{    0, 0,2}, /* core7 return_Stack4 bit54 */
			{    0, 0,2}, /* core7 return_Stack4 bit55 */
			{    0, 0,2}, /* core7 return_Stack4 bit56 */
			{    0, 0,2}, /* core7 return_Stack4 bit57 */
			{    0, 0,2}, /* core7 return_Stack4 bit58 */
			{    0, 0,2}, /* core7 return_Stack4 bit59 */
			{    0, 0,2}, /* core7 return_Stack4 bit60 */
			{    0, 0,2}, /* core7 return_Stack4 bit61 */
			{    0, 0,2}, /* core7 return_Stack4 bit62 */
			{    0, 0,2}, /* core7 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{15051,57,0}, /* core7 return_Stack5 bit0 */
			{15172,57,0}, /* core7 return_Stack5 bit1 */
			{ 3259,56,1}, /* core7 return_Stack5 bit2 */
			{ 3261,56,1}, /* core7 return_Stack5 bit3 */
			{15047,57,0}, /* core7 return_Stack5 bit4 */
			{15273,57,0}, /* core7 return_Stack5 bit5 */
			{ 3266,56,1}, /* core7 return_Stack5 bit6 */
			{ 3263,56,1}, /* core7 return_Stack5 bit7 */
			{ 3262,56,1}, /* core7 return_Stack5 bit8 */
			{ 3265,56,1}, /* core7 return_Stack5 bit9 */
			{15176,57,0}, /* core7 return_Stack5 bit10 */
			{ 3264,56,1}, /* core7 return_Stack5 bit11 */
			{15049,57,0}, /* core7 return_Stack5 bit12 */
			{15050,57,0}, /* core7 return_Stack5 bit13 */
			{15274,57,0}, /* core7 return_Stack5 bit14 */
			{ 3260,56,1}, /* core7 return_Stack5 bit15 */
			{15179,57,0}, /* core7 return_Stack5 bit16 */
			{15173,57,0}, /* core7 return_Stack5 bit17 */
			{15174,57,0}, /* core7 return_Stack5 bit18 */
			{15178,57,0}, /* core7 return_Stack5 bit19 */
			{15177,57,0}, /* core7 return_Stack5 bit20 */
			{15175,57,0}, /* core7 return_Stack5 bit21 */
			{25546,54,0}, /* core7 return_Stack5 bit22 */
			{25552,54,0}, /* core7 return_Stack5 bit23 */
			{22884,56,1}, /* core7 return_Stack5 bit24 */
			{25545,54,0}, /* core7 return_Stack5 bit25 */
			{25547,54,0}, /* core7 return_Stack5 bit26 */
			{25550,54,0}, /* core7 return_Stack5 bit27 */
			{25548,54,0}, /* core7 return_Stack5 bit28 */
			{25551,54,0}, /* core7 return_Stack5 bit29 */
			{25549,54,0}, /* core7 return_Stack5 bit30 */
			{ 3733,56,1}, /* core7 return_Stack5 bit31 */
			{15053,57,0}, /* core7 return_Stack5 bit32 */
			{15052,57,0}, /* core7 return_Stack5 bit33 */
			{ 3739,56,1}, /* core7 return_Stack5 bit34 */
			{22878,56,1}, /* core7 return_Stack5 bit35 */
			{ 3738,56,1}, /* core7 return_Stack5 bit36 */
			{ 3734,56,1}, /* core7 return_Stack5 bit37 */
			{22885,56,1}, /* core7 return_Stack5 bit38 */
			{ 3737,56,1}, /* core7 return_Stack5 bit39 */
			{22881,56,1}, /* core7 return_Stack5 bit40 */
			{ 3736,56,1}, /* core7 return_Stack5 bit41 */
			{ 3735,56,1}, /* core7 return_Stack5 bit42 */
			{22879,56,1}, /* core7 return_Stack5 bit43 */
			{22880,56,1}, /* core7 return_Stack5 bit44 */
			{ 3740,56,1}, /* core7 return_Stack5 bit45 */
			{22883,56,1}, /* core7 return_Stack5 bit46 */
			{22882,56,1}, /* core7 return_Stack5 bit47 */
			{15054,57,0}, /* core7 return_Stack5 bit48 */
			{    0, 0,2}, /* core7 return_Stack5 bit49 */
			{    0, 0,2}, /* core7 return_Stack5 bit50 */
			{    0, 0,2}, /* core7 return_Stack5 bit51 */
			{    0, 0,2}, /* core7 return_Stack5 bit52 */
			{    0, 0,2}, /* core7 return_Stack5 bit53 */
			{    0, 0,2}, /* core7 return_Stack5 bit54 */
			{    0, 0,2}, /* core7 return_Stack5 bit55 */
			{    0, 0,2}, /* core7 return_Stack5 bit56 */
			{    0, 0,2}, /* core7 return_Stack5 bit57 */
			{    0, 0,2}, /* core7 return_Stack5 bit58 */
			{    0, 0,2}, /* core7 return_Stack5 bit59 */
			{    0, 0,2}, /* core7 return_Stack5 bit60 */
			{    0, 0,2}, /* core7 return_Stack5 bit61 */
			{    0, 0,2}, /* core7 return_Stack5 bit62 */
			{    0, 0,2}, /* core7 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{22858,56,1}, /* core7 return_Stack6 bit0 */
			{15156,57,0}, /* core7 return_Stack6 bit1 */
			{15214,57,0}, /* core7 return_Stack6 bit2 */
			{15217,57,0}, /* core7 return_Stack6 bit3 */
			{15157,57,0}, /* core7 return_Stack6 bit4 */
			{19455,57,0}, /* core7 return_Stack6 bit5 */
			{15220,57,0}, /* core7 return_Stack6 bit6 */
			{15221,57,0}, /* core7 return_Stack6 bit7 */
			{15215,57,0}, /* core7 return_Stack6 bit8 */
			{19456,57,0}, /* core7 return_Stack6 bit9 */
			{15219,57,0}, /* core7 return_Stack6 bit10 */
			{19457,57,0}, /* core7 return_Stack6 bit11 */
			{ 3741,56,1}, /* core7 return_Stack6 bit12 */
			{18719,57,0}, /* core7 return_Stack6 bit13 */
			{19458,57,0}, /* core7 return_Stack6 bit14 */
			{15216,57,0}, /* core7 return_Stack6 bit15 */
			{15218,57,0}, /* core7 return_Stack6 bit16 */
			{15161,57,0}, /* core7 return_Stack6 bit17 */
			{15158,57,0}, /* core7 return_Stack6 bit18 */
			{15162,57,0}, /* core7 return_Stack6 bit19 */
			{15163,57,0}, /* core7 return_Stack6 bit20 */
			{15160,57,0}, /* core7 return_Stack6 bit21 */
			{ 3592,56,1}, /* core7 return_Stack6 bit22 */
			{ 2556,56,1}, /* core7 return_Stack6 bit23 */
			{ 3595,56,1}, /* core7 return_Stack6 bit24 */
			{ 3589,56,1}, /* core7 return_Stack6 bit25 */
			{ 3590,56,1}, /* core7 return_Stack6 bit26 */
			{ 3593,56,1}, /* core7 return_Stack6 bit27 */
			{ 3596,56,1}, /* core7 return_Stack6 bit28 */
			{ 3594,56,1}, /* core7 return_Stack6 bit29 */
			{ 3591,56,1}, /* core7 return_Stack6 bit30 */
			{ 3747,56,1}, /* core7 return_Stack6 bit31 */
			{ 3743,56,1}, /* core7 return_Stack6 bit32 */
			{ 3742,56,1}, /* core7 return_Stack6 bit33 */
			{ 3748,56,1}, /* core7 return_Stack6 bit34 */
			{22864,56,1}, /* core7 return_Stack6 bit35 */
			{ 3745,56,1}, /* core7 return_Stack6 bit36 */
			{ 2558,56,1}, /* core7 return_Stack6 bit37 */
			{ 2557,56,1}, /* core7 return_Stack6 bit38 */
			{ 2559,56,1}, /* core7 return_Stack6 bit39 */
			{22863,56,1}, /* core7 return_Stack6 bit40 */
			{ 3746,56,1}, /* core7 return_Stack6 bit41 */
			{25572,54,0}, /* core7 return_Stack6 bit42 */
			{22865,56,1}, /* core7 return_Stack6 bit43 */
			{22861,56,1}, /* core7 return_Stack6 bit44 */
			{ 3744,56,1}, /* core7 return_Stack6 bit45 */
			{22860,56,1}, /* core7 return_Stack6 bit46 */
			{22862,56,1}, /* core7 return_Stack6 bit47 */
			{22859,56,1}, /* core7 return_Stack6 bit48 */
			{    0, 0,2}, /* core7 return_Stack6 bit49 */
			{    0, 0,2}, /* core7 return_Stack6 bit50 */
			{    0, 0,2}, /* core7 return_Stack6 bit51 */
			{    0, 0,2}, /* core7 return_Stack6 bit52 */
			{    0, 0,2}, /* core7 return_Stack6 bit53 */
			{    0, 0,2}, /* core7 return_Stack6 bit54 */
			{    0, 0,2}, /* core7 return_Stack6 bit55 */
			{    0, 0,2}, /* core7 return_Stack6 bit56 */
			{    0, 0,2}, /* core7 return_Stack6 bit57 */
			{    0, 0,2}, /* core7 return_Stack6 bit58 */
			{    0, 0,2}, /* core7 return_Stack6 bit59 */
			{    0, 0,2}, /* core7 return_Stack6 bit60 */
			{    0, 0,2}, /* core7 return_Stack6 bit61 */
			{    0, 0,2}, /* core7 return_Stack6 bit62 */
			{    0, 0,2}, /* core7 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{22842,56,1}, /* core7 return_Stack7 bit0 */
			{15055,57,0}, /* core7 return_Stack7 bit1 */
			{15198,57,0}, /* core7 return_Stack7 bit2 */
			{15199,57,0}, /* core7 return_Stack7 bit3 */
			{15056,57,0}, /* core7 return_Stack7 bit4 */
			{21470,56,1}, /* core7 return_Stack7 bit5 */
			{21474,56,1}, /* core7 return_Stack7 bit6 */
			{21475,56,1}, /* core7 return_Stack7 bit7 */
			{15200,57,0}, /* core7 return_Stack7 bit8 */
			{21473,56,1}, /* core7 return_Stack7 bit9 */
			{15021,57,0}, /* core7 return_Stack7 bit10 */
			{21472,56,1}, /* core7 return_Stack7 bit11 */
			{15060,57,0}, /* core7 return_Stack7 bit12 */
			{15057,57,0}, /* core7 return_Stack7 bit13 */
			{21471,56,1}, /* core7 return_Stack7 bit14 */
			{15202,57,0}, /* core7 return_Stack7 bit15 */
			{15201,57,0}, /* core7 return_Stack7 bit16 */
			{15061,57,0}, /* core7 return_Stack7 bit17 */
			{15062,57,0}, /* core7 return_Stack7 bit18 */
			{15204,57,0}, /* core7 return_Stack7 bit19 */
			{15203,57,0}, /* core7 return_Stack7 bit20 */
			{15205,57,0}, /* core7 return_Stack7 bit21 */
			{ 3688,56,1}, /* core7 return_Stack7 bit22 */
			{ 3692,56,1}, /* core7 return_Stack7 bit23 */
			{ 3665,56,1}, /* core7 return_Stack7 bit24 */
			{ 3685,56,1}, /* core7 return_Stack7 bit25 */
			{ 3687,56,1}, /* core7 return_Stack7 bit26 */
			{ 3686,56,1}, /* core7 return_Stack7 bit27 */
			{ 3691,56,1}, /* core7 return_Stack7 bit28 */
			{ 3690,56,1}, /* core7 return_Stack7 bit29 */
			{ 3689,56,1}, /* core7 return_Stack7 bit30 */
			{ 3661,56,1}, /* core7 return_Stack7 bit31 */
			{22843,56,1}, /* core7 return_Stack7 bit32 */
			{15059,57,0}, /* core7 return_Stack7 bit33 */
			{ 3668,56,1}, /* core7 return_Stack7 bit34 */
			{13280,58,0}, /* core7 return_Stack7 bit35 */
			{25567,54,0}, /* core7 return_Stack7 bit36 */
			{ 3663,56,1}, /* core7 return_Stack7 bit37 */
			{ 3664,56,1}, /* core7 return_Stack7 bit38 */
			{ 3667,56,1}, /* core7 return_Stack7 bit39 */
			{22849,56,1}, /* core7 return_Stack7 bit40 */
			{ 3662,56,1}, /* core7 return_Stack7 bit41 */
			{ 3666,56,1}, /* core7 return_Stack7 bit42 */
			{22848,56,1}, /* core7 return_Stack7 bit43 */
			{22847,56,1}, /* core7 return_Stack7 bit44 */
			{13281,58,0}, /* core7 return_Stack7 bit45 */
			{22846,56,1}, /* core7 return_Stack7 bit46 */
			{22845,56,1}, /* core7 return_Stack7 bit47 */
			{22844,56,1}, /* core7 return_Stack7 bit48 */
			{    0, 0,2}, /* core7 return_Stack7 bit49 */
			{    0, 0,2}, /* core7 return_Stack7 bit50 */
			{    0, 0,2}, /* core7 return_Stack7 bit51 */
			{    0, 0,2}, /* core7 return_Stack7 bit52 */
			{    0, 0,2}, /* core7 return_Stack7 bit53 */
			{    0, 0,2}, /* core7 return_Stack7 bit54 */
			{    0, 0,2}, /* core7 return_Stack7 bit55 */
			{    0, 0,2}, /* core7 return_Stack7 bit56 */
			{    0, 0,2}, /* core7 return_Stack7 bit57 */
			{    0, 0,2}, /* core7 return_Stack7 bit58 */
			{    0, 0,2}, /* core7 return_Stack7 bit59 */
			{    0, 0,2}, /* core7 return_Stack7 bit60 */
			{    0, 0,2}, /* core7 return_Stack7 bit61 */
			{    0, 0,2}, /* core7 return_Stack7 bit62 */
			{    0, 0,2}, /* core7 return_Stack7 bit63 */
			}},
			.L2_parity_err_count = {{
			{ 6837, 8,0}, /* core7 L2_parity_err_count bit0 */
			{ 6836, 8,0}, /* core7 L2_parity_err_count bit1 */
			{ 6835, 8,0}, /* core7 L2_parity_err_count bit2 */
			{ 6834, 8,0}, /* core7 L2_parity_err_count bit3 */
			{ 6833, 8,0}, /* core7 L2_parity_err_count bit4 */
			{ 6832, 8,0}, /* core7 L2_parity_err_count bit5 */
			{ 6831, 8,0}, /* core7 L2_parity_err_count bit6 */
			{ 6830, 8,0}, /* core7 L2_parity_err_count bit7 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit8 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit9 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit10 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit11 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit12 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit13 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit14 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit15 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit16 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit17 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit18 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit19 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit20 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit21 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit22 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit23 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit24 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit25 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit26 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit27 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit28 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit29 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit30 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit31 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit32 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit33 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit34 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit35 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit36 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit37 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit38 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit39 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit40 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit41 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit42 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit43 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit44 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit45 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit46 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit47 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit48 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit49 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit50 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit51 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit52 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit53 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit54 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit55 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit56 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit57 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit58 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit59 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit60 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit61 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit62 */
			{    0, 0,2}, /* core7 L2_parity_err_count bit63 */
			}},
			.L2_parity_index = {{
			{ 6620, 8,0}, /* core7 L2_parity_index bit0 */
			{ 6619, 8,0}, /* core7 L2_parity_index bit1 */
			{ 6618, 8,0}, /* core7 L2_parity_index bit2 */
			{ 6617, 8,0}, /* core7 L2_parity_index bit3 */
			{ 6616, 8,0}, /* core7 L2_parity_index bit4 */
			{ 6615, 8,0}, /* core7 L2_parity_index bit5 */
			{ 6614, 8,0}, /* core7 L2_parity_index bit6 */
			{ 6613, 8,0}, /* core7 L2_parity_index bit7 */
			{ 6612, 8,0}, /* core7 L2_parity_index bit8 */
			{ 6611, 8,0}, /* core7 L2_parity_index bit9 */
			{    0, 0,2}, /* core7 L2_parity_index bit10 */
			{    0, 0,2}, /* core7 L2_parity_index bit11 */
			{    0, 0,2}, /* core7 L2_parity_index bit12 */
			{    0, 0,2}, /* core7 L2_parity_index bit13 */
			{    0, 0,2}, /* core7 L2_parity_index bit14 */
			{    0, 0,2}, /* core7 L2_parity_index bit15 */
			{    0, 0,2}, /* core7 L2_parity_index bit16 */
			{    0, 0,2}, /* core7 L2_parity_index bit17 */
			{    0, 0,2}, /* core7 L2_parity_index bit18 */
			{    0, 0,2}, /* core7 L2_parity_index bit19 */
			{    0, 0,2}, /* core7 L2_parity_index bit20 */
			{    0, 0,2}, /* core7 L2_parity_index bit21 */
			{    0, 0,2}, /* core7 L2_parity_index bit22 */
			{    0, 0,2}, /* core7 L2_parity_index bit23 */
			{    0, 0,2}, /* core7 L2_parity_index bit24 */
			{    0, 0,2}, /* core7 L2_parity_index bit25 */
			{    0, 0,2}, /* core7 L2_parity_index bit26 */
			{    0, 0,2}, /* core7 L2_parity_index bit27 */
			{    0, 0,2}, /* core7 L2_parity_index bit28 */
			{    0, 0,2}, /* core7 L2_parity_index bit29 */
			{    0, 0,2}, /* core7 L2_parity_index bit30 */
			{    0, 0,2}, /* core7 L2_parity_index bit31 */
			{    0, 0,2}, /* core7 L2_parity_index bit32 */
			{    0, 0,2}, /* core7 L2_parity_index bit33 */
			{    0, 0,2}, /* core7 L2_parity_index bit34 */
			{    0, 0,2}, /* core7 L2_parity_index bit35 */
			{    0, 0,2}, /* core7 L2_parity_index bit36 */
			{    0, 0,2}, /* core7 L2_parity_index bit37 */
			{    0, 0,2}, /* core7 L2_parity_index bit38 */
			{    0, 0,2}, /* core7 L2_parity_index bit39 */
			{    0, 0,2}, /* core7 L2_parity_index bit40 */
			{    0, 0,2}, /* core7 L2_parity_index bit41 */
			{    0, 0,2}, /* core7 L2_parity_index bit42 */
			{    0, 0,2}, /* core7 L2_parity_index bit43 */
			{    0, 0,2}, /* core7 L2_parity_index bit44 */
			{    0, 0,2}, /* core7 L2_parity_index bit45 */
			{    0, 0,2}, /* core7 L2_parity_index bit46 */
			{    0, 0,2}, /* core7 L2_parity_index bit47 */
			{    0, 0,2}, /* core7 L2_parity_index bit48 */
			{    0, 0,2}, /* core7 L2_parity_index bit49 */
			{    0, 0,2}, /* core7 L2_parity_index bit50 */
			{    0, 0,2}, /* core7 L2_parity_index bit51 */
			{    0, 0,2}, /* core7 L2_parity_index bit52 */
			{    0, 0,2}, /* core7 L2_parity_index bit53 */
			{    0, 0,2}, /* core7 L2_parity_index bit54 */
			{    0, 0,2}, /* core7 L2_parity_index bit55 */
			{    0, 0,2}, /* core7 L2_parity_index bit56 */
			{    0, 0,2}, /* core7 L2_parity_index bit57 */
			{    0, 0,2}, /* core7 L2_parity_index bit58 */
			{    0, 0,2}, /* core7 L2_parity_index bit59 */
			{    0, 0,2}, /* core7 L2_parity_index bit60 */
			{    0, 0,2}, /* core7 L2_parity_index bit61 */
			{    0, 0,2}, /* core7 L2_parity_index bit62 */
			{    0, 0,2}, /* core7 L2_parity_index bit63 */
			}},
			.L2_parity_way = {{
			{ 6605, 8,0}, /* core7 L2_parity_way bit0 */
			{ 6511, 8,0}, /* core7 L2_parity_way bit1 */
			{ 6510, 8,0}, /* core7 L2_parity_way bit2 */
			{    0, 0,2}, /* core7 L2_parity_way bit3 */
			{    0, 0,2}, /* core7 L2_parity_way bit4 */
			{    0, 0,2}, /* core7 L2_parity_way bit5 */
			{    0, 0,2}, /* core7 L2_parity_way bit6 */
			{    0, 0,2}, /* core7 L2_parity_way bit7 */
			{    0, 0,2}, /* core7 L2_parity_way bit8 */
			{    0, 0,2}, /* core7 L2_parity_way bit9 */
			{    0, 0,2}, /* core7 L2_parity_way bit10 */
			{    0, 0,2}, /* core7 L2_parity_way bit11 */
			{    0, 0,2}, /* core7 L2_parity_way bit12 */
			{    0, 0,2}, /* core7 L2_parity_way bit13 */
			{    0, 0,2}, /* core7 L2_parity_way bit14 */
			{    0, 0,2}, /* core7 L2_parity_way bit15 */
			{    0, 0,2}, /* core7 L2_parity_way bit16 */
			{    0, 0,2}, /* core7 L2_parity_way bit17 */
			{    0, 0,2}, /* core7 L2_parity_way bit18 */
			{    0, 0,2}, /* core7 L2_parity_way bit19 */
			{    0, 0,2}, /* core7 L2_parity_way bit20 */
			{    0, 0,2}, /* core7 L2_parity_way bit21 */
			{    0, 0,2}, /* core7 L2_parity_way bit22 */
			{    0, 0,2}, /* core7 L2_parity_way bit23 */
			{    0, 0,2}, /* core7 L2_parity_way bit24 */
			{    0, 0,2}, /* core7 L2_parity_way bit25 */
			{    0, 0,2}, /* core7 L2_parity_way bit26 */
			{    0, 0,2}, /* core7 L2_parity_way bit27 */
			{    0, 0,2}, /* core7 L2_parity_way bit28 */
			{    0, 0,2}, /* core7 L2_parity_way bit29 */
			{    0, 0,2}, /* core7 L2_parity_way bit30 */
			{    0, 0,2}, /* core7 L2_parity_way bit31 */
			{    0, 0,2}, /* core7 L2_parity_way bit32 */
			{    0, 0,2}, /* core7 L2_parity_way bit33 */
			{    0, 0,2}, /* core7 L2_parity_way bit34 */
			{    0, 0,2}, /* core7 L2_parity_way bit35 */
			{    0, 0,2}, /* core7 L2_parity_way bit36 */
			{    0, 0,2}, /* core7 L2_parity_way bit37 */
			{    0, 0,2}, /* core7 L2_parity_way bit38 */
			{    0, 0,2}, /* core7 L2_parity_way bit39 */
			{    0, 0,2}, /* core7 L2_parity_way bit40 */
			{    0, 0,2}, /* core7 L2_parity_way bit41 */
			{    0, 0,2}, /* core7 L2_parity_way bit42 */
			{    0, 0,2}, /* core7 L2_parity_way bit43 */
			{    0, 0,2}, /* core7 L2_parity_way bit44 */
			{    0, 0,2}, /* core7 L2_parity_way bit45 */
			{    0, 0,2}, /* core7 L2_parity_way bit46 */
			{    0, 0,2}, /* core7 L2_parity_way bit47 */
			{    0, 0,2}, /* core7 L2_parity_way bit48 */
			{    0, 0,2}, /* core7 L2_parity_way bit49 */
			{    0, 0,2}, /* core7 L2_parity_way bit50 */
			{    0, 0,2}, /* core7 L2_parity_way bit51 */
			{    0, 0,2}, /* core7 L2_parity_way bit52 */
			{    0, 0,2}, /* core7 L2_parity_way bit53 */
			{    0, 0,2}, /* core7 L2_parity_way bit54 */
			{    0, 0,2}, /* core7 L2_parity_way bit55 */
			{    0, 0,2}, /* core7 L2_parity_way bit56 */
			{    0, 0,2}, /* core7 L2_parity_way bit57 */
			{    0, 0,2}, /* core7 L2_parity_way bit58 */
			{    0, 0,2}, /* core7 L2_parity_way bit59 */
			{    0, 0,2}, /* core7 L2_parity_way bit60 */
			{    0, 0,2}, /* core7 L2_parity_way bit61 */
			{    0, 0,2}, /* core7 L2_parity_way bit62 */
			{    0, 0,2}, /* core7 L2_parity_way bit63 */
			}},
			.L2_parity_banks = {{
			{ 6829, 8,0}, /* core7 L2_parity_banks bit0 */
			{ 6828, 8,0}, /* core7 L2_parity_banks bit1 */
			{ 6827, 8,0}, /* core7 L2_parity_banks bit2 */
			{ 6826, 8,0}, /* core7 L2_parity_banks bit3 */
			{ 6825, 8,0}, /* core7 L2_parity_banks bit4 */
			{ 6824, 8,0}, /* core7 L2_parity_banks bit5 */
			{ 6823, 8,0}, /* core7 L2_parity_banks bit6 */
			{ 6822, 8,0}, /* core7 L2_parity_banks bit7 */
			{    0, 0,2}, /* core7 L2_parity_banks bit8 */
			{    0, 0,2}, /* core7 L2_parity_banks bit9 */
			{    0, 0,2}, /* core7 L2_parity_banks bit10 */
			{    0, 0,2}, /* core7 L2_parity_banks bit11 */
			{    0, 0,2}, /* core7 L2_parity_banks bit12 */
			{    0, 0,2}, /* core7 L2_parity_banks bit13 */
			{    0, 0,2}, /* core7 L2_parity_banks bit14 */
			{    0, 0,2}, /* core7 L2_parity_banks bit15 */
			{    0, 0,2}, /* core7 L2_parity_banks bit16 */
			{    0, 0,2}, /* core7 L2_parity_banks bit17 */
			{    0, 0,2}, /* core7 L2_parity_banks bit18 */
			{    0, 0,2}, /* core7 L2_parity_banks bit19 */
			{    0, 0,2}, /* core7 L2_parity_banks bit20 */
			{    0, 0,2}, /* core7 L2_parity_banks bit21 */
			{    0, 0,2}, /* core7 L2_parity_banks bit22 */
			{    0, 0,2}, /* core7 L2_parity_banks bit23 */
			{    0, 0,2}, /* core7 L2_parity_banks bit24 */
			{    0, 0,2}, /* core7 L2_parity_banks bit25 */
			{    0, 0,2}, /* core7 L2_parity_banks bit26 */
			{    0, 0,2}, /* core7 L2_parity_banks bit27 */
			{    0, 0,2}, /* core7 L2_parity_banks bit28 */
			{    0, 0,2}, /* core7 L2_parity_banks bit29 */
			{    0, 0,2}, /* core7 L2_parity_banks bit30 */
			{    0, 0,2}, /* core7 L2_parity_banks bit31 */
			{    0, 0,2}, /* core7 L2_parity_banks bit32 */
			{    0, 0,2}, /* core7 L2_parity_banks bit33 */
			{    0, 0,2}, /* core7 L2_parity_banks bit34 */
			{    0, 0,2}, /* core7 L2_parity_banks bit35 */
			{    0, 0,2}, /* core7 L2_parity_banks bit36 */
			{    0, 0,2}, /* core7 L2_parity_banks bit37 */
			{    0, 0,2}, /* core7 L2_parity_banks bit38 */
			{    0, 0,2}, /* core7 L2_parity_banks bit39 */
			{    0, 0,2}, /* core7 L2_parity_banks bit40 */
			{    0, 0,2}, /* core7 L2_parity_banks bit41 */
			{    0, 0,2}, /* core7 L2_parity_banks bit42 */
			{    0, 0,2}, /* core7 L2_parity_banks bit43 */
			{    0, 0,2}, /* core7 L2_parity_banks bit44 */
			{    0, 0,2}, /* core7 L2_parity_banks bit45 */
			{    0, 0,2}, /* core7 L2_parity_banks bit46 */
			{    0, 0,2}, /* core7 L2_parity_banks bit47 */
			{    0, 0,2}, /* core7 L2_parity_banks bit48 */
			{    0, 0,2}, /* core7 L2_parity_banks bit49 */
			{    0, 0,2}, /* core7 L2_parity_banks bit50 */
			{    0, 0,2}, /* core7 L2_parity_banks bit51 */
			{    0, 0,2}, /* core7 L2_parity_banks bit52 */
			{    0, 0,2}, /* core7 L2_parity_banks bit53 */
			{    0, 0,2}, /* core7 L2_parity_banks bit54 */
			{    0, 0,2}, /* core7 L2_parity_banks bit55 */
			{    0, 0,2}, /* core7 L2_parity_banks bit56 */
			{    0, 0,2}, /* core7 L2_parity_banks bit57 */
			{    0, 0,2}, /* core7 L2_parity_banks bit58 */
			{    0, 0,2}, /* core7 L2_parity_banks bit59 */
			{    0, 0,2}, /* core7 L2_parity_banks bit60 */
			{    0, 0,2}, /* core7 L2_parity_banks bit61 */
			{    0, 0,2}, /* core7 L2_parity_banks bit62 */
			{    0, 0,2}, /* core7 L2_parity_banks bit63 */
			}},
	},
}; 
