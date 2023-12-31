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
			.pc = {{
			{23475,15,0}, /* core0 pc bit0 */
			{23745,15,0}, /* core0 pc bit1 */
			{23431,15,0}, /* core0 pc bit2 */
			{23748,15,0}, /* core0 pc bit3 */
			{23472,15,0}, /* core0 pc bit4 */
			{23485,15,0}, /* core0 pc bit5 */
			{23494,15,0}, /* core0 pc bit6 */
			{23484,15,0}, /* core0 pc bit7 */
			{23497,15,0}, /* core0 pc bit8 */
			{23496,15,0}, /* core0 pc bit9 */
			{23501,15,0}, /* core0 pc bit10 */
			{23500,15,0}, /* core0 pc bit11 */
			{21881,11,1}, /* core0 pc bit12 */
			{23491,15,0}, /* core0 pc bit13 */
			{23468,15,0}, /* core0 pc bit14 */
			{23474,15,0}, /* core0 pc bit15 */
			{23430,15,0}, /* core0 pc bit16 */
			{23433,15,0}, /* core0 pc bit17 */
			{21338,15,0}, /* core0 pc bit18 */
			{23753,15,0}, /* core0 pc bit19 */
			{23752,15,0}, /* core0 pc bit20 */
			{23751,15,0}, /* core0 pc bit21 */
			{23750,15,0}, /* core0 pc bit22 */
			{23744,15,0}, /* core0 pc bit23 */
			{23759,15,0}, /* core0 pc bit24 */
			{21337,15,0}, /* core0 pc bit25 */
			{23764,15,0}, /* core0 pc bit26 */
			{23758,15,0}, /* core0 pc bit27 */
			{23755,15,0}, /* core0 pc bit28 */
			{23754,15,0}, /* core0 pc bit29 */
			{21335,15,0}, /* core0 pc bit30 */
			{21334,15,0}, /* core0 pc bit31 */
			{21357,15,0}, /* core0 pc bit32 */
			{21356,15,0}, /* core0 pc bit33 */
			{23757,15,0}, /* core0 pc bit34 */
			{21359,15,0}, /* core0 pc bit35 */
			{23490,15,0}, /* core0 pc bit36 */
			{23477,15,0}, /* core0 pc bit37 */
			{23476,15,0}, /* core0 pc bit38 */
			{23466,15,0}, /* core0 pc bit39 */
			{23479,15,0}, /* core0 pc bit40 */
			{23775,15,0}, /* core0 pc bit41 */
			{23774,15,0}, /* core0 pc bit42 */
			{23478,15,0}, /* core0 pc bit43 */
			{23481,15,0}, /* core0 pc bit44 */
			{10426,11,1}, /* core0 pc bit45 */
			{21329,15,0}, /* core0 pc bit46 */
			{21328,15,0}, /* core0 pc bit47 */
			{21358,15,0}, /* core0 pc bit48 */
			{10461,11,1}, /* core0 pc bit49 */
			{21355,15,0}, /* core0 pc bit50 */
			{21354,15,0}, /* core0 pc bit51 */
			{21377,15,0}, /* core0 pc bit52 */
			{21376,15,0}, /* core0 pc bit53 */
			{21353,15,0}, /* core0 pc bit54 */
			{21336,15,0}, /* core0 pc bit55 */
			{21351,15,0}, /* core0 pc bit56 */
			{21350,15,0}, /* core0 pc bit57 */
			{21375,15,0}, /* core0 pc bit58 */
			{21374,15,0}, /* core0 pc bit59 */
			{21341,15,0}, /* core0 pc bit60 */
			{21340,15,0}, /* core0 pc bit61 */
			{21343,15,0}, /* core0 pc bit62 */
			{21342,15,0}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{14975,15,1}, /* core0 sp32 bit0 */
			{14974,15,1}, /* core0 sp32 bit1 */
			{21822,11,1}, /* core0 sp32 bit2 */
			{23327,15,0}, /* core0 sp32 bit3 */
			{21824,11,1}, /* core0 sp32 bit4 */
			{21823,11,1}, /* core0 sp32 bit5 */
			{21820,11,1}, /* core0 sp32 bit6 */
			{21819,11,1}, /* core0 sp32 bit7 */
			{21816,11,1}, /* core0 sp32 bit8 */
			{21821,11,1}, /* core0 sp32 bit9 */
			{21815,11,1}, /* core0 sp32 bit10 */
			{15609,15,1}, /* core0 sp32 bit11 */
			{15608,15,1}, /* core0 sp32 bit12 */
			{21818,11,1}, /* core0 sp32 bit13 */
			{21817,11,1}, /* core0 sp32 bit14 */
			{20725,11,1}, /* core0 sp32 bit15 */
			{20109,15,0}, /* core0 sp32 bit16 */
			{10372,11,1}, /* core0 sp32 bit17 */
			{10371,11,1}, /* core0 sp32 bit18 */
			{22952,11,1}, /* core0 sp32 bit19 */
			{20108,15,0}, /* core0 sp32 bit20 */
			{20111,15,0}, /* core0 sp32 bit21 */
			{20110,15,0}, /* core0 sp32 bit22 */
			{22951,11,1}, /* core0 sp32 bit23 */
			{24341,15,0}, /* core0 sp32 bit24 */
			{23326,15,0}, /* core0 sp32 bit25 */
			{22369,15,0}, /* core0 sp32 bit26 */
			{22368,15,0}, /* core0 sp32 bit27 */
			{22371,15,0}, /* core0 sp32 bit28 */
			{22370,15,0}, /* core0 sp32 bit29 */
			{10391,11,1}, /* core0 sp32 bit30 */
			{24340,15,0}, /* core0 sp32 bit31 */
			{20815,15,0}, /* core0 sp32 bit32 */
			{20814,15,0}, /* core0 sp32 bit33 */
			{19941,15,0}, /* core0 sp32 bit34 */
			{19940,15,0}, /* core0 sp32 bit35 */
			{19943,15,0}, /* core0 sp32 bit36 */
			{19942,15,0}, /* core0 sp32 bit37 */
			{20853,15,0}, /* core0 sp32 bit38 */
			{20852,15,0}, /* core0 sp32 bit39 */
			{19945,15,0}, /* core0 sp32 bit40 */
			{19944,15,0}, /* core0 sp32 bit41 */
			{10529,11,1}, /* core0 sp32 bit42 */
			{20023,15,0}, /* core0 sp32 bit43 */
			{20022,15,0}, /* core0 sp32 bit44 */
			{20021,15,0}, /* core0 sp32 bit45 */
			{20020,15,0}, /* core0 sp32 bit46 */
			{20575,15,0}, /* core0 sp32 bit47 */
			{20574,15,0}, /* core0 sp32 bit48 */
			{20419,15,0}, /* core0 sp32 bit49 */
			{20417,15,0}, /* core0 sp32 bit50 */
			{20416,15,0}, /* core0 sp32 bit51 */
			{20415,15,0}, /* core0 sp32 bit52 */
			{20414,15,0}, /* core0 sp32 bit53 */
			{20413,15,0}, /* core0 sp32 bit54 */
			{20412,15,0}, /* core0 sp32 bit55 */
			{20585,15,0}, /* core0 sp32 bit56 */
			{20584,15,0}, /* core0 sp32 bit57 */
			{20425,15,0}, /* core0 sp32 bit58 */
			{20424,15,0}, /* core0 sp32 bit59 */
			{11036,11,1}, /* core0 sp32 bit60 */
			{20418,15,0}, /* core0 sp32 bit61 */
			{11035,11,1}, /* core0 sp32 bit62 */
			{22394,11,0}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{14883,15,1}, /* core0 fp32 bit0 */
			{14882,15,1}, /* core0 fp32 bit1 */
			{23040,11,1}, /* core0 fp32 bit2 */
			{10868,11,0}, /* core0 fp32 bit3 */
			{20151,15,0}, /* core0 fp32 bit4 */
			{20150,15,0}, /* core0 fp32 bit5 */
			{10950,11,0}, /* core0 fp32 bit6 */
			{10949,11,0}, /* core0 fp32 bit7 */
			{10948,11,0}, /* core0 fp32 bit8 */
			{10947,11,0}, /* core0 fp32 bit9 */
			{11478,11,0}, /* core0 fp32 bit10 */
			{11477,11,0}, /* core0 fp32 bit11 */
			{20081,15,0}, /* core0 fp32 bit12 */
			{20080,15,0}, /* core0 fp32 bit13 */
			{20099,15,0}, /* core0 fp32 bit14 */
			{20098,15,0}, /* core0 fp32 bit15 */
			{10867,11,0}, /* core0 fp32 bit16 */
			{10886,11,0}, /* core0 fp32 bit17 */
			{10885,11,0}, /* core0 fp32 bit18 */
			{10882,11,0}, /* core0 fp32 bit19 */
			{23312,11,0}, /* core0 fp32 bit20 */
			{10881,11,0}, /* core0 fp32 bit21 */
			{23039,11,1}, /* core0 fp32 bit22 */
			{23006,11,1}, /* core0 fp32 bit23 */
			{22944,11,1}, /* core0 fp32 bit24 */
			{23005,11,1}, /* core0 fp32 bit25 */
			{22978,11,1}, /* core0 fp32 bit26 */
			{22943,11,1}, /* core0 fp32 bit27 */
			{22942,11,1}, /* core0 fp32 bit28 */
			{22977,11,1}, /* core0 fp32 bit29 */
			{23316,11,0}, /* core0 fp32 bit30 */
			{22941,11,1}, /* core0 fp32 bit31 */
			{19545,15,0}, /* core0 fp32 bit32 */
			{19544,15,0}, /* core0 fp32 bit33 */
			{19547,15,0}, /* core0 fp32 bit34 */
			{19546,15,0}, /* core0 fp32 bit35 */
			{19289,15,0}, /* core0 fp32 bit36 */
			{19288,15,0}, /* core0 fp32 bit37 */
			{20357,15,0}, /* core0 fp32 bit38 */
			{20356,15,0}, /* core0 fp32 bit39 */
			{19575,15,0}, /* core0 fp32 bit40 */
			{10593,11,1}, /* core0 fp32 bit41 */
			{19574,15,0}, /* core0 fp32 bit42 */
			{20825,15,0}, /* core0 fp32 bit43 */
			{20824,15,0}, /* core0 fp32 bit44 */
			{20009,15,0}, /* core0 fp32 bit45 */
			{20008,15,0}, /* core0 fp32 bit46 */
			{20373,15,0}, /* core0 fp32 bit47 */
			{20372,15,0}, /* core0 fp32 bit48 */
			{20353,15,0}, /* core0 fp32 bit49 */
			{20345,15,0}, /* core0 fp32 bit50 */
			{20344,15,0}, /* core0 fp32 bit51 */
			{20343,15,0}, /* core0 fp32 bit52 */
			{20342,15,0}, /* core0 fp32 bit53 */
			{20393,15,0}, /* core0 fp32 bit54 */
			{20392,15,0}, /* core0 fp32 bit55 */
			{20391,15,0}, /* core0 fp32 bit56 */
			{20390,15,0}, /* core0 fp32 bit57 */
			{20395,15,0}, /* core0 fp32 bit58 */
			{20394,15,0}, /* core0 fp32 bit59 */
			{11019,11,1}, /* core0 fp32 bit60 */
			{20352,15,0}, /* core0 fp32 bit61 */
			{11027,11,1}, /* core0 fp32 bit62 */
			{10587,11,1}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{21567,15,0}, /* core0 fp64 bit0 */
			{21566,15,0}, /* core0 fp64 bit1 */
			{21565,15,0}, /* core0 fp64 bit2 */
			{21564,15,0}, /* core0 fp64 bit3 */
			{22473,15,0}, /* core0 fp64 bit4 */
			{22472,15,0}, /* core0 fp64 bit5 */
			{22467,15,0}, /* core0 fp64 bit6 */
			{22466,15,0}, /* core0 fp64 bit7 */
			{22645,15,0}, /* core0 fp64 bit8 */
			{22644,15,0}, /* core0 fp64 bit9 */
			{22469,15,0}, /* core0 fp64 bit10 */
			{22468,15,0}, /* core0 fp64 bit11 */
			{22471,15,0}, /* core0 fp64 bit12 */
			{22470,15,0}, /* core0 fp64 bit13 */
			{22603,15,0}, /* core0 fp64 bit14 */
			{22602,15,0}, /* core0 fp64 bit15 */
			{22599,15,0}, /* core0 fp64 bit16 */
			{22598,15,0}, /* core0 fp64 bit17 */
			{22429,15,0}, /* core0 fp64 bit18 */
			{22428,15,0}, /* core0 fp64 bit19 */
			{22597,15,0}, /* core0 fp64 bit20 */
			{22596,15,0}, /* core0 fp64 bit21 */
			{23405,15,0}, /* core0 fp64 bit22 */
			{23407,15,0}, /* core0 fp64 bit23 */
			{23406,15,0}, /* core0 fp64 bit24 */
			{23391,15,0}, /* core0 fp64 bit25 */
			{23390,15,0}, /* core0 fp64 bit26 */
			{23387,15,0}, /* core0 fp64 bit27 */
			{10454,11,1}, /* core0 fp64 bit28 */
			{23386,15,0}, /* core0 fp64 bit29 */
			{10455,11,1}, /* core0 fp64 bit30 */
			{23404,15,0}, /* core0 fp64 bit31 */
			{19355,15,0}, /* core0 fp64 bit32 */
			{19354,15,0}, /* core0 fp64 bit33 */
			{19349,15,0}, /* core0 fp64 bit34 */
			{19348,15,0}, /* core0 fp64 bit35 */
			{19375,15,0}, /* core0 fp64 bit36 */
			{19374,15,0}, /* core0 fp64 bit37 */
			{20951,15,0}, /* core0 fp64 bit38 */
			{20950,15,0}, /* core0 fp64 bit39 */
			{20909,15,0}, /* core0 fp64 bit40 */
			{20908,15,0}, /* core0 fp64 bit41 */
			{20911,15,0}, /* core0 fp64 bit42 */
			{20915,15,0}, /* core0 fp64 bit43 */
			{20910,15,0}, /* core0 fp64 bit44 */
			{20914,15,0}, /* core0 fp64 bit45 */
			{10605,11,1}, /* core0 fp64 bit46 */
			{19677,15,0}, /* core0 fp64 bit47 */
			{19676,15,0}, /* core0 fp64 bit48 */
			{19671,15,0}, /* core0 fp64 bit49 */
			{19715,15,0}, /* core0 fp64 bit50 */
			{19714,15,0}, /* core0 fp64 bit51 */
			{19719,15,0}, /* core0 fp64 bit52 */
			{19718,15,0}, /* core0 fp64 bit53 */
			{19721,15,0}, /* core0 fp64 bit54 */
			{19720,15,0}, /* core0 fp64 bit55 */
			{19670,15,0}, /* core0 fp64 bit56 */
			{19717,15,0}, /* core0 fp64 bit57 */
			{19716,15,0}, /* core0 fp64 bit58 */
			{19713,15,0}, /* core0 fp64 bit59 */
			{19712,15,0}, /* core0 fp64 bit60 */
			{19675,15,0}, /* core0 fp64 bit61 */
			{19674,15,0}, /* core0 fp64 bit62 */
			{10544,11,1}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{24337,15,0}, /* core0 sp_EL0 bit0 */
			{24336,15,0}, /* core0 sp_EL0 bit1 */
			{24335,15,0}, /* core0 sp_EL0 bit2 */
			{24334,15,0}, /* core0 sp_EL0 bit3 */
			{21282,11,1}, /* core0 sp_EL0 bit4 */
			{21281,11,1}, /* core0 sp_EL0 bit5 */
			{21284,11,1}, /* core0 sp_EL0 bit6 */
			{21283,11,1}, /* core0 sp_EL0 bit7 */
			{21311,15,0}, /* core0 sp_EL0 bit8 */
			{21310,15,0}, /* core0 sp_EL0 bit9 */
			{20969,11,1}, /* core0 sp_EL0 bit10 */
			{20968,11,1}, /* core0 sp_EL0 bit11 */
			{20971,11,1}, /* core0 sp_EL0 bit12 */
			{20970,11,1}, /* core0 sp_EL0 bit13 */
			{22455,15,0}, /* core0 sp_EL0 bit14 */
			{22454,15,0}, /* core0 sp_EL0 bit15 */
			{10419,11,1}, /* core0 sp_EL0 bit16 */
			{22591,15,0}, /* core0 sp_EL0 bit17 */
			{22590,15,0}, /* core0 sp_EL0 bit18 */
			{22435,15,0}, /* core0 sp_EL0 bit19 */
			{22434,15,0}, /* core0 sp_EL0 bit20 */
			{22587,15,0}, /* core0 sp_EL0 bit21 */
			{22586,15,0}, /* core0 sp_EL0 bit22 */
			{22579,15,0}, /* core0 sp_EL0 bit23 */
			{22578,15,0}, /* core0 sp_EL0 bit24 */
			{24313,15,0}, /* core0 sp_EL0 bit25 */
			{24312,15,0}, /* core0 sp_EL0 bit26 */
			{23367,15,0}, /* core0 sp_EL0 bit27 */
			{23365,15,0}, /* core0 sp_EL0 bit28 */
			{23364,15,0}, /* core0 sp_EL0 bit29 */
			{23366,15,0}, /* core0 sp_EL0 bit30 */
			{10449,11,1}, /* core0 sp_EL0 bit31 */
			{19341,15,0}, /* core0 sp_EL0 bit32 */
			{19340,15,0}, /* core0 sp_EL0 bit33 */
			{19679,15,0}, /* core0 sp_EL0 bit34 */
			{19678,15,0}, /* core0 sp_EL0 bit35 */
			{19311,15,0}, /* core0 sp_EL0 bit36 */
			{19310,15,0}, /* core0 sp_EL0 bit37 */
			{19369,15,0}, /* core0 sp_EL0 bit38 */
			{19368,15,0}, /* core0 sp_EL0 bit39 */
			{19367,15,0}, /* core0 sp_EL0 bit40 */
			{19366,15,0}, /* core0 sp_EL0 bit41 */
			{20945,15,0}, /* core0 sp_EL0 bit42 */
			{20944,15,0}, /* core0 sp_EL0 bit43 */
			{19377,15,0}, /* core0 sp_EL0 bit44 */
			{10541,11,1}, /* core0 sp_EL0 bit45 */
			{19376,15,0}, /* core0 sp_EL0 bit46 */
			{19683,15,0}, /* core0 sp_EL0 bit47 */
			{19682,15,0}, /* core0 sp_EL0 bit48 */
			{19663,15,0}, /* core0 sp_EL0 bit49 */
			{20713,15,0}, /* core0 sp_EL0 bit50 */
			{20712,15,0}, /* core0 sp_EL0 bit51 */
			{20707,15,0}, /* core0 sp_EL0 bit52 */
			{20706,15,0}, /* core0 sp_EL0 bit53 */
			{20709,15,0}, /* core0 sp_EL0 bit54 */
			{20708,15,0}, /* core0 sp_EL0 bit55 */
			{19662,15,0}, /* core0 sp_EL0 bit56 */
			{20711,15,0}, /* core0 sp_EL0 bit57 */
			{20710,15,0}, /* core0 sp_EL0 bit58 */
			{11046,11,1}, /* core0 sp_EL0 bit59 */
			{23293,15,0}, /* core0 sp_EL0 bit60 */
			{23292,15,0}, /* core0 sp_EL0 bit61 */
			{23291,15,0}, /* core0 sp_EL0 bit62 */
			{23290,15,0}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{24351,15,0}, /* core0 sp_EL1 bit0 */
			{24350,15,0}, /* core0 sp_EL1 bit1 */
			{24349,15,0}, /* core0 sp_EL1 bit2 */
			{24348,15,0}, /* core0 sp_EL1 bit3 */
			{22461,15,0}, /* core0 sp_EL1 bit4 */
			{22460,15,0}, /* core0 sp_EL1 bit5 */
			{22647,15,0}, /* core0 sp_EL1 bit6 */
			{22646,15,0}, /* core0 sp_EL1 bit7 */
			{22601,15,0}, /* core0 sp_EL1 bit8 */
			{22600,15,0}, /* core0 sp_EL1 bit9 */
			{22649,15,0}, /* core0 sp_EL1 bit10 */
			{22648,15,0}, /* core0 sp_EL1 bit11 */
			{22463,15,0}, /* core0 sp_EL1 bit12 */
			{22462,15,0}, /* core0 sp_EL1 bit13 */
			{22457,15,0}, /* core0 sp_EL1 bit14 */
			{22456,15,0}, /* core0 sp_EL1 bit15 */
			{22595,15,0}, /* core0 sp_EL1 bit16 */
			{22594,15,0}, /* core0 sp_EL1 bit17 */
			{22427,15,0}, /* core0 sp_EL1 bit18 */
			{23403,15,0}, /* core0 sp_EL1 bit19 */
			{22426,15,0}, /* core0 sp_EL1 bit20 */
			{22431,15,0}, /* core0 sp_EL1 bit21 */
			{22430,15,0}, /* core0 sp_EL1 bit22 */
			{23402,15,0}, /* core0 sp_EL1 bit23 */
			{23389,15,0}, /* core0 sp_EL1 bit24 */
			{23388,15,0}, /* core0 sp_EL1 bit25 */
			{23385,15,0}, /* core0 sp_EL1 bit26 */
			{23384,15,0}, /* core0 sp_EL1 bit27 */
			{10453,11,1}, /* core0 sp_EL1 bit28 */
			{23383,15,0}, /* core0 sp_EL1 bit29 */
			{23382,15,0}, /* core0 sp_EL1 bit30 */
			{10439,11,1}, /* core0 sp_EL1 bit31 */
			{19353,15,0}, /* core0 sp_EL1 bit32 */
			{19352,15,0}, /* core0 sp_EL1 bit33 */
			{19351,15,0}, /* core0 sp_EL1 bit34 */
			{19350,15,0}, /* core0 sp_EL1 bit35 */
			{19379,15,0}, /* core0 sp_EL1 bit36 */
			{19378,15,0}, /* core0 sp_EL1 bit37 */
			{19373,15,0}, /* core0 sp_EL1 bit38 */
			{19372,15,0}, /* core0 sp_EL1 bit39 */
			{20947,15,0}, /* core0 sp_EL1 bit40 */
			{20949,15,0}, /* core0 sp_EL1 bit41 */
			{20946,15,0}, /* core0 sp_EL1 bit42 */
			{20948,15,0}, /* core0 sp_EL1 bit43 */
			{20913,15,0}, /* core0 sp_EL1 bit44 */
			{20912,15,0}, /* core0 sp_EL1 bit45 */
			{10604,11,1}, /* core0 sp_EL1 bit46 */
			{19673,15,0}, /* core0 sp_EL1 bit47 */
			{19672,15,0}, /* core0 sp_EL1 bit48 */
			{19603,15,0}, /* core0 sp_EL1 bit49 */
			{19703,15,0}, /* core0 sp_EL1 bit50 */
			{19702,15,0}, /* core0 sp_EL1 bit51 */
			{19709,15,0}, /* core0 sp_EL1 bit52 */
			{19708,15,0}, /* core0 sp_EL1 bit53 */
			{19707,15,0}, /* core0 sp_EL1 bit54 */
			{19706,15,0}, /* core0 sp_EL1 bit55 */
			{19602,15,0}, /* core0 sp_EL1 bit56 */
			{19711,15,0}, /* core0 sp_EL1 bit57 */
			{19710,15,0}, /* core0 sp_EL1 bit58 */
			{19705,15,0}, /* core0 sp_EL1 bit59 */
			{19704,15,0}, /* core0 sp_EL1 bit60 */
			{19347,15,0}, /* core0 sp_EL1 bit61 */
			{19346,15,0}, /* core0 sp_EL1 bit62 */
			{10543,11,1}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 9416,11,0}, /* core0 sp_EL2 bit0 */
			{ 9415,11,0}, /* core0 sp_EL2 bit1 */
			{ 9414,11,0}, /* core0 sp_EL2 bit2 */
			{ 9413,11,0}, /* core0 sp_EL2 bit3 */
			{21307,15,0}, /* core0 sp_EL2 bit4 */
			{21306,15,0}, /* core0 sp_EL2 bit5 */
			{21317,15,0}, /* core0 sp_EL2 bit6 */
			{21316,15,0}, /* core0 sp_EL2 bit7 */
			{21315,15,0}, /* core0 sp_EL2 bit8 */
			{21314,15,0}, /* core0 sp_EL2 bit9 */
			{21313,15,0}, /* core0 sp_EL2 bit10 */
			{21312,15,0}, /* core0 sp_EL2 bit11 */
			{21309,15,0}, /* core0 sp_EL2 bit12 */
			{21308,15,0}, /* core0 sp_EL2 bit13 */
			{21321,15,0}, /* core0 sp_EL2 bit14 */
			{21320,15,0}, /* core0 sp_EL2 bit15 */
			{22433,15,0}, /* core0 sp_EL2 bit16 */
			{22432,15,0}, /* core0 sp_EL2 bit17 */
			{22707,15,0}, /* core0 sp_EL2 bit18 */
			{22706,15,0}, /* core0 sp_EL2 bit19 */
			{10416,11,1}, /* core0 sp_EL2 bit20 */
			{22585,15,0}, /* core0 sp_EL2 bit21 */
			{22584,15,0}, /* core0 sp_EL2 bit22 */
			{22581,15,0}, /* core0 sp_EL2 bit23 */
			{22580,15,0}, /* core0 sp_EL2 bit24 */
			{22409,15,0}, /* core0 sp_EL2 bit25 */
			{22408,15,0}, /* core0 sp_EL2 bit26 */
			{24323,15,0}, /* core0 sp_EL2 bit27 */
			{24322,15,0}, /* core0 sp_EL2 bit28 */
			{22571,15,0}, /* core0 sp_EL2 bit29 */
			{22570,15,0}, /* core0 sp_EL2 bit30 */
			{10450,11,1}, /* core0 sp_EL2 bit31 */
			{19299,15,0}, /* core0 sp_EL2 bit32 */
			{19298,15,0}, /* core0 sp_EL2 bit33 */
			{19297,15,0}, /* core0 sp_EL2 bit34 */
			{19296,15,0}, /* core0 sp_EL2 bit35 */
			{19329,15,0}, /* core0 sp_EL2 bit36 */
			{10560,11,1}, /* core0 sp_EL2 bit37 */
			{19328,15,0}, /* core0 sp_EL2 bit38 */
			{20929,15,0}, /* core0 sp_EL2 bit39 */
			{20928,15,0}, /* core0 sp_EL2 bit40 */
			{20931,15,0}, /* core0 sp_EL2 bit41 */
			{20930,15,0}, /* core0 sp_EL2 bit42 */
			{23311,15,0}, /* core0 sp_EL2 bit43 */
			{23310,15,0}, /* core0 sp_EL2 bit44 */
			{23309,15,0}, /* core0 sp_EL2 bit45 */
			{23308,15,0}, /* core0 sp_EL2 bit46 */
			{19651,15,0}, /* core0 sp_EL2 bit47 */
			{20669,15,0}, /* core0 sp_EL2 bit48 */
			{19650,15,0}, /* core0 sp_EL2 bit49 */
			{20668,15,0}, /* core0 sp_EL2 bit50 */
			{20617,15,0}, /* core0 sp_EL2 bit51 */
			{20616,15,0}, /* core0 sp_EL2 bit52 */
			{20601,15,0}, /* core0 sp_EL2 bit53 */
			{20600,15,0}, /* core0 sp_EL2 bit54 */
			{20603,15,0}, /* core0 sp_EL2 bit55 */
			{20629,15,0}, /* core0 sp_EL2 bit56 */
			{20602,15,0}, /* core0 sp_EL2 bit57 */
			{20613,15,0}, /* core0 sp_EL2 bit58 */
			{20612,15,0}, /* core0 sp_EL2 bit59 */
			{11044,11,1}, /* core0 sp_EL2 bit60 */
			{20628,15,0}, /* core0 sp_EL2 bit61 */
			{11045,11,1}, /* core0 sp_EL2 bit62 */
			{10559,11,1}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{23371,15,0}, /* core0 sp_EL3 bit0 */
			{22411,15,0}, /* core0 sp_EL3 bit1 */
			{23370,15,0}, /* core0 sp_EL3 bit2 */
			{10452,11,1}, /* core0 sp_EL3 bit3 */
			{22653,15,0}, /* core0 sp_EL3 bit4 */
			{22652,15,0}, /* core0 sp_EL3 bit5 */
			{22651,15,0}, /* core0 sp_EL3 bit6 */
			{22650,15,0}, /* core0 sp_EL3 bit7 */
			{22659,15,0}, /* core0 sp_EL3 bit8 */
			{22658,15,0}, /* core0 sp_EL3 bit9 */
			{22655,15,0}, /* core0 sp_EL3 bit10 */
			{22654,15,0}, /* core0 sp_EL3 bit11 */
			{22657,15,0}, /* core0 sp_EL3 bit12 */
			{22656,15,0}, /* core0 sp_EL3 bit13 */
			{10420,11,1}, /* core0 sp_EL3 bit14 */
			{22661,15,0}, /* core0 sp_EL3 bit15 */
			{22660,15,0}, /* core0 sp_EL3 bit16 */
			{22593,15,0}, /* core0 sp_EL3 bit17 */
			{22589,15,0}, /* core0 sp_EL3 bit18 */
			{22588,15,0}, /* core0 sp_EL3 bit19 */
			{22592,15,0}, /* core0 sp_EL3 bit20 */
			{23411,15,0}, /* core0 sp_EL3 bit21 */
			{23410,15,0}, /* core0 sp_EL3 bit22 */
			{22410,15,0}, /* core0 sp_EL3 bit23 */
			{23409,15,0}, /* core0 sp_EL3 bit24 */
			{23408,15,0}, /* core0 sp_EL3 bit25 */
			{23719,15,0}, /* core0 sp_EL3 bit26 */
			{23718,15,0}, /* core0 sp_EL3 bit27 */
			{23373,15,0}, /* core0 sp_EL3 bit28 */
			{23372,15,0}, /* core0 sp_EL3 bit29 */
			{23381,15,0}, /* core0 sp_EL3 bit30 */
			{23380,15,0}, /* core0 sp_EL3 bit31 */
			{19309,15,0}, /* core0 sp_EL3 bit32 */
			{19308,15,0}, /* core0 sp_EL3 bit33 */
			{19359,15,0}, /* core0 sp_EL3 bit34 */
			{19357,15,0}, /* core0 sp_EL3 bit35 */
			{19356,15,0}, /* core0 sp_EL3 bit36 */
			{19365,15,0}, /* core0 sp_EL3 bit37 */
			{19364,15,0}, /* core0 sp_EL3 bit38 */
			{19363,15,0}, /* core0 sp_EL3 bit39 */
			{19362,15,0}, /* core0 sp_EL3 bit40 */
			{20943,15,0}, /* core0 sp_EL3 bit41 */
			{20942,15,0}, /* core0 sp_EL3 bit42 */
			{20941,15,0}, /* core0 sp_EL3 bit43 */
			{20940,15,0}, /* core0 sp_EL3 bit44 */
			{10557,11,1}, /* core0 sp_EL3 bit45 */
			{19358,15,0}, /* core0 sp_EL3 bit46 */
			{19657,15,0}, /* core0 sp_EL3 bit47 */
			{19699,15,0}, /* core0 sp_EL3 bit48 */
			{19656,15,0}, /* core0 sp_EL3 bit49 */
			{20691,15,0}, /* core0 sp_EL3 bit50 */
			{19698,15,0}, /* core0 sp_EL3 bit51 */
			{20690,15,0}, /* core0 sp_EL3 bit52 */
			{20673,15,0}, /* core0 sp_EL3 bit53 */
			{20683,15,0}, /* core0 sp_EL3 bit54 */
			{20682,15,0}, /* core0 sp_EL3 bit55 */
			{20672,15,0}, /* core0 sp_EL3 bit56 */
			{20671,15,0}, /* core0 sp_EL3 bit57 */
			{20670,15,0}, /* core0 sp_EL3 bit58 */
			{20681,15,0}, /* core0 sp_EL3 bit59 */
			{20680,15,0}, /* core0 sp_EL3 bit60 */
			{19659,15,0}, /* core0 sp_EL3 bit61 */
			{19658,15,0}, /* core0 sp_EL3 bit62 */
			{10551,11,1}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{24321,15,0}, /* core0 elr_EL1 bit0 */
			{24320,15,0}, /* core0 elr_EL1 bit1 */
			{24319,15,0}, /* core0 elr_EL1 bit2 */
			{24318,15,0}, /* core0 elr_EL1 bit3 */
			{23789,15,0}, /* core0 elr_EL1 bit4 */
			{23788,15,0}, /* core0 elr_EL1 bit5 */
			{22451,15,0}, /* core0 elr_EL1 bit6 */
			{22450,15,0}, /* core0 elr_EL1 bit7 */
			{22453,15,0}, /* core0 elr_EL1 bit8 */
			{22452,15,0}, /* core0 elr_EL1 bit9 */
			{21305,15,0}, /* core0 elr_EL1 bit10 */
			{21304,15,0}, /* core0 elr_EL1 bit11 */
			{22449,15,0}, /* core0 elr_EL1 bit12 */
			{22448,15,0}, /* core0 elr_EL1 bit13 */
			{10418,11,1}, /* core0 elr_EL1 bit14 */
			{22667,15,0}, /* core0 elr_EL1 bit15 */
			{22666,15,0}, /* core0 elr_EL1 bit16 */
			{22669,15,0}, /* core0 elr_EL1 bit17 */
			{22703,15,0}, /* core0 elr_EL1 bit18 */
			{22702,15,0}, /* core0 elr_EL1 bit19 */
			{22668,15,0}, /* core0 elr_EL1 bit20 */
			{22405,15,0}, /* core0 elr_EL1 bit21 */
			{22407,15,0}, /* core0 elr_EL1 bit22 */
			{22406,15,0}, /* core0 elr_EL1 bit23 */
			{22404,15,0}, /* core0 elr_EL1 bit24 */
			{23379,15,0}, /* core0 elr_EL1 bit25 */
			{23378,15,0}, /* core0 elr_EL1 bit26 */
			{22415,15,0}, /* core0 elr_EL1 bit27 */
			{10451,11,1}, /* core0 elr_EL1 bit28 */
			{22414,15,0}, /* core0 elr_EL1 bit29 */
			{22413,15,0}, /* core0 elr_EL1 bit30 */
			{22412,15,0}, /* core0 elr_EL1 bit31 */
			{19307,15,0}, /* core0 elr_EL1 bit32 */
			{19306,15,0}, /* core0 elr_EL1 bit33 */
			{19641,15,0}, /* core0 elr_EL1 bit34 */
			{19640,15,0}, /* core0 elr_EL1 bit35 */
			{10555,11,1}, /* core0 elr_EL1 bit36 */
			{19321,15,0}, /* core0 elr_EL1 bit37 */
			{19320,15,0}, /* core0 elr_EL1 bit38 */
			{19317,15,0}, /* core0 elr_EL1 bit39 */
			{19316,15,0}, /* core0 elr_EL1 bit40 */
			{20923,15,0}, /* core0 elr_EL1 bit41 */
			{20922,15,0}, /* core0 elr_EL1 bit42 */
			{20917,15,0}, /* core0 elr_EL1 bit43 */
			{20916,15,0}, /* core0 elr_EL1 bit44 */
			{20939,15,0}, /* core0 elr_EL1 bit45 */
			{20938,15,0}, /* core0 elr_EL1 bit46 */
			{19667,15,0}, /* core0 elr_EL1 bit47 */
			{19599,15,0}, /* core0 elr_EL1 bit48 */
			{19666,15,0}, /* core0 elr_EL1 bit49 */
			{19598,15,0}, /* core0 elr_EL1 bit50 */
			{19701,15,0}, /* core0 elr_EL1 bit51 */
			{19700,15,0}, /* core0 elr_EL1 bit52 */
			{19597,15,0}, /* core0 elr_EL1 bit53 */
			{19596,15,0}, /* core0 elr_EL1 bit54 */
			{20699,15,0}, /* core0 elr_EL1 bit55 */
			{19665,15,0}, /* core0 elr_EL1 bit56 */
			{20698,15,0}, /* core0 elr_EL1 bit57 */
			{20701,15,0}, /* core0 elr_EL1 bit58 */
			{20700,15,0}, /* core0 elr_EL1 bit59 */
			{10237,11,1}, /* core0 elr_EL1 bit60 */
			{19664,15,0}, /* core0 elr_EL1 bit61 */
			{10238,11,1}, /* core0 elr_EL1 bit62 */
			{10556,11,1}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{10445,11,1}, /* core0 elr_EL2 bit0 */
			{23333,15,0}, /* core0 elr_EL2 bit1 */
			{23332,15,0}, /* core0 elr_EL2 bit2 */
			{23337,15,0}, /* core0 elr_EL2 bit3 */
			{21299,15,0}, /* core0 elr_EL2 bit4 */
			{21298,15,0}, /* core0 elr_EL2 bit5 */
			{21303,15,0}, /* core0 elr_EL2 bit6 */
			{21302,15,0}, /* core0 elr_EL2 bit7 */
			{22447,15,0}, /* core0 elr_EL2 bit8 */
			{22446,15,0}, /* core0 elr_EL2 bit9 */
			{21301,15,0}, /* core0 elr_EL2 bit10 */
			{21300,15,0}, /* core0 elr_EL2 bit11 */
			{22445,15,0}, /* core0 elr_EL2 bit12 */
			{22444,15,0}, /* core0 elr_EL2 bit13 */
			{22441,15,0}, /* core0 elr_EL2 bit14 */
			{22440,15,0}, /* core0 elr_EL2 bit15 */
			{22679,15,0}, /* core0 elr_EL2 bit16 */
			{22678,15,0}, /* core0 elr_EL2 bit17 */
			{22685,15,0}, /* core0 elr_EL2 bit18 */
			{22684,15,0}, /* core0 elr_EL2 bit19 */
			{22677,15,0}, /* core0 elr_EL2 bit20 */
			{22676,15,0}, /* core0 elr_EL2 bit21 */
			{22689,15,0}, /* core0 elr_EL2 bit22 */
			{23335,15,0}, /* core0 elr_EL2 bit23 */
			{22688,15,0}, /* core0 elr_EL2 bit24 */
			{23336,15,0}, /* core0 elr_EL2 bit25 */
			{23345,15,0}, /* core0 elr_EL2 bit26 */
			{23344,15,0}, /* core0 elr_EL2 bit27 */
			{23334,15,0}, /* core0 elr_EL2 bit28 */
			{14893,15,1}, /* core0 elr_EL2 bit29 */
			{14892,15,1}, /* core0 elr_EL2 bit30 */
			{10442,11,1}, /* core0 elr_EL2 bit31 */
			{19301,15,0}, /* core0 elr_EL2 bit32 */
			{19300,15,0}, /* core0 elr_EL2 bit33 */
			{19647,15,0}, /* core0 elr_EL2 bit34 */
			{19646,15,0}, /* core0 elr_EL2 bit35 */
			{19337,15,0}, /* core0 elr_EL2 bit36 */
			{19336,15,0}, /* core0 elr_EL2 bit37 */
			{19639,15,0}, /* core0 elr_EL2 bit38 */
			{19638,15,0}, /* core0 elr_EL2 bit39 */
			{20925,15,0}, /* core0 elr_EL2 bit40 */
			{20924,15,0}, /* core0 elr_EL2 bit41 */
			{20921,15,0}, /* core0 elr_EL2 bit42 */
			{20920,15,0}, /* core0 elr_EL2 bit43 */
			{20919,15,0}, /* core0 elr_EL2 bit44 */
			{20918,15,0}, /* core0 elr_EL2 bit45 */
			{10536,11,1}, /* core0 elr_EL2 bit46 */
			{19655,15,0}, /* core0 elr_EL2 bit47 */
			{19654,15,0}, /* core0 elr_EL2 bit48 */
			{19697,15,0}, /* core0 elr_EL2 bit49 */
			{19593,15,0}, /* core0 elr_EL2 bit50 */
			{19592,15,0}, /* core0 elr_EL2 bit51 */
			{20627,15,0}, /* core0 elr_EL2 bit52 */
			{20626,15,0}, /* core0 elr_EL2 bit53 */
			{19595,15,0}, /* core0 elr_EL2 bit54 */
			{19594,15,0}, /* core0 elr_EL2 bit55 */
			{19696,15,0}, /* core0 elr_EL2 bit56 */
			{20625,15,0}, /* core0 elr_EL2 bit57 */
			{20624,15,0}, /* core0 elr_EL2 bit58 */
			{19591,15,0}, /* core0 elr_EL2 bit59 */
			{19590,15,0}, /* core0 elr_EL2 bit60 */
			{19695,15,0}, /* core0 elr_EL2 bit61 */
			{19694,15,0}, /* core0 elr_EL2 bit62 */
			{10554,11,1}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{24317,15,0}, /* core0 elr_EL3 bit0 */
			{24316,15,0}, /* core0 elr_EL3 bit1 */
			{24315,15,0}, /* core0 elr_EL3 bit2 */
			{24314,15,0}, /* core0 elr_EL3 bit3 */
			{21782,11,1}, /* core0 elr_EL3 bit4 */
			{20733,11,1}, /* core0 elr_EL3 bit5 */
			{21781,11,1}, /* core0 elr_EL3 bit6 */
			{21780,11,1}, /* core0 elr_EL3 bit7 */
			{21779,11,1}, /* core0 elr_EL3 bit8 */
			{21794,11,1}, /* core0 elr_EL3 bit9 */
			{21793,11,1}, /* core0 elr_EL3 bit10 */
			{21792,11,1}, /* core0 elr_EL3 bit11 */
			{21791,11,1}, /* core0 elr_EL3 bit12 */
			{21796,11,1}, /* core0 elr_EL3 bit13 */
			{21795,11,1}, /* core0 elr_EL3 bit14 */
			{22663,15,0}, /* core0 elr_EL3 bit15 */
			{22662,15,0}, /* core0 elr_EL3 bit16 */
			{ 9412,11,0}, /* core0 elr_EL3 bit17 */
			{22671,15,0}, /* core0 elr_EL3 bit18 */
			{ 9411,11,0}, /* core0 elr_EL3 bit19 */
			{22670,15,0}, /* core0 elr_EL3 bit20 */
			{23413,15,0}, /* core0 elr_EL3 bit21 */
			{23412,15,0}, /* core0 elr_EL3 bit22 */
			{24309,15,0}, /* core0 elr_EL3 bit23 */
			{24308,15,0}, /* core0 elr_EL3 bit24 */
			{ 9410,11,0}, /* core0 elr_EL3 bit25 */
			{ 9409,11,0}, /* core0 elr_EL3 bit26 */
			{24307,15,0}, /* core0 elr_EL3 bit27 */
			{24306,15,0}, /* core0 elr_EL3 bit28 */
			{ 9408,11,0}, /* core0 elr_EL3 bit29 */
			{ 9407,11,0}, /* core0 elr_EL3 bit30 */
			{10440,11,1}, /* core0 elr_EL3 bit31 */
			{19343,15,0}, /* core0 elr_EL3 bit32 */
			{19643,15,0}, /* core0 elr_EL3 bit33 */
			{19642,15,0}, /* core0 elr_EL3 bit34 */
			{19342,15,0}, /* core0 elr_EL3 bit35 */
			{19361,15,0}, /* core0 elr_EL3 bit36 */
			{19360,15,0}, /* core0 elr_EL3 bit37 */
			{19319,15,0}, /* core0 elr_EL3 bit38 */
			{19318,15,0}, /* core0 elr_EL3 bit39 */
			{23549,15,0}, /* core0 elr_EL3 bit40 */
			{23548,15,0}, /* core0 elr_EL3 bit41 */
			{10539,11,1}, /* core0 elr_EL3 bit42 */
			{23551,15,0}, /* core0 elr_EL3 bit43 */
			{23550,15,0}, /* core0 elr_EL3 bit44 */
			{20889,15,0}, /* core0 elr_EL3 bit45 */
			{20888,15,0}, /* core0 elr_EL3 bit46 */
			{19681,15,0}, /* core0 elr_EL3 bit47 */
			{19680,15,0}, /* core0 elr_EL3 bit48 */
			{19601,15,0}, /* core0 elr_EL3 bit49 */
			{19600,15,0}, /* core0 elr_EL3 bit50 */
			{20697,15,0}, /* core0 elr_EL3 bit51 */
			{20696,15,0}, /* core0 elr_EL3 bit52 */
			{20675,15,0}, /* core0 elr_EL3 bit53 */
			{20677,15,0}, /* core0 elr_EL3 bit54 */
			{20674,15,0}, /* core0 elr_EL3 bit55 */
			{19669,15,0}, /* core0 elr_EL3 bit56 */
			{20676,15,0}, /* core0 elr_EL3 bit57 */
			{20679,15,0}, /* core0 elr_EL3 bit58 */
			{20678,15,0}, /* core0 elr_EL3 bit59 */
			{10236,11,1}, /* core0 elr_EL3 bit60 */
			{19668,15,0}, /* core0 elr_EL3 bit61 */
			{10552,11,1}, /* core0 elr_EL3 bit62 */
			{10601,11,1}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{21954,11,0}, /* core0 raw_pc bit0 */
			{21953,11,0}, /* core0 raw_pc bit1 */
			{20526,11,1}, /* core0 raw_pc bit2 */
			{20525,11,1}, /* core0 raw_pc bit3 */
			{20528,11,1}, /* core0 raw_pc bit4 */
			{20527,11,1}, /* core0 raw_pc bit5 */
			{21934,11,0}, /* core0 raw_pc bit6 */
			{21314,11,1}, /* core0 raw_pc bit7 */
			{15866,15,1}, /* core0 raw_pc bit8 */
			{15865,15,1}, /* core0 raw_pc bit9 */
			{22010,11,0}, /* core0 raw_pc bit10 */
			{22009,11,0}, /* core0 raw_pc bit11 */
			{22014,11,0}, /* core0 raw_pc bit12 */
			{22013,11,0}, /* core0 raw_pc bit13 */
			{22012,11,0}, /* core0 raw_pc bit14 */
			{22011,11,0}, /* core0 raw_pc bit15 */
			{22004,11,0}, /* core0 raw_pc bit16 */
			{22008,11,0}, /* core0 raw_pc bit17 */
			{22003,11,0}, /* core0 raw_pc bit18 */
			{22006,11,0}, /* core0 raw_pc bit19 */
			{22007,11,0}, /* core0 raw_pc bit20 */
			{15868,15,1}, /* core0 raw_pc bit21 */
			{22005,11,0}, /* core0 raw_pc bit22 */
			{15867,15,1}, /* core0 raw_pc bit23 */
			{22016,11,0}, /* core0 raw_pc bit24 */
			{22015,11,0}, /* core0 raw_pc bit25 */
			{22002,11,0}, /* core0 raw_pc bit26 */
			{22001,11,0}, /* core0 raw_pc bit27 */
			{22000,11,0}, /* core0 raw_pc bit28 */
			{21999,11,0}, /* core0 raw_pc bit29 */
			{21313,11,1}, /* core0 raw_pc bit30 */
			{22517,15,0}, /* core0 raw_pc bit31 */
			{22516,15,0}, /* core0 raw_pc bit32 */
			{22733,15,0}, /* core0 raw_pc bit33 */
			{22732,15,0}, /* core0 raw_pc bit34 */
			{22743,15,0}, /* core0 raw_pc bit35 */
			{22742,15,0}, /* core0 raw_pc bit36 */
			{22745,15,0}, /* core0 raw_pc bit37 */
			{22744,15,0}, /* core0 raw_pc bit38 */
			{22735,15,0}, /* core0 raw_pc bit39 */
			{22731,15,0}, /* core0 raw_pc bit40 */
			{22730,15,0}, /* core0 raw_pc bit41 */
			{22519,15,0}, /* core0 raw_pc bit42 */
			{22518,15,0}, /* core0 raw_pc bit43 */
			{21001,11,1}, /* core0 raw_pc bit44 */
			{22734,15,0}, /* core0 raw_pc bit45 */
			{22741,15,0}, /* core0 raw_pc bit46 */
			{22740,15,0}, /* core0 raw_pc bit47 */
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
			{21128,11,1}, /* core0 pc_iss bit0 */
			{20532,11,1}, /* core0 pc_iss bit1 */
			{20531,11,1}, /* core0 pc_iss bit2 */
			{20534,11,1}, /* core0 pc_iss bit3 */
			{20533,11,1}, /* core0 pc_iss bit4 */
			{20530,11,1}, /* core0 pc_iss bit5 */
			{20529,11,1}, /* core0 pc_iss bit6 */
			{21129,11,1}, /* core0 pc_iss bit7 */
			{20654,11,1}, /* core0 pc_iss bit8 */
			{20653,11,1}, /* core0 pc_iss bit9 */
			{20648,11,1}, /* core0 pc_iss bit10 */
			{20647,11,1}, /* core0 pc_iss bit11 */
			{20624,11,1}, /* core0 pc_iss bit12 */
			{20644,11,1}, /* core0 pc_iss bit13 */
			{20623,11,1}, /* core0 pc_iss bit14 */
			{20643,11,1}, /* core0 pc_iss bit15 */
			{20616,11,1}, /* core0 pc_iss bit16 */
			{20615,11,1}, /* core0 pc_iss bit17 */
			{20626,11,1}, /* core0 pc_iss bit18 */
			{20646,11,1}, /* core0 pc_iss bit19 */
			{20645,11,1}, /* core0 pc_iss bit20 */
			{20620,11,1}, /* core0 pc_iss bit21 */
			{20619,11,1}, /* core0 pc_iss bit22 */
			{20622,11,1}, /* core0 pc_iss bit23 */
			{20621,11,1}, /* core0 pc_iss bit24 */
			{20618,11,1}, /* core0 pc_iss bit25 */
			{20617,11,1}, /* core0 pc_iss bit26 */
			{20614,11,1}, /* core0 pc_iss bit27 */
			{20625,11,1}, /* core0 pc_iss bit28 */
			{20613,11,1}, /* core0 pc_iss bit29 */
			{20612,11,1}, /* core0 pc_iss bit30 */
			{20611,11,1}, /* core0 pc_iss bit31 */
			{20590,11,1}, /* core0 pc_iss bit32 */
			{20589,11,1}, /* core0 pc_iss bit33 */
			{20610,11,1}, /* core0 pc_iss bit34 */
			{20608,11,1}, /* core0 pc_iss bit35 */
			{20607,11,1}, /* core0 pc_iss bit36 */
			{20592,11,1}, /* core0 pc_iss bit37 */
			{20591,11,1}, /* core0 pc_iss bit38 */
			{20594,11,1}, /* core0 pc_iss bit39 */
			{20593,11,1}, /* core0 pc_iss bit40 */
			{22044,11,0}, /* core0 pc_iss bit41 */
			{20609,11,1}, /* core0 pc_iss bit42 */
			{22043,11,0}, /* core0 pc_iss bit43 */
			{20606,11,1}, /* core0 pc_iss bit44 */
			{21116,11,1}, /* core0 pc_iss bit45 */
			{20605,11,1}, /* core0 pc_iss bit46 */
			{20598,11,1}, /* core0 pc_iss bit47 */
			{20597,11,1}, /* core0 pc_iss bit48 */
			{20596,11,1}, /* core0 pc_iss bit49 */
			{20600,11,1}, /* core0 pc_iss bit50 */
			{20599,11,1}, /* core0 pc_iss bit51 */
			{22040,11,0}, /* core0 pc_iss bit52 */
			{20595,11,1}, /* core0 pc_iss bit53 */
			{22039,11,0}, /* core0 pc_iss bit54 */
			{22034,11,0}, /* core0 pc_iss bit55 */
			{22033,11,0}, /* core0 pc_iss bit56 */
			{20602,11,1}, /* core0 pc_iss bit57 */
			{20601,11,1}, /* core0 pc_iss bit58 */
			{22032,11,0}, /* core0 pc_iss bit59 */
			{22031,11,0}, /* core0 pc_iss bit60 */
			{22030,11,0}, /* core0 pc_iss bit61 */
			{22029,11,0}, /* core0 pc_iss bit62 */
			{21188,11,1}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 9736,11,1}, /* core0 full_pc_wr bit0 */
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
			{21158,11,1}, /* core0 full_pc_ex1 bit0 */
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
	},
	{		/* core 1 */
			.pc = {{
			{23475,12,0}, /* core1 pc bit0 */
			{23745,12,0}, /* core1 pc bit1 */
			{23431,12,0}, /* core1 pc bit2 */
			{23748,12,0}, /* core1 pc bit3 */
			{23472,12,0}, /* core1 pc bit4 */
			{23485,12,0}, /* core1 pc bit5 */
			{23494,12,0}, /* core1 pc bit6 */
			{23484,12,0}, /* core1 pc bit7 */
			{23497,12,0}, /* core1 pc bit8 */
			{23496,12,0}, /* core1 pc bit9 */
			{23501,12,0}, /* core1 pc bit10 */
			{23500,12,0}, /* core1 pc bit11 */
			{21881, 8,1}, /* core1 pc bit12 */
			{23491,12,0}, /* core1 pc bit13 */
			{23468,12,0}, /* core1 pc bit14 */
			{23474,12,0}, /* core1 pc bit15 */
			{23430,12,0}, /* core1 pc bit16 */
			{23433,12,0}, /* core1 pc bit17 */
			{21338,12,0}, /* core1 pc bit18 */
			{23753,12,0}, /* core1 pc bit19 */
			{23752,12,0}, /* core1 pc bit20 */
			{23751,12,0}, /* core1 pc bit21 */
			{23750,12,0}, /* core1 pc bit22 */
			{23744,12,0}, /* core1 pc bit23 */
			{23759,12,0}, /* core1 pc bit24 */
			{21337,12,0}, /* core1 pc bit25 */
			{23764,12,0}, /* core1 pc bit26 */
			{23758,12,0}, /* core1 pc bit27 */
			{23755,12,0}, /* core1 pc bit28 */
			{23754,12,0}, /* core1 pc bit29 */
			{21335,12,0}, /* core1 pc bit30 */
			{21334,12,0}, /* core1 pc bit31 */
			{21357,12,0}, /* core1 pc bit32 */
			{21356,12,0}, /* core1 pc bit33 */
			{23757,12,0}, /* core1 pc bit34 */
			{21359,12,0}, /* core1 pc bit35 */
			{23490,12,0}, /* core1 pc bit36 */
			{23477,12,0}, /* core1 pc bit37 */
			{23476,12,0}, /* core1 pc bit38 */
			{23466,12,0}, /* core1 pc bit39 */
			{23479,12,0}, /* core1 pc bit40 */
			{23775,12,0}, /* core1 pc bit41 */
			{23774,12,0}, /* core1 pc bit42 */
			{23478,12,0}, /* core1 pc bit43 */
			{23481,12,0}, /* core1 pc bit44 */
			{10426, 8,1}, /* core1 pc bit45 */
			{21329,12,0}, /* core1 pc bit46 */
			{21328,12,0}, /* core1 pc bit47 */
			{21358,12,0}, /* core1 pc bit48 */
			{10461, 8,1}, /* core1 pc bit49 */
			{21355,12,0}, /* core1 pc bit50 */
			{21354,12,0}, /* core1 pc bit51 */
			{21377,12,0}, /* core1 pc bit52 */
			{21376,12,0}, /* core1 pc bit53 */
			{21353,12,0}, /* core1 pc bit54 */
			{21336,12,0}, /* core1 pc bit55 */
			{21351,12,0}, /* core1 pc bit56 */
			{21350,12,0}, /* core1 pc bit57 */
			{21375,12,0}, /* core1 pc bit58 */
			{21374,12,0}, /* core1 pc bit59 */
			{21341,12,0}, /* core1 pc bit60 */
			{21340,12,0}, /* core1 pc bit61 */
			{21343,12,0}, /* core1 pc bit62 */
			{21342,12,0}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{14975,12,1}, /* core1 sp32 bit0 */
			{14974,12,1}, /* core1 sp32 bit1 */
			{21822, 8,1}, /* core1 sp32 bit2 */
			{23327,12,0}, /* core1 sp32 bit3 */
			{21824, 8,1}, /* core1 sp32 bit4 */
			{21823, 8,1}, /* core1 sp32 bit5 */
			{21820, 8,1}, /* core1 sp32 bit6 */
			{21819, 8,1}, /* core1 sp32 bit7 */
			{21816, 8,1}, /* core1 sp32 bit8 */
			{21821, 8,1}, /* core1 sp32 bit9 */
			{21815, 8,1}, /* core1 sp32 bit10 */
			{15609,12,1}, /* core1 sp32 bit11 */
			{15608,12,1}, /* core1 sp32 bit12 */
			{21818, 8,1}, /* core1 sp32 bit13 */
			{21817, 8,1}, /* core1 sp32 bit14 */
			{20725, 8,1}, /* core1 sp32 bit15 */
			{20109,12,0}, /* core1 sp32 bit16 */
			{10372, 8,1}, /* core1 sp32 bit17 */
			{10371, 8,1}, /* core1 sp32 bit18 */
			{22952, 8,1}, /* core1 sp32 bit19 */
			{20108,12,0}, /* core1 sp32 bit20 */
			{20111,12,0}, /* core1 sp32 bit21 */
			{20110,12,0}, /* core1 sp32 bit22 */
			{22951, 8,1}, /* core1 sp32 bit23 */
			{24341,12,0}, /* core1 sp32 bit24 */
			{23326,12,0}, /* core1 sp32 bit25 */
			{22369,12,0}, /* core1 sp32 bit26 */
			{22368,12,0}, /* core1 sp32 bit27 */
			{22371,12,0}, /* core1 sp32 bit28 */
			{22370,12,0}, /* core1 sp32 bit29 */
			{10391, 8,1}, /* core1 sp32 bit30 */
			{24340,12,0}, /* core1 sp32 bit31 */
			{20815,12,0}, /* core1 sp32 bit32 */
			{20814,12,0}, /* core1 sp32 bit33 */
			{19941,12,0}, /* core1 sp32 bit34 */
			{19940,12,0}, /* core1 sp32 bit35 */
			{19943,12,0}, /* core1 sp32 bit36 */
			{19942,12,0}, /* core1 sp32 bit37 */
			{20853,12,0}, /* core1 sp32 bit38 */
			{20852,12,0}, /* core1 sp32 bit39 */
			{19945,12,0}, /* core1 sp32 bit40 */
			{19944,12,0}, /* core1 sp32 bit41 */
			{10529, 8,1}, /* core1 sp32 bit42 */
			{20023,12,0}, /* core1 sp32 bit43 */
			{20022,12,0}, /* core1 sp32 bit44 */
			{20021,12,0}, /* core1 sp32 bit45 */
			{20020,12,0}, /* core1 sp32 bit46 */
			{20575,12,0}, /* core1 sp32 bit47 */
			{20574,12,0}, /* core1 sp32 bit48 */
			{20419,12,0}, /* core1 sp32 bit49 */
			{20417,12,0}, /* core1 sp32 bit50 */
			{20416,12,0}, /* core1 sp32 bit51 */
			{20415,12,0}, /* core1 sp32 bit52 */
			{20414,12,0}, /* core1 sp32 bit53 */
			{20413,12,0}, /* core1 sp32 bit54 */
			{20412,12,0}, /* core1 sp32 bit55 */
			{20585,12,0}, /* core1 sp32 bit56 */
			{20584,12,0}, /* core1 sp32 bit57 */
			{20425,12,0}, /* core1 sp32 bit58 */
			{20424,12,0}, /* core1 sp32 bit59 */
			{11036, 8,1}, /* core1 sp32 bit60 */
			{20418,12,0}, /* core1 sp32 bit61 */
			{11035, 8,1}, /* core1 sp32 bit62 */
			{22394, 8,0}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{14883,12,1}, /* core1 fp32 bit0 */
			{14882,12,1}, /* core1 fp32 bit1 */
			{23040, 8,1}, /* core1 fp32 bit2 */
			{10868, 8,0}, /* core1 fp32 bit3 */
			{20151,12,0}, /* core1 fp32 bit4 */
			{20150,12,0}, /* core1 fp32 bit5 */
			{10950, 8,0}, /* core1 fp32 bit6 */
			{10949, 8,0}, /* core1 fp32 bit7 */
			{10948, 8,0}, /* core1 fp32 bit8 */
			{10947, 8,0}, /* core1 fp32 bit9 */
			{11478, 8,0}, /* core1 fp32 bit10 */
			{11477, 8,0}, /* core1 fp32 bit11 */
			{20081,12,0}, /* core1 fp32 bit12 */
			{20080,12,0}, /* core1 fp32 bit13 */
			{20099,12,0}, /* core1 fp32 bit14 */
			{20098,12,0}, /* core1 fp32 bit15 */
			{10867, 8,0}, /* core1 fp32 bit16 */
			{10886, 8,0}, /* core1 fp32 bit17 */
			{10885, 8,0}, /* core1 fp32 bit18 */
			{10882, 8,0}, /* core1 fp32 bit19 */
			{23312, 8,0}, /* core1 fp32 bit20 */
			{10881, 8,0}, /* core1 fp32 bit21 */
			{23039, 8,1}, /* core1 fp32 bit22 */
			{23006, 8,1}, /* core1 fp32 bit23 */
			{22944, 8,1}, /* core1 fp32 bit24 */
			{23005, 8,1}, /* core1 fp32 bit25 */
			{22978, 8,1}, /* core1 fp32 bit26 */
			{22943, 8,1}, /* core1 fp32 bit27 */
			{22942, 8,1}, /* core1 fp32 bit28 */
			{22977, 8,1}, /* core1 fp32 bit29 */
			{23316, 8,0}, /* core1 fp32 bit30 */
			{22941, 8,1}, /* core1 fp32 bit31 */
			{19545,12,0}, /* core1 fp32 bit32 */
			{19544,12,0}, /* core1 fp32 bit33 */
			{19547,12,0}, /* core1 fp32 bit34 */
			{19546,12,0}, /* core1 fp32 bit35 */
			{19289,12,0}, /* core1 fp32 bit36 */
			{19288,12,0}, /* core1 fp32 bit37 */
			{20357,12,0}, /* core1 fp32 bit38 */
			{20356,12,0}, /* core1 fp32 bit39 */
			{19575,12,0}, /* core1 fp32 bit40 */
			{10593, 8,1}, /* core1 fp32 bit41 */
			{19574,12,0}, /* core1 fp32 bit42 */
			{20825,12,0}, /* core1 fp32 bit43 */
			{20824,12,0}, /* core1 fp32 bit44 */
			{20009,12,0}, /* core1 fp32 bit45 */
			{20008,12,0}, /* core1 fp32 bit46 */
			{20373,12,0}, /* core1 fp32 bit47 */
			{20372,12,0}, /* core1 fp32 bit48 */
			{20353,12,0}, /* core1 fp32 bit49 */
			{20345,12,0}, /* core1 fp32 bit50 */
			{20344,12,0}, /* core1 fp32 bit51 */
			{20343,12,0}, /* core1 fp32 bit52 */
			{20342,12,0}, /* core1 fp32 bit53 */
			{20393,12,0}, /* core1 fp32 bit54 */
			{20392,12,0}, /* core1 fp32 bit55 */
			{20391,12,0}, /* core1 fp32 bit56 */
			{20390,12,0}, /* core1 fp32 bit57 */
			{20395,12,0}, /* core1 fp32 bit58 */
			{20394,12,0}, /* core1 fp32 bit59 */
			{11019, 8,1}, /* core1 fp32 bit60 */
			{20352,12,0}, /* core1 fp32 bit61 */
			{11027, 8,1}, /* core1 fp32 bit62 */
			{10587, 8,1}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{21567,12,0}, /* core1 fp64 bit0 */
			{21566,12,0}, /* core1 fp64 bit1 */
			{21565,12,0}, /* core1 fp64 bit2 */
			{21564,12,0}, /* core1 fp64 bit3 */
			{22473,12,0}, /* core1 fp64 bit4 */
			{22472,12,0}, /* core1 fp64 bit5 */
			{22467,12,0}, /* core1 fp64 bit6 */
			{22466,12,0}, /* core1 fp64 bit7 */
			{22645,12,0}, /* core1 fp64 bit8 */
			{22644,12,0}, /* core1 fp64 bit9 */
			{22469,12,0}, /* core1 fp64 bit10 */
			{22468,12,0}, /* core1 fp64 bit11 */
			{22471,12,0}, /* core1 fp64 bit12 */
			{22470,12,0}, /* core1 fp64 bit13 */
			{22603,12,0}, /* core1 fp64 bit14 */
			{22602,12,0}, /* core1 fp64 bit15 */
			{22599,12,0}, /* core1 fp64 bit16 */
			{22598,12,0}, /* core1 fp64 bit17 */
			{22429,12,0}, /* core1 fp64 bit18 */
			{22428,12,0}, /* core1 fp64 bit19 */
			{22597,12,0}, /* core1 fp64 bit20 */
			{22596,12,0}, /* core1 fp64 bit21 */
			{23405,12,0}, /* core1 fp64 bit22 */
			{23407,12,0}, /* core1 fp64 bit23 */
			{23406,12,0}, /* core1 fp64 bit24 */
			{23391,12,0}, /* core1 fp64 bit25 */
			{23390,12,0}, /* core1 fp64 bit26 */
			{23387,12,0}, /* core1 fp64 bit27 */
			{10454, 8,1}, /* core1 fp64 bit28 */
			{23386,12,0}, /* core1 fp64 bit29 */
			{10455, 8,1}, /* core1 fp64 bit30 */
			{23404,12,0}, /* core1 fp64 bit31 */
			{19355,12,0}, /* core1 fp64 bit32 */
			{19354,12,0}, /* core1 fp64 bit33 */
			{19349,12,0}, /* core1 fp64 bit34 */
			{19348,12,0}, /* core1 fp64 bit35 */
			{19375,12,0}, /* core1 fp64 bit36 */
			{19374,12,0}, /* core1 fp64 bit37 */
			{20951,12,0}, /* core1 fp64 bit38 */
			{20950,12,0}, /* core1 fp64 bit39 */
			{20909,12,0}, /* core1 fp64 bit40 */
			{20908,12,0}, /* core1 fp64 bit41 */
			{20911,12,0}, /* core1 fp64 bit42 */
			{20915,12,0}, /* core1 fp64 bit43 */
			{20910,12,0}, /* core1 fp64 bit44 */
			{20914,12,0}, /* core1 fp64 bit45 */
			{10605, 8,1}, /* core1 fp64 bit46 */
			{19677,12,0}, /* core1 fp64 bit47 */
			{19676,12,0}, /* core1 fp64 bit48 */
			{19671,12,0}, /* core1 fp64 bit49 */
			{19715,12,0}, /* core1 fp64 bit50 */
			{19714,12,0}, /* core1 fp64 bit51 */
			{19719,12,0}, /* core1 fp64 bit52 */
			{19718,12,0}, /* core1 fp64 bit53 */
			{19721,12,0}, /* core1 fp64 bit54 */
			{19720,12,0}, /* core1 fp64 bit55 */
			{19670,12,0}, /* core1 fp64 bit56 */
			{19717,12,0}, /* core1 fp64 bit57 */
			{19716,12,0}, /* core1 fp64 bit58 */
			{19713,12,0}, /* core1 fp64 bit59 */
			{19712,12,0}, /* core1 fp64 bit60 */
			{19675,12,0}, /* core1 fp64 bit61 */
			{19674,12,0}, /* core1 fp64 bit62 */
			{10544, 8,1}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{24337,12,0}, /* core1 sp_EL0 bit0 */
			{24336,12,0}, /* core1 sp_EL0 bit1 */
			{24335,12,0}, /* core1 sp_EL0 bit2 */
			{24334,12,0}, /* core1 sp_EL0 bit3 */
			{21282, 8,1}, /* core1 sp_EL0 bit4 */
			{21281, 8,1}, /* core1 sp_EL0 bit5 */
			{21284, 8,1}, /* core1 sp_EL0 bit6 */
			{21283, 8,1}, /* core1 sp_EL0 bit7 */
			{21311,12,0}, /* core1 sp_EL0 bit8 */
			{21310,12,0}, /* core1 sp_EL0 bit9 */
			{20969, 8,1}, /* core1 sp_EL0 bit10 */
			{20968, 8,1}, /* core1 sp_EL0 bit11 */
			{20971, 8,1}, /* core1 sp_EL0 bit12 */
			{20970, 8,1}, /* core1 sp_EL0 bit13 */
			{22455,12,0}, /* core1 sp_EL0 bit14 */
			{22454,12,0}, /* core1 sp_EL0 bit15 */
			{10419, 8,1}, /* core1 sp_EL0 bit16 */
			{22591,12,0}, /* core1 sp_EL0 bit17 */
			{22590,12,0}, /* core1 sp_EL0 bit18 */
			{22435,12,0}, /* core1 sp_EL0 bit19 */
			{22434,12,0}, /* core1 sp_EL0 bit20 */
			{22587,12,0}, /* core1 sp_EL0 bit21 */
			{22586,12,0}, /* core1 sp_EL0 bit22 */
			{22579,12,0}, /* core1 sp_EL0 bit23 */
			{22578,12,0}, /* core1 sp_EL0 bit24 */
			{24313,12,0}, /* core1 sp_EL0 bit25 */
			{24312,12,0}, /* core1 sp_EL0 bit26 */
			{23367,12,0}, /* core1 sp_EL0 bit27 */
			{23365,12,0}, /* core1 sp_EL0 bit28 */
			{23364,12,0}, /* core1 sp_EL0 bit29 */
			{23366,12,0}, /* core1 sp_EL0 bit30 */
			{10449, 8,1}, /* core1 sp_EL0 bit31 */
			{19341,12,0}, /* core1 sp_EL0 bit32 */
			{19340,12,0}, /* core1 sp_EL0 bit33 */
			{19679,12,0}, /* core1 sp_EL0 bit34 */
			{19678,12,0}, /* core1 sp_EL0 bit35 */
			{19311,12,0}, /* core1 sp_EL0 bit36 */
			{19310,12,0}, /* core1 sp_EL0 bit37 */
			{19369,12,0}, /* core1 sp_EL0 bit38 */
			{19368,12,0}, /* core1 sp_EL0 bit39 */
			{19367,12,0}, /* core1 sp_EL0 bit40 */
			{19366,12,0}, /* core1 sp_EL0 bit41 */
			{20945,12,0}, /* core1 sp_EL0 bit42 */
			{20944,12,0}, /* core1 sp_EL0 bit43 */
			{19377,12,0}, /* core1 sp_EL0 bit44 */
			{10541, 8,1}, /* core1 sp_EL0 bit45 */
			{19376,12,0}, /* core1 sp_EL0 bit46 */
			{19683,12,0}, /* core1 sp_EL0 bit47 */
			{19682,12,0}, /* core1 sp_EL0 bit48 */
			{19663,12,0}, /* core1 sp_EL0 bit49 */
			{20713,12,0}, /* core1 sp_EL0 bit50 */
			{20712,12,0}, /* core1 sp_EL0 bit51 */
			{20707,12,0}, /* core1 sp_EL0 bit52 */
			{20706,12,0}, /* core1 sp_EL0 bit53 */
			{20709,12,0}, /* core1 sp_EL0 bit54 */
			{20708,12,0}, /* core1 sp_EL0 bit55 */
			{19662,12,0}, /* core1 sp_EL0 bit56 */
			{20711,12,0}, /* core1 sp_EL0 bit57 */
			{20710,12,0}, /* core1 sp_EL0 bit58 */
			{11046, 8,1}, /* core1 sp_EL0 bit59 */
			{23293,12,0}, /* core1 sp_EL0 bit60 */
			{23292,12,0}, /* core1 sp_EL0 bit61 */
			{23291,12,0}, /* core1 sp_EL0 bit62 */
			{23290,12,0}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{24351,12,0}, /* core1 sp_EL1 bit0 */
			{24350,12,0}, /* core1 sp_EL1 bit1 */
			{24349,12,0}, /* core1 sp_EL1 bit2 */
			{24348,12,0}, /* core1 sp_EL1 bit3 */
			{22461,12,0}, /* core1 sp_EL1 bit4 */
			{22460,12,0}, /* core1 sp_EL1 bit5 */
			{22647,12,0}, /* core1 sp_EL1 bit6 */
			{22646,12,0}, /* core1 sp_EL1 bit7 */
			{22601,12,0}, /* core1 sp_EL1 bit8 */
			{22600,12,0}, /* core1 sp_EL1 bit9 */
			{22649,12,0}, /* core1 sp_EL1 bit10 */
			{22648,12,0}, /* core1 sp_EL1 bit11 */
			{22463,12,0}, /* core1 sp_EL1 bit12 */
			{22462,12,0}, /* core1 sp_EL1 bit13 */
			{22457,12,0}, /* core1 sp_EL1 bit14 */
			{22456,12,0}, /* core1 sp_EL1 bit15 */
			{22595,12,0}, /* core1 sp_EL1 bit16 */
			{22594,12,0}, /* core1 sp_EL1 bit17 */
			{22427,12,0}, /* core1 sp_EL1 bit18 */
			{23403,12,0}, /* core1 sp_EL1 bit19 */
			{22426,12,0}, /* core1 sp_EL1 bit20 */
			{22431,12,0}, /* core1 sp_EL1 bit21 */
			{22430,12,0}, /* core1 sp_EL1 bit22 */
			{23402,12,0}, /* core1 sp_EL1 bit23 */
			{23389,12,0}, /* core1 sp_EL1 bit24 */
			{23388,12,0}, /* core1 sp_EL1 bit25 */
			{23385,12,0}, /* core1 sp_EL1 bit26 */
			{23384,12,0}, /* core1 sp_EL1 bit27 */
			{10453, 8,1}, /* core1 sp_EL1 bit28 */
			{23383,12,0}, /* core1 sp_EL1 bit29 */
			{23382,12,0}, /* core1 sp_EL1 bit30 */
			{10439, 8,1}, /* core1 sp_EL1 bit31 */
			{19353,12,0}, /* core1 sp_EL1 bit32 */
			{19352,12,0}, /* core1 sp_EL1 bit33 */
			{19351,12,0}, /* core1 sp_EL1 bit34 */
			{19350,12,0}, /* core1 sp_EL1 bit35 */
			{19379,12,0}, /* core1 sp_EL1 bit36 */
			{19378,12,0}, /* core1 sp_EL1 bit37 */
			{19373,12,0}, /* core1 sp_EL1 bit38 */
			{19372,12,0}, /* core1 sp_EL1 bit39 */
			{20947,12,0}, /* core1 sp_EL1 bit40 */
			{20949,12,0}, /* core1 sp_EL1 bit41 */
			{20946,12,0}, /* core1 sp_EL1 bit42 */
			{20948,12,0}, /* core1 sp_EL1 bit43 */
			{20913,12,0}, /* core1 sp_EL1 bit44 */
			{20912,12,0}, /* core1 sp_EL1 bit45 */
			{10604, 8,1}, /* core1 sp_EL1 bit46 */
			{19673,12,0}, /* core1 sp_EL1 bit47 */
			{19672,12,0}, /* core1 sp_EL1 bit48 */
			{19603,12,0}, /* core1 sp_EL1 bit49 */
			{19703,12,0}, /* core1 sp_EL1 bit50 */
			{19702,12,0}, /* core1 sp_EL1 bit51 */
			{19709,12,0}, /* core1 sp_EL1 bit52 */
			{19708,12,0}, /* core1 sp_EL1 bit53 */
			{19707,12,0}, /* core1 sp_EL1 bit54 */
			{19706,12,0}, /* core1 sp_EL1 bit55 */
			{19602,12,0}, /* core1 sp_EL1 bit56 */
			{19711,12,0}, /* core1 sp_EL1 bit57 */
			{19710,12,0}, /* core1 sp_EL1 bit58 */
			{19705,12,0}, /* core1 sp_EL1 bit59 */
			{19704,12,0}, /* core1 sp_EL1 bit60 */
			{19347,12,0}, /* core1 sp_EL1 bit61 */
			{19346,12,0}, /* core1 sp_EL1 bit62 */
			{10543, 8,1}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 9416, 8,0}, /* core1 sp_EL2 bit0 */
			{ 9415, 8,0}, /* core1 sp_EL2 bit1 */
			{ 9414, 8,0}, /* core1 sp_EL2 bit2 */
			{ 9413, 8,0}, /* core1 sp_EL2 bit3 */
			{21307,12,0}, /* core1 sp_EL2 bit4 */
			{21306,12,0}, /* core1 sp_EL2 bit5 */
			{21317,12,0}, /* core1 sp_EL2 bit6 */
			{21316,12,0}, /* core1 sp_EL2 bit7 */
			{21315,12,0}, /* core1 sp_EL2 bit8 */
			{21314,12,0}, /* core1 sp_EL2 bit9 */
			{21313,12,0}, /* core1 sp_EL2 bit10 */
			{21312,12,0}, /* core1 sp_EL2 bit11 */
			{21309,12,0}, /* core1 sp_EL2 bit12 */
			{21308,12,0}, /* core1 sp_EL2 bit13 */
			{21321,12,0}, /* core1 sp_EL2 bit14 */
			{21320,12,0}, /* core1 sp_EL2 bit15 */
			{22433,12,0}, /* core1 sp_EL2 bit16 */
			{22432,12,0}, /* core1 sp_EL2 bit17 */
			{22707,12,0}, /* core1 sp_EL2 bit18 */
			{22706,12,0}, /* core1 sp_EL2 bit19 */
			{10416, 8,1}, /* core1 sp_EL2 bit20 */
			{22585,12,0}, /* core1 sp_EL2 bit21 */
			{22584,12,0}, /* core1 sp_EL2 bit22 */
			{22581,12,0}, /* core1 sp_EL2 bit23 */
			{22580,12,0}, /* core1 sp_EL2 bit24 */
			{22409,12,0}, /* core1 sp_EL2 bit25 */
			{22408,12,0}, /* core1 sp_EL2 bit26 */
			{24323,12,0}, /* core1 sp_EL2 bit27 */
			{24322,12,0}, /* core1 sp_EL2 bit28 */
			{22571,12,0}, /* core1 sp_EL2 bit29 */
			{22570,12,0}, /* core1 sp_EL2 bit30 */
			{10450, 8,1}, /* core1 sp_EL2 bit31 */
			{19299,12,0}, /* core1 sp_EL2 bit32 */
			{19298,12,0}, /* core1 sp_EL2 bit33 */
			{19297,12,0}, /* core1 sp_EL2 bit34 */
			{19296,12,0}, /* core1 sp_EL2 bit35 */
			{19329,12,0}, /* core1 sp_EL2 bit36 */
			{10560, 8,1}, /* core1 sp_EL2 bit37 */
			{19328,12,0}, /* core1 sp_EL2 bit38 */
			{20929,12,0}, /* core1 sp_EL2 bit39 */
			{20928,12,0}, /* core1 sp_EL2 bit40 */
			{20931,12,0}, /* core1 sp_EL2 bit41 */
			{20930,12,0}, /* core1 sp_EL2 bit42 */
			{23311,12,0}, /* core1 sp_EL2 bit43 */
			{23310,12,0}, /* core1 sp_EL2 bit44 */
			{23309,12,0}, /* core1 sp_EL2 bit45 */
			{23308,12,0}, /* core1 sp_EL2 bit46 */
			{19651,12,0}, /* core1 sp_EL2 bit47 */
			{20669,12,0}, /* core1 sp_EL2 bit48 */
			{19650,12,0}, /* core1 sp_EL2 bit49 */
			{20668,12,0}, /* core1 sp_EL2 bit50 */
			{20617,12,0}, /* core1 sp_EL2 bit51 */
			{20616,12,0}, /* core1 sp_EL2 bit52 */
			{20601,12,0}, /* core1 sp_EL2 bit53 */
			{20600,12,0}, /* core1 sp_EL2 bit54 */
			{20603,12,0}, /* core1 sp_EL2 bit55 */
			{20629,12,0}, /* core1 sp_EL2 bit56 */
			{20602,12,0}, /* core1 sp_EL2 bit57 */
			{20613,12,0}, /* core1 sp_EL2 bit58 */
			{20612,12,0}, /* core1 sp_EL2 bit59 */
			{11044, 8,1}, /* core1 sp_EL2 bit60 */
			{20628,12,0}, /* core1 sp_EL2 bit61 */
			{11045, 8,1}, /* core1 sp_EL2 bit62 */
			{10559, 8,1}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{23371,12,0}, /* core1 sp_EL3 bit0 */
			{22411,12,0}, /* core1 sp_EL3 bit1 */
			{23370,12,0}, /* core1 sp_EL3 bit2 */
			{10452, 8,1}, /* core1 sp_EL3 bit3 */
			{22653,12,0}, /* core1 sp_EL3 bit4 */
			{22652,12,0}, /* core1 sp_EL3 bit5 */
			{22651,12,0}, /* core1 sp_EL3 bit6 */
			{22650,12,0}, /* core1 sp_EL3 bit7 */
			{22659,12,0}, /* core1 sp_EL3 bit8 */
			{22658,12,0}, /* core1 sp_EL3 bit9 */
			{22655,12,0}, /* core1 sp_EL3 bit10 */
			{22654,12,0}, /* core1 sp_EL3 bit11 */
			{22657,12,0}, /* core1 sp_EL3 bit12 */
			{22656,12,0}, /* core1 sp_EL3 bit13 */
			{10420, 8,1}, /* core1 sp_EL3 bit14 */
			{22661,12,0}, /* core1 sp_EL3 bit15 */
			{22660,12,0}, /* core1 sp_EL3 bit16 */
			{22593,12,0}, /* core1 sp_EL3 bit17 */
			{22589,12,0}, /* core1 sp_EL3 bit18 */
			{22588,12,0}, /* core1 sp_EL3 bit19 */
			{22592,12,0}, /* core1 sp_EL3 bit20 */
			{23411,12,0}, /* core1 sp_EL3 bit21 */
			{23410,12,0}, /* core1 sp_EL3 bit22 */
			{22410,12,0}, /* core1 sp_EL3 bit23 */
			{23409,12,0}, /* core1 sp_EL3 bit24 */
			{23408,12,0}, /* core1 sp_EL3 bit25 */
			{23719,12,0}, /* core1 sp_EL3 bit26 */
			{23718,12,0}, /* core1 sp_EL3 bit27 */
			{23373,12,0}, /* core1 sp_EL3 bit28 */
			{23372,12,0}, /* core1 sp_EL3 bit29 */
			{23381,12,0}, /* core1 sp_EL3 bit30 */
			{23380,12,0}, /* core1 sp_EL3 bit31 */
			{19309,12,0}, /* core1 sp_EL3 bit32 */
			{19308,12,0}, /* core1 sp_EL3 bit33 */
			{19359,12,0}, /* core1 sp_EL3 bit34 */
			{19357,12,0}, /* core1 sp_EL3 bit35 */
			{19356,12,0}, /* core1 sp_EL3 bit36 */
			{19365,12,0}, /* core1 sp_EL3 bit37 */
			{19364,12,0}, /* core1 sp_EL3 bit38 */
			{19363,12,0}, /* core1 sp_EL3 bit39 */
			{19362,12,0}, /* core1 sp_EL3 bit40 */
			{20943,12,0}, /* core1 sp_EL3 bit41 */
			{20942,12,0}, /* core1 sp_EL3 bit42 */
			{20941,12,0}, /* core1 sp_EL3 bit43 */
			{20940,12,0}, /* core1 sp_EL3 bit44 */
			{10557, 8,1}, /* core1 sp_EL3 bit45 */
			{19358,12,0}, /* core1 sp_EL3 bit46 */
			{19657,12,0}, /* core1 sp_EL3 bit47 */
			{19699,12,0}, /* core1 sp_EL3 bit48 */
			{19656,12,0}, /* core1 sp_EL3 bit49 */
			{20691,12,0}, /* core1 sp_EL3 bit50 */
			{19698,12,0}, /* core1 sp_EL3 bit51 */
			{20690,12,0}, /* core1 sp_EL3 bit52 */
			{20673,12,0}, /* core1 sp_EL3 bit53 */
			{20683,12,0}, /* core1 sp_EL3 bit54 */
			{20682,12,0}, /* core1 sp_EL3 bit55 */
			{20672,12,0}, /* core1 sp_EL3 bit56 */
			{20671,12,0}, /* core1 sp_EL3 bit57 */
			{20670,12,0}, /* core1 sp_EL3 bit58 */
			{20681,12,0}, /* core1 sp_EL3 bit59 */
			{20680,12,0}, /* core1 sp_EL3 bit60 */
			{19659,12,0}, /* core1 sp_EL3 bit61 */
			{19658,12,0}, /* core1 sp_EL3 bit62 */
			{10551, 8,1}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{24321,12,0}, /* core1 elr_EL1 bit0 */
			{24320,12,0}, /* core1 elr_EL1 bit1 */
			{24319,12,0}, /* core1 elr_EL1 bit2 */
			{24318,12,0}, /* core1 elr_EL1 bit3 */
			{23789,12,0}, /* core1 elr_EL1 bit4 */
			{23788,12,0}, /* core1 elr_EL1 bit5 */
			{22451,12,0}, /* core1 elr_EL1 bit6 */
			{22450,12,0}, /* core1 elr_EL1 bit7 */
			{22453,12,0}, /* core1 elr_EL1 bit8 */
			{22452,12,0}, /* core1 elr_EL1 bit9 */
			{21305,12,0}, /* core1 elr_EL1 bit10 */
			{21304,12,0}, /* core1 elr_EL1 bit11 */
			{22449,12,0}, /* core1 elr_EL1 bit12 */
			{22448,12,0}, /* core1 elr_EL1 bit13 */
			{10418, 8,1}, /* core1 elr_EL1 bit14 */
			{22667,12,0}, /* core1 elr_EL1 bit15 */
			{22666,12,0}, /* core1 elr_EL1 bit16 */
			{22669,12,0}, /* core1 elr_EL1 bit17 */
			{22703,12,0}, /* core1 elr_EL1 bit18 */
			{22702,12,0}, /* core1 elr_EL1 bit19 */
			{22668,12,0}, /* core1 elr_EL1 bit20 */
			{22405,12,0}, /* core1 elr_EL1 bit21 */
			{22407,12,0}, /* core1 elr_EL1 bit22 */
			{22406,12,0}, /* core1 elr_EL1 bit23 */
			{22404,12,0}, /* core1 elr_EL1 bit24 */
			{23379,12,0}, /* core1 elr_EL1 bit25 */
			{23378,12,0}, /* core1 elr_EL1 bit26 */
			{22415,12,0}, /* core1 elr_EL1 bit27 */
			{10451, 8,1}, /* core1 elr_EL1 bit28 */
			{22414,12,0}, /* core1 elr_EL1 bit29 */
			{22413,12,0}, /* core1 elr_EL1 bit30 */
			{22412,12,0}, /* core1 elr_EL1 bit31 */
			{19307,12,0}, /* core1 elr_EL1 bit32 */
			{19306,12,0}, /* core1 elr_EL1 bit33 */
			{19641,12,0}, /* core1 elr_EL1 bit34 */
			{19640,12,0}, /* core1 elr_EL1 bit35 */
			{10555, 8,1}, /* core1 elr_EL1 bit36 */
			{19321,12,0}, /* core1 elr_EL1 bit37 */
			{19320,12,0}, /* core1 elr_EL1 bit38 */
			{19317,12,0}, /* core1 elr_EL1 bit39 */
			{19316,12,0}, /* core1 elr_EL1 bit40 */
			{20923,12,0}, /* core1 elr_EL1 bit41 */
			{20922,12,0}, /* core1 elr_EL1 bit42 */
			{20917,12,0}, /* core1 elr_EL1 bit43 */
			{20916,12,0}, /* core1 elr_EL1 bit44 */
			{20939,12,0}, /* core1 elr_EL1 bit45 */
			{20938,12,0}, /* core1 elr_EL1 bit46 */
			{19667,12,0}, /* core1 elr_EL1 bit47 */
			{19599,12,0}, /* core1 elr_EL1 bit48 */
			{19666,12,0}, /* core1 elr_EL1 bit49 */
			{19598,12,0}, /* core1 elr_EL1 bit50 */
			{19701,12,0}, /* core1 elr_EL1 bit51 */
			{19700,12,0}, /* core1 elr_EL1 bit52 */
			{19597,12,0}, /* core1 elr_EL1 bit53 */
			{19596,12,0}, /* core1 elr_EL1 bit54 */
			{20699,12,0}, /* core1 elr_EL1 bit55 */
			{19665,12,0}, /* core1 elr_EL1 bit56 */
			{20698,12,0}, /* core1 elr_EL1 bit57 */
			{20701,12,0}, /* core1 elr_EL1 bit58 */
			{20700,12,0}, /* core1 elr_EL1 bit59 */
			{10237, 8,1}, /* core1 elr_EL1 bit60 */
			{19664,12,0}, /* core1 elr_EL1 bit61 */
			{10238, 8,1}, /* core1 elr_EL1 bit62 */
			{10556, 8,1}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{10445, 8,1}, /* core1 elr_EL2 bit0 */
			{23333,12,0}, /* core1 elr_EL2 bit1 */
			{23332,12,0}, /* core1 elr_EL2 bit2 */
			{23337,12,0}, /* core1 elr_EL2 bit3 */
			{21299,12,0}, /* core1 elr_EL2 bit4 */
			{21298,12,0}, /* core1 elr_EL2 bit5 */
			{21303,12,0}, /* core1 elr_EL2 bit6 */
			{21302,12,0}, /* core1 elr_EL2 bit7 */
			{22447,12,0}, /* core1 elr_EL2 bit8 */
			{22446,12,0}, /* core1 elr_EL2 bit9 */
			{21301,12,0}, /* core1 elr_EL2 bit10 */
			{21300,12,0}, /* core1 elr_EL2 bit11 */
			{22445,12,0}, /* core1 elr_EL2 bit12 */
			{22444,12,0}, /* core1 elr_EL2 bit13 */
			{22441,12,0}, /* core1 elr_EL2 bit14 */
			{22440,12,0}, /* core1 elr_EL2 bit15 */
			{22679,12,0}, /* core1 elr_EL2 bit16 */
			{22678,12,0}, /* core1 elr_EL2 bit17 */
			{22685,12,0}, /* core1 elr_EL2 bit18 */
			{22684,12,0}, /* core1 elr_EL2 bit19 */
			{22677,12,0}, /* core1 elr_EL2 bit20 */
			{22676,12,0}, /* core1 elr_EL2 bit21 */
			{22689,12,0}, /* core1 elr_EL2 bit22 */
			{23335,12,0}, /* core1 elr_EL2 bit23 */
			{22688,12,0}, /* core1 elr_EL2 bit24 */
			{23336,12,0}, /* core1 elr_EL2 bit25 */
			{23345,12,0}, /* core1 elr_EL2 bit26 */
			{23344,12,0}, /* core1 elr_EL2 bit27 */
			{23334,12,0}, /* core1 elr_EL2 bit28 */
			{14893,12,1}, /* core1 elr_EL2 bit29 */
			{14892,12,1}, /* core1 elr_EL2 bit30 */
			{10442, 8,1}, /* core1 elr_EL2 bit31 */
			{19301,12,0}, /* core1 elr_EL2 bit32 */
			{19300,12,0}, /* core1 elr_EL2 bit33 */
			{19647,12,0}, /* core1 elr_EL2 bit34 */
			{19646,12,0}, /* core1 elr_EL2 bit35 */
			{19337,12,0}, /* core1 elr_EL2 bit36 */
			{19336,12,0}, /* core1 elr_EL2 bit37 */
			{19639,12,0}, /* core1 elr_EL2 bit38 */
			{19638,12,0}, /* core1 elr_EL2 bit39 */
			{20925,12,0}, /* core1 elr_EL2 bit40 */
			{20924,12,0}, /* core1 elr_EL2 bit41 */
			{20921,12,0}, /* core1 elr_EL2 bit42 */
			{20920,12,0}, /* core1 elr_EL2 bit43 */
			{20919,12,0}, /* core1 elr_EL2 bit44 */
			{20918,12,0}, /* core1 elr_EL2 bit45 */
			{10536, 8,1}, /* core1 elr_EL2 bit46 */
			{19655,12,0}, /* core1 elr_EL2 bit47 */
			{19654,12,0}, /* core1 elr_EL2 bit48 */
			{19697,12,0}, /* core1 elr_EL2 bit49 */
			{19593,12,0}, /* core1 elr_EL2 bit50 */
			{19592,12,0}, /* core1 elr_EL2 bit51 */
			{20627,12,0}, /* core1 elr_EL2 bit52 */
			{20626,12,0}, /* core1 elr_EL2 bit53 */
			{19595,12,0}, /* core1 elr_EL2 bit54 */
			{19594,12,0}, /* core1 elr_EL2 bit55 */
			{19696,12,0}, /* core1 elr_EL2 bit56 */
			{20625,12,0}, /* core1 elr_EL2 bit57 */
			{20624,12,0}, /* core1 elr_EL2 bit58 */
			{19591,12,0}, /* core1 elr_EL2 bit59 */
			{19590,12,0}, /* core1 elr_EL2 bit60 */
			{19695,12,0}, /* core1 elr_EL2 bit61 */
			{19694,12,0}, /* core1 elr_EL2 bit62 */
			{10554, 8,1}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{24317,12,0}, /* core1 elr_EL3 bit0 */
			{24316,12,0}, /* core1 elr_EL3 bit1 */
			{24315,12,0}, /* core1 elr_EL3 bit2 */
			{24314,12,0}, /* core1 elr_EL3 bit3 */
			{21782, 8,1}, /* core1 elr_EL3 bit4 */
			{20733, 8,1}, /* core1 elr_EL3 bit5 */
			{21781, 8,1}, /* core1 elr_EL3 bit6 */
			{21780, 8,1}, /* core1 elr_EL3 bit7 */
			{21779, 8,1}, /* core1 elr_EL3 bit8 */
			{21794, 8,1}, /* core1 elr_EL3 bit9 */
			{21793, 8,1}, /* core1 elr_EL3 bit10 */
			{21792, 8,1}, /* core1 elr_EL3 bit11 */
			{21791, 8,1}, /* core1 elr_EL3 bit12 */
			{21796, 8,1}, /* core1 elr_EL3 bit13 */
			{21795, 8,1}, /* core1 elr_EL3 bit14 */
			{22663,12,0}, /* core1 elr_EL3 bit15 */
			{22662,12,0}, /* core1 elr_EL3 bit16 */
			{ 9412, 8,0}, /* core1 elr_EL3 bit17 */
			{22671,12,0}, /* core1 elr_EL3 bit18 */
			{ 9411, 8,0}, /* core1 elr_EL3 bit19 */
			{22670,12,0}, /* core1 elr_EL3 bit20 */
			{23413,12,0}, /* core1 elr_EL3 bit21 */
			{23412,12,0}, /* core1 elr_EL3 bit22 */
			{24309,12,0}, /* core1 elr_EL3 bit23 */
			{24308,12,0}, /* core1 elr_EL3 bit24 */
			{ 9410, 8,0}, /* core1 elr_EL3 bit25 */
			{ 9409, 8,0}, /* core1 elr_EL3 bit26 */
			{24307,12,0}, /* core1 elr_EL3 bit27 */
			{24306,12,0}, /* core1 elr_EL3 bit28 */
			{ 9408, 8,0}, /* core1 elr_EL3 bit29 */
			{ 9407, 8,0}, /* core1 elr_EL3 bit30 */
			{10440, 8,1}, /* core1 elr_EL3 bit31 */
			{19343,12,0}, /* core1 elr_EL3 bit32 */
			{19643,12,0}, /* core1 elr_EL3 bit33 */
			{19642,12,0}, /* core1 elr_EL3 bit34 */
			{19342,12,0}, /* core1 elr_EL3 bit35 */
			{19361,12,0}, /* core1 elr_EL3 bit36 */
			{19360,12,0}, /* core1 elr_EL3 bit37 */
			{19319,12,0}, /* core1 elr_EL3 bit38 */
			{19318,12,0}, /* core1 elr_EL3 bit39 */
			{23549,12,0}, /* core1 elr_EL3 bit40 */
			{23548,12,0}, /* core1 elr_EL3 bit41 */
			{10539, 8,1}, /* core1 elr_EL3 bit42 */
			{23551,12,0}, /* core1 elr_EL3 bit43 */
			{23550,12,0}, /* core1 elr_EL3 bit44 */
			{20889,12,0}, /* core1 elr_EL3 bit45 */
			{20888,12,0}, /* core1 elr_EL3 bit46 */
			{19681,12,0}, /* core1 elr_EL3 bit47 */
			{19680,12,0}, /* core1 elr_EL3 bit48 */
			{19601,12,0}, /* core1 elr_EL3 bit49 */
			{19600,12,0}, /* core1 elr_EL3 bit50 */
			{20697,12,0}, /* core1 elr_EL3 bit51 */
			{20696,12,0}, /* core1 elr_EL3 bit52 */
			{20675,12,0}, /* core1 elr_EL3 bit53 */
			{20677,12,0}, /* core1 elr_EL3 bit54 */
			{20674,12,0}, /* core1 elr_EL3 bit55 */
			{19669,12,0}, /* core1 elr_EL3 bit56 */
			{20676,12,0}, /* core1 elr_EL3 bit57 */
			{20679,12,0}, /* core1 elr_EL3 bit58 */
			{20678,12,0}, /* core1 elr_EL3 bit59 */
			{10236, 8,1}, /* core1 elr_EL3 bit60 */
			{19668,12,0}, /* core1 elr_EL3 bit61 */
			{10552, 8,1}, /* core1 elr_EL3 bit62 */
			{10601, 8,1}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{21954, 8,0}, /* core1 raw_pc bit0 */
			{21953, 8,0}, /* core1 raw_pc bit1 */
			{20526, 8,1}, /* core1 raw_pc bit2 */
			{20525, 8,1}, /* core1 raw_pc bit3 */
			{20528, 8,1}, /* core1 raw_pc bit4 */
			{20527, 8,1}, /* core1 raw_pc bit5 */
			{21934, 8,0}, /* core1 raw_pc bit6 */
			{21314, 8,1}, /* core1 raw_pc bit7 */
			{15866,12,1}, /* core1 raw_pc bit8 */
			{15865,12,1}, /* core1 raw_pc bit9 */
			{22010, 8,0}, /* core1 raw_pc bit10 */
			{22009, 8,0}, /* core1 raw_pc bit11 */
			{22014, 8,0}, /* core1 raw_pc bit12 */
			{22013, 8,0}, /* core1 raw_pc bit13 */
			{22012, 8,0}, /* core1 raw_pc bit14 */
			{22011, 8,0}, /* core1 raw_pc bit15 */
			{22004, 8,0}, /* core1 raw_pc bit16 */
			{22008, 8,0}, /* core1 raw_pc bit17 */
			{22003, 8,0}, /* core1 raw_pc bit18 */
			{22006, 8,0}, /* core1 raw_pc bit19 */
			{22007, 8,0}, /* core1 raw_pc bit20 */
			{15868,12,1}, /* core1 raw_pc bit21 */
			{22005, 8,0}, /* core1 raw_pc bit22 */
			{15867,12,1}, /* core1 raw_pc bit23 */
			{22016, 8,0}, /* core1 raw_pc bit24 */
			{22015, 8,0}, /* core1 raw_pc bit25 */
			{22002, 8,0}, /* core1 raw_pc bit26 */
			{22001, 8,0}, /* core1 raw_pc bit27 */
			{22000, 8,0}, /* core1 raw_pc bit28 */
			{21999, 8,0}, /* core1 raw_pc bit29 */
			{21313, 8,1}, /* core1 raw_pc bit30 */
			{22517,12,0}, /* core1 raw_pc bit31 */
			{22516,12,0}, /* core1 raw_pc bit32 */
			{22733,12,0}, /* core1 raw_pc bit33 */
			{22732,12,0}, /* core1 raw_pc bit34 */
			{22743,12,0}, /* core1 raw_pc bit35 */
			{22742,12,0}, /* core1 raw_pc bit36 */
			{22745,12,0}, /* core1 raw_pc bit37 */
			{22744,12,0}, /* core1 raw_pc bit38 */
			{22735,12,0}, /* core1 raw_pc bit39 */
			{22731,12,0}, /* core1 raw_pc bit40 */
			{22730,12,0}, /* core1 raw_pc bit41 */
			{22519,12,0}, /* core1 raw_pc bit42 */
			{22518,12,0}, /* core1 raw_pc bit43 */
			{21001, 8,1}, /* core1 raw_pc bit44 */
			{22734,12,0}, /* core1 raw_pc bit45 */
			{22741,12,0}, /* core1 raw_pc bit46 */
			{22740,12,0}, /* core1 raw_pc bit47 */
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
			{21128, 8,1}, /* core1 pc_iss bit0 */
			{20532, 8,1}, /* core1 pc_iss bit1 */
			{20531, 8,1}, /* core1 pc_iss bit2 */
			{20534, 8,1}, /* core1 pc_iss bit3 */
			{20533, 8,1}, /* core1 pc_iss bit4 */
			{20530, 8,1}, /* core1 pc_iss bit5 */
			{20529, 8,1}, /* core1 pc_iss bit6 */
			{21129, 8,1}, /* core1 pc_iss bit7 */
			{20654, 8,1}, /* core1 pc_iss bit8 */
			{20653, 8,1}, /* core1 pc_iss bit9 */
			{20648, 8,1}, /* core1 pc_iss bit10 */
			{20647, 8,1}, /* core1 pc_iss bit11 */
			{20624, 8,1}, /* core1 pc_iss bit12 */
			{20644, 8,1}, /* core1 pc_iss bit13 */
			{20623, 8,1}, /* core1 pc_iss bit14 */
			{20643, 8,1}, /* core1 pc_iss bit15 */
			{20616, 8,1}, /* core1 pc_iss bit16 */
			{20615, 8,1}, /* core1 pc_iss bit17 */
			{20626, 8,1}, /* core1 pc_iss bit18 */
			{20646, 8,1}, /* core1 pc_iss bit19 */
			{20645, 8,1}, /* core1 pc_iss bit20 */
			{20620, 8,1}, /* core1 pc_iss bit21 */
			{20619, 8,1}, /* core1 pc_iss bit22 */
			{20622, 8,1}, /* core1 pc_iss bit23 */
			{20621, 8,1}, /* core1 pc_iss bit24 */
			{20618, 8,1}, /* core1 pc_iss bit25 */
			{20617, 8,1}, /* core1 pc_iss bit26 */
			{20614, 8,1}, /* core1 pc_iss bit27 */
			{20625, 8,1}, /* core1 pc_iss bit28 */
			{20613, 8,1}, /* core1 pc_iss bit29 */
			{20612, 8,1}, /* core1 pc_iss bit30 */
			{20611, 8,1}, /* core1 pc_iss bit31 */
			{20590, 8,1}, /* core1 pc_iss bit32 */
			{20589, 8,1}, /* core1 pc_iss bit33 */
			{20610, 8,1}, /* core1 pc_iss bit34 */
			{20608, 8,1}, /* core1 pc_iss bit35 */
			{20607, 8,1}, /* core1 pc_iss bit36 */
			{20592, 8,1}, /* core1 pc_iss bit37 */
			{20591, 8,1}, /* core1 pc_iss bit38 */
			{20594, 8,1}, /* core1 pc_iss bit39 */
			{20593, 8,1}, /* core1 pc_iss bit40 */
			{22044, 8,0}, /* core1 pc_iss bit41 */
			{20609, 8,1}, /* core1 pc_iss bit42 */
			{22043, 8,0}, /* core1 pc_iss bit43 */
			{20606, 8,1}, /* core1 pc_iss bit44 */
			{21116, 8,1}, /* core1 pc_iss bit45 */
			{20605, 8,1}, /* core1 pc_iss bit46 */
			{20598, 8,1}, /* core1 pc_iss bit47 */
			{20597, 8,1}, /* core1 pc_iss bit48 */
			{20596, 8,1}, /* core1 pc_iss bit49 */
			{20600, 8,1}, /* core1 pc_iss bit50 */
			{20599, 8,1}, /* core1 pc_iss bit51 */
			{22040, 8,0}, /* core1 pc_iss bit52 */
			{20595, 8,1}, /* core1 pc_iss bit53 */
			{22039, 8,0}, /* core1 pc_iss bit54 */
			{22034, 8,0}, /* core1 pc_iss bit55 */
			{22033, 8,0}, /* core1 pc_iss bit56 */
			{20602, 8,1}, /* core1 pc_iss bit57 */
			{20601, 8,1}, /* core1 pc_iss bit58 */
			{22032, 8,0}, /* core1 pc_iss bit59 */
			{22031, 8,0}, /* core1 pc_iss bit60 */
			{22030, 8,0}, /* core1 pc_iss bit61 */
			{22029, 8,0}, /* core1 pc_iss bit62 */
			{21188, 8,1}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 9736, 8,1}, /* core1 full_pc_wr bit0 */
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
			{21158, 8,1}, /* core1 full_pc_ex1 bit0 */
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
	},
	{		/* core 2 */
			.pc = {{
			{23475,13,0}, /* core2 pc bit0 */
			{23745,13,0}, /* core2 pc bit1 */
			{23431,13,0}, /* core2 pc bit2 */
			{23748,13,0}, /* core2 pc bit3 */
			{23472,13,0}, /* core2 pc bit4 */
			{23485,13,0}, /* core2 pc bit5 */
			{23494,13,0}, /* core2 pc bit6 */
			{23484,13,0}, /* core2 pc bit7 */
			{23497,13,0}, /* core2 pc bit8 */
			{23496,13,0}, /* core2 pc bit9 */
			{23501,13,0}, /* core2 pc bit10 */
			{23500,13,0}, /* core2 pc bit11 */
			{21881, 9,1}, /* core2 pc bit12 */
			{23491,13,0}, /* core2 pc bit13 */
			{23468,13,0}, /* core2 pc bit14 */
			{23474,13,0}, /* core2 pc bit15 */
			{23430,13,0}, /* core2 pc bit16 */
			{23433,13,0}, /* core2 pc bit17 */
			{21338,13,0}, /* core2 pc bit18 */
			{23753,13,0}, /* core2 pc bit19 */
			{23752,13,0}, /* core2 pc bit20 */
			{23751,13,0}, /* core2 pc bit21 */
			{23750,13,0}, /* core2 pc bit22 */
			{23744,13,0}, /* core2 pc bit23 */
			{23759,13,0}, /* core2 pc bit24 */
			{21337,13,0}, /* core2 pc bit25 */
			{23764,13,0}, /* core2 pc bit26 */
			{23758,13,0}, /* core2 pc bit27 */
			{23755,13,0}, /* core2 pc bit28 */
			{23754,13,0}, /* core2 pc bit29 */
			{21335,13,0}, /* core2 pc bit30 */
			{21334,13,0}, /* core2 pc bit31 */
			{21357,13,0}, /* core2 pc bit32 */
			{21356,13,0}, /* core2 pc bit33 */
			{23757,13,0}, /* core2 pc bit34 */
			{21359,13,0}, /* core2 pc bit35 */
			{23490,13,0}, /* core2 pc bit36 */
			{23477,13,0}, /* core2 pc bit37 */
			{23476,13,0}, /* core2 pc bit38 */
			{23466,13,0}, /* core2 pc bit39 */
			{23479,13,0}, /* core2 pc bit40 */
			{23775,13,0}, /* core2 pc bit41 */
			{23774,13,0}, /* core2 pc bit42 */
			{23478,13,0}, /* core2 pc bit43 */
			{23481,13,0}, /* core2 pc bit44 */
			{10426, 9,1}, /* core2 pc bit45 */
			{21329,13,0}, /* core2 pc bit46 */
			{21328,13,0}, /* core2 pc bit47 */
			{21358,13,0}, /* core2 pc bit48 */
			{10461, 9,1}, /* core2 pc bit49 */
			{21355,13,0}, /* core2 pc bit50 */
			{21354,13,0}, /* core2 pc bit51 */
			{21377,13,0}, /* core2 pc bit52 */
			{21376,13,0}, /* core2 pc bit53 */
			{21353,13,0}, /* core2 pc bit54 */
			{21336,13,0}, /* core2 pc bit55 */
			{21351,13,0}, /* core2 pc bit56 */
			{21350,13,0}, /* core2 pc bit57 */
			{21375,13,0}, /* core2 pc bit58 */
			{21374,13,0}, /* core2 pc bit59 */
			{21341,13,0}, /* core2 pc bit60 */
			{21340,13,0}, /* core2 pc bit61 */
			{21343,13,0}, /* core2 pc bit62 */
			{21342,13,0}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{14975,13,1}, /* core2 sp32 bit0 */
			{14974,13,1}, /* core2 sp32 bit1 */
			{21822, 9,1}, /* core2 sp32 bit2 */
			{23327,13,0}, /* core2 sp32 bit3 */
			{21824, 9,1}, /* core2 sp32 bit4 */
			{21823, 9,1}, /* core2 sp32 bit5 */
			{21820, 9,1}, /* core2 sp32 bit6 */
			{21819, 9,1}, /* core2 sp32 bit7 */
			{21816, 9,1}, /* core2 sp32 bit8 */
			{21821, 9,1}, /* core2 sp32 bit9 */
			{21815, 9,1}, /* core2 sp32 bit10 */
			{15609,13,1}, /* core2 sp32 bit11 */
			{15608,13,1}, /* core2 sp32 bit12 */
			{21818, 9,1}, /* core2 sp32 bit13 */
			{21817, 9,1}, /* core2 sp32 bit14 */
			{20725, 9,1}, /* core2 sp32 bit15 */
			{20109,13,0}, /* core2 sp32 bit16 */
			{10372, 9,1}, /* core2 sp32 bit17 */
			{10371, 9,1}, /* core2 sp32 bit18 */
			{22952, 9,1}, /* core2 sp32 bit19 */
			{20108,13,0}, /* core2 sp32 bit20 */
			{20111,13,0}, /* core2 sp32 bit21 */
			{20110,13,0}, /* core2 sp32 bit22 */
			{22951, 9,1}, /* core2 sp32 bit23 */
			{24341,13,0}, /* core2 sp32 bit24 */
			{23326,13,0}, /* core2 sp32 bit25 */
			{22369,13,0}, /* core2 sp32 bit26 */
			{22368,13,0}, /* core2 sp32 bit27 */
			{22371,13,0}, /* core2 sp32 bit28 */
			{22370,13,0}, /* core2 sp32 bit29 */
			{10391, 9,1}, /* core2 sp32 bit30 */
			{24340,13,0}, /* core2 sp32 bit31 */
			{20815,13,0}, /* core2 sp32 bit32 */
			{20814,13,0}, /* core2 sp32 bit33 */
			{19941,13,0}, /* core2 sp32 bit34 */
			{19940,13,0}, /* core2 sp32 bit35 */
			{19943,13,0}, /* core2 sp32 bit36 */
			{19942,13,0}, /* core2 sp32 bit37 */
			{20853,13,0}, /* core2 sp32 bit38 */
			{20852,13,0}, /* core2 sp32 bit39 */
			{19945,13,0}, /* core2 sp32 bit40 */
			{19944,13,0}, /* core2 sp32 bit41 */
			{10529, 9,1}, /* core2 sp32 bit42 */
			{20023,13,0}, /* core2 sp32 bit43 */
			{20022,13,0}, /* core2 sp32 bit44 */
			{20021,13,0}, /* core2 sp32 bit45 */
			{20020,13,0}, /* core2 sp32 bit46 */
			{20575,13,0}, /* core2 sp32 bit47 */
			{20574,13,0}, /* core2 sp32 bit48 */
			{20419,13,0}, /* core2 sp32 bit49 */
			{20417,13,0}, /* core2 sp32 bit50 */
			{20416,13,0}, /* core2 sp32 bit51 */
			{20415,13,0}, /* core2 sp32 bit52 */
			{20414,13,0}, /* core2 sp32 bit53 */
			{20413,13,0}, /* core2 sp32 bit54 */
			{20412,13,0}, /* core2 sp32 bit55 */
			{20585,13,0}, /* core2 sp32 bit56 */
			{20584,13,0}, /* core2 sp32 bit57 */
			{20425,13,0}, /* core2 sp32 bit58 */
			{20424,13,0}, /* core2 sp32 bit59 */
			{11036, 9,1}, /* core2 sp32 bit60 */
			{20418,13,0}, /* core2 sp32 bit61 */
			{11035, 9,1}, /* core2 sp32 bit62 */
			{22394, 9,0}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{14883,13,1}, /* core2 fp32 bit0 */
			{14882,13,1}, /* core2 fp32 bit1 */
			{23040, 9,1}, /* core2 fp32 bit2 */
			{10868, 9,0}, /* core2 fp32 bit3 */
			{20151,13,0}, /* core2 fp32 bit4 */
			{20150,13,0}, /* core2 fp32 bit5 */
			{10950, 9,0}, /* core2 fp32 bit6 */
			{10949, 9,0}, /* core2 fp32 bit7 */
			{10948, 9,0}, /* core2 fp32 bit8 */
			{10947, 9,0}, /* core2 fp32 bit9 */
			{11478, 9,0}, /* core2 fp32 bit10 */
			{11477, 9,0}, /* core2 fp32 bit11 */
			{20081,13,0}, /* core2 fp32 bit12 */
			{20080,13,0}, /* core2 fp32 bit13 */
			{20099,13,0}, /* core2 fp32 bit14 */
			{20098,13,0}, /* core2 fp32 bit15 */
			{10867, 9,0}, /* core2 fp32 bit16 */
			{10886, 9,0}, /* core2 fp32 bit17 */
			{10885, 9,0}, /* core2 fp32 bit18 */
			{10882, 9,0}, /* core2 fp32 bit19 */
			{23312, 9,0}, /* core2 fp32 bit20 */
			{10881, 9,0}, /* core2 fp32 bit21 */
			{23039, 9,1}, /* core2 fp32 bit22 */
			{23006, 9,1}, /* core2 fp32 bit23 */
			{22944, 9,1}, /* core2 fp32 bit24 */
			{23005, 9,1}, /* core2 fp32 bit25 */
			{22978, 9,1}, /* core2 fp32 bit26 */
			{22943, 9,1}, /* core2 fp32 bit27 */
			{22942, 9,1}, /* core2 fp32 bit28 */
			{22977, 9,1}, /* core2 fp32 bit29 */
			{23316, 9,0}, /* core2 fp32 bit30 */
			{22941, 9,1}, /* core2 fp32 bit31 */
			{19545,13,0}, /* core2 fp32 bit32 */
			{19544,13,0}, /* core2 fp32 bit33 */
			{19547,13,0}, /* core2 fp32 bit34 */
			{19546,13,0}, /* core2 fp32 bit35 */
			{19289,13,0}, /* core2 fp32 bit36 */
			{19288,13,0}, /* core2 fp32 bit37 */
			{20357,13,0}, /* core2 fp32 bit38 */
			{20356,13,0}, /* core2 fp32 bit39 */
			{19575,13,0}, /* core2 fp32 bit40 */
			{10593, 9,1}, /* core2 fp32 bit41 */
			{19574,13,0}, /* core2 fp32 bit42 */
			{20825,13,0}, /* core2 fp32 bit43 */
			{20824,13,0}, /* core2 fp32 bit44 */
			{20009,13,0}, /* core2 fp32 bit45 */
			{20008,13,0}, /* core2 fp32 bit46 */
			{20373,13,0}, /* core2 fp32 bit47 */
			{20372,13,0}, /* core2 fp32 bit48 */
			{20353,13,0}, /* core2 fp32 bit49 */
			{20345,13,0}, /* core2 fp32 bit50 */
			{20344,13,0}, /* core2 fp32 bit51 */
			{20343,13,0}, /* core2 fp32 bit52 */
			{20342,13,0}, /* core2 fp32 bit53 */
			{20393,13,0}, /* core2 fp32 bit54 */
			{20392,13,0}, /* core2 fp32 bit55 */
			{20391,13,0}, /* core2 fp32 bit56 */
			{20390,13,0}, /* core2 fp32 bit57 */
			{20395,13,0}, /* core2 fp32 bit58 */
			{20394,13,0}, /* core2 fp32 bit59 */
			{11019, 9,1}, /* core2 fp32 bit60 */
			{20352,13,0}, /* core2 fp32 bit61 */
			{11027, 9,1}, /* core2 fp32 bit62 */
			{10587, 9,1}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{21567,13,0}, /* core2 fp64 bit0 */
			{21566,13,0}, /* core2 fp64 bit1 */
			{21565,13,0}, /* core2 fp64 bit2 */
			{21564,13,0}, /* core2 fp64 bit3 */
			{22473,13,0}, /* core2 fp64 bit4 */
			{22472,13,0}, /* core2 fp64 bit5 */
			{22467,13,0}, /* core2 fp64 bit6 */
			{22466,13,0}, /* core2 fp64 bit7 */
			{22645,13,0}, /* core2 fp64 bit8 */
			{22644,13,0}, /* core2 fp64 bit9 */
			{22469,13,0}, /* core2 fp64 bit10 */
			{22468,13,0}, /* core2 fp64 bit11 */
			{22471,13,0}, /* core2 fp64 bit12 */
			{22470,13,0}, /* core2 fp64 bit13 */
			{22603,13,0}, /* core2 fp64 bit14 */
			{22602,13,0}, /* core2 fp64 bit15 */
			{22599,13,0}, /* core2 fp64 bit16 */
			{22598,13,0}, /* core2 fp64 bit17 */
			{22429,13,0}, /* core2 fp64 bit18 */
			{22428,13,0}, /* core2 fp64 bit19 */
			{22597,13,0}, /* core2 fp64 bit20 */
			{22596,13,0}, /* core2 fp64 bit21 */
			{23405,13,0}, /* core2 fp64 bit22 */
			{23407,13,0}, /* core2 fp64 bit23 */
			{23406,13,0}, /* core2 fp64 bit24 */
			{23391,13,0}, /* core2 fp64 bit25 */
			{23390,13,0}, /* core2 fp64 bit26 */
			{23387,13,0}, /* core2 fp64 bit27 */
			{10454, 9,1}, /* core2 fp64 bit28 */
			{23386,13,0}, /* core2 fp64 bit29 */
			{10455, 9,1}, /* core2 fp64 bit30 */
			{23404,13,0}, /* core2 fp64 bit31 */
			{19355,13,0}, /* core2 fp64 bit32 */
			{19354,13,0}, /* core2 fp64 bit33 */
			{19349,13,0}, /* core2 fp64 bit34 */
			{19348,13,0}, /* core2 fp64 bit35 */
			{19375,13,0}, /* core2 fp64 bit36 */
			{19374,13,0}, /* core2 fp64 bit37 */
			{20951,13,0}, /* core2 fp64 bit38 */
			{20950,13,0}, /* core2 fp64 bit39 */
			{20909,13,0}, /* core2 fp64 bit40 */
			{20908,13,0}, /* core2 fp64 bit41 */
			{20911,13,0}, /* core2 fp64 bit42 */
			{20915,13,0}, /* core2 fp64 bit43 */
			{20910,13,0}, /* core2 fp64 bit44 */
			{20914,13,0}, /* core2 fp64 bit45 */
			{10605, 9,1}, /* core2 fp64 bit46 */
			{19677,13,0}, /* core2 fp64 bit47 */
			{19676,13,0}, /* core2 fp64 bit48 */
			{19671,13,0}, /* core2 fp64 bit49 */
			{19715,13,0}, /* core2 fp64 bit50 */
			{19714,13,0}, /* core2 fp64 bit51 */
			{19719,13,0}, /* core2 fp64 bit52 */
			{19718,13,0}, /* core2 fp64 bit53 */
			{19721,13,0}, /* core2 fp64 bit54 */
			{19720,13,0}, /* core2 fp64 bit55 */
			{19670,13,0}, /* core2 fp64 bit56 */
			{19717,13,0}, /* core2 fp64 bit57 */
			{19716,13,0}, /* core2 fp64 bit58 */
			{19713,13,0}, /* core2 fp64 bit59 */
			{19712,13,0}, /* core2 fp64 bit60 */
			{19675,13,0}, /* core2 fp64 bit61 */
			{19674,13,0}, /* core2 fp64 bit62 */
			{10544, 9,1}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{24337,13,0}, /* core2 sp_EL0 bit0 */
			{24336,13,0}, /* core2 sp_EL0 bit1 */
			{24335,13,0}, /* core2 sp_EL0 bit2 */
			{24334,13,0}, /* core2 sp_EL0 bit3 */
			{21282, 9,1}, /* core2 sp_EL0 bit4 */
			{21281, 9,1}, /* core2 sp_EL0 bit5 */
			{21284, 9,1}, /* core2 sp_EL0 bit6 */
			{21283, 9,1}, /* core2 sp_EL0 bit7 */
			{21311,13,0}, /* core2 sp_EL0 bit8 */
			{21310,13,0}, /* core2 sp_EL0 bit9 */
			{20969, 9,1}, /* core2 sp_EL0 bit10 */
			{20968, 9,1}, /* core2 sp_EL0 bit11 */
			{20971, 9,1}, /* core2 sp_EL0 bit12 */
			{20970, 9,1}, /* core2 sp_EL0 bit13 */
			{22455,13,0}, /* core2 sp_EL0 bit14 */
			{22454,13,0}, /* core2 sp_EL0 bit15 */
			{10419, 9,1}, /* core2 sp_EL0 bit16 */
			{22591,13,0}, /* core2 sp_EL0 bit17 */
			{22590,13,0}, /* core2 sp_EL0 bit18 */
			{22435,13,0}, /* core2 sp_EL0 bit19 */
			{22434,13,0}, /* core2 sp_EL0 bit20 */
			{22587,13,0}, /* core2 sp_EL0 bit21 */
			{22586,13,0}, /* core2 sp_EL0 bit22 */
			{22579,13,0}, /* core2 sp_EL0 bit23 */
			{22578,13,0}, /* core2 sp_EL0 bit24 */
			{24313,13,0}, /* core2 sp_EL0 bit25 */
			{24312,13,0}, /* core2 sp_EL0 bit26 */
			{23367,13,0}, /* core2 sp_EL0 bit27 */
			{23365,13,0}, /* core2 sp_EL0 bit28 */
			{23364,13,0}, /* core2 sp_EL0 bit29 */
			{23366,13,0}, /* core2 sp_EL0 bit30 */
			{10449, 9,1}, /* core2 sp_EL0 bit31 */
			{19341,13,0}, /* core2 sp_EL0 bit32 */
			{19340,13,0}, /* core2 sp_EL0 bit33 */
			{19679,13,0}, /* core2 sp_EL0 bit34 */
			{19678,13,0}, /* core2 sp_EL0 bit35 */
			{19311,13,0}, /* core2 sp_EL0 bit36 */
			{19310,13,0}, /* core2 sp_EL0 bit37 */
			{19369,13,0}, /* core2 sp_EL0 bit38 */
			{19368,13,0}, /* core2 sp_EL0 bit39 */
			{19367,13,0}, /* core2 sp_EL0 bit40 */
			{19366,13,0}, /* core2 sp_EL0 bit41 */
			{20945,13,0}, /* core2 sp_EL0 bit42 */
			{20944,13,0}, /* core2 sp_EL0 bit43 */
			{19377,13,0}, /* core2 sp_EL0 bit44 */
			{10541, 9,1}, /* core2 sp_EL0 bit45 */
			{19376,13,0}, /* core2 sp_EL0 bit46 */
			{19683,13,0}, /* core2 sp_EL0 bit47 */
			{19682,13,0}, /* core2 sp_EL0 bit48 */
			{19663,13,0}, /* core2 sp_EL0 bit49 */
			{20713,13,0}, /* core2 sp_EL0 bit50 */
			{20712,13,0}, /* core2 sp_EL0 bit51 */
			{20707,13,0}, /* core2 sp_EL0 bit52 */
			{20706,13,0}, /* core2 sp_EL0 bit53 */
			{20709,13,0}, /* core2 sp_EL0 bit54 */
			{20708,13,0}, /* core2 sp_EL0 bit55 */
			{19662,13,0}, /* core2 sp_EL0 bit56 */
			{20711,13,0}, /* core2 sp_EL0 bit57 */
			{20710,13,0}, /* core2 sp_EL0 bit58 */
			{11046, 9,1}, /* core2 sp_EL0 bit59 */
			{23293,13,0}, /* core2 sp_EL0 bit60 */
			{23292,13,0}, /* core2 sp_EL0 bit61 */
			{23291,13,0}, /* core2 sp_EL0 bit62 */
			{23290,13,0}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{24351,13,0}, /* core2 sp_EL1 bit0 */
			{24350,13,0}, /* core2 sp_EL1 bit1 */
			{24349,13,0}, /* core2 sp_EL1 bit2 */
			{24348,13,0}, /* core2 sp_EL1 bit3 */
			{22461,13,0}, /* core2 sp_EL1 bit4 */
			{22460,13,0}, /* core2 sp_EL1 bit5 */
			{22647,13,0}, /* core2 sp_EL1 bit6 */
			{22646,13,0}, /* core2 sp_EL1 bit7 */
			{22601,13,0}, /* core2 sp_EL1 bit8 */
			{22600,13,0}, /* core2 sp_EL1 bit9 */
			{22649,13,0}, /* core2 sp_EL1 bit10 */
			{22648,13,0}, /* core2 sp_EL1 bit11 */
			{22463,13,0}, /* core2 sp_EL1 bit12 */
			{22462,13,0}, /* core2 sp_EL1 bit13 */
			{22457,13,0}, /* core2 sp_EL1 bit14 */
			{22456,13,0}, /* core2 sp_EL1 bit15 */
			{22595,13,0}, /* core2 sp_EL1 bit16 */
			{22594,13,0}, /* core2 sp_EL1 bit17 */
			{22427,13,0}, /* core2 sp_EL1 bit18 */
			{23403,13,0}, /* core2 sp_EL1 bit19 */
			{22426,13,0}, /* core2 sp_EL1 bit20 */
			{22431,13,0}, /* core2 sp_EL1 bit21 */
			{22430,13,0}, /* core2 sp_EL1 bit22 */
			{23402,13,0}, /* core2 sp_EL1 bit23 */
			{23389,13,0}, /* core2 sp_EL1 bit24 */
			{23388,13,0}, /* core2 sp_EL1 bit25 */
			{23385,13,0}, /* core2 sp_EL1 bit26 */
			{23384,13,0}, /* core2 sp_EL1 bit27 */
			{10453, 9,1}, /* core2 sp_EL1 bit28 */
			{23383,13,0}, /* core2 sp_EL1 bit29 */
			{23382,13,0}, /* core2 sp_EL1 bit30 */
			{10439, 9,1}, /* core2 sp_EL1 bit31 */
			{19353,13,0}, /* core2 sp_EL1 bit32 */
			{19352,13,0}, /* core2 sp_EL1 bit33 */
			{19351,13,0}, /* core2 sp_EL1 bit34 */
			{19350,13,0}, /* core2 sp_EL1 bit35 */
			{19379,13,0}, /* core2 sp_EL1 bit36 */
			{19378,13,0}, /* core2 sp_EL1 bit37 */
			{19373,13,0}, /* core2 sp_EL1 bit38 */
			{19372,13,0}, /* core2 sp_EL1 bit39 */
			{20947,13,0}, /* core2 sp_EL1 bit40 */
			{20949,13,0}, /* core2 sp_EL1 bit41 */
			{20946,13,0}, /* core2 sp_EL1 bit42 */
			{20948,13,0}, /* core2 sp_EL1 bit43 */
			{20913,13,0}, /* core2 sp_EL1 bit44 */
			{20912,13,0}, /* core2 sp_EL1 bit45 */
			{10604, 9,1}, /* core2 sp_EL1 bit46 */
			{19673,13,0}, /* core2 sp_EL1 bit47 */
			{19672,13,0}, /* core2 sp_EL1 bit48 */
			{19603,13,0}, /* core2 sp_EL1 bit49 */
			{19703,13,0}, /* core2 sp_EL1 bit50 */
			{19702,13,0}, /* core2 sp_EL1 bit51 */
			{19709,13,0}, /* core2 sp_EL1 bit52 */
			{19708,13,0}, /* core2 sp_EL1 bit53 */
			{19707,13,0}, /* core2 sp_EL1 bit54 */
			{19706,13,0}, /* core2 sp_EL1 bit55 */
			{19602,13,0}, /* core2 sp_EL1 bit56 */
			{19711,13,0}, /* core2 sp_EL1 bit57 */
			{19710,13,0}, /* core2 sp_EL1 bit58 */
			{19705,13,0}, /* core2 sp_EL1 bit59 */
			{19704,13,0}, /* core2 sp_EL1 bit60 */
			{19347,13,0}, /* core2 sp_EL1 bit61 */
			{19346,13,0}, /* core2 sp_EL1 bit62 */
			{10543, 9,1}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 9416, 9,0}, /* core2 sp_EL2 bit0 */
			{ 9415, 9,0}, /* core2 sp_EL2 bit1 */
			{ 9414, 9,0}, /* core2 sp_EL2 bit2 */
			{ 9413, 9,0}, /* core2 sp_EL2 bit3 */
			{21307,13,0}, /* core2 sp_EL2 bit4 */
			{21306,13,0}, /* core2 sp_EL2 bit5 */
			{21317,13,0}, /* core2 sp_EL2 bit6 */
			{21316,13,0}, /* core2 sp_EL2 bit7 */
			{21315,13,0}, /* core2 sp_EL2 bit8 */
			{21314,13,0}, /* core2 sp_EL2 bit9 */
			{21313,13,0}, /* core2 sp_EL2 bit10 */
			{21312,13,0}, /* core2 sp_EL2 bit11 */
			{21309,13,0}, /* core2 sp_EL2 bit12 */
			{21308,13,0}, /* core2 sp_EL2 bit13 */
			{21321,13,0}, /* core2 sp_EL2 bit14 */
			{21320,13,0}, /* core2 sp_EL2 bit15 */
			{22433,13,0}, /* core2 sp_EL2 bit16 */
			{22432,13,0}, /* core2 sp_EL2 bit17 */
			{22707,13,0}, /* core2 sp_EL2 bit18 */
			{22706,13,0}, /* core2 sp_EL2 bit19 */
			{10416, 9,1}, /* core2 sp_EL2 bit20 */
			{22585,13,0}, /* core2 sp_EL2 bit21 */
			{22584,13,0}, /* core2 sp_EL2 bit22 */
			{22581,13,0}, /* core2 sp_EL2 bit23 */
			{22580,13,0}, /* core2 sp_EL2 bit24 */
			{22409,13,0}, /* core2 sp_EL2 bit25 */
			{22408,13,0}, /* core2 sp_EL2 bit26 */
			{24323,13,0}, /* core2 sp_EL2 bit27 */
			{24322,13,0}, /* core2 sp_EL2 bit28 */
			{22571,13,0}, /* core2 sp_EL2 bit29 */
			{22570,13,0}, /* core2 sp_EL2 bit30 */
			{10450, 9,1}, /* core2 sp_EL2 bit31 */
			{19299,13,0}, /* core2 sp_EL2 bit32 */
			{19298,13,0}, /* core2 sp_EL2 bit33 */
			{19297,13,0}, /* core2 sp_EL2 bit34 */
			{19296,13,0}, /* core2 sp_EL2 bit35 */
			{19329,13,0}, /* core2 sp_EL2 bit36 */
			{10560, 9,1}, /* core2 sp_EL2 bit37 */
			{19328,13,0}, /* core2 sp_EL2 bit38 */
			{20929,13,0}, /* core2 sp_EL2 bit39 */
			{20928,13,0}, /* core2 sp_EL2 bit40 */
			{20931,13,0}, /* core2 sp_EL2 bit41 */
			{20930,13,0}, /* core2 sp_EL2 bit42 */
			{23311,13,0}, /* core2 sp_EL2 bit43 */
			{23310,13,0}, /* core2 sp_EL2 bit44 */
			{23309,13,0}, /* core2 sp_EL2 bit45 */
			{23308,13,0}, /* core2 sp_EL2 bit46 */
			{19651,13,0}, /* core2 sp_EL2 bit47 */
			{20669,13,0}, /* core2 sp_EL2 bit48 */
			{19650,13,0}, /* core2 sp_EL2 bit49 */
			{20668,13,0}, /* core2 sp_EL2 bit50 */
			{20617,13,0}, /* core2 sp_EL2 bit51 */
			{20616,13,0}, /* core2 sp_EL2 bit52 */
			{20601,13,0}, /* core2 sp_EL2 bit53 */
			{20600,13,0}, /* core2 sp_EL2 bit54 */
			{20603,13,0}, /* core2 sp_EL2 bit55 */
			{20629,13,0}, /* core2 sp_EL2 bit56 */
			{20602,13,0}, /* core2 sp_EL2 bit57 */
			{20613,13,0}, /* core2 sp_EL2 bit58 */
			{20612,13,0}, /* core2 sp_EL2 bit59 */
			{11044, 9,1}, /* core2 sp_EL2 bit60 */
			{20628,13,0}, /* core2 sp_EL2 bit61 */
			{11045, 9,1}, /* core2 sp_EL2 bit62 */
			{10559, 9,1}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{23371,13,0}, /* core2 sp_EL3 bit0 */
			{22411,13,0}, /* core2 sp_EL3 bit1 */
			{23370,13,0}, /* core2 sp_EL3 bit2 */
			{10452, 9,1}, /* core2 sp_EL3 bit3 */
			{22653,13,0}, /* core2 sp_EL3 bit4 */
			{22652,13,0}, /* core2 sp_EL3 bit5 */
			{22651,13,0}, /* core2 sp_EL3 bit6 */
			{22650,13,0}, /* core2 sp_EL3 bit7 */
			{22659,13,0}, /* core2 sp_EL3 bit8 */
			{22658,13,0}, /* core2 sp_EL3 bit9 */
			{22655,13,0}, /* core2 sp_EL3 bit10 */
			{22654,13,0}, /* core2 sp_EL3 bit11 */
			{22657,13,0}, /* core2 sp_EL3 bit12 */
			{22656,13,0}, /* core2 sp_EL3 bit13 */
			{10420, 9,1}, /* core2 sp_EL3 bit14 */
			{22661,13,0}, /* core2 sp_EL3 bit15 */
			{22660,13,0}, /* core2 sp_EL3 bit16 */
			{22593,13,0}, /* core2 sp_EL3 bit17 */
			{22589,13,0}, /* core2 sp_EL3 bit18 */
			{22588,13,0}, /* core2 sp_EL3 bit19 */
			{22592,13,0}, /* core2 sp_EL3 bit20 */
			{23411,13,0}, /* core2 sp_EL3 bit21 */
			{23410,13,0}, /* core2 sp_EL3 bit22 */
			{22410,13,0}, /* core2 sp_EL3 bit23 */
			{23409,13,0}, /* core2 sp_EL3 bit24 */
			{23408,13,0}, /* core2 sp_EL3 bit25 */
			{23719,13,0}, /* core2 sp_EL3 bit26 */
			{23718,13,0}, /* core2 sp_EL3 bit27 */
			{23373,13,0}, /* core2 sp_EL3 bit28 */
			{23372,13,0}, /* core2 sp_EL3 bit29 */
			{23381,13,0}, /* core2 sp_EL3 bit30 */
			{23380,13,0}, /* core2 sp_EL3 bit31 */
			{19309,13,0}, /* core2 sp_EL3 bit32 */
			{19308,13,0}, /* core2 sp_EL3 bit33 */
			{19359,13,0}, /* core2 sp_EL3 bit34 */
			{19357,13,0}, /* core2 sp_EL3 bit35 */
			{19356,13,0}, /* core2 sp_EL3 bit36 */
			{19365,13,0}, /* core2 sp_EL3 bit37 */
			{19364,13,0}, /* core2 sp_EL3 bit38 */
			{19363,13,0}, /* core2 sp_EL3 bit39 */
			{19362,13,0}, /* core2 sp_EL3 bit40 */
			{20943,13,0}, /* core2 sp_EL3 bit41 */
			{20942,13,0}, /* core2 sp_EL3 bit42 */
			{20941,13,0}, /* core2 sp_EL3 bit43 */
			{20940,13,0}, /* core2 sp_EL3 bit44 */
			{10557, 9,1}, /* core2 sp_EL3 bit45 */
			{19358,13,0}, /* core2 sp_EL3 bit46 */
			{19657,13,0}, /* core2 sp_EL3 bit47 */
			{19699,13,0}, /* core2 sp_EL3 bit48 */
			{19656,13,0}, /* core2 sp_EL3 bit49 */
			{20691,13,0}, /* core2 sp_EL3 bit50 */
			{19698,13,0}, /* core2 sp_EL3 bit51 */
			{20690,13,0}, /* core2 sp_EL3 bit52 */
			{20673,13,0}, /* core2 sp_EL3 bit53 */
			{20683,13,0}, /* core2 sp_EL3 bit54 */
			{20682,13,0}, /* core2 sp_EL3 bit55 */
			{20672,13,0}, /* core2 sp_EL3 bit56 */
			{20671,13,0}, /* core2 sp_EL3 bit57 */
			{20670,13,0}, /* core2 sp_EL3 bit58 */
			{20681,13,0}, /* core2 sp_EL3 bit59 */
			{20680,13,0}, /* core2 sp_EL3 bit60 */
			{19659,13,0}, /* core2 sp_EL3 bit61 */
			{19658,13,0}, /* core2 sp_EL3 bit62 */
			{10551, 9,1}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{24321,13,0}, /* core2 elr_EL1 bit0 */
			{24320,13,0}, /* core2 elr_EL1 bit1 */
			{24319,13,0}, /* core2 elr_EL1 bit2 */
			{24318,13,0}, /* core2 elr_EL1 bit3 */
			{23789,13,0}, /* core2 elr_EL1 bit4 */
			{23788,13,0}, /* core2 elr_EL1 bit5 */
			{22451,13,0}, /* core2 elr_EL1 bit6 */
			{22450,13,0}, /* core2 elr_EL1 bit7 */
			{22453,13,0}, /* core2 elr_EL1 bit8 */
			{22452,13,0}, /* core2 elr_EL1 bit9 */
			{21305,13,0}, /* core2 elr_EL1 bit10 */
			{21304,13,0}, /* core2 elr_EL1 bit11 */
			{22449,13,0}, /* core2 elr_EL1 bit12 */
			{22448,13,0}, /* core2 elr_EL1 bit13 */
			{10418, 9,1}, /* core2 elr_EL1 bit14 */
			{22667,13,0}, /* core2 elr_EL1 bit15 */
			{22666,13,0}, /* core2 elr_EL1 bit16 */
			{22669,13,0}, /* core2 elr_EL1 bit17 */
			{22703,13,0}, /* core2 elr_EL1 bit18 */
			{22702,13,0}, /* core2 elr_EL1 bit19 */
			{22668,13,0}, /* core2 elr_EL1 bit20 */
			{22405,13,0}, /* core2 elr_EL1 bit21 */
			{22407,13,0}, /* core2 elr_EL1 bit22 */
			{22406,13,0}, /* core2 elr_EL1 bit23 */
			{22404,13,0}, /* core2 elr_EL1 bit24 */
			{23379,13,0}, /* core2 elr_EL1 bit25 */
			{23378,13,0}, /* core2 elr_EL1 bit26 */
			{22415,13,0}, /* core2 elr_EL1 bit27 */
			{10451, 9,1}, /* core2 elr_EL1 bit28 */
			{22414,13,0}, /* core2 elr_EL1 bit29 */
			{22413,13,0}, /* core2 elr_EL1 bit30 */
			{22412,13,0}, /* core2 elr_EL1 bit31 */
			{19307,13,0}, /* core2 elr_EL1 bit32 */
			{19306,13,0}, /* core2 elr_EL1 bit33 */
			{19641,13,0}, /* core2 elr_EL1 bit34 */
			{19640,13,0}, /* core2 elr_EL1 bit35 */
			{10555, 9,1}, /* core2 elr_EL1 bit36 */
			{19321,13,0}, /* core2 elr_EL1 bit37 */
			{19320,13,0}, /* core2 elr_EL1 bit38 */
			{19317,13,0}, /* core2 elr_EL1 bit39 */
			{19316,13,0}, /* core2 elr_EL1 bit40 */
			{20923,13,0}, /* core2 elr_EL1 bit41 */
			{20922,13,0}, /* core2 elr_EL1 bit42 */
			{20917,13,0}, /* core2 elr_EL1 bit43 */
			{20916,13,0}, /* core2 elr_EL1 bit44 */
			{20939,13,0}, /* core2 elr_EL1 bit45 */
			{20938,13,0}, /* core2 elr_EL1 bit46 */
			{19667,13,0}, /* core2 elr_EL1 bit47 */
			{19599,13,0}, /* core2 elr_EL1 bit48 */
			{19666,13,0}, /* core2 elr_EL1 bit49 */
			{19598,13,0}, /* core2 elr_EL1 bit50 */
			{19701,13,0}, /* core2 elr_EL1 bit51 */
			{19700,13,0}, /* core2 elr_EL1 bit52 */
			{19597,13,0}, /* core2 elr_EL1 bit53 */
			{19596,13,0}, /* core2 elr_EL1 bit54 */
			{20699,13,0}, /* core2 elr_EL1 bit55 */
			{19665,13,0}, /* core2 elr_EL1 bit56 */
			{20698,13,0}, /* core2 elr_EL1 bit57 */
			{20701,13,0}, /* core2 elr_EL1 bit58 */
			{20700,13,0}, /* core2 elr_EL1 bit59 */
			{10237, 9,1}, /* core2 elr_EL1 bit60 */
			{19664,13,0}, /* core2 elr_EL1 bit61 */
			{10238, 9,1}, /* core2 elr_EL1 bit62 */
			{10556, 9,1}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{10445, 9,1}, /* core2 elr_EL2 bit0 */
			{23333,13,0}, /* core2 elr_EL2 bit1 */
			{23332,13,0}, /* core2 elr_EL2 bit2 */
			{23337,13,0}, /* core2 elr_EL2 bit3 */
			{21299,13,0}, /* core2 elr_EL2 bit4 */
			{21298,13,0}, /* core2 elr_EL2 bit5 */
			{21303,13,0}, /* core2 elr_EL2 bit6 */
			{21302,13,0}, /* core2 elr_EL2 bit7 */
			{22447,13,0}, /* core2 elr_EL2 bit8 */
			{22446,13,0}, /* core2 elr_EL2 bit9 */
			{21301,13,0}, /* core2 elr_EL2 bit10 */
			{21300,13,0}, /* core2 elr_EL2 bit11 */
			{22445,13,0}, /* core2 elr_EL2 bit12 */
			{22444,13,0}, /* core2 elr_EL2 bit13 */
			{22441,13,0}, /* core2 elr_EL2 bit14 */
			{22440,13,0}, /* core2 elr_EL2 bit15 */
			{22679,13,0}, /* core2 elr_EL2 bit16 */
			{22678,13,0}, /* core2 elr_EL2 bit17 */
			{22685,13,0}, /* core2 elr_EL2 bit18 */
			{22684,13,0}, /* core2 elr_EL2 bit19 */
			{22677,13,0}, /* core2 elr_EL2 bit20 */
			{22676,13,0}, /* core2 elr_EL2 bit21 */
			{22689,13,0}, /* core2 elr_EL2 bit22 */
			{23335,13,0}, /* core2 elr_EL2 bit23 */
			{22688,13,0}, /* core2 elr_EL2 bit24 */
			{23336,13,0}, /* core2 elr_EL2 bit25 */
			{23345,13,0}, /* core2 elr_EL2 bit26 */
			{23344,13,0}, /* core2 elr_EL2 bit27 */
			{23334,13,0}, /* core2 elr_EL2 bit28 */
			{14893,13,1}, /* core2 elr_EL2 bit29 */
			{14892,13,1}, /* core2 elr_EL2 bit30 */
			{10442, 9,1}, /* core2 elr_EL2 bit31 */
			{19301,13,0}, /* core2 elr_EL2 bit32 */
			{19300,13,0}, /* core2 elr_EL2 bit33 */
			{19647,13,0}, /* core2 elr_EL2 bit34 */
			{19646,13,0}, /* core2 elr_EL2 bit35 */
			{19337,13,0}, /* core2 elr_EL2 bit36 */
			{19336,13,0}, /* core2 elr_EL2 bit37 */
			{19639,13,0}, /* core2 elr_EL2 bit38 */
			{19638,13,0}, /* core2 elr_EL2 bit39 */
			{20925,13,0}, /* core2 elr_EL2 bit40 */
			{20924,13,0}, /* core2 elr_EL2 bit41 */
			{20921,13,0}, /* core2 elr_EL2 bit42 */
			{20920,13,0}, /* core2 elr_EL2 bit43 */
			{20919,13,0}, /* core2 elr_EL2 bit44 */
			{20918,13,0}, /* core2 elr_EL2 bit45 */
			{10536, 9,1}, /* core2 elr_EL2 bit46 */
			{19655,13,0}, /* core2 elr_EL2 bit47 */
			{19654,13,0}, /* core2 elr_EL2 bit48 */
			{19697,13,0}, /* core2 elr_EL2 bit49 */
			{19593,13,0}, /* core2 elr_EL2 bit50 */
			{19592,13,0}, /* core2 elr_EL2 bit51 */
			{20627,13,0}, /* core2 elr_EL2 bit52 */
			{20626,13,0}, /* core2 elr_EL2 bit53 */
			{19595,13,0}, /* core2 elr_EL2 bit54 */
			{19594,13,0}, /* core2 elr_EL2 bit55 */
			{19696,13,0}, /* core2 elr_EL2 bit56 */
			{20625,13,0}, /* core2 elr_EL2 bit57 */
			{20624,13,0}, /* core2 elr_EL2 bit58 */
			{19591,13,0}, /* core2 elr_EL2 bit59 */
			{19590,13,0}, /* core2 elr_EL2 bit60 */
			{19695,13,0}, /* core2 elr_EL2 bit61 */
			{19694,13,0}, /* core2 elr_EL2 bit62 */
			{10554, 9,1}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{24317,13,0}, /* core2 elr_EL3 bit0 */
			{24316,13,0}, /* core2 elr_EL3 bit1 */
			{24315,13,0}, /* core2 elr_EL3 bit2 */
			{24314,13,0}, /* core2 elr_EL3 bit3 */
			{21782, 9,1}, /* core2 elr_EL3 bit4 */
			{20733, 9,1}, /* core2 elr_EL3 bit5 */
			{21781, 9,1}, /* core2 elr_EL3 bit6 */
			{21780, 9,1}, /* core2 elr_EL3 bit7 */
			{21779, 9,1}, /* core2 elr_EL3 bit8 */
			{21794, 9,1}, /* core2 elr_EL3 bit9 */
			{21793, 9,1}, /* core2 elr_EL3 bit10 */
			{21792, 9,1}, /* core2 elr_EL3 bit11 */
			{21791, 9,1}, /* core2 elr_EL3 bit12 */
			{21796, 9,1}, /* core2 elr_EL3 bit13 */
			{21795, 9,1}, /* core2 elr_EL3 bit14 */
			{22663,13,0}, /* core2 elr_EL3 bit15 */
			{22662,13,0}, /* core2 elr_EL3 bit16 */
			{ 9412, 9,0}, /* core2 elr_EL3 bit17 */
			{22671,13,0}, /* core2 elr_EL3 bit18 */
			{ 9411, 9,0}, /* core2 elr_EL3 bit19 */
			{22670,13,0}, /* core2 elr_EL3 bit20 */
			{23413,13,0}, /* core2 elr_EL3 bit21 */
			{23412,13,0}, /* core2 elr_EL3 bit22 */
			{24309,13,0}, /* core2 elr_EL3 bit23 */
			{24308,13,0}, /* core2 elr_EL3 bit24 */
			{ 9410, 9,0}, /* core2 elr_EL3 bit25 */
			{ 9409, 9,0}, /* core2 elr_EL3 bit26 */
			{24307,13,0}, /* core2 elr_EL3 bit27 */
			{24306,13,0}, /* core2 elr_EL3 bit28 */
			{ 9408, 9,0}, /* core2 elr_EL3 bit29 */
			{ 9407, 9,0}, /* core2 elr_EL3 bit30 */
			{10440, 9,1}, /* core2 elr_EL3 bit31 */
			{19343,13,0}, /* core2 elr_EL3 bit32 */
			{19643,13,0}, /* core2 elr_EL3 bit33 */
			{19642,13,0}, /* core2 elr_EL3 bit34 */
			{19342,13,0}, /* core2 elr_EL3 bit35 */
			{19361,13,0}, /* core2 elr_EL3 bit36 */
			{19360,13,0}, /* core2 elr_EL3 bit37 */
			{19319,13,0}, /* core2 elr_EL3 bit38 */
			{19318,13,0}, /* core2 elr_EL3 bit39 */
			{23549,13,0}, /* core2 elr_EL3 bit40 */
			{23548,13,0}, /* core2 elr_EL3 bit41 */
			{10539, 9,1}, /* core2 elr_EL3 bit42 */
			{23551,13,0}, /* core2 elr_EL3 bit43 */
			{23550,13,0}, /* core2 elr_EL3 bit44 */
			{20889,13,0}, /* core2 elr_EL3 bit45 */
			{20888,13,0}, /* core2 elr_EL3 bit46 */
			{19681,13,0}, /* core2 elr_EL3 bit47 */
			{19680,13,0}, /* core2 elr_EL3 bit48 */
			{19601,13,0}, /* core2 elr_EL3 bit49 */
			{19600,13,0}, /* core2 elr_EL3 bit50 */
			{20697,13,0}, /* core2 elr_EL3 bit51 */
			{20696,13,0}, /* core2 elr_EL3 bit52 */
			{20675,13,0}, /* core2 elr_EL3 bit53 */
			{20677,13,0}, /* core2 elr_EL3 bit54 */
			{20674,13,0}, /* core2 elr_EL3 bit55 */
			{19669,13,0}, /* core2 elr_EL3 bit56 */
			{20676,13,0}, /* core2 elr_EL3 bit57 */
			{20679,13,0}, /* core2 elr_EL3 bit58 */
			{20678,13,0}, /* core2 elr_EL3 bit59 */
			{10236, 9,1}, /* core2 elr_EL3 bit60 */
			{19668,13,0}, /* core2 elr_EL3 bit61 */
			{10552, 9,1}, /* core2 elr_EL3 bit62 */
			{10601, 9,1}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{21954, 9,0}, /* core2 raw_pc bit0 */
			{21953, 9,0}, /* core2 raw_pc bit1 */
			{20526, 9,1}, /* core2 raw_pc bit2 */
			{20525, 9,1}, /* core2 raw_pc bit3 */
			{20528, 9,1}, /* core2 raw_pc bit4 */
			{20527, 9,1}, /* core2 raw_pc bit5 */
			{21934, 9,0}, /* core2 raw_pc bit6 */
			{21314, 9,1}, /* core2 raw_pc bit7 */
			{15866,13,1}, /* core2 raw_pc bit8 */
			{15865,13,1}, /* core2 raw_pc bit9 */
			{22010, 9,0}, /* core2 raw_pc bit10 */
			{22009, 9,0}, /* core2 raw_pc bit11 */
			{22014, 9,0}, /* core2 raw_pc bit12 */
			{22013, 9,0}, /* core2 raw_pc bit13 */
			{22012, 9,0}, /* core2 raw_pc bit14 */
			{22011, 9,0}, /* core2 raw_pc bit15 */
			{22004, 9,0}, /* core2 raw_pc bit16 */
			{22008, 9,0}, /* core2 raw_pc bit17 */
			{22003, 9,0}, /* core2 raw_pc bit18 */
			{22006, 9,0}, /* core2 raw_pc bit19 */
			{22007, 9,0}, /* core2 raw_pc bit20 */
			{15868,13,1}, /* core2 raw_pc bit21 */
			{22005, 9,0}, /* core2 raw_pc bit22 */
			{15867,13,1}, /* core2 raw_pc bit23 */
			{22016, 9,0}, /* core2 raw_pc bit24 */
			{22015, 9,0}, /* core2 raw_pc bit25 */
			{22002, 9,0}, /* core2 raw_pc bit26 */
			{22001, 9,0}, /* core2 raw_pc bit27 */
			{22000, 9,0}, /* core2 raw_pc bit28 */
			{21999, 9,0}, /* core2 raw_pc bit29 */
			{21313, 9,1}, /* core2 raw_pc bit30 */
			{22517,13,0}, /* core2 raw_pc bit31 */
			{22516,13,0}, /* core2 raw_pc bit32 */
			{22733,13,0}, /* core2 raw_pc bit33 */
			{22732,13,0}, /* core2 raw_pc bit34 */
			{22743,13,0}, /* core2 raw_pc bit35 */
			{22742,13,0}, /* core2 raw_pc bit36 */
			{22745,13,0}, /* core2 raw_pc bit37 */
			{22744,13,0}, /* core2 raw_pc bit38 */
			{22735,13,0}, /* core2 raw_pc bit39 */
			{22731,13,0}, /* core2 raw_pc bit40 */
			{22730,13,0}, /* core2 raw_pc bit41 */
			{22519,13,0}, /* core2 raw_pc bit42 */
			{22518,13,0}, /* core2 raw_pc bit43 */
			{21001, 9,1}, /* core2 raw_pc bit44 */
			{22734,13,0}, /* core2 raw_pc bit45 */
			{22741,13,0}, /* core2 raw_pc bit46 */
			{22740,13,0}, /* core2 raw_pc bit47 */
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
			{21128, 9,1}, /* core2 pc_iss bit0 */
			{20532, 9,1}, /* core2 pc_iss bit1 */
			{20531, 9,1}, /* core2 pc_iss bit2 */
			{20534, 9,1}, /* core2 pc_iss bit3 */
			{20533, 9,1}, /* core2 pc_iss bit4 */
			{20530, 9,1}, /* core2 pc_iss bit5 */
			{20529, 9,1}, /* core2 pc_iss bit6 */
			{21129, 9,1}, /* core2 pc_iss bit7 */
			{20654, 9,1}, /* core2 pc_iss bit8 */
			{20653, 9,1}, /* core2 pc_iss bit9 */
			{20648, 9,1}, /* core2 pc_iss bit10 */
			{20647, 9,1}, /* core2 pc_iss bit11 */
			{20624, 9,1}, /* core2 pc_iss bit12 */
			{20644, 9,1}, /* core2 pc_iss bit13 */
			{20623, 9,1}, /* core2 pc_iss bit14 */
			{20643, 9,1}, /* core2 pc_iss bit15 */
			{20616, 9,1}, /* core2 pc_iss bit16 */
			{20615, 9,1}, /* core2 pc_iss bit17 */
			{20626, 9,1}, /* core2 pc_iss bit18 */
			{20646, 9,1}, /* core2 pc_iss bit19 */
			{20645, 9,1}, /* core2 pc_iss bit20 */
			{20620, 9,1}, /* core2 pc_iss bit21 */
			{20619, 9,1}, /* core2 pc_iss bit22 */
			{20622, 9,1}, /* core2 pc_iss bit23 */
			{20621, 9,1}, /* core2 pc_iss bit24 */
			{20618, 9,1}, /* core2 pc_iss bit25 */
			{20617, 9,1}, /* core2 pc_iss bit26 */
			{20614, 9,1}, /* core2 pc_iss bit27 */
			{20625, 9,1}, /* core2 pc_iss bit28 */
			{20613, 9,1}, /* core2 pc_iss bit29 */
			{20612, 9,1}, /* core2 pc_iss bit30 */
			{20611, 9,1}, /* core2 pc_iss bit31 */
			{20590, 9,1}, /* core2 pc_iss bit32 */
			{20589, 9,1}, /* core2 pc_iss bit33 */
			{20610, 9,1}, /* core2 pc_iss bit34 */
			{20608, 9,1}, /* core2 pc_iss bit35 */
			{20607, 9,1}, /* core2 pc_iss bit36 */
			{20592, 9,1}, /* core2 pc_iss bit37 */
			{20591, 9,1}, /* core2 pc_iss bit38 */
			{20594, 9,1}, /* core2 pc_iss bit39 */
			{20593, 9,1}, /* core2 pc_iss bit40 */
			{22044, 9,0}, /* core2 pc_iss bit41 */
			{20609, 9,1}, /* core2 pc_iss bit42 */
			{22043, 9,0}, /* core2 pc_iss bit43 */
			{20606, 9,1}, /* core2 pc_iss bit44 */
			{21116, 9,1}, /* core2 pc_iss bit45 */
			{20605, 9,1}, /* core2 pc_iss bit46 */
			{20598, 9,1}, /* core2 pc_iss bit47 */
			{20597, 9,1}, /* core2 pc_iss bit48 */
			{20596, 9,1}, /* core2 pc_iss bit49 */
			{20600, 9,1}, /* core2 pc_iss bit50 */
			{20599, 9,1}, /* core2 pc_iss bit51 */
			{22040, 9,0}, /* core2 pc_iss bit52 */
			{20595, 9,1}, /* core2 pc_iss bit53 */
			{22039, 9,0}, /* core2 pc_iss bit54 */
			{22034, 9,0}, /* core2 pc_iss bit55 */
			{22033, 9,0}, /* core2 pc_iss bit56 */
			{20602, 9,1}, /* core2 pc_iss bit57 */
			{20601, 9,1}, /* core2 pc_iss bit58 */
			{22032, 9,0}, /* core2 pc_iss bit59 */
			{22031, 9,0}, /* core2 pc_iss bit60 */
			{22030, 9,0}, /* core2 pc_iss bit61 */
			{22029, 9,0}, /* core2 pc_iss bit62 */
			{21188, 9,1}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 9736, 9,1}, /* core2 full_pc_wr bit0 */
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
			{21158, 9,1}, /* core2 full_pc_ex1 bit0 */
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
	},
	{		/* core 3 */
			.pc = {{
			{23475,14,0}, /* core3 pc bit0 */
			{23745,14,0}, /* core3 pc bit1 */
			{23431,14,0}, /* core3 pc bit2 */
			{23748,14,0}, /* core3 pc bit3 */
			{23472,14,0}, /* core3 pc bit4 */
			{23485,14,0}, /* core3 pc bit5 */
			{23494,14,0}, /* core3 pc bit6 */
			{23484,14,0}, /* core3 pc bit7 */
			{23497,14,0}, /* core3 pc bit8 */
			{23496,14,0}, /* core3 pc bit9 */
			{23501,14,0}, /* core3 pc bit10 */
			{23500,14,0}, /* core3 pc bit11 */
			{21881,10,1}, /* core3 pc bit12 */
			{23491,14,0}, /* core3 pc bit13 */
			{23468,14,0}, /* core3 pc bit14 */
			{23474,14,0}, /* core3 pc bit15 */
			{23430,14,0}, /* core3 pc bit16 */
			{23433,14,0}, /* core3 pc bit17 */
			{21338,14,0}, /* core3 pc bit18 */
			{23753,14,0}, /* core3 pc bit19 */
			{23752,14,0}, /* core3 pc bit20 */
			{23751,14,0}, /* core3 pc bit21 */
			{23750,14,0}, /* core3 pc bit22 */
			{23744,14,0}, /* core3 pc bit23 */
			{23759,14,0}, /* core3 pc bit24 */
			{21337,14,0}, /* core3 pc bit25 */
			{23764,14,0}, /* core3 pc bit26 */
			{23758,14,0}, /* core3 pc bit27 */
			{23755,14,0}, /* core3 pc bit28 */
			{23754,14,0}, /* core3 pc bit29 */
			{21335,14,0}, /* core3 pc bit30 */
			{21334,14,0}, /* core3 pc bit31 */
			{21357,14,0}, /* core3 pc bit32 */
			{21356,14,0}, /* core3 pc bit33 */
			{23757,14,0}, /* core3 pc bit34 */
			{21359,14,0}, /* core3 pc bit35 */
			{23490,14,0}, /* core3 pc bit36 */
			{23477,14,0}, /* core3 pc bit37 */
			{23476,14,0}, /* core3 pc bit38 */
			{23466,14,0}, /* core3 pc bit39 */
			{23479,14,0}, /* core3 pc bit40 */
			{23775,14,0}, /* core3 pc bit41 */
			{23774,14,0}, /* core3 pc bit42 */
			{23478,14,0}, /* core3 pc bit43 */
			{23481,14,0}, /* core3 pc bit44 */
			{10426,10,1}, /* core3 pc bit45 */
			{21329,14,0}, /* core3 pc bit46 */
			{21328,14,0}, /* core3 pc bit47 */
			{21358,14,0}, /* core3 pc bit48 */
			{10461,10,1}, /* core3 pc bit49 */
			{21355,14,0}, /* core3 pc bit50 */
			{21354,14,0}, /* core3 pc bit51 */
			{21377,14,0}, /* core3 pc bit52 */
			{21376,14,0}, /* core3 pc bit53 */
			{21353,14,0}, /* core3 pc bit54 */
			{21336,14,0}, /* core3 pc bit55 */
			{21351,14,0}, /* core3 pc bit56 */
			{21350,14,0}, /* core3 pc bit57 */
			{21375,14,0}, /* core3 pc bit58 */
			{21374,14,0}, /* core3 pc bit59 */
			{21341,14,0}, /* core3 pc bit60 */
			{21340,14,0}, /* core3 pc bit61 */
			{21343,14,0}, /* core3 pc bit62 */
			{21342,14,0}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{14975,14,1}, /* core3 sp32 bit0 */
			{14974,14,1}, /* core3 sp32 bit1 */
			{21822,10,1}, /* core3 sp32 bit2 */
			{23327,14,0}, /* core3 sp32 bit3 */
			{21824,10,1}, /* core3 sp32 bit4 */
			{21823,10,1}, /* core3 sp32 bit5 */
			{21820,10,1}, /* core3 sp32 bit6 */
			{21819,10,1}, /* core3 sp32 bit7 */
			{21816,10,1}, /* core3 sp32 bit8 */
			{21821,10,1}, /* core3 sp32 bit9 */
			{21815,10,1}, /* core3 sp32 bit10 */
			{15609,14,1}, /* core3 sp32 bit11 */
			{15608,14,1}, /* core3 sp32 bit12 */
			{21818,10,1}, /* core3 sp32 bit13 */
			{21817,10,1}, /* core3 sp32 bit14 */
			{20725,10,1}, /* core3 sp32 bit15 */
			{20109,14,0}, /* core3 sp32 bit16 */
			{10372,10,1}, /* core3 sp32 bit17 */
			{10371,10,1}, /* core3 sp32 bit18 */
			{22952,10,1}, /* core3 sp32 bit19 */
			{20108,14,0}, /* core3 sp32 bit20 */
			{20111,14,0}, /* core3 sp32 bit21 */
			{20110,14,0}, /* core3 sp32 bit22 */
			{22951,10,1}, /* core3 sp32 bit23 */
			{24341,14,0}, /* core3 sp32 bit24 */
			{23326,14,0}, /* core3 sp32 bit25 */
			{22369,14,0}, /* core3 sp32 bit26 */
			{22368,14,0}, /* core3 sp32 bit27 */
			{22371,14,0}, /* core3 sp32 bit28 */
			{22370,14,0}, /* core3 sp32 bit29 */
			{10391,10,1}, /* core3 sp32 bit30 */
			{24340,14,0}, /* core3 sp32 bit31 */
			{20815,14,0}, /* core3 sp32 bit32 */
			{20814,14,0}, /* core3 sp32 bit33 */
			{19941,14,0}, /* core3 sp32 bit34 */
			{19940,14,0}, /* core3 sp32 bit35 */
			{19943,14,0}, /* core3 sp32 bit36 */
			{19942,14,0}, /* core3 sp32 bit37 */
			{20853,14,0}, /* core3 sp32 bit38 */
			{20852,14,0}, /* core3 sp32 bit39 */
			{19945,14,0}, /* core3 sp32 bit40 */
			{19944,14,0}, /* core3 sp32 bit41 */
			{10529,10,1}, /* core3 sp32 bit42 */
			{20023,14,0}, /* core3 sp32 bit43 */
			{20022,14,0}, /* core3 sp32 bit44 */
			{20021,14,0}, /* core3 sp32 bit45 */
			{20020,14,0}, /* core3 sp32 bit46 */
			{20575,14,0}, /* core3 sp32 bit47 */
			{20574,14,0}, /* core3 sp32 bit48 */
			{20419,14,0}, /* core3 sp32 bit49 */
			{20417,14,0}, /* core3 sp32 bit50 */
			{20416,14,0}, /* core3 sp32 bit51 */
			{20415,14,0}, /* core3 sp32 bit52 */
			{20414,14,0}, /* core3 sp32 bit53 */
			{20413,14,0}, /* core3 sp32 bit54 */
			{20412,14,0}, /* core3 sp32 bit55 */
			{20585,14,0}, /* core3 sp32 bit56 */
			{20584,14,0}, /* core3 sp32 bit57 */
			{20425,14,0}, /* core3 sp32 bit58 */
			{20424,14,0}, /* core3 sp32 bit59 */
			{11036,10,1}, /* core3 sp32 bit60 */
			{20418,14,0}, /* core3 sp32 bit61 */
			{11035,10,1}, /* core3 sp32 bit62 */
			{22394,10,0}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{14883,14,1}, /* core3 fp32 bit0 */
			{14882,14,1}, /* core3 fp32 bit1 */
			{23040,10,1}, /* core3 fp32 bit2 */
			{10868,10,0}, /* core3 fp32 bit3 */
			{20151,14,0}, /* core3 fp32 bit4 */
			{20150,14,0}, /* core3 fp32 bit5 */
			{10950,10,0}, /* core3 fp32 bit6 */
			{10949,10,0}, /* core3 fp32 bit7 */
			{10948,10,0}, /* core3 fp32 bit8 */
			{10947,10,0}, /* core3 fp32 bit9 */
			{11478,10,0}, /* core3 fp32 bit10 */
			{11477,10,0}, /* core3 fp32 bit11 */
			{20081,14,0}, /* core3 fp32 bit12 */
			{20080,14,0}, /* core3 fp32 bit13 */
			{20099,14,0}, /* core3 fp32 bit14 */
			{20098,14,0}, /* core3 fp32 bit15 */
			{10867,10,0}, /* core3 fp32 bit16 */
			{10886,10,0}, /* core3 fp32 bit17 */
			{10885,10,0}, /* core3 fp32 bit18 */
			{10882,10,0}, /* core3 fp32 bit19 */
			{23312,10,0}, /* core3 fp32 bit20 */
			{10881,10,0}, /* core3 fp32 bit21 */
			{23039,10,1}, /* core3 fp32 bit22 */
			{23006,10,1}, /* core3 fp32 bit23 */
			{22944,10,1}, /* core3 fp32 bit24 */
			{23005,10,1}, /* core3 fp32 bit25 */
			{22978,10,1}, /* core3 fp32 bit26 */
			{22943,10,1}, /* core3 fp32 bit27 */
			{22942,10,1}, /* core3 fp32 bit28 */
			{22977,10,1}, /* core3 fp32 bit29 */
			{23316,10,0}, /* core3 fp32 bit30 */
			{22941,10,1}, /* core3 fp32 bit31 */
			{19545,14,0}, /* core3 fp32 bit32 */
			{19544,14,0}, /* core3 fp32 bit33 */
			{19547,14,0}, /* core3 fp32 bit34 */
			{19546,14,0}, /* core3 fp32 bit35 */
			{19289,14,0}, /* core3 fp32 bit36 */
			{19288,14,0}, /* core3 fp32 bit37 */
			{20357,14,0}, /* core3 fp32 bit38 */
			{20356,14,0}, /* core3 fp32 bit39 */
			{19575,14,0}, /* core3 fp32 bit40 */
			{10593,10,1}, /* core3 fp32 bit41 */
			{19574,14,0}, /* core3 fp32 bit42 */
			{20825,14,0}, /* core3 fp32 bit43 */
			{20824,14,0}, /* core3 fp32 bit44 */
			{20009,14,0}, /* core3 fp32 bit45 */
			{20008,14,0}, /* core3 fp32 bit46 */
			{20373,14,0}, /* core3 fp32 bit47 */
			{20372,14,0}, /* core3 fp32 bit48 */
			{20353,14,0}, /* core3 fp32 bit49 */
			{20345,14,0}, /* core3 fp32 bit50 */
			{20344,14,0}, /* core3 fp32 bit51 */
			{20343,14,0}, /* core3 fp32 bit52 */
			{20342,14,0}, /* core3 fp32 bit53 */
			{20393,14,0}, /* core3 fp32 bit54 */
			{20392,14,0}, /* core3 fp32 bit55 */
			{20391,14,0}, /* core3 fp32 bit56 */
			{20390,14,0}, /* core3 fp32 bit57 */
			{20395,14,0}, /* core3 fp32 bit58 */
			{20394,14,0}, /* core3 fp32 bit59 */
			{11019,10,1}, /* core3 fp32 bit60 */
			{20352,14,0}, /* core3 fp32 bit61 */
			{11027,10,1}, /* core3 fp32 bit62 */
			{10587,10,1}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{21567,14,0}, /* core3 fp64 bit0 */
			{21566,14,0}, /* core3 fp64 bit1 */
			{21565,14,0}, /* core3 fp64 bit2 */
			{21564,14,0}, /* core3 fp64 bit3 */
			{22473,14,0}, /* core3 fp64 bit4 */
			{22472,14,0}, /* core3 fp64 bit5 */
			{22467,14,0}, /* core3 fp64 bit6 */
			{22466,14,0}, /* core3 fp64 bit7 */
			{22645,14,0}, /* core3 fp64 bit8 */
			{22644,14,0}, /* core3 fp64 bit9 */
			{22469,14,0}, /* core3 fp64 bit10 */
			{22468,14,0}, /* core3 fp64 bit11 */
			{22471,14,0}, /* core3 fp64 bit12 */
			{22470,14,0}, /* core3 fp64 bit13 */
			{22603,14,0}, /* core3 fp64 bit14 */
			{22602,14,0}, /* core3 fp64 bit15 */
			{22599,14,0}, /* core3 fp64 bit16 */
			{22598,14,0}, /* core3 fp64 bit17 */
			{22429,14,0}, /* core3 fp64 bit18 */
			{22428,14,0}, /* core3 fp64 bit19 */
			{22597,14,0}, /* core3 fp64 bit20 */
			{22596,14,0}, /* core3 fp64 bit21 */
			{23405,14,0}, /* core3 fp64 bit22 */
			{23407,14,0}, /* core3 fp64 bit23 */
			{23406,14,0}, /* core3 fp64 bit24 */
			{23391,14,0}, /* core3 fp64 bit25 */
			{23390,14,0}, /* core3 fp64 bit26 */
			{23387,14,0}, /* core3 fp64 bit27 */
			{10454,10,1}, /* core3 fp64 bit28 */
			{23386,14,0}, /* core3 fp64 bit29 */
			{10455,10,1}, /* core3 fp64 bit30 */
			{23404,14,0}, /* core3 fp64 bit31 */
			{19355,14,0}, /* core3 fp64 bit32 */
			{19354,14,0}, /* core3 fp64 bit33 */
			{19349,14,0}, /* core3 fp64 bit34 */
			{19348,14,0}, /* core3 fp64 bit35 */
			{19375,14,0}, /* core3 fp64 bit36 */
			{19374,14,0}, /* core3 fp64 bit37 */
			{20951,14,0}, /* core3 fp64 bit38 */
			{20950,14,0}, /* core3 fp64 bit39 */
			{20909,14,0}, /* core3 fp64 bit40 */
			{20908,14,0}, /* core3 fp64 bit41 */
			{20911,14,0}, /* core3 fp64 bit42 */
			{20915,14,0}, /* core3 fp64 bit43 */
			{20910,14,0}, /* core3 fp64 bit44 */
			{20914,14,0}, /* core3 fp64 bit45 */
			{10605,10,1}, /* core3 fp64 bit46 */
			{19677,14,0}, /* core3 fp64 bit47 */
			{19676,14,0}, /* core3 fp64 bit48 */
			{19671,14,0}, /* core3 fp64 bit49 */
			{19715,14,0}, /* core3 fp64 bit50 */
			{19714,14,0}, /* core3 fp64 bit51 */
			{19719,14,0}, /* core3 fp64 bit52 */
			{19718,14,0}, /* core3 fp64 bit53 */
			{19721,14,0}, /* core3 fp64 bit54 */
			{19720,14,0}, /* core3 fp64 bit55 */
			{19670,14,0}, /* core3 fp64 bit56 */
			{19717,14,0}, /* core3 fp64 bit57 */
			{19716,14,0}, /* core3 fp64 bit58 */
			{19713,14,0}, /* core3 fp64 bit59 */
			{19712,14,0}, /* core3 fp64 bit60 */
			{19675,14,0}, /* core3 fp64 bit61 */
			{19674,14,0}, /* core3 fp64 bit62 */
			{10544,10,1}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{24337,14,0}, /* core3 sp_EL0 bit0 */
			{24336,14,0}, /* core3 sp_EL0 bit1 */
			{24335,14,0}, /* core3 sp_EL0 bit2 */
			{24334,14,0}, /* core3 sp_EL0 bit3 */
			{21282,10,1}, /* core3 sp_EL0 bit4 */
			{21281,10,1}, /* core3 sp_EL0 bit5 */
			{21284,10,1}, /* core3 sp_EL0 bit6 */
			{21283,10,1}, /* core3 sp_EL0 bit7 */
			{21311,14,0}, /* core3 sp_EL0 bit8 */
			{21310,14,0}, /* core3 sp_EL0 bit9 */
			{20969,10,1}, /* core3 sp_EL0 bit10 */
			{20968,10,1}, /* core3 sp_EL0 bit11 */
			{20971,10,1}, /* core3 sp_EL0 bit12 */
			{20970,10,1}, /* core3 sp_EL0 bit13 */
			{22455,14,0}, /* core3 sp_EL0 bit14 */
			{22454,14,0}, /* core3 sp_EL0 bit15 */
			{10419,10,1}, /* core3 sp_EL0 bit16 */
			{22591,14,0}, /* core3 sp_EL0 bit17 */
			{22590,14,0}, /* core3 sp_EL0 bit18 */
			{22435,14,0}, /* core3 sp_EL0 bit19 */
			{22434,14,0}, /* core3 sp_EL0 bit20 */
			{22587,14,0}, /* core3 sp_EL0 bit21 */
			{22586,14,0}, /* core3 sp_EL0 bit22 */
			{22579,14,0}, /* core3 sp_EL0 bit23 */
			{22578,14,0}, /* core3 sp_EL0 bit24 */
			{24313,14,0}, /* core3 sp_EL0 bit25 */
			{24312,14,0}, /* core3 sp_EL0 bit26 */
			{23367,14,0}, /* core3 sp_EL0 bit27 */
			{23365,14,0}, /* core3 sp_EL0 bit28 */
			{23364,14,0}, /* core3 sp_EL0 bit29 */
			{23366,14,0}, /* core3 sp_EL0 bit30 */
			{10449,10,1}, /* core3 sp_EL0 bit31 */
			{19341,14,0}, /* core3 sp_EL0 bit32 */
			{19340,14,0}, /* core3 sp_EL0 bit33 */
			{19679,14,0}, /* core3 sp_EL0 bit34 */
			{19678,14,0}, /* core3 sp_EL0 bit35 */
			{19311,14,0}, /* core3 sp_EL0 bit36 */
			{19310,14,0}, /* core3 sp_EL0 bit37 */
			{19369,14,0}, /* core3 sp_EL0 bit38 */
			{19368,14,0}, /* core3 sp_EL0 bit39 */
			{19367,14,0}, /* core3 sp_EL0 bit40 */
			{19366,14,0}, /* core3 sp_EL0 bit41 */
			{20945,14,0}, /* core3 sp_EL0 bit42 */
			{20944,14,0}, /* core3 sp_EL0 bit43 */
			{19377,14,0}, /* core3 sp_EL0 bit44 */
			{10541,10,1}, /* core3 sp_EL0 bit45 */
			{19376,14,0}, /* core3 sp_EL0 bit46 */
			{19683,14,0}, /* core3 sp_EL0 bit47 */
			{19682,14,0}, /* core3 sp_EL0 bit48 */
			{19663,14,0}, /* core3 sp_EL0 bit49 */
			{20713,14,0}, /* core3 sp_EL0 bit50 */
			{20712,14,0}, /* core3 sp_EL0 bit51 */
			{20707,14,0}, /* core3 sp_EL0 bit52 */
			{20706,14,0}, /* core3 sp_EL0 bit53 */
			{20709,14,0}, /* core3 sp_EL0 bit54 */
			{20708,14,0}, /* core3 sp_EL0 bit55 */
			{19662,14,0}, /* core3 sp_EL0 bit56 */
			{20711,14,0}, /* core3 sp_EL0 bit57 */
			{20710,14,0}, /* core3 sp_EL0 bit58 */
			{11046,10,1}, /* core3 sp_EL0 bit59 */
			{23293,14,0}, /* core3 sp_EL0 bit60 */
			{23292,14,0}, /* core3 sp_EL0 bit61 */
			{23291,14,0}, /* core3 sp_EL0 bit62 */
			{23290,14,0}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{24351,14,0}, /* core3 sp_EL1 bit0 */
			{24350,14,0}, /* core3 sp_EL1 bit1 */
			{24349,14,0}, /* core3 sp_EL1 bit2 */
			{24348,14,0}, /* core3 sp_EL1 bit3 */
			{22461,14,0}, /* core3 sp_EL1 bit4 */
			{22460,14,0}, /* core3 sp_EL1 bit5 */
			{22647,14,0}, /* core3 sp_EL1 bit6 */
			{22646,14,0}, /* core3 sp_EL1 bit7 */
			{22601,14,0}, /* core3 sp_EL1 bit8 */
			{22600,14,0}, /* core3 sp_EL1 bit9 */
			{22649,14,0}, /* core3 sp_EL1 bit10 */
			{22648,14,0}, /* core3 sp_EL1 bit11 */
			{22463,14,0}, /* core3 sp_EL1 bit12 */
			{22462,14,0}, /* core3 sp_EL1 bit13 */
			{22457,14,0}, /* core3 sp_EL1 bit14 */
			{22456,14,0}, /* core3 sp_EL1 bit15 */
			{22595,14,0}, /* core3 sp_EL1 bit16 */
			{22594,14,0}, /* core3 sp_EL1 bit17 */
			{22427,14,0}, /* core3 sp_EL1 bit18 */
			{23403,14,0}, /* core3 sp_EL1 bit19 */
			{22426,14,0}, /* core3 sp_EL1 bit20 */
			{22431,14,0}, /* core3 sp_EL1 bit21 */
			{22430,14,0}, /* core3 sp_EL1 bit22 */
			{23402,14,0}, /* core3 sp_EL1 bit23 */
			{23389,14,0}, /* core3 sp_EL1 bit24 */
			{23388,14,0}, /* core3 sp_EL1 bit25 */
			{23385,14,0}, /* core3 sp_EL1 bit26 */
			{23384,14,0}, /* core3 sp_EL1 bit27 */
			{10453,10,1}, /* core3 sp_EL1 bit28 */
			{23383,14,0}, /* core3 sp_EL1 bit29 */
			{23382,14,0}, /* core3 sp_EL1 bit30 */
			{10439,10,1}, /* core3 sp_EL1 bit31 */
			{19353,14,0}, /* core3 sp_EL1 bit32 */
			{19352,14,0}, /* core3 sp_EL1 bit33 */
			{19351,14,0}, /* core3 sp_EL1 bit34 */
			{19350,14,0}, /* core3 sp_EL1 bit35 */
			{19379,14,0}, /* core3 sp_EL1 bit36 */
			{19378,14,0}, /* core3 sp_EL1 bit37 */
			{19373,14,0}, /* core3 sp_EL1 bit38 */
			{19372,14,0}, /* core3 sp_EL1 bit39 */
			{20947,14,0}, /* core3 sp_EL1 bit40 */
			{20949,14,0}, /* core3 sp_EL1 bit41 */
			{20946,14,0}, /* core3 sp_EL1 bit42 */
			{20948,14,0}, /* core3 sp_EL1 bit43 */
			{20913,14,0}, /* core3 sp_EL1 bit44 */
			{20912,14,0}, /* core3 sp_EL1 bit45 */
			{10604,10,1}, /* core3 sp_EL1 bit46 */
			{19673,14,0}, /* core3 sp_EL1 bit47 */
			{19672,14,0}, /* core3 sp_EL1 bit48 */
			{19603,14,0}, /* core3 sp_EL1 bit49 */
			{19703,14,0}, /* core3 sp_EL1 bit50 */
			{19702,14,0}, /* core3 sp_EL1 bit51 */
			{19709,14,0}, /* core3 sp_EL1 bit52 */
			{19708,14,0}, /* core3 sp_EL1 bit53 */
			{19707,14,0}, /* core3 sp_EL1 bit54 */
			{19706,14,0}, /* core3 sp_EL1 bit55 */
			{19602,14,0}, /* core3 sp_EL1 bit56 */
			{19711,14,0}, /* core3 sp_EL1 bit57 */
			{19710,14,0}, /* core3 sp_EL1 bit58 */
			{19705,14,0}, /* core3 sp_EL1 bit59 */
			{19704,14,0}, /* core3 sp_EL1 bit60 */
			{19347,14,0}, /* core3 sp_EL1 bit61 */
			{19346,14,0}, /* core3 sp_EL1 bit62 */
			{10543,10,1}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 9416,10,0}, /* core3 sp_EL2 bit0 */
			{ 9415,10,0}, /* core3 sp_EL2 bit1 */
			{ 9414,10,0}, /* core3 sp_EL2 bit2 */
			{ 9413,10,0}, /* core3 sp_EL2 bit3 */
			{21307,14,0}, /* core3 sp_EL2 bit4 */
			{21306,14,0}, /* core3 sp_EL2 bit5 */
			{21317,14,0}, /* core3 sp_EL2 bit6 */
			{21316,14,0}, /* core3 sp_EL2 bit7 */
			{21315,14,0}, /* core3 sp_EL2 bit8 */
			{21314,14,0}, /* core3 sp_EL2 bit9 */
			{21313,14,0}, /* core3 sp_EL2 bit10 */
			{21312,14,0}, /* core3 sp_EL2 bit11 */
			{21309,14,0}, /* core3 sp_EL2 bit12 */
			{21308,14,0}, /* core3 sp_EL2 bit13 */
			{21321,14,0}, /* core3 sp_EL2 bit14 */
			{21320,14,0}, /* core3 sp_EL2 bit15 */
			{22433,14,0}, /* core3 sp_EL2 bit16 */
			{22432,14,0}, /* core3 sp_EL2 bit17 */
			{22707,14,0}, /* core3 sp_EL2 bit18 */
			{22706,14,0}, /* core3 sp_EL2 bit19 */
			{10416,10,1}, /* core3 sp_EL2 bit20 */
			{22585,14,0}, /* core3 sp_EL2 bit21 */
			{22584,14,0}, /* core3 sp_EL2 bit22 */
			{22581,14,0}, /* core3 sp_EL2 bit23 */
			{22580,14,0}, /* core3 sp_EL2 bit24 */
			{22409,14,0}, /* core3 sp_EL2 bit25 */
			{22408,14,0}, /* core3 sp_EL2 bit26 */
			{24323,14,0}, /* core3 sp_EL2 bit27 */
			{24322,14,0}, /* core3 sp_EL2 bit28 */
			{22571,14,0}, /* core3 sp_EL2 bit29 */
			{22570,14,0}, /* core3 sp_EL2 bit30 */
			{10450,10,1}, /* core3 sp_EL2 bit31 */
			{19299,14,0}, /* core3 sp_EL2 bit32 */
			{19298,14,0}, /* core3 sp_EL2 bit33 */
			{19297,14,0}, /* core3 sp_EL2 bit34 */
			{19296,14,0}, /* core3 sp_EL2 bit35 */
			{19329,14,0}, /* core3 sp_EL2 bit36 */
			{10560,10,1}, /* core3 sp_EL2 bit37 */
			{19328,14,0}, /* core3 sp_EL2 bit38 */
			{20929,14,0}, /* core3 sp_EL2 bit39 */
			{20928,14,0}, /* core3 sp_EL2 bit40 */
			{20931,14,0}, /* core3 sp_EL2 bit41 */
			{20930,14,0}, /* core3 sp_EL2 bit42 */
			{23311,14,0}, /* core3 sp_EL2 bit43 */
			{23310,14,0}, /* core3 sp_EL2 bit44 */
			{23309,14,0}, /* core3 sp_EL2 bit45 */
			{23308,14,0}, /* core3 sp_EL2 bit46 */
			{19651,14,0}, /* core3 sp_EL2 bit47 */
			{20669,14,0}, /* core3 sp_EL2 bit48 */
			{19650,14,0}, /* core3 sp_EL2 bit49 */
			{20668,14,0}, /* core3 sp_EL2 bit50 */
			{20617,14,0}, /* core3 sp_EL2 bit51 */
			{20616,14,0}, /* core3 sp_EL2 bit52 */
			{20601,14,0}, /* core3 sp_EL2 bit53 */
			{20600,14,0}, /* core3 sp_EL2 bit54 */
			{20603,14,0}, /* core3 sp_EL2 bit55 */
			{20629,14,0}, /* core3 sp_EL2 bit56 */
			{20602,14,0}, /* core3 sp_EL2 bit57 */
			{20613,14,0}, /* core3 sp_EL2 bit58 */
			{20612,14,0}, /* core3 sp_EL2 bit59 */
			{11044,10,1}, /* core3 sp_EL2 bit60 */
			{20628,14,0}, /* core3 sp_EL2 bit61 */
			{11045,10,1}, /* core3 sp_EL2 bit62 */
			{10559,10,1}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{23371,14,0}, /* core3 sp_EL3 bit0 */
			{22411,14,0}, /* core3 sp_EL3 bit1 */
			{23370,14,0}, /* core3 sp_EL3 bit2 */
			{10452,10,1}, /* core3 sp_EL3 bit3 */
			{22653,14,0}, /* core3 sp_EL3 bit4 */
			{22652,14,0}, /* core3 sp_EL3 bit5 */
			{22651,14,0}, /* core3 sp_EL3 bit6 */
			{22650,14,0}, /* core3 sp_EL3 bit7 */
			{22659,14,0}, /* core3 sp_EL3 bit8 */
			{22658,14,0}, /* core3 sp_EL3 bit9 */
			{22655,14,0}, /* core3 sp_EL3 bit10 */
			{22654,14,0}, /* core3 sp_EL3 bit11 */
			{22657,14,0}, /* core3 sp_EL3 bit12 */
			{22656,14,0}, /* core3 sp_EL3 bit13 */
			{10420,10,1}, /* core3 sp_EL3 bit14 */
			{22661,14,0}, /* core3 sp_EL3 bit15 */
			{22660,14,0}, /* core3 sp_EL3 bit16 */
			{22593,14,0}, /* core3 sp_EL3 bit17 */
			{22589,14,0}, /* core3 sp_EL3 bit18 */
			{22588,14,0}, /* core3 sp_EL3 bit19 */
			{22592,14,0}, /* core3 sp_EL3 bit20 */
			{23411,14,0}, /* core3 sp_EL3 bit21 */
			{23410,14,0}, /* core3 sp_EL3 bit22 */
			{22410,14,0}, /* core3 sp_EL3 bit23 */
			{23409,14,0}, /* core3 sp_EL3 bit24 */
			{23408,14,0}, /* core3 sp_EL3 bit25 */
			{23719,14,0}, /* core3 sp_EL3 bit26 */
			{23718,14,0}, /* core3 sp_EL3 bit27 */
			{23373,14,0}, /* core3 sp_EL3 bit28 */
			{23372,14,0}, /* core3 sp_EL3 bit29 */
			{23381,14,0}, /* core3 sp_EL3 bit30 */
			{23380,14,0}, /* core3 sp_EL3 bit31 */
			{19309,14,0}, /* core3 sp_EL3 bit32 */
			{19308,14,0}, /* core3 sp_EL3 bit33 */
			{19359,14,0}, /* core3 sp_EL3 bit34 */
			{19357,14,0}, /* core3 sp_EL3 bit35 */
			{19356,14,0}, /* core3 sp_EL3 bit36 */
			{19365,14,0}, /* core3 sp_EL3 bit37 */
			{19364,14,0}, /* core3 sp_EL3 bit38 */
			{19363,14,0}, /* core3 sp_EL3 bit39 */
			{19362,14,0}, /* core3 sp_EL3 bit40 */
			{20943,14,0}, /* core3 sp_EL3 bit41 */
			{20942,14,0}, /* core3 sp_EL3 bit42 */
			{20941,14,0}, /* core3 sp_EL3 bit43 */
			{20940,14,0}, /* core3 sp_EL3 bit44 */
			{10557,10,1}, /* core3 sp_EL3 bit45 */
			{19358,14,0}, /* core3 sp_EL3 bit46 */
			{19657,14,0}, /* core3 sp_EL3 bit47 */
			{19699,14,0}, /* core3 sp_EL3 bit48 */
			{19656,14,0}, /* core3 sp_EL3 bit49 */
			{20691,14,0}, /* core3 sp_EL3 bit50 */
			{19698,14,0}, /* core3 sp_EL3 bit51 */
			{20690,14,0}, /* core3 sp_EL3 bit52 */
			{20673,14,0}, /* core3 sp_EL3 bit53 */
			{20683,14,0}, /* core3 sp_EL3 bit54 */
			{20682,14,0}, /* core3 sp_EL3 bit55 */
			{20672,14,0}, /* core3 sp_EL3 bit56 */
			{20671,14,0}, /* core3 sp_EL3 bit57 */
			{20670,14,0}, /* core3 sp_EL3 bit58 */
			{20681,14,0}, /* core3 sp_EL3 bit59 */
			{20680,14,0}, /* core3 sp_EL3 bit60 */
			{19659,14,0}, /* core3 sp_EL3 bit61 */
			{19658,14,0}, /* core3 sp_EL3 bit62 */
			{10551,10,1}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{24321,14,0}, /* core3 elr_EL1 bit0 */
			{24320,14,0}, /* core3 elr_EL1 bit1 */
			{24319,14,0}, /* core3 elr_EL1 bit2 */
			{24318,14,0}, /* core3 elr_EL1 bit3 */
			{23789,14,0}, /* core3 elr_EL1 bit4 */
			{23788,14,0}, /* core3 elr_EL1 bit5 */
			{22451,14,0}, /* core3 elr_EL1 bit6 */
			{22450,14,0}, /* core3 elr_EL1 bit7 */
			{22453,14,0}, /* core3 elr_EL1 bit8 */
			{22452,14,0}, /* core3 elr_EL1 bit9 */
			{21305,14,0}, /* core3 elr_EL1 bit10 */
			{21304,14,0}, /* core3 elr_EL1 bit11 */
			{22449,14,0}, /* core3 elr_EL1 bit12 */
			{22448,14,0}, /* core3 elr_EL1 bit13 */
			{10418,10,1}, /* core3 elr_EL1 bit14 */
			{22667,14,0}, /* core3 elr_EL1 bit15 */
			{22666,14,0}, /* core3 elr_EL1 bit16 */
			{22669,14,0}, /* core3 elr_EL1 bit17 */
			{22703,14,0}, /* core3 elr_EL1 bit18 */
			{22702,14,0}, /* core3 elr_EL1 bit19 */
			{22668,14,0}, /* core3 elr_EL1 bit20 */
			{22405,14,0}, /* core3 elr_EL1 bit21 */
			{22407,14,0}, /* core3 elr_EL1 bit22 */
			{22406,14,0}, /* core3 elr_EL1 bit23 */
			{22404,14,0}, /* core3 elr_EL1 bit24 */
			{23379,14,0}, /* core3 elr_EL1 bit25 */
			{23378,14,0}, /* core3 elr_EL1 bit26 */
			{22415,14,0}, /* core3 elr_EL1 bit27 */
			{10451,10,1}, /* core3 elr_EL1 bit28 */
			{22414,14,0}, /* core3 elr_EL1 bit29 */
			{22413,14,0}, /* core3 elr_EL1 bit30 */
			{22412,14,0}, /* core3 elr_EL1 bit31 */
			{19307,14,0}, /* core3 elr_EL1 bit32 */
			{19306,14,0}, /* core3 elr_EL1 bit33 */
			{19641,14,0}, /* core3 elr_EL1 bit34 */
			{19640,14,0}, /* core3 elr_EL1 bit35 */
			{10555,10,1}, /* core3 elr_EL1 bit36 */
			{19321,14,0}, /* core3 elr_EL1 bit37 */
			{19320,14,0}, /* core3 elr_EL1 bit38 */
			{19317,14,0}, /* core3 elr_EL1 bit39 */
			{19316,14,0}, /* core3 elr_EL1 bit40 */
			{20923,14,0}, /* core3 elr_EL1 bit41 */
			{20922,14,0}, /* core3 elr_EL1 bit42 */
			{20917,14,0}, /* core3 elr_EL1 bit43 */
			{20916,14,0}, /* core3 elr_EL1 bit44 */
			{20939,14,0}, /* core3 elr_EL1 bit45 */
			{20938,14,0}, /* core3 elr_EL1 bit46 */
			{19667,14,0}, /* core3 elr_EL1 bit47 */
			{19599,14,0}, /* core3 elr_EL1 bit48 */
			{19666,14,0}, /* core3 elr_EL1 bit49 */
			{19598,14,0}, /* core3 elr_EL1 bit50 */
			{19701,14,0}, /* core3 elr_EL1 bit51 */
			{19700,14,0}, /* core3 elr_EL1 bit52 */
			{19597,14,0}, /* core3 elr_EL1 bit53 */
			{19596,14,0}, /* core3 elr_EL1 bit54 */
			{20699,14,0}, /* core3 elr_EL1 bit55 */
			{19665,14,0}, /* core3 elr_EL1 bit56 */
			{20698,14,0}, /* core3 elr_EL1 bit57 */
			{20701,14,0}, /* core3 elr_EL1 bit58 */
			{20700,14,0}, /* core3 elr_EL1 bit59 */
			{10237,10,1}, /* core3 elr_EL1 bit60 */
			{19664,14,0}, /* core3 elr_EL1 bit61 */
			{10238,10,1}, /* core3 elr_EL1 bit62 */
			{10556,10,1}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{10445,10,1}, /* core3 elr_EL2 bit0 */
			{23333,14,0}, /* core3 elr_EL2 bit1 */
			{23332,14,0}, /* core3 elr_EL2 bit2 */
			{23337,14,0}, /* core3 elr_EL2 bit3 */
			{21299,14,0}, /* core3 elr_EL2 bit4 */
			{21298,14,0}, /* core3 elr_EL2 bit5 */
			{21303,14,0}, /* core3 elr_EL2 bit6 */
			{21302,14,0}, /* core3 elr_EL2 bit7 */
			{22447,14,0}, /* core3 elr_EL2 bit8 */
			{22446,14,0}, /* core3 elr_EL2 bit9 */
			{21301,14,0}, /* core3 elr_EL2 bit10 */
			{21300,14,0}, /* core3 elr_EL2 bit11 */
			{22445,14,0}, /* core3 elr_EL2 bit12 */
			{22444,14,0}, /* core3 elr_EL2 bit13 */
			{22441,14,0}, /* core3 elr_EL2 bit14 */
			{22440,14,0}, /* core3 elr_EL2 bit15 */
			{22679,14,0}, /* core3 elr_EL2 bit16 */
			{22678,14,0}, /* core3 elr_EL2 bit17 */
			{22685,14,0}, /* core3 elr_EL2 bit18 */
			{22684,14,0}, /* core3 elr_EL2 bit19 */
			{22677,14,0}, /* core3 elr_EL2 bit20 */
			{22676,14,0}, /* core3 elr_EL2 bit21 */
			{22689,14,0}, /* core3 elr_EL2 bit22 */
			{23335,14,0}, /* core3 elr_EL2 bit23 */
			{22688,14,0}, /* core3 elr_EL2 bit24 */
			{23336,14,0}, /* core3 elr_EL2 bit25 */
			{23345,14,0}, /* core3 elr_EL2 bit26 */
			{23344,14,0}, /* core3 elr_EL2 bit27 */
			{23334,14,0}, /* core3 elr_EL2 bit28 */
			{14893,14,1}, /* core3 elr_EL2 bit29 */
			{14892,14,1}, /* core3 elr_EL2 bit30 */
			{10442,10,1}, /* core3 elr_EL2 bit31 */
			{19301,14,0}, /* core3 elr_EL2 bit32 */
			{19300,14,0}, /* core3 elr_EL2 bit33 */
			{19647,14,0}, /* core3 elr_EL2 bit34 */
			{19646,14,0}, /* core3 elr_EL2 bit35 */
			{19337,14,0}, /* core3 elr_EL2 bit36 */
			{19336,14,0}, /* core3 elr_EL2 bit37 */
			{19639,14,0}, /* core3 elr_EL2 bit38 */
			{19638,14,0}, /* core3 elr_EL2 bit39 */
			{20925,14,0}, /* core3 elr_EL2 bit40 */
			{20924,14,0}, /* core3 elr_EL2 bit41 */
			{20921,14,0}, /* core3 elr_EL2 bit42 */
			{20920,14,0}, /* core3 elr_EL2 bit43 */
			{20919,14,0}, /* core3 elr_EL2 bit44 */
			{20918,14,0}, /* core3 elr_EL2 bit45 */
			{10536,10,1}, /* core3 elr_EL2 bit46 */
			{19655,14,0}, /* core3 elr_EL2 bit47 */
			{19654,14,0}, /* core3 elr_EL2 bit48 */
			{19697,14,0}, /* core3 elr_EL2 bit49 */
			{19593,14,0}, /* core3 elr_EL2 bit50 */
			{19592,14,0}, /* core3 elr_EL2 bit51 */
			{20627,14,0}, /* core3 elr_EL2 bit52 */
			{20626,14,0}, /* core3 elr_EL2 bit53 */
			{19595,14,0}, /* core3 elr_EL2 bit54 */
			{19594,14,0}, /* core3 elr_EL2 bit55 */
			{19696,14,0}, /* core3 elr_EL2 bit56 */
			{20625,14,0}, /* core3 elr_EL2 bit57 */
			{20624,14,0}, /* core3 elr_EL2 bit58 */
			{19591,14,0}, /* core3 elr_EL2 bit59 */
			{19590,14,0}, /* core3 elr_EL2 bit60 */
			{19695,14,0}, /* core3 elr_EL2 bit61 */
			{19694,14,0}, /* core3 elr_EL2 bit62 */
			{10554,10,1}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{24317,14,0}, /* core3 elr_EL3 bit0 */
			{24316,14,0}, /* core3 elr_EL3 bit1 */
			{24315,14,0}, /* core3 elr_EL3 bit2 */
			{24314,14,0}, /* core3 elr_EL3 bit3 */
			{21782,10,1}, /* core3 elr_EL3 bit4 */
			{20733,10,1}, /* core3 elr_EL3 bit5 */
			{21781,10,1}, /* core3 elr_EL3 bit6 */
			{21780,10,1}, /* core3 elr_EL3 bit7 */
			{21779,10,1}, /* core3 elr_EL3 bit8 */
			{21794,10,1}, /* core3 elr_EL3 bit9 */
			{21793,10,1}, /* core3 elr_EL3 bit10 */
			{21792,10,1}, /* core3 elr_EL3 bit11 */
			{21791,10,1}, /* core3 elr_EL3 bit12 */
			{21796,10,1}, /* core3 elr_EL3 bit13 */
			{21795,10,1}, /* core3 elr_EL3 bit14 */
			{22663,14,0}, /* core3 elr_EL3 bit15 */
			{22662,14,0}, /* core3 elr_EL3 bit16 */
			{ 9412,10,0}, /* core3 elr_EL3 bit17 */
			{22671,14,0}, /* core3 elr_EL3 bit18 */
			{ 9411,10,0}, /* core3 elr_EL3 bit19 */
			{22670,14,0}, /* core3 elr_EL3 bit20 */
			{23413,14,0}, /* core3 elr_EL3 bit21 */
			{23412,14,0}, /* core3 elr_EL3 bit22 */
			{24309,14,0}, /* core3 elr_EL3 bit23 */
			{24308,14,0}, /* core3 elr_EL3 bit24 */
			{ 9410,10,0}, /* core3 elr_EL3 bit25 */
			{ 9409,10,0}, /* core3 elr_EL3 bit26 */
			{24307,14,0}, /* core3 elr_EL3 bit27 */
			{24306,14,0}, /* core3 elr_EL3 bit28 */
			{ 9408,10,0}, /* core3 elr_EL3 bit29 */
			{ 9407,10,0}, /* core3 elr_EL3 bit30 */
			{10440,10,1}, /* core3 elr_EL3 bit31 */
			{19343,14,0}, /* core3 elr_EL3 bit32 */
			{19643,14,0}, /* core3 elr_EL3 bit33 */
			{19642,14,0}, /* core3 elr_EL3 bit34 */
			{19342,14,0}, /* core3 elr_EL3 bit35 */
			{19361,14,0}, /* core3 elr_EL3 bit36 */
			{19360,14,0}, /* core3 elr_EL3 bit37 */
			{19319,14,0}, /* core3 elr_EL3 bit38 */
			{19318,14,0}, /* core3 elr_EL3 bit39 */
			{23549,14,0}, /* core3 elr_EL3 bit40 */
			{23548,14,0}, /* core3 elr_EL3 bit41 */
			{10539,10,1}, /* core3 elr_EL3 bit42 */
			{23551,14,0}, /* core3 elr_EL3 bit43 */
			{23550,14,0}, /* core3 elr_EL3 bit44 */
			{20889,14,0}, /* core3 elr_EL3 bit45 */
			{20888,14,0}, /* core3 elr_EL3 bit46 */
			{19681,14,0}, /* core3 elr_EL3 bit47 */
			{19680,14,0}, /* core3 elr_EL3 bit48 */
			{19601,14,0}, /* core3 elr_EL3 bit49 */
			{19600,14,0}, /* core3 elr_EL3 bit50 */
			{20697,14,0}, /* core3 elr_EL3 bit51 */
			{20696,14,0}, /* core3 elr_EL3 bit52 */
			{20675,14,0}, /* core3 elr_EL3 bit53 */
			{20677,14,0}, /* core3 elr_EL3 bit54 */
			{20674,14,0}, /* core3 elr_EL3 bit55 */
			{19669,14,0}, /* core3 elr_EL3 bit56 */
			{20676,14,0}, /* core3 elr_EL3 bit57 */
			{20679,14,0}, /* core3 elr_EL3 bit58 */
			{20678,14,0}, /* core3 elr_EL3 bit59 */
			{10236,10,1}, /* core3 elr_EL3 bit60 */
			{19668,14,0}, /* core3 elr_EL3 bit61 */
			{10552,10,1}, /* core3 elr_EL3 bit62 */
			{10601,10,1}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{21954,10,0}, /* core3 raw_pc bit0 */
			{21953,10,0}, /* core3 raw_pc bit1 */
			{20526,10,1}, /* core3 raw_pc bit2 */
			{20525,10,1}, /* core3 raw_pc bit3 */
			{20528,10,1}, /* core3 raw_pc bit4 */
			{20527,10,1}, /* core3 raw_pc bit5 */
			{21934,10,0}, /* core3 raw_pc bit6 */
			{21314,10,1}, /* core3 raw_pc bit7 */
			{15866,14,1}, /* core3 raw_pc bit8 */
			{15865,14,1}, /* core3 raw_pc bit9 */
			{22010,10,0}, /* core3 raw_pc bit10 */
			{22009,10,0}, /* core3 raw_pc bit11 */
			{22014,10,0}, /* core3 raw_pc bit12 */
			{22013,10,0}, /* core3 raw_pc bit13 */
			{22012,10,0}, /* core3 raw_pc bit14 */
			{22011,10,0}, /* core3 raw_pc bit15 */
			{22004,10,0}, /* core3 raw_pc bit16 */
			{22008,10,0}, /* core3 raw_pc bit17 */
			{22003,10,0}, /* core3 raw_pc bit18 */
			{22006,10,0}, /* core3 raw_pc bit19 */
			{22007,10,0}, /* core3 raw_pc bit20 */
			{15868,14,1}, /* core3 raw_pc bit21 */
			{22005,10,0}, /* core3 raw_pc bit22 */
			{15867,14,1}, /* core3 raw_pc bit23 */
			{22016,10,0}, /* core3 raw_pc bit24 */
			{22015,10,0}, /* core3 raw_pc bit25 */
			{22002,10,0}, /* core3 raw_pc bit26 */
			{22001,10,0}, /* core3 raw_pc bit27 */
			{22000,10,0}, /* core3 raw_pc bit28 */
			{21999,10,0}, /* core3 raw_pc bit29 */
			{21313,10,1}, /* core3 raw_pc bit30 */
			{22517,14,0}, /* core3 raw_pc bit31 */
			{22516,14,0}, /* core3 raw_pc bit32 */
			{22733,14,0}, /* core3 raw_pc bit33 */
			{22732,14,0}, /* core3 raw_pc bit34 */
			{22743,14,0}, /* core3 raw_pc bit35 */
			{22742,14,0}, /* core3 raw_pc bit36 */
			{22745,14,0}, /* core3 raw_pc bit37 */
			{22744,14,0}, /* core3 raw_pc bit38 */
			{22735,14,0}, /* core3 raw_pc bit39 */
			{22731,14,0}, /* core3 raw_pc bit40 */
			{22730,14,0}, /* core3 raw_pc bit41 */
			{22519,14,0}, /* core3 raw_pc bit42 */
			{22518,14,0}, /* core3 raw_pc bit43 */
			{21001,10,1}, /* core3 raw_pc bit44 */
			{22734,14,0}, /* core3 raw_pc bit45 */
			{22741,14,0}, /* core3 raw_pc bit46 */
			{22740,14,0}, /* core3 raw_pc bit47 */
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
			{21128,10,1}, /* core3 pc_iss bit0 */
			{20532,10,1}, /* core3 pc_iss bit1 */
			{20531,10,1}, /* core3 pc_iss bit2 */
			{20534,10,1}, /* core3 pc_iss bit3 */
			{20533,10,1}, /* core3 pc_iss bit4 */
			{20530,10,1}, /* core3 pc_iss bit5 */
			{20529,10,1}, /* core3 pc_iss bit6 */
			{21129,10,1}, /* core3 pc_iss bit7 */
			{20654,10,1}, /* core3 pc_iss bit8 */
			{20653,10,1}, /* core3 pc_iss bit9 */
			{20648,10,1}, /* core3 pc_iss bit10 */
			{20647,10,1}, /* core3 pc_iss bit11 */
			{20624,10,1}, /* core3 pc_iss bit12 */
			{20644,10,1}, /* core3 pc_iss bit13 */
			{20623,10,1}, /* core3 pc_iss bit14 */
			{20643,10,1}, /* core3 pc_iss bit15 */
			{20616,10,1}, /* core3 pc_iss bit16 */
			{20615,10,1}, /* core3 pc_iss bit17 */
			{20626,10,1}, /* core3 pc_iss bit18 */
			{20646,10,1}, /* core3 pc_iss bit19 */
			{20645,10,1}, /* core3 pc_iss bit20 */
			{20620,10,1}, /* core3 pc_iss bit21 */
			{20619,10,1}, /* core3 pc_iss bit22 */
			{20622,10,1}, /* core3 pc_iss bit23 */
			{20621,10,1}, /* core3 pc_iss bit24 */
			{20618,10,1}, /* core3 pc_iss bit25 */
			{20617,10,1}, /* core3 pc_iss bit26 */
			{20614,10,1}, /* core3 pc_iss bit27 */
			{20625,10,1}, /* core3 pc_iss bit28 */
			{20613,10,1}, /* core3 pc_iss bit29 */
			{20612,10,1}, /* core3 pc_iss bit30 */
			{20611,10,1}, /* core3 pc_iss bit31 */
			{20590,10,1}, /* core3 pc_iss bit32 */
			{20589,10,1}, /* core3 pc_iss bit33 */
			{20610,10,1}, /* core3 pc_iss bit34 */
			{20608,10,1}, /* core3 pc_iss bit35 */
			{20607,10,1}, /* core3 pc_iss bit36 */
			{20592,10,1}, /* core3 pc_iss bit37 */
			{20591,10,1}, /* core3 pc_iss bit38 */
			{20594,10,1}, /* core3 pc_iss bit39 */
			{20593,10,1}, /* core3 pc_iss bit40 */
			{22044,10,0}, /* core3 pc_iss bit41 */
			{20609,10,1}, /* core3 pc_iss bit42 */
			{22043,10,0}, /* core3 pc_iss bit43 */
			{20606,10,1}, /* core3 pc_iss bit44 */
			{21116,10,1}, /* core3 pc_iss bit45 */
			{20605,10,1}, /* core3 pc_iss bit46 */
			{20598,10,1}, /* core3 pc_iss bit47 */
			{20597,10,1}, /* core3 pc_iss bit48 */
			{20596,10,1}, /* core3 pc_iss bit49 */
			{20600,10,1}, /* core3 pc_iss bit50 */
			{20599,10,1}, /* core3 pc_iss bit51 */
			{22040,10,0}, /* core3 pc_iss bit52 */
			{20595,10,1}, /* core3 pc_iss bit53 */
			{22039,10,0}, /* core3 pc_iss bit54 */
			{22034,10,0}, /* core3 pc_iss bit55 */
			{22033,10,0}, /* core3 pc_iss bit56 */
			{20602,10,1}, /* core3 pc_iss bit57 */
			{20601,10,1}, /* core3 pc_iss bit58 */
			{22032,10,0}, /* core3 pc_iss bit59 */
			{22031,10,0}, /* core3 pc_iss bit60 */
			{22030,10,0}, /* core3 pc_iss bit61 */
			{22029,10,0}, /* core3 pc_iss bit62 */
			{21188,10,1}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{ 9736,10,1}, /* core3 full_pc_wr bit0 */
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
			{21158,10,1}, /* core3 full_pc_ex1 bit0 */
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
	},
	{		/* core 4 */
			.pc = {{
			{23439,23,0}, /* core4 pc bit0 */
			{23440,23,0}, /* core4 pc bit1 */
			{23441,23,0}, /* core4 pc bit2 */
			{23442,23,0}, /* core4 pc bit3 */
			{23427,23,0}, /* core4 pc bit4 */
			{23428,23,0}, /* core4 pc bit5 */
			{23429,23,0}, /* core4 pc bit6 */
			{23430,23,0}, /* core4 pc bit7 */
			{18247,19,0}, /* core4 pc bit8 */
			{18248,19,0}, /* core4 pc bit9 */
			{18249,19,0}, /* core4 pc bit10 */
			{18250,19,0}, /* core4 pc bit11 */
			{23459,23,0}, /* core4 pc bit12 */
			{23460,23,0}, /* core4 pc bit13 */
			{23461,23,0}, /* core4 pc bit14 */
			{23462,23,0}, /* core4 pc bit15 */
			{18231,19,0}, /* core4 pc bit16 */
			{18232,19,0}, /* core4 pc bit17 */
			{18233,19,0}, /* core4 pc bit18 */
			{18234,19,0}, /* core4 pc bit19 */
			{18239,19,0}, /* core4 pc bit20 */
			{18240,19,0}, /* core4 pc bit21 */
			{18241,19,0}, /* core4 pc bit22 */
			{18242,19,0}, /* core4 pc bit23 */
			{18243,19,0}, /* core4 pc bit24 */
			{18244,19,0}, /* core4 pc bit25 */
			{18245,19,0}, /* core4 pc bit26 */
			{18246,19,0}, /* core4 pc bit27 */
			{23455,23,0}, /* core4 pc bit28 */
			{23456,23,0}, /* core4 pc bit29 */
			{23457,23,0}, /* core4 pc bit30 */
			{23458,23,0}, /* core4 pc bit31 */
			{18147,19,0}, /* core4 pc bit32 */
			{18148,19,0}, /* core4 pc bit33 */
			{18149,19,0}, /* core4 pc bit34 */
			{18150,19,0}, /* core4 pc bit35 */
			{18879,19,0}, /* core4 pc bit36 */
			{18880,19,0}, /* core4 pc bit37 */
			{18881,19,0}, /* core4 pc bit38 */
			{18882,19,0}, /* core4 pc bit39 */
			{18883,19,0}, /* core4 pc bit40 */
			{18884,19,0}, /* core4 pc bit41 */
			{18885,19,0}, /* core4 pc bit42 */
			{18886,19,0}, /* core4 pc bit43 */
			{18151,19,0}, /* core4 pc bit44 */
			{18152,19,0}, /* core4 pc bit45 */
			{18153,19,0}, /* core4 pc bit46 */
			{18154,19,0}, /* core4 pc bit47 */
			{23777,23,0}, /* core4 pc bit48 */
			{23778,23,0}, /* core4 pc bit49 */
			{23779,23,0}, /* core4 pc bit50 */
			{23780,23,0}, /* core4 pc bit51 */
			{18143,19,0}, /* core4 pc bit52 */
			{18144,19,0}, /* core4 pc bit53 */
			{18145,19,0}, /* core4 pc bit54 */
			{18146,19,0}, /* core4 pc bit55 */
			{17659,19,0}, /* core4 pc bit56 */
			{17660,19,0}, /* core4 pc bit57 */
			{17661,19,0}, /* core4 pc bit58 */
			{17662,19,0}, /* core4 pc bit59 */
			{18139,19,0}, /* core4 pc bit60 */
			{18140,19,0}, /* core4 pc bit61 */
			{18141,19,0}, /* core4 pc bit62 */
			{18142,19,0}, /* core4 pc bit63 */
			}},
			.sp32 = {{
			{21959,19,0}, /* core4 sp32 bit0 */
			{21960,19,0}, /* core4 sp32 bit1 */
			{21961,19,0}, /* core4 sp32 bit2 */
			{21962,19,0}, /* core4 sp32 bit3 */
			{21987,19,0}, /* core4 sp32 bit4 */
			{21988,19,0}, /* core4 sp32 bit5 */
			{21989,19,0}, /* core4 sp32 bit6 */
			{21990,19,0}, /* core4 sp32 bit7 */
			{24209,23,0}, /* core4 sp32 bit8 */
			{24210,23,0}, /* core4 sp32 bit9 */
			{24211,23,0}, /* core4 sp32 bit10 */
			{24212,23,0}, /* core4 sp32 bit11 */
			{21591,19,0}, /* core4 sp32 bit12 */
			{21592,19,0}, /* core4 sp32 bit13 */
			{21593,19,0}, /* core4 sp32 bit14 */
			{21594,19,0}, /* core4 sp32 bit15 */
			{24193,23,0}, /* core4 sp32 bit16 */
			{24194,23,0}, /* core4 sp32 bit17 */
			{24195,23,0}, /* core4 sp32 bit18 */
			{24196,23,0}, /* core4 sp32 bit19 */
			{24197,23,0}, /* core4 sp32 bit20 */
			{24198,23,0}, /* core4 sp32 bit21 */
			{24199,23,0}, /* core4 sp32 bit22 */
			{24200,23,0}, /* core4 sp32 bit23 */
			{24189,23,0}, /* core4 sp32 bit24 */
			{24190,23,0}, /* core4 sp32 bit25 */
			{24191,23,0}, /* core4 sp32 bit26 */
			{24192,23,0}, /* core4 sp32 bit27 */
			{24121,23,0}, /* core4 sp32 bit28 */
			{24122,23,0}, /* core4 sp32 bit29 */
			{24123,23,0}, /* core4 sp32 bit30 */
			{24124,23,0}, /* core4 sp32 bit31 */
			{21431,19,0}, /* core4 sp32 bit32 */
			{21432,19,0}, /* core4 sp32 bit33 */
			{21433,19,0}, /* core4 sp32 bit34 */
			{21434,19,0}, /* core4 sp32 bit35 */
			{21159,19,0}, /* core4 sp32 bit36 */
			{21160,19,0}, /* core4 sp32 bit37 */
			{21161,19,0}, /* core4 sp32 bit38 */
			{21162,19,0}, /* core4 sp32 bit39 */
			{21155,19,0}, /* core4 sp32 bit40 */
			{21156,19,0}, /* core4 sp32 bit41 */
			{21157,19,0}, /* core4 sp32 bit42 */
			{21158,19,0}, /* core4 sp32 bit43 */
			{21199,19,0}, /* core4 sp32 bit44 */
			{21200,19,0}, /* core4 sp32 bit45 */
			{21201,19,0}, /* core4 sp32 bit46 */
			{21202,19,0}, /* core4 sp32 bit47 */
			{21383,19,0}, /* core4 sp32 bit48 */
			{21384,19,0}, /* core4 sp32 bit49 */
			{21385,19,0}, /* core4 sp32 bit50 */
			{21386,19,0}, /* core4 sp32 bit51 */
			{21203,19,0}, /* core4 sp32 bit52 */
			{21204,19,0}, /* core4 sp32 bit53 */
			{21205,19,0}, /* core4 sp32 bit54 */
			{21206,19,0}, /* core4 sp32 bit55 */
			{21143,19,0}, /* core4 sp32 bit56 */
			{21144,19,0}, /* core4 sp32 bit57 */
			{21145,19,0}, /* core4 sp32 bit58 */
			{21146,19,0}, /* core4 sp32 bit59 */
			{21151,19,0}, /* core4 sp32 bit60 */
			{21152,19,0}, /* core4 sp32 bit61 */
			{21153,19,0}, /* core4 sp32 bit62 */
			{21154,19,0}, /* core4 sp32 bit63 */
			}},
			.fp32 = {{
			{19762,23,0}, /* core4 fp32 bit0 */
			{19763,23,0}, /* core4 fp32 bit1 */
			{19764,23,0}, /* core4 fp32 bit2 */
			{19765,23,0}, /* core4 fp32 bit3 */
			{19754,23,0}, /* core4 fp32 bit4 */
			{19755,23,0}, /* core4 fp32 bit5 */
			{19756,23,0}, /* core4 fp32 bit6 */
			{19757,23,0}, /* core4 fp32 bit7 */
			{24137,23,0}, /* core4 fp32 bit8 */
			{24138,23,0}, /* core4 fp32 bit9 */
			{24139,23,0}, /* core4 fp32 bit10 */
			{24140,23,0}, /* core4 fp32 bit11 */
			{24093,23,0}, /* core4 fp32 bit12 */
			{24094,23,0}, /* core4 fp32 bit13 */
			{24095,23,0}, /* core4 fp32 bit14 */
			{24096,23,0}, /* core4 fp32 bit15 */
			{24141,23,0}, /* core4 fp32 bit16 */
			{24142,23,0}, /* core4 fp32 bit17 */
			{24143,23,0}, /* core4 fp32 bit18 */
			{24144,23,0}, /* core4 fp32 bit19 */
			{24149,23,0}, /* core4 fp32 bit20 */
			{24150,23,0}, /* core4 fp32 bit21 */
			{24151,23,0}, /* core4 fp32 bit22 */
			{24152,23,0}, /* core4 fp32 bit23 */
			{24145,23,0}, /* core4 fp32 bit24 */
			{24146,23,0}, /* core4 fp32 bit25 */
			{24147,23,0}, /* core4 fp32 bit26 */
			{24148,23,0}, /* core4 fp32 bit27 */
			{19806,23,0}, /* core4 fp32 bit28 */
			{19807,23,0}, /* core4 fp32 bit29 */
			{19808,23,0}, /* core4 fp32 bit30 */
			{19809,23,0}, /* core4 fp32 bit31 */
			{21475,19,0}, /* core4 fp32 bit32 */
			{21476,19,0}, /* core4 fp32 bit33 */
			{21477,19,0}, /* core4 fp32 bit34 */
			{21478,19,0}, /* core4 fp32 bit35 */
			{21479,19,0}, /* core4 fp32 bit36 */
			{21480,19,0}, /* core4 fp32 bit37 */
			{21481,19,0}, /* core4 fp32 bit38 */
			{21482,19,0}, /* core4 fp32 bit39 */
			{22159,19,0}, /* core4 fp32 bit40 */
			{22160,19,0}, /* core4 fp32 bit41 */
			{22161,19,0}, /* core4 fp32 bit42 */
			{22162,19,0}, /* core4 fp32 bit43 */
			{22199,19,0}, /* core4 fp32 bit44 */
			{22200,19,0}, /* core4 fp32 bit45 */
			{22201,19,0}, /* core4 fp32 bit46 */
			{22202,19,0}, /* core4 fp32 bit47 */
			{22163,19,0}, /* core4 fp32 bit48 */
			{22164,19,0}, /* core4 fp32 bit49 */
			{22165,19,0}, /* core4 fp32 bit50 */
			{22166,19,0}, /* core4 fp32 bit51 */
			{22151,19,0}, /* core4 fp32 bit52 */
			{22152,19,0}, /* core4 fp32 bit53 */
			{22153,19,0}, /* core4 fp32 bit54 */
			{22154,19,0}, /* core4 fp32 bit55 */
			{22167,19,0}, /* core4 fp32 bit56 */
			{22168,19,0}, /* core4 fp32 bit57 */
			{22169,19,0}, /* core4 fp32 bit58 */
			{22170,19,0}, /* core4 fp32 bit59 */
			{22195,19,0}, /* core4 fp32 bit60 */
			{22196,19,0}, /* core4 fp32 bit61 */
			{22197,19,0}, /* core4 fp32 bit62 */
			{22198,19,0}, /* core4 fp32 bit63 */
			}},
			.fp64 = {{
			{16607,19,0}, /* core4 fp64 bit0 */
			{16608,19,0}, /* core4 fp64 bit1 */
			{16609,19,0}, /* core4 fp64 bit2 */
			{16610,19,0}, /* core4 fp64 bit3 */
			{16603,19,0}, /* core4 fp64 bit4 */
			{16604,19,0}, /* core4 fp64 bit5 */
			{16605,19,0}, /* core4 fp64 bit6 */
			{16606,19,0}, /* core4 fp64 bit7 */
			{16571,19,0}, /* core4 fp64 bit8 */
			{16572,19,0}, /* core4 fp64 bit9 */
			{16573,19,0}, /* core4 fp64 bit10 */
			{16574,19,0}, /* core4 fp64 bit11 */
			{23343,23,0}, /* core4 fp64 bit12 */
			{23344,23,0}, /* core4 fp64 bit13 */
			{23345,23,0}, /* core4 fp64 bit14 */
			{23346,23,0}, /* core4 fp64 bit15 */
			{20611,19,0}, /* core4 fp64 bit16 */
			{20612,19,0}, /* core4 fp64 bit17 */
			{20613,19,0}, /* core4 fp64 bit18 */
			{20614,19,0}, /* core4 fp64 bit19 */
			{20619,19,0}, /* core4 fp64 bit20 */
			{20620,19,0}, /* core4 fp64 bit21 */
			{20621,19,0}, /* core4 fp64 bit22 */
			{20622,19,0}, /* core4 fp64 bit23 */
			{20615,19,0}, /* core4 fp64 bit24 */
			{20616,19,0}, /* core4 fp64 bit25 */
			{20617,19,0}, /* core4 fp64 bit26 */
			{20618,19,0}, /* core4 fp64 bit27 */
			{23375,23,0}, /* core4 fp64 bit28 */
			{23376,23,0}, /* core4 fp64 bit29 */
			{23377,23,0}, /* core4 fp64 bit30 */
			{23378,23,0}, /* core4 fp64 bit31 */
			{19087,19,0}, /* core4 fp64 bit32 */
			{19088,19,0}, /* core4 fp64 bit33 */
			{19089,19,0}, /* core4 fp64 bit34 */
			{19090,19,0}, /* core4 fp64 bit35 */
			{19043,19,0}, /* core4 fp64 bit36 */
			{19044,19,0}, /* core4 fp64 bit37 */
			{19045,19,0}, /* core4 fp64 bit38 */
			{19046,19,0}, /* core4 fp64 bit39 */
			{19079,19,0}, /* core4 fp64 bit40 */
			{19080,19,0}, /* core4 fp64 bit41 */
			{19081,19,0}, /* core4 fp64 bit42 */
			{19082,19,0}, /* core4 fp64 bit43 */
			{19059,19,0}, /* core4 fp64 bit44 */
			{19060,19,0}, /* core4 fp64 bit45 */
			{19061,19,0}, /* core4 fp64 bit46 */
			{19062,19,0}, /* core4 fp64 bit47 */
			{19067,19,0}, /* core4 fp64 bit48 */
			{19068,19,0}, /* core4 fp64 bit49 */
			{19069,19,0}, /* core4 fp64 bit50 */
			{19070,19,0}, /* core4 fp64 bit51 */
			{19055,19,0}, /* core4 fp64 bit52 */
			{19056,19,0}, /* core4 fp64 bit53 */
			{19057,19,0}, /* core4 fp64 bit54 */
			{19058,19,0}, /* core4 fp64 bit55 */
			{19095,19,0}, /* core4 fp64 bit56 */
			{19096,19,0}, /* core4 fp64 bit57 */
			{19097,19,0}, /* core4 fp64 bit58 */
			{19098,19,0}, /* core4 fp64 bit59 */
			{18919,19,0}, /* core4 fp64 bit60 */
			{18920,19,0}, /* core4 fp64 bit61 */
			{18921,19,0}, /* core4 fp64 bit62 */
			{18922,19,0}, /* core4 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{19111,19,0}, /* core4 sp_EL0 bit0 */
			{19112,19,0}, /* core4 sp_EL0 bit1 */
			{19113,19,0}, /* core4 sp_EL0 bit2 */
			{19114,19,0}, /* core4 sp_EL0 bit3 */
			{19119,19,0}, /* core4 sp_EL0 bit4 */
			{19120,19,0}, /* core4 sp_EL0 bit5 */
			{19121,19,0}, /* core4 sp_EL0 bit6 */
			{19122,19,0}, /* core4 sp_EL0 bit7 */
			{23391,23,0}, /* core4 sp_EL0 bit8 */
			{23392,23,0}, /* core4 sp_EL0 bit9 */
			{23393,23,0}, /* core4 sp_EL0 bit10 */
			{23394,23,0}, /* core4 sp_EL0 bit11 */
			{23387,23,0}, /* core4 sp_EL0 bit12 */
			{23388,23,0}, /* core4 sp_EL0 bit13 */
			{23389,23,0}, /* core4 sp_EL0 bit14 */
			{23390,23,0}, /* core4 sp_EL0 bit15 */
			{22071,19,0}, /* core4 sp_EL0 bit16 */
			{22072,19,0}, /* core4 sp_EL0 bit17 */
			{22073,19,0}, /* core4 sp_EL0 bit18 */
			{22074,19,0}, /* core4 sp_EL0 bit19 */
			{16579,19,0}, /* core4 sp_EL0 bit20 */
			{16580,19,0}, /* core4 sp_EL0 bit21 */
			{16581,19,0}, /* core4 sp_EL0 bit22 */
			{16582,19,0}, /* core4 sp_EL0 bit23 */
			{22055,19,0}, /* core4 sp_EL0 bit24 */
			{22056,19,0}, /* core4 sp_EL0 bit25 */
			{22057,19,0}, /* core4 sp_EL0 bit26 */
			{22058,19,0}, /* core4 sp_EL0 bit27 */
			{16595,19,0}, /* core4 sp_EL0 bit28 */
			{16596,19,0}, /* core4 sp_EL0 bit29 */
			{16597,19,0}, /* core4 sp_EL0 bit30 */
			{16598,19,0}, /* core4 sp_EL0 bit31 */
			{21091,19,0}, /* core4 sp_EL0 bit32 */
			{21092,19,0}, /* core4 sp_EL0 bit33 */
			{21093,19,0}, /* core4 sp_EL0 bit34 */
			{21094,19,0}, /* core4 sp_EL0 bit35 */
			{18991,19,0}, /* core4 sp_EL0 bit36 */
			{18992,19,0}, /* core4 sp_EL0 bit37 */
			{18993,19,0}, /* core4 sp_EL0 bit38 */
			{18994,19,0}, /* core4 sp_EL0 bit39 */
			{18987,19,0}, /* core4 sp_EL0 bit40 */
			{18988,19,0}, /* core4 sp_EL0 bit41 */
			{18989,19,0}, /* core4 sp_EL0 bit42 */
			{18990,19,0}, /* core4 sp_EL0 bit43 */
			{18995,19,0}, /* core4 sp_EL0 bit44 */
			{18996,19,0}, /* core4 sp_EL0 bit45 */
			{18997,19,0}, /* core4 sp_EL0 bit46 */
			{18998,19,0}, /* core4 sp_EL0 bit47 */
			{18983,19,0}, /* core4 sp_EL0 bit48 */
			{18984,19,0}, /* core4 sp_EL0 bit49 */
			{18985,19,0}, /* core4 sp_EL0 bit50 */
			{18986,19,0}, /* core4 sp_EL0 bit51 */
			{21047,19,0}, /* core4 sp_EL0 bit52 */
			{21048,19,0}, /* core4 sp_EL0 bit53 */
			{21049,19,0}, /* core4 sp_EL0 bit54 */
			{21050,19,0}, /* core4 sp_EL0 bit55 */
			{21099,19,0}, /* core4 sp_EL0 bit56 */
			{21100,19,0}, /* core4 sp_EL0 bit57 */
			{21101,19,0}, /* core4 sp_EL0 bit58 */
			{21102,19,0}, /* core4 sp_EL0 bit59 */
			{18923,19,0}, /* core4 sp_EL0 bit60 */
			{18924,19,0}, /* core4 sp_EL0 bit61 */
			{18925,19,0}, /* core4 sp_EL0 bit62 */
			{18926,19,0}, /* core4 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{18915,19,0}, /* core4 sp_EL1 bit0 */
			{18916,19,0}, /* core4 sp_EL1 bit1 */
			{18917,19,0}, /* core4 sp_EL1 bit2 */
			{18918,19,0}, /* core4 sp_EL1 bit3 */
			{16623,19,0}, /* core4 sp_EL1 bit4 */
			{16624,19,0}, /* core4 sp_EL1 bit5 */
			{16625,19,0}, /* core4 sp_EL1 bit6 */
			{16626,19,0}, /* core4 sp_EL1 bit7 */
			{23395,23,0}, /* core4 sp_EL1 bit8 */
			{23396,23,0}, /* core4 sp_EL1 bit9 */
			{23397,23,0}, /* core4 sp_EL1 bit10 */
			{23398,23,0}, /* core4 sp_EL1 bit11 */
			{23347,23,0}, /* core4 sp_EL1 bit12 */
			{23348,23,0}, /* core4 sp_EL1 bit13 */
			{23349,23,0}, /* core4 sp_EL1 bit14 */
			{23350,23,0}, /* core4 sp_EL1 bit15 */
			{20623,19,0}, /* core4 sp_EL1 bit16 */
			{20624,19,0}, /* core4 sp_EL1 bit17 */
			{20625,19,0}, /* core4 sp_EL1 bit18 */
			{20626,19,0}, /* core4 sp_EL1 bit19 */
			{20631,19,0}, /* core4 sp_EL1 bit20 */
			{20632,19,0}, /* core4 sp_EL1 bit21 */
			{20633,19,0}, /* core4 sp_EL1 bit22 */
			{20634,19,0}, /* core4 sp_EL1 bit23 */
			{20627,19,0}, /* core4 sp_EL1 bit24 */
			{20628,19,0}, /* core4 sp_EL1 bit25 */
			{20629,19,0}, /* core4 sp_EL1 bit26 */
			{20630,19,0}, /* core4 sp_EL1 bit27 */
			{23379,23,0}, /* core4 sp_EL1 bit28 */
			{23380,23,0}, /* core4 sp_EL1 bit29 */
			{23381,23,0}, /* core4 sp_EL1 bit30 */
			{23382,23,0}, /* core4 sp_EL1 bit31 */
			{19091,19,0}, /* core4 sp_EL1 bit32 */
			{19092,19,0}, /* core4 sp_EL1 bit33 */
			{19093,19,0}, /* core4 sp_EL1 bit34 */
			{19094,19,0}, /* core4 sp_EL1 bit35 */
			{18975,19,0}, /* core4 sp_EL1 bit36 */
			{18976,19,0}, /* core4 sp_EL1 bit37 */
			{18977,19,0}, /* core4 sp_EL1 bit38 */
			{18978,19,0}, /* core4 sp_EL1 bit39 */
			{19083,19,0}, /* core4 sp_EL1 bit40 */
			{19084,19,0}, /* core4 sp_EL1 bit41 */
			{19085,19,0}, /* core4 sp_EL1 bit42 */
			{19086,19,0}, /* core4 sp_EL1 bit43 */
			{19063,19,0}, /* core4 sp_EL1 bit44 */
			{19064,19,0}, /* core4 sp_EL1 bit45 */
			{19065,19,0}, /* core4 sp_EL1 bit46 */
			{19066,19,0}, /* core4 sp_EL1 bit47 */
			{19071,19,0}, /* core4 sp_EL1 bit48 */
			{19072,19,0}, /* core4 sp_EL1 bit49 */
			{19073,19,0}, /* core4 sp_EL1 bit50 */
			{19074,19,0}, /* core4 sp_EL1 bit51 */
			{19075,19,0}, /* core4 sp_EL1 bit52 */
			{19076,19,0}, /* core4 sp_EL1 bit53 */
			{19077,19,0}, /* core4 sp_EL1 bit54 */
			{19078,19,0}, /* core4 sp_EL1 bit55 */
			{21107,19,0}, /* core4 sp_EL1 bit56 */
			{21108,19,0}, /* core4 sp_EL1 bit57 */
			{21109,19,0}, /* core4 sp_EL1 bit58 */
			{21110,19,0}, /* core4 sp_EL1 bit59 */
			{21111,19,0}, /* core4 sp_EL1 bit60 */
			{21112,19,0}, /* core4 sp_EL1 bit61 */
			{21113,19,0}, /* core4 sp_EL1 bit62 */
			{21114,19,0}, /* core4 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{18855,19,0}, /* core4 sp_EL2 bit0 */
			{18856,19,0}, /* core4 sp_EL2 bit1 */
			{18857,19,0}, /* core4 sp_EL2 bit2 */
			{18858,19,0}, /* core4 sp_EL2 bit3 */
			{18867,19,0}, /* core4 sp_EL2 bit4 */
			{18868,19,0}, /* core4 sp_EL2 bit5 */
			{18869,19,0}, /* core4 sp_EL2 bit6 */
			{18870,19,0}, /* core4 sp_EL2 bit7 */
			{22099,19,0}, /* core4 sp_EL2 bit8 */
			{22100,19,0}, /* core4 sp_EL2 bit9 */
			{22101,19,0}, /* core4 sp_EL2 bit10 */
			{22102,19,0}, /* core4 sp_EL2 bit11 */
			{22031,19,0}, /* core4 sp_EL2 bit12 */
			{22032,19,0}, /* core4 sp_EL2 bit13 */
			{22033,19,0}, /* core4 sp_EL2 bit14 */
			{22034,19,0}, /* core4 sp_EL2 bit15 */
			{22063,19,0}, /* core4 sp_EL2 bit16 */
			{22064,19,0}, /* core4 sp_EL2 bit17 */
			{22065,19,0}, /* core4 sp_EL2 bit18 */
			{22066,19,0}, /* core4 sp_EL2 bit19 */
			{23111,19,0}, /* core4 sp_EL2 bit20 */
			{23112,19,0}, /* core4 sp_EL2 bit21 */
			{23113,19,0}, /* core4 sp_EL2 bit22 */
			{23114,19,0}, /* core4 sp_EL2 bit23 */
			{22059,19,0}, /* core4 sp_EL2 bit24 */
			{22060,19,0}, /* core4 sp_EL2 bit25 */
			{22061,19,0}, /* core4 sp_EL2 bit26 */
			{22062,19,0}, /* core4 sp_EL2 bit27 */
			{18875,19,0}, /* core4 sp_EL2 bit28 */
			{18876,19,0}, /* core4 sp_EL2 bit29 */
			{18877,19,0}, /* core4 sp_EL2 bit30 */
			{18878,19,0}, /* core4 sp_EL2 bit31 */
			{18955,19,0}, /* core4 sp_EL2 bit32 */
			{18956,19,0}, /* core4 sp_EL2 bit33 */
			{18957,19,0}, /* core4 sp_EL2 bit34 */
			{18958,19,0}, /* core4 sp_EL2 bit35 */
			{21059,19,0}, /* core4 sp_EL2 bit36 */
			{21060,19,0}, /* core4 sp_EL2 bit37 */
			{21061,19,0}, /* core4 sp_EL2 bit38 */
			{21062,19,0}, /* core4 sp_EL2 bit39 */
			{21075,19,0}, /* core4 sp_EL2 bit40 */
			{21076,19,0}, /* core4 sp_EL2 bit41 */
			{21077,19,0}, /* core4 sp_EL2 bit42 */
			{21078,19,0}, /* core4 sp_EL2 bit43 */
			{21063,19,0}, /* core4 sp_EL2 bit44 */
			{21064,19,0}, /* core4 sp_EL2 bit45 */
			{21065,19,0}, /* core4 sp_EL2 bit46 */
			{21066,19,0}, /* core4 sp_EL2 bit47 */
			{21079,19,0}, /* core4 sp_EL2 bit48 */
			{21080,19,0}, /* core4 sp_EL2 bit49 */
			{21081,19,0}, /* core4 sp_EL2 bit50 */
			{21082,19,0}, /* core4 sp_EL2 bit51 */
			{21067,19,0}, /* core4 sp_EL2 bit52 */
			{21068,19,0}, /* core4 sp_EL2 bit53 */
			{21069,19,0}, /* core4 sp_EL2 bit54 */
			{21070,19,0}, /* core4 sp_EL2 bit55 */
			{18951,19,0}, /* core4 sp_EL2 bit56 */
			{18952,19,0}, /* core4 sp_EL2 bit57 */
			{18953,19,0}, /* core4 sp_EL2 bit58 */
			{18954,19,0}, /* core4 sp_EL2 bit59 */
			{18939,19,0}, /* core4 sp_EL2 bit60 */
			{18940,19,0}, /* core4 sp_EL2 bit61 */
			{18941,19,0}, /* core4 sp_EL2 bit62 */
			{18942,19,0}, /* core4 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{18847,19,0}, /* core4 sp_EL3 bit0 */
			{18848,19,0}, /* core4 sp_EL3 bit1 */
			{18849,19,0}, /* core4 sp_EL3 bit2 */
			{18850,19,0}, /* core4 sp_EL3 bit3 */
			{19127,19,0}, /* core4 sp_EL3 bit4 */
			{19128,19,0}, /* core4 sp_EL3 bit5 */
			{19129,19,0}, /* core4 sp_EL3 bit6 */
			{19130,19,0}, /* core4 sp_EL3 bit7 */
			{16587,19,0}, /* core4 sp_EL3 bit8 */
			{16588,19,0}, /* core4 sp_EL3 bit9 */
			{16589,19,0}, /* core4 sp_EL3 bit10 */
			{16590,19,0}, /* core4 sp_EL3 bit11 */
			{19139,19,0}, /* core4 sp_EL3 bit12 */
			{19140,19,0}, /* core4 sp_EL3 bit13 */
			{19141,19,0}, /* core4 sp_EL3 bit14 */
			{19142,19,0}, /* core4 sp_EL3 bit15 */
			{22095,19,0}, /* core4 sp_EL3 bit16 */
			{22096,19,0}, /* core4 sp_EL3 bit17 */
			{22097,19,0}, /* core4 sp_EL3 bit18 */
			{22098,19,0}, /* core4 sp_EL3 bit19 */
			{22039,19,0}, /* core4 sp_EL3 bit20 */
			{22040,19,0}, /* core4 sp_EL3 bit21 */
			{22041,19,0}, /* core4 sp_EL3 bit22 */
			{22042,19,0}, /* core4 sp_EL3 bit23 */
			{16583,19,0}, /* core4 sp_EL3 bit24 */
			{16584,19,0}, /* core4 sp_EL3 bit25 */
			{16585,19,0}, /* core4 sp_EL3 bit26 */
			{16586,19,0}, /* core4 sp_EL3 bit27 */
			{16591,19,0}, /* core4 sp_EL3 bit28 */
			{16592,19,0}, /* core4 sp_EL3 bit29 */
			{16593,19,0}, /* core4 sp_EL3 bit30 */
			{16594,19,0}, /* core4 sp_EL3 bit31 */
			{18959,19,0}, /* core4 sp_EL3 bit32 */
			{18960,19,0}, /* core4 sp_EL3 bit33 */
			{18961,19,0}, /* core4 sp_EL3 bit34 */
			{18962,19,0}, /* core4 sp_EL3 bit35 */
			{20971,19,0}, /* core4 sp_EL3 bit36 */
			{20972,19,0}, /* core4 sp_EL3 bit37 */
			{20973,19,0}, /* core4 sp_EL3 bit38 */
			{20974,19,0}, /* core4 sp_EL3 bit39 */
			{18963,19,0}, /* core4 sp_EL3 bit40 */
			{18964,19,0}, /* core4 sp_EL3 bit41 */
			{18965,19,0}, /* core4 sp_EL3 bit42 */
			{18966,19,0}, /* core4 sp_EL3 bit43 */
			{20975,19,0}, /* core4 sp_EL3 bit44 */
			{20976,19,0}, /* core4 sp_EL3 bit45 */
			{20977,19,0}, /* core4 sp_EL3 bit46 */
			{20978,19,0}, /* core4 sp_EL3 bit47 */
			{21071,19,0}, /* core4 sp_EL3 bit48 */
			{21072,19,0}, /* core4 sp_EL3 bit49 */
			{21073,19,0}, /* core4 sp_EL3 bit50 */
			{21074,19,0}, /* core4 sp_EL3 bit51 */
			{20979,19,0}, /* core4 sp_EL3 bit52 */
			{20980,19,0}, /* core4 sp_EL3 bit53 */
			{20981,19,0}, /* core4 sp_EL3 bit54 */
			{20982,19,0}, /* core4 sp_EL3 bit55 */
			{18947,19,0}, /* core4 sp_EL3 bit56 */
			{18948,19,0}, /* core4 sp_EL3 bit57 */
			{18949,19,0}, /* core4 sp_EL3 bit58 */
			{18950,19,0}, /* core4 sp_EL3 bit59 */
			{18935,19,0}, /* core4 sp_EL3 bit60 */
			{18936,19,0}, /* core4 sp_EL3 bit61 */
			{18937,19,0}, /* core4 sp_EL3 bit62 */
			{18938,19,0}, /* core4 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{18851,19,0}, /* core4 elr_EL1 bit0 */
			{18852,19,0}, /* core4 elr_EL1 bit1 */
			{18853,19,0}, /* core4 elr_EL1 bit2 */
			{18854,19,0}, /* core4 elr_EL1 bit3 */
			{18871,19,0}, /* core4 elr_EL1 bit4 */
			{18872,19,0}, /* core4 elr_EL1 bit5 */
			{18873,19,0}, /* core4 elr_EL1 bit6 */
			{18874,19,0}, /* core4 elr_EL1 bit7 */
			{22091,19,0}, /* core4 elr_EL1 bit8 */
			{22092,19,0}, /* core4 elr_EL1 bit9 */
			{22093,19,0}, /* core4 elr_EL1 bit10 */
			{22094,19,0}, /* core4 elr_EL1 bit11 */
			{19143,19,0}, /* core4 elr_EL1 bit12 */
			{19144,19,0}, /* core4 elr_EL1 bit13 */
			{19145,19,0}, /* core4 elr_EL1 bit14 */
			{19146,19,0}, /* core4 elr_EL1 bit15 */
			{22083,19,0}, /* core4 elr_EL1 bit16 */
			{22084,19,0}, /* core4 elr_EL1 bit17 */
			{22085,19,0}, /* core4 elr_EL1 bit18 */
			{22086,19,0}, /* core4 elr_EL1 bit19 */
			{22079,19,0}, /* core4 elr_EL1 bit20 */
			{22080,19,0}, /* core4 elr_EL1 bit21 */
			{22081,19,0}, /* core4 elr_EL1 bit22 */
			{22082,19,0}, /* core4 elr_EL1 bit23 */
			{22075,19,0}, /* core4 elr_EL1 bit24 */
			{22076,19,0}, /* core4 elr_EL1 bit25 */
			{22077,19,0}, /* core4 elr_EL1 bit26 */
			{22078,19,0}, /* core4 elr_EL1 bit27 */
			{18911,19,0}, /* core4 elr_EL1 bit28 */
			{18912,19,0}, /* core4 elr_EL1 bit29 */
			{18913,19,0}, /* core4 elr_EL1 bit30 */
			{18914,19,0}, /* core4 elr_EL1 bit31 */
			{21095,19,0}, /* core4 elr_EL1 bit32 */
			{21096,19,0}, /* core4 elr_EL1 bit33 */
			{21097,19,0}, /* core4 elr_EL1 bit34 */
			{21098,19,0}, /* core4 elr_EL1 bit35 */
			{21055,19,0}, /* core4 elr_EL1 bit36 */
			{21056,19,0}, /* core4 elr_EL1 bit37 */
			{21057,19,0}, /* core4 elr_EL1 bit38 */
			{21058,19,0}, /* core4 elr_EL1 bit39 */
			{21083,19,0}, /* core4 elr_EL1 bit40 */
			{21084,19,0}, /* core4 elr_EL1 bit41 */
			{21085,19,0}, /* core4 elr_EL1 bit42 */
			{21086,19,0}, /* core4 elr_EL1 bit43 */
			{18971,19,0}, /* core4 elr_EL1 bit44 */
			{18972,19,0}, /* core4 elr_EL1 bit45 */
			{18973,19,0}, /* core4 elr_EL1 bit46 */
			{18974,19,0}, /* core4 elr_EL1 bit47 */
			{18967,19,0}, /* core4 elr_EL1 bit48 */
			{18968,19,0}, /* core4 elr_EL1 bit49 */
			{18969,19,0}, /* core4 elr_EL1 bit50 */
			{18970,19,0}, /* core4 elr_EL1 bit51 */
			{21051,19,0}, /* core4 elr_EL1 bit52 */
			{21052,19,0}, /* core4 elr_EL1 bit53 */
			{21053,19,0}, /* core4 elr_EL1 bit54 */
			{21054,19,0}, /* core4 elr_EL1 bit55 */
			{21103,19,0}, /* core4 elr_EL1 bit56 */
			{21104,19,0}, /* core4 elr_EL1 bit57 */
			{21105,19,0}, /* core4 elr_EL1 bit58 */
			{21106,19,0}, /* core4 elr_EL1 bit59 */
			{18927,19,0}, /* core4 elr_EL1 bit60 */
			{18928,19,0}, /* core4 elr_EL1 bit61 */
			{18929,19,0}, /* core4 elr_EL1 bit62 */
			{18930,19,0}, /* core4 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{19103,19,0}, /* core4 elr_EL2 bit0 */
			{19104,19,0}, /* core4 elr_EL2 bit1 */
			{19105,19,0}, /* core4 elr_EL2 bit2 */
			{19106,19,0}, /* core4 elr_EL2 bit3 */
			{19115,19,0}, /* core4 elr_EL2 bit4 */
			{19116,19,0}, /* core4 elr_EL2 bit5 */
			{19117,19,0}, /* core4 elr_EL2 bit6 */
			{19118,19,0}, /* core4 elr_EL2 bit7 */
			{23339,23,0}, /* core4 elr_EL2 bit8 */
			{23340,23,0}, /* core4 elr_EL2 bit9 */
			{23341,23,0}, /* core4 elr_EL2 bit10 */
			{23342,23,0}, /* core4 elr_EL2 bit11 */
			{23383,23,0}, /* core4 elr_EL2 bit12 */
			{23384,23,0}, /* core4 elr_EL2 bit13 */
			{23385,23,0}, /* core4 elr_EL2 bit14 */
			{23386,23,0}, /* core4 elr_EL2 bit15 */
			{22087,19,0}, /* core4 elr_EL2 bit16 */
			{22088,19,0}, /* core4 elr_EL2 bit17 */
			{22089,19,0}, /* core4 elr_EL2 bit18 */
			{22090,19,0}, /* core4 elr_EL2 bit19 */
			{23331,23,0}, /* core4 elr_EL2 bit20 */
			{23332,23,0}, /* core4 elr_EL2 bit21 */
			{23333,23,0}, /* core4 elr_EL2 bit22 */
			{23334,23,0}, /* core4 elr_EL2 bit23 */
			{23335,23,0}, /* core4 elr_EL2 bit24 */
			{23336,23,0}, /* core4 elr_EL2 bit25 */
			{23337,23,0}, /* core4 elr_EL2 bit26 */
			{23338,23,0}, /* core4 elr_EL2 bit27 */
			{16599,19,0}, /* core4 elr_EL2 bit28 */
			{16600,19,0}, /* core4 elr_EL2 bit29 */
			{16601,19,0}, /* core4 elr_EL2 bit30 */
			{16602,19,0}, /* core4 elr_EL2 bit31 */
			{18779,19,0}, /* core4 elr_EL2 bit32 */
			{18780,19,0}, /* core4 elr_EL2 bit33 */
			{18781,19,0}, /* core4 elr_EL2 bit34 */
			{18782,19,0}, /* core4 elr_EL2 bit35 */
			{18739,19,0}, /* core4 elr_EL2 bit36 */
			{18740,19,0}, /* core4 elr_EL2 bit37 */
			{18741,19,0}, /* core4 elr_EL2 bit38 */
			{18742,19,0}, /* core4 elr_EL2 bit39 */
			{18759,19,0}, /* core4 elr_EL2 bit40 */
			{18760,19,0}, /* core4 elr_EL2 bit41 */
			{18761,19,0}, /* core4 elr_EL2 bit42 */
			{18762,19,0}, /* core4 elr_EL2 bit43 */
			{18735,19,0}, /* core4 elr_EL2 bit44 */
			{18736,19,0}, /* core4 elr_EL2 bit45 */
			{18737,19,0}, /* core4 elr_EL2 bit46 */
			{18738,19,0}, /* core4 elr_EL2 bit47 */
			{18747,19,0}, /* core4 elr_EL2 bit48 */
			{18748,19,0}, /* core4 elr_EL2 bit49 */
			{18749,19,0}, /* core4 elr_EL2 bit50 */
			{18750,19,0}, /* core4 elr_EL2 bit51 */
			{18743,19,0}, /* core4 elr_EL2 bit52 */
			{18744,19,0}, /* core4 elr_EL2 bit53 */
			{18745,19,0}, /* core4 elr_EL2 bit54 */
			{18746,19,0}, /* core4 elr_EL2 bit55 */
			{18783,19,0}, /* core4 elr_EL2 bit56 */
			{18784,19,0}, /* core4 elr_EL2 bit57 */
			{18785,19,0}, /* core4 elr_EL2 bit58 */
			{18786,19,0}, /* core4 elr_EL2 bit59 */
			{18807,19,0}, /* core4 elr_EL2 bit60 */
			{18808,19,0}, /* core4 elr_EL2 bit61 */
			{18809,19,0}, /* core4 elr_EL2 bit62 */
			{18810,19,0}, /* core4 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{21975,19,0}, /* core4 elr_EL3 bit0 */
			{21976,19,0}, /* core4 elr_EL3 bit1 */
			{21977,19,0}, /* core4 elr_EL3 bit2 */
			{21978,19,0}, /* core4 elr_EL3 bit3 */
			{21983,19,0}, /* core4 elr_EL3 bit4 */
			{21984,19,0}, /* core4 elr_EL3 bit5 */
			{21985,19,0}, /* core4 elr_EL3 bit6 */
			{21986,19,0}, /* core4 elr_EL3 bit7 */
			{21615,19,0}, /* core4 elr_EL3 bit8 */
			{21616,19,0}, /* core4 elr_EL3 bit9 */
			{21617,19,0}, /* core4 elr_EL3 bit10 */
			{21618,19,0}, /* core4 elr_EL3 bit11 */
			{21587,19,0}, /* core4 elr_EL3 bit12 */
			{21588,19,0}, /* core4 elr_EL3 bit13 */
			{21589,19,0}, /* core4 elr_EL3 bit14 */
			{21590,19,0}, /* core4 elr_EL3 bit15 */
			{21379,19,0}, /* core4 elr_EL3 bit16 */
			{21380,19,0}, /* core4 elr_EL3 bit17 */
			{21381,19,0}, /* core4 elr_EL3 bit18 */
			{21382,19,0}, /* core4 elr_EL3 bit19 */
			{21623,19,0}, /* core4 elr_EL3 bit20 */
			{21624,19,0}, /* core4 elr_EL3 bit21 */
			{21625,19,0}, /* core4 elr_EL3 bit22 */
			{21626,19,0}, /* core4 elr_EL3 bit23 */
			{21627,19,0}, /* core4 elr_EL3 bit24 */
			{21628,19,0}, /* core4 elr_EL3 bit25 */
			{21629,19,0}, /* core4 elr_EL3 bit26 */
			{21630,19,0}, /* core4 elr_EL3 bit27 */
			{22003,19,0}, /* core4 elr_EL3 bit28 */
			{22004,19,0}, /* core4 elr_EL3 bit29 */
			{22005,19,0}, /* core4 elr_EL3 bit30 */
			{22006,19,0}, /* core4 elr_EL3 bit31 */
			{21559,19,0}, /* core4 elr_EL3 bit32 */
			{21560,19,0}, /* core4 elr_EL3 bit33 */
			{21561,19,0}, /* core4 elr_EL3 bit34 */
			{21562,19,0}, /* core4 elr_EL3 bit35 */
			{21531,19,0}, /* core4 elr_EL3 bit36 */
			{21532,19,0}, /* core4 elr_EL3 bit37 */
			{21533,19,0}, /* core4 elr_EL3 bit38 */
			{21534,19,0}, /* core4 elr_EL3 bit39 */
			{21555,19,0}, /* core4 elr_EL3 bit40 */
			{21556,19,0}, /* core4 elr_EL3 bit41 */
			{21557,19,0}, /* core4 elr_EL3 bit42 */
			{21558,19,0}, /* core4 elr_EL3 bit43 */
			{21535,19,0}, /* core4 elr_EL3 bit44 */
			{21536,19,0}, /* core4 elr_EL3 bit45 */
			{21537,19,0}, /* core4 elr_EL3 bit46 */
			{21538,19,0}, /* core4 elr_EL3 bit47 */
			{21539,19,0}, /* core4 elr_EL3 bit48 */
			{21540,19,0}, /* core4 elr_EL3 bit49 */
			{21541,19,0}, /* core4 elr_EL3 bit50 */
			{21542,19,0}, /* core4 elr_EL3 bit51 */
			{21515,19,0}, /* core4 elr_EL3 bit52 */
			{21516,19,0}, /* core4 elr_EL3 bit53 */
			{21517,19,0}, /* core4 elr_EL3 bit54 */
			{21518,19,0}, /* core4 elr_EL3 bit55 */
			{21567,19,0}, /* core4 elr_EL3 bit56 */
			{21568,19,0}, /* core4 elr_EL3 bit57 */
			{21569,19,0}, /* core4 elr_EL3 bit58 */
			{21570,19,0}, /* core4 elr_EL3 bit59 */
			{21571,19,0}, /* core4 elr_EL3 bit60 */
			{21572,19,0}, /* core4 elr_EL3 bit61 */
			{21573,19,0}, /* core4 elr_EL3 bit62 */
			{21574,19,0}, /* core4 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{14284,19,0}, /* core4 raw_pc bit0 */
			{19559,19,0}, /* core4 raw_pc bit1 */
			{19560,19,0}, /* core4 raw_pc bit2 */
			{20547,19,0}, /* core4 raw_pc bit3 */
			{20548,19,0}, /* core4 raw_pc bit4 */
			{20549,19,0}, /* core4 raw_pc bit5 */
			{20550,19,0}, /* core4 raw_pc bit6 */
			{18323,19,0}, /* core4 raw_pc bit7 */
			{18324,19,0}, /* core4 raw_pc bit8 */
			{18325,19,0}, /* core4 raw_pc bit9 */
			{18326,19,0}, /* core4 raw_pc bit10 */
			{18335,19,0}, /* core4 raw_pc bit11 */
			{18336,19,0}, /* core4 raw_pc bit12 */
			{18337,19,0}, /* core4 raw_pc bit13 */
			{18338,19,0}, /* core4 raw_pc bit14 */
			{18339,19,0}, /* core4 raw_pc bit15 */
			{18340,19,0}, /* core4 raw_pc bit16 */
			{18341,19,0}, /* core4 raw_pc bit17 */
			{18342,19,0}, /* core4 raw_pc bit18 */
			{18355,19,0}, /* core4 raw_pc bit19 */
			{18356,19,0}, /* core4 raw_pc bit20 */
			{18357,19,0}, /* core4 raw_pc bit21 */
			{18358,19,0}, /* core4 raw_pc bit22 */
			{18343,19,0}, /* core4 raw_pc bit23 */
			{18344,19,0}, /* core4 raw_pc bit24 */
			{18345,19,0}, /* core4 raw_pc bit25 */
			{18346,19,0}, /* core4 raw_pc bit26 */
			{18347,19,0}, /* core4 raw_pc bit27 */
			{18348,19,0}, /* core4 raw_pc bit28 */
			{18349,19,0}, /* core4 raw_pc bit29 */
			{18350,19,0}, /* core4 raw_pc bit30 */
			{15884,19,0}, /* core4 raw_pc bit31 */
			{17631,19,0}, /* core4 raw_pc bit32 */
			{17632,19,0}, /* core4 raw_pc bit33 */
			{17633,19,0}, /* core4 raw_pc bit34 */
			{17634,19,0}, /* core4 raw_pc bit35 */
			{18155,19,0}, /* core4 raw_pc bit36 */
			{18156,19,0}, /* core4 raw_pc bit37 */
			{18157,19,0}, /* core4 raw_pc bit38 */
			{18158,19,0}, /* core4 raw_pc bit39 */
			{17915,19,0}, /* core4 raw_pc bit40 */
			{17916,19,0}, /* core4 raw_pc bit41 */
			{17917,19,0}, /* core4 raw_pc bit42 */
			{17918,19,0}, /* core4 raw_pc bit43 */
			{17639,19,0}, /* core4 raw_pc bit44 */
			{17640,19,0}, /* core4 raw_pc bit45 */
			{17641,19,0}, /* core4 raw_pc bit46 */
			{17642,19,0}, /* core4 raw_pc bit47 */
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
			{14217,19,0}, /* core4 pc_iss bit0 */
			{14277,19,0}, /* core4 pc_iss bit1 */
			{14278,19,0}, /* core4 pc_iss bit2 */
			{14291,19,0}, /* core4 pc_iss bit3 */
			{14280,19,0}, /* core4 pc_iss bit4 */
			{14216,19,0}, /* core4 pc_iss bit5 */
			{14215,19,0}, /* core4 pc_iss bit6 */
			{14214,19,0}, /* core4 pc_iss bit7 */
			{19229,23,0}, /* core4 pc_iss bit8 */
			{19228,23,0}, /* core4 pc_iss bit9 */
			{14294,19,0}, /* core4 pc_iss bit10 */
			{14295,19,0}, /* core4 pc_iss bit11 */
			{19221,23,0}, /* core4 pc_iss bit12 */
			{19220,23,0}, /* core4 pc_iss bit13 */
			{19227,23,0}, /* core4 pc_iss bit14 */
			{17902,19,0}, /* core4 pc_iss bit15 */
			{17901,19,0}, /* core4 pc_iss bit16 */
			{17890,19,0}, /* core4 pc_iss bit17 */
			{17889,19,0}, /* core4 pc_iss bit18 */
			{17900,19,0}, /* core4 pc_iss bit19 */
			{17899,19,0}, /* core4 pc_iss bit20 */
			{19225,23,0}, /* core4 pc_iss bit21 */
			{19226,23,0}, /* core4 pc_iss bit22 */
			{19257,23,0}, /* core4 pc_iss bit23 */
			{19224,23,0}, /* core4 pc_iss bit24 */
			{19223,23,0}, /* core4 pc_iss bit25 */
			{19222,23,0}, /* core4 pc_iss bit26 */
			{19259,23,0}, /* core4 pc_iss bit27 */
			{19258,23,0}, /* core4 pc_iss bit28 */
			{14297,19,0}, /* core4 pc_iss bit29 */
			{19256,23,0}, /* core4 pc_iss bit30 */
			{14296,19,0}, /* core4 pc_iss bit31 */
			{17627,19,0}, /* core4 pc_iss bit32 */
			{17628,19,0}, /* core4 pc_iss bit33 */
			{17629,19,0}, /* core4 pc_iss bit34 */
			{17630,19,0}, /* core4 pc_iss bit35 */
			{17615,19,0}, /* core4 pc_iss bit36 */
			{17616,19,0}, /* core4 pc_iss bit37 */
			{17617,19,0}, /* core4 pc_iss bit38 */
			{17618,19,0}, /* core4 pc_iss bit39 */
			{17623,19,0}, /* core4 pc_iss bit40 */
			{17624,19,0}, /* core4 pc_iss bit41 */
			{17625,19,0}, /* core4 pc_iss bit42 */
			{17626,19,0}, /* core4 pc_iss bit43 */
			{17619,19,0}, /* core4 pc_iss bit44 */
			{17620,19,0}, /* core4 pc_iss bit45 */
			{17621,19,0}, /* core4 pc_iss bit46 */
			{17622,19,0}, /* core4 pc_iss bit47 */
			{17183,19,0}, /* core4 pc_iss bit48 */
			{17184,19,0}, /* core4 pc_iss bit49 */
			{17185,19,0}, /* core4 pc_iss bit50 */
			{17186,19,0}, /* core4 pc_iss bit51 */
			{17187,19,0}, /* core4 pc_iss bit52 */
			{17188,19,0}, /* core4 pc_iss bit53 */
			{17189,19,0}, /* core4 pc_iss bit54 */
			{17190,19,0}, /* core4 pc_iss bit55 */
			{17179,19,0}, /* core4 pc_iss bit56 */
			{17180,19,0}, /* core4 pc_iss bit57 */
			{17181,19,0}, /* core4 pc_iss bit58 */
			{17182,19,0}, /* core4 pc_iss bit59 */
			{17191,19,0}, /* core4 pc_iss bit60 */
			{17192,19,0}, /* core4 pc_iss bit61 */
			{17193,19,0}, /* core4 pc_iss bit62 */
			{17194,19,0}, /* core4 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{19562,19,0}, /* core4 full_pc_wr bit0 */
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
			{24026,23,0}, /* core4 full_pc_ex1 bit0 */
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
			{23798,23,0}, /* core4 full_pc_ex2 bit0 */
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
			{23439,20,0}, /* core5 pc bit0 */
			{23440,20,0}, /* core5 pc bit1 */
			{23441,20,0}, /* core5 pc bit2 */
			{23442,20,0}, /* core5 pc bit3 */
			{23427,20,0}, /* core5 pc bit4 */
			{23428,20,0}, /* core5 pc bit5 */
			{23429,20,0}, /* core5 pc bit6 */
			{23430,20,0}, /* core5 pc bit7 */
			{18247,16,0}, /* core5 pc bit8 */
			{18248,16,0}, /* core5 pc bit9 */
			{18249,16,0}, /* core5 pc bit10 */
			{18250,16,0}, /* core5 pc bit11 */
			{23459,20,0}, /* core5 pc bit12 */
			{23460,20,0}, /* core5 pc bit13 */
			{23461,20,0}, /* core5 pc bit14 */
			{23462,20,0}, /* core5 pc bit15 */
			{18231,16,0}, /* core5 pc bit16 */
			{18232,16,0}, /* core5 pc bit17 */
			{18233,16,0}, /* core5 pc bit18 */
			{18234,16,0}, /* core5 pc bit19 */
			{18239,16,0}, /* core5 pc bit20 */
			{18240,16,0}, /* core5 pc bit21 */
			{18241,16,0}, /* core5 pc bit22 */
			{18242,16,0}, /* core5 pc bit23 */
			{18243,16,0}, /* core5 pc bit24 */
			{18244,16,0}, /* core5 pc bit25 */
			{18245,16,0}, /* core5 pc bit26 */
			{18246,16,0}, /* core5 pc bit27 */
			{23455,20,0}, /* core5 pc bit28 */
			{23456,20,0}, /* core5 pc bit29 */
			{23457,20,0}, /* core5 pc bit30 */
			{23458,20,0}, /* core5 pc bit31 */
			{18147,16,0}, /* core5 pc bit32 */
			{18148,16,0}, /* core5 pc bit33 */
			{18149,16,0}, /* core5 pc bit34 */
			{18150,16,0}, /* core5 pc bit35 */
			{18879,16,0}, /* core5 pc bit36 */
			{18880,16,0}, /* core5 pc bit37 */
			{18881,16,0}, /* core5 pc bit38 */
			{18882,16,0}, /* core5 pc bit39 */
			{18883,16,0}, /* core5 pc bit40 */
			{18884,16,0}, /* core5 pc bit41 */
			{18885,16,0}, /* core5 pc bit42 */
			{18886,16,0}, /* core5 pc bit43 */
			{18151,16,0}, /* core5 pc bit44 */
			{18152,16,0}, /* core5 pc bit45 */
			{18153,16,0}, /* core5 pc bit46 */
			{18154,16,0}, /* core5 pc bit47 */
			{23777,20,0}, /* core5 pc bit48 */
			{23778,20,0}, /* core5 pc bit49 */
			{23779,20,0}, /* core5 pc bit50 */
			{23780,20,0}, /* core5 pc bit51 */
			{18143,16,0}, /* core5 pc bit52 */
			{18144,16,0}, /* core5 pc bit53 */
			{18145,16,0}, /* core5 pc bit54 */
			{18146,16,0}, /* core5 pc bit55 */
			{17659,16,0}, /* core5 pc bit56 */
			{17660,16,0}, /* core5 pc bit57 */
			{17661,16,0}, /* core5 pc bit58 */
			{17662,16,0}, /* core5 pc bit59 */
			{18139,16,0}, /* core5 pc bit60 */
			{18140,16,0}, /* core5 pc bit61 */
			{18141,16,0}, /* core5 pc bit62 */
			{18142,16,0}, /* core5 pc bit63 */
			}},
			.sp32 = {{
			{21959,16,0}, /* core5 sp32 bit0 */
			{21960,16,0}, /* core5 sp32 bit1 */
			{21961,16,0}, /* core5 sp32 bit2 */
			{21962,16,0}, /* core5 sp32 bit3 */
			{21987,16,0}, /* core5 sp32 bit4 */
			{21988,16,0}, /* core5 sp32 bit5 */
			{21989,16,0}, /* core5 sp32 bit6 */
			{21990,16,0}, /* core5 sp32 bit7 */
			{24209,20,0}, /* core5 sp32 bit8 */
			{24210,20,0}, /* core5 sp32 bit9 */
			{24211,20,0}, /* core5 sp32 bit10 */
			{24212,20,0}, /* core5 sp32 bit11 */
			{21591,16,0}, /* core5 sp32 bit12 */
			{21592,16,0}, /* core5 sp32 bit13 */
			{21593,16,0}, /* core5 sp32 bit14 */
			{21594,16,0}, /* core5 sp32 bit15 */
			{24193,20,0}, /* core5 sp32 bit16 */
			{24194,20,0}, /* core5 sp32 bit17 */
			{24195,20,0}, /* core5 sp32 bit18 */
			{24196,20,0}, /* core5 sp32 bit19 */
			{24197,20,0}, /* core5 sp32 bit20 */
			{24198,20,0}, /* core5 sp32 bit21 */
			{24199,20,0}, /* core5 sp32 bit22 */
			{24200,20,0}, /* core5 sp32 bit23 */
			{24189,20,0}, /* core5 sp32 bit24 */
			{24190,20,0}, /* core5 sp32 bit25 */
			{24191,20,0}, /* core5 sp32 bit26 */
			{24192,20,0}, /* core5 sp32 bit27 */
			{24121,20,0}, /* core5 sp32 bit28 */
			{24122,20,0}, /* core5 sp32 bit29 */
			{24123,20,0}, /* core5 sp32 bit30 */
			{24124,20,0}, /* core5 sp32 bit31 */
			{21431,16,0}, /* core5 sp32 bit32 */
			{21432,16,0}, /* core5 sp32 bit33 */
			{21433,16,0}, /* core5 sp32 bit34 */
			{21434,16,0}, /* core5 sp32 bit35 */
			{21159,16,0}, /* core5 sp32 bit36 */
			{21160,16,0}, /* core5 sp32 bit37 */
			{21161,16,0}, /* core5 sp32 bit38 */
			{21162,16,0}, /* core5 sp32 bit39 */
			{21155,16,0}, /* core5 sp32 bit40 */
			{21156,16,0}, /* core5 sp32 bit41 */
			{21157,16,0}, /* core5 sp32 bit42 */
			{21158,16,0}, /* core5 sp32 bit43 */
			{21199,16,0}, /* core5 sp32 bit44 */
			{21200,16,0}, /* core5 sp32 bit45 */
			{21201,16,0}, /* core5 sp32 bit46 */
			{21202,16,0}, /* core5 sp32 bit47 */
			{21383,16,0}, /* core5 sp32 bit48 */
			{21384,16,0}, /* core5 sp32 bit49 */
			{21385,16,0}, /* core5 sp32 bit50 */
			{21386,16,0}, /* core5 sp32 bit51 */
			{21203,16,0}, /* core5 sp32 bit52 */
			{21204,16,0}, /* core5 sp32 bit53 */
			{21205,16,0}, /* core5 sp32 bit54 */
			{21206,16,0}, /* core5 sp32 bit55 */
			{21143,16,0}, /* core5 sp32 bit56 */
			{21144,16,0}, /* core5 sp32 bit57 */
			{21145,16,0}, /* core5 sp32 bit58 */
			{21146,16,0}, /* core5 sp32 bit59 */
			{21151,16,0}, /* core5 sp32 bit60 */
			{21152,16,0}, /* core5 sp32 bit61 */
			{21153,16,0}, /* core5 sp32 bit62 */
			{21154,16,0}, /* core5 sp32 bit63 */
			}},
			.fp32 = {{
			{19762,20,0}, /* core5 fp32 bit0 */
			{19763,20,0}, /* core5 fp32 bit1 */
			{19764,20,0}, /* core5 fp32 bit2 */
			{19765,20,0}, /* core5 fp32 bit3 */
			{19754,20,0}, /* core5 fp32 bit4 */
			{19755,20,0}, /* core5 fp32 bit5 */
			{19756,20,0}, /* core5 fp32 bit6 */
			{19757,20,0}, /* core5 fp32 bit7 */
			{24137,20,0}, /* core5 fp32 bit8 */
			{24138,20,0}, /* core5 fp32 bit9 */
			{24139,20,0}, /* core5 fp32 bit10 */
			{24140,20,0}, /* core5 fp32 bit11 */
			{24093,20,0}, /* core5 fp32 bit12 */
			{24094,20,0}, /* core5 fp32 bit13 */
			{24095,20,0}, /* core5 fp32 bit14 */
			{24096,20,0}, /* core5 fp32 bit15 */
			{24141,20,0}, /* core5 fp32 bit16 */
			{24142,20,0}, /* core5 fp32 bit17 */
			{24143,20,0}, /* core5 fp32 bit18 */
			{24144,20,0}, /* core5 fp32 bit19 */
			{24149,20,0}, /* core5 fp32 bit20 */
			{24150,20,0}, /* core5 fp32 bit21 */
			{24151,20,0}, /* core5 fp32 bit22 */
			{24152,20,0}, /* core5 fp32 bit23 */
			{24145,20,0}, /* core5 fp32 bit24 */
			{24146,20,0}, /* core5 fp32 bit25 */
			{24147,20,0}, /* core5 fp32 bit26 */
			{24148,20,0}, /* core5 fp32 bit27 */
			{19806,20,0}, /* core5 fp32 bit28 */
			{19807,20,0}, /* core5 fp32 bit29 */
			{19808,20,0}, /* core5 fp32 bit30 */
			{19809,20,0}, /* core5 fp32 bit31 */
			{21475,16,0}, /* core5 fp32 bit32 */
			{21476,16,0}, /* core5 fp32 bit33 */
			{21477,16,0}, /* core5 fp32 bit34 */
			{21478,16,0}, /* core5 fp32 bit35 */
			{21479,16,0}, /* core5 fp32 bit36 */
			{21480,16,0}, /* core5 fp32 bit37 */
			{21481,16,0}, /* core5 fp32 bit38 */
			{21482,16,0}, /* core5 fp32 bit39 */
			{22159,16,0}, /* core5 fp32 bit40 */
			{22160,16,0}, /* core5 fp32 bit41 */
			{22161,16,0}, /* core5 fp32 bit42 */
			{22162,16,0}, /* core5 fp32 bit43 */
			{22199,16,0}, /* core5 fp32 bit44 */
			{22200,16,0}, /* core5 fp32 bit45 */
			{22201,16,0}, /* core5 fp32 bit46 */
			{22202,16,0}, /* core5 fp32 bit47 */
			{22163,16,0}, /* core5 fp32 bit48 */
			{22164,16,0}, /* core5 fp32 bit49 */
			{22165,16,0}, /* core5 fp32 bit50 */
			{22166,16,0}, /* core5 fp32 bit51 */
			{22151,16,0}, /* core5 fp32 bit52 */
			{22152,16,0}, /* core5 fp32 bit53 */
			{22153,16,0}, /* core5 fp32 bit54 */
			{22154,16,0}, /* core5 fp32 bit55 */
			{22167,16,0}, /* core5 fp32 bit56 */
			{22168,16,0}, /* core5 fp32 bit57 */
			{22169,16,0}, /* core5 fp32 bit58 */
			{22170,16,0}, /* core5 fp32 bit59 */
			{22195,16,0}, /* core5 fp32 bit60 */
			{22196,16,0}, /* core5 fp32 bit61 */
			{22197,16,0}, /* core5 fp32 bit62 */
			{22198,16,0}, /* core5 fp32 bit63 */
			}},
			.fp64 = {{
			{16607,16,0}, /* core5 fp64 bit0 */
			{16608,16,0}, /* core5 fp64 bit1 */
			{16609,16,0}, /* core5 fp64 bit2 */
			{16610,16,0}, /* core5 fp64 bit3 */
			{16603,16,0}, /* core5 fp64 bit4 */
			{16604,16,0}, /* core5 fp64 bit5 */
			{16605,16,0}, /* core5 fp64 bit6 */
			{16606,16,0}, /* core5 fp64 bit7 */
			{16571,16,0}, /* core5 fp64 bit8 */
			{16572,16,0}, /* core5 fp64 bit9 */
			{16573,16,0}, /* core5 fp64 bit10 */
			{16574,16,0}, /* core5 fp64 bit11 */
			{23343,20,0}, /* core5 fp64 bit12 */
			{23344,20,0}, /* core5 fp64 bit13 */
			{23345,20,0}, /* core5 fp64 bit14 */
			{23346,20,0}, /* core5 fp64 bit15 */
			{20611,16,0}, /* core5 fp64 bit16 */
			{20612,16,0}, /* core5 fp64 bit17 */
			{20613,16,0}, /* core5 fp64 bit18 */
			{20614,16,0}, /* core5 fp64 bit19 */
			{20619,16,0}, /* core5 fp64 bit20 */
			{20620,16,0}, /* core5 fp64 bit21 */
			{20621,16,0}, /* core5 fp64 bit22 */
			{20622,16,0}, /* core5 fp64 bit23 */
			{20615,16,0}, /* core5 fp64 bit24 */
			{20616,16,0}, /* core5 fp64 bit25 */
			{20617,16,0}, /* core5 fp64 bit26 */
			{20618,16,0}, /* core5 fp64 bit27 */
			{23375,20,0}, /* core5 fp64 bit28 */
			{23376,20,0}, /* core5 fp64 bit29 */
			{23377,20,0}, /* core5 fp64 bit30 */
			{23378,20,0}, /* core5 fp64 bit31 */
			{19087,16,0}, /* core5 fp64 bit32 */
			{19088,16,0}, /* core5 fp64 bit33 */
			{19089,16,0}, /* core5 fp64 bit34 */
			{19090,16,0}, /* core5 fp64 bit35 */
			{19043,16,0}, /* core5 fp64 bit36 */
			{19044,16,0}, /* core5 fp64 bit37 */
			{19045,16,0}, /* core5 fp64 bit38 */
			{19046,16,0}, /* core5 fp64 bit39 */
			{19079,16,0}, /* core5 fp64 bit40 */
			{19080,16,0}, /* core5 fp64 bit41 */
			{19081,16,0}, /* core5 fp64 bit42 */
			{19082,16,0}, /* core5 fp64 bit43 */
			{19059,16,0}, /* core5 fp64 bit44 */
			{19060,16,0}, /* core5 fp64 bit45 */
			{19061,16,0}, /* core5 fp64 bit46 */
			{19062,16,0}, /* core5 fp64 bit47 */
			{19067,16,0}, /* core5 fp64 bit48 */
			{19068,16,0}, /* core5 fp64 bit49 */
			{19069,16,0}, /* core5 fp64 bit50 */
			{19070,16,0}, /* core5 fp64 bit51 */
			{19055,16,0}, /* core5 fp64 bit52 */
			{19056,16,0}, /* core5 fp64 bit53 */
			{19057,16,0}, /* core5 fp64 bit54 */
			{19058,16,0}, /* core5 fp64 bit55 */
			{19095,16,0}, /* core5 fp64 bit56 */
			{19096,16,0}, /* core5 fp64 bit57 */
			{19097,16,0}, /* core5 fp64 bit58 */
			{19098,16,0}, /* core5 fp64 bit59 */
			{18919,16,0}, /* core5 fp64 bit60 */
			{18920,16,0}, /* core5 fp64 bit61 */
			{18921,16,0}, /* core5 fp64 bit62 */
			{18922,16,0}, /* core5 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{19111,16,0}, /* core5 sp_EL0 bit0 */
			{19112,16,0}, /* core5 sp_EL0 bit1 */
			{19113,16,0}, /* core5 sp_EL0 bit2 */
			{19114,16,0}, /* core5 sp_EL0 bit3 */
			{19119,16,0}, /* core5 sp_EL0 bit4 */
			{19120,16,0}, /* core5 sp_EL0 bit5 */
			{19121,16,0}, /* core5 sp_EL0 bit6 */
			{19122,16,0}, /* core5 sp_EL0 bit7 */
			{23391,20,0}, /* core5 sp_EL0 bit8 */
			{23392,20,0}, /* core5 sp_EL0 bit9 */
			{23393,20,0}, /* core5 sp_EL0 bit10 */
			{23394,20,0}, /* core5 sp_EL0 bit11 */
			{23387,20,0}, /* core5 sp_EL0 bit12 */
			{23388,20,0}, /* core5 sp_EL0 bit13 */
			{23389,20,0}, /* core5 sp_EL0 bit14 */
			{23390,20,0}, /* core5 sp_EL0 bit15 */
			{22071,16,0}, /* core5 sp_EL0 bit16 */
			{22072,16,0}, /* core5 sp_EL0 bit17 */
			{22073,16,0}, /* core5 sp_EL0 bit18 */
			{22074,16,0}, /* core5 sp_EL0 bit19 */
			{16579,16,0}, /* core5 sp_EL0 bit20 */
			{16580,16,0}, /* core5 sp_EL0 bit21 */
			{16581,16,0}, /* core5 sp_EL0 bit22 */
			{16582,16,0}, /* core5 sp_EL0 bit23 */
			{22055,16,0}, /* core5 sp_EL0 bit24 */
			{22056,16,0}, /* core5 sp_EL0 bit25 */
			{22057,16,0}, /* core5 sp_EL0 bit26 */
			{22058,16,0}, /* core5 sp_EL0 bit27 */
			{16595,16,0}, /* core5 sp_EL0 bit28 */
			{16596,16,0}, /* core5 sp_EL0 bit29 */
			{16597,16,0}, /* core5 sp_EL0 bit30 */
			{16598,16,0}, /* core5 sp_EL0 bit31 */
			{21091,16,0}, /* core5 sp_EL0 bit32 */
			{21092,16,0}, /* core5 sp_EL0 bit33 */
			{21093,16,0}, /* core5 sp_EL0 bit34 */
			{21094,16,0}, /* core5 sp_EL0 bit35 */
			{18991,16,0}, /* core5 sp_EL0 bit36 */
			{18992,16,0}, /* core5 sp_EL0 bit37 */
			{18993,16,0}, /* core5 sp_EL0 bit38 */
			{18994,16,0}, /* core5 sp_EL0 bit39 */
			{18987,16,0}, /* core5 sp_EL0 bit40 */
			{18988,16,0}, /* core5 sp_EL0 bit41 */
			{18989,16,0}, /* core5 sp_EL0 bit42 */
			{18990,16,0}, /* core5 sp_EL0 bit43 */
			{18995,16,0}, /* core5 sp_EL0 bit44 */
			{18996,16,0}, /* core5 sp_EL0 bit45 */
			{18997,16,0}, /* core5 sp_EL0 bit46 */
			{18998,16,0}, /* core5 sp_EL0 bit47 */
			{18983,16,0}, /* core5 sp_EL0 bit48 */
			{18984,16,0}, /* core5 sp_EL0 bit49 */
			{18985,16,0}, /* core5 sp_EL0 bit50 */
			{18986,16,0}, /* core5 sp_EL0 bit51 */
			{21047,16,0}, /* core5 sp_EL0 bit52 */
			{21048,16,0}, /* core5 sp_EL0 bit53 */
			{21049,16,0}, /* core5 sp_EL0 bit54 */
			{21050,16,0}, /* core5 sp_EL0 bit55 */
			{21099,16,0}, /* core5 sp_EL0 bit56 */
			{21100,16,0}, /* core5 sp_EL0 bit57 */
			{21101,16,0}, /* core5 sp_EL0 bit58 */
			{21102,16,0}, /* core5 sp_EL0 bit59 */
			{18923,16,0}, /* core5 sp_EL0 bit60 */
			{18924,16,0}, /* core5 sp_EL0 bit61 */
			{18925,16,0}, /* core5 sp_EL0 bit62 */
			{18926,16,0}, /* core5 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{18915,16,0}, /* core5 sp_EL1 bit0 */
			{18916,16,0}, /* core5 sp_EL1 bit1 */
			{18917,16,0}, /* core5 sp_EL1 bit2 */
			{18918,16,0}, /* core5 sp_EL1 bit3 */
			{16623,16,0}, /* core5 sp_EL1 bit4 */
			{16624,16,0}, /* core5 sp_EL1 bit5 */
			{16625,16,0}, /* core5 sp_EL1 bit6 */
			{16626,16,0}, /* core5 sp_EL1 bit7 */
			{23395,20,0}, /* core5 sp_EL1 bit8 */
			{23396,20,0}, /* core5 sp_EL1 bit9 */
			{23397,20,0}, /* core5 sp_EL1 bit10 */
			{23398,20,0}, /* core5 sp_EL1 bit11 */
			{23347,20,0}, /* core5 sp_EL1 bit12 */
			{23348,20,0}, /* core5 sp_EL1 bit13 */
			{23349,20,0}, /* core5 sp_EL1 bit14 */
			{23350,20,0}, /* core5 sp_EL1 bit15 */
			{20623,16,0}, /* core5 sp_EL1 bit16 */
			{20624,16,0}, /* core5 sp_EL1 bit17 */
			{20625,16,0}, /* core5 sp_EL1 bit18 */
			{20626,16,0}, /* core5 sp_EL1 bit19 */
			{20631,16,0}, /* core5 sp_EL1 bit20 */
			{20632,16,0}, /* core5 sp_EL1 bit21 */
			{20633,16,0}, /* core5 sp_EL1 bit22 */
			{20634,16,0}, /* core5 sp_EL1 bit23 */
			{20627,16,0}, /* core5 sp_EL1 bit24 */
			{20628,16,0}, /* core5 sp_EL1 bit25 */
			{20629,16,0}, /* core5 sp_EL1 bit26 */
			{20630,16,0}, /* core5 sp_EL1 bit27 */
			{23379,20,0}, /* core5 sp_EL1 bit28 */
			{23380,20,0}, /* core5 sp_EL1 bit29 */
			{23381,20,0}, /* core5 sp_EL1 bit30 */
			{23382,20,0}, /* core5 sp_EL1 bit31 */
			{19091,16,0}, /* core5 sp_EL1 bit32 */
			{19092,16,0}, /* core5 sp_EL1 bit33 */
			{19093,16,0}, /* core5 sp_EL1 bit34 */
			{19094,16,0}, /* core5 sp_EL1 bit35 */
			{18975,16,0}, /* core5 sp_EL1 bit36 */
			{18976,16,0}, /* core5 sp_EL1 bit37 */
			{18977,16,0}, /* core5 sp_EL1 bit38 */
			{18978,16,0}, /* core5 sp_EL1 bit39 */
			{19083,16,0}, /* core5 sp_EL1 bit40 */
			{19084,16,0}, /* core5 sp_EL1 bit41 */
			{19085,16,0}, /* core5 sp_EL1 bit42 */
			{19086,16,0}, /* core5 sp_EL1 bit43 */
			{19063,16,0}, /* core5 sp_EL1 bit44 */
			{19064,16,0}, /* core5 sp_EL1 bit45 */
			{19065,16,0}, /* core5 sp_EL1 bit46 */
			{19066,16,0}, /* core5 sp_EL1 bit47 */
			{19071,16,0}, /* core5 sp_EL1 bit48 */
			{19072,16,0}, /* core5 sp_EL1 bit49 */
			{19073,16,0}, /* core5 sp_EL1 bit50 */
			{19074,16,0}, /* core5 sp_EL1 bit51 */
			{19075,16,0}, /* core5 sp_EL1 bit52 */
			{19076,16,0}, /* core5 sp_EL1 bit53 */
			{19077,16,0}, /* core5 sp_EL1 bit54 */
			{19078,16,0}, /* core5 sp_EL1 bit55 */
			{21107,16,0}, /* core5 sp_EL1 bit56 */
			{21108,16,0}, /* core5 sp_EL1 bit57 */
			{21109,16,0}, /* core5 sp_EL1 bit58 */
			{21110,16,0}, /* core5 sp_EL1 bit59 */
			{21111,16,0}, /* core5 sp_EL1 bit60 */
			{21112,16,0}, /* core5 sp_EL1 bit61 */
			{21113,16,0}, /* core5 sp_EL1 bit62 */
			{21114,16,0}, /* core5 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{18855,16,0}, /* core5 sp_EL2 bit0 */
			{18856,16,0}, /* core5 sp_EL2 bit1 */
			{18857,16,0}, /* core5 sp_EL2 bit2 */
			{18858,16,0}, /* core5 sp_EL2 bit3 */
			{18867,16,0}, /* core5 sp_EL2 bit4 */
			{18868,16,0}, /* core5 sp_EL2 bit5 */
			{18869,16,0}, /* core5 sp_EL2 bit6 */
			{18870,16,0}, /* core5 sp_EL2 bit7 */
			{22099,16,0}, /* core5 sp_EL2 bit8 */
			{22100,16,0}, /* core5 sp_EL2 bit9 */
			{22101,16,0}, /* core5 sp_EL2 bit10 */
			{22102,16,0}, /* core5 sp_EL2 bit11 */
			{22031,16,0}, /* core5 sp_EL2 bit12 */
			{22032,16,0}, /* core5 sp_EL2 bit13 */
			{22033,16,0}, /* core5 sp_EL2 bit14 */
			{22034,16,0}, /* core5 sp_EL2 bit15 */
			{22063,16,0}, /* core5 sp_EL2 bit16 */
			{22064,16,0}, /* core5 sp_EL2 bit17 */
			{22065,16,0}, /* core5 sp_EL2 bit18 */
			{22066,16,0}, /* core5 sp_EL2 bit19 */
			{23111,16,0}, /* core5 sp_EL2 bit20 */
			{23112,16,0}, /* core5 sp_EL2 bit21 */
			{23113,16,0}, /* core5 sp_EL2 bit22 */
			{23114,16,0}, /* core5 sp_EL2 bit23 */
			{22059,16,0}, /* core5 sp_EL2 bit24 */
			{22060,16,0}, /* core5 sp_EL2 bit25 */
			{22061,16,0}, /* core5 sp_EL2 bit26 */
			{22062,16,0}, /* core5 sp_EL2 bit27 */
			{18875,16,0}, /* core5 sp_EL2 bit28 */
			{18876,16,0}, /* core5 sp_EL2 bit29 */
			{18877,16,0}, /* core5 sp_EL2 bit30 */
			{18878,16,0}, /* core5 sp_EL2 bit31 */
			{18955,16,0}, /* core5 sp_EL2 bit32 */
			{18956,16,0}, /* core5 sp_EL2 bit33 */
			{18957,16,0}, /* core5 sp_EL2 bit34 */
			{18958,16,0}, /* core5 sp_EL2 bit35 */
			{21059,16,0}, /* core5 sp_EL2 bit36 */
			{21060,16,0}, /* core5 sp_EL2 bit37 */
			{21061,16,0}, /* core5 sp_EL2 bit38 */
			{21062,16,0}, /* core5 sp_EL2 bit39 */
			{21075,16,0}, /* core5 sp_EL2 bit40 */
			{21076,16,0}, /* core5 sp_EL2 bit41 */
			{21077,16,0}, /* core5 sp_EL2 bit42 */
			{21078,16,0}, /* core5 sp_EL2 bit43 */
			{21063,16,0}, /* core5 sp_EL2 bit44 */
			{21064,16,0}, /* core5 sp_EL2 bit45 */
			{21065,16,0}, /* core5 sp_EL2 bit46 */
			{21066,16,0}, /* core5 sp_EL2 bit47 */
			{21079,16,0}, /* core5 sp_EL2 bit48 */
			{21080,16,0}, /* core5 sp_EL2 bit49 */
			{21081,16,0}, /* core5 sp_EL2 bit50 */
			{21082,16,0}, /* core5 sp_EL2 bit51 */
			{21067,16,0}, /* core5 sp_EL2 bit52 */
			{21068,16,0}, /* core5 sp_EL2 bit53 */
			{21069,16,0}, /* core5 sp_EL2 bit54 */
			{21070,16,0}, /* core5 sp_EL2 bit55 */
			{18951,16,0}, /* core5 sp_EL2 bit56 */
			{18952,16,0}, /* core5 sp_EL2 bit57 */
			{18953,16,0}, /* core5 sp_EL2 bit58 */
			{18954,16,0}, /* core5 sp_EL2 bit59 */
			{18939,16,0}, /* core5 sp_EL2 bit60 */
			{18940,16,0}, /* core5 sp_EL2 bit61 */
			{18941,16,0}, /* core5 sp_EL2 bit62 */
			{18942,16,0}, /* core5 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{18847,16,0}, /* core5 sp_EL3 bit0 */
			{18848,16,0}, /* core5 sp_EL3 bit1 */
			{18849,16,0}, /* core5 sp_EL3 bit2 */
			{18850,16,0}, /* core5 sp_EL3 bit3 */
			{19127,16,0}, /* core5 sp_EL3 bit4 */
			{19128,16,0}, /* core5 sp_EL3 bit5 */
			{19129,16,0}, /* core5 sp_EL3 bit6 */
			{19130,16,0}, /* core5 sp_EL3 bit7 */
			{16587,16,0}, /* core5 sp_EL3 bit8 */
			{16588,16,0}, /* core5 sp_EL3 bit9 */
			{16589,16,0}, /* core5 sp_EL3 bit10 */
			{16590,16,0}, /* core5 sp_EL3 bit11 */
			{19139,16,0}, /* core5 sp_EL3 bit12 */
			{19140,16,0}, /* core5 sp_EL3 bit13 */
			{19141,16,0}, /* core5 sp_EL3 bit14 */
			{19142,16,0}, /* core5 sp_EL3 bit15 */
			{22095,16,0}, /* core5 sp_EL3 bit16 */
			{22096,16,0}, /* core5 sp_EL3 bit17 */
			{22097,16,0}, /* core5 sp_EL3 bit18 */
			{22098,16,0}, /* core5 sp_EL3 bit19 */
			{22039,16,0}, /* core5 sp_EL3 bit20 */
			{22040,16,0}, /* core5 sp_EL3 bit21 */
			{22041,16,0}, /* core5 sp_EL3 bit22 */
			{22042,16,0}, /* core5 sp_EL3 bit23 */
			{16583,16,0}, /* core5 sp_EL3 bit24 */
			{16584,16,0}, /* core5 sp_EL3 bit25 */
			{16585,16,0}, /* core5 sp_EL3 bit26 */
			{16586,16,0}, /* core5 sp_EL3 bit27 */
			{16591,16,0}, /* core5 sp_EL3 bit28 */
			{16592,16,0}, /* core5 sp_EL3 bit29 */
			{16593,16,0}, /* core5 sp_EL3 bit30 */
			{16594,16,0}, /* core5 sp_EL3 bit31 */
			{18959,16,0}, /* core5 sp_EL3 bit32 */
			{18960,16,0}, /* core5 sp_EL3 bit33 */
			{18961,16,0}, /* core5 sp_EL3 bit34 */
			{18962,16,0}, /* core5 sp_EL3 bit35 */
			{20971,16,0}, /* core5 sp_EL3 bit36 */
			{20972,16,0}, /* core5 sp_EL3 bit37 */
			{20973,16,0}, /* core5 sp_EL3 bit38 */
			{20974,16,0}, /* core5 sp_EL3 bit39 */
			{18963,16,0}, /* core5 sp_EL3 bit40 */
			{18964,16,0}, /* core5 sp_EL3 bit41 */
			{18965,16,0}, /* core5 sp_EL3 bit42 */
			{18966,16,0}, /* core5 sp_EL3 bit43 */
			{20975,16,0}, /* core5 sp_EL3 bit44 */
			{20976,16,0}, /* core5 sp_EL3 bit45 */
			{20977,16,0}, /* core5 sp_EL3 bit46 */
			{20978,16,0}, /* core5 sp_EL3 bit47 */
			{21071,16,0}, /* core5 sp_EL3 bit48 */
			{21072,16,0}, /* core5 sp_EL3 bit49 */
			{21073,16,0}, /* core5 sp_EL3 bit50 */
			{21074,16,0}, /* core5 sp_EL3 bit51 */
			{20979,16,0}, /* core5 sp_EL3 bit52 */
			{20980,16,0}, /* core5 sp_EL3 bit53 */
			{20981,16,0}, /* core5 sp_EL3 bit54 */
			{20982,16,0}, /* core5 sp_EL3 bit55 */
			{18947,16,0}, /* core5 sp_EL3 bit56 */
			{18948,16,0}, /* core5 sp_EL3 bit57 */
			{18949,16,0}, /* core5 sp_EL3 bit58 */
			{18950,16,0}, /* core5 sp_EL3 bit59 */
			{18935,16,0}, /* core5 sp_EL3 bit60 */
			{18936,16,0}, /* core5 sp_EL3 bit61 */
			{18937,16,0}, /* core5 sp_EL3 bit62 */
			{18938,16,0}, /* core5 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{18851,16,0}, /* core5 elr_EL1 bit0 */
			{18852,16,0}, /* core5 elr_EL1 bit1 */
			{18853,16,0}, /* core5 elr_EL1 bit2 */
			{18854,16,0}, /* core5 elr_EL1 bit3 */
			{18871,16,0}, /* core5 elr_EL1 bit4 */
			{18872,16,0}, /* core5 elr_EL1 bit5 */
			{18873,16,0}, /* core5 elr_EL1 bit6 */
			{18874,16,0}, /* core5 elr_EL1 bit7 */
			{22091,16,0}, /* core5 elr_EL1 bit8 */
			{22092,16,0}, /* core5 elr_EL1 bit9 */
			{22093,16,0}, /* core5 elr_EL1 bit10 */
			{22094,16,0}, /* core5 elr_EL1 bit11 */
			{19143,16,0}, /* core5 elr_EL1 bit12 */
			{19144,16,0}, /* core5 elr_EL1 bit13 */
			{19145,16,0}, /* core5 elr_EL1 bit14 */
			{19146,16,0}, /* core5 elr_EL1 bit15 */
			{22083,16,0}, /* core5 elr_EL1 bit16 */
			{22084,16,0}, /* core5 elr_EL1 bit17 */
			{22085,16,0}, /* core5 elr_EL1 bit18 */
			{22086,16,0}, /* core5 elr_EL1 bit19 */
			{22079,16,0}, /* core5 elr_EL1 bit20 */
			{22080,16,0}, /* core5 elr_EL1 bit21 */
			{22081,16,0}, /* core5 elr_EL1 bit22 */
			{22082,16,0}, /* core5 elr_EL1 bit23 */
			{22075,16,0}, /* core5 elr_EL1 bit24 */
			{22076,16,0}, /* core5 elr_EL1 bit25 */
			{22077,16,0}, /* core5 elr_EL1 bit26 */
			{22078,16,0}, /* core5 elr_EL1 bit27 */
			{18911,16,0}, /* core5 elr_EL1 bit28 */
			{18912,16,0}, /* core5 elr_EL1 bit29 */
			{18913,16,0}, /* core5 elr_EL1 bit30 */
			{18914,16,0}, /* core5 elr_EL1 bit31 */
			{21095,16,0}, /* core5 elr_EL1 bit32 */
			{21096,16,0}, /* core5 elr_EL1 bit33 */
			{21097,16,0}, /* core5 elr_EL1 bit34 */
			{21098,16,0}, /* core5 elr_EL1 bit35 */
			{21055,16,0}, /* core5 elr_EL1 bit36 */
			{21056,16,0}, /* core5 elr_EL1 bit37 */
			{21057,16,0}, /* core5 elr_EL1 bit38 */
			{21058,16,0}, /* core5 elr_EL1 bit39 */
			{21083,16,0}, /* core5 elr_EL1 bit40 */
			{21084,16,0}, /* core5 elr_EL1 bit41 */
			{21085,16,0}, /* core5 elr_EL1 bit42 */
			{21086,16,0}, /* core5 elr_EL1 bit43 */
			{18971,16,0}, /* core5 elr_EL1 bit44 */
			{18972,16,0}, /* core5 elr_EL1 bit45 */
			{18973,16,0}, /* core5 elr_EL1 bit46 */
			{18974,16,0}, /* core5 elr_EL1 bit47 */
			{18967,16,0}, /* core5 elr_EL1 bit48 */
			{18968,16,0}, /* core5 elr_EL1 bit49 */
			{18969,16,0}, /* core5 elr_EL1 bit50 */
			{18970,16,0}, /* core5 elr_EL1 bit51 */
			{21051,16,0}, /* core5 elr_EL1 bit52 */
			{21052,16,0}, /* core5 elr_EL1 bit53 */
			{21053,16,0}, /* core5 elr_EL1 bit54 */
			{21054,16,0}, /* core5 elr_EL1 bit55 */
			{21103,16,0}, /* core5 elr_EL1 bit56 */
			{21104,16,0}, /* core5 elr_EL1 bit57 */
			{21105,16,0}, /* core5 elr_EL1 bit58 */
			{21106,16,0}, /* core5 elr_EL1 bit59 */
			{18927,16,0}, /* core5 elr_EL1 bit60 */
			{18928,16,0}, /* core5 elr_EL1 bit61 */
			{18929,16,0}, /* core5 elr_EL1 bit62 */
			{18930,16,0}, /* core5 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{19103,16,0}, /* core5 elr_EL2 bit0 */
			{19104,16,0}, /* core5 elr_EL2 bit1 */
			{19105,16,0}, /* core5 elr_EL2 bit2 */
			{19106,16,0}, /* core5 elr_EL2 bit3 */
			{19115,16,0}, /* core5 elr_EL2 bit4 */
			{19116,16,0}, /* core5 elr_EL2 bit5 */
			{19117,16,0}, /* core5 elr_EL2 bit6 */
			{19118,16,0}, /* core5 elr_EL2 bit7 */
			{23339,20,0}, /* core5 elr_EL2 bit8 */
			{23340,20,0}, /* core5 elr_EL2 bit9 */
			{23341,20,0}, /* core5 elr_EL2 bit10 */
			{23342,20,0}, /* core5 elr_EL2 bit11 */
			{23383,20,0}, /* core5 elr_EL2 bit12 */
			{23384,20,0}, /* core5 elr_EL2 bit13 */
			{23385,20,0}, /* core5 elr_EL2 bit14 */
			{23386,20,0}, /* core5 elr_EL2 bit15 */
			{22087,16,0}, /* core5 elr_EL2 bit16 */
			{22088,16,0}, /* core5 elr_EL2 bit17 */
			{22089,16,0}, /* core5 elr_EL2 bit18 */
			{22090,16,0}, /* core5 elr_EL2 bit19 */
			{23331,20,0}, /* core5 elr_EL2 bit20 */
			{23332,20,0}, /* core5 elr_EL2 bit21 */
			{23333,20,0}, /* core5 elr_EL2 bit22 */
			{23334,20,0}, /* core5 elr_EL2 bit23 */
			{23335,20,0}, /* core5 elr_EL2 bit24 */
			{23336,20,0}, /* core5 elr_EL2 bit25 */
			{23337,20,0}, /* core5 elr_EL2 bit26 */
			{23338,20,0}, /* core5 elr_EL2 bit27 */
			{16599,16,0}, /* core5 elr_EL2 bit28 */
			{16600,16,0}, /* core5 elr_EL2 bit29 */
			{16601,16,0}, /* core5 elr_EL2 bit30 */
			{16602,16,0}, /* core5 elr_EL2 bit31 */
			{18779,16,0}, /* core5 elr_EL2 bit32 */
			{18780,16,0}, /* core5 elr_EL2 bit33 */
			{18781,16,0}, /* core5 elr_EL2 bit34 */
			{18782,16,0}, /* core5 elr_EL2 bit35 */
			{18739,16,0}, /* core5 elr_EL2 bit36 */
			{18740,16,0}, /* core5 elr_EL2 bit37 */
			{18741,16,0}, /* core5 elr_EL2 bit38 */
			{18742,16,0}, /* core5 elr_EL2 bit39 */
			{18759,16,0}, /* core5 elr_EL2 bit40 */
			{18760,16,0}, /* core5 elr_EL2 bit41 */
			{18761,16,0}, /* core5 elr_EL2 bit42 */
			{18762,16,0}, /* core5 elr_EL2 bit43 */
			{18735,16,0}, /* core5 elr_EL2 bit44 */
			{18736,16,0}, /* core5 elr_EL2 bit45 */
			{18737,16,0}, /* core5 elr_EL2 bit46 */
			{18738,16,0}, /* core5 elr_EL2 bit47 */
			{18747,16,0}, /* core5 elr_EL2 bit48 */
			{18748,16,0}, /* core5 elr_EL2 bit49 */
			{18749,16,0}, /* core5 elr_EL2 bit50 */
			{18750,16,0}, /* core5 elr_EL2 bit51 */
			{18743,16,0}, /* core5 elr_EL2 bit52 */
			{18744,16,0}, /* core5 elr_EL2 bit53 */
			{18745,16,0}, /* core5 elr_EL2 bit54 */
			{18746,16,0}, /* core5 elr_EL2 bit55 */
			{18783,16,0}, /* core5 elr_EL2 bit56 */
			{18784,16,0}, /* core5 elr_EL2 bit57 */
			{18785,16,0}, /* core5 elr_EL2 bit58 */
			{18786,16,0}, /* core5 elr_EL2 bit59 */
			{18807,16,0}, /* core5 elr_EL2 bit60 */
			{18808,16,0}, /* core5 elr_EL2 bit61 */
			{18809,16,0}, /* core5 elr_EL2 bit62 */
			{18810,16,0}, /* core5 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{21975,16,0}, /* core5 elr_EL3 bit0 */
			{21976,16,0}, /* core5 elr_EL3 bit1 */
			{21977,16,0}, /* core5 elr_EL3 bit2 */
			{21978,16,0}, /* core5 elr_EL3 bit3 */
			{21983,16,0}, /* core5 elr_EL3 bit4 */
			{21984,16,0}, /* core5 elr_EL3 bit5 */
			{21985,16,0}, /* core5 elr_EL3 bit6 */
			{21986,16,0}, /* core5 elr_EL3 bit7 */
			{21615,16,0}, /* core5 elr_EL3 bit8 */
			{21616,16,0}, /* core5 elr_EL3 bit9 */
			{21617,16,0}, /* core5 elr_EL3 bit10 */
			{21618,16,0}, /* core5 elr_EL3 bit11 */
			{21587,16,0}, /* core5 elr_EL3 bit12 */
			{21588,16,0}, /* core5 elr_EL3 bit13 */
			{21589,16,0}, /* core5 elr_EL3 bit14 */
			{21590,16,0}, /* core5 elr_EL3 bit15 */
			{21379,16,0}, /* core5 elr_EL3 bit16 */
			{21380,16,0}, /* core5 elr_EL3 bit17 */
			{21381,16,0}, /* core5 elr_EL3 bit18 */
			{21382,16,0}, /* core5 elr_EL3 bit19 */
			{21623,16,0}, /* core5 elr_EL3 bit20 */
			{21624,16,0}, /* core5 elr_EL3 bit21 */
			{21625,16,0}, /* core5 elr_EL3 bit22 */
			{21626,16,0}, /* core5 elr_EL3 bit23 */
			{21627,16,0}, /* core5 elr_EL3 bit24 */
			{21628,16,0}, /* core5 elr_EL3 bit25 */
			{21629,16,0}, /* core5 elr_EL3 bit26 */
			{21630,16,0}, /* core5 elr_EL3 bit27 */
			{22003,16,0}, /* core5 elr_EL3 bit28 */
			{22004,16,0}, /* core5 elr_EL3 bit29 */
			{22005,16,0}, /* core5 elr_EL3 bit30 */
			{22006,16,0}, /* core5 elr_EL3 bit31 */
			{21559,16,0}, /* core5 elr_EL3 bit32 */
			{21560,16,0}, /* core5 elr_EL3 bit33 */
			{21561,16,0}, /* core5 elr_EL3 bit34 */
			{21562,16,0}, /* core5 elr_EL3 bit35 */
			{21531,16,0}, /* core5 elr_EL3 bit36 */
			{21532,16,0}, /* core5 elr_EL3 bit37 */
			{21533,16,0}, /* core5 elr_EL3 bit38 */
			{21534,16,0}, /* core5 elr_EL3 bit39 */
			{21555,16,0}, /* core5 elr_EL3 bit40 */
			{21556,16,0}, /* core5 elr_EL3 bit41 */
			{21557,16,0}, /* core5 elr_EL3 bit42 */
			{21558,16,0}, /* core5 elr_EL3 bit43 */
			{21535,16,0}, /* core5 elr_EL3 bit44 */
			{21536,16,0}, /* core5 elr_EL3 bit45 */
			{21537,16,0}, /* core5 elr_EL3 bit46 */
			{21538,16,0}, /* core5 elr_EL3 bit47 */
			{21539,16,0}, /* core5 elr_EL3 bit48 */
			{21540,16,0}, /* core5 elr_EL3 bit49 */
			{21541,16,0}, /* core5 elr_EL3 bit50 */
			{21542,16,0}, /* core5 elr_EL3 bit51 */
			{21515,16,0}, /* core5 elr_EL3 bit52 */
			{21516,16,0}, /* core5 elr_EL3 bit53 */
			{21517,16,0}, /* core5 elr_EL3 bit54 */
			{21518,16,0}, /* core5 elr_EL3 bit55 */
			{21567,16,0}, /* core5 elr_EL3 bit56 */
			{21568,16,0}, /* core5 elr_EL3 bit57 */
			{21569,16,0}, /* core5 elr_EL3 bit58 */
			{21570,16,0}, /* core5 elr_EL3 bit59 */
			{21571,16,0}, /* core5 elr_EL3 bit60 */
			{21572,16,0}, /* core5 elr_EL3 bit61 */
			{21573,16,0}, /* core5 elr_EL3 bit62 */
			{21574,16,0}, /* core5 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{14284,16,0}, /* core5 raw_pc bit0 */
			{19559,16,0}, /* core5 raw_pc bit1 */
			{19560,16,0}, /* core5 raw_pc bit2 */
			{20547,16,0}, /* core5 raw_pc bit3 */
			{20548,16,0}, /* core5 raw_pc bit4 */
			{20549,16,0}, /* core5 raw_pc bit5 */
			{20550,16,0}, /* core5 raw_pc bit6 */
			{18323,16,0}, /* core5 raw_pc bit7 */
			{18324,16,0}, /* core5 raw_pc bit8 */
			{18325,16,0}, /* core5 raw_pc bit9 */
			{18326,16,0}, /* core5 raw_pc bit10 */
			{18335,16,0}, /* core5 raw_pc bit11 */
			{18336,16,0}, /* core5 raw_pc bit12 */
			{18337,16,0}, /* core5 raw_pc bit13 */
			{18338,16,0}, /* core5 raw_pc bit14 */
			{18339,16,0}, /* core5 raw_pc bit15 */
			{18340,16,0}, /* core5 raw_pc bit16 */
			{18341,16,0}, /* core5 raw_pc bit17 */
			{18342,16,0}, /* core5 raw_pc bit18 */
			{18355,16,0}, /* core5 raw_pc bit19 */
			{18356,16,0}, /* core5 raw_pc bit20 */
			{18357,16,0}, /* core5 raw_pc bit21 */
			{18358,16,0}, /* core5 raw_pc bit22 */
			{18343,16,0}, /* core5 raw_pc bit23 */
			{18344,16,0}, /* core5 raw_pc bit24 */
			{18345,16,0}, /* core5 raw_pc bit25 */
			{18346,16,0}, /* core5 raw_pc bit26 */
			{18347,16,0}, /* core5 raw_pc bit27 */
			{18348,16,0}, /* core5 raw_pc bit28 */
			{18349,16,0}, /* core5 raw_pc bit29 */
			{18350,16,0}, /* core5 raw_pc bit30 */
			{15884,16,0}, /* core5 raw_pc bit31 */
			{17631,16,0}, /* core5 raw_pc bit32 */
			{17632,16,0}, /* core5 raw_pc bit33 */
			{17633,16,0}, /* core5 raw_pc bit34 */
			{17634,16,0}, /* core5 raw_pc bit35 */
			{18155,16,0}, /* core5 raw_pc bit36 */
			{18156,16,0}, /* core5 raw_pc bit37 */
			{18157,16,0}, /* core5 raw_pc bit38 */
			{18158,16,0}, /* core5 raw_pc bit39 */
			{17915,16,0}, /* core5 raw_pc bit40 */
			{17916,16,0}, /* core5 raw_pc bit41 */
			{17917,16,0}, /* core5 raw_pc bit42 */
			{17918,16,0}, /* core5 raw_pc bit43 */
			{17639,16,0}, /* core5 raw_pc bit44 */
			{17640,16,0}, /* core5 raw_pc bit45 */
			{17641,16,0}, /* core5 raw_pc bit46 */
			{17642,16,0}, /* core5 raw_pc bit47 */
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
			{14217,16,0}, /* core5 pc_iss bit0 */
			{14277,16,0}, /* core5 pc_iss bit1 */
			{14278,16,0}, /* core5 pc_iss bit2 */
			{14291,16,0}, /* core5 pc_iss bit3 */
			{14280,16,0}, /* core5 pc_iss bit4 */
			{14216,16,0}, /* core5 pc_iss bit5 */
			{14215,16,0}, /* core5 pc_iss bit6 */
			{14214,16,0}, /* core5 pc_iss bit7 */
			{19229,20,0}, /* core5 pc_iss bit8 */
			{19228,20,0}, /* core5 pc_iss bit9 */
			{14294,16,0}, /* core5 pc_iss bit10 */
			{14295,16,0}, /* core5 pc_iss bit11 */
			{19221,20,0}, /* core5 pc_iss bit12 */
			{19220,20,0}, /* core5 pc_iss bit13 */
			{19227,20,0}, /* core5 pc_iss bit14 */
			{17902,16,0}, /* core5 pc_iss bit15 */
			{17901,16,0}, /* core5 pc_iss bit16 */
			{17890,16,0}, /* core5 pc_iss bit17 */
			{17889,16,0}, /* core5 pc_iss bit18 */
			{17900,16,0}, /* core5 pc_iss bit19 */
			{17899,16,0}, /* core5 pc_iss bit20 */
			{19225,20,0}, /* core5 pc_iss bit21 */
			{19226,20,0}, /* core5 pc_iss bit22 */
			{19257,20,0}, /* core5 pc_iss bit23 */
			{19224,20,0}, /* core5 pc_iss bit24 */
			{19223,20,0}, /* core5 pc_iss bit25 */
			{19222,20,0}, /* core5 pc_iss bit26 */
			{19259,20,0}, /* core5 pc_iss bit27 */
			{19258,20,0}, /* core5 pc_iss bit28 */
			{14297,16,0}, /* core5 pc_iss bit29 */
			{19256,20,0}, /* core5 pc_iss bit30 */
			{14296,16,0}, /* core5 pc_iss bit31 */
			{17627,16,0}, /* core5 pc_iss bit32 */
			{17628,16,0}, /* core5 pc_iss bit33 */
			{17629,16,0}, /* core5 pc_iss bit34 */
			{17630,16,0}, /* core5 pc_iss bit35 */
			{17615,16,0}, /* core5 pc_iss bit36 */
			{17616,16,0}, /* core5 pc_iss bit37 */
			{17617,16,0}, /* core5 pc_iss bit38 */
			{17618,16,0}, /* core5 pc_iss bit39 */
			{17623,16,0}, /* core5 pc_iss bit40 */
			{17624,16,0}, /* core5 pc_iss bit41 */
			{17625,16,0}, /* core5 pc_iss bit42 */
			{17626,16,0}, /* core5 pc_iss bit43 */
			{17619,16,0}, /* core5 pc_iss bit44 */
			{17620,16,0}, /* core5 pc_iss bit45 */
			{17621,16,0}, /* core5 pc_iss bit46 */
			{17622,16,0}, /* core5 pc_iss bit47 */
			{17183,16,0}, /* core5 pc_iss bit48 */
			{17184,16,0}, /* core5 pc_iss bit49 */
			{17185,16,0}, /* core5 pc_iss bit50 */
			{17186,16,0}, /* core5 pc_iss bit51 */
			{17187,16,0}, /* core5 pc_iss bit52 */
			{17188,16,0}, /* core5 pc_iss bit53 */
			{17189,16,0}, /* core5 pc_iss bit54 */
			{17190,16,0}, /* core5 pc_iss bit55 */
			{17179,16,0}, /* core5 pc_iss bit56 */
			{17180,16,0}, /* core5 pc_iss bit57 */
			{17181,16,0}, /* core5 pc_iss bit58 */
			{17182,16,0}, /* core5 pc_iss bit59 */
			{17191,16,0}, /* core5 pc_iss bit60 */
			{17192,16,0}, /* core5 pc_iss bit61 */
			{17193,16,0}, /* core5 pc_iss bit62 */
			{17194,16,0}, /* core5 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{19562,16,0}, /* core5 full_pc_wr bit0 */
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
			{24026,20,0}, /* core5 full_pc_ex1 bit0 */
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
			{23798,20,0}, /* core5 full_pc_ex2 bit0 */
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
			{23439,21,0}, /* core6 pc bit0 */
			{23440,21,0}, /* core6 pc bit1 */
			{23441,21,0}, /* core6 pc bit2 */
			{23442,21,0}, /* core6 pc bit3 */
			{23427,21,0}, /* core6 pc bit4 */
			{23428,21,0}, /* core6 pc bit5 */
			{23429,21,0}, /* core6 pc bit6 */
			{23430,21,0}, /* core6 pc bit7 */
			{18247,17,0}, /* core6 pc bit8 */
			{18248,17,0}, /* core6 pc bit9 */
			{18249,17,0}, /* core6 pc bit10 */
			{18250,17,0}, /* core6 pc bit11 */
			{23459,21,0}, /* core6 pc bit12 */
			{23460,21,0}, /* core6 pc bit13 */
			{23461,21,0}, /* core6 pc bit14 */
			{23462,21,0}, /* core6 pc bit15 */
			{18231,17,0}, /* core6 pc bit16 */
			{18232,17,0}, /* core6 pc bit17 */
			{18233,17,0}, /* core6 pc bit18 */
			{18234,17,0}, /* core6 pc bit19 */
			{18239,17,0}, /* core6 pc bit20 */
			{18240,17,0}, /* core6 pc bit21 */
			{18241,17,0}, /* core6 pc bit22 */
			{18242,17,0}, /* core6 pc bit23 */
			{18243,17,0}, /* core6 pc bit24 */
			{18244,17,0}, /* core6 pc bit25 */
			{18245,17,0}, /* core6 pc bit26 */
			{18246,17,0}, /* core6 pc bit27 */
			{23455,21,0}, /* core6 pc bit28 */
			{23456,21,0}, /* core6 pc bit29 */
			{23457,21,0}, /* core6 pc bit30 */
			{23458,21,0}, /* core6 pc bit31 */
			{18147,17,0}, /* core6 pc bit32 */
			{18148,17,0}, /* core6 pc bit33 */
			{18149,17,0}, /* core6 pc bit34 */
			{18150,17,0}, /* core6 pc bit35 */
			{18879,17,0}, /* core6 pc bit36 */
			{18880,17,0}, /* core6 pc bit37 */
			{18881,17,0}, /* core6 pc bit38 */
			{18882,17,0}, /* core6 pc bit39 */
			{18883,17,0}, /* core6 pc bit40 */
			{18884,17,0}, /* core6 pc bit41 */
			{18885,17,0}, /* core6 pc bit42 */
			{18886,17,0}, /* core6 pc bit43 */
			{18151,17,0}, /* core6 pc bit44 */
			{18152,17,0}, /* core6 pc bit45 */
			{18153,17,0}, /* core6 pc bit46 */
			{18154,17,0}, /* core6 pc bit47 */
			{23777,21,0}, /* core6 pc bit48 */
			{23778,21,0}, /* core6 pc bit49 */
			{23779,21,0}, /* core6 pc bit50 */
			{23780,21,0}, /* core6 pc bit51 */
			{18143,17,0}, /* core6 pc bit52 */
			{18144,17,0}, /* core6 pc bit53 */
			{18145,17,0}, /* core6 pc bit54 */
			{18146,17,0}, /* core6 pc bit55 */
			{17659,17,0}, /* core6 pc bit56 */
			{17660,17,0}, /* core6 pc bit57 */
			{17661,17,0}, /* core6 pc bit58 */
			{17662,17,0}, /* core6 pc bit59 */
			{18139,17,0}, /* core6 pc bit60 */
			{18140,17,0}, /* core6 pc bit61 */
			{18141,17,0}, /* core6 pc bit62 */
			{18142,17,0}, /* core6 pc bit63 */
			}},
			.sp32 = {{
			{21959,17,0}, /* core6 sp32 bit0 */
			{21960,17,0}, /* core6 sp32 bit1 */
			{21961,17,0}, /* core6 sp32 bit2 */
			{21962,17,0}, /* core6 sp32 bit3 */
			{21987,17,0}, /* core6 sp32 bit4 */
			{21988,17,0}, /* core6 sp32 bit5 */
			{21989,17,0}, /* core6 sp32 bit6 */
			{21990,17,0}, /* core6 sp32 bit7 */
			{24209,21,0}, /* core6 sp32 bit8 */
			{24210,21,0}, /* core6 sp32 bit9 */
			{24211,21,0}, /* core6 sp32 bit10 */
			{24212,21,0}, /* core6 sp32 bit11 */
			{21591,17,0}, /* core6 sp32 bit12 */
			{21592,17,0}, /* core6 sp32 bit13 */
			{21593,17,0}, /* core6 sp32 bit14 */
			{21594,17,0}, /* core6 sp32 bit15 */
			{24193,21,0}, /* core6 sp32 bit16 */
			{24194,21,0}, /* core6 sp32 bit17 */
			{24195,21,0}, /* core6 sp32 bit18 */
			{24196,21,0}, /* core6 sp32 bit19 */
			{24197,21,0}, /* core6 sp32 bit20 */
			{24198,21,0}, /* core6 sp32 bit21 */
			{24199,21,0}, /* core6 sp32 bit22 */
			{24200,21,0}, /* core6 sp32 bit23 */
			{24189,21,0}, /* core6 sp32 bit24 */
			{24190,21,0}, /* core6 sp32 bit25 */
			{24191,21,0}, /* core6 sp32 bit26 */
			{24192,21,0}, /* core6 sp32 bit27 */
			{24121,21,0}, /* core6 sp32 bit28 */
			{24122,21,0}, /* core6 sp32 bit29 */
			{24123,21,0}, /* core6 sp32 bit30 */
			{24124,21,0}, /* core6 sp32 bit31 */
			{21431,17,0}, /* core6 sp32 bit32 */
			{21432,17,0}, /* core6 sp32 bit33 */
			{21433,17,0}, /* core6 sp32 bit34 */
			{21434,17,0}, /* core6 sp32 bit35 */
			{21159,17,0}, /* core6 sp32 bit36 */
			{21160,17,0}, /* core6 sp32 bit37 */
			{21161,17,0}, /* core6 sp32 bit38 */
			{21162,17,0}, /* core6 sp32 bit39 */
			{21155,17,0}, /* core6 sp32 bit40 */
			{21156,17,0}, /* core6 sp32 bit41 */
			{21157,17,0}, /* core6 sp32 bit42 */
			{21158,17,0}, /* core6 sp32 bit43 */
			{21199,17,0}, /* core6 sp32 bit44 */
			{21200,17,0}, /* core6 sp32 bit45 */
			{21201,17,0}, /* core6 sp32 bit46 */
			{21202,17,0}, /* core6 sp32 bit47 */
			{21383,17,0}, /* core6 sp32 bit48 */
			{21384,17,0}, /* core6 sp32 bit49 */
			{21385,17,0}, /* core6 sp32 bit50 */
			{21386,17,0}, /* core6 sp32 bit51 */
			{21203,17,0}, /* core6 sp32 bit52 */
			{21204,17,0}, /* core6 sp32 bit53 */
			{21205,17,0}, /* core6 sp32 bit54 */
			{21206,17,0}, /* core6 sp32 bit55 */
			{21143,17,0}, /* core6 sp32 bit56 */
			{21144,17,0}, /* core6 sp32 bit57 */
			{21145,17,0}, /* core6 sp32 bit58 */
			{21146,17,0}, /* core6 sp32 bit59 */
			{21151,17,0}, /* core6 sp32 bit60 */
			{21152,17,0}, /* core6 sp32 bit61 */
			{21153,17,0}, /* core6 sp32 bit62 */
			{21154,17,0}, /* core6 sp32 bit63 */
			}},
			.fp32 = {{
			{19762,21,0}, /* core6 fp32 bit0 */
			{19763,21,0}, /* core6 fp32 bit1 */
			{19764,21,0}, /* core6 fp32 bit2 */
			{19765,21,0}, /* core6 fp32 bit3 */
			{19754,21,0}, /* core6 fp32 bit4 */
			{19755,21,0}, /* core6 fp32 bit5 */
			{19756,21,0}, /* core6 fp32 bit6 */
			{19757,21,0}, /* core6 fp32 bit7 */
			{24137,21,0}, /* core6 fp32 bit8 */
			{24138,21,0}, /* core6 fp32 bit9 */
			{24139,21,0}, /* core6 fp32 bit10 */
			{24140,21,0}, /* core6 fp32 bit11 */
			{24093,21,0}, /* core6 fp32 bit12 */
			{24094,21,0}, /* core6 fp32 bit13 */
			{24095,21,0}, /* core6 fp32 bit14 */
			{24096,21,0}, /* core6 fp32 bit15 */
			{24141,21,0}, /* core6 fp32 bit16 */
			{24142,21,0}, /* core6 fp32 bit17 */
			{24143,21,0}, /* core6 fp32 bit18 */
			{24144,21,0}, /* core6 fp32 bit19 */
			{24149,21,0}, /* core6 fp32 bit20 */
			{24150,21,0}, /* core6 fp32 bit21 */
			{24151,21,0}, /* core6 fp32 bit22 */
			{24152,21,0}, /* core6 fp32 bit23 */
			{24145,21,0}, /* core6 fp32 bit24 */
			{24146,21,0}, /* core6 fp32 bit25 */
			{24147,21,0}, /* core6 fp32 bit26 */
			{24148,21,0}, /* core6 fp32 bit27 */
			{19806,21,0}, /* core6 fp32 bit28 */
			{19807,21,0}, /* core6 fp32 bit29 */
			{19808,21,0}, /* core6 fp32 bit30 */
			{19809,21,0}, /* core6 fp32 bit31 */
			{21475,17,0}, /* core6 fp32 bit32 */
			{21476,17,0}, /* core6 fp32 bit33 */
			{21477,17,0}, /* core6 fp32 bit34 */
			{21478,17,0}, /* core6 fp32 bit35 */
			{21479,17,0}, /* core6 fp32 bit36 */
			{21480,17,0}, /* core6 fp32 bit37 */
			{21481,17,0}, /* core6 fp32 bit38 */
			{21482,17,0}, /* core6 fp32 bit39 */
			{22159,17,0}, /* core6 fp32 bit40 */
			{22160,17,0}, /* core6 fp32 bit41 */
			{22161,17,0}, /* core6 fp32 bit42 */
			{22162,17,0}, /* core6 fp32 bit43 */
			{22199,17,0}, /* core6 fp32 bit44 */
			{22200,17,0}, /* core6 fp32 bit45 */
			{22201,17,0}, /* core6 fp32 bit46 */
			{22202,17,0}, /* core6 fp32 bit47 */
			{22163,17,0}, /* core6 fp32 bit48 */
			{22164,17,0}, /* core6 fp32 bit49 */
			{22165,17,0}, /* core6 fp32 bit50 */
			{22166,17,0}, /* core6 fp32 bit51 */
			{22151,17,0}, /* core6 fp32 bit52 */
			{22152,17,0}, /* core6 fp32 bit53 */
			{22153,17,0}, /* core6 fp32 bit54 */
			{22154,17,0}, /* core6 fp32 bit55 */
			{22167,17,0}, /* core6 fp32 bit56 */
			{22168,17,0}, /* core6 fp32 bit57 */
			{22169,17,0}, /* core6 fp32 bit58 */
			{22170,17,0}, /* core6 fp32 bit59 */
			{22195,17,0}, /* core6 fp32 bit60 */
			{22196,17,0}, /* core6 fp32 bit61 */
			{22197,17,0}, /* core6 fp32 bit62 */
			{22198,17,0}, /* core6 fp32 bit63 */
			}},
			.fp64 = {{
			{16607,17,0}, /* core6 fp64 bit0 */
			{16608,17,0}, /* core6 fp64 bit1 */
			{16609,17,0}, /* core6 fp64 bit2 */
			{16610,17,0}, /* core6 fp64 bit3 */
			{16603,17,0}, /* core6 fp64 bit4 */
			{16604,17,0}, /* core6 fp64 bit5 */
			{16605,17,0}, /* core6 fp64 bit6 */
			{16606,17,0}, /* core6 fp64 bit7 */
			{16571,17,0}, /* core6 fp64 bit8 */
			{16572,17,0}, /* core6 fp64 bit9 */
			{16573,17,0}, /* core6 fp64 bit10 */
			{16574,17,0}, /* core6 fp64 bit11 */
			{23343,21,0}, /* core6 fp64 bit12 */
			{23344,21,0}, /* core6 fp64 bit13 */
			{23345,21,0}, /* core6 fp64 bit14 */
			{23346,21,0}, /* core6 fp64 bit15 */
			{20611,17,0}, /* core6 fp64 bit16 */
			{20612,17,0}, /* core6 fp64 bit17 */
			{20613,17,0}, /* core6 fp64 bit18 */
			{20614,17,0}, /* core6 fp64 bit19 */
			{20619,17,0}, /* core6 fp64 bit20 */
			{20620,17,0}, /* core6 fp64 bit21 */
			{20621,17,0}, /* core6 fp64 bit22 */
			{20622,17,0}, /* core6 fp64 bit23 */
			{20615,17,0}, /* core6 fp64 bit24 */
			{20616,17,0}, /* core6 fp64 bit25 */
			{20617,17,0}, /* core6 fp64 bit26 */
			{20618,17,0}, /* core6 fp64 bit27 */
			{23375,21,0}, /* core6 fp64 bit28 */
			{23376,21,0}, /* core6 fp64 bit29 */
			{23377,21,0}, /* core6 fp64 bit30 */
			{23378,21,0}, /* core6 fp64 bit31 */
			{19087,17,0}, /* core6 fp64 bit32 */
			{19088,17,0}, /* core6 fp64 bit33 */
			{19089,17,0}, /* core6 fp64 bit34 */
			{19090,17,0}, /* core6 fp64 bit35 */
			{19043,17,0}, /* core6 fp64 bit36 */
			{19044,17,0}, /* core6 fp64 bit37 */
			{19045,17,0}, /* core6 fp64 bit38 */
			{19046,17,0}, /* core6 fp64 bit39 */
			{19079,17,0}, /* core6 fp64 bit40 */
			{19080,17,0}, /* core6 fp64 bit41 */
			{19081,17,0}, /* core6 fp64 bit42 */
			{19082,17,0}, /* core6 fp64 bit43 */
			{19059,17,0}, /* core6 fp64 bit44 */
			{19060,17,0}, /* core6 fp64 bit45 */
			{19061,17,0}, /* core6 fp64 bit46 */
			{19062,17,0}, /* core6 fp64 bit47 */
			{19067,17,0}, /* core6 fp64 bit48 */
			{19068,17,0}, /* core6 fp64 bit49 */
			{19069,17,0}, /* core6 fp64 bit50 */
			{19070,17,0}, /* core6 fp64 bit51 */
			{19055,17,0}, /* core6 fp64 bit52 */
			{19056,17,0}, /* core6 fp64 bit53 */
			{19057,17,0}, /* core6 fp64 bit54 */
			{19058,17,0}, /* core6 fp64 bit55 */
			{19095,17,0}, /* core6 fp64 bit56 */
			{19096,17,0}, /* core6 fp64 bit57 */
			{19097,17,0}, /* core6 fp64 bit58 */
			{19098,17,0}, /* core6 fp64 bit59 */
			{18919,17,0}, /* core6 fp64 bit60 */
			{18920,17,0}, /* core6 fp64 bit61 */
			{18921,17,0}, /* core6 fp64 bit62 */
			{18922,17,0}, /* core6 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{19111,17,0}, /* core6 sp_EL0 bit0 */
			{19112,17,0}, /* core6 sp_EL0 bit1 */
			{19113,17,0}, /* core6 sp_EL0 bit2 */
			{19114,17,0}, /* core6 sp_EL0 bit3 */
			{19119,17,0}, /* core6 sp_EL0 bit4 */
			{19120,17,0}, /* core6 sp_EL0 bit5 */
			{19121,17,0}, /* core6 sp_EL0 bit6 */
			{19122,17,0}, /* core6 sp_EL0 bit7 */
			{23391,21,0}, /* core6 sp_EL0 bit8 */
			{23392,21,0}, /* core6 sp_EL0 bit9 */
			{23393,21,0}, /* core6 sp_EL0 bit10 */
			{23394,21,0}, /* core6 sp_EL0 bit11 */
			{23387,21,0}, /* core6 sp_EL0 bit12 */
			{23388,21,0}, /* core6 sp_EL0 bit13 */
			{23389,21,0}, /* core6 sp_EL0 bit14 */
			{23390,21,0}, /* core6 sp_EL0 bit15 */
			{22071,17,0}, /* core6 sp_EL0 bit16 */
			{22072,17,0}, /* core6 sp_EL0 bit17 */
			{22073,17,0}, /* core6 sp_EL0 bit18 */
			{22074,17,0}, /* core6 sp_EL0 bit19 */
			{16579,17,0}, /* core6 sp_EL0 bit20 */
			{16580,17,0}, /* core6 sp_EL0 bit21 */
			{16581,17,0}, /* core6 sp_EL0 bit22 */
			{16582,17,0}, /* core6 sp_EL0 bit23 */
			{22055,17,0}, /* core6 sp_EL0 bit24 */
			{22056,17,0}, /* core6 sp_EL0 bit25 */
			{22057,17,0}, /* core6 sp_EL0 bit26 */
			{22058,17,0}, /* core6 sp_EL0 bit27 */
			{16595,17,0}, /* core6 sp_EL0 bit28 */
			{16596,17,0}, /* core6 sp_EL0 bit29 */
			{16597,17,0}, /* core6 sp_EL0 bit30 */
			{16598,17,0}, /* core6 sp_EL0 bit31 */
			{21091,17,0}, /* core6 sp_EL0 bit32 */
			{21092,17,0}, /* core6 sp_EL0 bit33 */
			{21093,17,0}, /* core6 sp_EL0 bit34 */
			{21094,17,0}, /* core6 sp_EL0 bit35 */
			{18991,17,0}, /* core6 sp_EL0 bit36 */
			{18992,17,0}, /* core6 sp_EL0 bit37 */
			{18993,17,0}, /* core6 sp_EL0 bit38 */
			{18994,17,0}, /* core6 sp_EL0 bit39 */
			{18987,17,0}, /* core6 sp_EL0 bit40 */
			{18988,17,0}, /* core6 sp_EL0 bit41 */
			{18989,17,0}, /* core6 sp_EL0 bit42 */
			{18990,17,0}, /* core6 sp_EL0 bit43 */
			{18995,17,0}, /* core6 sp_EL0 bit44 */
			{18996,17,0}, /* core6 sp_EL0 bit45 */
			{18997,17,0}, /* core6 sp_EL0 bit46 */
			{18998,17,0}, /* core6 sp_EL0 bit47 */
			{18983,17,0}, /* core6 sp_EL0 bit48 */
			{18984,17,0}, /* core6 sp_EL0 bit49 */
			{18985,17,0}, /* core6 sp_EL0 bit50 */
			{18986,17,0}, /* core6 sp_EL0 bit51 */
			{21047,17,0}, /* core6 sp_EL0 bit52 */
			{21048,17,0}, /* core6 sp_EL0 bit53 */
			{21049,17,0}, /* core6 sp_EL0 bit54 */
			{21050,17,0}, /* core6 sp_EL0 bit55 */
			{21099,17,0}, /* core6 sp_EL0 bit56 */
			{21100,17,0}, /* core6 sp_EL0 bit57 */
			{21101,17,0}, /* core6 sp_EL0 bit58 */
			{21102,17,0}, /* core6 sp_EL0 bit59 */
			{18923,17,0}, /* core6 sp_EL0 bit60 */
			{18924,17,0}, /* core6 sp_EL0 bit61 */
			{18925,17,0}, /* core6 sp_EL0 bit62 */
			{18926,17,0}, /* core6 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{18915,17,0}, /* core6 sp_EL1 bit0 */
			{18916,17,0}, /* core6 sp_EL1 bit1 */
			{18917,17,0}, /* core6 sp_EL1 bit2 */
			{18918,17,0}, /* core6 sp_EL1 bit3 */
			{16623,17,0}, /* core6 sp_EL1 bit4 */
			{16624,17,0}, /* core6 sp_EL1 bit5 */
			{16625,17,0}, /* core6 sp_EL1 bit6 */
			{16626,17,0}, /* core6 sp_EL1 bit7 */
			{23395,21,0}, /* core6 sp_EL1 bit8 */
			{23396,21,0}, /* core6 sp_EL1 bit9 */
			{23397,21,0}, /* core6 sp_EL1 bit10 */
			{23398,21,0}, /* core6 sp_EL1 bit11 */
			{23347,21,0}, /* core6 sp_EL1 bit12 */
			{23348,21,0}, /* core6 sp_EL1 bit13 */
			{23349,21,0}, /* core6 sp_EL1 bit14 */
			{23350,21,0}, /* core6 sp_EL1 bit15 */
			{20623,17,0}, /* core6 sp_EL1 bit16 */
			{20624,17,0}, /* core6 sp_EL1 bit17 */
			{20625,17,0}, /* core6 sp_EL1 bit18 */
			{20626,17,0}, /* core6 sp_EL1 bit19 */
			{20631,17,0}, /* core6 sp_EL1 bit20 */
			{20632,17,0}, /* core6 sp_EL1 bit21 */
			{20633,17,0}, /* core6 sp_EL1 bit22 */
			{20634,17,0}, /* core6 sp_EL1 bit23 */
			{20627,17,0}, /* core6 sp_EL1 bit24 */
			{20628,17,0}, /* core6 sp_EL1 bit25 */
			{20629,17,0}, /* core6 sp_EL1 bit26 */
			{20630,17,0}, /* core6 sp_EL1 bit27 */
			{23379,21,0}, /* core6 sp_EL1 bit28 */
			{23380,21,0}, /* core6 sp_EL1 bit29 */
			{23381,21,0}, /* core6 sp_EL1 bit30 */
			{23382,21,0}, /* core6 sp_EL1 bit31 */
			{19091,17,0}, /* core6 sp_EL1 bit32 */
			{19092,17,0}, /* core6 sp_EL1 bit33 */
			{19093,17,0}, /* core6 sp_EL1 bit34 */
			{19094,17,0}, /* core6 sp_EL1 bit35 */
			{18975,17,0}, /* core6 sp_EL1 bit36 */
			{18976,17,0}, /* core6 sp_EL1 bit37 */
			{18977,17,0}, /* core6 sp_EL1 bit38 */
			{18978,17,0}, /* core6 sp_EL1 bit39 */
			{19083,17,0}, /* core6 sp_EL1 bit40 */
			{19084,17,0}, /* core6 sp_EL1 bit41 */
			{19085,17,0}, /* core6 sp_EL1 bit42 */
			{19086,17,0}, /* core6 sp_EL1 bit43 */
			{19063,17,0}, /* core6 sp_EL1 bit44 */
			{19064,17,0}, /* core6 sp_EL1 bit45 */
			{19065,17,0}, /* core6 sp_EL1 bit46 */
			{19066,17,0}, /* core6 sp_EL1 bit47 */
			{19071,17,0}, /* core6 sp_EL1 bit48 */
			{19072,17,0}, /* core6 sp_EL1 bit49 */
			{19073,17,0}, /* core6 sp_EL1 bit50 */
			{19074,17,0}, /* core6 sp_EL1 bit51 */
			{19075,17,0}, /* core6 sp_EL1 bit52 */
			{19076,17,0}, /* core6 sp_EL1 bit53 */
			{19077,17,0}, /* core6 sp_EL1 bit54 */
			{19078,17,0}, /* core6 sp_EL1 bit55 */
			{21107,17,0}, /* core6 sp_EL1 bit56 */
			{21108,17,0}, /* core6 sp_EL1 bit57 */
			{21109,17,0}, /* core6 sp_EL1 bit58 */
			{21110,17,0}, /* core6 sp_EL1 bit59 */
			{21111,17,0}, /* core6 sp_EL1 bit60 */
			{21112,17,0}, /* core6 sp_EL1 bit61 */
			{21113,17,0}, /* core6 sp_EL1 bit62 */
			{21114,17,0}, /* core6 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{18855,17,0}, /* core6 sp_EL2 bit0 */
			{18856,17,0}, /* core6 sp_EL2 bit1 */
			{18857,17,0}, /* core6 sp_EL2 bit2 */
			{18858,17,0}, /* core6 sp_EL2 bit3 */
			{18867,17,0}, /* core6 sp_EL2 bit4 */
			{18868,17,0}, /* core6 sp_EL2 bit5 */
			{18869,17,0}, /* core6 sp_EL2 bit6 */
			{18870,17,0}, /* core6 sp_EL2 bit7 */
			{22099,17,0}, /* core6 sp_EL2 bit8 */
			{22100,17,0}, /* core6 sp_EL2 bit9 */
			{22101,17,0}, /* core6 sp_EL2 bit10 */
			{22102,17,0}, /* core6 sp_EL2 bit11 */
			{22031,17,0}, /* core6 sp_EL2 bit12 */
			{22032,17,0}, /* core6 sp_EL2 bit13 */
			{22033,17,0}, /* core6 sp_EL2 bit14 */
			{22034,17,0}, /* core6 sp_EL2 bit15 */
			{22063,17,0}, /* core6 sp_EL2 bit16 */
			{22064,17,0}, /* core6 sp_EL2 bit17 */
			{22065,17,0}, /* core6 sp_EL2 bit18 */
			{22066,17,0}, /* core6 sp_EL2 bit19 */
			{23111,17,0}, /* core6 sp_EL2 bit20 */
			{23112,17,0}, /* core6 sp_EL2 bit21 */
			{23113,17,0}, /* core6 sp_EL2 bit22 */
			{23114,17,0}, /* core6 sp_EL2 bit23 */
			{22059,17,0}, /* core6 sp_EL2 bit24 */
			{22060,17,0}, /* core6 sp_EL2 bit25 */
			{22061,17,0}, /* core6 sp_EL2 bit26 */
			{22062,17,0}, /* core6 sp_EL2 bit27 */
			{18875,17,0}, /* core6 sp_EL2 bit28 */
			{18876,17,0}, /* core6 sp_EL2 bit29 */
			{18877,17,0}, /* core6 sp_EL2 bit30 */
			{18878,17,0}, /* core6 sp_EL2 bit31 */
			{18955,17,0}, /* core6 sp_EL2 bit32 */
			{18956,17,0}, /* core6 sp_EL2 bit33 */
			{18957,17,0}, /* core6 sp_EL2 bit34 */
			{18958,17,0}, /* core6 sp_EL2 bit35 */
			{21059,17,0}, /* core6 sp_EL2 bit36 */
			{21060,17,0}, /* core6 sp_EL2 bit37 */
			{21061,17,0}, /* core6 sp_EL2 bit38 */
			{21062,17,0}, /* core6 sp_EL2 bit39 */
			{21075,17,0}, /* core6 sp_EL2 bit40 */
			{21076,17,0}, /* core6 sp_EL2 bit41 */
			{21077,17,0}, /* core6 sp_EL2 bit42 */
			{21078,17,0}, /* core6 sp_EL2 bit43 */
			{21063,17,0}, /* core6 sp_EL2 bit44 */
			{21064,17,0}, /* core6 sp_EL2 bit45 */
			{21065,17,0}, /* core6 sp_EL2 bit46 */
			{21066,17,0}, /* core6 sp_EL2 bit47 */
			{21079,17,0}, /* core6 sp_EL2 bit48 */
			{21080,17,0}, /* core6 sp_EL2 bit49 */
			{21081,17,0}, /* core6 sp_EL2 bit50 */
			{21082,17,0}, /* core6 sp_EL2 bit51 */
			{21067,17,0}, /* core6 sp_EL2 bit52 */
			{21068,17,0}, /* core6 sp_EL2 bit53 */
			{21069,17,0}, /* core6 sp_EL2 bit54 */
			{21070,17,0}, /* core6 sp_EL2 bit55 */
			{18951,17,0}, /* core6 sp_EL2 bit56 */
			{18952,17,0}, /* core6 sp_EL2 bit57 */
			{18953,17,0}, /* core6 sp_EL2 bit58 */
			{18954,17,0}, /* core6 sp_EL2 bit59 */
			{18939,17,0}, /* core6 sp_EL2 bit60 */
			{18940,17,0}, /* core6 sp_EL2 bit61 */
			{18941,17,0}, /* core6 sp_EL2 bit62 */
			{18942,17,0}, /* core6 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{18847,17,0}, /* core6 sp_EL3 bit0 */
			{18848,17,0}, /* core6 sp_EL3 bit1 */
			{18849,17,0}, /* core6 sp_EL3 bit2 */
			{18850,17,0}, /* core6 sp_EL3 bit3 */
			{19127,17,0}, /* core6 sp_EL3 bit4 */
			{19128,17,0}, /* core6 sp_EL3 bit5 */
			{19129,17,0}, /* core6 sp_EL3 bit6 */
			{19130,17,0}, /* core6 sp_EL3 bit7 */
			{16587,17,0}, /* core6 sp_EL3 bit8 */
			{16588,17,0}, /* core6 sp_EL3 bit9 */
			{16589,17,0}, /* core6 sp_EL3 bit10 */
			{16590,17,0}, /* core6 sp_EL3 bit11 */
			{19139,17,0}, /* core6 sp_EL3 bit12 */
			{19140,17,0}, /* core6 sp_EL3 bit13 */
			{19141,17,0}, /* core6 sp_EL3 bit14 */
			{19142,17,0}, /* core6 sp_EL3 bit15 */
			{22095,17,0}, /* core6 sp_EL3 bit16 */
			{22096,17,0}, /* core6 sp_EL3 bit17 */
			{22097,17,0}, /* core6 sp_EL3 bit18 */
			{22098,17,0}, /* core6 sp_EL3 bit19 */
			{22039,17,0}, /* core6 sp_EL3 bit20 */
			{22040,17,0}, /* core6 sp_EL3 bit21 */
			{22041,17,0}, /* core6 sp_EL3 bit22 */
			{22042,17,0}, /* core6 sp_EL3 bit23 */
			{16583,17,0}, /* core6 sp_EL3 bit24 */
			{16584,17,0}, /* core6 sp_EL3 bit25 */
			{16585,17,0}, /* core6 sp_EL3 bit26 */
			{16586,17,0}, /* core6 sp_EL3 bit27 */
			{16591,17,0}, /* core6 sp_EL3 bit28 */
			{16592,17,0}, /* core6 sp_EL3 bit29 */
			{16593,17,0}, /* core6 sp_EL3 bit30 */
			{16594,17,0}, /* core6 sp_EL3 bit31 */
			{18959,17,0}, /* core6 sp_EL3 bit32 */
			{18960,17,0}, /* core6 sp_EL3 bit33 */
			{18961,17,0}, /* core6 sp_EL3 bit34 */
			{18962,17,0}, /* core6 sp_EL3 bit35 */
			{20971,17,0}, /* core6 sp_EL3 bit36 */
			{20972,17,0}, /* core6 sp_EL3 bit37 */
			{20973,17,0}, /* core6 sp_EL3 bit38 */
			{20974,17,0}, /* core6 sp_EL3 bit39 */
			{18963,17,0}, /* core6 sp_EL3 bit40 */
			{18964,17,0}, /* core6 sp_EL3 bit41 */
			{18965,17,0}, /* core6 sp_EL3 bit42 */
			{18966,17,0}, /* core6 sp_EL3 bit43 */
			{20975,17,0}, /* core6 sp_EL3 bit44 */
			{20976,17,0}, /* core6 sp_EL3 bit45 */
			{20977,17,0}, /* core6 sp_EL3 bit46 */
			{20978,17,0}, /* core6 sp_EL3 bit47 */
			{21071,17,0}, /* core6 sp_EL3 bit48 */
			{21072,17,0}, /* core6 sp_EL3 bit49 */
			{21073,17,0}, /* core6 sp_EL3 bit50 */
			{21074,17,0}, /* core6 sp_EL3 bit51 */
			{20979,17,0}, /* core6 sp_EL3 bit52 */
			{20980,17,0}, /* core6 sp_EL3 bit53 */
			{20981,17,0}, /* core6 sp_EL3 bit54 */
			{20982,17,0}, /* core6 sp_EL3 bit55 */
			{18947,17,0}, /* core6 sp_EL3 bit56 */
			{18948,17,0}, /* core6 sp_EL3 bit57 */
			{18949,17,0}, /* core6 sp_EL3 bit58 */
			{18950,17,0}, /* core6 sp_EL3 bit59 */
			{18935,17,0}, /* core6 sp_EL3 bit60 */
			{18936,17,0}, /* core6 sp_EL3 bit61 */
			{18937,17,0}, /* core6 sp_EL3 bit62 */
			{18938,17,0}, /* core6 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{18851,17,0}, /* core6 elr_EL1 bit0 */
			{18852,17,0}, /* core6 elr_EL1 bit1 */
			{18853,17,0}, /* core6 elr_EL1 bit2 */
			{18854,17,0}, /* core6 elr_EL1 bit3 */
			{18871,17,0}, /* core6 elr_EL1 bit4 */
			{18872,17,0}, /* core6 elr_EL1 bit5 */
			{18873,17,0}, /* core6 elr_EL1 bit6 */
			{18874,17,0}, /* core6 elr_EL1 bit7 */
			{22091,17,0}, /* core6 elr_EL1 bit8 */
			{22092,17,0}, /* core6 elr_EL1 bit9 */
			{22093,17,0}, /* core6 elr_EL1 bit10 */
			{22094,17,0}, /* core6 elr_EL1 bit11 */
			{19143,17,0}, /* core6 elr_EL1 bit12 */
			{19144,17,0}, /* core6 elr_EL1 bit13 */
			{19145,17,0}, /* core6 elr_EL1 bit14 */
			{19146,17,0}, /* core6 elr_EL1 bit15 */
			{22083,17,0}, /* core6 elr_EL1 bit16 */
			{22084,17,0}, /* core6 elr_EL1 bit17 */
			{22085,17,0}, /* core6 elr_EL1 bit18 */
			{22086,17,0}, /* core6 elr_EL1 bit19 */
			{22079,17,0}, /* core6 elr_EL1 bit20 */
			{22080,17,0}, /* core6 elr_EL1 bit21 */
			{22081,17,0}, /* core6 elr_EL1 bit22 */
			{22082,17,0}, /* core6 elr_EL1 bit23 */
			{22075,17,0}, /* core6 elr_EL1 bit24 */
			{22076,17,0}, /* core6 elr_EL1 bit25 */
			{22077,17,0}, /* core6 elr_EL1 bit26 */
			{22078,17,0}, /* core6 elr_EL1 bit27 */
			{18911,17,0}, /* core6 elr_EL1 bit28 */
			{18912,17,0}, /* core6 elr_EL1 bit29 */
			{18913,17,0}, /* core6 elr_EL1 bit30 */
			{18914,17,0}, /* core6 elr_EL1 bit31 */
			{21095,17,0}, /* core6 elr_EL1 bit32 */
			{21096,17,0}, /* core6 elr_EL1 bit33 */
			{21097,17,0}, /* core6 elr_EL1 bit34 */
			{21098,17,0}, /* core6 elr_EL1 bit35 */
			{21055,17,0}, /* core6 elr_EL1 bit36 */
			{21056,17,0}, /* core6 elr_EL1 bit37 */
			{21057,17,0}, /* core6 elr_EL1 bit38 */
			{21058,17,0}, /* core6 elr_EL1 bit39 */
			{21083,17,0}, /* core6 elr_EL1 bit40 */
			{21084,17,0}, /* core6 elr_EL1 bit41 */
			{21085,17,0}, /* core6 elr_EL1 bit42 */
			{21086,17,0}, /* core6 elr_EL1 bit43 */
			{18971,17,0}, /* core6 elr_EL1 bit44 */
			{18972,17,0}, /* core6 elr_EL1 bit45 */
			{18973,17,0}, /* core6 elr_EL1 bit46 */
			{18974,17,0}, /* core6 elr_EL1 bit47 */
			{18967,17,0}, /* core6 elr_EL1 bit48 */
			{18968,17,0}, /* core6 elr_EL1 bit49 */
			{18969,17,0}, /* core6 elr_EL1 bit50 */
			{18970,17,0}, /* core6 elr_EL1 bit51 */
			{21051,17,0}, /* core6 elr_EL1 bit52 */
			{21052,17,0}, /* core6 elr_EL1 bit53 */
			{21053,17,0}, /* core6 elr_EL1 bit54 */
			{21054,17,0}, /* core6 elr_EL1 bit55 */
			{21103,17,0}, /* core6 elr_EL1 bit56 */
			{21104,17,0}, /* core6 elr_EL1 bit57 */
			{21105,17,0}, /* core6 elr_EL1 bit58 */
			{21106,17,0}, /* core6 elr_EL1 bit59 */
			{18927,17,0}, /* core6 elr_EL1 bit60 */
			{18928,17,0}, /* core6 elr_EL1 bit61 */
			{18929,17,0}, /* core6 elr_EL1 bit62 */
			{18930,17,0}, /* core6 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{19103,17,0}, /* core6 elr_EL2 bit0 */
			{19104,17,0}, /* core6 elr_EL2 bit1 */
			{19105,17,0}, /* core6 elr_EL2 bit2 */
			{19106,17,0}, /* core6 elr_EL2 bit3 */
			{19115,17,0}, /* core6 elr_EL2 bit4 */
			{19116,17,0}, /* core6 elr_EL2 bit5 */
			{19117,17,0}, /* core6 elr_EL2 bit6 */
			{19118,17,0}, /* core6 elr_EL2 bit7 */
			{23339,21,0}, /* core6 elr_EL2 bit8 */
			{23340,21,0}, /* core6 elr_EL2 bit9 */
			{23341,21,0}, /* core6 elr_EL2 bit10 */
			{23342,21,0}, /* core6 elr_EL2 bit11 */
			{23383,21,0}, /* core6 elr_EL2 bit12 */
			{23384,21,0}, /* core6 elr_EL2 bit13 */
			{23385,21,0}, /* core6 elr_EL2 bit14 */
			{23386,21,0}, /* core6 elr_EL2 bit15 */
			{22087,17,0}, /* core6 elr_EL2 bit16 */
			{22088,17,0}, /* core6 elr_EL2 bit17 */
			{22089,17,0}, /* core6 elr_EL2 bit18 */
			{22090,17,0}, /* core6 elr_EL2 bit19 */
			{23331,21,0}, /* core6 elr_EL2 bit20 */
			{23332,21,0}, /* core6 elr_EL2 bit21 */
			{23333,21,0}, /* core6 elr_EL2 bit22 */
			{23334,21,0}, /* core6 elr_EL2 bit23 */
			{23335,21,0}, /* core6 elr_EL2 bit24 */
			{23336,21,0}, /* core6 elr_EL2 bit25 */
			{23337,21,0}, /* core6 elr_EL2 bit26 */
			{23338,21,0}, /* core6 elr_EL2 bit27 */
			{16599,17,0}, /* core6 elr_EL2 bit28 */
			{16600,17,0}, /* core6 elr_EL2 bit29 */
			{16601,17,0}, /* core6 elr_EL2 bit30 */
			{16602,17,0}, /* core6 elr_EL2 bit31 */
			{18779,17,0}, /* core6 elr_EL2 bit32 */
			{18780,17,0}, /* core6 elr_EL2 bit33 */
			{18781,17,0}, /* core6 elr_EL2 bit34 */
			{18782,17,0}, /* core6 elr_EL2 bit35 */
			{18739,17,0}, /* core6 elr_EL2 bit36 */
			{18740,17,0}, /* core6 elr_EL2 bit37 */
			{18741,17,0}, /* core6 elr_EL2 bit38 */
			{18742,17,0}, /* core6 elr_EL2 bit39 */
			{18759,17,0}, /* core6 elr_EL2 bit40 */
			{18760,17,0}, /* core6 elr_EL2 bit41 */
			{18761,17,0}, /* core6 elr_EL2 bit42 */
			{18762,17,0}, /* core6 elr_EL2 bit43 */
			{18735,17,0}, /* core6 elr_EL2 bit44 */
			{18736,17,0}, /* core6 elr_EL2 bit45 */
			{18737,17,0}, /* core6 elr_EL2 bit46 */
			{18738,17,0}, /* core6 elr_EL2 bit47 */
			{18747,17,0}, /* core6 elr_EL2 bit48 */
			{18748,17,0}, /* core6 elr_EL2 bit49 */
			{18749,17,0}, /* core6 elr_EL2 bit50 */
			{18750,17,0}, /* core6 elr_EL2 bit51 */
			{18743,17,0}, /* core6 elr_EL2 bit52 */
			{18744,17,0}, /* core6 elr_EL2 bit53 */
			{18745,17,0}, /* core6 elr_EL2 bit54 */
			{18746,17,0}, /* core6 elr_EL2 bit55 */
			{18783,17,0}, /* core6 elr_EL2 bit56 */
			{18784,17,0}, /* core6 elr_EL2 bit57 */
			{18785,17,0}, /* core6 elr_EL2 bit58 */
			{18786,17,0}, /* core6 elr_EL2 bit59 */
			{18807,17,0}, /* core6 elr_EL2 bit60 */
			{18808,17,0}, /* core6 elr_EL2 bit61 */
			{18809,17,0}, /* core6 elr_EL2 bit62 */
			{18810,17,0}, /* core6 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{21975,17,0}, /* core6 elr_EL3 bit0 */
			{21976,17,0}, /* core6 elr_EL3 bit1 */
			{21977,17,0}, /* core6 elr_EL3 bit2 */
			{21978,17,0}, /* core6 elr_EL3 bit3 */
			{21983,17,0}, /* core6 elr_EL3 bit4 */
			{21984,17,0}, /* core6 elr_EL3 bit5 */
			{21985,17,0}, /* core6 elr_EL3 bit6 */
			{21986,17,0}, /* core6 elr_EL3 bit7 */
			{21615,17,0}, /* core6 elr_EL3 bit8 */
			{21616,17,0}, /* core6 elr_EL3 bit9 */
			{21617,17,0}, /* core6 elr_EL3 bit10 */
			{21618,17,0}, /* core6 elr_EL3 bit11 */
			{21587,17,0}, /* core6 elr_EL3 bit12 */
			{21588,17,0}, /* core6 elr_EL3 bit13 */
			{21589,17,0}, /* core6 elr_EL3 bit14 */
			{21590,17,0}, /* core6 elr_EL3 bit15 */
			{21379,17,0}, /* core6 elr_EL3 bit16 */
			{21380,17,0}, /* core6 elr_EL3 bit17 */
			{21381,17,0}, /* core6 elr_EL3 bit18 */
			{21382,17,0}, /* core6 elr_EL3 bit19 */
			{21623,17,0}, /* core6 elr_EL3 bit20 */
			{21624,17,0}, /* core6 elr_EL3 bit21 */
			{21625,17,0}, /* core6 elr_EL3 bit22 */
			{21626,17,0}, /* core6 elr_EL3 bit23 */
			{21627,17,0}, /* core6 elr_EL3 bit24 */
			{21628,17,0}, /* core6 elr_EL3 bit25 */
			{21629,17,0}, /* core6 elr_EL3 bit26 */
			{21630,17,0}, /* core6 elr_EL3 bit27 */
			{22003,17,0}, /* core6 elr_EL3 bit28 */
			{22004,17,0}, /* core6 elr_EL3 bit29 */
			{22005,17,0}, /* core6 elr_EL3 bit30 */
			{22006,17,0}, /* core6 elr_EL3 bit31 */
			{21559,17,0}, /* core6 elr_EL3 bit32 */
			{21560,17,0}, /* core6 elr_EL3 bit33 */
			{21561,17,0}, /* core6 elr_EL3 bit34 */
			{21562,17,0}, /* core6 elr_EL3 bit35 */
			{21531,17,0}, /* core6 elr_EL3 bit36 */
			{21532,17,0}, /* core6 elr_EL3 bit37 */
			{21533,17,0}, /* core6 elr_EL3 bit38 */
			{21534,17,0}, /* core6 elr_EL3 bit39 */
			{21555,17,0}, /* core6 elr_EL3 bit40 */
			{21556,17,0}, /* core6 elr_EL3 bit41 */
			{21557,17,0}, /* core6 elr_EL3 bit42 */
			{21558,17,0}, /* core6 elr_EL3 bit43 */
			{21535,17,0}, /* core6 elr_EL3 bit44 */
			{21536,17,0}, /* core6 elr_EL3 bit45 */
			{21537,17,0}, /* core6 elr_EL3 bit46 */
			{21538,17,0}, /* core6 elr_EL3 bit47 */
			{21539,17,0}, /* core6 elr_EL3 bit48 */
			{21540,17,0}, /* core6 elr_EL3 bit49 */
			{21541,17,0}, /* core6 elr_EL3 bit50 */
			{21542,17,0}, /* core6 elr_EL3 bit51 */
			{21515,17,0}, /* core6 elr_EL3 bit52 */
			{21516,17,0}, /* core6 elr_EL3 bit53 */
			{21517,17,0}, /* core6 elr_EL3 bit54 */
			{21518,17,0}, /* core6 elr_EL3 bit55 */
			{21567,17,0}, /* core6 elr_EL3 bit56 */
			{21568,17,0}, /* core6 elr_EL3 bit57 */
			{21569,17,0}, /* core6 elr_EL3 bit58 */
			{21570,17,0}, /* core6 elr_EL3 bit59 */
			{21571,17,0}, /* core6 elr_EL3 bit60 */
			{21572,17,0}, /* core6 elr_EL3 bit61 */
			{21573,17,0}, /* core6 elr_EL3 bit62 */
			{21574,17,0}, /* core6 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{14284,17,0}, /* core6 raw_pc bit0 */
			{19559,17,0}, /* core6 raw_pc bit1 */
			{19560,17,0}, /* core6 raw_pc bit2 */
			{20547,17,0}, /* core6 raw_pc bit3 */
			{20548,17,0}, /* core6 raw_pc bit4 */
			{20549,17,0}, /* core6 raw_pc bit5 */
			{20550,17,0}, /* core6 raw_pc bit6 */
			{18323,17,0}, /* core6 raw_pc bit7 */
			{18324,17,0}, /* core6 raw_pc bit8 */
			{18325,17,0}, /* core6 raw_pc bit9 */
			{18326,17,0}, /* core6 raw_pc bit10 */
			{18335,17,0}, /* core6 raw_pc bit11 */
			{18336,17,0}, /* core6 raw_pc bit12 */
			{18337,17,0}, /* core6 raw_pc bit13 */
			{18338,17,0}, /* core6 raw_pc bit14 */
			{18339,17,0}, /* core6 raw_pc bit15 */
			{18340,17,0}, /* core6 raw_pc bit16 */
			{18341,17,0}, /* core6 raw_pc bit17 */
			{18342,17,0}, /* core6 raw_pc bit18 */
			{18355,17,0}, /* core6 raw_pc bit19 */
			{18356,17,0}, /* core6 raw_pc bit20 */
			{18357,17,0}, /* core6 raw_pc bit21 */
			{18358,17,0}, /* core6 raw_pc bit22 */
			{18343,17,0}, /* core6 raw_pc bit23 */
			{18344,17,0}, /* core6 raw_pc bit24 */
			{18345,17,0}, /* core6 raw_pc bit25 */
			{18346,17,0}, /* core6 raw_pc bit26 */
			{18347,17,0}, /* core6 raw_pc bit27 */
			{18348,17,0}, /* core6 raw_pc bit28 */
			{18349,17,0}, /* core6 raw_pc bit29 */
			{18350,17,0}, /* core6 raw_pc bit30 */
			{15884,17,0}, /* core6 raw_pc bit31 */
			{17631,17,0}, /* core6 raw_pc bit32 */
			{17632,17,0}, /* core6 raw_pc bit33 */
			{17633,17,0}, /* core6 raw_pc bit34 */
			{17634,17,0}, /* core6 raw_pc bit35 */
			{18155,17,0}, /* core6 raw_pc bit36 */
			{18156,17,0}, /* core6 raw_pc bit37 */
			{18157,17,0}, /* core6 raw_pc bit38 */
			{18158,17,0}, /* core6 raw_pc bit39 */
			{17915,17,0}, /* core6 raw_pc bit40 */
			{17916,17,0}, /* core6 raw_pc bit41 */
			{17917,17,0}, /* core6 raw_pc bit42 */
			{17918,17,0}, /* core6 raw_pc bit43 */
			{17639,17,0}, /* core6 raw_pc bit44 */
			{17640,17,0}, /* core6 raw_pc bit45 */
			{17641,17,0}, /* core6 raw_pc bit46 */
			{17642,17,0}, /* core6 raw_pc bit47 */
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
			{14217,17,0}, /* core6 pc_iss bit0 */
			{14277,17,0}, /* core6 pc_iss bit1 */
			{14278,17,0}, /* core6 pc_iss bit2 */
			{14291,17,0}, /* core6 pc_iss bit3 */
			{14280,17,0}, /* core6 pc_iss bit4 */
			{14216,17,0}, /* core6 pc_iss bit5 */
			{14215,17,0}, /* core6 pc_iss bit6 */
			{14214,17,0}, /* core6 pc_iss bit7 */
			{19229,21,0}, /* core6 pc_iss bit8 */
			{19228,21,0}, /* core6 pc_iss bit9 */
			{14294,17,0}, /* core6 pc_iss bit10 */
			{14295,17,0}, /* core6 pc_iss bit11 */
			{19221,21,0}, /* core6 pc_iss bit12 */
			{19220,21,0}, /* core6 pc_iss bit13 */
			{19227,21,0}, /* core6 pc_iss bit14 */
			{17902,17,0}, /* core6 pc_iss bit15 */
			{17901,17,0}, /* core6 pc_iss bit16 */
			{17890,17,0}, /* core6 pc_iss bit17 */
			{17889,17,0}, /* core6 pc_iss bit18 */
			{17900,17,0}, /* core6 pc_iss bit19 */
			{17899,17,0}, /* core6 pc_iss bit20 */
			{19225,21,0}, /* core6 pc_iss bit21 */
			{19226,21,0}, /* core6 pc_iss bit22 */
			{19257,21,0}, /* core6 pc_iss bit23 */
			{19224,21,0}, /* core6 pc_iss bit24 */
			{19223,21,0}, /* core6 pc_iss bit25 */
			{19222,21,0}, /* core6 pc_iss bit26 */
			{19259,21,0}, /* core6 pc_iss bit27 */
			{19258,21,0}, /* core6 pc_iss bit28 */
			{14297,17,0}, /* core6 pc_iss bit29 */
			{19256,21,0}, /* core6 pc_iss bit30 */
			{14296,17,0}, /* core6 pc_iss bit31 */
			{17627,17,0}, /* core6 pc_iss bit32 */
			{17628,17,0}, /* core6 pc_iss bit33 */
			{17629,17,0}, /* core6 pc_iss bit34 */
			{17630,17,0}, /* core6 pc_iss bit35 */
			{17615,17,0}, /* core6 pc_iss bit36 */
			{17616,17,0}, /* core6 pc_iss bit37 */
			{17617,17,0}, /* core6 pc_iss bit38 */
			{17618,17,0}, /* core6 pc_iss bit39 */
			{17623,17,0}, /* core6 pc_iss bit40 */
			{17624,17,0}, /* core6 pc_iss bit41 */
			{17625,17,0}, /* core6 pc_iss bit42 */
			{17626,17,0}, /* core6 pc_iss bit43 */
			{17619,17,0}, /* core6 pc_iss bit44 */
			{17620,17,0}, /* core6 pc_iss bit45 */
			{17621,17,0}, /* core6 pc_iss bit46 */
			{17622,17,0}, /* core6 pc_iss bit47 */
			{17183,17,0}, /* core6 pc_iss bit48 */
			{17184,17,0}, /* core6 pc_iss bit49 */
			{17185,17,0}, /* core6 pc_iss bit50 */
			{17186,17,0}, /* core6 pc_iss bit51 */
			{17187,17,0}, /* core6 pc_iss bit52 */
			{17188,17,0}, /* core6 pc_iss bit53 */
			{17189,17,0}, /* core6 pc_iss bit54 */
			{17190,17,0}, /* core6 pc_iss bit55 */
			{17179,17,0}, /* core6 pc_iss bit56 */
			{17180,17,0}, /* core6 pc_iss bit57 */
			{17181,17,0}, /* core6 pc_iss bit58 */
			{17182,17,0}, /* core6 pc_iss bit59 */
			{17191,17,0}, /* core6 pc_iss bit60 */
			{17192,17,0}, /* core6 pc_iss bit61 */
			{17193,17,0}, /* core6 pc_iss bit62 */
			{17194,17,0}, /* core6 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{19562,17,0}, /* core6 full_pc_wr bit0 */
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
			{24026,21,0}, /* core6 full_pc_ex1 bit0 */
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
			{23798,21,0}, /* core6 full_pc_ex2 bit0 */
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
			{20578,18,0}, /* core7 pc bit0 */
			{20577,18,0}, /* core7 pc bit1 */
			{20536,18,0}, /* core7 pc bit2 */
			{20535,18,0}, /* core7 pc bit3 */
			{20585,18,0}, /* core7 pc bit4 */
			{20534,18,0}, /* core7 pc bit5 */
			{20533,18,0}, /* core7 pc bit6 */
			{20442,18,0}, /* core7 pc bit7 */
			{20441,18,0}, /* core7 pc bit8 */
			{20528,18,0}, /* core7 pc bit9 */
			{20440,18,0}, /* core7 pc bit10 */
			{20439,18,0}, /* core7 pc bit11 */
			{20527,18,0}, /* core7 pc bit12 */
			{20532,18,0}, /* core7 pc bit13 */
			{20571,18,0}, /* core7 pc bit14 */
			{20570,18,0}, /* core7 pc bit15 */
			{20526,18,0}, /* core7 pc bit16 */
			{20531,18,0}, /* core7 pc bit17 */
			{20569,18,0}, /* core7 pc bit18 */
			{20530,18,0}, /* core7 pc bit19 */
			{20540,18,0}, /* core7 pc bit20 */
			{20539,18,0}, /* core7 pc bit21 */
			{20525,18,0}, /* core7 pc bit22 */
			{20529,18,0}, /* core7 pc bit23 */
			{20576,18,0}, /* core7 pc bit24 */
			{20446,18,0}, /* core7 pc bit25 */
			{20445,18,0}, /* core7 pc bit26 */
			{20444,18,0}, /* core7 pc bit27 */
			{20575,18,0}, /* core7 pc bit28 */
			{20574,18,0}, /* core7 pc bit29 */
			{20573,18,0}, /* core7 pc bit30 */
			{20443,18,0}, /* core7 pc bit31 */
			{20450,18,0}, /* core7 pc bit32 */
			{20449,18,0}, /* core7 pc bit33 */
			{20448,18,0}, /* core7 pc bit34 */
			{20447,18,0}, /* core7 pc bit35 */
			{20512,18,0}, /* core7 pc bit36 */
			{20511,18,0}, /* core7 pc bit37 */
			{20510,18,0}, /* core7 pc bit38 */
			{20509,18,0}, /* core7 pc bit39 */
			{20520,18,0}, /* core7 pc bit40 */
			{20519,18,0}, /* core7 pc bit41 */
			{20518,18,0}, /* core7 pc bit42 */
			{20517,18,0}, /* core7 pc bit43 */
			{20454,18,0}, /* core7 pc bit44 */
			{20453,18,0}, /* core7 pc bit45 */
			{20452,18,0}, /* core7 pc bit46 */
			{20451,18,0}, /* core7 pc bit47 */
			{19390,18,0}, /* core7 pc bit48 */
			{19389,18,0}, /* core7 pc bit49 */
			{19392,18,0}, /* core7 pc bit50 */
			{19391,18,0}, /* core7 pc bit51 */
			{20516,18,0}, /* core7 pc bit52 */
			{20515,18,0}, /* core7 pc bit53 */
			{20514,18,0}, /* core7 pc bit54 */
			{20513,18,0}, /* core7 pc bit55 */
			{21420,18,0}, /* core7 pc bit56 */
			{21419,18,0}, /* core7 pc bit57 */
			{21418,18,0}, /* core7 pc bit58 */
			{21417,18,0}, /* core7 pc bit59 */
			{20524,18,0}, /* core7 pc bit60 */
			{20523,18,0}, /* core7 pc bit61 */
			{20522,18,0}, /* core7 pc bit62 */
			{20521,18,0}, /* core7 pc bit63 */
			}},
			.sp32 = {{
			{14843,22,0}, /* core7 sp32 bit0 */
			{14844,22,0}, /* core7 sp32 bit1 */
			{18023,18,0}, /* core7 sp32 bit2 */
			{18022,18,0}, /* core7 sp32 bit3 */
			{14862,22,0}, /* core7 sp32 bit4 */
			{14845,22,0}, /* core7 sp32 bit5 */
			{14899,22,0}, /* core7 sp32 bit6 */
			{14901,22,0}, /* core7 sp32 bit7 */
			{14900,22,0}, /* core7 sp32 bit8 */
			{14848,22,0}, /* core7 sp32 bit9 */
			{14896,22,0}, /* core7 sp32 bit10 */
			{14894,22,0}, /* core7 sp32 bit11 */
			{14846,22,0}, /* core7 sp32 bit12 */
			{14898,22,0}, /* core7 sp32 bit13 */
			{14813,22,0}, /* core7 sp32 bit14 */
			{14861,22,0}, /* core7 sp32 bit15 */
			{14864,22,0}, /* core7 sp32 bit16 */
			{14863,22,0}, /* core7 sp32 bit17 */
			{14812,22,0}, /* core7 sp32 bit18 */
			{14809,22,0}, /* core7 sp32 bit19 */
			{14867,22,0}, /* core7 sp32 bit20 */
			{14849,22,0}, /* core7 sp32 bit21 */
			{14866,22,0}, /* core7 sp32 bit22 */
			{14893,22,0}, /* core7 sp32 bit23 */
			{14897,22,0}, /* core7 sp32 bit24 */
			{14847,22,0}, /* core7 sp32 bit25 */
			{14810,22,0}, /* core7 sp32 bit26 */
			{14811,22,0}, /* core7 sp32 bit27 */
			{14842,22,0}, /* core7 sp32 bit28 */
			{14868,22,0}, /* core7 sp32 bit29 */
			{14865,22,0}, /* core7 sp32 bit30 */
			{14895,22,0}, /* core7 sp32 bit31 */
			{18449,22,0}, /* core7 sp32 bit32 */
			{18450,22,0}, /* core7 sp32 bit33 */
			{18453,22,0}, /* core7 sp32 bit34 */
			{18456,22,0}, /* core7 sp32 bit35 */
			{18455,22,0}, /* core7 sp32 bit36 */
			{18452,22,0}, /* core7 sp32 bit37 */
			{18447,22,0}, /* core7 sp32 bit38 */
			{18451,22,0}, /* core7 sp32 bit39 */
			{18454,22,0}, /* core7 sp32 bit40 */
			{18510,22,0}, /* core7 sp32 bit41 */
			{18511,22,0}, /* core7 sp32 bit42 */
			{18443,22,0}, /* core7 sp32 bit43 */
			{18444,22,0}, /* core7 sp32 bit44 */
			{18661,22,0}, /* core7 sp32 bit45 */
			{18574,22,0}, /* core7 sp32 bit46 */
			{18572,22,0}, /* core7 sp32 bit47 */
			{18619,22,0}, /* core7 sp32 bit48 */
			{18617,22,0}, /* core7 sp32 bit49 */
			{18576,22,0}, /* core7 sp32 bit50 */
			{18622,22,0}, /* core7 sp32 bit51 */
			{18660,22,0}, /* core7 sp32 bit52 */
			{18621,22,0}, /* core7 sp32 bit53 */
			{18623,22,0}, /* core7 sp32 bit54 */
			{18662,22,0}, /* core7 sp32 bit55 */
			{18618,22,0}, /* core7 sp32 bit56 */
			{18573,22,0}, /* core7 sp32 bit57 */
			{18575,22,0}, /* core7 sp32 bit58 */
			{18446,22,0}, /* core7 sp32 bit59 */
			{18445,22,0}, /* core7 sp32 bit60 */
			{18624,22,0}, /* core7 sp32 bit61 */
			{18620,22,0}, /* core7 sp32 bit62 */
			{18457,22,0}, /* core7 sp32 bit63 */
			}},
			.fp32 = {{
			{20121,18,0}, /* core7 fp32 bit0 */
			{17118,22,0}, /* core7 fp32 bit1 */
			{20120,18,0}, /* core7 fp32 bit2 */
			{17120,22,0}, /* core7 fp32 bit3 */
			{17096,22,0}, /* core7 fp32 bit4 */
			{17097,22,0}, /* core7 fp32 bit5 */
			{17119,22,0}, /* core7 fp32 bit6 */
			{17115,22,0}, /* core7 fp32 bit7 */
			{17116,22,0}, /* core7 fp32 bit8 */
			{17114,22,0}, /* core7 fp32 bit9 */
			{20119,18,0}, /* core7 fp32 bit10 */
			{17098,22,0}, /* core7 fp32 bit11 */
			{17117,22,0}, /* core7 fp32 bit12 */
			{20116,18,0}, /* core7 fp32 bit13 */
			{20118,18,0}, /* core7 fp32 bit14 */
			{17049,22,0}, /* core7 fp32 bit15 */
			{15842,22,0}, /* core7 fp32 bit16 */
			{17100,22,0}, /* core7 fp32 bit17 */
			{17099,22,0}, /* core7 fp32 bit18 */
			{17112,22,0}, /* core7 fp32 bit19 */
			{17046,22,0}, /* core7 fp32 bit20 */
			{15843,22,0}, /* core7 fp32 bit21 */
			{17108,22,0}, /* core7 fp32 bit22 */
			{20117,18,0}, /* core7 fp32 bit23 */
			{17101,22,0}, /* core7 fp32 bit24 */
			{17111,22,0}, /* core7 fp32 bit25 */
			{17106,22,0}, /* core7 fp32 bit26 */
			{20115,18,0}, /* core7 fp32 bit27 */
			{17109,22,0}, /* core7 fp32 bit28 */
			{17107,22,0}, /* core7 fp32 bit29 */
			{17110,22,0}, /* core7 fp32 bit30 */
			{17113,22,0}, /* core7 fp32 bit31 */
			{18317,22,0}, /* core7 fp32 bit32 */
			{18319,22,0}, /* core7 fp32 bit33 */
			{18316,22,0}, /* core7 fp32 bit34 */
			{18320,22,0}, /* core7 fp32 bit35 */
			{18315,22,0}, /* core7 fp32 bit36 */
			{18307,22,0}, /* core7 fp32 bit37 */
			{18318,22,0}, /* core7 fp32 bit38 */
			{22544,18,0}, /* core7 fp32 bit39 */
			{22543,18,0}, /* core7 fp32 bit40 */
			{22566,18,0}, /* core7 fp32 bit41 */
			{22241,18,0}, /* core7 fp32 bit42 */
			{22240,18,0}, /* core7 fp32 bit43 */
			{22541,18,0}, /* core7 fp32 bit44 */
			{22568,18,0}, /* core7 fp32 bit45 */
			{22552,18,0}, /* core7 fp32 bit46 */
			{22553,18,0}, /* core7 fp32 bit47 */
			{18310,22,0}, /* core7 fp32 bit48 */
			{22567,18,0}, /* core7 fp32 bit49 */
			{22209,18,0}, /* core7 fp32 bit50 */
			{22208,18,0}, /* core7 fp32 bit51 */
			{22207,18,0}, /* core7 fp32 bit52 */
			{22206,18,0}, /* core7 fp32 bit53 */
			{22542,18,0}, /* core7 fp32 bit54 */
			{22565,18,0}, /* core7 fp32 bit55 */
			{22556,18,0}, /* core7 fp32 bit56 */
			{22560,18,0}, /* core7 fp32 bit57 */
			{22554,18,0}, /* core7 fp32 bit58 */
			{22559,18,0}, /* core7 fp32 bit59 */
			{18309,22,0}, /* core7 fp32 bit60 */
			{22555,18,0}, /* core7 fp32 bit61 */
			{22205,18,0}, /* core7 fp32 bit62 */
			{22204,18,0}, /* core7 fp32 bit63 */
			}},
			.fp64 = {{
			{20600,18,0}, /* core7 fp64 bit0 */
			{20599,18,0}, /* core7 fp64 bit1 */
			{20598,18,0}, /* core7 fp64 bit2 */
			{20597,18,0}, /* core7 fp64 bit3 */
			{20887,18,0}, /* core7 fp64 bit4 */
			{20890,18,0}, /* core7 fp64 bit5 */
			{20928,18,0}, /* core7 fp64 bit6 */
			{19110,18,0}, /* core7 fp64 bit7 */
			{19011,18,0}, /* core7 fp64 bit8 */
			{19032,18,0}, /* core7 fp64 bit9 */
			{20888,18,0}, /* core7 fp64 bit10 */
			{20927,18,0}, /* core7 fp64 bit11 */
			{19109,18,0}, /* core7 fp64 bit12 */
			{19111,18,0}, /* core7 fp64 bit13 */
			{19015,18,0}, /* core7 fp64 bit14 */
			{19114,18,0}, /* core7 fp64 bit15 */
			{20926,18,0}, /* core7 fp64 bit16 */
			{19012,18,0}, /* core7 fp64 bit17 */
			{19118,18,0}, /* core7 fp64 bit18 */
			{19115,18,0}, /* core7 fp64 bit19 */
			{19026,18,0}, /* core7 fp64 bit20 */
			{19017,18,0}, /* core7 fp64 bit21 */
			{19113,18,0}, /* core7 fp64 bit22 */
			{19031,18,0}, /* core7 fp64 bit23 */
			{19027,18,0}, /* core7 fp64 bit24 */
			{19036,18,0}, /* core7 fp64 bit25 */
			{19016,18,0}, /* core7 fp64 bit26 */
			{19116,18,0}, /* core7 fp64 bit27 */
			{19117,18,0}, /* core7 fp64 bit28 */
			{19025,18,0}, /* core7 fp64 bit29 */
			{19112,18,0}, /* core7 fp64 bit30 */
			{19037,18,0}, /* core7 fp64 bit31 */
			{20016,18,0}, /* core7 fp64 bit32 */
			{20027,18,0}, /* core7 fp64 bit33 */
			{20026,18,0}, /* core7 fp64 bit34 */
			{20013,18,0}, /* core7 fp64 bit35 */
			{20023,18,0}, /* core7 fp64 bit36 */
			{20014,18,0}, /* core7 fp64 bit37 */
			{20017,18,0}, /* core7 fp64 bit38 */
			{20020,18,0}, /* core7 fp64 bit39 */
			{20021,18,0}, /* core7 fp64 bit40 */
			{20018,18,0}, /* core7 fp64 bit41 */
			{20022,18,0}, /* core7 fp64 bit42 */
			{20024,18,0}, /* core7 fp64 bit43 */
			{20028,18,0}, /* core7 fp64 bit44 */
			{20025,18,0}, /* core7 fp64 bit45 */
			{17292,22,0}, /* core7 fp64 bit46 */
			{17184,22,0}, /* core7 fp64 bit47 */
			{17185,22,0}, /* core7 fp64 bit48 */
			{17294,22,0}, /* core7 fp64 bit49 */
			{17158,22,0}, /* core7 fp64 bit50 */
			{17157,22,0}, /* core7 fp64 bit51 */
			{17293,22,0}, /* core7 fp64 bit52 */
			{17186,22,0}, /* core7 fp64 bit53 */
			{17291,22,0}, /* core7 fp64 bit54 */
			{17289,22,0}, /* core7 fp64 bit55 */
			{17290,22,0}, /* core7 fp64 bit56 */
			{17295,22,0}, /* core7 fp64 bit57 */
			{17189,22,0}, /* core7 fp64 bit58 */
			{17188,22,0}, /* core7 fp64 bit59 */
			{17187,22,0}, /* core7 fp64 bit60 */
			{17190,22,0}, /* core7 fp64 bit61 */
			{10836,18,0}, /* core7 fp64 bit62 */
			{10835,18,0}, /* core7 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{20196,18,0}, /* core7 sp_EL0 bit0 */
			{19624,18,0}, /* core7 sp_EL0 bit1 */
			{20195,18,0}, /* core7 sp_EL0 bit2 */
			{19623,18,0}, /* core7 sp_EL0 bit3 */
			{19094,18,0}, /* core7 sp_EL0 bit4 */
			{19092,18,0}, /* core7 sp_EL0 bit5 */
			{19093,18,0}, /* core7 sp_EL0 bit6 */
			{19095,18,0}, /* core7 sp_EL0 bit7 */
			{19091,18,0}, /* core7 sp_EL0 bit8 */
			{19089,18,0}, /* core7 sp_EL0 bit9 */
			{19098,18,0}, /* core7 sp_EL0 bit10 */
			{19096,18,0}, /* core7 sp_EL0 bit11 */
			{19626,18,0}, /* core7 sp_EL0 bit12 */
			{19099,18,0}, /* core7 sp_EL0 bit13 */
			{19090,18,0}, /* core7 sp_EL0 bit14 */
			{19628,18,0}, /* core7 sp_EL0 bit15 */
			{19097,18,0}, /* core7 sp_EL0 bit16 */
			{19087,18,0}, /* core7 sp_EL0 bit17 */
			{19616,18,0}, /* core7 sp_EL0 bit18 */
			{19618,18,0}, /* core7 sp_EL0 bit19 */
			{19088,18,0}, /* core7 sp_EL0 bit20 */
			{19617,18,0}, /* core7 sp_EL0 bit21 */
			{19621,18,0}, /* core7 sp_EL0 bit22 */
			{19100,18,0}, /* core7 sp_EL0 bit23 */
			{19630,18,0}, /* core7 sp_EL0 bit24 */
			{19619,18,0}, /* core7 sp_EL0 bit25 */
			{19629,18,0}, /* core7 sp_EL0 bit26 */
			{19622,18,0}, /* core7 sp_EL0 bit27 */
			{19620,18,0}, /* core7 sp_EL0 bit28 */
			{17619,18,0}, /* core7 sp_EL0 bit29 */
			{19631,18,0}, /* core7 sp_EL0 bit30 */
			{19627,18,0}, /* core7 sp_EL0 bit31 */
			{17066,22,0}, /* core7 sp_EL0 bit32 */
			{20135,18,0}, /* core7 sp_EL0 bit33 */
			{20130,18,0}, /* core7 sp_EL0 bit34 */
			{20134,18,0}, /* core7 sp_EL0 bit35 */
			{17065,22,0}, /* core7 sp_EL0 bit36 */
			{17053,22,0}, /* core7 sp_EL0 bit37 */
			{19955,18,0}, /* core7 sp_EL0 bit38 */
			{17054,22,0}, /* core7 sp_EL0 bit39 */
			{17063,22,0}, /* core7 sp_EL0 bit40 */
			{17062,22,0}, /* core7 sp_EL0 bit41 */
			{17064,22,0}, /* core7 sp_EL0 bit42 */
			{17254,22,0}, /* core7 sp_EL0 bit43 */
			{17271,22,0}, /* core7 sp_EL0 bit44 */
			{17273,22,0}, /* core7 sp_EL0 bit45 */
			{17255,22,0}, /* core7 sp_EL0 bit46 */
			{17274,22,0}, /* core7 sp_EL0 bit47 */
			{17251,22,0}, /* core7 sp_EL0 bit48 */
			{17252,22,0}, /* core7 sp_EL0 bit49 */
			{17278,22,0}, /* core7 sp_EL0 bit50 */
			{17277,22,0}, /* core7 sp_EL0 bit51 */
			{11124,18,0}, /* core7 sp_EL0 bit52 */
			{17272,22,0}, /* core7 sp_EL0 bit53 */
			{17276,22,0}, /* core7 sp_EL0 bit54 */
			{17275,22,0}, /* core7 sp_EL0 bit55 */
			{17253,22,0}, /* core7 sp_EL0 bit56 */
			{17250,22,0}, /* core7 sp_EL0 bit57 */
			{17052,22,0}, /* core7 sp_EL0 bit58 */
			{17051,22,0}, /* core7 sp_EL0 bit59 */
			{10876,18,0}, /* core7 sp_EL0 bit60 */
			{10875,18,0}, /* core7 sp_EL0 bit61 */
			{20133,18,0}, /* core7 sp_EL0 bit62 */
			{20132,18,0}, /* core7 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{20596,18,0}, /* core7 sp_EL1 bit0 */
			{20595,18,0}, /* core7 sp_EL1 bit1 */
			{20594,18,0}, /* core7 sp_EL1 bit2 */
			{20593,18,0}, /* core7 sp_EL1 bit3 */
			{19013,18,0}, /* core7 sp_EL1 bit4 */
			{20925,18,0}, /* core7 sp_EL1 bit5 */
			{19014,18,0}, /* core7 sp_EL1 bit6 */
			{19042,18,0}, /* core7 sp_EL1 bit7 */
			{19039,18,0}, /* core7 sp_EL1 bit8 */
			{19021,18,0}, /* core7 sp_EL1 bit9 */
			{19040,18,0}, /* core7 sp_EL1 bit10 */
			{19038,18,0}, /* core7 sp_EL1 bit11 */
			{19030,18,0}, /* core7 sp_EL1 bit12 */
			{19108,18,0}, /* core7 sp_EL1 bit13 */
			{19035,18,0}, /* core7 sp_EL1 bit14 */
			{19022,18,0}, /* core7 sp_EL1 bit15 */
			{19034,18,0}, /* core7 sp_EL1 bit16 */
			{19041,18,0}, /* core7 sp_EL1 bit17 */
			{19029,18,0}, /* core7 sp_EL1 bit18 */
			{19648,18,0}, /* core7 sp_EL1 bit19 */
			{19651,18,0}, /* core7 sp_EL1 bit20 */
			{19107,18,0}, /* core7 sp_EL1 bit21 */
			{19024,18,0}, /* core7 sp_EL1 bit22 */
			{19647,18,0}, /* core7 sp_EL1 bit23 */
			{19652,18,0}, /* core7 sp_EL1 bit24 */
			{19028,18,0}, /* core7 sp_EL1 bit25 */
			{19033,18,0}, /* core7 sp_EL1 bit26 */
			{19650,18,0}, /* core7 sp_EL1 bit27 */
			{19023,18,0}, /* core7 sp_EL1 bit28 */
			{19649,18,0}, /* core7 sp_EL1 bit29 */
			{19133,18,0}, /* core7 sp_EL1 bit30 */
			{19020,18,0}, /* core7 sp_EL1 bit31 */
			{20161,18,0}, /* core7 sp_EL1 bit32 */
			{20150,18,0}, /* core7 sp_EL1 bit33 */
			{20149,18,0}, /* core7 sp_EL1 bit34 */
			{20136,18,0}, /* core7 sp_EL1 bit35 */
			{20147,18,0}, /* core7 sp_EL1 bit36 */
			{20139,18,0}, /* core7 sp_EL1 bit37 */
			{20148,18,0}, /* core7 sp_EL1 bit38 */
			{20137,18,0}, /* core7 sp_EL1 bit39 */
			{19979,18,0}, /* core7 sp_EL1 bit40 */
			{20138,18,0}, /* core7 sp_EL1 bit41 */
			{20140,18,0}, /* core7 sp_EL1 bit42 */
			{19978,18,0}, /* core7 sp_EL1 bit43 */
			{17233,22,0}, /* core7 sp_EL1 bit44 */
			{17232,22,0}, /* core7 sp_EL1 bit45 */
			{17235,22,0}, /* core7 sp_EL1 bit46 */
			{17236,22,0}, /* core7 sp_EL1 bit47 */
			{17286,22,0}, /* core7 sp_EL1 bit48 */
			{17239,22,0}, /* core7 sp_EL1 bit49 */
			{17238,22,0}, /* core7 sp_EL1 bit50 */
			{17241,22,0}, /* core7 sp_EL1 bit51 */
			{24508,22,0}, /* core7 sp_EL1 bit52 */
			{24507,22,0}, /* core7 sp_EL1 bit53 */
			{17240,22,0}, /* core7 sp_EL1 bit54 */
			{17230,22,0}, /* core7 sp_EL1 bit55 */
			{17227,22,0}, /* core7 sp_EL1 bit56 */
			{17229,22,0}, /* core7 sp_EL1 bit57 */
			{17237,22,0}, /* core7 sp_EL1 bit58 */
			{17287,22,0}, /* core7 sp_EL1 bit59 */
			{17228,22,0}, /* core7 sp_EL1 bit60 */
			{17234,22,0}, /* core7 sp_EL1 bit61 */
			{20142,18,0}, /* core7 sp_EL1 bit62 */
			{20141,18,0}, /* core7 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{20438,18,0}, /* core7 sp_EL2 bit0 */
			{20437,18,0}, /* core7 sp_EL2 bit1 */
			{20436,18,0}, /* core7 sp_EL2 bit2 */
			{20435,18,0}, /* core7 sp_EL2 bit3 */
			{20902,18,0}, /* core7 sp_EL2 bit4 */
			{20900,18,0}, /* core7 sp_EL2 bit5 */
			{20897,18,0}, /* core7 sp_EL2 bit6 */
			{20916,18,0}, /* core7 sp_EL2 bit7 */
			{20903,18,0}, /* core7 sp_EL2 bit8 */
			{20904,18,0}, /* core7 sp_EL2 bit9 */
			{20901,18,0}, /* core7 sp_EL2 bit10 */
			{20917,18,0}, /* core7 sp_EL2 bit11 */
			{18991,18,0}, /* core7 sp_EL2 bit12 */
			{17987,18,0}, /* core7 sp_EL2 bit13 */
			{20694,18,0}, /* core7 sp_EL2 bit14 */
			{17990,18,0}, /* core7 sp_EL2 bit15 */
			{20898,18,0}, /* core7 sp_EL2 bit16 */
			{20899,18,0}, /* core7 sp_EL2 bit17 */
			{17986,18,0}, /* core7 sp_EL2 bit18 */
			{17963,18,0}, /* core7 sp_EL2 bit19 */
			{17985,18,0}, /* core7 sp_EL2 bit20 */
			{17988,18,0}, /* core7 sp_EL2 bit21 */
			{18043,18,0}, /* core7 sp_EL2 bit22 */
			{18990,18,0}, /* core7 sp_EL2 bit23 */
			{17965,18,0}, /* core7 sp_EL2 bit24 */
			{17991,18,0}, /* core7 sp_EL2 bit25 */
			{17994,18,0}, /* core7 sp_EL2 bit26 */
			{18042,18,0}, /* core7 sp_EL2 bit27 */
			{17964,18,0}, /* core7 sp_EL2 bit28 */
			{17993,18,0}, /* core7 sp_EL2 bit29 */
			{17989,18,0}, /* core7 sp_EL2 bit30 */
			{17992,18,0}, /* core7 sp_EL2 bit31 */
			{17148,22,0}, /* core7 sp_EL2 bit32 */
			{17058,22,0}, /* core7 sp_EL2 bit33 */
			{17061,22,0}, /* core7 sp_EL2 bit34 */
			{17149,22,0}, /* core7 sp_EL2 bit35 */
			{17146,22,0}, /* core7 sp_EL2 bit36 */
			{17150,22,0}, /* core7 sp_EL2 bit37 */
			{17059,22,0}, /* core7 sp_EL2 bit38 */
			{17147,22,0}, /* core7 sp_EL2 bit39 */
			{17151,22,0}, /* core7 sp_EL2 bit40 */
			{17152,22,0}, /* core7 sp_EL2 bit41 */
			{19969,18,0}, /* core7 sp_EL2 bit42 */
			{19968,18,0}, /* core7 sp_EL2 bit43 */
			{17160,22,0}, /* core7 sp_EL2 bit44 */
			{17163,22,0}, /* core7 sp_EL2 bit45 */
			{17183,22,0}, /* core7 sp_EL2 bit46 */
			{17162,22,0}, /* core7 sp_EL2 bit47 */
			{17182,22,0}, /* core7 sp_EL2 bit48 */
			{17164,22,0}, /* core7 sp_EL2 bit49 */
			{19971,18,0}, /* core7 sp_EL2 bit50 */
			{19970,18,0}, /* core7 sp_EL2 bit51 */
			{19975,18,0}, /* core7 sp_EL2 bit52 */
			{19974,18,0}, /* core7 sp_EL2 bit53 */
			{19973,18,0}, /* core7 sp_EL2 bit54 */
			{19972,18,0}, /* core7 sp_EL2 bit55 */
			{17161,22,0}, /* core7 sp_EL2 bit56 */
			{17166,22,0}, /* core7 sp_EL2 bit57 */
			{17159,22,0}, /* core7 sp_EL2 bit58 */
			{17154,22,0}, /* core7 sp_EL2 bit59 */
			{17153,22,0}, /* core7 sp_EL2 bit60 */
			{17165,22,0}, /* core7 sp_EL2 bit61 */
			{19977,18,0}, /* core7 sp_EL2 bit62 */
			{19976,18,0}, /* core7 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{20190,18,0}, /* core7 sp_EL3 bit0 */
			{17618,18,0}, /* core7 sp_EL3 bit1 */
			{20189,18,0}, /* core7 sp_EL3 bit2 */
			{19286,18,0}, /* core7 sp_EL3 bit3 */
			{18978,18,0}, /* core7 sp_EL3 bit4 */
			{19285,18,0}, /* core7 sp_EL3 bit5 */
			{18963,18,0}, /* core7 sp_EL3 bit6 */
			{18982,18,0}, /* core7 sp_EL3 bit7 */
			{18985,18,0}, /* core7 sp_EL3 bit8 */
			{18983,18,0}, /* core7 sp_EL3 bit9 */
			{18962,18,0}, /* core7 sp_EL3 bit10 */
			{18979,18,0}, /* core7 sp_EL3 bit11 */
			{18986,18,0}, /* core7 sp_EL3 bit12 */
			{18981,18,0}, /* core7 sp_EL3 bit13 */
			{18961,18,0}, /* core7 sp_EL3 bit14 */
			{17637,18,0}, /* core7 sp_EL3 bit15 */
			{18980,18,0}, /* core7 sp_EL3 bit16 */
			{18964,18,0}, /* core7 sp_EL3 bit17 */
			{17616,18,0}, /* core7 sp_EL3 bit18 */
			{17636,18,0}, /* core7 sp_EL3 bit19 */
			{17614,18,0}, /* core7 sp_EL3 bit20 */
			{17635,18,0}, /* core7 sp_EL3 bit21 */
			{17613,18,0}, /* core7 sp_EL3 bit22 */
			{18984,18,0}, /* core7 sp_EL3 bit23 */
			{19615,18,0}, /* core7 sp_EL3 bit24 */
			{17615,18,0}, /* core7 sp_EL3 bit25 */
			{17639,18,0}, /* core7 sp_EL3 bit26 */
			{17638,18,0}, /* core7 sp_EL3 bit27 */
			{17617,18,0}, /* core7 sp_EL3 bit28 */
			{17634,18,0}, /* core7 sp_EL3 bit29 */
			{17621,18,0}, /* core7 sp_EL3 bit30 */
			{17620,18,0}, /* core7 sp_EL3 bit31 */
			{20156,18,0}, /* core7 sp_EL3 bit32 */
			{20152,18,0}, /* core7 sp_EL3 bit33 */
			{20159,18,0}, /* core7 sp_EL3 bit34 */
			{20151,18,0}, /* core7 sp_EL3 bit35 */
			{19963,18,0}, /* core7 sp_EL3 bit36 */
			{19958,18,0}, /* core7 sp_EL3 bit37 */
			{19964,18,0}, /* core7 sp_EL3 bit38 */
			{20155,18,0}, /* core7 sp_EL3 bit39 */
			{20154,18,0}, /* core7 sp_EL3 bit40 */
			{19962,18,0}, /* core7 sp_EL3 bit41 */
			{20158,18,0}, /* core7 sp_EL3 bit42 */
			{19965,18,0}, /* core7 sp_EL3 bit43 */
			{20157,18,0}, /* core7 sp_EL3 bit44 */
			{17281,22,0}, /* core7 sp_EL3 bit45 */
			{20153,18,0}, /* core7 sp_EL3 bit46 */
			{17283,22,0}, /* core7 sp_EL3 bit47 */
			{17243,22,0}, /* core7 sp_EL3 bit48 */
			{17284,22,0}, /* core7 sp_EL3 bit49 */
			{17282,22,0}, /* core7 sp_EL3 bit50 */
			{17245,22,0}, /* core7 sp_EL3 bit51 */
			{17248,22,0}, /* core7 sp_EL3 bit52 */
			{17279,22,0}, /* core7 sp_EL3 bit53 */
			{17280,22,0}, /* core7 sp_EL3 bit54 */
			{17249,22,0}, /* core7 sp_EL3 bit55 */
			{17285,22,0}, /* core7 sp_EL3 bit56 */
			{17246,22,0}, /* core7 sp_EL3 bit57 */
			{17244,22,0}, /* core7 sp_EL3 bit58 */
			{17231,22,0}, /* core7 sp_EL3 bit59 */
			{17242,22,0}, /* core7 sp_EL3 bit60 */
			{17247,22,0}, /* core7 sp_EL3 bit61 */
			{19957,18,0}, /* core7 sp_EL3 bit62 */
			{19956,18,0}, /* core7 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{20194,18,0}, /* core7 elr_EL1 bit0 */
			{20193,18,0}, /* core7 elr_EL1 bit1 */
			{20192,18,0}, /* core7 elr_EL1 bit2 */
			{20191,18,0}, /* core7 elr_EL1 bit3 */
			{18949,18,0}, /* core7 elr_EL1 bit4 */
			{18942,18,0}, /* core7 elr_EL1 bit5 */
			{18954,18,0}, /* core7 elr_EL1 bit6 */
			{18943,18,0}, /* core7 elr_EL1 bit7 */
			{18952,18,0}, /* core7 elr_EL1 bit8 */
			{18945,18,0}, /* core7 elr_EL1 bit9 */
			{18944,18,0}, /* core7 elr_EL1 bit10 */
			{18946,18,0}, /* core7 elr_EL1 bit11 */
			{18953,18,0}, /* core7 elr_EL1 bit12 */
			{18947,18,0}, /* core7 elr_EL1 bit13 */
			{18948,18,0}, /* core7 elr_EL1 bit14 */
			{18951,18,0}, /* core7 elr_EL1 bit15 */
			{18950,18,0}, /* core7 elr_EL1 bit16 */
			{18046,18,0}, /* core7 elr_EL1 bit17 */
			{17979,18,0}, /* core7 elr_EL1 bit18 */
			{17973,18,0}, /* core7 elr_EL1 bit19 */
			{17977,18,0}, /* core7 elr_EL1 bit20 */
			{17982,18,0}, /* core7 elr_EL1 bit21 */
			{17983,18,0}, /* core7 elr_EL1 bit22 */
			{18044,18,0}, /* core7 elr_EL1 bit23 */
			{17981,18,0}, /* core7 elr_EL1 bit24 */
			{17984,18,0}, /* core7 elr_EL1 bit25 */
			{18045,18,0}, /* core7 elr_EL1 bit26 */
			{18213,18,0}, /* core7 elr_EL1 bit27 */
			{17976,18,0}, /* core7 elr_EL1 bit28 */
			{17978,18,0}, /* core7 elr_EL1 bit29 */
			{17980,18,0}, /* core7 elr_EL1 bit30 */
			{17975,18,0}, /* core7 elr_EL1 bit31 */
			{17193,22,0}, /* core7 elr_EL1 bit32 */
			{17135,22,0}, /* core7 elr_EL1 bit33 */
			{17132,22,0}, /* core7 elr_EL1 bit34 */
			{17131,22,0}, /* core7 elr_EL1 bit35 */
			{17137,22,0}, /* core7 elr_EL1 bit36 */
			{17130,22,0}, /* core7 elr_EL1 bit37 */
			{17136,22,0}, /* core7 elr_EL1 bit38 */
			{17129,22,0}, /* core7 elr_EL1 bit39 */
			{17203,22,0}, /* core7 elr_EL1 bit40 */
			{17123,22,0}, /* core7 elr_EL1 bit41 */
			{17124,22,0}, /* core7 elr_EL1 bit42 */
			{17205,22,0}, /* core7 elr_EL1 bit43 */
			{17209,22,0}, /* core7 elr_EL1 bit44 */
			{17201,22,0}, /* core7 elr_EL1 bit45 */
			{17200,22,0}, /* core7 elr_EL1 bit46 */
			{17208,22,0}, /* core7 elr_EL1 bit47 */
			{17206,22,0}, /* core7 elr_EL1 bit48 */
			{17204,22,0}, /* core7 elr_EL1 bit49 */
			{17199,22,0}, /* core7 elr_EL1 bit50 */
			{17198,22,0}, /* core7 elr_EL1 bit51 */
			{17197,22,0}, /* core7 elr_EL1 bit52 */
			{17196,22,0}, /* core7 elr_EL1 bit53 */
			{17211,22,0}, /* core7 elr_EL1 bit54 */
			{17195,22,0}, /* core7 elr_EL1 bit55 */
			{17194,22,0}, /* core7 elr_EL1 bit56 */
			{17210,22,0}, /* core7 elr_EL1 bit57 */
			{17202,22,0}, /* core7 elr_EL1 bit58 */
			{17192,22,0}, /* core7 elr_EL1 bit59 */
			{17191,22,0}, /* core7 elr_EL1 bit60 */
			{17207,22,0}, /* core7 elr_EL1 bit61 */
			{17134,22,0}, /* core7 elr_EL1 bit62 */
			{17133,22,0}, /* core7 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{20188,18,0}, /* core7 elr_EL2 bit0 */
			{20187,18,0}, /* core7 elr_EL2 bit1 */
			{20186,18,0}, /* core7 elr_EL2 bit2 */
			{20185,18,0}, /* core7 elr_EL2 bit3 */
			{18971,18,0}, /* core7 elr_EL2 bit4 */
			{18966,18,0}, /* core7 elr_EL2 bit5 */
			{18977,18,0}, /* core7 elr_EL2 bit6 */
			{18968,18,0}, /* core7 elr_EL2 bit7 */
			{18965,18,0}, /* core7 elr_EL2 bit8 */
			{18975,18,0}, /* core7 elr_EL2 bit9 */
			{18967,18,0}, /* core7 elr_EL2 bit10 */
			{18972,18,0}, /* core7 elr_EL2 bit11 */
			{19127,18,0}, /* core7 elr_EL2 bit12 */
			{18976,18,0}, /* core7 elr_EL2 bit13 */
			{18973,18,0}, /* core7 elr_EL2 bit14 */
			{19639,18,0}, /* core7 elr_EL2 bit15 */
			{18970,18,0}, /* core7 elr_EL2 bit16 */
			{18974,18,0}, /* core7 elr_EL2 bit17 */
			{17968,18,0}, /* core7 elr_EL2 bit18 */
			{19640,18,0}, /* core7 elr_EL2 bit19 */
			{18218,18,0}, /* core7 elr_EL2 bit20 */
			{17969,18,0}, /* core7 elr_EL2 bit21 */
			{18217,18,0}, /* core7 elr_EL2 bit22 */
			{19642,18,0}, /* core7 elr_EL2 bit23 */
			{19641,18,0}, /* core7 elr_EL2 bit24 */
			{18969,18,0}, /* core7 elr_EL2 bit25 */
			{18220,18,0}, /* core7 elr_EL2 bit26 */
			{19637,18,0}, /* core7 elr_EL2 bit27 */
			{18219,18,0}, /* core7 elr_EL2 bit28 */
			{19644,18,0}, /* core7 elr_EL2 bit29 */
			{19638,18,0}, /* core7 elr_EL2 bit30 */
			{19643,18,0}, /* core7 elr_EL2 bit31 */
			{17050,22,0}, /* core7 elr_EL2 bit32 */
			{17072,22,0}, /* core7 elr_EL2 bit33 */
			{17070,22,0}, /* core7 elr_EL2 bit34 */
			{17074,22,0}, /* core7 elr_EL2 bit35 */
			{17076,22,0}, /* core7 elr_EL2 bit36 */
			{17080,22,0}, /* core7 elr_EL2 bit37 */
			{17071,22,0}, /* core7 elr_EL2 bit38 */
			{17077,22,0}, /* core7 elr_EL2 bit39 */
			{17075,22,0}, /* core7 elr_EL2 bit40 */
			{17128,22,0}, /* core7 elr_EL2 bit41 */
			{17079,22,0}, /* core7 elr_EL2 bit42 */
			{17125,22,0}, /* core7 elr_EL2 bit43 */
			{17127,22,0}, /* core7 elr_EL2 bit44 */
			{17223,22,0}, /* core7 elr_EL2 bit45 */
			{17126,22,0}, /* core7 elr_EL2 bit46 */
			{17221,22,0}, /* core7 elr_EL2 bit47 */
			{17226,22,0}, /* core7 elr_EL2 bit48 */
			{17225,22,0}, /* core7 elr_EL2 bit49 */
			{17213,22,0}, /* core7 elr_EL2 bit50 */
			{17224,22,0}, /* core7 elr_EL2 bit51 */
			{17288,22,0}, /* core7 elr_EL2 bit52 */
			{17220,22,0}, /* core7 elr_EL2 bit53 */
			{17214,22,0}, /* core7 elr_EL2 bit54 */
			{17222,22,0}, /* core7 elr_EL2 bit55 */
			{17215,22,0}, /* core7 elr_EL2 bit56 */
			{17216,22,0}, /* core7 elr_EL2 bit57 */
			{17212,22,0}, /* core7 elr_EL2 bit58 */
			{17122,22,0}, /* core7 elr_EL2 bit59 */
			{17121,22,0}, /* core7 elr_EL2 bit60 */
			{17219,22,0}, /* core7 elr_EL2 bit61 */
			{17217,22,0}, /* core7 elr_EL2 bit62 */
			{17218,22,0}, /* core7 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{20688,18,0}, /* core7 elr_EL3 bit0 */
			{20687,18,0}, /* core7 elr_EL3 bit1 */
			{20686,18,0}, /* core7 elr_EL3 bit2 */
			{20685,18,0}, /* core7 elr_EL3 bit3 */
			{18956,18,0}, /* core7 elr_EL3 bit4 */
			{18940,18,0}, /* core7 elr_EL3 bit5 */
			{20912,18,0}, /* core7 elr_EL3 bit6 */
			{20911,18,0}, /* core7 elr_EL3 bit7 */
			{20910,18,0}, /* core7 elr_EL3 bit8 */
			{18939,18,0}, /* core7 elr_EL3 bit9 */
			{18957,18,0}, /* core7 elr_EL3 bit10 */
			{18959,18,0}, /* core7 elr_EL3 bit11 */
			{17612,18,0}, /* core7 elr_EL3 bit12 */
			{20909,18,0}, /* core7 elr_EL3 bit13 */
			{18958,18,0}, /* core7 elr_EL3 bit14 */
			{17633,18,0}, /* core7 elr_EL3 bit15 */
			{18941,18,0}, /* core7 elr_EL3 bit16 */
			{18955,18,0}, /* core7 elr_EL3 bit17 */
			{17626,18,0}, /* core7 elr_EL3 bit18 */
			{18212,18,0}, /* core7 elr_EL3 bit19 */
			{17631,18,0}, /* core7 elr_EL3 bit20 */
			{17628,18,0}, /* core7 elr_EL3 bit21 */
			{17630,18,0}, /* core7 elr_EL3 bit22 */
			{18960,18,0}, /* core7 elr_EL3 bit23 */
			{17623,18,0}, /* core7 elr_EL3 bit24 */
			{17629,18,0}, /* core7 elr_EL3 bit25 */
			{17625,18,0}, /* core7 elr_EL3 bit26 */
			{17632,18,0}, /* core7 elr_EL3 bit27 */
			{18211,18,0}, /* core7 elr_EL3 bit28 */
			{17624,18,0}, /* core7 elr_EL3 bit29 */
			{17627,18,0}, /* core7 elr_EL3 bit30 */
			{17622,18,0}, /* core7 elr_EL3 bit31 */
			{20001,18,0}, /* core7 elr_EL3 bit32 */
			{20007,18,0}, /* core7 elr_EL3 bit33 */
			{20002,18,0}, /* core7 elr_EL3 bit34 */
			{20004,18,0}, /* core7 elr_EL3 bit35 */
			{20003,18,0}, /* core7 elr_EL3 bit36 */
			{19999,18,0}, /* core7 elr_EL3 bit37 */
			{20000,18,0}, /* core7 elr_EL3 bit38 */
			{20005,18,0}, /* core7 elr_EL3 bit39 */
			{19998,18,0}, /* core7 elr_EL3 bit40 */
			{11131,18,0}, /* core7 elr_EL3 bit41 */
			{10838,18,0}, /* core7 elr_EL3 bit42 */
			{10837,18,0}, /* core7 elr_EL3 bit43 */
			{11194,18,0}, /* core7 elr_EL3 bit44 */
			{11193,18,0}, /* core7 elr_EL3 bit45 */
			{11170,18,0}, /* core7 elr_EL3 bit46 */
			{11166,18,0}, /* core7 elr_EL3 bit47 */
			{11198,18,0}, /* core7 elr_EL3 bit48 */
			{11167,18,0}, /* core7 elr_EL3 bit49 */
			{19997,18,0}, /* core7 elr_EL3 bit50 */
			{11169,18,0}, /* core7 elr_EL3 bit51 */
			{19296,18,0}, /* core7 elr_EL3 bit52 */
			{19295,18,0}, /* core7 elr_EL3 bit53 */
			{20009,18,0}, /* core7 elr_EL3 bit54 */
			{20008,18,0}, /* core7 elr_EL3 bit55 */
			{11195,18,0}, /* core7 elr_EL3 bit56 */
			{11197,18,0}, /* core7 elr_EL3 bit57 */
			{11196,18,0}, /* core7 elr_EL3 bit58 */
			{11168,18,0}, /* core7 elr_EL3 bit59 */
			{11130,18,0}, /* core7 elr_EL3 bit60 */
			{19996,18,0}, /* core7 elr_EL3 bit61 */
			{19298,18,0}, /* core7 elr_EL3 bit62 */
			{19297,18,0}, /* core7 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{20759,22,0}, /* core7 raw_pc bit0 */
			{20483,22,0}, /* core7 raw_pc bit1 */
			{20486,22,0}, /* core7 raw_pc bit2 */
			{20765,22,0}, /* core7 raw_pc bit3 */
			{20764,22,0}, /* core7 raw_pc bit4 */
			{20999,22,0}, /* core7 raw_pc bit5 */
			{20484,22,0}, /* core7 raw_pc bit6 */
			{22277,22,0}, /* core7 raw_pc bit7 */
			{20494,22,0}, /* core7 raw_pc bit8 */
			{20512,22,0}, /* core7 raw_pc bit9 */
			{20495,22,0}, /* core7 raw_pc bit10 */
			{20509,22,0}, /* core7 raw_pc bit11 */
			{20506,22,0}, /* core7 raw_pc bit12 */
			{20505,22,0}, /* core7 raw_pc bit13 */
			{20515,22,0}, /* core7 raw_pc bit14 */
			{20508,22,0}, /* core7 raw_pc bit15 */
			{20516,22,0}, /* core7 raw_pc bit16 */
			{20514,22,0}, /* core7 raw_pc bit17 */
			{20507,22,0}, /* core7 raw_pc bit18 */
			{22025,22,0}, /* core7 raw_pc bit19 */
			{20518,22,0}, /* core7 raw_pc bit20 */
			{22278,22,0}, /* core7 raw_pc bit21 */
			{20513,22,0}, /* core7 raw_pc bit22 */
			{22027,22,0}, /* core7 raw_pc bit23 */
			{22026,22,0}, /* core7 raw_pc bit24 */
			{20511,22,0}, /* core7 raw_pc bit25 */
			{22028,22,0}, /* core7 raw_pc bit26 */
			{20517,22,0}, /* core7 raw_pc bit27 */
			{20519,22,0}, /* core7 raw_pc bit28 */
			{20510,22,0}, /* core7 raw_pc bit29 */
			{22029,22,0}, /* core7 raw_pc bit30 */
			{20947,22,0}, /* core7 raw_pc bit31 */
			{20953,22,0}, /* core7 raw_pc bit32 */
			{21026,22,0}, /* core7 raw_pc bit33 */
			{20945,22,0}, /* core7 raw_pc bit34 */
			{21030,22,0}, /* core7 raw_pc bit35 */
			{21029,22,0}, /* core7 raw_pc bit36 */
			{20951,22,0}, /* core7 raw_pc bit37 */
			{20954,22,0}, /* core7 raw_pc bit38 */
			{20948,22,0}, /* core7 raw_pc bit39 */
			{20950,22,0}, /* core7 raw_pc bit40 */
			{20952,22,0}, /* core7 raw_pc bit41 */
			{20949,22,0}, /* core7 raw_pc bit42 */
			{17797,22,0}, /* core7 raw_pc bit43 */
			{21025,22,0}, /* core7 raw_pc bit44 */
			{21028,22,0}, /* core7 raw_pc bit45 */
			{21027,22,0}, /* core7 raw_pc bit46 */
			{20946,22,0}, /* core7 raw_pc bit47 */
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
			{21014,22,0}, /* core7 pc_iss bit0 */
			{22013,22,0}, /* core7 pc_iss bit1 */
			{20931,22,0}, /* core7 pc_iss bit2 */
			{22011,22,0}, /* core7 pc_iss bit3 */
			{20969,22,0}, /* core7 pc_iss bit4 */
			{22012,22,0}, /* core7 pc_iss bit5 */
			{20932,22,0}, /* core7 pc_iss bit6 */
			{20968,22,0}, /* core7 pc_iss bit7 */
			{20933,22,0}, /* core7 pc_iss bit8 */
			{20967,22,0}, /* core7 pc_iss bit9 */
			{20934,22,0}, /* core7 pc_iss bit10 */
			{21017,22,0}, /* core7 pc_iss bit11 */
			{20767,22,0}, /* core7 pc_iss bit12 */
			{20935,22,0}, /* core7 pc_iss bit13 */
			{21015,22,0}, /* core7 pc_iss bit14 */
			{21016,22,0}, /* core7 pc_iss bit15 */
			{20963,22,0}, /* core7 pc_iss bit16 */
			{22016,22,0}, /* core7 pc_iss bit17 */
			{20965,22,0}, /* core7 pc_iss bit18 */
			{21020,22,0}, /* core7 pc_iss bit19 */
			{21019,22,0}, /* core7 pc_iss bit20 */
			{22015,22,0}, /* core7 pc_iss bit21 */
			{20966,22,0}, /* core7 pc_iss bit22 */
			{22014,22,0}, /* core7 pc_iss bit23 */
			{20964,22,0}, /* core7 pc_iss bit24 */
			{20936,22,0}, /* core7 pc_iss bit25 */
			{22018,22,0}, /* core7 pc_iss bit26 */
			{20937,22,0}, /* core7 pc_iss bit27 */
			{22017,22,0}, /* core7 pc_iss bit28 */
			{21021,22,0}, /* core7 pc_iss bit29 */
			{20768,22,0}, /* core7 pc_iss bit30 */
			{20769,22,0}, /* core7 pc_iss bit31 */
			{11276,18,0}, /* core7 pc_iss bit32 */
			{21520,22,0}, /* core7 pc_iss bit33 */
			{23933,18,0}, /* core7 pc_iss bit34 */
			{21530,22,0}, /* core7 pc_iss bit35 */
			{21521,22,0}, /* core7 pc_iss bit36 */
			{23934,18,0}, /* core7 pc_iss bit37 */
			{11274,18,0}, /* core7 pc_iss bit38 */
			{21519,22,0}, /* core7 pc_iss bit39 */
			{21522,22,0}, /* core7 pc_iss bit40 */
			{21523,22,0}, /* core7 pc_iss bit41 */
			{11275,18,0}, /* core7 pc_iss bit42 */
			{21528,22,0}, /* core7 pc_iss bit43 */
			{21531,22,0}, /* core7 pc_iss bit44 */
			{21526,22,0}, /* core7 pc_iss bit45 */
			{21527,22,0}, /* core7 pc_iss bit46 */
			{11273,18,0}, /* core7 pc_iss bit47 */
			{11277,18,0}, /* core7 pc_iss bit48 */
			{11268,18,0}, /* core7 pc_iss bit49 */
			{21529,22,0}, /* core7 pc_iss bit50 */
			{11279,18,0}, /* core7 pc_iss bit51 */
			{11269,18,0}, /* core7 pc_iss bit52 */
			{11280,18,0}, /* core7 pc_iss bit53 */
			{11272,18,0}, /* core7 pc_iss bit54 */
			{11282,18,0}, /* core7 pc_iss bit55 */
			{11278,18,0}, /* core7 pc_iss bit56 */
			{11281,18,0}, /* core7 pc_iss bit57 */
			{21766,22,0}, /* core7 pc_iss bit58 */
			{21765,22,0}, /* core7 pc_iss bit59 */
			{11876,18,0}, /* core7 pc_iss bit60 */
			{11875,18,0}, /* core7 pc_iss bit61 */
			{21764,22,0}, /* core7 pc_iss bit62 */
			{21763,22,0}, /* core7 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{20757,22,0}, /* core7 full_pc_wr bit0 */
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
			{21257,22,0}, /* core7 full_pc_ex1 bit0 */
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
			{21002,22,0}, /* core7 full_pc_ex2 bit0 */
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

struct big_core_spec big_core[1];
