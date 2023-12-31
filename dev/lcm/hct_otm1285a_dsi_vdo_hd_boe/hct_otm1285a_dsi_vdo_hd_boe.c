/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/


#ifdef BUILD_LK
#else
#include <linux/string.h>
#if defined(BUILD_UBOOT)
#include <asm/arch/mt_gpio.h>
#else
        #include <mt-plat/mt_gpio.h>
#endif
#endif
#include "lcm_drv.h"

#if defined(BUILD_LK)
#else

#include <linux/proc_fs.h>   //proc file use 
#endif


// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH                                         (720)
#define FRAME_HEIGHT                                        (1280)
#define LCM_ID                       (0x1285)

#define REGFLAG_DELAY               (0XFE)
#define REGFLAG_END_OF_TABLE        (0x100) // END OF REGISTERS MARKER


#define LCM_DSI_CMD_MODE                                    0

#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)                                    (lcm_util.set_reset_pin((v)))

#define UDELAY(n)                                           (lcm_util.udelay(n))
#define MDELAY(n)                                           (lcm_util.mdelay(n))

static unsigned int lcm_esd_test = FALSE;      ///only for ESD test

// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)    lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)       lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)                                      lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)                  lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)                                           lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)               lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

 struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};


static struct LCM_setting_table lcm_initialization_setting[] = {
    
    /*
    Note :

    Data ID will depends on the following rule.
    
        count of parameters > 1 => Data ID = 0x39
        count of parameters = 1 => Data ID = 0x15
        count of parameters = 0 => Data ID = 0x05

    Structure Format :

    {DCS command, count of parameters, {parameter list}}
    {REGFLAG_DELAY, milliseconds of time, {}},

    ...

    Setting ending by predefined flag
    
    {REGFLAG_END_OF_TABLE, 0x00, {}}
    */
{0x00,1,{0x00}},
{0xFF,3,{0x12,0x85,0x01}},


{0x00,1,{0x80}},
{0xFF,2,{0x12,0x85}},


{0x00,1,{0xC1}},
{0xC5,1,{0x33}},


{0x00,1,{0x93}},
{0xC5,1,{0x12}}, //17


{0x00,1,{0x95}},
{0xC5,1,{0x19}},


{0x00,1,{0x96}},
{0xC5,1,{0x80}},


{0x00,1,{0x97}},
{0xC5,1,{0x16}},


{0x00,1,{0x98}},
{0xC5,2,{0x80,0x0F}},


{0x00,1,{0x00}},
{0xD8,2,{0x2E,0x2E}},


{0x00,1,{0x00}},
{0xD9,1,{0x83}}, //88


{0x00,1,{0x80}},
{0xC5,1,{0x34}},


{0x00,1,{0x90}},
{0xF5,14,{0x03,0x15,0x09,0x15,0x07,0x15,0x0C,0x15,0x0A,0x15,0x09,0x15,0x0A,0x15}},


{0x00,1,{0xA0}},
{0xF5,14,{0x12,0x11,0x03,0x15,0x09,0x15,0x11,0x15,0x08,0x15,0x07,0x15,0x09,0x15}},


{0x00,1,{0xC0}},
{0xF5,14,{0x0E,0x15,0x0E,0x15,0x00,0x15,0x00,0x15,0x2E,0x15,0x14,0x11,0x00,0x25}},


{0x00,1,{0xD0}},
{0xF5,15,{0x07,0x15,0x0A,0x15,0x10,0x11,0x00,0x10,0x90,0x90,0x90,0x02,0x90,0x00,0X00}},


{0x00,1,{0x82}},
{0xC0,3,{0x00,0x0e,0x0c}},


{0x00,1,{0x80}},
{0xC0,2,{0x00,0x70}},


{0x00,1,{0x80}},
{0xC1,4,{0x19,0x19,0x19,0x19}},


{0x00,1,{0x90}},
{0xC1,1,{0x77}},


{0x00,1,{0x80}},
{0xC2,8,{0x84,0x02,0x7B,0x12,0x85,0x01,0x5D,0xF0}},


{0x00,1,{0xF0}},
{0xC2,2,{0x00,0x00}},


{0x00,1,{0x90}},
{0xC2,15,{0x82,0x02,0x01,0x0D,0x05,0x81,0x02,0x01,0x0D,0x05,0x80,0x02,0x01,0x0D,0x05}},


{0x00,1,{0xA0}},
{0xC2,5,{0x83,0x02,0x01,0x0D,0x05}},


{0x00,1,{0xEC}},
{0xC2,2,{0x10,0x00}},


{0x00,1,{0xA0}},
{0xC0,1,{0x0B}},


{0x00,1,{0xA3}},
{0xC0,1,{0x00}},


{0x00,1,{0xA5}},
{0xC0,2,{0x18,0x05}},


{0x00,1,{0x80}},
{0xCC,12,{0x03,0x04,0x05,0x06,0x11,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B}},


{0x00,1,{0xB0}},
{0xCC,12,{0x06,0x05,0x04,0x03,0x0C,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B}},


{0x00,1,{0x80}},
{0xCD,15,{0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x01,0x02,0x14,0x13,0x12,0x0B,0x0B,0x0B}},


{0x00,1,{0x80}},
{0xCB,7,{0x00,0x00,0x00,0x00,0x00,0x00,0x00}},


{0x00,1,{0xF0}},
{0xCB,7,{0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xFF}},


{0x00,1,{0xC0}},
{0xCB,15,{0xFD,0xFD,0xFD,0xFD,0xFD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},


{0x00,1,{0xD0}},
{0xCB,12,{0x00,0x00,0x00,0x00,0xFD,0x00,0xFD,0xFD,0x05,0x00,0x00,0x00}},


{0x00,1,{0x90}},
{0xCB,15,{0x7F,0x7F,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},


{0x00,1,{0xA0}},
{0xCB,12,{0x00,0x00,0x00,0x40,0x7F,0x40,0x7F,0x7F,0x7F,0x00,0x00,0x00}},


{0x00,1,{0xE0}},
{0xCC,4,{0x80,0xF0,0x00,0x00}},


{0x00,1,{0xD0}},
{0xCD,15,{0x01,0x00,0x03,0x00,0x13,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F}},


{0x00,1,{0xE0}},
{0xCD,12,{0x10,0x11,0x12,0x05,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B}},


{0x00,1,{0xA0}},
{0xCD,15,{0x00,0x02,0x00,0x04,0x13,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F}},


{0x00,1,{0xB0}},
{0xCD,12,{0x10,0x11,0x12,0x05,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B}},



{0x00,1,{0xA2}},
{0xC1,1,{0x00}},


{0x00,1,{0xB3}},
{0xC0,1,{0x00}},


{0x00,1,{0xB4}},
{0xC0,1,{0x40}},


{0x00,1,{0x80}},
{0xC4,1,{0x88}},


{0x00,1,{0x83}},
{0xC4,1,{0x20}},


{0x00,1,{0x00}},
{0x35,1,{0x01}},

//--------------------CE  setting--------------------
{0x00, 1 , {0xA3}},
{0xB6,  1 ,{0x03}},

{0x00, 1 , {0x00}},
{0x59,  1 ,{0x00}},

{0x00, 1 , {0xA0}},
{0xD6, 12 ,{0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0x00, 1 , {0xB0}},
{0xD6, 12 ,{0x00,0x00,0x5A,0xB3,0xB3,0xB3,0xB3,0xB3,0xB3,0xB3,0xB3,0xB3}},

{0x00, 1 , {0xC0}},
{0xD6, 12 ,{0x3C,0x00,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77}},

{0x00, 1 , {0xD0}},
{0xD6, 12 ,{0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C}},
{0x55,  1 ,{0x80}},//0x00:off ;0x80:low;0x90:medium;0xb0:high   

//--------------------CE  end  --------------------

{0x00,1,{0x00}},
//GAMMAA R+
{0xE1,24,{0X0C,0X15,0X1E,0X2E,0X38,0X40,0X4C,0X5F,0X69,0X7C,0X89,0X92,0X67,0X61,0X5C,0X4D,0X3C,0X2C,0X22,0X1D,0X18,0X14,0X13,0X12}},


{0x00,1,{0x00}},
//GAMMAA R-
{0xE2,24,{0X0C,0X15,0X1E,0X2E,0X38,0X40,0X4C,0X5F,0X69,0X7C,0X89,0X92,0X67,0X61,0X5C,0X4D,0X3C,0X2C,0X22,0X1D,0X18,0X14,0X13,0X12}},


{0x00,1,{0x00}},
//GAMMAA G+
{0xE3,24,{0X0C,0X15,0X1E,0X2E,0X38,0X40,0X4C,0X5F,0X69,0X7C,0X89,0X92,0X67,0X61,0X5C,0X4D,0X3C,0X2C,0X22,0X1D,0X18,0X14,0X13,0X12}},


{0x00,1,{0x00}},
//GAMMAA G-
{0xE4,24,{0X0C,0X15,0X1E,0X2E,0X38,0X40,0X4C,0X5F,0X69,0X7C,0X89,0X92,0X67,0X61,0X5C,0X4D,0X3C,0X2C,0X22,0X1D,0X18,0X14,0X13,0X12}},


{0x00,1,{0x00}},
//GAMMAA B+
{0xE5,24,{0X0C,0X15,0X1E,0X2E,0X38,0X40,0X4C,0X5F,0X69,0X7C,0X89,0X92,0X67,0X61,0X5C,0X4D,0X3C,0X2C,0X22,0X1D,0X18,0X14,0X13,0X12}},


{0x00,1,{0x00}},
//GAMMAA B-
{0xE6,24,{0X0C,0X15,0X1E,0X2E,0X38,0X40,0X4C,0X5F,0X69,0X7C,0X89,0X92,0X67,0X61,0X5C,0X4D,0X3C,0X2C,0X22,0X1D,0X18,0X14,0X13,0X12}},

{REGFLAG_DELAY, 10, {}},

/*
{0x51,1,{0xFF}},

{0x53,1,{0x2C}},

{0x55,1,{0x00}},
*/


    {0x11,1,{0x00}},  
    {REGFLAG_DELAY,120,{}},

    {0x29,1,{0x00}},//Display ON 
    {REGFLAG_DELAY,20,{}},  

// Setting ending by predefined flag
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};

static struct LCM_setting_table lcm_sleep_out_setting[] = {
    // Sleep Out
    {0x11, 1, {0x00}},
    {REGFLAG_DELAY, 120, {}},
    // Display ON
    //{0x2C, 1, {0x00}},
    //{0x13, 1, {0x00}},
    {0x29, 1, {0x00}},
    {REGFLAG_DELAY, 20, {}},
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};


static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = {
    // Display off sequence
    {0x28, 1, {0x00}},
    {REGFLAG_DELAY, 20, {}},

    // Sleep Mode On
    {0x10, 1, {0x00}},
    {REGFLAG_DELAY, 120, {}},

    {REGFLAG_END_OF_TABLE, 0x00, {}}
};

static struct LCM_setting_table lcm_compare_id_setting[] = {
    // Display off sequence
    {0xf0, 5, {0x55, 0xaa, 0x52, 0x08, 0x01}},
    {REGFLAG_DELAY, 10, {}},
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};

static struct LCM_setting_table lcm_backlight_level_setting[] = {
    {0x51, 1, {0xFF}},
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};

//static int vcom=0x40;
static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
    unsigned int i;

    for(i = 0; i < count; i++) {
        
        unsigned cmd;
        cmd = table[i].cmd;
        
        switch (cmd) {
			/*case 0xd9:
			table[i].para_list[0]=vcom;
			dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
            vcom+=2;
			break;
			*/
            case REGFLAG_DELAY :
                MDELAY(table[i].count);
                break;
                
            case REGFLAG_END_OF_TABLE :
                break;
                
            default:
                dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
        }
    }
    
}


// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{
    memset(params, 0, sizeof(LCM_PARAMS));
    params->type   = LCM_TYPE_DSI;
    params->width  = FRAME_WIDTH;
    params->height = FRAME_HEIGHT;

    // enable tearing-free
    params->dbi.te_mode             = LCM_DBI_TE_MODE_DISABLED;
    params->dbi.te_edge_polarity        = LCM_POLARITY_RISING;



    params->dsi.mode   = SYNC_EVENT_VDO_MODE;


    // DSI
    /* Command mode setting */
    params->dsi.LANE_NUM                = LCM_FOUR_LANE;
    //The following defined the fomat for data coming from LCD engine. 
    params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
    params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST; 
    params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
    params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;
    // Highly depends on LCD driver capability.
    // Not support in MT6573
    params->dsi.packet_size=256;
    // Video mode setting       
    params->dsi.intermediat_buffer_num = 2;
    params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
    params->dsi.vertical_sync_active                = 4;
    params->dsi.vertical_backporch                  = 16;
    params->dsi.vertical_frontporch                 = 15;
    params->dsi.vertical_active_line                = FRAME_HEIGHT; 
    params->dsi.horizontal_sync_active              = 10;
    params->dsi.horizontal_backporch                = 64;
    params->dsi.horizontal_frontporch               = 64;
    params->dsi.horizontal_blanking_pixel              = 60;
    params->dsi.horizontal_active_pixel            = FRAME_WIDTH;
    // Bit rate calculation
#if 0
    params->dsi.pll_div1=1;     // div1=0,1,2,3;div1_real=1,2,4,4
    params->dsi.pll_div2=1;     // div2=0,1,2,3;div2_real=1,2,4,4
    params->dsi.fbk_sel=1;       // fbk_sel=0,1,2,3;fbk_sel_real=1,2,4,4
    params->dsi.fbk_div =30;        // fref=26MHz, fvco=fref*(fbk_div+1)*2/(div1_real*div2_real)    
#else
    params->dsi.PLL_CLOCK=230;//227;//254;//254//247
#endif
}

static void lcm_init(void)
{
    SET_RESET_PIN(1);
    MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(20);
    SET_RESET_PIN(1);
    MDELAY(120);

    push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
#ifdef BUILD_LK
    printf("[erick-lk]%s\n", __func__);
#else
    printk("[erick-k]%s\n", __func__);
#endif
}


static void lcm_suspend(void)
{
#ifndef BUILD_LK
    push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);   //wqtao. enable
    #ifdef BUILD_LK
        printf("[erick-lk]%s\n", __func__);
    #else
        printk("[erick-k]%s\n", __func__);
    #endif
#endif
}


static void lcm_resume(void)
{
#ifndef BUILD_LK
    push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
    #ifdef BUILD_LK
        printf("[erick-lk]%s\n", __func__);
    #else
        printk("[erick-k]%s\n", __func__);
    #endif
#endif
}

#if (LCM_DSI_CMD_MODE)
static void lcm_update(unsigned int x, unsigned int y,
                       unsigned int width, unsigned int height)
{
    unsigned int x0 = x;
    unsigned int y0 = y;
    unsigned int x1 = x0 + width - 1;
    unsigned int y1 = y0 + height - 1;

    unsigned char x0_MSB = ((x0>>8)&0xFF);
    unsigned char x0_LSB = (x0&0xFF);
    unsigned char x1_MSB = ((x1>>8)&0xFF);
    unsigned char x1_LSB = (x1&0xFF);
    unsigned char y0_MSB = ((y0>>8)&0xFF);
    unsigned char y0_LSB = (y0&0xFF);
    unsigned char y1_MSB = ((y1>>8)&0xFF);
    unsigned char y1_LSB = (y1&0xFF);

    unsigned int data_array[16];


    data_array[0]= 0x00053902;
    data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
    data_array[2]= (x1_LSB);
    dsi_set_cmdq(data_array, 3, 1);

    data_array[0]= 0x00053902;
    data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
    data_array[2]= (y1_LSB);
    dsi_set_cmdq(data_array, 3, 1);

    data_array[0]= 0x00290508; //HW bug, so need send one HS packet
    dsi_set_cmdq(data_array, 1, 1);

    data_array[0]= 0x002c3909;
    dsi_set_cmdq(data_array, 1, 0);
}
#endif

#if 0   //wqtao.        
static void lcm_setbacklight(unsigned int level)
{
    unsigned int default_level = 145;
    unsigned int mapped_level = 0;

    //for LGE backlight IC mapping table
    if(level > 255) 
            level = 255;

    if(level >0) 
            mapped_level = default_level+(level)*(255-default_level)/(255);
    else
            mapped_level=0;

    // Refresh value of backlight level.
    lcm_backlight_level_setting[0].para_list[0] = mapped_level;

    push_table(lcm_backlight_level_setting, sizeof(lcm_backlight_level_setting) / sizeof(struct LCM_setting_table), 1);
}
#endif

static unsigned int lcm_esd_check(void)
{
#ifndef BUILD_LK
    if(lcm_esd_test)
    {
        lcm_esd_test = FALSE;
        return TRUE;
    }

    /// please notice: the max return packet size is 1
    /// if you want to change it, you can refer to the following marked code
    /// but read_reg currently only support read no more than 4 bytes....
    /// if you need to read more, please let BinHan knows.
    /*
            unsigned int data_array[16];
            unsigned int max_return_size = 1;
            
            data_array[0]= 0x00003700 | (max_return_size << 16);    
            
            dsi_set_cmdq(&data_array, 1, 1);
    */

    if(read_reg(0x0a) == 0x9c)
    {
        return FALSE;
    }
    else
    {            
        return TRUE;
    }
#endif
}

static unsigned int lcm_esd_recover(void)
{
    unsigned char para = 0;

    SET_RESET_PIN(1);
    SET_RESET_PIN(0);
    MDELAY(1);
    SET_RESET_PIN(1);
    MDELAY(120);
      push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
    MDELAY(10);
      push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
    MDELAY(10);
    dsi_set_cmdq_V2(0x35, 1, &para, 1);     ///enable TE
    MDELAY(10);

    return TRUE;
}


static unsigned int lcm_compare_id(void)
{
    unsigned int id = 0;
    unsigned char buffer[5];
    unsigned int array[16];

    SET_RESET_PIN(1);   //NOTE:should reset LCM firstly
    MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(50);
    SET_RESET_PIN(1);
    MDELAY(50);

    array[0] = 0x00053700;  // read id return two byte,version and id
    dsi_set_cmdq(array, 1, 1);
    read_reg_v2(0xa1, buffer, 5);
    id = ((buffer[2] << 8) | buffer[3]);    //we only need ID

#ifdef BUILD_LK
    printf("[erick-lk]%s,  otm1285a id = 0x%08x\n", __func__, id);
#else
    printk("[erick-k]%s,  otm1285a id = 0x%08x\n", __func__, id);
#endif
    return (LCM_ID == id)?1:0;
}

// ---------------------------------------------------------------------------
//  Get LCM Driver Hooks
// ---------------------------------------------------------------------------
LCM_DRIVER hct_otm1285a_dsi_vdo_hd_boe = 
{
    .name           = "hct_otm1285a_dsi_vdo_hd_boe",
    .set_util_funcs = lcm_set_util_funcs,
    .get_params     = lcm_get_params,
    .init           = lcm_init,
    .suspend        = lcm_suspend,
    .resume         = lcm_resume,   
    .compare_id    = lcm_compare_id,    
#if (LCM_DSI_CMD_MODE)
    //.set_backlight    = lcm_setbacklight,
    //.esd_check   = lcm_esd_check, 
    //.esd_recover   = lcm_esd_recover, 
    .update         = lcm_update,
#endif  //wqtao
};

