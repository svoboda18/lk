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
			{ 1085,14,0}, /* core0 M0_AR_Pending_Counter bit0 */
			{ 1084,14,0}, /* core0 M0_AR_Pending_Counter bit1 */
			{ 1083,14,0}, /* core0 M0_AR_Pending_Counter bit2 */
			{ 1082,14,0}, /* core0 M0_AR_Pending_Counter bit3 */
			{ 3843,16,0}, /* core0 M0_AR_Pending_Counter bit4 */
			{ 3842,16,0}, /* core0 M0_AR_Pending_Counter bit5 */
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
			{ 1069,14,0}, /* core0 M1_AR_Pending_Counter bit0 */
			{ 1068,14,0}, /* core0 M1_AR_Pending_Counter bit1 */
			{ 1067,14,0}, /* core0 M1_AR_Pending_Counter bit2 */
			{ 1066,14,0}, /* core0 M1_AR_Pending_Counter bit3 */
			{ 1443,16,0}, /* core0 M1_AR_Pending_Counter bit4 */
			{ 1444,16,0}, /* core0 M1_AR_Pending_Counter bit5 */
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
			{ 1073,14,0}, /* core0 M2_AR_Pending_Counter bit0 */
			{ 1072,14,0}, /* core0 M2_AR_Pending_Counter bit1 */
			{ 1071,14,0}, /* core0 M2_AR_Pending_Counter bit2 */
			{ 1070,14,0}, /* core0 M2_AR_Pending_Counter bit3 */
			{ 3839,16,0}, /* core0 M2_AR_Pending_Counter bit4 */
			{ 3838,16,0}, /* core0 M2_AR_Pending_Counter bit5 */
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
			{ 1081,14,0}, /* core0 M0_AW_Pending_Counter bit0 */
			{ 1080,14,0}, /* core0 M0_AW_Pending_Counter bit1 */
			{ 1079,14,0}, /* core0 M0_AW_Pending_Counter bit2 */
			{ 1078,14,0}, /* core0 M0_AW_Pending_Counter bit3 */
			{ 3841,16,0}, /* core0 M0_AW_Pending_Counter bit4 */
			{ 3840,16,0}, /* core0 M0_AW_Pending_Counter bit5 */
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
			{ 1065,14,0}, /* core0 M1_AR_Pending_Counter bit0 */
			{ 1064,14,0}, /* core0 M1_AR_Pending_Counter bit1 */
			{ 1063,14,0}, /* core0 M1_AR_Pending_Counter bit2 */
			{ 1062,14,0}, /* core0 M1_AR_Pending_Counter bit3 */
			{ 3837,16,0}, /* core0 M1_AR_Pending_Counter bit4 */
			{ 3836,16,0}, /* core0 M1_AR_Pending_Counter bit5 */
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
			{ 1077,14,0}, /* core0 M2_AW_Pending_Counter bit0 */
			{ 1076,14,0}, /* core0 M2_AW_Pending_Counter bit1 */
			{ 1075,14,0}, /* core0 M2_AW_Pending_Counter bit2 */
			{ 1074,14,0}, /* core0 M2_AW_Pending_Counter bit3 */
			{ 3835,16,0}, /* core0 M2_AW_Pending_Counter bit4 */
			{ 3834,16,0}, /* core0 M2_AW_Pending_Counter bit5 */
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
			{ 1414,16,0}, /* core0 S4_AR_Pending_Counter bit0 */
			{ 1416,16,0}, /* core0 S4_AR_Pending_Counter bit1 */
			{ 1415,16,0}, /* core0 S4_AR_Pending_Counter bit2 */
			{ 1420,16,0}, /* core0 S4_AR_Pending_Counter bit3 */
			{ 1419,16,0}, /* core0 S4_AR_Pending_Counter bit4 */
			{ 1418,16,0}, /* core0 S4_AR_Pending_Counter bit5 */
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
			{ 1435,16,0}, /* core0 S4_AW_Pending_Counter bit0 */
			{ 1432,16,0}, /* core0 S4_AW_Pending_Counter bit1 */
			{ 1436,16,0}, /* core0 S4_AW_Pending_Counter bit2 */
			{ 1440,16,0}, /* core0 S4_AW_Pending_Counter bit3 */
			{ 1437,16,0}, /* core0 S4_AW_Pending_Counter bit4 */
			{ 1441,16,0}, /* core0 S4_AW_Pending_Counter bit5 */
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
			{ 1412,16,0}, /* core0 S3_AR_Pending_Counter bit0 */
			{ 1413,16,0}, /* core0 S3_AR_Pending_Counter bit1 */
			{ 1417,16,0}, /* core0 S3_AR_Pending_Counter bit2 */
			{ 1411,16,0}, /* core0 S3_AR_Pending_Counter bit3 */
			{ 1410,16,0}, /* core0 S3_AR_Pending_Counter bit4 */
			{ 1409,16,0}, /* core0 S3_AR_Pending_Counter bit5 */
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
			{ 1422,16,0}, /* core0 S3_AW_Pending_Counter bit0 */
			{ 1429,16,0}, /* core0 S3_AW_Pending_Counter bit1 */
			{ 1431,16,0}, /* core0 S3_AW_Pending_Counter bit2 */
			{ 1430,16,0}, /* core0 S3_AW_Pending_Counter bit3 */
			{ 1428,16,0}, /* core0 S3_AW_Pending_Counter bit4 */
			{ 1423,16,0}, /* core0 S3_AW_Pending_Counter bit5 */
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
			{ 1992, 4,0}, /* core0 mp0_L3_parity_err bit0 */
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
			{ 1990, 4,0}, /* core0 mp0_L3_parity_err_count bit0 */
			{ 1989, 4,0}, /* core0 mp0_L3_parity_err_count bit1 */
			{ 1988, 4,0}, /* core0 mp0_L3_parity_err_count bit2 */
			{ 1987, 4,0}, /* core0 mp0_L3_parity_err_count bit3 */
			{ 1986, 4,0}, /* core0 mp0_L3_parity_err_count bit4 */
			{ 1985, 4,0}, /* core0 mp0_L3_parity_err_count bit5 */
			{ 1984, 4,0}, /* core0 mp0_L3_parity_err_count bit6 */
			{ 1983, 4,0}, /* core0 mp0_L3_parity_err_count bit7 */
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
			{ 1991, 4,0}, /* core0 mp0_L3_parity_sap bit0 */
			{ 1946, 4,0}, /* core0 mp0_L3_parity_sap bit1 */
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
			{ 2021, 4,0}, /* core0 mp0_L3_parity_index bit0 */
			{ 2020, 4,0}, /* core0 mp0_L3_parity_index bit1 */
			{ 2019, 4,0}, /* core0 mp0_L3_parity_index bit2 */
			{ 2018, 4,0}, /* core0 mp0_L3_parity_index bit3 */
			{ 2011, 4,0}, /* core0 mp0_L3_parity_index bit4 */
			{ 2017, 4,0}, /* core0 mp0_L3_parity_index bit5 */
			{ 2008, 4,0}, /* core0 mp0_L3_parity_index bit6 */
			{ 2010, 4,0}, /* core0 mp0_L3_parity_index bit7 */
			{ 2007, 4,0}, /* core0 mp0_L3_parity_index bit8 */
			{ 2006, 4,0}, /* core0 mp0_L3_parity_index bit9 */
			{ 2005, 4,0}, /* core0 mp0_L3_parity_index bit10 */
			{ 2004, 4,0}, /* core0 mp0_L3_parity_index bit11 */
			{ 2003, 4,0}, /* core0 mp0_L3_parity_index bit12 */
			{ 2002, 4,0}, /* core0 mp0_L3_parity_index bit13 */
			{ 2009, 4,0}, /* core0 mp0_L3_parity_index bit14 */
			{ 2001, 4,0}, /* core0 mp0_L3_parity_index bit15 */
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
			{ 2016, 4,0}, /* core0 mp0_L3_parity_bank bit0 */
			{ 2015, 4,0}, /* core0 mp0_L3_parity_bank bit1 */
			{ 2000, 4,0}, /* core0 mp0_L3_parity_bank bit2 */
			{ 1999, 4,0}, /* core0 mp0_L3_parity_bank bit3 */
			{ 1998, 4,0}, /* core0 mp0_L3_parity_bank bit4 */
			{ 1997, 4,0}, /* core0 mp0_L3_parity_bank bit5 */
			{ 1996, 4,0}, /* core0 mp0_L3_parity_bank bit6 */
			{ 1995, 4,0}, /* core0 mp0_L3_parity_bank bit7 */
			{ 1994, 4,0}, /* core0 mp0_L3_parity_bank bit8 */
			{ 1993, 4,0}, /* core0 mp0_L3_parity_bank bit9 */
			{ 2014, 4,0}, /* core0 mp0_L3_parity_bank bit10 */
			{ 2013, 4,0}, /* core0 mp0_L3_parity_bank bit11 */
			{ 2024, 4,0}, /* core0 mp0_L3_parity_bank bit12 */
			{ 2012, 4,0}, /* core0 mp0_L3_parity_bank bit13 */
			{ 2023, 4,0}, /* core0 mp0_L3_parity_bank bit14 */
			{ 2022, 4,0}, /* core0 mp0_L3_parity_bank bit15 */
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
			{ 5572, 8,0}, /* core0 L2_parity_err bit0 */
			{ 5571, 8,0}, /* core0 L2_parity_err bit1 */
			{ 5570, 8,0}, /* core0 L2_parity_err bit2 */
			{ 5569, 8,0}, /* core0 L2_parity_err bit3 */
			{ 5568, 8,0}, /* core0 L2_parity_err bit4 */
			{ 5567, 8,0}, /* core0 L2_parity_err bit5 */
			{ 5566, 8,0}, /* core0 L2_parity_err bit6 */
			{ 5565, 8,0}, /* core0 L2_parity_err bit7 */
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
			{  232, 4,0}, /* core0 dfd_v35_enable bit0 */
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
			{   95,34,1}, /* core0 pc bit0 */
			{  433,34,1}, /* core0 pc bit1 */
			{  432,34,1}, /* core0 pc bit2 */
			{  431,34,1}, /* core0 pc bit3 */
			{  430,34,1}, /* core0 pc bit4 */
			{  429,34,1}, /* core0 pc bit5 */
			{  495,34,1}, /* core0 pc bit6 */
			{  426,34,1}, /* core0 pc bit7 */
			{  494,34,1}, /* core0 pc bit8 */
			{  425,34,1}, /* core0 pc bit9 */
			{  424,34,1}, /* core0 pc bit10 */
			{  445,34,1}, /* core0 pc bit11 */
			{  493,34,1}, /* core0 pc bit12 */
			{  492,34,1}, /* core0 pc bit13 */
			{  444,34,1}, /* core0 pc bit14 */
			{  443,34,1}, /* core0 pc bit15 */
			{  466,34,1}, /* core0 pc bit16 */
			{  482,34,1}, /* core0 pc bit17 */
			{  465,34,1}, /* core0 pc bit18 */
			{  464,34,1}, /* core0 pc bit19 */
			{  470,34,1}, /* core0 pc bit20 */
			{  463,34,1}, /* core0 pc bit21 */
			{  440,34,1}, /* core0 pc bit22 */
			{  446,34,1}, /* core0 pc bit23 */
			{  491,34,1}, /* core0 pc bit24 */
			{  462,34,1}, /* core0 pc bit25 */
			{  481,34,1}, /* core0 pc bit26 */
			{  480,34,1}, /* core0 pc bit27 */
			{  461,34,1}, /* core0 pc bit28 */
			{  460,34,1}, /* core0 pc bit29 */
			{  448,34,1}, /* core0 pc bit30 */
			{  450,34,1}, /* core0 pc bit31 */
			{  270,34,1}, /* core0 pc bit32 */
			{  269,34,1}, /* core0 pc bit33 */
			{  268,34,1}, /* core0 pc bit34 */
			{  278,34,1}, /* core0 pc bit35 */
			{  320,34,1}, /* core0 pc bit36 */
			{  267,34,1}, /* core0 pc bit37 */
			{  266,34,1}, /* core0 pc bit38 */
			{  312,34,1}, /* core0 pc bit39 */
			{  162,34,1}, /* core0 pc bit40 */
			{  319,34,1}, /* core0 pc bit41 */
			{  318,34,1}, /* core0 pc bit42 */
			{  161,34,1}, /* core0 pc bit43 */
			{  160,34,1}, /* core0 pc bit44 */
			{  159,34,1}, /* core0 pc bit45 */
			{  317,34,1}, /* core0 pc bit46 */
			{  316,34,1}, /* core0 pc bit47 */
			{  140,34,1}, /* core0 pc bit48 */
			{  277,34,1}, /* core0 pc bit49 */
			{  276,34,1}, /* core0 pc bit50 */
			{  275,34,1}, /* core0 pc bit51 */
			{  274,34,1}, /* core0 pc bit52 */
			{  139,34,1}, /* core0 pc bit53 */
			{  280,34,1}, /* core0 pc bit54 */
			{  279,34,1}, /* core0 pc bit55 */
			{  353,34,1}, /* core0 pc bit56 */
			{  273,34,1}, /* core0 pc bit57 */
			{  288,34,1}, /* core0 pc bit58 */
			{  287,34,1}, /* core0 pc bit59 */
			{  138,34,1}, /* core0 pc bit60 */
			{  264,34,1}, /* core0 pc bit61 */
			{  263,34,1}, /* core0 pc bit62 */
			{  145,34,1}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{41179,35,1}, /* core0 sp32 bit0 */
			{41177,35,1}, /* core0 sp32 bit1 */
			{41176,35,1}, /* core0 sp32 bit2 */
			{41175,35,1}, /* core0 sp32 bit3 */
			{41178,35,1}, /* core0 sp32 bit4 */
			{41171,35,1}, /* core0 sp32 bit5 */
			{41170,35,1}, /* core0 sp32 bit6 */
			{41172,35,1}, /* core0 sp32 bit7 */
			{41173,35,1}, /* core0 sp32 bit8 */
			{41174,35,1}, /* core0 sp32 bit9 */
			{41197,35,1}, /* core0 sp32 bit10 */
			{41190,35,1}, /* core0 sp32 bit11 */
			{41182,35,1}, /* core0 sp32 bit12 */
			{41201,35,1}, /* core0 sp32 bit13 */
			{41184,35,1}, /* core0 sp32 bit14 */
			{41198,35,1}, /* core0 sp32 bit15 */
			{34300,34,0}, /* core0 sp32 bit16 */
			{34299,34,0}, /* core0 sp32 bit17 */
			{34328,34,0}, /* core0 sp32 bit18 */
			{34327,34,0}, /* core0 sp32 bit19 */
			{41196,35,1}, /* core0 sp32 bit20 */
			{41185,35,1}, /* core0 sp32 bit21 */
			{41227,35,1}, /* core0 sp32 bit22 */
			{41226,35,1}, /* core0 sp32 bit23 */
			{41180,35,1}, /* core0 sp32 bit24 */
			{41181,35,1}, /* core0 sp32 bit25 */
			{41183,35,1}, /* core0 sp32 bit26 */
			{41186,35,1}, /* core0 sp32 bit27 */
			{41199,35,1}, /* core0 sp32 bit28 */
			{41191,35,1}, /* core0 sp32 bit29 */
			{41188,35,1}, /* core0 sp32 bit30 */
			{41189,35,1}, /* core0 sp32 bit31 */
			{41121,35,1}, /* core0 sp32 bit32 */
			{41123,35,1}, /* core0 sp32 bit33 */
			{41113,35,1}, /* core0 sp32 bit34 */
			{41115,35,1}, /* core0 sp32 bit35 */
			{41120,35,1}, /* core0 sp32 bit36 */
			{41118,35,1}, /* core0 sp32 bit37 */
			{41122,35,1}, /* core0 sp32 bit38 */
			{41117,35,1}, /* core0 sp32 bit39 */
			{41116,35,1}, /* core0 sp32 bit40 */
			{41119,35,1}, /* core0 sp32 bit41 */
			{41108,35,1}, /* core0 sp32 bit42 */
			{41109,35,1}, /* core0 sp32 bit43 */
			{41110,35,1}, /* core0 sp32 bit44 */
			{41114,35,1}, /* core0 sp32 bit45 */
			{41111,35,1}, /* core0 sp32 bit46 */
			{41112,35,1}, /* core0 sp32 bit47 */
			{41159,35,1}, /* core0 sp32 bit48 */
			{41164,35,1}, /* core0 sp32 bit49 */
			{34350,34,0}, /* core0 sp32 bit50 */
			{34349,34,0}, /* core0 sp32 bit51 */
			{41166,35,1}, /* core0 sp32 bit52 */
			{41165,35,1}, /* core0 sp32 bit53 */
			{41163,35,1}, /* core0 sp32 bit54 */
			{41161,35,1}, /* core0 sp32 bit55 */
			{41167,35,1}, /* core0 sp32 bit56 */
			{41160,35,1}, /* core0 sp32 bit57 */
			{41162,35,1}, /* core0 sp32 bit58 */
			{41158,35,1}, /* core0 sp32 bit59 */
			{41157,35,1}, /* core0 sp32 bit60 */
			{41155,35,1}, /* core0 sp32 bit61 */
			{41154,35,1}, /* core0 sp32 bit62 */
			{41156,35,1}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{41650,35,1}, /* core0 fp32 bit0 */
			{41651,35,1}, /* core0 fp32 bit1 */
			{41648,35,1}, /* core0 fp32 bit2 */
			{41645,35,1}, /* core0 fp32 bit3 */
			{41652,35,1}, /* core0 fp32 bit4 */
			{41647,35,1}, /* core0 fp32 bit5 */
			{41644,35,1}, /* core0 fp32 bit6 */
			{41646,35,1}, /* core0 fp32 bit7 */
			{41643,35,1}, /* core0 fp32 bit8 */
			{41642,35,1}, /* core0 fp32 bit9 */
			{41676,35,1}, /* core0 fp32 bit10 */
			{41675,35,1}, /* core0 fp32 bit11 */
			{41685,35,1}, /* core0 fp32 bit12 */
			{41684,35,1}, /* core0 fp32 bit13 */
			{41680,35,1}, /* core0 fp32 bit14 */
			{41681,35,1}, /* core0 fp32 bit15 */
			{41682,35,1}, /* core0 fp32 bit16 */
			{41656,35,1}, /* core0 fp32 bit17 */
			{41678,35,1}, /* core0 fp32 bit18 */
			{41683,35,1}, /* core0 fp32 bit19 */
			{41677,35,1}, /* core0 fp32 bit20 */
			{41672,35,1}, /* core0 fp32 bit21 */
			{41686,35,1}, /* core0 fp32 bit22 */
			{41649,35,1}, /* core0 fp32 bit23 */
			{41688,35,1}, /* core0 fp32 bit24 */
			{41689,35,1}, /* core0 fp32 bit25 */
			{41669,35,1}, /* core0 fp32 bit26 */
			{41670,35,1}, /* core0 fp32 bit27 */
			{41673,35,1}, /* core0 fp32 bit28 */
			{41679,35,1}, /* core0 fp32 bit29 */
			{41674,35,1}, /* core0 fp32 bit30 */
			{41671,35,1}, /* core0 fp32 bit31 */
			{41580,35,1}, /* core0 fp32 bit32 */
			{41589,35,1}, /* core0 fp32 bit33 */
			{41583,35,1}, /* core0 fp32 bit34 */
			{41587,35,1}, /* core0 fp32 bit35 */
			{41582,35,1}, /* core0 fp32 bit36 */
			{41575,35,1}, /* core0 fp32 bit37 */
			{41576,35,1}, /* core0 fp32 bit38 */
			{41585,35,1}, /* core0 fp32 bit39 */
			{41584,35,1}, /* core0 fp32 bit40 */
			{41581,35,1}, /* core0 fp32 bit41 */
			{41588,35,1}, /* core0 fp32 bit42 */
			{41577,35,1}, /* core0 fp32 bit43 */
			{41578,35,1}, /* core0 fp32 bit44 */
			{41579,35,1}, /* core0 fp32 bit45 */
			{41574,35,1}, /* core0 fp32 bit46 */
			{41586,35,1}, /* core0 fp32 bit47 */
			{41605,35,1}, /* core0 fp32 bit48 */
			{41604,35,1}, /* core0 fp32 bit49 */
			{41606,35,1}, /* core0 fp32 bit50 */
			{41609,35,1}, /* core0 fp32 bit51 */
			{41607,35,1}, /* core0 fp32 bit52 */
			{41610,35,1}, /* core0 fp32 bit53 */
			{41602,35,1}, /* core0 fp32 bit54 */
			{41597,35,1}, /* core0 fp32 bit55 */
			{41608,35,1}, /* core0 fp32 bit56 */
			{41598,35,1}, /* core0 fp32 bit57 */
			{41601,35,1}, /* core0 fp32 bit58 */
			{41596,35,1}, /* core0 fp32 bit59 */
			{41593,35,1}, /* core0 fp32 bit60 */
			{34376,34,0}, /* core0 fp32 bit61 */
			{34375,34,0}, /* core0 fp32 bit62 */
			{41594,35,1}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{40573,35,1}, /* core0 fp64 bit0 */
			{40571,35,1}, /* core0 fp64 bit1 */
			{40569,35,1}, /* core0 fp64 bit2 */
			{34306,34,0}, /* core0 fp64 bit3 */
			{34305,34,0}, /* core0 fp64 bit4 */
			{40567,35,1}, /* core0 fp64 bit5 */
			{40568,35,1}, /* core0 fp64 bit6 */
			{34304,34,0}, /* core0 fp64 bit7 */
			{34303,34,0}, /* core0 fp64 bit8 */
			{40570,35,1}, /* core0 fp64 bit9 */
			{40560,35,1}, /* core0 fp64 bit10 */
			{40558,35,1}, /* core0 fp64 bit11 */
			{40566,35,1}, /* core0 fp64 bit12 */
			{40565,35,1}, /* core0 fp64 bit13 */
			{40564,35,1}, /* core0 fp64 bit14 */
			{40559,35,1}, /* core0 fp64 bit15 */
			{40554,35,1}, /* core0 fp64 bit16 */
			{40490,35,1}, /* core0 fp64 bit17 */
			{40552,35,1}, /* core0 fp64 bit18 */
			{40555,35,1}, /* core0 fp64 bit19 */
			{40557,35,1}, /* core0 fp64 bit20 */
			{40553,35,1}, /* core0 fp64 bit21 */
			{40572,35,1}, /* core0 fp64 bit22 */
			{40491,35,1}, /* core0 fp64 bit23 */
			{40492,35,1}, /* core0 fp64 bit24 */
			{40493,35,1}, /* core0 fp64 bit25 */
			{40563,35,1}, /* core0 fp64 bit26 */
			{34322,34,0}, /* core0 fp64 bit27 */
			{34321,34,0}, /* core0 fp64 bit28 */
			{40562,35,1}, /* core0 fp64 bit29 */
			{40561,35,1}, /* core0 fp64 bit30 */
			{40556,35,1}, /* core0 fp64 bit31 */
			{40702,35,1}, /* core0 fp64 bit32 */
			{40697,35,1}, /* core0 fp64 bit33 */
			{40699,35,1}, /* core0 fp64 bit34 */
			{40708,35,1}, /* core0 fp64 bit35 */
			{40706,35,1}, /* core0 fp64 bit36 */
			{40701,35,1}, /* core0 fp64 bit37 */
			{40703,35,1}, /* core0 fp64 bit38 */
			{40705,35,1}, /* core0 fp64 bit39 */
			{40704,35,1}, /* core0 fp64 bit40 */
			{40698,35,1}, /* core0 fp64 bit41 */
			{40707,35,1}, /* core0 fp64 bit42 */
			{40700,35,1}, /* core0 fp64 bit43 */
			{40709,35,1}, /* core0 fp64 bit44 */
			{40696,35,1}, /* core0 fp64 bit45 */
			{40727,35,1}, /* core0 fp64 bit46 */
			{40695,35,1}, /* core0 fp64 bit47 */
			{40690,35,1}, /* core0 fp64 bit48 */
			{40638,35,1}, /* core0 fp64 bit49 */
			{40642,35,1}, /* core0 fp64 bit50 */
			{40645,35,1}, /* core0 fp64 bit51 */
			{40644,35,1}, /* core0 fp64 bit52 */
			{40643,35,1}, /* core0 fp64 bit53 */
			{40637,35,1}, /* core0 fp64 bit54 */
			{40632,35,1}, /* core0 fp64 bit55 */
			{40646,35,1}, /* core0 fp64 bit56 */
			{40633,35,1}, /* core0 fp64 bit57 */
			{40635,35,1}, /* core0 fp64 bit58 */
			{40691,35,1}, /* core0 fp64 bit59 */
			{40693,35,1}, /* core0 fp64 bit60 */
			{40726,35,1}, /* core0 fp64 bit61 */
			{40692,35,1}, /* core0 fp64 bit62 */
			{40694,35,1}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40577,35,1}, /* core0 sp_EL0 bit0 */
			{40575,35,1}, /* core0 sp_EL0 bit1 */
			{40580,35,1}, /* core0 sp_EL0 bit2 */
			{40582,35,1}, /* core0 sp_EL0 bit3 */
			{40583,35,1}, /* core0 sp_EL0 bit4 */
			{40581,35,1}, /* core0 sp_EL0 bit5 */
			{34278,34,0}, /* core0 sp_EL0 bit6 */
			{34277,34,0}, /* core0 sp_EL0 bit7 */
			{40578,35,1}, /* core0 sp_EL0 bit8 */
			{40576,35,1}, /* core0 sp_EL0 bit9 */
			{40488,35,1}, /* core0 sp_EL0 bit10 */
			{40487,35,1}, /* core0 sp_EL0 bit11 */
			{34276,34,0}, /* core0 sp_EL0 bit12 */
			{34275,34,0}, /* core0 sp_EL0 bit13 */
			{40579,35,1}, /* core0 sp_EL0 bit14 */
			{40574,35,1}, /* core0 sp_EL0 bit15 */
			{34284,34,0}, /* core0 sp_EL0 bit16 */
			{34283,34,0}, /* core0 sp_EL0 bit17 */
			{40489,35,1}, /* core0 sp_EL0 bit18 */
			{40486,35,1}, /* core0 sp_EL0 bit19 */
			{40485,35,1}, /* core0 sp_EL0 bit20 */
			{40484,35,1}, /* core0 sp_EL0 bit21 */
			{40306,35,1}, /* core0 sp_EL0 bit22 */
			{40302,35,1}, /* core0 sp_EL0 bit23 */
			{40304,35,1}, /* core0 sp_EL0 bit24 */
			{40305,35,1}, /* core0 sp_EL0 bit25 */
			{40282,35,1}, /* core0 sp_EL0 bit26 */
			{40283,35,1}, /* core0 sp_EL0 bit27 */
			{40285,35,1}, /* core0 sp_EL0 bit28 */
			{40284,35,1}, /* core0 sp_EL0 bit29 */
			{40286,35,1}, /* core0 sp_EL0 bit30 */
			{40303,35,1}, /* core0 sp_EL0 bit31 */
			{40436,35,1}, /* core0 sp_EL0 bit32 */
			{40434,35,1}, /* core0 sp_EL0 bit33 */
			{40440,35,1}, /* core0 sp_EL0 bit34 */
			{40437,35,1}, /* core0 sp_EL0 bit35 */
			{40427,35,1}, /* core0 sp_EL0 bit36 */
			{40428,35,1}, /* core0 sp_EL0 bit37 */
			{40431,35,1}, /* core0 sp_EL0 bit38 */
			{40429,35,1}, /* core0 sp_EL0 bit39 */
			{40430,35,1}, /* core0 sp_EL0 bit40 */
			{40441,35,1}, /* core0 sp_EL0 bit41 */
			{40433,35,1}, /* core0 sp_EL0 bit42 */
			{40432,35,1}, /* core0 sp_EL0 bit43 */
			{40439,35,1}, /* core0 sp_EL0 bit44 */
			{40438,35,1}, /* core0 sp_EL0 bit45 */
			{40443,35,1}, /* core0 sp_EL0 bit46 */
			{40442,35,1}, /* core0 sp_EL0 bit47 */
			{40456,35,1}, /* core0 sp_EL0 bit48 */
			{34430,34,0}, /* core0 sp_EL0 bit49 */
			{34426,34,0}, /* core0 sp_EL0 bit50 */
			{34425,34,0}, /* core0 sp_EL0 bit51 */
			{34432,34,0}, /* core0 sp_EL0 bit52 */
			{34431,34,0}, /* core0 sp_EL0 bit53 */
			{34429,34,0}, /* core0 sp_EL0 bit54 */
			{40446,35,1}, /* core0 sp_EL0 bit55 */
			{36696,34,0}, /* core0 sp_EL0 bit56 */
			{36695,34,0}, /* core0 sp_EL0 bit57 */
			{36694,34,0}, /* core0 sp_EL0 bit58 */
			{36693,34,0}, /* core0 sp_EL0 bit59 */
			{40445,35,1}, /* core0 sp_EL0 bit60 */
			{40444,35,1}, /* core0 sp_EL0 bit61 */
			{34392,34,0}, /* core0 sp_EL0 bit62 */
			{34391,34,0}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40312,35,1}, /* core0 sp_EL1 bit0 */
			{40319,35,1}, /* core0 sp_EL1 bit1 */
			{40314,35,1}, /* core0 sp_EL1 bit2 */
			{40315,35,1}, /* core0 sp_EL1 bit3 */
			{34236,34,0}, /* core0 sp_EL1 bit4 */
			{34235,34,0}, /* core0 sp_EL1 bit5 */
			{34238,34,0}, /* core0 sp_EL1 bit6 */
			{34237,34,0}, /* core0 sp_EL1 bit7 */
			{40313,35,1}, /* core0 sp_EL1 bit8 */
			{40316,35,1}, /* core0 sp_EL1 bit9 */
			{40336,35,1}, /* core0 sp_EL1 bit10 */
			{40333,35,1}, /* core0 sp_EL1 bit11 */
			{40311,35,1}, /* core0 sp_EL1 bit12 */
			{40308,35,1}, /* core0 sp_EL1 bit13 */
			{40331,35,1}, /* core0 sp_EL1 bit14 */
			{40330,35,1}, /* core0 sp_EL1 bit15 */
			{34216,34,0}, /* core0 sp_EL1 bit16 */
			{34215,34,0}, /* core0 sp_EL1 bit17 */
			{40348,35,1}, /* core0 sp_EL1 bit18 */
			{40349,35,1}, /* core0 sp_EL1 bit19 */
			{40350,35,1}, /* core0 sp_EL1 bit20 */
			{40346,35,1}, /* core0 sp_EL1 bit21 */
			{40332,35,1}, /* core0 sp_EL1 bit22 */
			{40334,35,1}, /* core0 sp_EL1 bit23 */
			{40335,35,1}, /* core0 sp_EL1 bit24 */
			{40347,35,1}, /* core0 sp_EL1 bit25 */
			{40320,35,1}, /* core0 sp_EL1 bit26 */
			{40321,35,1}, /* core0 sp_EL1 bit27 */
			{40310,35,1}, /* core0 sp_EL1 bit28 */
			{40309,35,1}, /* core0 sp_EL1 bit29 */
			{40307,35,1}, /* core0 sp_EL1 bit30 */
			{40345,35,1}, /* core0 sp_EL1 bit31 */
			{40406,35,1}, /* core0 sp_EL1 bit32 */
			{40405,35,1}, /* core0 sp_EL1 bit33 */
			{40386,35,1}, /* core0 sp_EL1 bit34 */
			{40383,35,1}, /* core0 sp_EL1 bit35 */
			{40422,35,1}, /* core0 sp_EL1 bit36 */
			{40421,35,1}, /* core0 sp_EL1 bit37 */
			{40407,35,1}, /* core0 sp_EL1 bit38 */
			{40400,35,1}, /* core0 sp_EL1 bit39 */
			{40401,35,1}, /* core0 sp_EL1 bit40 */
			{40409,35,1}, /* core0 sp_EL1 bit41 */
			{40410,35,1}, /* core0 sp_EL1 bit42 */
			{40411,35,1}, /* core0 sp_EL1 bit43 */
			{40408,35,1}, /* core0 sp_EL1 bit44 */
			{40384,35,1}, /* core0 sp_EL1 bit45 */
			{40379,35,1}, /* core0 sp_EL1 bit46 */
			{40385,35,1}, /* core0 sp_EL1 bit47 */
			{40449,35,1}, /* core0 sp_EL1 bit48 */
			{39472,34,0}, /* core0 sp_EL1 bit49 */
			{39471,34,0}, /* core0 sp_EL1 bit50 */
			{39470,34,0}, /* core0 sp_EL1 bit51 */
			{39469,34,0}, /* core0 sp_EL1 bit52 */
			{39468,34,0}, /* core0 sp_EL1 bit53 */
			{39467,34,0}, /* core0 sp_EL1 bit54 */
			{39466,34,0}, /* core0 sp_EL1 bit55 */
			{39465,34,0}, /* core0 sp_EL1 bit56 */
			{40448,35,1}, /* core0 sp_EL1 bit57 */
			{34398,34,0}, /* core0 sp_EL1 bit58 */
			{34397,34,0}, /* core0 sp_EL1 bit59 */
			{34386,34,0}, /* core0 sp_EL1 bit60 */
			{34385,34,0}, /* core0 sp_EL1 bit61 */
			{34198,34,0}, /* core0 sp_EL1 bit62 */
			{34197,34,0}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40264,35,1}, /* core0 sp_EL2 bit0 */
			{40256,35,1}, /* core0 sp_EL2 bit1 */
			{40268,35,1}, /* core0 sp_EL2 bit2 */
			{40266,35,1}, /* core0 sp_EL2 bit3 */
			{40257,35,1}, /* core0 sp_EL2 bit4 */
			{40263,35,1}, /* core0 sp_EL2 bit5 */
			{40267,35,1}, /* core0 sp_EL2 bit6 */
			{40262,35,1}, /* core0 sp_EL2 bit7 */
			{40261,35,1}, /* core0 sp_EL2 bit8 */
			{40260,35,1}, /* core0 sp_EL2 bit9 */
			{40245,35,1}, /* core0 sp_EL2 bit10 */
			{40246,35,1}, /* core0 sp_EL2 bit11 */
			{40265,35,1}, /* core0 sp_EL2 bit12 */
			{40243,35,1}, /* core0 sp_EL2 bit13 */
			{40241,35,1}, /* core0 sp_EL2 bit14 */
			{40239,35,1}, /* core0 sp_EL2 bit15 */
			{40251,35,1}, /* core0 sp_EL2 bit16 */
			{40259,35,1}, /* core0 sp_EL2 bit17 */
			{40250,35,1}, /* core0 sp_EL2 bit18 */
			{40247,35,1}, /* core0 sp_EL2 bit19 */
			{40248,35,1}, /* core0 sp_EL2 bit20 */
			{40249,35,1}, /* core0 sp_EL2 bit21 */
			{40255,35,1}, /* core0 sp_EL2 bit22 */
			{40258,35,1}, /* core0 sp_EL2 bit23 */
			{40254,35,1}, /* core0 sp_EL2 bit24 */
			{40253,35,1}, /* core0 sp_EL2 bit25 */
			{40238,35,1}, /* core0 sp_EL2 bit26 */
			{40237,35,1}, /* core0 sp_EL2 bit27 */
			{40242,35,1}, /* core0 sp_EL2 bit28 */
			{40240,35,1}, /* core0 sp_EL2 bit29 */
			{40244,35,1}, /* core0 sp_EL2 bit30 */
			{40252,35,1}, /* core0 sp_EL2 bit31 */
			{40402,35,1}, /* core0 sp_EL2 bit32 */
			{40412,35,1}, /* core0 sp_EL2 bit33 */
			{40387,35,1}, /* core0 sp_EL2 bit34 */
			{40388,35,1}, /* core0 sp_EL2 bit35 */
			{40419,35,1}, /* core0 sp_EL2 bit36 */
			{40414,35,1}, /* core0 sp_EL2 bit37 */
			{40413,35,1}, /* core0 sp_EL2 bit38 */
			{40417,35,1}, /* core0 sp_EL2 bit39 */
			{40416,35,1}, /* core0 sp_EL2 bit40 */
			{40418,35,1}, /* core0 sp_EL2 bit41 */
			{40415,35,1}, /* core0 sp_EL2 bit42 */
			{40420,35,1}, /* core0 sp_EL2 bit43 */
			{40404,35,1}, /* core0 sp_EL2 bit44 */
			{40403,35,1}, /* core0 sp_EL2 bit45 */
			{40378,35,1}, /* core0 sp_EL2 bit46 */
			{40389,35,1}, /* core0 sp_EL2 bit47 */
			{40447,35,1}, /* core0 sp_EL2 bit48 */
			{40460,35,1}, /* core0 sp_EL2 bit49 */
			{34422,34,0}, /* core0 sp_EL2 bit50 */
			{34421,34,0}, /* core0 sp_EL2 bit51 */
			{34420,34,0}, /* core0 sp_EL2 bit52 */
			{34419,34,0}, /* core0 sp_EL2 bit53 */
			{34416,34,0}, /* core0 sp_EL2 bit54 */
			{34415,34,0}, /* core0 sp_EL2 bit55 */
			{34400,34,0}, /* core0 sp_EL2 bit56 */
			{34399,34,0}, /* core0 sp_EL2 bit57 */
			{34396,34,0}, /* core0 sp_EL2 bit58 */
			{34395,34,0}, /* core0 sp_EL2 bit59 */
			{36728,34,0}, /* core0 sp_EL2 bit60 */
			{36727,34,0}, /* core0 sp_EL2 bit61 */
			{36726,34,0}, /* core0 sp_EL2 bit62 */
			{36725,34,0}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40272,35,1}, /* core0 sp_EL3 bit0 */
			{40289,35,1}, /* core0 sp_EL3 bit1 */
			{40277,35,1}, /* core0 sp_EL3 bit2 */
			{40279,35,1}, /* core0 sp_EL3 bit3 */
			{40281,35,1}, /* core0 sp_EL3 bit4 */
			{40280,35,1}, /* core0 sp_EL3 bit5 */
			{34280,34,0}, /* core0 sp_EL3 bit6 */
			{34279,34,0}, /* core0 sp_EL3 bit7 */
			{40278,35,1}, /* core0 sp_EL3 bit8 */
			{40276,35,1}, /* core0 sp_EL3 bit9 */
			{40290,35,1}, /* core0 sp_EL3 bit10 */
			{40292,35,1}, /* core0 sp_EL3 bit11 */
			{34282,34,0}, /* core0 sp_EL3 bit12 */
			{34281,34,0}, /* core0 sp_EL3 bit13 */
			{40288,35,1}, /* core0 sp_EL3 bit14 */
			{40287,35,1}, /* core0 sp_EL3 bit15 */
			{40300,35,1}, /* core0 sp_EL3 bit16 */
			{40301,35,1}, /* core0 sp_EL3 bit17 */
			{40291,35,1}, /* core0 sp_EL3 bit18 */
			{40299,35,1}, /* core0 sp_EL3 bit19 */
			{40297,35,1}, /* core0 sp_EL3 bit20 */
			{40298,35,1}, /* core0 sp_EL3 bit21 */
			{40271,35,1}, /* core0 sp_EL3 bit22 */
			{40294,35,1}, /* core0 sp_EL3 bit23 */
			{40295,35,1}, /* core0 sp_EL3 bit24 */
			{40296,35,1}, /* core0 sp_EL3 bit25 */
			{40275,35,1}, /* core0 sp_EL3 bit26 */
			{40274,35,1}, /* core0 sp_EL3 bit27 */
			{40273,35,1}, /* core0 sp_EL3 bit28 */
			{40270,35,1}, /* core0 sp_EL3 bit29 */
			{40269,35,1}, /* core0 sp_EL3 bit30 */
			{40293,35,1}, /* core0 sp_EL3 bit31 */
			{40393,35,1}, /* core0 sp_EL3 bit32 */
			{40392,35,1}, /* core0 sp_EL3 bit33 */
			{40391,35,1}, /* core0 sp_EL3 bit34 */
			{40396,35,1}, /* core0 sp_EL3 bit35 */
			{40425,35,1}, /* core0 sp_EL3 bit36 */
			{40423,35,1}, /* core0 sp_EL3 bit37 */
			{40395,35,1}, /* core0 sp_EL3 bit38 */
			{40426,35,1}, /* core0 sp_EL3 bit39 */
			{40397,35,1}, /* core0 sp_EL3 bit40 */
			{40399,35,1}, /* core0 sp_EL3 bit41 */
			{40424,35,1}, /* core0 sp_EL3 bit42 */
			{40398,35,1}, /* core0 sp_EL3 bit43 */
			{40394,35,1}, /* core0 sp_EL3 bit44 */
			{40435,35,1}, /* core0 sp_EL3 bit45 */
			{40377,35,1}, /* core0 sp_EL3 bit46 */
			{40390,35,1}, /* core0 sp_EL3 bit47 */
			{40458,35,1}, /* core0 sp_EL3 bit48 */
			{40457,35,1}, /* core0 sp_EL3 bit49 */
			{34418,34,0}, /* core0 sp_EL3 bit50 */
			{34417,34,0}, /* core0 sp_EL3 bit51 */
			{36776,34,0}, /* core0 sp_EL3 bit52 */
			{36775,34,0}, /* core0 sp_EL3 bit53 */
			{36774,34,0}, /* core0 sp_EL3 bit54 */
			{36773,34,0}, /* core0 sp_EL3 bit55 */
			{36692,34,0}, /* core0 sp_EL3 bit56 */
			{36691,34,0}, /* core0 sp_EL3 bit57 */
			{36690,34,0}, /* core0 sp_EL3 bit58 */
			{36689,34,0}, /* core0 sp_EL3 bit59 */
			{40375,35,1}, /* core0 sp_EL3 bit60 */
			{40374,35,1}, /* core0 sp_EL3 bit61 */
			{34388,34,0}, /* core0 sp_EL3 bit62 */
			{34387,34,0}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{39606,34,0}, /* core0 elr_EL1 bit0 */
			{39605,34,0}, /* core0 elr_EL1 bit1 */
			{39604,34,0}, /* core0 elr_EL1 bit2 */
			{39603,34,0}, /* core0 elr_EL1 bit3 */
			{39602,34,0}, /* core0 elr_EL1 bit4 */
			{39601,34,0}, /* core0 elr_EL1 bit5 */
			{39600,34,0}, /* core0 elr_EL1 bit6 */
			{39599,34,0}, /* core0 elr_EL1 bit7 */
			{34224,34,0}, /* core0 elr_EL1 bit8 */
			{34223,34,0}, /* core0 elr_EL1 bit9 */
			{34218,34,0}, /* core0 elr_EL1 bit10 */
			{34217,34,0}, /* core0 elr_EL1 bit11 */
			{34222,34,0}, /* core0 elr_EL1 bit12 */
			{34221,34,0}, /* core0 elr_EL1 bit13 */
			{34220,34,0}, /* core0 elr_EL1 bit14 */
			{34219,34,0}, /* core0 elr_EL1 bit15 */
			{39654,34,0}, /* core0 elr_EL1 bit16 */
			{39653,34,0}, /* core0 elr_EL1 bit17 */
			{39652,34,0}, /* core0 elr_EL1 bit18 */
			{39651,34,0}, /* core0 elr_EL1 bit19 */
			{39650,34,0}, /* core0 elr_EL1 bit20 */
			{39649,34,0}, /* core0 elr_EL1 bit21 */
			{39648,34,0}, /* core0 elr_EL1 bit22 */
			{39647,34,0}, /* core0 elr_EL1 bit23 */
			{39638,34,0}, /* core0 elr_EL1 bit24 */
			{39637,34,0}, /* core0 elr_EL1 bit25 */
			{39636,34,0}, /* core0 elr_EL1 bit26 */
			{39635,34,0}, /* core0 elr_EL1 bit27 */
			{39634,34,0}, /* core0 elr_EL1 bit28 */
			{39633,34,0}, /* core0 elr_EL1 bit29 */
			{39632,34,0}, /* core0 elr_EL1 bit30 */
			{39631,34,0}, /* core0 elr_EL1 bit31 */
			{36720,34,0}, /* core0 elr_EL1 bit32 */
			{36724,34,0}, /* core0 elr_EL1 bit33 */
			{36723,34,0}, /* core0 elr_EL1 bit34 */
			{36719,34,0}, /* core0 elr_EL1 bit35 */
			{36722,34,0}, /* core0 elr_EL1 bit36 */
			{36721,34,0}, /* core0 elr_EL1 bit37 */
			{36716,34,0}, /* core0 elr_EL1 bit38 */
			{36718,34,0}, /* core0 elr_EL1 bit39 */
			{36715,34,0}, /* core0 elr_EL1 bit40 */
			{36714,34,0}, /* core0 elr_EL1 bit41 */
			{39440,34,0}, /* core0 elr_EL1 bit42 */
			{39439,34,0}, /* core0 elr_EL1 bit43 */
			{39438,34,0}, /* core0 elr_EL1 bit44 */
			{36717,34,0}, /* core0 elr_EL1 bit45 */
			{39437,34,0}, /* core0 elr_EL1 bit46 */
			{39436,34,0}, /* core0 elr_EL1 bit47 */
			{36796,34,0}, /* core0 elr_EL1 bit48 */
			{39435,34,0}, /* core0 elr_EL1 bit49 */
			{36795,34,0}, /* core0 elr_EL1 bit50 */
			{36794,34,0}, /* core0 elr_EL1 bit51 */
			{36793,34,0}, /* core0 elr_EL1 bit52 */
			{36792,34,0}, /* core0 elr_EL1 bit53 */
			{39434,34,0}, /* core0 elr_EL1 bit54 */
			{39433,34,0}, /* core0 elr_EL1 bit55 */
			{36791,34,0}, /* core0 elr_EL1 bit56 */
			{36790,34,0}, /* core0 elr_EL1 bit57 */
			{36789,34,0}, /* core0 elr_EL1 bit58 */
			{34394,34,0}, /* core0 elr_EL1 bit59 */
			{36713,34,0}, /* core0 elr_EL1 bit60 */
			{34393,34,0}, /* core0 elr_EL1 bit61 */
			{34390,34,0}, /* core0 elr_EL1 bit62 */
			{34389,34,0}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{39614,34,0}, /* core0 elr_EL2 bit0 */
			{39613,34,0}, /* core0 elr_EL2 bit1 */
			{39612,34,0}, /* core0 elr_EL2 bit2 */
			{39611,34,0}, /* core0 elr_EL2 bit3 */
			{39610,34,0}, /* core0 elr_EL2 bit4 */
			{39609,34,0}, /* core0 elr_EL2 bit5 */
			{39608,34,0}, /* core0 elr_EL2 bit6 */
			{39607,34,0}, /* core0 elr_EL2 bit7 */
			{39622,34,0}, /* core0 elr_EL2 bit8 */
			{39621,34,0}, /* core0 elr_EL2 bit9 */
			{39620,34,0}, /* core0 elr_EL2 bit10 */
			{39619,34,0}, /* core0 elr_EL2 bit11 */
			{39618,34,0}, /* core0 elr_EL2 bit12 */
			{39617,34,0}, /* core0 elr_EL2 bit13 */
			{39616,34,0}, /* core0 elr_EL2 bit14 */
			{39615,34,0}, /* core0 elr_EL2 bit15 */
			{39646,34,0}, /* core0 elr_EL2 bit16 */
			{39645,34,0}, /* core0 elr_EL2 bit17 */
			{39644,34,0}, /* core0 elr_EL2 bit18 */
			{39643,34,0}, /* core0 elr_EL2 bit19 */
			{39642,34,0}, /* core0 elr_EL2 bit20 */
			{39641,34,0}, /* core0 elr_EL2 bit21 */
			{39640,34,0}, /* core0 elr_EL2 bit22 */
			{39639,34,0}, /* core0 elr_EL2 bit23 */
			{39630,34,0}, /* core0 elr_EL2 bit24 */
			{39629,34,0}, /* core0 elr_EL2 bit25 */
			{39628,34,0}, /* core0 elr_EL2 bit26 */
			{39627,34,0}, /* core0 elr_EL2 bit27 */
			{39626,34,0}, /* core0 elr_EL2 bit28 */
			{39625,34,0}, /* core0 elr_EL2 bit29 */
			{39624,34,0}, /* core0 elr_EL2 bit30 */
			{39623,34,0}, /* core0 elr_EL2 bit31 */
			{39432,34,0}, /* core0 elr_EL2 bit32 */
			{36712,34,0}, /* core0 elr_EL2 bit33 */
			{36711,34,0}, /* core0 elr_EL2 bit34 */
			{39431,34,0}, /* core0 elr_EL2 bit35 */
			{39430,34,0}, /* core0 elr_EL2 bit36 */
			{39429,34,0}, /* core0 elr_EL2 bit37 */
			{36710,34,0}, /* core0 elr_EL2 bit38 */
			{39428,34,0}, /* core0 elr_EL2 bit39 */
			{36709,34,0}, /* core0 elr_EL2 bit40 */
			{36708,34,0}, /* core0 elr_EL2 bit41 */
			{39427,34,0}, /* core0 elr_EL2 bit42 */
			{36707,34,0}, /* core0 elr_EL2 bit43 */
			{36706,34,0}, /* core0 elr_EL2 bit44 */
			{39426,34,0}, /* core0 elr_EL2 bit45 */
			{39425,34,0}, /* core0 elr_EL2 bit46 */
			{36705,34,0}, /* core0 elr_EL2 bit47 */
			{36788,34,0}, /* core0 elr_EL2 bit48 */
			{36787,34,0}, /* core0 elr_EL2 bit49 */
			{36786,34,0}, /* core0 elr_EL2 bit50 */
			{36785,34,0}, /* core0 elr_EL2 bit51 */
			{36784,34,0}, /* core0 elr_EL2 bit52 */
			{36783,34,0}, /* core0 elr_EL2 bit53 */
			{36782,34,0}, /* core0 elr_EL2 bit54 */
			{36781,34,0}, /* core0 elr_EL2 bit55 */
			{36780,34,0}, /* core0 elr_EL2 bit56 */
			{36779,34,0}, /* core0 elr_EL2 bit57 */
			{36778,34,0}, /* core0 elr_EL2 bit58 */
			{36777,34,0}, /* core0 elr_EL2 bit59 */
			{36704,34,0}, /* core0 elr_EL2 bit60 */
			{36703,34,0}, /* core0 elr_EL2 bit61 */
			{36702,34,0}, /* core0 elr_EL2 bit62 */
			{36701,34,0}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{34228,34,0}, /* core0 elr_EL3 bit0 */
			{34227,34,0}, /* core0 elr_EL3 bit1 */
			{40317,35,1}, /* core0 elr_EL3 bit2 */
			{40318,35,1}, /* core0 elr_EL3 bit3 */
			{36912,34,0}, /* core0 elr_EL3 bit4 */
			{36911,34,0}, /* core0 elr_EL3 bit5 */
			{36910,34,0}, /* core0 elr_EL3 bit6 */
			{36909,34,0}, /* core0 elr_EL3 bit7 */
			{34232,34,0}, /* core0 elr_EL3 bit8 */
			{34231,34,0}, /* core0 elr_EL3 bit9 */
			{40339,35,1}, /* core0 elr_EL3 bit10 */
			{40351,35,1}, /* core0 elr_EL3 bit11 */
			{34230,34,0}, /* core0 elr_EL3 bit12 */
			{34229,34,0}, /* core0 elr_EL3 bit13 */
			{40326,35,1}, /* core0 elr_EL3 bit14 */
			{40328,35,1}, /* core0 elr_EL3 bit15 */
			{40352,35,1}, /* core0 elr_EL3 bit16 */
			{40353,35,1}, /* core0 elr_EL3 bit17 */
			{40354,35,1}, /* core0 elr_EL3 bit18 */
			{40344,35,1}, /* core0 elr_EL3 bit19 */
			{40342,35,1}, /* core0 elr_EL3 bit20 */
			{40341,35,1}, /* core0 elr_EL3 bit21 */
			{40327,35,1}, /* core0 elr_EL3 bit22 */
			{40338,35,1}, /* core0 elr_EL3 bit23 */
			{40340,35,1}, /* core0 elr_EL3 bit24 */
			{40343,35,1}, /* core0 elr_EL3 bit25 */
			{40323,35,1}, /* core0 elr_EL3 bit26 */
			{40322,35,1}, /* core0 elr_EL3 bit27 */
			{40324,35,1}, /* core0 elr_EL3 bit28 */
			{40325,35,1}, /* core0 elr_EL3 bit29 */
			{40329,35,1}, /* core0 elr_EL3 bit30 */
			{40337,35,1}, /* core0 elr_EL3 bit31 */
			{34382,34,0}, /* core0 elr_EL3 bit32 */
			{34381,34,0}, /* core0 elr_EL3 bit33 */
			{40368,35,1}, /* core0 elr_EL3 bit34 */
			{40364,35,1}, /* core0 elr_EL3 bit35 */
			{40380,35,1}, /* core0 elr_EL3 bit36 */
			{40372,35,1}, /* core0 elr_EL3 bit37 */
			{40365,35,1}, /* core0 elr_EL3 bit38 */
			{40376,35,1}, /* core0 elr_EL3 bit39 */
			{40369,35,1}, /* core0 elr_EL3 bit40 */
			{40367,35,1}, /* core0 elr_EL3 bit41 */
			{40373,35,1}, /* core0 elr_EL3 bit42 */
			{40371,35,1}, /* core0 elr_EL3 bit43 */
			{40381,35,1}, /* core0 elr_EL3 bit44 */
			{40366,35,1}, /* core0 elr_EL3 bit45 */
			{40370,35,1}, /* core0 elr_EL3 bit46 */
			{40382,35,1}, /* core0 elr_EL3 bit47 */
			{34402,34,0}, /* core0 elr_EL3 bit48 */
			{34401,34,0}, /* core0 elr_EL3 bit49 */
			{36772,34,0}, /* core0 elr_EL3 bit50 */
			{36771,34,0}, /* core0 elr_EL3 bit51 */
			{34414,34,0}, /* core0 elr_EL3 bit52 */
			{36770,34,0}, /* core0 elr_EL3 bit53 */
			{34413,34,0}, /* core0 elr_EL3 bit54 */
			{36769,34,0}, /* core0 elr_EL3 bit55 */
			{36688,34,0}, /* core0 elr_EL3 bit56 */
			{36687,34,0}, /* core0 elr_EL3 bit57 */
			{36686,34,0}, /* core0 elr_EL3 bit58 */
			{36685,34,0}, /* core0 elr_EL3 bit59 */
			{34384,34,0}, /* core0 elr_EL3 bit60 */
			{34383,34,0}, /* core0 elr_EL3 bit61 */
			{34196,34,0}, /* core0 elr_EL3 bit62 */
			{34195,34,0}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{35631,34,0}, /* core0 raw_pc bit0 */
			{35630,34,0}, /* core0 raw_pc bit1 */
			{38290,34,0}, /* core0 raw_pc bit2 */
			{38289,34,0}, /* core0 raw_pc bit3 */
			{38288,34,0}, /* core0 raw_pc bit4 */
			{38287,34,0}, /* core0 raw_pc bit5 */
			{32560,34,1}, /* core0 raw_pc bit6 */
			{38278,34,0}, /* core0 raw_pc bit7 */
			{38277,34,0}, /* core0 raw_pc bit8 */
			{38276,34,0}, /* core0 raw_pc bit9 */
			{38275,34,0}, /* core0 raw_pc bit10 */
			{35637,34,0}, /* core0 raw_pc bit11 */
			{35636,34,0}, /* core0 raw_pc bit12 */
			{35635,34,0}, /* core0 raw_pc bit13 */
			{35634,34,0}, /* core0 raw_pc bit14 */
			{38282,34,0}, /* core0 raw_pc bit15 */
			{38281,34,0}, /* core0 raw_pc bit16 */
			{38280,34,0}, /* core0 raw_pc bit17 */
			{38279,34,0}, /* core0 raw_pc bit18 */
			{35641,34,0}, /* core0 raw_pc bit19 */
			{35640,34,0}, /* core0 raw_pc bit20 */
			{32562,34,1}, /* core0 raw_pc bit21 */
			{32561,34,1}, /* core0 raw_pc bit22 */
			{38286,34,0}, /* core0 raw_pc bit23 */
			{38285,34,0}, /* core0 raw_pc bit24 */
			{38284,34,0}, /* core0 raw_pc bit25 */
			{38283,34,0}, /* core0 raw_pc bit26 */
			{35633,34,0}, /* core0 raw_pc bit27 */
			{35632,34,0}, /* core0 raw_pc bit28 */
			{35639,34,0}, /* core0 raw_pc bit29 */
			{35638,34,0}, /* core0 raw_pc bit30 */
			{38274,34,0}, /* core0 raw_pc bit31 */
			{38273,34,0}, /* core0 raw_pc bit32 */
			{38272,34,0}, /* core0 raw_pc bit33 */
			{38271,34,0}, /* core0 raw_pc bit34 */
			{40754,34,0}, /* core0 raw_pc bit35 */
			{40753,34,0}, /* core0 raw_pc bit36 */
			{40752,34,0}, /* core0 raw_pc bit37 */
			{40751,34,0}, /* core0 raw_pc bit38 */
			{35645,34,0}, /* core0 raw_pc bit39 */
			{35644,34,0}, /* core0 raw_pc bit40 */
			{40750,34,0}, /* core0 raw_pc bit41 */
			{40749,34,0}, /* core0 raw_pc bit42 */
			{35647,34,0}, /* core0 raw_pc bit43 */
			{35646,34,0}, /* core0 raw_pc bit44 */
			{40748,34,0}, /* core0 raw_pc bit45 */
			{40747,34,0}, /* core0 raw_pc bit46 */
			{32577,34,1}, /* core0 raw_pc bit47 */
			{32578,34,1}, /* core0 raw_pc bit48 */
			{32579,34,1}, /* core0 raw_pc bit49 */
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
			{32555,34,1}, /* core0 pc_iss bit0 */
			{32637,34,1}, /* core0 pc_iss bit1 */
			{32634,34,1}, /* core0 pc_iss bit2 */
			{32633,34,1}, /* core0 pc_iss bit3 */
			{32635,34,1}, /* core0 pc_iss bit4 */
			{32554,34,1}, /* core0 pc_iss bit5 */
			{32556,34,1}, /* core0 pc_iss bit6 */
			{32636,34,1}, /* core0 pc_iss bit7 */
			{32610,34,1}, /* core0 pc_iss bit8 */
			{32603,34,1}, /* core0 pc_iss bit9 */
			{32632,34,1}, /* core0 pc_iss bit10 */
			{32631,34,1}, /* core0 pc_iss bit11 */
			{32629,34,1}, /* core0 pc_iss bit12 */
			{32630,34,1}, /* core0 pc_iss bit13 */
			{32628,34,1}, /* core0 pc_iss bit14 */
			{32614,34,1}, /* core0 pc_iss bit15 */
			{32615,34,1}, /* core0 pc_iss bit16 */
			{32627,34,1}, /* core0 pc_iss bit17 */
			{32624,34,1}, /* core0 pc_iss bit18 */
			{32617,34,1}, /* core0 pc_iss bit19 */
			{32625,34,1}, /* core0 pc_iss bit20 */
			{32626,34,1}, /* core0 pc_iss bit21 */
			{32611,34,1}, /* core0 pc_iss bit22 */
			{32618,34,1}, /* core0 pc_iss bit23 */
			{32622,34,1}, /* core0 pc_iss bit24 */
			{32621,34,1}, /* core0 pc_iss bit25 */
			{32619,34,1}, /* core0 pc_iss bit26 */
			{32612,34,1}, /* core0 pc_iss bit27 */
			{32613,34,1}, /* core0 pc_iss bit28 */
			{32620,34,1}, /* core0 pc_iss bit29 */
			{32616,34,1}, /* core0 pc_iss bit30 */
			{32623,34,1}, /* core0 pc_iss bit31 */
			{32573,34,1}, /* core0 pc_iss bit32 */
			{32574,34,1}, /* core0 pc_iss bit33 */
			{32563,34,1}, /* core0 pc_iss bit34 */
			{32564,34,1}, /* core0 pc_iss bit35 */
			{32570,34,1}, /* core0 pc_iss bit36 */
			{32566,34,1}, /* core0 pc_iss bit37 */
			{32571,34,1}, /* core0 pc_iss bit38 */
			{32565,34,1}, /* core0 pc_iss bit39 */
			{32572,34,1}, /* core0 pc_iss bit40 */
			{32568,34,1}, /* core0 pc_iss bit41 */
			{32567,34,1}, /* core0 pc_iss bit42 */
			{32569,34,1}, /* core0 pc_iss bit43 */
			{35685,34,0}, /* core0 pc_iss bit44 */
			{35684,34,0}, /* core0 pc_iss bit45 */
			{35683,34,0}, /* core0 pc_iss bit46 */
			{35682,34,0}, /* core0 pc_iss bit47 */
			{38270,34,0}, /* core0 pc_iss bit48 */
			{38269,34,0}, /* core0 pc_iss bit49 */
			{38268,34,0}, /* core0 pc_iss bit50 */
			{38267,34,0}, /* core0 pc_iss bit51 */
			{38266,34,0}, /* core0 pc_iss bit52 */
			{38265,34,0}, /* core0 pc_iss bit53 */
			{38264,34,0}, /* core0 pc_iss bit54 */
			{38263,34,0}, /* core0 pc_iss bit55 */
			{40956,34,0}, /* core0 pc_iss bit56 */
			{40955,34,0}, /* core0 pc_iss bit57 */
			{40954,34,0}, /* core0 pc_iss bit58 */
			{40953,34,0}, /* core0 pc_iss bit59 */
			{40952,34,0}, /* core0 pc_iss bit60 */
			{40951,34,0}, /* core0 pc_iss bit61 */
			{40950,34,0}, /* core0 pc_iss bit62 */
			{40949,34,0}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{32557,34,1}, /* core0 full_pc_wr bit0 */
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
			{41124,34,0}, /* core0 full_pc_ex1 bit0 */
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
			{41116,34,0}, /* core0 full_pc_ex2 bit0 */
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
			{25953,35,1}, /* core0 return_Stack_pointer bit0 */
			{28673,35,1}, /* core0 return_Stack_pointer bit1 */
			{28674,35,1}, /* core0 return_Stack_pointer bit2 */
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
			{32644,35,1}, /* core0 return_Stack0 bit0 */
			{32643,35,1}, /* core0 return_Stack0 bit1 */
			{32672,35,1}, /* core0 return_Stack0 bit2 */
			{32671,35,1}, /* core0 return_Stack0 bit3 */
			{32670,35,1}, /* core0 return_Stack0 bit4 */
			{32669,35,1}, /* core0 return_Stack0 bit5 */
			{28860,35,1}, /* core0 return_Stack0 bit6 */
			{28859,35,1}, /* core0 return_Stack0 bit7 */
			{28858,35,1}, /* core0 return_Stack0 bit8 */
			{28857,35,1}, /* core0 return_Stack0 bit9 */
			{37875,35,1}, /* core0 return_Stack0 bit10 */
			{37874,35,1}, /* core0 return_Stack0 bit11 */
			{37873,35,1}, /* core0 return_Stack0 bit12 */
			{37872,35,1}, /* core0 return_Stack0 bit13 */
			{37871,35,1}, /* core0 return_Stack0 bit14 */
			{37870,35,1}, /* core0 return_Stack0 bit15 */
			{37869,35,1}, /* core0 return_Stack0 bit16 */
			{32642,35,1}, /* core0 return_Stack0 bit17 */
			{37868,35,1}, /* core0 return_Stack0 bit18 */
			{32648,35,1}, /* core0 return_Stack0 bit19 */
			{32647,35,1}, /* core0 return_Stack0 bit20 */
			{32646,35,1}, /* core0 return_Stack0 bit21 */
			{32645,35,1}, /* core0 return_Stack0 bit22 */
			{32641,35,1}, /* core0 return_Stack0 bit23 */
			{26154,35,1}, /* core0 return_Stack0 bit24 */
			{26153,35,1}, /* core0 return_Stack0 bit25 */
			{28780,35,1}, /* core0 return_Stack0 bit26 */
			{28779,35,1}, /* core0 return_Stack0 bit27 */
			{32656,35,1}, /* core0 return_Stack0 bit28 */
			{32655,35,1}, /* core0 return_Stack0 bit29 */
			{32654,35,1}, /* core0 return_Stack0 bit30 */
			{26152,35,1}, /* core0 return_Stack0 bit31 */
			{32653,35,1}, /* core0 return_Stack0 bit32 */
			{28770,35,1}, /* core0 return_Stack0 bit33 */
			{28769,35,1}, /* core0 return_Stack0 bit34 */
			{25973,35,1}, /* core0 return_Stack0 bit35 */
			{28772,35,1}, /* core0 return_Stack0 bit36 */
			{28771,35,1}, /* core0 return_Stack0 bit37 */
			{32832,35,1}, /* core0 return_Stack0 bit38 */
			{32831,35,1}, /* core0 return_Stack0 bit39 */
			{32830,35,1}, /* core0 return_Stack0 bit40 */
			{32829,35,1}, /* core0 return_Stack0 bit41 */
			{25972,35,1}, /* core0 return_Stack0 bit42 */
			{28774,35,1}, /* core0 return_Stack0 bit43 */
			{28773,35,1}, /* core0 return_Stack0 bit44 */
			{28776,35,1}, /* core0 return_Stack0 bit45 */
			{28775,35,1}, /* core0 return_Stack0 bit46 */
			{28778,35,1}, /* core0 return_Stack0 bit47 */
			{28777,35,1}, /* core0 return_Stack0 bit48 */
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
			{28812,35,1}, /* core0 return_Stack1 bit0 */
			{28811,35,1}, /* core0 return_Stack1 bit1 */
			{32716,35,1}, /* core0 return_Stack1 bit2 */
			{32715,35,1}, /* core0 return_Stack1 bit3 */
			{32720,35,1}, /* core0 return_Stack1 bit4 */
			{32719,35,1}, /* core0 return_Stack1 bit5 */
			{32718,35,1}, /* core0 return_Stack1 bit6 */
			{32717,35,1}, /* core0 return_Stack1 bit7 */
			{28818,35,1}, /* core0 return_Stack1 bit8 */
			{28817,35,1}, /* core0 return_Stack1 bit9 */
			{32714,35,1}, /* core0 return_Stack1 bit10 */
			{32713,35,1}, /* core0 return_Stack1 bit11 */
			{32724,35,1}, /* core0 return_Stack1 bit12 */
			{32723,35,1}, /* core0 return_Stack1 bit13 */
			{32722,35,1}, /* core0 return_Stack1 bit14 */
			{32721,35,1}, /* core0 return_Stack1 bit15 */
			{28820,35,1}, /* core0 return_Stack1 bit16 */
			{28819,35,1}, /* core0 return_Stack1 bit17 */
			{28816,35,1}, /* core0 return_Stack1 bit18 */
			{28815,35,1}, /* core0 return_Stack1 bit19 */
			{28814,35,1}, /* core0 return_Stack1 bit20 */
			{28813,35,1}, /* core0 return_Stack1 bit21 */
			{26163,35,1}, /* core0 return_Stack1 bit22 */
			{26165,35,1}, /* core0 return_Stack1 bit23 */
			{26164,35,1}, /* core0 return_Stack1 bit24 */
			{32736,35,1}, /* core0 return_Stack1 bit25 */
			{32735,35,1}, /* core0 return_Stack1 bit26 */
			{32734,35,1}, /* core0 return_Stack1 bit27 */
			{32733,35,1}, /* core0 return_Stack1 bit28 */
			{28810,35,1}, /* core0 return_Stack1 bit29 */
			{28809,35,1}, /* core0 return_Stack1 bit30 */
			{26166,35,1}, /* core0 return_Stack1 bit31 */
			{28808,35,1}, /* core0 return_Stack1 bit32 */
			{28806,35,1}, /* core0 return_Stack1 bit33 */
			{28805,35,1}, /* core0 return_Stack1 bit34 */
			{28807,35,1}, /* core0 return_Stack1 bit35 */
			{26167,35,1}, /* core0 return_Stack1 bit36 */
			{32784,35,1}, /* core0 return_Stack1 bit37 */
			{32783,35,1}, /* core0 return_Stack1 bit38 */
			{32782,35,1}, /* core0 return_Stack1 bit39 */
			{32781,35,1}, /* core0 return_Stack1 bit40 */
			{32788,35,1}, /* core0 return_Stack1 bit41 */
			{32787,35,1}, /* core0 return_Stack1 bit42 */
			{32786,35,1}, /* core0 return_Stack1 bit43 */
			{32785,35,1}, /* core0 return_Stack1 bit44 */
			{32792,35,1}, /* core0 return_Stack1 bit45 */
			{32791,35,1}, /* core0 return_Stack1 bit46 */
			{32790,35,1}, /* core0 return_Stack1 bit47 */
			{32789,35,1}, /* core0 return_Stack1 bit48 */
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
			{28856,35,1}, /* core0 return_Stack2 bit0 */
			{28855,35,1}, /* core0 return_Stack2 bit1 */
			{28854,35,1}, /* core0 return_Stack2 bit2 */
			{28853,35,1}, /* core0 return_Stack2 bit3 */
			{32676,35,1}, /* core0 return_Stack2 bit4 */
			{32675,35,1}, /* core0 return_Stack2 bit5 */
			{32674,35,1}, /* core0 return_Stack2 bit6 */
			{32673,35,1}, /* core0 return_Stack2 bit7 */
			{32680,35,1}, /* core0 return_Stack2 bit8 */
			{32679,35,1}, /* core0 return_Stack2 bit9 */
			{32678,35,1}, /* core0 return_Stack2 bit10 */
			{32677,35,1}, /* core0 return_Stack2 bit11 */
			{28846,35,1}, /* core0 return_Stack2 bit12 */
			{28845,35,1}, /* core0 return_Stack2 bit13 */
			{28848,35,1}, /* core0 return_Stack2 bit14 */
			{28847,35,1}, /* core0 return_Stack2 bit15 */
			{28852,35,1}, /* core0 return_Stack2 bit16 */
			{28851,35,1}, /* core0 return_Stack2 bit17 */
			{28844,35,1}, /* core0 return_Stack2 bit18 */
			{28843,35,1}, /* core0 return_Stack2 bit19 */
			{28850,35,1}, /* core0 return_Stack2 bit20 */
			{28849,35,1}, /* core0 return_Stack2 bit21 */
			{26155,35,1}, /* core0 return_Stack2 bit22 */
			{26156,35,1}, /* core0 return_Stack2 bit23 */
			{26157,35,1}, /* core0 return_Stack2 bit24 */
			{32652,35,1}, /* core0 return_Stack2 bit25 */
			{32651,35,1}, /* core0 return_Stack2 bit26 */
			{32650,35,1}, /* core0 return_Stack2 bit27 */
			{32649,35,1}, /* core0 return_Stack2 bit28 */
			{32756,35,1}, /* core0 return_Stack2 bit29 */
			{32755,35,1}, /* core0 return_Stack2 bit30 */
			{32754,35,1}, /* core0 return_Stack2 bit31 */
			{32753,35,1}, /* core0 return_Stack2 bit32 */
			{32824,35,1}, /* core0 return_Stack2 bit33 */
			{32823,35,1}, /* core0 return_Stack2 bit34 */
			{32822,35,1}, /* core0 return_Stack2 bit35 */
			{32821,35,1}, /* core0 return_Stack2 bit36 */
			{32820,35,1}, /* core0 return_Stack2 bit37 */
			{32819,35,1}, /* core0 return_Stack2 bit38 */
			{32818,35,1}, /* core0 return_Stack2 bit39 */
			{32817,35,1}, /* core0 return_Stack2 bit40 */
			{32828,35,1}, /* core0 return_Stack2 bit41 */
			{32827,35,1}, /* core0 return_Stack2 bit42 */
			{32826,35,1}, /* core0 return_Stack2 bit43 */
			{32825,35,1}, /* core0 return_Stack2 bit44 */
			{32760,35,1}, /* core0 return_Stack2 bit45 */
			{32759,35,1}, /* core0 return_Stack2 bit46 */
			{32758,35,1}, /* core0 return_Stack2 bit47 */
			{32757,35,1}, /* core0 return_Stack2 bit48 */
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
			{28802,35,1}, /* core0 return_Stack3 bit0 */
			{28801,35,1}, /* core0 return_Stack3 bit1 */
			{28824,35,1}, /* core0 return_Stack3 bit2 */
			{28826,35,1}, /* core0 return_Stack3 bit3 */
			{28825,35,1}, /* core0 return_Stack3 bit4 */
			{28822,35,1}, /* core0 return_Stack3 bit5 */
			{28821,35,1}, /* core0 return_Stack3 bit6 */
			{28796,35,1}, /* core0 return_Stack3 bit7 */
			{28795,35,1}, /* core0 return_Stack3 bit8 */
			{28823,35,1}, /* core0 return_Stack3 bit9 */
			{28798,35,1}, /* core0 return_Stack3 bit10 */
			{28830,35,1}, /* core0 return_Stack3 bit11 */
			{28829,35,1}, /* core0 return_Stack3 bit12 */
			{28828,35,1}, /* core0 return_Stack3 bit13 */
			{28827,35,1}, /* core0 return_Stack3 bit14 */
			{32708,35,1}, /* core0 return_Stack3 bit15 */
			{28800,35,1}, /* core0 return_Stack3 bit16 */
			{28799,35,1}, /* core0 return_Stack3 bit17 */
			{32707,35,1}, /* core0 return_Stack3 bit18 */
			{32706,35,1}, /* core0 return_Stack3 bit19 */
			{32705,35,1}, /* core0 return_Stack3 bit20 */
			{28797,35,1}, /* core0 return_Stack3 bit21 */
			{26158,35,1}, /* core0 return_Stack3 bit22 */
			{26162,35,1}, /* core0 return_Stack3 bit23 */
			{26159,35,1}, /* core0 return_Stack3 bit24 */
			{26160,35,1}, /* core0 return_Stack3 bit25 */
			{32744,35,1}, /* core0 return_Stack3 bit26 */
			{32743,35,1}, /* core0 return_Stack3 bit27 */
			{32742,35,1}, /* core0 return_Stack3 bit28 */
			{32796,35,1}, /* core0 return_Stack3 bit29 */
			{32741,35,1}, /* core0 return_Stack3 bit30 */
			{32795,35,1}, /* core0 return_Stack3 bit31 */
			{28804,35,1}, /* core0 return_Stack3 bit32 */
			{32794,35,1}, /* core0 return_Stack3 bit33 */
			{32793,35,1}, /* core0 return_Stack3 bit34 */
			{28803,35,1}, /* core0 return_Stack3 bit35 */
			{32776,35,1}, /* core0 return_Stack3 bit36 */
			{32775,35,1}, /* core0 return_Stack3 bit37 */
			{32774,35,1}, /* core0 return_Stack3 bit38 */
			{32780,35,1}, /* core0 return_Stack3 bit39 */
			{32779,35,1}, /* core0 return_Stack3 bit40 */
			{32778,35,1}, /* core0 return_Stack3 bit41 */
			{32777,35,1}, /* core0 return_Stack3 bit42 */
			{32800,35,1}, /* core0 return_Stack3 bit43 */
			{32799,35,1}, /* core0 return_Stack3 bit44 */
			{32798,35,1}, /* core0 return_Stack3 bit45 */
			{32797,35,1}, /* core0 return_Stack3 bit46 */
			{32773,35,1}, /* core0 return_Stack3 bit47 */
			{26161,35,1}, /* core0 return_Stack3 bit48 */
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
			{32664,35,1}, /* core0 return_Stack4 bit0 */
			{32663,35,1}, /* core0 return_Stack4 bit1 */
			{32636,35,1}, /* core0 return_Stack4 bit2 */
			{32635,35,1}, /* core0 return_Stack4 bit3 */
			{28864,35,1}, /* core0 return_Stack4 bit4 */
			{28863,35,1}, /* core0 return_Stack4 bit5 */
			{32640,35,1}, /* core0 return_Stack4 bit6 */
			{32639,35,1}, /* core0 return_Stack4 bit7 */
			{32638,35,1}, /* core0 return_Stack4 bit8 */
			{32637,35,1}, /* core0 return_Stack4 bit9 */
			{32634,35,1}, /* core0 return_Stack4 bit10 */
			{32633,35,1}, /* core0 return_Stack4 bit11 */
			{28862,35,1}, /* core0 return_Stack4 bit12 */
			{28861,35,1}, /* core0 return_Stack4 bit13 */
			{32668,35,1}, /* core0 return_Stack4 bit14 */
			{32667,35,1}, /* core0 return_Stack4 bit15 */
			{32662,35,1}, /* core0 return_Stack4 bit16 */
			{32661,35,1}, /* core0 return_Stack4 bit17 */
			{32666,35,1}, /* core0 return_Stack4 bit18 */
			{32665,35,1}, /* core0 return_Stack4 bit19 */
			{28866,35,1}, /* core0 return_Stack4 bit20 */
			{28865,35,1}, /* core0 return_Stack4 bit21 */
			{28868,35,1}, /* core0 return_Stack4 bit22 */
			{28867,35,1}, /* core0 return_Stack4 bit23 */
			{26150,35,1}, /* core0 return_Stack4 bit24 */
			{26151,35,1}, /* core0 return_Stack4 bit25 */
			{32660,35,1}, /* core0 return_Stack4 bit26 */
			{32659,35,1}, /* core0 return_Stack4 bit27 */
			{32658,35,1}, /* core0 return_Stack4 bit28 */
			{32844,35,1}, /* core0 return_Stack4 bit29 */
			{32843,35,1}, /* core0 return_Stack4 bit30 */
			{32842,35,1}, /* core0 return_Stack4 bit31 */
			{32657,35,1}, /* core0 return_Stack4 bit32 */
			{25971,35,1}, /* core0 return_Stack4 bit33 */
			{32841,35,1}, /* core0 return_Stack4 bit34 */
			{32840,35,1}, /* core0 return_Stack4 bit35 */
			{32839,35,1}, /* core0 return_Stack4 bit36 */
			{32838,35,1}, /* core0 return_Stack4 bit37 */
			{32837,35,1}, /* core0 return_Stack4 bit38 */
			{32836,35,1}, /* core0 return_Stack4 bit39 */
			{32835,35,1}, /* core0 return_Stack4 bit40 */
			{32834,35,1}, /* core0 return_Stack4 bit41 */
			{32833,35,1}, /* core0 return_Stack4 bit42 */
			{25970,35,1}, /* core0 return_Stack4 bit43 */
			{28872,35,1}, /* core0 return_Stack4 bit44 */
			{28871,35,1}, /* core0 return_Stack4 bit45 */
			{28870,35,1}, /* core0 return_Stack4 bit46 */
			{28869,35,1}, /* core0 return_Stack4 bit47 */
			{25969,35,1}, /* core0 return_Stack4 bit48 */
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
			{28790,35,1}, /* core0 return_Stack5 bit0 */
			{28789,35,1}, /* core0 return_Stack5 bit1 */
			{32696,35,1}, /* core0 return_Stack5 bit2 */
			{32695,35,1}, /* core0 return_Stack5 bit3 */
			{28794,35,1}, /* core0 return_Stack5 bit4 */
			{28793,35,1}, /* core0 return_Stack5 bit5 */
			{32692,35,1}, /* core0 return_Stack5 bit6 */
			{32691,35,1}, /* core0 return_Stack5 bit7 */
			{32690,35,1}, /* core0 return_Stack5 bit8 */
			{32689,35,1}, /* core0 return_Stack5 bit9 */
			{32694,35,1}, /* core0 return_Stack5 bit10 */
			{32693,35,1}, /* core0 return_Stack5 bit11 */
			{32700,35,1}, /* core0 return_Stack5 bit12 */
			{32699,35,1}, /* core0 return_Stack5 bit13 */
			{28792,35,1}, /* core0 return_Stack5 bit14 */
			{28791,35,1}, /* core0 return_Stack5 bit15 */
			{28788,35,1}, /* core0 return_Stack5 bit16 */
			{28787,35,1}, /* core0 return_Stack5 bit17 */
			{32698,35,1}, /* core0 return_Stack5 bit18 */
			{32704,35,1}, /* core0 return_Stack5 bit19 */
			{32703,35,1}, /* core0 return_Stack5 bit20 */
			{32702,35,1}, /* core0 return_Stack5 bit21 */
			{32697,35,1}, /* core0 return_Stack5 bit22 */
			{28786,35,1}, /* core0 return_Stack5 bit23 */
			{32701,35,1}, /* core0 return_Stack5 bit24 */
			{28785,35,1}, /* core0 return_Stack5 bit25 */
			{32752,35,1}, /* core0 return_Stack5 bit26 */
			{25968,35,1}, /* core0 return_Stack5 bit27 */
			{32751,35,1}, /* core0 return_Stack5 bit28 */
			{32750,35,1}, /* core0 return_Stack5 bit29 */
			{32749,35,1}, /* core0 return_Stack5 bit30 */
			{32808,35,1}, /* core0 return_Stack5 bit31 */
			{32807,35,1}, /* core0 return_Stack5 bit32 */
			{32806,35,1}, /* core0 return_Stack5 bit33 */
			{32805,35,1}, /* core0 return_Stack5 bit34 */
			{32812,35,1}, /* core0 return_Stack5 bit35 */
			{32811,35,1}, /* core0 return_Stack5 bit36 */
			{32810,35,1}, /* core0 return_Stack5 bit37 */
			{32809,35,1}, /* core0 return_Stack5 bit38 */
			{32804,35,1}, /* core0 return_Stack5 bit39 */
			{32803,35,1}, /* core0 return_Stack5 bit40 */
			{32802,35,1}, /* core0 return_Stack5 bit41 */
			{32801,35,1}, /* core0 return_Stack5 bit42 */
			{32816,35,1}, /* core0 return_Stack5 bit43 */
			{32815,35,1}, /* core0 return_Stack5 bit44 */
			{32814,35,1}, /* core0 return_Stack5 bit45 */
			{32813,35,1}, /* core0 return_Stack5 bit46 */
			{25955,35,1}, /* core0 return_Stack5 bit47 */
			{25956,35,1}, /* core0 return_Stack5 bit48 */
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
			{28784,35,1}, /* core0 return_Stack6 bit0 */
			{28783,35,1}, /* core0 return_Stack6 bit1 */
			{28838,35,1}, /* core0 return_Stack6 bit2 */
			{32688,35,1}, /* core0 return_Stack6 bit3 */
			{28837,35,1}, /* core0 return_Stack6 bit4 */
			{32687,35,1}, /* core0 return_Stack6 bit5 */
			{32686,35,1}, /* core0 return_Stack6 bit6 */
			{32685,35,1}, /* core0 return_Stack6 bit7 */
			{28834,35,1}, /* core0 return_Stack6 bit8 */
			{28833,35,1}, /* core0 return_Stack6 bit9 */
			{32684,35,1}, /* core0 return_Stack6 bit10 */
			{32683,35,1}, /* core0 return_Stack6 bit11 */
			{32682,35,1}, /* core0 return_Stack6 bit12 */
			{32681,35,1}, /* core0 return_Stack6 bit13 */
			{28840,35,1}, /* core0 return_Stack6 bit14 */
			{28839,35,1}, /* core0 return_Stack6 bit15 */
			{28836,35,1}, /* core0 return_Stack6 bit16 */
			{28835,35,1}, /* core0 return_Stack6 bit17 */
			{28842,35,1}, /* core0 return_Stack6 bit18 */
			{28841,35,1}, /* core0 return_Stack6 bit19 */
			{28832,35,1}, /* core0 return_Stack6 bit20 */
			{28831,35,1}, /* core0 return_Stack6 bit21 */
			{25960,35,1}, /* core0 return_Stack6 bit22 */
			{25959,35,1}, /* core0 return_Stack6 bit23 */
			{25967,35,1}, /* core0 return_Stack6 bit24 */
			{25966,35,1}, /* core0 return_Stack6 bit25 */
			{32748,35,1}, /* core0 return_Stack6 bit26 */
			{32747,35,1}, /* core0 return_Stack6 bit27 */
			{28782,35,1}, /* core0 return_Stack6 bit28 */
			{32746,35,1}, /* core0 return_Stack6 bit29 */
			{32745,35,1}, /* core0 return_Stack6 bit30 */
			{28781,35,1}, /* core0 return_Stack6 bit31 */
			{25958,35,1}, /* core0 return_Stack6 bit32 */
			{28680,35,1}, /* core0 return_Stack6 bit33 */
			{28679,35,1}, /* core0 return_Stack6 bit34 */
			{25954,35,1}, /* core0 return_Stack6 bit35 */
			{25957,35,1}, /* core0 return_Stack6 bit36 */
			{28678,35,1}, /* core0 return_Stack6 bit37 */
			{28677,35,1}, /* core0 return_Stack6 bit38 */
			{32764,35,1}, /* core0 return_Stack6 bit39 */
			{32763,35,1}, /* core0 return_Stack6 bit40 */
			{32762,35,1}, /* core0 return_Stack6 bit41 */
			{32761,35,1}, /* core0 return_Stack6 bit42 */
			{28676,35,1}, /* core0 return_Stack6 bit43 */
			{28675,35,1}, /* core0 return_Stack6 bit44 */
			{28664,35,1}, /* core0 return_Stack6 bit45 */
			{28663,35,1}, /* core0 return_Stack6 bit46 */
			{28662,35,1}, /* core0 return_Stack6 bit47 */
			{28661,35,1}, /* core0 return_Stack6 bit48 */
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
			{32712,35,1}, /* core0 return_Stack7 bit0 */
			{32711,35,1}, /* core0 return_Stack7 bit1 */
			{32732,35,1}, /* core0 return_Stack7 bit2 */
			{32731,35,1}, /* core0 return_Stack7 bit3 */
			{32730,35,1}, /* core0 return_Stack7 bit4 */
			{32729,35,1}, /* core0 return_Stack7 bit5 */
			{28652,35,1}, /* core0 return_Stack7 bit6 */
			{28651,35,1}, /* core0 return_Stack7 bit7 */
			{28654,35,1}, /* core0 return_Stack7 bit8 */
			{28653,35,1}, /* core0 return_Stack7 bit9 */
			{32728,35,1}, /* core0 return_Stack7 bit10 */
			{32727,35,1}, /* core0 return_Stack7 bit11 */
			{28650,35,1}, /* core0 return_Stack7 bit12 */
			{28649,35,1}, /* core0 return_Stack7 bit13 */
			{32710,35,1}, /* core0 return_Stack7 bit14 */
			{32726,35,1}, /* core0 return_Stack7 bit15 */
			{32709,35,1}, /* core0 return_Stack7 bit16 */
			{32725,35,1}, /* core0 return_Stack7 bit17 */
			{28656,35,1}, /* core0 return_Stack7 bit18 */
			{28655,35,1}, /* core0 return_Stack7 bit19 */
			{28658,35,1}, /* core0 return_Stack7 bit20 */
			{28657,35,1}, /* core0 return_Stack7 bit21 */
			{25961,35,1}, /* core0 return_Stack7 bit22 */
			{25962,35,1}, /* core0 return_Stack7 bit23 */
			{25963,35,1}, /* core0 return_Stack7 bit24 */
			{25965,35,1}, /* core0 return_Stack7 bit25 */
			{28660,35,1}, /* core0 return_Stack7 bit26 */
			{32740,35,1}, /* core0 return_Stack7 bit27 */
			{28659,35,1}, /* core0 return_Stack7 bit28 */
			{32739,35,1}, /* core0 return_Stack7 bit29 */
			{32738,35,1}, /* core0 return_Stack7 bit30 */
			{32737,35,1}, /* core0 return_Stack7 bit31 */
			{32768,35,1}, /* core0 return_Stack7 bit32 */
			{32767,35,1}, /* core0 return_Stack7 bit33 */
			{32766,35,1}, /* core0 return_Stack7 bit34 */
			{32765,35,1}, /* core0 return_Stack7 bit35 */
			{28670,35,1}, /* core0 return_Stack7 bit36 */
			{28669,35,1}, /* core0 return_Stack7 bit37 */
			{28672,35,1}, /* core0 return_Stack7 bit38 */
			{28671,35,1}, /* core0 return_Stack7 bit39 */
			{32772,35,1}, /* core0 return_Stack7 bit40 */
			{32771,35,1}, /* core0 return_Stack7 bit41 */
			{32770,35,1}, /* core0 return_Stack7 bit42 */
			{32769,35,1}, /* core0 return_Stack7 bit43 */
			{28666,35,1}, /* core0 return_Stack7 bit44 */
			{28665,35,1}, /* core0 return_Stack7 bit45 */
			{28668,35,1}, /* core0 return_Stack7 bit46 */
			{28667,35,1}, /* core0 return_Stack7 bit47 */
			{25964,35,1}, /* core0 return_Stack7 bit48 */
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
			{ 5564, 8,0}, /* core0 L2_parity_err_count bit0 */
			{ 5563, 8,0}, /* core0 L2_parity_err_count bit1 */
			{ 5562, 8,0}, /* core0 L2_parity_err_count bit2 */
			{ 5561, 8,0}, /* core0 L2_parity_err_count bit3 */
			{ 5560, 8,0}, /* core0 L2_parity_err_count bit4 */
			{ 5559, 8,0}, /* core0 L2_parity_err_count bit5 */
			{ 5558, 8,0}, /* core0 L2_parity_err_count bit6 */
			{ 5557, 8,0}, /* core0 L2_parity_err_count bit7 */
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
			{ 5588, 8,0}, /* core0 L2_parity_index bit0 */
			{ 5587, 8,0}, /* core0 L2_parity_index bit1 */
			{ 5586, 8,0}, /* core0 L2_parity_index bit2 */
			{ 5585, 8,0}, /* core0 L2_parity_index bit3 */
			{ 5584, 8,0}, /* core0 L2_parity_index bit4 */
			{ 5583, 8,0}, /* core0 L2_parity_index bit5 */
			{ 5582, 8,0}, /* core0 L2_parity_index bit6 */
			{ 5581, 8,0}, /* core0 L2_parity_index bit7 */
			{ 5580, 8,0}, /* core0 L2_parity_index bit8 */
			{ 5579, 8,0}, /* core0 L2_parity_index bit9 */
			{ 5578, 8,0}, /* core0 L2_parity_index bit10 */
			{ 5577, 8,0}, /* core0 L2_parity_index bit11 */
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
			{ 5573, 8,0}, /* core0 L2_parity_way bit0 */
			{ 5191, 8,0}, /* core0 L2_parity_way bit1 */
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
			{ 5894, 8,0}, /* core0 L2_parity_banks bit0 */
			{ 5893, 8,0}, /* core0 L2_parity_banks bit1 */
			{ 5892, 8,0}, /* core0 L2_parity_banks bit2 */
			{ 5891, 8,0}, /* core0 L2_parity_banks bit3 */
			{ 5890, 8,0}, /* core0 L2_parity_banks bit4 */
			{ 5889, 8,0}, /* core0 L2_parity_banks bit5 */
			{ 5888, 8,0}, /* core0 L2_parity_banks bit6 */
			{ 5887, 8,0}, /* core0 L2_parity_banks bit7 */
			{ 5902, 8,0}, /* core0 L2_parity_banks bit8 */
			{ 5901, 8,0}, /* core0 L2_parity_banks bit9 */
			{ 5900, 8,0}, /* core0 L2_parity_banks bit10 */
			{ 5899, 8,0}, /* core0 L2_parity_banks bit11 */
			{ 5898, 8,0}, /* core0 L2_parity_banks bit12 */
			{ 5897, 8,0}, /* core0 L2_parity_banks bit13 */
			{ 5896, 8,0}, /* core0 L2_parity_banks bit14 */
			{ 5895, 8,0}, /* core0 L2_parity_banks bit15 */
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
			{   95,36,1}, /* core1 pc bit0 */
			{  433,36,1}, /* core1 pc bit1 */
			{  432,36,1}, /* core1 pc bit2 */
			{  431,36,1}, /* core1 pc bit3 */
			{  430,36,1}, /* core1 pc bit4 */
			{  429,36,1}, /* core1 pc bit5 */
			{  495,36,1}, /* core1 pc bit6 */
			{  426,36,1}, /* core1 pc bit7 */
			{  494,36,1}, /* core1 pc bit8 */
			{  425,36,1}, /* core1 pc bit9 */
			{  424,36,1}, /* core1 pc bit10 */
			{  445,36,1}, /* core1 pc bit11 */
			{  493,36,1}, /* core1 pc bit12 */
			{  492,36,1}, /* core1 pc bit13 */
			{  444,36,1}, /* core1 pc bit14 */
			{  443,36,1}, /* core1 pc bit15 */
			{  466,36,1}, /* core1 pc bit16 */
			{  482,36,1}, /* core1 pc bit17 */
			{  465,36,1}, /* core1 pc bit18 */
			{  464,36,1}, /* core1 pc bit19 */
			{  470,36,1}, /* core1 pc bit20 */
			{  463,36,1}, /* core1 pc bit21 */
			{  440,36,1}, /* core1 pc bit22 */
			{  446,36,1}, /* core1 pc bit23 */
			{  491,36,1}, /* core1 pc bit24 */
			{  462,36,1}, /* core1 pc bit25 */
			{  481,36,1}, /* core1 pc bit26 */
			{  480,36,1}, /* core1 pc bit27 */
			{  461,36,1}, /* core1 pc bit28 */
			{  460,36,1}, /* core1 pc bit29 */
			{  448,36,1}, /* core1 pc bit30 */
			{  450,36,1}, /* core1 pc bit31 */
			{  270,36,1}, /* core1 pc bit32 */
			{  269,36,1}, /* core1 pc bit33 */
			{  268,36,1}, /* core1 pc bit34 */
			{  278,36,1}, /* core1 pc bit35 */
			{  320,36,1}, /* core1 pc bit36 */
			{  267,36,1}, /* core1 pc bit37 */
			{  266,36,1}, /* core1 pc bit38 */
			{  312,36,1}, /* core1 pc bit39 */
			{  162,36,1}, /* core1 pc bit40 */
			{  319,36,1}, /* core1 pc bit41 */
			{  318,36,1}, /* core1 pc bit42 */
			{  161,36,1}, /* core1 pc bit43 */
			{  160,36,1}, /* core1 pc bit44 */
			{  159,36,1}, /* core1 pc bit45 */
			{  317,36,1}, /* core1 pc bit46 */
			{  316,36,1}, /* core1 pc bit47 */
			{  140,36,1}, /* core1 pc bit48 */
			{  277,36,1}, /* core1 pc bit49 */
			{  276,36,1}, /* core1 pc bit50 */
			{  275,36,1}, /* core1 pc bit51 */
			{  274,36,1}, /* core1 pc bit52 */
			{  139,36,1}, /* core1 pc bit53 */
			{  280,36,1}, /* core1 pc bit54 */
			{  279,36,1}, /* core1 pc bit55 */
			{  353,36,1}, /* core1 pc bit56 */
			{  273,36,1}, /* core1 pc bit57 */
			{  288,36,1}, /* core1 pc bit58 */
			{  287,36,1}, /* core1 pc bit59 */
			{  138,36,1}, /* core1 pc bit60 */
			{  264,36,1}, /* core1 pc bit61 */
			{  263,36,1}, /* core1 pc bit62 */
			{  145,36,1}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{41179,37,1}, /* core1 sp32 bit0 */
			{41177,37,1}, /* core1 sp32 bit1 */
			{41176,37,1}, /* core1 sp32 bit2 */
			{41175,37,1}, /* core1 sp32 bit3 */
			{41178,37,1}, /* core1 sp32 bit4 */
			{41171,37,1}, /* core1 sp32 bit5 */
			{41170,37,1}, /* core1 sp32 bit6 */
			{41172,37,1}, /* core1 sp32 bit7 */
			{41173,37,1}, /* core1 sp32 bit8 */
			{41174,37,1}, /* core1 sp32 bit9 */
			{41197,37,1}, /* core1 sp32 bit10 */
			{41190,37,1}, /* core1 sp32 bit11 */
			{41182,37,1}, /* core1 sp32 bit12 */
			{41201,37,1}, /* core1 sp32 bit13 */
			{41184,37,1}, /* core1 sp32 bit14 */
			{41198,37,1}, /* core1 sp32 bit15 */
			{34300,36,0}, /* core1 sp32 bit16 */
			{34299,36,0}, /* core1 sp32 bit17 */
			{34328,36,0}, /* core1 sp32 bit18 */
			{34327,36,0}, /* core1 sp32 bit19 */
			{41196,37,1}, /* core1 sp32 bit20 */
			{41185,37,1}, /* core1 sp32 bit21 */
			{41227,37,1}, /* core1 sp32 bit22 */
			{41226,37,1}, /* core1 sp32 bit23 */
			{41180,37,1}, /* core1 sp32 bit24 */
			{41181,37,1}, /* core1 sp32 bit25 */
			{41183,37,1}, /* core1 sp32 bit26 */
			{41186,37,1}, /* core1 sp32 bit27 */
			{41199,37,1}, /* core1 sp32 bit28 */
			{41191,37,1}, /* core1 sp32 bit29 */
			{41188,37,1}, /* core1 sp32 bit30 */
			{41189,37,1}, /* core1 sp32 bit31 */
			{41121,37,1}, /* core1 sp32 bit32 */
			{41123,37,1}, /* core1 sp32 bit33 */
			{41113,37,1}, /* core1 sp32 bit34 */
			{41115,37,1}, /* core1 sp32 bit35 */
			{41120,37,1}, /* core1 sp32 bit36 */
			{41118,37,1}, /* core1 sp32 bit37 */
			{41122,37,1}, /* core1 sp32 bit38 */
			{41117,37,1}, /* core1 sp32 bit39 */
			{41116,37,1}, /* core1 sp32 bit40 */
			{41119,37,1}, /* core1 sp32 bit41 */
			{41108,37,1}, /* core1 sp32 bit42 */
			{41109,37,1}, /* core1 sp32 bit43 */
			{41110,37,1}, /* core1 sp32 bit44 */
			{41114,37,1}, /* core1 sp32 bit45 */
			{41111,37,1}, /* core1 sp32 bit46 */
			{41112,37,1}, /* core1 sp32 bit47 */
			{41159,37,1}, /* core1 sp32 bit48 */
			{41164,37,1}, /* core1 sp32 bit49 */
			{34350,36,0}, /* core1 sp32 bit50 */
			{34349,36,0}, /* core1 sp32 bit51 */
			{41166,37,1}, /* core1 sp32 bit52 */
			{41165,37,1}, /* core1 sp32 bit53 */
			{41163,37,1}, /* core1 sp32 bit54 */
			{41161,37,1}, /* core1 sp32 bit55 */
			{41167,37,1}, /* core1 sp32 bit56 */
			{41160,37,1}, /* core1 sp32 bit57 */
			{41162,37,1}, /* core1 sp32 bit58 */
			{41158,37,1}, /* core1 sp32 bit59 */
			{41157,37,1}, /* core1 sp32 bit60 */
			{41155,37,1}, /* core1 sp32 bit61 */
			{41154,37,1}, /* core1 sp32 bit62 */
			{41156,37,1}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{41650,37,1}, /* core1 fp32 bit0 */
			{41651,37,1}, /* core1 fp32 bit1 */
			{41648,37,1}, /* core1 fp32 bit2 */
			{41645,37,1}, /* core1 fp32 bit3 */
			{41652,37,1}, /* core1 fp32 bit4 */
			{41647,37,1}, /* core1 fp32 bit5 */
			{41644,37,1}, /* core1 fp32 bit6 */
			{41646,37,1}, /* core1 fp32 bit7 */
			{41643,37,1}, /* core1 fp32 bit8 */
			{41642,37,1}, /* core1 fp32 bit9 */
			{41676,37,1}, /* core1 fp32 bit10 */
			{41675,37,1}, /* core1 fp32 bit11 */
			{41685,37,1}, /* core1 fp32 bit12 */
			{41684,37,1}, /* core1 fp32 bit13 */
			{41680,37,1}, /* core1 fp32 bit14 */
			{41681,37,1}, /* core1 fp32 bit15 */
			{41682,37,1}, /* core1 fp32 bit16 */
			{41656,37,1}, /* core1 fp32 bit17 */
			{41678,37,1}, /* core1 fp32 bit18 */
			{41683,37,1}, /* core1 fp32 bit19 */
			{41677,37,1}, /* core1 fp32 bit20 */
			{41672,37,1}, /* core1 fp32 bit21 */
			{41686,37,1}, /* core1 fp32 bit22 */
			{41649,37,1}, /* core1 fp32 bit23 */
			{41688,37,1}, /* core1 fp32 bit24 */
			{41689,37,1}, /* core1 fp32 bit25 */
			{41669,37,1}, /* core1 fp32 bit26 */
			{41670,37,1}, /* core1 fp32 bit27 */
			{41673,37,1}, /* core1 fp32 bit28 */
			{41679,37,1}, /* core1 fp32 bit29 */
			{41674,37,1}, /* core1 fp32 bit30 */
			{41671,37,1}, /* core1 fp32 bit31 */
			{41580,37,1}, /* core1 fp32 bit32 */
			{41589,37,1}, /* core1 fp32 bit33 */
			{41583,37,1}, /* core1 fp32 bit34 */
			{41587,37,1}, /* core1 fp32 bit35 */
			{41582,37,1}, /* core1 fp32 bit36 */
			{41575,37,1}, /* core1 fp32 bit37 */
			{41576,37,1}, /* core1 fp32 bit38 */
			{41585,37,1}, /* core1 fp32 bit39 */
			{41584,37,1}, /* core1 fp32 bit40 */
			{41581,37,1}, /* core1 fp32 bit41 */
			{41588,37,1}, /* core1 fp32 bit42 */
			{41577,37,1}, /* core1 fp32 bit43 */
			{41578,37,1}, /* core1 fp32 bit44 */
			{41579,37,1}, /* core1 fp32 bit45 */
			{41574,37,1}, /* core1 fp32 bit46 */
			{41586,37,1}, /* core1 fp32 bit47 */
			{41605,37,1}, /* core1 fp32 bit48 */
			{41604,37,1}, /* core1 fp32 bit49 */
			{41606,37,1}, /* core1 fp32 bit50 */
			{41609,37,1}, /* core1 fp32 bit51 */
			{41607,37,1}, /* core1 fp32 bit52 */
			{41610,37,1}, /* core1 fp32 bit53 */
			{41602,37,1}, /* core1 fp32 bit54 */
			{41597,37,1}, /* core1 fp32 bit55 */
			{41608,37,1}, /* core1 fp32 bit56 */
			{41598,37,1}, /* core1 fp32 bit57 */
			{41601,37,1}, /* core1 fp32 bit58 */
			{41596,37,1}, /* core1 fp32 bit59 */
			{41593,37,1}, /* core1 fp32 bit60 */
			{34376,36,0}, /* core1 fp32 bit61 */
			{34375,36,0}, /* core1 fp32 bit62 */
			{41594,37,1}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{40573,37,1}, /* core1 fp64 bit0 */
			{40571,37,1}, /* core1 fp64 bit1 */
			{40569,37,1}, /* core1 fp64 bit2 */
			{34306,36,0}, /* core1 fp64 bit3 */
			{34305,36,0}, /* core1 fp64 bit4 */
			{40567,37,1}, /* core1 fp64 bit5 */
			{40568,37,1}, /* core1 fp64 bit6 */
			{34304,36,0}, /* core1 fp64 bit7 */
			{34303,36,0}, /* core1 fp64 bit8 */
			{40570,37,1}, /* core1 fp64 bit9 */
			{40560,37,1}, /* core1 fp64 bit10 */
			{40558,37,1}, /* core1 fp64 bit11 */
			{40566,37,1}, /* core1 fp64 bit12 */
			{40565,37,1}, /* core1 fp64 bit13 */
			{40564,37,1}, /* core1 fp64 bit14 */
			{40559,37,1}, /* core1 fp64 bit15 */
			{40554,37,1}, /* core1 fp64 bit16 */
			{40490,37,1}, /* core1 fp64 bit17 */
			{40552,37,1}, /* core1 fp64 bit18 */
			{40555,37,1}, /* core1 fp64 bit19 */
			{40557,37,1}, /* core1 fp64 bit20 */
			{40553,37,1}, /* core1 fp64 bit21 */
			{40572,37,1}, /* core1 fp64 bit22 */
			{40491,37,1}, /* core1 fp64 bit23 */
			{40492,37,1}, /* core1 fp64 bit24 */
			{40493,37,1}, /* core1 fp64 bit25 */
			{40563,37,1}, /* core1 fp64 bit26 */
			{34322,36,0}, /* core1 fp64 bit27 */
			{34321,36,0}, /* core1 fp64 bit28 */
			{40562,37,1}, /* core1 fp64 bit29 */
			{40561,37,1}, /* core1 fp64 bit30 */
			{40556,37,1}, /* core1 fp64 bit31 */
			{40702,37,1}, /* core1 fp64 bit32 */
			{40697,37,1}, /* core1 fp64 bit33 */
			{40699,37,1}, /* core1 fp64 bit34 */
			{40708,37,1}, /* core1 fp64 bit35 */
			{40706,37,1}, /* core1 fp64 bit36 */
			{40701,37,1}, /* core1 fp64 bit37 */
			{40703,37,1}, /* core1 fp64 bit38 */
			{40705,37,1}, /* core1 fp64 bit39 */
			{40704,37,1}, /* core1 fp64 bit40 */
			{40698,37,1}, /* core1 fp64 bit41 */
			{40707,37,1}, /* core1 fp64 bit42 */
			{40700,37,1}, /* core1 fp64 bit43 */
			{40709,37,1}, /* core1 fp64 bit44 */
			{40696,37,1}, /* core1 fp64 bit45 */
			{40727,37,1}, /* core1 fp64 bit46 */
			{40695,37,1}, /* core1 fp64 bit47 */
			{40690,37,1}, /* core1 fp64 bit48 */
			{40638,37,1}, /* core1 fp64 bit49 */
			{40642,37,1}, /* core1 fp64 bit50 */
			{40645,37,1}, /* core1 fp64 bit51 */
			{40644,37,1}, /* core1 fp64 bit52 */
			{40643,37,1}, /* core1 fp64 bit53 */
			{40637,37,1}, /* core1 fp64 bit54 */
			{40632,37,1}, /* core1 fp64 bit55 */
			{40646,37,1}, /* core1 fp64 bit56 */
			{40633,37,1}, /* core1 fp64 bit57 */
			{40635,37,1}, /* core1 fp64 bit58 */
			{40691,37,1}, /* core1 fp64 bit59 */
			{40693,37,1}, /* core1 fp64 bit60 */
			{40726,37,1}, /* core1 fp64 bit61 */
			{40692,37,1}, /* core1 fp64 bit62 */
			{40694,37,1}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40577,37,1}, /* core1 sp_EL0 bit0 */
			{40575,37,1}, /* core1 sp_EL0 bit1 */
			{40580,37,1}, /* core1 sp_EL0 bit2 */
			{40582,37,1}, /* core1 sp_EL0 bit3 */
			{40583,37,1}, /* core1 sp_EL0 bit4 */
			{40581,37,1}, /* core1 sp_EL0 bit5 */
			{34278,36,0}, /* core1 sp_EL0 bit6 */
			{34277,36,0}, /* core1 sp_EL0 bit7 */
			{40578,37,1}, /* core1 sp_EL0 bit8 */
			{40576,37,1}, /* core1 sp_EL0 bit9 */
			{40488,37,1}, /* core1 sp_EL0 bit10 */
			{40487,37,1}, /* core1 sp_EL0 bit11 */
			{34276,36,0}, /* core1 sp_EL0 bit12 */
			{34275,36,0}, /* core1 sp_EL0 bit13 */
			{40579,37,1}, /* core1 sp_EL0 bit14 */
			{40574,37,1}, /* core1 sp_EL0 bit15 */
			{34284,36,0}, /* core1 sp_EL0 bit16 */
			{34283,36,0}, /* core1 sp_EL0 bit17 */
			{40489,37,1}, /* core1 sp_EL0 bit18 */
			{40486,37,1}, /* core1 sp_EL0 bit19 */
			{40485,37,1}, /* core1 sp_EL0 bit20 */
			{40484,37,1}, /* core1 sp_EL0 bit21 */
			{40306,37,1}, /* core1 sp_EL0 bit22 */
			{40302,37,1}, /* core1 sp_EL0 bit23 */
			{40304,37,1}, /* core1 sp_EL0 bit24 */
			{40305,37,1}, /* core1 sp_EL0 bit25 */
			{40282,37,1}, /* core1 sp_EL0 bit26 */
			{40283,37,1}, /* core1 sp_EL0 bit27 */
			{40285,37,1}, /* core1 sp_EL0 bit28 */
			{40284,37,1}, /* core1 sp_EL0 bit29 */
			{40286,37,1}, /* core1 sp_EL0 bit30 */
			{40303,37,1}, /* core1 sp_EL0 bit31 */
			{40436,37,1}, /* core1 sp_EL0 bit32 */
			{40434,37,1}, /* core1 sp_EL0 bit33 */
			{40440,37,1}, /* core1 sp_EL0 bit34 */
			{40437,37,1}, /* core1 sp_EL0 bit35 */
			{40427,37,1}, /* core1 sp_EL0 bit36 */
			{40428,37,1}, /* core1 sp_EL0 bit37 */
			{40431,37,1}, /* core1 sp_EL0 bit38 */
			{40429,37,1}, /* core1 sp_EL0 bit39 */
			{40430,37,1}, /* core1 sp_EL0 bit40 */
			{40441,37,1}, /* core1 sp_EL0 bit41 */
			{40433,37,1}, /* core1 sp_EL0 bit42 */
			{40432,37,1}, /* core1 sp_EL0 bit43 */
			{40439,37,1}, /* core1 sp_EL0 bit44 */
			{40438,37,1}, /* core1 sp_EL0 bit45 */
			{40443,37,1}, /* core1 sp_EL0 bit46 */
			{40442,37,1}, /* core1 sp_EL0 bit47 */
			{40456,37,1}, /* core1 sp_EL0 bit48 */
			{34430,36,0}, /* core1 sp_EL0 bit49 */
			{34426,36,0}, /* core1 sp_EL0 bit50 */
			{34425,36,0}, /* core1 sp_EL0 bit51 */
			{34432,36,0}, /* core1 sp_EL0 bit52 */
			{34431,36,0}, /* core1 sp_EL0 bit53 */
			{34429,36,0}, /* core1 sp_EL0 bit54 */
			{40446,37,1}, /* core1 sp_EL0 bit55 */
			{36696,36,0}, /* core1 sp_EL0 bit56 */
			{36695,36,0}, /* core1 sp_EL0 bit57 */
			{36694,36,0}, /* core1 sp_EL0 bit58 */
			{36693,36,0}, /* core1 sp_EL0 bit59 */
			{40445,37,1}, /* core1 sp_EL0 bit60 */
			{40444,37,1}, /* core1 sp_EL0 bit61 */
			{34392,36,0}, /* core1 sp_EL0 bit62 */
			{34391,36,0}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40312,37,1}, /* core1 sp_EL1 bit0 */
			{40319,37,1}, /* core1 sp_EL1 bit1 */
			{40314,37,1}, /* core1 sp_EL1 bit2 */
			{40315,37,1}, /* core1 sp_EL1 bit3 */
			{34236,36,0}, /* core1 sp_EL1 bit4 */
			{34235,36,0}, /* core1 sp_EL1 bit5 */
			{34238,36,0}, /* core1 sp_EL1 bit6 */
			{34237,36,0}, /* core1 sp_EL1 bit7 */
			{40313,37,1}, /* core1 sp_EL1 bit8 */
			{40316,37,1}, /* core1 sp_EL1 bit9 */
			{40336,37,1}, /* core1 sp_EL1 bit10 */
			{40333,37,1}, /* core1 sp_EL1 bit11 */
			{40311,37,1}, /* core1 sp_EL1 bit12 */
			{40308,37,1}, /* core1 sp_EL1 bit13 */
			{40331,37,1}, /* core1 sp_EL1 bit14 */
			{40330,37,1}, /* core1 sp_EL1 bit15 */
			{34216,36,0}, /* core1 sp_EL1 bit16 */
			{34215,36,0}, /* core1 sp_EL1 bit17 */
			{40348,37,1}, /* core1 sp_EL1 bit18 */
			{40349,37,1}, /* core1 sp_EL1 bit19 */
			{40350,37,1}, /* core1 sp_EL1 bit20 */
			{40346,37,1}, /* core1 sp_EL1 bit21 */
			{40332,37,1}, /* core1 sp_EL1 bit22 */
			{40334,37,1}, /* core1 sp_EL1 bit23 */
			{40335,37,1}, /* core1 sp_EL1 bit24 */
			{40347,37,1}, /* core1 sp_EL1 bit25 */
			{40320,37,1}, /* core1 sp_EL1 bit26 */
			{40321,37,1}, /* core1 sp_EL1 bit27 */
			{40310,37,1}, /* core1 sp_EL1 bit28 */
			{40309,37,1}, /* core1 sp_EL1 bit29 */
			{40307,37,1}, /* core1 sp_EL1 bit30 */
			{40345,37,1}, /* core1 sp_EL1 bit31 */
			{40406,37,1}, /* core1 sp_EL1 bit32 */
			{40405,37,1}, /* core1 sp_EL1 bit33 */
			{40386,37,1}, /* core1 sp_EL1 bit34 */
			{40383,37,1}, /* core1 sp_EL1 bit35 */
			{40422,37,1}, /* core1 sp_EL1 bit36 */
			{40421,37,1}, /* core1 sp_EL1 bit37 */
			{40407,37,1}, /* core1 sp_EL1 bit38 */
			{40400,37,1}, /* core1 sp_EL1 bit39 */
			{40401,37,1}, /* core1 sp_EL1 bit40 */
			{40409,37,1}, /* core1 sp_EL1 bit41 */
			{40410,37,1}, /* core1 sp_EL1 bit42 */
			{40411,37,1}, /* core1 sp_EL1 bit43 */
			{40408,37,1}, /* core1 sp_EL1 bit44 */
			{40384,37,1}, /* core1 sp_EL1 bit45 */
			{40379,37,1}, /* core1 sp_EL1 bit46 */
			{40385,37,1}, /* core1 sp_EL1 bit47 */
			{40449,37,1}, /* core1 sp_EL1 bit48 */
			{39472,36,0}, /* core1 sp_EL1 bit49 */
			{39471,36,0}, /* core1 sp_EL1 bit50 */
			{39470,36,0}, /* core1 sp_EL1 bit51 */
			{39469,36,0}, /* core1 sp_EL1 bit52 */
			{39468,36,0}, /* core1 sp_EL1 bit53 */
			{39467,36,0}, /* core1 sp_EL1 bit54 */
			{39466,36,0}, /* core1 sp_EL1 bit55 */
			{39465,36,0}, /* core1 sp_EL1 bit56 */
			{40448,37,1}, /* core1 sp_EL1 bit57 */
			{34398,36,0}, /* core1 sp_EL1 bit58 */
			{34397,36,0}, /* core1 sp_EL1 bit59 */
			{34386,36,0}, /* core1 sp_EL1 bit60 */
			{34385,36,0}, /* core1 sp_EL1 bit61 */
			{34198,36,0}, /* core1 sp_EL1 bit62 */
			{34197,36,0}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40264,37,1}, /* core1 sp_EL2 bit0 */
			{40256,37,1}, /* core1 sp_EL2 bit1 */
			{40268,37,1}, /* core1 sp_EL2 bit2 */
			{40266,37,1}, /* core1 sp_EL2 bit3 */
			{40257,37,1}, /* core1 sp_EL2 bit4 */
			{40263,37,1}, /* core1 sp_EL2 bit5 */
			{40267,37,1}, /* core1 sp_EL2 bit6 */
			{40262,37,1}, /* core1 sp_EL2 bit7 */
			{40261,37,1}, /* core1 sp_EL2 bit8 */
			{40260,37,1}, /* core1 sp_EL2 bit9 */
			{40245,37,1}, /* core1 sp_EL2 bit10 */
			{40246,37,1}, /* core1 sp_EL2 bit11 */
			{40265,37,1}, /* core1 sp_EL2 bit12 */
			{40243,37,1}, /* core1 sp_EL2 bit13 */
			{40241,37,1}, /* core1 sp_EL2 bit14 */
			{40239,37,1}, /* core1 sp_EL2 bit15 */
			{40251,37,1}, /* core1 sp_EL2 bit16 */
			{40259,37,1}, /* core1 sp_EL2 bit17 */
			{40250,37,1}, /* core1 sp_EL2 bit18 */
			{40247,37,1}, /* core1 sp_EL2 bit19 */
			{40248,37,1}, /* core1 sp_EL2 bit20 */
			{40249,37,1}, /* core1 sp_EL2 bit21 */
			{40255,37,1}, /* core1 sp_EL2 bit22 */
			{40258,37,1}, /* core1 sp_EL2 bit23 */
			{40254,37,1}, /* core1 sp_EL2 bit24 */
			{40253,37,1}, /* core1 sp_EL2 bit25 */
			{40238,37,1}, /* core1 sp_EL2 bit26 */
			{40237,37,1}, /* core1 sp_EL2 bit27 */
			{40242,37,1}, /* core1 sp_EL2 bit28 */
			{40240,37,1}, /* core1 sp_EL2 bit29 */
			{40244,37,1}, /* core1 sp_EL2 bit30 */
			{40252,37,1}, /* core1 sp_EL2 bit31 */
			{40402,37,1}, /* core1 sp_EL2 bit32 */
			{40412,37,1}, /* core1 sp_EL2 bit33 */
			{40387,37,1}, /* core1 sp_EL2 bit34 */
			{40388,37,1}, /* core1 sp_EL2 bit35 */
			{40419,37,1}, /* core1 sp_EL2 bit36 */
			{40414,37,1}, /* core1 sp_EL2 bit37 */
			{40413,37,1}, /* core1 sp_EL2 bit38 */
			{40417,37,1}, /* core1 sp_EL2 bit39 */
			{40416,37,1}, /* core1 sp_EL2 bit40 */
			{40418,37,1}, /* core1 sp_EL2 bit41 */
			{40415,37,1}, /* core1 sp_EL2 bit42 */
			{40420,37,1}, /* core1 sp_EL2 bit43 */
			{40404,37,1}, /* core1 sp_EL2 bit44 */
			{40403,37,1}, /* core1 sp_EL2 bit45 */
			{40378,37,1}, /* core1 sp_EL2 bit46 */
			{40389,37,1}, /* core1 sp_EL2 bit47 */
			{40447,37,1}, /* core1 sp_EL2 bit48 */
			{40460,37,1}, /* core1 sp_EL2 bit49 */
			{34422,36,0}, /* core1 sp_EL2 bit50 */
			{34421,36,0}, /* core1 sp_EL2 bit51 */
			{34420,36,0}, /* core1 sp_EL2 bit52 */
			{34419,36,0}, /* core1 sp_EL2 bit53 */
			{34416,36,0}, /* core1 sp_EL2 bit54 */
			{34415,36,0}, /* core1 sp_EL2 bit55 */
			{34400,36,0}, /* core1 sp_EL2 bit56 */
			{34399,36,0}, /* core1 sp_EL2 bit57 */
			{34396,36,0}, /* core1 sp_EL2 bit58 */
			{34395,36,0}, /* core1 sp_EL2 bit59 */
			{36728,36,0}, /* core1 sp_EL2 bit60 */
			{36727,36,0}, /* core1 sp_EL2 bit61 */
			{36726,36,0}, /* core1 sp_EL2 bit62 */
			{36725,36,0}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40272,37,1}, /* core1 sp_EL3 bit0 */
			{40289,37,1}, /* core1 sp_EL3 bit1 */
			{40277,37,1}, /* core1 sp_EL3 bit2 */
			{40279,37,1}, /* core1 sp_EL3 bit3 */
			{40281,37,1}, /* core1 sp_EL3 bit4 */
			{40280,37,1}, /* core1 sp_EL3 bit5 */
			{34280,36,0}, /* core1 sp_EL3 bit6 */
			{34279,36,0}, /* core1 sp_EL3 bit7 */
			{40278,37,1}, /* core1 sp_EL3 bit8 */
			{40276,37,1}, /* core1 sp_EL3 bit9 */
			{40290,37,1}, /* core1 sp_EL3 bit10 */
			{40292,37,1}, /* core1 sp_EL3 bit11 */
			{34282,36,0}, /* core1 sp_EL3 bit12 */
			{34281,36,0}, /* core1 sp_EL3 bit13 */
			{40288,37,1}, /* core1 sp_EL3 bit14 */
			{40287,37,1}, /* core1 sp_EL3 bit15 */
			{40300,37,1}, /* core1 sp_EL3 bit16 */
			{40301,37,1}, /* core1 sp_EL3 bit17 */
			{40291,37,1}, /* core1 sp_EL3 bit18 */
			{40299,37,1}, /* core1 sp_EL3 bit19 */
			{40297,37,1}, /* core1 sp_EL3 bit20 */
			{40298,37,1}, /* core1 sp_EL3 bit21 */
			{40271,37,1}, /* core1 sp_EL3 bit22 */
			{40294,37,1}, /* core1 sp_EL3 bit23 */
			{40295,37,1}, /* core1 sp_EL3 bit24 */
			{40296,37,1}, /* core1 sp_EL3 bit25 */
			{40275,37,1}, /* core1 sp_EL3 bit26 */
			{40274,37,1}, /* core1 sp_EL3 bit27 */
			{40273,37,1}, /* core1 sp_EL3 bit28 */
			{40270,37,1}, /* core1 sp_EL3 bit29 */
			{40269,37,1}, /* core1 sp_EL3 bit30 */
			{40293,37,1}, /* core1 sp_EL3 bit31 */
			{40393,37,1}, /* core1 sp_EL3 bit32 */
			{40392,37,1}, /* core1 sp_EL3 bit33 */
			{40391,37,1}, /* core1 sp_EL3 bit34 */
			{40396,37,1}, /* core1 sp_EL3 bit35 */
			{40425,37,1}, /* core1 sp_EL3 bit36 */
			{40423,37,1}, /* core1 sp_EL3 bit37 */
			{40395,37,1}, /* core1 sp_EL3 bit38 */
			{40426,37,1}, /* core1 sp_EL3 bit39 */
			{40397,37,1}, /* core1 sp_EL3 bit40 */
			{40399,37,1}, /* core1 sp_EL3 bit41 */
			{40424,37,1}, /* core1 sp_EL3 bit42 */
			{40398,37,1}, /* core1 sp_EL3 bit43 */
			{40394,37,1}, /* core1 sp_EL3 bit44 */
			{40435,37,1}, /* core1 sp_EL3 bit45 */
			{40377,37,1}, /* core1 sp_EL3 bit46 */
			{40390,37,1}, /* core1 sp_EL3 bit47 */
			{40458,37,1}, /* core1 sp_EL3 bit48 */
			{40457,37,1}, /* core1 sp_EL3 bit49 */
			{34418,36,0}, /* core1 sp_EL3 bit50 */
			{34417,36,0}, /* core1 sp_EL3 bit51 */
			{36776,36,0}, /* core1 sp_EL3 bit52 */
			{36775,36,0}, /* core1 sp_EL3 bit53 */
			{36774,36,0}, /* core1 sp_EL3 bit54 */
			{36773,36,0}, /* core1 sp_EL3 bit55 */
			{36692,36,0}, /* core1 sp_EL3 bit56 */
			{36691,36,0}, /* core1 sp_EL3 bit57 */
			{36690,36,0}, /* core1 sp_EL3 bit58 */
			{36689,36,0}, /* core1 sp_EL3 bit59 */
			{40375,37,1}, /* core1 sp_EL3 bit60 */
			{40374,37,1}, /* core1 sp_EL3 bit61 */
			{34388,36,0}, /* core1 sp_EL3 bit62 */
			{34387,36,0}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{39606,36,0}, /* core1 elr_EL1 bit0 */
			{39605,36,0}, /* core1 elr_EL1 bit1 */
			{39604,36,0}, /* core1 elr_EL1 bit2 */
			{39603,36,0}, /* core1 elr_EL1 bit3 */
			{39602,36,0}, /* core1 elr_EL1 bit4 */
			{39601,36,0}, /* core1 elr_EL1 bit5 */
			{39600,36,0}, /* core1 elr_EL1 bit6 */
			{39599,36,0}, /* core1 elr_EL1 bit7 */
			{34224,36,0}, /* core1 elr_EL1 bit8 */
			{34223,36,0}, /* core1 elr_EL1 bit9 */
			{34218,36,0}, /* core1 elr_EL1 bit10 */
			{34217,36,0}, /* core1 elr_EL1 bit11 */
			{34222,36,0}, /* core1 elr_EL1 bit12 */
			{34221,36,0}, /* core1 elr_EL1 bit13 */
			{34220,36,0}, /* core1 elr_EL1 bit14 */
			{34219,36,0}, /* core1 elr_EL1 bit15 */
			{39654,36,0}, /* core1 elr_EL1 bit16 */
			{39653,36,0}, /* core1 elr_EL1 bit17 */
			{39652,36,0}, /* core1 elr_EL1 bit18 */
			{39651,36,0}, /* core1 elr_EL1 bit19 */
			{39650,36,0}, /* core1 elr_EL1 bit20 */
			{39649,36,0}, /* core1 elr_EL1 bit21 */
			{39648,36,0}, /* core1 elr_EL1 bit22 */
			{39647,36,0}, /* core1 elr_EL1 bit23 */
			{39638,36,0}, /* core1 elr_EL1 bit24 */
			{39637,36,0}, /* core1 elr_EL1 bit25 */
			{39636,36,0}, /* core1 elr_EL1 bit26 */
			{39635,36,0}, /* core1 elr_EL1 bit27 */
			{39634,36,0}, /* core1 elr_EL1 bit28 */
			{39633,36,0}, /* core1 elr_EL1 bit29 */
			{39632,36,0}, /* core1 elr_EL1 bit30 */
			{39631,36,0}, /* core1 elr_EL1 bit31 */
			{36720,36,0}, /* core1 elr_EL1 bit32 */
			{36724,36,0}, /* core1 elr_EL1 bit33 */
			{36723,36,0}, /* core1 elr_EL1 bit34 */
			{36719,36,0}, /* core1 elr_EL1 bit35 */
			{36722,36,0}, /* core1 elr_EL1 bit36 */
			{36721,36,0}, /* core1 elr_EL1 bit37 */
			{36716,36,0}, /* core1 elr_EL1 bit38 */
			{36718,36,0}, /* core1 elr_EL1 bit39 */
			{36715,36,0}, /* core1 elr_EL1 bit40 */
			{36714,36,0}, /* core1 elr_EL1 bit41 */
			{39440,36,0}, /* core1 elr_EL1 bit42 */
			{39439,36,0}, /* core1 elr_EL1 bit43 */
			{39438,36,0}, /* core1 elr_EL1 bit44 */
			{36717,36,0}, /* core1 elr_EL1 bit45 */
			{39437,36,0}, /* core1 elr_EL1 bit46 */
			{39436,36,0}, /* core1 elr_EL1 bit47 */
			{36796,36,0}, /* core1 elr_EL1 bit48 */
			{39435,36,0}, /* core1 elr_EL1 bit49 */
			{36795,36,0}, /* core1 elr_EL1 bit50 */
			{36794,36,0}, /* core1 elr_EL1 bit51 */
			{36793,36,0}, /* core1 elr_EL1 bit52 */
			{36792,36,0}, /* core1 elr_EL1 bit53 */
			{39434,36,0}, /* core1 elr_EL1 bit54 */
			{39433,36,0}, /* core1 elr_EL1 bit55 */
			{36791,36,0}, /* core1 elr_EL1 bit56 */
			{36790,36,0}, /* core1 elr_EL1 bit57 */
			{36789,36,0}, /* core1 elr_EL1 bit58 */
			{34394,36,0}, /* core1 elr_EL1 bit59 */
			{36713,36,0}, /* core1 elr_EL1 bit60 */
			{34393,36,0}, /* core1 elr_EL1 bit61 */
			{34390,36,0}, /* core1 elr_EL1 bit62 */
			{34389,36,0}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{39614,36,0}, /* core1 elr_EL2 bit0 */
			{39613,36,0}, /* core1 elr_EL2 bit1 */
			{39612,36,0}, /* core1 elr_EL2 bit2 */
			{39611,36,0}, /* core1 elr_EL2 bit3 */
			{39610,36,0}, /* core1 elr_EL2 bit4 */
			{39609,36,0}, /* core1 elr_EL2 bit5 */
			{39608,36,0}, /* core1 elr_EL2 bit6 */
			{39607,36,0}, /* core1 elr_EL2 bit7 */
			{39622,36,0}, /* core1 elr_EL2 bit8 */
			{39621,36,0}, /* core1 elr_EL2 bit9 */
			{39620,36,0}, /* core1 elr_EL2 bit10 */
			{39619,36,0}, /* core1 elr_EL2 bit11 */
			{39618,36,0}, /* core1 elr_EL2 bit12 */
			{39617,36,0}, /* core1 elr_EL2 bit13 */
			{39616,36,0}, /* core1 elr_EL2 bit14 */
			{39615,36,0}, /* core1 elr_EL2 bit15 */
			{39646,36,0}, /* core1 elr_EL2 bit16 */
			{39645,36,0}, /* core1 elr_EL2 bit17 */
			{39644,36,0}, /* core1 elr_EL2 bit18 */
			{39643,36,0}, /* core1 elr_EL2 bit19 */
			{39642,36,0}, /* core1 elr_EL2 bit20 */
			{39641,36,0}, /* core1 elr_EL2 bit21 */
			{39640,36,0}, /* core1 elr_EL2 bit22 */
			{39639,36,0}, /* core1 elr_EL2 bit23 */
			{39630,36,0}, /* core1 elr_EL2 bit24 */
			{39629,36,0}, /* core1 elr_EL2 bit25 */
			{39628,36,0}, /* core1 elr_EL2 bit26 */
			{39627,36,0}, /* core1 elr_EL2 bit27 */
			{39626,36,0}, /* core1 elr_EL2 bit28 */
			{39625,36,0}, /* core1 elr_EL2 bit29 */
			{39624,36,0}, /* core1 elr_EL2 bit30 */
			{39623,36,0}, /* core1 elr_EL2 bit31 */
			{39432,36,0}, /* core1 elr_EL2 bit32 */
			{36712,36,0}, /* core1 elr_EL2 bit33 */
			{36711,36,0}, /* core1 elr_EL2 bit34 */
			{39431,36,0}, /* core1 elr_EL2 bit35 */
			{39430,36,0}, /* core1 elr_EL2 bit36 */
			{39429,36,0}, /* core1 elr_EL2 bit37 */
			{36710,36,0}, /* core1 elr_EL2 bit38 */
			{39428,36,0}, /* core1 elr_EL2 bit39 */
			{36709,36,0}, /* core1 elr_EL2 bit40 */
			{36708,36,0}, /* core1 elr_EL2 bit41 */
			{39427,36,0}, /* core1 elr_EL2 bit42 */
			{36707,36,0}, /* core1 elr_EL2 bit43 */
			{36706,36,0}, /* core1 elr_EL2 bit44 */
			{39426,36,0}, /* core1 elr_EL2 bit45 */
			{39425,36,0}, /* core1 elr_EL2 bit46 */
			{36705,36,0}, /* core1 elr_EL2 bit47 */
			{36788,36,0}, /* core1 elr_EL2 bit48 */
			{36787,36,0}, /* core1 elr_EL2 bit49 */
			{36786,36,0}, /* core1 elr_EL2 bit50 */
			{36785,36,0}, /* core1 elr_EL2 bit51 */
			{36784,36,0}, /* core1 elr_EL2 bit52 */
			{36783,36,0}, /* core1 elr_EL2 bit53 */
			{36782,36,0}, /* core1 elr_EL2 bit54 */
			{36781,36,0}, /* core1 elr_EL2 bit55 */
			{36780,36,0}, /* core1 elr_EL2 bit56 */
			{36779,36,0}, /* core1 elr_EL2 bit57 */
			{36778,36,0}, /* core1 elr_EL2 bit58 */
			{36777,36,0}, /* core1 elr_EL2 bit59 */
			{36704,36,0}, /* core1 elr_EL2 bit60 */
			{36703,36,0}, /* core1 elr_EL2 bit61 */
			{36702,36,0}, /* core1 elr_EL2 bit62 */
			{36701,36,0}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{34228,36,0}, /* core1 elr_EL3 bit0 */
			{34227,36,0}, /* core1 elr_EL3 bit1 */
			{40317,37,1}, /* core1 elr_EL3 bit2 */
			{40318,37,1}, /* core1 elr_EL3 bit3 */
			{36912,36,0}, /* core1 elr_EL3 bit4 */
			{36911,36,0}, /* core1 elr_EL3 bit5 */
			{36910,36,0}, /* core1 elr_EL3 bit6 */
			{36909,36,0}, /* core1 elr_EL3 bit7 */
			{34232,36,0}, /* core1 elr_EL3 bit8 */
			{34231,36,0}, /* core1 elr_EL3 bit9 */
			{40339,37,1}, /* core1 elr_EL3 bit10 */
			{40351,37,1}, /* core1 elr_EL3 bit11 */
			{34230,36,0}, /* core1 elr_EL3 bit12 */
			{34229,36,0}, /* core1 elr_EL3 bit13 */
			{40326,37,1}, /* core1 elr_EL3 bit14 */
			{40328,37,1}, /* core1 elr_EL3 bit15 */
			{40352,37,1}, /* core1 elr_EL3 bit16 */
			{40353,37,1}, /* core1 elr_EL3 bit17 */
			{40354,37,1}, /* core1 elr_EL3 bit18 */
			{40344,37,1}, /* core1 elr_EL3 bit19 */
			{40342,37,1}, /* core1 elr_EL3 bit20 */
			{40341,37,1}, /* core1 elr_EL3 bit21 */
			{40327,37,1}, /* core1 elr_EL3 bit22 */
			{40338,37,1}, /* core1 elr_EL3 bit23 */
			{40340,37,1}, /* core1 elr_EL3 bit24 */
			{40343,37,1}, /* core1 elr_EL3 bit25 */
			{40323,37,1}, /* core1 elr_EL3 bit26 */
			{40322,37,1}, /* core1 elr_EL3 bit27 */
			{40324,37,1}, /* core1 elr_EL3 bit28 */
			{40325,37,1}, /* core1 elr_EL3 bit29 */
			{40329,37,1}, /* core1 elr_EL3 bit30 */
			{40337,37,1}, /* core1 elr_EL3 bit31 */
			{34382,36,0}, /* core1 elr_EL3 bit32 */
			{34381,36,0}, /* core1 elr_EL3 bit33 */
			{40368,37,1}, /* core1 elr_EL3 bit34 */
			{40364,37,1}, /* core1 elr_EL3 bit35 */
			{40380,37,1}, /* core1 elr_EL3 bit36 */
			{40372,37,1}, /* core1 elr_EL3 bit37 */
			{40365,37,1}, /* core1 elr_EL3 bit38 */
			{40376,37,1}, /* core1 elr_EL3 bit39 */
			{40369,37,1}, /* core1 elr_EL3 bit40 */
			{40367,37,1}, /* core1 elr_EL3 bit41 */
			{40373,37,1}, /* core1 elr_EL3 bit42 */
			{40371,37,1}, /* core1 elr_EL3 bit43 */
			{40381,37,1}, /* core1 elr_EL3 bit44 */
			{40366,37,1}, /* core1 elr_EL3 bit45 */
			{40370,37,1}, /* core1 elr_EL3 bit46 */
			{40382,37,1}, /* core1 elr_EL3 bit47 */
			{34402,36,0}, /* core1 elr_EL3 bit48 */
			{34401,36,0}, /* core1 elr_EL3 bit49 */
			{36772,36,0}, /* core1 elr_EL3 bit50 */
			{36771,36,0}, /* core1 elr_EL3 bit51 */
			{34414,36,0}, /* core1 elr_EL3 bit52 */
			{36770,36,0}, /* core1 elr_EL3 bit53 */
			{34413,36,0}, /* core1 elr_EL3 bit54 */
			{36769,36,0}, /* core1 elr_EL3 bit55 */
			{36688,36,0}, /* core1 elr_EL3 bit56 */
			{36687,36,0}, /* core1 elr_EL3 bit57 */
			{36686,36,0}, /* core1 elr_EL3 bit58 */
			{36685,36,0}, /* core1 elr_EL3 bit59 */
			{34384,36,0}, /* core1 elr_EL3 bit60 */
			{34383,36,0}, /* core1 elr_EL3 bit61 */
			{34196,36,0}, /* core1 elr_EL3 bit62 */
			{34195,36,0}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{35631,36,0}, /* core1 raw_pc bit0 */
			{35630,36,0}, /* core1 raw_pc bit1 */
			{38290,36,0}, /* core1 raw_pc bit2 */
			{38289,36,0}, /* core1 raw_pc bit3 */
			{38288,36,0}, /* core1 raw_pc bit4 */
			{38287,36,0}, /* core1 raw_pc bit5 */
			{32560,36,1}, /* core1 raw_pc bit6 */
			{38278,36,0}, /* core1 raw_pc bit7 */
			{38277,36,0}, /* core1 raw_pc bit8 */
			{38276,36,0}, /* core1 raw_pc bit9 */
			{38275,36,0}, /* core1 raw_pc bit10 */
			{35637,36,0}, /* core1 raw_pc bit11 */
			{35636,36,0}, /* core1 raw_pc bit12 */
			{35635,36,0}, /* core1 raw_pc bit13 */
			{35634,36,0}, /* core1 raw_pc bit14 */
			{38282,36,0}, /* core1 raw_pc bit15 */
			{38281,36,0}, /* core1 raw_pc bit16 */
			{38280,36,0}, /* core1 raw_pc bit17 */
			{38279,36,0}, /* core1 raw_pc bit18 */
			{35641,36,0}, /* core1 raw_pc bit19 */
			{35640,36,0}, /* core1 raw_pc bit20 */
			{32562,36,1}, /* core1 raw_pc bit21 */
			{32561,36,1}, /* core1 raw_pc bit22 */
			{38286,36,0}, /* core1 raw_pc bit23 */
			{38285,36,0}, /* core1 raw_pc bit24 */
			{38284,36,0}, /* core1 raw_pc bit25 */
			{38283,36,0}, /* core1 raw_pc bit26 */
			{35633,36,0}, /* core1 raw_pc bit27 */
			{35632,36,0}, /* core1 raw_pc bit28 */
			{35639,36,0}, /* core1 raw_pc bit29 */
			{35638,36,0}, /* core1 raw_pc bit30 */
			{38274,36,0}, /* core1 raw_pc bit31 */
			{38273,36,0}, /* core1 raw_pc bit32 */
			{38272,36,0}, /* core1 raw_pc bit33 */
			{38271,36,0}, /* core1 raw_pc bit34 */
			{40754,36,0}, /* core1 raw_pc bit35 */
			{40753,36,0}, /* core1 raw_pc bit36 */
			{40752,36,0}, /* core1 raw_pc bit37 */
			{40751,36,0}, /* core1 raw_pc bit38 */
			{35645,36,0}, /* core1 raw_pc bit39 */
			{35644,36,0}, /* core1 raw_pc bit40 */
			{40750,36,0}, /* core1 raw_pc bit41 */
			{40749,36,0}, /* core1 raw_pc bit42 */
			{35647,36,0}, /* core1 raw_pc bit43 */
			{35646,36,0}, /* core1 raw_pc bit44 */
			{40748,36,0}, /* core1 raw_pc bit45 */
			{40747,36,0}, /* core1 raw_pc bit46 */
			{32577,36,1}, /* core1 raw_pc bit47 */
			{32578,36,1}, /* core1 raw_pc bit48 */
			{32579,36,1}, /* core1 raw_pc bit49 */
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
			{32555,36,1}, /* core1 pc_iss bit0 */
			{32637,36,1}, /* core1 pc_iss bit1 */
			{32634,36,1}, /* core1 pc_iss bit2 */
			{32633,36,1}, /* core1 pc_iss bit3 */
			{32635,36,1}, /* core1 pc_iss bit4 */
			{32554,36,1}, /* core1 pc_iss bit5 */
			{32556,36,1}, /* core1 pc_iss bit6 */
			{32636,36,1}, /* core1 pc_iss bit7 */
			{32610,36,1}, /* core1 pc_iss bit8 */
			{32603,36,1}, /* core1 pc_iss bit9 */
			{32632,36,1}, /* core1 pc_iss bit10 */
			{32631,36,1}, /* core1 pc_iss bit11 */
			{32629,36,1}, /* core1 pc_iss bit12 */
			{32630,36,1}, /* core1 pc_iss bit13 */
			{32628,36,1}, /* core1 pc_iss bit14 */
			{32614,36,1}, /* core1 pc_iss bit15 */
			{32615,36,1}, /* core1 pc_iss bit16 */
			{32627,36,1}, /* core1 pc_iss bit17 */
			{32624,36,1}, /* core1 pc_iss bit18 */
			{32617,36,1}, /* core1 pc_iss bit19 */
			{32625,36,1}, /* core1 pc_iss bit20 */
			{32626,36,1}, /* core1 pc_iss bit21 */
			{32611,36,1}, /* core1 pc_iss bit22 */
			{32618,36,1}, /* core1 pc_iss bit23 */
			{32622,36,1}, /* core1 pc_iss bit24 */
			{32621,36,1}, /* core1 pc_iss bit25 */
			{32619,36,1}, /* core1 pc_iss bit26 */
			{32612,36,1}, /* core1 pc_iss bit27 */
			{32613,36,1}, /* core1 pc_iss bit28 */
			{32620,36,1}, /* core1 pc_iss bit29 */
			{32616,36,1}, /* core1 pc_iss bit30 */
			{32623,36,1}, /* core1 pc_iss bit31 */
			{32573,36,1}, /* core1 pc_iss bit32 */
			{32574,36,1}, /* core1 pc_iss bit33 */
			{32563,36,1}, /* core1 pc_iss bit34 */
			{32564,36,1}, /* core1 pc_iss bit35 */
			{32570,36,1}, /* core1 pc_iss bit36 */
			{32566,36,1}, /* core1 pc_iss bit37 */
			{32571,36,1}, /* core1 pc_iss bit38 */
			{32565,36,1}, /* core1 pc_iss bit39 */
			{32572,36,1}, /* core1 pc_iss bit40 */
			{32568,36,1}, /* core1 pc_iss bit41 */
			{32567,36,1}, /* core1 pc_iss bit42 */
			{32569,36,1}, /* core1 pc_iss bit43 */
			{35685,36,0}, /* core1 pc_iss bit44 */
			{35684,36,0}, /* core1 pc_iss bit45 */
			{35683,36,0}, /* core1 pc_iss bit46 */
			{35682,36,0}, /* core1 pc_iss bit47 */
			{38270,36,0}, /* core1 pc_iss bit48 */
			{38269,36,0}, /* core1 pc_iss bit49 */
			{38268,36,0}, /* core1 pc_iss bit50 */
			{38267,36,0}, /* core1 pc_iss bit51 */
			{38266,36,0}, /* core1 pc_iss bit52 */
			{38265,36,0}, /* core1 pc_iss bit53 */
			{38264,36,0}, /* core1 pc_iss bit54 */
			{38263,36,0}, /* core1 pc_iss bit55 */
			{40956,36,0}, /* core1 pc_iss bit56 */
			{40955,36,0}, /* core1 pc_iss bit57 */
			{40954,36,0}, /* core1 pc_iss bit58 */
			{40953,36,0}, /* core1 pc_iss bit59 */
			{40952,36,0}, /* core1 pc_iss bit60 */
			{40951,36,0}, /* core1 pc_iss bit61 */
			{40950,36,0}, /* core1 pc_iss bit62 */
			{40949,36,0}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{32557,36,1}, /* core1 full_pc_wr bit0 */
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
			{41124,36,0}, /* core1 full_pc_ex1 bit0 */
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
			{41116,36,0}, /* core1 full_pc_ex2 bit0 */
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
			{25953,37,1}, /* core1 return_Stack_pointer bit0 */
			{28673,37,1}, /* core1 return_Stack_pointer bit1 */
			{28674,37,1}, /* core1 return_Stack_pointer bit2 */
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
			{32644,37,1}, /* core1 return_Stack0 bit0 */
			{32643,37,1}, /* core1 return_Stack0 bit1 */
			{32672,37,1}, /* core1 return_Stack0 bit2 */
			{32671,37,1}, /* core1 return_Stack0 bit3 */
			{32670,37,1}, /* core1 return_Stack0 bit4 */
			{32669,37,1}, /* core1 return_Stack0 bit5 */
			{28860,37,1}, /* core1 return_Stack0 bit6 */
			{28859,37,1}, /* core1 return_Stack0 bit7 */
			{28858,37,1}, /* core1 return_Stack0 bit8 */
			{28857,37,1}, /* core1 return_Stack0 bit9 */
			{37875,37,1}, /* core1 return_Stack0 bit10 */
			{37874,37,1}, /* core1 return_Stack0 bit11 */
			{37873,37,1}, /* core1 return_Stack0 bit12 */
			{37872,37,1}, /* core1 return_Stack0 bit13 */
			{37871,37,1}, /* core1 return_Stack0 bit14 */
			{37870,37,1}, /* core1 return_Stack0 bit15 */
			{37869,37,1}, /* core1 return_Stack0 bit16 */
			{32642,37,1}, /* core1 return_Stack0 bit17 */
			{37868,37,1}, /* core1 return_Stack0 bit18 */
			{32648,37,1}, /* core1 return_Stack0 bit19 */
			{32647,37,1}, /* core1 return_Stack0 bit20 */
			{32646,37,1}, /* core1 return_Stack0 bit21 */
			{32645,37,1}, /* core1 return_Stack0 bit22 */
			{32641,37,1}, /* core1 return_Stack0 bit23 */
			{26154,37,1}, /* core1 return_Stack0 bit24 */
			{26153,37,1}, /* core1 return_Stack0 bit25 */
			{28780,37,1}, /* core1 return_Stack0 bit26 */
			{28779,37,1}, /* core1 return_Stack0 bit27 */
			{32656,37,1}, /* core1 return_Stack0 bit28 */
			{32655,37,1}, /* core1 return_Stack0 bit29 */
			{32654,37,1}, /* core1 return_Stack0 bit30 */
			{26152,37,1}, /* core1 return_Stack0 bit31 */
			{32653,37,1}, /* core1 return_Stack0 bit32 */
			{28770,37,1}, /* core1 return_Stack0 bit33 */
			{28769,37,1}, /* core1 return_Stack0 bit34 */
			{25973,37,1}, /* core1 return_Stack0 bit35 */
			{28772,37,1}, /* core1 return_Stack0 bit36 */
			{28771,37,1}, /* core1 return_Stack0 bit37 */
			{32832,37,1}, /* core1 return_Stack0 bit38 */
			{32831,37,1}, /* core1 return_Stack0 bit39 */
			{32830,37,1}, /* core1 return_Stack0 bit40 */
			{32829,37,1}, /* core1 return_Stack0 bit41 */
			{25972,37,1}, /* core1 return_Stack0 bit42 */
			{28774,37,1}, /* core1 return_Stack0 bit43 */
			{28773,37,1}, /* core1 return_Stack0 bit44 */
			{28776,37,1}, /* core1 return_Stack0 bit45 */
			{28775,37,1}, /* core1 return_Stack0 bit46 */
			{28778,37,1}, /* core1 return_Stack0 bit47 */
			{28777,37,1}, /* core1 return_Stack0 bit48 */
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
			{28812,37,1}, /* core1 return_Stack1 bit0 */
			{28811,37,1}, /* core1 return_Stack1 bit1 */
			{32716,37,1}, /* core1 return_Stack1 bit2 */
			{32715,37,1}, /* core1 return_Stack1 bit3 */
			{32720,37,1}, /* core1 return_Stack1 bit4 */
			{32719,37,1}, /* core1 return_Stack1 bit5 */
			{32718,37,1}, /* core1 return_Stack1 bit6 */
			{32717,37,1}, /* core1 return_Stack1 bit7 */
			{28818,37,1}, /* core1 return_Stack1 bit8 */
			{28817,37,1}, /* core1 return_Stack1 bit9 */
			{32714,37,1}, /* core1 return_Stack1 bit10 */
			{32713,37,1}, /* core1 return_Stack1 bit11 */
			{32724,37,1}, /* core1 return_Stack1 bit12 */
			{32723,37,1}, /* core1 return_Stack1 bit13 */
			{32722,37,1}, /* core1 return_Stack1 bit14 */
			{32721,37,1}, /* core1 return_Stack1 bit15 */
			{28820,37,1}, /* core1 return_Stack1 bit16 */
			{28819,37,1}, /* core1 return_Stack1 bit17 */
			{28816,37,1}, /* core1 return_Stack1 bit18 */
			{28815,37,1}, /* core1 return_Stack1 bit19 */
			{28814,37,1}, /* core1 return_Stack1 bit20 */
			{28813,37,1}, /* core1 return_Stack1 bit21 */
			{26163,37,1}, /* core1 return_Stack1 bit22 */
			{26165,37,1}, /* core1 return_Stack1 bit23 */
			{26164,37,1}, /* core1 return_Stack1 bit24 */
			{32736,37,1}, /* core1 return_Stack1 bit25 */
			{32735,37,1}, /* core1 return_Stack1 bit26 */
			{32734,37,1}, /* core1 return_Stack1 bit27 */
			{32733,37,1}, /* core1 return_Stack1 bit28 */
			{28810,37,1}, /* core1 return_Stack1 bit29 */
			{28809,37,1}, /* core1 return_Stack1 bit30 */
			{26166,37,1}, /* core1 return_Stack1 bit31 */
			{28808,37,1}, /* core1 return_Stack1 bit32 */
			{28806,37,1}, /* core1 return_Stack1 bit33 */
			{28805,37,1}, /* core1 return_Stack1 bit34 */
			{28807,37,1}, /* core1 return_Stack1 bit35 */
			{26167,37,1}, /* core1 return_Stack1 bit36 */
			{32784,37,1}, /* core1 return_Stack1 bit37 */
			{32783,37,1}, /* core1 return_Stack1 bit38 */
			{32782,37,1}, /* core1 return_Stack1 bit39 */
			{32781,37,1}, /* core1 return_Stack1 bit40 */
			{32788,37,1}, /* core1 return_Stack1 bit41 */
			{32787,37,1}, /* core1 return_Stack1 bit42 */
			{32786,37,1}, /* core1 return_Stack1 bit43 */
			{32785,37,1}, /* core1 return_Stack1 bit44 */
			{32792,37,1}, /* core1 return_Stack1 bit45 */
			{32791,37,1}, /* core1 return_Stack1 bit46 */
			{32790,37,1}, /* core1 return_Stack1 bit47 */
			{32789,37,1}, /* core1 return_Stack1 bit48 */
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
			{28856,37,1}, /* core1 return_Stack2 bit0 */
			{28855,37,1}, /* core1 return_Stack2 bit1 */
			{28854,37,1}, /* core1 return_Stack2 bit2 */
			{28853,37,1}, /* core1 return_Stack2 bit3 */
			{32676,37,1}, /* core1 return_Stack2 bit4 */
			{32675,37,1}, /* core1 return_Stack2 bit5 */
			{32674,37,1}, /* core1 return_Stack2 bit6 */
			{32673,37,1}, /* core1 return_Stack2 bit7 */
			{32680,37,1}, /* core1 return_Stack2 bit8 */
			{32679,37,1}, /* core1 return_Stack2 bit9 */
			{32678,37,1}, /* core1 return_Stack2 bit10 */
			{32677,37,1}, /* core1 return_Stack2 bit11 */
			{28846,37,1}, /* core1 return_Stack2 bit12 */
			{28845,37,1}, /* core1 return_Stack2 bit13 */
			{28848,37,1}, /* core1 return_Stack2 bit14 */
			{28847,37,1}, /* core1 return_Stack2 bit15 */
			{28852,37,1}, /* core1 return_Stack2 bit16 */
			{28851,37,1}, /* core1 return_Stack2 bit17 */
			{28844,37,1}, /* core1 return_Stack2 bit18 */
			{28843,37,1}, /* core1 return_Stack2 bit19 */
			{28850,37,1}, /* core1 return_Stack2 bit20 */
			{28849,37,1}, /* core1 return_Stack2 bit21 */
			{26155,37,1}, /* core1 return_Stack2 bit22 */
			{26156,37,1}, /* core1 return_Stack2 bit23 */
			{26157,37,1}, /* core1 return_Stack2 bit24 */
			{32652,37,1}, /* core1 return_Stack2 bit25 */
			{32651,37,1}, /* core1 return_Stack2 bit26 */
			{32650,37,1}, /* core1 return_Stack2 bit27 */
			{32649,37,1}, /* core1 return_Stack2 bit28 */
			{32756,37,1}, /* core1 return_Stack2 bit29 */
			{32755,37,1}, /* core1 return_Stack2 bit30 */
			{32754,37,1}, /* core1 return_Stack2 bit31 */
			{32753,37,1}, /* core1 return_Stack2 bit32 */
			{32824,37,1}, /* core1 return_Stack2 bit33 */
			{32823,37,1}, /* core1 return_Stack2 bit34 */
			{32822,37,1}, /* core1 return_Stack2 bit35 */
			{32821,37,1}, /* core1 return_Stack2 bit36 */
			{32820,37,1}, /* core1 return_Stack2 bit37 */
			{32819,37,1}, /* core1 return_Stack2 bit38 */
			{32818,37,1}, /* core1 return_Stack2 bit39 */
			{32817,37,1}, /* core1 return_Stack2 bit40 */
			{32828,37,1}, /* core1 return_Stack2 bit41 */
			{32827,37,1}, /* core1 return_Stack2 bit42 */
			{32826,37,1}, /* core1 return_Stack2 bit43 */
			{32825,37,1}, /* core1 return_Stack2 bit44 */
			{32760,37,1}, /* core1 return_Stack2 bit45 */
			{32759,37,1}, /* core1 return_Stack2 bit46 */
			{32758,37,1}, /* core1 return_Stack2 bit47 */
			{32757,37,1}, /* core1 return_Stack2 bit48 */
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
			{28802,37,1}, /* core1 return_Stack3 bit0 */
			{28801,37,1}, /* core1 return_Stack3 bit1 */
			{28824,37,1}, /* core1 return_Stack3 bit2 */
			{28826,37,1}, /* core1 return_Stack3 bit3 */
			{28825,37,1}, /* core1 return_Stack3 bit4 */
			{28822,37,1}, /* core1 return_Stack3 bit5 */
			{28821,37,1}, /* core1 return_Stack3 bit6 */
			{28796,37,1}, /* core1 return_Stack3 bit7 */
			{28795,37,1}, /* core1 return_Stack3 bit8 */
			{28823,37,1}, /* core1 return_Stack3 bit9 */
			{28798,37,1}, /* core1 return_Stack3 bit10 */
			{28830,37,1}, /* core1 return_Stack3 bit11 */
			{28829,37,1}, /* core1 return_Stack3 bit12 */
			{28828,37,1}, /* core1 return_Stack3 bit13 */
			{28827,37,1}, /* core1 return_Stack3 bit14 */
			{32708,37,1}, /* core1 return_Stack3 bit15 */
			{28800,37,1}, /* core1 return_Stack3 bit16 */
			{28799,37,1}, /* core1 return_Stack3 bit17 */
			{32707,37,1}, /* core1 return_Stack3 bit18 */
			{32706,37,1}, /* core1 return_Stack3 bit19 */
			{32705,37,1}, /* core1 return_Stack3 bit20 */
			{28797,37,1}, /* core1 return_Stack3 bit21 */
			{26158,37,1}, /* core1 return_Stack3 bit22 */
			{26162,37,1}, /* core1 return_Stack3 bit23 */
			{26159,37,1}, /* core1 return_Stack3 bit24 */
			{26160,37,1}, /* core1 return_Stack3 bit25 */
			{32744,37,1}, /* core1 return_Stack3 bit26 */
			{32743,37,1}, /* core1 return_Stack3 bit27 */
			{32742,37,1}, /* core1 return_Stack3 bit28 */
			{32796,37,1}, /* core1 return_Stack3 bit29 */
			{32741,37,1}, /* core1 return_Stack3 bit30 */
			{32795,37,1}, /* core1 return_Stack3 bit31 */
			{28804,37,1}, /* core1 return_Stack3 bit32 */
			{32794,37,1}, /* core1 return_Stack3 bit33 */
			{32793,37,1}, /* core1 return_Stack3 bit34 */
			{28803,37,1}, /* core1 return_Stack3 bit35 */
			{32776,37,1}, /* core1 return_Stack3 bit36 */
			{32775,37,1}, /* core1 return_Stack3 bit37 */
			{32774,37,1}, /* core1 return_Stack3 bit38 */
			{32780,37,1}, /* core1 return_Stack3 bit39 */
			{32779,37,1}, /* core1 return_Stack3 bit40 */
			{32778,37,1}, /* core1 return_Stack3 bit41 */
			{32777,37,1}, /* core1 return_Stack3 bit42 */
			{32800,37,1}, /* core1 return_Stack3 bit43 */
			{32799,37,1}, /* core1 return_Stack3 bit44 */
			{32798,37,1}, /* core1 return_Stack3 bit45 */
			{32797,37,1}, /* core1 return_Stack3 bit46 */
			{32773,37,1}, /* core1 return_Stack3 bit47 */
			{26161,37,1}, /* core1 return_Stack3 bit48 */
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
			{32664,37,1}, /* core1 return_Stack4 bit0 */
			{32663,37,1}, /* core1 return_Stack4 bit1 */
			{32636,37,1}, /* core1 return_Stack4 bit2 */
			{32635,37,1}, /* core1 return_Stack4 bit3 */
			{28864,37,1}, /* core1 return_Stack4 bit4 */
			{28863,37,1}, /* core1 return_Stack4 bit5 */
			{32640,37,1}, /* core1 return_Stack4 bit6 */
			{32639,37,1}, /* core1 return_Stack4 bit7 */
			{32638,37,1}, /* core1 return_Stack4 bit8 */
			{32637,37,1}, /* core1 return_Stack4 bit9 */
			{32634,37,1}, /* core1 return_Stack4 bit10 */
			{32633,37,1}, /* core1 return_Stack4 bit11 */
			{28862,37,1}, /* core1 return_Stack4 bit12 */
			{28861,37,1}, /* core1 return_Stack4 bit13 */
			{32668,37,1}, /* core1 return_Stack4 bit14 */
			{32667,37,1}, /* core1 return_Stack4 bit15 */
			{32662,37,1}, /* core1 return_Stack4 bit16 */
			{32661,37,1}, /* core1 return_Stack4 bit17 */
			{32666,37,1}, /* core1 return_Stack4 bit18 */
			{32665,37,1}, /* core1 return_Stack4 bit19 */
			{28866,37,1}, /* core1 return_Stack4 bit20 */
			{28865,37,1}, /* core1 return_Stack4 bit21 */
			{28868,37,1}, /* core1 return_Stack4 bit22 */
			{28867,37,1}, /* core1 return_Stack4 bit23 */
			{26150,37,1}, /* core1 return_Stack4 bit24 */
			{26151,37,1}, /* core1 return_Stack4 bit25 */
			{32660,37,1}, /* core1 return_Stack4 bit26 */
			{32659,37,1}, /* core1 return_Stack4 bit27 */
			{32658,37,1}, /* core1 return_Stack4 bit28 */
			{32844,37,1}, /* core1 return_Stack4 bit29 */
			{32843,37,1}, /* core1 return_Stack4 bit30 */
			{32842,37,1}, /* core1 return_Stack4 bit31 */
			{32657,37,1}, /* core1 return_Stack4 bit32 */
			{25971,37,1}, /* core1 return_Stack4 bit33 */
			{32841,37,1}, /* core1 return_Stack4 bit34 */
			{32840,37,1}, /* core1 return_Stack4 bit35 */
			{32839,37,1}, /* core1 return_Stack4 bit36 */
			{32838,37,1}, /* core1 return_Stack4 bit37 */
			{32837,37,1}, /* core1 return_Stack4 bit38 */
			{32836,37,1}, /* core1 return_Stack4 bit39 */
			{32835,37,1}, /* core1 return_Stack4 bit40 */
			{32834,37,1}, /* core1 return_Stack4 bit41 */
			{32833,37,1}, /* core1 return_Stack4 bit42 */
			{25970,37,1}, /* core1 return_Stack4 bit43 */
			{28872,37,1}, /* core1 return_Stack4 bit44 */
			{28871,37,1}, /* core1 return_Stack4 bit45 */
			{28870,37,1}, /* core1 return_Stack4 bit46 */
			{28869,37,1}, /* core1 return_Stack4 bit47 */
			{25969,37,1}, /* core1 return_Stack4 bit48 */
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
			{28790,37,1}, /* core1 return_Stack5 bit0 */
			{28789,37,1}, /* core1 return_Stack5 bit1 */
			{32696,37,1}, /* core1 return_Stack5 bit2 */
			{32695,37,1}, /* core1 return_Stack5 bit3 */
			{28794,37,1}, /* core1 return_Stack5 bit4 */
			{28793,37,1}, /* core1 return_Stack5 bit5 */
			{32692,37,1}, /* core1 return_Stack5 bit6 */
			{32691,37,1}, /* core1 return_Stack5 bit7 */
			{32690,37,1}, /* core1 return_Stack5 bit8 */
			{32689,37,1}, /* core1 return_Stack5 bit9 */
			{32694,37,1}, /* core1 return_Stack5 bit10 */
			{32693,37,1}, /* core1 return_Stack5 bit11 */
			{32700,37,1}, /* core1 return_Stack5 bit12 */
			{32699,37,1}, /* core1 return_Stack5 bit13 */
			{28792,37,1}, /* core1 return_Stack5 bit14 */
			{28791,37,1}, /* core1 return_Stack5 bit15 */
			{28788,37,1}, /* core1 return_Stack5 bit16 */
			{28787,37,1}, /* core1 return_Stack5 bit17 */
			{32698,37,1}, /* core1 return_Stack5 bit18 */
			{32704,37,1}, /* core1 return_Stack5 bit19 */
			{32703,37,1}, /* core1 return_Stack5 bit20 */
			{32702,37,1}, /* core1 return_Stack5 bit21 */
			{32697,37,1}, /* core1 return_Stack5 bit22 */
			{28786,37,1}, /* core1 return_Stack5 bit23 */
			{32701,37,1}, /* core1 return_Stack5 bit24 */
			{28785,37,1}, /* core1 return_Stack5 bit25 */
			{32752,37,1}, /* core1 return_Stack5 bit26 */
			{25968,37,1}, /* core1 return_Stack5 bit27 */
			{32751,37,1}, /* core1 return_Stack5 bit28 */
			{32750,37,1}, /* core1 return_Stack5 bit29 */
			{32749,37,1}, /* core1 return_Stack5 bit30 */
			{32808,37,1}, /* core1 return_Stack5 bit31 */
			{32807,37,1}, /* core1 return_Stack5 bit32 */
			{32806,37,1}, /* core1 return_Stack5 bit33 */
			{32805,37,1}, /* core1 return_Stack5 bit34 */
			{32812,37,1}, /* core1 return_Stack5 bit35 */
			{32811,37,1}, /* core1 return_Stack5 bit36 */
			{32810,37,1}, /* core1 return_Stack5 bit37 */
			{32809,37,1}, /* core1 return_Stack5 bit38 */
			{32804,37,1}, /* core1 return_Stack5 bit39 */
			{32803,37,1}, /* core1 return_Stack5 bit40 */
			{32802,37,1}, /* core1 return_Stack5 bit41 */
			{32801,37,1}, /* core1 return_Stack5 bit42 */
			{32816,37,1}, /* core1 return_Stack5 bit43 */
			{32815,37,1}, /* core1 return_Stack5 bit44 */
			{32814,37,1}, /* core1 return_Stack5 bit45 */
			{32813,37,1}, /* core1 return_Stack5 bit46 */
			{25955,37,1}, /* core1 return_Stack5 bit47 */
			{25956,37,1}, /* core1 return_Stack5 bit48 */
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
			{28784,37,1}, /* core1 return_Stack6 bit0 */
			{28783,37,1}, /* core1 return_Stack6 bit1 */
			{28838,37,1}, /* core1 return_Stack6 bit2 */
			{32688,37,1}, /* core1 return_Stack6 bit3 */
			{28837,37,1}, /* core1 return_Stack6 bit4 */
			{32687,37,1}, /* core1 return_Stack6 bit5 */
			{32686,37,1}, /* core1 return_Stack6 bit6 */
			{32685,37,1}, /* core1 return_Stack6 bit7 */
			{28834,37,1}, /* core1 return_Stack6 bit8 */
			{28833,37,1}, /* core1 return_Stack6 bit9 */
			{32684,37,1}, /* core1 return_Stack6 bit10 */
			{32683,37,1}, /* core1 return_Stack6 bit11 */
			{32682,37,1}, /* core1 return_Stack6 bit12 */
			{32681,37,1}, /* core1 return_Stack6 bit13 */
			{28840,37,1}, /* core1 return_Stack6 bit14 */
			{28839,37,1}, /* core1 return_Stack6 bit15 */
			{28836,37,1}, /* core1 return_Stack6 bit16 */
			{28835,37,1}, /* core1 return_Stack6 bit17 */
			{28842,37,1}, /* core1 return_Stack6 bit18 */
			{28841,37,1}, /* core1 return_Stack6 bit19 */
			{28832,37,1}, /* core1 return_Stack6 bit20 */
			{28831,37,1}, /* core1 return_Stack6 bit21 */
			{25960,37,1}, /* core1 return_Stack6 bit22 */
			{25959,37,1}, /* core1 return_Stack6 bit23 */
			{25967,37,1}, /* core1 return_Stack6 bit24 */
			{25966,37,1}, /* core1 return_Stack6 bit25 */
			{32748,37,1}, /* core1 return_Stack6 bit26 */
			{32747,37,1}, /* core1 return_Stack6 bit27 */
			{28782,37,1}, /* core1 return_Stack6 bit28 */
			{32746,37,1}, /* core1 return_Stack6 bit29 */
			{32745,37,1}, /* core1 return_Stack6 bit30 */
			{28781,37,1}, /* core1 return_Stack6 bit31 */
			{25958,37,1}, /* core1 return_Stack6 bit32 */
			{28680,37,1}, /* core1 return_Stack6 bit33 */
			{28679,37,1}, /* core1 return_Stack6 bit34 */
			{25954,37,1}, /* core1 return_Stack6 bit35 */
			{25957,37,1}, /* core1 return_Stack6 bit36 */
			{28678,37,1}, /* core1 return_Stack6 bit37 */
			{28677,37,1}, /* core1 return_Stack6 bit38 */
			{32764,37,1}, /* core1 return_Stack6 bit39 */
			{32763,37,1}, /* core1 return_Stack6 bit40 */
			{32762,37,1}, /* core1 return_Stack6 bit41 */
			{32761,37,1}, /* core1 return_Stack6 bit42 */
			{28676,37,1}, /* core1 return_Stack6 bit43 */
			{28675,37,1}, /* core1 return_Stack6 bit44 */
			{28664,37,1}, /* core1 return_Stack6 bit45 */
			{28663,37,1}, /* core1 return_Stack6 bit46 */
			{28662,37,1}, /* core1 return_Stack6 bit47 */
			{28661,37,1}, /* core1 return_Stack6 bit48 */
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
			{32712,37,1}, /* core1 return_Stack7 bit0 */
			{32711,37,1}, /* core1 return_Stack7 bit1 */
			{32732,37,1}, /* core1 return_Stack7 bit2 */
			{32731,37,1}, /* core1 return_Stack7 bit3 */
			{32730,37,1}, /* core1 return_Stack7 bit4 */
			{32729,37,1}, /* core1 return_Stack7 bit5 */
			{28652,37,1}, /* core1 return_Stack7 bit6 */
			{28651,37,1}, /* core1 return_Stack7 bit7 */
			{28654,37,1}, /* core1 return_Stack7 bit8 */
			{28653,37,1}, /* core1 return_Stack7 bit9 */
			{32728,37,1}, /* core1 return_Stack7 bit10 */
			{32727,37,1}, /* core1 return_Stack7 bit11 */
			{28650,37,1}, /* core1 return_Stack7 bit12 */
			{28649,37,1}, /* core1 return_Stack7 bit13 */
			{32710,37,1}, /* core1 return_Stack7 bit14 */
			{32726,37,1}, /* core1 return_Stack7 bit15 */
			{32709,37,1}, /* core1 return_Stack7 bit16 */
			{32725,37,1}, /* core1 return_Stack7 bit17 */
			{28656,37,1}, /* core1 return_Stack7 bit18 */
			{28655,37,1}, /* core1 return_Stack7 bit19 */
			{28658,37,1}, /* core1 return_Stack7 bit20 */
			{28657,37,1}, /* core1 return_Stack7 bit21 */
			{25961,37,1}, /* core1 return_Stack7 bit22 */
			{25962,37,1}, /* core1 return_Stack7 bit23 */
			{25963,37,1}, /* core1 return_Stack7 bit24 */
			{25965,37,1}, /* core1 return_Stack7 bit25 */
			{28660,37,1}, /* core1 return_Stack7 bit26 */
			{32740,37,1}, /* core1 return_Stack7 bit27 */
			{28659,37,1}, /* core1 return_Stack7 bit28 */
			{32739,37,1}, /* core1 return_Stack7 bit29 */
			{32738,37,1}, /* core1 return_Stack7 bit30 */
			{32737,37,1}, /* core1 return_Stack7 bit31 */
			{32768,37,1}, /* core1 return_Stack7 bit32 */
			{32767,37,1}, /* core1 return_Stack7 bit33 */
			{32766,37,1}, /* core1 return_Stack7 bit34 */
			{32765,37,1}, /* core1 return_Stack7 bit35 */
			{28670,37,1}, /* core1 return_Stack7 bit36 */
			{28669,37,1}, /* core1 return_Stack7 bit37 */
			{28672,37,1}, /* core1 return_Stack7 bit38 */
			{28671,37,1}, /* core1 return_Stack7 bit39 */
			{32772,37,1}, /* core1 return_Stack7 bit40 */
			{32771,37,1}, /* core1 return_Stack7 bit41 */
			{32770,37,1}, /* core1 return_Stack7 bit42 */
			{32769,37,1}, /* core1 return_Stack7 bit43 */
			{28666,37,1}, /* core1 return_Stack7 bit44 */
			{28665,37,1}, /* core1 return_Stack7 bit45 */
			{28668,37,1}, /* core1 return_Stack7 bit46 */
			{28667,37,1}, /* core1 return_Stack7 bit47 */
			{25964,37,1}, /* core1 return_Stack7 bit48 */
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
			{ 5700, 8,0}, /* core1 L2_parity_err_count bit0 */
			{ 5699, 8,0}, /* core1 L2_parity_err_count bit1 */
			{ 5698, 8,0}, /* core1 L2_parity_err_count bit2 */
			{ 5697, 8,0}, /* core1 L2_parity_err_count bit3 */
			{ 5696, 8,0}, /* core1 L2_parity_err_count bit4 */
			{ 5695, 8,0}, /* core1 L2_parity_err_count bit5 */
			{ 5694, 8,0}, /* core1 L2_parity_err_count bit6 */
			{ 5693, 8,0}, /* core1 L2_parity_err_count bit7 */
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
			{ 5708, 8,0}, /* core1 L2_parity_index bit0 */
			{ 5707, 8,0}, /* core1 L2_parity_index bit1 */
			{ 5706, 8,0}, /* core1 L2_parity_index bit2 */
			{ 5705, 8,0}, /* core1 L2_parity_index bit3 */
			{ 5704, 8,0}, /* core1 L2_parity_index bit4 */
			{ 5703, 8,0}, /* core1 L2_parity_index bit5 */
			{ 5702, 8,0}, /* core1 L2_parity_index bit6 */
			{ 5701, 8,0}, /* core1 L2_parity_index bit7 */
			{ 5716, 8,0}, /* core1 L2_parity_index bit8 */
			{ 5715, 8,0}, /* core1 L2_parity_index bit9 */
			{ 5714, 8,0}, /* core1 L2_parity_index bit10 */
			{ 5713, 8,0}, /* core1 L2_parity_index bit11 */
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
			{ 5709, 8,0}, /* core1 L2_parity_way bit0 */
			{ 5161, 8,0}, /* core1 L2_parity_way bit1 */
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
			{ 5830, 8,0}, /* core1 L2_parity_banks bit0 */
			{ 5829, 8,0}, /* core1 L2_parity_banks bit1 */
			{ 5828, 8,0}, /* core1 L2_parity_banks bit2 */
			{ 5827, 8,0}, /* core1 L2_parity_banks bit3 */
			{ 5826, 8,0}, /* core1 L2_parity_banks bit4 */
			{ 5825, 8,0}, /* core1 L2_parity_banks bit5 */
			{ 5824, 8,0}, /* core1 L2_parity_banks bit6 */
			{ 5823, 8,0}, /* core1 L2_parity_banks bit7 */
			{ 5822, 8,0}, /* core1 L2_parity_banks bit8 */
			{ 5821, 8,0}, /* core1 L2_parity_banks bit9 */
			{ 5820, 8,0}, /* core1 L2_parity_banks bit10 */
			{ 5819, 8,0}, /* core1 L2_parity_banks bit11 */
			{ 5818, 8,0}, /* core1 L2_parity_banks bit12 */
			{ 5817, 8,0}, /* core1 L2_parity_banks bit13 */
			{ 5816, 8,0}, /* core1 L2_parity_banks bit14 */
			{ 5815, 8,0}, /* core1 L2_parity_banks bit15 */
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
			{   95,38,1}, /* core2 pc bit0 */
			{  433,38,1}, /* core2 pc bit1 */
			{  432,38,1}, /* core2 pc bit2 */
			{  431,38,1}, /* core2 pc bit3 */
			{  430,38,1}, /* core2 pc bit4 */
			{  429,38,1}, /* core2 pc bit5 */
			{  495,38,1}, /* core2 pc bit6 */
			{  426,38,1}, /* core2 pc bit7 */
			{  494,38,1}, /* core2 pc bit8 */
			{  425,38,1}, /* core2 pc bit9 */
			{  424,38,1}, /* core2 pc bit10 */
			{  445,38,1}, /* core2 pc bit11 */
			{  493,38,1}, /* core2 pc bit12 */
			{  492,38,1}, /* core2 pc bit13 */
			{  444,38,1}, /* core2 pc bit14 */
			{  443,38,1}, /* core2 pc bit15 */
			{  466,38,1}, /* core2 pc bit16 */
			{  482,38,1}, /* core2 pc bit17 */
			{  465,38,1}, /* core2 pc bit18 */
			{  464,38,1}, /* core2 pc bit19 */
			{  470,38,1}, /* core2 pc bit20 */
			{  463,38,1}, /* core2 pc bit21 */
			{  440,38,1}, /* core2 pc bit22 */
			{  446,38,1}, /* core2 pc bit23 */
			{  491,38,1}, /* core2 pc bit24 */
			{  462,38,1}, /* core2 pc bit25 */
			{  481,38,1}, /* core2 pc bit26 */
			{  480,38,1}, /* core2 pc bit27 */
			{  461,38,1}, /* core2 pc bit28 */
			{  460,38,1}, /* core2 pc bit29 */
			{  448,38,1}, /* core2 pc bit30 */
			{  450,38,1}, /* core2 pc bit31 */
			{  270,38,1}, /* core2 pc bit32 */
			{  269,38,1}, /* core2 pc bit33 */
			{  268,38,1}, /* core2 pc bit34 */
			{  278,38,1}, /* core2 pc bit35 */
			{  320,38,1}, /* core2 pc bit36 */
			{  267,38,1}, /* core2 pc bit37 */
			{  266,38,1}, /* core2 pc bit38 */
			{  312,38,1}, /* core2 pc bit39 */
			{  162,38,1}, /* core2 pc bit40 */
			{  319,38,1}, /* core2 pc bit41 */
			{  318,38,1}, /* core2 pc bit42 */
			{  161,38,1}, /* core2 pc bit43 */
			{  160,38,1}, /* core2 pc bit44 */
			{  159,38,1}, /* core2 pc bit45 */
			{  317,38,1}, /* core2 pc bit46 */
			{  316,38,1}, /* core2 pc bit47 */
			{  140,38,1}, /* core2 pc bit48 */
			{  277,38,1}, /* core2 pc bit49 */
			{  276,38,1}, /* core2 pc bit50 */
			{  275,38,1}, /* core2 pc bit51 */
			{  274,38,1}, /* core2 pc bit52 */
			{  139,38,1}, /* core2 pc bit53 */
			{  280,38,1}, /* core2 pc bit54 */
			{  279,38,1}, /* core2 pc bit55 */
			{  353,38,1}, /* core2 pc bit56 */
			{  273,38,1}, /* core2 pc bit57 */
			{  288,38,1}, /* core2 pc bit58 */
			{  287,38,1}, /* core2 pc bit59 */
			{  138,38,1}, /* core2 pc bit60 */
			{  264,38,1}, /* core2 pc bit61 */
			{  263,38,1}, /* core2 pc bit62 */
			{  145,38,1}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{41179,39,1}, /* core2 sp32 bit0 */
			{41177,39,1}, /* core2 sp32 bit1 */
			{41176,39,1}, /* core2 sp32 bit2 */
			{41175,39,1}, /* core2 sp32 bit3 */
			{41178,39,1}, /* core2 sp32 bit4 */
			{41171,39,1}, /* core2 sp32 bit5 */
			{41170,39,1}, /* core2 sp32 bit6 */
			{41172,39,1}, /* core2 sp32 bit7 */
			{41173,39,1}, /* core2 sp32 bit8 */
			{41174,39,1}, /* core2 sp32 bit9 */
			{41197,39,1}, /* core2 sp32 bit10 */
			{41190,39,1}, /* core2 sp32 bit11 */
			{41182,39,1}, /* core2 sp32 bit12 */
			{41201,39,1}, /* core2 sp32 bit13 */
			{41184,39,1}, /* core2 sp32 bit14 */
			{41198,39,1}, /* core2 sp32 bit15 */
			{34300,38,0}, /* core2 sp32 bit16 */
			{34299,38,0}, /* core2 sp32 bit17 */
			{34328,38,0}, /* core2 sp32 bit18 */
			{34327,38,0}, /* core2 sp32 bit19 */
			{41196,39,1}, /* core2 sp32 bit20 */
			{41185,39,1}, /* core2 sp32 bit21 */
			{41227,39,1}, /* core2 sp32 bit22 */
			{41226,39,1}, /* core2 sp32 bit23 */
			{41180,39,1}, /* core2 sp32 bit24 */
			{41181,39,1}, /* core2 sp32 bit25 */
			{41183,39,1}, /* core2 sp32 bit26 */
			{41186,39,1}, /* core2 sp32 bit27 */
			{41199,39,1}, /* core2 sp32 bit28 */
			{41191,39,1}, /* core2 sp32 bit29 */
			{41188,39,1}, /* core2 sp32 bit30 */
			{41189,39,1}, /* core2 sp32 bit31 */
			{41121,39,1}, /* core2 sp32 bit32 */
			{41123,39,1}, /* core2 sp32 bit33 */
			{41113,39,1}, /* core2 sp32 bit34 */
			{41115,39,1}, /* core2 sp32 bit35 */
			{41120,39,1}, /* core2 sp32 bit36 */
			{41118,39,1}, /* core2 sp32 bit37 */
			{41122,39,1}, /* core2 sp32 bit38 */
			{41117,39,1}, /* core2 sp32 bit39 */
			{41116,39,1}, /* core2 sp32 bit40 */
			{41119,39,1}, /* core2 sp32 bit41 */
			{41108,39,1}, /* core2 sp32 bit42 */
			{41109,39,1}, /* core2 sp32 bit43 */
			{41110,39,1}, /* core2 sp32 bit44 */
			{41114,39,1}, /* core2 sp32 bit45 */
			{41111,39,1}, /* core2 sp32 bit46 */
			{41112,39,1}, /* core2 sp32 bit47 */
			{41159,39,1}, /* core2 sp32 bit48 */
			{41164,39,1}, /* core2 sp32 bit49 */
			{34350,38,0}, /* core2 sp32 bit50 */
			{34349,38,0}, /* core2 sp32 bit51 */
			{41166,39,1}, /* core2 sp32 bit52 */
			{41165,39,1}, /* core2 sp32 bit53 */
			{41163,39,1}, /* core2 sp32 bit54 */
			{41161,39,1}, /* core2 sp32 bit55 */
			{41167,39,1}, /* core2 sp32 bit56 */
			{41160,39,1}, /* core2 sp32 bit57 */
			{41162,39,1}, /* core2 sp32 bit58 */
			{41158,39,1}, /* core2 sp32 bit59 */
			{41157,39,1}, /* core2 sp32 bit60 */
			{41155,39,1}, /* core2 sp32 bit61 */
			{41154,39,1}, /* core2 sp32 bit62 */
			{41156,39,1}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{41650,39,1}, /* core2 fp32 bit0 */
			{41651,39,1}, /* core2 fp32 bit1 */
			{41648,39,1}, /* core2 fp32 bit2 */
			{41645,39,1}, /* core2 fp32 bit3 */
			{41652,39,1}, /* core2 fp32 bit4 */
			{41647,39,1}, /* core2 fp32 bit5 */
			{41644,39,1}, /* core2 fp32 bit6 */
			{41646,39,1}, /* core2 fp32 bit7 */
			{41643,39,1}, /* core2 fp32 bit8 */
			{41642,39,1}, /* core2 fp32 bit9 */
			{41676,39,1}, /* core2 fp32 bit10 */
			{41675,39,1}, /* core2 fp32 bit11 */
			{41685,39,1}, /* core2 fp32 bit12 */
			{41684,39,1}, /* core2 fp32 bit13 */
			{41680,39,1}, /* core2 fp32 bit14 */
			{41681,39,1}, /* core2 fp32 bit15 */
			{41682,39,1}, /* core2 fp32 bit16 */
			{41656,39,1}, /* core2 fp32 bit17 */
			{41678,39,1}, /* core2 fp32 bit18 */
			{41683,39,1}, /* core2 fp32 bit19 */
			{41677,39,1}, /* core2 fp32 bit20 */
			{41672,39,1}, /* core2 fp32 bit21 */
			{41686,39,1}, /* core2 fp32 bit22 */
			{41649,39,1}, /* core2 fp32 bit23 */
			{41688,39,1}, /* core2 fp32 bit24 */
			{41689,39,1}, /* core2 fp32 bit25 */
			{41669,39,1}, /* core2 fp32 bit26 */
			{41670,39,1}, /* core2 fp32 bit27 */
			{41673,39,1}, /* core2 fp32 bit28 */
			{41679,39,1}, /* core2 fp32 bit29 */
			{41674,39,1}, /* core2 fp32 bit30 */
			{41671,39,1}, /* core2 fp32 bit31 */
			{41580,39,1}, /* core2 fp32 bit32 */
			{41589,39,1}, /* core2 fp32 bit33 */
			{41583,39,1}, /* core2 fp32 bit34 */
			{41587,39,1}, /* core2 fp32 bit35 */
			{41582,39,1}, /* core2 fp32 bit36 */
			{41575,39,1}, /* core2 fp32 bit37 */
			{41576,39,1}, /* core2 fp32 bit38 */
			{41585,39,1}, /* core2 fp32 bit39 */
			{41584,39,1}, /* core2 fp32 bit40 */
			{41581,39,1}, /* core2 fp32 bit41 */
			{41588,39,1}, /* core2 fp32 bit42 */
			{41577,39,1}, /* core2 fp32 bit43 */
			{41578,39,1}, /* core2 fp32 bit44 */
			{41579,39,1}, /* core2 fp32 bit45 */
			{41574,39,1}, /* core2 fp32 bit46 */
			{41586,39,1}, /* core2 fp32 bit47 */
			{41605,39,1}, /* core2 fp32 bit48 */
			{41604,39,1}, /* core2 fp32 bit49 */
			{41606,39,1}, /* core2 fp32 bit50 */
			{41609,39,1}, /* core2 fp32 bit51 */
			{41607,39,1}, /* core2 fp32 bit52 */
			{41610,39,1}, /* core2 fp32 bit53 */
			{41602,39,1}, /* core2 fp32 bit54 */
			{41597,39,1}, /* core2 fp32 bit55 */
			{41608,39,1}, /* core2 fp32 bit56 */
			{41598,39,1}, /* core2 fp32 bit57 */
			{41601,39,1}, /* core2 fp32 bit58 */
			{41596,39,1}, /* core2 fp32 bit59 */
			{41593,39,1}, /* core2 fp32 bit60 */
			{34376,38,0}, /* core2 fp32 bit61 */
			{34375,38,0}, /* core2 fp32 bit62 */
			{41594,39,1}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{40573,39,1}, /* core2 fp64 bit0 */
			{40571,39,1}, /* core2 fp64 bit1 */
			{40569,39,1}, /* core2 fp64 bit2 */
			{34306,38,0}, /* core2 fp64 bit3 */
			{34305,38,0}, /* core2 fp64 bit4 */
			{40567,39,1}, /* core2 fp64 bit5 */
			{40568,39,1}, /* core2 fp64 bit6 */
			{34304,38,0}, /* core2 fp64 bit7 */
			{34303,38,0}, /* core2 fp64 bit8 */
			{40570,39,1}, /* core2 fp64 bit9 */
			{40560,39,1}, /* core2 fp64 bit10 */
			{40558,39,1}, /* core2 fp64 bit11 */
			{40566,39,1}, /* core2 fp64 bit12 */
			{40565,39,1}, /* core2 fp64 bit13 */
			{40564,39,1}, /* core2 fp64 bit14 */
			{40559,39,1}, /* core2 fp64 bit15 */
			{40554,39,1}, /* core2 fp64 bit16 */
			{40490,39,1}, /* core2 fp64 bit17 */
			{40552,39,1}, /* core2 fp64 bit18 */
			{40555,39,1}, /* core2 fp64 bit19 */
			{40557,39,1}, /* core2 fp64 bit20 */
			{40553,39,1}, /* core2 fp64 bit21 */
			{40572,39,1}, /* core2 fp64 bit22 */
			{40491,39,1}, /* core2 fp64 bit23 */
			{40492,39,1}, /* core2 fp64 bit24 */
			{40493,39,1}, /* core2 fp64 bit25 */
			{40563,39,1}, /* core2 fp64 bit26 */
			{34322,38,0}, /* core2 fp64 bit27 */
			{34321,38,0}, /* core2 fp64 bit28 */
			{40562,39,1}, /* core2 fp64 bit29 */
			{40561,39,1}, /* core2 fp64 bit30 */
			{40556,39,1}, /* core2 fp64 bit31 */
			{40702,39,1}, /* core2 fp64 bit32 */
			{40697,39,1}, /* core2 fp64 bit33 */
			{40699,39,1}, /* core2 fp64 bit34 */
			{40708,39,1}, /* core2 fp64 bit35 */
			{40706,39,1}, /* core2 fp64 bit36 */
			{40701,39,1}, /* core2 fp64 bit37 */
			{40703,39,1}, /* core2 fp64 bit38 */
			{40705,39,1}, /* core2 fp64 bit39 */
			{40704,39,1}, /* core2 fp64 bit40 */
			{40698,39,1}, /* core2 fp64 bit41 */
			{40707,39,1}, /* core2 fp64 bit42 */
			{40700,39,1}, /* core2 fp64 bit43 */
			{40709,39,1}, /* core2 fp64 bit44 */
			{40696,39,1}, /* core2 fp64 bit45 */
			{40727,39,1}, /* core2 fp64 bit46 */
			{40695,39,1}, /* core2 fp64 bit47 */
			{40690,39,1}, /* core2 fp64 bit48 */
			{40638,39,1}, /* core2 fp64 bit49 */
			{40642,39,1}, /* core2 fp64 bit50 */
			{40645,39,1}, /* core2 fp64 bit51 */
			{40644,39,1}, /* core2 fp64 bit52 */
			{40643,39,1}, /* core2 fp64 bit53 */
			{40637,39,1}, /* core2 fp64 bit54 */
			{40632,39,1}, /* core2 fp64 bit55 */
			{40646,39,1}, /* core2 fp64 bit56 */
			{40633,39,1}, /* core2 fp64 bit57 */
			{40635,39,1}, /* core2 fp64 bit58 */
			{40691,39,1}, /* core2 fp64 bit59 */
			{40693,39,1}, /* core2 fp64 bit60 */
			{40726,39,1}, /* core2 fp64 bit61 */
			{40692,39,1}, /* core2 fp64 bit62 */
			{40694,39,1}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40577,39,1}, /* core2 sp_EL0 bit0 */
			{40575,39,1}, /* core2 sp_EL0 bit1 */
			{40580,39,1}, /* core2 sp_EL0 bit2 */
			{40582,39,1}, /* core2 sp_EL0 bit3 */
			{40583,39,1}, /* core2 sp_EL0 bit4 */
			{40581,39,1}, /* core2 sp_EL0 bit5 */
			{34278,38,0}, /* core2 sp_EL0 bit6 */
			{34277,38,0}, /* core2 sp_EL0 bit7 */
			{40578,39,1}, /* core2 sp_EL0 bit8 */
			{40576,39,1}, /* core2 sp_EL0 bit9 */
			{40488,39,1}, /* core2 sp_EL0 bit10 */
			{40487,39,1}, /* core2 sp_EL0 bit11 */
			{34276,38,0}, /* core2 sp_EL0 bit12 */
			{34275,38,0}, /* core2 sp_EL0 bit13 */
			{40579,39,1}, /* core2 sp_EL0 bit14 */
			{40574,39,1}, /* core2 sp_EL0 bit15 */
			{34284,38,0}, /* core2 sp_EL0 bit16 */
			{34283,38,0}, /* core2 sp_EL0 bit17 */
			{40489,39,1}, /* core2 sp_EL0 bit18 */
			{40486,39,1}, /* core2 sp_EL0 bit19 */
			{40485,39,1}, /* core2 sp_EL0 bit20 */
			{40484,39,1}, /* core2 sp_EL0 bit21 */
			{40306,39,1}, /* core2 sp_EL0 bit22 */
			{40302,39,1}, /* core2 sp_EL0 bit23 */
			{40304,39,1}, /* core2 sp_EL0 bit24 */
			{40305,39,1}, /* core2 sp_EL0 bit25 */
			{40282,39,1}, /* core2 sp_EL0 bit26 */
			{40283,39,1}, /* core2 sp_EL0 bit27 */
			{40285,39,1}, /* core2 sp_EL0 bit28 */
			{40284,39,1}, /* core2 sp_EL0 bit29 */
			{40286,39,1}, /* core2 sp_EL0 bit30 */
			{40303,39,1}, /* core2 sp_EL0 bit31 */
			{40436,39,1}, /* core2 sp_EL0 bit32 */
			{40434,39,1}, /* core2 sp_EL0 bit33 */
			{40440,39,1}, /* core2 sp_EL0 bit34 */
			{40437,39,1}, /* core2 sp_EL0 bit35 */
			{40427,39,1}, /* core2 sp_EL0 bit36 */
			{40428,39,1}, /* core2 sp_EL0 bit37 */
			{40431,39,1}, /* core2 sp_EL0 bit38 */
			{40429,39,1}, /* core2 sp_EL0 bit39 */
			{40430,39,1}, /* core2 sp_EL0 bit40 */
			{40441,39,1}, /* core2 sp_EL0 bit41 */
			{40433,39,1}, /* core2 sp_EL0 bit42 */
			{40432,39,1}, /* core2 sp_EL0 bit43 */
			{40439,39,1}, /* core2 sp_EL0 bit44 */
			{40438,39,1}, /* core2 sp_EL0 bit45 */
			{40443,39,1}, /* core2 sp_EL0 bit46 */
			{40442,39,1}, /* core2 sp_EL0 bit47 */
			{40456,39,1}, /* core2 sp_EL0 bit48 */
			{34430,38,0}, /* core2 sp_EL0 bit49 */
			{34426,38,0}, /* core2 sp_EL0 bit50 */
			{34425,38,0}, /* core2 sp_EL0 bit51 */
			{34432,38,0}, /* core2 sp_EL0 bit52 */
			{34431,38,0}, /* core2 sp_EL0 bit53 */
			{34429,38,0}, /* core2 sp_EL0 bit54 */
			{40446,39,1}, /* core2 sp_EL0 bit55 */
			{36696,38,0}, /* core2 sp_EL0 bit56 */
			{36695,38,0}, /* core2 sp_EL0 bit57 */
			{36694,38,0}, /* core2 sp_EL0 bit58 */
			{36693,38,0}, /* core2 sp_EL0 bit59 */
			{40445,39,1}, /* core2 sp_EL0 bit60 */
			{40444,39,1}, /* core2 sp_EL0 bit61 */
			{34392,38,0}, /* core2 sp_EL0 bit62 */
			{34391,38,0}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40312,39,1}, /* core2 sp_EL1 bit0 */
			{40319,39,1}, /* core2 sp_EL1 bit1 */
			{40314,39,1}, /* core2 sp_EL1 bit2 */
			{40315,39,1}, /* core2 sp_EL1 bit3 */
			{34236,38,0}, /* core2 sp_EL1 bit4 */
			{34235,38,0}, /* core2 sp_EL1 bit5 */
			{34238,38,0}, /* core2 sp_EL1 bit6 */
			{34237,38,0}, /* core2 sp_EL1 bit7 */
			{40313,39,1}, /* core2 sp_EL1 bit8 */
			{40316,39,1}, /* core2 sp_EL1 bit9 */
			{40336,39,1}, /* core2 sp_EL1 bit10 */
			{40333,39,1}, /* core2 sp_EL1 bit11 */
			{40311,39,1}, /* core2 sp_EL1 bit12 */
			{40308,39,1}, /* core2 sp_EL1 bit13 */
			{40331,39,1}, /* core2 sp_EL1 bit14 */
			{40330,39,1}, /* core2 sp_EL1 bit15 */
			{34216,38,0}, /* core2 sp_EL1 bit16 */
			{34215,38,0}, /* core2 sp_EL1 bit17 */
			{40348,39,1}, /* core2 sp_EL1 bit18 */
			{40349,39,1}, /* core2 sp_EL1 bit19 */
			{40350,39,1}, /* core2 sp_EL1 bit20 */
			{40346,39,1}, /* core2 sp_EL1 bit21 */
			{40332,39,1}, /* core2 sp_EL1 bit22 */
			{40334,39,1}, /* core2 sp_EL1 bit23 */
			{40335,39,1}, /* core2 sp_EL1 bit24 */
			{40347,39,1}, /* core2 sp_EL1 bit25 */
			{40320,39,1}, /* core2 sp_EL1 bit26 */
			{40321,39,1}, /* core2 sp_EL1 bit27 */
			{40310,39,1}, /* core2 sp_EL1 bit28 */
			{40309,39,1}, /* core2 sp_EL1 bit29 */
			{40307,39,1}, /* core2 sp_EL1 bit30 */
			{40345,39,1}, /* core2 sp_EL1 bit31 */
			{40406,39,1}, /* core2 sp_EL1 bit32 */
			{40405,39,1}, /* core2 sp_EL1 bit33 */
			{40386,39,1}, /* core2 sp_EL1 bit34 */
			{40383,39,1}, /* core2 sp_EL1 bit35 */
			{40422,39,1}, /* core2 sp_EL1 bit36 */
			{40421,39,1}, /* core2 sp_EL1 bit37 */
			{40407,39,1}, /* core2 sp_EL1 bit38 */
			{40400,39,1}, /* core2 sp_EL1 bit39 */
			{40401,39,1}, /* core2 sp_EL1 bit40 */
			{40409,39,1}, /* core2 sp_EL1 bit41 */
			{40410,39,1}, /* core2 sp_EL1 bit42 */
			{40411,39,1}, /* core2 sp_EL1 bit43 */
			{40408,39,1}, /* core2 sp_EL1 bit44 */
			{40384,39,1}, /* core2 sp_EL1 bit45 */
			{40379,39,1}, /* core2 sp_EL1 bit46 */
			{40385,39,1}, /* core2 sp_EL1 bit47 */
			{40449,39,1}, /* core2 sp_EL1 bit48 */
			{39472,38,0}, /* core2 sp_EL1 bit49 */
			{39471,38,0}, /* core2 sp_EL1 bit50 */
			{39470,38,0}, /* core2 sp_EL1 bit51 */
			{39469,38,0}, /* core2 sp_EL1 bit52 */
			{39468,38,0}, /* core2 sp_EL1 bit53 */
			{39467,38,0}, /* core2 sp_EL1 bit54 */
			{39466,38,0}, /* core2 sp_EL1 bit55 */
			{39465,38,0}, /* core2 sp_EL1 bit56 */
			{40448,39,1}, /* core2 sp_EL1 bit57 */
			{34398,38,0}, /* core2 sp_EL1 bit58 */
			{34397,38,0}, /* core2 sp_EL1 bit59 */
			{34386,38,0}, /* core2 sp_EL1 bit60 */
			{34385,38,0}, /* core2 sp_EL1 bit61 */
			{34198,38,0}, /* core2 sp_EL1 bit62 */
			{34197,38,0}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40264,39,1}, /* core2 sp_EL2 bit0 */
			{40256,39,1}, /* core2 sp_EL2 bit1 */
			{40268,39,1}, /* core2 sp_EL2 bit2 */
			{40266,39,1}, /* core2 sp_EL2 bit3 */
			{40257,39,1}, /* core2 sp_EL2 bit4 */
			{40263,39,1}, /* core2 sp_EL2 bit5 */
			{40267,39,1}, /* core2 sp_EL2 bit6 */
			{40262,39,1}, /* core2 sp_EL2 bit7 */
			{40261,39,1}, /* core2 sp_EL2 bit8 */
			{40260,39,1}, /* core2 sp_EL2 bit9 */
			{40245,39,1}, /* core2 sp_EL2 bit10 */
			{40246,39,1}, /* core2 sp_EL2 bit11 */
			{40265,39,1}, /* core2 sp_EL2 bit12 */
			{40243,39,1}, /* core2 sp_EL2 bit13 */
			{40241,39,1}, /* core2 sp_EL2 bit14 */
			{40239,39,1}, /* core2 sp_EL2 bit15 */
			{40251,39,1}, /* core2 sp_EL2 bit16 */
			{40259,39,1}, /* core2 sp_EL2 bit17 */
			{40250,39,1}, /* core2 sp_EL2 bit18 */
			{40247,39,1}, /* core2 sp_EL2 bit19 */
			{40248,39,1}, /* core2 sp_EL2 bit20 */
			{40249,39,1}, /* core2 sp_EL2 bit21 */
			{40255,39,1}, /* core2 sp_EL2 bit22 */
			{40258,39,1}, /* core2 sp_EL2 bit23 */
			{40254,39,1}, /* core2 sp_EL2 bit24 */
			{40253,39,1}, /* core2 sp_EL2 bit25 */
			{40238,39,1}, /* core2 sp_EL2 bit26 */
			{40237,39,1}, /* core2 sp_EL2 bit27 */
			{40242,39,1}, /* core2 sp_EL2 bit28 */
			{40240,39,1}, /* core2 sp_EL2 bit29 */
			{40244,39,1}, /* core2 sp_EL2 bit30 */
			{40252,39,1}, /* core2 sp_EL2 bit31 */
			{40402,39,1}, /* core2 sp_EL2 bit32 */
			{40412,39,1}, /* core2 sp_EL2 bit33 */
			{40387,39,1}, /* core2 sp_EL2 bit34 */
			{40388,39,1}, /* core2 sp_EL2 bit35 */
			{40419,39,1}, /* core2 sp_EL2 bit36 */
			{40414,39,1}, /* core2 sp_EL2 bit37 */
			{40413,39,1}, /* core2 sp_EL2 bit38 */
			{40417,39,1}, /* core2 sp_EL2 bit39 */
			{40416,39,1}, /* core2 sp_EL2 bit40 */
			{40418,39,1}, /* core2 sp_EL2 bit41 */
			{40415,39,1}, /* core2 sp_EL2 bit42 */
			{40420,39,1}, /* core2 sp_EL2 bit43 */
			{40404,39,1}, /* core2 sp_EL2 bit44 */
			{40403,39,1}, /* core2 sp_EL2 bit45 */
			{40378,39,1}, /* core2 sp_EL2 bit46 */
			{40389,39,1}, /* core2 sp_EL2 bit47 */
			{40447,39,1}, /* core2 sp_EL2 bit48 */
			{40460,39,1}, /* core2 sp_EL2 bit49 */
			{34422,38,0}, /* core2 sp_EL2 bit50 */
			{34421,38,0}, /* core2 sp_EL2 bit51 */
			{34420,38,0}, /* core2 sp_EL2 bit52 */
			{34419,38,0}, /* core2 sp_EL2 bit53 */
			{34416,38,0}, /* core2 sp_EL2 bit54 */
			{34415,38,0}, /* core2 sp_EL2 bit55 */
			{34400,38,0}, /* core2 sp_EL2 bit56 */
			{34399,38,0}, /* core2 sp_EL2 bit57 */
			{34396,38,0}, /* core2 sp_EL2 bit58 */
			{34395,38,0}, /* core2 sp_EL2 bit59 */
			{36728,38,0}, /* core2 sp_EL2 bit60 */
			{36727,38,0}, /* core2 sp_EL2 bit61 */
			{36726,38,0}, /* core2 sp_EL2 bit62 */
			{36725,38,0}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40272,39,1}, /* core2 sp_EL3 bit0 */
			{40289,39,1}, /* core2 sp_EL3 bit1 */
			{40277,39,1}, /* core2 sp_EL3 bit2 */
			{40279,39,1}, /* core2 sp_EL3 bit3 */
			{40281,39,1}, /* core2 sp_EL3 bit4 */
			{40280,39,1}, /* core2 sp_EL3 bit5 */
			{34280,38,0}, /* core2 sp_EL3 bit6 */
			{34279,38,0}, /* core2 sp_EL3 bit7 */
			{40278,39,1}, /* core2 sp_EL3 bit8 */
			{40276,39,1}, /* core2 sp_EL3 bit9 */
			{40290,39,1}, /* core2 sp_EL3 bit10 */
			{40292,39,1}, /* core2 sp_EL3 bit11 */
			{34282,38,0}, /* core2 sp_EL3 bit12 */
			{34281,38,0}, /* core2 sp_EL3 bit13 */
			{40288,39,1}, /* core2 sp_EL3 bit14 */
			{40287,39,1}, /* core2 sp_EL3 bit15 */
			{40300,39,1}, /* core2 sp_EL3 bit16 */
			{40301,39,1}, /* core2 sp_EL3 bit17 */
			{40291,39,1}, /* core2 sp_EL3 bit18 */
			{40299,39,1}, /* core2 sp_EL3 bit19 */
			{40297,39,1}, /* core2 sp_EL3 bit20 */
			{40298,39,1}, /* core2 sp_EL3 bit21 */
			{40271,39,1}, /* core2 sp_EL3 bit22 */
			{40294,39,1}, /* core2 sp_EL3 bit23 */
			{40295,39,1}, /* core2 sp_EL3 bit24 */
			{40296,39,1}, /* core2 sp_EL3 bit25 */
			{40275,39,1}, /* core2 sp_EL3 bit26 */
			{40274,39,1}, /* core2 sp_EL3 bit27 */
			{40273,39,1}, /* core2 sp_EL3 bit28 */
			{40270,39,1}, /* core2 sp_EL3 bit29 */
			{40269,39,1}, /* core2 sp_EL3 bit30 */
			{40293,39,1}, /* core2 sp_EL3 bit31 */
			{40393,39,1}, /* core2 sp_EL3 bit32 */
			{40392,39,1}, /* core2 sp_EL3 bit33 */
			{40391,39,1}, /* core2 sp_EL3 bit34 */
			{40396,39,1}, /* core2 sp_EL3 bit35 */
			{40425,39,1}, /* core2 sp_EL3 bit36 */
			{40423,39,1}, /* core2 sp_EL3 bit37 */
			{40395,39,1}, /* core2 sp_EL3 bit38 */
			{40426,39,1}, /* core2 sp_EL3 bit39 */
			{40397,39,1}, /* core2 sp_EL3 bit40 */
			{40399,39,1}, /* core2 sp_EL3 bit41 */
			{40424,39,1}, /* core2 sp_EL3 bit42 */
			{40398,39,1}, /* core2 sp_EL3 bit43 */
			{40394,39,1}, /* core2 sp_EL3 bit44 */
			{40435,39,1}, /* core2 sp_EL3 bit45 */
			{40377,39,1}, /* core2 sp_EL3 bit46 */
			{40390,39,1}, /* core2 sp_EL3 bit47 */
			{40458,39,1}, /* core2 sp_EL3 bit48 */
			{40457,39,1}, /* core2 sp_EL3 bit49 */
			{34418,38,0}, /* core2 sp_EL3 bit50 */
			{34417,38,0}, /* core2 sp_EL3 bit51 */
			{36776,38,0}, /* core2 sp_EL3 bit52 */
			{36775,38,0}, /* core2 sp_EL3 bit53 */
			{36774,38,0}, /* core2 sp_EL3 bit54 */
			{36773,38,0}, /* core2 sp_EL3 bit55 */
			{36692,38,0}, /* core2 sp_EL3 bit56 */
			{36691,38,0}, /* core2 sp_EL3 bit57 */
			{36690,38,0}, /* core2 sp_EL3 bit58 */
			{36689,38,0}, /* core2 sp_EL3 bit59 */
			{40375,39,1}, /* core2 sp_EL3 bit60 */
			{40374,39,1}, /* core2 sp_EL3 bit61 */
			{34388,38,0}, /* core2 sp_EL3 bit62 */
			{34387,38,0}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{39606,38,0}, /* core2 elr_EL1 bit0 */
			{39605,38,0}, /* core2 elr_EL1 bit1 */
			{39604,38,0}, /* core2 elr_EL1 bit2 */
			{39603,38,0}, /* core2 elr_EL1 bit3 */
			{39602,38,0}, /* core2 elr_EL1 bit4 */
			{39601,38,0}, /* core2 elr_EL1 bit5 */
			{39600,38,0}, /* core2 elr_EL1 bit6 */
			{39599,38,0}, /* core2 elr_EL1 bit7 */
			{34224,38,0}, /* core2 elr_EL1 bit8 */
			{34223,38,0}, /* core2 elr_EL1 bit9 */
			{34218,38,0}, /* core2 elr_EL1 bit10 */
			{34217,38,0}, /* core2 elr_EL1 bit11 */
			{34222,38,0}, /* core2 elr_EL1 bit12 */
			{34221,38,0}, /* core2 elr_EL1 bit13 */
			{34220,38,0}, /* core2 elr_EL1 bit14 */
			{34219,38,0}, /* core2 elr_EL1 bit15 */
			{39654,38,0}, /* core2 elr_EL1 bit16 */
			{39653,38,0}, /* core2 elr_EL1 bit17 */
			{39652,38,0}, /* core2 elr_EL1 bit18 */
			{39651,38,0}, /* core2 elr_EL1 bit19 */
			{39650,38,0}, /* core2 elr_EL1 bit20 */
			{39649,38,0}, /* core2 elr_EL1 bit21 */
			{39648,38,0}, /* core2 elr_EL1 bit22 */
			{39647,38,0}, /* core2 elr_EL1 bit23 */
			{39638,38,0}, /* core2 elr_EL1 bit24 */
			{39637,38,0}, /* core2 elr_EL1 bit25 */
			{39636,38,0}, /* core2 elr_EL1 bit26 */
			{39635,38,0}, /* core2 elr_EL1 bit27 */
			{39634,38,0}, /* core2 elr_EL1 bit28 */
			{39633,38,0}, /* core2 elr_EL1 bit29 */
			{39632,38,0}, /* core2 elr_EL1 bit30 */
			{39631,38,0}, /* core2 elr_EL1 bit31 */
			{36720,38,0}, /* core2 elr_EL1 bit32 */
			{36724,38,0}, /* core2 elr_EL1 bit33 */
			{36723,38,0}, /* core2 elr_EL1 bit34 */
			{36719,38,0}, /* core2 elr_EL1 bit35 */
			{36722,38,0}, /* core2 elr_EL1 bit36 */
			{36721,38,0}, /* core2 elr_EL1 bit37 */
			{36716,38,0}, /* core2 elr_EL1 bit38 */
			{36718,38,0}, /* core2 elr_EL1 bit39 */
			{36715,38,0}, /* core2 elr_EL1 bit40 */
			{36714,38,0}, /* core2 elr_EL1 bit41 */
			{39440,38,0}, /* core2 elr_EL1 bit42 */
			{39439,38,0}, /* core2 elr_EL1 bit43 */
			{39438,38,0}, /* core2 elr_EL1 bit44 */
			{36717,38,0}, /* core2 elr_EL1 bit45 */
			{39437,38,0}, /* core2 elr_EL1 bit46 */
			{39436,38,0}, /* core2 elr_EL1 bit47 */
			{36796,38,0}, /* core2 elr_EL1 bit48 */
			{39435,38,0}, /* core2 elr_EL1 bit49 */
			{36795,38,0}, /* core2 elr_EL1 bit50 */
			{36794,38,0}, /* core2 elr_EL1 bit51 */
			{36793,38,0}, /* core2 elr_EL1 bit52 */
			{36792,38,0}, /* core2 elr_EL1 bit53 */
			{39434,38,0}, /* core2 elr_EL1 bit54 */
			{39433,38,0}, /* core2 elr_EL1 bit55 */
			{36791,38,0}, /* core2 elr_EL1 bit56 */
			{36790,38,0}, /* core2 elr_EL1 bit57 */
			{36789,38,0}, /* core2 elr_EL1 bit58 */
			{34394,38,0}, /* core2 elr_EL1 bit59 */
			{36713,38,0}, /* core2 elr_EL1 bit60 */
			{34393,38,0}, /* core2 elr_EL1 bit61 */
			{34390,38,0}, /* core2 elr_EL1 bit62 */
			{34389,38,0}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{39614,38,0}, /* core2 elr_EL2 bit0 */
			{39613,38,0}, /* core2 elr_EL2 bit1 */
			{39612,38,0}, /* core2 elr_EL2 bit2 */
			{39611,38,0}, /* core2 elr_EL2 bit3 */
			{39610,38,0}, /* core2 elr_EL2 bit4 */
			{39609,38,0}, /* core2 elr_EL2 bit5 */
			{39608,38,0}, /* core2 elr_EL2 bit6 */
			{39607,38,0}, /* core2 elr_EL2 bit7 */
			{39622,38,0}, /* core2 elr_EL2 bit8 */
			{39621,38,0}, /* core2 elr_EL2 bit9 */
			{39620,38,0}, /* core2 elr_EL2 bit10 */
			{39619,38,0}, /* core2 elr_EL2 bit11 */
			{39618,38,0}, /* core2 elr_EL2 bit12 */
			{39617,38,0}, /* core2 elr_EL2 bit13 */
			{39616,38,0}, /* core2 elr_EL2 bit14 */
			{39615,38,0}, /* core2 elr_EL2 bit15 */
			{39646,38,0}, /* core2 elr_EL2 bit16 */
			{39645,38,0}, /* core2 elr_EL2 bit17 */
			{39644,38,0}, /* core2 elr_EL2 bit18 */
			{39643,38,0}, /* core2 elr_EL2 bit19 */
			{39642,38,0}, /* core2 elr_EL2 bit20 */
			{39641,38,0}, /* core2 elr_EL2 bit21 */
			{39640,38,0}, /* core2 elr_EL2 bit22 */
			{39639,38,0}, /* core2 elr_EL2 bit23 */
			{39630,38,0}, /* core2 elr_EL2 bit24 */
			{39629,38,0}, /* core2 elr_EL2 bit25 */
			{39628,38,0}, /* core2 elr_EL2 bit26 */
			{39627,38,0}, /* core2 elr_EL2 bit27 */
			{39626,38,0}, /* core2 elr_EL2 bit28 */
			{39625,38,0}, /* core2 elr_EL2 bit29 */
			{39624,38,0}, /* core2 elr_EL2 bit30 */
			{39623,38,0}, /* core2 elr_EL2 bit31 */
			{39432,38,0}, /* core2 elr_EL2 bit32 */
			{36712,38,0}, /* core2 elr_EL2 bit33 */
			{36711,38,0}, /* core2 elr_EL2 bit34 */
			{39431,38,0}, /* core2 elr_EL2 bit35 */
			{39430,38,0}, /* core2 elr_EL2 bit36 */
			{39429,38,0}, /* core2 elr_EL2 bit37 */
			{36710,38,0}, /* core2 elr_EL2 bit38 */
			{39428,38,0}, /* core2 elr_EL2 bit39 */
			{36709,38,0}, /* core2 elr_EL2 bit40 */
			{36708,38,0}, /* core2 elr_EL2 bit41 */
			{39427,38,0}, /* core2 elr_EL2 bit42 */
			{36707,38,0}, /* core2 elr_EL2 bit43 */
			{36706,38,0}, /* core2 elr_EL2 bit44 */
			{39426,38,0}, /* core2 elr_EL2 bit45 */
			{39425,38,0}, /* core2 elr_EL2 bit46 */
			{36705,38,0}, /* core2 elr_EL2 bit47 */
			{36788,38,0}, /* core2 elr_EL2 bit48 */
			{36787,38,0}, /* core2 elr_EL2 bit49 */
			{36786,38,0}, /* core2 elr_EL2 bit50 */
			{36785,38,0}, /* core2 elr_EL2 bit51 */
			{36784,38,0}, /* core2 elr_EL2 bit52 */
			{36783,38,0}, /* core2 elr_EL2 bit53 */
			{36782,38,0}, /* core2 elr_EL2 bit54 */
			{36781,38,0}, /* core2 elr_EL2 bit55 */
			{36780,38,0}, /* core2 elr_EL2 bit56 */
			{36779,38,0}, /* core2 elr_EL2 bit57 */
			{36778,38,0}, /* core2 elr_EL2 bit58 */
			{36777,38,0}, /* core2 elr_EL2 bit59 */
			{36704,38,0}, /* core2 elr_EL2 bit60 */
			{36703,38,0}, /* core2 elr_EL2 bit61 */
			{36702,38,0}, /* core2 elr_EL2 bit62 */
			{36701,38,0}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{34228,38,0}, /* core2 elr_EL3 bit0 */
			{34227,38,0}, /* core2 elr_EL3 bit1 */
			{40317,39,1}, /* core2 elr_EL3 bit2 */
			{40318,39,1}, /* core2 elr_EL3 bit3 */
			{36912,38,0}, /* core2 elr_EL3 bit4 */
			{36911,38,0}, /* core2 elr_EL3 bit5 */
			{36910,38,0}, /* core2 elr_EL3 bit6 */
			{36909,38,0}, /* core2 elr_EL3 bit7 */
			{34232,38,0}, /* core2 elr_EL3 bit8 */
			{34231,38,0}, /* core2 elr_EL3 bit9 */
			{40339,39,1}, /* core2 elr_EL3 bit10 */
			{40351,39,1}, /* core2 elr_EL3 bit11 */
			{34230,38,0}, /* core2 elr_EL3 bit12 */
			{34229,38,0}, /* core2 elr_EL3 bit13 */
			{40326,39,1}, /* core2 elr_EL3 bit14 */
			{40328,39,1}, /* core2 elr_EL3 bit15 */
			{40352,39,1}, /* core2 elr_EL3 bit16 */
			{40353,39,1}, /* core2 elr_EL3 bit17 */
			{40354,39,1}, /* core2 elr_EL3 bit18 */
			{40344,39,1}, /* core2 elr_EL3 bit19 */
			{40342,39,1}, /* core2 elr_EL3 bit20 */
			{40341,39,1}, /* core2 elr_EL3 bit21 */
			{40327,39,1}, /* core2 elr_EL3 bit22 */
			{40338,39,1}, /* core2 elr_EL3 bit23 */
			{40340,39,1}, /* core2 elr_EL3 bit24 */
			{40343,39,1}, /* core2 elr_EL3 bit25 */
			{40323,39,1}, /* core2 elr_EL3 bit26 */
			{40322,39,1}, /* core2 elr_EL3 bit27 */
			{40324,39,1}, /* core2 elr_EL3 bit28 */
			{40325,39,1}, /* core2 elr_EL3 bit29 */
			{40329,39,1}, /* core2 elr_EL3 bit30 */
			{40337,39,1}, /* core2 elr_EL3 bit31 */
			{34382,38,0}, /* core2 elr_EL3 bit32 */
			{34381,38,0}, /* core2 elr_EL3 bit33 */
			{40368,39,1}, /* core2 elr_EL3 bit34 */
			{40364,39,1}, /* core2 elr_EL3 bit35 */
			{40380,39,1}, /* core2 elr_EL3 bit36 */
			{40372,39,1}, /* core2 elr_EL3 bit37 */
			{40365,39,1}, /* core2 elr_EL3 bit38 */
			{40376,39,1}, /* core2 elr_EL3 bit39 */
			{40369,39,1}, /* core2 elr_EL3 bit40 */
			{40367,39,1}, /* core2 elr_EL3 bit41 */
			{40373,39,1}, /* core2 elr_EL3 bit42 */
			{40371,39,1}, /* core2 elr_EL3 bit43 */
			{40381,39,1}, /* core2 elr_EL3 bit44 */
			{40366,39,1}, /* core2 elr_EL3 bit45 */
			{40370,39,1}, /* core2 elr_EL3 bit46 */
			{40382,39,1}, /* core2 elr_EL3 bit47 */
			{34402,38,0}, /* core2 elr_EL3 bit48 */
			{34401,38,0}, /* core2 elr_EL3 bit49 */
			{36772,38,0}, /* core2 elr_EL3 bit50 */
			{36771,38,0}, /* core2 elr_EL3 bit51 */
			{34414,38,0}, /* core2 elr_EL3 bit52 */
			{36770,38,0}, /* core2 elr_EL3 bit53 */
			{34413,38,0}, /* core2 elr_EL3 bit54 */
			{36769,38,0}, /* core2 elr_EL3 bit55 */
			{36688,38,0}, /* core2 elr_EL3 bit56 */
			{36687,38,0}, /* core2 elr_EL3 bit57 */
			{36686,38,0}, /* core2 elr_EL3 bit58 */
			{36685,38,0}, /* core2 elr_EL3 bit59 */
			{34384,38,0}, /* core2 elr_EL3 bit60 */
			{34383,38,0}, /* core2 elr_EL3 bit61 */
			{34196,38,0}, /* core2 elr_EL3 bit62 */
			{34195,38,0}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{35631,38,0}, /* core2 raw_pc bit0 */
			{35630,38,0}, /* core2 raw_pc bit1 */
			{38290,38,0}, /* core2 raw_pc bit2 */
			{38289,38,0}, /* core2 raw_pc bit3 */
			{38288,38,0}, /* core2 raw_pc bit4 */
			{38287,38,0}, /* core2 raw_pc bit5 */
			{32560,38,1}, /* core2 raw_pc bit6 */
			{38278,38,0}, /* core2 raw_pc bit7 */
			{38277,38,0}, /* core2 raw_pc bit8 */
			{38276,38,0}, /* core2 raw_pc bit9 */
			{38275,38,0}, /* core2 raw_pc bit10 */
			{35637,38,0}, /* core2 raw_pc bit11 */
			{35636,38,0}, /* core2 raw_pc bit12 */
			{35635,38,0}, /* core2 raw_pc bit13 */
			{35634,38,0}, /* core2 raw_pc bit14 */
			{38282,38,0}, /* core2 raw_pc bit15 */
			{38281,38,0}, /* core2 raw_pc bit16 */
			{38280,38,0}, /* core2 raw_pc bit17 */
			{38279,38,0}, /* core2 raw_pc bit18 */
			{35641,38,0}, /* core2 raw_pc bit19 */
			{35640,38,0}, /* core2 raw_pc bit20 */
			{32562,38,1}, /* core2 raw_pc bit21 */
			{32561,38,1}, /* core2 raw_pc bit22 */
			{38286,38,0}, /* core2 raw_pc bit23 */
			{38285,38,0}, /* core2 raw_pc bit24 */
			{38284,38,0}, /* core2 raw_pc bit25 */
			{38283,38,0}, /* core2 raw_pc bit26 */
			{35633,38,0}, /* core2 raw_pc bit27 */
			{35632,38,0}, /* core2 raw_pc bit28 */
			{35639,38,0}, /* core2 raw_pc bit29 */
			{35638,38,0}, /* core2 raw_pc bit30 */
			{38274,38,0}, /* core2 raw_pc bit31 */
			{38273,38,0}, /* core2 raw_pc bit32 */
			{38272,38,0}, /* core2 raw_pc bit33 */
			{38271,38,0}, /* core2 raw_pc bit34 */
			{40754,38,0}, /* core2 raw_pc bit35 */
			{40753,38,0}, /* core2 raw_pc bit36 */
			{40752,38,0}, /* core2 raw_pc bit37 */
			{40751,38,0}, /* core2 raw_pc bit38 */
			{35645,38,0}, /* core2 raw_pc bit39 */
			{35644,38,0}, /* core2 raw_pc bit40 */
			{40750,38,0}, /* core2 raw_pc bit41 */
			{40749,38,0}, /* core2 raw_pc bit42 */
			{35647,38,0}, /* core2 raw_pc bit43 */
			{35646,38,0}, /* core2 raw_pc bit44 */
			{40748,38,0}, /* core2 raw_pc bit45 */
			{40747,38,0}, /* core2 raw_pc bit46 */
			{32577,38,1}, /* core2 raw_pc bit47 */
			{32578,38,1}, /* core2 raw_pc bit48 */
			{32579,38,1}, /* core2 raw_pc bit49 */
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
			{32555,38,1}, /* core2 pc_iss bit0 */
			{32637,38,1}, /* core2 pc_iss bit1 */
			{32634,38,1}, /* core2 pc_iss bit2 */
			{32633,38,1}, /* core2 pc_iss bit3 */
			{32635,38,1}, /* core2 pc_iss bit4 */
			{32554,38,1}, /* core2 pc_iss bit5 */
			{32556,38,1}, /* core2 pc_iss bit6 */
			{32636,38,1}, /* core2 pc_iss bit7 */
			{32610,38,1}, /* core2 pc_iss bit8 */
			{32603,38,1}, /* core2 pc_iss bit9 */
			{32632,38,1}, /* core2 pc_iss bit10 */
			{32631,38,1}, /* core2 pc_iss bit11 */
			{32629,38,1}, /* core2 pc_iss bit12 */
			{32630,38,1}, /* core2 pc_iss bit13 */
			{32628,38,1}, /* core2 pc_iss bit14 */
			{32614,38,1}, /* core2 pc_iss bit15 */
			{32615,38,1}, /* core2 pc_iss bit16 */
			{32627,38,1}, /* core2 pc_iss bit17 */
			{32624,38,1}, /* core2 pc_iss bit18 */
			{32617,38,1}, /* core2 pc_iss bit19 */
			{32625,38,1}, /* core2 pc_iss bit20 */
			{32626,38,1}, /* core2 pc_iss bit21 */
			{32611,38,1}, /* core2 pc_iss bit22 */
			{32618,38,1}, /* core2 pc_iss bit23 */
			{32622,38,1}, /* core2 pc_iss bit24 */
			{32621,38,1}, /* core2 pc_iss bit25 */
			{32619,38,1}, /* core2 pc_iss bit26 */
			{32612,38,1}, /* core2 pc_iss bit27 */
			{32613,38,1}, /* core2 pc_iss bit28 */
			{32620,38,1}, /* core2 pc_iss bit29 */
			{32616,38,1}, /* core2 pc_iss bit30 */
			{32623,38,1}, /* core2 pc_iss bit31 */
			{32573,38,1}, /* core2 pc_iss bit32 */
			{32574,38,1}, /* core2 pc_iss bit33 */
			{32563,38,1}, /* core2 pc_iss bit34 */
			{32564,38,1}, /* core2 pc_iss bit35 */
			{32570,38,1}, /* core2 pc_iss bit36 */
			{32566,38,1}, /* core2 pc_iss bit37 */
			{32571,38,1}, /* core2 pc_iss bit38 */
			{32565,38,1}, /* core2 pc_iss bit39 */
			{32572,38,1}, /* core2 pc_iss bit40 */
			{32568,38,1}, /* core2 pc_iss bit41 */
			{32567,38,1}, /* core2 pc_iss bit42 */
			{32569,38,1}, /* core2 pc_iss bit43 */
			{35685,38,0}, /* core2 pc_iss bit44 */
			{35684,38,0}, /* core2 pc_iss bit45 */
			{35683,38,0}, /* core2 pc_iss bit46 */
			{35682,38,0}, /* core2 pc_iss bit47 */
			{38270,38,0}, /* core2 pc_iss bit48 */
			{38269,38,0}, /* core2 pc_iss bit49 */
			{38268,38,0}, /* core2 pc_iss bit50 */
			{38267,38,0}, /* core2 pc_iss bit51 */
			{38266,38,0}, /* core2 pc_iss bit52 */
			{38265,38,0}, /* core2 pc_iss bit53 */
			{38264,38,0}, /* core2 pc_iss bit54 */
			{38263,38,0}, /* core2 pc_iss bit55 */
			{40956,38,0}, /* core2 pc_iss bit56 */
			{40955,38,0}, /* core2 pc_iss bit57 */
			{40954,38,0}, /* core2 pc_iss bit58 */
			{40953,38,0}, /* core2 pc_iss bit59 */
			{40952,38,0}, /* core2 pc_iss bit60 */
			{40951,38,0}, /* core2 pc_iss bit61 */
			{40950,38,0}, /* core2 pc_iss bit62 */
			{40949,38,0}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{32557,38,1}, /* core2 full_pc_wr bit0 */
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
			{41124,38,0}, /* core2 full_pc_ex1 bit0 */
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
			{41116,38,0}, /* core2 full_pc_ex2 bit0 */
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
			{25953,39,1}, /* core2 return_Stack_pointer bit0 */
			{28673,39,1}, /* core2 return_Stack_pointer bit1 */
			{28674,39,1}, /* core2 return_Stack_pointer bit2 */
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
			{32644,39,1}, /* core2 return_Stack0 bit0 */
			{32643,39,1}, /* core2 return_Stack0 bit1 */
			{32672,39,1}, /* core2 return_Stack0 bit2 */
			{32671,39,1}, /* core2 return_Stack0 bit3 */
			{32670,39,1}, /* core2 return_Stack0 bit4 */
			{32669,39,1}, /* core2 return_Stack0 bit5 */
			{28860,39,1}, /* core2 return_Stack0 bit6 */
			{28859,39,1}, /* core2 return_Stack0 bit7 */
			{28858,39,1}, /* core2 return_Stack0 bit8 */
			{28857,39,1}, /* core2 return_Stack0 bit9 */
			{37875,39,1}, /* core2 return_Stack0 bit10 */
			{37874,39,1}, /* core2 return_Stack0 bit11 */
			{37873,39,1}, /* core2 return_Stack0 bit12 */
			{37872,39,1}, /* core2 return_Stack0 bit13 */
			{37871,39,1}, /* core2 return_Stack0 bit14 */
			{37870,39,1}, /* core2 return_Stack0 bit15 */
			{37869,39,1}, /* core2 return_Stack0 bit16 */
			{32642,39,1}, /* core2 return_Stack0 bit17 */
			{37868,39,1}, /* core2 return_Stack0 bit18 */
			{32648,39,1}, /* core2 return_Stack0 bit19 */
			{32647,39,1}, /* core2 return_Stack0 bit20 */
			{32646,39,1}, /* core2 return_Stack0 bit21 */
			{32645,39,1}, /* core2 return_Stack0 bit22 */
			{32641,39,1}, /* core2 return_Stack0 bit23 */
			{26154,39,1}, /* core2 return_Stack0 bit24 */
			{26153,39,1}, /* core2 return_Stack0 bit25 */
			{28780,39,1}, /* core2 return_Stack0 bit26 */
			{28779,39,1}, /* core2 return_Stack0 bit27 */
			{32656,39,1}, /* core2 return_Stack0 bit28 */
			{32655,39,1}, /* core2 return_Stack0 bit29 */
			{32654,39,1}, /* core2 return_Stack0 bit30 */
			{26152,39,1}, /* core2 return_Stack0 bit31 */
			{32653,39,1}, /* core2 return_Stack0 bit32 */
			{28770,39,1}, /* core2 return_Stack0 bit33 */
			{28769,39,1}, /* core2 return_Stack0 bit34 */
			{25973,39,1}, /* core2 return_Stack0 bit35 */
			{28772,39,1}, /* core2 return_Stack0 bit36 */
			{28771,39,1}, /* core2 return_Stack0 bit37 */
			{32832,39,1}, /* core2 return_Stack0 bit38 */
			{32831,39,1}, /* core2 return_Stack0 bit39 */
			{32830,39,1}, /* core2 return_Stack0 bit40 */
			{32829,39,1}, /* core2 return_Stack0 bit41 */
			{25972,39,1}, /* core2 return_Stack0 bit42 */
			{28774,39,1}, /* core2 return_Stack0 bit43 */
			{28773,39,1}, /* core2 return_Stack0 bit44 */
			{28776,39,1}, /* core2 return_Stack0 bit45 */
			{28775,39,1}, /* core2 return_Stack0 bit46 */
			{28778,39,1}, /* core2 return_Stack0 bit47 */
			{28777,39,1}, /* core2 return_Stack0 bit48 */
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
			{28812,39,1}, /* core2 return_Stack1 bit0 */
			{28811,39,1}, /* core2 return_Stack1 bit1 */
			{32716,39,1}, /* core2 return_Stack1 bit2 */
			{32715,39,1}, /* core2 return_Stack1 bit3 */
			{32720,39,1}, /* core2 return_Stack1 bit4 */
			{32719,39,1}, /* core2 return_Stack1 bit5 */
			{32718,39,1}, /* core2 return_Stack1 bit6 */
			{32717,39,1}, /* core2 return_Stack1 bit7 */
			{28818,39,1}, /* core2 return_Stack1 bit8 */
			{28817,39,1}, /* core2 return_Stack1 bit9 */
			{32714,39,1}, /* core2 return_Stack1 bit10 */
			{32713,39,1}, /* core2 return_Stack1 bit11 */
			{32724,39,1}, /* core2 return_Stack1 bit12 */
			{32723,39,1}, /* core2 return_Stack1 bit13 */
			{32722,39,1}, /* core2 return_Stack1 bit14 */
			{32721,39,1}, /* core2 return_Stack1 bit15 */
			{28820,39,1}, /* core2 return_Stack1 bit16 */
			{28819,39,1}, /* core2 return_Stack1 bit17 */
			{28816,39,1}, /* core2 return_Stack1 bit18 */
			{28815,39,1}, /* core2 return_Stack1 bit19 */
			{28814,39,1}, /* core2 return_Stack1 bit20 */
			{28813,39,1}, /* core2 return_Stack1 bit21 */
			{26163,39,1}, /* core2 return_Stack1 bit22 */
			{26165,39,1}, /* core2 return_Stack1 bit23 */
			{26164,39,1}, /* core2 return_Stack1 bit24 */
			{32736,39,1}, /* core2 return_Stack1 bit25 */
			{32735,39,1}, /* core2 return_Stack1 bit26 */
			{32734,39,1}, /* core2 return_Stack1 bit27 */
			{32733,39,1}, /* core2 return_Stack1 bit28 */
			{28810,39,1}, /* core2 return_Stack1 bit29 */
			{28809,39,1}, /* core2 return_Stack1 bit30 */
			{26166,39,1}, /* core2 return_Stack1 bit31 */
			{28808,39,1}, /* core2 return_Stack1 bit32 */
			{28806,39,1}, /* core2 return_Stack1 bit33 */
			{28805,39,1}, /* core2 return_Stack1 bit34 */
			{28807,39,1}, /* core2 return_Stack1 bit35 */
			{26167,39,1}, /* core2 return_Stack1 bit36 */
			{32784,39,1}, /* core2 return_Stack1 bit37 */
			{32783,39,1}, /* core2 return_Stack1 bit38 */
			{32782,39,1}, /* core2 return_Stack1 bit39 */
			{32781,39,1}, /* core2 return_Stack1 bit40 */
			{32788,39,1}, /* core2 return_Stack1 bit41 */
			{32787,39,1}, /* core2 return_Stack1 bit42 */
			{32786,39,1}, /* core2 return_Stack1 bit43 */
			{32785,39,1}, /* core2 return_Stack1 bit44 */
			{32792,39,1}, /* core2 return_Stack1 bit45 */
			{32791,39,1}, /* core2 return_Stack1 bit46 */
			{32790,39,1}, /* core2 return_Stack1 bit47 */
			{32789,39,1}, /* core2 return_Stack1 bit48 */
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
			{28856,39,1}, /* core2 return_Stack2 bit0 */
			{28855,39,1}, /* core2 return_Stack2 bit1 */
			{28854,39,1}, /* core2 return_Stack2 bit2 */
			{28853,39,1}, /* core2 return_Stack2 bit3 */
			{32676,39,1}, /* core2 return_Stack2 bit4 */
			{32675,39,1}, /* core2 return_Stack2 bit5 */
			{32674,39,1}, /* core2 return_Stack2 bit6 */
			{32673,39,1}, /* core2 return_Stack2 bit7 */
			{32680,39,1}, /* core2 return_Stack2 bit8 */
			{32679,39,1}, /* core2 return_Stack2 bit9 */
			{32678,39,1}, /* core2 return_Stack2 bit10 */
			{32677,39,1}, /* core2 return_Stack2 bit11 */
			{28846,39,1}, /* core2 return_Stack2 bit12 */
			{28845,39,1}, /* core2 return_Stack2 bit13 */
			{28848,39,1}, /* core2 return_Stack2 bit14 */
			{28847,39,1}, /* core2 return_Stack2 bit15 */
			{28852,39,1}, /* core2 return_Stack2 bit16 */
			{28851,39,1}, /* core2 return_Stack2 bit17 */
			{28844,39,1}, /* core2 return_Stack2 bit18 */
			{28843,39,1}, /* core2 return_Stack2 bit19 */
			{28850,39,1}, /* core2 return_Stack2 bit20 */
			{28849,39,1}, /* core2 return_Stack2 bit21 */
			{26155,39,1}, /* core2 return_Stack2 bit22 */
			{26156,39,1}, /* core2 return_Stack2 bit23 */
			{26157,39,1}, /* core2 return_Stack2 bit24 */
			{32652,39,1}, /* core2 return_Stack2 bit25 */
			{32651,39,1}, /* core2 return_Stack2 bit26 */
			{32650,39,1}, /* core2 return_Stack2 bit27 */
			{32649,39,1}, /* core2 return_Stack2 bit28 */
			{32756,39,1}, /* core2 return_Stack2 bit29 */
			{32755,39,1}, /* core2 return_Stack2 bit30 */
			{32754,39,1}, /* core2 return_Stack2 bit31 */
			{32753,39,1}, /* core2 return_Stack2 bit32 */
			{32824,39,1}, /* core2 return_Stack2 bit33 */
			{32823,39,1}, /* core2 return_Stack2 bit34 */
			{32822,39,1}, /* core2 return_Stack2 bit35 */
			{32821,39,1}, /* core2 return_Stack2 bit36 */
			{32820,39,1}, /* core2 return_Stack2 bit37 */
			{32819,39,1}, /* core2 return_Stack2 bit38 */
			{32818,39,1}, /* core2 return_Stack2 bit39 */
			{32817,39,1}, /* core2 return_Stack2 bit40 */
			{32828,39,1}, /* core2 return_Stack2 bit41 */
			{32827,39,1}, /* core2 return_Stack2 bit42 */
			{32826,39,1}, /* core2 return_Stack2 bit43 */
			{32825,39,1}, /* core2 return_Stack2 bit44 */
			{32760,39,1}, /* core2 return_Stack2 bit45 */
			{32759,39,1}, /* core2 return_Stack2 bit46 */
			{32758,39,1}, /* core2 return_Stack2 bit47 */
			{32757,39,1}, /* core2 return_Stack2 bit48 */
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
			{28802,39,1}, /* core2 return_Stack3 bit0 */
			{28801,39,1}, /* core2 return_Stack3 bit1 */
			{28824,39,1}, /* core2 return_Stack3 bit2 */
			{28826,39,1}, /* core2 return_Stack3 bit3 */
			{28825,39,1}, /* core2 return_Stack3 bit4 */
			{28822,39,1}, /* core2 return_Stack3 bit5 */
			{28821,39,1}, /* core2 return_Stack3 bit6 */
			{28796,39,1}, /* core2 return_Stack3 bit7 */
			{28795,39,1}, /* core2 return_Stack3 bit8 */
			{28823,39,1}, /* core2 return_Stack3 bit9 */
			{28798,39,1}, /* core2 return_Stack3 bit10 */
			{28830,39,1}, /* core2 return_Stack3 bit11 */
			{28829,39,1}, /* core2 return_Stack3 bit12 */
			{28828,39,1}, /* core2 return_Stack3 bit13 */
			{28827,39,1}, /* core2 return_Stack3 bit14 */
			{32708,39,1}, /* core2 return_Stack3 bit15 */
			{28800,39,1}, /* core2 return_Stack3 bit16 */
			{28799,39,1}, /* core2 return_Stack3 bit17 */
			{32707,39,1}, /* core2 return_Stack3 bit18 */
			{32706,39,1}, /* core2 return_Stack3 bit19 */
			{32705,39,1}, /* core2 return_Stack3 bit20 */
			{28797,39,1}, /* core2 return_Stack3 bit21 */
			{26158,39,1}, /* core2 return_Stack3 bit22 */
			{26162,39,1}, /* core2 return_Stack3 bit23 */
			{26159,39,1}, /* core2 return_Stack3 bit24 */
			{26160,39,1}, /* core2 return_Stack3 bit25 */
			{32744,39,1}, /* core2 return_Stack3 bit26 */
			{32743,39,1}, /* core2 return_Stack3 bit27 */
			{32742,39,1}, /* core2 return_Stack3 bit28 */
			{32796,39,1}, /* core2 return_Stack3 bit29 */
			{32741,39,1}, /* core2 return_Stack3 bit30 */
			{32795,39,1}, /* core2 return_Stack3 bit31 */
			{28804,39,1}, /* core2 return_Stack3 bit32 */
			{32794,39,1}, /* core2 return_Stack3 bit33 */
			{32793,39,1}, /* core2 return_Stack3 bit34 */
			{28803,39,1}, /* core2 return_Stack3 bit35 */
			{32776,39,1}, /* core2 return_Stack3 bit36 */
			{32775,39,1}, /* core2 return_Stack3 bit37 */
			{32774,39,1}, /* core2 return_Stack3 bit38 */
			{32780,39,1}, /* core2 return_Stack3 bit39 */
			{32779,39,1}, /* core2 return_Stack3 bit40 */
			{32778,39,1}, /* core2 return_Stack3 bit41 */
			{32777,39,1}, /* core2 return_Stack3 bit42 */
			{32800,39,1}, /* core2 return_Stack3 bit43 */
			{32799,39,1}, /* core2 return_Stack3 bit44 */
			{32798,39,1}, /* core2 return_Stack3 bit45 */
			{32797,39,1}, /* core2 return_Stack3 bit46 */
			{32773,39,1}, /* core2 return_Stack3 bit47 */
			{26161,39,1}, /* core2 return_Stack3 bit48 */
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
			{32664,39,1}, /* core2 return_Stack4 bit0 */
			{32663,39,1}, /* core2 return_Stack4 bit1 */
			{32636,39,1}, /* core2 return_Stack4 bit2 */
			{32635,39,1}, /* core2 return_Stack4 bit3 */
			{28864,39,1}, /* core2 return_Stack4 bit4 */
			{28863,39,1}, /* core2 return_Stack4 bit5 */
			{32640,39,1}, /* core2 return_Stack4 bit6 */
			{32639,39,1}, /* core2 return_Stack4 bit7 */
			{32638,39,1}, /* core2 return_Stack4 bit8 */
			{32637,39,1}, /* core2 return_Stack4 bit9 */
			{32634,39,1}, /* core2 return_Stack4 bit10 */
			{32633,39,1}, /* core2 return_Stack4 bit11 */
			{28862,39,1}, /* core2 return_Stack4 bit12 */
			{28861,39,1}, /* core2 return_Stack4 bit13 */
			{32668,39,1}, /* core2 return_Stack4 bit14 */
			{32667,39,1}, /* core2 return_Stack4 bit15 */
			{32662,39,1}, /* core2 return_Stack4 bit16 */
			{32661,39,1}, /* core2 return_Stack4 bit17 */
			{32666,39,1}, /* core2 return_Stack4 bit18 */
			{32665,39,1}, /* core2 return_Stack4 bit19 */
			{28866,39,1}, /* core2 return_Stack4 bit20 */
			{28865,39,1}, /* core2 return_Stack4 bit21 */
			{28868,39,1}, /* core2 return_Stack4 bit22 */
			{28867,39,1}, /* core2 return_Stack4 bit23 */
			{26150,39,1}, /* core2 return_Stack4 bit24 */
			{26151,39,1}, /* core2 return_Stack4 bit25 */
			{32660,39,1}, /* core2 return_Stack4 bit26 */
			{32659,39,1}, /* core2 return_Stack4 bit27 */
			{32658,39,1}, /* core2 return_Stack4 bit28 */
			{32844,39,1}, /* core2 return_Stack4 bit29 */
			{32843,39,1}, /* core2 return_Stack4 bit30 */
			{32842,39,1}, /* core2 return_Stack4 bit31 */
			{32657,39,1}, /* core2 return_Stack4 bit32 */
			{25971,39,1}, /* core2 return_Stack4 bit33 */
			{32841,39,1}, /* core2 return_Stack4 bit34 */
			{32840,39,1}, /* core2 return_Stack4 bit35 */
			{32839,39,1}, /* core2 return_Stack4 bit36 */
			{32838,39,1}, /* core2 return_Stack4 bit37 */
			{32837,39,1}, /* core2 return_Stack4 bit38 */
			{32836,39,1}, /* core2 return_Stack4 bit39 */
			{32835,39,1}, /* core2 return_Stack4 bit40 */
			{32834,39,1}, /* core2 return_Stack4 bit41 */
			{32833,39,1}, /* core2 return_Stack4 bit42 */
			{25970,39,1}, /* core2 return_Stack4 bit43 */
			{28872,39,1}, /* core2 return_Stack4 bit44 */
			{28871,39,1}, /* core2 return_Stack4 bit45 */
			{28870,39,1}, /* core2 return_Stack4 bit46 */
			{28869,39,1}, /* core2 return_Stack4 bit47 */
			{25969,39,1}, /* core2 return_Stack4 bit48 */
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
			{28790,39,1}, /* core2 return_Stack5 bit0 */
			{28789,39,1}, /* core2 return_Stack5 bit1 */
			{32696,39,1}, /* core2 return_Stack5 bit2 */
			{32695,39,1}, /* core2 return_Stack5 bit3 */
			{28794,39,1}, /* core2 return_Stack5 bit4 */
			{28793,39,1}, /* core2 return_Stack5 bit5 */
			{32692,39,1}, /* core2 return_Stack5 bit6 */
			{32691,39,1}, /* core2 return_Stack5 bit7 */
			{32690,39,1}, /* core2 return_Stack5 bit8 */
			{32689,39,1}, /* core2 return_Stack5 bit9 */
			{32694,39,1}, /* core2 return_Stack5 bit10 */
			{32693,39,1}, /* core2 return_Stack5 bit11 */
			{32700,39,1}, /* core2 return_Stack5 bit12 */
			{32699,39,1}, /* core2 return_Stack5 bit13 */
			{28792,39,1}, /* core2 return_Stack5 bit14 */
			{28791,39,1}, /* core2 return_Stack5 bit15 */
			{28788,39,1}, /* core2 return_Stack5 bit16 */
			{28787,39,1}, /* core2 return_Stack5 bit17 */
			{32698,39,1}, /* core2 return_Stack5 bit18 */
			{32704,39,1}, /* core2 return_Stack5 bit19 */
			{32703,39,1}, /* core2 return_Stack5 bit20 */
			{32702,39,1}, /* core2 return_Stack5 bit21 */
			{32697,39,1}, /* core2 return_Stack5 bit22 */
			{28786,39,1}, /* core2 return_Stack5 bit23 */
			{32701,39,1}, /* core2 return_Stack5 bit24 */
			{28785,39,1}, /* core2 return_Stack5 bit25 */
			{32752,39,1}, /* core2 return_Stack5 bit26 */
			{25968,39,1}, /* core2 return_Stack5 bit27 */
			{32751,39,1}, /* core2 return_Stack5 bit28 */
			{32750,39,1}, /* core2 return_Stack5 bit29 */
			{32749,39,1}, /* core2 return_Stack5 bit30 */
			{32808,39,1}, /* core2 return_Stack5 bit31 */
			{32807,39,1}, /* core2 return_Stack5 bit32 */
			{32806,39,1}, /* core2 return_Stack5 bit33 */
			{32805,39,1}, /* core2 return_Stack5 bit34 */
			{32812,39,1}, /* core2 return_Stack5 bit35 */
			{32811,39,1}, /* core2 return_Stack5 bit36 */
			{32810,39,1}, /* core2 return_Stack5 bit37 */
			{32809,39,1}, /* core2 return_Stack5 bit38 */
			{32804,39,1}, /* core2 return_Stack5 bit39 */
			{32803,39,1}, /* core2 return_Stack5 bit40 */
			{32802,39,1}, /* core2 return_Stack5 bit41 */
			{32801,39,1}, /* core2 return_Stack5 bit42 */
			{32816,39,1}, /* core2 return_Stack5 bit43 */
			{32815,39,1}, /* core2 return_Stack5 bit44 */
			{32814,39,1}, /* core2 return_Stack5 bit45 */
			{32813,39,1}, /* core2 return_Stack5 bit46 */
			{25955,39,1}, /* core2 return_Stack5 bit47 */
			{25956,39,1}, /* core2 return_Stack5 bit48 */
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
			{28784,39,1}, /* core2 return_Stack6 bit0 */
			{28783,39,1}, /* core2 return_Stack6 bit1 */
			{28838,39,1}, /* core2 return_Stack6 bit2 */
			{32688,39,1}, /* core2 return_Stack6 bit3 */
			{28837,39,1}, /* core2 return_Stack6 bit4 */
			{32687,39,1}, /* core2 return_Stack6 bit5 */
			{32686,39,1}, /* core2 return_Stack6 bit6 */
			{32685,39,1}, /* core2 return_Stack6 bit7 */
			{28834,39,1}, /* core2 return_Stack6 bit8 */
			{28833,39,1}, /* core2 return_Stack6 bit9 */
			{32684,39,1}, /* core2 return_Stack6 bit10 */
			{32683,39,1}, /* core2 return_Stack6 bit11 */
			{32682,39,1}, /* core2 return_Stack6 bit12 */
			{32681,39,1}, /* core2 return_Stack6 bit13 */
			{28840,39,1}, /* core2 return_Stack6 bit14 */
			{28839,39,1}, /* core2 return_Stack6 bit15 */
			{28836,39,1}, /* core2 return_Stack6 bit16 */
			{28835,39,1}, /* core2 return_Stack6 bit17 */
			{28842,39,1}, /* core2 return_Stack6 bit18 */
			{28841,39,1}, /* core2 return_Stack6 bit19 */
			{28832,39,1}, /* core2 return_Stack6 bit20 */
			{28831,39,1}, /* core2 return_Stack6 bit21 */
			{25960,39,1}, /* core2 return_Stack6 bit22 */
			{25959,39,1}, /* core2 return_Stack6 bit23 */
			{25967,39,1}, /* core2 return_Stack6 bit24 */
			{25966,39,1}, /* core2 return_Stack6 bit25 */
			{32748,39,1}, /* core2 return_Stack6 bit26 */
			{32747,39,1}, /* core2 return_Stack6 bit27 */
			{28782,39,1}, /* core2 return_Stack6 bit28 */
			{32746,39,1}, /* core2 return_Stack6 bit29 */
			{32745,39,1}, /* core2 return_Stack6 bit30 */
			{28781,39,1}, /* core2 return_Stack6 bit31 */
			{25958,39,1}, /* core2 return_Stack6 bit32 */
			{28680,39,1}, /* core2 return_Stack6 bit33 */
			{28679,39,1}, /* core2 return_Stack6 bit34 */
			{25954,39,1}, /* core2 return_Stack6 bit35 */
			{25957,39,1}, /* core2 return_Stack6 bit36 */
			{28678,39,1}, /* core2 return_Stack6 bit37 */
			{28677,39,1}, /* core2 return_Stack6 bit38 */
			{32764,39,1}, /* core2 return_Stack6 bit39 */
			{32763,39,1}, /* core2 return_Stack6 bit40 */
			{32762,39,1}, /* core2 return_Stack6 bit41 */
			{32761,39,1}, /* core2 return_Stack6 bit42 */
			{28676,39,1}, /* core2 return_Stack6 bit43 */
			{28675,39,1}, /* core2 return_Stack6 bit44 */
			{28664,39,1}, /* core2 return_Stack6 bit45 */
			{28663,39,1}, /* core2 return_Stack6 bit46 */
			{28662,39,1}, /* core2 return_Stack6 bit47 */
			{28661,39,1}, /* core2 return_Stack6 bit48 */
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
			{32712,39,1}, /* core2 return_Stack7 bit0 */
			{32711,39,1}, /* core2 return_Stack7 bit1 */
			{32732,39,1}, /* core2 return_Stack7 bit2 */
			{32731,39,1}, /* core2 return_Stack7 bit3 */
			{32730,39,1}, /* core2 return_Stack7 bit4 */
			{32729,39,1}, /* core2 return_Stack7 bit5 */
			{28652,39,1}, /* core2 return_Stack7 bit6 */
			{28651,39,1}, /* core2 return_Stack7 bit7 */
			{28654,39,1}, /* core2 return_Stack7 bit8 */
			{28653,39,1}, /* core2 return_Stack7 bit9 */
			{32728,39,1}, /* core2 return_Stack7 bit10 */
			{32727,39,1}, /* core2 return_Stack7 bit11 */
			{28650,39,1}, /* core2 return_Stack7 bit12 */
			{28649,39,1}, /* core2 return_Stack7 bit13 */
			{32710,39,1}, /* core2 return_Stack7 bit14 */
			{32726,39,1}, /* core2 return_Stack7 bit15 */
			{32709,39,1}, /* core2 return_Stack7 bit16 */
			{32725,39,1}, /* core2 return_Stack7 bit17 */
			{28656,39,1}, /* core2 return_Stack7 bit18 */
			{28655,39,1}, /* core2 return_Stack7 bit19 */
			{28658,39,1}, /* core2 return_Stack7 bit20 */
			{28657,39,1}, /* core2 return_Stack7 bit21 */
			{25961,39,1}, /* core2 return_Stack7 bit22 */
			{25962,39,1}, /* core2 return_Stack7 bit23 */
			{25963,39,1}, /* core2 return_Stack7 bit24 */
			{25965,39,1}, /* core2 return_Stack7 bit25 */
			{28660,39,1}, /* core2 return_Stack7 bit26 */
			{32740,39,1}, /* core2 return_Stack7 bit27 */
			{28659,39,1}, /* core2 return_Stack7 bit28 */
			{32739,39,1}, /* core2 return_Stack7 bit29 */
			{32738,39,1}, /* core2 return_Stack7 bit30 */
			{32737,39,1}, /* core2 return_Stack7 bit31 */
			{32768,39,1}, /* core2 return_Stack7 bit32 */
			{32767,39,1}, /* core2 return_Stack7 bit33 */
			{32766,39,1}, /* core2 return_Stack7 bit34 */
			{32765,39,1}, /* core2 return_Stack7 bit35 */
			{28670,39,1}, /* core2 return_Stack7 bit36 */
			{28669,39,1}, /* core2 return_Stack7 bit37 */
			{28672,39,1}, /* core2 return_Stack7 bit38 */
			{28671,39,1}, /* core2 return_Stack7 bit39 */
			{32772,39,1}, /* core2 return_Stack7 bit40 */
			{32771,39,1}, /* core2 return_Stack7 bit41 */
			{32770,39,1}, /* core2 return_Stack7 bit42 */
			{32769,39,1}, /* core2 return_Stack7 bit43 */
			{28666,39,1}, /* core2 return_Stack7 bit44 */
			{28665,39,1}, /* core2 return_Stack7 bit45 */
			{28668,39,1}, /* core2 return_Stack7 bit46 */
			{28667,39,1}, /* core2 return_Stack7 bit47 */
			{25964,39,1}, /* core2 return_Stack7 bit48 */
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
			{ 5764, 8,0}, /* core2 L2_parity_err_count bit0 */
			{ 5763, 8,0}, /* core2 L2_parity_err_count bit1 */
			{ 5762, 8,0}, /* core2 L2_parity_err_count bit2 */
			{ 5761, 8,0}, /* core2 L2_parity_err_count bit3 */
			{ 5760, 8,0}, /* core2 L2_parity_err_count bit4 */
			{ 5759, 8,0}, /* core2 L2_parity_err_count bit5 */
			{ 5758, 8,0}, /* core2 L2_parity_err_count bit6 */
			{ 5757, 8,0}, /* core2 L2_parity_err_count bit7 */
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
			{ 5724, 8,0}, /* core2 L2_parity_index bit0 */
			{ 5723, 8,0}, /* core2 L2_parity_index bit1 */
			{ 5722, 8,0}, /* core2 L2_parity_index bit2 */
			{ 5721, 8,0}, /* core2 L2_parity_index bit3 */
			{ 5720, 8,0}, /* core2 L2_parity_index bit4 */
			{ 5719, 8,0}, /* core2 L2_parity_index bit5 */
			{ 5718, 8,0}, /* core2 L2_parity_index bit6 */
			{ 5717, 8,0}, /* core2 L2_parity_index bit7 */
			{ 5692, 8,0}, /* core2 L2_parity_index bit8 */
			{ 5691, 8,0}, /* core2 L2_parity_index bit9 */
			{ 5690, 8,0}, /* core2 L2_parity_index bit10 */
			{ 5689, 8,0}, /* core2 L2_parity_index bit11 */
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
			{ 5685, 8,0}, /* core2 L2_parity_way bit0 */
			{ 5157, 8,0}, /* core2 L2_parity_way bit1 */
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
			{ 5838, 8,0}, /* core2 L2_parity_banks bit0 */
			{ 5837, 8,0}, /* core2 L2_parity_banks bit1 */
			{ 5836, 8,0}, /* core2 L2_parity_banks bit2 */
			{ 5835, 8,0}, /* core2 L2_parity_banks bit3 */
			{ 5834, 8,0}, /* core2 L2_parity_banks bit4 */
			{ 5833, 8,0}, /* core2 L2_parity_banks bit5 */
			{ 5832, 8,0}, /* core2 L2_parity_banks bit6 */
			{ 5831, 8,0}, /* core2 L2_parity_banks bit7 */
			{ 5772, 8,0}, /* core2 L2_parity_banks bit8 */
			{ 5771, 8,0}, /* core2 L2_parity_banks bit9 */
			{ 5770, 8,0}, /* core2 L2_parity_banks bit10 */
			{ 5769, 8,0}, /* core2 L2_parity_banks bit11 */
			{ 5768, 8,0}, /* core2 L2_parity_banks bit12 */
			{ 5767, 8,0}, /* core2 L2_parity_banks bit13 */
			{ 5766, 8,0}, /* core2 L2_parity_banks bit14 */
			{ 5765, 8,0}, /* core2 L2_parity_banks bit15 */
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
			{   95,40,1}, /* core3 pc bit0 */
			{  433,40,1}, /* core3 pc bit1 */
			{  432,40,1}, /* core3 pc bit2 */
			{  431,40,1}, /* core3 pc bit3 */
			{  430,40,1}, /* core3 pc bit4 */
			{  429,40,1}, /* core3 pc bit5 */
			{  495,40,1}, /* core3 pc bit6 */
			{  426,40,1}, /* core3 pc bit7 */
			{  494,40,1}, /* core3 pc bit8 */
			{  425,40,1}, /* core3 pc bit9 */
			{  424,40,1}, /* core3 pc bit10 */
			{  445,40,1}, /* core3 pc bit11 */
			{  493,40,1}, /* core3 pc bit12 */
			{  492,40,1}, /* core3 pc bit13 */
			{  444,40,1}, /* core3 pc bit14 */
			{  443,40,1}, /* core3 pc bit15 */
			{  466,40,1}, /* core3 pc bit16 */
			{  482,40,1}, /* core3 pc bit17 */
			{  465,40,1}, /* core3 pc bit18 */
			{  464,40,1}, /* core3 pc bit19 */
			{  470,40,1}, /* core3 pc bit20 */
			{  463,40,1}, /* core3 pc bit21 */
			{  440,40,1}, /* core3 pc bit22 */
			{  446,40,1}, /* core3 pc bit23 */
			{  491,40,1}, /* core3 pc bit24 */
			{  462,40,1}, /* core3 pc bit25 */
			{  481,40,1}, /* core3 pc bit26 */
			{  480,40,1}, /* core3 pc bit27 */
			{  461,40,1}, /* core3 pc bit28 */
			{  460,40,1}, /* core3 pc bit29 */
			{  448,40,1}, /* core3 pc bit30 */
			{  450,40,1}, /* core3 pc bit31 */
			{  270,40,1}, /* core3 pc bit32 */
			{  269,40,1}, /* core3 pc bit33 */
			{  268,40,1}, /* core3 pc bit34 */
			{  278,40,1}, /* core3 pc bit35 */
			{  320,40,1}, /* core3 pc bit36 */
			{  267,40,1}, /* core3 pc bit37 */
			{  266,40,1}, /* core3 pc bit38 */
			{  312,40,1}, /* core3 pc bit39 */
			{  162,40,1}, /* core3 pc bit40 */
			{  319,40,1}, /* core3 pc bit41 */
			{  318,40,1}, /* core3 pc bit42 */
			{  161,40,1}, /* core3 pc bit43 */
			{  160,40,1}, /* core3 pc bit44 */
			{  159,40,1}, /* core3 pc bit45 */
			{  317,40,1}, /* core3 pc bit46 */
			{  316,40,1}, /* core3 pc bit47 */
			{  140,40,1}, /* core3 pc bit48 */
			{  277,40,1}, /* core3 pc bit49 */
			{  276,40,1}, /* core3 pc bit50 */
			{  275,40,1}, /* core3 pc bit51 */
			{  274,40,1}, /* core3 pc bit52 */
			{  139,40,1}, /* core3 pc bit53 */
			{  280,40,1}, /* core3 pc bit54 */
			{  279,40,1}, /* core3 pc bit55 */
			{  353,40,1}, /* core3 pc bit56 */
			{  273,40,1}, /* core3 pc bit57 */
			{  288,40,1}, /* core3 pc bit58 */
			{  287,40,1}, /* core3 pc bit59 */
			{  138,40,1}, /* core3 pc bit60 */
			{  264,40,1}, /* core3 pc bit61 */
			{  263,40,1}, /* core3 pc bit62 */
			{  145,40,1}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{41179,41,1}, /* core3 sp32 bit0 */
			{41177,41,1}, /* core3 sp32 bit1 */
			{41176,41,1}, /* core3 sp32 bit2 */
			{41175,41,1}, /* core3 sp32 bit3 */
			{41178,41,1}, /* core3 sp32 bit4 */
			{41171,41,1}, /* core3 sp32 bit5 */
			{41170,41,1}, /* core3 sp32 bit6 */
			{41172,41,1}, /* core3 sp32 bit7 */
			{41173,41,1}, /* core3 sp32 bit8 */
			{41174,41,1}, /* core3 sp32 bit9 */
			{41197,41,1}, /* core3 sp32 bit10 */
			{41190,41,1}, /* core3 sp32 bit11 */
			{41182,41,1}, /* core3 sp32 bit12 */
			{41201,41,1}, /* core3 sp32 bit13 */
			{41184,41,1}, /* core3 sp32 bit14 */
			{41198,41,1}, /* core3 sp32 bit15 */
			{34300,40,0}, /* core3 sp32 bit16 */
			{34299,40,0}, /* core3 sp32 bit17 */
			{34328,40,0}, /* core3 sp32 bit18 */
			{34327,40,0}, /* core3 sp32 bit19 */
			{41196,41,1}, /* core3 sp32 bit20 */
			{41185,41,1}, /* core3 sp32 bit21 */
			{41227,41,1}, /* core3 sp32 bit22 */
			{41226,41,1}, /* core3 sp32 bit23 */
			{41180,41,1}, /* core3 sp32 bit24 */
			{41181,41,1}, /* core3 sp32 bit25 */
			{41183,41,1}, /* core3 sp32 bit26 */
			{41186,41,1}, /* core3 sp32 bit27 */
			{41199,41,1}, /* core3 sp32 bit28 */
			{41191,41,1}, /* core3 sp32 bit29 */
			{41188,41,1}, /* core3 sp32 bit30 */
			{41189,41,1}, /* core3 sp32 bit31 */
			{41121,41,1}, /* core3 sp32 bit32 */
			{41123,41,1}, /* core3 sp32 bit33 */
			{41113,41,1}, /* core3 sp32 bit34 */
			{41115,41,1}, /* core3 sp32 bit35 */
			{41120,41,1}, /* core3 sp32 bit36 */
			{41118,41,1}, /* core3 sp32 bit37 */
			{41122,41,1}, /* core3 sp32 bit38 */
			{41117,41,1}, /* core3 sp32 bit39 */
			{41116,41,1}, /* core3 sp32 bit40 */
			{41119,41,1}, /* core3 sp32 bit41 */
			{41108,41,1}, /* core3 sp32 bit42 */
			{41109,41,1}, /* core3 sp32 bit43 */
			{41110,41,1}, /* core3 sp32 bit44 */
			{41114,41,1}, /* core3 sp32 bit45 */
			{41111,41,1}, /* core3 sp32 bit46 */
			{41112,41,1}, /* core3 sp32 bit47 */
			{41159,41,1}, /* core3 sp32 bit48 */
			{41164,41,1}, /* core3 sp32 bit49 */
			{34350,40,0}, /* core3 sp32 bit50 */
			{34349,40,0}, /* core3 sp32 bit51 */
			{41166,41,1}, /* core3 sp32 bit52 */
			{41165,41,1}, /* core3 sp32 bit53 */
			{41163,41,1}, /* core3 sp32 bit54 */
			{41161,41,1}, /* core3 sp32 bit55 */
			{41167,41,1}, /* core3 sp32 bit56 */
			{41160,41,1}, /* core3 sp32 bit57 */
			{41162,41,1}, /* core3 sp32 bit58 */
			{41158,41,1}, /* core3 sp32 bit59 */
			{41157,41,1}, /* core3 sp32 bit60 */
			{41155,41,1}, /* core3 sp32 bit61 */
			{41154,41,1}, /* core3 sp32 bit62 */
			{41156,41,1}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{41650,41,1}, /* core3 fp32 bit0 */
			{41651,41,1}, /* core3 fp32 bit1 */
			{41648,41,1}, /* core3 fp32 bit2 */
			{41645,41,1}, /* core3 fp32 bit3 */
			{41652,41,1}, /* core3 fp32 bit4 */
			{41647,41,1}, /* core3 fp32 bit5 */
			{41644,41,1}, /* core3 fp32 bit6 */
			{41646,41,1}, /* core3 fp32 bit7 */
			{41643,41,1}, /* core3 fp32 bit8 */
			{41642,41,1}, /* core3 fp32 bit9 */
			{41676,41,1}, /* core3 fp32 bit10 */
			{41675,41,1}, /* core3 fp32 bit11 */
			{41685,41,1}, /* core3 fp32 bit12 */
			{41684,41,1}, /* core3 fp32 bit13 */
			{41680,41,1}, /* core3 fp32 bit14 */
			{41681,41,1}, /* core3 fp32 bit15 */
			{41682,41,1}, /* core3 fp32 bit16 */
			{41656,41,1}, /* core3 fp32 bit17 */
			{41678,41,1}, /* core3 fp32 bit18 */
			{41683,41,1}, /* core3 fp32 bit19 */
			{41677,41,1}, /* core3 fp32 bit20 */
			{41672,41,1}, /* core3 fp32 bit21 */
			{41686,41,1}, /* core3 fp32 bit22 */
			{41649,41,1}, /* core3 fp32 bit23 */
			{41688,41,1}, /* core3 fp32 bit24 */
			{41689,41,1}, /* core3 fp32 bit25 */
			{41669,41,1}, /* core3 fp32 bit26 */
			{41670,41,1}, /* core3 fp32 bit27 */
			{41673,41,1}, /* core3 fp32 bit28 */
			{41679,41,1}, /* core3 fp32 bit29 */
			{41674,41,1}, /* core3 fp32 bit30 */
			{41671,41,1}, /* core3 fp32 bit31 */
			{41580,41,1}, /* core3 fp32 bit32 */
			{41589,41,1}, /* core3 fp32 bit33 */
			{41583,41,1}, /* core3 fp32 bit34 */
			{41587,41,1}, /* core3 fp32 bit35 */
			{41582,41,1}, /* core3 fp32 bit36 */
			{41575,41,1}, /* core3 fp32 bit37 */
			{41576,41,1}, /* core3 fp32 bit38 */
			{41585,41,1}, /* core3 fp32 bit39 */
			{41584,41,1}, /* core3 fp32 bit40 */
			{41581,41,1}, /* core3 fp32 bit41 */
			{41588,41,1}, /* core3 fp32 bit42 */
			{41577,41,1}, /* core3 fp32 bit43 */
			{41578,41,1}, /* core3 fp32 bit44 */
			{41579,41,1}, /* core3 fp32 bit45 */
			{41574,41,1}, /* core3 fp32 bit46 */
			{41586,41,1}, /* core3 fp32 bit47 */
			{41605,41,1}, /* core3 fp32 bit48 */
			{41604,41,1}, /* core3 fp32 bit49 */
			{41606,41,1}, /* core3 fp32 bit50 */
			{41609,41,1}, /* core3 fp32 bit51 */
			{41607,41,1}, /* core3 fp32 bit52 */
			{41610,41,1}, /* core3 fp32 bit53 */
			{41602,41,1}, /* core3 fp32 bit54 */
			{41597,41,1}, /* core3 fp32 bit55 */
			{41608,41,1}, /* core3 fp32 bit56 */
			{41598,41,1}, /* core3 fp32 bit57 */
			{41601,41,1}, /* core3 fp32 bit58 */
			{41596,41,1}, /* core3 fp32 bit59 */
			{41593,41,1}, /* core3 fp32 bit60 */
			{34376,40,0}, /* core3 fp32 bit61 */
			{34375,40,0}, /* core3 fp32 bit62 */
			{41594,41,1}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{40573,41,1}, /* core3 fp64 bit0 */
			{40571,41,1}, /* core3 fp64 bit1 */
			{40569,41,1}, /* core3 fp64 bit2 */
			{34306,40,0}, /* core3 fp64 bit3 */
			{34305,40,0}, /* core3 fp64 bit4 */
			{40567,41,1}, /* core3 fp64 bit5 */
			{40568,41,1}, /* core3 fp64 bit6 */
			{34304,40,0}, /* core3 fp64 bit7 */
			{34303,40,0}, /* core3 fp64 bit8 */
			{40570,41,1}, /* core3 fp64 bit9 */
			{40560,41,1}, /* core3 fp64 bit10 */
			{40558,41,1}, /* core3 fp64 bit11 */
			{40566,41,1}, /* core3 fp64 bit12 */
			{40565,41,1}, /* core3 fp64 bit13 */
			{40564,41,1}, /* core3 fp64 bit14 */
			{40559,41,1}, /* core3 fp64 bit15 */
			{40554,41,1}, /* core3 fp64 bit16 */
			{40490,41,1}, /* core3 fp64 bit17 */
			{40552,41,1}, /* core3 fp64 bit18 */
			{40555,41,1}, /* core3 fp64 bit19 */
			{40557,41,1}, /* core3 fp64 bit20 */
			{40553,41,1}, /* core3 fp64 bit21 */
			{40572,41,1}, /* core3 fp64 bit22 */
			{40491,41,1}, /* core3 fp64 bit23 */
			{40492,41,1}, /* core3 fp64 bit24 */
			{40493,41,1}, /* core3 fp64 bit25 */
			{40563,41,1}, /* core3 fp64 bit26 */
			{34322,40,0}, /* core3 fp64 bit27 */
			{34321,40,0}, /* core3 fp64 bit28 */
			{40562,41,1}, /* core3 fp64 bit29 */
			{40561,41,1}, /* core3 fp64 bit30 */
			{40556,41,1}, /* core3 fp64 bit31 */
			{40702,41,1}, /* core3 fp64 bit32 */
			{40697,41,1}, /* core3 fp64 bit33 */
			{40699,41,1}, /* core3 fp64 bit34 */
			{40708,41,1}, /* core3 fp64 bit35 */
			{40706,41,1}, /* core3 fp64 bit36 */
			{40701,41,1}, /* core3 fp64 bit37 */
			{40703,41,1}, /* core3 fp64 bit38 */
			{40705,41,1}, /* core3 fp64 bit39 */
			{40704,41,1}, /* core3 fp64 bit40 */
			{40698,41,1}, /* core3 fp64 bit41 */
			{40707,41,1}, /* core3 fp64 bit42 */
			{40700,41,1}, /* core3 fp64 bit43 */
			{40709,41,1}, /* core3 fp64 bit44 */
			{40696,41,1}, /* core3 fp64 bit45 */
			{40727,41,1}, /* core3 fp64 bit46 */
			{40695,41,1}, /* core3 fp64 bit47 */
			{40690,41,1}, /* core3 fp64 bit48 */
			{40638,41,1}, /* core3 fp64 bit49 */
			{40642,41,1}, /* core3 fp64 bit50 */
			{40645,41,1}, /* core3 fp64 bit51 */
			{40644,41,1}, /* core3 fp64 bit52 */
			{40643,41,1}, /* core3 fp64 bit53 */
			{40637,41,1}, /* core3 fp64 bit54 */
			{40632,41,1}, /* core3 fp64 bit55 */
			{40646,41,1}, /* core3 fp64 bit56 */
			{40633,41,1}, /* core3 fp64 bit57 */
			{40635,41,1}, /* core3 fp64 bit58 */
			{40691,41,1}, /* core3 fp64 bit59 */
			{40693,41,1}, /* core3 fp64 bit60 */
			{40726,41,1}, /* core3 fp64 bit61 */
			{40692,41,1}, /* core3 fp64 bit62 */
			{40694,41,1}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40577,41,1}, /* core3 sp_EL0 bit0 */
			{40575,41,1}, /* core3 sp_EL0 bit1 */
			{40580,41,1}, /* core3 sp_EL0 bit2 */
			{40582,41,1}, /* core3 sp_EL0 bit3 */
			{40583,41,1}, /* core3 sp_EL0 bit4 */
			{40581,41,1}, /* core3 sp_EL0 bit5 */
			{34278,40,0}, /* core3 sp_EL0 bit6 */
			{34277,40,0}, /* core3 sp_EL0 bit7 */
			{40578,41,1}, /* core3 sp_EL0 bit8 */
			{40576,41,1}, /* core3 sp_EL0 bit9 */
			{40488,41,1}, /* core3 sp_EL0 bit10 */
			{40487,41,1}, /* core3 sp_EL0 bit11 */
			{34276,40,0}, /* core3 sp_EL0 bit12 */
			{34275,40,0}, /* core3 sp_EL0 bit13 */
			{40579,41,1}, /* core3 sp_EL0 bit14 */
			{40574,41,1}, /* core3 sp_EL0 bit15 */
			{34284,40,0}, /* core3 sp_EL0 bit16 */
			{34283,40,0}, /* core3 sp_EL0 bit17 */
			{40489,41,1}, /* core3 sp_EL0 bit18 */
			{40486,41,1}, /* core3 sp_EL0 bit19 */
			{40485,41,1}, /* core3 sp_EL0 bit20 */
			{40484,41,1}, /* core3 sp_EL0 bit21 */
			{40306,41,1}, /* core3 sp_EL0 bit22 */
			{40302,41,1}, /* core3 sp_EL0 bit23 */
			{40304,41,1}, /* core3 sp_EL0 bit24 */
			{40305,41,1}, /* core3 sp_EL0 bit25 */
			{40282,41,1}, /* core3 sp_EL0 bit26 */
			{40283,41,1}, /* core3 sp_EL0 bit27 */
			{40285,41,1}, /* core3 sp_EL0 bit28 */
			{40284,41,1}, /* core3 sp_EL0 bit29 */
			{40286,41,1}, /* core3 sp_EL0 bit30 */
			{40303,41,1}, /* core3 sp_EL0 bit31 */
			{40436,41,1}, /* core3 sp_EL0 bit32 */
			{40434,41,1}, /* core3 sp_EL0 bit33 */
			{40440,41,1}, /* core3 sp_EL0 bit34 */
			{40437,41,1}, /* core3 sp_EL0 bit35 */
			{40427,41,1}, /* core3 sp_EL0 bit36 */
			{40428,41,1}, /* core3 sp_EL0 bit37 */
			{40431,41,1}, /* core3 sp_EL0 bit38 */
			{40429,41,1}, /* core3 sp_EL0 bit39 */
			{40430,41,1}, /* core3 sp_EL0 bit40 */
			{40441,41,1}, /* core3 sp_EL0 bit41 */
			{40433,41,1}, /* core3 sp_EL0 bit42 */
			{40432,41,1}, /* core3 sp_EL0 bit43 */
			{40439,41,1}, /* core3 sp_EL0 bit44 */
			{40438,41,1}, /* core3 sp_EL0 bit45 */
			{40443,41,1}, /* core3 sp_EL0 bit46 */
			{40442,41,1}, /* core3 sp_EL0 bit47 */
			{40456,41,1}, /* core3 sp_EL0 bit48 */
			{34430,40,0}, /* core3 sp_EL0 bit49 */
			{34426,40,0}, /* core3 sp_EL0 bit50 */
			{34425,40,0}, /* core3 sp_EL0 bit51 */
			{34432,40,0}, /* core3 sp_EL0 bit52 */
			{34431,40,0}, /* core3 sp_EL0 bit53 */
			{34429,40,0}, /* core3 sp_EL0 bit54 */
			{40446,41,1}, /* core3 sp_EL0 bit55 */
			{36696,40,0}, /* core3 sp_EL0 bit56 */
			{36695,40,0}, /* core3 sp_EL0 bit57 */
			{36694,40,0}, /* core3 sp_EL0 bit58 */
			{36693,40,0}, /* core3 sp_EL0 bit59 */
			{40445,41,1}, /* core3 sp_EL0 bit60 */
			{40444,41,1}, /* core3 sp_EL0 bit61 */
			{34392,40,0}, /* core3 sp_EL0 bit62 */
			{34391,40,0}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40312,41,1}, /* core3 sp_EL1 bit0 */
			{40319,41,1}, /* core3 sp_EL1 bit1 */
			{40314,41,1}, /* core3 sp_EL1 bit2 */
			{40315,41,1}, /* core3 sp_EL1 bit3 */
			{34236,40,0}, /* core3 sp_EL1 bit4 */
			{34235,40,0}, /* core3 sp_EL1 bit5 */
			{34238,40,0}, /* core3 sp_EL1 bit6 */
			{34237,40,0}, /* core3 sp_EL1 bit7 */
			{40313,41,1}, /* core3 sp_EL1 bit8 */
			{40316,41,1}, /* core3 sp_EL1 bit9 */
			{40336,41,1}, /* core3 sp_EL1 bit10 */
			{40333,41,1}, /* core3 sp_EL1 bit11 */
			{40311,41,1}, /* core3 sp_EL1 bit12 */
			{40308,41,1}, /* core3 sp_EL1 bit13 */
			{40331,41,1}, /* core3 sp_EL1 bit14 */
			{40330,41,1}, /* core3 sp_EL1 bit15 */
			{34216,40,0}, /* core3 sp_EL1 bit16 */
			{34215,40,0}, /* core3 sp_EL1 bit17 */
			{40348,41,1}, /* core3 sp_EL1 bit18 */
			{40349,41,1}, /* core3 sp_EL1 bit19 */
			{40350,41,1}, /* core3 sp_EL1 bit20 */
			{40346,41,1}, /* core3 sp_EL1 bit21 */
			{40332,41,1}, /* core3 sp_EL1 bit22 */
			{40334,41,1}, /* core3 sp_EL1 bit23 */
			{40335,41,1}, /* core3 sp_EL1 bit24 */
			{40347,41,1}, /* core3 sp_EL1 bit25 */
			{40320,41,1}, /* core3 sp_EL1 bit26 */
			{40321,41,1}, /* core3 sp_EL1 bit27 */
			{40310,41,1}, /* core3 sp_EL1 bit28 */
			{40309,41,1}, /* core3 sp_EL1 bit29 */
			{40307,41,1}, /* core3 sp_EL1 bit30 */
			{40345,41,1}, /* core3 sp_EL1 bit31 */
			{40406,41,1}, /* core3 sp_EL1 bit32 */
			{40405,41,1}, /* core3 sp_EL1 bit33 */
			{40386,41,1}, /* core3 sp_EL1 bit34 */
			{40383,41,1}, /* core3 sp_EL1 bit35 */
			{40422,41,1}, /* core3 sp_EL1 bit36 */
			{40421,41,1}, /* core3 sp_EL1 bit37 */
			{40407,41,1}, /* core3 sp_EL1 bit38 */
			{40400,41,1}, /* core3 sp_EL1 bit39 */
			{40401,41,1}, /* core3 sp_EL1 bit40 */
			{40409,41,1}, /* core3 sp_EL1 bit41 */
			{40410,41,1}, /* core3 sp_EL1 bit42 */
			{40411,41,1}, /* core3 sp_EL1 bit43 */
			{40408,41,1}, /* core3 sp_EL1 bit44 */
			{40384,41,1}, /* core3 sp_EL1 bit45 */
			{40379,41,1}, /* core3 sp_EL1 bit46 */
			{40385,41,1}, /* core3 sp_EL1 bit47 */
			{40449,41,1}, /* core3 sp_EL1 bit48 */
			{39472,40,0}, /* core3 sp_EL1 bit49 */
			{39471,40,0}, /* core3 sp_EL1 bit50 */
			{39470,40,0}, /* core3 sp_EL1 bit51 */
			{39469,40,0}, /* core3 sp_EL1 bit52 */
			{39468,40,0}, /* core3 sp_EL1 bit53 */
			{39467,40,0}, /* core3 sp_EL1 bit54 */
			{39466,40,0}, /* core3 sp_EL1 bit55 */
			{39465,40,0}, /* core3 sp_EL1 bit56 */
			{40448,41,1}, /* core3 sp_EL1 bit57 */
			{34398,40,0}, /* core3 sp_EL1 bit58 */
			{34397,40,0}, /* core3 sp_EL1 bit59 */
			{34386,40,0}, /* core3 sp_EL1 bit60 */
			{34385,40,0}, /* core3 sp_EL1 bit61 */
			{34198,40,0}, /* core3 sp_EL1 bit62 */
			{34197,40,0}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40264,41,1}, /* core3 sp_EL2 bit0 */
			{40256,41,1}, /* core3 sp_EL2 bit1 */
			{40268,41,1}, /* core3 sp_EL2 bit2 */
			{40266,41,1}, /* core3 sp_EL2 bit3 */
			{40257,41,1}, /* core3 sp_EL2 bit4 */
			{40263,41,1}, /* core3 sp_EL2 bit5 */
			{40267,41,1}, /* core3 sp_EL2 bit6 */
			{40262,41,1}, /* core3 sp_EL2 bit7 */
			{40261,41,1}, /* core3 sp_EL2 bit8 */
			{40260,41,1}, /* core3 sp_EL2 bit9 */
			{40245,41,1}, /* core3 sp_EL2 bit10 */
			{40246,41,1}, /* core3 sp_EL2 bit11 */
			{40265,41,1}, /* core3 sp_EL2 bit12 */
			{40243,41,1}, /* core3 sp_EL2 bit13 */
			{40241,41,1}, /* core3 sp_EL2 bit14 */
			{40239,41,1}, /* core3 sp_EL2 bit15 */
			{40251,41,1}, /* core3 sp_EL2 bit16 */
			{40259,41,1}, /* core3 sp_EL2 bit17 */
			{40250,41,1}, /* core3 sp_EL2 bit18 */
			{40247,41,1}, /* core3 sp_EL2 bit19 */
			{40248,41,1}, /* core3 sp_EL2 bit20 */
			{40249,41,1}, /* core3 sp_EL2 bit21 */
			{40255,41,1}, /* core3 sp_EL2 bit22 */
			{40258,41,1}, /* core3 sp_EL2 bit23 */
			{40254,41,1}, /* core3 sp_EL2 bit24 */
			{40253,41,1}, /* core3 sp_EL2 bit25 */
			{40238,41,1}, /* core3 sp_EL2 bit26 */
			{40237,41,1}, /* core3 sp_EL2 bit27 */
			{40242,41,1}, /* core3 sp_EL2 bit28 */
			{40240,41,1}, /* core3 sp_EL2 bit29 */
			{40244,41,1}, /* core3 sp_EL2 bit30 */
			{40252,41,1}, /* core3 sp_EL2 bit31 */
			{40402,41,1}, /* core3 sp_EL2 bit32 */
			{40412,41,1}, /* core3 sp_EL2 bit33 */
			{40387,41,1}, /* core3 sp_EL2 bit34 */
			{40388,41,1}, /* core3 sp_EL2 bit35 */
			{40419,41,1}, /* core3 sp_EL2 bit36 */
			{40414,41,1}, /* core3 sp_EL2 bit37 */
			{40413,41,1}, /* core3 sp_EL2 bit38 */
			{40417,41,1}, /* core3 sp_EL2 bit39 */
			{40416,41,1}, /* core3 sp_EL2 bit40 */
			{40418,41,1}, /* core3 sp_EL2 bit41 */
			{40415,41,1}, /* core3 sp_EL2 bit42 */
			{40420,41,1}, /* core3 sp_EL2 bit43 */
			{40404,41,1}, /* core3 sp_EL2 bit44 */
			{40403,41,1}, /* core3 sp_EL2 bit45 */
			{40378,41,1}, /* core3 sp_EL2 bit46 */
			{40389,41,1}, /* core3 sp_EL2 bit47 */
			{40447,41,1}, /* core3 sp_EL2 bit48 */
			{40460,41,1}, /* core3 sp_EL2 bit49 */
			{34422,40,0}, /* core3 sp_EL2 bit50 */
			{34421,40,0}, /* core3 sp_EL2 bit51 */
			{34420,40,0}, /* core3 sp_EL2 bit52 */
			{34419,40,0}, /* core3 sp_EL2 bit53 */
			{34416,40,0}, /* core3 sp_EL2 bit54 */
			{34415,40,0}, /* core3 sp_EL2 bit55 */
			{34400,40,0}, /* core3 sp_EL2 bit56 */
			{34399,40,0}, /* core3 sp_EL2 bit57 */
			{34396,40,0}, /* core3 sp_EL2 bit58 */
			{34395,40,0}, /* core3 sp_EL2 bit59 */
			{36728,40,0}, /* core3 sp_EL2 bit60 */
			{36727,40,0}, /* core3 sp_EL2 bit61 */
			{36726,40,0}, /* core3 sp_EL2 bit62 */
			{36725,40,0}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40272,41,1}, /* core3 sp_EL3 bit0 */
			{40289,41,1}, /* core3 sp_EL3 bit1 */
			{40277,41,1}, /* core3 sp_EL3 bit2 */
			{40279,41,1}, /* core3 sp_EL3 bit3 */
			{40281,41,1}, /* core3 sp_EL3 bit4 */
			{40280,41,1}, /* core3 sp_EL3 bit5 */
			{34280,40,0}, /* core3 sp_EL3 bit6 */
			{34279,40,0}, /* core3 sp_EL3 bit7 */
			{40278,41,1}, /* core3 sp_EL3 bit8 */
			{40276,41,1}, /* core3 sp_EL3 bit9 */
			{40290,41,1}, /* core3 sp_EL3 bit10 */
			{40292,41,1}, /* core3 sp_EL3 bit11 */
			{34282,40,0}, /* core3 sp_EL3 bit12 */
			{34281,40,0}, /* core3 sp_EL3 bit13 */
			{40288,41,1}, /* core3 sp_EL3 bit14 */
			{40287,41,1}, /* core3 sp_EL3 bit15 */
			{40300,41,1}, /* core3 sp_EL3 bit16 */
			{40301,41,1}, /* core3 sp_EL3 bit17 */
			{40291,41,1}, /* core3 sp_EL3 bit18 */
			{40299,41,1}, /* core3 sp_EL3 bit19 */
			{40297,41,1}, /* core3 sp_EL3 bit20 */
			{40298,41,1}, /* core3 sp_EL3 bit21 */
			{40271,41,1}, /* core3 sp_EL3 bit22 */
			{40294,41,1}, /* core3 sp_EL3 bit23 */
			{40295,41,1}, /* core3 sp_EL3 bit24 */
			{40296,41,1}, /* core3 sp_EL3 bit25 */
			{40275,41,1}, /* core3 sp_EL3 bit26 */
			{40274,41,1}, /* core3 sp_EL3 bit27 */
			{40273,41,1}, /* core3 sp_EL3 bit28 */
			{40270,41,1}, /* core3 sp_EL3 bit29 */
			{40269,41,1}, /* core3 sp_EL3 bit30 */
			{40293,41,1}, /* core3 sp_EL3 bit31 */
			{40393,41,1}, /* core3 sp_EL3 bit32 */
			{40392,41,1}, /* core3 sp_EL3 bit33 */
			{40391,41,1}, /* core3 sp_EL3 bit34 */
			{40396,41,1}, /* core3 sp_EL3 bit35 */
			{40425,41,1}, /* core3 sp_EL3 bit36 */
			{40423,41,1}, /* core3 sp_EL3 bit37 */
			{40395,41,1}, /* core3 sp_EL3 bit38 */
			{40426,41,1}, /* core3 sp_EL3 bit39 */
			{40397,41,1}, /* core3 sp_EL3 bit40 */
			{40399,41,1}, /* core3 sp_EL3 bit41 */
			{40424,41,1}, /* core3 sp_EL3 bit42 */
			{40398,41,1}, /* core3 sp_EL3 bit43 */
			{40394,41,1}, /* core3 sp_EL3 bit44 */
			{40435,41,1}, /* core3 sp_EL3 bit45 */
			{40377,41,1}, /* core3 sp_EL3 bit46 */
			{40390,41,1}, /* core3 sp_EL3 bit47 */
			{40458,41,1}, /* core3 sp_EL3 bit48 */
			{40457,41,1}, /* core3 sp_EL3 bit49 */
			{34418,40,0}, /* core3 sp_EL3 bit50 */
			{34417,40,0}, /* core3 sp_EL3 bit51 */
			{36776,40,0}, /* core3 sp_EL3 bit52 */
			{36775,40,0}, /* core3 sp_EL3 bit53 */
			{36774,40,0}, /* core3 sp_EL3 bit54 */
			{36773,40,0}, /* core3 sp_EL3 bit55 */
			{36692,40,0}, /* core3 sp_EL3 bit56 */
			{36691,40,0}, /* core3 sp_EL3 bit57 */
			{36690,40,0}, /* core3 sp_EL3 bit58 */
			{36689,40,0}, /* core3 sp_EL3 bit59 */
			{40375,41,1}, /* core3 sp_EL3 bit60 */
			{40374,41,1}, /* core3 sp_EL3 bit61 */
			{34388,40,0}, /* core3 sp_EL3 bit62 */
			{34387,40,0}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{39606,40,0}, /* core3 elr_EL1 bit0 */
			{39605,40,0}, /* core3 elr_EL1 bit1 */
			{39604,40,0}, /* core3 elr_EL1 bit2 */
			{39603,40,0}, /* core3 elr_EL1 bit3 */
			{39602,40,0}, /* core3 elr_EL1 bit4 */
			{39601,40,0}, /* core3 elr_EL1 bit5 */
			{39600,40,0}, /* core3 elr_EL1 bit6 */
			{39599,40,0}, /* core3 elr_EL1 bit7 */
			{34224,40,0}, /* core3 elr_EL1 bit8 */
			{34223,40,0}, /* core3 elr_EL1 bit9 */
			{34218,40,0}, /* core3 elr_EL1 bit10 */
			{34217,40,0}, /* core3 elr_EL1 bit11 */
			{34222,40,0}, /* core3 elr_EL1 bit12 */
			{34221,40,0}, /* core3 elr_EL1 bit13 */
			{34220,40,0}, /* core3 elr_EL1 bit14 */
			{34219,40,0}, /* core3 elr_EL1 bit15 */
			{39654,40,0}, /* core3 elr_EL1 bit16 */
			{39653,40,0}, /* core3 elr_EL1 bit17 */
			{39652,40,0}, /* core3 elr_EL1 bit18 */
			{39651,40,0}, /* core3 elr_EL1 bit19 */
			{39650,40,0}, /* core3 elr_EL1 bit20 */
			{39649,40,0}, /* core3 elr_EL1 bit21 */
			{39648,40,0}, /* core3 elr_EL1 bit22 */
			{39647,40,0}, /* core3 elr_EL1 bit23 */
			{39638,40,0}, /* core3 elr_EL1 bit24 */
			{39637,40,0}, /* core3 elr_EL1 bit25 */
			{39636,40,0}, /* core3 elr_EL1 bit26 */
			{39635,40,0}, /* core3 elr_EL1 bit27 */
			{39634,40,0}, /* core3 elr_EL1 bit28 */
			{39633,40,0}, /* core3 elr_EL1 bit29 */
			{39632,40,0}, /* core3 elr_EL1 bit30 */
			{39631,40,0}, /* core3 elr_EL1 bit31 */
			{36720,40,0}, /* core3 elr_EL1 bit32 */
			{36724,40,0}, /* core3 elr_EL1 bit33 */
			{36723,40,0}, /* core3 elr_EL1 bit34 */
			{36719,40,0}, /* core3 elr_EL1 bit35 */
			{36722,40,0}, /* core3 elr_EL1 bit36 */
			{36721,40,0}, /* core3 elr_EL1 bit37 */
			{36716,40,0}, /* core3 elr_EL1 bit38 */
			{36718,40,0}, /* core3 elr_EL1 bit39 */
			{36715,40,0}, /* core3 elr_EL1 bit40 */
			{36714,40,0}, /* core3 elr_EL1 bit41 */
			{39440,40,0}, /* core3 elr_EL1 bit42 */
			{39439,40,0}, /* core3 elr_EL1 bit43 */
			{39438,40,0}, /* core3 elr_EL1 bit44 */
			{36717,40,0}, /* core3 elr_EL1 bit45 */
			{39437,40,0}, /* core3 elr_EL1 bit46 */
			{39436,40,0}, /* core3 elr_EL1 bit47 */
			{36796,40,0}, /* core3 elr_EL1 bit48 */
			{39435,40,0}, /* core3 elr_EL1 bit49 */
			{36795,40,0}, /* core3 elr_EL1 bit50 */
			{36794,40,0}, /* core3 elr_EL1 bit51 */
			{36793,40,0}, /* core3 elr_EL1 bit52 */
			{36792,40,0}, /* core3 elr_EL1 bit53 */
			{39434,40,0}, /* core3 elr_EL1 bit54 */
			{39433,40,0}, /* core3 elr_EL1 bit55 */
			{36791,40,0}, /* core3 elr_EL1 bit56 */
			{36790,40,0}, /* core3 elr_EL1 bit57 */
			{36789,40,0}, /* core3 elr_EL1 bit58 */
			{34394,40,0}, /* core3 elr_EL1 bit59 */
			{36713,40,0}, /* core3 elr_EL1 bit60 */
			{34393,40,0}, /* core3 elr_EL1 bit61 */
			{34390,40,0}, /* core3 elr_EL1 bit62 */
			{34389,40,0}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{39614,40,0}, /* core3 elr_EL2 bit0 */
			{39613,40,0}, /* core3 elr_EL2 bit1 */
			{39612,40,0}, /* core3 elr_EL2 bit2 */
			{39611,40,0}, /* core3 elr_EL2 bit3 */
			{39610,40,0}, /* core3 elr_EL2 bit4 */
			{39609,40,0}, /* core3 elr_EL2 bit5 */
			{39608,40,0}, /* core3 elr_EL2 bit6 */
			{39607,40,0}, /* core3 elr_EL2 bit7 */
			{39622,40,0}, /* core3 elr_EL2 bit8 */
			{39621,40,0}, /* core3 elr_EL2 bit9 */
			{39620,40,0}, /* core3 elr_EL2 bit10 */
			{39619,40,0}, /* core3 elr_EL2 bit11 */
			{39618,40,0}, /* core3 elr_EL2 bit12 */
			{39617,40,0}, /* core3 elr_EL2 bit13 */
			{39616,40,0}, /* core3 elr_EL2 bit14 */
			{39615,40,0}, /* core3 elr_EL2 bit15 */
			{39646,40,0}, /* core3 elr_EL2 bit16 */
			{39645,40,0}, /* core3 elr_EL2 bit17 */
			{39644,40,0}, /* core3 elr_EL2 bit18 */
			{39643,40,0}, /* core3 elr_EL2 bit19 */
			{39642,40,0}, /* core3 elr_EL2 bit20 */
			{39641,40,0}, /* core3 elr_EL2 bit21 */
			{39640,40,0}, /* core3 elr_EL2 bit22 */
			{39639,40,0}, /* core3 elr_EL2 bit23 */
			{39630,40,0}, /* core3 elr_EL2 bit24 */
			{39629,40,0}, /* core3 elr_EL2 bit25 */
			{39628,40,0}, /* core3 elr_EL2 bit26 */
			{39627,40,0}, /* core3 elr_EL2 bit27 */
			{39626,40,0}, /* core3 elr_EL2 bit28 */
			{39625,40,0}, /* core3 elr_EL2 bit29 */
			{39624,40,0}, /* core3 elr_EL2 bit30 */
			{39623,40,0}, /* core3 elr_EL2 bit31 */
			{39432,40,0}, /* core3 elr_EL2 bit32 */
			{36712,40,0}, /* core3 elr_EL2 bit33 */
			{36711,40,0}, /* core3 elr_EL2 bit34 */
			{39431,40,0}, /* core3 elr_EL2 bit35 */
			{39430,40,0}, /* core3 elr_EL2 bit36 */
			{39429,40,0}, /* core3 elr_EL2 bit37 */
			{36710,40,0}, /* core3 elr_EL2 bit38 */
			{39428,40,0}, /* core3 elr_EL2 bit39 */
			{36709,40,0}, /* core3 elr_EL2 bit40 */
			{36708,40,0}, /* core3 elr_EL2 bit41 */
			{39427,40,0}, /* core3 elr_EL2 bit42 */
			{36707,40,0}, /* core3 elr_EL2 bit43 */
			{36706,40,0}, /* core3 elr_EL2 bit44 */
			{39426,40,0}, /* core3 elr_EL2 bit45 */
			{39425,40,0}, /* core3 elr_EL2 bit46 */
			{36705,40,0}, /* core3 elr_EL2 bit47 */
			{36788,40,0}, /* core3 elr_EL2 bit48 */
			{36787,40,0}, /* core3 elr_EL2 bit49 */
			{36786,40,0}, /* core3 elr_EL2 bit50 */
			{36785,40,0}, /* core3 elr_EL2 bit51 */
			{36784,40,0}, /* core3 elr_EL2 bit52 */
			{36783,40,0}, /* core3 elr_EL2 bit53 */
			{36782,40,0}, /* core3 elr_EL2 bit54 */
			{36781,40,0}, /* core3 elr_EL2 bit55 */
			{36780,40,0}, /* core3 elr_EL2 bit56 */
			{36779,40,0}, /* core3 elr_EL2 bit57 */
			{36778,40,0}, /* core3 elr_EL2 bit58 */
			{36777,40,0}, /* core3 elr_EL2 bit59 */
			{36704,40,0}, /* core3 elr_EL2 bit60 */
			{36703,40,0}, /* core3 elr_EL2 bit61 */
			{36702,40,0}, /* core3 elr_EL2 bit62 */
			{36701,40,0}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{34228,40,0}, /* core3 elr_EL3 bit0 */
			{34227,40,0}, /* core3 elr_EL3 bit1 */
			{40317,41,1}, /* core3 elr_EL3 bit2 */
			{40318,41,1}, /* core3 elr_EL3 bit3 */
			{36912,40,0}, /* core3 elr_EL3 bit4 */
			{36911,40,0}, /* core3 elr_EL3 bit5 */
			{36910,40,0}, /* core3 elr_EL3 bit6 */
			{36909,40,0}, /* core3 elr_EL3 bit7 */
			{34232,40,0}, /* core3 elr_EL3 bit8 */
			{34231,40,0}, /* core3 elr_EL3 bit9 */
			{40339,41,1}, /* core3 elr_EL3 bit10 */
			{40351,41,1}, /* core3 elr_EL3 bit11 */
			{34230,40,0}, /* core3 elr_EL3 bit12 */
			{34229,40,0}, /* core3 elr_EL3 bit13 */
			{40326,41,1}, /* core3 elr_EL3 bit14 */
			{40328,41,1}, /* core3 elr_EL3 bit15 */
			{40352,41,1}, /* core3 elr_EL3 bit16 */
			{40353,41,1}, /* core3 elr_EL3 bit17 */
			{40354,41,1}, /* core3 elr_EL3 bit18 */
			{40344,41,1}, /* core3 elr_EL3 bit19 */
			{40342,41,1}, /* core3 elr_EL3 bit20 */
			{40341,41,1}, /* core3 elr_EL3 bit21 */
			{40327,41,1}, /* core3 elr_EL3 bit22 */
			{40338,41,1}, /* core3 elr_EL3 bit23 */
			{40340,41,1}, /* core3 elr_EL3 bit24 */
			{40343,41,1}, /* core3 elr_EL3 bit25 */
			{40323,41,1}, /* core3 elr_EL3 bit26 */
			{40322,41,1}, /* core3 elr_EL3 bit27 */
			{40324,41,1}, /* core3 elr_EL3 bit28 */
			{40325,41,1}, /* core3 elr_EL3 bit29 */
			{40329,41,1}, /* core3 elr_EL3 bit30 */
			{40337,41,1}, /* core3 elr_EL3 bit31 */
			{34382,40,0}, /* core3 elr_EL3 bit32 */
			{34381,40,0}, /* core3 elr_EL3 bit33 */
			{40368,41,1}, /* core3 elr_EL3 bit34 */
			{40364,41,1}, /* core3 elr_EL3 bit35 */
			{40380,41,1}, /* core3 elr_EL3 bit36 */
			{40372,41,1}, /* core3 elr_EL3 bit37 */
			{40365,41,1}, /* core3 elr_EL3 bit38 */
			{40376,41,1}, /* core3 elr_EL3 bit39 */
			{40369,41,1}, /* core3 elr_EL3 bit40 */
			{40367,41,1}, /* core3 elr_EL3 bit41 */
			{40373,41,1}, /* core3 elr_EL3 bit42 */
			{40371,41,1}, /* core3 elr_EL3 bit43 */
			{40381,41,1}, /* core3 elr_EL3 bit44 */
			{40366,41,1}, /* core3 elr_EL3 bit45 */
			{40370,41,1}, /* core3 elr_EL3 bit46 */
			{40382,41,1}, /* core3 elr_EL3 bit47 */
			{34402,40,0}, /* core3 elr_EL3 bit48 */
			{34401,40,0}, /* core3 elr_EL3 bit49 */
			{36772,40,0}, /* core3 elr_EL3 bit50 */
			{36771,40,0}, /* core3 elr_EL3 bit51 */
			{34414,40,0}, /* core3 elr_EL3 bit52 */
			{36770,40,0}, /* core3 elr_EL3 bit53 */
			{34413,40,0}, /* core3 elr_EL3 bit54 */
			{36769,40,0}, /* core3 elr_EL3 bit55 */
			{36688,40,0}, /* core3 elr_EL3 bit56 */
			{36687,40,0}, /* core3 elr_EL3 bit57 */
			{36686,40,0}, /* core3 elr_EL3 bit58 */
			{36685,40,0}, /* core3 elr_EL3 bit59 */
			{34384,40,0}, /* core3 elr_EL3 bit60 */
			{34383,40,0}, /* core3 elr_EL3 bit61 */
			{34196,40,0}, /* core3 elr_EL3 bit62 */
			{34195,40,0}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{35631,40,0}, /* core3 raw_pc bit0 */
			{35630,40,0}, /* core3 raw_pc bit1 */
			{38290,40,0}, /* core3 raw_pc bit2 */
			{38289,40,0}, /* core3 raw_pc bit3 */
			{38288,40,0}, /* core3 raw_pc bit4 */
			{38287,40,0}, /* core3 raw_pc bit5 */
			{32560,40,1}, /* core3 raw_pc bit6 */
			{38278,40,0}, /* core3 raw_pc bit7 */
			{38277,40,0}, /* core3 raw_pc bit8 */
			{38276,40,0}, /* core3 raw_pc bit9 */
			{38275,40,0}, /* core3 raw_pc bit10 */
			{35637,40,0}, /* core3 raw_pc bit11 */
			{35636,40,0}, /* core3 raw_pc bit12 */
			{35635,40,0}, /* core3 raw_pc bit13 */
			{35634,40,0}, /* core3 raw_pc bit14 */
			{38282,40,0}, /* core3 raw_pc bit15 */
			{38281,40,0}, /* core3 raw_pc bit16 */
			{38280,40,0}, /* core3 raw_pc bit17 */
			{38279,40,0}, /* core3 raw_pc bit18 */
			{35641,40,0}, /* core3 raw_pc bit19 */
			{35640,40,0}, /* core3 raw_pc bit20 */
			{32562,40,1}, /* core3 raw_pc bit21 */
			{32561,40,1}, /* core3 raw_pc bit22 */
			{38286,40,0}, /* core3 raw_pc bit23 */
			{38285,40,0}, /* core3 raw_pc bit24 */
			{38284,40,0}, /* core3 raw_pc bit25 */
			{38283,40,0}, /* core3 raw_pc bit26 */
			{35633,40,0}, /* core3 raw_pc bit27 */
			{35632,40,0}, /* core3 raw_pc bit28 */
			{35639,40,0}, /* core3 raw_pc bit29 */
			{35638,40,0}, /* core3 raw_pc bit30 */
			{38274,40,0}, /* core3 raw_pc bit31 */
			{38273,40,0}, /* core3 raw_pc bit32 */
			{38272,40,0}, /* core3 raw_pc bit33 */
			{38271,40,0}, /* core3 raw_pc bit34 */
			{40754,40,0}, /* core3 raw_pc bit35 */
			{40753,40,0}, /* core3 raw_pc bit36 */
			{40752,40,0}, /* core3 raw_pc bit37 */
			{40751,40,0}, /* core3 raw_pc bit38 */
			{35645,40,0}, /* core3 raw_pc bit39 */
			{35644,40,0}, /* core3 raw_pc bit40 */
			{40750,40,0}, /* core3 raw_pc bit41 */
			{40749,40,0}, /* core3 raw_pc bit42 */
			{35647,40,0}, /* core3 raw_pc bit43 */
			{35646,40,0}, /* core3 raw_pc bit44 */
			{40748,40,0}, /* core3 raw_pc bit45 */
			{40747,40,0}, /* core3 raw_pc bit46 */
			{32577,40,1}, /* core3 raw_pc bit47 */
			{32578,40,1}, /* core3 raw_pc bit48 */
			{32579,40,1}, /* core3 raw_pc bit49 */
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
			{32555,40,1}, /* core3 pc_iss bit0 */
			{32637,40,1}, /* core3 pc_iss bit1 */
			{32634,40,1}, /* core3 pc_iss bit2 */
			{32633,40,1}, /* core3 pc_iss bit3 */
			{32635,40,1}, /* core3 pc_iss bit4 */
			{32554,40,1}, /* core3 pc_iss bit5 */
			{32556,40,1}, /* core3 pc_iss bit6 */
			{32636,40,1}, /* core3 pc_iss bit7 */
			{32610,40,1}, /* core3 pc_iss bit8 */
			{32603,40,1}, /* core3 pc_iss bit9 */
			{32632,40,1}, /* core3 pc_iss bit10 */
			{32631,40,1}, /* core3 pc_iss bit11 */
			{32629,40,1}, /* core3 pc_iss bit12 */
			{32630,40,1}, /* core3 pc_iss bit13 */
			{32628,40,1}, /* core3 pc_iss bit14 */
			{32614,40,1}, /* core3 pc_iss bit15 */
			{32615,40,1}, /* core3 pc_iss bit16 */
			{32627,40,1}, /* core3 pc_iss bit17 */
			{32624,40,1}, /* core3 pc_iss bit18 */
			{32617,40,1}, /* core3 pc_iss bit19 */
			{32625,40,1}, /* core3 pc_iss bit20 */
			{32626,40,1}, /* core3 pc_iss bit21 */
			{32611,40,1}, /* core3 pc_iss bit22 */
			{32618,40,1}, /* core3 pc_iss bit23 */
			{32622,40,1}, /* core3 pc_iss bit24 */
			{32621,40,1}, /* core3 pc_iss bit25 */
			{32619,40,1}, /* core3 pc_iss bit26 */
			{32612,40,1}, /* core3 pc_iss bit27 */
			{32613,40,1}, /* core3 pc_iss bit28 */
			{32620,40,1}, /* core3 pc_iss bit29 */
			{32616,40,1}, /* core3 pc_iss bit30 */
			{32623,40,1}, /* core3 pc_iss bit31 */
			{32573,40,1}, /* core3 pc_iss bit32 */
			{32574,40,1}, /* core3 pc_iss bit33 */
			{32563,40,1}, /* core3 pc_iss bit34 */
			{32564,40,1}, /* core3 pc_iss bit35 */
			{32570,40,1}, /* core3 pc_iss bit36 */
			{32566,40,1}, /* core3 pc_iss bit37 */
			{32571,40,1}, /* core3 pc_iss bit38 */
			{32565,40,1}, /* core3 pc_iss bit39 */
			{32572,40,1}, /* core3 pc_iss bit40 */
			{32568,40,1}, /* core3 pc_iss bit41 */
			{32567,40,1}, /* core3 pc_iss bit42 */
			{32569,40,1}, /* core3 pc_iss bit43 */
			{35685,40,0}, /* core3 pc_iss bit44 */
			{35684,40,0}, /* core3 pc_iss bit45 */
			{35683,40,0}, /* core3 pc_iss bit46 */
			{35682,40,0}, /* core3 pc_iss bit47 */
			{38270,40,0}, /* core3 pc_iss bit48 */
			{38269,40,0}, /* core3 pc_iss bit49 */
			{38268,40,0}, /* core3 pc_iss bit50 */
			{38267,40,0}, /* core3 pc_iss bit51 */
			{38266,40,0}, /* core3 pc_iss bit52 */
			{38265,40,0}, /* core3 pc_iss bit53 */
			{38264,40,0}, /* core3 pc_iss bit54 */
			{38263,40,0}, /* core3 pc_iss bit55 */
			{40956,40,0}, /* core3 pc_iss bit56 */
			{40955,40,0}, /* core3 pc_iss bit57 */
			{40954,40,0}, /* core3 pc_iss bit58 */
			{40953,40,0}, /* core3 pc_iss bit59 */
			{40952,40,0}, /* core3 pc_iss bit60 */
			{40951,40,0}, /* core3 pc_iss bit61 */
			{40950,40,0}, /* core3 pc_iss bit62 */
			{40949,40,0}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{32557,40,1}, /* core3 full_pc_wr bit0 */
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
			{41124,40,0}, /* core3 full_pc_ex1 bit0 */
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
			{41116,40,0}, /* core3 full_pc_ex2 bit0 */
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
			{25953,41,1}, /* core3 return_Stack_pointer bit0 */
			{28673,41,1}, /* core3 return_Stack_pointer bit1 */
			{28674,41,1}, /* core3 return_Stack_pointer bit2 */
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
			{32644,41,1}, /* core3 return_Stack0 bit0 */
			{32643,41,1}, /* core3 return_Stack0 bit1 */
			{32672,41,1}, /* core3 return_Stack0 bit2 */
			{32671,41,1}, /* core3 return_Stack0 bit3 */
			{32670,41,1}, /* core3 return_Stack0 bit4 */
			{32669,41,1}, /* core3 return_Stack0 bit5 */
			{28860,41,1}, /* core3 return_Stack0 bit6 */
			{28859,41,1}, /* core3 return_Stack0 bit7 */
			{28858,41,1}, /* core3 return_Stack0 bit8 */
			{28857,41,1}, /* core3 return_Stack0 bit9 */
			{37875,41,1}, /* core3 return_Stack0 bit10 */
			{37874,41,1}, /* core3 return_Stack0 bit11 */
			{37873,41,1}, /* core3 return_Stack0 bit12 */
			{37872,41,1}, /* core3 return_Stack0 bit13 */
			{37871,41,1}, /* core3 return_Stack0 bit14 */
			{37870,41,1}, /* core3 return_Stack0 bit15 */
			{37869,41,1}, /* core3 return_Stack0 bit16 */
			{32642,41,1}, /* core3 return_Stack0 bit17 */
			{37868,41,1}, /* core3 return_Stack0 bit18 */
			{32648,41,1}, /* core3 return_Stack0 bit19 */
			{32647,41,1}, /* core3 return_Stack0 bit20 */
			{32646,41,1}, /* core3 return_Stack0 bit21 */
			{32645,41,1}, /* core3 return_Stack0 bit22 */
			{32641,41,1}, /* core3 return_Stack0 bit23 */
			{26154,41,1}, /* core3 return_Stack0 bit24 */
			{26153,41,1}, /* core3 return_Stack0 bit25 */
			{28780,41,1}, /* core3 return_Stack0 bit26 */
			{28779,41,1}, /* core3 return_Stack0 bit27 */
			{32656,41,1}, /* core3 return_Stack0 bit28 */
			{32655,41,1}, /* core3 return_Stack0 bit29 */
			{32654,41,1}, /* core3 return_Stack0 bit30 */
			{26152,41,1}, /* core3 return_Stack0 bit31 */
			{32653,41,1}, /* core3 return_Stack0 bit32 */
			{28770,41,1}, /* core3 return_Stack0 bit33 */
			{28769,41,1}, /* core3 return_Stack0 bit34 */
			{25973,41,1}, /* core3 return_Stack0 bit35 */
			{28772,41,1}, /* core3 return_Stack0 bit36 */
			{28771,41,1}, /* core3 return_Stack0 bit37 */
			{32832,41,1}, /* core3 return_Stack0 bit38 */
			{32831,41,1}, /* core3 return_Stack0 bit39 */
			{32830,41,1}, /* core3 return_Stack0 bit40 */
			{32829,41,1}, /* core3 return_Stack0 bit41 */
			{25972,41,1}, /* core3 return_Stack0 bit42 */
			{28774,41,1}, /* core3 return_Stack0 bit43 */
			{28773,41,1}, /* core3 return_Stack0 bit44 */
			{28776,41,1}, /* core3 return_Stack0 bit45 */
			{28775,41,1}, /* core3 return_Stack0 bit46 */
			{28778,41,1}, /* core3 return_Stack0 bit47 */
			{28777,41,1}, /* core3 return_Stack0 bit48 */
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
			{28812,41,1}, /* core3 return_Stack1 bit0 */
			{28811,41,1}, /* core3 return_Stack1 bit1 */
			{32716,41,1}, /* core3 return_Stack1 bit2 */
			{32715,41,1}, /* core3 return_Stack1 bit3 */
			{32720,41,1}, /* core3 return_Stack1 bit4 */
			{32719,41,1}, /* core3 return_Stack1 bit5 */
			{32718,41,1}, /* core3 return_Stack1 bit6 */
			{32717,41,1}, /* core3 return_Stack1 bit7 */
			{28818,41,1}, /* core3 return_Stack1 bit8 */
			{28817,41,1}, /* core3 return_Stack1 bit9 */
			{32714,41,1}, /* core3 return_Stack1 bit10 */
			{32713,41,1}, /* core3 return_Stack1 bit11 */
			{32724,41,1}, /* core3 return_Stack1 bit12 */
			{32723,41,1}, /* core3 return_Stack1 bit13 */
			{32722,41,1}, /* core3 return_Stack1 bit14 */
			{32721,41,1}, /* core3 return_Stack1 bit15 */
			{28820,41,1}, /* core3 return_Stack1 bit16 */
			{28819,41,1}, /* core3 return_Stack1 bit17 */
			{28816,41,1}, /* core3 return_Stack1 bit18 */
			{28815,41,1}, /* core3 return_Stack1 bit19 */
			{28814,41,1}, /* core3 return_Stack1 bit20 */
			{28813,41,1}, /* core3 return_Stack1 bit21 */
			{26163,41,1}, /* core3 return_Stack1 bit22 */
			{26165,41,1}, /* core3 return_Stack1 bit23 */
			{26164,41,1}, /* core3 return_Stack1 bit24 */
			{32736,41,1}, /* core3 return_Stack1 bit25 */
			{32735,41,1}, /* core3 return_Stack1 bit26 */
			{32734,41,1}, /* core3 return_Stack1 bit27 */
			{32733,41,1}, /* core3 return_Stack1 bit28 */
			{28810,41,1}, /* core3 return_Stack1 bit29 */
			{28809,41,1}, /* core3 return_Stack1 bit30 */
			{26166,41,1}, /* core3 return_Stack1 bit31 */
			{28808,41,1}, /* core3 return_Stack1 bit32 */
			{28806,41,1}, /* core3 return_Stack1 bit33 */
			{28805,41,1}, /* core3 return_Stack1 bit34 */
			{28807,41,1}, /* core3 return_Stack1 bit35 */
			{26167,41,1}, /* core3 return_Stack1 bit36 */
			{32784,41,1}, /* core3 return_Stack1 bit37 */
			{32783,41,1}, /* core3 return_Stack1 bit38 */
			{32782,41,1}, /* core3 return_Stack1 bit39 */
			{32781,41,1}, /* core3 return_Stack1 bit40 */
			{32788,41,1}, /* core3 return_Stack1 bit41 */
			{32787,41,1}, /* core3 return_Stack1 bit42 */
			{32786,41,1}, /* core3 return_Stack1 bit43 */
			{32785,41,1}, /* core3 return_Stack1 bit44 */
			{32792,41,1}, /* core3 return_Stack1 bit45 */
			{32791,41,1}, /* core3 return_Stack1 bit46 */
			{32790,41,1}, /* core3 return_Stack1 bit47 */
			{32789,41,1}, /* core3 return_Stack1 bit48 */
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
			{28856,41,1}, /* core3 return_Stack2 bit0 */
			{28855,41,1}, /* core3 return_Stack2 bit1 */
			{28854,41,1}, /* core3 return_Stack2 bit2 */
			{28853,41,1}, /* core3 return_Stack2 bit3 */
			{32676,41,1}, /* core3 return_Stack2 bit4 */
			{32675,41,1}, /* core3 return_Stack2 bit5 */
			{32674,41,1}, /* core3 return_Stack2 bit6 */
			{32673,41,1}, /* core3 return_Stack2 bit7 */
			{32680,41,1}, /* core3 return_Stack2 bit8 */
			{32679,41,1}, /* core3 return_Stack2 bit9 */
			{32678,41,1}, /* core3 return_Stack2 bit10 */
			{32677,41,1}, /* core3 return_Stack2 bit11 */
			{28846,41,1}, /* core3 return_Stack2 bit12 */
			{28845,41,1}, /* core3 return_Stack2 bit13 */
			{28848,41,1}, /* core3 return_Stack2 bit14 */
			{28847,41,1}, /* core3 return_Stack2 bit15 */
			{28852,41,1}, /* core3 return_Stack2 bit16 */
			{28851,41,1}, /* core3 return_Stack2 bit17 */
			{28844,41,1}, /* core3 return_Stack2 bit18 */
			{28843,41,1}, /* core3 return_Stack2 bit19 */
			{28850,41,1}, /* core3 return_Stack2 bit20 */
			{28849,41,1}, /* core3 return_Stack2 bit21 */
			{26155,41,1}, /* core3 return_Stack2 bit22 */
			{26156,41,1}, /* core3 return_Stack2 bit23 */
			{26157,41,1}, /* core3 return_Stack2 bit24 */
			{32652,41,1}, /* core3 return_Stack2 bit25 */
			{32651,41,1}, /* core3 return_Stack2 bit26 */
			{32650,41,1}, /* core3 return_Stack2 bit27 */
			{32649,41,1}, /* core3 return_Stack2 bit28 */
			{32756,41,1}, /* core3 return_Stack2 bit29 */
			{32755,41,1}, /* core3 return_Stack2 bit30 */
			{32754,41,1}, /* core3 return_Stack2 bit31 */
			{32753,41,1}, /* core3 return_Stack2 bit32 */
			{32824,41,1}, /* core3 return_Stack2 bit33 */
			{32823,41,1}, /* core3 return_Stack2 bit34 */
			{32822,41,1}, /* core3 return_Stack2 bit35 */
			{32821,41,1}, /* core3 return_Stack2 bit36 */
			{32820,41,1}, /* core3 return_Stack2 bit37 */
			{32819,41,1}, /* core3 return_Stack2 bit38 */
			{32818,41,1}, /* core3 return_Stack2 bit39 */
			{32817,41,1}, /* core3 return_Stack2 bit40 */
			{32828,41,1}, /* core3 return_Stack2 bit41 */
			{32827,41,1}, /* core3 return_Stack2 bit42 */
			{32826,41,1}, /* core3 return_Stack2 bit43 */
			{32825,41,1}, /* core3 return_Stack2 bit44 */
			{32760,41,1}, /* core3 return_Stack2 bit45 */
			{32759,41,1}, /* core3 return_Stack2 bit46 */
			{32758,41,1}, /* core3 return_Stack2 bit47 */
			{32757,41,1}, /* core3 return_Stack2 bit48 */
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
			{28802,41,1}, /* core3 return_Stack3 bit0 */
			{28801,41,1}, /* core3 return_Stack3 bit1 */
			{28824,41,1}, /* core3 return_Stack3 bit2 */
			{28826,41,1}, /* core3 return_Stack3 bit3 */
			{28825,41,1}, /* core3 return_Stack3 bit4 */
			{28822,41,1}, /* core3 return_Stack3 bit5 */
			{28821,41,1}, /* core3 return_Stack3 bit6 */
			{28796,41,1}, /* core3 return_Stack3 bit7 */
			{28795,41,1}, /* core3 return_Stack3 bit8 */
			{28823,41,1}, /* core3 return_Stack3 bit9 */
			{28798,41,1}, /* core3 return_Stack3 bit10 */
			{28830,41,1}, /* core3 return_Stack3 bit11 */
			{28829,41,1}, /* core3 return_Stack3 bit12 */
			{28828,41,1}, /* core3 return_Stack3 bit13 */
			{28827,41,1}, /* core3 return_Stack3 bit14 */
			{32708,41,1}, /* core3 return_Stack3 bit15 */
			{28800,41,1}, /* core3 return_Stack3 bit16 */
			{28799,41,1}, /* core3 return_Stack3 bit17 */
			{32707,41,1}, /* core3 return_Stack3 bit18 */
			{32706,41,1}, /* core3 return_Stack3 bit19 */
			{32705,41,1}, /* core3 return_Stack3 bit20 */
			{28797,41,1}, /* core3 return_Stack3 bit21 */
			{26158,41,1}, /* core3 return_Stack3 bit22 */
			{26162,41,1}, /* core3 return_Stack3 bit23 */
			{26159,41,1}, /* core3 return_Stack3 bit24 */
			{26160,41,1}, /* core3 return_Stack3 bit25 */
			{32744,41,1}, /* core3 return_Stack3 bit26 */
			{32743,41,1}, /* core3 return_Stack3 bit27 */
			{32742,41,1}, /* core3 return_Stack3 bit28 */
			{32796,41,1}, /* core3 return_Stack3 bit29 */
			{32741,41,1}, /* core3 return_Stack3 bit30 */
			{32795,41,1}, /* core3 return_Stack3 bit31 */
			{28804,41,1}, /* core3 return_Stack3 bit32 */
			{32794,41,1}, /* core3 return_Stack3 bit33 */
			{32793,41,1}, /* core3 return_Stack3 bit34 */
			{28803,41,1}, /* core3 return_Stack3 bit35 */
			{32776,41,1}, /* core3 return_Stack3 bit36 */
			{32775,41,1}, /* core3 return_Stack3 bit37 */
			{32774,41,1}, /* core3 return_Stack3 bit38 */
			{32780,41,1}, /* core3 return_Stack3 bit39 */
			{32779,41,1}, /* core3 return_Stack3 bit40 */
			{32778,41,1}, /* core3 return_Stack3 bit41 */
			{32777,41,1}, /* core3 return_Stack3 bit42 */
			{32800,41,1}, /* core3 return_Stack3 bit43 */
			{32799,41,1}, /* core3 return_Stack3 bit44 */
			{32798,41,1}, /* core3 return_Stack3 bit45 */
			{32797,41,1}, /* core3 return_Stack3 bit46 */
			{32773,41,1}, /* core3 return_Stack3 bit47 */
			{26161,41,1}, /* core3 return_Stack3 bit48 */
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
			{32664,41,1}, /* core3 return_Stack4 bit0 */
			{32663,41,1}, /* core3 return_Stack4 bit1 */
			{32636,41,1}, /* core3 return_Stack4 bit2 */
			{32635,41,1}, /* core3 return_Stack4 bit3 */
			{28864,41,1}, /* core3 return_Stack4 bit4 */
			{28863,41,1}, /* core3 return_Stack4 bit5 */
			{32640,41,1}, /* core3 return_Stack4 bit6 */
			{32639,41,1}, /* core3 return_Stack4 bit7 */
			{32638,41,1}, /* core3 return_Stack4 bit8 */
			{32637,41,1}, /* core3 return_Stack4 bit9 */
			{32634,41,1}, /* core3 return_Stack4 bit10 */
			{32633,41,1}, /* core3 return_Stack4 bit11 */
			{28862,41,1}, /* core3 return_Stack4 bit12 */
			{28861,41,1}, /* core3 return_Stack4 bit13 */
			{32668,41,1}, /* core3 return_Stack4 bit14 */
			{32667,41,1}, /* core3 return_Stack4 bit15 */
			{32662,41,1}, /* core3 return_Stack4 bit16 */
			{32661,41,1}, /* core3 return_Stack4 bit17 */
			{32666,41,1}, /* core3 return_Stack4 bit18 */
			{32665,41,1}, /* core3 return_Stack4 bit19 */
			{28866,41,1}, /* core3 return_Stack4 bit20 */
			{28865,41,1}, /* core3 return_Stack4 bit21 */
			{28868,41,1}, /* core3 return_Stack4 bit22 */
			{28867,41,1}, /* core3 return_Stack4 bit23 */
			{26150,41,1}, /* core3 return_Stack4 bit24 */
			{26151,41,1}, /* core3 return_Stack4 bit25 */
			{32660,41,1}, /* core3 return_Stack4 bit26 */
			{32659,41,1}, /* core3 return_Stack4 bit27 */
			{32658,41,1}, /* core3 return_Stack4 bit28 */
			{32844,41,1}, /* core3 return_Stack4 bit29 */
			{32843,41,1}, /* core3 return_Stack4 bit30 */
			{32842,41,1}, /* core3 return_Stack4 bit31 */
			{32657,41,1}, /* core3 return_Stack4 bit32 */
			{25971,41,1}, /* core3 return_Stack4 bit33 */
			{32841,41,1}, /* core3 return_Stack4 bit34 */
			{32840,41,1}, /* core3 return_Stack4 bit35 */
			{32839,41,1}, /* core3 return_Stack4 bit36 */
			{32838,41,1}, /* core3 return_Stack4 bit37 */
			{32837,41,1}, /* core3 return_Stack4 bit38 */
			{32836,41,1}, /* core3 return_Stack4 bit39 */
			{32835,41,1}, /* core3 return_Stack4 bit40 */
			{32834,41,1}, /* core3 return_Stack4 bit41 */
			{32833,41,1}, /* core3 return_Stack4 bit42 */
			{25970,41,1}, /* core3 return_Stack4 bit43 */
			{28872,41,1}, /* core3 return_Stack4 bit44 */
			{28871,41,1}, /* core3 return_Stack4 bit45 */
			{28870,41,1}, /* core3 return_Stack4 bit46 */
			{28869,41,1}, /* core3 return_Stack4 bit47 */
			{25969,41,1}, /* core3 return_Stack4 bit48 */
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
			{28790,41,1}, /* core3 return_Stack5 bit0 */
			{28789,41,1}, /* core3 return_Stack5 bit1 */
			{32696,41,1}, /* core3 return_Stack5 bit2 */
			{32695,41,1}, /* core3 return_Stack5 bit3 */
			{28794,41,1}, /* core3 return_Stack5 bit4 */
			{28793,41,1}, /* core3 return_Stack5 bit5 */
			{32692,41,1}, /* core3 return_Stack5 bit6 */
			{32691,41,1}, /* core3 return_Stack5 bit7 */
			{32690,41,1}, /* core3 return_Stack5 bit8 */
			{32689,41,1}, /* core3 return_Stack5 bit9 */
			{32694,41,1}, /* core3 return_Stack5 bit10 */
			{32693,41,1}, /* core3 return_Stack5 bit11 */
			{32700,41,1}, /* core3 return_Stack5 bit12 */
			{32699,41,1}, /* core3 return_Stack5 bit13 */
			{28792,41,1}, /* core3 return_Stack5 bit14 */
			{28791,41,1}, /* core3 return_Stack5 bit15 */
			{28788,41,1}, /* core3 return_Stack5 bit16 */
			{28787,41,1}, /* core3 return_Stack5 bit17 */
			{32698,41,1}, /* core3 return_Stack5 bit18 */
			{32704,41,1}, /* core3 return_Stack5 bit19 */
			{32703,41,1}, /* core3 return_Stack5 bit20 */
			{32702,41,1}, /* core3 return_Stack5 bit21 */
			{32697,41,1}, /* core3 return_Stack5 bit22 */
			{28786,41,1}, /* core3 return_Stack5 bit23 */
			{32701,41,1}, /* core3 return_Stack5 bit24 */
			{28785,41,1}, /* core3 return_Stack5 bit25 */
			{32752,41,1}, /* core3 return_Stack5 bit26 */
			{25968,41,1}, /* core3 return_Stack5 bit27 */
			{32751,41,1}, /* core3 return_Stack5 bit28 */
			{32750,41,1}, /* core3 return_Stack5 bit29 */
			{32749,41,1}, /* core3 return_Stack5 bit30 */
			{32808,41,1}, /* core3 return_Stack5 bit31 */
			{32807,41,1}, /* core3 return_Stack5 bit32 */
			{32806,41,1}, /* core3 return_Stack5 bit33 */
			{32805,41,1}, /* core3 return_Stack5 bit34 */
			{32812,41,1}, /* core3 return_Stack5 bit35 */
			{32811,41,1}, /* core3 return_Stack5 bit36 */
			{32810,41,1}, /* core3 return_Stack5 bit37 */
			{32809,41,1}, /* core3 return_Stack5 bit38 */
			{32804,41,1}, /* core3 return_Stack5 bit39 */
			{32803,41,1}, /* core3 return_Stack5 bit40 */
			{32802,41,1}, /* core3 return_Stack5 bit41 */
			{32801,41,1}, /* core3 return_Stack5 bit42 */
			{32816,41,1}, /* core3 return_Stack5 bit43 */
			{32815,41,1}, /* core3 return_Stack5 bit44 */
			{32814,41,1}, /* core3 return_Stack5 bit45 */
			{32813,41,1}, /* core3 return_Stack5 bit46 */
			{25955,41,1}, /* core3 return_Stack5 bit47 */
			{25956,41,1}, /* core3 return_Stack5 bit48 */
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
			{28784,41,1}, /* core3 return_Stack6 bit0 */
			{28783,41,1}, /* core3 return_Stack6 bit1 */
			{28838,41,1}, /* core3 return_Stack6 bit2 */
			{32688,41,1}, /* core3 return_Stack6 bit3 */
			{28837,41,1}, /* core3 return_Stack6 bit4 */
			{32687,41,1}, /* core3 return_Stack6 bit5 */
			{32686,41,1}, /* core3 return_Stack6 bit6 */
			{32685,41,1}, /* core3 return_Stack6 bit7 */
			{28834,41,1}, /* core3 return_Stack6 bit8 */
			{28833,41,1}, /* core3 return_Stack6 bit9 */
			{32684,41,1}, /* core3 return_Stack6 bit10 */
			{32683,41,1}, /* core3 return_Stack6 bit11 */
			{32682,41,1}, /* core3 return_Stack6 bit12 */
			{32681,41,1}, /* core3 return_Stack6 bit13 */
			{28840,41,1}, /* core3 return_Stack6 bit14 */
			{28839,41,1}, /* core3 return_Stack6 bit15 */
			{28836,41,1}, /* core3 return_Stack6 bit16 */
			{28835,41,1}, /* core3 return_Stack6 bit17 */
			{28842,41,1}, /* core3 return_Stack6 bit18 */
			{28841,41,1}, /* core3 return_Stack6 bit19 */
			{28832,41,1}, /* core3 return_Stack6 bit20 */
			{28831,41,1}, /* core3 return_Stack6 bit21 */
			{25960,41,1}, /* core3 return_Stack6 bit22 */
			{25959,41,1}, /* core3 return_Stack6 bit23 */
			{25967,41,1}, /* core3 return_Stack6 bit24 */
			{25966,41,1}, /* core3 return_Stack6 bit25 */
			{32748,41,1}, /* core3 return_Stack6 bit26 */
			{32747,41,1}, /* core3 return_Stack6 bit27 */
			{28782,41,1}, /* core3 return_Stack6 bit28 */
			{32746,41,1}, /* core3 return_Stack6 bit29 */
			{32745,41,1}, /* core3 return_Stack6 bit30 */
			{28781,41,1}, /* core3 return_Stack6 bit31 */
			{25958,41,1}, /* core3 return_Stack6 bit32 */
			{28680,41,1}, /* core3 return_Stack6 bit33 */
			{28679,41,1}, /* core3 return_Stack6 bit34 */
			{25954,41,1}, /* core3 return_Stack6 bit35 */
			{25957,41,1}, /* core3 return_Stack6 bit36 */
			{28678,41,1}, /* core3 return_Stack6 bit37 */
			{28677,41,1}, /* core3 return_Stack6 bit38 */
			{32764,41,1}, /* core3 return_Stack6 bit39 */
			{32763,41,1}, /* core3 return_Stack6 bit40 */
			{32762,41,1}, /* core3 return_Stack6 bit41 */
			{32761,41,1}, /* core3 return_Stack6 bit42 */
			{28676,41,1}, /* core3 return_Stack6 bit43 */
			{28675,41,1}, /* core3 return_Stack6 bit44 */
			{28664,41,1}, /* core3 return_Stack6 bit45 */
			{28663,41,1}, /* core3 return_Stack6 bit46 */
			{28662,41,1}, /* core3 return_Stack6 bit47 */
			{28661,41,1}, /* core3 return_Stack6 bit48 */
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
			{32712,41,1}, /* core3 return_Stack7 bit0 */
			{32711,41,1}, /* core3 return_Stack7 bit1 */
			{32732,41,1}, /* core3 return_Stack7 bit2 */
			{32731,41,1}, /* core3 return_Stack7 bit3 */
			{32730,41,1}, /* core3 return_Stack7 bit4 */
			{32729,41,1}, /* core3 return_Stack7 bit5 */
			{28652,41,1}, /* core3 return_Stack7 bit6 */
			{28651,41,1}, /* core3 return_Stack7 bit7 */
			{28654,41,1}, /* core3 return_Stack7 bit8 */
			{28653,41,1}, /* core3 return_Stack7 bit9 */
			{32728,41,1}, /* core3 return_Stack7 bit10 */
			{32727,41,1}, /* core3 return_Stack7 bit11 */
			{28650,41,1}, /* core3 return_Stack7 bit12 */
			{28649,41,1}, /* core3 return_Stack7 bit13 */
			{32710,41,1}, /* core3 return_Stack7 bit14 */
			{32726,41,1}, /* core3 return_Stack7 bit15 */
			{32709,41,1}, /* core3 return_Stack7 bit16 */
			{32725,41,1}, /* core3 return_Stack7 bit17 */
			{28656,41,1}, /* core3 return_Stack7 bit18 */
			{28655,41,1}, /* core3 return_Stack7 bit19 */
			{28658,41,1}, /* core3 return_Stack7 bit20 */
			{28657,41,1}, /* core3 return_Stack7 bit21 */
			{25961,41,1}, /* core3 return_Stack7 bit22 */
			{25962,41,1}, /* core3 return_Stack7 bit23 */
			{25963,41,1}, /* core3 return_Stack7 bit24 */
			{25965,41,1}, /* core3 return_Stack7 bit25 */
			{28660,41,1}, /* core3 return_Stack7 bit26 */
			{32740,41,1}, /* core3 return_Stack7 bit27 */
			{28659,41,1}, /* core3 return_Stack7 bit28 */
			{32739,41,1}, /* core3 return_Stack7 bit29 */
			{32738,41,1}, /* core3 return_Stack7 bit30 */
			{32737,41,1}, /* core3 return_Stack7 bit31 */
			{32768,41,1}, /* core3 return_Stack7 bit32 */
			{32767,41,1}, /* core3 return_Stack7 bit33 */
			{32766,41,1}, /* core3 return_Stack7 bit34 */
			{32765,41,1}, /* core3 return_Stack7 bit35 */
			{28670,41,1}, /* core3 return_Stack7 bit36 */
			{28669,41,1}, /* core3 return_Stack7 bit37 */
			{28672,41,1}, /* core3 return_Stack7 bit38 */
			{28671,41,1}, /* core3 return_Stack7 bit39 */
			{32772,41,1}, /* core3 return_Stack7 bit40 */
			{32771,41,1}, /* core3 return_Stack7 bit41 */
			{32770,41,1}, /* core3 return_Stack7 bit42 */
			{32769,41,1}, /* core3 return_Stack7 bit43 */
			{28666,41,1}, /* core3 return_Stack7 bit44 */
			{28665,41,1}, /* core3 return_Stack7 bit45 */
			{28668,41,1}, /* core3 return_Stack7 bit46 */
			{28667,41,1}, /* core3 return_Stack7 bit47 */
			{25964,41,1}, /* core3 return_Stack7 bit48 */
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
			{ 5023, 8,0}, /* core3 L2_parity_err_count bit0 */
			{ 5155, 8,0}, /* core3 L2_parity_err_count bit1 */
			{ 5020, 8,0}, /* core3 L2_parity_err_count bit2 */
			{ 5024, 8,0}, /* core3 L2_parity_err_count bit3 */
			{ 5154, 8,0}, /* core3 L2_parity_err_count bit4 */
			{ 5019, 8,0}, /* core3 L2_parity_err_count bit5 */
			{ 5017, 8,0}, /* core3 L2_parity_err_count bit6 */
			{ 5028, 8,0}, /* core3 L2_parity_err_count bit7 */
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
			{ 5676, 8,0}, /* core3 L2_parity_index bit0 */
			{ 5675, 8,0}, /* core3 L2_parity_index bit1 */
			{ 5674, 8,0}, /* core3 L2_parity_index bit2 */
			{ 5673, 8,0}, /* core3 L2_parity_index bit3 */
			{ 5672, 8,0}, /* core3 L2_parity_index bit4 */
			{ 5671, 8,0}, /* core3 L2_parity_index bit5 */
			{ 5670, 8,0}, /* core3 L2_parity_index bit6 */
			{ 5669, 8,0}, /* core3 L2_parity_index bit7 */
			{ 5684, 8,0}, /* core3 L2_parity_index bit8 */
			{ 5683, 8,0}, /* core3 L2_parity_index bit9 */
			{ 5682, 8,0}, /* core3 L2_parity_index bit10 */
			{ 5681, 8,0}, /* core3 L2_parity_index bit11 */
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
			{ 5677, 8,0}, /* core3 L2_parity_way bit0 */
			{ 5159, 8,0}, /* core3 L2_parity_way bit1 */
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
			{ 5029, 8,0}, /* core3 L2_parity_banks bit0 */
			{ 5756, 8,0}, /* core3 L2_parity_banks bit1 */
			{ 5018, 8,0}, /* core3 L2_parity_banks bit2 */
			{ 5755, 8,0}, /* core3 L2_parity_banks bit3 */
			{ 5030, 8,0}, /* core3 L2_parity_banks bit4 */
			{ 5754, 8,0}, /* core3 L2_parity_banks bit5 */
			{ 5027, 8,0}, /* core3 L2_parity_banks bit6 */
			{ 5753, 8,0}, /* core3 L2_parity_banks bit7 */
			{ 5026, 8,0}, /* core3 L2_parity_banks bit8 */
			{ 5025, 8,0}, /* core3 L2_parity_banks bit9 */
			{ 5752, 8,0}, /* core3 L2_parity_banks bit10 */
			{ 5751, 8,0}, /* core3 L2_parity_banks bit11 */
			{ 5750, 8,0}, /* core3 L2_parity_banks bit12 */
			{ 5749, 8,0}, /* core3 L2_parity_banks bit13 */
			{ 5021, 8,0}, /* core3 L2_parity_banks bit14 */
			{ 5022, 8,0}, /* core3 L2_parity_banks bit15 */
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
			{   95,42,1}, /* core4 pc bit0 */
			{  433,42,1}, /* core4 pc bit1 */
			{  432,42,1}, /* core4 pc bit2 */
			{  431,42,1}, /* core4 pc bit3 */
			{  430,42,1}, /* core4 pc bit4 */
			{  429,42,1}, /* core4 pc bit5 */
			{  495,42,1}, /* core4 pc bit6 */
			{  426,42,1}, /* core4 pc bit7 */
			{  494,42,1}, /* core4 pc bit8 */
			{  425,42,1}, /* core4 pc bit9 */
			{  424,42,1}, /* core4 pc bit10 */
			{  445,42,1}, /* core4 pc bit11 */
			{  493,42,1}, /* core4 pc bit12 */
			{  492,42,1}, /* core4 pc bit13 */
			{  444,42,1}, /* core4 pc bit14 */
			{  443,42,1}, /* core4 pc bit15 */
			{  466,42,1}, /* core4 pc bit16 */
			{  482,42,1}, /* core4 pc bit17 */
			{  465,42,1}, /* core4 pc bit18 */
			{  464,42,1}, /* core4 pc bit19 */
			{  470,42,1}, /* core4 pc bit20 */
			{  463,42,1}, /* core4 pc bit21 */
			{  440,42,1}, /* core4 pc bit22 */
			{  446,42,1}, /* core4 pc bit23 */
			{  491,42,1}, /* core4 pc bit24 */
			{  462,42,1}, /* core4 pc bit25 */
			{  481,42,1}, /* core4 pc bit26 */
			{  480,42,1}, /* core4 pc bit27 */
			{  461,42,1}, /* core4 pc bit28 */
			{  460,42,1}, /* core4 pc bit29 */
			{  448,42,1}, /* core4 pc bit30 */
			{  450,42,1}, /* core4 pc bit31 */
			{  270,42,1}, /* core4 pc bit32 */
			{  269,42,1}, /* core4 pc bit33 */
			{  268,42,1}, /* core4 pc bit34 */
			{  278,42,1}, /* core4 pc bit35 */
			{  320,42,1}, /* core4 pc bit36 */
			{  267,42,1}, /* core4 pc bit37 */
			{  266,42,1}, /* core4 pc bit38 */
			{  312,42,1}, /* core4 pc bit39 */
			{  162,42,1}, /* core4 pc bit40 */
			{  319,42,1}, /* core4 pc bit41 */
			{  318,42,1}, /* core4 pc bit42 */
			{  161,42,1}, /* core4 pc bit43 */
			{  160,42,1}, /* core4 pc bit44 */
			{  159,42,1}, /* core4 pc bit45 */
			{  317,42,1}, /* core4 pc bit46 */
			{  316,42,1}, /* core4 pc bit47 */
			{  140,42,1}, /* core4 pc bit48 */
			{  277,42,1}, /* core4 pc bit49 */
			{  276,42,1}, /* core4 pc bit50 */
			{  275,42,1}, /* core4 pc bit51 */
			{  274,42,1}, /* core4 pc bit52 */
			{  139,42,1}, /* core4 pc bit53 */
			{  280,42,1}, /* core4 pc bit54 */
			{  279,42,1}, /* core4 pc bit55 */
			{  353,42,1}, /* core4 pc bit56 */
			{  273,42,1}, /* core4 pc bit57 */
			{  288,42,1}, /* core4 pc bit58 */
			{  287,42,1}, /* core4 pc bit59 */
			{  138,42,1}, /* core4 pc bit60 */
			{  264,42,1}, /* core4 pc bit61 */
			{  263,42,1}, /* core4 pc bit62 */
			{  145,42,1}, /* core4 pc bit63 */
			}},
			.sp32 = {{
			{41179,43,1}, /* core4 sp32 bit0 */
			{41177,43,1}, /* core4 sp32 bit1 */
			{41176,43,1}, /* core4 sp32 bit2 */
			{41175,43,1}, /* core4 sp32 bit3 */
			{41178,43,1}, /* core4 sp32 bit4 */
			{41171,43,1}, /* core4 sp32 bit5 */
			{41170,43,1}, /* core4 sp32 bit6 */
			{41172,43,1}, /* core4 sp32 bit7 */
			{41173,43,1}, /* core4 sp32 bit8 */
			{41174,43,1}, /* core4 sp32 bit9 */
			{41197,43,1}, /* core4 sp32 bit10 */
			{41190,43,1}, /* core4 sp32 bit11 */
			{41182,43,1}, /* core4 sp32 bit12 */
			{41201,43,1}, /* core4 sp32 bit13 */
			{41184,43,1}, /* core4 sp32 bit14 */
			{41198,43,1}, /* core4 sp32 bit15 */
			{34300,42,0}, /* core4 sp32 bit16 */
			{34299,42,0}, /* core4 sp32 bit17 */
			{34328,42,0}, /* core4 sp32 bit18 */
			{34327,42,0}, /* core4 sp32 bit19 */
			{41196,43,1}, /* core4 sp32 bit20 */
			{41185,43,1}, /* core4 sp32 bit21 */
			{41227,43,1}, /* core4 sp32 bit22 */
			{41226,43,1}, /* core4 sp32 bit23 */
			{41180,43,1}, /* core4 sp32 bit24 */
			{41181,43,1}, /* core4 sp32 bit25 */
			{41183,43,1}, /* core4 sp32 bit26 */
			{41186,43,1}, /* core4 sp32 bit27 */
			{41199,43,1}, /* core4 sp32 bit28 */
			{41191,43,1}, /* core4 sp32 bit29 */
			{41188,43,1}, /* core4 sp32 bit30 */
			{41189,43,1}, /* core4 sp32 bit31 */
			{41121,43,1}, /* core4 sp32 bit32 */
			{41123,43,1}, /* core4 sp32 bit33 */
			{41113,43,1}, /* core4 sp32 bit34 */
			{41115,43,1}, /* core4 sp32 bit35 */
			{41120,43,1}, /* core4 sp32 bit36 */
			{41118,43,1}, /* core4 sp32 bit37 */
			{41122,43,1}, /* core4 sp32 bit38 */
			{41117,43,1}, /* core4 sp32 bit39 */
			{41116,43,1}, /* core4 sp32 bit40 */
			{41119,43,1}, /* core4 sp32 bit41 */
			{41108,43,1}, /* core4 sp32 bit42 */
			{41109,43,1}, /* core4 sp32 bit43 */
			{41110,43,1}, /* core4 sp32 bit44 */
			{41114,43,1}, /* core4 sp32 bit45 */
			{41111,43,1}, /* core4 sp32 bit46 */
			{41112,43,1}, /* core4 sp32 bit47 */
			{41159,43,1}, /* core4 sp32 bit48 */
			{41164,43,1}, /* core4 sp32 bit49 */
			{34350,42,0}, /* core4 sp32 bit50 */
			{34349,42,0}, /* core4 sp32 bit51 */
			{41166,43,1}, /* core4 sp32 bit52 */
			{41165,43,1}, /* core4 sp32 bit53 */
			{41163,43,1}, /* core4 sp32 bit54 */
			{41161,43,1}, /* core4 sp32 bit55 */
			{41167,43,1}, /* core4 sp32 bit56 */
			{41160,43,1}, /* core4 sp32 bit57 */
			{41162,43,1}, /* core4 sp32 bit58 */
			{41158,43,1}, /* core4 sp32 bit59 */
			{41157,43,1}, /* core4 sp32 bit60 */
			{41155,43,1}, /* core4 sp32 bit61 */
			{41154,43,1}, /* core4 sp32 bit62 */
			{41156,43,1}, /* core4 sp32 bit63 */
			}},
			.fp32 = {{
			{41650,43,1}, /* core4 fp32 bit0 */
			{41651,43,1}, /* core4 fp32 bit1 */
			{41648,43,1}, /* core4 fp32 bit2 */
			{41645,43,1}, /* core4 fp32 bit3 */
			{41652,43,1}, /* core4 fp32 bit4 */
			{41647,43,1}, /* core4 fp32 bit5 */
			{41644,43,1}, /* core4 fp32 bit6 */
			{41646,43,1}, /* core4 fp32 bit7 */
			{41643,43,1}, /* core4 fp32 bit8 */
			{41642,43,1}, /* core4 fp32 bit9 */
			{41676,43,1}, /* core4 fp32 bit10 */
			{41675,43,1}, /* core4 fp32 bit11 */
			{41685,43,1}, /* core4 fp32 bit12 */
			{41684,43,1}, /* core4 fp32 bit13 */
			{41680,43,1}, /* core4 fp32 bit14 */
			{41681,43,1}, /* core4 fp32 bit15 */
			{41682,43,1}, /* core4 fp32 bit16 */
			{41656,43,1}, /* core4 fp32 bit17 */
			{41678,43,1}, /* core4 fp32 bit18 */
			{41683,43,1}, /* core4 fp32 bit19 */
			{41677,43,1}, /* core4 fp32 bit20 */
			{41672,43,1}, /* core4 fp32 bit21 */
			{41686,43,1}, /* core4 fp32 bit22 */
			{41649,43,1}, /* core4 fp32 bit23 */
			{41688,43,1}, /* core4 fp32 bit24 */
			{41689,43,1}, /* core4 fp32 bit25 */
			{41669,43,1}, /* core4 fp32 bit26 */
			{41670,43,1}, /* core4 fp32 bit27 */
			{41673,43,1}, /* core4 fp32 bit28 */
			{41679,43,1}, /* core4 fp32 bit29 */
			{41674,43,1}, /* core4 fp32 bit30 */
			{41671,43,1}, /* core4 fp32 bit31 */
			{41580,43,1}, /* core4 fp32 bit32 */
			{41589,43,1}, /* core4 fp32 bit33 */
			{41583,43,1}, /* core4 fp32 bit34 */
			{41587,43,1}, /* core4 fp32 bit35 */
			{41582,43,1}, /* core4 fp32 bit36 */
			{41575,43,1}, /* core4 fp32 bit37 */
			{41576,43,1}, /* core4 fp32 bit38 */
			{41585,43,1}, /* core4 fp32 bit39 */
			{41584,43,1}, /* core4 fp32 bit40 */
			{41581,43,1}, /* core4 fp32 bit41 */
			{41588,43,1}, /* core4 fp32 bit42 */
			{41577,43,1}, /* core4 fp32 bit43 */
			{41578,43,1}, /* core4 fp32 bit44 */
			{41579,43,1}, /* core4 fp32 bit45 */
			{41574,43,1}, /* core4 fp32 bit46 */
			{41586,43,1}, /* core4 fp32 bit47 */
			{41605,43,1}, /* core4 fp32 bit48 */
			{41604,43,1}, /* core4 fp32 bit49 */
			{41606,43,1}, /* core4 fp32 bit50 */
			{41609,43,1}, /* core4 fp32 bit51 */
			{41607,43,1}, /* core4 fp32 bit52 */
			{41610,43,1}, /* core4 fp32 bit53 */
			{41602,43,1}, /* core4 fp32 bit54 */
			{41597,43,1}, /* core4 fp32 bit55 */
			{41608,43,1}, /* core4 fp32 bit56 */
			{41598,43,1}, /* core4 fp32 bit57 */
			{41601,43,1}, /* core4 fp32 bit58 */
			{41596,43,1}, /* core4 fp32 bit59 */
			{41593,43,1}, /* core4 fp32 bit60 */
			{34376,42,0}, /* core4 fp32 bit61 */
			{34375,42,0}, /* core4 fp32 bit62 */
			{41594,43,1}, /* core4 fp32 bit63 */
			}},
			.fp64 = {{
			{40573,43,1}, /* core4 fp64 bit0 */
			{40571,43,1}, /* core4 fp64 bit1 */
			{40569,43,1}, /* core4 fp64 bit2 */
			{34306,42,0}, /* core4 fp64 bit3 */
			{34305,42,0}, /* core4 fp64 bit4 */
			{40567,43,1}, /* core4 fp64 bit5 */
			{40568,43,1}, /* core4 fp64 bit6 */
			{34304,42,0}, /* core4 fp64 bit7 */
			{34303,42,0}, /* core4 fp64 bit8 */
			{40570,43,1}, /* core4 fp64 bit9 */
			{40560,43,1}, /* core4 fp64 bit10 */
			{40558,43,1}, /* core4 fp64 bit11 */
			{40566,43,1}, /* core4 fp64 bit12 */
			{40565,43,1}, /* core4 fp64 bit13 */
			{40564,43,1}, /* core4 fp64 bit14 */
			{40559,43,1}, /* core4 fp64 bit15 */
			{40554,43,1}, /* core4 fp64 bit16 */
			{40490,43,1}, /* core4 fp64 bit17 */
			{40552,43,1}, /* core4 fp64 bit18 */
			{40555,43,1}, /* core4 fp64 bit19 */
			{40557,43,1}, /* core4 fp64 bit20 */
			{40553,43,1}, /* core4 fp64 bit21 */
			{40572,43,1}, /* core4 fp64 bit22 */
			{40491,43,1}, /* core4 fp64 bit23 */
			{40492,43,1}, /* core4 fp64 bit24 */
			{40493,43,1}, /* core4 fp64 bit25 */
			{40563,43,1}, /* core4 fp64 bit26 */
			{34322,42,0}, /* core4 fp64 bit27 */
			{34321,42,0}, /* core4 fp64 bit28 */
			{40562,43,1}, /* core4 fp64 bit29 */
			{40561,43,1}, /* core4 fp64 bit30 */
			{40556,43,1}, /* core4 fp64 bit31 */
			{40702,43,1}, /* core4 fp64 bit32 */
			{40697,43,1}, /* core4 fp64 bit33 */
			{40699,43,1}, /* core4 fp64 bit34 */
			{40708,43,1}, /* core4 fp64 bit35 */
			{40706,43,1}, /* core4 fp64 bit36 */
			{40701,43,1}, /* core4 fp64 bit37 */
			{40703,43,1}, /* core4 fp64 bit38 */
			{40705,43,1}, /* core4 fp64 bit39 */
			{40704,43,1}, /* core4 fp64 bit40 */
			{40698,43,1}, /* core4 fp64 bit41 */
			{40707,43,1}, /* core4 fp64 bit42 */
			{40700,43,1}, /* core4 fp64 bit43 */
			{40709,43,1}, /* core4 fp64 bit44 */
			{40696,43,1}, /* core4 fp64 bit45 */
			{40727,43,1}, /* core4 fp64 bit46 */
			{40695,43,1}, /* core4 fp64 bit47 */
			{40690,43,1}, /* core4 fp64 bit48 */
			{40638,43,1}, /* core4 fp64 bit49 */
			{40642,43,1}, /* core4 fp64 bit50 */
			{40645,43,1}, /* core4 fp64 bit51 */
			{40644,43,1}, /* core4 fp64 bit52 */
			{40643,43,1}, /* core4 fp64 bit53 */
			{40637,43,1}, /* core4 fp64 bit54 */
			{40632,43,1}, /* core4 fp64 bit55 */
			{40646,43,1}, /* core4 fp64 bit56 */
			{40633,43,1}, /* core4 fp64 bit57 */
			{40635,43,1}, /* core4 fp64 bit58 */
			{40691,43,1}, /* core4 fp64 bit59 */
			{40693,43,1}, /* core4 fp64 bit60 */
			{40726,43,1}, /* core4 fp64 bit61 */
			{40692,43,1}, /* core4 fp64 bit62 */
			{40694,43,1}, /* core4 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40577,43,1}, /* core4 sp_EL0 bit0 */
			{40575,43,1}, /* core4 sp_EL0 bit1 */
			{40580,43,1}, /* core4 sp_EL0 bit2 */
			{40582,43,1}, /* core4 sp_EL0 bit3 */
			{40583,43,1}, /* core4 sp_EL0 bit4 */
			{40581,43,1}, /* core4 sp_EL0 bit5 */
			{34278,42,0}, /* core4 sp_EL0 bit6 */
			{34277,42,0}, /* core4 sp_EL0 bit7 */
			{40578,43,1}, /* core4 sp_EL0 bit8 */
			{40576,43,1}, /* core4 sp_EL0 bit9 */
			{40488,43,1}, /* core4 sp_EL0 bit10 */
			{40487,43,1}, /* core4 sp_EL0 bit11 */
			{34276,42,0}, /* core4 sp_EL0 bit12 */
			{34275,42,0}, /* core4 sp_EL0 bit13 */
			{40579,43,1}, /* core4 sp_EL0 bit14 */
			{40574,43,1}, /* core4 sp_EL0 bit15 */
			{34284,42,0}, /* core4 sp_EL0 bit16 */
			{34283,42,0}, /* core4 sp_EL0 bit17 */
			{40489,43,1}, /* core4 sp_EL0 bit18 */
			{40486,43,1}, /* core4 sp_EL0 bit19 */
			{40485,43,1}, /* core4 sp_EL0 bit20 */
			{40484,43,1}, /* core4 sp_EL0 bit21 */
			{40306,43,1}, /* core4 sp_EL0 bit22 */
			{40302,43,1}, /* core4 sp_EL0 bit23 */
			{40304,43,1}, /* core4 sp_EL0 bit24 */
			{40305,43,1}, /* core4 sp_EL0 bit25 */
			{40282,43,1}, /* core4 sp_EL0 bit26 */
			{40283,43,1}, /* core4 sp_EL0 bit27 */
			{40285,43,1}, /* core4 sp_EL0 bit28 */
			{40284,43,1}, /* core4 sp_EL0 bit29 */
			{40286,43,1}, /* core4 sp_EL0 bit30 */
			{40303,43,1}, /* core4 sp_EL0 bit31 */
			{40436,43,1}, /* core4 sp_EL0 bit32 */
			{40434,43,1}, /* core4 sp_EL0 bit33 */
			{40440,43,1}, /* core4 sp_EL0 bit34 */
			{40437,43,1}, /* core4 sp_EL0 bit35 */
			{40427,43,1}, /* core4 sp_EL0 bit36 */
			{40428,43,1}, /* core4 sp_EL0 bit37 */
			{40431,43,1}, /* core4 sp_EL0 bit38 */
			{40429,43,1}, /* core4 sp_EL0 bit39 */
			{40430,43,1}, /* core4 sp_EL0 bit40 */
			{40441,43,1}, /* core4 sp_EL0 bit41 */
			{40433,43,1}, /* core4 sp_EL0 bit42 */
			{40432,43,1}, /* core4 sp_EL0 bit43 */
			{40439,43,1}, /* core4 sp_EL0 bit44 */
			{40438,43,1}, /* core4 sp_EL0 bit45 */
			{40443,43,1}, /* core4 sp_EL0 bit46 */
			{40442,43,1}, /* core4 sp_EL0 bit47 */
			{40456,43,1}, /* core4 sp_EL0 bit48 */
			{34430,42,0}, /* core4 sp_EL0 bit49 */
			{34426,42,0}, /* core4 sp_EL0 bit50 */
			{34425,42,0}, /* core4 sp_EL0 bit51 */
			{34432,42,0}, /* core4 sp_EL0 bit52 */
			{34431,42,0}, /* core4 sp_EL0 bit53 */
			{34429,42,0}, /* core4 sp_EL0 bit54 */
			{40446,43,1}, /* core4 sp_EL0 bit55 */
			{36696,42,0}, /* core4 sp_EL0 bit56 */
			{36695,42,0}, /* core4 sp_EL0 bit57 */
			{36694,42,0}, /* core4 sp_EL0 bit58 */
			{36693,42,0}, /* core4 sp_EL0 bit59 */
			{40445,43,1}, /* core4 sp_EL0 bit60 */
			{40444,43,1}, /* core4 sp_EL0 bit61 */
			{34392,42,0}, /* core4 sp_EL0 bit62 */
			{34391,42,0}, /* core4 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40312,43,1}, /* core4 sp_EL1 bit0 */
			{40319,43,1}, /* core4 sp_EL1 bit1 */
			{40314,43,1}, /* core4 sp_EL1 bit2 */
			{40315,43,1}, /* core4 sp_EL1 bit3 */
			{34236,42,0}, /* core4 sp_EL1 bit4 */
			{34235,42,0}, /* core4 sp_EL1 bit5 */
			{34238,42,0}, /* core4 sp_EL1 bit6 */
			{34237,42,0}, /* core4 sp_EL1 bit7 */
			{40313,43,1}, /* core4 sp_EL1 bit8 */
			{40316,43,1}, /* core4 sp_EL1 bit9 */
			{40336,43,1}, /* core4 sp_EL1 bit10 */
			{40333,43,1}, /* core4 sp_EL1 bit11 */
			{40311,43,1}, /* core4 sp_EL1 bit12 */
			{40308,43,1}, /* core4 sp_EL1 bit13 */
			{40331,43,1}, /* core4 sp_EL1 bit14 */
			{40330,43,1}, /* core4 sp_EL1 bit15 */
			{34216,42,0}, /* core4 sp_EL1 bit16 */
			{34215,42,0}, /* core4 sp_EL1 bit17 */
			{40348,43,1}, /* core4 sp_EL1 bit18 */
			{40349,43,1}, /* core4 sp_EL1 bit19 */
			{40350,43,1}, /* core4 sp_EL1 bit20 */
			{40346,43,1}, /* core4 sp_EL1 bit21 */
			{40332,43,1}, /* core4 sp_EL1 bit22 */
			{40334,43,1}, /* core4 sp_EL1 bit23 */
			{40335,43,1}, /* core4 sp_EL1 bit24 */
			{40347,43,1}, /* core4 sp_EL1 bit25 */
			{40320,43,1}, /* core4 sp_EL1 bit26 */
			{40321,43,1}, /* core4 sp_EL1 bit27 */
			{40310,43,1}, /* core4 sp_EL1 bit28 */
			{40309,43,1}, /* core4 sp_EL1 bit29 */
			{40307,43,1}, /* core4 sp_EL1 bit30 */
			{40345,43,1}, /* core4 sp_EL1 bit31 */
			{40406,43,1}, /* core4 sp_EL1 bit32 */
			{40405,43,1}, /* core4 sp_EL1 bit33 */
			{40386,43,1}, /* core4 sp_EL1 bit34 */
			{40383,43,1}, /* core4 sp_EL1 bit35 */
			{40422,43,1}, /* core4 sp_EL1 bit36 */
			{40421,43,1}, /* core4 sp_EL1 bit37 */
			{40407,43,1}, /* core4 sp_EL1 bit38 */
			{40400,43,1}, /* core4 sp_EL1 bit39 */
			{40401,43,1}, /* core4 sp_EL1 bit40 */
			{40409,43,1}, /* core4 sp_EL1 bit41 */
			{40410,43,1}, /* core4 sp_EL1 bit42 */
			{40411,43,1}, /* core4 sp_EL1 bit43 */
			{40408,43,1}, /* core4 sp_EL1 bit44 */
			{40384,43,1}, /* core4 sp_EL1 bit45 */
			{40379,43,1}, /* core4 sp_EL1 bit46 */
			{40385,43,1}, /* core4 sp_EL1 bit47 */
			{40449,43,1}, /* core4 sp_EL1 bit48 */
			{39472,42,0}, /* core4 sp_EL1 bit49 */
			{39471,42,0}, /* core4 sp_EL1 bit50 */
			{39470,42,0}, /* core4 sp_EL1 bit51 */
			{39469,42,0}, /* core4 sp_EL1 bit52 */
			{39468,42,0}, /* core4 sp_EL1 bit53 */
			{39467,42,0}, /* core4 sp_EL1 bit54 */
			{39466,42,0}, /* core4 sp_EL1 bit55 */
			{39465,42,0}, /* core4 sp_EL1 bit56 */
			{40448,43,1}, /* core4 sp_EL1 bit57 */
			{34398,42,0}, /* core4 sp_EL1 bit58 */
			{34397,42,0}, /* core4 sp_EL1 bit59 */
			{34386,42,0}, /* core4 sp_EL1 bit60 */
			{34385,42,0}, /* core4 sp_EL1 bit61 */
			{34198,42,0}, /* core4 sp_EL1 bit62 */
			{34197,42,0}, /* core4 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40264,43,1}, /* core4 sp_EL2 bit0 */
			{40256,43,1}, /* core4 sp_EL2 bit1 */
			{40268,43,1}, /* core4 sp_EL2 bit2 */
			{40266,43,1}, /* core4 sp_EL2 bit3 */
			{40257,43,1}, /* core4 sp_EL2 bit4 */
			{40263,43,1}, /* core4 sp_EL2 bit5 */
			{40267,43,1}, /* core4 sp_EL2 bit6 */
			{40262,43,1}, /* core4 sp_EL2 bit7 */
			{40261,43,1}, /* core4 sp_EL2 bit8 */
			{40260,43,1}, /* core4 sp_EL2 bit9 */
			{40245,43,1}, /* core4 sp_EL2 bit10 */
			{40246,43,1}, /* core4 sp_EL2 bit11 */
			{40265,43,1}, /* core4 sp_EL2 bit12 */
			{40243,43,1}, /* core4 sp_EL2 bit13 */
			{40241,43,1}, /* core4 sp_EL2 bit14 */
			{40239,43,1}, /* core4 sp_EL2 bit15 */
			{40251,43,1}, /* core4 sp_EL2 bit16 */
			{40259,43,1}, /* core4 sp_EL2 bit17 */
			{40250,43,1}, /* core4 sp_EL2 bit18 */
			{40247,43,1}, /* core4 sp_EL2 bit19 */
			{40248,43,1}, /* core4 sp_EL2 bit20 */
			{40249,43,1}, /* core4 sp_EL2 bit21 */
			{40255,43,1}, /* core4 sp_EL2 bit22 */
			{40258,43,1}, /* core4 sp_EL2 bit23 */
			{40254,43,1}, /* core4 sp_EL2 bit24 */
			{40253,43,1}, /* core4 sp_EL2 bit25 */
			{40238,43,1}, /* core4 sp_EL2 bit26 */
			{40237,43,1}, /* core4 sp_EL2 bit27 */
			{40242,43,1}, /* core4 sp_EL2 bit28 */
			{40240,43,1}, /* core4 sp_EL2 bit29 */
			{40244,43,1}, /* core4 sp_EL2 bit30 */
			{40252,43,1}, /* core4 sp_EL2 bit31 */
			{40402,43,1}, /* core4 sp_EL2 bit32 */
			{40412,43,1}, /* core4 sp_EL2 bit33 */
			{40387,43,1}, /* core4 sp_EL2 bit34 */
			{40388,43,1}, /* core4 sp_EL2 bit35 */
			{40419,43,1}, /* core4 sp_EL2 bit36 */
			{40414,43,1}, /* core4 sp_EL2 bit37 */
			{40413,43,1}, /* core4 sp_EL2 bit38 */
			{40417,43,1}, /* core4 sp_EL2 bit39 */
			{40416,43,1}, /* core4 sp_EL2 bit40 */
			{40418,43,1}, /* core4 sp_EL2 bit41 */
			{40415,43,1}, /* core4 sp_EL2 bit42 */
			{40420,43,1}, /* core4 sp_EL2 bit43 */
			{40404,43,1}, /* core4 sp_EL2 bit44 */
			{40403,43,1}, /* core4 sp_EL2 bit45 */
			{40378,43,1}, /* core4 sp_EL2 bit46 */
			{40389,43,1}, /* core4 sp_EL2 bit47 */
			{40447,43,1}, /* core4 sp_EL2 bit48 */
			{40460,43,1}, /* core4 sp_EL2 bit49 */
			{34422,42,0}, /* core4 sp_EL2 bit50 */
			{34421,42,0}, /* core4 sp_EL2 bit51 */
			{34420,42,0}, /* core4 sp_EL2 bit52 */
			{34419,42,0}, /* core4 sp_EL2 bit53 */
			{34416,42,0}, /* core4 sp_EL2 bit54 */
			{34415,42,0}, /* core4 sp_EL2 bit55 */
			{34400,42,0}, /* core4 sp_EL2 bit56 */
			{34399,42,0}, /* core4 sp_EL2 bit57 */
			{34396,42,0}, /* core4 sp_EL2 bit58 */
			{34395,42,0}, /* core4 sp_EL2 bit59 */
			{36728,42,0}, /* core4 sp_EL2 bit60 */
			{36727,42,0}, /* core4 sp_EL2 bit61 */
			{36726,42,0}, /* core4 sp_EL2 bit62 */
			{36725,42,0}, /* core4 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40272,43,1}, /* core4 sp_EL3 bit0 */
			{40289,43,1}, /* core4 sp_EL3 bit1 */
			{40277,43,1}, /* core4 sp_EL3 bit2 */
			{40279,43,1}, /* core4 sp_EL3 bit3 */
			{40281,43,1}, /* core4 sp_EL3 bit4 */
			{40280,43,1}, /* core4 sp_EL3 bit5 */
			{34280,42,0}, /* core4 sp_EL3 bit6 */
			{34279,42,0}, /* core4 sp_EL3 bit7 */
			{40278,43,1}, /* core4 sp_EL3 bit8 */
			{40276,43,1}, /* core4 sp_EL3 bit9 */
			{40290,43,1}, /* core4 sp_EL3 bit10 */
			{40292,43,1}, /* core4 sp_EL3 bit11 */
			{34282,42,0}, /* core4 sp_EL3 bit12 */
			{34281,42,0}, /* core4 sp_EL3 bit13 */
			{40288,43,1}, /* core4 sp_EL3 bit14 */
			{40287,43,1}, /* core4 sp_EL3 bit15 */
			{40300,43,1}, /* core4 sp_EL3 bit16 */
			{40301,43,1}, /* core4 sp_EL3 bit17 */
			{40291,43,1}, /* core4 sp_EL3 bit18 */
			{40299,43,1}, /* core4 sp_EL3 bit19 */
			{40297,43,1}, /* core4 sp_EL3 bit20 */
			{40298,43,1}, /* core4 sp_EL3 bit21 */
			{40271,43,1}, /* core4 sp_EL3 bit22 */
			{40294,43,1}, /* core4 sp_EL3 bit23 */
			{40295,43,1}, /* core4 sp_EL3 bit24 */
			{40296,43,1}, /* core4 sp_EL3 bit25 */
			{40275,43,1}, /* core4 sp_EL3 bit26 */
			{40274,43,1}, /* core4 sp_EL3 bit27 */
			{40273,43,1}, /* core4 sp_EL3 bit28 */
			{40270,43,1}, /* core4 sp_EL3 bit29 */
			{40269,43,1}, /* core4 sp_EL3 bit30 */
			{40293,43,1}, /* core4 sp_EL3 bit31 */
			{40393,43,1}, /* core4 sp_EL3 bit32 */
			{40392,43,1}, /* core4 sp_EL3 bit33 */
			{40391,43,1}, /* core4 sp_EL3 bit34 */
			{40396,43,1}, /* core4 sp_EL3 bit35 */
			{40425,43,1}, /* core4 sp_EL3 bit36 */
			{40423,43,1}, /* core4 sp_EL3 bit37 */
			{40395,43,1}, /* core4 sp_EL3 bit38 */
			{40426,43,1}, /* core4 sp_EL3 bit39 */
			{40397,43,1}, /* core4 sp_EL3 bit40 */
			{40399,43,1}, /* core4 sp_EL3 bit41 */
			{40424,43,1}, /* core4 sp_EL3 bit42 */
			{40398,43,1}, /* core4 sp_EL3 bit43 */
			{40394,43,1}, /* core4 sp_EL3 bit44 */
			{40435,43,1}, /* core4 sp_EL3 bit45 */
			{40377,43,1}, /* core4 sp_EL3 bit46 */
			{40390,43,1}, /* core4 sp_EL3 bit47 */
			{40458,43,1}, /* core4 sp_EL3 bit48 */
			{40457,43,1}, /* core4 sp_EL3 bit49 */
			{34418,42,0}, /* core4 sp_EL3 bit50 */
			{34417,42,0}, /* core4 sp_EL3 bit51 */
			{36776,42,0}, /* core4 sp_EL3 bit52 */
			{36775,42,0}, /* core4 sp_EL3 bit53 */
			{36774,42,0}, /* core4 sp_EL3 bit54 */
			{36773,42,0}, /* core4 sp_EL3 bit55 */
			{36692,42,0}, /* core4 sp_EL3 bit56 */
			{36691,42,0}, /* core4 sp_EL3 bit57 */
			{36690,42,0}, /* core4 sp_EL3 bit58 */
			{36689,42,0}, /* core4 sp_EL3 bit59 */
			{40375,43,1}, /* core4 sp_EL3 bit60 */
			{40374,43,1}, /* core4 sp_EL3 bit61 */
			{34388,42,0}, /* core4 sp_EL3 bit62 */
			{34387,42,0}, /* core4 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{39606,42,0}, /* core4 elr_EL1 bit0 */
			{39605,42,0}, /* core4 elr_EL1 bit1 */
			{39604,42,0}, /* core4 elr_EL1 bit2 */
			{39603,42,0}, /* core4 elr_EL1 bit3 */
			{39602,42,0}, /* core4 elr_EL1 bit4 */
			{39601,42,0}, /* core4 elr_EL1 bit5 */
			{39600,42,0}, /* core4 elr_EL1 bit6 */
			{39599,42,0}, /* core4 elr_EL1 bit7 */
			{34224,42,0}, /* core4 elr_EL1 bit8 */
			{34223,42,0}, /* core4 elr_EL1 bit9 */
			{34218,42,0}, /* core4 elr_EL1 bit10 */
			{34217,42,0}, /* core4 elr_EL1 bit11 */
			{34222,42,0}, /* core4 elr_EL1 bit12 */
			{34221,42,0}, /* core4 elr_EL1 bit13 */
			{34220,42,0}, /* core4 elr_EL1 bit14 */
			{34219,42,0}, /* core4 elr_EL1 bit15 */
			{39654,42,0}, /* core4 elr_EL1 bit16 */
			{39653,42,0}, /* core4 elr_EL1 bit17 */
			{39652,42,0}, /* core4 elr_EL1 bit18 */
			{39651,42,0}, /* core4 elr_EL1 bit19 */
			{39650,42,0}, /* core4 elr_EL1 bit20 */
			{39649,42,0}, /* core4 elr_EL1 bit21 */
			{39648,42,0}, /* core4 elr_EL1 bit22 */
			{39647,42,0}, /* core4 elr_EL1 bit23 */
			{39638,42,0}, /* core4 elr_EL1 bit24 */
			{39637,42,0}, /* core4 elr_EL1 bit25 */
			{39636,42,0}, /* core4 elr_EL1 bit26 */
			{39635,42,0}, /* core4 elr_EL1 bit27 */
			{39634,42,0}, /* core4 elr_EL1 bit28 */
			{39633,42,0}, /* core4 elr_EL1 bit29 */
			{39632,42,0}, /* core4 elr_EL1 bit30 */
			{39631,42,0}, /* core4 elr_EL1 bit31 */
			{36720,42,0}, /* core4 elr_EL1 bit32 */
			{36724,42,0}, /* core4 elr_EL1 bit33 */
			{36723,42,0}, /* core4 elr_EL1 bit34 */
			{36719,42,0}, /* core4 elr_EL1 bit35 */
			{36722,42,0}, /* core4 elr_EL1 bit36 */
			{36721,42,0}, /* core4 elr_EL1 bit37 */
			{36716,42,0}, /* core4 elr_EL1 bit38 */
			{36718,42,0}, /* core4 elr_EL1 bit39 */
			{36715,42,0}, /* core4 elr_EL1 bit40 */
			{36714,42,0}, /* core4 elr_EL1 bit41 */
			{39440,42,0}, /* core4 elr_EL1 bit42 */
			{39439,42,0}, /* core4 elr_EL1 bit43 */
			{39438,42,0}, /* core4 elr_EL1 bit44 */
			{36717,42,0}, /* core4 elr_EL1 bit45 */
			{39437,42,0}, /* core4 elr_EL1 bit46 */
			{39436,42,0}, /* core4 elr_EL1 bit47 */
			{36796,42,0}, /* core4 elr_EL1 bit48 */
			{39435,42,0}, /* core4 elr_EL1 bit49 */
			{36795,42,0}, /* core4 elr_EL1 bit50 */
			{36794,42,0}, /* core4 elr_EL1 bit51 */
			{36793,42,0}, /* core4 elr_EL1 bit52 */
			{36792,42,0}, /* core4 elr_EL1 bit53 */
			{39434,42,0}, /* core4 elr_EL1 bit54 */
			{39433,42,0}, /* core4 elr_EL1 bit55 */
			{36791,42,0}, /* core4 elr_EL1 bit56 */
			{36790,42,0}, /* core4 elr_EL1 bit57 */
			{36789,42,0}, /* core4 elr_EL1 bit58 */
			{34394,42,0}, /* core4 elr_EL1 bit59 */
			{36713,42,0}, /* core4 elr_EL1 bit60 */
			{34393,42,0}, /* core4 elr_EL1 bit61 */
			{34390,42,0}, /* core4 elr_EL1 bit62 */
			{34389,42,0}, /* core4 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{39614,42,0}, /* core4 elr_EL2 bit0 */
			{39613,42,0}, /* core4 elr_EL2 bit1 */
			{39612,42,0}, /* core4 elr_EL2 bit2 */
			{39611,42,0}, /* core4 elr_EL2 bit3 */
			{39610,42,0}, /* core4 elr_EL2 bit4 */
			{39609,42,0}, /* core4 elr_EL2 bit5 */
			{39608,42,0}, /* core4 elr_EL2 bit6 */
			{39607,42,0}, /* core4 elr_EL2 bit7 */
			{39622,42,0}, /* core4 elr_EL2 bit8 */
			{39621,42,0}, /* core4 elr_EL2 bit9 */
			{39620,42,0}, /* core4 elr_EL2 bit10 */
			{39619,42,0}, /* core4 elr_EL2 bit11 */
			{39618,42,0}, /* core4 elr_EL2 bit12 */
			{39617,42,0}, /* core4 elr_EL2 bit13 */
			{39616,42,0}, /* core4 elr_EL2 bit14 */
			{39615,42,0}, /* core4 elr_EL2 bit15 */
			{39646,42,0}, /* core4 elr_EL2 bit16 */
			{39645,42,0}, /* core4 elr_EL2 bit17 */
			{39644,42,0}, /* core4 elr_EL2 bit18 */
			{39643,42,0}, /* core4 elr_EL2 bit19 */
			{39642,42,0}, /* core4 elr_EL2 bit20 */
			{39641,42,0}, /* core4 elr_EL2 bit21 */
			{39640,42,0}, /* core4 elr_EL2 bit22 */
			{39639,42,0}, /* core4 elr_EL2 bit23 */
			{39630,42,0}, /* core4 elr_EL2 bit24 */
			{39629,42,0}, /* core4 elr_EL2 bit25 */
			{39628,42,0}, /* core4 elr_EL2 bit26 */
			{39627,42,0}, /* core4 elr_EL2 bit27 */
			{39626,42,0}, /* core4 elr_EL2 bit28 */
			{39625,42,0}, /* core4 elr_EL2 bit29 */
			{39624,42,0}, /* core4 elr_EL2 bit30 */
			{39623,42,0}, /* core4 elr_EL2 bit31 */
			{39432,42,0}, /* core4 elr_EL2 bit32 */
			{36712,42,0}, /* core4 elr_EL2 bit33 */
			{36711,42,0}, /* core4 elr_EL2 bit34 */
			{39431,42,0}, /* core4 elr_EL2 bit35 */
			{39430,42,0}, /* core4 elr_EL2 bit36 */
			{39429,42,0}, /* core4 elr_EL2 bit37 */
			{36710,42,0}, /* core4 elr_EL2 bit38 */
			{39428,42,0}, /* core4 elr_EL2 bit39 */
			{36709,42,0}, /* core4 elr_EL2 bit40 */
			{36708,42,0}, /* core4 elr_EL2 bit41 */
			{39427,42,0}, /* core4 elr_EL2 bit42 */
			{36707,42,0}, /* core4 elr_EL2 bit43 */
			{36706,42,0}, /* core4 elr_EL2 bit44 */
			{39426,42,0}, /* core4 elr_EL2 bit45 */
			{39425,42,0}, /* core4 elr_EL2 bit46 */
			{36705,42,0}, /* core4 elr_EL2 bit47 */
			{36788,42,0}, /* core4 elr_EL2 bit48 */
			{36787,42,0}, /* core4 elr_EL2 bit49 */
			{36786,42,0}, /* core4 elr_EL2 bit50 */
			{36785,42,0}, /* core4 elr_EL2 bit51 */
			{36784,42,0}, /* core4 elr_EL2 bit52 */
			{36783,42,0}, /* core4 elr_EL2 bit53 */
			{36782,42,0}, /* core4 elr_EL2 bit54 */
			{36781,42,0}, /* core4 elr_EL2 bit55 */
			{36780,42,0}, /* core4 elr_EL2 bit56 */
			{36779,42,0}, /* core4 elr_EL2 bit57 */
			{36778,42,0}, /* core4 elr_EL2 bit58 */
			{36777,42,0}, /* core4 elr_EL2 bit59 */
			{36704,42,0}, /* core4 elr_EL2 bit60 */
			{36703,42,0}, /* core4 elr_EL2 bit61 */
			{36702,42,0}, /* core4 elr_EL2 bit62 */
			{36701,42,0}, /* core4 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{34228,42,0}, /* core4 elr_EL3 bit0 */
			{34227,42,0}, /* core4 elr_EL3 bit1 */
			{40317,43,1}, /* core4 elr_EL3 bit2 */
			{40318,43,1}, /* core4 elr_EL3 bit3 */
			{36912,42,0}, /* core4 elr_EL3 bit4 */
			{36911,42,0}, /* core4 elr_EL3 bit5 */
			{36910,42,0}, /* core4 elr_EL3 bit6 */
			{36909,42,0}, /* core4 elr_EL3 bit7 */
			{34232,42,0}, /* core4 elr_EL3 bit8 */
			{34231,42,0}, /* core4 elr_EL3 bit9 */
			{40339,43,1}, /* core4 elr_EL3 bit10 */
			{40351,43,1}, /* core4 elr_EL3 bit11 */
			{34230,42,0}, /* core4 elr_EL3 bit12 */
			{34229,42,0}, /* core4 elr_EL3 bit13 */
			{40326,43,1}, /* core4 elr_EL3 bit14 */
			{40328,43,1}, /* core4 elr_EL3 bit15 */
			{40352,43,1}, /* core4 elr_EL3 bit16 */
			{40353,43,1}, /* core4 elr_EL3 bit17 */
			{40354,43,1}, /* core4 elr_EL3 bit18 */
			{40344,43,1}, /* core4 elr_EL3 bit19 */
			{40342,43,1}, /* core4 elr_EL3 bit20 */
			{40341,43,1}, /* core4 elr_EL3 bit21 */
			{40327,43,1}, /* core4 elr_EL3 bit22 */
			{40338,43,1}, /* core4 elr_EL3 bit23 */
			{40340,43,1}, /* core4 elr_EL3 bit24 */
			{40343,43,1}, /* core4 elr_EL3 bit25 */
			{40323,43,1}, /* core4 elr_EL3 bit26 */
			{40322,43,1}, /* core4 elr_EL3 bit27 */
			{40324,43,1}, /* core4 elr_EL3 bit28 */
			{40325,43,1}, /* core4 elr_EL3 bit29 */
			{40329,43,1}, /* core4 elr_EL3 bit30 */
			{40337,43,1}, /* core4 elr_EL3 bit31 */
			{34382,42,0}, /* core4 elr_EL3 bit32 */
			{34381,42,0}, /* core4 elr_EL3 bit33 */
			{40368,43,1}, /* core4 elr_EL3 bit34 */
			{40364,43,1}, /* core4 elr_EL3 bit35 */
			{40380,43,1}, /* core4 elr_EL3 bit36 */
			{40372,43,1}, /* core4 elr_EL3 bit37 */
			{40365,43,1}, /* core4 elr_EL3 bit38 */
			{40376,43,1}, /* core4 elr_EL3 bit39 */
			{40369,43,1}, /* core4 elr_EL3 bit40 */
			{40367,43,1}, /* core4 elr_EL3 bit41 */
			{40373,43,1}, /* core4 elr_EL3 bit42 */
			{40371,43,1}, /* core4 elr_EL3 bit43 */
			{40381,43,1}, /* core4 elr_EL3 bit44 */
			{40366,43,1}, /* core4 elr_EL3 bit45 */
			{40370,43,1}, /* core4 elr_EL3 bit46 */
			{40382,43,1}, /* core4 elr_EL3 bit47 */
			{34402,42,0}, /* core4 elr_EL3 bit48 */
			{34401,42,0}, /* core4 elr_EL3 bit49 */
			{36772,42,0}, /* core4 elr_EL3 bit50 */
			{36771,42,0}, /* core4 elr_EL3 bit51 */
			{34414,42,0}, /* core4 elr_EL3 bit52 */
			{36770,42,0}, /* core4 elr_EL3 bit53 */
			{34413,42,0}, /* core4 elr_EL3 bit54 */
			{36769,42,0}, /* core4 elr_EL3 bit55 */
			{36688,42,0}, /* core4 elr_EL3 bit56 */
			{36687,42,0}, /* core4 elr_EL3 bit57 */
			{36686,42,0}, /* core4 elr_EL3 bit58 */
			{36685,42,0}, /* core4 elr_EL3 bit59 */
			{34384,42,0}, /* core4 elr_EL3 bit60 */
			{34383,42,0}, /* core4 elr_EL3 bit61 */
			{34196,42,0}, /* core4 elr_EL3 bit62 */
			{34195,42,0}, /* core4 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{35631,42,0}, /* core4 raw_pc bit0 */
			{35630,42,0}, /* core4 raw_pc bit1 */
			{38290,42,0}, /* core4 raw_pc bit2 */
			{38289,42,0}, /* core4 raw_pc bit3 */
			{38288,42,0}, /* core4 raw_pc bit4 */
			{38287,42,0}, /* core4 raw_pc bit5 */
			{32560,42,1}, /* core4 raw_pc bit6 */
			{38278,42,0}, /* core4 raw_pc bit7 */
			{38277,42,0}, /* core4 raw_pc bit8 */
			{38276,42,0}, /* core4 raw_pc bit9 */
			{38275,42,0}, /* core4 raw_pc bit10 */
			{35637,42,0}, /* core4 raw_pc bit11 */
			{35636,42,0}, /* core4 raw_pc bit12 */
			{35635,42,0}, /* core4 raw_pc bit13 */
			{35634,42,0}, /* core4 raw_pc bit14 */
			{38282,42,0}, /* core4 raw_pc bit15 */
			{38281,42,0}, /* core4 raw_pc bit16 */
			{38280,42,0}, /* core4 raw_pc bit17 */
			{38279,42,0}, /* core4 raw_pc bit18 */
			{35641,42,0}, /* core4 raw_pc bit19 */
			{35640,42,0}, /* core4 raw_pc bit20 */
			{32562,42,1}, /* core4 raw_pc bit21 */
			{32561,42,1}, /* core4 raw_pc bit22 */
			{38286,42,0}, /* core4 raw_pc bit23 */
			{38285,42,0}, /* core4 raw_pc bit24 */
			{38284,42,0}, /* core4 raw_pc bit25 */
			{38283,42,0}, /* core4 raw_pc bit26 */
			{35633,42,0}, /* core4 raw_pc bit27 */
			{35632,42,0}, /* core4 raw_pc bit28 */
			{35639,42,0}, /* core4 raw_pc bit29 */
			{35638,42,0}, /* core4 raw_pc bit30 */
			{38274,42,0}, /* core4 raw_pc bit31 */
			{38273,42,0}, /* core4 raw_pc bit32 */
			{38272,42,0}, /* core4 raw_pc bit33 */
			{38271,42,0}, /* core4 raw_pc bit34 */
			{40754,42,0}, /* core4 raw_pc bit35 */
			{40753,42,0}, /* core4 raw_pc bit36 */
			{40752,42,0}, /* core4 raw_pc bit37 */
			{40751,42,0}, /* core4 raw_pc bit38 */
			{35645,42,0}, /* core4 raw_pc bit39 */
			{35644,42,0}, /* core4 raw_pc bit40 */
			{40750,42,0}, /* core4 raw_pc bit41 */
			{40749,42,0}, /* core4 raw_pc bit42 */
			{35647,42,0}, /* core4 raw_pc bit43 */
			{35646,42,0}, /* core4 raw_pc bit44 */
			{40748,42,0}, /* core4 raw_pc bit45 */
			{40747,42,0}, /* core4 raw_pc bit46 */
			{32577,42,1}, /* core4 raw_pc bit47 */
			{32578,42,1}, /* core4 raw_pc bit48 */
			{32579,42,1}, /* core4 raw_pc bit49 */
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
			{32555,42,1}, /* core4 pc_iss bit0 */
			{32637,42,1}, /* core4 pc_iss bit1 */
			{32634,42,1}, /* core4 pc_iss bit2 */
			{32633,42,1}, /* core4 pc_iss bit3 */
			{32635,42,1}, /* core4 pc_iss bit4 */
			{32554,42,1}, /* core4 pc_iss bit5 */
			{32556,42,1}, /* core4 pc_iss bit6 */
			{32636,42,1}, /* core4 pc_iss bit7 */
			{32610,42,1}, /* core4 pc_iss bit8 */
			{32603,42,1}, /* core4 pc_iss bit9 */
			{32632,42,1}, /* core4 pc_iss bit10 */
			{32631,42,1}, /* core4 pc_iss bit11 */
			{32629,42,1}, /* core4 pc_iss bit12 */
			{32630,42,1}, /* core4 pc_iss bit13 */
			{32628,42,1}, /* core4 pc_iss bit14 */
			{32614,42,1}, /* core4 pc_iss bit15 */
			{32615,42,1}, /* core4 pc_iss bit16 */
			{32627,42,1}, /* core4 pc_iss bit17 */
			{32624,42,1}, /* core4 pc_iss bit18 */
			{32617,42,1}, /* core4 pc_iss bit19 */
			{32625,42,1}, /* core4 pc_iss bit20 */
			{32626,42,1}, /* core4 pc_iss bit21 */
			{32611,42,1}, /* core4 pc_iss bit22 */
			{32618,42,1}, /* core4 pc_iss bit23 */
			{32622,42,1}, /* core4 pc_iss bit24 */
			{32621,42,1}, /* core4 pc_iss bit25 */
			{32619,42,1}, /* core4 pc_iss bit26 */
			{32612,42,1}, /* core4 pc_iss bit27 */
			{32613,42,1}, /* core4 pc_iss bit28 */
			{32620,42,1}, /* core4 pc_iss bit29 */
			{32616,42,1}, /* core4 pc_iss bit30 */
			{32623,42,1}, /* core4 pc_iss bit31 */
			{32573,42,1}, /* core4 pc_iss bit32 */
			{32574,42,1}, /* core4 pc_iss bit33 */
			{32563,42,1}, /* core4 pc_iss bit34 */
			{32564,42,1}, /* core4 pc_iss bit35 */
			{32570,42,1}, /* core4 pc_iss bit36 */
			{32566,42,1}, /* core4 pc_iss bit37 */
			{32571,42,1}, /* core4 pc_iss bit38 */
			{32565,42,1}, /* core4 pc_iss bit39 */
			{32572,42,1}, /* core4 pc_iss bit40 */
			{32568,42,1}, /* core4 pc_iss bit41 */
			{32567,42,1}, /* core4 pc_iss bit42 */
			{32569,42,1}, /* core4 pc_iss bit43 */
			{35685,42,0}, /* core4 pc_iss bit44 */
			{35684,42,0}, /* core4 pc_iss bit45 */
			{35683,42,0}, /* core4 pc_iss bit46 */
			{35682,42,0}, /* core4 pc_iss bit47 */
			{38270,42,0}, /* core4 pc_iss bit48 */
			{38269,42,0}, /* core4 pc_iss bit49 */
			{38268,42,0}, /* core4 pc_iss bit50 */
			{38267,42,0}, /* core4 pc_iss bit51 */
			{38266,42,0}, /* core4 pc_iss bit52 */
			{38265,42,0}, /* core4 pc_iss bit53 */
			{38264,42,0}, /* core4 pc_iss bit54 */
			{38263,42,0}, /* core4 pc_iss bit55 */
			{40956,42,0}, /* core4 pc_iss bit56 */
			{40955,42,0}, /* core4 pc_iss bit57 */
			{40954,42,0}, /* core4 pc_iss bit58 */
			{40953,42,0}, /* core4 pc_iss bit59 */
			{40952,42,0}, /* core4 pc_iss bit60 */
			{40951,42,0}, /* core4 pc_iss bit61 */
			{40950,42,0}, /* core4 pc_iss bit62 */
			{40949,42,0}, /* core4 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{32557,42,1}, /* core4 full_pc_wr bit0 */
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
			{41124,42,0}, /* core4 full_pc_ex1 bit0 */
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
			{41116,42,0}, /* core4 full_pc_ex2 bit0 */
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
			{25953,43,1}, /* core4 return_Stack_pointer bit0 */
			{28673,43,1}, /* core4 return_Stack_pointer bit1 */
			{28674,43,1}, /* core4 return_Stack_pointer bit2 */
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
			{32644,43,1}, /* core4 return_Stack0 bit0 */
			{32643,43,1}, /* core4 return_Stack0 bit1 */
			{32672,43,1}, /* core4 return_Stack0 bit2 */
			{32671,43,1}, /* core4 return_Stack0 bit3 */
			{32670,43,1}, /* core4 return_Stack0 bit4 */
			{32669,43,1}, /* core4 return_Stack0 bit5 */
			{28860,43,1}, /* core4 return_Stack0 bit6 */
			{28859,43,1}, /* core4 return_Stack0 bit7 */
			{28858,43,1}, /* core4 return_Stack0 bit8 */
			{28857,43,1}, /* core4 return_Stack0 bit9 */
			{37875,43,1}, /* core4 return_Stack0 bit10 */
			{37874,43,1}, /* core4 return_Stack0 bit11 */
			{37873,43,1}, /* core4 return_Stack0 bit12 */
			{37872,43,1}, /* core4 return_Stack0 bit13 */
			{37871,43,1}, /* core4 return_Stack0 bit14 */
			{37870,43,1}, /* core4 return_Stack0 bit15 */
			{37869,43,1}, /* core4 return_Stack0 bit16 */
			{32642,43,1}, /* core4 return_Stack0 bit17 */
			{37868,43,1}, /* core4 return_Stack0 bit18 */
			{32648,43,1}, /* core4 return_Stack0 bit19 */
			{32647,43,1}, /* core4 return_Stack0 bit20 */
			{32646,43,1}, /* core4 return_Stack0 bit21 */
			{32645,43,1}, /* core4 return_Stack0 bit22 */
			{32641,43,1}, /* core4 return_Stack0 bit23 */
			{26154,43,1}, /* core4 return_Stack0 bit24 */
			{26153,43,1}, /* core4 return_Stack0 bit25 */
			{28780,43,1}, /* core4 return_Stack0 bit26 */
			{28779,43,1}, /* core4 return_Stack0 bit27 */
			{32656,43,1}, /* core4 return_Stack0 bit28 */
			{32655,43,1}, /* core4 return_Stack0 bit29 */
			{32654,43,1}, /* core4 return_Stack0 bit30 */
			{26152,43,1}, /* core4 return_Stack0 bit31 */
			{32653,43,1}, /* core4 return_Stack0 bit32 */
			{28770,43,1}, /* core4 return_Stack0 bit33 */
			{28769,43,1}, /* core4 return_Stack0 bit34 */
			{25973,43,1}, /* core4 return_Stack0 bit35 */
			{28772,43,1}, /* core4 return_Stack0 bit36 */
			{28771,43,1}, /* core4 return_Stack0 bit37 */
			{32832,43,1}, /* core4 return_Stack0 bit38 */
			{32831,43,1}, /* core4 return_Stack0 bit39 */
			{32830,43,1}, /* core4 return_Stack0 bit40 */
			{32829,43,1}, /* core4 return_Stack0 bit41 */
			{25972,43,1}, /* core4 return_Stack0 bit42 */
			{28774,43,1}, /* core4 return_Stack0 bit43 */
			{28773,43,1}, /* core4 return_Stack0 bit44 */
			{28776,43,1}, /* core4 return_Stack0 bit45 */
			{28775,43,1}, /* core4 return_Stack0 bit46 */
			{28778,43,1}, /* core4 return_Stack0 bit47 */
			{28777,43,1}, /* core4 return_Stack0 bit48 */
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
			{28812,43,1}, /* core4 return_Stack1 bit0 */
			{28811,43,1}, /* core4 return_Stack1 bit1 */
			{32716,43,1}, /* core4 return_Stack1 bit2 */
			{32715,43,1}, /* core4 return_Stack1 bit3 */
			{32720,43,1}, /* core4 return_Stack1 bit4 */
			{32719,43,1}, /* core4 return_Stack1 bit5 */
			{32718,43,1}, /* core4 return_Stack1 bit6 */
			{32717,43,1}, /* core4 return_Stack1 bit7 */
			{28818,43,1}, /* core4 return_Stack1 bit8 */
			{28817,43,1}, /* core4 return_Stack1 bit9 */
			{32714,43,1}, /* core4 return_Stack1 bit10 */
			{32713,43,1}, /* core4 return_Stack1 bit11 */
			{32724,43,1}, /* core4 return_Stack1 bit12 */
			{32723,43,1}, /* core4 return_Stack1 bit13 */
			{32722,43,1}, /* core4 return_Stack1 bit14 */
			{32721,43,1}, /* core4 return_Stack1 bit15 */
			{28820,43,1}, /* core4 return_Stack1 bit16 */
			{28819,43,1}, /* core4 return_Stack1 bit17 */
			{28816,43,1}, /* core4 return_Stack1 bit18 */
			{28815,43,1}, /* core4 return_Stack1 bit19 */
			{28814,43,1}, /* core4 return_Stack1 bit20 */
			{28813,43,1}, /* core4 return_Stack1 bit21 */
			{26163,43,1}, /* core4 return_Stack1 bit22 */
			{26165,43,1}, /* core4 return_Stack1 bit23 */
			{26164,43,1}, /* core4 return_Stack1 bit24 */
			{32736,43,1}, /* core4 return_Stack1 bit25 */
			{32735,43,1}, /* core4 return_Stack1 bit26 */
			{32734,43,1}, /* core4 return_Stack1 bit27 */
			{32733,43,1}, /* core4 return_Stack1 bit28 */
			{28810,43,1}, /* core4 return_Stack1 bit29 */
			{28809,43,1}, /* core4 return_Stack1 bit30 */
			{26166,43,1}, /* core4 return_Stack1 bit31 */
			{28808,43,1}, /* core4 return_Stack1 bit32 */
			{28806,43,1}, /* core4 return_Stack1 bit33 */
			{28805,43,1}, /* core4 return_Stack1 bit34 */
			{28807,43,1}, /* core4 return_Stack1 bit35 */
			{26167,43,1}, /* core4 return_Stack1 bit36 */
			{32784,43,1}, /* core4 return_Stack1 bit37 */
			{32783,43,1}, /* core4 return_Stack1 bit38 */
			{32782,43,1}, /* core4 return_Stack1 bit39 */
			{32781,43,1}, /* core4 return_Stack1 bit40 */
			{32788,43,1}, /* core4 return_Stack1 bit41 */
			{32787,43,1}, /* core4 return_Stack1 bit42 */
			{32786,43,1}, /* core4 return_Stack1 bit43 */
			{32785,43,1}, /* core4 return_Stack1 bit44 */
			{32792,43,1}, /* core4 return_Stack1 bit45 */
			{32791,43,1}, /* core4 return_Stack1 bit46 */
			{32790,43,1}, /* core4 return_Stack1 bit47 */
			{32789,43,1}, /* core4 return_Stack1 bit48 */
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
			{28856,43,1}, /* core4 return_Stack2 bit0 */
			{28855,43,1}, /* core4 return_Stack2 bit1 */
			{28854,43,1}, /* core4 return_Stack2 bit2 */
			{28853,43,1}, /* core4 return_Stack2 bit3 */
			{32676,43,1}, /* core4 return_Stack2 bit4 */
			{32675,43,1}, /* core4 return_Stack2 bit5 */
			{32674,43,1}, /* core4 return_Stack2 bit6 */
			{32673,43,1}, /* core4 return_Stack2 bit7 */
			{32680,43,1}, /* core4 return_Stack2 bit8 */
			{32679,43,1}, /* core4 return_Stack2 bit9 */
			{32678,43,1}, /* core4 return_Stack2 bit10 */
			{32677,43,1}, /* core4 return_Stack2 bit11 */
			{28846,43,1}, /* core4 return_Stack2 bit12 */
			{28845,43,1}, /* core4 return_Stack2 bit13 */
			{28848,43,1}, /* core4 return_Stack2 bit14 */
			{28847,43,1}, /* core4 return_Stack2 bit15 */
			{28852,43,1}, /* core4 return_Stack2 bit16 */
			{28851,43,1}, /* core4 return_Stack2 bit17 */
			{28844,43,1}, /* core4 return_Stack2 bit18 */
			{28843,43,1}, /* core4 return_Stack2 bit19 */
			{28850,43,1}, /* core4 return_Stack2 bit20 */
			{28849,43,1}, /* core4 return_Stack2 bit21 */
			{26155,43,1}, /* core4 return_Stack2 bit22 */
			{26156,43,1}, /* core4 return_Stack2 bit23 */
			{26157,43,1}, /* core4 return_Stack2 bit24 */
			{32652,43,1}, /* core4 return_Stack2 bit25 */
			{32651,43,1}, /* core4 return_Stack2 bit26 */
			{32650,43,1}, /* core4 return_Stack2 bit27 */
			{32649,43,1}, /* core4 return_Stack2 bit28 */
			{32756,43,1}, /* core4 return_Stack2 bit29 */
			{32755,43,1}, /* core4 return_Stack2 bit30 */
			{32754,43,1}, /* core4 return_Stack2 bit31 */
			{32753,43,1}, /* core4 return_Stack2 bit32 */
			{32824,43,1}, /* core4 return_Stack2 bit33 */
			{32823,43,1}, /* core4 return_Stack2 bit34 */
			{32822,43,1}, /* core4 return_Stack2 bit35 */
			{32821,43,1}, /* core4 return_Stack2 bit36 */
			{32820,43,1}, /* core4 return_Stack2 bit37 */
			{32819,43,1}, /* core4 return_Stack2 bit38 */
			{32818,43,1}, /* core4 return_Stack2 bit39 */
			{32817,43,1}, /* core4 return_Stack2 bit40 */
			{32828,43,1}, /* core4 return_Stack2 bit41 */
			{32827,43,1}, /* core4 return_Stack2 bit42 */
			{32826,43,1}, /* core4 return_Stack2 bit43 */
			{32825,43,1}, /* core4 return_Stack2 bit44 */
			{32760,43,1}, /* core4 return_Stack2 bit45 */
			{32759,43,1}, /* core4 return_Stack2 bit46 */
			{32758,43,1}, /* core4 return_Stack2 bit47 */
			{32757,43,1}, /* core4 return_Stack2 bit48 */
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
			{28802,43,1}, /* core4 return_Stack3 bit0 */
			{28801,43,1}, /* core4 return_Stack3 bit1 */
			{28824,43,1}, /* core4 return_Stack3 bit2 */
			{28826,43,1}, /* core4 return_Stack3 bit3 */
			{28825,43,1}, /* core4 return_Stack3 bit4 */
			{28822,43,1}, /* core4 return_Stack3 bit5 */
			{28821,43,1}, /* core4 return_Stack3 bit6 */
			{28796,43,1}, /* core4 return_Stack3 bit7 */
			{28795,43,1}, /* core4 return_Stack3 bit8 */
			{28823,43,1}, /* core4 return_Stack3 bit9 */
			{28798,43,1}, /* core4 return_Stack3 bit10 */
			{28830,43,1}, /* core4 return_Stack3 bit11 */
			{28829,43,1}, /* core4 return_Stack3 bit12 */
			{28828,43,1}, /* core4 return_Stack3 bit13 */
			{28827,43,1}, /* core4 return_Stack3 bit14 */
			{32708,43,1}, /* core4 return_Stack3 bit15 */
			{28800,43,1}, /* core4 return_Stack3 bit16 */
			{28799,43,1}, /* core4 return_Stack3 bit17 */
			{32707,43,1}, /* core4 return_Stack3 bit18 */
			{32706,43,1}, /* core4 return_Stack3 bit19 */
			{32705,43,1}, /* core4 return_Stack3 bit20 */
			{28797,43,1}, /* core4 return_Stack3 bit21 */
			{26158,43,1}, /* core4 return_Stack3 bit22 */
			{26162,43,1}, /* core4 return_Stack3 bit23 */
			{26159,43,1}, /* core4 return_Stack3 bit24 */
			{26160,43,1}, /* core4 return_Stack3 bit25 */
			{32744,43,1}, /* core4 return_Stack3 bit26 */
			{32743,43,1}, /* core4 return_Stack3 bit27 */
			{32742,43,1}, /* core4 return_Stack3 bit28 */
			{32796,43,1}, /* core4 return_Stack3 bit29 */
			{32741,43,1}, /* core4 return_Stack3 bit30 */
			{32795,43,1}, /* core4 return_Stack3 bit31 */
			{28804,43,1}, /* core4 return_Stack3 bit32 */
			{32794,43,1}, /* core4 return_Stack3 bit33 */
			{32793,43,1}, /* core4 return_Stack3 bit34 */
			{28803,43,1}, /* core4 return_Stack3 bit35 */
			{32776,43,1}, /* core4 return_Stack3 bit36 */
			{32775,43,1}, /* core4 return_Stack3 bit37 */
			{32774,43,1}, /* core4 return_Stack3 bit38 */
			{32780,43,1}, /* core4 return_Stack3 bit39 */
			{32779,43,1}, /* core4 return_Stack3 bit40 */
			{32778,43,1}, /* core4 return_Stack3 bit41 */
			{32777,43,1}, /* core4 return_Stack3 bit42 */
			{32800,43,1}, /* core4 return_Stack3 bit43 */
			{32799,43,1}, /* core4 return_Stack3 bit44 */
			{32798,43,1}, /* core4 return_Stack3 bit45 */
			{32797,43,1}, /* core4 return_Stack3 bit46 */
			{32773,43,1}, /* core4 return_Stack3 bit47 */
			{26161,43,1}, /* core4 return_Stack3 bit48 */
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
			{32664,43,1}, /* core4 return_Stack4 bit0 */
			{32663,43,1}, /* core4 return_Stack4 bit1 */
			{32636,43,1}, /* core4 return_Stack4 bit2 */
			{32635,43,1}, /* core4 return_Stack4 bit3 */
			{28864,43,1}, /* core4 return_Stack4 bit4 */
			{28863,43,1}, /* core4 return_Stack4 bit5 */
			{32640,43,1}, /* core4 return_Stack4 bit6 */
			{32639,43,1}, /* core4 return_Stack4 bit7 */
			{32638,43,1}, /* core4 return_Stack4 bit8 */
			{32637,43,1}, /* core4 return_Stack4 bit9 */
			{32634,43,1}, /* core4 return_Stack4 bit10 */
			{32633,43,1}, /* core4 return_Stack4 bit11 */
			{28862,43,1}, /* core4 return_Stack4 bit12 */
			{28861,43,1}, /* core4 return_Stack4 bit13 */
			{32668,43,1}, /* core4 return_Stack4 bit14 */
			{32667,43,1}, /* core4 return_Stack4 bit15 */
			{32662,43,1}, /* core4 return_Stack4 bit16 */
			{32661,43,1}, /* core4 return_Stack4 bit17 */
			{32666,43,1}, /* core4 return_Stack4 bit18 */
			{32665,43,1}, /* core4 return_Stack4 bit19 */
			{28866,43,1}, /* core4 return_Stack4 bit20 */
			{28865,43,1}, /* core4 return_Stack4 bit21 */
			{28868,43,1}, /* core4 return_Stack4 bit22 */
			{28867,43,1}, /* core4 return_Stack4 bit23 */
			{26150,43,1}, /* core4 return_Stack4 bit24 */
			{26151,43,1}, /* core4 return_Stack4 bit25 */
			{32660,43,1}, /* core4 return_Stack4 bit26 */
			{32659,43,1}, /* core4 return_Stack4 bit27 */
			{32658,43,1}, /* core4 return_Stack4 bit28 */
			{32844,43,1}, /* core4 return_Stack4 bit29 */
			{32843,43,1}, /* core4 return_Stack4 bit30 */
			{32842,43,1}, /* core4 return_Stack4 bit31 */
			{32657,43,1}, /* core4 return_Stack4 bit32 */
			{25971,43,1}, /* core4 return_Stack4 bit33 */
			{32841,43,1}, /* core4 return_Stack4 bit34 */
			{32840,43,1}, /* core4 return_Stack4 bit35 */
			{32839,43,1}, /* core4 return_Stack4 bit36 */
			{32838,43,1}, /* core4 return_Stack4 bit37 */
			{32837,43,1}, /* core4 return_Stack4 bit38 */
			{32836,43,1}, /* core4 return_Stack4 bit39 */
			{32835,43,1}, /* core4 return_Stack4 bit40 */
			{32834,43,1}, /* core4 return_Stack4 bit41 */
			{32833,43,1}, /* core4 return_Stack4 bit42 */
			{25970,43,1}, /* core4 return_Stack4 bit43 */
			{28872,43,1}, /* core4 return_Stack4 bit44 */
			{28871,43,1}, /* core4 return_Stack4 bit45 */
			{28870,43,1}, /* core4 return_Stack4 bit46 */
			{28869,43,1}, /* core4 return_Stack4 bit47 */
			{25969,43,1}, /* core4 return_Stack4 bit48 */
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
			{28790,43,1}, /* core4 return_Stack5 bit0 */
			{28789,43,1}, /* core4 return_Stack5 bit1 */
			{32696,43,1}, /* core4 return_Stack5 bit2 */
			{32695,43,1}, /* core4 return_Stack5 bit3 */
			{28794,43,1}, /* core4 return_Stack5 bit4 */
			{28793,43,1}, /* core4 return_Stack5 bit5 */
			{32692,43,1}, /* core4 return_Stack5 bit6 */
			{32691,43,1}, /* core4 return_Stack5 bit7 */
			{32690,43,1}, /* core4 return_Stack5 bit8 */
			{32689,43,1}, /* core4 return_Stack5 bit9 */
			{32694,43,1}, /* core4 return_Stack5 bit10 */
			{32693,43,1}, /* core4 return_Stack5 bit11 */
			{32700,43,1}, /* core4 return_Stack5 bit12 */
			{32699,43,1}, /* core4 return_Stack5 bit13 */
			{28792,43,1}, /* core4 return_Stack5 bit14 */
			{28791,43,1}, /* core4 return_Stack5 bit15 */
			{28788,43,1}, /* core4 return_Stack5 bit16 */
			{28787,43,1}, /* core4 return_Stack5 bit17 */
			{32698,43,1}, /* core4 return_Stack5 bit18 */
			{32704,43,1}, /* core4 return_Stack5 bit19 */
			{32703,43,1}, /* core4 return_Stack5 bit20 */
			{32702,43,1}, /* core4 return_Stack5 bit21 */
			{32697,43,1}, /* core4 return_Stack5 bit22 */
			{28786,43,1}, /* core4 return_Stack5 bit23 */
			{32701,43,1}, /* core4 return_Stack5 bit24 */
			{28785,43,1}, /* core4 return_Stack5 bit25 */
			{32752,43,1}, /* core4 return_Stack5 bit26 */
			{25968,43,1}, /* core4 return_Stack5 bit27 */
			{32751,43,1}, /* core4 return_Stack5 bit28 */
			{32750,43,1}, /* core4 return_Stack5 bit29 */
			{32749,43,1}, /* core4 return_Stack5 bit30 */
			{32808,43,1}, /* core4 return_Stack5 bit31 */
			{32807,43,1}, /* core4 return_Stack5 bit32 */
			{32806,43,1}, /* core4 return_Stack5 bit33 */
			{32805,43,1}, /* core4 return_Stack5 bit34 */
			{32812,43,1}, /* core4 return_Stack5 bit35 */
			{32811,43,1}, /* core4 return_Stack5 bit36 */
			{32810,43,1}, /* core4 return_Stack5 bit37 */
			{32809,43,1}, /* core4 return_Stack5 bit38 */
			{32804,43,1}, /* core4 return_Stack5 bit39 */
			{32803,43,1}, /* core4 return_Stack5 bit40 */
			{32802,43,1}, /* core4 return_Stack5 bit41 */
			{32801,43,1}, /* core4 return_Stack5 bit42 */
			{32816,43,1}, /* core4 return_Stack5 bit43 */
			{32815,43,1}, /* core4 return_Stack5 bit44 */
			{32814,43,1}, /* core4 return_Stack5 bit45 */
			{32813,43,1}, /* core4 return_Stack5 bit46 */
			{25955,43,1}, /* core4 return_Stack5 bit47 */
			{25956,43,1}, /* core4 return_Stack5 bit48 */
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
			{28784,43,1}, /* core4 return_Stack6 bit0 */
			{28783,43,1}, /* core4 return_Stack6 bit1 */
			{28838,43,1}, /* core4 return_Stack6 bit2 */
			{32688,43,1}, /* core4 return_Stack6 bit3 */
			{28837,43,1}, /* core4 return_Stack6 bit4 */
			{32687,43,1}, /* core4 return_Stack6 bit5 */
			{32686,43,1}, /* core4 return_Stack6 bit6 */
			{32685,43,1}, /* core4 return_Stack6 bit7 */
			{28834,43,1}, /* core4 return_Stack6 bit8 */
			{28833,43,1}, /* core4 return_Stack6 bit9 */
			{32684,43,1}, /* core4 return_Stack6 bit10 */
			{32683,43,1}, /* core4 return_Stack6 bit11 */
			{32682,43,1}, /* core4 return_Stack6 bit12 */
			{32681,43,1}, /* core4 return_Stack6 bit13 */
			{28840,43,1}, /* core4 return_Stack6 bit14 */
			{28839,43,1}, /* core4 return_Stack6 bit15 */
			{28836,43,1}, /* core4 return_Stack6 bit16 */
			{28835,43,1}, /* core4 return_Stack6 bit17 */
			{28842,43,1}, /* core4 return_Stack6 bit18 */
			{28841,43,1}, /* core4 return_Stack6 bit19 */
			{28832,43,1}, /* core4 return_Stack6 bit20 */
			{28831,43,1}, /* core4 return_Stack6 bit21 */
			{25960,43,1}, /* core4 return_Stack6 bit22 */
			{25959,43,1}, /* core4 return_Stack6 bit23 */
			{25967,43,1}, /* core4 return_Stack6 bit24 */
			{25966,43,1}, /* core4 return_Stack6 bit25 */
			{32748,43,1}, /* core4 return_Stack6 bit26 */
			{32747,43,1}, /* core4 return_Stack6 bit27 */
			{28782,43,1}, /* core4 return_Stack6 bit28 */
			{32746,43,1}, /* core4 return_Stack6 bit29 */
			{32745,43,1}, /* core4 return_Stack6 bit30 */
			{28781,43,1}, /* core4 return_Stack6 bit31 */
			{25958,43,1}, /* core4 return_Stack6 bit32 */
			{28680,43,1}, /* core4 return_Stack6 bit33 */
			{28679,43,1}, /* core4 return_Stack6 bit34 */
			{25954,43,1}, /* core4 return_Stack6 bit35 */
			{25957,43,1}, /* core4 return_Stack6 bit36 */
			{28678,43,1}, /* core4 return_Stack6 bit37 */
			{28677,43,1}, /* core4 return_Stack6 bit38 */
			{32764,43,1}, /* core4 return_Stack6 bit39 */
			{32763,43,1}, /* core4 return_Stack6 bit40 */
			{32762,43,1}, /* core4 return_Stack6 bit41 */
			{32761,43,1}, /* core4 return_Stack6 bit42 */
			{28676,43,1}, /* core4 return_Stack6 bit43 */
			{28675,43,1}, /* core4 return_Stack6 bit44 */
			{28664,43,1}, /* core4 return_Stack6 bit45 */
			{28663,43,1}, /* core4 return_Stack6 bit46 */
			{28662,43,1}, /* core4 return_Stack6 bit47 */
			{28661,43,1}, /* core4 return_Stack6 bit48 */
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
			{32712,43,1}, /* core4 return_Stack7 bit0 */
			{32711,43,1}, /* core4 return_Stack7 bit1 */
			{32732,43,1}, /* core4 return_Stack7 bit2 */
			{32731,43,1}, /* core4 return_Stack7 bit3 */
			{32730,43,1}, /* core4 return_Stack7 bit4 */
			{32729,43,1}, /* core4 return_Stack7 bit5 */
			{28652,43,1}, /* core4 return_Stack7 bit6 */
			{28651,43,1}, /* core4 return_Stack7 bit7 */
			{28654,43,1}, /* core4 return_Stack7 bit8 */
			{28653,43,1}, /* core4 return_Stack7 bit9 */
			{32728,43,1}, /* core4 return_Stack7 bit10 */
			{32727,43,1}, /* core4 return_Stack7 bit11 */
			{28650,43,1}, /* core4 return_Stack7 bit12 */
			{28649,43,1}, /* core4 return_Stack7 bit13 */
			{32710,43,1}, /* core4 return_Stack7 bit14 */
			{32726,43,1}, /* core4 return_Stack7 bit15 */
			{32709,43,1}, /* core4 return_Stack7 bit16 */
			{32725,43,1}, /* core4 return_Stack7 bit17 */
			{28656,43,1}, /* core4 return_Stack7 bit18 */
			{28655,43,1}, /* core4 return_Stack7 bit19 */
			{28658,43,1}, /* core4 return_Stack7 bit20 */
			{28657,43,1}, /* core4 return_Stack7 bit21 */
			{25961,43,1}, /* core4 return_Stack7 bit22 */
			{25962,43,1}, /* core4 return_Stack7 bit23 */
			{25963,43,1}, /* core4 return_Stack7 bit24 */
			{25965,43,1}, /* core4 return_Stack7 bit25 */
			{28660,43,1}, /* core4 return_Stack7 bit26 */
			{32740,43,1}, /* core4 return_Stack7 bit27 */
			{28659,43,1}, /* core4 return_Stack7 bit28 */
			{32739,43,1}, /* core4 return_Stack7 bit29 */
			{32738,43,1}, /* core4 return_Stack7 bit30 */
			{32737,43,1}, /* core4 return_Stack7 bit31 */
			{32768,43,1}, /* core4 return_Stack7 bit32 */
			{32767,43,1}, /* core4 return_Stack7 bit33 */
			{32766,43,1}, /* core4 return_Stack7 bit34 */
			{32765,43,1}, /* core4 return_Stack7 bit35 */
			{28670,43,1}, /* core4 return_Stack7 bit36 */
			{28669,43,1}, /* core4 return_Stack7 bit37 */
			{28672,43,1}, /* core4 return_Stack7 bit38 */
			{28671,43,1}, /* core4 return_Stack7 bit39 */
			{32772,43,1}, /* core4 return_Stack7 bit40 */
			{32771,43,1}, /* core4 return_Stack7 bit41 */
			{32770,43,1}, /* core4 return_Stack7 bit42 */
			{32769,43,1}, /* core4 return_Stack7 bit43 */
			{28666,43,1}, /* core4 return_Stack7 bit44 */
			{28665,43,1}, /* core4 return_Stack7 bit45 */
			{28668,43,1}, /* core4 return_Stack7 bit46 */
			{28667,43,1}, /* core4 return_Stack7 bit47 */
			{25964,43,1}, /* core4 return_Stack7 bit48 */
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
			{ 5741, 8,0}, /* core4 L2_parity_err_count bit0 */
			{ 5153, 8,0}, /* core4 L2_parity_err_count bit1 */
			{ 5152, 8,0}, /* core4 L2_parity_err_count bit2 */
			{ 5151, 8,0}, /* core4 L2_parity_err_count bit3 */
			{ 5015, 8,0}, /* core4 L2_parity_err_count bit4 */
			{ 5150, 8,0}, /* core4 L2_parity_err_count bit5 */
			{ 5149, 8,0}, /* core4 L2_parity_err_count bit6 */
			{ 5148, 8,0}, /* core4 L2_parity_err_count bit7 */
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
			{ 5604, 8,0}, /* core4 L2_parity_index bit0 */
			{ 5603, 8,0}, /* core4 L2_parity_index bit1 */
			{ 5602, 8,0}, /* core4 L2_parity_index bit2 */
			{ 5601, 8,0}, /* core4 L2_parity_index bit3 */
			{ 5600, 8,0}, /* core4 L2_parity_index bit4 */
			{ 5599, 8,0}, /* core4 L2_parity_index bit5 */
			{ 5598, 8,0}, /* core4 L2_parity_index bit6 */
			{ 5597, 8,0}, /* core4 L2_parity_index bit7 */
			{ 5596, 8,0}, /* core4 L2_parity_index bit8 */
			{ 5595, 8,0}, /* core4 L2_parity_index bit9 */
			{ 5594, 8,0}, /* core4 L2_parity_index bit10 */
			{ 5593, 8,0}, /* core4 L2_parity_index bit11 */
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
			{ 5589, 8,0}, /* core4 L2_parity_way bit0 */
			{ 5127, 8,0}, /* core4 L2_parity_way bit1 */
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
			{ 5740, 8,0}, /* core4 L2_parity_banks bit0 */
			{ 5739, 8,0}, /* core4 L2_parity_banks bit1 */
			{ 5738, 8,0}, /* core4 L2_parity_banks bit2 */
			{ 5737, 8,0}, /* core4 L2_parity_banks bit3 */
			{ 5736, 8,0}, /* core4 L2_parity_banks bit4 */
			{ 5735, 8,0}, /* core4 L2_parity_banks bit5 */
			{ 5734, 8,0}, /* core4 L2_parity_banks bit6 */
			{ 5733, 8,0}, /* core4 L2_parity_banks bit7 */
			{ 5748, 8,0}, /* core4 L2_parity_banks bit8 */
			{ 5747, 8,0}, /* core4 L2_parity_banks bit9 */
			{ 5746, 8,0}, /* core4 L2_parity_banks bit10 */
			{ 5745, 8,0}, /* core4 L2_parity_banks bit11 */
			{ 5016, 8,0}, /* core4 L2_parity_banks bit12 */
			{ 5744, 8,0}, /* core4 L2_parity_banks bit13 */
			{ 5743, 8,0}, /* core4 L2_parity_banks bit14 */
			{ 5742, 8,0}, /* core4 L2_parity_banks bit15 */
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
			{   95,44,1}, /* core5 pc bit0 */
			{  433,44,1}, /* core5 pc bit1 */
			{  432,44,1}, /* core5 pc bit2 */
			{  431,44,1}, /* core5 pc bit3 */
			{  430,44,1}, /* core5 pc bit4 */
			{  429,44,1}, /* core5 pc bit5 */
			{  495,44,1}, /* core5 pc bit6 */
			{  426,44,1}, /* core5 pc bit7 */
			{  494,44,1}, /* core5 pc bit8 */
			{  425,44,1}, /* core5 pc bit9 */
			{  424,44,1}, /* core5 pc bit10 */
			{  445,44,1}, /* core5 pc bit11 */
			{  493,44,1}, /* core5 pc bit12 */
			{  492,44,1}, /* core5 pc bit13 */
			{  444,44,1}, /* core5 pc bit14 */
			{  443,44,1}, /* core5 pc bit15 */
			{  466,44,1}, /* core5 pc bit16 */
			{  482,44,1}, /* core5 pc bit17 */
			{  465,44,1}, /* core5 pc bit18 */
			{  464,44,1}, /* core5 pc bit19 */
			{  470,44,1}, /* core5 pc bit20 */
			{  463,44,1}, /* core5 pc bit21 */
			{  440,44,1}, /* core5 pc bit22 */
			{  446,44,1}, /* core5 pc bit23 */
			{  491,44,1}, /* core5 pc bit24 */
			{  462,44,1}, /* core5 pc bit25 */
			{  481,44,1}, /* core5 pc bit26 */
			{  480,44,1}, /* core5 pc bit27 */
			{  461,44,1}, /* core5 pc bit28 */
			{  460,44,1}, /* core5 pc bit29 */
			{  448,44,1}, /* core5 pc bit30 */
			{  450,44,1}, /* core5 pc bit31 */
			{  270,44,1}, /* core5 pc bit32 */
			{  269,44,1}, /* core5 pc bit33 */
			{  268,44,1}, /* core5 pc bit34 */
			{  278,44,1}, /* core5 pc bit35 */
			{  320,44,1}, /* core5 pc bit36 */
			{  267,44,1}, /* core5 pc bit37 */
			{  266,44,1}, /* core5 pc bit38 */
			{  312,44,1}, /* core5 pc bit39 */
			{  162,44,1}, /* core5 pc bit40 */
			{  319,44,1}, /* core5 pc bit41 */
			{  318,44,1}, /* core5 pc bit42 */
			{  161,44,1}, /* core5 pc bit43 */
			{  160,44,1}, /* core5 pc bit44 */
			{  159,44,1}, /* core5 pc bit45 */
			{  317,44,1}, /* core5 pc bit46 */
			{  316,44,1}, /* core5 pc bit47 */
			{  140,44,1}, /* core5 pc bit48 */
			{  277,44,1}, /* core5 pc bit49 */
			{  276,44,1}, /* core5 pc bit50 */
			{  275,44,1}, /* core5 pc bit51 */
			{  274,44,1}, /* core5 pc bit52 */
			{  139,44,1}, /* core5 pc bit53 */
			{  280,44,1}, /* core5 pc bit54 */
			{  279,44,1}, /* core5 pc bit55 */
			{  353,44,1}, /* core5 pc bit56 */
			{  273,44,1}, /* core5 pc bit57 */
			{  288,44,1}, /* core5 pc bit58 */
			{  287,44,1}, /* core5 pc bit59 */
			{  138,44,1}, /* core5 pc bit60 */
			{  264,44,1}, /* core5 pc bit61 */
			{  263,44,1}, /* core5 pc bit62 */
			{  145,44,1}, /* core5 pc bit63 */
			}},
			.sp32 = {{
			{41179,45,1}, /* core5 sp32 bit0 */
			{41177,45,1}, /* core5 sp32 bit1 */
			{41176,45,1}, /* core5 sp32 bit2 */
			{41175,45,1}, /* core5 sp32 bit3 */
			{41178,45,1}, /* core5 sp32 bit4 */
			{41171,45,1}, /* core5 sp32 bit5 */
			{41170,45,1}, /* core5 sp32 bit6 */
			{41172,45,1}, /* core5 sp32 bit7 */
			{41173,45,1}, /* core5 sp32 bit8 */
			{41174,45,1}, /* core5 sp32 bit9 */
			{41197,45,1}, /* core5 sp32 bit10 */
			{41190,45,1}, /* core5 sp32 bit11 */
			{41182,45,1}, /* core5 sp32 bit12 */
			{41201,45,1}, /* core5 sp32 bit13 */
			{41184,45,1}, /* core5 sp32 bit14 */
			{41198,45,1}, /* core5 sp32 bit15 */
			{34300,44,0}, /* core5 sp32 bit16 */
			{34299,44,0}, /* core5 sp32 bit17 */
			{34328,44,0}, /* core5 sp32 bit18 */
			{34327,44,0}, /* core5 sp32 bit19 */
			{41196,45,1}, /* core5 sp32 bit20 */
			{41185,45,1}, /* core5 sp32 bit21 */
			{41227,45,1}, /* core5 sp32 bit22 */
			{41226,45,1}, /* core5 sp32 bit23 */
			{41180,45,1}, /* core5 sp32 bit24 */
			{41181,45,1}, /* core5 sp32 bit25 */
			{41183,45,1}, /* core5 sp32 bit26 */
			{41186,45,1}, /* core5 sp32 bit27 */
			{41199,45,1}, /* core5 sp32 bit28 */
			{41191,45,1}, /* core5 sp32 bit29 */
			{41188,45,1}, /* core5 sp32 bit30 */
			{41189,45,1}, /* core5 sp32 bit31 */
			{41121,45,1}, /* core5 sp32 bit32 */
			{41123,45,1}, /* core5 sp32 bit33 */
			{41113,45,1}, /* core5 sp32 bit34 */
			{41115,45,1}, /* core5 sp32 bit35 */
			{41120,45,1}, /* core5 sp32 bit36 */
			{41118,45,1}, /* core5 sp32 bit37 */
			{41122,45,1}, /* core5 sp32 bit38 */
			{41117,45,1}, /* core5 sp32 bit39 */
			{41116,45,1}, /* core5 sp32 bit40 */
			{41119,45,1}, /* core5 sp32 bit41 */
			{41108,45,1}, /* core5 sp32 bit42 */
			{41109,45,1}, /* core5 sp32 bit43 */
			{41110,45,1}, /* core5 sp32 bit44 */
			{41114,45,1}, /* core5 sp32 bit45 */
			{41111,45,1}, /* core5 sp32 bit46 */
			{41112,45,1}, /* core5 sp32 bit47 */
			{41159,45,1}, /* core5 sp32 bit48 */
			{41164,45,1}, /* core5 sp32 bit49 */
			{34350,44,0}, /* core5 sp32 bit50 */
			{34349,44,0}, /* core5 sp32 bit51 */
			{41166,45,1}, /* core5 sp32 bit52 */
			{41165,45,1}, /* core5 sp32 bit53 */
			{41163,45,1}, /* core5 sp32 bit54 */
			{41161,45,1}, /* core5 sp32 bit55 */
			{41167,45,1}, /* core5 sp32 bit56 */
			{41160,45,1}, /* core5 sp32 bit57 */
			{41162,45,1}, /* core5 sp32 bit58 */
			{41158,45,1}, /* core5 sp32 bit59 */
			{41157,45,1}, /* core5 sp32 bit60 */
			{41155,45,1}, /* core5 sp32 bit61 */
			{41154,45,1}, /* core5 sp32 bit62 */
			{41156,45,1}, /* core5 sp32 bit63 */
			}},
			.fp32 = {{
			{41650,45,1}, /* core5 fp32 bit0 */
			{41651,45,1}, /* core5 fp32 bit1 */
			{41648,45,1}, /* core5 fp32 bit2 */
			{41645,45,1}, /* core5 fp32 bit3 */
			{41652,45,1}, /* core5 fp32 bit4 */
			{41647,45,1}, /* core5 fp32 bit5 */
			{41644,45,1}, /* core5 fp32 bit6 */
			{41646,45,1}, /* core5 fp32 bit7 */
			{41643,45,1}, /* core5 fp32 bit8 */
			{41642,45,1}, /* core5 fp32 bit9 */
			{41676,45,1}, /* core5 fp32 bit10 */
			{41675,45,1}, /* core5 fp32 bit11 */
			{41685,45,1}, /* core5 fp32 bit12 */
			{41684,45,1}, /* core5 fp32 bit13 */
			{41680,45,1}, /* core5 fp32 bit14 */
			{41681,45,1}, /* core5 fp32 bit15 */
			{41682,45,1}, /* core5 fp32 bit16 */
			{41656,45,1}, /* core5 fp32 bit17 */
			{41678,45,1}, /* core5 fp32 bit18 */
			{41683,45,1}, /* core5 fp32 bit19 */
			{41677,45,1}, /* core5 fp32 bit20 */
			{41672,45,1}, /* core5 fp32 bit21 */
			{41686,45,1}, /* core5 fp32 bit22 */
			{41649,45,1}, /* core5 fp32 bit23 */
			{41688,45,1}, /* core5 fp32 bit24 */
			{41689,45,1}, /* core5 fp32 bit25 */
			{41669,45,1}, /* core5 fp32 bit26 */
			{41670,45,1}, /* core5 fp32 bit27 */
			{41673,45,1}, /* core5 fp32 bit28 */
			{41679,45,1}, /* core5 fp32 bit29 */
			{41674,45,1}, /* core5 fp32 bit30 */
			{41671,45,1}, /* core5 fp32 bit31 */
			{41580,45,1}, /* core5 fp32 bit32 */
			{41589,45,1}, /* core5 fp32 bit33 */
			{41583,45,1}, /* core5 fp32 bit34 */
			{41587,45,1}, /* core5 fp32 bit35 */
			{41582,45,1}, /* core5 fp32 bit36 */
			{41575,45,1}, /* core5 fp32 bit37 */
			{41576,45,1}, /* core5 fp32 bit38 */
			{41585,45,1}, /* core5 fp32 bit39 */
			{41584,45,1}, /* core5 fp32 bit40 */
			{41581,45,1}, /* core5 fp32 bit41 */
			{41588,45,1}, /* core5 fp32 bit42 */
			{41577,45,1}, /* core5 fp32 bit43 */
			{41578,45,1}, /* core5 fp32 bit44 */
			{41579,45,1}, /* core5 fp32 bit45 */
			{41574,45,1}, /* core5 fp32 bit46 */
			{41586,45,1}, /* core5 fp32 bit47 */
			{41605,45,1}, /* core5 fp32 bit48 */
			{41604,45,1}, /* core5 fp32 bit49 */
			{41606,45,1}, /* core5 fp32 bit50 */
			{41609,45,1}, /* core5 fp32 bit51 */
			{41607,45,1}, /* core5 fp32 bit52 */
			{41610,45,1}, /* core5 fp32 bit53 */
			{41602,45,1}, /* core5 fp32 bit54 */
			{41597,45,1}, /* core5 fp32 bit55 */
			{41608,45,1}, /* core5 fp32 bit56 */
			{41598,45,1}, /* core5 fp32 bit57 */
			{41601,45,1}, /* core5 fp32 bit58 */
			{41596,45,1}, /* core5 fp32 bit59 */
			{41593,45,1}, /* core5 fp32 bit60 */
			{34376,44,0}, /* core5 fp32 bit61 */
			{34375,44,0}, /* core5 fp32 bit62 */
			{41594,45,1}, /* core5 fp32 bit63 */
			}},
			.fp64 = {{
			{40573,45,1}, /* core5 fp64 bit0 */
			{40571,45,1}, /* core5 fp64 bit1 */
			{40569,45,1}, /* core5 fp64 bit2 */
			{34306,44,0}, /* core5 fp64 bit3 */
			{34305,44,0}, /* core5 fp64 bit4 */
			{40567,45,1}, /* core5 fp64 bit5 */
			{40568,45,1}, /* core5 fp64 bit6 */
			{34304,44,0}, /* core5 fp64 bit7 */
			{34303,44,0}, /* core5 fp64 bit8 */
			{40570,45,1}, /* core5 fp64 bit9 */
			{40560,45,1}, /* core5 fp64 bit10 */
			{40558,45,1}, /* core5 fp64 bit11 */
			{40566,45,1}, /* core5 fp64 bit12 */
			{40565,45,1}, /* core5 fp64 bit13 */
			{40564,45,1}, /* core5 fp64 bit14 */
			{40559,45,1}, /* core5 fp64 bit15 */
			{40554,45,1}, /* core5 fp64 bit16 */
			{40490,45,1}, /* core5 fp64 bit17 */
			{40552,45,1}, /* core5 fp64 bit18 */
			{40555,45,1}, /* core5 fp64 bit19 */
			{40557,45,1}, /* core5 fp64 bit20 */
			{40553,45,1}, /* core5 fp64 bit21 */
			{40572,45,1}, /* core5 fp64 bit22 */
			{40491,45,1}, /* core5 fp64 bit23 */
			{40492,45,1}, /* core5 fp64 bit24 */
			{40493,45,1}, /* core5 fp64 bit25 */
			{40563,45,1}, /* core5 fp64 bit26 */
			{34322,44,0}, /* core5 fp64 bit27 */
			{34321,44,0}, /* core5 fp64 bit28 */
			{40562,45,1}, /* core5 fp64 bit29 */
			{40561,45,1}, /* core5 fp64 bit30 */
			{40556,45,1}, /* core5 fp64 bit31 */
			{40702,45,1}, /* core5 fp64 bit32 */
			{40697,45,1}, /* core5 fp64 bit33 */
			{40699,45,1}, /* core5 fp64 bit34 */
			{40708,45,1}, /* core5 fp64 bit35 */
			{40706,45,1}, /* core5 fp64 bit36 */
			{40701,45,1}, /* core5 fp64 bit37 */
			{40703,45,1}, /* core5 fp64 bit38 */
			{40705,45,1}, /* core5 fp64 bit39 */
			{40704,45,1}, /* core5 fp64 bit40 */
			{40698,45,1}, /* core5 fp64 bit41 */
			{40707,45,1}, /* core5 fp64 bit42 */
			{40700,45,1}, /* core5 fp64 bit43 */
			{40709,45,1}, /* core5 fp64 bit44 */
			{40696,45,1}, /* core5 fp64 bit45 */
			{40727,45,1}, /* core5 fp64 bit46 */
			{40695,45,1}, /* core5 fp64 bit47 */
			{40690,45,1}, /* core5 fp64 bit48 */
			{40638,45,1}, /* core5 fp64 bit49 */
			{40642,45,1}, /* core5 fp64 bit50 */
			{40645,45,1}, /* core5 fp64 bit51 */
			{40644,45,1}, /* core5 fp64 bit52 */
			{40643,45,1}, /* core5 fp64 bit53 */
			{40637,45,1}, /* core5 fp64 bit54 */
			{40632,45,1}, /* core5 fp64 bit55 */
			{40646,45,1}, /* core5 fp64 bit56 */
			{40633,45,1}, /* core5 fp64 bit57 */
			{40635,45,1}, /* core5 fp64 bit58 */
			{40691,45,1}, /* core5 fp64 bit59 */
			{40693,45,1}, /* core5 fp64 bit60 */
			{40726,45,1}, /* core5 fp64 bit61 */
			{40692,45,1}, /* core5 fp64 bit62 */
			{40694,45,1}, /* core5 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{40577,45,1}, /* core5 sp_EL0 bit0 */
			{40575,45,1}, /* core5 sp_EL0 bit1 */
			{40580,45,1}, /* core5 sp_EL0 bit2 */
			{40582,45,1}, /* core5 sp_EL0 bit3 */
			{40583,45,1}, /* core5 sp_EL0 bit4 */
			{40581,45,1}, /* core5 sp_EL0 bit5 */
			{34278,44,0}, /* core5 sp_EL0 bit6 */
			{34277,44,0}, /* core5 sp_EL0 bit7 */
			{40578,45,1}, /* core5 sp_EL0 bit8 */
			{40576,45,1}, /* core5 sp_EL0 bit9 */
			{40488,45,1}, /* core5 sp_EL0 bit10 */
			{40487,45,1}, /* core5 sp_EL0 bit11 */
			{34276,44,0}, /* core5 sp_EL0 bit12 */
			{34275,44,0}, /* core5 sp_EL0 bit13 */
			{40579,45,1}, /* core5 sp_EL0 bit14 */
			{40574,45,1}, /* core5 sp_EL0 bit15 */
			{34284,44,0}, /* core5 sp_EL0 bit16 */
			{34283,44,0}, /* core5 sp_EL0 bit17 */
			{40489,45,1}, /* core5 sp_EL0 bit18 */
			{40486,45,1}, /* core5 sp_EL0 bit19 */
			{40485,45,1}, /* core5 sp_EL0 bit20 */
			{40484,45,1}, /* core5 sp_EL0 bit21 */
			{40306,45,1}, /* core5 sp_EL0 bit22 */
			{40302,45,1}, /* core5 sp_EL0 bit23 */
			{40304,45,1}, /* core5 sp_EL0 bit24 */
			{40305,45,1}, /* core5 sp_EL0 bit25 */
			{40282,45,1}, /* core5 sp_EL0 bit26 */
			{40283,45,1}, /* core5 sp_EL0 bit27 */
			{40285,45,1}, /* core5 sp_EL0 bit28 */
			{40284,45,1}, /* core5 sp_EL0 bit29 */
			{40286,45,1}, /* core5 sp_EL0 bit30 */
			{40303,45,1}, /* core5 sp_EL0 bit31 */
			{40436,45,1}, /* core5 sp_EL0 bit32 */
			{40434,45,1}, /* core5 sp_EL0 bit33 */
			{40440,45,1}, /* core5 sp_EL0 bit34 */
			{40437,45,1}, /* core5 sp_EL0 bit35 */
			{40427,45,1}, /* core5 sp_EL0 bit36 */
			{40428,45,1}, /* core5 sp_EL0 bit37 */
			{40431,45,1}, /* core5 sp_EL0 bit38 */
			{40429,45,1}, /* core5 sp_EL0 bit39 */
			{40430,45,1}, /* core5 sp_EL0 bit40 */
			{40441,45,1}, /* core5 sp_EL0 bit41 */
			{40433,45,1}, /* core5 sp_EL0 bit42 */
			{40432,45,1}, /* core5 sp_EL0 bit43 */
			{40439,45,1}, /* core5 sp_EL0 bit44 */
			{40438,45,1}, /* core5 sp_EL0 bit45 */
			{40443,45,1}, /* core5 sp_EL0 bit46 */
			{40442,45,1}, /* core5 sp_EL0 bit47 */
			{40456,45,1}, /* core5 sp_EL0 bit48 */
			{34430,44,0}, /* core5 sp_EL0 bit49 */
			{34426,44,0}, /* core5 sp_EL0 bit50 */
			{34425,44,0}, /* core5 sp_EL0 bit51 */
			{34432,44,0}, /* core5 sp_EL0 bit52 */
			{34431,44,0}, /* core5 sp_EL0 bit53 */
			{34429,44,0}, /* core5 sp_EL0 bit54 */
			{40446,45,1}, /* core5 sp_EL0 bit55 */
			{36696,44,0}, /* core5 sp_EL0 bit56 */
			{36695,44,0}, /* core5 sp_EL0 bit57 */
			{36694,44,0}, /* core5 sp_EL0 bit58 */
			{36693,44,0}, /* core5 sp_EL0 bit59 */
			{40445,45,1}, /* core5 sp_EL0 bit60 */
			{40444,45,1}, /* core5 sp_EL0 bit61 */
			{34392,44,0}, /* core5 sp_EL0 bit62 */
			{34391,44,0}, /* core5 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{40312,45,1}, /* core5 sp_EL1 bit0 */
			{40319,45,1}, /* core5 sp_EL1 bit1 */
			{40314,45,1}, /* core5 sp_EL1 bit2 */
			{40315,45,1}, /* core5 sp_EL1 bit3 */
			{34236,44,0}, /* core5 sp_EL1 bit4 */
			{34235,44,0}, /* core5 sp_EL1 bit5 */
			{34238,44,0}, /* core5 sp_EL1 bit6 */
			{34237,44,0}, /* core5 sp_EL1 bit7 */
			{40313,45,1}, /* core5 sp_EL1 bit8 */
			{40316,45,1}, /* core5 sp_EL1 bit9 */
			{40336,45,1}, /* core5 sp_EL1 bit10 */
			{40333,45,1}, /* core5 sp_EL1 bit11 */
			{40311,45,1}, /* core5 sp_EL1 bit12 */
			{40308,45,1}, /* core5 sp_EL1 bit13 */
			{40331,45,1}, /* core5 sp_EL1 bit14 */
			{40330,45,1}, /* core5 sp_EL1 bit15 */
			{34216,44,0}, /* core5 sp_EL1 bit16 */
			{34215,44,0}, /* core5 sp_EL1 bit17 */
			{40348,45,1}, /* core5 sp_EL1 bit18 */
			{40349,45,1}, /* core5 sp_EL1 bit19 */
			{40350,45,1}, /* core5 sp_EL1 bit20 */
			{40346,45,1}, /* core5 sp_EL1 bit21 */
			{40332,45,1}, /* core5 sp_EL1 bit22 */
			{40334,45,1}, /* core5 sp_EL1 bit23 */
			{40335,45,1}, /* core5 sp_EL1 bit24 */
			{40347,45,1}, /* core5 sp_EL1 bit25 */
			{40320,45,1}, /* core5 sp_EL1 bit26 */
			{40321,45,1}, /* core5 sp_EL1 bit27 */
			{40310,45,1}, /* core5 sp_EL1 bit28 */
			{40309,45,1}, /* core5 sp_EL1 bit29 */
			{40307,45,1}, /* core5 sp_EL1 bit30 */
			{40345,45,1}, /* core5 sp_EL1 bit31 */
			{40406,45,1}, /* core5 sp_EL1 bit32 */
			{40405,45,1}, /* core5 sp_EL1 bit33 */
			{40386,45,1}, /* core5 sp_EL1 bit34 */
			{40383,45,1}, /* core5 sp_EL1 bit35 */
			{40422,45,1}, /* core5 sp_EL1 bit36 */
			{40421,45,1}, /* core5 sp_EL1 bit37 */
			{40407,45,1}, /* core5 sp_EL1 bit38 */
			{40400,45,1}, /* core5 sp_EL1 bit39 */
			{40401,45,1}, /* core5 sp_EL1 bit40 */
			{40409,45,1}, /* core5 sp_EL1 bit41 */
			{40410,45,1}, /* core5 sp_EL1 bit42 */
			{40411,45,1}, /* core5 sp_EL1 bit43 */
			{40408,45,1}, /* core5 sp_EL1 bit44 */
			{40384,45,1}, /* core5 sp_EL1 bit45 */
			{40379,45,1}, /* core5 sp_EL1 bit46 */
			{40385,45,1}, /* core5 sp_EL1 bit47 */
			{40449,45,1}, /* core5 sp_EL1 bit48 */
			{39472,44,0}, /* core5 sp_EL1 bit49 */
			{39471,44,0}, /* core5 sp_EL1 bit50 */
			{39470,44,0}, /* core5 sp_EL1 bit51 */
			{39469,44,0}, /* core5 sp_EL1 bit52 */
			{39468,44,0}, /* core5 sp_EL1 bit53 */
			{39467,44,0}, /* core5 sp_EL1 bit54 */
			{39466,44,0}, /* core5 sp_EL1 bit55 */
			{39465,44,0}, /* core5 sp_EL1 bit56 */
			{40448,45,1}, /* core5 sp_EL1 bit57 */
			{34398,44,0}, /* core5 sp_EL1 bit58 */
			{34397,44,0}, /* core5 sp_EL1 bit59 */
			{34386,44,0}, /* core5 sp_EL1 bit60 */
			{34385,44,0}, /* core5 sp_EL1 bit61 */
			{34198,44,0}, /* core5 sp_EL1 bit62 */
			{34197,44,0}, /* core5 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{40264,45,1}, /* core5 sp_EL2 bit0 */
			{40256,45,1}, /* core5 sp_EL2 bit1 */
			{40268,45,1}, /* core5 sp_EL2 bit2 */
			{40266,45,1}, /* core5 sp_EL2 bit3 */
			{40257,45,1}, /* core5 sp_EL2 bit4 */
			{40263,45,1}, /* core5 sp_EL2 bit5 */
			{40267,45,1}, /* core5 sp_EL2 bit6 */
			{40262,45,1}, /* core5 sp_EL2 bit7 */
			{40261,45,1}, /* core5 sp_EL2 bit8 */
			{40260,45,1}, /* core5 sp_EL2 bit9 */
			{40245,45,1}, /* core5 sp_EL2 bit10 */
			{40246,45,1}, /* core5 sp_EL2 bit11 */
			{40265,45,1}, /* core5 sp_EL2 bit12 */
			{40243,45,1}, /* core5 sp_EL2 bit13 */
			{40241,45,1}, /* core5 sp_EL2 bit14 */
			{40239,45,1}, /* core5 sp_EL2 bit15 */
			{40251,45,1}, /* core5 sp_EL2 bit16 */
			{40259,45,1}, /* core5 sp_EL2 bit17 */
			{40250,45,1}, /* core5 sp_EL2 bit18 */
			{40247,45,1}, /* core5 sp_EL2 bit19 */
			{40248,45,1}, /* core5 sp_EL2 bit20 */
			{40249,45,1}, /* core5 sp_EL2 bit21 */
			{40255,45,1}, /* core5 sp_EL2 bit22 */
			{40258,45,1}, /* core5 sp_EL2 bit23 */
			{40254,45,1}, /* core5 sp_EL2 bit24 */
			{40253,45,1}, /* core5 sp_EL2 bit25 */
			{40238,45,1}, /* core5 sp_EL2 bit26 */
			{40237,45,1}, /* core5 sp_EL2 bit27 */
			{40242,45,1}, /* core5 sp_EL2 bit28 */
			{40240,45,1}, /* core5 sp_EL2 bit29 */
			{40244,45,1}, /* core5 sp_EL2 bit30 */
			{40252,45,1}, /* core5 sp_EL2 bit31 */
			{40402,45,1}, /* core5 sp_EL2 bit32 */
			{40412,45,1}, /* core5 sp_EL2 bit33 */
			{40387,45,1}, /* core5 sp_EL2 bit34 */
			{40388,45,1}, /* core5 sp_EL2 bit35 */
			{40419,45,1}, /* core5 sp_EL2 bit36 */
			{40414,45,1}, /* core5 sp_EL2 bit37 */
			{40413,45,1}, /* core5 sp_EL2 bit38 */
			{40417,45,1}, /* core5 sp_EL2 bit39 */
			{40416,45,1}, /* core5 sp_EL2 bit40 */
			{40418,45,1}, /* core5 sp_EL2 bit41 */
			{40415,45,1}, /* core5 sp_EL2 bit42 */
			{40420,45,1}, /* core5 sp_EL2 bit43 */
			{40404,45,1}, /* core5 sp_EL2 bit44 */
			{40403,45,1}, /* core5 sp_EL2 bit45 */
			{40378,45,1}, /* core5 sp_EL2 bit46 */
			{40389,45,1}, /* core5 sp_EL2 bit47 */
			{40447,45,1}, /* core5 sp_EL2 bit48 */
			{40460,45,1}, /* core5 sp_EL2 bit49 */
			{34422,44,0}, /* core5 sp_EL2 bit50 */
			{34421,44,0}, /* core5 sp_EL2 bit51 */
			{34420,44,0}, /* core5 sp_EL2 bit52 */
			{34419,44,0}, /* core5 sp_EL2 bit53 */
			{34416,44,0}, /* core5 sp_EL2 bit54 */
			{34415,44,0}, /* core5 sp_EL2 bit55 */
			{34400,44,0}, /* core5 sp_EL2 bit56 */
			{34399,44,0}, /* core5 sp_EL2 bit57 */
			{34396,44,0}, /* core5 sp_EL2 bit58 */
			{34395,44,0}, /* core5 sp_EL2 bit59 */
			{36728,44,0}, /* core5 sp_EL2 bit60 */
			{36727,44,0}, /* core5 sp_EL2 bit61 */
			{36726,44,0}, /* core5 sp_EL2 bit62 */
			{36725,44,0}, /* core5 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{40272,45,1}, /* core5 sp_EL3 bit0 */
			{40289,45,1}, /* core5 sp_EL3 bit1 */
			{40277,45,1}, /* core5 sp_EL3 bit2 */
			{40279,45,1}, /* core5 sp_EL3 bit3 */
			{40281,45,1}, /* core5 sp_EL3 bit4 */
			{40280,45,1}, /* core5 sp_EL3 bit5 */
			{34280,44,0}, /* core5 sp_EL3 bit6 */
			{34279,44,0}, /* core5 sp_EL3 bit7 */
			{40278,45,1}, /* core5 sp_EL3 bit8 */
			{40276,45,1}, /* core5 sp_EL3 bit9 */
			{40290,45,1}, /* core5 sp_EL3 bit10 */
			{40292,45,1}, /* core5 sp_EL3 bit11 */
			{34282,44,0}, /* core5 sp_EL3 bit12 */
			{34281,44,0}, /* core5 sp_EL3 bit13 */
			{40288,45,1}, /* core5 sp_EL3 bit14 */
			{40287,45,1}, /* core5 sp_EL3 bit15 */
			{40300,45,1}, /* core5 sp_EL3 bit16 */
			{40301,45,1}, /* core5 sp_EL3 bit17 */
			{40291,45,1}, /* core5 sp_EL3 bit18 */
			{40299,45,1}, /* core5 sp_EL3 bit19 */
			{40297,45,1}, /* core5 sp_EL3 bit20 */
			{40298,45,1}, /* core5 sp_EL3 bit21 */
			{40271,45,1}, /* core5 sp_EL3 bit22 */
			{40294,45,1}, /* core5 sp_EL3 bit23 */
			{40295,45,1}, /* core5 sp_EL3 bit24 */
			{40296,45,1}, /* core5 sp_EL3 bit25 */
			{40275,45,1}, /* core5 sp_EL3 bit26 */
			{40274,45,1}, /* core5 sp_EL3 bit27 */
			{40273,45,1}, /* core5 sp_EL3 bit28 */
			{40270,45,1}, /* core5 sp_EL3 bit29 */
			{40269,45,1}, /* core5 sp_EL3 bit30 */
			{40293,45,1}, /* core5 sp_EL3 bit31 */
			{40393,45,1}, /* core5 sp_EL3 bit32 */
			{40392,45,1}, /* core5 sp_EL3 bit33 */
			{40391,45,1}, /* core5 sp_EL3 bit34 */
			{40396,45,1}, /* core5 sp_EL3 bit35 */
			{40425,45,1}, /* core5 sp_EL3 bit36 */
			{40423,45,1}, /* core5 sp_EL3 bit37 */
			{40395,45,1}, /* core5 sp_EL3 bit38 */
			{40426,45,1}, /* core5 sp_EL3 bit39 */
			{40397,45,1}, /* core5 sp_EL3 bit40 */
			{40399,45,1}, /* core5 sp_EL3 bit41 */
			{40424,45,1}, /* core5 sp_EL3 bit42 */
			{40398,45,1}, /* core5 sp_EL3 bit43 */
			{40394,45,1}, /* core5 sp_EL3 bit44 */
			{40435,45,1}, /* core5 sp_EL3 bit45 */
			{40377,45,1}, /* core5 sp_EL3 bit46 */
			{40390,45,1}, /* core5 sp_EL3 bit47 */
			{40458,45,1}, /* core5 sp_EL3 bit48 */
			{40457,45,1}, /* core5 sp_EL3 bit49 */
			{34418,44,0}, /* core5 sp_EL3 bit50 */
			{34417,44,0}, /* core5 sp_EL3 bit51 */
			{36776,44,0}, /* core5 sp_EL3 bit52 */
			{36775,44,0}, /* core5 sp_EL3 bit53 */
			{36774,44,0}, /* core5 sp_EL3 bit54 */
			{36773,44,0}, /* core5 sp_EL3 bit55 */
			{36692,44,0}, /* core5 sp_EL3 bit56 */
			{36691,44,0}, /* core5 sp_EL3 bit57 */
			{36690,44,0}, /* core5 sp_EL3 bit58 */
			{36689,44,0}, /* core5 sp_EL3 bit59 */
			{40375,45,1}, /* core5 sp_EL3 bit60 */
			{40374,45,1}, /* core5 sp_EL3 bit61 */
			{34388,44,0}, /* core5 sp_EL3 bit62 */
			{34387,44,0}, /* core5 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{39606,44,0}, /* core5 elr_EL1 bit0 */
			{39605,44,0}, /* core5 elr_EL1 bit1 */
			{39604,44,0}, /* core5 elr_EL1 bit2 */
			{39603,44,0}, /* core5 elr_EL1 bit3 */
			{39602,44,0}, /* core5 elr_EL1 bit4 */
			{39601,44,0}, /* core5 elr_EL1 bit5 */
			{39600,44,0}, /* core5 elr_EL1 bit6 */
			{39599,44,0}, /* core5 elr_EL1 bit7 */
			{34224,44,0}, /* core5 elr_EL1 bit8 */
			{34223,44,0}, /* core5 elr_EL1 bit9 */
			{34218,44,0}, /* core5 elr_EL1 bit10 */
			{34217,44,0}, /* core5 elr_EL1 bit11 */
			{34222,44,0}, /* core5 elr_EL1 bit12 */
			{34221,44,0}, /* core5 elr_EL1 bit13 */
			{34220,44,0}, /* core5 elr_EL1 bit14 */
			{34219,44,0}, /* core5 elr_EL1 bit15 */
			{39654,44,0}, /* core5 elr_EL1 bit16 */
			{39653,44,0}, /* core5 elr_EL1 bit17 */
			{39652,44,0}, /* core5 elr_EL1 bit18 */
			{39651,44,0}, /* core5 elr_EL1 bit19 */
			{39650,44,0}, /* core5 elr_EL1 bit20 */
			{39649,44,0}, /* core5 elr_EL1 bit21 */
			{39648,44,0}, /* core5 elr_EL1 bit22 */
			{39647,44,0}, /* core5 elr_EL1 bit23 */
			{39638,44,0}, /* core5 elr_EL1 bit24 */
			{39637,44,0}, /* core5 elr_EL1 bit25 */
			{39636,44,0}, /* core5 elr_EL1 bit26 */
			{39635,44,0}, /* core5 elr_EL1 bit27 */
			{39634,44,0}, /* core5 elr_EL1 bit28 */
			{39633,44,0}, /* core5 elr_EL1 bit29 */
			{39632,44,0}, /* core5 elr_EL1 bit30 */
			{39631,44,0}, /* core5 elr_EL1 bit31 */
			{36720,44,0}, /* core5 elr_EL1 bit32 */
			{36724,44,0}, /* core5 elr_EL1 bit33 */
			{36723,44,0}, /* core5 elr_EL1 bit34 */
			{36719,44,0}, /* core5 elr_EL1 bit35 */
			{36722,44,0}, /* core5 elr_EL1 bit36 */
			{36721,44,0}, /* core5 elr_EL1 bit37 */
			{36716,44,0}, /* core5 elr_EL1 bit38 */
			{36718,44,0}, /* core5 elr_EL1 bit39 */
			{36715,44,0}, /* core5 elr_EL1 bit40 */
			{36714,44,0}, /* core5 elr_EL1 bit41 */
			{39440,44,0}, /* core5 elr_EL1 bit42 */
			{39439,44,0}, /* core5 elr_EL1 bit43 */
			{39438,44,0}, /* core5 elr_EL1 bit44 */
			{36717,44,0}, /* core5 elr_EL1 bit45 */
			{39437,44,0}, /* core5 elr_EL1 bit46 */
			{39436,44,0}, /* core5 elr_EL1 bit47 */
			{36796,44,0}, /* core5 elr_EL1 bit48 */
			{39435,44,0}, /* core5 elr_EL1 bit49 */
			{36795,44,0}, /* core5 elr_EL1 bit50 */
			{36794,44,0}, /* core5 elr_EL1 bit51 */
			{36793,44,0}, /* core5 elr_EL1 bit52 */
			{36792,44,0}, /* core5 elr_EL1 bit53 */
			{39434,44,0}, /* core5 elr_EL1 bit54 */
			{39433,44,0}, /* core5 elr_EL1 bit55 */
			{36791,44,0}, /* core5 elr_EL1 bit56 */
			{36790,44,0}, /* core5 elr_EL1 bit57 */
			{36789,44,0}, /* core5 elr_EL1 bit58 */
			{34394,44,0}, /* core5 elr_EL1 bit59 */
			{36713,44,0}, /* core5 elr_EL1 bit60 */
			{34393,44,0}, /* core5 elr_EL1 bit61 */
			{34390,44,0}, /* core5 elr_EL1 bit62 */
			{34389,44,0}, /* core5 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{39614,44,0}, /* core5 elr_EL2 bit0 */
			{39613,44,0}, /* core5 elr_EL2 bit1 */
			{39612,44,0}, /* core5 elr_EL2 bit2 */
			{39611,44,0}, /* core5 elr_EL2 bit3 */
			{39610,44,0}, /* core5 elr_EL2 bit4 */
			{39609,44,0}, /* core5 elr_EL2 bit5 */
			{39608,44,0}, /* core5 elr_EL2 bit6 */
			{39607,44,0}, /* core5 elr_EL2 bit7 */
			{39622,44,0}, /* core5 elr_EL2 bit8 */
			{39621,44,0}, /* core5 elr_EL2 bit9 */
			{39620,44,0}, /* core5 elr_EL2 bit10 */
			{39619,44,0}, /* core5 elr_EL2 bit11 */
			{39618,44,0}, /* core5 elr_EL2 bit12 */
			{39617,44,0}, /* core5 elr_EL2 bit13 */
			{39616,44,0}, /* core5 elr_EL2 bit14 */
			{39615,44,0}, /* core5 elr_EL2 bit15 */
			{39646,44,0}, /* core5 elr_EL2 bit16 */
			{39645,44,0}, /* core5 elr_EL2 bit17 */
			{39644,44,0}, /* core5 elr_EL2 bit18 */
			{39643,44,0}, /* core5 elr_EL2 bit19 */
			{39642,44,0}, /* core5 elr_EL2 bit20 */
			{39641,44,0}, /* core5 elr_EL2 bit21 */
			{39640,44,0}, /* core5 elr_EL2 bit22 */
			{39639,44,0}, /* core5 elr_EL2 bit23 */
			{39630,44,0}, /* core5 elr_EL2 bit24 */
			{39629,44,0}, /* core5 elr_EL2 bit25 */
			{39628,44,0}, /* core5 elr_EL2 bit26 */
			{39627,44,0}, /* core5 elr_EL2 bit27 */
			{39626,44,0}, /* core5 elr_EL2 bit28 */
			{39625,44,0}, /* core5 elr_EL2 bit29 */
			{39624,44,0}, /* core5 elr_EL2 bit30 */
			{39623,44,0}, /* core5 elr_EL2 bit31 */
			{39432,44,0}, /* core5 elr_EL2 bit32 */
			{36712,44,0}, /* core5 elr_EL2 bit33 */
			{36711,44,0}, /* core5 elr_EL2 bit34 */
			{39431,44,0}, /* core5 elr_EL2 bit35 */
			{39430,44,0}, /* core5 elr_EL2 bit36 */
			{39429,44,0}, /* core5 elr_EL2 bit37 */
			{36710,44,0}, /* core5 elr_EL2 bit38 */
			{39428,44,0}, /* core5 elr_EL2 bit39 */
			{36709,44,0}, /* core5 elr_EL2 bit40 */
			{36708,44,0}, /* core5 elr_EL2 bit41 */
			{39427,44,0}, /* core5 elr_EL2 bit42 */
			{36707,44,0}, /* core5 elr_EL2 bit43 */
			{36706,44,0}, /* core5 elr_EL2 bit44 */
			{39426,44,0}, /* core5 elr_EL2 bit45 */
			{39425,44,0}, /* core5 elr_EL2 bit46 */
			{36705,44,0}, /* core5 elr_EL2 bit47 */
			{36788,44,0}, /* core5 elr_EL2 bit48 */
			{36787,44,0}, /* core5 elr_EL2 bit49 */
			{36786,44,0}, /* core5 elr_EL2 bit50 */
			{36785,44,0}, /* core5 elr_EL2 bit51 */
			{36784,44,0}, /* core5 elr_EL2 bit52 */
			{36783,44,0}, /* core5 elr_EL2 bit53 */
			{36782,44,0}, /* core5 elr_EL2 bit54 */
			{36781,44,0}, /* core5 elr_EL2 bit55 */
			{36780,44,0}, /* core5 elr_EL2 bit56 */
			{36779,44,0}, /* core5 elr_EL2 bit57 */
			{36778,44,0}, /* core5 elr_EL2 bit58 */
			{36777,44,0}, /* core5 elr_EL2 bit59 */
			{36704,44,0}, /* core5 elr_EL2 bit60 */
			{36703,44,0}, /* core5 elr_EL2 bit61 */
			{36702,44,0}, /* core5 elr_EL2 bit62 */
			{36701,44,0}, /* core5 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{34228,44,0}, /* core5 elr_EL3 bit0 */
			{34227,44,0}, /* core5 elr_EL3 bit1 */
			{40317,45,1}, /* core5 elr_EL3 bit2 */
			{40318,45,1}, /* core5 elr_EL3 bit3 */
			{36912,44,0}, /* core5 elr_EL3 bit4 */
			{36911,44,0}, /* core5 elr_EL3 bit5 */
			{36910,44,0}, /* core5 elr_EL3 bit6 */
			{36909,44,0}, /* core5 elr_EL3 bit7 */
			{34232,44,0}, /* core5 elr_EL3 bit8 */
			{34231,44,0}, /* core5 elr_EL3 bit9 */
			{40339,45,1}, /* core5 elr_EL3 bit10 */
			{40351,45,1}, /* core5 elr_EL3 bit11 */
			{34230,44,0}, /* core5 elr_EL3 bit12 */
			{34229,44,0}, /* core5 elr_EL3 bit13 */
			{40326,45,1}, /* core5 elr_EL3 bit14 */
			{40328,45,1}, /* core5 elr_EL3 bit15 */
			{40352,45,1}, /* core5 elr_EL3 bit16 */
			{40353,45,1}, /* core5 elr_EL3 bit17 */
			{40354,45,1}, /* core5 elr_EL3 bit18 */
			{40344,45,1}, /* core5 elr_EL3 bit19 */
			{40342,45,1}, /* core5 elr_EL3 bit20 */
			{40341,45,1}, /* core5 elr_EL3 bit21 */
			{40327,45,1}, /* core5 elr_EL3 bit22 */
			{40338,45,1}, /* core5 elr_EL3 bit23 */
			{40340,45,1}, /* core5 elr_EL3 bit24 */
			{40343,45,1}, /* core5 elr_EL3 bit25 */
			{40323,45,1}, /* core5 elr_EL3 bit26 */
			{40322,45,1}, /* core5 elr_EL3 bit27 */
			{40324,45,1}, /* core5 elr_EL3 bit28 */
			{40325,45,1}, /* core5 elr_EL3 bit29 */
			{40329,45,1}, /* core5 elr_EL3 bit30 */
			{40337,45,1}, /* core5 elr_EL3 bit31 */
			{34382,44,0}, /* core5 elr_EL3 bit32 */
			{34381,44,0}, /* core5 elr_EL3 bit33 */
			{40368,45,1}, /* core5 elr_EL3 bit34 */
			{40364,45,1}, /* core5 elr_EL3 bit35 */
			{40380,45,1}, /* core5 elr_EL3 bit36 */
			{40372,45,1}, /* core5 elr_EL3 bit37 */
			{40365,45,1}, /* core5 elr_EL3 bit38 */
			{40376,45,1}, /* core5 elr_EL3 bit39 */
			{40369,45,1}, /* core5 elr_EL3 bit40 */
			{40367,45,1}, /* core5 elr_EL3 bit41 */
			{40373,45,1}, /* core5 elr_EL3 bit42 */
			{40371,45,1}, /* core5 elr_EL3 bit43 */
			{40381,45,1}, /* core5 elr_EL3 bit44 */
			{40366,45,1}, /* core5 elr_EL3 bit45 */
			{40370,45,1}, /* core5 elr_EL3 bit46 */
			{40382,45,1}, /* core5 elr_EL3 bit47 */
			{34402,44,0}, /* core5 elr_EL3 bit48 */
			{34401,44,0}, /* core5 elr_EL3 bit49 */
			{36772,44,0}, /* core5 elr_EL3 bit50 */
			{36771,44,0}, /* core5 elr_EL3 bit51 */
			{34414,44,0}, /* core5 elr_EL3 bit52 */
			{36770,44,0}, /* core5 elr_EL3 bit53 */
			{34413,44,0}, /* core5 elr_EL3 bit54 */
			{36769,44,0}, /* core5 elr_EL3 bit55 */
			{36688,44,0}, /* core5 elr_EL3 bit56 */
			{36687,44,0}, /* core5 elr_EL3 bit57 */
			{36686,44,0}, /* core5 elr_EL3 bit58 */
			{36685,44,0}, /* core5 elr_EL3 bit59 */
			{34384,44,0}, /* core5 elr_EL3 bit60 */
			{34383,44,0}, /* core5 elr_EL3 bit61 */
			{34196,44,0}, /* core5 elr_EL3 bit62 */
			{34195,44,0}, /* core5 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{35631,44,0}, /* core5 raw_pc bit0 */
			{35630,44,0}, /* core5 raw_pc bit1 */
			{38290,44,0}, /* core5 raw_pc bit2 */
			{38289,44,0}, /* core5 raw_pc bit3 */
			{38288,44,0}, /* core5 raw_pc bit4 */
			{38287,44,0}, /* core5 raw_pc bit5 */
			{32560,44,1}, /* core5 raw_pc bit6 */
			{38278,44,0}, /* core5 raw_pc bit7 */
			{38277,44,0}, /* core5 raw_pc bit8 */
			{38276,44,0}, /* core5 raw_pc bit9 */
			{38275,44,0}, /* core5 raw_pc bit10 */
			{35637,44,0}, /* core5 raw_pc bit11 */
			{35636,44,0}, /* core5 raw_pc bit12 */
			{35635,44,0}, /* core5 raw_pc bit13 */
			{35634,44,0}, /* core5 raw_pc bit14 */
			{38282,44,0}, /* core5 raw_pc bit15 */
			{38281,44,0}, /* core5 raw_pc bit16 */
			{38280,44,0}, /* core5 raw_pc bit17 */
			{38279,44,0}, /* core5 raw_pc bit18 */
			{35641,44,0}, /* core5 raw_pc bit19 */
			{35640,44,0}, /* core5 raw_pc bit20 */
			{32562,44,1}, /* core5 raw_pc bit21 */
			{32561,44,1}, /* core5 raw_pc bit22 */
			{38286,44,0}, /* core5 raw_pc bit23 */
			{38285,44,0}, /* core5 raw_pc bit24 */
			{38284,44,0}, /* core5 raw_pc bit25 */
			{38283,44,0}, /* core5 raw_pc bit26 */
			{35633,44,0}, /* core5 raw_pc bit27 */
			{35632,44,0}, /* core5 raw_pc bit28 */
			{35639,44,0}, /* core5 raw_pc bit29 */
			{35638,44,0}, /* core5 raw_pc bit30 */
			{38274,44,0}, /* core5 raw_pc bit31 */
			{38273,44,0}, /* core5 raw_pc bit32 */
			{38272,44,0}, /* core5 raw_pc bit33 */
			{38271,44,0}, /* core5 raw_pc bit34 */
			{40754,44,0}, /* core5 raw_pc bit35 */
			{40753,44,0}, /* core5 raw_pc bit36 */
			{40752,44,0}, /* core5 raw_pc bit37 */
			{40751,44,0}, /* core5 raw_pc bit38 */
			{35645,44,0}, /* core5 raw_pc bit39 */
			{35644,44,0}, /* core5 raw_pc bit40 */
			{40750,44,0}, /* core5 raw_pc bit41 */
			{40749,44,0}, /* core5 raw_pc bit42 */
			{35647,44,0}, /* core5 raw_pc bit43 */
			{35646,44,0}, /* core5 raw_pc bit44 */
			{40748,44,0}, /* core5 raw_pc bit45 */
			{40747,44,0}, /* core5 raw_pc bit46 */
			{32577,44,1}, /* core5 raw_pc bit47 */
			{32578,44,1}, /* core5 raw_pc bit48 */
			{32579,44,1}, /* core5 raw_pc bit49 */
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
			{32555,44,1}, /* core5 pc_iss bit0 */
			{32637,44,1}, /* core5 pc_iss bit1 */
			{32634,44,1}, /* core5 pc_iss bit2 */
			{32633,44,1}, /* core5 pc_iss bit3 */
			{32635,44,1}, /* core5 pc_iss bit4 */
			{32554,44,1}, /* core5 pc_iss bit5 */
			{32556,44,1}, /* core5 pc_iss bit6 */
			{32636,44,1}, /* core5 pc_iss bit7 */
			{32610,44,1}, /* core5 pc_iss bit8 */
			{32603,44,1}, /* core5 pc_iss bit9 */
			{32632,44,1}, /* core5 pc_iss bit10 */
			{32631,44,1}, /* core5 pc_iss bit11 */
			{32629,44,1}, /* core5 pc_iss bit12 */
			{32630,44,1}, /* core5 pc_iss bit13 */
			{32628,44,1}, /* core5 pc_iss bit14 */
			{32614,44,1}, /* core5 pc_iss bit15 */
			{32615,44,1}, /* core5 pc_iss bit16 */
			{32627,44,1}, /* core5 pc_iss bit17 */
			{32624,44,1}, /* core5 pc_iss bit18 */
			{32617,44,1}, /* core5 pc_iss bit19 */
			{32625,44,1}, /* core5 pc_iss bit20 */
			{32626,44,1}, /* core5 pc_iss bit21 */
			{32611,44,1}, /* core5 pc_iss bit22 */
			{32618,44,1}, /* core5 pc_iss bit23 */
			{32622,44,1}, /* core5 pc_iss bit24 */
			{32621,44,1}, /* core5 pc_iss bit25 */
			{32619,44,1}, /* core5 pc_iss bit26 */
			{32612,44,1}, /* core5 pc_iss bit27 */
			{32613,44,1}, /* core5 pc_iss bit28 */
			{32620,44,1}, /* core5 pc_iss bit29 */
			{32616,44,1}, /* core5 pc_iss bit30 */
			{32623,44,1}, /* core5 pc_iss bit31 */
			{32573,44,1}, /* core5 pc_iss bit32 */
			{32574,44,1}, /* core5 pc_iss bit33 */
			{32563,44,1}, /* core5 pc_iss bit34 */
			{32564,44,1}, /* core5 pc_iss bit35 */
			{32570,44,1}, /* core5 pc_iss bit36 */
			{32566,44,1}, /* core5 pc_iss bit37 */
			{32571,44,1}, /* core5 pc_iss bit38 */
			{32565,44,1}, /* core5 pc_iss bit39 */
			{32572,44,1}, /* core5 pc_iss bit40 */
			{32568,44,1}, /* core5 pc_iss bit41 */
			{32567,44,1}, /* core5 pc_iss bit42 */
			{32569,44,1}, /* core5 pc_iss bit43 */
			{35685,44,0}, /* core5 pc_iss bit44 */
			{35684,44,0}, /* core5 pc_iss bit45 */
			{35683,44,0}, /* core5 pc_iss bit46 */
			{35682,44,0}, /* core5 pc_iss bit47 */
			{38270,44,0}, /* core5 pc_iss bit48 */
			{38269,44,0}, /* core5 pc_iss bit49 */
			{38268,44,0}, /* core5 pc_iss bit50 */
			{38267,44,0}, /* core5 pc_iss bit51 */
			{38266,44,0}, /* core5 pc_iss bit52 */
			{38265,44,0}, /* core5 pc_iss bit53 */
			{38264,44,0}, /* core5 pc_iss bit54 */
			{38263,44,0}, /* core5 pc_iss bit55 */
			{40956,44,0}, /* core5 pc_iss bit56 */
			{40955,44,0}, /* core5 pc_iss bit57 */
			{40954,44,0}, /* core5 pc_iss bit58 */
			{40953,44,0}, /* core5 pc_iss bit59 */
			{40952,44,0}, /* core5 pc_iss bit60 */
			{40951,44,0}, /* core5 pc_iss bit61 */
			{40950,44,0}, /* core5 pc_iss bit62 */
			{40949,44,0}, /* core5 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{32557,44,1}, /* core5 full_pc_wr bit0 */
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
			{41124,44,0}, /* core5 full_pc_ex1 bit0 */
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
			{41116,44,0}, /* core5 full_pc_ex2 bit0 */
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
			{25953,45,1}, /* core5 return_Stack_pointer bit0 */
			{28673,45,1}, /* core5 return_Stack_pointer bit1 */
			{28674,45,1}, /* core5 return_Stack_pointer bit2 */
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
			{32644,45,1}, /* core5 return_Stack0 bit0 */
			{32643,45,1}, /* core5 return_Stack0 bit1 */
			{32672,45,1}, /* core5 return_Stack0 bit2 */
			{32671,45,1}, /* core5 return_Stack0 bit3 */
			{32670,45,1}, /* core5 return_Stack0 bit4 */
			{32669,45,1}, /* core5 return_Stack0 bit5 */
			{28860,45,1}, /* core5 return_Stack0 bit6 */
			{28859,45,1}, /* core5 return_Stack0 bit7 */
			{28858,45,1}, /* core5 return_Stack0 bit8 */
			{28857,45,1}, /* core5 return_Stack0 bit9 */
			{37875,45,1}, /* core5 return_Stack0 bit10 */
			{37874,45,1}, /* core5 return_Stack0 bit11 */
			{37873,45,1}, /* core5 return_Stack0 bit12 */
			{37872,45,1}, /* core5 return_Stack0 bit13 */
			{37871,45,1}, /* core5 return_Stack0 bit14 */
			{37870,45,1}, /* core5 return_Stack0 bit15 */
			{37869,45,1}, /* core5 return_Stack0 bit16 */
			{32642,45,1}, /* core5 return_Stack0 bit17 */
			{37868,45,1}, /* core5 return_Stack0 bit18 */
			{32648,45,1}, /* core5 return_Stack0 bit19 */
			{32647,45,1}, /* core5 return_Stack0 bit20 */
			{32646,45,1}, /* core5 return_Stack0 bit21 */
			{32645,45,1}, /* core5 return_Stack0 bit22 */
			{32641,45,1}, /* core5 return_Stack0 bit23 */
			{26154,45,1}, /* core5 return_Stack0 bit24 */
			{26153,45,1}, /* core5 return_Stack0 bit25 */
			{28780,45,1}, /* core5 return_Stack0 bit26 */
			{28779,45,1}, /* core5 return_Stack0 bit27 */
			{32656,45,1}, /* core5 return_Stack0 bit28 */
			{32655,45,1}, /* core5 return_Stack0 bit29 */
			{32654,45,1}, /* core5 return_Stack0 bit30 */
			{26152,45,1}, /* core5 return_Stack0 bit31 */
			{32653,45,1}, /* core5 return_Stack0 bit32 */
			{28770,45,1}, /* core5 return_Stack0 bit33 */
			{28769,45,1}, /* core5 return_Stack0 bit34 */
			{25973,45,1}, /* core5 return_Stack0 bit35 */
			{28772,45,1}, /* core5 return_Stack0 bit36 */
			{28771,45,1}, /* core5 return_Stack0 bit37 */
			{32832,45,1}, /* core5 return_Stack0 bit38 */
			{32831,45,1}, /* core5 return_Stack0 bit39 */
			{32830,45,1}, /* core5 return_Stack0 bit40 */
			{32829,45,1}, /* core5 return_Stack0 bit41 */
			{25972,45,1}, /* core5 return_Stack0 bit42 */
			{28774,45,1}, /* core5 return_Stack0 bit43 */
			{28773,45,1}, /* core5 return_Stack0 bit44 */
			{28776,45,1}, /* core5 return_Stack0 bit45 */
			{28775,45,1}, /* core5 return_Stack0 bit46 */
			{28778,45,1}, /* core5 return_Stack0 bit47 */
			{28777,45,1}, /* core5 return_Stack0 bit48 */
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
			{28812,45,1}, /* core5 return_Stack1 bit0 */
			{28811,45,1}, /* core5 return_Stack1 bit1 */
			{32716,45,1}, /* core5 return_Stack1 bit2 */
			{32715,45,1}, /* core5 return_Stack1 bit3 */
			{32720,45,1}, /* core5 return_Stack1 bit4 */
			{32719,45,1}, /* core5 return_Stack1 bit5 */
			{32718,45,1}, /* core5 return_Stack1 bit6 */
			{32717,45,1}, /* core5 return_Stack1 bit7 */
			{28818,45,1}, /* core5 return_Stack1 bit8 */
			{28817,45,1}, /* core5 return_Stack1 bit9 */
			{32714,45,1}, /* core5 return_Stack1 bit10 */
			{32713,45,1}, /* core5 return_Stack1 bit11 */
			{32724,45,1}, /* core5 return_Stack1 bit12 */
			{32723,45,1}, /* core5 return_Stack1 bit13 */
			{32722,45,1}, /* core5 return_Stack1 bit14 */
			{32721,45,1}, /* core5 return_Stack1 bit15 */
			{28820,45,1}, /* core5 return_Stack1 bit16 */
			{28819,45,1}, /* core5 return_Stack1 bit17 */
			{28816,45,1}, /* core5 return_Stack1 bit18 */
			{28815,45,1}, /* core5 return_Stack1 bit19 */
			{28814,45,1}, /* core5 return_Stack1 bit20 */
			{28813,45,1}, /* core5 return_Stack1 bit21 */
			{26163,45,1}, /* core5 return_Stack1 bit22 */
			{26165,45,1}, /* core5 return_Stack1 bit23 */
			{26164,45,1}, /* core5 return_Stack1 bit24 */
			{32736,45,1}, /* core5 return_Stack1 bit25 */
			{32735,45,1}, /* core5 return_Stack1 bit26 */
			{32734,45,1}, /* core5 return_Stack1 bit27 */
			{32733,45,1}, /* core5 return_Stack1 bit28 */
			{28810,45,1}, /* core5 return_Stack1 bit29 */
			{28809,45,1}, /* core5 return_Stack1 bit30 */
			{26166,45,1}, /* core5 return_Stack1 bit31 */
			{28808,45,1}, /* core5 return_Stack1 bit32 */
			{28806,45,1}, /* core5 return_Stack1 bit33 */
			{28805,45,1}, /* core5 return_Stack1 bit34 */
			{28807,45,1}, /* core5 return_Stack1 bit35 */
			{26167,45,1}, /* core5 return_Stack1 bit36 */
			{32784,45,1}, /* core5 return_Stack1 bit37 */
			{32783,45,1}, /* core5 return_Stack1 bit38 */
			{32782,45,1}, /* core5 return_Stack1 bit39 */
			{32781,45,1}, /* core5 return_Stack1 bit40 */
			{32788,45,1}, /* core5 return_Stack1 bit41 */
			{32787,45,1}, /* core5 return_Stack1 bit42 */
			{32786,45,1}, /* core5 return_Stack1 bit43 */
			{32785,45,1}, /* core5 return_Stack1 bit44 */
			{32792,45,1}, /* core5 return_Stack1 bit45 */
			{32791,45,1}, /* core5 return_Stack1 bit46 */
			{32790,45,1}, /* core5 return_Stack1 bit47 */
			{32789,45,1}, /* core5 return_Stack1 bit48 */
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
			{28856,45,1}, /* core5 return_Stack2 bit0 */
			{28855,45,1}, /* core5 return_Stack2 bit1 */
			{28854,45,1}, /* core5 return_Stack2 bit2 */
			{28853,45,1}, /* core5 return_Stack2 bit3 */
			{32676,45,1}, /* core5 return_Stack2 bit4 */
			{32675,45,1}, /* core5 return_Stack2 bit5 */
			{32674,45,1}, /* core5 return_Stack2 bit6 */
			{32673,45,1}, /* core5 return_Stack2 bit7 */
			{32680,45,1}, /* core5 return_Stack2 bit8 */
			{32679,45,1}, /* core5 return_Stack2 bit9 */
			{32678,45,1}, /* core5 return_Stack2 bit10 */
			{32677,45,1}, /* core5 return_Stack2 bit11 */
			{28846,45,1}, /* core5 return_Stack2 bit12 */
			{28845,45,1}, /* core5 return_Stack2 bit13 */
			{28848,45,1}, /* core5 return_Stack2 bit14 */
			{28847,45,1}, /* core5 return_Stack2 bit15 */
			{28852,45,1}, /* core5 return_Stack2 bit16 */
			{28851,45,1}, /* core5 return_Stack2 bit17 */
			{28844,45,1}, /* core5 return_Stack2 bit18 */
			{28843,45,1}, /* core5 return_Stack2 bit19 */
			{28850,45,1}, /* core5 return_Stack2 bit20 */
			{28849,45,1}, /* core5 return_Stack2 bit21 */
			{26155,45,1}, /* core5 return_Stack2 bit22 */
			{26156,45,1}, /* core5 return_Stack2 bit23 */
			{26157,45,1}, /* core5 return_Stack2 bit24 */
			{32652,45,1}, /* core5 return_Stack2 bit25 */
			{32651,45,1}, /* core5 return_Stack2 bit26 */
			{32650,45,1}, /* core5 return_Stack2 bit27 */
			{32649,45,1}, /* core5 return_Stack2 bit28 */
			{32756,45,1}, /* core5 return_Stack2 bit29 */
			{32755,45,1}, /* core5 return_Stack2 bit30 */
			{32754,45,1}, /* core5 return_Stack2 bit31 */
			{32753,45,1}, /* core5 return_Stack2 bit32 */
			{32824,45,1}, /* core5 return_Stack2 bit33 */
			{32823,45,1}, /* core5 return_Stack2 bit34 */
			{32822,45,1}, /* core5 return_Stack2 bit35 */
			{32821,45,1}, /* core5 return_Stack2 bit36 */
			{32820,45,1}, /* core5 return_Stack2 bit37 */
			{32819,45,1}, /* core5 return_Stack2 bit38 */
			{32818,45,1}, /* core5 return_Stack2 bit39 */
			{32817,45,1}, /* core5 return_Stack2 bit40 */
			{32828,45,1}, /* core5 return_Stack2 bit41 */
			{32827,45,1}, /* core5 return_Stack2 bit42 */
			{32826,45,1}, /* core5 return_Stack2 bit43 */
			{32825,45,1}, /* core5 return_Stack2 bit44 */
			{32760,45,1}, /* core5 return_Stack2 bit45 */
			{32759,45,1}, /* core5 return_Stack2 bit46 */
			{32758,45,1}, /* core5 return_Stack2 bit47 */
			{32757,45,1}, /* core5 return_Stack2 bit48 */
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
			{28802,45,1}, /* core5 return_Stack3 bit0 */
			{28801,45,1}, /* core5 return_Stack3 bit1 */
			{28824,45,1}, /* core5 return_Stack3 bit2 */
			{28826,45,1}, /* core5 return_Stack3 bit3 */
			{28825,45,1}, /* core5 return_Stack3 bit4 */
			{28822,45,1}, /* core5 return_Stack3 bit5 */
			{28821,45,1}, /* core5 return_Stack3 bit6 */
			{28796,45,1}, /* core5 return_Stack3 bit7 */
			{28795,45,1}, /* core5 return_Stack3 bit8 */
			{28823,45,1}, /* core5 return_Stack3 bit9 */
			{28798,45,1}, /* core5 return_Stack3 bit10 */
			{28830,45,1}, /* core5 return_Stack3 bit11 */
			{28829,45,1}, /* core5 return_Stack3 bit12 */
			{28828,45,1}, /* core5 return_Stack3 bit13 */
			{28827,45,1}, /* core5 return_Stack3 bit14 */
			{32708,45,1}, /* core5 return_Stack3 bit15 */
			{28800,45,1}, /* core5 return_Stack3 bit16 */
			{28799,45,1}, /* core5 return_Stack3 bit17 */
			{32707,45,1}, /* core5 return_Stack3 bit18 */
			{32706,45,1}, /* core5 return_Stack3 bit19 */
			{32705,45,1}, /* core5 return_Stack3 bit20 */
			{28797,45,1}, /* core5 return_Stack3 bit21 */
			{26158,45,1}, /* core5 return_Stack3 bit22 */
			{26162,45,1}, /* core5 return_Stack3 bit23 */
			{26159,45,1}, /* core5 return_Stack3 bit24 */
			{26160,45,1}, /* core5 return_Stack3 bit25 */
			{32744,45,1}, /* core5 return_Stack3 bit26 */
			{32743,45,1}, /* core5 return_Stack3 bit27 */
			{32742,45,1}, /* core5 return_Stack3 bit28 */
			{32796,45,1}, /* core5 return_Stack3 bit29 */
			{32741,45,1}, /* core5 return_Stack3 bit30 */
			{32795,45,1}, /* core5 return_Stack3 bit31 */
			{28804,45,1}, /* core5 return_Stack3 bit32 */
			{32794,45,1}, /* core5 return_Stack3 bit33 */
			{32793,45,1}, /* core5 return_Stack3 bit34 */
			{28803,45,1}, /* core5 return_Stack3 bit35 */
			{32776,45,1}, /* core5 return_Stack3 bit36 */
			{32775,45,1}, /* core5 return_Stack3 bit37 */
			{32774,45,1}, /* core5 return_Stack3 bit38 */
			{32780,45,1}, /* core5 return_Stack3 bit39 */
			{32779,45,1}, /* core5 return_Stack3 bit40 */
			{32778,45,1}, /* core5 return_Stack3 bit41 */
			{32777,45,1}, /* core5 return_Stack3 bit42 */
			{32800,45,1}, /* core5 return_Stack3 bit43 */
			{32799,45,1}, /* core5 return_Stack3 bit44 */
			{32798,45,1}, /* core5 return_Stack3 bit45 */
			{32797,45,1}, /* core5 return_Stack3 bit46 */
			{32773,45,1}, /* core5 return_Stack3 bit47 */
			{26161,45,1}, /* core5 return_Stack3 bit48 */
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
			{32664,45,1}, /* core5 return_Stack4 bit0 */
			{32663,45,1}, /* core5 return_Stack4 bit1 */
			{32636,45,1}, /* core5 return_Stack4 bit2 */
			{32635,45,1}, /* core5 return_Stack4 bit3 */
			{28864,45,1}, /* core5 return_Stack4 bit4 */
			{28863,45,1}, /* core5 return_Stack4 bit5 */
			{32640,45,1}, /* core5 return_Stack4 bit6 */
			{32639,45,1}, /* core5 return_Stack4 bit7 */
			{32638,45,1}, /* core5 return_Stack4 bit8 */
			{32637,45,1}, /* core5 return_Stack4 bit9 */
			{32634,45,1}, /* core5 return_Stack4 bit10 */
			{32633,45,1}, /* core5 return_Stack4 bit11 */
			{28862,45,1}, /* core5 return_Stack4 bit12 */
			{28861,45,1}, /* core5 return_Stack4 bit13 */
			{32668,45,1}, /* core5 return_Stack4 bit14 */
			{32667,45,1}, /* core5 return_Stack4 bit15 */
			{32662,45,1}, /* core5 return_Stack4 bit16 */
			{32661,45,1}, /* core5 return_Stack4 bit17 */
			{32666,45,1}, /* core5 return_Stack4 bit18 */
			{32665,45,1}, /* core5 return_Stack4 bit19 */
			{28866,45,1}, /* core5 return_Stack4 bit20 */
			{28865,45,1}, /* core5 return_Stack4 bit21 */
			{28868,45,1}, /* core5 return_Stack4 bit22 */
			{28867,45,1}, /* core5 return_Stack4 bit23 */
			{26150,45,1}, /* core5 return_Stack4 bit24 */
			{26151,45,1}, /* core5 return_Stack4 bit25 */
			{32660,45,1}, /* core5 return_Stack4 bit26 */
			{32659,45,1}, /* core5 return_Stack4 bit27 */
			{32658,45,1}, /* core5 return_Stack4 bit28 */
			{32844,45,1}, /* core5 return_Stack4 bit29 */
			{32843,45,1}, /* core5 return_Stack4 bit30 */
			{32842,45,1}, /* core5 return_Stack4 bit31 */
			{32657,45,1}, /* core5 return_Stack4 bit32 */
			{25971,45,1}, /* core5 return_Stack4 bit33 */
			{32841,45,1}, /* core5 return_Stack4 bit34 */
			{32840,45,1}, /* core5 return_Stack4 bit35 */
			{32839,45,1}, /* core5 return_Stack4 bit36 */
			{32838,45,1}, /* core5 return_Stack4 bit37 */
			{32837,45,1}, /* core5 return_Stack4 bit38 */
			{32836,45,1}, /* core5 return_Stack4 bit39 */
			{32835,45,1}, /* core5 return_Stack4 bit40 */
			{32834,45,1}, /* core5 return_Stack4 bit41 */
			{32833,45,1}, /* core5 return_Stack4 bit42 */
			{25970,45,1}, /* core5 return_Stack4 bit43 */
			{28872,45,1}, /* core5 return_Stack4 bit44 */
			{28871,45,1}, /* core5 return_Stack4 bit45 */
			{28870,45,1}, /* core5 return_Stack4 bit46 */
			{28869,45,1}, /* core5 return_Stack4 bit47 */
			{25969,45,1}, /* core5 return_Stack4 bit48 */
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
			{28790,45,1}, /* core5 return_Stack5 bit0 */
			{28789,45,1}, /* core5 return_Stack5 bit1 */
			{32696,45,1}, /* core5 return_Stack5 bit2 */
			{32695,45,1}, /* core5 return_Stack5 bit3 */
			{28794,45,1}, /* core5 return_Stack5 bit4 */
			{28793,45,1}, /* core5 return_Stack5 bit5 */
			{32692,45,1}, /* core5 return_Stack5 bit6 */
			{32691,45,1}, /* core5 return_Stack5 bit7 */
			{32690,45,1}, /* core5 return_Stack5 bit8 */
			{32689,45,1}, /* core5 return_Stack5 bit9 */
			{32694,45,1}, /* core5 return_Stack5 bit10 */
			{32693,45,1}, /* core5 return_Stack5 bit11 */
			{32700,45,1}, /* core5 return_Stack5 bit12 */
			{32699,45,1}, /* core5 return_Stack5 bit13 */
			{28792,45,1}, /* core5 return_Stack5 bit14 */
			{28791,45,1}, /* core5 return_Stack5 bit15 */
			{28788,45,1}, /* core5 return_Stack5 bit16 */
			{28787,45,1}, /* core5 return_Stack5 bit17 */
			{32698,45,1}, /* core5 return_Stack5 bit18 */
			{32704,45,1}, /* core5 return_Stack5 bit19 */
			{32703,45,1}, /* core5 return_Stack5 bit20 */
			{32702,45,1}, /* core5 return_Stack5 bit21 */
			{32697,45,1}, /* core5 return_Stack5 bit22 */
			{28786,45,1}, /* core5 return_Stack5 bit23 */
			{32701,45,1}, /* core5 return_Stack5 bit24 */
			{28785,45,1}, /* core5 return_Stack5 bit25 */
			{32752,45,1}, /* core5 return_Stack5 bit26 */
			{25968,45,1}, /* core5 return_Stack5 bit27 */
			{32751,45,1}, /* core5 return_Stack5 bit28 */
			{32750,45,1}, /* core5 return_Stack5 bit29 */
			{32749,45,1}, /* core5 return_Stack5 bit30 */
			{32808,45,1}, /* core5 return_Stack5 bit31 */
			{32807,45,1}, /* core5 return_Stack5 bit32 */
			{32806,45,1}, /* core5 return_Stack5 bit33 */
			{32805,45,1}, /* core5 return_Stack5 bit34 */
			{32812,45,1}, /* core5 return_Stack5 bit35 */
			{32811,45,1}, /* core5 return_Stack5 bit36 */
			{32810,45,1}, /* core5 return_Stack5 bit37 */
			{32809,45,1}, /* core5 return_Stack5 bit38 */
			{32804,45,1}, /* core5 return_Stack5 bit39 */
			{32803,45,1}, /* core5 return_Stack5 bit40 */
			{32802,45,1}, /* core5 return_Stack5 bit41 */
			{32801,45,1}, /* core5 return_Stack5 bit42 */
			{32816,45,1}, /* core5 return_Stack5 bit43 */
			{32815,45,1}, /* core5 return_Stack5 bit44 */
			{32814,45,1}, /* core5 return_Stack5 bit45 */
			{32813,45,1}, /* core5 return_Stack5 bit46 */
			{25955,45,1}, /* core5 return_Stack5 bit47 */
			{25956,45,1}, /* core5 return_Stack5 bit48 */
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
			{28784,45,1}, /* core5 return_Stack6 bit0 */
			{28783,45,1}, /* core5 return_Stack6 bit1 */
			{28838,45,1}, /* core5 return_Stack6 bit2 */
			{32688,45,1}, /* core5 return_Stack6 bit3 */
			{28837,45,1}, /* core5 return_Stack6 bit4 */
			{32687,45,1}, /* core5 return_Stack6 bit5 */
			{32686,45,1}, /* core5 return_Stack6 bit6 */
			{32685,45,1}, /* core5 return_Stack6 bit7 */
			{28834,45,1}, /* core5 return_Stack6 bit8 */
			{28833,45,1}, /* core5 return_Stack6 bit9 */
			{32684,45,1}, /* core5 return_Stack6 bit10 */
			{32683,45,1}, /* core5 return_Stack6 bit11 */
			{32682,45,1}, /* core5 return_Stack6 bit12 */
			{32681,45,1}, /* core5 return_Stack6 bit13 */
			{28840,45,1}, /* core5 return_Stack6 bit14 */
			{28839,45,1}, /* core5 return_Stack6 bit15 */
			{28836,45,1}, /* core5 return_Stack6 bit16 */
			{28835,45,1}, /* core5 return_Stack6 bit17 */
			{28842,45,1}, /* core5 return_Stack6 bit18 */
			{28841,45,1}, /* core5 return_Stack6 bit19 */
			{28832,45,1}, /* core5 return_Stack6 bit20 */
			{28831,45,1}, /* core5 return_Stack6 bit21 */
			{25960,45,1}, /* core5 return_Stack6 bit22 */
			{25959,45,1}, /* core5 return_Stack6 bit23 */
			{25967,45,1}, /* core5 return_Stack6 bit24 */
			{25966,45,1}, /* core5 return_Stack6 bit25 */
			{32748,45,1}, /* core5 return_Stack6 bit26 */
			{32747,45,1}, /* core5 return_Stack6 bit27 */
			{28782,45,1}, /* core5 return_Stack6 bit28 */
			{32746,45,1}, /* core5 return_Stack6 bit29 */
			{32745,45,1}, /* core5 return_Stack6 bit30 */
			{28781,45,1}, /* core5 return_Stack6 bit31 */
			{25958,45,1}, /* core5 return_Stack6 bit32 */
			{28680,45,1}, /* core5 return_Stack6 bit33 */
			{28679,45,1}, /* core5 return_Stack6 bit34 */
			{25954,45,1}, /* core5 return_Stack6 bit35 */
			{25957,45,1}, /* core5 return_Stack6 bit36 */
			{28678,45,1}, /* core5 return_Stack6 bit37 */
			{28677,45,1}, /* core5 return_Stack6 bit38 */
			{32764,45,1}, /* core5 return_Stack6 bit39 */
			{32763,45,1}, /* core5 return_Stack6 bit40 */
			{32762,45,1}, /* core5 return_Stack6 bit41 */
			{32761,45,1}, /* core5 return_Stack6 bit42 */
			{28676,45,1}, /* core5 return_Stack6 bit43 */
			{28675,45,1}, /* core5 return_Stack6 bit44 */
			{28664,45,1}, /* core5 return_Stack6 bit45 */
			{28663,45,1}, /* core5 return_Stack6 bit46 */
			{28662,45,1}, /* core5 return_Stack6 bit47 */
			{28661,45,1}, /* core5 return_Stack6 bit48 */
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
			{32712,45,1}, /* core5 return_Stack7 bit0 */
			{32711,45,1}, /* core5 return_Stack7 bit1 */
			{32732,45,1}, /* core5 return_Stack7 bit2 */
			{32731,45,1}, /* core5 return_Stack7 bit3 */
			{32730,45,1}, /* core5 return_Stack7 bit4 */
			{32729,45,1}, /* core5 return_Stack7 bit5 */
			{28652,45,1}, /* core5 return_Stack7 bit6 */
			{28651,45,1}, /* core5 return_Stack7 bit7 */
			{28654,45,1}, /* core5 return_Stack7 bit8 */
			{28653,45,1}, /* core5 return_Stack7 bit9 */
			{32728,45,1}, /* core5 return_Stack7 bit10 */
			{32727,45,1}, /* core5 return_Stack7 bit11 */
			{28650,45,1}, /* core5 return_Stack7 bit12 */
			{28649,45,1}, /* core5 return_Stack7 bit13 */
			{32710,45,1}, /* core5 return_Stack7 bit14 */
			{32726,45,1}, /* core5 return_Stack7 bit15 */
			{32709,45,1}, /* core5 return_Stack7 bit16 */
			{32725,45,1}, /* core5 return_Stack7 bit17 */
			{28656,45,1}, /* core5 return_Stack7 bit18 */
			{28655,45,1}, /* core5 return_Stack7 bit19 */
			{28658,45,1}, /* core5 return_Stack7 bit20 */
			{28657,45,1}, /* core5 return_Stack7 bit21 */
			{25961,45,1}, /* core5 return_Stack7 bit22 */
			{25962,45,1}, /* core5 return_Stack7 bit23 */
			{25963,45,1}, /* core5 return_Stack7 bit24 */
			{25965,45,1}, /* core5 return_Stack7 bit25 */
			{28660,45,1}, /* core5 return_Stack7 bit26 */
			{32740,45,1}, /* core5 return_Stack7 bit27 */
			{28659,45,1}, /* core5 return_Stack7 bit28 */
			{32739,45,1}, /* core5 return_Stack7 bit29 */
			{32738,45,1}, /* core5 return_Stack7 bit30 */
			{32737,45,1}, /* core5 return_Stack7 bit31 */
			{32768,45,1}, /* core5 return_Stack7 bit32 */
			{32767,45,1}, /* core5 return_Stack7 bit33 */
			{32766,45,1}, /* core5 return_Stack7 bit34 */
			{32765,45,1}, /* core5 return_Stack7 bit35 */
			{28670,45,1}, /* core5 return_Stack7 bit36 */
			{28669,45,1}, /* core5 return_Stack7 bit37 */
			{28672,45,1}, /* core5 return_Stack7 bit38 */
			{28671,45,1}, /* core5 return_Stack7 bit39 */
			{32772,45,1}, /* core5 return_Stack7 bit40 */
			{32771,45,1}, /* core5 return_Stack7 bit41 */
			{32770,45,1}, /* core5 return_Stack7 bit42 */
			{32769,45,1}, /* core5 return_Stack7 bit43 */
			{28666,45,1}, /* core5 return_Stack7 bit44 */
			{28665,45,1}, /* core5 return_Stack7 bit45 */
			{28668,45,1}, /* core5 return_Stack7 bit46 */
			{28667,45,1}, /* core5 return_Stack7 bit47 */
			{25964,45,1}, /* core5 return_Stack7 bit48 */
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
			{ 5668, 8,0}, /* core5 L2_parity_err_count bit0 */
			{ 5667, 8,0}, /* core5 L2_parity_err_count bit1 */
			{ 5666, 8,0}, /* core5 L2_parity_err_count bit2 */
			{ 5665, 8,0}, /* core5 L2_parity_err_count bit3 */
			{ 5664, 8,0}, /* core5 L2_parity_err_count bit4 */
			{ 5663, 8,0}, /* core5 L2_parity_err_count bit5 */
			{ 5662, 8,0}, /* core5 L2_parity_err_count bit6 */
			{ 5661, 8,0}, /* core5 L2_parity_err_count bit7 */
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
			{ 5636, 8,0}, /* core5 L2_parity_index bit0 */
			{ 5635, 8,0}, /* core5 L2_parity_index bit1 */
			{ 5634, 8,0}, /* core5 L2_parity_index bit2 */
			{ 5633, 8,0}, /* core5 L2_parity_index bit3 */
			{ 5632, 8,0}, /* core5 L2_parity_index bit4 */
			{ 5631, 8,0}, /* core5 L2_parity_index bit5 */
			{ 5630, 8,0}, /* core5 L2_parity_index bit6 */
			{ 5629, 8,0}, /* core5 L2_parity_index bit7 */
			{ 5644, 8,0}, /* core5 L2_parity_index bit8 */
			{ 5643, 8,0}, /* core5 L2_parity_index bit9 */
			{ 5642, 8,0}, /* core5 L2_parity_index bit10 */
			{ 5641, 8,0}, /* core5 L2_parity_index bit11 */
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
			{ 5637, 8,0}, /* core5 L2_parity_way bit0 */
			{ 5137, 8,0}, /* core5 L2_parity_way bit1 */
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
			{ 5660, 8,0}, /* core5 L2_parity_banks bit0 */
			{ 5659, 8,0}, /* core5 L2_parity_banks bit1 */
			{ 5658, 8,0}, /* core5 L2_parity_banks bit2 */
			{ 5657, 8,0}, /* core5 L2_parity_banks bit3 */
			{ 5656, 8,0}, /* core5 L2_parity_banks bit4 */
			{ 5655, 8,0}, /* core5 L2_parity_banks bit5 */
			{ 5654, 8,0}, /* core5 L2_parity_banks bit6 */
			{ 5653, 8,0}, /* core5 L2_parity_banks bit7 */
			{ 5652, 8,0}, /* core5 L2_parity_banks bit8 */
			{ 5651, 8,0}, /* core5 L2_parity_banks bit9 */
			{ 5650, 8,0}, /* core5 L2_parity_banks bit10 */
			{ 5649, 8,0}, /* core5 L2_parity_banks bit11 */
			{ 5648, 8,0}, /* core5 L2_parity_banks bit12 */
			{ 5647, 8,0}, /* core5 L2_parity_banks bit13 */
			{ 5646, 8,0}, /* core5 L2_parity_banks bit14 */
			{ 5645, 8,0}, /* core5 L2_parity_banks bit15 */
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
			.i0_pc = {{
			{ 8732,52,0}, /* core6 i0_pc bit0 */
			{10031,52,0}, /* core6 i0_pc bit1 */
			{10032,52,0}, /* core6 i0_pc bit2 */
			{10035,52,0}, /* core6 i0_pc bit3 */
			{ 8751,52,0}, /* core6 i0_pc bit4 */
			{ 8754,52,0}, /* core6 i0_pc bit5 */
			{27051,48,0}, /* core6 i0_pc bit6 */
			{27050,48,0}, /* core6 i0_pc bit7 */
			{27053,48,0}, /* core6 i0_pc bit8 */
			{ 8743,52,0}, /* core6 i0_pc bit9 */
			{10028,52,0}, /* core6 i0_pc bit10 */
			{10037,52,0}, /* core6 i0_pc bit11 */
			{10034,52,0}, /* core6 i0_pc bit12 */
			{ 8734,52,0}, /* core6 i0_pc bit13 */
			{10036,52,0}, /* core6 i0_pc bit14 */
			{ 8733,52,0}, /* core6 i0_pc bit15 */
			{10023,52,0}, /* core6 i0_pc bit16 */
			{10019,52,0}, /* core6 i0_pc bit17 */
			{10020,52,0}, /* core6 i0_pc bit18 */
			{10021,52,0}, /* core6 i0_pc bit19 */
			{10016,52,0}, /* core6 i0_pc bit20 */
			{10017,52,0}, /* core6 i0_pc bit21 */
			{10015,52,0}, /* core6 i0_pc bit22 */
			{10014,52,0}, /* core6 i0_pc bit23 */
			{10024,52,0}, /* core6 i0_pc bit24 */
			{10018,52,0}, /* core6 i0_pc bit25 */
			{10038,52,0}, /* core6 i0_pc bit26 */
			{10040,52,0}, /* core6 i0_pc bit27 */
			{10039,52,0}, /* core6 i0_pc bit28 */
			{ 8735,52,0}, /* core6 i0_pc bit29 */
			{10022,52,0}, /* core6 i0_pc bit30 */
			{10030,52,0}, /* core6 i0_pc bit31 */
			{10029,52,0}, /* core6 i0_pc bit32 */
			{10033,52,0}, /* core6 i0_pc bit33 */
			{10027,52,0}, /* core6 i0_pc bit34 */
			{10025,52,0}, /* core6 i0_pc bit35 */
			{10026,52,0}, /* core6 i0_pc bit36 */
			{10041,52,0}, /* core6 i0_pc bit37 */
			{ 8746,52,0}, /* core6 i0_pc bit38 */
			{ 8744,52,0}, /* core6 i0_pc bit39 */
			{ 8745,52,0}, /* core6 i0_pc bit40 */
			{ 8747,52,0}, /* core6 i0_pc bit41 */
			{ 8737,52,0}, /* core6 i0_pc bit42 */
			{ 8736,52,0}, /* core6 i0_pc bit43 */
			{27046,48,0}, /* core6 i0_pc bit44 */
			{27041,48,0}, /* core6 i0_pc bit45 */
			{ 8755,52,0}, /* core6 i0_pc bit46 */
			{27038,48,0}, /* core6 i0_pc bit47 */
			{27039,48,0}, /* core6 i0_pc bit48 */
			{ 8738,52,0}, /* core6 i0_pc bit49 */
			{ 8752,52,0}, /* core6 i0_pc bit50 */
			{27047,48,0}, /* core6 i0_pc bit51 */
			{27052,48,0}, /* core6 i0_pc bit52 */
			{ 8741,52,0}, /* core6 i0_pc bit53 */
			{ 8740,52,0}, /* core6 i0_pc bit54 */
			{ 8739,52,0}, /* core6 i0_pc bit55 */
			{27040,48,0}, /* core6 i0_pc bit56 */
			{ 8742,52,0}, /* core6 i0_pc bit57 */
			{27048,48,0}, /* core6 i0_pc bit58 */
			{27049,48,0}, /* core6 i0_pc bit59 */
			{ 8753,52,0}, /* core6 i0_pc bit60 */
			{ 8748,52,0}, /* core6 i0_pc bit61 */
			{ 8750,52,0}, /* core6 i0_pc bit62 */
			{ 8749,52,0}, /* core6 i0_pc bit63 */
			}},
			.sram_wr_ptr_0 = {{
			{ 4980,51,0}, /* core6 sram_wr_ptr_0 bit0 */
			{ 4982,51,0}, /* core6 sram_wr_ptr_0 bit1 */
			{ 4981,51,0}, /* core6 sram_wr_ptr_0 bit2 */
			{ 4979,51,0}, /* core6 sram_wr_ptr_0 bit3 */
			{ 4976,51,0}, /* core6 sram_wr_ptr_0 bit4 */
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
			{ 4988,51,0}, /* core6 sram_wr_ptr_1 bit0 */
			{  818,48,0}, /* core6 sram_wr_ptr_1 bit1 */
			{  819,48,0}, /* core6 sram_wr_ptr_1 bit2 */
			{  820,48,0}, /* core6 sram_wr_ptr_1 bit3 */
			{  817,48,0}, /* core6 sram_wr_ptr_1 bit4 */
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
			{ 4990,51,0}, /* core6 sram_wr_ptr_2 bit0 */
			{ 4978,51,0}, /* core6 sram_wr_ptr_2 bit1 */
			{ 4987,51,0}, /* core6 sram_wr_ptr_2 bit2 */
			{ 4977,51,0}, /* core6 sram_wr_ptr_2 bit3 */
			{ 4975,51,0}, /* core6 sram_wr_ptr_2 bit4 */
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
			.L2_parity_err_count = {{
			{ 5065, 8,0}, /* core6 L2_parity_err_count bit0 */
			{ 5062, 8,0}, /* core6 L2_parity_err_count bit1 */
			{ 5043, 8,0}, /* core6 L2_parity_err_count bit2 */
			{ 5055, 8,0}, /* core6 L2_parity_err_count bit3 */
			{ 5051, 8,0}, /* core6 L2_parity_err_count bit4 */
			{ 5050, 8,0}, /* core6 L2_parity_err_count bit5 */
			{ 5048, 8,0}, /* core6 L2_parity_err_count bit6 */
			{ 5047, 8,0}, /* core6 L2_parity_err_count bit7 */
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
			{ 5628, 8,0}, /* core6 L2_parity_index bit0 */
			{ 5627, 8,0}, /* core6 L2_parity_index bit1 */
			{ 5626, 8,0}, /* core6 L2_parity_index bit2 */
			{ 5625, 8,0}, /* core6 L2_parity_index bit3 */
			{ 5624, 8,0}, /* core6 L2_parity_index bit4 */
			{ 5623, 8,0}, /* core6 L2_parity_index bit5 */
			{ 5622, 8,0}, /* core6 L2_parity_index bit6 */
			{ 5621, 8,0}, /* core6 L2_parity_index bit7 */
			{ 5554, 8,0}, /* core6 L2_parity_index bit8 */
			{ 5553, 8,0}, /* core6 L2_parity_index bit9 */
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
			{ 5547, 8,0}, /* core6 L2_parity_way bit0 */
			{ 5135, 8,0}, /* core6 L2_parity_way bit1 */
			{ 5134, 8,0}, /* core6 L2_parity_way bit2 */
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
			{ 5053, 8,0}, /* core6 L2_parity_banks bit0 */
			{ 5045, 8,0}, /* core6 L2_parity_banks bit1 */
			{ 5049, 8,0}, /* core6 L2_parity_banks bit2 */
			{ 5063, 8,0}, /* core6 L2_parity_banks bit3 */
			{ 5052, 8,0}, /* core6 L2_parity_banks bit4 */
			{ 5046, 8,0}, /* core6 L2_parity_banks bit5 */
			{ 5054, 8,0}, /* core6 L2_parity_banks bit6 */
			{ 5061, 8,0}, /* core6 L2_parity_banks bit7 */
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
			.i0_pc = {{
			{ 8732,60,0}, /* core7 i0_pc bit0 */
			{10031,60,0}, /* core7 i0_pc bit1 */
			{10032,60,0}, /* core7 i0_pc bit2 */
			{10035,60,0}, /* core7 i0_pc bit3 */
			{ 8751,60,0}, /* core7 i0_pc bit4 */
			{ 8754,60,0}, /* core7 i0_pc bit5 */
			{27051,56,0}, /* core7 i0_pc bit6 */
			{27050,56,0}, /* core7 i0_pc bit7 */
			{27053,56,0}, /* core7 i0_pc bit8 */
			{ 8743,60,0}, /* core7 i0_pc bit9 */
			{10028,60,0}, /* core7 i0_pc bit10 */
			{10037,60,0}, /* core7 i0_pc bit11 */
			{10034,60,0}, /* core7 i0_pc bit12 */
			{ 8734,60,0}, /* core7 i0_pc bit13 */
			{10036,60,0}, /* core7 i0_pc bit14 */
			{ 8733,60,0}, /* core7 i0_pc bit15 */
			{10023,60,0}, /* core7 i0_pc bit16 */
			{10019,60,0}, /* core7 i0_pc bit17 */
			{10020,60,0}, /* core7 i0_pc bit18 */
			{10021,60,0}, /* core7 i0_pc bit19 */
			{10016,60,0}, /* core7 i0_pc bit20 */
			{10017,60,0}, /* core7 i0_pc bit21 */
			{10015,60,0}, /* core7 i0_pc bit22 */
			{10014,60,0}, /* core7 i0_pc bit23 */
			{10024,60,0}, /* core7 i0_pc bit24 */
			{10018,60,0}, /* core7 i0_pc bit25 */
			{10038,60,0}, /* core7 i0_pc bit26 */
			{10040,60,0}, /* core7 i0_pc bit27 */
			{10039,60,0}, /* core7 i0_pc bit28 */
			{ 8735,60,0}, /* core7 i0_pc bit29 */
			{10022,60,0}, /* core7 i0_pc bit30 */
			{10030,60,0}, /* core7 i0_pc bit31 */
			{10029,60,0}, /* core7 i0_pc bit32 */
			{10033,60,0}, /* core7 i0_pc bit33 */
			{10027,60,0}, /* core7 i0_pc bit34 */
			{10025,60,0}, /* core7 i0_pc bit35 */
			{10026,60,0}, /* core7 i0_pc bit36 */
			{10041,60,0}, /* core7 i0_pc bit37 */
			{ 8746,60,0}, /* core7 i0_pc bit38 */
			{ 8744,60,0}, /* core7 i0_pc bit39 */
			{ 8745,60,0}, /* core7 i0_pc bit40 */
			{ 8747,60,0}, /* core7 i0_pc bit41 */
			{ 8737,60,0}, /* core7 i0_pc bit42 */
			{ 8736,60,0}, /* core7 i0_pc bit43 */
			{27046,56,0}, /* core7 i0_pc bit44 */
			{27041,56,0}, /* core7 i0_pc bit45 */
			{ 8755,60,0}, /* core7 i0_pc bit46 */
			{27038,56,0}, /* core7 i0_pc bit47 */
			{27039,56,0}, /* core7 i0_pc bit48 */
			{ 8738,60,0}, /* core7 i0_pc bit49 */
			{ 8752,60,0}, /* core7 i0_pc bit50 */
			{27047,56,0}, /* core7 i0_pc bit51 */
			{27052,56,0}, /* core7 i0_pc bit52 */
			{ 8741,60,0}, /* core7 i0_pc bit53 */
			{ 8740,60,0}, /* core7 i0_pc bit54 */
			{ 8739,60,0}, /* core7 i0_pc bit55 */
			{27040,56,0}, /* core7 i0_pc bit56 */
			{ 8742,60,0}, /* core7 i0_pc bit57 */
			{27048,56,0}, /* core7 i0_pc bit58 */
			{27049,56,0}, /* core7 i0_pc bit59 */
			{ 8753,60,0}, /* core7 i0_pc bit60 */
			{ 8748,60,0}, /* core7 i0_pc bit61 */
			{ 8750,60,0}, /* core7 i0_pc bit62 */
			{ 8749,60,0}, /* core7 i0_pc bit63 */
			}},
			.sram_wr_ptr_0 = {{
			{ 4980,59,0}, /* core7 sram_wr_ptr_0 bit0 */
			{ 4982,59,0}, /* core7 sram_wr_ptr_0 bit1 */
			{ 4981,59,0}, /* core7 sram_wr_ptr_0 bit2 */
			{ 4979,59,0}, /* core7 sram_wr_ptr_0 bit3 */
			{ 4976,59,0}, /* core7 sram_wr_ptr_0 bit4 */
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
			{ 4988,59,0}, /* core7 sram_wr_ptr_1 bit0 */
			{  818,56,0}, /* core7 sram_wr_ptr_1 bit1 */
			{  819,56,0}, /* core7 sram_wr_ptr_1 bit2 */
			{  820,56,0}, /* core7 sram_wr_ptr_1 bit3 */
			{  817,56,0}, /* core7 sram_wr_ptr_1 bit4 */
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
			{ 4990,59,0}, /* core7 sram_wr_ptr_2 bit0 */
			{ 4978,59,0}, /* core7 sram_wr_ptr_2 bit1 */
			{ 4987,59,0}, /* core7 sram_wr_ptr_2 bit2 */
			{ 4977,59,0}, /* core7 sram_wr_ptr_2 bit3 */
			{ 4975,59,0}, /* core7 sram_wr_ptr_2 bit4 */
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
			.L2_parity_err_count = {{
			{ 5044, 8,0}, /* core7 L2_parity_err_count bit0 */
			{ 5614, 8,0}, /* core7 L2_parity_err_count bit1 */
			{ 5613, 8,0}, /* core7 L2_parity_err_count bit2 */
			{ 5131, 8,0}, /* core7 L2_parity_err_count bit3 */
			{ 5130, 8,0}, /* core7 L2_parity_err_count bit4 */
			{ 5129, 8,0}, /* core7 L2_parity_err_count bit5 */
			{ 5128, 8,0}, /* core7 L2_parity_err_count bit6 */
			{ 5040, 8,0}, /* core7 L2_parity_err_count bit7 */
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
			{ 5546, 8,0}, /* core7 L2_parity_index bit0 */
			{ 5545, 8,0}, /* core7 L2_parity_index bit1 */
			{ 5544, 8,0}, /* core7 L2_parity_index bit2 */
			{ 5543, 8,0}, /* core7 L2_parity_index bit3 */
			{ 5542, 8,0}, /* core7 L2_parity_index bit4 */
			{ 5541, 8,0}, /* core7 L2_parity_index bit5 */
			{ 5540, 8,0}, /* core7 L2_parity_index bit6 */
			{ 5539, 8,0}, /* core7 L2_parity_index bit7 */
			{ 5538, 8,0}, /* core7 L2_parity_index bit8 */
			{ 5537, 8,0}, /* core7 L2_parity_index bit9 */
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
			{ 5531, 8,0}, /* core7 L2_parity_way bit0 */
			{ 5133, 8,0}, /* core7 L2_parity_way bit1 */
			{ 5132, 8,0}, /* core7 L2_parity_way bit2 */
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
			{ 5612, 8,0}, /* core7 L2_parity_banks bit0 */
			{ 5611, 8,0}, /* core7 L2_parity_banks bit1 */
			{ 5610, 8,0}, /* core7 L2_parity_banks bit2 */
			{ 5039, 8,0}, /* core7 L2_parity_banks bit3 */
			{ 5609, 8,0}, /* core7 L2_parity_banks bit4 */
			{ 5608, 8,0}, /* core7 L2_parity_banks bit5 */
			{ 5607, 8,0}, /* core7 L2_parity_banks bit6 */
			{ 5606, 8,0}, /* core7 L2_parity_banks bit7 */
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
