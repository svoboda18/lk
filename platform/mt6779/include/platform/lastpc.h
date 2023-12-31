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
			{ 4263,12,0}, /* core0 M0_AR_Pending_Counter bit0 */
			{ 4262,12,0}, /* core0 M0_AR_Pending_Counter bit1 */
			{ 4261,12,0}, /* core0 M0_AR_Pending_Counter bit2 */
			{ 4260,12,0}, /* core0 M0_AR_Pending_Counter bit3 */
			{ 6645,15,0}, /* core0 M0_AR_Pending_Counter bit4 */
			{ 6644,15,0}, /* core0 M0_AR_Pending_Counter bit5 */
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
			{ 4251,12,0}, /* core0 M1_AR_Pending_Counter bit0 */
			{ 4250,12,0}, /* core0 M1_AR_Pending_Counter bit1 */
			{ 4249,12,0}, /* core0 M1_AR_Pending_Counter bit2 */
			{ 4248,12,0}, /* core0 M1_AR_Pending_Counter bit3 */
			{ 6547,15,0}, /* core0 M1_AR_Pending_Counter bit4 */
			{ 6546,15,0}, /* core0 M1_AR_Pending_Counter bit5 */
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
			{ 4247,12,0}, /* core0 M2_AR_Pending_Counter bit0 */
			{ 4246,12,0}, /* core0 M2_AR_Pending_Counter bit1 */
			{ 4245,12,0}, /* core0 M2_AR_Pending_Counter bit2 */
			{ 4244,12,0}, /* core0 M2_AR_Pending_Counter bit3 */
			{ 6549,15,0}, /* core0 M2_AR_Pending_Counter bit4 */
			{ 6548,15,0}, /* core0 M2_AR_Pending_Counter bit5 */
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
			{ 4267,12,0}, /* core0 M0_AW_Pending_Counter bit0 */
			{ 4266,12,0}, /* core0 M0_AW_Pending_Counter bit1 */
			{ 4265,12,0}, /* core0 M0_AW_Pending_Counter bit2 */
			{ 4264,12,0}, /* core0 M0_AW_Pending_Counter bit3 */
			{ 6647,15,0}, /* core0 M0_AW_Pending_Counter bit4 */
			{ 6646,15,0}, /* core0 M0_AW_Pending_Counter bit5 */
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
			{ 4255,12,0}, /* core0 M1_AR_Pending_Counter bit0 */
			{ 4254,12,0}, /* core0 M1_AR_Pending_Counter bit1 */
			{ 4253,12,0}, /* core0 M1_AR_Pending_Counter bit2 */
			{ 4252,12,0}, /* core0 M1_AR_Pending_Counter bit3 */
			{ 6545,15,0}, /* core0 M1_AR_Pending_Counter bit4 */
			{ 6544,15,0}, /* core0 M1_AR_Pending_Counter bit5 */
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
			{ 4259,12,0}, /* core0 M2_AW_Pending_Counter bit0 */
			{ 4258,12,0}, /* core0 M2_AW_Pending_Counter bit1 */
			{ 4257,12,0}, /* core0 M2_AW_Pending_Counter bit2 */
			{ 4256,12,0}, /* core0 M2_AW_Pending_Counter bit3 */
			{ 6643,15,0}, /* core0 M2_AW_Pending_Counter bit4 */
			{ 6642,15,0}, /* core0 M2_AW_Pending_Counter bit5 */
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
			{ 4728,15,0}, /* core0 S4_AR_Pending_Counter bit0 */
			{ 4721,15,0}, /* core0 S4_AR_Pending_Counter bit1 */
			{ 4722,15,0}, /* core0 S4_AR_Pending_Counter bit2 */
			{ 4723,15,0}, /* core0 S4_AR_Pending_Counter bit3 */
			{ 4724,15,0}, /* core0 S4_AR_Pending_Counter bit4 */
			{ 4725,15,0}, /* core0 S4_AR_Pending_Counter bit5 */
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
			{ 4731,15,0}, /* core0 S4_AW_Pending_Counter bit0 */
			{ 4756,15,0}, /* core0 S4_AW_Pending_Counter bit1 */
			{ 4755,15,0}, /* core0 S4_AW_Pending_Counter bit2 */
			{ 4754,15,0}, /* core0 S4_AW_Pending_Counter bit3 */
			{ 4757,15,0}, /* core0 S4_AW_Pending_Counter bit4 */
			{ 4758,15,0}, /* core0 S4_AW_Pending_Counter bit5 */
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
			{ 4735,15,0}, /* core0 S3_AR_Pending_Counter bit0 */
			{ 4732,15,0}, /* core0 S3_AR_Pending_Counter bit1 */
			{ 4720,15,0}, /* core0 S3_AR_Pending_Counter bit2 */
			{ 4719,15,0}, /* core0 S3_AR_Pending_Counter bit3 */
			{ 4718,15,0}, /* core0 S3_AR_Pending_Counter bit4 */
			{ 4717,15,0}, /* core0 S3_AR_Pending_Counter bit5 */
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
			{ 4747,15,0}, /* core0 S3_AW_Pending_Counter bit0 */
			{ 4748,15,0}, /* core0 S3_AW_Pending_Counter bit1 */
			{ 4753,15,0}, /* core0 S3_AW_Pending_Counter bit2 */
			{ 4745,15,0}, /* core0 S3_AW_Pending_Counter bit3 */
			{ 4743,15,0}, /* core0 S3_AW_Pending_Counter bit4 */
			{ 4746,15,0}, /* core0 S3_AW_Pending_Counter bit5 */
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
			{  807, 5,0}, /* core0 mp0_L3_parity_err bit0 */
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
			{ 1587, 5,0}, /* core0 mp0_L3_parity_err_count bit0 */
			{ 1586, 5,0}, /* core0 mp0_L3_parity_err_count bit1 */
			{ 1585, 5,0}, /* core0 mp0_L3_parity_err_count bit2 */
			{ 1584, 5,0}, /* core0 mp0_L3_parity_err_count bit3 */
			{ 1599, 5,0}, /* core0 mp0_L3_parity_err_count bit4 */
			{ 1598, 5,0}, /* core0 mp0_L3_parity_err_count bit5 */
			{ 1597, 5,0}, /* core0 mp0_L3_parity_err_count bit6 */
			{ 1596, 5,0}, /* core0 mp0_L3_parity_err_count bit7 */
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
			{  806, 5,0}, /* core0 mp0_L3_parity_sap bit0 */
			{  956, 7,0}, /* core0 mp0_L3_parity_sap bit1 */
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
			{ 1247, 5,0}, /* core0 mp0_L3_parity_index bit0 */
			{ 1246, 5,0}, /* core0 mp0_L3_parity_index bit1 */
			{ 1245, 5,0}, /* core0 mp0_L3_parity_index bit2 */
			{ 1591, 5,0}, /* core0 mp0_L3_parity_index bit3 */
			{ 1590, 5,0}, /* core0 mp0_L3_parity_index bit4 */
			{ 1244, 5,0}, /* core0 mp0_L3_parity_index bit5 */
			{ 1589, 5,0}, /* core0 mp0_L3_parity_index bit6 */
			{ 1251, 5,0}, /* core0 mp0_L3_parity_index bit7 */
			{ 1250, 5,0}, /* core0 mp0_L3_parity_index bit8 */
			{ 1249, 5,0}, /* core0 mp0_L3_parity_index bit9 */
			{ 1248, 5,0}, /* core0 mp0_L3_parity_index bit10 */
			{ 1588, 5,0}, /* core0 mp0_L3_parity_index bit11 */
			{  805, 5,0}, /* core0 mp0_L3_parity_index bit12 */
			{  804, 5,0}, /* core0 mp0_L3_parity_index bit13 */
			{  955, 7,0}, /* core0 mp0_L3_parity_index bit14 */
			{  957, 7,0}, /* core0 mp0_L3_parity_index bit15 */
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
			{ 1255, 5,0}, /* core0 mp0_L3_parity_bank bit0 */
			{ 1595, 5,0}, /* core0 mp0_L3_parity_bank bit1 */
			{ 1594, 5,0}, /* core0 mp0_L3_parity_bank bit2 */
			{ 1593, 5,0}, /* core0 mp0_L3_parity_bank bit3 */
			{ 1254, 5,0}, /* core0 mp0_L3_parity_bank bit4 */
			{ 1253, 5,0}, /* core0 mp0_L3_parity_bank bit5 */
			{ 1592, 5,0}, /* core0 mp0_L3_parity_bank bit6 */
			{ 1252, 5,0}, /* core0 mp0_L3_parity_bank bit7 */
			{ 1603, 5,0}, /* core0 mp0_L3_parity_bank bit8 */
			{ 1602, 5,0}, /* core0 mp0_L3_parity_bank bit9 */
			{ 1601, 5,0}, /* core0 mp0_L3_parity_bank bit10 */
			{ 1600, 5,0}, /* core0 mp0_L3_parity_bank bit11 */
			{ 1243, 5,0}, /* core0 mp0_L3_parity_bank bit12 */
			{ 1242, 5,0}, /* core0 mp0_L3_parity_bank bit13 */
			{ 1241, 5,0}, /* core0 mp0_L3_parity_bank bit14 */
			{ 1240, 5,0}, /* core0 mp0_L3_parity_bank bit15 */
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
			.dfd_v35_enable = {{
			{ 1288, 4,0}, /* core0 dfd_v35_enable bit0 */
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
			{  192,33,0}, /* core0 pc bit0 */
			{  191,33,0}, /* core0 pc bit1 */
			{  190,33,0}, /* core0 pc bit2 */
			{  189,33,0}, /* core0 pc bit3 */
			{  142,33,0}, /* core0 pc bit4 */
			{  141,33,0}, /* core0 pc bit5 */
			{  140,33,0}, /* core0 pc bit6 */
			{  139,33,0}, /* core0 pc bit7 */
			{  146,33,0}, /* core0 pc bit8 */
			{  145,33,0}, /* core0 pc bit9 */
			{  144,33,0}, /* core0 pc bit10 */
			{  143,33,0}, /* core0 pc bit11 */
			{  150,33,0}, /* core0 pc bit12 */
			{  149,33,0}, /* core0 pc bit13 */
			{  148,33,0}, /* core0 pc bit14 */
			{  147,33,0}, /* core0 pc bit15 */
			{  126,33,0}, /* core0 pc bit16 */
			{  125,33,0}, /* core0 pc bit17 */
			{  124,33,0}, /* core0 pc bit18 */
			{  123,33,0}, /* core0 pc bit19 */
			{  134,33,0}, /* core0 pc bit20 */
			{  133,33,0}, /* core0 pc bit21 */
			{  132,33,0}, /* core0 pc bit22 */
			{  131,33,0}, /* core0 pc bit23 */
			{  138,33,0}, /* core0 pc bit24 */
			{  137,33,0}, /* core0 pc bit25 */
			{  136,33,0}, /* core0 pc bit26 */
			{  135,33,0}, /* core0 pc bit27 */
			{  130,33,0}, /* core0 pc bit28 */
			{  129,33,0}, /* core0 pc bit29 */
			{  128,33,0}, /* core0 pc bit30 */
			{  127,33,0}, /* core0 pc bit31 */
			{  240,33,0}, /* core0 pc bit32 */
			{  239,33,0}, /* core0 pc bit33 */
			{  238,33,0}, /* core0 pc bit34 */
			{  237,33,0}, /* core0 pc bit35 */
			{  248,33,0}, /* core0 pc bit36 */
			{  247,33,0}, /* core0 pc bit37 */
			{  246,33,0}, /* core0 pc bit38 */
			{  245,33,0}, /* core0 pc bit39 */
			{  244,33,0}, /* core0 pc bit40 */
			{  243,33,0}, /* core0 pc bit41 */
			{  242,33,0}, /* core0 pc bit42 */
			{  241,33,0}, /* core0 pc bit43 */
			{  216,33,0}, /* core0 pc bit44 */
			{  215,33,0}, /* core0 pc bit45 */
			{  214,33,0}, /* core0 pc bit46 */
			{  213,33,0}, /* core0 pc bit47 */
			{  180,33,0}, /* core0 pc bit48 */
			{  179,33,0}, /* core0 pc bit49 */
			{  178,33,0}, /* core0 pc bit50 */
			{  177,33,0}, /* core0 pc bit51 */
			{  184,33,0}, /* core0 pc bit52 */
			{  183,33,0}, /* core0 pc bit53 */
			{  182,33,0}, /* core0 pc bit54 */
			{  181,33,0}, /* core0 pc bit55 */
			{  236,33,0}, /* core0 pc bit56 */
			{  235,33,0}, /* core0 pc bit57 */
			{  234,33,0}, /* core0 pc bit58 */
			{  233,33,0}, /* core0 pc bit59 */
			{  188,33,0}, /* core0 pc bit60 */
			{  187,33,0}, /* core0 pc bit61 */
			{  186,33,0}, /* core0 pc bit62 */
			{  185,33,0}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{41807,34,0}, /* core0 sp32 bit0 */
			{41871,34,0}, /* core0 sp32 bit1 */
			{41806,34,0}, /* core0 sp32 bit2 */
			{41805,34,0}, /* core0 sp32 bit3 */
			{41804,34,0}, /* core0 sp32 bit4 */
			{41855,34,0}, /* core0 sp32 bit5 */
			{41854,34,0}, /* core0 sp32 bit6 */
			{41853,34,0}, /* core0 sp32 bit7 */
			{41852,34,0}, /* core0 sp32 bit8 */
			{41859,34,0}, /* core0 sp32 bit9 */
			{41858,34,0}, /* core0 sp32 bit10 */
			{41857,34,0}, /* core0 sp32 bit11 */
			{41856,34,0}, /* core0 sp32 bit12 */
			{41867,34,0}, /* core0 sp32 bit13 */
			{41866,34,0}, /* core0 sp32 bit14 */
			{41865,34,0}, /* core0 sp32 bit15 */
			{41864,34,0}, /* core0 sp32 bit16 */
			{41679,34,0}, /* core0 sp32 bit17 */
			{41678,34,0}, /* core0 sp32 bit18 */
			{41870,34,0}, /* core0 sp32 bit19 */
			{41677,34,0}, /* core0 sp32 bit20 */
			{41676,34,0}, /* core0 sp32 bit21 */
			{41671,34,0}, /* core0 sp32 bit22 */
			{41670,34,0}, /* core0 sp32 bit23 */
			{41669,34,0}, /* core0 sp32 bit24 */
			{41668,34,0}, /* core0 sp32 bit25 */
			{41869,34,0}, /* core0 sp32 bit26 */
			{41667,34,0}, /* core0 sp32 bit27 */
			{41666,34,0}, /* core0 sp32 bit28 */
			{41665,34,0}, /* core0 sp32 bit29 */
			{41664,34,0}, /* core0 sp32 bit30 */
			{41868,34,0}, /* core0 sp32 bit31 */
			{41483,34,0}, /* core0 sp32 bit32 */
			{41482,34,0}, /* core0 sp32 bit33 */
			{41481,34,0}, /* core0 sp32 bit34 */
			{41480,34,0}, /* core0 sp32 bit35 */
			{36299,34,0}, /* core0 sp32 bit36 */
			{28101,34,0}, /* core0 sp32 bit37 */
			{36298,34,0}, /* core0 sp32 bit38 */
			{41535,34,0}, /* core0 sp32 bit39 */
			{41534,34,0}, /* core0 sp32 bit40 */
			{41533,34,0}, /* core0 sp32 bit41 */
			{41532,34,0}, /* core0 sp32 bit42 */
			{41479,34,0}, /* core0 sp32 bit43 */
			{41478,34,0}, /* core0 sp32 bit44 */
			{41477,34,0}, /* core0 sp32 bit45 */
			{41476,34,0}, /* core0 sp32 bit46 */
			{36277,34,0}, /* core0 sp32 bit47 */
			{36276,34,0}, /* core0 sp32 bit48 */
			{41531,34,0}, /* core0 sp32 bit49 */
			{41530,34,0}, /* core0 sp32 bit50 */
			{41529,34,0}, /* core0 sp32 bit51 */
			{41528,34,0}, /* core0 sp32 bit52 */
			{41523,34,0}, /* core0 sp32 bit53 */
			{41522,34,0}, /* core0 sp32 bit54 */
			{41521,34,0}, /* core0 sp32 bit55 */
			{41520,34,0}, /* core0 sp32 bit56 */
			{41527,34,0}, /* core0 sp32 bit57 */
			{41526,34,0}, /* core0 sp32 bit58 */
			{41525,34,0}, /* core0 sp32 bit59 */
			{41524,34,0}, /* core0 sp32 bit60 */
			{41519,34,0}, /* core0 sp32 bit61 */
			{41518,34,0}, /* core0 sp32 bit62 */
			{41517,34,0}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{42038,34,0}, /* core0 fp32 bit0 */
			{42037,34,0}, /* core0 fp32 bit1 */
			{42021,34,0}, /* core0 fp32 bit2 */
			{42020,34,0}, /* core0 fp32 bit3 */
			{42036,34,0}, /* core0 fp32 bit4 */
			{42043,34,0}, /* core0 fp32 bit5 */
			{42042,34,0}, /* core0 fp32 bit6 */
			{42041,34,0}, /* core0 fp32 bit7 */
			{42040,34,0}, /* core0 fp32 bit8 */
			{42027,34,0}, /* core0 fp32 bit9 */
			{42031,34,0}, /* core0 fp32 bit10 */
			{42030,34,0}, /* core0 fp32 bit11 */
			{42029,34,0}, /* core0 fp32 bit12 */
			{42028,34,0}, /* core0 fp32 bit13 */
			{42015,34,0}, /* core0 fp32 bit14 */
			{42014,34,0}, /* core0 fp32 bit15 */
			{42026,34,0}, /* core0 fp32 bit16 */
			{42013,34,0}, /* core0 fp32 bit17 */
			{42035,34,0}, /* core0 fp32 bit18 */
			{42034,34,0}, /* core0 fp32 bit19 */
			{42033,34,0}, /* core0 fp32 bit20 */
			{42012,34,0}, /* core0 fp32 bit21 */
			{42019,34,0}, /* core0 fp32 bit22 */
			{42018,34,0}, /* core0 fp32 bit23 */
			{42017,34,0}, /* core0 fp32 bit24 */
			{42032,34,0}, /* core0 fp32 bit25 */
			{42016,34,0}, /* core0 fp32 bit26 */
			{42023,34,0}, /* core0 fp32 bit27 */
			{42025,34,0}, /* core0 fp32 bit28 */
			{42022,34,0}, /* core0 fp32 bit29 */
			{42024,34,0}, /* core0 fp32 bit30 */
			{42039,34,0}, /* core0 fp32 bit31 */
			{42143,34,0}, /* core0 fp32 bit32 */
			{42142,34,0}, /* core0 fp32 bit33 */
			{42141,34,0}, /* core0 fp32 bit34 */
			{42140,34,0}, /* core0 fp32 bit35 */
			{42135,34,0}, /* core0 fp32 bit36 */
			{42134,34,0}, /* core0 fp32 bit37 */
			{42133,34,0}, /* core0 fp32 bit38 */
			{42132,34,0}, /* core0 fp32 bit39 */
			{42131,34,0}, /* core0 fp32 bit40 */
			{42130,34,0}, /* core0 fp32 bit41 */
			{42129,34,0}, /* core0 fp32 bit42 */
			{42128,34,0}, /* core0 fp32 bit43 */
			{42139,34,0}, /* core0 fp32 bit44 */
			{42138,34,0}, /* core0 fp32 bit45 */
			{42137,34,0}, /* core0 fp32 bit46 */
			{42136,34,0}, /* core0 fp32 bit47 */
			{28149,34,0}, /* core0 fp32 bit48 */
			{42151,34,0}, /* core0 fp32 bit49 */
			{42150,34,0}, /* core0 fp32 bit50 */
			{42149,34,0}, /* core0 fp32 bit51 */
			{42148,34,0}, /* core0 fp32 bit52 */
			{42155,34,0}, /* core0 fp32 bit53 */
			{42154,34,0}, /* core0 fp32 bit54 */
			{42153,34,0}, /* core0 fp32 bit55 */
			{42152,34,0}, /* core0 fp32 bit56 */
			{42147,34,0}, /* core0 fp32 bit57 */
			{42146,34,0}, /* core0 fp32 bit58 */
			{42145,34,0}, /* core0 fp32 bit59 */
			{42144,34,0}, /* core0 fp32 bit60 */
			{42159,34,0}, /* core0 fp32 bit61 */
			{42158,34,0}, /* core0 fp32 bit62 */
			{42157,34,0}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{40979,34,0}, /* core0 fp64 bit0 */
			{40978,34,0}, /* core0 fp64 bit1 */
			{28248,34,0}, /* core0 fp64 bit2 */
			{40999,34,0}, /* core0 fp64 bit3 */
			{36342,34,0}, /* core0 fp64 bit4 */
			{40977,34,0}, /* core0 fp64 bit5 */
			{40970,34,0}, /* core0 fp64 bit6 */
			{40976,34,0}, /* core0 fp64 bit7 */
			{40969,34,0}, /* core0 fp64 bit8 */
			{40968,34,0}, /* core0 fp64 bit9 */
			{40975,34,0}, /* core0 fp64 bit10 */
			{40974,34,0}, /* core0 fp64 bit11 */
			{40987,34,0}, /* core0 fp64 bit12 */
			{40986,34,0}, /* core0 fp64 bit13 */
			{40985,34,0}, /* core0 fp64 bit14 */
			{40973,34,0}, /* core0 fp64 bit15 */
			{40998,34,0}, /* core0 fp64 bit16 */
			{40997,34,0}, /* core0 fp64 bit17 */
			{40996,34,0}, /* core0 fp64 bit18 */
			{36343,34,0}, /* core0 fp64 bit19 */
			{40995,34,0}, /* core0 fp64 bit20 */
			{40972,34,0}, /* core0 fp64 bit21 */
			{40984,34,0}, /* core0 fp64 bit22 */
			{40983,34,0}, /* core0 fp64 bit23 */
			{28249,34,0}, /* core0 fp64 bit24 */
			{40982,34,0}, /* core0 fp64 bit25 */
			{40994,34,0}, /* core0 fp64 bit26 */
			{40981,34,0}, /* core0 fp64 bit27 */
			{40993,34,0}, /* core0 fp64 bit28 */
			{40992,34,0}, /* core0 fp64 bit29 */
			{40980,34,0}, /* core0 fp64 bit30 */
			{40971,34,0}, /* core0 fp64 bit31 */
			{41143,34,0}, /* core0 fp64 bit32 */
			{41142,34,0}, /* core0 fp64 bit33 */
			{41141,34,0}, /* core0 fp64 bit34 */
			{28127,34,0}, /* core0 fp64 bit35 */
			{41140,34,0}, /* core0 fp64 bit36 */
			{36435,34,0}, /* core0 fp64 bit37 */
			{41151,34,0}, /* core0 fp64 bit38 */
			{41150,34,0}, /* core0 fp64 bit39 */
			{41149,34,0}, /* core0 fp64 bit40 */
			{41148,34,0}, /* core0 fp64 bit41 */
			{41147,34,0}, /* core0 fp64 bit42 */
			{41146,34,0}, /* core0 fp64 bit43 */
			{41145,34,0}, /* core0 fp64 bit44 */
			{28114,34,0}, /* core0 fp64 bit45 */
			{36434,34,0}, /* core0 fp64 bit46 */
			{41144,34,0}, /* core0 fp64 bit47 */
			{28132,34,0}, /* core0 fp64 bit48 */
			{36455,34,0}, /* core0 fp64 bit49 */
			{41119,34,0}, /* core0 fp64 bit50 */
			{41118,34,0}, /* core0 fp64 bit51 */
			{41117,34,0}, /* core0 fp64 bit52 */
			{36454,34,0}, /* core0 fp64 bit53 */
			{41116,34,0}, /* core0 fp64 bit54 */
			{41135,34,0}, /* core0 fp64 bit55 */
			{41134,34,0}, /* core0 fp64 bit56 */
			{41133,34,0}, /* core0 fp64 bit57 */
			{41132,34,0}, /* core0 fp64 bit58 */
			{28131,34,0}, /* core0 fp64 bit59 */
			{41115,34,0}, /* core0 fp64 bit60 */
			{41114,34,0}, /* core0 fp64 bit61 */
			{41113,34,0}, /* core0 fp64 bit62 */
			{41112,34,0}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40942,34,0}, /* core0 sp_EL0 bit0 */
			{40941,34,0}, /* core0 sp_EL0 bit1 */
			{40940,34,0}, /* core0 sp_EL0 bit2 */
			{41010,34,0}, /* core0 sp_EL0 bit3 */
			{41009,34,0}, /* core0 sp_EL0 bit4 */
			{40939,34,0}, /* core0 sp_EL0 bit5 */
			{40938,34,0}, /* core0 sp_EL0 bit6 */
			{40937,34,0}, /* core0 sp_EL0 bit7 */
			{40936,34,0}, /* core0 sp_EL0 bit8 */
			{40931,34,0}, /* core0 sp_EL0 bit9 */
			{40947,34,0}, /* core0 sp_EL0 bit10 */
			{40930,34,0}, /* core0 sp_EL0 bit11 */
			{40929,34,0}, /* core0 sp_EL0 bit12 */
			{40928,34,0}, /* core0 sp_EL0 bit13 */
			{40951,34,0}, /* core0 sp_EL0 bit14 */
			{40950,34,0}, /* core0 sp_EL0 bit15 */
			{41008,34,0}, /* core0 sp_EL0 bit16 */
			{41015,34,0}, /* core0 sp_EL0 bit17 */
			{41014,34,0}, /* core0 sp_EL0 bit18 */
			{41011,34,0}, /* core0 sp_EL0 bit19 */
			{41013,34,0}, /* core0 sp_EL0 bit20 */
			{40946,34,0}, /* core0 sp_EL0 bit21 */
			{40949,34,0}, /* core0 sp_EL0 bit22 */
			{40945,34,0}, /* core0 sp_EL0 bit23 */
			{28259,34,0}, /* core0 sp_EL0 bit24 */
			{40944,34,0}, /* core0 sp_EL0 bit25 */
			{41012,34,0}, /* core0 sp_EL0 bit26 */
			{36257,34,0}, /* core0 sp_EL0 bit27 */
			{36347,34,0}, /* core0 sp_EL0 bit28 */
			{36346,34,0}, /* core0 sp_EL0 bit29 */
			{36256,34,0}, /* core0 sp_EL0 bit30 */
			{40943,34,0}, /* core0 sp_EL0 bit31 */
			{41063,34,0}, /* core0 sp_EL0 bit32 */
			{41059,34,0}, /* core0 sp_EL0 bit33 */
			{41058,34,0}, /* core0 sp_EL0 bit34 */
			{41062,34,0}, /* core0 sp_EL0 bit35 */
			{41061,34,0}, /* core0 sp_EL0 bit36 */
			{41057,34,0}, /* core0 sp_EL0 bit37 */
			{41060,34,0}, /* core0 sp_EL0 bit38 */
			{41071,34,0}, /* core0 sp_EL0 bit39 */
			{41070,34,0}, /* core0 sp_EL0 bit40 */
			{41069,34,0}, /* core0 sp_EL0 bit41 */
			{41056,34,0}, /* core0 sp_EL0 bit42 */
			{41068,34,0}, /* core0 sp_EL0 bit43 */
			{41067,34,0}, /* core0 sp_EL0 bit44 */
			{41066,34,0}, /* core0 sp_EL0 bit45 */
			{41065,34,0}, /* core0 sp_EL0 bit46 */
			{41064,34,0}, /* core0 sp_EL0 bit47 */
			{28157,34,0}, /* core0 sp_EL0 bit48 */
			{41103,34,0}, /* core0 sp_EL0 bit49 */
			{41102,34,0}, /* core0 sp_EL0 bit50 */
			{41101,34,0}, /* core0 sp_EL0 bit51 */
			{41100,34,0}, /* core0 sp_EL0 bit52 */
			{41107,34,0}, /* core0 sp_EL0 bit53 */
			{41106,34,0}, /* core0 sp_EL0 bit54 */
			{41105,34,0}, /* core0 sp_EL0 bit55 */
			{41104,34,0}, /* core0 sp_EL0 bit56 */
			{41055,34,0}, /* core0 sp_EL0 bit57 */
			{41054,34,0}, /* core0 sp_EL0 bit58 */
			{41053,34,0}, /* core0 sp_EL0 bit59 */
			{41052,34,0}, /* core0 sp_EL0 bit60 */
			{41111,34,0}, /* core0 sp_EL0 bit61 */
			{41110,34,0}, /* core0 sp_EL0 bit62 */
			{41109,34,0}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40935,34,0}, /* core0 sp_EL1 bit0 */
			{40934,34,0}, /* core0 sp_EL1 bit1 */
			{40902,34,0}, /* core0 sp_EL1 bit2 */
			{40882,34,0}, /* core0 sp_EL1 bit3 */
			{40881,34,0}, /* core0 sp_EL1 bit4 */
			{40933,34,0}, /* core0 sp_EL1 bit5 */
			{40901,34,0}, /* core0 sp_EL1 bit6 */
			{40932,34,0}, /* core0 sp_EL1 bit7 */
			{40900,34,0}, /* core0 sp_EL1 bit8 */
			{40927,34,0}, /* core0 sp_EL1 bit9 */
			{40926,34,0}, /* core0 sp_EL1 bit10 */
			{40923,34,0}, /* core0 sp_EL1 bit11 */
			{40922,34,0}, /* core0 sp_EL1 bit12 */
			{40921,34,0}, /* core0 sp_EL1 bit13 */
			{40920,34,0}, /* core0 sp_EL1 bit14 */
			{40925,34,0}, /* core0 sp_EL1 bit15 */
			{40880,34,0}, /* core0 sp_EL1 bit16 */
			{40879,34,0}, /* core0 sp_EL1 bit17 */
			{40878,34,0}, /* core0 sp_EL1 bit18 */
			{36259,34,0}, /* core0 sp_EL1 bit19 */
			{40877,34,0}, /* core0 sp_EL1 bit20 */
			{40924,34,0}, /* core0 sp_EL1 bit21 */
			{28258,34,0}, /* core0 sp_EL1 bit22 */
			{40899,34,0}, /* core0 sp_EL1 bit23 */
			{36258,34,0}, /* core0 sp_EL1 bit24 */
			{40898,34,0}, /* core0 sp_EL1 bit25 */
			{40883,34,0}, /* core0 sp_EL1 bit26 */
			{40897,34,0}, /* core0 sp_EL1 bit27 */
			{40876,34,0}, /* core0 sp_EL1 bit28 */
			{28244,34,0}, /* core0 sp_EL1 bit29 */
			{40896,34,0}, /* core0 sp_EL1 bit30 */
			{40903,34,0}, /* core0 sp_EL1 bit31 */
			{40803,34,0}, /* core0 sp_EL1 bit32 */
			{40799,34,0}, /* core0 sp_EL1 bit33 */
			{40798,34,0}, /* core0 sp_EL1 bit34 */
			{40802,34,0}, /* core0 sp_EL1 bit35 */
			{40801,34,0}, /* core0 sp_EL1 bit36 */
			{40797,34,0}, /* core0 sp_EL1 bit37 */
			{40800,34,0}, /* core0 sp_EL1 bit38 */
			{40791,34,0}, /* core0 sp_EL1 bit39 */
			{40790,34,0}, /* core0 sp_EL1 bit40 */
			{40789,34,0}, /* core0 sp_EL1 bit41 */
			{40796,34,0}, /* core0 sp_EL1 bit42 */
			{40788,34,0}, /* core0 sp_EL1 bit43 */
			{40795,34,0}, /* core0 sp_EL1 bit44 */
			{40794,34,0}, /* core0 sp_EL1 bit45 */
			{40792,34,0}, /* core0 sp_EL1 bit46 */
			{40793,34,0}, /* core0 sp_EL1 bit47 */
			{28158,34,0}, /* core0 sp_EL1 bit48 */
			{36423,34,0}, /* core0 sp_EL1 bit49 */
			{40839,34,0}, /* core0 sp_EL1 bit50 */
			{40838,34,0}, /* core0 sp_EL1 bit51 */
			{40837,34,0}, /* core0 sp_EL1 bit52 */
			{36422,34,0}, /* core0 sp_EL1 bit53 */
			{40836,34,0}, /* core0 sp_EL1 bit54 */
			{40831,34,0}, /* core0 sp_EL1 bit55 */
			{40830,34,0}, /* core0 sp_EL1 bit56 */
			{40829,34,0}, /* core0 sp_EL1 bit57 */
			{40828,34,0}, /* core0 sp_EL1 bit58 */
			{28159,34,0}, /* core0 sp_EL1 bit59 */
			{40835,34,0}, /* core0 sp_EL1 bit60 */
			{40834,34,0}, /* core0 sp_EL1 bit61 */
			{40833,34,0}, /* core0 sp_EL1 bit62 */
			{40832,34,0}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40906,34,0}, /* core0 sp_EL2 bit0 */
			{40905,34,0}, /* core0 sp_EL2 bit1 */
			{40904,34,0}, /* core0 sp_EL2 bit2 */
			{40886,34,0}, /* core0 sp_EL2 bit3 */
			{40891,34,0}, /* core0 sp_EL2 bit4 */
			{40911,34,0}, /* core0 sp_EL2 bit5 */
			{40910,34,0}, /* core0 sp_EL2 bit6 */
			{40909,34,0}, /* core0 sp_EL2 bit7 */
			{40908,34,0}, /* core0 sp_EL2 bit8 */
			{40919,34,0}, /* core0 sp_EL2 bit9 */
			{40915,34,0}, /* core0 sp_EL2 bit10 */
			{40918,34,0}, /* core0 sp_EL2 bit11 */
			{40917,34,0}, /* core0 sp_EL2 bit12 */
			{40916,34,0}, /* core0 sp_EL2 bit13 */
			{40895,34,0}, /* core0 sp_EL2 bit14 */
			{40894,34,0}, /* core0 sp_EL2 bit15 */
			{40885,34,0}, /* core0 sp_EL2 bit16 */
			{40884,34,0}, /* core0 sp_EL2 bit17 */
			{40890,34,0}, /* core0 sp_EL2 bit18 */
			{28260,34,0}, /* core0 sp_EL2 bit19 */
			{40889,34,0}, /* core0 sp_EL2 bit20 */
			{40914,34,0}, /* core0 sp_EL2 bit21 */
			{40893,34,0}, /* core0 sp_EL2 bit22 */
			{40913,34,0}, /* core0 sp_EL2 bit23 */
			{40888,34,0}, /* core0 sp_EL2 bit24 */
			{40912,34,0}, /* core0 sp_EL2 bit25 */
			{40887,34,0}, /* core0 sp_EL2 bit26 */
			{36261,34,0}, /* core0 sp_EL2 bit27 */
			{36255,34,0}, /* core0 sp_EL2 bit28 */
			{36254,34,0}, /* core0 sp_EL2 bit29 */
			{36260,34,0}, /* core0 sp_EL2 bit30 */
			{40907,34,0}, /* core0 sp_EL2 bit31 */
			{40811,34,0}, /* core0 sp_EL2 bit32 */
			{40810,34,0}, /* core0 sp_EL2 bit33 */
			{40809,34,0}, /* core0 sp_EL2 bit34 */
			{40808,34,0}, /* core0 sp_EL2 bit35 */
			{40783,34,0}, /* core0 sp_EL2 bit36 */
			{40782,34,0}, /* core0 sp_EL2 bit37 */
			{40781,34,0}, /* core0 sp_EL2 bit38 */
			{40780,34,0}, /* core0 sp_EL2 bit39 */
			{40787,34,0}, /* core0 sp_EL2 bit40 */
			{40786,34,0}, /* core0 sp_EL2 bit41 */
			{40785,34,0}, /* core0 sp_EL2 bit42 */
			{40784,34,0}, /* core0 sp_EL2 bit43 */
			{40755,34,0}, /* core0 sp_EL2 bit44 */
			{40754,34,0}, /* core0 sp_EL2 bit45 */
			{40752,34,0}, /* core0 sp_EL2 bit46 */
			{40753,34,0}, /* core0 sp_EL2 bit47 */
			{28170,34,0}, /* core0 sp_EL2 bit48 */
			{28161,34,0}, /* core0 sp_EL2 bit49 */
			{40847,34,0}, /* core0 sp_EL2 bit50 */
			{40846,34,0}, /* core0 sp_EL2 bit51 */
			{40845,34,0}, /* core0 sp_EL2 bit52 */
			{40844,34,0}, /* core0 sp_EL2 bit53 */
			{40843,34,0}, /* core0 sp_EL2 bit54 */
			{40842,34,0}, /* core0 sp_EL2 bit55 */
			{40841,34,0}, /* core0 sp_EL2 bit56 */
			{40840,34,0}, /* core0 sp_EL2 bit57 */
			{40815,34,0}, /* core0 sp_EL2 bit58 */
			{40814,34,0}, /* core0 sp_EL2 bit59 */
			{40813,34,0}, /* core0 sp_EL2 bit60 */
			{40812,34,0}, /* core0 sp_EL2 bit61 */
			{36421,34,0}, /* core0 sp_EL2 bit62 */
			{36420,34,0}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40861,34,0}, /* core0 sp_EL3 bit0 */
			{40860,34,0}, /* core0 sp_EL3 bit1 */
			{40739,34,0}, /* core0 sp_EL3 bit2 */
			{40875,34,0}, /* core0 sp_EL3 bit3 */
			{40874,34,0}, /* core0 sp_EL3 bit4 */
			{40738,34,0}, /* core0 sp_EL3 bit5 */
			{40737,34,0}, /* core0 sp_EL3 bit6 */
			{40736,34,0}, /* core0 sp_EL3 bit7 */
			{40867,34,0}, /* core0 sp_EL3 bit8 */
			{40866,34,0}, /* core0 sp_EL3 bit9 */
			{40865,34,0}, /* core0 sp_EL3 bit10 */
			{40864,34,0}, /* core0 sp_EL3 bit11 */
			{40743,34,0}, /* core0 sp_EL3 bit12 */
			{40742,34,0}, /* core0 sp_EL3 bit13 */
			{40741,34,0}, /* core0 sp_EL3 bit14 */
			{40740,34,0}, /* core0 sp_EL3 bit15 */
			{40873,34,0}, /* core0 sp_EL3 bit16 */
			{40872,34,0}, /* core0 sp_EL3 bit17 */
			{40871,34,0}, /* core0 sp_EL3 bit18 */
			{40863,34,0}, /* core0 sp_EL3 bit19 */
			{40870,34,0}, /* core0 sp_EL3 bit20 */
			{40735,34,0}, /* core0 sp_EL3 bit21 */
			{40734,34,0}, /* core0 sp_EL3 bit22 */
			{40733,34,0}, /* core0 sp_EL3 bit23 */
			{28185,34,0}, /* core0 sp_EL3 bit24 */
			{40732,34,0}, /* core0 sp_EL3 bit25 */
			{40869,34,0}, /* core0 sp_EL3 bit26 */
			{36251,34,0}, /* core0 sp_EL3 bit27 */
			{40868,34,0}, /* core0 sp_EL3 bit28 */
			{28186,34,0}, /* core0 sp_EL3 bit29 */
			{36250,34,0}, /* core0 sp_EL3 bit30 */
			{40862,34,0}, /* core0 sp_EL3 bit31 */
			{40807,34,0}, /* core0 sp_EL3 bit32 */
			{40806,34,0}, /* core0 sp_EL3 bit33 */
			{40805,34,0}, /* core0 sp_EL3 bit34 */
			{40804,34,0}, /* core0 sp_EL3 bit35 */
			{40763,34,0}, /* core0 sp_EL3 bit36 */
			{40762,34,0}, /* core0 sp_EL3 bit37 */
			{40761,34,0}, /* core0 sp_EL3 bit38 */
			{40760,34,0}, /* core0 sp_EL3 bit39 */
			{40767,34,0}, /* core0 sp_EL3 bit40 */
			{40766,34,0}, /* core0 sp_EL3 bit41 */
			{40765,34,0}, /* core0 sp_EL3 bit42 */
			{40764,34,0}, /* core0 sp_EL3 bit43 */
			{40759,34,0}, /* core0 sp_EL3 bit44 */
			{40758,34,0}, /* core0 sp_EL3 bit45 */
			{40756,34,0}, /* core0 sp_EL3 bit46 */
			{40757,34,0}, /* core0 sp_EL3 bit47 */
			{28172,34,0}, /* core0 sp_EL3 bit48 */
			{36425,34,0}, /* core0 sp_EL3 bit49 */
			{40827,34,0}, /* core0 sp_EL3 bit50 */
			{40826,34,0}, /* core0 sp_EL3 bit51 */
			{40825,34,0}, /* core0 sp_EL3 bit52 */
			{40824,34,0}, /* core0 sp_EL3 bit53 */
			{40823,34,0}, /* core0 sp_EL3 bit54 */
			{40822,34,0}, /* core0 sp_EL3 bit55 */
			{40821,34,0}, /* core0 sp_EL3 bit56 */
			{40820,34,0}, /* core0 sp_EL3 bit57 */
			{40819,34,0}, /* core0 sp_EL3 bit58 */
			{36424,34,0}, /* core0 sp_EL3 bit59 */
			{40818,34,0}, /* core0 sp_EL3 bit60 */
			{40817,34,0}, /* core0 sp_EL3 bit61 */
			{40816,34,0}, /* core0 sp_EL3 bit62 */
			{28160,34,0}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{40707,34,0}, /* core0 elr_EL1 bit0 */
			{40706,34,0}, /* core0 elr_EL1 bit1 */
			{40705,34,0}, /* core0 elr_EL1 bit2 */
			{40723,34,0}, /* core0 elr_EL1 bit3 */
			{40722,34,0}, /* core0 elr_EL1 bit4 */
			{40704,34,0}, /* core0 elr_EL1 bit5 */
			{40703,34,0}, /* core0 elr_EL1 bit6 */
			{40702,34,0}, /* core0 elr_EL1 bit7 */
			{40701,34,0}, /* core0 elr_EL1 bit8 */
			{40700,34,0}, /* core0 elr_EL1 bit9 */
			{40695,34,0}, /* core0 elr_EL1 bit10 */
			{40694,34,0}, /* core0 elr_EL1 bit11 */
			{40693,34,0}, /* core0 elr_EL1 bit12 */
			{40692,34,0}, /* core0 elr_EL1 bit13 */
			{40699,34,0}, /* core0 elr_EL1 bit14 */
			{40698,34,0}, /* core0 elr_EL1 bit15 */
			{40721,34,0}, /* core0 elr_EL1 bit16 */
			{40720,34,0}, /* core0 elr_EL1 bit17 */
			{40727,34,0}, /* core0 elr_EL1 bit18 */
			{40697,34,0}, /* core0 elr_EL1 bit19 */
			{40726,34,0}, /* core0 elr_EL1 bit20 */
			{40696,34,0}, /* core0 elr_EL1 bit21 */
			{40715,34,0}, /* core0 elr_EL1 bit22 */
			{40714,34,0}, /* core0 elr_EL1 bit23 */
			{28252,34,0}, /* core0 elr_EL1 bit24 */
			{40713,34,0}, /* core0 elr_EL1 bit25 */
			{40725,34,0}, /* core0 elr_EL1 bit26 */
			{40712,34,0}, /* core0 elr_EL1 bit27 */
			{40724,34,0}, /* core0 elr_EL1 bit28 */
			{28251,34,0}, /* core0 elr_EL1 bit29 */
			{36265,34,0}, /* core0 elr_EL1 bit30 */
			{36264,34,0}, /* core0 elr_EL1 bit31 */
			{40751,34,0}, /* core0 elr_EL1 bit32 */
			{40750,34,0}, /* core0 elr_EL1 bit33 */
			{40749,34,0}, /* core0 elr_EL1 bit34 */
			{40748,34,0}, /* core0 elr_EL1 bit35 */
			{40771,34,0}, /* core0 elr_EL1 bit36 */
			{40770,34,0}, /* core0 elr_EL1 bit37 */
			{40769,34,0}, /* core0 elr_EL1 bit38 */
			{40768,34,0}, /* core0 elr_EL1 bit39 */
			{40775,34,0}, /* core0 elr_EL1 bit40 */
			{40774,34,0}, /* core0 elr_EL1 bit41 */
			{40773,34,0}, /* core0 elr_EL1 bit42 */
			{40772,34,0}, /* core0 elr_EL1 bit43 */
			{40779,34,0}, /* core0 elr_EL1 bit44 */
			{40778,34,0}, /* core0 elr_EL1 bit45 */
			{40777,34,0}, /* core0 elr_EL1 bit46 */
			{40776,34,0}, /* core0 elr_EL1 bit47 */
			{28165,34,0}, /* core0 elr_EL1 bit48 */
			{40859,34,0}, /* core0 elr_EL1 bit49 */
			{40858,34,0}, /* core0 elr_EL1 bit50 */
			{40857,34,0}, /* core0 elr_EL1 bit51 */
			{40856,34,0}, /* core0 elr_EL1 bit52 */
			{40855,34,0}, /* core0 elr_EL1 bit53 */
			{40854,34,0}, /* core0 elr_EL1 bit54 */
			{40853,34,0}, /* core0 elr_EL1 bit55 */
			{40852,34,0}, /* core0 elr_EL1 bit56 */
			{40747,34,0}, /* core0 elr_EL1 bit57 */
			{40746,34,0}, /* core0 elr_EL1 bit58 */
			{40745,34,0}, /* core0 elr_EL1 bit59 */
			{40744,34,0}, /* core0 elr_EL1 bit60 */
			{40851,34,0}, /* core0 elr_EL1 bit61 */
			{40850,34,0}, /* core0 elr_EL1 bit62 */
			{40849,34,0}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{40711,34,0}, /* core0 elr_EL2 bit0 */
			{40710,34,0}, /* core0 elr_EL2 bit1 */
			{40709,34,0}, /* core0 elr_EL2 bit2 */
			{40719,34,0}, /* core0 elr_EL2 bit3 */
			{40718,34,0}, /* core0 elr_EL2 bit4 */
			{40708,34,0}, /* core0 elr_EL2 bit5 */
			{40687,34,0}, /* core0 elr_EL2 bit6 */
			{40691,34,0}, /* core0 elr_EL2 bit7 */
			{40690,34,0}, /* core0 elr_EL2 bit8 */
			{40689,34,0}, /* core0 elr_EL2 bit9 */
			{40686,34,0}, /* core0 elr_EL2 bit10 */
			{40688,34,0}, /* core0 elr_EL2 bit11 */
			{40683,34,0}, /* core0 elr_EL2 bit12 */
			{40682,34,0}, /* core0 elr_EL2 bit13 */
			{40681,34,0}, /* core0 elr_EL2 bit14 */
			{40685,34,0}, /* core0 elr_EL2 bit15 */
			{40717,34,0}, /* core0 elr_EL2 bit16 */
			{40716,34,0}, /* core0 elr_EL2 bit17 */
			{40731,34,0}, /* core0 elr_EL2 bit18 */
			{40684,34,0}, /* core0 elr_EL2 bit19 */
			{40730,34,0}, /* core0 elr_EL2 bit20 */
			{40679,34,0}, /* core0 elr_EL2 bit21 */
			{40680,34,0}, /* core0 elr_EL2 bit22 */
			{40678,34,0}, /* core0 elr_EL2 bit23 */
			{28253,34,0}, /* core0 elr_EL2 bit24 */
			{40677,34,0}, /* core0 elr_EL2 bit25 */
			{40729,34,0}, /* core0 elr_EL2 bit26 */
			{40676,34,0}, /* core0 elr_EL2 bit27 */
			{40728,34,0}, /* core0 elr_EL2 bit28 */
			{28254,34,0}, /* core0 elr_EL2 bit29 */
			{28255,34,0}, /* core0 elr_EL2 bit30 */
			{28256,34,0}, /* core0 elr_EL2 bit31 */
			{40501,34,0}, /* core0 elr_EL2 bit32 */
			{40500,34,0}, /* core0 elr_EL2 bit33 */
			{40499,34,0}, /* core0 elr_EL2 bit34 */
			{40498,34,0}, /* core0 elr_EL2 bit35 */
			{40481,34,0}, /* core0 elr_EL2 bit36 */
			{40480,34,0}, /* core0 elr_EL2 bit37 */
			{40479,34,0}, /* core0 elr_EL2 bit38 */
			{40478,34,0}, /* core0 elr_EL2 bit39 */
			{40477,34,0}, /* core0 elr_EL2 bit40 */
			{40476,34,0}, /* core0 elr_EL2 bit41 */
			{40475,34,0}, /* core0 elr_EL2 bit42 */
			{40474,34,0}, /* core0 elr_EL2 bit43 */
			{40485,34,0}, /* core0 elr_EL2 bit44 */
			{40484,34,0}, /* core0 elr_EL2 bit45 */
			{40483,34,0}, /* core0 elr_EL2 bit46 */
			{40482,34,0}, /* core0 elr_EL2 bit47 */
			{28164,34,0}, /* core0 elr_EL2 bit48 */
			{40509,34,0}, /* core0 elr_EL2 bit49 */
			{40508,34,0}, /* core0 elr_EL2 bit50 */
			{40507,34,0}, /* core0 elr_EL2 bit51 */
			{40506,34,0}, /* core0 elr_EL2 bit52 */
			{40465,34,0}, /* core0 elr_EL2 bit53 */
			{40464,34,0}, /* core0 elr_EL2 bit54 */
			{40463,34,0}, /* core0 elr_EL2 bit55 */
			{40462,34,0}, /* core0 elr_EL2 bit56 */
			{40473,34,0}, /* core0 elr_EL2 bit57 */
			{40472,34,0}, /* core0 elr_EL2 bit58 */
			{40471,34,0}, /* core0 elr_EL2 bit59 */
			{40470,34,0}, /* core0 elr_EL2 bit60 */
			{40469,34,0}, /* core0 elr_EL2 bit61 */
			{40468,34,0}, /* core0 elr_EL2 bit62 */
			{40467,34,0}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{40452,34,0}, /* core0 elr_EL3 bit0 */
			{40451,34,0}, /* core0 elr_EL3 bit1 */
			{40450,34,0}, /* core0 elr_EL3 bit2 */
			{40437,34,0}, /* core0 elr_EL3 bit3 */
			{40436,34,0}, /* core0 elr_EL3 bit4 */
			{40441,34,0}, /* core0 elr_EL3 bit5 */
			{40440,34,0}, /* core0 elr_EL3 bit6 */
			{40439,34,0}, /* core0 elr_EL3 bit7 */
			{40438,34,0}, /* core0 elr_EL3 bit8 */
			{40449,34,0}, /* core0 elr_EL3 bit9 */
			{40448,34,0}, /* core0 elr_EL3 bit10 */
			{40447,34,0}, /* core0 elr_EL3 bit11 */
			{40446,34,0}, /* core0 elr_EL3 bit12 */
			{40457,34,0}, /* core0 elr_EL3 bit13 */
			{40456,34,0}, /* core0 elr_EL3 bit14 */
			{40455,34,0}, /* core0 elr_EL3 bit15 */
			{40435,34,0}, /* core0 elr_EL3 bit16 */
			{40434,34,0}, /* core0 elr_EL3 bit17 */
			{40461,34,0}, /* core0 elr_EL3 bit18 */
			{40445,34,0}, /* core0 elr_EL3 bit19 */
			{40460,34,0}, /* core0 elr_EL3 bit20 */
			{40444,34,0}, /* core0 elr_EL3 bit21 */
			{40454,34,0}, /* core0 elr_EL3 bit22 */
			{40443,34,0}, /* core0 elr_EL3 bit23 */
			{28245,34,0}, /* core0 elr_EL3 bit24 */
			{40442,34,0}, /* core0 elr_EL3 bit25 */
			{40459,34,0}, /* core0 elr_EL3 bit26 */
			{36263,34,0}, /* core0 elr_EL3 bit27 */
			{40458,34,0}, /* core0 elr_EL3 bit28 */
			{28246,34,0}, /* core0 elr_EL3 bit29 */
			{36262,34,0}, /* core0 elr_EL3 bit30 */
			{40453,34,0}, /* core0 elr_EL3 bit31 */
			{40505,34,0}, /* core0 elr_EL3 bit32 */
			{40504,34,0}, /* core0 elr_EL3 bit33 */
			{40503,34,0}, /* core0 elr_EL3 bit34 */
			{40493,34,0}, /* core0 elr_EL3 bit35 */
			{40492,34,0}, /* core0 elr_EL3 bit36 */
			{40502,34,0}, /* core0 elr_EL3 bit37 */
			{40491,34,0}, /* core0 elr_EL3 bit38 */
			{40490,34,0}, /* core0 elr_EL3 bit39 */
			{40489,34,0}, /* core0 elr_EL3 bit40 */
			{40488,34,0}, /* core0 elr_EL3 bit41 */
			{40497,34,0}, /* core0 elr_EL3 bit42 */
			{40487,34,0}, /* core0 elr_EL3 bit43 */
			{40496,34,0}, /* core0 elr_EL3 bit44 */
			{40495,34,0}, /* core0 elr_EL3 bit45 */
			{36215,34,0}, /* core0 elr_EL3 bit46 */
			{40494,34,0}, /* core0 elr_EL3 bit47 */
			{36214,34,0}, /* core0 elr_EL3 bit48 */
			{40517,34,0}, /* core0 elr_EL3 bit49 */
			{40516,34,0}, /* core0 elr_EL3 bit50 */
			{40515,34,0}, /* core0 elr_EL3 bit51 */
			{40514,34,0}, /* core0 elr_EL3 bit52 */
			{40521,34,0}, /* core0 elr_EL3 bit53 */
			{40520,34,0}, /* core0 elr_EL3 bit54 */
			{40519,34,0}, /* core0 elr_EL3 bit55 */
			{40518,34,0}, /* core0 elr_EL3 bit56 */
			{40513,34,0}, /* core0 elr_EL3 bit57 */
			{40512,34,0}, /* core0 elr_EL3 bit58 */
			{40511,34,0}, /* core0 elr_EL3 bit59 */
			{40510,34,0}, /* core0 elr_EL3 bit60 */
			{40433,34,0}, /* core0 elr_EL3 bit61 */
			{40432,34,0}, /* core0 elr_EL3 bit62 */
			{40431,34,0}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{30898,34,0}, /* core0 raw_pc bit0 */
			{33534,33,0}, /* core0 raw_pc bit1 */
			{33533,33,0}, /* core0 raw_pc bit2 */
			{33532,33,0}, /* core0 raw_pc bit3 */
			{33531,33,0}, /* core0 raw_pc bit4 */
			{37455,34,0}, /* core0 raw_pc bit5 */
			{37454,34,0}, /* core0 raw_pc bit6 */
			{37453,34,0}, /* core0 raw_pc bit7 */
			{37452,34,0}, /* core0 raw_pc bit8 */
			{37451,34,0}, /* core0 raw_pc bit9 */
			{37450,34,0}, /* core0 raw_pc bit10 */
			{37447,34,0}, /* core0 raw_pc bit11 */
			{37446,34,0}, /* core0 raw_pc bit12 */
			{37449,34,0}, /* core0 raw_pc bit13 */
			{37448,34,0}, /* core0 raw_pc bit14 */
			{33538,33,0}, /* core0 raw_pc bit15 */
			{33537,33,0}, /* core0 raw_pc bit16 */
			{33536,33,0}, /* core0 raw_pc bit17 */
			{33535,33,0}, /* core0 raw_pc bit18 */
			{33542,33,0}, /* core0 raw_pc bit19 */
			{33541,33,0}, /* core0 raw_pc bit20 */
			{33540,33,0}, /* core0 raw_pc bit21 */
			{33539,33,0}, /* core0 raw_pc bit22 */
			{33546,33,0}, /* core0 raw_pc bit23 */
			{33545,33,0}, /* core0 raw_pc bit24 */
			{33544,33,0}, /* core0 raw_pc bit25 */
			{33543,33,0}, /* core0 raw_pc bit26 */
			{33482,33,0}, /* core0 raw_pc bit27 */
			{33481,33,0}, /* core0 raw_pc bit28 */
			{33480,33,0}, /* core0 raw_pc bit29 */
			{33479,33,0}, /* core0 raw_pc bit30 */
			{33606,33,0}, /* core0 raw_pc bit31 */
			{33605,33,0}, /* core0 raw_pc bit32 */
			{33604,33,0}, /* core0 raw_pc bit33 */
			{33603,33,0}, /* core0 raw_pc bit34 */
			{37245,34,0}, /* core0 raw_pc bit35 */
			{37244,34,0}, /* core0 raw_pc bit36 */
			{37249,34,0}, /* core0 raw_pc bit37 */
			{37248,34,0}, /* core0 raw_pc bit38 */
			{33602,33,0}, /* core0 raw_pc bit39 */
			{33601,33,0}, /* core0 raw_pc bit40 */
			{33600,33,0}, /* core0 raw_pc bit41 */
			{33599,33,0}, /* core0 raw_pc bit42 */
			{37247,34,0}, /* core0 raw_pc bit43 */
			{37246,34,0}, /* core0 raw_pc bit44 */
			{37251,34,0}, /* core0 raw_pc bit45 */
			{37250,34,0}, /* core0 raw_pc bit46 */
			{33598,33,0}, /* core0 raw_pc bit47 */
			{33597,33,0}, /* core0 raw_pc bit48 */
			{33596,33,0}, /* core0 raw_pc bit49 */
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
			{33491,33,0}, /* core0 pc_iss bit0 */
			{33498,33,0}, /* core0 pc_iss bit1 */
			{33497,33,0}, /* core0 pc_iss bit2 */
			{33496,33,0}, /* core0 pc_iss bit3 */
			{33495,33,0}, /* core0 pc_iss bit4 */
			{33494,33,0}, /* core0 pc_iss bit5 */
			{33493,33,0}, /* core0 pc_iss bit6 */
			{33492,33,0}, /* core0 pc_iss bit7 */
			{33522,33,0}, /* core0 pc_iss bit8 */
			{33521,33,0}, /* core0 pc_iss bit9 */
			{33520,33,0}, /* core0 pc_iss bit10 */
			{33519,33,0}, /* core0 pc_iss bit11 */
			{33470,33,0}, /* core0 pc_iss bit12 */
			{33469,33,0}, /* core0 pc_iss bit13 */
			{33468,33,0}, /* core0 pc_iss bit14 */
			{33467,33,0}, /* core0 pc_iss bit15 */
			{33526,33,0}, /* core0 pc_iss bit16 */
			{33525,33,0}, /* core0 pc_iss bit17 */
			{33524,33,0}, /* core0 pc_iss bit18 */
			{33523,33,0}, /* core0 pc_iss bit19 */
			{33530,33,0}, /* core0 pc_iss bit20 */
			{33529,33,0}, /* core0 pc_iss bit21 */
			{33528,33,0}, /* core0 pc_iss bit22 */
			{33527,33,0}, /* core0 pc_iss bit23 */
			{33474,33,0}, /* core0 pc_iss bit24 */
			{33473,33,0}, /* core0 pc_iss bit25 */
			{33472,33,0}, /* core0 pc_iss bit26 */
			{33471,33,0}, /* core0 pc_iss bit27 */
			{33478,33,0}, /* core0 pc_iss bit28 */
			{33477,33,0}, /* core0 pc_iss bit29 */
			{33476,33,0}, /* core0 pc_iss bit30 */
			{33475,33,0}, /* core0 pc_iss bit31 */
			{33631,33,0}, /* core0 pc_iss bit32 */
			{33618,33,0}, /* core0 pc_iss bit33 */
			{33617,33,0}, /* core0 pc_iss bit34 */
			{33616,33,0}, /* core0 pc_iss bit35 */
			{33621,33,0}, /* core0 pc_iss bit36 */
			{33615,33,0}, /* core0 pc_iss bit37 */
			{33620,33,0}, /* core0 pc_iss bit38 */
			{33619,33,0}, /* core0 pc_iss bit39 */
			{33614,33,0}, /* core0 pc_iss bit40 */
			{33613,33,0}, /* core0 pc_iss bit41 */
			{33610,33,0}, /* core0 pc_iss bit42 */
			{33612,33,0}, /* core0 pc_iss bit43 */
			{33611,33,0}, /* core0 pc_iss bit44 */
			{33630,33,0}, /* core0 pc_iss bit45 */
			{33629,33,0}, /* core0 pc_iss bit46 */
			{33609,33,0}, /* core0 pc_iss bit47 */
			{33628,33,0}, /* core0 pc_iss bit48 */
			{33627,33,0}, /* core0 pc_iss bit49 */
			{33626,33,0}, /* core0 pc_iss bit50 */
			{33625,33,0}, /* core0 pc_iss bit51 */
			{33624,33,0}, /* core0 pc_iss bit52 */
			{33622,33,0}, /* core0 pc_iss bit53 */
			{33623,33,0}, /* core0 pc_iss bit54 */
			{33634,33,0}, /* core0 pc_iss bit55 */
			{33633,33,0}, /* core0 pc_iss bit56 */
			{33632,33,0}, /* core0 pc_iss bit57 */
			{33608,33,0}, /* core0 pc_iss bit58 */
			{33607,33,0}, /* core0 pc_iss bit59 */
			{33638,33,0}, /* core0 pc_iss bit60 */
			{33637,33,0}, /* core0 pc_iss bit61 */
			{33636,33,0}, /* core0 pc_iss bit62 */
			{33635,33,0}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{30897,34,0}, /* core0 full_pc_wr bit0 */
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
			{30971,34,0}, /* core0 full_pc_ex1 bit0 */
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
			{30942,34,0}, /* core0 full_pc_ex2 bit0 */
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
			{16598,34,0}, /* core0 return_Stack_pointer bit0 */
			{16597,34,0}, /* core0 return_Stack_pointer bit1 */
			{13720,34,0}, /* core0 return_Stack_pointer bit2 */
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
			{23469,34,0}, /* core0 return_Stack0 bit0 */
			{23468,34,0}, /* core0 return_Stack0 bit1 */
			{23467,34,0}, /* core0 return_Stack0 bit2 */
			{23449,34,0}, /* core0 return_Stack0 bit3 */
			{23448,34,0}, /* core0 return_Stack0 bit4 */
			{23447,34,0}, /* core0 return_Stack0 bit5 */
			{23446,34,0}, /* core0 return_Stack0 bit6 */
			{23365,34,0}, /* core0 return_Stack0 bit7 */
			{23364,34,0}, /* core0 return_Stack0 bit8 */
			{23363,34,0}, /* core0 return_Stack0 bit9 */
			{23466,34,0}, /* core0 return_Stack0 bit10 */
			{23417,34,0}, /* core0 return_Stack0 bit11 */
			{23416,34,0}, /* core0 return_Stack0 bit12 */
			{23415,34,0}, /* core0 return_Stack0 bit13 */
			{23414,34,0}, /* core0 return_Stack0 bit14 */
			{23369,34,0}, /* core0 return_Stack0 bit15 */
			{23368,34,0}, /* core0 return_Stack0 bit16 */
			{23367,34,0}, /* core0 return_Stack0 bit17 */
			{23366,34,0}, /* core0 return_Stack0 bit18 */
			{23421,34,0}, /* core0 return_Stack0 bit19 */
			{23420,34,0}, /* core0 return_Stack0 bit20 */
			{23419,34,0}, /* core0 return_Stack0 bit21 */
			{23418,34,0}, /* core0 return_Stack0 bit22 */
			{23465,34,1}, /* core0 return_Stack0 bit23 */
			{23464,34,1}, /* core0 return_Stack0 bit24 */
			{23463,34,1}, /* core0 return_Stack0 bit25 */
			{23462,34,1}, /* core0 return_Stack0 bit26 */
			{23385,34,1}, /* core0 return_Stack0 bit27 */
			{23384,34,1}, /* core0 return_Stack0 bit28 */
			{23383,34,1}, /* core0 return_Stack0 bit29 */
			{23382,34,1}, /* core0 return_Stack0 bit30 */
			{13706,34,0}, /* core0 return_Stack0 bit31 */
			{23381,34,0}, /* core0 return_Stack0 bit32 */
			{23380,34,0}, /* core0 return_Stack0 bit33 */
			{23379,34,0}, /* core0 return_Stack0 bit34 */
			{23378,34,0}, /* core0 return_Stack0 bit35 */
			{23413,34,1}, /* core0 return_Stack0 bit36 */
			{23412,34,1}, /* core0 return_Stack0 bit37 */
			{23411,34,1}, /* core0 return_Stack0 bit38 */
			{23410,34,1}, /* core0 return_Stack0 bit39 */
			{23405,34,0}, /* core0 return_Stack0 bit40 */
			{23404,34,0}, /* core0 return_Stack0 bit41 */
			{23403,34,0}, /* core0 return_Stack0 bit42 */
			{23402,34,0}, /* core0 return_Stack0 bit43 */
			{23409,34,1}, /* core0 return_Stack0 bit44 */
			{23408,34,1}, /* core0 return_Stack0 bit45 */
			{23407,34,1}, /* core0 return_Stack0 bit46 */
			{23406,34,1}, /* core0 return_Stack0 bit47 */
			{13707,34,0}, /* core0 return_Stack0 bit48 */
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
			{23461,34,0}, /* core0 return_Stack1 bit0 */
			{23460,34,0}, /* core0 return_Stack1 bit1 */
			{23459,34,0}, /* core0 return_Stack1 bit2 */
			{23445,34,0}, /* core0 return_Stack1 bit3 */
			{23444,34,0}, /* core0 return_Stack1 bit4 */
			{23443,34,0}, /* core0 return_Stack1 bit5 */
			{23442,34,0}, /* core0 return_Stack1 bit6 */
			{23441,34,0}, /* core0 return_Stack1 bit7 */
			{23440,34,0}, /* core0 return_Stack1 bit8 */
			{23439,34,0}, /* core0 return_Stack1 bit9 */
			{23458,34,0}, /* core0 return_Stack1 bit10 */
			{23425,34,0}, /* core0 return_Stack1 bit11 */
			{23424,34,0}, /* core0 return_Stack1 bit12 */
			{23423,34,0}, /* core0 return_Stack1 bit13 */
			{23422,34,0}, /* core0 return_Stack1 bit14 */
			{23373,34,0}, /* core0 return_Stack1 bit15 */
			{23372,34,0}, /* core0 return_Stack1 bit16 */
			{23371,34,0}, /* core0 return_Stack1 bit17 */
			{23370,34,0}, /* core0 return_Stack1 bit18 */
			{23429,34,0}, /* core0 return_Stack1 bit19 */
			{23428,34,0}, /* core0 return_Stack1 bit20 */
			{23427,34,0}, /* core0 return_Stack1 bit21 */
			{23426,34,0}, /* core0 return_Stack1 bit22 */
			{23393,34,1}, /* core0 return_Stack1 bit23 */
			{23392,34,1}, /* core0 return_Stack1 bit24 */
			{23391,34,1}, /* core0 return_Stack1 bit25 */
			{23390,34,1}, /* core0 return_Stack1 bit26 */
			{23389,34,1}, /* core0 return_Stack1 bit27 */
			{23388,34,1}, /* core0 return_Stack1 bit28 */
			{23387,34,1}, /* core0 return_Stack1 bit29 */
			{23386,34,1}, /* core0 return_Stack1 bit30 */
			{13711,34,0}, /* core0 return_Stack1 bit31 */
			{23377,34,0}, /* core0 return_Stack1 bit32 */
			{23376,34,0}, /* core0 return_Stack1 bit33 */
			{23375,34,0}, /* core0 return_Stack1 bit34 */
			{23374,34,0}, /* core0 return_Stack1 bit35 */
			{23453,34,1}, /* core0 return_Stack1 bit36 */
			{23452,34,1}, /* core0 return_Stack1 bit37 */
			{23451,34,1}, /* core0 return_Stack1 bit38 */
			{23450,34,1}, /* core0 return_Stack1 bit39 */
			{23401,34,0}, /* core0 return_Stack1 bit40 */
			{23400,34,0}, /* core0 return_Stack1 bit41 */
			{23399,34,0}, /* core0 return_Stack1 bit42 */
			{23398,34,0}, /* core0 return_Stack1 bit43 */
			{23457,34,1}, /* core0 return_Stack1 bit44 */
			{23456,34,1}, /* core0 return_Stack1 bit45 */
			{23455,34,1}, /* core0 return_Stack1 bit46 */
			{23454,34,1}, /* core0 return_Stack1 bit47 */
			{13705,34,0}, /* core0 return_Stack1 bit48 */
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
			{23397,34,0}, /* core0 return_Stack2 bit0 */
			{23396,34,0}, /* core0 return_Stack2 bit1 */
			{23395,34,0}, /* core0 return_Stack2 bit2 */
			{23437,34,0}, /* core0 return_Stack2 bit3 */
			{23436,34,0}, /* core0 return_Stack2 bit4 */
			{23435,34,0}, /* core0 return_Stack2 bit5 */
			{23434,34,0}, /* core0 return_Stack2 bit6 */
			{23361,34,0}, /* core0 return_Stack2 bit7 */
			{23360,34,0}, /* core0 return_Stack2 bit8 */
			{23359,34,0}, /* core0 return_Stack2 bit9 */
			{23394,34,0}, /* core0 return_Stack2 bit10 */
			{23433,34,0}, /* core0 return_Stack2 bit11 */
			{23432,34,0}, /* core0 return_Stack2 bit12 */
			{23431,34,0}, /* core0 return_Stack2 bit13 */
			{23430,34,0}, /* core0 return_Stack2 bit14 */
			{23357,34,1}, /* core0 return_Stack2 bit15 */
			{23356,34,1}, /* core0 return_Stack2 bit16 */
			{23355,34,1}, /* core0 return_Stack2 bit17 */
			{23354,34,1}, /* core0 return_Stack2 bit18 */
			{23216,34,0}, /* core0 return_Stack2 bit19 */
			{23215,34,0}, /* core0 return_Stack2 bit20 */
			{23214,34,0}, /* core0 return_Stack2 bit21 */
			{23213,34,0}, /* core0 return_Stack2 bit22 */
			{23312,34,1}, /* core0 return_Stack2 bit23 */
			{23311,34,1}, /* core0 return_Stack2 bit24 */
			{23310,34,1}, /* core0 return_Stack2 bit25 */
			{23309,34,1}, /* core0 return_Stack2 bit26 */
			{23128,34,1}, /* core0 return_Stack2 bit27 */
			{23127,34,1}, /* core0 return_Stack2 bit28 */
			{23126,34,1}, /* core0 return_Stack2 bit29 */
			{23125,34,1}, /* core0 return_Stack2 bit30 */
			{13712,34,0}, /* core0 return_Stack2 bit31 */
			{23152,34,1}, /* core0 return_Stack2 bit32 */
			{23151,34,1}, /* core0 return_Stack2 bit33 */
			{23150,34,1}, /* core0 return_Stack2 bit34 */
			{23149,34,1}, /* core0 return_Stack2 bit35 */
			{23244,34,1}, /* core0 return_Stack2 bit36 */
			{23243,34,1}, /* core0 return_Stack2 bit37 */
			{23242,34,1}, /* core0 return_Stack2 bit38 */
			{23241,34,1}, /* core0 return_Stack2 bit39 */
			{23308,34,1}, /* core0 return_Stack2 bit40 */
			{23307,34,1}, /* core0 return_Stack2 bit41 */
			{23306,34,1}, /* core0 return_Stack2 bit42 */
			{23305,34,1}, /* core0 return_Stack2 bit43 */
			{23256,34,1}, /* core0 return_Stack2 bit44 */
			{23255,34,1}, /* core0 return_Stack2 bit45 */
			{23254,34,1}, /* core0 return_Stack2 bit46 */
			{23253,34,1}, /* core0 return_Stack2 bit47 */
			{13713,34,0}, /* core0 return_Stack2 bit48 */
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
			{23332,34,0}, /* core0 return_Stack3 bit0 */
			{23331,34,0}, /* core0 return_Stack3 bit1 */
			{23330,34,0}, /* core0 return_Stack3 bit2 */
			{23204,34,0}, /* core0 return_Stack3 bit3 */
			{23203,34,0}, /* core0 return_Stack3 bit4 */
			{23202,34,0}, /* core0 return_Stack3 bit5 */
			{23201,34,0}, /* core0 return_Stack3 bit6 */
			{23168,34,0}, /* core0 return_Stack3 bit7 */
			{23167,34,0}, /* core0 return_Stack3 bit8 */
			{23166,34,0}, /* core0 return_Stack3 bit9 */
			{23329,34,0}, /* core0 return_Stack3 bit10 */
			{23228,34,0}, /* core0 return_Stack3 bit11 */
			{23227,34,0}, /* core0 return_Stack3 bit12 */
			{23226,34,0}, /* core0 return_Stack3 bit13 */
			{23225,34,0}, /* core0 return_Stack3 bit14 */
			{23160,34,1}, /* core0 return_Stack3 bit15 */
			{23159,34,1}, /* core0 return_Stack3 bit16 */
			{23158,34,1}, /* core0 return_Stack3 bit17 */
			{23157,34,1}, /* core0 return_Stack3 bit18 */
			{23224,34,0}, /* core0 return_Stack3 bit19 */
			{23223,34,0}, /* core0 return_Stack3 bit20 */
			{23222,34,0}, /* core0 return_Stack3 bit21 */
			{23221,34,0}, /* core0 return_Stack3 bit22 */
			{23340,34,1}, /* core0 return_Stack3 bit23 */
			{23339,34,1}, /* core0 return_Stack3 bit24 */
			{23338,34,1}, /* core0 return_Stack3 bit25 */
			{23337,34,1}, /* core0 return_Stack3 bit26 */
			{23124,34,1}, /* core0 return_Stack3 bit27 */
			{23123,34,1}, /* core0 return_Stack3 bit28 */
			{23122,34,1}, /* core0 return_Stack3 bit29 */
			{23121,34,1}, /* core0 return_Stack3 bit30 */
			{13714,34,0}, /* core0 return_Stack3 bit31 */
			{23148,34,1}, /* core0 return_Stack3 bit32 */
			{23147,34,1}, /* core0 return_Stack3 bit33 */
			{23146,34,1}, /* core0 return_Stack3 bit34 */
			{23145,34,1}, /* core0 return_Stack3 bit35 */
			{23272,34,1}, /* core0 return_Stack3 bit36 */
			{23271,34,1}, /* core0 return_Stack3 bit37 */
			{23270,34,1}, /* core0 return_Stack3 bit38 */
			{23269,34,1}, /* core0 return_Stack3 bit39 */
			{23320,34,1}, /* core0 return_Stack3 bit40 */
			{23319,34,1}, /* core0 return_Stack3 bit41 */
			{23318,34,1}, /* core0 return_Stack3 bit42 */
			{23317,34,1}, /* core0 return_Stack3 bit43 */
			{23264,34,1}, /* core0 return_Stack3 bit44 */
			{23263,34,1}, /* core0 return_Stack3 bit45 */
			{23262,34,1}, /* core0 return_Stack3 bit46 */
			{23261,34,1}, /* core0 return_Stack3 bit47 */
			{13717,34,0}, /* core0 return_Stack3 bit48 */
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
			{23352,34,0}, /* core0 return_Stack4 bit0 */
			{23351,34,0}, /* core0 return_Stack4 bit1 */
			{23350,34,0}, /* core0 return_Stack4 bit2 */
			{23268,34,0}, /* core0 return_Stack4 bit3 */
			{23267,34,0}, /* core0 return_Stack4 bit4 */
			{23266,34,0}, /* core0 return_Stack4 bit5 */
			{23265,34,0}, /* core0 return_Stack4 bit6 */
			{23180,34,0}, /* core0 return_Stack4 bit7 */
			{23179,34,0}, /* core0 return_Stack4 bit8 */
			{23178,34,0}, /* core0 return_Stack4 bit9 */
			{23349,34,0}, /* core0 return_Stack4 bit10 */
			{23288,34,0}, /* core0 return_Stack4 bit11 */
			{23287,34,0}, /* core0 return_Stack4 bit12 */
			{23286,34,0}, /* core0 return_Stack4 bit13 */
			{23285,34,0}, /* core0 return_Stack4 bit14 */
			{23184,34,0}, /* core0 return_Stack4 bit15 */
			{23183,34,0}, /* core0 return_Stack4 bit16 */
			{23182,34,0}, /* core0 return_Stack4 bit17 */
			{23181,34,0}, /* core0 return_Stack4 bit18 */
			{23284,34,0}, /* core0 return_Stack4 bit19 */
			{23283,34,0}, /* core0 return_Stack4 bit20 */
			{23282,34,0}, /* core0 return_Stack4 bit21 */
			{23281,34,0}, /* core0 return_Stack4 bit22 */
			{23344,34,1}, /* core0 return_Stack4 bit23 */
			{23343,34,1}, /* core0 return_Stack4 bit24 */
			{23342,34,1}, /* core0 return_Stack4 bit25 */
			{23341,34,1}, /* core0 return_Stack4 bit26 */
			{23116,34,1}, /* core0 return_Stack4 bit27 */
			{23115,34,1}, /* core0 return_Stack4 bit28 */
			{23114,34,1}, /* core0 return_Stack4 bit29 */
			{23113,34,1}, /* core0 return_Stack4 bit30 */
			{13708,34,0}, /* core0 return_Stack4 bit31 */
			{23140,34,0}, /* core0 return_Stack4 bit32 */
			{23139,34,0}, /* core0 return_Stack4 bit33 */
			{23138,34,0}, /* core0 return_Stack4 bit34 */
			{23137,34,0}, /* core0 return_Stack4 bit35 */
			{23292,34,1}, /* core0 return_Stack4 bit36 */
			{23291,34,1}, /* core0 return_Stack4 bit37 */
			{23290,34,1}, /* core0 return_Stack4 bit38 */
			{23289,34,1}, /* core0 return_Stack4 bit39 */
			{23300,34,0}, /* core0 return_Stack4 bit40 */
			{23299,34,0}, /* core0 return_Stack4 bit41 */
			{23298,34,0}, /* core0 return_Stack4 bit42 */
			{23297,34,0}, /* core0 return_Stack4 bit43 */
			{23296,34,1}, /* core0 return_Stack4 bit44 */
			{23295,34,1}, /* core0 return_Stack4 bit45 */
			{23294,34,1}, /* core0 return_Stack4 bit46 */
			{23293,34,1}, /* core0 return_Stack4 bit47 */
			{13709,34,0}, /* core0 return_Stack4 bit48 */
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
			{23348,34,0}, /* core0 return_Stack5 bit0 */
			{23347,34,0}, /* core0 return_Stack5 bit1 */
			{23346,34,0}, /* core0 return_Stack5 bit2 */
			{23196,34,0}, /* core0 return_Stack5 bit3 */
			{23195,34,0}, /* core0 return_Stack5 bit4 */
			{23194,34,0}, /* core0 return_Stack5 bit5 */
			{23193,34,0}, /* core0 return_Stack5 bit6 */
			{23192,34,0}, /* core0 return_Stack5 bit7 */
			{23191,34,0}, /* core0 return_Stack5 bit8 */
			{23190,34,0}, /* core0 return_Stack5 bit9 */
			{23345,34,0}, /* core0 return_Stack5 bit10 */
			{23240,34,0}, /* core0 return_Stack5 bit11 */
			{23239,34,0}, /* core0 return_Stack5 bit12 */
			{23238,34,0}, /* core0 return_Stack5 bit13 */
			{23237,34,0}, /* core0 return_Stack5 bit14 */
			{23188,34,0}, /* core0 return_Stack5 bit15 */
			{23187,34,0}, /* core0 return_Stack5 bit16 */
			{23186,34,0}, /* core0 return_Stack5 bit17 */
			{23185,34,0}, /* core0 return_Stack5 bit18 */
			{23280,34,0}, /* core0 return_Stack5 bit19 */
			{23279,34,0}, /* core0 return_Stack5 bit20 */
			{23278,34,0}, /* core0 return_Stack5 bit21 */
			{23277,34,0}, /* core0 return_Stack5 bit22 */
			{23112,34,1}, /* core0 return_Stack5 bit23 */
			{23111,34,1}, /* core0 return_Stack5 bit24 */
			{23110,34,1}, /* core0 return_Stack5 bit25 */
			{23109,34,1}, /* core0 return_Stack5 bit26 */
			{23120,34,1}, /* core0 return_Stack5 bit27 */
			{23119,34,1}, /* core0 return_Stack5 bit28 */
			{23118,34,1}, /* core0 return_Stack5 bit29 */
			{23117,34,1}, /* core0 return_Stack5 bit30 */
			{13710,34,0}, /* core0 return_Stack5 bit31 */
			{23136,34,0}, /* core0 return_Stack5 bit32 */
			{23135,34,0}, /* core0 return_Stack5 bit33 */
			{23134,34,0}, /* core0 return_Stack5 bit34 */
			{23133,34,0}, /* core0 return_Stack5 bit35 */
			{23248,34,1}, /* core0 return_Stack5 bit36 */
			{23247,34,1}, /* core0 return_Stack5 bit37 */
			{23246,34,1}, /* core0 return_Stack5 bit38 */
			{23245,34,1}, /* core0 return_Stack5 bit39 */
			{23304,34,0}, /* core0 return_Stack5 bit40 */
			{23303,34,0}, /* core0 return_Stack5 bit41 */
			{23302,34,0}, /* core0 return_Stack5 bit42 */
			{23301,34,0}, /* core0 return_Stack5 bit43 */
			{23252,34,1}, /* core0 return_Stack5 bit44 */
			{23251,34,1}, /* core0 return_Stack5 bit45 */
			{23250,34,1}, /* core0 return_Stack5 bit46 */
			{23249,34,1}, /* core0 return_Stack5 bit47 */
			{13704,34,0}, /* core0 return_Stack5 bit48 */
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
			{23324,34,0}, /* core0 return_Stack6 bit0 */
			{23323,34,0}, /* core0 return_Stack6 bit1 */
			{23322,34,0}, /* core0 return_Stack6 bit2 */
			{23208,34,0}, /* core0 return_Stack6 bit3 */
			{23207,34,0}, /* core0 return_Stack6 bit4 */
			{23206,34,0}, /* core0 return_Stack6 bit5 */
			{23205,34,0}, /* core0 return_Stack6 bit6 */
			{23176,34,0}, /* core0 return_Stack6 bit7 */
			{23175,34,0}, /* core0 return_Stack6 bit8 */
			{23174,34,0}, /* core0 return_Stack6 bit9 */
			{23321,34,0}, /* core0 return_Stack6 bit10 */
			{23212,34,0}, /* core0 return_Stack6 bit11 */
			{23211,34,0}, /* core0 return_Stack6 bit12 */
			{23210,34,0}, /* core0 return_Stack6 bit13 */
			{23209,34,0}, /* core0 return_Stack6 bit14 */
			{23164,34,1}, /* core0 return_Stack6 bit15 */
			{23163,34,1}, /* core0 return_Stack6 bit16 */
			{23162,34,1}, /* core0 return_Stack6 bit17 */
			{23161,34,1}, /* core0 return_Stack6 bit18 */
			{23220,34,0}, /* core0 return_Stack6 bit19 */
			{23219,34,0}, /* core0 return_Stack6 bit20 */
			{23218,34,0}, /* core0 return_Stack6 bit21 */
			{23217,34,0}, /* core0 return_Stack6 bit22 */
			{23316,34,1}, /* core0 return_Stack6 bit23 */
			{23315,34,1}, /* core0 return_Stack6 bit24 */
			{23314,34,1}, /* core0 return_Stack6 bit25 */
			{23313,34,1}, /* core0 return_Stack6 bit26 */
			{23132,34,1}, /* core0 return_Stack6 bit27 */
			{23131,34,1}, /* core0 return_Stack6 bit28 */
			{23130,34,1}, /* core0 return_Stack6 bit29 */
			{23129,34,1}, /* core0 return_Stack6 bit30 */
			{13718,34,0}, /* core0 return_Stack6 bit31 */
			{23144,34,0}, /* core0 return_Stack6 bit32 */
			{23143,34,0}, /* core0 return_Stack6 bit33 */
			{23142,34,0}, /* core0 return_Stack6 bit34 */
			{23141,34,0}, /* core0 return_Stack6 bit35 */
			{23276,34,1}, /* core0 return_Stack6 bit36 */
			{23275,34,1}, /* core0 return_Stack6 bit37 */
			{23274,34,1}, /* core0 return_Stack6 bit38 */
			{23273,34,1}, /* core0 return_Stack6 bit39 */
			{23328,34,1}, /* core0 return_Stack6 bit40 */
			{23327,34,1}, /* core0 return_Stack6 bit41 */
			{23326,34,1}, /* core0 return_Stack6 bit42 */
			{23325,34,1}, /* core0 return_Stack6 bit43 */
			{23260,34,1}, /* core0 return_Stack6 bit44 */
			{23259,34,1}, /* core0 return_Stack6 bit45 */
			{23258,34,1}, /* core0 return_Stack6 bit46 */
			{23257,34,1}, /* core0 return_Stack6 bit47 */
			{13719,34,0}, /* core0 return_Stack6 bit48 */
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
			{23336,34,0}, /* core0 return_Stack7 bit0 */
			{23335,34,0}, /* core0 return_Stack7 bit1 */
			{23334,34,0}, /* core0 return_Stack7 bit2 */
			{23200,34,0}, /* core0 return_Stack7 bit3 */
			{23199,34,0}, /* core0 return_Stack7 bit4 */
			{23198,34,0}, /* core0 return_Stack7 bit5 */
			{23197,34,0}, /* core0 return_Stack7 bit6 */
			{23172,34,0}, /* core0 return_Stack7 bit7 */
			{23171,34,0}, /* core0 return_Stack7 bit8 */
			{23170,34,0}, /* core0 return_Stack7 bit9 */
			{23333,34,0}, /* core0 return_Stack7 bit10 */
			{23236,34,0}, /* core0 return_Stack7 bit11 */
			{23235,34,0}, /* core0 return_Stack7 bit12 */
			{23234,34,0}, /* core0 return_Stack7 bit13 */
			{23233,34,0}, /* core0 return_Stack7 bit14 */
			{23156,34,1}, /* core0 return_Stack7 bit15 */
			{23155,34,1}, /* core0 return_Stack7 bit16 */
			{23154,34,1}, /* core0 return_Stack7 bit17 */
			{23153,34,1}, /* core0 return_Stack7 bit18 */
			{23232,34,0}, /* core0 return_Stack7 bit19 */
			{23231,34,0}, /* core0 return_Stack7 bit20 */
			{23230,34,0}, /* core0 return_Stack7 bit21 */
			{23229,34,0}, /* core0 return_Stack7 bit22 */
			{23108,34,1}, /* core0 return_Stack7 bit23 */
			{23107,34,1}, /* core0 return_Stack7 bit24 */
			{23106,34,1}, /* core0 return_Stack7 bit25 */
			{23105,34,1}, /* core0 return_Stack7 bit26 */
			{23035,34,1}, /* core0 return_Stack7 bit27 */
			{23034,34,1}, /* core0 return_Stack7 bit28 */
			{23033,34,1}, /* core0 return_Stack7 bit29 */
			{23032,34,1}, /* core0 return_Stack7 bit30 */
			{13715,34,0}, /* core0 return_Stack7 bit31 */
			{23031,34,1}, /* core0 return_Stack7 bit32 */
			{23030,34,1}, /* core0 return_Stack7 bit33 */
			{23029,34,1}, /* core0 return_Stack7 bit34 */
			{23028,34,1}, /* core0 return_Stack7 bit35 */
			{23023,34,1}, /* core0 return_Stack7 bit36 */
			{23022,34,1}, /* core0 return_Stack7 bit37 */
			{23021,34,1}, /* core0 return_Stack7 bit38 */
			{23020,34,1}, /* core0 return_Stack7 bit39 */
			{23039,34,1}, /* core0 return_Stack7 bit40 */
			{23038,34,1}, /* core0 return_Stack7 bit41 */
			{23037,34,1}, /* core0 return_Stack7 bit42 */
			{23036,34,1}, /* core0 return_Stack7 bit43 */
			{23027,34,1}, /* core0 return_Stack7 bit44 */
			{23026,34,1}, /* core0 return_Stack7 bit45 */
			{23025,34,1}, /* core0 return_Stack7 bit46 */
			{23024,34,1}, /* core0 return_Stack7 bit47 */
			{13716,34,0}, /* core0 return_Stack7 bit48 */
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
			.L2_parity_err = {{
			{ 7910,33,0}, /* core0 L2_parity_err bit0 */
			{    0, 0,2}, /* core0 L2_parity_err bit1 */
			{    0, 0,2}, /* core0 L2_parity_err bit2 */
			{    0, 0,2}, /* core0 L2_parity_err bit3 */
			{    0, 0,2}, /* core0 L2_parity_err bit4 */
			{    0, 0,2}, /* core0 L2_parity_err bit5 */
			{    0, 0,2}, /* core0 L2_parity_err bit6 */
			{    0, 0,2}, /* core0 L2_parity_err bit7 */
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
			.L2_parity_err_count = {{
			{13805,33,1}, /* core0 L2_parity_err_count bit0 */
			{13804,33,1}, /* core0 L2_parity_err_count bit1 */
			{13803,33,1}, /* core0 L2_parity_err_count bit2 */
			{13810,33,0}, /* core0 L2_parity_err_count bit3 */
			{13809,33,0}, /* core0 L2_parity_err_count bit4 */
			{13808,33,0}, /* core0 L2_parity_err_count bit5 */
			{13807,33,0}, /* core0 L2_parity_err_count bit6 */
			{ 7911,33,0}, /* core0 L2_parity_err_count bit7 */
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
			{14288,33,0}, /* core0 L2_parity_index bit0 */
			{14287,33,0}, /* core0 L2_parity_index bit1 */
			{14286,33,0}, /* core0 L2_parity_index bit2 */
			{14285,33,0}, /* core0 L2_parity_index bit3 */
			{14284,33,0}, /* core0 L2_parity_index bit4 */
			{14283,33,0}, /* core0 L2_parity_index bit5 */
			{14282,33,0}, /* core0 L2_parity_index bit6 */
			{14281,33,0}, /* core0 L2_parity_index bit7 */
			{ 7821,33,0}, /* core0 L2_parity_index bit8 */
			{    0, 0,2}, /* core0 L2_parity_index bit9 */
			{    0, 0,2}, /* core0 L2_parity_index bit10 */
			{    0, 0,2}, /* core0 L2_parity_index bit11 */
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
			{10378,33,0}, /* core0 L2_parity_way bit0 */
			{10377,33,0}, /* core0 L2_parity_way bit1 */
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
			{14280,33,0}, /* core0 L2_parity_banks bit0 */
			{14279,33,0}, /* core0 L2_parity_banks bit1 */
			{14278,33,0}, /* core0 L2_parity_banks bit2 */
			{14277,33,0}, /* core0 L2_parity_banks bit3 */
			{14272,33,0}, /* core0 L2_parity_banks bit4 */
			{14271,33,0}, /* core0 L2_parity_banks bit5 */
			{14270,33,0}, /* core0 L2_parity_banks bit6 */
			{14269,33,0}, /* core0 L2_parity_banks bit7 */
			{14292,33,0}, /* core0 L2_parity_banks bit8 */
			{14291,33,0}, /* core0 L2_parity_banks bit9 */
			{14290,33,0}, /* core0 L2_parity_banks bit10 */
			{14289,33,0}, /* core0 L2_parity_banks bit11 */
			{14276,33,0}, /* core0 L2_parity_banks bit12 */
			{14275,33,0}, /* core0 L2_parity_banks bit13 */
			{14274,33,0}, /* core0 L2_parity_banks bit14 */
			{14273,33,0}, /* core0 L2_parity_banks bit15 */
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
			{  192,35,0}, /* core1 pc bit0 */
			{  191,35,0}, /* core1 pc bit1 */
			{  190,35,0}, /* core1 pc bit2 */
			{  189,35,0}, /* core1 pc bit3 */
			{  142,35,0}, /* core1 pc bit4 */
			{  141,35,0}, /* core1 pc bit5 */
			{  140,35,0}, /* core1 pc bit6 */
			{  139,35,0}, /* core1 pc bit7 */
			{  146,35,0}, /* core1 pc bit8 */
			{  145,35,0}, /* core1 pc bit9 */
			{  144,35,0}, /* core1 pc bit10 */
			{  143,35,0}, /* core1 pc bit11 */
			{  150,35,0}, /* core1 pc bit12 */
			{  149,35,0}, /* core1 pc bit13 */
			{  148,35,0}, /* core1 pc bit14 */
			{  147,35,0}, /* core1 pc bit15 */
			{  126,35,0}, /* core1 pc bit16 */
			{  125,35,0}, /* core1 pc bit17 */
			{  124,35,0}, /* core1 pc bit18 */
			{  123,35,0}, /* core1 pc bit19 */
			{  134,35,0}, /* core1 pc bit20 */
			{  133,35,0}, /* core1 pc bit21 */
			{  132,35,0}, /* core1 pc bit22 */
			{  131,35,0}, /* core1 pc bit23 */
			{  138,35,0}, /* core1 pc bit24 */
			{  137,35,0}, /* core1 pc bit25 */
			{  136,35,0}, /* core1 pc bit26 */
			{  135,35,0}, /* core1 pc bit27 */
			{  130,35,0}, /* core1 pc bit28 */
			{  129,35,0}, /* core1 pc bit29 */
			{  128,35,0}, /* core1 pc bit30 */
			{  127,35,0}, /* core1 pc bit31 */
			{  240,35,0}, /* core1 pc bit32 */
			{  239,35,0}, /* core1 pc bit33 */
			{  238,35,0}, /* core1 pc bit34 */
			{  237,35,0}, /* core1 pc bit35 */
			{  248,35,0}, /* core1 pc bit36 */
			{  247,35,0}, /* core1 pc bit37 */
			{  246,35,0}, /* core1 pc bit38 */
			{  245,35,0}, /* core1 pc bit39 */
			{  244,35,0}, /* core1 pc bit40 */
			{  243,35,0}, /* core1 pc bit41 */
			{  242,35,0}, /* core1 pc bit42 */
			{  241,35,0}, /* core1 pc bit43 */
			{  216,35,0}, /* core1 pc bit44 */
			{  215,35,0}, /* core1 pc bit45 */
			{  214,35,0}, /* core1 pc bit46 */
			{  213,35,0}, /* core1 pc bit47 */
			{  180,35,0}, /* core1 pc bit48 */
			{  179,35,0}, /* core1 pc bit49 */
			{  178,35,0}, /* core1 pc bit50 */
			{  177,35,0}, /* core1 pc bit51 */
			{  184,35,0}, /* core1 pc bit52 */
			{  183,35,0}, /* core1 pc bit53 */
			{  182,35,0}, /* core1 pc bit54 */
			{  181,35,0}, /* core1 pc bit55 */
			{  236,35,0}, /* core1 pc bit56 */
			{  235,35,0}, /* core1 pc bit57 */
			{  234,35,0}, /* core1 pc bit58 */
			{  233,35,0}, /* core1 pc bit59 */
			{  188,35,0}, /* core1 pc bit60 */
			{  187,35,0}, /* core1 pc bit61 */
			{  186,35,0}, /* core1 pc bit62 */
			{  185,35,0}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{41807,36,0}, /* core1 sp32 bit0 */
			{41871,36,0}, /* core1 sp32 bit1 */
			{41806,36,0}, /* core1 sp32 bit2 */
			{41805,36,0}, /* core1 sp32 bit3 */
			{41804,36,0}, /* core1 sp32 bit4 */
			{41855,36,0}, /* core1 sp32 bit5 */
			{41854,36,0}, /* core1 sp32 bit6 */
			{41853,36,0}, /* core1 sp32 bit7 */
			{41852,36,0}, /* core1 sp32 bit8 */
			{41859,36,0}, /* core1 sp32 bit9 */
			{41858,36,0}, /* core1 sp32 bit10 */
			{41857,36,0}, /* core1 sp32 bit11 */
			{41856,36,0}, /* core1 sp32 bit12 */
			{41867,36,0}, /* core1 sp32 bit13 */
			{41866,36,0}, /* core1 sp32 bit14 */
			{41865,36,0}, /* core1 sp32 bit15 */
			{41864,36,0}, /* core1 sp32 bit16 */
			{41679,36,0}, /* core1 sp32 bit17 */
			{41678,36,0}, /* core1 sp32 bit18 */
			{41870,36,0}, /* core1 sp32 bit19 */
			{41677,36,0}, /* core1 sp32 bit20 */
			{41676,36,0}, /* core1 sp32 bit21 */
			{41671,36,0}, /* core1 sp32 bit22 */
			{41670,36,0}, /* core1 sp32 bit23 */
			{41669,36,0}, /* core1 sp32 bit24 */
			{41668,36,0}, /* core1 sp32 bit25 */
			{41869,36,0}, /* core1 sp32 bit26 */
			{41667,36,0}, /* core1 sp32 bit27 */
			{41666,36,0}, /* core1 sp32 bit28 */
			{41665,36,0}, /* core1 sp32 bit29 */
			{41664,36,0}, /* core1 sp32 bit30 */
			{41868,36,0}, /* core1 sp32 bit31 */
			{41483,36,0}, /* core1 sp32 bit32 */
			{41482,36,0}, /* core1 sp32 bit33 */
			{41481,36,0}, /* core1 sp32 bit34 */
			{41480,36,0}, /* core1 sp32 bit35 */
			{36299,36,0}, /* core1 sp32 bit36 */
			{28101,36,0}, /* core1 sp32 bit37 */
			{36298,36,0}, /* core1 sp32 bit38 */
			{41535,36,0}, /* core1 sp32 bit39 */
			{41534,36,0}, /* core1 sp32 bit40 */
			{41533,36,0}, /* core1 sp32 bit41 */
			{41532,36,0}, /* core1 sp32 bit42 */
			{41479,36,0}, /* core1 sp32 bit43 */
			{41478,36,0}, /* core1 sp32 bit44 */
			{41477,36,0}, /* core1 sp32 bit45 */
			{41476,36,0}, /* core1 sp32 bit46 */
			{36277,36,0}, /* core1 sp32 bit47 */
			{36276,36,0}, /* core1 sp32 bit48 */
			{41531,36,0}, /* core1 sp32 bit49 */
			{41530,36,0}, /* core1 sp32 bit50 */
			{41529,36,0}, /* core1 sp32 bit51 */
			{41528,36,0}, /* core1 sp32 bit52 */
			{41523,36,0}, /* core1 sp32 bit53 */
			{41522,36,0}, /* core1 sp32 bit54 */
			{41521,36,0}, /* core1 sp32 bit55 */
			{41520,36,0}, /* core1 sp32 bit56 */
			{41527,36,0}, /* core1 sp32 bit57 */
			{41526,36,0}, /* core1 sp32 bit58 */
			{41525,36,0}, /* core1 sp32 bit59 */
			{41524,36,0}, /* core1 sp32 bit60 */
			{41519,36,0}, /* core1 sp32 bit61 */
			{41518,36,0}, /* core1 sp32 bit62 */
			{41517,36,0}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{42038,36,0}, /* core1 fp32 bit0 */
			{42037,36,0}, /* core1 fp32 bit1 */
			{42021,36,0}, /* core1 fp32 bit2 */
			{42020,36,0}, /* core1 fp32 bit3 */
			{42036,36,0}, /* core1 fp32 bit4 */
			{42043,36,0}, /* core1 fp32 bit5 */
			{42042,36,0}, /* core1 fp32 bit6 */
			{42041,36,0}, /* core1 fp32 bit7 */
			{42040,36,0}, /* core1 fp32 bit8 */
			{42027,36,0}, /* core1 fp32 bit9 */
			{42031,36,0}, /* core1 fp32 bit10 */
			{42030,36,0}, /* core1 fp32 bit11 */
			{42029,36,0}, /* core1 fp32 bit12 */
			{42028,36,0}, /* core1 fp32 bit13 */
			{42015,36,0}, /* core1 fp32 bit14 */
			{42014,36,0}, /* core1 fp32 bit15 */
			{42026,36,0}, /* core1 fp32 bit16 */
			{42013,36,0}, /* core1 fp32 bit17 */
			{42035,36,0}, /* core1 fp32 bit18 */
			{42034,36,0}, /* core1 fp32 bit19 */
			{42033,36,0}, /* core1 fp32 bit20 */
			{42012,36,0}, /* core1 fp32 bit21 */
			{42019,36,0}, /* core1 fp32 bit22 */
			{42018,36,0}, /* core1 fp32 bit23 */
			{42017,36,0}, /* core1 fp32 bit24 */
			{42032,36,0}, /* core1 fp32 bit25 */
			{42016,36,0}, /* core1 fp32 bit26 */
			{42023,36,0}, /* core1 fp32 bit27 */
			{42025,36,0}, /* core1 fp32 bit28 */
			{42022,36,0}, /* core1 fp32 bit29 */
			{42024,36,0}, /* core1 fp32 bit30 */
			{42039,36,0}, /* core1 fp32 bit31 */
			{42143,36,0}, /* core1 fp32 bit32 */
			{42142,36,0}, /* core1 fp32 bit33 */
			{42141,36,0}, /* core1 fp32 bit34 */
			{42140,36,0}, /* core1 fp32 bit35 */
			{42135,36,0}, /* core1 fp32 bit36 */
			{42134,36,0}, /* core1 fp32 bit37 */
			{42133,36,0}, /* core1 fp32 bit38 */
			{42132,36,0}, /* core1 fp32 bit39 */
			{42131,36,0}, /* core1 fp32 bit40 */
			{42130,36,0}, /* core1 fp32 bit41 */
			{42129,36,0}, /* core1 fp32 bit42 */
			{42128,36,0}, /* core1 fp32 bit43 */
			{42139,36,0}, /* core1 fp32 bit44 */
			{42138,36,0}, /* core1 fp32 bit45 */
			{42137,36,0}, /* core1 fp32 bit46 */
			{42136,36,0}, /* core1 fp32 bit47 */
			{28149,36,0}, /* core1 fp32 bit48 */
			{42151,36,0}, /* core1 fp32 bit49 */
			{42150,36,0}, /* core1 fp32 bit50 */
			{42149,36,0}, /* core1 fp32 bit51 */
			{42148,36,0}, /* core1 fp32 bit52 */
			{42155,36,0}, /* core1 fp32 bit53 */
			{42154,36,0}, /* core1 fp32 bit54 */
			{42153,36,0}, /* core1 fp32 bit55 */
			{42152,36,0}, /* core1 fp32 bit56 */
			{42147,36,0}, /* core1 fp32 bit57 */
			{42146,36,0}, /* core1 fp32 bit58 */
			{42145,36,0}, /* core1 fp32 bit59 */
			{42144,36,0}, /* core1 fp32 bit60 */
			{42159,36,0}, /* core1 fp32 bit61 */
			{42158,36,0}, /* core1 fp32 bit62 */
			{42157,36,0}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{40979,36,0}, /* core1 fp64 bit0 */
			{40978,36,0}, /* core1 fp64 bit1 */
			{28248,36,0}, /* core1 fp64 bit2 */
			{40999,36,0}, /* core1 fp64 bit3 */
			{36342,36,0}, /* core1 fp64 bit4 */
			{40977,36,0}, /* core1 fp64 bit5 */
			{40970,36,0}, /* core1 fp64 bit6 */
			{40976,36,0}, /* core1 fp64 bit7 */
			{40969,36,0}, /* core1 fp64 bit8 */
			{40968,36,0}, /* core1 fp64 bit9 */
			{40975,36,0}, /* core1 fp64 bit10 */
			{40974,36,0}, /* core1 fp64 bit11 */
			{40987,36,0}, /* core1 fp64 bit12 */
			{40986,36,0}, /* core1 fp64 bit13 */
			{40985,36,0}, /* core1 fp64 bit14 */
			{40973,36,0}, /* core1 fp64 bit15 */
			{40998,36,0}, /* core1 fp64 bit16 */
			{40997,36,0}, /* core1 fp64 bit17 */
			{40996,36,0}, /* core1 fp64 bit18 */
			{36343,36,0}, /* core1 fp64 bit19 */
			{40995,36,0}, /* core1 fp64 bit20 */
			{40972,36,0}, /* core1 fp64 bit21 */
			{40984,36,0}, /* core1 fp64 bit22 */
			{40983,36,0}, /* core1 fp64 bit23 */
			{28249,36,0}, /* core1 fp64 bit24 */
			{40982,36,0}, /* core1 fp64 bit25 */
			{40994,36,0}, /* core1 fp64 bit26 */
			{40981,36,0}, /* core1 fp64 bit27 */
			{40993,36,0}, /* core1 fp64 bit28 */
			{40992,36,0}, /* core1 fp64 bit29 */
			{40980,36,0}, /* core1 fp64 bit30 */
			{40971,36,0}, /* core1 fp64 bit31 */
			{41143,36,0}, /* core1 fp64 bit32 */
			{41142,36,0}, /* core1 fp64 bit33 */
			{41141,36,0}, /* core1 fp64 bit34 */
			{28127,36,0}, /* core1 fp64 bit35 */
			{41140,36,0}, /* core1 fp64 bit36 */
			{36435,36,0}, /* core1 fp64 bit37 */
			{41151,36,0}, /* core1 fp64 bit38 */
			{41150,36,0}, /* core1 fp64 bit39 */
			{41149,36,0}, /* core1 fp64 bit40 */
			{41148,36,0}, /* core1 fp64 bit41 */
			{41147,36,0}, /* core1 fp64 bit42 */
			{41146,36,0}, /* core1 fp64 bit43 */
			{41145,36,0}, /* core1 fp64 bit44 */
			{28114,36,0}, /* core1 fp64 bit45 */
			{36434,36,0}, /* core1 fp64 bit46 */
			{41144,36,0}, /* core1 fp64 bit47 */
			{28132,36,0}, /* core1 fp64 bit48 */
			{36455,36,0}, /* core1 fp64 bit49 */
			{41119,36,0}, /* core1 fp64 bit50 */
			{41118,36,0}, /* core1 fp64 bit51 */
			{41117,36,0}, /* core1 fp64 bit52 */
			{36454,36,0}, /* core1 fp64 bit53 */
			{41116,36,0}, /* core1 fp64 bit54 */
			{41135,36,0}, /* core1 fp64 bit55 */
			{41134,36,0}, /* core1 fp64 bit56 */
			{41133,36,0}, /* core1 fp64 bit57 */
			{41132,36,0}, /* core1 fp64 bit58 */
			{28131,36,0}, /* core1 fp64 bit59 */
			{41115,36,0}, /* core1 fp64 bit60 */
			{41114,36,0}, /* core1 fp64 bit61 */
			{41113,36,0}, /* core1 fp64 bit62 */
			{41112,36,0}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40942,36,0}, /* core1 sp_EL0 bit0 */
			{40941,36,0}, /* core1 sp_EL0 bit1 */
			{40940,36,0}, /* core1 sp_EL0 bit2 */
			{41010,36,0}, /* core1 sp_EL0 bit3 */
			{41009,36,0}, /* core1 sp_EL0 bit4 */
			{40939,36,0}, /* core1 sp_EL0 bit5 */
			{40938,36,0}, /* core1 sp_EL0 bit6 */
			{40937,36,0}, /* core1 sp_EL0 bit7 */
			{40936,36,0}, /* core1 sp_EL0 bit8 */
			{40931,36,0}, /* core1 sp_EL0 bit9 */
			{40947,36,0}, /* core1 sp_EL0 bit10 */
			{40930,36,0}, /* core1 sp_EL0 bit11 */
			{40929,36,0}, /* core1 sp_EL0 bit12 */
			{40928,36,0}, /* core1 sp_EL0 bit13 */
			{40951,36,0}, /* core1 sp_EL0 bit14 */
			{40950,36,0}, /* core1 sp_EL0 bit15 */
			{41008,36,0}, /* core1 sp_EL0 bit16 */
			{41015,36,0}, /* core1 sp_EL0 bit17 */
			{41014,36,0}, /* core1 sp_EL0 bit18 */
			{41011,36,0}, /* core1 sp_EL0 bit19 */
			{41013,36,0}, /* core1 sp_EL0 bit20 */
			{40946,36,0}, /* core1 sp_EL0 bit21 */
			{40949,36,0}, /* core1 sp_EL0 bit22 */
			{40945,36,0}, /* core1 sp_EL0 bit23 */
			{28259,36,0}, /* core1 sp_EL0 bit24 */
			{40944,36,0}, /* core1 sp_EL0 bit25 */
			{41012,36,0}, /* core1 sp_EL0 bit26 */
			{36257,36,0}, /* core1 sp_EL0 bit27 */
			{36347,36,0}, /* core1 sp_EL0 bit28 */
			{36346,36,0}, /* core1 sp_EL0 bit29 */
			{36256,36,0}, /* core1 sp_EL0 bit30 */
			{40943,36,0}, /* core1 sp_EL0 bit31 */
			{41063,36,0}, /* core1 sp_EL0 bit32 */
			{41059,36,0}, /* core1 sp_EL0 bit33 */
			{41058,36,0}, /* core1 sp_EL0 bit34 */
			{41062,36,0}, /* core1 sp_EL0 bit35 */
			{41061,36,0}, /* core1 sp_EL0 bit36 */
			{41057,36,0}, /* core1 sp_EL0 bit37 */
			{41060,36,0}, /* core1 sp_EL0 bit38 */
			{41071,36,0}, /* core1 sp_EL0 bit39 */
			{41070,36,0}, /* core1 sp_EL0 bit40 */
			{41069,36,0}, /* core1 sp_EL0 bit41 */
			{41056,36,0}, /* core1 sp_EL0 bit42 */
			{41068,36,0}, /* core1 sp_EL0 bit43 */
			{41067,36,0}, /* core1 sp_EL0 bit44 */
			{41066,36,0}, /* core1 sp_EL0 bit45 */
			{41065,36,0}, /* core1 sp_EL0 bit46 */
			{41064,36,0}, /* core1 sp_EL0 bit47 */
			{28157,36,0}, /* core1 sp_EL0 bit48 */
			{41103,36,0}, /* core1 sp_EL0 bit49 */
			{41102,36,0}, /* core1 sp_EL0 bit50 */
			{41101,36,0}, /* core1 sp_EL0 bit51 */
			{41100,36,0}, /* core1 sp_EL0 bit52 */
			{41107,36,0}, /* core1 sp_EL0 bit53 */
			{41106,36,0}, /* core1 sp_EL0 bit54 */
			{41105,36,0}, /* core1 sp_EL0 bit55 */
			{41104,36,0}, /* core1 sp_EL0 bit56 */
			{41055,36,0}, /* core1 sp_EL0 bit57 */
			{41054,36,0}, /* core1 sp_EL0 bit58 */
			{41053,36,0}, /* core1 sp_EL0 bit59 */
			{41052,36,0}, /* core1 sp_EL0 bit60 */
			{41111,36,0}, /* core1 sp_EL0 bit61 */
			{41110,36,0}, /* core1 sp_EL0 bit62 */
			{41109,36,0}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40935,36,0}, /* core1 sp_EL1 bit0 */
			{40934,36,0}, /* core1 sp_EL1 bit1 */
			{40902,36,0}, /* core1 sp_EL1 bit2 */
			{40882,36,0}, /* core1 sp_EL1 bit3 */
			{40881,36,0}, /* core1 sp_EL1 bit4 */
			{40933,36,0}, /* core1 sp_EL1 bit5 */
			{40901,36,0}, /* core1 sp_EL1 bit6 */
			{40932,36,0}, /* core1 sp_EL1 bit7 */
			{40900,36,0}, /* core1 sp_EL1 bit8 */
			{40927,36,0}, /* core1 sp_EL1 bit9 */
			{40926,36,0}, /* core1 sp_EL1 bit10 */
			{40923,36,0}, /* core1 sp_EL1 bit11 */
			{40922,36,0}, /* core1 sp_EL1 bit12 */
			{40921,36,0}, /* core1 sp_EL1 bit13 */
			{40920,36,0}, /* core1 sp_EL1 bit14 */
			{40925,36,0}, /* core1 sp_EL1 bit15 */
			{40880,36,0}, /* core1 sp_EL1 bit16 */
			{40879,36,0}, /* core1 sp_EL1 bit17 */
			{40878,36,0}, /* core1 sp_EL1 bit18 */
			{36259,36,0}, /* core1 sp_EL1 bit19 */
			{40877,36,0}, /* core1 sp_EL1 bit20 */
			{40924,36,0}, /* core1 sp_EL1 bit21 */
			{28258,36,0}, /* core1 sp_EL1 bit22 */
			{40899,36,0}, /* core1 sp_EL1 bit23 */
			{36258,36,0}, /* core1 sp_EL1 bit24 */
			{40898,36,0}, /* core1 sp_EL1 bit25 */
			{40883,36,0}, /* core1 sp_EL1 bit26 */
			{40897,36,0}, /* core1 sp_EL1 bit27 */
			{40876,36,0}, /* core1 sp_EL1 bit28 */
			{28244,36,0}, /* core1 sp_EL1 bit29 */
			{40896,36,0}, /* core1 sp_EL1 bit30 */
			{40903,36,0}, /* core1 sp_EL1 bit31 */
			{40803,36,0}, /* core1 sp_EL1 bit32 */
			{40799,36,0}, /* core1 sp_EL1 bit33 */
			{40798,36,0}, /* core1 sp_EL1 bit34 */
			{40802,36,0}, /* core1 sp_EL1 bit35 */
			{40801,36,0}, /* core1 sp_EL1 bit36 */
			{40797,36,0}, /* core1 sp_EL1 bit37 */
			{40800,36,0}, /* core1 sp_EL1 bit38 */
			{40791,36,0}, /* core1 sp_EL1 bit39 */
			{40790,36,0}, /* core1 sp_EL1 bit40 */
			{40789,36,0}, /* core1 sp_EL1 bit41 */
			{40796,36,0}, /* core1 sp_EL1 bit42 */
			{40788,36,0}, /* core1 sp_EL1 bit43 */
			{40795,36,0}, /* core1 sp_EL1 bit44 */
			{40794,36,0}, /* core1 sp_EL1 bit45 */
			{40792,36,0}, /* core1 sp_EL1 bit46 */
			{40793,36,0}, /* core1 sp_EL1 bit47 */
			{28158,36,0}, /* core1 sp_EL1 bit48 */
			{36423,36,0}, /* core1 sp_EL1 bit49 */
			{40839,36,0}, /* core1 sp_EL1 bit50 */
			{40838,36,0}, /* core1 sp_EL1 bit51 */
			{40837,36,0}, /* core1 sp_EL1 bit52 */
			{36422,36,0}, /* core1 sp_EL1 bit53 */
			{40836,36,0}, /* core1 sp_EL1 bit54 */
			{40831,36,0}, /* core1 sp_EL1 bit55 */
			{40830,36,0}, /* core1 sp_EL1 bit56 */
			{40829,36,0}, /* core1 sp_EL1 bit57 */
			{40828,36,0}, /* core1 sp_EL1 bit58 */
			{28159,36,0}, /* core1 sp_EL1 bit59 */
			{40835,36,0}, /* core1 sp_EL1 bit60 */
			{40834,36,0}, /* core1 sp_EL1 bit61 */
			{40833,36,0}, /* core1 sp_EL1 bit62 */
			{40832,36,0}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40906,36,0}, /* core1 sp_EL2 bit0 */
			{40905,36,0}, /* core1 sp_EL2 bit1 */
			{40904,36,0}, /* core1 sp_EL2 bit2 */
			{40886,36,0}, /* core1 sp_EL2 bit3 */
			{40891,36,0}, /* core1 sp_EL2 bit4 */
			{40911,36,0}, /* core1 sp_EL2 bit5 */
			{40910,36,0}, /* core1 sp_EL2 bit6 */
			{40909,36,0}, /* core1 sp_EL2 bit7 */
			{40908,36,0}, /* core1 sp_EL2 bit8 */
			{40919,36,0}, /* core1 sp_EL2 bit9 */
			{40915,36,0}, /* core1 sp_EL2 bit10 */
			{40918,36,0}, /* core1 sp_EL2 bit11 */
			{40917,36,0}, /* core1 sp_EL2 bit12 */
			{40916,36,0}, /* core1 sp_EL2 bit13 */
			{40895,36,0}, /* core1 sp_EL2 bit14 */
			{40894,36,0}, /* core1 sp_EL2 bit15 */
			{40885,36,0}, /* core1 sp_EL2 bit16 */
			{40884,36,0}, /* core1 sp_EL2 bit17 */
			{40890,36,0}, /* core1 sp_EL2 bit18 */
			{28260,36,0}, /* core1 sp_EL2 bit19 */
			{40889,36,0}, /* core1 sp_EL2 bit20 */
			{40914,36,0}, /* core1 sp_EL2 bit21 */
			{40893,36,0}, /* core1 sp_EL2 bit22 */
			{40913,36,0}, /* core1 sp_EL2 bit23 */
			{40888,36,0}, /* core1 sp_EL2 bit24 */
			{40912,36,0}, /* core1 sp_EL2 bit25 */
			{40887,36,0}, /* core1 sp_EL2 bit26 */
			{36261,36,0}, /* core1 sp_EL2 bit27 */
			{36255,36,0}, /* core1 sp_EL2 bit28 */
			{36254,36,0}, /* core1 sp_EL2 bit29 */
			{36260,36,0}, /* core1 sp_EL2 bit30 */
			{40907,36,0}, /* core1 sp_EL2 bit31 */
			{40811,36,0}, /* core1 sp_EL2 bit32 */
			{40810,36,0}, /* core1 sp_EL2 bit33 */
			{40809,36,0}, /* core1 sp_EL2 bit34 */
			{40808,36,0}, /* core1 sp_EL2 bit35 */
			{40783,36,0}, /* core1 sp_EL2 bit36 */
			{40782,36,0}, /* core1 sp_EL2 bit37 */
			{40781,36,0}, /* core1 sp_EL2 bit38 */
			{40780,36,0}, /* core1 sp_EL2 bit39 */
			{40787,36,0}, /* core1 sp_EL2 bit40 */
			{40786,36,0}, /* core1 sp_EL2 bit41 */
			{40785,36,0}, /* core1 sp_EL2 bit42 */
			{40784,36,0}, /* core1 sp_EL2 bit43 */
			{40755,36,0}, /* core1 sp_EL2 bit44 */
			{40754,36,0}, /* core1 sp_EL2 bit45 */
			{40752,36,0}, /* core1 sp_EL2 bit46 */
			{40753,36,0}, /* core1 sp_EL2 bit47 */
			{28170,36,0}, /* core1 sp_EL2 bit48 */
			{28161,36,0}, /* core1 sp_EL2 bit49 */
			{40847,36,0}, /* core1 sp_EL2 bit50 */
			{40846,36,0}, /* core1 sp_EL2 bit51 */
			{40845,36,0}, /* core1 sp_EL2 bit52 */
			{40844,36,0}, /* core1 sp_EL2 bit53 */
			{40843,36,0}, /* core1 sp_EL2 bit54 */
			{40842,36,0}, /* core1 sp_EL2 bit55 */
			{40841,36,0}, /* core1 sp_EL2 bit56 */
			{40840,36,0}, /* core1 sp_EL2 bit57 */
			{40815,36,0}, /* core1 sp_EL2 bit58 */
			{40814,36,0}, /* core1 sp_EL2 bit59 */
			{40813,36,0}, /* core1 sp_EL2 bit60 */
			{40812,36,0}, /* core1 sp_EL2 bit61 */
			{36421,36,0}, /* core1 sp_EL2 bit62 */
			{36420,36,0}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40861,36,0}, /* core1 sp_EL3 bit0 */
			{40860,36,0}, /* core1 sp_EL3 bit1 */
			{40739,36,0}, /* core1 sp_EL3 bit2 */
			{40875,36,0}, /* core1 sp_EL3 bit3 */
			{40874,36,0}, /* core1 sp_EL3 bit4 */
			{40738,36,0}, /* core1 sp_EL3 bit5 */
			{40737,36,0}, /* core1 sp_EL3 bit6 */
			{40736,36,0}, /* core1 sp_EL3 bit7 */
			{40867,36,0}, /* core1 sp_EL3 bit8 */
			{40866,36,0}, /* core1 sp_EL3 bit9 */
			{40865,36,0}, /* core1 sp_EL3 bit10 */
			{40864,36,0}, /* core1 sp_EL3 bit11 */
			{40743,36,0}, /* core1 sp_EL3 bit12 */
			{40742,36,0}, /* core1 sp_EL3 bit13 */
			{40741,36,0}, /* core1 sp_EL3 bit14 */
			{40740,36,0}, /* core1 sp_EL3 bit15 */
			{40873,36,0}, /* core1 sp_EL3 bit16 */
			{40872,36,0}, /* core1 sp_EL3 bit17 */
			{40871,36,0}, /* core1 sp_EL3 bit18 */
			{40863,36,0}, /* core1 sp_EL3 bit19 */
			{40870,36,0}, /* core1 sp_EL3 bit20 */
			{40735,36,0}, /* core1 sp_EL3 bit21 */
			{40734,36,0}, /* core1 sp_EL3 bit22 */
			{40733,36,0}, /* core1 sp_EL3 bit23 */
			{28185,36,0}, /* core1 sp_EL3 bit24 */
			{40732,36,0}, /* core1 sp_EL3 bit25 */
			{40869,36,0}, /* core1 sp_EL3 bit26 */
			{36251,36,0}, /* core1 sp_EL3 bit27 */
			{40868,36,0}, /* core1 sp_EL3 bit28 */
			{28186,36,0}, /* core1 sp_EL3 bit29 */
			{36250,36,0}, /* core1 sp_EL3 bit30 */
			{40862,36,0}, /* core1 sp_EL3 bit31 */
			{40807,36,0}, /* core1 sp_EL3 bit32 */
			{40806,36,0}, /* core1 sp_EL3 bit33 */
			{40805,36,0}, /* core1 sp_EL3 bit34 */
			{40804,36,0}, /* core1 sp_EL3 bit35 */
			{40763,36,0}, /* core1 sp_EL3 bit36 */
			{40762,36,0}, /* core1 sp_EL3 bit37 */
			{40761,36,0}, /* core1 sp_EL3 bit38 */
			{40760,36,0}, /* core1 sp_EL3 bit39 */
			{40767,36,0}, /* core1 sp_EL3 bit40 */
			{40766,36,0}, /* core1 sp_EL3 bit41 */
			{40765,36,0}, /* core1 sp_EL3 bit42 */
			{40764,36,0}, /* core1 sp_EL3 bit43 */
			{40759,36,0}, /* core1 sp_EL3 bit44 */
			{40758,36,0}, /* core1 sp_EL3 bit45 */
			{40756,36,0}, /* core1 sp_EL3 bit46 */
			{40757,36,0}, /* core1 sp_EL3 bit47 */
			{28172,36,0}, /* core1 sp_EL3 bit48 */
			{36425,36,0}, /* core1 sp_EL3 bit49 */
			{40827,36,0}, /* core1 sp_EL3 bit50 */
			{40826,36,0}, /* core1 sp_EL3 bit51 */
			{40825,36,0}, /* core1 sp_EL3 bit52 */
			{40824,36,0}, /* core1 sp_EL3 bit53 */
			{40823,36,0}, /* core1 sp_EL3 bit54 */
			{40822,36,0}, /* core1 sp_EL3 bit55 */
			{40821,36,0}, /* core1 sp_EL3 bit56 */
			{40820,36,0}, /* core1 sp_EL3 bit57 */
			{40819,36,0}, /* core1 sp_EL3 bit58 */
			{36424,36,0}, /* core1 sp_EL3 bit59 */
			{40818,36,0}, /* core1 sp_EL3 bit60 */
			{40817,36,0}, /* core1 sp_EL3 bit61 */
			{40816,36,0}, /* core1 sp_EL3 bit62 */
			{28160,36,0}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{40707,36,0}, /* core1 elr_EL1 bit0 */
			{40706,36,0}, /* core1 elr_EL1 bit1 */
			{40705,36,0}, /* core1 elr_EL1 bit2 */
			{40723,36,0}, /* core1 elr_EL1 bit3 */
			{40722,36,0}, /* core1 elr_EL1 bit4 */
			{40704,36,0}, /* core1 elr_EL1 bit5 */
			{40703,36,0}, /* core1 elr_EL1 bit6 */
			{40702,36,0}, /* core1 elr_EL1 bit7 */
			{40701,36,0}, /* core1 elr_EL1 bit8 */
			{40700,36,0}, /* core1 elr_EL1 bit9 */
			{40695,36,0}, /* core1 elr_EL1 bit10 */
			{40694,36,0}, /* core1 elr_EL1 bit11 */
			{40693,36,0}, /* core1 elr_EL1 bit12 */
			{40692,36,0}, /* core1 elr_EL1 bit13 */
			{40699,36,0}, /* core1 elr_EL1 bit14 */
			{40698,36,0}, /* core1 elr_EL1 bit15 */
			{40721,36,0}, /* core1 elr_EL1 bit16 */
			{40720,36,0}, /* core1 elr_EL1 bit17 */
			{40727,36,0}, /* core1 elr_EL1 bit18 */
			{40697,36,0}, /* core1 elr_EL1 bit19 */
			{40726,36,0}, /* core1 elr_EL1 bit20 */
			{40696,36,0}, /* core1 elr_EL1 bit21 */
			{40715,36,0}, /* core1 elr_EL1 bit22 */
			{40714,36,0}, /* core1 elr_EL1 bit23 */
			{28252,36,0}, /* core1 elr_EL1 bit24 */
			{40713,36,0}, /* core1 elr_EL1 bit25 */
			{40725,36,0}, /* core1 elr_EL1 bit26 */
			{40712,36,0}, /* core1 elr_EL1 bit27 */
			{40724,36,0}, /* core1 elr_EL1 bit28 */
			{28251,36,0}, /* core1 elr_EL1 bit29 */
			{36265,36,0}, /* core1 elr_EL1 bit30 */
			{36264,36,0}, /* core1 elr_EL1 bit31 */
			{40751,36,0}, /* core1 elr_EL1 bit32 */
			{40750,36,0}, /* core1 elr_EL1 bit33 */
			{40749,36,0}, /* core1 elr_EL1 bit34 */
			{40748,36,0}, /* core1 elr_EL1 bit35 */
			{40771,36,0}, /* core1 elr_EL1 bit36 */
			{40770,36,0}, /* core1 elr_EL1 bit37 */
			{40769,36,0}, /* core1 elr_EL1 bit38 */
			{40768,36,0}, /* core1 elr_EL1 bit39 */
			{40775,36,0}, /* core1 elr_EL1 bit40 */
			{40774,36,0}, /* core1 elr_EL1 bit41 */
			{40773,36,0}, /* core1 elr_EL1 bit42 */
			{40772,36,0}, /* core1 elr_EL1 bit43 */
			{40779,36,0}, /* core1 elr_EL1 bit44 */
			{40778,36,0}, /* core1 elr_EL1 bit45 */
			{40777,36,0}, /* core1 elr_EL1 bit46 */
			{40776,36,0}, /* core1 elr_EL1 bit47 */
			{28165,36,0}, /* core1 elr_EL1 bit48 */
			{40859,36,0}, /* core1 elr_EL1 bit49 */
			{40858,36,0}, /* core1 elr_EL1 bit50 */
			{40857,36,0}, /* core1 elr_EL1 bit51 */
			{40856,36,0}, /* core1 elr_EL1 bit52 */
			{40855,36,0}, /* core1 elr_EL1 bit53 */
			{40854,36,0}, /* core1 elr_EL1 bit54 */
			{40853,36,0}, /* core1 elr_EL1 bit55 */
			{40852,36,0}, /* core1 elr_EL1 bit56 */
			{40747,36,0}, /* core1 elr_EL1 bit57 */
			{40746,36,0}, /* core1 elr_EL1 bit58 */
			{40745,36,0}, /* core1 elr_EL1 bit59 */
			{40744,36,0}, /* core1 elr_EL1 bit60 */
			{40851,36,0}, /* core1 elr_EL1 bit61 */
			{40850,36,0}, /* core1 elr_EL1 bit62 */
			{40849,36,0}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{40711,36,0}, /* core1 elr_EL2 bit0 */
			{40710,36,0}, /* core1 elr_EL2 bit1 */
			{40709,36,0}, /* core1 elr_EL2 bit2 */
			{40719,36,0}, /* core1 elr_EL2 bit3 */
			{40718,36,0}, /* core1 elr_EL2 bit4 */
			{40708,36,0}, /* core1 elr_EL2 bit5 */
			{40687,36,0}, /* core1 elr_EL2 bit6 */
			{40691,36,0}, /* core1 elr_EL2 bit7 */
			{40690,36,0}, /* core1 elr_EL2 bit8 */
			{40689,36,0}, /* core1 elr_EL2 bit9 */
			{40686,36,0}, /* core1 elr_EL2 bit10 */
			{40688,36,0}, /* core1 elr_EL2 bit11 */
			{40683,36,0}, /* core1 elr_EL2 bit12 */
			{40682,36,0}, /* core1 elr_EL2 bit13 */
			{40681,36,0}, /* core1 elr_EL2 bit14 */
			{40685,36,0}, /* core1 elr_EL2 bit15 */
			{40717,36,0}, /* core1 elr_EL2 bit16 */
			{40716,36,0}, /* core1 elr_EL2 bit17 */
			{40731,36,0}, /* core1 elr_EL2 bit18 */
			{40684,36,0}, /* core1 elr_EL2 bit19 */
			{40730,36,0}, /* core1 elr_EL2 bit20 */
			{40679,36,0}, /* core1 elr_EL2 bit21 */
			{40680,36,0}, /* core1 elr_EL2 bit22 */
			{40678,36,0}, /* core1 elr_EL2 bit23 */
			{28253,36,0}, /* core1 elr_EL2 bit24 */
			{40677,36,0}, /* core1 elr_EL2 bit25 */
			{40729,36,0}, /* core1 elr_EL2 bit26 */
			{40676,36,0}, /* core1 elr_EL2 bit27 */
			{40728,36,0}, /* core1 elr_EL2 bit28 */
			{28254,36,0}, /* core1 elr_EL2 bit29 */
			{28255,36,0}, /* core1 elr_EL2 bit30 */
			{28256,36,0}, /* core1 elr_EL2 bit31 */
			{40501,36,0}, /* core1 elr_EL2 bit32 */
			{40500,36,0}, /* core1 elr_EL2 bit33 */
			{40499,36,0}, /* core1 elr_EL2 bit34 */
			{40498,36,0}, /* core1 elr_EL2 bit35 */
			{40481,36,0}, /* core1 elr_EL2 bit36 */
			{40480,36,0}, /* core1 elr_EL2 bit37 */
			{40479,36,0}, /* core1 elr_EL2 bit38 */
			{40478,36,0}, /* core1 elr_EL2 bit39 */
			{40477,36,0}, /* core1 elr_EL2 bit40 */
			{40476,36,0}, /* core1 elr_EL2 bit41 */
			{40475,36,0}, /* core1 elr_EL2 bit42 */
			{40474,36,0}, /* core1 elr_EL2 bit43 */
			{40485,36,0}, /* core1 elr_EL2 bit44 */
			{40484,36,0}, /* core1 elr_EL2 bit45 */
			{40483,36,0}, /* core1 elr_EL2 bit46 */
			{40482,36,0}, /* core1 elr_EL2 bit47 */
			{28164,36,0}, /* core1 elr_EL2 bit48 */
			{40509,36,0}, /* core1 elr_EL2 bit49 */
			{40508,36,0}, /* core1 elr_EL2 bit50 */
			{40507,36,0}, /* core1 elr_EL2 bit51 */
			{40506,36,0}, /* core1 elr_EL2 bit52 */
			{40465,36,0}, /* core1 elr_EL2 bit53 */
			{40464,36,0}, /* core1 elr_EL2 bit54 */
			{40463,36,0}, /* core1 elr_EL2 bit55 */
			{40462,36,0}, /* core1 elr_EL2 bit56 */
			{40473,36,0}, /* core1 elr_EL2 bit57 */
			{40472,36,0}, /* core1 elr_EL2 bit58 */
			{40471,36,0}, /* core1 elr_EL2 bit59 */
			{40470,36,0}, /* core1 elr_EL2 bit60 */
			{40469,36,0}, /* core1 elr_EL2 bit61 */
			{40468,36,0}, /* core1 elr_EL2 bit62 */
			{40467,36,0}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{40452,36,0}, /* core1 elr_EL3 bit0 */
			{40451,36,0}, /* core1 elr_EL3 bit1 */
			{40450,36,0}, /* core1 elr_EL3 bit2 */
			{40437,36,0}, /* core1 elr_EL3 bit3 */
			{40436,36,0}, /* core1 elr_EL3 bit4 */
			{40441,36,0}, /* core1 elr_EL3 bit5 */
			{40440,36,0}, /* core1 elr_EL3 bit6 */
			{40439,36,0}, /* core1 elr_EL3 bit7 */
			{40438,36,0}, /* core1 elr_EL3 bit8 */
			{40449,36,0}, /* core1 elr_EL3 bit9 */
			{40448,36,0}, /* core1 elr_EL3 bit10 */
			{40447,36,0}, /* core1 elr_EL3 bit11 */
			{40446,36,0}, /* core1 elr_EL3 bit12 */
			{40457,36,0}, /* core1 elr_EL3 bit13 */
			{40456,36,0}, /* core1 elr_EL3 bit14 */
			{40455,36,0}, /* core1 elr_EL3 bit15 */
			{40435,36,0}, /* core1 elr_EL3 bit16 */
			{40434,36,0}, /* core1 elr_EL3 bit17 */
			{40461,36,0}, /* core1 elr_EL3 bit18 */
			{40445,36,0}, /* core1 elr_EL3 bit19 */
			{40460,36,0}, /* core1 elr_EL3 bit20 */
			{40444,36,0}, /* core1 elr_EL3 bit21 */
			{40454,36,0}, /* core1 elr_EL3 bit22 */
			{40443,36,0}, /* core1 elr_EL3 bit23 */
			{28245,36,0}, /* core1 elr_EL3 bit24 */
			{40442,36,0}, /* core1 elr_EL3 bit25 */
			{40459,36,0}, /* core1 elr_EL3 bit26 */
			{36263,36,0}, /* core1 elr_EL3 bit27 */
			{40458,36,0}, /* core1 elr_EL3 bit28 */
			{28246,36,0}, /* core1 elr_EL3 bit29 */
			{36262,36,0}, /* core1 elr_EL3 bit30 */
			{40453,36,0}, /* core1 elr_EL3 bit31 */
			{40505,36,0}, /* core1 elr_EL3 bit32 */
			{40504,36,0}, /* core1 elr_EL3 bit33 */
			{40503,36,0}, /* core1 elr_EL3 bit34 */
			{40493,36,0}, /* core1 elr_EL3 bit35 */
			{40492,36,0}, /* core1 elr_EL3 bit36 */
			{40502,36,0}, /* core1 elr_EL3 bit37 */
			{40491,36,0}, /* core1 elr_EL3 bit38 */
			{40490,36,0}, /* core1 elr_EL3 bit39 */
			{40489,36,0}, /* core1 elr_EL3 bit40 */
			{40488,36,0}, /* core1 elr_EL3 bit41 */
			{40497,36,0}, /* core1 elr_EL3 bit42 */
			{40487,36,0}, /* core1 elr_EL3 bit43 */
			{40496,36,0}, /* core1 elr_EL3 bit44 */
			{40495,36,0}, /* core1 elr_EL3 bit45 */
			{36215,36,0}, /* core1 elr_EL3 bit46 */
			{40494,36,0}, /* core1 elr_EL3 bit47 */
			{36214,36,0}, /* core1 elr_EL3 bit48 */
			{40517,36,0}, /* core1 elr_EL3 bit49 */
			{40516,36,0}, /* core1 elr_EL3 bit50 */
			{40515,36,0}, /* core1 elr_EL3 bit51 */
			{40514,36,0}, /* core1 elr_EL3 bit52 */
			{40521,36,0}, /* core1 elr_EL3 bit53 */
			{40520,36,0}, /* core1 elr_EL3 bit54 */
			{40519,36,0}, /* core1 elr_EL3 bit55 */
			{40518,36,0}, /* core1 elr_EL3 bit56 */
			{40513,36,0}, /* core1 elr_EL3 bit57 */
			{40512,36,0}, /* core1 elr_EL3 bit58 */
			{40511,36,0}, /* core1 elr_EL3 bit59 */
			{40510,36,0}, /* core1 elr_EL3 bit60 */
			{40433,36,0}, /* core1 elr_EL3 bit61 */
			{40432,36,0}, /* core1 elr_EL3 bit62 */
			{40431,36,0}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{30898,36,0}, /* core1 raw_pc bit0 */
			{33534,35,0}, /* core1 raw_pc bit1 */
			{33533,35,0}, /* core1 raw_pc bit2 */
			{33532,35,0}, /* core1 raw_pc bit3 */
			{33531,35,0}, /* core1 raw_pc bit4 */
			{37455,36,0}, /* core1 raw_pc bit5 */
			{37454,36,0}, /* core1 raw_pc bit6 */
			{37453,36,0}, /* core1 raw_pc bit7 */
			{37452,36,0}, /* core1 raw_pc bit8 */
			{37451,36,0}, /* core1 raw_pc bit9 */
			{37450,36,0}, /* core1 raw_pc bit10 */
			{37447,36,0}, /* core1 raw_pc bit11 */
			{37446,36,0}, /* core1 raw_pc bit12 */
			{37449,36,0}, /* core1 raw_pc bit13 */
			{37448,36,0}, /* core1 raw_pc bit14 */
			{33538,35,0}, /* core1 raw_pc bit15 */
			{33537,35,0}, /* core1 raw_pc bit16 */
			{33536,35,0}, /* core1 raw_pc bit17 */
			{33535,35,0}, /* core1 raw_pc bit18 */
			{33542,35,0}, /* core1 raw_pc bit19 */
			{33541,35,0}, /* core1 raw_pc bit20 */
			{33540,35,0}, /* core1 raw_pc bit21 */
			{33539,35,0}, /* core1 raw_pc bit22 */
			{33546,35,0}, /* core1 raw_pc bit23 */
			{33545,35,0}, /* core1 raw_pc bit24 */
			{33544,35,0}, /* core1 raw_pc bit25 */
			{33543,35,0}, /* core1 raw_pc bit26 */
			{33482,35,0}, /* core1 raw_pc bit27 */
			{33481,35,0}, /* core1 raw_pc bit28 */
			{33480,35,0}, /* core1 raw_pc bit29 */
			{33479,35,0}, /* core1 raw_pc bit30 */
			{33606,35,0}, /* core1 raw_pc bit31 */
			{33605,35,0}, /* core1 raw_pc bit32 */
			{33604,35,0}, /* core1 raw_pc bit33 */
			{33603,35,0}, /* core1 raw_pc bit34 */
			{37245,36,0}, /* core1 raw_pc bit35 */
			{37244,36,0}, /* core1 raw_pc bit36 */
			{37249,36,0}, /* core1 raw_pc bit37 */
			{37248,36,0}, /* core1 raw_pc bit38 */
			{33602,35,0}, /* core1 raw_pc bit39 */
			{33601,35,0}, /* core1 raw_pc bit40 */
			{33600,35,0}, /* core1 raw_pc bit41 */
			{33599,35,0}, /* core1 raw_pc bit42 */
			{37247,36,0}, /* core1 raw_pc bit43 */
			{37246,36,0}, /* core1 raw_pc bit44 */
			{37251,36,0}, /* core1 raw_pc bit45 */
			{37250,36,0}, /* core1 raw_pc bit46 */
			{33598,35,0}, /* core1 raw_pc bit47 */
			{33597,35,0}, /* core1 raw_pc bit48 */
			{33596,35,0}, /* core1 raw_pc bit49 */
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
			{33491,35,0}, /* core1 pc_iss bit0 */
			{33498,35,0}, /* core1 pc_iss bit1 */
			{33497,35,0}, /* core1 pc_iss bit2 */
			{33496,35,0}, /* core1 pc_iss bit3 */
			{33495,35,0}, /* core1 pc_iss bit4 */
			{33494,35,0}, /* core1 pc_iss bit5 */
			{33493,35,0}, /* core1 pc_iss bit6 */
			{33492,35,0}, /* core1 pc_iss bit7 */
			{33522,35,0}, /* core1 pc_iss bit8 */
			{33521,35,0}, /* core1 pc_iss bit9 */
			{33520,35,0}, /* core1 pc_iss bit10 */
			{33519,35,0}, /* core1 pc_iss bit11 */
			{33470,35,0}, /* core1 pc_iss bit12 */
			{33469,35,0}, /* core1 pc_iss bit13 */
			{33468,35,0}, /* core1 pc_iss bit14 */
			{33467,35,0}, /* core1 pc_iss bit15 */
			{33526,35,0}, /* core1 pc_iss bit16 */
			{33525,35,0}, /* core1 pc_iss bit17 */
			{33524,35,0}, /* core1 pc_iss bit18 */
			{33523,35,0}, /* core1 pc_iss bit19 */
			{33530,35,0}, /* core1 pc_iss bit20 */
			{33529,35,0}, /* core1 pc_iss bit21 */
			{33528,35,0}, /* core1 pc_iss bit22 */
			{33527,35,0}, /* core1 pc_iss bit23 */
			{33474,35,0}, /* core1 pc_iss bit24 */
			{33473,35,0}, /* core1 pc_iss bit25 */
			{33472,35,0}, /* core1 pc_iss bit26 */
			{33471,35,0}, /* core1 pc_iss bit27 */
			{33478,35,0}, /* core1 pc_iss bit28 */
			{33477,35,0}, /* core1 pc_iss bit29 */
			{33476,35,0}, /* core1 pc_iss bit30 */
			{33475,35,0}, /* core1 pc_iss bit31 */
			{33631,35,0}, /* core1 pc_iss bit32 */
			{33618,35,0}, /* core1 pc_iss bit33 */
			{33617,35,0}, /* core1 pc_iss bit34 */
			{33616,35,0}, /* core1 pc_iss bit35 */
			{33621,35,0}, /* core1 pc_iss bit36 */
			{33615,35,0}, /* core1 pc_iss bit37 */
			{33620,35,0}, /* core1 pc_iss bit38 */
			{33619,35,0}, /* core1 pc_iss bit39 */
			{33614,35,0}, /* core1 pc_iss bit40 */
			{33613,35,0}, /* core1 pc_iss bit41 */
			{33610,35,0}, /* core1 pc_iss bit42 */
			{33612,35,0}, /* core1 pc_iss bit43 */
			{33611,35,0}, /* core1 pc_iss bit44 */
			{33630,35,0}, /* core1 pc_iss bit45 */
			{33629,35,0}, /* core1 pc_iss bit46 */
			{33609,35,0}, /* core1 pc_iss bit47 */
			{33628,35,0}, /* core1 pc_iss bit48 */
			{33627,35,0}, /* core1 pc_iss bit49 */
			{33626,35,0}, /* core1 pc_iss bit50 */
			{33625,35,0}, /* core1 pc_iss bit51 */
			{33624,35,0}, /* core1 pc_iss bit52 */
			{33622,35,0}, /* core1 pc_iss bit53 */
			{33623,35,0}, /* core1 pc_iss bit54 */
			{33634,35,0}, /* core1 pc_iss bit55 */
			{33633,35,0}, /* core1 pc_iss bit56 */
			{33632,35,0}, /* core1 pc_iss bit57 */
			{33608,35,0}, /* core1 pc_iss bit58 */
			{33607,35,0}, /* core1 pc_iss bit59 */
			{33638,35,0}, /* core1 pc_iss bit60 */
			{33637,35,0}, /* core1 pc_iss bit61 */
			{33636,35,0}, /* core1 pc_iss bit62 */
			{33635,35,0}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{30897,36,0}, /* core1 full_pc_wr bit0 */
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
			{30971,36,0}, /* core1 full_pc_ex1 bit0 */
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
			{30942,36,0}, /* core1 full_pc_ex2 bit0 */
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
			{16598,36,0}, /* core1 return_Stack_pointer bit0 */
			{16597,36,0}, /* core1 return_Stack_pointer bit1 */
			{13720,36,0}, /* core1 return_Stack_pointer bit2 */
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
			{23469,36,0}, /* core1 return_Stack0 bit0 */
			{23468,36,0}, /* core1 return_Stack0 bit1 */
			{23467,36,0}, /* core1 return_Stack0 bit2 */
			{23449,36,0}, /* core1 return_Stack0 bit3 */
			{23448,36,0}, /* core1 return_Stack0 bit4 */
			{23447,36,0}, /* core1 return_Stack0 bit5 */
			{23446,36,0}, /* core1 return_Stack0 bit6 */
			{23365,36,0}, /* core1 return_Stack0 bit7 */
			{23364,36,0}, /* core1 return_Stack0 bit8 */
			{23363,36,0}, /* core1 return_Stack0 bit9 */
			{23466,36,0}, /* core1 return_Stack0 bit10 */
			{23417,36,0}, /* core1 return_Stack0 bit11 */
			{23416,36,0}, /* core1 return_Stack0 bit12 */
			{23415,36,0}, /* core1 return_Stack0 bit13 */
			{23414,36,0}, /* core1 return_Stack0 bit14 */
			{23369,36,0}, /* core1 return_Stack0 bit15 */
			{23368,36,0}, /* core1 return_Stack0 bit16 */
			{23367,36,0}, /* core1 return_Stack0 bit17 */
			{23366,36,0}, /* core1 return_Stack0 bit18 */
			{23421,36,0}, /* core1 return_Stack0 bit19 */
			{23420,36,0}, /* core1 return_Stack0 bit20 */
			{23419,36,0}, /* core1 return_Stack0 bit21 */
			{23418,36,0}, /* core1 return_Stack0 bit22 */
			{23465,36,1}, /* core1 return_Stack0 bit23 */
			{23464,36,1}, /* core1 return_Stack0 bit24 */
			{23463,36,1}, /* core1 return_Stack0 bit25 */
			{23462,36,1}, /* core1 return_Stack0 bit26 */
			{23385,36,1}, /* core1 return_Stack0 bit27 */
			{23384,36,1}, /* core1 return_Stack0 bit28 */
			{23383,36,1}, /* core1 return_Stack0 bit29 */
			{23382,36,1}, /* core1 return_Stack0 bit30 */
			{13706,36,0}, /* core1 return_Stack0 bit31 */
			{23381,36,0}, /* core1 return_Stack0 bit32 */
			{23380,36,0}, /* core1 return_Stack0 bit33 */
			{23379,36,0}, /* core1 return_Stack0 bit34 */
			{23378,36,0}, /* core1 return_Stack0 bit35 */
			{23413,36,1}, /* core1 return_Stack0 bit36 */
			{23412,36,1}, /* core1 return_Stack0 bit37 */
			{23411,36,1}, /* core1 return_Stack0 bit38 */
			{23410,36,1}, /* core1 return_Stack0 bit39 */
			{23405,36,0}, /* core1 return_Stack0 bit40 */
			{23404,36,0}, /* core1 return_Stack0 bit41 */
			{23403,36,0}, /* core1 return_Stack0 bit42 */
			{23402,36,0}, /* core1 return_Stack0 bit43 */
			{23409,36,1}, /* core1 return_Stack0 bit44 */
			{23408,36,1}, /* core1 return_Stack0 bit45 */
			{23407,36,1}, /* core1 return_Stack0 bit46 */
			{23406,36,1}, /* core1 return_Stack0 bit47 */
			{13707,36,0}, /* core1 return_Stack0 bit48 */
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
			{23461,36,0}, /* core1 return_Stack1 bit0 */
			{23460,36,0}, /* core1 return_Stack1 bit1 */
			{23459,36,0}, /* core1 return_Stack1 bit2 */
			{23445,36,0}, /* core1 return_Stack1 bit3 */
			{23444,36,0}, /* core1 return_Stack1 bit4 */
			{23443,36,0}, /* core1 return_Stack1 bit5 */
			{23442,36,0}, /* core1 return_Stack1 bit6 */
			{23441,36,0}, /* core1 return_Stack1 bit7 */
			{23440,36,0}, /* core1 return_Stack1 bit8 */
			{23439,36,0}, /* core1 return_Stack1 bit9 */
			{23458,36,0}, /* core1 return_Stack1 bit10 */
			{23425,36,0}, /* core1 return_Stack1 bit11 */
			{23424,36,0}, /* core1 return_Stack1 bit12 */
			{23423,36,0}, /* core1 return_Stack1 bit13 */
			{23422,36,0}, /* core1 return_Stack1 bit14 */
			{23373,36,0}, /* core1 return_Stack1 bit15 */
			{23372,36,0}, /* core1 return_Stack1 bit16 */
			{23371,36,0}, /* core1 return_Stack1 bit17 */
			{23370,36,0}, /* core1 return_Stack1 bit18 */
			{23429,36,0}, /* core1 return_Stack1 bit19 */
			{23428,36,0}, /* core1 return_Stack1 bit20 */
			{23427,36,0}, /* core1 return_Stack1 bit21 */
			{23426,36,0}, /* core1 return_Stack1 bit22 */
			{23393,36,1}, /* core1 return_Stack1 bit23 */
			{23392,36,1}, /* core1 return_Stack1 bit24 */
			{23391,36,1}, /* core1 return_Stack1 bit25 */
			{23390,36,1}, /* core1 return_Stack1 bit26 */
			{23389,36,1}, /* core1 return_Stack1 bit27 */
			{23388,36,1}, /* core1 return_Stack1 bit28 */
			{23387,36,1}, /* core1 return_Stack1 bit29 */
			{23386,36,1}, /* core1 return_Stack1 bit30 */
			{13711,36,0}, /* core1 return_Stack1 bit31 */
			{23377,36,0}, /* core1 return_Stack1 bit32 */
			{23376,36,0}, /* core1 return_Stack1 bit33 */
			{23375,36,0}, /* core1 return_Stack1 bit34 */
			{23374,36,0}, /* core1 return_Stack1 bit35 */
			{23453,36,1}, /* core1 return_Stack1 bit36 */
			{23452,36,1}, /* core1 return_Stack1 bit37 */
			{23451,36,1}, /* core1 return_Stack1 bit38 */
			{23450,36,1}, /* core1 return_Stack1 bit39 */
			{23401,36,0}, /* core1 return_Stack1 bit40 */
			{23400,36,0}, /* core1 return_Stack1 bit41 */
			{23399,36,0}, /* core1 return_Stack1 bit42 */
			{23398,36,0}, /* core1 return_Stack1 bit43 */
			{23457,36,1}, /* core1 return_Stack1 bit44 */
			{23456,36,1}, /* core1 return_Stack1 bit45 */
			{23455,36,1}, /* core1 return_Stack1 bit46 */
			{23454,36,1}, /* core1 return_Stack1 bit47 */
			{13705,36,0}, /* core1 return_Stack1 bit48 */
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
			{23397,36,0}, /* core1 return_Stack2 bit0 */
			{23396,36,0}, /* core1 return_Stack2 bit1 */
			{23395,36,0}, /* core1 return_Stack2 bit2 */
			{23437,36,0}, /* core1 return_Stack2 bit3 */
			{23436,36,0}, /* core1 return_Stack2 bit4 */
			{23435,36,0}, /* core1 return_Stack2 bit5 */
			{23434,36,0}, /* core1 return_Stack2 bit6 */
			{23361,36,0}, /* core1 return_Stack2 bit7 */
			{23360,36,0}, /* core1 return_Stack2 bit8 */
			{23359,36,0}, /* core1 return_Stack2 bit9 */
			{23394,36,0}, /* core1 return_Stack2 bit10 */
			{23433,36,0}, /* core1 return_Stack2 bit11 */
			{23432,36,0}, /* core1 return_Stack2 bit12 */
			{23431,36,0}, /* core1 return_Stack2 bit13 */
			{23430,36,0}, /* core1 return_Stack2 bit14 */
			{23357,36,1}, /* core1 return_Stack2 bit15 */
			{23356,36,1}, /* core1 return_Stack2 bit16 */
			{23355,36,1}, /* core1 return_Stack2 bit17 */
			{23354,36,1}, /* core1 return_Stack2 bit18 */
			{23216,36,0}, /* core1 return_Stack2 bit19 */
			{23215,36,0}, /* core1 return_Stack2 bit20 */
			{23214,36,0}, /* core1 return_Stack2 bit21 */
			{23213,36,0}, /* core1 return_Stack2 bit22 */
			{23312,36,1}, /* core1 return_Stack2 bit23 */
			{23311,36,1}, /* core1 return_Stack2 bit24 */
			{23310,36,1}, /* core1 return_Stack2 bit25 */
			{23309,36,1}, /* core1 return_Stack2 bit26 */
			{23128,36,1}, /* core1 return_Stack2 bit27 */
			{23127,36,1}, /* core1 return_Stack2 bit28 */
			{23126,36,1}, /* core1 return_Stack2 bit29 */
			{23125,36,1}, /* core1 return_Stack2 bit30 */
			{13712,36,0}, /* core1 return_Stack2 bit31 */
			{23152,36,1}, /* core1 return_Stack2 bit32 */
			{23151,36,1}, /* core1 return_Stack2 bit33 */
			{23150,36,1}, /* core1 return_Stack2 bit34 */
			{23149,36,1}, /* core1 return_Stack2 bit35 */
			{23244,36,1}, /* core1 return_Stack2 bit36 */
			{23243,36,1}, /* core1 return_Stack2 bit37 */
			{23242,36,1}, /* core1 return_Stack2 bit38 */
			{23241,36,1}, /* core1 return_Stack2 bit39 */
			{23308,36,1}, /* core1 return_Stack2 bit40 */
			{23307,36,1}, /* core1 return_Stack2 bit41 */
			{23306,36,1}, /* core1 return_Stack2 bit42 */
			{23305,36,1}, /* core1 return_Stack2 bit43 */
			{23256,36,1}, /* core1 return_Stack2 bit44 */
			{23255,36,1}, /* core1 return_Stack2 bit45 */
			{23254,36,1}, /* core1 return_Stack2 bit46 */
			{23253,36,1}, /* core1 return_Stack2 bit47 */
			{13713,36,0}, /* core1 return_Stack2 bit48 */
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
			{23332,36,0}, /* core1 return_Stack3 bit0 */
			{23331,36,0}, /* core1 return_Stack3 bit1 */
			{23330,36,0}, /* core1 return_Stack3 bit2 */
			{23204,36,0}, /* core1 return_Stack3 bit3 */
			{23203,36,0}, /* core1 return_Stack3 bit4 */
			{23202,36,0}, /* core1 return_Stack3 bit5 */
			{23201,36,0}, /* core1 return_Stack3 bit6 */
			{23168,36,0}, /* core1 return_Stack3 bit7 */
			{23167,36,0}, /* core1 return_Stack3 bit8 */
			{23166,36,0}, /* core1 return_Stack3 bit9 */
			{23329,36,0}, /* core1 return_Stack3 bit10 */
			{23228,36,0}, /* core1 return_Stack3 bit11 */
			{23227,36,0}, /* core1 return_Stack3 bit12 */
			{23226,36,0}, /* core1 return_Stack3 bit13 */
			{23225,36,0}, /* core1 return_Stack3 bit14 */
			{23160,36,1}, /* core1 return_Stack3 bit15 */
			{23159,36,1}, /* core1 return_Stack3 bit16 */
			{23158,36,1}, /* core1 return_Stack3 bit17 */
			{23157,36,1}, /* core1 return_Stack3 bit18 */
			{23224,36,0}, /* core1 return_Stack3 bit19 */
			{23223,36,0}, /* core1 return_Stack3 bit20 */
			{23222,36,0}, /* core1 return_Stack3 bit21 */
			{23221,36,0}, /* core1 return_Stack3 bit22 */
			{23340,36,1}, /* core1 return_Stack3 bit23 */
			{23339,36,1}, /* core1 return_Stack3 bit24 */
			{23338,36,1}, /* core1 return_Stack3 bit25 */
			{23337,36,1}, /* core1 return_Stack3 bit26 */
			{23124,36,1}, /* core1 return_Stack3 bit27 */
			{23123,36,1}, /* core1 return_Stack3 bit28 */
			{23122,36,1}, /* core1 return_Stack3 bit29 */
			{23121,36,1}, /* core1 return_Stack3 bit30 */
			{13714,36,0}, /* core1 return_Stack3 bit31 */
			{23148,36,1}, /* core1 return_Stack3 bit32 */
			{23147,36,1}, /* core1 return_Stack3 bit33 */
			{23146,36,1}, /* core1 return_Stack3 bit34 */
			{23145,36,1}, /* core1 return_Stack3 bit35 */
			{23272,36,1}, /* core1 return_Stack3 bit36 */
			{23271,36,1}, /* core1 return_Stack3 bit37 */
			{23270,36,1}, /* core1 return_Stack3 bit38 */
			{23269,36,1}, /* core1 return_Stack3 bit39 */
			{23320,36,1}, /* core1 return_Stack3 bit40 */
			{23319,36,1}, /* core1 return_Stack3 bit41 */
			{23318,36,1}, /* core1 return_Stack3 bit42 */
			{23317,36,1}, /* core1 return_Stack3 bit43 */
			{23264,36,1}, /* core1 return_Stack3 bit44 */
			{23263,36,1}, /* core1 return_Stack3 bit45 */
			{23262,36,1}, /* core1 return_Stack3 bit46 */
			{23261,36,1}, /* core1 return_Stack3 bit47 */
			{13717,36,0}, /* core1 return_Stack3 bit48 */
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
			{23352,36,0}, /* core1 return_Stack4 bit0 */
			{23351,36,0}, /* core1 return_Stack4 bit1 */
			{23350,36,0}, /* core1 return_Stack4 bit2 */
			{23268,36,0}, /* core1 return_Stack4 bit3 */
			{23267,36,0}, /* core1 return_Stack4 bit4 */
			{23266,36,0}, /* core1 return_Stack4 bit5 */
			{23265,36,0}, /* core1 return_Stack4 bit6 */
			{23180,36,0}, /* core1 return_Stack4 bit7 */
			{23179,36,0}, /* core1 return_Stack4 bit8 */
			{23178,36,0}, /* core1 return_Stack4 bit9 */
			{23349,36,0}, /* core1 return_Stack4 bit10 */
			{23288,36,0}, /* core1 return_Stack4 bit11 */
			{23287,36,0}, /* core1 return_Stack4 bit12 */
			{23286,36,0}, /* core1 return_Stack4 bit13 */
			{23285,36,0}, /* core1 return_Stack4 bit14 */
			{23184,36,0}, /* core1 return_Stack4 bit15 */
			{23183,36,0}, /* core1 return_Stack4 bit16 */
			{23182,36,0}, /* core1 return_Stack4 bit17 */
			{23181,36,0}, /* core1 return_Stack4 bit18 */
			{23284,36,0}, /* core1 return_Stack4 bit19 */
			{23283,36,0}, /* core1 return_Stack4 bit20 */
			{23282,36,0}, /* core1 return_Stack4 bit21 */
			{23281,36,0}, /* core1 return_Stack4 bit22 */
			{23344,36,1}, /* core1 return_Stack4 bit23 */
			{23343,36,1}, /* core1 return_Stack4 bit24 */
			{23342,36,1}, /* core1 return_Stack4 bit25 */
			{23341,36,1}, /* core1 return_Stack4 bit26 */
			{23116,36,1}, /* core1 return_Stack4 bit27 */
			{23115,36,1}, /* core1 return_Stack4 bit28 */
			{23114,36,1}, /* core1 return_Stack4 bit29 */
			{23113,36,1}, /* core1 return_Stack4 bit30 */
			{13708,36,0}, /* core1 return_Stack4 bit31 */
			{23140,36,0}, /* core1 return_Stack4 bit32 */
			{23139,36,0}, /* core1 return_Stack4 bit33 */
			{23138,36,0}, /* core1 return_Stack4 bit34 */
			{23137,36,0}, /* core1 return_Stack4 bit35 */
			{23292,36,1}, /* core1 return_Stack4 bit36 */
			{23291,36,1}, /* core1 return_Stack4 bit37 */
			{23290,36,1}, /* core1 return_Stack4 bit38 */
			{23289,36,1}, /* core1 return_Stack4 bit39 */
			{23300,36,0}, /* core1 return_Stack4 bit40 */
			{23299,36,0}, /* core1 return_Stack4 bit41 */
			{23298,36,0}, /* core1 return_Stack4 bit42 */
			{23297,36,0}, /* core1 return_Stack4 bit43 */
			{23296,36,1}, /* core1 return_Stack4 bit44 */
			{23295,36,1}, /* core1 return_Stack4 bit45 */
			{23294,36,1}, /* core1 return_Stack4 bit46 */
			{23293,36,1}, /* core1 return_Stack4 bit47 */
			{13709,36,0}, /* core1 return_Stack4 bit48 */
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
			{23348,36,0}, /* core1 return_Stack5 bit0 */
			{23347,36,0}, /* core1 return_Stack5 bit1 */
			{23346,36,0}, /* core1 return_Stack5 bit2 */
			{23196,36,0}, /* core1 return_Stack5 bit3 */
			{23195,36,0}, /* core1 return_Stack5 bit4 */
			{23194,36,0}, /* core1 return_Stack5 bit5 */
			{23193,36,0}, /* core1 return_Stack5 bit6 */
			{23192,36,0}, /* core1 return_Stack5 bit7 */
			{23191,36,0}, /* core1 return_Stack5 bit8 */
			{23190,36,0}, /* core1 return_Stack5 bit9 */
			{23345,36,0}, /* core1 return_Stack5 bit10 */
			{23240,36,0}, /* core1 return_Stack5 bit11 */
			{23239,36,0}, /* core1 return_Stack5 bit12 */
			{23238,36,0}, /* core1 return_Stack5 bit13 */
			{23237,36,0}, /* core1 return_Stack5 bit14 */
			{23188,36,0}, /* core1 return_Stack5 bit15 */
			{23187,36,0}, /* core1 return_Stack5 bit16 */
			{23186,36,0}, /* core1 return_Stack5 bit17 */
			{23185,36,0}, /* core1 return_Stack5 bit18 */
			{23280,36,0}, /* core1 return_Stack5 bit19 */
			{23279,36,0}, /* core1 return_Stack5 bit20 */
			{23278,36,0}, /* core1 return_Stack5 bit21 */
			{23277,36,0}, /* core1 return_Stack5 bit22 */
			{23112,36,1}, /* core1 return_Stack5 bit23 */
			{23111,36,1}, /* core1 return_Stack5 bit24 */
			{23110,36,1}, /* core1 return_Stack5 bit25 */
			{23109,36,1}, /* core1 return_Stack5 bit26 */
			{23120,36,1}, /* core1 return_Stack5 bit27 */
			{23119,36,1}, /* core1 return_Stack5 bit28 */
			{23118,36,1}, /* core1 return_Stack5 bit29 */
			{23117,36,1}, /* core1 return_Stack5 bit30 */
			{13710,36,0}, /* core1 return_Stack5 bit31 */
			{23136,36,0}, /* core1 return_Stack5 bit32 */
			{23135,36,0}, /* core1 return_Stack5 bit33 */
			{23134,36,0}, /* core1 return_Stack5 bit34 */
			{23133,36,0}, /* core1 return_Stack5 bit35 */
			{23248,36,1}, /* core1 return_Stack5 bit36 */
			{23247,36,1}, /* core1 return_Stack5 bit37 */
			{23246,36,1}, /* core1 return_Stack5 bit38 */
			{23245,36,1}, /* core1 return_Stack5 bit39 */
			{23304,36,0}, /* core1 return_Stack5 bit40 */
			{23303,36,0}, /* core1 return_Stack5 bit41 */
			{23302,36,0}, /* core1 return_Stack5 bit42 */
			{23301,36,0}, /* core1 return_Stack5 bit43 */
			{23252,36,1}, /* core1 return_Stack5 bit44 */
			{23251,36,1}, /* core1 return_Stack5 bit45 */
			{23250,36,1}, /* core1 return_Stack5 bit46 */
			{23249,36,1}, /* core1 return_Stack5 bit47 */
			{13704,36,0}, /* core1 return_Stack5 bit48 */
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
			{23324,36,0}, /* core1 return_Stack6 bit0 */
			{23323,36,0}, /* core1 return_Stack6 bit1 */
			{23322,36,0}, /* core1 return_Stack6 bit2 */
			{23208,36,0}, /* core1 return_Stack6 bit3 */
			{23207,36,0}, /* core1 return_Stack6 bit4 */
			{23206,36,0}, /* core1 return_Stack6 bit5 */
			{23205,36,0}, /* core1 return_Stack6 bit6 */
			{23176,36,0}, /* core1 return_Stack6 bit7 */
			{23175,36,0}, /* core1 return_Stack6 bit8 */
			{23174,36,0}, /* core1 return_Stack6 bit9 */
			{23321,36,0}, /* core1 return_Stack6 bit10 */
			{23212,36,0}, /* core1 return_Stack6 bit11 */
			{23211,36,0}, /* core1 return_Stack6 bit12 */
			{23210,36,0}, /* core1 return_Stack6 bit13 */
			{23209,36,0}, /* core1 return_Stack6 bit14 */
			{23164,36,1}, /* core1 return_Stack6 bit15 */
			{23163,36,1}, /* core1 return_Stack6 bit16 */
			{23162,36,1}, /* core1 return_Stack6 bit17 */
			{23161,36,1}, /* core1 return_Stack6 bit18 */
			{23220,36,0}, /* core1 return_Stack6 bit19 */
			{23219,36,0}, /* core1 return_Stack6 bit20 */
			{23218,36,0}, /* core1 return_Stack6 bit21 */
			{23217,36,0}, /* core1 return_Stack6 bit22 */
			{23316,36,1}, /* core1 return_Stack6 bit23 */
			{23315,36,1}, /* core1 return_Stack6 bit24 */
			{23314,36,1}, /* core1 return_Stack6 bit25 */
			{23313,36,1}, /* core1 return_Stack6 bit26 */
			{23132,36,1}, /* core1 return_Stack6 bit27 */
			{23131,36,1}, /* core1 return_Stack6 bit28 */
			{23130,36,1}, /* core1 return_Stack6 bit29 */
			{23129,36,1}, /* core1 return_Stack6 bit30 */
			{13718,36,0}, /* core1 return_Stack6 bit31 */
			{23144,36,0}, /* core1 return_Stack6 bit32 */
			{23143,36,0}, /* core1 return_Stack6 bit33 */
			{23142,36,0}, /* core1 return_Stack6 bit34 */
			{23141,36,0}, /* core1 return_Stack6 bit35 */
			{23276,36,1}, /* core1 return_Stack6 bit36 */
			{23275,36,1}, /* core1 return_Stack6 bit37 */
			{23274,36,1}, /* core1 return_Stack6 bit38 */
			{23273,36,1}, /* core1 return_Stack6 bit39 */
			{23328,36,1}, /* core1 return_Stack6 bit40 */
			{23327,36,1}, /* core1 return_Stack6 bit41 */
			{23326,36,1}, /* core1 return_Stack6 bit42 */
			{23325,36,1}, /* core1 return_Stack6 bit43 */
			{23260,36,1}, /* core1 return_Stack6 bit44 */
			{23259,36,1}, /* core1 return_Stack6 bit45 */
			{23258,36,1}, /* core1 return_Stack6 bit46 */
			{23257,36,1}, /* core1 return_Stack6 bit47 */
			{13719,36,0}, /* core1 return_Stack6 bit48 */
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
			{23336,36,0}, /* core1 return_Stack7 bit0 */
			{23335,36,0}, /* core1 return_Stack7 bit1 */
			{23334,36,0}, /* core1 return_Stack7 bit2 */
			{23200,36,0}, /* core1 return_Stack7 bit3 */
			{23199,36,0}, /* core1 return_Stack7 bit4 */
			{23198,36,0}, /* core1 return_Stack7 bit5 */
			{23197,36,0}, /* core1 return_Stack7 bit6 */
			{23172,36,0}, /* core1 return_Stack7 bit7 */
			{23171,36,0}, /* core1 return_Stack7 bit8 */
			{23170,36,0}, /* core1 return_Stack7 bit9 */
			{23333,36,0}, /* core1 return_Stack7 bit10 */
			{23236,36,0}, /* core1 return_Stack7 bit11 */
			{23235,36,0}, /* core1 return_Stack7 bit12 */
			{23234,36,0}, /* core1 return_Stack7 bit13 */
			{23233,36,0}, /* core1 return_Stack7 bit14 */
			{23156,36,1}, /* core1 return_Stack7 bit15 */
			{23155,36,1}, /* core1 return_Stack7 bit16 */
			{23154,36,1}, /* core1 return_Stack7 bit17 */
			{23153,36,1}, /* core1 return_Stack7 bit18 */
			{23232,36,0}, /* core1 return_Stack7 bit19 */
			{23231,36,0}, /* core1 return_Stack7 bit20 */
			{23230,36,0}, /* core1 return_Stack7 bit21 */
			{23229,36,0}, /* core1 return_Stack7 bit22 */
			{23108,36,1}, /* core1 return_Stack7 bit23 */
			{23107,36,1}, /* core1 return_Stack7 bit24 */
			{23106,36,1}, /* core1 return_Stack7 bit25 */
			{23105,36,1}, /* core1 return_Stack7 bit26 */
			{23035,36,1}, /* core1 return_Stack7 bit27 */
			{23034,36,1}, /* core1 return_Stack7 bit28 */
			{23033,36,1}, /* core1 return_Stack7 bit29 */
			{23032,36,1}, /* core1 return_Stack7 bit30 */
			{13715,36,0}, /* core1 return_Stack7 bit31 */
			{23031,36,1}, /* core1 return_Stack7 bit32 */
			{23030,36,1}, /* core1 return_Stack7 bit33 */
			{23029,36,1}, /* core1 return_Stack7 bit34 */
			{23028,36,1}, /* core1 return_Stack7 bit35 */
			{23023,36,1}, /* core1 return_Stack7 bit36 */
			{23022,36,1}, /* core1 return_Stack7 bit37 */
			{23021,36,1}, /* core1 return_Stack7 bit38 */
			{23020,36,1}, /* core1 return_Stack7 bit39 */
			{23039,36,1}, /* core1 return_Stack7 bit40 */
			{23038,36,1}, /* core1 return_Stack7 bit41 */
			{23037,36,1}, /* core1 return_Stack7 bit42 */
			{23036,36,1}, /* core1 return_Stack7 bit43 */
			{23027,36,1}, /* core1 return_Stack7 bit44 */
			{23026,36,1}, /* core1 return_Stack7 bit45 */
			{23025,36,1}, /* core1 return_Stack7 bit46 */
			{23024,36,1}, /* core1 return_Stack7 bit47 */
			{13716,36,0}, /* core1 return_Stack7 bit48 */
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
			.L2_parity_err = {{
			{ 7910,35,0}, /* core1 L2_parity_err bit0 */
			{    0, 0,2}, /* core1 L2_parity_err bit1 */
			{    0, 0,2}, /* core1 L2_parity_err bit2 */
			{    0, 0,2}, /* core1 L2_parity_err bit3 */
			{    0, 0,2}, /* core1 L2_parity_err bit4 */
			{    0, 0,2}, /* core1 L2_parity_err bit5 */
			{    0, 0,2}, /* core1 L2_parity_err bit6 */
			{    0, 0,2}, /* core1 L2_parity_err bit7 */
			{    0, 0,2}, /* core1 L2_parity_err bit8 */
			{    0, 0,2}, /* core1 L2_parity_err bit9 */
			{    0, 0,2}, /* core1 L2_parity_err bit10 */
			{    0, 0,2}, /* core1 L2_parity_err bit11 */
			{    0, 0,2}, /* core1 L2_parity_err bit12 */
			{    0, 0,2}, /* core1 L2_parity_err bit13 */
			{    0, 0,2}, /* core1 L2_parity_err bit14 */
			{    0, 0,2}, /* core1 L2_parity_err bit15 */
			{    0, 0,2}, /* core1 L2_parity_err bit16 */
			{    0, 0,2}, /* core1 L2_parity_err bit17 */
			{    0, 0,2}, /* core1 L2_parity_err bit18 */
			{    0, 0,2}, /* core1 L2_parity_err bit19 */
			{    0, 0,2}, /* core1 L2_parity_err bit20 */
			{    0, 0,2}, /* core1 L2_parity_err bit21 */
			{    0, 0,2}, /* core1 L2_parity_err bit22 */
			{    0, 0,2}, /* core1 L2_parity_err bit23 */
			{    0, 0,2}, /* core1 L2_parity_err bit24 */
			{    0, 0,2}, /* core1 L2_parity_err bit25 */
			{    0, 0,2}, /* core1 L2_parity_err bit26 */
			{    0, 0,2}, /* core1 L2_parity_err bit27 */
			{    0, 0,2}, /* core1 L2_parity_err bit28 */
			{    0, 0,2}, /* core1 L2_parity_err bit29 */
			{    0, 0,2}, /* core1 L2_parity_err bit30 */
			{    0, 0,2}, /* core1 L2_parity_err bit31 */
			{    0, 0,2}, /* core1 L2_parity_err bit32 */
			{    0, 0,2}, /* core1 L2_parity_err bit33 */
			{    0, 0,2}, /* core1 L2_parity_err bit34 */
			{    0, 0,2}, /* core1 L2_parity_err bit35 */
			{    0, 0,2}, /* core1 L2_parity_err bit36 */
			{    0, 0,2}, /* core1 L2_parity_err bit37 */
			{    0, 0,2}, /* core1 L2_parity_err bit38 */
			{    0, 0,2}, /* core1 L2_parity_err bit39 */
			{    0, 0,2}, /* core1 L2_parity_err bit40 */
			{    0, 0,2}, /* core1 L2_parity_err bit41 */
			{    0, 0,2}, /* core1 L2_parity_err bit42 */
			{    0, 0,2}, /* core1 L2_parity_err bit43 */
			{    0, 0,2}, /* core1 L2_parity_err bit44 */
			{    0, 0,2}, /* core1 L2_parity_err bit45 */
			{    0, 0,2}, /* core1 L2_parity_err bit46 */
			{    0, 0,2}, /* core1 L2_parity_err bit47 */
			{    0, 0,2}, /* core1 L2_parity_err bit48 */
			{    0, 0,2}, /* core1 L2_parity_err bit49 */
			{    0, 0,2}, /* core1 L2_parity_err bit50 */
			{    0, 0,2}, /* core1 L2_parity_err bit51 */
			{    0, 0,2}, /* core1 L2_parity_err bit52 */
			{    0, 0,2}, /* core1 L2_parity_err bit53 */
			{    0, 0,2}, /* core1 L2_parity_err bit54 */
			{    0, 0,2}, /* core1 L2_parity_err bit55 */
			{    0, 0,2}, /* core1 L2_parity_err bit56 */
			{    0, 0,2}, /* core1 L2_parity_err bit57 */
			{    0, 0,2}, /* core1 L2_parity_err bit58 */
			{    0, 0,2}, /* core1 L2_parity_err bit59 */
			{    0, 0,2}, /* core1 L2_parity_err bit60 */
			{    0, 0,2}, /* core1 L2_parity_err bit61 */
			{    0, 0,2}, /* core1 L2_parity_err bit62 */
			{    0, 0,2}, /* core1 L2_parity_err bit63 */
			}},
			.L2_parity_err_count = {{
			{13805,35,1}, /* core1 L2_parity_err_count bit0 */
			{13804,35,1}, /* core1 L2_parity_err_count bit1 */
			{13803,35,1}, /* core1 L2_parity_err_count bit2 */
			{13810,35,0}, /* core1 L2_parity_err_count bit3 */
			{13809,35,0}, /* core1 L2_parity_err_count bit4 */
			{13808,35,0}, /* core1 L2_parity_err_count bit5 */
			{13807,35,0}, /* core1 L2_parity_err_count bit6 */
			{ 7911,35,0}, /* core1 L2_parity_err_count bit7 */
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
			{14288,35,0}, /* core1 L2_parity_index bit0 */
			{14287,35,0}, /* core1 L2_parity_index bit1 */
			{14286,35,0}, /* core1 L2_parity_index bit2 */
			{14285,35,0}, /* core1 L2_parity_index bit3 */
			{14284,35,0}, /* core1 L2_parity_index bit4 */
			{14283,35,0}, /* core1 L2_parity_index bit5 */
			{14282,35,0}, /* core1 L2_parity_index bit6 */
			{14281,35,0}, /* core1 L2_parity_index bit7 */
			{ 7821,35,0}, /* core1 L2_parity_index bit8 */
			{    0, 0,2}, /* core1 L2_parity_index bit9 */
			{    0, 0,2}, /* core1 L2_parity_index bit10 */
			{    0, 0,2}, /* core1 L2_parity_index bit11 */
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
			{10378,35,0}, /* core1 L2_parity_way bit0 */
			{10377,35,0}, /* core1 L2_parity_way bit1 */
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
			{14280,35,0}, /* core1 L2_parity_banks bit0 */
			{14279,35,0}, /* core1 L2_parity_banks bit1 */
			{14278,35,0}, /* core1 L2_parity_banks bit2 */
			{14277,35,0}, /* core1 L2_parity_banks bit3 */
			{14272,35,0}, /* core1 L2_parity_banks bit4 */
			{14271,35,0}, /* core1 L2_parity_banks bit5 */
			{14270,35,0}, /* core1 L2_parity_banks bit6 */
			{14269,35,0}, /* core1 L2_parity_banks bit7 */
			{14292,35,0}, /* core1 L2_parity_banks bit8 */
			{14291,35,0}, /* core1 L2_parity_banks bit9 */
			{14290,35,0}, /* core1 L2_parity_banks bit10 */
			{14289,35,0}, /* core1 L2_parity_banks bit11 */
			{14276,35,0}, /* core1 L2_parity_banks bit12 */
			{14275,35,0}, /* core1 L2_parity_banks bit13 */
			{14274,35,0}, /* core1 L2_parity_banks bit14 */
			{14273,35,0}, /* core1 L2_parity_banks bit15 */
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
			{  192,37,0}, /* core2 pc bit0 */
			{  191,37,0}, /* core2 pc bit1 */
			{  190,37,0}, /* core2 pc bit2 */
			{  189,37,0}, /* core2 pc bit3 */
			{  142,37,0}, /* core2 pc bit4 */
			{  141,37,0}, /* core2 pc bit5 */
			{  140,37,0}, /* core2 pc bit6 */
			{  139,37,0}, /* core2 pc bit7 */
			{  146,37,0}, /* core2 pc bit8 */
			{  145,37,0}, /* core2 pc bit9 */
			{  144,37,0}, /* core2 pc bit10 */
			{  143,37,0}, /* core2 pc bit11 */
			{  150,37,0}, /* core2 pc bit12 */
			{  149,37,0}, /* core2 pc bit13 */
			{  148,37,0}, /* core2 pc bit14 */
			{  147,37,0}, /* core2 pc bit15 */
			{  126,37,0}, /* core2 pc bit16 */
			{  125,37,0}, /* core2 pc bit17 */
			{  124,37,0}, /* core2 pc bit18 */
			{  123,37,0}, /* core2 pc bit19 */
			{  134,37,0}, /* core2 pc bit20 */
			{  133,37,0}, /* core2 pc bit21 */
			{  132,37,0}, /* core2 pc bit22 */
			{  131,37,0}, /* core2 pc bit23 */
			{  138,37,0}, /* core2 pc bit24 */
			{  137,37,0}, /* core2 pc bit25 */
			{  136,37,0}, /* core2 pc bit26 */
			{  135,37,0}, /* core2 pc bit27 */
			{  130,37,0}, /* core2 pc bit28 */
			{  129,37,0}, /* core2 pc bit29 */
			{  128,37,0}, /* core2 pc bit30 */
			{  127,37,0}, /* core2 pc bit31 */
			{  240,37,0}, /* core2 pc bit32 */
			{  239,37,0}, /* core2 pc bit33 */
			{  238,37,0}, /* core2 pc bit34 */
			{  237,37,0}, /* core2 pc bit35 */
			{  248,37,0}, /* core2 pc bit36 */
			{  247,37,0}, /* core2 pc bit37 */
			{  246,37,0}, /* core2 pc bit38 */
			{  245,37,0}, /* core2 pc bit39 */
			{  244,37,0}, /* core2 pc bit40 */
			{  243,37,0}, /* core2 pc bit41 */
			{  242,37,0}, /* core2 pc bit42 */
			{  241,37,0}, /* core2 pc bit43 */
			{  216,37,0}, /* core2 pc bit44 */
			{  215,37,0}, /* core2 pc bit45 */
			{  214,37,0}, /* core2 pc bit46 */
			{  213,37,0}, /* core2 pc bit47 */
			{  180,37,0}, /* core2 pc bit48 */
			{  179,37,0}, /* core2 pc bit49 */
			{  178,37,0}, /* core2 pc bit50 */
			{  177,37,0}, /* core2 pc bit51 */
			{  184,37,0}, /* core2 pc bit52 */
			{  183,37,0}, /* core2 pc bit53 */
			{  182,37,0}, /* core2 pc bit54 */
			{  181,37,0}, /* core2 pc bit55 */
			{  236,37,0}, /* core2 pc bit56 */
			{  235,37,0}, /* core2 pc bit57 */
			{  234,37,0}, /* core2 pc bit58 */
			{  233,37,0}, /* core2 pc bit59 */
			{  188,37,0}, /* core2 pc bit60 */
			{  187,37,0}, /* core2 pc bit61 */
			{  186,37,0}, /* core2 pc bit62 */
			{  185,37,0}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{41807,38,0}, /* core2 sp32 bit0 */
			{41871,38,0}, /* core2 sp32 bit1 */
			{41806,38,0}, /* core2 sp32 bit2 */
			{41805,38,0}, /* core2 sp32 bit3 */
			{41804,38,0}, /* core2 sp32 bit4 */
			{41855,38,0}, /* core2 sp32 bit5 */
			{41854,38,0}, /* core2 sp32 bit6 */
			{41853,38,0}, /* core2 sp32 bit7 */
			{41852,38,0}, /* core2 sp32 bit8 */
			{41859,38,0}, /* core2 sp32 bit9 */
			{41858,38,0}, /* core2 sp32 bit10 */
			{41857,38,0}, /* core2 sp32 bit11 */
			{41856,38,0}, /* core2 sp32 bit12 */
			{41867,38,0}, /* core2 sp32 bit13 */
			{41866,38,0}, /* core2 sp32 bit14 */
			{41865,38,0}, /* core2 sp32 bit15 */
			{41864,38,0}, /* core2 sp32 bit16 */
			{41679,38,0}, /* core2 sp32 bit17 */
			{41678,38,0}, /* core2 sp32 bit18 */
			{41870,38,0}, /* core2 sp32 bit19 */
			{41677,38,0}, /* core2 sp32 bit20 */
			{41676,38,0}, /* core2 sp32 bit21 */
			{41671,38,0}, /* core2 sp32 bit22 */
			{41670,38,0}, /* core2 sp32 bit23 */
			{41669,38,0}, /* core2 sp32 bit24 */
			{41668,38,0}, /* core2 sp32 bit25 */
			{41869,38,0}, /* core2 sp32 bit26 */
			{41667,38,0}, /* core2 sp32 bit27 */
			{41666,38,0}, /* core2 sp32 bit28 */
			{41665,38,0}, /* core2 sp32 bit29 */
			{41664,38,0}, /* core2 sp32 bit30 */
			{41868,38,0}, /* core2 sp32 bit31 */
			{41483,38,0}, /* core2 sp32 bit32 */
			{41482,38,0}, /* core2 sp32 bit33 */
			{41481,38,0}, /* core2 sp32 bit34 */
			{41480,38,0}, /* core2 sp32 bit35 */
			{36299,38,0}, /* core2 sp32 bit36 */
			{28101,38,0}, /* core2 sp32 bit37 */
			{36298,38,0}, /* core2 sp32 bit38 */
			{41535,38,0}, /* core2 sp32 bit39 */
			{41534,38,0}, /* core2 sp32 bit40 */
			{41533,38,0}, /* core2 sp32 bit41 */
			{41532,38,0}, /* core2 sp32 bit42 */
			{41479,38,0}, /* core2 sp32 bit43 */
			{41478,38,0}, /* core2 sp32 bit44 */
			{41477,38,0}, /* core2 sp32 bit45 */
			{41476,38,0}, /* core2 sp32 bit46 */
			{36277,38,0}, /* core2 sp32 bit47 */
			{36276,38,0}, /* core2 sp32 bit48 */
			{41531,38,0}, /* core2 sp32 bit49 */
			{41530,38,0}, /* core2 sp32 bit50 */
			{41529,38,0}, /* core2 sp32 bit51 */
			{41528,38,0}, /* core2 sp32 bit52 */
			{41523,38,0}, /* core2 sp32 bit53 */
			{41522,38,0}, /* core2 sp32 bit54 */
			{41521,38,0}, /* core2 sp32 bit55 */
			{41520,38,0}, /* core2 sp32 bit56 */
			{41527,38,0}, /* core2 sp32 bit57 */
			{41526,38,0}, /* core2 sp32 bit58 */
			{41525,38,0}, /* core2 sp32 bit59 */
			{41524,38,0}, /* core2 sp32 bit60 */
			{41519,38,0}, /* core2 sp32 bit61 */
			{41518,38,0}, /* core2 sp32 bit62 */
			{41517,38,0}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{42038,38,0}, /* core2 fp32 bit0 */
			{42037,38,0}, /* core2 fp32 bit1 */
			{42021,38,0}, /* core2 fp32 bit2 */
			{42020,38,0}, /* core2 fp32 bit3 */
			{42036,38,0}, /* core2 fp32 bit4 */
			{42043,38,0}, /* core2 fp32 bit5 */
			{42042,38,0}, /* core2 fp32 bit6 */
			{42041,38,0}, /* core2 fp32 bit7 */
			{42040,38,0}, /* core2 fp32 bit8 */
			{42027,38,0}, /* core2 fp32 bit9 */
			{42031,38,0}, /* core2 fp32 bit10 */
			{42030,38,0}, /* core2 fp32 bit11 */
			{42029,38,0}, /* core2 fp32 bit12 */
			{42028,38,0}, /* core2 fp32 bit13 */
			{42015,38,0}, /* core2 fp32 bit14 */
			{42014,38,0}, /* core2 fp32 bit15 */
			{42026,38,0}, /* core2 fp32 bit16 */
			{42013,38,0}, /* core2 fp32 bit17 */
			{42035,38,0}, /* core2 fp32 bit18 */
			{42034,38,0}, /* core2 fp32 bit19 */
			{42033,38,0}, /* core2 fp32 bit20 */
			{42012,38,0}, /* core2 fp32 bit21 */
			{42019,38,0}, /* core2 fp32 bit22 */
			{42018,38,0}, /* core2 fp32 bit23 */
			{42017,38,0}, /* core2 fp32 bit24 */
			{42032,38,0}, /* core2 fp32 bit25 */
			{42016,38,0}, /* core2 fp32 bit26 */
			{42023,38,0}, /* core2 fp32 bit27 */
			{42025,38,0}, /* core2 fp32 bit28 */
			{42022,38,0}, /* core2 fp32 bit29 */
			{42024,38,0}, /* core2 fp32 bit30 */
			{42039,38,0}, /* core2 fp32 bit31 */
			{42143,38,0}, /* core2 fp32 bit32 */
			{42142,38,0}, /* core2 fp32 bit33 */
			{42141,38,0}, /* core2 fp32 bit34 */
			{42140,38,0}, /* core2 fp32 bit35 */
			{42135,38,0}, /* core2 fp32 bit36 */
			{42134,38,0}, /* core2 fp32 bit37 */
			{42133,38,0}, /* core2 fp32 bit38 */
			{42132,38,0}, /* core2 fp32 bit39 */
			{42131,38,0}, /* core2 fp32 bit40 */
			{42130,38,0}, /* core2 fp32 bit41 */
			{42129,38,0}, /* core2 fp32 bit42 */
			{42128,38,0}, /* core2 fp32 bit43 */
			{42139,38,0}, /* core2 fp32 bit44 */
			{42138,38,0}, /* core2 fp32 bit45 */
			{42137,38,0}, /* core2 fp32 bit46 */
			{42136,38,0}, /* core2 fp32 bit47 */
			{28149,38,0}, /* core2 fp32 bit48 */
			{42151,38,0}, /* core2 fp32 bit49 */
			{42150,38,0}, /* core2 fp32 bit50 */
			{42149,38,0}, /* core2 fp32 bit51 */
			{42148,38,0}, /* core2 fp32 bit52 */
			{42155,38,0}, /* core2 fp32 bit53 */
			{42154,38,0}, /* core2 fp32 bit54 */
			{42153,38,0}, /* core2 fp32 bit55 */
			{42152,38,0}, /* core2 fp32 bit56 */
			{42147,38,0}, /* core2 fp32 bit57 */
			{42146,38,0}, /* core2 fp32 bit58 */
			{42145,38,0}, /* core2 fp32 bit59 */
			{42144,38,0}, /* core2 fp32 bit60 */
			{42159,38,0}, /* core2 fp32 bit61 */
			{42158,38,0}, /* core2 fp32 bit62 */
			{42157,38,0}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{40979,38,0}, /* core2 fp64 bit0 */
			{40978,38,0}, /* core2 fp64 bit1 */
			{28248,38,0}, /* core2 fp64 bit2 */
			{40999,38,0}, /* core2 fp64 bit3 */
			{36342,38,0}, /* core2 fp64 bit4 */
			{40977,38,0}, /* core2 fp64 bit5 */
			{40970,38,0}, /* core2 fp64 bit6 */
			{40976,38,0}, /* core2 fp64 bit7 */
			{40969,38,0}, /* core2 fp64 bit8 */
			{40968,38,0}, /* core2 fp64 bit9 */
			{40975,38,0}, /* core2 fp64 bit10 */
			{40974,38,0}, /* core2 fp64 bit11 */
			{40987,38,0}, /* core2 fp64 bit12 */
			{40986,38,0}, /* core2 fp64 bit13 */
			{40985,38,0}, /* core2 fp64 bit14 */
			{40973,38,0}, /* core2 fp64 bit15 */
			{40998,38,0}, /* core2 fp64 bit16 */
			{40997,38,0}, /* core2 fp64 bit17 */
			{40996,38,0}, /* core2 fp64 bit18 */
			{36343,38,0}, /* core2 fp64 bit19 */
			{40995,38,0}, /* core2 fp64 bit20 */
			{40972,38,0}, /* core2 fp64 bit21 */
			{40984,38,0}, /* core2 fp64 bit22 */
			{40983,38,0}, /* core2 fp64 bit23 */
			{28249,38,0}, /* core2 fp64 bit24 */
			{40982,38,0}, /* core2 fp64 bit25 */
			{40994,38,0}, /* core2 fp64 bit26 */
			{40981,38,0}, /* core2 fp64 bit27 */
			{40993,38,0}, /* core2 fp64 bit28 */
			{40992,38,0}, /* core2 fp64 bit29 */
			{40980,38,0}, /* core2 fp64 bit30 */
			{40971,38,0}, /* core2 fp64 bit31 */
			{41143,38,0}, /* core2 fp64 bit32 */
			{41142,38,0}, /* core2 fp64 bit33 */
			{41141,38,0}, /* core2 fp64 bit34 */
			{28127,38,0}, /* core2 fp64 bit35 */
			{41140,38,0}, /* core2 fp64 bit36 */
			{36435,38,0}, /* core2 fp64 bit37 */
			{41151,38,0}, /* core2 fp64 bit38 */
			{41150,38,0}, /* core2 fp64 bit39 */
			{41149,38,0}, /* core2 fp64 bit40 */
			{41148,38,0}, /* core2 fp64 bit41 */
			{41147,38,0}, /* core2 fp64 bit42 */
			{41146,38,0}, /* core2 fp64 bit43 */
			{41145,38,0}, /* core2 fp64 bit44 */
			{28114,38,0}, /* core2 fp64 bit45 */
			{36434,38,0}, /* core2 fp64 bit46 */
			{41144,38,0}, /* core2 fp64 bit47 */
			{28132,38,0}, /* core2 fp64 bit48 */
			{36455,38,0}, /* core2 fp64 bit49 */
			{41119,38,0}, /* core2 fp64 bit50 */
			{41118,38,0}, /* core2 fp64 bit51 */
			{41117,38,0}, /* core2 fp64 bit52 */
			{36454,38,0}, /* core2 fp64 bit53 */
			{41116,38,0}, /* core2 fp64 bit54 */
			{41135,38,0}, /* core2 fp64 bit55 */
			{41134,38,0}, /* core2 fp64 bit56 */
			{41133,38,0}, /* core2 fp64 bit57 */
			{41132,38,0}, /* core2 fp64 bit58 */
			{28131,38,0}, /* core2 fp64 bit59 */
			{41115,38,0}, /* core2 fp64 bit60 */
			{41114,38,0}, /* core2 fp64 bit61 */
			{41113,38,0}, /* core2 fp64 bit62 */
			{41112,38,0}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40942,38,0}, /* core2 sp_EL0 bit0 */
			{40941,38,0}, /* core2 sp_EL0 bit1 */
			{40940,38,0}, /* core2 sp_EL0 bit2 */
			{41010,38,0}, /* core2 sp_EL0 bit3 */
			{41009,38,0}, /* core2 sp_EL0 bit4 */
			{40939,38,0}, /* core2 sp_EL0 bit5 */
			{40938,38,0}, /* core2 sp_EL0 bit6 */
			{40937,38,0}, /* core2 sp_EL0 bit7 */
			{40936,38,0}, /* core2 sp_EL0 bit8 */
			{40931,38,0}, /* core2 sp_EL0 bit9 */
			{40947,38,0}, /* core2 sp_EL0 bit10 */
			{40930,38,0}, /* core2 sp_EL0 bit11 */
			{40929,38,0}, /* core2 sp_EL0 bit12 */
			{40928,38,0}, /* core2 sp_EL0 bit13 */
			{40951,38,0}, /* core2 sp_EL0 bit14 */
			{40950,38,0}, /* core2 sp_EL0 bit15 */
			{41008,38,0}, /* core2 sp_EL0 bit16 */
			{41015,38,0}, /* core2 sp_EL0 bit17 */
			{41014,38,0}, /* core2 sp_EL0 bit18 */
			{41011,38,0}, /* core2 sp_EL0 bit19 */
			{41013,38,0}, /* core2 sp_EL0 bit20 */
			{40946,38,0}, /* core2 sp_EL0 bit21 */
			{40949,38,0}, /* core2 sp_EL0 bit22 */
			{40945,38,0}, /* core2 sp_EL0 bit23 */
			{28259,38,0}, /* core2 sp_EL0 bit24 */
			{40944,38,0}, /* core2 sp_EL0 bit25 */
			{41012,38,0}, /* core2 sp_EL0 bit26 */
			{36257,38,0}, /* core2 sp_EL0 bit27 */
			{36347,38,0}, /* core2 sp_EL0 bit28 */
			{36346,38,0}, /* core2 sp_EL0 bit29 */
			{36256,38,0}, /* core2 sp_EL0 bit30 */
			{40943,38,0}, /* core2 sp_EL0 bit31 */
			{41063,38,0}, /* core2 sp_EL0 bit32 */
			{41059,38,0}, /* core2 sp_EL0 bit33 */
			{41058,38,0}, /* core2 sp_EL0 bit34 */
			{41062,38,0}, /* core2 sp_EL0 bit35 */
			{41061,38,0}, /* core2 sp_EL0 bit36 */
			{41057,38,0}, /* core2 sp_EL0 bit37 */
			{41060,38,0}, /* core2 sp_EL0 bit38 */
			{41071,38,0}, /* core2 sp_EL0 bit39 */
			{41070,38,0}, /* core2 sp_EL0 bit40 */
			{41069,38,0}, /* core2 sp_EL0 bit41 */
			{41056,38,0}, /* core2 sp_EL0 bit42 */
			{41068,38,0}, /* core2 sp_EL0 bit43 */
			{41067,38,0}, /* core2 sp_EL0 bit44 */
			{41066,38,0}, /* core2 sp_EL0 bit45 */
			{41065,38,0}, /* core2 sp_EL0 bit46 */
			{41064,38,0}, /* core2 sp_EL0 bit47 */
			{28157,38,0}, /* core2 sp_EL0 bit48 */
			{41103,38,0}, /* core2 sp_EL0 bit49 */
			{41102,38,0}, /* core2 sp_EL0 bit50 */
			{41101,38,0}, /* core2 sp_EL0 bit51 */
			{41100,38,0}, /* core2 sp_EL0 bit52 */
			{41107,38,0}, /* core2 sp_EL0 bit53 */
			{41106,38,0}, /* core2 sp_EL0 bit54 */
			{41105,38,0}, /* core2 sp_EL0 bit55 */
			{41104,38,0}, /* core2 sp_EL0 bit56 */
			{41055,38,0}, /* core2 sp_EL0 bit57 */
			{41054,38,0}, /* core2 sp_EL0 bit58 */
			{41053,38,0}, /* core2 sp_EL0 bit59 */
			{41052,38,0}, /* core2 sp_EL0 bit60 */
			{41111,38,0}, /* core2 sp_EL0 bit61 */
			{41110,38,0}, /* core2 sp_EL0 bit62 */
			{41109,38,0}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40935,38,0}, /* core2 sp_EL1 bit0 */
			{40934,38,0}, /* core2 sp_EL1 bit1 */
			{40902,38,0}, /* core2 sp_EL1 bit2 */
			{40882,38,0}, /* core2 sp_EL1 bit3 */
			{40881,38,0}, /* core2 sp_EL1 bit4 */
			{40933,38,0}, /* core2 sp_EL1 bit5 */
			{40901,38,0}, /* core2 sp_EL1 bit6 */
			{40932,38,0}, /* core2 sp_EL1 bit7 */
			{40900,38,0}, /* core2 sp_EL1 bit8 */
			{40927,38,0}, /* core2 sp_EL1 bit9 */
			{40926,38,0}, /* core2 sp_EL1 bit10 */
			{40923,38,0}, /* core2 sp_EL1 bit11 */
			{40922,38,0}, /* core2 sp_EL1 bit12 */
			{40921,38,0}, /* core2 sp_EL1 bit13 */
			{40920,38,0}, /* core2 sp_EL1 bit14 */
			{40925,38,0}, /* core2 sp_EL1 bit15 */
			{40880,38,0}, /* core2 sp_EL1 bit16 */
			{40879,38,0}, /* core2 sp_EL1 bit17 */
			{40878,38,0}, /* core2 sp_EL1 bit18 */
			{36259,38,0}, /* core2 sp_EL1 bit19 */
			{40877,38,0}, /* core2 sp_EL1 bit20 */
			{40924,38,0}, /* core2 sp_EL1 bit21 */
			{28258,38,0}, /* core2 sp_EL1 bit22 */
			{40899,38,0}, /* core2 sp_EL1 bit23 */
			{36258,38,0}, /* core2 sp_EL1 bit24 */
			{40898,38,0}, /* core2 sp_EL1 bit25 */
			{40883,38,0}, /* core2 sp_EL1 bit26 */
			{40897,38,0}, /* core2 sp_EL1 bit27 */
			{40876,38,0}, /* core2 sp_EL1 bit28 */
			{28244,38,0}, /* core2 sp_EL1 bit29 */
			{40896,38,0}, /* core2 sp_EL1 bit30 */
			{40903,38,0}, /* core2 sp_EL1 bit31 */
			{40803,38,0}, /* core2 sp_EL1 bit32 */
			{40799,38,0}, /* core2 sp_EL1 bit33 */
			{40798,38,0}, /* core2 sp_EL1 bit34 */
			{40802,38,0}, /* core2 sp_EL1 bit35 */
			{40801,38,0}, /* core2 sp_EL1 bit36 */
			{40797,38,0}, /* core2 sp_EL1 bit37 */
			{40800,38,0}, /* core2 sp_EL1 bit38 */
			{40791,38,0}, /* core2 sp_EL1 bit39 */
			{40790,38,0}, /* core2 sp_EL1 bit40 */
			{40789,38,0}, /* core2 sp_EL1 bit41 */
			{40796,38,0}, /* core2 sp_EL1 bit42 */
			{40788,38,0}, /* core2 sp_EL1 bit43 */
			{40795,38,0}, /* core2 sp_EL1 bit44 */
			{40794,38,0}, /* core2 sp_EL1 bit45 */
			{40792,38,0}, /* core2 sp_EL1 bit46 */
			{40793,38,0}, /* core2 sp_EL1 bit47 */
			{28158,38,0}, /* core2 sp_EL1 bit48 */
			{36423,38,0}, /* core2 sp_EL1 bit49 */
			{40839,38,0}, /* core2 sp_EL1 bit50 */
			{40838,38,0}, /* core2 sp_EL1 bit51 */
			{40837,38,0}, /* core2 sp_EL1 bit52 */
			{36422,38,0}, /* core2 sp_EL1 bit53 */
			{40836,38,0}, /* core2 sp_EL1 bit54 */
			{40831,38,0}, /* core2 sp_EL1 bit55 */
			{40830,38,0}, /* core2 sp_EL1 bit56 */
			{40829,38,0}, /* core2 sp_EL1 bit57 */
			{40828,38,0}, /* core2 sp_EL1 bit58 */
			{28159,38,0}, /* core2 sp_EL1 bit59 */
			{40835,38,0}, /* core2 sp_EL1 bit60 */
			{40834,38,0}, /* core2 sp_EL1 bit61 */
			{40833,38,0}, /* core2 sp_EL1 bit62 */
			{40832,38,0}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40906,38,0}, /* core2 sp_EL2 bit0 */
			{40905,38,0}, /* core2 sp_EL2 bit1 */
			{40904,38,0}, /* core2 sp_EL2 bit2 */
			{40886,38,0}, /* core2 sp_EL2 bit3 */
			{40891,38,0}, /* core2 sp_EL2 bit4 */
			{40911,38,0}, /* core2 sp_EL2 bit5 */
			{40910,38,0}, /* core2 sp_EL2 bit6 */
			{40909,38,0}, /* core2 sp_EL2 bit7 */
			{40908,38,0}, /* core2 sp_EL2 bit8 */
			{40919,38,0}, /* core2 sp_EL2 bit9 */
			{40915,38,0}, /* core2 sp_EL2 bit10 */
			{40918,38,0}, /* core2 sp_EL2 bit11 */
			{40917,38,0}, /* core2 sp_EL2 bit12 */
			{40916,38,0}, /* core2 sp_EL2 bit13 */
			{40895,38,0}, /* core2 sp_EL2 bit14 */
			{40894,38,0}, /* core2 sp_EL2 bit15 */
			{40885,38,0}, /* core2 sp_EL2 bit16 */
			{40884,38,0}, /* core2 sp_EL2 bit17 */
			{40890,38,0}, /* core2 sp_EL2 bit18 */
			{28260,38,0}, /* core2 sp_EL2 bit19 */
			{40889,38,0}, /* core2 sp_EL2 bit20 */
			{40914,38,0}, /* core2 sp_EL2 bit21 */
			{40893,38,0}, /* core2 sp_EL2 bit22 */
			{40913,38,0}, /* core2 sp_EL2 bit23 */
			{40888,38,0}, /* core2 sp_EL2 bit24 */
			{40912,38,0}, /* core2 sp_EL2 bit25 */
			{40887,38,0}, /* core2 sp_EL2 bit26 */
			{36261,38,0}, /* core2 sp_EL2 bit27 */
			{36255,38,0}, /* core2 sp_EL2 bit28 */
			{36254,38,0}, /* core2 sp_EL2 bit29 */
			{36260,38,0}, /* core2 sp_EL2 bit30 */
			{40907,38,0}, /* core2 sp_EL2 bit31 */
			{40811,38,0}, /* core2 sp_EL2 bit32 */
			{40810,38,0}, /* core2 sp_EL2 bit33 */
			{40809,38,0}, /* core2 sp_EL2 bit34 */
			{40808,38,0}, /* core2 sp_EL2 bit35 */
			{40783,38,0}, /* core2 sp_EL2 bit36 */
			{40782,38,0}, /* core2 sp_EL2 bit37 */
			{40781,38,0}, /* core2 sp_EL2 bit38 */
			{40780,38,0}, /* core2 sp_EL2 bit39 */
			{40787,38,0}, /* core2 sp_EL2 bit40 */
			{40786,38,0}, /* core2 sp_EL2 bit41 */
			{40785,38,0}, /* core2 sp_EL2 bit42 */
			{40784,38,0}, /* core2 sp_EL2 bit43 */
			{40755,38,0}, /* core2 sp_EL2 bit44 */
			{40754,38,0}, /* core2 sp_EL2 bit45 */
			{40752,38,0}, /* core2 sp_EL2 bit46 */
			{40753,38,0}, /* core2 sp_EL2 bit47 */
			{28170,38,0}, /* core2 sp_EL2 bit48 */
			{28161,38,0}, /* core2 sp_EL2 bit49 */
			{40847,38,0}, /* core2 sp_EL2 bit50 */
			{40846,38,0}, /* core2 sp_EL2 bit51 */
			{40845,38,0}, /* core2 sp_EL2 bit52 */
			{40844,38,0}, /* core2 sp_EL2 bit53 */
			{40843,38,0}, /* core2 sp_EL2 bit54 */
			{40842,38,0}, /* core2 sp_EL2 bit55 */
			{40841,38,0}, /* core2 sp_EL2 bit56 */
			{40840,38,0}, /* core2 sp_EL2 bit57 */
			{40815,38,0}, /* core2 sp_EL2 bit58 */
			{40814,38,0}, /* core2 sp_EL2 bit59 */
			{40813,38,0}, /* core2 sp_EL2 bit60 */
			{40812,38,0}, /* core2 sp_EL2 bit61 */
			{36421,38,0}, /* core2 sp_EL2 bit62 */
			{36420,38,0}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40861,38,0}, /* core2 sp_EL3 bit0 */
			{40860,38,0}, /* core2 sp_EL3 bit1 */
			{40739,38,0}, /* core2 sp_EL3 bit2 */
			{40875,38,0}, /* core2 sp_EL3 bit3 */
			{40874,38,0}, /* core2 sp_EL3 bit4 */
			{40738,38,0}, /* core2 sp_EL3 bit5 */
			{40737,38,0}, /* core2 sp_EL3 bit6 */
			{40736,38,0}, /* core2 sp_EL3 bit7 */
			{40867,38,0}, /* core2 sp_EL3 bit8 */
			{40866,38,0}, /* core2 sp_EL3 bit9 */
			{40865,38,0}, /* core2 sp_EL3 bit10 */
			{40864,38,0}, /* core2 sp_EL3 bit11 */
			{40743,38,0}, /* core2 sp_EL3 bit12 */
			{40742,38,0}, /* core2 sp_EL3 bit13 */
			{40741,38,0}, /* core2 sp_EL3 bit14 */
			{40740,38,0}, /* core2 sp_EL3 bit15 */
			{40873,38,0}, /* core2 sp_EL3 bit16 */
			{40872,38,0}, /* core2 sp_EL3 bit17 */
			{40871,38,0}, /* core2 sp_EL3 bit18 */
			{40863,38,0}, /* core2 sp_EL3 bit19 */
			{40870,38,0}, /* core2 sp_EL3 bit20 */
			{40735,38,0}, /* core2 sp_EL3 bit21 */
			{40734,38,0}, /* core2 sp_EL3 bit22 */
			{40733,38,0}, /* core2 sp_EL3 bit23 */
			{28185,38,0}, /* core2 sp_EL3 bit24 */
			{40732,38,0}, /* core2 sp_EL3 bit25 */
			{40869,38,0}, /* core2 sp_EL3 bit26 */
			{36251,38,0}, /* core2 sp_EL3 bit27 */
			{40868,38,0}, /* core2 sp_EL3 bit28 */
			{28186,38,0}, /* core2 sp_EL3 bit29 */
			{36250,38,0}, /* core2 sp_EL3 bit30 */
			{40862,38,0}, /* core2 sp_EL3 bit31 */
			{40807,38,0}, /* core2 sp_EL3 bit32 */
			{40806,38,0}, /* core2 sp_EL3 bit33 */
			{40805,38,0}, /* core2 sp_EL3 bit34 */
			{40804,38,0}, /* core2 sp_EL3 bit35 */
			{40763,38,0}, /* core2 sp_EL3 bit36 */
			{40762,38,0}, /* core2 sp_EL3 bit37 */
			{40761,38,0}, /* core2 sp_EL3 bit38 */
			{40760,38,0}, /* core2 sp_EL3 bit39 */
			{40767,38,0}, /* core2 sp_EL3 bit40 */
			{40766,38,0}, /* core2 sp_EL3 bit41 */
			{40765,38,0}, /* core2 sp_EL3 bit42 */
			{40764,38,0}, /* core2 sp_EL3 bit43 */
			{40759,38,0}, /* core2 sp_EL3 bit44 */
			{40758,38,0}, /* core2 sp_EL3 bit45 */
			{40756,38,0}, /* core2 sp_EL3 bit46 */
			{40757,38,0}, /* core2 sp_EL3 bit47 */
			{28172,38,0}, /* core2 sp_EL3 bit48 */
			{36425,38,0}, /* core2 sp_EL3 bit49 */
			{40827,38,0}, /* core2 sp_EL3 bit50 */
			{40826,38,0}, /* core2 sp_EL3 bit51 */
			{40825,38,0}, /* core2 sp_EL3 bit52 */
			{40824,38,0}, /* core2 sp_EL3 bit53 */
			{40823,38,0}, /* core2 sp_EL3 bit54 */
			{40822,38,0}, /* core2 sp_EL3 bit55 */
			{40821,38,0}, /* core2 sp_EL3 bit56 */
			{40820,38,0}, /* core2 sp_EL3 bit57 */
			{40819,38,0}, /* core2 sp_EL3 bit58 */
			{36424,38,0}, /* core2 sp_EL3 bit59 */
			{40818,38,0}, /* core2 sp_EL3 bit60 */
			{40817,38,0}, /* core2 sp_EL3 bit61 */
			{40816,38,0}, /* core2 sp_EL3 bit62 */
			{28160,38,0}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{40707,38,0}, /* core2 elr_EL1 bit0 */
			{40706,38,0}, /* core2 elr_EL1 bit1 */
			{40705,38,0}, /* core2 elr_EL1 bit2 */
			{40723,38,0}, /* core2 elr_EL1 bit3 */
			{40722,38,0}, /* core2 elr_EL1 bit4 */
			{40704,38,0}, /* core2 elr_EL1 bit5 */
			{40703,38,0}, /* core2 elr_EL1 bit6 */
			{40702,38,0}, /* core2 elr_EL1 bit7 */
			{40701,38,0}, /* core2 elr_EL1 bit8 */
			{40700,38,0}, /* core2 elr_EL1 bit9 */
			{40695,38,0}, /* core2 elr_EL1 bit10 */
			{40694,38,0}, /* core2 elr_EL1 bit11 */
			{40693,38,0}, /* core2 elr_EL1 bit12 */
			{40692,38,0}, /* core2 elr_EL1 bit13 */
			{40699,38,0}, /* core2 elr_EL1 bit14 */
			{40698,38,0}, /* core2 elr_EL1 bit15 */
			{40721,38,0}, /* core2 elr_EL1 bit16 */
			{40720,38,0}, /* core2 elr_EL1 bit17 */
			{40727,38,0}, /* core2 elr_EL1 bit18 */
			{40697,38,0}, /* core2 elr_EL1 bit19 */
			{40726,38,0}, /* core2 elr_EL1 bit20 */
			{40696,38,0}, /* core2 elr_EL1 bit21 */
			{40715,38,0}, /* core2 elr_EL1 bit22 */
			{40714,38,0}, /* core2 elr_EL1 bit23 */
			{28252,38,0}, /* core2 elr_EL1 bit24 */
			{40713,38,0}, /* core2 elr_EL1 bit25 */
			{40725,38,0}, /* core2 elr_EL1 bit26 */
			{40712,38,0}, /* core2 elr_EL1 bit27 */
			{40724,38,0}, /* core2 elr_EL1 bit28 */
			{28251,38,0}, /* core2 elr_EL1 bit29 */
			{36265,38,0}, /* core2 elr_EL1 bit30 */
			{36264,38,0}, /* core2 elr_EL1 bit31 */
			{40751,38,0}, /* core2 elr_EL1 bit32 */
			{40750,38,0}, /* core2 elr_EL1 bit33 */
			{40749,38,0}, /* core2 elr_EL1 bit34 */
			{40748,38,0}, /* core2 elr_EL1 bit35 */
			{40771,38,0}, /* core2 elr_EL1 bit36 */
			{40770,38,0}, /* core2 elr_EL1 bit37 */
			{40769,38,0}, /* core2 elr_EL1 bit38 */
			{40768,38,0}, /* core2 elr_EL1 bit39 */
			{40775,38,0}, /* core2 elr_EL1 bit40 */
			{40774,38,0}, /* core2 elr_EL1 bit41 */
			{40773,38,0}, /* core2 elr_EL1 bit42 */
			{40772,38,0}, /* core2 elr_EL1 bit43 */
			{40779,38,0}, /* core2 elr_EL1 bit44 */
			{40778,38,0}, /* core2 elr_EL1 bit45 */
			{40777,38,0}, /* core2 elr_EL1 bit46 */
			{40776,38,0}, /* core2 elr_EL1 bit47 */
			{28165,38,0}, /* core2 elr_EL1 bit48 */
			{40859,38,0}, /* core2 elr_EL1 bit49 */
			{40858,38,0}, /* core2 elr_EL1 bit50 */
			{40857,38,0}, /* core2 elr_EL1 bit51 */
			{40856,38,0}, /* core2 elr_EL1 bit52 */
			{40855,38,0}, /* core2 elr_EL1 bit53 */
			{40854,38,0}, /* core2 elr_EL1 bit54 */
			{40853,38,0}, /* core2 elr_EL1 bit55 */
			{40852,38,0}, /* core2 elr_EL1 bit56 */
			{40747,38,0}, /* core2 elr_EL1 bit57 */
			{40746,38,0}, /* core2 elr_EL1 bit58 */
			{40745,38,0}, /* core2 elr_EL1 bit59 */
			{40744,38,0}, /* core2 elr_EL1 bit60 */
			{40851,38,0}, /* core2 elr_EL1 bit61 */
			{40850,38,0}, /* core2 elr_EL1 bit62 */
			{40849,38,0}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{40711,38,0}, /* core2 elr_EL2 bit0 */
			{40710,38,0}, /* core2 elr_EL2 bit1 */
			{40709,38,0}, /* core2 elr_EL2 bit2 */
			{40719,38,0}, /* core2 elr_EL2 bit3 */
			{40718,38,0}, /* core2 elr_EL2 bit4 */
			{40708,38,0}, /* core2 elr_EL2 bit5 */
			{40687,38,0}, /* core2 elr_EL2 bit6 */
			{40691,38,0}, /* core2 elr_EL2 bit7 */
			{40690,38,0}, /* core2 elr_EL2 bit8 */
			{40689,38,0}, /* core2 elr_EL2 bit9 */
			{40686,38,0}, /* core2 elr_EL2 bit10 */
			{40688,38,0}, /* core2 elr_EL2 bit11 */
			{40683,38,0}, /* core2 elr_EL2 bit12 */
			{40682,38,0}, /* core2 elr_EL2 bit13 */
			{40681,38,0}, /* core2 elr_EL2 bit14 */
			{40685,38,0}, /* core2 elr_EL2 bit15 */
			{40717,38,0}, /* core2 elr_EL2 bit16 */
			{40716,38,0}, /* core2 elr_EL2 bit17 */
			{40731,38,0}, /* core2 elr_EL2 bit18 */
			{40684,38,0}, /* core2 elr_EL2 bit19 */
			{40730,38,0}, /* core2 elr_EL2 bit20 */
			{40679,38,0}, /* core2 elr_EL2 bit21 */
			{40680,38,0}, /* core2 elr_EL2 bit22 */
			{40678,38,0}, /* core2 elr_EL2 bit23 */
			{28253,38,0}, /* core2 elr_EL2 bit24 */
			{40677,38,0}, /* core2 elr_EL2 bit25 */
			{40729,38,0}, /* core2 elr_EL2 bit26 */
			{40676,38,0}, /* core2 elr_EL2 bit27 */
			{40728,38,0}, /* core2 elr_EL2 bit28 */
			{28254,38,0}, /* core2 elr_EL2 bit29 */
			{28255,38,0}, /* core2 elr_EL2 bit30 */
			{28256,38,0}, /* core2 elr_EL2 bit31 */
			{40501,38,0}, /* core2 elr_EL2 bit32 */
			{40500,38,0}, /* core2 elr_EL2 bit33 */
			{40499,38,0}, /* core2 elr_EL2 bit34 */
			{40498,38,0}, /* core2 elr_EL2 bit35 */
			{40481,38,0}, /* core2 elr_EL2 bit36 */
			{40480,38,0}, /* core2 elr_EL2 bit37 */
			{40479,38,0}, /* core2 elr_EL2 bit38 */
			{40478,38,0}, /* core2 elr_EL2 bit39 */
			{40477,38,0}, /* core2 elr_EL2 bit40 */
			{40476,38,0}, /* core2 elr_EL2 bit41 */
			{40475,38,0}, /* core2 elr_EL2 bit42 */
			{40474,38,0}, /* core2 elr_EL2 bit43 */
			{40485,38,0}, /* core2 elr_EL2 bit44 */
			{40484,38,0}, /* core2 elr_EL2 bit45 */
			{40483,38,0}, /* core2 elr_EL2 bit46 */
			{40482,38,0}, /* core2 elr_EL2 bit47 */
			{28164,38,0}, /* core2 elr_EL2 bit48 */
			{40509,38,0}, /* core2 elr_EL2 bit49 */
			{40508,38,0}, /* core2 elr_EL2 bit50 */
			{40507,38,0}, /* core2 elr_EL2 bit51 */
			{40506,38,0}, /* core2 elr_EL2 bit52 */
			{40465,38,0}, /* core2 elr_EL2 bit53 */
			{40464,38,0}, /* core2 elr_EL2 bit54 */
			{40463,38,0}, /* core2 elr_EL2 bit55 */
			{40462,38,0}, /* core2 elr_EL2 bit56 */
			{40473,38,0}, /* core2 elr_EL2 bit57 */
			{40472,38,0}, /* core2 elr_EL2 bit58 */
			{40471,38,0}, /* core2 elr_EL2 bit59 */
			{40470,38,0}, /* core2 elr_EL2 bit60 */
			{40469,38,0}, /* core2 elr_EL2 bit61 */
			{40468,38,0}, /* core2 elr_EL2 bit62 */
			{40467,38,0}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{40452,38,0}, /* core2 elr_EL3 bit0 */
			{40451,38,0}, /* core2 elr_EL3 bit1 */
			{40450,38,0}, /* core2 elr_EL3 bit2 */
			{40437,38,0}, /* core2 elr_EL3 bit3 */
			{40436,38,0}, /* core2 elr_EL3 bit4 */
			{40441,38,0}, /* core2 elr_EL3 bit5 */
			{40440,38,0}, /* core2 elr_EL3 bit6 */
			{40439,38,0}, /* core2 elr_EL3 bit7 */
			{40438,38,0}, /* core2 elr_EL3 bit8 */
			{40449,38,0}, /* core2 elr_EL3 bit9 */
			{40448,38,0}, /* core2 elr_EL3 bit10 */
			{40447,38,0}, /* core2 elr_EL3 bit11 */
			{40446,38,0}, /* core2 elr_EL3 bit12 */
			{40457,38,0}, /* core2 elr_EL3 bit13 */
			{40456,38,0}, /* core2 elr_EL3 bit14 */
			{40455,38,0}, /* core2 elr_EL3 bit15 */
			{40435,38,0}, /* core2 elr_EL3 bit16 */
			{40434,38,0}, /* core2 elr_EL3 bit17 */
			{40461,38,0}, /* core2 elr_EL3 bit18 */
			{40445,38,0}, /* core2 elr_EL3 bit19 */
			{40460,38,0}, /* core2 elr_EL3 bit20 */
			{40444,38,0}, /* core2 elr_EL3 bit21 */
			{40454,38,0}, /* core2 elr_EL3 bit22 */
			{40443,38,0}, /* core2 elr_EL3 bit23 */
			{28245,38,0}, /* core2 elr_EL3 bit24 */
			{40442,38,0}, /* core2 elr_EL3 bit25 */
			{40459,38,0}, /* core2 elr_EL3 bit26 */
			{36263,38,0}, /* core2 elr_EL3 bit27 */
			{40458,38,0}, /* core2 elr_EL3 bit28 */
			{28246,38,0}, /* core2 elr_EL3 bit29 */
			{36262,38,0}, /* core2 elr_EL3 bit30 */
			{40453,38,0}, /* core2 elr_EL3 bit31 */
			{40505,38,0}, /* core2 elr_EL3 bit32 */
			{40504,38,0}, /* core2 elr_EL3 bit33 */
			{40503,38,0}, /* core2 elr_EL3 bit34 */
			{40493,38,0}, /* core2 elr_EL3 bit35 */
			{40492,38,0}, /* core2 elr_EL3 bit36 */
			{40502,38,0}, /* core2 elr_EL3 bit37 */
			{40491,38,0}, /* core2 elr_EL3 bit38 */
			{40490,38,0}, /* core2 elr_EL3 bit39 */
			{40489,38,0}, /* core2 elr_EL3 bit40 */
			{40488,38,0}, /* core2 elr_EL3 bit41 */
			{40497,38,0}, /* core2 elr_EL3 bit42 */
			{40487,38,0}, /* core2 elr_EL3 bit43 */
			{40496,38,0}, /* core2 elr_EL3 bit44 */
			{40495,38,0}, /* core2 elr_EL3 bit45 */
			{36215,38,0}, /* core2 elr_EL3 bit46 */
			{40494,38,0}, /* core2 elr_EL3 bit47 */
			{36214,38,0}, /* core2 elr_EL3 bit48 */
			{40517,38,0}, /* core2 elr_EL3 bit49 */
			{40516,38,0}, /* core2 elr_EL3 bit50 */
			{40515,38,0}, /* core2 elr_EL3 bit51 */
			{40514,38,0}, /* core2 elr_EL3 bit52 */
			{40521,38,0}, /* core2 elr_EL3 bit53 */
			{40520,38,0}, /* core2 elr_EL3 bit54 */
			{40519,38,0}, /* core2 elr_EL3 bit55 */
			{40518,38,0}, /* core2 elr_EL3 bit56 */
			{40513,38,0}, /* core2 elr_EL3 bit57 */
			{40512,38,0}, /* core2 elr_EL3 bit58 */
			{40511,38,0}, /* core2 elr_EL3 bit59 */
			{40510,38,0}, /* core2 elr_EL3 bit60 */
			{40433,38,0}, /* core2 elr_EL3 bit61 */
			{40432,38,0}, /* core2 elr_EL3 bit62 */
			{40431,38,0}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{30898,38,0}, /* core2 raw_pc bit0 */
			{33534,37,0}, /* core2 raw_pc bit1 */
			{33533,37,0}, /* core2 raw_pc bit2 */
			{33532,37,0}, /* core2 raw_pc bit3 */
			{33531,37,0}, /* core2 raw_pc bit4 */
			{37455,38,0}, /* core2 raw_pc bit5 */
			{37454,38,0}, /* core2 raw_pc bit6 */
			{37453,38,0}, /* core2 raw_pc bit7 */
			{37452,38,0}, /* core2 raw_pc bit8 */
			{37451,38,0}, /* core2 raw_pc bit9 */
			{37450,38,0}, /* core2 raw_pc bit10 */
			{37447,38,0}, /* core2 raw_pc bit11 */
			{37446,38,0}, /* core2 raw_pc bit12 */
			{37449,38,0}, /* core2 raw_pc bit13 */
			{37448,38,0}, /* core2 raw_pc bit14 */
			{33538,37,0}, /* core2 raw_pc bit15 */
			{33537,37,0}, /* core2 raw_pc bit16 */
			{33536,37,0}, /* core2 raw_pc bit17 */
			{33535,37,0}, /* core2 raw_pc bit18 */
			{33542,37,0}, /* core2 raw_pc bit19 */
			{33541,37,0}, /* core2 raw_pc bit20 */
			{33540,37,0}, /* core2 raw_pc bit21 */
			{33539,37,0}, /* core2 raw_pc bit22 */
			{33546,37,0}, /* core2 raw_pc bit23 */
			{33545,37,0}, /* core2 raw_pc bit24 */
			{33544,37,0}, /* core2 raw_pc bit25 */
			{33543,37,0}, /* core2 raw_pc bit26 */
			{33482,37,0}, /* core2 raw_pc bit27 */
			{33481,37,0}, /* core2 raw_pc bit28 */
			{33480,37,0}, /* core2 raw_pc bit29 */
			{33479,37,0}, /* core2 raw_pc bit30 */
			{33606,37,0}, /* core2 raw_pc bit31 */
			{33605,37,0}, /* core2 raw_pc bit32 */
			{33604,37,0}, /* core2 raw_pc bit33 */
			{33603,37,0}, /* core2 raw_pc bit34 */
			{37245,38,0}, /* core2 raw_pc bit35 */
			{37244,38,0}, /* core2 raw_pc bit36 */
			{37249,38,0}, /* core2 raw_pc bit37 */
			{37248,38,0}, /* core2 raw_pc bit38 */
			{33602,37,0}, /* core2 raw_pc bit39 */
			{33601,37,0}, /* core2 raw_pc bit40 */
			{33600,37,0}, /* core2 raw_pc bit41 */
			{33599,37,0}, /* core2 raw_pc bit42 */
			{37247,38,0}, /* core2 raw_pc bit43 */
			{37246,38,0}, /* core2 raw_pc bit44 */
			{37251,38,0}, /* core2 raw_pc bit45 */
			{37250,38,0}, /* core2 raw_pc bit46 */
			{33598,37,0}, /* core2 raw_pc bit47 */
			{33597,37,0}, /* core2 raw_pc bit48 */
			{33596,37,0}, /* core2 raw_pc bit49 */
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
			{33491,37,0}, /* core2 pc_iss bit0 */
			{33498,37,0}, /* core2 pc_iss bit1 */
			{33497,37,0}, /* core2 pc_iss bit2 */
			{33496,37,0}, /* core2 pc_iss bit3 */
			{33495,37,0}, /* core2 pc_iss bit4 */
			{33494,37,0}, /* core2 pc_iss bit5 */
			{33493,37,0}, /* core2 pc_iss bit6 */
			{33492,37,0}, /* core2 pc_iss bit7 */
			{33522,37,0}, /* core2 pc_iss bit8 */
			{33521,37,0}, /* core2 pc_iss bit9 */
			{33520,37,0}, /* core2 pc_iss bit10 */
			{33519,37,0}, /* core2 pc_iss bit11 */
			{33470,37,0}, /* core2 pc_iss bit12 */
			{33469,37,0}, /* core2 pc_iss bit13 */
			{33468,37,0}, /* core2 pc_iss bit14 */
			{33467,37,0}, /* core2 pc_iss bit15 */
			{33526,37,0}, /* core2 pc_iss bit16 */
			{33525,37,0}, /* core2 pc_iss bit17 */
			{33524,37,0}, /* core2 pc_iss bit18 */
			{33523,37,0}, /* core2 pc_iss bit19 */
			{33530,37,0}, /* core2 pc_iss bit20 */
			{33529,37,0}, /* core2 pc_iss bit21 */
			{33528,37,0}, /* core2 pc_iss bit22 */
			{33527,37,0}, /* core2 pc_iss bit23 */
			{33474,37,0}, /* core2 pc_iss bit24 */
			{33473,37,0}, /* core2 pc_iss bit25 */
			{33472,37,0}, /* core2 pc_iss bit26 */
			{33471,37,0}, /* core2 pc_iss bit27 */
			{33478,37,0}, /* core2 pc_iss bit28 */
			{33477,37,0}, /* core2 pc_iss bit29 */
			{33476,37,0}, /* core2 pc_iss bit30 */
			{33475,37,0}, /* core2 pc_iss bit31 */
			{33631,37,0}, /* core2 pc_iss bit32 */
			{33618,37,0}, /* core2 pc_iss bit33 */
			{33617,37,0}, /* core2 pc_iss bit34 */
			{33616,37,0}, /* core2 pc_iss bit35 */
			{33621,37,0}, /* core2 pc_iss bit36 */
			{33615,37,0}, /* core2 pc_iss bit37 */
			{33620,37,0}, /* core2 pc_iss bit38 */
			{33619,37,0}, /* core2 pc_iss bit39 */
			{33614,37,0}, /* core2 pc_iss bit40 */
			{33613,37,0}, /* core2 pc_iss bit41 */
			{33610,37,0}, /* core2 pc_iss bit42 */
			{33612,37,0}, /* core2 pc_iss bit43 */
			{33611,37,0}, /* core2 pc_iss bit44 */
			{33630,37,0}, /* core2 pc_iss bit45 */
			{33629,37,0}, /* core2 pc_iss bit46 */
			{33609,37,0}, /* core2 pc_iss bit47 */
			{33628,37,0}, /* core2 pc_iss bit48 */
			{33627,37,0}, /* core2 pc_iss bit49 */
			{33626,37,0}, /* core2 pc_iss bit50 */
			{33625,37,0}, /* core2 pc_iss bit51 */
			{33624,37,0}, /* core2 pc_iss bit52 */
			{33622,37,0}, /* core2 pc_iss bit53 */
			{33623,37,0}, /* core2 pc_iss bit54 */
			{33634,37,0}, /* core2 pc_iss bit55 */
			{33633,37,0}, /* core2 pc_iss bit56 */
			{33632,37,0}, /* core2 pc_iss bit57 */
			{33608,37,0}, /* core2 pc_iss bit58 */
			{33607,37,0}, /* core2 pc_iss bit59 */
			{33638,37,0}, /* core2 pc_iss bit60 */
			{33637,37,0}, /* core2 pc_iss bit61 */
			{33636,37,0}, /* core2 pc_iss bit62 */
			{33635,37,0}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{30897,38,0}, /* core2 full_pc_wr bit0 */
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
			{30971,38,0}, /* core2 full_pc_ex1 bit0 */
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
			{30942,38,0}, /* core2 full_pc_ex2 bit0 */
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
			{16598,38,0}, /* core2 return_Stack_pointer bit0 */
			{16597,38,0}, /* core2 return_Stack_pointer bit1 */
			{13720,38,0}, /* core2 return_Stack_pointer bit2 */
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
			{23469,38,0}, /* core2 return_Stack0 bit0 */
			{23468,38,0}, /* core2 return_Stack0 bit1 */
			{23467,38,0}, /* core2 return_Stack0 bit2 */
			{23449,38,0}, /* core2 return_Stack0 bit3 */
			{23448,38,0}, /* core2 return_Stack0 bit4 */
			{23447,38,0}, /* core2 return_Stack0 bit5 */
			{23446,38,0}, /* core2 return_Stack0 bit6 */
			{23365,38,0}, /* core2 return_Stack0 bit7 */
			{23364,38,0}, /* core2 return_Stack0 bit8 */
			{23363,38,0}, /* core2 return_Stack0 bit9 */
			{23466,38,0}, /* core2 return_Stack0 bit10 */
			{23417,38,0}, /* core2 return_Stack0 bit11 */
			{23416,38,0}, /* core2 return_Stack0 bit12 */
			{23415,38,0}, /* core2 return_Stack0 bit13 */
			{23414,38,0}, /* core2 return_Stack0 bit14 */
			{23369,38,0}, /* core2 return_Stack0 bit15 */
			{23368,38,0}, /* core2 return_Stack0 bit16 */
			{23367,38,0}, /* core2 return_Stack0 bit17 */
			{23366,38,0}, /* core2 return_Stack0 bit18 */
			{23421,38,0}, /* core2 return_Stack0 bit19 */
			{23420,38,0}, /* core2 return_Stack0 bit20 */
			{23419,38,0}, /* core2 return_Stack0 bit21 */
			{23418,38,0}, /* core2 return_Stack0 bit22 */
			{23465,38,1}, /* core2 return_Stack0 bit23 */
			{23464,38,1}, /* core2 return_Stack0 bit24 */
			{23463,38,1}, /* core2 return_Stack0 bit25 */
			{23462,38,1}, /* core2 return_Stack0 bit26 */
			{23385,38,1}, /* core2 return_Stack0 bit27 */
			{23384,38,1}, /* core2 return_Stack0 bit28 */
			{23383,38,1}, /* core2 return_Stack0 bit29 */
			{23382,38,1}, /* core2 return_Stack0 bit30 */
			{13706,38,0}, /* core2 return_Stack0 bit31 */
			{23381,38,0}, /* core2 return_Stack0 bit32 */
			{23380,38,0}, /* core2 return_Stack0 bit33 */
			{23379,38,0}, /* core2 return_Stack0 bit34 */
			{23378,38,0}, /* core2 return_Stack0 bit35 */
			{23413,38,1}, /* core2 return_Stack0 bit36 */
			{23412,38,1}, /* core2 return_Stack0 bit37 */
			{23411,38,1}, /* core2 return_Stack0 bit38 */
			{23410,38,1}, /* core2 return_Stack0 bit39 */
			{23405,38,0}, /* core2 return_Stack0 bit40 */
			{23404,38,0}, /* core2 return_Stack0 bit41 */
			{23403,38,0}, /* core2 return_Stack0 bit42 */
			{23402,38,0}, /* core2 return_Stack0 bit43 */
			{23409,38,1}, /* core2 return_Stack0 bit44 */
			{23408,38,1}, /* core2 return_Stack0 bit45 */
			{23407,38,1}, /* core2 return_Stack0 bit46 */
			{23406,38,1}, /* core2 return_Stack0 bit47 */
			{13707,38,0}, /* core2 return_Stack0 bit48 */
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
			{23461,38,0}, /* core2 return_Stack1 bit0 */
			{23460,38,0}, /* core2 return_Stack1 bit1 */
			{23459,38,0}, /* core2 return_Stack1 bit2 */
			{23445,38,0}, /* core2 return_Stack1 bit3 */
			{23444,38,0}, /* core2 return_Stack1 bit4 */
			{23443,38,0}, /* core2 return_Stack1 bit5 */
			{23442,38,0}, /* core2 return_Stack1 bit6 */
			{23441,38,0}, /* core2 return_Stack1 bit7 */
			{23440,38,0}, /* core2 return_Stack1 bit8 */
			{23439,38,0}, /* core2 return_Stack1 bit9 */
			{23458,38,0}, /* core2 return_Stack1 bit10 */
			{23425,38,0}, /* core2 return_Stack1 bit11 */
			{23424,38,0}, /* core2 return_Stack1 bit12 */
			{23423,38,0}, /* core2 return_Stack1 bit13 */
			{23422,38,0}, /* core2 return_Stack1 bit14 */
			{23373,38,0}, /* core2 return_Stack1 bit15 */
			{23372,38,0}, /* core2 return_Stack1 bit16 */
			{23371,38,0}, /* core2 return_Stack1 bit17 */
			{23370,38,0}, /* core2 return_Stack1 bit18 */
			{23429,38,0}, /* core2 return_Stack1 bit19 */
			{23428,38,0}, /* core2 return_Stack1 bit20 */
			{23427,38,0}, /* core2 return_Stack1 bit21 */
			{23426,38,0}, /* core2 return_Stack1 bit22 */
			{23393,38,1}, /* core2 return_Stack1 bit23 */
			{23392,38,1}, /* core2 return_Stack1 bit24 */
			{23391,38,1}, /* core2 return_Stack1 bit25 */
			{23390,38,1}, /* core2 return_Stack1 bit26 */
			{23389,38,1}, /* core2 return_Stack1 bit27 */
			{23388,38,1}, /* core2 return_Stack1 bit28 */
			{23387,38,1}, /* core2 return_Stack1 bit29 */
			{23386,38,1}, /* core2 return_Stack1 bit30 */
			{13711,38,0}, /* core2 return_Stack1 bit31 */
			{23377,38,0}, /* core2 return_Stack1 bit32 */
			{23376,38,0}, /* core2 return_Stack1 bit33 */
			{23375,38,0}, /* core2 return_Stack1 bit34 */
			{23374,38,0}, /* core2 return_Stack1 bit35 */
			{23453,38,1}, /* core2 return_Stack1 bit36 */
			{23452,38,1}, /* core2 return_Stack1 bit37 */
			{23451,38,1}, /* core2 return_Stack1 bit38 */
			{23450,38,1}, /* core2 return_Stack1 bit39 */
			{23401,38,0}, /* core2 return_Stack1 bit40 */
			{23400,38,0}, /* core2 return_Stack1 bit41 */
			{23399,38,0}, /* core2 return_Stack1 bit42 */
			{23398,38,0}, /* core2 return_Stack1 bit43 */
			{23457,38,1}, /* core2 return_Stack1 bit44 */
			{23456,38,1}, /* core2 return_Stack1 bit45 */
			{23455,38,1}, /* core2 return_Stack1 bit46 */
			{23454,38,1}, /* core2 return_Stack1 bit47 */
			{13705,38,0}, /* core2 return_Stack1 bit48 */
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
			{23397,38,0}, /* core2 return_Stack2 bit0 */
			{23396,38,0}, /* core2 return_Stack2 bit1 */
			{23395,38,0}, /* core2 return_Stack2 bit2 */
			{23437,38,0}, /* core2 return_Stack2 bit3 */
			{23436,38,0}, /* core2 return_Stack2 bit4 */
			{23435,38,0}, /* core2 return_Stack2 bit5 */
			{23434,38,0}, /* core2 return_Stack2 bit6 */
			{23361,38,0}, /* core2 return_Stack2 bit7 */
			{23360,38,0}, /* core2 return_Stack2 bit8 */
			{23359,38,0}, /* core2 return_Stack2 bit9 */
			{23394,38,0}, /* core2 return_Stack2 bit10 */
			{23433,38,0}, /* core2 return_Stack2 bit11 */
			{23432,38,0}, /* core2 return_Stack2 bit12 */
			{23431,38,0}, /* core2 return_Stack2 bit13 */
			{23430,38,0}, /* core2 return_Stack2 bit14 */
			{23357,38,1}, /* core2 return_Stack2 bit15 */
			{23356,38,1}, /* core2 return_Stack2 bit16 */
			{23355,38,1}, /* core2 return_Stack2 bit17 */
			{23354,38,1}, /* core2 return_Stack2 bit18 */
			{23216,38,0}, /* core2 return_Stack2 bit19 */
			{23215,38,0}, /* core2 return_Stack2 bit20 */
			{23214,38,0}, /* core2 return_Stack2 bit21 */
			{23213,38,0}, /* core2 return_Stack2 bit22 */
			{23312,38,1}, /* core2 return_Stack2 bit23 */
			{23311,38,1}, /* core2 return_Stack2 bit24 */
			{23310,38,1}, /* core2 return_Stack2 bit25 */
			{23309,38,1}, /* core2 return_Stack2 bit26 */
			{23128,38,1}, /* core2 return_Stack2 bit27 */
			{23127,38,1}, /* core2 return_Stack2 bit28 */
			{23126,38,1}, /* core2 return_Stack2 bit29 */
			{23125,38,1}, /* core2 return_Stack2 bit30 */
			{13712,38,0}, /* core2 return_Stack2 bit31 */
			{23152,38,1}, /* core2 return_Stack2 bit32 */
			{23151,38,1}, /* core2 return_Stack2 bit33 */
			{23150,38,1}, /* core2 return_Stack2 bit34 */
			{23149,38,1}, /* core2 return_Stack2 bit35 */
			{23244,38,1}, /* core2 return_Stack2 bit36 */
			{23243,38,1}, /* core2 return_Stack2 bit37 */
			{23242,38,1}, /* core2 return_Stack2 bit38 */
			{23241,38,1}, /* core2 return_Stack2 bit39 */
			{23308,38,1}, /* core2 return_Stack2 bit40 */
			{23307,38,1}, /* core2 return_Stack2 bit41 */
			{23306,38,1}, /* core2 return_Stack2 bit42 */
			{23305,38,1}, /* core2 return_Stack2 bit43 */
			{23256,38,1}, /* core2 return_Stack2 bit44 */
			{23255,38,1}, /* core2 return_Stack2 bit45 */
			{23254,38,1}, /* core2 return_Stack2 bit46 */
			{23253,38,1}, /* core2 return_Stack2 bit47 */
			{13713,38,0}, /* core2 return_Stack2 bit48 */
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
			{23332,38,0}, /* core2 return_Stack3 bit0 */
			{23331,38,0}, /* core2 return_Stack3 bit1 */
			{23330,38,0}, /* core2 return_Stack3 bit2 */
			{23204,38,0}, /* core2 return_Stack3 bit3 */
			{23203,38,0}, /* core2 return_Stack3 bit4 */
			{23202,38,0}, /* core2 return_Stack3 bit5 */
			{23201,38,0}, /* core2 return_Stack3 bit6 */
			{23168,38,0}, /* core2 return_Stack3 bit7 */
			{23167,38,0}, /* core2 return_Stack3 bit8 */
			{23166,38,0}, /* core2 return_Stack3 bit9 */
			{23329,38,0}, /* core2 return_Stack3 bit10 */
			{23228,38,0}, /* core2 return_Stack3 bit11 */
			{23227,38,0}, /* core2 return_Stack3 bit12 */
			{23226,38,0}, /* core2 return_Stack3 bit13 */
			{23225,38,0}, /* core2 return_Stack3 bit14 */
			{23160,38,1}, /* core2 return_Stack3 bit15 */
			{23159,38,1}, /* core2 return_Stack3 bit16 */
			{23158,38,1}, /* core2 return_Stack3 bit17 */
			{23157,38,1}, /* core2 return_Stack3 bit18 */
			{23224,38,0}, /* core2 return_Stack3 bit19 */
			{23223,38,0}, /* core2 return_Stack3 bit20 */
			{23222,38,0}, /* core2 return_Stack3 bit21 */
			{23221,38,0}, /* core2 return_Stack3 bit22 */
			{23340,38,1}, /* core2 return_Stack3 bit23 */
			{23339,38,1}, /* core2 return_Stack3 bit24 */
			{23338,38,1}, /* core2 return_Stack3 bit25 */
			{23337,38,1}, /* core2 return_Stack3 bit26 */
			{23124,38,1}, /* core2 return_Stack3 bit27 */
			{23123,38,1}, /* core2 return_Stack3 bit28 */
			{23122,38,1}, /* core2 return_Stack3 bit29 */
			{23121,38,1}, /* core2 return_Stack3 bit30 */
			{13714,38,0}, /* core2 return_Stack3 bit31 */
			{23148,38,1}, /* core2 return_Stack3 bit32 */
			{23147,38,1}, /* core2 return_Stack3 bit33 */
			{23146,38,1}, /* core2 return_Stack3 bit34 */
			{23145,38,1}, /* core2 return_Stack3 bit35 */
			{23272,38,1}, /* core2 return_Stack3 bit36 */
			{23271,38,1}, /* core2 return_Stack3 bit37 */
			{23270,38,1}, /* core2 return_Stack3 bit38 */
			{23269,38,1}, /* core2 return_Stack3 bit39 */
			{23320,38,1}, /* core2 return_Stack3 bit40 */
			{23319,38,1}, /* core2 return_Stack3 bit41 */
			{23318,38,1}, /* core2 return_Stack3 bit42 */
			{23317,38,1}, /* core2 return_Stack3 bit43 */
			{23264,38,1}, /* core2 return_Stack3 bit44 */
			{23263,38,1}, /* core2 return_Stack3 bit45 */
			{23262,38,1}, /* core2 return_Stack3 bit46 */
			{23261,38,1}, /* core2 return_Stack3 bit47 */
			{13717,38,0}, /* core2 return_Stack3 bit48 */
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
			{23352,38,0}, /* core2 return_Stack4 bit0 */
			{23351,38,0}, /* core2 return_Stack4 bit1 */
			{23350,38,0}, /* core2 return_Stack4 bit2 */
			{23268,38,0}, /* core2 return_Stack4 bit3 */
			{23267,38,0}, /* core2 return_Stack4 bit4 */
			{23266,38,0}, /* core2 return_Stack4 bit5 */
			{23265,38,0}, /* core2 return_Stack4 bit6 */
			{23180,38,0}, /* core2 return_Stack4 bit7 */
			{23179,38,0}, /* core2 return_Stack4 bit8 */
			{23178,38,0}, /* core2 return_Stack4 bit9 */
			{23349,38,0}, /* core2 return_Stack4 bit10 */
			{23288,38,0}, /* core2 return_Stack4 bit11 */
			{23287,38,0}, /* core2 return_Stack4 bit12 */
			{23286,38,0}, /* core2 return_Stack4 bit13 */
			{23285,38,0}, /* core2 return_Stack4 bit14 */
			{23184,38,0}, /* core2 return_Stack4 bit15 */
			{23183,38,0}, /* core2 return_Stack4 bit16 */
			{23182,38,0}, /* core2 return_Stack4 bit17 */
			{23181,38,0}, /* core2 return_Stack4 bit18 */
			{23284,38,0}, /* core2 return_Stack4 bit19 */
			{23283,38,0}, /* core2 return_Stack4 bit20 */
			{23282,38,0}, /* core2 return_Stack4 bit21 */
			{23281,38,0}, /* core2 return_Stack4 bit22 */
			{23344,38,1}, /* core2 return_Stack4 bit23 */
			{23343,38,1}, /* core2 return_Stack4 bit24 */
			{23342,38,1}, /* core2 return_Stack4 bit25 */
			{23341,38,1}, /* core2 return_Stack4 bit26 */
			{23116,38,1}, /* core2 return_Stack4 bit27 */
			{23115,38,1}, /* core2 return_Stack4 bit28 */
			{23114,38,1}, /* core2 return_Stack4 bit29 */
			{23113,38,1}, /* core2 return_Stack4 bit30 */
			{13708,38,0}, /* core2 return_Stack4 bit31 */
			{23140,38,0}, /* core2 return_Stack4 bit32 */
			{23139,38,0}, /* core2 return_Stack4 bit33 */
			{23138,38,0}, /* core2 return_Stack4 bit34 */
			{23137,38,0}, /* core2 return_Stack4 bit35 */
			{23292,38,1}, /* core2 return_Stack4 bit36 */
			{23291,38,1}, /* core2 return_Stack4 bit37 */
			{23290,38,1}, /* core2 return_Stack4 bit38 */
			{23289,38,1}, /* core2 return_Stack4 bit39 */
			{23300,38,0}, /* core2 return_Stack4 bit40 */
			{23299,38,0}, /* core2 return_Stack4 bit41 */
			{23298,38,0}, /* core2 return_Stack4 bit42 */
			{23297,38,0}, /* core2 return_Stack4 bit43 */
			{23296,38,1}, /* core2 return_Stack4 bit44 */
			{23295,38,1}, /* core2 return_Stack4 bit45 */
			{23294,38,1}, /* core2 return_Stack4 bit46 */
			{23293,38,1}, /* core2 return_Stack4 bit47 */
			{13709,38,0}, /* core2 return_Stack4 bit48 */
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
			{23348,38,0}, /* core2 return_Stack5 bit0 */
			{23347,38,0}, /* core2 return_Stack5 bit1 */
			{23346,38,0}, /* core2 return_Stack5 bit2 */
			{23196,38,0}, /* core2 return_Stack5 bit3 */
			{23195,38,0}, /* core2 return_Stack5 bit4 */
			{23194,38,0}, /* core2 return_Stack5 bit5 */
			{23193,38,0}, /* core2 return_Stack5 bit6 */
			{23192,38,0}, /* core2 return_Stack5 bit7 */
			{23191,38,0}, /* core2 return_Stack5 bit8 */
			{23190,38,0}, /* core2 return_Stack5 bit9 */
			{23345,38,0}, /* core2 return_Stack5 bit10 */
			{23240,38,0}, /* core2 return_Stack5 bit11 */
			{23239,38,0}, /* core2 return_Stack5 bit12 */
			{23238,38,0}, /* core2 return_Stack5 bit13 */
			{23237,38,0}, /* core2 return_Stack5 bit14 */
			{23188,38,0}, /* core2 return_Stack5 bit15 */
			{23187,38,0}, /* core2 return_Stack5 bit16 */
			{23186,38,0}, /* core2 return_Stack5 bit17 */
			{23185,38,0}, /* core2 return_Stack5 bit18 */
			{23280,38,0}, /* core2 return_Stack5 bit19 */
			{23279,38,0}, /* core2 return_Stack5 bit20 */
			{23278,38,0}, /* core2 return_Stack5 bit21 */
			{23277,38,0}, /* core2 return_Stack5 bit22 */
			{23112,38,1}, /* core2 return_Stack5 bit23 */
			{23111,38,1}, /* core2 return_Stack5 bit24 */
			{23110,38,1}, /* core2 return_Stack5 bit25 */
			{23109,38,1}, /* core2 return_Stack5 bit26 */
			{23120,38,1}, /* core2 return_Stack5 bit27 */
			{23119,38,1}, /* core2 return_Stack5 bit28 */
			{23118,38,1}, /* core2 return_Stack5 bit29 */
			{23117,38,1}, /* core2 return_Stack5 bit30 */
			{13710,38,0}, /* core2 return_Stack5 bit31 */
			{23136,38,0}, /* core2 return_Stack5 bit32 */
			{23135,38,0}, /* core2 return_Stack5 bit33 */
			{23134,38,0}, /* core2 return_Stack5 bit34 */
			{23133,38,0}, /* core2 return_Stack5 bit35 */
			{23248,38,1}, /* core2 return_Stack5 bit36 */
			{23247,38,1}, /* core2 return_Stack5 bit37 */
			{23246,38,1}, /* core2 return_Stack5 bit38 */
			{23245,38,1}, /* core2 return_Stack5 bit39 */
			{23304,38,0}, /* core2 return_Stack5 bit40 */
			{23303,38,0}, /* core2 return_Stack5 bit41 */
			{23302,38,0}, /* core2 return_Stack5 bit42 */
			{23301,38,0}, /* core2 return_Stack5 bit43 */
			{23252,38,1}, /* core2 return_Stack5 bit44 */
			{23251,38,1}, /* core2 return_Stack5 bit45 */
			{23250,38,1}, /* core2 return_Stack5 bit46 */
			{23249,38,1}, /* core2 return_Stack5 bit47 */
			{13704,38,0}, /* core2 return_Stack5 bit48 */
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
			{23324,38,0}, /* core2 return_Stack6 bit0 */
			{23323,38,0}, /* core2 return_Stack6 bit1 */
			{23322,38,0}, /* core2 return_Stack6 bit2 */
			{23208,38,0}, /* core2 return_Stack6 bit3 */
			{23207,38,0}, /* core2 return_Stack6 bit4 */
			{23206,38,0}, /* core2 return_Stack6 bit5 */
			{23205,38,0}, /* core2 return_Stack6 bit6 */
			{23176,38,0}, /* core2 return_Stack6 bit7 */
			{23175,38,0}, /* core2 return_Stack6 bit8 */
			{23174,38,0}, /* core2 return_Stack6 bit9 */
			{23321,38,0}, /* core2 return_Stack6 bit10 */
			{23212,38,0}, /* core2 return_Stack6 bit11 */
			{23211,38,0}, /* core2 return_Stack6 bit12 */
			{23210,38,0}, /* core2 return_Stack6 bit13 */
			{23209,38,0}, /* core2 return_Stack6 bit14 */
			{23164,38,1}, /* core2 return_Stack6 bit15 */
			{23163,38,1}, /* core2 return_Stack6 bit16 */
			{23162,38,1}, /* core2 return_Stack6 bit17 */
			{23161,38,1}, /* core2 return_Stack6 bit18 */
			{23220,38,0}, /* core2 return_Stack6 bit19 */
			{23219,38,0}, /* core2 return_Stack6 bit20 */
			{23218,38,0}, /* core2 return_Stack6 bit21 */
			{23217,38,0}, /* core2 return_Stack6 bit22 */
			{23316,38,1}, /* core2 return_Stack6 bit23 */
			{23315,38,1}, /* core2 return_Stack6 bit24 */
			{23314,38,1}, /* core2 return_Stack6 bit25 */
			{23313,38,1}, /* core2 return_Stack6 bit26 */
			{23132,38,1}, /* core2 return_Stack6 bit27 */
			{23131,38,1}, /* core2 return_Stack6 bit28 */
			{23130,38,1}, /* core2 return_Stack6 bit29 */
			{23129,38,1}, /* core2 return_Stack6 bit30 */
			{13718,38,0}, /* core2 return_Stack6 bit31 */
			{23144,38,0}, /* core2 return_Stack6 bit32 */
			{23143,38,0}, /* core2 return_Stack6 bit33 */
			{23142,38,0}, /* core2 return_Stack6 bit34 */
			{23141,38,0}, /* core2 return_Stack6 bit35 */
			{23276,38,1}, /* core2 return_Stack6 bit36 */
			{23275,38,1}, /* core2 return_Stack6 bit37 */
			{23274,38,1}, /* core2 return_Stack6 bit38 */
			{23273,38,1}, /* core2 return_Stack6 bit39 */
			{23328,38,1}, /* core2 return_Stack6 bit40 */
			{23327,38,1}, /* core2 return_Stack6 bit41 */
			{23326,38,1}, /* core2 return_Stack6 bit42 */
			{23325,38,1}, /* core2 return_Stack6 bit43 */
			{23260,38,1}, /* core2 return_Stack6 bit44 */
			{23259,38,1}, /* core2 return_Stack6 bit45 */
			{23258,38,1}, /* core2 return_Stack6 bit46 */
			{23257,38,1}, /* core2 return_Stack6 bit47 */
			{13719,38,0}, /* core2 return_Stack6 bit48 */
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
			{23336,38,0}, /* core2 return_Stack7 bit0 */
			{23335,38,0}, /* core2 return_Stack7 bit1 */
			{23334,38,0}, /* core2 return_Stack7 bit2 */
			{23200,38,0}, /* core2 return_Stack7 bit3 */
			{23199,38,0}, /* core2 return_Stack7 bit4 */
			{23198,38,0}, /* core2 return_Stack7 bit5 */
			{23197,38,0}, /* core2 return_Stack7 bit6 */
			{23172,38,0}, /* core2 return_Stack7 bit7 */
			{23171,38,0}, /* core2 return_Stack7 bit8 */
			{23170,38,0}, /* core2 return_Stack7 bit9 */
			{23333,38,0}, /* core2 return_Stack7 bit10 */
			{23236,38,0}, /* core2 return_Stack7 bit11 */
			{23235,38,0}, /* core2 return_Stack7 bit12 */
			{23234,38,0}, /* core2 return_Stack7 bit13 */
			{23233,38,0}, /* core2 return_Stack7 bit14 */
			{23156,38,1}, /* core2 return_Stack7 bit15 */
			{23155,38,1}, /* core2 return_Stack7 bit16 */
			{23154,38,1}, /* core2 return_Stack7 bit17 */
			{23153,38,1}, /* core2 return_Stack7 bit18 */
			{23232,38,0}, /* core2 return_Stack7 bit19 */
			{23231,38,0}, /* core2 return_Stack7 bit20 */
			{23230,38,0}, /* core2 return_Stack7 bit21 */
			{23229,38,0}, /* core2 return_Stack7 bit22 */
			{23108,38,1}, /* core2 return_Stack7 bit23 */
			{23107,38,1}, /* core2 return_Stack7 bit24 */
			{23106,38,1}, /* core2 return_Stack7 bit25 */
			{23105,38,1}, /* core2 return_Stack7 bit26 */
			{23035,38,1}, /* core2 return_Stack7 bit27 */
			{23034,38,1}, /* core2 return_Stack7 bit28 */
			{23033,38,1}, /* core2 return_Stack7 bit29 */
			{23032,38,1}, /* core2 return_Stack7 bit30 */
			{13715,38,0}, /* core2 return_Stack7 bit31 */
			{23031,38,1}, /* core2 return_Stack7 bit32 */
			{23030,38,1}, /* core2 return_Stack7 bit33 */
			{23029,38,1}, /* core2 return_Stack7 bit34 */
			{23028,38,1}, /* core2 return_Stack7 bit35 */
			{23023,38,1}, /* core2 return_Stack7 bit36 */
			{23022,38,1}, /* core2 return_Stack7 bit37 */
			{23021,38,1}, /* core2 return_Stack7 bit38 */
			{23020,38,1}, /* core2 return_Stack7 bit39 */
			{23039,38,1}, /* core2 return_Stack7 bit40 */
			{23038,38,1}, /* core2 return_Stack7 bit41 */
			{23037,38,1}, /* core2 return_Stack7 bit42 */
			{23036,38,1}, /* core2 return_Stack7 bit43 */
			{23027,38,1}, /* core2 return_Stack7 bit44 */
			{23026,38,1}, /* core2 return_Stack7 bit45 */
			{23025,38,1}, /* core2 return_Stack7 bit46 */
			{23024,38,1}, /* core2 return_Stack7 bit47 */
			{13716,38,0}, /* core2 return_Stack7 bit48 */
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
			.L2_parity_err = {{
			{ 7910,37,0}, /* core2 L2_parity_err bit0 */
			{    0, 0,2}, /* core2 L2_parity_err bit1 */
			{    0, 0,2}, /* core2 L2_parity_err bit2 */
			{    0, 0,2}, /* core2 L2_parity_err bit3 */
			{    0, 0,2}, /* core2 L2_parity_err bit4 */
			{    0, 0,2}, /* core2 L2_parity_err bit5 */
			{    0, 0,2}, /* core2 L2_parity_err bit6 */
			{    0, 0,2}, /* core2 L2_parity_err bit7 */
			{    0, 0,2}, /* core2 L2_parity_err bit8 */
			{    0, 0,2}, /* core2 L2_parity_err bit9 */
			{    0, 0,2}, /* core2 L2_parity_err bit10 */
			{    0, 0,2}, /* core2 L2_parity_err bit11 */
			{    0, 0,2}, /* core2 L2_parity_err bit12 */
			{    0, 0,2}, /* core2 L2_parity_err bit13 */
			{    0, 0,2}, /* core2 L2_parity_err bit14 */
			{    0, 0,2}, /* core2 L2_parity_err bit15 */
			{    0, 0,2}, /* core2 L2_parity_err bit16 */
			{    0, 0,2}, /* core2 L2_parity_err bit17 */
			{    0, 0,2}, /* core2 L2_parity_err bit18 */
			{    0, 0,2}, /* core2 L2_parity_err bit19 */
			{    0, 0,2}, /* core2 L2_parity_err bit20 */
			{    0, 0,2}, /* core2 L2_parity_err bit21 */
			{    0, 0,2}, /* core2 L2_parity_err bit22 */
			{    0, 0,2}, /* core2 L2_parity_err bit23 */
			{    0, 0,2}, /* core2 L2_parity_err bit24 */
			{    0, 0,2}, /* core2 L2_parity_err bit25 */
			{    0, 0,2}, /* core2 L2_parity_err bit26 */
			{    0, 0,2}, /* core2 L2_parity_err bit27 */
			{    0, 0,2}, /* core2 L2_parity_err bit28 */
			{    0, 0,2}, /* core2 L2_parity_err bit29 */
			{    0, 0,2}, /* core2 L2_parity_err bit30 */
			{    0, 0,2}, /* core2 L2_parity_err bit31 */
			{    0, 0,2}, /* core2 L2_parity_err bit32 */
			{    0, 0,2}, /* core2 L2_parity_err bit33 */
			{    0, 0,2}, /* core2 L2_parity_err bit34 */
			{    0, 0,2}, /* core2 L2_parity_err bit35 */
			{    0, 0,2}, /* core2 L2_parity_err bit36 */
			{    0, 0,2}, /* core2 L2_parity_err bit37 */
			{    0, 0,2}, /* core2 L2_parity_err bit38 */
			{    0, 0,2}, /* core2 L2_parity_err bit39 */
			{    0, 0,2}, /* core2 L2_parity_err bit40 */
			{    0, 0,2}, /* core2 L2_parity_err bit41 */
			{    0, 0,2}, /* core2 L2_parity_err bit42 */
			{    0, 0,2}, /* core2 L2_parity_err bit43 */
			{    0, 0,2}, /* core2 L2_parity_err bit44 */
			{    0, 0,2}, /* core2 L2_parity_err bit45 */
			{    0, 0,2}, /* core2 L2_parity_err bit46 */
			{    0, 0,2}, /* core2 L2_parity_err bit47 */
			{    0, 0,2}, /* core2 L2_parity_err bit48 */
			{    0, 0,2}, /* core2 L2_parity_err bit49 */
			{    0, 0,2}, /* core2 L2_parity_err bit50 */
			{    0, 0,2}, /* core2 L2_parity_err bit51 */
			{    0, 0,2}, /* core2 L2_parity_err bit52 */
			{    0, 0,2}, /* core2 L2_parity_err bit53 */
			{    0, 0,2}, /* core2 L2_parity_err bit54 */
			{    0, 0,2}, /* core2 L2_parity_err bit55 */
			{    0, 0,2}, /* core2 L2_parity_err bit56 */
			{    0, 0,2}, /* core2 L2_parity_err bit57 */
			{    0, 0,2}, /* core2 L2_parity_err bit58 */
			{    0, 0,2}, /* core2 L2_parity_err bit59 */
			{    0, 0,2}, /* core2 L2_parity_err bit60 */
			{    0, 0,2}, /* core2 L2_parity_err bit61 */
			{    0, 0,2}, /* core2 L2_parity_err bit62 */
			{    0, 0,2}, /* core2 L2_parity_err bit63 */
			}},
			.L2_parity_err_count = {{
			{13805,37,1}, /* core2 L2_parity_err_count bit0 */
			{13804,37,1}, /* core2 L2_parity_err_count bit1 */
			{13803,37,1}, /* core2 L2_parity_err_count bit2 */
			{13810,37,0}, /* core2 L2_parity_err_count bit3 */
			{13809,37,0}, /* core2 L2_parity_err_count bit4 */
			{13808,37,0}, /* core2 L2_parity_err_count bit5 */
			{13807,37,0}, /* core2 L2_parity_err_count bit6 */
			{ 7911,37,0}, /* core2 L2_parity_err_count bit7 */
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
			{14288,37,0}, /* core2 L2_parity_index bit0 */
			{14287,37,0}, /* core2 L2_parity_index bit1 */
			{14286,37,0}, /* core2 L2_parity_index bit2 */
			{14285,37,0}, /* core2 L2_parity_index bit3 */
			{14284,37,0}, /* core2 L2_parity_index bit4 */
			{14283,37,0}, /* core2 L2_parity_index bit5 */
			{14282,37,0}, /* core2 L2_parity_index bit6 */
			{14281,37,0}, /* core2 L2_parity_index bit7 */
			{ 7821,37,0}, /* core2 L2_parity_index bit8 */
			{    0, 0,2}, /* core2 L2_parity_index bit9 */
			{    0, 0,2}, /* core2 L2_parity_index bit10 */
			{    0, 0,2}, /* core2 L2_parity_index bit11 */
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
			{10378,37,0}, /* core2 L2_parity_way bit0 */
			{10377,37,0}, /* core2 L2_parity_way bit1 */
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
			{14280,37,0}, /* core2 L2_parity_banks bit0 */
			{14279,37,0}, /* core2 L2_parity_banks bit1 */
			{14278,37,0}, /* core2 L2_parity_banks bit2 */
			{14277,37,0}, /* core2 L2_parity_banks bit3 */
			{14272,37,0}, /* core2 L2_parity_banks bit4 */
			{14271,37,0}, /* core2 L2_parity_banks bit5 */
			{14270,37,0}, /* core2 L2_parity_banks bit6 */
			{14269,37,0}, /* core2 L2_parity_banks bit7 */
			{14292,37,0}, /* core2 L2_parity_banks bit8 */
			{14291,37,0}, /* core2 L2_parity_banks bit9 */
			{14290,37,0}, /* core2 L2_parity_banks bit10 */
			{14289,37,0}, /* core2 L2_parity_banks bit11 */
			{14276,37,0}, /* core2 L2_parity_banks bit12 */
			{14275,37,0}, /* core2 L2_parity_banks bit13 */
			{14274,37,0}, /* core2 L2_parity_banks bit14 */
			{14273,37,0}, /* core2 L2_parity_banks bit15 */
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
			{  192,39,0}, /* core3 pc bit0 */
			{  191,39,0}, /* core3 pc bit1 */
			{  190,39,0}, /* core3 pc bit2 */
			{  189,39,0}, /* core3 pc bit3 */
			{  142,39,0}, /* core3 pc bit4 */
			{  141,39,0}, /* core3 pc bit5 */
			{  140,39,0}, /* core3 pc bit6 */
			{  139,39,0}, /* core3 pc bit7 */
			{  146,39,0}, /* core3 pc bit8 */
			{  145,39,0}, /* core3 pc bit9 */
			{  144,39,0}, /* core3 pc bit10 */
			{  143,39,0}, /* core3 pc bit11 */
			{  150,39,0}, /* core3 pc bit12 */
			{  149,39,0}, /* core3 pc bit13 */
			{  148,39,0}, /* core3 pc bit14 */
			{  147,39,0}, /* core3 pc bit15 */
			{  126,39,0}, /* core3 pc bit16 */
			{  125,39,0}, /* core3 pc bit17 */
			{  124,39,0}, /* core3 pc bit18 */
			{  123,39,0}, /* core3 pc bit19 */
			{  134,39,0}, /* core3 pc bit20 */
			{  133,39,0}, /* core3 pc bit21 */
			{  132,39,0}, /* core3 pc bit22 */
			{  131,39,0}, /* core3 pc bit23 */
			{  138,39,0}, /* core3 pc bit24 */
			{  137,39,0}, /* core3 pc bit25 */
			{  136,39,0}, /* core3 pc bit26 */
			{  135,39,0}, /* core3 pc bit27 */
			{  130,39,0}, /* core3 pc bit28 */
			{  129,39,0}, /* core3 pc bit29 */
			{  128,39,0}, /* core3 pc bit30 */
			{  127,39,0}, /* core3 pc bit31 */
			{  240,39,0}, /* core3 pc bit32 */
			{  239,39,0}, /* core3 pc bit33 */
			{  238,39,0}, /* core3 pc bit34 */
			{  237,39,0}, /* core3 pc bit35 */
			{  248,39,0}, /* core3 pc bit36 */
			{  247,39,0}, /* core3 pc bit37 */
			{  246,39,0}, /* core3 pc bit38 */
			{  245,39,0}, /* core3 pc bit39 */
			{  244,39,0}, /* core3 pc bit40 */
			{  243,39,0}, /* core3 pc bit41 */
			{  242,39,0}, /* core3 pc bit42 */
			{  241,39,0}, /* core3 pc bit43 */
			{  216,39,0}, /* core3 pc bit44 */
			{  215,39,0}, /* core3 pc bit45 */
			{  214,39,0}, /* core3 pc bit46 */
			{  213,39,0}, /* core3 pc bit47 */
			{  180,39,0}, /* core3 pc bit48 */
			{  179,39,0}, /* core3 pc bit49 */
			{  178,39,0}, /* core3 pc bit50 */
			{  177,39,0}, /* core3 pc bit51 */
			{  184,39,0}, /* core3 pc bit52 */
			{  183,39,0}, /* core3 pc bit53 */
			{  182,39,0}, /* core3 pc bit54 */
			{  181,39,0}, /* core3 pc bit55 */
			{  236,39,0}, /* core3 pc bit56 */
			{  235,39,0}, /* core3 pc bit57 */
			{  234,39,0}, /* core3 pc bit58 */
			{  233,39,0}, /* core3 pc bit59 */
			{  188,39,0}, /* core3 pc bit60 */
			{  187,39,0}, /* core3 pc bit61 */
			{  186,39,0}, /* core3 pc bit62 */
			{  185,39,0}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{41807,40,0}, /* core3 sp32 bit0 */
			{41871,40,0}, /* core3 sp32 bit1 */
			{41806,40,0}, /* core3 sp32 bit2 */
			{41805,40,0}, /* core3 sp32 bit3 */
			{41804,40,0}, /* core3 sp32 bit4 */
			{41855,40,0}, /* core3 sp32 bit5 */
			{41854,40,0}, /* core3 sp32 bit6 */
			{41853,40,0}, /* core3 sp32 bit7 */
			{41852,40,0}, /* core3 sp32 bit8 */
			{41859,40,0}, /* core3 sp32 bit9 */
			{41858,40,0}, /* core3 sp32 bit10 */
			{41857,40,0}, /* core3 sp32 bit11 */
			{41856,40,0}, /* core3 sp32 bit12 */
			{41867,40,0}, /* core3 sp32 bit13 */
			{41866,40,0}, /* core3 sp32 bit14 */
			{41865,40,0}, /* core3 sp32 bit15 */
			{41864,40,0}, /* core3 sp32 bit16 */
			{41679,40,0}, /* core3 sp32 bit17 */
			{41678,40,0}, /* core3 sp32 bit18 */
			{41870,40,0}, /* core3 sp32 bit19 */
			{41677,40,0}, /* core3 sp32 bit20 */
			{41676,40,0}, /* core3 sp32 bit21 */
			{41671,40,0}, /* core3 sp32 bit22 */
			{41670,40,0}, /* core3 sp32 bit23 */
			{41669,40,0}, /* core3 sp32 bit24 */
			{41668,40,0}, /* core3 sp32 bit25 */
			{41869,40,0}, /* core3 sp32 bit26 */
			{41667,40,0}, /* core3 sp32 bit27 */
			{41666,40,0}, /* core3 sp32 bit28 */
			{41665,40,0}, /* core3 sp32 bit29 */
			{41664,40,0}, /* core3 sp32 bit30 */
			{41868,40,0}, /* core3 sp32 bit31 */
			{41483,40,0}, /* core3 sp32 bit32 */
			{41482,40,0}, /* core3 sp32 bit33 */
			{41481,40,0}, /* core3 sp32 bit34 */
			{41480,40,0}, /* core3 sp32 bit35 */
			{36299,40,0}, /* core3 sp32 bit36 */
			{28101,40,0}, /* core3 sp32 bit37 */
			{36298,40,0}, /* core3 sp32 bit38 */
			{41535,40,0}, /* core3 sp32 bit39 */
			{41534,40,0}, /* core3 sp32 bit40 */
			{41533,40,0}, /* core3 sp32 bit41 */
			{41532,40,0}, /* core3 sp32 bit42 */
			{41479,40,0}, /* core3 sp32 bit43 */
			{41478,40,0}, /* core3 sp32 bit44 */
			{41477,40,0}, /* core3 sp32 bit45 */
			{41476,40,0}, /* core3 sp32 bit46 */
			{36277,40,0}, /* core3 sp32 bit47 */
			{36276,40,0}, /* core3 sp32 bit48 */
			{41531,40,0}, /* core3 sp32 bit49 */
			{41530,40,0}, /* core3 sp32 bit50 */
			{41529,40,0}, /* core3 sp32 bit51 */
			{41528,40,0}, /* core3 sp32 bit52 */
			{41523,40,0}, /* core3 sp32 bit53 */
			{41522,40,0}, /* core3 sp32 bit54 */
			{41521,40,0}, /* core3 sp32 bit55 */
			{41520,40,0}, /* core3 sp32 bit56 */
			{41527,40,0}, /* core3 sp32 bit57 */
			{41526,40,0}, /* core3 sp32 bit58 */
			{41525,40,0}, /* core3 sp32 bit59 */
			{41524,40,0}, /* core3 sp32 bit60 */
			{41519,40,0}, /* core3 sp32 bit61 */
			{41518,40,0}, /* core3 sp32 bit62 */
			{41517,40,0}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{42038,40,0}, /* core3 fp32 bit0 */
			{42037,40,0}, /* core3 fp32 bit1 */
			{42021,40,0}, /* core3 fp32 bit2 */
			{42020,40,0}, /* core3 fp32 bit3 */
			{42036,40,0}, /* core3 fp32 bit4 */
			{42043,40,0}, /* core3 fp32 bit5 */
			{42042,40,0}, /* core3 fp32 bit6 */
			{42041,40,0}, /* core3 fp32 bit7 */
			{42040,40,0}, /* core3 fp32 bit8 */
			{42027,40,0}, /* core3 fp32 bit9 */
			{42031,40,0}, /* core3 fp32 bit10 */
			{42030,40,0}, /* core3 fp32 bit11 */
			{42029,40,0}, /* core3 fp32 bit12 */
			{42028,40,0}, /* core3 fp32 bit13 */
			{42015,40,0}, /* core3 fp32 bit14 */
			{42014,40,0}, /* core3 fp32 bit15 */
			{42026,40,0}, /* core3 fp32 bit16 */
			{42013,40,0}, /* core3 fp32 bit17 */
			{42035,40,0}, /* core3 fp32 bit18 */
			{42034,40,0}, /* core3 fp32 bit19 */
			{42033,40,0}, /* core3 fp32 bit20 */
			{42012,40,0}, /* core3 fp32 bit21 */
			{42019,40,0}, /* core3 fp32 bit22 */
			{42018,40,0}, /* core3 fp32 bit23 */
			{42017,40,0}, /* core3 fp32 bit24 */
			{42032,40,0}, /* core3 fp32 bit25 */
			{42016,40,0}, /* core3 fp32 bit26 */
			{42023,40,0}, /* core3 fp32 bit27 */
			{42025,40,0}, /* core3 fp32 bit28 */
			{42022,40,0}, /* core3 fp32 bit29 */
			{42024,40,0}, /* core3 fp32 bit30 */
			{42039,40,0}, /* core3 fp32 bit31 */
			{42143,40,0}, /* core3 fp32 bit32 */
			{42142,40,0}, /* core3 fp32 bit33 */
			{42141,40,0}, /* core3 fp32 bit34 */
			{42140,40,0}, /* core3 fp32 bit35 */
			{42135,40,0}, /* core3 fp32 bit36 */
			{42134,40,0}, /* core3 fp32 bit37 */
			{42133,40,0}, /* core3 fp32 bit38 */
			{42132,40,0}, /* core3 fp32 bit39 */
			{42131,40,0}, /* core3 fp32 bit40 */
			{42130,40,0}, /* core3 fp32 bit41 */
			{42129,40,0}, /* core3 fp32 bit42 */
			{42128,40,0}, /* core3 fp32 bit43 */
			{42139,40,0}, /* core3 fp32 bit44 */
			{42138,40,0}, /* core3 fp32 bit45 */
			{42137,40,0}, /* core3 fp32 bit46 */
			{42136,40,0}, /* core3 fp32 bit47 */
			{28149,40,0}, /* core3 fp32 bit48 */
			{42151,40,0}, /* core3 fp32 bit49 */
			{42150,40,0}, /* core3 fp32 bit50 */
			{42149,40,0}, /* core3 fp32 bit51 */
			{42148,40,0}, /* core3 fp32 bit52 */
			{42155,40,0}, /* core3 fp32 bit53 */
			{42154,40,0}, /* core3 fp32 bit54 */
			{42153,40,0}, /* core3 fp32 bit55 */
			{42152,40,0}, /* core3 fp32 bit56 */
			{42147,40,0}, /* core3 fp32 bit57 */
			{42146,40,0}, /* core3 fp32 bit58 */
			{42145,40,0}, /* core3 fp32 bit59 */
			{42144,40,0}, /* core3 fp32 bit60 */
			{42159,40,0}, /* core3 fp32 bit61 */
			{42158,40,0}, /* core3 fp32 bit62 */
			{42157,40,0}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{40979,40,0}, /* core3 fp64 bit0 */
			{40978,40,0}, /* core3 fp64 bit1 */
			{28248,40,0}, /* core3 fp64 bit2 */
			{40999,40,0}, /* core3 fp64 bit3 */
			{36342,40,0}, /* core3 fp64 bit4 */
			{40977,40,0}, /* core3 fp64 bit5 */
			{40970,40,0}, /* core3 fp64 bit6 */
			{40976,40,0}, /* core3 fp64 bit7 */
			{40969,40,0}, /* core3 fp64 bit8 */
			{40968,40,0}, /* core3 fp64 bit9 */
			{40975,40,0}, /* core3 fp64 bit10 */
			{40974,40,0}, /* core3 fp64 bit11 */
			{40987,40,0}, /* core3 fp64 bit12 */
			{40986,40,0}, /* core3 fp64 bit13 */
			{40985,40,0}, /* core3 fp64 bit14 */
			{40973,40,0}, /* core3 fp64 bit15 */
			{40998,40,0}, /* core3 fp64 bit16 */
			{40997,40,0}, /* core3 fp64 bit17 */
			{40996,40,0}, /* core3 fp64 bit18 */
			{36343,40,0}, /* core3 fp64 bit19 */
			{40995,40,0}, /* core3 fp64 bit20 */
			{40972,40,0}, /* core3 fp64 bit21 */
			{40984,40,0}, /* core3 fp64 bit22 */
			{40983,40,0}, /* core3 fp64 bit23 */
			{28249,40,0}, /* core3 fp64 bit24 */
			{40982,40,0}, /* core3 fp64 bit25 */
			{40994,40,0}, /* core3 fp64 bit26 */
			{40981,40,0}, /* core3 fp64 bit27 */
			{40993,40,0}, /* core3 fp64 bit28 */
			{40992,40,0}, /* core3 fp64 bit29 */
			{40980,40,0}, /* core3 fp64 bit30 */
			{40971,40,0}, /* core3 fp64 bit31 */
			{41143,40,0}, /* core3 fp64 bit32 */
			{41142,40,0}, /* core3 fp64 bit33 */
			{41141,40,0}, /* core3 fp64 bit34 */
			{28127,40,0}, /* core3 fp64 bit35 */
			{41140,40,0}, /* core3 fp64 bit36 */
			{36435,40,0}, /* core3 fp64 bit37 */
			{41151,40,0}, /* core3 fp64 bit38 */
			{41150,40,0}, /* core3 fp64 bit39 */
			{41149,40,0}, /* core3 fp64 bit40 */
			{41148,40,0}, /* core3 fp64 bit41 */
			{41147,40,0}, /* core3 fp64 bit42 */
			{41146,40,0}, /* core3 fp64 bit43 */
			{41145,40,0}, /* core3 fp64 bit44 */
			{28114,40,0}, /* core3 fp64 bit45 */
			{36434,40,0}, /* core3 fp64 bit46 */
			{41144,40,0}, /* core3 fp64 bit47 */
			{28132,40,0}, /* core3 fp64 bit48 */
			{36455,40,0}, /* core3 fp64 bit49 */
			{41119,40,0}, /* core3 fp64 bit50 */
			{41118,40,0}, /* core3 fp64 bit51 */
			{41117,40,0}, /* core3 fp64 bit52 */
			{36454,40,0}, /* core3 fp64 bit53 */
			{41116,40,0}, /* core3 fp64 bit54 */
			{41135,40,0}, /* core3 fp64 bit55 */
			{41134,40,0}, /* core3 fp64 bit56 */
			{41133,40,0}, /* core3 fp64 bit57 */
			{41132,40,0}, /* core3 fp64 bit58 */
			{28131,40,0}, /* core3 fp64 bit59 */
			{41115,40,0}, /* core3 fp64 bit60 */
			{41114,40,0}, /* core3 fp64 bit61 */
			{41113,40,0}, /* core3 fp64 bit62 */
			{41112,40,0}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40942,40,0}, /* core3 sp_EL0 bit0 */
			{40941,40,0}, /* core3 sp_EL0 bit1 */
			{40940,40,0}, /* core3 sp_EL0 bit2 */
			{41010,40,0}, /* core3 sp_EL0 bit3 */
			{41009,40,0}, /* core3 sp_EL0 bit4 */
			{40939,40,0}, /* core3 sp_EL0 bit5 */
			{40938,40,0}, /* core3 sp_EL0 bit6 */
			{40937,40,0}, /* core3 sp_EL0 bit7 */
			{40936,40,0}, /* core3 sp_EL0 bit8 */
			{40931,40,0}, /* core3 sp_EL0 bit9 */
			{40947,40,0}, /* core3 sp_EL0 bit10 */
			{40930,40,0}, /* core3 sp_EL0 bit11 */
			{40929,40,0}, /* core3 sp_EL0 bit12 */
			{40928,40,0}, /* core3 sp_EL0 bit13 */
			{40951,40,0}, /* core3 sp_EL0 bit14 */
			{40950,40,0}, /* core3 sp_EL0 bit15 */
			{41008,40,0}, /* core3 sp_EL0 bit16 */
			{41015,40,0}, /* core3 sp_EL0 bit17 */
			{41014,40,0}, /* core3 sp_EL0 bit18 */
			{41011,40,0}, /* core3 sp_EL0 bit19 */
			{41013,40,0}, /* core3 sp_EL0 bit20 */
			{40946,40,0}, /* core3 sp_EL0 bit21 */
			{40949,40,0}, /* core3 sp_EL0 bit22 */
			{40945,40,0}, /* core3 sp_EL0 bit23 */
			{28259,40,0}, /* core3 sp_EL0 bit24 */
			{40944,40,0}, /* core3 sp_EL0 bit25 */
			{41012,40,0}, /* core3 sp_EL0 bit26 */
			{36257,40,0}, /* core3 sp_EL0 bit27 */
			{36347,40,0}, /* core3 sp_EL0 bit28 */
			{36346,40,0}, /* core3 sp_EL0 bit29 */
			{36256,40,0}, /* core3 sp_EL0 bit30 */
			{40943,40,0}, /* core3 sp_EL0 bit31 */
			{41063,40,0}, /* core3 sp_EL0 bit32 */
			{41059,40,0}, /* core3 sp_EL0 bit33 */
			{41058,40,0}, /* core3 sp_EL0 bit34 */
			{41062,40,0}, /* core3 sp_EL0 bit35 */
			{41061,40,0}, /* core3 sp_EL0 bit36 */
			{41057,40,0}, /* core3 sp_EL0 bit37 */
			{41060,40,0}, /* core3 sp_EL0 bit38 */
			{41071,40,0}, /* core3 sp_EL0 bit39 */
			{41070,40,0}, /* core3 sp_EL0 bit40 */
			{41069,40,0}, /* core3 sp_EL0 bit41 */
			{41056,40,0}, /* core3 sp_EL0 bit42 */
			{41068,40,0}, /* core3 sp_EL0 bit43 */
			{41067,40,0}, /* core3 sp_EL0 bit44 */
			{41066,40,0}, /* core3 sp_EL0 bit45 */
			{41065,40,0}, /* core3 sp_EL0 bit46 */
			{41064,40,0}, /* core3 sp_EL0 bit47 */
			{28157,40,0}, /* core3 sp_EL0 bit48 */
			{41103,40,0}, /* core3 sp_EL0 bit49 */
			{41102,40,0}, /* core3 sp_EL0 bit50 */
			{41101,40,0}, /* core3 sp_EL0 bit51 */
			{41100,40,0}, /* core3 sp_EL0 bit52 */
			{41107,40,0}, /* core3 sp_EL0 bit53 */
			{41106,40,0}, /* core3 sp_EL0 bit54 */
			{41105,40,0}, /* core3 sp_EL0 bit55 */
			{41104,40,0}, /* core3 sp_EL0 bit56 */
			{41055,40,0}, /* core3 sp_EL0 bit57 */
			{41054,40,0}, /* core3 sp_EL0 bit58 */
			{41053,40,0}, /* core3 sp_EL0 bit59 */
			{41052,40,0}, /* core3 sp_EL0 bit60 */
			{41111,40,0}, /* core3 sp_EL0 bit61 */
			{41110,40,0}, /* core3 sp_EL0 bit62 */
			{41109,40,0}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40935,40,0}, /* core3 sp_EL1 bit0 */
			{40934,40,0}, /* core3 sp_EL1 bit1 */
			{40902,40,0}, /* core3 sp_EL1 bit2 */
			{40882,40,0}, /* core3 sp_EL1 bit3 */
			{40881,40,0}, /* core3 sp_EL1 bit4 */
			{40933,40,0}, /* core3 sp_EL1 bit5 */
			{40901,40,0}, /* core3 sp_EL1 bit6 */
			{40932,40,0}, /* core3 sp_EL1 bit7 */
			{40900,40,0}, /* core3 sp_EL1 bit8 */
			{40927,40,0}, /* core3 sp_EL1 bit9 */
			{40926,40,0}, /* core3 sp_EL1 bit10 */
			{40923,40,0}, /* core3 sp_EL1 bit11 */
			{40922,40,0}, /* core3 sp_EL1 bit12 */
			{40921,40,0}, /* core3 sp_EL1 bit13 */
			{40920,40,0}, /* core3 sp_EL1 bit14 */
			{40925,40,0}, /* core3 sp_EL1 bit15 */
			{40880,40,0}, /* core3 sp_EL1 bit16 */
			{40879,40,0}, /* core3 sp_EL1 bit17 */
			{40878,40,0}, /* core3 sp_EL1 bit18 */
			{36259,40,0}, /* core3 sp_EL1 bit19 */
			{40877,40,0}, /* core3 sp_EL1 bit20 */
			{40924,40,0}, /* core3 sp_EL1 bit21 */
			{28258,40,0}, /* core3 sp_EL1 bit22 */
			{40899,40,0}, /* core3 sp_EL1 bit23 */
			{36258,40,0}, /* core3 sp_EL1 bit24 */
			{40898,40,0}, /* core3 sp_EL1 bit25 */
			{40883,40,0}, /* core3 sp_EL1 bit26 */
			{40897,40,0}, /* core3 sp_EL1 bit27 */
			{40876,40,0}, /* core3 sp_EL1 bit28 */
			{28244,40,0}, /* core3 sp_EL1 bit29 */
			{40896,40,0}, /* core3 sp_EL1 bit30 */
			{40903,40,0}, /* core3 sp_EL1 bit31 */
			{40803,40,0}, /* core3 sp_EL1 bit32 */
			{40799,40,0}, /* core3 sp_EL1 bit33 */
			{40798,40,0}, /* core3 sp_EL1 bit34 */
			{40802,40,0}, /* core3 sp_EL1 bit35 */
			{40801,40,0}, /* core3 sp_EL1 bit36 */
			{40797,40,0}, /* core3 sp_EL1 bit37 */
			{40800,40,0}, /* core3 sp_EL1 bit38 */
			{40791,40,0}, /* core3 sp_EL1 bit39 */
			{40790,40,0}, /* core3 sp_EL1 bit40 */
			{40789,40,0}, /* core3 sp_EL1 bit41 */
			{40796,40,0}, /* core3 sp_EL1 bit42 */
			{40788,40,0}, /* core3 sp_EL1 bit43 */
			{40795,40,0}, /* core3 sp_EL1 bit44 */
			{40794,40,0}, /* core3 sp_EL1 bit45 */
			{40792,40,0}, /* core3 sp_EL1 bit46 */
			{40793,40,0}, /* core3 sp_EL1 bit47 */
			{28158,40,0}, /* core3 sp_EL1 bit48 */
			{36423,40,0}, /* core3 sp_EL1 bit49 */
			{40839,40,0}, /* core3 sp_EL1 bit50 */
			{40838,40,0}, /* core3 sp_EL1 bit51 */
			{40837,40,0}, /* core3 sp_EL1 bit52 */
			{36422,40,0}, /* core3 sp_EL1 bit53 */
			{40836,40,0}, /* core3 sp_EL1 bit54 */
			{40831,40,0}, /* core3 sp_EL1 bit55 */
			{40830,40,0}, /* core3 sp_EL1 bit56 */
			{40829,40,0}, /* core3 sp_EL1 bit57 */
			{40828,40,0}, /* core3 sp_EL1 bit58 */
			{28159,40,0}, /* core3 sp_EL1 bit59 */
			{40835,40,0}, /* core3 sp_EL1 bit60 */
			{40834,40,0}, /* core3 sp_EL1 bit61 */
			{40833,40,0}, /* core3 sp_EL1 bit62 */
			{40832,40,0}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40906,40,0}, /* core3 sp_EL2 bit0 */
			{40905,40,0}, /* core3 sp_EL2 bit1 */
			{40904,40,0}, /* core3 sp_EL2 bit2 */
			{40886,40,0}, /* core3 sp_EL2 bit3 */
			{40891,40,0}, /* core3 sp_EL2 bit4 */
			{40911,40,0}, /* core3 sp_EL2 bit5 */
			{40910,40,0}, /* core3 sp_EL2 bit6 */
			{40909,40,0}, /* core3 sp_EL2 bit7 */
			{40908,40,0}, /* core3 sp_EL2 bit8 */
			{40919,40,0}, /* core3 sp_EL2 bit9 */
			{40915,40,0}, /* core3 sp_EL2 bit10 */
			{40918,40,0}, /* core3 sp_EL2 bit11 */
			{40917,40,0}, /* core3 sp_EL2 bit12 */
			{40916,40,0}, /* core3 sp_EL2 bit13 */
			{40895,40,0}, /* core3 sp_EL2 bit14 */
			{40894,40,0}, /* core3 sp_EL2 bit15 */
			{40885,40,0}, /* core3 sp_EL2 bit16 */
			{40884,40,0}, /* core3 sp_EL2 bit17 */
			{40890,40,0}, /* core3 sp_EL2 bit18 */
			{28260,40,0}, /* core3 sp_EL2 bit19 */
			{40889,40,0}, /* core3 sp_EL2 bit20 */
			{40914,40,0}, /* core3 sp_EL2 bit21 */
			{40893,40,0}, /* core3 sp_EL2 bit22 */
			{40913,40,0}, /* core3 sp_EL2 bit23 */
			{40888,40,0}, /* core3 sp_EL2 bit24 */
			{40912,40,0}, /* core3 sp_EL2 bit25 */
			{40887,40,0}, /* core3 sp_EL2 bit26 */
			{36261,40,0}, /* core3 sp_EL2 bit27 */
			{36255,40,0}, /* core3 sp_EL2 bit28 */
			{36254,40,0}, /* core3 sp_EL2 bit29 */
			{36260,40,0}, /* core3 sp_EL2 bit30 */
			{40907,40,0}, /* core3 sp_EL2 bit31 */
			{40811,40,0}, /* core3 sp_EL2 bit32 */
			{40810,40,0}, /* core3 sp_EL2 bit33 */
			{40809,40,0}, /* core3 sp_EL2 bit34 */
			{40808,40,0}, /* core3 sp_EL2 bit35 */
			{40783,40,0}, /* core3 sp_EL2 bit36 */
			{40782,40,0}, /* core3 sp_EL2 bit37 */
			{40781,40,0}, /* core3 sp_EL2 bit38 */
			{40780,40,0}, /* core3 sp_EL2 bit39 */
			{40787,40,0}, /* core3 sp_EL2 bit40 */
			{40786,40,0}, /* core3 sp_EL2 bit41 */
			{40785,40,0}, /* core3 sp_EL2 bit42 */
			{40784,40,0}, /* core3 sp_EL2 bit43 */
			{40755,40,0}, /* core3 sp_EL2 bit44 */
			{40754,40,0}, /* core3 sp_EL2 bit45 */
			{40752,40,0}, /* core3 sp_EL2 bit46 */
			{40753,40,0}, /* core3 sp_EL2 bit47 */
			{28170,40,0}, /* core3 sp_EL2 bit48 */
			{28161,40,0}, /* core3 sp_EL2 bit49 */
			{40847,40,0}, /* core3 sp_EL2 bit50 */
			{40846,40,0}, /* core3 sp_EL2 bit51 */
			{40845,40,0}, /* core3 sp_EL2 bit52 */
			{40844,40,0}, /* core3 sp_EL2 bit53 */
			{40843,40,0}, /* core3 sp_EL2 bit54 */
			{40842,40,0}, /* core3 sp_EL2 bit55 */
			{40841,40,0}, /* core3 sp_EL2 bit56 */
			{40840,40,0}, /* core3 sp_EL2 bit57 */
			{40815,40,0}, /* core3 sp_EL2 bit58 */
			{40814,40,0}, /* core3 sp_EL2 bit59 */
			{40813,40,0}, /* core3 sp_EL2 bit60 */
			{40812,40,0}, /* core3 sp_EL2 bit61 */
			{36421,40,0}, /* core3 sp_EL2 bit62 */
			{36420,40,0}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40861,40,0}, /* core3 sp_EL3 bit0 */
			{40860,40,0}, /* core3 sp_EL3 bit1 */
			{40739,40,0}, /* core3 sp_EL3 bit2 */
			{40875,40,0}, /* core3 sp_EL3 bit3 */
			{40874,40,0}, /* core3 sp_EL3 bit4 */
			{40738,40,0}, /* core3 sp_EL3 bit5 */
			{40737,40,0}, /* core3 sp_EL3 bit6 */
			{40736,40,0}, /* core3 sp_EL3 bit7 */
			{40867,40,0}, /* core3 sp_EL3 bit8 */
			{40866,40,0}, /* core3 sp_EL3 bit9 */
			{40865,40,0}, /* core3 sp_EL3 bit10 */
			{40864,40,0}, /* core3 sp_EL3 bit11 */
			{40743,40,0}, /* core3 sp_EL3 bit12 */
			{40742,40,0}, /* core3 sp_EL3 bit13 */
			{40741,40,0}, /* core3 sp_EL3 bit14 */
			{40740,40,0}, /* core3 sp_EL3 bit15 */
			{40873,40,0}, /* core3 sp_EL3 bit16 */
			{40872,40,0}, /* core3 sp_EL3 bit17 */
			{40871,40,0}, /* core3 sp_EL3 bit18 */
			{40863,40,0}, /* core3 sp_EL3 bit19 */
			{40870,40,0}, /* core3 sp_EL3 bit20 */
			{40735,40,0}, /* core3 sp_EL3 bit21 */
			{40734,40,0}, /* core3 sp_EL3 bit22 */
			{40733,40,0}, /* core3 sp_EL3 bit23 */
			{28185,40,0}, /* core3 sp_EL3 bit24 */
			{40732,40,0}, /* core3 sp_EL3 bit25 */
			{40869,40,0}, /* core3 sp_EL3 bit26 */
			{36251,40,0}, /* core3 sp_EL3 bit27 */
			{40868,40,0}, /* core3 sp_EL3 bit28 */
			{28186,40,0}, /* core3 sp_EL3 bit29 */
			{36250,40,0}, /* core3 sp_EL3 bit30 */
			{40862,40,0}, /* core3 sp_EL3 bit31 */
			{40807,40,0}, /* core3 sp_EL3 bit32 */
			{40806,40,0}, /* core3 sp_EL3 bit33 */
			{40805,40,0}, /* core3 sp_EL3 bit34 */
			{40804,40,0}, /* core3 sp_EL3 bit35 */
			{40763,40,0}, /* core3 sp_EL3 bit36 */
			{40762,40,0}, /* core3 sp_EL3 bit37 */
			{40761,40,0}, /* core3 sp_EL3 bit38 */
			{40760,40,0}, /* core3 sp_EL3 bit39 */
			{40767,40,0}, /* core3 sp_EL3 bit40 */
			{40766,40,0}, /* core3 sp_EL3 bit41 */
			{40765,40,0}, /* core3 sp_EL3 bit42 */
			{40764,40,0}, /* core3 sp_EL3 bit43 */
			{40759,40,0}, /* core3 sp_EL3 bit44 */
			{40758,40,0}, /* core3 sp_EL3 bit45 */
			{40756,40,0}, /* core3 sp_EL3 bit46 */
			{40757,40,0}, /* core3 sp_EL3 bit47 */
			{28172,40,0}, /* core3 sp_EL3 bit48 */
			{36425,40,0}, /* core3 sp_EL3 bit49 */
			{40827,40,0}, /* core3 sp_EL3 bit50 */
			{40826,40,0}, /* core3 sp_EL3 bit51 */
			{40825,40,0}, /* core3 sp_EL3 bit52 */
			{40824,40,0}, /* core3 sp_EL3 bit53 */
			{40823,40,0}, /* core3 sp_EL3 bit54 */
			{40822,40,0}, /* core3 sp_EL3 bit55 */
			{40821,40,0}, /* core3 sp_EL3 bit56 */
			{40820,40,0}, /* core3 sp_EL3 bit57 */
			{40819,40,0}, /* core3 sp_EL3 bit58 */
			{36424,40,0}, /* core3 sp_EL3 bit59 */
			{40818,40,0}, /* core3 sp_EL3 bit60 */
			{40817,40,0}, /* core3 sp_EL3 bit61 */
			{40816,40,0}, /* core3 sp_EL3 bit62 */
			{28160,40,0}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{40707,40,0}, /* core3 elr_EL1 bit0 */
			{40706,40,0}, /* core3 elr_EL1 bit1 */
			{40705,40,0}, /* core3 elr_EL1 bit2 */
			{40723,40,0}, /* core3 elr_EL1 bit3 */
			{40722,40,0}, /* core3 elr_EL1 bit4 */
			{40704,40,0}, /* core3 elr_EL1 bit5 */
			{40703,40,0}, /* core3 elr_EL1 bit6 */
			{40702,40,0}, /* core3 elr_EL1 bit7 */
			{40701,40,0}, /* core3 elr_EL1 bit8 */
			{40700,40,0}, /* core3 elr_EL1 bit9 */
			{40695,40,0}, /* core3 elr_EL1 bit10 */
			{40694,40,0}, /* core3 elr_EL1 bit11 */
			{40693,40,0}, /* core3 elr_EL1 bit12 */
			{40692,40,0}, /* core3 elr_EL1 bit13 */
			{40699,40,0}, /* core3 elr_EL1 bit14 */
			{40698,40,0}, /* core3 elr_EL1 bit15 */
			{40721,40,0}, /* core3 elr_EL1 bit16 */
			{40720,40,0}, /* core3 elr_EL1 bit17 */
			{40727,40,0}, /* core3 elr_EL1 bit18 */
			{40697,40,0}, /* core3 elr_EL1 bit19 */
			{40726,40,0}, /* core3 elr_EL1 bit20 */
			{40696,40,0}, /* core3 elr_EL1 bit21 */
			{40715,40,0}, /* core3 elr_EL1 bit22 */
			{40714,40,0}, /* core3 elr_EL1 bit23 */
			{28252,40,0}, /* core3 elr_EL1 bit24 */
			{40713,40,0}, /* core3 elr_EL1 bit25 */
			{40725,40,0}, /* core3 elr_EL1 bit26 */
			{40712,40,0}, /* core3 elr_EL1 bit27 */
			{40724,40,0}, /* core3 elr_EL1 bit28 */
			{28251,40,0}, /* core3 elr_EL1 bit29 */
			{36265,40,0}, /* core3 elr_EL1 bit30 */
			{36264,40,0}, /* core3 elr_EL1 bit31 */
			{40751,40,0}, /* core3 elr_EL1 bit32 */
			{40750,40,0}, /* core3 elr_EL1 bit33 */
			{40749,40,0}, /* core3 elr_EL1 bit34 */
			{40748,40,0}, /* core3 elr_EL1 bit35 */
			{40771,40,0}, /* core3 elr_EL1 bit36 */
			{40770,40,0}, /* core3 elr_EL1 bit37 */
			{40769,40,0}, /* core3 elr_EL1 bit38 */
			{40768,40,0}, /* core3 elr_EL1 bit39 */
			{40775,40,0}, /* core3 elr_EL1 bit40 */
			{40774,40,0}, /* core3 elr_EL1 bit41 */
			{40773,40,0}, /* core3 elr_EL1 bit42 */
			{40772,40,0}, /* core3 elr_EL1 bit43 */
			{40779,40,0}, /* core3 elr_EL1 bit44 */
			{40778,40,0}, /* core3 elr_EL1 bit45 */
			{40777,40,0}, /* core3 elr_EL1 bit46 */
			{40776,40,0}, /* core3 elr_EL1 bit47 */
			{28165,40,0}, /* core3 elr_EL1 bit48 */
			{40859,40,0}, /* core3 elr_EL1 bit49 */
			{40858,40,0}, /* core3 elr_EL1 bit50 */
			{40857,40,0}, /* core3 elr_EL1 bit51 */
			{40856,40,0}, /* core3 elr_EL1 bit52 */
			{40855,40,0}, /* core3 elr_EL1 bit53 */
			{40854,40,0}, /* core3 elr_EL1 bit54 */
			{40853,40,0}, /* core3 elr_EL1 bit55 */
			{40852,40,0}, /* core3 elr_EL1 bit56 */
			{40747,40,0}, /* core3 elr_EL1 bit57 */
			{40746,40,0}, /* core3 elr_EL1 bit58 */
			{40745,40,0}, /* core3 elr_EL1 bit59 */
			{40744,40,0}, /* core3 elr_EL1 bit60 */
			{40851,40,0}, /* core3 elr_EL1 bit61 */
			{40850,40,0}, /* core3 elr_EL1 bit62 */
			{40849,40,0}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{40711,40,0}, /* core3 elr_EL2 bit0 */
			{40710,40,0}, /* core3 elr_EL2 bit1 */
			{40709,40,0}, /* core3 elr_EL2 bit2 */
			{40719,40,0}, /* core3 elr_EL2 bit3 */
			{40718,40,0}, /* core3 elr_EL2 bit4 */
			{40708,40,0}, /* core3 elr_EL2 bit5 */
			{40687,40,0}, /* core3 elr_EL2 bit6 */
			{40691,40,0}, /* core3 elr_EL2 bit7 */
			{40690,40,0}, /* core3 elr_EL2 bit8 */
			{40689,40,0}, /* core3 elr_EL2 bit9 */
			{40686,40,0}, /* core3 elr_EL2 bit10 */
			{40688,40,0}, /* core3 elr_EL2 bit11 */
			{40683,40,0}, /* core3 elr_EL2 bit12 */
			{40682,40,0}, /* core3 elr_EL2 bit13 */
			{40681,40,0}, /* core3 elr_EL2 bit14 */
			{40685,40,0}, /* core3 elr_EL2 bit15 */
			{40717,40,0}, /* core3 elr_EL2 bit16 */
			{40716,40,0}, /* core3 elr_EL2 bit17 */
			{40731,40,0}, /* core3 elr_EL2 bit18 */
			{40684,40,0}, /* core3 elr_EL2 bit19 */
			{40730,40,0}, /* core3 elr_EL2 bit20 */
			{40679,40,0}, /* core3 elr_EL2 bit21 */
			{40680,40,0}, /* core3 elr_EL2 bit22 */
			{40678,40,0}, /* core3 elr_EL2 bit23 */
			{28253,40,0}, /* core3 elr_EL2 bit24 */
			{40677,40,0}, /* core3 elr_EL2 bit25 */
			{40729,40,0}, /* core3 elr_EL2 bit26 */
			{40676,40,0}, /* core3 elr_EL2 bit27 */
			{40728,40,0}, /* core3 elr_EL2 bit28 */
			{28254,40,0}, /* core3 elr_EL2 bit29 */
			{28255,40,0}, /* core3 elr_EL2 bit30 */
			{28256,40,0}, /* core3 elr_EL2 bit31 */
			{40501,40,0}, /* core3 elr_EL2 bit32 */
			{40500,40,0}, /* core3 elr_EL2 bit33 */
			{40499,40,0}, /* core3 elr_EL2 bit34 */
			{40498,40,0}, /* core3 elr_EL2 bit35 */
			{40481,40,0}, /* core3 elr_EL2 bit36 */
			{40480,40,0}, /* core3 elr_EL2 bit37 */
			{40479,40,0}, /* core3 elr_EL2 bit38 */
			{40478,40,0}, /* core3 elr_EL2 bit39 */
			{40477,40,0}, /* core3 elr_EL2 bit40 */
			{40476,40,0}, /* core3 elr_EL2 bit41 */
			{40475,40,0}, /* core3 elr_EL2 bit42 */
			{40474,40,0}, /* core3 elr_EL2 bit43 */
			{40485,40,0}, /* core3 elr_EL2 bit44 */
			{40484,40,0}, /* core3 elr_EL2 bit45 */
			{40483,40,0}, /* core3 elr_EL2 bit46 */
			{40482,40,0}, /* core3 elr_EL2 bit47 */
			{28164,40,0}, /* core3 elr_EL2 bit48 */
			{40509,40,0}, /* core3 elr_EL2 bit49 */
			{40508,40,0}, /* core3 elr_EL2 bit50 */
			{40507,40,0}, /* core3 elr_EL2 bit51 */
			{40506,40,0}, /* core3 elr_EL2 bit52 */
			{40465,40,0}, /* core3 elr_EL2 bit53 */
			{40464,40,0}, /* core3 elr_EL2 bit54 */
			{40463,40,0}, /* core3 elr_EL2 bit55 */
			{40462,40,0}, /* core3 elr_EL2 bit56 */
			{40473,40,0}, /* core3 elr_EL2 bit57 */
			{40472,40,0}, /* core3 elr_EL2 bit58 */
			{40471,40,0}, /* core3 elr_EL2 bit59 */
			{40470,40,0}, /* core3 elr_EL2 bit60 */
			{40469,40,0}, /* core3 elr_EL2 bit61 */
			{40468,40,0}, /* core3 elr_EL2 bit62 */
			{40467,40,0}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{40452,40,0}, /* core3 elr_EL3 bit0 */
			{40451,40,0}, /* core3 elr_EL3 bit1 */
			{40450,40,0}, /* core3 elr_EL3 bit2 */
			{40437,40,0}, /* core3 elr_EL3 bit3 */
			{40436,40,0}, /* core3 elr_EL3 bit4 */
			{40441,40,0}, /* core3 elr_EL3 bit5 */
			{40440,40,0}, /* core3 elr_EL3 bit6 */
			{40439,40,0}, /* core3 elr_EL3 bit7 */
			{40438,40,0}, /* core3 elr_EL3 bit8 */
			{40449,40,0}, /* core3 elr_EL3 bit9 */
			{40448,40,0}, /* core3 elr_EL3 bit10 */
			{40447,40,0}, /* core3 elr_EL3 bit11 */
			{40446,40,0}, /* core3 elr_EL3 bit12 */
			{40457,40,0}, /* core3 elr_EL3 bit13 */
			{40456,40,0}, /* core3 elr_EL3 bit14 */
			{40455,40,0}, /* core3 elr_EL3 bit15 */
			{40435,40,0}, /* core3 elr_EL3 bit16 */
			{40434,40,0}, /* core3 elr_EL3 bit17 */
			{40461,40,0}, /* core3 elr_EL3 bit18 */
			{40445,40,0}, /* core3 elr_EL3 bit19 */
			{40460,40,0}, /* core3 elr_EL3 bit20 */
			{40444,40,0}, /* core3 elr_EL3 bit21 */
			{40454,40,0}, /* core3 elr_EL3 bit22 */
			{40443,40,0}, /* core3 elr_EL3 bit23 */
			{28245,40,0}, /* core3 elr_EL3 bit24 */
			{40442,40,0}, /* core3 elr_EL3 bit25 */
			{40459,40,0}, /* core3 elr_EL3 bit26 */
			{36263,40,0}, /* core3 elr_EL3 bit27 */
			{40458,40,0}, /* core3 elr_EL3 bit28 */
			{28246,40,0}, /* core3 elr_EL3 bit29 */
			{36262,40,0}, /* core3 elr_EL3 bit30 */
			{40453,40,0}, /* core3 elr_EL3 bit31 */
			{40505,40,0}, /* core3 elr_EL3 bit32 */
			{40504,40,0}, /* core3 elr_EL3 bit33 */
			{40503,40,0}, /* core3 elr_EL3 bit34 */
			{40493,40,0}, /* core3 elr_EL3 bit35 */
			{40492,40,0}, /* core3 elr_EL3 bit36 */
			{40502,40,0}, /* core3 elr_EL3 bit37 */
			{40491,40,0}, /* core3 elr_EL3 bit38 */
			{40490,40,0}, /* core3 elr_EL3 bit39 */
			{40489,40,0}, /* core3 elr_EL3 bit40 */
			{40488,40,0}, /* core3 elr_EL3 bit41 */
			{40497,40,0}, /* core3 elr_EL3 bit42 */
			{40487,40,0}, /* core3 elr_EL3 bit43 */
			{40496,40,0}, /* core3 elr_EL3 bit44 */
			{40495,40,0}, /* core3 elr_EL3 bit45 */
			{36215,40,0}, /* core3 elr_EL3 bit46 */
			{40494,40,0}, /* core3 elr_EL3 bit47 */
			{36214,40,0}, /* core3 elr_EL3 bit48 */
			{40517,40,0}, /* core3 elr_EL3 bit49 */
			{40516,40,0}, /* core3 elr_EL3 bit50 */
			{40515,40,0}, /* core3 elr_EL3 bit51 */
			{40514,40,0}, /* core3 elr_EL3 bit52 */
			{40521,40,0}, /* core3 elr_EL3 bit53 */
			{40520,40,0}, /* core3 elr_EL3 bit54 */
			{40519,40,0}, /* core3 elr_EL3 bit55 */
			{40518,40,0}, /* core3 elr_EL3 bit56 */
			{40513,40,0}, /* core3 elr_EL3 bit57 */
			{40512,40,0}, /* core3 elr_EL3 bit58 */
			{40511,40,0}, /* core3 elr_EL3 bit59 */
			{40510,40,0}, /* core3 elr_EL3 bit60 */
			{40433,40,0}, /* core3 elr_EL3 bit61 */
			{40432,40,0}, /* core3 elr_EL3 bit62 */
			{40431,40,0}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{30898,40,0}, /* core3 raw_pc bit0 */
			{33534,39,0}, /* core3 raw_pc bit1 */
			{33533,39,0}, /* core3 raw_pc bit2 */
			{33532,39,0}, /* core3 raw_pc bit3 */
			{33531,39,0}, /* core3 raw_pc bit4 */
			{37455,40,0}, /* core3 raw_pc bit5 */
			{37454,40,0}, /* core3 raw_pc bit6 */
			{37453,40,0}, /* core3 raw_pc bit7 */
			{37452,40,0}, /* core3 raw_pc bit8 */
			{37451,40,0}, /* core3 raw_pc bit9 */
			{37450,40,0}, /* core3 raw_pc bit10 */
			{37447,40,0}, /* core3 raw_pc bit11 */
			{37446,40,0}, /* core3 raw_pc bit12 */
			{37449,40,0}, /* core3 raw_pc bit13 */
			{37448,40,0}, /* core3 raw_pc bit14 */
			{33538,39,0}, /* core3 raw_pc bit15 */
			{33537,39,0}, /* core3 raw_pc bit16 */
			{33536,39,0}, /* core3 raw_pc bit17 */
			{33535,39,0}, /* core3 raw_pc bit18 */
			{33542,39,0}, /* core3 raw_pc bit19 */
			{33541,39,0}, /* core3 raw_pc bit20 */
			{33540,39,0}, /* core3 raw_pc bit21 */
			{33539,39,0}, /* core3 raw_pc bit22 */
			{33546,39,0}, /* core3 raw_pc bit23 */
			{33545,39,0}, /* core3 raw_pc bit24 */
			{33544,39,0}, /* core3 raw_pc bit25 */
			{33543,39,0}, /* core3 raw_pc bit26 */
			{33482,39,0}, /* core3 raw_pc bit27 */
			{33481,39,0}, /* core3 raw_pc bit28 */
			{33480,39,0}, /* core3 raw_pc bit29 */
			{33479,39,0}, /* core3 raw_pc bit30 */
			{33606,39,0}, /* core3 raw_pc bit31 */
			{33605,39,0}, /* core3 raw_pc bit32 */
			{33604,39,0}, /* core3 raw_pc bit33 */
			{33603,39,0}, /* core3 raw_pc bit34 */
			{37245,40,0}, /* core3 raw_pc bit35 */
			{37244,40,0}, /* core3 raw_pc bit36 */
			{37249,40,0}, /* core3 raw_pc bit37 */
			{37248,40,0}, /* core3 raw_pc bit38 */
			{33602,39,0}, /* core3 raw_pc bit39 */
			{33601,39,0}, /* core3 raw_pc bit40 */
			{33600,39,0}, /* core3 raw_pc bit41 */
			{33599,39,0}, /* core3 raw_pc bit42 */
			{37247,40,0}, /* core3 raw_pc bit43 */
			{37246,40,0}, /* core3 raw_pc bit44 */
			{37251,40,0}, /* core3 raw_pc bit45 */
			{37250,40,0}, /* core3 raw_pc bit46 */
			{33598,39,0}, /* core3 raw_pc bit47 */
			{33597,39,0}, /* core3 raw_pc bit48 */
			{33596,39,0}, /* core3 raw_pc bit49 */
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
			{33491,39,0}, /* core3 pc_iss bit0 */
			{33498,39,0}, /* core3 pc_iss bit1 */
			{33497,39,0}, /* core3 pc_iss bit2 */
			{33496,39,0}, /* core3 pc_iss bit3 */
			{33495,39,0}, /* core3 pc_iss bit4 */
			{33494,39,0}, /* core3 pc_iss bit5 */
			{33493,39,0}, /* core3 pc_iss bit6 */
			{33492,39,0}, /* core3 pc_iss bit7 */
			{33522,39,0}, /* core3 pc_iss bit8 */
			{33521,39,0}, /* core3 pc_iss bit9 */
			{33520,39,0}, /* core3 pc_iss bit10 */
			{33519,39,0}, /* core3 pc_iss bit11 */
			{33470,39,0}, /* core3 pc_iss bit12 */
			{33469,39,0}, /* core3 pc_iss bit13 */
			{33468,39,0}, /* core3 pc_iss bit14 */
			{33467,39,0}, /* core3 pc_iss bit15 */
			{33526,39,0}, /* core3 pc_iss bit16 */
			{33525,39,0}, /* core3 pc_iss bit17 */
			{33524,39,0}, /* core3 pc_iss bit18 */
			{33523,39,0}, /* core3 pc_iss bit19 */
			{33530,39,0}, /* core3 pc_iss bit20 */
			{33529,39,0}, /* core3 pc_iss bit21 */
			{33528,39,0}, /* core3 pc_iss bit22 */
			{33527,39,0}, /* core3 pc_iss bit23 */
			{33474,39,0}, /* core3 pc_iss bit24 */
			{33473,39,0}, /* core3 pc_iss bit25 */
			{33472,39,0}, /* core3 pc_iss bit26 */
			{33471,39,0}, /* core3 pc_iss bit27 */
			{33478,39,0}, /* core3 pc_iss bit28 */
			{33477,39,0}, /* core3 pc_iss bit29 */
			{33476,39,0}, /* core3 pc_iss bit30 */
			{33475,39,0}, /* core3 pc_iss bit31 */
			{33631,39,0}, /* core3 pc_iss bit32 */
			{33618,39,0}, /* core3 pc_iss bit33 */
			{33617,39,0}, /* core3 pc_iss bit34 */
			{33616,39,0}, /* core3 pc_iss bit35 */
			{33621,39,0}, /* core3 pc_iss bit36 */
			{33615,39,0}, /* core3 pc_iss bit37 */
			{33620,39,0}, /* core3 pc_iss bit38 */
			{33619,39,0}, /* core3 pc_iss bit39 */
			{33614,39,0}, /* core3 pc_iss bit40 */
			{33613,39,0}, /* core3 pc_iss bit41 */
			{33610,39,0}, /* core3 pc_iss bit42 */
			{33612,39,0}, /* core3 pc_iss bit43 */
			{33611,39,0}, /* core3 pc_iss bit44 */
			{33630,39,0}, /* core3 pc_iss bit45 */
			{33629,39,0}, /* core3 pc_iss bit46 */
			{33609,39,0}, /* core3 pc_iss bit47 */
			{33628,39,0}, /* core3 pc_iss bit48 */
			{33627,39,0}, /* core3 pc_iss bit49 */
			{33626,39,0}, /* core3 pc_iss bit50 */
			{33625,39,0}, /* core3 pc_iss bit51 */
			{33624,39,0}, /* core3 pc_iss bit52 */
			{33622,39,0}, /* core3 pc_iss bit53 */
			{33623,39,0}, /* core3 pc_iss bit54 */
			{33634,39,0}, /* core3 pc_iss bit55 */
			{33633,39,0}, /* core3 pc_iss bit56 */
			{33632,39,0}, /* core3 pc_iss bit57 */
			{33608,39,0}, /* core3 pc_iss bit58 */
			{33607,39,0}, /* core3 pc_iss bit59 */
			{33638,39,0}, /* core3 pc_iss bit60 */
			{33637,39,0}, /* core3 pc_iss bit61 */
			{33636,39,0}, /* core3 pc_iss bit62 */
			{33635,39,0}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{30897,40,0}, /* core3 full_pc_wr bit0 */
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
			{30971,40,0}, /* core3 full_pc_ex1 bit0 */
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
			{30942,40,0}, /* core3 full_pc_ex2 bit0 */
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
			{16598,40,0}, /* core3 return_Stack_pointer bit0 */
			{16597,40,0}, /* core3 return_Stack_pointer bit1 */
			{13720,40,0}, /* core3 return_Stack_pointer bit2 */
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
			{23469,40,0}, /* core3 return_Stack0 bit0 */
			{23468,40,0}, /* core3 return_Stack0 bit1 */
			{23467,40,0}, /* core3 return_Stack0 bit2 */
			{23449,40,0}, /* core3 return_Stack0 bit3 */
			{23448,40,0}, /* core3 return_Stack0 bit4 */
			{23447,40,0}, /* core3 return_Stack0 bit5 */
			{23446,40,0}, /* core3 return_Stack0 bit6 */
			{23365,40,0}, /* core3 return_Stack0 bit7 */
			{23364,40,0}, /* core3 return_Stack0 bit8 */
			{23363,40,0}, /* core3 return_Stack0 bit9 */
			{23466,40,0}, /* core3 return_Stack0 bit10 */
			{23417,40,0}, /* core3 return_Stack0 bit11 */
			{23416,40,0}, /* core3 return_Stack0 bit12 */
			{23415,40,0}, /* core3 return_Stack0 bit13 */
			{23414,40,0}, /* core3 return_Stack0 bit14 */
			{23369,40,0}, /* core3 return_Stack0 bit15 */
			{23368,40,0}, /* core3 return_Stack0 bit16 */
			{23367,40,0}, /* core3 return_Stack0 bit17 */
			{23366,40,0}, /* core3 return_Stack0 bit18 */
			{23421,40,0}, /* core3 return_Stack0 bit19 */
			{23420,40,0}, /* core3 return_Stack0 bit20 */
			{23419,40,0}, /* core3 return_Stack0 bit21 */
			{23418,40,0}, /* core3 return_Stack0 bit22 */
			{23465,40,1}, /* core3 return_Stack0 bit23 */
			{23464,40,1}, /* core3 return_Stack0 bit24 */
			{23463,40,1}, /* core3 return_Stack0 bit25 */
			{23462,40,1}, /* core3 return_Stack0 bit26 */
			{23385,40,1}, /* core3 return_Stack0 bit27 */
			{23384,40,1}, /* core3 return_Stack0 bit28 */
			{23383,40,1}, /* core3 return_Stack0 bit29 */
			{23382,40,1}, /* core3 return_Stack0 bit30 */
			{13706,40,0}, /* core3 return_Stack0 bit31 */
			{23381,40,0}, /* core3 return_Stack0 bit32 */
			{23380,40,0}, /* core3 return_Stack0 bit33 */
			{23379,40,0}, /* core3 return_Stack0 bit34 */
			{23378,40,0}, /* core3 return_Stack0 bit35 */
			{23413,40,1}, /* core3 return_Stack0 bit36 */
			{23412,40,1}, /* core3 return_Stack0 bit37 */
			{23411,40,1}, /* core3 return_Stack0 bit38 */
			{23410,40,1}, /* core3 return_Stack0 bit39 */
			{23405,40,0}, /* core3 return_Stack0 bit40 */
			{23404,40,0}, /* core3 return_Stack0 bit41 */
			{23403,40,0}, /* core3 return_Stack0 bit42 */
			{23402,40,0}, /* core3 return_Stack0 bit43 */
			{23409,40,1}, /* core3 return_Stack0 bit44 */
			{23408,40,1}, /* core3 return_Stack0 bit45 */
			{23407,40,1}, /* core3 return_Stack0 bit46 */
			{23406,40,1}, /* core3 return_Stack0 bit47 */
			{13707,40,0}, /* core3 return_Stack0 bit48 */
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
			{23461,40,0}, /* core3 return_Stack1 bit0 */
			{23460,40,0}, /* core3 return_Stack1 bit1 */
			{23459,40,0}, /* core3 return_Stack1 bit2 */
			{23445,40,0}, /* core3 return_Stack1 bit3 */
			{23444,40,0}, /* core3 return_Stack1 bit4 */
			{23443,40,0}, /* core3 return_Stack1 bit5 */
			{23442,40,0}, /* core3 return_Stack1 bit6 */
			{23441,40,0}, /* core3 return_Stack1 bit7 */
			{23440,40,0}, /* core3 return_Stack1 bit8 */
			{23439,40,0}, /* core3 return_Stack1 bit9 */
			{23458,40,0}, /* core3 return_Stack1 bit10 */
			{23425,40,0}, /* core3 return_Stack1 bit11 */
			{23424,40,0}, /* core3 return_Stack1 bit12 */
			{23423,40,0}, /* core3 return_Stack1 bit13 */
			{23422,40,0}, /* core3 return_Stack1 bit14 */
			{23373,40,0}, /* core3 return_Stack1 bit15 */
			{23372,40,0}, /* core3 return_Stack1 bit16 */
			{23371,40,0}, /* core3 return_Stack1 bit17 */
			{23370,40,0}, /* core3 return_Stack1 bit18 */
			{23429,40,0}, /* core3 return_Stack1 bit19 */
			{23428,40,0}, /* core3 return_Stack1 bit20 */
			{23427,40,0}, /* core3 return_Stack1 bit21 */
			{23426,40,0}, /* core3 return_Stack1 bit22 */
			{23393,40,1}, /* core3 return_Stack1 bit23 */
			{23392,40,1}, /* core3 return_Stack1 bit24 */
			{23391,40,1}, /* core3 return_Stack1 bit25 */
			{23390,40,1}, /* core3 return_Stack1 bit26 */
			{23389,40,1}, /* core3 return_Stack1 bit27 */
			{23388,40,1}, /* core3 return_Stack1 bit28 */
			{23387,40,1}, /* core3 return_Stack1 bit29 */
			{23386,40,1}, /* core3 return_Stack1 bit30 */
			{13711,40,0}, /* core3 return_Stack1 bit31 */
			{23377,40,0}, /* core3 return_Stack1 bit32 */
			{23376,40,0}, /* core3 return_Stack1 bit33 */
			{23375,40,0}, /* core3 return_Stack1 bit34 */
			{23374,40,0}, /* core3 return_Stack1 bit35 */
			{23453,40,1}, /* core3 return_Stack1 bit36 */
			{23452,40,1}, /* core3 return_Stack1 bit37 */
			{23451,40,1}, /* core3 return_Stack1 bit38 */
			{23450,40,1}, /* core3 return_Stack1 bit39 */
			{23401,40,0}, /* core3 return_Stack1 bit40 */
			{23400,40,0}, /* core3 return_Stack1 bit41 */
			{23399,40,0}, /* core3 return_Stack1 bit42 */
			{23398,40,0}, /* core3 return_Stack1 bit43 */
			{23457,40,1}, /* core3 return_Stack1 bit44 */
			{23456,40,1}, /* core3 return_Stack1 bit45 */
			{23455,40,1}, /* core3 return_Stack1 bit46 */
			{23454,40,1}, /* core3 return_Stack1 bit47 */
			{13705,40,0}, /* core3 return_Stack1 bit48 */
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
			{23397,40,0}, /* core3 return_Stack2 bit0 */
			{23396,40,0}, /* core3 return_Stack2 bit1 */
			{23395,40,0}, /* core3 return_Stack2 bit2 */
			{23437,40,0}, /* core3 return_Stack2 bit3 */
			{23436,40,0}, /* core3 return_Stack2 bit4 */
			{23435,40,0}, /* core3 return_Stack2 bit5 */
			{23434,40,0}, /* core3 return_Stack2 bit6 */
			{23361,40,0}, /* core3 return_Stack2 bit7 */
			{23360,40,0}, /* core3 return_Stack2 bit8 */
			{23359,40,0}, /* core3 return_Stack2 bit9 */
			{23394,40,0}, /* core3 return_Stack2 bit10 */
			{23433,40,0}, /* core3 return_Stack2 bit11 */
			{23432,40,0}, /* core3 return_Stack2 bit12 */
			{23431,40,0}, /* core3 return_Stack2 bit13 */
			{23430,40,0}, /* core3 return_Stack2 bit14 */
			{23357,40,1}, /* core3 return_Stack2 bit15 */
			{23356,40,1}, /* core3 return_Stack2 bit16 */
			{23355,40,1}, /* core3 return_Stack2 bit17 */
			{23354,40,1}, /* core3 return_Stack2 bit18 */
			{23216,40,0}, /* core3 return_Stack2 bit19 */
			{23215,40,0}, /* core3 return_Stack2 bit20 */
			{23214,40,0}, /* core3 return_Stack2 bit21 */
			{23213,40,0}, /* core3 return_Stack2 bit22 */
			{23312,40,1}, /* core3 return_Stack2 bit23 */
			{23311,40,1}, /* core3 return_Stack2 bit24 */
			{23310,40,1}, /* core3 return_Stack2 bit25 */
			{23309,40,1}, /* core3 return_Stack2 bit26 */
			{23128,40,1}, /* core3 return_Stack2 bit27 */
			{23127,40,1}, /* core3 return_Stack2 bit28 */
			{23126,40,1}, /* core3 return_Stack2 bit29 */
			{23125,40,1}, /* core3 return_Stack2 bit30 */
			{13712,40,0}, /* core3 return_Stack2 bit31 */
			{23152,40,1}, /* core3 return_Stack2 bit32 */
			{23151,40,1}, /* core3 return_Stack2 bit33 */
			{23150,40,1}, /* core3 return_Stack2 bit34 */
			{23149,40,1}, /* core3 return_Stack2 bit35 */
			{23244,40,1}, /* core3 return_Stack2 bit36 */
			{23243,40,1}, /* core3 return_Stack2 bit37 */
			{23242,40,1}, /* core3 return_Stack2 bit38 */
			{23241,40,1}, /* core3 return_Stack2 bit39 */
			{23308,40,1}, /* core3 return_Stack2 bit40 */
			{23307,40,1}, /* core3 return_Stack2 bit41 */
			{23306,40,1}, /* core3 return_Stack2 bit42 */
			{23305,40,1}, /* core3 return_Stack2 bit43 */
			{23256,40,1}, /* core3 return_Stack2 bit44 */
			{23255,40,1}, /* core3 return_Stack2 bit45 */
			{23254,40,1}, /* core3 return_Stack2 bit46 */
			{23253,40,1}, /* core3 return_Stack2 bit47 */
			{13713,40,0}, /* core3 return_Stack2 bit48 */
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
			{23332,40,0}, /* core3 return_Stack3 bit0 */
			{23331,40,0}, /* core3 return_Stack3 bit1 */
			{23330,40,0}, /* core3 return_Stack3 bit2 */
			{23204,40,0}, /* core3 return_Stack3 bit3 */
			{23203,40,0}, /* core3 return_Stack3 bit4 */
			{23202,40,0}, /* core3 return_Stack3 bit5 */
			{23201,40,0}, /* core3 return_Stack3 bit6 */
			{23168,40,0}, /* core3 return_Stack3 bit7 */
			{23167,40,0}, /* core3 return_Stack3 bit8 */
			{23166,40,0}, /* core3 return_Stack3 bit9 */
			{23329,40,0}, /* core3 return_Stack3 bit10 */
			{23228,40,0}, /* core3 return_Stack3 bit11 */
			{23227,40,0}, /* core3 return_Stack3 bit12 */
			{23226,40,0}, /* core3 return_Stack3 bit13 */
			{23225,40,0}, /* core3 return_Stack3 bit14 */
			{23160,40,1}, /* core3 return_Stack3 bit15 */
			{23159,40,1}, /* core3 return_Stack3 bit16 */
			{23158,40,1}, /* core3 return_Stack3 bit17 */
			{23157,40,1}, /* core3 return_Stack3 bit18 */
			{23224,40,0}, /* core3 return_Stack3 bit19 */
			{23223,40,0}, /* core3 return_Stack3 bit20 */
			{23222,40,0}, /* core3 return_Stack3 bit21 */
			{23221,40,0}, /* core3 return_Stack3 bit22 */
			{23340,40,1}, /* core3 return_Stack3 bit23 */
			{23339,40,1}, /* core3 return_Stack3 bit24 */
			{23338,40,1}, /* core3 return_Stack3 bit25 */
			{23337,40,1}, /* core3 return_Stack3 bit26 */
			{23124,40,1}, /* core3 return_Stack3 bit27 */
			{23123,40,1}, /* core3 return_Stack3 bit28 */
			{23122,40,1}, /* core3 return_Stack3 bit29 */
			{23121,40,1}, /* core3 return_Stack3 bit30 */
			{13714,40,0}, /* core3 return_Stack3 bit31 */
			{23148,40,1}, /* core3 return_Stack3 bit32 */
			{23147,40,1}, /* core3 return_Stack3 bit33 */
			{23146,40,1}, /* core3 return_Stack3 bit34 */
			{23145,40,1}, /* core3 return_Stack3 bit35 */
			{23272,40,1}, /* core3 return_Stack3 bit36 */
			{23271,40,1}, /* core3 return_Stack3 bit37 */
			{23270,40,1}, /* core3 return_Stack3 bit38 */
			{23269,40,1}, /* core3 return_Stack3 bit39 */
			{23320,40,1}, /* core3 return_Stack3 bit40 */
			{23319,40,1}, /* core3 return_Stack3 bit41 */
			{23318,40,1}, /* core3 return_Stack3 bit42 */
			{23317,40,1}, /* core3 return_Stack3 bit43 */
			{23264,40,1}, /* core3 return_Stack3 bit44 */
			{23263,40,1}, /* core3 return_Stack3 bit45 */
			{23262,40,1}, /* core3 return_Stack3 bit46 */
			{23261,40,1}, /* core3 return_Stack3 bit47 */
			{13717,40,0}, /* core3 return_Stack3 bit48 */
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
			{23352,40,0}, /* core3 return_Stack4 bit0 */
			{23351,40,0}, /* core3 return_Stack4 bit1 */
			{23350,40,0}, /* core3 return_Stack4 bit2 */
			{23268,40,0}, /* core3 return_Stack4 bit3 */
			{23267,40,0}, /* core3 return_Stack4 bit4 */
			{23266,40,0}, /* core3 return_Stack4 bit5 */
			{23265,40,0}, /* core3 return_Stack4 bit6 */
			{23180,40,0}, /* core3 return_Stack4 bit7 */
			{23179,40,0}, /* core3 return_Stack4 bit8 */
			{23178,40,0}, /* core3 return_Stack4 bit9 */
			{23349,40,0}, /* core3 return_Stack4 bit10 */
			{23288,40,0}, /* core3 return_Stack4 bit11 */
			{23287,40,0}, /* core3 return_Stack4 bit12 */
			{23286,40,0}, /* core3 return_Stack4 bit13 */
			{23285,40,0}, /* core3 return_Stack4 bit14 */
			{23184,40,0}, /* core3 return_Stack4 bit15 */
			{23183,40,0}, /* core3 return_Stack4 bit16 */
			{23182,40,0}, /* core3 return_Stack4 bit17 */
			{23181,40,0}, /* core3 return_Stack4 bit18 */
			{23284,40,0}, /* core3 return_Stack4 bit19 */
			{23283,40,0}, /* core3 return_Stack4 bit20 */
			{23282,40,0}, /* core3 return_Stack4 bit21 */
			{23281,40,0}, /* core3 return_Stack4 bit22 */
			{23344,40,1}, /* core3 return_Stack4 bit23 */
			{23343,40,1}, /* core3 return_Stack4 bit24 */
			{23342,40,1}, /* core3 return_Stack4 bit25 */
			{23341,40,1}, /* core3 return_Stack4 bit26 */
			{23116,40,1}, /* core3 return_Stack4 bit27 */
			{23115,40,1}, /* core3 return_Stack4 bit28 */
			{23114,40,1}, /* core3 return_Stack4 bit29 */
			{23113,40,1}, /* core3 return_Stack4 bit30 */
			{13708,40,0}, /* core3 return_Stack4 bit31 */
			{23140,40,0}, /* core3 return_Stack4 bit32 */
			{23139,40,0}, /* core3 return_Stack4 bit33 */
			{23138,40,0}, /* core3 return_Stack4 bit34 */
			{23137,40,0}, /* core3 return_Stack4 bit35 */
			{23292,40,1}, /* core3 return_Stack4 bit36 */
			{23291,40,1}, /* core3 return_Stack4 bit37 */
			{23290,40,1}, /* core3 return_Stack4 bit38 */
			{23289,40,1}, /* core3 return_Stack4 bit39 */
			{23300,40,0}, /* core3 return_Stack4 bit40 */
			{23299,40,0}, /* core3 return_Stack4 bit41 */
			{23298,40,0}, /* core3 return_Stack4 bit42 */
			{23297,40,0}, /* core3 return_Stack4 bit43 */
			{23296,40,1}, /* core3 return_Stack4 bit44 */
			{23295,40,1}, /* core3 return_Stack4 bit45 */
			{23294,40,1}, /* core3 return_Stack4 bit46 */
			{23293,40,1}, /* core3 return_Stack4 bit47 */
			{13709,40,0}, /* core3 return_Stack4 bit48 */
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
			{23348,40,0}, /* core3 return_Stack5 bit0 */
			{23347,40,0}, /* core3 return_Stack5 bit1 */
			{23346,40,0}, /* core3 return_Stack5 bit2 */
			{23196,40,0}, /* core3 return_Stack5 bit3 */
			{23195,40,0}, /* core3 return_Stack5 bit4 */
			{23194,40,0}, /* core3 return_Stack5 bit5 */
			{23193,40,0}, /* core3 return_Stack5 bit6 */
			{23192,40,0}, /* core3 return_Stack5 bit7 */
			{23191,40,0}, /* core3 return_Stack5 bit8 */
			{23190,40,0}, /* core3 return_Stack5 bit9 */
			{23345,40,0}, /* core3 return_Stack5 bit10 */
			{23240,40,0}, /* core3 return_Stack5 bit11 */
			{23239,40,0}, /* core3 return_Stack5 bit12 */
			{23238,40,0}, /* core3 return_Stack5 bit13 */
			{23237,40,0}, /* core3 return_Stack5 bit14 */
			{23188,40,0}, /* core3 return_Stack5 bit15 */
			{23187,40,0}, /* core3 return_Stack5 bit16 */
			{23186,40,0}, /* core3 return_Stack5 bit17 */
			{23185,40,0}, /* core3 return_Stack5 bit18 */
			{23280,40,0}, /* core3 return_Stack5 bit19 */
			{23279,40,0}, /* core3 return_Stack5 bit20 */
			{23278,40,0}, /* core3 return_Stack5 bit21 */
			{23277,40,0}, /* core3 return_Stack5 bit22 */
			{23112,40,1}, /* core3 return_Stack5 bit23 */
			{23111,40,1}, /* core3 return_Stack5 bit24 */
			{23110,40,1}, /* core3 return_Stack5 bit25 */
			{23109,40,1}, /* core3 return_Stack5 bit26 */
			{23120,40,1}, /* core3 return_Stack5 bit27 */
			{23119,40,1}, /* core3 return_Stack5 bit28 */
			{23118,40,1}, /* core3 return_Stack5 bit29 */
			{23117,40,1}, /* core3 return_Stack5 bit30 */
			{13710,40,0}, /* core3 return_Stack5 bit31 */
			{23136,40,0}, /* core3 return_Stack5 bit32 */
			{23135,40,0}, /* core3 return_Stack5 bit33 */
			{23134,40,0}, /* core3 return_Stack5 bit34 */
			{23133,40,0}, /* core3 return_Stack5 bit35 */
			{23248,40,1}, /* core3 return_Stack5 bit36 */
			{23247,40,1}, /* core3 return_Stack5 bit37 */
			{23246,40,1}, /* core3 return_Stack5 bit38 */
			{23245,40,1}, /* core3 return_Stack5 bit39 */
			{23304,40,0}, /* core3 return_Stack5 bit40 */
			{23303,40,0}, /* core3 return_Stack5 bit41 */
			{23302,40,0}, /* core3 return_Stack5 bit42 */
			{23301,40,0}, /* core3 return_Stack5 bit43 */
			{23252,40,1}, /* core3 return_Stack5 bit44 */
			{23251,40,1}, /* core3 return_Stack5 bit45 */
			{23250,40,1}, /* core3 return_Stack5 bit46 */
			{23249,40,1}, /* core3 return_Stack5 bit47 */
			{13704,40,0}, /* core3 return_Stack5 bit48 */
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
			{23324,40,0}, /* core3 return_Stack6 bit0 */
			{23323,40,0}, /* core3 return_Stack6 bit1 */
			{23322,40,0}, /* core3 return_Stack6 bit2 */
			{23208,40,0}, /* core3 return_Stack6 bit3 */
			{23207,40,0}, /* core3 return_Stack6 bit4 */
			{23206,40,0}, /* core3 return_Stack6 bit5 */
			{23205,40,0}, /* core3 return_Stack6 bit6 */
			{23176,40,0}, /* core3 return_Stack6 bit7 */
			{23175,40,0}, /* core3 return_Stack6 bit8 */
			{23174,40,0}, /* core3 return_Stack6 bit9 */
			{23321,40,0}, /* core3 return_Stack6 bit10 */
			{23212,40,0}, /* core3 return_Stack6 bit11 */
			{23211,40,0}, /* core3 return_Stack6 bit12 */
			{23210,40,0}, /* core3 return_Stack6 bit13 */
			{23209,40,0}, /* core3 return_Stack6 bit14 */
			{23164,40,1}, /* core3 return_Stack6 bit15 */
			{23163,40,1}, /* core3 return_Stack6 bit16 */
			{23162,40,1}, /* core3 return_Stack6 bit17 */
			{23161,40,1}, /* core3 return_Stack6 bit18 */
			{23220,40,0}, /* core3 return_Stack6 bit19 */
			{23219,40,0}, /* core3 return_Stack6 bit20 */
			{23218,40,0}, /* core3 return_Stack6 bit21 */
			{23217,40,0}, /* core3 return_Stack6 bit22 */
			{23316,40,1}, /* core3 return_Stack6 bit23 */
			{23315,40,1}, /* core3 return_Stack6 bit24 */
			{23314,40,1}, /* core3 return_Stack6 bit25 */
			{23313,40,1}, /* core3 return_Stack6 bit26 */
			{23132,40,1}, /* core3 return_Stack6 bit27 */
			{23131,40,1}, /* core3 return_Stack6 bit28 */
			{23130,40,1}, /* core3 return_Stack6 bit29 */
			{23129,40,1}, /* core3 return_Stack6 bit30 */
			{13718,40,0}, /* core3 return_Stack6 bit31 */
			{23144,40,0}, /* core3 return_Stack6 bit32 */
			{23143,40,0}, /* core3 return_Stack6 bit33 */
			{23142,40,0}, /* core3 return_Stack6 bit34 */
			{23141,40,0}, /* core3 return_Stack6 bit35 */
			{23276,40,1}, /* core3 return_Stack6 bit36 */
			{23275,40,1}, /* core3 return_Stack6 bit37 */
			{23274,40,1}, /* core3 return_Stack6 bit38 */
			{23273,40,1}, /* core3 return_Stack6 bit39 */
			{23328,40,1}, /* core3 return_Stack6 bit40 */
			{23327,40,1}, /* core3 return_Stack6 bit41 */
			{23326,40,1}, /* core3 return_Stack6 bit42 */
			{23325,40,1}, /* core3 return_Stack6 bit43 */
			{23260,40,1}, /* core3 return_Stack6 bit44 */
			{23259,40,1}, /* core3 return_Stack6 bit45 */
			{23258,40,1}, /* core3 return_Stack6 bit46 */
			{23257,40,1}, /* core3 return_Stack6 bit47 */
			{13719,40,0}, /* core3 return_Stack6 bit48 */
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
			{23336,40,0}, /* core3 return_Stack7 bit0 */
			{23335,40,0}, /* core3 return_Stack7 bit1 */
			{23334,40,0}, /* core3 return_Stack7 bit2 */
			{23200,40,0}, /* core3 return_Stack7 bit3 */
			{23199,40,0}, /* core3 return_Stack7 bit4 */
			{23198,40,0}, /* core3 return_Stack7 bit5 */
			{23197,40,0}, /* core3 return_Stack7 bit6 */
			{23172,40,0}, /* core3 return_Stack7 bit7 */
			{23171,40,0}, /* core3 return_Stack7 bit8 */
			{23170,40,0}, /* core3 return_Stack7 bit9 */
			{23333,40,0}, /* core3 return_Stack7 bit10 */
			{23236,40,0}, /* core3 return_Stack7 bit11 */
			{23235,40,0}, /* core3 return_Stack7 bit12 */
			{23234,40,0}, /* core3 return_Stack7 bit13 */
			{23233,40,0}, /* core3 return_Stack7 bit14 */
			{23156,40,1}, /* core3 return_Stack7 bit15 */
			{23155,40,1}, /* core3 return_Stack7 bit16 */
			{23154,40,1}, /* core3 return_Stack7 bit17 */
			{23153,40,1}, /* core3 return_Stack7 bit18 */
			{23232,40,0}, /* core3 return_Stack7 bit19 */
			{23231,40,0}, /* core3 return_Stack7 bit20 */
			{23230,40,0}, /* core3 return_Stack7 bit21 */
			{23229,40,0}, /* core3 return_Stack7 bit22 */
			{23108,40,1}, /* core3 return_Stack7 bit23 */
			{23107,40,1}, /* core3 return_Stack7 bit24 */
			{23106,40,1}, /* core3 return_Stack7 bit25 */
			{23105,40,1}, /* core3 return_Stack7 bit26 */
			{23035,40,1}, /* core3 return_Stack7 bit27 */
			{23034,40,1}, /* core3 return_Stack7 bit28 */
			{23033,40,1}, /* core3 return_Stack7 bit29 */
			{23032,40,1}, /* core3 return_Stack7 bit30 */
			{13715,40,0}, /* core3 return_Stack7 bit31 */
			{23031,40,1}, /* core3 return_Stack7 bit32 */
			{23030,40,1}, /* core3 return_Stack7 bit33 */
			{23029,40,1}, /* core3 return_Stack7 bit34 */
			{23028,40,1}, /* core3 return_Stack7 bit35 */
			{23023,40,1}, /* core3 return_Stack7 bit36 */
			{23022,40,1}, /* core3 return_Stack7 bit37 */
			{23021,40,1}, /* core3 return_Stack7 bit38 */
			{23020,40,1}, /* core3 return_Stack7 bit39 */
			{23039,40,1}, /* core3 return_Stack7 bit40 */
			{23038,40,1}, /* core3 return_Stack7 bit41 */
			{23037,40,1}, /* core3 return_Stack7 bit42 */
			{23036,40,1}, /* core3 return_Stack7 bit43 */
			{23027,40,1}, /* core3 return_Stack7 bit44 */
			{23026,40,1}, /* core3 return_Stack7 bit45 */
			{23025,40,1}, /* core3 return_Stack7 bit46 */
			{23024,40,1}, /* core3 return_Stack7 bit47 */
			{13716,40,0}, /* core3 return_Stack7 bit48 */
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
			.L2_parity_err = {{
			{ 7910,39,0}, /* core3 L2_parity_err bit0 */
			{    0, 0,2}, /* core3 L2_parity_err bit1 */
			{    0, 0,2}, /* core3 L2_parity_err bit2 */
			{    0, 0,2}, /* core3 L2_parity_err bit3 */
			{    0, 0,2}, /* core3 L2_parity_err bit4 */
			{    0, 0,2}, /* core3 L2_parity_err bit5 */
			{    0, 0,2}, /* core3 L2_parity_err bit6 */
			{    0, 0,2}, /* core3 L2_parity_err bit7 */
			{    0, 0,2}, /* core3 L2_parity_err bit8 */
			{    0, 0,2}, /* core3 L2_parity_err bit9 */
			{    0, 0,2}, /* core3 L2_parity_err bit10 */
			{    0, 0,2}, /* core3 L2_parity_err bit11 */
			{    0, 0,2}, /* core3 L2_parity_err bit12 */
			{    0, 0,2}, /* core3 L2_parity_err bit13 */
			{    0, 0,2}, /* core3 L2_parity_err bit14 */
			{    0, 0,2}, /* core3 L2_parity_err bit15 */
			{    0, 0,2}, /* core3 L2_parity_err bit16 */
			{    0, 0,2}, /* core3 L2_parity_err bit17 */
			{    0, 0,2}, /* core3 L2_parity_err bit18 */
			{    0, 0,2}, /* core3 L2_parity_err bit19 */
			{    0, 0,2}, /* core3 L2_parity_err bit20 */
			{    0, 0,2}, /* core3 L2_parity_err bit21 */
			{    0, 0,2}, /* core3 L2_parity_err bit22 */
			{    0, 0,2}, /* core3 L2_parity_err bit23 */
			{    0, 0,2}, /* core3 L2_parity_err bit24 */
			{    0, 0,2}, /* core3 L2_parity_err bit25 */
			{    0, 0,2}, /* core3 L2_parity_err bit26 */
			{    0, 0,2}, /* core3 L2_parity_err bit27 */
			{    0, 0,2}, /* core3 L2_parity_err bit28 */
			{    0, 0,2}, /* core3 L2_parity_err bit29 */
			{    0, 0,2}, /* core3 L2_parity_err bit30 */
			{    0, 0,2}, /* core3 L2_parity_err bit31 */
			{    0, 0,2}, /* core3 L2_parity_err bit32 */
			{    0, 0,2}, /* core3 L2_parity_err bit33 */
			{    0, 0,2}, /* core3 L2_parity_err bit34 */
			{    0, 0,2}, /* core3 L2_parity_err bit35 */
			{    0, 0,2}, /* core3 L2_parity_err bit36 */
			{    0, 0,2}, /* core3 L2_parity_err bit37 */
			{    0, 0,2}, /* core3 L2_parity_err bit38 */
			{    0, 0,2}, /* core3 L2_parity_err bit39 */
			{    0, 0,2}, /* core3 L2_parity_err bit40 */
			{    0, 0,2}, /* core3 L2_parity_err bit41 */
			{    0, 0,2}, /* core3 L2_parity_err bit42 */
			{    0, 0,2}, /* core3 L2_parity_err bit43 */
			{    0, 0,2}, /* core3 L2_parity_err bit44 */
			{    0, 0,2}, /* core3 L2_parity_err bit45 */
			{    0, 0,2}, /* core3 L2_parity_err bit46 */
			{    0, 0,2}, /* core3 L2_parity_err bit47 */
			{    0, 0,2}, /* core3 L2_parity_err bit48 */
			{    0, 0,2}, /* core3 L2_parity_err bit49 */
			{    0, 0,2}, /* core3 L2_parity_err bit50 */
			{    0, 0,2}, /* core3 L2_parity_err bit51 */
			{    0, 0,2}, /* core3 L2_parity_err bit52 */
			{    0, 0,2}, /* core3 L2_parity_err bit53 */
			{    0, 0,2}, /* core3 L2_parity_err bit54 */
			{    0, 0,2}, /* core3 L2_parity_err bit55 */
			{    0, 0,2}, /* core3 L2_parity_err bit56 */
			{    0, 0,2}, /* core3 L2_parity_err bit57 */
			{    0, 0,2}, /* core3 L2_parity_err bit58 */
			{    0, 0,2}, /* core3 L2_parity_err bit59 */
			{    0, 0,2}, /* core3 L2_parity_err bit60 */
			{    0, 0,2}, /* core3 L2_parity_err bit61 */
			{    0, 0,2}, /* core3 L2_parity_err bit62 */
			{    0, 0,2}, /* core3 L2_parity_err bit63 */
			}},
			.L2_parity_err_count = {{
			{13805,39,1}, /* core3 L2_parity_err_count bit0 */
			{13804,39,1}, /* core3 L2_parity_err_count bit1 */
			{13803,39,1}, /* core3 L2_parity_err_count bit2 */
			{13810,39,0}, /* core3 L2_parity_err_count bit3 */
			{13809,39,0}, /* core3 L2_parity_err_count bit4 */
			{13808,39,0}, /* core3 L2_parity_err_count bit5 */
			{13807,39,0}, /* core3 L2_parity_err_count bit6 */
			{ 7911,39,0}, /* core3 L2_parity_err_count bit7 */
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
			{14288,39,0}, /* core3 L2_parity_index bit0 */
			{14287,39,0}, /* core3 L2_parity_index bit1 */
			{14286,39,0}, /* core3 L2_parity_index bit2 */
			{14285,39,0}, /* core3 L2_parity_index bit3 */
			{14284,39,0}, /* core3 L2_parity_index bit4 */
			{14283,39,0}, /* core3 L2_parity_index bit5 */
			{14282,39,0}, /* core3 L2_parity_index bit6 */
			{14281,39,0}, /* core3 L2_parity_index bit7 */
			{ 7821,39,0}, /* core3 L2_parity_index bit8 */
			{    0, 0,2}, /* core3 L2_parity_index bit9 */
			{    0, 0,2}, /* core3 L2_parity_index bit10 */
			{    0, 0,2}, /* core3 L2_parity_index bit11 */
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
			{10378,39,0}, /* core3 L2_parity_way bit0 */
			{10377,39,0}, /* core3 L2_parity_way bit1 */
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
			{14280,39,0}, /* core3 L2_parity_banks bit0 */
			{14279,39,0}, /* core3 L2_parity_banks bit1 */
			{14278,39,0}, /* core3 L2_parity_banks bit2 */
			{14277,39,0}, /* core3 L2_parity_banks bit3 */
			{14272,39,0}, /* core3 L2_parity_banks bit4 */
			{14271,39,0}, /* core3 L2_parity_banks bit5 */
			{14270,39,0}, /* core3 L2_parity_banks bit6 */
			{14269,39,0}, /* core3 L2_parity_banks bit7 */
			{14292,39,0}, /* core3 L2_parity_banks bit8 */
			{14291,39,0}, /* core3 L2_parity_banks bit9 */
			{14290,39,0}, /* core3 L2_parity_banks bit10 */
			{14289,39,0}, /* core3 L2_parity_banks bit11 */
			{14276,39,0}, /* core3 L2_parity_banks bit12 */
			{14275,39,0}, /* core3 L2_parity_banks bit13 */
			{14274,39,0}, /* core3 L2_parity_banks bit14 */
			{14273,39,0}, /* core3 L2_parity_banks bit15 */
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
			{  192,41,0}, /* core4 pc bit0 */
			{  191,41,0}, /* core4 pc bit1 */
			{  190,41,0}, /* core4 pc bit2 */
			{  189,41,0}, /* core4 pc bit3 */
			{  142,41,0}, /* core4 pc bit4 */
			{  141,41,0}, /* core4 pc bit5 */
			{  140,41,0}, /* core4 pc bit6 */
			{  139,41,0}, /* core4 pc bit7 */
			{  146,41,0}, /* core4 pc bit8 */
			{  145,41,0}, /* core4 pc bit9 */
			{  144,41,0}, /* core4 pc bit10 */
			{  143,41,0}, /* core4 pc bit11 */
			{  150,41,0}, /* core4 pc bit12 */
			{  149,41,0}, /* core4 pc bit13 */
			{  148,41,0}, /* core4 pc bit14 */
			{  147,41,0}, /* core4 pc bit15 */
			{  126,41,0}, /* core4 pc bit16 */
			{  125,41,0}, /* core4 pc bit17 */
			{  124,41,0}, /* core4 pc bit18 */
			{  123,41,0}, /* core4 pc bit19 */
			{  134,41,0}, /* core4 pc bit20 */
			{  133,41,0}, /* core4 pc bit21 */
			{  132,41,0}, /* core4 pc bit22 */
			{  131,41,0}, /* core4 pc bit23 */
			{  138,41,0}, /* core4 pc bit24 */
			{  137,41,0}, /* core4 pc bit25 */
			{  136,41,0}, /* core4 pc bit26 */
			{  135,41,0}, /* core4 pc bit27 */
			{  130,41,0}, /* core4 pc bit28 */
			{  129,41,0}, /* core4 pc bit29 */
			{  128,41,0}, /* core4 pc bit30 */
			{  127,41,0}, /* core4 pc bit31 */
			{  240,41,0}, /* core4 pc bit32 */
			{  239,41,0}, /* core4 pc bit33 */
			{  238,41,0}, /* core4 pc bit34 */
			{  237,41,0}, /* core4 pc bit35 */
			{  248,41,0}, /* core4 pc bit36 */
			{  247,41,0}, /* core4 pc bit37 */
			{  246,41,0}, /* core4 pc bit38 */
			{  245,41,0}, /* core4 pc bit39 */
			{  244,41,0}, /* core4 pc bit40 */
			{  243,41,0}, /* core4 pc bit41 */
			{  242,41,0}, /* core4 pc bit42 */
			{  241,41,0}, /* core4 pc bit43 */
			{  216,41,0}, /* core4 pc bit44 */
			{  215,41,0}, /* core4 pc bit45 */
			{  214,41,0}, /* core4 pc bit46 */
			{  213,41,0}, /* core4 pc bit47 */
			{  180,41,0}, /* core4 pc bit48 */
			{  179,41,0}, /* core4 pc bit49 */
			{  178,41,0}, /* core4 pc bit50 */
			{  177,41,0}, /* core4 pc bit51 */
			{  184,41,0}, /* core4 pc bit52 */
			{  183,41,0}, /* core4 pc bit53 */
			{  182,41,0}, /* core4 pc bit54 */
			{  181,41,0}, /* core4 pc bit55 */
			{  236,41,0}, /* core4 pc bit56 */
			{  235,41,0}, /* core4 pc bit57 */
			{  234,41,0}, /* core4 pc bit58 */
			{  233,41,0}, /* core4 pc bit59 */
			{  188,41,0}, /* core4 pc bit60 */
			{  187,41,0}, /* core4 pc bit61 */
			{  186,41,0}, /* core4 pc bit62 */
			{  185,41,0}, /* core4 pc bit63 */
			}},
			.sp32 = {{
			{41807,42,0}, /* core4 sp32 bit0 */
			{41871,42,0}, /* core4 sp32 bit1 */
			{41806,42,0}, /* core4 sp32 bit2 */
			{41805,42,0}, /* core4 sp32 bit3 */
			{41804,42,0}, /* core4 sp32 bit4 */
			{41855,42,0}, /* core4 sp32 bit5 */
			{41854,42,0}, /* core4 sp32 bit6 */
			{41853,42,0}, /* core4 sp32 bit7 */
			{41852,42,0}, /* core4 sp32 bit8 */
			{41859,42,0}, /* core4 sp32 bit9 */
			{41858,42,0}, /* core4 sp32 bit10 */
			{41857,42,0}, /* core4 sp32 bit11 */
			{41856,42,0}, /* core4 sp32 bit12 */
			{41867,42,0}, /* core4 sp32 bit13 */
			{41866,42,0}, /* core4 sp32 bit14 */
			{41865,42,0}, /* core4 sp32 bit15 */
			{41864,42,0}, /* core4 sp32 bit16 */
			{41679,42,0}, /* core4 sp32 bit17 */
			{41678,42,0}, /* core4 sp32 bit18 */
			{41870,42,0}, /* core4 sp32 bit19 */
			{41677,42,0}, /* core4 sp32 bit20 */
			{41676,42,0}, /* core4 sp32 bit21 */
			{41671,42,0}, /* core4 sp32 bit22 */
			{41670,42,0}, /* core4 sp32 bit23 */
			{41669,42,0}, /* core4 sp32 bit24 */
			{41668,42,0}, /* core4 sp32 bit25 */
			{41869,42,0}, /* core4 sp32 bit26 */
			{41667,42,0}, /* core4 sp32 bit27 */
			{41666,42,0}, /* core4 sp32 bit28 */
			{41665,42,0}, /* core4 sp32 bit29 */
			{41664,42,0}, /* core4 sp32 bit30 */
			{41868,42,0}, /* core4 sp32 bit31 */
			{41483,42,0}, /* core4 sp32 bit32 */
			{41482,42,0}, /* core4 sp32 bit33 */
			{41481,42,0}, /* core4 sp32 bit34 */
			{41480,42,0}, /* core4 sp32 bit35 */
			{36299,42,0}, /* core4 sp32 bit36 */
			{28101,42,0}, /* core4 sp32 bit37 */
			{36298,42,0}, /* core4 sp32 bit38 */
			{41535,42,0}, /* core4 sp32 bit39 */
			{41534,42,0}, /* core4 sp32 bit40 */
			{41533,42,0}, /* core4 sp32 bit41 */
			{41532,42,0}, /* core4 sp32 bit42 */
			{41479,42,0}, /* core4 sp32 bit43 */
			{41478,42,0}, /* core4 sp32 bit44 */
			{41477,42,0}, /* core4 sp32 bit45 */
			{41476,42,0}, /* core4 sp32 bit46 */
			{36277,42,0}, /* core4 sp32 bit47 */
			{36276,42,0}, /* core4 sp32 bit48 */
			{41531,42,0}, /* core4 sp32 bit49 */
			{41530,42,0}, /* core4 sp32 bit50 */
			{41529,42,0}, /* core4 sp32 bit51 */
			{41528,42,0}, /* core4 sp32 bit52 */
			{41523,42,0}, /* core4 sp32 bit53 */
			{41522,42,0}, /* core4 sp32 bit54 */
			{41521,42,0}, /* core4 sp32 bit55 */
			{41520,42,0}, /* core4 sp32 bit56 */
			{41527,42,0}, /* core4 sp32 bit57 */
			{41526,42,0}, /* core4 sp32 bit58 */
			{41525,42,0}, /* core4 sp32 bit59 */
			{41524,42,0}, /* core4 sp32 bit60 */
			{41519,42,0}, /* core4 sp32 bit61 */
			{41518,42,0}, /* core4 sp32 bit62 */
			{41517,42,0}, /* core4 sp32 bit63 */
			}},
			.fp32 = {{
			{42038,42,0}, /* core4 fp32 bit0 */
			{42037,42,0}, /* core4 fp32 bit1 */
			{42021,42,0}, /* core4 fp32 bit2 */
			{42020,42,0}, /* core4 fp32 bit3 */
			{42036,42,0}, /* core4 fp32 bit4 */
			{42043,42,0}, /* core4 fp32 bit5 */
			{42042,42,0}, /* core4 fp32 bit6 */
			{42041,42,0}, /* core4 fp32 bit7 */
			{42040,42,0}, /* core4 fp32 bit8 */
			{42027,42,0}, /* core4 fp32 bit9 */
			{42031,42,0}, /* core4 fp32 bit10 */
			{42030,42,0}, /* core4 fp32 bit11 */
			{42029,42,0}, /* core4 fp32 bit12 */
			{42028,42,0}, /* core4 fp32 bit13 */
			{42015,42,0}, /* core4 fp32 bit14 */
			{42014,42,0}, /* core4 fp32 bit15 */
			{42026,42,0}, /* core4 fp32 bit16 */
			{42013,42,0}, /* core4 fp32 bit17 */
			{42035,42,0}, /* core4 fp32 bit18 */
			{42034,42,0}, /* core4 fp32 bit19 */
			{42033,42,0}, /* core4 fp32 bit20 */
			{42012,42,0}, /* core4 fp32 bit21 */
			{42019,42,0}, /* core4 fp32 bit22 */
			{42018,42,0}, /* core4 fp32 bit23 */
			{42017,42,0}, /* core4 fp32 bit24 */
			{42032,42,0}, /* core4 fp32 bit25 */
			{42016,42,0}, /* core4 fp32 bit26 */
			{42023,42,0}, /* core4 fp32 bit27 */
			{42025,42,0}, /* core4 fp32 bit28 */
			{42022,42,0}, /* core4 fp32 bit29 */
			{42024,42,0}, /* core4 fp32 bit30 */
			{42039,42,0}, /* core4 fp32 bit31 */
			{42143,42,0}, /* core4 fp32 bit32 */
			{42142,42,0}, /* core4 fp32 bit33 */
			{42141,42,0}, /* core4 fp32 bit34 */
			{42140,42,0}, /* core4 fp32 bit35 */
			{42135,42,0}, /* core4 fp32 bit36 */
			{42134,42,0}, /* core4 fp32 bit37 */
			{42133,42,0}, /* core4 fp32 bit38 */
			{42132,42,0}, /* core4 fp32 bit39 */
			{42131,42,0}, /* core4 fp32 bit40 */
			{42130,42,0}, /* core4 fp32 bit41 */
			{42129,42,0}, /* core4 fp32 bit42 */
			{42128,42,0}, /* core4 fp32 bit43 */
			{42139,42,0}, /* core4 fp32 bit44 */
			{42138,42,0}, /* core4 fp32 bit45 */
			{42137,42,0}, /* core4 fp32 bit46 */
			{42136,42,0}, /* core4 fp32 bit47 */
			{28149,42,0}, /* core4 fp32 bit48 */
			{42151,42,0}, /* core4 fp32 bit49 */
			{42150,42,0}, /* core4 fp32 bit50 */
			{42149,42,0}, /* core4 fp32 bit51 */
			{42148,42,0}, /* core4 fp32 bit52 */
			{42155,42,0}, /* core4 fp32 bit53 */
			{42154,42,0}, /* core4 fp32 bit54 */
			{42153,42,0}, /* core4 fp32 bit55 */
			{42152,42,0}, /* core4 fp32 bit56 */
			{42147,42,0}, /* core4 fp32 bit57 */
			{42146,42,0}, /* core4 fp32 bit58 */
			{42145,42,0}, /* core4 fp32 bit59 */
			{42144,42,0}, /* core4 fp32 bit60 */
			{42159,42,0}, /* core4 fp32 bit61 */
			{42158,42,0}, /* core4 fp32 bit62 */
			{42157,42,0}, /* core4 fp32 bit63 */
			}},
			.fp64 = {{
			{40979,42,0}, /* core4 fp64 bit0 */
			{40978,42,0}, /* core4 fp64 bit1 */
			{28248,42,0}, /* core4 fp64 bit2 */
			{40999,42,0}, /* core4 fp64 bit3 */
			{36342,42,0}, /* core4 fp64 bit4 */
			{40977,42,0}, /* core4 fp64 bit5 */
			{40970,42,0}, /* core4 fp64 bit6 */
			{40976,42,0}, /* core4 fp64 bit7 */
			{40969,42,0}, /* core4 fp64 bit8 */
			{40968,42,0}, /* core4 fp64 bit9 */
			{40975,42,0}, /* core4 fp64 bit10 */
			{40974,42,0}, /* core4 fp64 bit11 */
			{40987,42,0}, /* core4 fp64 bit12 */
			{40986,42,0}, /* core4 fp64 bit13 */
			{40985,42,0}, /* core4 fp64 bit14 */
			{40973,42,0}, /* core4 fp64 bit15 */
			{40998,42,0}, /* core4 fp64 bit16 */
			{40997,42,0}, /* core4 fp64 bit17 */
			{40996,42,0}, /* core4 fp64 bit18 */
			{36343,42,0}, /* core4 fp64 bit19 */
			{40995,42,0}, /* core4 fp64 bit20 */
			{40972,42,0}, /* core4 fp64 bit21 */
			{40984,42,0}, /* core4 fp64 bit22 */
			{40983,42,0}, /* core4 fp64 bit23 */
			{28249,42,0}, /* core4 fp64 bit24 */
			{40982,42,0}, /* core4 fp64 bit25 */
			{40994,42,0}, /* core4 fp64 bit26 */
			{40981,42,0}, /* core4 fp64 bit27 */
			{40993,42,0}, /* core4 fp64 bit28 */
			{40992,42,0}, /* core4 fp64 bit29 */
			{40980,42,0}, /* core4 fp64 bit30 */
			{40971,42,0}, /* core4 fp64 bit31 */
			{41143,42,0}, /* core4 fp64 bit32 */
			{41142,42,0}, /* core4 fp64 bit33 */
			{41141,42,0}, /* core4 fp64 bit34 */
			{28127,42,0}, /* core4 fp64 bit35 */
			{41140,42,0}, /* core4 fp64 bit36 */
			{36435,42,0}, /* core4 fp64 bit37 */
			{41151,42,0}, /* core4 fp64 bit38 */
			{41150,42,0}, /* core4 fp64 bit39 */
			{41149,42,0}, /* core4 fp64 bit40 */
			{41148,42,0}, /* core4 fp64 bit41 */
			{41147,42,0}, /* core4 fp64 bit42 */
			{41146,42,0}, /* core4 fp64 bit43 */
			{41145,42,0}, /* core4 fp64 bit44 */
			{28114,42,0}, /* core4 fp64 bit45 */
			{36434,42,0}, /* core4 fp64 bit46 */
			{41144,42,0}, /* core4 fp64 bit47 */
			{28132,42,0}, /* core4 fp64 bit48 */
			{36455,42,0}, /* core4 fp64 bit49 */
			{41119,42,0}, /* core4 fp64 bit50 */
			{41118,42,0}, /* core4 fp64 bit51 */
			{41117,42,0}, /* core4 fp64 bit52 */
			{36454,42,0}, /* core4 fp64 bit53 */
			{41116,42,0}, /* core4 fp64 bit54 */
			{41135,42,0}, /* core4 fp64 bit55 */
			{41134,42,0}, /* core4 fp64 bit56 */
			{41133,42,0}, /* core4 fp64 bit57 */
			{41132,42,0}, /* core4 fp64 bit58 */
			{28131,42,0}, /* core4 fp64 bit59 */
			{41115,42,0}, /* core4 fp64 bit60 */
			{41114,42,0}, /* core4 fp64 bit61 */
			{41113,42,0}, /* core4 fp64 bit62 */
			{41112,42,0}, /* core4 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40942,42,0}, /* core4 sp_EL0 bit0 */
			{40941,42,0}, /* core4 sp_EL0 bit1 */
			{40940,42,0}, /* core4 sp_EL0 bit2 */
			{41010,42,0}, /* core4 sp_EL0 bit3 */
			{41009,42,0}, /* core4 sp_EL0 bit4 */
			{40939,42,0}, /* core4 sp_EL0 bit5 */
			{40938,42,0}, /* core4 sp_EL0 bit6 */
			{40937,42,0}, /* core4 sp_EL0 bit7 */
			{40936,42,0}, /* core4 sp_EL0 bit8 */
			{40931,42,0}, /* core4 sp_EL0 bit9 */
			{40947,42,0}, /* core4 sp_EL0 bit10 */
			{40930,42,0}, /* core4 sp_EL0 bit11 */
			{40929,42,0}, /* core4 sp_EL0 bit12 */
			{40928,42,0}, /* core4 sp_EL0 bit13 */
			{40951,42,0}, /* core4 sp_EL0 bit14 */
			{40950,42,0}, /* core4 sp_EL0 bit15 */
			{41008,42,0}, /* core4 sp_EL0 bit16 */
			{41015,42,0}, /* core4 sp_EL0 bit17 */
			{41014,42,0}, /* core4 sp_EL0 bit18 */
			{41011,42,0}, /* core4 sp_EL0 bit19 */
			{41013,42,0}, /* core4 sp_EL0 bit20 */
			{40946,42,0}, /* core4 sp_EL0 bit21 */
			{40949,42,0}, /* core4 sp_EL0 bit22 */
			{40945,42,0}, /* core4 sp_EL0 bit23 */
			{28259,42,0}, /* core4 sp_EL0 bit24 */
			{40944,42,0}, /* core4 sp_EL0 bit25 */
			{41012,42,0}, /* core4 sp_EL0 bit26 */
			{36257,42,0}, /* core4 sp_EL0 bit27 */
			{36347,42,0}, /* core4 sp_EL0 bit28 */
			{36346,42,0}, /* core4 sp_EL0 bit29 */
			{36256,42,0}, /* core4 sp_EL0 bit30 */
			{40943,42,0}, /* core4 sp_EL0 bit31 */
			{41063,42,0}, /* core4 sp_EL0 bit32 */
			{41059,42,0}, /* core4 sp_EL0 bit33 */
			{41058,42,0}, /* core4 sp_EL0 bit34 */
			{41062,42,0}, /* core4 sp_EL0 bit35 */
			{41061,42,0}, /* core4 sp_EL0 bit36 */
			{41057,42,0}, /* core4 sp_EL0 bit37 */
			{41060,42,0}, /* core4 sp_EL0 bit38 */
			{41071,42,0}, /* core4 sp_EL0 bit39 */
			{41070,42,0}, /* core4 sp_EL0 bit40 */
			{41069,42,0}, /* core4 sp_EL0 bit41 */
			{41056,42,0}, /* core4 sp_EL0 bit42 */
			{41068,42,0}, /* core4 sp_EL0 bit43 */
			{41067,42,0}, /* core4 sp_EL0 bit44 */
			{41066,42,0}, /* core4 sp_EL0 bit45 */
			{41065,42,0}, /* core4 sp_EL0 bit46 */
			{41064,42,0}, /* core4 sp_EL0 bit47 */
			{28157,42,0}, /* core4 sp_EL0 bit48 */
			{41103,42,0}, /* core4 sp_EL0 bit49 */
			{41102,42,0}, /* core4 sp_EL0 bit50 */
			{41101,42,0}, /* core4 sp_EL0 bit51 */
			{41100,42,0}, /* core4 sp_EL0 bit52 */
			{41107,42,0}, /* core4 sp_EL0 bit53 */
			{41106,42,0}, /* core4 sp_EL0 bit54 */
			{41105,42,0}, /* core4 sp_EL0 bit55 */
			{41104,42,0}, /* core4 sp_EL0 bit56 */
			{41055,42,0}, /* core4 sp_EL0 bit57 */
			{41054,42,0}, /* core4 sp_EL0 bit58 */
			{41053,42,0}, /* core4 sp_EL0 bit59 */
			{41052,42,0}, /* core4 sp_EL0 bit60 */
			{41111,42,0}, /* core4 sp_EL0 bit61 */
			{41110,42,0}, /* core4 sp_EL0 bit62 */
			{41109,42,0}, /* core4 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40935,42,0}, /* core4 sp_EL1 bit0 */
			{40934,42,0}, /* core4 sp_EL1 bit1 */
			{40902,42,0}, /* core4 sp_EL1 bit2 */
			{40882,42,0}, /* core4 sp_EL1 bit3 */
			{40881,42,0}, /* core4 sp_EL1 bit4 */
			{40933,42,0}, /* core4 sp_EL1 bit5 */
			{40901,42,0}, /* core4 sp_EL1 bit6 */
			{40932,42,0}, /* core4 sp_EL1 bit7 */
			{40900,42,0}, /* core4 sp_EL1 bit8 */
			{40927,42,0}, /* core4 sp_EL1 bit9 */
			{40926,42,0}, /* core4 sp_EL1 bit10 */
			{40923,42,0}, /* core4 sp_EL1 bit11 */
			{40922,42,0}, /* core4 sp_EL1 bit12 */
			{40921,42,0}, /* core4 sp_EL1 bit13 */
			{40920,42,0}, /* core4 sp_EL1 bit14 */
			{40925,42,0}, /* core4 sp_EL1 bit15 */
			{40880,42,0}, /* core4 sp_EL1 bit16 */
			{40879,42,0}, /* core4 sp_EL1 bit17 */
			{40878,42,0}, /* core4 sp_EL1 bit18 */
			{36259,42,0}, /* core4 sp_EL1 bit19 */
			{40877,42,0}, /* core4 sp_EL1 bit20 */
			{40924,42,0}, /* core4 sp_EL1 bit21 */
			{28258,42,0}, /* core4 sp_EL1 bit22 */
			{40899,42,0}, /* core4 sp_EL1 bit23 */
			{36258,42,0}, /* core4 sp_EL1 bit24 */
			{40898,42,0}, /* core4 sp_EL1 bit25 */
			{40883,42,0}, /* core4 sp_EL1 bit26 */
			{40897,42,0}, /* core4 sp_EL1 bit27 */
			{40876,42,0}, /* core4 sp_EL1 bit28 */
			{28244,42,0}, /* core4 sp_EL1 bit29 */
			{40896,42,0}, /* core4 sp_EL1 bit30 */
			{40903,42,0}, /* core4 sp_EL1 bit31 */
			{40803,42,0}, /* core4 sp_EL1 bit32 */
			{40799,42,0}, /* core4 sp_EL1 bit33 */
			{40798,42,0}, /* core4 sp_EL1 bit34 */
			{40802,42,0}, /* core4 sp_EL1 bit35 */
			{40801,42,0}, /* core4 sp_EL1 bit36 */
			{40797,42,0}, /* core4 sp_EL1 bit37 */
			{40800,42,0}, /* core4 sp_EL1 bit38 */
			{40791,42,0}, /* core4 sp_EL1 bit39 */
			{40790,42,0}, /* core4 sp_EL1 bit40 */
			{40789,42,0}, /* core4 sp_EL1 bit41 */
			{40796,42,0}, /* core4 sp_EL1 bit42 */
			{40788,42,0}, /* core4 sp_EL1 bit43 */
			{40795,42,0}, /* core4 sp_EL1 bit44 */
			{40794,42,0}, /* core4 sp_EL1 bit45 */
			{40792,42,0}, /* core4 sp_EL1 bit46 */
			{40793,42,0}, /* core4 sp_EL1 bit47 */
			{28158,42,0}, /* core4 sp_EL1 bit48 */
			{36423,42,0}, /* core4 sp_EL1 bit49 */
			{40839,42,0}, /* core4 sp_EL1 bit50 */
			{40838,42,0}, /* core4 sp_EL1 bit51 */
			{40837,42,0}, /* core4 sp_EL1 bit52 */
			{36422,42,0}, /* core4 sp_EL1 bit53 */
			{40836,42,0}, /* core4 sp_EL1 bit54 */
			{40831,42,0}, /* core4 sp_EL1 bit55 */
			{40830,42,0}, /* core4 sp_EL1 bit56 */
			{40829,42,0}, /* core4 sp_EL1 bit57 */
			{40828,42,0}, /* core4 sp_EL1 bit58 */
			{28159,42,0}, /* core4 sp_EL1 bit59 */
			{40835,42,0}, /* core4 sp_EL1 bit60 */
			{40834,42,0}, /* core4 sp_EL1 bit61 */
			{40833,42,0}, /* core4 sp_EL1 bit62 */
			{40832,42,0}, /* core4 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40906,42,0}, /* core4 sp_EL2 bit0 */
			{40905,42,0}, /* core4 sp_EL2 bit1 */
			{40904,42,0}, /* core4 sp_EL2 bit2 */
			{40886,42,0}, /* core4 sp_EL2 bit3 */
			{40891,42,0}, /* core4 sp_EL2 bit4 */
			{40911,42,0}, /* core4 sp_EL2 bit5 */
			{40910,42,0}, /* core4 sp_EL2 bit6 */
			{40909,42,0}, /* core4 sp_EL2 bit7 */
			{40908,42,0}, /* core4 sp_EL2 bit8 */
			{40919,42,0}, /* core4 sp_EL2 bit9 */
			{40915,42,0}, /* core4 sp_EL2 bit10 */
			{40918,42,0}, /* core4 sp_EL2 bit11 */
			{40917,42,0}, /* core4 sp_EL2 bit12 */
			{40916,42,0}, /* core4 sp_EL2 bit13 */
			{40895,42,0}, /* core4 sp_EL2 bit14 */
			{40894,42,0}, /* core4 sp_EL2 bit15 */
			{40885,42,0}, /* core4 sp_EL2 bit16 */
			{40884,42,0}, /* core4 sp_EL2 bit17 */
			{40890,42,0}, /* core4 sp_EL2 bit18 */
			{28260,42,0}, /* core4 sp_EL2 bit19 */
			{40889,42,0}, /* core4 sp_EL2 bit20 */
			{40914,42,0}, /* core4 sp_EL2 bit21 */
			{40893,42,0}, /* core4 sp_EL2 bit22 */
			{40913,42,0}, /* core4 sp_EL2 bit23 */
			{40888,42,0}, /* core4 sp_EL2 bit24 */
			{40912,42,0}, /* core4 sp_EL2 bit25 */
			{40887,42,0}, /* core4 sp_EL2 bit26 */
			{36261,42,0}, /* core4 sp_EL2 bit27 */
			{36255,42,0}, /* core4 sp_EL2 bit28 */
			{36254,42,0}, /* core4 sp_EL2 bit29 */
			{36260,42,0}, /* core4 sp_EL2 bit30 */
			{40907,42,0}, /* core4 sp_EL2 bit31 */
			{40811,42,0}, /* core4 sp_EL2 bit32 */
			{40810,42,0}, /* core4 sp_EL2 bit33 */
			{40809,42,0}, /* core4 sp_EL2 bit34 */
			{40808,42,0}, /* core4 sp_EL2 bit35 */
			{40783,42,0}, /* core4 sp_EL2 bit36 */
			{40782,42,0}, /* core4 sp_EL2 bit37 */
			{40781,42,0}, /* core4 sp_EL2 bit38 */
			{40780,42,0}, /* core4 sp_EL2 bit39 */
			{40787,42,0}, /* core4 sp_EL2 bit40 */
			{40786,42,0}, /* core4 sp_EL2 bit41 */
			{40785,42,0}, /* core4 sp_EL2 bit42 */
			{40784,42,0}, /* core4 sp_EL2 bit43 */
			{40755,42,0}, /* core4 sp_EL2 bit44 */
			{40754,42,0}, /* core4 sp_EL2 bit45 */
			{40752,42,0}, /* core4 sp_EL2 bit46 */
			{40753,42,0}, /* core4 sp_EL2 bit47 */
			{28170,42,0}, /* core4 sp_EL2 bit48 */
			{28161,42,0}, /* core4 sp_EL2 bit49 */
			{40847,42,0}, /* core4 sp_EL2 bit50 */
			{40846,42,0}, /* core4 sp_EL2 bit51 */
			{40845,42,0}, /* core4 sp_EL2 bit52 */
			{40844,42,0}, /* core4 sp_EL2 bit53 */
			{40843,42,0}, /* core4 sp_EL2 bit54 */
			{40842,42,0}, /* core4 sp_EL2 bit55 */
			{40841,42,0}, /* core4 sp_EL2 bit56 */
			{40840,42,0}, /* core4 sp_EL2 bit57 */
			{40815,42,0}, /* core4 sp_EL2 bit58 */
			{40814,42,0}, /* core4 sp_EL2 bit59 */
			{40813,42,0}, /* core4 sp_EL2 bit60 */
			{40812,42,0}, /* core4 sp_EL2 bit61 */
			{36421,42,0}, /* core4 sp_EL2 bit62 */
			{36420,42,0}, /* core4 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40861,42,0}, /* core4 sp_EL3 bit0 */
			{40860,42,0}, /* core4 sp_EL3 bit1 */
			{40739,42,0}, /* core4 sp_EL3 bit2 */
			{40875,42,0}, /* core4 sp_EL3 bit3 */
			{40874,42,0}, /* core4 sp_EL3 bit4 */
			{40738,42,0}, /* core4 sp_EL3 bit5 */
			{40737,42,0}, /* core4 sp_EL3 bit6 */
			{40736,42,0}, /* core4 sp_EL3 bit7 */
			{40867,42,0}, /* core4 sp_EL3 bit8 */
			{40866,42,0}, /* core4 sp_EL3 bit9 */
			{40865,42,0}, /* core4 sp_EL3 bit10 */
			{40864,42,0}, /* core4 sp_EL3 bit11 */
			{40743,42,0}, /* core4 sp_EL3 bit12 */
			{40742,42,0}, /* core4 sp_EL3 bit13 */
			{40741,42,0}, /* core4 sp_EL3 bit14 */
			{40740,42,0}, /* core4 sp_EL3 bit15 */
			{40873,42,0}, /* core4 sp_EL3 bit16 */
			{40872,42,0}, /* core4 sp_EL3 bit17 */
			{40871,42,0}, /* core4 sp_EL3 bit18 */
			{40863,42,0}, /* core4 sp_EL3 bit19 */
			{40870,42,0}, /* core4 sp_EL3 bit20 */
			{40735,42,0}, /* core4 sp_EL3 bit21 */
			{40734,42,0}, /* core4 sp_EL3 bit22 */
			{40733,42,0}, /* core4 sp_EL3 bit23 */
			{28185,42,0}, /* core4 sp_EL3 bit24 */
			{40732,42,0}, /* core4 sp_EL3 bit25 */
			{40869,42,0}, /* core4 sp_EL3 bit26 */
			{36251,42,0}, /* core4 sp_EL3 bit27 */
			{40868,42,0}, /* core4 sp_EL3 bit28 */
			{28186,42,0}, /* core4 sp_EL3 bit29 */
			{36250,42,0}, /* core4 sp_EL3 bit30 */
			{40862,42,0}, /* core4 sp_EL3 bit31 */
			{40807,42,0}, /* core4 sp_EL3 bit32 */
			{40806,42,0}, /* core4 sp_EL3 bit33 */
			{40805,42,0}, /* core4 sp_EL3 bit34 */
			{40804,42,0}, /* core4 sp_EL3 bit35 */
			{40763,42,0}, /* core4 sp_EL3 bit36 */
			{40762,42,0}, /* core4 sp_EL3 bit37 */
			{40761,42,0}, /* core4 sp_EL3 bit38 */
			{40760,42,0}, /* core4 sp_EL3 bit39 */
			{40767,42,0}, /* core4 sp_EL3 bit40 */
			{40766,42,0}, /* core4 sp_EL3 bit41 */
			{40765,42,0}, /* core4 sp_EL3 bit42 */
			{40764,42,0}, /* core4 sp_EL3 bit43 */
			{40759,42,0}, /* core4 sp_EL3 bit44 */
			{40758,42,0}, /* core4 sp_EL3 bit45 */
			{40756,42,0}, /* core4 sp_EL3 bit46 */
			{40757,42,0}, /* core4 sp_EL3 bit47 */
			{28172,42,0}, /* core4 sp_EL3 bit48 */
			{36425,42,0}, /* core4 sp_EL3 bit49 */
			{40827,42,0}, /* core4 sp_EL3 bit50 */
			{40826,42,0}, /* core4 sp_EL3 bit51 */
			{40825,42,0}, /* core4 sp_EL3 bit52 */
			{40824,42,0}, /* core4 sp_EL3 bit53 */
			{40823,42,0}, /* core4 sp_EL3 bit54 */
			{40822,42,0}, /* core4 sp_EL3 bit55 */
			{40821,42,0}, /* core4 sp_EL3 bit56 */
			{40820,42,0}, /* core4 sp_EL3 bit57 */
			{40819,42,0}, /* core4 sp_EL3 bit58 */
			{36424,42,0}, /* core4 sp_EL3 bit59 */
			{40818,42,0}, /* core4 sp_EL3 bit60 */
			{40817,42,0}, /* core4 sp_EL3 bit61 */
			{40816,42,0}, /* core4 sp_EL3 bit62 */
			{28160,42,0}, /* core4 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{40707,42,0}, /* core4 elr_EL1 bit0 */
			{40706,42,0}, /* core4 elr_EL1 bit1 */
			{40705,42,0}, /* core4 elr_EL1 bit2 */
			{40723,42,0}, /* core4 elr_EL1 bit3 */
			{40722,42,0}, /* core4 elr_EL1 bit4 */
			{40704,42,0}, /* core4 elr_EL1 bit5 */
			{40703,42,0}, /* core4 elr_EL1 bit6 */
			{40702,42,0}, /* core4 elr_EL1 bit7 */
			{40701,42,0}, /* core4 elr_EL1 bit8 */
			{40700,42,0}, /* core4 elr_EL1 bit9 */
			{40695,42,0}, /* core4 elr_EL1 bit10 */
			{40694,42,0}, /* core4 elr_EL1 bit11 */
			{40693,42,0}, /* core4 elr_EL1 bit12 */
			{40692,42,0}, /* core4 elr_EL1 bit13 */
			{40699,42,0}, /* core4 elr_EL1 bit14 */
			{40698,42,0}, /* core4 elr_EL1 bit15 */
			{40721,42,0}, /* core4 elr_EL1 bit16 */
			{40720,42,0}, /* core4 elr_EL1 bit17 */
			{40727,42,0}, /* core4 elr_EL1 bit18 */
			{40697,42,0}, /* core4 elr_EL1 bit19 */
			{40726,42,0}, /* core4 elr_EL1 bit20 */
			{40696,42,0}, /* core4 elr_EL1 bit21 */
			{40715,42,0}, /* core4 elr_EL1 bit22 */
			{40714,42,0}, /* core4 elr_EL1 bit23 */
			{28252,42,0}, /* core4 elr_EL1 bit24 */
			{40713,42,0}, /* core4 elr_EL1 bit25 */
			{40725,42,0}, /* core4 elr_EL1 bit26 */
			{40712,42,0}, /* core4 elr_EL1 bit27 */
			{40724,42,0}, /* core4 elr_EL1 bit28 */
			{28251,42,0}, /* core4 elr_EL1 bit29 */
			{36265,42,0}, /* core4 elr_EL1 bit30 */
			{36264,42,0}, /* core4 elr_EL1 bit31 */
			{40751,42,0}, /* core4 elr_EL1 bit32 */
			{40750,42,0}, /* core4 elr_EL1 bit33 */
			{40749,42,0}, /* core4 elr_EL1 bit34 */
			{40748,42,0}, /* core4 elr_EL1 bit35 */
			{40771,42,0}, /* core4 elr_EL1 bit36 */
			{40770,42,0}, /* core4 elr_EL1 bit37 */
			{40769,42,0}, /* core4 elr_EL1 bit38 */
			{40768,42,0}, /* core4 elr_EL1 bit39 */
			{40775,42,0}, /* core4 elr_EL1 bit40 */
			{40774,42,0}, /* core4 elr_EL1 bit41 */
			{40773,42,0}, /* core4 elr_EL1 bit42 */
			{40772,42,0}, /* core4 elr_EL1 bit43 */
			{40779,42,0}, /* core4 elr_EL1 bit44 */
			{40778,42,0}, /* core4 elr_EL1 bit45 */
			{40777,42,0}, /* core4 elr_EL1 bit46 */
			{40776,42,0}, /* core4 elr_EL1 bit47 */
			{28165,42,0}, /* core4 elr_EL1 bit48 */
			{40859,42,0}, /* core4 elr_EL1 bit49 */
			{40858,42,0}, /* core4 elr_EL1 bit50 */
			{40857,42,0}, /* core4 elr_EL1 bit51 */
			{40856,42,0}, /* core4 elr_EL1 bit52 */
			{40855,42,0}, /* core4 elr_EL1 bit53 */
			{40854,42,0}, /* core4 elr_EL1 bit54 */
			{40853,42,0}, /* core4 elr_EL1 bit55 */
			{40852,42,0}, /* core4 elr_EL1 bit56 */
			{40747,42,0}, /* core4 elr_EL1 bit57 */
			{40746,42,0}, /* core4 elr_EL1 bit58 */
			{40745,42,0}, /* core4 elr_EL1 bit59 */
			{40744,42,0}, /* core4 elr_EL1 bit60 */
			{40851,42,0}, /* core4 elr_EL1 bit61 */
			{40850,42,0}, /* core4 elr_EL1 bit62 */
			{40849,42,0}, /* core4 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{40711,42,0}, /* core4 elr_EL2 bit0 */
			{40710,42,0}, /* core4 elr_EL2 bit1 */
			{40709,42,0}, /* core4 elr_EL2 bit2 */
			{40719,42,0}, /* core4 elr_EL2 bit3 */
			{40718,42,0}, /* core4 elr_EL2 bit4 */
			{40708,42,0}, /* core4 elr_EL2 bit5 */
			{40687,42,0}, /* core4 elr_EL2 bit6 */
			{40691,42,0}, /* core4 elr_EL2 bit7 */
			{40690,42,0}, /* core4 elr_EL2 bit8 */
			{40689,42,0}, /* core4 elr_EL2 bit9 */
			{40686,42,0}, /* core4 elr_EL2 bit10 */
			{40688,42,0}, /* core4 elr_EL2 bit11 */
			{40683,42,0}, /* core4 elr_EL2 bit12 */
			{40682,42,0}, /* core4 elr_EL2 bit13 */
			{40681,42,0}, /* core4 elr_EL2 bit14 */
			{40685,42,0}, /* core4 elr_EL2 bit15 */
			{40717,42,0}, /* core4 elr_EL2 bit16 */
			{40716,42,0}, /* core4 elr_EL2 bit17 */
			{40731,42,0}, /* core4 elr_EL2 bit18 */
			{40684,42,0}, /* core4 elr_EL2 bit19 */
			{40730,42,0}, /* core4 elr_EL2 bit20 */
			{40679,42,0}, /* core4 elr_EL2 bit21 */
			{40680,42,0}, /* core4 elr_EL2 bit22 */
			{40678,42,0}, /* core4 elr_EL2 bit23 */
			{28253,42,0}, /* core4 elr_EL2 bit24 */
			{40677,42,0}, /* core4 elr_EL2 bit25 */
			{40729,42,0}, /* core4 elr_EL2 bit26 */
			{40676,42,0}, /* core4 elr_EL2 bit27 */
			{40728,42,0}, /* core4 elr_EL2 bit28 */
			{28254,42,0}, /* core4 elr_EL2 bit29 */
			{28255,42,0}, /* core4 elr_EL2 bit30 */
			{28256,42,0}, /* core4 elr_EL2 bit31 */
			{40501,42,0}, /* core4 elr_EL2 bit32 */
			{40500,42,0}, /* core4 elr_EL2 bit33 */
			{40499,42,0}, /* core4 elr_EL2 bit34 */
			{40498,42,0}, /* core4 elr_EL2 bit35 */
			{40481,42,0}, /* core4 elr_EL2 bit36 */
			{40480,42,0}, /* core4 elr_EL2 bit37 */
			{40479,42,0}, /* core4 elr_EL2 bit38 */
			{40478,42,0}, /* core4 elr_EL2 bit39 */
			{40477,42,0}, /* core4 elr_EL2 bit40 */
			{40476,42,0}, /* core4 elr_EL2 bit41 */
			{40475,42,0}, /* core4 elr_EL2 bit42 */
			{40474,42,0}, /* core4 elr_EL2 bit43 */
			{40485,42,0}, /* core4 elr_EL2 bit44 */
			{40484,42,0}, /* core4 elr_EL2 bit45 */
			{40483,42,0}, /* core4 elr_EL2 bit46 */
			{40482,42,0}, /* core4 elr_EL2 bit47 */
			{28164,42,0}, /* core4 elr_EL2 bit48 */
			{40509,42,0}, /* core4 elr_EL2 bit49 */
			{40508,42,0}, /* core4 elr_EL2 bit50 */
			{40507,42,0}, /* core4 elr_EL2 bit51 */
			{40506,42,0}, /* core4 elr_EL2 bit52 */
			{40465,42,0}, /* core4 elr_EL2 bit53 */
			{40464,42,0}, /* core4 elr_EL2 bit54 */
			{40463,42,0}, /* core4 elr_EL2 bit55 */
			{40462,42,0}, /* core4 elr_EL2 bit56 */
			{40473,42,0}, /* core4 elr_EL2 bit57 */
			{40472,42,0}, /* core4 elr_EL2 bit58 */
			{40471,42,0}, /* core4 elr_EL2 bit59 */
			{40470,42,0}, /* core4 elr_EL2 bit60 */
			{40469,42,0}, /* core4 elr_EL2 bit61 */
			{40468,42,0}, /* core4 elr_EL2 bit62 */
			{40467,42,0}, /* core4 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{40452,42,0}, /* core4 elr_EL3 bit0 */
			{40451,42,0}, /* core4 elr_EL3 bit1 */
			{40450,42,0}, /* core4 elr_EL3 bit2 */
			{40437,42,0}, /* core4 elr_EL3 bit3 */
			{40436,42,0}, /* core4 elr_EL3 bit4 */
			{40441,42,0}, /* core4 elr_EL3 bit5 */
			{40440,42,0}, /* core4 elr_EL3 bit6 */
			{40439,42,0}, /* core4 elr_EL3 bit7 */
			{40438,42,0}, /* core4 elr_EL3 bit8 */
			{40449,42,0}, /* core4 elr_EL3 bit9 */
			{40448,42,0}, /* core4 elr_EL3 bit10 */
			{40447,42,0}, /* core4 elr_EL3 bit11 */
			{40446,42,0}, /* core4 elr_EL3 bit12 */
			{40457,42,0}, /* core4 elr_EL3 bit13 */
			{40456,42,0}, /* core4 elr_EL3 bit14 */
			{40455,42,0}, /* core4 elr_EL3 bit15 */
			{40435,42,0}, /* core4 elr_EL3 bit16 */
			{40434,42,0}, /* core4 elr_EL3 bit17 */
			{40461,42,0}, /* core4 elr_EL3 bit18 */
			{40445,42,0}, /* core4 elr_EL3 bit19 */
			{40460,42,0}, /* core4 elr_EL3 bit20 */
			{40444,42,0}, /* core4 elr_EL3 bit21 */
			{40454,42,0}, /* core4 elr_EL3 bit22 */
			{40443,42,0}, /* core4 elr_EL3 bit23 */
			{28245,42,0}, /* core4 elr_EL3 bit24 */
			{40442,42,0}, /* core4 elr_EL3 bit25 */
			{40459,42,0}, /* core4 elr_EL3 bit26 */
			{36263,42,0}, /* core4 elr_EL3 bit27 */
			{40458,42,0}, /* core4 elr_EL3 bit28 */
			{28246,42,0}, /* core4 elr_EL3 bit29 */
			{36262,42,0}, /* core4 elr_EL3 bit30 */
			{40453,42,0}, /* core4 elr_EL3 bit31 */
			{40505,42,0}, /* core4 elr_EL3 bit32 */
			{40504,42,0}, /* core4 elr_EL3 bit33 */
			{40503,42,0}, /* core4 elr_EL3 bit34 */
			{40493,42,0}, /* core4 elr_EL3 bit35 */
			{40492,42,0}, /* core4 elr_EL3 bit36 */
			{40502,42,0}, /* core4 elr_EL3 bit37 */
			{40491,42,0}, /* core4 elr_EL3 bit38 */
			{40490,42,0}, /* core4 elr_EL3 bit39 */
			{40489,42,0}, /* core4 elr_EL3 bit40 */
			{40488,42,0}, /* core4 elr_EL3 bit41 */
			{40497,42,0}, /* core4 elr_EL3 bit42 */
			{40487,42,0}, /* core4 elr_EL3 bit43 */
			{40496,42,0}, /* core4 elr_EL3 bit44 */
			{40495,42,0}, /* core4 elr_EL3 bit45 */
			{36215,42,0}, /* core4 elr_EL3 bit46 */
			{40494,42,0}, /* core4 elr_EL3 bit47 */
			{36214,42,0}, /* core4 elr_EL3 bit48 */
			{40517,42,0}, /* core4 elr_EL3 bit49 */
			{40516,42,0}, /* core4 elr_EL3 bit50 */
			{40515,42,0}, /* core4 elr_EL3 bit51 */
			{40514,42,0}, /* core4 elr_EL3 bit52 */
			{40521,42,0}, /* core4 elr_EL3 bit53 */
			{40520,42,0}, /* core4 elr_EL3 bit54 */
			{40519,42,0}, /* core4 elr_EL3 bit55 */
			{40518,42,0}, /* core4 elr_EL3 bit56 */
			{40513,42,0}, /* core4 elr_EL3 bit57 */
			{40512,42,0}, /* core4 elr_EL3 bit58 */
			{40511,42,0}, /* core4 elr_EL3 bit59 */
			{40510,42,0}, /* core4 elr_EL3 bit60 */
			{40433,42,0}, /* core4 elr_EL3 bit61 */
			{40432,42,0}, /* core4 elr_EL3 bit62 */
			{40431,42,0}, /* core4 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{30898,42,0}, /* core4 raw_pc bit0 */
			{33534,41,0}, /* core4 raw_pc bit1 */
			{33533,41,0}, /* core4 raw_pc bit2 */
			{33532,41,0}, /* core4 raw_pc bit3 */
			{33531,41,0}, /* core4 raw_pc bit4 */
			{37455,42,0}, /* core4 raw_pc bit5 */
			{37454,42,0}, /* core4 raw_pc bit6 */
			{37453,42,0}, /* core4 raw_pc bit7 */
			{37452,42,0}, /* core4 raw_pc bit8 */
			{37451,42,0}, /* core4 raw_pc bit9 */
			{37450,42,0}, /* core4 raw_pc bit10 */
			{37447,42,0}, /* core4 raw_pc bit11 */
			{37446,42,0}, /* core4 raw_pc bit12 */
			{37449,42,0}, /* core4 raw_pc bit13 */
			{37448,42,0}, /* core4 raw_pc bit14 */
			{33538,41,0}, /* core4 raw_pc bit15 */
			{33537,41,0}, /* core4 raw_pc bit16 */
			{33536,41,0}, /* core4 raw_pc bit17 */
			{33535,41,0}, /* core4 raw_pc bit18 */
			{33542,41,0}, /* core4 raw_pc bit19 */
			{33541,41,0}, /* core4 raw_pc bit20 */
			{33540,41,0}, /* core4 raw_pc bit21 */
			{33539,41,0}, /* core4 raw_pc bit22 */
			{33546,41,0}, /* core4 raw_pc bit23 */
			{33545,41,0}, /* core4 raw_pc bit24 */
			{33544,41,0}, /* core4 raw_pc bit25 */
			{33543,41,0}, /* core4 raw_pc bit26 */
			{33482,41,0}, /* core4 raw_pc bit27 */
			{33481,41,0}, /* core4 raw_pc bit28 */
			{33480,41,0}, /* core4 raw_pc bit29 */
			{33479,41,0}, /* core4 raw_pc bit30 */
			{33606,41,0}, /* core4 raw_pc bit31 */
			{33605,41,0}, /* core4 raw_pc bit32 */
			{33604,41,0}, /* core4 raw_pc bit33 */
			{33603,41,0}, /* core4 raw_pc bit34 */
			{37245,42,0}, /* core4 raw_pc bit35 */
			{37244,42,0}, /* core4 raw_pc bit36 */
			{37249,42,0}, /* core4 raw_pc bit37 */
			{37248,42,0}, /* core4 raw_pc bit38 */
			{33602,41,0}, /* core4 raw_pc bit39 */
			{33601,41,0}, /* core4 raw_pc bit40 */
			{33600,41,0}, /* core4 raw_pc bit41 */
			{33599,41,0}, /* core4 raw_pc bit42 */
			{37247,42,0}, /* core4 raw_pc bit43 */
			{37246,42,0}, /* core4 raw_pc bit44 */
			{37251,42,0}, /* core4 raw_pc bit45 */
			{37250,42,0}, /* core4 raw_pc bit46 */
			{33598,41,0}, /* core4 raw_pc bit47 */
			{33597,41,0}, /* core4 raw_pc bit48 */
			{33596,41,0}, /* core4 raw_pc bit49 */
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
			{33491,41,0}, /* core4 pc_iss bit0 */
			{33498,41,0}, /* core4 pc_iss bit1 */
			{33497,41,0}, /* core4 pc_iss bit2 */
			{33496,41,0}, /* core4 pc_iss bit3 */
			{33495,41,0}, /* core4 pc_iss bit4 */
			{33494,41,0}, /* core4 pc_iss bit5 */
			{33493,41,0}, /* core4 pc_iss bit6 */
			{33492,41,0}, /* core4 pc_iss bit7 */
			{33522,41,0}, /* core4 pc_iss bit8 */
			{33521,41,0}, /* core4 pc_iss bit9 */
			{33520,41,0}, /* core4 pc_iss bit10 */
			{33519,41,0}, /* core4 pc_iss bit11 */
			{33470,41,0}, /* core4 pc_iss bit12 */
			{33469,41,0}, /* core4 pc_iss bit13 */
			{33468,41,0}, /* core4 pc_iss bit14 */
			{33467,41,0}, /* core4 pc_iss bit15 */
			{33526,41,0}, /* core4 pc_iss bit16 */
			{33525,41,0}, /* core4 pc_iss bit17 */
			{33524,41,0}, /* core4 pc_iss bit18 */
			{33523,41,0}, /* core4 pc_iss bit19 */
			{33530,41,0}, /* core4 pc_iss bit20 */
			{33529,41,0}, /* core4 pc_iss bit21 */
			{33528,41,0}, /* core4 pc_iss bit22 */
			{33527,41,0}, /* core4 pc_iss bit23 */
			{33474,41,0}, /* core4 pc_iss bit24 */
			{33473,41,0}, /* core4 pc_iss bit25 */
			{33472,41,0}, /* core4 pc_iss bit26 */
			{33471,41,0}, /* core4 pc_iss bit27 */
			{33478,41,0}, /* core4 pc_iss bit28 */
			{33477,41,0}, /* core4 pc_iss bit29 */
			{33476,41,0}, /* core4 pc_iss bit30 */
			{33475,41,0}, /* core4 pc_iss bit31 */
			{33631,41,0}, /* core4 pc_iss bit32 */
			{33618,41,0}, /* core4 pc_iss bit33 */
			{33617,41,0}, /* core4 pc_iss bit34 */
			{33616,41,0}, /* core4 pc_iss bit35 */
			{33621,41,0}, /* core4 pc_iss bit36 */
			{33615,41,0}, /* core4 pc_iss bit37 */
			{33620,41,0}, /* core4 pc_iss bit38 */
			{33619,41,0}, /* core4 pc_iss bit39 */
			{33614,41,0}, /* core4 pc_iss bit40 */
			{33613,41,0}, /* core4 pc_iss bit41 */
			{33610,41,0}, /* core4 pc_iss bit42 */
			{33612,41,0}, /* core4 pc_iss bit43 */
			{33611,41,0}, /* core4 pc_iss bit44 */
			{33630,41,0}, /* core4 pc_iss bit45 */
			{33629,41,0}, /* core4 pc_iss bit46 */
			{33609,41,0}, /* core4 pc_iss bit47 */
			{33628,41,0}, /* core4 pc_iss bit48 */
			{33627,41,0}, /* core4 pc_iss bit49 */
			{33626,41,0}, /* core4 pc_iss bit50 */
			{33625,41,0}, /* core4 pc_iss bit51 */
			{33624,41,0}, /* core4 pc_iss bit52 */
			{33622,41,0}, /* core4 pc_iss bit53 */
			{33623,41,0}, /* core4 pc_iss bit54 */
			{33634,41,0}, /* core4 pc_iss bit55 */
			{33633,41,0}, /* core4 pc_iss bit56 */
			{33632,41,0}, /* core4 pc_iss bit57 */
			{33608,41,0}, /* core4 pc_iss bit58 */
			{33607,41,0}, /* core4 pc_iss bit59 */
			{33638,41,0}, /* core4 pc_iss bit60 */
			{33637,41,0}, /* core4 pc_iss bit61 */
			{33636,41,0}, /* core4 pc_iss bit62 */
			{33635,41,0}, /* core4 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{30897,42,0}, /* core4 full_pc_wr bit0 */
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
			{30971,42,0}, /* core4 full_pc_ex1 bit0 */
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
			{30942,42,0}, /* core4 full_pc_ex2 bit0 */
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
			{16598,42,0}, /* core4 return_Stack_pointer bit0 */
			{16597,42,0}, /* core4 return_Stack_pointer bit1 */
			{13720,42,0}, /* core4 return_Stack_pointer bit2 */
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
			{23469,42,0}, /* core4 return_Stack0 bit0 */
			{23468,42,0}, /* core4 return_Stack0 bit1 */
			{23467,42,0}, /* core4 return_Stack0 bit2 */
			{23449,42,0}, /* core4 return_Stack0 bit3 */
			{23448,42,0}, /* core4 return_Stack0 bit4 */
			{23447,42,0}, /* core4 return_Stack0 bit5 */
			{23446,42,0}, /* core4 return_Stack0 bit6 */
			{23365,42,0}, /* core4 return_Stack0 bit7 */
			{23364,42,0}, /* core4 return_Stack0 bit8 */
			{23363,42,0}, /* core4 return_Stack0 bit9 */
			{23466,42,0}, /* core4 return_Stack0 bit10 */
			{23417,42,0}, /* core4 return_Stack0 bit11 */
			{23416,42,0}, /* core4 return_Stack0 bit12 */
			{23415,42,0}, /* core4 return_Stack0 bit13 */
			{23414,42,0}, /* core4 return_Stack0 bit14 */
			{23369,42,0}, /* core4 return_Stack0 bit15 */
			{23368,42,0}, /* core4 return_Stack0 bit16 */
			{23367,42,0}, /* core4 return_Stack0 bit17 */
			{23366,42,0}, /* core4 return_Stack0 bit18 */
			{23421,42,0}, /* core4 return_Stack0 bit19 */
			{23420,42,0}, /* core4 return_Stack0 bit20 */
			{23419,42,0}, /* core4 return_Stack0 bit21 */
			{23418,42,0}, /* core4 return_Stack0 bit22 */
			{23465,42,1}, /* core4 return_Stack0 bit23 */
			{23464,42,1}, /* core4 return_Stack0 bit24 */
			{23463,42,1}, /* core4 return_Stack0 bit25 */
			{23462,42,1}, /* core4 return_Stack0 bit26 */
			{23385,42,1}, /* core4 return_Stack0 bit27 */
			{23384,42,1}, /* core4 return_Stack0 bit28 */
			{23383,42,1}, /* core4 return_Stack0 bit29 */
			{23382,42,1}, /* core4 return_Stack0 bit30 */
			{13706,42,0}, /* core4 return_Stack0 bit31 */
			{23381,42,0}, /* core4 return_Stack0 bit32 */
			{23380,42,0}, /* core4 return_Stack0 bit33 */
			{23379,42,0}, /* core4 return_Stack0 bit34 */
			{23378,42,0}, /* core4 return_Stack0 bit35 */
			{23413,42,1}, /* core4 return_Stack0 bit36 */
			{23412,42,1}, /* core4 return_Stack0 bit37 */
			{23411,42,1}, /* core4 return_Stack0 bit38 */
			{23410,42,1}, /* core4 return_Stack0 bit39 */
			{23405,42,0}, /* core4 return_Stack0 bit40 */
			{23404,42,0}, /* core4 return_Stack0 bit41 */
			{23403,42,0}, /* core4 return_Stack0 bit42 */
			{23402,42,0}, /* core4 return_Stack0 bit43 */
			{23409,42,1}, /* core4 return_Stack0 bit44 */
			{23408,42,1}, /* core4 return_Stack0 bit45 */
			{23407,42,1}, /* core4 return_Stack0 bit46 */
			{23406,42,1}, /* core4 return_Stack0 bit47 */
			{13707,42,0}, /* core4 return_Stack0 bit48 */
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
			{23461,42,0}, /* core4 return_Stack1 bit0 */
			{23460,42,0}, /* core4 return_Stack1 bit1 */
			{23459,42,0}, /* core4 return_Stack1 bit2 */
			{23445,42,0}, /* core4 return_Stack1 bit3 */
			{23444,42,0}, /* core4 return_Stack1 bit4 */
			{23443,42,0}, /* core4 return_Stack1 bit5 */
			{23442,42,0}, /* core4 return_Stack1 bit6 */
			{23441,42,0}, /* core4 return_Stack1 bit7 */
			{23440,42,0}, /* core4 return_Stack1 bit8 */
			{23439,42,0}, /* core4 return_Stack1 bit9 */
			{23458,42,0}, /* core4 return_Stack1 bit10 */
			{23425,42,0}, /* core4 return_Stack1 bit11 */
			{23424,42,0}, /* core4 return_Stack1 bit12 */
			{23423,42,0}, /* core4 return_Stack1 bit13 */
			{23422,42,0}, /* core4 return_Stack1 bit14 */
			{23373,42,0}, /* core4 return_Stack1 bit15 */
			{23372,42,0}, /* core4 return_Stack1 bit16 */
			{23371,42,0}, /* core4 return_Stack1 bit17 */
			{23370,42,0}, /* core4 return_Stack1 bit18 */
			{23429,42,0}, /* core4 return_Stack1 bit19 */
			{23428,42,0}, /* core4 return_Stack1 bit20 */
			{23427,42,0}, /* core4 return_Stack1 bit21 */
			{23426,42,0}, /* core4 return_Stack1 bit22 */
			{23393,42,1}, /* core4 return_Stack1 bit23 */
			{23392,42,1}, /* core4 return_Stack1 bit24 */
			{23391,42,1}, /* core4 return_Stack1 bit25 */
			{23390,42,1}, /* core4 return_Stack1 bit26 */
			{23389,42,1}, /* core4 return_Stack1 bit27 */
			{23388,42,1}, /* core4 return_Stack1 bit28 */
			{23387,42,1}, /* core4 return_Stack1 bit29 */
			{23386,42,1}, /* core4 return_Stack1 bit30 */
			{13711,42,0}, /* core4 return_Stack1 bit31 */
			{23377,42,0}, /* core4 return_Stack1 bit32 */
			{23376,42,0}, /* core4 return_Stack1 bit33 */
			{23375,42,0}, /* core4 return_Stack1 bit34 */
			{23374,42,0}, /* core4 return_Stack1 bit35 */
			{23453,42,1}, /* core4 return_Stack1 bit36 */
			{23452,42,1}, /* core4 return_Stack1 bit37 */
			{23451,42,1}, /* core4 return_Stack1 bit38 */
			{23450,42,1}, /* core4 return_Stack1 bit39 */
			{23401,42,0}, /* core4 return_Stack1 bit40 */
			{23400,42,0}, /* core4 return_Stack1 bit41 */
			{23399,42,0}, /* core4 return_Stack1 bit42 */
			{23398,42,0}, /* core4 return_Stack1 bit43 */
			{23457,42,1}, /* core4 return_Stack1 bit44 */
			{23456,42,1}, /* core4 return_Stack1 bit45 */
			{23455,42,1}, /* core4 return_Stack1 bit46 */
			{23454,42,1}, /* core4 return_Stack1 bit47 */
			{13705,42,0}, /* core4 return_Stack1 bit48 */
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
			{23397,42,0}, /* core4 return_Stack2 bit0 */
			{23396,42,0}, /* core4 return_Stack2 bit1 */
			{23395,42,0}, /* core4 return_Stack2 bit2 */
			{23437,42,0}, /* core4 return_Stack2 bit3 */
			{23436,42,0}, /* core4 return_Stack2 bit4 */
			{23435,42,0}, /* core4 return_Stack2 bit5 */
			{23434,42,0}, /* core4 return_Stack2 bit6 */
			{23361,42,0}, /* core4 return_Stack2 bit7 */
			{23360,42,0}, /* core4 return_Stack2 bit8 */
			{23359,42,0}, /* core4 return_Stack2 bit9 */
			{23394,42,0}, /* core4 return_Stack2 bit10 */
			{23433,42,0}, /* core4 return_Stack2 bit11 */
			{23432,42,0}, /* core4 return_Stack2 bit12 */
			{23431,42,0}, /* core4 return_Stack2 bit13 */
			{23430,42,0}, /* core4 return_Stack2 bit14 */
			{23357,42,1}, /* core4 return_Stack2 bit15 */
			{23356,42,1}, /* core4 return_Stack2 bit16 */
			{23355,42,1}, /* core4 return_Stack2 bit17 */
			{23354,42,1}, /* core4 return_Stack2 bit18 */
			{23216,42,0}, /* core4 return_Stack2 bit19 */
			{23215,42,0}, /* core4 return_Stack2 bit20 */
			{23214,42,0}, /* core4 return_Stack2 bit21 */
			{23213,42,0}, /* core4 return_Stack2 bit22 */
			{23312,42,1}, /* core4 return_Stack2 bit23 */
			{23311,42,1}, /* core4 return_Stack2 bit24 */
			{23310,42,1}, /* core4 return_Stack2 bit25 */
			{23309,42,1}, /* core4 return_Stack2 bit26 */
			{23128,42,1}, /* core4 return_Stack2 bit27 */
			{23127,42,1}, /* core4 return_Stack2 bit28 */
			{23126,42,1}, /* core4 return_Stack2 bit29 */
			{23125,42,1}, /* core4 return_Stack2 bit30 */
			{13712,42,0}, /* core4 return_Stack2 bit31 */
			{23152,42,1}, /* core4 return_Stack2 bit32 */
			{23151,42,1}, /* core4 return_Stack2 bit33 */
			{23150,42,1}, /* core4 return_Stack2 bit34 */
			{23149,42,1}, /* core4 return_Stack2 bit35 */
			{23244,42,1}, /* core4 return_Stack2 bit36 */
			{23243,42,1}, /* core4 return_Stack2 bit37 */
			{23242,42,1}, /* core4 return_Stack2 bit38 */
			{23241,42,1}, /* core4 return_Stack2 bit39 */
			{23308,42,1}, /* core4 return_Stack2 bit40 */
			{23307,42,1}, /* core4 return_Stack2 bit41 */
			{23306,42,1}, /* core4 return_Stack2 bit42 */
			{23305,42,1}, /* core4 return_Stack2 bit43 */
			{23256,42,1}, /* core4 return_Stack2 bit44 */
			{23255,42,1}, /* core4 return_Stack2 bit45 */
			{23254,42,1}, /* core4 return_Stack2 bit46 */
			{23253,42,1}, /* core4 return_Stack2 bit47 */
			{13713,42,0}, /* core4 return_Stack2 bit48 */
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
			{23332,42,0}, /* core4 return_Stack3 bit0 */
			{23331,42,0}, /* core4 return_Stack3 bit1 */
			{23330,42,0}, /* core4 return_Stack3 bit2 */
			{23204,42,0}, /* core4 return_Stack3 bit3 */
			{23203,42,0}, /* core4 return_Stack3 bit4 */
			{23202,42,0}, /* core4 return_Stack3 bit5 */
			{23201,42,0}, /* core4 return_Stack3 bit6 */
			{23168,42,0}, /* core4 return_Stack3 bit7 */
			{23167,42,0}, /* core4 return_Stack3 bit8 */
			{23166,42,0}, /* core4 return_Stack3 bit9 */
			{23329,42,0}, /* core4 return_Stack3 bit10 */
			{23228,42,0}, /* core4 return_Stack3 bit11 */
			{23227,42,0}, /* core4 return_Stack3 bit12 */
			{23226,42,0}, /* core4 return_Stack3 bit13 */
			{23225,42,0}, /* core4 return_Stack3 bit14 */
			{23160,42,1}, /* core4 return_Stack3 bit15 */
			{23159,42,1}, /* core4 return_Stack3 bit16 */
			{23158,42,1}, /* core4 return_Stack3 bit17 */
			{23157,42,1}, /* core4 return_Stack3 bit18 */
			{23224,42,0}, /* core4 return_Stack3 bit19 */
			{23223,42,0}, /* core4 return_Stack3 bit20 */
			{23222,42,0}, /* core4 return_Stack3 bit21 */
			{23221,42,0}, /* core4 return_Stack3 bit22 */
			{23340,42,1}, /* core4 return_Stack3 bit23 */
			{23339,42,1}, /* core4 return_Stack3 bit24 */
			{23338,42,1}, /* core4 return_Stack3 bit25 */
			{23337,42,1}, /* core4 return_Stack3 bit26 */
			{23124,42,1}, /* core4 return_Stack3 bit27 */
			{23123,42,1}, /* core4 return_Stack3 bit28 */
			{23122,42,1}, /* core4 return_Stack3 bit29 */
			{23121,42,1}, /* core4 return_Stack3 bit30 */
			{13714,42,0}, /* core4 return_Stack3 bit31 */
			{23148,42,1}, /* core4 return_Stack3 bit32 */
			{23147,42,1}, /* core4 return_Stack3 bit33 */
			{23146,42,1}, /* core4 return_Stack3 bit34 */
			{23145,42,1}, /* core4 return_Stack3 bit35 */
			{23272,42,1}, /* core4 return_Stack3 bit36 */
			{23271,42,1}, /* core4 return_Stack3 bit37 */
			{23270,42,1}, /* core4 return_Stack3 bit38 */
			{23269,42,1}, /* core4 return_Stack3 bit39 */
			{23320,42,1}, /* core4 return_Stack3 bit40 */
			{23319,42,1}, /* core4 return_Stack3 bit41 */
			{23318,42,1}, /* core4 return_Stack3 bit42 */
			{23317,42,1}, /* core4 return_Stack3 bit43 */
			{23264,42,1}, /* core4 return_Stack3 bit44 */
			{23263,42,1}, /* core4 return_Stack3 bit45 */
			{23262,42,1}, /* core4 return_Stack3 bit46 */
			{23261,42,1}, /* core4 return_Stack3 bit47 */
			{13717,42,0}, /* core4 return_Stack3 bit48 */
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
			{23352,42,0}, /* core4 return_Stack4 bit0 */
			{23351,42,0}, /* core4 return_Stack4 bit1 */
			{23350,42,0}, /* core4 return_Stack4 bit2 */
			{23268,42,0}, /* core4 return_Stack4 bit3 */
			{23267,42,0}, /* core4 return_Stack4 bit4 */
			{23266,42,0}, /* core4 return_Stack4 bit5 */
			{23265,42,0}, /* core4 return_Stack4 bit6 */
			{23180,42,0}, /* core4 return_Stack4 bit7 */
			{23179,42,0}, /* core4 return_Stack4 bit8 */
			{23178,42,0}, /* core4 return_Stack4 bit9 */
			{23349,42,0}, /* core4 return_Stack4 bit10 */
			{23288,42,0}, /* core4 return_Stack4 bit11 */
			{23287,42,0}, /* core4 return_Stack4 bit12 */
			{23286,42,0}, /* core4 return_Stack4 bit13 */
			{23285,42,0}, /* core4 return_Stack4 bit14 */
			{23184,42,0}, /* core4 return_Stack4 bit15 */
			{23183,42,0}, /* core4 return_Stack4 bit16 */
			{23182,42,0}, /* core4 return_Stack4 bit17 */
			{23181,42,0}, /* core4 return_Stack4 bit18 */
			{23284,42,0}, /* core4 return_Stack4 bit19 */
			{23283,42,0}, /* core4 return_Stack4 bit20 */
			{23282,42,0}, /* core4 return_Stack4 bit21 */
			{23281,42,0}, /* core4 return_Stack4 bit22 */
			{23344,42,1}, /* core4 return_Stack4 bit23 */
			{23343,42,1}, /* core4 return_Stack4 bit24 */
			{23342,42,1}, /* core4 return_Stack4 bit25 */
			{23341,42,1}, /* core4 return_Stack4 bit26 */
			{23116,42,1}, /* core4 return_Stack4 bit27 */
			{23115,42,1}, /* core4 return_Stack4 bit28 */
			{23114,42,1}, /* core4 return_Stack4 bit29 */
			{23113,42,1}, /* core4 return_Stack4 bit30 */
			{13708,42,0}, /* core4 return_Stack4 bit31 */
			{23140,42,0}, /* core4 return_Stack4 bit32 */
			{23139,42,0}, /* core4 return_Stack4 bit33 */
			{23138,42,0}, /* core4 return_Stack4 bit34 */
			{23137,42,0}, /* core4 return_Stack4 bit35 */
			{23292,42,1}, /* core4 return_Stack4 bit36 */
			{23291,42,1}, /* core4 return_Stack4 bit37 */
			{23290,42,1}, /* core4 return_Stack4 bit38 */
			{23289,42,1}, /* core4 return_Stack4 bit39 */
			{23300,42,0}, /* core4 return_Stack4 bit40 */
			{23299,42,0}, /* core4 return_Stack4 bit41 */
			{23298,42,0}, /* core4 return_Stack4 bit42 */
			{23297,42,0}, /* core4 return_Stack4 bit43 */
			{23296,42,1}, /* core4 return_Stack4 bit44 */
			{23295,42,1}, /* core4 return_Stack4 bit45 */
			{23294,42,1}, /* core4 return_Stack4 bit46 */
			{23293,42,1}, /* core4 return_Stack4 bit47 */
			{13709,42,0}, /* core4 return_Stack4 bit48 */
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
			{23348,42,0}, /* core4 return_Stack5 bit0 */
			{23347,42,0}, /* core4 return_Stack5 bit1 */
			{23346,42,0}, /* core4 return_Stack5 bit2 */
			{23196,42,0}, /* core4 return_Stack5 bit3 */
			{23195,42,0}, /* core4 return_Stack5 bit4 */
			{23194,42,0}, /* core4 return_Stack5 bit5 */
			{23193,42,0}, /* core4 return_Stack5 bit6 */
			{23192,42,0}, /* core4 return_Stack5 bit7 */
			{23191,42,0}, /* core4 return_Stack5 bit8 */
			{23190,42,0}, /* core4 return_Stack5 bit9 */
			{23345,42,0}, /* core4 return_Stack5 bit10 */
			{23240,42,0}, /* core4 return_Stack5 bit11 */
			{23239,42,0}, /* core4 return_Stack5 bit12 */
			{23238,42,0}, /* core4 return_Stack5 bit13 */
			{23237,42,0}, /* core4 return_Stack5 bit14 */
			{23188,42,0}, /* core4 return_Stack5 bit15 */
			{23187,42,0}, /* core4 return_Stack5 bit16 */
			{23186,42,0}, /* core4 return_Stack5 bit17 */
			{23185,42,0}, /* core4 return_Stack5 bit18 */
			{23280,42,0}, /* core4 return_Stack5 bit19 */
			{23279,42,0}, /* core4 return_Stack5 bit20 */
			{23278,42,0}, /* core4 return_Stack5 bit21 */
			{23277,42,0}, /* core4 return_Stack5 bit22 */
			{23112,42,1}, /* core4 return_Stack5 bit23 */
			{23111,42,1}, /* core4 return_Stack5 bit24 */
			{23110,42,1}, /* core4 return_Stack5 bit25 */
			{23109,42,1}, /* core4 return_Stack5 bit26 */
			{23120,42,1}, /* core4 return_Stack5 bit27 */
			{23119,42,1}, /* core4 return_Stack5 bit28 */
			{23118,42,1}, /* core4 return_Stack5 bit29 */
			{23117,42,1}, /* core4 return_Stack5 bit30 */
			{13710,42,0}, /* core4 return_Stack5 bit31 */
			{23136,42,0}, /* core4 return_Stack5 bit32 */
			{23135,42,0}, /* core4 return_Stack5 bit33 */
			{23134,42,0}, /* core4 return_Stack5 bit34 */
			{23133,42,0}, /* core4 return_Stack5 bit35 */
			{23248,42,1}, /* core4 return_Stack5 bit36 */
			{23247,42,1}, /* core4 return_Stack5 bit37 */
			{23246,42,1}, /* core4 return_Stack5 bit38 */
			{23245,42,1}, /* core4 return_Stack5 bit39 */
			{23304,42,0}, /* core4 return_Stack5 bit40 */
			{23303,42,0}, /* core4 return_Stack5 bit41 */
			{23302,42,0}, /* core4 return_Stack5 bit42 */
			{23301,42,0}, /* core4 return_Stack5 bit43 */
			{23252,42,1}, /* core4 return_Stack5 bit44 */
			{23251,42,1}, /* core4 return_Stack5 bit45 */
			{23250,42,1}, /* core4 return_Stack5 bit46 */
			{23249,42,1}, /* core4 return_Stack5 bit47 */
			{13704,42,0}, /* core4 return_Stack5 bit48 */
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
			{23324,42,0}, /* core4 return_Stack6 bit0 */
			{23323,42,0}, /* core4 return_Stack6 bit1 */
			{23322,42,0}, /* core4 return_Stack6 bit2 */
			{23208,42,0}, /* core4 return_Stack6 bit3 */
			{23207,42,0}, /* core4 return_Stack6 bit4 */
			{23206,42,0}, /* core4 return_Stack6 bit5 */
			{23205,42,0}, /* core4 return_Stack6 bit6 */
			{23176,42,0}, /* core4 return_Stack6 bit7 */
			{23175,42,0}, /* core4 return_Stack6 bit8 */
			{23174,42,0}, /* core4 return_Stack6 bit9 */
			{23321,42,0}, /* core4 return_Stack6 bit10 */
			{23212,42,0}, /* core4 return_Stack6 bit11 */
			{23211,42,0}, /* core4 return_Stack6 bit12 */
			{23210,42,0}, /* core4 return_Stack6 bit13 */
			{23209,42,0}, /* core4 return_Stack6 bit14 */
			{23164,42,1}, /* core4 return_Stack6 bit15 */
			{23163,42,1}, /* core4 return_Stack6 bit16 */
			{23162,42,1}, /* core4 return_Stack6 bit17 */
			{23161,42,1}, /* core4 return_Stack6 bit18 */
			{23220,42,0}, /* core4 return_Stack6 bit19 */
			{23219,42,0}, /* core4 return_Stack6 bit20 */
			{23218,42,0}, /* core4 return_Stack6 bit21 */
			{23217,42,0}, /* core4 return_Stack6 bit22 */
			{23316,42,1}, /* core4 return_Stack6 bit23 */
			{23315,42,1}, /* core4 return_Stack6 bit24 */
			{23314,42,1}, /* core4 return_Stack6 bit25 */
			{23313,42,1}, /* core4 return_Stack6 bit26 */
			{23132,42,1}, /* core4 return_Stack6 bit27 */
			{23131,42,1}, /* core4 return_Stack6 bit28 */
			{23130,42,1}, /* core4 return_Stack6 bit29 */
			{23129,42,1}, /* core4 return_Stack6 bit30 */
			{13718,42,0}, /* core4 return_Stack6 bit31 */
			{23144,42,0}, /* core4 return_Stack6 bit32 */
			{23143,42,0}, /* core4 return_Stack6 bit33 */
			{23142,42,0}, /* core4 return_Stack6 bit34 */
			{23141,42,0}, /* core4 return_Stack6 bit35 */
			{23276,42,1}, /* core4 return_Stack6 bit36 */
			{23275,42,1}, /* core4 return_Stack6 bit37 */
			{23274,42,1}, /* core4 return_Stack6 bit38 */
			{23273,42,1}, /* core4 return_Stack6 bit39 */
			{23328,42,1}, /* core4 return_Stack6 bit40 */
			{23327,42,1}, /* core4 return_Stack6 bit41 */
			{23326,42,1}, /* core4 return_Stack6 bit42 */
			{23325,42,1}, /* core4 return_Stack6 bit43 */
			{23260,42,1}, /* core4 return_Stack6 bit44 */
			{23259,42,1}, /* core4 return_Stack6 bit45 */
			{23258,42,1}, /* core4 return_Stack6 bit46 */
			{23257,42,1}, /* core4 return_Stack6 bit47 */
			{13719,42,0}, /* core4 return_Stack6 bit48 */
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
			{23336,42,0}, /* core4 return_Stack7 bit0 */
			{23335,42,0}, /* core4 return_Stack7 bit1 */
			{23334,42,0}, /* core4 return_Stack7 bit2 */
			{23200,42,0}, /* core4 return_Stack7 bit3 */
			{23199,42,0}, /* core4 return_Stack7 bit4 */
			{23198,42,0}, /* core4 return_Stack7 bit5 */
			{23197,42,0}, /* core4 return_Stack7 bit6 */
			{23172,42,0}, /* core4 return_Stack7 bit7 */
			{23171,42,0}, /* core4 return_Stack7 bit8 */
			{23170,42,0}, /* core4 return_Stack7 bit9 */
			{23333,42,0}, /* core4 return_Stack7 bit10 */
			{23236,42,0}, /* core4 return_Stack7 bit11 */
			{23235,42,0}, /* core4 return_Stack7 bit12 */
			{23234,42,0}, /* core4 return_Stack7 bit13 */
			{23233,42,0}, /* core4 return_Stack7 bit14 */
			{23156,42,1}, /* core4 return_Stack7 bit15 */
			{23155,42,1}, /* core4 return_Stack7 bit16 */
			{23154,42,1}, /* core4 return_Stack7 bit17 */
			{23153,42,1}, /* core4 return_Stack7 bit18 */
			{23232,42,0}, /* core4 return_Stack7 bit19 */
			{23231,42,0}, /* core4 return_Stack7 bit20 */
			{23230,42,0}, /* core4 return_Stack7 bit21 */
			{23229,42,0}, /* core4 return_Stack7 bit22 */
			{23108,42,1}, /* core4 return_Stack7 bit23 */
			{23107,42,1}, /* core4 return_Stack7 bit24 */
			{23106,42,1}, /* core4 return_Stack7 bit25 */
			{23105,42,1}, /* core4 return_Stack7 bit26 */
			{23035,42,1}, /* core4 return_Stack7 bit27 */
			{23034,42,1}, /* core4 return_Stack7 bit28 */
			{23033,42,1}, /* core4 return_Stack7 bit29 */
			{23032,42,1}, /* core4 return_Stack7 bit30 */
			{13715,42,0}, /* core4 return_Stack7 bit31 */
			{23031,42,1}, /* core4 return_Stack7 bit32 */
			{23030,42,1}, /* core4 return_Stack7 bit33 */
			{23029,42,1}, /* core4 return_Stack7 bit34 */
			{23028,42,1}, /* core4 return_Stack7 bit35 */
			{23023,42,1}, /* core4 return_Stack7 bit36 */
			{23022,42,1}, /* core4 return_Stack7 bit37 */
			{23021,42,1}, /* core4 return_Stack7 bit38 */
			{23020,42,1}, /* core4 return_Stack7 bit39 */
			{23039,42,1}, /* core4 return_Stack7 bit40 */
			{23038,42,1}, /* core4 return_Stack7 bit41 */
			{23037,42,1}, /* core4 return_Stack7 bit42 */
			{23036,42,1}, /* core4 return_Stack7 bit43 */
			{23027,42,1}, /* core4 return_Stack7 bit44 */
			{23026,42,1}, /* core4 return_Stack7 bit45 */
			{23025,42,1}, /* core4 return_Stack7 bit46 */
			{23024,42,1}, /* core4 return_Stack7 bit47 */
			{13716,42,0}, /* core4 return_Stack7 bit48 */
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
			.L2_parity_err = {{
			{ 7910,41,0}, /* core4 L2_parity_err bit0 */
			{    0, 0,2}, /* core4 L2_parity_err bit1 */
			{    0, 0,2}, /* core4 L2_parity_err bit2 */
			{    0, 0,2}, /* core4 L2_parity_err bit3 */
			{    0, 0,2}, /* core4 L2_parity_err bit4 */
			{    0, 0,2}, /* core4 L2_parity_err bit5 */
			{    0, 0,2}, /* core4 L2_parity_err bit6 */
			{    0, 0,2}, /* core4 L2_parity_err bit7 */
			{    0, 0,2}, /* core4 L2_parity_err bit8 */
			{    0, 0,2}, /* core4 L2_parity_err bit9 */
			{    0, 0,2}, /* core4 L2_parity_err bit10 */
			{    0, 0,2}, /* core4 L2_parity_err bit11 */
			{    0, 0,2}, /* core4 L2_parity_err bit12 */
			{    0, 0,2}, /* core4 L2_parity_err bit13 */
			{    0, 0,2}, /* core4 L2_parity_err bit14 */
			{    0, 0,2}, /* core4 L2_parity_err bit15 */
			{    0, 0,2}, /* core4 L2_parity_err bit16 */
			{    0, 0,2}, /* core4 L2_parity_err bit17 */
			{    0, 0,2}, /* core4 L2_parity_err bit18 */
			{    0, 0,2}, /* core4 L2_parity_err bit19 */
			{    0, 0,2}, /* core4 L2_parity_err bit20 */
			{    0, 0,2}, /* core4 L2_parity_err bit21 */
			{    0, 0,2}, /* core4 L2_parity_err bit22 */
			{    0, 0,2}, /* core4 L2_parity_err bit23 */
			{    0, 0,2}, /* core4 L2_parity_err bit24 */
			{    0, 0,2}, /* core4 L2_parity_err bit25 */
			{    0, 0,2}, /* core4 L2_parity_err bit26 */
			{    0, 0,2}, /* core4 L2_parity_err bit27 */
			{    0, 0,2}, /* core4 L2_parity_err bit28 */
			{    0, 0,2}, /* core4 L2_parity_err bit29 */
			{    0, 0,2}, /* core4 L2_parity_err bit30 */
			{    0, 0,2}, /* core4 L2_parity_err bit31 */
			{    0, 0,2}, /* core4 L2_parity_err bit32 */
			{    0, 0,2}, /* core4 L2_parity_err bit33 */
			{    0, 0,2}, /* core4 L2_parity_err bit34 */
			{    0, 0,2}, /* core4 L2_parity_err bit35 */
			{    0, 0,2}, /* core4 L2_parity_err bit36 */
			{    0, 0,2}, /* core4 L2_parity_err bit37 */
			{    0, 0,2}, /* core4 L2_parity_err bit38 */
			{    0, 0,2}, /* core4 L2_parity_err bit39 */
			{    0, 0,2}, /* core4 L2_parity_err bit40 */
			{    0, 0,2}, /* core4 L2_parity_err bit41 */
			{    0, 0,2}, /* core4 L2_parity_err bit42 */
			{    0, 0,2}, /* core4 L2_parity_err bit43 */
			{    0, 0,2}, /* core4 L2_parity_err bit44 */
			{    0, 0,2}, /* core4 L2_parity_err bit45 */
			{    0, 0,2}, /* core4 L2_parity_err bit46 */
			{    0, 0,2}, /* core4 L2_parity_err bit47 */
			{    0, 0,2}, /* core4 L2_parity_err bit48 */
			{    0, 0,2}, /* core4 L2_parity_err bit49 */
			{    0, 0,2}, /* core4 L2_parity_err bit50 */
			{    0, 0,2}, /* core4 L2_parity_err bit51 */
			{    0, 0,2}, /* core4 L2_parity_err bit52 */
			{    0, 0,2}, /* core4 L2_parity_err bit53 */
			{    0, 0,2}, /* core4 L2_parity_err bit54 */
			{    0, 0,2}, /* core4 L2_parity_err bit55 */
			{    0, 0,2}, /* core4 L2_parity_err bit56 */
			{    0, 0,2}, /* core4 L2_parity_err bit57 */
			{    0, 0,2}, /* core4 L2_parity_err bit58 */
			{    0, 0,2}, /* core4 L2_parity_err bit59 */
			{    0, 0,2}, /* core4 L2_parity_err bit60 */
			{    0, 0,2}, /* core4 L2_parity_err bit61 */
			{    0, 0,2}, /* core4 L2_parity_err bit62 */
			{    0, 0,2}, /* core4 L2_parity_err bit63 */
			}},
			.L2_parity_err_count = {{
			{13805,41,1}, /* core4 L2_parity_err_count bit0 */
			{13804,41,1}, /* core4 L2_parity_err_count bit1 */
			{13803,41,1}, /* core4 L2_parity_err_count bit2 */
			{13810,41,0}, /* core4 L2_parity_err_count bit3 */
			{13809,41,0}, /* core4 L2_parity_err_count bit4 */
			{13808,41,0}, /* core4 L2_parity_err_count bit5 */
			{13807,41,0}, /* core4 L2_parity_err_count bit6 */
			{ 7911,41,0}, /* core4 L2_parity_err_count bit7 */
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
			{14288,41,0}, /* core4 L2_parity_index bit0 */
			{14287,41,0}, /* core4 L2_parity_index bit1 */
			{14286,41,0}, /* core4 L2_parity_index bit2 */
			{14285,41,0}, /* core4 L2_parity_index bit3 */
			{14284,41,0}, /* core4 L2_parity_index bit4 */
			{14283,41,0}, /* core4 L2_parity_index bit5 */
			{14282,41,0}, /* core4 L2_parity_index bit6 */
			{14281,41,0}, /* core4 L2_parity_index bit7 */
			{ 7821,41,0}, /* core4 L2_parity_index bit8 */
			{    0, 0,2}, /* core4 L2_parity_index bit9 */
			{    0, 0,2}, /* core4 L2_parity_index bit10 */
			{    0, 0,2}, /* core4 L2_parity_index bit11 */
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
			{10378,41,0}, /* core4 L2_parity_way bit0 */
			{10377,41,0}, /* core4 L2_parity_way bit1 */
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
			{14280,41,0}, /* core4 L2_parity_banks bit0 */
			{14279,41,0}, /* core4 L2_parity_banks bit1 */
			{14278,41,0}, /* core4 L2_parity_banks bit2 */
			{14277,41,0}, /* core4 L2_parity_banks bit3 */
			{14272,41,0}, /* core4 L2_parity_banks bit4 */
			{14271,41,0}, /* core4 L2_parity_banks bit5 */
			{14270,41,0}, /* core4 L2_parity_banks bit6 */
			{14269,41,0}, /* core4 L2_parity_banks bit7 */
			{14292,41,0}, /* core4 L2_parity_banks bit8 */
			{14291,41,0}, /* core4 L2_parity_banks bit9 */
			{14290,41,0}, /* core4 L2_parity_banks bit10 */
			{14289,41,0}, /* core4 L2_parity_banks bit11 */
			{14276,41,0}, /* core4 L2_parity_banks bit12 */
			{14275,41,0}, /* core4 L2_parity_banks bit13 */
			{14274,41,0}, /* core4 L2_parity_banks bit14 */
			{14273,41,0}, /* core4 L2_parity_banks bit15 */
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
			{  192,43,0}, /* core5 pc bit0 */
			{  191,43,0}, /* core5 pc bit1 */
			{  190,43,0}, /* core5 pc bit2 */
			{  189,43,0}, /* core5 pc bit3 */
			{  142,43,0}, /* core5 pc bit4 */
			{  141,43,0}, /* core5 pc bit5 */
			{  140,43,0}, /* core5 pc bit6 */
			{  139,43,0}, /* core5 pc bit7 */
			{  146,43,0}, /* core5 pc bit8 */
			{  145,43,0}, /* core5 pc bit9 */
			{  144,43,0}, /* core5 pc bit10 */
			{  143,43,0}, /* core5 pc bit11 */
			{  150,43,0}, /* core5 pc bit12 */
			{  149,43,0}, /* core5 pc bit13 */
			{  148,43,0}, /* core5 pc bit14 */
			{  147,43,0}, /* core5 pc bit15 */
			{  126,43,0}, /* core5 pc bit16 */
			{  125,43,0}, /* core5 pc bit17 */
			{  124,43,0}, /* core5 pc bit18 */
			{  123,43,0}, /* core5 pc bit19 */
			{  134,43,0}, /* core5 pc bit20 */
			{  133,43,0}, /* core5 pc bit21 */
			{  132,43,0}, /* core5 pc bit22 */
			{  131,43,0}, /* core5 pc bit23 */
			{  138,43,0}, /* core5 pc bit24 */
			{  137,43,0}, /* core5 pc bit25 */
			{  136,43,0}, /* core5 pc bit26 */
			{  135,43,0}, /* core5 pc bit27 */
			{  130,43,0}, /* core5 pc bit28 */
			{  129,43,0}, /* core5 pc bit29 */
			{  128,43,0}, /* core5 pc bit30 */
			{  127,43,0}, /* core5 pc bit31 */
			{  240,43,0}, /* core5 pc bit32 */
			{  239,43,0}, /* core5 pc bit33 */
			{  238,43,0}, /* core5 pc bit34 */
			{  237,43,0}, /* core5 pc bit35 */
			{  248,43,0}, /* core5 pc bit36 */
			{  247,43,0}, /* core5 pc bit37 */
			{  246,43,0}, /* core5 pc bit38 */
			{  245,43,0}, /* core5 pc bit39 */
			{  244,43,0}, /* core5 pc bit40 */
			{  243,43,0}, /* core5 pc bit41 */
			{  242,43,0}, /* core5 pc bit42 */
			{  241,43,0}, /* core5 pc bit43 */
			{  216,43,0}, /* core5 pc bit44 */
			{  215,43,0}, /* core5 pc bit45 */
			{  214,43,0}, /* core5 pc bit46 */
			{  213,43,0}, /* core5 pc bit47 */
			{  180,43,0}, /* core5 pc bit48 */
			{  179,43,0}, /* core5 pc bit49 */
			{  178,43,0}, /* core5 pc bit50 */
			{  177,43,0}, /* core5 pc bit51 */
			{  184,43,0}, /* core5 pc bit52 */
			{  183,43,0}, /* core5 pc bit53 */
			{  182,43,0}, /* core5 pc bit54 */
			{  181,43,0}, /* core5 pc bit55 */
			{  236,43,0}, /* core5 pc bit56 */
			{  235,43,0}, /* core5 pc bit57 */
			{  234,43,0}, /* core5 pc bit58 */
			{  233,43,0}, /* core5 pc bit59 */
			{  188,43,0}, /* core5 pc bit60 */
			{  187,43,0}, /* core5 pc bit61 */
			{  186,43,0}, /* core5 pc bit62 */
			{  185,43,0}, /* core5 pc bit63 */
			}},
			.sp32 = {{
			{41807,44,0}, /* core5 sp32 bit0 */
			{41871,44,0}, /* core5 sp32 bit1 */
			{41806,44,0}, /* core5 sp32 bit2 */
			{41805,44,0}, /* core5 sp32 bit3 */
			{41804,44,0}, /* core5 sp32 bit4 */
			{41855,44,0}, /* core5 sp32 bit5 */
			{41854,44,0}, /* core5 sp32 bit6 */
			{41853,44,0}, /* core5 sp32 bit7 */
			{41852,44,0}, /* core5 sp32 bit8 */
			{41859,44,0}, /* core5 sp32 bit9 */
			{41858,44,0}, /* core5 sp32 bit10 */
			{41857,44,0}, /* core5 sp32 bit11 */
			{41856,44,0}, /* core5 sp32 bit12 */
			{41867,44,0}, /* core5 sp32 bit13 */
			{41866,44,0}, /* core5 sp32 bit14 */
			{41865,44,0}, /* core5 sp32 bit15 */
			{41864,44,0}, /* core5 sp32 bit16 */
			{41679,44,0}, /* core5 sp32 bit17 */
			{41678,44,0}, /* core5 sp32 bit18 */
			{41870,44,0}, /* core5 sp32 bit19 */
			{41677,44,0}, /* core5 sp32 bit20 */
			{41676,44,0}, /* core5 sp32 bit21 */
			{41671,44,0}, /* core5 sp32 bit22 */
			{41670,44,0}, /* core5 sp32 bit23 */
			{41669,44,0}, /* core5 sp32 bit24 */
			{41668,44,0}, /* core5 sp32 bit25 */
			{41869,44,0}, /* core5 sp32 bit26 */
			{41667,44,0}, /* core5 sp32 bit27 */
			{41666,44,0}, /* core5 sp32 bit28 */
			{41665,44,0}, /* core5 sp32 bit29 */
			{41664,44,0}, /* core5 sp32 bit30 */
			{41868,44,0}, /* core5 sp32 bit31 */
			{41483,44,0}, /* core5 sp32 bit32 */
			{41482,44,0}, /* core5 sp32 bit33 */
			{41481,44,0}, /* core5 sp32 bit34 */
			{41480,44,0}, /* core5 sp32 bit35 */
			{36299,44,0}, /* core5 sp32 bit36 */
			{28101,44,0}, /* core5 sp32 bit37 */
			{36298,44,0}, /* core5 sp32 bit38 */
			{41535,44,0}, /* core5 sp32 bit39 */
			{41534,44,0}, /* core5 sp32 bit40 */
			{41533,44,0}, /* core5 sp32 bit41 */
			{41532,44,0}, /* core5 sp32 bit42 */
			{41479,44,0}, /* core5 sp32 bit43 */
			{41478,44,0}, /* core5 sp32 bit44 */
			{41477,44,0}, /* core5 sp32 bit45 */
			{41476,44,0}, /* core5 sp32 bit46 */
			{36277,44,0}, /* core5 sp32 bit47 */
			{36276,44,0}, /* core5 sp32 bit48 */
			{41531,44,0}, /* core5 sp32 bit49 */
			{41530,44,0}, /* core5 sp32 bit50 */
			{41529,44,0}, /* core5 sp32 bit51 */
			{41528,44,0}, /* core5 sp32 bit52 */
			{41523,44,0}, /* core5 sp32 bit53 */
			{41522,44,0}, /* core5 sp32 bit54 */
			{41521,44,0}, /* core5 sp32 bit55 */
			{41520,44,0}, /* core5 sp32 bit56 */
			{41527,44,0}, /* core5 sp32 bit57 */
			{41526,44,0}, /* core5 sp32 bit58 */
			{41525,44,0}, /* core5 sp32 bit59 */
			{41524,44,0}, /* core5 sp32 bit60 */
			{41519,44,0}, /* core5 sp32 bit61 */
			{41518,44,0}, /* core5 sp32 bit62 */
			{41517,44,0}, /* core5 sp32 bit63 */
			}},
			.fp32 = {{
			{42038,44,0}, /* core5 fp32 bit0 */
			{42037,44,0}, /* core5 fp32 bit1 */
			{42021,44,0}, /* core5 fp32 bit2 */
			{42020,44,0}, /* core5 fp32 bit3 */
			{42036,44,0}, /* core5 fp32 bit4 */
			{42043,44,0}, /* core5 fp32 bit5 */
			{42042,44,0}, /* core5 fp32 bit6 */
			{42041,44,0}, /* core5 fp32 bit7 */
			{42040,44,0}, /* core5 fp32 bit8 */
			{42027,44,0}, /* core5 fp32 bit9 */
			{42031,44,0}, /* core5 fp32 bit10 */
			{42030,44,0}, /* core5 fp32 bit11 */
			{42029,44,0}, /* core5 fp32 bit12 */
			{42028,44,0}, /* core5 fp32 bit13 */
			{42015,44,0}, /* core5 fp32 bit14 */
			{42014,44,0}, /* core5 fp32 bit15 */
			{42026,44,0}, /* core5 fp32 bit16 */
			{42013,44,0}, /* core5 fp32 bit17 */
			{42035,44,0}, /* core5 fp32 bit18 */
			{42034,44,0}, /* core5 fp32 bit19 */
			{42033,44,0}, /* core5 fp32 bit20 */
			{42012,44,0}, /* core5 fp32 bit21 */
			{42019,44,0}, /* core5 fp32 bit22 */
			{42018,44,0}, /* core5 fp32 bit23 */
			{42017,44,0}, /* core5 fp32 bit24 */
			{42032,44,0}, /* core5 fp32 bit25 */
			{42016,44,0}, /* core5 fp32 bit26 */
			{42023,44,0}, /* core5 fp32 bit27 */
			{42025,44,0}, /* core5 fp32 bit28 */
			{42022,44,0}, /* core5 fp32 bit29 */
			{42024,44,0}, /* core5 fp32 bit30 */
			{42039,44,0}, /* core5 fp32 bit31 */
			{42143,44,0}, /* core5 fp32 bit32 */
			{42142,44,0}, /* core5 fp32 bit33 */
			{42141,44,0}, /* core5 fp32 bit34 */
			{42140,44,0}, /* core5 fp32 bit35 */
			{42135,44,0}, /* core5 fp32 bit36 */
			{42134,44,0}, /* core5 fp32 bit37 */
			{42133,44,0}, /* core5 fp32 bit38 */
			{42132,44,0}, /* core5 fp32 bit39 */
			{42131,44,0}, /* core5 fp32 bit40 */
			{42130,44,0}, /* core5 fp32 bit41 */
			{42129,44,0}, /* core5 fp32 bit42 */
			{42128,44,0}, /* core5 fp32 bit43 */
			{42139,44,0}, /* core5 fp32 bit44 */
			{42138,44,0}, /* core5 fp32 bit45 */
			{42137,44,0}, /* core5 fp32 bit46 */
			{42136,44,0}, /* core5 fp32 bit47 */
			{28149,44,0}, /* core5 fp32 bit48 */
			{42151,44,0}, /* core5 fp32 bit49 */
			{42150,44,0}, /* core5 fp32 bit50 */
			{42149,44,0}, /* core5 fp32 bit51 */
			{42148,44,0}, /* core5 fp32 bit52 */
			{42155,44,0}, /* core5 fp32 bit53 */
			{42154,44,0}, /* core5 fp32 bit54 */
			{42153,44,0}, /* core5 fp32 bit55 */
			{42152,44,0}, /* core5 fp32 bit56 */
			{42147,44,0}, /* core5 fp32 bit57 */
			{42146,44,0}, /* core5 fp32 bit58 */
			{42145,44,0}, /* core5 fp32 bit59 */
			{42144,44,0}, /* core5 fp32 bit60 */
			{42159,44,0}, /* core5 fp32 bit61 */
			{42158,44,0}, /* core5 fp32 bit62 */
			{42157,44,0}, /* core5 fp32 bit63 */
			}},
			.fp64 = {{
			{40979,44,0}, /* core5 fp64 bit0 */
			{40978,44,0}, /* core5 fp64 bit1 */
			{28248,44,0}, /* core5 fp64 bit2 */
			{40999,44,0}, /* core5 fp64 bit3 */
			{36342,44,0}, /* core5 fp64 bit4 */
			{40977,44,0}, /* core5 fp64 bit5 */
			{40970,44,0}, /* core5 fp64 bit6 */
			{40976,44,0}, /* core5 fp64 bit7 */
			{40969,44,0}, /* core5 fp64 bit8 */
			{40968,44,0}, /* core5 fp64 bit9 */
			{40975,44,0}, /* core5 fp64 bit10 */
			{40974,44,0}, /* core5 fp64 bit11 */
			{40987,44,0}, /* core5 fp64 bit12 */
			{40986,44,0}, /* core5 fp64 bit13 */
			{40985,44,0}, /* core5 fp64 bit14 */
			{40973,44,0}, /* core5 fp64 bit15 */
			{40998,44,0}, /* core5 fp64 bit16 */
			{40997,44,0}, /* core5 fp64 bit17 */
			{40996,44,0}, /* core5 fp64 bit18 */
			{36343,44,0}, /* core5 fp64 bit19 */
			{40995,44,0}, /* core5 fp64 bit20 */
			{40972,44,0}, /* core5 fp64 bit21 */
			{40984,44,0}, /* core5 fp64 bit22 */
			{40983,44,0}, /* core5 fp64 bit23 */
			{28249,44,0}, /* core5 fp64 bit24 */
			{40982,44,0}, /* core5 fp64 bit25 */
			{40994,44,0}, /* core5 fp64 bit26 */
			{40981,44,0}, /* core5 fp64 bit27 */
			{40993,44,0}, /* core5 fp64 bit28 */
			{40992,44,0}, /* core5 fp64 bit29 */
			{40980,44,0}, /* core5 fp64 bit30 */
			{40971,44,0}, /* core5 fp64 bit31 */
			{41143,44,0}, /* core5 fp64 bit32 */
			{41142,44,0}, /* core5 fp64 bit33 */
			{41141,44,0}, /* core5 fp64 bit34 */
			{28127,44,0}, /* core5 fp64 bit35 */
			{41140,44,0}, /* core5 fp64 bit36 */
			{36435,44,0}, /* core5 fp64 bit37 */
			{41151,44,0}, /* core5 fp64 bit38 */
			{41150,44,0}, /* core5 fp64 bit39 */
			{41149,44,0}, /* core5 fp64 bit40 */
			{41148,44,0}, /* core5 fp64 bit41 */
			{41147,44,0}, /* core5 fp64 bit42 */
			{41146,44,0}, /* core5 fp64 bit43 */
			{41145,44,0}, /* core5 fp64 bit44 */
			{28114,44,0}, /* core5 fp64 bit45 */
			{36434,44,0}, /* core5 fp64 bit46 */
			{41144,44,0}, /* core5 fp64 bit47 */
			{28132,44,0}, /* core5 fp64 bit48 */
			{36455,44,0}, /* core5 fp64 bit49 */
			{41119,44,0}, /* core5 fp64 bit50 */
			{41118,44,0}, /* core5 fp64 bit51 */
			{41117,44,0}, /* core5 fp64 bit52 */
			{36454,44,0}, /* core5 fp64 bit53 */
			{41116,44,0}, /* core5 fp64 bit54 */
			{41135,44,0}, /* core5 fp64 bit55 */
			{41134,44,0}, /* core5 fp64 bit56 */
			{41133,44,0}, /* core5 fp64 bit57 */
			{41132,44,0}, /* core5 fp64 bit58 */
			{28131,44,0}, /* core5 fp64 bit59 */
			{41115,44,0}, /* core5 fp64 bit60 */
			{41114,44,0}, /* core5 fp64 bit61 */
			{41113,44,0}, /* core5 fp64 bit62 */
			{41112,44,0}, /* core5 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40942,44,0}, /* core5 sp_EL0 bit0 */
			{40941,44,0}, /* core5 sp_EL0 bit1 */
			{40940,44,0}, /* core5 sp_EL0 bit2 */
			{41010,44,0}, /* core5 sp_EL0 bit3 */
			{41009,44,0}, /* core5 sp_EL0 bit4 */
			{40939,44,0}, /* core5 sp_EL0 bit5 */
			{40938,44,0}, /* core5 sp_EL0 bit6 */
			{40937,44,0}, /* core5 sp_EL0 bit7 */
			{40936,44,0}, /* core5 sp_EL0 bit8 */
			{40931,44,0}, /* core5 sp_EL0 bit9 */
			{40947,44,0}, /* core5 sp_EL0 bit10 */
			{40930,44,0}, /* core5 sp_EL0 bit11 */
			{40929,44,0}, /* core5 sp_EL0 bit12 */
			{40928,44,0}, /* core5 sp_EL0 bit13 */
			{40951,44,0}, /* core5 sp_EL0 bit14 */
			{40950,44,0}, /* core5 sp_EL0 bit15 */
			{41008,44,0}, /* core5 sp_EL0 bit16 */
			{41015,44,0}, /* core5 sp_EL0 bit17 */
			{41014,44,0}, /* core5 sp_EL0 bit18 */
			{41011,44,0}, /* core5 sp_EL0 bit19 */
			{41013,44,0}, /* core5 sp_EL0 bit20 */
			{40946,44,0}, /* core5 sp_EL0 bit21 */
			{40949,44,0}, /* core5 sp_EL0 bit22 */
			{40945,44,0}, /* core5 sp_EL0 bit23 */
			{28259,44,0}, /* core5 sp_EL0 bit24 */
			{40944,44,0}, /* core5 sp_EL0 bit25 */
			{41012,44,0}, /* core5 sp_EL0 bit26 */
			{36257,44,0}, /* core5 sp_EL0 bit27 */
			{36347,44,0}, /* core5 sp_EL0 bit28 */
			{36346,44,0}, /* core5 sp_EL0 bit29 */
			{36256,44,0}, /* core5 sp_EL0 bit30 */
			{40943,44,0}, /* core5 sp_EL0 bit31 */
			{41063,44,0}, /* core5 sp_EL0 bit32 */
			{41059,44,0}, /* core5 sp_EL0 bit33 */
			{41058,44,0}, /* core5 sp_EL0 bit34 */
			{41062,44,0}, /* core5 sp_EL0 bit35 */
			{41061,44,0}, /* core5 sp_EL0 bit36 */
			{41057,44,0}, /* core5 sp_EL0 bit37 */
			{41060,44,0}, /* core5 sp_EL0 bit38 */
			{41071,44,0}, /* core5 sp_EL0 bit39 */
			{41070,44,0}, /* core5 sp_EL0 bit40 */
			{41069,44,0}, /* core5 sp_EL0 bit41 */
			{41056,44,0}, /* core5 sp_EL0 bit42 */
			{41068,44,0}, /* core5 sp_EL0 bit43 */
			{41067,44,0}, /* core5 sp_EL0 bit44 */
			{41066,44,0}, /* core5 sp_EL0 bit45 */
			{41065,44,0}, /* core5 sp_EL0 bit46 */
			{41064,44,0}, /* core5 sp_EL0 bit47 */
			{28157,44,0}, /* core5 sp_EL0 bit48 */
			{41103,44,0}, /* core5 sp_EL0 bit49 */
			{41102,44,0}, /* core5 sp_EL0 bit50 */
			{41101,44,0}, /* core5 sp_EL0 bit51 */
			{41100,44,0}, /* core5 sp_EL0 bit52 */
			{41107,44,0}, /* core5 sp_EL0 bit53 */
			{41106,44,0}, /* core5 sp_EL0 bit54 */
			{41105,44,0}, /* core5 sp_EL0 bit55 */
			{41104,44,0}, /* core5 sp_EL0 bit56 */
			{41055,44,0}, /* core5 sp_EL0 bit57 */
			{41054,44,0}, /* core5 sp_EL0 bit58 */
			{41053,44,0}, /* core5 sp_EL0 bit59 */
			{41052,44,0}, /* core5 sp_EL0 bit60 */
			{41111,44,0}, /* core5 sp_EL0 bit61 */
			{41110,44,0}, /* core5 sp_EL0 bit62 */
			{41109,44,0}, /* core5 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40935,44,0}, /* core5 sp_EL1 bit0 */
			{40934,44,0}, /* core5 sp_EL1 bit1 */
			{40902,44,0}, /* core5 sp_EL1 bit2 */
			{40882,44,0}, /* core5 sp_EL1 bit3 */
			{40881,44,0}, /* core5 sp_EL1 bit4 */
			{40933,44,0}, /* core5 sp_EL1 bit5 */
			{40901,44,0}, /* core5 sp_EL1 bit6 */
			{40932,44,0}, /* core5 sp_EL1 bit7 */
			{40900,44,0}, /* core5 sp_EL1 bit8 */
			{40927,44,0}, /* core5 sp_EL1 bit9 */
			{40926,44,0}, /* core5 sp_EL1 bit10 */
			{40923,44,0}, /* core5 sp_EL1 bit11 */
			{40922,44,0}, /* core5 sp_EL1 bit12 */
			{40921,44,0}, /* core5 sp_EL1 bit13 */
			{40920,44,0}, /* core5 sp_EL1 bit14 */
			{40925,44,0}, /* core5 sp_EL1 bit15 */
			{40880,44,0}, /* core5 sp_EL1 bit16 */
			{40879,44,0}, /* core5 sp_EL1 bit17 */
			{40878,44,0}, /* core5 sp_EL1 bit18 */
			{36259,44,0}, /* core5 sp_EL1 bit19 */
			{40877,44,0}, /* core5 sp_EL1 bit20 */
			{40924,44,0}, /* core5 sp_EL1 bit21 */
			{28258,44,0}, /* core5 sp_EL1 bit22 */
			{40899,44,0}, /* core5 sp_EL1 bit23 */
			{36258,44,0}, /* core5 sp_EL1 bit24 */
			{40898,44,0}, /* core5 sp_EL1 bit25 */
			{40883,44,0}, /* core5 sp_EL1 bit26 */
			{40897,44,0}, /* core5 sp_EL1 bit27 */
			{40876,44,0}, /* core5 sp_EL1 bit28 */
			{28244,44,0}, /* core5 sp_EL1 bit29 */
			{40896,44,0}, /* core5 sp_EL1 bit30 */
			{40903,44,0}, /* core5 sp_EL1 bit31 */
			{40803,44,0}, /* core5 sp_EL1 bit32 */
			{40799,44,0}, /* core5 sp_EL1 bit33 */
			{40798,44,0}, /* core5 sp_EL1 bit34 */
			{40802,44,0}, /* core5 sp_EL1 bit35 */
			{40801,44,0}, /* core5 sp_EL1 bit36 */
			{40797,44,0}, /* core5 sp_EL1 bit37 */
			{40800,44,0}, /* core5 sp_EL1 bit38 */
			{40791,44,0}, /* core5 sp_EL1 bit39 */
			{40790,44,0}, /* core5 sp_EL1 bit40 */
			{40789,44,0}, /* core5 sp_EL1 bit41 */
			{40796,44,0}, /* core5 sp_EL1 bit42 */
			{40788,44,0}, /* core5 sp_EL1 bit43 */
			{40795,44,0}, /* core5 sp_EL1 bit44 */
			{40794,44,0}, /* core5 sp_EL1 bit45 */
			{40792,44,0}, /* core5 sp_EL1 bit46 */
			{40793,44,0}, /* core5 sp_EL1 bit47 */
			{28158,44,0}, /* core5 sp_EL1 bit48 */
			{36423,44,0}, /* core5 sp_EL1 bit49 */
			{40839,44,0}, /* core5 sp_EL1 bit50 */
			{40838,44,0}, /* core5 sp_EL1 bit51 */
			{40837,44,0}, /* core5 sp_EL1 bit52 */
			{36422,44,0}, /* core5 sp_EL1 bit53 */
			{40836,44,0}, /* core5 sp_EL1 bit54 */
			{40831,44,0}, /* core5 sp_EL1 bit55 */
			{40830,44,0}, /* core5 sp_EL1 bit56 */
			{40829,44,0}, /* core5 sp_EL1 bit57 */
			{40828,44,0}, /* core5 sp_EL1 bit58 */
			{28159,44,0}, /* core5 sp_EL1 bit59 */
			{40835,44,0}, /* core5 sp_EL1 bit60 */
			{40834,44,0}, /* core5 sp_EL1 bit61 */
			{40833,44,0}, /* core5 sp_EL1 bit62 */
			{40832,44,0}, /* core5 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40906,44,0}, /* core5 sp_EL2 bit0 */
			{40905,44,0}, /* core5 sp_EL2 bit1 */
			{40904,44,0}, /* core5 sp_EL2 bit2 */
			{40886,44,0}, /* core5 sp_EL2 bit3 */
			{40891,44,0}, /* core5 sp_EL2 bit4 */
			{40911,44,0}, /* core5 sp_EL2 bit5 */
			{40910,44,0}, /* core5 sp_EL2 bit6 */
			{40909,44,0}, /* core5 sp_EL2 bit7 */
			{40908,44,0}, /* core5 sp_EL2 bit8 */
			{40919,44,0}, /* core5 sp_EL2 bit9 */
			{40915,44,0}, /* core5 sp_EL2 bit10 */
			{40918,44,0}, /* core5 sp_EL2 bit11 */
			{40917,44,0}, /* core5 sp_EL2 bit12 */
			{40916,44,0}, /* core5 sp_EL2 bit13 */
			{40895,44,0}, /* core5 sp_EL2 bit14 */
			{40894,44,0}, /* core5 sp_EL2 bit15 */
			{40885,44,0}, /* core5 sp_EL2 bit16 */
			{40884,44,0}, /* core5 sp_EL2 bit17 */
			{40890,44,0}, /* core5 sp_EL2 bit18 */
			{28260,44,0}, /* core5 sp_EL2 bit19 */
			{40889,44,0}, /* core5 sp_EL2 bit20 */
			{40914,44,0}, /* core5 sp_EL2 bit21 */
			{40893,44,0}, /* core5 sp_EL2 bit22 */
			{40913,44,0}, /* core5 sp_EL2 bit23 */
			{40888,44,0}, /* core5 sp_EL2 bit24 */
			{40912,44,0}, /* core5 sp_EL2 bit25 */
			{40887,44,0}, /* core5 sp_EL2 bit26 */
			{36261,44,0}, /* core5 sp_EL2 bit27 */
			{36255,44,0}, /* core5 sp_EL2 bit28 */
			{36254,44,0}, /* core5 sp_EL2 bit29 */
			{36260,44,0}, /* core5 sp_EL2 bit30 */
			{40907,44,0}, /* core5 sp_EL2 bit31 */
			{40811,44,0}, /* core5 sp_EL2 bit32 */
			{40810,44,0}, /* core5 sp_EL2 bit33 */
			{40809,44,0}, /* core5 sp_EL2 bit34 */
			{40808,44,0}, /* core5 sp_EL2 bit35 */
			{40783,44,0}, /* core5 sp_EL2 bit36 */
			{40782,44,0}, /* core5 sp_EL2 bit37 */
			{40781,44,0}, /* core5 sp_EL2 bit38 */
			{40780,44,0}, /* core5 sp_EL2 bit39 */
			{40787,44,0}, /* core5 sp_EL2 bit40 */
			{40786,44,0}, /* core5 sp_EL2 bit41 */
			{40785,44,0}, /* core5 sp_EL2 bit42 */
			{40784,44,0}, /* core5 sp_EL2 bit43 */
			{40755,44,0}, /* core5 sp_EL2 bit44 */
			{40754,44,0}, /* core5 sp_EL2 bit45 */
			{40752,44,0}, /* core5 sp_EL2 bit46 */
			{40753,44,0}, /* core5 sp_EL2 bit47 */
			{28170,44,0}, /* core5 sp_EL2 bit48 */
			{28161,44,0}, /* core5 sp_EL2 bit49 */
			{40847,44,0}, /* core5 sp_EL2 bit50 */
			{40846,44,0}, /* core5 sp_EL2 bit51 */
			{40845,44,0}, /* core5 sp_EL2 bit52 */
			{40844,44,0}, /* core5 sp_EL2 bit53 */
			{40843,44,0}, /* core5 sp_EL2 bit54 */
			{40842,44,0}, /* core5 sp_EL2 bit55 */
			{40841,44,0}, /* core5 sp_EL2 bit56 */
			{40840,44,0}, /* core5 sp_EL2 bit57 */
			{40815,44,0}, /* core5 sp_EL2 bit58 */
			{40814,44,0}, /* core5 sp_EL2 bit59 */
			{40813,44,0}, /* core5 sp_EL2 bit60 */
			{40812,44,0}, /* core5 sp_EL2 bit61 */
			{36421,44,0}, /* core5 sp_EL2 bit62 */
			{36420,44,0}, /* core5 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40861,44,0}, /* core5 sp_EL3 bit0 */
			{40860,44,0}, /* core5 sp_EL3 bit1 */
			{40739,44,0}, /* core5 sp_EL3 bit2 */
			{40875,44,0}, /* core5 sp_EL3 bit3 */
			{40874,44,0}, /* core5 sp_EL3 bit4 */
			{40738,44,0}, /* core5 sp_EL3 bit5 */
			{40737,44,0}, /* core5 sp_EL3 bit6 */
			{40736,44,0}, /* core5 sp_EL3 bit7 */
			{40867,44,0}, /* core5 sp_EL3 bit8 */
			{40866,44,0}, /* core5 sp_EL3 bit9 */
			{40865,44,0}, /* core5 sp_EL3 bit10 */
			{40864,44,0}, /* core5 sp_EL3 bit11 */
			{40743,44,0}, /* core5 sp_EL3 bit12 */
			{40742,44,0}, /* core5 sp_EL3 bit13 */
			{40741,44,0}, /* core5 sp_EL3 bit14 */
			{40740,44,0}, /* core5 sp_EL3 bit15 */
			{40873,44,0}, /* core5 sp_EL3 bit16 */
			{40872,44,0}, /* core5 sp_EL3 bit17 */
			{40871,44,0}, /* core5 sp_EL3 bit18 */
			{40863,44,0}, /* core5 sp_EL3 bit19 */
			{40870,44,0}, /* core5 sp_EL3 bit20 */
			{40735,44,0}, /* core5 sp_EL3 bit21 */
			{40734,44,0}, /* core5 sp_EL3 bit22 */
			{40733,44,0}, /* core5 sp_EL3 bit23 */
			{28185,44,0}, /* core5 sp_EL3 bit24 */
			{40732,44,0}, /* core5 sp_EL3 bit25 */
			{40869,44,0}, /* core5 sp_EL3 bit26 */
			{36251,44,0}, /* core5 sp_EL3 bit27 */
			{40868,44,0}, /* core5 sp_EL3 bit28 */
			{28186,44,0}, /* core5 sp_EL3 bit29 */
			{36250,44,0}, /* core5 sp_EL3 bit30 */
			{40862,44,0}, /* core5 sp_EL3 bit31 */
			{40807,44,0}, /* core5 sp_EL3 bit32 */
			{40806,44,0}, /* core5 sp_EL3 bit33 */
			{40805,44,0}, /* core5 sp_EL3 bit34 */
			{40804,44,0}, /* core5 sp_EL3 bit35 */
			{40763,44,0}, /* core5 sp_EL3 bit36 */
			{40762,44,0}, /* core5 sp_EL3 bit37 */
			{40761,44,0}, /* core5 sp_EL3 bit38 */
			{40760,44,0}, /* core5 sp_EL3 bit39 */
			{40767,44,0}, /* core5 sp_EL3 bit40 */
			{40766,44,0}, /* core5 sp_EL3 bit41 */
			{40765,44,0}, /* core5 sp_EL3 bit42 */
			{40764,44,0}, /* core5 sp_EL3 bit43 */
			{40759,44,0}, /* core5 sp_EL3 bit44 */
			{40758,44,0}, /* core5 sp_EL3 bit45 */
			{40756,44,0}, /* core5 sp_EL3 bit46 */
			{40757,44,0}, /* core5 sp_EL3 bit47 */
			{28172,44,0}, /* core5 sp_EL3 bit48 */
			{36425,44,0}, /* core5 sp_EL3 bit49 */
			{40827,44,0}, /* core5 sp_EL3 bit50 */
			{40826,44,0}, /* core5 sp_EL3 bit51 */
			{40825,44,0}, /* core5 sp_EL3 bit52 */
			{40824,44,0}, /* core5 sp_EL3 bit53 */
			{40823,44,0}, /* core5 sp_EL3 bit54 */
			{40822,44,0}, /* core5 sp_EL3 bit55 */
			{40821,44,0}, /* core5 sp_EL3 bit56 */
			{40820,44,0}, /* core5 sp_EL3 bit57 */
			{40819,44,0}, /* core5 sp_EL3 bit58 */
			{36424,44,0}, /* core5 sp_EL3 bit59 */
			{40818,44,0}, /* core5 sp_EL3 bit60 */
			{40817,44,0}, /* core5 sp_EL3 bit61 */
			{40816,44,0}, /* core5 sp_EL3 bit62 */
			{28160,44,0}, /* core5 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{40707,44,0}, /* core5 elr_EL1 bit0 */
			{40706,44,0}, /* core5 elr_EL1 bit1 */
			{40705,44,0}, /* core5 elr_EL1 bit2 */
			{40723,44,0}, /* core5 elr_EL1 bit3 */
			{40722,44,0}, /* core5 elr_EL1 bit4 */
			{40704,44,0}, /* core5 elr_EL1 bit5 */
			{40703,44,0}, /* core5 elr_EL1 bit6 */
			{40702,44,0}, /* core5 elr_EL1 bit7 */
			{40701,44,0}, /* core5 elr_EL1 bit8 */
			{40700,44,0}, /* core5 elr_EL1 bit9 */
			{40695,44,0}, /* core5 elr_EL1 bit10 */
			{40694,44,0}, /* core5 elr_EL1 bit11 */
			{40693,44,0}, /* core5 elr_EL1 bit12 */
			{40692,44,0}, /* core5 elr_EL1 bit13 */
			{40699,44,0}, /* core5 elr_EL1 bit14 */
			{40698,44,0}, /* core5 elr_EL1 bit15 */
			{40721,44,0}, /* core5 elr_EL1 bit16 */
			{40720,44,0}, /* core5 elr_EL1 bit17 */
			{40727,44,0}, /* core5 elr_EL1 bit18 */
			{40697,44,0}, /* core5 elr_EL1 bit19 */
			{40726,44,0}, /* core5 elr_EL1 bit20 */
			{40696,44,0}, /* core5 elr_EL1 bit21 */
			{40715,44,0}, /* core5 elr_EL1 bit22 */
			{40714,44,0}, /* core5 elr_EL1 bit23 */
			{28252,44,0}, /* core5 elr_EL1 bit24 */
			{40713,44,0}, /* core5 elr_EL1 bit25 */
			{40725,44,0}, /* core5 elr_EL1 bit26 */
			{40712,44,0}, /* core5 elr_EL1 bit27 */
			{40724,44,0}, /* core5 elr_EL1 bit28 */
			{28251,44,0}, /* core5 elr_EL1 bit29 */
			{36265,44,0}, /* core5 elr_EL1 bit30 */
			{36264,44,0}, /* core5 elr_EL1 bit31 */
			{40751,44,0}, /* core5 elr_EL1 bit32 */
			{40750,44,0}, /* core5 elr_EL1 bit33 */
			{40749,44,0}, /* core5 elr_EL1 bit34 */
			{40748,44,0}, /* core5 elr_EL1 bit35 */
			{40771,44,0}, /* core5 elr_EL1 bit36 */
			{40770,44,0}, /* core5 elr_EL1 bit37 */
			{40769,44,0}, /* core5 elr_EL1 bit38 */
			{40768,44,0}, /* core5 elr_EL1 bit39 */
			{40775,44,0}, /* core5 elr_EL1 bit40 */
			{40774,44,0}, /* core5 elr_EL1 bit41 */
			{40773,44,0}, /* core5 elr_EL1 bit42 */
			{40772,44,0}, /* core5 elr_EL1 bit43 */
			{40779,44,0}, /* core5 elr_EL1 bit44 */
			{40778,44,0}, /* core5 elr_EL1 bit45 */
			{40777,44,0}, /* core5 elr_EL1 bit46 */
			{40776,44,0}, /* core5 elr_EL1 bit47 */
			{28165,44,0}, /* core5 elr_EL1 bit48 */
			{40859,44,0}, /* core5 elr_EL1 bit49 */
			{40858,44,0}, /* core5 elr_EL1 bit50 */
			{40857,44,0}, /* core5 elr_EL1 bit51 */
			{40856,44,0}, /* core5 elr_EL1 bit52 */
			{40855,44,0}, /* core5 elr_EL1 bit53 */
			{40854,44,0}, /* core5 elr_EL1 bit54 */
			{40853,44,0}, /* core5 elr_EL1 bit55 */
			{40852,44,0}, /* core5 elr_EL1 bit56 */
			{40747,44,0}, /* core5 elr_EL1 bit57 */
			{40746,44,0}, /* core5 elr_EL1 bit58 */
			{40745,44,0}, /* core5 elr_EL1 bit59 */
			{40744,44,0}, /* core5 elr_EL1 bit60 */
			{40851,44,0}, /* core5 elr_EL1 bit61 */
			{40850,44,0}, /* core5 elr_EL1 bit62 */
			{40849,44,0}, /* core5 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{40711,44,0}, /* core5 elr_EL2 bit0 */
			{40710,44,0}, /* core5 elr_EL2 bit1 */
			{40709,44,0}, /* core5 elr_EL2 bit2 */
			{40719,44,0}, /* core5 elr_EL2 bit3 */
			{40718,44,0}, /* core5 elr_EL2 bit4 */
			{40708,44,0}, /* core5 elr_EL2 bit5 */
			{40687,44,0}, /* core5 elr_EL2 bit6 */
			{40691,44,0}, /* core5 elr_EL2 bit7 */
			{40690,44,0}, /* core5 elr_EL2 bit8 */
			{40689,44,0}, /* core5 elr_EL2 bit9 */
			{40686,44,0}, /* core5 elr_EL2 bit10 */
			{40688,44,0}, /* core5 elr_EL2 bit11 */
			{40683,44,0}, /* core5 elr_EL2 bit12 */
			{40682,44,0}, /* core5 elr_EL2 bit13 */
			{40681,44,0}, /* core5 elr_EL2 bit14 */
			{40685,44,0}, /* core5 elr_EL2 bit15 */
			{40717,44,0}, /* core5 elr_EL2 bit16 */
			{40716,44,0}, /* core5 elr_EL2 bit17 */
			{40731,44,0}, /* core5 elr_EL2 bit18 */
			{40684,44,0}, /* core5 elr_EL2 bit19 */
			{40730,44,0}, /* core5 elr_EL2 bit20 */
			{40679,44,0}, /* core5 elr_EL2 bit21 */
			{40680,44,0}, /* core5 elr_EL2 bit22 */
			{40678,44,0}, /* core5 elr_EL2 bit23 */
			{28253,44,0}, /* core5 elr_EL2 bit24 */
			{40677,44,0}, /* core5 elr_EL2 bit25 */
			{40729,44,0}, /* core5 elr_EL2 bit26 */
			{40676,44,0}, /* core5 elr_EL2 bit27 */
			{40728,44,0}, /* core5 elr_EL2 bit28 */
			{28254,44,0}, /* core5 elr_EL2 bit29 */
			{28255,44,0}, /* core5 elr_EL2 bit30 */
			{28256,44,0}, /* core5 elr_EL2 bit31 */
			{40501,44,0}, /* core5 elr_EL2 bit32 */
			{40500,44,0}, /* core5 elr_EL2 bit33 */
			{40499,44,0}, /* core5 elr_EL2 bit34 */
			{40498,44,0}, /* core5 elr_EL2 bit35 */
			{40481,44,0}, /* core5 elr_EL2 bit36 */
			{40480,44,0}, /* core5 elr_EL2 bit37 */
			{40479,44,0}, /* core5 elr_EL2 bit38 */
			{40478,44,0}, /* core5 elr_EL2 bit39 */
			{40477,44,0}, /* core5 elr_EL2 bit40 */
			{40476,44,0}, /* core5 elr_EL2 bit41 */
			{40475,44,0}, /* core5 elr_EL2 bit42 */
			{40474,44,0}, /* core5 elr_EL2 bit43 */
			{40485,44,0}, /* core5 elr_EL2 bit44 */
			{40484,44,0}, /* core5 elr_EL2 bit45 */
			{40483,44,0}, /* core5 elr_EL2 bit46 */
			{40482,44,0}, /* core5 elr_EL2 bit47 */
			{28164,44,0}, /* core5 elr_EL2 bit48 */
			{40509,44,0}, /* core5 elr_EL2 bit49 */
			{40508,44,0}, /* core5 elr_EL2 bit50 */
			{40507,44,0}, /* core5 elr_EL2 bit51 */
			{40506,44,0}, /* core5 elr_EL2 bit52 */
			{40465,44,0}, /* core5 elr_EL2 bit53 */
			{40464,44,0}, /* core5 elr_EL2 bit54 */
			{40463,44,0}, /* core5 elr_EL2 bit55 */
			{40462,44,0}, /* core5 elr_EL2 bit56 */
			{40473,44,0}, /* core5 elr_EL2 bit57 */
			{40472,44,0}, /* core5 elr_EL2 bit58 */
			{40471,44,0}, /* core5 elr_EL2 bit59 */
			{40470,44,0}, /* core5 elr_EL2 bit60 */
			{40469,44,0}, /* core5 elr_EL2 bit61 */
			{40468,44,0}, /* core5 elr_EL2 bit62 */
			{40467,44,0}, /* core5 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{40452,44,0}, /* core5 elr_EL3 bit0 */
			{40451,44,0}, /* core5 elr_EL3 bit1 */
			{40450,44,0}, /* core5 elr_EL3 bit2 */
			{40437,44,0}, /* core5 elr_EL3 bit3 */
			{40436,44,0}, /* core5 elr_EL3 bit4 */
			{40441,44,0}, /* core5 elr_EL3 bit5 */
			{40440,44,0}, /* core5 elr_EL3 bit6 */
			{40439,44,0}, /* core5 elr_EL3 bit7 */
			{40438,44,0}, /* core5 elr_EL3 bit8 */
			{40449,44,0}, /* core5 elr_EL3 bit9 */
			{40448,44,0}, /* core5 elr_EL3 bit10 */
			{40447,44,0}, /* core5 elr_EL3 bit11 */
			{40446,44,0}, /* core5 elr_EL3 bit12 */
			{40457,44,0}, /* core5 elr_EL3 bit13 */
			{40456,44,0}, /* core5 elr_EL3 bit14 */
			{40455,44,0}, /* core5 elr_EL3 bit15 */
			{40435,44,0}, /* core5 elr_EL3 bit16 */
			{40434,44,0}, /* core5 elr_EL3 bit17 */
			{40461,44,0}, /* core5 elr_EL3 bit18 */
			{40445,44,0}, /* core5 elr_EL3 bit19 */
			{40460,44,0}, /* core5 elr_EL3 bit20 */
			{40444,44,0}, /* core5 elr_EL3 bit21 */
			{40454,44,0}, /* core5 elr_EL3 bit22 */
			{40443,44,0}, /* core5 elr_EL3 bit23 */
			{28245,44,0}, /* core5 elr_EL3 bit24 */
			{40442,44,0}, /* core5 elr_EL3 bit25 */
			{40459,44,0}, /* core5 elr_EL3 bit26 */
			{36263,44,0}, /* core5 elr_EL3 bit27 */
			{40458,44,0}, /* core5 elr_EL3 bit28 */
			{28246,44,0}, /* core5 elr_EL3 bit29 */
			{36262,44,0}, /* core5 elr_EL3 bit30 */
			{40453,44,0}, /* core5 elr_EL3 bit31 */
			{40505,44,0}, /* core5 elr_EL3 bit32 */
			{40504,44,0}, /* core5 elr_EL3 bit33 */
			{40503,44,0}, /* core5 elr_EL3 bit34 */
			{40493,44,0}, /* core5 elr_EL3 bit35 */
			{40492,44,0}, /* core5 elr_EL3 bit36 */
			{40502,44,0}, /* core5 elr_EL3 bit37 */
			{40491,44,0}, /* core5 elr_EL3 bit38 */
			{40490,44,0}, /* core5 elr_EL3 bit39 */
			{40489,44,0}, /* core5 elr_EL3 bit40 */
			{40488,44,0}, /* core5 elr_EL3 bit41 */
			{40497,44,0}, /* core5 elr_EL3 bit42 */
			{40487,44,0}, /* core5 elr_EL3 bit43 */
			{40496,44,0}, /* core5 elr_EL3 bit44 */
			{40495,44,0}, /* core5 elr_EL3 bit45 */
			{36215,44,0}, /* core5 elr_EL3 bit46 */
			{40494,44,0}, /* core5 elr_EL3 bit47 */
			{36214,44,0}, /* core5 elr_EL3 bit48 */
			{40517,44,0}, /* core5 elr_EL3 bit49 */
			{40516,44,0}, /* core5 elr_EL3 bit50 */
			{40515,44,0}, /* core5 elr_EL3 bit51 */
			{40514,44,0}, /* core5 elr_EL3 bit52 */
			{40521,44,0}, /* core5 elr_EL3 bit53 */
			{40520,44,0}, /* core5 elr_EL3 bit54 */
			{40519,44,0}, /* core5 elr_EL3 bit55 */
			{40518,44,0}, /* core5 elr_EL3 bit56 */
			{40513,44,0}, /* core5 elr_EL3 bit57 */
			{40512,44,0}, /* core5 elr_EL3 bit58 */
			{40511,44,0}, /* core5 elr_EL3 bit59 */
			{40510,44,0}, /* core5 elr_EL3 bit60 */
			{40433,44,0}, /* core5 elr_EL3 bit61 */
			{40432,44,0}, /* core5 elr_EL3 bit62 */
			{40431,44,0}, /* core5 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{30898,44,0}, /* core5 raw_pc bit0 */
			{33534,43,0}, /* core5 raw_pc bit1 */
			{33533,43,0}, /* core5 raw_pc bit2 */
			{33532,43,0}, /* core5 raw_pc bit3 */
			{33531,43,0}, /* core5 raw_pc bit4 */
			{37455,44,0}, /* core5 raw_pc bit5 */
			{37454,44,0}, /* core5 raw_pc bit6 */
			{37453,44,0}, /* core5 raw_pc bit7 */
			{37452,44,0}, /* core5 raw_pc bit8 */
			{37451,44,0}, /* core5 raw_pc bit9 */
			{37450,44,0}, /* core5 raw_pc bit10 */
			{37447,44,0}, /* core5 raw_pc bit11 */
			{37446,44,0}, /* core5 raw_pc bit12 */
			{37449,44,0}, /* core5 raw_pc bit13 */
			{37448,44,0}, /* core5 raw_pc bit14 */
			{33538,43,0}, /* core5 raw_pc bit15 */
			{33537,43,0}, /* core5 raw_pc bit16 */
			{33536,43,0}, /* core5 raw_pc bit17 */
			{33535,43,0}, /* core5 raw_pc bit18 */
			{33542,43,0}, /* core5 raw_pc bit19 */
			{33541,43,0}, /* core5 raw_pc bit20 */
			{33540,43,0}, /* core5 raw_pc bit21 */
			{33539,43,0}, /* core5 raw_pc bit22 */
			{33546,43,0}, /* core5 raw_pc bit23 */
			{33545,43,0}, /* core5 raw_pc bit24 */
			{33544,43,0}, /* core5 raw_pc bit25 */
			{33543,43,0}, /* core5 raw_pc bit26 */
			{33482,43,0}, /* core5 raw_pc bit27 */
			{33481,43,0}, /* core5 raw_pc bit28 */
			{33480,43,0}, /* core5 raw_pc bit29 */
			{33479,43,0}, /* core5 raw_pc bit30 */
			{33606,43,0}, /* core5 raw_pc bit31 */
			{33605,43,0}, /* core5 raw_pc bit32 */
			{33604,43,0}, /* core5 raw_pc bit33 */
			{33603,43,0}, /* core5 raw_pc bit34 */
			{37245,44,0}, /* core5 raw_pc bit35 */
			{37244,44,0}, /* core5 raw_pc bit36 */
			{37249,44,0}, /* core5 raw_pc bit37 */
			{37248,44,0}, /* core5 raw_pc bit38 */
			{33602,43,0}, /* core5 raw_pc bit39 */
			{33601,43,0}, /* core5 raw_pc bit40 */
			{33600,43,0}, /* core5 raw_pc bit41 */
			{33599,43,0}, /* core5 raw_pc bit42 */
			{37247,44,0}, /* core5 raw_pc bit43 */
			{37246,44,0}, /* core5 raw_pc bit44 */
			{37251,44,0}, /* core5 raw_pc bit45 */
			{37250,44,0}, /* core5 raw_pc bit46 */
			{33598,43,0}, /* core5 raw_pc bit47 */
			{33597,43,0}, /* core5 raw_pc bit48 */
			{33596,43,0}, /* core5 raw_pc bit49 */
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
			{33491,43,0}, /* core5 pc_iss bit0 */
			{33498,43,0}, /* core5 pc_iss bit1 */
			{33497,43,0}, /* core5 pc_iss bit2 */
			{33496,43,0}, /* core5 pc_iss bit3 */
			{33495,43,0}, /* core5 pc_iss bit4 */
			{33494,43,0}, /* core5 pc_iss bit5 */
			{33493,43,0}, /* core5 pc_iss bit6 */
			{33492,43,0}, /* core5 pc_iss bit7 */
			{33522,43,0}, /* core5 pc_iss bit8 */
			{33521,43,0}, /* core5 pc_iss bit9 */
			{33520,43,0}, /* core5 pc_iss bit10 */
			{33519,43,0}, /* core5 pc_iss bit11 */
			{33470,43,0}, /* core5 pc_iss bit12 */
			{33469,43,0}, /* core5 pc_iss bit13 */
			{33468,43,0}, /* core5 pc_iss bit14 */
			{33467,43,0}, /* core5 pc_iss bit15 */
			{33526,43,0}, /* core5 pc_iss bit16 */
			{33525,43,0}, /* core5 pc_iss bit17 */
			{33524,43,0}, /* core5 pc_iss bit18 */
			{33523,43,0}, /* core5 pc_iss bit19 */
			{33530,43,0}, /* core5 pc_iss bit20 */
			{33529,43,0}, /* core5 pc_iss bit21 */
			{33528,43,0}, /* core5 pc_iss bit22 */
			{33527,43,0}, /* core5 pc_iss bit23 */
			{33474,43,0}, /* core5 pc_iss bit24 */
			{33473,43,0}, /* core5 pc_iss bit25 */
			{33472,43,0}, /* core5 pc_iss bit26 */
			{33471,43,0}, /* core5 pc_iss bit27 */
			{33478,43,0}, /* core5 pc_iss bit28 */
			{33477,43,0}, /* core5 pc_iss bit29 */
			{33476,43,0}, /* core5 pc_iss bit30 */
			{33475,43,0}, /* core5 pc_iss bit31 */
			{33631,43,0}, /* core5 pc_iss bit32 */
			{33618,43,0}, /* core5 pc_iss bit33 */
			{33617,43,0}, /* core5 pc_iss bit34 */
			{33616,43,0}, /* core5 pc_iss bit35 */
			{33621,43,0}, /* core5 pc_iss bit36 */
			{33615,43,0}, /* core5 pc_iss bit37 */
			{33620,43,0}, /* core5 pc_iss bit38 */
			{33619,43,0}, /* core5 pc_iss bit39 */
			{33614,43,0}, /* core5 pc_iss bit40 */
			{33613,43,0}, /* core5 pc_iss bit41 */
			{33610,43,0}, /* core5 pc_iss bit42 */
			{33612,43,0}, /* core5 pc_iss bit43 */
			{33611,43,0}, /* core5 pc_iss bit44 */
			{33630,43,0}, /* core5 pc_iss bit45 */
			{33629,43,0}, /* core5 pc_iss bit46 */
			{33609,43,0}, /* core5 pc_iss bit47 */
			{33628,43,0}, /* core5 pc_iss bit48 */
			{33627,43,0}, /* core5 pc_iss bit49 */
			{33626,43,0}, /* core5 pc_iss bit50 */
			{33625,43,0}, /* core5 pc_iss bit51 */
			{33624,43,0}, /* core5 pc_iss bit52 */
			{33622,43,0}, /* core5 pc_iss bit53 */
			{33623,43,0}, /* core5 pc_iss bit54 */
			{33634,43,0}, /* core5 pc_iss bit55 */
			{33633,43,0}, /* core5 pc_iss bit56 */
			{33632,43,0}, /* core5 pc_iss bit57 */
			{33608,43,0}, /* core5 pc_iss bit58 */
			{33607,43,0}, /* core5 pc_iss bit59 */
			{33638,43,0}, /* core5 pc_iss bit60 */
			{33637,43,0}, /* core5 pc_iss bit61 */
			{33636,43,0}, /* core5 pc_iss bit62 */
			{33635,43,0}, /* core5 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{30897,44,0}, /* core5 full_pc_wr bit0 */
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
			{30971,44,0}, /* core5 full_pc_ex1 bit0 */
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
			{30942,44,0}, /* core5 full_pc_ex2 bit0 */
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
			{16598,44,0}, /* core5 return_Stack_pointer bit0 */
			{16597,44,0}, /* core5 return_Stack_pointer bit1 */
			{13720,44,0}, /* core5 return_Stack_pointer bit2 */
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
			{23469,44,0}, /* core5 return_Stack0 bit0 */
			{23468,44,0}, /* core5 return_Stack0 bit1 */
			{23467,44,0}, /* core5 return_Stack0 bit2 */
			{23449,44,0}, /* core5 return_Stack0 bit3 */
			{23448,44,0}, /* core5 return_Stack0 bit4 */
			{23447,44,0}, /* core5 return_Stack0 bit5 */
			{23446,44,0}, /* core5 return_Stack0 bit6 */
			{23365,44,0}, /* core5 return_Stack0 bit7 */
			{23364,44,0}, /* core5 return_Stack0 bit8 */
			{23363,44,0}, /* core5 return_Stack0 bit9 */
			{23466,44,0}, /* core5 return_Stack0 bit10 */
			{23417,44,0}, /* core5 return_Stack0 bit11 */
			{23416,44,0}, /* core5 return_Stack0 bit12 */
			{23415,44,0}, /* core5 return_Stack0 bit13 */
			{23414,44,0}, /* core5 return_Stack0 bit14 */
			{23369,44,0}, /* core5 return_Stack0 bit15 */
			{23368,44,0}, /* core5 return_Stack0 bit16 */
			{23367,44,0}, /* core5 return_Stack0 bit17 */
			{23366,44,0}, /* core5 return_Stack0 bit18 */
			{23421,44,0}, /* core5 return_Stack0 bit19 */
			{23420,44,0}, /* core5 return_Stack0 bit20 */
			{23419,44,0}, /* core5 return_Stack0 bit21 */
			{23418,44,0}, /* core5 return_Stack0 bit22 */
			{23465,44,1}, /* core5 return_Stack0 bit23 */
			{23464,44,1}, /* core5 return_Stack0 bit24 */
			{23463,44,1}, /* core5 return_Stack0 bit25 */
			{23462,44,1}, /* core5 return_Stack0 bit26 */
			{23385,44,1}, /* core5 return_Stack0 bit27 */
			{23384,44,1}, /* core5 return_Stack0 bit28 */
			{23383,44,1}, /* core5 return_Stack0 bit29 */
			{23382,44,1}, /* core5 return_Stack0 bit30 */
			{13706,44,0}, /* core5 return_Stack0 bit31 */
			{23381,44,0}, /* core5 return_Stack0 bit32 */
			{23380,44,0}, /* core5 return_Stack0 bit33 */
			{23379,44,0}, /* core5 return_Stack0 bit34 */
			{23378,44,0}, /* core5 return_Stack0 bit35 */
			{23413,44,1}, /* core5 return_Stack0 bit36 */
			{23412,44,1}, /* core5 return_Stack0 bit37 */
			{23411,44,1}, /* core5 return_Stack0 bit38 */
			{23410,44,1}, /* core5 return_Stack0 bit39 */
			{23405,44,0}, /* core5 return_Stack0 bit40 */
			{23404,44,0}, /* core5 return_Stack0 bit41 */
			{23403,44,0}, /* core5 return_Stack0 bit42 */
			{23402,44,0}, /* core5 return_Stack0 bit43 */
			{23409,44,1}, /* core5 return_Stack0 bit44 */
			{23408,44,1}, /* core5 return_Stack0 bit45 */
			{23407,44,1}, /* core5 return_Stack0 bit46 */
			{23406,44,1}, /* core5 return_Stack0 bit47 */
			{13707,44,0}, /* core5 return_Stack0 bit48 */
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
			{23461,44,0}, /* core5 return_Stack1 bit0 */
			{23460,44,0}, /* core5 return_Stack1 bit1 */
			{23459,44,0}, /* core5 return_Stack1 bit2 */
			{23445,44,0}, /* core5 return_Stack1 bit3 */
			{23444,44,0}, /* core5 return_Stack1 bit4 */
			{23443,44,0}, /* core5 return_Stack1 bit5 */
			{23442,44,0}, /* core5 return_Stack1 bit6 */
			{23441,44,0}, /* core5 return_Stack1 bit7 */
			{23440,44,0}, /* core5 return_Stack1 bit8 */
			{23439,44,0}, /* core5 return_Stack1 bit9 */
			{23458,44,0}, /* core5 return_Stack1 bit10 */
			{23425,44,0}, /* core5 return_Stack1 bit11 */
			{23424,44,0}, /* core5 return_Stack1 bit12 */
			{23423,44,0}, /* core5 return_Stack1 bit13 */
			{23422,44,0}, /* core5 return_Stack1 bit14 */
			{23373,44,0}, /* core5 return_Stack1 bit15 */
			{23372,44,0}, /* core5 return_Stack1 bit16 */
			{23371,44,0}, /* core5 return_Stack1 bit17 */
			{23370,44,0}, /* core5 return_Stack1 bit18 */
			{23429,44,0}, /* core5 return_Stack1 bit19 */
			{23428,44,0}, /* core5 return_Stack1 bit20 */
			{23427,44,0}, /* core5 return_Stack1 bit21 */
			{23426,44,0}, /* core5 return_Stack1 bit22 */
			{23393,44,1}, /* core5 return_Stack1 bit23 */
			{23392,44,1}, /* core5 return_Stack1 bit24 */
			{23391,44,1}, /* core5 return_Stack1 bit25 */
			{23390,44,1}, /* core5 return_Stack1 bit26 */
			{23389,44,1}, /* core5 return_Stack1 bit27 */
			{23388,44,1}, /* core5 return_Stack1 bit28 */
			{23387,44,1}, /* core5 return_Stack1 bit29 */
			{23386,44,1}, /* core5 return_Stack1 bit30 */
			{13711,44,0}, /* core5 return_Stack1 bit31 */
			{23377,44,0}, /* core5 return_Stack1 bit32 */
			{23376,44,0}, /* core5 return_Stack1 bit33 */
			{23375,44,0}, /* core5 return_Stack1 bit34 */
			{23374,44,0}, /* core5 return_Stack1 bit35 */
			{23453,44,1}, /* core5 return_Stack1 bit36 */
			{23452,44,1}, /* core5 return_Stack1 bit37 */
			{23451,44,1}, /* core5 return_Stack1 bit38 */
			{23450,44,1}, /* core5 return_Stack1 bit39 */
			{23401,44,0}, /* core5 return_Stack1 bit40 */
			{23400,44,0}, /* core5 return_Stack1 bit41 */
			{23399,44,0}, /* core5 return_Stack1 bit42 */
			{23398,44,0}, /* core5 return_Stack1 bit43 */
			{23457,44,1}, /* core5 return_Stack1 bit44 */
			{23456,44,1}, /* core5 return_Stack1 bit45 */
			{23455,44,1}, /* core5 return_Stack1 bit46 */
			{23454,44,1}, /* core5 return_Stack1 bit47 */
			{13705,44,0}, /* core5 return_Stack1 bit48 */
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
			{23397,44,0}, /* core5 return_Stack2 bit0 */
			{23396,44,0}, /* core5 return_Stack2 bit1 */
			{23395,44,0}, /* core5 return_Stack2 bit2 */
			{23437,44,0}, /* core5 return_Stack2 bit3 */
			{23436,44,0}, /* core5 return_Stack2 bit4 */
			{23435,44,0}, /* core5 return_Stack2 bit5 */
			{23434,44,0}, /* core5 return_Stack2 bit6 */
			{23361,44,0}, /* core5 return_Stack2 bit7 */
			{23360,44,0}, /* core5 return_Stack2 bit8 */
			{23359,44,0}, /* core5 return_Stack2 bit9 */
			{23394,44,0}, /* core5 return_Stack2 bit10 */
			{23433,44,0}, /* core5 return_Stack2 bit11 */
			{23432,44,0}, /* core5 return_Stack2 bit12 */
			{23431,44,0}, /* core5 return_Stack2 bit13 */
			{23430,44,0}, /* core5 return_Stack2 bit14 */
			{23357,44,1}, /* core5 return_Stack2 bit15 */
			{23356,44,1}, /* core5 return_Stack2 bit16 */
			{23355,44,1}, /* core5 return_Stack2 bit17 */
			{23354,44,1}, /* core5 return_Stack2 bit18 */
			{23216,44,0}, /* core5 return_Stack2 bit19 */
			{23215,44,0}, /* core5 return_Stack2 bit20 */
			{23214,44,0}, /* core5 return_Stack2 bit21 */
			{23213,44,0}, /* core5 return_Stack2 bit22 */
			{23312,44,1}, /* core5 return_Stack2 bit23 */
			{23311,44,1}, /* core5 return_Stack2 bit24 */
			{23310,44,1}, /* core5 return_Stack2 bit25 */
			{23309,44,1}, /* core5 return_Stack2 bit26 */
			{23128,44,1}, /* core5 return_Stack2 bit27 */
			{23127,44,1}, /* core5 return_Stack2 bit28 */
			{23126,44,1}, /* core5 return_Stack2 bit29 */
			{23125,44,1}, /* core5 return_Stack2 bit30 */
			{13712,44,0}, /* core5 return_Stack2 bit31 */
			{23152,44,1}, /* core5 return_Stack2 bit32 */
			{23151,44,1}, /* core5 return_Stack2 bit33 */
			{23150,44,1}, /* core5 return_Stack2 bit34 */
			{23149,44,1}, /* core5 return_Stack2 bit35 */
			{23244,44,1}, /* core5 return_Stack2 bit36 */
			{23243,44,1}, /* core5 return_Stack2 bit37 */
			{23242,44,1}, /* core5 return_Stack2 bit38 */
			{23241,44,1}, /* core5 return_Stack2 bit39 */
			{23308,44,1}, /* core5 return_Stack2 bit40 */
			{23307,44,1}, /* core5 return_Stack2 bit41 */
			{23306,44,1}, /* core5 return_Stack2 bit42 */
			{23305,44,1}, /* core5 return_Stack2 bit43 */
			{23256,44,1}, /* core5 return_Stack2 bit44 */
			{23255,44,1}, /* core5 return_Stack2 bit45 */
			{23254,44,1}, /* core5 return_Stack2 bit46 */
			{23253,44,1}, /* core5 return_Stack2 bit47 */
			{13713,44,0}, /* core5 return_Stack2 bit48 */
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
			{23332,44,0}, /* core5 return_Stack3 bit0 */
			{23331,44,0}, /* core5 return_Stack3 bit1 */
			{23330,44,0}, /* core5 return_Stack3 bit2 */
			{23204,44,0}, /* core5 return_Stack3 bit3 */
			{23203,44,0}, /* core5 return_Stack3 bit4 */
			{23202,44,0}, /* core5 return_Stack3 bit5 */
			{23201,44,0}, /* core5 return_Stack3 bit6 */
			{23168,44,0}, /* core5 return_Stack3 bit7 */
			{23167,44,0}, /* core5 return_Stack3 bit8 */
			{23166,44,0}, /* core5 return_Stack3 bit9 */
			{23329,44,0}, /* core5 return_Stack3 bit10 */
			{23228,44,0}, /* core5 return_Stack3 bit11 */
			{23227,44,0}, /* core5 return_Stack3 bit12 */
			{23226,44,0}, /* core5 return_Stack3 bit13 */
			{23225,44,0}, /* core5 return_Stack3 bit14 */
			{23160,44,1}, /* core5 return_Stack3 bit15 */
			{23159,44,1}, /* core5 return_Stack3 bit16 */
			{23158,44,1}, /* core5 return_Stack3 bit17 */
			{23157,44,1}, /* core5 return_Stack3 bit18 */
			{23224,44,0}, /* core5 return_Stack3 bit19 */
			{23223,44,0}, /* core5 return_Stack3 bit20 */
			{23222,44,0}, /* core5 return_Stack3 bit21 */
			{23221,44,0}, /* core5 return_Stack3 bit22 */
			{23340,44,1}, /* core5 return_Stack3 bit23 */
			{23339,44,1}, /* core5 return_Stack3 bit24 */
			{23338,44,1}, /* core5 return_Stack3 bit25 */
			{23337,44,1}, /* core5 return_Stack3 bit26 */
			{23124,44,1}, /* core5 return_Stack3 bit27 */
			{23123,44,1}, /* core5 return_Stack3 bit28 */
			{23122,44,1}, /* core5 return_Stack3 bit29 */
			{23121,44,1}, /* core5 return_Stack3 bit30 */
			{13714,44,0}, /* core5 return_Stack3 bit31 */
			{23148,44,1}, /* core5 return_Stack3 bit32 */
			{23147,44,1}, /* core5 return_Stack3 bit33 */
			{23146,44,1}, /* core5 return_Stack3 bit34 */
			{23145,44,1}, /* core5 return_Stack3 bit35 */
			{23272,44,1}, /* core5 return_Stack3 bit36 */
			{23271,44,1}, /* core5 return_Stack3 bit37 */
			{23270,44,1}, /* core5 return_Stack3 bit38 */
			{23269,44,1}, /* core5 return_Stack3 bit39 */
			{23320,44,1}, /* core5 return_Stack3 bit40 */
			{23319,44,1}, /* core5 return_Stack3 bit41 */
			{23318,44,1}, /* core5 return_Stack3 bit42 */
			{23317,44,1}, /* core5 return_Stack3 bit43 */
			{23264,44,1}, /* core5 return_Stack3 bit44 */
			{23263,44,1}, /* core5 return_Stack3 bit45 */
			{23262,44,1}, /* core5 return_Stack3 bit46 */
			{23261,44,1}, /* core5 return_Stack3 bit47 */
			{13717,44,0}, /* core5 return_Stack3 bit48 */
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
			{23352,44,0}, /* core5 return_Stack4 bit0 */
			{23351,44,0}, /* core5 return_Stack4 bit1 */
			{23350,44,0}, /* core5 return_Stack4 bit2 */
			{23268,44,0}, /* core5 return_Stack4 bit3 */
			{23267,44,0}, /* core5 return_Stack4 bit4 */
			{23266,44,0}, /* core5 return_Stack4 bit5 */
			{23265,44,0}, /* core5 return_Stack4 bit6 */
			{23180,44,0}, /* core5 return_Stack4 bit7 */
			{23179,44,0}, /* core5 return_Stack4 bit8 */
			{23178,44,0}, /* core5 return_Stack4 bit9 */
			{23349,44,0}, /* core5 return_Stack4 bit10 */
			{23288,44,0}, /* core5 return_Stack4 bit11 */
			{23287,44,0}, /* core5 return_Stack4 bit12 */
			{23286,44,0}, /* core5 return_Stack4 bit13 */
			{23285,44,0}, /* core5 return_Stack4 bit14 */
			{23184,44,0}, /* core5 return_Stack4 bit15 */
			{23183,44,0}, /* core5 return_Stack4 bit16 */
			{23182,44,0}, /* core5 return_Stack4 bit17 */
			{23181,44,0}, /* core5 return_Stack4 bit18 */
			{23284,44,0}, /* core5 return_Stack4 bit19 */
			{23283,44,0}, /* core5 return_Stack4 bit20 */
			{23282,44,0}, /* core5 return_Stack4 bit21 */
			{23281,44,0}, /* core5 return_Stack4 bit22 */
			{23344,44,1}, /* core5 return_Stack4 bit23 */
			{23343,44,1}, /* core5 return_Stack4 bit24 */
			{23342,44,1}, /* core5 return_Stack4 bit25 */
			{23341,44,1}, /* core5 return_Stack4 bit26 */
			{23116,44,1}, /* core5 return_Stack4 bit27 */
			{23115,44,1}, /* core5 return_Stack4 bit28 */
			{23114,44,1}, /* core5 return_Stack4 bit29 */
			{23113,44,1}, /* core5 return_Stack4 bit30 */
			{13708,44,0}, /* core5 return_Stack4 bit31 */
			{23140,44,0}, /* core5 return_Stack4 bit32 */
			{23139,44,0}, /* core5 return_Stack4 bit33 */
			{23138,44,0}, /* core5 return_Stack4 bit34 */
			{23137,44,0}, /* core5 return_Stack4 bit35 */
			{23292,44,1}, /* core5 return_Stack4 bit36 */
			{23291,44,1}, /* core5 return_Stack4 bit37 */
			{23290,44,1}, /* core5 return_Stack4 bit38 */
			{23289,44,1}, /* core5 return_Stack4 bit39 */
			{23300,44,0}, /* core5 return_Stack4 bit40 */
			{23299,44,0}, /* core5 return_Stack4 bit41 */
			{23298,44,0}, /* core5 return_Stack4 bit42 */
			{23297,44,0}, /* core5 return_Stack4 bit43 */
			{23296,44,1}, /* core5 return_Stack4 bit44 */
			{23295,44,1}, /* core5 return_Stack4 bit45 */
			{23294,44,1}, /* core5 return_Stack4 bit46 */
			{23293,44,1}, /* core5 return_Stack4 bit47 */
			{13709,44,0}, /* core5 return_Stack4 bit48 */
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
			{23348,44,0}, /* core5 return_Stack5 bit0 */
			{23347,44,0}, /* core5 return_Stack5 bit1 */
			{23346,44,0}, /* core5 return_Stack5 bit2 */
			{23196,44,0}, /* core5 return_Stack5 bit3 */
			{23195,44,0}, /* core5 return_Stack5 bit4 */
			{23194,44,0}, /* core5 return_Stack5 bit5 */
			{23193,44,0}, /* core5 return_Stack5 bit6 */
			{23192,44,0}, /* core5 return_Stack5 bit7 */
			{23191,44,0}, /* core5 return_Stack5 bit8 */
			{23190,44,0}, /* core5 return_Stack5 bit9 */
			{23345,44,0}, /* core5 return_Stack5 bit10 */
			{23240,44,0}, /* core5 return_Stack5 bit11 */
			{23239,44,0}, /* core5 return_Stack5 bit12 */
			{23238,44,0}, /* core5 return_Stack5 bit13 */
			{23237,44,0}, /* core5 return_Stack5 bit14 */
			{23188,44,0}, /* core5 return_Stack5 bit15 */
			{23187,44,0}, /* core5 return_Stack5 bit16 */
			{23186,44,0}, /* core5 return_Stack5 bit17 */
			{23185,44,0}, /* core5 return_Stack5 bit18 */
			{23280,44,0}, /* core5 return_Stack5 bit19 */
			{23279,44,0}, /* core5 return_Stack5 bit20 */
			{23278,44,0}, /* core5 return_Stack5 bit21 */
			{23277,44,0}, /* core5 return_Stack5 bit22 */
			{23112,44,1}, /* core5 return_Stack5 bit23 */
			{23111,44,1}, /* core5 return_Stack5 bit24 */
			{23110,44,1}, /* core5 return_Stack5 bit25 */
			{23109,44,1}, /* core5 return_Stack5 bit26 */
			{23120,44,1}, /* core5 return_Stack5 bit27 */
			{23119,44,1}, /* core5 return_Stack5 bit28 */
			{23118,44,1}, /* core5 return_Stack5 bit29 */
			{23117,44,1}, /* core5 return_Stack5 bit30 */
			{13710,44,0}, /* core5 return_Stack5 bit31 */
			{23136,44,0}, /* core5 return_Stack5 bit32 */
			{23135,44,0}, /* core5 return_Stack5 bit33 */
			{23134,44,0}, /* core5 return_Stack5 bit34 */
			{23133,44,0}, /* core5 return_Stack5 bit35 */
			{23248,44,1}, /* core5 return_Stack5 bit36 */
			{23247,44,1}, /* core5 return_Stack5 bit37 */
			{23246,44,1}, /* core5 return_Stack5 bit38 */
			{23245,44,1}, /* core5 return_Stack5 bit39 */
			{23304,44,0}, /* core5 return_Stack5 bit40 */
			{23303,44,0}, /* core5 return_Stack5 bit41 */
			{23302,44,0}, /* core5 return_Stack5 bit42 */
			{23301,44,0}, /* core5 return_Stack5 bit43 */
			{23252,44,1}, /* core5 return_Stack5 bit44 */
			{23251,44,1}, /* core5 return_Stack5 bit45 */
			{23250,44,1}, /* core5 return_Stack5 bit46 */
			{23249,44,1}, /* core5 return_Stack5 bit47 */
			{13704,44,0}, /* core5 return_Stack5 bit48 */
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
			{23324,44,0}, /* core5 return_Stack6 bit0 */
			{23323,44,0}, /* core5 return_Stack6 bit1 */
			{23322,44,0}, /* core5 return_Stack6 bit2 */
			{23208,44,0}, /* core5 return_Stack6 bit3 */
			{23207,44,0}, /* core5 return_Stack6 bit4 */
			{23206,44,0}, /* core5 return_Stack6 bit5 */
			{23205,44,0}, /* core5 return_Stack6 bit6 */
			{23176,44,0}, /* core5 return_Stack6 bit7 */
			{23175,44,0}, /* core5 return_Stack6 bit8 */
			{23174,44,0}, /* core5 return_Stack6 bit9 */
			{23321,44,0}, /* core5 return_Stack6 bit10 */
			{23212,44,0}, /* core5 return_Stack6 bit11 */
			{23211,44,0}, /* core5 return_Stack6 bit12 */
			{23210,44,0}, /* core5 return_Stack6 bit13 */
			{23209,44,0}, /* core5 return_Stack6 bit14 */
			{23164,44,1}, /* core5 return_Stack6 bit15 */
			{23163,44,1}, /* core5 return_Stack6 bit16 */
			{23162,44,1}, /* core5 return_Stack6 bit17 */
			{23161,44,1}, /* core5 return_Stack6 bit18 */
			{23220,44,0}, /* core5 return_Stack6 bit19 */
			{23219,44,0}, /* core5 return_Stack6 bit20 */
			{23218,44,0}, /* core5 return_Stack6 bit21 */
			{23217,44,0}, /* core5 return_Stack6 bit22 */
			{23316,44,1}, /* core5 return_Stack6 bit23 */
			{23315,44,1}, /* core5 return_Stack6 bit24 */
			{23314,44,1}, /* core5 return_Stack6 bit25 */
			{23313,44,1}, /* core5 return_Stack6 bit26 */
			{23132,44,1}, /* core5 return_Stack6 bit27 */
			{23131,44,1}, /* core5 return_Stack6 bit28 */
			{23130,44,1}, /* core5 return_Stack6 bit29 */
			{23129,44,1}, /* core5 return_Stack6 bit30 */
			{13718,44,0}, /* core5 return_Stack6 bit31 */
			{23144,44,0}, /* core5 return_Stack6 bit32 */
			{23143,44,0}, /* core5 return_Stack6 bit33 */
			{23142,44,0}, /* core5 return_Stack6 bit34 */
			{23141,44,0}, /* core5 return_Stack6 bit35 */
			{23276,44,1}, /* core5 return_Stack6 bit36 */
			{23275,44,1}, /* core5 return_Stack6 bit37 */
			{23274,44,1}, /* core5 return_Stack6 bit38 */
			{23273,44,1}, /* core5 return_Stack6 bit39 */
			{23328,44,1}, /* core5 return_Stack6 bit40 */
			{23327,44,1}, /* core5 return_Stack6 bit41 */
			{23326,44,1}, /* core5 return_Stack6 bit42 */
			{23325,44,1}, /* core5 return_Stack6 bit43 */
			{23260,44,1}, /* core5 return_Stack6 bit44 */
			{23259,44,1}, /* core5 return_Stack6 bit45 */
			{23258,44,1}, /* core5 return_Stack6 bit46 */
			{23257,44,1}, /* core5 return_Stack6 bit47 */
			{13719,44,0}, /* core5 return_Stack6 bit48 */
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
			{23336,44,0}, /* core5 return_Stack7 bit0 */
			{23335,44,0}, /* core5 return_Stack7 bit1 */
			{23334,44,0}, /* core5 return_Stack7 bit2 */
			{23200,44,0}, /* core5 return_Stack7 bit3 */
			{23199,44,0}, /* core5 return_Stack7 bit4 */
			{23198,44,0}, /* core5 return_Stack7 bit5 */
			{23197,44,0}, /* core5 return_Stack7 bit6 */
			{23172,44,0}, /* core5 return_Stack7 bit7 */
			{23171,44,0}, /* core5 return_Stack7 bit8 */
			{23170,44,0}, /* core5 return_Stack7 bit9 */
			{23333,44,0}, /* core5 return_Stack7 bit10 */
			{23236,44,0}, /* core5 return_Stack7 bit11 */
			{23235,44,0}, /* core5 return_Stack7 bit12 */
			{23234,44,0}, /* core5 return_Stack7 bit13 */
			{23233,44,0}, /* core5 return_Stack7 bit14 */
			{23156,44,1}, /* core5 return_Stack7 bit15 */
			{23155,44,1}, /* core5 return_Stack7 bit16 */
			{23154,44,1}, /* core5 return_Stack7 bit17 */
			{23153,44,1}, /* core5 return_Stack7 bit18 */
			{23232,44,0}, /* core5 return_Stack7 bit19 */
			{23231,44,0}, /* core5 return_Stack7 bit20 */
			{23230,44,0}, /* core5 return_Stack7 bit21 */
			{23229,44,0}, /* core5 return_Stack7 bit22 */
			{23108,44,1}, /* core5 return_Stack7 bit23 */
			{23107,44,1}, /* core5 return_Stack7 bit24 */
			{23106,44,1}, /* core5 return_Stack7 bit25 */
			{23105,44,1}, /* core5 return_Stack7 bit26 */
			{23035,44,1}, /* core5 return_Stack7 bit27 */
			{23034,44,1}, /* core5 return_Stack7 bit28 */
			{23033,44,1}, /* core5 return_Stack7 bit29 */
			{23032,44,1}, /* core5 return_Stack7 bit30 */
			{13715,44,0}, /* core5 return_Stack7 bit31 */
			{23031,44,1}, /* core5 return_Stack7 bit32 */
			{23030,44,1}, /* core5 return_Stack7 bit33 */
			{23029,44,1}, /* core5 return_Stack7 bit34 */
			{23028,44,1}, /* core5 return_Stack7 bit35 */
			{23023,44,1}, /* core5 return_Stack7 bit36 */
			{23022,44,1}, /* core5 return_Stack7 bit37 */
			{23021,44,1}, /* core5 return_Stack7 bit38 */
			{23020,44,1}, /* core5 return_Stack7 bit39 */
			{23039,44,1}, /* core5 return_Stack7 bit40 */
			{23038,44,1}, /* core5 return_Stack7 bit41 */
			{23037,44,1}, /* core5 return_Stack7 bit42 */
			{23036,44,1}, /* core5 return_Stack7 bit43 */
			{23027,44,1}, /* core5 return_Stack7 bit44 */
			{23026,44,1}, /* core5 return_Stack7 bit45 */
			{23025,44,1}, /* core5 return_Stack7 bit46 */
			{23024,44,1}, /* core5 return_Stack7 bit47 */
			{13716,44,0}, /* core5 return_Stack7 bit48 */
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
			.L2_parity_err = {{
			{ 7910,43,0}, /* core5 L2_parity_err bit0 */
			{    0, 0,2}, /* core5 L2_parity_err bit1 */
			{    0, 0,2}, /* core5 L2_parity_err bit2 */
			{    0, 0,2}, /* core5 L2_parity_err bit3 */
			{    0, 0,2}, /* core5 L2_parity_err bit4 */
			{    0, 0,2}, /* core5 L2_parity_err bit5 */
			{    0, 0,2}, /* core5 L2_parity_err bit6 */
			{    0, 0,2}, /* core5 L2_parity_err bit7 */
			{    0, 0,2}, /* core5 L2_parity_err bit8 */
			{    0, 0,2}, /* core5 L2_parity_err bit9 */
			{    0, 0,2}, /* core5 L2_parity_err bit10 */
			{    0, 0,2}, /* core5 L2_parity_err bit11 */
			{    0, 0,2}, /* core5 L2_parity_err bit12 */
			{    0, 0,2}, /* core5 L2_parity_err bit13 */
			{    0, 0,2}, /* core5 L2_parity_err bit14 */
			{    0, 0,2}, /* core5 L2_parity_err bit15 */
			{    0, 0,2}, /* core5 L2_parity_err bit16 */
			{    0, 0,2}, /* core5 L2_parity_err bit17 */
			{    0, 0,2}, /* core5 L2_parity_err bit18 */
			{    0, 0,2}, /* core5 L2_parity_err bit19 */
			{    0, 0,2}, /* core5 L2_parity_err bit20 */
			{    0, 0,2}, /* core5 L2_parity_err bit21 */
			{    0, 0,2}, /* core5 L2_parity_err bit22 */
			{    0, 0,2}, /* core5 L2_parity_err bit23 */
			{    0, 0,2}, /* core5 L2_parity_err bit24 */
			{    0, 0,2}, /* core5 L2_parity_err bit25 */
			{    0, 0,2}, /* core5 L2_parity_err bit26 */
			{    0, 0,2}, /* core5 L2_parity_err bit27 */
			{    0, 0,2}, /* core5 L2_parity_err bit28 */
			{    0, 0,2}, /* core5 L2_parity_err bit29 */
			{    0, 0,2}, /* core5 L2_parity_err bit30 */
			{    0, 0,2}, /* core5 L2_parity_err bit31 */
			{    0, 0,2}, /* core5 L2_parity_err bit32 */
			{    0, 0,2}, /* core5 L2_parity_err bit33 */
			{    0, 0,2}, /* core5 L2_parity_err bit34 */
			{    0, 0,2}, /* core5 L2_parity_err bit35 */
			{    0, 0,2}, /* core5 L2_parity_err bit36 */
			{    0, 0,2}, /* core5 L2_parity_err bit37 */
			{    0, 0,2}, /* core5 L2_parity_err bit38 */
			{    0, 0,2}, /* core5 L2_parity_err bit39 */
			{    0, 0,2}, /* core5 L2_parity_err bit40 */
			{    0, 0,2}, /* core5 L2_parity_err bit41 */
			{    0, 0,2}, /* core5 L2_parity_err bit42 */
			{    0, 0,2}, /* core5 L2_parity_err bit43 */
			{    0, 0,2}, /* core5 L2_parity_err bit44 */
			{    0, 0,2}, /* core5 L2_parity_err bit45 */
			{    0, 0,2}, /* core5 L2_parity_err bit46 */
			{    0, 0,2}, /* core5 L2_parity_err bit47 */
			{    0, 0,2}, /* core5 L2_parity_err bit48 */
			{    0, 0,2}, /* core5 L2_parity_err bit49 */
			{    0, 0,2}, /* core5 L2_parity_err bit50 */
			{    0, 0,2}, /* core5 L2_parity_err bit51 */
			{    0, 0,2}, /* core5 L2_parity_err bit52 */
			{    0, 0,2}, /* core5 L2_parity_err bit53 */
			{    0, 0,2}, /* core5 L2_parity_err bit54 */
			{    0, 0,2}, /* core5 L2_parity_err bit55 */
			{    0, 0,2}, /* core5 L2_parity_err bit56 */
			{    0, 0,2}, /* core5 L2_parity_err bit57 */
			{    0, 0,2}, /* core5 L2_parity_err bit58 */
			{    0, 0,2}, /* core5 L2_parity_err bit59 */
			{    0, 0,2}, /* core5 L2_parity_err bit60 */
			{    0, 0,2}, /* core5 L2_parity_err bit61 */
			{    0, 0,2}, /* core5 L2_parity_err bit62 */
			{    0, 0,2}, /* core5 L2_parity_err bit63 */
			}},
			.L2_parity_err_count = {{
			{13805,43,1}, /* core5 L2_parity_err_count bit0 */
			{13804,43,1}, /* core5 L2_parity_err_count bit1 */
			{13803,43,1}, /* core5 L2_parity_err_count bit2 */
			{13810,43,0}, /* core5 L2_parity_err_count bit3 */
			{13809,43,0}, /* core5 L2_parity_err_count bit4 */
			{13808,43,0}, /* core5 L2_parity_err_count bit5 */
			{13807,43,0}, /* core5 L2_parity_err_count bit6 */
			{ 7911,43,0}, /* core5 L2_parity_err_count bit7 */
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
			{14288,43,0}, /* core5 L2_parity_index bit0 */
			{14287,43,0}, /* core5 L2_parity_index bit1 */
			{14286,43,0}, /* core5 L2_parity_index bit2 */
			{14285,43,0}, /* core5 L2_parity_index bit3 */
			{14284,43,0}, /* core5 L2_parity_index bit4 */
			{14283,43,0}, /* core5 L2_parity_index bit5 */
			{14282,43,0}, /* core5 L2_parity_index bit6 */
			{14281,43,0}, /* core5 L2_parity_index bit7 */
			{ 7821,43,0}, /* core5 L2_parity_index bit8 */
			{    0, 0,2}, /* core5 L2_parity_index bit9 */
			{    0, 0,2}, /* core5 L2_parity_index bit10 */
			{    0, 0,2}, /* core5 L2_parity_index bit11 */
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
			{10378,43,0}, /* core5 L2_parity_way bit0 */
			{10377,43,0}, /* core5 L2_parity_way bit1 */
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
			{14280,43,0}, /* core5 L2_parity_banks bit0 */
			{14279,43,0}, /* core5 L2_parity_banks bit1 */
			{14278,43,0}, /* core5 L2_parity_banks bit2 */
			{14277,43,0}, /* core5 L2_parity_banks bit3 */
			{14272,43,0}, /* core5 L2_parity_banks bit4 */
			{14271,43,0}, /* core5 L2_parity_banks bit5 */
			{14270,43,0}, /* core5 L2_parity_banks bit6 */
			{14269,43,0}, /* core5 L2_parity_banks bit7 */
			{14292,43,0}, /* core5 L2_parity_banks bit8 */
			{14291,43,0}, /* core5 L2_parity_banks bit9 */
			{14290,43,0}, /* core5 L2_parity_banks bit10 */
			{14289,43,0}, /* core5 L2_parity_banks bit11 */
			{14276,43,0}, /* core5 L2_parity_banks bit12 */
			{14275,43,0}, /* core5 L2_parity_banks bit13 */
			{14274,43,0}, /* core5 L2_parity_banks bit14 */
			{14273,43,0}, /* core5 L2_parity_banks bit15 */
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
			{13279,51,0}, /* core6 return_Stack7 bit35 */
			{25567,47,0}, /* core6 return_Stack7 bit36 */
			{ 3663,49,1}, /* core6 return_Stack7 bit37 */
			{ 3664,49,1}, /* core6 return_Stack7 bit38 */
			{ 3667,49,1}, /* core6 return_Stack7 bit39 */
			{22849,49,1}, /* core6 return_Stack7 bit40 */
			{ 3662,49,1}, /* core6 return_Stack7 bit41 */
			{ 3666,49,1}, /* core6 return_Stack7 bit42 */
			{22848,49,1}, /* core6 return_Stack7 bit43 */
			{22847,49,1}, /* core6 return_Stack7 bit44 */
			{13280,51,0}, /* core6 return_Stack7 bit45 */
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
			.L2_parity_err = {{
			{ 2973,51,0}, /* core6 L2_parity_err bit0 */
			{    0, 0,2}, /* core6 L2_parity_err bit1 */
			{    0, 0,2}, /* core6 L2_parity_err bit2 */
			{    0, 0,2}, /* core6 L2_parity_err bit3 */
			{    0, 0,2}, /* core6 L2_parity_err bit4 */
			{    0, 0,2}, /* core6 L2_parity_err bit5 */
			{    0, 0,2}, /* core6 L2_parity_err bit6 */
			{    0, 0,2}, /* core6 L2_parity_err bit7 */
			{    0, 0,2}, /* core6 L2_parity_err bit8 */
			{    0, 0,2}, /* core6 L2_parity_err bit9 */
			{    0, 0,2}, /* core6 L2_parity_err bit10 */
			{    0, 0,2}, /* core6 L2_parity_err bit11 */
			{    0, 0,2}, /* core6 L2_parity_err bit12 */
			{    0, 0,2}, /* core6 L2_parity_err bit13 */
			{    0, 0,2}, /* core6 L2_parity_err bit14 */
			{    0, 0,2}, /* core6 L2_parity_err bit15 */
			{    0, 0,2}, /* core6 L2_parity_err bit16 */
			{    0, 0,2}, /* core6 L2_parity_err bit17 */
			{    0, 0,2}, /* core6 L2_parity_err bit18 */
			{    0, 0,2}, /* core6 L2_parity_err bit19 */
			{    0, 0,2}, /* core6 L2_parity_err bit20 */
			{    0, 0,2}, /* core6 L2_parity_err bit21 */
			{    0, 0,2}, /* core6 L2_parity_err bit22 */
			{    0, 0,2}, /* core6 L2_parity_err bit23 */
			{    0, 0,2}, /* core6 L2_parity_err bit24 */
			{    0, 0,2}, /* core6 L2_parity_err bit25 */
			{    0, 0,2}, /* core6 L2_parity_err bit26 */
			{    0, 0,2}, /* core6 L2_parity_err bit27 */
			{    0, 0,2}, /* core6 L2_parity_err bit28 */
			{    0, 0,2}, /* core6 L2_parity_err bit29 */
			{    0, 0,2}, /* core6 L2_parity_err bit30 */
			{    0, 0,2}, /* core6 L2_parity_err bit31 */
			{    0, 0,2}, /* core6 L2_parity_err bit32 */
			{    0, 0,2}, /* core6 L2_parity_err bit33 */
			{    0, 0,2}, /* core6 L2_parity_err bit34 */
			{    0, 0,2}, /* core6 L2_parity_err bit35 */
			{    0, 0,2}, /* core6 L2_parity_err bit36 */
			{    0, 0,2}, /* core6 L2_parity_err bit37 */
			{    0, 0,2}, /* core6 L2_parity_err bit38 */
			{    0, 0,2}, /* core6 L2_parity_err bit39 */
			{    0, 0,2}, /* core6 L2_parity_err bit40 */
			{    0, 0,2}, /* core6 L2_parity_err bit41 */
			{    0, 0,2}, /* core6 L2_parity_err bit42 */
			{    0, 0,2}, /* core6 L2_parity_err bit43 */
			{    0, 0,2}, /* core6 L2_parity_err bit44 */
			{    0, 0,2}, /* core6 L2_parity_err bit45 */
			{    0, 0,2}, /* core6 L2_parity_err bit46 */
			{    0, 0,2}, /* core6 L2_parity_err bit47 */
			{    0, 0,2}, /* core6 L2_parity_err bit48 */
			{    0, 0,2}, /* core6 L2_parity_err bit49 */
			{    0, 0,2}, /* core6 L2_parity_err bit50 */
			{    0, 0,2}, /* core6 L2_parity_err bit51 */
			{    0, 0,2}, /* core6 L2_parity_err bit52 */
			{    0, 0,2}, /* core6 L2_parity_err bit53 */
			{    0, 0,2}, /* core6 L2_parity_err bit54 */
			{    0, 0,2}, /* core6 L2_parity_err bit55 */
			{    0, 0,2}, /* core6 L2_parity_err bit56 */
			{    0, 0,2}, /* core6 L2_parity_err bit57 */
			{    0, 0,2}, /* core6 L2_parity_err bit58 */
			{    0, 0,2}, /* core6 L2_parity_err bit59 */
			{    0, 0,2}, /* core6 L2_parity_err bit60 */
			{    0, 0,2}, /* core6 L2_parity_err bit61 */
			{    0, 0,2}, /* core6 L2_parity_err bit62 */
			{    0, 0,2}, /* core6 L2_parity_err bit63 */
			}},
			.L2_parity_err_count = {{
			{27084,45,0}, /* core6 L2_parity_err_count bit0 */
			{27083,45,0}, /* core6 L2_parity_err_count bit1 */
			{27082,45,0}, /* core6 L2_parity_err_count bit2 */
			{27085,45,0}, /* core6 L2_parity_err_count bit3 */
			{27081,45,0}, /* core6 L2_parity_err_count bit4 */
			{27087,45,0}, /* core6 L2_parity_err_count bit5 */
			{27086,45,0}, /* core6 L2_parity_err_count bit6 */
			{27088,45,0}, /* core6 L2_parity_err_count bit7 */
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
			{27748,45,0}, /* core6 L2_parity_index bit0 */
			{ 8276,47,0}, /* core6 L2_parity_index bit1 */
			{27749,45,0}, /* core6 L2_parity_index bit2 */
			{25552,45,0}, /* core6 L2_parity_index bit3 */
			{ 8272,47,0}, /* core6 L2_parity_index bit4 */
			{ 8271,47,0}, /* core6 L2_parity_index bit5 */
			{ 8273,47,0}, /* core6 L2_parity_index bit6 */
			{27752,45,0}, /* core6 L2_parity_index bit7 */
			{ 8275,47,0}, /* core6 L2_parity_index bit8 */
			{ 8270,47,0}, /* core6 L2_parity_index bit9 */
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
			.L2_parity_banks = {{
			{27751,45,0}, /* core6 L2_parity_banks bit0 */
			{25555,45,0}, /* core6 L2_parity_banks bit1 */
			{27753,45,0}, /* core6 L2_parity_banks bit2 */
			{27750,45,0}, /* core6 L2_parity_banks bit3 */
			{25553,45,0}, /* core6 L2_parity_banks bit4 */
			{27754,45,0}, /* core6 L2_parity_banks bit5 */
			{15678,51,0}, /* core6 L2_parity_banks bit6 */
			{25554,45,0}, /* core6 L2_parity_banks bit7 */
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
			{13279,58,0}, /* core7 return_Stack7 bit35 */
			{25567,54,0}, /* core7 return_Stack7 bit36 */
			{ 3663,56,1}, /* core7 return_Stack7 bit37 */
			{ 3664,56,1}, /* core7 return_Stack7 bit38 */
			{ 3667,56,1}, /* core7 return_Stack7 bit39 */
			{22849,56,1}, /* core7 return_Stack7 bit40 */
			{ 3662,56,1}, /* core7 return_Stack7 bit41 */
			{ 3666,56,1}, /* core7 return_Stack7 bit42 */
			{22848,56,1}, /* core7 return_Stack7 bit43 */
			{22847,56,1}, /* core7 return_Stack7 bit44 */
			{13280,58,0}, /* core7 return_Stack7 bit45 */
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
			.L2_parity_err = {{
			{ 2973,58,0}, /* core7 L2_parity_err bit0 */
			{    0, 0,2}, /* core7 L2_parity_err bit1 */
			{    0, 0,2}, /* core7 L2_parity_err bit2 */
			{    0, 0,2}, /* core7 L2_parity_err bit3 */
			{    0, 0,2}, /* core7 L2_parity_err bit4 */
			{    0, 0,2}, /* core7 L2_parity_err bit5 */
			{    0, 0,2}, /* core7 L2_parity_err bit6 */
			{    0, 0,2}, /* core7 L2_parity_err bit7 */
			{    0, 0,2}, /* core7 L2_parity_err bit8 */
			{    0, 0,2}, /* core7 L2_parity_err bit9 */
			{    0, 0,2}, /* core7 L2_parity_err bit10 */
			{    0, 0,2}, /* core7 L2_parity_err bit11 */
			{    0, 0,2}, /* core7 L2_parity_err bit12 */
			{    0, 0,2}, /* core7 L2_parity_err bit13 */
			{    0, 0,2}, /* core7 L2_parity_err bit14 */
			{    0, 0,2}, /* core7 L2_parity_err bit15 */
			{    0, 0,2}, /* core7 L2_parity_err bit16 */
			{    0, 0,2}, /* core7 L2_parity_err bit17 */
			{    0, 0,2}, /* core7 L2_parity_err bit18 */
			{    0, 0,2}, /* core7 L2_parity_err bit19 */
			{    0, 0,2}, /* core7 L2_parity_err bit20 */
			{    0, 0,2}, /* core7 L2_parity_err bit21 */
			{    0, 0,2}, /* core7 L2_parity_err bit22 */
			{    0, 0,2}, /* core7 L2_parity_err bit23 */
			{    0, 0,2}, /* core7 L2_parity_err bit24 */
			{    0, 0,2}, /* core7 L2_parity_err bit25 */
			{    0, 0,2}, /* core7 L2_parity_err bit26 */
			{    0, 0,2}, /* core7 L2_parity_err bit27 */
			{    0, 0,2}, /* core7 L2_parity_err bit28 */
			{    0, 0,2}, /* core7 L2_parity_err bit29 */
			{    0, 0,2}, /* core7 L2_parity_err bit30 */
			{    0, 0,2}, /* core7 L2_parity_err bit31 */
			{    0, 0,2}, /* core7 L2_parity_err bit32 */
			{    0, 0,2}, /* core7 L2_parity_err bit33 */
			{    0, 0,2}, /* core7 L2_parity_err bit34 */
			{    0, 0,2}, /* core7 L2_parity_err bit35 */
			{    0, 0,2}, /* core7 L2_parity_err bit36 */
			{    0, 0,2}, /* core7 L2_parity_err bit37 */
			{    0, 0,2}, /* core7 L2_parity_err bit38 */
			{    0, 0,2}, /* core7 L2_parity_err bit39 */
			{    0, 0,2}, /* core7 L2_parity_err bit40 */
			{    0, 0,2}, /* core7 L2_parity_err bit41 */
			{    0, 0,2}, /* core7 L2_parity_err bit42 */
			{    0, 0,2}, /* core7 L2_parity_err bit43 */
			{    0, 0,2}, /* core7 L2_parity_err bit44 */
			{    0, 0,2}, /* core7 L2_parity_err bit45 */
			{    0, 0,2}, /* core7 L2_parity_err bit46 */
			{    0, 0,2}, /* core7 L2_parity_err bit47 */
			{    0, 0,2}, /* core7 L2_parity_err bit48 */
			{    0, 0,2}, /* core7 L2_parity_err bit49 */
			{    0, 0,2}, /* core7 L2_parity_err bit50 */
			{    0, 0,2}, /* core7 L2_parity_err bit51 */
			{    0, 0,2}, /* core7 L2_parity_err bit52 */
			{    0, 0,2}, /* core7 L2_parity_err bit53 */
			{    0, 0,2}, /* core7 L2_parity_err bit54 */
			{    0, 0,2}, /* core7 L2_parity_err bit55 */
			{    0, 0,2}, /* core7 L2_parity_err bit56 */
			{    0, 0,2}, /* core7 L2_parity_err bit57 */
			{    0, 0,2}, /* core7 L2_parity_err bit58 */
			{    0, 0,2}, /* core7 L2_parity_err bit59 */
			{    0, 0,2}, /* core7 L2_parity_err bit60 */
			{    0, 0,2}, /* core7 L2_parity_err bit61 */
			{    0, 0,2}, /* core7 L2_parity_err bit62 */
			{    0, 0,2}, /* core7 L2_parity_err bit63 */
			}},
			.L2_parity_err_count = {{
			{27084,52,0}, /* core7 L2_parity_err_count bit0 */
			{27083,52,0}, /* core7 L2_parity_err_count bit1 */
			{27082,52,0}, /* core7 L2_parity_err_count bit2 */
			{27085,52,0}, /* core7 L2_parity_err_count bit3 */
			{27081,52,0}, /* core7 L2_parity_err_count bit4 */
			{27087,52,0}, /* core7 L2_parity_err_count bit5 */
			{27086,52,0}, /* core7 L2_parity_err_count bit6 */
			{27088,52,0}, /* core7 L2_parity_err_count bit7 */
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
			{27748,52,0}, /* core7 L2_parity_index bit0 */
			{ 8276,54,0}, /* core7 L2_parity_index bit1 */
			{27749,52,0}, /* core7 L2_parity_index bit2 */
			{25552,52,0}, /* core7 L2_parity_index bit3 */
			{ 8272,54,0}, /* core7 L2_parity_index bit4 */
			{ 8271,54,0}, /* core7 L2_parity_index bit5 */
			{ 8273,54,0}, /* core7 L2_parity_index bit6 */
			{27752,52,0}, /* core7 L2_parity_index bit7 */
			{ 8275,54,0}, /* core7 L2_parity_index bit8 */
			{ 8270,54,0}, /* core7 L2_parity_index bit9 */
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
			.L2_parity_banks = {{
			{27751,52,0}, /* core7 L2_parity_banks bit0 */
			{25555,52,0}, /* core7 L2_parity_banks bit1 */
			{27753,52,0}, /* core7 L2_parity_banks bit2 */
			{27750,52,0}, /* core7 L2_parity_banks bit3 */
			{25553,52,0}, /* core7 L2_parity_banks bit4 */
			{27754,52,0}, /* core7 L2_parity_banks bit5 */
			{15678,58,0}, /* core7 L2_parity_banks bit6 */
			{25554,52,0}, /* core7 L2_parity_banks bit7 */
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
