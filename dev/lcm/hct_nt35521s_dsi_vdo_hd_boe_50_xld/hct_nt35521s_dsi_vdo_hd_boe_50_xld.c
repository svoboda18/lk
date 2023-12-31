
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
#endif

#include "lcm_drv.h"
//yufeng
#ifdef BUILD_LK
    #include <platform/mt_gpio.h>
#elif defined(BUILD_UBOOT)
    #include <asm/arch/mt_gpio.h>
#else
        #include <mt-plat/mt_gpio.h>
#endif

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH                                          (720)
#define FRAME_HEIGHT                                         (1280)

#define REGFLAG_DELAY                                         0XFC
#define REGFLAG_END_OF_TABLE                                  0xFA   // END OF REGISTERS MARKER

#define LCM_ID_NT35521  0x5521
#define LCM_DSI_CMD_MODE                                    0

#define FALSE 0
#define TRUE 1
//HQ_fujin 131104
static unsigned int lcm_esd_test = FALSE;      ///only for ESD test
// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)    lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)        lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)                                    lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)                lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg                                            lcm_util.dsi_read_reg()
#define read_reg_v2(cmd, buffer, buffer_size)                   lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size) 

struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};

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
		params->dbi.te_mode= LCM_DBI_TE_MODE_DISABLED;
		params->dsi.mode   = SYNC_EVENT_VDO_MODE;

		// DSI
		/* Command mode setting */
		//1 Three lane or Four lane
		params->dsi.LANE_NUM		    = LCM_THREE_LANE;
		//The following defined the fomat for data coming from LCD engine.
		params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
		params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
		params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
		params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

		// Highly depends on LCD driver capability.
		// Not support in MT6573
		params->dsi.packet_size=256;

		// Video mode setting
		params->dsi.intermediat_buffer_num = 0;//because DSI/DPI HW design change, this parameters should be 0 when video mode in MT658X; or memory leakage

		params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
		params->dsi.word_count=720*3;


		params->dsi.vertical_sync_active				= 6;// 3    2
		params->dsi.vertical_backporch					= 16;// 20   1
		params->dsi.vertical_frontporch					= 16; // 1  12
		params->dsi.vertical_active_line				= FRAME_HEIGHT;

		params->dsi.horizontal_sync_active				= 10;// 50  2
		params->dsi.horizontal_backporch				= 30;
		params->dsi.horizontal_frontporch				= 30 ;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

	    //params->dsi.LPX=8;

		// Bit rate calculation
		//1 Every lane speed
        	//params->dsi.pll_select=1;
	    params->dsi.PLL_CLOCK = 260; //this value must be in MTK suggested table

params->dsi.esd_check_enable = 1;
params->dsi.customization_esd_check_enable = 1;
params->dsi.lcm_esd_check_table[0].count = 1;
params->dsi.lcm_esd_check_table[0].cmd = 10;
params->dsi.lcm_esd_check_table[0].para_list[0] = 156;

params->dsi.noncont_clock_period = 2;
params->dsi.clk_lp_per_line_enable = 1;
}

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
    unsigned int i;

    for(i = 0; i < count; i++) {
       
        unsigned cmd;
        cmd = table[i].cmd;
       
        switch (cmd) {

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

static struct LCM_setting_table lcm_initialization_setting[] = {
{0XFF, 4, {0XAA, 0X55, 0X25, 0X01}},
{0X6F, 1, {0X03}},
{0XF4, 1, {0X60}},
{0X6F, 1, {0X06}},
{0XF4, 1, {0X01}},
{0X6F, 1, {0X21}},
{0XF7, 1, {0X01}},
{REGFLAG_DELAY, 1, {}},
{0X6F, 1, {0X21}},
{0XF7, 1, {0X00}},
{REGFLAG_DELAY, 1, {}},
{REGFLAG_DELAY, 1, {}},
{REGFLAG_DELAY, 1, {}},
{0X6F, 1, {0X16}},
{0XF7, 1, {0X10}},
{REGFLAG_DELAY, 1, {}},
{0XFF, 4, {0XAA, 0X55, 0X25, 0X00}},
{0XFF, 4, {0XAA, 0X55, 0XA5, 0X80}},
{0X6F, 2, {0X11, 0X00}},
{0XF7, 2, {0X20, 0X00}},
{0X6F, 1, {0X06}},
{0XF7, 1, {0XA0}},
{0X6F, 1, {0X19}},
{0XF7, 1, {0X12}},
{0X6F, 1, {0X02}},
{0XF7, 1, {0X47}},
{0X6F, 1, {0X17}},
{0XF4, 1, {0X70}},
{0X6F, 1, {0X01}},
{0XF9, 1, {0X46}},
{0XF0, 5, {0X55, 0XAA, 0X52, 0X08, 0X00}},
{0XBD, 5, {0X01, 0XA0, 0X10, 0X10, 0X01}},
{0XB8, 4, {0X00, 0X00, 0X00, 0X00}},
{0XBB, 2, {0X24, 0X24}},
{0XBC, 2, {0X00, 0X00}},
{0XB6, 1, {0X04}},
{0XC8, 1, {0X80}},
{0XD9, 2, {0X01, 0X01}},
{0XD4, 1, {0XC7}},
{0XB1, 2, {0X60, 0X21}},
{0XF0, 5, {0X55, 0XAA, 0X52, 0X08, 0X01}},
{0XB0, 2, {0X09, 0X09}},
{0XB1, 2, {0X09, 0X09}},
{0XBC, 2, {0X90, 0X00}},
{0XBD, 2, {0X90, 0X00}},
{0XBE, 1, {0X5F}},
{0XCA, 1, {0X00}},
{0XC0, 1, {0X0C}},
{0XB5, 2, {0X03, 0X03}},
{0XB3, 2, {0X1E, 0X1E}},
{0XB4, 2, {0X21, 0X21}},
{0XB9, 2, {0X26, 0X26}},
{0XBA, 2, {0X14, 0X14}},
{0XF0, 5, {0X55, 0XAA, 0X52, 0X08, 0X02}},
{0XB0, 16, {0X00, 0X0E, 0X00, 0X69, 0X00, 0X96, 0X00, 0XB5, 0X00, 0XD0, 0X00, 0XF4, 0X01, 0X11, 0X01, 0X3F}},
{0XB1, 16, {0X01, 0X62, 0X01, 0X9C, 0X01, 0XC9, 0X02, 0X0E, 0X02, 0X44, 0X02, 0X48, 0X02, 0X74, 0X02, 0XA9}},
{0XB2, 16, {0X02, 0XCB, 0X02, 0XF6, 0X03, 0X16, 0X03, 0X3F, 0X03, 0X5C, 0X03, 0X73, 0X03, 0X9B, 0X03, 0X9F}},
{0XB3, 4, {0X03, 0XD7, 0X03, 0XE8}},
{0XB4, 16, {0X00, 0X05, 0X00, 0X50, 0X00, 0X8D, 0X00, 0XAD, 0X00, 0XC4, 0X00, 0XEB, 0X01, 0X09, 0X01, 0X39}},
{0XB5, 16, {0X01, 0X5E, 0X01, 0X97, 0X01, 0XC4, 0X02, 0X08, 0X02, 0X3D, 0X02, 0X3E, 0X02, 0X70, 0X02, 0XA4}},
{0XB6, 16, {0X02, 0XC5, 0X02, 0XF2, 0X03, 0X11, 0X03, 0X3B, 0X03, 0X58, 0X03, 0X6C, 0X03, 0X96, 0X03, 0XCA}},
{0XB7, 4, {0X03, 0XF5, 0X03, 0XF8}},
{0XB8, 16, {0X00, 0X14, 0X00, 0X3B, 0X00, 0X6F, 0X00, 0X8E, 0X00, 0XA9, 0X00, 0XD1, 0X00, 0XF1, 0X01, 0X24}},
{0XB9, 16, {0X01, 0X4C, 0X01, 0X8A, 0X01, 0XB9, 0X02, 0X03, 0X02, 0X3A, 0X02, 0X3B, 0X02, 0X6E, 0X02, 0XA4}},
{0XBA, 16, {0X02, 0XC5, 0X02, 0XF4, 0X03, 0X16, 0X03, 0X4D, 0X03, 0X81, 0X03, 0XF9, 0X03, 0XFA, 0X03, 0XFB}},
{0XBB, 4, {0X03, 0XFD, 0X03, 0XFE}},
{0XBC, 16, {0X00, 0X0E, 0X00, 0X69, 0X00, 0X96, 0X00, 0XB5, 0X00, 0XD0, 0X00, 0XF4, 0X01, 0X11, 0X01, 0X3F}},
{0XBD, 16, {0X01, 0X62, 0X01, 0X9C, 0X01, 0XC9, 0X02, 0X0E, 0X02, 0X44, 0X02, 0X48, 0X02, 0X74, 0X02, 0XA9}},
{0XBE, 16, {0X02, 0XCB, 0X02, 0XF6, 0X03, 0X16, 0X03, 0X3F, 0X03, 0X5C, 0X03, 0X73, 0X03, 0X9B, 0X03, 0X9F}},
{0XBF, 4, {0X03, 0XD7, 0X03, 0XE8}},
{0XC0, 16, {0X00, 0X05, 0X00, 0X50, 0X00, 0X8D, 0X00, 0XAD, 0X00, 0XC4, 0X00, 0XEB, 0X01, 0X09, 0X01, 0X39}},
{0XC1, 16, {0X01, 0X5E, 0X01, 0X97, 0X01, 0XC4, 0X02, 0X08, 0X02, 0X3D, 0X02, 0X3E, 0X02, 0X70, 0X02, 0XA4}},
{0XC2, 16, {0X02, 0XC5, 0X02, 0XF2, 0X03, 0X11, 0X03, 0X3B, 0X03, 0X58, 0X03, 0X6C, 0X03, 0X96, 0X03, 0XCA}},
{0XC3, 4, {0X03, 0XF5, 0X03, 0XF8}},
{0XC4, 16, {0X00, 0X14, 0X00, 0X3B, 0X00, 0X6F, 0X00, 0X8E, 0X00, 0XA9, 0X00, 0XD1, 0X00, 0XF1, 0X01, 0X24}},
{0XC5, 16, {0X01, 0X4C, 0X01, 0X8A, 0X01, 0XB9, 0X02, 0X03, 0X02, 0X3A, 0X02, 0X3B, 0X02, 0X6E, 0X02, 0XA4}},
{0XC6, 16, {0X02, 0XC5, 0X02, 0XF4, 0X03, 0X16, 0X03, 0X4D, 0X03, 0X81, 0X03, 0XF9, 0X03, 0XFA, 0X03, 0XFB}},
{0XC7, 4, {0X03, 0XFD, 0X03, 0XFE}},
{0XF0, 5, {0X55, 0XAA, 0X52, 0X08, 0X06}},
{0XB0, 2, {0X31, 0X2E}},
{0XB1, 2, {0X10, 0X12}},
{0XB2, 2, {0X16, 0X18}},
{0XB3, 2, {0X31, 0X31}},
{0XB4, 2, {0X31, 0X34}},
{0XB5, 2, {0X34, 0X34}},
{0XB6, 2, {0X34, 0X34}},
{0XB7, 2, {0X34, 0X34}},
{0XB8, 2, {0X33, 0X2D}},
{0XB9, 2, {0X00, 0X02}},
{0XBA, 2, {0X03, 0X01}},
{0XBB, 2, {0X2D, 0X33}},
{0XBC, 2, {0X34, 0X34}},
{0XBD, 2, {0X34, 0X34}},
{0XBE, 2, {0X34, 0X34}},
{0XBF, 2, {0X34, 0X31}},
{0XC0, 2, {0X31, 0X31}},
{0XC1, 2, {0X19, 0X17}},
{0XC2, 2, {0X13, 0X11}},
{0XC3, 2, {0X2E, 0X31}},
{0XE5, 2, {0X31, 0X31}},
{0XC4, 2, {0X31, 0X2D}},
{0XC5, 2, {0X19, 0X17}},
{0XC6, 2, {0X13, 0X11}},
{0XC7, 2, {0X31, 0X31}},
{0XC8, 2, {0X31, 0X34}},
{0XC9, 2, {0X34, 0X34}},
{0XCA, 2, {0X34, 0X34}},
{0XCB, 2, {0X34, 0X34}},
{0XCC, 2, {0X33, 0X2E}},
{0XCD, 2, {0X03, 0X01}},
{0XCE, 2, {0X00, 0X02}},
{0XCF, 2, {0X2E, 0X33}},
{0XD0, 2, {0X34, 0X34}},
{0XD1, 2, {0X34, 0X34}},
{0XD2, 2, {0X34, 0X34}},
{0XD3, 2, {0X34, 0X31}},
{0XD4, 2, {0X31, 0X31}},
{0XD5, 2, {0X10, 0X12}},
{0XD6, 2, {0X16, 0X18}},
{0XD7, 2, {0X2D, 0X31}},
{0XE6, 2, {0X31, 0X31}},
{0XD8, 5, {0X00, 0X00, 0X00, 0X00, 0X00}},
{0XD9, 5, {0X00, 0X00, 0X00, 0X00, 0X00}},
{0XE7, 1, {0X00}},
{0XF0, 5, {0X55, 0XAA, 0X52, 0X08, 0X05}},
{0XED, 1, {0X30}},
{0XB0, 2, {0X17, 0X06}},
{0XB8, 1, {0X00}},
{0XC0, 1, {0X0D}},
{0XC1, 1, {0X0B}},
{0XC2, 1, {0X00}},
{0XC3, 1, {0X00}},
{0XC4, 1, {0X84}},
{0XC5, 1, {0X82}},
{0XC6, 1, {0X82}},
{0XC7, 1, {0X80}},
{0XC8, 2, {0X0B, 0X20}},
{0XC9, 2, {0X07, 0X20}},
{0XCA, 2, {0X01, 0X10}},
{0XD1, 5, {0X03, 0X05, 0X05, 0X07, 0X00}},
{0XD2, 5, {0X03, 0X05, 0X09, 0X03, 0X00}},
{0XD3, 5, {0X00, 0X00, 0X6A, 0X07, 0X10}},
{0XD4, 5, {0X30, 0X00, 0X6A, 0X07, 0X10}},
{0XF0, 5, {0X55, 0XAA, 0X52, 0X08, 0X03}},
{0XB0, 2, {0X00, 0X00}},
{0XB1, 2, {0X00, 0X00}},
{0XB2, 5, {0X05, 0X01, 0X13, 0X00, 0X00}},
{0XB3, 5, {0X05, 0X01, 0X13, 0X00, 0X00}},
{0XB4, 5, {0X05, 0X01, 0X13, 0X00, 0X00}},
{0XB5, 5, {0X05, 0X01, 0X13, 0X00, 0X00}},
{0XB6, 5, {0X02, 0X01, 0X13, 0X00, 0X00}},
{0XB7, 5, {0X02, 0X01, 0X13, 0X00, 0X00}},
{0XB8, 5, {0X02, 0X01, 0X13, 0X00, 0X00}},
{0XB9, 5, {0X02, 0X01, 0X13, 0X00, 0X00}},
{0XBA, 5, {0X53, 0X01, 0X13, 0X00, 0X00}},
{0XBB, 5, {0X53, 0X01, 0X13, 0X00, 0X00}},
{0XBC, 5, {0X53, 0X01, 0X13, 0X00, 0X00}},
{0XBD, 5, {0X53, 0X01, 0X13, 0X00, 0X00}},
{0XC4, 1, {0X60}},
{0XC5, 1, {0X40}},
{0XC6, 1, {0X64}},
{0XC7, 1, {0X44}},
{0X6F, 1, {0X11}},
{0XF3, 1, {0X01}},
{0X35, 1, {0X00}},
{0X11, 1, {0X00}},
{REGFLAG_DELAY, 150, {}},
{0X29, 1, {0X00}},
{REGFLAG_DELAY, 50, {}},
};

static void lcm_init(void)
{
    unsigned int data_array[16];   
    SET_RESET_PIN(1);
    SET_RESET_PIN(0);
    MDELAY(50);
    SET_RESET_PIN(1);
    MDELAY(120);
   // lcm_initialization();
    push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}

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
    //MDELAY(1);
   
    data_array[0]= 0x00053902;
    data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
    data_array[2]= (y1_LSB);
    dsi_set_cmdq(data_array, 3, 1);
    //MDELAY(1);
   
    data_array[0]= 0x00290508;
    dsi_set_cmdq(data_array, 1, 1);
    //MDELAY(1);
   
    data_array[0]= 0x002c3909;
    dsi_set_cmdq(data_array, 1, 0);
    //MDELAY(1);

}

static void lcm_suspend(void)
{
    unsigned int data_array[16];
    data_array[0]=0x00280500;
    dsi_set_cmdq(data_array,1,1);
    MDELAY(10);
    data_array[0]=0x00100500;
    dsi_set_cmdq(data_array,1,1);
    MDELAY(100);
}


static void lcm_resume(void)
{
    unsigned int data_array[16];
    data_array[0]=0x00110500;
    dsi_set_cmdq(data_array,1,1);
    MDELAY(100);
    data_array[0]=0x00290500;
    dsi_set_cmdq(data_array,1,1);
    MDELAY(10);
}


static unsigned int lcm_compare_id(void)
{
    unsigned int id=0;
    unsigned char buffer[3];
    unsigned int array[16]; 
    unsigned int data_array[16];

    SET_RESET_PIN(1);
        MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(50);
   
    SET_RESET_PIN(1);
    MDELAY(120);

    data_array[0] = 0x00063902;
    data_array[1] = 0x52AA55F0; 
    data_array[2] = 0x00000108;               
    dsi_set_cmdq(data_array, 3, 1);

    array[0] = 0x00033700;// read id return two byte,version and id
    dsi_set_cmdq(array, 1, 1);
   
    read_reg_v2(0xC5, buffer, 3);
    id = buffer[1]; //we only need ID
    #ifdef BUILD_LK
        printf("%s, LK nt35590 debug: nt35590 id = 0x%08x buffer[0]=0x%08x,buffer[1]=0x%08x,buffer[2]=0x%08x\n", __func__, id,buffer[0],buffer[1],buffer[2]);
    #else
        printk("%s, LK nt35590 debug: nt35590 id = 0x%08x buffer[0]=0x%08x,buffer[1]=0x%08x,buffer[2]=0x%08x\n", __func__, id,buffer[0],buffer[1],buffer[2]);
    #endif

   // if(id == LCM_ID_NT35521)
    if(buffer[0]==0x55 && buffer[1]==0x21)
        return 1;
    else
        return 0;


}




static int err_count = 0;

static unsigned int lcm_esd_check(void)
{
#ifndef BUILD_LK
    unsigned char buffer[8] = {0};
    unsigned int array[4];
    int i =0;

    array[0] = 0x00013700;   
    dsi_set_cmdq(array, 1,1);
    read_reg_v2(0x0A, buffer,8);

    printk( "nt35521_JDI lcm_esd_check: buffer[0] = %d,buffer[1] = %d,buffer[2] = %d,buffer[3] = %d,buffer[4] = %d,buffer[5] = %d,buffer[6] = %d,buffer[7] = %d\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6],buffer[7]);

    if((buffer[0] != 0x9C))/*LCD work status error,need re-initalize*/
    {
        printk( "nt35521_JDI lcm_esd_check buffer[0] = %d\n",buffer[0]);
        return TRUE;
    }
    else
    {
        if(buffer[3] != 0x02) //error data type is 0x02
        {
             //return FALSE;
        err_count = 0;
        }
        else
        {
             //if(((buffer[4] != 0) && (buffer[4] != 0x40)) ||  (buffer[5] != 0x80))
        if( (buffer[4] == 0x40) || (buffer[5] == 0x80))
             {
                  err_count = 0;
             }
             else
             {
                  err_count++;
             }            
             if(err_count >=2 )
             {
                 err_count = 0;
                 printk( "nt35521_JDI lcm_esd_check buffer[4] = %d , buffer[5] = %d\n",buffer[4],buffer[5]);
                 return TRUE;
             }
        }
        return FALSE;
    }
#endif
   
}

static unsigned int lcm_esd_recover(void)
{
    lcm_init();
    return TRUE;
}

// ---------------------------------------------------------------------------
//  Get LCM Driver Hooks
// ---------------------------------------------------------------------------
LCM_DRIVER hct_nt35521s_dsi_vdo_hd_boe_50_xld= 
{
    .name			= "hct_nt35521s_dsi_vdo_hd_boe_50_xld",
    .set_util_funcs = lcm_set_util_funcs,
    .get_params     = lcm_get_params,
    .init           = lcm_init,
    .suspend        = lcm_suspend,
    .resume         = lcm_resume,
    .compare_id    = lcm_compare_id,
#if 0//defined(LCM_DSI_CMD_MODE)
//    .set_backlight	= lcm_setbacklight,
    //.set_pwm        = lcm_setpwm,
    //.get_pwm        = lcm_getpwm,
    .update         = lcm_update
#endif
};

