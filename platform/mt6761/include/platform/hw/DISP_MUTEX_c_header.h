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
#ifndef __DISP_MUTEX_REGS_H__
#define __DISP_MUTEX_REGS_H__


#ifdef __cplusplus
extern "C" {
#endif

#ifndef REG_BASE_C_MODULE
// ----------------- DISP_MUTEX Bit Field Definitions -------------------

#define PACKING
typedef unsigned int FIELD;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_INTEN               : 32;
    } Bits;
    UINT32 Raw;
} REG_INTEN, *PREG_INTEN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_INTSTA              : 32;
    } Bits;
    UINT32 Raw;
} REG_INTSTA, *PREG_INTSTA;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_CFG                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_CFG, *PREG_CFG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX0_EN, *PREG_DISP_MUTEX0_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX0_RST, *PREG_DISP_MUTEX0_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX0_CTL, *PREG_DISP_MUTEX0_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX0_MOD0, *PREG_DISP_MUTEX0_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX1_EN, *PREG_DISP_MUTEX1_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX1_RST, *PREG_DISP_MUTEX1_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX1_CTL, *PREG_DISP_MUTEX1_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX1_MOD0, *PREG_DISP_MUTEX1_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX2_EN, *PREG_DISP_MUTEX2_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX2_RST, *PREG_DISP_MUTEX2_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX2_CTL, *PREG_DISP_MUTEX2_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX2_MOD0, *PREG_DISP_MUTEX2_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX3_EN, *PREG_DISP_MUTEX3_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX3_RST, *PREG_DISP_MUTEX3_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX3_CTL, *PREG_DISP_MUTEX3_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX3_MOD0, *PREG_DISP_MUTEX3_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX4_EN, *PREG_DISP_MUTEX4_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX4_RST, *PREG_DISP_MUTEX4_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX4_CTL, *PREG_DISP_MUTEX4_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX4_MOD0, *PREG_DISP_MUTEX4_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX5_EN, *PREG_DISP_MUTEX5_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX5_RST, *PREG_DISP_MUTEX5_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX5_CTL, *PREG_DISP_MUTEX5_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX5_MOD0, *PREG_DISP_MUTEX5_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX6_EN, *PREG_DISP_MUTEX6_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX6_RST, *PREG_DISP_MUTEX6_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX6_CTL, *PREG_DISP_MUTEX6_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX6_MOD0, *PREG_DISP_MUTEX6_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX7_EN, *PREG_DISP_MUTEX7_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX7_RST, *PREG_DISP_MUTEX7_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX7_CTL, *PREG_DISP_MUTEX7_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX7_MOD0, *PREG_DISP_MUTEX7_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX8_EN, *PREG_DISP_MUTEX8_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX8_RST, *PREG_DISP_MUTEX8_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX8_CTL, *PREG_DISP_MUTEX8_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX8_MOD0, *PREG_DISP_MUTEX8_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX9_EN, *PREG_DISP_MUTEX9_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_RST                 : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX9_RST, *PREG_DISP_MUTEX9_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_SOF                 : 3;
        FIELD MUTEX_SOF_TIMING          : 2;
        FIELD MUTEX_SOF_WAIT            : 1;
        FIELD MUTEX_EOF                 : 3;
        FIELD MUTEX_EOF_TIMING          : 2;
        FIELD MUTEX_EOF_WAIT            : 1;
        FIELD rsv_12                    : 20;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX9_CTL, *PREG_DISP_MUTEX9_CTL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD MUTEX_MOD0                : 32;
    } Bits;
    UINT32 Raw;
} REG_DISP_MUTEX9_MOD0, *PREG_DISP_MUTEX9_MOD0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD DEBUG_OUT_SEL             : 2;
        FIELD rsv_2                     : 14;
    } Bits;
    UINT32 Raw;
} REG_DEBUG_OUT_SEL, *PREG_DEBUG_OUT_SEL;

// ----------------- DISP_MUTEX  Grouping Definitions -------------------
typedef struct
{
    REG_INTSTA                      DISP_MUTEX_INTSTA;   //14001004
}MUTEX_STS, *PMUTEX_STS;

typedef struct
{
    REG_DISP_MUTEX0_EN              DISP_MUTEX0_EN;      //14001020
    REG_DISP_MUTEX1_EN              DISP_MUTEX1_EN;      //14001040
    REG_DISP_MUTEX2_EN              DISP_MUTEX2_EN;      //14001060
    REG_DISP_MUTEX3_EN              DISP_MUTEX3_EN;      //14001080
    REG_DISP_MUTEX4_EN              DISP_MUTEX4_EN;      //140010A0
    REG_DISP_MUTEX5_EN              DISP_MUTEX5_EN;      //140010C0
    REG_DISP_MUTEX6_EN              DISP_MUTEX6_EN;      //140010E0
    REG_DISP_MUTEX7_EN              DISP_MUTEX7_EN;      //14001100
    REG_DISP_MUTEX8_EN              DISP_MUTEX8_EN;      //14001120
    REG_DISP_MUTEX9_EN              DISP_MUTEX9_EN;      //14001140
}MUTEX_START, *PMUTEX_START;

typedef struct
{
    REG_INTEN                       DISP_MUTEX_INTEN;    //14001000
    REG_CFG                         DISP_MUTEX_CFG;      //14001008
    REG_DISP_MUTEX0_RST             DISP_MUTEX0_RST;     //14001028
    REG_DISP_MUTEX0_CTL             DISP_MUTEX0_CTL;     //1400102C
    REG_DISP_MUTEX0_MOD0            DISP_MUTEX0_MOD0;    //14001030
    REG_DISP_MUTEX1_RST             DISP_MUTEX1_RST;     //14001048
    REG_DISP_MUTEX1_CTL             DISP_MUTEX1_CTL;     //1400104C
    REG_DISP_MUTEX1_MOD0            DISP_MUTEX1_MOD0;    //14001050
    REG_DISP_MUTEX2_RST             DISP_MUTEX2_RST;     //14001068
    REG_DISP_MUTEX2_CTL             DISP_MUTEX2_CTL;     //1400106C
    REG_DISP_MUTEX2_MOD0            DISP_MUTEX2_MOD0;    //14001070
    REG_DISP_MUTEX3_RST             DISP_MUTEX3_RST;     //14001088
    REG_DISP_MUTEX3_CTL             DISP_MUTEX3_CTL;     //1400108C
    REG_DISP_MUTEX3_MOD0            DISP_MUTEX3_MOD0;    //14001090
    REG_DISP_MUTEX4_RST             DISP_MUTEX4_RST;     //140010A8
    REG_DISP_MUTEX4_CTL             DISP_MUTEX4_CTL;     //140010AC
    REG_DISP_MUTEX4_MOD0            DISP_MUTEX4_MOD0;    //140010B0
    REG_DISP_MUTEX5_RST             DISP_MUTEX5_RST;     //140010C8
    REG_DISP_MUTEX5_CTL             DISP_MUTEX5_CTL;     //140010CC
    REG_DISP_MUTEX5_MOD0            DISP_MUTEX5_MOD0;    //140010D0
    REG_DISP_MUTEX6_RST             DISP_MUTEX6_RST;     //140010E8
    REG_DISP_MUTEX6_CTL             DISP_MUTEX6_CTL;     //140010EC
    REG_DISP_MUTEX6_MOD0            DISP_MUTEX6_MOD0;    //140010F0
    REG_DISP_MUTEX7_RST             DISP_MUTEX7_RST;     //14001108
    REG_DISP_MUTEX7_CTL             DISP_MUTEX7_CTL;     //1400110C
    REG_DISP_MUTEX7_MOD0            DISP_MUTEX7_MOD0;    //14001110
    REG_DISP_MUTEX8_RST             DISP_MUTEX8_RST;     //14001128
    REG_DISP_MUTEX8_CTL             DISP_MUTEX8_CTL;     //1400112C
    REG_DISP_MUTEX8_MOD0            DISP_MUTEX8_MOD0;    //14001130
    REG_DISP_MUTEX9_RST             DISP_MUTEX9_RST;     //14001148
    REG_DISP_MUTEX9_CTL             DISP_MUTEX9_CTL;     //1400114C
    REG_DISP_MUTEX9_MOD0            DISP_MUTEX9_MOD0;    //14001150
    REG_DEBUG_OUT_SEL               DISP_MUTEX_DEBUG_OUT_SEL; //130C
}MUTEX_CFG, *PMUTEX_CFG;

// ----------------- DISP_MUTEX Register Definition -------------------
/* modify by RD */
typedef volatile PACKING struct
{
    REG_INTEN                       DISP_MUTEX_INTEN;    	//14016000
    REG_INTSTA                      DISP_MUTEX_INTSTA;   	//14016004
    REG_CFG                         DISP_MUTEX_CFG;      	//14016008
    UINT32                          rsv_100C[5];      		// 100C..101C
    REG_DISP_MUTEX0_EN              DISP_MUTEX0_EN;      	//14016020
    UINT32                          rsv_1024;         		// 1024
    REG_DISP_MUTEX0_RST             DISP_MUTEX0_RST;     	//14016028
    REG_DISP_MUTEX0_CTL             DISP_MUTEX0_CTL;     	//1401602C
    REG_DISP_MUTEX0_MOD0            DISP_MUTEX0_MOD0;    	//14016030
    UINT32                          rsv_6034[3];      		//14016034..603C
    REG_DISP_MUTEX1_EN              DISP_MUTEX1_EN;      	//14016040
    UINT32                          rsv_1044;         		// 1044
    REG_DISP_MUTEX1_RST             DISP_MUTEX1_RST;     	//14016048
    REG_DISP_MUTEX1_CTL             DISP_MUTEX1_CTL;     	//1401604C
    REG_DISP_MUTEX1_MOD0            DISP_MUTEX1_MOD0;    	//14016050
    UINT32                          rsv_6054[3];      		//14016054..605C
    REG_DISP_MUTEX2_EN              DISP_MUTEX2_EN;      	//14016060
    UINT32                          rsv_1064;         		// 1064
    REG_DISP_MUTEX2_RST             DISP_MUTEX2_RST;     	//14016068
    REG_DISP_MUTEX2_CTL             DISP_MUTEX2_CTL;     	//1401606C
    REG_DISP_MUTEX2_MOD0            DISP_MUTEX2_MOD0;    	//14016070
    UINT32                          rsv_6074[3];      		//14016074..607C
    REG_DISP_MUTEX3_EN              DISP_MUTEX3_EN;      	//14016080
    UINT32                          rsv_1084;         		// 1084
    REG_DISP_MUTEX3_RST             DISP_MUTEX3_RST;     	//14016088
    REG_DISP_MUTEX3_CTL             DISP_MUTEX3_CTL;     	//1401608C
    REG_DISP_MUTEX3_MOD0            DISP_MUTEX3_MOD0;    	//14016090
    UINT32                          rsv_6094[3];      		//14016094..609C
    REG_DISP_MUTEX4_EN              DISP_MUTEX4_EN;      	//140160A0
    UINT32                          rsv_10A4;         		// 10A4
    REG_DISP_MUTEX4_RST             DISP_MUTEX4_RST;     	//140160A8
    REG_DISP_MUTEX4_CTL             DISP_MUTEX4_CTL;     	//140160AC
    REG_DISP_MUTEX4_MOD0            DISP_MUTEX4_MOD0;    	//140160B0
    UINT32                          rsv_60B4[3];      		//140160B4..60BC
    REG_DISP_MUTEX5_EN              DISP_MUTEX5_EN;      	//140160C0
    UINT32                          rsv_10C4;         		// 10C4
    REG_DISP_MUTEX5_RST             DISP_MUTEX5_RST;     	//140160C8
    REG_DISP_MUTEX5_CTL             DISP_MUTEX5_CTL;     	//140160CC
    REG_DISP_MUTEX5_MOD0            DISP_MUTEX5_MOD0;    	//140160D0
    UINT32                          rsv_60D4[3];      		//140160D4..60DC
    REG_DISP_MUTEX6_EN              DISP_MUTEX6_EN;      	//140160E0
    UINT32                          rsv_10E4;         		// 10E4
    REG_DISP_MUTEX6_RST             DISP_MUTEX6_RST;     	//140160E8
    REG_DISP_MUTEX6_CTL             DISP_MUTEX6_CTL;     	//140160EC
    REG_DISP_MUTEX6_MOD0            DISP_MUTEX6_MOD0;    	//140160F0 
    UINT32                          rsv_60F4[3];      		//140160F4..60FC
    REG_DISP_MUTEX7_EN              DISP_MUTEX7_EN;      	//14016100
    UINT32                          rsv_1104;         		// 1104
    REG_DISP_MUTEX7_RST             DISP_MUTEX7_RST;     	//14016108
    REG_DISP_MUTEX7_CTL             DISP_MUTEX7_CTL;     	//1401610C
    REG_DISP_MUTEX7_MOD0            DISP_MUTEX7_MOD0;    	//14016110
    UINT32                          rsv_6114[3];      		//14016114..611C
    REG_DISP_MUTEX8_EN              DISP_MUTEX8_EN;      	//14016120
    UINT32                          rsv_1124;         		// 1124
    REG_DISP_MUTEX8_RST             DISP_MUTEX8_RST;     	//14016128
    REG_DISP_MUTEX8_CTL             DISP_MUTEX8_CTL;     	//1401612C
    REG_DISP_MUTEX8_MOD0            DISP_MUTEX8_MOD0;    	//14016130
    UINT32                          rsv_6134[3];      		//14016134..613C
    REG_DISP_MUTEX9_EN              DISP_MUTEX9_EN;      	//14016140
    UINT32                          rsv_1144;         		// 1144
    REG_DISP_MUTEX9_RST             DISP_MUTEX9_RST;     	//14016148
    REG_DISP_MUTEX9_CTL             DISP_MUTEX9_CTL;     	//1401614C
    REG_DISP_MUTEX9_MOD0            DISP_MUTEX9_MOD0;    	//14016150
    UINT32                          rsv_1154[110];    		// 1154..1308
    REG_DEBUG_OUT_SEL               DISP_MUTEX_DEBUG_OUT_SEL; //1401630C
}DISP_MUTEX_REGS, *PDISP_MUTEX_REGS;

// ---------- DISP_MUTEX Enum Definitions      ----------
// ---------- DISP_MUTEX C Macro Definitions   ----------
extern PDISP_MUTEX_REGS g_DISP_MUTEX_BASE;

#define DISP_MUTEX_BASE                                        (g_DISP_MUTEX_BASE)

#define DISP_MUTEX_INTEN                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX_INTEN) // 1000
#define DISP_MUTEX_INTSTA                                      (U32)(&DISP_MUTEX_BASE->DISP_MUTEX_INTSTA) // 1004
#define DISP_MUTEX_CFG                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX_CFG) // 1008
#define DISP_MUTEX0_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX0_EN) // 6020
#define DISP_MUTEX0_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX0_RST) // 6028
#define DISP_MUTEX0_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX0_CTL) // 602C
#define DISP_MUTEX0_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX0_MOD0) // 6030
#define DISP_MUTEX1_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX1_EN) // 6040
#define DISP_MUTEX1_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX1_RST) // 6048
#define DISP_MUTEX1_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX1_CTL) // 604C
#define DISP_MUTEX1_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX1_MOD0) // 6050
#define DISP_MUTEX2_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX2_EN) // 6060
#define DISP_MUTEX2_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX2_RST) // 6068
#define DISP_MUTEX2_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX2_CTL) // 606C
#define DISP_MUTEX2_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX2_MOD0) // 6070
#define DISP_MUTEX3_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX3_EN) // 6080
#define DISP_MUTEX3_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX3_RST) // 6088
#define DISP_MUTEX3_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX3_CTL) // 608C
#define DISP_MUTEX3_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX3_MOD0) // 6090
#define DISP_MUTEX4_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX4_EN) // 60A0
#define DISP_MUTEX4_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX4_RST) // 60A8
#define DISP_MUTEX4_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX4_CTL) // 60AC
#define DISP_MUTEX4_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX4_MOD0) // 60B0
#define DISP_MUTEX5_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX5_EN) // 60C0
#define DISP_MUTEX5_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX5_RST) // 60C8
#define DISP_MUTEX5_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX5_CTL) // 60CC
#define DISP_MUTEX5_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX5_MOD0) // 60D0
#define DISP_MUTEX6_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX6_EN) // 60E0
#define DISP_MUTEX6_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX6_RST) // 60E8
#define DISP_MUTEX6_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX6_CTL) // 60EC
#define DISP_MUTEX6_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX6_MOD0) // 60F0
#define DISP_MUTEX7_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX7_EN) // 6100
#define DISP_MUTEX7_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX7_RST) // 6108
#define DISP_MUTEX7_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX7_CTL) // 610C
#define DISP_MUTEX7_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX7_MOD0) // 6110
#define DISP_MUTEX8_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX8_EN) // 6120
#define DISP_MUTEX8_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX8_RST) // 6128
#define DISP_MUTEX8_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX8_CTL) // 612C
#define DISP_MUTEX8_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX8_MOD0) // 6130
#define DISP_MUTEX9_EN                                         (U32)(&DISP_MUTEX_BASE->DISP_MUTEX9_EN) // 6140
#define DISP_MUTEX9_RST                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX9_RST) // 6148
#define DISP_MUTEX9_CTL                                        (U32)(&DISP_MUTEX_BASE->DISP_MUTEX9_CTL) // 614C
#define DISP_MUTEX9_MOD0                                       (U32)(&DISP_MUTEX_BASE->DISP_MUTEX9_MOD0) // 6150
#define DEBUG_OUT_SEL                                          (U32)(&DISP_MUTEX_BASE->DEBUG_OUT_SEL) // 130C

#endif


#define INTEN_FLD_MUTEX_INTEN                                  REG_FLD(32, 0)

#define INTSTA_FLD_MUTEX_INTSTA                                REG_FLD(32, 0)

#define CFG_FLD_MUTEX_CFG                                      REG_FLD(1, 0)

#define DISP_MUTEX0_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX0_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX0_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX0_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX0_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX0_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX0_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX0_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX0_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DISP_MUTEX1_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX1_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX1_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX1_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX1_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX1_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX1_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX1_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX1_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DISP_MUTEX2_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX2_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX2_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX2_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX2_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX2_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX2_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX2_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX2_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DISP_MUTEX3_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX3_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX3_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX3_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX3_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX3_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX3_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX3_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX3_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DISP_MUTEX4_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX4_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX4_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX4_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX4_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX4_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX4_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX4_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX4_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DISP_MUTEX5_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX5_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX5_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX5_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX5_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX5_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX5_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX5_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX5_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DISP_MUTEX6_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX6_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX6_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX6_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX6_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX6_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX6_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX6_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX6_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DISP_MUTEX7_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX7_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX7_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX7_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX7_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX7_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX7_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX7_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX7_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DISP_MUTEX8_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX8_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX8_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX8_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX8_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX8_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX8_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX8_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX8_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DISP_MUTEX9_EN_FLD_MUTEX_EN                            REG_FLD(1, 0)

#define DISP_MUTEX9_RST_FLD_MUTEX_RST                          REG_FLD(1, 0)

#define DISP_MUTEX9_CTL_FLD_MUTEX_EOF_WAIT                     REG_FLD(1, 11)
#define DISP_MUTEX9_CTL_FLD_MUTEX_EOF_TIMING                   REG_FLD(2, 9)
#define DISP_MUTEX9_CTL_FLD_MUTEX_EOF                          REG_FLD(3, 6)
#define DISP_MUTEX9_CTL_FLD_MUTEX_SOF_WAIT                     REG_FLD(1, 5)
#define DISP_MUTEX9_CTL_FLD_MUTEX_SOF_TIMING                   REG_FLD(2, 3)
#define DISP_MUTEX9_CTL_FLD_MUTEX_SOF                          REG_FLD(3, 0)

#define DISP_MUTEX9_MOD0_FLD_MUTEX_MOD0                        REG_FLD(32, 0)

#define DEBUG_OUT_SEL_FLD_DEBUG_OUT_SEL                        REG_FLD(2, 0)

#define INTEN_GET_MUTEX_INTEN(reg32)                           REG_FLD_GET(INTEN_FLD_MUTEX_INTEN, (reg32))

#define INTSTA_GET_MUTEX_INTSTA(reg32)                         REG_FLD_GET(INTSTA_FLD_MUTEX_INTSTA, (reg32))

#define CFG_GET_MUTEX_CFG(reg32)                               REG_FLD_GET(CFG_FLD_MUTEX_CFG, (reg32))

#define DISP_MUTEX0_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX0_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX0_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX0_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX0_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX0_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX0_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX0_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX0_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX0_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX0_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX0_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX0_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX0_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX0_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX0_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX0_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX0_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DISP_MUTEX1_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX1_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX1_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX1_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX1_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX1_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX1_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX1_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX1_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX1_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX1_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX1_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX1_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX1_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX1_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX1_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX1_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX1_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DISP_MUTEX2_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX2_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX2_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX2_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX2_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX2_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX2_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX2_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX2_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX2_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX2_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX2_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX2_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX2_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX2_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX2_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX2_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX2_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DISP_MUTEX3_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX3_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX3_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX3_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX3_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX3_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX3_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX3_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX3_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX3_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX3_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX3_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX3_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX3_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX3_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX3_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX3_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX3_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DISP_MUTEX4_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX4_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX4_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX4_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX4_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX4_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX4_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX4_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX4_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX4_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX4_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX4_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX4_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX4_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX4_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX4_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX4_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX4_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DISP_MUTEX5_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX5_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX5_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX5_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX5_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX5_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX5_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX5_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX5_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX5_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX5_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX5_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX5_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX5_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX5_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX5_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX5_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX5_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DISP_MUTEX6_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX6_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX6_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX6_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX6_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX6_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX6_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX6_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX6_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX6_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX6_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX6_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX6_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX6_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX6_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX6_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX6_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX6_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DISP_MUTEX7_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX7_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX7_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX7_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX7_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX7_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX7_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX7_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX7_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX7_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX7_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX7_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX7_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX7_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX7_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX7_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX7_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX7_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DISP_MUTEX8_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX8_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX8_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX8_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX8_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX8_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX8_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX8_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX8_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX8_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX8_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX8_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX8_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX8_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX8_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX8_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX8_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX8_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DISP_MUTEX9_EN_GET_MUTEX_EN(reg32)                     REG_FLD_GET(DISP_MUTEX9_EN_FLD_MUTEX_EN, (reg32))

#define DISP_MUTEX9_RST_GET_MUTEX_RST(reg32)                   REG_FLD_GET(DISP_MUTEX9_RST_FLD_MUTEX_RST, (reg32))

#define DISP_MUTEX9_CTL_GET_MUTEX_EOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX9_CTL_FLD_MUTEX_EOF_WAIT, (reg32))
#define DISP_MUTEX9_CTL_GET_MUTEX_EOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX9_CTL_FLD_MUTEX_EOF_TIMING, (reg32))
#define DISP_MUTEX9_CTL_GET_MUTEX_EOF(reg32)                   REG_FLD_GET(DISP_MUTEX9_CTL_FLD_MUTEX_EOF, (reg32))
#define DISP_MUTEX9_CTL_GET_MUTEX_SOF_WAIT(reg32)              REG_FLD_GET(DISP_MUTEX9_CTL_FLD_MUTEX_SOF_WAIT, (reg32))
#define DISP_MUTEX9_CTL_GET_MUTEX_SOF_TIMING(reg32)            REG_FLD_GET(DISP_MUTEX9_CTL_FLD_MUTEX_SOF_TIMING, (reg32))
#define DISP_MUTEX9_CTL_GET_MUTEX_SOF(reg32)                   REG_FLD_GET(DISP_MUTEX9_CTL_FLD_MUTEX_SOF, (reg32))

#define DISP_MUTEX9_MOD0_GET_MUTEX_MOD0(reg32)                 REG_FLD_GET(DISP_MUTEX9_MOD0_FLD_MUTEX_MOD0, (reg32))

#define DEBUG_OUT_SEL_GET_DEBUG_OUT_SEL(reg32)                 REG_FLD_GET(DEBUG_OUT_SEL_FLD_DEBUG_OUT_SEL, (reg32))

#define INTEN_SET_MUTEX_INTEN(reg32, val)                      REG_FLD_SET(INTEN_FLD_MUTEX_INTEN, (reg32), (val))

#define INTSTA_SET_MUTEX_INTSTA(reg32, val)                    REG_FLD_SET(INTSTA_FLD_MUTEX_INTSTA, (reg32), (val))

#define CFG_SET_MUTEX_CFG(reg32, val)                          REG_FLD_SET(CFG_FLD_MUTEX_CFG, (reg32), (val))

#define DISP_MUTEX0_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX0_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX0_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX0_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX0_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX0_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX0_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX0_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX0_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX0_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX0_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX0_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX0_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX0_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX0_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX0_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX0_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX0_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DISP_MUTEX1_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX1_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX1_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX1_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX1_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX1_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX1_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX1_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX1_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX1_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX1_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX1_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX1_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX1_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX1_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX1_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX1_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX1_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DISP_MUTEX2_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX2_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX2_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX2_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX2_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX2_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX2_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX2_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX2_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX2_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX2_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX2_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX2_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX2_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX2_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX2_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX2_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX2_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DISP_MUTEX3_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX3_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX3_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX3_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX3_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX3_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX3_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX3_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX3_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX3_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX3_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX3_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX3_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX3_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX3_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX3_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX3_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX3_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DISP_MUTEX4_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX4_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX4_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX4_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX4_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX4_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX4_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX4_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX4_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX4_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX4_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX4_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX4_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX4_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX4_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX4_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX4_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX4_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DISP_MUTEX5_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX5_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX5_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX5_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX5_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX5_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX5_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX5_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX5_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX5_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX5_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX5_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX5_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX5_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX5_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX5_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX5_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX5_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DISP_MUTEX6_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX6_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX6_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX6_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX6_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX6_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX6_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX6_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX6_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX6_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX6_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX6_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX6_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX6_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX6_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX6_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX6_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX6_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DISP_MUTEX7_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX7_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX7_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX7_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX7_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX7_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX7_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX7_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX7_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX7_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX7_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX7_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX7_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX7_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX7_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX7_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX7_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX7_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DISP_MUTEX8_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX8_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX8_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX8_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX8_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX8_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX8_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX8_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX8_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX8_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX8_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX8_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX8_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX8_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX8_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX8_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX8_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX8_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DISP_MUTEX9_EN_SET_MUTEX_EN(reg32, val)                REG_FLD_SET(DISP_MUTEX9_EN_FLD_MUTEX_EN, (reg32), (val))

#define DISP_MUTEX9_RST_SET_MUTEX_RST(reg32, val)              REG_FLD_SET(DISP_MUTEX9_RST_FLD_MUTEX_RST, (reg32), (val))

#define DISP_MUTEX9_CTL_SET_MUTEX_EOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX9_CTL_FLD_MUTEX_EOF_WAIT, (reg32), (val))
#define DISP_MUTEX9_CTL_SET_MUTEX_EOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX9_CTL_FLD_MUTEX_EOF_TIMING, (reg32), (val))
#define DISP_MUTEX9_CTL_SET_MUTEX_EOF(reg32, val)              REG_FLD_SET(DISP_MUTEX9_CTL_FLD_MUTEX_EOF, (reg32), (val))
#define DISP_MUTEX9_CTL_SET_MUTEX_SOF_WAIT(reg32, val)         REG_FLD_SET(DISP_MUTEX9_CTL_FLD_MUTEX_SOF_WAIT, (reg32), (val))
#define DISP_MUTEX9_CTL_SET_MUTEX_SOF_TIMING(reg32, val)       REG_FLD_SET(DISP_MUTEX9_CTL_FLD_MUTEX_SOF_TIMING, (reg32), (val))
#define DISP_MUTEX9_CTL_SET_MUTEX_SOF(reg32, val)              REG_FLD_SET(DISP_MUTEX9_CTL_FLD_MUTEX_SOF, (reg32), (val))

#define DISP_MUTEX9_MOD0_SET_MUTEX_MOD0(reg32, val)            REG_FLD_SET(DISP_MUTEX9_MOD0_FLD_MUTEX_MOD0, (reg32), (val))

#define DEBUG_OUT_SEL_SET_DEBUG_OUT_SEL(reg32, val)            REG_FLD_SET(DEBUG_OUT_SEL_FLD_DEBUG_OUT_SEL, (reg32), (val))

#define INTEN_VAL_MUTEX_INTEN(val)                             REG_FLD_VAL(INTEN_FLD_MUTEX_INTEN, (val))

#define INTSTA_VAL_MUTEX_INTSTA(val)                           REG_FLD_VAL(INTSTA_FLD_MUTEX_INTSTA, (val))

#define CFG_VAL_MUTEX_CFG(val)                                 REG_FLD_VAL(CFG_FLD_MUTEX_CFG, (val))

#define DISP_MUTEX0_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX0_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX0_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX0_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX0_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX0_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX0_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX0_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX0_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX0_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX0_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX0_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX0_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX0_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX0_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX0_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX0_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX0_MOD0_FLD_MUTEX_MOD0, (val))

#define DISP_MUTEX1_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX1_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX1_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX1_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX1_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX1_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX1_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX1_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX1_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX1_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX1_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX1_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX1_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX1_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX1_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX1_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX1_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX1_MOD0_FLD_MUTEX_MOD0, (val))

#define DISP_MUTEX2_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX2_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX2_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX2_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX2_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX2_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX2_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX2_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX2_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX2_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX2_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX2_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX2_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX2_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX2_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX2_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX2_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX2_MOD0_FLD_MUTEX_MOD0, (val))

#define DISP_MUTEX3_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX3_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX3_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX3_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX3_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX3_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX3_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX3_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX3_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX3_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX3_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX3_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX3_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX3_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX3_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX3_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX3_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX3_MOD0_FLD_MUTEX_MOD0, (val))

#define DISP_MUTEX4_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX4_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX4_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX4_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX4_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX4_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX4_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX4_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX4_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX4_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX4_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX4_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX4_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX4_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX4_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX4_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX4_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX4_MOD0_FLD_MUTEX_MOD0, (val))

#define DISP_MUTEX5_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX5_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX5_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX5_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX5_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX5_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX5_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX5_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX5_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX5_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX5_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX5_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX5_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX5_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX5_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX5_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX5_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX5_MOD0_FLD_MUTEX_MOD0, (val))

#define DISP_MUTEX6_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX6_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX6_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX6_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX6_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX6_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX6_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX6_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX6_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX6_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX6_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX6_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX6_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX6_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX6_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX6_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX6_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX6_MOD0_FLD_MUTEX_MOD0, (val))

#define DISP_MUTEX7_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX7_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX7_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX7_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX7_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX7_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX7_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX7_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX7_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX7_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX7_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX7_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX7_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX7_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX7_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX7_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX7_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX7_MOD0_FLD_MUTEX_MOD0, (val))

#define DISP_MUTEX8_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX8_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX8_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX8_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX8_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX8_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX8_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX8_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX8_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX8_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX8_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX8_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX8_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX8_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX8_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX8_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX8_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX8_MOD0_FLD_MUTEX_MOD0, (val))

#define DISP_MUTEX9_EN_VAL_MUTEX_EN(val)                       REG_FLD_VAL(DISP_MUTEX9_EN_FLD_MUTEX_EN, (val))

#define DISP_MUTEX9_RST_VAL_MUTEX_RST(val)                     REG_FLD_VAL(DISP_MUTEX9_RST_FLD_MUTEX_RST, (val))

#define DISP_MUTEX9_CTL_VAL_MUTEX_EOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX9_CTL_FLD_MUTEX_EOF_WAIT, (val))
#define DISP_MUTEX9_CTL_VAL_MUTEX_EOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX9_CTL_FLD_MUTEX_EOF_TIMING, (val))
#define DISP_MUTEX9_CTL_VAL_MUTEX_EOF(val)                     REG_FLD_VAL(DISP_MUTEX9_CTL_FLD_MUTEX_EOF, (val))
#define DISP_MUTEX9_CTL_VAL_MUTEX_SOF_WAIT(val)                REG_FLD_VAL(DISP_MUTEX9_CTL_FLD_MUTEX_SOF_WAIT, (val))
#define DISP_MUTEX9_CTL_VAL_MUTEX_SOF_TIMING(val)              REG_FLD_VAL(DISP_MUTEX9_CTL_FLD_MUTEX_SOF_TIMING, (val))
#define DISP_MUTEX9_CTL_VAL_MUTEX_SOF(val)                     REG_FLD_VAL(DISP_MUTEX9_CTL_FLD_MUTEX_SOF, (val))

#define DISP_MUTEX9_MOD0_VAL_MUTEX_MOD0(val)                   REG_FLD_VAL(DISP_MUTEX9_MOD0_FLD_MUTEX_MOD0, (val))

#define DEBUG_OUT_SEL_VAL_DEBUG_OUT_SEL(val)                   REG_FLD_VAL(DEBUG_OUT_SEL_FLD_DEBUG_OUT_SEL, (val))

#ifdef __cplusplus
}
#endif

#endif // __DISP_MUTEX_REGS_H__
