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
#ifndef __DISP_SPLIT_REGS_H__
#define __DISP_SPLIT_REGS_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef REG_BASE_C_MODULE
// ----------------- DISP_SPLIT Bit Field Definitions -------------------

#define PACKING
typedef unsigned int FIELD;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SPLIT_EN                  : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_EN, *PDISP_SPLIT_REG_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SPLIT_RESET               : 1;
        FIELD rsv_1                     : 31;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_RESET, *PDISP_SPLIT_REG_RESET;

typedef PACKING union
{
    PACKING struct
    {
        FIELD IF_END_INT_EN             : 1;
        FIELD ROF_END_INT_EN            : 1;
        FIELD LOF_END_INT_EN            : 1;
        FIELD rsv_3                     : 29;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_INTEN, *PDISP_SPLIT_REG_INTEN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD IF_END_INT                : 1;
        FIELD ROF_END_INT               : 1;
        FIELD LOF_END_INT               : 1;
        FIELD rsv_3                     : 29;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_INTSTA, *PDISP_SPLIT_REG_INTSTA;

typedef PACKING union
{
    PACKING struct
    {
        FIELD IF_UNFINISH               : 1;
        FIELD ROF_UNFINISH              : 1;
        FIELD LOF_UNFINISH              : 1;
        FIELD rsv_3                     : 1;
        FIELD IN_READY                  : 1;
        FIELD IN_VALID                  : 1;
        FIELD OUT_RIGHT_READY           : 1;
        FIELD OUT_RIGHT_VALID           : 1;
        FIELD OUT_LEFT_READY            : 1;
        FIELD OUT_LEFT_VALID            : 1;
        FIELD INP_OUT_READY             : 1;
        FIELD INP_OUT_VALID             : 1;
        FIELD INP_IN_READY              : 1;
        FIELD INP_IN_VALID              : 1;
        FIELD OUTP_LEFT_OUT_READY       : 1;
        FIELD OUTP_LEFT_OUT_VALID       : 1;
        FIELD OUTP_LEFT_IN_READY        : 1;
        FIELD OUTP_LEFT_IN_VALID        : 1;
        FIELD OUTP_RIGHT_OUT_READY      : 1;
        FIELD OUTP_RIGHT_OUT_VALID      : 1;
        FIELD OUTP_RIGHT_IN_READY       : 1;
        FIELD OUTP_RIGHT_IN_VALID       : 1;
        FIELD SPLIT_RIGHT_OUT_READY     : 1;
        FIELD SPLIT_RIGHT_OUT_VALID     : 1;
        FIELD SPLIT_LEFT_OUT_READY      : 1;
        FIELD SPLIT_LEFT_OUT_VALID      : 1;
        FIELD SPLIT_IN_READY            : 1;
        FIELD SPLIT_IN_VALID            : 1;
        FIELD RIGHT_FRAME_EXIST         : 1;
        FIELD LEFT_FRAME_EXIST          : 1;
        FIELD ONLY_ONE_SIDE             : 1;
        FIELD rsv_31                    : 1;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_STATUS, *PDISP_SPLIT_REG_STATUS;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SWAP_EN                   : 1;
        FIELD EMPTY_FLAG_SEL            : 2;
        FIELD rsv_3                     : 5;
        FIELD STALL_CG_ON               : 1;
        FIELD rsv_9                     : 19;
        FIELD CHKSUM_EN                 : 1;
        FIELD CHKSUM_SEL                : 2;
        FIELD rsv_31                    : 1;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_CFG, *PDISP_SPLIT_REG_CFG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD INP_PIX_CNT               : 12;
        FIELD rsv_12                    : 4;
        FIELD INP_LINE_CNT              : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_INPUT_COUNT, *PDISP_SPLIT_REG_INPUT_COUNT;

typedef PACKING union
{
    PACKING struct
    {
        FIELD LEFT_OUTP_PIX_CNT         : 12;
        FIELD rsv_12                    : 4;
        FIELD LEFT_OUTP_LINE_CNT        : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_LEFT_OUTPUT_COUNT, *PDISP_SPLIT_REG_LEFT_OUTPUT_COUNT;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RIGHT_OUTP_PIX_CNT        : 12;
        FIELD rsv_12                    : 4;
        FIELD RIGHT_OUTP_LINE_CNT       : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_RIGHT_OUTPUT_COUNT, *PDISP_SPLIT_REG_RIGHT_OUTPUT_COUNT;

typedef PACKING union
{
    PACKING struct
    {
        FIELD CHKSUM                    : 24;
        FIELD rsv_24                    : 8;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_CHKSUM, *PDISP_SPLIT_REG_CHKSUM;

typedef PACKING union
{
    PACKING struct
    {
        FIELD HSIZE_R                   : 11;
        FIELD rsv_11                    : 5;
        FIELD HSIZE_L                   : 11;
        FIELD rsv_27                    : 5;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_HSIZE, *PDISP_SPLIT_REG_HSIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD VSIZE                     : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_VSIZE, *PDISP_SPLIT_REG_VSIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVERLAP_EN                : 1;
        FIELD rsv_1                     : 7;
        FIELD OVERLAP_LENGTH            : 8;
        FIELD rsv_16                    : 16;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_OVERLAP, *PDISP_SPLIT_REG_OVERLAP;

typedef PACKING union
{
    PACKING struct
    {
        FIELD HCNT_R_RIGHT              : 10;
        FIELD HCNT_R_LEFT               : 10;
        FIELD HCNT_R                    : 10;
        FIELD STATE_R                   : 2;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_INFO_A, *PDISP_SPLIT_REG_INFO_A;

typedef PACKING union
{
    PACKING struct
    {
        FIELD PCNT                      : 13;
        FIELD FIFO_EMPTY                : 1;
        FIELD FIFO0_EMPTY               : 1;
        FIELD FIFO1_EMPTY               : 1;
        FIELD HEND_R_RIGHT              : 1;
        FIELD HEND_R_LEFT               : 1;
        FIELD HEND_R                    : 1;
        FIELD rsv_19                    : 3;
        FIELD IBUF_FULL                 : 1;
        FIELD IBUF_WPTR                 : 1;
        FIELD IBUF_POP                  : 1;
        FIELD IBUF_PUSH                 : 1;
        FIELD FBUF_COND2                : 1;
        FIELD FBUF_TYPE                 : 1;
        FIELD FBUF_FULL                 : 1;
        FIELD FBUF_POP                  : 1;
        FIELD FBUF_PUSH_D1              : 1;
        FIELD FBUF_PUSH                 : 1;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_INFO_B, *PDISP_SPLIT_REG_INFO_B;

typedef PACKING union
{
    PACKING struct
    {
        FIELD FIFO0_WPTR                : 10;
        FIELD FIFO0_RPTR                : 10;
        FIELD FIFO1_RPTR                : 10;
        FIELD FIFO0_FULL                : 1;
        FIELD rsv_31                    : 1;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_INFO_C, *PDISP_SPLIT_REG_INFO_C;

typedef PACKING union
{
    PACKING struct
    {
        FIELD FORCE_COMMIT              : 1;
        FIELD BYPASS_SHADOW             : 1;
        FIELD READ_WRK_REG              : 1;
        FIELD rsv_3                     : 29;
    } Bits;
    UINT32 Raw;
} DISP_SPLIT_REG_SHADOW_CTRL, *PDISP_SPLIT_REG_SHADOW_CTRL;

// ----------------- DISP_SPLIT  Grouping Definitions -------------------
typedef struct
{
    DISP_SPLIT_REG_RESET            DISP_SPLIT_RESET;    //14013004
    DISP_SPLIT_REG_INTEN            DISP_SPLIT_INTEN;    //14013008
    DISP_SPLIT_REG_CFG              DISP_SPLIT_CFG;      //14013020
    DISP_SPLIT_REG_HSIZE            DISP_SPLIT_HSIZE;    //14013034
    DISP_SPLIT_REG_VSIZE            DISP_SPLIT_VSIZE;    //14013038
    DISP_SPLIT_REG_OVERLAP          DISP_SPLIT_OVERLAP;  //1401303C
    DISP_SPLIT_REG_INFO_A           DISP_SPLIT_INFO_A;   //14013040
    DISP_SPLIT_REG_INFO_B           DISP_SPLIT_INFO_B;   //14013044
    DISP_SPLIT_REG_INFO_C           DISP_SPLIT_INFO_C;   //14013048
    DISP_SPLIT_REG_SHADOW_CTRL      DISP_SPLIT_SHADOW_CTRL; //14013080
}DISP_SPLIT_SPLIT_CFG, *PDISP_SPLIT_SPLIT_CFG;

typedef struct
{
    DISP_SPLIT_REG_INTSTA           DISP_SPLIT_INTSTA;   //1401300C
    DISP_SPLIT_REG_STATUS           DISP_SPLIT_STATUS;   //14013010
    DISP_SPLIT_REG_INPUT_COUNT      DISP_SPLIT_INPUT_COUNT; //14013024
    DISP_SPLIT_REG_LEFT_OUTPUT_COUNT DISP_SPLIT_LEFT_OUTPUT_COUNT; //14013028
    DISP_SPLIT_REG_RIGHT_OUTPUT_COUNT DISP_SPLIT_RIGHT_OUTPUT_COUNT; //1401302C
    DISP_SPLIT_REG_CHKSUM           DISP_SPLIT_CHKSUM;   //14013030
}DISP_SPLIT_SPLIT_STATUS, *PDISP_SPLIT_SPLIT_STATUS;

typedef struct
{
    DISP_SPLIT_REG_EN               DISP_SPLIT_EN;       //14013000
}DISP_SPLIT_SPLIT_START, *PDISP_SPLIT_SPLIT_START;

// ----------------- DISP_SPLIT Register Definition -------------------
/* modify by RD */
typedef volatile PACKING struct
{
	DISP_SPLIT_REG_EN				EN;		 //14013000
    DISP_SPLIT_REG_RESET            RESET;    //14013004
    DISP_SPLIT_REG_INTEN            INTEN;    //14013008
    DISP_SPLIT_REG_INTSTA           INTSTA;   //1401300C
    DISP_SPLIT_REG_STATUS           STATUS;   //14013010
    UINT32                          rsv_3014[3];         //3014..301C
    DISP_SPLIT_REG_CFG              CFG;      //14013020
    DISP_SPLIT_REG_INPUT_COUNT      INPUT_COUNT; 		//14013024
    DISP_SPLIT_REG_LEFT_OUTPUT_COUNT LEFT_OUTPUT_COUNT; 	//14013028
    DISP_SPLIT_REG_RIGHT_OUTPUT_COUNT RIGHT_OUTPUT_COUNT;//1401302C
    DISP_SPLIT_REG_CHKSUM           CHKSUM;   //14013030
    DISP_SPLIT_REG_HSIZE            HSIZE;    //14013034
    DISP_SPLIT_REG_VSIZE            VSIZE;    //14013038
    DISP_SPLIT_REG_OVERLAP          OVERLAP;  //1401303C
    DISP_SPLIT_REG_INFO_A           INFO_A;   //14013040
    DISP_SPLIT_REG_INFO_B           INFO_B;   //14013044
    DISP_SPLIT_REG_INFO_C           INFO_C;   //14013048
    UINT32                          rsv_304C[13];     	 //304C..307C
	DISP_SPLIT_REG_SHADOW_CTRL		SHADOW_CTRL; //14013080
}DISP_SPLIT_REGS, *PDISP_SPLIT_REGS;

// ---------- DISP_SPLIT Enum Definitions      ----------
// ---------- DISP_SPLIT C Macro Definitions   ----------
extern PDISP_SPLIT_REGS g_DISP_SPLIT_BASE;

#define DISP_SPLIT_BASE                                        (g_DISP_SPLIT_BASE)

#define DISP_SPLIT_EN                                          (U32)(&DISP_SPLIT_BASE->EN) // 3000
#define DISP_SPLIT_RESET                                       (U32)(&DISP_SPLIT_BASE->RESET) // 3004
#define DISP_SPLIT_INTEN                                       (U32)(&DISP_SPLIT_BASE->INTEN) // 3008
#define DISP_SPLIT_INTSTA                                      (U32)(&DISP_SPLIT_BASE->INTSTA) // 300C
#define DISP_SPLIT_STATUS                                      (U32)(&DISP_SPLIT_BASE->STATUS) // 3010
#define DISP_SPLIT_CFG                                         (U32)(&DISP_SPLIT_BASE->CFG) // 3020
#define DISP_SPLIT_INPUT_COUNT                                 (U32)(&DISP_SPLIT_BASE->INPUT_COUNT) // 3024
#define DISP_SPLIT_LEFT_OUTPUT_COUNT                           (U32)(&DISP_SPLIT_BASE->LEFT_OUTPUT_COUNT) // 3028
#define DISP_SPLIT_RIGHT_OUTPUT_COUNT                          (U32)(&DISP_SPLIT_BASE->RIGHT_OUTPUT_COUNT) // 302C
#define DISP_SPLIT_CHKSUM                                      (U32)(&DISP_SPLIT_BASE->CHKSUM) // 3030
#define DISP_SPLIT_HSIZE                                       (U32)(&DISP_SPLIT_BASE->HSIZE) // 3034
#define DISP_SPLIT_VSIZE                                       (U32)(&DISP_SPLIT_BASE->VSIZE) // 3038
#define DISP_SPLIT_OVERLAP                                     (U32)(&DISP_SPLIT_BASE->OVERLAP) // 303C
#define DISP_SPLIT_INFO_A                                      (U32)(&DISP_SPLIT_BASE->INFO_A) // 3040
#define DISP_SPLIT_INFO_B                                      (U32)(&DISP_SPLIT_BASE->INFO_B) // 3044
#define DISP_SPLIT_INFO_C                                      (U32)(&DISP_SPLIT_BASE->INFO_C) // 3048
#define DISP_SPLIT_SHADOW_CTRL                                 (U32)(&DISP_SPLIT_BASE->SHADOW_CTRL) // 3080

#endif


#define EN_FLD_SPLIT_EN                                        REG_FLD(1, 0)

#define RESET_FLD_SPLIT_RESET                                  REG_FLD(1, 0)

#define INTEN_FLD_LOF_END_INT_EN                               REG_FLD(1, 2)
#define INTEN_FLD_ROF_END_INT_EN                               REG_FLD(1, 1)
#define INTEN_FLD_IF_END_INT_EN                                REG_FLD(1, 0)

#define INTSTA_FLD_LOF_END_INT                                 REG_FLD(1, 2)
#define INTSTA_FLD_ROF_END_INT                                 REG_FLD(1, 1)
#define INTSTA_FLD_IF_END_INT                                  REG_FLD(1, 0)

#define STATUS_FLD_ONLY_ONE_SIDE                               REG_FLD(1, 30)
#define STATUS_FLD_LEFT_FRAME_EXIST                            REG_FLD(1, 29)
#define STATUS_FLD_RIGHT_FRAME_EXIST                           REG_FLD(1, 28)
#define STATUS_FLD_SPLIT_IN_VALID                              REG_FLD(1, 27)
#define STATUS_FLD_SPLIT_IN_READY                              REG_FLD(1, 26)
#define STATUS_FLD_SPLIT_LEFT_OUT_VALID                        REG_FLD(1, 25)
#define STATUS_FLD_SPLIT_LEFT_OUT_READY                        REG_FLD(1, 24)
#define STATUS_FLD_SPLIT_RIGHT_OUT_VALID                       REG_FLD(1, 23)
#define STATUS_FLD_SPLIT_RIGHT_OUT_READY                       REG_FLD(1, 22)
#define STATUS_FLD_OUTP_RIGHT_IN_VALID                         REG_FLD(1, 21)
#define STATUS_FLD_OUTP_RIGHT_IN_READY                         REG_FLD(1, 20)
#define STATUS_FLD_OUTP_RIGHT_OUT_VALID                        REG_FLD(1, 19)
#define STATUS_FLD_OUTP_RIGHT_OUT_READY                        REG_FLD(1, 18)
#define STATUS_FLD_OUTP_LEFT_IN_VALID                          REG_FLD(1, 17)
#define STATUS_FLD_OUTP_LEFT_IN_READY                          REG_FLD(1, 16)
#define STATUS_FLD_OUTP_LEFT_OUT_VALID                         REG_FLD(1, 15)
#define STATUS_FLD_OUTP_LEFT_OUT_READY                         REG_FLD(1, 14)
#define STATUS_FLD_INP_IN_VALID                                REG_FLD(1, 13)
#define STATUS_FLD_INP_IN_READY                                REG_FLD(1, 12)
#define STATUS_FLD_INP_OUT_VALID                               REG_FLD(1, 11)
#define STATUS_FLD_INP_OUT_READY                               REG_FLD(1, 10)
#define STATUS_FLD_OUT_LEFT_VALID                              REG_FLD(1, 9)
#define STATUS_FLD_OUT_LEFT_READY                              REG_FLD(1, 8)
#define STATUS_FLD_OUT_RIGHT_VALID                             REG_FLD(1, 7)
#define STATUS_FLD_OUT_RIGHT_READY                             REG_FLD(1, 6)
#define STATUS_FLD_IN_VALID                                    REG_FLD(1, 5)
#define STATUS_FLD_IN_READY                                    REG_FLD(1, 4)
#define STATUS_FLD_LOF_UNFINISH                                REG_FLD(1, 2)
#define STATUS_FLD_ROF_UNFINISH                                REG_FLD(1, 1)
#define STATUS_FLD_IF_UNFINISH                                 REG_FLD(1, 0)

#define CFG_FLD_CHKSUM_SEL                                     REG_FLD(2, 29)
#define CFG_FLD_CHKSUM_EN                                      REG_FLD(1, 28)
#define CFG_FLD_STALL_CG_ON                                    REG_FLD(1, 8)
#define CFG_FLD_EMPTY_FLAG_SEL                                 REG_FLD(2, 1)
#define CFG_FLD_SWAP_EN                                        REG_FLD(1, 0)

#define INPUT_COUNT_FLD_INP_LINE_CNT                           REG_FLD(13, 16)
#define INPUT_COUNT_FLD_INP_PIX_CNT                            REG_FLD(12, 0)

#define LEFT_OUTPUT_COUNT_FLD_LEFT_OUTP_LINE_CNT               REG_FLD(13, 16)
#define LEFT_OUTPUT_COUNT_FLD_LEFT_OUTP_PIX_CNT                REG_FLD(12, 0)

#define RIGHT_OUTPUT_COUNT_FLD_RIGHT_OUTP_LINE_CNT             REG_FLD(13, 16)
#define RIGHT_OUTPUT_COUNT_FLD_RIGHT_OUTP_PIX_CNT              REG_FLD(12, 0)

#define CHKSUM_FLD_CHKSUM                                      REG_FLD(24, 0)

#define HSIZE_FLD_HSIZE_L                                      REG_FLD(11, 16)
#define HSIZE_FLD_HSIZE_R                                      REG_FLD(11, 0)

#define VSIZE_FLD_VSIZE                                        REG_FLD(13, 0)

#define OVERLAP_FLD_OVERLAP_LENGTH                             REG_FLD(8, 8)
#define OVERLAP_FLD_OVERLAP_EN                                 REG_FLD(1, 0)

#define INFO_A_FLD_STATE_R                                     REG_FLD(2, 30)
#define INFO_A_FLD_HCNT_R                                      REG_FLD(10, 20)
#define INFO_A_FLD_HCNT_R_LEFT                                 REG_FLD(10, 10)
#define INFO_A_FLD_HCNT_R_RIGHT                                REG_FLD(10, 0)

#define INFO_B_FLD_FBUF_PUSH                                   REG_FLD(1, 31)
#define INFO_B_FLD_FBUF_PUSH_D1                                REG_FLD(1, 30)
#define INFO_B_FLD_FBUF_POP                                    REG_FLD(1, 29)
#define INFO_B_FLD_FBUF_FULL                                   REG_FLD(1, 28)
#define INFO_B_FLD_FBUF_TYPE                                   REG_FLD(1, 27)
#define INFO_B_FLD_FBUF_COND2                                  REG_FLD(1, 26)
#define INFO_B_FLD_IBUF_PUSH                                   REG_FLD(1, 25)
#define INFO_B_FLD_IBUF_POP                                    REG_FLD(1, 24)
#define INFO_B_FLD_IBUF_WPTR                                   REG_FLD(1, 23)
#define INFO_B_FLD_IBUF_FULL                                   REG_FLD(1, 22)
#define INFO_B_FLD_HEND_R                                      REG_FLD(1, 18)
#define INFO_B_FLD_HEND_R_LEFT                                 REG_FLD(1, 17)
#define INFO_B_FLD_HEND_R_RIGHT                                REG_FLD(1, 16)
#define INFO_B_FLD_FIFO1_EMPTY                                 REG_FLD(1, 15)
#define INFO_B_FLD_FIFO0_EMPTY                                 REG_FLD(1, 14)
#define INFO_B_FLD_FIFO_EMPTY                                  REG_FLD(1, 13)
#define INFO_B_FLD_PCNT                                        REG_FLD(13, 0)

#define INFO_C_FLD_FIFO0_FULL                                  REG_FLD(1, 30)
#define INFO_C_FLD_FIFO1_RPTR                                  REG_FLD(10, 20)
#define INFO_C_FLD_FIFO0_RPTR                                  REG_FLD(10, 10)
#define INFO_C_FLD_FIFO0_WPTR                                  REG_FLD(10, 0)

#define SHADOW_CTRL_FLD_READ_WRK_REG                           REG_FLD(1, 2)
#define SHADOW_CTRL_FLD_BYPASS_SHADOW                          REG_FLD(1, 1)
#define SHADOW_CTRL_FLD_FORCE_COMMIT                           REG_FLD(1, 0)

#define EN_GET_SPLIT_EN(reg32)                                 REG_FLD_GET(EN_FLD_SPLIT_EN, (reg32))

#define RESET_GET_SPLIT_RESET(reg32)                           REG_FLD_GET(RESET_FLD_SPLIT_RESET, (reg32))

#define INTEN_GET_LOF_END_INT_EN(reg32)                        REG_FLD_GET(INTEN_FLD_LOF_END_INT_EN, (reg32))
#define INTEN_GET_ROF_END_INT_EN(reg32)                        REG_FLD_GET(INTEN_FLD_ROF_END_INT_EN, (reg32))
#define INTEN_GET_IF_END_INT_EN(reg32)                         REG_FLD_GET(INTEN_FLD_IF_END_INT_EN, (reg32))

#define INTSTA_GET_LOF_END_INT(reg32)                          REG_FLD_GET(INTSTA_FLD_LOF_END_INT, (reg32))
#define INTSTA_GET_ROF_END_INT(reg32)                          REG_FLD_GET(INTSTA_FLD_ROF_END_INT, (reg32))
#define INTSTA_GET_IF_END_INT(reg32)                           REG_FLD_GET(INTSTA_FLD_IF_END_INT, (reg32))

#define STATUS_GET_ONLY_ONE_SIDE(reg32)                        REG_FLD_GET(STATUS_FLD_ONLY_ONE_SIDE, (reg32))
#define STATUS_GET_LEFT_FRAME_EXIST(reg32)                     REG_FLD_GET(STATUS_FLD_LEFT_FRAME_EXIST, (reg32))
#define STATUS_GET_RIGHT_FRAME_EXIST(reg32)                    REG_FLD_GET(STATUS_FLD_RIGHT_FRAME_EXIST, (reg32))
#define STATUS_GET_SPLIT_IN_VALID(reg32)                       REG_FLD_GET(STATUS_FLD_SPLIT_IN_VALID, (reg32))
#define STATUS_GET_SPLIT_IN_READY(reg32)                       REG_FLD_GET(STATUS_FLD_SPLIT_IN_READY, (reg32))
#define STATUS_GET_SPLIT_LEFT_OUT_VALID(reg32)                 REG_FLD_GET(STATUS_FLD_SPLIT_LEFT_OUT_VALID, (reg32))
#define STATUS_GET_SPLIT_LEFT_OUT_READY(reg32)                 REG_FLD_GET(STATUS_FLD_SPLIT_LEFT_OUT_READY, (reg32))
#define STATUS_GET_SPLIT_RIGHT_OUT_VALID(reg32)                REG_FLD_GET(STATUS_FLD_SPLIT_RIGHT_OUT_VALID, (reg32))
#define STATUS_GET_SPLIT_RIGHT_OUT_READY(reg32)                REG_FLD_GET(STATUS_FLD_SPLIT_RIGHT_OUT_READY, (reg32))
#define STATUS_GET_OUTP_RIGHT_IN_VALID(reg32)                  REG_FLD_GET(STATUS_FLD_OUTP_RIGHT_IN_VALID, (reg32))
#define STATUS_GET_OUTP_RIGHT_IN_READY(reg32)                  REG_FLD_GET(STATUS_FLD_OUTP_RIGHT_IN_READY, (reg32))
#define STATUS_GET_OUTP_RIGHT_OUT_VALID(reg32)                 REG_FLD_GET(STATUS_FLD_OUTP_RIGHT_OUT_VALID, (reg32))
#define STATUS_GET_OUTP_RIGHT_OUT_READY(reg32)                 REG_FLD_GET(STATUS_FLD_OUTP_RIGHT_OUT_READY, (reg32))
#define STATUS_GET_OUTP_LEFT_IN_VALID(reg32)                   REG_FLD_GET(STATUS_FLD_OUTP_LEFT_IN_VALID, (reg32))
#define STATUS_GET_OUTP_LEFT_IN_READY(reg32)                   REG_FLD_GET(STATUS_FLD_OUTP_LEFT_IN_READY, (reg32))
#define STATUS_GET_OUTP_LEFT_OUT_VALID(reg32)                  REG_FLD_GET(STATUS_FLD_OUTP_LEFT_OUT_VALID, (reg32))
#define STATUS_GET_OUTP_LEFT_OUT_READY(reg32)                  REG_FLD_GET(STATUS_FLD_OUTP_LEFT_OUT_READY, (reg32))
#define STATUS_GET_INP_IN_VALID(reg32)                         REG_FLD_GET(STATUS_FLD_INP_IN_VALID, (reg32))
#define STATUS_GET_INP_IN_READY(reg32)                         REG_FLD_GET(STATUS_FLD_INP_IN_READY, (reg32))
#define STATUS_GET_INP_OUT_VALID(reg32)                        REG_FLD_GET(STATUS_FLD_INP_OUT_VALID, (reg32))
#define STATUS_GET_INP_OUT_READY(reg32)                        REG_FLD_GET(STATUS_FLD_INP_OUT_READY, (reg32))
#define STATUS_GET_OUT_LEFT_VALID(reg32)                       REG_FLD_GET(STATUS_FLD_OUT_LEFT_VALID, (reg32))
#define STATUS_GET_OUT_LEFT_READY(reg32)                       REG_FLD_GET(STATUS_FLD_OUT_LEFT_READY, (reg32))
#define STATUS_GET_OUT_RIGHT_VALID(reg32)                      REG_FLD_GET(STATUS_FLD_OUT_RIGHT_VALID, (reg32))
#define STATUS_GET_OUT_RIGHT_READY(reg32)                      REG_FLD_GET(STATUS_FLD_OUT_RIGHT_READY, (reg32))
#define STATUS_GET_IN_VALID(reg32)                             REG_FLD_GET(STATUS_FLD_IN_VALID, (reg32))
#define STATUS_GET_IN_READY(reg32)                             REG_FLD_GET(STATUS_FLD_IN_READY, (reg32))
#define STATUS_GET_LOF_UNFINISH(reg32)                         REG_FLD_GET(STATUS_FLD_LOF_UNFINISH, (reg32))
#define STATUS_GET_ROF_UNFINISH(reg32)                         REG_FLD_GET(STATUS_FLD_ROF_UNFINISH, (reg32))
#define STATUS_GET_IF_UNFINISH(reg32)                          REG_FLD_GET(STATUS_FLD_IF_UNFINISH, (reg32))

#define CFG_GET_CHKSUM_SEL(reg32)                              REG_FLD_GET(CFG_FLD_CHKSUM_SEL, (reg32))
#define CFG_GET_CHKSUM_EN(reg32)                               REG_FLD_GET(CFG_FLD_CHKSUM_EN, (reg32))
#define CFG_GET_STALL_CG_ON(reg32)                             REG_FLD_GET(CFG_FLD_STALL_CG_ON, (reg32))
#define CFG_GET_EMPTY_FLAG_SEL(reg32)                          REG_FLD_GET(CFG_FLD_EMPTY_FLAG_SEL, (reg32))
#define CFG_GET_SWAP_EN(reg32)                                 REG_FLD_GET(CFG_FLD_SWAP_EN, (reg32))

#define INPUT_COUNT_GET_INP_LINE_CNT(reg32)                    REG_FLD_GET(INPUT_COUNT_FLD_INP_LINE_CNT, (reg32))
#define INPUT_COUNT_GET_INP_PIX_CNT(reg32)                     REG_FLD_GET(INPUT_COUNT_FLD_INP_PIX_CNT, (reg32))

#define LEFT_OUTPUT_COUNT_GET_LEFT_OUTP_LINE_CNT(reg32)        REG_FLD_GET(LEFT_OUTPUT_COUNT_FLD_LEFT_OUTP_LINE_CNT, (reg32))
#define LEFT_OUTPUT_COUNT_GET_LEFT_OUTP_PIX_CNT(reg32)         REG_FLD_GET(LEFT_OUTPUT_COUNT_FLD_LEFT_OUTP_PIX_CNT, (reg32))

#define RIGHT_OUTPUT_COUNT_GET_RIGHT_OUTP_LINE_CNT(reg32)      REG_FLD_GET(RIGHT_OUTPUT_COUNT_FLD_RIGHT_OUTP_LINE_CNT, (reg32))
#define RIGHT_OUTPUT_COUNT_GET_RIGHT_OUTP_PIX_CNT(reg32)       REG_FLD_GET(RIGHT_OUTPUT_COUNT_FLD_RIGHT_OUTP_PIX_CNT, (reg32))

#define CHKSUM_GET_CHKSUM(reg32)                               REG_FLD_GET(CHKSUM_FLD_CHKSUM, (reg32))

#define HSIZE_GET_HSIZE_L(reg32)                               REG_FLD_GET(HSIZE_FLD_HSIZE_L, (reg32))
#define HSIZE_GET_HSIZE_R(reg32)                               REG_FLD_GET(HSIZE_FLD_HSIZE_R, (reg32))

#define VSIZE_GET_VSIZE(reg32)                                 REG_FLD_GET(VSIZE_FLD_VSIZE, (reg32))

#define OVERLAP_GET_OVERLAP_LENGTH(reg32)                      REG_FLD_GET(OVERLAP_FLD_OVERLAP_LENGTH, (reg32))
#define OVERLAP_GET_OVERLAP_EN(reg32)                          REG_FLD_GET(OVERLAP_FLD_OVERLAP_EN, (reg32))

#define INFO_A_GET_STATE_R(reg32)                              REG_FLD_GET(INFO_A_FLD_STATE_R, (reg32))
#define INFO_A_GET_HCNT_R(reg32)                               REG_FLD_GET(INFO_A_FLD_HCNT_R, (reg32))
#define INFO_A_GET_HCNT_R_LEFT(reg32)                          REG_FLD_GET(INFO_A_FLD_HCNT_R_LEFT, (reg32))
#define INFO_A_GET_HCNT_R_RIGHT(reg32)                         REG_FLD_GET(INFO_A_FLD_HCNT_R_RIGHT, (reg32))

#define INFO_B_GET_FBUF_PUSH(reg32)                            REG_FLD_GET(INFO_B_FLD_FBUF_PUSH, (reg32))
#define INFO_B_GET_FBUF_PUSH_D1(reg32)                         REG_FLD_GET(INFO_B_FLD_FBUF_PUSH_D1, (reg32))
#define INFO_B_GET_FBUF_POP(reg32)                             REG_FLD_GET(INFO_B_FLD_FBUF_POP, (reg32))
#define INFO_B_GET_FBUF_FULL(reg32)                            REG_FLD_GET(INFO_B_FLD_FBUF_FULL, (reg32))
#define INFO_B_GET_FBUF_TYPE(reg32)                            REG_FLD_GET(INFO_B_FLD_FBUF_TYPE, (reg32))
#define INFO_B_GET_FBUF_COND2(reg32)                           REG_FLD_GET(INFO_B_FLD_FBUF_COND2, (reg32))
#define INFO_B_GET_IBUF_PUSH(reg32)                            REG_FLD_GET(INFO_B_FLD_IBUF_PUSH, (reg32))
#define INFO_B_GET_IBUF_POP(reg32)                             REG_FLD_GET(INFO_B_FLD_IBUF_POP, (reg32))
#define INFO_B_GET_IBUF_WPTR(reg32)                            REG_FLD_GET(INFO_B_FLD_IBUF_WPTR, (reg32))
#define INFO_B_GET_IBUF_FULL(reg32)                            REG_FLD_GET(INFO_B_FLD_IBUF_FULL, (reg32))
#define INFO_B_GET_HEND_R(reg32)                               REG_FLD_GET(INFO_B_FLD_HEND_R, (reg32))
#define INFO_B_GET_HEND_R_LEFT(reg32)                          REG_FLD_GET(INFO_B_FLD_HEND_R_LEFT, (reg32))
#define INFO_B_GET_HEND_R_RIGHT(reg32)                         REG_FLD_GET(INFO_B_FLD_HEND_R_RIGHT, (reg32))
#define INFO_B_GET_FIFO1_EMPTY(reg32)                          REG_FLD_GET(INFO_B_FLD_FIFO1_EMPTY, (reg32))
#define INFO_B_GET_FIFO0_EMPTY(reg32)                          REG_FLD_GET(INFO_B_FLD_FIFO0_EMPTY, (reg32))
#define INFO_B_GET_FIFO_EMPTY(reg32)                           REG_FLD_GET(INFO_B_FLD_FIFO_EMPTY, (reg32))
#define INFO_B_GET_PCNT(reg32)                                 REG_FLD_GET(INFO_B_FLD_PCNT, (reg32))

#define INFO_C_GET_FIFO0_FULL(reg32)                           REG_FLD_GET(INFO_C_FLD_FIFO0_FULL, (reg32))
#define INFO_C_GET_FIFO1_RPTR(reg32)                           REG_FLD_GET(INFO_C_FLD_FIFO1_RPTR, (reg32))
#define INFO_C_GET_FIFO0_RPTR(reg32)                           REG_FLD_GET(INFO_C_FLD_FIFO0_RPTR, (reg32))
#define INFO_C_GET_FIFO0_WPTR(reg32)                           REG_FLD_GET(INFO_C_FLD_FIFO0_WPTR, (reg32))

#define SHADOW_CTRL_GET_READ_WRK_REG(reg32)                    REG_FLD_GET(SHADOW_CTRL_FLD_READ_WRK_REG, (reg32))
#define SHADOW_CTRL_GET_BYPASS_SHADOW(reg32)                   REG_FLD_GET(SHADOW_CTRL_FLD_BYPASS_SHADOW, (reg32))
#define SHADOW_CTRL_GET_FORCE_COMMIT(reg32)                    REG_FLD_GET(SHADOW_CTRL_FLD_FORCE_COMMIT, (reg32))

#define EN_SET_SPLIT_EN(reg32, val)                            REG_FLD_SET(EN_FLD_SPLIT_EN, (reg32), (val))

#define RESET_SET_SPLIT_RESET(reg32, val)                      REG_FLD_SET(RESET_FLD_SPLIT_RESET, (reg32), (val))

#define INTEN_SET_LOF_END_INT_EN(reg32, val)                   REG_FLD_SET(INTEN_FLD_LOF_END_INT_EN, (reg32), (val))
#define INTEN_SET_ROF_END_INT_EN(reg32, val)                   REG_FLD_SET(INTEN_FLD_ROF_END_INT_EN, (reg32), (val))
#define INTEN_SET_IF_END_INT_EN(reg32, val)                    REG_FLD_SET(INTEN_FLD_IF_END_INT_EN, (reg32), (val))

#define INTSTA_SET_LOF_END_INT(reg32, val)                     REG_FLD_SET(INTSTA_FLD_LOF_END_INT, (reg32), (val))
#define INTSTA_SET_ROF_END_INT(reg32, val)                     REG_FLD_SET(INTSTA_FLD_ROF_END_INT, (reg32), (val))
#define INTSTA_SET_IF_END_INT(reg32, val)                      REG_FLD_SET(INTSTA_FLD_IF_END_INT, (reg32), (val))

#define STATUS_SET_ONLY_ONE_SIDE(reg32, val)                   REG_FLD_SET(STATUS_FLD_ONLY_ONE_SIDE, (reg32), (val))
#define STATUS_SET_LEFT_FRAME_EXIST(reg32, val)                REG_FLD_SET(STATUS_FLD_LEFT_FRAME_EXIST, (reg32), (val))
#define STATUS_SET_RIGHT_FRAME_EXIST(reg32, val)               REG_FLD_SET(STATUS_FLD_RIGHT_FRAME_EXIST, (reg32), (val))
#define STATUS_SET_SPLIT_IN_VALID(reg32, val)                  REG_FLD_SET(STATUS_FLD_SPLIT_IN_VALID, (reg32), (val))
#define STATUS_SET_SPLIT_IN_READY(reg32, val)                  REG_FLD_SET(STATUS_FLD_SPLIT_IN_READY, (reg32), (val))
#define STATUS_SET_SPLIT_LEFT_OUT_VALID(reg32, val)            REG_FLD_SET(STATUS_FLD_SPLIT_LEFT_OUT_VALID, (reg32), (val))
#define STATUS_SET_SPLIT_LEFT_OUT_READY(reg32, val)            REG_FLD_SET(STATUS_FLD_SPLIT_LEFT_OUT_READY, (reg32), (val))
#define STATUS_SET_SPLIT_RIGHT_OUT_VALID(reg32, val)           REG_FLD_SET(STATUS_FLD_SPLIT_RIGHT_OUT_VALID, (reg32), (val))
#define STATUS_SET_SPLIT_RIGHT_OUT_READY(reg32, val)           REG_FLD_SET(STATUS_FLD_SPLIT_RIGHT_OUT_READY, (reg32), (val))
#define STATUS_SET_OUTP_RIGHT_IN_VALID(reg32, val)             REG_FLD_SET(STATUS_FLD_OUTP_RIGHT_IN_VALID, (reg32), (val))
#define STATUS_SET_OUTP_RIGHT_IN_READY(reg32, val)             REG_FLD_SET(STATUS_FLD_OUTP_RIGHT_IN_READY, (reg32), (val))
#define STATUS_SET_OUTP_RIGHT_OUT_VALID(reg32, val)            REG_FLD_SET(STATUS_FLD_OUTP_RIGHT_OUT_VALID, (reg32), (val))
#define STATUS_SET_OUTP_RIGHT_OUT_READY(reg32, val)            REG_FLD_SET(STATUS_FLD_OUTP_RIGHT_OUT_READY, (reg32), (val))
#define STATUS_SET_OUTP_LEFT_IN_VALID(reg32, val)              REG_FLD_SET(STATUS_FLD_OUTP_LEFT_IN_VALID, (reg32), (val))
#define STATUS_SET_OUTP_LEFT_IN_READY(reg32, val)              REG_FLD_SET(STATUS_FLD_OUTP_LEFT_IN_READY, (reg32), (val))
#define STATUS_SET_OUTP_LEFT_OUT_VALID(reg32, val)             REG_FLD_SET(STATUS_FLD_OUTP_LEFT_OUT_VALID, (reg32), (val))
#define STATUS_SET_OUTP_LEFT_OUT_READY(reg32, val)             REG_FLD_SET(STATUS_FLD_OUTP_LEFT_OUT_READY, (reg32), (val))
#define STATUS_SET_INP_IN_VALID(reg32, val)                    REG_FLD_SET(STATUS_FLD_INP_IN_VALID, (reg32), (val))
#define STATUS_SET_INP_IN_READY(reg32, val)                    REG_FLD_SET(STATUS_FLD_INP_IN_READY, (reg32), (val))
#define STATUS_SET_INP_OUT_VALID(reg32, val)                   REG_FLD_SET(STATUS_FLD_INP_OUT_VALID, (reg32), (val))
#define STATUS_SET_INP_OUT_READY(reg32, val)                   REG_FLD_SET(STATUS_FLD_INP_OUT_READY, (reg32), (val))
#define STATUS_SET_OUT_LEFT_VALID(reg32, val)                  REG_FLD_SET(STATUS_FLD_OUT_LEFT_VALID, (reg32), (val))
#define STATUS_SET_OUT_LEFT_READY(reg32, val)                  REG_FLD_SET(STATUS_FLD_OUT_LEFT_READY, (reg32), (val))
#define STATUS_SET_OUT_RIGHT_VALID(reg32, val)                 REG_FLD_SET(STATUS_FLD_OUT_RIGHT_VALID, (reg32), (val))
#define STATUS_SET_OUT_RIGHT_READY(reg32, val)                 REG_FLD_SET(STATUS_FLD_OUT_RIGHT_READY, (reg32), (val))
#define STATUS_SET_IN_VALID(reg32, val)                        REG_FLD_SET(STATUS_FLD_IN_VALID, (reg32), (val))
#define STATUS_SET_IN_READY(reg32, val)                        REG_FLD_SET(STATUS_FLD_IN_READY, (reg32), (val))
#define STATUS_SET_LOF_UNFINISH(reg32, val)                    REG_FLD_SET(STATUS_FLD_LOF_UNFINISH, (reg32), (val))
#define STATUS_SET_ROF_UNFINISH(reg32, val)                    REG_FLD_SET(STATUS_FLD_ROF_UNFINISH, (reg32), (val))
#define STATUS_SET_IF_UNFINISH(reg32, val)                     REG_FLD_SET(STATUS_FLD_IF_UNFINISH, (reg32), (val))

#define CFG_SET_CHKSUM_SEL(reg32, val)                         REG_FLD_SET(CFG_FLD_CHKSUM_SEL, (reg32), (val))
#define CFG_SET_CHKSUM_EN(reg32, val)                          REG_FLD_SET(CFG_FLD_CHKSUM_EN, (reg32), (val))
#define CFG_SET_STALL_CG_ON(reg32, val)                        REG_FLD_SET(CFG_FLD_STALL_CG_ON, (reg32), (val))
#define CFG_SET_EMPTY_FLAG_SEL(reg32, val)                     REG_FLD_SET(CFG_FLD_EMPTY_FLAG_SEL, (reg32), (val))
#define CFG_SET_SWAP_EN(reg32, val)                            REG_FLD_SET(CFG_FLD_SWAP_EN, (reg32), (val))

#define INPUT_COUNT_SET_INP_LINE_CNT(reg32, val)               REG_FLD_SET(INPUT_COUNT_FLD_INP_LINE_CNT, (reg32), (val))
#define INPUT_COUNT_SET_INP_PIX_CNT(reg32, val)                REG_FLD_SET(INPUT_COUNT_FLD_INP_PIX_CNT, (reg32), (val))

#define LEFT_OUTPUT_COUNT_SET_LEFT_OUTP_LINE_CNT(reg32, val)   REG_FLD_SET(LEFT_OUTPUT_COUNT_FLD_LEFT_OUTP_LINE_CNT, (reg32), (val))
#define LEFT_OUTPUT_COUNT_SET_LEFT_OUTP_PIX_CNT(reg32, val)    REG_FLD_SET(LEFT_OUTPUT_COUNT_FLD_LEFT_OUTP_PIX_CNT, (reg32), (val))

#define RIGHT_OUTPUT_COUNT_SET_RIGHT_OUTP_LINE_CNT(reg32, val) REG_FLD_SET(RIGHT_OUTPUT_COUNT_FLD_RIGHT_OUTP_LINE_CNT, (reg32), (val))
#define RIGHT_OUTPUT_COUNT_SET_RIGHT_OUTP_PIX_CNT(reg32, val)  REG_FLD_SET(RIGHT_OUTPUT_COUNT_FLD_RIGHT_OUTP_PIX_CNT, (reg32), (val))

#define CHKSUM_SET_CHKSUM(reg32, val)                          REG_FLD_SET(CHKSUM_FLD_CHKSUM, (reg32), (val))

#define HSIZE_SET_HSIZE_L(reg32, val)                          REG_FLD_SET(HSIZE_FLD_HSIZE_L, (reg32), (val))
#define HSIZE_SET_HSIZE_R(reg32, val)                          REG_FLD_SET(HSIZE_FLD_HSIZE_R, (reg32), (val))

#define VSIZE_SET_VSIZE(reg32, val)                            REG_FLD_SET(VSIZE_FLD_VSIZE, (reg32), (val))

#define OVERLAP_SET_OVERLAP_LENGTH(reg32, val)                 REG_FLD_SET(OVERLAP_FLD_OVERLAP_LENGTH, (reg32), (val))
#define OVERLAP_SET_OVERLAP_EN(reg32, val)                     REG_FLD_SET(OVERLAP_FLD_OVERLAP_EN, (reg32), (val))

#define INFO_A_SET_STATE_R(reg32, val)                         REG_FLD_SET(INFO_A_FLD_STATE_R, (reg32), (val))
#define INFO_A_SET_HCNT_R(reg32, val)                          REG_FLD_SET(INFO_A_FLD_HCNT_R, (reg32), (val))
#define INFO_A_SET_HCNT_R_LEFT(reg32, val)                     REG_FLD_SET(INFO_A_FLD_HCNT_R_LEFT, (reg32), (val))
#define INFO_A_SET_HCNT_R_RIGHT(reg32, val)                    REG_FLD_SET(INFO_A_FLD_HCNT_R_RIGHT, (reg32), (val))

#define INFO_B_SET_FBUF_PUSH(reg32, val)                       REG_FLD_SET(INFO_B_FLD_FBUF_PUSH, (reg32), (val))
#define INFO_B_SET_FBUF_PUSH_D1(reg32, val)                    REG_FLD_SET(INFO_B_FLD_FBUF_PUSH_D1, (reg32), (val))
#define INFO_B_SET_FBUF_POP(reg32, val)                        REG_FLD_SET(INFO_B_FLD_FBUF_POP, (reg32), (val))
#define INFO_B_SET_FBUF_FULL(reg32, val)                       REG_FLD_SET(INFO_B_FLD_FBUF_FULL, (reg32), (val))
#define INFO_B_SET_FBUF_TYPE(reg32, val)                       REG_FLD_SET(INFO_B_FLD_FBUF_TYPE, (reg32), (val))
#define INFO_B_SET_FBUF_COND2(reg32, val)                      REG_FLD_SET(INFO_B_FLD_FBUF_COND2, (reg32), (val))
#define INFO_B_SET_IBUF_PUSH(reg32, val)                       REG_FLD_SET(INFO_B_FLD_IBUF_PUSH, (reg32), (val))
#define INFO_B_SET_IBUF_POP(reg32, val)                        REG_FLD_SET(INFO_B_FLD_IBUF_POP, (reg32), (val))
#define INFO_B_SET_IBUF_WPTR(reg32, val)                       REG_FLD_SET(INFO_B_FLD_IBUF_WPTR, (reg32), (val))
#define INFO_B_SET_IBUF_FULL(reg32, val)                       REG_FLD_SET(INFO_B_FLD_IBUF_FULL, (reg32), (val))
#define INFO_B_SET_HEND_R(reg32, val)                          REG_FLD_SET(INFO_B_FLD_HEND_R, (reg32), (val))
#define INFO_B_SET_HEND_R_LEFT(reg32, val)                     REG_FLD_SET(INFO_B_FLD_HEND_R_LEFT, (reg32), (val))
#define INFO_B_SET_HEND_R_RIGHT(reg32, val)                    REG_FLD_SET(INFO_B_FLD_HEND_R_RIGHT, (reg32), (val))
#define INFO_B_SET_FIFO1_EMPTY(reg32, val)                     REG_FLD_SET(INFO_B_FLD_FIFO1_EMPTY, (reg32), (val))
#define INFO_B_SET_FIFO0_EMPTY(reg32, val)                     REG_FLD_SET(INFO_B_FLD_FIFO0_EMPTY, (reg32), (val))
#define INFO_B_SET_FIFO_EMPTY(reg32, val)                      REG_FLD_SET(INFO_B_FLD_FIFO_EMPTY, (reg32), (val))
#define INFO_B_SET_PCNT(reg32, val)                            REG_FLD_SET(INFO_B_FLD_PCNT, (reg32), (val))

#define INFO_C_SET_FIFO0_FULL(reg32, val)                      REG_FLD_SET(INFO_C_FLD_FIFO0_FULL, (reg32), (val))
#define INFO_C_SET_FIFO1_RPTR(reg32, val)                      REG_FLD_SET(INFO_C_FLD_FIFO1_RPTR, (reg32), (val))
#define INFO_C_SET_FIFO0_RPTR(reg32, val)                      REG_FLD_SET(INFO_C_FLD_FIFO0_RPTR, (reg32), (val))
#define INFO_C_SET_FIFO0_WPTR(reg32, val)                      REG_FLD_SET(INFO_C_FLD_FIFO0_WPTR, (reg32), (val))

#define SHADOW_CTRL_SET_READ_WRK_REG(reg32, val)               REG_FLD_SET(SHADOW_CTRL_FLD_READ_WRK_REG, (reg32), (val))
#define SHADOW_CTRL_SET_BYPASS_SHADOW(reg32, val)              REG_FLD_SET(SHADOW_CTRL_FLD_BYPASS_SHADOW, (reg32), (val))
#define SHADOW_CTRL_SET_FORCE_COMMIT(reg32, val)               REG_FLD_SET(SHADOW_CTRL_FLD_FORCE_COMMIT, (reg32), (val))

#define EN_VAL_SPLIT_EN(val)                                   REG_FLD_VAL(EN_FLD_SPLIT_EN, (val))

#define RESET_VAL_SPLIT_RESET(val)                             REG_FLD_VAL(RESET_FLD_SPLIT_RESET, (val))

#define INTEN_VAL_LOF_END_INT_EN(val)                          REG_FLD_VAL(INTEN_FLD_LOF_END_INT_EN, (val))
#define INTEN_VAL_ROF_END_INT_EN(val)                          REG_FLD_VAL(INTEN_FLD_ROF_END_INT_EN, (val))
#define INTEN_VAL_IF_END_INT_EN(val)                           REG_FLD_VAL(INTEN_FLD_IF_END_INT_EN, (val))

#define INTSTA_VAL_LOF_END_INT(val)                            REG_FLD_VAL(INTSTA_FLD_LOF_END_INT, (val))
#define INTSTA_VAL_ROF_END_INT(val)                            REG_FLD_VAL(INTSTA_FLD_ROF_END_INT, (val))
#define INTSTA_VAL_IF_END_INT(val)                             REG_FLD_VAL(INTSTA_FLD_IF_END_INT, (val))

#define STATUS_VAL_ONLY_ONE_SIDE(val)                          REG_FLD_VAL(STATUS_FLD_ONLY_ONE_SIDE, (val))
#define STATUS_VAL_LEFT_FRAME_EXIST(val)                       REG_FLD_VAL(STATUS_FLD_LEFT_FRAME_EXIST, (val))
#define STATUS_VAL_RIGHT_FRAME_EXIST(val)                      REG_FLD_VAL(STATUS_FLD_RIGHT_FRAME_EXIST, (val))
#define STATUS_VAL_SPLIT_IN_VALID(val)                         REG_FLD_VAL(STATUS_FLD_SPLIT_IN_VALID, (val))
#define STATUS_VAL_SPLIT_IN_READY(val)                         REG_FLD_VAL(STATUS_FLD_SPLIT_IN_READY, (val))
#define STATUS_VAL_SPLIT_LEFT_OUT_VALID(val)                   REG_FLD_VAL(STATUS_FLD_SPLIT_LEFT_OUT_VALID, (val))
#define STATUS_VAL_SPLIT_LEFT_OUT_READY(val)                   REG_FLD_VAL(STATUS_FLD_SPLIT_LEFT_OUT_READY, (val))
#define STATUS_VAL_SPLIT_RIGHT_OUT_VALID(val)                  REG_FLD_VAL(STATUS_FLD_SPLIT_RIGHT_OUT_VALID, (val))
#define STATUS_VAL_SPLIT_RIGHT_OUT_READY(val)                  REG_FLD_VAL(STATUS_FLD_SPLIT_RIGHT_OUT_READY, (val))
#define STATUS_VAL_OUTP_RIGHT_IN_VALID(val)                    REG_FLD_VAL(STATUS_FLD_OUTP_RIGHT_IN_VALID, (val))
#define STATUS_VAL_OUTP_RIGHT_IN_READY(val)                    REG_FLD_VAL(STATUS_FLD_OUTP_RIGHT_IN_READY, (val))
#define STATUS_VAL_OUTP_RIGHT_OUT_VALID(val)                   REG_FLD_VAL(STATUS_FLD_OUTP_RIGHT_OUT_VALID, (val))
#define STATUS_VAL_OUTP_RIGHT_OUT_READY(val)                   REG_FLD_VAL(STATUS_FLD_OUTP_RIGHT_OUT_READY, (val))
#define STATUS_VAL_OUTP_LEFT_IN_VALID(val)                     REG_FLD_VAL(STATUS_FLD_OUTP_LEFT_IN_VALID, (val))
#define STATUS_VAL_OUTP_LEFT_IN_READY(val)                     REG_FLD_VAL(STATUS_FLD_OUTP_LEFT_IN_READY, (val))
#define STATUS_VAL_OUTP_LEFT_OUT_VALID(val)                    REG_FLD_VAL(STATUS_FLD_OUTP_LEFT_OUT_VALID, (val))
#define STATUS_VAL_OUTP_LEFT_OUT_READY(val)                    REG_FLD_VAL(STATUS_FLD_OUTP_LEFT_OUT_READY, (val))
#define STATUS_VAL_INP_IN_VALID(val)                           REG_FLD_VAL(STATUS_FLD_INP_IN_VALID, (val))
#define STATUS_VAL_INP_IN_READY(val)                           REG_FLD_VAL(STATUS_FLD_INP_IN_READY, (val))
#define STATUS_VAL_INP_OUT_VALID(val)                          REG_FLD_VAL(STATUS_FLD_INP_OUT_VALID, (val))
#define STATUS_VAL_INP_OUT_READY(val)                          REG_FLD_VAL(STATUS_FLD_INP_OUT_READY, (val))
#define STATUS_VAL_OUT_LEFT_VALID(val)                         REG_FLD_VAL(STATUS_FLD_OUT_LEFT_VALID, (val))
#define STATUS_VAL_OUT_LEFT_READY(val)                         REG_FLD_VAL(STATUS_FLD_OUT_LEFT_READY, (val))
#define STATUS_VAL_OUT_RIGHT_VALID(val)                        REG_FLD_VAL(STATUS_FLD_OUT_RIGHT_VALID, (val))
#define STATUS_VAL_OUT_RIGHT_READY(val)                        REG_FLD_VAL(STATUS_FLD_OUT_RIGHT_READY, (val))
#define STATUS_VAL_IN_VALID(val)                               REG_FLD_VAL(STATUS_FLD_IN_VALID, (val))
#define STATUS_VAL_IN_READY(val)                               REG_FLD_VAL(STATUS_FLD_IN_READY, (val))
#define STATUS_VAL_LOF_UNFINISH(val)                           REG_FLD_VAL(STATUS_FLD_LOF_UNFINISH, (val))
#define STATUS_VAL_ROF_UNFINISH(val)                           REG_FLD_VAL(STATUS_FLD_ROF_UNFINISH, (val))
#define STATUS_VAL_IF_UNFINISH(val)                            REG_FLD_VAL(STATUS_FLD_IF_UNFINISH, (val))

#define CFG_VAL_CHKSUM_SEL(val)                                REG_FLD_VAL(CFG_FLD_CHKSUM_SEL, (val))
#define CFG_VAL_CHKSUM_EN(val)                                 REG_FLD_VAL(CFG_FLD_CHKSUM_EN, (val))
#define CFG_VAL_STALL_CG_ON(val)                               REG_FLD_VAL(CFG_FLD_STALL_CG_ON, (val))
#define CFG_VAL_EMPTY_FLAG_SEL(val)                            REG_FLD_VAL(CFG_FLD_EMPTY_FLAG_SEL, (val))
#define CFG_VAL_SWAP_EN(val)                                   REG_FLD_VAL(CFG_FLD_SWAP_EN, (val))

#define INPUT_COUNT_VAL_INP_LINE_CNT(val)                      REG_FLD_VAL(INPUT_COUNT_FLD_INP_LINE_CNT, (val))
#define INPUT_COUNT_VAL_INP_PIX_CNT(val)                       REG_FLD_VAL(INPUT_COUNT_FLD_INP_PIX_CNT, (val))

#define LEFT_OUTPUT_COUNT_VAL_LEFT_OUTP_LINE_CNT(val)          REG_FLD_VAL(LEFT_OUTPUT_COUNT_FLD_LEFT_OUTP_LINE_CNT, (val))
#define LEFT_OUTPUT_COUNT_VAL_LEFT_OUTP_PIX_CNT(val)           REG_FLD_VAL(LEFT_OUTPUT_COUNT_FLD_LEFT_OUTP_PIX_CNT, (val))

#define RIGHT_OUTPUT_COUNT_VAL_RIGHT_OUTP_LINE_CNT(val)        REG_FLD_VAL(RIGHT_OUTPUT_COUNT_FLD_RIGHT_OUTP_LINE_CNT, (val))
#define RIGHT_OUTPUT_COUNT_VAL_RIGHT_OUTP_PIX_CNT(val)         REG_FLD_VAL(RIGHT_OUTPUT_COUNT_FLD_RIGHT_OUTP_PIX_CNT, (val))

#define CHKSUM_VAL_CHKSUM(val)                                 REG_FLD_VAL(CHKSUM_FLD_CHKSUM, (val))

#define HSIZE_VAL_HSIZE_L(val)                                 REG_FLD_VAL(HSIZE_FLD_HSIZE_L, (val))
#define HSIZE_VAL_HSIZE_R(val)                                 REG_FLD_VAL(HSIZE_FLD_HSIZE_R, (val))

#define VSIZE_VAL_VSIZE(val)                                   REG_FLD_VAL(VSIZE_FLD_VSIZE, (val))

#define OVERLAP_VAL_OVERLAP_LENGTH(val)                        REG_FLD_VAL(OVERLAP_FLD_OVERLAP_LENGTH, (val))
#define OVERLAP_VAL_OVERLAP_EN(val)                            REG_FLD_VAL(OVERLAP_FLD_OVERLAP_EN, (val))

#define INFO_A_VAL_STATE_R(val)                                REG_FLD_VAL(INFO_A_FLD_STATE_R, (val))
#define INFO_A_VAL_HCNT_R(val)                                 REG_FLD_VAL(INFO_A_FLD_HCNT_R, (val))
#define INFO_A_VAL_HCNT_R_LEFT(val)                            REG_FLD_VAL(INFO_A_FLD_HCNT_R_LEFT, (val))
#define INFO_A_VAL_HCNT_R_RIGHT(val)                           REG_FLD_VAL(INFO_A_FLD_HCNT_R_RIGHT, (val))

#define INFO_B_VAL_FBUF_PUSH(val)                              REG_FLD_VAL(INFO_B_FLD_FBUF_PUSH, (val))
#define INFO_B_VAL_FBUF_PUSH_D1(val)                           REG_FLD_VAL(INFO_B_FLD_FBUF_PUSH_D1, (val))
#define INFO_B_VAL_FBUF_POP(val)                               REG_FLD_VAL(INFO_B_FLD_FBUF_POP, (val))
#define INFO_B_VAL_FBUF_FULL(val)                              REG_FLD_VAL(INFO_B_FLD_FBUF_FULL, (val))
#define INFO_B_VAL_FBUF_TYPE(val)                              REG_FLD_VAL(INFO_B_FLD_FBUF_TYPE, (val))
#define INFO_B_VAL_FBUF_COND2(val)                             REG_FLD_VAL(INFO_B_FLD_FBUF_COND2, (val))
#define INFO_B_VAL_IBUF_PUSH(val)                              REG_FLD_VAL(INFO_B_FLD_IBUF_PUSH, (val))
#define INFO_B_VAL_IBUF_POP(val)                               REG_FLD_VAL(INFO_B_FLD_IBUF_POP, (val))
#define INFO_B_VAL_IBUF_WPTR(val)                              REG_FLD_VAL(INFO_B_FLD_IBUF_WPTR, (val))
#define INFO_B_VAL_IBUF_FULL(val)                              REG_FLD_VAL(INFO_B_FLD_IBUF_FULL, (val))
#define INFO_B_VAL_HEND_R(val)                                 REG_FLD_VAL(INFO_B_FLD_HEND_R, (val))
#define INFO_B_VAL_HEND_R_LEFT(val)                            REG_FLD_VAL(INFO_B_FLD_HEND_R_LEFT, (val))
#define INFO_B_VAL_HEND_R_RIGHT(val)                           REG_FLD_VAL(INFO_B_FLD_HEND_R_RIGHT, (val))
#define INFO_B_VAL_FIFO1_EMPTY(val)                            REG_FLD_VAL(INFO_B_FLD_FIFO1_EMPTY, (val))
#define INFO_B_VAL_FIFO0_EMPTY(val)                            REG_FLD_VAL(INFO_B_FLD_FIFO0_EMPTY, (val))
#define INFO_B_VAL_FIFO_EMPTY(val)                             REG_FLD_VAL(INFO_B_FLD_FIFO_EMPTY, (val))
#define INFO_B_VAL_PCNT(val)                                   REG_FLD_VAL(INFO_B_FLD_PCNT, (val))

#define INFO_C_VAL_FIFO0_FULL(val)                             REG_FLD_VAL(INFO_C_FLD_FIFO0_FULL, (val))
#define INFO_C_VAL_FIFO1_RPTR(val)                             REG_FLD_VAL(INFO_C_FLD_FIFO1_RPTR, (val))
#define INFO_C_VAL_FIFO0_RPTR(val)                             REG_FLD_VAL(INFO_C_FLD_FIFO0_RPTR, (val))
#define INFO_C_VAL_FIFO0_WPTR(val)                             REG_FLD_VAL(INFO_C_FLD_FIFO0_WPTR, (val))

#define SHADOW_CTRL_VAL_READ_WRK_REG(val)                      REG_FLD_VAL(SHADOW_CTRL_FLD_READ_WRK_REG, (val))
#define SHADOW_CTRL_VAL_BYPASS_SHADOW(val)                     REG_FLD_VAL(SHADOW_CTRL_FLD_BYPASS_SHADOW, (val))
#define SHADOW_CTRL_VAL_FORCE_COMMIT(val)                      REG_FLD_VAL(SHADOW_CTRL_FLD_FORCE_COMMIT, (val))

#ifdef __cplusplus
}
#endif

#endif // __DISP_SPLIT_REGS_H__
