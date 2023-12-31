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
			{    2, 0,0}, /* core4 power on */
			{    2,10,0}, /* core4 retention on */
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
			{    2, 1,0}, /* core5 power on */
			{    2,11,0}, /* core5 retention on */
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
			{    2, 2,0}, /* core6 power on */
			{    2,12,0}, /* core6 retention on */
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
			{    2, 3,0}, /* core7 power on */
			{    2,13,0}, /* core7 retention on */
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
			{ 9802,34,0}, /* core0 pc bit0 */
			{ 9803, 4,0}, /* core0 pc bit1 */
			{ 9803,38,0}, /* core0 pc bit2 */
			{ 9804, 8,0}, /* core0 pc bit3 */
			{ 9783,26,0}, /* core0 pc bit4 */
			{ 9783,60,0}, /* core0 pc bit5 */
			{ 9784,30,0}, /* core0 pc bit6 */
			{ 9785, 0,0}, /* core0 pc bit7 */
			{ 9804,42,0}, /* core0 pc bit8 */
			{ 9805,12,0}, /* core0 pc bit9 */
			{ 9805,46,0}, /* core0 pc bit10 */
			{ 9806,16,0}, /* core0 pc bit11 */
			{ 9787,42,0}, /* core0 pc bit12 */
			{ 9788,12,0}, /* core0 pc bit13 */
			{ 9788,46,0}, /* core0 pc bit14 */
			{ 9789,16,0}, /* core0 pc bit15 */
			{ 9800,26,0}, /* core0 pc bit16 */
			{ 9800,60,0}, /* core0 pc bit17 */
			{ 9801,30,0}, /* core0 pc bit18 */
			{ 9802, 0,0}, /* core0 pc bit19 */
			{ 2319,13,0}, /* core0 pc bit20 */
			{ 2320,11,0}, /* core0 pc bit21 */
			{ 2321, 9,0}, /* core0 pc bit22 */
			{ 2322, 7,0}, /* core0 pc bit23 */
			{ 2315,21,0}, /* core0 pc bit24 */
			{ 2316,19,0}, /* core0 pc bit25 */
			{ 2317,17,0}, /* core0 pc bit26 */
			{ 2318,15,0}, /* core0 pc bit27 */
			{ 2299,53,0}, /* core0 pc bit28 */
			{ 2300,51,0}, /* core0 pc bit29 */
			{ 2301,49,0}, /* core0 pc bit30 */
			{ 2302,47,0}, /* core0 pc bit31 */
			{ 9796,10,0}, /* core0 pc bit32 */
			{ 9796,44,0}, /* core0 pc bit33 */
			{ 9797,14,0}, /* core0 pc bit34 */
			{ 9797,48,0}, /* core0 pc bit35 */
			{   12,38,0}, /* core0 pc bit36 */
			{   13,36,0}, /* core0 pc bit37 */
			{   14,34,0}, /* core0 pc bit38 */
			{   15,32,0}, /* core0 pc bit39 */
			{ 9798,18,0}, /* core0 pc bit40 */
			{ 9798,52,0}, /* core0 pc bit41 */
			{ 9799,22,0}, /* core0 pc bit42 */
			{ 9799,56,0}, /* core0 pc bit43 */
			{   16,30,0}, /* core0 pc bit44 */
			{   17,28,0}, /* core0 pc bit45 */
			{   18,26,0}, /* core0 pc bit46 */
			{   19,24,0}, /* core0 pc bit47 */
			{ 9794, 2,0}, /* core0 pc bit48 */
			{ 9794,36,0}, /* core0 pc bit49 */
			{ 9795, 6,0}, /* core0 pc bit50 */
			{ 9795,40,0}, /* core0 pc bit51 */
			{ 9785,34,0}, /* core0 pc bit52 */
			{ 9786, 4,0}, /* core0 pc bit53 */
			{ 9786,38,0}, /* core0 pc bit54 */
			{ 9787, 8,0}, /* core0 pc bit55 */
			{ 2989,37,0}, /* core0 pc bit56 */
			{ 2990,35,0}, /* core0 pc bit57 */
			{ 2991,33,0}, /* core0 pc bit58 */
			{ 2992,31,0}, /* core0 pc bit59 */
			{   20,22,0}, /* core0 pc bit60 */
			{   21,20,0}, /* core0 pc bit61 */
			{   22,18,0}, /* core0 pc bit62 */
			{   23,16,0}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{ 5777, 9,0}, /* core0 sp32 bit0 */
			{ 5777,50,0}, /* core0 sp32 bit1 */
			{ 5778,27,0}, /* core0 sp32 bit2 */
			{ 5779, 4,0}, /* core0 sp32 bit3 */
			{ 5633,41,0}, /* core0 sp32 bit4 */
			{ 5634,18,0}, /* core0 sp32 bit5 */
			{ 5634,59,0}, /* core0 sp32 bit6 */
			{ 5635,36,0}, /* core0 sp32 bit7 */
			{ 2016,61,0}, /* core0 sp32 bit8 */
			{ 2017,59,0}, /* core0 sp32 bit9 */
			{ 2018,57,0}, /* core0 sp32 bit10 */
			{ 2019,55,0}, /* core0 sp32 bit11 */
			{ 5656,45,0}, /* core0 sp32 bit12 */
			{ 5657,22,0}, /* core0 sp32 bit13 */
			{ 5657,63,0}, /* core0 sp32 bit14 */
			{ 5658,40,0}, /* core0 sp32 bit15 */
			{ 5774,37,0}, /* core0 sp32 bit16 */
			{ 5775,14,0}, /* core0 sp32 bit17 */
			{ 5775,55,0}, /* core0 sp32 bit18 */
			{ 5776,32,0}, /* core0 sp32 bit19 */
			{ 5769,29,0}, /* core0 sp32 bit20 */
			{ 5770, 6,0}, /* core0 sp32 bit21 */
			{ 5770,47,0}, /* core0 sp32 bit22 */
			{ 5771,24,0}, /* core0 sp32 bit23 */
			{ 5748,61,0}, /* core0 sp32 bit24 */
			{ 5749,38,0}, /* core0 sp32 bit25 */
			{ 5750,15,0}, /* core0 sp32 bit26 */
			{ 5750,56,0}, /* core0 sp32 bit27 */
			{ 5654, 9,0}, /* core0 sp32 bit28 */
			{ 5654,50,0}, /* core0 sp32 bit29 */
			{ 5655,27,0}, /* core0 sp32 bit30 */
			{ 5656, 4,0}, /* core0 sp32 bit31 */
			{ 5203, 9,0}, /* core0 sp32 bit32 */
			{ 5203,50,0}, /* core0 sp32 bit33 */
			{ 5204,27,0}, /* core0 sp32 bit34 */
			{ 5205, 4,0}, /* core0 sp32 bit35 */
			{ 5356,57,0}, /* core0 sp32 bit36 */
			{ 5357,34,0}, /* core0 sp32 bit37 */
			{ 5358,11,0}, /* core0 sp32 bit38 */
			{ 5358,52,0}, /* core0 sp32 bit39 */
			{ 5133,20,0}, /* core0 sp32 bit40 */
			{ 5133,61,0}, /* core0 sp32 bit41 */
			{ 5134,38,0}, /* core0 sp32 bit42 */
			{ 5135,15,0}, /* core0 sp32 bit43 */
			{ 5123, 4,0}, /* core0 sp32 bit44 */
			{ 5123,45,0}, /* core0 sp32 bit45 */
			{ 5124,22,0}, /* core0 sp32 bit46 */
			{ 5124,63,0}, /* core0 sp32 bit47 */
			{ 5125,40,0}, /* core0 sp32 bit48 */
			{ 5126,17,0}, /* core0 sp32 bit49 */
			{ 5126,58,0}, /* core0 sp32 bit50 */
			{ 5127,35,0}, /* core0 sp32 bit51 */
			{ 5387,41,0}, /* core0 sp32 bit52 */
			{ 5388,18,0}, /* core0 sp32 bit53 */
			{ 5388,59,0}, /* core0 sp32 bit54 */
			{ 5389,36,0}, /* core0 sp32 bit55 */
			{ 5390,13,0}, /* core0 sp32 bit56 */
			{ 5390,54,0}, /* core0 sp32 bit57 */
			{ 5391,31,0}, /* core0 sp32 bit58 */
			{ 5392, 8,0}, /* core0 sp32 bit59 */
			{ 5392,49,0}, /* core0 sp32 bit60 */
			{ 5393,26,0}, /* core0 sp32 bit61 */
			{ 5394, 3,0}, /* core0 sp32 bit62 */
			{ 5394,44,0}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{ 6107,45,0}, /* core0 fp32 bit0 */
			{ 6108,22,0}, /* core0 fp32 bit1 */
			{ 6108,63,0}, /* core0 fp32 bit2 */
			{ 6109,40,0}, /* core0 fp32 bit3 */
			{ 6343,29,0}, /* core0 fp32 bit4 */
			{ 6344, 6,0}, /* core0 fp32 bit5 */
			{ 6344,47,0}, /* core0 fp32 bit6 */
			{ 6345,24,0}, /* core0 fp32 bit7 */
			{ 1013,21,1}, /* core0 fp32 bit8 */
			{ 1014,19,1}, /* core0 fp32 bit9 */
			{ 1015,17,1}, /* core0 fp32 bit10 */
			{ 1016,15,1}, /* core0 fp32 bit11 */
			{ 6340,57,0}, /* core0 fp32 bit12 */
			{ 6341,34,0}, /* core0 fp32 bit13 */
			{ 6342,11,0}, /* core0 fp32 bit14 */
			{ 6342,52,0}, /* core0 fp32 bit15 */
			{ 6079,33,0}, /* core0 fp32 bit16 */
			{ 6080,10,0}, /* core0 fp32 bit17 */
			{ 6080,51,0}, /* core0 fp32 bit18 */
			{ 6081,28,0}, /* core0 fp32 bit19 */
			{ 5951,25,0}, /* core0 fp32 bit20 */
			{ 5952, 2,0}, /* core0 fp32 bit21 */
			{ 5952,43,0}, /* core0 fp32 bit22 */
			{ 5953,20,0}, /* core0 fp32 bit23 */
			{ 6182, 1,0}, /* core0 fp32 bit24 */
			{ 6182,42,0}, /* core0 fp32 bit25 */
			{ 6183,19,0}, /* core0 fp32 bit26 */
			{ 6183,60,0}, /* core0 fp32 bit27 */
			{ 5841,13,0}, /* core0 fp32 bit28 */
			{ 5841,54,0}, /* core0 fp32 bit29 */
			{ 5842,31,0}, /* core0 fp32 bit30 */
			{ 5843, 8,0}, /* core0 fp32 bit31 */
			{ 5198, 1,0}, /* core0 fp32 bit32 */
			{ 5198,42,0}, /* core0 fp32 bit33 */
			{ 5199,19,0}, /* core0 fp32 bit34 */
			{ 5199,60,0}, /* core0 fp32 bit35 */
			{ 5195,29,0}, /* core0 fp32 bit36 */
			{ 5196, 6,0}, /* core0 fp32 bit37 */
			{ 5196,47,0}, /* core0 fp32 bit38 */
			{ 5197,24,0}, /* core0 fp32 bit39 */
			{ 5135,56,0}, /* core0 fp32 bit40 */
			{ 5136,33,0}, /* core0 fp32 bit41 */
			{ 5137,10,0}, /* core0 fp32 bit42 */
			{ 5137,51,0}, /* core0 fp32 bit43 */
			{ 5141, 0,0}, /* core0 fp32 bit44 */
			{ 5141,41,0}, /* core0 fp32 bit45 */
			{ 5142,18,0}, /* core0 fp32 bit46 */
			{ 5142,59,0}, /* core0 fp32 bit47 */
			{ 5128,12,0}, /* core0 fp32 bit48 */
			{ 5128,53,0}, /* core0 fp32 bit49 */
			{ 5129,30,0}, /* core0 fp32 bit50 */
			{ 5130, 7,0}, /* core0 fp32 bit51 */
			{ 5420,61,0}, /* core0 fp32 bit52 */
			{ 5421,38,0}, /* core0 fp32 bit53 */
			{ 5422,15,0}, /* core0 fp32 bit54 */
			{ 5422,56,0}, /* core0 fp32 bit55 */
			{ 5418,25,0}, /* core0 fp32 bit56 */
			{ 5419, 2,0}, /* core0 fp32 bit57 */
			{ 5419,43,0}, /* core0 fp32 bit58 */
			{ 5420,20,0}, /* core0 fp32 bit59 */
			{ 5200,37,0}, /* core0 fp32 bit60 */
			{ 5201,14,0}, /* core0 fp32 bit61 */
			{ 5201,55,0}, /* core0 fp32 bit62 */
			{ 5202,32,0}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{ 2024,45,0}, /* core0 fp64 bit0 */
			{ 2025,43,0}, /* core0 fp64 bit1 */
			{ 2026,41,0}, /* core0 fp64 bit2 */
			{ 2027,39,0}, /* core0 fp64 bit3 */
			{ 5643,57,0}, /* core0 fp64 bit4 */
			{ 5644,34,0}, /* core0 fp64 bit5 */
			{ 5645,11,0}, /* core0 fp64 bit6 */
			{ 5645,52,0}, /* core0 fp64 bit7 */
			{   28, 6,0}, /* core0 fp64 bit8 */
			{   29, 4,0}, /* core0 fp64 bit9 */
			{   30, 2,0}, /* core0 fp64 bit10 */
			{   31, 0,0}, /* core0 fp64 bit11 */
			{ 5646,29,0}, /* core0 fp64 bit12 */
			{ 5647, 6,0}, /* core0 fp64 bit13 */
			{ 5647,47,0}, /* core0 fp64 bit14 */
			{ 5648,24,0}, /* core0 fp64 bit15 */
			{ 5772, 1,0}, /* core0 fp64 bit16 */
			{ 5772,42,0}, /* core0 fp64 bit17 */
			{ 5773,19,0}, /* core0 fp64 bit18 */
			{ 5773,60,0}, /* core0 fp64 bit19 */
			{ 5756,41,0}, /* core0 fp64 bit20 */
			{ 5757,18,0}, /* core0 fp64 bit21 */
			{ 5757,59,0}, /* core0 fp64 bit22 */
			{ 5758,36,0}, /* core0 fp64 bit23 */
			{ 5692,37,0}, /* core0 fp64 bit24 */
			{ 5693,14,0}, /* core0 fp64 bit25 */
			{ 5693,55,0}, /* core0 fp64 bit26 */
			{ 5694,32,0}, /* core0 fp64 bit27 */
			{ 5746,25,0}, /* core0 fp64 bit28 */
			{ 5747, 2,0}, /* core0 fp64 bit29 */
			{ 5747,43,0}, /* core0 fp64 bit30 */
			{ 5748,20,0}, /* core0 fp64 bit31 */
			{ 5528,37,0}, /* core0 fp64 bit32 */
			{ 5529,14,0}, /* core0 fp64 bit33 */
			{ 5529,55,0}, /* core0 fp64 bit34 */
			{ 5530,32,0}, /* core0 fp64 bit35 */
			{ 5543,61,0}, /* core0 fp64 bit36 */
			{ 5544,38,0}, /* core0 fp64 bit37 */
			{ 5545,15,0}, /* core0 fp64 bit38 */
			{ 5545,56,0}, /* core0 fp64 bit39 */
			{ 5533,45,0}, /* core0 fp64 bit40 */
			{ 5534,22,0}, /* core0 fp64 bit41 */
			{ 5534,63,0}, /* core0 fp64 bit42 */
			{ 5535,40,0}, /* core0 fp64 bit43 */
			{ 5523,29,0}, /* core0 fp64 bit44 */
			{ 5524, 6,0}, /* core0 fp64 bit45 */
			{ 5524,47,0}, /* core0 fp64 bit46 */
			{ 5525,24,0}, /* core0 fp64 bit47 */
			{ 5590, 5,0}, /* core0 fp64 bit48 */
			{ 5590,46,0}, /* core0 fp64 bit49 */
			{ 5591,23,0}, /* core0 fp64 bit50 */
			{ 5592, 0,0}, /* core0 fp64 bit51 */
			{ 5541,25,0}, /* core0 fp64 bit52 */
			{ 5542, 2,0}, /* core0 fp64 bit53 */
			{ 5542,43,0}, /* core0 fp64 bit54 */
			{ 5543,20,0}, /* core0 fp64 bit55 */
			{ 5531, 9,0}, /* core0 fp64 bit56 */
			{ 5531,50,0}, /* core0 fp64 bit57 */
			{ 5532,27,0}, /* core0 fp64 bit58 */
			{ 5533, 4,0}, /* core0 fp64 bit59 */
			{ 5526, 1,0}, /* core0 fp64 bit60 */
			{ 5526,42,0}, /* core0 fp64 bit61 */
			{ 5527,19,0}, /* core0 fp64 bit62 */
			{ 5527,60,0}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 7711,53,1}, /* core0 sp_EL0 bit0 */
			{ 7712,30,1}, /* core0 sp_EL0 bit1 */
			{ 7713, 7,1}, /* core0 sp_EL0 bit2 */
			{ 7713,48,1}, /* core0 sp_EL0 bit3 */
			{ 6387, 1,0}, /* core0 sp_EL0 bit4 */
			{ 6387,42,0}, /* core0 sp_EL0 bit5 */
			{ 6388,19,0}, /* core0 sp_EL0 bit6 */
			{ 6388,60,0}, /* core0 sp_EL0 bit7 */
			{ 6033,25,0}, /* core0 sp_EL0 bit8 */
			{ 6034, 2,0}, /* core0 sp_EL0 bit9 */
			{ 6034,43,0}, /* core0 sp_EL0 bit10 */
			{ 6035,20,0}, /* core0 sp_EL0 bit11 */
			{ 6381,57,0}, /* core0 sp_EL0 bit12 */
			{ 6382,34,0}, /* core0 sp_EL0 bit13 */
			{ 6383,11,0}, /* core0 sp_EL0 bit14 */
			{ 6383,52,0}, /* core0 sp_EL0 bit15 */
			{ 6043,41,0}, /* core0 sp_EL0 bit16 */
			{ 6044,18,0}, /* core0 sp_EL0 bit17 */
			{ 6044,59,0}, /* core0 sp_EL0 bit18 */
			{ 6045,36,0}, /* core0 sp_EL0 bit19 */
			{ 5715,41,0}, /* core0 sp_EL0 bit20 */
			{ 5716,18,0}, /* core0 sp_EL0 bit21 */
			{ 5716,59,0}, /* core0 sp_EL0 bit22 */
			{ 5717,36,0}, /* core0 sp_EL0 bit23 */
			{ 5725,57,0}, /* core0 sp_EL0 bit24 */
			{ 5726,34,0}, /* core0 sp_EL0 bit25 */
			{ 5727,11,0}, /* core0 sp_EL0 bit26 */
			{ 5727,52,0}, /* core0 sp_EL0 bit27 */
			{ 6415,13,0}, /* core0 sp_EL0 bit28 */
			{ 6415,54,0}, /* core0 sp_EL0 bit29 */
			{ 6416,31,0}, /* core0 sp_EL0 bit30 */
			{ 6417, 8,0}, /* core0 sp_EL0 bit31 */
			{ 5244, 9,0}, /* core0 sp_EL0 bit32 */
			{ 5244,50,0}, /* core0 sp_EL0 bit33 */
			{ 5245,27,0}, /* core0 sp_EL0 bit34 */
			{ 5246, 4,0}, /* core0 sp_EL0 bit35 */
			{ 5236,29,0}, /* core0 sp_EL0 bit36 */
			{ 5237, 6,0}, /* core0 sp_EL0 bit37 */
			{ 5237,47,0}, /* core0 sp_EL0 bit38 */
			{ 5238,24,0}, /* core0 sp_EL0 bit39 */
			{ 5231,21,0}, /* core0 sp_EL0 bit40 */
			{ 5231,62,0}, /* core0 sp_EL0 bit41 */
			{ 5232,39,0}, /* core0 sp_EL0 bit42 */
			{ 5233,16,0}, /* core0 sp_EL0 bit43 */
			{ 5233,57,0}, /* core0 sp_EL0 bit44 */
			{ 5234,34,0}, /* core0 sp_EL0 bit45 */
			{ 5235,11,0}, /* core0 sp_EL0 bit46 */
			{ 5235,52,0}, /* core0 sp_EL0 bit47 */
			{ 5159,37,0}, /* core0 sp_EL0 bit48 */
			{ 5160,14,0}, /* core0 sp_EL0 bit49 */
			{ 5160,55,0}, /* core0 sp_EL0 bit50 */
			{ 5161,32,0}, /* core0 sp_EL0 bit51 */
			{ 5249,17,0}, /* core0 sp_EL0 bit52 */
			{ 5249,58,0}, /* core0 sp_EL0 bit53 */
			{ 5250,35,0}, /* core0 sp_EL0 bit54 */
			{ 5251,12,0}, /* core0 sp_EL0 bit55 */
			{ 5274,57,0}, /* core0 sp_EL0 bit56 */
			{ 5275,34,0}, /* core0 sp_EL0 bit57 */
			{ 5276,11,0}, /* core0 sp_EL0 bit58 */
			{ 5276,52,0}, /* core0 sp_EL0 bit59 */
			{ 5285, 9,0}, /* core0 sp_EL0 bit60 */
			{ 5285,50,0}, /* core0 sp_EL0 bit61 */
			{ 5286,27,0}, /* core0 sp_EL0 bit62 */
			{ 5287, 4,0}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{10025,42,0}, /* core0 sp_EL1 bit0 */
			{10026,12,0}, /* core0 sp_EL1 bit1 */
			{10026,46,0}, /* core0 sp_EL1 bit2 */
			{10027,16,0}, /* core0 sp_EL1 bit3 */
			{ 2974, 5,0}, /* core0 sp_EL1 bit4 */
			{ 2975, 3,0}, /* core0 sp_EL1 bit5 */
			{ 2976, 1,0}, /* core0 sp_EL1 bit6 */
			{ 2976,63,0}, /* core0 sp_EL1 bit7 */
			{ 2020,53,0}, /* core0 sp_EL1 bit8 */
			{ 2021,51,0}, /* core0 sp_EL1 bit9 */
			{ 2022,49,0}, /* core0 sp_EL1 bit10 */
			{ 2023,47,0}, /* core0 sp_EL1 bit11 */
			{ 5672, 5,0}, /* core0 sp_EL1 bit12 */
			{ 5672,46,0}, /* core0 sp_EL1 bit13 */
			{ 5673,23,0}, /* core0 sp_EL1 bit14 */
			{ 5674, 0,0}, /* core0 sp_EL1 bit15 */
			{ 5779,45,0}, /* core0 sp_EL1 bit16 */
			{ 5780,22,0}, /* core0 sp_EL1 bit17 */
			{ 5780,63,0}, /* core0 sp_EL1 bit18 */
			{ 5781,40,0}, /* core0 sp_EL1 bit19 */
			{ 5761,49,0}, /* core0 sp_EL1 bit20 */
			{ 5762,26,0}, /* core0 sp_EL1 bit21 */
			{ 5763, 3,0}, /* core0 sp_EL1 bit22 */
			{ 5763,44,0}, /* core0 sp_EL1 bit23 */
			{ 5697,45,0}, /* core0 sp_EL1 bit24 */
			{ 5698,22,0}, /* core0 sp_EL1 bit25 */
			{ 5698,63,0}, /* core0 sp_EL1 bit26 */
			{ 5699,40,0}, /* core0 sp_EL1 bit27 */
			{ 5674,41,0}, /* core0 sp_EL1 bit28 */
			{ 5675,18,0}, /* core0 sp_EL1 bit29 */
			{ 5675,59,0}, /* core0 sp_EL1 bit30 */
			{ 5676,36,0}, /* core0 sp_EL1 bit31 */
			{ 5518,21,0}, /* core0 sp_EL1 bit32 */
			{ 5518,62,0}, /* core0 sp_EL1 bit33 */
			{ 5519,39,0}, /* core0 sp_EL1 bit34 */
			{ 5520,16,0}, /* core0 sp_EL1 bit35 */
			{ 5551,41,0}, /* core0 sp_EL1 bit36 */
			{ 5552,18,0}, /* core0 sp_EL1 bit37 */
			{ 5552,59,0}, /* core0 sp_EL1 bit38 */
			{ 5553,36,0}, /* core0 sp_EL1 bit39 */
			{ 5549, 5,0}, /* core0 sp_EL1 bit40 */
			{ 5549,46,0}, /* core0 sp_EL1 bit41 */
			{ 5550,23,0}, /* core0 sp_EL1 bit42 */
			{ 5551, 0,0}, /* core0 sp_EL1 bit43 */
			{ 5561,57,0}, /* core0 sp_EL1 bit44 */
			{ 5562,34,0}, /* core0 sp_EL1 bit45 */
			{ 5563,11,0}, /* core0 sp_EL1 bit46 */
			{ 5563,52,0}, /* core0 sp_EL1 bit47 */
			{ 5554,13,0}, /* core0 sp_EL1 bit48 */
			{ 5554,54,0}, /* core0 sp_EL1 bit49 */
			{ 5555,31,0}, /* core0 sp_EL1 bit50 */
			{ 5556, 8,0}, /* core0 sp_EL1 bit51 */
			{ 5559,21,0}, /* core0 sp_EL1 bit52 */
			{ 5559,62,0}, /* core0 sp_EL1 bit53 */
			{ 5560,39,0}, /* core0 sp_EL1 bit54 */
			{ 5561,16,0}, /* core0 sp_EL1 bit55 */
			{ 5520,57,0}, /* core0 sp_EL1 bit56 */
			{ 5521,34,0}, /* core0 sp_EL1 bit57 */
			{ 5522,11,0}, /* core0 sp_EL1 bit58 */
			{ 5522,52,0}, /* core0 sp_EL1 bit59 */
			{ 5556,49,0}, /* core0 sp_EL1 bit60 */
			{ 5557,26,0}, /* core0 sp_EL1 bit61 */
			{ 5558, 3,0}, /* core0 sp_EL1 bit62 */
			{ 5558,44,0}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{10012,58,0}, /* core0 sp_EL2 bit0 */
			{10013,28,0}, /* core0 sp_EL2 bit1 */
			{10013,62,0}, /* core0 sp_EL2 bit2 */
			{10014,32,0}, /* core0 sp_EL2 bit3 */
			{ 2939,13,0}, /* core0 sp_EL2 bit4 */
			{ 2940,11,0}, /* core0 sp_EL2 bit5 */
			{ 2941, 9,0}, /* core0 sp_EL2 bit6 */
			{ 2942, 7,0}, /* core0 sp_EL2 bit7 */
			{10015, 2,0}, /* core0 sp_EL2 bit8 */
			{10015,36,0}, /* core0 sp_EL2 bit9 */
			{10016, 6,0}, /* core0 sp_EL2 bit10 */
			{10016,40,0}, /* core0 sp_EL2 bit11 */
			{ 6430,37,0}, /* core0 sp_EL2 bit12 */
			{ 6431,14,0}, /* core0 sp_EL2 bit13 */
			{ 6431,55,0}, /* core0 sp_EL2 bit14 */
			{ 6432,32,0}, /* core0 sp_EL2 bit15 */
			{ 5784,53,0}, /* core0 sp_EL2 bit16 */
			{ 5785,30,0}, /* core0 sp_EL2 bit17 */
			{ 5786, 7,0}, /* core0 sp_EL2 bit18 */
			{ 5786,48,0}, /* core0 sp_EL2 bit19 */
			{ 5707,61,0}, /* core0 sp_EL2 bit20 */
			{ 5708,38,0}, /* core0 sp_EL2 bit21 */
			{ 5709,15,0}, /* core0 sp_EL2 bit22 */
			{ 5709,56,0}, /* core0 sp_EL2 bit23 */
			{ 5733,37,0}, /* core0 sp_EL2 bit24 */
			{ 5734,14,0}, /* core0 sp_EL2 bit25 */
			{ 5734,55,0}, /* core0 sp_EL2 bit26 */
			{ 5735,32,0}, /* core0 sp_EL2 bit27 */
			{ 2943, 5,0}, /* core0 sp_EL2 bit28 */
			{ 2944, 3,0}, /* core0 sp_EL2 bit29 */
			{ 2945, 1,0}, /* core0 sp_EL2 bit30 */
			{ 2945,63,0}, /* core0 sp_EL2 bit31 */
			{ 5620,53,0}, /* core0 sp_EL2 bit32 */
			{ 5621,30,0}, /* core0 sp_EL2 bit33 */
			{ 5622, 7,0}, /* core0 sp_EL2 bit34 */
			{ 5622,48,0}, /* core0 sp_EL2 bit35 */
			{ 5608, 1,0}, /* core0 sp_EL2 bit36 */
			{ 5608,42,0}, /* core0 sp_EL2 bit37 */
			{ 5609,19,0}, /* core0 sp_EL2 bit38 */
			{ 5609,60,0}, /* core0 sp_EL2 bit39 */
			{ 5605,29,0}, /* core0 sp_EL2 bit40 */
			{ 5606, 6,0}, /* core0 sp_EL2 bit41 */
			{ 5606,47,0}, /* core0 sp_EL2 bit42 */
			{ 5607,24,0}, /* core0 sp_EL2 bit43 */
			{ 5597,49,0}, /* core0 sp_EL2 bit44 */
			{ 5598,26,0}, /* core0 sp_EL2 bit45 */
			{ 5599, 3,0}, /* core0 sp_EL2 bit46 */
			{ 5599,44,0}, /* core0 sp_EL2 bit47 */
			{ 5600,21,0}, /* core0 sp_EL2 bit48 */
			{ 5600,62,0}, /* core0 sp_EL2 bit49 */
			{ 5601,39,0}, /* core0 sp_EL2 bit50 */
			{ 5602,16,0}, /* core0 sp_EL2 bit51 */
			{ 5610,37,0}, /* core0 sp_EL2 bit52 */
			{ 5611,14,0}, /* core0 sp_EL2 bit53 */
			{ 5611,55,0}, /* core0 sp_EL2 bit54 */
			{ 5612,32,0}, /* core0 sp_EL2 bit55 */
			{ 5615,45,0}, /* core0 sp_EL2 bit56 */
			{ 5616,22,0}, /* core0 sp_EL2 bit57 */
			{ 5616,63,0}, /* core0 sp_EL2 bit58 */
			{ 5617,40,0}, /* core0 sp_EL2 bit59 */
			{ 5618,17,0}, /* core0 sp_EL2 bit60 */
			{ 5618,58,0}, /* core0 sp_EL2 bit61 */
			{ 5619,35,0}, /* core0 sp_EL2 bit62 */
			{ 5620,12,0}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 7816,57,1}, /* core0 sp_EL3 bit0 */
			{ 7817,34,1}, /* core0 sp_EL3 bit1 */
			{ 7818,11,1}, /* core0 sp_EL3 bit2 */
			{ 7818,52,1}, /* core0 sp_EL3 bit3 */
			{ 5625,61,0}, /* core0 sp_EL3 bit4 */
			{ 5626,38,0}, /* core0 sp_EL3 bit5 */
			{ 5627,15,0}, /* core0 sp_EL3 bit6 */
			{ 5627,56,0}, /* core0 sp_EL3 bit7 */
			{ 7811,49,1}, /* core0 sp_EL3 bit8 */
			{ 7812,26,1}, /* core0 sp_EL3 bit9 */
			{ 7813, 3,1}, /* core0 sp_EL3 bit10 */
			{ 7813,44,1}, /* core0 sp_EL3 bit11 */
			{ 5628,33,0}, /* core0 sp_EL3 bit12 */
			{ 5629,10,0}, /* core0 sp_EL3 bit13 */
			{ 5629,51,0}, /* core0 sp_EL3 bit14 */
			{ 5630,28,0}, /* core0 sp_EL3 bit15 */
			{ 5787,25,0}, /* core0 sp_EL3 bit16 */
			{ 5788, 2,0}, /* core0 sp_EL3 bit17 */
			{ 5788,43,0}, /* core0 sp_EL3 bit18 */
			{ 5789,20,0}, /* core0 sp_EL3 bit19 */
			{ 5710,33,0}, /* core0 sp_EL3 bit20 */
			{ 5711,10,0}, /* core0 sp_EL3 bit21 */
			{ 5711,51,0}, /* core0 sp_EL3 bit22 */
			{ 5712,28,0}, /* core0 sp_EL3 bit23 */
			{ 5731, 1,0}, /* core0 sp_EL3 bit24 */
			{ 5731,42,0}, /* core0 sp_EL3 bit25 */
			{ 5732,19,0}, /* core0 sp_EL3 bit26 */
			{ 5732,60,0}, /* core0 sp_EL3 bit27 */
			{ 6455,36,0}, /* core0 sp_EL3 bit28 */
			{ 6456,13,0}, /* core0 sp_EL3 bit29 */
			{ 6456,54,0}, /* core0 sp_EL3 bit30 */
			{ 6457,31,0}, /* core0 sp_EL3 bit31 */
			{ 5213,25,0}, /* core0 sp_EL3 bit32 */
			{ 5214, 2,0}, /* core0 sp_EL3 bit33 */
			{ 5214,43,0}, /* core0 sp_EL3 bit34 */
			{ 5215,20,0}, /* core0 sp_EL3 bit35 */
			{ 4998, 9,0}, /* core0 sp_EL3 bit36 */
			{ 4998,50,0}, /* core0 sp_EL3 bit37 */
			{ 4999,27,0}, /* core0 sp_EL3 bit38 */
			{ 5000, 4,0}, /* core0 sp_EL3 bit39 */
			{ 5062,13,0}, /* core0 sp_EL3 bit40 */
			{ 5062,54,0}, /* core0 sp_EL3 bit41 */
			{ 5063,31,0}, /* core0 sp_EL3 bit42 */
			{ 5064, 8,0}, /* core0 sp_EL3 bit43 */
			{ 5059,41,0}, /* core0 sp_EL3 bit44 */
			{ 5060,18,0}, /* core0 sp_EL3 bit45 */
			{ 5060,59,0}, /* core0 sp_EL3 bit46 */
			{ 5061,36,0}, /* core0 sp_EL3 bit47 */
			{ 5057, 5,0}, /* core0 sp_EL3 bit48 */
			{ 5057,46,0}, /* core0 sp_EL3 bit49 */
			{ 5058,23,0}, /* core0 sp_EL3 bit50 */
			{ 5059, 0,0}, /* core0 sp_EL3 bit51 */
			{ 5256,61,0}, /* core0 sp_EL3 bit52 */
			{ 5257,38,0}, /* core0 sp_EL3 bit53 */
			{ 5258,15,0}, /* core0 sp_EL3 bit54 */
			{ 5258,56,0}, /* core0 sp_EL3 bit55 */
			{ 5259,33,0}, /* core0 sp_EL3 bit56 */
			{ 5260,10,0}, /* core0 sp_EL3 bit57 */
			{ 5260,51,0}, /* core0 sp_EL3 bit58 */
			{ 5261,28,0}, /* core0 sp_EL3 bit59 */
			{ 5262, 5,0}, /* core0 sp_EL3 bit60 */
			{ 5262,46,0}, /* core0 sp_EL3 bit61 */
			{ 5263,23,0}, /* core0 sp_EL3 bit62 */
			{ 5264, 0,0}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{ 7814,21,1}, /* core0 elr_EL1 bit0 */
			{ 7814,62,1}, /* core0 elr_EL1 bit1 */
			{ 7815,39,1}, /* core0 elr_EL1 bit2 */
			{ 7816,16,1}, /* core0 elr_EL1 bit3 */
			{ 6379,21,0}, /* core0 elr_EL1 bit4 */
			{ 6379,62,0}, /* core0 elr_EL1 bit5 */
			{ 6380,39,0}, /* core0 elr_EL1 bit6 */
			{ 6381,16,0}, /* core0 elr_EL1 bit7 */
			{ 6030,53,0}, /* core0 elr_EL1 bit8 */
			{ 6031,30,0}, /* core0 elr_EL1 bit9 */
			{ 6032, 7,0}, /* core0 elr_EL1 bit10 */
			{ 6032,48,0}, /* core0 elr_EL1 bit11 */
			{ 6384,29,0}, /* core0 elr_EL1 bit12 */
			{ 6385, 6,0}, /* core0 elr_EL1 bit13 */
			{ 6385,47,0}, /* core0 elr_EL1 bit14 */
			{ 6386,24,0}, /* core0 elr_EL1 bit15 */
			{ 7804, 5,1}, /* core0 elr_EL1 bit16 */
			{ 7804,46,1}, /* core0 elr_EL1 bit17 */
			{ 7805,23,1}, /* core0 elr_EL1 bit18 */
			{ 7806, 0,1}, /* core0 elr_EL1 bit19 */
			{ 5713, 5,0}, /* core0 elr_EL1 bit20 */
			{ 5713,46,0}, /* core0 elr_EL1 bit21 */
			{ 5714,23,0}, /* core0 elr_EL1 bit22 */
			{ 5715, 0,0}, /* core0 elr_EL1 bit23 */
			{ 5728,29,0}, /* core0 elr_EL1 bit24 */
			{ 5729, 6,0}, /* core0 elr_EL1 bit25 */
			{ 5729,47,0}, /* core0 elr_EL1 bit26 */
			{ 5730,24,0}, /* core0 elr_EL1 bit27 */
			{ 6412,41,0}, /* core0 elr_EL1 bit28 */
			{ 6413,18,0}, /* core0 elr_EL1 bit29 */
			{ 6413,59,0}, /* core0 elr_EL1 bit30 */
			{ 6414,36,0}, /* core0 elr_EL1 bit31 */
			{ 5215,61,0}, /* core0 elr_EL1 bit32 */
			{ 5216,38,0}, /* core0 elr_EL1 bit33 */
			{ 5217,15,0}, /* core0 elr_EL1 bit34 */
			{ 5217,56,0}, /* core0 elr_EL1 bit35 */
			{ 5164,45,0}, /* core0 elr_EL1 bit36 */
			{ 5165,22,0}, /* core0 elr_EL1 bit37 */
			{ 5165,63,0}, /* core0 elr_EL1 bit38 */
			{ 5166,40,0}, /* core0 elr_EL1 bit39 */
			{ 5167,17,0}, /* core0 elr_EL1 bit40 */
			{ 5167,58,0}, /* core0 elr_EL1 bit41 */
			{ 5168,35,0}, /* core0 elr_EL1 bit42 */
			{ 5169,12,0}, /* core0 elr_EL1 bit43 */
			{ 5169,53,0}, /* core0 elr_EL1 bit44 */
			{ 5170,30,0}, /* core0 elr_EL1 bit45 */
			{ 5171, 7,0}, /* core0 elr_EL1 bit46 */
			{ 5171,48,0}, /* core0 elr_EL1 bit47 */
			{ 5172,25,0}, /* core0 elr_EL1 bit48 */
			{ 5173, 2,0}, /* core0 elr_EL1 bit49 */
			{ 5173,43,0}, /* core0 elr_EL1 bit50 */
			{ 5174,20,0}, /* core0 elr_EL1 bit51 */
			{ 5254,25,0}, /* core0 elr_EL1 bit52 */
			{ 5255, 2,0}, /* core0 elr_EL1 bit53 */
			{ 5255,43,0}, /* core0 elr_EL1 bit54 */
			{ 5256,20,0}, /* core0 elr_EL1 bit55 */
			{ 5269,49,0}, /* core0 elr_EL1 bit56 */
			{ 5270,26,0}, /* core0 elr_EL1 bit57 */
			{ 5271, 3,0}, /* core0 elr_EL1 bit58 */
			{ 5271,44,0}, /* core0 elr_EL1 bit59 */
			{ 5264,41,0}, /* core0 elr_EL1 bit60 */
			{ 5265,18,0}, /* core0 elr_EL1 bit61 */
			{ 5265,59,0}, /* core0 elr_EL1 bit62 */
			{ 5266,36,0}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 6015,29,0}, /* core0 elr_EL2 bit0 */
			{ 6016, 6,0}, /* core0 elr_EL2 bit1 */
			{ 6016,47,0}, /* core0 elr_EL2 bit2 */
			{ 6017,24,0}, /* core0 elr_EL2 bit3 */
			{ 6371,41,0}, /* core0 elr_EL2 bit4 */
			{ 6372,18,0}, /* core0 elr_EL2 bit5 */
			{ 6372,59,0}, /* core0 elr_EL2 bit6 */
			{ 6373,36,0}, /* core0 elr_EL2 bit7 */
			{ 6094,57,0}, /* core0 elr_EL2 bit8 */
			{ 6095,34,0}, /* core0 elr_EL2 bit9 */
			{ 6096,11,0}, /* core0 elr_EL2 bit10 */
			{ 6096,52,0}, /* core0 elr_EL2 bit11 */
			{ 6374,13,0}, /* core0 elr_EL2 bit12 */
			{ 6374,54,0}, /* core0 elr_EL2 bit13 */
			{ 6375,31,0}, /* core0 elr_EL2 bit14 */
			{ 6376, 8,0}, /* core0 elr_EL2 bit15 */
			{ 6048,49,0}, /* core0 elr_EL2 bit16 */
			{ 6049,26,0}, /* core0 elr_EL2 bit17 */
			{ 6050, 3,0}, /* core0 elr_EL2 bit18 */
			{ 6050,44,0}, /* core0 elr_EL2 bit19 */
			{ 6056,29,0}, /* core0 elr_EL2 bit20 */
			{ 6057, 6,0}, /* core0 elr_EL2 bit21 */
			{ 6057,47,0}, /* core0 elr_EL2 bit22 */
			{ 6058,24,0}, /* core0 elr_EL2 bit23 */
			{ 7793,53,1}, /* core0 elr_EL2 bit24 */
			{ 7794,30,1}, /* core0 elr_EL2 bit25 */
			{ 7795, 7,1}, /* core0 elr_EL2 bit26 */
			{ 7795,48,1}, /* core0 elr_EL2 bit27 */
			{ 6407,33,0}, /* core0 elr_EL2 bit28 */
			{ 6408,10,0}, /* core0 elr_EL2 bit29 */
			{ 6408,51,0}, /* core0 elr_EL2 bit30 */
			{ 6409,28,0}, /* core0 elr_EL2 bit31 */
			{ 5246,45,0}, /* core0 elr_EL2 bit32 */
			{ 5247,22,0}, /* core0 elr_EL2 bit33 */
			{ 5247,63,0}, /* core0 elr_EL2 bit34 */
			{ 5248,40,0}, /* core0 elr_EL2 bit35 */
			{ 5241,37,0}, /* core0 elr_EL2 bit36 */
			{ 5242,14,0}, /* core0 elr_EL2 bit37 */
			{ 5242,55,0}, /* core0 elr_EL2 bit38 */
			{ 5243,32,0}, /* core0 elr_EL2 bit39 */
			{ 5221, 5,0}, /* core0 elr_EL2 bit40 */
			{ 5221,46,0}, /* core0 elr_EL2 bit41 */
			{ 5222,23,0}, /* core0 elr_EL2 bit42 */
			{ 5223, 0,0}, /* core0 elr_EL2 bit43 */
			{ 5239, 1,0}, /* core0 elr_EL2 bit44 */
			{ 5239,42,0}, /* core0 elr_EL2 bit45 */
			{ 5240,19,0}, /* core0 elr_EL2 bit46 */
			{ 5240,60,0}, /* core0 elr_EL2 bit47 */
			{ 5223,41,0}, /* core0 elr_EL2 bit48 */
			{ 5224,18,0}, /* core0 elr_EL2 bit49 */
			{ 5224,59,0}, /* core0 elr_EL2 bit50 */
			{ 5225,36,0}, /* core0 elr_EL2 bit51 */
			{ 5287,45,0}, /* core0 elr_EL2 bit52 */
			{ 5288,22,0}, /* core0 elr_EL2 bit53 */
			{ 5288,63,0}, /* core0 elr_EL2 bit54 */
			{ 5289,40,0}, /* core0 elr_EL2 bit55 */
			{ 5282,37,0}, /* core0 elr_EL2 bit56 */
			{ 5283,14,0}, /* core0 elr_EL2 bit57 */
			{ 5283,55,0}, /* core0 elr_EL2 bit58 */
			{ 5284,32,0}, /* core0 elr_EL2 bit59 */
			{ 5579,53,0}, /* core0 elr_EL2 bit60 */
			{ 5580,30,0}, /* core0 elr_EL2 bit61 */
			{ 5581, 7,0}, /* core0 elr_EL2 bit62 */
			{ 5581,48,0}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{10010,50,0}, /* core0 elr_EL3 bit0 */
			{10011,20,0}, /* core0 elr_EL3 bit1 */
			{10011,54,0}, /* core0 elr_EL3 bit2 */
			{10012,24,0}, /* core0 elr_EL3 bit3 */
			{ 2935,21,0}, /* core0 elr_EL3 bit4 */
			{ 2936,19,0}, /* core0 elr_EL3 bit5 */
			{ 2937,17,0}, /* core0 elr_EL3 bit6 */
			{ 2938,15,0}, /* core0 elr_EL3 bit7 */
			{ 7809,13,1}, /* core0 elr_EL3 bit8 */
			{ 7809,54,1}, /* core0 elr_EL3 bit9 */
			{ 7810,31,1}, /* core0 elr_EL3 bit10 */
			{ 7811, 8,1}, /* core0 elr_EL3 bit11 */
			{ 2931,29,0}, /* core0 elr_EL3 bit12 */
			{ 2932,27,0}, /* core0 elr_EL3 bit13 */
			{ 2933,25,0}, /* core0 elr_EL3 bit14 */
			{ 2934,23,0}, /* core0 elr_EL3 bit15 */
			{ 5782,17,0}, /* core0 elr_EL3 bit16 */
			{ 5782,58,0}, /* core0 elr_EL3 bit17 */
			{ 5783,35,0}, /* core0 elr_EL3 bit18 */
			{ 5784,12,0}, /* core0 elr_EL3 bit19 */
			{ 5705,25,0}, /* core0 elr_EL3 bit20 */
			{ 5706, 2,0}, /* core0 elr_EL3 bit21 */
			{ 5706,43,0}, /* core0 elr_EL3 bit22 */
			{ 5707,20,0}, /* core0 elr_EL3 bit23 */
			{ 5736, 9,0}, /* core0 elr_EL3 bit24 */
			{ 5736,50,0}, /* core0 elr_EL3 bit25 */
			{ 5737,27,0}, /* core0 elr_EL3 bit26 */
			{ 5738, 4,0}, /* core0 elr_EL3 bit27 */
			{ 5649, 1,0}, /* core0 elr_EL3 bit28 */
			{ 5649,42,0}, /* core0 elr_EL3 bit29 */
			{ 5650,19,0}, /* core0 elr_EL3 bit30 */
			{ 5650,60,0}, /* core0 elr_EL3 bit31 */
			{ 5508, 5,0}, /* core0 elr_EL3 bit32 */
			{ 5508,46,0}, /* core0 elr_EL3 bit33 */
			{ 5509,23,0}, /* core0 elr_EL3 bit34 */
			{ 5510, 0,0}, /* core0 elr_EL3 bit35 */
			{ 5536,17,0}, /* core0 elr_EL3 bit36 */
			{ 5536,58,0}, /* core0 elr_EL3 bit37 */
			{ 5537,35,0}, /* core0 elr_EL3 bit38 */
			{ 5538,12,0}, /* core0 elr_EL3 bit39 */
			{ 5592,41,0}, /* core0 elr_EL3 bit40 */
			{ 5593,18,0}, /* core0 elr_EL3 bit41 */
			{ 5593,59,0}, /* core0 elr_EL3 bit42 */
			{ 5594,36,0}, /* core0 elr_EL3 bit43 */
			{ 5595,13,0}, /* core0 elr_EL3 bit44 */
			{ 5595,54,0}, /* core0 elr_EL3 bit45 */
			{ 5596,31,0}, /* core0 elr_EL3 bit46 */
			{ 5597, 8,0}, /* core0 elr_EL3 bit47 */
			{ 5587,33,0}, /* core0 elr_EL3 bit48 */
			{ 5588,10,0}, /* core0 elr_EL3 bit49 */
			{ 5588,51,0}, /* core0 elr_EL3 bit50 */
			{ 5589,28,0}, /* core0 elr_EL3 bit51 */
			{ 5538,53,0}, /* core0 elr_EL3 bit52 */
			{ 5539,30,0}, /* core0 elr_EL3 bit53 */
			{ 5540, 7,0}, /* core0 elr_EL3 bit54 */
			{ 5540,48,0}, /* core0 elr_EL3 bit55 */
			{ 5613, 9,0}, /* core0 elr_EL3 bit56 */
			{ 5613,50,0}, /* core0 elr_EL3 bit57 */
			{ 5614,27,0}, /* core0 elr_EL3 bit58 */
			{ 5615, 4,0}, /* core0 elr_EL3 bit59 */
			{ 5510,41,0}, /* core0 elr_EL3 bit60 */
			{ 5511,18,0}, /* core0 elr_EL3 bit61 */
			{ 5511,59,0}, /* core0 elr_EL3 bit62 */
			{ 5512,36,0}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 7534,24,1}, /* core0 raw_pc bit0 */
			{ 9652,12,0}, /* core0 raw_pc bit1 */
			{ 9652,46,0}, /* core0 raw_pc bit2 */
			{ 4204,25,0}, /* core0 raw_pc bit3 */
			{ 4205,23,0}, /* core0 raw_pc bit4 */
			{ 4206,21,0}, /* core0 raw_pc bit5 */
			{ 4207,19,0}, /* core0 raw_pc bit6 */
			{ 1962,45,0}, /* core0 raw_pc bit7 */
			{ 1963,43,0}, /* core0 raw_pc bit8 */
			{ 1964,41,0}, /* core0 raw_pc bit9 */
			{ 1965,39,0}, /* core0 raw_pc bit10 */
			{ 1970,29,0}, /* core0 raw_pc bit11 */
			{ 1971,27,0}, /* core0 raw_pc bit12 */
			{ 1972,25,0}, /* core0 raw_pc bit13 */
			{ 1973,23,0}, /* core0 raw_pc bit14 */
			{ 1982, 5,0}, /* core0 raw_pc bit15 */
			{ 1983, 3,0}, /* core0 raw_pc bit16 */
			{ 1984, 1,0}, /* core0 raw_pc bit17 */
			{ 1984,63,0}, /* core0 raw_pc bit18 */
			{ 1966,37,0}, /* core0 raw_pc bit19 */
			{ 1967,35,0}, /* core0 raw_pc bit20 */
			{ 1968,33,0}, /* core0 raw_pc bit21 */
			{ 1969,31,0}, /* core0 raw_pc bit22 */
			{ 1989,53,0}, /* core0 raw_pc bit23 */
			{ 1990,51,0}, /* core0 raw_pc bit24 */
			{ 1991,49,0}, /* core0 raw_pc bit25 */
			{ 1992,47,0}, /* core0 raw_pc bit26 */
			{ 1939,29,0}, /* core0 raw_pc bit27 */
			{ 1940,27,0}, /* core0 raw_pc bit28 */
			{ 1941,25,0}, /* core0 raw_pc bit29 */
			{ 1942,23,0}, /* core0 raw_pc bit30 */
			{  218,60,0}, /* core0 raw_pc bit31 */
			{ 1943,21,0}, /* core0 raw_pc bit32 */
			{ 1944,19,0}, /* core0 raw_pc bit33 */
			{ 1945,17,0}, /* core0 raw_pc bit34 */
			{ 1946,15,0}, /* core0 raw_pc bit35 */
			{ 1931,45,0}, /* core0 raw_pc bit36 */
			{ 1932,43,0}, /* core0 raw_pc bit37 */
			{ 1933,41,0}, /* core0 raw_pc bit38 */
			{ 1934,39,0}, /* core0 raw_pc bit39 */
			{ 1935,37,0}, /* core0 raw_pc bit40 */
			{ 1936,35,0}, /* core0 raw_pc bit41 */
			{ 1937,33,0}, /* core0 raw_pc bit42 */
			{ 1938,31,0}, /* core0 raw_pc bit43 */
			{ 1927,53,0}, /* core0 raw_pc bit44 */
			{ 1928,51,0}, /* core0 raw_pc bit45 */
			{ 1929,49,0}, /* core0 raw_pc bit46 */
			{ 1930,47,0}, /* core0 raw_pc bit47 */
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
			{ 4531,53,0}, /* core0 pc_iss bit0 */
			{ 4528,59,0}, /* core0 pc_iss bit1 */
			{ 4453,23,0}, /* core0 pc_iss bit2 */
			{ 4527,61,0}, /* core0 pc_iss bit3 */
			{ 4454,21,0}, /* core0 pc_iss bit4 */
			{ 4525, 3,0}, /* core0 pc_iss bit5 */
			{ 4529,57,0}, /* core0 pc_iss bit6 */
			{ 4526,63,0}, /* core0 pc_iss bit7 */
			{ 4457,15,0}, /* core0 pc_iss bit8 */
			{ 4533,49,0}, /* core0 pc_iss bit9 */
			{ 4532,51,0}, /* core0 pc_iss bit10 */
			{ 4536,43,0}, /* core0 pc_iss bit11 */
			{ 4458,13,0}, /* core0 pc_iss bit12 */
			{ 4534,47,0}, /* core0 pc_iss bit13 */
			{ 4535,45,0}, /* core0 pc_iss bit14 */
			{ 4537,41,0}, /* core0 pc_iss bit15 */
			{ 4541,33,0}, /* core0 pc_iss bit16 */
			{ 4539,37,0}, /* core0 pc_iss bit17 */
			{ 4538,39,0}, /* core0 pc_iss bit18 */
			{ 4543,29,0}, /* core0 pc_iss bit19 */
			{ 4540,35,0}, /* core0 pc_iss bit20 */
			{ 4545,25,0}, /* core0 pc_iss bit21 */
			{ 4542,31,0}, /* core0 pc_iss bit22 */
			{ 9565, 4,0}, /* core0 pc_iss bit23 */
			{ 4460, 9,0}, /* core0 pc_iss bit24 */
			{ 4544,27,0}, /* core0 pc_iss bit25 */
			{ 4546,23,0}, /* core0 pc_iss bit26 */
			{ 4461, 7,0}, /* core0 pc_iss bit27 */
			{ 4459,11,0}, /* core0 pc_iss bit28 */
			{ 4462, 5,0}, /* core0 pc_iss bit29 */
			{ 9566,42,0}, /* core0 pc_iss bit30 */
			{ 9567,12,0}, /* core0 pc_iss bit31 */
			{ 9655,58,0}, /* core0 pc_iss bit32 */
			{ 9656,28,0}, /* core0 pc_iss bit33 */
			{ 4208,17,0}, /* core0 pc_iss bit34 */
			{ 4209,15,0}, /* core0 pc_iss bit35 */
			{ 4210,13,0}, /* core0 pc_iss bit36 */
			{ 4211,11,0}, /* core0 pc_iss bit37 */
			{ 4212, 9,0}, /* core0 pc_iss bit38 */
			{ 4213, 7,0}, /* core0 pc_iss bit39 */
			{ 4214, 5,0}, /* core0 pc_iss bit40 */
			{ 4215, 3,0}, /* core0 pc_iss bit41 */
			{ 4216, 1,0}, /* core0 pc_iss bit42 */
			{ 4216,63,0}, /* core0 pc_iss bit43 */
			{ 4217,61,0}, /* core0 pc_iss bit44 */
			{ 4218,59,0}, /* core0 pc_iss bit45 */
			{ 9658,36,0}, /* core0 pc_iss bit46 */
			{ 9658, 2,0}, /* core0 pc_iss bit47 */
			{ 9659,40,0}, /* core0 pc_iss bit48 */
			{ 9659, 6,0}, /* core0 pc_iss bit49 */
			{ 9664,26,0}, /* core0 pc_iss bit50 */
			{ 9663,56,0}, /* core0 pc_iss bit51 */
			{ 9566, 8,0}, /* core0 pc_iss bit52 */
			{ 9565,38,0}, /* core0 pc_iss bit53 */
			{ 4222,51,0}, /* core0 pc_iss bit54 */
			{ 4221,53,0}, /* core0 pc_iss bit55 */
			{ 4220,55,0}, /* core0 pc_iss bit56 */
			{ 4219,57,0}, /* core0 pc_iss bit57 */
			{ 9662,18,0}, /* core0 pc_iss bit58 */
			{ 9661,48,0}, /* core0 pc_iss bit59 */
			{ 9661,14,0}, /* core0 pc_iss bit60 */
			{ 9660,44,0}, /* core0 pc_iss bit61 */
			{ 9663,22,0}, /* core0 pc_iss bit62 */
			{ 9662,52,0}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 7533,47,1}, /* core0 full_pc_wr bit0 */
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
			{ 4472,47,0}, /* core0 full_pc_ex1 bit0 */
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
			{ 4469,53,0}, /* core0 full_pc_ex2 bit0 */
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
			{ 9802,36,0}, /* core1 pc bit0 */
			{ 9803, 6,0}, /* core1 pc bit1 */
			{ 9803,40,0}, /* core1 pc bit2 */
			{ 9804,10,0}, /* core1 pc bit3 */
			{ 9783,28,0}, /* core1 pc bit4 */
			{ 9783,62,0}, /* core1 pc bit5 */
			{ 9784,32,0}, /* core1 pc bit6 */
			{ 9785, 2,0}, /* core1 pc bit7 */
			{ 9804,44,0}, /* core1 pc bit8 */
			{ 9805,14,0}, /* core1 pc bit9 */
			{ 9805,48,0}, /* core1 pc bit10 */
			{ 9806,18,0}, /* core1 pc bit11 */
			{ 9787,44,0}, /* core1 pc bit12 */
			{ 9788,14,0}, /* core1 pc bit13 */
			{ 9788,48,0}, /* core1 pc bit14 */
			{ 9789,18,0}, /* core1 pc bit15 */
			{ 9800,28,0}, /* core1 pc bit16 */
			{ 9800,62,0}, /* core1 pc bit17 */
			{ 9801,32,0}, /* core1 pc bit18 */
			{ 9802, 2,0}, /* core1 pc bit19 */
			{ 2319,15,0}, /* core1 pc bit20 */
			{ 2320,13,0}, /* core1 pc bit21 */
			{ 2321,11,0}, /* core1 pc bit22 */
			{ 2322, 9,0}, /* core1 pc bit23 */
			{ 2315,23,0}, /* core1 pc bit24 */
			{ 2316,21,0}, /* core1 pc bit25 */
			{ 2317,19,0}, /* core1 pc bit26 */
			{ 2318,17,0}, /* core1 pc bit27 */
			{ 2299,55,0}, /* core1 pc bit28 */
			{ 2300,53,0}, /* core1 pc bit29 */
			{ 2301,51,0}, /* core1 pc bit30 */
			{ 2302,49,0}, /* core1 pc bit31 */
			{ 9796,12,0}, /* core1 pc bit32 */
			{ 9796,46,0}, /* core1 pc bit33 */
			{ 9797,16,0}, /* core1 pc bit34 */
			{ 9797,50,0}, /* core1 pc bit35 */
			{   12,40,0}, /* core1 pc bit36 */
			{   13,38,0}, /* core1 pc bit37 */
			{   14,36,0}, /* core1 pc bit38 */
			{   15,34,0}, /* core1 pc bit39 */
			{ 9798,20,0}, /* core1 pc bit40 */
			{ 9798,54,0}, /* core1 pc bit41 */
			{ 9799,24,0}, /* core1 pc bit42 */
			{ 9799,58,0}, /* core1 pc bit43 */
			{   16,32,0}, /* core1 pc bit44 */
			{   17,30,0}, /* core1 pc bit45 */
			{   18,28,0}, /* core1 pc bit46 */
			{   19,26,0}, /* core1 pc bit47 */
			{ 9794, 4,0}, /* core1 pc bit48 */
			{ 9794,38,0}, /* core1 pc bit49 */
			{ 9795, 8,0}, /* core1 pc bit50 */
			{ 9795,42,0}, /* core1 pc bit51 */
			{ 9785,36,0}, /* core1 pc bit52 */
			{ 9786, 6,0}, /* core1 pc bit53 */
			{ 9786,40,0}, /* core1 pc bit54 */
			{ 9787,10,0}, /* core1 pc bit55 */
			{ 2989,39,0}, /* core1 pc bit56 */
			{ 2990,37,0}, /* core1 pc bit57 */
			{ 2991,35,0}, /* core1 pc bit58 */
			{ 2992,33,0}, /* core1 pc bit59 */
			{   20,24,0}, /* core1 pc bit60 */
			{   21,22,0}, /* core1 pc bit61 */
			{   22,20,0}, /* core1 pc bit62 */
			{   23,18,0}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{ 5777,11,0}, /* core1 sp32 bit0 */
			{ 5777,52,0}, /* core1 sp32 bit1 */
			{ 5778,29,0}, /* core1 sp32 bit2 */
			{ 5779, 6,0}, /* core1 sp32 bit3 */
			{ 5633,43,0}, /* core1 sp32 bit4 */
			{ 5634,20,0}, /* core1 sp32 bit5 */
			{ 5634,61,0}, /* core1 sp32 bit6 */
			{ 5635,38,0}, /* core1 sp32 bit7 */
			{ 2016,63,0}, /* core1 sp32 bit8 */
			{ 2017,61,0}, /* core1 sp32 bit9 */
			{ 2018,59,0}, /* core1 sp32 bit10 */
			{ 2019,57,0}, /* core1 sp32 bit11 */
			{ 5656,47,0}, /* core1 sp32 bit12 */
			{ 5657,24,0}, /* core1 sp32 bit13 */
			{ 5658, 1,0}, /* core1 sp32 bit14 */
			{ 5658,42,0}, /* core1 sp32 bit15 */
			{ 5774,39,0}, /* core1 sp32 bit16 */
			{ 5775,16,0}, /* core1 sp32 bit17 */
			{ 5775,57,0}, /* core1 sp32 bit18 */
			{ 5776,34,0}, /* core1 sp32 bit19 */
			{ 5769,31,0}, /* core1 sp32 bit20 */
			{ 5770, 8,0}, /* core1 sp32 bit21 */
			{ 5770,49,0}, /* core1 sp32 bit22 */
			{ 5771,26,0}, /* core1 sp32 bit23 */
			{ 5748,63,0}, /* core1 sp32 bit24 */
			{ 5749,40,0}, /* core1 sp32 bit25 */
			{ 5750,17,0}, /* core1 sp32 bit26 */
			{ 5750,58,0}, /* core1 sp32 bit27 */
			{ 5654,11,0}, /* core1 sp32 bit28 */
			{ 5654,52,0}, /* core1 sp32 bit29 */
			{ 5655,29,0}, /* core1 sp32 bit30 */
			{ 5656, 6,0}, /* core1 sp32 bit31 */
			{ 5203,11,0}, /* core1 sp32 bit32 */
			{ 5203,52,0}, /* core1 sp32 bit33 */
			{ 5204,29,0}, /* core1 sp32 bit34 */
			{ 5205, 6,0}, /* core1 sp32 bit35 */
			{ 5356,59,0}, /* core1 sp32 bit36 */
			{ 5357,36,0}, /* core1 sp32 bit37 */
			{ 5358,13,0}, /* core1 sp32 bit38 */
			{ 5358,54,0}, /* core1 sp32 bit39 */
			{ 5133,22,0}, /* core1 sp32 bit40 */
			{ 5133,63,0}, /* core1 sp32 bit41 */
			{ 5134,40,0}, /* core1 sp32 bit42 */
			{ 5135,17,0}, /* core1 sp32 bit43 */
			{ 5123, 6,0}, /* core1 sp32 bit44 */
			{ 5123,47,0}, /* core1 sp32 bit45 */
			{ 5124,24,0}, /* core1 sp32 bit46 */
			{ 5125, 1,0}, /* core1 sp32 bit47 */
			{ 5125,42,0}, /* core1 sp32 bit48 */
			{ 5126,19,0}, /* core1 sp32 bit49 */
			{ 5126,60,0}, /* core1 sp32 bit50 */
			{ 5127,37,0}, /* core1 sp32 bit51 */
			{ 5387,43,0}, /* core1 sp32 bit52 */
			{ 5388,20,0}, /* core1 sp32 bit53 */
			{ 5388,61,0}, /* core1 sp32 bit54 */
			{ 5389,38,0}, /* core1 sp32 bit55 */
			{ 5390,15,0}, /* core1 sp32 bit56 */
			{ 5390,56,0}, /* core1 sp32 bit57 */
			{ 5391,33,0}, /* core1 sp32 bit58 */
			{ 5392,10,0}, /* core1 sp32 bit59 */
			{ 5392,51,0}, /* core1 sp32 bit60 */
			{ 5393,28,0}, /* core1 sp32 bit61 */
			{ 5394, 5,0}, /* core1 sp32 bit62 */
			{ 5394,46,0}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{ 6107,47,0}, /* core1 fp32 bit0 */
			{ 6108,24,0}, /* core1 fp32 bit1 */
			{ 6109, 1,0}, /* core1 fp32 bit2 */
			{ 6109,42,0}, /* core1 fp32 bit3 */
			{ 6343,31,0}, /* core1 fp32 bit4 */
			{ 6344, 8,0}, /* core1 fp32 bit5 */
			{ 6344,49,0}, /* core1 fp32 bit6 */
			{ 6345,26,0}, /* core1 fp32 bit7 */
			{ 1013,23,1}, /* core1 fp32 bit8 */
			{ 1014,21,1}, /* core1 fp32 bit9 */
			{ 1015,19,1}, /* core1 fp32 bit10 */
			{ 1016,17,1}, /* core1 fp32 bit11 */
			{ 6340,59,0}, /* core1 fp32 bit12 */
			{ 6341,36,0}, /* core1 fp32 bit13 */
			{ 6342,13,0}, /* core1 fp32 bit14 */
			{ 6342,54,0}, /* core1 fp32 bit15 */
			{ 6079,35,0}, /* core1 fp32 bit16 */
			{ 6080,12,0}, /* core1 fp32 bit17 */
			{ 6080,53,0}, /* core1 fp32 bit18 */
			{ 6081,30,0}, /* core1 fp32 bit19 */
			{ 5951,27,0}, /* core1 fp32 bit20 */
			{ 5952, 4,0}, /* core1 fp32 bit21 */
			{ 5952,45,0}, /* core1 fp32 bit22 */
			{ 5953,22,0}, /* core1 fp32 bit23 */
			{ 6182, 3,0}, /* core1 fp32 bit24 */
			{ 6182,44,0}, /* core1 fp32 bit25 */
			{ 6183,21,0}, /* core1 fp32 bit26 */
			{ 6183,62,0}, /* core1 fp32 bit27 */
			{ 5841,15,0}, /* core1 fp32 bit28 */
			{ 5841,56,0}, /* core1 fp32 bit29 */
			{ 5842,33,0}, /* core1 fp32 bit30 */
			{ 5843,10,0}, /* core1 fp32 bit31 */
			{ 5198, 3,0}, /* core1 fp32 bit32 */
			{ 5198,44,0}, /* core1 fp32 bit33 */
			{ 5199,21,0}, /* core1 fp32 bit34 */
			{ 5199,62,0}, /* core1 fp32 bit35 */
			{ 5195,31,0}, /* core1 fp32 bit36 */
			{ 5196, 8,0}, /* core1 fp32 bit37 */
			{ 5196,49,0}, /* core1 fp32 bit38 */
			{ 5197,26,0}, /* core1 fp32 bit39 */
			{ 5135,58,0}, /* core1 fp32 bit40 */
			{ 5136,35,0}, /* core1 fp32 bit41 */
			{ 5137,12,0}, /* core1 fp32 bit42 */
			{ 5137,53,0}, /* core1 fp32 bit43 */
			{ 5141, 2,0}, /* core1 fp32 bit44 */
			{ 5141,43,0}, /* core1 fp32 bit45 */
			{ 5142,20,0}, /* core1 fp32 bit46 */
			{ 5142,61,0}, /* core1 fp32 bit47 */
			{ 5128,14,0}, /* core1 fp32 bit48 */
			{ 5128,55,0}, /* core1 fp32 bit49 */
			{ 5129,32,0}, /* core1 fp32 bit50 */
			{ 5130, 9,0}, /* core1 fp32 bit51 */
			{ 5420,63,0}, /* core1 fp32 bit52 */
			{ 5421,40,0}, /* core1 fp32 bit53 */
			{ 5422,17,0}, /* core1 fp32 bit54 */
			{ 5422,58,0}, /* core1 fp32 bit55 */
			{ 5418,27,0}, /* core1 fp32 bit56 */
			{ 5419, 4,0}, /* core1 fp32 bit57 */
			{ 5419,45,0}, /* core1 fp32 bit58 */
			{ 5420,22,0}, /* core1 fp32 bit59 */
			{ 5200,39,0}, /* core1 fp32 bit60 */
			{ 5201,16,0}, /* core1 fp32 bit61 */
			{ 5201,57,0}, /* core1 fp32 bit62 */
			{ 5202,34,0}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{ 2024,47,0}, /* core1 fp64 bit0 */
			{ 2025,45,0}, /* core1 fp64 bit1 */
			{ 2026,43,0}, /* core1 fp64 bit2 */
			{ 2027,41,0}, /* core1 fp64 bit3 */
			{ 5643,59,0}, /* core1 fp64 bit4 */
			{ 5644,36,0}, /* core1 fp64 bit5 */
			{ 5645,13,0}, /* core1 fp64 bit6 */
			{ 5645,54,0}, /* core1 fp64 bit7 */
			{   28, 8,0}, /* core1 fp64 bit8 */
			{   29, 6,0}, /* core1 fp64 bit9 */
			{   30, 4,0}, /* core1 fp64 bit10 */
			{   31, 2,0}, /* core1 fp64 bit11 */
			{ 5646,31,0}, /* core1 fp64 bit12 */
			{ 5647, 8,0}, /* core1 fp64 bit13 */
			{ 5647,49,0}, /* core1 fp64 bit14 */
			{ 5648,26,0}, /* core1 fp64 bit15 */
			{ 5772, 3,0}, /* core1 fp64 bit16 */
			{ 5772,44,0}, /* core1 fp64 bit17 */
			{ 5773,21,0}, /* core1 fp64 bit18 */
			{ 5773,62,0}, /* core1 fp64 bit19 */
			{ 5756,43,0}, /* core1 fp64 bit20 */
			{ 5757,20,0}, /* core1 fp64 bit21 */
			{ 5757,61,0}, /* core1 fp64 bit22 */
			{ 5758,38,0}, /* core1 fp64 bit23 */
			{ 5692,39,0}, /* core1 fp64 bit24 */
			{ 5693,16,0}, /* core1 fp64 bit25 */
			{ 5693,57,0}, /* core1 fp64 bit26 */
			{ 5694,34,0}, /* core1 fp64 bit27 */
			{ 5746,27,0}, /* core1 fp64 bit28 */
			{ 5747, 4,0}, /* core1 fp64 bit29 */
			{ 5747,45,0}, /* core1 fp64 bit30 */
			{ 5748,22,0}, /* core1 fp64 bit31 */
			{ 5528,39,0}, /* core1 fp64 bit32 */
			{ 5529,16,0}, /* core1 fp64 bit33 */
			{ 5529,57,0}, /* core1 fp64 bit34 */
			{ 5530,34,0}, /* core1 fp64 bit35 */
			{ 5543,63,0}, /* core1 fp64 bit36 */
			{ 5544,40,0}, /* core1 fp64 bit37 */
			{ 5545,17,0}, /* core1 fp64 bit38 */
			{ 5545,58,0}, /* core1 fp64 bit39 */
			{ 5533,47,0}, /* core1 fp64 bit40 */
			{ 5534,24,0}, /* core1 fp64 bit41 */
			{ 5535, 1,0}, /* core1 fp64 bit42 */
			{ 5535,42,0}, /* core1 fp64 bit43 */
			{ 5523,31,0}, /* core1 fp64 bit44 */
			{ 5524, 8,0}, /* core1 fp64 bit45 */
			{ 5524,49,0}, /* core1 fp64 bit46 */
			{ 5525,26,0}, /* core1 fp64 bit47 */
			{ 5590, 7,0}, /* core1 fp64 bit48 */
			{ 5590,48,0}, /* core1 fp64 bit49 */
			{ 5591,25,0}, /* core1 fp64 bit50 */
			{ 5592, 2,0}, /* core1 fp64 bit51 */
			{ 5541,27,0}, /* core1 fp64 bit52 */
			{ 5542, 4,0}, /* core1 fp64 bit53 */
			{ 5542,45,0}, /* core1 fp64 bit54 */
			{ 5543,22,0}, /* core1 fp64 bit55 */
			{ 5531,11,0}, /* core1 fp64 bit56 */
			{ 5531,52,0}, /* core1 fp64 bit57 */
			{ 5532,29,0}, /* core1 fp64 bit58 */
			{ 5533, 6,0}, /* core1 fp64 bit59 */
			{ 5526, 3,0}, /* core1 fp64 bit60 */
			{ 5526,44,0}, /* core1 fp64 bit61 */
			{ 5527,21,0}, /* core1 fp64 bit62 */
			{ 5527,62,0}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 7711,55,1}, /* core1 sp_EL0 bit0 */
			{ 7712,32,1}, /* core1 sp_EL0 bit1 */
			{ 7713, 9,1}, /* core1 sp_EL0 bit2 */
			{ 7713,50,1}, /* core1 sp_EL0 bit3 */
			{ 6387, 3,0}, /* core1 sp_EL0 bit4 */
			{ 6387,44,0}, /* core1 sp_EL0 bit5 */
			{ 6388,21,0}, /* core1 sp_EL0 bit6 */
			{ 6388,62,0}, /* core1 sp_EL0 bit7 */
			{ 6033,27,0}, /* core1 sp_EL0 bit8 */
			{ 6034, 4,0}, /* core1 sp_EL0 bit9 */
			{ 6034,45,0}, /* core1 sp_EL0 bit10 */
			{ 6035,22,0}, /* core1 sp_EL0 bit11 */
			{ 6381,59,0}, /* core1 sp_EL0 bit12 */
			{ 6382,36,0}, /* core1 sp_EL0 bit13 */
			{ 6383,13,0}, /* core1 sp_EL0 bit14 */
			{ 6383,54,0}, /* core1 sp_EL0 bit15 */
			{ 6043,43,0}, /* core1 sp_EL0 bit16 */
			{ 6044,20,0}, /* core1 sp_EL0 bit17 */
			{ 6044,61,0}, /* core1 sp_EL0 bit18 */
			{ 6045,38,0}, /* core1 sp_EL0 bit19 */
			{ 5715,43,0}, /* core1 sp_EL0 bit20 */
			{ 5716,20,0}, /* core1 sp_EL0 bit21 */
			{ 5716,61,0}, /* core1 sp_EL0 bit22 */
			{ 5717,38,0}, /* core1 sp_EL0 bit23 */
			{ 5725,59,0}, /* core1 sp_EL0 bit24 */
			{ 5726,36,0}, /* core1 sp_EL0 bit25 */
			{ 5727,13,0}, /* core1 sp_EL0 bit26 */
			{ 5727,54,0}, /* core1 sp_EL0 bit27 */
			{ 6415,15,0}, /* core1 sp_EL0 bit28 */
			{ 6415,56,0}, /* core1 sp_EL0 bit29 */
			{ 6416,33,0}, /* core1 sp_EL0 bit30 */
			{ 6417,10,0}, /* core1 sp_EL0 bit31 */
			{ 5244,11,0}, /* core1 sp_EL0 bit32 */
			{ 5244,52,0}, /* core1 sp_EL0 bit33 */
			{ 5245,29,0}, /* core1 sp_EL0 bit34 */
			{ 5246, 6,0}, /* core1 sp_EL0 bit35 */
			{ 5236,31,0}, /* core1 sp_EL0 bit36 */
			{ 5237, 8,0}, /* core1 sp_EL0 bit37 */
			{ 5237,49,0}, /* core1 sp_EL0 bit38 */
			{ 5238,26,0}, /* core1 sp_EL0 bit39 */
			{ 5231,23,0}, /* core1 sp_EL0 bit40 */
			{ 5232, 0,0}, /* core1 sp_EL0 bit41 */
			{ 5232,41,0}, /* core1 sp_EL0 bit42 */
			{ 5233,18,0}, /* core1 sp_EL0 bit43 */
			{ 5233,59,0}, /* core1 sp_EL0 bit44 */
			{ 5234,36,0}, /* core1 sp_EL0 bit45 */
			{ 5235,13,0}, /* core1 sp_EL0 bit46 */
			{ 5235,54,0}, /* core1 sp_EL0 bit47 */
			{ 5159,39,0}, /* core1 sp_EL0 bit48 */
			{ 5160,16,0}, /* core1 sp_EL0 bit49 */
			{ 5160,57,0}, /* core1 sp_EL0 bit50 */
			{ 5161,34,0}, /* core1 sp_EL0 bit51 */
			{ 5249,19,0}, /* core1 sp_EL0 bit52 */
			{ 5249,60,0}, /* core1 sp_EL0 bit53 */
			{ 5250,37,0}, /* core1 sp_EL0 bit54 */
			{ 5251,14,0}, /* core1 sp_EL0 bit55 */
			{ 5274,59,0}, /* core1 sp_EL0 bit56 */
			{ 5275,36,0}, /* core1 sp_EL0 bit57 */
			{ 5276,13,0}, /* core1 sp_EL0 bit58 */
			{ 5276,54,0}, /* core1 sp_EL0 bit59 */
			{ 5285,11,0}, /* core1 sp_EL0 bit60 */
			{ 5285,52,0}, /* core1 sp_EL0 bit61 */
			{ 5286,29,0}, /* core1 sp_EL0 bit62 */
			{ 5287, 6,0}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{10025,44,0}, /* core1 sp_EL1 bit0 */
			{10026,14,0}, /* core1 sp_EL1 bit1 */
			{10026,48,0}, /* core1 sp_EL1 bit2 */
			{10027,18,0}, /* core1 sp_EL1 bit3 */
			{ 2974, 7,0}, /* core1 sp_EL1 bit4 */
			{ 2975, 5,0}, /* core1 sp_EL1 bit5 */
			{ 2976, 3,0}, /* core1 sp_EL1 bit6 */
			{ 2977, 1,0}, /* core1 sp_EL1 bit7 */
			{ 2020,55,0}, /* core1 sp_EL1 bit8 */
			{ 2021,53,0}, /* core1 sp_EL1 bit9 */
			{ 2022,51,0}, /* core1 sp_EL1 bit10 */
			{ 2023,49,0}, /* core1 sp_EL1 bit11 */
			{ 5672, 7,0}, /* core1 sp_EL1 bit12 */
			{ 5672,48,0}, /* core1 sp_EL1 bit13 */
			{ 5673,25,0}, /* core1 sp_EL1 bit14 */
			{ 5674, 2,0}, /* core1 sp_EL1 bit15 */
			{ 5779,47,0}, /* core1 sp_EL1 bit16 */
			{ 5780,24,0}, /* core1 sp_EL1 bit17 */
			{ 5781, 1,0}, /* core1 sp_EL1 bit18 */
			{ 5781,42,0}, /* core1 sp_EL1 bit19 */
			{ 5761,51,0}, /* core1 sp_EL1 bit20 */
			{ 5762,28,0}, /* core1 sp_EL1 bit21 */
			{ 5763, 5,0}, /* core1 sp_EL1 bit22 */
			{ 5763,46,0}, /* core1 sp_EL1 bit23 */
			{ 5697,47,0}, /* core1 sp_EL1 bit24 */
			{ 5698,24,0}, /* core1 sp_EL1 bit25 */
			{ 5699, 1,0}, /* core1 sp_EL1 bit26 */
			{ 5699,42,0}, /* core1 sp_EL1 bit27 */
			{ 5674,43,0}, /* core1 sp_EL1 bit28 */
			{ 5675,20,0}, /* core1 sp_EL1 bit29 */
			{ 5675,61,0}, /* core1 sp_EL1 bit30 */
			{ 5676,38,0}, /* core1 sp_EL1 bit31 */
			{ 5518,23,0}, /* core1 sp_EL1 bit32 */
			{ 5519, 0,0}, /* core1 sp_EL1 bit33 */
			{ 5519,41,0}, /* core1 sp_EL1 bit34 */
			{ 5520,18,0}, /* core1 sp_EL1 bit35 */
			{ 5551,43,0}, /* core1 sp_EL1 bit36 */
			{ 5552,20,0}, /* core1 sp_EL1 bit37 */
			{ 5552,61,0}, /* core1 sp_EL1 bit38 */
			{ 5553,38,0}, /* core1 sp_EL1 bit39 */
			{ 5549, 7,0}, /* core1 sp_EL1 bit40 */
			{ 5549,48,0}, /* core1 sp_EL1 bit41 */
			{ 5550,25,0}, /* core1 sp_EL1 bit42 */
			{ 5551, 2,0}, /* core1 sp_EL1 bit43 */
			{ 5561,59,0}, /* core1 sp_EL1 bit44 */
			{ 5562,36,0}, /* core1 sp_EL1 bit45 */
			{ 5563,13,0}, /* core1 sp_EL1 bit46 */
			{ 5563,54,0}, /* core1 sp_EL1 bit47 */
			{ 5554,15,0}, /* core1 sp_EL1 bit48 */
			{ 5554,56,0}, /* core1 sp_EL1 bit49 */
			{ 5555,33,0}, /* core1 sp_EL1 bit50 */
			{ 5556,10,0}, /* core1 sp_EL1 bit51 */
			{ 5559,23,0}, /* core1 sp_EL1 bit52 */
			{ 5560, 0,0}, /* core1 sp_EL1 bit53 */
			{ 5560,41,0}, /* core1 sp_EL1 bit54 */
			{ 5561,18,0}, /* core1 sp_EL1 bit55 */
			{ 5520,59,0}, /* core1 sp_EL1 bit56 */
			{ 5521,36,0}, /* core1 sp_EL1 bit57 */
			{ 5522,13,0}, /* core1 sp_EL1 bit58 */
			{ 5522,54,0}, /* core1 sp_EL1 bit59 */
			{ 5556,51,0}, /* core1 sp_EL1 bit60 */
			{ 5557,28,0}, /* core1 sp_EL1 bit61 */
			{ 5558, 5,0}, /* core1 sp_EL1 bit62 */
			{ 5558,46,0}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{10012,60,0}, /* core1 sp_EL2 bit0 */
			{10013,30,0}, /* core1 sp_EL2 bit1 */
			{10014, 0,0}, /* core1 sp_EL2 bit2 */
			{10014,34,0}, /* core1 sp_EL2 bit3 */
			{ 2939,15,0}, /* core1 sp_EL2 bit4 */
			{ 2940,13,0}, /* core1 sp_EL2 bit5 */
			{ 2941,11,0}, /* core1 sp_EL2 bit6 */
			{ 2942, 9,0}, /* core1 sp_EL2 bit7 */
			{10015, 4,0}, /* core1 sp_EL2 bit8 */
			{10015,38,0}, /* core1 sp_EL2 bit9 */
			{10016, 8,0}, /* core1 sp_EL2 bit10 */
			{10016,42,0}, /* core1 sp_EL2 bit11 */
			{ 6430,39,0}, /* core1 sp_EL2 bit12 */
			{ 6431,16,0}, /* core1 sp_EL2 bit13 */
			{ 6431,57,0}, /* core1 sp_EL2 bit14 */
			{ 6432,34,0}, /* core1 sp_EL2 bit15 */
			{ 5784,55,0}, /* core1 sp_EL2 bit16 */
			{ 5785,32,0}, /* core1 sp_EL2 bit17 */
			{ 5786, 9,0}, /* core1 sp_EL2 bit18 */
			{ 5786,50,0}, /* core1 sp_EL2 bit19 */
			{ 5707,63,0}, /* core1 sp_EL2 bit20 */
			{ 5708,40,0}, /* core1 sp_EL2 bit21 */
			{ 5709,17,0}, /* core1 sp_EL2 bit22 */
			{ 5709,58,0}, /* core1 sp_EL2 bit23 */
			{ 5733,39,0}, /* core1 sp_EL2 bit24 */
			{ 5734,16,0}, /* core1 sp_EL2 bit25 */
			{ 5734,57,0}, /* core1 sp_EL2 bit26 */
			{ 5735,34,0}, /* core1 sp_EL2 bit27 */
			{ 2943, 7,0}, /* core1 sp_EL2 bit28 */
			{ 2944, 5,0}, /* core1 sp_EL2 bit29 */
			{ 2945, 3,0}, /* core1 sp_EL2 bit30 */
			{ 2946, 1,0}, /* core1 sp_EL2 bit31 */
			{ 5620,55,0}, /* core1 sp_EL2 bit32 */
			{ 5621,32,0}, /* core1 sp_EL2 bit33 */
			{ 5622, 9,0}, /* core1 sp_EL2 bit34 */
			{ 5622,50,0}, /* core1 sp_EL2 bit35 */
			{ 5608, 3,0}, /* core1 sp_EL2 bit36 */
			{ 5608,44,0}, /* core1 sp_EL2 bit37 */
			{ 5609,21,0}, /* core1 sp_EL2 bit38 */
			{ 5609,62,0}, /* core1 sp_EL2 bit39 */
			{ 5605,31,0}, /* core1 sp_EL2 bit40 */
			{ 5606, 8,0}, /* core1 sp_EL2 bit41 */
			{ 5606,49,0}, /* core1 sp_EL2 bit42 */
			{ 5607,26,0}, /* core1 sp_EL2 bit43 */
			{ 5597,51,0}, /* core1 sp_EL2 bit44 */
			{ 5598,28,0}, /* core1 sp_EL2 bit45 */
			{ 5599, 5,0}, /* core1 sp_EL2 bit46 */
			{ 5599,46,0}, /* core1 sp_EL2 bit47 */
			{ 5600,23,0}, /* core1 sp_EL2 bit48 */
			{ 5601, 0,0}, /* core1 sp_EL2 bit49 */
			{ 5601,41,0}, /* core1 sp_EL2 bit50 */
			{ 5602,18,0}, /* core1 sp_EL2 bit51 */
			{ 5610,39,0}, /* core1 sp_EL2 bit52 */
			{ 5611,16,0}, /* core1 sp_EL2 bit53 */
			{ 5611,57,0}, /* core1 sp_EL2 bit54 */
			{ 5612,34,0}, /* core1 sp_EL2 bit55 */
			{ 5615,47,0}, /* core1 sp_EL2 bit56 */
			{ 5616,24,0}, /* core1 sp_EL2 bit57 */
			{ 5617, 1,0}, /* core1 sp_EL2 bit58 */
			{ 5617,42,0}, /* core1 sp_EL2 bit59 */
			{ 5618,19,0}, /* core1 sp_EL2 bit60 */
			{ 5618,60,0}, /* core1 sp_EL2 bit61 */
			{ 5619,37,0}, /* core1 sp_EL2 bit62 */
			{ 5620,14,0}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 7816,59,1}, /* core1 sp_EL3 bit0 */
			{ 7817,36,1}, /* core1 sp_EL3 bit1 */
			{ 7818,13,1}, /* core1 sp_EL3 bit2 */
			{ 7818,54,1}, /* core1 sp_EL3 bit3 */
			{ 5625,63,0}, /* core1 sp_EL3 bit4 */
			{ 5626,40,0}, /* core1 sp_EL3 bit5 */
			{ 5627,17,0}, /* core1 sp_EL3 bit6 */
			{ 5627,58,0}, /* core1 sp_EL3 bit7 */
			{ 7811,51,1}, /* core1 sp_EL3 bit8 */
			{ 7812,28,1}, /* core1 sp_EL3 bit9 */
			{ 7813, 5,1}, /* core1 sp_EL3 bit10 */
			{ 7813,46,1}, /* core1 sp_EL3 bit11 */
			{ 5628,35,0}, /* core1 sp_EL3 bit12 */
			{ 5629,12,0}, /* core1 sp_EL3 bit13 */
			{ 5629,53,0}, /* core1 sp_EL3 bit14 */
			{ 5630,30,0}, /* core1 sp_EL3 bit15 */
			{ 5787,27,0}, /* core1 sp_EL3 bit16 */
			{ 5788, 4,0}, /* core1 sp_EL3 bit17 */
			{ 5788,45,0}, /* core1 sp_EL3 bit18 */
			{ 5789,22,0}, /* core1 sp_EL3 bit19 */
			{ 5710,35,0}, /* core1 sp_EL3 bit20 */
			{ 5711,12,0}, /* core1 sp_EL3 bit21 */
			{ 5711,53,0}, /* core1 sp_EL3 bit22 */
			{ 5712,30,0}, /* core1 sp_EL3 bit23 */
			{ 5731, 3,0}, /* core1 sp_EL3 bit24 */
			{ 5731,44,0}, /* core1 sp_EL3 bit25 */
			{ 5732,21,0}, /* core1 sp_EL3 bit26 */
			{ 5732,62,0}, /* core1 sp_EL3 bit27 */
			{ 6455,38,0}, /* core1 sp_EL3 bit28 */
			{ 6456,15,0}, /* core1 sp_EL3 bit29 */
			{ 6456,56,0}, /* core1 sp_EL3 bit30 */
			{ 6457,33,0}, /* core1 sp_EL3 bit31 */
			{ 5213,27,0}, /* core1 sp_EL3 bit32 */
			{ 5214, 4,0}, /* core1 sp_EL3 bit33 */
			{ 5214,45,0}, /* core1 sp_EL3 bit34 */
			{ 5215,22,0}, /* core1 sp_EL3 bit35 */
			{ 4998,11,0}, /* core1 sp_EL3 bit36 */
			{ 4998,52,0}, /* core1 sp_EL3 bit37 */
			{ 4999,29,0}, /* core1 sp_EL3 bit38 */
			{ 5000, 6,0}, /* core1 sp_EL3 bit39 */
			{ 5062,15,0}, /* core1 sp_EL3 bit40 */
			{ 5062,56,0}, /* core1 sp_EL3 bit41 */
			{ 5063,33,0}, /* core1 sp_EL3 bit42 */
			{ 5064,10,0}, /* core1 sp_EL3 bit43 */
			{ 5059,43,0}, /* core1 sp_EL3 bit44 */
			{ 5060,20,0}, /* core1 sp_EL3 bit45 */
			{ 5060,61,0}, /* core1 sp_EL3 bit46 */
			{ 5061,38,0}, /* core1 sp_EL3 bit47 */
			{ 5057, 7,0}, /* core1 sp_EL3 bit48 */
			{ 5057,48,0}, /* core1 sp_EL3 bit49 */
			{ 5058,25,0}, /* core1 sp_EL3 bit50 */
			{ 5059, 2,0}, /* core1 sp_EL3 bit51 */
			{ 5256,63,0}, /* core1 sp_EL3 bit52 */
			{ 5257,40,0}, /* core1 sp_EL3 bit53 */
			{ 5258,17,0}, /* core1 sp_EL3 bit54 */
			{ 5258,58,0}, /* core1 sp_EL3 bit55 */
			{ 5259,35,0}, /* core1 sp_EL3 bit56 */
			{ 5260,12,0}, /* core1 sp_EL3 bit57 */
			{ 5260,53,0}, /* core1 sp_EL3 bit58 */
			{ 5261,30,0}, /* core1 sp_EL3 bit59 */
			{ 5262, 7,0}, /* core1 sp_EL3 bit60 */
			{ 5262,48,0}, /* core1 sp_EL3 bit61 */
			{ 5263,25,0}, /* core1 sp_EL3 bit62 */
			{ 5264, 2,0}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{ 7814,23,1}, /* core1 elr_EL1 bit0 */
			{ 7815, 0,1}, /* core1 elr_EL1 bit1 */
			{ 7815,41,1}, /* core1 elr_EL1 bit2 */
			{ 7816,18,1}, /* core1 elr_EL1 bit3 */
			{ 6379,23,0}, /* core1 elr_EL1 bit4 */
			{ 6380, 0,0}, /* core1 elr_EL1 bit5 */
			{ 6380,41,0}, /* core1 elr_EL1 bit6 */
			{ 6381,18,0}, /* core1 elr_EL1 bit7 */
			{ 6030,55,0}, /* core1 elr_EL1 bit8 */
			{ 6031,32,0}, /* core1 elr_EL1 bit9 */
			{ 6032, 9,0}, /* core1 elr_EL1 bit10 */
			{ 6032,50,0}, /* core1 elr_EL1 bit11 */
			{ 6384,31,0}, /* core1 elr_EL1 bit12 */
			{ 6385, 8,0}, /* core1 elr_EL1 bit13 */
			{ 6385,49,0}, /* core1 elr_EL1 bit14 */
			{ 6386,26,0}, /* core1 elr_EL1 bit15 */
			{ 7804, 7,1}, /* core1 elr_EL1 bit16 */
			{ 7804,48,1}, /* core1 elr_EL1 bit17 */
			{ 7805,25,1}, /* core1 elr_EL1 bit18 */
			{ 7806, 2,1}, /* core1 elr_EL1 bit19 */
			{ 5713, 7,0}, /* core1 elr_EL1 bit20 */
			{ 5713,48,0}, /* core1 elr_EL1 bit21 */
			{ 5714,25,0}, /* core1 elr_EL1 bit22 */
			{ 5715, 2,0}, /* core1 elr_EL1 bit23 */
			{ 5728,31,0}, /* core1 elr_EL1 bit24 */
			{ 5729, 8,0}, /* core1 elr_EL1 bit25 */
			{ 5729,49,0}, /* core1 elr_EL1 bit26 */
			{ 5730,26,0}, /* core1 elr_EL1 bit27 */
			{ 6412,43,0}, /* core1 elr_EL1 bit28 */
			{ 6413,20,0}, /* core1 elr_EL1 bit29 */
			{ 6413,61,0}, /* core1 elr_EL1 bit30 */
			{ 6414,38,0}, /* core1 elr_EL1 bit31 */
			{ 5215,63,0}, /* core1 elr_EL1 bit32 */
			{ 5216,40,0}, /* core1 elr_EL1 bit33 */
			{ 5217,17,0}, /* core1 elr_EL1 bit34 */
			{ 5217,58,0}, /* core1 elr_EL1 bit35 */
			{ 5164,47,0}, /* core1 elr_EL1 bit36 */
			{ 5165,24,0}, /* core1 elr_EL1 bit37 */
			{ 5166, 1,0}, /* core1 elr_EL1 bit38 */
			{ 5166,42,0}, /* core1 elr_EL1 bit39 */
			{ 5167,19,0}, /* core1 elr_EL1 bit40 */
			{ 5167,60,0}, /* core1 elr_EL1 bit41 */
			{ 5168,37,0}, /* core1 elr_EL1 bit42 */
			{ 5169,14,0}, /* core1 elr_EL1 bit43 */
			{ 5169,55,0}, /* core1 elr_EL1 bit44 */
			{ 5170,32,0}, /* core1 elr_EL1 bit45 */
			{ 5171, 9,0}, /* core1 elr_EL1 bit46 */
			{ 5171,50,0}, /* core1 elr_EL1 bit47 */
			{ 5172,27,0}, /* core1 elr_EL1 bit48 */
			{ 5173, 4,0}, /* core1 elr_EL1 bit49 */
			{ 5173,45,0}, /* core1 elr_EL1 bit50 */
			{ 5174,22,0}, /* core1 elr_EL1 bit51 */
			{ 5254,27,0}, /* core1 elr_EL1 bit52 */
			{ 5255, 4,0}, /* core1 elr_EL1 bit53 */
			{ 5255,45,0}, /* core1 elr_EL1 bit54 */
			{ 5256,22,0}, /* core1 elr_EL1 bit55 */
			{ 5269,51,0}, /* core1 elr_EL1 bit56 */
			{ 5270,28,0}, /* core1 elr_EL1 bit57 */
			{ 5271, 5,0}, /* core1 elr_EL1 bit58 */
			{ 5271,46,0}, /* core1 elr_EL1 bit59 */
			{ 5264,43,0}, /* core1 elr_EL1 bit60 */
			{ 5265,20,0}, /* core1 elr_EL1 bit61 */
			{ 5265,61,0}, /* core1 elr_EL1 bit62 */
			{ 5266,38,0}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 6015,31,0}, /* core1 elr_EL2 bit0 */
			{ 6016, 8,0}, /* core1 elr_EL2 bit1 */
			{ 6016,49,0}, /* core1 elr_EL2 bit2 */
			{ 6017,26,0}, /* core1 elr_EL2 bit3 */
			{ 6371,43,0}, /* core1 elr_EL2 bit4 */
			{ 6372,20,0}, /* core1 elr_EL2 bit5 */
			{ 6372,61,0}, /* core1 elr_EL2 bit6 */
			{ 6373,38,0}, /* core1 elr_EL2 bit7 */
			{ 6094,59,0}, /* core1 elr_EL2 bit8 */
			{ 6095,36,0}, /* core1 elr_EL2 bit9 */
			{ 6096,13,0}, /* core1 elr_EL2 bit10 */
			{ 6096,54,0}, /* core1 elr_EL2 bit11 */
			{ 6374,15,0}, /* core1 elr_EL2 bit12 */
			{ 6374,56,0}, /* core1 elr_EL2 bit13 */
			{ 6375,33,0}, /* core1 elr_EL2 bit14 */
			{ 6376,10,0}, /* core1 elr_EL2 bit15 */
			{ 6048,51,0}, /* core1 elr_EL2 bit16 */
			{ 6049,28,0}, /* core1 elr_EL2 bit17 */
			{ 6050, 5,0}, /* core1 elr_EL2 bit18 */
			{ 6050,46,0}, /* core1 elr_EL2 bit19 */
			{ 6056,31,0}, /* core1 elr_EL2 bit20 */
			{ 6057, 8,0}, /* core1 elr_EL2 bit21 */
			{ 6057,49,0}, /* core1 elr_EL2 bit22 */
			{ 6058,26,0}, /* core1 elr_EL2 bit23 */
			{ 7793,55,1}, /* core1 elr_EL2 bit24 */
			{ 7794,32,1}, /* core1 elr_EL2 bit25 */
			{ 7795, 9,1}, /* core1 elr_EL2 bit26 */
			{ 7795,50,1}, /* core1 elr_EL2 bit27 */
			{ 6407,35,0}, /* core1 elr_EL2 bit28 */
			{ 6408,12,0}, /* core1 elr_EL2 bit29 */
			{ 6408,53,0}, /* core1 elr_EL2 bit30 */
			{ 6409,30,0}, /* core1 elr_EL2 bit31 */
			{ 5246,47,0}, /* core1 elr_EL2 bit32 */
			{ 5247,24,0}, /* core1 elr_EL2 bit33 */
			{ 5248, 1,0}, /* core1 elr_EL2 bit34 */
			{ 5248,42,0}, /* core1 elr_EL2 bit35 */
			{ 5241,39,0}, /* core1 elr_EL2 bit36 */
			{ 5242,16,0}, /* core1 elr_EL2 bit37 */
			{ 5242,57,0}, /* core1 elr_EL2 bit38 */
			{ 5243,34,0}, /* core1 elr_EL2 bit39 */
			{ 5221, 7,0}, /* core1 elr_EL2 bit40 */
			{ 5221,48,0}, /* core1 elr_EL2 bit41 */
			{ 5222,25,0}, /* core1 elr_EL2 bit42 */
			{ 5223, 2,0}, /* core1 elr_EL2 bit43 */
			{ 5239, 3,0}, /* core1 elr_EL2 bit44 */
			{ 5239,44,0}, /* core1 elr_EL2 bit45 */
			{ 5240,21,0}, /* core1 elr_EL2 bit46 */
			{ 5240,62,0}, /* core1 elr_EL2 bit47 */
			{ 5223,43,0}, /* core1 elr_EL2 bit48 */
			{ 5224,20,0}, /* core1 elr_EL2 bit49 */
			{ 5224,61,0}, /* core1 elr_EL2 bit50 */
			{ 5225,38,0}, /* core1 elr_EL2 bit51 */
			{ 5287,47,0}, /* core1 elr_EL2 bit52 */
			{ 5288,24,0}, /* core1 elr_EL2 bit53 */
			{ 5289, 1,0}, /* core1 elr_EL2 bit54 */
			{ 5289,42,0}, /* core1 elr_EL2 bit55 */
			{ 5282,39,0}, /* core1 elr_EL2 bit56 */
			{ 5283,16,0}, /* core1 elr_EL2 bit57 */
			{ 5283,57,0}, /* core1 elr_EL2 bit58 */
			{ 5284,34,0}, /* core1 elr_EL2 bit59 */
			{ 5579,55,0}, /* core1 elr_EL2 bit60 */
			{ 5580,32,0}, /* core1 elr_EL2 bit61 */
			{ 5581, 9,0}, /* core1 elr_EL2 bit62 */
			{ 5581,50,0}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{10010,52,0}, /* core1 elr_EL3 bit0 */
			{10011,22,0}, /* core1 elr_EL3 bit1 */
			{10011,56,0}, /* core1 elr_EL3 bit2 */
			{10012,26,0}, /* core1 elr_EL3 bit3 */
			{ 2935,23,0}, /* core1 elr_EL3 bit4 */
			{ 2936,21,0}, /* core1 elr_EL3 bit5 */
			{ 2937,19,0}, /* core1 elr_EL3 bit6 */
			{ 2938,17,0}, /* core1 elr_EL3 bit7 */
			{ 7809,15,1}, /* core1 elr_EL3 bit8 */
			{ 7809,56,1}, /* core1 elr_EL3 bit9 */
			{ 7810,33,1}, /* core1 elr_EL3 bit10 */
			{ 7811,10,1}, /* core1 elr_EL3 bit11 */
			{ 2931,31,0}, /* core1 elr_EL3 bit12 */
			{ 2932,29,0}, /* core1 elr_EL3 bit13 */
			{ 2933,27,0}, /* core1 elr_EL3 bit14 */
			{ 2934,25,0}, /* core1 elr_EL3 bit15 */
			{ 5782,19,0}, /* core1 elr_EL3 bit16 */
			{ 5782,60,0}, /* core1 elr_EL3 bit17 */
			{ 5783,37,0}, /* core1 elr_EL3 bit18 */
			{ 5784,14,0}, /* core1 elr_EL3 bit19 */
			{ 5705,27,0}, /* core1 elr_EL3 bit20 */
			{ 5706, 4,0}, /* core1 elr_EL3 bit21 */
			{ 5706,45,0}, /* core1 elr_EL3 bit22 */
			{ 5707,22,0}, /* core1 elr_EL3 bit23 */
			{ 5736,11,0}, /* core1 elr_EL3 bit24 */
			{ 5736,52,0}, /* core1 elr_EL3 bit25 */
			{ 5737,29,0}, /* core1 elr_EL3 bit26 */
			{ 5738, 6,0}, /* core1 elr_EL3 bit27 */
			{ 5649, 3,0}, /* core1 elr_EL3 bit28 */
			{ 5649,44,0}, /* core1 elr_EL3 bit29 */
			{ 5650,21,0}, /* core1 elr_EL3 bit30 */
			{ 5650,62,0}, /* core1 elr_EL3 bit31 */
			{ 5508, 7,0}, /* core1 elr_EL3 bit32 */
			{ 5508,48,0}, /* core1 elr_EL3 bit33 */
			{ 5509,25,0}, /* core1 elr_EL3 bit34 */
			{ 5510, 2,0}, /* core1 elr_EL3 bit35 */
			{ 5536,19,0}, /* core1 elr_EL3 bit36 */
			{ 5536,60,0}, /* core1 elr_EL3 bit37 */
			{ 5537,37,0}, /* core1 elr_EL3 bit38 */
			{ 5538,14,0}, /* core1 elr_EL3 bit39 */
			{ 5592,43,0}, /* core1 elr_EL3 bit40 */
			{ 5593,20,0}, /* core1 elr_EL3 bit41 */
			{ 5593,61,0}, /* core1 elr_EL3 bit42 */
			{ 5594,38,0}, /* core1 elr_EL3 bit43 */
			{ 5595,15,0}, /* core1 elr_EL3 bit44 */
			{ 5595,56,0}, /* core1 elr_EL3 bit45 */
			{ 5596,33,0}, /* core1 elr_EL3 bit46 */
			{ 5597,10,0}, /* core1 elr_EL3 bit47 */
			{ 5587,35,0}, /* core1 elr_EL3 bit48 */
			{ 5588,12,0}, /* core1 elr_EL3 bit49 */
			{ 5588,53,0}, /* core1 elr_EL3 bit50 */
			{ 5589,30,0}, /* core1 elr_EL3 bit51 */
			{ 5538,55,0}, /* core1 elr_EL3 bit52 */
			{ 5539,32,0}, /* core1 elr_EL3 bit53 */
			{ 5540, 9,0}, /* core1 elr_EL3 bit54 */
			{ 5540,50,0}, /* core1 elr_EL3 bit55 */
			{ 5613,11,0}, /* core1 elr_EL3 bit56 */
			{ 5613,52,0}, /* core1 elr_EL3 bit57 */
			{ 5614,29,0}, /* core1 elr_EL3 bit58 */
			{ 5615, 6,0}, /* core1 elr_EL3 bit59 */
			{ 5510,43,0}, /* core1 elr_EL3 bit60 */
			{ 5511,20,0}, /* core1 elr_EL3 bit61 */
			{ 5511,61,0}, /* core1 elr_EL3 bit62 */
			{ 5512,38,0}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 7534,26,1}, /* core1 raw_pc bit0 */
			{ 9652,14,0}, /* core1 raw_pc bit1 */
			{ 9652,48,0}, /* core1 raw_pc bit2 */
			{ 4204,27,0}, /* core1 raw_pc bit3 */
			{ 4205,25,0}, /* core1 raw_pc bit4 */
			{ 4206,23,0}, /* core1 raw_pc bit5 */
			{ 4207,21,0}, /* core1 raw_pc bit6 */
			{ 1962,47,0}, /* core1 raw_pc bit7 */
			{ 1963,45,0}, /* core1 raw_pc bit8 */
			{ 1964,43,0}, /* core1 raw_pc bit9 */
			{ 1965,41,0}, /* core1 raw_pc bit10 */
			{ 1970,31,0}, /* core1 raw_pc bit11 */
			{ 1971,29,0}, /* core1 raw_pc bit12 */
			{ 1972,27,0}, /* core1 raw_pc bit13 */
			{ 1973,25,0}, /* core1 raw_pc bit14 */
			{ 1982, 7,0}, /* core1 raw_pc bit15 */
			{ 1983, 5,0}, /* core1 raw_pc bit16 */
			{ 1984, 3,0}, /* core1 raw_pc bit17 */
			{ 1985, 1,0}, /* core1 raw_pc bit18 */
			{ 1966,39,0}, /* core1 raw_pc bit19 */
			{ 1967,37,0}, /* core1 raw_pc bit20 */
			{ 1968,35,0}, /* core1 raw_pc bit21 */
			{ 1969,33,0}, /* core1 raw_pc bit22 */
			{ 1989,55,0}, /* core1 raw_pc bit23 */
			{ 1990,53,0}, /* core1 raw_pc bit24 */
			{ 1991,51,0}, /* core1 raw_pc bit25 */
			{ 1992,49,0}, /* core1 raw_pc bit26 */
			{ 1939,31,0}, /* core1 raw_pc bit27 */
			{ 1940,29,0}, /* core1 raw_pc bit28 */
			{ 1941,27,0}, /* core1 raw_pc bit29 */
			{ 1942,25,0}, /* core1 raw_pc bit30 */
			{  218,62,0}, /* core1 raw_pc bit31 */
			{ 1943,23,0}, /* core1 raw_pc bit32 */
			{ 1944,21,0}, /* core1 raw_pc bit33 */
			{ 1945,19,0}, /* core1 raw_pc bit34 */
			{ 1946,17,0}, /* core1 raw_pc bit35 */
			{ 1931,47,0}, /* core1 raw_pc bit36 */
			{ 1932,45,0}, /* core1 raw_pc bit37 */
			{ 1933,43,0}, /* core1 raw_pc bit38 */
			{ 1934,41,0}, /* core1 raw_pc bit39 */
			{ 1935,39,0}, /* core1 raw_pc bit40 */
			{ 1936,37,0}, /* core1 raw_pc bit41 */
			{ 1937,35,0}, /* core1 raw_pc bit42 */
			{ 1938,33,0}, /* core1 raw_pc bit43 */
			{ 1927,55,0}, /* core1 raw_pc bit44 */
			{ 1928,53,0}, /* core1 raw_pc bit45 */
			{ 1929,51,0}, /* core1 raw_pc bit46 */
			{ 1930,49,0}, /* core1 raw_pc bit47 */
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
			{ 4531,55,0}, /* core1 pc_iss bit0 */
			{ 4528,61,0}, /* core1 pc_iss bit1 */
			{ 4453,25,0}, /* core1 pc_iss bit2 */
			{ 4527,63,0}, /* core1 pc_iss bit3 */
			{ 4454,23,0}, /* core1 pc_iss bit4 */
			{ 4525, 5,0}, /* core1 pc_iss bit5 */
			{ 4529,59,0}, /* core1 pc_iss bit6 */
			{ 4527, 1,0}, /* core1 pc_iss bit7 */
			{ 4457,17,0}, /* core1 pc_iss bit8 */
			{ 4533,51,0}, /* core1 pc_iss bit9 */
			{ 4532,53,0}, /* core1 pc_iss bit10 */
			{ 4536,45,0}, /* core1 pc_iss bit11 */
			{ 4458,15,0}, /* core1 pc_iss bit12 */
			{ 4534,49,0}, /* core1 pc_iss bit13 */
			{ 4535,47,0}, /* core1 pc_iss bit14 */
			{ 4537,43,0}, /* core1 pc_iss bit15 */
			{ 4541,35,0}, /* core1 pc_iss bit16 */
			{ 4539,39,0}, /* core1 pc_iss bit17 */
			{ 4538,41,0}, /* core1 pc_iss bit18 */
			{ 4543,31,0}, /* core1 pc_iss bit19 */
			{ 4540,37,0}, /* core1 pc_iss bit20 */
			{ 4545,27,0}, /* core1 pc_iss bit21 */
			{ 4542,33,0}, /* core1 pc_iss bit22 */
			{ 9565, 6,0}, /* core1 pc_iss bit23 */
			{ 4460,11,0}, /* core1 pc_iss bit24 */
			{ 4544,29,0}, /* core1 pc_iss bit25 */
			{ 4546,25,0}, /* core1 pc_iss bit26 */
			{ 4461, 9,0}, /* core1 pc_iss bit27 */
			{ 4459,13,0}, /* core1 pc_iss bit28 */
			{ 4462, 7,0}, /* core1 pc_iss bit29 */
			{ 9566,44,0}, /* core1 pc_iss bit30 */
			{ 9567,14,0}, /* core1 pc_iss bit31 */
			{ 9655,60,0}, /* core1 pc_iss bit32 */
			{ 9656,30,0}, /* core1 pc_iss bit33 */
			{ 4208,19,0}, /* core1 pc_iss bit34 */
			{ 4209,17,0}, /* core1 pc_iss bit35 */
			{ 4210,15,0}, /* core1 pc_iss bit36 */
			{ 4211,13,0}, /* core1 pc_iss bit37 */
			{ 4212,11,0}, /* core1 pc_iss bit38 */
			{ 4213, 9,0}, /* core1 pc_iss bit39 */
			{ 4214, 7,0}, /* core1 pc_iss bit40 */
			{ 4215, 5,0}, /* core1 pc_iss bit41 */
			{ 4216, 3,0}, /* core1 pc_iss bit42 */
			{ 4217, 1,0}, /* core1 pc_iss bit43 */
			{ 4217,63,0}, /* core1 pc_iss bit44 */
			{ 4218,61,0}, /* core1 pc_iss bit45 */
			{ 9658,38,0}, /* core1 pc_iss bit46 */
			{ 9658, 4,0}, /* core1 pc_iss bit47 */
			{ 9659,42,0}, /* core1 pc_iss bit48 */
			{ 9659, 8,0}, /* core1 pc_iss bit49 */
			{ 9664,28,0}, /* core1 pc_iss bit50 */
			{ 9663,58,0}, /* core1 pc_iss bit51 */
			{ 9566,10,0}, /* core1 pc_iss bit52 */
			{ 9565,40,0}, /* core1 pc_iss bit53 */
			{ 4222,53,0}, /* core1 pc_iss bit54 */
			{ 4221,55,0}, /* core1 pc_iss bit55 */
			{ 4220,57,0}, /* core1 pc_iss bit56 */
			{ 4219,59,0}, /* core1 pc_iss bit57 */
			{ 9662,20,0}, /* core1 pc_iss bit58 */
			{ 9661,50,0}, /* core1 pc_iss bit59 */
			{ 9661,16,0}, /* core1 pc_iss bit60 */
			{ 9660,46,0}, /* core1 pc_iss bit61 */
			{ 9663,24,0}, /* core1 pc_iss bit62 */
			{ 9662,54,0}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 7533,49,1}, /* core1 full_pc_wr bit0 */
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
			{ 4472,49,0}, /* core1 full_pc_ex1 bit0 */
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
			{ 4469,55,0}, /* core1 full_pc_ex2 bit0 */
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
			{ 9802,38,0}, /* core2 pc bit0 */
			{ 9803, 8,0}, /* core2 pc bit1 */
			{ 9803,42,0}, /* core2 pc bit2 */
			{ 9804,12,0}, /* core2 pc bit3 */
			{ 9783,30,0}, /* core2 pc bit4 */
			{ 9784, 0,0}, /* core2 pc bit5 */
			{ 9784,34,0}, /* core2 pc bit6 */
			{ 9785, 4,0}, /* core2 pc bit7 */
			{ 9804,46,0}, /* core2 pc bit8 */
			{ 9805,16,0}, /* core2 pc bit9 */
			{ 9805,50,0}, /* core2 pc bit10 */
			{ 9806,20,0}, /* core2 pc bit11 */
			{ 9787,46,0}, /* core2 pc bit12 */
			{ 9788,16,0}, /* core2 pc bit13 */
			{ 9788,50,0}, /* core2 pc bit14 */
			{ 9789,20,0}, /* core2 pc bit15 */
			{ 9800,30,0}, /* core2 pc bit16 */
			{ 9801, 0,0}, /* core2 pc bit17 */
			{ 9801,34,0}, /* core2 pc bit18 */
			{ 9802, 4,0}, /* core2 pc bit19 */
			{ 2319,17,0}, /* core2 pc bit20 */
			{ 2320,15,0}, /* core2 pc bit21 */
			{ 2321,13,0}, /* core2 pc bit22 */
			{ 2322,11,0}, /* core2 pc bit23 */
			{ 2315,25,0}, /* core2 pc bit24 */
			{ 2316,23,0}, /* core2 pc bit25 */
			{ 2317,21,0}, /* core2 pc bit26 */
			{ 2318,19,0}, /* core2 pc bit27 */
			{ 2299,57,0}, /* core2 pc bit28 */
			{ 2300,55,0}, /* core2 pc bit29 */
			{ 2301,53,0}, /* core2 pc bit30 */
			{ 2302,51,0}, /* core2 pc bit31 */
			{ 9796,14,0}, /* core2 pc bit32 */
			{ 9796,48,0}, /* core2 pc bit33 */
			{ 9797,18,0}, /* core2 pc bit34 */
			{ 9797,52,0}, /* core2 pc bit35 */
			{   12,42,0}, /* core2 pc bit36 */
			{   13,40,0}, /* core2 pc bit37 */
			{   14,38,0}, /* core2 pc bit38 */
			{   15,36,0}, /* core2 pc bit39 */
			{ 9798,22,0}, /* core2 pc bit40 */
			{ 9798,56,0}, /* core2 pc bit41 */
			{ 9799,26,0}, /* core2 pc bit42 */
			{ 9799,60,0}, /* core2 pc bit43 */
			{   16,34,0}, /* core2 pc bit44 */
			{   17,32,0}, /* core2 pc bit45 */
			{   18,30,0}, /* core2 pc bit46 */
			{   19,28,0}, /* core2 pc bit47 */
			{ 9794, 6,0}, /* core2 pc bit48 */
			{ 9794,40,0}, /* core2 pc bit49 */
			{ 9795,10,0}, /* core2 pc bit50 */
			{ 9795,44,0}, /* core2 pc bit51 */
			{ 9785,38,0}, /* core2 pc bit52 */
			{ 9786, 8,0}, /* core2 pc bit53 */
			{ 9786,42,0}, /* core2 pc bit54 */
			{ 9787,12,0}, /* core2 pc bit55 */
			{ 2989,41,0}, /* core2 pc bit56 */
			{ 2990,39,0}, /* core2 pc bit57 */
			{ 2991,37,0}, /* core2 pc bit58 */
			{ 2992,35,0}, /* core2 pc bit59 */
			{   20,26,0}, /* core2 pc bit60 */
			{   21,24,0}, /* core2 pc bit61 */
			{   22,22,0}, /* core2 pc bit62 */
			{   23,20,0}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{ 5777,13,0}, /* core2 sp32 bit0 */
			{ 5777,54,0}, /* core2 sp32 bit1 */
			{ 5778,31,0}, /* core2 sp32 bit2 */
			{ 5779, 8,0}, /* core2 sp32 bit3 */
			{ 5633,45,0}, /* core2 sp32 bit4 */
			{ 5634,22,0}, /* core2 sp32 bit5 */
			{ 5634,63,0}, /* core2 sp32 bit6 */
			{ 5635,40,0}, /* core2 sp32 bit7 */
			{ 2017, 1,0}, /* core2 sp32 bit8 */
			{ 2017,63,0}, /* core2 sp32 bit9 */
			{ 2018,61,0}, /* core2 sp32 bit10 */
			{ 2019,59,0}, /* core2 sp32 bit11 */
			{ 5656,49,0}, /* core2 sp32 bit12 */
			{ 5657,26,0}, /* core2 sp32 bit13 */
			{ 5658, 3,0}, /* core2 sp32 bit14 */
			{ 5658,44,0}, /* core2 sp32 bit15 */
			{ 5774,41,0}, /* core2 sp32 bit16 */
			{ 5775,18,0}, /* core2 sp32 bit17 */
			{ 5775,59,0}, /* core2 sp32 bit18 */
			{ 5776,36,0}, /* core2 sp32 bit19 */
			{ 5769,33,0}, /* core2 sp32 bit20 */
			{ 5770,10,0}, /* core2 sp32 bit21 */
			{ 5770,51,0}, /* core2 sp32 bit22 */
			{ 5771,28,0}, /* core2 sp32 bit23 */
			{ 5749, 1,0}, /* core2 sp32 bit24 */
			{ 5749,42,0}, /* core2 sp32 bit25 */
			{ 5750,19,0}, /* core2 sp32 bit26 */
			{ 5750,60,0}, /* core2 sp32 bit27 */
			{ 5654,13,0}, /* core2 sp32 bit28 */
			{ 5654,54,0}, /* core2 sp32 bit29 */
			{ 5655,31,0}, /* core2 sp32 bit30 */
			{ 5656, 8,0}, /* core2 sp32 bit31 */
			{ 5203,13,0}, /* core2 sp32 bit32 */
			{ 5203,54,0}, /* core2 sp32 bit33 */
			{ 5204,31,0}, /* core2 sp32 bit34 */
			{ 5205, 8,0}, /* core2 sp32 bit35 */
			{ 5356,61,0}, /* core2 sp32 bit36 */
			{ 5357,38,0}, /* core2 sp32 bit37 */
			{ 5358,15,0}, /* core2 sp32 bit38 */
			{ 5358,56,0}, /* core2 sp32 bit39 */
			{ 5133,24,0}, /* core2 sp32 bit40 */
			{ 5134, 1,0}, /* core2 sp32 bit41 */
			{ 5134,42,0}, /* core2 sp32 bit42 */
			{ 5135,19,0}, /* core2 sp32 bit43 */
			{ 5123, 8,0}, /* core2 sp32 bit44 */
			{ 5123,49,0}, /* core2 sp32 bit45 */
			{ 5124,26,0}, /* core2 sp32 bit46 */
			{ 5125, 3,0}, /* core2 sp32 bit47 */
			{ 5125,44,0}, /* core2 sp32 bit48 */
			{ 5126,21,0}, /* core2 sp32 bit49 */
			{ 5126,62,0}, /* core2 sp32 bit50 */
			{ 5127,39,0}, /* core2 sp32 bit51 */
			{ 5387,45,0}, /* core2 sp32 bit52 */
			{ 5388,22,0}, /* core2 sp32 bit53 */
			{ 5388,63,0}, /* core2 sp32 bit54 */
			{ 5389,40,0}, /* core2 sp32 bit55 */
			{ 5390,17,0}, /* core2 sp32 bit56 */
			{ 5390,58,0}, /* core2 sp32 bit57 */
			{ 5391,35,0}, /* core2 sp32 bit58 */
			{ 5392,12,0}, /* core2 sp32 bit59 */
			{ 5392,53,0}, /* core2 sp32 bit60 */
			{ 5393,30,0}, /* core2 sp32 bit61 */
			{ 5394, 7,0}, /* core2 sp32 bit62 */
			{ 5394,48,0}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{ 6107,49,0}, /* core2 fp32 bit0 */
			{ 6108,26,0}, /* core2 fp32 bit1 */
			{ 6109, 3,0}, /* core2 fp32 bit2 */
			{ 6109,44,0}, /* core2 fp32 bit3 */
			{ 6343,33,0}, /* core2 fp32 bit4 */
			{ 6344,10,0}, /* core2 fp32 bit5 */
			{ 6344,51,0}, /* core2 fp32 bit6 */
			{ 6345,28,0}, /* core2 fp32 bit7 */
			{ 1013,25,1}, /* core2 fp32 bit8 */
			{ 1014,23,1}, /* core2 fp32 bit9 */
			{ 1015,21,1}, /* core2 fp32 bit10 */
			{ 1016,19,1}, /* core2 fp32 bit11 */
			{ 6340,61,0}, /* core2 fp32 bit12 */
			{ 6341,38,0}, /* core2 fp32 bit13 */
			{ 6342,15,0}, /* core2 fp32 bit14 */
			{ 6342,56,0}, /* core2 fp32 bit15 */
			{ 6079,37,0}, /* core2 fp32 bit16 */
			{ 6080,14,0}, /* core2 fp32 bit17 */
			{ 6080,55,0}, /* core2 fp32 bit18 */
			{ 6081,32,0}, /* core2 fp32 bit19 */
			{ 5951,29,0}, /* core2 fp32 bit20 */
			{ 5952, 6,0}, /* core2 fp32 bit21 */
			{ 5952,47,0}, /* core2 fp32 bit22 */
			{ 5953,24,0}, /* core2 fp32 bit23 */
			{ 6182, 5,0}, /* core2 fp32 bit24 */
			{ 6182,46,0}, /* core2 fp32 bit25 */
			{ 6183,23,0}, /* core2 fp32 bit26 */
			{ 6184, 0,0}, /* core2 fp32 bit27 */
			{ 5841,17,0}, /* core2 fp32 bit28 */
			{ 5841,58,0}, /* core2 fp32 bit29 */
			{ 5842,35,0}, /* core2 fp32 bit30 */
			{ 5843,12,0}, /* core2 fp32 bit31 */
			{ 5198, 5,0}, /* core2 fp32 bit32 */
			{ 5198,46,0}, /* core2 fp32 bit33 */
			{ 5199,23,0}, /* core2 fp32 bit34 */
			{ 5200, 0,0}, /* core2 fp32 bit35 */
			{ 5195,33,0}, /* core2 fp32 bit36 */
			{ 5196,10,0}, /* core2 fp32 bit37 */
			{ 5196,51,0}, /* core2 fp32 bit38 */
			{ 5197,28,0}, /* core2 fp32 bit39 */
			{ 5135,60,0}, /* core2 fp32 bit40 */
			{ 5136,37,0}, /* core2 fp32 bit41 */
			{ 5137,14,0}, /* core2 fp32 bit42 */
			{ 5137,55,0}, /* core2 fp32 bit43 */
			{ 5141, 4,0}, /* core2 fp32 bit44 */
			{ 5141,45,0}, /* core2 fp32 bit45 */
			{ 5142,22,0}, /* core2 fp32 bit46 */
			{ 5142,63,0}, /* core2 fp32 bit47 */
			{ 5128,16,0}, /* core2 fp32 bit48 */
			{ 5128,57,0}, /* core2 fp32 bit49 */
			{ 5129,34,0}, /* core2 fp32 bit50 */
			{ 5130,11,0}, /* core2 fp32 bit51 */
			{ 5421, 1,0}, /* core2 fp32 bit52 */
			{ 5421,42,0}, /* core2 fp32 bit53 */
			{ 5422,19,0}, /* core2 fp32 bit54 */
			{ 5422,60,0}, /* core2 fp32 bit55 */
			{ 5418,29,0}, /* core2 fp32 bit56 */
			{ 5419, 6,0}, /* core2 fp32 bit57 */
			{ 5419,47,0}, /* core2 fp32 bit58 */
			{ 5420,24,0}, /* core2 fp32 bit59 */
			{ 5200,41,0}, /* core2 fp32 bit60 */
			{ 5201,18,0}, /* core2 fp32 bit61 */
			{ 5201,59,0}, /* core2 fp32 bit62 */
			{ 5202,36,0}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{ 2024,49,0}, /* core2 fp64 bit0 */
			{ 2025,47,0}, /* core2 fp64 bit1 */
			{ 2026,45,0}, /* core2 fp64 bit2 */
			{ 2027,43,0}, /* core2 fp64 bit3 */
			{ 5643,61,0}, /* core2 fp64 bit4 */
			{ 5644,38,0}, /* core2 fp64 bit5 */
			{ 5645,15,0}, /* core2 fp64 bit6 */
			{ 5645,56,0}, /* core2 fp64 bit7 */
			{   28,10,0}, /* core2 fp64 bit8 */
			{   29, 8,0}, /* core2 fp64 bit9 */
			{   30, 6,0}, /* core2 fp64 bit10 */
			{   31, 4,0}, /* core2 fp64 bit11 */
			{ 5646,33,0}, /* core2 fp64 bit12 */
			{ 5647,10,0}, /* core2 fp64 bit13 */
			{ 5647,51,0}, /* core2 fp64 bit14 */
			{ 5648,28,0}, /* core2 fp64 bit15 */
			{ 5772, 5,0}, /* core2 fp64 bit16 */
			{ 5772,46,0}, /* core2 fp64 bit17 */
			{ 5773,23,0}, /* core2 fp64 bit18 */
			{ 5774, 0,0}, /* core2 fp64 bit19 */
			{ 5756,45,0}, /* core2 fp64 bit20 */
			{ 5757,22,0}, /* core2 fp64 bit21 */
			{ 5757,63,0}, /* core2 fp64 bit22 */
			{ 5758,40,0}, /* core2 fp64 bit23 */
			{ 5692,41,0}, /* core2 fp64 bit24 */
			{ 5693,18,0}, /* core2 fp64 bit25 */
			{ 5693,59,0}, /* core2 fp64 bit26 */
			{ 5694,36,0}, /* core2 fp64 bit27 */
			{ 5746,29,0}, /* core2 fp64 bit28 */
			{ 5747, 6,0}, /* core2 fp64 bit29 */
			{ 5747,47,0}, /* core2 fp64 bit30 */
			{ 5748,24,0}, /* core2 fp64 bit31 */
			{ 5528,41,0}, /* core2 fp64 bit32 */
			{ 5529,18,0}, /* core2 fp64 bit33 */
			{ 5529,59,0}, /* core2 fp64 bit34 */
			{ 5530,36,0}, /* core2 fp64 bit35 */
			{ 5544, 1,0}, /* core2 fp64 bit36 */
			{ 5544,42,0}, /* core2 fp64 bit37 */
			{ 5545,19,0}, /* core2 fp64 bit38 */
			{ 5545,60,0}, /* core2 fp64 bit39 */
			{ 5533,49,0}, /* core2 fp64 bit40 */
			{ 5534,26,0}, /* core2 fp64 bit41 */
			{ 5535, 3,0}, /* core2 fp64 bit42 */
			{ 5535,44,0}, /* core2 fp64 bit43 */
			{ 5523,33,0}, /* core2 fp64 bit44 */
			{ 5524,10,0}, /* core2 fp64 bit45 */
			{ 5524,51,0}, /* core2 fp64 bit46 */
			{ 5525,28,0}, /* core2 fp64 bit47 */
			{ 5590, 9,0}, /* core2 fp64 bit48 */
			{ 5590,50,0}, /* core2 fp64 bit49 */
			{ 5591,27,0}, /* core2 fp64 bit50 */
			{ 5592, 4,0}, /* core2 fp64 bit51 */
			{ 5541,29,0}, /* core2 fp64 bit52 */
			{ 5542, 6,0}, /* core2 fp64 bit53 */
			{ 5542,47,0}, /* core2 fp64 bit54 */
			{ 5543,24,0}, /* core2 fp64 bit55 */
			{ 5531,13,0}, /* core2 fp64 bit56 */
			{ 5531,54,0}, /* core2 fp64 bit57 */
			{ 5532,31,0}, /* core2 fp64 bit58 */
			{ 5533, 8,0}, /* core2 fp64 bit59 */
			{ 5526, 5,0}, /* core2 fp64 bit60 */
			{ 5526,46,0}, /* core2 fp64 bit61 */
			{ 5527,23,0}, /* core2 fp64 bit62 */
			{ 5528, 0,0}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 7711,57,1}, /* core2 sp_EL0 bit0 */
			{ 7712,34,1}, /* core2 sp_EL0 bit1 */
			{ 7713,11,1}, /* core2 sp_EL0 bit2 */
			{ 7713,52,1}, /* core2 sp_EL0 bit3 */
			{ 6387, 5,0}, /* core2 sp_EL0 bit4 */
			{ 6387,46,0}, /* core2 sp_EL0 bit5 */
			{ 6388,23,0}, /* core2 sp_EL0 bit6 */
			{ 6389, 0,0}, /* core2 sp_EL0 bit7 */
			{ 6033,29,0}, /* core2 sp_EL0 bit8 */
			{ 6034, 6,0}, /* core2 sp_EL0 bit9 */
			{ 6034,47,0}, /* core2 sp_EL0 bit10 */
			{ 6035,24,0}, /* core2 sp_EL0 bit11 */
			{ 6381,61,0}, /* core2 sp_EL0 bit12 */
			{ 6382,38,0}, /* core2 sp_EL0 bit13 */
			{ 6383,15,0}, /* core2 sp_EL0 bit14 */
			{ 6383,56,0}, /* core2 sp_EL0 bit15 */
			{ 6043,45,0}, /* core2 sp_EL0 bit16 */
			{ 6044,22,0}, /* core2 sp_EL0 bit17 */
			{ 6044,63,0}, /* core2 sp_EL0 bit18 */
			{ 6045,40,0}, /* core2 sp_EL0 bit19 */
			{ 5715,45,0}, /* core2 sp_EL0 bit20 */
			{ 5716,22,0}, /* core2 sp_EL0 bit21 */
			{ 5716,63,0}, /* core2 sp_EL0 bit22 */
			{ 5717,40,0}, /* core2 sp_EL0 bit23 */
			{ 5725,61,0}, /* core2 sp_EL0 bit24 */
			{ 5726,38,0}, /* core2 sp_EL0 bit25 */
			{ 5727,15,0}, /* core2 sp_EL0 bit26 */
			{ 5727,56,0}, /* core2 sp_EL0 bit27 */
			{ 6415,17,0}, /* core2 sp_EL0 bit28 */
			{ 6415,58,0}, /* core2 sp_EL0 bit29 */
			{ 6416,35,0}, /* core2 sp_EL0 bit30 */
			{ 6417,12,0}, /* core2 sp_EL0 bit31 */
			{ 5244,13,0}, /* core2 sp_EL0 bit32 */
			{ 5244,54,0}, /* core2 sp_EL0 bit33 */
			{ 5245,31,0}, /* core2 sp_EL0 bit34 */
			{ 5246, 8,0}, /* core2 sp_EL0 bit35 */
			{ 5236,33,0}, /* core2 sp_EL0 bit36 */
			{ 5237,10,0}, /* core2 sp_EL0 bit37 */
			{ 5237,51,0}, /* core2 sp_EL0 bit38 */
			{ 5238,28,0}, /* core2 sp_EL0 bit39 */
			{ 5231,25,0}, /* core2 sp_EL0 bit40 */
			{ 5232, 2,0}, /* core2 sp_EL0 bit41 */
			{ 5232,43,0}, /* core2 sp_EL0 bit42 */
			{ 5233,20,0}, /* core2 sp_EL0 bit43 */
			{ 5233,61,0}, /* core2 sp_EL0 bit44 */
			{ 5234,38,0}, /* core2 sp_EL0 bit45 */
			{ 5235,15,0}, /* core2 sp_EL0 bit46 */
			{ 5235,56,0}, /* core2 sp_EL0 bit47 */
			{ 5159,41,0}, /* core2 sp_EL0 bit48 */
			{ 5160,18,0}, /* core2 sp_EL0 bit49 */
			{ 5160,59,0}, /* core2 sp_EL0 bit50 */
			{ 5161,36,0}, /* core2 sp_EL0 bit51 */
			{ 5249,21,0}, /* core2 sp_EL0 bit52 */
			{ 5249,62,0}, /* core2 sp_EL0 bit53 */
			{ 5250,39,0}, /* core2 sp_EL0 bit54 */
			{ 5251,16,0}, /* core2 sp_EL0 bit55 */
			{ 5274,61,0}, /* core2 sp_EL0 bit56 */
			{ 5275,38,0}, /* core2 sp_EL0 bit57 */
			{ 5276,15,0}, /* core2 sp_EL0 bit58 */
			{ 5276,56,0}, /* core2 sp_EL0 bit59 */
			{ 5285,13,0}, /* core2 sp_EL0 bit60 */
			{ 5285,54,0}, /* core2 sp_EL0 bit61 */
			{ 5286,31,0}, /* core2 sp_EL0 bit62 */
			{ 5287, 8,0}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{10025,46,0}, /* core2 sp_EL1 bit0 */
			{10026,16,0}, /* core2 sp_EL1 bit1 */
			{10026,50,0}, /* core2 sp_EL1 bit2 */
			{10027,20,0}, /* core2 sp_EL1 bit3 */
			{ 2974, 9,0}, /* core2 sp_EL1 bit4 */
			{ 2975, 7,0}, /* core2 sp_EL1 bit5 */
			{ 2976, 5,0}, /* core2 sp_EL1 bit6 */
			{ 2977, 3,0}, /* core2 sp_EL1 bit7 */
			{ 2020,57,0}, /* core2 sp_EL1 bit8 */
			{ 2021,55,0}, /* core2 sp_EL1 bit9 */
			{ 2022,53,0}, /* core2 sp_EL1 bit10 */
			{ 2023,51,0}, /* core2 sp_EL1 bit11 */
			{ 5672, 9,0}, /* core2 sp_EL1 bit12 */
			{ 5672,50,0}, /* core2 sp_EL1 bit13 */
			{ 5673,27,0}, /* core2 sp_EL1 bit14 */
			{ 5674, 4,0}, /* core2 sp_EL1 bit15 */
			{ 5779,49,0}, /* core2 sp_EL1 bit16 */
			{ 5780,26,0}, /* core2 sp_EL1 bit17 */
			{ 5781, 3,0}, /* core2 sp_EL1 bit18 */
			{ 5781,44,0}, /* core2 sp_EL1 bit19 */
			{ 5761,53,0}, /* core2 sp_EL1 bit20 */
			{ 5762,30,0}, /* core2 sp_EL1 bit21 */
			{ 5763, 7,0}, /* core2 sp_EL1 bit22 */
			{ 5763,48,0}, /* core2 sp_EL1 bit23 */
			{ 5697,49,0}, /* core2 sp_EL1 bit24 */
			{ 5698,26,0}, /* core2 sp_EL1 bit25 */
			{ 5699, 3,0}, /* core2 sp_EL1 bit26 */
			{ 5699,44,0}, /* core2 sp_EL1 bit27 */
			{ 5674,45,0}, /* core2 sp_EL1 bit28 */
			{ 5675,22,0}, /* core2 sp_EL1 bit29 */
			{ 5675,63,0}, /* core2 sp_EL1 bit30 */
			{ 5676,40,0}, /* core2 sp_EL1 bit31 */
			{ 5518,25,0}, /* core2 sp_EL1 bit32 */
			{ 5519, 2,0}, /* core2 sp_EL1 bit33 */
			{ 5519,43,0}, /* core2 sp_EL1 bit34 */
			{ 5520,20,0}, /* core2 sp_EL1 bit35 */
			{ 5551,45,0}, /* core2 sp_EL1 bit36 */
			{ 5552,22,0}, /* core2 sp_EL1 bit37 */
			{ 5552,63,0}, /* core2 sp_EL1 bit38 */
			{ 5553,40,0}, /* core2 sp_EL1 bit39 */
			{ 5549, 9,0}, /* core2 sp_EL1 bit40 */
			{ 5549,50,0}, /* core2 sp_EL1 bit41 */
			{ 5550,27,0}, /* core2 sp_EL1 bit42 */
			{ 5551, 4,0}, /* core2 sp_EL1 bit43 */
			{ 5561,61,0}, /* core2 sp_EL1 bit44 */
			{ 5562,38,0}, /* core2 sp_EL1 bit45 */
			{ 5563,15,0}, /* core2 sp_EL1 bit46 */
			{ 5563,56,0}, /* core2 sp_EL1 bit47 */
			{ 5554,17,0}, /* core2 sp_EL1 bit48 */
			{ 5554,58,0}, /* core2 sp_EL1 bit49 */
			{ 5555,35,0}, /* core2 sp_EL1 bit50 */
			{ 5556,12,0}, /* core2 sp_EL1 bit51 */
			{ 5559,25,0}, /* core2 sp_EL1 bit52 */
			{ 5560, 2,0}, /* core2 sp_EL1 bit53 */
			{ 5560,43,0}, /* core2 sp_EL1 bit54 */
			{ 5561,20,0}, /* core2 sp_EL1 bit55 */
			{ 5520,61,0}, /* core2 sp_EL1 bit56 */
			{ 5521,38,0}, /* core2 sp_EL1 bit57 */
			{ 5522,15,0}, /* core2 sp_EL1 bit58 */
			{ 5522,56,0}, /* core2 sp_EL1 bit59 */
			{ 5556,53,0}, /* core2 sp_EL1 bit60 */
			{ 5557,30,0}, /* core2 sp_EL1 bit61 */
			{ 5558, 7,0}, /* core2 sp_EL1 bit62 */
			{ 5558,48,0}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{10012,62,0}, /* core2 sp_EL2 bit0 */
			{10013,32,0}, /* core2 sp_EL2 bit1 */
			{10014, 2,0}, /* core2 sp_EL2 bit2 */
			{10014,36,0}, /* core2 sp_EL2 bit3 */
			{ 2939,17,0}, /* core2 sp_EL2 bit4 */
			{ 2940,15,0}, /* core2 sp_EL2 bit5 */
			{ 2941,13,0}, /* core2 sp_EL2 bit6 */
			{ 2942,11,0}, /* core2 sp_EL2 bit7 */
			{10015, 6,0}, /* core2 sp_EL2 bit8 */
			{10015,40,0}, /* core2 sp_EL2 bit9 */
			{10016,10,0}, /* core2 sp_EL2 bit10 */
			{10016,44,0}, /* core2 sp_EL2 bit11 */
			{ 6430,41,0}, /* core2 sp_EL2 bit12 */
			{ 6431,18,0}, /* core2 sp_EL2 bit13 */
			{ 6431,59,0}, /* core2 sp_EL2 bit14 */
			{ 6432,36,0}, /* core2 sp_EL2 bit15 */
			{ 5784,57,0}, /* core2 sp_EL2 bit16 */
			{ 5785,34,0}, /* core2 sp_EL2 bit17 */
			{ 5786,11,0}, /* core2 sp_EL2 bit18 */
			{ 5786,52,0}, /* core2 sp_EL2 bit19 */
			{ 5708, 1,0}, /* core2 sp_EL2 bit20 */
			{ 5708,42,0}, /* core2 sp_EL2 bit21 */
			{ 5709,19,0}, /* core2 sp_EL2 bit22 */
			{ 5709,60,0}, /* core2 sp_EL2 bit23 */
			{ 5733,41,0}, /* core2 sp_EL2 bit24 */
			{ 5734,18,0}, /* core2 sp_EL2 bit25 */
			{ 5734,59,0}, /* core2 sp_EL2 bit26 */
			{ 5735,36,0}, /* core2 sp_EL2 bit27 */
			{ 2943, 9,0}, /* core2 sp_EL2 bit28 */
			{ 2944, 7,0}, /* core2 sp_EL2 bit29 */
			{ 2945, 5,0}, /* core2 sp_EL2 bit30 */
			{ 2946, 3,0}, /* core2 sp_EL2 bit31 */
			{ 5620,57,0}, /* core2 sp_EL2 bit32 */
			{ 5621,34,0}, /* core2 sp_EL2 bit33 */
			{ 5622,11,0}, /* core2 sp_EL2 bit34 */
			{ 5622,52,0}, /* core2 sp_EL2 bit35 */
			{ 5608, 5,0}, /* core2 sp_EL2 bit36 */
			{ 5608,46,0}, /* core2 sp_EL2 bit37 */
			{ 5609,23,0}, /* core2 sp_EL2 bit38 */
			{ 5610, 0,0}, /* core2 sp_EL2 bit39 */
			{ 5605,33,0}, /* core2 sp_EL2 bit40 */
			{ 5606,10,0}, /* core2 sp_EL2 bit41 */
			{ 5606,51,0}, /* core2 sp_EL2 bit42 */
			{ 5607,28,0}, /* core2 sp_EL2 bit43 */
			{ 5597,53,0}, /* core2 sp_EL2 bit44 */
			{ 5598,30,0}, /* core2 sp_EL2 bit45 */
			{ 5599, 7,0}, /* core2 sp_EL2 bit46 */
			{ 5599,48,0}, /* core2 sp_EL2 bit47 */
			{ 5600,25,0}, /* core2 sp_EL2 bit48 */
			{ 5601, 2,0}, /* core2 sp_EL2 bit49 */
			{ 5601,43,0}, /* core2 sp_EL2 bit50 */
			{ 5602,20,0}, /* core2 sp_EL2 bit51 */
			{ 5610,41,0}, /* core2 sp_EL2 bit52 */
			{ 5611,18,0}, /* core2 sp_EL2 bit53 */
			{ 5611,59,0}, /* core2 sp_EL2 bit54 */
			{ 5612,36,0}, /* core2 sp_EL2 bit55 */
			{ 5615,49,0}, /* core2 sp_EL2 bit56 */
			{ 5616,26,0}, /* core2 sp_EL2 bit57 */
			{ 5617, 3,0}, /* core2 sp_EL2 bit58 */
			{ 5617,44,0}, /* core2 sp_EL2 bit59 */
			{ 5618,21,0}, /* core2 sp_EL2 bit60 */
			{ 5618,62,0}, /* core2 sp_EL2 bit61 */
			{ 5619,39,0}, /* core2 sp_EL2 bit62 */
			{ 5620,16,0}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 7816,61,1}, /* core2 sp_EL3 bit0 */
			{ 7817,38,1}, /* core2 sp_EL3 bit1 */
			{ 7818,15,1}, /* core2 sp_EL3 bit2 */
			{ 7818,56,1}, /* core2 sp_EL3 bit3 */
			{ 5626, 1,0}, /* core2 sp_EL3 bit4 */
			{ 5626,42,0}, /* core2 sp_EL3 bit5 */
			{ 5627,19,0}, /* core2 sp_EL3 bit6 */
			{ 5627,60,0}, /* core2 sp_EL3 bit7 */
			{ 7811,53,1}, /* core2 sp_EL3 bit8 */
			{ 7812,30,1}, /* core2 sp_EL3 bit9 */
			{ 7813, 7,1}, /* core2 sp_EL3 bit10 */
			{ 7813,48,1}, /* core2 sp_EL3 bit11 */
			{ 5628,37,0}, /* core2 sp_EL3 bit12 */
			{ 5629,14,0}, /* core2 sp_EL3 bit13 */
			{ 5629,55,0}, /* core2 sp_EL3 bit14 */
			{ 5630,32,0}, /* core2 sp_EL3 bit15 */
			{ 5787,29,0}, /* core2 sp_EL3 bit16 */
			{ 5788, 6,0}, /* core2 sp_EL3 bit17 */
			{ 5788,47,0}, /* core2 sp_EL3 bit18 */
			{ 5789,24,0}, /* core2 sp_EL3 bit19 */
			{ 5710,37,0}, /* core2 sp_EL3 bit20 */
			{ 5711,14,0}, /* core2 sp_EL3 bit21 */
			{ 5711,55,0}, /* core2 sp_EL3 bit22 */
			{ 5712,32,0}, /* core2 sp_EL3 bit23 */
			{ 5731, 5,0}, /* core2 sp_EL3 bit24 */
			{ 5731,46,0}, /* core2 sp_EL3 bit25 */
			{ 5732,23,0}, /* core2 sp_EL3 bit26 */
			{ 5733, 0,0}, /* core2 sp_EL3 bit27 */
			{ 6455,40,0}, /* core2 sp_EL3 bit28 */
			{ 6456,17,0}, /* core2 sp_EL3 bit29 */
			{ 6456,58,0}, /* core2 sp_EL3 bit30 */
			{ 6457,35,0}, /* core2 sp_EL3 bit31 */
			{ 5213,29,0}, /* core2 sp_EL3 bit32 */
			{ 5214, 6,0}, /* core2 sp_EL3 bit33 */
			{ 5214,47,0}, /* core2 sp_EL3 bit34 */
			{ 5215,24,0}, /* core2 sp_EL3 bit35 */
			{ 4998,13,0}, /* core2 sp_EL3 bit36 */
			{ 4998,54,0}, /* core2 sp_EL3 bit37 */
			{ 4999,31,0}, /* core2 sp_EL3 bit38 */
			{ 5000, 8,0}, /* core2 sp_EL3 bit39 */
			{ 5062,17,0}, /* core2 sp_EL3 bit40 */
			{ 5062,58,0}, /* core2 sp_EL3 bit41 */
			{ 5063,35,0}, /* core2 sp_EL3 bit42 */
			{ 5064,12,0}, /* core2 sp_EL3 bit43 */
			{ 5059,45,0}, /* core2 sp_EL3 bit44 */
			{ 5060,22,0}, /* core2 sp_EL3 bit45 */
			{ 5060,63,0}, /* core2 sp_EL3 bit46 */
			{ 5061,40,0}, /* core2 sp_EL3 bit47 */
			{ 5057, 9,0}, /* core2 sp_EL3 bit48 */
			{ 5057,50,0}, /* core2 sp_EL3 bit49 */
			{ 5058,27,0}, /* core2 sp_EL3 bit50 */
			{ 5059, 4,0}, /* core2 sp_EL3 bit51 */
			{ 5257, 1,0}, /* core2 sp_EL3 bit52 */
			{ 5257,42,0}, /* core2 sp_EL3 bit53 */
			{ 5258,19,0}, /* core2 sp_EL3 bit54 */
			{ 5258,60,0}, /* core2 sp_EL3 bit55 */
			{ 5259,37,0}, /* core2 sp_EL3 bit56 */
			{ 5260,14,0}, /* core2 sp_EL3 bit57 */
			{ 5260,55,0}, /* core2 sp_EL3 bit58 */
			{ 5261,32,0}, /* core2 sp_EL3 bit59 */
			{ 5262, 9,0}, /* core2 sp_EL3 bit60 */
			{ 5262,50,0}, /* core2 sp_EL3 bit61 */
			{ 5263,27,0}, /* core2 sp_EL3 bit62 */
			{ 5264, 4,0}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{ 7814,25,1}, /* core2 elr_EL1 bit0 */
			{ 7815, 2,1}, /* core2 elr_EL1 bit1 */
			{ 7815,43,1}, /* core2 elr_EL1 bit2 */
			{ 7816,20,1}, /* core2 elr_EL1 bit3 */
			{ 6379,25,0}, /* core2 elr_EL1 bit4 */
			{ 6380, 2,0}, /* core2 elr_EL1 bit5 */
			{ 6380,43,0}, /* core2 elr_EL1 bit6 */
			{ 6381,20,0}, /* core2 elr_EL1 bit7 */
			{ 6030,57,0}, /* core2 elr_EL1 bit8 */
			{ 6031,34,0}, /* core2 elr_EL1 bit9 */
			{ 6032,11,0}, /* core2 elr_EL1 bit10 */
			{ 6032,52,0}, /* core2 elr_EL1 bit11 */
			{ 6384,33,0}, /* core2 elr_EL1 bit12 */
			{ 6385,10,0}, /* core2 elr_EL1 bit13 */
			{ 6385,51,0}, /* core2 elr_EL1 bit14 */
			{ 6386,28,0}, /* core2 elr_EL1 bit15 */
			{ 7804, 9,1}, /* core2 elr_EL1 bit16 */
			{ 7804,50,1}, /* core2 elr_EL1 bit17 */
			{ 7805,27,1}, /* core2 elr_EL1 bit18 */
			{ 7806, 4,1}, /* core2 elr_EL1 bit19 */
			{ 5713, 9,0}, /* core2 elr_EL1 bit20 */
			{ 5713,50,0}, /* core2 elr_EL1 bit21 */
			{ 5714,27,0}, /* core2 elr_EL1 bit22 */
			{ 5715, 4,0}, /* core2 elr_EL1 bit23 */
			{ 5728,33,0}, /* core2 elr_EL1 bit24 */
			{ 5729,10,0}, /* core2 elr_EL1 bit25 */
			{ 5729,51,0}, /* core2 elr_EL1 bit26 */
			{ 5730,28,0}, /* core2 elr_EL1 bit27 */
			{ 6412,45,0}, /* core2 elr_EL1 bit28 */
			{ 6413,22,0}, /* core2 elr_EL1 bit29 */
			{ 6413,63,0}, /* core2 elr_EL1 bit30 */
			{ 6414,40,0}, /* core2 elr_EL1 bit31 */
			{ 5216, 1,0}, /* core2 elr_EL1 bit32 */
			{ 5216,42,0}, /* core2 elr_EL1 bit33 */
			{ 5217,19,0}, /* core2 elr_EL1 bit34 */
			{ 5217,60,0}, /* core2 elr_EL1 bit35 */
			{ 5164,49,0}, /* core2 elr_EL1 bit36 */
			{ 5165,26,0}, /* core2 elr_EL1 bit37 */
			{ 5166, 3,0}, /* core2 elr_EL1 bit38 */
			{ 5166,44,0}, /* core2 elr_EL1 bit39 */
			{ 5167,21,0}, /* core2 elr_EL1 bit40 */
			{ 5167,62,0}, /* core2 elr_EL1 bit41 */
			{ 5168,39,0}, /* core2 elr_EL1 bit42 */
			{ 5169,16,0}, /* core2 elr_EL1 bit43 */
			{ 5169,57,0}, /* core2 elr_EL1 bit44 */
			{ 5170,34,0}, /* core2 elr_EL1 bit45 */
			{ 5171,11,0}, /* core2 elr_EL1 bit46 */
			{ 5171,52,0}, /* core2 elr_EL1 bit47 */
			{ 5172,29,0}, /* core2 elr_EL1 bit48 */
			{ 5173, 6,0}, /* core2 elr_EL1 bit49 */
			{ 5173,47,0}, /* core2 elr_EL1 bit50 */
			{ 5174,24,0}, /* core2 elr_EL1 bit51 */
			{ 5254,29,0}, /* core2 elr_EL1 bit52 */
			{ 5255, 6,0}, /* core2 elr_EL1 bit53 */
			{ 5255,47,0}, /* core2 elr_EL1 bit54 */
			{ 5256,24,0}, /* core2 elr_EL1 bit55 */
			{ 5269,53,0}, /* core2 elr_EL1 bit56 */
			{ 5270,30,0}, /* core2 elr_EL1 bit57 */
			{ 5271, 7,0}, /* core2 elr_EL1 bit58 */
			{ 5271,48,0}, /* core2 elr_EL1 bit59 */
			{ 5264,45,0}, /* core2 elr_EL1 bit60 */
			{ 5265,22,0}, /* core2 elr_EL1 bit61 */
			{ 5265,63,0}, /* core2 elr_EL1 bit62 */
			{ 5266,40,0}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 6015,33,0}, /* core2 elr_EL2 bit0 */
			{ 6016,10,0}, /* core2 elr_EL2 bit1 */
			{ 6016,51,0}, /* core2 elr_EL2 bit2 */
			{ 6017,28,0}, /* core2 elr_EL2 bit3 */
			{ 6371,45,0}, /* core2 elr_EL2 bit4 */
			{ 6372,22,0}, /* core2 elr_EL2 bit5 */
			{ 6372,63,0}, /* core2 elr_EL2 bit6 */
			{ 6373,40,0}, /* core2 elr_EL2 bit7 */
			{ 6094,61,0}, /* core2 elr_EL2 bit8 */
			{ 6095,38,0}, /* core2 elr_EL2 bit9 */
			{ 6096,15,0}, /* core2 elr_EL2 bit10 */
			{ 6096,56,0}, /* core2 elr_EL2 bit11 */
			{ 6374,17,0}, /* core2 elr_EL2 bit12 */
			{ 6374,58,0}, /* core2 elr_EL2 bit13 */
			{ 6375,35,0}, /* core2 elr_EL2 bit14 */
			{ 6376,12,0}, /* core2 elr_EL2 bit15 */
			{ 6048,53,0}, /* core2 elr_EL2 bit16 */
			{ 6049,30,0}, /* core2 elr_EL2 bit17 */
			{ 6050, 7,0}, /* core2 elr_EL2 bit18 */
			{ 6050,48,0}, /* core2 elr_EL2 bit19 */
			{ 6056,33,0}, /* core2 elr_EL2 bit20 */
			{ 6057,10,0}, /* core2 elr_EL2 bit21 */
			{ 6057,51,0}, /* core2 elr_EL2 bit22 */
			{ 6058,28,0}, /* core2 elr_EL2 bit23 */
			{ 7793,57,1}, /* core2 elr_EL2 bit24 */
			{ 7794,34,1}, /* core2 elr_EL2 bit25 */
			{ 7795,11,1}, /* core2 elr_EL2 bit26 */
			{ 7795,52,1}, /* core2 elr_EL2 bit27 */
			{ 6407,37,0}, /* core2 elr_EL2 bit28 */
			{ 6408,14,0}, /* core2 elr_EL2 bit29 */
			{ 6408,55,0}, /* core2 elr_EL2 bit30 */
			{ 6409,32,0}, /* core2 elr_EL2 bit31 */
			{ 5246,49,0}, /* core2 elr_EL2 bit32 */
			{ 5247,26,0}, /* core2 elr_EL2 bit33 */
			{ 5248, 3,0}, /* core2 elr_EL2 bit34 */
			{ 5248,44,0}, /* core2 elr_EL2 bit35 */
			{ 5241,41,0}, /* core2 elr_EL2 bit36 */
			{ 5242,18,0}, /* core2 elr_EL2 bit37 */
			{ 5242,59,0}, /* core2 elr_EL2 bit38 */
			{ 5243,36,0}, /* core2 elr_EL2 bit39 */
			{ 5221, 9,0}, /* core2 elr_EL2 bit40 */
			{ 5221,50,0}, /* core2 elr_EL2 bit41 */
			{ 5222,27,0}, /* core2 elr_EL2 bit42 */
			{ 5223, 4,0}, /* core2 elr_EL2 bit43 */
			{ 5239, 5,0}, /* core2 elr_EL2 bit44 */
			{ 5239,46,0}, /* core2 elr_EL2 bit45 */
			{ 5240,23,0}, /* core2 elr_EL2 bit46 */
			{ 5241, 0,0}, /* core2 elr_EL2 bit47 */
			{ 5223,45,0}, /* core2 elr_EL2 bit48 */
			{ 5224,22,0}, /* core2 elr_EL2 bit49 */
			{ 5224,63,0}, /* core2 elr_EL2 bit50 */
			{ 5225,40,0}, /* core2 elr_EL2 bit51 */
			{ 5287,49,0}, /* core2 elr_EL2 bit52 */
			{ 5288,26,0}, /* core2 elr_EL2 bit53 */
			{ 5289, 3,0}, /* core2 elr_EL2 bit54 */
			{ 5289,44,0}, /* core2 elr_EL2 bit55 */
			{ 5282,41,0}, /* core2 elr_EL2 bit56 */
			{ 5283,18,0}, /* core2 elr_EL2 bit57 */
			{ 5283,59,0}, /* core2 elr_EL2 bit58 */
			{ 5284,36,0}, /* core2 elr_EL2 bit59 */
			{ 5579,57,0}, /* core2 elr_EL2 bit60 */
			{ 5580,34,0}, /* core2 elr_EL2 bit61 */
			{ 5581,11,0}, /* core2 elr_EL2 bit62 */
			{ 5581,52,0}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{10010,54,0}, /* core2 elr_EL3 bit0 */
			{10011,24,0}, /* core2 elr_EL3 bit1 */
			{10011,58,0}, /* core2 elr_EL3 bit2 */
			{10012,28,0}, /* core2 elr_EL3 bit3 */
			{ 2935,25,0}, /* core2 elr_EL3 bit4 */
			{ 2936,23,0}, /* core2 elr_EL3 bit5 */
			{ 2937,21,0}, /* core2 elr_EL3 bit6 */
			{ 2938,19,0}, /* core2 elr_EL3 bit7 */
			{ 7809,17,1}, /* core2 elr_EL3 bit8 */
			{ 7809,58,1}, /* core2 elr_EL3 bit9 */
			{ 7810,35,1}, /* core2 elr_EL3 bit10 */
			{ 7811,12,1}, /* core2 elr_EL3 bit11 */
			{ 2931,33,0}, /* core2 elr_EL3 bit12 */
			{ 2932,31,0}, /* core2 elr_EL3 bit13 */
			{ 2933,29,0}, /* core2 elr_EL3 bit14 */
			{ 2934,27,0}, /* core2 elr_EL3 bit15 */
			{ 5782,21,0}, /* core2 elr_EL3 bit16 */
			{ 5782,62,0}, /* core2 elr_EL3 bit17 */
			{ 5783,39,0}, /* core2 elr_EL3 bit18 */
			{ 5784,16,0}, /* core2 elr_EL3 bit19 */
			{ 5705,29,0}, /* core2 elr_EL3 bit20 */
			{ 5706, 6,0}, /* core2 elr_EL3 bit21 */
			{ 5706,47,0}, /* core2 elr_EL3 bit22 */
			{ 5707,24,0}, /* core2 elr_EL3 bit23 */
			{ 5736,13,0}, /* core2 elr_EL3 bit24 */
			{ 5736,54,0}, /* core2 elr_EL3 bit25 */
			{ 5737,31,0}, /* core2 elr_EL3 bit26 */
			{ 5738, 8,0}, /* core2 elr_EL3 bit27 */
			{ 5649, 5,0}, /* core2 elr_EL3 bit28 */
			{ 5649,46,0}, /* core2 elr_EL3 bit29 */
			{ 5650,23,0}, /* core2 elr_EL3 bit30 */
			{ 5651, 0,0}, /* core2 elr_EL3 bit31 */
			{ 5508, 9,0}, /* core2 elr_EL3 bit32 */
			{ 5508,50,0}, /* core2 elr_EL3 bit33 */
			{ 5509,27,0}, /* core2 elr_EL3 bit34 */
			{ 5510, 4,0}, /* core2 elr_EL3 bit35 */
			{ 5536,21,0}, /* core2 elr_EL3 bit36 */
			{ 5536,62,0}, /* core2 elr_EL3 bit37 */
			{ 5537,39,0}, /* core2 elr_EL3 bit38 */
			{ 5538,16,0}, /* core2 elr_EL3 bit39 */
			{ 5592,45,0}, /* core2 elr_EL3 bit40 */
			{ 5593,22,0}, /* core2 elr_EL3 bit41 */
			{ 5593,63,0}, /* core2 elr_EL3 bit42 */
			{ 5594,40,0}, /* core2 elr_EL3 bit43 */
			{ 5595,17,0}, /* core2 elr_EL3 bit44 */
			{ 5595,58,0}, /* core2 elr_EL3 bit45 */
			{ 5596,35,0}, /* core2 elr_EL3 bit46 */
			{ 5597,12,0}, /* core2 elr_EL3 bit47 */
			{ 5587,37,0}, /* core2 elr_EL3 bit48 */
			{ 5588,14,0}, /* core2 elr_EL3 bit49 */
			{ 5588,55,0}, /* core2 elr_EL3 bit50 */
			{ 5589,32,0}, /* core2 elr_EL3 bit51 */
			{ 5538,57,0}, /* core2 elr_EL3 bit52 */
			{ 5539,34,0}, /* core2 elr_EL3 bit53 */
			{ 5540,11,0}, /* core2 elr_EL3 bit54 */
			{ 5540,52,0}, /* core2 elr_EL3 bit55 */
			{ 5613,13,0}, /* core2 elr_EL3 bit56 */
			{ 5613,54,0}, /* core2 elr_EL3 bit57 */
			{ 5614,31,0}, /* core2 elr_EL3 bit58 */
			{ 5615, 8,0}, /* core2 elr_EL3 bit59 */
			{ 5510,45,0}, /* core2 elr_EL3 bit60 */
			{ 5511,22,0}, /* core2 elr_EL3 bit61 */
			{ 5511,63,0}, /* core2 elr_EL3 bit62 */
			{ 5512,40,0}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 7534,28,1}, /* core2 raw_pc bit0 */
			{ 9652,16,0}, /* core2 raw_pc bit1 */
			{ 9652,50,0}, /* core2 raw_pc bit2 */
			{ 4204,29,0}, /* core2 raw_pc bit3 */
			{ 4205,27,0}, /* core2 raw_pc bit4 */
			{ 4206,25,0}, /* core2 raw_pc bit5 */
			{ 4207,23,0}, /* core2 raw_pc bit6 */
			{ 1962,49,0}, /* core2 raw_pc bit7 */
			{ 1963,47,0}, /* core2 raw_pc bit8 */
			{ 1964,45,0}, /* core2 raw_pc bit9 */
			{ 1965,43,0}, /* core2 raw_pc bit10 */
			{ 1970,33,0}, /* core2 raw_pc bit11 */
			{ 1971,31,0}, /* core2 raw_pc bit12 */
			{ 1972,29,0}, /* core2 raw_pc bit13 */
			{ 1973,27,0}, /* core2 raw_pc bit14 */
			{ 1982, 9,0}, /* core2 raw_pc bit15 */
			{ 1983, 7,0}, /* core2 raw_pc bit16 */
			{ 1984, 5,0}, /* core2 raw_pc bit17 */
			{ 1985, 3,0}, /* core2 raw_pc bit18 */
			{ 1966,41,0}, /* core2 raw_pc bit19 */
			{ 1967,39,0}, /* core2 raw_pc bit20 */
			{ 1968,37,0}, /* core2 raw_pc bit21 */
			{ 1969,35,0}, /* core2 raw_pc bit22 */
			{ 1989,57,0}, /* core2 raw_pc bit23 */
			{ 1990,55,0}, /* core2 raw_pc bit24 */
			{ 1991,53,0}, /* core2 raw_pc bit25 */
			{ 1992,51,0}, /* core2 raw_pc bit26 */
			{ 1939,33,0}, /* core2 raw_pc bit27 */
			{ 1940,31,0}, /* core2 raw_pc bit28 */
			{ 1941,29,0}, /* core2 raw_pc bit29 */
			{ 1942,27,0}, /* core2 raw_pc bit30 */
			{  219, 0,0}, /* core2 raw_pc bit31 */
			{ 1943,25,0}, /* core2 raw_pc bit32 */
			{ 1944,23,0}, /* core2 raw_pc bit33 */
			{ 1945,21,0}, /* core2 raw_pc bit34 */
			{ 1946,19,0}, /* core2 raw_pc bit35 */
			{ 1931,49,0}, /* core2 raw_pc bit36 */
			{ 1932,47,0}, /* core2 raw_pc bit37 */
			{ 1933,45,0}, /* core2 raw_pc bit38 */
			{ 1934,43,0}, /* core2 raw_pc bit39 */
			{ 1935,41,0}, /* core2 raw_pc bit40 */
			{ 1936,39,0}, /* core2 raw_pc bit41 */
			{ 1937,37,0}, /* core2 raw_pc bit42 */
			{ 1938,35,0}, /* core2 raw_pc bit43 */
			{ 1927,57,0}, /* core2 raw_pc bit44 */
			{ 1928,55,0}, /* core2 raw_pc bit45 */
			{ 1929,53,0}, /* core2 raw_pc bit46 */
			{ 1930,51,0}, /* core2 raw_pc bit47 */
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
			{ 4531,57,0}, /* core2 pc_iss bit0 */
			{ 4528,63,0}, /* core2 pc_iss bit1 */
			{ 4453,27,0}, /* core2 pc_iss bit2 */
			{ 4528, 1,0}, /* core2 pc_iss bit3 */
			{ 4454,25,0}, /* core2 pc_iss bit4 */
			{ 4525, 7,0}, /* core2 pc_iss bit5 */
			{ 4529,61,0}, /* core2 pc_iss bit6 */
			{ 4527, 3,0}, /* core2 pc_iss bit7 */
			{ 4457,19,0}, /* core2 pc_iss bit8 */
			{ 4533,53,0}, /* core2 pc_iss bit9 */
			{ 4532,55,0}, /* core2 pc_iss bit10 */
			{ 4536,47,0}, /* core2 pc_iss bit11 */
			{ 4458,17,0}, /* core2 pc_iss bit12 */
			{ 4534,51,0}, /* core2 pc_iss bit13 */
			{ 4535,49,0}, /* core2 pc_iss bit14 */
			{ 4537,45,0}, /* core2 pc_iss bit15 */
			{ 4541,37,0}, /* core2 pc_iss bit16 */
			{ 4539,41,0}, /* core2 pc_iss bit17 */
			{ 4538,43,0}, /* core2 pc_iss bit18 */
			{ 4543,33,0}, /* core2 pc_iss bit19 */
			{ 4540,39,0}, /* core2 pc_iss bit20 */
			{ 4545,29,0}, /* core2 pc_iss bit21 */
			{ 4542,35,0}, /* core2 pc_iss bit22 */
			{ 9565, 8,0}, /* core2 pc_iss bit23 */
			{ 4460,13,0}, /* core2 pc_iss bit24 */
			{ 4544,31,0}, /* core2 pc_iss bit25 */
			{ 4546,27,0}, /* core2 pc_iss bit26 */
			{ 4461,11,0}, /* core2 pc_iss bit27 */
			{ 4459,15,0}, /* core2 pc_iss bit28 */
			{ 4462, 9,0}, /* core2 pc_iss bit29 */
			{ 9566,46,0}, /* core2 pc_iss bit30 */
			{ 9567,16,0}, /* core2 pc_iss bit31 */
			{ 9655,62,0}, /* core2 pc_iss bit32 */
			{ 9656,32,0}, /* core2 pc_iss bit33 */
			{ 4208,21,0}, /* core2 pc_iss bit34 */
			{ 4209,19,0}, /* core2 pc_iss bit35 */
			{ 4210,17,0}, /* core2 pc_iss bit36 */
			{ 4211,15,0}, /* core2 pc_iss bit37 */
			{ 4212,13,0}, /* core2 pc_iss bit38 */
			{ 4213,11,0}, /* core2 pc_iss bit39 */
			{ 4214, 9,0}, /* core2 pc_iss bit40 */
			{ 4215, 7,0}, /* core2 pc_iss bit41 */
			{ 4216, 5,0}, /* core2 pc_iss bit42 */
			{ 4217, 3,0}, /* core2 pc_iss bit43 */
			{ 4218, 1,0}, /* core2 pc_iss bit44 */
			{ 4218,63,0}, /* core2 pc_iss bit45 */
			{ 9658,40,0}, /* core2 pc_iss bit46 */
			{ 9658, 6,0}, /* core2 pc_iss bit47 */
			{ 9659,44,0}, /* core2 pc_iss bit48 */
			{ 9659,10,0}, /* core2 pc_iss bit49 */
			{ 9664,30,0}, /* core2 pc_iss bit50 */
			{ 9663,60,0}, /* core2 pc_iss bit51 */
			{ 9566,12,0}, /* core2 pc_iss bit52 */
			{ 9565,42,0}, /* core2 pc_iss bit53 */
			{ 4222,55,0}, /* core2 pc_iss bit54 */
			{ 4221,57,0}, /* core2 pc_iss bit55 */
			{ 4220,59,0}, /* core2 pc_iss bit56 */
			{ 4219,61,0}, /* core2 pc_iss bit57 */
			{ 9662,22,0}, /* core2 pc_iss bit58 */
			{ 9661,52,0}, /* core2 pc_iss bit59 */
			{ 9661,18,0}, /* core2 pc_iss bit60 */
			{ 9660,48,0}, /* core2 pc_iss bit61 */
			{ 9663,26,0}, /* core2 pc_iss bit62 */
			{ 9662,56,0}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 7533,51,1}, /* core2 full_pc_wr bit0 */
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
			{ 4472,51,0}, /* core2 full_pc_ex1 bit0 */
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
			{ 4469,57,0}, /* core2 full_pc_ex2 bit0 */
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
			{ 9802,40,0}, /* core3 pc bit0 */
			{ 9803,10,0}, /* core3 pc bit1 */
			{ 9803,44,0}, /* core3 pc bit2 */
			{ 9804,14,0}, /* core3 pc bit3 */
			{ 9783,32,0}, /* core3 pc bit4 */
			{ 9784, 2,0}, /* core3 pc bit5 */
			{ 9784,36,0}, /* core3 pc bit6 */
			{ 9785, 6,0}, /* core3 pc bit7 */
			{ 9804,48,0}, /* core3 pc bit8 */
			{ 9805,18,0}, /* core3 pc bit9 */
			{ 9805,52,0}, /* core3 pc bit10 */
			{ 9806,22,0}, /* core3 pc bit11 */
			{ 9787,48,0}, /* core3 pc bit12 */
			{ 9788,18,0}, /* core3 pc bit13 */
			{ 9788,52,0}, /* core3 pc bit14 */
			{ 9789,22,0}, /* core3 pc bit15 */
			{ 9800,32,0}, /* core3 pc bit16 */
			{ 9801, 2,0}, /* core3 pc bit17 */
			{ 9801,36,0}, /* core3 pc bit18 */
			{ 9802, 6,0}, /* core3 pc bit19 */
			{ 2319,19,0}, /* core3 pc bit20 */
			{ 2320,17,0}, /* core3 pc bit21 */
			{ 2321,15,0}, /* core3 pc bit22 */
			{ 2322,13,0}, /* core3 pc bit23 */
			{ 2315,27,0}, /* core3 pc bit24 */
			{ 2316,25,0}, /* core3 pc bit25 */
			{ 2317,23,0}, /* core3 pc bit26 */
			{ 2318,21,0}, /* core3 pc bit27 */
			{ 2299,59,0}, /* core3 pc bit28 */
			{ 2300,57,0}, /* core3 pc bit29 */
			{ 2301,55,0}, /* core3 pc bit30 */
			{ 2302,53,0}, /* core3 pc bit31 */
			{ 9796,16,0}, /* core3 pc bit32 */
			{ 9796,50,0}, /* core3 pc bit33 */
			{ 9797,20,0}, /* core3 pc bit34 */
			{ 9797,54,0}, /* core3 pc bit35 */
			{   12,44,0}, /* core3 pc bit36 */
			{   13,42,0}, /* core3 pc bit37 */
			{   14,40,0}, /* core3 pc bit38 */
			{   15,38,0}, /* core3 pc bit39 */
			{ 9798,24,0}, /* core3 pc bit40 */
			{ 9798,58,0}, /* core3 pc bit41 */
			{ 9799,28,0}, /* core3 pc bit42 */
			{ 9799,62,0}, /* core3 pc bit43 */
			{   16,36,0}, /* core3 pc bit44 */
			{   17,34,0}, /* core3 pc bit45 */
			{   18,32,0}, /* core3 pc bit46 */
			{   19,30,0}, /* core3 pc bit47 */
			{ 9794, 8,0}, /* core3 pc bit48 */
			{ 9794,42,0}, /* core3 pc bit49 */
			{ 9795,12,0}, /* core3 pc bit50 */
			{ 9795,46,0}, /* core3 pc bit51 */
			{ 9785,40,0}, /* core3 pc bit52 */
			{ 9786,10,0}, /* core3 pc bit53 */
			{ 9786,44,0}, /* core3 pc bit54 */
			{ 9787,14,0}, /* core3 pc bit55 */
			{ 2989,43,0}, /* core3 pc bit56 */
			{ 2990,41,0}, /* core3 pc bit57 */
			{ 2991,39,0}, /* core3 pc bit58 */
			{ 2992,37,0}, /* core3 pc bit59 */
			{   20,28,0}, /* core3 pc bit60 */
			{   21,26,0}, /* core3 pc bit61 */
			{   22,24,0}, /* core3 pc bit62 */
			{   23,22,0}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{ 5777,15,0}, /* core3 sp32 bit0 */
			{ 5777,56,0}, /* core3 sp32 bit1 */
			{ 5778,33,0}, /* core3 sp32 bit2 */
			{ 5779,10,0}, /* core3 sp32 bit3 */
			{ 5633,47,0}, /* core3 sp32 bit4 */
			{ 5634,24,0}, /* core3 sp32 bit5 */
			{ 5635, 1,0}, /* core3 sp32 bit6 */
			{ 5635,42,0}, /* core3 sp32 bit7 */
			{ 2017, 3,0}, /* core3 sp32 bit8 */
			{ 2018, 1,0}, /* core3 sp32 bit9 */
			{ 2018,63,0}, /* core3 sp32 bit10 */
			{ 2019,61,0}, /* core3 sp32 bit11 */
			{ 5656,51,0}, /* core3 sp32 bit12 */
			{ 5657,28,0}, /* core3 sp32 bit13 */
			{ 5658, 5,0}, /* core3 sp32 bit14 */
			{ 5658,46,0}, /* core3 sp32 bit15 */
			{ 5774,43,0}, /* core3 sp32 bit16 */
			{ 5775,20,0}, /* core3 sp32 bit17 */
			{ 5775,61,0}, /* core3 sp32 bit18 */
			{ 5776,38,0}, /* core3 sp32 bit19 */
			{ 5769,35,0}, /* core3 sp32 bit20 */
			{ 5770,12,0}, /* core3 sp32 bit21 */
			{ 5770,53,0}, /* core3 sp32 bit22 */
			{ 5771,30,0}, /* core3 sp32 bit23 */
			{ 5749, 3,0}, /* core3 sp32 bit24 */
			{ 5749,44,0}, /* core3 sp32 bit25 */
			{ 5750,21,0}, /* core3 sp32 bit26 */
			{ 5750,62,0}, /* core3 sp32 bit27 */
			{ 5654,15,0}, /* core3 sp32 bit28 */
			{ 5654,56,0}, /* core3 sp32 bit29 */
			{ 5655,33,0}, /* core3 sp32 bit30 */
			{ 5656,10,0}, /* core3 sp32 bit31 */
			{ 5203,15,0}, /* core3 sp32 bit32 */
			{ 5203,56,0}, /* core3 sp32 bit33 */
			{ 5204,33,0}, /* core3 sp32 bit34 */
			{ 5205,10,0}, /* core3 sp32 bit35 */
			{ 5356,63,0}, /* core3 sp32 bit36 */
			{ 5357,40,0}, /* core3 sp32 bit37 */
			{ 5358,17,0}, /* core3 sp32 bit38 */
			{ 5358,58,0}, /* core3 sp32 bit39 */
			{ 5133,26,0}, /* core3 sp32 bit40 */
			{ 5134, 3,0}, /* core3 sp32 bit41 */
			{ 5134,44,0}, /* core3 sp32 bit42 */
			{ 5135,21,0}, /* core3 sp32 bit43 */
			{ 5123,10,0}, /* core3 sp32 bit44 */
			{ 5123,51,0}, /* core3 sp32 bit45 */
			{ 5124,28,0}, /* core3 sp32 bit46 */
			{ 5125, 5,0}, /* core3 sp32 bit47 */
			{ 5125,46,0}, /* core3 sp32 bit48 */
			{ 5126,23,0}, /* core3 sp32 bit49 */
			{ 5127, 0,0}, /* core3 sp32 bit50 */
			{ 5127,41,0}, /* core3 sp32 bit51 */
			{ 5387,47,0}, /* core3 sp32 bit52 */
			{ 5388,24,0}, /* core3 sp32 bit53 */
			{ 5389, 1,0}, /* core3 sp32 bit54 */
			{ 5389,42,0}, /* core3 sp32 bit55 */
			{ 5390,19,0}, /* core3 sp32 bit56 */
			{ 5390,60,0}, /* core3 sp32 bit57 */
			{ 5391,37,0}, /* core3 sp32 bit58 */
			{ 5392,14,0}, /* core3 sp32 bit59 */
			{ 5392,55,0}, /* core3 sp32 bit60 */
			{ 5393,32,0}, /* core3 sp32 bit61 */
			{ 5394, 9,0}, /* core3 sp32 bit62 */
			{ 5394,50,0}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{ 6107,51,0}, /* core3 fp32 bit0 */
			{ 6108,28,0}, /* core3 fp32 bit1 */
			{ 6109, 5,0}, /* core3 fp32 bit2 */
			{ 6109,46,0}, /* core3 fp32 bit3 */
			{ 6343,35,0}, /* core3 fp32 bit4 */
			{ 6344,12,0}, /* core3 fp32 bit5 */
			{ 6344,53,0}, /* core3 fp32 bit6 */
			{ 6345,30,0}, /* core3 fp32 bit7 */
			{ 1013,27,1}, /* core3 fp32 bit8 */
			{ 1014,25,1}, /* core3 fp32 bit9 */
			{ 1015,23,1}, /* core3 fp32 bit10 */
			{ 1016,21,1}, /* core3 fp32 bit11 */
			{ 6340,63,0}, /* core3 fp32 bit12 */
			{ 6341,40,0}, /* core3 fp32 bit13 */
			{ 6342,17,0}, /* core3 fp32 bit14 */
			{ 6342,58,0}, /* core3 fp32 bit15 */
			{ 6079,39,0}, /* core3 fp32 bit16 */
			{ 6080,16,0}, /* core3 fp32 bit17 */
			{ 6080,57,0}, /* core3 fp32 bit18 */
			{ 6081,34,0}, /* core3 fp32 bit19 */
			{ 5951,31,0}, /* core3 fp32 bit20 */
			{ 5952, 8,0}, /* core3 fp32 bit21 */
			{ 5952,49,0}, /* core3 fp32 bit22 */
			{ 5953,26,0}, /* core3 fp32 bit23 */
			{ 6182, 7,0}, /* core3 fp32 bit24 */
			{ 6182,48,0}, /* core3 fp32 bit25 */
			{ 6183,25,0}, /* core3 fp32 bit26 */
			{ 6184, 2,0}, /* core3 fp32 bit27 */
			{ 5841,19,0}, /* core3 fp32 bit28 */
			{ 5841,60,0}, /* core3 fp32 bit29 */
			{ 5842,37,0}, /* core3 fp32 bit30 */
			{ 5843,14,0}, /* core3 fp32 bit31 */
			{ 5198, 7,0}, /* core3 fp32 bit32 */
			{ 5198,48,0}, /* core3 fp32 bit33 */
			{ 5199,25,0}, /* core3 fp32 bit34 */
			{ 5200, 2,0}, /* core3 fp32 bit35 */
			{ 5195,35,0}, /* core3 fp32 bit36 */
			{ 5196,12,0}, /* core3 fp32 bit37 */
			{ 5196,53,0}, /* core3 fp32 bit38 */
			{ 5197,30,0}, /* core3 fp32 bit39 */
			{ 5135,62,0}, /* core3 fp32 bit40 */
			{ 5136,39,0}, /* core3 fp32 bit41 */
			{ 5137,16,0}, /* core3 fp32 bit42 */
			{ 5137,57,0}, /* core3 fp32 bit43 */
			{ 5141, 6,0}, /* core3 fp32 bit44 */
			{ 5141,47,0}, /* core3 fp32 bit45 */
			{ 5142,24,0}, /* core3 fp32 bit46 */
			{ 5143, 1,0}, /* core3 fp32 bit47 */
			{ 5128,18,0}, /* core3 fp32 bit48 */
			{ 5128,59,0}, /* core3 fp32 bit49 */
			{ 5129,36,0}, /* core3 fp32 bit50 */
			{ 5130,13,0}, /* core3 fp32 bit51 */
			{ 5421, 3,0}, /* core3 fp32 bit52 */
			{ 5421,44,0}, /* core3 fp32 bit53 */
			{ 5422,21,0}, /* core3 fp32 bit54 */
			{ 5422,62,0}, /* core3 fp32 bit55 */
			{ 5418,31,0}, /* core3 fp32 bit56 */
			{ 5419, 8,0}, /* core3 fp32 bit57 */
			{ 5419,49,0}, /* core3 fp32 bit58 */
			{ 5420,26,0}, /* core3 fp32 bit59 */
			{ 5200,43,0}, /* core3 fp32 bit60 */
			{ 5201,20,0}, /* core3 fp32 bit61 */
			{ 5201,61,0}, /* core3 fp32 bit62 */
			{ 5202,38,0}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{ 2024,51,0}, /* core3 fp64 bit0 */
			{ 2025,49,0}, /* core3 fp64 bit1 */
			{ 2026,47,0}, /* core3 fp64 bit2 */
			{ 2027,45,0}, /* core3 fp64 bit3 */
			{ 5643,63,0}, /* core3 fp64 bit4 */
			{ 5644,40,0}, /* core3 fp64 bit5 */
			{ 5645,17,0}, /* core3 fp64 bit6 */
			{ 5645,58,0}, /* core3 fp64 bit7 */
			{   28,12,0}, /* core3 fp64 bit8 */
			{   29,10,0}, /* core3 fp64 bit9 */
			{   30, 8,0}, /* core3 fp64 bit10 */
			{   31, 6,0}, /* core3 fp64 bit11 */
			{ 5646,35,0}, /* core3 fp64 bit12 */
			{ 5647,12,0}, /* core3 fp64 bit13 */
			{ 5647,53,0}, /* core3 fp64 bit14 */
			{ 5648,30,0}, /* core3 fp64 bit15 */
			{ 5772, 7,0}, /* core3 fp64 bit16 */
			{ 5772,48,0}, /* core3 fp64 bit17 */
			{ 5773,25,0}, /* core3 fp64 bit18 */
			{ 5774, 2,0}, /* core3 fp64 bit19 */
			{ 5756,47,0}, /* core3 fp64 bit20 */
			{ 5757,24,0}, /* core3 fp64 bit21 */
			{ 5758, 1,0}, /* core3 fp64 bit22 */
			{ 5758,42,0}, /* core3 fp64 bit23 */
			{ 5692,43,0}, /* core3 fp64 bit24 */
			{ 5693,20,0}, /* core3 fp64 bit25 */
			{ 5693,61,0}, /* core3 fp64 bit26 */
			{ 5694,38,0}, /* core3 fp64 bit27 */
			{ 5746,31,0}, /* core3 fp64 bit28 */
			{ 5747, 8,0}, /* core3 fp64 bit29 */
			{ 5747,49,0}, /* core3 fp64 bit30 */
			{ 5748,26,0}, /* core3 fp64 bit31 */
			{ 5528,43,0}, /* core3 fp64 bit32 */
			{ 5529,20,0}, /* core3 fp64 bit33 */
			{ 5529,61,0}, /* core3 fp64 bit34 */
			{ 5530,38,0}, /* core3 fp64 bit35 */
			{ 5544, 3,0}, /* core3 fp64 bit36 */
			{ 5544,44,0}, /* core3 fp64 bit37 */
			{ 5545,21,0}, /* core3 fp64 bit38 */
			{ 5545,62,0}, /* core3 fp64 bit39 */
			{ 5533,51,0}, /* core3 fp64 bit40 */
			{ 5534,28,0}, /* core3 fp64 bit41 */
			{ 5535, 5,0}, /* core3 fp64 bit42 */
			{ 5535,46,0}, /* core3 fp64 bit43 */
			{ 5523,35,0}, /* core3 fp64 bit44 */
			{ 5524,12,0}, /* core3 fp64 bit45 */
			{ 5524,53,0}, /* core3 fp64 bit46 */
			{ 5525,30,0}, /* core3 fp64 bit47 */
			{ 5590,11,0}, /* core3 fp64 bit48 */
			{ 5590,52,0}, /* core3 fp64 bit49 */
			{ 5591,29,0}, /* core3 fp64 bit50 */
			{ 5592, 6,0}, /* core3 fp64 bit51 */
			{ 5541,31,0}, /* core3 fp64 bit52 */
			{ 5542, 8,0}, /* core3 fp64 bit53 */
			{ 5542,49,0}, /* core3 fp64 bit54 */
			{ 5543,26,0}, /* core3 fp64 bit55 */
			{ 5531,15,0}, /* core3 fp64 bit56 */
			{ 5531,56,0}, /* core3 fp64 bit57 */
			{ 5532,33,0}, /* core3 fp64 bit58 */
			{ 5533,10,0}, /* core3 fp64 bit59 */
			{ 5526, 7,0}, /* core3 fp64 bit60 */
			{ 5526,48,0}, /* core3 fp64 bit61 */
			{ 5527,25,0}, /* core3 fp64 bit62 */
			{ 5528, 2,0}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 7711,59,1}, /* core3 sp_EL0 bit0 */
			{ 7712,36,1}, /* core3 sp_EL0 bit1 */
			{ 7713,13,1}, /* core3 sp_EL0 bit2 */
			{ 7713,54,1}, /* core3 sp_EL0 bit3 */
			{ 6387, 7,0}, /* core3 sp_EL0 bit4 */
			{ 6387,48,0}, /* core3 sp_EL0 bit5 */
			{ 6388,25,0}, /* core3 sp_EL0 bit6 */
			{ 6389, 2,0}, /* core3 sp_EL0 bit7 */
			{ 6033,31,0}, /* core3 sp_EL0 bit8 */
			{ 6034, 8,0}, /* core3 sp_EL0 bit9 */
			{ 6034,49,0}, /* core3 sp_EL0 bit10 */
			{ 6035,26,0}, /* core3 sp_EL0 bit11 */
			{ 6381,63,0}, /* core3 sp_EL0 bit12 */
			{ 6382,40,0}, /* core3 sp_EL0 bit13 */
			{ 6383,17,0}, /* core3 sp_EL0 bit14 */
			{ 6383,58,0}, /* core3 sp_EL0 bit15 */
			{ 6043,47,0}, /* core3 sp_EL0 bit16 */
			{ 6044,24,0}, /* core3 sp_EL0 bit17 */
			{ 6045, 1,0}, /* core3 sp_EL0 bit18 */
			{ 6045,42,0}, /* core3 sp_EL0 bit19 */
			{ 5715,47,0}, /* core3 sp_EL0 bit20 */
			{ 5716,24,0}, /* core3 sp_EL0 bit21 */
			{ 5717, 1,0}, /* core3 sp_EL0 bit22 */
			{ 5717,42,0}, /* core3 sp_EL0 bit23 */
			{ 5725,63,0}, /* core3 sp_EL0 bit24 */
			{ 5726,40,0}, /* core3 sp_EL0 bit25 */
			{ 5727,17,0}, /* core3 sp_EL0 bit26 */
			{ 5727,58,0}, /* core3 sp_EL0 bit27 */
			{ 6415,19,0}, /* core3 sp_EL0 bit28 */
			{ 6415,60,0}, /* core3 sp_EL0 bit29 */
			{ 6416,37,0}, /* core3 sp_EL0 bit30 */
			{ 6417,14,0}, /* core3 sp_EL0 bit31 */
			{ 5244,15,0}, /* core3 sp_EL0 bit32 */
			{ 5244,56,0}, /* core3 sp_EL0 bit33 */
			{ 5245,33,0}, /* core3 sp_EL0 bit34 */
			{ 5246,10,0}, /* core3 sp_EL0 bit35 */
			{ 5236,35,0}, /* core3 sp_EL0 bit36 */
			{ 5237,12,0}, /* core3 sp_EL0 bit37 */
			{ 5237,53,0}, /* core3 sp_EL0 bit38 */
			{ 5238,30,0}, /* core3 sp_EL0 bit39 */
			{ 5231,27,0}, /* core3 sp_EL0 bit40 */
			{ 5232, 4,0}, /* core3 sp_EL0 bit41 */
			{ 5232,45,0}, /* core3 sp_EL0 bit42 */
			{ 5233,22,0}, /* core3 sp_EL0 bit43 */
			{ 5233,63,0}, /* core3 sp_EL0 bit44 */
			{ 5234,40,0}, /* core3 sp_EL0 bit45 */
			{ 5235,17,0}, /* core3 sp_EL0 bit46 */
			{ 5235,58,0}, /* core3 sp_EL0 bit47 */
			{ 5159,43,0}, /* core3 sp_EL0 bit48 */
			{ 5160,20,0}, /* core3 sp_EL0 bit49 */
			{ 5160,61,0}, /* core3 sp_EL0 bit50 */
			{ 5161,38,0}, /* core3 sp_EL0 bit51 */
			{ 5249,23,0}, /* core3 sp_EL0 bit52 */
			{ 5250, 0,0}, /* core3 sp_EL0 bit53 */
			{ 5250,41,0}, /* core3 sp_EL0 bit54 */
			{ 5251,18,0}, /* core3 sp_EL0 bit55 */
			{ 5274,63,0}, /* core3 sp_EL0 bit56 */
			{ 5275,40,0}, /* core3 sp_EL0 bit57 */
			{ 5276,17,0}, /* core3 sp_EL0 bit58 */
			{ 5276,58,0}, /* core3 sp_EL0 bit59 */
			{ 5285,15,0}, /* core3 sp_EL0 bit60 */
			{ 5285,56,0}, /* core3 sp_EL0 bit61 */
			{ 5286,33,0}, /* core3 sp_EL0 bit62 */
			{ 5287,10,0}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{10025,48,0}, /* core3 sp_EL1 bit0 */
			{10026,18,0}, /* core3 sp_EL1 bit1 */
			{10026,52,0}, /* core3 sp_EL1 bit2 */
			{10027,22,0}, /* core3 sp_EL1 bit3 */
			{ 2974,11,0}, /* core3 sp_EL1 bit4 */
			{ 2975, 9,0}, /* core3 sp_EL1 bit5 */
			{ 2976, 7,0}, /* core3 sp_EL1 bit6 */
			{ 2977, 5,0}, /* core3 sp_EL1 bit7 */
			{ 2020,59,0}, /* core3 sp_EL1 bit8 */
			{ 2021,57,0}, /* core3 sp_EL1 bit9 */
			{ 2022,55,0}, /* core3 sp_EL1 bit10 */
			{ 2023,53,0}, /* core3 sp_EL1 bit11 */
			{ 5672,11,0}, /* core3 sp_EL1 bit12 */
			{ 5672,52,0}, /* core3 sp_EL1 bit13 */
			{ 5673,29,0}, /* core3 sp_EL1 bit14 */
			{ 5674, 6,0}, /* core3 sp_EL1 bit15 */
			{ 5779,51,0}, /* core3 sp_EL1 bit16 */
			{ 5780,28,0}, /* core3 sp_EL1 bit17 */
			{ 5781, 5,0}, /* core3 sp_EL1 bit18 */
			{ 5781,46,0}, /* core3 sp_EL1 bit19 */
			{ 5761,55,0}, /* core3 sp_EL1 bit20 */
			{ 5762,32,0}, /* core3 sp_EL1 bit21 */
			{ 5763, 9,0}, /* core3 sp_EL1 bit22 */
			{ 5763,50,0}, /* core3 sp_EL1 bit23 */
			{ 5697,51,0}, /* core3 sp_EL1 bit24 */
			{ 5698,28,0}, /* core3 sp_EL1 bit25 */
			{ 5699, 5,0}, /* core3 sp_EL1 bit26 */
			{ 5699,46,0}, /* core3 sp_EL1 bit27 */
			{ 5674,47,0}, /* core3 sp_EL1 bit28 */
			{ 5675,24,0}, /* core3 sp_EL1 bit29 */
			{ 5676, 1,0}, /* core3 sp_EL1 bit30 */
			{ 5676,42,0}, /* core3 sp_EL1 bit31 */
			{ 5518,27,0}, /* core3 sp_EL1 bit32 */
			{ 5519, 4,0}, /* core3 sp_EL1 bit33 */
			{ 5519,45,0}, /* core3 sp_EL1 bit34 */
			{ 5520,22,0}, /* core3 sp_EL1 bit35 */
			{ 5551,47,0}, /* core3 sp_EL1 bit36 */
			{ 5552,24,0}, /* core3 sp_EL1 bit37 */
			{ 5553, 1,0}, /* core3 sp_EL1 bit38 */
			{ 5553,42,0}, /* core3 sp_EL1 bit39 */
			{ 5549,11,0}, /* core3 sp_EL1 bit40 */
			{ 5549,52,0}, /* core3 sp_EL1 bit41 */
			{ 5550,29,0}, /* core3 sp_EL1 bit42 */
			{ 5551, 6,0}, /* core3 sp_EL1 bit43 */
			{ 5561,63,0}, /* core3 sp_EL1 bit44 */
			{ 5562,40,0}, /* core3 sp_EL1 bit45 */
			{ 5563,17,0}, /* core3 sp_EL1 bit46 */
			{ 5563,58,0}, /* core3 sp_EL1 bit47 */
			{ 5554,19,0}, /* core3 sp_EL1 bit48 */
			{ 5554,60,0}, /* core3 sp_EL1 bit49 */
			{ 5555,37,0}, /* core3 sp_EL1 bit50 */
			{ 5556,14,0}, /* core3 sp_EL1 bit51 */
			{ 5559,27,0}, /* core3 sp_EL1 bit52 */
			{ 5560, 4,0}, /* core3 sp_EL1 bit53 */
			{ 5560,45,0}, /* core3 sp_EL1 bit54 */
			{ 5561,22,0}, /* core3 sp_EL1 bit55 */
			{ 5520,63,0}, /* core3 sp_EL1 bit56 */
			{ 5521,40,0}, /* core3 sp_EL1 bit57 */
			{ 5522,17,0}, /* core3 sp_EL1 bit58 */
			{ 5522,58,0}, /* core3 sp_EL1 bit59 */
			{ 5556,55,0}, /* core3 sp_EL1 bit60 */
			{ 5557,32,0}, /* core3 sp_EL1 bit61 */
			{ 5558, 9,0}, /* core3 sp_EL1 bit62 */
			{ 5558,50,0}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{10013, 0,0}, /* core3 sp_EL2 bit0 */
			{10013,34,0}, /* core3 sp_EL2 bit1 */
			{10014, 4,0}, /* core3 sp_EL2 bit2 */
			{10014,38,0}, /* core3 sp_EL2 bit3 */
			{ 2939,19,0}, /* core3 sp_EL2 bit4 */
			{ 2940,17,0}, /* core3 sp_EL2 bit5 */
			{ 2941,15,0}, /* core3 sp_EL2 bit6 */
			{ 2942,13,0}, /* core3 sp_EL2 bit7 */
			{10015, 8,0}, /* core3 sp_EL2 bit8 */
			{10015,42,0}, /* core3 sp_EL2 bit9 */
			{10016,12,0}, /* core3 sp_EL2 bit10 */
			{10016,46,0}, /* core3 sp_EL2 bit11 */
			{ 6430,43,0}, /* core3 sp_EL2 bit12 */
			{ 6431,20,0}, /* core3 sp_EL2 bit13 */
			{ 6431,61,0}, /* core3 sp_EL2 bit14 */
			{ 6432,38,0}, /* core3 sp_EL2 bit15 */
			{ 5784,59,0}, /* core3 sp_EL2 bit16 */
			{ 5785,36,0}, /* core3 sp_EL2 bit17 */
			{ 5786,13,0}, /* core3 sp_EL2 bit18 */
			{ 5786,54,0}, /* core3 sp_EL2 bit19 */
			{ 5708, 3,0}, /* core3 sp_EL2 bit20 */
			{ 5708,44,0}, /* core3 sp_EL2 bit21 */
			{ 5709,21,0}, /* core3 sp_EL2 bit22 */
			{ 5709,62,0}, /* core3 sp_EL2 bit23 */
			{ 5733,43,0}, /* core3 sp_EL2 bit24 */
			{ 5734,20,0}, /* core3 sp_EL2 bit25 */
			{ 5734,61,0}, /* core3 sp_EL2 bit26 */
			{ 5735,38,0}, /* core3 sp_EL2 bit27 */
			{ 2943,11,0}, /* core3 sp_EL2 bit28 */
			{ 2944, 9,0}, /* core3 sp_EL2 bit29 */
			{ 2945, 7,0}, /* core3 sp_EL2 bit30 */
			{ 2946, 5,0}, /* core3 sp_EL2 bit31 */
			{ 5620,59,0}, /* core3 sp_EL2 bit32 */
			{ 5621,36,0}, /* core3 sp_EL2 bit33 */
			{ 5622,13,0}, /* core3 sp_EL2 bit34 */
			{ 5622,54,0}, /* core3 sp_EL2 bit35 */
			{ 5608, 7,0}, /* core3 sp_EL2 bit36 */
			{ 5608,48,0}, /* core3 sp_EL2 bit37 */
			{ 5609,25,0}, /* core3 sp_EL2 bit38 */
			{ 5610, 2,0}, /* core3 sp_EL2 bit39 */
			{ 5605,35,0}, /* core3 sp_EL2 bit40 */
			{ 5606,12,0}, /* core3 sp_EL2 bit41 */
			{ 5606,53,0}, /* core3 sp_EL2 bit42 */
			{ 5607,30,0}, /* core3 sp_EL2 bit43 */
			{ 5597,55,0}, /* core3 sp_EL2 bit44 */
			{ 5598,32,0}, /* core3 sp_EL2 bit45 */
			{ 5599, 9,0}, /* core3 sp_EL2 bit46 */
			{ 5599,50,0}, /* core3 sp_EL2 bit47 */
			{ 5600,27,0}, /* core3 sp_EL2 bit48 */
			{ 5601, 4,0}, /* core3 sp_EL2 bit49 */
			{ 5601,45,0}, /* core3 sp_EL2 bit50 */
			{ 5602,22,0}, /* core3 sp_EL2 bit51 */
			{ 5610,43,0}, /* core3 sp_EL2 bit52 */
			{ 5611,20,0}, /* core3 sp_EL2 bit53 */
			{ 5611,61,0}, /* core3 sp_EL2 bit54 */
			{ 5612,38,0}, /* core3 sp_EL2 bit55 */
			{ 5615,51,0}, /* core3 sp_EL2 bit56 */
			{ 5616,28,0}, /* core3 sp_EL2 bit57 */
			{ 5617, 5,0}, /* core3 sp_EL2 bit58 */
			{ 5617,46,0}, /* core3 sp_EL2 bit59 */
			{ 5618,23,0}, /* core3 sp_EL2 bit60 */
			{ 5619, 0,0}, /* core3 sp_EL2 bit61 */
			{ 5619,41,0}, /* core3 sp_EL2 bit62 */
			{ 5620,18,0}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 7816,63,1}, /* core3 sp_EL3 bit0 */
			{ 7817,40,1}, /* core3 sp_EL3 bit1 */
			{ 7818,17,1}, /* core3 sp_EL3 bit2 */
			{ 7818,58,1}, /* core3 sp_EL3 bit3 */
			{ 5626, 3,0}, /* core3 sp_EL3 bit4 */
			{ 5626,44,0}, /* core3 sp_EL3 bit5 */
			{ 5627,21,0}, /* core3 sp_EL3 bit6 */
			{ 5627,62,0}, /* core3 sp_EL3 bit7 */
			{ 7811,55,1}, /* core3 sp_EL3 bit8 */
			{ 7812,32,1}, /* core3 sp_EL3 bit9 */
			{ 7813, 9,1}, /* core3 sp_EL3 bit10 */
			{ 7813,50,1}, /* core3 sp_EL3 bit11 */
			{ 5628,39,0}, /* core3 sp_EL3 bit12 */
			{ 5629,16,0}, /* core3 sp_EL3 bit13 */
			{ 5629,57,0}, /* core3 sp_EL3 bit14 */
			{ 5630,34,0}, /* core3 sp_EL3 bit15 */
			{ 5787,31,0}, /* core3 sp_EL3 bit16 */
			{ 5788, 8,0}, /* core3 sp_EL3 bit17 */
			{ 5788,49,0}, /* core3 sp_EL3 bit18 */
			{ 5789,26,0}, /* core3 sp_EL3 bit19 */
			{ 5710,39,0}, /* core3 sp_EL3 bit20 */
			{ 5711,16,0}, /* core3 sp_EL3 bit21 */
			{ 5711,57,0}, /* core3 sp_EL3 bit22 */
			{ 5712,34,0}, /* core3 sp_EL3 bit23 */
			{ 5731, 7,0}, /* core3 sp_EL3 bit24 */
			{ 5731,48,0}, /* core3 sp_EL3 bit25 */
			{ 5732,25,0}, /* core3 sp_EL3 bit26 */
			{ 5733, 2,0}, /* core3 sp_EL3 bit27 */
			{ 6455,42,0}, /* core3 sp_EL3 bit28 */
			{ 6456,19,0}, /* core3 sp_EL3 bit29 */
			{ 6456,60,0}, /* core3 sp_EL3 bit30 */
			{ 6457,37,0}, /* core3 sp_EL3 bit31 */
			{ 5213,31,0}, /* core3 sp_EL3 bit32 */
			{ 5214, 8,0}, /* core3 sp_EL3 bit33 */
			{ 5214,49,0}, /* core3 sp_EL3 bit34 */
			{ 5215,26,0}, /* core3 sp_EL3 bit35 */
			{ 4998,15,0}, /* core3 sp_EL3 bit36 */
			{ 4998,56,0}, /* core3 sp_EL3 bit37 */
			{ 4999,33,0}, /* core3 sp_EL3 bit38 */
			{ 5000,10,0}, /* core3 sp_EL3 bit39 */
			{ 5062,19,0}, /* core3 sp_EL3 bit40 */
			{ 5062,60,0}, /* core3 sp_EL3 bit41 */
			{ 5063,37,0}, /* core3 sp_EL3 bit42 */
			{ 5064,14,0}, /* core3 sp_EL3 bit43 */
			{ 5059,47,0}, /* core3 sp_EL3 bit44 */
			{ 5060,24,0}, /* core3 sp_EL3 bit45 */
			{ 5061, 1,0}, /* core3 sp_EL3 bit46 */
			{ 5061,42,0}, /* core3 sp_EL3 bit47 */
			{ 5057,11,0}, /* core3 sp_EL3 bit48 */
			{ 5057,52,0}, /* core3 sp_EL3 bit49 */
			{ 5058,29,0}, /* core3 sp_EL3 bit50 */
			{ 5059, 6,0}, /* core3 sp_EL3 bit51 */
			{ 5257, 3,0}, /* core3 sp_EL3 bit52 */
			{ 5257,44,0}, /* core3 sp_EL3 bit53 */
			{ 5258,21,0}, /* core3 sp_EL3 bit54 */
			{ 5258,62,0}, /* core3 sp_EL3 bit55 */
			{ 5259,39,0}, /* core3 sp_EL3 bit56 */
			{ 5260,16,0}, /* core3 sp_EL3 bit57 */
			{ 5260,57,0}, /* core3 sp_EL3 bit58 */
			{ 5261,34,0}, /* core3 sp_EL3 bit59 */
			{ 5262,11,0}, /* core3 sp_EL3 bit60 */
			{ 5262,52,0}, /* core3 sp_EL3 bit61 */
			{ 5263,29,0}, /* core3 sp_EL3 bit62 */
			{ 5264, 6,0}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{ 7814,27,1}, /* core3 elr_EL1 bit0 */
			{ 7815, 4,1}, /* core3 elr_EL1 bit1 */
			{ 7815,45,1}, /* core3 elr_EL1 bit2 */
			{ 7816,22,1}, /* core3 elr_EL1 bit3 */
			{ 6379,27,0}, /* core3 elr_EL1 bit4 */
			{ 6380, 4,0}, /* core3 elr_EL1 bit5 */
			{ 6380,45,0}, /* core3 elr_EL1 bit6 */
			{ 6381,22,0}, /* core3 elr_EL1 bit7 */
			{ 6030,59,0}, /* core3 elr_EL1 bit8 */
			{ 6031,36,0}, /* core3 elr_EL1 bit9 */
			{ 6032,13,0}, /* core3 elr_EL1 bit10 */
			{ 6032,54,0}, /* core3 elr_EL1 bit11 */
			{ 6384,35,0}, /* core3 elr_EL1 bit12 */
			{ 6385,12,0}, /* core3 elr_EL1 bit13 */
			{ 6385,53,0}, /* core3 elr_EL1 bit14 */
			{ 6386,30,0}, /* core3 elr_EL1 bit15 */
			{ 7804,11,1}, /* core3 elr_EL1 bit16 */
			{ 7804,52,1}, /* core3 elr_EL1 bit17 */
			{ 7805,29,1}, /* core3 elr_EL1 bit18 */
			{ 7806, 6,1}, /* core3 elr_EL1 bit19 */
			{ 5713,11,0}, /* core3 elr_EL1 bit20 */
			{ 5713,52,0}, /* core3 elr_EL1 bit21 */
			{ 5714,29,0}, /* core3 elr_EL1 bit22 */
			{ 5715, 6,0}, /* core3 elr_EL1 bit23 */
			{ 5728,35,0}, /* core3 elr_EL1 bit24 */
			{ 5729,12,0}, /* core3 elr_EL1 bit25 */
			{ 5729,53,0}, /* core3 elr_EL1 bit26 */
			{ 5730,30,0}, /* core3 elr_EL1 bit27 */
			{ 6412,47,0}, /* core3 elr_EL1 bit28 */
			{ 6413,24,0}, /* core3 elr_EL1 bit29 */
			{ 6414, 1,0}, /* core3 elr_EL1 bit30 */
			{ 6414,42,0}, /* core3 elr_EL1 bit31 */
			{ 5216, 3,0}, /* core3 elr_EL1 bit32 */
			{ 5216,44,0}, /* core3 elr_EL1 bit33 */
			{ 5217,21,0}, /* core3 elr_EL1 bit34 */
			{ 5217,62,0}, /* core3 elr_EL1 bit35 */
			{ 5164,51,0}, /* core3 elr_EL1 bit36 */
			{ 5165,28,0}, /* core3 elr_EL1 bit37 */
			{ 5166, 5,0}, /* core3 elr_EL1 bit38 */
			{ 5166,46,0}, /* core3 elr_EL1 bit39 */
			{ 5167,23,0}, /* core3 elr_EL1 bit40 */
			{ 5168, 0,0}, /* core3 elr_EL1 bit41 */
			{ 5168,41,0}, /* core3 elr_EL1 bit42 */
			{ 5169,18,0}, /* core3 elr_EL1 bit43 */
			{ 5169,59,0}, /* core3 elr_EL1 bit44 */
			{ 5170,36,0}, /* core3 elr_EL1 bit45 */
			{ 5171,13,0}, /* core3 elr_EL1 bit46 */
			{ 5171,54,0}, /* core3 elr_EL1 bit47 */
			{ 5172,31,0}, /* core3 elr_EL1 bit48 */
			{ 5173, 8,0}, /* core3 elr_EL1 bit49 */
			{ 5173,49,0}, /* core3 elr_EL1 bit50 */
			{ 5174,26,0}, /* core3 elr_EL1 bit51 */
			{ 5254,31,0}, /* core3 elr_EL1 bit52 */
			{ 5255, 8,0}, /* core3 elr_EL1 bit53 */
			{ 5255,49,0}, /* core3 elr_EL1 bit54 */
			{ 5256,26,0}, /* core3 elr_EL1 bit55 */
			{ 5269,55,0}, /* core3 elr_EL1 bit56 */
			{ 5270,32,0}, /* core3 elr_EL1 bit57 */
			{ 5271, 9,0}, /* core3 elr_EL1 bit58 */
			{ 5271,50,0}, /* core3 elr_EL1 bit59 */
			{ 5264,47,0}, /* core3 elr_EL1 bit60 */
			{ 5265,24,0}, /* core3 elr_EL1 bit61 */
			{ 5266, 1,0}, /* core3 elr_EL1 bit62 */
			{ 5266,42,0}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{ 6015,35,0}, /* core3 elr_EL2 bit0 */
			{ 6016,12,0}, /* core3 elr_EL2 bit1 */
			{ 6016,53,0}, /* core3 elr_EL2 bit2 */
			{ 6017,30,0}, /* core3 elr_EL2 bit3 */
			{ 6371,47,0}, /* core3 elr_EL2 bit4 */
			{ 6372,24,0}, /* core3 elr_EL2 bit5 */
			{ 6373, 1,0}, /* core3 elr_EL2 bit6 */
			{ 6373,42,0}, /* core3 elr_EL2 bit7 */
			{ 6094,63,0}, /* core3 elr_EL2 bit8 */
			{ 6095,40,0}, /* core3 elr_EL2 bit9 */
			{ 6096,17,0}, /* core3 elr_EL2 bit10 */
			{ 6096,58,0}, /* core3 elr_EL2 bit11 */
			{ 6374,19,0}, /* core3 elr_EL2 bit12 */
			{ 6374,60,0}, /* core3 elr_EL2 bit13 */
			{ 6375,37,0}, /* core3 elr_EL2 bit14 */
			{ 6376,14,0}, /* core3 elr_EL2 bit15 */
			{ 6048,55,0}, /* core3 elr_EL2 bit16 */
			{ 6049,32,0}, /* core3 elr_EL2 bit17 */
			{ 6050, 9,0}, /* core3 elr_EL2 bit18 */
			{ 6050,50,0}, /* core3 elr_EL2 bit19 */
			{ 6056,35,0}, /* core3 elr_EL2 bit20 */
			{ 6057,12,0}, /* core3 elr_EL2 bit21 */
			{ 6057,53,0}, /* core3 elr_EL2 bit22 */
			{ 6058,30,0}, /* core3 elr_EL2 bit23 */
			{ 7793,59,1}, /* core3 elr_EL2 bit24 */
			{ 7794,36,1}, /* core3 elr_EL2 bit25 */
			{ 7795,13,1}, /* core3 elr_EL2 bit26 */
			{ 7795,54,1}, /* core3 elr_EL2 bit27 */
			{ 6407,39,0}, /* core3 elr_EL2 bit28 */
			{ 6408,16,0}, /* core3 elr_EL2 bit29 */
			{ 6408,57,0}, /* core3 elr_EL2 bit30 */
			{ 6409,34,0}, /* core3 elr_EL2 bit31 */
			{ 5246,51,0}, /* core3 elr_EL2 bit32 */
			{ 5247,28,0}, /* core3 elr_EL2 bit33 */
			{ 5248, 5,0}, /* core3 elr_EL2 bit34 */
			{ 5248,46,0}, /* core3 elr_EL2 bit35 */
			{ 5241,43,0}, /* core3 elr_EL2 bit36 */
			{ 5242,20,0}, /* core3 elr_EL2 bit37 */
			{ 5242,61,0}, /* core3 elr_EL2 bit38 */
			{ 5243,38,0}, /* core3 elr_EL2 bit39 */
			{ 5221,11,0}, /* core3 elr_EL2 bit40 */
			{ 5221,52,0}, /* core3 elr_EL2 bit41 */
			{ 5222,29,0}, /* core3 elr_EL2 bit42 */
			{ 5223, 6,0}, /* core3 elr_EL2 bit43 */
			{ 5239, 7,0}, /* core3 elr_EL2 bit44 */
			{ 5239,48,0}, /* core3 elr_EL2 bit45 */
			{ 5240,25,0}, /* core3 elr_EL2 bit46 */
			{ 5241, 2,0}, /* core3 elr_EL2 bit47 */
			{ 5223,47,0}, /* core3 elr_EL2 bit48 */
			{ 5224,24,0}, /* core3 elr_EL2 bit49 */
			{ 5225, 1,0}, /* core3 elr_EL2 bit50 */
			{ 5225,42,0}, /* core3 elr_EL2 bit51 */
			{ 5287,51,0}, /* core3 elr_EL2 bit52 */
			{ 5288,28,0}, /* core3 elr_EL2 bit53 */
			{ 5289, 5,0}, /* core3 elr_EL2 bit54 */
			{ 5289,46,0}, /* core3 elr_EL2 bit55 */
			{ 5282,43,0}, /* core3 elr_EL2 bit56 */
			{ 5283,20,0}, /* core3 elr_EL2 bit57 */
			{ 5283,61,0}, /* core3 elr_EL2 bit58 */
			{ 5284,38,0}, /* core3 elr_EL2 bit59 */
			{ 5579,59,0}, /* core3 elr_EL2 bit60 */
			{ 5580,36,0}, /* core3 elr_EL2 bit61 */
			{ 5581,13,0}, /* core3 elr_EL2 bit62 */
			{ 5581,54,0}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{10010,56,0}, /* core3 elr_EL3 bit0 */
			{10011,26,0}, /* core3 elr_EL3 bit1 */
			{10011,60,0}, /* core3 elr_EL3 bit2 */
			{10012,30,0}, /* core3 elr_EL3 bit3 */
			{ 2935,27,0}, /* core3 elr_EL3 bit4 */
			{ 2936,25,0}, /* core3 elr_EL3 bit5 */
			{ 2937,23,0}, /* core3 elr_EL3 bit6 */
			{ 2938,21,0}, /* core3 elr_EL3 bit7 */
			{ 7809,19,1}, /* core3 elr_EL3 bit8 */
			{ 7809,60,1}, /* core3 elr_EL3 bit9 */
			{ 7810,37,1}, /* core3 elr_EL3 bit10 */
			{ 7811,14,1}, /* core3 elr_EL3 bit11 */
			{ 2931,35,0}, /* core3 elr_EL3 bit12 */
			{ 2932,33,0}, /* core3 elr_EL3 bit13 */
			{ 2933,31,0}, /* core3 elr_EL3 bit14 */
			{ 2934,29,0}, /* core3 elr_EL3 bit15 */
			{ 5782,23,0}, /* core3 elr_EL3 bit16 */
			{ 5783, 0,0}, /* core3 elr_EL3 bit17 */
			{ 5783,41,0}, /* core3 elr_EL3 bit18 */
			{ 5784,18,0}, /* core3 elr_EL3 bit19 */
			{ 5705,31,0}, /* core3 elr_EL3 bit20 */
			{ 5706, 8,0}, /* core3 elr_EL3 bit21 */
			{ 5706,49,0}, /* core3 elr_EL3 bit22 */
			{ 5707,26,0}, /* core3 elr_EL3 bit23 */
			{ 5736,15,0}, /* core3 elr_EL3 bit24 */
			{ 5736,56,0}, /* core3 elr_EL3 bit25 */
			{ 5737,33,0}, /* core3 elr_EL3 bit26 */
			{ 5738,10,0}, /* core3 elr_EL3 bit27 */
			{ 5649, 7,0}, /* core3 elr_EL3 bit28 */
			{ 5649,48,0}, /* core3 elr_EL3 bit29 */
			{ 5650,25,0}, /* core3 elr_EL3 bit30 */
			{ 5651, 2,0}, /* core3 elr_EL3 bit31 */
			{ 5508,11,0}, /* core3 elr_EL3 bit32 */
			{ 5508,52,0}, /* core3 elr_EL3 bit33 */
			{ 5509,29,0}, /* core3 elr_EL3 bit34 */
			{ 5510, 6,0}, /* core3 elr_EL3 bit35 */
			{ 5536,23,0}, /* core3 elr_EL3 bit36 */
			{ 5537, 0,0}, /* core3 elr_EL3 bit37 */
			{ 5537,41,0}, /* core3 elr_EL3 bit38 */
			{ 5538,18,0}, /* core3 elr_EL3 bit39 */
			{ 5592,47,0}, /* core3 elr_EL3 bit40 */
			{ 5593,24,0}, /* core3 elr_EL3 bit41 */
			{ 5594, 1,0}, /* core3 elr_EL3 bit42 */
			{ 5594,42,0}, /* core3 elr_EL3 bit43 */
			{ 5595,19,0}, /* core3 elr_EL3 bit44 */
			{ 5595,60,0}, /* core3 elr_EL3 bit45 */
			{ 5596,37,0}, /* core3 elr_EL3 bit46 */
			{ 5597,14,0}, /* core3 elr_EL3 bit47 */
			{ 5587,39,0}, /* core3 elr_EL3 bit48 */
			{ 5588,16,0}, /* core3 elr_EL3 bit49 */
			{ 5588,57,0}, /* core3 elr_EL3 bit50 */
			{ 5589,34,0}, /* core3 elr_EL3 bit51 */
			{ 5538,59,0}, /* core3 elr_EL3 bit52 */
			{ 5539,36,0}, /* core3 elr_EL3 bit53 */
			{ 5540,13,0}, /* core3 elr_EL3 bit54 */
			{ 5540,54,0}, /* core3 elr_EL3 bit55 */
			{ 5613,15,0}, /* core3 elr_EL3 bit56 */
			{ 5613,56,0}, /* core3 elr_EL3 bit57 */
			{ 5614,33,0}, /* core3 elr_EL3 bit58 */
			{ 5615,10,0}, /* core3 elr_EL3 bit59 */
			{ 5510,47,0}, /* core3 elr_EL3 bit60 */
			{ 5511,24,0}, /* core3 elr_EL3 bit61 */
			{ 5512, 1,0}, /* core3 elr_EL3 bit62 */
			{ 5512,42,0}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{ 7534,30,1}, /* core3 raw_pc bit0 */
			{ 9652,18,0}, /* core3 raw_pc bit1 */
			{ 9652,52,0}, /* core3 raw_pc bit2 */
			{ 4204,31,0}, /* core3 raw_pc bit3 */
			{ 4205,29,0}, /* core3 raw_pc bit4 */
			{ 4206,27,0}, /* core3 raw_pc bit5 */
			{ 4207,25,0}, /* core3 raw_pc bit6 */
			{ 1962,51,0}, /* core3 raw_pc bit7 */
			{ 1963,49,0}, /* core3 raw_pc bit8 */
			{ 1964,47,0}, /* core3 raw_pc bit9 */
			{ 1965,45,0}, /* core3 raw_pc bit10 */
			{ 1970,35,0}, /* core3 raw_pc bit11 */
			{ 1971,33,0}, /* core3 raw_pc bit12 */
			{ 1972,31,0}, /* core3 raw_pc bit13 */
			{ 1973,29,0}, /* core3 raw_pc bit14 */
			{ 1982,11,0}, /* core3 raw_pc bit15 */
			{ 1983, 9,0}, /* core3 raw_pc bit16 */
			{ 1984, 7,0}, /* core3 raw_pc bit17 */
			{ 1985, 5,0}, /* core3 raw_pc bit18 */
			{ 1966,43,0}, /* core3 raw_pc bit19 */
			{ 1967,41,0}, /* core3 raw_pc bit20 */
			{ 1968,39,0}, /* core3 raw_pc bit21 */
			{ 1969,37,0}, /* core3 raw_pc bit22 */
			{ 1989,59,0}, /* core3 raw_pc bit23 */
			{ 1990,57,0}, /* core3 raw_pc bit24 */
			{ 1991,55,0}, /* core3 raw_pc bit25 */
			{ 1992,53,0}, /* core3 raw_pc bit26 */
			{ 1939,35,0}, /* core3 raw_pc bit27 */
			{ 1940,33,0}, /* core3 raw_pc bit28 */
			{ 1941,31,0}, /* core3 raw_pc bit29 */
			{ 1942,29,0}, /* core3 raw_pc bit30 */
			{  219, 2,0}, /* core3 raw_pc bit31 */
			{ 1943,27,0}, /* core3 raw_pc bit32 */
			{ 1944,25,0}, /* core3 raw_pc bit33 */
			{ 1945,23,0}, /* core3 raw_pc bit34 */
			{ 1946,21,0}, /* core3 raw_pc bit35 */
			{ 1931,51,0}, /* core3 raw_pc bit36 */
			{ 1932,49,0}, /* core3 raw_pc bit37 */
			{ 1933,47,0}, /* core3 raw_pc bit38 */
			{ 1934,45,0}, /* core3 raw_pc bit39 */
			{ 1935,43,0}, /* core3 raw_pc bit40 */
			{ 1936,41,0}, /* core3 raw_pc bit41 */
			{ 1937,39,0}, /* core3 raw_pc bit42 */
			{ 1938,37,0}, /* core3 raw_pc bit43 */
			{ 1927,59,0}, /* core3 raw_pc bit44 */
			{ 1928,57,0}, /* core3 raw_pc bit45 */
			{ 1929,55,0}, /* core3 raw_pc bit46 */
			{ 1930,53,0}, /* core3 raw_pc bit47 */
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
			{ 4531,59,0}, /* core3 pc_iss bit0 */
			{ 4529, 1,0}, /* core3 pc_iss bit1 */
			{ 4453,29,0}, /* core3 pc_iss bit2 */
			{ 4528, 3,0}, /* core3 pc_iss bit3 */
			{ 4454,27,0}, /* core3 pc_iss bit4 */
			{ 4525, 9,0}, /* core3 pc_iss bit5 */
			{ 4529,63,0}, /* core3 pc_iss bit6 */
			{ 4527, 5,0}, /* core3 pc_iss bit7 */
			{ 4457,21,0}, /* core3 pc_iss bit8 */
			{ 4533,55,0}, /* core3 pc_iss bit9 */
			{ 4532,57,0}, /* core3 pc_iss bit10 */
			{ 4536,49,0}, /* core3 pc_iss bit11 */
			{ 4458,19,0}, /* core3 pc_iss bit12 */
			{ 4534,53,0}, /* core3 pc_iss bit13 */
			{ 4535,51,0}, /* core3 pc_iss bit14 */
			{ 4537,47,0}, /* core3 pc_iss bit15 */
			{ 4541,39,0}, /* core3 pc_iss bit16 */
			{ 4539,43,0}, /* core3 pc_iss bit17 */
			{ 4538,45,0}, /* core3 pc_iss bit18 */
			{ 4543,35,0}, /* core3 pc_iss bit19 */
			{ 4540,41,0}, /* core3 pc_iss bit20 */
			{ 4545,31,0}, /* core3 pc_iss bit21 */
			{ 4542,37,0}, /* core3 pc_iss bit22 */
			{ 9565,10,0}, /* core3 pc_iss bit23 */
			{ 4460,15,0}, /* core3 pc_iss bit24 */
			{ 4544,33,0}, /* core3 pc_iss bit25 */
			{ 4546,29,0}, /* core3 pc_iss bit26 */
			{ 4461,13,0}, /* core3 pc_iss bit27 */
			{ 4459,17,0}, /* core3 pc_iss bit28 */
			{ 4462,11,0}, /* core3 pc_iss bit29 */
			{ 9566,48,0}, /* core3 pc_iss bit30 */
			{ 9567,18,0}, /* core3 pc_iss bit31 */
			{ 9656, 0,0}, /* core3 pc_iss bit32 */
			{ 9656,34,0}, /* core3 pc_iss bit33 */
			{ 4208,23,0}, /* core3 pc_iss bit34 */
			{ 4209,21,0}, /* core3 pc_iss bit35 */
			{ 4210,19,0}, /* core3 pc_iss bit36 */
			{ 4211,17,0}, /* core3 pc_iss bit37 */
			{ 4212,15,0}, /* core3 pc_iss bit38 */
			{ 4213,13,0}, /* core3 pc_iss bit39 */
			{ 4214,11,0}, /* core3 pc_iss bit40 */
			{ 4215, 9,0}, /* core3 pc_iss bit41 */
			{ 4216, 7,0}, /* core3 pc_iss bit42 */
			{ 4217, 5,0}, /* core3 pc_iss bit43 */
			{ 4218, 3,0}, /* core3 pc_iss bit44 */
			{ 4219, 1,0}, /* core3 pc_iss bit45 */
			{ 9658,42,0}, /* core3 pc_iss bit46 */
			{ 9658, 8,0}, /* core3 pc_iss bit47 */
			{ 9659,46,0}, /* core3 pc_iss bit48 */
			{ 9659,12,0}, /* core3 pc_iss bit49 */
			{ 9664,32,0}, /* core3 pc_iss bit50 */
			{ 9663,62,0}, /* core3 pc_iss bit51 */
			{ 9566,14,0}, /* core3 pc_iss bit52 */
			{ 9565,44,0}, /* core3 pc_iss bit53 */
			{ 4222,57,0}, /* core3 pc_iss bit54 */
			{ 4221,59,0}, /* core3 pc_iss bit55 */
			{ 4220,61,0}, /* core3 pc_iss bit56 */
			{ 4219,63,0}, /* core3 pc_iss bit57 */
			{ 9662,24,0}, /* core3 pc_iss bit58 */
			{ 9661,54,0}, /* core3 pc_iss bit59 */
			{ 9661,20,0}, /* core3 pc_iss bit60 */
			{ 9660,50,0}, /* core3 pc_iss bit61 */
			{ 9663,28,0}, /* core3 pc_iss bit62 */
			{ 9662,58,0}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 7533,53,1}, /* core3 full_pc_wr bit0 */
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
			{ 4472,53,0}, /* core3 full_pc_ex1 bit0 */
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
			{ 4469,59,0}, /* core3 full_pc_ex2 bit0 */
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
};

struct big_core_spec big_core[] = {
	{		/* core 4 */
			.i0_valid = {{
			{11069,48,0}, /* core4 i0_valid bit0 */
			{    0, 0,2}, /* core4 i0_valid bit1 */
			{    0, 0,2}, /* core4 i0_valid bit2 */
			{    0, 0,2}, /* core4 i0_valid bit3 */
			{    0, 0,2}, /* core4 i0_valid bit4 */
			{    0, 0,2}, /* core4 i0_valid bit5 */
			{    0, 0,2}, /* core4 i0_valid bit6 */
			{    0, 0,2}, /* core4 i0_valid bit7 */
			{    0, 0,2}, /* core4 i0_valid bit8 */
			{    0, 0,2}, /* core4 i0_valid bit9 */
			{    0, 0,2}, /* core4 i0_valid bit10 */
			{    0, 0,2}, /* core4 i0_valid bit11 */
			{    0, 0,2}, /* core4 i0_valid bit12 */
			{    0, 0,2}, /* core4 i0_valid bit13 */
			{    0, 0,2}, /* core4 i0_valid bit14 */
			{    0, 0,2}, /* core4 i0_valid bit15 */
			{    0, 0,2}, /* core4 i0_valid bit16 */
			{    0, 0,2}, /* core4 i0_valid bit17 */
			{    0, 0,2}, /* core4 i0_valid bit18 */
			{    0, 0,2}, /* core4 i0_valid bit19 */
			{    0, 0,2}, /* core4 i0_valid bit20 */
			{    0, 0,2}, /* core4 i0_valid bit21 */
			{    0, 0,2}, /* core4 i0_valid bit22 */
			{    0, 0,2}, /* core4 i0_valid bit23 */
			{    0, 0,2}, /* core4 i0_valid bit24 */
			{    0, 0,2}, /* core4 i0_valid bit25 */
			{    0, 0,2}, /* core4 i0_valid bit26 */
			{    0, 0,2}, /* core4 i0_valid bit27 */
			{    0, 0,2}, /* core4 i0_valid bit28 */
			{    0, 0,2}, /* core4 i0_valid bit29 */
			{    0, 0,2}, /* core4 i0_valid bit30 */
			{    0, 0,2}, /* core4 i0_valid bit31 */
			{    0, 0,2}, /* core4 i0_valid bit32 */
			{    0, 0,2}, /* core4 i0_valid bit33 */
			{    0, 0,2}, /* core4 i0_valid bit34 */
			{    0, 0,2}, /* core4 i0_valid bit35 */
			{    0, 0,2}, /* core4 i0_valid bit36 */
			{    0, 0,2}, /* core4 i0_valid bit37 */
			{    0, 0,2}, /* core4 i0_valid bit38 */
			{    0, 0,2}, /* core4 i0_valid bit39 */
			{    0, 0,2}, /* core4 i0_valid bit40 */
			{    0, 0,2}, /* core4 i0_valid bit41 */
			{    0, 0,2}, /* core4 i0_valid bit42 */
			{    0, 0,2}, /* core4 i0_valid bit43 */
			{    0, 0,2}, /* core4 i0_valid bit44 */
			{    0, 0,2}, /* core4 i0_valid bit45 */
			{    0, 0,2}, /* core4 i0_valid bit46 */
			{    0, 0,2}, /* core4 i0_valid bit47 */
			{    0, 0,2}, /* core4 i0_valid bit48 */
			{    0, 0,2}, /* core4 i0_valid bit49 */
			{    0, 0,2}, /* core4 i0_valid bit50 */
			{    0, 0,2}, /* core4 i0_valid bit51 */
			{    0, 0,2}, /* core4 i0_valid bit52 */
			{    0, 0,2}, /* core4 i0_valid bit53 */
			{    0, 0,2}, /* core4 i0_valid bit54 */
			{    0, 0,2}, /* core4 i0_valid bit55 */
			{    0, 0,2}, /* core4 i0_valid bit56 */
			{    0, 0,2}, /* core4 i0_valid bit57 */
			{    0, 0,2}, /* core4 i0_valid bit58 */
			{    0, 0,2}, /* core4 i0_valid bit59 */
			{    0, 0,2}, /* core4 i0_valid bit60 */
			{    0, 0,2}, /* core4 i0_valid bit61 */
			{    0, 0,2}, /* core4 i0_valid bit62 */
			{    0, 0,2}, /* core4 i0_valid bit63 */
			}},
			.i0_pc = {{
			{ 9873,24,0}, /* core4 i0_pc bit0 */
			{ 9867,34,0}, /* core4 i0_pc bit1 */
			{ 9870,12,0}, /* core4 i0_pc bit2 */
			{ 9869, 8,0}, /* core4 i0_pc bit3 */
			{ 9871,16,0}, /* core4 i0_pc bit4 */
			{ 8439,50,0}, /* core4 i0_pc bit5 */
			{ 9180,19,1}, /* core4 i0_pc bit6 */
			{ 9869,42,0}, /* core4 i0_pc bit7 */
			{ 9868,38,0}, /* core4 i0_pc bit8 */
			{ 9870,46,0}, /* core4 i0_pc bit9 */
			{ 9871,50,0}, /* core4 i0_pc bit10 */
			{ 9865,26,0}, /* core4 i0_pc bit11 */
			{ 9867, 0,0}, /* core4 i0_pc bit12 */
			{ 9872,20,0}, /* core4 i0_pc bit13 */
			{ 9874,28,0}, /* core4 i0_pc bit14 */
			{ 9868, 4,0}, /* core4 i0_pc bit15 */
			{ 9862,48,0}, /* core4 i0_pc bit16 */
			{ 9873,58,0}, /* core4 i0_pc bit17 */
			{ 8318,45,0}, /* core4 i0_pc bit18 */
			{ 9863,18,0}, /* core4 i0_pc bit19 */
			{ 9872,54,0}, /* core4 i0_pc bit20 */
			{ 9863,52,0}, /* core4 i0_pc bit21 */
			{ 8315,32,0}, /* core4 i0_pc bit22 */
			{ 9866,30,0}, /* core4 i0_pc bit23 */
			{ 8316, 9,0}, /* core4 i0_pc bit24 */
			{ 8316,50,0}, /* core4 i0_pc bit25 */
			{ 9862,14,0}, /* core4 i0_pc bit26 */
			{ 8318, 4,0}, /* core4 i0_pc bit27 */
			{ 8317,27,0}, /* core4 i0_pc bit28 */
			{ 9865,60,0}, /* core4 i0_pc bit29 */
			{ 9864,22,0}, /* core4 i0_pc bit30 */
			{ 9864,56,0}, /* core4 i0_pc bit31 */
			{ 8303,62,0}, /* core4 i0_pc bit32 */
			{10945,28,0}, /* core4 i0_pc bit33 */
			{10933,14,0}, /* core4 i0_pc bit34 */
			{10944,58,0}, /* core4 i0_pc bit35 */
			{10934,18,0}, /* core4 i0_pc bit36 */
			{10930,36,0}, /* core4 i0_pc bit37 */
			{10932,44,0}, /* core4 i0_pc bit38 */
			{ 8299,31,0}, /* core4 i0_pc bit39 */
			{ 8300,49,0}, /* core4 i0_pc bit40 */
			{10931,40,0}, /* core4 i0_pc bit41 */
			{10944,24,0}, /* core4 i0_pc bit42 */
			{10933,48,0}, /* core4 i0_pc bit43 */
			{ 8303,21,0}, /* core4 i0_pc bit44 */
			{10928,28,0}, /* core4 i0_pc bit45 */
			{10932,10,0}, /* core4 i0_pc bit46 */
			{ 8300, 8,0}, /* core4 i0_pc bit47 */
			{10943,54,0}, /* core4 i0_pc bit48 */
			{10926,54,0}, /* core4 i0_pc bit49 */
			{10946,32,0}, /* core4 i0_pc bit50 */
			{10947, 2,0}, /* core4 i0_pc bit51 */
			{ 8302,44,0}, /* core4 i0_pc bit52 */
			{10947,36,0}, /* core4 i0_pc bit53 */
			{ 8301,26,0}, /* core4 i0_pc bit54 */
			{ 8302, 3,0}, /* core4 i0_pc bit55 */
			{10927,58,0}, /* core4 i0_pc bit56 */
			{10930, 2,0}, /* core4 i0_pc bit57 */
			{10934,52,0}, /* core4 i0_pc bit58 */
			{10928,62,0}, /* core4 i0_pc bit59 */
			{10945,62,0}, /* core4 i0_pc bit60 */
			{10927,24,0}, /* core4 i0_pc bit61 */
			{10931, 6,0}, /* core4 i0_pc bit62 */
			{10929,32,0}, /* core4 i0_pc bit63 */
			}},
			.i1_valid = {{
			{11069,14,0}, /* core4 i1_valid bit0 */
			{    0, 0,2}, /* core4 i1_valid bit1 */
			{    0, 0,2}, /* core4 i1_valid bit2 */
			{    0, 0,2}, /* core4 i1_valid bit3 */
			{    0, 0,2}, /* core4 i1_valid bit4 */
			{    0, 0,2}, /* core4 i1_valid bit5 */
			{    0, 0,2}, /* core4 i1_valid bit6 */
			{    0, 0,2}, /* core4 i1_valid bit7 */
			{    0, 0,2}, /* core4 i1_valid bit8 */
			{    0, 0,2}, /* core4 i1_valid bit9 */
			{    0, 0,2}, /* core4 i1_valid bit10 */
			{    0, 0,2}, /* core4 i1_valid bit11 */
			{    0, 0,2}, /* core4 i1_valid bit12 */
			{    0, 0,2}, /* core4 i1_valid bit13 */
			{    0, 0,2}, /* core4 i1_valid bit14 */
			{    0, 0,2}, /* core4 i1_valid bit15 */
			{    0, 0,2}, /* core4 i1_valid bit16 */
			{    0, 0,2}, /* core4 i1_valid bit17 */
			{    0, 0,2}, /* core4 i1_valid bit18 */
			{    0, 0,2}, /* core4 i1_valid bit19 */
			{    0, 0,2}, /* core4 i1_valid bit20 */
			{    0, 0,2}, /* core4 i1_valid bit21 */
			{    0, 0,2}, /* core4 i1_valid bit22 */
			{    0, 0,2}, /* core4 i1_valid bit23 */
			{    0, 0,2}, /* core4 i1_valid bit24 */
			{    0, 0,2}, /* core4 i1_valid bit25 */
			{    0, 0,2}, /* core4 i1_valid bit26 */
			{    0, 0,2}, /* core4 i1_valid bit27 */
			{    0, 0,2}, /* core4 i1_valid bit28 */
			{    0, 0,2}, /* core4 i1_valid bit29 */
			{    0, 0,2}, /* core4 i1_valid bit30 */
			{    0, 0,2}, /* core4 i1_valid bit31 */
			{    0, 0,2}, /* core4 i1_valid bit32 */
			{    0, 0,2}, /* core4 i1_valid bit33 */
			{    0, 0,2}, /* core4 i1_valid bit34 */
			{    0, 0,2}, /* core4 i1_valid bit35 */
			{    0, 0,2}, /* core4 i1_valid bit36 */
			{    0, 0,2}, /* core4 i1_valid bit37 */
			{    0, 0,2}, /* core4 i1_valid bit38 */
			{    0, 0,2}, /* core4 i1_valid bit39 */
			{    0, 0,2}, /* core4 i1_valid bit40 */
			{    0, 0,2}, /* core4 i1_valid bit41 */
			{    0, 0,2}, /* core4 i1_valid bit42 */
			{    0, 0,2}, /* core4 i1_valid bit43 */
			{    0, 0,2}, /* core4 i1_valid bit44 */
			{    0, 0,2}, /* core4 i1_valid bit45 */
			{    0, 0,2}, /* core4 i1_valid bit46 */
			{    0, 0,2}, /* core4 i1_valid bit47 */
			{    0, 0,2}, /* core4 i1_valid bit48 */
			{    0, 0,2}, /* core4 i1_valid bit49 */
			{    0, 0,2}, /* core4 i1_valid bit50 */
			{    0, 0,2}, /* core4 i1_valid bit51 */
			{    0, 0,2}, /* core4 i1_valid bit52 */
			{    0, 0,2}, /* core4 i1_valid bit53 */
			{    0, 0,2}, /* core4 i1_valid bit54 */
			{    0, 0,2}, /* core4 i1_valid bit55 */
			{    0, 0,2}, /* core4 i1_valid bit56 */
			{    0, 0,2}, /* core4 i1_valid bit57 */
			{    0, 0,2}, /* core4 i1_valid bit58 */
			{    0, 0,2}, /* core4 i1_valid bit59 */
			{    0, 0,2}, /* core4 i1_valid bit60 */
			{    0, 0,2}, /* core4 i1_valid bit61 */
			{    0, 0,2}, /* core4 i1_valid bit62 */
			{    0, 0,2}, /* core4 i1_valid bit63 */
			}},
			.i1_pc = {{
			{ 8397,32,0}, /* core4 i1_pc bit0 */
			{ 8398, 9,0}, /* core4 i1_pc bit1 */
			{ 8405,12,0}, /* core4 i1_pc bit2 */
			{ 8404,35,0}, /* core4 i1_pc bit3 */
			{ 8395,37,0}, /* core4 i1_pc bit4 */
			{ 8412,15,0}, /* core4 i1_pc bit5 */
			{ 8410,20,0}, /* core4 i1_pc bit6 */
			{ 8410,61,0}, /* core4 i1_pc bit7 */
			{ 8403,58,0}, /* core4 i1_pc bit8 */
			{ 8411,38,0}, /* core4 i1_pc bit9 */
			{ 8401,22,0}, /* core4 i1_pc bit10 */
			{ 8414,51,0}, /* core4 i1_pc bit11 */
			{ 8414,10,0}, /* core4 i1_pc bit12 */
			{ 8398,50,0}, /* core4 i1_pc bit13 */
			{ 8402,40,0}, /* core4 i1_pc bit14 */
			{ 8413,33,0}, /* core4 i1_pc bit15 */
			{ 8403,17,0}, /* core4 i1_pc bit16 */
			{ 8407,48,0}, /* core4 i1_pc bit17 */
			{ 8400, 4,0}, /* core4 i1_pc bit18 */
			{ 8396,55,0}, /* core4 i1_pc bit19 */
			{ 8396,14,0}, /* core4 i1_pc bit20 */
			{ 8412,56,0}, /* core4 i1_pc bit21 */
			{ 8401,63,0}, /* core4 i1_pc bit22 */
			{ 8400,45,0}, /* core4 i1_pc bit23 */
			{ 8399,27,0}, /* core4 i1_pc bit24 */
			{ 8417,23,0}, /* core4 i1_pc bit25 */
			{ 8416,46,0}, /* core4 i1_pc bit26 */
			{ 8416, 5,0}, /* core4 i1_pc bit27 */
			{ 8415,28,0}, /* core4 i1_pc bit28 */
			{ 8409,43,0}, /* core4 i1_pc bit29 */
			{ 8408,25,0}, /* core4 i1_pc bit30 */
			{ 8409, 2,0}, /* core4 i1_pc bit31 */
			{ 8274,32,0}, /* core4 i1_pc bit32 */
			{10925,16,0}, /* core4 i1_pc bit33 */
			{ 8279,40,0}, /* core4 i1_pc bit34 */
			{ 8276,27,0}, /* core4 i1_pc bit35 */
			{ 8277, 4,0}, /* core4 i1_pc bit36 */
			{10926,20,0}, /* core4 i1_pc bit37 */
			{10919,26,0}, /* core4 i1_pc bit38 */
			{10924,46,0}, /* core4 i1_pc bit39 */
			{ 8266,11,0}, /* core4 i1_pc bit40 */
			{10925,50,0}, /* core4 i1_pc bit41 */
			{10919,60,0}, /* core4 i1_pc bit42 */
			{10921, 0,0}, /* core4 i1_pc bit43 */
			{ 8275, 9,0}, /* core4 i1_pc bit44 */
			{ 8275,50,0}, /* core4 i1_pc bit45 */
			{ 8278,22,0}, /* core4 i1_pc bit46 */
			{ 8278,63,0}, /* core4 i1_pc bit47 */
			{ 8273,55,0}, /* core4 i1_pc bit48 */
			{10923, 8,0}, /* core4 i1_pc bit49 */
			{ 8265,34,0}, /* core4 i1_pc bit50 */
			{10917,18,0}, /* core4 i1_pc bit51 */
			{ 8280,58,0}, /* core4 i1_pc bit52 */
			{10922,38,0}, /* core4 i1_pc bit53 */
			{ 8280,17,0}, /* core4 i1_pc bit54 */
			{10918,22,0}, /* core4 i1_pc bit55 */
			{10918,56,0}, /* core4 i1_pc bit56 */
			{10924,12,0}, /* core4 i1_pc bit57 */
			{ 8277,45,0}, /* core4 i1_pc bit58 */
			{10917,52,0}, /* core4 i1_pc bit59 */
			{10920,30,0}, /* core4 i1_pc bit60 */
			{ 8267,29,0}, /* core4 i1_pc bit61 */
			{10923,42,0}, /* core4 i1_pc bit62 */
			{ 8266,52,0}, /* core4 i1_pc bit63 */
			}},
			.last_branch = {{
			{ 5712,55,0}, /* core4 last_branch bit0 */
			{ 4149,37,0}, /* core4 last_branch bit1 */
			{ 2996,49,0}, /* core4 last_branch bit2 */
			{ 2993,55,0}, /* core4 last_branch bit3 */
			{ 6127,63,0}, /* core4 last_branch bit4 */
			{ 6122,55,0}, /* core4 last_branch bit5 */
			{ 6121,37,0}, /* core4 last_branch bit6 */
			{ 6120,60,0}, /* core4 last_branch bit7 */
			{ 6120,19,0}, /* core4 last_branch bit8 */
			{ 6124, 9,0}, /* core4 last_branch bit9 */
			{ 5711,37,0}, /* core4 last_branch bit10 */
			{ 5714,50,0}, /* core4 last_branch bit11 */
			{ 5714, 9,0}, /* core4 last_branch bit12 */
			{ 5713,32,0}, /* core4 last_branch bit13 */
			{ 5710,60,0}, /* core4 last_branch bit14 */
			{ 5712,14,0}, /* core4 last_branch bit15 */
			{ 2999,43,0}, /* core4 last_branch bit16 */
			{ 5710,19,0}, /* core4 last_branch bit17 */
			{ 2995,51,0}, /* core4 last_branch bit18 */
			{ 2998,45,0}, /* core4 last_branch bit19 */
			{ 2987, 5,0}, /* core4 last_branch bit20 */
			{ 2989,63,0}, /* core4 last_branch bit21 */
			{ 2997,47,0}, /* core4 last_branch bit22 */
			{ 2989, 1,0}, /* core4 last_branch bit23 */
			{ 2991,59,0}, /* core4 last_branch bit24 */
			{ 2990,61,0}, /* core4 last_branch bit25 */
			{ 2992,57,0}, /* core4 last_branch bit26 */
			{ 2986, 7,0}, /* core4 last_branch bit27 */
			{ 2988, 3,0}, /* core4 last_branch bit28 */
			{ 2994,53,0}, /* core4 last_branch bit29 */
			{ 2985, 9,0}, /* core4 last_branch bit30 */
			{ 5935,51,0}, /* core4 last_branch bit31 */
			{ 5937,46,0}, /* core4 last_branch bit32 */
			{ 5936,28,0}, /* core4 last_branch bit33 */
			{ 5938,23,0}, /* core4 last_branch bit34 */
			{ 5939, 0,0}, /* core4 last_branch bit35 */
			{ 6128,40,0}, /* core4 last_branch bit36 */
			{ 6130,35,0}, /* core4 last_branch bit37 */
			{ 5937, 5,0}, /* core4 last_branch bit38 */
			{ 5935,10,0}, /* core4 last_branch bit39 */
			{ 6129,58,0}, /* core4 last_branch bit40 */
			{ 5939,41,0}, /* core4 last_branch bit41 */
			{ 6129,17,0}, /* core4 last_branch bit42 */
			{ 6126, 4,0}, /* core4 last_branch bit43 */
			{ 6123,32,0}, /* core4 last_branch bit44 */
			{ 6126,45,0}, /* core4 last_branch bit45 */
			{ 6122,14,0}, /* core4 last_branch bit46 */
			{ 6124,50,0}, /* core4 last_branch bit47 */
			{ 6127,22,0}, /* core4 last_branch bit48 */
			{    0, 0,2}, /* core4 last_branch bit49 */
			{    0, 0,2}, /* core4 last_branch bit50 */
			{    0, 0,2}, /* core4 last_branch bit51 */
			{    0, 0,2}, /* core4 last_branch bit52 */
			{    0, 0,2}, /* core4 last_branch bit53 */
			{    0, 0,2}, /* core4 last_branch bit54 */
			{    0, 0,2}, /* core4 last_branch bit55 */
			{    0, 0,2}, /* core4 last_branch bit56 */
			{    0, 0,2}, /* core4 last_branch bit57 */
			{    0, 0,2}, /* core4 last_branch bit58 */
			{    0, 0,2}, /* core4 last_branch bit59 */
			{    0, 0,2}, /* core4 last_branch bit60 */
			{    0, 0,2}, /* core4 last_branch bit61 */
			{    0, 0,2}, /* core4 last_branch bit62 */
			{    0, 0,2}, /* core4 last_branch bit63 */
			}},
			.sram_wr_ptr = {{
			{13668, 4,1}, /* core4 sram_wr_ptr bit0 */
			{ 2204,20,0}, /* core4 sram_wr_ptr bit1 */
			{ 2207,14,0}, /* core4 sram_wr_ptr bit2 */
			{ 2206,16,0}, /* core4 sram_wr_ptr bit3 */
			{ 2205,18,0}, /* core4 sram_wr_ptr bit4 */
			{13668,38,1}, /* core4 sram_wr_ptr bit5 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit6 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit7 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit8 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit9 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit10 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit11 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit12 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit13 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit14 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit15 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit16 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit17 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit18 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit19 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit20 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit21 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit22 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit23 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit24 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit25 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit26 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit27 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit28 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit29 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit30 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit31 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit32 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit33 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit34 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit35 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit36 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit37 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit38 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit39 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit40 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit41 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit42 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit43 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit44 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit45 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit46 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit47 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit48 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit49 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit50 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit51 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit52 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit53 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit54 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit55 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit56 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit57 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit58 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit59 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit60 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit61 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit62 */
			{    0, 0,2}, /* core4 sram_wr_ptr bit63 */
			}},
	},
	{		/* core 5 */
			.i0_valid = {{
			{11069,52,0}, /* core5 i0_valid bit0 */
			{    0, 0,2}, /* core5 i0_valid bit1 */
			{    0, 0,2}, /* core5 i0_valid bit2 */
			{    0, 0,2}, /* core5 i0_valid bit3 */
			{    0, 0,2}, /* core5 i0_valid bit4 */
			{    0, 0,2}, /* core5 i0_valid bit5 */
			{    0, 0,2}, /* core5 i0_valid bit6 */
			{    0, 0,2}, /* core5 i0_valid bit7 */
			{    0, 0,2}, /* core5 i0_valid bit8 */
			{    0, 0,2}, /* core5 i0_valid bit9 */
			{    0, 0,2}, /* core5 i0_valid bit10 */
			{    0, 0,2}, /* core5 i0_valid bit11 */
			{    0, 0,2}, /* core5 i0_valid bit12 */
			{    0, 0,2}, /* core5 i0_valid bit13 */
			{    0, 0,2}, /* core5 i0_valid bit14 */
			{    0, 0,2}, /* core5 i0_valid bit15 */
			{    0, 0,2}, /* core5 i0_valid bit16 */
			{    0, 0,2}, /* core5 i0_valid bit17 */
			{    0, 0,2}, /* core5 i0_valid bit18 */
			{    0, 0,2}, /* core5 i0_valid bit19 */
			{    0, 0,2}, /* core5 i0_valid bit20 */
			{    0, 0,2}, /* core5 i0_valid bit21 */
			{    0, 0,2}, /* core5 i0_valid bit22 */
			{    0, 0,2}, /* core5 i0_valid bit23 */
			{    0, 0,2}, /* core5 i0_valid bit24 */
			{    0, 0,2}, /* core5 i0_valid bit25 */
			{    0, 0,2}, /* core5 i0_valid bit26 */
			{    0, 0,2}, /* core5 i0_valid bit27 */
			{    0, 0,2}, /* core5 i0_valid bit28 */
			{    0, 0,2}, /* core5 i0_valid bit29 */
			{    0, 0,2}, /* core5 i0_valid bit30 */
			{    0, 0,2}, /* core5 i0_valid bit31 */
			{    0, 0,2}, /* core5 i0_valid bit32 */
			{    0, 0,2}, /* core5 i0_valid bit33 */
			{    0, 0,2}, /* core5 i0_valid bit34 */
			{    0, 0,2}, /* core5 i0_valid bit35 */
			{    0, 0,2}, /* core5 i0_valid bit36 */
			{    0, 0,2}, /* core5 i0_valid bit37 */
			{    0, 0,2}, /* core5 i0_valid bit38 */
			{    0, 0,2}, /* core5 i0_valid bit39 */
			{    0, 0,2}, /* core5 i0_valid bit40 */
			{    0, 0,2}, /* core5 i0_valid bit41 */
			{    0, 0,2}, /* core5 i0_valid bit42 */
			{    0, 0,2}, /* core5 i0_valid bit43 */
			{    0, 0,2}, /* core5 i0_valid bit44 */
			{    0, 0,2}, /* core5 i0_valid bit45 */
			{    0, 0,2}, /* core5 i0_valid bit46 */
			{    0, 0,2}, /* core5 i0_valid bit47 */
			{    0, 0,2}, /* core5 i0_valid bit48 */
			{    0, 0,2}, /* core5 i0_valid bit49 */
			{    0, 0,2}, /* core5 i0_valid bit50 */
			{    0, 0,2}, /* core5 i0_valid bit51 */
			{    0, 0,2}, /* core5 i0_valid bit52 */
			{    0, 0,2}, /* core5 i0_valid bit53 */
			{    0, 0,2}, /* core5 i0_valid bit54 */
			{    0, 0,2}, /* core5 i0_valid bit55 */
			{    0, 0,2}, /* core5 i0_valid bit56 */
			{    0, 0,2}, /* core5 i0_valid bit57 */
			{    0, 0,2}, /* core5 i0_valid bit58 */
			{    0, 0,2}, /* core5 i0_valid bit59 */
			{    0, 0,2}, /* core5 i0_valid bit60 */
			{    0, 0,2}, /* core5 i0_valid bit61 */
			{    0, 0,2}, /* core5 i0_valid bit62 */
			{    0, 0,2}, /* core5 i0_valid bit63 */
			}},
			.i0_pc = {{
			{ 9873,28,0}, /* core5 i0_pc bit0 */
			{ 9867,38,0}, /* core5 i0_pc bit1 */
			{ 9870,16,0}, /* core5 i0_pc bit2 */
			{ 9869,12,0}, /* core5 i0_pc bit3 */
			{ 9871,20,0}, /* core5 i0_pc bit4 */
			{ 8439,54,0}, /* core5 i0_pc bit5 */
			{ 9180,23,1}, /* core5 i0_pc bit6 */
			{ 9869,46,0}, /* core5 i0_pc bit7 */
			{ 9868,42,0}, /* core5 i0_pc bit8 */
			{ 9870,50,0}, /* core5 i0_pc bit9 */
			{ 9871,54,0}, /* core5 i0_pc bit10 */
			{ 9865,30,0}, /* core5 i0_pc bit11 */
			{ 9867, 4,0}, /* core5 i0_pc bit12 */
			{ 9872,24,0}, /* core5 i0_pc bit13 */
			{ 9874,32,0}, /* core5 i0_pc bit14 */
			{ 9868, 8,0}, /* core5 i0_pc bit15 */
			{ 9862,52,0}, /* core5 i0_pc bit16 */
			{ 9873,62,0}, /* core5 i0_pc bit17 */
			{ 8318,49,0}, /* core5 i0_pc bit18 */
			{ 9863,22,0}, /* core5 i0_pc bit19 */
			{ 9872,58,0}, /* core5 i0_pc bit20 */
			{ 9863,56,0}, /* core5 i0_pc bit21 */
			{ 8315,36,0}, /* core5 i0_pc bit22 */
			{ 9866,34,0}, /* core5 i0_pc bit23 */
			{ 8316,13,0}, /* core5 i0_pc bit24 */
			{ 8316,54,0}, /* core5 i0_pc bit25 */
			{ 9862,18,0}, /* core5 i0_pc bit26 */
			{ 8318, 8,0}, /* core5 i0_pc bit27 */
			{ 8317,31,0}, /* core5 i0_pc bit28 */
			{ 9866, 0,0}, /* core5 i0_pc bit29 */
			{ 9864,26,0}, /* core5 i0_pc bit30 */
			{ 9864,60,0}, /* core5 i0_pc bit31 */
			{ 8304, 2,0}, /* core5 i0_pc bit32 */
			{10945,32,0}, /* core5 i0_pc bit33 */
			{10933,18,0}, /* core5 i0_pc bit34 */
			{10944,62,0}, /* core5 i0_pc bit35 */
			{10934,22,0}, /* core5 i0_pc bit36 */
			{10930,40,0}, /* core5 i0_pc bit37 */
			{10932,48,0}, /* core5 i0_pc bit38 */
			{ 8299,35,0}, /* core5 i0_pc bit39 */
			{ 8300,53,0}, /* core5 i0_pc bit40 */
			{10931,44,0}, /* core5 i0_pc bit41 */
			{10944,28,0}, /* core5 i0_pc bit42 */
			{10933,52,0}, /* core5 i0_pc bit43 */
			{ 8303,25,0}, /* core5 i0_pc bit44 */
			{10928,32,0}, /* core5 i0_pc bit45 */
			{10932,14,0}, /* core5 i0_pc bit46 */
			{ 8300,12,0}, /* core5 i0_pc bit47 */
			{10943,58,0}, /* core5 i0_pc bit48 */
			{10926,58,0}, /* core5 i0_pc bit49 */
			{10946,36,0}, /* core5 i0_pc bit50 */
			{10947, 6,0}, /* core5 i0_pc bit51 */
			{ 8302,48,0}, /* core5 i0_pc bit52 */
			{10947,40,0}, /* core5 i0_pc bit53 */
			{ 8301,30,0}, /* core5 i0_pc bit54 */
			{ 8302, 7,0}, /* core5 i0_pc bit55 */
			{10927,62,0}, /* core5 i0_pc bit56 */
			{10930, 6,0}, /* core5 i0_pc bit57 */
			{10934,56,0}, /* core5 i0_pc bit58 */
			{10929, 2,0}, /* core5 i0_pc bit59 */
			{10946, 2,0}, /* core5 i0_pc bit60 */
			{10927,28,0}, /* core5 i0_pc bit61 */
			{10931,10,0}, /* core5 i0_pc bit62 */
			{10929,36,0}, /* core5 i0_pc bit63 */
			}},
			.i1_valid = {{
			{11069,18,0}, /* core5 i1_valid bit0 */
			{    0, 0,2}, /* core5 i1_valid bit1 */
			{    0, 0,2}, /* core5 i1_valid bit2 */
			{    0, 0,2}, /* core5 i1_valid bit3 */
			{    0, 0,2}, /* core5 i1_valid bit4 */
			{    0, 0,2}, /* core5 i1_valid bit5 */
			{    0, 0,2}, /* core5 i1_valid bit6 */
			{    0, 0,2}, /* core5 i1_valid bit7 */
			{    0, 0,2}, /* core5 i1_valid bit8 */
			{    0, 0,2}, /* core5 i1_valid bit9 */
			{    0, 0,2}, /* core5 i1_valid bit10 */
			{    0, 0,2}, /* core5 i1_valid bit11 */
			{    0, 0,2}, /* core5 i1_valid bit12 */
			{    0, 0,2}, /* core5 i1_valid bit13 */
			{    0, 0,2}, /* core5 i1_valid bit14 */
			{    0, 0,2}, /* core5 i1_valid bit15 */
			{    0, 0,2}, /* core5 i1_valid bit16 */
			{    0, 0,2}, /* core5 i1_valid bit17 */
			{    0, 0,2}, /* core5 i1_valid bit18 */
			{    0, 0,2}, /* core5 i1_valid bit19 */
			{    0, 0,2}, /* core5 i1_valid bit20 */
			{    0, 0,2}, /* core5 i1_valid bit21 */
			{    0, 0,2}, /* core5 i1_valid bit22 */
			{    0, 0,2}, /* core5 i1_valid bit23 */
			{    0, 0,2}, /* core5 i1_valid bit24 */
			{    0, 0,2}, /* core5 i1_valid bit25 */
			{    0, 0,2}, /* core5 i1_valid bit26 */
			{    0, 0,2}, /* core5 i1_valid bit27 */
			{    0, 0,2}, /* core5 i1_valid bit28 */
			{    0, 0,2}, /* core5 i1_valid bit29 */
			{    0, 0,2}, /* core5 i1_valid bit30 */
			{    0, 0,2}, /* core5 i1_valid bit31 */
			{    0, 0,2}, /* core5 i1_valid bit32 */
			{    0, 0,2}, /* core5 i1_valid bit33 */
			{    0, 0,2}, /* core5 i1_valid bit34 */
			{    0, 0,2}, /* core5 i1_valid bit35 */
			{    0, 0,2}, /* core5 i1_valid bit36 */
			{    0, 0,2}, /* core5 i1_valid bit37 */
			{    0, 0,2}, /* core5 i1_valid bit38 */
			{    0, 0,2}, /* core5 i1_valid bit39 */
			{    0, 0,2}, /* core5 i1_valid bit40 */
			{    0, 0,2}, /* core5 i1_valid bit41 */
			{    0, 0,2}, /* core5 i1_valid bit42 */
			{    0, 0,2}, /* core5 i1_valid bit43 */
			{    0, 0,2}, /* core5 i1_valid bit44 */
			{    0, 0,2}, /* core5 i1_valid bit45 */
			{    0, 0,2}, /* core5 i1_valid bit46 */
			{    0, 0,2}, /* core5 i1_valid bit47 */
			{    0, 0,2}, /* core5 i1_valid bit48 */
			{    0, 0,2}, /* core5 i1_valid bit49 */
			{    0, 0,2}, /* core5 i1_valid bit50 */
			{    0, 0,2}, /* core5 i1_valid bit51 */
			{    0, 0,2}, /* core5 i1_valid bit52 */
			{    0, 0,2}, /* core5 i1_valid bit53 */
			{    0, 0,2}, /* core5 i1_valid bit54 */
			{    0, 0,2}, /* core5 i1_valid bit55 */
			{    0, 0,2}, /* core5 i1_valid bit56 */
			{    0, 0,2}, /* core5 i1_valid bit57 */
			{    0, 0,2}, /* core5 i1_valid bit58 */
			{    0, 0,2}, /* core5 i1_valid bit59 */
			{    0, 0,2}, /* core5 i1_valid bit60 */
			{    0, 0,2}, /* core5 i1_valid bit61 */
			{    0, 0,2}, /* core5 i1_valid bit62 */
			{    0, 0,2}, /* core5 i1_valid bit63 */
			}},
			.i1_pc = {{
			{ 8397,36,0}, /* core5 i1_pc bit0 */
			{ 8398,13,0}, /* core5 i1_pc bit1 */
			{ 8405,16,0}, /* core5 i1_pc bit2 */
			{ 8404,39,0}, /* core5 i1_pc bit3 */
			{ 8395,41,0}, /* core5 i1_pc bit4 */
			{ 8412,19,0}, /* core5 i1_pc bit5 */
			{ 8410,24,0}, /* core5 i1_pc bit6 */
			{ 8411, 1,0}, /* core5 i1_pc bit7 */
			{ 8403,62,0}, /* core5 i1_pc bit8 */
			{ 8411,42,0}, /* core5 i1_pc bit9 */
			{ 8401,26,0}, /* core5 i1_pc bit10 */
			{ 8414,55,0}, /* core5 i1_pc bit11 */
			{ 8414,14,0}, /* core5 i1_pc bit12 */
			{ 8398,54,0}, /* core5 i1_pc bit13 */
			{ 8402,44,0}, /* core5 i1_pc bit14 */
			{ 8413,37,0}, /* core5 i1_pc bit15 */
			{ 8403,21,0}, /* core5 i1_pc bit16 */
			{ 8407,52,0}, /* core5 i1_pc bit17 */
			{ 8400, 8,0}, /* core5 i1_pc bit18 */
			{ 8396,59,0}, /* core5 i1_pc bit19 */
			{ 8396,18,0}, /* core5 i1_pc bit20 */
			{ 8412,60,0}, /* core5 i1_pc bit21 */
			{ 8402, 3,0}, /* core5 i1_pc bit22 */
			{ 8400,49,0}, /* core5 i1_pc bit23 */
			{ 8399,31,0}, /* core5 i1_pc bit24 */
			{ 8417,27,0}, /* core5 i1_pc bit25 */
			{ 8416,50,0}, /* core5 i1_pc bit26 */
			{ 8416, 9,0}, /* core5 i1_pc bit27 */
			{ 8415,32,0}, /* core5 i1_pc bit28 */
			{ 8409,47,0}, /* core5 i1_pc bit29 */
			{ 8408,29,0}, /* core5 i1_pc bit30 */
			{ 8409, 6,0}, /* core5 i1_pc bit31 */
			{ 8274,36,0}, /* core5 i1_pc bit32 */
			{10925,20,0}, /* core5 i1_pc bit33 */
			{ 8279,44,0}, /* core5 i1_pc bit34 */
			{ 8276,31,0}, /* core5 i1_pc bit35 */
			{ 8277, 8,0}, /* core5 i1_pc bit36 */
			{10926,24,0}, /* core5 i1_pc bit37 */
			{10919,30,0}, /* core5 i1_pc bit38 */
			{10924,50,0}, /* core5 i1_pc bit39 */
			{ 8266,15,0}, /* core5 i1_pc bit40 */
			{10925,54,0}, /* core5 i1_pc bit41 */
			{10920, 0,0}, /* core5 i1_pc bit42 */
			{10921, 4,0}, /* core5 i1_pc bit43 */
			{ 8275,13,0}, /* core5 i1_pc bit44 */
			{ 8275,54,0}, /* core5 i1_pc bit45 */
			{ 8278,26,0}, /* core5 i1_pc bit46 */
			{ 8279, 3,0}, /* core5 i1_pc bit47 */
			{ 8273,59,0}, /* core5 i1_pc bit48 */
			{10923,12,0}, /* core5 i1_pc bit49 */
			{ 8265,38,0}, /* core5 i1_pc bit50 */
			{10917,22,0}, /* core5 i1_pc bit51 */
			{ 8280,62,0}, /* core5 i1_pc bit52 */
			{10922,42,0}, /* core5 i1_pc bit53 */
			{ 8280,21,0}, /* core5 i1_pc bit54 */
			{10918,26,0}, /* core5 i1_pc bit55 */
			{10918,60,0}, /* core5 i1_pc bit56 */
			{10924,16,0}, /* core5 i1_pc bit57 */
			{ 8277,49,0}, /* core5 i1_pc bit58 */
			{10917,56,0}, /* core5 i1_pc bit59 */
			{10920,34,0}, /* core5 i1_pc bit60 */
			{ 8267,33,0}, /* core5 i1_pc bit61 */
			{10923,46,0}, /* core5 i1_pc bit62 */
			{ 8266,56,0}, /* core5 i1_pc bit63 */
			}},
			.last_branch = {{
			{ 5712,57,0}, /* core5 last_branch bit0 */
			{ 4149,39,0}, /* core5 last_branch bit1 */
			{ 2996,51,0}, /* core5 last_branch bit2 */
			{ 2993,57,0}, /* core5 last_branch bit3 */
			{ 6128, 1,0}, /* core5 last_branch bit4 */
			{ 6122,57,0}, /* core5 last_branch bit5 */
			{ 6121,39,0}, /* core5 last_branch bit6 */
			{ 6120,62,0}, /* core5 last_branch bit7 */
			{ 6120,21,0}, /* core5 last_branch bit8 */
			{ 6124,11,0}, /* core5 last_branch bit9 */
			{ 5711,39,0}, /* core5 last_branch bit10 */
			{ 5714,52,0}, /* core5 last_branch bit11 */
			{ 5714,11,0}, /* core5 last_branch bit12 */
			{ 5713,34,0}, /* core5 last_branch bit13 */
			{ 5710,62,0}, /* core5 last_branch bit14 */
			{ 5712,16,0}, /* core5 last_branch bit15 */
			{ 2999,45,0}, /* core5 last_branch bit16 */
			{ 5710,21,0}, /* core5 last_branch bit17 */
			{ 2995,53,0}, /* core5 last_branch bit18 */
			{ 2998,47,0}, /* core5 last_branch bit19 */
			{ 2987, 7,0}, /* core5 last_branch bit20 */
			{ 2990, 1,0}, /* core5 last_branch bit21 */
			{ 2997,49,0}, /* core5 last_branch bit22 */
			{ 2989, 3,0}, /* core5 last_branch bit23 */
			{ 2991,61,0}, /* core5 last_branch bit24 */
			{ 2990,63,0}, /* core5 last_branch bit25 */
			{ 2992,59,0}, /* core5 last_branch bit26 */
			{ 2986, 9,0}, /* core5 last_branch bit27 */
			{ 2988, 5,0}, /* core5 last_branch bit28 */
			{ 2994,55,0}, /* core5 last_branch bit29 */
			{ 2985,11,0}, /* core5 last_branch bit30 */
			{ 5935,53,0}, /* core5 last_branch bit31 */
			{ 5937,48,0}, /* core5 last_branch bit32 */
			{ 5936,30,0}, /* core5 last_branch bit33 */
			{ 5938,25,0}, /* core5 last_branch bit34 */
			{ 5939, 2,0}, /* core5 last_branch bit35 */
			{ 6128,42,0}, /* core5 last_branch bit36 */
			{ 6130,37,0}, /* core5 last_branch bit37 */
			{ 5937, 7,0}, /* core5 last_branch bit38 */
			{ 5935,12,0}, /* core5 last_branch bit39 */
			{ 6129,60,0}, /* core5 last_branch bit40 */
			{ 5939,43,0}, /* core5 last_branch bit41 */
			{ 6129,19,0}, /* core5 last_branch bit42 */
			{ 6126, 6,0}, /* core5 last_branch bit43 */
			{ 6123,34,0}, /* core5 last_branch bit44 */
			{ 6126,47,0}, /* core5 last_branch bit45 */
			{ 6122,16,0}, /* core5 last_branch bit46 */
			{ 6124,52,0}, /* core5 last_branch bit47 */
			{ 6127,24,0}, /* core5 last_branch bit48 */
			{    0, 0,2}, /* core5 last_branch bit49 */
			{    0, 0,2}, /* core5 last_branch bit50 */
			{    0, 0,2}, /* core5 last_branch bit51 */
			{    0, 0,2}, /* core5 last_branch bit52 */
			{    0, 0,2}, /* core5 last_branch bit53 */
			{    0, 0,2}, /* core5 last_branch bit54 */
			{    0, 0,2}, /* core5 last_branch bit55 */
			{    0, 0,2}, /* core5 last_branch bit56 */
			{    0, 0,2}, /* core5 last_branch bit57 */
			{    0, 0,2}, /* core5 last_branch bit58 */
			{    0, 0,2}, /* core5 last_branch bit59 */
			{    0, 0,2}, /* core5 last_branch bit60 */
			{    0, 0,2}, /* core5 last_branch bit61 */
			{    0, 0,2}, /* core5 last_branch bit62 */
			{    0, 0,2}, /* core5 last_branch bit63 */
			}},
			.sram_wr_ptr = {{
			{13668, 8,1}, /* core5 sram_wr_ptr bit0 */
			{ 2204,22,0}, /* core5 sram_wr_ptr bit1 */
			{ 2207,16,0}, /* core5 sram_wr_ptr bit2 */
			{ 2206,18,0}, /* core5 sram_wr_ptr bit3 */
			{ 2205,20,0}, /* core5 sram_wr_ptr bit4 */
			{13668,42,1}, /* core5 sram_wr_ptr bit5 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit6 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit7 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit8 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit9 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit10 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit11 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit12 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit13 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit14 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit15 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit16 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit17 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit18 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit19 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit20 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit21 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit22 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit23 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit24 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit25 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit26 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit27 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit28 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit29 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit30 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit31 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit32 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit33 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit34 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit35 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit36 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit37 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit38 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit39 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit40 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit41 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit42 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit43 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit44 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit45 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit46 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit47 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit48 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit49 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit50 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit51 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit52 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit53 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit54 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit55 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit56 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit57 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit58 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit59 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit60 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit61 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit62 */
			{    0, 0,2}, /* core5 sram_wr_ptr bit63 */
			}},
	},
	{		/* core 6 */
			.i0_valid = {{
			{11069,56,0}, /* core6 i0_valid bit0 */
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
			{ 9873,32,0}, /* core6 i0_pc bit0 */
			{ 9867,42,0}, /* core6 i0_pc bit1 */
			{ 9870,20,0}, /* core6 i0_pc bit2 */
			{ 9869,16,0}, /* core6 i0_pc bit3 */
			{ 9871,24,0}, /* core6 i0_pc bit4 */
			{ 8439,58,0}, /* core6 i0_pc bit5 */
			{ 9180,27,1}, /* core6 i0_pc bit6 */
			{ 9869,50,0}, /* core6 i0_pc bit7 */
			{ 9868,46,0}, /* core6 i0_pc bit8 */
			{ 9870,54,0}, /* core6 i0_pc bit9 */
			{ 9871,58,0}, /* core6 i0_pc bit10 */
			{ 9865,34,0}, /* core6 i0_pc bit11 */
			{ 9867, 8,0}, /* core6 i0_pc bit12 */
			{ 9872,28,0}, /* core6 i0_pc bit13 */
			{ 9874,36,0}, /* core6 i0_pc bit14 */
			{ 9868,12,0}, /* core6 i0_pc bit15 */
			{ 9862,56,0}, /* core6 i0_pc bit16 */
			{ 9874, 2,0}, /* core6 i0_pc bit17 */
			{ 8318,53,0}, /* core6 i0_pc bit18 */
			{ 9863,26,0}, /* core6 i0_pc bit19 */
			{ 9872,62,0}, /* core6 i0_pc bit20 */
			{ 9863,60,0}, /* core6 i0_pc bit21 */
			{ 8315,40,0}, /* core6 i0_pc bit22 */
			{ 9866,38,0}, /* core6 i0_pc bit23 */
			{ 8316,17,0}, /* core6 i0_pc bit24 */
			{ 8316,58,0}, /* core6 i0_pc bit25 */
			{ 9862,22,0}, /* core6 i0_pc bit26 */
			{ 8318,12,0}, /* core6 i0_pc bit27 */
			{ 8317,35,0}, /* core6 i0_pc bit28 */
			{ 9866, 4,0}, /* core6 i0_pc bit29 */
			{ 9864,30,0}, /* core6 i0_pc bit30 */
			{ 9865, 0,0}, /* core6 i0_pc bit31 */
			{ 8304, 6,0}, /* core6 i0_pc bit32 */
			{10945,36,0}, /* core6 i0_pc bit33 */
			{10933,22,0}, /* core6 i0_pc bit34 */
			{10945, 2,0}, /* core6 i0_pc bit35 */
			{10934,26,0}, /* core6 i0_pc bit36 */
			{10930,44,0}, /* core6 i0_pc bit37 */
			{10932,52,0}, /* core6 i0_pc bit38 */
			{ 8299,39,0}, /* core6 i0_pc bit39 */
			{ 8300,57,0}, /* core6 i0_pc bit40 */
			{10931,48,0}, /* core6 i0_pc bit41 */
			{10944,32,0}, /* core6 i0_pc bit42 */
			{10933,56,0}, /* core6 i0_pc bit43 */
			{ 8303,29,0}, /* core6 i0_pc bit44 */
			{10928,36,0}, /* core6 i0_pc bit45 */
			{10932,18,0}, /* core6 i0_pc bit46 */
			{ 8300,16,0}, /* core6 i0_pc bit47 */
			{10943,62,0}, /* core6 i0_pc bit48 */
			{10926,62,0}, /* core6 i0_pc bit49 */
			{10946,40,0}, /* core6 i0_pc bit50 */
			{10947,10,0}, /* core6 i0_pc bit51 */
			{ 8302,52,0}, /* core6 i0_pc bit52 */
			{10947,44,0}, /* core6 i0_pc bit53 */
			{ 8301,34,0}, /* core6 i0_pc bit54 */
			{ 8302,11,0}, /* core6 i0_pc bit55 */
			{10928, 2,0}, /* core6 i0_pc bit56 */
			{10930,10,0}, /* core6 i0_pc bit57 */
			{10934,60,0}, /* core6 i0_pc bit58 */
			{10929, 6,0}, /* core6 i0_pc bit59 */
			{10946, 6,0}, /* core6 i0_pc bit60 */
			{10927,32,0}, /* core6 i0_pc bit61 */
			{10931,14,0}, /* core6 i0_pc bit62 */
			{10929,40,0}, /* core6 i0_pc bit63 */
			}},
			.i1_valid = {{
			{11069,22,0}, /* core6 i1_valid bit0 */
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
			{ 8397,40,0}, /* core6 i1_pc bit0 */
			{ 8398,17,0}, /* core6 i1_pc bit1 */
			{ 8405,20,0}, /* core6 i1_pc bit2 */
			{ 8404,43,0}, /* core6 i1_pc bit3 */
			{ 8395,45,0}, /* core6 i1_pc bit4 */
			{ 8412,23,0}, /* core6 i1_pc bit5 */
			{ 8410,28,0}, /* core6 i1_pc bit6 */
			{ 8411, 5,0}, /* core6 i1_pc bit7 */
			{ 8404, 2,0}, /* core6 i1_pc bit8 */
			{ 8411,46,0}, /* core6 i1_pc bit9 */
			{ 8401,30,0}, /* core6 i1_pc bit10 */
			{ 8414,59,0}, /* core6 i1_pc bit11 */
			{ 8414,18,0}, /* core6 i1_pc bit12 */
			{ 8398,58,0}, /* core6 i1_pc bit13 */
			{ 8402,48,0}, /* core6 i1_pc bit14 */
			{ 8413,41,0}, /* core6 i1_pc bit15 */
			{ 8403,25,0}, /* core6 i1_pc bit16 */
			{ 8407,56,0}, /* core6 i1_pc bit17 */
			{ 8400,12,0}, /* core6 i1_pc bit18 */
			{ 8396,63,0}, /* core6 i1_pc bit19 */
			{ 8396,22,0}, /* core6 i1_pc bit20 */
			{ 8413, 0,0}, /* core6 i1_pc bit21 */
			{ 8402, 7,0}, /* core6 i1_pc bit22 */
			{ 8400,53,0}, /* core6 i1_pc bit23 */
			{ 8399,35,0}, /* core6 i1_pc bit24 */
			{ 8417,31,0}, /* core6 i1_pc bit25 */
			{ 8416,54,0}, /* core6 i1_pc bit26 */
			{ 8416,13,0}, /* core6 i1_pc bit27 */
			{ 8415,36,0}, /* core6 i1_pc bit28 */
			{ 8409,51,0}, /* core6 i1_pc bit29 */
			{ 8408,33,0}, /* core6 i1_pc bit30 */
			{ 8409,10,0}, /* core6 i1_pc bit31 */
			{ 8274,40,0}, /* core6 i1_pc bit32 */
			{10925,24,0}, /* core6 i1_pc bit33 */
			{ 8279,48,0}, /* core6 i1_pc bit34 */
			{ 8276,35,0}, /* core6 i1_pc bit35 */
			{ 8277,12,0}, /* core6 i1_pc bit36 */
			{10926,28,0}, /* core6 i1_pc bit37 */
			{10919,34,0}, /* core6 i1_pc bit38 */
			{10924,54,0}, /* core6 i1_pc bit39 */
			{ 8266,19,0}, /* core6 i1_pc bit40 */
			{10925,58,0}, /* core6 i1_pc bit41 */
			{10920, 4,0}, /* core6 i1_pc bit42 */
			{10921, 8,0}, /* core6 i1_pc bit43 */
			{ 8275,17,0}, /* core6 i1_pc bit44 */
			{ 8275,58,0}, /* core6 i1_pc bit45 */
			{ 8278,30,0}, /* core6 i1_pc bit46 */
			{ 8279, 7,0}, /* core6 i1_pc bit47 */
			{ 8273,63,0}, /* core6 i1_pc bit48 */
			{10923,16,0}, /* core6 i1_pc bit49 */
			{ 8265,42,0}, /* core6 i1_pc bit50 */
			{10917,26,0}, /* core6 i1_pc bit51 */
			{ 8281, 2,0}, /* core6 i1_pc bit52 */
			{10922,46,0}, /* core6 i1_pc bit53 */
			{ 8280,25,0}, /* core6 i1_pc bit54 */
			{10918,30,0}, /* core6 i1_pc bit55 */
			{10919, 0,0}, /* core6 i1_pc bit56 */
			{10924,20,0}, /* core6 i1_pc bit57 */
			{ 8277,53,0}, /* core6 i1_pc bit58 */
			{10917,60,0}, /* core6 i1_pc bit59 */
			{10920,38,0}, /* core6 i1_pc bit60 */
			{ 8267,37,0}, /* core6 i1_pc bit61 */
			{10923,50,0}, /* core6 i1_pc bit62 */
			{ 8266,60,0}, /* core6 i1_pc bit63 */
			}},
			.last_branch = {{
			{ 5712,59,0}, /* core6 last_branch bit0 */
			{ 4149,41,0}, /* core6 last_branch bit1 */
			{ 2996,53,0}, /* core6 last_branch bit2 */
			{ 2993,59,0}, /* core6 last_branch bit3 */
			{ 6128, 3,0}, /* core6 last_branch bit4 */
			{ 6122,59,0}, /* core6 last_branch bit5 */
			{ 6121,41,0}, /* core6 last_branch bit6 */
			{ 6121, 0,0}, /* core6 last_branch bit7 */
			{ 6120,23,0}, /* core6 last_branch bit8 */
			{ 6124,13,0}, /* core6 last_branch bit9 */
			{ 5711,41,0}, /* core6 last_branch bit10 */
			{ 5714,54,0}, /* core6 last_branch bit11 */
			{ 5714,13,0}, /* core6 last_branch bit12 */
			{ 5713,36,0}, /* core6 last_branch bit13 */
			{ 5711, 0,0}, /* core6 last_branch bit14 */
			{ 5712,18,0}, /* core6 last_branch bit15 */
			{ 2999,47,0}, /* core6 last_branch bit16 */
			{ 5710,23,0}, /* core6 last_branch bit17 */
			{ 2995,55,0}, /* core6 last_branch bit18 */
			{ 2998,49,0}, /* core6 last_branch bit19 */
			{ 2987, 9,0}, /* core6 last_branch bit20 */
			{ 2990, 3,0}, /* core6 last_branch bit21 */
			{ 2997,51,0}, /* core6 last_branch bit22 */
			{ 2989, 5,0}, /* core6 last_branch bit23 */
			{ 2991,63,0}, /* core6 last_branch bit24 */
			{ 2991, 1,0}, /* core6 last_branch bit25 */
			{ 2992,61,0}, /* core6 last_branch bit26 */
			{ 2986,11,0}, /* core6 last_branch bit27 */
			{ 2988, 7,0}, /* core6 last_branch bit28 */
			{ 2994,57,0}, /* core6 last_branch bit29 */
			{ 2985,13,0}, /* core6 last_branch bit30 */
			{ 5935,55,0}, /* core6 last_branch bit31 */
			{ 5937,50,0}, /* core6 last_branch bit32 */
			{ 5936,32,0}, /* core6 last_branch bit33 */
			{ 5938,27,0}, /* core6 last_branch bit34 */
			{ 5939, 4,0}, /* core6 last_branch bit35 */
			{ 6128,44,0}, /* core6 last_branch bit36 */
			{ 6130,39,0}, /* core6 last_branch bit37 */
			{ 5937, 9,0}, /* core6 last_branch bit38 */
			{ 5935,14,0}, /* core6 last_branch bit39 */
			{ 6129,62,0}, /* core6 last_branch bit40 */
			{ 5939,45,0}, /* core6 last_branch bit41 */
			{ 6129,21,0}, /* core6 last_branch bit42 */
			{ 6126, 8,0}, /* core6 last_branch bit43 */
			{ 6123,36,0}, /* core6 last_branch bit44 */
			{ 6126,49,0}, /* core6 last_branch bit45 */
			{ 6122,18,0}, /* core6 last_branch bit46 */
			{ 6124,54,0}, /* core6 last_branch bit47 */
			{ 6127,26,0}, /* core6 last_branch bit48 */
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
			.sram_wr_ptr = {{
			{13668,12,1}, /* core6 sram_wr_ptr bit0 */
			{ 2204,24,0}, /* core6 sram_wr_ptr bit1 */
			{ 2207,18,0}, /* core6 sram_wr_ptr bit2 */
			{ 2206,20,0}, /* core6 sram_wr_ptr bit3 */
			{ 2205,22,0}, /* core6 sram_wr_ptr bit4 */
			{13668,46,1}, /* core6 sram_wr_ptr bit5 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit6 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit7 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit8 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit9 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit10 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit11 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit12 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit13 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit14 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit15 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit16 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit17 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit18 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit19 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit20 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit21 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit22 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit23 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit24 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit25 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit26 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit27 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit28 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit29 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit30 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit31 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit32 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit33 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit34 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit35 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit36 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit37 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit38 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit39 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit40 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit41 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit42 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit43 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit44 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit45 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit46 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit47 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit48 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit49 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit50 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit51 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit52 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit53 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit54 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit55 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit56 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit57 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit58 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit59 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit60 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit61 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit62 */
			{    0, 0,2}, /* core6 sram_wr_ptr bit63 */
			}},
	},
	{		/* core 7 */
			.i0_valid = {{
			{11069,60,0}, /* core7 i0_valid bit0 */
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
			{ 9873,36,0}, /* core7 i0_pc bit0 */
			{ 9867,46,0}, /* core7 i0_pc bit1 */
			{ 9870,24,0}, /* core7 i0_pc bit2 */
			{ 9869,20,0}, /* core7 i0_pc bit3 */
			{ 9871,28,0}, /* core7 i0_pc bit4 */
			{ 8439,62,0}, /* core7 i0_pc bit5 */
			{ 9180,31,1}, /* core7 i0_pc bit6 */
			{ 9869,54,0}, /* core7 i0_pc bit7 */
			{ 9868,50,0}, /* core7 i0_pc bit8 */
			{ 9870,58,0}, /* core7 i0_pc bit9 */
			{ 9871,62,0}, /* core7 i0_pc bit10 */
			{ 9865,38,0}, /* core7 i0_pc bit11 */
			{ 9867,12,0}, /* core7 i0_pc bit12 */
			{ 9872,32,0}, /* core7 i0_pc bit13 */
			{ 9874,40,0}, /* core7 i0_pc bit14 */
			{ 9868,16,0}, /* core7 i0_pc bit15 */
			{ 9862,60,0}, /* core7 i0_pc bit16 */
			{ 9874, 6,0}, /* core7 i0_pc bit17 */
			{ 8318,57,0}, /* core7 i0_pc bit18 */
			{ 9863,30,0}, /* core7 i0_pc bit19 */
			{ 9873, 2,0}, /* core7 i0_pc bit20 */
			{ 9864, 0,0}, /* core7 i0_pc bit21 */
			{ 8315,44,0}, /* core7 i0_pc bit22 */
			{ 9866,42,0}, /* core7 i0_pc bit23 */
			{ 8316,21,0}, /* core7 i0_pc bit24 */
			{ 8316,62,0}, /* core7 i0_pc bit25 */
			{ 9862,26,0}, /* core7 i0_pc bit26 */
			{ 8318,16,0}, /* core7 i0_pc bit27 */
			{ 8317,39,0}, /* core7 i0_pc bit28 */
			{ 9866, 8,0}, /* core7 i0_pc bit29 */
			{ 9864,34,0}, /* core7 i0_pc bit30 */
			{ 9865, 4,0}, /* core7 i0_pc bit31 */
			{ 8304,10,0}, /* core7 i0_pc bit32 */
			{10945,40,0}, /* core7 i0_pc bit33 */
			{10933,26,0}, /* core7 i0_pc bit34 */
			{10945, 6,0}, /* core7 i0_pc bit35 */
			{10934,30,0}, /* core7 i0_pc bit36 */
			{10930,48,0}, /* core7 i0_pc bit37 */
			{10932,56,0}, /* core7 i0_pc bit38 */
			{ 8299,43,0}, /* core7 i0_pc bit39 */
			{ 8300,61,0}, /* core7 i0_pc bit40 */
			{10931,52,0}, /* core7 i0_pc bit41 */
			{10944,36,0}, /* core7 i0_pc bit42 */
			{10933,60,0}, /* core7 i0_pc bit43 */
			{ 8303,33,0}, /* core7 i0_pc bit44 */
			{10928,40,0}, /* core7 i0_pc bit45 */
			{10932,22,0}, /* core7 i0_pc bit46 */
			{ 8300,20,0}, /* core7 i0_pc bit47 */
			{10944, 2,0}, /* core7 i0_pc bit48 */
			{10927, 2,0}, /* core7 i0_pc bit49 */
			{10946,44,0}, /* core7 i0_pc bit50 */
			{10947,14,0}, /* core7 i0_pc bit51 */
			{ 8302,56,0}, /* core7 i0_pc bit52 */
			{10947,48,0}, /* core7 i0_pc bit53 */
			{ 8301,38,0}, /* core7 i0_pc bit54 */
			{ 8302,15,0}, /* core7 i0_pc bit55 */
			{10928, 6,0}, /* core7 i0_pc bit56 */
			{10930,14,0}, /* core7 i0_pc bit57 */
			{10935, 0,0}, /* core7 i0_pc bit58 */
			{10929,10,0}, /* core7 i0_pc bit59 */
			{10946,10,0}, /* core7 i0_pc bit60 */
			{10927,36,0}, /* core7 i0_pc bit61 */
			{10931,18,0}, /* core7 i0_pc bit62 */
			{10929,44,0}, /* core7 i0_pc bit63 */
			}},
			.i1_valid = {{
			{11069,26,0}, /* core7 i1_valid bit0 */
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
			{ 8397,44,0}, /* core7 i1_pc bit0 */
			{ 8398,21,0}, /* core7 i1_pc bit1 */
			{ 8405,24,0}, /* core7 i1_pc bit2 */
			{ 8404,47,0}, /* core7 i1_pc bit3 */
			{ 8395,49,0}, /* core7 i1_pc bit4 */
			{ 8412,27,0}, /* core7 i1_pc bit5 */
			{ 8410,32,0}, /* core7 i1_pc bit6 */
			{ 8411, 9,0}, /* core7 i1_pc bit7 */
			{ 8404, 6,0}, /* core7 i1_pc bit8 */
			{ 8411,50,0}, /* core7 i1_pc bit9 */
			{ 8401,34,0}, /* core7 i1_pc bit10 */
			{ 8414,63,0}, /* core7 i1_pc bit11 */
			{ 8414,22,0}, /* core7 i1_pc bit12 */
			{ 8398,62,0}, /* core7 i1_pc bit13 */
			{ 8402,52,0}, /* core7 i1_pc bit14 */
			{ 8413,45,0}, /* core7 i1_pc bit15 */
			{ 8403,29,0}, /* core7 i1_pc bit16 */
			{ 8407,60,0}, /* core7 i1_pc bit17 */
			{ 8400,16,0}, /* core7 i1_pc bit18 */
			{ 8397, 3,0}, /* core7 i1_pc bit19 */
			{ 8396,26,0}, /* core7 i1_pc bit20 */
			{ 8413, 4,0}, /* core7 i1_pc bit21 */
			{ 8402,11,0}, /* core7 i1_pc bit22 */
			{ 8400,57,0}, /* core7 i1_pc bit23 */
			{ 8399,39,0}, /* core7 i1_pc bit24 */
			{ 8417,35,0}, /* core7 i1_pc bit25 */
			{ 8416,58,0}, /* core7 i1_pc bit26 */
			{ 8416,17,0}, /* core7 i1_pc bit27 */
			{ 8415,40,0}, /* core7 i1_pc bit28 */
			{ 8409,55,0}, /* core7 i1_pc bit29 */
			{ 8408,37,0}, /* core7 i1_pc bit30 */
			{ 8409,14,0}, /* core7 i1_pc bit31 */
			{ 8274,44,0}, /* core7 i1_pc bit32 */
			{10925,28,0}, /* core7 i1_pc bit33 */
			{ 8279,52,0}, /* core7 i1_pc bit34 */
			{ 8276,39,0}, /* core7 i1_pc bit35 */
			{ 8277,16,0}, /* core7 i1_pc bit36 */
			{10926,32,0}, /* core7 i1_pc bit37 */
			{10919,38,0}, /* core7 i1_pc bit38 */
			{10924,58,0}, /* core7 i1_pc bit39 */
			{ 8266,23,0}, /* core7 i1_pc bit40 */
			{10925,62,0}, /* core7 i1_pc bit41 */
			{10920, 8,0}, /* core7 i1_pc bit42 */
			{10921,12,0}, /* core7 i1_pc bit43 */
			{ 8275,21,0}, /* core7 i1_pc bit44 */
			{ 8275,62,0}, /* core7 i1_pc bit45 */
			{ 8278,34,0}, /* core7 i1_pc bit46 */
			{ 8279,11,0}, /* core7 i1_pc bit47 */
			{ 8274, 3,0}, /* core7 i1_pc bit48 */
			{10923,20,0}, /* core7 i1_pc bit49 */
			{ 8265,46,0}, /* core7 i1_pc bit50 */
			{10917,30,0}, /* core7 i1_pc bit51 */
			{ 8281, 6,0}, /* core7 i1_pc bit52 */
			{10922,50,0}, /* core7 i1_pc bit53 */
			{ 8280,29,0}, /* core7 i1_pc bit54 */
			{10918,34,0}, /* core7 i1_pc bit55 */
			{10919, 4,0}, /* core7 i1_pc bit56 */
			{10924,24,0}, /* core7 i1_pc bit57 */
			{ 8277,57,0}, /* core7 i1_pc bit58 */
			{10918, 0,0}, /* core7 i1_pc bit59 */
			{10920,42,0}, /* core7 i1_pc bit60 */
			{ 8267,41,0}, /* core7 i1_pc bit61 */
			{10923,54,0}, /* core7 i1_pc bit62 */
			{ 8267, 0,0}, /* core7 i1_pc bit63 */
			}},
			.last_branch = {{
			{ 5712,61,0}, /* core7 last_branch bit0 */
			{ 4149,43,0}, /* core7 last_branch bit1 */
			{ 2996,55,0}, /* core7 last_branch bit2 */
			{ 2993,61,0}, /* core7 last_branch bit3 */
			{ 6128, 5,0}, /* core7 last_branch bit4 */
			{ 6122,61,0}, /* core7 last_branch bit5 */
			{ 6121,43,0}, /* core7 last_branch bit6 */
			{ 6121, 2,0}, /* core7 last_branch bit7 */
			{ 6120,25,0}, /* core7 last_branch bit8 */
			{ 6124,15,0}, /* core7 last_branch bit9 */
			{ 5711,43,0}, /* core7 last_branch bit10 */
			{ 5714,56,0}, /* core7 last_branch bit11 */
			{ 5714,15,0}, /* core7 last_branch bit12 */
			{ 5713,38,0}, /* core7 last_branch bit13 */
			{ 5711, 2,0}, /* core7 last_branch bit14 */
			{ 5712,20,0}, /* core7 last_branch bit15 */
			{ 2999,49,0}, /* core7 last_branch bit16 */
			{ 5710,25,0}, /* core7 last_branch bit17 */
			{ 2995,57,0}, /* core7 last_branch bit18 */
			{ 2998,51,0}, /* core7 last_branch bit19 */
			{ 2987,11,0}, /* core7 last_branch bit20 */
			{ 2990, 5,0}, /* core7 last_branch bit21 */
			{ 2997,53,0}, /* core7 last_branch bit22 */
			{ 2989, 7,0}, /* core7 last_branch bit23 */
			{ 2992, 1,0}, /* core7 last_branch bit24 */
			{ 2991, 3,0}, /* core7 last_branch bit25 */
			{ 2992,63,0}, /* core7 last_branch bit26 */
			{ 2986,13,0}, /* core7 last_branch bit27 */
			{ 2988, 9,0}, /* core7 last_branch bit28 */
			{ 2994,59,0}, /* core7 last_branch bit29 */
			{ 2985,15,0}, /* core7 last_branch bit30 */
			{ 5935,57,0}, /* core7 last_branch bit31 */
			{ 5937,52,0}, /* core7 last_branch bit32 */
			{ 5936,34,0}, /* core7 last_branch bit33 */
			{ 5938,29,0}, /* core7 last_branch bit34 */
			{ 5939, 6,0}, /* core7 last_branch bit35 */
			{ 6128,46,0}, /* core7 last_branch bit36 */
			{ 6130,41,0}, /* core7 last_branch bit37 */
			{ 5937,11,0}, /* core7 last_branch bit38 */
			{ 5935,16,0}, /* core7 last_branch bit39 */
			{ 6130, 0,0}, /* core7 last_branch bit40 */
			{ 5939,47,0}, /* core7 last_branch bit41 */
			{ 6129,23,0}, /* core7 last_branch bit42 */
			{ 6126,10,0}, /* core7 last_branch bit43 */
			{ 6123,38,0}, /* core7 last_branch bit44 */
			{ 6126,51,0}, /* core7 last_branch bit45 */
			{ 6122,20,0}, /* core7 last_branch bit46 */
			{ 6124,56,0}, /* core7 last_branch bit47 */
			{ 6127,28,0}, /* core7 last_branch bit48 */
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
			.sram_wr_ptr = {{
			{13668,16,1}, /* core7 sram_wr_ptr bit0 */
			{ 2204,26,0}, /* core7 sram_wr_ptr bit1 */
			{ 2207,20,0}, /* core7 sram_wr_ptr bit2 */
			{ 2206,22,0}, /* core7 sram_wr_ptr bit3 */
			{ 2205,24,0}, /* core7 sram_wr_ptr bit4 */
			{13668,50,1}, /* core7 sram_wr_ptr bit5 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit6 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit7 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit8 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit9 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit10 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit11 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit12 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit13 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit14 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit15 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit16 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit17 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit18 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit19 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit20 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit21 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit22 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit23 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit24 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit25 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit26 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit27 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit28 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit29 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit30 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit31 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit32 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit33 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit34 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit35 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit36 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit37 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit38 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit39 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit40 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit41 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit42 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit43 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit44 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit45 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit46 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit47 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit48 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit49 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit50 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit51 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit52 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit53 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit54 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit55 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit56 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit57 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit58 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit59 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit60 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit61 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit62 */
			{    0, 0,2}, /* core7 sram_wr_ptr bit63 */
			}},
	},
};
