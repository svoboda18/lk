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
};

struct power_spec {
	struct reg_collector power_state;
};

struct power_spec spmc_power_state[] = {
                {
			.power_state = {{
			{    0, 0,0}, /* core0 power on */
			{    0,10,0}, /* core0 retention on */
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
	{		/* core 1 */
			.power_state = {{
			{    0, 1,0}, /* core1 power on */
			{    0,11,0}, /* core1 retention on */
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
	{		/* core 2 */
			.power_state = {{
			{    0, 2,0}, /* core2 power on */
			{    0,12,0}, /* core2 retention on */
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
	{		/* core 3 */
			.power_state = {{
			{    0, 3,0}, /* core3 power on */
			{    0,13,0}, /* core3 retention on */
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
	{		/* core 4 */
			.power_state = {{
			{    0,32,0}, /* core4 power on */
			{    0,42,0}, /* core4 retention on */
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
	{		/* core 5 */
			.power_state = {{
			{    0,33,0}, /* core5 power on */
			{    0,43,0}, /* core5 retention on */
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
	{		/* core 6 */
			.power_state = {{
			{    0,34,0}, /* core6 power on */
			{    0,44,0}, /* core6 retention on */
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
	{		/* core 7 */
			.power_state = {{
			{    0,35,0}, /* core7 power on */
			{    0,45,0}, /* core7 retention on */
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

struct little_core_spec little_core[] = {
	{		/* core 0 */ 
			.pc = {{
			{ 6231, 1,0}, /* core0 pc bit0 */
			{ 6232, 1,0}, /* core0 pc bit1 */
			{ 6233, 1,0}, /* core0 pc bit2 */
			{ 6234, 1,0}, /* core0 pc bit3 */
			{ 6296, 1,0}, /* core0 pc bit4 */
			{ 6297, 1,0}, /* core0 pc bit5 */
			{ 6298, 1,0}, /* core0 pc bit6 */
			{ 6299, 1,0}, /* core0 pc bit7 */
			{ 6340, 1,0}, /* core0 pc bit8 */
			{ 6341, 1,0}, /* core0 pc bit9 */
			{ 6342, 1,0}, /* core0 pc bit10 */
			{ 6343, 1,0}, /* core0 pc bit11 */
			{ 6480, 1,0}, /* core0 pc bit12 */
			{ 6481, 1,0}, /* core0 pc bit13 */
			{ 6482, 1,0}, /* core0 pc bit14 */
			{ 6483, 1,0}, /* core0 pc bit15 */
			{ 6692, 1,0}, /* core0 pc bit16 */
			{ 6693, 1,0}, /* core0 pc bit17 */
			{ 6694, 1,0}, /* core0 pc bit18 */
			{ 6695, 1,0}, /* core0 pc bit19 */
			{ 6352, 1,0}, /* core0 pc bit20 */
			{ 6353, 1,0}, /* core0 pc bit21 */
			{ 6354, 1,0}, /* core0 pc bit22 */
			{ 6355, 1,0}, /* core0 pc bit23 */
			{ 6696, 1,0}, /* core0 pc bit24 */
			{ 6697, 1,0}, /* core0 pc bit25 */
			{ 6698, 1,0}, /* core0 pc bit26 */
			{ 6699, 1,0}, /* core0 pc bit27 */
			{ 6328, 1,0}, /* core0 pc bit28 */
			{ 6329, 1,0}, /* core0 pc bit29 */
			{ 6330, 1,0}, /* core0 pc bit30 */
			{ 6331, 1,0}, /* core0 pc bit31 */
			{13288, 1,0}, /* core0 pc bit32 */
			{13289, 1,0}, /* core0 pc bit33 */
			{13290, 1,0}, /* core0 pc bit34 */
			{13291, 1,0}, /* core0 pc bit35 */
			{13280, 1,0}, /* core0 pc bit36 */
			{13281, 1,0}, /* core0 pc bit37 */
			{13282, 1,0}, /* core0 pc bit38 */
			{13283, 1,0}, /* core0 pc bit39 */
			{13268, 1,0}, /* core0 pc bit40 */
			{13269, 1,0}, /* core0 pc bit41 */
			{13270, 1,0}, /* core0 pc bit42 */
			{13271, 1,0}, /* core0 pc bit43 */
			{13284, 1,0}, /* core0 pc bit44 */
			{13285, 1,0}, /* core0 pc bit45 */
			{13286, 1,0}, /* core0 pc bit46 */
			{13287, 1,0}, /* core0 pc bit47 */
			{13264, 1,0}, /* core0 pc bit48 */
			{13265, 1,0}, /* core0 pc bit49 */
			{13266, 1,0}, /* core0 pc bit50 */
			{13267, 1,0}, /* core0 pc bit51 */
			{13272, 1,0}, /* core0 pc bit52 */
			{13273, 1,0}, /* core0 pc bit53 */
			{13274, 1,0}, /* core0 pc bit54 */
			{13275, 1,0}, /* core0 pc bit55 */
			{13292, 1,0}, /* core0 pc bit56 */
			{13293, 1,0}, /* core0 pc bit57 */
			{13294, 1,0}, /* core0 pc bit58 */
			{13295, 1,0}, /* core0 pc bit59 */
			{13276, 1,0}, /* core0 pc bit60 */
			{13277, 1,0}, /* core0 pc bit61 */
			{13278, 1,0}, /* core0 pc bit62 */
			{13279, 1,0}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{ 6012, 1,0}, /* core0 sp32 bit0 */
			{ 6013, 1,0}, /* core0 sp32 bit1 */
			{ 6014, 1,0}, /* core0 sp32 bit2 */
			{ 6015, 1,0}, /* core0 sp32 bit3 */
			{ 6188, 1,0}, /* core0 sp32 bit4 */
			{ 6189, 1,0}, /* core0 sp32 bit5 */
			{ 6190, 1,0}, /* core0 sp32 bit6 */
			{ 6191, 1,0}, /* core0 sp32 bit7 */
			{ 6992, 1,0}, /* core0 sp32 bit8 */
			{ 6993, 1,0}, /* core0 sp32 bit9 */
			{ 6994, 1,0}, /* core0 sp32 bit10 */
			{ 6995, 1,0}, /* core0 sp32 bit11 */
			{ 6872, 1,0}, /* core0 sp32 bit12 */
			{ 6873, 1,0}, /* core0 sp32 bit13 */
			{ 6874, 1,0}, /* core0 sp32 bit14 */
			{ 6875, 1,0}, /* core0 sp32 bit15 */
			{ 6884, 1,0}, /* core0 sp32 bit16 */
			{ 6885, 1,0}, /* core0 sp32 bit17 */
			{ 6886, 1,0}, /* core0 sp32 bit18 */
			{ 6887, 1,0}, /* core0 sp32 bit19 */
			{ 6944, 1,0}, /* core0 sp32 bit20 */
			{ 6945, 1,0}, /* core0 sp32 bit21 */
			{ 6946, 1,0}, /* core0 sp32 bit22 */
			{ 6947, 1,0}, /* core0 sp32 bit23 */
			{ 6880, 1,0}, /* core0 sp32 bit24 */
			{ 6881, 1,0}, /* core0 sp32 bit25 */
			{ 6882, 1,0}, /* core0 sp32 bit26 */
			{ 6883, 1,0}, /* core0 sp32 bit27 */
			{ 6980, 1,0}, /* core0 sp32 bit28 */
			{ 6981, 1,0}, /* core0 sp32 bit29 */
			{ 6982, 1,0}, /* core0 sp32 bit30 */
			{ 6983, 1,0}, /* core0 sp32 bit31 */
			{11004, 1,0}, /* core0 sp32 bit32 */
			{11005, 1,0}, /* core0 sp32 bit33 */
			{11006, 1,0}, /* core0 sp32 bit34 */
			{11007, 1,0}, /* core0 sp32 bit35 */
			{ 2324, 2,0}, /* core0 sp32 bit36 */
			{ 2325, 2,0}, /* core0 sp32 bit37 */
			{ 2326, 2,0}, /* core0 sp32 bit38 */
			{ 2327, 2,0}, /* core0 sp32 bit39 */
			{ 2316, 2,0}, /* core0 sp32 bit40 */
			{ 2317, 2,0}, /* core0 sp32 bit41 */
			{ 2318, 2,0}, /* core0 sp32 bit42 */
			{ 2319, 2,0}, /* core0 sp32 bit43 */
			{ 2312, 2,0}, /* core0 sp32 bit44 */
			{ 2313, 2,0}, /* core0 sp32 bit45 */
			{ 2314, 2,0}, /* core0 sp32 bit46 */
			{ 2315, 2,0}, /* core0 sp32 bit47 */
			{ 2308, 2,0}, /* core0 sp32 bit48 */
			{ 2309, 2,0}, /* core0 sp32 bit49 */
			{ 2310, 2,0}, /* core0 sp32 bit50 */
			{ 2311, 2,0}, /* core0 sp32 bit51 */
			{11072, 1,0}, /* core0 sp32 bit52 */
			{11073, 1,0}, /* core0 sp32 bit53 */
			{11074, 1,0}, /* core0 sp32 bit54 */
			{11075, 1,0}, /* core0 sp32 bit55 */
			{11036, 1,0}, /* core0 sp32 bit56 */
			{11037, 1,0}, /* core0 sp32 bit57 */
			{11038, 1,0}, /* core0 sp32 bit58 */
			{11039, 1,0}, /* core0 sp32 bit59 */
			{11024, 1,0}, /* core0 sp32 bit60 */
			{11025, 1,0}, /* core0 sp32 bit61 */
			{11026, 1,0}, /* core0 sp32 bit62 */
			{11027, 1,0}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7136, 1,0}, /* core0 fp32 bit0 */
			{ 7137, 1,0}, /* core0 fp32 bit1 */
			{ 7138, 1,0}, /* core0 fp32 bit2 */
			{ 7139, 1,0}, /* core0 fp32 bit3 */
			{ 7152, 1,0}, /* core0 fp32 bit4 */
			{ 7153, 1,0}, /* core0 fp32 bit5 */
			{ 7154, 1,0}, /* core0 fp32 bit6 */
			{ 7155, 1,0}, /* core0 fp32 bit7 */
			{   32, 1,0}, /* core0 fp32 bit8 */
			{   33, 1,0}, /* core0 fp32 bit9 */
			{   34, 1,0}, /* core0 fp32 bit10 */
			{   35, 1,0}, /* core0 fp32 bit11 */
			{ 8444, 1,0}, /* core0 fp32 bit12 */
			{ 8445, 1,0}, /* core0 fp32 bit13 */
			{ 8446, 1,0}, /* core0 fp32 bit14 */
			{ 8447, 1,0}, /* core0 fp32 bit15 */
			{ 8440, 1,0}, /* core0 fp32 bit16 */
			{ 8441, 1,0}, /* core0 fp32 bit17 */
			{ 8442, 1,0}, /* core0 fp32 bit18 */
			{ 8443, 1,0}, /* core0 fp32 bit19 */
			{ 7080, 1,0}, /* core0 fp32 bit20 */
			{ 7081, 1,0}, /* core0 fp32 bit21 */
			{ 7082, 1,0}, /* core0 fp32 bit22 */
			{ 7083, 1,0}, /* core0 fp32 bit23 */
			{ 8424, 1,0}, /* core0 fp32 bit24 */
			{ 8425, 1,0}, /* core0 fp32 bit25 */
			{ 8426, 1,0}, /* core0 fp32 bit26 */
			{ 8427, 1,0}, /* core0 fp32 bit27 */
			{ 8216, 1,0}, /* core0 fp32 bit28 */
			{ 8217, 1,0}, /* core0 fp32 bit29 */
			{ 8218, 1,0}, /* core0 fp32 bit30 */
			{ 8219, 1,0}, /* core0 fp32 bit31 */
			{ 7516, 1,0}, /* core0 fp32 bit32 */
			{ 7517, 1,0}, /* core0 fp32 bit33 */
			{ 7518, 1,0}, /* core0 fp32 bit34 */
			{ 7519, 1,0}, /* core0 fp32 bit35 */
			{ 7592, 1,0}, /* core0 fp32 bit36 */
			{ 7593, 1,0}, /* core0 fp32 bit37 */
			{ 7594, 1,0}, /* core0 fp32 bit38 */
			{ 7595, 1,0}, /* core0 fp32 bit39 */
			{ 7484, 1,0}, /* core0 fp32 bit40 */
			{ 7485, 1,0}, /* core0 fp32 bit41 */
			{ 7486, 1,0}, /* core0 fp32 bit42 */
			{ 7487, 1,0}, /* core0 fp32 bit43 */
			{ 7476, 1,0}, /* core0 fp32 bit44 */
			{ 7477, 1,0}, /* core0 fp32 bit45 */
			{ 7478, 1,0}, /* core0 fp32 bit46 */
			{ 7479, 1,0}, /* core0 fp32 bit47 */
			{ 7480, 1,0}, /* core0 fp32 bit48 */
			{ 7481, 1,0}, /* core0 fp32 bit49 */
			{ 7482, 1,0}, /* core0 fp32 bit50 */
			{ 7483, 1,0}, /* core0 fp32 bit51 */
			{ 8128, 1,0}, /* core0 fp32 bit52 */
			{ 8129, 1,0}, /* core0 fp32 bit53 */
			{ 8130, 1,0}, /* core0 fp32 bit54 */
			{ 8131, 1,0}, /* core0 fp32 bit55 */
			{ 8132, 1,0}, /* core0 fp32 bit56 */
			{ 8133, 1,0}, /* core0 fp32 bit57 */
			{ 8134, 1,0}, /* core0 fp32 bit58 */
			{ 8135, 1,0}, /* core0 fp32 bit59 */
			{ 7616, 1,0}, /* core0 fp32 bit60 */
			{ 7617, 1,0}, /* core0 fp32 bit61 */
			{ 7618, 1,0}, /* core0 fp32 bit62 */
			{ 7619, 1,0}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{ 6211, 1,0}, /* core0 fp64 bit0 */
			{ 6212, 1,0}, /* core0 fp64 bit1 */
			{ 6213, 1,0}, /* core0 fp64 bit2 */
			{ 6214, 1,0}, /* core0 fp64 bit3 */
			{ 6276, 1,0}, /* core0 fp64 bit4 */
			{ 6277, 1,0}, /* core0 fp64 bit5 */
			{ 6278, 1,0}, /* core0 fp64 bit6 */
			{ 6279, 1,0}, /* core0 fp64 bit7 */
			{ 6376, 1,0}, /* core0 fp64 bit8 */
			{ 6377, 1,0}, /* core0 fp64 bit9 */
			{ 6378, 1,0}, /* core0 fp64 bit10 */
			{ 6379, 1,0}, /* core0 fp64 bit11 */
			{ 6476, 1,0}, /* core0 fp64 bit12 */
			{ 6477, 1,0}, /* core0 fp64 bit13 */
			{ 6478, 1,0}, /* core0 fp64 bit14 */
			{ 6479, 1,0}, /* core0 fp64 bit15 */
			{ 6684, 1,0}, /* core0 fp64 bit16 */
			{ 6685, 1,0}, /* core0 fp64 bit17 */
			{ 6686, 1,0}, /* core0 fp64 bit18 */
			{ 6687, 1,0}, /* core0 fp64 bit19 */
			{ 6356, 1,0}, /* core0 fp64 bit20 */
			{ 6357, 1,0}, /* core0 fp64 bit21 */
			{ 6358, 1,0}, /* core0 fp64 bit22 */
			{ 6359, 1,0}, /* core0 fp64 bit23 */
			{ 6688, 1,0}, /* core0 fp64 bit24 */
			{ 6689, 1,0}, /* core0 fp64 bit25 */
			{ 6690, 1,0}, /* core0 fp64 bit26 */
			{ 6691, 1,0}, /* core0 fp64 bit27 */
			{ 6392, 1,0}, /* core0 fp64 bit28 */
			{ 6393, 1,0}, /* core0 fp64 bit29 */
			{ 6394, 1,0}, /* core0 fp64 bit30 */
			{ 6395, 1,0}, /* core0 fp64 bit31 */
			{ 7908, 1,0}, /* core0 fp64 bit32 */
			{ 7909, 1,0}, /* core0 fp64 bit33 */
			{ 7910, 1,0}, /* core0 fp64 bit34 */
			{ 7911, 1,0}, /* core0 fp64 bit35 */
			{ 8260, 1,0}, /* core0 fp64 bit36 */
			{ 8261, 1,0}, /* core0 fp64 bit37 */
			{ 8262, 1,0}, /* core0 fp64 bit38 */
			{ 8263, 1,0}, /* core0 fp64 bit39 */
			{ 8272, 1,0}, /* core0 fp64 bit40 */
			{ 8273, 1,0}, /* core0 fp64 bit41 */
			{ 8274, 1,0}, /* core0 fp64 bit42 */
			{ 8275, 1,0}, /* core0 fp64 bit43 */
			{ 8276, 1,0}, /* core0 fp64 bit44 */
			{ 8277, 1,0}, /* core0 fp64 bit45 */
			{ 8278, 1,0}, /* core0 fp64 bit46 */
			{ 8279, 1,0}, /* core0 fp64 bit47 */
			{ 8312, 1,0}, /* core0 fp64 bit48 */
			{ 8313, 1,0}, /* core0 fp64 bit49 */
			{ 8314, 1,0}, /* core0 fp64 bit50 */
			{ 8315, 1,0}, /* core0 fp64 bit51 */
			{ 8320, 1,0}, /* core0 fp64 bit52 */
			{ 8321, 1,0}, /* core0 fp64 bit53 */
			{ 8322, 1,0}, /* core0 fp64 bit54 */
			{ 8323, 1,0}, /* core0 fp64 bit55 */
			{ 7900, 1,0}, /* core0 fp64 bit56 */
			{ 7901, 1,0}, /* core0 fp64 bit57 */
			{ 7902, 1,0}, /* core0 fp64 bit58 */
			{ 7903, 1,0}, /* core0 fp64 bit59 */
			{ 7968, 1,0}, /* core0 fp64 bit60 */
			{ 7969, 1,0}, /* core0 fp64 bit61 */
			{ 7970, 1,0}, /* core0 fp64 bit62 */
			{ 7971, 1,0}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 6132, 1,0}, /* core0 sp_EL0 bit0 */
			{ 6133, 1,0}, /* core0 sp_EL0 bit1 */
			{ 6134, 1,0}, /* core0 sp_EL0 bit2 */
			{ 6135, 1,0}, /* core0 sp_EL0 bit3 */
			{ 6260, 1,0}, /* core0 sp_EL0 bit4 */
			{ 6261, 1,0}, /* core0 sp_EL0 bit5 */
			{ 6262, 1,0}, /* core0 sp_EL0 bit6 */
			{ 6263, 1,0}, /* core0 sp_EL0 bit7 */
			{ 6236, 1,0}, /* core0 sp_EL0 bit8 */
			{ 6237, 1,0}, /* core0 sp_EL0 bit9 */
			{ 6238, 1,0}, /* core0 sp_EL0 bit10 */
			{ 6239, 1,0}, /* core0 sp_EL0 bit11 */
			{ 6452, 1,0}, /* core0 sp_EL0 bit12 */
			{ 6453, 1,0}, /* core0 sp_EL0 bit13 */
			{ 6454, 1,0}, /* core0 sp_EL0 bit14 */
			{ 6455, 1,0}, /* core0 sp_EL0 bit15 */
			{ 6740, 1,0}, /* core0 sp_EL0 bit16 */
			{ 6741, 1,0}, /* core0 sp_EL0 bit17 */
			{ 6742, 1,0}, /* core0 sp_EL0 bit18 */
			{ 6743, 1,0}, /* core0 sp_EL0 bit19 */
			{ 6432, 1,0}, /* core0 sp_EL0 bit20 */
			{ 6433, 1,0}, /* core0 sp_EL0 bit21 */
			{ 6434, 1,0}, /* core0 sp_EL0 bit22 */
			{ 6435, 1,0}, /* core0 sp_EL0 bit23 */
			{ 6736, 1,0}, /* core0 sp_EL0 bit24 */
			{ 6737, 1,0}, /* core0 sp_EL0 bit25 */
			{ 6738, 1,0}, /* core0 sp_EL0 bit26 */
			{ 6739, 1,0}, /* core0 sp_EL0 bit27 */
			{ 6408, 1,0}, /* core0 sp_EL0 bit28 */
			{ 6409, 1,0}, /* core0 sp_EL0 bit29 */
			{ 6410, 1,0}, /* core0 sp_EL0 bit30 */
			{ 6411, 1,0}, /* core0 sp_EL0 bit31 */
			{ 7916, 1,0}, /* core0 sp_EL0 bit32 */
			{ 7917, 1,0}, /* core0 sp_EL0 bit33 */
			{ 7918, 1,0}, /* core0 sp_EL0 bit34 */
			{ 7919, 1,0}, /* core0 sp_EL0 bit35 */
			{  153, 1,0}, /* core0 sp_EL0 bit36 */
			{  154, 1,0}, /* core0 sp_EL0 bit37 */
			{  155, 1,0}, /* core0 sp_EL0 bit38 */
			{  156, 1,0}, /* core0 sp_EL0 bit39 */
			{  161, 1,0}, /* core0 sp_EL0 bit40 */
			{  162, 1,0}, /* core0 sp_EL0 bit41 */
			{  163, 1,0}, /* core0 sp_EL0 bit42 */
			{  164, 1,0}, /* core0 sp_EL0 bit43 */
			{  165, 1,0}, /* core0 sp_EL0 bit44 */
			{  166, 1,0}, /* core0 sp_EL0 bit45 */
			{  167, 1,0}, /* core0 sp_EL0 bit46 */
			{  168, 1,0}, /* core0 sp_EL0 bit47 */
			{ 7440, 1,0}, /* core0 sp_EL0 bit48 */
			{ 7441, 1,0}, /* core0 sp_EL0 bit49 */
			{ 7442, 1,0}, /* core0 sp_EL0 bit50 */
			{ 7443, 1,0}, /* core0 sp_EL0 bit51 */
			{ 7468, 1,0}, /* core0 sp_EL0 bit52 */
			{ 7469, 1,0}, /* core0 sp_EL0 bit53 */
			{ 7470, 1,0}, /* core0 sp_EL0 bit54 */
			{ 7471, 1,0}, /* core0 sp_EL0 bit55 */
			{ 7892, 1,0}, /* core0 sp_EL0 bit56 */
			{ 7893, 1,0}, /* core0 sp_EL0 bit57 */
			{ 7894, 1,0}, /* core0 sp_EL0 bit58 */
			{ 7895, 1,0}, /* core0 sp_EL0 bit59 */
			{ 7948, 1,0}, /* core0 sp_EL0 bit60 */
			{ 7949, 1,0}, /* core0 sp_EL0 bit61 */
			{ 7950, 1,0}, /* core0 sp_EL0 bit62 */
			{ 7951, 1,0}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6215, 1,0}, /* core0 sp_EL1 bit0 */
			{ 6216, 1,0}, /* core0 sp_EL1 bit1 */
			{ 6217, 1,0}, /* core0 sp_EL1 bit2 */
			{ 6218, 1,0}, /* core0 sp_EL1 bit3 */
			{ 6272, 1,0}, /* core0 sp_EL1 bit4 */
			{ 6273, 1,0}, /* core0 sp_EL1 bit5 */
			{ 6274, 1,0}, /* core0 sp_EL1 bit6 */
			{ 6275, 1,0}, /* core0 sp_EL1 bit7 */
			{ 6380, 1,0}, /* core0 sp_EL1 bit8 */
			{ 6381, 1,0}, /* core0 sp_EL1 bit9 */
			{ 6382, 1,0}, /* core0 sp_EL1 bit10 */
			{ 6383, 1,0}, /* core0 sp_EL1 bit11 */
			{ 6472, 1,0}, /* core0 sp_EL1 bit12 */
			{ 6473, 1,0}, /* core0 sp_EL1 bit13 */
			{ 6474, 1,0}, /* core0 sp_EL1 bit14 */
			{ 6475, 1,0}, /* core0 sp_EL1 bit15 */
			{ 6648, 1,0}, /* core0 sp_EL1 bit16 */
			{ 6649, 1,0}, /* core0 sp_EL1 bit17 */
			{ 6650, 1,0}, /* core0 sp_EL1 bit18 */
			{ 6651, 1,0}, /* core0 sp_EL1 bit19 */
			{ 6976, 1,0}, /* core0 sp_EL1 bit20 */
			{ 6977, 1,0}, /* core0 sp_EL1 bit21 */
			{ 6978, 1,0}, /* core0 sp_EL1 bit22 */
			{ 6979, 1,0}, /* core0 sp_EL1 bit23 */
			{ 6652, 1,0}, /* core0 sp_EL1 bit24 */
			{ 6653, 1,0}, /* core0 sp_EL1 bit25 */
			{ 6654, 1,0}, /* core0 sp_EL1 bit26 */
			{ 6655, 1,0}, /* core0 sp_EL1 bit27 */
			{ 6388, 1,0}, /* core0 sp_EL1 bit28 */
			{ 6389, 1,0}, /* core0 sp_EL1 bit29 */
			{ 6390, 1,0}, /* core0 sp_EL1 bit30 */
			{ 6391, 1,0}, /* core0 sp_EL1 bit31 */
			{ 7904, 1,0}, /* core0 sp_EL1 bit32 */
			{ 7905, 1,0}, /* core0 sp_EL1 bit33 */
			{ 7906, 1,0}, /* core0 sp_EL1 bit34 */
			{ 7907, 1,0}, /* core0 sp_EL1 bit35 */
			{ 8304, 1,0}, /* core0 sp_EL1 bit36 */
			{ 8305, 1,0}, /* core0 sp_EL1 bit37 */
			{ 8306, 1,0}, /* core0 sp_EL1 bit38 */
			{ 8307, 1,0}, /* core0 sp_EL1 bit39 */
			{ 8296, 1,0}, /* core0 sp_EL1 bit40 */
			{ 8297, 1,0}, /* core0 sp_EL1 bit41 */
			{ 8298, 1,0}, /* core0 sp_EL1 bit42 */
			{ 8299, 1,0}, /* core0 sp_EL1 bit43 */
			{ 8292, 1,0}, /* core0 sp_EL1 bit44 */
			{ 8293, 1,0}, /* core0 sp_EL1 bit45 */
			{ 8294, 1,0}, /* core0 sp_EL1 bit46 */
			{ 8295, 1,0}, /* core0 sp_EL1 bit47 */
			{ 8308, 1,0}, /* core0 sp_EL1 bit48 */
			{ 8309, 1,0}, /* core0 sp_EL1 bit49 */
			{ 8310, 1,0}, /* core0 sp_EL1 bit50 */
			{ 8311, 1,0}, /* core0 sp_EL1 bit51 */
			{ 8328, 1,0}, /* core0 sp_EL1 bit52 */
			{ 8329, 1,0}, /* core0 sp_EL1 bit53 */
			{ 8330, 1,0}, /* core0 sp_EL1 bit54 */
			{ 8331, 1,0}, /* core0 sp_EL1 bit55 */
			{ 8336, 1,0}, /* core0 sp_EL1 bit56 */
			{ 8337, 1,0}, /* core0 sp_EL1 bit57 */
			{ 8338, 1,0}, /* core0 sp_EL1 bit58 */
			{ 8339, 1,0}, /* core0 sp_EL1 bit59 */
			{ 7964, 1,0}, /* core0 sp_EL1 bit60 */
			{ 7965, 1,0}, /* core0 sp_EL1 bit61 */
			{ 7966, 1,0}, /* core0 sp_EL1 bit62 */
			{ 7967, 1,0}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 6120, 1,0}, /* core0 sp_EL2 bit0 */
			{ 6121, 1,0}, /* core0 sp_EL2 bit1 */
			{ 6122, 1,0}, /* core0 sp_EL2 bit2 */
			{ 6123, 1,0}, /* core0 sp_EL2 bit3 */
			{ 6148, 1,0}, /* core0 sp_EL2 bit4 */
			{ 6149, 1,0}, /* core0 sp_EL2 bit5 */
			{ 6150, 1,0}, /* core0 sp_EL2 bit6 */
			{ 6151, 1,0}, /* core0 sp_EL2 bit7 */
			{ 6960, 1,0}, /* core0 sp_EL2 bit8 */
			{ 6961, 1,0}, /* core0 sp_EL2 bit9 */
			{ 6962, 1,0}, /* core0 sp_EL2 bit10 */
			{ 6963, 1,0}, /* core0 sp_EL2 bit11 */
			{ 6444, 1,0}, /* core0 sp_EL2 bit12 */
			{ 6445, 1,0}, /* core0 sp_EL2 bit13 */
			{ 6446, 1,0}, /* core0 sp_EL2 bit14 */
			{ 6447, 1,0}, /* core0 sp_EL2 bit15 */
			{ 6912, 1,0}, /* core0 sp_EL2 bit16 */
			{ 6913, 1,0}, /* core0 sp_EL2 bit17 */
			{ 6914, 1,0}, /* core0 sp_EL2 bit18 */
			{ 6915, 1,0}, /* core0 sp_EL2 bit19 */
			{ 6956, 1,0}, /* core0 sp_EL2 bit20 */
			{ 6957, 1,0}, /* core0 sp_EL2 bit21 */
			{ 6958, 1,0}, /* core0 sp_EL2 bit22 */
			{ 6959, 1,0}, /* core0 sp_EL2 bit23 */
			{ 6908, 1,0}, /* core0 sp_EL2 bit24 */
			{ 6909, 1,0}, /* core0 sp_EL2 bit25 */
			{ 6910, 1,0}, /* core0 sp_EL2 bit26 */
			{ 6911, 1,0}, /* core0 sp_EL2 bit27 */
			{ 6168, 1,0}, /* core0 sp_EL2 bit28 */
			{ 6169, 1,0}, /* core0 sp_EL2 bit29 */
			{ 6170, 1,0}, /* core0 sp_EL2 bit30 */
			{ 6171, 1,0}, /* core0 sp_EL2 bit31 */
			{ 7960, 1,0}, /* core0 sp_EL2 bit32 */
			{ 7961, 1,0}, /* core0 sp_EL2 bit33 */
			{ 7962, 1,0}, /* core0 sp_EL2 bit34 */
			{ 7963, 1,0}, /* core0 sp_EL2 bit35 */
			{  141, 1,0}, /* core0 sp_EL2 bit36 */
			{  142, 1,0}, /* core0 sp_EL2 bit37 */
			{  143, 1,0}, /* core0 sp_EL2 bit38 */
			{  144, 1,0}, /* core0 sp_EL2 bit39 */
			{  149, 1,0}, /* core0 sp_EL2 bit40 */
			{  150, 1,0}, /* core0 sp_EL2 bit41 */
			{  151, 1,0}, /* core0 sp_EL2 bit42 */
			{  152, 1,0}, /* core0 sp_EL2 bit43 */
			{  145, 1,0}, /* core0 sp_EL2 bit44 */
			{  146, 1,0}, /* core0 sp_EL2 bit45 */
			{  147, 1,0}, /* core0 sp_EL2 bit46 */
			{  148, 1,0}, /* core0 sp_EL2 bit47 */
			{ 7880, 1,0}, /* core0 sp_EL2 bit48 */
			{ 7881, 1,0}, /* core0 sp_EL2 bit49 */
			{ 7882, 1,0}, /* core0 sp_EL2 bit50 */
			{ 7883, 1,0}, /* core0 sp_EL2 bit51 */
			{ 8332, 1,0}, /* core0 sp_EL2 bit52 */
			{ 8333, 1,0}, /* core0 sp_EL2 bit53 */
			{ 8334, 1,0}, /* core0 sp_EL2 bit54 */
			{ 8335, 1,0}, /* core0 sp_EL2 bit55 */
			{ 7896, 1,0}, /* core0 sp_EL2 bit56 */
			{ 7897, 1,0}, /* core0 sp_EL2 bit57 */
			{ 7898, 1,0}, /* core0 sp_EL2 bit58 */
			{ 7899, 1,0}, /* core0 sp_EL2 bit59 */
			{ 7956, 1,0}, /* core0 sp_EL2 bit60 */
			{ 7957, 1,0}, /* core0 sp_EL2 bit61 */
			{ 7958, 1,0}, /* core0 sp_EL2 bit62 */
			{ 7959, 1,0}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6004, 1,0}, /* core0 sp_EL3 bit0 */
			{ 6005, 1,0}, /* core0 sp_EL3 bit1 */
			{ 6006, 1,0}, /* core0 sp_EL3 bit2 */
			{ 6007, 1,0}, /* core0 sp_EL3 bit3 */
			{ 6000, 1,0}, /* core0 sp_EL3 bit4 */
			{ 6001, 1,0}, /* core0 sp_EL3 bit5 */
			{ 6002, 1,0}, /* core0 sp_EL3 bit6 */
			{ 6003, 1,0}, /* core0 sp_EL3 bit7 */
			{ 6984, 1,0}, /* core0 sp_EL3 bit8 */
			{ 6985, 1,0}, /* core0 sp_EL3 bit9 */
			{ 6986, 1,0}, /* core0 sp_EL3 bit10 */
			{ 6987, 1,0}, /* core0 sp_EL3 bit11 */
			{ 7040, 1,0}, /* core0 sp_EL3 bit12 */
			{ 7041, 1,0}, /* core0 sp_EL3 bit13 */
			{ 7042, 1,0}, /* core0 sp_EL3 bit14 */
			{ 7043, 1,0}, /* core0 sp_EL3 bit15 */
			{ 6888, 1,0}, /* core0 sp_EL3 bit16 */
			{ 6889, 1,0}, /* core0 sp_EL3 bit17 */
			{ 6890, 1,0}, /* core0 sp_EL3 bit18 */
			{ 6891, 1,0}, /* core0 sp_EL3 bit19 */
			{ 7024, 1,0}, /* core0 sp_EL3 bit20 */
			{ 7025, 1,0}, /* core0 sp_EL3 bit21 */
			{ 7026, 1,0}, /* core0 sp_EL3 bit22 */
			{ 7027, 1,0}, /* core0 sp_EL3 bit23 */
			{ 6852, 1,0}, /* core0 sp_EL3 bit24 */
			{ 6853, 1,0}, /* core0 sp_EL3 bit25 */
			{ 6854, 1,0}, /* core0 sp_EL3 bit26 */
			{ 6855, 1,0}, /* core0 sp_EL3 bit27 */
			{ 7220, 1,0}, /* core0 sp_EL3 bit28 */
			{ 7221, 1,0}, /* core0 sp_EL3 bit29 */
			{ 7222, 1,0}, /* core0 sp_EL3 bit30 */
			{ 7223, 1,0}, /* core0 sp_EL3 bit31 */
			{ 8344, 1,0}, /* core0 sp_EL3 bit32 */
			{ 8345, 1,0}, /* core0 sp_EL3 bit33 */
			{ 8346, 1,0}, /* core0 sp_EL3 bit34 */
			{ 8347, 1,0}, /* core0 sp_EL3 bit35 */
			{ 7448, 1,0}, /* core0 sp_EL3 bit36 */
			{ 7449, 1,0}, /* core0 sp_EL3 bit37 */
			{ 7450, 1,0}, /* core0 sp_EL3 bit38 */
			{ 7451, 1,0}, /* core0 sp_EL3 bit39 */
			{ 7872, 1,0}, /* core0 sp_EL3 bit40 */
			{ 7873, 1,0}, /* core0 sp_EL3 bit41 */
			{ 7874, 1,0}, /* core0 sp_EL3 bit42 */
			{ 7875, 1,0}, /* core0 sp_EL3 bit43 */
			{ 7444, 1,0}, /* core0 sp_EL3 bit44 */
			{ 7445, 1,0}, /* core0 sp_EL3 bit45 */
			{ 7446, 1,0}, /* core0 sp_EL3 bit46 */
			{ 7447, 1,0}, /* core0 sp_EL3 bit47 */
			{ 8316, 1,0}, /* core0 sp_EL3 bit48 */
			{ 8317, 1,0}, /* core0 sp_EL3 bit49 */
			{ 8318, 1,0}, /* core0 sp_EL3 bit50 */
			{ 8319, 1,0}, /* core0 sp_EL3 bit51 */
			{ 8248, 1,0}, /* core0 sp_EL3 bit52 */
			{ 8249, 1,0}, /* core0 sp_EL3 bit53 */
			{ 8250, 1,0}, /* core0 sp_EL3 bit54 */
			{ 8251, 1,0}, /* core0 sp_EL3 bit55 */
			{ 7884, 1,0}, /* core0 sp_EL3 bit56 */
			{ 7885, 1,0}, /* core0 sp_EL3 bit57 */
			{ 7886, 1,0}, /* core0 sp_EL3 bit58 */
			{ 7887, 1,0}, /* core0 sp_EL3 bit59 */
			{ 7944, 1,0}, /* core0 sp_EL3 bit60 */
			{ 7945, 1,0}, /* core0 sp_EL3 bit61 */
			{ 7946, 1,0}, /* core0 sp_EL3 bit62 */
			{ 7947, 1,0}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{ 5988, 1,0}, /* core0 elr_EL1 bit0 */
			{ 5989, 1,0}, /* core0 elr_EL1 bit1 */
			{ 5990, 1,0}, /* core0 elr_EL1 bit2 */
			{ 5991, 1,0}, /* core0 elr_EL1 bit3 */
			{ 5996, 1,0}, /* core0 elr_EL1 bit4 */
			{ 5997, 1,0}, /* core0 elr_EL1 bit5 */
			{ 5998, 1,0}, /* core0 elr_EL1 bit6 */
			{ 5999, 1,0}, /* core0 elr_EL1 bit7 */
			{ 6988, 1,0}, /* core0 elr_EL1 bit8 */
			{ 6989, 1,0}, /* core0 elr_EL1 bit9 */
			{ 6990, 1,0}, /* core0 elr_EL1 bit10 */
			{ 6991, 1,0}, /* core0 elr_EL1 bit11 */
			{ 7048, 1,0}, /* core0 elr_EL1 bit12 */
			{ 7049, 1,0}, /* core0 elr_EL1 bit13 */
			{ 7050, 1,0}, /* core0 elr_EL1 bit14 */
			{ 7051, 1,0}, /* core0 elr_EL1 bit15 */
			{ 6896, 1,0}, /* core0 elr_EL1 bit16 */
			{ 6897, 1,0}, /* core0 elr_EL1 bit17 */
			{ 6898, 1,0}, /* core0 elr_EL1 bit18 */
			{ 6899, 1,0}, /* core0 elr_EL1 bit19 */
			{ 6940, 1,0}, /* core0 elr_EL1 bit20 */
			{ 6941, 1,0}, /* core0 elr_EL1 bit21 */
			{ 6942, 1,0}, /* core0 elr_EL1 bit22 */
			{ 6943, 1,0}, /* core0 elr_EL1 bit23 */
			{ 6856, 1,0}, /* core0 elr_EL1 bit24 */
			{ 6857, 1,0}, /* core0 elr_EL1 bit25 */
			{ 6858, 1,0}, /* core0 elr_EL1 bit26 */
			{ 6859, 1,0}, /* core0 elr_EL1 bit27 */
			{ 7216, 1,0}, /* core0 elr_EL1 bit28 */
			{ 7217, 1,0}, /* core0 elr_EL1 bit29 */
			{ 7218, 1,0}, /* core0 elr_EL1 bit30 */
			{ 7219, 1,0}, /* core0 elr_EL1 bit31 */
			{ 8164, 1,0}, /* core0 elr_EL1 bit32 */
			{ 8165, 1,0}, /* core0 elr_EL1 bit33 */
			{ 8166, 1,0}, /* core0 elr_EL1 bit34 */
			{ 8167, 1,0}, /* core0 elr_EL1 bit35 */
			{ 7288, 1,0}, /* core0 elr_EL1 bit36 */
			{ 7289, 1,0}, /* core0 elr_EL1 bit37 */
			{ 7290, 1,0}, /* core0 elr_EL1 bit38 */
			{ 7291, 1,0}, /* core0 elr_EL1 bit39 */
			{ 7428, 1,0}, /* core0 elr_EL1 bit40 */
			{ 7429, 1,0}, /* core0 elr_EL1 bit41 */
			{ 7430, 1,0}, /* core0 elr_EL1 bit42 */
			{ 7431, 1,0}, /* core0 elr_EL1 bit43 */
			{ 7284, 1,0}, /* core0 elr_EL1 bit44 */
			{ 7285, 1,0}, /* core0 elr_EL1 bit45 */
			{ 7286, 1,0}, /* core0 elr_EL1 bit46 */
			{ 7287, 1,0}, /* core0 elr_EL1 bit47 */
			{ 7420, 1,0}, /* core0 elr_EL1 bit48 */
			{ 7421, 1,0}, /* core0 elr_EL1 bit49 */
			{ 7422, 1,0}, /* core0 elr_EL1 bit50 */
			{ 7423, 1,0}, /* core0 elr_EL1 bit51 */
			{ 7860, 1,0}, /* core0 elr_EL1 bit52 */
			{ 7861, 1,0}, /* core0 elr_EL1 bit53 */
			{ 7862, 1,0}, /* core0 elr_EL1 bit54 */
			{ 7863, 1,0}, /* core0 elr_EL1 bit55 */
			{ 7932, 1,0}, /* core0 elr_EL1 bit56 */
			{ 7933, 1,0}, /* core0 elr_EL1 bit57 */
			{ 7934, 1,0}, /* core0 elr_EL1 bit58 */
			{ 7935, 1,0}, /* core0 elr_EL1 bit59 */
			{ 8168, 1,0}, /* core0 elr_EL1 bit60 */
			{ 8169, 1,0}, /* core0 elr_EL1 bit61 */
			{ 8170, 1,0}, /* core0 elr_EL1 bit62 */
			{ 8171, 1,0}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 5992, 1,0}, /* core0 elr_EL2 bit0 */
			{ 5993, 1,0}, /* core0 elr_EL2 bit1 */
			{ 5994, 1,0}, /* core0 elr_EL2 bit2 */
			{ 5995, 1,0}, /* core0 elr_EL2 bit3 */
			{ 6152, 1,0}, /* core0 elr_EL2 bit4 */
			{ 6153, 1,0}, /* core0 elr_EL2 bit5 */
			{ 6154, 1,0}, /* core0 elr_EL2 bit6 */
			{ 6155, 1,0}, /* core0 elr_EL2 bit7 */
			{ 6416, 1,0}, /* core0 elr_EL2 bit8 */
			{ 6417, 1,0}, /* core0 elr_EL2 bit9 */
			{ 6418, 1,0}, /* core0 elr_EL2 bit10 */
			{ 6419, 1,0}, /* core0 elr_EL2 bit11 */
			{ 6924, 1,0}, /* core0 elr_EL2 bit12 */
			{ 6925, 1,0}, /* core0 elr_EL2 bit13 */
			{ 6926, 1,0}, /* core0 elr_EL2 bit14 */
			{ 6927, 1,0}, /* core0 elr_EL2 bit15 */
			{ 6916, 1,0}, /* core0 elr_EL2 bit16 */
			{ 6917, 1,0}, /* core0 elr_EL2 bit17 */
			{ 6918, 1,0}, /* core0 elr_EL2 bit18 */
			{ 6919, 1,0}, /* core0 elr_EL2 bit19 */
			{ 6952, 1,0}, /* core0 elr_EL2 bit20 */
			{ 6953, 1,0}, /* core0 elr_EL2 bit21 */
			{ 6954, 1,0}, /* core0 elr_EL2 bit22 */
			{ 6955, 1,0}, /* core0 elr_EL2 bit23 */
			{ 6904, 1,0}, /* core0 elr_EL2 bit24 */
			{ 6905, 1,0}, /* core0 elr_EL2 bit25 */
			{ 6906, 1,0}, /* core0 elr_EL2 bit26 */
			{ 6907, 1,0}, /* core0 elr_EL2 bit27 */
			{ 7224, 1,0}, /* core0 elr_EL2 bit28 */
			{ 7225, 1,0}, /* core0 elr_EL2 bit29 */
			{ 7226, 1,0}, /* core0 elr_EL2 bit30 */
			{ 7227, 1,0}, /* core0 elr_EL2 bit31 */
			{ 7912, 1,0}, /* core0 elr_EL2 bit32 */
			{ 7913, 1,0}, /* core0 elr_EL2 bit33 */
			{ 7914, 1,0}, /* core0 elr_EL2 bit34 */
			{ 7915, 1,0}, /* core0 elr_EL2 bit35 */
			{ 8300, 1,0}, /* core0 elr_EL2 bit36 */
			{ 8301, 1,0}, /* core0 elr_EL2 bit37 */
			{ 8302, 1,0}, /* core0 elr_EL2 bit38 */
			{ 8303, 1,0}, /* core0 elr_EL2 bit39 */
			{ 8264, 1,0}, /* core0 elr_EL2 bit40 */
			{ 8265, 1,0}, /* core0 elr_EL2 bit41 */
			{ 8266, 1,0}, /* core0 elr_EL2 bit42 */
			{ 8267, 1,0}, /* core0 elr_EL2 bit43 */
			{ 8268, 1,0}, /* core0 elr_EL2 bit44 */
			{ 8269, 1,0}, /* core0 elr_EL2 bit45 */
			{ 8270, 1,0}, /* core0 elr_EL2 bit46 */
			{ 8271, 1,0}, /* core0 elr_EL2 bit47 */
			{ 7456, 1,0}, /* core0 elr_EL2 bit48 */
			{ 7457, 1,0}, /* core0 elr_EL2 bit49 */
			{ 7458, 1,0}, /* core0 elr_EL2 bit50 */
			{ 7459, 1,0}, /* core0 elr_EL2 bit51 */
			{ 7464, 1,0}, /* core0 elr_EL2 bit52 */
			{ 7465, 1,0}, /* core0 elr_EL2 bit53 */
			{ 7466, 1,0}, /* core0 elr_EL2 bit54 */
			{ 7467, 1,0}, /* core0 elr_EL2 bit55 */
			{ 7888, 1,0}, /* core0 elr_EL2 bit56 */
			{ 7889, 1,0}, /* core0 elr_EL2 bit57 */
			{ 7890, 1,0}, /* core0 elr_EL2 bit58 */
			{ 7891, 1,0}, /* core0 elr_EL2 bit59 */
			{ 7936, 1,0}, /* core0 elr_EL2 bit60 */
			{ 7937, 1,0}, /* core0 elr_EL2 bit61 */
			{ 7938, 1,0}, /* core0 elr_EL2 bit62 */
			{ 7939, 1,0}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 6040, 1,0}, /* core0 elr_EL3 bit0 */
			{ 6041, 1,0}, /* core0 elr_EL3 bit1 */
			{ 6042, 1,0}, /* core0 elr_EL3 bit2 */
			{ 6043, 1,0}, /* core0 elr_EL3 bit3 */
			{ 7140, 1,0}, /* core0 elr_EL3 bit4 */
			{ 7141, 1,0}, /* core0 elr_EL3 bit5 */
			{ 7142, 1,0}, /* core0 elr_EL3 bit6 */
			{ 7143, 1,0}, /* core0 elr_EL3 bit7 */
			{ 7180, 1,0}, /* core0 elr_EL3 bit8 */
			{ 7181, 1,0}, /* core0 elr_EL3 bit9 */
			{ 7182, 1,0}, /* core0 elr_EL3 bit10 */
			{ 7183, 1,0}, /* core0 elr_EL3 bit11 */
			{ 7044, 1,0}, /* core0 elr_EL3 bit12 */
			{ 7045, 1,0}, /* core0 elr_EL3 bit13 */
			{ 7046, 1,0}, /* core0 elr_EL3 bit14 */
			{ 7047, 1,0}, /* core0 elr_EL3 bit15 */
			{ 6864, 1,0}, /* core0 elr_EL3 bit16 */
			{ 6865, 1,0}, /* core0 elr_EL3 bit17 */
			{ 6866, 1,0}, /* core0 elr_EL3 bit18 */
			{ 6867, 1,0}, /* core0 elr_EL3 bit19 */
			{ 7028, 1,0}, /* core0 elr_EL3 bit20 */
			{ 7029, 1,0}, /* core0 elr_EL3 bit21 */
			{ 7030, 1,0}, /* core0 elr_EL3 bit22 */
			{ 7031, 1,0}, /* core0 elr_EL3 bit23 */
			{ 6860, 1,0}, /* core0 elr_EL3 bit24 */
			{ 6861, 1,0}, /* core0 elr_EL3 bit25 */
			{ 6862, 1,0}, /* core0 elr_EL3 bit26 */
			{ 6863, 1,0}, /* core0 elr_EL3 bit27 */
			{ 7204, 1,0}, /* core0 elr_EL3 bit28 */
			{ 7205, 1,0}, /* core0 elr_EL3 bit29 */
			{ 7206, 1,0}, /* core0 elr_EL3 bit30 */
			{ 7207, 1,0}, /* core0 elr_EL3 bit31 */
			{ 8340, 1,0}, /* core0 elr_EL3 bit32 */
			{ 8341, 1,0}, /* core0 elr_EL3 bit33 */
			{ 8342, 1,0}, /* core0 elr_EL3 bit34 */
			{ 8343, 1,0}, /* core0 elr_EL3 bit35 */
			{ 8252, 1,0}, /* core0 elr_EL3 bit36 */
			{ 8253, 1,0}, /* core0 elr_EL3 bit37 */
			{ 8254, 1,0}, /* core0 elr_EL3 bit38 */
			{ 8255, 1,0}, /* core0 elr_EL3 bit39 */
			{ 7868, 1,0}, /* core0 elr_EL3 bit40 */
			{ 7869, 1,0}, /* core0 elr_EL3 bit41 */
			{ 7870, 1,0}, /* core0 elr_EL3 bit42 */
			{ 7871, 1,0}, /* core0 elr_EL3 bit43 */
			{ 7864, 1,0}, /* core0 elr_EL3 bit44 */
			{ 7865, 1,0}, /* core0 elr_EL3 bit45 */
			{ 7866, 1,0}, /* core0 elr_EL3 bit46 */
			{ 7867, 1,0}, /* core0 elr_EL3 bit47 */
			{ 7876, 1,0}, /* core0 elr_EL3 bit48 */
			{ 7877, 1,0}, /* core0 elr_EL3 bit49 */
			{ 7878, 1,0}, /* core0 elr_EL3 bit50 */
			{ 7879, 1,0}, /* core0 elr_EL3 bit51 */
			{ 8324, 1,0}, /* core0 elr_EL3 bit52 */
			{ 8325, 1,0}, /* core0 elr_EL3 bit53 */
			{ 8326, 1,0}, /* core0 elr_EL3 bit54 */
			{ 8327, 1,0}, /* core0 elr_EL3 bit55 */
			{ 7924, 1,0}, /* core0 elr_EL3 bit56 */
			{ 7925, 1,0}, /* core0 elr_EL3 bit57 */
			{ 7926, 1,0}, /* core0 elr_EL3 bit58 */
			{ 7927, 1,0}, /* core0 elr_EL3 bit59 */
			{ 7940, 1,0}, /* core0 elr_EL3 bit60 */
			{ 7941, 1,0}, /* core0 elr_EL3 bit61 */
			{ 7942, 1,0}, /* core0 elr_EL3 bit62 */
			{ 7943, 1,0}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 8448, 2,0}, /* core0 raw_pc bit0 */
			{10692, 1,0}, /* core0 raw_pc bit1 */
			{10693, 1,0}, /* core0 raw_pc bit2 */
			{ 9360, 1,0}, /* core0 raw_pc bit3 */
			{ 9361, 1,0}, /* core0 raw_pc bit4 */
			{ 9362, 1,0}, /* core0 raw_pc bit5 */
			{ 9363, 1,0}, /* core0 raw_pc bit6 */
			{12608, 1,0}, /* core0 raw_pc bit7 */
			{12609, 1,0}, /* core0 raw_pc bit8 */
			{12610, 1,0}, /* core0 raw_pc bit9 */
			{12611, 1,0}, /* core0 raw_pc bit10 */
			{12580, 1,0}, /* core0 raw_pc bit11 */
			{12581, 1,0}, /* core0 raw_pc bit12 */
			{12582, 1,0}, /* core0 raw_pc bit13 */
			{12583, 1,0}, /* core0 raw_pc bit14 */
			{12584, 1,0}, /* core0 raw_pc bit15 */
			{12585, 1,0}, /* core0 raw_pc bit16 */
			{12586, 1,0}, /* core0 raw_pc bit17 */
			{12587, 1,0}, /* core0 raw_pc bit18 */
			{12576, 1,0}, /* core0 raw_pc bit19 */
			{12577, 1,0}, /* core0 raw_pc bit20 */
			{12578, 1,0}, /* core0 raw_pc bit21 */
			{12579, 1,0}, /* core0 raw_pc bit22 */
			{ 9376, 1,0}, /* core0 raw_pc bit23 */
			{ 9377, 1,0}, /* core0 raw_pc bit24 */
			{ 9378, 1,0}, /* core0 raw_pc bit25 */
			{ 9379, 1,0}, /* core0 raw_pc bit26 */
			{ 9384, 1,0}, /* core0 raw_pc bit27 */
			{ 9385, 1,0}, /* core0 raw_pc bit28 */
			{ 9386, 1,0}, /* core0 raw_pc bit29 */
			{ 9387, 1,0}, /* core0 raw_pc bit30 */
			{14492, 1,0}, /* core0 raw_pc bit31 */
			{12620, 1,0}, /* core0 raw_pc bit32 */
			{12621, 1,0}, /* core0 raw_pc bit33 */
			{12622, 1,0}, /* core0 raw_pc bit34 */
			{12623, 1,0}, /* core0 raw_pc bit35 */
			{ 9408, 1,0}, /* core0 raw_pc bit36 */
			{ 9409, 1,0}, /* core0 raw_pc bit37 */
			{ 9410, 1,0}, /* core0 raw_pc bit38 */
			{ 9411, 1,0}, /* core0 raw_pc bit39 */
			{ 9396, 1,0}, /* core0 raw_pc bit40 */
			{ 9397, 1,0}, /* core0 raw_pc bit41 */
			{ 9398, 1,0}, /* core0 raw_pc bit42 */
			{ 9399, 1,0}, /* core0 raw_pc bit43 */
			{ 9392, 1,0}, /* core0 raw_pc bit44 */
			{ 9393, 1,0}, /* core0 raw_pc bit45 */
			{ 9394, 1,0}, /* core0 raw_pc bit46 */
			{ 9395, 1,0}, /* core0 raw_pc bit47 */
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
			{15238, 1,0}, /* core0 pc_iss bit0 */
			{15206, 1,0}, /* core0 pc_iss bit1 */
			{15235, 1,0}, /* core0 pc_iss bit2 */
			{15306, 1,0}, /* core0 pc_iss bit3 */
			{15203, 1,0}, /* core0 pc_iss bit4 */
			{15297, 1,0}, /* core0 pc_iss bit5 */
			{15207, 1,0}, /* core0 pc_iss bit6 */
			{15204, 1,0}, /* core0 pc_iss bit7 */
			{15208, 1,0}, /* core0 pc_iss bit8 */
			{15209, 1,0}, /* core0 pc_iss bit9 */
			{15211, 1,0}, /* core0 pc_iss bit10 */
			{15200, 1,0}, /* core0 pc_iss bit11 */
			{15215, 1,0}, /* core0 pc_iss bit12 */
			{15212, 1,0}, /* core0 pc_iss bit13 */
			{15188, 1,0}, /* core0 pc_iss bit14 */
			{15210, 1,0}, /* core0 pc_iss bit15 */
			{15217, 1,0}, /* core0 pc_iss bit16 */
			{15213, 1,0}, /* core0 pc_iss bit17 */
			{15214, 1,0}, /* core0 pc_iss bit18 */
			{15189, 1,0}, /* core0 pc_iss bit19 */
			{15187, 1,0}, /* core0 pc_iss bit20 */
			{15216, 1,0}, /* core0 pc_iss bit21 */
			{15196, 1,0}, /* core0 pc_iss bit22 */
			{15195, 1,0}, /* core0 pc_iss bit23 */
			{15186, 1,0}, /* core0 pc_iss bit24 */
			{15193, 1,0}, /* core0 pc_iss bit25 */
			{15194, 1,0}, /* core0 pc_iss bit26 */
			{15327, 1,0}, /* core0 pc_iss bit27 */
			{15333, 1,0}, /* core0 pc_iss bit28 */
			{15326, 1,0}, /* core0 pc_iss bit29 */
			{15191, 1,0}, /* core0 pc_iss bit30 */
			{15336, 1,0}, /* core0 pc_iss bit31 */
			{12440, 1,0}, /* core0 pc_iss bit32 */
			{12441, 1,0}, /* core0 pc_iss bit33 */
			{12442, 1,0}, /* core0 pc_iss bit34 */
			{12443, 1,0}, /* core0 pc_iss bit35 */
			{12436, 1,0}, /* core0 pc_iss bit36 */
			{12437, 1,0}, /* core0 pc_iss bit37 */
			{12438, 1,0}, /* core0 pc_iss bit38 */
			{12439, 1,0}, /* core0 pc_iss bit39 */
			{12516, 1,0}, /* core0 pc_iss bit40 */
			{12517, 1,0}, /* core0 pc_iss bit41 */
			{12518, 1,0}, /* core0 pc_iss bit42 */
			{12519, 1,0}, /* core0 pc_iss bit43 */
			{12512, 1,0}, /* core0 pc_iss bit44 */
			{12513, 1,0}, /* core0 pc_iss bit45 */
			{12514, 1,0}, /* core0 pc_iss bit46 */
			{12515, 1,0}, /* core0 pc_iss bit47 */
			{12636, 1,0}, /* core0 pc_iss bit48 */
			{12637, 1,0}, /* core0 pc_iss bit49 */
			{12638, 1,0}, /* core0 pc_iss bit50 */
			{12639, 1,0}, /* core0 pc_iss bit51 */
			{12632, 1,0}, /* core0 pc_iss bit52 */
			{12633, 1,0}, /* core0 pc_iss bit53 */
			{12634, 1,0}, /* core0 pc_iss bit54 */
			{12635, 1,0}, /* core0 pc_iss bit55 */
			{12640, 1,0}, /* core0 pc_iss bit56 */
			{12641, 1,0}, /* core0 pc_iss bit57 */
			{12642, 1,0}, /* core0 pc_iss bit58 */
			{12643, 1,0}, /* core0 pc_iss bit59 */
			{12644, 1,0}, /* core0 pc_iss bit60 */
			{12645, 1,0}, /* core0 pc_iss bit61 */
			{12646, 1,0}, /* core0 pc_iss bit62 */
			{12647, 1,0}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 8447, 2,0}, /* core0 full_pc_wr bit0 */
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
			{15304, 1,0}, /* core0 full_pc_ex1 bit0 */
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
			{ 8443, 2,0}, /* core0 full_pc_ex2 bit0 */
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
	},
	{		/* core 1 */ 
			.pc = {{
			{ 6231, 3,0}, /* core1 pc bit0 */
			{ 6232, 3,0}, /* core1 pc bit1 */
			{ 6233, 3,0}, /* core1 pc bit2 */
			{ 6234, 3,0}, /* core1 pc bit3 */
			{ 6296, 3,0}, /* core1 pc bit4 */
			{ 6297, 3,0}, /* core1 pc bit5 */
			{ 6298, 3,0}, /* core1 pc bit6 */
			{ 6299, 3,0}, /* core1 pc bit7 */
			{ 6340, 3,0}, /* core1 pc bit8 */
			{ 6341, 3,0}, /* core1 pc bit9 */
			{ 6342, 3,0}, /* core1 pc bit10 */
			{ 6343, 3,0}, /* core1 pc bit11 */
			{ 6480, 3,0}, /* core1 pc bit12 */
			{ 6481, 3,0}, /* core1 pc bit13 */
			{ 6482, 3,0}, /* core1 pc bit14 */
			{ 6483, 3,0}, /* core1 pc bit15 */
			{ 6692, 3,0}, /* core1 pc bit16 */
			{ 6693, 3,0}, /* core1 pc bit17 */
			{ 6694, 3,0}, /* core1 pc bit18 */
			{ 6695, 3,0}, /* core1 pc bit19 */
			{ 6352, 3,0}, /* core1 pc bit20 */
			{ 6353, 3,0}, /* core1 pc bit21 */
			{ 6354, 3,0}, /* core1 pc bit22 */
			{ 6355, 3,0}, /* core1 pc bit23 */
			{ 6696, 3,0}, /* core1 pc bit24 */
			{ 6697, 3,0}, /* core1 pc bit25 */
			{ 6698, 3,0}, /* core1 pc bit26 */
			{ 6699, 3,0}, /* core1 pc bit27 */
			{ 6328, 3,0}, /* core1 pc bit28 */
			{ 6329, 3,0}, /* core1 pc bit29 */
			{ 6330, 3,0}, /* core1 pc bit30 */
			{ 6331, 3,0}, /* core1 pc bit31 */
			{13288, 3,0}, /* core1 pc bit32 */
			{13289, 3,0}, /* core1 pc bit33 */
			{13290, 3,0}, /* core1 pc bit34 */
			{13291, 3,0}, /* core1 pc bit35 */
			{13280, 3,0}, /* core1 pc bit36 */
			{13281, 3,0}, /* core1 pc bit37 */
			{13282, 3,0}, /* core1 pc bit38 */
			{13283, 3,0}, /* core1 pc bit39 */
			{13268, 3,0}, /* core1 pc bit40 */
			{13269, 3,0}, /* core1 pc bit41 */
			{13270, 3,0}, /* core1 pc bit42 */
			{13271, 3,0}, /* core1 pc bit43 */
			{13284, 3,0}, /* core1 pc bit44 */
			{13285, 3,0}, /* core1 pc bit45 */
			{13286, 3,0}, /* core1 pc bit46 */
			{13287, 3,0}, /* core1 pc bit47 */
			{13264, 3,0}, /* core1 pc bit48 */
			{13265, 3,0}, /* core1 pc bit49 */
			{13266, 3,0}, /* core1 pc bit50 */
			{13267, 3,0}, /* core1 pc bit51 */
			{13272, 3,0}, /* core1 pc bit52 */
			{13273, 3,0}, /* core1 pc bit53 */
			{13274, 3,0}, /* core1 pc bit54 */
			{13275, 3,0}, /* core1 pc bit55 */
			{13292, 3,0}, /* core1 pc bit56 */
			{13293, 3,0}, /* core1 pc bit57 */
			{13294, 3,0}, /* core1 pc bit58 */
			{13295, 3,0}, /* core1 pc bit59 */
			{13276, 3,0}, /* core1 pc bit60 */
			{13277, 3,0}, /* core1 pc bit61 */
			{13278, 3,0}, /* core1 pc bit62 */
			{13279, 3,0}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{ 6012, 3,0}, /* core1 sp32 bit0 */
			{ 6013, 3,0}, /* core1 sp32 bit1 */
			{ 6014, 3,0}, /* core1 sp32 bit2 */
			{ 6015, 3,0}, /* core1 sp32 bit3 */
			{ 6188, 3,0}, /* core1 sp32 bit4 */
			{ 6189, 3,0}, /* core1 sp32 bit5 */
			{ 6190, 3,0}, /* core1 sp32 bit6 */
			{ 6191, 3,0}, /* core1 sp32 bit7 */
			{ 6992, 3,0}, /* core1 sp32 bit8 */
			{ 6993, 3,0}, /* core1 sp32 bit9 */
			{ 6994, 3,0}, /* core1 sp32 bit10 */
			{ 6995, 3,0}, /* core1 sp32 bit11 */
			{ 6872, 3,0}, /* core1 sp32 bit12 */
			{ 6873, 3,0}, /* core1 sp32 bit13 */
			{ 6874, 3,0}, /* core1 sp32 bit14 */
			{ 6875, 3,0}, /* core1 sp32 bit15 */
			{ 6884, 3,0}, /* core1 sp32 bit16 */
			{ 6885, 3,0}, /* core1 sp32 bit17 */
			{ 6886, 3,0}, /* core1 sp32 bit18 */
			{ 6887, 3,0}, /* core1 sp32 bit19 */
			{ 6944, 3,0}, /* core1 sp32 bit20 */
			{ 6945, 3,0}, /* core1 sp32 bit21 */
			{ 6946, 3,0}, /* core1 sp32 bit22 */
			{ 6947, 3,0}, /* core1 sp32 bit23 */
			{ 6880, 3,0}, /* core1 sp32 bit24 */
			{ 6881, 3,0}, /* core1 sp32 bit25 */
			{ 6882, 3,0}, /* core1 sp32 bit26 */
			{ 6883, 3,0}, /* core1 sp32 bit27 */
			{ 6980, 3,0}, /* core1 sp32 bit28 */
			{ 6981, 3,0}, /* core1 sp32 bit29 */
			{ 6982, 3,0}, /* core1 sp32 bit30 */
			{ 6983, 3,0}, /* core1 sp32 bit31 */
			{11004, 3,0}, /* core1 sp32 bit32 */
			{11005, 3,0}, /* core1 sp32 bit33 */
			{11006, 3,0}, /* core1 sp32 bit34 */
			{11007, 3,0}, /* core1 sp32 bit35 */
			{ 2324, 4,0}, /* core1 sp32 bit36 */
			{ 2325, 4,0}, /* core1 sp32 bit37 */
			{ 2326, 4,0}, /* core1 sp32 bit38 */
			{ 2327, 4,0}, /* core1 sp32 bit39 */
			{ 2316, 4,0}, /* core1 sp32 bit40 */
			{ 2317, 4,0}, /* core1 sp32 bit41 */
			{ 2318, 4,0}, /* core1 sp32 bit42 */
			{ 2319, 4,0}, /* core1 sp32 bit43 */
			{ 2312, 4,0}, /* core1 sp32 bit44 */
			{ 2313, 4,0}, /* core1 sp32 bit45 */
			{ 2314, 4,0}, /* core1 sp32 bit46 */
			{ 2315, 4,0}, /* core1 sp32 bit47 */
			{ 2308, 4,0}, /* core1 sp32 bit48 */
			{ 2309, 4,0}, /* core1 sp32 bit49 */
			{ 2310, 4,0}, /* core1 sp32 bit50 */
			{ 2311, 4,0}, /* core1 sp32 bit51 */
			{11072, 3,0}, /* core1 sp32 bit52 */
			{11073, 3,0}, /* core1 sp32 bit53 */
			{11074, 3,0}, /* core1 sp32 bit54 */
			{11075, 3,0}, /* core1 sp32 bit55 */
			{11036, 3,0}, /* core1 sp32 bit56 */
			{11037, 3,0}, /* core1 sp32 bit57 */
			{11038, 3,0}, /* core1 sp32 bit58 */
			{11039, 3,0}, /* core1 sp32 bit59 */
			{11024, 3,0}, /* core1 sp32 bit60 */
			{11025, 3,0}, /* core1 sp32 bit61 */
			{11026, 3,0}, /* core1 sp32 bit62 */
			{11027, 3,0}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7136, 3,0}, /* core1 fp32 bit0 */
			{ 7137, 3,0}, /* core1 fp32 bit1 */
			{ 7138, 3,0}, /* core1 fp32 bit2 */
			{ 7139, 3,0}, /* core1 fp32 bit3 */
			{ 7152, 3,0}, /* core1 fp32 bit4 */
			{ 7153, 3,0}, /* core1 fp32 bit5 */
			{ 7154, 3,0}, /* core1 fp32 bit6 */
			{ 7155, 3,0}, /* core1 fp32 bit7 */
			{   32, 3,0}, /* core1 fp32 bit8 */
			{   33, 3,0}, /* core1 fp32 bit9 */
			{   34, 3,0}, /* core1 fp32 bit10 */
			{   35, 3,0}, /* core1 fp32 bit11 */
			{ 8444, 3,0}, /* core1 fp32 bit12 */
			{ 8445, 3,0}, /* core1 fp32 bit13 */
			{ 8446, 3,0}, /* core1 fp32 bit14 */
			{ 8447, 3,0}, /* core1 fp32 bit15 */
			{ 8440, 3,0}, /* core1 fp32 bit16 */
			{ 8441, 3,0}, /* core1 fp32 bit17 */
			{ 8442, 3,0}, /* core1 fp32 bit18 */
			{ 8443, 3,0}, /* core1 fp32 bit19 */
			{ 7080, 3,0}, /* core1 fp32 bit20 */
			{ 7081, 3,0}, /* core1 fp32 bit21 */
			{ 7082, 3,0}, /* core1 fp32 bit22 */
			{ 7083, 3,0}, /* core1 fp32 bit23 */
			{ 8424, 3,0}, /* core1 fp32 bit24 */
			{ 8425, 3,0}, /* core1 fp32 bit25 */
			{ 8426, 3,0}, /* core1 fp32 bit26 */
			{ 8427, 3,0}, /* core1 fp32 bit27 */
			{ 8216, 3,0}, /* core1 fp32 bit28 */
			{ 8217, 3,0}, /* core1 fp32 bit29 */
			{ 8218, 3,0}, /* core1 fp32 bit30 */
			{ 8219, 3,0}, /* core1 fp32 bit31 */
			{ 7516, 3,0}, /* core1 fp32 bit32 */
			{ 7517, 3,0}, /* core1 fp32 bit33 */
			{ 7518, 3,0}, /* core1 fp32 bit34 */
			{ 7519, 3,0}, /* core1 fp32 bit35 */
			{ 7592, 3,0}, /* core1 fp32 bit36 */
			{ 7593, 3,0}, /* core1 fp32 bit37 */
			{ 7594, 3,0}, /* core1 fp32 bit38 */
			{ 7595, 3,0}, /* core1 fp32 bit39 */
			{ 7484, 3,0}, /* core1 fp32 bit40 */
			{ 7485, 3,0}, /* core1 fp32 bit41 */
			{ 7486, 3,0}, /* core1 fp32 bit42 */
			{ 7487, 3,0}, /* core1 fp32 bit43 */
			{ 7476, 3,0}, /* core1 fp32 bit44 */
			{ 7477, 3,0}, /* core1 fp32 bit45 */
			{ 7478, 3,0}, /* core1 fp32 bit46 */
			{ 7479, 3,0}, /* core1 fp32 bit47 */
			{ 7480, 3,0}, /* core1 fp32 bit48 */
			{ 7481, 3,0}, /* core1 fp32 bit49 */
			{ 7482, 3,0}, /* core1 fp32 bit50 */
			{ 7483, 3,0}, /* core1 fp32 bit51 */
			{ 8128, 3,0}, /* core1 fp32 bit52 */
			{ 8129, 3,0}, /* core1 fp32 bit53 */
			{ 8130, 3,0}, /* core1 fp32 bit54 */
			{ 8131, 3,0}, /* core1 fp32 bit55 */
			{ 8132, 3,0}, /* core1 fp32 bit56 */
			{ 8133, 3,0}, /* core1 fp32 bit57 */
			{ 8134, 3,0}, /* core1 fp32 bit58 */
			{ 8135, 3,0}, /* core1 fp32 bit59 */
			{ 7616, 3,0}, /* core1 fp32 bit60 */
			{ 7617, 3,0}, /* core1 fp32 bit61 */
			{ 7618, 3,0}, /* core1 fp32 bit62 */
			{ 7619, 3,0}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{ 6211, 3,0}, /* core1 fp64 bit0 */
			{ 6212, 3,0}, /* core1 fp64 bit1 */
			{ 6213, 3,0}, /* core1 fp64 bit2 */
			{ 6214, 3,0}, /* core1 fp64 bit3 */
			{ 6276, 3,0}, /* core1 fp64 bit4 */
			{ 6277, 3,0}, /* core1 fp64 bit5 */
			{ 6278, 3,0}, /* core1 fp64 bit6 */
			{ 6279, 3,0}, /* core1 fp64 bit7 */
			{ 6376, 3,0}, /* core1 fp64 bit8 */
			{ 6377, 3,0}, /* core1 fp64 bit9 */
			{ 6378, 3,0}, /* core1 fp64 bit10 */
			{ 6379, 3,0}, /* core1 fp64 bit11 */
			{ 6476, 3,0}, /* core1 fp64 bit12 */
			{ 6477, 3,0}, /* core1 fp64 bit13 */
			{ 6478, 3,0}, /* core1 fp64 bit14 */
			{ 6479, 3,0}, /* core1 fp64 bit15 */
			{ 6684, 3,0}, /* core1 fp64 bit16 */
			{ 6685, 3,0}, /* core1 fp64 bit17 */
			{ 6686, 3,0}, /* core1 fp64 bit18 */
			{ 6687, 3,0}, /* core1 fp64 bit19 */
			{ 6356, 3,0}, /* core1 fp64 bit20 */
			{ 6357, 3,0}, /* core1 fp64 bit21 */
			{ 6358, 3,0}, /* core1 fp64 bit22 */
			{ 6359, 3,0}, /* core1 fp64 bit23 */
			{ 6688, 3,0}, /* core1 fp64 bit24 */
			{ 6689, 3,0}, /* core1 fp64 bit25 */
			{ 6690, 3,0}, /* core1 fp64 bit26 */
			{ 6691, 3,0}, /* core1 fp64 bit27 */
			{ 6392, 3,0}, /* core1 fp64 bit28 */
			{ 6393, 3,0}, /* core1 fp64 bit29 */
			{ 6394, 3,0}, /* core1 fp64 bit30 */
			{ 6395, 3,0}, /* core1 fp64 bit31 */
			{ 7908, 3,0}, /* core1 fp64 bit32 */
			{ 7909, 3,0}, /* core1 fp64 bit33 */
			{ 7910, 3,0}, /* core1 fp64 bit34 */
			{ 7911, 3,0}, /* core1 fp64 bit35 */
			{ 8260, 3,0}, /* core1 fp64 bit36 */
			{ 8261, 3,0}, /* core1 fp64 bit37 */
			{ 8262, 3,0}, /* core1 fp64 bit38 */
			{ 8263, 3,0}, /* core1 fp64 bit39 */
			{ 8272, 3,0}, /* core1 fp64 bit40 */
			{ 8273, 3,0}, /* core1 fp64 bit41 */
			{ 8274, 3,0}, /* core1 fp64 bit42 */
			{ 8275, 3,0}, /* core1 fp64 bit43 */
			{ 8276, 3,0}, /* core1 fp64 bit44 */
			{ 8277, 3,0}, /* core1 fp64 bit45 */
			{ 8278, 3,0}, /* core1 fp64 bit46 */
			{ 8279, 3,0}, /* core1 fp64 bit47 */
			{ 8312, 3,0}, /* core1 fp64 bit48 */
			{ 8313, 3,0}, /* core1 fp64 bit49 */
			{ 8314, 3,0}, /* core1 fp64 bit50 */
			{ 8315, 3,0}, /* core1 fp64 bit51 */
			{ 8320, 3,0}, /* core1 fp64 bit52 */
			{ 8321, 3,0}, /* core1 fp64 bit53 */
			{ 8322, 3,0}, /* core1 fp64 bit54 */
			{ 8323, 3,0}, /* core1 fp64 bit55 */
			{ 7900, 3,0}, /* core1 fp64 bit56 */
			{ 7901, 3,0}, /* core1 fp64 bit57 */
			{ 7902, 3,0}, /* core1 fp64 bit58 */
			{ 7903, 3,0}, /* core1 fp64 bit59 */
			{ 7968, 3,0}, /* core1 fp64 bit60 */
			{ 7969, 3,0}, /* core1 fp64 bit61 */
			{ 7970, 3,0}, /* core1 fp64 bit62 */
			{ 7971, 3,0}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 6132, 3,0}, /* core1 sp_EL0 bit0 */
			{ 6133, 3,0}, /* core1 sp_EL0 bit1 */
			{ 6134, 3,0}, /* core1 sp_EL0 bit2 */
			{ 6135, 3,0}, /* core1 sp_EL0 bit3 */
			{ 6260, 3,0}, /* core1 sp_EL0 bit4 */
			{ 6261, 3,0}, /* core1 sp_EL0 bit5 */
			{ 6262, 3,0}, /* core1 sp_EL0 bit6 */
			{ 6263, 3,0}, /* core1 sp_EL0 bit7 */
			{ 6236, 3,0}, /* core1 sp_EL0 bit8 */
			{ 6237, 3,0}, /* core1 sp_EL0 bit9 */
			{ 6238, 3,0}, /* core1 sp_EL0 bit10 */
			{ 6239, 3,0}, /* core1 sp_EL0 bit11 */
			{ 6452, 3,0}, /* core1 sp_EL0 bit12 */
			{ 6453, 3,0}, /* core1 sp_EL0 bit13 */
			{ 6454, 3,0}, /* core1 sp_EL0 bit14 */
			{ 6455, 3,0}, /* core1 sp_EL0 bit15 */
			{ 6740, 3,0}, /* core1 sp_EL0 bit16 */
			{ 6741, 3,0}, /* core1 sp_EL0 bit17 */
			{ 6742, 3,0}, /* core1 sp_EL0 bit18 */
			{ 6743, 3,0}, /* core1 sp_EL0 bit19 */
			{ 6432, 3,0}, /* core1 sp_EL0 bit20 */
			{ 6433, 3,0}, /* core1 sp_EL0 bit21 */
			{ 6434, 3,0}, /* core1 sp_EL0 bit22 */
			{ 6435, 3,0}, /* core1 sp_EL0 bit23 */
			{ 6736, 3,0}, /* core1 sp_EL0 bit24 */
			{ 6737, 3,0}, /* core1 sp_EL0 bit25 */
			{ 6738, 3,0}, /* core1 sp_EL0 bit26 */
			{ 6739, 3,0}, /* core1 sp_EL0 bit27 */
			{ 6408, 3,0}, /* core1 sp_EL0 bit28 */
			{ 6409, 3,0}, /* core1 sp_EL0 bit29 */
			{ 6410, 3,0}, /* core1 sp_EL0 bit30 */
			{ 6411, 3,0}, /* core1 sp_EL0 bit31 */
			{ 7916, 3,0}, /* core1 sp_EL0 bit32 */
			{ 7917, 3,0}, /* core1 sp_EL0 bit33 */
			{ 7918, 3,0}, /* core1 sp_EL0 bit34 */
			{ 7919, 3,0}, /* core1 sp_EL0 bit35 */
			{  153, 3,0}, /* core1 sp_EL0 bit36 */
			{  154, 3,0}, /* core1 sp_EL0 bit37 */
			{  155, 3,0}, /* core1 sp_EL0 bit38 */
			{  156, 3,0}, /* core1 sp_EL0 bit39 */
			{  161, 3,0}, /* core1 sp_EL0 bit40 */
			{  162, 3,0}, /* core1 sp_EL0 bit41 */
			{  163, 3,0}, /* core1 sp_EL0 bit42 */
			{  164, 3,0}, /* core1 sp_EL0 bit43 */
			{  165, 3,0}, /* core1 sp_EL0 bit44 */
			{  166, 3,0}, /* core1 sp_EL0 bit45 */
			{  167, 3,0}, /* core1 sp_EL0 bit46 */
			{  168, 3,0}, /* core1 sp_EL0 bit47 */
			{ 7440, 3,0}, /* core1 sp_EL0 bit48 */
			{ 7441, 3,0}, /* core1 sp_EL0 bit49 */
			{ 7442, 3,0}, /* core1 sp_EL0 bit50 */
			{ 7443, 3,0}, /* core1 sp_EL0 bit51 */
			{ 7468, 3,0}, /* core1 sp_EL0 bit52 */
			{ 7469, 3,0}, /* core1 sp_EL0 bit53 */
			{ 7470, 3,0}, /* core1 sp_EL0 bit54 */
			{ 7471, 3,0}, /* core1 sp_EL0 bit55 */
			{ 7892, 3,0}, /* core1 sp_EL0 bit56 */
			{ 7893, 3,0}, /* core1 sp_EL0 bit57 */
			{ 7894, 3,0}, /* core1 sp_EL0 bit58 */
			{ 7895, 3,0}, /* core1 sp_EL0 bit59 */
			{ 7948, 3,0}, /* core1 sp_EL0 bit60 */
			{ 7949, 3,0}, /* core1 sp_EL0 bit61 */
			{ 7950, 3,0}, /* core1 sp_EL0 bit62 */
			{ 7951, 3,0}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6215, 3,0}, /* core1 sp_EL1 bit0 */
			{ 6216, 3,0}, /* core1 sp_EL1 bit1 */
			{ 6217, 3,0}, /* core1 sp_EL1 bit2 */
			{ 6218, 3,0}, /* core1 sp_EL1 bit3 */
			{ 6272, 3,0}, /* core1 sp_EL1 bit4 */
			{ 6273, 3,0}, /* core1 sp_EL1 bit5 */
			{ 6274, 3,0}, /* core1 sp_EL1 bit6 */
			{ 6275, 3,0}, /* core1 sp_EL1 bit7 */
			{ 6380, 3,0}, /* core1 sp_EL1 bit8 */
			{ 6381, 3,0}, /* core1 sp_EL1 bit9 */
			{ 6382, 3,0}, /* core1 sp_EL1 bit10 */
			{ 6383, 3,0}, /* core1 sp_EL1 bit11 */
			{ 6472, 3,0}, /* core1 sp_EL1 bit12 */
			{ 6473, 3,0}, /* core1 sp_EL1 bit13 */
			{ 6474, 3,0}, /* core1 sp_EL1 bit14 */
			{ 6475, 3,0}, /* core1 sp_EL1 bit15 */
			{ 6648, 3,0}, /* core1 sp_EL1 bit16 */
			{ 6649, 3,0}, /* core1 sp_EL1 bit17 */
			{ 6650, 3,0}, /* core1 sp_EL1 bit18 */
			{ 6651, 3,0}, /* core1 sp_EL1 bit19 */
			{ 6976, 3,0}, /* core1 sp_EL1 bit20 */
			{ 6977, 3,0}, /* core1 sp_EL1 bit21 */
			{ 6978, 3,0}, /* core1 sp_EL1 bit22 */
			{ 6979, 3,0}, /* core1 sp_EL1 bit23 */
			{ 6652, 3,0}, /* core1 sp_EL1 bit24 */
			{ 6653, 3,0}, /* core1 sp_EL1 bit25 */
			{ 6654, 3,0}, /* core1 sp_EL1 bit26 */
			{ 6655, 3,0}, /* core1 sp_EL1 bit27 */
			{ 6388, 3,0}, /* core1 sp_EL1 bit28 */
			{ 6389, 3,0}, /* core1 sp_EL1 bit29 */
			{ 6390, 3,0}, /* core1 sp_EL1 bit30 */
			{ 6391, 3,0}, /* core1 sp_EL1 bit31 */
			{ 7904, 3,0}, /* core1 sp_EL1 bit32 */
			{ 7905, 3,0}, /* core1 sp_EL1 bit33 */
			{ 7906, 3,0}, /* core1 sp_EL1 bit34 */
			{ 7907, 3,0}, /* core1 sp_EL1 bit35 */
			{ 8304, 3,0}, /* core1 sp_EL1 bit36 */
			{ 8305, 3,0}, /* core1 sp_EL1 bit37 */
			{ 8306, 3,0}, /* core1 sp_EL1 bit38 */
			{ 8307, 3,0}, /* core1 sp_EL1 bit39 */
			{ 8296, 3,0}, /* core1 sp_EL1 bit40 */
			{ 8297, 3,0}, /* core1 sp_EL1 bit41 */
			{ 8298, 3,0}, /* core1 sp_EL1 bit42 */
			{ 8299, 3,0}, /* core1 sp_EL1 bit43 */
			{ 8292, 3,0}, /* core1 sp_EL1 bit44 */
			{ 8293, 3,0}, /* core1 sp_EL1 bit45 */
			{ 8294, 3,0}, /* core1 sp_EL1 bit46 */
			{ 8295, 3,0}, /* core1 sp_EL1 bit47 */
			{ 8308, 3,0}, /* core1 sp_EL1 bit48 */
			{ 8309, 3,0}, /* core1 sp_EL1 bit49 */
			{ 8310, 3,0}, /* core1 sp_EL1 bit50 */
			{ 8311, 3,0}, /* core1 sp_EL1 bit51 */
			{ 8328, 3,0}, /* core1 sp_EL1 bit52 */
			{ 8329, 3,0}, /* core1 sp_EL1 bit53 */
			{ 8330, 3,0}, /* core1 sp_EL1 bit54 */
			{ 8331, 3,0}, /* core1 sp_EL1 bit55 */
			{ 8336, 3,0}, /* core1 sp_EL1 bit56 */
			{ 8337, 3,0}, /* core1 sp_EL1 bit57 */
			{ 8338, 3,0}, /* core1 sp_EL1 bit58 */
			{ 8339, 3,0}, /* core1 sp_EL1 bit59 */
			{ 7964, 3,0}, /* core1 sp_EL1 bit60 */
			{ 7965, 3,0}, /* core1 sp_EL1 bit61 */
			{ 7966, 3,0}, /* core1 sp_EL1 bit62 */
			{ 7967, 3,0}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 6120, 3,0}, /* core1 sp_EL2 bit0 */
			{ 6121, 3,0}, /* core1 sp_EL2 bit1 */
			{ 6122, 3,0}, /* core1 sp_EL2 bit2 */
			{ 6123, 3,0}, /* core1 sp_EL2 bit3 */
			{ 6148, 3,0}, /* core1 sp_EL2 bit4 */
			{ 6149, 3,0}, /* core1 sp_EL2 bit5 */
			{ 6150, 3,0}, /* core1 sp_EL2 bit6 */
			{ 6151, 3,0}, /* core1 sp_EL2 bit7 */
			{ 6960, 3,0}, /* core1 sp_EL2 bit8 */
			{ 6961, 3,0}, /* core1 sp_EL2 bit9 */
			{ 6962, 3,0}, /* core1 sp_EL2 bit10 */
			{ 6963, 3,0}, /* core1 sp_EL2 bit11 */
			{ 6444, 3,0}, /* core1 sp_EL2 bit12 */
			{ 6445, 3,0}, /* core1 sp_EL2 bit13 */
			{ 6446, 3,0}, /* core1 sp_EL2 bit14 */
			{ 6447, 3,0}, /* core1 sp_EL2 bit15 */
			{ 6912, 3,0}, /* core1 sp_EL2 bit16 */
			{ 6913, 3,0}, /* core1 sp_EL2 bit17 */
			{ 6914, 3,0}, /* core1 sp_EL2 bit18 */
			{ 6915, 3,0}, /* core1 sp_EL2 bit19 */
			{ 6956, 3,0}, /* core1 sp_EL2 bit20 */
			{ 6957, 3,0}, /* core1 sp_EL2 bit21 */
			{ 6958, 3,0}, /* core1 sp_EL2 bit22 */
			{ 6959, 3,0}, /* core1 sp_EL2 bit23 */
			{ 6908, 3,0}, /* core1 sp_EL2 bit24 */
			{ 6909, 3,0}, /* core1 sp_EL2 bit25 */
			{ 6910, 3,0}, /* core1 sp_EL2 bit26 */
			{ 6911, 3,0}, /* core1 sp_EL2 bit27 */
			{ 6168, 3,0}, /* core1 sp_EL2 bit28 */
			{ 6169, 3,0}, /* core1 sp_EL2 bit29 */
			{ 6170, 3,0}, /* core1 sp_EL2 bit30 */
			{ 6171, 3,0}, /* core1 sp_EL2 bit31 */
			{ 7960, 3,0}, /* core1 sp_EL2 bit32 */
			{ 7961, 3,0}, /* core1 sp_EL2 bit33 */
			{ 7962, 3,0}, /* core1 sp_EL2 bit34 */
			{ 7963, 3,0}, /* core1 sp_EL2 bit35 */
			{  141, 3,0}, /* core1 sp_EL2 bit36 */
			{  142, 3,0}, /* core1 sp_EL2 bit37 */
			{  143, 3,0}, /* core1 sp_EL2 bit38 */
			{  144, 3,0}, /* core1 sp_EL2 bit39 */
			{  149, 3,0}, /* core1 sp_EL2 bit40 */
			{  150, 3,0}, /* core1 sp_EL2 bit41 */
			{  151, 3,0}, /* core1 sp_EL2 bit42 */
			{  152, 3,0}, /* core1 sp_EL2 bit43 */
			{  145, 3,0}, /* core1 sp_EL2 bit44 */
			{  146, 3,0}, /* core1 sp_EL2 bit45 */
			{  147, 3,0}, /* core1 sp_EL2 bit46 */
			{  148, 3,0}, /* core1 sp_EL2 bit47 */
			{ 7880, 3,0}, /* core1 sp_EL2 bit48 */
			{ 7881, 3,0}, /* core1 sp_EL2 bit49 */
			{ 7882, 3,0}, /* core1 sp_EL2 bit50 */
			{ 7883, 3,0}, /* core1 sp_EL2 bit51 */
			{ 8332, 3,0}, /* core1 sp_EL2 bit52 */
			{ 8333, 3,0}, /* core1 sp_EL2 bit53 */
			{ 8334, 3,0}, /* core1 sp_EL2 bit54 */
			{ 8335, 3,0}, /* core1 sp_EL2 bit55 */
			{ 7896, 3,0}, /* core1 sp_EL2 bit56 */
			{ 7897, 3,0}, /* core1 sp_EL2 bit57 */
			{ 7898, 3,0}, /* core1 sp_EL2 bit58 */
			{ 7899, 3,0}, /* core1 sp_EL2 bit59 */
			{ 7956, 3,0}, /* core1 sp_EL2 bit60 */
			{ 7957, 3,0}, /* core1 sp_EL2 bit61 */
			{ 7958, 3,0}, /* core1 sp_EL2 bit62 */
			{ 7959, 3,0}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6004, 3,0}, /* core1 sp_EL3 bit0 */
			{ 6005, 3,0}, /* core1 sp_EL3 bit1 */
			{ 6006, 3,0}, /* core1 sp_EL3 bit2 */
			{ 6007, 3,0}, /* core1 sp_EL3 bit3 */
			{ 6000, 3,0}, /* core1 sp_EL3 bit4 */
			{ 6001, 3,0}, /* core1 sp_EL3 bit5 */
			{ 6002, 3,0}, /* core1 sp_EL3 bit6 */
			{ 6003, 3,0}, /* core1 sp_EL3 bit7 */
			{ 6984, 3,0}, /* core1 sp_EL3 bit8 */
			{ 6985, 3,0}, /* core1 sp_EL3 bit9 */
			{ 6986, 3,0}, /* core1 sp_EL3 bit10 */
			{ 6987, 3,0}, /* core1 sp_EL3 bit11 */
			{ 7040, 3,0}, /* core1 sp_EL3 bit12 */
			{ 7041, 3,0}, /* core1 sp_EL3 bit13 */
			{ 7042, 3,0}, /* core1 sp_EL3 bit14 */
			{ 7043, 3,0}, /* core1 sp_EL3 bit15 */
			{ 6888, 3,0}, /* core1 sp_EL3 bit16 */
			{ 6889, 3,0}, /* core1 sp_EL3 bit17 */
			{ 6890, 3,0}, /* core1 sp_EL3 bit18 */
			{ 6891, 3,0}, /* core1 sp_EL3 bit19 */
			{ 7024, 3,0}, /* core1 sp_EL3 bit20 */
			{ 7025, 3,0}, /* core1 sp_EL3 bit21 */
			{ 7026, 3,0}, /* core1 sp_EL3 bit22 */
			{ 7027, 3,0}, /* core1 sp_EL3 bit23 */
			{ 6852, 3,0}, /* core1 sp_EL3 bit24 */
			{ 6853, 3,0}, /* core1 sp_EL3 bit25 */
			{ 6854, 3,0}, /* core1 sp_EL3 bit26 */
			{ 6855, 3,0}, /* core1 sp_EL3 bit27 */
			{ 7220, 3,0}, /* core1 sp_EL3 bit28 */
			{ 7221, 3,0}, /* core1 sp_EL3 bit29 */
			{ 7222, 3,0}, /* core1 sp_EL3 bit30 */
			{ 7223, 3,0}, /* core1 sp_EL3 bit31 */
			{ 8344, 3,0}, /* core1 sp_EL3 bit32 */
			{ 8345, 3,0}, /* core1 sp_EL3 bit33 */
			{ 8346, 3,0}, /* core1 sp_EL3 bit34 */
			{ 8347, 3,0}, /* core1 sp_EL3 bit35 */
			{ 7448, 3,0}, /* core1 sp_EL3 bit36 */
			{ 7449, 3,0}, /* core1 sp_EL3 bit37 */
			{ 7450, 3,0}, /* core1 sp_EL3 bit38 */
			{ 7451, 3,0}, /* core1 sp_EL3 bit39 */
			{ 7872, 3,0}, /* core1 sp_EL3 bit40 */
			{ 7873, 3,0}, /* core1 sp_EL3 bit41 */
			{ 7874, 3,0}, /* core1 sp_EL3 bit42 */
			{ 7875, 3,0}, /* core1 sp_EL3 bit43 */
			{ 7444, 3,0}, /* core1 sp_EL3 bit44 */
			{ 7445, 3,0}, /* core1 sp_EL3 bit45 */
			{ 7446, 3,0}, /* core1 sp_EL3 bit46 */
			{ 7447, 3,0}, /* core1 sp_EL3 bit47 */
			{ 8316, 3,0}, /* core1 sp_EL3 bit48 */
			{ 8317, 3,0}, /* core1 sp_EL3 bit49 */
			{ 8318, 3,0}, /* core1 sp_EL3 bit50 */
			{ 8319, 3,0}, /* core1 sp_EL3 bit51 */
			{ 8248, 3,0}, /* core1 sp_EL3 bit52 */
			{ 8249, 3,0}, /* core1 sp_EL3 bit53 */
			{ 8250, 3,0}, /* core1 sp_EL3 bit54 */
			{ 8251, 3,0}, /* core1 sp_EL3 bit55 */
			{ 7884, 3,0}, /* core1 sp_EL3 bit56 */
			{ 7885, 3,0}, /* core1 sp_EL3 bit57 */
			{ 7886, 3,0}, /* core1 sp_EL3 bit58 */
			{ 7887, 3,0}, /* core1 sp_EL3 bit59 */
			{ 7944, 3,0}, /* core1 sp_EL3 bit60 */
			{ 7945, 3,0}, /* core1 sp_EL3 bit61 */
			{ 7946, 3,0}, /* core1 sp_EL3 bit62 */
			{ 7947, 3,0}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{ 5988, 3,0}, /* core1 elr_EL1 bit0 */
			{ 5989, 3,0}, /* core1 elr_EL1 bit1 */
			{ 5990, 3,0}, /* core1 elr_EL1 bit2 */
			{ 5991, 3,0}, /* core1 elr_EL1 bit3 */
			{ 5996, 3,0}, /* core1 elr_EL1 bit4 */
			{ 5997, 3,0}, /* core1 elr_EL1 bit5 */
			{ 5998, 3,0}, /* core1 elr_EL1 bit6 */
			{ 5999, 3,0}, /* core1 elr_EL1 bit7 */
			{ 6988, 3,0}, /* core1 elr_EL1 bit8 */
			{ 6989, 3,0}, /* core1 elr_EL1 bit9 */
			{ 6990, 3,0}, /* core1 elr_EL1 bit10 */
			{ 6991, 3,0}, /* core1 elr_EL1 bit11 */
			{ 7048, 3,0}, /* core1 elr_EL1 bit12 */
			{ 7049, 3,0}, /* core1 elr_EL1 bit13 */
			{ 7050, 3,0}, /* core1 elr_EL1 bit14 */
			{ 7051, 3,0}, /* core1 elr_EL1 bit15 */
			{ 6896, 3,0}, /* core1 elr_EL1 bit16 */
			{ 6897, 3,0}, /* core1 elr_EL1 bit17 */
			{ 6898, 3,0}, /* core1 elr_EL1 bit18 */
			{ 6899, 3,0}, /* core1 elr_EL1 bit19 */
			{ 6940, 3,0}, /* core1 elr_EL1 bit20 */
			{ 6941, 3,0}, /* core1 elr_EL1 bit21 */
			{ 6942, 3,0}, /* core1 elr_EL1 bit22 */
			{ 6943, 3,0}, /* core1 elr_EL1 bit23 */
			{ 6856, 3,0}, /* core1 elr_EL1 bit24 */
			{ 6857, 3,0}, /* core1 elr_EL1 bit25 */
			{ 6858, 3,0}, /* core1 elr_EL1 bit26 */
			{ 6859, 3,0}, /* core1 elr_EL1 bit27 */
			{ 7216, 3,0}, /* core1 elr_EL1 bit28 */
			{ 7217, 3,0}, /* core1 elr_EL1 bit29 */
			{ 7218, 3,0}, /* core1 elr_EL1 bit30 */
			{ 7219, 3,0}, /* core1 elr_EL1 bit31 */
			{ 8164, 3,0}, /* core1 elr_EL1 bit32 */
			{ 8165, 3,0}, /* core1 elr_EL1 bit33 */
			{ 8166, 3,0}, /* core1 elr_EL1 bit34 */
			{ 8167, 3,0}, /* core1 elr_EL1 bit35 */
			{ 7288, 3,0}, /* core1 elr_EL1 bit36 */
			{ 7289, 3,0}, /* core1 elr_EL1 bit37 */
			{ 7290, 3,0}, /* core1 elr_EL1 bit38 */
			{ 7291, 3,0}, /* core1 elr_EL1 bit39 */
			{ 7428, 3,0}, /* core1 elr_EL1 bit40 */
			{ 7429, 3,0}, /* core1 elr_EL1 bit41 */
			{ 7430, 3,0}, /* core1 elr_EL1 bit42 */
			{ 7431, 3,0}, /* core1 elr_EL1 bit43 */
			{ 7284, 3,0}, /* core1 elr_EL1 bit44 */
			{ 7285, 3,0}, /* core1 elr_EL1 bit45 */
			{ 7286, 3,0}, /* core1 elr_EL1 bit46 */
			{ 7287, 3,0}, /* core1 elr_EL1 bit47 */
			{ 7420, 3,0}, /* core1 elr_EL1 bit48 */
			{ 7421, 3,0}, /* core1 elr_EL1 bit49 */
			{ 7422, 3,0}, /* core1 elr_EL1 bit50 */
			{ 7423, 3,0}, /* core1 elr_EL1 bit51 */
			{ 7860, 3,0}, /* core1 elr_EL1 bit52 */
			{ 7861, 3,0}, /* core1 elr_EL1 bit53 */
			{ 7862, 3,0}, /* core1 elr_EL1 bit54 */
			{ 7863, 3,0}, /* core1 elr_EL1 bit55 */
			{ 7932, 3,0}, /* core1 elr_EL1 bit56 */
			{ 7933, 3,0}, /* core1 elr_EL1 bit57 */
			{ 7934, 3,0}, /* core1 elr_EL1 bit58 */
			{ 7935, 3,0}, /* core1 elr_EL1 bit59 */
			{ 8168, 3,0}, /* core1 elr_EL1 bit60 */
			{ 8169, 3,0}, /* core1 elr_EL1 bit61 */
			{ 8170, 3,0}, /* core1 elr_EL1 bit62 */
			{ 8171, 3,0}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 5992, 3,0}, /* core1 elr_EL2 bit0 */
			{ 5993, 3,0}, /* core1 elr_EL2 bit1 */
			{ 5994, 3,0}, /* core1 elr_EL2 bit2 */
			{ 5995, 3,0}, /* core1 elr_EL2 bit3 */
			{ 6152, 3,0}, /* core1 elr_EL2 bit4 */
			{ 6153, 3,0}, /* core1 elr_EL2 bit5 */
			{ 6154, 3,0}, /* core1 elr_EL2 bit6 */
			{ 6155, 3,0}, /* core1 elr_EL2 bit7 */
			{ 6416, 3,0}, /* core1 elr_EL2 bit8 */
			{ 6417, 3,0}, /* core1 elr_EL2 bit9 */
			{ 6418, 3,0}, /* core1 elr_EL2 bit10 */
			{ 6419, 3,0}, /* core1 elr_EL2 bit11 */
			{ 6924, 3,0}, /* core1 elr_EL2 bit12 */
			{ 6925, 3,0}, /* core1 elr_EL2 bit13 */
			{ 6926, 3,0}, /* core1 elr_EL2 bit14 */
			{ 6927, 3,0}, /* core1 elr_EL2 bit15 */
			{ 6916, 3,0}, /* core1 elr_EL2 bit16 */
			{ 6917, 3,0}, /* core1 elr_EL2 bit17 */
			{ 6918, 3,0}, /* core1 elr_EL2 bit18 */
			{ 6919, 3,0}, /* core1 elr_EL2 bit19 */
			{ 6952, 3,0}, /* core1 elr_EL2 bit20 */
			{ 6953, 3,0}, /* core1 elr_EL2 bit21 */
			{ 6954, 3,0}, /* core1 elr_EL2 bit22 */
			{ 6955, 3,0}, /* core1 elr_EL2 bit23 */
			{ 6904, 3,0}, /* core1 elr_EL2 bit24 */
			{ 6905, 3,0}, /* core1 elr_EL2 bit25 */
			{ 6906, 3,0}, /* core1 elr_EL2 bit26 */
			{ 6907, 3,0}, /* core1 elr_EL2 bit27 */
			{ 7224, 3,0}, /* core1 elr_EL2 bit28 */
			{ 7225, 3,0}, /* core1 elr_EL2 bit29 */
			{ 7226, 3,0}, /* core1 elr_EL2 bit30 */
			{ 7227, 3,0}, /* core1 elr_EL2 bit31 */
			{ 7912, 3,0}, /* core1 elr_EL2 bit32 */
			{ 7913, 3,0}, /* core1 elr_EL2 bit33 */
			{ 7914, 3,0}, /* core1 elr_EL2 bit34 */
			{ 7915, 3,0}, /* core1 elr_EL2 bit35 */
			{ 8300, 3,0}, /* core1 elr_EL2 bit36 */
			{ 8301, 3,0}, /* core1 elr_EL2 bit37 */
			{ 8302, 3,0}, /* core1 elr_EL2 bit38 */
			{ 8303, 3,0}, /* core1 elr_EL2 bit39 */
			{ 8264, 3,0}, /* core1 elr_EL2 bit40 */
			{ 8265, 3,0}, /* core1 elr_EL2 bit41 */
			{ 8266, 3,0}, /* core1 elr_EL2 bit42 */
			{ 8267, 3,0}, /* core1 elr_EL2 bit43 */
			{ 8268, 3,0}, /* core1 elr_EL2 bit44 */
			{ 8269, 3,0}, /* core1 elr_EL2 bit45 */
			{ 8270, 3,0}, /* core1 elr_EL2 bit46 */
			{ 8271, 3,0}, /* core1 elr_EL2 bit47 */
			{ 7456, 3,0}, /* core1 elr_EL2 bit48 */
			{ 7457, 3,0}, /* core1 elr_EL2 bit49 */
			{ 7458, 3,0}, /* core1 elr_EL2 bit50 */
			{ 7459, 3,0}, /* core1 elr_EL2 bit51 */
			{ 7464, 3,0}, /* core1 elr_EL2 bit52 */
			{ 7465, 3,0}, /* core1 elr_EL2 bit53 */
			{ 7466, 3,0}, /* core1 elr_EL2 bit54 */
			{ 7467, 3,0}, /* core1 elr_EL2 bit55 */
			{ 7888, 3,0}, /* core1 elr_EL2 bit56 */
			{ 7889, 3,0}, /* core1 elr_EL2 bit57 */
			{ 7890, 3,0}, /* core1 elr_EL2 bit58 */
			{ 7891, 3,0}, /* core1 elr_EL2 bit59 */
			{ 7936, 3,0}, /* core1 elr_EL2 bit60 */
			{ 7937, 3,0}, /* core1 elr_EL2 bit61 */
			{ 7938, 3,0}, /* core1 elr_EL2 bit62 */
			{ 7939, 3,0}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 6040, 3,0}, /* core1 elr_EL3 bit0 */
			{ 6041, 3,0}, /* core1 elr_EL3 bit1 */
			{ 6042, 3,0}, /* core1 elr_EL3 bit2 */
			{ 6043, 3,0}, /* core1 elr_EL3 bit3 */
			{ 7140, 3,0}, /* core1 elr_EL3 bit4 */
			{ 7141, 3,0}, /* core1 elr_EL3 bit5 */
			{ 7142, 3,0}, /* core1 elr_EL3 bit6 */
			{ 7143, 3,0}, /* core1 elr_EL3 bit7 */
			{ 7180, 3,0}, /* core1 elr_EL3 bit8 */
			{ 7181, 3,0}, /* core1 elr_EL3 bit9 */
			{ 7182, 3,0}, /* core1 elr_EL3 bit10 */
			{ 7183, 3,0}, /* core1 elr_EL3 bit11 */
			{ 7044, 3,0}, /* core1 elr_EL3 bit12 */
			{ 7045, 3,0}, /* core1 elr_EL3 bit13 */
			{ 7046, 3,0}, /* core1 elr_EL3 bit14 */
			{ 7047, 3,0}, /* core1 elr_EL3 bit15 */
			{ 6864, 3,0}, /* core1 elr_EL3 bit16 */
			{ 6865, 3,0}, /* core1 elr_EL3 bit17 */
			{ 6866, 3,0}, /* core1 elr_EL3 bit18 */
			{ 6867, 3,0}, /* core1 elr_EL3 bit19 */
			{ 7028, 3,0}, /* core1 elr_EL3 bit20 */
			{ 7029, 3,0}, /* core1 elr_EL3 bit21 */
			{ 7030, 3,0}, /* core1 elr_EL3 bit22 */
			{ 7031, 3,0}, /* core1 elr_EL3 bit23 */
			{ 6860, 3,0}, /* core1 elr_EL3 bit24 */
			{ 6861, 3,0}, /* core1 elr_EL3 bit25 */
			{ 6862, 3,0}, /* core1 elr_EL3 bit26 */
			{ 6863, 3,0}, /* core1 elr_EL3 bit27 */
			{ 7204, 3,0}, /* core1 elr_EL3 bit28 */
			{ 7205, 3,0}, /* core1 elr_EL3 bit29 */
			{ 7206, 3,0}, /* core1 elr_EL3 bit30 */
			{ 7207, 3,0}, /* core1 elr_EL3 bit31 */
			{ 8340, 3,0}, /* core1 elr_EL3 bit32 */
			{ 8341, 3,0}, /* core1 elr_EL3 bit33 */
			{ 8342, 3,0}, /* core1 elr_EL3 bit34 */
			{ 8343, 3,0}, /* core1 elr_EL3 bit35 */
			{ 8252, 3,0}, /* core1 elr_EL3 bit36 */
			{ 8253, 3,0}, /* core1 elr_EL3 bit37 */
			{ 8254, 3,0}, /* core1 elr_EL3 bit38 */
			{ 8255, 3,0}, /* core1 elr_EL3 bit39 */
			{ 7868, 3,0}, /* core1 elr_EL3 bit40 */
			{ 7869, 3,0}, /* core1 elr_EL3 bit41 */
			{ 7870, 3,0}, /* core1 elr_EL3 bit42 */
			{ 7871, 3,0}, /* core1 elr_EL3 bit43 */
			{ 7864, 3,0}, /* core1 elr_EL3 bit44 */
			{ 7865, 3,0}, /* core1 elr_EL3 bit45 */
			{ 7866, 3,0}, /* core1 elr_EL3 bit46 */
			{ 7867, 3,0}, /* core1 elr_EL3 bit47 */
			{ 7876, 3,0}, /* core1 elr_EL3 bit48 */
			{ 7877, 3,0}, /* core1 elr_EL3 bit49 */
			{ 7878, 3,0}, /* core1 elr_EL3 bit50 */
			{ 7879, 3,0}, /* core1 elr_EL3 bit51 */
			{ 8324, 3,0}, /* core1 elr_EL3 bit52 */
			{ 8325, 3,0}, /* core1 elr_EL3 bit53 */
			{ 8326, 3,0}, /* core1 elr_EL3 bit54 */
			{ 8327, 3,0}, /* core1 elr_EL3 bit55 */
			{ 7924, 3,0}, /* core1 elr_EL3 bit56 */
			{ 7925, 3,0}, /* core1 elr_EL3 bit57 */
			{ 7926, 3,0}, /* core1 elr_EL3 bit58 */
			{ 7927, 3,0}, /* core1 elr_EL3 bit59 */
			{ 7940, 3,0}, /* core1 elr_EL3 bit60 */
			{ 7941, 3,0}, /* core1 elr_EL3 bit61 */
			{ 7942, 3,0}, /* core1 elr_EL3 bit62 */
			{ 7943, 3,0}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 8448, 4,0}, /* core1 raw_pc bit0 */
			{10692, 3,0}, /* core1 raw_pc bit1 */
			{10693, 3,0}, /* core1 raw_pc bit2 */
			{ 9360, 3,0}, /* core1 raw_pc bit3 */
			{ 9361, 3,0}, /* core1 raw_pc bit4 */
			{ 9362, 3,0}, /* core1 raw_pc bit5 */
			{ 9363, 3,0}, /* core1 raw_pc bit6 */
			{12608, 3,0}, /* core1 raw_pc bit7 */
			{12609, 3,0}, /* core1 raw_pc bit8 */
			{12610, 3,0}, /* core1 raw_pc bit9 */
			{12611, 3,0}, /* core1 raw_pc bit10 */
			{12580, 3,0}, /* core1 raw_pc bit11 */
			{12581, 3,0}, /* core1 raw_pc bit12 */
			{12582, 3,0}, /* core1 raw_pc bit13 */
			{12583, 3,0}, /* core1 raw_pc bit14 */
			{12584, 3,0}, /* core1 raw_pc bit15 */
			{12585, 3,0}, /* core1 raw_pc bit16 */
			{12586, 3,0}, /* core1 raw_pc bit17 */
			{12587, 3,0}, /* core1 raw_pc bit18 */
			{12576, 3,0}, /* core1 raw_pc bit19 */
			{12577, 3,0}, /* core1 raw_pc bit20 */
			{12578, 3,0}, /* core1 raw_pc bit21 */
			{12579, 3,0}, /* core1 raw_pc bit22 */
			{ 9376, 3,0}, /* core1 raw_pc bit23 */
			{ 9377, 3,0}, /* core1 raw_pc bit24 */
			{ 9378, 3,0}, /* core1 raw_pc bit25 */
			{ 9379, 3,0}, /* core1 raw_pc bit26 */
			{ 9384, 3,0}, /* core1 raw_pc bit27 */
			{ 9385, 3,0}, /* core1 raw_pc bit28 */
			{ 9386, 3,0}, /* core1 raw_pc bit29 */
			{ 9387, 3,0}, /* core1 raw_pc bit30 */
			{14492, 3,0}, /* core1 raw_pc bit31 */
			{12620, 3,0}, /* core1 raw_pc bit32 */
			{12621, 3,0}, /* core1 raw_pc bit33 */
			{12622, 3,0}, /* core1 raw_pc bit34 */
			{12623, 3,0}, /* core1 raw_pc bit35 */
			{ 9408, 3,0}, /* core1 raw_pc bit36 */
			{ 9409, 3,0}, /* core1 raw_pc bit37 */
			{ 9410, 3,0}, /* core1 raw_pc bit38 */
			{ 9411, 3,0}, /* core1 raw_pc bit39 */
			{ 9396, 3,0}, /* core1 raw_pc bit40 */
			{ 9397, 3,0}, /* core1 raw_pc bit41 */
			{ 9398, 3,0}, /* core1 raw_pc bit42 */
			{ 9399, 3,0}, /* core1 raw_pc bit43 */
			{ 9392, 3,0}, /* core1 raw_pc bit44 */
			{ 9393, 3,0}, /* core1 raw_pc bit45 */
			{ 9394, 3,0}, /* core1 raw_pc bit46 */
			{ 9395, 3,0}, /* core1 raw_pc bit47 */
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
			{15238, 3,0}, /* core1 pc_iss bit0 */
			{15206, 3,0}, /* core1 pc_iss bit1 */
			{15235, 3,0}, /* core1 pc_iss bit2 */
			{15306, 3,0}, /* core1 pc_iss bit3 */
			{15203, 3,0}, /* core1 pc_iss bit4 */
			{15297, 3,0}, /* core1 pc_iss bit5 */
			{15207, 3,0}, /* core1 pc_iss bit6 */
			{15204, 3,0}, /* core1 pc_iss bit7 */
			{15208, 3,0}, /* core1 pc_iss bit8 */
			{15209, 3,0}, /* core1 pc_iss bit9 */
			{15211, 3,0}, /* core1 pc_iss bit10 */
			{15200, 3,0}, /* core1 pc_iss bit11 */
			{15215, 3,0}, /* core1 pc_iss bit12 */
			{15212, 3,0}, /* core1 pc_iss bit13 */
			{15188, 3,0}, /* core1 pc_iss bit14 */
			{15210, 3,0}, /* core1 pc_iss bit15 */
			{15217, 3,0}, /* core1 pc_iss bit16 */
			{15213, 3,0}, /* core1 pc_iss bit17 */
			{15214, 3,0}, /* core1 pc_iss bit18 */
			{15189, 3,0}, /* core1 pc_iss bit19 */
			{15187, 3,0}, /* core1 pc_iss bit20 */
			{15216, 3,0}, /* core1 pc_iss bit21 */
			{15196, 3,0}, /* core1 pc_iss bit22 */
			{15195, 3,0}, /* core1 pc_iss bit23 */
			{15186, 3,0}, /* core1 pc_iss bit24 */
			{15193, 3,0}, /* core1 pc_iss bit25 */
			{15194, 3,0}, /* core1 pc_iss bit26 */
			{15327, 3,0}, /* core1 pc_iss bit27 */
			{15333, 3,0}, /* core1 pc_iss bit28 */
			{15326, 3,0}, /* core1 pc_iss bit29 */
			{15191, 3,0}, /* core1 pc_iss bit30 */
			{15336, 3,0}, /* core1 pc_iss bit31 */
			{12440, 3,0}, /* core1 pc_iss bit32 */
			{12441, 3,0}, /* core1 pc_iss bit33 */
			{12442, 3,0}, /* core1 pc_iss bit34 */
			{12443, 3,0}, /* core1 pc_iss bit35 */
			{12436, 3,0}, /* core1 pc_iss bit36 */
			{12437, 3,0}, /* core1 pc_iss bit37 */
			{12438, 3,0}, /* core1 pc_iss bit38 */
			{12439, 3,0}, /* core1 pc_iss bit39 */
			{12516, 3,0}, /* core1 pc_iss bit40 */
			{12517, 3,0}, /* core1 pc_iss bit41 */
			{12518, 3,0}, /* core1 pc_iss bit42 */
			{12519, 3,0}, /* core1 pc_iss bit43 */
			{12512, 3,0}, /* core1 pc_iss bit44 */
			{12513, 3,0}, /* core1 pc_iss bit45 */
			{12514, 3,0}, /* core1 pc_iss bit46 */
			{12515, 3,0}, /* core1 pc_iss bit47 */
			{12636, 3,0}, /* core1 pc_iss bit48 */
			{12637, 3,0}, /* core1 pc_iss bit49 */
			{12638, 3,0}, /* core1 pc_iss bit50 */
			{12639, 3,0}, /* core1 pc_iss bit51 */
			{12632, 3,0}, /* core1 pc_iss bit52 */
			{12633, 3,0}, /* core1 pc_iss bit53 */
			{12634, 3,0}, /* core1 pc_iss bit54 */
			{12635, 3,0}, /* core1 pc_iss bit55 */
			{12640, 3,0}, /* core1 pc_iss bit56 */
			{12641, 3,0}, /* core1 pc_iss bit57 */
			{12642, 3,0}, /* core1 pc_iss bit58 */
			{12643, 3,0}, /* core1 pc_iss bit59 */
			{12644, 3,0}, /* core1 pc_iss bit60 */
			{12645, 3,0}, /* core1 pc_iss bit61 */
			{12646, 3,0}, /* core1 pc_iss bit62 */
			{12647, 3,0}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 8447, 4,0}, /* core1 full_pc_wr bit0 */
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
			{15304, 3,0}, /* core1 full_pc_ex1 bit0 */
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
			{ 8443, 4,0}, /* core1 full_pc_ex2 bit0 */
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
	},
	{		/* core 2 */ 
			.pc = {{
			{ 6231, 5,0}, /* core2 pc bit0 */
			{ 6232, 5,0}, /* core2 pc bit1 */
			{ 6233, 5,0}, /* core2 pc bit2 */
			{ 6234, 5,0}, /* core2 pc bit3 */
			{ 6296, 5,0}, /* core2 pc bit4 */
			{ 6297, 5,0}, /* core2 pc bit5 */
			{ 6298, 5,0}, /* core2 pc bit6 */
			{ 6299, 5,0}, /* core2 pc bit7 */
			{ 6340, 5,0}, /* core2 pc bit8 */
			{ 6341, 5,0}, /* core2 pc bit9 */
			{ 6342, 5,0}, /* core2 pc bit10 */
			{ 6343, 5,0}, /* core2 pc bit11 */
			{ 6480, 5,0}, /* core2 pc bit12 */
			{ 6481, 5,0}, /* core2 pc bit13 */
			{ 6482, 5,0}, /* core2 pc bit14 */
			{ 6483, 5,0}, /* core2 pc bit15 */
			{ 6692, 5,0}, /* core2 pc bit16 */
			{ 6693, 5,0}, /* core2 pc bit17 */
			{ 6694, 5,0}, /* core2 pc bit18 */
			{ 6695, 5,0}, /* core2 pc bit19 */
			{ 6352, 5,0}, /* core2 pc bit20 */
			{ 6353, 5,0}, /* core2 pc bit21 */
			{ 6354, 5,0}, /* core2 pc bit22 */
			{ 6355, 5,0}, /* core2 pc bit23 */
			{ 6696, 5,0}, /* core2 pc bit24 */
			{ 6697, 5,0}, /* core2 pc bit25 */
			{ 6698, 5,0}, /* core2 pc bit26 */
			{ 6699, 5,0}, /* core2 pc bit27 */
			{ 6328, 5,0}, /* core2 pc bit28 */
			{ 6329, 5,0}, /* core2 pc bit29 */
			{ 6330, 5,0}, /* core2 pc bit30 */
			{ 6331, 5,0}, /* core2 pc bit31 */
			{13288, 5,0}, /* core2 pc bit32 */
			{13289, 5,0}, /* core2 pc bit33 */
			{13290, 5,0}, /* core2 pc bit34 */
			{13291, 5,0}, /* core2 pc bit35 */
			{13280, 5,0}, /* core2 pc bit36 */
			{13281, 5,0}, /* core2 pc bit37 */
			{13282, 5,0}, /* core2 pc bit38 */
			{13283, 5,0}, /* core2 pc bit39 */
			{13268, 5,0}, /* core2 pc bit40 */
			{13269, 5,0}, /* core2 pc bit41 */
			{13270, 5,0}, /* core2 pc bit42 */
			{13271, 5,0}, /* core2 pc bit43 */
			{13284, 5,0}, /* core2 pc bit44 */
			{13285, 5,0}, /* core2 pc bit45 */
			{13286, 5,0}, /* core2 pc bit46 */
			{13287, 5,0}, /* core2 pc bit47 */
			{13264, 5,0}, /* core2 pc bit48 */
			{13265, 5,0}, /* core2 pc bit49 */
			{13266, 5,0}, /* core2 pc bit50 */
			{13267, 5,0}, /* core2 pc bit51 */
			{13272, 5,0}, /* core2 pc bit52 */
			{13273, 5,0}, /* core2 pc bit53 */
			{13274, 5,0}, /* core2 pc bit54 */
			{13275, 5,0}, /* core2 pc bit55 */
			{13292, 5,0}, /* core2 pc bit56 */
			{13293, 5,0}, /* core2 pc bit57 */
			{13294, 5,0}, /* core2 pc bit58 */
			{13295, 5,0}, /* core2 pc bit59 */
			{13276, 5,0}, /* core2 pc bit60 */
			{13277, 5,0}, /* core2 pc bit61 */
			{13278, 5,0}, /* core2 pc bit62 */
			{13279, 5,0}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{ 6012, 5,0}, /* core2 sp32 bit0 */
			{ 6013, 5,0}, /* core2 sp32 bit1 */
			{ 6014, 5,0}, /* core2 sp32 bit2 */
			{ 6015, 5,0}, /* core2 sp32 bit3 */
			{ 6188, 5,0}, /* core2 sp32 bit4 */
			{ 6189, 5,0}, /* core2 sp32 bit5 */
			{ 6190, 5,0}, /* core2 sp32 bit6 */
			{ 6191, 5,0}, /* core2 sp32 bit7 */
			{ 6992, 5,0}, /* core2 sp32 bit8 */
			{ 6993, 5,0}, /* core2 sp32 bit9 */
			{ 6994, 5,0}, /* core2 sp32 bit10 */
			{ 6995, 5,0}, /* core2 sp32 bit11 */
			{ 6872, 5,0}, /* core2 sp32 bit12 */
			{ 6873, 5,0}, /* core2 sp32 bit13 */
			{ 6874, 5,0}, /* core2 sp32 bit14 */
			{ 6875, 5,0}, /* core2 sp32 bit15 */
			{ 6884, 5,0}, /* core2 sp32 bit16 */
			{ 6885, 5,0}, /* core2 sp32 bit17 */
			{ 6886, 5,0}, /* core2 sp32 bit18 */
			{ 6887, 5,0}, /* core2 sp32 bit19 */
			{ 6944, 5,0}, /* core2 sp32 bit20 */
			{ 6945, 5,0}, /* core2 sp32 bit21 */
			{ 6946, 5,0}, /* core2 sp32 bit22 */
			{ 6947, 5,0}, /* core2 sp32 bit23 */
			{ 6880, 5,0}, /* core2 sp32 bit24 */
			{ 6881, 5,0}, /* core2 sp32 bit25 */
			{ 6882, 5,0}, /* core2 sp32 bit26 */
			{ 6883, 5,0}, /* core2 sp32 bit27 */
			{ 6980, 5,0}, /* core2 sp32 bit28 */
			{ 6981, 5,0}, /* core2 sp32 bit29 */
			{ 6982, 5,0}, /* core2 sp32 bit30 */
			{ 6983, 5,0}, /* core2 sp32 bit31 */
			{11004, 5,0}, /* core2 sp32 bit32 */
			{11005, 5,0}, /* core2 sp32 bit33 */
			{11006, 5,0}, /* core2 sp32 bit34 */
			{11007, 5,0}, /* core2 sp32 bit35 */
			{ 2324, 6,0}, /* core2 sp32 bit36 */
			{ 2325, 6,0}, /* core2 sp32 bit37 */
			{ 2326, 6,0}, /* core2 sp32 bit38 */
			{ 2327, 6,0}, /* core2 sp32 bit39 */
			{ 2316, 6,0}, /* core2 sp32 bit40 */
			{ 2317, 6,0}, /* core2 sp32 bit41 */
			{ 2318, 6,0}, /* core2 sp32 bit42 */
			{ 2319, 6,0}, /* core2 sp32 bit43 */
			{ 2312, 6,0}, /* core2 sp32 bit44 */
			{ 2313, 6,0}, /* core2 sp32 bit45 */
			{ 2314, 6,0}, /* core2 sp32 bit46 */
			{ 2315, 6,0}, /* core2 sp32 bit47 */
			{ 2308, 6,0}, /* core2 sp32 bit48 */
			{ 2309, 6,0}, /* core2 sp32 bit49 */
			{ 2310, 6,0}, /* core2 sp32 bit50 */
			{ 2311, 6,0}, /* core2 sp32 bit51 */
			{11072, 5,0}, /* core2 sp32 bit52 */
			{11073, 5,0}, /* core2 sp32 bit53 */
			{11074, 5,0}, /* core2 sp32 bit54 */
			{11075, 5,0}, /* core2 sp32 bit55 */
			{11036, 5,0}, /* core2 sp32 bit56 */
			{11037, 5,0}, /* core2 sp32 bit57 */
			{11038, 5,0}, /* core2 sp32 bit58 */
			{11039, 5,0}, /* core2 sp32 bit59 */
			{11024, 5,0}, /* core2 sp32 bit60 */
			{11025, 5,0}, /* core2 sp32 bit61 */
			{11026, 5,0}, /* core2 sp32 bit62 */
			{11027, 5,0}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7136, 5,0}, /* core2 fp32 bit0 */
			{ 7137, 5,0}, /* core2 fp32 bit1 */
			{ 7138, 5,0}, /* core2 fp32 bit2 */
			{ 7139, 5,0}, /* core2 fp32 bit3 */
			{ 7152, 5,0}, /* core2 fp32 bit4 */
			{ 7153, 5,0}, /* core2 fp32 bit5 */
			{ 7154, 5,0}, /* core2 fp32 bit6 */
			{ 7155, 5,0}, /* core2 fp32 bit7 */
			{   32, 5,0}, /* core2 fp32 bit8 */
			{   33, 5,0}, /* core2 fp32 bit9 */
			{   34, 5,0}, /* core2 fp32 bit10 */
			{   35, 5,0}, /* core2 fp32 bit11 */
			{ 8444, 5,0}, /* core2 fp32 bit12 */
			{ 8445, 5,0}, /* core2 fp32 bit13 */
			{ 8446, 5,0}, /* core2 fp32 bit14 */
			{ 8447, 5,0}, /* core2 fp32 bit15 */
			{ 8440, 5,0}, /* core2 fp32 bit16 */
			{ 8441, 5,0}, /* core2 fp32 bit17 */
			{ 8442, 5,0}, /* core2 fp32 bit18 */
			{ 8443, 5,0}, /* core2 fp32 bit19 */
			{ 7080, 5,0}, /* core2 fp32 bit20 */
			{ 7081, 5,0}, /* core2 fp32 bit21 */
			{ 7082, 5,0}, /* core2 fp32 bit22 */
			{ 7083, 5,0}, /* core2 fp32 bit23 */
			{ 8424, 5,0}, /* core2 fp32 bit24 */
			{ 8425, 5,0}, /* core2 fp32 bit25 */
			{ 8426, 5,0}, /* core2 fp32 bit26 */
			{ 8427, 5,0}, /* core2 fp32 bit27 */
			{ 8216, 5,0}, /* core2 fp32 bit28 */
			{ 8217, 5,0}, /* core2 fp32 bit29 */
			{ 8218, 5,0}, /* core2 fp32 bit30 */
			{ 8219, 5,0}, /* core2 fp32 bit31 */
			{ 7516, 5,0}, /* core2 fp32 bit32 */
			{ 7517, 5,0}, /* core2 fp32 bit33 */
			{ 7518, 5,0}, /* core2 fp32 bit34 */
			{ 7519, 5,0}, /* core2 fp32 bit35 */
			{ 7592, 5,0}, /* core2 fp32 bit36 */
			{ 7593, 5,0}, /* core2 fp32 bit37 */
			{ 7594, 5,0}, /* core2 fp32 bit38 */
			{ 7595, 5,0}, /* core2 fp32 bit39 */
			{ 7484, 5,0}, /* core2 fp32 bit40 */
			{ 7485, 5,0}, /* core2 fp32 bit41 */
			{ 7486, 5,0}, /* core2 fp32 bit42 */
			{ 7487, 5,0}, /* core2 fp32 bit43 */
			{ 7476, 5,0}, /* core2 fp32 bit44 */
			{ 7477, 5,0}, /* core2 fp32 bit45 */
			{ 7478, 5,0}, /* core2 fp32 bit46 */
			{ 7479, 5,0}, /* core2 fp32 bit47 */
			{ 7480, 5,0}, /* core2 fp32 bit48 */
			{ 7481, 5,0}, /* core2 fp32 bit49 */
			{ 7482, 5,0}, /* core2 fp32 bit50 */
			{ 7483, 5,0}, /* core2 fp32 bit51 */
			{ 8128, 5,0}, /* core2 fp32 bit52 */
			{ 8129, 5,0}, /* core2 fp32 bit53 */
			{ 8130, 5,0}, /* core2 fp32 bit54 */
			{ 8131, 5,0}, /* core2 fp32 bit55 */
			{ 8132, 5,0}, /* core2 fp32 bit56 */
			{ 8133, 5,0}, /* core2 fp32 bit57 */
			{ 8134, 5,0}, /* core2 fp32 bit58 */
			{ 8135, 5,0}, /* core2 fp32 bit59 */
			{ 7616, 5,0}, /* core2 fp32 bit60 */
			{ 7617, 5,0}, /* core2 fp32 bit61 */
			{ 7618, 5,0}, /* core2 fp32 bit62 */
			{ 7619, 5,0}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{ 6211, 5,0}, /* core2 fp64 bit0 */
			{ 6212, 5,0}, /* core2 fp64 bit1 */
			{ 6213, 5,0}, /* core2 fp64 bit2 */
			{ 6214, 5,0}, /* core2 fp64 bit3 */
			{ 6276, 5,0}, /* core2 fp64 bit4 */
			{ 6277, 5,0}, /* core2 fp64 bit5 */
			{ 6278, 5,0}, /* core2 fp64 bit6 */
			{ 6279, 5,0}, /* core2 fp64 bit7 */
			{ 6376, 5,0}, /* core2 fp64 bit8 */
			{ 6377, 5,0}, /* core2 fp64 bit9 */
			{ 6378, 5,0}, /* core2 fp64 bit10 */
			{ 6379, 5,0}, /* core2 fp64 bit11 */
			{ 6476, 5,0}, /* core2 fp64 bit12 */
			{ 6477, 5,0}, /* core2 fp64 bit13 */
			{ 6478, 5,0}, /* core2 fp64 bit14 */
			{ 6479, 5,0}, /* core2 fp64 bit15 */
			{ 6684, 5,0}, /* core2 fp64 bit16 */
			{ 6685, 5,0}, /* core2 fp64 bit17 */
			{ 6686, 5,0}, /* core2 fp64 bit18 */
			{ 6687, 5,0}, /* core2 fp64 bit19 */
			{ 6356, 5,0}, /* core2 fp64 bit20 */
			{ 6357, 5,0}, /* core2 fp64 bit21 */
			{ 6358, 5,0}, /* core2 fp64 bit22 */
			{ 6359, 5,0}, /* core2 fp64 bit23 */
			{ 6688, 5,0}, /* core2 fp64 bit24 */
			{ 6689, 5,0}, /* core2 fp64 bit25 */
			{ 6690, 5,0}, /* core2 fp64 bit26 */
			{ 6691, 5,0}, /* core2 fp64 bit27 */
			{ 6392, 5,0}, /* core2 fp64 bit28 */
			{ 6393, 5,0}, /* core2 fp64 bit29 */
			{ 6394, 5,0}, /* core2 fp64 bit30 */
			{ 6395, 5,0}, /* core2 fp64 bit31 */
			{ 7908, 5,0}, /* core2 fp64 bit32 */
			{ 7909, 5,0}, /* core2 fp64 bit33 */
			{ 7910, 5,0}, /* core2 fp64 bit34 */
			{ 7911, 5,0}, /* core2 fp64 bit35 */
			{ 8260, 5,0}, /* core2 fp64 bit36 */
			{ 8261, 5,0}, /* core2 fp64 bit37 */
			{ 8262, 5,0}, /* core2 fp64 bit38 */
			{ 8263, 5,0}, /* core2 fp64 bit39 */
			{ 8272, 5,0}, /* core2 fp64 bit40 */
			{ 8273, 5,0}, /* core2 fp64 bit41 */
			{ 8274, 5,0}, /* core2 fp64 bit42 */
			{ 8275, 5,0}, /* core2 fp64 bit43 */
			{ 8276, 5,0}, /* core2 fp64 bit44 */
			{ 8277, 5,0}, /* core2 fp64 bit45 */
			{ 8278, 5,0}, /* core2 fp64 bit46 */
			{ 8279, 5,0}, /* core2 fp64 bit47 */
			{ 8312, 5,0}, /* core2 fp64 bit48 */
			{ 8313, 5,0}, /* core2 fp64 bit49 */
			{ 8314, 5,0}, /* core2 fp64 bit50 */
			{ 8315, 5,0}, /* core2 fp64 bit51 */
			{ 8320, 5,0}, /* core2 fp64 bit52 */
			{ 8321, 5,0}, /* core2 fp64 bit53 */
			{ 8322, 5,0}, /* core2 fp64 bit54 */
			{ 8323, 5,0}, /* core2 fp64 bit55 */
			{ 7900, 5,0}, /* core2 fp64 bit56 */
			{ 7901, 5,0}, /* core2 fp64 bit57 */
			{ 7902, 5,0}, /* core2 fp64 bit58 */
			{ 7903, 5,0}, /* core2 fp64 bit59 */
			{ 7968, 5,0}, /* core2 fp64 bit60 */
			{ 7969, 5,0}, /* core2 fp64 bit61 */
			{ 7970, 5,0}, /* core2 fp64 bit62 */
			{ 7971, 5,0}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 6132, 5,0}, /* core2 sp_EL0 bit0 */
			{ 6133, 5,0}, /* core2 sp_EL0 bit1 */
			{ 6134, 5,0}, /* core2 sp_EL0 bit2 */
			{ 6135, 5,0}, /* core2 sp_EL0 bit3 */
			{ 6260, 5,0}, /* core2 sp_EL0 bit4 */
			{ 6261, 5,0}, /* core2 sp_EL0 bit5 */
			{ 6262, 5,0}, /* core2 sp_EL0 bit6 */
			{ 6263, 5,0}, /* core2 sp_EL0 bit7 */
			{ 6236, 5,0}, /* core2 sp_EL0 bit8 */
			{ 6237, 5,0}, /* core2 sp_EL0 bit9 */
			{ 6238, 5,0}, /* core2 sp_EL0 bit10 */
			{ 6239, 5,0}, /* core2 sp_EL0 bit11 */
			{ 6452, 5,0}, /* core2 sp_EL0 bit12 */
			{ 6453, 5,0}, /* core2 sp_EL0 bit13 */
			{ 6454, 5,0}, /* core2 sp_EL0 bit14 */
			{ 6455, 5,0}, /* core2 sp_EL0 bit15 */
			{ 6740, 5,0}, /* core2 sp_EL0 bit16 */
			{ 6741, 5,0}, /* core2 sp_EL0 bit17 */
			{ 6742, 5,0}, /* core2 sp_EL0 bit18 */
			{ 6743, 5,0}, /* core2 sp_EL0 bit19 */
			{ 6432, 5,0}, /* core2 sp_EL0 bit20 */
			{ 6433, 5,0}, /* core2 sp_EL0 bit21 */
			{ 6434, 5,0}, /* core2 sp_EL0 bit22 */
			{ 6435, 5,0}, /* core2 sp_EL0 bit23 */
			{ 6736, 5,0}, /* core2 sp_EL0 bit24 */
			{ 6737, 5,0}, /* core2 sp_EL0 bit25 */
			{ 6738, 5,0}, /* core2 sp_EL0 bit26 */
			{ 6739, 5,0}, /* core2 sp_EL0 bit27 */
			{ 6408, 5,0}, /* core2 sp_EL0 bit28 */
			{ 6409, 5,0}, /* core2 sp_EL0 bit29 */
			{ 6410, 5,0}, /* core2 sp_EL0 bit30 */
			{ 6411, 5,0}, /* core2 sp_EL0 bit31 */
			{ 7916, 5,0}, /* core2 sp_EL0 bit32 */
			{ 7917, 5,0}, /* core2 sp_EL0 bit33 */
			{ 7918, 5,0}, /* core2 sp_EL0 bit34 */
			{ 7919, 5,0}, /* core2 sp_EL0 bit35 */
			{  153, 5,0}, /* core2 sp_EL0 bit36 */
			{  154, 5,0}, /* core2 sp_EL0 bit37 */
			{  155, 5,0}, /* core2 sp_EL0 bit38 */
			{  156, 5,0}, /* core2 sp_EL0 bit39 */
			{  161, 5,0}, /* core2 sp_EL0 bit40 */
			{  162, 5,0}, /* core2 sp_EL0 bit41 */
			{  163, 5,0}, /* core2 sp_EL0 bit42 */
			{  164, 5,0}, /* core2 sp_EL0 bit43 */
			{  165, 5,0}, /* core2 sp_EL0 bit44 */
			{  166, 5,0}, /* core2 sp_EL0 bit45 */
			{  167, 5,0}, /* core2 sp_EL0 bit46 */
			{  168, 5,0}, /* core2 sp_EL0 bit47 */
			{ 7440, 5,0}, /* core2 sp_EL0 bit48 */
			{ 7441, 5,0}, /* core2 sp_EL0 bit49 */
			{ 7442, 5,0}, /* core2 sp_EL0 bit50 */
			{ 7443, 5,0}, /* core2 sp_EL0 bit51 */
			{ 7468, 5,0}, /* core2 sp_EL0 bit52 */
			{ 7469, 5,0}, /* core2 sp_EL0 bit53 */
			{ 7470, 5,0}, /* core2 sp_EL0 bit54 */
			{ 7471, 5,0}, /* core2 sp_EL0 bit55 */
			{ 7892, 5,0}, /* core2 sp_EL0 bit56 */
			{ 7893, 5,0}, /* core2 sp_EL0 bit57 */
			{ 7894, 5,0}, /* core2 sp_EL0 bit58 */
			{ 7895, 5,0}, /* core2 sp_EL0 bit59 */
			{ 7948, 5,0}, /* core2 sp_EL0 bit60 */
			{ 7949, 5,0}, /* core2 sp_EL0 bit61 */
			{ 7950, 5,0}, /* core2 sp_EL0 bit62 */
			{ 7951, 5,0}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6215, 5,0}, /* core2 sp_EL1 bit0 */
			{ 6216, 5,0}, /* core2 sp_EL1 bit1 */
			{ 6217, 5,0}, /* core2 sp_EL1 bit2 */
			{ 6218, 5,0}, /* core2 sp_EL1 bit3 */
			{ 6272, 5,0}, /* core2 sp_EL1 bit4 */
			{ 6273, 5,0}, /* core2 sp_EL1 bit5 */
			{ 6274, 5,0}, /* core2 sp_EL1 bit6 */
			{ 6275, 5,0}, /* core2 sp_EL1 bit7 */
			{ 6380, 5,0}, /* core2 sp_EL1 bit8 */
			{ 6381, 5,0}, /* core2 sp_EL1 bit9 */
			{ 6382, 5,0}, /* core2 sp_EL1 bit10 */
			{ 6383, 5,0}, /* core2 sp_EL1 bit11 */
			{ 6472, 5,0}, /* core2 sp_EL1 bit12 */
			{ 6473, 5,0}, /* core2 sp_EL1 bit13 */
			{ 6474, 5,0}, /* core2 sp_EL1 bit14 */
			{ 6475, 5,0}, /* core2 sp_EL1 bit15 */
			{ 6648, 5,0}, /* core2 sp_EL1 bit16 */
			{ 6649, 5,0}, /* core2 sp_EL1 bit17 */
			{ 6650, 5,0}, /* core2 sp_EL1 bit18 */
			{ 6651, 5,0}, /* core2 sp_EL1 bit19 */
			{ 6976, 5,0}, /* core2 sp_EL1 bit20 */
			{ 6977, 5,0}, /* core2 sp_EL1 bit21 */
			{ 6978, 5,0}, /* core2 sp_EL1 bit22 */
			{ 6979, 5,0}, /* core2 sp_EL1 bit23 */
			{ 6652, 5,0}, /* core2 sp_EL1 bit24 */
			{ 6653, 5,0}, /* core2 sp_EL1 bit25 */
			{ 6654, 5,0}, /* core2 sp_EL1 bit26 */
			{ 6655, 5,0}, /* core2 sp_EL1 bit27 */
			{ 6388, 5,0}, /* core2 sp_EL1 bit28 */
			{ 6389, 5,0}, /* core2 sp_EL1 bit29 */
			{ 6390, 5,0}, /* core2 sp_EL1 bit30 */
			{ 6391, 5,0}, /* core2 sp_EL1 bit31 */
			{ 7904, 5,0}, /* core2 sp_EL1 bit32 */
			{ 7905, 5,0}, /* core2 sp_EL1 bit33 */
			{ 7906, 5,0}, /* core2 sp_EL1 bit34 */
			{ 7907, 5,0}, /* core2 sp_EL1 bit35 */
			{ 8304, 5,0}, /* core2 sp_EL1 bit36 */
			{ 8305, 5,0}, /* core2 sp_EL1 bit37 */
			{ 8306, 5,0}, /* core2 sp_EL1 bit38 */
			{ 8307, 5,0}, /* core2 sp_EL1 bit39 */
			{ 8296, 5,0}, /* core2 sp_EL1 bit40 */
			{ 8297, 5,0}, /* core2 sp_EL1 bit41 */
			{ 8298, 5,0}, /* core2 sp_EL1 bit42 */
			{ 8299, 5,0}, /* core2 sp_EL1 bit43 */
			{ 8292, 5,0}, /* core2 sp_EL1 bit44 */
			{ 8293, 5,0}, /* core2 sp_EL1 bit45 */
			{ 8294, 5,0}, /* core2 sp_EL1 bit46 */
			{ 8295, 5,0}, /* core2 sp_EL1 bit47 */
			{ 8308, 5,0}, /* core2 sp_EL1 bit48 */
			{ 8309, 5,0}, /* core2 sp_EL1 bit49 */
			{ 8310, 5,0}, /* core2 sp_EL1 bit50 */
			{ 8311, 5,0}, /* core2 sp_EL1 bit51 */
			{ 8328, 5,0}, /* core2 sp_EL1 bit52 */
			{ 8329, 5,0}, /* core2 sp_EL1 bit53 */
			{ 8330, 5,0}, /* core2 sp_EL1 bit54 */
			{ 8331, 5,0}, /* core2 sp_EL1 bit55 */
			{ 8336, 5,0}, /* core2 sp_EL1 bit56 */
			{ 8337, 5,0}, /* core2 sp_EL1 bit57 */
			{ 8338, 5,0}, /* core2 sp_EL1 bit58 */
			{ 8339, 5,0}, /* core2 sp_EL1 bit59 */
			{ 7964, 5,0}, /* core2 sp_EL1 bit60 */
			{ 7965, 5,0}, /* core2 sp_EL1 bit61 */
			{ 7966, 5,0}, /* core2 sp_EL1 bit62 */
			{ 7967, 5,0}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 6120, 5,0}, /* core2 sp_EL2 bit0 */
			{ 6121, 5,0}, /* core2 sp_EL2 bit1 */
			{ 6122, 5,0}, /* core2 sp_EL2 bit2 */
			{ 6123, 5,0}, /* core2 sp_EL2 bit3 */
			{ 6148, 5,0}, /* core2 sp_EL2 bit4 */
			{ 6149, 5,0}, /* core2 sp_EL2 bit5 */
			{ 6150, 5,0}, /* core2 sp_EL2 bit6 */
			{ 6151, 5,0}, /* core2 sp_EL2 bit7 */
			{ 6960, 5,0}, /* core2 sp_EL2 bit8 */
			{ 6961, 5,0}, /* core2 sp_EL2 bit9 */
			{ 6962, 5,0}, /* core2 sp_EL2 bit10 */
			{ 6963, 5,0}, /* core2 sp_EL2 bit11 */
			{ 6444, 5,0}, /* core2 sp_EL2 bit12 */
			{ 6445, 5,0}, /* core2 sp_EL2 bit13 */
			{ 6446, 5,0}, /* core2 sp_EL2 bit14 */
			{ 6447, 5,0}, /* core2 sp_EL2 bit15 */
			{ 6912, 5,0}, /* core2 sp_EL2 bit16 */
			{ 6913, 5,0}, /* core2 sp_EL2 bit17 */
			{ 6914, 5,0}, /* core2 sp_EL2 bit18 */
			{ 6915, 5,0}, /* core2 sp_EL2 bit19 */
			{ 6956, 5,0}, /* core2 sp_EL2 bit20 */
			{ 6957, 5,0}, /* core2 sp_EL2 bit21 */
			{ 6958, 5,0}, /* core2 sp_EL2 bit22 */
			{ 6959, 5,0}, /* core2 sp_EL2 bit23 */
			{ 6908, 5,0}, /* core2 sp_EL2 bit24 */
			{ 6909, 5,0}, /* core2 sp_EL2 bit25 */
			{ 6910, 5,0}, /* core2 sp_EL2 bit26 */
			{ 6911, 5,0}, /* core2 sp_EL2 bit27 */
			{ 6168, 5,0}, /* core2 sp_EL2 bit28 */
			{ 6169, 5,0}, /* core2 sp_EL2 bit29 */
			{ 6170, 5,0}, /* core2 sp_EL2 bit30 */
			{ 6171, 5,0}, /* core2 sp_EL2 bit31 */
			{ 7960, 5,0}, /* core2 sp_EL2 bit32 */
			{ 7961, 5,0}, /* core2 sp_EL2 bit33 */
			{ 7962, 5,0}, /* core2 sp_EL2 bit34 */
			{ 7963, 5,0}, /* core2 sp_EL2 bit35 */
			{  141, 5,0}, /* core2 sp_EL2 bit36 */
			{  142, 5,0}, /* core2 sp_EL2 bit37 */
			{  143, 5,0}, /* core2 sp_EL2 bit38 */
			{  144, 5,0}, /* core2 sp_EL2 bit39 */
			{  149, 5,0}, /* core2 sp_EL2 bit40 */
			{  150, 5,0}, /* core2 sp_EL2 bit41 */
			{  151, 5,0}, /* core2 sp_EL2 bit42 */
			{  152, 5,0}, /* core2 sp_EL2 bit43 */
			{  145, 5,0}, /* core2 sp_EL2 bit44 */
			{  146, 5,0}, /* core2 sp_EL2 bit45 */
			{  147, 5,0}, /* core2 sp_EL2 bit46 */
			{  148, 5,0}, /* core2 sp_EL2 bit47 */
			{ 7880, 5,0}, /* core2 sp_EL2 bit48 */
			{ 7881, 5,0}, /* core2 sp_EL2 bit49 */
			{ 7882, 5,0}, /* core2 sp_EL2 bit50 */
			{ 7883, 5,0}, /* core2 sp_EL2 bit51 */
			{ 8332, 5,0}, /* core2 sp_EL2 bit52 */
			{ 8333, 5,0}, /* core2 sp_EL2 bit53 */
			{ 8334, 5,0}, /* core2 sp_EL2 bit54 */
			{ 8335, 5,0}, /* core2 sp_EL2 bit55 */
			{ 7896, 5,0}, /* core2 sp_EL2 bit56 */
			{ 7897, 5,0}, /* core2 sp_EL2 bit57 */
			{ 7898, 5,0}, /* core2 sp_EL2 bit58 */
			{ 7899, 5,0}, /* core2 sp_EL2 bit59 */
			{ 7956, 5,0}, /* core2 sp_EL2 bit60 */
			{ 7957, 5,0}, /* core2 sp_EL2 bit61 */
			{ 7958, 5,0}, /* core2 sp_EL2 bit62 */
			{ 7959, 5,0}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6004, 5,0}, /* core2 sp_EL3 bit0 */
			{ 6005, 5,0}, /* core2 sp_EL3 bit1 */
			{ 6006, 5,0}, /* core2 sp_EL3 bit2 */
			{ 6007, 5,0}, /* core2 sp_EL3 bit3 */
			{ 6000, 5,0}, /* core2 sp_EL3 bit4 */
			{ 6001, 5,0}, /* core2 sp_EL3 bit5 */
			{ 6002, 5,0}, /* core2 sp_EL3 bit6 */
			{ 6003, 5,0}, /* core2 sp_EL3 bit7 */
			{ 6984, 5,0}, /* core2 sp_EL3 bit8 */
			{ 6985, 5,0}, /* core2 sp_EL3 bit9 */
			{ 6986, 5,0}, /* core2 sp_EL3 bit10 */
			{ 6987, 5,0}, /* core2 sp_EL3 bit11 */
			{ 7040, 5,0}, /* core2 sp_EL3 bit12 */
			{ 7041, 5,0}, /* core2 sp_EL3 bit13 */
			{ 7042, 5,0}, /* core2 sp_EL3 bit14 */
			{ 7043, 5,0}, /* core2 sp_EL3 bit15 */
			{ 6888, 5,0}, /* core2 sp_EL3 bit16 */
			{ 6889, 5,0}, /* core2 sp_EL3 bit17 */
			{ 6890, 5,0}, /* core2 sp_EL3 bit18 */
			{ 6891, 5,0}, /* core2 sp_EL3 bit19 */
			{ 7024, 5,0}, /* core2 sp_EL3 bit20 */
			{ 7025, 5,0}, /* core2 sp_EL3 bit21 */
			{ 7026, 5,0}, /* core2 sp_EL3 bit22 */
			{ 7027, 5,0}, /* core2 sp_EL3 bit23 */
			{ 6852, 5,0}, /* core2 sp_EL3 bit24 */
			{ 6853, 5,0}, /* core2 sp_EL3 bit25 */
			{ 6854, 5,0}, /* core2 sp_EL3 bit26 */
			{ 6855, 5,0}, /* core2 sp_EL3 bit27 */
			{ 7220, 5,0}, /* core2 sp_EL3 bit28 */
			{ 7221, 5,0}, /* core2 sp_EL3 bit29 */
			{ 7222, 5,0}, /* core2 sp_EL3 bit30 */
			{ 7223, 5,0}, /* core2 sp_EL3 bit31 */
			{ 8344, 5,0}, /* core2 sp_EL3 bit32 */
			{ 8345, 5,0}, /* core2 sp_EL3 bit33 */
			{ 8346, 5,0}, /* core2 sp_EL3 bit34 */
			{ 8347, 5,0}, /* core2 sp_EL3 bit35 */
			{ 7448, 5,0}, /* core2 sp_EL3 bit36 */
			{ 7449, 5,0}, /* core2 sp_EL3 bit37 */
			{ 7450, 5,0}, /* core2 sp_EL3 bit38 */
			{ 7451, 5,0}, /* core2 sp_EL3 bit39 */
			{ 7872, 5,0}, /* core2 sp_EL3 bit40 */
			{ 7873, 5,0}, /* core2 sp_EL3 bit41 */
			{ 7874, 5,0}, /* core2 sp_EL3 bit42 */
			{ 7875, 5,0}, /* core2 sp_EL3 bit43 */
			{ 7444, 5,0}, /* core2 sp_EL3 bit44 */
			{ 7445, 5,0}, /* core2 sp_EL3 bit45 */
			{ 7446, 5,0}, /* core2 sp_EL3 bit46 */
			{ 7447, 5,0}, /* core2 sp_EL3 bit47 */
			{ 8316, 5,0}, /* core2 sp_EL3 bit48 */
			{ 8317, 5,0}, /* core2 sp_EL3 bit49 */
			{ 8318, 5,0}, /* core2 sp_EL3 bit50 */
			{ 8319, 5,0}, /* core2 sp_EL3 bit51 */
			{ 8248, 5,0}, /* core2 sp_EL3 bit52 */
			{ 8249, 5,0}, /* core2 sp_EL3 bit53 */
			{ 8250, 5,0}, /* core2 sp_EL3 bit54 */
			{ 8251, 5,0}, /* core2 sp_EL3 bit55 */
			{ 7884, 5,0}, /* core2 sp_EL3 bit56 */
			{ 7885, 5,0}, /* core2 sp_EL3 bit57 */
			{ 7886, 5,0}, /* core2 sp_EL3 bit58 */
			{ 7887, 5,0}, /* core2 sp_EL3 bit59 */
			{ 7944, 5,0}, /* core2 sp_EL3 bit60 */
			{ 7945, 5,0}, /* core2 sp_EL3 bit61 */
			{ 7946, 5,0}, /* core2 sp_EL3 bit62 */
			{ 7947, 5,0}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{ 5988, 5,0}, /* core2 elr_EL1 bit0 */
			{ 5989, 5,0}, /* core2 elr_EL1 bit1 */
			{ 5990, 5,0}, /* core2 elr_EL1 bit2 */
			{ 5991, 5,0}, /* core2 elr_EL1 bit3 */
			{ 5996, 5,0}, /* core2 elr_EL1 bit4 */
			{ 5997, 5,0}, /* core2 elr_EL1 bit5 */
			{ 5998, 5,0}, /* core2 elr_EL1 bit6 */
			{ 5999, 5,0}, /* core2 elr_EL1 bit7 */
			{ 6988, 5,0}, /* core2 elr_EL1 bit8 */
			{ 6989, 5,0}, /* core2 elr_EL1 bit9 */
			{ 6990, 5,0}, /* core2 elr_EL1 bit10 */
			{ 6991, 5,0}, /* core2 elr_EL1 bit11 */
			{ 7048, 5,0}, /* core2 elr_EL1 bit12 */
			{ 7049, 5,0}, /* core2 elr_EL1 bit13 */
			{ 7050, 5,0}, /* core2 elr_EL1 bit14 */
			{ 7051, 5,0}, /* core2 elr_EL1 bit15 */
			{ 6896, 5,0}, /* core2 elr_EL1 bit16 */
			{ 6897, 5,0}, /* core2 elr_EL1 bit17 */
			{ 6898, 5,0}, /* core2 elr_EL1 bit18 */
			{ 6899, 5,0}, /* core2 elr_EL1 bit19 */
			{ 6940, 5,0}, /* core2 elr_EL1 bit20 */
			{ 6941, 5,0}, /* core2 elr_EL1 bit21 */
			{ 6942, 5,0}, /* core2 elr_EL1 bit22 */
			{ 6943, 5,0}, /* core2 elr_EL1 bit23 */
			{ 6856, 5,0}, /* core2 elr_EL1 bit24 */
			{ 6857, 5,0}, /* core2 elr_EL1 bit25 */
			{ 6858, 5,0}, /* core2 elr_EL1 bit26 */
			{ 6859, 5,0}, /* core2 elr_EL1 bit27 */
			{ 7216, 5,0}, /* core2 elr_EL1 bit28 */
			{ 7217, 5,0}, /* core2 elr_EL1 bit29 */
			{ 7218, 5,0}, /* core2 elr_EL1 bit30 */
			{ 7219, 5,0}, /* core2 elr_EL1 bit31 */
			{ 8164, 5,0}, /* core2 elr_EL1 bit32 */
			{ 8165, 5,0}, /* core2 elr_EL1 bit33 */
			{ 8166, 5,0}, /* core2 elr_EL1 bit34 */
			{ 8167, 5,0}, /* core2 elr_EL1 bit35 */
			{ 7288, 5,0}, /* core2 elr_EL1 bit36 */
			{ 7289, 5,0}, /* core2 elr_EL1 bit37 */
			{ 7290, 5,0}, /* core2 elr_EL1 bit38 */
			{ 7291, 5,0}, /* core2 elr_EL1 bit39 */
			{ 7428, 5,0}, /* core2 elr_EL1 bit40 */
			{ 7429, 5,0}, /* core2 elr_EL1 bit41 */
			{ 7430, 5,0}, /* core2 elr_EL1 bit42 */
			{ 7431, 5,0}, /* core2 elr_EL1 bit43 */
			{ 7284, 5,0}, /* core2 elr_EL1 bit44 */
			{ 7285, 5,0}, /* core2 elr_EL1 bit45 */
			{ 7286, 5,0}, /* core2 elr_EL1 bit46 */
			{ 7287, 5,0}, /* core2 elr_EL1 bit47 */
			{ 7420, 5,0}, /* core2 elr_EL1 bit48 */
			{ 7421, 5,0}, /* core2 elr_EL1 bit49 */
			{ 7422, 5,0}, /* core2 elr_EL1 bit50 */
			{ 7423, 5,0}, /* core2 elr_EL1 bit51 */
			{ 7860, 5,0}, /* core2 elr_EL1 bit52 */
			{ 7861, 5,0}, /* core2 elr_EL1 bit53 */
			{ 7862, 5,0}, /* core2 elr_EL1 bit54 */
			{ 7863, 5,0}, /* core2 elr_EL1 bit55 */
			{ 7932, 5,0}, /* core2 elr_EL1 bit56 */
			{ 7933, 5,0}, /* core2 elr_EL1 bit57 */
			{ 7934, 5,0}, /* core2 elr_EL1 bit58 */
			{ 7935, 5,0}, /* core2 elr_EL1 bit59 */
			{ 8168, 5,0}, /* core2 elr_EL1 bit60 */
			{ 8169, 5,0}, /* core2 elr_EL1 bit61 */
			{ 8170, 5,0}, /* core2 elr_EL1 bit62 */
			{ 8171, 5,0}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 5992, 5,0}, /* core2 elr_EL2 bit0 */
			{ 5993, 5,0}, /* core2 elr_EL2 bit1 */
			{ 5994, 5,0}, /* core2 elr_EL2 bit2 */
			{ 5995, 5,0}, /* core2 elr_EL2 bit3 */
			{ 6152, 5,0}, /* core2 elr_EL2 bit4 */
			{ 6153, 5,0}, /* core2 elr_EL2 bit5 */
			{ 6154, 5,0}, /* core2 elr_EL2 bit6 */
			{ 6155, 5,0}, /* core2 elr_EL2 bit7 */
			{ 6416, 5,0}, /* core2 elr_EL2 bit8 */
			{ 6417, 5,0}, /* core2 elr_EL2 bit9 */
			{ 6418, 5,0}, /* core2 elr_EL2 bit10 */
			{ 6419, 5,0}, /* core2 elr_EL2 bit11 */
			{ 6924, 5,0}, /* core2 elr_EL2 bit12 */
			{ 6925, 5,0}, /* core2 elr_EL2 bit13 */
			{ 6926, 5,0}, /* core2 elr_EL2 bit14 */
			{ 6927, 5,0}, /* core2 elr_EL2 bit15 */
			{ 6916, 5,0}, /* core2 elr_EL2 bit16 */
			{ 6917, 5,0}, /* core2 elr_EL2 bit17 */
			{ 6918, 5,0}, /* core2 elr_EL2 bit18 */
			{ 6919, 5,0}, /* core2 elr_EL2 bit19 */
			{ 6952, 5,0}, /* core2 elr_EL2 bit20 */
			{ 6953, 5,0}, /* core2 elr_EL2 bit21 */
			{ 6954, 5,0}, /* core2 elr_EL2 bit22 */
			{ 6955, 5,0}, /* core2 elr_EL2 bit23 */
			{ 6904, 5,0}, /* core2 elr_EL2 bit24 */
			{ 6905, 5,0}, /* core2 elr_EL2 bit25 */
			{ 6906, 5,0}, /* core2 elr_EL2 bit26 */
			{ 6907, 5,0}, /* core2 elr_EL2 bit27 */
			{ 7224, 5,0}, /* core2 elr_EL2 bit28 */
			{ 7225, 5,0}, /* core2 elr_EL2 bit29 */
			{ 7226, 5,0}, /* core2 elr_EL2 bit30 */
			{ 7227, 5,0}, /* core2 elr_EL2 bit31 */
			{ 7912, 5,0}, /* core2 elr_EL2 bit32 */
			{ 7913, 5,0}, /* core2 elr_EL2 bit33 */
			{ 7914, 5,0}, /* core2 elr_EL2 bit34 */
			{ 7915, 5,0}, /* core2 elr_EL2 bit35 */
			{ 8300, 5,0}, /* core2 elr_EL2 bit36 */
			{ 8301, 5,0}, /* core2 elr_EL2 bit37 */
			{ 8302, 5,0}, /* core2 elr_EL2 bit38 */
			{ 8303, 5,0}, /* core2 elr_EL2 bit39 */
			{ 8264, 5,0}, /* core2 elr_EL2 bit40 */
			{ 8265, 5,0}, /* core2 elr_EL2 bit41 */
			{ 8266, 5,0}, /* core2 elr_EL2 bit42 */
			{ 8267, 5,0}, /* core2 elr_EL2 bit43 */
			{ 8268, 5,0}, /* core2 elr_EL2 bit44 */
			{ 8269, 5,0}, /* core2 elr_EL2 bit45 */
			{ 8270, 5,0}, /* core2 elr_EL2 bit46 */
			{ 8271, 5,0}, /* core2 elr_EL2 bit47 */
			{ 7456, 5,0}, /* core2 elr_EL2 bit48 */
			{ 7457, 5,0}, /* core2 elr_EL2 bit49 */
			{ 7458, 5,0}, /* core2 elr_EL2 bit50 */
			{ 7459, 5,0}, /* core2 elr_EL2 bit51 */
			{ 7464, 5,0}, /* core2 elr_EL2 bit52 */
			{ 7465, 5,0}, /* core2 elr_EL2 bit53 */
			{ 7466, 5,0}, /* core2 elr_EL2 bit54 */
			{ 7467, 5,0}, /* core2 elr_EL2 bit55 */
			{ 7888, 5,0}, /* core2 elr_EL2 bit56 */
			{ 7889, 5,0}, /* core2 elr_EL2 bit57 */
			{ 7890, 5,0}, /* core2 elr_EL2 bit58 */
			{ 7891, 5,0}, /* core2 elr_EL2 bit59 */
			{ 7936, 5,0}, /* core2 elr_EL2 bit60 */
			{ 7937, 5,0}, /* core2 elr_EL2 bit61 */
			{ 7938, 5,0}, /* core2 elr_EL2 bit62 */
			{ 7939, 5,0}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 6040, 5,0}, /* core2 elr_EL3 bit0 */
			{ 6041, 5,0}, /* core2 elr_EL3 bit1 */
			{ 6042, 5,0}, /* core2 elr_EL3 bit2 */
			{ 6043, 5,0}, /* core2 elr_EL3 bit3 */
			{ 7140, 5,0}, /* core2 elr_EL3 bit4 */
			{ 7141, 5,0}, /* core2 elr_EL3 bit5 */
			{ 7142, 5,0}, /* core2 elr_EL3 bit6 */
			{ 7143, 5,0}, /* core2 elr_EL3 bit7 */
			{ 7180, 5,0}, /* core2 elr_EL3 bit8 */
			{ 7181, 5,0}, /* core2 elr_EL3 bit9 */
			{ 7182, 5,0}, /* core2 elr_EL3 bit10 */
			{ 7183, 5,0}, /* core2 elr_EL3 bit11 */
			{ 7044, 5,0}, /* core2 elr_EL3 bit12 */
			{ 7045, 5,0}, /* core2 elr_EL3 bit13 */
			{ 7046, 5,0}, /* core2 elr_EL3 bit14 */
			{ 7047, 5,0}, /* core2 elr_EL3 bit15 */
			{ 6864, 5,0}, /* core2 elr_EL3 bit16 */
			{ 6865, 5,0}, /* core2 elr_EL3 bit17 */
			{ 6866, 5,0}, /* core2 elr_EL3 bit18 */
			{ 6867, 5,0}, /* core2 elr_EL3 bit19 */
			{ 7028, 5,0}, /* core2 elr_EL3 bit20 */
			{ 7029, 5,0}, /* core2 elr_EL3 bit21 */
			{ 7030, 5,0}, /* core2 elr_EL3 bit22 */
			{ 7031, 5,0}, /* core2 elr_EL3 bit23 */
			{ 6860, 5,0}, /* core2 elr_EL3 bit24 */
			{ 6861, 5,0}, /* core2 elr_EL3 bit25 */
			{ 6862, 5,0}, /* core2 elr_EL3 bit26 */
			{ 6863, 5,0}, /* core2 elr_EL3 bit27 */
			{ 7204, 5,0}, /* core2 elr_EL3 bit28 */
			{ 7205, 5,0}, /* core2 elr_EL3 bit29 */
			{ 7206, 5,0}, /* core2 elr_EL3 bit30 */
			{ 7207, 5,0}, /* core2 elr_EL3 bit31 */
			{ 8340, 5,0}, /* core2 elr_EL3 bit32 */
			{ 8341, 5,0}, /* core2 elr_EL3 bit33 */
			{ 8342, 5,0}, /* core2 elr_EL3 bit34 */
			{ 8343, 5,0}, /* core2 elr_EL3 bit35 */
			{ 8252, 5,0}, /* core2 elr_EL3 bit36 */
			{ 8253, 5,0}, /* core2 elr_EL3 bit37 */
			{ 8254, 5,0}, /* core2 elr_EL3 bit38 */
			{ 8255, 5,0}, /* core2 elr_EL3 bit39 */
			{ 7868, 5,0}, /* core2 elr_EL3 bit40 */
			{ 7869, 5,0}, /* core2 elr_EL3 bit41 */
			{ 7870, 5,0}, /* core2 elr_EL3 bit42 */
			{ 7871, 5,0}, /* core2 elr_EL3 bit43 */
			{ 7864, 5,0}, /* core2 elr_EL3 bit44 */
			{ 7865, 5,0}, /* core2 elr_EL3 bit45 */
			{ 7866, 5,0}, /* core2 elr_EL3 bit46 */
			{ 7867, 5,0}, /* core2 elr_EL3 bit47 */
			{ 7876, 5,0}, /* core2 elr_EL3 bit48 */
			{ 7877, 5,0}, /* core2 elr_EL3 bit49 */
			{ 7878, 5,0}, /* core2 elr_EL3 bit50 */
			{ 7879, 5,0}, /* core2 elr_EL3 bit51 */
			{ 8324, 5,0}, /* core2 elr_EL3 bit52 */
			{ 8325, 5,0}, /* core2 elr_EL3 bit53 */
			{ 8326, 5,0}, /* core2 elr_EL3 bit54 */
			{ 8327, 5,0}, /* core2 elr_EL3 bit55 */
			{ 7924, 5,0}, /* core2 elr_EL3 bit56 */
			{ 7925, 5,0}, /* core2 elr_EL3 bit57 */
			{ 7926, 5,0}, /* core2 elr_EL3 bit58 */
			{ 7927, 5,0}, /* core2 elr_EL3 bit59 */
			{ 7940, 5,0}, /* core2 elr_EL3 bit60 */
			{ 7941, 5,0}, /* core2 elr_EL3 bit61 */
			{ 7942, 5,0}, /* core2 elr_EL3 bit62 */
			{ 7943, 5,0}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 8448, 6,0}, /* core2 raw_pc bit0 */
			{10692, 5,0}, /* core2 raw_pc bit1 */
			{10693, 5,0}, /* core2 raw_pc bit2 */
			{ 9360, 5,0}, /* core2 raw_pc bit3 */
			{ 9361, 5,0}, /* core2 raw_pc bit4 */
			{ 9362, 5,0}, /* core2 raw_pc bit5 */
			{ 9363, 5,0}, /* core2 raw_pc bit6 */
			{12608, 5,0}, /* core2 raw_pc bit7 */
			{12609, 5,0}, /* core2 raw_pc bit8 */
			{12610, 5,0}, /* core2 raw_pc bit9 */
			{12611, 5,0}, /* core2 raw_pc bit10 */
			{12580, 5,0}, /* core2 raw_pc bit11 */
			{12581, 5,0}, /* core2 raw_pc bit12 */
			{12582, 5,0}, /* core2 raw_pc bit13 */
			{12583, 5,0}, /* core2 raw_pc bit14 */
			{12584, 5,0}, /* core2 raw_pc bit15 */
			{12585, 5,0}, /* core2 raw_pc bit16 */
			{12586, 5,0}, /* core2 raw_pc bit17 */
			{12587, 5,0}, /* core2 raw_pc bit18 */
			{12576, 5,0}, /* core2 raw_pc bit19 */
			{12577, 5,0}, /* core2 raw_pc bit20 */
			{12578, 5,0}, /* core2 raw_pc bit21 */
			{12579, 5,0}, /* core2 raw_pc bit22 */
			{ 9376, 5,0}, /* core2 raw_pc bit23 */
			{ 9377, 5,0}, /* core2 raw_pc bit24 */
			{ 9378, 5,0}, /* core2 raw_pc bit25 */
			{ 9379, 5,0}, /* core2 raw_pc bit26 */
			{ 9384, 5,0}, /* core2 raw_pc bit27 */
			{ 9385, 5,0}, /* core2 raw_pc bit28 */
			{ 9386, 5,0}, /* core2 raw_pc bit29 */
			{ 9387, 5,0}, /* core2 raw_pc bit30 */
			{14492, 5,0}, /* core2 raw_pc bit31 */
			{12620, 5,0}, /* core2 raw_pc bit32 */
			{12621, 5,0}, /* core2 raw_pc bit33 */
			{12622, 5,0}, /* core2 raw_pc bit34 */
			{12623, 5,0}, /* core2 raw_pc bit35 */
			{ 9408, 5,0}, /* core2 raw_pc bit36 */
			{ 9409, 5,0}, /* core2 raw_pc bit37 */
			{ 9410, 5,0}, /* core2 raw_pc bit38 */
			{ 9411, 5,0}, /* core2 raw_pc bit39 */
			{ 9396, 5,0}, /* core2 raw_pc bit40 */
			{ 9397, 5,0}, /* core2 raw_pc bit41 */
			{ 9398, 5,0}, /* core2 raw_pc bit42 */
			{ 9399, 5,0}, /* core2 raw_pc bit43 */
			{ 9392, 5,0}, /* core2 raw_pc bit44 */
			{ 9393, 5,0}, /* core2 raw_pc bit45 */
			{ 9394, 5,0}, /* core2 raw_pc bit46 */
			{ 9395, 5,0}, /* core2 raw_pc bit47 */
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
			{15238, 5,0}, /* core2 pc_iss bit0 */
			{15206, 5,0}, /* core2 pc_iss bit1 */
			{15235, 5,0}, /* core2 pc_iss bit2 */
			{15306, 5,0}, /* core2 pc_iss bit3 */
			{15203, 5,0}, /* core2 pc_iss bit4 */
			{15297, 5,0}, /* core2 pc_iss bit5 */
			{15207, 5,0}, /* core2 pc_iss bit6 */
			{15204, 5,0}, /* core2 pc_iss bit7 */
			{15208, 5,0}, /* core2 pc_iss bit8 */
			{15209, 5,0}, /* core2 pc_iss bit9 */
			{15211, 5,0}, /* core2 pc_iss bit10 */
			{15200, 5,0}, /* core2 pc_iss bit11 */
			{15215, 5,0}, /* core2 pc_iss bit12 */
			{15212, 5,0}, /* core2 pc_iss bit13 */
			{15188, 5,0}, /* core2 pc_iss bit14 */
			{15210, 5,0}, /* core2 pc_iss bit15 */
			{15217, 5,0}, /* core2 pc_iss bit16 */
			{15213, 5,0}, /* core2 pc_iss bit17 */
			{15214, 5,0}, /* core2 pc_iss bit18 */
			{15189, 5,0}, /* core2 pc_iss bit19 */
			{15187, 5,0}, /* core2 pc_iss bit20 */
			{15216, 5,0}, /* core2 pc_iss bit21 */
			{15196, 5,0}, /* core2 pc_iss bit22 */
			{15195, 5,0}, /* core2 pc_iss bit23 */
			{15186, 5,0}, /* core2 pc_iss bit24 */
			{15193, 5,0}, /* core2 pc_iss bit25 */
			{15194, 5,0}, /* core2 pc_iss bit26 */
			{15327, 5,0}, /* core2 pc_iss bit27 */
			{15333, 5,0}, /* core2 pc_iss bit28 */
			{15326, 5,0}, /* core2 pc_iss bit29 */
			{15191, 5,0}, /* core2 pc_iss bit30 */
			{15336, 5,0}, /* core2 pc_iss bit31 */
			{12440, 5,0}, /* core2 pc_iss bit32 */
			{12441, 5,0}, /* core2 pc_iss bit33 */
			{12442, 5,0}, /* core2 pc_iss bit34 */
			{12443, 5,0}, /* core2 pc_iss bit35 */
			{12436, 5,0}, /* core2 pc_iss bit36 */
			{12437, 5,0}, /* core2 pc_iss bit37 */
			{12438, 5,0}, /* core2 pc_iss bit38 */
			{12439, 5,0}, /* core2 pc_iss bit39 */
			{12516, 5,0}, /* core2 pc_iss bit40 */
			{12517, 5,0}, /* core2 pc_iss bit41 */
			{12518, 5,0}, /* core2 pc_iss bit42 */
			{12519, 5,0}, /* core2 pc_iss bit43 */
			{12512, 5,0}, /* core2 pc_iss bit44 */
			{12513, 5,0}, /* core2 pc_iss bit45 */
			{12514, 5,0}, /* core2 pc_iss bit46 */
			{12515, 5,0}, /* core2 pc_iss bit47 */
			{12636, 5,0}, /* core2 pc_iss bit48 */
			{12637, 5,0}, /* core2 pc_iss bit49 */
			{12638, 5,0}, /* core2 pc_iss bit50 */
			{12639, 5,0}, /* core2 pc_iss bit51 */
			{12632, 5,0}, /* core2 pc_iss bit52 */
			{12633, 5,0}, /* core2 pc_iss bit53 */
			{12634, 5,0}, /* core2 pc_iss bit54 */
			{12635, 5,0}, /* core2 pc_iss bit55 */
			{12640, 5,0}, /* core2 pc_iss bit56 */
			{12641, 5,0}, /* core2 pc_iss bit57 */
			{12642, 5,0}, /* core2 pc_iss bit58 */
			{12643, 5,0}, /* core2 pc_iss bit59 */
			{12644, 5,0}, /* core2 pc_iss bit60 */
			{12645, 5,0}, /* core2 pc_iss bit61 */
			{12646, 5,0}, /* core2 pc_iss bit62 */
			{12647, 5,0}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 8447, 6,0}, /* core2 full_pc_wr bit0 */
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
			{15304, 5,0}, /* core2 full_pc_ex1 bit0 */
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
			{ 8443, 6,0}, /* core2 full_pc_ex2 bit0 */
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
	},
	{		/* core 3 */ 
			.pc = {{
			{ 6231, 7,0}, /* core3 pc bit0 */
			{ 6232, 7,0}, /* core3 pc bit1 */
			{ 6233, 7,0}, /* core3 pc bit2 */
			{ 6234, 7,0}, /* core3 pc bit3 */
			{ 6296, 7,0}, /* core3 pc bit4 */
			{ 6297, 7,0}, /* core3 pc bit5 */
			{ 6298, 7,0}, /* core3 pc bit6 */
			{ 6299, 7,0}, /* core3 pc bit7 */
			{ 6340, 7,0}, /* core3 pc bit8 */
			{ 6341, 7,0}, /* core3 pc bit9 */
			{ 6342, 7,0}, /* core3 pc bit10 */
			{ 6343, 7,0}, /* core3 pc bit11 */
			{ 6480, 7,0}, /* core3 pc bit12 */
			{ 6481, 7,0}, /* core3 pc bit13 */
			{ 6482, 7,0}, /* core3 pc bit14 */
			{ 6483, 7,0}, /* core3 pc bit15 */
			{ 6692, 7,0}, /* core3 pc bit16 */
			{ 6693, 7,0}, /* core3 pc bit17 */
			{ 6694, 7,0}, /* core3 pc bit18 */
			{ 6695, 7,0}, /* core3 pc bit19 */
			{ 6352, 7,0}, /* core3 pc bit20 */
			{ 6353, 7,0}, /* core3 pc bit21 */
			{ 6354, 7,0}, /* core3 pc bit22 */
			{ 6355, 7,0}, /* core3 pc bit23 */
			{ 6696, 7,0}, /* core3 pc bit24 */
			{ 6697, 7,0}, /* core3 pc bit25 */
			{ 6698, 7,0}, /* core3 pc bit26 */
			{ 6699, 7,0}, /* core3 pc bit27 */
			{ 6328, 7,0}, /* core3 pc bit28 */
			{ 6329, 7,0}, /* core3 pc bit29 */
			{ 6330, 7,0}, /* core3 pc bit30 */
			{ 6331, 7,0}, /* core3 pc bit31 */
			{13288, 7,0}, /* core3 pc bit32 */
			{13289, 7,0}, /* core3 pc bit33 */
			{13290, 7,0}, /* core3 pc bit34 */
			{13291, 7,0}, /* core3 pc bit35 */
			{13280, 7,0}, /* core3 pc bit36 */
			{13281, 7,0}, /* core3 pc bit37 */
			{13282, 7,0}, /* core3 pc bit38 */
			{13283, 7,0}, /* core3 pc bit39 */
			{13268, 7,0}, /* core3 pc bit40 */
			{13269, 7,0}, /* core3 pc bit41 */
			{13270, 7,0}, /* core3 pc bit42 */
			{13271, 7,0}, /* core3 pc bit43 */
			{13284, 7,0}, /* core3 pc bit44 */
			{13285, 7,0}, /* core3 pc bit45 */
			{13286, 7,0}, /* core3 pc bit46 */
			{13287, 7,0}, /* core3 pc bit47 */
			{13264, 7,0}, /* core3 pc bit48 */
			{13265, 7,0}, /* core3 pc bit49 */
			{13266, 7,0}, /* core3 pc bit50 */
			{13267, 7,0}, /* core3 pc bit51 */
			{13272, 7,0}, /* core3 pc bit52 */
			{13273, 7,0}, /* core3 pc bit53 */
			{13274, 7,0}, /* core3 pc bit54 */
			{13275, 7,0}, /* core3 pc bit55 */
			{13292, 7,0}, /* core3 pc bit56 */
			{13293, 7,0}, /* core3 pc bit57 */
			{13294, 7,0}, /* core3 pc bit58 */
			{13295, 7,0}, /* core3 pc bit59 */
			{13276, 7,0}, /* core3 pc bit60 */
			{13277, 7,0}, /* core3 pc bit61 */
			{13278, 7,0}, /* core3 pc bit62 */
			{13279, 7,0}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{ 6012, 7,0}, /* core3 sp32 bit0 */
			{ 6013, 7,0}, /* core3 sp32 bit1 */
			{ 6014, 7,0}, /* core3 sp32 bit2 */
			{ 6015, 7,0}, /* core3 sp32 bit3 */
			{ 6188, 7,0}, /* core3 sp32 bit4 */
			{ 6189, 7,0}, /* core3 sp32 bit5 */
			{ 6190, 7,0}, /* core3 sp32 bit6 */
			{ 6191, 7,0}, /* core3 sp32 bit7 */
			{ 6992, 7,0}, /* core3 sp32 bit8 */
			{ 6993, 7,0}, /* core3 sp32 bit9 */
			{ 6994, 7,0}, /* core3 sp32 bit10 */
			{ 6995, 7,0}, /* core3 sp32 bit11 */
			{ 6872, 7,0}, /* core3 sp32 bit12 */
			{ 6873, 7,0}, /* core3 sp32 bit13 */
			{ 6874, 7,0}, /* core3 sp32 bit14 */
			{ 6875, 7,0}, /* core3 sp32 bit15 */
			{ 6884, 7,0}, /* core3 sp32 bit16 */
			{ 6885, 7,0}, /* core3 sp32 bit17 */
			{ 6886, 7,0}, /* core3 sp32 bit18 */
			{ 6887, 7,0}, /* core3 sp32 bit19 */
			{ 6944, 7,0}, /* core3 sp32 bit20 */
			{ 6945, 7,0}, /* core3 sp32 bit21 */
			{ 6946, 7,0}, /* core3 sp32 bit22 */
			{ 6947, 7,0}, /* core3 sp32 bit23 */
			{ 6880, 7,0}, /* core3 sp32 bit24 */
			{ 6881, 7,0}, /* core3 sp32 bit25 */
			{ 6882, 7,0}, /* core3 sp32 bit26 */
			{ 6883, 7,0}, /* core3 sp32 bit27 */
			{ 6980, 7,0}, /* core3 sp32 bit28 */
			{ 6981, 7,0}, /* core3 sp32 bit29 */
			{ 6982, 7,0}, /* core3 sp32 bit30 */
			{ 6983, 7,0}, /* core3 sp32 bit31 */
			{11004, 7,0}, /* core3 sp32 bit32 */
			{11005, 7,0}, /* core3 sp32 bit33 */
			{11006, 7,0}, /* core3 sp32 bit34 */
			{11007, 7,0}, /* core3 sp32 bit35 */
			{ 2324, 8,0}, /* core3 sp32 bit36 */
			{ 2325, 8,0}, /* core3 sp32 bit37 */
			{ 2326, 8,0}, /* core3 sp32 bit38 */
			{ 2327, 8,0}, /* core3 sp32 bit39 */
			{ 2316, 8,0}, /* core3 sp32 bit40 */
			{ 2317, 8,0}, /* core3 sp32 bit41 */
			{ 2318, 8,0}, /* core3 sp32 bit42 */
			{ 2319, 8,0}, /* core3 sp32 bit43 */
			{ 2312, 8,0}, /* core3 sp32 bit44 */
			{ 2313, 8,0}, /* core3 sp32 bit45 */
			{ 2314, 8,0}, /* core3 sp32 bit46 */
			{ 2315, 8,0}, /* core3 sp32 bit47 */
			{ 2308, 8,0}, /* core3 sp32 bit48 */
			{ 2309, 8,0}, /* core3 sp32 bit49 */
			{ 2310, 8,0}, /* core3 sp32 bit50 */
			{ 2311, 8,0}, /* core3 sp32 bit51 */
			{11072, 7,0}, /* core3 sp32 bit52 */
			{11073, 7,0}, /* core3 sp32 bit53 */
			{11074, 7,0}, /* core3 sp32 bit54 */
			{11075, 7,0}, /* core3 sp32 bit55 */
			{11036, 7,0}, /* core3 sp32 bit56 */
			{11037, 7,0}, /* core3 sp32 bit57 */
			{11038, 7,0}, /* core3 sp32 bit58 */
			{11039, 7,0}, /* core3 sp32 bit59 */
			{11024, 7,0}, /* core3 sp32 bit60 */
			{11025, 7,0}, /* core3 sp32 bit61 */
			{11026, 7,0}, /* core3 sp32 bit62 */
			{11027, 7,0}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7136, 7,0}, /* core3 fp32 bit0 */
			{ 7137, 7,0}, /* core3 fp32 bit1 */
			{ 7138, 7,0}, /* core3 fp32 bit2 */
			{ 7139, 7,0}, /* core3 fp32 bit3 */
			{ 7152, 7,0}, /* core3 fp32 bit4 */
			{ 7153, 7,0}, /* core3 fp32 bit5 */
			{ 7154, 7,0}, /* core3 fp32 bit6 */
			{ 7155, 7,0}, /* core3 fp32 bit7 */
			{   32, 7,0}, /* core3 fp32 bit8 */
			{   33, 7,0}, /* core3 fp32 bit9 */
			{   34, 7,0}, /* core3 fp32 bit10 */
			{   35, 7,0}, /* core3 fp32 bit11 */
			{ 8444, 7,0}, /* core3 fp32 bit12 */
			{ 8445, 7,0}, /* core3 fp32 bit13 */
			{ 8446, 7,0}, /* core3 fp32 bit14 */
			{ 8447, 7,0}, /* core3 fp32 bit15 */
			{ 8440, 7,0}, /* core3 fp32 bit16 */
			{ 8441, 7,0}, /* core3 fp32 bit17 */
			{ 8442, 7,0}, /* core3 fp32 bit18 */
			{ 8443, 7,0}, /* core3 fp32 bit19 */
			{ 7080, 7,0}, /* core3 fp32 bit20 */
			{ 7081, 7,0}, /* core3 fp32 bit21 */
			{ 7082, 7,0}, /* core3 fp32 bit22 */
			{ 7083, 7,0}, /* core3 fp32 bit23 */
			{ 8424, 7,0}, /* core3 fp32 bit24 */
			{ 8425, 7,0}, /* core3 fp32 bit25 */
			{ 8426, 7,0}, /* core3 fp32 bit26 */
			{ 8427, 7,0}, /* core3 fp32 bit27 */
			{ 8216, 7,0}, /* core3 fp32 bit28 */
			{ 8217, 7,0}, /* core3 fp32 bit29 */
			{ 8218, 7,0}, /* core3 fp32 bit30 */
			{ 8219, 7,0}, /* core3 fp32 bit31 */
			{ 7516, 7,0}, /* core3 fp32 bit32 */
			{ 7517, 7,0}, /* core3 fp32 bit33 */
			{ 7518, 7,0}, /* core3 fp32 bit34 */
			{ 7519, 7,0}, /* core3 fp32 bit35 */
			{ 7592, 7,0}, /* core3 fp32 bit36 */
			{ 7593, 7,0}, /* core3 fp32 bit37 */
			{ 7594, 7,0}, /* core3 fp32 bit38 */
			{ 7595, 7,0}, /* core3 fp32 bit39 */
			{ 7484, 7,0}, /* core3 fp32 bit40 */
			{ 7485, 7,0}, /* core3 fp32 bit41 */
			{ 7486, 7,0}, /* core3 fp32 bit42 */
			{ 7487, 7,0}, /* core3 fp32 bit43 */
			{ 7476, 7,0}, /* core3 fp32 bit44 */
			{ 7477, 7,0}, /* core3 fp32 bit45 */
			{ 7478, 7,0}, /* core3 fp32 bit46 */
			{ 7479, 7,0}, /* core3 fp32 bit47 */
			{ 7480, 7,0}, /* core3 fp32 bit48 */
			{ 7481, 7,0}, /* core3 fp32 bit49 */
			{ 7482, 7,0}, /* core3 fp32 bit50 */
			{ 7483, 7,0}, /* core3 fp32 bit51 */
			{ 8128, 7,0}, /* core3 fp32 bit52 */
			{ 8129, 7,0}, /* core3 fp32 bit53 */
			{ 8130, 7,0}, /* core3 fp32 bit54 */
			{ 8131, 7,0}, /* core3 fp32 bit55 */
			{ 8132, 7,0}, /* core3 fp32 bit56 */
			{ 8133, 7,0}, /* core3 fp32 bit57 */
			{ 8134, 7,0}, /* core3 fp32 bit58 */
			{ 8135, 7,0}, /* core3 fp32 bit59 */
			{ 7616, 7,0}, /* core3 fp32 bit60 */
			{ 7617, 7,0}, /* core3 fp32 bit61 */
			{ 7618, 7,0}, /* core3 fp32 bit62 */
			{ 7619, 7,0}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{ 6211, 7,0}, /* core3 fp64 bit0 */
			{ 6212, 7,0}, /* core3 fp64 bit1 */
			{ 6213, 7,0}, /* core3 fp64 bit2 */
			{ 6214, 7,0}, /* core3 fp64 bit3 */
			{ 6276, 7,0}, /* core3 fp64 bit4 */
			{ 6277, 7,0}, /* core3 fp64 bit5 */
			{ 6278, 7,0}, /* core3 fp64 bit6 */
			{ 6279, 7,0}, /* core3 fp64 bit7 */
			{ 6376, 7,0}, /* core3 fp64 bit8 */
			{ 6377, 7,0}, /* core3 fp64 bit9 */
			{ 6378, 7,0}, /* core3 fp64 bit10 */
			{ 6379, 7,0}, /* core3 fp64 bit11 */
			{ 6476, 7,0}, /* core3 fp64 bit12 */
			{ 6477, 7,0}, /* core3 fp64 bit13 */
			{ 6478, 7,0}, /* core3 fp64 bit14 */
			{ 6479, 7,0}, /* core3 fp64 bit15 */
			{ 6684, 7,0}, /* core3 fp64 bit16 */
			{ 6685, 7,0}, /* core3 fp64 bit17 */
			{ 6686, 7,0}, /* core3 fp64 bit18 */
			{ 6687, 7,0}, /* core3 fp64 bit19 */
			{ 6356, 7,0}, /* core3 fp64 bit20 */
			{ 6357, 7,0}, /* core3 fp64 bit21 */
			{ 6358, 7,0}, /* core3 fp64 bit22 */
			{ 6359, 7,0}, /* core3 fp64 bit23 */
			{ 6688, 7,0}, /* core3 fp64 bit24 */
			{ 6689, 7,0}, /* core3 fp64 bit25 */
			{ 6690, 7,0}, /* core3 fp64 bit26 */
			{ 6691, 7,0}, /* core3 fp64 bit27 */
			{ 6392, 7,0}, /* core3 fp64 bit28 */
			{ 6393, 7,0}, /* core3 fp64 bit29 */
			{ 6394, 7,0}, /* core3 fp64 bit30 */
			{ 6395, 7,0}, /* core3 fp64 bit31 */
			{ 7908, 7,0}, /* core3 fp64 bit32 */
			{ 7909, 7,0}, /* core3 fp64 bit33 */
			{ 7910, 7,0}, /* core3 fp64 bit34 */
			{ 7911, 7,0}, /* core3 fp64 bit35 */
			{ 8260, 7,0}, /* core3 fp64 bit36 */
			{ 8261, 7,0}, /* core3 fp64 bit37 */
			{ 8262, 7,0}, /* core3 fp64 bit38 */
			{ 8263, 7,0}, /* core3 fp64 bit39 */
			{ 8272, 7,0}, /* core3 fp64 bit40 */
			{ 8273, 7,0}, /* core3 fp64 bit41 */
			{ 8274, 7,0}, /* core3 fp64 bit42 */
			{ 8275, 7,0}, /* core3 fp64 bit43 */
			{ 8276, 7,0}, /* core3 fp64 bit44 */
			{ 8277, 7,0}, /* core3 fp64 bit45 */
			{ 8278, 7,0}, /* core3 fp64 bit46 */
			{ 8279, 7,0}, /* core3 fp64 bit47 */
			{ 8312, 7,0}, /* core3 fp64 bit48 */
			{ 8313, 7,0}, /* core3 fp64 bit49 */
			{ 8314, 7,0}, /* core3 fp64 bit50 */
			{ 8315, 7,0}, /* core3 fp64 bit51 */
			{ 8320, 7,0}, /* core3 fp64 bit52 */
			{ 8321, 7,0}, /* core3 fp64 bit53 */
			{ 8322, 7,0}, /* core3 fp64 bit54 */
			{ 8323, 7,0}, /* core3 fp64 bit55 */
			{ 7900, 7,0}, /* core3 fp64 bit56 */
			{ 7901, 7,0}, /* core3 fp64 bit57 */
			{ 7902, 7,0}, /* core3 fp64 bit58 */
			{ 7903, 7,0}, /* core3 fp64 bit59 */
			{ 7968, 7,0}, /* core3 fp64 bit60 */
			{ 7969, 7,0}, /* core3 fp64 bit61 */
			{ 7970, 7,0}, /* core3 fp64 bit62 */
			{ 7971, 7,0}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 6132, 7,0}, /* core3 sp_EL0 bit0 */
			{ 6133, 7,0}, /* core3 sp_EL0 bit1 */
			{ 6134, 7,0}, /* core3 sp_EL0 bit2 */
			{ 6135, 7,0}, /* core3 sp_EL0 bit3 */
			{ 6260, 7,0}, /* core3 sp_EL0 bit4 */
			{ 6261, 7,0}, /* core3 sp_EL0 bit5 */
			{ 6262, 7,0}, /* core3 sp_EL0 bit6 */
			{ 6263, 7,0}, /* core3 sp_EL0 bit7 */
			{ 6236, 7,0}, /* core3 sp_EL0 bit8 */
			{ 6237, 7,0}, /* core3 sp_EL0 bit9 */
			{ 6238, 7,0}, /* core3 sp_EL0 bit10 */
			{ 6239, 7,0}, /* core3 sp_EL0 bit11 */
			{ 6452, 7,0}, /* core3 sp_EL0 bit12 */
			{ 6453, 7,0}, /* core3 sp_EL0 bit13 */
			{ 6454, 7,0}, /* core3 sp_EL0 bit14 */
			{ 6455, 7,0}, /* core3 sp_EL0 bit15 */
			{ 6740, 7,0}, /* core3 sp_EL0 bit16 */
			{ 6741, 7,0}, /* core3 sp_EL0 bit17 */
			{ 6742, 7,0}, /* core3 sp_EL0 bit18 */
			{ 6743, 7,0}, /* core3 sp_EL0 bit19 */
			{ 6432, 7,0}, /* core3 sp_EL0 bit20 */
			{ 6433, 7,0}, /* core3 sp_EL0 bit21 */
			{ 6434, 7,0}, /* core3 sp_EL0 bit22 */
			{ 6435, 7,0}, /* core3 sp_EL0 bit23 */
			{ 6736, 7,0}, /* core3 sp_EL0 bit24 */
			{ 6737, 7,0}, /* core3 sp_EL0 bit25 */
			{ 6738, 7,0}, /* core3 sp_EL0 bit26 */
			{ 6739, 7,0}, /* core3 sp_EL0 bit27 */
			{ 6408, 7,0}, /* core3 sp_EL0 bit28 */
			{ 6409, 7,0}, /* core3 sp_EL0 bit29 */
			{ 6410, 7,0}, /* core3 sp_EL0 bit30 */
			{ 6411, 7,0}, /* core3 sp_EL0 bit31 */
			{ 7916, 7,0}, /* core3 sp_EL0 bit32 */
			{ 7917, 7,0}, /* core3 sp_EL0 bit33 */
			{ 7918, 7,0}, /* core3 sp_EL0 bit34 */
			{ 7919, 7,0}, /* core3 sp_EL0 bit35 */
			{  153, 7,0}, /* core3 sp_EL0 bit36 */
			{  154, 7,0}, /* core3 sp_EL0 bit37 */
			{  155, 7,0}, /* core3 sp_EL0 bit38 */
			{  156, 7,0}, /* core3 sp_EL0 bit39 */
			{  161, 7,0}, /* core3 sp_EL0 bit40 */
			{  162, 7,0}, /* core3 sp_EL0 bit41 */
			{  163, 7,0}, /* core3 sp_EL0 bit42 */
			{  164, 7,0}, /* core3 sp_EL0 bit43 */
			{  165, 7,0}, /* core3 sp_EL0 bit44 */
			{  166, 7,0}, /* core3 sp_EL0 bit45 */
			{  167, 7,0}, /* core3 sp_EL0 bit46 */
			{  168, 7,0}, /* core3 sp_EL0 bit47 */
			{ 7440, 7,0}, /* core3 sp_EL0 bit48 */
			{ 7441, 7,0}, /* core3 sp_EL0 bit49 */
			{ 7442, 7,0}, /* core3 sp_EL0 bit50 */
			{ 7443, 7,0}, /* core3 sp_EL0 bit51 */
			{ 7468, 7,0}, /* core3 sp_EL0 bit52 */
			{ 7469, 7,0}, /* core3 sp_EL0 bit53 */
			{ 7470, 7,0}, /* core3 sp_EL0 bit54 */
			{ 7471, 7,0}, /* core3 sp_EL0 bit55 */
			{ 7892, 7,0}, /* core3 sp_EL0 bit56 */
			{ 7893, 7,0}, /* core3 sp_EL0 bit57 */
			{ 7894, 7,0}, /* core3 sp_EL0 bit58 */
			{ 7895, 7,0}, /* core3 sp_EL0 bit59 */
			{ 7948, 7,0}, /* core3 sp_EL0 bit60 */
			{ 7949, 7,0}, /* core3 sp_EL0 bit61 */
			{ 7950, 7,0}, /* core3 sp_EL0 bit62 */
			{ 7951, 7,0}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6215, 7,0}, /* core3 sp_EL1 bit0 */
			{ 6216, 7,0}, /* core3 sp_EL1 bit1 */
			{ 6217, 7,0}, /* core3 sp_EL1 bit2 */
			{ 6218, 7,0}, /* core3 sp_EL1 bit3 */
			{ 6272, 7,0}, /* core3 sp_EL1 bit4 */
			{ 6273, 7,0}, /* core3 sp_EL1 bit5 */
			{ 6274, 7,0}, /* core3 sp_EL1 bit6 */
			{ 6275, 7,0}, /* core3 sp_EL1 bit7 */
			{ 6380, 7,0}, /* core3 sp_EL1 bit8 */
			{ 6381, 7,0}, /* core3 sp_EL1 bit9 */
			{ 6382, 7,0}, /* core3 sp_EL1 bit10 */
			{ 6383, 7,0}, /* core3 sp_EL1 bit11 */
			{ 6472, 7,0}, /* core3 sp_EL1 bit12 */
			{ 6473, 7,0}, /* core3 sp_EL1 bit13 */
			{ 6474, 7,0}, /* core3 sp_EL1 bit14 */
			{ 6475, 7,0}, /* core3 sp_EL1 bit15 */
			{ 6648, 7,0}, /* core3 sp_EL1 bit16 */
			{ 6649, 7,0}, /* core3 sp_EL1 bit17 */
			{ 6650, 7,0}, /* core3 sp_EL1 bit18 */
			{ 6651, 7,0}, /* core3 sp_EL1 bit19 */
			{ 6976, 7,0}, /* core3 sp_EL1 bit20 */
			{ 6977, 7,0}, /* core3 sp_EL1 bit21 */
			{ 6978, 7,0}, /* core3 sp_EL1 bit22 */
			{ 6979, 7,0}, /* core3 sp_EL1 bit23 */
			{ 6652, 7,0}, /* core3 sp_EL1 bit24 */
			{ 6653, 7,0}, /* core3 sp_EL1 bit25 */
			{ 6654, 7,0}, /* core3 sp_EL1 bit26 */
			{ 6655, 7,0}, /* core3 sp_EL1 bit27 */
			{ 6388, 7,0}, /* core3 sp_EL1 bit28 */
			{ 6389, 7,0}, /* core3 sp_EL1 bit29 */
			{ 6390, 7,0}, /* core3 sp_EL1 bit30 */
			{ 6391, 7,0}, /* core3 sp_EL1 bit31 */
			{ 7904, 7,0}, /* core3 sp_EL1 bit32 */
			{ 7905, 7,0}, /* core3 sp_EL1 bit33 */
			{ 7906, 7,0}, /* core3 sp_EL1 bit34 */
			{ 7907, 7,0}, /* core3 sp_EL1 bit35 */
			{ 8304, 7,0}, /* core3 sp_EL1 bit36 */
			{ 8305, 7,0}, /* core3 sp_EL1 bit37 */
			{ 8306, 7,0}, /* core3 sp_EL1 bit38 */
			{ 8307, 7,0}, /* core3 sp_EL1 bit39 */
			{ 8296, 7,0}, /* core3 sp_EL1 bit40 */
			{ 8297, 7,0}, /* core3 sp_EL1 bit41 */
			{ 8298, 7,0}, /* core3 sp_EL1 bit42 */
			{ 8299, 7,0}, /* core3 sp_EL1 bit43 */
			{ 8292, 7,0}, /* core3 sp_EL1 bit44 */
			{ 8293, 7,0}, /* core3 sp_EL1 bit45 */
			{ 8294, 7,0}, /* core3 sp_EL1 bit46 */
			{ 8295, 7,0}, /* core3 sp_EL1 bit47 */
			{ 8308, 7,0}, /* core3 sp_EL1 bit48 */
			{ 8309, 7,0}, /* core3 sp_EL1 bit49 */
			{ 8310, 7,0}, /* core3 sp_EL1 bit50 */
			{ 8311, 7,0}, /* core3 sp_EL1 bit51 */
			{ 8328, 7,0}, /* core3 sp_EL1 bit52 */
			{ 8329, 7,0}, /* core3 sp_EL1 bit53 */
			{ 8330, 7,0}, /* core3 sp_EL1 bit54 */
			{ 8331, 7,0}, /* core3 sp_EL1 bit55 */
			{ 8336, 7,0}, /* core3 sp_EL1 bit56 */
			{ 8337, 7,0}, /* core3 sp_EL1 bit57 */
			{ 8338, 7,0}, /* core3 sp_EL1 bit58 */
			{ 8339, 7,0}, /* core3 sp_EL1 bit59 */
			{ 7964, 7,0}, /* core3 sp_EL1 bit60 */
			{ 7965, 7,0}, /* core3 sp_EL1 bit61 */
			{ 7966, 7,0}, /* core3 sp_EL1 bit62 */
			{ 7967, 7,0}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 6120, 7,0}, /* core3 sp_EL2 bit0 */
			{ 6121, 7,0}, /* core3 sp_EL2 bit1 */
			{ 6122, 7,0}, /* core3 sp_EL2 bit2 */
			{ 6123, 7,0}, /* core3 sp_EL2 bit3 */
			{ 6148, 7,0}, /* core3 sp_EL2 bit4 */
			{ 6149, 7,0}, /* core3 sp_EL2 bit5 */
			{ 6150, 7,0}, /* core3 sp_EL2 bit6 */
			{ 6151, 7,0}, /* core3 sp_EL2 bit7 */
			{ 6960, 7,0}, /* core3 sp_EL2 bit8 */
			{ 6961, 7,0}, /* core3 sp_EL2 bit9 */
			{ 6962, 7,0}, /* core3 sp_EL2 bit10 */
			{ 6963, 7,0}, /* core3 sp_EL2 bit11 */
			{ 6444, 7,0}, /* core3 sp_EL2 bit12 */
			{ 6445, 7,0}, /* core3 sp_EL2 bit13 */
			{ 6446, 7,0}, /* core3 sp_EL2 bit14 */
			{ 6447, 7,0}, /* core3 sp_EL2 bit15 */
			{ 6912, 7,0}, /* core3 sp_EL2 bit16 */
			{ 6913, 7,0}, /* core3 sp_EL2 bit17 */
			{ 6914, 7,0}, /* core3 sp_EL2 bit18 */
			{ 6915, 7,0}, /* core3 sp_EL2 bit19 */
			{ 6956, 7,0}, /* core3 sp_EL2 bit20 */
			{ 6957, 7,0}, /* core3 sp_EL2 bit21 */
			{ 6958, 7,0}, /* core3 sp_EL2 bit22 */
			{ 6959, 7,0}, /* core3 sp_EL2 bit23 */
			{ 6908, 7,0}, /* core3 sp_EL2 bit24 */
			{ 6909, 7,0}, /* core3 sp_EL2 bit25 */
			{ 6910, 7,0}, /* core3 sp_EL2 bit26 */
			{ 6911, 7,0}, /* core3 sp_EL2 bit27 */
			{ 6168, 7,0}, /* core3 sp_EL2 bit28 */
			{ 6169, 7,0}, /* core3 sp_EL2 bit29 */
			{ 6170, 7,0}, /* core3 sp_EL2 bit30 */
			{ 6171, 7,0}, /* core3 sp_EL2 bit31 */
			{ 7960, 7,0}, /* core3 sp_EL2 bit32 */
			{ 7961, 7,0}, /* core3 sp_EL2 bit33 */
			{ 7962, 7,0}, /* core3 sp_EL2 bit34 */
			{ 7963, 7,0}, /* core3 sp_EL2 bit35 */
			{  141, 7,0}, /* core3 sp_EL2 bit36 */
			{  142, 7,0}, /* core3 sp_EL2 bit37 */
			{  143, 7,0}, /* core3 sp_EL2 bit38 */
			{  144, 7,0}, /* core3 sp_EL2 bit39 */
			{  149, 7,0}, /* core3 sp_EL2 bit40 */
			{  150, 7,0}, /* core3 sp_EL2 bit41 */
			{  151, 7,0}, /* core3 sp_EL2 bit42 */
			{  152, 7,0}, /* core3 sp_EL2 bit43 */
			{  145, 7,0}, /* core3 sp_EL2 bit44 */
			{  146, 7,0}, /* core3 sp_EL2 bit45 */
			{  147, 7,0}, /* core3 sp_EL2 bit46 */
			{  148, 7,0}, /* core3 sp_EL2 bit47 */
			{ 7880, 7,0}, /* core3 sp_EL2 bit48 */
			{ 7881, 7,0}, /* core3 sp_EL2 bit49 */
			{ 7882, 7,0}, /* core3 sp_EL2 bit50 */
			{ 7883, 7,0}, /* core3 sp_EL2 bit51 */
			{ 8332, 7,0}, /* core3 sp_EL2 bit52 */
			{ 8333, 7,0}, /* core3 sp_EL2 bit53 */
			{ 8334, 7,0}, /* core3 sp_EL2 bit54 */
			{ 8335, 7,0}, /* core3 sp_EL2 bit55 */
			{ 7896, 7,0}, /* core3 sp_EL2 bit56 */
			{ 7897, 7,0}, /* core3 sp_EL2 bit57 */
			{ 7898, 7,0}, /* core3 sp_EL2 bit58 */
			{ 7899, 7,0}, /* core3 sp_EL2 bit59 */
			{ 7956, 7,0}, /* core3 sp_EL2 bit60 */
			{ 7957, 7,0}, /* core3 sp_EL2 bit61 */
			{ 7958, 7,0}, /* core3 sp_EL2 bit62 */
			{ 7959, 7,0}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6004, 7,0}, /* core3 sp_EL3 bit0 */
			{ 6005, 7,0}, /* core3 sp_EL3 bit1 */
			{ 6006, 7,0}, /* core3 sp_EL3 bit2 */
			{ 6007, 7,0}, /* core3 sp_EL3 bit3 */
			{ 6000, 7,0}, /* core3 sp_EL3 bit4 */
			{ 6001, 7,0}, /* core3 sp_EL3 bit5 */
			{ 6002, 7,0}, /* core3 sp_EL3 bit6 */
			{ 6003, 7,0}, /* core3 sp_EL3 bit7 */
			{ 6984, 7,0}, /* core3 sp_EL3 bit8 */
			{ 6985, 7,0}, /* core3 sp_EL3 bit9 */
			{ 6986, 7,0}, /* core3 sp_EL3 bit10 */
			{ 6987, 7,0}, /* core3 sp_EL3 bit11 */
			{ 7040, 7,0}, /* core3 sp_EL3 bit12 */
			{ 7041, 7,0}, /* core3 sp_EL3 bit13 */
			{ 7042, 7,0}, /* core3 sp_EL3 bit14 */
			{ 7043, 7,0}, /* core3 sp_EL3 bit15 */
			{ 6888, 7,0}, /* core3 sp_EL3 bit16 */
			{ 6889, 7,0}, /* core3 sp_EL3 bit17 */
			{ 6890, 7,0}, /* core3 sp_EL3 bit18 */
			{ 6891, 7,0}, /* core3 sp_EL3 bit19 */
			{ 7024, 7,0}, /* core3 sp_EL3 bit20 */
			{ 7025, 7,0}, /* core3 sp_EL3 bit21 */
			{ 7026, 7,0}, /* core3 sp_EL3 bit22 */
			{ 7027, 7,0}, /* core3 sp_EL3 bit23 */
			{ 6852, 7,0}, /* core3 sp_EL3 bit24 */
			{ 6853, 7,0}, /* core3 sp_EL3 bit25 */
			{ 6854, 7,0}, /* core3 sp_EL3 bit26 */
			{ 6855, 7,0}, /* core3 sp_EL3 bit27 */
			{ 7220, 7,0}, /* core3 sp_EL3 bit28 */
			{ 7221, 7,0}, /* core3 sp_EL3 bit29 */
			{ 7222, 7,0}, /* core3 sp_EL3 bit30 */
			{ 7223, 7,0}, /* core3 sp_EL3 bit31 */
			{ 8344, 7,0}, /* core3 sp_EL3 bit32 */
			{ 8345, 7,0}, /* core3 sp_EL3 bit33 */
			{ 8346, 7,0}, /* core3 sp_EL3 bit34 */
			{ 8347, 7,0}, /* core3 sp_EL3 bit35 */
			{ 7448, 7,0}, /* core3 sp_EL3 bit36 */
			{ 7449, 7,0}, /* core3 sp_EL3 bit37 */
			{ 7450, 7,0}, /* core3 sp_EL3 bit38 */
			{ 7451, 7,0}, /* core3 sp_EL3 bit39 */
			{ 7872, 7,0}, /* core3 sp_EL3 bit40 */
			{ 7873, 7,0}, /* core3 sp_EL3 bit41 */
			{ 7874, 7,0}, /* core3 sp_EL3 bit42 */
			{ 7875, 7,0}, /* core3 sp_EL3 bit43 */
			{ 7444, 7,0}, /* core3 sp_EL3 bit44 */
			{ 7445, 7,0}, /* core3 sp_EL3 bit45 */
			{ 7446, 7,0}, /* core3 sp_EL3 bit46 */
			{ 7447, 7,0}, /* core3 sp_EL3 bit47 */
			{ 8316, 7,0}, /* core3 sp_EL3 bit48 */
			{ 8317, 7,0}, /* core3 sp_EL3 bit49 */
			{ 8318, 7,0}, /* core3 sp_EL3 bit50 */
			{ 8319, 7,0}, /* core3 sp_EL3 bit51 */
			{ 8248, 7,0}, /* core3 sp_EL3 bit52 */
			{ 8249, 7,0}, /* core3 sp_EL3 bit53 */
			{ 8250, 7,0}, /* core3 sp_EL3 bit54 */
			{ 8251, 7,0}, /* core3 sp_EL3 bit55 */
			{ 7884, 7,0}, /* core3 sp_EL3 bit56 */
			{ 7885, 7,0}, /* core3 sp_EL3 bit57 */
			{ 7886, 7,0}, /* core3 sp_EL3 bit58 */
			{ 7887, 7,0}, /* core3 sp_EL3 bit59 */
			{ 7944, 7,0}, /* core3 sp_EL3 bit60 */
			{ 7945, 7,0}, /* core3 sp_EL3 bit61 */
			{ 7946, 7,0}, /* core3 sp_EL3 bit62 */
			{ 7947, 7,0}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{ 5988, 7,0}, /* core3 elr_EL1 bit0 */
			{ 5989, 7,0}, /* core3 elr_EL1 bit1 */
			{ 5990, 7,0}, /* core3 elr_EL1 bit2 */
			{ 5991, 7,0}, /* core3 elr_EL1 bit3 */
			{ 5996, 7,0}, /* core3 elr_EL1 bit4 */
			{ 5997, 7,0}, /* core3 elr_EL1 bit5 */
			{ 5998, 7,0}, /* core3 elr_EL1 bit6 */
			{ 5999, 7,0}, /* core3 elr_EL1 bit7 */
			{ 6988, 7,0}, /* core3 elr_EL1 bit8 */
			{ 6989, 7,0}, /* core3 elr_EL1 bit9 */
			{ 6990, 7,0}, /* core3 elr_EL1 bit10 */
			{ 6991, 7,0}, /* core3 elr_EL1 bit11 */
			{ 7048, 7,0}, /* core3 elr_EL1 bit12 */
			{ 7049, 7,0}, /* core3 elr_EL1 bit13 */
			{ 7050, 7,0}, /* core3 elr_EL1 bit14 */
			{ 7051, 7,0}, /* core3 elr_EL1 bit15 */
			{ 6896, 7,0}, /* core3 elr_EL1 bit16 */
			{ 6897, 7,0}, /* core3 elr_EL1 bit17 */
			{ 6898, 7,0}, /* core3 elr_EL1 bit18 */
			{ 6899, 7,0}, /* core3 elr_EL1 bit19 */
			{ 6940, 7,0}, /* core3 elr_EL1 bit20 */
			{ 6941, 7,0}, /* core3 elr_EL1 bit21 */
			{ 6942, 7,0}, /* core3 elr_EL1 bit22 */
			{ 6943, 7,0}, /* core3 elr_EL1 bit23 */
			{ 6856, 7,0}, /* core3 elr_EL1 bit24 */
			{ 6857, 7,0}, /* core3 elr_EL1 bit25 */
			{ 6858, 7,0}, /* core3 elr_EL1 bit26 */
			{ 6859, 7,0}, /* core3 elr_EL1 bit27 */
			{ 7216, 7,0}, /* core3 elr_EL1 bit28 */
			{ 7217, 7,0}, /* core3 elr_EL1 bit29 */
			{ 7218, 7,0}, /* core3 elr_EL1 bit30 */
			{ 7219, 7,0}, /* core3 elr_EL1 bit31 */
			{ 8164, 7,0}, /* core3 elr_EL1 bit32 */
			{ 8165, 7,0}, /* core3 elr_EL1 bit33 */
			{ 8166, 7,0}, /* core3 elr_EL1 bit34 */
			{ 8167, 7,0}, /* core3 elr_EL1 bit35 */
			{ 7288, 7,0}, /* core3 elr_EL1 bit36 */
			{ 7289, 7,0}, /* core3 elr_EL1 bit37 */
			{ 7290, 7,0}, /* core3 elr_EL1 bit38 */
			{ 7291, 7,0}, /* core3 elr_EL1 bit39 */
			{ 7428, 7,0}, /* core3 elr_EL1 bit40 */
			{ 7429, 7,0}, /* core3 elr_EL1 bit41 */
			{ 7430, 7,0}, /* core3 elr_EL1 bit42 */
			{ 7431, 7,0}, /* core3 elr_EL1 bit43 */
			{ 7284, 7,0}, /* core3 elr_EL1 bit44 */
			{ 7285, 7,0}, /* core3 elr_EL1 bit45 */
			{ 7286, 7,0}, /* core3 elr_EL1 bit46 */
			{ 7287, 7,0}, /* core3 elr_EL1 bit47 */
			{ 7420, 7,0}, /* core3 elr_EL1 bit48 */
			{ 7421, 7,0}, /* core3 elr_EL1 bit49 */
			{ 7422, 7,0}, /* core3 elr_EL1 bit50 */
			{ 7423, 7,0}, /* core3 elr_EL1 bit51 */
			{ 7860, 7,0}, /* core3 elr_EL1 bit52 */
			{ 7861, 7,0}, /* core3 elr_EL1 bit53 */
			{ 7862, 7,0}, /* core3 elr_EL1 bit54 */
			{ 7863, 7,0}, /* core3 elr_EL1 bit55 */
			{ 7932, 7,0}, /* core3 elr_EL1 bit56 */
			{ 7933, 7,0}, /* core3 elr_EL1 bit57 */
			{ 7934, 7,0}, /* core3 elr_EL1 bit58 */
			{ 7935, 7,0}, /* core3 elr_EL1 bit59 */
			{ 8168, 7,0}, /* core3 elr_EL1 bit60 */
			{ 8169, 7,0}, /* core3 elr_EL1 bit61 */
			{ 8170, 7,0}, /* core3 elr_EL1 bit62 */
			{ 8171, 7,0}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 5992, 7,0}, /* core3 elr_EL2 bit0 */
			{ 5993, 7,0}, /* core3 elr_EL2 bit1 */
			{ 5994, 7,0}, /* core3 elr_EL2 bit2 */
			{ 5995, 7,0}, /* core3 elr_EL2 bit3 */
			{ 6152, 7,0}, /* core3 elr_EL2 bit4 */
			{ 6153, 7,0}, /* core3 elr_EL2 bit5 */
			{ 6154, 7,0}, /* core3 elr_EL2 bit6 */
			{ 6155, 7,0}, /* core3 elr_EL2 bit7 */
			{ 6416, 7,0}, /* core3 elr_EL2 bit8 */
			{ 6417, 7,0}, /* core3 elr_EL2 bit9 */
			{ 6418, 7,0}, /* core3 elr_EL2 bit10 */
			{ 6419, 7,0}, /* core3 elr_EL2 bit11 */
			{ 6924, 7,0}, /* core3 elr_EL2 bit12 */
			{ 6925, 7,0}, /* core3 elr_EL2 bit13 */
			{ 6926, 7,0}, /* core3 elr_EL2 bit14 */
			{ 6927, 7,0}, /* core3 elr_EL2 bit15 */
			{ 6916, 7,0}, /* core3 elr_EL2 bit16 */
			{ 6917, 7,0}, /* core3 elr_EL2 bit17 */
			{ 6918, 7,0}, /* core3 elr_EL2 bit18 */
			{ 6919, 7,0}, /* core3 elr_EL2 bit19 */
			{ 6952, 7,0}, /* core3 elr_EL2 bit20 */
			{ 6953, 7,0}, /* core3 elr_EL2 bit21 */
			{ 6954, 7,0}, /* core3 elr_EL2 bit22 */
			{ 6955, 7,0}, /* core3 elr_EL2 bit23 */
			{ 6904, 7,0}, /* core3 elr_EL2 bit24 */
			{ 6905, 7,0}, /* core3 elr_EL2 bit25 */
			{ 6906, 7,0}, /* core3 elr_EL2 bit26 */
			{ 6907, 7,0}, /* core3 elr_EL2 bit27 */
			{ 7224, 7,0}, /* core3 elr_EL2 bit28 */
			{ 7225, 7,0}, /* core3 elr_EL2 bit29 */
			{ 7226, 7,0}, /* core3 elr_EL2 bit30 */
			{ 7227, 7,0}, /* core3 elr_EL2 bit31 */
			{ 7912, 7,0}, /* core3 elr_EL2 bit32 */
			{ 7913, 7,0}, /* core3 elr_EL2 bit33 */
			{ 7914, 7,0}, /* core3 elr_EL2 bit34 */
			{ 7915, 7,0}, /* core3 elr_EL2 bit35 */
			{ 8300, 7,0}, /* core3 elr_EL2 bit36 */
			{ 8301, 7,0}, /* core3 elr_EL2 bit37 */
			{ 8302, 7,0}, /* core3 elr_EL2 bit38 */
			{ 8303, 7,0}, /* core3 elr_EL2 bit39 */
			{ 8264, 7,0}, /* core3 elr_EL2 bit40 */
			{ 8265, 7,0}, /* core3 elr_EL2 bit41 */
			{ 8266, 7,0}, /* core3 elr_EL2 bit42 */
			{ 8267, 7,0}, /* core3 elr_EL2 bit43 */
			{ 8268, 7,0}, /* core3 elr_EL2 bit44 */
			{ 8269, 7,0}, /* core3 elr_EL2 bit45 */
			{ 8270, 7,0}, /* core3 elr_EL2 bit46 */
			{ 8271, 7,0}, /* core3 elr_EL2 bit47 */
			{ 7456, 7,0}, /* core3 elr_EL2 bit48 */
			{ 7457, 7,0}, /* core3 elr_EL2 bit49 */
			{ 7458, 7,0}, /* core3 elr_EL2 bit50 */
			{ 7459, 7,0}, /* core3 elr_EL2 bit51 */
			{ 7464, 7,0}, /* core3 elr_EL2 bit52 */
			{ 7465, 7,0}, /* core3 elr_EL2 bit53 */
			{ 7466, 7,0}, /* core3 elr_EL2 bit54 */
			{ 7467, 7,0}, /* core3 elr_EL2 bit55 */
			{ 7888, 7,0}, /* core3 elr_EL2 bit56 */
			{ 7889, 7,0}, /* core3 elr_EL2 bit57 */
			{ 7890, 7,0}, /* core3 elr_EL2 bit58 */
			{ 7891, 7,0}, /* core3 elr_EL2 bit59 */
			{ 7936, 7,0}, /* core3 elr_EL2 bit60 */
			{ 7937, 7,0}, /* core3 elr_EL2 bit61 */
			{ 7938, 7,0}, /* core3 elr_EL2 bit62 */
			{ 7939, 7,0}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 6040, 7,0}, /* core3 elr_EL3 bit0 */
			{ 6041, 7,0}, /* core3 elr_EL3 bit1 */
			{ 6042, 7,0}, /* core3 elr_EL3 bit2 */
			{ 6043, 7,0}, /* core3 elr_EL3 bit3 */
			{ 7140, 7,0}, /* core3 elr_EL3 bit4 */
			{ 7141, 7,0}, /* core3 elr_EL3 bit5 */
			{ 7142, 7,0}, /* core3 elr_EL3 bit6 */
			{ 7143, 7,0}, /* core3 elr_EL3 bit7 */
			{ 7180, 7,0}, /* core3 elr_EL3 bit8 */
			{ 7181, 7,0}, /* core3 elr_EL3 bit9 */
			{ 7182, 7,0}, /* core3 elr_EL3 bit10 */
			{ 7183, 7,0}, /* core3 elr_EL3 bit11 */
			{ 7044, 7,0}, /* core3 elr_EL3 bit12 */
			{ 7045, 7,0}, /* core3 elr_EL3 bit13 */
			{ 7046, 7,0}, /* core3 elr_EL3 bit14 */
			{ 7047, 7,0}, /* core3 elr_EL3 bit15 */
			{ 6864, 7,0}, /* core3 elr_EL3 bit16 */
			{ 6865, 7,0}, /* core3 elr_EL3 bit17 */
			{ 6866, 7,0}, /* core3 elr_EL3 bit18 */
			{ 6867, 7,0}, /* core3 elr_EL3 bit19 */
			{ 7028, 7,0}, /* core3 elr_EL3 bit20 */
			{ 7029, 7,0}, /* core3 elr_EL3 bit21 */
			{ 7030, 7,0}, /* core3 elr_EL3 bit22 */
			{ 7031, 7,0}, /* core3 elr_EL3 bit23 */
			{ 6860, 7,0}, /* core3 elr_EL3 bit24 */
			{ 6861, 7,0}, /* core3 elr_EL3 bit25 */
			{ 6862, 7,0}, /* core3 elr_EL3 bit26 */
			{ 6863, 7,0}, /* core3 elr_EL3 bit27 */
			{ 7204, 7,0}, /* core3 elr_EL3 bit28 */
			{ 7205, 7,0}, /* core3 elr_EL3 bit29 */
			{ 7206, 7,0}, /* core3 elr_EL3 bit30 */
			{ 7207, 7,0}, /* core3 elr_EL3 bit31 */
			{ 8340, 7,0}, /* core3 elr_EL3 bit32 */
			{ 8341, 7,0}, /* core3 elr_EL3 bit33 */
			{ 8342, 7,0}, /* core3 elr_EL3 bit34 */
			{ 8343, 7,0}, /* core3 elr_EL3 bit35 */
			{ 8252, 7,0}, /* core3 elr_EL3 bit36 */
			{ 8253, 7,0}, /* core3 elr_EL3 bit37 */
			{ 8254, 7,0}, /* core3 elr_EL3 bit38 */
			{ 8255, 7,0}, /* core3 elr_EL3 bit39 */
			{ 7868, 7,0}, /* core3 elr_EL3 bit40 */
			{ 7869, 7,0}, /* core3 elr_EL3 bit41 */
			{ 7870, 7,0}, /* core3 elr_EL3 bit42 */
			{ 7871, 7,0}, /* core3 elr_EL3 bit43 */
			{ 7864, 7,0}, /* core3 elr_EL3 bit44 */
			{ 7865, 7,0}, /* core3 elr_EL3 bit45 */
			{ 7866, 7,0}, /* core3 elr_EL3 bit46 */
			{ 7867, 7,0}, /* core3 elr_EL3 bit47 */
			{ 7876, 7,0}, /* core3 elr_EL3 bit48 */
			{ 7877, 7,0}, /* core3 elr_EL3 bit49 */
			{ 7878, 7,0}, /* core3 elr_EL3 bit50 */
			{ 7879, 7,0}, /* core3 elr_EL3 bit51 */
			{ 8324, 7,0}, /* core3 elr_EL3 bit52 */
			{ 8325, 7,0}, /* core3 elr_EL3 bit53 */
			{ 8326, 7,0}, /* core3 elr_EL3 bit54 */
			{ 8327, 7,0}, /* core3 elr_EL3 bit55 */
			{ 7924, 7,0}, /* core3 elr_EL3 bit56 */
			{ 7925, 7,0}, /* core3 elr_EL3 bit57 */
			{ 7926, 7,0}, /* core3 elr_EL3 bit58 */
			{ 7927, 7,0}, /* core3 elr_EL3 bit59 */
			{ 7940, 7,0}, /* core3 elr_EL3 bit60 */
			{ 7941, 7,0}, /* core3 elr_EL3 bit61 */
			{ 7942, 7,0}, /* core3 elr_EL3 bit62 */
			{ 7943, 7,0}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 8448, 8,0}, /* core3 raw_pc bit0 */
			{10692, 7,0}, /* core3 raw_pc bit1 */
			{10693, 7,0}, /* core3 raw_pc bit2 */
			{ 9360, 7,0}, /* core3 raw_pc bit3 */
			{ 9361, 7,0}, /* core3 raw_pc bit4 */
			{ 9362, 7,0}, /* core3 raw_pc bit5 */
			{ 9363, 7,0}, /* core3 raw_pc bit6 */
			{12608, 7,0}, /* core3 raw_pc bit7 */
			{12609, 7,0}, /* core3 raw_pc bit8 */
			{12610, 7,0}, /* core3 raw_pc bit9 */
			{12611, 7,0}, /* core3 raw_pc bit10 */
			{12580, 7,0}, /* core3 raw_pc bit11 */
			{12581, 7,0}, /* core3 raw_pc bit12 */
			{12582, 7,0}, /* core3 raw_pc bit13 */
			{12583, 7,0}, /* core3 raw_pc bit14 */
			{12584, 7,0}, /* core3 raw_pc bit15 */
			{12585, 7,0}, /* core3 raw_pc bit16 */
			{12586, 7,0}, /* core3 raw_pc bit17 */
			{12587, 7,0}, /* core3 raw_pc bit18 */
			{12576, 7,0}, /* core3 raw_pc bit19 */
			{12577, 7,0}, /* core3 raw_pc bit20 */
			{12578, 7,0}, /* core3 raw_pc bit21 */
			{12579, 7,0}, /* core3 raw_pc bit22 */
			{ 9376, 7,0}, /* core3 raw_pc bit23 */
			{ 9377, 7,0}, /* core3 raw_pc bit24 */
			{ 9378, 7,0}, /* core3 raw_pc bit25 */
			{ 9379, 7,0}, /* core3 raw_pc bit26 */
			{ 9384, 7,0}, /* core3 raw_pc bit27 */
			{ 9385, 7,0}, /* core3 raw_pc bit28 */
			{ 9386, 7,0}, /* core3 raw_pc bit29 */
			{ 9387, 7,0}, /* core3 raw_pc bit30 */
			{14492, 7,0}, /* core3 raw_pc bit31 */
			{12620, 7,0}, /* core3 raw_pc bit32 */
			{12621, 7,0}, /* core3 raw_pc bit33 */
			{12622, 7,0}, /* core3 raw_pc bit34 */
			{12623, 7,0}, /* core3 raw_pc bit35 */
			{ 9408, 7,0}, /* core3 raw_pc bit36 */
			{ 9409, 7,0}, /* core3 raw_pc bit37 */
			{ 9410, 7,0}, /* core3 raw_pc bit38 */
			{ 9411, 7,0}, /* core3 raw_pc bit39 */
			{ 9396, 7,0}, /* core3 raw_pc bit40 */
			{ 9397, 7,0}, /* core3 raw_pc bit41 */
			{ 9398, 7,0}, /* core3 raw_pc bit42 */
			{ 9399, 7,0}, /* core3 raw_pc bit43 */
			{ 9392, 7,0}, /* core3 raw_pc bit44 */
			{ 9393, 7,0}, /* core3 raw_pc bit45 */
			{ 9394, 7,0}, /* core3 raw_pc bit46 */
			{ 9395, 7,0}, /* core3 raw_pc bit47 */
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
			{15238, 7,0}, /* core3 pc_iss bit0 */
			{15206, 7,0}, /* core3 pc_iss bit1 */
			{15235, 7,0}, /* core3 pc_iss bit2 */
			{15306, 7,0}, /* core3 pc_iss bit3 */
			{15203, 7,0}, /* core3 pc_iss bit4 */
			{15297, 7,0}, /* core3 pc_iss bit5 */
			{15207, 7,0}, /* core3 pc_iss bit6 */
			{15204, 7,0}, /* core3 pc_iss bit7 */
			{15208, 7,0}, /* core3 pc_iss bit8 */
			{15209, 7,0}, /* core3 pc_iss bit9 */
			{15211, 7,0}, /* core3 pc_iss bit10 */
			{15200, 7,0}, /* core3 pc_iss bit11 */
			{15215, 7,0}, /* core3 pc_iss bit12 */
			{15212, 7,0}, /* core3 pc_iss bit13 */
			{15188, 7,0}, /* core3 pc_iss bit14 */
			{15210, 7,0}, /* core3 pc_iss bit15 */
			{15217, 7,0}, /* core3 pc_iss bit16 */
			{15213, 7,0}, /* core3 pc_iss bit17 */
			{15214, 7,0}, /* core3 pc_iss bit18 */
			{15189, 7,0}, /* core3 pc_iss bit19 */
			{15187, 7,0}, /* core3 pc_iss bit20 */
			{15216, 7,0}, /* core3 pc_iss bit21 */
			{15196, 7,0}, /* core3 pc_iss bit22 */
			{15195, 7,0}, /* core3 pc_iss bit23 */
			{15186, 7,0}, /* core3 pc_iss bit24 */
			{15193, 7,0}, /* core3 pc_iss bit25 */
			{15194, 7,0}, /* core3 pc_iss bit26 */
			{15327, 7,0}, /* core3 pc_iss bit27 */
			{15333, 7,0}, /* core3 pc_iss bit28 */
			{15326, 7,0}, /* core3 pc_iss bit29 */
			{15191, 7,0}, /* core3 pc_iss bit30 */
			{15336, 7,0}, /* core3 pc_iss bit31 */
			{12440, 7,0}, /* core3 pc_iss bit32 */
			{12441, 7,0}, /* core3 pc_iss bit33 */
			{12442, 7,0}, /* core3 pc_iss bit34 */
			{12443, 7,0}, /* core3 pc_iss bit35 */
			{12436, 7,0}, /* core3 pc_iss bit36 */
			{12437, 7,0}, /* core3 pc_iss bit37 */
			{12438, 7,0}, /* core3 pc_iss bit38 */
			{12439, 7,0}, /* core3 pc_iss bit39 */
			{12516, 7,0}, /* core3 pc_iss bit40 */
			{12517, 7,0}, /* core3 pc_iss bit41 */
			{12518, 7,0}, /* core3 pc_iss bit42 */
			{12519, 7,0}, /* core3 pc_iss bit43 */
			{12512, 7,0}, /* core3 pc_iss bit44 */
			{12513, 7,0}, /* core3 pc_iss bit45 */
			{12514, 7,0}, /* core3 pc_iss bit46 */
			{12515, 7,0}, /* core3 pc_iss bit47 */
			{12636, 7,0}, /* core3 pc_iss bit48 */
			{12637, 7,0}, /* core3 pc_iss bit49 */
			{12638, 7,0}, /* core3 pc_iss bit50 */
			{12639, 7,0}, /* core3 pc_iss bit51 */
			{12632, 7,0}, /* core3 pc_iss bit52 */
			{12633, 7,0}, /* core3 pc_iss bit53 */
			{12634, 7,0}, /* core3 pc_iss bit54 */
			{12635, 7,0}, /* core3 pc_iss bit55 */
			{12640, 7,0}, /* core3 pc_iss bit56 */
			{12641, 7,0}, /* core3 pc_iss bit57 */
			{12642, 7,0}, /* core3 pc_iss bit58 */
			{12643, 7,0}, /* core3 pc_iss bit59 */
			{12644, 7,0}, /* core3 pc_iss bit60 */
			{12645, 7,0}, /* core3 pc_iss bit61 */
			{12646, 7,0}, /* core3 pc_iss bit62 */
			{12647, 7,0}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 8447, 8,0}, /* core3 full_pc_wr bit0 */
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
			{15304, 7,0}, /* core3 full_pc_ex1 bit0 */
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
			{ 8443, 8,0}, /* core3 full_pc_ex2 bit0 */
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
	},
	{		/* core 4 */ 
			.pc = {{
			{ 7160,10,0}, /* core4 pc bit0 */
			{ 7161,10,0}, /* core4 pc bit1 */
			{ 7162,10,0}, /* core4 pc bit2 */
			{ 7163,10,0}, /* core4 pc bit3 */
			{ 7344,10,0}, /* core4 pc bit4 */
			{ 7345,10,0}, /* core4 pc bit5 */
			{ 7346,10,0}, /* core4 pc bit6 */
			{ 7347,10,0}, /* core4 pc bit7 */
			{ 7356,10,0}, /* core4 pc bit8 */
			{ 7357,10,0}, /* core4 pc bit9 */
			{ 7358,10,0}, /* core4 pc bit10 */
			{ 7359,10,0}, /* core4 pc bit11 */
			{ 6704,10,0}, /* core4 pc bit12 */
			{ 6705,10,0}, /* core4 pc bit13 */
			{ 6706,10,0}, /* core4 pc bit14 */
			{ 6707,10,0}, /* core4 pc bit15 */
			{ 6708,10,0}, /* core4 pc bit16 */
			{ 6709,10,0}, /* core4 pc bit17 */
			{ 6710,10,0}, /* core4 pc bit18 */
			{ 6711,10,0}, /* core4 pc bit19 */
			{10968,10,0}, /* core4 pc bit20 */
			{10969,10,0}, /* core4 pc bit21 */
			{10970,10,0}, /* core4 pc bit22 */
			{10971,10,0}, /* core4 pc bit23 */
			{ 7348,10,0}, /* core4 pc bit24 */
			{ 7349,10,0}, /* core4 pc bit25 */
			{ 7350,10,0}, /* core4 pc bit26 */
			{ 7351,10,0}, /* core4 pc bit27 */
			{ 6700,10,0}, /* core4 pc bit28 */
			{ 6701,10,0}, /* core4 pc bit29 */
			{ 6702,10,0}, /* core4 pc bit30 */
			{ 6703,10,0}, /* core4 pc bit31 */
			{17044,10,0}, /* core4 pc bit32 */
			{17045,10,0}, /* core4 pc bit33 */
			{17046,10,0}, /* core4 pc bit34 */
			{17047,10,0}, /* core4 pc bit35 */
			{17040,10,0}, /* core4 pc bit36 */
			{17041,10,0}, /* core4 pc bit37 */
			{17042,10,0}, /* core4 pc bit38 */
			{17043,10,0}, /* core4 pc bit39 */
			{17036,10,0}, /* core4 pc bit40 */
			{17037,10,0}, /* core4 pc bit41 */
			{17038,10,0}, /* core4 pc bit42 */
			{17039,10,0}, /* core4 pc bit43 */
			{17032,10,0}, /* core4 pc bit44 */
			{17033,10,0}, /* core4 pc bit45 */
			{17034,10,0}, /* core4 pc bit46 */
			{17035,10,0}, /* core4 pc bit47 */
			{17016,10,0}, /* core4 pc bit48 */
			{17017,10,0}, /* core4 pc bit49 */
			{17018,10,0}, /* core4 pc bit50 */
			{17019,10,0}, /* core4 pc bit51 */
			{17020,10,0}, /* core4 pc bit52 */
			{17021,10,0}, /* core4 pc bit53 */
			{17022,10,0}, /* core4 pc bit54 */
			{17023,10,0}, /* core4 pc bit55 */
			{17028,10,0}, /* core4 pc bit56 */
			{17029,10,0}, /* core4 pc bit57 */
			{17030,10,0}, /* core4 pc bit58 */
			{17031,10,0}, /* core4 pc bit59 */
			{17024,10,0}, /* core4 pc bit60 */
			{17025,10,0}, /* core4 pc bit61 */
			{17026,10,0}, /* core4 pc bit62 */
			{17027,10,0}, /* core4 pc bit63 */
			}},
			.sp32 = {{
			{ 6923,10,0}, /* core4 sp32 bit0 */
			{ 6922,10,0}, /* core4 sp32 bit1 */
			{ 6921,10,0}, /* core4 sp32 bit2 */
			{ 6920,10,0}, /* core4 sp32 bit3 */
			{ 6588,10,0}, /* core4 sp32 bit4 */
			{ 6589,10,0}, /* core4 sp32 bit5 */
			{ 6590,10,0}, /* core4 sp32 bit6 */
			{ 6591,10,0}, /* core4 sp32 bit7 */
			{ 6676,10,0}, /* core4 sp32 bit8 */
			{ 6677,10,0}, /* core4 sp32 bit9 */
			{ 6678,10,0}, /* core4 sp32 bit10 */
			{ 6679,10,0}, /* core4 sp32 bit11 */
			{ 6656,10,0}, /* core4 sp32 bit12 */
			{ 6657,10,0}, /* core4 sp32 bit13 */
			{ 6658,10,0}, /* core4 sp32 bit14 */
			{ 6659,10,0}, /* core4 sp32 bit15 */
			{ 6660,10,0}, /* core4 sp32 bit16 */
			{ 6661,10,0}, /* core4 sp32 bit17 */
			{ 6662,10,0}, /* core4 sp32 bit18 */
			{ 6663,10,0}, /* core4 sp32 bit19 */
			{ 6912,10,0}, /* core4 sp32 bit20 */
			{ 6913,10,0}, /* core4 sp32 bit21 */
			{ 6914,10,0}, /* core4 sp32 bit22 */
			{ 6915,10,0}, /* core4 sp32 bit23 */
			{ 6628,10,0}, /* core4 sp32 bit24 */
			{ 6629,10,0}, /* core4 sp32 bit25 */
			{ 6630,10,0}, /* core4 sp32 bit26 */
			{ 6631,10,0}, /* core4 sp32 bit27 */
			{ 6916,10,0}, /* core4 sp32 bit28 */
			{ 6917,10,0}, /* core4 sp32 bit29 */
			{ 6918,10,0}, /* core4 sp32 bit30 */
			{ 6919,10,0}, /* core4 sp32 bit31 */
			{ 7624,10,0}, /* core4 sp32 bit32 */
			{ 7625,10,0}, /* core4 sp32 bit33 */
			{ 7626,10,0}, /* core4 sp32 bit34 */
			{ 7627,10,0}, /* core4 sp32 bit35 */
			{ 7656,10,0}, /* core4 sp32 bit36 */
			{ 7657,10,0}, /* core4 sp32 bit37 */
			{ 7658,10,0}, /* core4 sp32 bit38 */
			{ 7659,10,0}, /* core4 sp32 bit39 */
			{ 7688,10,0}, /* core4 sp32 bit40 */
			{ 7689,10,0}, /* core4 sp32 bit41 */
			{ 7690,10,0}, /* core4 sp32 bit42 */
			{ 7691,10,0}, /* core4 sp32 bit43 */
			{ 8436,10,0}, /* core4 sp32 bit44 */
			{ 8437,10,0}, /* core4 sp32 bit45 */
			{ 8438,10,0}, /* core4 sp32 bit46 */
			{ 8439,10,0}, /* core4 sp32 bit47 */
			{ 8248,10,0}, /* core4 sp32 bit48 */
			{ 8249,10,0}, /* core4 sp32 bit49 */
			{ 8250,10,0}, /* core4 sp32 bit50 */
			{ 8251,10,0}, /* core4 sp32 bit51 */
			{ 8244,10,0}, /* core4 sp32 bit52 */
			{ 8245,10,0}, /* core4 sp32 bit53 */
			{ 8246,10,0}, /* core4 sp32 bit54 */
			{ 8247,10,0}, /* core4 sp32 bit55 */
			{ 8252,10,0}, /* core4 sp32 bit56 */
			{ 8253,10,0}, /* core4 sp32 bit57 */
			{ 8254,10,0}, /* core4 sp32 bit58 */
			{ 8255,10,0}, /* core4 sp32 bit59 */
			{ 7596,10,0}, /* core4 sp32 bit60 */
			{ 7597,10,0}, /* core4 sp32 bit61 */
			{ 7598,10,0}, /* core4 sp32 bit62 */
			{ 7599,10,0}, /* core4 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7916,10,0}, /* core4 fp32 bit0 */
			{ 7917,10,0}, /* core4 fp32 bit1 */
			{ 7918,10,0}, /* core4 fp32 bit2 */
			{ 7919,10,0}, /* core4 fp32 bit3 */
			{ 3892,11,0}, /* core4 fp32 bit4 */
			{ 3893,11,0}, /* core4 fp32 bit5 */
			{ 3894,11,0}, /* core4 fp32 bit6 */
			{ 3895,11,0}, /* core4 fp32 bit7 */
			{10104,10,0}, /* core4 fp32 bit8 */
			{10105,10,0}, /* core4 fp32 bit9 */
			{10106,10,0}, /* core4 fp32 bit10 */
			{10107,10,0}, /* core4 fp32 bit11 */
			{10108,10,0}, /* core4 fp32 bit12 */
			{10109,10,0}, /* core4 fp32 bit13 */
			{10110,10,0}, /* core4 fp32 bit14 */
			{10111,10,0}, /* core4 fp32 bit15 */
			{ 3946,11,0}, /* core4 fp32 bit16 */
			{ 3947,11,0}, /* core4 fp32 bit17 */
			{ 3948,11,0}, /* core4 fp32 bit18 */
			{ 3949,11,0}, /* core4 fp32 bit19 */
			{ 7876,10,0}, /* core4 fp32 bit20 */
			{ 7877,10,0}, /* core4 fp32 bit21 */
			{ 7878,10,0}, /* core4 fp32 bit22 */
			{ 7879,10,0}, /* core4 fp32 bit23 */
			{ 3906,11,0}, /* core4 fp32 bit24 */
			{ 3907,11,0}, /* core4 fp32 bit25 */
			{ 3908,11,0}, /* core4 fp32 bit26 */
			{ 3909,11,0}, /* core4 fp32 bit27 */
			{ 7880,10,0}, /* core4 fp32 bit28 */
			{ 7881,10,0}, /* core4 fp32 bit29 */
			{ 7882,10,0}, /* core4 fp32 bit30 */
			{ 7883,10,0}, /* core4 fp32 bit31 */
			{ 7860,10,0}, /* core4 fp32 bit32 */
			{ 7861,10,0}, /* core4 fp32 bit33 */
			{ 7862,10,0}, /* core4 fp32 bit34 */
			{ 7863,10,0}, /* core4 fp32 bit35 */
			{ 7804,10,0}, /* core4 fp32 bit36 */
			{ 7805,10,0}, /* core4 fp32 bit37 */
			{ 7806,10,0}, /* core4 fp32 bit38 */
			{ 7807,10,0}, /* core4 fp32 bit39 */
			{ 7772,10,0}, /* core4 fp32 bit40 */
			{ 7773,10,0}, /* core4 fp32 bit41 */
			{ 7774,10,0}, /* core4 fp32 bit42 */
			{ 7775,10,0}, /* core4 fp32 bit43 */
			{ 7744,10,0}, /* core4 fp32 bit44 */
			{ 7745,10,0}, /* core4 fp32 bit45 */
			{ 7746,10,0}, /* core4 fp32 bit46 */
			{ 7747,10,0}, /* core4 fp32 bit47 */
			{11296,10,0}, /* core4 fp32 bit48 */
			{11297,10,0}, /* core4 fp32 bit49 */
			{11298,10,0}, /* core4 fp32 bit50 */
			{11299,10,0}, /* core4 fp32 bit51 */
			{11288,10,0}, /* core4 fp32 bit52 */
			{11289,10,0}, /* core4 fp32 bit53 */
			{11290,10,0}, /* core4 fp32 bit54 */
			{11291,10,0}, /* core4 fp32 bit55 */
			{ 7500,10,0}, /* core4 fp32 bit56 */
			{ 7501,10,0}, /* core4 fp32 bit57 */
			{ 7502,10,0}, /* core4 fp32 bit58 */
			{ 7503,10,0}, /* core4 fp32 bit59 */
			{11268,10,0}, /* core4 fp32 bit60 */
			{11269,10,0}, /* core4 fp32 bit61 */
			{11270,10,0}, /* core4 fp32 bit62 */
			{11271,10,0}, /* core4 fp32 bit63 */
			}},
			.fp64 = {{
			{ 8687,10,0}, /* core4 fp64 bit0 */
			{ 8685,10,0}, /* core4 fp64 bit1 */
			{ 8686,10,0}, /* core4 fp64 bit2 */
			{ 5329,11,0}, /* core4 fp64 bit3 */
			{ 8684,10,0}, /* core4 fp64 bit4 */
			{ 5312,11,0}, /* core4 fp64 bit5 */
			{  481,11,0}, /* core4 fp64 bit6 */
			{  480,11,0}, /* core4 fp64 bit7 */
			{ 5307,11,0}, /* core4 fp64 bit8 */
			{  485,11,0}, /* core4 fp64 bit9 */
			{  484,11,0}, /* core4 fp64 bit10 */
			{ 5311,11,0}, /* core4 fp64 bit11 */
			{ 5310,11,0}, /* core4 fp64 bit12 */
			{  453,11,0}, /* core4 fp64 bit13 */
			{  452,11,0}, /* core4 fp64 bit14 */
			{ 5308,11,0}, /* core4 fp64 bit15 */
			{16318,10,0}, /* core4 fp64 bit16 */
			{  455,11,0}, /* core4 fp64 bit17 */
			{  454,11,0}, /* core4 fp64 bit18 */
			{16314,10,0}, /* core4 fp64 bit19 */
			{16313,10,0}, /* core4 fp64 bit20 */
			{ 8659,10,0}, /* core4 fp64 bit21 */
			{ 8658,10,0}, /* core4 fp64 bit22 */
			{16317,10,0}, /* core4 fp64 bit23 */
			{16312,10,0}, /* core4 fp64 bit24 */
			{16311,10,0}, /* core4 fp64 bit25 */
			{16316,10,0}, /* core4 fp64 bit26 */
			{ 5332,11,0}, /* core4 fp64 bit27 */
			{ 8657,10,0}, /* core4 fp64 bit28 */
			{16315,10,0}, /* core4 fp64 bit29 */
			{ 8656,10,0}, /* core4 fp64 bit30 */
			{ 5328,11,0}, /* core4 fp64 bit31 */
			{   24,10,0}, /* core4 fp64 bit32 */
			{   25,10,0}, /* core4 fp64 bit33 */
			{   26,10,0}, /* core4 fp64 bit34 */
			{   27,10,0}, /* core4 fp64 bit35 */
			{   28,10,0}, /* core4 fp64 bit36 */
			{   29,10,0}, /* core4 fp64 bit37 */
			{   30,10,0}, /* core4 fp64 bit38 */
			{   31,10,0}, /* core4 fp64 bit39 */
			{   52,10,0}, /* core4 fp64 bit40 */
			{   53,10,0}, /* core4 fp64 bit41 */
			{   54,10,0}, /* core4 fp64 bit42 */
			{   55,10,0}, /* core4 fp64 bit43 */
			{  112,10,0}, /* core4 fp64 bit44 */
			{  113,10,0}, /* core4 fp64 bit45 */
			{  114,10,0}, /* core4 fp64 bit46 */
			{  115,10,0}, /* core4 fp64 bit47 */
			{  156,10,0}, /* core4 fp64 bit48 */
			{  157,10,0}, /* core4 fp64 bit49 */
			{  158,10,0}, /* core4 fp64 bit50 */
			{  159,10,0}, /* core4 fp64 bit51 */
			{  168,10,0}, /* core4 fp64 bit52 */
			{  169,10,0}, /* core4 fp64 bit53 */
			{  170,10,0}, /* core4 fp64 bit54 */
			{  171,10,0}, /* core4 fp64 bit55 */
			{  172,10,0}, /* core4 fp64 bit56 */
			{  173,10,0}, /* core4 fp64 bit57 */
			{  174,10,0}, /* core4 fp64 bit58 */
			{  175,10,0}, /* core4 fp64 bit59 */
			{ 7564,10,0}, /* core4 fp64 bit60 */
			{ 7565,10,0}, /* core4 fp64 bit61 */
			{ 7566,10,0}, /* core4 fp64 bit62 */
			{ 7567,10,0}, /* core4 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{16282,10,0}, /* core4 sp_EL0 bit0 */
			{16281,10,0}, /* core4 sp_EL0 bit1 */
			{16280,10,0}, /* core4 sp_EL0 bit2 */
			{16279,10,0}, /* core4 sp_EL0 bit3 */
			{ 6524,10,0}, /* core4 sp_EL0 bit4 */
			{ 6525,10,0}, /* core4 sp_EL0 bit5 */
			{ 6526,10,0}, /* core4 sp_EL0 bit6 */
			{ 6527,10,0}, /* core4 sp_EL0 bit7 */
			{ 7116,10,0}, /* core4 sp_EL0 bit8 */
			{ 7117,10,0}, /* core4 sp_EL0 bit9 */
			{ 7118,10,0}, /* core4 sp_EL0 bit10 */
			{ 7119,10,0}, /* core4 sp_EL0 bit11 */
			{ 7128,10,0}, /* core4 sp_EL0 bit12 */
			{ 7129,10,0}, /* core4 sp_EL0 bit13 */
			{ 7130,10,0}, /* core4 sp_EL0 bit14 */
			{ 7131,10,0}, /* core4 sp_EL0 bit15 */
			{ 6992,10,0}, /* core4 sp_EL0 bit16 */
			{ 6993,10,0}, /* core4 sp_EL0 bit17 */
			{ 6994,10,0}, /* core4 sp_EL0 bit18 */
			{ 6995,10,0}, /* core4 sp_EL0 bit19 */
			{ 6712,10,0}, /* core4 sp_EL0 bit20 */
			{ 6713,10,0}, /* core4 sp_EL0 bit21 */
			{ 6714,10,0}, /* core4 sp_EL0 bit22 */
			{ 6715,10,0}, /* core4 sp_EL0 bit23 */
			{ 6544,10,0}, /* core4 sp_EL0 bit24 */
			{ 6545,10,0}, /* core4 sp_EL0 bit25 */
			{ 6546,10,0}, /* core4 sp_EL0 bit26 */
			{ 6547,10,0}, /* core4 sp_EL0 bit27 */
			{ 6756,10,0}, /* core4 sp_EL0 bit28 */
			{ 6757,10,0}, /* core4 sp_EL0 bit29 */
			{ 6758,10,0}, /* core4 sp_EL0 bit30 */
			{ 6759,10,0}, /* core4 sp_EL0 bit31 */
			{   32,10,0}, /* core4 sp_EL0 bit32 */
			{   33,10,0}, /* core4 sp_EL0 bit33 */
			{   34,10,0}, /* core4 sp_EL0 bit34 */
			{   35,10,0}, /* core4 sp_EL0 bit35 */
			{   48,10,0}, /* core4 sp_EL0 bit36 */
			{   49,10,0}, /* core4 sp_EL0 bit37 */
			{   50,10,0}, /* core4 sp_EL0 bit38 */
			{   51,10,0}, /* core4 sp_EL0 bit39 */
			{   60,10,0}, /* core4 sp_EL0 bit40 */
			{   61,10,0}, /* core4 sp_EL0 bit41 */
			{   62,10,0}, /* core4 sp_EL0 bit42 */
			{   63,10,0}, /* core4 sp_EL0 bit43 */
			{  108,10,0}, /* core4 sp_EL0 bit44 */
			{  109,10,0}, /* core4 sp_EL0 bit45 */
			{  110,10,0}, /* core4 sp_EL0 bit46 */
			{  111,10,0}, /* core4 sp_EL0 bit47 */
			{ 8380,10,0}, /* core4 sp_EL0 bit48 */
			{ 8381,10,0}, /* core4 sp_EL0 bit49 */
			{ 8382,10,0}, /* core4 sp_EL0 bit50 */
			{ 8383,10,0}, /* core4 sp_EL0 bit51 */
			{ 8376,10,0}, /* core4 sp_EL0 bit52 */
			{ 8377,10,0}, /* core4 sp_EL0 bit53 */
			{ 8378,10,0}, /* core4 sp_EL0 bit54 */
			{ 8379,10,0}, /* core4 sp_EL0 bit55 */
			{ 8384,10,0}, /* core4 sp_EL0 bit56 */
			{ 8385,10,0}, /* core4 sp_EL0 bit57 */
			{ 8386,10,0}, /* core4 sp_EL0 bit58 */
			{ 8387,10,0}, /* core4 sp_EL0 bit59 */
			{ 8388,10,0}, /* core4 sp_EL0 bit60 */
			{ 8389,10,0}, /* core4 sp_EL0 bit61 */
			{ 8390,10,0}, /* core4 sp_EL0 bit62 */
			{ 8391,10,0}, /* core4 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6575,10,0}, /* core4 sp_EL1 bit0 */
			{ 6574,10,0}, /* core4 sp_EL1 bit1 */
			{ 6573,10,0}, /* core4 sp_EL1 bit2 */
			{ 6572,10,0}, /* core4 sp_EL1 bit3 */
			{ 5326,11,0}, /* core4 sp_EL1 bit4 */
			{  489,11,0}, /* core4 sp_EL1 bit5 */
			{  488,11,0}, /* core4 sp_EL1 bit6 */
			{  487,11,0}, /* core4 sp_EL1 bit7 */
			{  486,11,0}, /* core4 sp_EL1 bit8 */
			{ 7311,10,0}, /* core4 sp_EL1 bit9 */
			{ 7259,10,0}, /* core4 sp_EL1 bit10 */
			{ 7258,10,0}, /* core4 sp_EL1 bit11 */
			{ 7257,10,0}, /* core4 sp_EL1 bit12 */
			{ 7256,10,0}, /* core4 sp_EL1 bit13 */
			{ 5305,11,0}, /* core4 sp_EL1 bit14 */
			{ 7310,10,0}, /* core4 sp_EL1 bit15 */
			{  491,11,0}, /* core4 sp_EL1 bit16 */
			{ 7309,10,0}, /* core4 sp_EL1 bit17 */
			{ 7308,10,0}, /* core4 sp_EL1 bit18 */
			{ 6587,10,0}, /* core4 sp_EL1 bit19 */
			{ 5325,11,0}, /* core4 sp_EL1 bit20 */
			{ 6586,10,0}, /* core4 sp_EL1 bit21 */
			{ 6585,10,0}, /* core4 sp_EL1 bit22 */
			{ 6584,10,0}, /* core4 sp_EL1 bit23 */
			{  490,11,0}, /* core4 sp_EL1 bit24 */
			{16320,10,0}, /* core4 sp_EL1 bit25 */
			{16319,10,0}, /* core4 sp_EL1 bit26 */
			{10137,10,0}, /* core4 sp_EL1 bit27 */
			{10136,10,0}, /* core4 sp_EL1 bit28 */
			{ 8693,10,0}, /* core4 sp_EL1 bit29 */
			{ 8692,10,0}, /* core4 sp_EL1 bit30 */
			{ 5327,11,0}, /* core4 sp_EL1 bit31 */
			{ 6824,10,0}, /* core4 sp_EL1 bit32 */
			{ 6825,10,0}, /* core4 sp_EL1 bit33 */
			{ 6826,10,0}, /* core4 sp_EL1 bit34 */
			{ 6827,10,0}, /* core4 sp_EL1 bit35 */
			{ 6800,10,0}, /* core4 sp_EL1 bit36 */
			{ 6801,10,0}, /* core4 sp_EL1 bit37 */
			{ 6802,10,0}, /* core4 sp_EL1 bit38 */
			{ 6803,10,0}, /* core4 sp_EL1 bit39 */
			{ 6804,10,0}, /* core4 sp_EL1 bit40 */
			{ 6805,10,0}, /* core4 sp_EL1 bit41 */
			{ 6806,10,0}, /* core4 sp_EL1 bit42 */
			{ 6807,10,0}, /* core4 sp_EL1 bit43 */
			{   68,10,0}, /* core4 sp_EL1 bit44 */
			{   69,10,0}, /* core4 sp_EL1 bit45 */
			{   70,10,0}, /* core4 sp_EL1 bit46 */
			{   71,10,0}, /* core4 sp_EL1 bit47 */
			{  148,10,0}, /* core4 sp_EL1 bit48 */
			{  149,10,0}, /* core4 sp_EL1 bit49 */
			{  150,10,0}, /* core4 sp_EL1 bit50 */
			{  151,10,0}, /* core4 sp_EL1 bit51 */
			{  140,10,0}, /* core4 sp_EL1 bit52 */
			{  141,10,0}, /* core4 sp_EL1 bit53 */
			{  142,10,0}, /* core4 sp_EL1 bit54 */
			{  143,10,0}, /* core4 sp_EL1 bit55 */
			{  128,10,0}, /* core4 sp_EL1 bit56 */
			{  129,10,0}, /* core4 sp_EL1 bit57 */
			{  130,10,0}, /* core4 sp_EL1 bit58 */
			{  131,10,0}, /* core4 sp_EL1 bit59 */
			{  124,10,0}, /* core4 sp_EL1 bit60 */
			{  125,10,0}, /* core4 sp_EL1 bit61 */
			{  126,10,0}, /* core4 sp_EL1 bit62 */
			{  127,10,0}, /* core4 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{16266,10,0}, /* core4 sp_EL2 bit0 */
			{16265,10,0}, /* core4 sp_EL2 bit1 */
			{16276,10,0}, /* core4 sp_EL2 bit2 */
			{16275,10,0}, /* core4 sp_EL2 bit3 */
			{ 6512,10,0}, /* core4 sp_EL2 bit4 */
			{ 6513,10,0}, /* core4 sp_EL2 bit5 */
			{ 6514,10,0}, /* core4 sp_EL2 bit6 */
			{ 6515,10,0}, /* core4 sp_EL2 bit7 */
			{ 7040,10,0}, /* core4 sp_EL2 bit8 */
			{ 7041,10,0}, /* core4 sp_EL2 bit9 */
			{ 7042,10,0}, /* core4 sp_EL2 bit10 */
			{ 7043,10,0}, /* core4 sp_EL2 bit11 */
			{ 7004,10,0}, /* core4 sp_EL2 bit12 */
			{ 7005,10,0}, /* core4 sp_EL2 bit13 */
			{ 7006,10,0}, /* core4 sp_EL2 bit14 */
			{ 7007,10,0}, /* core4 sp_EL2 bit15 */
			{ 7224,10,0}, /* core4 sp_EL2 bit16 */
			{ 7225,10,0}, /* core4 sp_EL2 bit17 */
			{ 7226,10,0}, /* core4 sp_EL2 bit18 */
			{ 7227,10,0}, /* core4 sp_EL2 bit19 */
			{ 6768,10,0}, /* core4 sp_EL2 bit20 */
			{ 6769,10,0}, /* core4 sp_EL2 bit21 */
			{ 6770,10,0}, /* core4 sp_EL2 bit22 */
			{ 6771,10,0}, /* core4 sp_EL2 bit23 */
			{ 6556,10,0}, /* core4 sp_EL2 bit24 */
			{ 6557,10,0}, /* core4 sp_EL2 bit25 */
			{ 6558,10,0}, /* core4 sp_EL2 bit26 */
			{ 6559,10,0}, /* core4 sp_EL2 bit27 */
			{ 6764,10,0}, /* core4 sp_EL2 bit28 */
			{ 6765,10,0}, /* core4 sp_EL2 bit29 */
			{ 6766,10,0}, /* core4 sp_EL2 bit30 */
			{ 6767,10,0}, /* core4 sp_EL2 bit31 */
			{ 8444,10,0}, /* core4 sp_EL2 bit32 */
			{ 8445,10,0}, /* core4 sp_EL2 bit33 */
			{ 8446,10,0}, /* core4 sp_EL2 bit34 */
			{ 8447,10,0}, /* core4 sp_EL2 bit35 */
			{ 8036,10,0}, /* core4 sp_EL2 bit36 */
			{ 8037,10,0}, /* core4 sp_EL2 bit37 */
			{ 8038,10,0}, /* core4 sp_EL2 bit38 */
			{ 8039,10,0}, /* core4 sp_EL2 bit39 */
			{ 8440,10,0}, /* core4 sp_EL2 bit40 */
			{ 8441,10,0}, /* core4 sp_EL2 bit41 */
			{ 8442,10,0}, /* core4 sp_EL2 bit42 */
			{ 8443,10,0}, /* core4 sp_EL2 bit43 */
			{ 8408,10,0}, /* core4 sp_EL2 bit44 */
			{ 8409,10,0}, /* core4 sp_EL2 bit45 */
			{ 8410,10,0}, /* core4 sp_EL2 bit46 */
			{ 8411,10,0}, /* core4 sp_EL2 bit47 */
			{ 8558,10,0}, /* core4 sp_EL2 bit48 */
			{ 8559,10,0}, /* core4 sp_EL2 bit49 */
			{ 8560,10,0}, /* core4 sp_EL2 bit50 */
			{ 8561,10,0}, /* core4 sp_EL2 bit51 */
			{ 8352,10,0}, /* core4 sp_EL2 bit52 */
			{ 8353,10,0}, /* core4 sp_EL2 bit53 */
			{ 8354,10,0}, /* core4 sp_EL2 bit54 */
			{ 8355,10,0}, /* core4 sp_EL2 bit55 */
			{ 8372,10,0}, /* core4 sp_EL2 bit56 */
			{ 8373,10,0}, /* core4 sp_EL2 bit57 */
			{ 8374,10,0}, /* core4 sp_EL2 bit58 */
			{ 8375,10,0}, /* core4 sp_EL2 bit59 */
			{ 8400,10,0}, /* core4 sp_EL2 bit60 */
			{ 8401,10,0}, /* core4 sp_EL2 bit61 */
			{ 8402,10,0}, /* core4 sp_EL2 bit62 */
			{ 8403,10,0}, /* core4 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6499,10,0}, /* core4 sp_EL3 bit0 */
			{ 6498,10,0}, /* core4 sp_EL3 bit1 */
			{ 6497,10,0}, /* core4 sp_EL3 bit2 */
			{ 6496,10,0}, /* core4 sp_EL3 bit3 */
			{16302,10,0}, /* core4 sp_EL3 bit4 */
			{ 7235,10,0}, /* core4 sp_EL3 bit5 */
			{16301,10,0}, /* core4 sp_EL3 bit6 */
			{ 7234,10,0}, /* core4 sp_EL3 bit7 */
			{ 7247,10,0}, /* core4 sp_EL3 bit8 */
			{ 7246,10,0}, /* core4 sp_EL3 bit9 */
			{ 7245,10,0}, /* core4 sp_EL3 bit10 */
			{ 7244,10,0}, /* core4 sp_EL3 bit11 */
			{ 7243,10,0}, /* core4 sp_EL3 bit12 */
			{ 7242,10,0}, /* core4 sp_EL3 bit13 */
			{ 7241,10,0}, /* core4 sp_EL3 bit14 */
			{ 7233,10,0}, /* core4 sp_EL3 bit15 */
			{ 7240,10,0}, /* core4 sp_EL3 bit16 */
			{ 7223,10,0}, /* core4 sp_EL3 bit17 */
			{ 7222,10,0}, /* core4 sp_EL3 bit18 */
			{ 7221,10,0}, /* core4 sp_EL3 bit19 */
			{ 8663,10,0}, /* core4 sp_EL3 bit20 */
			{ 8662,10,0}, /* core4 sp_EL3 bit21 */
			{ 6445,10,0}, /* core4 sp_EL3 bit22 */
			{ 6463,10,0}, /* core4 sp_EL3 bit23 */
			{ 7232,10,0}, /* core4 sp_EL3 bit24 */
			{16288,10,0}, /* core4 sp_EL3 bit25 */
			{ 7220,10,0}, /* core4 sp_EL3 bit26 */
			{16287,10,0}, /* core4 sp_EL3 bit27 */
			{ 8661,10,0}, /* core4 sp_EL3 bit28 */
			{ 8660,10,0}, /* core4 sp_EL3 bit29 */
			{ 6444,10,0}, /* core4 sp_EL3 bit30 */
			{ 6446,10,0}, /* core4 sp_EL3 bit31 */
			{ 6816,10,0}, /* core4 sp_EL3 bit32 */
			{ 6817,10,0}, /* core4 sp_EL3 bit33 */
			{ 6818,10,0}, /* core4 sp_EL3 bit34 */
			{ 6819,10,0}, /* core4 sp_EL3 bit35 */
			{ 6808,10,0}, /* core4 sp_EL3 bit36 */
			{ 6809,10,0}, /* core4 sp_EL3 bit37 */
			{ 6810,10,0}, /* core4 sp_EL3 bit38 */
			{ 6811,10,0}, /* core4 sp_EL3 bit39 */
			{   56,10,0}, /* core4 sp_EL3 bit40 */
			{   57,10,0}, /* core4 sp_EL3 bit41 */
			{   58,10,0}, /* core4 sp_EL3 bit42 */
			{   59,10,0}, /* core4 sp_EL3 bit43 */
			{   80,10,0}, /* core4 sp_EL3 bit44 */
			{   81,10,0}, /* core4 sp_EL3 bit45 */
			{   82,10,0}, /* core4 sp_EL3 bit46 */
			{   83,10,0}, /* core4 sp_EL3 bit47 */
			{  144,10,0}, /* core4 sp_EL3 bit48 */
			{  145,10,0}, /* core4 sp_EL3 bit49 */
			{  146,10,0}, /* core4 sp_EL3 bit50 */
			{  147,10,0}, /* core4 sp_EL3 bit51 */
			{ 8088,10,0}, /* core4 sp_EL3 bit52 */
			{ 8089,10,0}, /* core4 sp_EL3 bit53 */
			{ 8090,10,0}, /* core4 sp_EL3 bit54 */
			{ 8091,10,0}, /* core4 sp_EL3 bit55 */
			{  132,10,0}, /* core4 sp_EL3 bit56 */
			{  133,10,0}, /* core4 sp_EL3 bit57 */
			{  134,10,0}, /* core4 sp_EL3 bit58 */
			{  135,10,0}, /* core4 sp_EL3 bit59 */
			{  120,10,0}, /* core4 sp_EL3 bit60 */
			{  121,10,0}, /* core4 sp_EL3 bit61 */
			{  122,10,0}, /* core4 sp_EL3 bit62 */
			{  123,10,0}, /* core4 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{16306,10,0}, /* core4 elr_EL1 bit0 */
			{16305,10,0}, /* core4 elr_EL1 bit1 */
			{16308,10,0}, /* core4 elr_EL1 bit2 */
			{16307,10,0}, /* core4 elr_EL1 bit3 */
			{ 7275,10,0}, /* core4 elr_EL1 bit4 */
			{ 7274,10,0}, /* core4 elr_EL1 bit5 */
			{ 5306,11,0}, /* core4 elr_EL1 bit6 */
			{ 7273,10,0}, /* core4 elr_EL1 bit7 */
			{ 7272,10,0}, /* core4 elr_EL1 bit8 */
			{ 7255,10,0}, /* core4 elr_EL1 bit9 */
			{ 7254,10,0}, /* core4 elr_EL1 bit10 */
			{ 7253,10,0}, /* core4 elr_EL1 bit11 */
			{ 7252,10,0}, /* core4 elr_EL1 bit12 */
			{ 7239,10,0}, /* core4 elr_EL1 bit13 */
			{ 7238,10,0}, /* core4 elr_EL1 bit14 */
			{ 7237,10,0}, /* core4 elr_EL1 bit15 */
			{ 7236,10,0}, /* core4 elr_EL1 bit16 */
			{  475,11,0}, /* core4 elr_EL1 bit17 */
			{  474,11,0}, /* core4 elr_EL1 bit18 */
			{ 8683,10,0}, /* core4 elr_EL1 bit19 */
			{ 6433,10,0}, /* core4 elr_EL1 bit20 */
			{ 8655,10,0}, /* core4 elr_EL1 bit21 */
			{ 8654,10,0}, /* core4 elr_EL1 bit22 */
			{ 8682,10,0}, /* core4 elr_EL1 bit23 */
			{16310,10,0}, /* core4 elr_EL1 bit24 */
			{16309,10,0}, /* core4 elr_EL1 bit25 */
			{  473,11,0}, /* core4 elr_EL1 bit26 */
			{  472,11,0}, /* core4 elr_EL1 bit27 */
			{ 6434,10,0}, /* core4 elr_EL1 bit28 */
			{ 6432,10,0}, /* core4 elr_EL1 bit29 */
			{ 6443,10,0}, /* core4 elr_EL1 bit30 */
			{ 6431,10,0}, /* core4 elr_EL1 bit31 */
			{  244,10,0}, /* core4 elr_EL1 bit32 */
			{  245,10,0}, /* core4 elr_EL1 bit33 */
			{  246,10,0}, /* core4 elr_EL1 bit34 */
			{  247,10,0}, /* core4 elr_EL1 bit35 */
			{  224,10,0}, /* core4 elr_EL1 bit36 */
			{  225,10,0}, /* core4 elr_EL1 bit37 */
			{  226,10,0}, /* core4 elr_EL1 bit38 */
			{  227,10,0}, /* core4 elr_EL1 bit39 */
			{  228,10,0}, /* core4 elr_EL1 bit40 */
			{  229,10,0}, /* core4 elr_EL1 bit41 */
			{  230,10,0}, /* core4 elr_EL1 bit42 */
			{  231,10,0}, /* core4 elr_EL1 bit43 */
			{  232,10,0}, /* core4 elr_EL1 bit44 */
			{  233,10,0}, /* core4 elr_EL1 bit45 */
			{  234,10,0}, /* core4 elr_EL1 bit46 */
			{  235,10,0}, /* core4 elr_EL1 bit47 */
			{ 7548,10,0}, /* core4 elr_EL1 bit48 */
			{ 7549,10,0}, /* core4 elr_EL1 bit49 */
			{ 7550,10,0}, /* core4 elr_EL1 bit50 */
			{ 7551,10,0}, /* core4 elr_EL1 bit51 */
			{ 7556,10,0}, /* core4 elr_EL1 bit52 */
			{ 7557,10,0}, /* core4 elr_EL1 bit53 */
			{ 7558,10,0}, /* core4 elr_EL1 bit54 */
			{ 7559,10,0}, /* core4 elr_EL1 bit55 */
			{ 7560,10,0}, /* core4 elr_EL1 bit56 */
			{ 7561,10,0}, /* core4 elr_EL1 bit57 */
			{ 7562,10,0}, /* core4 elr_EL1 bit58 */
			{ 7563,10,0}, /* core4 elr_EL1 bit59 */
			{ 7552,10,0}, /* core4 elr_EL1 bit60 */
			{ 7553,10,0}, /* core4 elr_EL1 bit61 */
			{ 7554,10,0}, /* core4 elr_EL1 bit62 */
			{ 7555,10,0}, /* core4 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 6467,10,0}, /* core4 elr_EL2 bit0 */
			{ 6466,10,0}, /* core4 elr_EL2 bit1 */
			{ 6465,10,0}, /* core4 elr_EL2 bit2 */
			{ 6464,10,0}, /* core4 elr_EL2 bit3 */
			{ 5322,11,0}, /* core4 elr_EL2 bit4 */
			{ 5314,11,0}, /* core4 elr_EL2 bit5 */
			{  461,11,0}, /* core4 elr_EL2 bit6 */
			{  460,11,0}, /* core4 elr_EL2 bit7 */
			{  447,11,0}, /* core4 elr_EL2 bit8 */
			{  446,11,0}, /* core4 elr_EL2 bit9 */
			{ 5313,11,0}, /* core4 elr_EL2 bit10 */
			{ 5315,11,0}, /* core4 elr_EL2 bit11 */
			{  459,11,0}, /* core4 elr_EL2 bit12 */
			{  458,11,0}, /* core4 elr_EL2 bit13 */
			{  463,11,0}, /* core4 elr_EL2 bit14 */
			{  462,11,0}, /* core4 elr_EL2 bit15 */
			{ 5335,11,0}, /* core4 elr_EL2 bit16 */
			{  467,11,0}, /* core4 elr_EL2 bit17 */
			{  466,11,0}, /* core4 elr_EL2 bit18 */
			{16290,10,0}, /* core4 elr_EL2 bit19 */
			{16289,10,0}, /* core4 elr_EL2 bit20 */
			{ 8675,10,0}, /* core4 elr_EL2 bit21 */
			{ 8674,10,0}, /* core4 elr_EL2 bit22 */
			{ 8677,10,0}, /* core4 elr_EL2 bit23 */
			{16292,10,0}, /* core4 elr_EL2 bit24 */
			{16291,10,0}, /* core4 elr_EL2 bit25 */
			{16294,10,0}, /* core4 elr_EL2 bit26 */
			{16293,10,0}, /* core4 elr_EL2 bit27 */
			{ 8676,10,0}, /* core4 elr_EL2 bit28 */
			{ 1999,10,0}, /* core4 elr_EL2 bit29 */
			{ 6454,10,0}, /* core4 elr_EL2 bit30 */
			{ 6455,10,0}, /* core4 elr_EL2 bit31 */
			{ 6820,10,0}, /* core4 elr_EL2 bit32 */
			{ 6821,10,0}, /* core4 elr_EL2 bit33 */
			{ 6822,10,0}, /* core4 elr_EL2 bit34 */
			{ 6823,10,0}, /* core4 elr_EL2 bit35 */
			{   12,10,0}, /* core4 elr_EL2 bit36 */
			{   13,10,0}, /* core4 elr_EL2 bit37 */
			{   14,10,0}, /* core4 elr_EL2 bit38 */
			{   15,10,0}, /* core4 elr_EL2 bit39 */
			{   92,10,0}, /* core4 elr_EL2 bit40 */
			{   93,10,0}, /* core4 elr_EL2 bit41 */
			{   94,10,0}, /* core4 elr_EL2 bit42 */
			{   95,10,0}, /* core4 elr_EL2 bit43 */
			{  100,10,0}, /* core4 elr_EL2 bit44 */
			{  101,10,0}, /* core4 elr_EL2 bit45 */
			{  102,10,0}, /* core4 elr_EL2 bit46 */
			{  103,10,0}, /* core4 elr_EL2 bit47 */
			{  152,10,0}, /* core4 elr_EL2 bit48 */
			{  153,10,0}, /* core4 elr_EL2 bit49 */
			{  154,10,0}, /* core4 elr_EL2 bit50 */
			{  155,10,0}, /* core4 elr_EL2 bit51 */
			{ 8092,10,0}, /* core4 elr_EL2 bit52 */
			{ 8093,10,0}, /* core4 elr_EL2 bit53 */
			{ 8094,10,0}, /* core4 elr_EL2 bit54 */
			{ 8095,10,0}, /* core4 elr_EL2 bit55 */
			{  136,10,0}, /* core4 elr_EL2 bit56 */
			{  137,10,0}, /* core4 elr_EL2 bit57 */
			{  138,10,0}, /* core4 elr_EL2 bit58 */
			{  139,10,0}, /* core4 elr_EL2 bit59 */
			{ 8068,10,0}, /* core4 elr_EL2 bit60 */
			{ 8069,10,0}, /* core4 elr_EL2 bit61 */
			{ 8070,10,0}, /* core4 elr_EL2 bit62 */
			{ 8071,10,0}, /* core4 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 7947,10,0}, /* core4 elr_EL3 bit0 */
			{ 7946,10,0}, /* core4 elr_EL3 bit1 */
			{ 7945,10,0}, /* core4 elr_EL3 bit2 */
			{ 7944,10,0}, /* core4 elr_EL3 bit3 */
			{ 6932,10,0}, /* core4 elr_EL3 bit4 */
			{ 6933,10,0}, /* core4 elr_EL3 bit5 */
			{ 6934,10,0}, /* core4 elr_EL3 bit6 */
			{ 6935,10,0}, /* core4 elr_EL3 bit7 */
			{ 6644,10,0}, /* core4 elr_EL3 bit8 */
			{ 6645,10,0}, /* core4 elr_EL3 bit9 */
			{ 6646,10,0}, /* core4 elr_EL3 bit10 */
			{ 6647,10,0}, /* core4 elr_EL3 bit11 */
			{ 6640,10,0}, /* core4 elr_EL3 bit12 */
			{ 6641,10,0}, /* core4 elr_EL3 bit13 */
			{ 6642,10,0}, /* core4 elr_EL3 bit14 */
			{ 6643,10,0}, /* core4 elr_EL3 bit15 */
			{ 6636,10,0}, /* core4 elr_EL3 bit16 */
			{ 6637,10,0}, /* core4 elr_EL3 bit17 */
			{ 6638,10,0}, /* core4 elr_EL3 bit18 */
			{ 6639,10,0}, /* core4 elr_EL3 bit19 */
			{ 7932,10,0}, /* core4 elr_EL3 bit20 */
			{ 7933,10,0}, /* core4 elr_EL3 bit21 */
			{ 7934,10,0}, /* core4 elr_EL3 bit22 */
			{ 7935,10,0}, /* core4 elr_EL3 bit23 */
			{ 6936,10,0}, /* core4 elr_EL3 bit24 */
			{ 6937,10,0}, /* core4 elr_EL3 bit25 */
			{ 6938,10,0}, /* core4 elr_EL3 bit26 */
			{ 6939,10,0}, /* core4 elr_EL3 bit27 */
			{ 7928,10,0}, /* core4 elr_EL3 bit28 */
			{ 7929,10,0}, /* core4 elr_EL3 bit29 */
			{ 7930,10,0}, /* core4 elr_EL3 bit30 */
			{ 7931,10,0}, /* core4 elr_EL3 bit31 */
			{ 8040,10,0}, /* core4 elr_EL3 bit32 */
			{ 8041,10,0}, /* core4 elr_EL3 bit33 */
			{ 8042,10,0}, /* core4 elr_EL3 bit34 */
			{ 8043,10,0}, /* core4 elr_EL3 bit35 */
			{ 8412,10,0}, /* core4 elr_EL3 bit36 */
			{ 8413,10,0}, /* core4 elr_EL3 bit37 */
			{ 8414,10,0}, /* core4 elr_EL3 bit38 */
			{ 8415,10,0}, /* core4 elr_EL3 bit39 */
			{ 8032,10,0}, /* core4 elr_EL3 bit40 */
			{ 8033,10,0}, /* core4 elr_EL3 bit41 */
			{ 8034,10,0}, /* core4 elr_EL3 bit42 */
			{ 8035,10,0}, /* core4 elr_EL3 bit43 */
			{ 8404,10,0}, /* core4 elr_EL3 bit44 */
			{ 8405,10,0}, /* core4 elr_EL3 bit45 */
			{ 8406,10,0}, /* core4 elr_EL3 bit46 */
			{ 8407,10,0}, /* core4 elr_EL3 bit47 */
			{ 8566,10,0}, /* core4 elr_EL3 bit48 */
			{ 8567,10,0}, /* core4 elr_EL3 bit49 */
			{ 8568,10,0}, /* core4 elr_EL3 bit50 */
			{ 8569,10,0}, /* core4 elr_EL3 bit51 */
			{ 8360,10,0}, /* core4 elr_EL3 bit52 */
			{ 8361,10,0}, /* core4 elr_EL3 bit53 */
			{ 8362,10,0}, /* core4 elr_EL3 bit54 */
			{ 8363,10,0}, /* core4 elr_EL3 bit55 */
			{ 8562,10,0}, /* core4 elr_EL3 bit56 */
			{ 8563,10,0}, /* core4 elr_EL3 bit57 */
			{ 8564,10,0}, /* core4 elr_EL3 bit58 */
			{ 8565,10,0}, /* core4 elr_EL3 bit59 */
			{ 8392,10,0}, /* core4 elr_EL3 bit60 */
			{ 8393,10,0}, /* core4 elr_EL3 bit61 */
			{ 8394,10,0}, /* core4 elr_EL3 bit62 */
			{ 8395,10,0}, /* core4 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{17159,10,0}, /* core4 raw_pc bit0 */
			{14566,10,0}, /* core4 raw_pc bit1 */
			{14567,10,0}, /* core4 raw_pc bit2 */
			{13688,10,0}, /* core4 raw_pc bit3 */
			{13689,10,0}, /* core4 raw_pc bit4 */
			{13690,10,0}, /* core4 raw_pc bit5 */
			{13691,10,0}, /* core4 raw_pc bit6 */
			{ 1390,11,0}, /* core4 raw_pc bit7 */
			{ 1391,11,0}, /* core4 raw_pc bit8 */
			{ 1392,11,0}, /* core4 raw_pc bit9 */
			{ 1393,11,0}, /* core4 raw_pc bit10 */
			{ 1410,11,0}, /* core4 raw_pc bit11 */
			{ 1411,11,0}, /* core4 raw_pc bit12 */
			{ 1412,11,0}, /* core4 raw_pc bit13 */
			{ 1413,11,0}, /* core4 raw_pc bit14 */
			{13896,10,0}, /* core4 raw_pc bit15 */
			{13897,10,0}, /* core4 raw_pc bit16 */
			{13898,10,0}, /* core4 raw_pc bit17 */
			{13899,10,0}, /* core4 raw_pc bit18 */
			{ 1426,11,0}, /* core4 raw_pc bit19 */
			{ 1427,11,0}, /* core4 raw_pc bit20 */
			{ 1428,11,0}, /* core4 raw_pc bit21 */
			{ 1429,11,0}, /* core4 raw_pc bit22 */
			{ 1430,11,0}, /* core4 raw_pc bit23 */
			{ 1431,11,0}, /* core4 raw_pc bit24 */
			{ 1432,11,0}, /* core4 raw_pc bit25 */
			{ 1433,11,0}, /* core4 raw_pc bit26 */
			{ 1434,11,0}, /* core4 raw_pc bit27 */
			{ 1435,11,0}, /* core4 raw_pc bit28 */
			{ 1436,11,0}, /* core4 raw_pc bit29 */
			{ 1437,11,0}, /* core4 raw_pc bit30 */
			{15938,10,0}, /* core4 raw_pc bit31 */
			{13480,10,0}, /* core4 raw_pc bit32 */
			{13481,10,0}, /* core4 raw_pc bit33 */
			{13482,10,0}, /* core4 raw_pc bit34 */
			{13483,10,0}, /* core4 raw_pc bit35 */
			{13476,10,0}, /* core4 raw_pc bit36 */
			{13477,10,0}, /* core4 raw_pc bit37 */
			{13478,10,0}, /* core4 raw_pc bit38 */
			{13479,10,0}, /* core4 raw_pc bit39 */
			{13496,10,0}, /* core4 raw_pc bit40 */
			{13497,10,0}, /* core4 raw_pc bit41 */
			{13498,10,0}, /* core4 raw_pc bit42 */
			{13499,10,0}, /* core4 raw_pc bit43 */
			{13500,10,0}, /* core4 raw_pc bit44 */
			{13501,10,0}, /* core4 raw_pc bit45 */
			{13502,10,0}, /* core4 raw_pc bit46 */
			{13503,10,0}, /* core4 raw_pc bit47 */
			{    0, 0,2}, /* core4 raw_pc bit48 */
			{    0, 0,2}, /* core4 raw_pc bit49 */
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
			{12164,10,0}, /* core4 pc_iss bit0 */
			{12165,10,0}, /* core4 pc_iss bit1 */
			{12166,10,0}, /* core4 pc_iss bit2 */
			{12167,10,0}, /* core4 pc_iss bit3 */
			{13860,10,0}, /* core4 pc_iss bit4 */
			{13861,10,0}, /* core4 pc_iss bit5 */
			{13862,10,0}, /* core4 pc_iss bit6 */
			{13863,10,0}, /* core4 pc_iss bit7 */
			{13420,10,0}, /* core4 pc_iss bit8 */
			{13421,10,0}, /* core4 pc_iss bit9 */
			{13422,10,0}, /* core4 pc_iss bit10 */
			{13423,10,0}, /* core4 pc_iss bit11 */
			{13428,10,0}, /* core4 pc_iss bit12 */
			{13429,10,0}, /* core4 pc_iss bit13 */
			{13430,10,0}, /* core4 pc_iss bit14 */
			{13431,10,0}, /* core4 pc_iss bit15 */
			{13408,10,0}, /* core4 pc_iss bit16 */
			{13409,10,0}, /* core4 pc_iss bit17 */
			{13410,10,0}, /* core4 pc_iss bit18 */
			{13411,10,0}, /* core4 pc_iss bit19 */
			{13412,10,0}, /* core4 pc_iss bit20 */
			{13413,10,0}, /* core4 pc_iss bit21 */
			{13414,10,0}, /* core4 pc_iss bit22 */
			{13415,10,0}, /* core4 pc_iss bit23 */
			{13424,10,0}, /* core4 pc_iss bit24 */
			{13425,10,0}, /* core4 pc_iss bit25 */
			{13426,10,0}, /* core4 pc_iss bit26 */
			{13427,10,0}, /* core4 pc_iss bit27 */
			{13416,10,0}, /* core4 pc_iss bit28 */
			{13417,10,0}, /* core4 pc_iss bit29 */
			{13418,10,0}, /* core4 pc_iss bit30 */
			{13419,10,0}, /* core4 pc_iss bit31 */
			{13508,10,0}, /* core4 pc_iss bit32 */
			{13509,10,0}, /* core4 pc_iss bit33 */
			{13510,10,0}, /* core4 pc_iss bit34 */
			{13511,10,0}, /* core4 pc_iss bit35 */
			{13504,10,0}, /* core4 pc_iss bit36 */
			{13505,10,0}, /* core4 pc_iss bit37 */
			{13506,10,0}, /* core4 pc_iss bit38 */
			{13507,10,0}, /* core4 pc_iss bit39 */
			{13520,10,0}, /* core4 pc_iss bit40 */
			{13521,10,0}, /* core4 pc_iss bit41 */
			{13522,10,0}, /* core4 pc_iss bit42 */
			{13523,10,0}, /* core4 pc_iss bit43 */
			{13524,10,0}, /* core4 pc_iss bit44 */
			{13525,10,0}, /* core4 pc_iss bit45 */
			{13526,10,0}, /* core4 pc_iss bit46 */
			{13527,10,0}, /* core4 pc_iss bit47 */
			{13540,10,0}, /* core4 pc_iss bit48 */
			{13541,10,0}, /* core4 pc_iss bit49 */
			{13542,10,0}, /* core4 pc_iss bit50 */
			{13543,10,0}, /* core4 pc_iss bit51 */
			{13528,10,0}, /* core4 pc_iss bit52 */
			{13529,10,0}, /* core4 pc_iss bit53 */
			{13530,10,0}, /* core4 pc_iss bit54 */
			{13531,10,0}, /* core4 pc_iss bit55 */
			{13544,10,0}, /* core4 pc_iss bit56 */
			{13545,10,0}, /* core4 pc_iss bit57 */
			{13546,10,0}, /* core4 pc_iss bit58 */
			{13547,10,0}, /* core4 pc_iss bit59 */
			{13548,10,0}, /* core4 pc_iss bit60 */
			{13549,10,0}, /* core4 pc_iss bit61 */
			{13550,10,0}, /* core4 pc_iss bit62 */
			{13551,10,0}, /* core4 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{17168,10,0}, /* core4 full_pc_wr bit0 */
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
			{14569,10,0}, /* core4 full_pc_ex1 bit0 */
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
			{17170,10,0}, /* core4 full_pc_ex2 bit0 */
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
	},
	{		/* core 5 */ 
			.pc = {{
			{ 7160,12,0}, /* core5 pc bit0 */
			{ 7161,12,0}, /* core5 pc bit1 */
			{ 7162,12,0}, /* core5 pc bit2 */
			{ 7163,12,0}, /* core5 pc bit3 */
			{ 7344,12,0}, /* core5 pc bit4 */
			{ 7345,12,0}, /* core5 pc bit5 */
			{ 7346,12,0}, /* core5 pc bit6 */
			{ 7347,12,0}, /* core5 pc bit7 */
			{ 7356,12,0}, /* core5 pc bit8 */
			{ 7357,12,0}, /* core5 pc bit9 */
			{ 7358,12,0}, /* core5 pc bit10 */
			{ 7359,12,0}, /* core5 pc bit11 */
			{ 6704,12,0}, /* core5 pc bit12 */
			{ 6705,12,0}, /* core5 pc bit13 */
			{ 6706,12,0}, /* core5 pc bit14 */
			{ 6707,12,0}, /* core5 pc bit15 */
			{ 6708,12,0}, /* core5 pc bit16 */
			{ 6709,12,0}, /* core5 pc bit17 */
			{ 6710,12,0}, /* core5 pc bit18 */
			{ 6711,12,0}, /* core5 pc bit19 */
			{10968,12,0}, /* core5 pc bit20 */
			{10969,12,0}, /* core5 pc bit21 */
			{10970,12,0}, /* core5 pc bit22 */
			{10971,12,0}, /* core5 pc bit23 */
			{ 7348,12,0}, /* core5 pc bit24 */
			{ 7349,12,0}, /* core5 pc bit25 */
			{ 7350,12,0}, /* core5 pc bit26 */
			{ 7351,12,0}, /* core5 pc bit27 */
			{ 6700,12,0}, /* core5 pc bit28 */
			{ 6701,12,0}, /* core5 pc bit29 */
			{ 6702,12,0}, /* core5 pc bit30 */
			{ 6703,12,0}, /* core5 pc bit31 */
			{17044,12,0}, /* core5 pc bit32 */
			{17045,12,0}, /* core5 pc bit33 */
			{17046,12,0}, /* core5 pc bit34 */
			{17047,12,0}, /* core5 pc bit35 */
			{17040,12,0}, /* core5 pc bit36 */
			{17041,12,0}, /* core5 pc bit37 */
			{17042,12,0}, /* core5 pc bit38 */
			{17043,12,0}, /* core5 pc bit39 */
			{17036,12,0}, /* core5 pc bit40 */
			{17037,12,0}, /* core5 pc bit41 */
			{17038,12,0}, /* core5 pc bit42 */
			{17039,12,0}, /* core5 pc bit43 */
			{17032,12,0}, /* core5 pc bit44 */
			{17033,12,0}, /* core5 pc bit45 */
			{17034,12,0}, /* core5 pc bit46 */
			{17035,12,0}, /* core5 pc bit47 */
			{17016,12,0}, /* core5 pc bit48 */
			{17017,12,0}, /* core5 pc bit49 */
			{17018,12,0}, /* core5 pc bit50 */
			{17019,12,0}, /* core5 pc bit51 */
			{17020,12,0}, /* core5 pc bit52 */
			{17021,12,0}, /* core5 pc bit53 */
			{17022,12,0}, /* core5 pc bit54 */
			{17023,12,0}, /* core5 pc bit55 */
			{17028,12,0}, /* core5 pc bit56 */
			{17029,12,0}, /* core5 pc bit57 */
			{17030,12,0}, /* core5 pc bit58 */
			{17031,12,0}, /* core5 pc bit59 */
			{17024,12,0}, /* core5 pc bit60 */
			{17025,12,0}, /* core5 pc bit61 */
			{17026,12,0}, /* core5 pc bit62 */
			{17027,12,0}, /* core5 pc bit63 */
			}},
			.sp32 = {{
			{ 6923,12,0}, /* core5 sp32 bit0 */
			{ 6922,12,0}, /* core5 sp32 bit1 */
			{ 6921,12,0}, /* core5 sp32 bit2 */
			{ 6920,12,0}, /* core5 sp32 bit3 */
			{ 6588,12,0}, /* core5 sp32 bit4 */
			{ 6589,12,0}, /* core5 sp32 bit5 */
			{ 6590,12,0}, /* core5 sp32 bit6 */
			{ 6591,12,0}, /* core5 sp32 bit7 */
			{ 6676,12,0}, /* core5 sp32 bit8 */
			{ 6677,12,0}, /* core5 sp32 bit9 */
			{ 6678,12,0}, /* core5 sp32 bit10 */
			{ 6679,12,0}, /* core5 sp32 bit11 */
			{ 6656,12,0}, /* core5 sp32 bit12 */
			{ 6657,12,0}, /* core5 sp32 bit13 */
			{ 6658,12,0}, /* core5 sp32 bit14 */
			{ 6659,12,0}, /* core5 sp32 bit15 */
			{ 6660,12,0}, /* core5 sp32 bit16 */
			{ 6661,12,0}, /* core5 sp32 bit17 */
			{ 6662,12,0}, /* core5 sp32 bit18 */
			{ 6663,12,0}, /* core5 sp32 bit19 */
			{ 6912,12,0}, /* core5 sp32 bit20 */
			{ 6913,12,0}, /* core5 sp32 bit21 */
			{ 6914,12,0}, /* core5 sp32 bit22 */
			{ 6915,12,0}, /* core5 sp32 bit23 */
			{ 6628,12,0}, /* core5 sp32 bit24 */
			{ 6629,12,0}, /* core5 sp32 bit25 */
			{ 6630,12,0}, /* core5 sp32 bit26 */
			{ 6631,12,0}, /* core5 sp32 bit27 */
			{ 6916,12,0}, /* core5 sp32 bit28 */
			{ 6917,12,0}, /* core5 sp32 bit29 */
			{ 6918,12,0}, /* core5 sp32 bit30 */
			{ 6919,12,0}, /* core5 sp32 bit31 */
			{ 7624,12,0}, /* core5 sp32 bit32 */
			{ 7625,12,0}, /* core5 sp32 bit33 */
			{ 7626,12,0}, /* core5 sp32 bit34 */
			{ 7627,12,0}, /* core5 sp32 bit35 */
			{ 7656,12,0}, /* core5 sp32 bit36 */
			{ 7657,12,0}, /* core5 sp32 bit37 */
			{ 7658,12,0}, /* core5 sp32 bit38 */
			{ 7659,12,0}, /* core5 sp32 bit39 */
			{ 7688,12,0}, /* core5 sp32 bit40 */
			{ 7689,12,0}, /* core5 sp32 bit41 */
			{ 7690,12,0}, /* core5 sp32 bit42 */
			{ 7691,12,0}, /* core5 sp32 bit43 */
			{ 8436,12,0}, /* core5 sp32 bit44 */
			{ 8437,12,0}, /* core5 sp32 bit45 */
			{ 8438,12,0}, /* core5 sp32 bit46 */
			{ 8439,12,0}, /* core5 sp32 bit47 */
			{ 8248,12,0}, /* core5 sp32 bit48 */
			{ 8249,12,0}, /* core5 sp32 bit49 */
			{ 8250,12,0}, /* core5 sp32 bit50 */
			{ 8251,12,0}, /* core5 sp32 bit51 */
			{ 8244,12,0}, /* core5 sp32 bit52 */
			{ 8245,12,0}, /* core5 sp32 bit53 */
			{ 8246,12,0}, /* core5 sp32 bit54 */
			{ 8247,12,0}, /* core5 sp32 bit55 */
			{ 8252,12,0}, /* core5 sp32 bit56 */
			{ 8253,12,0}, /* core5 sp32 bit57 */
			{ 8254,12,0}, /* core5 sp32 bit58 */
			{ 8255,12,0}, /* core5 sp32 bit59 */
			{ 7596,12,0}, /* core5 sp32 bit60 */
			{ 7597,12,0}, /* core5 sp32 bit61 */
			{ 7598,12,0}, /* core5 sp32 bit62 */
			{ 7599,12,0}, /* core5 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7916,12,0}, /* core5 fp32 bit0 */
			{ 7917,12,0}, /* core5 fp32 bit1 */
			{ 7918,12,0}, /* core5 fp32 bit2 */
			{ 7919,12,0}, /* core5 fp32 bit3 */
			{ 3892,13,0}, /* core5 fp32 bit4 */
			{ 3893,13,0}, /* core5 fp32 bit5 */
			{ 3894,13,0}, /* core5 fp32 bit6 */
			{ 3895,13,0}, /* core5 fp32 bit7 */
			{10104,12,0}, /* core5 fp32 bit8 */
			{10105,12,0}, /* core5 fp32 bit9 */
			{10106,12,0}, /* core5 fp32 bit10 */
			{10107,12,0}, /* core5 fp32 bit11 */
			{10108,12,0}, /* core5 fp32 bit12 */
			{10109,12,0}, /* core5 fp32 bit13 */
			{10110,12,0}, /* core5 fp32 bit14 */
			{10111,12,0}, /* core5 fp32 bit15 */
			{ 3946,13,0}, /* core5 fp32 bit16 */
			{ 3947,13,0}, /* core5 fp32 bit17 */
			{ 3948,13,0}, /* core5 fp32 bit18 */
			{ 3949,13,0}, /* core5 fp32 bit19 */
			{ 7876,12,0}, /* core5 fp32 bit20 */
			{ 7877,12,0}, /* core5 fp32 bit21 */
			{ 7878,12,0}, /* core5 fp32 bit22 */
			{ 7879,12,0}, /* core5 fp32 bit23 */
			{ 3906,13,0}, /* core5 fp32 bit24 */
			{ 3907,13,0}, /* core5 fp32 bit25 */
			{ 3908,13,0}, /* core5 fp32 bit26 */
			{ 3909,13,0}, /* core5 fp32 bit27 */
			{ 7880,12,0}, /* core5 fp32 bit28 */
			{ 7881,12,0}, /* core5 fp32 bit29 */
			{ 7882,12,0}, /* core5 fp32 bit30 */
			{ 7883,12,0}, /* core5 fp32 bit31 */
			{ 7860,12,0}, /* core5 fp32 bit32 */
			{ 7861,12,0}, /* core5 fp32 bit33 */
			{ 7862,12,0}, /* core5 fp32 bit34 */
			{ 7863,12,0}, /* core5 fp32 bit35 */
			{ 7804,12,0}, /* core5 fp32 bit36 */
			{ 7805,12,0}, /* core5 fp32 bit37 */
			{ 7806,12,0}, /* core5 fp32 bit38 */
			{ 7807,12,0}, /* core5 fp32 bit39 */
			{ 7772,12,0}, /* core5 fp32 bit40 */
			{ 7773,12,0}, /* core5 fp32 bit41 */
			{ 7774,12,0}, /* core5 fp32 bit42 */
			{ 7775,12,0}, /* core5 fp32 bit43 */
			{ 7744,12,0}, /* core5 fp32 bit44 */
			{ 7745,12,0}, /* core5 fp32 bit45 */
			{ 7746,12,0}, /* core5 fp32 bit46 */
			{ 7747,12,0}, /* core5 fp32 bit47 */
			{11296,12,0}, /* core5 fp32 bit48 */
			{11297,12,0}, /* core5 fp32 bit49 */
			{11298,12,0}, /* core5 fp32 bit50 */
			{11299,12,0}, /* core5 fp32 bit51 */
			{11288,12,0}, /* core5 fp32 bit52 */
			{11289,12,0}, /* core5 fp32 bit53 */
			{11290,12,0}, /* core5 fp32 bit54 */
			{11291,12,0}, /* core5 fp32 bit55 */
			{ 7500,12,0}, /* core5 fp32 bit56 */
			{ 7501,12,0}, /* core5 fp32 bit57 */
			{ 7502,12,0}, /* core5 fp32 bit58 */
			{ 7503,12,0}, /* core5 fp32 bit59 */
			{11268,12,0}, /* core5 fp32 bit60 */
			{11269,12,0}, /* core5 fp32 bit61 */
			{11270,12,0}, /* core5 fp32 bit62 */
			{11271,12,0}, /* core5 fp32 bit63 */
			}},
			.fp64 = {{
			{ 8687,12,0}, /* core5 fp64 bit0 */
			{ 8685,12,0}, /* core5 fp64 bit1 */
			{ 8686,12,0}, /* core5 fp64 bit2 */
			{ 5329,13,0}, /* core5 fp64 bit3 */
			{ 8684,12,0}, /* core5 fp64 bit4 */
			{ 5312,13,0}, /* core5 fp64 bit5 */
			{  481,13,0}, /* core5 fp64 bit6 */
			{  480,13,0}, /* core5 fp64 bit7 */
			{ 5307,13,0}, /* core5 fp64 bit8 */
			{  485,13,0}, /* core5 fp64 bit9 */
			{  484,13,0}, /* core5 fp64 bit10 */
			{ 5311,13,0}, /* core5 fp64 bit11 */
			{ 5310,13,0}, /* core5 fp64 bit12 */
			{  453,13,0}, /* core5 fp64 bit13 */
			{  452,13,0}, /* core5 fp64 bit14 */
			{ 5308,13,0}, /* core5 fp64 bit15 */
			{16318,12,0}, /* core5 fp64 bit16 */
			{  455,13,0}, /* core5 fp64 bit17 */
			{  454,13,0}, /* core5 fp64 bit18 */
			{16314,12,0}, /* core5 fp64 bit19 */
			{16313,12,0}, /* core5 fp64 bit20 */
			{ 8659,12,0}, /* core5 fp64 bit21 */
			{ 8658,12,0}, /* core5 fp64 bit22 */
			{16317,12,0}, /* core5 fp64 bit23 */
			{16312,12,0}, /* core5 fp64 bit24 */
			{16311,12,0}, /* core5 fp64 bit25 */
			{16316,12,0}, /* core5 fp64 bit26 */
			{ 5332,13,0}, /* core5 fp64 bit27 */
			{ 8657,12,0}, /* core5 fp64 bit28 */
			{16315,12,0}, /* core5 fp64 bit29 */
			{ 8656,12,0}, /* core5 fp64 bit30 */
			{ 5328,13,0}, /* core5 fp64 bit31 */
			{   24,12,0}, /* core5 fp64 bit32 */
			{   25,12,0}, /* core5 fp64 bit33 */
			{   26,12,0}, /* core5 fp64 bit34 */
			{   27,12,0}, /* core5 fp64 bit35 */
			{   28,12,0}, /* core5 fp64 bit36 */
			{   29,12,0}, /* core5 fp64 bit37 */
			{   30,12,0}, /* core5 fp64 bit38 */
			{   31,12,0}, /* core5 fp64 bit39 */
			{   52,12,0}, /* core5 fp64 bit40 */
			{   53,12,0}, /* core5 fp64 bit41 */
			{   54,12,0}, /* core5 fp64 bit42 */
			{   55,12,0}, /* core5 fp64 bit43 */
			{  112,12,0}, /* core5 fp64 bit44 */
			{  113,12,0}, /* core5 fp64 bit45 */
			{  114,12,0}, /* core5 fp64 bit46 */
			{  115,12,0}, /* core5 fp64 bit47 */
			{  156,12,0}, /* core5 fp64 bit48 */
			{  157,12,0}, /* core5 fp64 bit49 */
			{  158,12,0}, /* core5 fp64 bit50 */
			{  159,12,0}, /* core5 fp64 bit51 */
			{  168,12,0}, /* core5 fp64 bit52 */
			{  169,12,0}, /* core5 fp64 bit53 */
			{  170,12,0}, /* core5 fp64 bit54 */
			{  171,12,0}, /* core5 fp64 bit55 */
			{  172,12,0}, /* core5 fp64 bit56 */
			{  173,12,0}, /* core5 fp64 bit57 */
			{  174,12,0}, /* core5 fp64 bit58 */
			{  175,12,0}, /* core5 fp64 bit59 */
			{ 7564,12,0}, /* core5 fp64 bit60 */
			{ 7565,12,0}, /* core5 fp64 bit61 */
			{ 7566,12,0}, /* core5 fp64 bit62 */
			{ 7567,12,0}, /* core5 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{16282,12,0}, /* core5 sp_EL0 bit0 */
			{16281,12,0}, /* core5 sp_EL0 bit1 */
			{16280,12,0}, /* core5 sp_EL0 bit2 */
			{16279,12,0}, /* core5 sp_EL0 bit3 */
			{ 6524,12,0}, /* core5 sp_EL0 bit4 */
			{ 6525,12,0}, /* core5 sp_EL0 bit5 */
			{ 6526,12,0}, /* core5 sp_EL0 bit6 */
			{ 6527,12,0}, /* core5 sp_EL0 bit7 */
			{ 7116,12,0}, /* core5 sp_EL0 bit8 */
			{ 7117,12,0}, /* core5 sp_EL0 bit9 */
			{ 7118,12,0}, /* core5 sp_EL0 bit10 */
			{ 7119,12,0}, /* core5 sp_EL0 bit11 */
			{ 7128,12,0}, /* core5 sp_EL0 bit12 */
			{ 7129,12,0}, /* core5 sp_EL0 bit13 */
			{ 7130,12,0}, /* core5 sp_EL0 bit14 */
			{ 7131,12,0}, /* core5 sp_EL0 bit15 */
			{ 6992,12,0}, /* core5 sp_EL0 bit16 */
			{ 6993,12,0}, /* core5 sp_EL0 bit17 */
			{ 6994,12,0}, /* core5 sp_EL0 bit18 */
			{ 6995,12,0}, /* core5 sp_EL0 bit19 */
			{ 6712,12,0}, /* core5 sp_EL0 bit20 */
			{ 6713,12,0}, /* core5 sp_EL0 bit21 */
			{ 6714,12,0}, /* core5 sp_EL0 bit22 */
			{ 6715,12,0}, /* core5 sp_EL0 bit23 */
			{ 6544,12,0}, /* core5 sp_EL0 bit24 */
			{ 6545,12,0}, /* core5 sp_EL0 bit25 */
			{ 6546,12,0}, /* core5 sp_EL0 bit26 */
			{ 6547,12,0}, /* core5 sp_EL0 bit27 */
			{ 6756,12,0}, /* core5 sp_EL0 bit28 */
			{ 6757,12,0}, /* core5 sp_EL0 bit29 */
			{ 6758,12,0}, /* core5 sp_EL0 bit30 */
			{ 6759,12,0}, /* core5 sp_EL0 bit31 */
			{   32,12,0}, /* core5 sp_EL0 bit32 */
			{   33,12,0}, /* core5 sp_EL0 bit33 */
			{   34,12,0}, /* core5 sp_EL0 bit34 */
			{   35,12,0}, /* core5 sp_EL0 bit35 */
			{   48,12,0}, /* core5 sp_EL0 bit36 */
			{   49,12,0}, /* core5 sp_EL0 bit37 */
			{   50,12,0}, /* core5 sp_EL0 bit38 */
			{   51,12,0}, /* core5 sp_EL0 bit39 */
			{   60,12,0}, /* core5 sp_EL0 bit40 */
			{   61,12,0}, /* core5 sp_EL0 bit41 */
			{   62,12,0}, /* core5 sp_EL0 bit42 */
			{   63,12,0}, /* core5 sp_EL0 bit43 */
			{  108,12,0}, /* core5 sp_EL0 bit44 */
			{  109,12,0}, /* core5 sp_EL0 bit45 */
			{  110,12,0}, /* core5 sp_EL0 bit46 */
			{  111,12,0}, /* core5 sp_EL0 bit47 */
			{ 8380,12,0}, /* core5 sp_EL0 bit48 */
			{ 8381,12,0}, /* core5 sp_EL0 bit49 */
			{ 8382,12,0}, /* core5 sp_EL0 bit50 */
			{ 8383,12,0}, /* core5 sp_EL0 bit51 */
			{ 8376,12,0}, /* core5 sp_EL0 bit52 */
			{ 8377,12,0}, /* core5 sp_EL0 bit53 */
			{ 8378,12,0}, /* core5 sp_EL0 bit54 */
			{ 8379,12,0}, /* core5 sp_EL0 bit55 */
			{ 8384,12,0}, /* core5 sp_EL0 bit56 */
			{ 8385,12,0}, /* core5 sp_EL0 bit57 */
			{ 8386,12,0}, /* core5 sp_EL0 bit58 */
			{ 8387,12,0}, /* core5 sp_EL0 bit59 */
			{ 8388,12,0}, /* core5 sp_EL0 bit60 */
			{ 8389,12,0}, /* core5 sp_EL0 bit61 */
			{ 8390,12,0}, /* core5 sp_EL0 bit62 */
			{ 8391,12,0}, /* core5 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6575,12,0}, /* core5 sp_EL1 bit0 */
			{ 6574,12,0}, /* core5 sp_EL1 bit1 */
			{ 6573,12,0}, /* core5 sp_EL1 bit2 */
			{ 6572,12,0}, /* core5 sp_EL1 bit3 */
			{ 5326,13,0}, /* core5 sp_EL1 bit4 */
			{  489,13,0}, /* core5 sp_EL1 bit5 */
			{  488,13,0}, /* core5 sp_EL1 bit6 */
			{  487,13,0}, /* core5 sp_EL1 bit7 */
			{  486,13,0}, /* core5 sp_EL1 bit8 */
			{ 7311,12,0}, /* core5 sp_EL1 bit9 */
			{ 7259,12,0}, /* core5 sp_EL1 bit10 */
			{ 7258,12,0}, /* core5 sp_EL1 bit11 */
			{ 7257,12,0}, /* core5 sp_EL1 bit12 */
			{ 7256,12,0}, /* core5 sp_EL1 bit13 */
			{ 5305,13,0}, /* core5 sp_EL1 bit14 */
			{ 7310,12,0}, /* core5 sp_EL1 bit15 */
			{  491,13,0}, /* core5 sp_EL1 bit16 */
			{ 7309,12,0}, /* core5 sp_EL1 bit17 */
			{ 7308,12,0}, /* core5 sp_EL1 bit18 */
			{ 6587,12,0}, /* core5 sp_EL1 bit19 */
			{ 5325,13,0}, /* core5 sp_EL1 bit20 */
			{ 6586,12,0}, /* core5 sp_EL1 bit21 */
			{ 6585,12,0}, /* core5 sp_EL1 bit22 */
			{ 6584,12,0}, /* core5 sp_EL1 bit23 */
			{  490,13,0}, /* core5 sp_EL1 bit24 */
			{16320,12,0}, /* core5 sp_EL1 bit25 */
			{16319,12,0}, /* core5 sp_EL1 bit26 */
			{10137,12,0}, /* core5 sp_EL1 bit27 */
			{10136,12,0}, /* core5 sp_EL1 bit28 */
			{ 8693,12,0}, /* core5 sp_EL1 bit29 */
			{ 8692,12,0}, /* core5 sp_EL1 bit30 */
			{ 5327,13,0}, /* core5 sp_EL1 bit31 */
			{ 6824,12,0}, /* core5 sp_EL1 bit32 */
			{ 6825,12,0}, /* core5 sp_EL1 bit33 */
			{ 6826,12,0}, /* core5 sp_EL1 bit34 */
			{ 6827,12,0}, /* core5 sp_EL1 bit35 */
			{ 6800,12,0}, /* core5 sp_EL1 bit36 */
			{ 6801,12,0}, /* core5 sp_EL1 bit37 */
			{ 6802,12,0}, /* core5 sp_EL1 bit38 */
			{ 6803,12,0}, /* core5 sp_EL1 bit39 */
			{ 6804,12,0}, /* core5 sp_EL1 bit40 */
			{ 6805,12,0}, /* core5 sp_EL1 bit41 */
			{ 6806,12,0}, /* core5 sp_EL1 bit42 */
			{ 6807,12,0}, /* core5 sp_EL1 bit43 */
			{   68,12,0}, /* core5 sp_EL1 bit44 */
			{   69,12,0}, /* core5 sp_EL1 bit45 */
			{   70,12,0}, /* core5 sp_EL1 bit46 */
			{   71,12,0}, /* core5 sp_EL1 bit47 */
			{  148,12,0}, /* core5 sp_EL1 bit48 */
			{  149,12,0}, /* core5 sp_EL1 bit49 */
			{  150,12,0}, /* core5 sp_EL1 bit50 */
			{  151,12,0}, /* core5 sp_EL1 bit51 */
			{  140,12,0}, /* core5 sp_EL1 bit52 */
			{  141,12,0}, /* core5 sp_EL1 bit53 */
			{  142,12,0}, /* core5 sp_EL1 bit54 */
			{  143,12,0}, /* core5 sp_EL1 bit55 */
			{  128,12,0}, /* core5 sp_EL1 bit56 */
			{  129,12,0}, /* core5 sp_EL1 bit57 */
			{  130,12,0}, /* core5 sp_EL1 bit58 */
			{  131,12,0}, /* core5 sp_EL1 bit59 */
			{  124,12,0}, /* core5 sp_EL1 bit60 */
			{  125,12,0}, /* core5 sp_EL1 bit61 */
			{  126,12,0}, /* core5 sp_EL1 bit62 */
			{  127,12,0}, /* core5 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{16266,12,0}, /* core5 sp_EL2 bit0 */
			{16265,12,0}, /* core5 sp_EL2 bit1 */
			{16276,12,0}, /* core5 sp_EL2 bit2 */
			{16275,12,0}, /* core5 sp_EL2 bit3 */
			{ 6512,12,0}, /* core5 sp_EL2 bit4 */
			{ 6513,12,0}, /* core5 sp_EL2 bit5 */
			{ 6514,12,0}, /* core5 sp_EL2 bit6 */
			{ 6515,12,0}, /* core5 sp_EL2 bit7 */
			{ 7040,12,0}, /* core5 sp_EL2 bit8 */
			{ 7041,12,0}, /* core5 sp_EL2 bit9 */
			{ 7042,12,0}, /* core5 sp_EL2 bit10 */
			{ 7043,12,0}, /* core5 sp_EL2 bit11 */
			{ 7004,12,0}, /* core5 sp_EL2 bit12 */
			{ 7005,12,0}, /* core5 sp_EL2 bit13 */
			{ 7006,12,0}, /* core5 sp_EL2 bit14 */
			{ 7007,12,0}, /* core5 sp_EL2 bit15 */
			{ 7224,12,0}, /* core5 sp_EL2 bit16 */
			{ 7225,12,0}, /* core5 sp_EL2 bit17 */
			{ 7226,12,0}, /* core5 sp_EL2 bit18 */
			{ 7227,12,0}, /* core5 sp_EL2 bit19 */
			{ 6768,12,0}, /* core5 sp_EL2 bit20 */
			{ 6769,12,0}, /* core5 sp_EL2 bit21 */
			{ 6770,12,0}, /* core5 sp_EL2 bit22 */
			{ 6771,12,0}, /* core5 sp_EL2 bit23 */
			{ 6556,12,0}, /* core5 sp_EL2 bit24 */
			{ 6557,12,0}, /* core5 sp_EL2 bit25 */
			{ 6558,12,0}, /* core5 sp_EL2 bit26 */
			{ 6559,12,0}, /* core5 sp_EL2 bit27 */
			{ 6764,12,0}, /* core5 sp_EL2 bit28 */
			{ 6765,12,0}, /* core5 sp_EL2 bit29 */
			{ 6766,12,0}, /* core5 sp_EL2 bit30 */
			{ 6767,12,0}, /* core5 sp_EL2 bit31 */
			{ 8444,12,0}, /* core5 sp_EL2 bit32 */
			{ 8445,12,0}, /* core5 sp_EL2 bit33 */
			{ 8446,12,0}, /* core5 sp_EL2 bit34 */
			{ 8447,12,0}, /* core5 sp_EL2 bit35 */
			{ 8036,12,0}, /* core5 sp_EL2 bit36 */
			{ 8037,12,0}, /* core5 sp_EL2 bit37 */
			{ 8038,12,0}, /* core5 sp_EL2 bit38 */
			{ 8039,12,0}, /* core5 sp_EL2 bit39 */
			{ 8440,12,0}, /* core5 sp_EL2 bit40 */
			{ 8441,12,0}, /* core5 sp_EL2 bit41 */
			{ 8442,12,0}, /* core5 sp_EL2 bit42 */
			{ 8443,12,0}, /* core5 sp_EL2 bit43 */
			{ 8408,12,0}, /* core5 sp_EL2 bit44 */
			{ 8409,12,0}, /* core5 sp_EL2 bit45 */
			{ 8410,12,0}, /* core5 sp_EL2 bit46 */
			{ 8411,12,0}, /* core5 sp_EL2 bit47 */
			{ 8558,12,0}, /* core5 sp_EL2 bit48 */
			{ 8559,12,0}, /* core5 sp_EL2 bit49 */
			{ 8560,12,0}, /* core5 sp_EL2 bit50 */
			{ 8561,12,0}, /* core5 sp_EL2 bit51 */
			{ 8352,12,0}, /* core5 sp_EL2 bit52 */
			{ 8353,12,0}, /* core5 sp_EL2 bit53 */
			{ 8354,12,0}, /* core5 sp_EL2 bit54 */
			{ 8355,12,0}, /* core5 sp_EL2 bit55 */
			{ 8372,12,0}, /* core5 sp_EL2 bit56 */
			{ 8373,12,0}, /* core5 sp_EL2 bit57 */
			{ 8374,12,0}, /* core5 sp_EL2 bit58 */
			{ 8375,12,0}, /* core5 sp_EL2 bit59 */
			{ 8400,12,0}, /* core5 sp_EL2 bit60 */
			{ 8401,12,0}, /* core5 sp_EL2 bit61 */
			{ 8402,12,0}, /* core5 sp_EL2 bit62 */
			{ 8403,12,0}, /* core5 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6499,12,0}, /* core5 sp_EL3 bit0 */
			{ 6498,12,0}, /* core5 sp_EL3 bit1 */
			{ 6497,12,0}, /* core5 sp_EL3 bit2 */
			{ 6496,12,0}, /* core5 sp_EL3 bit3 */
			{16302,12,0}, /* core5 sp_EL3 bit4 */
			{ 7235,12,0}, /* core5 sp_EL3 bit5 */
			{16301,12,0}, /* core5 sp_EL3 bit6 */
			{ 7234,12,0}, /* core5 sp_EL3 bit7 */
			{ 7247,12,0}, /* core5 sp_EL3 bit8 */
			{ 7246,12,0}, /* core5 sp_EL3 bit9 */
			{ 7245,12,0}, /* core5 sp_EL3 bit10 */
			{ 7244,12,0}, /* core5 sp_EL3 bit11 */
			{ 7243,12,0}, /* core5 sp_EL3 bit12 */
			{ 7242,12,0}, /* core5 sp_EL3 bit13 */
			{ 7241,12,0}, /* core5 sp_EL3 bit14 */
			{ 7233,12,0}, /* core5 sp_EL3 bit15 */
			{ 7240,12,0}, /* core5 sp_EL3 bit16 */
			{ 7223,12,0}, /* core5 sp_EL3 bit17 */
			{ 7222,12,0}, /* core5 sp_EL3 bit18 */
			{ 7221,12,0}, /* core5 sp_EL3 bit19 */
			{ 8663,12,0}, /* core5 sp_EL3 bit20 */
			{ 8662,12,0}, /* core5 sp_EL3 bit21 */
			{ 6445,12,0}, /* core5 sp_EL3 bit22 */
			{ 6463,12,0}, /* core5 sp_EL3 bit23 */
			{ 7232,12,0}, /* core5 sp_EL3 bit24 */
			{16288,12,0}, /* core5 sp_EL3 bit25 */
			{ 7220,12,0}, /* core5 sp_EL3 bit26 */
			{16287,12,0}, /* core5 sp_EL3 bit27 */
			{ 8661,12,0}, /* core5 sp_EL3 bit28 */
			{ 8660,12,0}, /* core5 sp_EL3 bit29 */
			{ 6444,12,0}, /* core5 sp_EL3 bit30 */
			{ 6446,12,0}, /* core5 sp_EL3 bit31 */
			{ 6816,12,0}, /* core5 sp_EL3 bit32 */
			{ 6817,12,0}, /* core5 sp_EL3 bit33 */
			{ 6818,12,0}, /* core5 sp_EL3 bit34 */
			{ 6819,12,0}, /* core5 sp_EL3 bit35 */
			{ 6808,12,0}, /* core5 sp_EL3 bit36 */
			{ 6809,12,0}, /* core5 sp_EL3 bit37 */
			{ 6810,12,0}, /* core5 sp_EL3 bit38 */
			{ 6811,12,0}, /* core5 sp_EL3 bit39 */
			{   56,12,0}, /* core5 sp_EL3 bit40 */
			{   57,12,0}, /* core5 sp_EL3 bit41 */
			{   58,12,0}, /* core5 sp_EL3 bit42 */
			{   59,12,0}, /* core5 sp_EL3 bit43 */
			{   80,12,0}, /* core5 sp_EL3 bit44 */
			{   81,12,0}, /* core5 sp_EL3 bit45 */
			{   82,12,0}, /* core5 sp_EL3 bit46 */
			{   83,12,0}, /* core5 sp_EL3 bit47 */
			{  144,12,0}, /* core5 sp_EL3 bit48 */
			{  145,12,0}, /* core5 sp_EL3 bit49 */
			{  146,12,0}, /* core5 sp_EL3 bit50 */
			{  147,12,0}, /* core5 sp_EL3 bit51 */
			{ 8088,12,0}, /* core5 sp_EL3 bit52 */
			{ 8089,12,0}, /* core5 sp_EL3 bit53 */
			{ 8090,12,0}, /* core5 sp_EL3 bit54 */
			{ 8091,12,0}, /* core5 sp_EL3 bit55 */
			{  132,12,0}, /* core5 sp_EL3 bit56 */
			{  133,12,0}, /* core5 sp_EL3 bit57 */
			{  134,12,0}, /* core5 sp_EL3 bit58 */
			{  135,12,0}, /* core5 sp_EL3 bit59 */
			{  120,12,0}, /* core5 sp_EL3 bit60 */
			{  121,12,0}, /* core5 sp_EL3 bit61 */
			{  122,12,0}, /* core5 sp_EL3 bit62 */
			{  123,12,0}, /* core5 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{16306,12,0}, /* core5 elr_EL1 bit0 */
			{16305,12,0}, /* core5 elr_EL1 bit1 */
			{16308,12,0}, /* core5 elr_EL1 bit2 */
			{16307,12,0}, /* core5 elr_EL1 bit3 */
			{ 7275,12,0}, /* core5 elr_EL1 bit4 */
			{ 7274,12,0}, /* core5 elr_EL1 bit5 */
			{ 5306,13,0}, /* core5 elr_EL1 bit6 */
			{ 7273,12,0}, /* core5 elr_EL1 bit7 */
			{ 7272,12,0}, /* core5 elr_EL1 bit8 */
			{ 7255,12,0}, /* core5 elr_EL1 bit9 */
			{ 7254,12,0}, /* core5 elr_EL1 bit10 */
			{ 7253,12,0}, /* core5 elr_EL1 bit11 */
			{ 7252,12,0}, /* core5 elr_EL1 bit12 */
			{ 7239,12,0}, /* core5 elr_EL1 bit13 */
			{ 7238,12,0}, /* core5 elr_EL1 bit14 */
			{ 7237,12,0}, /* core5 elr_EL1 bit15 */
			{ 7236,12,0}, /* core5 elr_EL1 bit16 */
			{  475,13,0}, /* core5 elr_EL1 bit17 */
			{  474,13,0}, /* core5 elr_EL1 bit18 */
			{ 8683,12,0}, /* core5 elr_EL1 bit19 */
			{ 6433,12,0}, /* core5 elr_EL1 bit20 */
			{ 8655,12,0}, /* core5 elr_EL1 bit21 */
			{ 8654,12,0}, /* core5 elr_EL1 bit22 */
			{ 8682,12,0}, /* core5 elr_EL1 bit23 */
			{16310,12,0}, /* core5 elr_EL1 bit24 */
			{16309,12,0}, /* core5 elr_EL1 bit25 */
			{  473,13,0}, /* core5 elr_EL1 bit26 */
			{  472,13,0}, /* core5 elr_EL1 bit27 */
			{ 6434,12,0}, /* core5 elr_EL1 bit28 */
			{ 6432,12,0}, /* core5 elr_EL1 bit29 */
			{ 6443,12,0}, /* core5 elr_EL1 bit30 */
			{ 6431,12,0}, /* core5 elr_EL1 bit31 */
			{  244,12,0}, /* core5 elr_EL1 bit32 */
			{  245,12,0}, /* core5 elr_EL1 bit33 */
			{  246,12,0}, /* core5 elr_EL1 bit34 */
			{  247,12,0}, /* core5 elr_EL1 bit35 */
			{  224,12,0}, /* core5 elr_EL1 bit36 */
			{  225,12,0}, /* core5 elr_EL1 bit37 */
			{  226,12,0}, /* core5 elr_EL1 bit38 */
			{  227,12,0}, /* core5 elr_EL1 bit39 */
			{  228,12,0}, /* core5 elr_EL1 bit40 */
			{  229,12,0}, /* core5 elr_EL1 bit41 */
			{  230,12,0}, /* core5 elr_EL1 bit42 */
			{  231,12,0}, /* core5 elr_EL1 bit43 */
			{  232,12,0}, /* core5 elr_EL1 bit44 */
			{  233,12,0}, /* core5 elr_EL1 bit45 */
			{  234,12,0}, /* core5 elr_EL1 bit46 */
			{  235,12,0}, /* core5 elr_EL1 bit47 */
			{ 7548,12,0}, /* core5 elr_EL1 bit48 */
			{ 7549,12,0}, /* core5 elr_EL1 bit49 */
			{ 7550,12,0}, /* core5 elr_EL1 bit50 */
			{ 7551,12,0}, /* core5 elr_EL1 bit51 */
			{ 7556,12,0}, /* core5 elr_EL1 bit52 */
			{ 7557,12,0}, /* core5 elr_EL1 bit53 */
			{ 7558,12,0}, /* core5 elr_EL1 bit54 */
			{ 7559,12,0}, /* core5 elr_EL1 bit55 */
			{ 7560,12,0}, /* core5 elr_EL1 bit56 */
			{ 7561,12,0}, /* core5 elr_EL1 bit57 */
			{ 7562,12,0}, /* core5 elr_EL1 bit58 */
			{ 7563,12,0}, /* core5 elr_EL1 bit59 */
			{ 7552,12,0}, /* core5 elr_EL1 bit60 */
			{ 7553,12,0}, /* core5 elr_EL1 bit61 */
			{ 7554,12,0}, /* core5 elr_EL1 bit62 */
			{ 7555,12,0}, /* core5 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 6467,12,0}, /* core5 elr_EL2 bit0 */
			{ 6466,12,0}, /* core5 elr_EL2 bit1 */
			{ 6465,12,0}, /* core5 elr_EL2 bit2 */
			{ 6464,12,0}, /* core5 elr_EL2 bit3 */
			{ 5322,13,0}, /* core5 elr_EL2 bit4 */
			{ 5314,13,0}, /* core5 elr_EL2 bit5 */
			{  461,13,0}, /* core5 elr_EL2 bit6 */
			{  460,13,0}, /* core5 elr_EL2 bit7 */
			{  447,13,0}, /* core5 elr_EL2 bit8 */
			{  446,13,0}, /* core5 elr_EL2 bit9 */
			{ 5313,13,0}, /* core5 elr_EL2 bit10 */
			{ 5315,13,0}, /* core5 elr_EL2 bit11 */
			{  459,13,0}, /* core5 elr_EL2 bit12 */
			{  458,13,0}, /* core5 elr_EL2 bit13 */
			{  463,13,0}, /* core5 elr_EL2 bit14 */
			{  462,13,0}, /* core5 elr_EL2 bit15 */
			{ 5335,13,0}, /* core5 elr_EL2 bit16 */
			{  467,13,0}, /* core5 elr_EL2 bit17 */
			{  466,13,0}, /* core5 elr_EL2 bit18 */
			{16290,12,0}, /* core5 elr_EL2 bit19 */
			{16289,12,0}, /* core5 elr_EL2 bit20 */
			{ 8675,12,0}, /* core5 elr_EL2 bit21 */
			{ 8674,12,0}, /* core5 elr_EL2 bit22 */
			{ 8677,12,0}, /* core5 elr_EL2 bit23 */
			{16292,12,0}, /* core5 elr_EL2 bit24 */
			{16291,12,0}, /* core5 elr_EL2 bit25 */
			{16294,12,0}, /* core5 elr_EL2 bit26 */
			{16293,12,0}, /* core5 elr_EL2 bit27 */
			{ 8676,12,0}, /* core5 elr_EL2 bit28 */
			{ 1999,12,0}, /* core5 elr_EL2 bit29 */
			{ 6454,12,0}, /* core5 elr_EL2 bit30 */
			{ 6455,12,0}, /* core5 elr_EL2 bit31 */
			{ 6820,12,0}, /* core5 elr_EL2 bit32 */
			{ 6821,12,0}, /* core5 elr_EL2 bit33 */
			{ 6822,12,0}, /* core5 elr_EL2 bit34 */
			{ 6823,12,0}, /* core5 elr_EL2 bit35 */
			{   12,12,0}, /* core5 elr_EL2 bit36 */
			{   13,12,0}, /* core5 elr_EL2 bit37 */
			{   14,12,0}, /* core5 elr_EL2 bit38 */
			{   15,12,0}, /* core5 elr_EL2 bit39 */
			{   92,12,0}, /* core5 elr_EL2 bit40 */
			{   93,12,0}, /* core5 elr_EL2 bit41 */
			{   94,12,0}, /* core5 elr_EL2 bit42 */
			{   95,12,0}, /* core5 elr_EL2 bit43 */
			{  100,12,0}, /* core5 elr_EL2 bit44 */
			{  101,12,0}, /* core5 elr_EL2 bit45 */
			{  102,12,0}, /* core5 elr_EL2 bit46 */
			{  103,12,0}, /* core5 elr_EL2 bit47 */
			{  152,12,0}, /* core5 elr_EL2 bit48 */
			{  153,12,0}, /* core5 elr_EL2 bit49 */
			{  154,12,0}, /* core5 elr_EL2 bit50 */
			{  155,12,0}, /* core5 elr_EL2 bit51 */
			{ 8092,12,0}, /* core5 elr_EL2 bit52 */
			{ 8093,12,0}, /* core5 elr_EL2 bit53 */
			{ 8094,12,0}, /* core5 elr_EL2 bit54 */
			{ 8095,12,0}, /* core5 elr_EL2 bit55 */
			{  136,12,0}, /* core5 elr_EL2 bit56 */
			{  137,12,0}, /* core5 elr_EL2 bit57 */
			{  138,12,0}, /* core5 elr_EL2 bit58 */
			{  139,12,0}, /* core5 elr_EL2 bit59 */
			{ 8068,12,0}, /* core5 elr_EL2 bit60 */
			{ 8069,12,0}, /* core5 elr_EL2 bit61 */
			{ 8070,12,0}, /* core5 elr_EL2 bit62 */
			{ 8071,12,0}, /* core5 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 7947,12,0}, /* core5 elr_EL3 bit0 */
			{ 7946,12,0}, /* core5 elr_EL3 bit1 */
			{ 7945,12,0}, /* core5 elr_EL3 bit2 */
			{ 7944,12,0}, /* core5 elr_EL3 bit3 */
			{ 6932,12,0}, /* core5 elr_EL3 bit4 */
			{ 6933,12,0}, /* core5 elr_EL3 bit5 */
			{ 6934,12,0}, /* core5 elr_EL3 bit6 */
			{ 6935,12,0}, /* core5 elr_EL3 bit7 */
			{ 6644,12,0}, /* core5 elr_EL3 bit8 */
			{ 6645,12,0}, /* core5 elr_EL3 bit9 */
			{ 6646,12,0}, /* core5 elr_EL3 bit10 */
			{ 6647,12,0}, /* core5 elr_EL3 bit11 */
			{ 6640,12,0}, /* core5 elr_EL3 bit12 */
			{ 6641,12,0}, /* core5 elr_EL3 bit13 */
			{ 6642,12,0}, /* core5 elr_EL3 bit14 */
			{ 6643,12,0}, /* core5 elr_EL3 bit15 */
			{ 6636,12,0}, /* core5 elr_EL3 bit16 */
			{ 6637,12,0}, /* core5 elr_EL3 bit17 */
			{ 6638,12,0}, /* core5 elr_EL3 bit18 */
			{ 6639,12,0}, /* core5 elr_EL3 bit19 */
			{ 7932,12,0}, /* core5 elr_EL3 bit20 */
			{ 7933,12,0}, /* core5 elr_EL3 bit21 */
			{ 7934,12,0}, /* core5 elr_EL3 bit22 */
			{ 7935,12,0}, /* core5 elr_EL3 bit23 */
			{ 6936,12,0}, /* core5 elr_EL3 bit24 */
			{ 6937,12,0}, /* core5 elr_EL3 bit25 */
			{ 6938,12,0}, /* core5 elr_EL3 bit26 */
			{ 6939,12,0}, /* core5 elr_EL3 bit27 */
			{ 7928,12,0}, /* core5 elr_EL3 bit28 */
			{ 7929,12,0}, /* core5 elr_EL3 bit29 */
			{ 7930,12,0}, /* core5 elr_EL3 bit30 */
			{ 7931,12,0}, /* core5 elr_EL3 bit31 */
			{ 8040,12,0}, /* core5 elr_EL3 bit32 */
			{ 8041,12,0}, /* core5 elr_EL3 bit33 */
			{ 8042,12,0}, /* core5 elr_EL3 bit34 */
			{ 8043,12,0}, /* core5 elr_EL3 bit35 */
			{ 8412,12,0}, /* core5 elr_EL3 bit36 */
			{ 8413,12,0}, /* core5 elr_EL3 bit37 */
			{ 8414,12,0}, /* core5 elr_EL3 bit38 */
			{ 8415,12,0}, /* core5 elr_EL3 bit39 */
			{ 8032,12,0}, /* core5 elr_EL3 bit40 */
			{ 8033,12,0}, /* core5 elr_EL3 bit41 */
			{ 8034,12,0}, /* core5 elr_EL3 bit42 */
			{ 8035,12,0}, /* core5 elr_EL3 bit43 */
			{ 8404,12,0}, /* core5 elr_EL3 bit44 */
			{ 8405,12,0}, /* core5 elr_EL3 bit45 */
			{ 8406,12,0}, /* core5 elr_EL3 bit46 */
			{ 8407,12,0}, /* core5 elr_EL3 bit47 */
			{ 8566,12,0}, /* core5 elr_EL3 bit48 */
			{ 8567,12,0}, /* core5 elr_EL3 bit49 */
			{ 8568,12,0}, /* core5 elr_EL3 bit50 */
			{ 8569,12,0}, /* core5 elr_EL3 bit51 */
			{ 8360,12,0}, /* core5 elr_EL3 bit52 */
			{ 8361,12,0}, /* core5 elr_EL3 bit53 */
			{ 8362,12,0}, /* core5 elr_EL3 bit54 */
			{ 8363,12,0}, /* core5 elr_EL3 bit55 */
			{ 8562,12,0}, /* core5 elr_EL3 bit56 */
			{ 8563,12,0}, /* core5 elr_EL3 bit57 */
			{ 8564,12,0}, /* core5 elr_EL3 bit58 */
			{ 8565,12,0}, /* core5 elr_EL3 bit59 */
			{ 8392,12,0}, /* core5 elr_EL3 bit60 */
			{ 8393,12,0}, /* core5 elr_EL3 bit61 */
			{ 8394,12,0}, /* core5 elr_EL3 bit62 */
			{ 8395,12,0}, /* core5 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{17159,12,0}, /* core5 raw_pc bit0 */
			{14566,12,0}, /* core5 raw_pc bit1 */
			{14567,12,0}, /* core5 raw_pc bit2 */
			{13688,12,0}, /* core5 raw_pc bit3 */
			{13689,12,0}, /* core5 raw_pc bit4 */
			{13690,12,0}, /* core5 raw_pc bit5 */
			{13691,12,0}, /* core5 raw_pc bit6 */
			{ 1390,13,0}, /* core5 raw_pc bit7 */
			{ 1391,13,0}, /* core5 raw_pc bit8 */
			{ 1392,13,0}, /* core5 raw_pc bit9 */
			{ 1393,13,0}, /* core5 raw_pc bit10 */
			{ 1410,13,0}, /* core5 raw_pc bit11 */
			{ 1411,13,0}, /* core5 raw_pc bit12 */
			{ 1412,13,0}, /* core5 raw_pc bit13 */
			{ 1413,13,0}, /* core5 raw_pc bit14 */
			{13896,12,0}, /* core5 raw_pc bit15 */
			{13897,12,0}, /* core5 raw_pc bit16 */
			{13898,12,0}, /* core5 raw_pc bit17 */
			{13899,12,0}, /* core5 raw_pc bit18 */
			{ 1426,13,0}, /* core5 raw_pc bit19 */
			{ 1427,13,0}, /* core5 raw_pc bit20 */
			{ 1428,13,0}, /* core5 raw_pc bit21 */
			{ 1429,13,0}, /* core5 raw_pc bit22 */
			{ 1430,13,0}, /* core5 raw_pc bit23 */
			{ 1431,13,0}, /* core5 raw_pc bit24 */
			{ 1432,13,0}, /* core5 raw_pc bit25 */
			{ 1433,13,0}, /* core5 raw_pc bit26 */
			{ 1434,13,0}, /* core5 raw_pc bit27 */
			{ 1435,13,0}, /* core5 raw_pc bit28 */
			{ 1436,13,0}, /* core5 raw_pc bit29 */
			{ 1437,13,0}, /* core5 raw_pc bit30 */
			{15938,12,0}, /* core5 raw_pc bit31 */
			{13480,12,0}, /* core5 raw_pc bit32 */
			{13481,12,0}, /* core5 raw_pc bit33 */
			{13482,12,0}, /* core5 raw_pc bit34 */
			{13483,12,0}, /* core5 raw_pc bit35 */
			{13476,12,0}, /* core5 raw_pc bit36 */
			{13477,12,0}, /* core5 raw_pc bit37 */
			{13478,12,0}, /* core5 raw_pc bit38 */
			{13479,12,0}, /* core5 raw_pc bit39 */
			{13496,12,0}, /* core5 raw_pc bit40 */
			{13497,12,0}, /* core5 raw_pc bit41 */
			{13498,12,0}, /* core5 raw_pc bit42 */
			{13499,12,0}, /* core5 raw_pc bit43 */
			{13500,12,0}, /* core5 raw_pc bit44 */
			{13501,12,0}, /* core5 raw_pc bit45 */
			{13502,12,0}, /* core5 raw_pc bit46 */
			{13503,12,0}, /* core5 raw_pc bit47 */
			{    0, 0,2}, /* core5 raw_pc bit48 */
			{    0, 0,2}, /* core5 raw_pc bit49 */
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
			{12164,12,0}, /* core5 pc_iss bit0 */
			{12165,12,0}, /* core5 pc_iss bit1 */
			{12166,12,0}, /* core5 pc_iss bit2 */
			{12167,12,0}, /* core5 pc_iss bit3 */
			{13860,12,0}, /* core5 pc_iss bit4 */
			{13861,12,0}, /* core5 pc_iss bit5 */
			{13862,12,0}, /* core5 pc_iss bit6 */
			{13863,12,0}, /* core5 pc_iss bit7 */
			{13420,12,0}, /* core5 pc_iss bit8 */
			{13421,12,0}, /* core5 pc_iss bit9 */
			{13422,12,0}, /* core5 pc_iss bit10 */
			{13423,12,0}, /* core5 pc_iss bit11 */
			{13428,12,0}, /* core5 pc_iss bit12 */
			{13429,12,0}, /* core5 pc_iss bit13 */
			{13430,12,0}, /* core5 pc_iss bit14 */
			{13431,12,0}, /* core5 pc_iss bit15 */
			{13408,12,0}, /* core5 pc_iss bit16 */
			{13409,12,0}, /* core5 pc_iss bit17 */
			{13410,12,0}, /* core5 pc_iss bit18 */
			{13411,12,0}, /* core5 pc_iss bit19 */
			{13412,12,0}, /* core5 pc_iss bit20 */
			{13413,12,0}, /* core5 pc_iss bit21 */
			{13414,12,0}, /* core5 pc_iss bit22 */
			{13415,12,0}, /* core5 pc_iss bit23 */
			{13424,12,0}, /* core5 pc_iss bit24 */
			{13425,12,0}, /* core5 pc_iss bit25 */
			{13426,12,0}, /* core5 pc_iss bit26 */
			{13427,12,0}, /* core5 pc_iss bit27 */
			{13416,12,0}, /* core5 pc_iss bit28 */
			{13417,12,0}, /* core5 pc_iss bit29 */
			{13418,12,0}, /* core5 pc_iss bit30 */
			{13419,12,0}, /* core5 pc_iss bit31 */
			{13508,12,0}, /* core5 pc_iss bit32 */
			{13509,12,0}, /* core5 pc_iss bit33 */
			{13510,12,0}, /* core5 pc_iss bit34 */
			{13511,12,0}, /* core5 pc_iss bit35 */
			{13504,12,0}, /* core5 pc_iss bit36 */
			{13505,12,0}, /* core5 pc_iss bit37 */
			{13506,12,0}, /* core5 pc_iss bit38 */
			{13507,12,0}, /* core5 pc_iss bit39 */
			{13520,12,0}, /* core5 pc_iss bit40 */
			{13521,12,0}, /* core5 pc_iss bit41 */
			{13522,12,0}, /* core5 pc_iss bit42 */
			{13523,12,0}, /* core5 pc_iss bit43 */
			{13524,12,0}, /* core5 pc_iss bit44 */
			{13525,12,0}, /* core5 pc_iss bit45 */
			{13526,12,0}, /* core5 pc_iss bit46 */
			{13527,12,0}, /* core5 pc_iss bit47 */
			{13540,12,0}, /* core5 pc_iss bit48 */
			{13541,12,0}, /* core5 pc_iss bit49 */
			{13542,12,0}, /* core5 pc_iss bit50 */
			{13543,12,0}, /* core5 pc_iss bit51 */
			{13528,12,0}, /* core5 pc_iss bit52 */
			{13529,12,0}, /* core5 pc_iss bit53 */
			{13530,12,0}, /* core5 pc_iss bit54 */
			{13531,12,0}, /* core5 pc_iss bit55 */
			{13544,12,0}, /* core5 pc_iss bit56 */
			{13545,12,0}, /* core5 pc_iss bit57 */
			{13546,12,0}, /* core5 pc_iss bit58 */
			{13547,12,0}, /* core5 pc_iss bit59 */
			{13548,12,0}, /* core5 pc_iss bit60 */
			{13549,12,0}, /* core5 pc_iss bit61 */
			{13550,12,0}, /* core5 pc_iss bit62 */
			{13551,12,0}, /* core5 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{17168,12,0}, /* core5 full_pc_wr bit0 */
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
			{14569,12,0}, /* core5 full_pc_ex1 bit0 */
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
			{17170,12,0}, /* core5 full_pc_ex2 bit0 */
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
	},
	{		/* core 6 */ 
			.pc = {{
			{ 7160,14,0}, /* core6 pc bit0 */
			{ 7161,14,0}, /* core6 pc bit1 */
			{ 7162,14,0}, /* core6 pc bit2 */
			{ 7163,14,0}, /* core6 pc bit3 */
			{ 7344,14,0}, /* core6 pc bit4 */
			{ 7345,14,0}, /* core6 pc bit5 */
			{ 7346,14,0}, /* core6 pc bit6 */
			{ 7347,14,0}, /* core6 pc bit7 */
			{ 7356,14,0}, /* core6 pc bit8 */
			{ 7357,14,0}, /* core6 pc bit9 */
			{ 7358,14,0}, /* core6 pc bit10 */
			{ 7359,14,0}, /* core6 pc bit11 */
			{ 6704,14,0}, /* core6 pc bit12 */
			{ 6705,14,0}, /* core6 pc bit13 */
			{ 6706,14,0}, /* core6 pc bit14 */
			{ 6707,14,0}, /* core6 pc bit15 */
			{ 6708,14,0}, /* core6 pc bit16 */
			{ 6709,14,0}, /* core6 pc bit17 */
			{ 6710,14,0}, /* core6 pc bit18 */
			{ 6711,14,0}, /* core6 pc bit19 */
			{10968,14,0}, /* core6 pc bit20 */
			{10969,14,0}, /* core6 pc bit21 */
			{10970,14,0}, /* core6 pc bit22 */
			{10971,14,0}, /* core6 pc bit23 */
			{ 7348,14,0}, /* core6 pc bit24 */
			{ 7349,14,0}, /* core6 pc bit25 */
			{ 7350,14,0}, /* core6 pc bit26 */
			{ 7351,14,0}, /* core6 pc bit27 */
			{ 6700,14,0}, /* core6 pc bit28 */
			{ 6701,14,0}, /* core6 pc bit29 */
			{ 6702,14,0}, /* core6 pc bit30 */
			{ 6703,14,0}, /* core6 pc bit31 */
			{17044,14,0}, /* core6 pc bit32 */
			{17045,14,0}, /* core6 pc bit33 */
			{17046,14,0}, /* core6 pc bit34 */
			{17047,14,0}, /* core6 pc bit35 */
			{17040,14,0}, /* core6 pc bit36 */
			{17041,14,0}, /* core6 pc bit37 */
			{17042,14,0}, /* core6 pc bit38 */
			{17043,14,0}, /* core6 pc bit39 */
			{17036,14,0}, /* core6 pc bit40 */
			{17037,14,0}, /* core6 pc bit41 */
			{17038,14,0}, /* core6 pc bit42 */
			{17039,14,0}, /* core6 pc bit43 */
			{17032,14,0}, /* core6 pc bit44 */
			{17033,14,0}, /* core6 pc bit45 */
			{17034,14,0}, /* core6 pc bit46 */
			{17035,14,0}, /* core6 pc bit47 */
			{17016,14,0}, /* core6 pc bit48 */
			{17017,14,0}, /* core6 pc bit49 */
			{17018,14,0}, /* core6 pc bit50 */
			{17019,14,0}, /* core6 pc bit51 */
			{17020,14,0}, /* core6 pc bit52 */
			{17021,14,0}, /* core6 pc bit53 */
			{17022,14,0}, /* core6 pc bit54 */
			{17023,14,0}, /* core6 pc bit55 */
			{17028,14,0}, /* core6 pc bit56 */
			{17029,14,0}, /* core6 pc bit57 */
			{17030,14,0}, /* core6 pc bit58 */
			{17031,14,0}, /* core6 pc bit59 */
			{17024,14,0}, /* core6 pc bit60 */
			{17025,14,0}, /* core6 pc bit61 */
			{17026,14,0}, /* core6 pc bit62 */
			{17027,14,0}, /* core6 pc bit63 */
			}},
			.sp32 = {{
			{ 6923,14,0}, /* core6 sp32 bit0 */
			{ 6922,14,0}, /* core6 sp32 bit1 */
			{ 6921,14,0}, /* core6 sp32 bit2 */
			{ 6920,14,0}, /* core6 sp32 bit3 */
			{ 6588,14,0}, /* core6 sp32 bit4 */
			{ 6589,14,0}, /* core6 sp32 bit5 */
			{ 6590,14,0}, /* core6 sp32 bit6 */
			{ 6591,14,0}, /* core6 sp32 bit7 */
			{ 6676,14,0}, /* core6 sp32 bit8 */
			{ 6677,14,0}, /* core6 sp32 bit9 */
			{ 6678,14,0}, /* core6 sp32 bit10 */
			{ 6679,14,0}, /* core6 sp32 bit11 */
			{ 6656,14,0}, /* core6 sp32 bit12 */
			{ 6657,14,0}, /* core6 sp32 bit13 */
			{ 6658,14,0}, /* core6 sp32 bit14 */
			{ 6659,14,0}, /* core6 sp32 bit15 */
			{ 6660,14,0}, /* core6 sp32 bit16 */
			{ 6661,14,0}, /* core6 sp32 bit17 */
			{ 6662,14,0}, /* core6 sp32 bit18 */
			{ 6663,14,0}, /* core6 sp32 bit19 */
			{ 6912,14,0}, /* core6 sp32 bit20 */
			{ 6913,14,0}, /* core6 sp32 bit21 */
			{ 6914,14,0}, /* core6 sp32 bit22 */
			{ 6915,14,0}, /* core6 sp32 bit23 */
			{ 6628,14,0}, /* core6 sp32 bit24 */
			{ 6629,14,0}, /* core6 sp32 bit25 */
			{ 6630,14,0}, /* core6 sp32 bit26 */
			{ 6631,14,0}, /* core6 sp32 bit27 */
			{ 6916,14,0}, /* core6 sp32 bit28 */
			{ 6917,14,0}, /* core6 sp32 bit29 */
			{ 6918,14,0}, /* core6 sp32 bit30 */
			{ 6919,14,0}, /* core6 sp32 bit31 */
			{ 7624,14,0}, /* core6 sp32 bit32 */
			{ 7625,14,0}, /* core6 sp32 bit33 */
			{ 7626,14,0}, /* core6 sp32 bit34 */
			{ 7627,14,0}, /* core6 sp32 bit35 */
			{ 7656,14,0}, /* core6 sp32 bit36 */
			{ 7657,14,0}, /* core6 sp32 bit37 */
			{ 7658,14,0}, /* core6 sp32 bit38 */
			{ 7659,14,0}, /* core6 sp32 bit39 */
			{ 7688,14,0}, /* core6 sp32 bit40 */
			{ 7689,14,0}, /* core6 sp32 bit41 */
			{ 7690,14,0}, /* core6 sp32 bit42 */
			{ 7691,14,0}, /* core6 sp32 bit43 */
			{ 8436,14,0}, /* core6 sp32 bit44 */
			{ 8437,14,0}, /* core6 sp32 bit45 */
			{ 8438,14,0}, /* core6 sp32 bit46 */
			{ 8439,14,0}, /* core6 sp32 bit47 */
			{ 8248,14,0}, /* core6 sp32 bit48 */
			{ 8249,14,0}, /* core6 sp32 bit49 */
			{ 8250,14,0}, /* core6 sp32 bit50 */
			{ 8251,14,0}, /* core6 sp32 bit51 */
			{ 8244,14,0}, /* core6 sp32 bit52 */
			{ 8245,14,0}, /* core6 sp32 bit53 */
			{ 8246,14,0}, /* core6 sp32 bit54 */
			{ 8247,14,0}, /* core6 sp32 bit55 */
			{ 8252,14,0}, /* core6 sp32 bit56 */
			{ 8253,14,0}, /* core6 sp32 bit57 */
			{ 8254,14,0}, /* core6 sp32 bit58 */
			{ 8255,14,0}, /* core6 sp32 bit59 */
			{ 7596,14,0}, /* core6 sp32 bit60 */
			{ 7597,14,0}, /* core6 sp32 bit61 */
			{ 7598,14,0}, /* core6 sp32 bit62 */
			{ 7599,14,0}, /* core6 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7916,14,0}, /* core6 fp32 bit0 */
			{ 7917,14,0}, /* core6 fp32 bit1 */
			{ 7918,14,0}, /* core6 fp32 bit2 */
			{ 7919,14,0}, /* core6 fp32 bit3 */
			{ 3892,15,0}, /* core6 fp32 bit4 */
			{ 3893,15,0}, /* core6 fp32 bit5 */
			{ 3894,15,0}, /* core6 fp32 bit6 */
			{ 3895,15,0}, /* core6 fp32 bit7 */
			{10104,14,0}, /* core6 fp32 bit8 */
			{10105,14,0}, /* core6 fp32 bit9 */
			{10106,14,0}, /* core6 fp32 bit10 */
			{10107,14,0}, /* core6 fp32 bit11 */
			{10108,14,0}, /* core6 fp32 bit12 */
			{10109,14,0}, /* core6 fp32 bit13 */
			{10110,14,0}, /* core6 fp32 bit14 */
			{10111,14,0}, /* core6 fp32 bit15 */
			{ 3946,15,0}, /* core6 fp32 bit16 */
			{ 3947,15,0}, /* core6 fp32 bit17 */
			{ 3948,15,0}, /* core6 fp32 bit18 */
			{ 3949,15,0}, /* core6 fp32 bit19 */
			{ 7876,14,0}, /* core6 fp32 bit20 */
			{ 7877,14,0}, /* core6 fp32 bit21 */
			{ 7878,14,0}, /* core6 fp32 bit22 */
			{ 7879,14,0}, /* core6 fp32 bit23 */
			{ 3906,15,0}, /* core6 fp32 bit24 */
			{ 3907,15,0}, /* core6 fp32 bit25 */
			{ 3908,15,0}, /* core6 fp32 bit26 */
			{ 3909,15,0}, /* core6 fp32 bit27 */
			{ 7880,14,0}, /* core6 fp32 bit28 */
			{ 7881,14,0}, /* core6 fp32 bit29 */
			{ 7882,14,0}, /* core6 fp32 bit30 */
			{ 7883,14,0}, /* core6 fp32 bit31 */
			{ 7860,14,0}, /* core6 fp32 bit32 */
			{ 7861,14,0}, /* core6 fp32 bit33 */
			{ 7862,14,0}, /* core6 fp32 bit34 */
			{ 7863,14,0}, /* core6 fp32 bit35 */
			{ 7804,14,0}, /* core6 fp32 bit36 */
			{ 7805,14,0}, /* core6 fp32 bit37 */
			{ 7806,14,0}, /* core6 fp32 bit38 */
			{ 7807,14,0}, /* core6 fp32 bit39 */
			{ 7772,14,0}, /* core6 fp32 bit40 */
			{ 7773,14,0}, /* core6 fp32 bit41 */
			{ 7774,14,0}, /* core6 fp32 bit42 */
			{ 7775,14,0}, /* core6 fp32 bit43 */
			{ 7744,14,0}, /* core6 fp32 bit44 */
			{ 7745,14,0}, /* core6 fp32 bit45 */
			{ 7746,14,0}, /* core6 fp32 bit46 */
			{ 7747,14,0}, /* core6 fp32 bit47 */
			{11296,14,0}, /* core6 fp32 bit48 */
			{11297,14,0}, /* core6 fp32 bit49 */
			{11298,14,0}, /* core6 fp32 bit50 */
			{11299,14,0}, /* core6 fp32 bit51 */
			{11288,14,0}, /* core6 fp32 bit52 */
			{11289,14,0}, /* core6 fp32 bit53 */
			{11290,14,0}, /* core6 fp32 bit54 */
			{11291,14,0}, /* core6 fp32 bit55 */
			{ 7500,14,0}, /* core6 fp32 bit56 */
			{ 7501,14,0}, /* core6 fp32 bit57 */
			{ 7502,14,0}, /* core6 fp32 bit58 */
			{ 7503,14,0}, /* core6 fp32 bit59 */
			{11268,14,0}, /* core6 fp32 bit60 */
			{11269,14,0}, /* core6 fp32 bit61 */
			{11270,14,0}, /* core6 fp32 bit62 */
			{11271,14,0}, /* core6 fp32 bit63 */
			}},
			.fp64 = {{
			{ 8687,14,0}, /* core6 fp64 bit0 */
			{ 8685,14,0}, /* core6 fp64 bit1 */
			{ 8686,14,0}, /* core6 fp64 bit2 */
			{ 5329,15,0}, /* core6 fp64 bit3 */
			{ 8684,14,0}, /* core6 fp64 bit4 */
			{ 5312,15,0}, /* core6 fp64 bit5 */
			{  481,15,0}, /* core6 fp64 bit6 */
			{  480,15,0}, /* core6 fp64 bit7 */
			{ 5307,15,0}, /* core6 fp64 bit8 */
			{  485,15,0}, /* core6 fp64 bit9 */
			{  484,15,0}, /* core6 fp64 bit10 */
			{ 5311,15,0}, /* core6 fp64 bit11 */
			{ 5310,15,0}, /* core6 fp64 bit12 */
			{  453,15,0}, /* core6 fp64 bit13 */
			{  452,15,0}, /* core6 fp64 bit14 */
			{ 5308,15,0}, /* core6 fp64 bit15 */
			{16318,14,0}, /* core6 fp64 bit16 */
			{  455,15,0}, /* core6 fp64 bit17 */
			{  454,15,0}, /* core6 fp64 bit18 */
			{16314,14,0}, /* core6 fp64 bit19 */
			{16313,14,0}, /* core6 fp64 bit20 */
			{ 8659,14,0}, /* core6 fp64 bit21 */
			{ 8658,14,0}, /* core6 fp64 bit22 */
			{16317,14,0}, /* core6 fp64 bit23 */
			{16312,14,0}, /* core6 fp64 bit24 */
			{16311,14,0}, /* core6 fp64 bit25 */
			{16316,14,0}, /* core6 fp64 bit26 */
			{ 5332,15,0}, /* core6 fp64 bit27 */
			{ 8657,14,0}, /* core6 fp64 bit28 */
			{16315,14,0}, /* core6 fp64 bit29 */
			{ 8656,14,0}, /* core6 fp64 bit30 */
			{ 5328,15,0}, /* core6 fp64 bit31 */
			{   24,14,0}, /* core6 fp64 bit32 */
			{   25,14,0}, /* core6 fp64 bit33 */
			{   26,14,0}, /* core6 fp64 bit34 */
			{   27,14,0}, /* core6 fp64 bit35 */
			{   28,14,0}, /* core6 fp64 bit36 */
			{   29,14,0}, /* core6 fp64 bit37 */
			{   30,14,0}, /* core6 fp64 bit38 */
			{   31,14,0}, /* core6 fp64 bit39 */
			{   52,14,0}, /* core6 fp64 bit40 */
			{   53,14,0}, /* core6 fp64 bit41 */
			{   54,14,0}, /* core6 fp64 bit42 */
			{   55,14,0}, /* core6 fp64 bit43 */
			{  112,14,0}, /* core6 fp64 bit44 */
			{  113,14,0}, /* core6 fp64 bit45 */
			{  114,14,0}, /* core6 fp64 bit46 */
			{  115,14,0}, /* core6 fp64 bit47 */
			{  156,14,0}, /* core6 fp64 bit48 */
			{  157,14,0}, /* core6 fp64 bit49 */
			{  158,14,0}, /* core6 fp64 bit50 */
			{  159,14,0}, /* core6 fp64 bit51 */
			{  168,14,0}, /* core6 fp64 bit52 */
			{  169,14,0}, /* core6 fp64 bit53 */
			{  170,14,0}, /* core6 fp64 bit54 */
			{  171,14,0}, /* core6 fp64 bit55 */
			{  172,14,0}, /* core6 fp64 bit56 */
			{  173,14,0}, /* core6 fp64 bit57 */
			{  174,14,0}, /* core6 fp64 bit58 */
			{  175,14,0}, /* core6 fp64 bit59 */
			{ 7564,14,0}, /* core6 fp64 bit60 */
			{ 7565,14,0}, /* core6 fp64 bit61 */
			{ 7566,14,0}, /* core6 fp64 bit62 */
			{ 7567,14,0}, /* core6 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{16282,14,0}, /* core6 sp_EL0 bit0 */
			{16281,14,0}, /* core6 sp_EL0 bit1 */
			{16280,14,0}, /* core6 sp_EL0 bit2 */
			{16279,14,0}, /* core6 sp_EL0 bit3 */
			{ 6524,14,0}, /* core6 sp_EL0 bit4 */
			{ 6525,14,0}, /* core6 sp_EL0 bit5 */
			{ 6526,14,0}, /* core6 sp_EL0 bit6 */
			{ 6527,14,0}, /* core6 sp_EL0 bit7 */
			{ 7116,14,0}, /* core6 sp_EL0 bit8 */
			{ 7117,14,0}, /* core6 sp_EL0 bit9 */
			{ 7118,14,0}, /* core6 sp_EL0 bit10 */
			{ 7119,14,0}, /* core6 sp_EL0 bit11 */
			{ 7128,14,0}, /* core6 sp_EL0 bit12 */
			{ 7129,14,0}, /* core6 sp_EL0 bit13 */
			{ 7130,14,0}, /* core6 sp_EL0 bit14 */
			{ 7131,14,0}, /* core6 sp_EL0 bit15 */
			{ 6992,14,0}, /* core6 sp_EL0 bit16 */
			{ 6993,14,0}, /* core6 sp_EL0 bit17 */
			{ 6994,14,0}, /* core6 sp_EL0 bit18 */
			{ 6995,14,0}, /* core6 sp_EL0 bit19 */
			{ 6712,14,0}, /* core6 sp_EL0 bit20 */
			{ 6713,14,0}, /* core6 sp_EL0 bit21 */
			{ 6714,14,0}, /* core6 sp_EL0 bit22 */
			{ 6715,14,0}, /* core6 sp_EL0 bit23 */
			{ 6544,14,0}, /* core6 sp_EL0 bit24 */
			{ 6545,14,0}, /* core6 sp_EL0 bit25 */
			{ 6546,14,0}, /* core6 sp_EL0 bit26 */
			{ 6547,14,0}, /* core6 sp_EL0 bit27 */
			{ 6756,14,0}, /* core6 sp_EL0 bit28 */
			{ 6757,14,0}, /* core6 sp_EL0 bit29 */
			{ 6758,14,0}, /* core6 sp_EL0 bit30 */
			{ 6759,14,0}, /* core6 sp_EL0 bit31 */
			{   32,14,0}, /* core6 sp_EL0 bit32 */
			{   33,14,0}, /* core6 sp_EL0 bit33 */
			{   34,14,0}, /* core6 sp_EL0 bit34 */
			{   35,14,0}, /* core6 sp_EL0 bit35 */
			{   48,14,0}, /* core6 sp_EL0 bit36 */
			{   49,14,0}, /* core6 sp_EL0 bit37 */
			{   50,14,0}, /* core6 sp_EL0 bit38 */
			{   51,14,0}, /* core6 sp_EL0 bit39 */
			{   60,14,0}, /* core6 sp_EL0 bit40 */
			{   61,14,0}, /* core6 sp_EL0 bit41 */
			{   62,14,0}, /* core6 sp_EL0 bit42 */
			{   63,14,0}, /* core6 sp_EL0 bit43 */
			{  108,14,0}, /* core6 sp_EL0 bit44 */
			{  109,14,0}, /* core6 sp_EL0 bit45 */
			{  110,14,0}, /* core6 sp_EL0 bit46 */
			{  111,14,0}, /* core6 sp_EL0 bit47 */
			{ 8380,14,0}, /* core6 sp_EL0 bit48 */
			{ 8381,14,0}, /* core6 sp_EL0 bit49 */
			{ 8382,14,0}, /* core6 sp_EL0 bit50 */
			{ 8383,14,0}, /* core6 sp_EL0 bit51 */
			{ 8376,14,0}, /* core6 sp_EL0 bit52 */
			{ 8377,14,0}, /* core6 sp_EL0 bit53 */
			{ 8378,14,0}, /* core6 sp_EL0 bit54 */
			{ 8379,14,0}, /* core6 sp_EL0 bit55 */
			{ 8384,14,0}, /* core6 sp_EL0 bit56 */
			{ 8385,14,0}, /* core6 sp_EL0 bit57 */
			{ 8386,14,0}, /* core6 sp_EL0 bit58 */
			{ 8387,14,0}, /* core6 sp_EL0 bit59 */
			{ 8388,14,0}, /* core6 sp_EL0 bit60 */
			{ 8389,14,0}, /* core6 sp_EL0 bit61 */
			{ 8390,14,0}, /* core6 sp_EL0 bit62 */
			{ 8391,14,0}, /* core6 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6575,14,0}, /* core6 sp_EL1 bit0 */
			{ 6574,14,0}, /* core6 sp_EL1 bit1 */
			{ 6573,14,0}, /* core6 sp_EL1 bit2 */
			{ 6572,14,0}, /* core6 sp_EL1 bit3 */
			{ 5326,15,0}, /* core6 sp_EL1 bit4 */
			{  489,15,0}, /* core6 sp_EL1 bit5 */
			{  488,15,0}, /* core6 sp_EL1 bit6 */
			{  487,15,0}, /* core6 sp_EL1 bit7 */
			{  486,15,0}, /* core6 sp_EL1 bit8 */
			{ 7311,14,0}, /* core6 sp_EL1 bit9 */
			{ 7259,14,0}, /* core6 sp_EL1 bit10 */
			{ 7258,14,0}, /* core6 sp_EL1 bit11 */
			{ 7257,14,0}, /* core6 sp_EL1 bit12 */
			{ 7256,14,0}, /* core6 sp_EL1 bit13 */
			{ 5305,15,0}, /* core6 sp_EL1 bit14 */
			{ 7310,14,0}, /* core6 sp_EL1 bit15 */
			{  491,15,0}, /* core6 sp_EL1 bit16 */
			{ 7309,14,0}, /* core6 sp_EL1 bit17 */
			{ 7308,14,0}, /* core6 sp_EL1 bit18 */
			{ 6587,14,0}, /* core6 sp_EL1 bit19 */
			{ 5325,15,0}, /* core6 sp_EL1 bit20 */
			{ 6586,14,0}, /* core6 sp_EL1 bit21 */
			{ 6585,14,0}, /* core6 sp_EL1 bit22 */
			{ 6584,14,0}, /* core6 sp_EL1 bit23 */
			{  490,15,0}, /* core6 sp_EL1 bit24 */
			{16320,14,0}, /* core6 sp_EL1 bit25 */
			{16319,14,0}, /* core6 sp_EL1 bit26 */
			{10137,14,0}, /* core6 sp_EL1 bit27 */
			{10136,14,0}, /* core6 sp_EL1 bit28 */
			{ 8693,14,0}, /* core6 sp_EL1 bit29 */
			{ 8692,14,0}, /* core6 sp_EL1 bit30 */
			{ 5327,15,0}, /* core6 sp_EL1 bit31 */
			{ 6824,14,0}, /* core6 sp_EL1 bit32 */
			{ 6825,14,0}, /* core6 sp_EL1 bit33 */
			{ 6826,14,0}, /* core6 sp_EL1 bit34 */
			{ 6827,14,0}, /* core6 sp_EL1 bit35 */
			{ 6800,14,0}, /* core6 sp_EL1 bit36 */
			{ 6801,14,0}, /* core6 sp_EL1 bit37 */
			{ 6802,14,0}, /* core6 sp_EL1 bit38 */
			{ 6803,14,0}, /* core6 sp_EL1 bit39 */
			{ 6804,14,0}, /* core6 sp_EL1 bit40 */
			{ 6805,14,0}, /* core6 sp_EL1 bit41 */
			{ 6806,14,0}, /* core6 sp_EL1 bit42 */
			{ 6807,14,0}, /* core6 sp_EL1 bit43 */
			{   68,14,0}, /* core6 sp_EL1 bit44 */
			{   69,14,0}, /* core6 sp_EL1 bit45 */
			{   70,14,0}, /* core6 sp_EL1 bit46 */
			{   71,14,0}, /* core6 sp_EL1 bit47 */
			{  148,14,0}, /* core6 sp_EL1 bit48 */
			{  149,14,0}, /* core6 sp_EL1 bit49 */
			{  150,14,0}, /* core6 sp_EL1 bit50 */
			{  151,14,0}, /* core6 sp_EL1 bit51 */
			{  140,14,0}, /* core6 sp_EL1 bit52 */
			{  141,14,0}, /* core6 sp_EL1 bit53 */
			{  142,14,0}, /* core6 sp_EL1 bit54 */
			{  143,14,0}, /* core6 sp_EL1 bit55 */
			{  128,14,0}, /* core6 sp_EL1 bit56 */
			{  129,14,0}, /* core6 sp_EL1 bit57 */
			{  130,14,0}, /* core6 sp_EL1 bit58 */
			{  131,14,0}, /* core6 sp_EL1 bit59 */
			{  124,14,0}, /* core6 sp_EL1 bit60 */
			{  125,14,0}, /* core6 sp_EL1 bit61 */
			{  126,14,0}, /* core6 sp_EL1 bit62 */
			{  127,14,0}, /* core6 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{16266,14,0}, /* core6 sp_EL2 bit0 */
			{16265,14,0}, /* core6 sp_EL2 bit1 */
			{16276,14,0}, /* core6 sp_EL2 bit2 */
			{16275,14,0}, /* core6 sp_EL2 bit3 */
			{ 6512,14,0}, /* core6 sp_EL2 bit4 */
			{ 6513,14,0}, /* core6 sp_EL2 bit5 */
			{ 6514,14,0}, /* core6 sp_EL2 bit6 */
			{ 6515,14,0}, /* core6 sp_EL2 bit7 */
			{ 7040,14,0}, /* core6 sp_EL2 bit8 */
			{ 7041,14,0}, /* core6 sp_EL2 bit9 */
			{ 7042,14,0}, /* core6 sp_EL2 bit10 */
			{ 7043,14,0}, /* core6 sp_EL2 bit11 */
			{ 7004,14,0}, /* core6 sp_EL2 bit12 */
			{ 7005,14,0}, /* core6 sp_EL2 bit13 */
			{ 7006,14,0}, /* core6 sp_EL2 bit14 */
			{ 7007,14,0}, /* core6 sp_EL2 bit15 */
			{ 7224,14,0}, /* core6 sp_EL2 bit16 */
			{ 7225,14,0}, /* core6 sp_EL2 bit17 */
			{ 7226,14,0}, /* core6 sp_EL2 bit18 */
			{ 7227,14,0}, /* core6 sp_EL2 bit19 */
			{ 6768,14,0}, /* core6 sp_EL2 bit20 */
			{ 6769,14,0}, /* core6 sp_EL2 bit21 */
			{ 6770,14,0}, /* core6 sp_EL2 bit22 */
			{ 6771,14,0}, /* core6 sp_EL2 bit23 */
			{ 6556,14,0}, /* core6 sp_EL2 bit24 */
			{ 6557,14,0}, /* core6 sp_EL2 bit25 */
			{ 6558,14,0}, /* core6 sp_EL2 bit26 */
			{ 6559,14,0}, /* core6 sp_EL2 bit27 */
			{ 6764,14,0}, /* core6 sp_EL2 bit28 */
			{ 6765,14,0}, /* core6 sp_EL2 bit29 */
			{ 6766,14,0}, /* core6 sp_EL2 bit30 */
			{ 6767,14,0}, /* core6 sp_EL2 bit31 */
			{ 8444,14,0}, /* core6 sp_EL2 bit32 */
			{ 8445,14,0}, /* core6 sp_EL2 bit33 */
			{ 8446,14,0}, /* core6 sp_EL2 bit34 */
			{ 8447,14,0}, /* core6 sp_EL2 bit35 */
			{ 8036,14,0}, /* core6 sp_EL2 bit36 */
			{ 8037,14,0}, /* core6 sp_EL2 bit37 */
			{ 8038,14,0}, /* core6 sp_EL2 bit38 */
			{ 8039,14,0}, /* core6 sp_EL2 bit39 */
			{ 8440,14,0}, /* core6 sp_EL2 bit40 */
			{ 8441,14,0}, /* core6 sp_EL2 bit41 */
			{ 8442,14,0}, /* core6 sp_EL2 bit42 */
			{ 8443,14,0}, /* core6 sp_EL2 bit43 */
			{ 8408,14,0}, /* core6 sp_EL2 bit44 */
			{ 8409,14,0}, /* core6 sp_EL2 bit45 */
			{ 8410,14,0}, /* core6 sp_EL2 bit46 */
			{ 8411,14,0}, /* core6 sp_EL2 bit47 */
			{ 8558,14,0}, /* core6 sp_EL2 bit48 */
			{ 8559,14,0}, /* core6 sp_EL2 bit49 */
			{ 8560,14,0}, /* core6 sp_EL2 bit50 */
			{ 8561,14,0}, /* core6 sp_EL2 bit51 */
			{ 8352,14,0}, /* core6 sp_EL2 bit52 */
			{ 8353,14,0}, /* core6 sp_EL2 bit53 */
			{ 8354,14,0}, /* core6 sp_EL2 bit54 */
			{ 8355,14,0}, /* core6 sp_EL2 bit55 */
			{ 8372,14,0}, /* core6 sp_EL2 bit56 */
			{ 8373,14,0}, /* core6 sp_EL2 bit57 */
			{ 8374,14,0}, /* core6 sp_EL2 bit58 */
			{ 8375,14,0}, /* core6 sp_EL2 bit59 */
			{ 8400,14,0}, /* core6 sp_EL2 bit60 */
			{ 8401,14,0}, /* core6 sp_EL2 bit61 */
			{ 8402,14,0}, /* core6 sp_EL2 bit62 */
			{ 8403,14,0}, /* core6 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6499,14,0}, /* core6 sp_EL3 bit0 */
			{ 6498,14,0}, /* core6 sp_EL3 bit1 */
			{ 6497,14,0}, /* core6 sp_EL3 bit2 */
			{ 6496,14,0}, /* core6 sp_EL3 bit3 */
			{16302,14,0}, /* core6 sp_EL3 bit4 */
			{ 7235,14,0}, /* core6 sp_EL3 bit5 */
			{16301,14,0}, /* core6 sp_EL3 bit6 */
			{ 7234,14,0}, /* core6 sp_EL3 bit7 */
			{ 7247,14,0}, /* core6 sp_EL3 bit8 */
			{ 7246,14,0}, /* core6 sp_EL3 bit9 */
			{ 7245,14,0}, /* core6 sp_EL3 bit10 */
			{ 7244,14,0}, /* core6 sp_EL3 bit11 */
			{ 7243,14,0}, /* core6 sp_EL3 bit12 */
			{ 7242,14,0}, /* core6 sp_EL3 bit13 */
			{ 7241,14,0}, /* core6 sp_EL3 bit14 */
			{ 7233,14,0}, /* core6 sp_EL3 bit15 */
			{ 7240,14,0}, /* core6 sp_EL3 bit16 */
			{ 7223,14,0}, /* core6 sp_EL3 bit17 */
			{ 7222,14,0}, /* core6 sp_EL3 bit18 */
			{ 7221,14,0}, /* core6 sp_EL3 bit19 */
			{ 8663,14,0}, /* core6 sp_EL3 bit20 */
			{ 8662,14,0}, /* core6 sp_EL3 bit21 */
			{ 6445,14,0}, /* core6 sp_EL3 bit22 */
			{ 6463,14,0}, /* core6 sp_EL3 bit23 */
			{ 7232,14,0}, /* core6 sp_EL3 bit24 */
			{16288,14,0}, /* core6 sp_EL3 bit25 */
			{ 7220,14,0}, /* core6 sp_EL3 bit26 */
			{16287,14,0}, /* core6 sp_EL3 bit27 */
			{ 8661,14,0}, /* core6 sp_EL3 bit28 */
			{ 8660,14,0}, /* core6 sp_EL3 bit29 */
			{ 6444,14,0}, /* core6 sp_EL3 bit30 */
			{ 6446,14,0}, /* core6 sp_EL3 bit31 */
			{ 6816,14,0}, /* core6 sp_EL3 bit32 */
			{ 6817,14,0}, /* core6 sp_EL3 bit33 */
			{ 6818,14,0}, /* core6 sp_EL3 bit34 */
			{ 6819,14,0}, /* core6 sp_EL3 bit35 */
			{ 6808,14,0}, /* core6 sp_EL3 bit36 */
			{ 6809,14,0}, /* core6 sp_EL3 bit37 */
			{ 6810,14,0}, /* core6 sp_EL3 bit38 */
			{ 6811,14,0}, /* core6 sp_EL3 bit39 */
			{   56,14,0}, /* core6 sp_EL3 bit40 */
			{   57,14,0}, /* core6 sp_EL3 bit41 */
			{   58,14,0}, /* core6 sp_EL3 bit42 */
			{   59,14,0}, /* core6 sp_EL3 bit43 */
			{   80,14,0}, /* core6 sp_EL3 bit44 */
			{   81,14,0}, /* core6 sp_EL3 bit45 */
			{   82,14,0}, /* core6 sp_EL3 bit46 */
			{   83,14,0}, /* core6 sp_EL3 bit47 */
			{  144,14,0}, /* core6 sp_EL3 bit48 */
			{  145,14,0}, /* core6 sp_EL3 bit49 */
			{  146,14,0}, /* core6 sp_EL3 bit50 */
			{  147,14,0}, /* core6 sp_EL3 bit51 */
			{ 8088,14,0}, /* core6 sp_EL3 bit52 */
			{ 8089,14,0}, /* core6 sp_EL3 bit53 */
			{ 8090,14,0}, /* core6 sp_EL3 bit54 */
			{ 8091,14,0}, /* core6 sp_EL3 bit55 */
			{  132,14,0}, /* core6 sp_EL3 bit56 */
			{  133,14,0}, /* core6 sp_EL3 bit57 */
			{  134,14,0}, /* core6 sp_EL3 bit58 */
			{  135,14,0}, /* core6 sp_EL3 bit59 */
			{  120,14,0}, /* core6 sp_EL3 bit60 */
			{  121,14,0}, /* core6 sp_EL3 bit61 */
			{  122,14,0}, /* core6 sp_EL3 bit62 */
			{  123,14,0}, /* core6 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{16306,14,0}, /* core6 elr_EL1 bit0 */
			{16305,14,0}, /* core6 elr_EL1 bit1 */
			{16308,14,0}, /* core6 elr_EL1 bit2 */
			{16307,14,0}, /* core6 elr_EL1 bit3 */
			{ 7275,14,0}, /* core6 elr_EL1 bit4 */
			{ 7274,14,0}, /* core6 elr_EL1 bit5 */
			{ 5306,15,0}, /* core6 elr_EL1 bit6 */
			{ 7273,14,0}, /* core6 elr_EL1 bit7 */
			{ 7272,14,0}, /* core6 elr_EL1 bit8 */
			{ 7255,14,0}, /* core6 elr_EL1 bit9 */
			{ 7254,14,0}, /* core6 elr_EL1 bit10 */
			{ 7253,14,0}, /* core6 elr_EL1 bit11 */
			{ 7252,14,0}, /* core6 elr_EL1 bit12 */
			{ 7239,14,0}, /* core6 elr_EL1 bit13 */
			{ 7238,14,0}, /* core6 elr_EL1 bit14 */
			{ 7237,14,0}, /* core6 elr_EL1 bit15 */
			{ 7236,14,0}, /* core6 elr_EL1 bit16 */
			{  475,15,0}, /* core6 elr_EL1 bit17 */
			{  474,15,0}, /* core6 elr_EL1 bit18 */
			{ 8683,14,0}, /* core6 elr_EL1 bit19 */
			{ 6433,14,0}, /* core6 elr_EL1 bit20 */
			{ 8655,14,0}, /* core6 elr_EL1 bit21 */
			{ 8654,14,0}, /* core6 elr_EL1 bit22 */
			{ 8682,14,0}, /* core6 elr_EL1 bit23 */
			{16310,14,0}, /* core6 elr_EL1 bit24 */
			{16309,14,0}, /* core6 elr_EL1 bit25 */
			{  473,15,0}, /* core6 elr_EL1 bit26 */
			{  472,15,0}, /* core6 elr_EL1 bit27 */
			{ 6434,14,0}, /* core6 elr_EL1 bit28 */
			{ 6432,14,0}, /* core6 elr_EL1 bit29 */
			{ 6443,14,0}, /* core6 elr_EL1 bit30 */
			{ 6431,14,0}, /* core6 elr_EL1 bit31 */
			{  244,14,0}, /* core6 elr_EL1 bit32 */
			{  245,14,0}, /* core6 elr_EL1 bit33 */
			{  246,14,0}, /* core6 elr_EL1 bit34 */
			{  247,14,0}, /* core6 elr_EL1 bit35 */
			{  224,14,0}, /* core6 elr_EL1 bit36 */
			{  225,14,0}, /* core6 elr_EL1 bit37 */
			{  226,14,0}, /* core6 elr_EL1 bit38 */
			{  227,14,0}, /* core6 elr_EL1 bit39 */
			{  228,14,0}, /* core6 elr_EL1 bit40 */
			{  229,14,0}, /* core6 elr_EL1 bit41 */
			{  230,14,0}, /* core6 elr_EL1 bit42 */
			{  231,14,0}, /* core6 elr_EL1 bit43 */
			{  232,14,0}, /* core6 elr_EL1 bit44 */
			{  233,14,0}, /* core6 elr_EL1 bit45 */
			{  234,14,0}, /* core6 elr_EL1 bit46 */
			{  235,14,0}, /* core6 elr_EL1 bit47 */
			{ 7548,14,0}, /* core6 elr_EL1 bit48 */
			{ 7549,14,0}, /* core6 elr_EL1 bit49 */
			{ 7550,14,0}, /* core6 elr_EL1 bit50 */
			{ 7551,14,0}, /* core6 elr_EL1 bit51 */
			{ 7556,14,0}, /* core6 elr_EL1 bit52 */
			{ 7557,14,0}, /* core6 elr_EL1 bit53 */
			{ 7558,14,0}, /* core6 elr_EL1 bit54 */
			{ 7559,14,0}, /* core6 elr_EL1 bit55 */
			{ 7560,14,0}, /* core6 elr_EL1 bit56 */
			{ 7561,14,0}, /* core6 elr_EL1 bit57 */
			{ 7562,14,0}, /* core6 elr_EL1 bit58 */
			{ 7563,14,0}, /* core6 elr_EL1 bit59 */
			{ 7552,14,0}, /* core6 elr_EL1 bit60 */
			{ 7553,14,0}, /* core6 elr_EL1 bit61 */
			{ 7554,14,0}, /* core6 elr_EL1 bit62 */
			{ 7555,14,0}, /* core6 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 6467,14,0}, /* core6 elr_EL2 bit0 */
			{ 6466,14,0}, /* core6 elr_EL2 bit1 */
			{ 6465,14,0}, /* core6 elr_EL2 bit2 */
			{ 6464,14,0}, /* core6 elr_EL2 bit3 */
			{ 5322,15,0}, /* core6 elr_EL2 bit4 */
			{ 5314,15,0}, /* core6 elr_EL2 bit5 */
			{  461,15,0}, /* core6 elr_EL2 bit6 */
			{  460,15,0}, /* core6 elr_EL2 bit7 */
			{  447,15,0}, /* core6 elr_EL2 bit8 */
			{  446,15,0}, /* core6 elr_EL2 bit9 */
			{ 5313,15,0}, /* core6 elr_EL2 bit10 */
			{ 5315,15,0}, /* core6 elr_EL2 bit11 */
			{  459,15,0}, /* core6 elr_EL2 bit12 */
			{  458,15,0}, /* core6 elr_EL2 bit13 */
			{  463,15,0}, /* core6 elr_EL2 bit14 */
			{  462,15,0}, /* core6 elr_EL2 bit15 */
			{ 5335,15,0}, /* core6 elr_EL2 bit16 */
			{  467,15,0}, /* core6 elr_EL2 bit17 */
			{  466,15,0}, /* core6 elr_EL2 bit18 */
			{16290,14,0}, /* core6 elr_EL2 bit19 */
			{16289,14,0}, /* core6 elr_EL2 bit20 */
			{ 8675,14,0}, /* core6 elr_EL2 bit21 */
			{ 8674,14,0}, /* core6 elr_EL2 bit22 */
			{ 8677,14,0}, /* core6 elr_EL2 bit23 */
			{16292,14,0}, /* core6 elr_EL2 bit24 */
			{16291,14,0}, /* core6 elr_EL2 bit25 */
			{16294,14,0}, /* core6 elr_EL2 bit26 */
			{16293,14,0}, /* core6 elr_EL2 bit27 */
			{ 8676,14,0}, /* core6 elr_EL2 bit28 */
			{ 1999,14,0}, /* core6 elr_EL2 bit29 */
			{ 6454,14,0}, /* core6 elr_EL2 bit30 */
			{ 6455,14,0}, /* core6 elr_EL2 bit31 */
			{ 6820,14,0}, /* core6 elr_EL2 bit32 */
			{ 6821,14,0}, /* core6 elr_EL2 bit33 */
			{ 6822,14,0}, /* core6 elr_EL2 bit34 */
			{ 6823,14,0}, /* core6 elr_EL2 bit35 */
			{   12,14,0}, /* core6 elr_EL2 bit36 */
			{   13,14,0}, /* core6 elr_EL2 bit37 */
			{   14,14,0}, /* core6 elr_EL2 bit38 */
			{   15,14,0}, /* core6 elr_EL2 bit39 */
			{   92,14,0}, /* core6 elr_EL2 bit40 */
			{   93,14,0}, /* core6 elr_EL2 bit41 */
			{   94,14,0}, /* core6 elr_EL2 bit42 */
			{   95,14,0}, /* core6 elr_EL2 bit43 */
			{  100,14,0}, /* core6 elr_EL2 bit44 */
			{  101,14,0}, /* core6 elr_EL2 bit45 */
			{  102,14,0}, /* core6 elr_EL2 bit46 */
			{  103,14,0}, /* core6 elr_EL2 bit47 */
			{  152,14,0}, /* core6 elr_EL2 bit48 */
			{  153,14,0}, /* core6 elr_EL2 bit49 */
			{  154,14,0}, /* core6 elr_EL2 bit50 */
			{  155,14,0}, /* core6 elr_EL2 bit51 */
			{ 8092,14,0}, /* core6 elr_EL2 bit52 */
			{ 8093,14,0}, /* core6 elr_EL2 bit53 */
			{ 8094,14,0}, /* core6 elr_EL2 bit54 */
			{ 8095,14,0}, /* core6 elr_EL2 bit55 */
			{  136,14,0}, /* core6 elr_EL2 bit56 */
			{  137,14,0}, /* core6 elr_EL2 bit57 */
			{  138,14,0}, /* core6 elr_EL2 bit58 */
			{  139,14,0}, /* core6 elr_EL2 bit59 */
			{ 8068,14,0}, /* core6 elr_EL2 bit60 */
			{ 8069,14,0}, /* core6 elr_EL2 bit61 */
			{ 8070,14,0}, /* core6 elr_EL2 bit62 */
			{ 8071,14,0}, /* core6 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 7947,14,0}, /* core6 elr_EL3 bit0 */
			{ 7946,14,0}, /* core6 elr_EL3 bit1 */
			{ 7945,14,0}, /* core6 elr_EL3 bit2 */
			{ 7944,14,0}, /* core6 elr_EL3 bit3 */
			{ 6932,14,0}, /* core6 elr_EL3 bit4 */
			{ 6933,14,0}, /* core6 elr_EL3 bit5 */
			{ 6934,14,0}, /* core6 elr_EL3 bit6 */
			{ 6935,14,0}, /* core6 elr_EL3 bit7 */
			{ 6644,14,0}, /* core6 elr_EL3 bit8 */
			{ 6645,14,0}, /* core6 elr_EL3 bit9 */
			{ 6646,14,0}, /* core6 elr_EL3 bit10 */
			{ 6647,14,0}, /* core6 elr_EL3 bit11 */
			{ 6640,14,0}, /* core6 elr_EL3 bit12 */
			{ 6641,14,0}, /* core6 elr_EL3 bit13 */
			{ 6642,14,0}, /* core6 elr_EL3 bit14 */
			{ 6643,14,0}, /* core6 elr_EL3 bit15 */
			{ 6636,14,0}, /* core6 elr_EL3 bit16 */
			{ 6637,14,0}, /* core6 elr_EL3 bit17 */
			{ 6638,14,0}, /* core6 elr_EL3 bit18 */
			{ 6639,14,0}, /* core6 elr_EL3 bit19 */
			{ 7932,14,0}, /* core6 elr_EL3 bit20 */
			{ 7933,14,0}, /* core6 elr_EL3 bit21 */
			{ 7934,14,0}, /* core6 elr_EL3 bit22 */
			{ 7935,14,0}, /* core6 elr_EL3 bit23 */
			{ 6936,14,0}, /* core6 elr_EL3 bit24 */
			{ 6937,14,0}, /* core6 elr_EL3 bit25 */
			{ 6938,14,0}, /* core6 elr_EL3 bit26 */
			{ 6939,14,0}, /* core6 elr_EL3 bit27 */
			{ 7928,14,0}, /* core6 elr_EL3 bit28 */
			{ 7929,14,0}, /* core6 elr_EL3 bit29 */
			{ 7930,14,0}, /* core6 elr_EL3 bit30 */
			{ 7931,14,0}, /* core6 elr_EL3 bit31 */
			{ 8040,14,0}, /* core6 elr_EL3 bit32 */
			{ 8041,14,0}, /* core6 elr_EL3 bit33 */
			{ 8042,14,0}, /* core6 elr_EL3 bit34 */
			{ 8043,14,0}, /* core6 elr_EL3 bit35 */
			{ 8412,14,0}, /* core6 elr_EL3 bit36 */
			{ 8413,14,0}, /* core6 elr_EL3 bit37 */
			{ 8414,14,0}, /* core6 elr_EL3 bit38 */
			{ 8415,14,0}, /* core6 elr_EL3 bit39 */
			{ 8032,14,0}, /* core6 elr_EL3 bit40 */
			{ 8033,14,0}, /* core6 elr_EL3 bit41 */
			{ 8034,14,0}, /* core6 elr_EL3 bit42 */
			{ 8035,14,0}, /* core6 elr_EL3 bit43 */
			{ 8404,14,0}, /* core6 elr_EL3 bit44 */
			{ 8405,14,0}, /* core6 elr_EL3 bit45 */
			{ 8406,14,0}, /* core6 elr_EL3 bit46 */
			{ 8407,14,0}, /* core6 elr_EL3 bit47 */
			{ 8566,14,0}, /* core6 elr_EL3 bit48 */
			{ 8567,14,0}, /* core6 elr_EL3 bit49 */
			{ 8568,14,0}, /* core6 elr_EL3 bit50 */
			{ 8569,14,0}, /* core6 elr_EL3 bit51 */
			{ 8360,14,0}, /* core6 elr_EL3 bit52 */
			{ 8361,14,0}, /* core6 elr_EL3 bit53 */
			{ 8362,14,0}, /* core6 elr_EL3 bit54 */
			{ 8363,14,0}, /* core6 elr_EL3 bit55 */
			{ 8562,14,0}, /* core6 elr_EL3 bit56 */
			{ 8563,14,0}, /* core6 elr_EL3 bit57 */
			{ 8564,14,0}, /* core6 elr_EL3 bit58 */
			{ 8565,14,0}, /* core6 elr_EL3 bit59 */
			{ 8392,14,0}, /* core6 elr_EL3 bit60 */
			{ 8393,14,0}, /* core6 elr_EL3 bit61 */
			{ 8394,14,0}, /* core6 elr_EL3 bit62 */
			{ 8395,14,0}, /* core6 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{17159,14,0}, /* core6 raw_pc bit0 */
			{14566,14,0}, /* core6 raw_pc bit1 */
			{14567,14,0}, /* core6 raw_pc bit2 */
			{13688,14,0}, /* core6 raw_pc bit3 */
			{13689,14,0}, /* core6 raw_pc bit4 */
			{13690,14,0}, /* core6 raw_pc bit5 */
			{13691,14,0}, /* core6 raw_pc bit6 */
			{ 1390,15,0}, /* core6 raw_pc bit7 */
			{ 1391,15,0}, /* core6 raw_pc bit8 */
			{ 1392,15,0}, /* core6 raw_pc bit9 */
			{ 1393,15,0}, /* core6 raw_pc bit10 */
			{ 1410,15,0}, /* core6 raw_pc bit11 */
			{ 1411,15,0}, /* core6 raw_pc bit12 */
			{ 1412,15,0}, /* core6 raw_pc bit13 */
			{ 1413,15,0}, /* core6 raw_pc bit14 */
			{13896,14,0}, /* core6 raw_pc bit15 */
			{13897,14,0}, /* core6 raw_pc bit16 */
			{13898,14,0}, /* core6 raw_pc bit17 */
			{13899,14,0}, /* core6 raw_pc bit18 */
			{ 1426,15,0}, /* core6 raw_pc bit19 */
			{ 1427,15,0}, /* core6 raw_pc bit20 */
			{ 1428,15,0}, /* core6 raw_pc bit21 */
			{ 1429,15,0}, /* core6 raw_pc bit22 */
			{ 1430,15,0}, /* core6 raw_pc bit23 */
			{ 1431,15,0}, /* core6 raw_pc bit24 */
			{ 1432,15,0}, /* core6 raw_pc bit25 */
			{ 1433,15,0}, /* core6 raw_pc bit26 */
			{ 1434,15,0}, /* core6 raw_pc bit27 */
			{ 1435,15,0}, /* core6 raw_pc bit28 */
			{ 1436,15,0}, /* core6 raw_pc bit29 */
			{ 1437,15,0}, /* core6 raw_pc bit30 */
			{15938,14,0}, /* core6 raw_pc bit31 */
			{13480,14,0}, /* core6 raw_pc bit32 */
			{13481,14,0}, /* core6 raw_pc bit33 */
			{13482,14,0}, /* core6 raw_pc bit34 */
			{13483,14,0}, /* core6 raw_pc bit35 */
			{13476,14,0}, /* core6 raw_pc bit36 */
			{13477,14,0}, /* core6 raw_pc bit37 */
			{13478,14,0}, /* core6 raw_pc bit38 */
			{13479,14,0}, /* core6 raw_pc bit39 */
			{13496,14,0}, /* core6 raw_pc bit40 */
			{13497,14,0}, /* core6 raw_pc bit41 */
			{13498,14,0}, /* core6 raw_pc bit42 */
			{13499,14,0}, /* core6 raw_pc bit43 */
			{13500,14,0}, /* core6 raw_pc bit44 */
			{13501,14,0}, /* core6 raw_pc bit45 */
			{13502,14,0}, /* core6 raw_pc bit46 */
			{13503,14,0}, /* core6 raw_pc bit47 */
			{    0, 0,2}, /* core6 raw_pc bit48 */
			{    0, 0,2}, /* core6 raw_pc bit49 */
			{    0, 0,2}, /* core6 raw_pc bit50 */
			{    0, 0,2}, /* core6 raw_pc bit51 */
			{    0, 0,2}, /* core6 raw_pc bit52 */
			{    0, 0,2}, /* core6 raw_pc bit53 */
			{    0, 0,2}, /* core6 raw_pc bit54 */
			{    0, 0,2}, /* core6 raw_pc bit55 */
			{    0, 0,2}, /* core6 raw_pc bit56 */
			{    0, 0,2}, /* core6 raw_pc bit57 */
			{    0, 0,2}, /* core6 raw_pc bit58 */
			{    0, 0,2}, /* core6 raw_pc bit59 */
			{    0, 0,2}, /* core6 raw_pc bit60 */
			{    0, 0,2}, /* core6 raw_pc bit61 */
			{    0, 0,2}, /* core6 raw_pc bit62 */
			{    0, 0,2}, /* core6 raw_pc bit63 */
			}},
			.pc_iss = {{
			{12164,14,0}, /* core6 pc_iss bit0 */
			{12165,14,0}, /* core6 pc_iss bit1 */
			{12166,14,0}, /* core6 pc_iss bit2 */
			{12167,14,0}, /* core6 pc_iss bit3 */
			{13860,14,0}, /* core6 pc_iss bit4 */
			{13861,14,0}, /* core6 pc_iss bit5 */
			{13862,14,0}, /* core6 pc_iss bit6 */
			{13863,14,0}, /* core6 pc_iss bit7 */
			{13420,14,0}, /* core6 pc_iss bit8 */
			{13421,14,0}, /* core6 pc_iss bit9 */
			{13422,14,0}, /* core6 pc_iss bit10 */
			{13423,14,0}, /* core6 pc_iss bit11 */
			{13428,14,0}, /* core6 pc_iss bit12 */
			{13429,14,0}, /* core6 pc_iss bit13 */
			{13430,14,0}, /* core6 pc_iss bit14 */
			{13431,14,0}, /* core6 pc_iss bit15 */
			{13408,14,0}, /* core6 pc_iss bit16 */
			{13409,14,0}, /* core6 pc_iss bit17 */
			{13410,14,0}, /* core6 pc_iss bit18 */
			{13411,14,0}, /* core6 pc_iss bit19 */
			{13412,14,0}, /* core6 pc_iss bit20 */
			{13413,14,0}, /* core6 pc_iss bit21 */
			{13414,14,0}, /* core6 pc_iss bit22 */
			{13415,14,0}, /* core6 pc_iss bit23 */
			{13424,14,0}, /* core6 pc_iss bit24 */
			{13425,14,0}, /* core6 pc_iss bit25 */
			{13426,14,0}, /* core6 pc_iss bit26 */
			{13427,14,0}, /* core6 pc_iss bit27 */
			{13416,14,0}, /* core6 pc_iss bit28 */
			{13417,14,0}, /* core6 pc_iss bit29 */
			{13418,14,0}, /* core6 pc_iss bit30 */
			{13419,14,0}, /* core6 pc_iss bit31 */
			{13508,14,0}, /* core6 pc_iss bit32 */
			{13509,14,0}, /* core6 pc_iss bit33 */
			{13510,14,0}, /* core6 pc_iss bit34 */
			{13511,14,0}, /* core6 pc_iss bit35 */
			{13504,14,0}, /* core6 pc_iss bit36 */
			{13505,14,0}, /* core6 pc_iss bit37 */
			{13506,14,0}, /* core6 pc_iss bit38 */
			{13507,14,0}, /* core6 pc_iss bit39 */
			{13520,14,0}, /* core6 pc_iss bit40 */
			{13521,14,0}, /* core6 pc_iss bit41 */
			{13522,14,0}, /* core6 pc_iss bit42 */
			{13523,14,0}, /* core6 pc_iss bit43 */
			{13524,14,0}, /* core6 pc_iss bit44 */
			{13525,14,0}, /* core6 pc_iss bit45 */
			{13526,14,0}, /* core6 pc_iss bit46 */
			{13527,14,0}, /* core6 pc_iss bit47 */
			{13540,14,0}, /* core6 pc_iss bit48 */
			{13541,14,0}, /* core6 pc_iss bit49 */
			{13542,14,0}, /* core6 pc_iss bit50 */
			{13543,14,0}, /* core6 pc_iss bit51 */
			{13528,14,0}, /* core6 pc_iss bit52 */
			{13529,14,0}, /* core6 pc_iss bit53 */
			{13530,14,0}, /* core6 pc_iss bit54 */
			{13531,14,0}, /* core6 pc_iss bit55 */
			{13544,14,0}, /* core6 pc_iss bit56 */
			{13545,14,0}, /* core6 pc_iss bit57 */
			{13546,14,0}, /* core6 pc_iss bit58 */
			{13547,14,0}, /* core6 pc_iss bit59 */
			{13548,14,0}, /* core6 pc_iss bit60 */
			{13549,14,0}, /* core6 pc_iss bit61 */
			{13550,14,0}, /* core6 pc_iss bit62 */
			{13551,14,0}, /* core6 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{17168,14,0}, /* core6 full_pc_wr bit0 */
			{    0, 0,2}, /* core6 full_pc_wr bit1 */
			{    0, 0,2}, /* core6 full_pc_wr bit2 */
			{    0, 0,2}, /* core6 full_pc_wr bit3 */
			{    0, 0,2}, /* core6 full_pc_wr bit4 */
			{    0, 0,2}, /* core6 full_pc_wr bit5 */
			{    0, 0,2}, /* core6 full_pc_wr bit6 */
			{    0, 0,2}, /* core6 full_pc_wr bit7 */
			{    0, 0,2}, /* core6 full_pc_wr bit8 */
			{    0, 0,2}, /* core6 full_pc_wr bit9 */
			{    0, 0,2}, /* core6 full_pc_wr bit10 */
			{    0, 0,2}, /* core6 full_pc_wr bit11 */
			{    0, 0,2}, /* core6 full_pc_wr bit12 */
			{    0, 0,2}, /* core6 full_pc_wr bit13 */
			{    0, 0,2}, /* core6 full_pc_wr bit14 */
			{    0, 0,2}, /* core6 full_pc_wr bit15 */
			{    0, 0,2}, /* core6 full_pc_wr bit16 */
			{    0, 0,2}, /* core6 full_pc_wr bit17 */
			{    0, 0,2}, /* core6 full_pc_wr bit18 */
			{    0, 0,2}, /* core6 full_pc_wr bit19 */
			{    0, 0,2}, /* core6 full_pc_wr bit20 */
			{    0, 0,2}, /* core6 full_pc_wr bit21 */
			{    0, 0,2}, /* core6 full_pc_wr bit22 */
			{    0, 0,2}, /* core6 full_pc_wr bit23 */
			{    0, 0,2}, /* core6 full_pc_wr bit24 */
			{    0, 0,2}, /* core6 full_pc_wr bit25 */
			{    0, 0,2}, /* core6 full_pc_wr bit26 */
			{    0, 0,2}, /* core6 full_pc_wr bit27 */
			{    0, 0,2}, /* core6 full_pc_wr bit28 */
			{    0, 0,2}, /* core6 full_pc_wr bit29 */
			{    0, 0,2}, /* core6 full_pc_wr bit30 */
			{    0, 0,2}, /* core6 full_pc_wr bit31 */
			{    0, 0,2}, /* core6 full_pc_wr bit32 */
			{    0, 0,2}, /* core6 full_pc_wr bit33 */
			{    0, 0,2}, /* core6 full_pc_wr bit34 */
			{    0, 0,2}, /* core6 full_pc_wr bit35 */
			{    0, 0,2}, /* core6 full_pc_wr bit36 */
			{    0, 0,2}, /* core6 full_pc_wr bit37 */
			{    0, 0,2}, /* core6 full_pc_wr bit38 */
			{    0, 0,2}, /* core6 full_pc_wr bit39 */
			{    0, 0,2}, /* core6 full_pc_wr bit40 */
			{    0, 0,2}, /* core6 full_pc_wr bit41 */
			{    0, 0,2}, /* core6 full_pc_wr bit42 */
			{    0, 0,2}, /* core6 full_pc_wr bit43 */
			{    0, 0,2}, /* core6 full_pc_wr bit44 */
			{    0, 0,2}, /* core6 full_pc_wr bit45 */
			{    0, 0,2}, /* core6 full_pc_wr bit46 */
			{    0, 0,2}, /* core6 full_pc_wr bit47 */
			{    0, 0,2}, /* core6 full_pc_wr bit48 */
			{    0, 0,2}, /* core6 full_pc_wr bit49 */
			{    0, 0,2}, /* core6 full_pc_wr bit50 */
			{    0, 0,2}, /* core6 full_pc_wr bit51 */
			{    0, 0,2}, /* core6 full_pc_wr bit52 */
			{    0, 0,2}, /* core6 full_pc_wr bit53 */
			{    0, 0,2}, /* core6 full_pc_wr bit54 */
			{    0, 0,2}, /* core6 full_pc_wr bit55 */
			{    0, 0,2}, /* core6 full_pc_wr bit56 */
			{    0, 0,2}, /* core6 full_pc_wr bit57 */
			{    0, 0,2}, /* core6 full_pc_wr bit58 */
			{    0, 0,2}, /* core6 full_pc_wr bit59 */
			{    0, 0,2}, /* core6 full_pc_wr bit60 */
			{    0, 0,2}, /* core6 full_pc_wr bit61 */
			{    0, 0,2}, /* core6 full_pc_wr bit62 */
			{    0, 0,2}, /* core6 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{14569,14,0}, /* core6 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core6 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{17170,14,0}, /* core6 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core6 full_pc_ex2 bit63 */
			}},
	},
	{		/* core 7 */ 
			.pc = {{
			{ 7160,16,0}, /* core7 pc bit0 */
			{ 7161,16,0}, /* core7 pc bit1 */
			{ 7162,16,0}, /* core7 pc bit2 */
			{ 7163,16,0}, /* core7 pc bit3 */
			{ 7344,16,0}, /* core7 pc bit4 */
			{ 7345,16,0}, /* core7 pc bit5 */
			{ 7346,16,0}, /* core7 pc bit6 */
			{ 7347,16,0}, /* core7 pc bit7 */
			{ 7356,16,0}, /* core7 pc bit8 */
			{ 7357,16,0}, /* core7 pc bit9 */
			{ 7358,16,0}, /* core7 pc bit10 */
			{ 7359,16,0}, /* core7 pc bit11 */
			{ 6704,16,0}, /* core7 pc bit12 */
			{ 6705,16,0}, /* core7 pc bit13 */
			{ 6706,16,0}, /* core7 pc bit14 */
			{ 6707,16,0}, /* core7 pc bit15 */
			{ 6708,16,0}, /* core7 pc bit16 */
			{ 6709,16,0}, /* core7 pc bit17 */
			{ 6710,16,0}, /* core7 pc bit18 */
			{ 6711,16,0}, /* core7 pc bit19 */
			{10968,16,0}, /* core7 pc bit20 */
			{10969,16,0}, /* core7 pc bit21 */
			{10970,16,0}, /* core7 pc bit22 */
			{10971,16,0}, /* core7 pc bit23 */
			{ 7348,16,0}, /* core7 pc bit24 */
			{ 7349,16,0}, /* core7 pc bit25 */
			{ 7350,16,0}, /* core7 pc bit26 */
			{ 7351,16,0}, /* core7 pc bit27 */
			{ 6700,16,0}, /* core7 pc bit28 */
			{ 6701,16,0}, /* core7 pc bit29 */
			{ 6702,16,0}, /* core7 pc bit30 */
			{ 6703,16,0}, /* core7 pc bit31 */
			{17044,16,0}, /* core7 pc bit32 */
			{17045,16,0}, /* core7 pc bit33 */
			{17046,16,0}, /* core7 pc bit34 */
			{17047,16,0}, /* core7 pc bit35 */
			{17040,16,0}, /* core7 pc bit36 */
			{17041,16,0}, /* core7 pc bit37 */
			{17042,16,0}, /* core7 pc bit38 */
			{17043,16,0}, /* core7 pc bit39 */
			{17036,16,0}, /* core7 pc bit40 */
			{17037,16,0}, /* core7 pc bit41 */
			{17038,16,0}, /* core7 pc bit42 */
			{17039,16,0}, /* core7 pc bit43 */
			{17032,16,0}, /* core7 pc bit44 */
			{17033,16,0}, /* core7 pc bit45 */
			{17034,16,0}, /* core7 pc bit46 */
			{17035,16,0}, /* core7 pc bit47 */
			{17016,16,0}, /* core7 pc bit48 */
			{17017,16,0}, /* core7 pc bit49 */
			{17018,16,0}, /* core7 pc bit50 */
			{17019,16,0}, /* core7 pc bit51 */
			{17020,16,0}, /* core7 pc bit52 */
			{17021,16,0}, /* core7 pc bit53 */
			{17022,16,0}, /* core7 pc bit54 */
			{17023,16,0}, /* core7 pc bit55 */
			{17028,16,0}, /* core7 pc bit56 */
			{17029,16,0}, /* core7 pc bit57 */
			{17030,16,0}, /* core7 pc bit58 */
			{17031,16,0}, /* core7 pc bit59 */
			{17024,16,0}, /* core7 pc bit60 */
			{17025,16,0}, /* core7 pc bit61 */
			{17026,16,0}, /* core7 pc bit62 */
			{17027,16,0}, /* core7 pc bit63 */
			}},
			.sp32 = {{
			{ 6923,16,0}, /* core7 sp32 bit0 */
			{ 6922,16,0}, /* core7 sp32 bit1 */
			{ 6921,16,0}, /* core7 sp32 bit2 */
			{ 6920,16,0}, /* core7 sp32 bit3 */
			{ 6588,16,0}, /* core7 sp32 bit4 */
			{ 6589,16,0}, /* core7 sp32 bit5 */
			{ 6590,16,0}, /* core7 sp32 bit6 */
			{ 6591,16,0}, /* core7 sp32 bit7 */
			{ 6676,16,0}, /* core7 sp32 bit8 */
			{ 6677,16,0}, /* core7 sp32 bit9 */
			{ 6678,16,0}, /* core7 sp32 bit10 */
			{ 6679,16,0}, /* core7 sp32 bit11 */
			{ 6656,16,0}, /* core7 sp32 bit12 */
			{ 6657,16,0}, /* core7 sp32 bit13 */
			{ 6658,16,0}, /* core7 sp32 bit14 */
			{ 6659,16,0}, /* core7 sp32 bit15 */
			{ 6660,16,0}, /* core7 sp32 bit16 */
			{ 6661,16,0}, /* core7 sp32 bit17 */
			{ 6662,16,0}, /* core7 sp32 bit18 */
			{ 6663,16,0}, /* core7 sp32 bit19 */
			{ 6912,16,0}, /* core7 sp32 bit20 */
			{ 6913,16,0}, /* core7 sp32 bit21 */
			{ 6914,16,0}, /* core7 sp32 bit22 */
			{ 6915,16,0}, /* core7 sp32 bit23 */
			{ 6628,16,0}, /* core7 sp32 bit24 */
			{ 6629,16,0}, /* core7 sp32 bit25 */
			{ 6630,16,0}, /* core7 sp32 bit26 */
			{ 6631,16,0}, /* core7 sp32 bit27 */
			{ 6916,16,0}, /* core7 sp32 bit28 */
			{ 6917,16,0}, /* core7 sp32 bit29 */
			{ 6918,16,0}, /* core7 sp32 bit30 */
			{ 6919,16,0}, /* core7 sp32 bit31 */
			{ 7624,16,0}, /* core7 sp32 bit32 */
			{ 7625,16,0}, /* core7 sp32 bit33 */
			{ 7626,16,0}, /* core7 sp32 bit34 */
			{ 7627,16,0}, /* core7 sp32 bit35 */
			{ 7656,16,0}, /* core7 sp32 bit36 */
			{ 7657,16,0}, /* core7 sp32 bit37 */
			{ 7658,16,0}, /* core7 sp32 bit38 */
			{ 7659,16,0}, /* core7 sp32 bit39 */
			{ 7688,16,0}, /* core7 sp32 bit40 */
			{ 7689,16,0}, /* core7 sp32 bit41 */
			{ 7690,16,0}, /* core7 sp32 bit42 */
			{ 7691,16,0}, /* core7 sp32 bit43 */
			{ 8436,16,0}, /* core7 sp32 bit44 */
			{ 8437,16,0}, /* core7 sp32 bit45 */
			{ 8438,16,0}, /* core7 sp32 bit46 */
			{ 8439,16,0}, /* core7 sp32 bit47 */
			{ 8248,16,0}, /* core7 sp32 bit48 */
			{ 8249,16,0}, /* core7 sp32 bit49 */
			{ 8250,16,0}, /* core7 sp32 bit50 */
			{ 8251,16,0}, /* core7 sp32 bit51 */
			{ 8244,16,0}, /* core7 sp32 bit52 */
			{ 8245,16,0}, /* core7 sp32 bit53 */
			{ 8246,16,0}, /* core7 sp32 bit54 */
			{ 8247,16,0}, /* core7 sp32 bit55 */
			{ 8252,16,0}, /* core7 sp32 bit56 */
			{ 8253,16,0}, /* core7 sp32 bit57 */
			{ 8254,16,0}, /* core7 sp32 bit58 */
			{ 8255,16,0}, /* core7 sp32 bit59 */
			{ 7596,16,0}, /* core7 sp32 bit60 */
			{ 7597,16,0}, /* core7 sp32 bit61 */
			{ 7598,16,0}, /* core7 sp32 bit62 */
			{ 7599,16,0}, /* core7 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7916,16,0}, /* core7 fp32 bit0 */
			{ 7917,16,0}, /* core7 fp32 bit1 */
			{ 7918,16,0}, /* core7 fp32 bit2 */
			{ 7919,16,0}, /* core7 fp32 bit3 */
			{ 3892,17,0}, /* core7 fp32 bit4 */
			{ 3893,17,0}, /* core7 fp32 bit5 */
			{ 3894,17,0}, /* core7 fp32 bit6 */
			{ 3895,17,0}, /* core7 fp32 bit7 */
			{10104,16,0}, /* core7 fp32 bit8 */
			{10105,16,0}, /* core7 fp32 bit9 */
			{10106,16,0}, /* core7 fp32 bit10 */
			{10107,16,0}, /* core7 fp32 bit11 */
			{10108,16,0}, /* core7 fp32 bit12 */
			{10109,16,0}, /* core7 fp32 bit13 */
			{10110,16,0}, /* core7 fp32 bit14 */
			{10111,16,0}, /* core7 fp32 bit15 */
			{ 3946,17,0}, /* core7 fp32 bit16 */
			{ 3947,17,0}, /* core7 fp32 bit17 */
			{ 3948,17,0}, /* core7 fp32 bit18 */
			{ 3949,17,0}, /* core7 fp32 bit19 */
			{ 7876,16,0}, /* core7 fp32 bit20 */
			{ 7877,16,0}, /* core7 fp32 bit21 */
			{ 7878,16,0}, /* core7 fp32 bit22 */
			{ 7879,16,0}, /* core7 fp32 bit23 */
			{ 3906,17,0}, /* core7 fp32 bit24 */
			{ 3907,17,0}, /* core7 fp32 bit25 */
			{ 3908,17,0}, /* core7 fp32 bit26 */
			{ 3909,17,0}, /* core7 fp32 bit27 */
			{ 7880,16,0}, /* core7 fp32 bit28 */
			{ 7881,16,0}, /* core7 fp32 bit29 */
			{ 7882,16,0}, /* core7 fp32 bit30 */
			{ 7883,16,0}, /* core7 fp32 bit31 */
			{ 7860,16,0}, /* core7 fp32 bit32 */
			{ 7861,16,0}, /* core7 fp32 bit33 */
			{ 7862,16,0}, /* core7 fp32 bit34 */
			{ 7863,16,0}, /* core7 fp32 bit35 */
			{ 7804,16,0}, /* core7 fp32 bit36 */
			{ 7805,16,0}, /* core7 fp32 bit37 */
			{ 7806,16,0}, /* core7 fp32 bit38 */
			{ 7807,16,0}, /* core7 fp32 bit39 */
			{ 7772,16,0}, /* core7 fp32 bit40 */
			{ 7773,16,0}, /* core7 fp32 bit41 */
			{ 7774,16,0}, /* core7 fp32 bit42 */
			{ 7775,16,0}, /* core7 fp32 bit43 */
			{ 7744,16,0}, /* core7 fp32 bit44 */
			{ 7745,16,0}, /* core7 fp32 bit45 */
			{ 7746,16,0}, /* core7 fp32 bit46 */
			{ 7747,16,0}, /* core7 fp32 bit47 */
			{11296,16,0}, /* core7 fp32 bit48 */
			{11297,16,0}, /* core7 fp32 bit49 */
			{11298,16,0}, /* core7 fp32 bit50 */
			{11299,16,0}, /* core7 fp32 bit51 */
			{11288,16,0}, /* core7 fp32 bit52 */
			{11289,16,0}, /* core7 fp32 bit53 */
			{11290,16,0}, /* core7 fp32 bit54 */
			{11291,16,0}, /* core7 fp32 bit55 */
			{ 7500,16,0}, /* core7 fp32 bit56 */
			{ 7501,16,0}, /* core7 fp32 bit57 */
			{ 7502,16,0}, /* core7 fp32 bit58 */
			{ 7503,16,0}, /* core7 fp32 bit59 */
			{11268,16,0}, /* core7 fp32 bit60 */
			{11269,16,0}, /* core7 fp32 bit61 */
			{11270,16,0}, /* core7 fp32 bit62 */
			{11271,16,0}, /* core7 fp32 bit63 */
			}},
			.fp64 = {{
			{ 8687,16,0}, /* core7 fp64 bit0 */
			{ 8685,16,0}, /* core7 fp64 bit1 */
			{ 8686,16,0}, /* core7 fp64 bit2 */
			{ 5329,17,0}, /* core7 fp64 bit3 */
			{ 8684,16,0}, /* core7 fp64 bit4 */
			{ 5312,17,0}, /* core7 fp64 bit5 */
			{  481,17,0}, /* core7 fp64 bit6 */
			{  480,17,0}, /* core7 fp64 bit7 */
			{ 5307,17,0}, /* core7 fp64 bit8 */
			{  485,17,0}, /* core7 fp64 bit9 */
			{  484,17,0}, /* core7 fp64 bit10 */
			{ 5311,17,0}, /* core7 fp64 bit11 */
			{ 5310,17,0}, /* core7 fp64 bit12 */
			{  453,17,0}, /* core7 fp64 bit13 */
			{  452,17,0}, /* core7 fp64 bit14 */
			{ 5308,17,0}, /* core7 fp64 bit15 */
			{16318,16,0}, /* core7 fp64 bit16 */
			{  455,17,0}, /* core7 fp64 bit17 */
			{  454,17,0}, /* core7 fp64 bit18 */
			{16314,16,0}, /* core7 fp64 bit19 */
			{16313,16,0}, /* core7 fp64 bit20 */
			{ 8659,16,0}, /* core7 fp64 bit21 */
			{ 8658,16,0}, /* core7 fp64 bit22 */
			{16317,16,0}, /* core7 fp64 bit23 */
			{16312,16,0}, /* core7 fp64 bit24 */
			{16311,16,0}, /* core7 fp64 bit25 */
			{16316,16,0}, /* core7 fp64 bit26 */
			{ 5332,17,0}, /* core7 fp64 bit27 */
			{ 8657,16,0}, /* core7 fp64 bit28 */
			{16315,16,0}, /* core7 fp64 bit29 */
			{ 8656,16,0}, /* core7 fp64 bit30 */
			{ 5328,17,0}, /* core7 fp64 bit31 */
			{   24,16,0}, /* core7 fp64 bit32 */
			{   25,16,0}, /* core7 fp64 bit33 */
			{   26,16,0}, /* core7 fp64 bit34 */
			{   27,16,0}, /* core7 fp64 bit35 */
			{   28,16,0}, /* core7 fp64 bit36 */
			{   29,16,0}, /* core7 fp64 bit37 */
			{   30,16,0}, /* core7 fp64 bit38 */
			{   31,16,0}, /* core7 fp64 bit39 */
			{   52,16,0}, /* core7 fp64 bit40 */
			{   53,16,0}, /* core7 fp64 bit41 */
			{   54,16,0}, /* core7 fp64 bit42 */
			{   55,16,0}, /* core7 fp64 bit43 */
			{  112,16,0}, /* core7 fp64 bit44 */
			{  113,16,0}, /* core7 fp64 bit45 */
			{  114,16,0}, /* core7 fp64 bit46 */
			{  115,16,0}, /* core7 fp64 bit47 */
			{  156,16,0}, /* core7 fp64 bit48 */
			{  157,16,0}, /* core7 fp64 bit49 */
			{  158,16,0}, /* core7 fp64 bit50 */
			{  159,16,0}, /* core7 fp64 bit51 */
			{  168,16,0}, /* core7 fp64 bit52 */
			{  169,16,0}, /* core7 fp64 bit53 */
			{  170,16,0}, /* core7 fp64 bit54 */
			{  171,16,0}, /* core7 fp64 bit55 */
			{  172,16,0}, /* core7 fp64 bit56 */
			{  173,16,0}, /* core7 fp64 bit57 */
			{  174,16,0}, /* core7 fp64 bit58 */
			{  175,16,0}, /* core7 fp64 bit59 */
			{ 7564,16,0}, /* core7 fp64 bit60 */
			{ 7565,16,0}, /* core7 fp64 bit61 */
			{ 7566,16,0}, /* core7 fp64 bit62 */
			{ 7567,16,0}, /* core7 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{16282,16,0}, /* core7 sp_EL0 bit0 */
			{16281,16,0}, /* core7 sp_EL0 bit1 */
			{16280,16,0}, /* core7 sp_EL0 bit2 */
			{16279,16,0}, /* core7 sp_EL0 bit3 */
			{ 6524,16,0}, /* core7 sp_EL0 bit4 */
			{ 6525,16,0}, /* core7 sp_EL0 bit5 */
			{ 6526,16,0}, /* core7 sp_EL0 bit6 */
			{ 6527,16,0}, /* core7 sp_EL0 bit7 */
			{ 7116,16,0}, /* core7 sp_EL0 bit8 */
			{ 7117,16,0}, /* core7 sp_EL0 bit9 */
			{ 7118,16,0}, /* core7 sp_EL0 bit10 */
			{ 7119,16,0}, /* core7 sp_EL0 bit11 */
			{ 7128,16,0}, /* core7 sp_EL0 bit12 */
			{ 7129,16,0}, /* core7 sp_EL0 bit13 */
			{ 7130,16,0}, /* core7 sp_EL0 bit14 */
			{ 7131,16,0}, /* core7 sp_EL0 bit15 */
			{ 6992,16,0}, /* core7 sp_EL0 bit16 */
			{ 6993,16,0}, /* core7 sp_EL0 bit17 */
			{ 6994,16,0}, /* core7 sp_EL0 bit18 */
			{ 6995,16,0}, /* core7 sp_EL0 bit19 */
			{ 6712,16,0}, /* core7 sp_EL0 bit20 */
			{ 6713,16,0}, /* core7 sp_EL0 bit21 */
			{ 6714,16,0}, /* core7 sp_EL0 bit22 */
			{ 6715,16,0}, /* core7 sp_EL0 bit23 */
			{ 6544,16,0}, /* core7 sp_EL0 bit24 */
			{ 6545,16,0}, /* core7 sp_EL0 bit25 */
			{ 6546,16,0}, /* core7 sp_EL0 bit26 */
			{ 6547,16,0}, /* core7 sp_EL0 bit27 */
			{ 6756,16,0}, /* core7 sp_EL0 bit28 */
			{ 6757,16,0}, /* core7 sp_EL0 bit29 */
			{ 6758,16,0}, /* core7 sp_EL0 bit30 */
			{ 6759,16,0}, /* core7 sp_EL0 bit31 */
			{   32,16,0}, /* core7 sp_EL0 bit32 */
			{   33,16,0}, /* core7 sp_EL0 bit33 */
			{   34,16,0}, /* core7 sp_EL0 bit34 */
			{   35,16,0}, /* core7 sp_EL0 bit35 */
			{   48,16,0}, /* core7 sp_EL0 bit36 */
			{   49,16,0}, /* core7 sp_EL0 bit37 */
			{   50,16,0}, /* core7 sp_EL0 bit38 */
			{   51,16,0}, /* core7 sp_EL0 bit39 */
			{   60,16,0}, /* core7 sp_EL0 bit40 */
			{   61,16,0}, /* core7 sp_EL0 bit41 */
			{   62,16,0}, /* core7 sp_EL0 bit42 */
			{   63,16,0}, /* core7 sp_EL0 bit43 */
			{  108,16,0}, /* core7 sp_EL0 bit44 */
			{  109,16,0}, /* core7 sp_EL0 bit45 */
			{  110,16,0}, /* core7 sp_EL0 bit46 */
			{  111,16,0}, /* core7 sp_EL0 bit47 */
			{ 8380,16,0}, /* core7 sp_EL0 bit48 */
			{ 8381,16,0}, /* core7 sp_EL0 bit49 */
			{ 8382,16,0}, /* core7 sp_EL0 bit50 */
			{ 8383,16,0}, /* core7 sp_EL0 bit51 */
			{ 8376,16,0}, /* core7 sp_EL0 bit52 */
			{ 8377,16,0}, /* core7 sp_EL0 bit53 */
			{ 8378,16,0}, /* core7 sp_EL0 bit54 */
			{ 8379,16,0}, /* core7 sp_EL0 bit55 */
			{ 8384,16,0}, /* core7 sp_EL0 bit56 */
			{ 8385,16,0}, /* core7 sp_EL0 bit57 */
			{ 8386,16,0}, /* core7 sp_EL0 bit58 */
			{ 8387,16,0}, /* core7 sp_EL0 bit59 */
			{ 8388,16,0}, /* core7 sp_EL0 bit60 */
			{ 8389,16,0}, /* core7 sp_EL0 bit61 */
			{ 8390,16,0}, /* core7 sp_EL0 bit62 */
			{ 8391,16,0}, /* core7 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6575,16,0}, /* core7 sp_EL1 bit0 */
			{ 6574,16,0}, /* core7 sp_EL1 bit1 */
			{ 6573,16,0}, /* core7 sp_EL1 bit2 */
			{ 6572,16,0}, /* core7 sp_EL1 bit3 */
			{ 5326,17,0}, /* core7 sp_EL1 bit4 */
			{  489,17,0}, /* core7 sp_EL1 bit5 */
			{  488,17,0}, /* core7 sp_EL1 bit6 */
			{  487,17,0}, /* core7 sp_EL1 bit7 */
			{  486,17,0}, /* core7 sp_EL1 bit8 */
			{ 7311,16,0}, /* core7 sp_EL1 bit9 */
			{ 7259,16,0}, /* core7 sp_EL1 bit10 */
			{ 7258,16,0}, /* core7 sp_EL1 bit11 */
			{ 7257,16,0}, /* core7 sp_EL1 bit12 */
			{ 7256,16,0}, /* core7 sp_EL1 bit13 */
			{ 5305,17,0}, /* core7 sp_EL1 bit14 */
			{ 7310,16,0}, /* core7 sp_EL1 bit15 */
			{  491,17,0}, /* core7 sp_EL1 bit16 */
			{ 7309,16,0}, /* core7 sp_EL1 bit17 */
			{ 7308,16,0}, /* core7 sp_EL1 bit18 */
			{ 6587,16,0}, /* core7 sp_EL1 bit19 */
			{ 5325,17,0}, /* core7 sp_EL1 bit20 */
			{ 6586,16,0}, /* core7 sp_EL1 bit21 */
			{ 6585,16,0}, /* core7 sp_EL1 bit22 */
			{ 6584,16,0}, /* core7 sp_EL1 bit23 */
			{  490,17,0}, /* core7 sp_EL1 bit24 */
			{16320,16,0}, /* core7 sp_EL1 bit25 */
			{16319,16,0}, /* core7 sp_EL1 bit26 */
			{10137,16,0}, /* core7 sp_EL1 bit27 */
			{10136,16,0}, /* core7 sp_EL1 bit28 */
			{ 8693,16,0}, /* core7 sp_EL1 bit29 */
			{ 8692,16,0}, /* core7 sp_EL1 bit30 */
			{ 5327,17,0}, /* core7 sp_EL1 bit31 */
			{ 6824,16,0}, /* core7 sp_EL1 bit32 */
			{ 6825,16,0}, /* core7 sp_EL1 bit33 */
			{ 6826,16,0}, /* core7 sp_EL1 bit34 */
			{ 6827,16,0}, /* core7 sp_EL1 bit35 */
			{ 6800,16,0}, /* core7 sp_EL1 bit36 */
			{ 6801,16,0}, /* core7 sp_EL1 bit37 */
			{ 6802,16,0}, /* core7 sp_EL1 bit38 */
			{ 6803,16,0}, /* core7 sp_EL1 bit39 */
			{ 6804,16,0}, /* core7 sp_EL1 bit40 */
			{ 6805,16,0}, /* core7 sp_EL1 bit41 */
			{ 6806,16,0}, /* core7 sp_EL1 bit42 */
			{ 6807,16,0}, /* core7 sp_EL1 bit43 */
			{   68,16,0}, /* core7 sp_EL1 bit44 */
			{   69,16,0}, /* core7 sp_EL1 bit45 */
			{   70,16,0}, /* core7 sp_EL1 bit46 */
			{   71,16,0}, /* core7 sp_EL1 bit47 */
			{  148,16,0}, /* core7 sp_EL1 bit48 */
			{  149,16,0}, /* core7 sp_EL1 bit49 */
			{  150,16,0}, /* core7 sp_EL1 bit50 */
			{  151,16,0}, /* core7 sp_EL1 bit51 */
			{  140,16,0}, /* core7 sp_EL1 bit52 */
			{  141,16,0}, /* core7 sp_EL1 bit53 */
			{  142,16,0}, /* core7 sp_EL1 bit54 */
			{  143,16,0}, /* core7 sp_EL1 bit55 */
			{  128,16,0}, /* core7 sp_EL1 bit56 */
			{  129,16,0}, /* core7 sp_EL1 bit57 */
			{  130,16,0}, /* core7 sp_EL1 bit58 */
			{  131,16,0}, /* core7 sp_EL1 bit59 */
			{  124,16,0}, /* core7 sp_EL1 bit60 */
			{  125,16,0}, /* core7 sp_EL1 bit61 */
			{  126,16,0}, /* core7 sp_EL1 bit62 */
			{  127,16,0}, /* core7 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{16266,16,0}, /* core7 sp_EL2 bit0 */
			{16265,16,0}, /* core7 sp_EL2 bit1 */
			{16276,16,0}, /* core7 sp_EL2 bit2 */
			{16275,16,0}, /* core7 sp_EL2 bit3 */
			{ 6512,16,0}, /* core7 sp_EL2 bit4 */
			{ 6513,16,0}, /* core7 sp_EL2 bit5 */
			{ 6514,16,0}, /* core7 sp_EL2 bit6 */
			{ 6515,16,0}, /* core7 sp_EL2 bit7 */
			{ 7040,16,0}, /* core7 sp_EL2 bit8 */
			{ 7041,16,0}, /* core7 sp_EL2 bit9 */
			{ 7042,16,0}, /* core7 sp_EL2 bit10 */
			{ 7043,16,0}, /* core7 sp_EL2 bit11 */
			{ 7004,16,0}, /* core7 sp_EL2 bit12 */
			{ 7005,16,0}, /* core7 sp_EL2 bit13 */
			{ 7006,16,0}, /* core7 sp_EL2 bit14 */
			{ 7007,16,0}, /* core7 sp_EL2 bit15 */
			{ 7224,16,0}, /* core7 sp_EL2 bit16 */
			{ 7225,16,0}, /* core7 sp_EL2 bit17 */
			{ 7226,16,0}, /* core7 sp_EL2 bit18 */
			{ 7227,16,0}, /* core7 sp_EL2 bit19 */
			{ 6768,16,0}, /* core7 sp_EL2 bit20 */
			{ 6769,16,0}, /* core7 sp_EL2 bit21 */
			{ 6770,16,0}, /* core7 sp_EL2 bit22 */
			{ 6771,16,0}, /* core7 sp_EL2 bit23 */
			{ 6556,16,0}, /* core7 sp_EL2 bit24 */
			{ 6557,16,0}, /* core7 sp_EL2 bit25 */
			{ 6558,16,0}, /* core7 sp_EL2 bit26 */
			{ 6559,16,0}, /* core7 sp_EL2 bit27 */
			{ 6764,16,0}, /* core7 sp_EL2 bit28 */
			{ 6765,16,0}, /* core7 sp_EL2 bit29 */
			{ 6766,16,0}, /* core7 sp_EL2 bit30 */
			{ 6767,16,0}, /* core7 sp_EL2 bit31 */
			{ 8444,16,0}, /* core7 sp_EL2 bit32 */
			{ 8445,16,0}, /* core7 sp_EL2 bit33 */
			{ 8446,16,0}, /* core7 sp_EL2 bit34 */
			{ 8447,16,0}, /* core7 sp_EL2 bit35 */
			{ 8036,16,0}, /* core7 sp_EL2 bit36 */
			{ 8037,16,0}, /* core7 sp_EL2 bit37 */
			{ 8038,16,0}, /* core7 sp_EL2 bit38 */
			{ 8039,16,0}, /* core7 sp_EL2 bit39 */
			{ 8440,16,0}, /* core7 sp_EL2 bit40 */
			{ 8441,16,0}, /* core7 sp_EL2 bit41 */
			{ 8442,16,0}, /* core7 sp_EL2 bit42 */
			{ 8443,16,0}, /* core7 sp_EL2 bit43 */
			{ 8408,16,0}, /* core7 sp_EL2 bit44 */
			{ 8409,16,0}, /* core7 sp_EL2 bit45 */
			{ 8410,16,0}, /* core7 sp_EL2 bit46 */
			{ 8411,16,0}, /* core7 sp_EL2 bit47 */
			{ 8558,16,0}, /* core7 sp_EL2 bit48 */
			{ 8559,16,0}, /* core7 sp_EL2 bit49 */
			{ 8560,16,0}, /* core7 sp_EL2 bit50 */
			{ 8561,16,0}, /* core7 sp_EL2 bit51 */
			{ 8352,16,0}, /* core7 sp_EL2 bit52 */
			{ 8353,16,0}, /* core7 sp_EL2 bit53 */
			{ 8354,16,0}, /* core7 sp_EL2 bit54 */
			{ 8355,16,0}, /* core7 sp_EL2 bit55 */
			{ 8372,16,0}, /* core7 sp_EL2 bit56 */
			{ 8373,16,0}, /* core7 sp_EL2 bit57 */
			{ 8374,16,0}, /* core7 sp_EL2 bit58 */
			{ 8375,16,0}, /* core7 sp_EL2 bit59 */
			{ 8400,16,0}, /* core7 sp_EL2 bit60 */
			{ 8401,16,0}, /* core7 sp_EL2 bit61 */
			{ 8402,16,0}, /* core7 sp_EL2 bit62 */
			{ 8403,16,0}, /* core7 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6499,16,0}, /* core7 sp_EL3 bit0 */
			{ 6498,16,0}, /* core7 sp_EL3 bit1 */
			{ 6497,16,0}, /* core7 sp_EL3 bit2 */
			{ 6496,16,0}, /* core7 sp_EL3 bit3 */
			{16302,16,0}, /* core7 sp_EL3 bit4 */
			{ 7235,16,0}, /* core7 sp_EL3 bit5 */
			{16301,16,0}, /* core7 sp_EL3 bit6 */
			{ 7234,16,0}, /* core7 sp_EL3 bit7 */
			{ 7247,16,0}, /* core7 sp_EL3 bit8 */
			{ 7246,16,0}, /* core7 sp_EL3 bit9 */
			{ 7245,16,0}, /* core7 sp_EL3 bit10 */
			{ 7244,16,0}, /* core7 sp_EL3 bit11 */
			{ 7243,16,0}, /* core7 sp_EL3 bit12 */
			{ 7242,16,0}, /* core7 sp_EL3 bit13 */
			{ 7241,16,0}, /* core7 sp_EL3 bit14 */
			{ 7233,16,0}, /* core7 sp_EL3 bit15 */
			{ 7240,16,0}, /* core7 sp_EL3 bit16 */
			{ 7223,16,0}, /* core7 sp_EL3 bit17 */
			{ 7222,16,0}, /* core7 sp_EL3 bit18 */
			{ 7221,16,0}, /* core7 sp_EL3 bit19 */
			{ 8663,16,0}, /* core7 sp_EL3 bit20 */
			{ 8662,16,0}, /* core7 sp_EL3 bit21 */
			{ 6445,16,0}, /* core7 sp_EL3 bit22 */
			{ 6463,16,0}, /* core7 sp_EL3 bit23 */
			{ 7232,16,0}, /* core7 sp_EL3 bit24 */
			{16288,16,0}, /* core7 sp_EL3 bit25 */
			{ 7220,16,0}, /* core7 sp_EL3 bit26 */
			{16287,16,0}, /* core7 sp_EL3 bit27 */
			{ 8661,16,0}, /* core7 sp_EL3 bit28 */
			{ 8660,16,0}, /* core7 sp_EL3 bit29 */
			{ 6444,16,0}, /* core7 sp_EL3 bit30 */
			{ 6446,16,0}, /* core7 sp_EL3 bit31 */
			{ 6816,16,0}, /* core7 sp_EL3 bit32 */
			{ 6817,16,0}, /* core7 sp_EL3 bit33 */
			{ 6818,16,0}, /* core7 sp_EL3 bit34 */
			{ 6819,16,0}, /* core7 sp_EL3 bit35 */
			{ 6808,16,0}, /* core7 sp_EL3 bit36 */
			{ 6809,16,0}, /* core7 sp_EL3 bit37 */
			{ 6810,16,0}, /* core7 sp_EL3 bit38 */
			{ 6811,16,0}, /* core7 sp_EL3 bit39 */
			{   56,16,0}, /* core7 sp_EL3 bit40 */
			{   57,16,0}, /* core7 sp_EL3 bit41 */
			{   58,16,0}, /* core7 sp_EL3 bit42 */
			{   59,16,0}, /* core7 sp_EL3 bit43 */
			{   80,16,0}, /* core7 sp_EL3 bit44 */
			{   81,16,0}, /* core7 sp_EL3 bit45 */
			{   82,16,0}, /* core7 sp_EL3 bit46 */
			{   83,16,0}, /* core7 sp_EL3 bit47 */
			{  144,16,0}, /* core7 sp_EL3 bit48 */
			{  145,16,0}, /* core7 sp_EL3 bit49 */
			{  146,16,0}, /* core7 sp_EL3 bit50 */
			{  147,16,0}, /* core7 sp_EL3 bit51 */
			{ 8088,16,0}, /* core7 sp_EL3 bit52 */
			{ 8089,16,0}, /* core7 sp_EL3 bit53 */
			{ 8090,16,0}, /* core7 sp_EL3 bit54 */
			{ 8091,16,0}, /* core7 sp_EL3 bit55 */
			{  132,16,0}, /* core7 sp_EL3 bit56 */
			{  133,16,0}, /* core7 sp_EL3 bit57 */
			{  134,16,0}, /* core7 sp_EL3 bit58 */
			{  135,16,0}, /* core7 sp_EL3 bit59 */
			{  120,16,0}, /* core7 sp_EL3 bit60 */
			{  121,16,0}, /* core7 sp_EL3 bit61 */
			{  122,16,0}, /* core7 sp_EL3 bit62 */
			{  123,16,0}, /* core7 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{16306,16,0}, /* core7 elr_EL1 bit0 */
			{16305,16,0}, /* core7 elr_EL1 bit1 */
			{16308,16,0}, /* core7 elr_EL1 bit2 */
			{16307,16,0}, /* core7 elr_EL1 bit3 */
			{ 7275,16,0}, /* core7 elr_EL1 bit4 */
			{ 7274,16,0}, /* core7 elr_EL1 bit5 */
			{ 5306,17,0}, /* core7 elr_EL1 bit6 */
			{ 7273,16,0}, /* core7 elr_EL1 bit7 */
			{ 7272,16,0}, /* core7 elr_EL1 bit8 */
			{ 7255,16,0}, /* core7 elr_EL1 bit9 */
			{ 7254,16,0}, /* core7 elr_EL1 bit10 */
			{ 7253,16,0}, /* core7 elr_EL1 bit11 */
			{ 7252,16,0}, /* core7 elr_EL1 bit12 */
			{ 7239,16,0}, /* core7 elr_EL1 bit13 */
			{ 7238,16,0}, /* core7 elr_EL1 bit14 */
			{ 7237,16,0}, /* core7 elr_EL1 bit15 */
			{ 7236,16,0}, /* core7 elr_EL1 bit16 */
			{  475,17,0}, /* core7 elr_EL1 bit17 */
			{  474,17,0}, /* core7 elr_EL1 bit18 */
			{ 8683,16,0}, /* core7 elr_EL1 bit19 */
			{ 6433,16,0}, /* core7 elr_EL1 bit20 */
			{ 8655,16,0}, /* core7 elr_EL1 bit21 */
			{ 8654,16,0}, /* core7 elr_EL1 bit22 */
			{ 8682,16,0}, /* core7 elr_EL1 bit23 */
			{16310,16,0}, /* core7 elr_EL1 bit24 */
			{16309,16,0}, /* core7 elr_EL1 bit25 */
			{  473,17,0}, /* core7 elr_EL1 bit26 */
			{  472,17,0}, /* core7 elr_EL1 bit27 */
			{ 6434,16,0}, /* core7 elr_EL1 bit28 */
			{ 6432,16,0}, /* core7 elr_EL1 bit29 */
			{ 6443,16,0}, /* core7 elr_EL1 bit30 */
			{ 6431,16,0}, /* core7 elr_EL1 bit31 */
			{  244,16,0}, /* core7 elr_EL1 bit32 */
			{  245,16,0}, /* core7 elr_EL1 bit33 */
			{  246,16,0}, /* core7 elr_EL1 bit34 */
			{  247,16,0}, /* core7 elr_EL1 bit35 */
			{  224,16,0}, /* core7 elr_EL1 bit36 */
			{  225,16,0}, /* core7 elr_EL1 bit37 */
			{  226,16,0}, /* core7 elr_EL1 bit38 */
			{  227,16,0}, /* core7 elr_EL1 bit39 */
			{  228,16,0}, /* core7 elr_EL1 bit40 */
			{  229,16,0}, /* core7 elr_EL1 bit41 */
			{  230,16,0}, /* core7 elr_EL1 bit42 */
			{  231,16,0}, /* core7 elr_EL1 bit43 */
			{  232,16,0}, /* core7 elr_EL1 bit44 */
			{  233,16,0}, /* core7 elr_EL1 bit45 */
			{  234,16,0}, /* core7 elr_EL1 bit46 */
			{  235,16,0}, /* core7 elr_EL1 bit47 */
			{ 7548,16,0}, /* core7 elr_EL1 bit48 */
			{ 7549,16,0}, /* core7 elr_EL1 bit49 */
			{ 7550,16,0}, /* core7 elr_EL1 bit50 */
			{ 7551,16,0}, /* core7 elr_EL1 bit51 */
			{ 7556,16,0}, /* core7 elr_EL1 bit52 */
			{ 7557,16,0}, /* core7 elr_EL1 bit53 */
			{ 7558,16,0}, /* core7 elr_EL1 bit54 */
			{ 7559,16,0}, /* core7 elr_EL1 bit55 */
			{ 7560,16,0}, /* core7 elr_EL1 bit56 */
			{ 7561,16,0}, /* core7 elr_EL1 bit57 */
			{ 7562,16,0}, /* core7 elr_EL1 bit58 */
			{ 7563,16,0}, /* core7 elr_EL1 bit59 */
			{ 7552,16,0}, /* core7 elr_EL1 bit60 */
			{ 7553,16,0}, /* core7 elr_EL1 bit61 */
			{ 7554,16,0}, /* core7 elr_EL1 bit62 */
			{ 7555,16,0}, /* core7 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 6467,16,0}, /* core7 elr_EL2 bit0 */
			{ 6466,16,0}, /* core7 elr_EL2 bit1 */
			{ 6465,16,0}, /* core7 elr_EL2 bit2 */
			{ 6464,16,0}, /* core7 elr_EL2 bit3 */
			{ 5322,17,0}, /* core7 elr_EL2 bit4 */
			{ 5314,17,0}, /* core7 elr_EL2 bit5 */
			{  461,17,0}, /* core7 elr_EL2 bit6 */
			{  460,17,0}, /* core7 elr_EL2 bit7 */
			{  447,17,0}, /* core7 elr_EL2 bit8 */
			{  446,17,0}, /* core7 elr_EL2 bit9 */
			{ 5313,17,0}, /* core7 elr_EL2 bit10 */
			{ 5315,17,0}, /* core7 elr_EL2 bit11 */
			{  459,17,0}, /* core7 elr_EL2 bit12 */
			{  458,17,0}, /* core7 elr_EL2 bit13 */
			{  463,17,0}, /* core7 elr_EL2 bit14 */
			{  462,17,0}, /* core7 elr_EL2 bit15 */
			{ 5335,17,0}, /* core7 elr_EL2 bit16 */
			{  467,17,0}, /* core7 elr_EL2 bit17 */
			{  466,17,0}, /* core7 elr_EL2 bit18 */
			{16290,16,0}, /* core7 elr_EL2 bit19 */
			{16289,16,0}, /* core7 elr_EL2 bit20 */
			{ 8675,16,0}, /* core7 elr_EL2 bit21 */
			{ 8674,16,0}, /* core7 elr_EL2 bit22 */
			{ 8677,16,0}, /* core7 elr_EL2 bit23 */
			{16292,16,0}, /* core7 elr_EL2 bit24 */
			{16291,16,0}, /* core7 elr_EL2 bit25 */
			{16294,16,0}, /* core7 elr_EL2 bit26 */
			{16293,16,0}, /* core7 elr_EL2 bit27 */
			{ 8676,16,0}, /* core7 elr_EL2 bit28 */
			{ 1999,16,0}, /* core7 elr_EL2 bit29 */
			{ 6454,16,0}, /* core7 elr_EL2 bit30 */
			{ 6455,16,0}, /* core7 elr_EL2 bit31 */
			{ 6820,16,0}, /* core7 elr_EL2 bit32 */
			{ 6821,16,0}, /* core7 elr_EL2 bit33 */
			{ 6822,16,0}, /* core7 elr_EL2 bit34 */
			{ 6823,16,0}, /* core7 elr_EL2 bit35 */
			{   12,16,0}, /* core7 elr_EL2 bit36 */
			{   13,16,0}, /* core7 elr_EL2 bit37 */
			{   14,16,0}, /* core7 elr_EL2 bit38 */
			{   15,16,0}, /* core7 elr_EL2 bit39 */
			{   92,16,0}, /* core7 elr_EL2 bit40 */
			{   93,16,0}, /* core7 elr_EL2 bit41 */
			{   94,16,0}, /* core7 elr_EL2 bit42 */
			{   95,16,0}, /* core7 elr_EL2 bit43 */
			{  100,16,0}, /* core7 elr_EL2 bit44 */
			{  101,16,0}, /* core7 elr_EL2 bit45 */
			{  102,16,0}, /* core7 elr_EL2 bit46 */
			{  103,16,0}, /* core7 elr_EL2 bit47 */
			{  152,16,0}, /* core7 elr_EL2 bit48 */
			{  153,16,0}, /* core7 elr_EL2 bit49 */
			{  154,16,0}, /* core7 elr_EL2 bit50 */
			{  155,16,0}, /* core7 elr_EL2 bit51 */
			{ 8092,16,0}, /* core7 elr_EL2 bit52 */
			{ 8093,16,0}, /* core7 elr_EL2 bit53 */
			{ 8094,16,0}, /* core7 elr_EL2 bit54 */
			{ 8095,16,0}, /* core7 elr_EL2 bit55 */
			{  136,16,0}, /* core7 elr_EL2 bit56 */
			{  137,16,0}, /* core7 elr_EL2 bit57 */
			{  138,16,0}, /* core7 elr_EL2 bit58 */
			{  139,16,0}, /* core7 elr_EL2 bit59 */
			{ 8068,16,0}, /* core7 elr_EL2 bit60 */
			{ 8069,16,0}, /* core7 elr_EL2 bit61 */
			{ 8070,16,0}, /* core7 elr_EL2 bit62 */
			{ 8071,16,0}, /* core7 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 7947,16,0}, /* core7 elr_EL3 bit0 */
			{ 7946,16,0}, /* core7 elr_EL3 bit1 */
			{ 7945,16,0}, /* core7 elr_EL3 bit2 */
			{ 7944,16,0}, /* core7 elr_EL3 bit3 */
			{ 6932,16,0}, /* core7 elr_EL3 bit4 */
			{ 6933,16,0}, /* core7 elr_EL3 bit5 */
			{ 6934,16,0}, /* core7 elr_EL3 bit6 */
			{ 6935,16,0}, /* core7 elr_EL3 bit7 */
			{ 6644,16,0}, /* core7 elr_EL3 bit8 */
			{ 6645,16,0}, /* core7 elr_EL3 bit9 */
			{ 6646,16,0}, /* core7 elr_EL3 bit10 */
			{ 6647,16,0}, /* core7 elr_EL3 bit11 */
			{ 6640,16,0}, /* core7 elr_EL3 bit12 */
			{ 6641,16,0}, /* core7 elr_EL3 bit13 */
			{ 6642,16,0}, /* core7 elr_EL3 bit14 */
			{ 6643,16,0}, /* core7 elr_EL3 bit15 */
			{ 6636,16,0}, /* core7 elr_EL3 bit16 */
			{ 6637,16,0}, /* core7 elr_EL3 bit17 */
			{ 6638,16,0}, /* core7 elr_EL3 bit18 */
			{ 6639,16,0}, /* core7 elr_EL3 bit19 */
			{ 7932,16,0}, /* core7 elr_EL3 bit20 */
			{ 7933,16,0}, /* core7 elr_EL3 bit21 */
			{ 7934,16,0}, /* core7 elr_EL3 bit22 */
			{ 7935,16,0}, /* core7 elr_EL3 bit23 */
			{ 6936,16,0}, /* core7 elr_EL3 bit24 */
			{ 6937,16,0}, /* core7 elr_EL3 bit25 */
			{ 6938,16,0}, /* core7 elr_EL3 bit26 */
			{ 6939,16,0}, /* core7 elr_EL3 bit27 */
			{ 7928,16,0}, /* core7 elr_EL3 bit28 */
			{ 7929,16,0}, /* core7 elr_EL3 bit29 */
			{ 7930,16,0}, /* core7 elr_EL3 bit30 */
			{ 7931,16,0}, /* core7 elr_EL3 bit31 */
			{ 8040,16,0}, /* core7 elr_EL3 bit32 */
			{ 8041,16,0}, /* core7 elr_EL3 bit33 */
			{ 8042,16,0}, /* core7 elr_EL3 bit34 */
			{ 8043,16,0}, /* core7 elr_EL3 bit35 */
			{ 8412,16,0}, /* core7 elr_EL3 bit36 */
			{ 8413,16,0}, /* core7 elr_EL3 bit37 */
			{ 8414,16,0}, /* core7 elr_EL3 bit38 */
			{ 8415,16,0}, /* core7 elr_EL3 bit39 */
			{ 8032,16,0}, /* core7 elr_EL3 bit40 */
			{ 8033,16,0}, /* core7 elr_EL3 bit41 */
			{ 8034,16,0}, /* core7 elr_EL3 bit42 */
			{ 8035,16,0}, /* core7 elr_EL3 bit43 */
			{ 8404,16,0}, /* core7 elr_EL3 bit44 */
			{ 8405,16,0}, /* core7 elr_EL3 bit45 */
			{ 8406,16,0}, /* core7 elr_EL3 bit46 */
			{ 8407,16,0}, /* core7 elr_EL3 bit47 */
			{ 8566,16,0}, /* core7 elr_EL3 bit48 */
			{ 8567,16,0}, /* core7 elr_EL3 bit49 */
			{ 8568,16,0}, /* core7 elr_EL3 bit50 */
			{ 8569,16,0}, /* core7 elr_EL3 bit51 */
			{ 8360,16,0}, /* core7 elr_EL3 bit52 */
			{ 8361,16,0}, /* core7 elr_EL3 bit53 */
			{ 8362,16,0}, /* core7 elr_EL3 bit54 */
			{ 8363,16,0}, /* core7 elr_EL3 bit55 */
			{ 8562,16,0}, /* core7 elr_EL3 bit56 */
			{ 8563,16,0}, /* core7 elr_EL3 bit57 */
			{ 8564,16,0}, /* core7 elr_EL3 bit58 */
			{ 8565,16,0}, /* core7 elr_EL3 bit59 */
			{ 8392,16,0}, /* core7 elr_EL3 bit60 */
			{ 8393,16,0}, /* core7 elr_EL3 bit61 */
			{ 8394,16,0}, /* core7 elr_EL3 bit62 */
			{ 8395,16,0}, /* core7 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{17159,16,0}, /* core7 raw_pc bit0 */
			{14566,16,0}, /* core7 raw_pc bit1 */
			{14567,16,0}, /* core7 raw_pc bit2 */
			{13688,16,0}, /* core7 raw_pc bit3 */
			{13689,16,0}, /* core7 raw_pc bit4 */
			{13690,16,0}, /* core7 raw_pc bit5 */
			{13691,16,0}, /* core7 raw_pc bit6 */
			{ 1390,17,0}, /* core7 raw_pc bit7 */
			{ 1391,17,0}, /* core7 raw_pc bit8 */
			{ 1392,17,0}, /* core7 raw_pc bit9 */
			{ 1393,17,0}, /* core7 raw_pc bit10 */
			{ 1410,17,0}, /* core7 raw_pc bit11 */
			{ 1411,17,0}, /* core7 raw_pc bit12 */
			{ 1412,17,0}, /* core7 raw_pc bit13 */
			{ 1413,17,0}, /* core7 raw_pc bit14 */
			{13896,16,0}, /* core7 raw_pc bit15 */
			{13897,16,0}, /* core7 raw_pc bit16 */
			{13898,16,0}, /* core7 raw_pc bit17 */
			{13899,16,0}, /* core7 raw_pc bit18 */
			{ 1426,17,0}, /* core7 raw_pc bit19 */
			{ 1427,17,0}, /* core7 raw_pc bit20 */
			{ 1428,17,0}, /* core7 raw_pc bit21 */
			{ 1429,17,0}, /* core7 raw_pc bit22 */
			{ 1430,17,0}, /* core7 raw_pc bit23 */
			{ 1431,17,0}, /* core7 raw_pc bit24 */
			{ 1432,17,0}, /* core7 raw_pc bit25 */
			{ 1433,17,0}, /* core7 raw_pc bit26 */
			{ 1434,17,0}, /* core7 raw_pc bit27 */
			{ 1435,17,0}, /* core7 raw_pc bit28 */
			{ 1436,17,0}, /* core7 raw_pc bit29 */
			{ 1437,17,0}, /* core7 raw_pc bit30 */
			{15938,16,0}, /* core7 raw_pc bit31 */
			{13480,16,0}, /* core7 raw_pc bit32 */
			{13481,16,0}, /* core7 raw_pc bit33 */
			{13482,16,0}, /* core7 raw_pc bit34 */
			{13483,16,0}, /* core7 raw_pc bit35 */
			{13476,16,0}, /* core7 raw_pc bit36 */
			{13477,16,0}, /* core7 raw_pc bit37 */
			{13478,16,0}, /* core7 raw_pc bit38 */
			{13479,16,0}, /* core7 raw_pc bit39 */
			{13496,16,0}, /* core7 raw_pc bit40 */
			{13497,16,0}, /* core7 raw_pc bit41 */
			{13498,16,0}, /* core7 raw_pc bit42 */
			{13499,16,0}, /* core7 raw_pc bit43 */
			{13500,16,0}, /* core7 raw_pc bit44 */
			{13501,16,0}, /* core7 raw_pc bit45 */
			{13502,16,0}, /* core7 raw_pc bit46 */
			{13503,16,0}, /* core7 raw_pc bit47 */
			{    0, 0,2}, /* core7 raw_pc bit48 */
			{    0, 0,2}, /* core7 raw_pc bit49 */
			{    0, 0,2}, /* core7 raw_pc bit50 */
			{    0, 0,2}, /* core7 raw_pc bit51 */
			{    0, 0,2}, /* core7 raw_pc bit52 */
			{    0, 0,2}, /* core7 raw_pc bit53 */
			{    0, 0,2}, /* core7 raw_pc bit54 */
			{    0, 0,2}, /* core7 raw_pc bit55 */
			{    0, 0,2}, /* core7 raw_pc bit56 */
			{    0, 0,2}, /* core7 raw_pc bit57 */
			{    0, 0,2}, /* core7 raw_pc bit58 */
			{    0, 0,2}, /* core7 raw_pc bit59 */
			{    0, 0,2}, /* core7 raw_pc bit60 */
			{    0, 0,2}, /* core7 raw_pc bit61 */
			{    0, 0,2}, /* core7 raw_pc bit62 */
			{    0, 0,2}, /* core7 raw_pc bit63 */
			}},
			.pc_iss = {{
			{12164,16,0}, /* core7 pc_iss bit0 */
			{12165,16,0}, /* core7 pc_iss bit1 */
			{12166,16,0}, /* core7 pc_iss bit2 */
			{12167,16,0}, /* core7 pc_iss bit3 */
			{13860,16,0}, /* core7 pc_iss bit4 */
			{13861,16,0}, /* core7 pc_iss bit5 */
			{13862,16,0}, /* core7 pc_iss bit6 */
			{13863,16,0}, /* core7 pc_iss bit7 */
			{13420,16,0}, /* core7 pc_iss bit8 */
			{13421,16,0}, /* core7 pc_iss bit9 */
			{13422,16,0}, /* core7 pc_iss bit10 */
			{13423,16,0}, /* core7 pc_iss bit11 */
			{13428,16,0}, /* core7 pc_iss bit12 */
			{13429,16,0}, /* core7 pc_iss bit13 */
			{13430,16,0}, /* core7 pc_iss bit14 */
			{13431,16,0}, /* core7 pc_iss bit15 */
			{13408,16,0}, /* core7 pc_iss bit16 */
			{13409,16,0}, /* core7 pc_iss bit17 */
			{13410,16,0}, /* core7 pc_iss bit18 */
			{13411,16,0}, /* core7 pc_iss bit19 */
			{13412,16,0}, /* core7 pc_iss bit20 */
			{13413,16,0}, /* core7 pc_iss bit21 */
			{13414,16,0}, /* core7 pc_iss bit22 */
			{13415,16,0}, /* core7 pc_iss bit23 */
			{13424,16,0}, /* core7 pc_iss bit24 */
			{13425,16,0}, /* core7 pc_iss bit25 */
			{13426,16,0}, /* core7 pc_iss bit26 */
			{13427,16,0}, /* core7 pc_iss bit27 */
			{13416,16,0}, /* core7 pc_iss bit28 */
			{13417,16,0}, /* core7 pc_iss bit29 */
			{13418,16,0}, /* core7 pc_iss bit30 */
			{13419,16,0}, /* core7 pc_iss bit31 */
			{13508,16,0}, /* core7 pc_iss bit32 */
			{13509,16,0}, /* core7 pc_iss bit33 */
			{13510,16,0}, /* core7 pc_iss bit34 */
			{13511,16,0}, /* core7 pc_iss bit35 */
			{13504,16,0}, /* core7 pc_iss bit36 */
			{13505,16,0}, /* core7 pc_iss bit37 */
			{13506,16,0}, /* core7 pc_iss bit38 */
			{13507,16,0}, /* core7 pc_iss bit39 */
			{13520,16,0}, /* core7 pc_iss bit40 */
			{13521,16,0}, /* core7 pc_iss bit41 */
			{13522,16,0}, /* core7 pc_iss bit42 */
			{13523,16,0}, /* core7 pc_iss bit43 */
			{13524,16,0}, /* core7 pc_iss bit44 */
			{13525,16,0}, /* core7 pc_iss bit45 */
			{13526,16,0}, /* core7 pc_iss bit46 */
			{13527,16,0}, /* core7 pc_iss bit47 */
			{13540,16,0}, /* core7 pc_iss bit48 */
			{13541,16,0}, /* core7 pc_iss bit49 */
			{13542,16,0}, /* core7 pc_iss bit50 */
			{13543,16,0}, /* core7 pc_iss bit51 */
			{13528,16,0}, /* core7 pc_iss bit52 */
			{13529,16,0}, /* core7 pc_iss bit53 */
			{13530,16,0}, /* core7 pc_iss bit54 */
			{13531,16,0}, /* core7 pc_iss bit55 */
			{13544,16,0}, /* core7 pc_iss bit56 */
			{13545,16,0}, /* core7 pc_iss bit57 */
			{13546,16,0}, /* core7 pc_iss bit58 */
			{13547,16,0}, /* core7 pc_iss bit59 */
			{13548,16,0}, /* core7 pc_iss bit60 */
			{13549,16,0}, /* core7 pc_iss bit61 */
			{13550,16,0}, /* core7 pc_iss bit62 */
			{13551,16,0}, /* core7 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{17168,16,0}, /* core7 full_pc_wr bit0 */
			{    0, 0,2}, /* core7 full_pc_wr bit1 */
			{    0, 0,2}, /* core7 full_pc_wr bit2 */
			{    0, 0,2}, /* core7 full_pc_wr bit3 */
			{    0, 0,2}, /* core7 full_pc_wr bit4 */
			{    0, 0,2}, /* core7 full_pc_wr bit5 */
			{    0, 0,2}, /* core7 full_pc_wr bit6 */
			{    0, 0,2}, /* core7 full_pc_wr bit7 */
			{    0, 0,2}, /* core7 full_pc_wr bit8 */
			{    0, 0,2}, /* core7 full_pc_wr bit9 */
			{    0, 0,2}, /* core7 full_pc_wr bit10 */
			{    0, 0,2}, /* core7 full_pc_wr bit11 */
			{    0, 0,2}, /* core7 full_pc_wr bit12 */
			{    0, 0,2}, /* core7 full_pc_wr bit13 */
			{    0, 0,2}, /* core7 full_pc_wr bit14 */
			{    0, 0,2}, /* core7 full_pc_wr bit15 */
			{    0, 0,2}, /* core7 full_pc_wr bit16 */
			{    0, 0,2}, /* core7 full_pc_wr bit17 */
			{    0, 0,2}, /* core7 full_pc_wr bit18 */
			{    0, 0,2}, /* core7 full_pc_wr bit19 */
			{    0, 0,2}, /* core7 full_pc_wr bit20 */
			{    0, 0,2}, /* core7 full_pc_wr bit21 */
			{    0, 0,2}, /* core7 full_pc_wr bit22 */
			{    0, 0,2}, /* core7 full_pc_wr bit23 */
			{    0, 0,2}, /* core7 full_pc_wr bit24 */
			{    0, 0,2}, /* core7 full_pc_wr bit25 */
			{    0, 0,2}, /* core7 full_pc_wr bit26 */
			{    0, 0,2}, /* core7 full_pc_wr bit27 */
			{    0, 0,2}, /* core7 full_pc_wr bit28 */
			{    0, 0,2}, /* core7 full_pc_wr bit29 */
			{    0, 0,2}, /* core7 full_pc_wr bit30 */
			{    0, 0,2}, /* core7 full_pc_wr bit31 */
			{    0, 0,2}, /* core7 full_pc_wr bit32 */
			{    0, 0,2}, /* core7 full_pc_wr bit33 */
			{    0, 0,2}, /* core7 full_pc_wr bit34 */
			{    0, 0,2}, /* core7 full_pc_wr bit35 */
			{    0, 0,2}, /* core7 full_pc_wr bit36 */
			{    0, 0,2}, /* core7 full_pc_wr bit37 */
			{    0, 0,2}, /* core7 full_pc_wr bit38 */
			{    0, 0,2}, /* core7 full_pc_wr bit39 */
			{    0, 0,2}, /* core7 full_pc_wr bit40 */
			{    0, 0,2}, /* core7 full_pc_wr bit41 */
			{    0, 0,2}, /* core7 full_pc_wr bit42 */
			{    0, 0,2}, /* core7 full_pc_wr bit43 */
			{    0, 0,2}, /* core7 full_pc_wr bit44 */
			{    0, 0,2}, /* core7 full_pc_wr bit45 */
			{    0, 0,2}, /* core7 full_pc_wr bit46 */
			{    0, 0,2}, /* core7 full_pc_wr bit47 */
			{    0, 0,2}, /* core7 full_pc_wr bit48 */
			{    0, 0,2}, /* core7 full_pc_wr bit49 */
			{    0, 0,2}, /* core7 full_pc_wr bit50 */
			{    0, 0,2}, /* core7 full_pc_wr bit51 */
			{    0, 0,2}, /* core7 full_pc_wr bit52 */
			{    0, 0,2}, /* core7 full_pc_wr bit53 */
			{    0, 0,2}, /* core7 full_pc_wr bit54 */
			{    0, 0,2}, /* core7 full_pc_wr bit55 */
			{    0, 0,2}, /* core7 full_pc_wr bit56 */
			{    0, 0,2}, /* core7 full_pc_wr bit57 */
			{    0, 0,2}, /* core7 full_pc_wr bit58 */
			{    0, 0,2}, /* core7 full_pc_wr bit59 */
			{    0, 0,2}, /* core7 full_pc_wr bit60 */
			{    0, 0,2}, /* core7 full_pc_wr bit61 */
			{    0, 0,2}, /* core7 full_pc_wr bit62 */
			{    0, 0,2}, /* core7 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{14569,16,0}, /* core7 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core7 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{17170,16,0}, /* core7 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core7 full_pc_ex2 bit63 */
			}},
	},
};

struct big_core_spec big_core[] = {
};
