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
       struct reg_collector pc;
       struct reg_collector edpcsr;
       struct reg_collector spmc_power_state;
       struct reg_collector i0_valid;
       struct reg_collector i0_pc;
       struct reg_collector i1_valid;
       struct reg_collector i1_pc;
       struct reg_collector last_branch;
       struct reg_collector sram_wr_ptr;
};

struct little_core_spec little_core[] = {
	{		/* core 0 */
			.spmc_power_state = {{
			{15203,17,1}, /* core0 spmc_power_state bit0 */
			{15402,17,1}, /* core0 spmc_power_state bit1 */
			{15401,17,1}, /* core0 spmc_power_state bit2 */
			{15400,17,1}, /* core0 spmc_power_state bit3 */
			{15399,17,1}, /* core0 spmc_power_state bit4 */
			{15202,17,1}, /* core0 spmc_power_state bit5 */
			{    0, 0,2}, /* core0 spmc_power_state bit6 */
			{    0, 0,2}, /* core0 spmc_power_state bit7 */
			{    0, 0,2}, /* core0 spmc_power_state bit8 */
			{    0, 0,2}, /* core0 spmc_power_state bit9 */
			{    0, 0,2}, /* core0 spmc_power_state bit10 */
			{    0, 0,2}, /* core0 spmc_power_state bit11 */
			{    0, 0,2}, /* core0 spmc_power_state bit12 */
			{    0, 0,2}, /* core0 spmc_power_state bit13 */
			{    0, 0,2}, /* core0 spmc_power_state bit14 */
			{    0, 0,2}, /* core0 spmc_power_state bit15 */
			{    0, 0,2}, /* core0 spmc_power_state bit16 */
			{    0, 0,2}, /* core0 spmc_power_state bit17 */
			{    0, 0,2}, /* core0 spmc_power_state bit18 */
			{    0, 0,2}, /* core0 spmc_power_state bit19 */
			{    0, 0,2}, /* core0 spmc_power_state bit20 */
			{    0, 0,2}, /* core0 spmc_power_state bit21 */
			{    0, 0,2}, /* core0 spmc_power_state bit22 */
			{    0, 0,2}, /* core0 spmc_power_state bit23 */
			{    0, 0,2}, /* core0 spmc_power_state bit24 */
			{    0, 0,2}, /* core0 spmc_power_state bit25 */
			{    0, 0,2}, /* core0 spmc_power_state bit26 */
			{    0, 0,2}, /* core0 spmc_power_state bit27 */
			{    0, 0,2}, /* core0 spmc_power_state bit28 */
			{    0, 0,2}, /* core0 spmc_power_state bit29 */
			{    0, 0,2}, /* core0 spmc_power_state bit30 */
			{    0, 0,2}, /* core0 spmc_power_state bit31 */
			{    0, 0,2}, /* core0 spmc_power_state bit32 */
			{    0, 0,2}, /* core0 spmc_power_state bit33 */
			{    0, 0,2}, /* core0 spmc_power_state bit34 */
			{    0, 0,2}, /* core0 spmc_power_state bit35 */
			{    0, 0,2}, /* core0 spmc_power_state bit36 */
			{    0, 0,2}, /* core0 spmc_power_state bit37 */
			{    0, 0,2}, /* core0 spmc_power_state bit38 */
			{    0, 0,2}, /* core0 spmc_power_state bit39 */
			{    0, 0,2}, /* core0 spmc_power_state bit40 */
			{    0, 0,2}, /* core0 spmc_power_state bit41 */
			{    0, 0,2}, /* core0 spmc_power_state bit42 */
			{    0, 0,2}, /* core0 spmc_power_state bit43 */
			{    0, 0,2}, /* core0 spmc_power_state bit44 */
			{    0, 0,2}, /* core0 spmc_power_state bit45 */
			{    0, 0,2}, /* core0 spmc_power_state bit46 */
			{    0, 0,2}, /* core0 spmc_power_state bit47 */
			{    0, 0,2}, /* core0 spmc_power_state bit48 */
			{    0, 0,2}, /* core0 spmc_power_state bit49 */
			{    0, 0,2}, /* core0 spmc_power_state bit50 */
			{    0, 0,2}, /* core0 spmc_power_state bit51 */
			{    0, 0,2}, /* core0 spmc_power_state bit52 */
			{    0, 0,2}, /* core0 spmc_power_state bit53 */
			{    0, 0,2}, /* core0 spmc_power_state bit54 */
			{    0, 0,2}, /* core0 spmc_power_state bit55 */
			{    0, 0,2}, /* core0 spmc_power_state bit56 */
			{    0, 0,2}, /* core0 spmc_power_state bit57 */
			{    0, 0,2}, /* core0 spmc_power_state bit58 */
			{    0, 0,2}, /* core0 spmc_power_state bit59 */
			{    0, 0,2}, /* core0 spmc_power_state bit60 */
			{    0, 0,2}, /* core0 spmc_power_state bit61 */
			{    0, 0,2}, /* core0 spmc_power_state bit62 */
			{    0, 0,2}, /* core0 spmc_power_state bit63 */
			}},
			.pc = {{
			{23998, 1,1}, /* core0 pc bit0 */
			{24031, 1,1}, /* core0 pc bit1 */
			{24033, 1,1}, /* core0 pc bit2 */
			{24014, 1,1}, /* core0 pc bit3 */
			{24032, 1,1}, /* core0 pc bit4 */
			{24025, 1,1}, /* core0 pc bit5 */
			{16287, 1,1}, /* core0 pc bit6 */
			{24024, 1,1}, /* core0 pc bit7 */
			{16286, 1,1}, /* core0 pc bit8 */
			{24030, 1,1}, /* core0 pc bit9 */
			{24051, 1,1}, /* core0 pc bit10 */
			{ 9105, 0,1}, /* core0 pc bit11 */
			{ 9104, 0,1}, /* core0 pc bit12 */
			{23975, 1,1}, /* core0 pc bit13 */
			{24045, 1,1}, /* core0 pc bit14 */
			{24044, 1,1}, /* core0 pc bit15 */
			{24050, 1,1}, /* core0 pc bit16 */
			{24053, 1,1}, /* core0 pc bit17 */
			{24052, 1,1}, /* core0 pc bit18 */
			{24003, 1,1}, /* core0 pc bit19 */
			{24002, 1,1}, /* core0 pc bit20 */
			{24147, 1,1}, /* core0 pc bit21 */
			{24037, 1,1}, /* core0 pc bit22 */
			{ 9103, 0,1}, /* core0 pc bit23 */
			{24036, 1,1}, /* core0 pc bit24 */
			{24133, 1,1}, /* core0 pc bit25 */
			{ 9102, 0,1}, /* core0 pc bit26 */
			{23168, 1,1}, /* core0 pc bit27 */
			{24146, 1,1}, /* core0 pc bit28 */
			{23167, 1,1}, /* core0 pc bit29 */
			{24043, 1,1}, /* core0 pc bit30 */
			{24042, 1,1}, /* core0 pc bit31 */
			{23959, 1,1}, /* core0 pc bit32 */
			{23958, 1,1}, /* core0 pc bit33 */
			{23993, 1,1}, /* core0 pc bit34 */
			{23992, 1,1}, /* core0 pc bit35 */
			{24149, 1,1}, /* core0 pc bit36 */
			{24132, 1,1}, /* core0 pc bit37 */
			{23961, 1,1}, /* core0 pc bit38 */
			{23960, 1,1}, /* core0 pc bit39 */
			{23957, 1,1}, /* core0 pc bit40 */
			{23956, 1,1}, /* core0 pc bit41 */
			{23967, 1,1}, /* core0 pc bit42 */
			{24148, 1,1}, /* core0 pc bit43 */
			{22945, 0,1}, /* core0 pc bit44 */
			{22944, 0,1}, /* core0 pc bit45 */
			{23987, 1,1}, /* core0 pc bit46 */
			{23966, 1,1}, /* core0 pc bit47 */
			{23991, 1,1}, /* core0 pc bit48 */
			{23989, 1,1}, /* core0 pc bit49 */
			{23990, 1,1}, /* core0 pc bit50 */
			{23965, 1,1}, /* core0 pc bit51 */
			{23964, 1,1}, /* core0 pc bit52 */
			{23988, 1,1}, /* core0 pc bit53 */
			{24107, 1,1}, /* core0 pc bit54 */
			{24106, 1,1}, /* core0 pc bit55 */
			{23068, 1,1}, /* core0 pc bit56 */
			{ 9101, 0,1}, /* core0 pc bit57 */
			{23150, 1,1}, /* core0 pc bit58 */
			{23986, 1,1}, /* core0 pc bit59 */
			{23963, 1,1}, /* core0 pc bit60 */
			{ 9100, 0,1}, /* core0 pc bit61 */
			{23962, 1,1}, /* core0 pc bit62 */
			{23151, 1,1}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{10987, 0,1}, /* core0 sp32 bit0 */
			{10986, 0,1}, /* core0 sp32 bit1 */
			{23581, 0,1}, /* core0 sp32 bit2 */
			{23580, 0,1}, /* core0 sp32 bit3 */
			{10989, 0,1}, /* core0 sp32 bit4 */
			{23571, 0,1}, /* core0 sp32 bit5 */
			{23577, 0,1}, /* core0 sp32 bit6 */
			{16267, 1,1}, /* core0 sp32 bit7 */
			{10988, 0,1}, /* core0 sp32 bit8 */
			{23576, 0,1}, /* core0 sp32 bit9 */
			{16251, 1,1}, /* core0 sp32 bit10 */
			{23570, 0,1}, /* core0 sp32 bit11 */
			{16250, 1,1}, /* core0 sp32 bit12 */
			{23575, 0,1}, /* core0 sp32 bit13 */
			{23574, 0,1}, /* core0 sp32 bit14 */
			{16269, 1,1}, /* core0 sp32 bit15 */
			{16268, 1,1}, /* core0 sp32 bit16 */
			{16265, 1,1}, /* core0 sp32 bit17 */
			{16264, 1,1}, /* core0 sp32 bit18 */
			{16247, 1,1}, /* core0 sp32 bit19 */
			{23579, 0,1}, /* core0 sp32 bit20 */
			{23578, 0,1}, /* core0 sp32 bit21 */
			{16266, 1,1}, /* core0 sp32 bit22 */
			{24021, 1,1}, /* core0 sp32 bit23 */
			{16246, 1,1}, /* core0 sp32 bit24 */
			{16249, 1,1}, /* core0 sp32 bit25 */
			{24020, 1,1}, /* core0 sp32 bit26 */
			{16271, 1,1}, /* core0 sp32 bit27 */
			{16248, 1,1}, /* core0 sp32 bit28 */
			{23573, 0,1}, /* core0 sp32 bit29 */
			{23572, 0,1}, /* core0 sp32 bit30 */
			{16270, 1,1}, /* core0 sp32 bit31 */
			{13203, 0,1}, /* core0 sp32 bit32 */
			{13202, 0,1}, /* core0 sp32 bit33 */
			{13205, 0,1}, /* core0 sp32 bit34 */
			{13204, 0,1}, /* core0 sp32 bit35 */
			{13243, 0,1}, /* core0 sp32 bit36 */
			{13242, 0,1}, /* core0 sp32 bit37 */
			{12299, 0,1}, /* core0 sp32 bit38 */
			{13201, 0,1}, /* core0 sp32 bit39 */
			{13200, 0,1}, /* core0 sp32 bit40 */
			{12297, 0,1}, /* core0 sp32 bit41 */
			{12296, 0,1}, /* core0 sp32 bit42 */
			{12298, 0,1}, /* core0 sp32 bit43 */
			{13241, 0,1}, /* core0 sp32 bit44 */
			{13240, 0,1}, /* core0 sp32 bit45 */
			{13777, 0,1}, /* core0 sp32 bit46 */
			{13187, 0,1}, /* core0 sp32 bit47 */
			{13185, 0,1}, /* core0 sp32 bit48 */
			{13186, 0,1}, /* core0 sp32 bit49 */
			{13184, 0,1}, /* core0 sp32 bit50 */
			{12289, 0,1}, /* core0 sp32 bit51 */
			{12288, 0,1}, /* core0 sp32 bit52 */
			{13207, 0,1}, /* core0 sp32 bit53 */
			{13239, 0,1}, /* core0 sp32 bit54 */
			{13238, 0,1}, /* core0 sp32 bit55 */
			{13211, 0,1}, /* core0 sp32 bit56 */
			{13206, 0,1}, /* core0 sp32 bit57 */
			{12291, 0,1}, /* core0 sp32 bit58 */
			{12290, 0,1}, /* core0 sp32 bit59 */
			{13209, 0,1}, /* core0 sp32 bit60 */
			{13208, 0,1}, /* core0 sp32 bit61 */
			{13750, 0,1}, /* core0 sp32 bit62 */
			{13210, 0,1}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{16193, 1,1}, /* core0 fp32 bit0 */
			{16192, 1,1}, /* core0 fp32 bit1 */
			{16197, 1,1}, /* core0 fp32 bit2 */
			{16196, 1,1}, /* core0 fp32 bit3 */
			{16207, 1,1}, /* core0 fp32 bit4 */
			{16203, 1,1}, /* core0 fp32 bit5 */
			{16205, 1,1}, /* core0 fp32 bit6 */
			{16204, 1,1}, /* core0 fp32 bit7 */
			{16161, 1,1}, /* core0 fp32 bit8 */
			{16160, 1,1}, /* core0 fp32 bit9 */
			{16209, 1,1}, /* core0 fp32 bit10 */
			{16202, 1,1}, /* core0 fp32 bit11 */
			{16208, 1,1}, /* core0 fp32 bit12 */
			{11941, 0,1}, /* core0 fp32 bit13 */
			{11935, 0,1}, /* core0 fp32 bit14 */
			{16159, 1,1}, /* core0 fp32 bit15 */
			{11940, 0,1}, /* core0 fp32 bit16 */
			{16206, 1,1}, /* core0 fp32 bit17 */
			{16199, 1,1}, /* core0 fp32 bit18 */
			{16198, 1,1}, /* core0 fp32 bit19 */
			{11934, 0,1}, /* core0 fp32 bit20 */
			{16201, 1,1}, /* core0 fp32 bit21 */
			{16200, 1,1}, /* core0 fp32 bit22 */
			{11925, 0,1}, /* core0 fp32 bit23 */
			{11924, 0,1}, /* core0 fp32 bit24 */
			{11937, 0,1}, /* core0 fp32 bit25 */
			{16195, 1,1}, /* core0 fp32 bit26 */
			{13733, 0,1}, /* core0 fp32 bit27 */
			{11936, 0,1}, /* core0 fp32 bit28 */
			{16194, 1,1}, /* core0 fp32 bit29 */
			{11939, 0,1}, /* core0 fp32 bit30 */
			{11938, 0,1}, /* core0 fp32 bit31 */
			{14669, 0,1}, /* core0 fp32 bit32 */
			{14668, 0,1}, /* core0 fp32 bit33 */
			{14671, 0,1}, /* core0 fp32 bit34 */
			{14670, 0,1}, /* core0 fp32 bit35 */
			{14645, 0,1}, /* core0 fp32 bit36 */
			{14644, 0,1}, /* core0 fp32 bit37 */
			{14647, 0,1}, /* core0 fp32 bit38 */
			{14646, 0,1}, /* core0 fp32 bit39 */
			{13771, 0,1}, /* core0 fp32 bit40 */
			{14651, 0,1}, /* core0 fp32 bit41 */
			{14650, 0,1}, /* core0 fp32 bit42 */
			{14653, 0,1}, /* core0 fp32 bit43 */
			{14652, 0,1}, /* core0 fp32 bit44 */
			{14657, 0,1}, /* core0 fp32 bit45 */
			{14656, 0,1}, /* core0 fp32 bit46 */
			{14641, 0,1}, /* core0 fp32 bit47 */
			{14640, 0,1}, /* core0 fp32 bit48 */
			{14649, 0,1}, /* core0 fp32 bit49 */
			{14648, 0,1}, /* core0 fp32 bit50 */
			{14643, 0,1}, /* core0 fp32 bit51 */
			{14642, 0,1}, /* core0 fp32 bit52 */
			{14661, 0,1}, /* core0 fp32 bit53 */
			{14665, 0,1}, /* core0 fp32 bit54 */
			{14660, 0,1}, /* core0 fp32 bit55 */
			{14664, 0,1}, /* core0 fp32 bit56 */
			{14667, 0,1}, /* core0 fp32 bit57 */
			{14663, 0,1}, /* core0 fp32 bit58 */
			{14662, 0,1}, /* core0 fp32 bit59 */
			{14666, 0,1}, /* core0 fp32 bit60 */
			{14659, 0,1}, /* core0 fp32 bit61 */
			{14658, 0,1}, /* core0 fp32 bit62 */
			{13769, 0,1}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{10273, 0,1}, /* core0 fp64 bit0 */
			{10272, 0,1}, /* core0 fp64 bit1 */
			{10271, 0,1}, /* core0 fp64 bit2 */
			{10270, 0,1}, /* core0 fp64 bit3 */
			{16293, 1,1}, /* core0 fp64 bit4 */
			{16292, 1,1}, /* core0 fp64 bit5 */
			{16275, 1,1}, /* core0 fp64 bit6 */
			{16274, 1,1}, /* core0 fp64 bit7 */
			{16297, 1,1}, /* core0 fp64 bit8 */
			{16296, 1,1}, /* core0 fp64 bit9 */
			{16273, 1,1}, /* core0 fp64 bit10 */
			{16279, 1,1}, /* core0 fp64 bit11 */
			{16272, 1,1}, /* core0 fp64 bit12 */
			{16291, 1,1}, /* core0 fp64 bit13 */
			{16257, 1,1}, /* core0 fp64 bit14 */
			{16290, 1,1}, /* core0 fp64 bit15 */
			{24023, 1,1}, /* core0 fp64 bit16 */
			{16278, 1,1}, /* core0 fp64 bit17 */
			{16281, 1,1}, /* core0 fp64 bit18 */
			{16280, 1,1}, /* core0 fp64 bit19 */
			{16256, 1,1}, /* core0 fp64 bit20 */
			{16259, 1,1}, /* core0 fp64 bit21 */
			{16317, 1,1}, /* core0 fp64 bit22 */
			{16316, 1,1}, /* core0 fp64 bit23 */
			{16295, 1,1}, /* core0 fp64 bit24 */
			{16258, 1,1}, /* core0 fp64 bit25 */
			{16277, 1,1}, /* core0 fp64 bit26 */
			{24022, 1,1}, /* core0 fp64 bit27 */
			{16294, 1,1}, /* core0 fp64 bit28 */
			{16276, 1,1}, /* core0 fp64 bit29 */
			{16283, 1,1}, /* core0 fp64 bit30 */
			{16282, 1,1}, /* core0 fp64 bit31 */
			{ 9757, 0,1}, /* core0 fp64 bit32 */
			{ 9756, 0,1}, /* core0 fp64 bit33 */
			{ 9751, 0,1}, /* core0 fp64 bit34 */
			{ 9750, 0,1}, /* core0 fp64 bit35 */
			{ 9729, 0,1}, /* core0 fp64 bit36 */
			{ 9755, 0,1}, /* core0 fp64 bit37 */
			{ 9754, 0,1}, /* core0 fp64 bit38 */
			{ 9731, 0,1}, /* core0 fp64 bit39 */
			{ 9728, 0,1}, /* core0 fp64 bit40 */
			{ 9730, 0,1}, /* core0 fp64 bit41 */
			{ 9721, 0,1}, /* core0 fp64 bit42 */
			{13801, 0,1}, /* core0 fp64 bit43 */
			{ 9720, 0,1}, /* core0 fp64 bit44 */
			{ 9733, 0,1}, /* core0 fp64 bit45 */
			{ 9732, 0,1}, /* core0 fp64 bit46 */
			{ 9725, 0,1}, /* core0 fp64 bit47 */
			{ 9727, 0,1}, /* core0 fp64 bit48 */
			{ 9726, 0,1}, /* core0 fp64 bit49 */
			{ 9724, 0,1}, /* core0 fp64 bit50 */
			{ 9763, 0,1}, /* core0 fp64 bit51 */
			{ 9753, 0,1}, /* core0 fp64 bit52 */
			{ 9752, 0,1}, /* core0 fp64 bit53 */
			{ 9759, 0,1}, /* core0 fp64 bit54 */
			{ 9758, 0,1}, /* core0 fp64 bit55 */
			{ 9762, 0,1}, /* core0 fp64 bit56 */
			{ 9719, 0,1}, /* core0 fp64 bit57 */
			{13800, 0,1}, /* core0 fp64 bit58 */
			{ 9718, 0,1}, /* core0 fp64 bit59 */
			{ 9761, 0,1}, /* core0 fp64 bit60 */
			{ 9760, 0,1}, /* core0 fp64 bit61 */
			{ 9723, 0,1}, /* core0 fp64 bit62 */
			{ 9722, 0,1}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{12529, 0,1}, /* core0 sp_EL0 bit0 */
			{10485, 0,1}, /* core0 sp_EL0 bit1 */
			{10484, 0,1}, /* core0 sp_EL0 bit2 */
			{12527, 0,1}, /* core0 sp_EL0 bit3 */
			{10489, 0,1}, /* core0 sp_EL0 bit4 */
			{10488, 0,1}, /* core0 sp_EL0 bit5 */
			{12526, 0,1}, /* core0 sp_EL0 bit6 */
			{12528, 0,1}, /* core0 sp_EL0 bit7 */
			{12531, 0,1}, /* core0 sp_EL0 bit8 */
			{12530, 0,1}, /* core0 sp_EL0 bit9 */
			{12439, 0,1}, /* core0 sp_EL0 bit10 */
			{12523, 0,1}, /* core0 sp_EL0 bit11 */
			{10487, 0,1}, /* core0 sp_EL0 bit12 */
			{12438, 0,1}, /* core0 sp_EL0 bit13 */
			{12429, 0,1}, /* core0 sp_EL0 bit14 */
			{10486, 0,1}, /* core0 sp_EL0 bit15 */
			{13720, 0,1}, /* core0 sp_EL0 bit16 */
			{12428, 0,1}, /* core0 sp_EL0 bit17 */
			{12437, 0,1}, /* core0 sp_EL0 bit18 */
			{12436, 0,1}, /* core0 sp_EL0 bit19 */
			{12522, 0,1}, /* core0 sp_EL0 bit20 */
			{12525, 0,1}, /* core0 sp_EL0 bit21 */
			{12431, 0,1}, /* core0 sp_EL0 bit22 */
			{12430, 0,1}, /* core0 sp_EL0 bit23 */
			{12521, 0,1}, /* core0 sp_EL0 bit24 */
			{12524, 0,1}, /* core0 sp_EL0 bit25 */
			{12427, 0,1}, /* core0 sp_EL0 bit26 */
			{13721, 0,1}, /* core0 sp_EL0 bit27 */
			{12520, 0,1}, /* core0 sp_EL0 bit28 */
			{12426, 0,1}, /* core0 sp_EL0 bit29 */
			{12441, 0,1}, /* core0 sp_EL0 bit30 */
			{12440, 0,1}, /* core0 sp_EL0 bit31 */
			{12829, 0,1}, /* core0 sp_EL0 bit32 */
			{12828, 0,1}, /* core0 sp_EL0 bit33 */
			{12823, 0,1}, /* core0 sp_EL0 bit34 */
			{11205, 0,1}, /* core0 sp_EL0 bit35 */
			{12822, 0,1}, /* core0 sp_EL0 bit36 */
			{11213, 0,1}, /* core0 sp_EL0 bit37 */
			{11212, 0,1}, /* core0 sp_EL0 bit38 */
			{11211, 0,1}, /* core0 sp_EL0 bit39 */
			{11210, 0,1}, /* core0 sp_EL0 bit40 */
			{11204, 0,1}, /* core0 sp_EL0 bit41 */
			{11201, 0,1}, /* core0 sp_EL0 bit42 */
			{11200, 0,1}, /* core0 sp_EL0 bit43 */
			{12827, 0,1}, /* core0 sp_EL0 bit44 */
			{12826, 0,1}, /* core0 sp_EL0 bit45 */
			{14527, 0,1}, /* core0 sp_EL0 bit46 */
			{11217, 0,1}, /* core0 sp_EL0 bit47 */
			{11216, 0,1}, /* core0 sp_EL0 bit48 */
			{11207, 0,1}, /* core0 sp_EL0 bit49 */
			{12821, 0,1}, /* core0 sp_EL0 bit50 */
			{11206, 0,1}, /* core0 sp_EL0 bit51 */
			{12820, 0,1}, /* core0 sp_EL0 bit52 */
			{11219, 0,1}, /* core0 sp_EL0 bit53 */
			{11218, 0,1}, /* core0 sp_EL0 bit54 */
			{14231, 0,1}, /* core0 sp_EL0 bit55 */
			{12825, 0,1}, /* core0 sp_EL0 bit56 */
			{12824, 0,1}, /* core0 sp_EL0 bit57 */
			{11215, 0,1}, /* core0 sp_EL0 bit58 */
			{11214, 0,1}, /* core0 sp_EL0 bit59 */
			{11203, 0,1}, /* core0 sp_EL0 bit60 */
			{11202, 0,1}, /* core0 sp_EL0 bit61 */
			{14526, 0,1}, /* core0 sp_EL0 bit62 */
			{14528, 0,1}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{10269, 0,1}, /* core0 sp_EL1 bit0 */
			{10268, 0,1}, /* core0 sp_EL1 bit1 */
			{10267, 0,1}, /* core0 sp_EL1 bit2 */
			{10266, 0,1}, /* core0 sp_EL1 bit3 */
			{16243, 1,1}, /* core0 sp_EL1 bit4 */
			{16242, 1,1}, /* core0 sp_EL1 bit5 */
			{10991, 0,1}, /* core0 sp_EL1 bit6 */
			{10990, 0,1}, /* core0 sp_EL1 bit7 */
			{16255, 1,1}, /* core0 sp_EL1 bit8 */
			{16254, 1,1}, /* core0 sp_EL1 bit9 */
			{16263, 1,1}, /* core0 sp_EL1 bit10 */
			{16237, 1,1}, /* core0 sp_EL1 bit11 */
			{16262, 1,1}, /* core0 sp_EL1 bit12 */
			{16245, 1,1}, /* core0 sp_EL1 bit13 */
			{16236, 1,1}, /* core0 sp_EL1 bit14 */
			{16253, 1,1}, /* core0 sp_EL1 bit15 */
			{16252, 1,1}, /* core0 sp_EL1 bit16 */
			{16233, 1,1}, /* core0 sp_EL1 bit17 */
			{16232, 1,1}, /* core0 sp_EL1 bit18 */
			{16235, 1,1}, /* core0 sp_EL1 bit19 */
			{10985, 0,1}, /* core0 sp_EL1 bit20 */
			{16234, 1,1}, /* core0 sp_EL1 bit21 */
			{16244, 1,1}, /* core0 sp_EL1 bit22 */
			{16239, 1,1}, /* core0 sp_EL1 bit23 */
			{23070, 1,1}, /* core0 sp_EL1 bit24 */
			{10984, 0,1}, /* core0 sp_EL1 bit25 */
			{16261, 1,1}, /* core0 sp_EL1 bit26 */
			{16260, 1,1}, /* core0 sp_EL1 bit27 */
			{16238, 1,1}, /* core0 sp_EL1 bit28 */
			{23069, 1,1}, /* core0 sp_EL1 bit29 */
			{16241, 1,1}, /* core0 sp_EL1 bit30 */
			{16240, 1,1}, /* core0 sp_EL1 bit31 */
			{24089, 0,1}, /* core0 sp_EL1 bit32 */
			{24088, 0,1}, /* core0 sp_EL1 bit33 */
			{12803, 0,1}, /* core0 sp_EL1 bit34 */
			{11221, 0,1}, /* core0 sp_EL1 bit35 */
			{11220, 0,1}, /* core0 sp_EL1 bit36 */
			{12799, 0,1}, /* core0 sp_EL1 bit37 */
			{12798, 0,1}, /* core0 sp_EL1 bit38 */
			{24091, 0,1}, /* core0 sp_EL1 bit39 */
			{24090, 0,1}, /* core0 sp_EL1 bit40 */
			{12802, 0,1}, /* core0 sp_EL1 bit41 */
			{12807, 0,1}, /* core0 sp_EL1 bit42 */
			{12801, 0,1}, /* core0 sp_EL1 bit43 */
			{12800, 0,1}, /* core0 sp_EL1 bit44 */
			{14517, 0,1}, /* core0 sp_EL1 bit45 */
			{12806, 0,1}, /* core0 sp_EL1 bit46 */
			{12809, 0,1}, /* core0 sp_EL1 bit47 */
			{12808, 0,1}, /* core0 sp_EL1 bit48 */
			{12797, 0,1}, /* core0 sp_EL1 bit49 */
			{24085, 0,1}, /* core0 sp_EL1 bit50 */
			{24084, 0,1}, /* core0 sp_EL1 bit51 */
			{12805, 0,1}, /* core0 sp_EL1 bit52 */
			{12796, 0,1}, /* core0 sp_EL1 bit53 */
			{12804, 0,1}, /* core0 sp_EL1 bit54 */
			{24081, 0,1}, /* core0 sp_EL1 bit55 */
			{24080, 0,1}, /* core0 sp_EL1 bit56 */
			{24087, 0,1}, /* core0 sp_EL1 bit57 */
			{14515, 0,1}, /* core0 sp_EL1 bit58 */
			{24086, 0,1}, /* core0 sp_EL1 bit59 */
			{24083, 0,1}, /* core0 sp_EL1 bit60 */
			{24082, 0,1}, /* core0 sp_EL1 bit61 */
			{14516, 0,1}, /* core0 sp_EL1 bit62 */
			{14514, 0,1}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{10265, 0,1}, /* core0 sp_EL2 bit0 */
			{10264, 0,1}, /* core0 sp_EL2 bit1 */
			{10263, 0,1}, /* core0 sp_EL2 bit2 */
			{10262, 0,1}, /* core0 sp_EL2 bit3 */
			{12503, 0,1}, /* core0 sp_EL2 bit4 */
			{12502, 0,1}, /* core0 sp_EL2 bit5 */
			{12549, 0,1}, /* core0 sp_EL2 bit6 */
			{12548, 0,1}, /* core0 sp_EL2 bit7 */
			{12507, 0,1}, /* core0 sp_EL2 bit8 */
			{12506, 0,1}, /* core0 sp_EL2 bit9 */
			{12509, 0,1}, /* core0 sp_EL2 bit10 */
			{12559, 0,1}, /* core0 sp_EL2 bit11 */
			{12508, 0,1}, /* core0 sp_EL2 bit12 */
			{12505, 0,1}, /* core0 sp_EL2 bit13 */
			{12551, 0,1}, /* core0 sp_EL2 bit14 */
			{12547, 0,1}, /* core0 sp_EL2 bit15 */
			{12546, 0,1}, /* core0 sp_EL2 bit16 */
			{12558, 0,1}, /* core0 sp_EL2 bit17 */
			{12557, 0,1}, /* core0 sp_EL2 bit18 */
			{12556, 0,1}, /* core0 sp_EL2 bit19 */
			{12550, 0,1}, /* core0 sp_EL2 bit20 */
			{12553, 0,1}, /* core0 sp_EL2 bit21 */
			{12501, 0,1}, /* core0 sp_EL2 bit22 */
			{14539, 0,1}, /* core0 sp_EL2 bit23 */
			{12500, 0,1}, /* core0 sp_EL2 bit24 */
			{12555, 0,1}, /* core0 sp_EL2 bit25 */
			{12504, 0,1}, /* core0 sp_EL2 bit26 */
			{12552, 0,1}, /* core0 sp_EL2 bit27 */
			{12554, 0,1}, /* core0 sp_EL2 bit28 */
			{13717, 0,1}, /* core0 sp_EL2 bit29 */
			{12499, 0,1}, /* core0 sp_EL2 bit30 */
			{12498, 0,1}, /* core0 sp_EL2 bit31 */
			{12765, 0,1}, /* core0 sp_EL2 bit32 */
			{12764, 0,1}, /* core0 sp_EL2 bit33 */
			{12853, 0,1}, /* core0 sp_EL2 bit34 */
			{12761, 0,1}, /* core0 sp_EL2 bit35 */
			{12760, 0,1}, /* core0 sp_EL2 bit36 */
			{12852, 0,1}, /* core0 sp_EL2 bit37 */
			{12851, 0,1}, /* core0 sp_EL2 bit38 */
			{12850, 0,1}, /* core0 sp_EL2 bit39 */
			{14520, 0,1}, /* core0 sp_EL2 bit40 */
			{12855, 0,1}, /* core0 sp_EL2 bit41 */
			{12854, 0,1}, /* core0 sp_EL2 bit42 */
			{12863, 0,1}, /* core0 sp_EL2 bit43 */
			{12862, 0,1}, /* core0 sp_EL2 bit44 */
			{12763, 0,1}, /* core0 sp_EL2 bit45 */
			{12762, 0,1}, /* core0 sp_EL2 bit46 */
			{12857, 0,1}, /* core0 sp_EL2 bit47 */
			{12859, 0,1}, /* core0 sp_EL2 bit48 */
			{12858, 0,1}, /* core0 sp_EL2 bit49 */
			{12856, 0,1}, /* core0 sp_EL2 bit50 */
			{12865, 0,1}, /* core0 sp_EL2 bit51 */
			{12867, 0,1}, /* core0 sp_EL2 bit52 */
			{12866, 0,1}, /* core0 sp_EL2 bit53 */
			{12864, 0,1}, /* core0 sp_EL2 bit54 */
			{12861, 0,1}, /* core0 sp_EL2 bit55 */
			{12860, 0,1}, /* core0 sp_EL2 bit56 */
			{12871, 0,1}, /* core0 sp_EL2 bit57 */
			{12870, 0,1}, /* core0 sp_EL2 bit58 */
			{12759, 0,1}, /* core0 sp_EL2 bit59 */
			{12758, 0,1}, /* core0 sp_EL2 bit60 */
			{12869, 0,1}, /* core0 sp_EL2 bit61 */
			{12868, 0,1}, /* core0 sp_EL2 bit62 */
			{14445, 0,1}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{12453, 0,1}, /* core0 sp_EL3 bit0 */
			{12452, 0,1}, /* core0 sp_EL3 bit1 */
			{12513, 0,1}, /* core0 sp_EL3 bit2 */
			{12447, 0,1}, /* core0 sp_EL3 bit3 */
			{12515, 0,1}, /* core0 sp_EL3 bit4 */
			{12514, 0,1}, /* core0 sp_EL3 bit5 */
			{12446, 0,1}, /* core0 sp_EL3 bit6 */
			{12443, 0,1}, /* core0 sp_EL3 bit7 */
			{12512, 0,1}, /* core0 sp_EL3 bit8 */
			{12511, 0,1}, /* core0 sp_EL3 bit9 */
			{12442, 0,1}, /* core0 sp_EL3 bit10 */
			{12423, 0,1}, /* core0 sp_EL3 bit11 */
			{12445, 0,1}, /* core0 sp_EL3 bit12 */
			{12510, 0,1}, /* core0 sp_EL3 bit13 */
			{12449, 0,1}, /* core0 sp_EL3 bit14 */
			{12444, 0,1}, /* core0 sp_EL3 bit15 */
			{14538, 0,1}, /* core0 sp_EL3 bit16 */
			{12422, 0,1}, /* core0 sp_EL3 bit17 */
			{12451, 0,1}, /* core0 sp_EL3 bit18 */
			{12450, 0,1}, /* core0 sp_EL3 bit19 */
			{12448, 0,1}, /* core0 sp_EL3 bit20 */
			{12457, 0,1}, /* core0 sp_EL3 bit21 */
			{12459, 0,1}, /* core0 sp_EL3 bit22 */
			{12456, 0,1}, /* core0 sp_EL3 bit23 */
			{12458, 0,1}, /* core0 sp_EL3 bit24 */
			{12455, 0,1}, /* core0 sp_EL3 bit25 */
			{12425, 0,1}, /* core0 sp_EL3 bit26 */
			{12424, 0,1}, /* core0 sp_EL3 bit27 */
			{12461, 0,1}, /* core0 sp_EL3 bit28 */
			{12454, 0,1}, /* core0 sp_EL3 bit29 */
			{12460, 0,1}, /* core0 sp_EL3 bit30 */
			{13716, 0,1}, /* core0 sp_EL3 bit31 */
			{12115, 0,1}, /* core0 sp_EL3 bit32 */
			{12114, 0,1}, /* core0 sp_EL3 bit33 */
			{14149, 0,1}, /* core0 sp_EL3 bit34 */
			{23991, 0,1}, /* core0 sp_EL3 bit35 */
			{14148, 0,1}, /* core0 sp_EL3 bit36 */
			{14147, 0,1}, /* core0 sp_EL3 bit37 */
			{14146, 0,1}, /* core0 sp_EL3 bit38 */
			{24247, 0,1}, /* core0 sp_EL3 bit39 */
			{24246, 0,1}, /* core0 sp_EL3 bit40 */
			{23990, 0,1}, /* core0 sp_EL3 bit41 */
			{23993, 0,1}, /* core0 sp_EL3 bit42 */
			{23992, 0,1}, /* core0 sp_EL3 bit43 */
			{12113, 0,1}, /* core0 sp_EL3 bit44 */
			{12112, 0,1}, /* core0 sp_EL3 bit45 */
			{14510, 0,1}, /* core0 sp_EL3 bit46 */
			{14143, 0,1}, /* core0 sp_EL3 bit47 */
			{14142, 0,1}, /* core0 sp_EL3 bit48 */
			{14061, 0,1}, /* core0 sp_EL3 bit49 */
			{14060, 0,1}, /* core0 sp_EL3 bit50 */
			{24245, 0,1}, /* core0 sp_EL3 bit51 */
			{24244, 0,1}, /* core0 sp_EL3 bit52 */
			{14509, 0,1}, /* core0 sp_EL3 bit53 */
			{14145, 0,1}, /* core0 sp_EL3 bit54 */
			{14144, 0,1}, /* core0 sp_EL3 bit55 */
			{12111, 0,1}, /* core0 sp_EL3 bit56 */
			{12110, 0,1}, /* core0 sp_EL3 bit57 */
			{14063, 0,1}, /* core0 sp_EL3 bit58 */
			{14062, 0,1}, /* core0 sp_EL3 bit59 */
			{24249, 0,1}, /* core0 sp_EL3 bit60 */
			{24248, 0,1}, /* core0 sp_EL3 bit61 */
			{14501, 0,1}, /* core0 sp_EL3 bit62 */
			{14508, 0,1}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{10491, 0,1}, /* core0 elr_EL1 bit0 */
			{10490, 0,1}, /* core0 elr_EL1 bit1 */
			{10493, 0,1}, /* core0 elr_EL1 bit2 */
			{13718, 0,1}, /* core0 elr_EL1 bit3 */
			{12545, 0,1}, /* core0 elr_EL1 bit4 */
			{12519, 0,1}, /* core0 elr_EL1 bit5 */
			{12539, 0,1}, /* core0 elr_EL1 bit6 */
			{12538, 0,1}, /* core0 elr_EL1 bit7 */
			{10492, 0,1}, /* core0 elr_EL1 bit8 */
			{12535, 0,1}, /* core0 elr_EL1 bit9 */
			{10499, 0,1}, /* core0 elr_EL1 bit10 */
			{12544, 0,1}, /* core0 elr_EL1 bit11 */
			{12534, 0,1}, /* core0 elr_EL1 bit12 */
			{12537, 0,1}, /* core0 elr_EL1 bit13 */
			{12518, 0,1}, /* core0 elr_EL1 bit14 */
			{12536, 0,1}, /* core0 elr_EL1 bit15 */
			{13719, 0,1}, /* core0 elr_EL1 bit16 */
			{10497, 0,1}, /* core0 elr_EL1 bit17 */
			{10496, 0,1}, /* core0 elr_EL1 bit18 */
			{10495, 0,1}, /* core0 elr_EL1 bit19 */
			{12541, 0,1}, /* core0 elr_EL1 bit20 */
			{10494, 0,1}, /* core0 elr_EL1 bit21 */
			{12517, 0,1}, /* core0 elr_EL1 bit22 */
			{12516, 0,1}, /* core0 elr_EL1 bit23 */
			{13715, 0,1}, /* core0 elr_EL1 bit24 */
			{12540, 0,1}, /* core0 elr_EL1 bit25 */
			{10498, 0,1}, /* core0 elr_EL1 bit26 */
			{12533, 0,1}, /* core0 elr_EL1 bit27 */
			{12543, 0,1}, /* core0 elr_EL1 bit28 */
			{12532, 0,1}, /* core0 elr_EL1 bit29 */
			{12542, 0,1}, /* core0 elr_EL1 bit30 */
			{13714, 0,1}, /* core0 elr_EL1 bit31 */
			{14131, 0,1}, /* core0 elr_EL1 bit32 */
			{14073, 0,1}, /* core0 elr_EL1 bit33 */
			{14072, 0,1}, /* core0 elr_EL1 bit34 */
			{14130, 0,1}, /* core0 elr_EL1 bit35 */
			{14123, 0,1}, /* core0 elr_EL1 bit36 */
			{14122, 0,1}, /* core0 elr_EL1 bit37 */
			{14125, 0,1}, /* core0 elr_EL1 bit38 */
			{14071, 0,1}, /* core0 elr_EL1 bit39 */
			{14070, 0,1}, /* core0 elr_EL1 bit40 */
			{14124, 0,1}, /* core0 elr_EL1 bit41 */
			{14133, 0,1}, /* core0 elr_EL1 bit42 */
			{14132, 0,1}, /* core0 elr_EL1 bit43 */
			{14127, 0,1}, /* core0 elr_EL1 bit44 */
			{14126, 0,1}, /* core0 elr_EL1 bit45 */
			{13802, 0,1}, /* core0 elr_EL1 bit46 */
			{14135, 0,1}, /* core0 elr_EL1 bit47 */
			{14134, 0,1}, /* core0 elr_EL1 bit48 */
			{14069, 0,1}, /* core0 elr_EL1 bit49 */
			{14068, 0,1}, /* core0 elr_EL1 bit50 */
			{14129, 0,1}, /* core0 elr_EL1 bit51 */
			{14067, 0,1}, /* core0 elr_EL1 bit52 */
			{14066, 0,1}, /* core0 elr_EL1 bit53 */
			{14141, 0,1}, /* core0 elr_EL1 bit54 */
			{14128, 0,1}, /* core0 elr_EL1 bit55 */
			{14140, 0,1}, /* core0 elr_EL1 bit56 */
			{14065, 0,1}, /* core0 elr_EL1 bit57 */
			{14064, 0,1}, /* core0 elr_EL1 bit58 */
			{14139, 0,1}, /* core0 elr_EL1 bit59 */
			{14138, 0,1}, /* core0 elr_EL1 bit60 */
			{14137, 0,1}, /* core0 elr_EL1 bit61 */
			{14136, 0,1}, /* core0 elr_EL1 bit62 */
			{14499, 0,1}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{24107, 0,1}, /* core0 elr_EL2 bit0 */
			{24106, 0,1}, /* core0 elr_EL2 bit1 */
			{11155, 0,1}, /* core0 elr_EL2 bit2 */
			{11154, 0,1}, /* core0 elr_EL2 bit3 */
			{24113, 0,1}, /* core0 elr_EL2 bit4 */
			{24112, 0,1}, /* core0 elr_EL2 bit5 */
			{11165, 0,1}, /* core0 elr_EL2 bit6 */
			{11164, 0,1}, /* core0 elr_EL2 bit7 */
			{24109, 0,1}, /* core0 elr_EL2 bit8 */
			{24108, 0,1}, /* core0 elr_EL2 bit9 */
			{24117, 0,1}, /* core0 elr_EL2 bit10 */
			{24105, 0,1}, /* core0 elr_EL2 bit11 */
			{24116, 0,1}, /* core0 elr_EL2 bit12 */
			{11161, 0,1}, /* core0 elr_EL2 bit13 */
			{24115, 0,1}, /* core0 elr_EL2 bit14 */
			{11160, 0,1}, /* core0 elr_EL2 bit15 */
			{11157, 0,1}, /* core0 elr_EL2 bit16 */
			{24104, 0,1}, /* core0 elr_EL2 bit17 */
			{11169, 0,1}, /* core0 elr_EL2 bit18 */
			{24114, 0,1}, /* core0 elr_EL2 bit19 */
			{11159, 0,1}, /* core0 elr_EL2 bit20 */
			{11158, 0,1}, /* core0 elr_EL2 bit21 */
			{11163, 0,1}, /* core0 elr_EL2 bit22 */
			{11168, 0,1}, /* core0 elr_EL2 bit23 */
			{11162, 0,1}, /* core0 elr_EL2 bit24 */
			{24111, 0,1}, /* core0 elr_EL2 bit25 */
			{11156, 0,1}, /* core0 elr_EL2 bit26 */
			{13693, 0,1}, /* core0 elr_EL2 bit27 */
			{11167, 0,1}, /* core0 elr_EL2 bit28 */
			{11166, 0,1}, /* core0 elr_EL2 bit29 */
			{14449, 0,1}, /* core0 elr_EL2 bit30 */
			{24110, 0,1}, /* core0 elr_EL2 bit31 */
			{24243, 0,1}, /* core0 elr_EL2 bit32 */
			{24075, 0,1}, /* core0 elr_EL2 bit33 */
			{24074, 0,1}, /* core0 elr_EL2 bit34 */
			{24242, 0,1}, /* core0 elr_EL2 bit35 */
			{23987, 0,1}, /* core0 elr_EL2 bit36 */
			{24071, 0,1}, /* core0 elr_EL2 bit37 */
			{24070, 0,1}, /* core0 elr_EL2 bit38 */
			{23983, 0,1}, /* core0 elr_EL2 bit39 */
			{23982, 0,1}, /* core0 elr_EL2 bit40 */
			{23986, 0,1}, /* core0 elr_EL2 bit41 */
			{24079, 0,1}, /* core0 elr_EL2 bit42 */
			{24078, 0,1}, /* core0 elr_EL2 bit43 */
			{24073, 0,1}, /* core0 elr_EL2 bit44 */
			{24072, 0,1}, /* core0 elr_EL2 bit45 */
			{14511, 0,1}, /* core0 elr_EL2 bit46 */
			{24241, 0,1}, /* core0 elr_EL2 bit47 */
			{24240, 0,1}, /* core0 elr_EL2 bit48 */
			{24065, 0,1}, /* core0 elr_EL2 bit49 */
			{24064, 0,1}, /* core0 elr_EL2 bit50 */
			{24063, 0,1}, /* core0 elr_EL2 bit51 */
			{23989, 0,1}, /* core0 elr_EL2 bit52 */
			{24069, 0,1}, /* core0 elr_EL2 bit53 */
			{23988, 0,1}, /* core0 elr_EL2 bit54 */
			{23985, 0,1}, /* core0 elr_EL2 bit55 */
			{24062, 0,1}, /* core0 elr_EL2 bit56 */
			{23984, 0,1}, /* core0 elr_EL2 bit57 */
			{24067, 0,1}, /* core0 elr_EL2 bit58 */
			{24066, 0,1}, /* core0 elr_EL2 bit59 */
			{24077, 0,1}, /* core0 elr_EL2 bit60 */
			{24076, 0,1}, /* core0 elr_EL2 bit61 */
			{14512, 0,1}, /* core0 elr_EL2 bit62 */
			{24068, 0,1}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{11309, 0,1}, /* core0 elr_EL3 bit0 */
			{12421, 0,1}, /* core0 elr_EL3 bit1 */
			{12420, 0,1}, /* core0 elr_EL3 bit2 */
			{14537, 0,1}, /* core0 elr_EL3 bit3 */
			{12419, 0,1}, /* core0 elr_EL3 bit4 */
			{12418, 0,1}, /* core0 elr_EL3 bit5 */
			{11308, 0,1}, /* core0 elr_EL3 bit6 */
			{12465, 0,1}, /* core0 elr_EL3 bit7 */
			{12464, 0,1}, /* core0 elr_EL3 bit8 */
			{24351, 0,0}, /* core0 elr_EL3 bit9 */
			{11307, 0,1}, /* core0 elr_EL3 bit10 */
			{11317, 0,1}, /* core0 elr_EL3 bit11 */
			{11306, 0,1}, /* core0 elr_EL3 bit12 */
			{24350, 0,0}, /* core0 elr_EL3 bit13 */
			{11316, 0,1}, /* core0 elr_EL3 bit14 */
			{12417, 0,1}, /* core0 elr_EL3 bit15 */
			{12416, 0,1}, /* core0 elr_EL3 bit16 */
			{11305, 0,1}, /* core0 elr_EL3 bit17 */
			{11304, 0,1}, /* core0 elr_EL3 bit18 */
			{11311, 0,1}, /* core0 elr_EL3 bit19 */
			{11315, 0,1}, /* core0 elr_EL3 bit20 */
			{11314, 0,1}, /* core0 elr_EL3 bit21 */
			{11310, 0,1}, /* core0 elr_EL3 bit22 */
			{12463, 0,1}, /* core0 elr_EL3 bit23 */
			{12462, 0,1}, /* core0 elr_EL3 bit24 */
			{14533, 0,1}, /* core0 elr_EL3 bit25 */
			{24349, 0,0}, /* core0 elr_EL3 bit26 */
			{24348, 0,0}, /* core0 elr_EL3 bit27 */
			{11313, 0,1}, /* core0 elr_EL3 bit28 */
			{13811, 0,1}, /* core0 elr_EL3 bit29 */
			{11312, 0,1}, /* core0 elr_EL3 bit30 */
			{14534, 0,1}, /* core0 elr_EL3 bit31 */
			{12771, 0,1}, /* core0 elr_EL3 bit32 */
			{12770, 0,1}, /* core0 elr_EL3 bit33 */
			{12773, 0,1}, /* core0 elr_EL3 bit34 */
			{12783, 0,1}, /* core0 elr_EL3 bit35 */
			{12782, 0,1}, /* core0 elr_EL3 bit36 */
			{12839, 0,1}, /* core0 elr_EL3 bit37 */
			{12772, 0,1}, /* core0 elr_EL3 bit38 */
			{12838, 0,1}, /* core0 elr_EL3 bit39 */
			{12767, 0,1}, /* core0 elr_EL3 bit40 */
			{12841, 0,1}, /* core0 elr_EL3 bit41 */
			{12840, 0,1}, /* core0 elr_EL3 bit42 */
			{12766, 0,1}, /* core0 elr_EL3 bit43 */
			{12781, 0,1}, /* core0 elr_EL3 bit44 */
			{12780, 0,1}, /* core0 elr_EL3 bit45 */
			{14522, 0,1}, /* core0 elr_EL3 bit46 */
			{12769, 0,1}, /* core0 elr_EL3 bit47 */
			{12775, 0,1}, /* core0 elr_EL3 bit48 */
			{12774, 0,1}, /* core0 elr_EL3 bit49 */
			{12777, 0,1}, /* core0 elr_EL3 bit50 */
			{12776, 0,1}, /* core0 elr_EL3 bit51 */
			{12843, 0,1}, /* core0 elr_EL3 bit52 */
			{12842, 0,1}, /* core0 elr_EL3 bit53 */
			{12779, 0,1}, /* core0 elr_EL3 bit54 */
			{12778, 0,1}, /* core0 elr_EL3 bit55 */
			{12768, 0,1}, /* core0 elr_EL3 bit56 */
			{12845, 0,1}, /* core0 elr_EL3 bit57 */
			{12844, 0,1}, /* core0 elr_EL3 bit58 */
			{12847, 0,1}, /* core0 elr_EL3 bit59 */
			{12846, 0,1}, /* core0 elr_EL3 bit60 */
			{12849, 0,1}, /* core0 elr_EL3 bit61 */
			{12848, 0,1}, /* core0 elr_EL3 bit62 */
			{14521, 0,1}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{10298, 0,1}, /* core0 raw_pc bit0 */
			{10297, 0,1}, /* core0 raw_pc bit1 */
			{10296, 0,1}, /* core0 raw_pc bit2 */
			{10579, 0,1}, /* core0 raw_pc bit3 */
			{10578, 0,1}, /* core0 raw_pc bit4 */
			{10577, 0,1}, /* core0 raw_pc bit5 */
			{10576, 0,1}, /* core0 raw_pc bit6 */
			{10435, 0,1}, /* core0 raw_pc bit7 */
			{10434, 0,1}, /* core0 raw_pc bit8 */
			{10425, 0,1}, /* core0 raw_pc bit9 */
			{10424, 0,1}, /* core0 raw_pc bit10 */
			{10437, 0,1}, /* core0 raw_pc bit11 */
			{10427, 0,1}, /* core0 raw_pc bit12 */
			{10426, 0,1}, /* core0 raw_pc bit13 */
			{10423, 0,1}, /* core0 raw_pc bit14 */
			{10597, 0,1}, /* core0 raw_pc bit15 */
			{10436, 0,1}, /* core0 raw_pc bit16 */
			{10595, 0,1}, /* core0 raw_pc bit17 */
			{10594, 0,1}, /* core0 raw_pc bit18 */
			{10596, 0,1}, /* core0 raw_pc bit19 */
			{10439, 0,1}, /* core0 raw_pc bit20 */
			{10438, 0,1}, /* core0 raw_pc bit21 */
			{10431, 0,1}, /* core0 raw_pc bit22 */
			{10430, 0,1}, /* core0 raw_pc bit23 */
			{10433, 0,1}, /* core0 raw_pc bit24 */
			{10432, 0,1}, /* core0 raw_pc bit25 */
			{22628, 0,1}, /* core0 raw_pc bit26 */
			{10422, 0,1}, /* core0 raw_pc bit27 */
			{10429, 0,1}, /* core0 raw_pc bit28 */
			{10428, 0,1}, /* core0 raw_pc bit29 */
			{22629, 0,1}, /* core0 raw_pc bit30 */
			{22249, 0,1}, /* core0 raw_pc bit31 */
			{22248, 0,1}, /* core0 raw_pc bit32 */
			{22251, 0,1}, /* core0 raw_pc bit33 */
			{22257, 0,1}, /* core0 raw_pc bit34 */
			{22250, 0,1}, /* core0 raw_pc bit35 */
			{22219, 0,1}, /* core0 raw_pc bit36 */
			{22256, 0,1}, /* core0 raw_pc bit37 */
			{22218, 0,1}, /* core0 raw_pc bit38 */
			{22253, 0,1}, /* core0 raw_pc bit39 */
			{22215, 0,1}, /* core0 raw_pc bit40 */
			{22252, 0,1}, /* core0 raw_pc bit41 */
			{22214, 0,1}, /* core0 raw_pc bit42 */
			{22217, 0,1}, /* core0 raw_pc bit43 */
			{22255, 0,1}, /* core0 raw_pc bit44 */
			{22254, 0,1}, /* core0 raw_pc bit45 */
			{22216, 0,1}, /* core0 raw_pc bit46 */
			{23218, 0,1}, /* core0 raw_pc bit47 */
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
			{22649, 0,1}, /* core0 pc_iss bit0 */
			{22279, 0,1}, /* core0 pc_iss bit1 */
			{22278, 0,1}, /* core0 pc_iss bit2 */
			{ 9131, 0,1}, /* core0 pc_iss bit3 */
			{ 9130, 0,1}, /* core0 pc_iss bit4 */
			{22281, 0,1}, /* core0 pc_iss bit5 */
			{22280, 0,1}, /* core0 pc_iss bit6 */
			{22648, 0,1}, /* core0 pc_iss bit7 */
			{22261, 0,1}, /* core0 pc_iss bit8 */
			{22260, 0,1}, /* core0 pc_iss bit9 */
			{22263, 0,1}, /* core0 pc_iss bit10 */
			{22262, 0,1}, /* core0 pc_iss bit11 */
			{22293, 0,1}, /* core0 pc_iss bit12 */
			{22292, 0,1}, /* core0 pc_iss bit13 */
			{22259, 0,1}, /* core0 pc_iss bit14 */
			{22258, 0,1}, /* core0 pc_iss bit15 */
			{22299, 0,1}, /* core0 pc_iss bit16 */
			{22298, 0,1}, /* core0 pc_iss bit17 */
			{23221, 0,1}, /* core0 pc_iss bit18 */
			{22285, 0,1}, /* core0 pc_iss bit19 */
			{22284, 0,1}, /* core0 pc_iss bit20 */
			{22297, 0,1}, /* core0 pc_iss bit21 */
			{22296, 0,1}, /* core0 pc_iss bit22 */
			{22295, 0,1}, /* core0 pc_iss bit23 */
			{22294, 0,1}, /* core0 pc_iss bit24 */
			{22291, 0,1}, /* core0 pc_iss bit25 */
			{22290, 0,1}, /* core0 pc_iss bit26 */
			{22287, 0,1}, /* core0 pc_iss bit27 */
			{22286, 0,1}, /* core0 pc_iss bit28 */
			{22289, 0,1}, /* core0 pc_iss bit29 */
			{22288, 0,1}, /* core0 pc_iss bit30 */
			{23220, 0,1}, /* core0 pc_iss bit31 */
			{22341, 0,1}, /* core0 pc_iss bit32 */
			{22340, 0,1}, /* core0 pc_iss bit33 */
			{22337, 0,1}, /* core0 pc_iss bit34 */
			{22336, 0,1}, /* core0 pc_iss bit35 */
			{22339, 0,1}, /* core0 pc_iss bit36 */
			{22338, 0,1}, /* core0 pc_iss bit37 */
			{21785, 0,1}, /* core0 pc_iss bit38 */
			{21784, 0,1}, /* core0 pc_iss bit39 */
			{23215, 0,1}, /* core0 pc_iss bit40 */
			{23214, 0,1}, /* core0 pc_iss bit41 */
			{22335, 0,1}, /* core0 pc_iss bit42 */
			{21783, 0,1}, /* core0 pc_iss bit43 */
			{22334, 0,1}, /* core0 pc_iss bit44 */
			{22333, 0,1}, /* core0 pc_iss bit45 */
			{21782, 0,1}, /* core0 pc_iss bit46 */
			{22332, 0,1}, /* core0 pc_iss bit47 */
			{21775, 0,1}, /* core0 pc_iss bit48 */
			{21774, 0,1}, /* core0 pc_iss bit49 */
			{21777, 0,1}, /* core0 pc_iss bit50 */
			{22327, 0,1}, /* core0 pc_iss bit51 */
			{22326, 0,1}, /* core0 pc_iss bit52 */
			{22325, 0,1}, /* core0 pc_iss bit53 */
			{22324, 0,1}, /* core0 pc_iss bit54 */
			{21776, 0,1}, /* core0 pc_iss bit55 */
			{22331, 0,1}, /* core0 pc_iss bit56 */
			{22330, 0,1}, /* core0 pc_iss bit57 */
			{22329, 0,1}, /* core0 pc_iss bit58 */
			{22328, 0,1}, /* core0 pc_iss bit59 */
			{21779, 0,1}, /* core0 pc_iss bit60 */
			{21778, 0,1}, /* core0 pc_iss bit61 */
			{21781, 0,1}, /* core0 pc_iss bit62 */
			{21780, 0,1}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{10299, 0,1}, /* core0 full_pc_wr bit0 */
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
			{13824, 0,1}, /* core0 full_pc_ex1 bit0 */
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
			{10249, 0,1}, /* core0 full_pc_ex2 bit0 */
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
			.spmc_power_state = {{
			{15803,19,0}, /* core1 spmc_power_state bit0 */
			{16019,16,1}, /* core1 spmc_power_state bit1 */
			{16018,16,1}, /* core1 spmc_power_state bit2 */
			{16017,16,1}, /* core1 spmc_power_state bit3 */
			{16016,16,1}, /* core1 spmc_power_state bit4 */
			{15800,19,0}, /* core1 spmc_power_state bit5 */
			{    0, 0,2}, /* core1 spmc_power_state bit6 */
			{    0, 0,2}, /* core1 spmc_power_state bit7 */
			{    0, 0,2}, /* core1 spmc_power_state bit8 */
			{    0, 0,2}, /* core1 spmc_power_state bit9 */
			{    0, 0,2}, /* core1 spmc_power_state bit10 */
			{    0, 0,2}, /* core1 spmc_power_state bit11 */
			{    0, 0,2}, /* core1 spmc_power_state bit12 */
			{    0, 0,2}, /* core1 spmc_power_state bit13 */
			{    0, 0,2}, /* core1 spmc_power_state bit14 */
			{    0, 0,2}, /* core1 spmc_power_state bit15 */
			{    0, 0,2}, /* core1 spmc_power_state bit16 */
			{    0, 0,2}, /* core1 spmc_power_state bit17 */
			{    0, 0,2}, /* core1 spmc_power_state bit18 */
			{    0, 0,2}, /* core1 spmc_power_state bit19 */
			{    0, 0,2}, /* core1 spmc_power_state bit20 */
			{    0, 0,2}, /* core1 spmc_power_state bit21 */
			{    0, 0,2}, /* core1 spmc_power_state bit22 */
			{    0, 0,2}, /* core1 spmc_power_state bit23 */
			{    0, 0,2}, /* core1 spmc_power_state bit24 */
			{    0, 0,2}, /* core1 spmc_power_state bit25 */
			{    0, 0,2}, /* core1 spmc_power_state bit26 */
			{    0, 0,2}, /* core1 spmc_power_state bit27 */
			{    0, 0,2}, /* core1 spmc_power_state bit28 */
			{    0, 0,2}, /* core1 spmc_power_state bit29 */
			{    0, 0,2}, /* core1 spmc_power_state bit30 */
			{    0, 0,2}, /* core1 spmc_power_state bit31 */
			{    0, 0,2}, /* core1 spmc_power_state bit32 */
			{    0, 0,2}, /* core1 spmc_power_state bit33 */
			{    0, 0,2}, /* core1 spmc_power_state bit34 */
			{    0, 0,2}, /* core1 spmc_power_state bit35 */
			{    0, 0,2}, /* core1 spmc_power_state bit36 */
			{    0, 0,2}, /* core1 spmc_power_state bit37 */
			{    0, 0,2}, /* core1 spmc_power_state bit38 */
			{    0, 0,2}, /* core1 spmc_power_state bit39 */
			{    0, 0,2}, /* core1 spmc_power_state bit40 */
			{    0, 0,2}, /* core1 spmc_power_state bit41 */
			{    0, 0,2}, /* core1 spmc_power_state bit42 */
			{    0, 0,2}, /* core1 spmc_power_state bit43 */
			{    0, 0,2}, /* core1 spmc_power_state bit44 */
			{    0, 0,2}, /* core1 spmc_power_state bit45 */
			{    0, 0,2}, /* core1 spmc_power_state bit46 */
			{    0, 0,2}, /* core1 spmc_power_state bit47 */
			{    0, 0,2}, /* core1 spmc_power_state bit48 */
			{    0, 0,2}, /* core1 spmc_power_state bit49 */
			{    0, 0,2}, /* core1 spmc_power_state bit50 */
			{    0, 0,2}, /* core1 spmc_power_state bit51 */
			{    0, 0,2}, /* core1 spmc_power_state bit52 */
			{    0, 0,2}, /* core1 spmc_power_state bit53 */
			{    0, 0,2}, /* core1 spmc_power_state bit54 */
			{    0, 0,2}, /* core1 spmc_power_state bit55 */
			{    0, 0,2}, /* core1 spmc_power_state bit56 */
			{    0, 0,2}, /* core1 spmc_power_state bit57 */
			{    0, 0,2}, /* core1 spmc_power_state bit58 */
			{    0, 0,2}, /* core1 spmc_power_state bit59 */
			{    0, 0,2}, /* core1 spmc_power_state bit60 */
			{    0, 0,2}, /* core1 spmc_power_state bit61 */
			{    0, 0,2}, /* core1 spmc_power_state bit62 */
			{    0, 0,2}, /* core1 spmc_power_state bit63 */
			}},
			.pc = {{
			{23998, 3,1}, /* core1 pc bit0 */
			{24031, 3,1}, /* core1 pc bit1 */
			{24033, 3,1}, /* core1 pc bit2 */
			{24014, 3,1}, /* core1 pc bit3 */
			{24032, 3,1}, /* core1 pc bit4 */
			{24025, 3,1}, /* core1 pc bit5 */
			{16287, 3,1}, /* core1 pc bit6 */
			{24024, 3,1}, /* core1 pc bit7 */
			{16286, 3,1}, /* core1 pc bit8 */
			{24030, 3,1}, /* core1 pc bit9 */
			{24051, 3,1}, /* core1 pc bit10 */
			{ 9105, 2,1}, /* core1 pc bit11 */
			{ 9104, 2,1}, /* core1 pc bit12 */
			{23975, 3,1}, /* core1 pc bit13 */
			{24045, 3,1}, /* core1 pc bit14 */
			{24044, 3,1}, /* core1 pc bit15 */
			{24050, 3,1}, /* core1 pc bit16 */
			{24053, 3,1}, /* core1 pc bit17 */
			{24052, 3,1}, /* core1 pc bit18 */
			{24003, 3,1}, /* core1 pc bit19 */
			{24002, 3,1}, /* core1 pc bit20 */
			{24147, 3,1}, /* core1 pc bit21 */
			{24037, 3,1}, /* core1 pc bit22 */
			{ 9103, 2,1}, /* core1 pc bit23 */
			{24036, 3,1}, /* core1 pc bit24 */
			{24133, 3,1}, /* core1 pc bit25 */
			{ 9102, 2,1}, /* core1 pc bit26 */
			{23168, 3,1}, /* core1 pc bit27 */
			{24146, 3,1}, /* core1 pc bit28 */
			{23167, 3,1}, /* core1 pc bit29 */
			{24043, 3,1}, /* core1 pc bit30 */
			{24042, 3,1}, /* core1 pc bit31 */
			{23959, 3,1}, /* core1 pc bit32 */
			{23958, 3,1}, /* core1 pc bit33 */
			{23993, 3,1}, /* core1 pc bit34 */
			{23992, 3,1}, /* core1 pc bit35 */
			{24149, 3,1}, /* core1 pc bit36 */
			{24132, 3,1}, /* core1 pc bit37 */
			{23961, 3,1}, /* core1 pc bit38 */
			{23960, 3,1}, /* core1 pc bit39 */
			{23957, 3,1}, /* core1 pc bit40 */
			{23956, 3,1}, /* core1 pc bit41 */
			{23967, 3,1}, /* core1 pc bit42 */
			{24148, 3,1}, /* core1 pc bit43 */
			{22945, 2,1}, /* core1 pc bit44 */
			{22944, 2,1}, /* core1 pc bit45 */
			{23987, 3,1}, /* core1 pc bit46 */
			{23966, 3,1}, /* core1 pc bit47 */
			{23991, 3,1}, /* core1 pc bit48 */
			{23989, 3,1}, /* core1 pc bit49 */
			{23990, 3,1}, /* core1 pc bit50 */
			{23965, 3,1}, /* core1 pc bit51 */
			{23964, 3,1}, /* core1 pc bit52 */
			{23988, 3,1}, /* core1 pc bit53 */
			{24107, 3,1}, /* core1 pc bit54 */
			{24106, 3,1}, /* core1 pc bit55 */
			{23068, 3,1}, /* core1 pc bit56 */
			{ 9101, 2,1}, /* core1 pc bit57 */
			{23150, 3,1}, /* core1 pc bit58 */
			{23986, 3,1}, /* core1 pc bit59 */
			{23963, 3,1}, /* core1 pc bit60 */
			{ 9100, 2,1}, /* core1 pc bit61 */
			{23962, 3,1}, /* core1 pc bit62 */
			{23151, 3,1}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{10987, 2,1}, /* core1 sp32 bit0 */
			{10986, 2,1}, /* core1 sp32 bit1 */
			{23581, 2,1}, /* core1 sp32 bit2 */
			{23580, 2,1}, /* core1 sp32 bit3 */
			{10989, 2,1}, /* core1 sp32 bit4 */
			{23571, 2,1}, /* core1 sp32 bit5 */
			{23577, 2,1}, /* core1 sp32 bit6 */
			{16267, 3,1}, /* core1 sp32 bit7 */
			{10988, 2,1}, /* core1 sp32 bit8 */
			{23576, 2,1}, /* core1 sp32 bit9 */
			{16251, 3,1}, /* core1 sp32 bit10 */
			{23570, 2,1}, /* core1 sp32 bit11 */
			{16250, 3,1}, /* core1 sp32 bit12 */
			{23575, 2,1}, /* core1 sp32 bit13 */
			{23574, 2,1}, /* core1 sp32 bit14 */
			{16269, 3,1}, /* core1 sp32 bit15 */
			{16268, 3,1}, /* core1 sp32 bit16 */
			{16265, 3,1}, /* core1 sp32 bit17 */
			{16264, 3,1}, /* core1 sp32 bit18 */
			{16247, 3,1}, /* core1 sp32 bit19 */
			{23579, 2,1}, /* core1 sp32 bit20 */
			{23578, 2,1}, /* core1 sp32 bit21 */
			{16266, 3,1}, /* core1 sp32 bit22 */
			{24021, 3,1}, /* core1 sp32 bit23 */
			{16246, 3,1}, /* core1 sp32 bit24 */
			{16249, 3,1}, /* core1 sp32 bit25 */
			{24020, 3,1}, /* core1 sp32 bit26 */
			{16271, 3,1}, /* core1 sp32 bit27 */
			{16248, 3,1}, /* core1 sp32 bit28 */
			{23573, 2,1}, /* core1 sp32 bit29 */
			{23572, 2,1}, /* core1 sp32 bit30 */
			{16270, 3,1}, /* core1 sp32 bit31 */
			{13203, 2,1}, /* core1 sp32 bit32 */
			{13202, 2,1}, /* core1 sp32 bit33 */
			{13205, 2,1}, /* core1 sp32 bit34 */
			{13204, 2,1}, /* core1 sp32 bit35 */
			{13243, 2,1}, /* core1 sp32 bit36 */
			{13242, 2,1}, /* core1 sp32 bit37 */
			{12299, 2,1}, /* core1 sp32 bit38 */
			{13201, 2,1}, /* core1 sp32 bit39 */
			{13200, 2,1}, /* core1 sp32 bit40 */
			{12297, 2,1}, /* core1 sp32 bit41 */
			{12296, 2,1}, /* core1 sp32 bit42 */
			{12298, 2,1}, /* core1 sp32 bit43 */
			{13241, 2,1}, /* core1 sp32 bit44 */
			{13240, 2,1}, /* core1 sp32 bit45 */
			{13777, 2,1}, /* core1 sp32 bit46 */
			{13187, 2,1}, /* core1 sp32 bit47 */
			{13185, 2,1}, /* core1 sp32 bit48 */
			{13186, 2,1}, /* core1 sp32 bit49 */
			{13184, 2,1}, /* core1 sp32 bit50 */
			{12289, 2,1}, /* core1 sp32 bit51 */
			{12288, 2,1}, /* core1 sp32 bit52 */
			{13207, 2,1}, /* core1 sp32 bit53 */
			{13239, 2,1}, /* core1 sp32 bit54 */
			{13238, 2,1}, /* core1 sp32 bit55 */
			{13211, 2,1}, /* core1 sp32 bit56 */
			{13206, 2,1}, /* core1 sp32 bit57 */
			{12291, 2,1}, /* core1 sp32 bit58 */
			{12290, 2,1}, /* core1 sp32 bit59 */
			{13209, 2,1}, /* core1 sp32 bit60 */
			{13208, 2,1}, /* core1 sp32 bit61 */
			{13750, 2,1}, /* core1 sp32 bit62 */
			{13210, 2,1}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{16193, 3,1}, /* core1 fp32 bit0 */
			{16192, 3,1}, /* core1 fp32 bit1 */
			{16197, 3,1}, /* core1 fp32 bit2 */
			{16196, 3,1}, /* core1 fp32 bit3 */
			{16207, 3,1}, /* core1 fp32 bit4 */
			{16203, 3,1}, /* core1 fp32 bit5 */
			{16205, 3,1}, /* core1 fp32 bit6 */
			{16204, 3,1}, /* core1 fp32 bit7 */
			{16161, 3,1}, /* core1 fp32 bit8 */
			{16160, 3,1}, /* core1 fp32 bit9 */
			{16209, 3,1}, /* core1 fp32 bit10 */
			{16202, 3,1}, /* core1 fp32 bit11 */
			{16208, 3,1}, /* core1 fp32 bit12 */
			{11941, 2,1}, /* core1 fp32 bit13 */
			{11935, 2,1}, /* core1 fp32 bit14 */
			{16159, 3,1}, /* core1 fp32 bit15 */
			{11940, 2,1}, /* core1 fp32 bit16 */
			{16206, 3,1}, /* core1 fp32 bit17 */
			{16199, 3,1}, /* core1 fp32 bit18 */
			{16198, 3,1}, /* core1 fp32 bit19 */
			{11934, 2,1}, /* core1 fp32 bit20 */
			{16201, 3,1}, /* core1 fp32 bit21 */
			{16200, 3,1}, /* core1 fp32 bit22 */
			{11925, 2,1}, /* core1 fp32 bit23 */
			{11924, 2,1}, /* core1 fp32 bit24 */
			{11937, 2,1}, /* core1 fp32 bit25 */
			{16195, 3,1}, /* core1 fp32 bit26 */
			{13733, 2,1}, /* core1 fp32 bit27 */
			{11936, 2,1}, /* core1 fp32 bit28 */
			{16194, 3,1}, /* core1 fp32 bit29 */
			{11939, 2,1}, /* core1 fp32 bit30 */
			{11938, 2,1}, /* core1 fp32 bit31 */
			{14669, 2,1}, /* core1 fp32 bit32 */
			{14668, 2,1}, /* core1 fp32 bit33 */
			{14671, 2,1}, /* core1 fp32 bit34 */
			{14670, 2,1}, /* core1 fp32 bit35 */
			{14645, 2,1}, /* core1 fp32 bit36 */
			{14644, 2,1}, /* core1 fp32 bit37 */
			{14647, 2,1}, /* core1 fp32 bit38 */
			{14646, 2,1}, /* core1 fp32 bit39 */
			{13771, 2,1}, /* core1 fp32 bit40 */
			{14651, 2,1}, /* core1 fp32 bit41 */
			{14650, 2,1}, /* core1 fp32 bit42 */
			{14653, 2,1}, /* core1 fp32 bit43 */
			{14652, 2,1}, /* core1 fp32 bit44 */
			{14657, 2,1}, /* core1 fp32 bit45 */
			{14656, 2,1}, /* core1 fp32 bit46 */
			{14641, 2,1}, /* core1 fp32 bit47 */
			{14640, 2,1}, /* core1 fp32 bit48 */
			{14649, 2,1}, /* core1 fp32 bit49 */
			{14648, 2,1}, /* core1 fp32 bit50 */
			{14643, 2,1}, /* core1 fp32 bit51 */
			{14642, 2,1}, /* core1 fp32 bit52 */
			{14661, 2,1}, /* core1 fp32 bit53 */
			{14665, 2,1}, /* core1 fp32 bit54 */
			{14660, 2,1}, /* core1 fp32 bit55 */
			{14664, 2,1}, /* core1 fp32 bit56 */
			{14667, 2,1}, /* core1 fp32 bit57 */
			{14663, 2,1}, /* core1 fp32 bit58 */
			{14662, 2,1}, /* core1 fp32 bit59 */
			{14666, 2,1}, /* core1 fp32 bit60 */
			{14659, 2,1}, /* core1 fp32 bit61 */
			{14658, 2,1}, /* core1 fp32 bit62 */
			{13769, 2,1}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{10273, 2,1}, /* core1 fp64 bit0 */
			{10272, 2,1}, /* core1 fp64 bit1 */
			{10271, 2,1}, /* core1 fp64 bit2 */
			{10270, 2,1}, /* core1 fp64 bit3 */
			{16293, 3,1}, /* core1 fp64 bit4 */
			{16292, 3,1}, /* core1 fp64 bit5 */
			{16275, 3,1}, /* core1 fp64 bit6 */
			{16274, 3,1}, /* core1 fp64 bit7 */
			{16297, 3,1}, /* core1 fp64 bit8 */
			{16296, 3,1}, /* core1 fp64 bit9 */
			{16273, 3,1}, /* core1 fp64 bit10 */
			{16279, 3,1}, /* core1 fp64 bit11 */
			{16272, 3,1}, /* core1 fp64 bit12 */
			{16291, 3,1}, /* core1 fp64 bit13 */
			{16257, 3,1}, /* core1 fp64 bit14 */
			{16290, 3,1}, /* core1 fp64 bit15 */
			{24023, 3,1}, /* core1 fp64 bit16 */
			{16278, 3,1}, /* core1 fp64 bit17 */
			{16281, 3,1}, /* core1 fp64 bit18 */
			{16280, 3,1}, /* core1 fp64 bit19 */
			{16256, 3,1}, /* core1 fp64 bit20 */
			{16259, 3,1}, /* core1 fp64 bit21 */
			{16317, 3,1}, /* core1 fp64 bit22 */
			{16316, 3,1}, /* core1 fp64 bit23 */
			{16295, 3,1}, /* core1 fp64 bit24 */
			{16258, 3,1}, /* core1 fp64 bit25 */
			{16277, 3,1}, /* core1 fp64 bit26 */
			{24022, 3,1}, /* core1 fp64 bit27 */
			{16294, 3,1}, /* core1 fp64 bit28 */
			{16276, 3,1}, /* core1 fp64 bit29 */
			{16283, 3,1}, /* core1 fp64 bit30 */
			{16282, 3,1}, /* core1 fp64 bit31 */
			{ 9757, 2,1}, /* core1 fp64 bit32 */
			{ 9756, 2,1}, /* core1 fp64 bit33 */
			{ 9751, 2,1}, /* core1 fp64 bit34 */
			{ 9750, 2,1}, /* core1 fp64 bit35 */
			{ 9729, 2,1}, /* core1 fp64 bit36 */
			{ 9755, 2,1}, /* core1 fp64 bit37 */
			{ 9754, 2,1}, /* core1 fp64 bit38 */
			{ 9731, 2,1}, /* core1 fp64 bit39 */
			{ 9728, 2,1}, /* core1 fp64 bit40 */
			{ 9730, 2,1}, /* core1 fp64 bit41 */
			{ 9721, 2,1}, /* core1 fp64 bit42 */
			{13801, 2,1}, /* core1 fp64 bit43 */
			{ 9720, 2,1}, /* core1 fp64 bit44 */
			{ 9733, 2,1}, /* core1 fp64 bit45 */
			{ 9732, 2,1}, /* core1 fp64 bit46 */
			{ 9725, 2,1}, /* core1 fp64 bit47 */
			{ 9727, 2,1}, /* core1 fp64 bit48 */
			{ 9726, 2,1}, /* core1 fp64 bit49 */
			{ 9724, 2,1}, /* core1 fp64 bit50 */
			{ 9763, 2,1}, /* core1 fp64 bit51 */
			{ 9753, 2,1}, /* core1 fp64 bit52 */
			{ 9752, 2,1}, /* core1 fp64 bit53 */
			{ 9759, 2,1}, /* core1 fp64 bit54 */
			{ 9758, 2,1}, /* core1 fp64 bit55 */
			{ 9762, 2,1}, /* core1 fp64 bit56 */
			{ 9719, 2,1}, /* core1 fp64 bit57 */
			{13800, 2,1}, /* core1 fp64 bit58 */
			{ 9718, 2,1}, /* core1 fp64 bit59 */
			{ 9761, 2,1}, /* core1 fp64 bit60 */
			{ 9760, 2,1}, /* core1 fp64 bit61 */
			{ 9723, 2,1}, /* core1 fp64 bit62 */
			{ 9722, 2,1}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{12529, 2,1}, /* core1 sp_EL0 bit0 */
			{10485, 2,1}, /* core1 sp_EL0 bit1 */
			{10484, 2,1}, /* core1 sp_EL0 bit2 */
			{12527, 2,1}, /* core1 sp_EL0 bit3 */
			{10489, 2,1}, /* core1 sp_EL0 bit4 */
			{10488, 2,1}, /* core1 sp_EL0 bit5 */
			{12526, 2,1}, /* core1 sp_EL0 bit6 */
			{12528, 2,1}, /* core1 sp_EL0 bit7 */
			{12531, 2,1}, /* core1 sp_EL0 bit8 */
			{12530, 2,1}, /* core1 sp_EL0 bit9 */
			{12439, 2,1}, /* core1 sp_EL0 bit10 */
			{12523, 2,1}, /* core1 sp_EL0 bit11 */
			{10487, 2,1}, /* core1 sp_EL0 bit12 */
			{12438, 2,1}, /* core1 sp_EL0 bit13 */
			{12429, 2,1}, /* core1 sp_EL0 bit14 */
			{10486, 2,1}, /* core1 sp_EL0 bit15 */
			{13720, 2,1}, /* core1 sp_EL0 bit16 */
			{12428, 2,1}, /* core1 sp_EL0 bit17 */
			{12437, 2,1}, /* core1 sp_EL0 bit18 */
			{12436, 2,1}, /* core1 sp_EL0 bit19 */
			{12522, 2,1}, /* core1 sp_EL0 bit20 */
			{12525, 2,1}, /* core1 sp_EL0 bit21 */
			{12431, 2,1}, /* core1 sp_EL0 bit22 */
			{12430, 2,1}, /* core1 sp_EL0 bit23 */
			{12521, 2,1}, /* core1 sp_EL0 bit24 */
			{12524, 2,1}, /* core1 sp_EL0 bit25 */
			{12427, 2,1}, /* core1 sp_EL0 bit26 */
			{13721, 2,1}, /* core1 sp_EL0 bit27 */
			{12520, 2,1}, /* core1 sp_EL0 bit28 */
			{12426, 2,1}, /* core1 sp_EL0 bit29 */
			{12441, 2,1}, /* core1 sp_EL0 bit30 */
			{12440, 2,1}, /* core1 sp_EL0 bit31 */
			{12829, 2,1}, /* core1 sp_EL0 bit32 */
			{12828, 2,1}, /* core1 sp_EL0 bit33 */
			{12823, 2,1}, /* core1 sp_EL0 bit34 */
			{11205, 2,1}, /* core1 sp_EL0 bit35 */
			{12822, 2,1}, /* core1 sp_EL0 bit36 */
			{11213, 2,1}, /* core1 sp_EL0 bit37 */
			{11212, 2,1}, /* core1 sp_EL0 bit38 */
			{11211, 2,1}, /* core1 sp_EL0 bit39 */
			{11210, 2,1}, /* core1 sp_EL0 bit40 */
			{11204, 2,1}, /* core1 sp_EL0 bit41 */
			{11201, 2,1}, /* core1 sp_EL0 bit42 */
			{11200, 2,1}, /* core1 sp_EL0 bit43 */
			{12827, 2,1}, /* core1 sp_EL0 bit44 */
			{12826, 2,1}, /* core1 sp_EL0 bit45 */
			{14527, 2,1}, /* core1 sp_EL0 bit46 */
			{11217, 2,1}, /* core1 sp_EL0 bit47 */
			{11216, 2,1}, /* core1 sp_EL0 bit48 */
			{11207, 2,1}, /* core1 sp_EL0 bit49 */
			{12821, 2,1}, /* core1 sp_EL0 bit50 */
			{11206, 2,1}, /* core1 sp_EL0 bit51 */
			{12820, 2,1}, /* core1 sp_EL0 bit52 */
			{11219, 2,1}, /* core1 sp_EL0 bit53 */
			{11218, 2,1}, /* core1 sp_EL0 bit54 */
			{14231, 2,1}, /* core1 sp_EL0 bit55 */
			{12825, 2,1}, /* core1 sp_EL0 bit56 */
			{12824, 2,1}, /* core1 sp_EL0 bit57 */
			{11215, 2,1}, /* core1 sp_EL0 bit58 */
			{11214, 2,1}, /* core1 sp_EL0 bit59 */
			{11203, 2,1}, /* core1 sp_EL0 bit60 */
			{11202, 2,1}, /* core1 sp_EL0 bit61 */
			{14526, 2,1}, /* core1 sp_EL0 bit62 */
			{14528, 2,1}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{10269, 2,1}, /* core1 sp_EL1 bit0 */
			{10268, 2,1}, /* core1 sp_EL1 bit1 */
			{10267, 2,1}, /* core1 sp_EL1 bit2 */
			{10266, 2,1}, /* core1 sp_EL1 bit3 */
			{16243, 3,1}, /* core1 sp_EL1 bit4 */
			{16242, 3,1}, /* core1 sp_EL1 bit5 */
			{10991, 2,1}, /* core1 sp_EL1 bit6 */
			{10990, 2,1}, /* core1 sp_EL1 bit7 */
			{16255, 3,1}, /* core1 sp_EL1 bit8 */
			{16254, 3,1}, /* core1 sp_EL1 bit9 */
			{16263, 3,1}, /* core1 sp_EL1 bit10 */
			{16237, 3,1}, /* core1 sp_EL1 bit11 */
			{16262, 3,1}, /* core1 sp_EL1 bit12 */
			{16245, 3,1}, /* core1 sp_EL1 bit13 */
			{16236, 3,1}, /* core1 sp_EL1 bit14 */
			{16253, 3,1}, /* core1 sp_EL1 bit15 */
			{16252, 3,1}, /* core1 sp_EL1 bit16 */
			{16233, 3,1}, /* core1 sp_EL1 bit17 */
			{16232, 3,1}, /* core1 sp_EL1 bit18 */
			{16235, 3,1}, /* core1 sp_EL1 bit19 */
			{10985, 2,1}, /* core1 sp_EL1 bit20 */
			{16234, 3,1}, /* core1 sp_EL1 bit21 */
			{16244, 3,1}, /* core1 sp_EL1 bit22 */
			{16239, 3,1}, /* core1 sp_EL1 bit23 */
			{23070, 3,1}, /* core1 sp_EL1 bit24 */
			{10984, 2,1}, /* core1 sp_EL1 bit25 */
			{16261, 3,1}, /* core1 sp_EL1 bit26 */
			{16260, 3,1}, /* core1 sp_EL1 bit27 */
			{16238, 3,1}, /* core1 sp_EL1 bit28 */
			{23069, 3,1}, /* core1 sp_EL1 bit29 */
			{16241, 3,1}, /* core1 sp_EL1 bit30 */
			{16240, 3,1}, /* core1 sp_EL1 bit31 */
			{24089, 2,1}, /* core1 sp_EL1 bit32 */
			{24088, 2,1}, /* core1 sp_EL1 bit33 */
			{12803, 2,1}, /* core1 sp_EL1 bit34 */
			{11221, 2,1}, /* core1 sp_EL1 bit35 */
			{11220, 2,1}, /* core1 sp_EL1 bit36 */
			{12799, 2,1}, /* core1 sp_EL1 bit37 */
			{12798, 2,1}, /* core1 sp_EL1 bit38 */
			{24091, 2,1}, /* core1 sp_EL1 bit39 */
			{24090, 2,1}, /* core1 sp_EL1 bit40 */
			{12802, 2,1}, /* core1 sp_EL1 bit41 */
			{12807, 2,1}, /* core1 sp_EL1 bit42 */
			{12801, 2,1}, /* core1 sp_EL1 bit43 */
			{12800, 2,1}, /* core1 sp_EL1 bit44 */
			{14517, 2,1}, /* core1 sp_EL1 bit45 */
			{12806, 2,1}, /* core1 sp_EL1 bit46 */
			{12809, 2,1}, /* core1 sp_EL1 bit47 */
			{12808, 2,1}, /* core1 sp_EL1 bit48 */
			{12797, 2,1}, /* core1 sp_EL1 bit49 */
			{24085, 2,1}, /* core1 sp_EL1 bit50 */
			{24084, 2,1}, /* core1 sp_EL1 bit51 */
			{12805, 2,1}, /* core1 sp_EL1 bit52 */
			{12796, 2,1}, /* core1 sp_EL1 bit53 */
			{12804, 2,1}, /* core1 sp_EL1 bit54 */
			{24081, 2,1}, /* core1 sp_EL1 bit55 */
			{24080, 2,1}, /* core1 sp_EL1 bit56 */
			{24087, 2,1}, /* core1 sp_EL1 bit57 */
			{14515, 2,1}, /* core1 sp_EL1 bit58 */
			{24086, 2,1}, /* core1 sp_EL1 bit59 */
			{24083, 2,1}, /* core1 sp_EL1 bit60 */
			{24082, 2,1}, /* core1 sp_EL1 bit61 */
			{14516, 2,1}, /* core1 sp_EL1 bit62 */
			{14514, 2,1}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{10265, 2,1}, /* core1 sp_EL2 bit0 */
			{10264, 2,1}, /* core1 sp_EL2 bit1 */
			{10263, 2,1}, /* core1 sp_EL2 bit2 */
			{10262, 2,1}, /* core1 sp_EL2 bit3 */
			{12503, 2,1}, /* core1 sp_EL2 bit4 */
			{12502, 2,1}, /* core1 sp_EL2 bit5 */
			{12549, 2,1}, /* core1 sp_EL2 bit6 */
			{12548, 2,1}, /* core1 sp_EL2 bit7 */
			{12507, 2,1}, /* core1 sp_EL2 bit8 */
			{12506, 2,1}, /* core1 sp_EL2 bit9 */
			{12509, 2,1}, /* core1 sp_EL2 bit10 */
			{12559, 2,1}, /* core1 sp_EL2 bit11 */
			{12508, 2,1}, /* core1 sp_EL2 bit12 */
			{12505, 2,1}, /* core1 sp_EL2 bit13 */
			{12551, 2,1}, /* core1 sp_EL2 bit14 */
			{12547, 2,1}, /* core1 sp_EL2 bit15 */
			{12546, 2,1}, /* core1 sp_EL2 bit16 */
			{12558, 2,1}, /* core1 sp_EL2 bit17 */
			{12557, 2,1}, /* core1 sp_EL2 bit18 */
			{12556, 2,1}, /* core1 sp_EL2 bit19 */
			{12550, 2,1}, /* core1 sp_EL2 bit20 */
			{12553, 2,1}, /* core1 sp_EL2 bit21 */
			{12501, 2,1}, /* core1 sp_EL2 bit22 */
			{14539, 2,1}, /* core1 sp_EL2 bit23 */
			{12500, 2,1}, /* core1 sp_EL2 bit24 */
			{12555, 2,1}, /* core1 sp_EL2 bit25 */
			{12504, 2,1}, /* core1 sp_EL2 bit26 */
			{12552, 2,1}, /* core1 sp_EL2 bit27 */
			{12554, 2,1}, /* core1 sp_EL2 bit28 */
			{13717, 2,1}, /* core1 sp_EL2 bit29 */
			{12499, 2,1}, /* core1 sp_EL2 bit30 */
			{12498, 2,1}, /* core1 sp_EL2 bit31 */
			{12765, 2,1}, /* core1 sp_EL2 bit32 */
			{12764, 2,1}, /* core1 sp_EL2 bit33 */
			{12853, 2,1}, /* core1 sp_EL2 bit34 */
			{12761, 2,1}, /* core1 sp_EL2 bit35 */
			{12760, 2,1}, /* core1 sp_EL2 bit36 */
			{12852, 2,1}, /* core1 sp_EL2 bit37 */
			{12851, 2,1}, /* core1 sp_EL2 bit38 */
			{12850, 2,1}, /* core1 sp_EL2 bit39 */
			{14520, 2,1}, /* core1 sp_EL2 bit40 */
			{12855, 2,1}, /* core1 sp_EL2 bit41 */
			{12854, 2,1}, /* core1 sp_EL2 bit42 */
			{12863, 2,1}, /* core1 sp_EL2 bit43 */
			{12862, 2,1}, /* core1 sp_EL2 bit44 */
			{12763, 2,1}, /* core1 sp_EL2 bit45 */
			{12762, 2,1}, /* core1 sp_EL2 bit46 */
			{12857, 2,1}, /* core1 sp_EL2 bit47 */
			{12859, 2,1}, /* core1 sp_EL2 bit48 */
			{12858, 2,1}, /* core1 sp_EL2 bit49 */
			{12856, 2,1}, /* core1 sp_EL2 bit50 */
			{12865, 2,1}, /* core1 sp_EL2 bit51 */
			{12867, 2,1}, /* core1 sp_EL2 bit52 */
			{12866, 2,1}, /* core1 sp_EL2 bit53 */
			{12864, 2,1}, /* core1 sp_EL2 bit54 */
			{12861, 2,1}, /* core1 sp_EL2 bit55 */
			{12860, 2,1}, /* core1 sp_EL2 bit56 */
			{12871, 2,1}, /* core1 sp_EL2 bit57 */
			{12870, 2,1}, /* core1 sp_EL2 bit58 */
			{12759, 2,1}, /* core1 sp_EL2 bit59 */
			{12758, 2,1}, /* core1 sp_EL2 bit60 */
			{12869, 2,1}, /* core1 sp_EL2 bit61 */
			{12868, 2,1}, /* core1 sp_EL2 bit62 */
			{14445, 2,1}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{12453, 2,1}, /* core1 sp_EL3 bit0 */
			{12452, 2,1}, /* core1 sp_EL3 bit1 */
			{12513, 2,1}, /* core1 sp_EL3 bit2 */
			{12447, 2,1}, /* core1 sp_EL3 bit3 */
			{12515, 2,1}, /* core1 sp_EL3 bit4 */
			{12514, 2,1}, /* core1 sp_EL3 bit5 */
			{12446, 2,1}, /* core1 sp_EL3 bit6 */
			{12443, 2,1}, /* core1 sp_EL3 bit7 */
			{12512, 2,1}, /* core1 sp_EL3 bit8 */
			{12511, 2,1}, /* core1 sp_EL3 bit9 */
			{12442, 2,1}, /* core1 sp_EL3 bit10 */
			{12423, 2,1}, /* core1 sp_EL3 bit11 */
			{12445, 2,1}, /* core1 sp_EL3 bit12 */
			{12510, 2,1}, /* core1 sp_EL3 bit13 */
			{12449, 2,1}, /* core1 sp_EL3 bit14 */
			{12444, 2,1}, /* core1 sp_EL3 bit15 */
			{14538, 2,1}, /* core1 sp_EL3 bit16 */
			{12422, 2,1}, /* core1 sp_EL3 bit17 */
			{12451, 2,1}, /* core1 sp_EL3 bit18 */
			{12450, 2,1}, /* core1 sp_EL3 bit19 */
			{12448, 2,1}, /* core1 sp_EL3 bit20 */
			{12457, 2,1}, /* core1 sp_EL3 bit21 */
			{12459, 2,1}, /* core1 sp_EL3 bit22 */
			{12456, 2,1}, /* core1 sp_EL3 bit23 */
			{12458, 2,1}, /* core1 sp_EL3 bit24 */
			{12455, 2,1}, /* core1 sp_EL3 bit25 */
			{12425, 2,1}, /* core1 sp_EL3 bit26 */
			{12424, 2,1}, /* core1 sp_EL3 bit27 */
			{12461, 2,1}, /* core1 sp_EL3 bit28 */
			{12454, 2,1}, /* core1 sp_EL3 bit29 */
			{12460, 2,1}, /* core1 sp_EL3 bit30 */
			{13716, 2,1}, /* core1 sp_EL3 bit31 */
			{12115, 2,1}, /* core1 sp_EL3 bit32 */
			{12114, 2,1}, /* core1 sp_EL3 bit33 */
			{14149, 2,1}, /* core1 sp_EL3 bit34 */
			{23991, 2,1}, /* core1 sp_EL3 bit35 */
			{14148, 2,1}, /* core1 sp_EL3 bit36 */
			{14147, 2,1}, /* core1 sp_EL3 bit37 */
			{14146, 2,1}, /* core1 sp_EL3 bit38 */
			{24247, 2,1}, /* core1 sp_EL3 bit39 */
			{24246, 2,1}, /* core1 sp_EL3 bit40 */
			{23990, 2,1}, /* core1 sp_EL3 bit41 */
			{23993, 2,1}, /* core1 sp_EL3 bit42 */
			{23992, 2,1}, /* core1 sp_EL3 bit43 */
			{12113, 2,1}, /* core1 sp_EL3 bit44 */
			{12112, 2,1}, /* core1 sp_EL3 bit45 */
			{14510, 2,1}, /* core1 sp_EL3 bit46 */
			{14143, 2,1}, /* core1 sp_EL3 bit47 */
			{14142, 2,1}, /* core1 sp_EL3 bit48 */
			{14061, 2,1}, /* core1 sp_EL3 bit49 */
			{14060, 2,1}, /* core1 sp_EL3 bit50 */
			{24245, 2,1}, /* core1 sp_EL3 bit51 */
			{24244, 2,1}, /* core1 sp_EL3 bit52 */
			{14509, 2,1}, /* core1 sp_EL3 bit53 */
			{14145, 2,1}, /* core1 sp_EL3 bit54 */
			{14144, 2,1}, /* core1 sp_EL3 bit55 */
			{12111, 2,1}, /* core1 sp_EL3 bit56 */
			{12110, 2,1}, /* core1 sp_EL3 bit57 */
			{14063, 2,1}, /* core1 sp_EL3 bit58 */
			{14062, 2,1}, /* core1 sp_EL3 bit59 */
			{24249, 2,1}, /* core1 sp_EL3 bit60 */
			{24248, 2,1}, /* core1 sp_EL3 bit61 */
			{14501, 2,1}, /* core1 sp_EL3 bit62 */
			{14508, 2,1}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{10491, 2,1}, /* core1 elr_EL1 bit0 */
			{10490, 2,1}, /* core1 elr_EL1 bit1 */
			{10493, 2,1}, /* core1 elr_EL1 bit2 */
			{13718, 2,1}, /* core1 elr_EL1 bit3 */
			{12545, 2,1}, /* core1 elr_EL1 bit4 */
			{12519, 2,1}, /* core1 elr_EL1 bit5 */
			{12539, 2,1}, /* core1 elr_EL1 bit6 */
			{12538, 2,1}, /* core1 elr_EL1 bit7 */
			{10492, 2,1}, /* core1 elr_EL1 bit8 */
			{12535, 2,1}, /* core1 elr_EL1 bit9 */
			{10499, 2,1}, /* core1 elr_EL1 bit10 */
			{12544, 2,1}, /* core1 elr_EL1 bit11 */
			{12534, 2,1}, /* core1 elr_EL1 bit12 */
			{12537, 2,1}, /* core1 elr_EL1 bit13 */
			{12518, 2,1}, /* core1 elr_EL1 bit14 */
			{12536, 2,1}, /* core1 elr_EL1 bit15 */
			{13719, 2,1}, /* core1 elr_EL1 bit16 */
			{10497, 2,1}, /* core1 elr_EL1 bit17 */
			{10496, 2,1}, /* core1 elr_EL1 bit18 */
			{10495, 2,1}, /* core1 elr_EL1 bit19 */
			{12541, 2,1}, /* core1 elr_EL1 bit20 */
			{10494, 2,1}, /* core1 elr_EL1 bit21 */
			{12517, 2,1}, /* core1 elr_EL1 bit22 */
			{12516, 2,1}, /* core1 elr_EL1 bit23 */
			{13715, 2,1}, /* core1 elr_EL1 bit24 */
			{12540, 2,1}, /* core1 elr_EL1 bit25 */
			{10498, 2,1}, /* core1 elr_EL1 bit26 */
			{12533, 2,1}, /* core1 elr_EL1 bit27 */
			{12543, 2,1}, /* core1 elr_EL1 bit28 */
			{12532, 2,1}, /* core1 elr_EL1 bit29 */
			{12542, 2,1}, /* core1 elr_EL1 bit30 */
			{13714, 2,1}, /* core1 elr_EL1 bit31 */
			{14131, 2,1}, /* core1 elr_EL1 bit32 */
			{14073, 2,1}, /* core1 elr_EL1 bit33 */
			{14072, 2,1}, /* core1 elr_EL1 bit34 */
			{14130, 2,1}, /* core1 elr_EL1 bit35 */
			{14123, 2,1}, /* core1 elr_EL1 bit36 */
			{14122, 2,1}, /* core1 elr_EL1 bit37 */
			{14125, 2,1}, /* core1 elr_EL1 bit38 */
			{14071, 2,1}, /* core1 elr_EL1 bit39 */
			{14070, 2,1}, /* core1 elr_EL1 bit40 */
			{14124, 2,1}, /* core1 elr_EL1 bit41 */
			{14133, 2,1}, /* core1 elr_EL1 bit42 */
			{14132, 2,1}, /* core1 elr_EL1 bit43 */
			{14127, 2,1}, /* core1 elr_EL1 bit44 */
			{14126, 2,1}, /* core1 elr_EL1 bit45 */
			{13802, 2,1}, /* core1 elr_EL1 bit46 */
			{14135, 2,1}, /* core1 elr_EL1 bit47 */
			{14134, 2,1}, /* core1 elr_EL1 bit48 */
			{14069, 2,1}, /* core1 elr_EL1 bit49 */
			{14068, 2,1}, /* core1 elr_EL1 bit50 */
			{14129, 2,1}, /* core1 elr_EL1 bit51 */
			{14067, 2,1}, /* core1 elr_EL1 bit52 */
			{14066, 2,1}, /* core1 elr_EL1 bit53 */
			{14141, 2,1}, /* core1 elr_EL1 bit54 */
			{14128, 2,1}, /* core1 elr_EL1 bit55 */
			{14140, 2,1}, /* core1 elr_EL1 bit56 */
			{14065, 2,1}, /* core1 elr_EL1 bit57 */
			{14064, 2,1}, /* core1 elr_EL1 bit58 */
			{14139, 2,1}, /* core1 elr_EL1 bit59 */
			{14138, 2,1}, /* core1 elr_EL1 bit60 */
			{14137, 2,1}, /* core1 elr_EL1 bit61 */
			{14136, 2,1}, /* core1 elr_EL1 bit62 */
			{14499, 2,1}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{24107, 2,1}, /* core1 elr_EL2 bit0 */
			{24106, 2,1}, /* core1 elr_EL2 bit1 */
			{11155, 2,1}, /* core1 elr_EL2 bit2 */
			{11154, 2,1}, /* core1 elr_EL2 bit3 */
			{24113, 2,1}, /* core1 elr_EL2 bit4 */
			{24112, 2,1}, /* core1 elr_EL2 bit5 */
			{11165, 2,1}, /* core1 elr_EL2 bit6 */
			{11164, 2,1}, /* core1 elr_EL2 bit7 */
			{24109, 2,1}, /* core1 elr_EL2 bit8 */
			{24108, 2,1}, /* core1 elr_EL2 bit9 */
			{24117, 2,1}, /* core1 elr_EL2 bit10 */
			{24105, 2,1}, /* core1 elr_EL2 bit11 */
			{24116, 2,1}, /* core1 elr_EL2 bit12 */
			{11161, 2,1}, /* core1 elr_EL2 bit13 */
			{24115, 2,1}, /* core1 elr_EL2 bit14 */
			{11160, 2,1}, /* core1 elr_EL2 bit15 */
			{11157, 2,1}, /* core1 elr_EL2 bit16 */
			{24104, 2,1}, /* core1 elr_EL2 bit17 */
			{11169, 2,1}, /* core1 elr_EL2 bit18 */
			{24114, 2,1}, /* core1 elr_EL2 bit19 */
			{11159, 2,1}, /* core1 elr_EL2 bit20 */
			{11158, 2,1}, /* core1 elr_EL2 bit21 */
			{11163, 2,1}, /* core1 elr_EL2 bit22 */
			{11168, 2,1}, /* core1 elr_EL2 bit23 */
			{11162, 2,1}, /* core1 elr_EL2 bit24 */
			{24111, 2,1}, /* core1 elr_EL2 bit25 */
			{11156, 2,1}, /* core1 elr_EL2 bit26 */
			{13693, 2,1}, /* core1 elr_EL2 bit27 */
			{11167, 2,1}, /* core1 elr_EL2 bit28 */
			{11166, 2,1}, /* core1 elr_EL2 bit29 */
			{14449, 2,1}, /* core1 elr_EL2 bit30 */
			{24110, 2,1}, /* core1 elr_EL2 bit31 */
			{24243, 2,1}, /* core1 elr_EL2 bit32 */
			{24075, 2,1}, /* core1 elr_EL2 bit33 */
			{24074, 2,1}, /* core1 elr_EL2 bit34 */
			{24242, 2,1}, /* core1 elr_EL2 bit35 */
			{23987, 2,1}, /* core1 elr_EL2 bit36 */
			{24071, 2,1}, /* core1 elr_EL2 bit37 */
			{24070, 2,1}, /* core1 elr_EL2 bit38 */
			{23983, 2,1}, /* core1 elr_EL2 bit39 */
			{23982, 2,1}, /* core1 elr_EL2 bit40 */
			{23986, 2,1}, /* core1 elr_EL2 bit41 */
			{24079, 2,1}, /* core1 elr_EL2 bit42 */
			{24078, 2,1}, /* core1 elr_EL2 bit43 */
			{24073, 2,1}, /* core1 elr_EL2 bit44 */
			{24072, 2,1}, /* core1 elr_EL2 bit45 */
			{14511, 2,1}, /* core1 elr_EL2 bit46 */
			{24241, 2,1}, /* core1 elr_EL2 bit47 */
			{24240, 2,1}, /* core1 elr_EL2 bit48 */
			{24065, 2,1}, /* core1 elr_EL2 bit49 */
			{24064, 2,1}, /* core1 elr_EL2 bit50 */
			{24063, 2,1}, /* core1 elr_EL2 bit51 */
			{23989, 2,1}, /* core1 elr_EL2 bit52 */
			{24069, 2,1}, /* core1 elr_EL2 bit53 */
			{23988, 2,1}, /* core1 elr_EL2 bit54 */
			{23985, 2,1}, /* core1 elr_EL2 bit55 */
			{24062, 2,1}, /* core1 elr_EL2 bit56 */
			{23984, 2,1}, /* core1 elr_EL2 bit57 */
			{24067, 2,1}, /* core1 elr_EL2 bit58 */
			{24066, 2,1}, /* core1 elr_EL2 bit59 */
			{24077, 2,1}, /* core1 elr_EL2 bit60 */
			{24076, 2,1}, /* core1 elr_EL2 bit61 */
			{14512, 2,1}, /* core1 elr_EL2 bit62 */
			{24068, 2,1}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{11309, 2,1}, /* core1 elr_EL3 bit0 */
			{12421, 2,1}, /* core1 elr_EL3 bit1 */
			{12420, 2,1}, /* core1 elr_EL3 bit2 */
			{14537, 2,1}, /* core1 elr_EL3 bit3 */
			{12419, 2,1}, /* core1 elr_EL3 bit4 */
			{12418, 2,1}, /* core1 elr_EL3 bit5 */
			{11308, 2,1}, /* core1 elr_EL3 bit6 */
			{12465, 2,1}, /* core1 elr_EL3 bit7 */
			{12464, 2,1}, /* core1 elr_EL3 bit8 */
			{24351, 2,0}, /* core1 elr_EL3 bit9 */
			{11307, 2,1}, /* core1 elr_EL3 bit10 */
			{11317, 2,1}, /* core1 elr_EL3 bit11 */
			{11306, 2,1}, /* core1 elr_EL3 bit12 */
			{24350, 2,0}, /* core1 elr_EL3 bit13 */
			{11316, 2,1}, /* core1 elr_EL3 bit14 */
			{12417, 2,1}, /* core1 elr_EL3 bit15 */
			{12416, 2,1}, /* core1 elr_EL3 bit16 */
			{11305, 2,1}, /* core1 elr_EL3 bit17 */
			{11304, 2,1}, /* core1 elr_EL3 bit18 */
			{11311, 2,1}, /* core1 elr_EL3 bit19 */
			{11315, 2,1}, /* core1 elr_EL3 bit20 */
			{11314, 2,1}, /* core1 elr_EL3 bit21 */
			{11310, 2,1}, /* core1 elr_EL3 bit22 */
			{12463, 2,1}, /* core1 elr_EL3 bit23 */
			{12462, 2,1}, /* core1 elr_EL3 bit24 */
			{14533, 2,1}, /* core1 elr_EL3 bit25 */
			{24349, 2,0}, /* core1 elr_EL3 bit26 */
			{24348, 2,0}, /* core1 elr_EL3 bit27 */
			{11313, 2,1}, /* core1 elr_EL3 bit28 */
			{13811, 2,1}, /* core1 elr_EL3 bit29 */
			{11312, 2,1}, /* core1 elr_EL3 bit30 */
			{14534, 2,1}, /* core1 elr_EL3 bit31 */
			{12771, 2,1}, /* core1 elr_EL3 bit32 */
			{12770, 2,1}, /* core1 elr_EL3 bit33 */
			{12773, 2,1}, /* core1 elr_EL3 bit34 */
			{12783, 2,1}, /* core1 elr_EL3 bit35 */
			{12782, 2,1}, /* core1 elr_EL3 bit36 */
			{12839, 2,1}, /* core1 elr_EL3 bit37 */
			{12772, 2,1}, /* core1 elr_EL3 bit38 */
			{12838, 2,1}, /* core1 elr_EL3 bit39 */
			{12767, 2,1}, /* core1 elr_EL3 bit40 */
			{12841, 2,1}, /* core1 elr_EL3 bit41 */
			{12840, 2,1}, /* core1 elr_EL3 bit42 */
			{12766, 2,1}, /* core1 elr_EL3 bit43 */
			{12781, 2,1}, /* core1 elr_EL3 bit44 */
			{12780, 2,1}, /* core1 elr_EL3 bit45 */
			{14522, 2,1}, /* core1 elr_EL3 bit46 */
			{12769, 2,1}, /* core1 elr_EL3 bit47 */
			{12775, 2,1}, /* core1 elr_EL3 bit48 */
			{12774, 2,1}, /* core1 elr_EL3 bit49 */
			{12777, 2,1}, /* core1 elr_EL3 bit50 */
			{12776, 2,1}, /* core1 elr_EL3 bit51 */
			{12843, 2,1}, /* core1 elr_EL3 bit52 */
			{12842, 2,1}, /* core1 elr_EL3 bit53 */
			{12779, 2,1}, /* core1 elr_EL3 bit54 */
			{12778, 2,1}, /* core1 elr_EL3 bit55 */
			{12768, 2,1}, /* core1 elr_EL3 bit56 */
			{12845, 2,1}, /* core1 elr_EL3 bit57 */
			{12844, 2,1}, /* core1 elr_EL3 bit58 */
			{12847, 2,1}, /* core1 elr_EL3 bit59 */
			{12846, 2,1}, /* core1 elr_EL3 bit60 */
			{12849, 2,1}, /* core1 elr_EL3 bit61 */
			{12848, 2,1}, /* core1 elr_EL3 bit62 */
			{14521, 2,1}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{10298, 2,1}, /* core1 raw_pc bit0 */
			{10297, 2,1}, /* core1 raw_pc bit1 */
			{10296, 2,1}, /* core1 raw_pc bit2 */
			{10579, 2,1}, /* core1 raw_pc bit3 */
			{10578, 2,1}, /* core1 raw_pc bit4 */
			{10577, 2,1}, /* core1 raw_pc bit5 */
			{10576, 2,1}, /* core1 raw_pc bit6 */
			{10435, 2,1}, /* core1 raw_pc bit7 */
			{10434, 2,1}, /* core1 raw_pc bit8 */
			{10425, 2,1}, /* core1 raw_pc bit9 */
			{10424, 2,1}, /* core1 raw_pc bit10 */
			{10437, 2,1}, /* core1 raw_pc bit11 */
			{10427, 2,1}, /* core1 raw_pc bit12 */
			{10426, 2,1}, /* core1 raw_pc bit13 */
			{10423, 2,1}, /* core1 raw_pc bit14 */
			{10597, 2,1}, /* core1 raw_pc bit15 */
			{10436, 2,1}, /* core1 raw_pc bit16 */
			{10595, 2,1}, /* core1 raw_pc bit17 */
			{10594, 2,1}, /* core1 raw_pc bit18 */
			{10596, 2,1}, /* core1 raw_pc bit19 */
			{10439, 2,1}, /* core1 raw_pc bit20 */
			{10438, 2,1}, /* core1 raw_pc bit21 */
			{10431, 2,1}, /* core1 raw_pc bit22 */
			{10430, 2,1}, /* core1 raw_pc bit23 */
			{10433, 2,1}, /* core1 raw_pc bit24 */
			{10432, 2,1}, /* core1 raw_pc bit25 */
			{22628, 2,1}, /* core1 raw_pc bit26 */
			{10422, 2,1}, /* core1 raw_pc bit27 */
			{10429, 2,1}, /* core1 raw_pc bit28 */
			{10428, 2,1}, /* core1 raw_pc bit29 */
			{22629, 2,1}, /* core1 raw_pc bit30 */
			{22249, 2,1}, /* core1 raw_pc bit31 */
			{22248, 2,1}, /* core1 raw_pc bit32 */
			{22251, 2,1}, /* core1 raw_pc bit33 */
			{22257, 2,1}, /* core1 raw_pc bit34 */
			{22250, 2,1}, /* core1 raw_pc bit35 */
			{22219, 2,1}, /* core1 raw_pc bit36 */
			{22256, 2,1}, /* core1 raw_pc bit37 */
			{22218, 2,1}, /* core1 raw_pc bit38 */
			{22253, 2,1}, /* core1 raw_pc bit39 */
			{22215, 2,1}, /* core1 raw_pc bit40 */
			{22252, 2,1}, /* core1 raw_pc bit41 */
			{22214, 2,1}, /* core1 raw_pc bit42 */
			{22217, 2,1}, /* core1 raw_pc bit43 */
			{22255, 2,1}, /* core1 raw_pc bit44 */
			{22254, 2,1}, /* core1 raw_pc bit45 */
			{22216, 2,1}, /* core1 raw_pc bit46 */
			{23218, 2,1}, /* core1 raw_pc bit47 */
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
			{22649, 2,1}, /* core1 pc_iss bit0 */
			{22279, 2,1}, /* core1 pc_iss bit1 */
			{22278, 2,1}, /* core1 pc_iss bit2 */
			{ 9131, 2,1}, /* core1 pc_iss bit3 */
			{ 9130, 2,1}, /* core1 pc_iss bit4 */
			{22281, 2,1}, /* core1 pc_iss bit5 */
			{22280, 2,1}, /* core1 pc_iss bit6 */
			{22648, 2,1}, /* core1 pc_iss bit7 */
			{22261, 2,1}, /* core1 pc_iss bit8 */
			{22260, 2,1}, /* core1 pc_iss bit9 */
			{22263, 2,1}, /* core1 pc_iss bit10 */
			{22262, 2,1}, /* core1 pc_iss bit11 */
			{22293, 2,1}, /* core1 pc_iss bit12 */
			{22292, 2,1}, /* core1 pc_iss bit13 */
			{22259, 2,1}, /* core1 pc_iss bit14 */
			{22258, 2,1}, /* core1 pc_iss bit15 */
			{22299, 2,1}, /* core1 pc_iss bit16 */
			{22298, 2,1}, /* core1 pc_iss bit17 */
			{23221, 2,1}, /* core1 pc_iss bit18 */
			{22285, 2,1}, /* core1 pc_iss bit19 */
			{22284, 2,1}, /* core1 pc_iss bit20 */
			{22297, 2,1}, /* core1 pc_iss bit21 */
			{22296, 2,1}, /* core1 pc_iss bit22 */
			{22295, 2,1}, /* core1 pc_iss bit23 */
			{22294, 2,1}, /* core1 pc_iss bit24 */
			{22291, 2,1}, /* core1 pc_iss bit25 */
			{22290, 2,1}, /* core1 pc_iss bit26 */
			{22287, 2,1}, /* core1 pc_iss bit27 */
			{22286, 2,1}, /* core1 pc_iss bit28 */
			{22289, 2,1}, /* core1 pc_iss bit29 */
			{22288, 2,1}, /* core1 pc_iss bit30 */
			{23220, 2,1}, /* core1 pc_iss bit31 */
			{22341, 2,1}, /* core1 pc_iss bit32 */
			{22340, 2,1}, /* core1 pc_iss bit33 */
			{22337, 2,1}, /* core1 pc_iss bit34 */
			{22336, 2,1}, /* core1 pc_iss bit35 */
			{22339, 2,1}, /* core1 pc_iss bit36 */
			{22338, 2,1}, /* core1 pc_iss bit37 */
			{21785, 2,1}, /* core1 pc_iss bit38 */
			{21784, 2,1}, /* core1 pc_iss bit39 */
			{23215, 2,1}, /* core1 pc_iss bit40 */
			{23214, 2,1}, /* core1 pc_iss bit41 */
			{22335, 2,1}, /* core1 pc_iss bit42 */
			{21783, 2,1}, /* core1 pc_iss bit43 */
			{22334, 2,1}, /* core1 pc_iss bit44 */
			{22333, 2,1}, /* core1 pc_iss bit45 */
			{21782, 2,1}, /* core1 pc_iss bit46 */
			{22332, 2,1}, /* core1 pc_iss bit47 */
			{21775, 2,1}, /* core1 pc_iss bit48 */
			{21774, 2,1}, /* core1 pc_iss bit49 */
			{21777, 2,1}, /* core1 pc_iss bit50 */
			{22327, 2,1}, /* core1 pc_iss bit51 */
			{22326, 2,1}, /* core1 pc_iss bit52 */
			{22325, 2,1}, /* core1 pc_iss bit53 */
			{22324, 2,1}, /* core1 pc_iss bit54 */
			{21776, 2,1}, /* core1 pc_iss bit55 */
			{22331, 2,1}, /* core1 pc_iss bit56 */
			{22330, 2,1}, /* core1 pc_iss bit57 */
			{22329, 2,1}, /* core1 pc_iss bit58 */
			{22328, 2,1}, /* core1 pc_iss bit59 */
			{21779, 2,1}, /* core1 pc_iss bit60 */
			{21778, 2,1}, /* core1 pc_iss bit61 */
			{21781, 2,1}, /* core1 pc_iss bit62 */
			{21780, 2,1}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{10299, 2,1}, /* core1 full_pc_wr bit0 */
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
			{13824, 2,1}, /* core1 full_pc_ex1 bit0 */
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
			{10249, 2,1}, /* core1 full_pc_ex2 bit0 */
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
			.spmc_power_state = {{
			{16038,19,0}, /* core2 spmc_power_state bit0 */
			{15939,16,1}, /* core2 spmc_power_state bit1 */
			{15938,16,1}, /* core2 spmc_power_state bit2 */
			{15937,16,1}, /* core2 spmc_power_state bit3 */
			{15936,16,1}, /* core2 spmc_power_state bit4 */
			{16036,19,0}, /* core2 spmc_power_state bit5 */
			{    0, 0,2}, /* core2 spmc_power_state bit6 */
			{    0, 0,2}, /* core2 spmc_power_state bit7 */
			{    0, 0,2}, /* core2 spmc_power_state bit8 */
			{    0, 0,2}, /* core2 spmc_power_state bit9 */
			{    0, 0,2}, /* core2 spmc_power_state bit10 */
			{    0, 0,2}, /* core2 spmc_power_state bit11 */
			{    0, 0,2}, /* core2 spmc_power_state bit12 */
			{    0, 0,2}, /* core2 spmc_power_state bit13 */
			{    0, 0,2}, /* core2 spmc_power_state bit14 */
			{    0, 0,2}, /* core2 spmc_power_state bit15 */
			{    0, 0,2}, /* core2 spmc_power_state bit16 */
			{    0, 0,2}, /* core2 spmc_power_state bit17 */
			{    0, 0,2}, /* core2 spmc_power_state bit18 */
			{    0, 0,2}, /* core2 spmc_power_state bit19 */
			{    0, 0,2}, /* core2 spmc_power_state bit20 */
			{    0, 0,2}, /* core2 spmc_power_state bit21 */
			{    0, 0,2}, /* core2 spmc_power_state bit22 */
			{    0, 0,2}, /* core2 spmc_power_state bit23 */
			{    0, 0,2}, /* core2 spmc_power_state bit24 */
			{    0, 0,2}, /* core2 spmc_power_state bit25 */
			{    0, 0,2}, /* core2 spmc_power_state bit26 */
			{    0, 0,2}, /* core2 spmc_power_state bit27 */
			{    0, 0,2}, /* core2 spmc_power_state bit28 */
			{    0, 0,2}, /* core2 spmc_power_state bit29 */
			{    0, 0,2}, /* core2 spmc_power_state bit30 */
			{    0, 0,2}, /* core2 spmc_power_state bit31 */
			{    0, 0,2}, /* core2 spmc_power_state bit32 */
			{    0, 0,2}, /* core2 spmc_power_state bit33 */
			{    0, 0,2}, /* core2 spmc_power_state bit34 */
			{    0, 0,2}, /* core2 spmc_power_state bit35 */
			{    0, 0,2}, /* core2 spmc_power_state bit36 */
			{    0, 0,2}, /* core2 spmc_power_state bit37 */
			{    0, 0,2}, /* core2 spmc_power_state bit38 */
			{    0, 0,2}, /* core2 spmc_power_state bit39 */
			{    0, 0,2}, /* core2 spmc_power_state bit40 */
			{    0, 0,2}, /* core2 spmc_power_state bit41 */
			{    0, 0,2}, /* core2 spmc_power_state bit42 */
			{    0, 0,2}, /* core2 spmc_power_state bit43 */
			{    0, 0,2}, /* core2 spmc_power_state bit44 */
			{    0, 0,2}, /* core2 spmc_power_state bit45 */
			{    0, 0,2}, /* core2 spmc_power_state bit46 */
			{    0, 0,2}, /* core2 spmc_power_state bit47 */
			{    0, 0,2}, /* core2 spmc_power_state bit48 */
			{    0, 0,2}, /* core2 spmc_power_state bit49 */
			{    0, 0,2}, /* core2 spmc_power_state bit50 */
			{    0, 0,2}, /* core2 spmc_power_state bit51 */
			{    0, 0,2}, /* core2 spmc_power_state bit52 */
			{    0, 0,2}, /* core2 spmc_power_state bit53 */
			{    0, 0,2}, /* core2 spmc_power_state bit54 */
			{    0, 0,2}, /* core2 spmc_power_state bit55 */
			{    0, 0,2}, /* core2 spmc_power_state bit56 */
			{    0, 0,2}, /* core2 spmc_power_state bit57 */
			{    0, 0,2}, /* core2 spmc_power_state bit58 */
			{    0, 0,2}, /* core2 spmc_power_state bit59 */
			{    0, 0,2}, /* core2 spmc_power_state bit60 */
			{    0, 0,2}, /* core2 spmc_power_state bit61 */
			{    0, 0,2}, /* core2 spmc_power_state bit62 */
			{    0, 0,2}, /* core2 spmc_power_state bit63 */
			}},
			.pc = {{
			{23998, 5,1}, /* core2 pc bit0 */
			{24031, 5,1}, /* core2 pc bit1 */
			{24033, 5,1}, /* core2 pc bit2 */
			{24014, 5,1}, /* core2 pc bit3 */
			{24032, 5,1}, /* core2 pc bit4 */
			{24025, 5,1}, /* core2 pc bit5 */
			{16287, 5,1}, /* core2 pc bit6 */
			{24024, 5,1}, /* core2 pc bit7 */
			{16286, 5,1}, /* core2 pc bit8 */
			{24030, 5,1}, /* core2 pc bit9 */
			{24051, 5,1}, /* core2 pc bit10 */
			{ 9105, 4,1}, /* core2 pc bit11 */
			{ 9104, 4,1}, /* core2 pc bit12 */
			{23975, 5,1}, /* core2 pc bit13 */
			{24045, 5,1}, /* core2 pc bit14 */
			{24044, 5,1}, /* core2 pc bit15 */
			{24050, 5,1}, /* core2 pc bit16 */
			{24053, 5,1}, /* core2 pc bit17 */
			{24052, 5,1}, /* core2 pc bit18 */
			{24003, 5,1}, /* core2 pc bit19 */
			{24002, 5,1}, /* core2 pc bit20 */
			{24147, 5,1}, /* core2 pc bit21 */
			{24037, 5,1}, /* core2 pc bit22 */
			{ 9103, 4,1}, /* core2 pc bit23 */
			{24036, 5,1}, /* core2 pc bit24 */
			{24133, 5,1}, /* core2 pc bit25 */
			{ 9102, 4,1}, /* core2 pc bit26 */
			{23168, 5,1}, /* core2 pc bit27 */
			{24146, 5,1}, /* core2 pc bit28 */
			{23167, 5,1}, /* core2 pc bit29 */
			{24043, 5,1}, /* core2 pc bit30 */
			{24042, 5,1}, /* core2 pc bit31 */
			{23959, 5,1}, /* core2 pc bit32 */
			{23958, 5,1}, /* core2 pc bit33 */
			{23993, 5,1}, /* core2 pc bit34 */
			{23992, 5,1}, /* core2 pc bit35 */
			{24149, 5,1}, /* core2 pc bit36 */
			{24132, 5,1}, /* core2 pc bit37 */
			{23961, 5,1}, /* core2 pc bit38 */
			{23960, 5,1}, /* core2 pc bit39 */
			{23957, 5,1}, /* core2 pc bit40 */
			{23956, 5,1}, /* core2 pc bit41 */
			{23967, 5,1}, /* core2 pc bit42 */
			{24148, 5,1}, /* core2 pc bit43 */
			{22945, 4,1}, /* core2 pc bit44 */
			{22944, 4,1}, /* core2 pc bit45 */
			{23987, 5,1}, /* core2 pc bit46 */
			{23966, 5,1}, /* core2 pc bit47 */
			{23991, 5,1}, /* core2 pc bit48 */
			{23989, 5,1}, /* core2 pc bit49 */
			{23990, 5,1}, /* core2 pc bit50 */
			{23965, 5,1}, /* core2 pc bit51 */
			{23964, 5,1}, /* core2 pc bit52 */
			{23988, 5,1}, /* core2 pc bit53 */
			{24107, 5,1}, /* core2 pc bit54 */
			{24106, 5,1}, /* core2 pc bit55 */
			{23068, 5,1}, /* core2 pc bit56 */
			{ 9101, 4,1}, /* core2 pc bit57 */
			{23150, 5,1}, /* core2 pc bit58 */
			{23986, 5,1}, /* core2 pc bit59 */
			{23963, 5,1}, /* core2 pc bit60 */
			{ 9100, 4,1}, /* core2 pc bit61 */
			{23962, 5,1}, /* core2 pc bit62 */
			{23151, 5,1}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{10987, 4,1}, /* core2 sp32 bit0 */
			{10986, 4,1}, /* core2 sp32 bit1 */
			{23581, 4,1}, /* core2 sp32 bit2 */
			{23580, 4,1}, /* core2 sp32 bit3 */
			{10989, 4,1}, /* core2 sp32 bit4 */
			{23571, 4,1}, /* core2 sp32 bit5 */
			{23577, 4,1}, /* core2 sp32 bit6 */
			{16267, 5,1}, /* core2 sp32 bit7 */
			{10988, 4,1}, /* core2 sp32 bit8 */
			{23576, 4,1}, /* core2 sp32 bit9 */
			{16251, 5,1}, /* core2 sp32 bit10 */
			{23570, 4,1}, /* core2 sp32 bit11 */
			{16250, 5,1}, /* core2 sp32 bit12 */
			{23575, 4,1}, /* core2 sp32 bit13 */
			{23574, 4,1}, /* core2 sp32 bit14 */
			{16269, 5,1}, /* core2 sp32 bit15 */
			{16268, 5,1}, /* core2 sp32 bit16 */
			{16265, 5,1}, /* core2 sp32 bit17 */
			{16264, 5,1}, /* core2 sp32 bit18 */
			{16247, 5,1}, /* core2 sp32 bit19 */
			{23579, 4,1}, /* core2 sp32 bit20 */
			{23578, 4,1}, /* core2 sp32 bit21 */
			{16266, 5,1}, /* core2 sp32 bit22 */
			{24021, 5,1}, /* core2 sp32 bit23 */
			{16246, 5,1}, /* core2 sp32 bit24 */
			{16249, 5,1}, /* core2 sp32 bit25 */
			{24020, 5,1}, /* core2 sp32 bit26 */
			{16271, 5,1}, /* core2 sp32 bit27 */
			{16248, 5,1}, /* core2 sp32 bit28 */
			{23573, 4,1}, /* core2 sp32 bit29 */
			{23572, 4,1}, /* core2 sp32 bit30 */
			{16270, 5,1}, /* core2 sp32 bit31 */
			{13203, 4,1}, /* core2 sp32 bit32 */
			{13202, 4,1}, /* core2 sp32 bit33 */
			{13205, 4,1}, /* core2 sp32 bit34 */
			{13204, 4,1}, /* core2 sp32 bit35 */
			{13243, 4,1}, /* core2 sp32 bit36 */
			{13242, 4,1}, /* core2 sp32 bit37 */
			{12299, 4,1}, /* core2 sp32 bit38 */
			{13201, 4,1}, /* core2 sp32 bit39 */
			{13200, 4,1}, /* core2 sp32 bit40 */
			{12297, 4,1}, /* core2 sp32 bit41 */
			{12296, 4,1}, /* core2 sp32 bit42 */
			{12298, 4,1}, /* core2 sp32 bit43 */
			{13241, 4,1}, /* core2 sp32 bit44 */
			{13240, 4,1}, /* core2 sp32 bit45 */
			{13777, 4,1}, /* core2 sp32 bit46 */
			{13187, 4,1}, /* core2 sp32 bit47 */
			{13185, 4,1}, /* core2 sp32 bit48 */
			{13186, 4,1}, /* core2 sp32 bit49 */
			{13184, 4,1}, /* core2 sp32 bit50 */
			{12289, 4,1}, /* core2 sp32 bit51 */
			{12288, 4,1}, /* core2 sp32 bit52 */
			{13207, 4,1}, /* core2 sp32 bit53 */
			{13239, 4,1}, /* core2 sp32 bit54 */
			{13238, 4,1}, /* core2 sp32 bit55 */
			{13211, 4,1}, /* core2 sp32 bit56 */
			{13206, 4,1}, /* core2 sp32 bit57 */
			{12291, 4,1}, /* core2 sp32 bit58 */
			{12290, 4,1}, /* core2 sp32 bit59 */
			{13209, 4,1}, /* core2 sp32 bit60 */
			{13208, 4,1}, /* core2 sp32 bit61 */
			{13750, 4,1}, /* core2 sp32 bit62 */
			{13210, 4,1}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{16193, 5,1}, /* core2 fp32 bit0 */
			{16192, 5,1}, /* core2 fp32 bit1 */
			{16197, 5,1}, /* core2 fp32 bit2 */
			{16196, 5,1}, /* core2 fp32 bit3 */
			{16207, 5,1}, /* core2 fp32 bit4 */
			{16203, 5,1}, /* core2 fp32 bit5 */
			{16205, 5,1}, /* core2 fp32 bit6 */
			{16204, 5,1}, /* core2 fp32 bit7 */
			{16161, 5,1}, /* core2 fp32 bit8 */
			{16160, 5,1}, /* core2 fp32 bit9 */
			{16209, 5,1}, /* core2 fp32 bit10 */
			{16202, 5,1}, /* core2 fp32 bit11 */
			{16208, 5,1}, /* core2 fp32 bit12 */
			{11941, 4,1}, /* core2 fp32 bit13 */
			{11935, 4,1}, /* core2 fp32 bit14 */
			{16159, 5,1}, /* core2 fp32 bit15 */
			{11940, 4,1}, /* core2 fp32 bit16 */
			{16206, 5,1}, /* core2 fp32 bit17 */
			{16199, 5,1}, /* core2 fp32 bit18 */
			{16198, 5,1}, /* core2 fp32 bit19 */
			{11934, 4,1}, /* core2 fp32 bit20 */
			{16201, 5,1}, /* core2 fp32 bit21 */
			{16200, 5,1}, /* core2 fp32 bit22 */
			{11925, 4,1}, /* core2 fp32 bit23 */
			{11924, 4,1}, /* core2 fp32 bit24 */
			{11937, 4,1}, /* core2 fp32 bit25 */
			{16195, 5,1}, /* core2 fp32 bit26 */
			{13733, 4,1}, /* core2 fp32 bit27 */
			{11936, 4,1}, /* core2 fp32 bit28 */
			{16194, 5,1}, /* core2 fp32 bit29 */
			{11939, 4,1}, /* core2 fp32 bit30 */
			{11938, 4,1}, /* core2 fp32 bit31 */
			{14669, 4,1}, /* core2 fp32 bit32 */
			{14668, 4,1}, /* core2 fp32 bit33 */
			{14671, 4,1}, /* core2 fp32 bit34 */
			{14670, 4,1}, /* core2 fp32 bit35 */
			{14645, 4,1}, /* core2 fp32 bit36 */
			{14644, 4,1}, /* core2 fp32 bit37 */
			{14647, 4,1}, /* core2 fp32 bit38 */
			{14646, 4,1}, /* core2 fp32 bit39 */
			{13771, 4,1}, /* core2 fp32 bit40 */
			{14651, 4,1}, /* core2 fp32 bit41 */
			{14650, 4,1}, /* core2 fp32 bit42 */
			{14653, 4,1}, /* core2 fp32 bit43 */
			{14652, 4,1}, /* core2 fp32 bit44 */
			{14657, 4,1}, /* core2 fp32 bit45 */
			{14656, 4,1}, /* core2 fp32 bit46 */
			{14641, 4,1}, /* core2 fp32 bit47 */
			{14640, 4,1}, /* core2 fp32 bit48 */
			{14649, 4,1}, /* core2 fp32 bit49 */
			{14648, 4,1}, /* core2 fp32 bit50 */
			{14643, 4,1}, /* core2 fp32 bit51 */
			{14642, 4,1}, /* core2 fp32 bit52 */
			{14661, 4,1}, /* core2 fp32 bit53 */
			{14665, 4,1}, /* core2 fp32 bit54 */
			{14660, 4,1}, /* core2 fp32 bit55 */
			{14664, 4,1}, /* core2 fp32 bit56 */
			{14667, 4,1}, /* core2 fp32 bit57 */
			{14663, 4,1}, /* core2 fp32 bit58 */
			{14662, 4,1}, /* core2 fp32 bit59 */
			{14666, 4,1}, /* core2 fp32 bit60 */
			{14659, 4,1}, /* core2 fp32 bit61 */
			{14658, 4,1}, /* core2 fp32 bit62 */
			{13769, 4,1}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{10273, 4,1}, /* core2 fp64 bit0 */
			{10272, 4,1}, /* core2 fp64 bit1 */
			{10271, 4,1}, /* core2 fp64 bit2 */
			{10270, 4,1}, /* core2 fp64 bit3 */
			{16293, 5,1}, /* core2 fp64 bit4 */
			{16292, 5,1}, /* core2 fp64 bit5 */
			{16275, 5,1}, /* core2 fp64 bit6 */
			{16274, 5,1}, /* core2 fp64 bit7 */
			{16297, 5,1}, /* core2 fp64 bit8 */
			{16296, 5,1}, /* core2 fp64 bit9 */
			{16273, 5,1}, /* core2 fp64 bit10 */
			{16279, 5,1}, /* core2 fp64 bit11 */
			{16272, 5,1}, /* core2 fp64 bit12 */
			{16291, 5,1}, /* core2 fp64 bit13 */
			{16257, 5,1}, /* core2 fp64 bit14 */
			{16290, 5,1}, /* core2 fp64 bit15 */
			{24023, 5,1}, /* core2 fp64 bit16 */
			{16278, 5,1}, /* core2 fp64 bit17 */
			{16281, 5,1}, /* core2 fp64 bit18 */
			{16280, 5,1}, /* core2 fp64 bit19 */
			{16256, 5,1}, /* core2 fp64 bit20 */
			{16259, 5,1}, /* core2 fp64 bit21 */
			{16317, 5,1}, /* core2 fp64 bit22 */
			{16316, 5,1}, /* core2 fp64 bit23 */
			{16295, 5,1}, /* core2 fp64 bit24 */
			{16258, 5,1}, /* core2 fp64 bit25 */
			{16277, 5,1}, /* core2 fp64 bit26 */
			{24022, 5,1}, /* core2 fp64 bit27 */
			{16294, 5,1}, /* core2 fp64 bit28 */
			{16276, 5,1}, /* core2 fp64 bit29 */
			{16283, 5,1}, /* core2 fp64 bit30 */
			{16282, 5,1}, /* core2 fp64 bit31 */
			{ 9757, 4,1}, /* core2 fp64 bit32 */
			{ 9756, 4,1}, /* core2 fp64 bit33 */
			{ 9751, 4,1}, /* core2 fp64 bit34 */
			{ 9750, 4,1}, /* core2 fp64 bit35 */
			{ 9729, 4,1}, /* core2 fp64 bit36 */
			{ 9755, 4,1}, /* core2 fp64 bit37 */
			{ 9754, 4,1}, /* core2 fp64 bit38 */
			{ 9731, 4,1}, /* core2 fp64 bit39 */
			{ 9728, 4,1}, /* core2 fp64 bit40 */
			{ 9730, 4,1}, /* core2 fp64 bit41 */
			{ 9721, 4,1}, /* core2 fp64 bit42 */
			{13801, 4,1}, /* core2 fp64 bit43 */
			{ 9720, 4,1}, /* core2 fp64 bit44 */
			{ 9733, 4,1}, /* core2 fp64 bit45 */
			{ 9732, 4,1}, /* core2 fp64 bit46 */
			{ 9725, 4,1}, /* core2 fp64 bit47 */
			{ 9727, 4,1}, /* core2 fp64 bit48 */
			{ 9726, 4,1}, /* core2 fp64 bit49 */
			{ 9724, 4,1}, /* core2 fp64 bit50 */
			{ 9763, 4,1}, /* core2 fp64 bit51 */
			{ 9753, 4,1}, /* core2 fp64 bit52 */
			{ 9752, 4,1}, /* core2 fp64 bit53 */
			{ 9759, 4,1}, /* core2 fp64 bit54 */
			{ 9758, 4,1}, /* core2 fp64 bit55 */
			{ 9762, 4,1}, /* core2 fp64 bit56 */
			{ 9719, 4,1}, /* core2 fp64 bit57 */
			{13800, 4,1}, /* core2 fp64 bit58 */
			{ 9718, 4,1}, /* core2 fp64 bit59 */
			{ 9761, 4,1}, /* core2 fp64 bit60 */
			{ 9760, 4,1}, /* core2 fp64 bit61 */
			{ 9723, 4,1}, /* core2 fp64 bit62 */
			{ 9722, 4,1}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{12529, 4,1}, /* core2 sp_EL0 bit0 */
			{10485, 4,1}, /* core2 sp_EL0 bit1 */
			{10484, 4,1}, /* core2 sp_EL0 bit2 */
			{12527, 4,1}, /* core2 sp_EL0 bit3 */
			{10489, 4,1}, /* core2 sp_EL0 bit4 */
			{10488, 4,1}, /* core2 sp_EL0 bit5 */
			{12526, 4,1}, /* core2 sp_EL0 bit6 */
			{12528, 4,1}, /* core2 sp_EL0 bit7 */
			{12531, 4,1}, /* core2 sp_EL0 bit8 */
			{12530, 4,1}, /* core2 sp_EL0 bit9 */
			{12439, 4,1}, /* core2 sp_EL0 bit10 */
			{12523, 4,1}, /* core2 sp_EL0 bit11 */
			{10487, 4,1}, /* core2 sp_EL0 bit12 */
			{12438, 4,1}, /* core2 sp_EL0 bit13 */
			{12429, 4,1}, /* core2 sp_EL0 bit14 */
			{10486, 4,1}, /* core2 sp_EL0 bit15 */
			{13720, 4,1}, /* core2 sp_EL0 bit16 */
			{12428, 4,1}, /* core2 sp_EL0 bit17 */
			{12437, 4,1}, /* core2 sp_EL0 bit18 */
			{12436, 4,1}, /* core2 sp_EL0 bit19 */
			{12522, 4,1}, /* core2 sp_EL0 bit20 */
			{12525, 4,1}, /* core2 sp_EL0 bit21 */
			{12431, 4,1}, /* core2 sp_EL0 bit22 */
			{12430, 4,1}, /* core2 sp_EL0 bit23 */
			{12521, 4,1}, /* core2 sp_EL0 bit24 */
			{12524, 4,1}, /* core2 sp_EL0 bit25 */
			{12427, 4,1}, /* core2 sp_EL0 bit26 */
			{13721, 4,1}, /* core2 sp_EL0 bit27 */
			{12520, 4,1}, /* core2 sp_EL0 bit28 */
			{12426, 4,1}, /* core2 sp_EL0 bit29 */
			{12441, 4,1}, /* core2 sp_EL0 bit30 */
			{12440, 4,1}, /* core2 sp_EL0 bit31 */
			{12829, 4,1}, /* core2 sp_EL0 bit32 */
			{12828, 4,1}, /* core2 sp_EL0 bit33 */
			{12823, 4,1}, /* core2 sp_EL0 bit34 */
			{11205, 4,1}, /* core2 sp_EL0 bit35 */
			{12822, 4,1}, /* core2 sp_EL0 bit36 */
			{11213, 4,1}, /* core2 sp_EL0 bit37 */
			{11212, 4,1}, /* core2 sp_EL0 bit38 */
			{11211, 4,1}, /* core2 sp_EL0 bit39 */
			{11210, 4,1}, /* core2 sp_EL0 bit40 */
			{11204, 4,1}, /* core2 sp_EL0 bit41 */
			{11201, 4,1}, /* core2 sp_EL0 bit42 */
			{11200, 4,1}, /* core2 sp_EL0 bit43 */
			{12827, 4,1}, /* core2 sp_EL0 bit44 */
			{12826, 4,1}, /* core2 sp_EL0 bit45 */
			{14527, 4,1}, /* core2 sp_EL0 bit46 */
			{11217, 4,1}, /* core2 sp_EL0 bit47 */
			{11216, 4,1}, /* core2 sp_EL0 bit48 */
			{11207, 4,1}, /* core2 sp_EL0 bit49 */
			{12821, 4,1}, /* core2 sp_EL0 bit50 */
			{11206, 4,1}, /* core2 sp_EL0 bit51 */
			{12820, 4,1}, /* core2 sp_EL0 bit52 */
			{11219, 4,1}, /* core2 sp_EL0 bit53 */
			{11218, 4,1}, /* core2 sp_EL0 bit54 */
			{14231, 4,1}, /* core2 sp_EL0 bit55 */
			{12825, 4,1}, /* core2 sp_EL0 bit56 */
			{12824, 4,1}, /* core2 sp_EL0 bit57 */
			{11215, 4,1}, /* core2 sp_EL0 bit58 */
			{11214, 4,1}, /* core2 sp_EL0 bit59 */
			{11203, 4,1}, /* core2 sp_EL0 bit60 */
			{11202, 4,1}, /* core2 sp_EL0 bit61 */
			{14526, 4,1}, /* core2 sp_EL0 bit62 */
			{14528, 4,1}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{10269, 4,1}, /* core2 sp_EL1 bit0 */
			{10268, 4,1}, /* core2 sp_EL1 bit1 */
			{10267, 4,1}, /* core2 sp_EL1 bit2 */
			{10266, 4,1}, /* core2 sp_EL1 bit3 */
			{16243, 5,1}, /* core2 sp_EL1 bit4 */
			{16242, 5,1}, /* core2 sp_EL1 bit5 */
			{10991, 4,1}, /* core2 sp_EL1 bit6 */
			{10990, 4,1}, /* core2 sp_EL1 bit7 */
			{16255, 5,1}, /* core2 sp_EL1 bit8 */
			{16254, 5,1}, /* core2 sp_EL1 bit9 */
			{16263, 5,1}, /* core2 sp_EL1 bit10 */
			{16237, 5,1}, /* core2 sp_EL1 bit11 */
			{16262, 5,1}, /* core2 sp_EL1 bit12 */
			{16245, 5,1}, /* core2 sp_EL1 bit13 */
			{16236, 5,1}, /* core2 sp_EL1 bit14 */
			{16253, 5,1}, /* core2 sp_EL1 bit15 */
			{16252, 5,1}, /* core2 sp_EL1 bit16 */
			{16233, 5,1}, /* core2 sp_EL1 bit17 */
			{16232, 5,1}, /* core2 sp_EL1 bit18 */
			{16235, 5,1}, /* core2 sp_EL1 bit19 */
			{10985, 4,1}, /* core2 sp_EL1 bit20 */
			{16234, 5,1}, /* core2 sp_EL1 bit21 */
			{16244, 5,1}, /* core2 sp_EL1 bit22 */
			{16239, 5,1}, /* core2 sp_EL1 bit23 */
			{23070, 5,1}, /* core2 sp_EL1 bit24 */
			{10984, 4,1}, /* core2 sp_EL1 bit25 */
			{16261, 5,1}, /* core2 sp_EL1 bit26 */
			{16260, 5,1}, /* core2 sp_EL1 bit27 */
			{16238, 5,1}, /* core2 sp_EL1 bit28 */
			{23069, 5,1}, /* core2 sp_EL1 bit29 */
			{16241, 5,1}, /* core2 sp_EL1 bit30 */
			{16240, 5,1}, /* core2 sp_EL1 bit31 */
			{24089, 4,1}, /* core2 sp_EL1 bit32 */
			{24088, 4,1}, /* core2 sp_EL1 bit33 */
			{12803, 4,1}, /* core2 sp_EL1 bit34 */
			{11221, 4,1}, /* core2 sp_EL1 bit35 */
			{11220, 4,1}, /* core2 sp_EL1 bit36 */
			{12799, 4,1}, /* core2 sp_EL1 bit37 */
			{12798, 4,1}, /* core2 sp_EL1 bit38 */
			{24091, 4,1}, /* core2 sp_EL1 bit39 */
			{24090, 4,1}, /* core2 sp_EL1 bit40 */
			{12802, 4,1}, /* core2 sp_EL1 bit41 */
			{12807, 4,1}, /* core2 sp_EL1 bit42 */
			{12801, 4,1}, /* core2 sp_EL1 bit43 */
			{12800, 4,1}, /* core2 sp_EL1 bit44 */
			{14517, 4,1}, /* core2 sp_EL1 bit45 */
			{12806, 4,1}, /* core2 sp_EL1 bit46 */
			{12809, 4,1}, /* core2 sp_EL1 bit47 */
			{12808, 4,1}, /* core2 sp_EL1 bit48 */
			{12797, 4,1}, /* core2 sp_EL1 bit49 */
			{24085, 4,1}, /* core2 sp_EL1 bit50 */
			{24084, 4,1}, /* core2 sp_EL1 bit51 */
			{12805, 4,1}, /* core2 sp_EL1 bit52 */
			{12796, 4,1}, /* core2 sp_EL1 bit53 */
			{12804, 4,1}, /* core2 sp_EL1 bit54 */
			{24081, 4,1}, /* core2 sp_EL1 bit55 */
			{24080, 4,1}, /* core2 sp_EL1 bit56 */
			{24087, 4,1}, /* core2 sp_EL1 bit57 */
			{14515, 4,1}, /* core2 sp_EL1 bit58 */
			{24086, 4,1}, /* core2 sp_EL1 bit59 */
			{24083, 4,1}, /* core2 sp_EL1 bit60 */
			{24082, 4,1}, /* core2 sp_EL1 bit61 */
			{14516, 4,1}, /* core2 sp_EL1 bit62 */
			{14514, 4,1}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{10265, 4,1}, /* core2 sp_EL2 bit0 */
			{10264, 4,1}, /* core2 sp_EL2 bit1 */
			{10263, 4,1}, /* core2 sp_EL2 bit2 */
			{10262, 4,1}, /* core2 sp_EL2 bit3 */
			{12503, 4,1}, /* core2 sp_EL2 bit4 */
			{12502, 4,1}, /* core2 sp_EL2 bit5 */
			{12549, 4,1}, /* core2 sp_EL2 bit6 */
			{12548, 4,1}, /* core2 sp_EL2 bit7 */
			{12507, 4,1}, /* core2 sp_EL2 bit8 */
			{12506, 4,1}, /* core2 sp_EL2 bit9 */
			{12509, 4,1}, /* core2 sp_EL2 bit10 */
			{12559, 4,1}, /* core2 sp_EL2 bit11 */
			{12508, 4,1}, /* core2 sp_EL2 bit12 */
			{12505, 4,1}, /* core2 sp_EL2 bit13 */
			{12551, 4,1}, /* core2 sp_EL2 bit14 */
			{12547, 4,1}, /* core2 sp_EL2 bit15 */
			{12546, 4,1}, /* core2 sp_EL2 bit16 */
			{12558, 4,1}, /* core2 sp_EL2 bit17 */
			{12557, 4,1}, /* core2 sp_EL2 bit18 */
			{12556, 4,1}, /* core2 sp_EL2 bit19 */
			{12550, 4,1}, /* core2 sp_EL2 bit20 */
			{12553, 4,1}, /* core2 sp_EL2 bit21 */
			{12501, 4,1}, /* core2 sp_EL2 bit22 */
			{14539, 4,1}, /* core2 sp_EL2 bit23 */
			{12500, 4,1}, /* core2 sp_EL2 bit24 */
			{12555, 4,1}, /* core2 sp_EL2 bit25 */
			{12504, 4,1}, /* core2 sp_EL2 bit26 */
			{12552, 4,1}, /* core2 sp_EL2 bit27 */
			{12554, 4,1}, /* core2 sp_EL2 bit28 */
			{13717, 4,1}, /* core2 sp_EL2 bit29 */
			{12499, 4,1}, /* core2 sp_EL2 bit30 */
			{12498, 4,1}, /* core2 sp_EL2 bit31 */
			{12765, 4,1}, /* core2 sp_EL2 bit32 */
			{12764, 4,1}, /* core2 sp_EL2 bit33 */
			{12853, 4,1}, /* core2 sp_EL2 bit34 */
			{12761, 4,1}, /* core2 sp_EL2 bit35 */
			{12760, 4,1}, /* core2 sp_EL2 bit36 */
			{12852, 4,1}, /* core2 sp_EL2 bit37 */
			{12851, 4,1}, /* core2 sp_EL2 bit38 */
			{12850, 4,1}, /* core2 sp_EL2 bit39 */
			{14520, 4,1}, /* core2 sp_EL2 bit40 */
			{12855, 4,1}, /* core2 sp_EL2 bit41 */
			{12854, 4,1}, /* core2 sp_EL2 bit42 */
			{12863, 4,1}, /* core2 sp_EL2 bit43 */
			{12862, 4,1}, /* core2 sp_EL2 bit44 */
			{12763, 4,1}, /* core2 sp_EL2 bit45 */
			{12762, 4,1}, /* core2 sp_EL2 bit46 */
			{12857, 4,1}, /* core2 sp_EL2 bit47 */
			{12859, 4,1}, /* core2 sp_EL2 bit48 */
			{12858, 4,1}, /* core2 sp_EL2 bit49 */
			{12856, 4,1}, /* core2 sp_EL2 bit50 */
			{12865, 4,1}, /* core2 sp_EL2 bit51 */
			{12867, 4,1}, /* core2 sp_EL2 bit52 */
			{12866, 4,1}, /* core2 sp_EL2 bit53 */
			{12864, 4,1}, /* core2 sp_EL2 bit54 */
			{12861, 4,1}, /* core2 sp_EL2 bit55 */
			{12860, 4,1}, /* core2 sp_EL2 bit56 */
			{12871, 4,1}, /* core2 sp_EL2 bit57 */
			{12870, 4,1}, /* core2 sp_EL2 bit58 */
			{12759, 4,1}, /* core2 sp_EL2 bit59 */
			{12758, 4,1}, /* core2 sp_EL2 bit60 */
			{12869, 4,1}, /* core2 sp_EL2 bit61 */
			{12868, 4,1}, /* core2 sp_EL2 bit62 */
			{14445, 4,1}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{12453, 4,1}, /* core2 sp_EL3 bit0 */
			{12452, 4,1}, /* core2 sp_EL3 bit1 */
			{12513, 4,1}, /* core2 sp_EL3 bit2 */
			{12447, 4,1}, /* core2 sp_EL3 bit3 */
			{12515, 4,1}, /* core2 sp_EL3 bit4 */
			{12514, 4,1}, /* core2 sp_EL3 bit5 */
			{12446, 4,1}, /* core2 sp_EL3 bit6 */
			{12443, 4,1}, /* core2 sp_EL3 bit7 */
			{12512, 4,1}, /* core2 sp_EL3 bit8 */
			{12511, 4,1}, /* core2 sp_EL3 bit9 */
			{12442, 4,1}, /* core2 sp_EL3 bit10 */
			{12423, 4,1}, /* core2 sp_EL3 bit11 */
			{12445, 4,1}, /* core2 sp_EL3 bit12 */
			{12510, 4,1}, /* core2 sp_EL3 bit13 */
			{12449, 4,1}, /* core2 sp_EL3 bit14 */
			{12444, 4,1}, /* core2 sp_EL3 bit15 */
			{14538, 4,1}, /* core2 sp_EL3 bit16 */
			{12422, 4,1}, /* core2 sp_EL3 bit17 */
			{12451, 4,1}, /* core2 sp_EL3 bit18 */
			{12450, 4,1}, /* core2 sp_EL3 bit19 */
			{12448, 4,1}, /* core2 sp_EL3 bit20 */
			{12457, 4,1}, /* core2 sp_EL3 bit21 */
			{12459, 4,1}, /* core2 sp_EL3 bit22 */
			{12456, 4,1}, /* core2 sp_EL3 bit23 */
			{12458, 4,1}, /* core2 sp_EL3 bit24 */
			{12455, 4,1}, /* core2 sp_EL3 bit25 */
			{12425, 4,1}, /* core2 sp_EL3 bit26 */
			{12424, 4,1}, /* core2 sp_EL3 bit27 */
			{12461, 4,1}, /* core2 sp_EL3 bit28 */
			{12454, 4,1}, /* core2 sp_EL3 bit29 */
			{12460, 4,1}, /* core2 sp_EL3 bit30 */
			{13716, 4,1}, /* core2 sp_EL3 bit31 */
			{12115, 4,1}, /* core2 sp_EL3 bit32 */
			{12114, 4,1}, /* core2 sp_EL3 bit33 */
			{14149, 4,1}, /* core2 sp_EL3 bit34 */
			{23991, 4,1}, /* core2 sp_EL3 bit35 */
			{14148, 4,1}, /* core2 sp_EL3 bit36 */
			{14147, 4,1}, /* core2 sp_EL3 bit37 */
			{14146, 4,1}, /* core2 sp_EL3 bit38 */
			{24247, 4,1}, /* core2 sp_EL3 bit39 */
			{24246, 4,1}, /* core2 sp_EL3 bit40 */
			{23990, 4,1}, /* core2 sp_EL3 bit41 */
			{23993, 4,1}, /* core2 sp_EL3 bit42 */
			{23992, 4,1}, /* core2 sp_EL3 bit43 */
			{12113, 4,1}, /* core2 sp_EL3 bit44 */
			{12112, 4,1}, /* core2 sp_EL3 bit45 */
			{14510, 4,1}, /* core2 sp_EL3 bit46 */
			{14143, 4,1}, /* core2 sp_EL3 bit47 */
			{14142, 4,1}, /* core2 sp_EL3 bit48 */
			{14061, 4,1}, /* core2 sp_EL3 bit49 */
			{14060, 4,1}, /* core2 sp_EL3 bit50 */
			{24245, 4,1}, /* core2 sp_EL3 bit51 */
			{24244, 4,1}, /* core2 sp_EL3 bit52 */
			{14509, 4,1}, /* core2 sp_EL3 bit53 */
			{14145, 4,1}, /* core2 sp_EL3 bit54 */
			{14144, 4,1}, /* core2 sp_EL3 bit55 */
			{12111, 4,1}, /* core2 sp_EL3 bit56 */
			{12110, 4,1}, /* core2 sp_EL3 bit57 */
			{14063, 4,1}, /* core2 sp_EL3 bit58 */
			{14062, 4,1}, /* core2 sp_EL3 bit59 */
			{24249, 4,1}, /* core2 sp_EL3 bit60 */
			{24248, 4,1}, /* core2 sp_EL3 bit61 */
			{14501, 4,1}, /* core2 sp_EL3 bit62 */
			{14508, 4,1}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{10491, 4,1}, /* core2 elr_EL1 bit0 */
			{10490, 4,1}, /* core2 elr_EL1 bit1 */
			{10493, 4,1}, /* core2 elr_EL1 bit2 */
			{13718, 4,1}, /* core2 elr_EL1 bit3 */
			{12545, 4,1}, /* core2 elr_EL1 bit4 */
			{12519, 4,1}, /* core2 elr_EL1 bit5 */
			{12539, 4,1}, /* core2 elr_EL1 bit6 */
			{12538, 4,1}, /* core2 elr_EL1 bit7 */
			{10492, 4,1}, /* core2 elr_EL1 bit8 */
			{12535, 4,1}, /* core2 elr_EL1 bit9 */
			{10499, 4,1}, /* core2 elr_EL1 bit10 */
			{12544, 4,1}, /* core2 elr_EL1 bit11 */
			{12534, 4,1}, /* core2 elr_EL1 bit12 */
			{12537, 4,1}, /* core2 elr_EL1 bit13 */
			{12518, 4,1}, /* core2 elr_EL1 bit14 */
			{12536, 4,1}, /* core2 elr_EL1 bit15 */
			{13719, 4,1}, /* core2 elr_EL1 bit16 */
			{10497, 4,1}, /* core2 elr_EL1 bit17 */
			{10496, 4,1}, /* core2 elr_EL1 bit18 */
			{10495, 4,1}, /* core2 elr_EL1 bit19 */
			{12541, 4,1}, /* core2 elr_EL1 bit20 */
			{10494, 4,1}, /* core2 elr_EL1 bit21 */
			{12517, 4,1}, /* core2 elr_EL1 bit22 */
			{12516, 4,1}, /* core2 elr_EL1 bit23 */
			{13715, 4,1}, /* core2 elr_EL1 bit24 */
			{12540, 4,1}, /* core2 elr_EL1 bit25 */
			{10498, 4,1}, /* core2 elr_EL1 bit26 */
			{12533, 4,1}, /* core2 elr_EL1 bit27 */
			{12543, 4,1}, /* core2 elr_EL1 bit28 */
			{12532, 4,1}, /* core2 elr_EL1 bit29 */
			{12542, 4,1}, /* core2 elr_EL1 bit30 */
			{13714, 4,1}, /* core2 elr_EL1 bit31 */
			{14131, 4,1}, /* core2 elr_EL1 bit32 */
			{14073, 4,1}, /* core2 elr_EL1 bit33 */
			{14072, 4,1}, /* core2 elr_EL1 bit34 */
			{14130, 4,1}, /* core2 elr_EL1 bit35 */
			{14123, 4,1}, /* core2 elr_EL1 bit36 */
			{14122, 4,1}, /* core2 elr_EL1 bit37 */
			{14125, 4,1}, /* core2 elr_EL1 bit38 */
			{14071, 4,1}, /* core2 elr_EL1 bit39 */
			{14070, 4,1}, /* core2 elr_EL1 bit40 */
			{14124, 4,1}, /* core2 elr_EL1 bit41 */
			{14133, 4,1}, /* core2 elr_EL1 bit42 */
			{14132, 4,1}, /* core2 elr_EL1 bit43 */
			{14127, 4,1}, /* core2 elr_EL1 bit44 */
			{14126, 4,1}, /* core2 elr_EL1 bit45 */
			{13802, 4,1}, /* core2 elr_EL1 bit46 */
			{14135, 4,1}, /* core2 elr_EL1 bit47 */
			{14134, 4,1}, /* core2 elr_EL1 bit48 */
			{14069, 4,1}, /* core2 elr_EL1 bit49 */
			{14068, 4,1}, /* core2 elr_EL1 bit50 */
			{14129, 4,1}, /* core2 elr_EL1 bit51 */
			{14067, 4,1}, /* core2 elr_EL1 bit52 */
			{14066, 4,1}, /* core2 elr_EL1 bit53 */
			{14141, 4,1}, /* core2 elr_EL1 bit54 */
			{14128, 4,1}, /* core2 elr_EL1 bit55 */
			{14140, 4,1}, /* core2 elr_EL1 bit56 */
			{14065, 4,1}, /* core2 elr_EL1 bit57 */
			{14064, 4,1}, /* core2 elr_EL1 bit58 */
			{14139, 4,1}, /* core2 elr_EL1 bit59 */
			{14138, 4,1}, /* core2 elr_EL1 bit60 */
			{14137, 4,1}, /* core2 elr_EL1 bit61 */
			{14136, 4,1}, /* core2 elr_EL1 bit62 */
			{14499, 4,1}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{24107, 4,1}, /* core2 elr_EL2 bit0 */
			{24106, 4,1}, /* core2 elr_EL2 bit1 */
			{11155, 4,1}, /* core2 elr_EL2 bit2 */
			{11154, 4,1}, /* core2 elr_EL2 bit3 */
			{24113, 4,1}, /* core2 elr_EL2 bit4 */
			{24112, 4,1}, /* core2 elr_EL2 bit5 */
			{11165, 4,1}, /* core2 elr_EL2 bit6 */
			{11164, 4,1}, /* core2 elr_EL2 bit7 */
			{24109, 4,1}, /* core2 elr_EL2 bit8 */
			{24108, 4,1}, /* core2 elr_EL2 bit9 */
			{24117, 4,1}, /* core2 elr_EL2 bit10 */
			{24105, 4,1}, /* core2 elr_EL2 bit11 */
			{24116, 4,1}, /* core2 elr_EL2 bit12 */
			{11161, 4,1}, /* core2 elr_EL2 bit13 */
			{24115, 4,1}, /* core2 elr_EL2 bit14 */
			{11160, 4,1}, /* core2 elr_EL2 bit15 */
			{11157, 4,1}, /* core2 elr_EL2 bit16 */
			{24104, 4,1}, /* core2 elr_EL2 bit17 */
			{11169, 4,1}, /* core2 elr_EL2 bit18 */
			{24114, 4,1}, /* core2 elr_EL2 bit19 */
			{11159, 4,1}, /* core2 elr_EL2 bit20 */
			{11158, 4,1}, /* core2 elr_EL2 bit21 */
			{11163, 4,1}, /* core2 elr_EL2 bit22 */
			{11168, 4,1}, /* core2 elr_EL2 bit23 */
			{11162, 4,1}, /* core2 elr_EL2 bit24 */
			{24111, 4,1}, /* core2 elr_EL2 bit25 */
			{11156, 4,1}, /* core2 elr_EL2 bit26 */
			{13693, 4,1}, /* core2 elr_EL2 bit27 */
			{11167, 4,1}, /* core2 elr_EL2 bit28 */
			{11166, 4,1}, /* core2 elr_EL2 bit29 */
			{14449, 4,1}, /* core2 elr_EL2 bit30 */
			{24110, 4,1}, /* core2 elr_EL2 bit31 */
			{24243, 4,1}, /* core2 elr_EL2 bit32 */
			{24075, 4,1}, /* core2 elr_EL2 bit33 */
			{24074, 4,1}, /* core2 elr_EL2 bit34 */
			{24242, 4,1}, /* core2 elr_EL2 bit35 */
			{23987, 4,1}, /* core2 elr_EL2 bit36 */
			{24071, 4,1}, /* core2 elr_EL2 bit37 */
			{24070, 4,1}, /* core2 elr_EL2 bit38 */
			{23983, 4,1}, /* core2 elr_EL2 bit39 */
			{23982, 4,1}, /* core2 elr_EL2 bit40 */
			{23986, 4,1}, /* core2 elr_EL2 bit41 */
			{24079, 4,1}, /* core2 elr_EL2 bit42 */
			{24078, 4,1}, /* core2 elr_EL2 bit43 */
			{24073, 4,1}, /* core2 elr_EL2 bit44 */
			{24072, 4,1}, /* core2 elr_EL2 bit45 */
			{14511, 4,1}, /* core2 elr_EL2 bit46 */
			{24241, 4,1}, /* core2 elr_EL2 bit47 */
			{24240, 4,1}, /* core2 elr_EL2 bit48 */
			{24065, 4,1}, /* core2 elr_EL2 bit49 */
			{24064, 4,1}, /* core2 elr_EL2 bit50 */
			{24063, 4,1}, /* core2 elr_EL2 bit51 */
			{23989, 4,1}, /* core2 elr_EL2 bit52 */
			{24069, 4,1}, /* core2 elr_EL2 bit53 */
			{23988, 4,1}, /* core2 elr_EL2 bit54 */
			{23985, 4,1}, /* core2 elr_EL2 bit55 */
			{24062, 4,1}, /* core2 elr_EL2 bit56 */
			{23984, 4,1}, /* core2 elr_EL2 bit57 */
			{24067, 4,1}, /* core2 elr_EL2 bit58 */
			{24066, 4,1}, /* core2 elr_EL2 bit59 */
			{24077, 4,1}, /* core2 elr_EL2 bit60 */
			{24076, 4,1}, /* core2 elr_EL2 bit61 */
			{14512, 4,1}, /* core2 elr_EL2 bit62 */
			{24068, 4,1}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{11309, 4,1}, /* core2 elr_EL3 bit0 */
			{12421, 4,1}, /* core2 elr_EL3 bit1 */
			{12420, 4,1}, /* core2 elr_EL3 bit2 */
			{14537, 4,1}, /* core2 elr_EL3 bit3 */
			{12419, 4,1}, /* core2 elr_EL3 bit4 */
			{12418, 4,1}, /* core2 elr_EL3 bit5 */
			{11308, 4,1}, /* core2 elr_EL3 bit6 */
			{12465, 4,1}, /* core2 elr_EL3 bit7 */
			{12464, 4,1}, /* core2 elr_EL3 bit8 */
			{24351, 4,0}, /* core2 elr_EL3 bit9 */
			{11307, 4,1}, /* core2 elr_EL3 bit10 */
			{11317, 4,1}, /* core2 elr_EL3 bit11 */
			{11306, 4,1}, /* core2 elr_EL3 bit12 */
			{24350, 4,0}, /* core2 elr_EL3 bit13 */
			{11316, 4,1}, /* core2 elr_EL3 bit14 */
			{12417, 4,1}, /* core2 elr_EL3 bit15 */
			{12416, 4,1}, /* core2 elr_EL3 bit16 */
			{11305, 4,1}, /* core2 elr_EL3 bit17 */
			{11304, 4,1}, /* core2 elr_EL3 bit18 */
			{11311, 4,1}, /* core2 elr_EL3 bit19 */
			{11315, 4,1}, /* core2 elr_EL3 bit20 */
			{11314, 4,1}, /* core2 elr_EL3 bit21 */
			{11310, 4,1}, /* core2 elr_EL3 bit22 */
			{12463, 4,1}, /* core2 elr_EL3 bit23 */
			{12462, 4,1}, /* core2 elr_EL3 bit24 */
			{14533, 4,1}, /* core2 elr_EL3 bit25 */
			{24349, 4,0}, /* core2 elr_EL3 bit26 */
			{24348, 4,0}, /* core2 elr_EL3 bit27 */
			{11313, 4,1}, /* core2 elr_EL3 bit28 */
			{13811, 4,1}, /* core2 elr_EL3 bit29 */
			{11312, 4,1}, /* core2 elr_EL3 bit30 */
			{14534, 4,1}, /* core2 elr_EL3 bit31 */
			{12771, 4,1}, /* core2 elr_EL3 bit32 */
			{12770, 4,1}, /* core2 elr_EL3 bit33 */
			{12773, 4,1}, /* core2 elr_EL3 bit34 */
			{12783, 4,1}, /* core2 elr_EL3 bit35 */
			{12782, 4,1}, /* core2 elr_EL3 bit36 */
			{12839, 4,1}, /* core2 elr_EL3 bit37 */
			{12772, 4,1}, /* core2 elr_EL3 bit38 */
			{12838, 4,1}, /* core2 elr_EL3 bit39 */
			{12767, 4,1}, /* core2 elr_EL3 bit40 */
			{12841, 4,1}, /* core2 elr_EL3 bit41 */
			{12840, 4,1}, /* core2 elr_EL3 bit42 */
			{12766, 4,1}, /* core2 elr_EL3 bit43 */
			{12781, 4,1}, /* core2 elr_EL3 bit44 */
			{12780, 4,1}, /* core2 elr_EL3 bit45 */
			{14522, 4,1}, /* core2 elr_EL3 bit46 */
			{12769, 4,1}, /* core2 elr_EL3 bit47 */
			{12775, 4,1}, /* core2 elr_EL3 bit48 */
			{12774, 4,1}, /* core2 elr_EL3 bit49 */
			{12777, 4,1}, /* core2 elr_EL3 bit50 */
			{12776, 4,1}, /* core2 elr_EL3 bit51 */
			{12843, 4,1}, /* core2 elr_EL3 bit52 */
			{12842, 4,1}, /* core2 elr_EL3 bit53 */
			{12779, 4,1}, /* core2 elr_EL3 bit54 */
			{12778, 4,1}, /* core2 elr_EL3 bit55 */
			{12768, 4,1}, /* core2 elr_EL3 bit56 */
			{12845, 4,1}, /* core2 elr_EL3 bit57 */
			{12844, 4,1}, /* core2 elr_EL3 bit58 */
			{12847, 4,1}, /* core2 elr_EL3 bit59 */
			{12846, 4,1}, /* core2 elr_EL3 bit60 */
			{12849, 4,1}, /* core2 elr_EL3 bit61 */
			{12848, 4,1}, /* core2 elr_EL3 bit62 */
			{14521, 4,1}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{10298, 4,1}, /* core2 raw_pc bit0 */
			{10297, 4,1}, /* core2 raw_pc bit1 */
			{10296, 4,1}, /* core2 raw_pc bit2 */
			{10579, 4,1}, /* core2 raw_pc bit3 */
			{10578, 4,1}, /* core2 raw_pc bit4 */
			{10577, 4,1}, /* core2 raw_pc bit5 */
			{10576, 4,1}, /* core2 raw_pc bit6 */
			{10435, 4,1}, /* core2 raw_pc bit7 */
			{10434, 4,1}, /* core2 raw_pc bit8 */
			{10425, 4,1}, /* core2 raw_pc bit9 */
			{10424, 4,1}, /* core2 raw_pc bit10 */
			{10437, 4,1}, /* core2 raw_pc bit11 */
			{10427, 4,1}, /* core2 raw_pc bit12 */
			{10426, 4,1}, /* core2 raw_pc bit13 */
			{10423, 4,1}, /* core2 raw_pc bit14 */
			{10597, 4,1}, /* core2 raw_pc bit15 */
			{10436, 4,1}, /* core2 raw_pc bit16 */
			{10595, 4,1}, /* core2 raw_pc bit17 */
			{10594, 4,1}, /* core2 raw_pc bit18 */
			{10596, 4,1}, /* core2 raw_pc bit19 */
			{10439, 4,1}, /* core2 raw_pc bit20 */
			{10438, 4,1}, /* core2 raw_pc bit21 */
			{10431, 4,1}, /* core2 raw_pc bit22 */
			{10430, 4,1}, /* core2 raw_pc bit23 */
			{10433, 4,1}, /* core2 raw_pc bit24 */
			{10432, 4,1}, /* core2 raw_pc bit25 */
			{22628, 4,1}, /* core2 raw_pc bit26 */
			{10422, 4,1}, /* core2 raw_pc bit27 */
			{10429, 4,1}, /* core2 raw_pc bit28 */
			{10428, 4,1}, /* core2 raw_pc bit29 */
			{22629, 4,1}, /* core2 raw_pc bit30 */
			{22249, 4,1}, /* core2 raw_pc bit31 */
			{22248, 4,1}, /* core2 raw_pc bit32 */
			{22251, 4,1}, /* core2 raw_pc bit33 */
			{22257, 4,1}, /* core2 raw_pc bit34 */
			{22250, 4,1}, /* core2 raw_pc bit35 */
			{22219, 4,1}, /* core2 raw_pc bit36 */
			{22256, 4,1}, /* core2 raw_pc bit37 */
			{22218, 4,1}, /* core2 raw_pc bit38 */
			{22253, 4,1}, /* core2 raw_pc bit39 */
			{22215, 4,1}, /* core2 raw_pc bit40 */
			{22252, 4,1}, /* core2 raw_pc bit41 */
			{22214, 4,1}, /* core2 raw_pc bit42 */
			{22217, 4,1}, /* core2 raw_pc bit43 */
			{22255, 4,1}, /* core2 raw_pc bit44 */
			{22254, 4,1}, /* core2 raw_pc bit45 */
			{22216, 4,1}, /* core2 raw_pc bit46 */
			{23218, 4,1}, /* core2 raw_pc bit47 */
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
			{22649, 4,1}, /* core2 pc_iss bit0 */
			{22279, 4,1}, /* core2 pc_iss bit1 */
			{22278, 4,1}, /* core2 pc_iss bit2 */
			{ 9131, 4,1}, /* core2 pc_iss bit3 */
			{ 9130, 4,1}, /* core2 pc_iss bit4 */
			{22281, 4,1}, /* core2 pc_iss bit5 */
			{22280, 4,1}, /* core2 pc_iss bit6 */
			{22648, 4,1}, /* core2 pc_iss bit7 */
			{22261, 4,1}, /* core2 pc_iss bit8 */
			{22260, 4,1}, /* core2 pc_iss bit9 */
			{22263, 4,1}, /* core2 pc_iss bit10 */
			{22262, 4,1}, /* core2 pc_iss bit11 */
			{22293, 4,1}, /* core2 pc_iss bit12 */
			{22292, 4,1}, /* core2 pc_iss bit13 */
			{22259, 4,1}, /* core2 pc_iss bit14 */
			{22258, 4,1}, /* core2 pc_iss bit15 */
			{22299, 4,1}, /* core2 pc_iss bit16 */
			{22298, 4,1}, /* core2 pc_iss bit17 */
			{23221, 4,1}, /* core2 pc_iss bit18 */
			{22285, 4,1}, /* core2 pc_iss bit19 */
			{22284, 4,1}, /* core2 pc_iss bit20 */
			{22297, 4,1}, /* core2 pc_iss bit21 */
			{22296, 4,1}, /* core2 pc_iss bit22 */
			{22295, 4,1}, /* core2 pc_iss bit23 */
			{22294, 4,1}, /* core2 pc_iss bit24 */
			{22291, 4,1}, /* core2 pc_iss bit25 */
			{22290, 4,1}, /* core2 pc_iss bit26 */
			{22287, 4,1}, /* core2 pc_iss bit27 */
			{22286, 4,1}, /* core2 pc_iss bit28 */
			{22289, 4,1}, /* core2 pc_iss bit29 */
			{22288, 4,1}, /* core2 pc_iss bit30 */
			{23220, 4,1}, /* core2 pc_iss bit31 */
			{22341, 4,1}, /* core2 pc_iss bit32 */
			{22340, 4,1}, /* core2 pc_iss bit33 */
			{22337, 4,1}, /* core2 pc_iss bit34 */
			{22336, 4,1}, /* core2 pc_iss bit35 */
			{22339, 4,1}, /* core2 pc_iss bit36 */
			{22338, 4,1}, /* core2 pc_iss bit37 */
			{21785, 4,1}, /* core2 pc_iss bit38 */
			{21784, 4,1}, /* core2 pc_iss bit39 */
			{23215, 4,1}, /* core2 pc_iss bit40 */
			{23214, 4,1}, /* core2 pc_iss bit41 */
			{22335, 4,1}, /* core2 pc_iss bit42 */
			{21783, 4,1}, /* core2 pc_iss bit43 */
			{22334, 4,1}, /* core2 pc_iss bit44 */
			{22333, 4,1}, /* core2 pc_iss bit45 */
			{21782, 4,1}, /* core2 pc_iss bit46 */
			{22332, 4,1}, /* core2 pc_iss bit47 */
			{21775, 4,1}, /* core2 pc_iss bit48 */
			{21774, 4,1}, /* core2 pc_iss bit49 */
			{21777, 4,1}, /* core2 pc_iss bit50 */
			{22327, 4,1}, /* core2 pc_iss bit51 */
			{22326, 4,1}, /* core2 pc_iss bit52 */
			{22325, 4,1}, /* core2 pc_iss bit53 */
			{22324, 4,1}, /* core2 pc_iss bit54 */
			{21776, 4,1}, /* core2 pc_iss bit55 */
			{22331, 4,1}, /* core2 pc_iss bit56 */
			{22330, 4,1}, /* core2 pc_iss bit57 */
			{22329, 4,1}, /* core2 pc_iss bit58 */
			{22328, 4,1}, /* core2 pc_iss bit59 */
			{21779, 4,1}, /* core2 pc_iss bit60 */
			{21778, 4,1}, /* core2 pc_iss bit61 */
			{21781, 4,1}, /* core2 pc_iss bit62 */
			{21780, 4,1}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{10299, 4,1}, /* core2 full_pc_wr bit0 */
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
			{13824, 4,1}, /* core2 full_pc_ex1 bit0 */
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
			{10249, 4,1}, /* core2 full_pc_ex2 bit0 */
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
			.spmc_power_state = {{
			{15782,19,0}, /* core3 spmc_power_state bit0 */
			{14986,17,1}, /* core3 spmc_power_state bit1 */
			{14985,17,1}, /* core3 spmc_power_state bit2 */
			{14984,17,1}, /* core3 spmc_power_state bit3 */
			{14983,17,1}, /* core3 spmc_power_state bit4 */
			{15781,19,0}, /* core3 spmc_power_state bit5 */
			{    0, 0,2}, /* core3 spmc_power_state bit6 */
			{    0, 0,2}, /* core3 spmc_power_state bit7 */
			{    0, 0,2}, /* core3 spmc_power_state bit8 */
			{    0, 0,2}, /* core3 spmc_power_state bit9 */
			{    0, 0,2}, /* core3 spmc_power_state bit10 */
			{    0, 0,2}, /* core3 spmc_power_state bit11 */
			{    0, 0,2}, /* core3 spmc_power_state bit12 */
			{    0, 0,2}, /* core3 spmc_power_state bit13 */
			{    0, 0,2}, /* core3 spmc_power_state bit14 */
			{    0, 0,2}, /* core3 spmc_power_state bit15 */
			{    0, 0,2}, /* core3 spmc_power_state bit16 */
			{    0, 0,2}, /* core3 spmc_power_state bit17 */
			{    0, 0,2}, /* core3 spmc_power_state bit18 */
			{    0, 0,2}, /* core3 spmc_power_state bit19 */
			{    0, 0,2}, /* core3 spmc_power_state bit20 */
			{    0, 0,2}, /* core3 spmc_power_state bit21 */
			{    0, 0,2}, /* core3 spmc_power_state bit22 */
			{    0, 0,2}, /* core3 spmc_power_state bit23 */
			{    0, 0,2}, /* core3 spmc_power_state bit24 */
			{    0, 0,2}, /* core3 spmc_power_state bit25 */
			{    0, 0,2}, /* core3 spmc_power_state bit26 */
			{    0, 0,2}, /* core3 spmc_power_state bit27 */
			{    0, 0,2}, /* core3 spmc_power_state bit28 */
			{    0, 0,2}, /* core3 spmc_power_state bit29 */
			{    0, 0,2}, /* core3 spmc_power_state bit30 */
			{    0, 0,2}, /* core3 spmc_power_state bit31 */
			{    0, 0,2}, /* core3 spmc_power_state bit32 */
			{    0, 0,2}, /* core3 spmc_power_state bit33 */
			{    0, 0,2}, /* core3 spmc_power_state bit34 */
			{    0, 0,2}, /* core3 spmc_power_state bit35 */
			{    0, 0,2}, /* core3 spmc_power_state bit36 */
			{    0, 0,2}, /* core3 spmc_power_state bit37 */
			{    0, 0,2}, /* core3 spmc_power_state bit38 */
			{    0, 0,2}, /* core3 spmc_power_state bit39 */
			{    0, 0,2}, /* core3 spmc_power_state bit40 */
			{    0, 0,2}, /* core3 spmc_power_state bit41 */
			{    0, 0,2}, /* core3 spmc_power_state bit42 */
			{    0, 0,2}, /* core3 spmc_power_state bit43 */
			{    0, 0,2}, /* core3 spmc_power_state bit44 */
			{    0, 0,2}, /* core3 spmc_power_state bit45 */
			{    0, 0,2}, /* core3 spmc_power_state bit46 */
			{    0, 0,2}, /* core3 spmc_power_state bit47 */
			{    0, 0,2}, /* core3 spmc_power_state bit48 */
			{    0, 0,2}, /* core3 spmc_power_state bit49 */
			{    0, 0,2}, /* core3 spmc_power_state bit50 */
			{    0, 0,2}, /* core3 spmc_power_state bit51 */
			{    0, 0,2}, /* core3 spmc_power_state bit52 */
			{    0, 0,2}, /* core3 spmc_power_state bit53 */
			{    0, 0,2}, /* core3 spmc_power_state bit54 */
			{    0, 0,2}, /* core3 spmc_power_state bit55 */
			{    0, 0,2}, /* core3 spmc_power_state bit56 */
			{    0, 0,2}, /* core3 spmc_power_state bit57 */
			{    0, 0,2}, /* core3 spmc_power_state bit58 */
			{    0, 0,2}, /* core3 spmc_power_state bit59 */
			{    0, 0,2}, /* core3 spmc_power_state bit60 */
			{    0, 0,2}, /* core3 spmc_power_state bit61 */
			{    0, 0,2}, /* core3 spmc_power_state bit62 */
			{    0, 0,2}, /* core3 spmc_power_state bit63 */
			}},
			.pc = {{
			{23998, 7,1}, /* core3 pc bit0 */
			{24031, 7,1}, /* core3 pc bit1 */
			{24033, 7,1}, /* core3 pc bit2 */
			{24014, 7,1}, /* core3 pc bit3 */
			{24032, 7,1}, /* core3 pc bit4 */
			{24025, 7,1}, /* core3 pc bit5 */
			{16287, 7,1}, /* core3 pc bit6 */
			{24024, 7,1}, /* core3 pc bit7 */
			{16286, 7,1}, /* core3 pc bit8 */
			{24030, 7,1}, /* core3 pc bit9 */
			{24051, 7,1}, /* core3 pc bit10 */
			{ 9105, 6,1}, /* core3 pc bit11 */
			{ 9104, 6,1}, /* core3 pc bit12 */
			{23975, 7,1}, /* core3 pc bit13 */
			{24045, 7,1}, /* core3 pc bit14 */
			{24044, 7,1}, /* core3 pc bit15 */
			{24050, 7,1}, /* core3 pc bit16 */
			{24053, 7,1}, /* core3 pc bit17 */
			{24052, 7,1}, /* core3 pc bit18 */
			{24003, 7,1}, /* core3 pc bit19 */
			{24002, 7,1}, /* core3 pc bit20 */
			{24147, 7,1}, /* core3 pc bit21 */
			{24037, 7,1}, /* core3 pc bit22 */
			{ 9103, 6,1}, /* core3 pc bit23 */
			{24036, 7,1}, /* core3 pc bit24 */
			{24133, 7,1}, /* core3 pc bit25 */
			{ 9102, 6,1}, /* core3 pc bit26 */
			{23168, 7,1}, /* core3 pc bit27 */
			{24146, 7,1}, /* core3 pc bit28 */
			{23167, 7,1}, /* core3 pc bit29 */
			{24043, 7,1}, /* core3 pc bit30 */
			{24042, 7,1}, /* core3 pc bit31 */
			{23959, 7,1}, /* core3 pc bit32 */
			{23958, 7,1}, /* core3 pc bit33 */
			{23993, 7,1}, /* core3 pc bit34 */
			{23992, 7,1}, /* core3 pc bit35 */
			{24149, 7,1}, /* core3 pc bit36 */
			{24132, 7,1}, /* core3 pc bit37 */
			{23961, 7,1}, /* core3 pc bit38 */
			{23960, 7,1}, /* core3 pc bit39 */
			{23957, 7,1}, /* core3 pc bit40 */
			{23956, 7,1}, /* core3 pc bit41 */
			{23967, 7,1}, /* core3 pc bit42 */
			{24148, 7,1}, /* core3 pc bit43 */
			{22945, 6,1}, /* core3 pc bit44 */
			{22944, 6,1}, /* core3 pc bit45 */
			{23987, 7,1}, /* core3 pc bit46 */
			{23966, 7,1}, /* core3 pc bit47 */
			{23991, 7,1}, /* core3 pc bit48 */
			{23989, 7,1}, /* core3 pc bit49 */
			{23990, 7,1}, /* core3 pc bit50 */
			{23965, 7,1}, /* core3 pc bit51 */
			{23964, 7,1}, /* core3 pc bit52 */
			{23988, 7,1}, /* core3 pc bit53 */
			{24107, 7,1}, /* core3 pc bit54 */
			{24106, 7,1}, /* core3 pc bit55 */
			{23068, 7,1}, /* core3 pc bit56 */
			{ 9101, 6,1}, /* core3 pc bit57 */
			{23150, 7,1}, /* core3 pc bit58 */
			{23986, 7,1}, /* core3 pc bit59 */
			{23963, 7,1}, /* core3 pc bit60 */
			{ 9100, 6,1}, /* core3 pc bit61 */
			{23962, 7,1}, /* core3 pc bit62 */
			{23151, 7,1}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{10987, 6,1}, /* core3 sp32 bit0 */
			{10986, 6,1}, /* core3 sp32 bit1 */
			{23581, 6,1}, /* core3 sp32 bit2 */
			{23580, 6,1}, /* core3 sp32 bit3 */
			{10989, 6,1}, /* core3 sp32 bit4 */
			{23571, 6,1}, /* core3 sp32 bit5 */
			{23577, 6,1}, /* core3 sp32 bit6 */
			{16267, 7,1}, /* core3 sp32 bit7 */
			{10988, 6,1}, /* core3 sp32 bit8 */
			{23576, 6,1}, /* core3 sp32 bit9 */
			{16251, 7,1}, /* core3 sp32 bit10 */
			{23570, 6,1}, /* core3 sp32 bit11 */
			{16250, 7,1}, /* core3 sp32 bit12 */
			{23575, 6,1}, /* core3 sp32 bit13 */
			{23574, 6,1}, /* core3 sp32 bit14 */
			{16269, 7,1}, /* core3 sp32 bit15 */
			{16268, 7,1}, /* core3 sp32 bit16 */
			{16265, 7,1}, /* core3 sp32 bit17 */
			{16264, 7,1}, /* core3 sp32 bit18 */
			{16247, 7,1}, /* core3 sp32 bit19 */
			{23579, 6,1}, /* core3 sp32 bit20 */
			{23578, 6,1}, /* core3 sp32 bit21 */
			{16266, 7,1}, /* core3 sp32 bit22 */
			{24021, 7,1}, /* core3 sp32 bit23 */
			{16246, 7,1}, /* core3 sp32 bit24 */
			{16249, 7,1}, /* core3 sp32 bit25 */
			{24020, 7,1}, /* core3 sp32 bit26 */
			{16271, 7,1}, /* core3 sp32 bit27 */
			{16248, 7,1}, /* core3 sp32 bit28 */
			{23573, 6,1}, /* core3 sp32 bit29 */
			{23572, 6,1}, /* core3 sp32 bit30 */
			{16270, 7,1}, /* core3 sp32 bit31 */
			{13203, 6,1}, /* core3 sp32 bit32 */
			{13202, 6,1}, /* core3 sp32 bit33 */
			{13205, 6,1}, /* core3 sp32 bit34 */
			{13204, 6,1}, /* core3 sp32 bit35 */
			{13243, 6,1}, /* core3 sp32 bit36 */
			{13242, 6,1}, /* core3 sp32 bit37 */
			{12299, 6,1}, /* core3 sp32 bit38 */
			{13201, 6,1}, /* core3 sp32 bit39 */
			{13200, 6,1}, /* core3 sp32 bit40 */
			{12297, 6,1}, /* core3 sp32 bit41 */
			{12296, 6,1}, /* core3 sp32 bit42 */
			{12298, 6,1}, /* core3 sp32 bit43 */
			{13241, 6,1}, /* core3 sp32 bit44 */
			{13240, 6,1}, /* core3 sp32 bit45 */
			{13777, 6,1}, /* core3 sp32 bit46 */
			{13187, 6,1}, /* core3 sp32 bit47 */
			{13185, 6,1}, /* core3 sp32 bit48 */
			{13186, 6,1}, /* core3 sp32 bit49 */
			{13184, 6,1}, /* core3 sp32 bit50 */
			{12289, 6,1}, /* core3 sp32 bit51 */
			{12288, 6,1}, /* core3 sp32 bit52 */
			{13207, 6,1}, /* core3 sp32 bit53 */
			{13239, 6,1}, /* core3 sp32 bit54 */
			{13238, 6,1}, /* core3 sp32 bit55 */
			{13211, 6,1}, /* core3 sp32 bit56 */
			{13206, 6,1}, /* core3 sp32 bit57 */
			{12291, 6,1}, /* core3 sp32 bit58 */
			{12290, 6,1}, /* core3 sp32 bit59 */
			{13209, 6,1}, /* core3 sp32 bit60 */
			{13208, 6,1}, /* core3 sp32 bit61 */
			{13750, 6,1}, /* core3 sp32 bit62 */
			{13210, 6,1}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{16193, 7,1}, /* core3 fp32 bit0 */
			{16192, 7,1}, /* core3 fp32 bit1 */
			{16197, 7,1}, /* core3 fp32 bit2 */
			{16196, 7,1}, /* core3 fp32 bit3 */
			{16207, 7,1}, /* core3 fp32 bit4 */
			{16203, 7,1}, /* core3 fp32 bit5 */
			{16205, 7,1}, /* core3 fp32 bit6 */
			{16204, 7,1}, /* core3 fp32 bit7 */
			{16161, 7,1}, /* core3 fp32 bit8 */
			{16160, 7,1}, /* core3 fp32 bit9 */
			{16209, 7,1}, /* core3 fp32 bit10 */
			{16202, 7,1}, /* core3 fp32 bit11 */
			{16208, 7,1}, /* core3 fp32 bit12 */
			{11941, 6,1}, /* core3 fp32 bit13 */
			{11935, 6,1}, /* core3 fp32 bit14 */
			{16159, 7,1}, /* core3 fp32 bit15 */
			{11940, 6,1}, /* core3 fp32 bit16 */
			{16206, 7,1}, /* core3 fp32 bit17 */
			{16199, 7,1}, /* core3 fp32 bit18 */
			{16198, 7,1}, /* core3 fp32 bit19 */
			{11934, 6,1}, /* core3 fp32 bit20 */
			{16201, 7,1}, /* core3 fp32 bit21 */
			{16200, 7,1}, /* core3 fp32 bit22 */
			{11925, 6,1}, /* core3 fp32 bit23 */
			{11924, 6,1}, /* core3 fp32 bit24 */
			{11937, 6,1}, /* core3 fp32 bit25 */
			{16195, 7,1}, /* core3 fp32 bit26 */
			{13733, 6,1}, /* core3 fp32 bit27 */
			{11936, 6,1}, /* core3 fp32 bit28 */
			{16194, 7,1}, /* core3 fp32 bit29 */
			{11939, 6,1}, /* core3 fp32 bit30 */
			{11938, 6,1}, /* core3 fp32 bit31 */
			{14669, 6,1}, /* core3 fp32 bit32 */
			{14668, 6,1}, /* core3 fp32 bit33 */
			{14671, 6,1}, /* core3 fp32 bit34 */
			{14670, 6,1}, /* core3 fp32 bit35 */
			{14645, 6,1}, /* core3 fp32 bit36 */
			{14644, 6,1}, /* core3 fp32 bit37 */
			{14647, 6,1}, /* core3 fp32 bit38 */
			{14646, 6,1}, /* core3 fp32 bit39 */
			{13771, 6,1}, /* core3 fp32 bit40 */
			{14651, 6,1}, /* core3 fp32 bit41 */
			{14650, 6,1}, /* core3 fp32 bit42 */
			{14653, 6,1}, /* core3 fp32 bit43 */
			{14652, 6,1}, /* core3 fp32 bit44 */
			{14657, 6,1}, /* core3 fp32 bit45 */
			{14656, 6,1}, /* core3 fp32 bit46 */
			{14641, 6,1}, /* core3 fp32 bit47 */
			{14640, 6,1}, /* core3 fp32 bit48 */
			{14649, 6,1}, /* core3 fp32 bit49 */
			{14648, 6,1}, /* core3 fp32 bit50 */
			{14643, 6,1}, /* core3 fp32 bit51 */
			{14642, 6,1}, /* core3 fp32 bit52 */
			{14661, 6,1}, /* core3 fp32 bit53 */
			{14665, 6,1}, /* core3 fp32 bit54 */
			{14660, 6,1}, /* core3 fp32 bit55 */
			{14664, 6,1}, /* core3 fp32 bit56 */
			{14667, 6,1}, /* core3 fp32 bit57 */
			{14663, 6,1}, /* core3 fp32 bit58 */
			{14662, 6,1}, /* core3 fp32 bit59 */
			{14666, 6,1}, /* core3 fp32 bit60 */
			{14659, 6,1}, /* core3 fp32 bit61 */
			{14658, 6,1}, /* core3 fp32 bit62 */
			{13769, 6,1}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{10273, 6,1}, /* core3 fp64 bit0 */
			{10272, 6,1}, /* core3 fp64 bit1 */
			{10271, 6,1}, /* core3 fp64 bit2 */
			{10270, 6,1}, /* core3 fp64 bit3 */
			{16293, 7,1}, /* core3 fp64 bit4 */
			{16292, 7,1}, /* core3 fp64 bit5 */
			{16275, 7,1}, /* core3 fp64 bit6 */
			{16274, 7,1}, /* core3 fp64 bit7 */
			{16297, 7,1}, /* core3 fp64 bit8 */
			{16296, 7,1}, /* core3 fp64 bit9 */
			{16273, 7,1}, /* core3 fp64 bit10 */
			{16279, 7,1}, /* core3 fp64 bit11 */
			{16272, 7,1}, /* core3 fp64 bit12 */
			{16291, 7,1}, /* core3 fp64 bit13 */
			{16257, 7,1}, /* core3 fp64 bit14 */
			{16290, 7,1}, /* core3 fp64 bit15 */
			{24023, 7,1}, /* core3 fp64 bit16 */
			{16278, 7,1}, /* core3 fp64 bit17 */
			{16281, 7,1}, /* core3 fp64 bit18 */
			{16280, 7,1}, /* core3 fp64 bit19 */
			{16256, 7,1}, /* core3 fp64 bit20 */
			{16259, 7,1}, /* core3 fp64 bit21 */
			{16317, 7,1}, /* core3 fp64 bit22 */
			{16316, 7,1}, /* core3 fp64 bit23 */
			{16295, 7,1}, /* core3 fp64 bit24 */
			{16258, 7,1}, /* core3 fp64 bit25 */
			{16277, 7,1}, /* core3 fp64 bit26 */
			{24022, 7,1}, /* core3 fp64 bit27 */
			{16294, 7,1}, /* core3 fp64 bit28 */
			{16276, 7,1}, /* core3 fp64 bit29 */
			{16283, 7,1}, /* core3 fp64 bit30 */
			{16282, 7,1}, /* core3 fp64 bit31 */
			{ 9757, 6,1}, /* core3 fp64 bit32 */
			{ 9756, 6,1}, /* core3 fp64 bit33 */
			{ 9751, 6,1}, /* core3 fp64 bit34 */
			{ 9750, 6,1}, /* core3 fp64 bit35 */
			{ 9729, 6,1}, /* core3 fp64 bit36 */
			{ 9755, 6,1}, /* core3 fp64 bit37 */
			{ 9754, 6,1}, /* core3 fp64 bit38 */
			{ 9731, 6,1}, /* core3 fp64 bit39 */
			{ 9728, 6,1}, /* core3 fp64 bit40 */
			{ 9730, 6,1}, /* core3 fp64 bit41 */
			{ 9721, 6,1}, /* core3 fp64 bit42 */
			{13801, 6,1}, /* core3 fp64 bit43 */
			{ 9720, 6,1}, /* core3 fp64 bit44 */
			{ 9733, 6,1}, /* core3 fp64 bit45 */
			{ 9732, 6,1}, /* core3 fp64 bit46 */
			{ 9725, 6,1}, /* core3 fp64 bit47 */
			{ 9727, 6,1}, /* core3 fp64 bit48 */
			{ 9726, 6,1}, /* core3 fp64 bit49 */
			{ 9724, 6,1}, /* core3 fp64 bit50 */
			{ 9763, 6,1}, /* core3 fp64 bit51 */
			{ 9753, 6,1}, /* core3 fp64 bit52 */
			{ 9752, 6,1}, /* core3 fp64 bit53 */
			{ 9759, 6,1}, /* core3 fp64 bit54 */
			{ 9758, 6,1}, /* core3 fp64 bit55 */
			{ 9762, 6,1}, /* core3 fp64 bit56 */
			{ 9719, 6,1}, /* core3 fp64 bit57 */
			{13800, 6,1}, /* core3 fp64 bit58 */
			{ 9718, 6,1}, /* core3 fp64 bit59 */
			{ 9761, 6,1}, /* core3 fp64 bit60 */
			{ 9760, 6,1}, /* core3 fp64 bit61 */
			{ 9723, 6,1}, /* core3 fp64 bit62 */
			{ 9722, 6,1}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{12529, 6,1}, /* core3 sp_EL0 bit0 */
			{10485, 6,1}, /* core3 sp_EL0 bit1 */
			{10484, 6,1}, /* core3 sp_EL0 bit2 */
			{12527, 6,1}, /* core3 sp_EL0 bit3 */
			{10489, 6,1}, /* core3 sp_EL0 bit4 */
			{10488, 6,1}, /* core3 sp_EL0 bit5 */
			{12526, 6,1}, /* core3 sp_EL0 bit6 */
			{12528, 6,1}, /* core3 sp_EL0 bit7 */
			{12531, 6,1}, /* core3 sp_EL0 bit8 */
			{12530, 6,1}, /* core3 sp_EL0 bit9 */
			{12439, 6,1}, /* core3 sp_EL0 bit10 */
			{12523, 6,1}, /* core3 sp_EL0 bit11 */
			{10487, 6,1}, /* core3 sp_EL0 bit12 */
			{12438, 6,1}, /* core3 sp_EL0 bit13 */
			{12429, 6,1}, /* core3 sp_EL0 bit14 */
			{10486, 6,1}, /* core3 sp_EL0 bit15 */
			{13720, 6,1}, /* core3 sp_EL0 bit16 */
			{12428, 6,1}, /* core3 sp_EL0 bit17 */
			{12437, 6,1}, /* core3 sp_EL0 bit18 */
			{12436, 6,1}, /* core3 sp_EL0 bit19 */
			{12522, 6,1}, /* core3 sp_EL0 bit20 */
			{12525, 6,1}, /* core3 sp_EL0 bit21 */
			{12431, 6,1}, /* core3 sp_EL0 bit22 */
			{12430, 6,1}, /* core3 sp_EL0 bit23 */
			{12521, 6,1}, /* core3 sp_EL0 bit24 */
			{12524, 6,1}, /* core3 sp_EL0 bit25 */
			{12427, 6,1}, /* core3 sp_EL0 bit26 */
			{13721, 6,1}, /* core3 sp_EL0 bit27 */
			{12520, 6,1}, /* core3 sp_EL0 bit28 */
			{12426, 6,1}, /* core3 sp_EL0 bit29 */
			{12441, 6,1}, /* core3 sp_EL0 bit30 */
			{12440, 6,1}, /* core3 sp_EL0 bit31 */
			{12829, 6,1}, /* core3 sp_EL0 bit32 */
			{12828, 6,1}, /* core3 sp_EL0 bit33 */
			{12823, 6,1}, /* core3 sp_EL0 bit34 */
			{11205, 6,1}, /* core3 sp_EL0 bit35 */
			{12822, 6,1}, /* core3 sp_EL0 bit36 */
			{11213, 6,1}, /* core3 sp_EL0 bit37 */
			{11212, 6,1}, /* core3 sp_EL0 bit38 */
			{11211, 6,1}, /* core3 sp_EL0 bit39 */
			{11210, 6,1}, /* core3 sp_EL0 bit40 */
			{11204, 6,1}, /* core3 sp_EL0 bit41 */
			{11201, 6,1}, /* core3 sp_EL0 bit42 */
			{11200, 6,1}, /* core3 sp_EL0 bit43 */
			{12827, 6,1}, /* core3 sp_EL0 bit44 */
			{12826, 6,1}, /* core3 sp_EL0 bit45 */
			{14527, 6,1}, /* core3 sp_EL0 bit46 */
			{11217, 6,1}, /* core3 sp_EL0 bit47 */
			{11216, 6,1}, /* core3 sp_EL0 bit48 */
			{11207, 6,1}, /* core3 sp_EL0 bit49 */
			{12821, 6,1}, /* core3 sp_EL0 bit50 */
			{11206, 6,1}, /* core3 sp_EL0 bit51 */
			{12820, 6,1}, /* core3 sp_EL0 bit52 */
			{11219, 6,1}, /* core3 sp_EL0 bit53 */
			{11218, 6,1}, /* core3 sp_EL0 bit54 */
			{14231, 6,1}, /* core3 sp_EL0 bit55 */
			{12825, 6,1}, /* core3 sp_EL0 bit56 */
			{12824, 6,1}, /* core3 sp_EL0 bit57 */
			{11215, 6,1}, /* core3 sp_EL0 bit58 */
			{11214, 6,1}, /* core3 sp_EL0 bit59 */
			{11203, 6,1}, /* core3 sp_EL0 bit60 */
			{11202, 6,1}, /* core3 sp_EL0 bit61 */
			{14526, 6,1}, /* core3 sp_EL0 bit62 */
			{14528, 6,1}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{10269, 6,1}, /* core3 sp_EL1 bit0 */
			{10268, 6,1}, /* core3 sp_EL1 bit1 */
			{10267, 6,1}, /* core3 sp_EL1 bit2 */
			{10266, 6,1}, /* core3 sp_EL1 bit3 */
			{16243, 7,1}, /* core3 sp_EL1 bit4 */
			{16242, 7,1}, /* core3 sp_EL1 bit5 */
			{10991, 6,1}, /* core3 sp_EL1 bit6 */
			{10990, 6,1}, /* core3 sp_EL1 bit7 */
			{16255, 7,1}, /* core3 sp_EL1 bit8 */
			{16254, 7,1}, /* core3 sp_EL1 bit9 */
			{16263, 7,1}, /* core3 sp_EL1 bit10 */
			{16237, 7,1}, /* core3 sp_EL1 bit11 */
			{16262, 7,1}, /* core3 sp_EL1 bit12 */
			{16245, 7,1}, /* core3 sp_EL1 bit13 */
			{16236, 7,1}, /* core3 sp_EL1 bit14 */
			{16253, 7,1}, /* core3 sp_EL1 bit15 */
			{16252, 7,1}, /* core3 sp_EL1 bit16 */
			{16233, 7,1}, /* core3 sp_EL1 bit17 */
			{16232, 7,1}, /* core3 sp_EL1 bit18 */
			{16235, 7,1}, /* core3 sp_EL1 bit19 */
			{10985, 6,1}, /* core3 sp_EL1 bit20 */
			{16234, 7,1}, /* core3 sp_EL1 bit21 */
			{16244, 7,1}, /* core3 sp_EL1 bit22 */
			{16239, 7,1}, /* core3 sp_EL1 bit23 */
			{23070, 7,1}, /* core3 sp_EL1 bit24 */
			{10984, 6,1}, /* core3 sp_EL1 bit25 */
			{16261, 7,1}, /* core3 sp_EL1 bit26 */
			{16260, 7,1}, /* core3 sp_EL1 bit27 */
			{16238, 7,1}, /* core3 sp_EL1 bit28 */
			{23069, 7,1}, /* core3 sp_EL1 bit29 */
			{16241, 7,1}, /* core3 sp_EL1 bit30 */
			{16240, 7,1}, /* core3 sp_EL1 bit31 */
			{24089, 6,1}, /* core3 sp_EL1 bit32 */
			{24088, 6,1}, /* core3 sp_EL1 bit33 */
			{12803, 6,1}, /* core3 sp_EL1 bit34 */
			{11221, 6,1}, /* core3 sp_EL1 bit35 */
			{11220, 6,1}, /* core3 sp_EL1 bit36 */
			{12799, 6,1}, /* core3 sp_EL1 bit37 */
			{12798, 6,1}, /* core3 sp_EL1 bit38 */
			{24091, 6,1}, /* core3 sp_EL1 bit39 */
			{24090, 6,1}, /* core3 sp_EL1 bit40 */
			{12802, 6,1}, /* core3 sp_EL1 bit41 */
			{12807, 6,1}, /* core3 sp_EL1 bit42 */
			{12801, 6,1}, /* core3 sp_EL1 bit43 */
			{12800, 6,1}, /* core3 sp_EL1 bit44 */
			{14517, 6,1}, /* core3 sp_EL1 bit45 */
			{12806, 6,1}, /* core3 sp_EL1 bit46 */
			{12809, 6,1}, /* core3 sp_EL1 bit47 */
			{12808, 6,1}, /* core3 sp_EL1 bit48 */
			{12797, 6,1}, /* core3 sp_EL1 bit49 */
			{24085, 6,1}, /* core3 sp_EL1 bit50 */
			{24084, 6,1}, /* core3 sp_EL1 bit51 */
			{12805, 6,1}, /* core3 sp_EL1 bit52 */
			{12796, 6,1}, /* core3 sp_EL1 bit53 */
			{12804, 6,1}, /* core3 sp_EL1 bit54 */
			{24081, 6,1}, /* core3 sp_EL1 bit55 */
			{24080, 6,1}, /* core3 sp_EL1 bit56 */
			{24087, 6,1}, /* core3 sp_EL1 bit57 */
			{14515, 6,1}, /* core3 sp_EL1 bit58 */
			{24086, 6,1}, /* core3 sp_EL1 bit59 */
			{24083, 6,1}, /* core3 sp_EL1 bit60 */
			{24082, 6,1}, /* core3 sp_EL1 bit61 */
			{14516, 6,1}, /* core3 sp_EL1 bit62 */
			{14514, 6,1}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{10265, 6,1}, /* core3 sp_EL2 bit0 */
			{10264, 6,1}, /* core3 sp_EL2 bit1 */
			{10263, 6,1}, /* core3 sp_EL2 bit2 */
			{10262, 6,1}, /* core3 sp_EL2 bit3 */
			{12503, 6,1}, /* core3 sp_EL2 bit4 */
			{12502, 6,1}, /* core3 sp_EL2 bit5 */
			{12549, 6,1}, /* core3 sp_EL2 bit6 */
			{12548, 6,1}, /* core3 sp_EL2 bit7 */
			{12507, 6,1}, /* core3 sp_EL2 bit8 */
			{12506, 6,1}, /* core3 sp_EL2 bit9 */
			{12509, 6,1}, /* core3 sp_EL2 bit10 */
			{12559, 6,1}, /* core3 sp_EL2 bit11 */
			{12508, 6,1}, /* core3 sp_EL2 bit12 */
			{12505, 6,1}, /* core3 sp_EL2 bit13 */
			{12551, 6,1}, /* core3 sp_EL2 bit14 */
			{12547, 6,1}, /* core3 sp_EL2 bit15 */
			{12546, 6,1}, /* core3 sp_EL2 bit16 */
			{12558, 6,1}, /* core3 sp_EL2 bit17 */
			{12557, 6,1}, /* core3 sp_EL2 bit18 */
			{12556, 6,1}, /* core3 sp_EL2 bit19 */
			{12550, 6,1}, /* core3 sp_EL2 bit20 */
			{12553, 6,1}, /* core3 sp_EL2 bit21 */
			{12501, 6,1}, /* core3 sp_EL2 bit22 */
			{14539, 6,1}, /* core3 sp_EL2 bit23 */
			{12500, 6,1}, /* core3 sp_EL2 bit24 */
			{12555, 6,1}, /* core3 sp_EL2 bit25 */
			{12504, 6,1}, /* core3 sp_EL2 bit26 */
			{12552, 6,1}, /* core3 sp_EL2 bit27 */
			{12554, 6,1}, /* core3 sp_EL2 bit28 */
			{13717, 6,1}, /* core3 sp_EL2 bit29 */
			{12499, 6,1}, /* core3 sp_EL2 bit30 */
			{12498, 6,1}, /* core3 sp_EL2 bit31 */
			{12765, 6,1}, /* core3 sp_EL2 bit32 */
			{12764, 6,1}, /* core3 sp_EL2 bit33 */
			{12853, 6,1}, /* core3 sp_EL2 bit34 */
			{12761, 6,1}, /* core3 sp_EL2 bit35 */
			{12760, 6,1}, /* core3 sp_EL2 bit36 */
			{12852, 6,1}, /* core3 sp_EL2 bit37 */
			{12851, 6,1}, /* core3 sp_EL2 bit38 */
			{12850, 6,1}, /* core3 sp_EL2 bit39 */
			{14520, 6,1}, /* core3 sp_EL2 bit40 */
			{12855, 6,1}, /* core3 sp_EL2 bit41 */
			{12854, 6,1}, /* core3 sp_EL2 bit42 */
			{12863, 6,1}, /* core3 sp_EL2 bit43 */
			{12862, 6,1}, /* core3 sp_EL2 bit44 */
			{12763, 6,1}, /* core3 sp_EL2 bit45 */
			{12762, 6,1}, /* core3 sp_EL2 bit46 */
			{12857, 6,1}, /* core3 sp_EL2 bit47 */
			{12859, 6,1}, /* core3 sp_EL2 bit48 */
			{12858, 6,1}, /* core3 sp_EL2 bit49 */
			{12856, 6,1}, /* core3 sp_EL2 bit50 */
			{12865, 6,1}, /* core3 sp_EL2 bit51 */
			{12867, 6,1}, /* core3 sp_EL2 bit52 */
			{12866, 6,1}, /* core3 sp_EL2 bit53 */
			{12864, 6,1}, /* core3 sp_EL2 bit54 */
			{12861, 6,1}, /* core3 sp_EL2 bit55 */
			{12860, 6,1}, /* core3 sp_EL2 bit56 */
			{12871, 6,1}, /* core3 sp_EL2 bit57 */
			{12870, 6,1}, /* core3 sp_EL2 bit58 */
			{12759, 6,1}, /* core3 sp_EL2 bit59 */
			{12758, 6,1}, /* core3 sp_EL2 bit60 */
			{12869, 6,1}, /* core3 sp_EL2 bit61 */
			{12868, 6,1}, /* core3 sp_EL2 bit62 */
			{14445, 6,1}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{12453, 6,1}, /* core3 sp_EL3 bit0 */
			{12452, 6,1}, /* core3 sp_EL3 bit1 */
			{12513, 6,1}, /* core3 sp_EL3 bit2 */
			{12447, 6,1}, /* core3 sp_EL3 bit3 */
			{12515, 6,1}, /* core3 sp_EL3 bit4 */
			{12514, 6,1}, /* core3 sp_EL3 bit5 */
			{12446, 6,1}, /* core3 sp_EL3 bit6 */
			{12443, 6,1}, /* core3 sp_EL3 bit7 */
			{12512, 6,1}, /* core3 sp_EL3 bit8 */
			{12511, 6,1}, /* core3 sp_EL3 bit9 */
			{12442, 6,1}, /* core3 sp_EL3 bit10 */
			{12423, 6,1}, /* core3 sp_EL3 bit11 */
			{12445, 6,1}, /* core3 sp_EL3 bit12 */
			{12510, 6,1}, /* core3 sp_EL3 bit13 */
			{12449, 6,1}, /* core3 sp_EL3 bit14 */
			{12444, 6,1}, /* core3 sp_EL3 bit15 */
			{14538, 6,1}, /* core3 sp_EL3 bit16 */
			{12422, 6,1}, /* core3 sp_EL3 bit17 */
			{12451, 6,1}, /* core3 sp_EL3 bit18 */
			{12450, 6,1}, /* core3 sp_EL3 bit19 */
			{12448, 6,1}, /* core3 sp_EL3 bit20 */
			{12457, 6,1}, /* core3 sp_EL3 bit21 */
			{12459, 6,1}, /* core3 sp_EL3 bit22 */
			{12456, 6,1}, /* core3 sp_EL3 bit23 */
			{12458, 6,1}, /* core3 sp_EL3 bit24 */
			{12455, 6,1}, /* core3 sp_EL3 bit25 */
			{12425, 6,1}, /* core3 sp_EL3 bit26 */
			{12424, 6,1}, /* core3 sp_EL3 bit27 */
			{12461, 6,1}, /* core3 sp_EL3 bit28 */
			{12454, 6,1}, /* core3 sp_EL3 bit29 */
			{12460, 6,1}, /* core3 sp_EL3 bit30 */
			{13716, 6,1}, /* core3 sp_EL3 bit31 */
			{12115, 6,1}, /* core3 sp_EL3 bit32 */
			{12114, 6,1}, /* core3 sp_EL3 bit33 */
			{14149, 6,1}, /* core3 sp_EL3 bit34 */
			{23991, 6,1}, /* core3 sp_EL3 bit35 */
			{14148, 6,1}, /* core3 sp_EL3 bit36 */
			{14147, 6,1}, /* core3 sp_EL3 bit37 */
			{14146, 6,1}, /* core3 sp_EL3 bit38 */
			{24247, 6,1}, /* core3 sp_EL3 bit39 */
			{24246, 6,1}, /* core3 sp_EL3 bit40 */
			{23990, 6,1}, /* core3 sp_EL3 bit41 */
			{23993, 6,1}, /* core3 sp_EL3 bit42 */
			{23992, 6,1}, /* core3 sp_EL3 bit43 */
			{12113, 6,1}, /* core3 sp_EL3 bit44 */
			{12112, 6,1}, /* core3 sp_EL3 bit45 */
			{14510, 6,1}, /* core3 sp_EL3 bit46 */
			{14143, 6,1}, /* core3 sp_EL3 bit47 */
			{14142, 6,1}, /* core3 sp_EL3 bit48 */
			{14061, 6,1}, /* core3 sp_EL3 bit49 */
			{14060, 6,1}, /* core3 sp_EL3 bit50 */
			{24245, 6,1}, /* core3 sp_EL3 bit51 */
			{24244, 6,1}, /* core3 sp_EL3 bit52 */
			{14509, 6,1}, /* core3 sp_EL3 bit53 */
			{14145, 6,1}, /* core3 sp_EL3 bit54 */
			{14144, 6,1}, /* core3 sp_EL3 bit55 */
			{12111, 6,1}, /* core3 sp_EL3 bit56 */
			{12110, 6,1}, /* core3 sp_EL3 bit57 */
			{14063, 6,1}, /* core3 sp_EL3 bit58 */
			{14062, 6,1}, /* core3 sp_EL3 bit59 */
			{24249, 6,1}, /* core3 sp_EL3 bit60 */
			{24248, 6,1}, /* core3 sp_EL3 bit61 */
			{14501, 6,1}, /* core3 sp_EL3 bit62 */
			{14508, 6,1}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{10491, 6,1}, /* core3 elr_EL1 bit0 */
			{10490, 6,1}, /* core3 elr_EL1 bit1 */
			{10493, 6,1}, /* core3 elr_EL1 bit2 */
			{13718, 6,1}, /* core3 elr_EL1 bit3 */
			{12545, 6,1}, /* core3 elr_EL1 bit4 */
			{12519, 6,1}, /* core3 elr_EL1 bit5 */
			{12539, 6,1}, /* core3 elr_EL1 bit6 */
			{12538, 6,1}, /* core3 elr_EL1 bit7 */
			{10492, 6,1}, /* core3 elr_EL1 bit8 */
			{12535, 6,1}, /* core3 elr_EL1 bit9 */
			{10499, 6,1}, /* core3 elr_EL1 bit10 */
			{12544, 6,1}, /* core3 elr_EL1 bit11 */
			{12534, 6,1}, /* core3 elr_EL1 bit12 */
			{12537, 6,1}, /* core3 elr_EL1 bit13 */
			{12518, 6,1}, /* core3 elr_EL1 bit14 */
			{12536, 6,1}, /* core3 elr_EL1 bit15 */
			{13719, 6,1}, /* core3 elr_EL1 bit16 */
			{10497, 6,1}, /* core3 elr_EL1 bit17 */
			{10496, 6,1}, /* core3 elr_EL1 bit18 */
			{10495, 6,1}, /* core3 elr_EL1 bit19 */
			{12541, 6,1}, /* core3 elr_EL1 bit20 */
			{10494, 6,1}, /* core3 elr_EL1 bit21 */
			{12517, 6,1}, /* core3 elr_EL1 bit22 */
			{12516, 6,1}, /* core3 elr_EL1 bit23 */
			{13715, 6,1}, /* core3 elr_EL1 bit24 */
			{12540, 6,1}, /* core3 elr_EL1 bit25 */
			{10498, 6,1}, /* core3 elr_EL1 bit26 */
			{12533, 6,1}, /* core3 elr_EL1 bit27 */
			{12543, 6,1}, /* core3 elr_EL1 bit28 */
			{12532, 6,1}, /* core3 elr_EL1 bit29 */
			{12542, 6,1}, /* core3 elr_EL1 bit30 */
			{13714, 6,1}, /* core3 elr_EL1 bit31 */
			{14131, 6,1}, /* core3 elr_EL1 bit32 */
			{14073, 6,1}, /* core3 elr_EL1 bit33 */
			{14072, 6,1}, /* core3 elr_EL1 bit34 */
			{14130, 6,1}, /* core3 elr_EL1 bit35 */
			{14123, 6,1}, /* core3 elr_EL1 bit36 */
			{14122, 6,1}, /* core3 elr_EL1 bit37 */
			{14125, 6,1}, /* core3 elr_EL1 bit38 */
			{14071, 6,1}, /* core3 elr_EL1 bit39 */
			{14070, 6,1}, /* core3 elr_EL1 bit40 */
			{14124, 6,1}, /* core3 elr_EL1 bit41 */
			{14133, 6,1}, /* core3 elr_EL1 bit42 */
			{14132, 6,1}, /* core3 elr_EL1 bit43 */
			{14127, 6,1}, /* core3 elr_EL1 bit44 */
			{14126, 6,1}, /* core3 elr_EL1 bit45 */
			{13802, 6,1}, /* core3 elr_EL1 bit46 */
			{14135, 6,1}, /* core3 elr_EL1 bit47 */
			{14134, 6,1}, /* core3 elr_EL1 bit48 */
			{14069, 6,1}, /* core3 elr_EL1 bit49 */
			{14068, 6,1}, /* core3 elr_EL1 bit50 */
			{14129, 6,1}, /* core3 elr_EL1 bit51 */
			{14067, 6,1}, /* core3 elr_EL1 bit52 */
			{14066, 6,1}, /* core3 elr_EL1 bit53 */
			{14141, 6,1}, /* core3 elr_EL1 bit54 */
			{14128, 6,1}, /* core3 elr_EL1 bit55 */
			{14140, 6,1}, /* core3 elr_EL1 bit56 */
			{14065, 6,1}, /* core3 elr_EL1 bit57 */
			{14064, 6,1}, /* core3 elr_EL1 bit58 */
			{14139, 6,1}, /* core3 elr_EL1 bit59 */
			{14138, 6,1}, /* core3 elr_EL1 bit60 */
			{14137, 6,1}, /* core3 elr_EL1 bit61 */
			{14136, 6,1}, /* core3 elr_EL1 bit62 */
			{14499, 6,1}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{24107, 6,1}, /* core3 elr_EL2 bit0 */
			{24106, 6,1}, /* core3 elr_EL2 bit1 */
			{11155, 6,1}, /* core3 elr_EL2 bit2 */
			{11154, 6,1}, /* core3 elr_EL2 bit3 */
			{24113, 6,1}, /* core3 elr_EL2 bit4 */
			{24112, 6,1}, /* core3 elr_EL2 bit5 */
			{11165, 6,1}, /* core3 elr_EL2 bit6 */
			{11164, 6,1}, /* core3 elr_EL2 bit7 */
			{24109, 6,1}, /* core3 elr_EL2 bit8 */
			{24108, 6,1}, /* core3 elr_EL2 bit9 */
			{24117, 6,1}, /* core3 elr_EL2 bit10 */
			{24105, 6,1}, /* core3 elr_EL2 bit11 */
			{24116, 6,1}, /* core3 elr_EL2 bit12 */
			{11161, 6,1}, /* core3 elr_EL2 bit13 */
			{24115, 6,1}, /* core3 elr_EL2 bit14 */
			{11160, 6,1}, /* core3 elr_EL2 bit15 */
			{11157, 6,1}, /* core3 elr_EL2 bit16 */
			{24104, 6,1}, /* core3 elr_EL2 bit17 */
			{11169, 6,1}, /* core3 elr_EL2 bit18 */
			{24114, 6,1}, /* core3 elr_EL2 bit19 */
			{11159, 6,1}, /* core3 elr_EL2 bit20 */
			{11158, 6,1}, /* core3 elr_EL2 bit21 */
			{11163, 6,1}, /* core3 elr_EL2 bit22 */
			{11168, 6,1}, /* core3 elr_EL2 bit23 */
			{11162, 6,1}, /* core3 elr_EL2 bit24 */
			{24111, 6,1}, /* core3 elr_EL2 bit25 */
			{11156, 6,1}, /* core3 elr_EL2 bit26 */
			{13693, 6,1}, /* core3 elr_EL2 bit27 */
			{11167, 6,1}, /* core3 elr_EL2 bit28 */
			{11166, 6,1}, /* core3 elr_EL2 bit29 */
			{14449, 6,1}, /* core3 elr_EL2 bit30 */
			{24110, 6,1}, /* core3 elr_EL2 bit31 */
			{24243, 6,1}, /* core3 elr_EL2 bit32 */
			{24075, 6,1}, /* core3 elr_EL2 bit33 */
			{24074, 6,1}, /* core3 elr_EL2 bit34 */
			{24242, 6,1}, /* core3 elr_EL2 bit35 */
			{23987, 6,1}, /* core3 elr_EL2 bit36 */
			{24071, 6,1}, /* core3 elr_EL2 bit37 */
			{24070, 6,1}, /* core3 elr_EL2 bit38 */
			{23983, 6,1}, /* core3 elr_EL2 bit39 */
			{23982, 6,1}, /* core3 elr_EL2 bit40 */
			{23986, 6,1}, /* core3 elr_EL2 bit41 */
			{24079, 6,1}, /* core3 elr_EL2 bit42 */
			{24078, 6,1}, /* core3 elr_EL2 bit43 */
			{24073, 6,1}, /* core3 elr_EL2 bit44 */
			{24072, 6,1}, /* core3 elr_EL2 bit45 */
			{14511, 6,1}, /* core3 elr_EL2 bit46 */
			{24241, 6,1}, /* core3 elr_EL2 bit47 */
			{24240, 6,1}, /* core3 elr_EL2 bit48 */
			{24065, 6,1}, /* core3 elr_EL2 bit49 */
			{24064, 6,1}, /* core3 elr_EL2 bit50 */
			{24063, 6,1}, /* core3 elr_EL2 bit51 */
			{23989, 6,1}, /* core3 elr_EL2 bit52 */
			{24069, 6,1}, /* core3 elr_EL2 bit53 */
			{23988, 6,1}, /* core3 elr_EL2 bit54 */
			{23985, 6,1}, /* core3 elr_EL2 bit55 */
			{24062, 6,1}, /* core3 elr_EL2 bit56 */
			{23984, 6,1}, /* core3 elr_EL2 bit57 */
			{24067, 6,1}, /* core3 elr_EL2 bit58 */
			{24066, 6,1}, /* core3 elr_EL2 bit59 */
			{24077, 6,1}, /* core3 elr_EL2 bit60 */
			{24076, 6,1}, /* core3 elr_EL2 bit61 */
			{14512, 6,1}, /* core3 elr_EL2 bit62 */
			{24068, 6,1}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{11309, 6,1}, /* core3 elr_EL3 bit0 */
			{12421, 6,1}, /* core3 elr_EL3 bit1 */
			{12420, 6,1}, /* core3 elr_EL3 bit2 */
			{14537, 6,1}, /* core3 elr_EL3 bit3 */
			{12419, 6,1}, /* core3 elr_EL3 bit4 */
			{12418, 6,1}, /* core3 elr_EL3 bit5 */
			{11308, 6,1}, /* core3 elr_EL3 bit6 */
			{12465, 6,1}, /* core3 elr_EL3 bit7 */
			{12464, 6,1}, /* core3 elr_EL3 bit8 */
			{24351, 6,0}, /* core3 elr_EL3 bit9 */
			{11307, 6,1}, /* core3 elr_EL3 bit10 */
			{11317, 6,1}, /* core3 elr_EL3 bit11 */
			{11306, 6,1}, /* core3 elr_EL3 bit12 */
			{24350, 6,0}, /* core3 elr_EL3 bit13 */
			{11316, 6,1}, /* core3 elr_EL3 bit14 */
			{12417, 6,1}, /* core3 elr_EL3 bit15 */
			{12416, 6,1}, /* core3 elr_EL3 bit16 */
			{11305, 6,1}, /* core3 elr_EL3 bit17 */
			{11304, 6,1}, /* core3 elr_EL3 bit18 */
			{11311, 6,1}, /* core3 elr_EL3 bit19 */
			{11315, 6,1}, /* core3 elr_EL3 bit20 */
			{11314, 6,1}, /* core3 elr_EL3 bit21 */
			{11310, 6,1}, /* core3 elr_EL3 bit22 */
			{12463, 6,1}, /* core3 elr_EL3 bit23 */
			{12462, 6,1}, /* core3 elr_EL3 bit24 */
			{14533, 6,1}, /* core3 elr_EL3 bit25 */
			{24349, 6,0}, /* core3 elr_EL3 bit26 */
			{24348, 6,0}, /* core3 elr_EL3 bit27 */
			{11313, 6,1}, /* core3 elr_EL3 bit28 */
			{13811, 6,1}, /* core3 elr_EL3 bit29 */
			{11312, 6,1}, /* core3 elr_EL3 bit30 */
			{14534, 6,1}, /* core3 elr_EL3 bit31 */
			{12771, 6,1}, /* core3 elr_EL3 bit32 */
			{12770, 6,1}, /* core3 elr_EL3 bit33 */
			{12773, 6,1}, /* core3 elr_EL3 bit34 */
			{12783, 6,1}, /* core3 elr_EL3 bit35 */
			{12782, 6,1}, /* core3 elr_EL3 bit36 */
			{12839, 6,1}, /* core3 elr_EL3 bit37 */
			{12772, 6,1}, /* core3 elr_EL3 bit38 */
			{12838, 6,1}, /* core3 elr_EL3 bit39 */
			{12767, 6,1}, /* core3 elr_EL3 bit40 */
			{12841, 6,1}, /* core3 elr_EL3 bit41 */
			{12840, 6,1}, /* core3 elr_EL3 bit42 */
			{12766, 6,1}, /* core3 elr_EL3 bit43 */
			{12781, 6,1}, /* core3 elr_EL3 bit44 */
			{12780, 6,1}, /* core3 elr_EL3 bit45 */
			{14522, 6,1}, /* core3 elr_EL3 bit46 */
			{12769, 6,1}, /* core3 elr_EL3 bit47 */
			{12775, 6,1}, /* core3 elr_EL3 bit48 */
			{12774, 6,1}, /* core3 elr_EL3 bit49 */
			{12777, 6,1}, /* core3 elr_EL3 bit50 */
			{12776, 6,1}, /* core3 elr_EL3 bit51 */
			{12843, 6,1}, /* core3 elr_EL3 bit52 */
			{12842, 6,1}, /* core3 elr_EL3 bit53 */
			{12779, 6,1}, /* core3 elr_EL3 bit54 */
			{12778, 6,1}, /* core3 elr_EL3 bit55 */
			{12768, 6,1}, /* core3 elr_EL3 bit56 */
			{12845, 6,1}, /* core3 elr_EL3 bit57 */
			{12844, 6,1}, /* core3 elr_EL3 bit58 */
			{12847, 6,1}, /* core3 elr_EL3 bit59 */
			{12846, 6,1}, /* core3 elr_EL3 bit60 */
			{12849, 6,1}, /* core3 elr_EL3 bit61 */
			{12848, 6,1}, /* core3 elr_EL3 bit62 */
			{14521, 6,1}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{10298, 6,1}, /* core3 raw_pc bit0 */
			{10297, 6,1}, /* core3 raw_pc bit1 */
			{10296, 6,1}, /* core3 raw_pc bit2 */
			{10579, 6,1}, /* core3 raw_pc bit3 */
			{10578, 6,1}, /* core3 raw_pc bit4 */
			{10577, 6,1}, /* core3 raw_pc bit5 */
			{10576, 6,1}, /* core3 raw_pc bit6 */
			{10435, 6,1}, /* core3 raw_pc bit7 */
			{10434, 6,1}, /* core3 raw_pc bit8 */
			{10425, 6,1}, /* core3 raw_pc bit9 */
			{10424, 6,1}, /* core3 raw_pc bit10 */
			{10437, 6,1}, /* core3 raw_pc bit11 */
			{10427, 6,1}, /* core3 raw_pc bit12 */
			{10426, 6,1}, /* core3 raw_pc bit13 */
			{10423, 6,1}, /* core3 raw_pc bit14 */
			{10597, 6,1}, /* core3 raw_pc bit15 */
			{10436, 6,1}, /* core3 raw_pc bit16 */
			{10595, 6,1}, /* core3 raw_pc bit17 */
			{10594, 6,1}, /* core3 raw_pc bit18 */
			{10596, 6,1}, /* core3 raw_pc bit19 */
			{10439, 6,1}, /* core3 raw_pc bit20 */
			{10438, 6,1}, /* core3 raw_pc bit21 */
			{10431, 6,1}, /* core3 raw_pc bit22 */
			{10430, 6,1}, /* core3 raw_pc bit23 */
			{10433, 6,1}, /* core3 raw_pc bit24 */
			{10432, 6,1}, /* core3 raw_pc bit25 */
			{22628, 6,1}, /* core3 raw_pc bit26 */
			{10422, 6,1}, /* core3 raw_pc bit27 */
			{10429, 6,1}, /* core3 raw_pc bit28 */
			{10428, 6,1}, /* core3 raw_pc bit29 */
			{22629, 6,1}, /* core3 raw_pc bit30 */
			{22249, 6,1}, /* core3 raw_pc bit31 */
			{22248, 6,1}, /* core3 raw_pc bit32 */
			{22251, 6,1}, /* core3 raw_pc bit33 */
			{22257, 6,1}, /* core3 raw_pc bit34 */
			{22250, 6,1}, /* core3 raw_pc bit35 */
			{22219, 6,1}, /* core3 raw_pc bit36 */
			{22256, 6,1}, /* core3 raw_pc bit37 */
			{22218, 6,1}, /* core3 raw_pc bit38 */
			{22253, 6,1}, /* core3 raw_pc bit39 */
			{22215, 6,1}, /* core3 raw_pc bit40 */
			{22252, 6,1}, /* core3 raw_pc bit41 */
			{22214, 6,1}, /* core3 raw_pc bit42 */
			{22217, 6,1}, /* core3 raw_pc bit43 */
			{22255, 6,1}, /* core3 raw_pc bit44 */
			{22254, 6,1}, /* core3 raw_pc bit45 */
			{22216, 6,1}, /* core3 raw_pc bit46 */
			{23218, 6,1}, /* core3 raw_pc bit47 */
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
			{22649, 6,1}, /* core3 pc_iss bit0 */
			{22279, 6,1}, /* core3 pc_iss bit1 */
			{22278, 6,1}, /* core3 pc_iss bit2 */
			{ 9131, 6,1}, /* core3 pc_iss bit3 */
			{ 9130, 6,1}, /* core3 pc_iss bit4 */
			{22281, 6,1}, /* core3 pc_iss bit5 */
			{22280, 6,1}, /* core3 pc_iss bit6 */
			{22648, 6,1}, /* core3 pc_iss bit7 */
			{22261, 6,1}, /* core3 pc_iss bit8 */
			{22260, 6,1}, /* core3 pc_iss bit9 */
			{22263, 6,1}, /* core3 pc_iss bit10 */
			{22262, 6,1}, /* core3 pc_iss bit11 */
			{22293, 6,1}, /* core3 pc_iss bit12 */
			{22292, 6,1}, /* core3 pc_iss bit13 */
			{22259, 6,1}, /* core3 pc_iss bit14 */
			{22258, 6,1}, /* core3 pc_iss bit15 */
			{22299, 6,1}, /* core3 pc_iss bit16 */
			{22298, 6,1}, /* core3 pc_iss bit17 */
			{23221, 6,1}, /* core3 pc_iss bit18 */
			{22285, 6,1}, /* core3 pc_iss bit19 */
			{22284, 6,1}, /* core3 pc_iss bit20 */
			{22297, 6,1}, /* core3 pc_iss bit21 */
			{22296, 6,1}, /* core3 pc_iss bit22 */
			{22295, 6,1}, /* core3 pc_iss bit23 */
			{22294, 6,1}, /* core3 pc_iss bit24 */
			{22291, 6,1}, /* core3 pc_iss bit25 */
			{22290, 6,1}, /* core3 pc_iss bit26 */
			{22287, 6,1}, /* core3 pc_iss bit27 */
			{22286, 6,1}, /* core3 pc_iss bit28 */
			{22289, 6,1}, /* core3 pc_iss bit29 */
			{22288, 6,1}, /* core3 pc_iss bit30 */
			{23220, 6,1}, /* core3 pc_iss bit31 */
			{22341, 6,1}, /* core3 pc_iss bit32 */
			{22340, 6,1}, /* core3 pc_iss bit33 */
			{22337, 6,1}, /* core3 pc_iss bit34 */
			{22336, 6,1}, /* core3 pc_iss bit35 */
			{22339, 6,1}, /* core3 pc_iss bit36 */
			{22338, 6,1}, /* core3 pc_iss bit37 */
			{21785, 6,1}, /* core3 pc_iss bit38 */
			{21784, 6,1}, /* core3 pc_iss bit39 */
			{23215, 6,1}, /* core3 pc_iss bit40 */
			{23214, 6,1}, /* core3 pc_iss bit41 */
			{22335, 6,1}, /* core3 pc_iss bit42 */
			{21783, 6,1}, /* core3 pc_iss bit43 */
			{22334, 6,1}, /* core3 pc_iss bit44 */
			{22333, 6,1}, /* core3 pc_iss bit45 */
			{21782, 6,1}, /* core3 pc_iss bit46 */
			{22332, 6,1}, /* core3 pc_iss bit47 */
			{21775, 6,1}, /* core3 pc_iss bit48 */
			{21774, 6,1}, /* core3 pc_iss bit49 */
			{21777, 6,1}, /* core3 pc_iss bit50 */
			{22327, 6,1}, /* core3 pc_iss bit51 */
			{22326, 6,1}, /* core3 pc_iss bit52 */
			{22325, 6,1}, /* core3 pc_iss bit53 */
			{22324, 6,1}, /* core3 pc_iss bit54 */
			{21776, 6,1}, /* core3 pc_iss bit55 */
			{22331, 6,1}, /* core3 pc_iss bit56 */
			{22330, 6,1}, /* core3 pc_iss bit57 */
			{22329, 6,1}, /* core3 pc_iss bit58 */
			{22328, 6,1}, /* core3 pc_iss bit59 */
			{21779, 6,1}, /* core3 pc_iss bit60 */
			{21778, 6,1}, /* core3 pc_iss bit61 */
			{21781, 6,1}, /* core3 pc_iss bit62 */
			{21780, 6,1}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{10299, 6,1}, /* core3 full_pc_wr bit0 */
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
			{13824, 6,1}, /* core3 full_pc_ex1 bit0 */
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
			{10249, 6,1}, /* core3 full_pc_ex2 bit0 */
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
			.spmc_power_state = {{
			{15899,23,0}, /* core4 spmc_power_state bit0 */
			{15360,21,1}, /* core4 spmc_power_state bit1 */
			{15359,21,1}, /* core4 spmc_power_state bit2 */
			{15362,21,1}, /* core4 spmc_power_state bit3 */
			{15361,21,1}, /* core4 spmc_power_state bit4 */
			{15848,23,0}, /* core4 spmc_power_state bit5 */
			{    0, 0,2}, /* core4 spmc_power_state bit6 */
			{    0, 0,2}, /* core4 spmc_power_state bit7 */
			{    0, 0,2}, /* core4 spmc_power_state bit8 */
			{    0, 0,2}, /* core4 spmc_power_state bit9 */
			{    0, 0,2}, /* core4 spmc_power_state bit10 */
			{    0, 0,2}, /* core4 spmc_power_state bit11 */
			{    0, 0,2}, /* core4 spmc_power_state bit12 */
			{    0, 0,2}, /* core4 spmc_power_state bit13 */
			{    0, 0,2}, /* core4 spmc_power_state bit14 */
			{    0, 0,2}, /* core4 spmc_power_state bit15 */
			{    0, 0,2}, /* core4 spmc_power_state bit16 */
			{    0, 0,2}, /* core4 spmc_power_state bit17 */
			{    0, 0,2}, /* core4 spmc_power_state bit18 */
			{    0, 0,2}, /* core4 spmc_power_state bit19 */
			{    0, 0,2}, /* core4 spmc_power_state bit20 */
			{    0, 0,2}, /* core4 spmc_power_state bit21 */
			{    0, 0,2}, /* core4 spmc_power_state bit22 */
			{    0, 0,2}, /* core4 spmc_power_state bit23 */
			{    0, 0,2}, /* core4 spmc_power_state bit24 */
			{    0, 0,2}, /* core4 spmc_power_state bit25 */
			{    0, 0,2}, /* core4 spmc_power_state bit26 */
			{    0, 0,2}, /* core4 spmc_power_state bit27 */
			{    0, 0,2}, /* core4 spmc_power_state bit28 */
			{    0, 0,2}, /* core4 spmc_power_state bit29 */
			{    0, 0,2}, /* core4 spmc_power_state bit30 */
			{    0, 0,2}, /* core4 spmc_power_state bit31 */
			{    0, 0,2}, /* core4 spmc_power_state bit32 */
			{    0, 0,2}, /* core4 spmc_power_state bit33 */
			{    0, 0,2}, /* core4 spmc_power_state bit34 */
			{    0, 0,2}, /* core4 spmc_power_state bit35 */
			{    0, 0,2}, /* core4 spmc_power_state bit36 */
			{    0, 0,2}, /* core4 spmc_power_state bit37 */
			{    0, 0,2}, /* core4 spmc_power_state bit38 */
			{    0, 0,2}, /* core4 spmc_power_state bit39 */
			{    0, 0,2}, /* core4 spmc_power_state bit40 */
			{    0, 0,2}, /* core4 spmc_power_state bit41 */
			{    0, 0,2}, /* core4 spmc_power_state bit42 */
			{    0, 0,2}, /* core4 spmc_power_state bit43 */
			{    0, 0,2}, /* core4 spmc_power_state bit44 */
			{    0, 0,2}, /* core4 spmc_power_state bit45 */
			{    0, 0,2}, /* core4 spmc_power_state bit46 */
			{    0, 0,2}, /* core4 spmc_power_state bit47 */
			{    0, 0,2}, /* core4 spmc_power_state bit48 */
			{    0, 0,2}, /* core4 spmc_power_state bit49 */
			{    0, 0,2}, /* core4 spmc_power_state bit50 */
			{    0, 0,2}, /* core4 spmc_power_state bit51 */
			{    0, 0,2}, /* core4 spmc_power_state bit52 */
			{    0, 0,2}, /* core4 spmc_power_state bit53 */
			{    0, 0,2}, /* core4 spmc_power_state bit54 */
			{    0, 0,2}, /* core4 spmc_power_state bit55 */
			{    0, 0,2}, /* core4 spmc_power_state bit56 */
			{    0, 0,2}, /* core4 spmc_power_state bit57 */
			{    0, 0,2}, /* core4 spmc_power_state bit58 */
			{    0, 0,2}, /* core4 spmc_power_state bit59 */
			{    0, 0,2}, /* core4 spmc_power_state bit60 */
			{    0, 0,2}, /* core4 spmc_power_state bit61 */
			{    0, 0,2}, /* core4 spmc_power_state bit62 */
			{    0, 0,2}, /* core4 spmc_power_state bit63 */
			}},
			.pc = {{
			{13357, 8,1}, /* core4 pc bit0 */
			{13356, 8,1}, /* core4 pc bit1 */
			{13355, 8,1}, /* core4 pc bit2 */
			{13354, 8,1}, /* core4 pc bit3 */
			{13497, 8,1}, /* core4 pc bit4 */
			{13496, 8,1}, /* core4 pc bit5 */
			{13495, 8,1}, /* core4 pc bit6 */
			{13494, 8,1}, /* core4 pc bit7 */
			{13709, 8,1}, /* core4 pc bit8 */
			{13708, 8,1}, /* core4 pc bit9 */
			{13707, 8,1}, /* core4 pc bit10 */
			{13706, 8,1}, /* core4 pc bit11 */
			{13309, 8,1}, /* core4 pc bit12 */
			{13308, 8,1}, /* core4 pc bit13 */
			{13307, 8,1}, /* core4 pc bit14 */
			{13306, 8,1}, /* core4 pc bit15 */
			{12965, 8,1}, /* core4 pc bit16 */
			{12964, 8,1}, /* core4 pc bit17 */
			{12963, 8,1}, /* core4 pc bit18 */
			{12962, 8,1}, /* core4 pc bit19 */
			{13149, 8,1}, /* core4 pc bit20 */
			{13148, 8,1}, /* core4 pc bit21 */
			{13147, 8,1}, /* core4 pc bit22 */
			{13146, 8,1}, /* core4 pc bit23 */
			{13313, 8,1}, /* core4 pc bit24 */
			{13312, 8,1}, /* core4 pc bit25 */
			{13311, 8,1}, /* core4 pc bit26 */
			{13310, 8,1}, /* core4 pc bit27 */
			{13689, 8,1}, /* core4 pc bit28 */
			{13688, 8,1}, /* core4 pc bit29 */
			{13687, 8,1}, /* core4 pc bit30 */
			{13686, 8,1}, /* core4 pc bit31 */
			{13525, 8,1}, /* core4 pc bit32 */
			{13524, 8,1}, /* core4 pc bit33 */
			{13523, 8,1}, /* core4 pc bit34 */
			{13522, 8,1}, /* core4 pc bit35 */
			{13325, 8,1}, /* core4 pc bit36 */
			{13324, 8,1}, /* core4 pc bit37 */
			{13323, 8,1}, /* core4 pc bit38 */
			{13322, 8,1}, /* core4 pc bit39 */
			{13521, 8,1}, /* core4 pc bit40 */
			{13520, 8,1}, /* core4 pc bit41 */
			{13519, 8,1}, /* core4 pc bit42 */
			{13518, 8,1}, /* core4 pc bit43 */
			{13157, 8,1}, /* core4 pc bit44 */
			{13156, 8,1}, /* core4 pc bit45 */
			{13155, 8,1}, /* core4 pc bit46 */
			{13154, 8,1}, /* core4 pc bit47 */
			{12981, 8,1}, /* core4 pc bit48 */
			{12980, 8,1}, /* core4 pc bit49 */
			{12979, 8,1}, /* core4 pc bit50 */
			{12978, 8,1}, /* core4 pc bit51 */
			{12997, 8,1}, /* core4 pc bit52 */
			{12996, 8,1}, /* core4 pc bit53 */
			{12995, 8,1}, /* core4 pc bit54 */
			{12994, 8,1}, /* core4 pc bit55 */
			{12973, 8,1}, /* core4 pc bit56 */
			{12972, 8,1}, /* core4 pc bit57 */
			{12971, 8,1}, /* core4 pc bit58 */
			{12970, 8,1}, /* core4 pc bit59 */
			{13529, 8,1}, /* core4 pc bit60 */
			{13528, 8,1}, /* core4 pc bit61 */
			{13527, 8,1}, /* core4 pc bit62 */
			{13526, 8,1}, /* core4 pc bit63 */
			}},
			.sp32 = {{
			{21453, 8,1}, /* core4 sp32 bit0 */
			{21452, 8,1}, /* core4 sp32 bit1 */
			{21451, 8,1}, /* core4 sp32 bit2 */
			{21450, 8,1}, /* core4 sp32 bit3 */
			{18933, 9,1}, /* core4 sp32 bit4 */
			{18916, 9,1}, /* core4 sp32 bit5 */
			{18931, 9,1}, /* core4 sp32 bit6 */
			{18915, 9,1}, /* core4 sp32 bit7 */
			{18935, 9,1}, /* core4 sp32 bit8 */
			{18930, 9,1}, /* core4 sp32 bit9 */
			{18934, 9,1}, /* core4 sp32 bit10 */
			{18917, 9,1}, /* core4 sp32 bit11 */
			{18932, 9,1}, /* core4 sp32 bit12 */
			{18918, 9,1}, /* core4 sp32 bit13 */
			{19085, 9,1}, /* core4 sp32 bit14 */
			{19087, 9,1}, /* core4 sp32 bit15 */
			{19316, 9,1}, /* core4 sp32 bit16 */
			{19317, 9,1}, /* core4 sp32 bit17 */
			{19315, 9,1}, /* core4 sp32 bit18 */
			{19320, 9,1}, /* core4 sp32 bit19 */
			{19620, 9,1}, /* core4 sp32 bit20 */
			{19489, 9,1}, /* core4 sp32 bit21 */
			{20067, 9,1}, /* core4 sp32 bit22 */
			{20068, 9,1}, /* core4 sp32 bit23 */
			{19911, 9,1}, /* core4 sp32 bit24 */
			{19318, 9,1}, /* core4 sp32 bit25 */
			{19319, 9,1}, /* core4 sp32 bit26 */
			{19615, 9,1}, /* core4 sp32 bit27 */
			{19487, 9,1}, /* core4 sp32 bit28 */
			{19488, 9,1}, /* core4 sp32 bit29 */
			{19321, 9,1}, /* core4 sp32 bit30 */
			{19947, 9,1}, /* core4 sp32 bit31 */
			{21259, 9,1}, /* core4 sp32 bit32 */
			{24269, 9,1}, /* core4 sp32 bit33 */
			{24268, 9,1}, /* core4 sp32 bit34 */
			{20735, 9,1}, /* core4 sp32 bit35 */
			{21222, 9,1}, /* core4 sp32 bit36 */
			{21221, 9,1}, /* core4 sp32 bit37 */
			{20734, 9,1}, /* core4 sp32 bit38 */
			{24271, 9,1}, /* core4 sp32 bit39 */
			{21064, 9,1}, /* core4 sp32 bit40 */
			{21257, 9,1}, /* core4 sp32 bit41 */
			{21220, 9,1}, /* core4 sp32 bit42 */
			{21219, 9,1}, /* core4 sp32 bit43 */
			{21256, 9,1}, /* core4 sp32 bit44 */
			{20892, 9,1}, /* core4 sp32 bit45 */
			{21258, 9,1}, /* core4 sp32 bit46 */
			{24270, 9,1}, /* core4 sp32 bit47 */
			{22709, 8,1}, /* core4 sp32 bit48 */
			{22708, 8,1}, /* core4 sp32 bit49 */
			{22707, 8,1}, /* core4 sp32 bit50 */
			{22706, 8,1}, /* core4 sp32 bit51 */
			{22357, 8,1}, /* core4 sp32 bit52 */
			{24257, 9,1}, /* core4 sp32 bit53 */
			{22356, 8,1}, /* core4 sp32 bit54 */
			{22355, 8,1}, /* core4 sp32 bit55 */
			{22354, 8,1}, /* core4 sp32 bit56 */
			{22425, 8,1}, /* core4 sp32 bit57 */
			{22424, 8,1}, /* core4 sp32 bit58 */
			{22423, 8,1}, /* core4 sp32 bit59 */
			{22422, 8,1}, /* core4 sp32 bit60 */
			{24256, 9,1}, /* core4 sp32 bit61 */
			{24259, 9,1}, /* core4 sp32 bit62 */
			{24258, 9,1}, /* core4 sp32 bit63 */
			}},
			.fp32 = {{
			{21521, 8,1}, /* core4 fp32 bit0 */
			{21520, 8,1}, /* core4 fp32 bit1 */
			{21519, 8,1}, /* core4 fp32 bit2 */
			{21518, 8,1}, /* core4 fp32 bit3 */
			{18466, 9,1}, /* core4 fp32 bit4 */
			{18286, 9,1}, /* core4 fp32 bit5 */
			{18285, 9,1}, /* core4 fp32 bit6 */
			{18287, 9,1}, /* core4 fp32 bit7 */
			{18461, 9,1}, /* core4 fp32 bit8 */
			{18465, 9,1}, /* core4 fp32 bit9 */
			{18284, 9,1}, /* core4 fp32 bit10 */
			{18467, 9,1}, /* core4 fp32 bit11 */
			{18463, 9,1}, /* core4 fp32 bit12 */
			{18462, 9,1}, /* core4 fp32 bit13 */
			{18468, 9,1}, /* core4 fp32 bit14 */
			{18464, 9,1}, /* core4 fp32 bit15 */
			{19113, 9,1}, /* core4 fp32 bit16 */
			{19112, 9,1}, /* core4 fp32 bit17 */
			{19116, 9,1}, /* core4 fp32 bit18 */
			{19115, 9,1}, /* core4 fp32 bit19 */
			{20145, 9,1}, /* core4 fp32 bit20 */
			{19119, 9,1}, /* core4 fp32 bit21 */
			{19368, 9,1}, /* core4 fp32 bit22 */
			{19369, 9,1}, /* core4 fp32 bit23 */
			{19371, 9,1}, /* core4 fp32 bit24 */
			{19878, 9,1}, /* core4 fp32 bit25 */
			{19117, 9,1}, /* core4 fp32 bit26 */
			{19370, 9,1}, /* core4 fp32 bit27 */
			{19114, 9,1}, /* core4 fp32 bit28 */
			{19118, 9,1}, /* core4 fp32 bit29 */
			{19372, 9,1}, /* core4 fp32 bit30 */
			{19877, 9,1}, /* core4 fp32 bit31 */
			{22070, 9,1}, /* core4 fp32 bit32 */
			{24617, 9,1}, /* core4 fp32 bit33 */
			{22069, 9,1}, /* core4 fp32 bit34 */
			{22072, 9,1}, /* core4 fp32 bit35 */
			{22039, 9,1}, /* core4 fp32 bit36 */
			{22044, 9,1}, /* core4 fp32 bit37 */
			{22074, 9,1}, /* core4 fp32 bit38 */
			{22067, 9,1}, /* core4 fp32 bit39 */
			{22073, 9,1}, /* core4 fp32 bit40 */
			{21851, 9,1}, /* core4 fp32 bit41 */
			{22075, 9,1}, /* core4 fp32 bit42 */
			{21852, 9,1}, /* core4 fp32 bit43 */
			{22071, 9,1}, /* core4 fp32 bit44 */
			{22038, 9,1}, /* core4 fp32 bit45 */
			{22068, 9,1}, /* core4 fp32 bit46 */
			{24616, 9,1}, /* core4 fp32 bit47 */
			{23597, 8,1}, /* core4 fp32 bit48 */
			{23596, 8,1}, /* core4 fp32 bit49 */
			{23595, 8,1}, /* core4 fp32 bit50 */
			{23594, 8,1}, /* core4 fp32 bit51 */
			{23585, 8,1}, /* core4 fp32 bit52 */
			{23584, 8,1}, /* core4 fp32 bit53 */
			{23583, 8,1}, /* core4 fp32 bit54 */
			{23582, 8,1}, /* core4 fp32 bit55 */
			{23589, 8,1}, /* core4 fp32 bit56 */
			{23588, 8,1}, /* core4 fp32 bit57 */
			{23587, 8,1}, /* core4 fp32 bit58 */
			{23586, 8,1}, /* core4 fp32 bit59 */
			{23593, 8,1}, /* core4 fp32 bit60 */
			{23592, 8,1}, /* core4 fp32 bit61 */
			{23591, 8,1}, /* core4 fp32 bit62 */
			{23590, 8,1}, /* core4 fp32 bit63 */
			}},
			.fp64 = {{
			{21449, 8,1}, /* core4 fp64 bit0 */
			{21448, 8,1}, /* core4 fp64 bit1 */
			{21447, 8,1}, /* core4 fp64 bit2 */
			{21446, 8,1}, /* core4 fp64 bit3 */
			{18920, 9,1}, /* core4 fp64 bit4 */
			{19090, 9,1}, /* core4 fp64 bit5 */
			{19065, 9,1}, /* core4 fp64 bit6 */
			{19088, 9,1}, /* core4 fp64 bit7 */
			{18922, 9,1}, /* core4 fp64 bit8 */
			{18928, 9,1}, /* core4 fp64 bit9 */
			{18919, 9,1}, /* core4 fp64 bit10 */
			{18929, 9,1}, /* core4 fp64 bit11 */
			{18921, 9,1}, /* core4 fp64 bit12 */
			{18923, 9,1}, /* core4 fp64 bit13 */
			{19064, 9,1}, /* core4 fp64 bit14 */
			{19066, 9,1}, /* core4 fp64 bit15 */
			{19322, 9,1}, /* core4 fp64 bit16 */
			{19485, 9,1}, /* core4 fp64 bit17 */
			{19482, 9,1}, /* core4 fp64 bit18 */
			{19483, 9,1}, /* core4 fp64 bit19 */
			{20163, 9,1}, /* core4 fp64 bit20 */
			{19906, 9,1}, /* core4 fp64 bit21 */
			{19904, 9,1}, /* core4 fp64 bit22 */
			{19905, 9,1}, /* core4 fp64 bit23 */
			{19907, 9,1}, /* core4 fp64 bit24 */
			{19484, 9,1}, /* core4 fp64 bit25 */
			{19486, 9,1}, /* core4 fp64 bit26 */
			{19910, 9,1}, /* core4 fp64 bit27 */
			{19481, 9,1}, /* core4 fp64 bit28 */
			{19909, 9,1}, /* core4 fp64 bit29 */
			{19323, 9,1}, /* core4 fp64 bit30 */
			{19908, 9,1}, /* core4 fp64 bit31 */
			{20417, 9,1}, /* core4 fp64 bit32 */
			{20381, 9,1}, /* core4 fp64 bit33 */
			{20375, 9,1}, /* core4 fp64 bit34 */
			{20176, 9,1}, /* core4 fp64 bit35 */
			{20416, 9,1}, /* core4 fp64 bit36 */
			{20171, 9,1}, /* core4 fp64 bit37 */
			{20379, 9,1}, /* core4 fp64 bit38 */
			{20374, 9,1}, /* core4 fp64 bit39 */
			{20373, 9,1}, /* core4 fp64 bit40 */
			{20170, 9,1}, /* core4 fp64 bit41 */
			{20377, 9,1}, /* core4 fp64 bit42 */
			{20378, 9,1}, /* core4 fp64 bit43 */
			{20376, 9,1}, /* core4 fp64 bit44 */
			{20174, 9,1}, /* core4 fp64 bit45 */
			{20175, 9,1}, /* core4 fp64 bit46 */
			{20418, 9,1}, /* core4 fp64 bit47 */
			{20562, 9,1}, /* core4 fp64 bit48 */
			{24281, 9,1}, /* core4 fp64 bit49 */
			{24280, 9,1}, /* core4 fp64 bit50 */
			{20560, 9,1}, /* core4 fp64 bit51 */
			{20564, 9,1}, /* core4 fp64 bit52 */
			{20566, 9,1}, /* core4 fp64 bit53 */
			{20565, 9,1}, /* core4 fp64 bit54 */
			{20561, 9,1}, /* core4 fp64 bit55 */
			{20563, 9,1}, /* core4 fp64 bit56 */
			{20380, 9,1}, /* core4 fp64 bit57 */
			{20372, 9,1}, /* core4 fp64 bit58 */
			{20172, 9,1}, /* core4 fp64 bit59 */
			{21549, 8,1}, /* core4 fp64 bit60 */
			{21548, 8,1}, /* core4 fp64 bit61 */
			{21547, 8,1}, /* core4 fp64 bit62 */
			{21546, 8,1}, /* core4 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{21625, 8,1}, /* core4 sp_EL0 bit0 */
			{21624, 8,1}, /* core4 sp_EL0 bit1 */
			{21623, 8,1}, /* core4 sp_EL0 bit2 */
			{21622, 8,1}, /* core4 sp_EL0 bit3 */
			{18483, 9,1}, /* core4 sp_EL0 bit4 */
			{18614, 9,1}, /* core4 sp_EL0 bit5 */
			{18612, 9,1}, /* core4 sp_EL0 bit6 */
			{18486, 9,1}, /* core4 sp_EL0 bit7 */
			{18824, 9,1}, /* core4 sp_EL0 bit8 */
			{18664, 9,1}, /* core4 sp_EL0 bit9 */
			{18823, 9,1}, /* core4 sp_EL0 bit10 */
			{18482, 9,1}, /* core4 sp_EL0 bit11 */
			{18613, 9,1}, /* core4 sp_EL0 bit12 */
			{18663, 9,1}, /* core4 sp_EL0 bit13 */
			{18615, 9,1}, /* core4 sp_EL0 bit14 */
			{18822, 9,1}, /* core4 sp_EL0 bit15 */
			{19289, 9,1}, /* core4 sp_EL0 bit16 */
			{19351, 9,1}, /* core4 sp_EL0 bit17 */
			{19353, 9,1}, /* core4 sp_EL0 bit18 */
			{19350, 9,1}, /* core4 sp_EL0 bit19 */
			{19749, 9,1}, /* core4 sp_EL0 bit20 */
			{20136, 9,1}, /* core4 sp_EL0 bit21 */
			{19748, 9,1}, /* core4 sp_EL0 bit22 */
			{20135, 9,1}, /* core4 sp_EL0 bit23 */
			{19900, 9,1}, /* core4 sp_EL0 bit24 */
			{19288, 9,1}, /* core4 sp_EL0 bit25 */
			{19290, 9,1}, /* core4 sp_EL0 bit26 */
			{19750, 9,1}, /* core4 sp_EL0 bit27 */
			{19515, 9,1}, /* core4 sp_EL0 bit28 */
			{19514, 9,1}, /* core4 sp_EL0 bit29 */
			{19352, 9,1}, /* core4 sp_EL0 bit30 */
			{19901, 9,1}, /* core4 sp_EL0 bit31 */
			{20581, 9,1}, /* core4 sp_EL0 bit32 */
			{24277, 9,1}, /* core4 sp_EL0 bit33 */
			{20368, 9,1}, /* core4 sp_EL0 bit34 */
			{20419, 9,1}, /* core4 sp_EL0 bit35 */
			{20424, 9,1}, /* core4 sp_EL0 bit36 */
			{20421, 9,1}, /* core4 sp_EL0 bit37 */
			{20580, 9,1}, /* core4 sp_EL0 bit38 */
			{20770, 9,1}, /* core4 sp_EL0 bit39 */
			{20423, 9,1}, /* core4 sp_EL0 bit40 */
			{20369, 9,1}, /* core4 sp_EL0 bit41 */
			{20582, 9,1}, /* core4 sp_EL0 bit42 */
			{20370, 9,1}, /* core4 sp_EL0 bit43 */
			{20420, 9,1}, /* core4 sp_EL0 bit44 */
			{20583, 9,1}, /* core4 sp_EL0 bit45 */
			{20367, 9,1}, /* core4 sp_EL0 bit46 */
			{20422, 9,1}, /* core4 sp_EL0 bit47 */
			{24276, 9,1}, /* core4 sp_EL0 bit48 */
			{22133, 8,1}, /* core4 sp_EL0 bit49 */
			{22132, 8,1}, /* core4 sp_EL0 bit50 */
			{22131, 8,1}, /* core4 sp_EL0 bit51 */
			{22130, 8,1}, /* core4 sp_EL0 bit52 */
			{22137, 8,1}, /* core4 sp_EL0 bit53 */
			{22136, 8,1}, /* core4 sp_EL0 bit54 */
			{22135, 8,1}, /* core4 sp_EL0 bit55 */
			{22134, 8,1}, /* core4 sp_EL0 bit56 */
			{21805, 8,1}, /* core4 sp_EL0 bit57 */
			{21804, 8,1}, /* core4 sp_EL0 bit58 */
			{21803, 8,1}, /* core4 sp_EL0 bit59 */
			{21802, 8,1}, /* core4 sp_EL0 bit60 */
			{24279, 9,1}, /* core4 sp_EL0 bit61 */
			{24278, 9,1}, /* core4 sp_EL0 bit62 */
			{20371, 9,1}, /* core4 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{21457, 8,1}, /* core4 sp_EL1 bit0 */
			{21456, 8,1}, /* core4 sp_EL1 bit1 */
			{21455, 8,1}, /* core4 sp_EL1 bit2 */
			{21454, 8,1}, /* core4 sp_EL1 bit3 */
			{18836, 9,1}, /* core4 sp_EL1 bit4 */
			{18679, 9,1}, /* core4 sp_EL1 bit5 */
			{18840, 9,1}, /* core4 sp_EL1 bit6 */
			{18837, 9,1}, /* core4 sp_EL1 bit7 */
			{18841, 9,1}, /* core4 sp_EL1 bit8 */
			{18881, 9,1}, /* core4 sp_EL1 bit9 */
			{18677, 9,1}, /* core4 sp_EL1 bit10 */
			{18678, 9,1}, /* core4 sp_EL1 bit11 */
			{18842, 9,1}, /* core4 sp_EL1 bit12 */
			{18839, 9,1}, /* core4 sp_EL1 bit13 */
			{18838, 9,1}, /* core4 sp_EL1 bit14 */
			{19086, 9,1}, /* core4 sp_EL1 bit15 */
			{19314, 9,1}, /* core4 sp_EL1 bit16 */
			{19491, 9,1}, /* core4 sp_EL1 bit17 */
			{19311, 9,1}, /* core4 sp_EL1 bit18 */
			{19312, 9,1}, /* core4 sp_EL1 bit19 */
			{20069, 9,1}, /* core4 sp_EL1 bit20 */
			{19765, 9,1}, /* core4 sp_EL1 bit21 */
			{19611, 9,1}, /* core4 sp_EL1 bit22 */
			{19912, 9,1}, /* core4 sp_EL1 bit23 */
			{19766, 9,1}, /* core4 sp_EL1 bit24 */
			{19492, 9,1}, /* core4 sp_EL1 bit25 */
			{19493, 9,1}, /* core4 sp_EL1 bit26 */
			{19614, 9,1}, /* core4 sp_EL1 bit27 */
			{19490, 9,1}, /* core4 sp_EL1 bit28 */
			{19613, 9,1}, /* core4 sp_EL1 bit29 */
			{19310, 9,1}, /* core4 sp_EL1 bit30 */
			{19612, 9,1}, /* core4 sp_EL1 bit31 */
			{20570, 9,1}, /* core4 sp_EL1 bit32 */
			{20568, 9,1}, /* core4 sp_EL1 bit33 */
			{20412, 9,1}, /* core4 sp_EL1 bit34 */
			{20408, 9,1}, /* core4 sp_EL1 bit35 */
			{20404, 9,1}, /* core4 sp_EL1 bit36 */
			{20403, 9,1}, /* core4 sp_EL1 bit37 */
			{20558, 9,1}, /* core4 sp_EL1 bit38 */
			{20410, 9,1}, /* core4 sp_EL1 bit39 */
			{20406, 9,1}, /* core4 sp_EL1 bit40 */
			{20571, 9,1}, /* core4 sp_EL1 bit41 */
			{20409, 9,1}, /* core4 sp_EL1 bit42 */
			{20402, 9,1}, /* core4 sp_EL1 bit43 */
			{20405, 9,1}, /* core4 sp_EL1 bit44 */
			{20572, 9,1}, /* core4 sp_EL1 bit45 */
			{20414, 9,1}, /* core4 sp_EL1 bit46 */
			{20413, 9,1}, /* core4 sp_EL1 bit47 */
			{20557, 9,1}, /* core4 sp_EL1 bit48 */
			{24297, 9,1}, /* core4 sp_EL1 bit49 */
			{20567, 9,1}, /* core4 sp_EL1 bit50 */
			{21797, 8,1}, /* core4 sp_EL1 bit51 */
			{20569, 9,1}, /* core4 sp_EL1 bit52 */
			{20407, 9,1}, /* core4 sp_EL1 bit53 */
			{24296, 9,1}, /* core4 sp_EL1 bit54 */
			{21796, 8,1}, /* core4 sp_EL1 bit55 */
			{20559, 9,1}, /* core4 sp_EL1 bit56 */
			{21795, 8,1}, /* core4 sp_EL1 bit57 */
			{20411, 9,1}, /* core4 sp_EL1 bit58 */
			{24293, 9,1}, /* core4 sp_EL1 bit59 */
			{21794, 8,1}, /* core4 sp_EL1 bit60 */
			{24292, 9,1}, /* core4 sp_EL1 bit61 */
			{24295, 9,1}, /* core4 sp_EL1 bit62 */
			{24294, 9,1}, /* core4 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{21361, 8,1}, /* core4 sp_EL2 bit0 */
			{21360, 8,1}, /* core4 sp_EL2 bit1 */
			{21359, 8,1}, /* core4 sp_EL2 bit2 */
			{21358, 8,1}, /* core4 sp_EL2 bit3 */
			{18669, 9,1}, /* core4 sp_EL2 bit4 */
			{18670, 9,1}, /* core4 sp_EL2 bit5 */
			{18619, 9,1}, /* core4 sp_EL2 bit6 */
			{18830, 9,1}, /* core4 sp_EL2 bit7 */
			{18827, 9,1}, /* core4 sp_EL2 bit8 */
			{18618, 9,1}, /* core4 sp_EL2 bit9 */
			{18829, 9,1}, /* core4 sp_EL2 bit10 */
			{18667, 9,1}, /* core4 sp_EL2 bit11 */
			{18620, 9,1}, /* core4 sp_EL2 bit12 */
			{18668, 9,1}, /* core4 sp_EL2 bit13 */
			{18828, 9,1}, /* core4 sp_EL2 bit14 */
			{18831, 9,1}, /* core4 sp_EL2 bit15 */
			{19347, 9,1}, /* core4 sp_EL2 bit16 */
			{19345, 9,1}, /* core4 sp_EL2 bit17 */
			{19509, 9,1}, /* core4 sp_EL2 bit18 */
			{19511, 9,1}, /* core4 sp_EL2 bit19 */
			{19934, 9,1}, /* core4 sp_EL2 bit20 */
			{20143, 9,1}, /* core4 sp_EL2 bit21 */
			{19927, 9,1}, /* core4 sp_EL2 bit22 */
			{20142, 9,1}, /* core4 sp_EL2 bit23 */
			{19933, 9,1}, /* core4 sp_EL2 bit24 */
			{19512, 9,1}, /* core4 sp_EL2 bit25 */
			{19348, 9,1}, /* core4 sp_EL2 bit26 */
			{19638, 9,1}, /* core4 sp_EL2 bit27 */
			{19510, 9,1}, /* core4 sp_EL2 bit28 */
			{19932, 9,1}, /* core4 sp_EL2 bit29 */
			{19346, 9,1}, /* core4 sp_EL2 bit30 */
			{19928, 9,1}, /* core4 sp_EL2 bit31 */
			{20876, 9,1}, /* core4 sp_EL2 bit32 */
			{24309, 9,1}, /* core4 sp_EL2 bit33 */
			{20872, 9,1}, /* core4 sp_EL2 bit34 */
			{20869, 9,1}, /* core4 sp_EL2 bit35 */
			{20874, 9,1}, /* core4 sp_EL2 bit36 */
			{20873, 9,1}, /* core4 sp_EL2 bit37 */
			{20877, 9,1}, /* core4 sp_EL2 bit38 */
			{20870, 9,1}, /* core4 sp_EL2 bit39 */
			{20738, 9,1}, /* core4 sp_EL2 bit40 */
			{20875, 9,1}, /* core4 sp_EL2 bit41 */
			{20740, 9,1}, /* core4 sp_EL2 bit42 */
			{20878, 9,1}, /* core4 sp_EL2 bit43 */
			{20871, 9,1}, /* core4 sp_EL2 bit44 */
			{21045, 9,1}, /* core4 sp_EL2 bit45 */
			{24308, 9,1}, /* core4 sp_EL2 bit46 */
			{21044, 9,1}, /* core4 sp_EL2 bit47 */
			{22433, 8,1}, /* core4 sp_EL2 bit48 */
			{22432, 8,1}, /* core4 sp_EL2 bit49 */
			{22431, 8,1}, /* core4 sp_EL2 bit50 */
			{22430, 8,1}, /* core4 sp_EL2 bit51 */
			{22685, 8,1}, /* core4 sp_EL2 bit52 */
			{22684, 8,1}, /* core4 sp_EL2 bit53 */
			{22683, 8,1}, /* core4 sp_EL2 bit54 */
			{22682, 8,1}, /* core4 sp_EL2 bit55 */
			{22261, 8,1}, /* core4 sp_EL2 bit56 */
			{22260, 8,1}, /* core4 sp_EL2 bit57 */
			{22259, 8,1}, /* core4 sp_EL2 bit58 */
			{22258, 8,1}, /* core4 sp_EL2 bit59 */
			{22265, 8,1}, /* core4 sp_EL2 bit60 */
			{22264, 8,1}, /* core4 sp_EL2 bit61 */
			{22263, 8,1}, /* core4 sp_EL2 bit62 */
			{22262, 8,1}, /* core4 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{21617, 8,1}, /* core4 sp_EL3 bit0 */
			{21616, 8,1}, /* core4 sp_EL3 bit1 */
			{21615, 8,1}, /* core4 sp_EL3 bit2 */
			{21614, 8,1}, /* core4 sp_EL3 bit3 */
			{18625, 9,1}, /* core4 sp_EL3 bit4 */
			{18622, 9,1}, /* core4 sp_EL3 bit5 */
			{18623, 9,1}, /* core4 sp_EL3 bit6 */
			{18813, 9,1}, /* core4 sp_EL3 bit7 */
			{18796, 9,1}, /* core4 sp_EL3 bit8 */
			{18797, 9,1}, /* core4 sp_EL3 bit9 */
			{18812, 9,1}, /* core4 sp_EL3 bit10 */
			{18621, 9,1}, /* core4 sp_EL3 bit11 */
			{18795, 9,1}, /* core4 sp_EL3 bit12 */
			{18624, 9,1}, /* core4 sp_EL3 bit13 */
			{18961, 9,1}, /* core4 sp_EL3 bit14 */
			{18798, 9,1}, /* core4 sp_EL3 bit15 */
			{19295, 9,1}, /* core4 sp_EL3 bit16 */
			{19506, 9,1}, /* core4 sp_EL3 bit17 */
			{19303, 9,1}, /* core4 sp_EL3 bit18 */
			{19294, 9,1}, /* core4 sp_EL3 bit19 */
			{20155, 9,1}, /* core4 sp_EL3 bit20 */
			{20154, 9,1}, /* core4 sp_EL3 bit21 */
			{19760, 9,1}, /* core4 sp_EL3 bit22 */
			{20153, 9,1}, /* core4 sp_EL3 bit23 */
			{19759, 9,1}, /* core4 sp_EL3 bit24 */
			{19508, 9,1}, /* core4 sp_EL3 bit25 */
			{19507, 9,1}, /* core4 sp_EL3 bit26 */
			{19761, 9,1}, /* core4 sp_EL3 bit27 */
			{19504, 9,1}, /* core4 sp_EL3 bit28 */
			{19762, 9,1}, /* core4 sp_EL3 bit29 */
			{19293, 9,1}, /* core4 sp_EL3 bit30 */
			{19763, 9,1}, /* core4 sp_EL3 bit31 */
			{20744, 9,1}, /* core4 sp_EL3 bit32 */
			{24301, 9,1}, /* core4 sp_EL3 bit33 */
			{20747, 9,1}, /* core4 sp_EL3 bit34 */
			{20864, 9,1}, /* core4 sp_EL3 bit35 */
			{20745, 9,1}, /* core4 sp_EL3 bit36 */
			{20866, 9,1}, /* core4 sp_EL3 bit37 */
			{20742, 9,1}, /* core4 sp_EL3 bit38 */
			{20863, 9,1}, /* core4 sp_EL3 bit39 */
			{20748, 9,1}, /* core4 sp_EL3 bit40 */
			{20741, 9,1}, /* core4 sp_EL3 bit41 */
			{20746, 9,1}, /* core4 sp_EL3 bit42 */
			{20865, 9,1}, /* core4 sp_EL3 bit43 */
			{20743, 9,1}, /* core4 sp_EL3 bit44 */
			{21041, 9,1}, /* core4 sp_EL3 bit45 */
			{20867, 9,1}, /* core4 sp_EL3 bit46 */
			{21042, 9,1}, /* core4 sp_EL3 bit47 */
			{24300, 9,1}, /* core4 sp_EL3 bit48 */
			{22509, 8,1}, /* core4 sp_EL3 bit49 */
			{22508, 8,1}, /* core4 sp_EL3 bit50 */
			{22507, 8,1}, /* core4 sp_EL3 bit51 */
			{22506, 8,1}, /* core4 sp_EL3 bit52 */
			{22337, 8,1}, /* core4 sp_EL3 bit53 */
			{22336, 8,1}, /* core4 sp_EL3 bit54 */
			{22335, 8,1}, /* core4 sp_EL3 bit55 */
			{22334, 8,1}, /* core4 sp_EL3 bit56 */
			{22277, 8,1}, /* core4 sp_EL3 bit57 */
			{22276, 8,1}, /* core4 sp_EL3 bit58 */
			{22275, 8,1}, /* core4 sp_EL3 bit59 */
			{22274, 8,1}, /* core4 sp_EL3 bit60 */
			{24303, 9,1}, /* core4 sp_EL3 bit61 */
			{24302, 9,1}, /* core4 sp_EL3 bit62 */
			{20868, 9,1}, /* core4 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{21357, 8,1}, /* core4 elr_EL1 bit0 */
			{21356, 8,1}, /* core4 elr_EL1 bit1 */
			{21355, 8,1}, /* core4 elr_EL1 bit2 */
			{21354, 8,1}, /* core4 elr_EL1 bit3 */
			{18607, 9,1}, /* core4 elr_EL1 bit4 */
			{18605, 9,1}, /* core4 elr_EL1 bit5 */
			{18662, 9,1}, /* core4 elr_EL1 bit6 */
			{18661, 9,1}, /* core4 elr_EL1 bit7 */
			{18821, 9,1}, /* core4 elr_EL1 bit8 */
			{18481, 9,1}, /* core4 elr_EL1 bit9 */
			{18820, 9,1}, /* core4 elr_EL1 bit10 */
			{18480, 9,1}, /* core4 elr_EL1 bit11 */
			{18606, 9,1}, /* core4 elr_EL1 bit12 */
			{18660, 9,1}, /* core4 elr_EL1 bit13 */
			{18659, 9,1}, /* core4 elr_EL1 bit14 */
			{18658, 9,1}, /* core4 elr_EL1 bit15 */
			{19354, 9,1}, /* core4 elr_EL1 bit16 */
			{19609, 9,1}, /* core4 elr_EL1 bit17 */
			{19610, 9,1}, /* core4 elr_EL1 bit18 */
			{19355, 9,1}, /* core4 elr_EL1 bit19 */
			{20099, 9,1}, /* core4 elr_EL1 bit20 */
			{20098, 9,1}, /* core4 elr_EL1 bit21 */
			{19840, 9,1}, /* core4 elr_EL1 bit22 */
			{20100, 9,1}, /* core4 elr_EL1 bit23 */
			{19837, 9,1}, /* core4 elr_EL1 bit24 */
			{19608, 9,1}, /* core4 elr_EL1 bit25 */
			{19758, 9,1}, /* core4 elr_EL1 bit26 */
			{19839, 9,1}, /* core4 elr_EL1 bit27 */
			{19757, 9,1}, /* core4 elr_EL1 bit28 */
			{19836, 9,1}, /* core4 elr_EL1 bit29 */
			{19356, 9,1}, /* core4 elr_EL1 bit30 */
			{19838, 9,1}, /* core4 elr_EL1 bit31 */
			{20762, 9,1}, /* core4 elr_EL1 bit32 */
			{24313, 9,1}, /* core4 elr_EL1 bit33 */
			{20759, 9,1}, /* core4 elr_EL1 bit34 */
			{24312, 9,1}, /* core4 elr_EL1 bit35 */
			{20859, 9,1}, /* core4 elr_EL1 bit36 */
			{20881, 9,1}, /* core4 elr_EL1 bit37 */
			{20763, 9,1}, /* core4 elr_EL1 bit38 */
			{20880, 9,1}, /* core4 elr_EL1 bit39 */
			{20760, 9,1}, /* core4 elr_EL1 bit40 */
			{20574, 9,1}, /* core4 elr_EL1 bit41 */
			{20764, 9,1}, /* core4 elr_EL1 bit42 */
			{20882, 9,1}, /* core4 elr_EL1 bit43 */
			{20761, 9,1}, /* core4 elr_EL1 bit44 */
			{20573, 9,1}, /* core4 elr_EL1 bit45 */
			{21037, 9,1}, /* core4 elr_EL1 bit46 */
			{21036, 9,1}, /* core4 elr_EL1 bit47 */
			{24307, 9,1}, /* core4 elr_EL1 bit48 */
			{22513, 8,1}, /* core4 elr_EL1 bit49 */
			{22512, 8,1}, /* core4 elr_EL1 bit50 */
			{22511, 8,1}, /* core4 elr_EL1 bit51 */
			{22510, 8,1}, /* core4 elr_EL1 bit52 */
			{22429, 8,1}, /* core4 elr_EL1 bit53 */
			{22428, 8,1}, /* core4 elr_EL1 bit54 */
			{22427, 8,1}, /* core4 elr_EL1 bit55 */
			{22426, 8,1}, /* core4 elr_EL1 bit56 */
			{22517, 8,1}, /* core4 elr_EL1 bit57 */
			{22516, 8,1}, /* core4 elr_EL1 bit58 */
			{22515, 8,1}, /* core4 elr_EL1 bit59 */
			{22514, 8,1}, /* core4 elr_EL1 bit60 */
			{24306, 9,1}, /* core4 elr_EL1 bit61 */
			{24305, 9,1}, /* core4 elr_EL1 bit62 */
			{24304, 9,1}, /* core4 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{21365, 8,1}, /* core4 elr_EL2 bit0 */
			{21364, 8,1}, /* core4 elr_EL2 bit1 */
			{21363, 8,1}, /* core4 elr_EL2 bit2 */
			{21362, 8,1}, /* core4 elr_EL2 bit3 */
			{18673, 9,1}, /* core4 elr_EL2 bit4 */
			{18672, 9,1}, /* core4 elr_EL2 bit5 */
			{18676, 9,1}, /* core4 elr_EL2 bit6 */
			{18834, 9,1}, /* core4 elr_EL2 bit7 */
			{18833, 9,1}, /* core4 elr_EL2 bit8 */
			{18674, 9,1}, /* core4 elr_EL2 bit9 */
			{18806, 9,1}, /* core4 elr_EL2 bit10 */
			{18675, 9,1}, /* core4 elr_EL2 bit11 */
			{18835, 9,1}, /* core4 elr_EL2 bit12 */
			{18671, 9,1}, /* core4 elr_EL2 bit13 */
			{18807, 9,1}, /* core4 elr_EL2 bit14 */
			{18832, 9,1}, /* core4 elr_EL2 bit15 */
			{19308, 9,1}, /* core4 elr_EL2 bit16 */
			{19307, 9,1}, /* core4 elr_EL2 bit17 */
			{19501, 9,1}, /* core4 elr_EL2 bit18 */
			{19500, 9,1}, /* core4 elr_EL2 bit19 */
			{19915, 9,1}, /* core4 elr_EL2 bit20 */
			{20156, 9,1}, /* core4 elr_EL2 bit21 */
			{19764, 9,1}, /* core4 elr_EL2 bit22 */
			{19917, 9,1}, /* core4 elr_EL2 bit23 */
			{19919, 9,1}, /* core4 elr_EL2 bit24 */
			{19503, 9,1}, /* core4 elr_EL2 bit25 */
			{19502, 9,1}, /* core4 elr_EL2 bit26 */
			{19920, 9,1}, /* core4 elr_EL2 bit27 */
			{19505, 9,1}, /* core4 elr_EL2 bit28 */
			{19918, 9,1}, /* core4 elr_EL2 bit29 */
			{19302, 9,1}, /* core4 elr_EL2 bit30 */
			{19916, 9,1}, /* core4 elr_EL2 bit31 */
			{20751, 9,1}, /* core4 elr_EL2 bit32 */
			{24311, 9,1}, /* core4 elr_EL2 bit33 */
			{20754, 9,1}, /* core4 elr_EL2 bit34 */
			{24310, 9,1}, /* core4 elr_EL2 bit35 */
			{20862, 9,1}, /* core4 elr_EL2 bit36 */
			{20879, 9,1}, /* core4 elr_EL2 bit37 */
			{20750, 9,1}, /* core4 elr_EL2 bit38 */
			{20861, 9,1}, /* core4 elr_EL2 bit39 */
			{20752, 9,1}, /* core4 elr_EL2 bit40 */
			{20755, 9,1}, /* core4 elr_EL2 bit41 */
			{20753, 9,1}, /* core4 elr_EL2 bit42 */
			{20860, 9,1}, /* core4 elr_EL2 bit43 */
			{20749, 9,1}, /* core4 elr_EL2 bit44 */
			{21040, 9,1}, /* core4 elr_EL2 bit45 */
			{21038, 9,1}, /* core4 elr_EL2 bit46 */
			{21039, 9,1}, /* core4 elr_EL2 bit47 */
			{22437, 8,1}, /* core4 elr_EL2 bit48 */
			{22436, 8,1}, /* core4 elr_EL2 bit49 */
			{22435, 8,1}, /* core4 elr_EL2 bit50 */
			{22434, 8,1}, /* core4 elr_EL2 bit51 */
			{22273, 8,1}, /* core4 elr_EL2 bit52 */
			{22272, 8,1}, /* core4 elr_EL2 bit53 */
			{22271, 8,1}, /* core4 elr_EL2 bit54 */
			{22270, 8,1}, /* core4 elr_EL2 bit55 */
			{22333, 8,1}, /* core4 elr_EL2 bit56 */
			{22332, 8,1}, /* core4 elr_EL2 bit57 */
			{22331, 8,1}, /* core4 elr_EL2 bit58 */
			{22330, 8,1}, /* core4 elr_EL2 bit59 */
			{22269, 8,1}, /* core4 elr_EL2 bit60 */
			{22268, 8,1}, /* core4 elr_EL2 bit61 */
			{22267, 8,1}, /* core4 elr_EL2 bit62 */
			{22266, 8,1}, /* core4 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{22077, 8,1}, /* core4 elr_EL3 bit0 */
			{22076, 8,1}, /* core4 elr_EL3 bit1 */
			{22075, 8,1}, /* core4 elr_EL3 bit2 */
			{22074, 8,1}, /* core4 elr_EL3 bit3 */
			{18592, 9,1}, /* core4 elr_EL3 bit4 */
			{18439, 9,1}, /* core4 elr_EL3 bit5 */
			{18780, 9,1}, /* core4 elr_EL3 bit6 */
			{18434, 9,1}, /* core4 elr_EL3 bit7 */
			{18432, 9,1}, /* core4 elr_EL3 bit8 */
			{18594, 9,1}, /* core4 elr_EL3 bit9 */
			{18431, 9,1}, /* core4 elr_EL3 bit10 */
			{18438, 9,1}, /* core4 elr_EL3 bit11 */
			{18433, 9,1}, /* core4 elr_EL3 bit12 */
			{18781, 9,1}, /* core4 elr_EL3 bit13 */
			{18593, 9,1}, /* core4 elr_EL3 bit14 */
			{18440, 9,1}, /* core4 elr_EL3 bit15 */
			{19567, 9,1}, /* core4 elr_EL3 bit16 */
			{19563, 9,1}, /* core4 elr_EL3 bit17 */
			{19568, 9,1}, /* core4 elr_EL3 bit18 */
			{19565, 9,1}, /* core4 elr_EL3 bit19 */
			{19727, 9,1}, /* core4 elr_EL3 bit20 */
			{20134, 9,1}, /* core4 elr_EL3 bit21 */
			{19824, 9,1}, /* core4 elr_EL3 bit22 */
			{19728, 9,1}, /* core4 elr_EL3 bit23 */
			{19823, 9,1}, /* core4 elr_EL3 bit24 */
			{19564, 9,1}, /* core4 elr_EL3 bit25 */
			{19388, 9,1}, /* core4 elr_EL3 bit26 */
			{19695, 9,1}, /* core4 elr_EL3 bit27 */
			{19566, 9,1}, /* core4 elr_EL3 bit28 */
			{19729, 9,1}, /* core4 elr_EL3 bit29 */
			{19389, 9,1}, /* core4 elr_EL3 bit30 */
			{19694, 9,1}, /* core4 elr_EL3 bit31 */
			{24597, 9,1}, /* core4 elr_EL3 bit32 */
			{23029, 8,1}, /* core4 elr_EL3 bit33 */
			{24596, 9,1}, /* core4 elr_EL3 bit34 */
			{24599, 9,1}, /* core4 elr_EL3 bit35 */
			{21544, 9,1}, /* core4 elr_EL3 bit36 */
			{21543, 9,1}, /* core4 elr_EL3 bit37 */
			{21550, 9,1}, /* core4 elr_EL3 bit38 */
			{21558, 9,1}, /* core4 elr_EL3 bit39 */
			{24598, 9,1}, /* core4 elr_EL3 bit40 */
			{21545, 9,1}, /* core4 elr_EL3 bit41 */
			{21559, 9,1}, /* core4 elr_EL3 bit42 */
			{21552, 9,1}, /* core4 elr_EL3 bit43 */
			{21551, 9,1}, /* core4 elr_EL3 bit44 */
			{21241, 9,1}, /* core4 elr_EL3 bit45 */
			{21242, 9,1}, /* core4 elr_EL3 bit46 */
			{23028, 8,1}, /* core4 elr_EL3 bit47 */
			{23027, 8,1}, /* core4 elr_EL3 bit48 */
			{23026, 8,1}, /* core4 elr_EL3 bit49 */
			{23033, 8,1}, /* core4 elr_EL3 bit50 */
			{23032, 8,1}, /* core4 elr_EL3 bit51 */
			{23031, 8,1}, /* core4 elr_EL3 bit52 */
			{23030, 8,1}, /* core4 elr_EL3 bit53 */
			{22897, 8,1}, /* core4 elr_EL3 bit54 */
			{22896, 8,1}, /* core4 elr_EL3 bit55 */
			{22895, 8,1}, /* core4 elr_EL3 bit56 */
			{22894, 8,1}, /* core4 elr_EL3 bit57 */
			{22893, 8,1}, /* core4 elr_EL3 bit58 */
			{22892, 8,1}, /* core4 elr_EL3 bit59 */
			{22891, 8,1}, /* core4 elr_EL3 bit60 */
			{22890, 8,1}, /* core4 elr_EL3 bit61 */
			{24595, 9,1}, /* core4 elr_EL3 bit62 */
			{24594, 9,1}, /* core4 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{19459, 9,1}, /* core4 raw_pc bit0 */
			{19462, 9,1}, /* core4 raw_pc bit1 */
			{19463, 9,1}, /* core4 raw_pc bit2 */
			{19461, 9,1}, /* core4 raw_pc bit3 */
			{19460, 9,1}, /* core4 raw_pc bit4 */
			{19686, 9,1}, /* core4 raw_pc bit5 */
			{19411, 9,1}, /* core4 raw_pc bit6 */
			{18020, 9,1}, /* core4 raw_pc bit7 */
			{19145, 8,1}, /* core4 raw_pc bit8 */
			{19144, 8,1}, /* core4 raw_pc bit9 */
			{19143, 8,1}, /* core4 raw_pc bit10 */
			{19142, 8,1}, /* core4 raw_pc bit11 */
			{18957, 8,1}, /* core4 raw_pc bit12 */
			{18956, 8,1}, /* core4 raw_pc bit13 */
			{18955, 8,1}, /* core4 raw_pc bit14 */
			{17855, 9,1}, /* core4 raw_pc bit15 */
			{17853, 9,1}, /* core4 raw_pc bit16 */
			{23935, 9,1}, /* core4 raw_pc bit17 */
			{23934, 9,1}, /* core4 raw_pc bit18 */
			{18019, 9,1}, /* core4 raw_pc bit19 */
			{18017, 9,1}, /* core4 raw_pc bit20 */
			{18954, 8,1}, /* core4 raw_pc bit21 */
			{18018, 9,1}, /* core4 raw_pc bit22 */
			{17854, 9,1}, /* core4 raw_pc bit23 */
			{23931, 9,1}, /* core4 raw_pc bit24 */
			{17857, 9,1}, /* core4 raw_pc bit25 */
			{17856, 9,1}, /* core4 raw_pc bit26 */
			{23930, 9,1}, /* core4 raw_pc bit27 */
			{23933, 9,1}, /* core4 raw_pc bit28 */
			{23932, 9,1}, /* core4 raw_pc bit29 */
			{17858, 9,1}, /* core4 raw_pc bit30 */
			{18301, 8,1}, /* core4 raw_pc bit31 */
			{17644, 9,1}, /* core4 raw_pc bit32 */
			{18300, 8,1}, /* core4 raw_pc bit33 */
			{18299, 8,1}, /* core4 raw_pc bit34 */
			{18298, 8,1}, /* core4 raw_pc bit35 */
			{18297, 8,1}, /* core4 raw_pc bit36 */
			{18296, 8,1}, /* core4 raw_pc bit37 */
			{18295, 8,1}, /* core4 raw_pc bit38 */
			{18294, 8,1}, /* core4 raw_pc bit39 */
			{18293, 8,1}, /* core4 raw_pc bit40 */
			{18292, 8,1}, /* core4 raw_pc bit41 */
			{18291, 8,1}, /* core4 raw_pc bit42 */
			{18290, 8,1}, /* core4 raw_pc bit43 */
			{23723, 9,1}, /* core4 raw_pc bit44 */
			{23722, 9,1}, /* core4 raw_pc bit45 */
			{17642, 9,1}, /* core4 raw_pc bit46 */
			{17643, 9,1}, /* core4 raw_pc bit47 */
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
			{19178, 9,1}, /* core4 pc_iss bit0 */
			{19183, 9,1}, /* core4 pc_iss bit1 */
			{19181, 9,1}, /* core4 pc_iss bit2 */
			{19177, 9,1}, /* core4 pc_iss bit3 */
			{19176, 9,1}, /* core4 pc_iss bit4 */
			{19185, 9,1}, /* core4 pc_iss bit5 */
			{19184, 9,1}, /* core4 pc_iss bit6 */
			{19186, 9,1}, /* core4 pc_iss bit7 */
			{18373, 9,1}, /* core4 pc_iss bit8 */
			{18374, 9,1}, /* core4 pc_iss bit9 */
			{18378, 9,1}, /* core4 pc_iss bit10 */
			{18375, 9,1}, /* core4 pc_iss bit11 */
			{18370, 9,1}, /* core4 pc_iss bit12 */
			{18371, 9,1}, /* core4 pc_iss bit13 */
			{18376, 9,1}, /* core4 pc_iss bit14 */
			{18189, 9,1}, /* core4 pc_iss bit15 */
			{18162, 9,1}, /* core4 pc_iss bit16 */
			{18368, 9,1}, /* core4 pc_iss bit17 */
			{18150, 9,1}, /* core4 pc_iss bit18 */
			{18366, 9,1}, /* core4 pc_iss bit19 */
			{18367, 9,1}, /* core4 pc_iss bit20 */
			{18369, 9,1}, /* core4 pc_iss bit21 */
			{18188, 9,1}, /* core4 pc_iss bit22 */
			{18152, 9,1}, /* core4 pc_iss bit23 */
			{18379, 9,1}, /* core4 pc_iss bit24 */
			{18153, 9,1}, /* core4 pc_iss bit25 */
			{18191, 9,1}, /* core4 pc_iss bit26 */
			{18151, 9,1}, /* core4 pc_iss bit27 */
			{18372, 9,1}, /* core4 pc_iss bit28 */
			{18190, 9,1}, /* core4 pc_iss bit29 */
			{18161, 9,1}, /* core4 pc_iss bit30 */
			{17979, 9,1}, /* core4 pc_iss bit31 */
			{18022, 9,1}, /* core4 pc_iss bit32 */
			{18021, 9,1}, /* core4 pc_iss bit33 */
			{17838, 9,1}, /* core4 pc_iss bit34 */
			{17848, 9,1}, /* core4 pc_iss bit35 */
			{17837, 9,1}, /* core4 pc_iss bit36 */
			{17847, 9,1}, /* core4 pc_iss bit37 */
			{17849, 9,1}, /* core4 pc_iss bit38 */
			{17842, 9,1}, /* core4 pc_iss bit39 */
			{17840, 9,1}, /* core4 pc_iss bit40 */
			{17850, 9,1}, /* core4 pc_iss bit41 */
			{17846, 9,1}, /* core4 pc_iss bit42 */
			{17843, 9,1}, /* core4 pc_iss bit43 */
			{17844, 9,1}, /* core4 pc_iss bit44 */
			{17841, 9,1}, /* core4 pc_iss bit45 */
			{17845, 9,1}, /* core4 pc_iss bit46 */
			{17839, 9,1}, /* core4 pc_iss bit47 */
			{18441, 8,1}, /* core4 pc_iss bit48 */
			{18440, 8,1}, /* core4 pc_iss bit49 */
			{18439, 8,1}, /* core4 pc_iss bit50 */
			{18438, 8,1}, /* core4 pc_iss bit51 */
			{18281, 8,1}, /* core4 pc_iss bit52 */
			{18280, 8,1}, /* core4 pc_iss bit53 */
			{18279, 8,1}, /* core4 pc_iss bit54 */
			{18278, 8,1}, /* core4 pc_iss bit55 */
			{18289, 8,1}, /* core4 pc_iss bit56 */
			{18288, 8,1}, /* core4 pc_iss bit57 */
			{18287, 8,1}, /* core4 pc_iss bit58 */
			{18286, 8,1}, /* core4 pc_iss bit59 */
			{18285, 8,1}, /* core4 pc_iss bit60 */
			{18284, 8,1}, /* core4 pc_iss bit61 */
			{18283, 8,1}, /* core4 pc_iss bit62 */
			{18282, 8,1}, /* core4 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{19685, 9,1}, /* core4 full_pc_wr bit0 */
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
			{20035, 9,1}, /* core4 full_pc_ex1 bit0 */
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
			{20029, 9,1}, /* core4 full_pc_ex2 bit0 */
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
			.spmc_power_state = {{
			{16025,23,0}, /* core5 spmc_power_state bit0 */
			{15578,21,1}, /* core5 spmc_power_state bit1 */
			{15577,21,1}, /* core5 spmc_power_state bit2 */
			{15554,21,1}, /* core5 spmc_power_state bit3 */
			{15553,21,1}, /* core5 spmc_power_state bit4 */
			{16021,23,0}, /* core5 spmc_power_state bit5 */
			{    0, 0,2}, /* core5 spmc_power_state bit6 */
			{    0, 0,2}, /* core5 spmc_power_state bit7 */
			{    0, 0,2}, /* core5 spmc_power_state bit8 */
			{    0, 0,2}, /* core5 spmc_power_state bit9 */
			{    0, 0,2}, /* core5 spmc_power_state bit10 */
			{    0, 0,2}, /* core5 spmc_power_state bit11 */
			{    0, 0,2}, /* core5 spmc_power_state bit12 */
			{    0, 0,2}, /* core5 spmc_power_state bit13 */
			{    0, 0,2}, /* core5 spmc_power_state bit14 */
			{    0, 0,2}, /* core5 spmc_power_state bit15 */
			{    0, 0,2}, /* core5 spmc_power_state bit16 */
			{    0, 0,2}, /* core5 spmc_power_state bit17 */
			{    0, 0,2}, /* core5 spmc_power_state bit18 */
			{    0, 0,2}, /* core5 spmc_power_state bit19 */
			{    0, 0,2}, /* core5 spmc_power_state bit20 */
			{    0, 0,2}, /* core5 spmc_power_state bit21 */
			{    0, 0,2}, /* core5 spmc_power_state bit22 */
			{    0, 0,2}, /* core5 spmc_power_state bit23 */
			{    0, 0,2}, /* core5 spmc_power_state bit24 */
			{    0, 0,2}, /* core5 spmc_power_state bit25 */
			{    0, 0,2}, /* core5 spmc_power_state bit26 */
			{    0, 0,2}, /* core5 spmc_power_state bit27 */
			{    0, 0,2}, /* core5 spmc_power_state bit28 */
			{    0, 0,2}, /* core5 spmc_power_state bit29 */
			{    0, 0,2}, /* core5 spmc_power_state bit30 */
			{    0, 0,2}, /* core5 spmc_power_state bit31 */
			{    0, 0,2}, /* core5 spmc_power_state bit32 */
			{    0, 0,2}, /* core5 spmc_power_state bit33 */
			{    0, 0,2}, /* core5 spmc_power_state bit34 */
			{    0, 0,2}, /* core5 spmc_power_state bit35 */
			{    0, 0,2}, /* core5 spmc_power_state bit36 */
			{    0, 0,2}, /* core5 spmc_power_state bit37 */
			{    0, 0,2}, /* core5 spmc_power_state bit38 */
			{    0, 0,2}, /* core5 spmc_power_state bit39 */
			{    0, 0,2}, /* core5 spmc_power_state bit40 */
			{    0, 0,2}, /* core5 spmc_power_state bit41 */
			{    0, 0,2}, /* core5 spmc_power_state bit42 */
			{    0, 0,2}, /* core5 spmc_power_state bit43 */
			{    0, 0,2}, /* core5 spmc_power_state bit44 */
			{    0, 0,2}, /* core5 spmc_power_state bit45 */
			{    0, 0,2}, /* core5 spmc_power_state bit46 */
			{    0, 0,2}, /* core5 spmc_power_state bit47 */
			{    0, 0,2}, /* core5 spmc_power_state bit48 */
			{    0, 0,2}, /* core5 spmc_power_state bit49 */
			{    0, 0,2}, /* core5 spmc_power_state bit50 */
			{    0, 0,2}, /* core5 spmc_power_state bit51 */
			{    0, 0,2}, /* core5 spmc_power_state bit52 */
			{    0, 0,2}, /* core5 spmc_power_state bit53 */
			{    0, 0,2}, /* core5 spmc_power_state bit54 */
			{    0, 0,2}, /* core5 spmc_power_state bit55 */
			{    0, 0,2}, /* core5 spmc_power_state bit56 */
			{    0, 0,2}, /* core5 spmc_power_state bit57 */
			{    0, 0,2}, /* core5 spmc_power_state bit58 */
			{    0, 0,2}, /* core5 spmc_power_state bit59 */
			{    0, 0,2}, /* core5 spmc_power_state bit60 */
			{    0, 0,2}, /* core5 spmc_power_state bit61 */
			{    0, 0,2}, /* core5 spmc_power_state bit62 */
			{    0, 0,2}, /* core5 spmc_power_state bit63 */
			}},
			.pc = {{
			{13357,10,1}, /* core5 pc bit0 */
			{13356,10,1}, /* core5 pc bit1 */
			{13355,10,1}, /* core5 pc bit2 */
			{13354,10,1}, /* core5 pc bit3 */
			{13497,10,1}, /* core5 pc bit4 */
			{13496,10,1}, /* core5 pc bit5 */
			{13495,10,1}, /* core5 pc bit6 */
			{13494,10,1}, /* core5 pc bit7 */
			{13709,10,1}, /* core5 pc bit8 */
			{13708,10,1}, /* core5 pc bit9 */
			{13707,10,1}, /* core5 pc bit10 */
			{13706,10,1}, /* core5 pc bit11 */
			{13309,10,1}, /* core5 pc bit12 */
			{13308,10,1}, /* core5 pc bit13 */
			{13307,10,1}, /* core5 pc bit14 */
			{13306,10,1}, /* core5 pc bit15 */
			{12965,10,1}, /* core5 pc bit16 */
			{12964,10,1}, /* core5 pc bit17 */
			{12963,10,1}, /* core5 pc bit18 */
			{12962,10,1}, /* core5 pc bit19 */
			{13149,10,1}, /* core5 pc bit20 */
			{13148,10,1}, /* core5 pc bit21 */
			{13147,10,1}, /* core5 pc bit22 */
			{13146,10,1}, /* core5 pc bit23 */
			{13313,10,1}, /* core5 pc bit24 */
			{13312,10,1}, /* core5 pc bit25 */
			{13311,10,1}, /* core5 pc bit26 */
			{13310,10,1}, /* core5 pc bit27 */
			{13689,10,1}, /* core5 pc bit28 */
			{13688,10,1}, /* core5 pc bit29 */
			{13687,10,1}, /* core5 pc bit30 */
			{13686,10,1}, /* core5 pc bit31 */
			{13525,10,1}, /* core5 pc bit32 */
			{13524,10,1}, /* core5 pc bit33 */
			{13523,10,1}, /* core5 pc bit34 */
			{13522,10,1}, /* core5 pc bit35 */
			{13325,10,1}, /* core5 pc bit36 */
			{13324,10,1}, /* core5 pc bit37 */
			{13323,10,1}, /* core5 pc bit38 */
			{13322,10,1}, /* core5 pc bit39 */
			{13521,10,1}, /* core5 pc bit40 */
			{13520,10,1}, /* core5 pc bit41 */
			{13519,10,1}, /* core5 pc bit42 */
			{13518,10,1}, /* core5 pc bit43 */
			{13157,10,1}, /* core5 pc bit44 */
			{13156,10,1}, /* core5 pc bit45 */
			{13155,10,1}, /* core5 pc bit46 */
			{13154,10,1}, /* core5 pc bit47 */
			{12981,10,1}, /* core5 pc bit48 */
			{12980,10,1}, /* core5 pc bit49 */
			{12979,10,1}, /* core5 pc bit50 */
			{12978,10,1}, /* core5 pc bit51 */
			{12997,10,1}, /* core5 pc bit52 */
			{12996,10,1}, /* core5 pc bit53 */
			{12995,10,1}, /* core5 pc bit54 */
			{12994,10,1}, /* core5 pc bit55 */
			{12973,10,1}, /* core5 pc bit56 */
			{12972,10,1}, /* core5 pc bit57 */
			{12971,10,1}, /* core5 pc bit58 */
			{12970,10,1}, /* core5 pc bit59 */
			{13529,10,1}, /* core5 pc bit60 */
			{13528,10,1}, /* core5 pc bit61 */
			{13527,10,1}, /* core5 pc bit62 */
			{13526,10,1}, /* core5 pc bit63 */
			}},
			.sp32 = {{
			{21453,10,1}, /* core5 sp32 bit0 */
			{21452,10,1}, /* core5 sp32 bit1 */
			{21451,10,1}, /* core5 sp32 bit2 */
			{21450,10,1}, /* core5 sp32 bit3 */
			{18933,11,1}, /* core5 sp32 bit4 */
			{18916,11,1}, /* core5 sp32 bit5 */
			{18931,11,1}, /* core5 sp32 bit6 */
			{18915,11,1}, /* core5 sp32 bit7 */
			{18935,11,1}, /* core5 sp32 bit8 */
			{18930,11,1}, /* core5 sp32 bit9 */
			{18934,11,1}, /* core5 sp32 bit10 */
			{18917,11,1}, /* core5 sp32 bit11 */
			{18932,11,1}, /* core5 sp32 bit12 */
			{18918,11,1}, /* core5 sp32 bit13 */
			{19085,11,1}, /* core5 sp32 bit14 */
			{19087,11,1}, /* core5 sp32 bit15 */
			{19316,11,1}, /* core5 sp32 bit16 */
			{19317,11,1}, /* core5 sp32 bit17 */
			{19315,11,1}, /* core5 sp32 bit18 */
			{19320,11,1}, /* core5 sp32 bit19 */
			{19620,11,1}, /* core5 sp32 bit20 */
			{19489,11,1}, /* core5 sp32 bit21 */
			{20067,11,1}, /* core5 sp32 bit22 */
			{20068,11,1}, /* core5 sp32 bit23 */
			{19911,11,1}, /* core5 sp32 bit24 */
			{19318,11,1}, /* core5 sp32 bit25 */
			{19319,11,1}, /* core5 sp32 bit26 */
			{19615,11,1}, /* core5 sp32 bit27 */
			{19487,11,1}, /* core5 sp32 bit28 */
			{19488,11,1}, /* core5 sp32 bit29 */
			{19321,11,1}, /* core5 sp32 bit30 */
			{19947,11,1}, /* core5 sp32 bit31 */
			{21259,11,1}, /* core5 sp32 bit32 */
			{24269,11,1}, /* core5 sp32 bit33 */
			{24268,11,1}, /* core5 sp32 bit34 */
			{20735,11,1}, /* core5 sp32 bit35 */
			{21222,11,1}, /* core5 sp32 bit36 */
			{21221,11,1}, /* core5 sp32 bit37 */
			{20734,11,1}, /* core5 sp32 bit38 */
			{24271,11,1}, /* core5 sp32 bit39 */
			{21064,11,1}, /* core5 sp32 bit40 */
			{21257,11,1}, /* core5 sp32 bit41 */
			{21220,11,1}, /* core5 sp32 bit42 */
			{21219,11,1}, /* core5 sp32 bit43 */
			{21256,11,1}, /* core5 sp32 bit44 */
			{20892,11,1}, /* core5 sp32 bit45 */
			{21258,11,1}, /* core5 sp32 bit46 */
			{24270,11,1}, /* core5 sp32 bit47 */
			{22709,10,1}, /* core5 sp32 bit48 */
			{22708,10,1}, /* core5 sp32 bit49 */
			{22707,10,1}, /* core5 sp32 bit50 */
			{22706,10,1}, /* core5 sp32 bit51 */
			{22357,10,1}, /* core5 sp32 bit52 */
			{24257,11,1}, /* core5 sp32 bit53 */
			{22356,10,1}, /* core5 sp32 bit54 */
			{22355,10,1}, /* core5 sp32 bit55 */
			{22354,10,1}, /* core5 sp32 bit56 */
			{22425,10,1}, /* core5 sp32 bit57 */
			{22424,10,1}, /* core5 sp32 bit58 */
			{22423,10,1}, /* core5 sp32 bit59 */
			{22422,10,1}, /* core5 sp32 bit60 */
			{24256,11,1}, /* core5 sp32 bit61 */
			{24259,11,1}, /* core5 sp32 bit62 */
			{24258,11,1}, /* core5 sp32 bit63 */
			}},
			.fp32 = {{
			{21521,10,1}, /* core5 fp32 bit0 */
			{21520,10,1}, /* core5 fp32 bit1 */
			{21519,10,1}, /* core5 fp32 bit2 */
			{21518,10,1}, /* core5 fp32 bit3 */
			{18466,11,1}, /* core5 fp32 bit4 */
			{18286,11,1}, /* core5 fp32 bit5 */
			{18285,11,1}, /* core5 fp32 bit6 */
			{18287,11,1}, /* core5 fp32 bit7 */
			{18461,11,1}, /* core5 fp32 bit8 */
			{18465,11,1}, /* core5 fp32 bit9 */
			{18284,11,1}, /* core5 fp32 bit10 */
			{18467,11,1}, /* core5 fp32 bit11 */
			{18463,11,1}, /* core5 fp32 bit12 */
			{18462,11,1}, /* core5 fp32 bit13 */
			{18468,11,1}, /* core5 fp32 bit14 */
			{18464,11,1}, /* core5 fp32 bit15 */
			{19113,11,1}, /* core5 fp32 bit16 */
			{19112,11,1}, /* core5 fp32 bit17 */
			{19116,11,1}, /* core5 fp32 bit18 */
			{19115,11,1}, /* core5 fp32 bit19 */
			{20145,11,1}, /* core5 fp32 bit20 */
			{19119,11,1}, /* core5 fp32 bit21 */
			{19368,11,1}, /* core5 fp32 bit22 */
			{19369,11,1}, /* core5 fp32 bit23 */
			{19371,11,1}, /* core5 fp32 bit24 */
			{19878,11,1}, /* core5 fp32 bit25 */
			{19117,11,1}, /* core5 fp32 bit26 */
			{19370,11,1}, /* core5 fp32 bit27 */
			{19114,11,1}, /* core5 fp32 bit28 */
			{19118,11,1}, /* core5 fp32 bit29 */
			{19372,11,1}, /* core5 fp32 bit30 */
			{19877,11,1}, /* core5 fp32 bit31 */
			{22070,11,1}, /* core5 fp32 bit32 */
			{24617,11,1}, /* core5 fp32 bit33 */
			{22069,11,1}, /* core5 fp32 bit34 */
			{22072,11,1}, /* core5 fp32 bit35 */
			{22039,11,1}, /* core5 fp32 bit36 */
			{22044,11,1}, /* core5 fp32 bit37 */
			{22074,11,1}, /* core5 fp32 bit38 */
			{22067,11,1}, /* core5 fp32 bit39 */
			{22073,11,1}, /* core5 fp32 bit40 */
			{21851,11,1}, /* core5 fp32 bit41 */
			{22075,11,1}, /* core5 fp32 bit42 */
			{21852,11,1}, /* core5 fp32 bit43 */
			{22071,11,1}, /* core5 fp32 bit44 */
			{22038,11,1}, /* core5 fp32 bit45 */
			{22068,11,1}, /* core5 fp32 bit46 */
			{24616,11,1}, /* core5 fp32 bit47 */
			{23597,10,1}, /* core5 fp32 bit48 */
			{23596,10,1}, /* core5 fp32 bit49 */
			{23595,10,1}, /* core5 fp32 bit50 */
			{23594,10,1}, /* core5 fp32 bit51 */
			{23585,10,1}, /* core5 fp32 bit52 */
			{23584,10,1}, /* core5 fp32 bit53 */
			{23583,10,1}, /* core5 fp32 bit54 */
			{23582,10,1}, /* core5 fp32 bit55 */
			{23589,10,1}, /* core5 fp32 bit56 */
			{23588,10,1}, /* core5 fp32 bit57 */
			{23587,10,1}, /* core5 fp32 bit58 */
			{23586,10,1}, /* core5 fp32 bit59 */
			{23593,10,1}, /* core5 fp32 bit60 */
			{23592,10,1}, /* core5 fp32 bit61 */
			{23591,10,1}, /* core5 fp32 bit62 */
			{23590,10,1}, /* core5 fp32 bit63 */
			}},
			.fp64 = {{
			{21449,10,1}, /* core5 fp64 bit0 */
			{21448,10,1}, /* core5 fp64 bit1 */
			{21447,10,1}, /* core5 fp64 bit2 */
			{21446,10,1}, /* core5 fp64 bit3 */
			{18920,11,1}, /* core5 fp64 bit4 */
			{19090,11,1}, /* core5 fp64 bit5 */
			{19065,11,1}, /* core5 fp64 bit6 */
			{19088,11,1}, /* core5 fp64 bit7 */
			{18922,11,1}, /* core5 fp64 bit8 */
			{18928,11,1}, /* core5 fp64 bit9 */
			{18919,11,1}, /* core5 fp64 bit10 */
			{18929,11,1}, /* core5 fp64 bit11 */
			{18921,11,1}, /* core5 fp64 bit12 */
			{18923,11,1}, /* core5 fp64 bit13 */
			{19064,11,1}, /* core5 fp64 bit14 */
			{19066,11,1}, /* core5 fp64 bit15 */
			{19322,11,1}, /* core5 fp64 bit16 */
			{19485,11,1}, /* core5 fp64 bit17 */
			{19482,11,1}, /* core5 fp64 bit18 */
			{19483,11,1}, /* core5 fp64 bit19 */
			{20163,11,1}, /* core5 fp64 bit20 */
			{19906,11,1}, /* core5 fp64 bit21 */
			{19904,11,1}, /* core5 fp64 bit22 */
			{19905,11,1}, /* core5 fp64 bit23 */
			{19907,11,1}, /* core5 fp64 bit24 */
			{19484,11,1}, /* core5 fp64 bit25 */
			{19486,11,1}, /* core5 fp64 bit26 */
			{19910,11,1}, /* core5 fp64 bit27 */
			{19481,11,1}, /* core5 fp64 bit28 */
			{19909,11,1}, /* core5 fp64 bit29 */
			{19323,11,1}, /* core5 fp64 bit30 */
			{19908,11,1}, /* core5 fp64 bit31 */
			{20417,11,1}, /* core5 fp64 bit32 */
			{20381,11,1}, /* core5 fp64 bit33 */
			{20375,11,1}, /* core5 fp64 bit34 */
			{20176,11,1}, /* core5 fp64 bit35 */
			{20416,11,1}, /* core5 fp64 bit36 */
			{20171,11,1}, /* core5 fp64 bit37 */
			{20379,11,1}, /* core5 fp64 bit38 */
			{20374,11,1}, /* core5 fp64 bit39 */
			{20373,11,1}, /* core5 fp64 bit40 */
			{20170,11,1}, /* core5 fp64 bit41 */
			{20377,11,1}, /* core5 fp64 bit42 */
			{20378,11,1}, /* core5 fp64 bit43 */
			{20376,11,1}, /* core5 fp64 bit44 */
			{20174,11,1}, /* core5 fp64 bit45 */
			{20175,11,1}, /* core5 fp64 bit46 */
			{20418,11,1}, /* core5 fp64 bit47 */
			{20562,11,1}, /* core5 fp64 bit48 */
			{24281,11,1}, /* core5 fp64 bit49 */
			{24280,11,1}, /* core5 fp64 bit50 */
			{20560,11,1}, /* core5 fp64 bit51 */
			{20564,11,1}, /* core5 fp64 bit52 */
			{20566,11,1}, /* core5 fp64 bit53 */
			{20565,11,1}, /* core5 fp64 bit54 */
			{20561,11,1}, /* core5 fp64 bit55 */
			{20563,11,1}, /* core5 fp64 bit56 */
			{20380,11,1}, /* core5 fp64 bit57 */
			{20372,11,1}, /* core5 fp64 bit58 */
			{20172,11,1}, /* core5 fp64 bit59 */
			{21549,10,1}, /* core5 fp64 bit60 */
			{21548,10,1}, /* core5 fp64 bit61 */
			{21547,10,1}, /* core5 fp64 bit62 */
			{21546,10,1}, /* core5 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{21625,10,1}, /* core5 sp_EL0 bit0 */
			{21624,10,1}, /* core5 sp_EL0 bit1 */
			{21623,10,1}, /* core5 sp_EL0 bit2 */
			{21622,10,1}, /* core5 sp_EL0 bit3 */
			{18483,11,1}, /* core5 sp_EL0 bit4 */
			{18614,11,1}, /* core5 sp_EL0 bit5 */
			{18612,11,1}, /* core5 sp_EL0 bit6 */
			{18486,11,1}, /* core5 sp_EL0 bit7 */
			{18824,11,1}, /* core5 sp_EL0 bit8 */
			{18664,11,1}, /* core5 sp_EL0 bit9 */
			{18823,11,1}, /* core5 sp_EL0 bit10 */
			{18482,11,1}, /* core5 sp_EL0 bit11 */
			{18613,11,1}, /* core5 sp_EL0 bit12 */
			{18663,11,1}, /* core5 sp_EL0 bit13 */
			{18615,11,1}, /* core5 sp_EL0 bit14 */
			{18822,11,1}, /* core5 sp_EL0 bit15 */
			{19289,11,1}, /* core5 sp_EL0 bit16 */
			{19351,11,1}, /* core5 sp_EL0 bit17 */
			{19353,11,1}, /* core5 sp_EL0 bit18 */
			{19350,11,1}, /* core5 sp_EL0 bit19 */
			{19749,11,1}, /* core5 sp_EL0 bit20 */
			{20136,11,1}, /* core5 sp_EL0 bit21 */
			{19748,11,1}, /* core5 sp_EL0 bit22 */
			{20135,11,1}, /* core5 sp_EL0 bit23 */
			{19900,11,1}, /* core5 sp_EL0 bit24 */
			{19288,11,1}, /* core5 sp_EL0 bit25 */
			{19290,11,1}, /* core5 sp_EL0 bit26 */
			{19750,11,1}, /* core5 sp_EL0 bit27 */
			{19515,11,1}, /* core5 sp_EL0 bit28 */
			{19514,11,1}, /* core5 sp_EL0 bit29 */
			{19352,11,1}, /* core5 sp_EL0 bit30 */
			{19901,11,1}, /* core5 sp_EL0 bit31 */
			{20581,11,1}, /* core5 sp_EL0 bit32 */
			{24277,11,1}, /* core5 sp_EL0 bit33 */
			{20368,11,1}, /* core5 sp_EL0 bit34 */
			{20419,11,1}, /* core5 sp_EL0 bit35 */
			{20424,11,1}, /* core5 sp_EL0 bit36 */
			{20421,11,1}, /* core5 sp_EL0 bit37 */
			{20580,11,1}, /* core5 sp_EL0 bit38 */
			{20770,11,1}, /* core5 sp_EL0 bit39 */
			{20423,11,1}, /* core5 sp_EL0 bit40 */
			{20369,11,1}, /* core5 sp_EL0 bit41 */
			{20582,11,1}, /* core5 sp_EL0 bit42 */
			{20370,11,1}, /* core5 sp_EL0 bit43 */
			{20420,11,1}, /* core5 sp_EL0 bit44 */
			{20583,11,1}, /* core5 sp_EL0 bit45 */
			{20367,11,1}, /* core5 sp_EL0 bit46 */
			{20422,11,1}, /* core5 sp_EL0 bit47 */
			{24276,11,1}, /* core5 sp_EL0 bit48 */
			{22133,10,1}, /* core5 sp_EL0 bit49 */
			{22132,10,1}, /* core5 sp_EL0 bit50 */
			{22131,10,1}, /* core5 sp_EL0 bit51 */
			{22130,10,1}, /* core5 sp_EL0 bit52 */
			{22137,10,1}, /* core5 sp_EL0 bit53 */
			{22136,10,1}, /* core5 sp_EL0 bit54 */
			{22135,10,1}, /* core5 sp_EL0 bit55 */
			{22134,10,1}, /* core5 sp_EL0 bit56 */
			{21805,10,1}, /* core5 sp_EL0 bit57 */
			{21804,10,1}, /* core5 sp_EL0 bit58 */
			{21803,10,1}, /* core5 sp_EL0 bit59 */
			{21802,10,1}, /* core5 sp_EL0 bit60 */
			{24279,11,1}, /* core5 sp_EL0 bit61 */
			{24278,11,1}, /* core5 sp_EL0 bit62 */
			{20371,11,1}, /* core5 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{21457,10,1}, /* core5 sp_EL1 bit0 */
			{21456,10,1}, /* core5 sp_EL1 bit1 */
			{21455,10,1}, /* core5 sp_EL1 bit2 */
			{21454,10,1}, /* core5 sp_EL1 bit3 */
			{18836,11,1}, /* core5 sp_EL1 bit4 */
			{18679,11,1}, /* core5 sp_EL1 bit5 */
			{18840,11,1}, /* core5 sp_EL1 bit6 */
			{18837,11,1}, /* core5 sp_EL1 bit7 */
			{18841,11,1}, /* core5 sp_EL1 bit8 */
			{18881,11,1}, /* core5 sp_EL1 bit9 */
			{18677,11,1}, /* core5 sp_EL1 bit10 */
			{18678,11,1}, /* core5 sp_EL1 bit11 */
			{18842,11,1}, /* core5 sp_EL1 bit12 */
			{18839,11,1}, /* core5 sp_EL1 bit13 */
			{18838,11,1}, /* core5 sp_EL1 bit14 */
			{19086,11,1}, /* core5 sp_EL1 bit15 */
			{19314,11,1}, /* core5 sp_EL1 bit16 */
			{19491,11,1}, /* core5 sp_EL1 bit17 */
			{19311,11,1}, /* core5 sp_EL1 bit18 */
			{19312,11,1}, /* core5 sp_EL1 bit19 */
			{20069,11,1}, /* core5 sp_EL1 bit20 */
			{19765,11,1}, /* core5 sp_EL1 bit21 */
			{19611,11,1}, /* core5 sp_EL1 bit22 */
			{19912,11,1}, /* core5 sp_EL1 bit23 */
			{19766,11,1}, /* core5 sp_EL1 bit24 */
			{19492,11,1}, /* core5 sp_EL1 bit25 */
			{19493,11,1}, /* core5 sp_EL1 bit26 */
			{19614,11,1}, /* core5 sp_EL1 bit27 */
			{19490,11,1}, /* core5 sp_EL1 bit28 */
			{19613,11,1}, /* core5 sp_EL1 bit29 */
			{19310,11,1}, /* core5 sp_EL1 bit30 */
			{19612,11,1}, /* core5 sp_EL1 bit31 */
			{20570,11,1}, /* core5 sp_EL1 bit32 */
			{20568,11,1}, /* core5 sp_EL1 bit33 */
			{20412,11,1}, /* core5 sp_EL1 bit34 */
			{20408,11,1}, /* core5 sp_EL1 bit35 */
			{20404,11,1}, /* core5 sp_EL1 bit36 */
			{20403,11,1}, /* core5 sp_EL1 bit37 */
			{20558,11,1}, /* core5 sp_EL1 bit38 */
			{20410,11,1}, /* core5 sp_EL1 bit39 */
			{20406,11,1}, /* core5 sp_EL1 bit40 */
			{20571,11,1}, /* core5 sp_EL1 bit41 */
			{20409,11,1}, /* core5 sp_EL1 bit42 */
			{20402,11,1}, /* core5 sp_EL1 bit43 */
			{20405,11,1}, /* core5 sp_EL1 bit44 */
			{20572,11,1}, /* core5 sp_EL1 bit45 */
			{20414,11,1}, /* core5 sp_EL1 bit46 */
			{20413,11,1}, /* core5 sp_EL1 bit47 */
			{20557,11,1}, /* core5 sp_EL1 bit48 */
			{24297,11,1}, /* core5 sp_EL1 bit49 */
			{20567,11,1}, /* core5 sp_EL1 bit50 */
			{21797,10,1}, /* core5 sp_EL1 bit51 */
			{20569,11,1}, /* core5 sp_EL1 bit52 */
			{20407,11,1}, /* core5 sp_EL1 bit53 */
			{24296,11,1}, /* core5 sp_EL1 bit54 */
			{21796,10,1}, /* core5 sp_EL1 bit55 */
			{20559,11,1}, /* core5 sp_EL1 bit56 */
			{21795,10,1}, /* core5 sp_EL1 bit57 */
			{20411,11,1}, /* core5 sp_EL1 bit58 */
			{24293,11,1}, /* core5 sp_EL1 bit59 */
			{21794,10,1}, /* core5 sp_EL1 bit60 */
			{24292,11,1}, /* core5 sp_EL1 bit61 */
			{24295,11,1}, /* core5 sp_EL1 bit62 */
			{24294,11,1}, /* core5 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{21361,10,1}, /* core5 sp_EL2 bit0 */
			{21360,10,1}, /* core5 sp_EL2 bit1 */
			{21359,10,1}, /* core5 sp_EL2 bit2 */
			{21358,10,1}, /* core5 sp_EL2 bit3 */
			{18669,11,1}, /* core5 sp_EL2 bit4 */
			{18670,11,1}, /* core5 sp_EL2 bit5 */
			{18619,11,1}, /* core5 sp_EL2 bit6 */
			{18830,11,1}, /* core5 sp_EL2 bit7 */
			{18827,11,1}, /* core5 sp_EL2 bit8 */
			{18618,11,1}, /* core5 sp_EL2 bit9 */
			{18829,11,1}, /* core5 sp_EL2 bit10 */
			{18667,11,1}, /* core5 sp_EL2 bit11 */
			{18620,11,1}, /* core5 sp_EL2 bit12 */
			{18668,11,1}, /* core5 sp_EL2 bit13 */
			{18828,11,1}, /* core5 sp_EL2 bit14 */
			{18831,11,1}, /* core5 sp_EL2 bit15 */
			{19347,11,1}, /* core5 sp_EL2 bit16 */
			{19345,11,1}, /* core5 sp_EL2 bit17 */
			{19509,11,1}, /* core5 sp_EL2 bit18 */
			{19511,11,1}, /* core5 sp_EL2 bit19 */
			{19934,11,1}, /* core5 sp_EL2 bit20 */
			{20143,11,1}, /* core5 sp_EL2 bit21 */
			{19927,11,1}, /* core5 sp_EL2 bit22 */
			{20142,11,1}, /* core5 sp_EL2 bit23 */
			{19933,11,1}, /* core5 sp_EL2 bit24 */
			{19512,11,1}, /* core5 sp_EL2 bit25 */
			{19348,11,1}, /* core5 sp_EL2 bit26 */
			{19638,11,1}, /* core5 sp_EL2 bit27 */
			{19510,11,1}, /* core5 sp_EL2 bit28 */
			{19932,11,1}, /* core5 sp_EL2 bit29 */
			{19346,11,1}, /* core5 sp_EL2 bit30 */
			{19928,11,1}, /* core5 sp_EL2 bit31 */
			{20876,11,1}, /* core5 sp_EL2 bit32 */
			{24309,11,1}, /* core5 sp_EL2 bit33 */
			{20872,11,1}, /* core5 sp_EL2 bit34 */
			{20869,11,1}, /* core5 sp_EL2 bit35 */
			{20874,11,1}, /* core5 sp_EL2 bit36 */
			{20873,11,1}, /* core5 sp_EL2 bit37 */
			{20877,11,1}, /* core5 sp_EL2 bit38 */
			{20870,11,1}, /* core5 sp_EL2 bit39 */
			{20738,11,1}, /* core5 sp_EL2 bit40 */
			{20875,11,1}, /* core5 sp_EL2 bit41 */
			{20740,11,1}, /* core5 sp_EL2 bit42 */
			{20878,11,1}, /* core5 sp_EL2 bit43 */
			{20871,11,1}, /* core5 sp_EL2 bit44 */
			{21045,11,1}, /* core5 sp_EL2 bit45 */
			{24308,11,1}, /* core5 sp_EL2 bit46 */
			{21044,11,1}, /* core5 sp_EL2 bit47 */
			{22433,10,1}, /* core5 sp_EL2 bit48 */
			{22432,10,1}, /* core5 sp_EL2 bit49 */
			{22431,10,1}, /* core5 sp_EL2 bit50 */
			{22430,10,1}, /* core5 sp_EL2 bit51 */
			{22685,10,1}, /* core5 sp_EL2 bit52 */
			{22684,10,1}, /* core5 sp_EL2 bit53 */
			{22683,10,1}, /* core5 sp_EL2 bit54 */
			{22682,10,1}, /* core5 sp_EL2 bit55 */
			{22261,10,1}, /* core5 sp_EL2 bit56 */
			{22260,10,1}, /* core5 sp_EL2 bit57 */
			{22259,10,1}, /* core5 sp_EL2 bit58 */
			{22258,10,1}, /* core5 sp_EL2 bit59 */
			{22265,10,1}, /* core5 sp_EL2 bit60 */
			{22264,10,1}, /* core5 sp_EL2 bit61 */
			{22263,10,1}, /* core5 sp_EL2 bit62 */
			{22262,10,1}, /* core5 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{21617,10,1}, /* core5 sp_EL3 bit0 */
			{21616,10,1}, /* core5 sp_EL3 bit1 */
			{21615,10,1}, /* core5 sp_EL3 bit2 */
			{21614,10,1}, /* core5 sp_EL3 bit3 */
			{18625,11,1}, /* core5 sp_EL3 bit4 */
			{18622,11,1}, /* core5 sp_EL3 bit5 */
			{18623,11,1}, /* core5 sp_EL3 bit6 */
			{18813,11,1}, /* core5 sp_EL3 bit7 */
			{18796,11,1}, /* core5 sp_EL3 bit8 */
			{18797,11,1}, /* core5 sp_EL3 bit9 */
			{18812,11,1}, /* core5 sp_EL3 bit10 */
			{18621,11,1}, /* core5 sp_EL3 bit11 */
			{18795,11,1}, /* core5 sp_EL3 bit12 */
			{18624,11,1}, /* core5 sp_EL3 bit13 */
			{18961,11,1}, /* core5 sp_EL3 bit14 */
			{18798,11,1}, /* core5 sp_EL3 bit15 */
			{19295,11,1}, /* core5 sp_EL3 bit16 */
			{19506,11,1}, /* core5 sp_EL3 bit17 */
			{19303,11,1}, /* core5 sp_EL3 bit18 */
			{19294,11,1}, /* core5 sp_EL3 bit19 */
			{20155,11,1}, /* core5 sp_EL3 bit20 */
			{20154,11,1}, /* core5 sp_EL3 bit21 */
			{19760,11,1}, /* core5 sp_EL3 bit22 */
			{20153,11,1}, /* core5 sp_EL3 bit23 */
			{19759,11,1}, /* core5 sp_EL3 bit24 */
			{19508,11,1}, /* core5 sp_EL3 bit25 */
			{19507,11,1}, /* core5 sp_EL3 bit26 */
			{19761,11,1}, /* core5 sp_EL3 bit27 */
			{19504,11,1}, /* core5 sp_EL3 bit28 */
			{19762,11,1}, /* core5 sp_EL3 bit29 */
			{19293,11,1}, /* core5 sp_EL3 bit30 */
			{19763,11,1}, /* core5 sp_EL3 bit31 */
			{20744,11,1}, /* core5 sp_EL3 bit32 */
			{24301,11,1}, /* core5 sp_EL3 bit33 */
			{20747,11,1}, /* core5 sp_EL3 bit34 */
			{20864,11,1}, /* core5 sp_EL3 bit35 */
			{20745,11,1}, /* core5 sp_EL3 bit36 */
			{20866,11,1}, /* core5 sp_EL3 bit37 */
			{20742,11,1}, /* core5 sp_EL3 bit38 */
			{20863,11,1}, /* core5 sp_EL3 bit39 */
			{20748,11,1}, /* core5 sp_EL3 bit40 */
			{20741,11,1}, /* core5 sp_EL3 bit41 */
			{20746,11,1}, /* core5 sp_EL3 bit42 */
			{20865,11,1}, /* core5 sp_EL3 bit43 */
			{20743,11,1}, /* core5 sp_EL3 bit44 */
			{21041,11,1}, /* core5 sp_EL3 bit45 */
			{20867,11,1}, /* core5 sp_EL3 bit46 */
			{21042,11,1}, /* core5 sp_EL3 bit47 */
			{24300,11,1}, /* core5 sp_EL3 bit48 */
			{22509,10,1}, /* core5 sp_EL3 bit49 */
			{22508,10,1}, /* core5 sp_EL3 bit50 */
			{22507,10,1}, /* core5 sp_EL3 bit51 */
			{22506,10,1}, /* core5 sp_EL3 bit52 */
			{22337,10,1}, /* core5 sp_EL3 bit53 */
			{22336,10,1}, /* core5 sp_EL3 bit54 */
			{22335,10,1}, /* core5 sp_EL3 bit55 */
			{22334,10,1}, /* core5 sp_EL3 bit56 */
			{22277,10,1}, /* core5 sp_EL3 bit57 */
			{22276,10,1}, /* core5 sp_EL3 bit58 */
			{22275,10,1}, /* core5 sp_EL3 bit59 */
			{22274,10,1}, /* core5 sp_EL3 bit60 */
			{24303,11,1}, /* core5 sp_EL3 bit61 */
			{24302,11,1}, /* core5 sp_EL3 bit62 */
			{20868,11,1}, /* core5 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{21357,10,1}, /* core5 elr_EL1 bit0 */
			{21356,10,1}, /* core5 elr_EL1 bit1 */
			{21355,10,1}, /* core5 elr_EL1 bit2 */
			{21354,10,1}, /* core5 elr_EL1 bit3 */
			{18607,11,1}, /* core5 elr_EL1 bit4 */
			{18605,11,1}, /* core5 elr_EL1 bit5 */
			{18662,11,1}, /* core5 elr_EL1 bit6 */
			{18661,11,1}, /* core5 elr_EL1 bit7 */
			{18821,11,1}, /* core5 elr_EL1 bit8 */
			{18481,11,1}, /* core5 elr_EL1 bit9 */
			{18820,11,1}, /* core5 elr_EL1 bit10 */
			{18480,11,1}, /* core5 elr_EL1 bit11 */
			{18606,11,1}, /* core5 elr_EL1 bit12 */
			{18660,11,1}, /* core5 elr_EL1 bit13 */
			{18659,11,1}, /* core5 elr_EL1 bit14 */
			{18658,11,1}, /* core5 elr_EL1 bit15 */
			{19354,11,1}, /* core5 elr_EL1 bit16 */
			{19609,11,1}, /* core5 elr_EL1 bit17 */
			{19610,11,1}, /* core5 elr_EL1 bit18 */
			{19355,11,1}, /* core5 elr_EL1 bit19 */
			{20099,11,1}, /* core5 elr_EL1 bit20 */
			{20098,11,1}, /* core5 elr_EL1 bit21 */
			{19840,11,1}, /* core5 elr_EL1 bit22 */
			{20100,11,1}, /* core5 elr_EL1 bit23 */
			{19837,11,1}, /* core5 elr_EL1 bit24 */
			{19608,11,1}, /* core5 elr_EL1 bit25 */
			{19758,11,1}, /* core5 elr_EL1 bit26 */
			{19839,11,1}, /* core5 elr_EL1 bit27 */
			{19757,11,1}, /* core5 elr_EL1 bit28 */
			{19836,11,1}, /* core5 elr_EL1 bit29 */
			{19356,11,1}, /* core5 elr_EL1 bit30 */
			{19838,11,1}, /* core5 elr_EL1 bit31 */
			{20762,11,1}, /* core5 elr_EL1 bit32 */
			{24313,11,1}, /* core5 elr_EL1 bit33 */
			{20759,11,1}, /* core5 elr_EL1 bit34 */
			{24312,11,1}, /* core5 elr_EL1 bit35 */
			{20859,11,1}, /* core5 elr_EL1 bit36 */
			{20881,11,1}, /* core5 elr_EL1 bit37 */
			{20763,11,1}, /* core5 elr_EL1 bit38 */
			{20880,11,1}, /* core5 elr_EL1 bit39 */
			{20760,11,1}, /* core5 elr_EL1 bit40 */
			{20574,11,1}, /* core5 elr_EL1 bit41 */
			{20764,11,1}, /* core5 elr_EL1 bit42 */
			{20882,11,1}, /* core5 elr_EL1 bit43 */
			{20761,11,1}, /* core5 elr_EL1 bit44 */
			{20573,11,1}, /* core5 elr_EL1 bit45 */
			{21037,11,1}, /* core5 elr_EL1 bit46 */
			{21036,11,1}, /* core5 elr_EL1 bit47 */
			{24307,11,1}, /* core5 elr_EL1 bit48 */
			{22513,10,1}, /* core5 elr_EL1 bit49 */
			{22512,10,1}, /* core5 elr_EL1 bit50 */
			{22511,10,1}, /* core5 elr_EL1 bit51 */
			{22510,10,1}, /* core5 elr_EL1 bit52 */
			{22429,10,1}, /* core5 elr_EL1 bit53 */
			{22428,10,1}, /* core5 elr_EL1 bit54 */
			{22427,10,1}, /* core5 elr_EL1 bit55 */
			{22426,10,1}, /* core5 elr_EL1 bit56 */
			{22517,10,1}, /* core5 elr_EL1 bit57 */
			{22516,10,1}, /* core5 elr_EL1 bit58 */
			{22515,10,1}, /* core5 elr_EL1 bit59 */
			{22514,10,1}, /* core5 elr_EL1 bit60 */
			{24306,11,1}, /* core5 elr_EL1 bit61 */
			{24305,11,1}, /* core5 elr_EL1 bit62 */
			{24304,11,1}, /* core5 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{21365,10,1}, /* core5 elr_EL2 bit0 */
			{21364,10,1}, /* core5 elr_EL2 bit1 */
			{21363,10,1}, /* core5 elr_EL2 bit2 */
			{21362,10,1}, /* core5 elr_EL2 bit3 */
			{18673,11,1}, /* core5 elr_EL2 bit4 */
			{18672,11,1}, /* core5 elr_EL2 bit5 */
			{18676,11,1}, /* core5 elr_EL2 bit6 */
			{18834,11,1}, /* core5 elr_EL2 bit7 */
			{18833,11,1}, /* core5 elr_EL2 bit8 */
			{18674,11,1}, /* core5 elr_EL2 bit9 */
			{18806,11,1}, /* core5 elr_EL2 bit10 */
			{18675,11,1}, /* core5 elr_EL2 bit11 */
			{18835,11,1}, /* core5 elr_EL2 bit12 */
			{18671,11,1}, /* core5 elr_EL2 bit13 */
			{18807,11,1}, /* core5 elr_EL2 bit14 */
			{18832,11,1}, /* core5 elr_EL2 bit15 */
			{19308,11,1}, /* core5 elr_EL2 bit16 */
			{19307,11,1}, /* core5 elr_EL2 bit17 */
			{19501,11,1}, /* core5 elr_EL2 bit18 */
			{19500,11,1}, /* core5 elr_EL2 bit19 */
			{19915,11,1}, /* core5 elr_EL2 bit20 */
			{20156,11,1}, /* core5 elr_EL2 bit21 */
			{19764,11,1}, /* core5 elr_EL2 bit22 */
			{19917,11,1}, /* core5 elr_EL2 bit23 */
			{19919,11,1}, /* core5 elr_EL2 bit24 */
			{19503,11,1}, /* core5 elr_EL2 bit25 */
			{19502,11,1}, /* core5 elr_EL2 bit26 */
			{19920,11,1}, /* core5 elr_EL2 bit27 */
			{19505,11,1}, /* core5 elr_EL2 bit28 */
			{19918,11,1}, /* core5 elr_EL2 bit29 */
			{19302,11,1}, /* core5 elr_EL2 bit30 */
			{19916,11,1}, /* core5 elr_EL2 bit31 */
			{20751,11,1}, /* core5 elr_EL2 bit32 */
			{24311,11,1}, /* core5 elr_EL2 bit33 */
			{20754,11,1}, /* core5 elr_EL2 bit34 */
			{24310,11,1}, /* core5 elr_EL2 bit35 */
			{20862,11,1}, /* core5 elr_EL2 bit36 */
			{20879,11,1}, /* core5 elr_EL2 bit37 */
			{20750,11,1}, /* core5 elr_EL2 bit38 */
			{20861,11,1}, /* core5 elr_EL2 bit39 */
			{20752,11,1}, /* core5 elr_EL2 bit40 */
			{20755,11,1}, /* core5 elr_EL2 bit41 */
			{20753,11,1}, /* core5 elr_EL2 bit42 */
			{20860,11,1}, /* core5 elr_EL2 bit43 */
			{20749,11,1}, /* core5 elr_EL2 bit44 */
			{21040,11,1}, /* core5 elr_EL2 bit45 */
			{21038,11,1}, /* core5 elr_EL2 bit46 */
			{21039,11,1}, /* core5 elr_EL2 bit47 */
			{22437,10,1}, /* core5 elr_EL2 bit48 */
			{22436,10,1}, /* core5 elr_EL2 bit49 */
			{22435,10,1}, /* core5 elr_EL2 bit50 */
			{22434,10,1}, /* core5 elr_EL2 bit51 */
			{22273,10,1}, /* core5 elr_EL2 bit52 */
			{22272,10,1}, /* core5 elr_EL2 bit53 */
			{22271,10,1}, /* core5 elr_EL2 bit54 */
			{22270,10,1}, /* core5 elr_EL2 bit55 */
			{22333,10,1}, /* core5 elr_EL2 bit56 */
			{22332,10,1}, /* core5 elr_EL2 bit57 */
			{22331,10,1}, /* core5 elr_EL2 bit58 */
			{22330,10,1}, /* core5 elr_EL2 bit59 */
			{22269,10,1}, /* core5 elr_EL2 bit60 */
			{22268,10,1}, /* core5 elr_EL2 bit61 */
			{22267,10,1}, /* core5 elr_EL2 bit62 */
			{22266,10,1}, /* core5 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{22077,10,1}, /* core5 elr_EL3 bit0 */
			{22076,10,1}, /* core5 elr_EL3 bit1 */
			{22075,10,1}, /* core5 elr_EL3 bit2 */
			{22074,10,1}, /* core5 elr_EL3 bit3 */
			{18592,11,1}, /* core5 elr_EL3 bit4 */
			{18439,11,1}, /* core5 elr_EL3 bit5 */
			{18780,11,1}, /* core5 elr_EL3 bit6 */
			{18434,11,1}, /* core5 elr_EL3 bit7 */
			{18432,11,1}, /* core5 elr_EL3 bit8 */
			{18594,11,1}, /* core5 elr_EL3 bit9 */
			{18431,11,1}, /* core5 elr_EL3 bit10 */
			{18438,11,1}, /* core5 elr_EL3 bit11 */
			{18433,11,1}, /* core5 elr_EL3 bit12 */
			{18781,11,1}, /* core5 elr_EL3 bit13 */
			{18593,11,1}, /* core5 elr_EL3 bit14 */
			{18440,11,1}, /* core5 elr_EL3 bit15 */
			{19567,11,1}, /* core5 elr_EL3 bit16 */
			{19563,11,1}, /* core5 elr_EL3 bit17 */
			{19568,11,1}, /* core5 elr_EL3 bit18 */
			{19565,11,1}, /* core5 elr_EL3 bit19 */
			{19727,11,1}, /* core5 elr_EL3 bit20 */
			{20134,11,1}, /* core5 elr_EL3 bit21 */
			{19824,11,1}, /* core5 elr_EL3 bit22 */
			{19728,11,1}, /* core5 elr_EL3 bit23 */
			{19823,11,1}, /* core5 elr_EL3 bit24 */
			{19564,11,1}, /* core5 elr_EL3 bit25 */
			{19388,11,1}, /* core5 elr_EL3 bit26 */
			{19695,11,1}, /* core5 elr_EL3 bit27 */
			{19566,11,1}, /* core5 elr_EL3 bit28 */
			{19729,11,1}, /* core5 elr_EL3 bit29 */
			{19389,11,1}, /* core5 elr_EL3 bit30 */
			{19694,11,1}, /* core5 elr_EL3 bit31 */
			{24597,11,1}, /* core5 elr_EL3 bit32 */
			{23029,10,1}, /* core5 elr_EL3 bit33 */
			{24596,11,1}, /* core5 elr_EL3 bit34 */
			{24599,11,1}, /* core5 elr_EL3 bit35 */
			{21544,11,1}, /* core5 elr_EL3 bit36 */
			{21543,11,1}, /* core5 elr_EL3 bit37 */
			{21550,11,1}, /* core5 elr_EL3 bit38 */
			{21558,11,1}, /* core5 elr_EL3 bit39 */
			{24598,11,1}, /* core5 elr_EL3 bit40 */
			{21545,11,1}, /* core5 elr_EL3 bit41 */
			{21559,11,1}, /* core5 elr_EL3 bit42 */
			{21552,11,1}, /* core5 elr_EL3 bit43 */
			{21551,11,1}, /* core5 elr_EL3 bit44 */
			{21241,11,1}, /* core5 elr_EL3 bit45 */
			{21242,11,1}, /* core5 elr_EL3 bit46 */
			{23028,10,1}, /* core5 elr_EL3 bit47 */
			{23027,10,1}, /* core5 elr_EL3 bit48 */
			{23026,10,1}, /* core5 elr_EL3 bit49 */
			{23033,10,1}, /* core5 elr_EL3 bit50 */
			{23032,10,1}, /* core5 elr_EL3 bit51 */
			{23031,10,1}, /* core5 elr_EL3 bit52 */
			{23030,10,1}, /* core5 elr_EL3 bit53 */
			{22897,10,1}, /* core5 elr_EL3 bit54 */
			{22896,10,1}, /* core5 elr_EL3 bit55 */
			{22895,10,1}, /* core5 elr_EL3 bit56 */
			{22894,10,1}, /* core5 elr_EL3 bit57 */
			{22893,10,1}, /* core5 elr_EL3 bit58 */
			{22892,10,1}, /* core5 elr_EL3 bit59 */
			{22891,10,1}, /* core5 elr_EL3 bit60 */
			{22890,10,1}, /* core5 elr_EL3 bit61 */
			{24595,11,1}, /* core5 elr_EL3 bit62 */
			{24594,11,1}, /* core5 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{19459,11,1}, /* core5 raw_pc bit0 */
			{19462,11,1}, /* core5 raw_pc bit1 */
			{19463,11,1}, /* core5 raw_pc bit2 */
			{19461,11,1}, /* core5 raw_pc bit3 */
			{19460,11,1}, /* core5 raw_pc bit4 */
			{19686,11,1}, /* core5 raw_pc bit5 */
			{19411,11,1}, /* core5 raw_pc bit6 */
			{18020,11,1}, /* core5 raw_pc bit7 */
			{19145,10,1}, /* core5 raw_pc bit8 */
			{19144,10,1}, /* core5 raw_pc bit9 */
			{19143,10,1}, /* core5 raw_pc bit10 */
			{19142,10,1}, /* core5 raw_pc bit11 */
			{18957,10,1}, /* core5 raw_pc bit12 */
			{18956,10,1}, /* core5 raw_pc bit13 */
			{18955,10,1}, /* core5 raw_pc bit14 */
			{17855,11,1}, /* core5 raw_pc bit15 */
			{17853,11,1}, /* core5 raw_pc bit16 */
			{23935,11,1}, /* core5 raw_pc bit17 */
			{23934,11,1}, /* core5 raw_pc bit18 */
			{18019,11,1}, /* core5 raw_pc bit19 */
			{18017,11,1}, /* core5 raw_pc bit20 */
			{18954,10,1}, /* core5 raw_pc bit21 */
			{18018,11,1}, /* core5 raw_pc bit22 */
			{17854,11,1}, /* core5 raw_pc bit23 */
			{23931,11,1}, /* core5 raw_pc bit24 */
			{17857,11,1}, /* core5 raw_pc bit25 */
			{17856,11,1}, /* core5 raw_pc bit26 */
			{23930,11,1}, /* core5 raw_pc bit27 */
			{23933,11,1}, /* core5 raw_pc bit28 */
			{23932,11,1}, /* core5 raw_pc bit29 */
			{17858,11,1}, /* core5 raw_pc bit30 */
			{18301,10,1}, /* core5 raw_pc bit31 */
			{17644,11,1}, /* core5 raw_pc bit32 */
			{18300,10,1}, /* core5 raw_pc bit33 */
			{18299,10,1}, /* core5 raw_pc bit34 */
			{18298,10,1}, /* core5 raw_pc bit35 */
			{18297,10,1}, /* core5 raw_pc bit36 */
			{18296,10,1}, /* core5 raw_pc bit37 */
			{18295,10,1}, /* core5 raw_pc bit38 */
			{18294,10,1}, /* core5 raw_pc bit39 */
			{18293,10,1}, /* core5 raw_pc bit40 */
			{18292,10,1}, /* core5 raw_pc bit41 */
			{18291,10,1}, /* core5 raw_pc bit42 */
			{18290,10,1}, /* core5 raw_pc bit43 */
			{23723,11,1}, /* core5 raw_pc bit44 */
			{23722,11,1}, /* core5 raw_pc bit45 */
			{17642,11,1}, /* core5 raw_pc bit46 */
			{17643,11,1}, /* core5 raw_pc bit47 */
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
			{19178,11,1}, /* core5 pc_iss bit0 */
			{19183,11,1}, /* core5 pc_iss bit1 */
			{19181,11,1}, /* core5 pc_iss bit2 */
			{19177,11,1}, /* core5 pc_iss bit3 */
			{19176,11,1}, /* core5 pc_iss bit4 */
			{19185,11,1}, /* core5 pc_iss bit5 */
			{19184,11,1}, /* core5 pc_iss bit6 */
			{19186,11,1}, /* core5 pc_iss bit7 */
			{18373,11,1}, /* core5 pc_iss bit8 */
			{18374,11,1}, /* core5 pc_iss bit9 */
			{18378,11,1}, /* core5 pc_iss bit10 */
			{18375,11,1}, /* core5 pc_iss bit11 */
			{18370,11,1}, /* core5 pc_iss bit12 */
			{18371,11,1}, /* core5 pc_iss bit13 */
			{18376,11,1}, /* core5 pc_iss bit14 */
			{18189,11,1}, /* core5 pc_iss bit15 */
			{18162,11,1}, /* core5 pc_iss bit16 */
			{18368,11,1}, /* core5 pc_iss bit17 */
			{18150,11,1}, /* core5 pc_iss bit18 */
			{18366,11,1}, /* core5 pc_iss bit19 */
			{18367,11,1}, /* core5 pc_iss bit20 */
			{18369,11,1}, /* core5 pc_iss bit21 */
			{18188,11,1}, /* core5 pc_iss bit22 */
			{18152,11,1}, /* core5 pc_iss bit23 */
			{18379,11,1}, /* core5 pc_iss bit24 */
			{18153,11,1}, /* core5 pc_iss bit25 */
			{18191,11,1}, /* core5 pc_iss bit26 */
			{18151,11,1}, /* core5 pc_iss bit27 */
			{18372,11,1}, /* core5 pc_iss bit28 */
			{18190,11,1}, /* core5 pc_iss bit29 */
			{18161,11,1}, /* core5 pc_iss bit30 */
			{17979,11,1}, /* core5 pc_iss bit31 */
			{18022,11,1}, /* core5 pc_iss bit32 */
			{18021,11,1}, /* core5 pc_iss bit33 */
			{17838,11,1}, /* core5 pc_iss bit34 */
			{17848,11,1}, /* core5 pc_iss bit35 */
			{17837,11,1}, /* core5 pc_iss bit36 */
			{17847,11,1}, /* core5 pc_iss bit37 */
			{17849,11,1}, /* core5 pc_iss bit38 */
			{17842,11,1}, /* core5 pc_iss bit39 */
			{17840,11,1}, /* core5 pc_iss bit40 */
			{17850,11,1}, /* core5 pc_iss bit41 */
			{17846,11,1}, /* core5 pc_iss bit42 */
			{17843,11,1}, /* core5 pc_iss bit43 */
			{17844,11,1}, /* core5 pc_iss bit44 */
			{17841,11,1}, /* core5 pc_iss bit45 */
			{17845,11,1}, /* core5 pc_iss bit46 */
			{17839,11,1}, /* core5 pc_iss bit47 */
			{18441,10,1}, /* core5 pc_iss bit48 */
			{18440,10,1}, /* core5 pc_iss bit49 */
			{18439,10,1}, /* core5 pc_iss bit50 */
			{18438,10,1}, /* core5 pc_iss bit51 */
			{18281,10,1}, /* core5 pc_iss bit52 */
			{18280,10,1}, /* core5 pc_iss bit53 */
			{18279,10,1}, /* core5 pc_iss bit54 */
			{18278,10,1}, /* core5 pc_iss bit55 */
			{18289,10,1}, /* core5 pc_iss bit56 */
			{18288,10,1}, /* core5 pc_iss bit57 */
			{18287,10,1}, /* core5 pc_iss bit58 */
			{18286,10,1}, /* core5 pc_iss bit59 */
			{18285,10,1}, /* core5 pc_iss bit60 */
			{18284,10,1}, /* core5 pc_iss bit61 */
			{18283,10,1}, /* core5 pc_iss bit62 */
			{18282,10,1}, /* core5 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{19685,11,1}, /* core5 full_pc_wr bit0 */
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
			{20035,11,1}, /* core5 full_pc_ex1 bit0 */
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
			{20029,11,1}, /* core5 full_pc_ex2 bit0 */
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
			.spmc_power_state = {{
			{16016,23,0}, /* core6 spmc_power_state bit0 */
			{15596,21,1}, /* core6 spmc_power_state bit1 */
			{15595,21,1}, /* core6 spmc_power_state bit2 */
			{15598,21,1}, /* core6 spmc_power_state bit3 */
			{15597,21,1}, /* core6 spmc_power_state bit4 */
			{16022,23,0}, /* core6 spmc_power_state bit5 */
			{    0, 0,2}, /* core6 spmc_power_state bit6 */
			{    0, 0,2}, /* core6 spmc_power_state bit7 */
			{    0, 0,2}, /* core6 spmc_power_state bit8 */
			{    0, 0,2}, /* core6 spmc_power_state bit9 */
			{    0, 0,2}, /* core6 spmc_power_state bit10 */
			{    0, 0,2}, /* core6 spmc_power_state bit11 */
			{    0, 0,2}, /* core6 spmc_power_state bit12 */
			{    0, 0,2}, /* core6 spmc_power_state bit13 */
			{    0, 0,2}, /* core6 spmc_power_state bit14 */
			{    0, 0,2}, /* core6 spmc_power_state bit15 */
			{    0, 0,2}, /* core6 spmc_power_state bit16 */
			{    0, 0,2}, /* core6 spmc_power_state bit17 */
			{    0, 0,2}, /* core6 spmc_power_state bit18 */
			{    0, 0,2}, /* core6 spmc_power_state bit19 */
			{    0, 0,2}, /* core6 spmc_power_state bit20 */
			{    0, 0,2}, /* core6 spmc_power_state bit21 */
			{    0, 0,2}, /* core6 spmc_power_state bit22 */
			{    0, 0,2}, /* core6 spmc_power_state bit23 */
			{    0, 0,2}, /* core6 spmc_power_state bit24 */
			{    0, 0,2}, /* core6 spmc_power_state bit25 */
			{    0, 0,2}, /* core6 spmc_power_state bit26 */
			{    0, 0,2}, /* core6 spmc_power_state bit27 */
			{    0, 0,2}, /* core6 spmc_power_state bit28 */
			{    0, 0,2}, /* core6 spmc_power_state bit29 */
			{    0, 0,2}, /* core6 spmc_power_state bit30 */
			{    0, 0,2}, /* core6 spmc_power_state bit31 */
			{    0, 0,2}, /* core6 spmc_power_state bit32 */
			{    0, 0,2}, /* core6 spmc_power_state bit33 */
			{    0, 0,2}, /* core6 spmc_power_state bit34 */
			{    0, 0,2}, /* core6 spmc_power_state bit35 */
			{    0, 0,2}, /* core6 spmc_power_state bit36 */
			{    0, 0,2}, /* core6 spmc_power_state bit37 */
			{    0, 0,2}, /* core6 spmc_power_state bit38 */
			{    0, 0,2}, /* core6 spmc_power_state bit39 */
			{    0, 0,2}, /* core6 spmc_power_state bit40 */
			{    0, 0,2}, /* core6 spmc_power_state bit41 */
			{    0, 0,2}, /* core6 spmc_power_state bit42 */
			{    0, 0,2}, /* core6 spmc_power_state bit43 */
			{    0, 0,2}, /* core6 spmc_power_state bit44 */
			{    0, 0,2}, /* core6 spmc_power_state bit45 */
			{    0, 0,2}, /* core6 spmc_power_state bit46 */
			{    0, 0,2}, /* core6 spmc_power_state bit47 */
			{    0, 0,2}, /* core6 spmc_power_state bit48 */
			{    0, 0,2}, /* core6 spmc_power_state bit49 */
			{    0, 0,2}, /* core6 spmc_power_state bit50 */
			{    0, 0,2}, /* core6 spmc_power_state bit51 */
			{    0, 0,2}, /* core6 spmc_power_state bit52 */
			{    0, 0,2}, /* core6 spmc_power_state bit53 */
			{    0, 0,2}, /* core6 spmc_power_state bit54 */
			{    0, 0,2}, /* core6 spmc_power_state bit55 */
			{    0, 0,2}, /* core6 spmc_power_state bit56 */
			{    0, 0,2}, /* core6 spmc_power_state bit57 */
			{    0, 0,2}, /* core6 spmc_power_state bit58 */
			{    0, 0,2}, /* core6 spmc_power_state bit59 */
			{    0, 0,2}, /* core6 spmc_power_state bit60 */
			{    0, 0,2}, /* core6 spmc_power_state bit61 */
			{    0, 0,2}, /* core6 spmc_power_state bit62 */
			{    0, 0,2}, /* core6 spmc_power_state bit63 */
			}},
			.pc = {{
			{13357,12,1}, /* core6 pc bit0 */
			{13356,12,1}, /* core6 pc bit1 */
			{13355,12,1}, /* core6 pc bit2 */
			{13354,12,1}, /* core6 pc bit3 */
			{13497,12,1}, /* core6 pc bit4 */
			{13496,12,1}, /* core6 pc bit5 */
			{13495,12,1}, /* core6 pc bit6 */
			{13494,12,1}, /* core6 pc bit7 */
			{13709,12,1}, /* core6 pc bit8 */
			{13708,12,1}, /* core6 pc bit9 */
			{13707,12,1}, /* core6 pc bit10 */
			{13706,12,1}, /* core6 pc bit11 */
			{13309,12,1}, /* core6 pc bit12 */
			{13308,12,1}, /* core6 pc bit13 */
			{13307,12,1}, /* core6 pc bit14 */
			{13306,12,1}, /* core6 pc bit15 */
			{12965,12,1}, /* core6 pc bit16 */
			{12964,12,1}, /* core6 pc bit17 */
			{12963,12,1}, /* core6 pc bit18 */
			{12962,12,1}, /* core6 pc bit19 */
			{13149,12,1}, /* core6 pc bit20 */
			{13148,12,1}, /* core6 pc bit21 */
			{13147,12,1}, /* core6 pc bit22 */
			{13146,12,1}, /* core6 pc bit23 */
			{13313,12,1}, /* core6 pc bit24 */
			{13312,12,1}, /* core6 pc bit25 */
			{13311,12,1}, /* core6 pc bit26 */
			{13310,12,1}, /* core6 pc bit27 */
			{13689,12,1}, /* core6 pc bit28 */
			{13688,12,1}, /* core6 pc bit29 */
			{13687,12,1}, /* core6 pc bit30 */
			{13686,12,1}, /* core6 pc bit31 */
			{13525,12,1}, /* core6 pc bit32 */
			{13524,12,1}, /* core6 pc bit33 */
			{13523,12,1}, /* core6 pc bit34 */
			{13522,12,1}, /* core6 pc bit35 */
			{13325,12,1}, /* core6 pc bit36 */
			{13324,12,1}, /* core6 pc bit37 */
			{13323,12,1}, /* core6 pc bit38 */
			{13322,12,1}, /* core6 pc bit39 */
			{13521,12,1}, /* core6 pc bit40 */
			{13520,12,1}, /* core6 pc bit41 */
			{13519,12,1}, /* core6 pc bit42 */
			{13518,12,1}, /* core6 pc bit43 */
			{13157,12,1}, /* core6 pc bit44 */
			{13156,12,1}, /* core6 pc bit45 */
			{13155,12,1}, /* core6 pc bit46 */
			{13154,12,1}, /* core6 pc bit47 */
			{12981,12,1}, /* core6 pc bit48 */
			{12980,12,1}, /* core6 pc bit49 */
			{12979,12,1}, /* core6 pc bit50 */
			{12978,12,1}, /* core6 pc bit51 */
			{12997,12,1}, /* core6 pc bit52 */
			{12996,12,1}, /* core6 pc bit53 */
			{12995,12,1}, /* core6 pc bit54 */
			{12994,12,1}, /* core6 pc bit55 */
			{12973,12,1}, /* core6 pc bit56 */
			{12972,12,1}, /* core6 pc bit57 */
			{12971,12,1}, /* core6 pc bit58 */
			{12970,12,1}, /* core6 pc bit59 */
			{13529,12,1}, /* core6 pc bit60 */
			{13528,12,1}, /* core6 pc bit61 */
			{13527,12,1}, /* core6 pc bit62 */
			{13526,12,1}, /* core6 pc bit63 */
			}},
			.sp32 = {{
			{21453,12,1}, /* core6 sp32 bit0 */
			{21452,12,1}, /* core6 sp32 bit1 */
			{21451,12,1}, /* core6 sp32 bit2 */
			{21450,12,1}, /* core6 sp32 bit3 */
			{18933,13,1}, /* core6 sp32 bit4 */
			{18916,13,1}, /* core6 sp32 bit5 */
			{18931,13,1}, /* core6 sp32 bit6 */
			{18915,13,1}, /* core6 sp32 bit7 */
			{18935,13,1}, /* core6 sp32 bit8 */
			{18930,13,1}, /* core6 sp32 bit9 */
			{18934,13,1}, /* core6 sp32 bit10 */
			{18917,13,1}, /* core6 sp32 bit11 */
			{18932,13,1}, /* core6 sp32 bit12 */
			{18918,13,1}, /* core6 sp32 bit13 */
			{19085,13,1}, /* core6 sp32 bit14 */
			{19087,13,1}, /* core6 sp32 bit15 */
			{19316,13,1}, /* core6 sp32 bit16 */
			{19317,13,1}, /* core6 sp32 bit17 */
			{19315,13,1}, /* core6 sp32 bit18 */
			{19320,13,1}, /* core6 sp32 bit19 */
			{19620,13,1}, /* core6 sp32 bit20 */
			{19489,13,1}, /* core6 sp32 bit21 */
			{20067,13,1}, /* core6 sp32 bit22 */
			{20068,13,1}, /* core6 sp32 bit23 */
			{19911,13,1}, /* core6 sp32 bit24 */
			{19318,13,1}, /* core6 sp32 bit25 */
			{19319,13,1}, /* core6 sp32 bit26 */
			{19615,13,1}, /* core6 sp32 bit27 */
			{19487,13,1}, /* core6 sp32 bit28 */
			{19488,13,1}, /* core6 sp32 bit29 */
			{19321,13,1}, /* core6 sp32 bit30 */
			{19947,13,1}, /* core6 sp32 bit31 */
			{21259,13,1}, /* core6 sp32 bit32 */
			{24269,13,1}, /* core6 sp32 bit33 */
			{24268,13,1}, /* core6 sp32 bit34 */
			{20735,13,1}, /* core6 sp32 bit35 */
			{21222,13,1}, /* core6 sp32 bit36 */
			{21221,13,1}, /* core6 sp32 bit37 */
			{20734,13,1}, /* core6 sp32 bit38 */
			{24271,13,1}, /* core6 sp32 bit39 */
			{21064,13,1}, /* core6 sp32 bit40 */
			{21257,13,1}, /* core6 sp32 bit41 */
			{21220,13,1}, /* core6 sp32 bit42 */
			{21219,13,1}, /* core6 sp32 bit43 */
			{21256,13,1}, /* core6 sp32 bit44 */
			{20892,13,1}, /* core6 sp32 bit45 */
			{21258,13,1}, /* core6 sp32 bit46 */
			{24270,13,1}, /* core6 sp32 bit47 */
			{22709,12,1}, /* core6 sp32 bit48 */
			{22708,12,1}, /* core6 sp32 bit49 */
			{22707,12,1}, /* core6 sp32 bit50 */
			{22706,12,1}, /* core6 sp32 bit51 */
			{22357,12,1}, /* core6 sp32 bit52 */
			{24257,13,1}, /* core6 sp32 bit53 */
			{22356,12,1}, /* core6 sp32 bit54 */
			{22355,12,1}, /* core6 sp32 bit55 */
			{22354,12,1}, /* core6 sp32 bit56 */
			{22425,12,1}, /* core6 sp32 bit57 */
			{22424,12,1}, /* core6 sp32 bit58 */
			{22423,12,1}, /* core6 sp32 bit59 */
			{22422,12,1}, /* core6 sp32 bit60 */
			{24256,13,1}, /* core6 sp32 bit61 */
			{24259,13,1}, /* core6 sp32 bit62 */
			{24258,13,1}, /* core6 sp32 bit63 */
			}},
			.fp32 = {{
			{21521,12,1}, /* core6 fp32 bit0 */
			{21520,12,1}, /* core6 fp32 bit1 */
			{21519,12,1}, /* core6 fp32 bit2 */
			{21518,12,1}, /* core6 fp32 bit3 */
			{18466,13,1}, /* core6 fp32 bit4 */
			{18286,13,1}, /* core6 fp32 bit5 */
			{18285,13,1}, /* core6 fp32 bit6 */
			{18287,13,1}, /* core6 fp32 bit7 */
			{18461,13,1}, /* core6 fp32 bit8 */
			{18465,13,1}, /* core6 fp32 bit9 */
			{18284,13,1}, /* core6 fp32 bit10 */
			{18467,13,1}, /* core6 fp32 bit11 */
			{18463,13,1}, /* core6 fp32 bit12 */
			{18462,13,1}, /* core6 fp32 bit13 */
			{18468,13,1}, /* core6 fp32 bit14 */
			{18464,13,1}, /* core6 fp32 bit15 */
			{19113,13,1}, /* core6 fp32 bit16 */
			{19112,13,1}, /* core6 fp32 bit17 */
			{19116,13,1}, /* core6 fp32 bit18 */
			{19115,13,1}, /* core6 fp32 bit19 */
			{20145,13,1}, /* core6 fp32 bit20 */
			{19119,13,1}, /* core6 fp32 bit21 */
			{19368,13,1}, /* core6 fp32 bit22 */
			{19369,13,1}, /* core6 fp32 bit23 */
			{19371,13,1}, /* core6 fp32 bit24 */
			{19878,13,1}, /* core6 fp32 bit25 */
			{19117,13,1}, /* core6 fp32 bit26 */
			{19370,13,1}, /* core6 fp32 bit27 */
			{19114,13,1}, /* core6 fp32 bit28 */
			{19118,13,1}, /* core6 fp32 bit29 */
			{19372,13,1}, /* core6 fp32 bit30 */
			{19877,13,1}, /* core6 fp32 bit31 */
			{22070,13,1}, /* core6 fp32 bit32 */
			{24617,13,1}, /* core6 fp32 bit33 */
			{22069,13,1}, /* core6 fp32 bit34 */
			{22072,13,1}, /* core6 fp32 bit35 */
			{22039,13,1}, /* core6 fp32 bit36 */
			{22044,13,1}, /* core6 fp32 bit37 */
			{22074,13,1}, /* core6 fp32 bit38 */
			{22067,13,1}, /* core6 fp32 bit39 */
			{22073,13,1}, /* core6 fp32 bit40 */
			{21851,13,1}, /* core6 fp32 bit41 */
			{22075,13,1}, /* core6 fp32 bit42 */
			{21852,13,1}, /* core6 fp32 bit43 */
			{22071,13,1}, /* core6 fp32 bit44 */
			{22038,13,1}, /* core6 fp32 bit45 */
			{22068,13,1}, /* core6 fp32 bit46 */
			{24616,13,1}, /* core6 fp32 bit47 */
			{23597,12,1}, /* core6 fp32 bit48 */
			{23596,12,1}, /* core6 fp32 bit49 */
			{23595,12,1}, /* core6 fp32 bit50 */
			{23594,12,1}, /* core6 fp32 bit51 */
			{23585,12,1}, /* core6 fp32 bit52 */
			{23584,12,1}, /* core6 fp32 bit53 */
			{23583,12,1}, /* core6 fp32 bit54 */
			{23582,12,1}, /* core6 fp32 bit55 */
			{23589,12,1}, /* core6 fp32 bit56 */
			{23588,12,1}, /* core6 fp32 bit57 */
			{23587,12,1}, /* core6 fp32 bit58 */
			{23586,12,1}, /* core6 fp32 bit59 */
			{23593,12,1}, /* core6 fp32 bit60 */
			{23592,12,1}, /* core6 fp32 bit61 */
			{23591,12,1}, /* core6 fp32 bit62 */
			{23590,12,1}, /* core6 fp32 bit63 */
			}},
			.fp64 = {{
			{21449,12,1}, /* core6 fp64 bit0 */
			{21448,12,1}, /* core6 fp64 bit1 */
			{21447,12,1}, /* core6 fp64 bit2 */
			{21446,12,1}, /* core6 fp64 bit3 */
			{18920,13,1}, /* core6 fp64 bit4 */
			{19090,13,1}, /* core6 fp64 bit5 */
			{19065,13,1}, /* core6 fp64 bit6 */
			{19088,13,1}, /* core6 fp64 bit7 */
			{18922,13,1}, /* core6 fp64 bit8 */
			{18928,13,1}, /* core6 fp64 bit9 */
			{18919,13,1}, /* core6 fp64 bit10 */
			{18929,13,1}, /* core6 fp64 bit11 */
			{18921,13,1}, /* core6 fp64 bit12 */
			{18923,13,1}, /* core6 fp64 bit13 */
			{19064,13,1}, /* core6 fp64 bit14 */
			{19066,13,1}, /* core6 fp64 bit15 */
			{19322,13,1}, /* core6 fp64 bit16 */
			{19485,13,1}, /* core6 fp64 bit17 */
			{19482,13,1}, /* core6 fp64 bit18 */
			{19483,13,1}, /* core6 fp64 bit19 */
			{20163,13,1}, /* core6 fp64 bit20 */
			{19906,13,1}, /* core6 fp64 bit21 */
			{19904,13,1}, /* core6 fp64 bit22 */
			{19905,13,1}, /* core6 fp64 bit23 */
			{19907,13,1}, /* core6 fp64 bit24 */
			{19484,13,1}, /* core6 fp64 bit25 */
			{19486,13,1}, /* core6 fp64 bit26 */
			{19910,13,1}, /* core6 fp64 bit27 */
			{19481,13,1}, /* core6 fp64 bit28 */
			{19909,13,1}, /* core6 fp64 bit29 */
			{19323,13,1}, /* core6 fp64 bit30 */
			{19908,13,1}, /* core6 fp64 bit31 */
			{20417,13,1}, /* core6 fp64 bit32 */
			{20381,13,1}, /* core6 fp64 bit33 */
			{20375,13,1}, /* core6 fp64 bit34 */
			{20176,13,1}, /* core6 fp64 bit35 */
			{20416,13,1}, /* core6 fp64 bit36 */
			{20171,13,1}, /* core6 fp64 bit37 */
			{20379,13,1}, /* core6 fp64 bit38 */
			{20374,13,1}, /* core6 fp64 bit39 */
			{20373,13,1}, /* core6 fp64 bit40 */
			{20170,13,1}, /* core6 fp64 bit41 */
			{20377,13,1}, /* core6 fp64 bit42 */
			{20378,13,1}, /* core6 fp64 bit43 */
			{20376,13,1}, /* core6 fp64 bit44 */
			{20174,13,1}, /* core6 fp64 bit45 */
			{20175,13,1}, /* core6 fp64 bit46 */
			{20418,13,1}, /* core6 fp64 bit47 */
			{20562,13,1}, /* core6 fp64 bit48 */
			{24281,13,1}, /* core6 fp64 bit49 */
			{24280,13,1}, /* core6 fp64 bit50 */
			{20560,13,1}, /* core6 fp64 bit51 */
			{20564,13,1}, /* core6 fp64 bit52 */
			{20566,13,1}, /* core6 fp64 bit53 */
			{20565,13,1}, /* core6 fp64 bit54 */
			{20561,13,1}, /* core6 fp64 bit55 */
			{20563,13,1}, /* core6 fp64 bit56 */
			{20380,13,1}, /* core6 fp64 bit57 */
			{20372,13,1}, /* core6 fp64 bit58 */
			{20172,13,1}, /* core6 fp64 bit59 */
			{21549,12,1}, /* core6 fp64 bit60 */
			{21548,12,1}, /* core6 fp64 bit61 */
			{21547,12,1}, /* core6 fp64 bit62 */
			{21546,12,1}, /* core6 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{21625,12,1}, /* core6 sp_EL0 bit0 */
			{21624,12,1}, /* core6 sp_EL0 bit1 */
			{21623,12,1}, /* core6 sp_EL0 bit2 */
			{21622,12,1}, /* core6 sp_EL0 bit3 */
			{18483,13,1}, /* core6 sp_EL0 bit4 */
			{18614,13,1}, /* core6 sp_EL0 bit5 */
			{18612,13,1}, /* core6 sp_EL0 bit6 */
			{18486,13,1}, /* core6 sp_EL0 bit7 */
			{18824,13,1}, /* core6 sp_EL0 bit8 */
			{18664,13,1}, /* core6 sp_EL0 bit9 */
			{18823,13,1}, /* core6 sp_EL0 bit10 */
			{18482,13,1}, /* core6 sp_EL0 bit11 */
			{18613,13,1}, /* core6 sp_EL0 bit12 */
			{18663,13,1}, /* core6 sp_EL0 bit13 */
			{18615,13,1}, /* core6 sp_EL0 bit14 */
			{18822,13,1}, /* core6 sp_EL0 bit15 */
			{19289,13,1}, /* core6 sp_EL0 bit16 */
			{19351,13,1}, /* core6 sp_EL0 bit17 */
			{19353,13,1}, /* core6 sp_EL0 bit18 */
			{19350,13,1}, /* core6 sp_EL0 bit19 */
			{19749,13,1}, /* core6 sp_EL0 bit20 */
			{20136,13,1}, /* core6 sp_EL0 bit21 */
			{19748,13,1}, /* core6 sp_EL0 bit22 */
			{20135,13,1}, /* core6 sp_EL0 bit23 */
			{19900,13,1}, /* core6 sp_EL0 bit24 */
			{19288,13,1}, /* core6 sp_EL0 bit25 */
			{19290,13,1}, /* core6 sp_EL0 bit26 */
			{19750,13,1}, /* core6 sp_EL0 bit27 */
			{19515,13,1}, /* core6 sp_EL0 bit28 */
			{19514,13,1}, /* core6 sp_EL0 bit29 */
			{19352,13,1}, /* core6 sp_EL0 bit30 */
			{19901,13,1}, /* core6 sp_EL0 bit31 */
			{20581,13,1}, /* core6 sp_EL0 bit32 */
			{24277,13,1}, /* core6 sp_EL0 bit33 */
			{20368,13,1}, /* core6 sp_EL0 bit34 */
			{20419,13,1}, /* core6 sp_EL0 bit35 */
			{20424,13,1}, /* core6 sp_EL0 bit36 */
			{20421,13,1}, /* core6 sp_EL0 bit37 */
			{20580,13,1}, /* core6 sp_EL0 bit38 */
			{20770,13,1}, /* core6 sp_EL0 bit39 */
			{20423,13,1}, /* core6 sp_EL0 bit40 */
			{20369,13,1}, /* core6 sp_EL0 bit41 */
			{20582,13,1}, /* core6 sp_EL0 bit42 */
			{20370,13,1}, /* core6 sp_EL0 bit43 */
			{20420,13,1}, /* core6 sp_EL0 bit44 */
			{20583,13,1}, /* core6 sp_EL0 bit45 */
			{20367,13,1}, /* core6 sp_EL0 bit46 */
			{20422,13,1}, /* core6 sp_EL0 bit47 */
			{24276,13,1}, /* core6 sp_EL0 bit48 */
			{22133,12,1}, /* core6 sp_EL0 bit49 */
			{22132,12,1}, /* core6 sp_EL0 bit50 */
			{22131,12,1}, /* core6 sp_EL0 bit51 */
			{22130,12,1}, /* core6 sp_EL0 bit52 */
			{22137,12,1}, /* core6 sp_EL0 bit53 */
			{22136,12,1}, /* core6 sp_EL0 bit54 */
			{22135,12,1}, /* core6 sp_EL0 bit55 */
			{22134,12,1}, /* core6 sp_EL0 bit56 */
			{21805,12,1}, /* core6 sp_EL0 bit57 */
			{21804,12,1}, /* core6 sp_EL0 bit58 */
			{21803,12,1}, /* core6 sp_EL0 bit59 */
			{21802,12,1}, /* core6 sp_EL0 bit60 */
			{24279,13,1}, /* core6 sp_EL0 bit61 */
			{24278,13,1}, /* core6 sp_EL0 bit62 */
			{20371,13,1}, /* core6 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{21457,12,1}, /* core6 sp_EL1 bit0 */
			{21456,12,1}, /* core6 sp_EL1 bit1 */
			{21455,12,1}, /* core6 sp_EL1 bit2 */
			{21454,12,1}, /* core6 sp_EL1 bit3 */
			{18836,13,1}, /* core6 sp_EL1 bit4 */
			{18679,13,1}, /* core6 sp_EL1 bit5 */
			{18840,13,1}, /* core6 sp_EL1 bit6 */
			{18837,13,1}, /* core6 sp_EL1 bit7 */
			{18841,13,1}, /* core6 sp_EL1 bit8 */
			{18881,13,1}, /* core6 sp_EL1 bit9 */
			{18677,13,1}, /* core6 sp_EL1 bit10 */
			{18678,13,1}, /* core6 sp_EL1 bit11 */
			{18842,13,1}, /* core6 sp_EL1 bit12 */
			{18839,13,1}, /* core6 sp_EL1 bit13 */
			{18838,13,1}, /* core6 sp_EL1 bit14 */
			{19086,13,1}, /* core6 sp_EL1 bit15 */
			{19314,13,1}, /* core6 sp_EL1 bit16 */
			{19491,13,1}, /* core6 sp_EL1 bit17 */
			{19311,13,1}, /* core6 sp_EL1 bit18 */
			{19312,13,1}, /* core6 sp_EL1 bit19 */
			{20069,13,1}, /* core6 sp_EL1 bit20 */
			{19765,13,1}, /* core6 sp_EL1 bit21 */
			{19611,13,1}, /* core6 sp_EL1 bit22 */
			{19912,13,1}, /* core6 sp_EL1 bit23 */
			{19766,13,1}, /* core6 sp_EL1 bit24 */
			{19492,13,1}, /* core6 sp_EL1 bit25 */
			{19493,13,1}, /* core6 sp_EL1 bit26 */
			{19614,13,1}, /* core6 sp_EL1 bit27 */
			{19490,13,1}, /* core6 sp_EL1 bit28 */
			{19613,13,1}, /* core6 sp_EL1 bit29 */
			{19310,13,1}, /* core6 sp_EL1 bit30 */
			{19612,13,1}, /* core6 sp_EL1 bit31 */
			{20570,13,1}, /* core6 sp_EL1 bit32 */
			{20568,13,1}, /* core6 sp_EL1 bit33 */
			{20412,13,1}, /* core6 sp_EL1 bit34 */
			{20408,13,1}, /* core6 sp_EL1 bit35 */
			{20404,13,1}, /* core6 sp_EL1 bit36 */
			{20403,13,1}, /* core6 sp_EL1 bit37 */
			{20558,13,1}, /* core6 sp_EL1 bit38 */
			{20410,13,1}, /* core6 sp_EL1 bit39 */
			{20406,13,1}, /* core6 sp_EL1 bit40 */
			{20571,13,1}, /* core6 sp_EL1 bit41 */
			{20409,13,1}, /* core6 sp_EL1 bit42 */
			{20402,13,1}, /* core6 sp_EL1 bit43 */
			{20405,13,1}, /* core6 sp_EL1 bit44 */
			{20572,13,1}, /* core6 sp_EL1 bit45 */
			{20414,13,1}, /* core6 sp_EL1 bit46 */
			{20413,13,1}, /* core6 sp_EL1 bit47 */
			{20557,13,1}, /* core6 sp_EL1 bit48 */
			{24297,13,1}, /* core6 sp_EL1 bit49 */
			{20567,13,1}, /* core6 sp_EL1 bit50 */
			{21797,12,1}, /* core6 sp_EL1 bit51 */
			{20569,13,1}, /* core6 sp_EL1 bit52 */
			{20407,13,1}, /* core6 sp_EL1 bit53 */
			{24296,13,1}, /* core6 sp_EL1 bit54 */
			{21796,12,1}, /* core6 sp_EL1 bit55 */
			{20559,13,1}, /* core6 sp_EL1 bit56 */
			{21795,12,1}, /* core6 sp_EL1 bit57 */
			{20411,13,1}, /* core6 sp_EL1 bit58 */
			{24293,13,1}, /* core6 sp_EL1 bit59 */
			{21794,12,1}, /* core6 sp_EL1 bit60 */
			{24292,13,1}, /* core6 sp_EL1 bit61 */
			{24295,13,1}, /* core6 sp_EL1 bit62 */
			{24294,13,1}, /* core6 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{21361,12,1}, /* core6 sp_EL2 bit0 */
			{21360,12,1}, /* core6 sp_EL2 bit1 */
			{21359,12,1}, /* core6 sp_EL2 bit2 */
			{21358,12,1}, /* core6 sp_EL2 bit3 */
			{18669,13,1}, /* core6 sp_EL2 bit4 */
			{18670,13,1}, /* core6 sp_EL2 bit5 */
			{18619,13,1}, /* core6 sp_EL2 bit6 */
			{18830,13,1}, /* core6 sp_EL2 bit7 */
			{18827,13,1}, /* core6 sp_EL2 bit8 */
			{18618,13,1}, /* core6 sp_EL2 bit9 */
			{18829,13,1}, /* core6 sp_EL2 bit10 */
			{18667,13,1}, /* core6 sp_EL2 bit11 */
			{18620,13,1}, /* core6 sp_EL2 bit12 */
			{18668,13,1}, /* core6 sp_EL2 bit13 */
			{18828,13,1}, /* core6 sp_EL2 bit14 */
			{18831,13,1}, /* core6 sp_EL2 bit15 */
			{19347,13,1}, /* core6 sp_EL2 bit16 */
			{19345,13,1}, /* core6 sp_EL2 bit17 */
			{19509,13,1}, /* core6 sp_EL2 bit18 */
			{19511,13,1}, /* core6 sp_EL2 bit19 */
			{19934,13,1}, /* core6 sp_EL2 bit20 */
			{20143,13,1}, /* core6 sp_EL2 bit21 */
			{19927,13,1}, /* core6 sp_EL2 bit22 */
			{20142,13,1}, /* core6 sp_EL2 bit23 */
			{19933,13,1}, /* core6 sp_EL2 bit24 */
			{19512,13,1}, /* core6 sp_EL2 bit25 */
			{19348,13,1}, /* core6 sp_EL2 bit26 */
			{19638,13,1}, /* core6 sp_EL2 bit27 */
			{19510,13,1}, /* core6 sp_EL2 bit28 */
			{19932,13,1}, /* core6 sp_EL2 bit29 */
			{19346,13,1}, /* core6 sp_EL2 bit30 */
			{19928,13,1}, /* core6 sp_EL2 bit31 */
			{20876,13,1}, /* core6 sp_EL2 bit32 */
			{24309,13,1}, /* core6 sp_EL2 bit33 */
			{20872,13,1}, /* core6 sp_EL2 bit34 */
			{20869,13,1}, /* core6 sp_EL2 bit35 */
			{20874,13,1}, /* core6 sp_EL2 bit36 */
			{20873,13,1}, /* core6 sp_EL2 bit37 */
			{20877,13,1}, /* core6 sp_EL2 bit38 */
			{20870,13,1}, /* core6 sp_EL2 bit39 */
			{20738,13,1}, /* core6 sp_EL2 bit40 */
			{20875,13,1}, /* core6 sp_EL2 bit41 */
			{20740,13,1}, /* core6 sp_EL2 bit42 */
			{20878,13,1}, /* core6 sp_EL2 bit43 */
			{20871,13,1}, /* core6 sp_EL2 bit44 */
			{21045,13,1}, /* core6 sp_EL2 bit45 */
			{24308,13,1}, /* core6 sp_EL2 bit46 */
			{21044,13,1}, /* core6 sp_EL2 bit47 */
			{22433,12,1}, /* core6 sp_EL2 bit48 */
			{22432,12,1}, /* core6 sp_EL2 bit49 */
			{22431,12,1}, /* core6 sp_EL2 bit50 */
			{22430,12,1}, /* core6 sp_EL2 bit51 */
			{22685,12,1}, /* core6 sp_EL2 bit52 */
			{22684,12,1}, /* core6 sp_EL2 bit53 */
			{22683,12,1}, /* core6 sp_EL2 bit54 */
			{22682,12,1}, /* core6 sp_EL2 bit55 */
			{22261,12,1}, /* core6 sp_EL2 bit56 */
			{22260,12,1}, /* core6 sp_EL2 bit57 */
			{22259,12,1}, /* core6 sp_EL2 bit58 */
			{22258,12,1}, /* core6 sp_EL2 bit59 */
			{22265,12,1}, /* core6 sp_EL2 bit60 */
			{22264,12,1}, /* core6 sp_EL2 bit61 */
			{22263,12,1}, /* core6 sp_EL2 bit62 */
			{22262,12,1}, /* core6 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{21617,12,1}, /* core6 sp_EL3 bit0 */
			{21616,12,1}, /* core6 sp_EL3 bit1 */
			{21615,12,1}, /* core6 sp_EL3 bit2 */
			{21614,12,1}, /* core6 sp_EL3 bit3 */
			{18625,13,1}, /* core6 sp_EL3 bit4 */
			{18622,13,1}, /* core6 sp_EL3 bit5 */
			{18623,13,1}, /* core6 sp_EL3 bit6 */
			{18813,13,1}, /* core6 sp_EL3 bit7 */
			{18796,13,1}, /* core6 sp_EL3 bit8 */
			{18797,13,1}, /* core6 sp_EL3 bit9 */
			{18812,13,1}, /* core6 sp_EL3 bit10 */
			{18621,13,1}, /* core6 sp_EL3 bit11 */
			{18795,13,1}, /* core6 sp_EL3 bit12 */
			{18624,13,1}, /* core6 sp_EL3 bit13 */
			{18961,13,1}, /* core6 sp_EL3 bit14 */
			{18798,13,1}, /* core6 sp_EL3 bit15 */
			{19295,13,1}, /* core6 sp_EL3 bit16 */
			{19506,13,1}, /* core6 sp_EL3 bit17 */
			{19303,13,1}, /* core6 sp_EL3 bit18 */
			{19294,13,1}, /* core6 sp_EL3 bit19 */
			{20155,13,1}, /* core6 sp_EL3 bit20 */
			{20154,13,1}, /* core6 sp_EL3 bit21 */
			{19760,13,1}, /* core6 sp_EL3 bit22 */
			{20153,13,1}, /* core6 sp_EL3 bit23 */
			{19759,13,1}, /* core6 sp_EL3 bit24 */
			{19508,13,1}, /* core6 sp_EL3 bit25 */
			{19507,13,1}, /* core6 sp_EL3 bit26 */
			{19761,13,1}, /* core6 sp_EL3 bit27 */
			{19504,13,1}, /* core6 sp_EL3 bit28 */
			{19762,13,1}, /* core6 sp_EL3 bit29 */
			{19293,13,1}, /* core6 sp_EL3 bit30 */
			{19763,13,1}, /* core6 sp_EL3 bit31 */
			{20744,13,1}, /* core6 sp_EL3 bit32 */
			{24301,13,1}, /* core6 sp_EL3 bit33 */
			{20747,13,1}, /* core6 sp_EL3 bit34 */
			{20864,13,1}, /* core6 sp_EL3 bit35 */
			{20745,13,1}, /* core6 sp_EL3 bit36 */
			{20866,13,1}, /* core6 sp_EL3 bit37 */
			{20742,13,1}, /* core6 sp_EL3 bit38 */
			{20863,13,1}, /* core6 sp_EL3 bit39 */
			{20748,13,1}, /* core6 sp_EL3 bit40 */
			{20741,13,1}, /* core6 sp_EL3 bit41 */
			{20746,13,1}, /* core6 sp_EL3 bit42 */
			{20865,13,1}, /* core6 sp_EL3 bit43 */
			{20743,13,1}, /* core6 sp_EL3 bit44 */
			{21041,13,1}, /* core6 sp_EL3 bit45 */
			{20867,13,1}, /* core6 sp_EL3 bit46 */
			{21042,13,1}, /* core6 sp_EL3 bit47 */
			{24300,13,1}, /* core6 sp_EL3 bit48 */
			{22509,12,1}, /* core6 sp_EL3 bit49 */
			{22508,12,1}, /* core6 sp_EL3 bit50 */
			{22507,12,1}, /* core6 sp_EL3 bit51 */
			{22506,12,1}, /* core6 sp_EL3 bit52 */
			{22337,12,1}, /* core6 sp_EL3 bit53 */
			{22336,12,1}, /* core6 sp_EL3 bit54 */
			{22335,12,1}, /* core6 sp_EL3 bit55 */
			{22334,12,1}, /* core6 sp_EL3 bit56 */
			{22277,12,1}, /* core6 sp_EL3 bit57 */
			{22276,12,1}, /* core6 sp_EL3 bit58 */
			{22275,12,1}, /* core6 sp_EL3 bit59 */
			{22274,12,1}, /* core6 sp_EL3 bit60 */
			{24303,13,1}, /* core6 sp_EL3 bit61 */
			{24302,13,1}, /* core6 sp_EL3 bit62 */
			{20868,13,1}, /* core6 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{21357,12,1}, /* core6 elr_EL1 bit0 */
			{21356,12,1}, /* core6 elr_EL1 bit1 */
			{21355,12,1}, /* core6 elr_EL1 bit2 */
			{21354,12,1}, /* core6 elr_EL1 bit3 */
			{18607,13,1}, /* core6 elr_EL1 bit4 */
			{18605,13,1}, /* core6 elr_EL1 bit5 */
			{18662,13,1}, /* core6 elr_EL1 bit6 */
			{18661,13,1}, /* core6 elr_EL1 bit7 */
			{18821,13,1}, /* core6 elr_EL1 bit8 */
			{18481,13,1}, /* core6 elr_EL1 bit9 */
			{18820,13,1}, /* core6 elr_EL1 bit10 */
			{18480,13,1}, /* core6 elr_EL1 bit11 */
			{18606,13,1}, /* core6 elr_EL1 bit12 */
			{18660,13,1}, /* core6 elr_EL1 bit13 */
			{18659,13,1}, /* core6 elr_EL1 bit14 */
			{18658,13,1}, /* core6 elr_EL1 bit15 */
			{19354,13,1}, /* core6 elr_EL1 bit16 */
			{19609,13,1}, /* core6 elr_EL1 bit17 */
			{19610,13,1}, /* core6 elr_EL1 bit18 */
			{19355,13,1}, /* core6 elr_EL1 bit19 */
			{20099,13,1}, /* core6 elr_EL1 bit20 */
			{20098,13,1}, /* core6 elr_EL1 bit21 */
			{19840,13,1}, /* core6 elr_EL1 bit22 */
			{20100,13,1}, /* core6 elr_EL1 bit23 */
			{19837,13,1}, /* core6 elr_EL1 bit24 */
			{19608,13,1}, /* core6 elr_EL1 bit25 */
			{19758,13,1}, /* core6 elr_EL1 bit26 */
			{19839,13,1}, /* core6 elr_EL1 bit27 */
			{19757,13,1}, /* core6 elr_EL1 bit28 */
			{19836,13,1}, /* core6 elr_EL1 bit29 */
			{19356,13,1}, /* core6 elr_EL1 bit30 */
			{19838,13,1}, /* core6 elr_EL1 bit31 */
			{20762,13,1}, /* core6 elr_EL1 bit32 */
			{24313,13,1}, /* core6 elr_EL1 bit33 */
			{20759,13,1}, /* core6 elr_EL1 bit34 */
			{24312,13,1}, /* core6 elr_EL1 bit35 */
			{20859,13,1}, /* core6 elr_EL1 bit36 */
			{20881,13,1}, /* core6 elr_EL1 bit37 */
			{20763,13,1}, /* core6 elr_EL1 bit38 */
			{20880,13,1}, /* core6 elr_EL1 bit39 */
			{20760,13,1}, /* core6 elr_EL1 bit40 */
			{20574,13,1}, /* core6 elr_EL1 bit41 */
			{20764,13,1}, /* core6 elr_EL1 bit42 */
			{20882,13,1}, /* core6 elr_EL1 bit43 */
			{20761,13,1}, /* core6 elr_EL1 bit44 */
			{20573,13,1}, /* core6 elr_EL1 bit45 */
			{21037,13,1}, /* core6 elr_EL1 bit46 */
			{21036,13,1}, /* core6 elr_EL1 bit47 */
			{24307,13,1}, /* core6 elr_EL1 bit48 */
			{22513,12,1}, /* core6 elr_EL1 bit49 */
			{22512,12,1}, /* core6 elr_EL1 bit50 */
			{22511,12,1}, /* core6 elr_EL1 bit51 */
			{22510,12,1}, /* core6 elr_EL1 bit52 */
			{22429,12,1}, /* core6 elr_EL1 bit53 */
			{22428,12,1}, /* core6 elr_EL1 bit54 */
			{22427,12,1}, /* core6 elr_EL1 bit55 */
			{22426,12,1}, /* core6 elr_EL1 bit56 */
			{22517,12,1}, /* core6 elr_EL1 bit57 */
			{22516,12,1}, /* core6 elr_EL1 bit58 */
			{22515,12,1}, /* core6 elr_EL1 bit59 */
			{22514,12,1}, /* core6 elr_EL1 bit60 */
			{24306,13,1}, /* core6 elr_EL1 bit61 */
			{24305,13,1}, /* core6 elr_EL1 bit62 */
			{24304,13,1}, /* core6 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{21365,12,1}, /* core6 elr_EL2 bit0 */
			{21364,12,1}, /* core6 elr_EL2 bit1 */
			{21363,12,1}, /* core6 elr_EL2 bit2 */
			{21362,12,1}, /* core6 elr_EL2 bit3 */
			{18673,13,1}, /* core6 elr_EL2 bit4 */
			{18672,13,1}, /* core6 elr_EL2 bit5 */
			{18676,13,1}, /* core6 elr_EL2 bit6 */
			{18834,13,1}, /* core6 elr_EL2 bit7 */
			{18833,13,1}, /* core6 elr_EL2 bit8 */
			{18674,13,1}, /* core6 elr_EL2 bit9 */
			{18806,13,1}, /* core6 elr_EL2 bit10 */
			{18675,13,1}, /* core6 elr_EL2 bit11 */
			{18835,13,1}, /* core6 elr_EL2 bit12 */
			{18671,13,1}, /* core6 elr_EL2 bit13 */
			{18807,13,1}, /* core6 elr_EL2 bit14 */
			{18832,13,1}, /* core6 elr_EL2 bit15 */
			{19308,13,1}, /* core6 elr_EL2 bit16 */
			{19307,13,1}, /* core6 elr_EL2 bit17 */
			{19501,13,1}, /* core6 elr_EL2 bit18 */
			{19500,13,1}, /* core6 elr_EL2 bit19 */
			{19915,13,1}, /* core6 elr_EL2 bit20 */
			{20156,13,1}, /* core6 elr_EL2 bit21 */
			{19764,13,1}, /* core6 elr_EL2 bit22 */
			{19917,13,1}, /* core6 elr_EL2 bit23 */
			{19919,13,1}, /* core6 elr_EL2 bit24 */
			{19503,13,1}, /* core6 elr_EL2 bit25 */
			{19502,13,1}, /* core6 elr_EL2 bit26 */
			{19920,13,1}, /* core6 elr_EL2 bit27 */
			{19505,13,1}, /* core6 elr_EL2 bit28 */
			{19918,13,1}, /* core6 elr_EL2 bit29 */
			{19302,13,1}, /* core6 elr_EL2 bit30 */
			{19916,13,1}, /* core6 elr_EL2 bit31 */
			{20751,13,1}, /* core6 elr_EL2 bit32 */
			{24311,13,1}, /* core6 elr_EL2 bit33 */
			{20754,13,1}, /* core6 elr_EL2 bit34 */
			{24310,13,1}, /* core6 elr_EL2 bit35 */
			{20862,13,1}, /* core6 elr_EL2 bit36 */
			{20879,13,1}, /* core6 elr_EL2 bit37 */
			{20750,13,1}, /* core6 elr_EL2 bit38 */
			{20861,13,1}, /* core6 elr_EL2 bit39 */
			{20752,13,1}, /* core6 elr_EL2 bit40 */
			{20755,13,1}, /* core6 elr_EL2 bit41 */
			{20753,13,1}, /* core6 elr_EL2 bit42 */
			{20860,13,1}, /* core6 elr_EL2 bit43 */
			{20749,13,1}, /* core6 elr_EL2 bit44 */
			{21040,13,1}, /* core6 elr_EL2 bit45 */
			{21038,13,1}, /* core6 elr_EL2 bit46 */
			{21039,13,1}, /* core6 elr_EL2 bit47 */
			{22437,12,1}, /* core6 elr_EL2 bit48 */
			{22436,12,1}, /* core6 elr_EL2 bit49 */
			{22435,12,1}, /* core6 elr_EL2 bit50 */
			{22434,12,1}, /* core6 elr_EL2 bit51 */
			{22273,12,1}, /* core6 elr_EL2 bit52 */
			{22272,12,1}, /* core6 elr_EL2 bit53 */
			{22271,12,1}, /* core6 elr_EL2 bit54 */
			{22270,12,1}, /* core6 elr_EL2 bit55 */
			{22333,12,1}, /* core6 elr_EL2 bit56 */
			{22332,12,1}, /* core6 elr_EL2 bit57 */
			{22331,12,1}, /* core6 elr_EL2 bit58 */
			{22330,12,1}, /* core6 elr_EL2 bit59 */
			{22269,12,1}, /* core6 elr_EL2 bit60 */
			{22268,12,1}, /* core6 elr_EL2 bit61 */
			{22267,12,1}, /* core6 elr_EL2 bit62 */
			{22266,12,1}, /* core6 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{22077,12,1}, /* core6 elr_EL3 bit0 */
			{22076,12,1}, /* core6 elr_EL3 bit1 */
			{22075,12,1}, /* core6 elr_EL3 bit2 */
			{22074,12,1}, /* core6 elr_EL3 bit3 */
			{18592,13,1}, /* core6 elr_EL3 bit4 */
			{18439,13,1}, /* core6 elr_EL3 bit5 */
			{18780,13,1}, /* core6 elr_EL3 bit6 */
			{18434,13,1}, /* core6 elr_EL3 bit7 */
			{18432,13,1}, /* core6 elr_EL3 bit8 */
			{18594,13,1}, /* core6 elr_EL3 bit9 */
			{18431,13,1}, /* core6 elr_EL3 bit10 */
			{18438,13,1}, /* core6 elr_EL3 bit11 */
			{18433,13,1}, /* core6 elr_EL3 bit12 */
			{18781,13,1}, /* core6 elr_EL3 bit13 */
			{18593,13,1}, /* core6 elr_EL3 bit14 */
			{18440,13,1}, /* core6 elr_EL3 bit15 */
			{19567,13,1}, /* core6 elr_EL3 bit16 */
			{19563,13,1}, /* core6 elr_EL3 bit17 */
			{19568,13,1}, /* core6 elr_EL3 bit18 */
			{19565,13,1}, /* core6 elr_EL3 bit19 */
			{19727,13,1}, /* core6 elr_EL3 bit20 */
			{20134,13,1}, /* core6 elr_EL3 bit21 */
			{19824,13,1}, /* core6 elr_EL3 bit22 */
			{19728,13,1}, /* core6 elr_EL3 bit23 */
			{19823,13,1}, /* core6 elr_EL3 bit24 */
			{19564,13,1}, /* core6 elr_EL3 bit25 */
			{19388,13,1}, /* core6 elr_EL3 bit26 */
			{19695,13,1}, /* core6 elr_EL3 bit27 */
			{19566,13,1}, /* core6 elr_EL3 bit28 */
			{19729,13,1}, /* core6 elr_EL3 bit29 */
			{19389,13,1}, /* core6 elr_EL3 bit30 */
			{19694,13,1}, /* core6 elr_EL3 bit31 */
			{24597,13,1}, /* core6 elr_EL3 bit32 */
			{23029,12,1}, /* core6 elr_EL3 bit33 */
			{24596,13,1}, /* core6 elr_EL3 bit34 */
			{24599,13,1}, /* core6 elr_EL3 bit35 */
			{21544,13,1}, /* core6 elr_EL3 bit36 */
			{21543,13,1}, /* core6 elr_EL3 bit37 */
			{21550,13,1}, /* core6 elr_EL3 bit38 */
			{21558,13,1}, /* core6 elr_EL3 bit39 */
			{24598,13,1}, /* core6 elr_EL3 bit40 */
			{21545,13,1}, /* core6 elr_EL3 bit41 */
			{21559,13,1}, /* core6 elr_EL3 bit42 */
			{21552,13,1}, /* core6 elr_EL3 bit43 */
			{21551,13,1}, /* core6 elr_EL3 bit44 */
			{21241,13,1}, /* core6 elr_EL3 bit45 */
			{21242,13,1}, /* core6 elr_EL3 bit46 */
			{23028,12,1}, /* core6 elr_EL3 bit47 */
			{23027,12,1}, /* core6 elr_EL3 bit48 */
			{23026,12,1}, /* core6 elr_EL3 bit49 */
			{23033,12,1}, /* core6 elr_EL3 bit50 */
			{23032,12,1}, /* core6 elr_EL3 bit51 */
			{23031,12,1}, /* core6 elr_EL3 bit52 */
			{23030,12,1}, /* core6 elr_EL3 bit53 */
			{22897,12,1}, /* core6 elr_EL3 bit54 */
			{22896,12,1}, /* core6 elr_EL3 bit55 */
			{22895,12,1}, /* core6 elr_EL3 bit56 */
			{22894,12,1}, /* core6 elr_EL3 bit57 */
			{22893,12,1}, /* core6 elr_EL3 bit58 */
			{22892,12,1}, /* core6 elr_EL3 bit59 */
			{22891,12,1}, /* core6 elr_EL3 bit60 */
			{22890,12,1}, /* core6 elr_EL3 bit61 */
			{24595,13,1}, /* core6 elr_EL3 bit62 */
			{24594,13,1}, /* core6 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{19459,13,1}, /* core6 raw_pc bit0 */
			{19462,13,1}, /* core6 raw_pc bit1 */
			{19463,13,1}, /* core6 raw_pc bit2 */
			{19461,13,1}, /* core6 raw_pc bit3 */
			{19460,13,1}, /* core6 raw_pc bit4 */
			{19686,13,1}, /* core6 raw_pc bit5 */
			{19411,13,1}, /* core6 raw_pc bit6 */
			{18020,13,1}, /* core6 raw_pc bit7 */
			{19145,12,1}, /* core6 raw_pc bit8 */
			{19144,12,1}, /* core6 raw_pc bit9 */
			{19143,12,1}, /* core6 raw_pc bit10 */
			{19142,12,1}, /* core6 raw_pc bit11 */
			{18957,12,1}, /* core6 raw_pc bit12 */
			{18956,12,1}, /* core6 raw_pc bit13 */
			{18955,12,1}, /* core6 raw_pc bit14 */
			{17855,13,1}, /* core6 raw_pc bit15 */
			{17853,13,1}, /* core6 raw_pc bit16 */
			{23935,13,1}, /* core6 raw_pc bit17 */
			{23934,13,1}, /* core6 raw_pc bit18 */
			{18019,13,1}, /* core6 raw_pc bit19 */
			{18017,13,1}, /* core6 raw_pc bit20 */
			{18954,12,1}, /* core6 raw_pc bit21 */
			{18018,13,1}, /* core6 raw_pc bit22 */
			{17854,13,1}, /* core6 raw_pc bit23 */
			{23931,13,1}, /* core6 raw_pc bit24 */
			{17857,13,1}, /* core6 raw_pc bit25 */
			{17856,13,1}, /* core6 raw_pc bit26 */
			{23930,13,1}, /* core6 raw_pc bit27 */
			{23933,13,1}, /* core6 raw_pc bit28 */
			{23932,13,1}, /* core6 raw_pc bit29 */
			{17858,13,1}, /* core6 raw_pc bit30 */
			{18301,12,1}, /* core6 raw_pc bit31 */
			{17644,13,1}, /* core6 raw_pc bit32 */
			{18300,12,1}, /* core6 raw_pc bit33 */
			{18299,12,1}, /* core6 raw_pc bit34 */
			{18298,12,1}, /* core6 raw_pc bit35 */
			{18297,12,1}, /* core6 raw_pc bit36 */
			{18296,12,1}, /* core6 raw_pc bit37 */
			{18295,12,1}, /* core6 raw_pc bit38 */
			{18294,12,1}, /* core6 raw_pc bit39 */
			{18293,12,1}, /* core6 raw_pc bit40 */
			{18292,12,1}, /* core6 raw_pc bit41 */
			{18291,12,1}, /* core6 raw_pc bit42 */
			{18290,12,1}, /* core6 raw_pc bit43 */
			{23723,13,1}, /* core6 raw_pc bit44 */
			{23722,13,1}, /* core6 raw_pc bit45 */
			{17642,13,1}, /* core6 raw_pc bit46 */
			{17643,13,1}, /* core6 raw_pc bit47 */
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
			{19178,13,1}, /* core6 pc_iss bit0 */
			{19183,13,1}, /* core6 pc_iss bit1 */
			{19181,13,1}, /* core6 pc_iss bit2 */
			{19177,13,1}, /* core6 pc_iss bit3 */
			{19176,13,1}, /* core6 pc_iss bit4 */
			{19185,13,1}, /* core6 pc_iss bit5 */
			{19184,13,1}, /* core6 pc_iss bit6 */
			{19186,13,1}, /* core6 pc_iss bit7 */
			{18373,13,1}, /* core6 pc_iss bit8 */
			{18374,13,1}, /* core6 pc_iss bit9 */
			{18378,13,1}, /* core6 pc_iss bit10 */
			{18375,13,1}, /* core6 pc_iss bit11 */
			{18370,13,1}, /* core6 pc_iss bit12 */
			{18371,13,1}, /* core6 pc_iss bit13 */
			{18376,13,1}, /* core6 pc_iss bit14 */
			{18189,13,1}, /* core6 pc_iss bit15 */
			{18162,13,1}, /* core6 pc_iss bit16 */
			{18368,13,1}, /* core6 pc_iss bit17 */
			{18150,13,1}, /* core6 pc_iss bit18 */
			{18366,13,1}, /* core6 pc_iss bit19 */
			{18367,13,1}, /* core6 pc_iss bit20 */
			{18369,13,1}, /* core6 pc_iss bit21 */
			{18188,13,1}, /* core6 pc_iss bit22 */
			{18152,13,1}, /* core6 pc_iss bit23 */
			{18379,13,1}, /* core6 pc_iss bit24 */
			{18153,13,1}, /* core6 pc_iss bit25 */
			{18191,13,1}, /* core6 pc_iss bit26 */
			{18151,13,1}, /* core6 pc_iss bit27 */
			{18372,13,1}, /* core6 pc_iss bit28 */
			{18190,13,1}, /* core6 pc_iss bit29 */
			{18161,13,1}, /* core6 pc_iss bit30 */
			{17979,13,1}, /* core6 pc_iss bit31 */
			{18022,13,1}, /* core6 pc_iss bit32 */
			{18021,13,1}, /* core6 pc_iss bit33 */
			{17838,13,1}, /* core6 pc_iss bit34 */
			{17848,13,1}, /* core6 pc_iss bit35 */
			{17837,13,1}, /* core6 pc_iss bit36 */
			{17847,13,1}, /* core6 pc_iss bit37 */
			{17849,13,1}, /* core6 pc_iss bit38 */
			{17842,13,1}, /* core6 pc_iss bit39 */
			{17840,13,1}, /* core6 pc_iss bit40 */
			{17850,13,1}, /* core6 pc_iss bit41 */
			{17846,13,1}, /* core6 pc_iss bit42 */
			{17843,13,1}, /* core6 pc_iss bit43 */
			{17844,13,1}, /* core6 pc_iss bit44 */
			{17841,13,1}, /* core6 pc_iss bit45 */
			{17845,13,1}, /* core6 pc_iss bit46 */
			{17839,13,1}, /* core6 pc_iss bit47 */
			{18441,12,1}, /* core6 pc_iss bit48 */
			{18440,12,1}, /* core6 pc_iss bit49 */
			{18439,12,1}, /* core6 pc_iss bit50 */
			{18438,12,1}, /* core6 pc_iss bit51 */
			{18281,12,1}, /* core6 pc_iss bit52 */
			{18280,12,1}, /* core6 pc_iss bit53 */
			{18279,12,1}, /* core6 pc_iss bit54 */
			{18278,12,1}, /* core6 pc_iss bit55 */
			{18289,12,1}, /* core6 pc_iss bit56 */
			{18288,12,1}, /* core6 pc_iss bit57 */
			{18287,12,1}, /* core6 pc_iss bit58 */
			{18286,12,1}, /* core6 pc_iss bit59 */
			{18285,12,1}, /* core6 pc_iss bit60 */
			{18284,12,1}, /* core6 pc_iss bit61 */
			{18283,12,1}, /* core6 pc_iss bit62 */
			{18282,12,1}, /* core6 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{19685,13,1}, /* core6 full_pc_wr bit0 */
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
			{20035,13,1}, /* core6 full_pc_ex1 bit0 */
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
			{20029,13,1}, /* core6 full_pc_ex2 bit0 */
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
			.spmc_power_state = {{
			{15836,23,0}, /* core7 spmc_power_state bit0 */
			{15272,21,1}, /* core7 spmc_power_state bit1 */
			{15271,21,1}, /* core7 spmc_power_state bit2 */
			{15192,21,1}, /* core7 spmc_power_state bit3 */
			{15191,21,1}, /* core7 spmc_power_state bit4 */
			{15835,23,0}, /* core7 spmc_power_state bit5 */
			{    0, 0,2}, /* core7 spmc_power_state bit6 */
			{    0, 0,2}, /* core7 spmc_power_state bit7 */
			{    0, 0,2}, /* core7 spmc_power_state bit8 */
			{    0, 0,2}, /* core7 spmc_power_state bit9 */
			{    0, 0,2}, /* core7 spmc_power_state bit10 */
			{    0, 0,2}, /* core7 spmc_power_state bit11 */
			{    0, 0,2}, /* core7 spmc_power_state bit12 */
			{    0, 0,2}, /* core7 spmc_power_state bit13 */
			{    0, 0,2}, /* core7 spmc_power_state bit14 */
			{    0, 0,2}, /* core7 spmc_power_state bit15 */
			{    0, 0,2}, /* core7 spmc_power_state bit16 */
			{    0, 0,2}, /* core7 spmc_power_state bit17 */
			{    0, 0,2}, /* core7 spmc_power_state bit18 */
			{    0, 0,2}, /* core7 spmc_power_state bit19 */
			{    0, 0,2}, /* core7 spmc_power_state bit20 */
			{    0, 0,2}, /* core7 spmc_power_state bit21 */
			{    0, 0,2}, /* core7 spmc_power_state bit22 */
			{    0, 0,2}, /* core7 spmc_power_state bit23 */
			{    0, 0,2}, /* core7 spmc_power_state bit24 */
			{    0, 0,2}, /* core7 spmc_power_state bit25 */
			{    0, 0,2}, /* core7 spmc_power_state bit26 */
			{    0, 0,2}, /* core7 spmc_power_state bit27 */
			{    0, 0,2}, /* core7 spmc_power_state bit28 */
			{    0, 0,2}, /* core7 spmc_power_state bit29 */
			{    0, 0,2}, /* core7 spmc_power_state bit30 */
			{    0, 0,2}, /* core7 spmc_power_state bit31 */
			{    0, 0,2}, /* core7 spmc_power_state bit32 */
			{    0, 0,2}, /* core7 spmc_power_state bit33 */
			{    0, 0,2}, /* core7 spmc_power_state bit34 */
			{    0, 0,2}, /* core7 spmc_power_state bit35 */
			{    0, 0,2}, /* core7 spmc_power_state bit36 */
			{    0, 0,2}, /* core7 spmc_power_state bit37 */
			{    0, 0,2}, /* core7 spmc_power_state bit38 */
			{    0, 0,2}, /* core7 spmc_power_state bit39 */
			{    0, 0,2}, /* core7 spmc_power_state bit40 */
			{    0, 0,2}, /* core7 spmc_power_state bit41 */
			{    0, 0,2}, /* core7 spmc_power_state bit42 */
			{    0, 0,2}, /* core7 spmc_power_state bit43 */
			{    0, 0,2}, /* core7 spmc_power_state bit44 */
			{    0, 0,2}, /* core7 spmc_power_state bit45 */
			{    0, 0,2}, /* core7 spmc_power_state bit46 */
			{    0, 0,2}, /* core7 spmc_power_state bit47 */
			{    0, 0,2}, /* core7 spmc_power_state bit48 */
			{    0, 0,2}, /* core7 spmc_power_state bit49 */
			{    0, 0,2}, /* core7 spmc_power_state bit50 */
			{    0, 0,2}, /* core7 spmc_power_state bit51 */
			{    0, 0,2}, /* core7 spmc_power_state bit52 */
			{    0, 0,2}, /* core7 spmc_power_state bit53 */
			{    0, 0,2}, /* core7 spmc_power_state bit54 */
			{    0, 0,2}, /* core7 spmc_power_state bit55 */
			{    0, 0,2}, /* core7 spmc_power_state bit56 */
			{    0, 0,2}, /* core7 spmc_power_state bit57 */
			{    0, 0,2}, /* core7 spmc_power_state bit58 */
			{    0, 0,2}, /* core7 spmc_power_state bit59 */
			{    0, 0,2}, /* core7 spmc_power_state bit60 */
			{    0, 0,2}, /* core7 spmc_power_state bit61 */
			{    0, 0,2}, /* core7 spmc_power_state bit62 */
			{    0, 0,2}, /* core7 spmc_power_state bit63 */
			}},
			.pc = {{
			{15638,15,1}, /* core7 pc bit0 */
			{15710,15,1}, /* core7 pc bit1 */
			{15709,15,1}, /* core7 pc bit2 */
			{15708,15,1}, /* core7 pc bit3 */
			{15745,14,1}, /* core7 pc bit4 */
			{15730,15,1}, /* core7 pc bit5 */
			{15729,15,1}, /* core7 pc bit6 */
			{15728,15,1}, /* core7 pc bit7 */
			{15594,14,1}, /* core7 pc bit8 */
			{15727,15,1}, /* core7 pc bit9 */
			{15782,15,1}, /* core7 pc bit10 */
			{15781,15,1}, /* core7 pc bit11 */
			{15780,15,1}, /* core7 pc bit12 */
			{15779,15,1}, /* core7 pc bit13 */
			{16608,15,1}, /* core7 pc bit14 */
			{13558,15,1}, /* core7 pc bit15 */
			{13557,15,1}, /* core7 pc bit16 */
			{15707,15,1}, /* core7 pc bit17 */
			{15642,15,1}, /* core7 pc bit18 */
			{15641,15,1}, /* core7 pc bit19 */
			{15640,15,1}, /* core7 pc bit20 */
			{15639,15,1}, /* core7 pc bit21 */
			{19852,15,1}, /* core7 pc bit22 */
			{15637,15,1}, /* core7 pc bit23 */
			{15636,15,1}, /* core7 pc bit24 */
			{15635,15,1}, /* core7 pc bit25 */
			{15646,15,1}, /* core7 pc bit26 */
			{15645,15,1}, /* core7 pc bit27 */
			{15644,15,1}, /* core7 pc bit28 */
			{15643,15,1}, /* core7 pc bit29 */
			{15654,15,1}, /* core7 pc bit30 */
			{19851,15,1}, /* core7 pc bit31 */
			{15674,15,1}, /* core7 pc bit32 */
			{15673,15,1}, /* core7 pc bit33 */
			{15672,15,1}, /* core7 pc bit34 */
			{15671,15,1}, /* core7 pc bit35 */
			{15678,15,1}, /* core7 pc bit36 */
			{15677,15,1}, /* core7 pc bit37 */
			{15676,15,1}, /* core7 pc bit38 */
			{15675,15,1}, /* core7 pc bit39 */
			{15682,15,1}, /* core7 pc bit40 */
			{15681,15,1}, /* core7 pc bit41 */
			{15680,15,1}, /* core7 pc bit42 */
			{15679,15,1}, /* core7 pc bit43 */
			{15694,15,1}, /* core7 pc bit44 */
			{15693,15,1}, /* core7 pc bit45 */
			{15692,15,1}, /* core7 pc bit46 */
			{15691,15,1}, /* core7 pc bit47 */
			{13630,15,1}, /* core7 pc bit48 */
			{13629,15,1}, /* core7 pc bit49 */
			{11486,14,1}, /* core7 pc bit50 */
			{11532,14,1}, /* core7 pc bit51 */
			{15686,15,1}, /* core7 pc bit52 */
			{15685,15,1}, /* core7 pc bit53 */
			{15684,15,1}, /* core7 pc bit54 */
			{15683,15,1}, /* core7 pc bit55 */
			{15690,15,1}, /* core7 pc bit56 */
			{15689,15,1}, /* core7 pc bit57 */
			{15688,15,1}, /* core7 pc bit58 */
			{15687,15,1}, /* core7 pc bit59 */
			{15670,15,1}, /* core7 pc bit60 */
			{15669,15,1}, /* core7 pc bit61 */
			{15668,15,1}, /* core7 pc bit62 */
			{15667,15,1}, /* core7 pc bit63 */
			}},
			.sp32 = {{
			{15719,14,1}, /* core7 sp32 bit0 */
			{15718,14,1}, /* core7 sp32 bit1 */
			{15705,14,1}, /* core7 sp32 bit2 */
			{15702,14,1}, /* core7 sp32 bit3 */
			{15300,14,1}, /* core7 sp32 bit4 */
			{17410,15,1}, /* core7 sp32 bit5 */
			{17412,15,1}, /* core7 sp32 bit6 */
			{15298,14,1}, /* core7 sp32 bit7 */
			{15303,14,1}, /* core7 sp32 bit8 */
			{15299,14,1}, /* core7 sp32 bit9 */
			{15306,14,1}, /* core7 sp32 bit10 */
			{17411,15,1}, /* core7 sp32 bit11 */
			{15068,14,1}, /* core7 sp32 bit12 */
			{15053,14,1}, /* core7 sp32 bit13 */
			{15304,14,1}, /* core7 sp32 bit14 */
			{15200,14,1}, /* core7 sp32 bit15 */
			{15680,14,1}, /* core7 sp32 bit16 */
			{15069,14,1}, /* core7 sp32 bit17 */
			{15682,14,1}, /* core7 sp32 bit18 */
			{11511,14,1}, /* core7 sp32 bit19 */
			{15703,14,1}, /* core7 sp32 bit20 */
			{11528,14,1}, /* core7 sp32 bit21 */
			{11529,14,1}, /* core7 sp32 bit22 */
			{11488,14,1}, /* core7 sp32 bit23 */
			{15720,14,1}, /* core7 sp32 bit24 */
			{11485,14,1}, /* core7 sp32 bit25 */
			{11530,14,1}, /* core7 sp32 bit26 */
			{15704,14,1}, /* core7 sp32 bit27 */
			{11489,14,1}, /* core7 sp32 bit28 */
			{11487,14,1}, /* core7 sp32 bit29 */
			{11531,14,1}, /* core7 sp32 bit30 */
			{15683,14,1}, /* core7 sp32 bit31 */
			{11104,14,1}, /* core7 sp32 bit32 */
			{19747,15,1}, /* core7 sp32 bit33 */
			{19748,15,1}, /* core7 sp32 bit34 */
			{19711,15,1}, /* core7 sp32 bit35 */
			{20071,15,1}, /* core7 sp32 bit36 */
			{20277,15,1}, /* core7 sp32 bit37 */
			{20066,15,1}, /* core7 sp32 bit38 */
			{20285,15,1}, /* core7 sp32 bit39 */
			{20282,15,1}, /* core7 sp32 bit40 */
			{20286,15,1}, /* core7 sp32 bit41 */
			{20108,15,1}, /* core7 sp32 bit42 */
			{20283,15,1}, /* core7 sp32 bit43 */
			{20281,15,1}, /* core7 sp32 bit44 */
			{20276,15,1}, /* core7 sp32 bit45 */
			{20065,15,1}, /* core7 sp32 bit46 */
			{18048,15,1}, /* core7 sp32 bit47 */
			{20064,15,1}, /* core7 sp32 bit48 */
			{20284,15,1}, /* core7 sp32 bit49 */
			{11103,14,1}, /* core7 sp32 bit50 */
			{16472,15,1}, /* core7 sp32 bit51 */
			{11105,14,1}, /* core7 sp32 bit52 */
			{16499,15,1}, /* core7 sp32 bit53 */
			{16473,15,1}, /* core7 sp32 bit54 */
			{16447,15,1}, /* core7 sp32 bit55 */
			{16845,15,1}, /* core7 sp32 bit56 */
			{16847,15,1}, /* core7 sp32 bit57 */
			{16846,15,1}, /* core7 sp32 bit58 */
			{16863,15,1}, /* core7 sp32 bit59 */
			{16849,15,1}, /* core7 sp32 bit60 */
			{16864,15,1}, /* core7 sp32 bit61 */
			{13538,15,1}, /* core7 sp32 bit62 */
			{13537,15,1}, /* core7 sp32 bit63 */
			}},
			.fp32 = {{
			{13726,15,1}, /* core7 fp32 bit0 */
			{13725,15,1}, /* core7 fp32 bit1 */
			{13433,15,1}, /* core7 fp32 bit2 */
			{13448,15,1}, /* core7 fp32 bit3 */
			{10876,14,1}, /* core7 fp32 bit4 */
			{13393,15,1}, /* core7 fp32 bit5 */
			{13425,15,1}, /* core7 fp32 bit6 */
			{13418,15,1}, /* core7 fp32 bit7 */
			{13426,15,1}, /* core7 fp32 bit8 */
			{13427,15,1}, /* core7 fp32 bit9 */
			{13417,15,1}, /* core7 fp32 bit10 */
			{13424,15,1}, /* core7 fp32 bit11 */
			{13439,15,1}, /* core7 fp32 bit12 */
			{13432,15,1}, /* core7 fp32 bit13 */
			{13419,15,1}, /* core7 fp32 bit14 */
			{13442,15,1}, /* core7 fp32 bit15 */
			{13446,15,1}, /* core7 fp32 bit16 */
			{13449,15,1}, /* core7 fp32 bit17 */
			{13785,15,1}, /* core7 fp32 bit18 */
			{14146,15,1}, /* core7 fp32 bit19 */
			{13727,15,1}, /* core7 fp32 bit20 */
			{14145,15,1}, /* core7 fp32 bit21 */
			{13729,15,1}, /* core7 fp32 bit22 */
			{14142,15,1}, /* core7 fp32 bit23 */
			{13267,15,1}, /* core7 fp32 bit24 */
			{13272,15,1}, /* core7 fp32 bit25 */
			{13271,15,1}, /* core7 fp32 bit26 */
			{13789,15,1}, /* core7 fp32 bit27 */
			{13270,15,1}, /* core7 fp32 bit28 */
			{13269,15,1}, /* core7 fp32 bit29 */
			{14144,15,1}, /* core7 fp32 bit30 */
			{13447,15,1}, /* core7 fp32 bit31 */
			{16778,15,1}, /* core7 fp32 bit32 */
			{16411,15,1}, /* core7 fp32 bit33 */
			{16409,15,1}, /* core7 fp32 bit34 */
			{16413,15,1}, /* core7 fp32 bit35 */
			{15539,14,1}, /* core7 fp32 bit36 */
			{15556,14,1}, /* core7 fp32 bit37 */
			{20264,15,1}, /* core7 fp32 bit38 */
			{15557,14,1}, /* core7 fp32 bit39 */
			{15524,14,1}, /* core7 fp32 bit40 */
			{19657,15,1}, /* core7 fp32 bit41 */
			{15554,14,1}, /* core7 fp32 bit42 */
			{15552,14,1}, /* core7 fp32 bit43 */
			{15559,14,1}, /* core7 fp32 bit44 */
			{20265,15,1}, /* core7 fp32 bit45 */
			{15555,14,1}, /* core7 fp32 bit46 */
			{15560,14,1}, /* core7 fp32 bit47 */
			{15553,14,1}, /* core7 fp32 bit48 */
			{15558,14,1}, /* core7 fp32 bit49 */
			{16397,15,1}, /* core7 fp32 bit50 */
			{16785,15,1}, /* core7 fp32 bit51 */
			{16788,15,1}, /* core7 fp32 bit52 */
			{16432,15,1}, /* core7 fp32 bit53 */
			{16786,15,1}, /* core7 fp32 bit54 */
			{17023,15,1}, /* core7 fp32 bit55 */
			{13018,15,1}, /* core7 fp32 bit56 */
			{16069,15,1}, /* core7 fp32 bit57 */
			{16131,15,1}, /* core7 fp32 bit58 */
			{17024,15,1}, /* core7 fp32 bit59 */
			{15437,15,1}, /* core7 fp32 bit60 */
			{16068,15,1}, /* core7 fp32 bit61 */
			{16132,15,1}, /* core7 fp32 bit62 */
			{17025,15,1}, /* core7 fp32 bit63 */
			}},
			.fp64 = {{
			{13580,15,1}, /* core7 fp64 bit0 */
			{15742,14,1}, /* core7 fp64 bit1 */
			{13579,15,1}, /* core7 fp64 bit2 */
			{15599,14,1}, /* core7 fp64 bit3 */
			{17434,15,1}, /* core7 fp64 bit4 */
			{17438,15,1}, /* core7 fp64 bit5 */
			{17439,15,1}, /* core7 fp64 bit6 */
			{17437,15,1}, /* core7 fp64 bit7 */
			{17585,15,1}, /* core7 fp64 bit8 */
			{17433,15,1}, /* core7 fp64 bit9 */
			{17429,15,1}, /* core7 fp64 bit10 */
			{17440,15,1}, /* core7 fp64 bit11 */
			{15233,14,1}, /* core7 fp64 bit12 */
			{15236,14,1}, /* core7 fp64 bit13 */
			{17441,15,1}, /* core7 fp64 bit14 */
			{15237,14,1}, /* core7 fp64 bit15 */
			{15326,14,1}, /* core7 fp64 bit16 */
			{15327,14,1}, /* core7 fp64 bit17 */
			{15240,14,1}, /* core7 fp64 bit18 */
			{11459,14,1}, /* core7 fp64 bit19 */
			{15619,14,1}, /* core7 fp64 bit20 */
			{11456,14,1}, /* core7 fp64 bit21 */
			{11454,14,1}, /* core7 fp64 bit22 */
			{11461,14,1}, /* core7 fp64 bit23 */
			{15601,14,1}, /* core7 fp64 bit24 */
			{11462,14,1}, /* core7 fp64 bit25 */
			{11455,14,1}, /* core7 fp64 bit26 */
			{15616,14,1}, /* core7 fp64 bit27 */
			{11457,14,1}, /* core7 fp64 bit28 */
			{11458,14,1}, /* core7 fp64 bit29 */
			{11460,14,1}, /* core7 fp64 bit30 */
			{15235,14,1}, /* core7 fp64 bit31 */
			{15936,14,1}, /* core7 fp64 bit32 */
			{17255,15,1}, /* core7 fp64 bit33 */
			{17254,15,1}, /* core7 fp64 bit34 */
			{17249,15,1}, /* core7 fp64 bit35 */
			{17248,15,1}, /* core7 fp64 bit36 */
			{17265,15,1}, /* core7 fp64 bit37 */
			{17251,15,1}, /* core7 fp64 bit38 */
			{17266,15,1}, /* core7 fp64 bit39 */
			{17258,15,1}, /* core7 fp64 bit40 */
			{17267,15,1}, /* core7 fp64 bit41 */
			{17274,15,1}, /* core7 fp64 bit42 */
			{18098,15,1}, /* core7 fp64 bit43 */
			{17268,15,1}, /* core7 fp64 bit44 */
			{17253,15,1}, /* core7 fp64 bit45 */
			{17263,15,1}, /* core7 fp64 bit46 */
			{17264,15,1}, /* core7 fp64 bit47 */
			{18099,15,1}, /* core7 fp64 bit48 */
			{17252,15,1}, /* core7 fp64 bit49 */
			{17275,15,1}, /* core7 fp64 bit50 */
			{17300,15,1}, /* core7 fp64 bit51 */
			{17298,15,1}, /* core7 fp64 bit52 */
			{17297,15,1}, /* core7 fp64 bit53 */
			{17299,15,1}, /* core7 fp64 bit54 */
			{15947,14,1}, /* core7 fp64 bit55 */
			{15934,14,1}, /* core7 fp64 bit56 */
			{15935,14,1}, /* core7 fp64 bit57 */
			{15977,14,1}, /* core7 fp64 bit58 */
			{15940,14,1}, /* core7 fp64 bit59 */
			{15939,14,1}, /* core7 fp64 bit60 */
			{15938,14,1}, /* core7 fp64 bit61 */
			{15978,14,1}, /* core7 fp64 bit62 */
			{15937,14,1}, /* core7 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{15678,14,1}, /* core7 sp_EL0 bit0 */
			{15204,14,1}, /* core7 sp_EL0 bit1 */
			{15311,14,1}, /* core7 sp_EL0 bit2 */
			{15675,14,1}, /* core7 sp_EL0 bit3 */
			{17564,15,1}, /* core7 sp_EL0 bit4 */
			{17483,15,1}, /* core7 sp_EL0 bit5 */
			{17485,15,1}, /* core7 sp_EL0 bit6 */
			{17481,15,1}, /* core7 sp_EL0 bit7 */
			{17563,15,1}, /* core7 sp_EL0 bit8 */
			{17562,15,1}, /* core7 sp_EL0 bit9 */
			{15296,14,1}, /* core7 sp_EL0 bit10 */
			{17565,15,1}, /* core7 sp_EL0 bit11 */
			{15310,14,1}, /* core7 sp_EL0 bit12 */
			{15291,14,1}, /* core7 sp_EL0 bit13 */
			{17484,15,1}, /* core7 sp_EL0 bit14 */
			{15060,14,1}, /* core7 sp_EL0 bit15 */
			{15205,14,1}, /* core7 sp_EL0 bit16 */
			{15061,14,1}, /* core7 sp_EL0 bit17 */
			{15679,14,1}, /* core7 sp_EL0 bit18 */
			{15582,14,1}, /* core7 sp_EL0 bit19 */
			{15687,14,1}, /* core7 sp_EL0 bit20 */
			{11477,14,1}, /* core7 sp_EL0 bit21 */
			{11496,14,1}, /* core7 sp_EL0 bit22 */
			{11478,14,1}, /* core7 sp_EL0 bit23 */
			{15735,14,1}, /* core7 sp_EL0 bit24 */
			{11499,14,1}, /* core7 sp_EL0 bit25 */
			{15583,14,1}, /* core7 sp_EL0 bit26 */
			{15676,14,1}, /* core7 sp_EL0 bit27 */
			{15696,14,1}, /* core7 sp_EL0 bit28 */
			{11497,14,1}, /* core7 sp_EL0 bit29 */
			{11498,14,1}, /* core7 sp_EL0 bit30 */
			{15055,14,1}, /* core7 sp_EL0 bit31 */
			{11236,14,1}, /* core7 sp_EL0 bit32 */
			{11221,14,1}, /* core7 sp_EL0 bit33 */
			{11206,14,1}, /* core7 sp_EL0 bit34 */
			{17393,15,1}, /* core7 sp_EL0 bit35 */
			{11216,14,1}, /* core7 sp_EL0 bit36 */
			{11218,14,1}, /* core7 sp_EL0 bit37 */
			{11220,14,1}, /* core7 sp_EL0 bit38 */
			{11219,14,1}, /* core7 sp_EL0 bit39 */
			{11115,14,1}, /* core7 sp_EL0 bit40 */
			{17390,15,1}, /* core7 sp_EL0 bit41 */
			{17391,15,1}, /* core7 sp_EL0 bit42 */
			{11116,14,1}, /* core7 sp_EL0 bit43 */
			{17389,15,1}, /* core7 sp_EL0 bit44 */
			{17392,15,1}, /* core7 sp_EL0 bit45 */
			{11217,14,1}, /* core7 sp_EL0 bit46 */
			{17388,15,1}, /* core7 sp_EL0 bit47 */
			{17368,15,1}, /* core7 sp_EL0 bit48 */
			{11222,14,1}, /* core7 sp_EL0 bit49 */
			{11228,14,1}, /* core7 sp_EL0 bit50 */
			{11230,14,1}, /* core7 sp_EL0 bit51 */
			{11231,14,1}, /* core7 sp_EL0 bit52 */
			{11119,14,1}, /* core7 sp_EL0 bit53 */
			{11232,14,1}, /* core7 sp_EL0 bit54 */
			{16459,15,1}, /* core7 sp_EL0 bit55 */
			{16455,15,1}, /* core7 sp_EL0 bit56 */
			{16456,15,1}, /* core7 sp_EL0 bit57 */
			{16458,15,1}, /* core7 sp_EL0 bit58 */
			{15961,14,1}, /* core7 sp_EL0 bit59 */
			{11189,14,1}, /* core7 sp_EL0 bit60 */
			{16457,15,1}, /* core7 sp_EL0 bit61 */
			{13544,15,1}, /* core7 sp_EL0 bit62 */
			{13543,15,1}, /* core7 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{13578,15,1}, /* core7 sp_EL1 bit0 */
			{15610,14,1}, /* core7 sp_EL1 bit1 */
			{13577,15,1}, /* core7 sp_EL1 bit2 */
			{15604,14,1}, /* core7 sp_EL1 bit3 */
			{17431,15,1}, /* core7 sp_EL1 bit4 */
			{17587,15,1}, /* core7 sp_EL1 bit5 */
			{17435,15,1}, /* core7 sp_EL1 bit6 */
			{17430,15,1}, /* core7 sp_EL1 bit7 */
			{15231,14,1}, /* core7 sp_EL1 bit8 */
			{17588,15,1}, /* core7 sp_EL1 bit9 */
			{15232,14,1}, /* core7 sp_EL1 bit10 */
			{17432,15,1}, /* core7 sp_EL1 bit11 */
			{15234,14,1}, /* core7 sp_EL1 bit12 */
			{17586,15,1}, /* core7 sp_EL1 bit13 */
			{17436,15,1}, /* core7 sp_EL1 bit14 */
			{15238,14,1}, /* core7 sp_EL1 bit15 */
			{15325,14,1}, /* core7 sp_EL1 bit16 */
			{15239,14,1}, /* core7 sp_EL1 bit17 */
			{15241,14,1}, /* core7 sp_EL1 bit18 */
			{15598,14,1}, /* core7 sp_EL1 bit19 */
			{15617,14,1}, /* core7 sp_EL1 bit20 */
			{15595,14,1}, /* core7 sp_EL1 bit21 */
			{15590,14,1}, /* core7 sp_EL1 bit22 */
			{15589,14,1}, /* core7 sp_EL1 bit23 */
			{15609,14,1}, /* core7 sp_EL1 bit24 */
			{15588,14,1}, /* core7 sp_EL1 bit25 */
			{15600,14,1}, /* core7 sp_EL1 bit26 */
			{15618,14,1}, /* core7 sp_EL1 bit27 */
			{15591,14,1}, /* core7 sp_EL1 bit28 */
			{15596,14,1}, /* core7 sp_EL1 bit29 */
			{15597,14,1}, /* core7 sp_EL1 bit30 */
			{15230,14,1}, /* core7 sp_EL1 bit31 */
			{15944,14,1}, /* core7 sp_EL1 bit32 */
			{17322,15,1}, /* core7 sp_EL1 bit33 */
			{17250,15,1}, /* core7 sp_EL1 bit34 */
			{17310,15,1}, /* core7 sp_EL1 bit35 */
			{17312,15,1}, /* core7 sp_EL1 bit36 */
			{17272,15,1}, /* core7 sp_EL1 bit37 */
			{17311,15,1}, /* core7 sp_EL1 bit38 */
			{17308,15,1}, /* core7 sp_EL1 bit39 */
			{17270,15,1}, /* core7 sp_EL1 bit40 */
			{17269,15,1}, /* core7 sp_EL1 bit41 */
			{17309,15,1}, /* core7 sp_EL1 bit42 */
			{17271,15,1}, /* core7 sp_EL1 bit43 */
			{17313,15,1}, /* core7 sp_EL1 bit44 */
			{17314,15,1}, /* core7 sp_EL1 bit45 */
			{17306,15,1}, /* core7 sp_EL1 bit46 */
			{17273,15,1}, /* core7 sp_EL1 bit47 */
			{17307,15,1}, /* core7 sp_EL1 bit48 */
			{17305,15,1}, /* core7 sp_EL1 bit49 */
			{17304,15,1}, /* core7 sp_EL1 bit50 */
			{17296,15,1}, /* core7 sp_EL1 bit51 */
			{17303,15,1}, /* core7 sp_EL1 bit52 */
			{17301,15,1}, /* core7 sp_EL1 bit53 */
			{17302,15,1}, /* core7 sp_EL1 bit54 */
			{17295,15,1}, /* core7 sp_EL1 bit55 */
			{15941,14,1}, /* core7 sp_EL1 bit56 */
			{15973,14,1}, /* core7 sp_EL1 bit57 */
			{15942,14,1}, /* core7 sp_EL1 bit58 */
			{15943,14,1}, /* core7 sp_EL1 bit59 */
			{15945,14,1}, /* core7 sp_EL1 bit60 */
			{15974,14,1}, /* core7 sp_EL1 bit61 */
			{15948,14,1}, /* core7 sp_EL1 bit62 */
			{15975,14,1}, /* core7 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{13496,15,1}, /* core7 sp_EL2 bit0 */
			{15672,14,1}, /* core7 sp_EL2 bit1 */
			{13495,15,1}, /* core7 sp_EL2 bit2 */
			{15666,14,1}, /* core7 sp_EL2 bit3 */
			{17419,15,1}, /* core7 sp_EL2 bit4 */
			{17475,15,1}, /* core7 sp_EL2 bit5 */
			{17574,15,1}, /* core7 sp_EL2 bit6 */
			{17575,15,1}, /* core7 sp_EL2 bit7 */
			{17417,15,1}, /* core7 sp_EL2 bit8 */
			{17418,15,1}, /* core7 sp_EL2 bit9 */
			{15294,14,1}, /* core7 sp_EL2 bit10 */
			{17572,15,1}, /* core7 sp_EL2 bit11 */
			{15289,14,1}, /* core7 sp_EL2 bit12 */
			{15293,14,1}, /* core7 sp_EL2 bit13 */
			{17415,15,1}, /* core7 sp_EL2 bit14 */
			{15317,14,1}, /* core7 sp_EL2 bit15 */
			{15059,14,1}, /* core7 sp_EL2 bit16 */
			{15056,14,1}, /* core7 sp_EL2 bit17 */
			{15669,14,1}, /* core7 sp_EL2 bit18 */
			{15663,14,1}, /* core7 sp_EL2 bit19 */
			{15665,14,1}, /* core7 sp_EL2 bit20 */
			{15691,14,1}, /* core7 sp_EL2 bit21 */
			{15736,14,1}, /* core7 sp_EL2 bit22 */
			{15659,14,1}, /* core7 sp_EL2 bit23 */
			{15664,14,1}, /* core7 sp_EL2 bit24 */
			{15658,14,1}, /* core7 sp_EL2 bit25 */
			{15689,14,1}, /* core7 sp_EL2 bit26 */
			{15671,14,1}, /* core7 sp_EL2 bit27 */
			{15660,14,1}, /* core7 sp_EL2 bit28 */
			{15737,14,1}, /* core7 sp_EL2 bit29 */
			{15662,14,1}, /* core7 sp_EL2 bit30 */
			{15314,14,1}, /* core7 sp_EL2 bit31 */
			{11191,14,1}, /* core7 sp_EL2 bit32 */
			{17397,15,1}, /* core7 sp_EL2 bit33 */
			{11210,14,1}, /* core7 sp_EL2 bit34 */
			{11203,14,1}, /* core7 sp_EL2 bit35 */
			{11172,14,1}, /* core7 sp_EL2 bit36 */
			{11168,14,1}, /* core7 sp_EL2 bit37 */
			{11208,14,1}, /* core7 sp_EL2 bit38 */
			{11200,14,1}, /* core7 sp_EL2 bit39 */
			{11214,14,1}, /* core7 sp_EL2 bit40 */
			{11171,14,1}, /* core7 sp_EL2 bit41 */
			{11202,14,1}, /* core7 sp_EL2 bit42 */
			{11173,14,1}, /* core7 sp_EL2 bit43 */
			{11170,14,1}, /* core7 sp_EL2 bit44 */
			{11207,14,1}, /* core7 sp_EL2 bit45 */
			{11209,14,1}, /* core7 sp_EL2 bit46 */
			{11201,14,1}, /* core7 sp_EL2 bit47 */
			{11169,14,1}, /* core7 sp_EL2 bit48 */
			{11199,14,1}, /* core7 sp_EL2 bit49 */
			{11174,14,1}, /* core7 sp_EL2 bit50 */
			{11196,14,1}, /* core7 sp_EL2 bit51 */
			{11194,14,1}, /* core7 sp_EL2 bit52 */
			{11211,14,1}, /* core7 sp_EL2 bit53 */
			{11123,14,1}, /* core7 sp_EL2 bit54 */
			{11180,14,1}, /* core7 sp_EL2 bit55 */
			{11190,14,1}, /* core7 sp_EL2 bit56 */
			{11187,14,1}, /* core7 sp_EL2 bit57 */
			{11185,14,1}, /* core7 sp_EL2 bit58 */
			{11183,14,1}, /* core7 sp_EL2 bit59 */
			{11181,14,1}, /* core7 sp_EL2 bit60 */
			{11184,14,1}, /* core7 sp_EL2 bit61 */
			{13550,15,1}, /* core7 sp_EL2 bit62 */
			{13549,15,1}, /* core7 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{15630,14,1}, /* core7 sp_EL3 bit0 */
			{15277,14,1}, /* core7 sp_EL3 bit1 */
			{15635,14,1}, /* core7 sp_EL3 bit2 */
			{15276,14,1}, /* core7 sp_EL3 bit3 */
			{17463,15,1}, /* core7 sp_EL3 bit4 */
			{17461,15,1}, /* core7 sp_EL3 bit5 */
			{17465,15,1}, /* core7 sp_EL3 bit6 */
			{17460,15,1}, /* core7 sp_EL3 bit7 */
			{17423,15,1}, /* core7 sp_EL3 bit8 */
			{17459,15,1}, /* core7 sp_EL3 bit9 */
			{15259,14,1}, /* core7 sp_EL3 bit10 */
			{17462,15,1}, /* core7 sp_EL3 bit11 */
			{15261,14,1}, /* core7 sp_EL3 bit12 */
			{15260,14,1}, /* core7 sp_EL3 bit13 */
			{17464,15,1}, /* core7 sp_EL3 bit14 */
			{15265,14,1}, /* core7 sp_EL3 bit15 */
			{15320,14,1}, /* core7 sp_EL3 bit16 */
			{15262,14,1}, /* core7 sp_EL3 bit17 */
			{15209,14,1}, /* core7 sp_EL3 bit18 */
			{15655,14,1}, /* core7 sp_EL3 bit19 */
			{15628,14,1}, /* core7 sp_EL3 bit20 */
			{15649,14,1}, /* core7 sp_EL3 bit21 */
			{15648,14,1}, /* core7 sp_EL3 bit22 */
			{15739,14,1}, /* core7 sp_EL3 bit23 */
			{15624,14,1}, /* core7 sp_EL3 bit24 */
			{15647,14,1}, /* core7 sp_EL3 bit25 */
			{15657,14,1}, /* core7 sp_EL3 bit26 */
			{15629,14,1}, /* core7 sp_EL3 bit27 */
			{15656,14,1}, /* core7 sp_EL3 bit28 */
			{15650,14,1}, /* core7 sp_EL3 bit29 */
			{15661,14,1}, /* core7 sp_EL3 bit30 */
			{15263,14,1}, /* core7 sp_EL3 bit31 */
			{11128,14,1}, /* core7 sp_EL3 bit32 */
			{17406,15,1}, /* core7 sp_EL3 bit33 */
			{17405,15,1}, /* core7 sp_EL3 bit34 */
			{17335,15,1}, /* core7 sp_EL3 bit35 */
			{17401,15,1}, /* core7 sp_EL3 bit36 */
			{17399,15,1}, /* core7 sp_EL3 bit37 */
			{17403,15,1}, /* core7 sp_EL3 bit38 */
			{17332,15,1}, /* core7 sp_EL3 bit39 */
			{17333,15,1}, /* core7 sp_EL3 bit40 */
			{17400,15,1}, /* core7 sp_EL3 bit41 */
			{17334,15,1}, /* core7 sp_EL3 bit42 */
			{11165,14,1}, /* core7 sp_EL3 bit43 */
			{17402,15,1}, /* core7 sp_EL3 bit44 */
			{17404,15,1}, /* core7 sp_EL3 bit45 */
			{17398,15,1}, /* core7 sp_EL3 bit46 */
			{11166,14,1}, /* core7 sp_EL3 bit47 */
			{17336,15,1}, /* core7 sp_EL3 bit48 */
			{11167,14,1}, /* core7 sp_EL3 bit49 */
			{11176,14,1}, /* core7 sp_EL3 bit50 */
			{11129,14,1}, /* core7 sp_EL3 bit51 */
			{11127,14,1}, /* core7 sp_EL3 bit52 */
			{11162,14,1}, /* core7 sp_EL3 bit53 */
			{11179,14,1}, /* core7 sp_EL3 bit54 */
			{11146,14,1}, /* core7 sp_EL3 bit55 */
			{15969,14,1}, /* core7 sp_EL3 bit56 */
			{15967,14,1}, /* core7 sp_EL3 bit57 */
			{15955,14,1}, /* core7 sp_EL3 bit58 */
			{15966,14,1}, /* core7 sp_EL3 bit59 */
			{15968,14,1}, /* core7 sp_EL3 bit60 */
			{15970,14,1}, /* core7 sp_EL3 bit61 */
			{15965,14,1}, /* core7 sp_EL3 bit62 */
			{15956,14,1}, /* core7 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{15269,14,1}, /* core7 elr_EL1 bit0 */
			{15270,14,1}, /* core7 elr_EL1 bit1 */
			{15253,14,1}, /* core7 elr_EL1 bit2 */
			{15272,14,1}, /* core7 elr_EL1 bit3 */
			{17427,15,1}, /* core7 elr_EL1 bit4 */
			{17453,15,1}, /* core7 elr_EL1 bit5 */
			{17451,15,1}, /* core7 elr_EL1 bit6 */
			{17444,15,1}, /* core7 elr_EL1 bit7 */
			{17426,15,1}, /* core7 elr_EL1 bit8 */
			{17583,15,1}, /* core7 elr_EL1 bit9 */
			{17425,15,1}, /* core7 elr_EL1 bit10 */
			{17452,15,1}, /* core7 elr_EL1 bit11 */
			{15249,14,1}, /* core7 elr_EL1 bit12 */
			{15248,14,1}, /* core7 elr_EL1 bit13 */
			{17445,15,1}, /* core7 elr_EL1 bit14 */
			{15252,14,1}, /* core7 elr_EL1 bit15 */
			{15323,14,1}, /* core7 elr_EL1 bit16 */
			{15250,14,1}, /* core7 elr_EL1 bit17 */
			{15273,14,1}, /* core7 elr_EL1 bit18 */
			{15603,14,1}, /* core7 elr_EL1 bit19 */
			{15613,14,1}, /* core7 elr_EL1 bit20 */
			{15602,14,1}, /* core7 elr_EL1 bit21 */
			{15608,14,1}, /* core7 elr_EL1 bit22 */
			{15645,14,1}, /* core7 elr_EL1 bit23 */
			{15741,14,1}, /* core7 elr_EL1 bit24 */
			{15607,14,1}, /* core7 elr_EL1 bit25 */
			{15743,14,1}, /* core7 elr_EL1 bit26 */
			{15274,14,1}, /* core7 elr_EL1 bit27 */
			{15606,14,1}, /* core7 elr_EL1 bit28 */
			{15605,14,1}, /* core7 elr_EL1 bit29 */
			{15651,14,1}, /* core7 elr_EL1 bit30 */
			{15251,14,1}, /* core7 elr_EL1 bit31 */
			{17318,15,1}, /* core7 elr_EL1 bit32 */
			{17323,15,1}, /* core7 elr_EL1 bit33 */
			{17325,15,1}, /* core7 elr_EL1 bit34 */
			{17324,15,1}, /* core7 elr_EL1 bit35 */
			{17331,15,1}, /* core7 elr_EL1 bit36 */
			{17339,15,1}, /* core7 elr_EL1 bit37 */
			{17246,15,1}, /* core7 elr_EL1 bit38 */
			{17245,15,1}, /* core7 elr_EL1 bit39 */
			{17327,15,1}, /* core7 elr_EL1 bit40 */
			{17328,15,1}, /* core7 elr_EL1 bit41 */
			{17326,15,1}, /* core7 elr_EL1 bit42 */
			{17338,15,1}, /* core7 elr_EL1 bit43 */
			{17341,15,1}, /* core7 elr_EL1 bit44 */
			{17247,15,1}, /* core7 elr_EL1 bit45 */
			{17329,15,1}, /* core7 elr_EL1 bit46 */
			{17330,15,1}, /* core7 elr_EL1 bit47 */
			{17340,15,1}, /* core7 elr_EL1 bit48 */
			{17337,15,1}, /* core7 elr_EL1 bit49 */
			{17319,15,1}, /* core7 elr_EL1 bit50 */
			{11131,14,1}, /* core7 elr_EL1 bit51 */
			{11161,14,1}, /* core7 elr_EL1 bit52 */
			{11130,14,1}, /* core7 elr_EL1 bit53 */
			{17407,15,1}, /* core7 elr_EL1 bit54 */
			{11160,14,1}, /* core7 elr_EL1 bit55 */
			{11159,14,1}, /* core7 elr_EL1 bit56 */
			{11141,14,1}, /* core7 elr_EL1 bit57 */
			{11147,14,1}, /* core7 elr_EL1 bit58 */
			{11143,14,1}, /* core7 elr_EL1 bit59 */
			{11145,14,1}, /* core7 elr_EL1 bit60 */
			{11144,14,1}, /* core7 elr_EL1 bit61 */
			{11142,14,1}, /* core7 elr_EL1 bit62 */
			{11148,14,1}, /* core7 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{15278,14,1}, /* core7 elr_EL2 bit0 */
			{15267,14,1}, /* core7 elr_EL2 bit1 */
			{15264,14,1}, /* core7 elr_EL2 bit2 */
			{15268,14,1}, /* core7 elr_EL2 bit3 */
			{17578,15,1}, /* core7 elr_EL2 bit4 */
			{17454,15,1}, /* core7 elr_EL2 bit5 */
			{17455,15,1}, /* core7 elr_EL2 bit6 */
			{17456,15,1}, /* core7 elr_EL2 bit7 */
			{17579,15,1}, /* core7 elr_EL2 bit8 */
			{17580,15,1}, /* core7 elr_EL2 bit9 */
			{17424,15,1}, /* core7 elr_EL2 bit10 */
			{17581,15,1}, /* core7 elr_EL2 bit11 */
			{15256,14,1}, /* core7 elr_EL2 bit12 */
			{15257,14,1}, /* core7 elr_EL2 bit13 */
			{17582,15,1}, /* core7 elr_EL2 bit14 */
			{15266,14,1}, /* core7 elr_EL2 bit15 */
			{15321,14,1}, /* core7 elr_EL2 bit16 */
			{15255,14,1}, /* core7 elr_EL2 bit17 */
			{15275,14,1}, /* core7 elr_EL2 bit18 */
			{15620,14,1}, /* core7 elr_EL2 bit19 */
			{15627,14,1}, /* core7 elr_EL2 bit20 */
			{15626,14,1}, /* core7 elr_EL2 bit21 */
			{15621,14,1}, /* core7 elr_EL2 bit22 */
			{15740,14,1}, /* core7 elr_EL2 bit23 */
			{15612,14,1}, /* core7 elr_EL2 bit24 */
			{15643,14,1}, /* core7 elr_EL2 bit25 */
			{15622,14,1}, /* core7 elr_EL2 bit26 */
			{15631,14,1}, /* core7 elr_EL2 bit27 */
			{15623,14,1}, /* core7 elr_EL2 bit28 */
			{15625,14,1}, /* core7 elr_EL2 bit29 */
			{15644,14,1}, /* core7 elr_EL2 bit30 */
			{15254,14,1}, /* core7 elr_EL2 bit31 */
			{17257,15,1}, /* core7 elr_EL2 bit32 */
			{18130,15,1}, /* core7 elr_EL2 bit33 */
			{18131,15,1}, /* core7 elr_EL2 bit34 */
			{18095,15,1}, /* core7 elr_EL2 bit35 */
			{18096,15,1}, /* core7 elr_EL2 bit36 */
			{18137,15,1}, /* core7 elr_EL2 bit37 */
			{18134,15,1}, /* core7 elr_EL2 bit38 */
			{18139,15,1}, /* core7 elr_EL2 bit39 */
			{18136,15,1}, /* core7 elr_EL2 bit40 */
			{18102,15,1}, /* core7 elr_EL2 bit41 */
			{18133,15,1}, /* core7 elr_EL2 bit42 */
			{18132,15,1}, /* core7 elr_EL2 bit43 */
			{18097,15,1}, /* core7 elr_EL2 bit44 */
			{18135,15,1}, /* core7 elr_EL2 bit45 */
			{18138,15,1}, /* core7 elr_EL2 bit46 */
			{18101,15,1}, /* core7 elr_EL2 bit47 */
			{18094,15,1}, /* core7 elr_EL2 bit48 */
			{18100,15,1}, /* core7 elr_EL2 bit49 */
			{17256,15,1}, /* core7 elr_EL2 bit50 */
			{17280,15,1}, /* core7 elr_EL2 bit51 */
			{17259,15,1}, /* core7 elr_EL2 bit52 */
			{17277,15,1}, /* core7 elr_EL2 bit53 */
			{17279,15,1}, /* core7 elr_EL2 bit54 */
			{17283,15,1}, /* core7 elr_EL2 bit55 */
			{17284,15,1}, /* core7 elr_EL2 bit56 */
			{17288,15,1}, /* core7 elr_EL2 bit57 */
			{17293,15,1}, /* core7 elr_EL2 bit58 */
			{17285,15,1}, /* core7 elr_EL2 bit59 */
			{17282,15,1}, /* core7 elr_EL2 bit60 */
			{17287,15,1}, /* core7 elr_EL2 bit61 */
			{17289,15,1}, /* core7 elr_EL2 bit62 */
			{17290,15,1}, /* core7 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{13494,15,1}, /* core7 elr_EL3 bit0 */
			{13493,15,1}, /* core7 elr_EL3 bit1 */
			{13632,15,1}, /* core7 elr_EL3 bit2 */
			{13631,15,1}, /* core7 elr_EL3 bit3 */
			{17492,15,1}, /* core7 elr_EL3 bit4 */
			{17487,15,1}, /* core7 elr_EL3 bit5 */
			{17488,15,1}, /* core7 elr_EL3 bit6 */
			{17489,15,1}, /* core7 elr_EL3 bit7 */
			{17490,15,1}, /* core7 elr_EL3 bit8 */
			{17491,15,1}, /* core7 elr_EL3 bit9 */
			{15301,14,1}, /* core7 elr_EL3 bit10 */
			{17561,15,1}, /* core7 elr_EL3 bit11 */
			{15054,14,1}, /* core7 elr_EL3 bit12 */
			{15307,14,1}, /* core7 elr_EL3 bit13 */
			{17486,15,1}, /* core7 elr_EL3 bit14 */
			{15064,14,1}, /* core7 elr_EL3 bit15 */
			{15203,14,1}, /* core7 elr_EL3 bit16 */
			{15062,14,1}, /* core7 elr_EL3 bit17 */
			{15677,14,1}, /* core7 elr_EL3 bit18 */
			{11484,14,1}, /* core7 elr_EL3 bit19 */
			{15690,14,1}, /* core7 elr_EL3 bit20 */
			{11507,14,1}, /* core7 elr_EL3 bit21 */
			{11491,14,1}, /* core7 elr_EL3 bit22 */
			{11492,14,1}, /* core7 elr_EL3 bit23 */
			{15701,14,1}, /* core7 elr_EL3 bit24 */
			{11510,14,1}, /* core7 elr_EL3 bit25 */
			{11490,14,1}, /* core7 elr_EL3 bit26 */
			{15686,14,1}, /* core7 elr_EL3 bit27 */
			{11508,14,1}, /* core7 elr_EL3 bit28 */
			{11493,14,1}, /* core7 elr_EL3 bit29 */
			{11509,14,1}, /* core7 elr_EL3 bit30 */
			{15065,14,1}, /* core7 elr_EL3 bit31 */
			{11118,14,1}, /* core7 elr_EL3 bit32 */
			{17234,15,1}, /* core7 elr_EL3 bit33 */
			{17346,15,1}, /* core7 elr_EL3 bit34 */
			{17357,15,1}, /* core7 elr_EL3 bit35 */
			{17351,15,1}, /* core7 elr_EL3 bit36 */
			{17348,15,1}, /* core7 elr_EL3 bit37 */
			{17236,15,1}, /* core7 elr_EL3 bit38 */
			{17353,15,1}, /* core7 elr_EL3 bit39 */
			{17237,15,1}, /* core7 elr_EL3 bit40 */
			{18077,15,1}, /* core7 elr_EL3 bit41 */
			{17349,15,1}, /* core7 elr_EL3 bit42 */
			{17352,15,1}, /* core7 elr_EL3 bit43 */
			{17235,15,1}, /* core7 elr_EL3 bit44 */
			{17350,15,1}, /* core7 elr_EL3 bit45 */
			{17238,15,1}, /* core7 elr_EL3 bit46 */
			{18076,15,1}, /* core7 elr_EL3 bit47 */
			{17239,15,1}, /* core7 elr_EL3 bit48 */
			{17347,15,1}, /* core7 elr_EL3 bit49 */
			{17371,15,1}, /* core7 elr_EL3 bit50 */
			{17386,15,1}, /* core7 elr_EL3 bit51 */
			{17387,15,1}, /* core7 elr_EL3 bit52 */
			{11215,14,1}, /* core7 elr_EL3 bit53 */
			{11117,14,1}, /* core7 elr_EL3 bit54 */
			{11212,14,1}, /* core7 elr_EL3 bit55 */
			{11120,14,1}, /* core7 elr_EL3 bit56 */
			{11234,14,1}, /* core7 elr_EL3 bit57 */
			{11122,14,1}, /* core7 elr_EL3 bit58 */
			{11239,14,1}, /* core7 elr_EL3 bit59 */
			{11213,14,1}, /* core7 elr_EL3 bit60 */
			{11121,14,1}, /* core7 elr_EL3 bit61 */
			{13548,15,1}, /* core7 elr_EL3 bit62 */
			{13547,15,1}, /* core7 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{15226,15,1}, /* core7 raw_pc bit0 */
			{15255,15,1}, /* core7 raw_pc bit1 */
			{15251,15,1}, /* core7 raw_pc bit2 */
			{15230,15,1}, /* core7 raw_pc bit3 */
			{15228,15,1}, /* core7 raw_pc bit4 */
			{14840,14,1}, /* core7 raw_pc bit5 */
			{14839,14,1}, /* core7 raw_pc bit6 */
			{20632,15,1}, /* core7 raw_pc bit7 */
			{17806,14,1}, /* core7 raw_pc bit8 */
			{20630,15,1}, /* core7 raw_pc bit9 */
			{12195,14,1}, /* core7 raw_pc bit10 */
			{20641,15,1}, /* core7 raw_pc bit11 */
			{20637,15,1}, /* core7 raw_pc bit12 */
			{12194,14,1}, /* core7 raw_pc bit13 */
			{21641,15,1}, /* core7 raw_pc bit14 */
			{20636,15,1}, /* core7 raw_pc bit15 */
			{20628,15,1}, /* core7 raw_pc bit16 */
			{12197,14,1}, /* core7 raw_pc bit17 */
			{20629,15,1}, /* core7 raw_pc bit18 */
			{20640,15,1}, /* core7 raw_pc bit19 */
			{12203,14,1}, /* core7 raw_pc bit20 */
			{20642,15,1}, /* core7 raw_pc bit21 */
			{20639,15,1}, /* core7 raw_pc bit22 */
			{12206,14,1}, /* core7 raw_pc bit23 */
			{12196,14,1}, /* core7 raw_pc bit24 */
			{12204,14,1}, /* core7 raw_pc bit25 */
			{17807,14,1}, /* core7 raw_pc bit26 */
			{20638,15,1}, /* core7 raw_pc bit27 */
			{12205,14,1}, /* core7 raw_pc bit28 */
			{20643,15,1}, /* core7 raw_pc bit29 */
			{20644,15,1}, /* core7 raw_pc bit30 */
			{12207,14,1}, /* core7 raw_pc bit31 */
			{20648,15,1}, /* core7 raw_pc bit32 */
			{12210,14,1}, /* core7 raw_pc bit33 */
			{12213,14,1}, /* core7 raw_pc bit34 */
			{12214,14,1}, /* core7 raw_pc bit35 */
			{12211,14,1}, /* core7 raw_pc bit36 */
			{12212,14,1}, /* core7 raw_pc bit37 */
			{20647,15,1}, /* core7 raw_pc bit38 */
			{17729,14,1}, /* core7 raw_pc bit39 */
			{17728,14,1}, /* core7 raw_pc bit40 */
			{12215,14,1}, /* core7 raw_pc bit41 */
			{12209,14,1}, /* core7 raw_pc bit42 */
			{17727,14,1}, /* core7 raw_pc bit43 */
			{17726,14,1}, /* core7 raw_pc bit44 */
			{17725,14,1}, /* core7 raw_pc bit45 */
			{17724,14,1}, /* core7 raw_pc bit46 */
			{12208,14,1}, /* core7 raw_pc bit47 */
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
			{21613,15,1}, /* core7 pc_iss bit0 */
			{21579,15,1}, /* core7 pc_iss bit1 */
			{21629,15,1}, /* core7 pc_iss bit2 */
			{21616,15,1}, /* core7 pc_iss bit3 */
			{21630,15,1}, /* core7 pc_iss bit4 */
			{21612,15,1}, /* core7 pc_iss bit5 */
			{21614,15,1}, /* core7 pc_iss bit6 */
			{21615,15,1}, /* core7 pc_iss bit7 */
			{21278,15,1}, /* core7 pc_iss bit8 */
			{21257,15,1}, /* core7 pc_iss bit9 */
			{21265,15,1}, /* core7 pc_iss bit10 */
			{21264,15,1}, /* core7 pc_iss bit11 */
			{21256,15,1}, /* core7 pc_iss bit12 */
			{21259,15,1}, /* core7 pc_iss bit13 */
			{22041,15,1}, /* core7 pc_iss bit14 */
			{21255,15,1}, /* core7 pc_iss bit15 */
			{21281,15,1}, /* core7 pc_iss bit16 */
			{21239,15,1}, /* core7 pc_iss bit17 */
			{21258,15,1}, /* core7 pc_iss bit18 */
			{21280,15,1}, /* core7 pc_iss bit19 */
			{22042,15,1}, /* core7 pc_iss bit20 */
			{21260,15,1}, /* core7 pc_iss bit21 */
			{22043,15,1}, /* core7 pc_iss bit22 */
			{21279,15,1}, /* core7 pc_iss bit23 */
			{21262,15,1}, /* core7 pc_iss bit24 */
			{21263,15,1}, /* core7 pc_iss bit25 */
			{21261,15,1}, /* core7 pc_iss bit26 */
			{21244,15,1}, /* core7 pc_iss bit27 */
			{21240,15,1}, /* core7 pc_iss bit28 */
			{21241,15,1}, /* core7 pc_iss bit29 */
			{21242,15,1}, /* core7 pc_iss bit30 */
			{21243,15,1}, /* core7 pc_iss bit31 */
			{21237,15,1}, /* core7 pc_iss bit32 */
			{22054,15,1}, /* core7 pc_iss bit33 */
			{22053,15,1}, /* core7 pc_iss bit34 */
			{22056,15,1}, /* core7 pc_iss bit35 */
			{21228,15,1}, /* core7 pc_iss bit36 */
			{22048,15,1}, /* core7 pc_iss bit37 */
			{21232,15,1}, /* core7 pc_iss bit38 */
			{22046,15,1}, /* core7 pc_iss bit39 */
			{21233,15,1}, /* core7 pc_iss bit40 */
			{21238,15,1}, /* core7 pc_iss bit41 */
			{22058,15,1}, /* core7 pc_iss bit42 */
			{22051,15,1}, /* core7 pc_iss bit43 */
			{22052,15,1}, /* core7 pc_iss bit44 */
			{22055,15,1}, /* core7 pc_iss bit45 */
			{21235,15,1}, /* core7 pc_iss bit46 */
			{22050,15,1}, /* core7 pc_iss bit47 */
			{22059,15,1}, /* core7 pc_iss bit48 */
			{22057,15,1}, /* core7 pc_iss bit49 */
			{22060,15,1}, /* core7 pc_iss bit50 */
			{21231,15,1}, /* core7 pc_iss bit51 */
			{21236,15,1}, /* core7 pc_iss bit52 */
			{21234,15,1}, /* core7 pc_iss bit53 */
			{21230,15,1}, /* core7 pc_iss bit54 */
			{22047,15,1}, /* core7 pc_iss bit55 */
			{22049,15,1}, /* core7 pc_iss bit56 */
			{21229,15,1}, /* core7 pc_iss bit57 */
			{22062,15,1}, /* core7 pc_iss bit58 */
			{22061,15,1}, /* core7 pc_iss bit59 */
			{22064,15,1}, /* core7 pc_iss bit60 */
			{22063,15,1}, /* core7 pc_iss bit61 */
			{22066,15,1}, /* core7 pc_iss bit62 */
			{22065,15,1}, /* core7 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{15256,15,1}, /* core7 full_pc_wr bit0 */
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
			{15249,15,1}, /* core7 full_pc_ex1 bit0 */
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
			{15248,15,1}, /* core7 full_pc_ex2 bit0 */
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
