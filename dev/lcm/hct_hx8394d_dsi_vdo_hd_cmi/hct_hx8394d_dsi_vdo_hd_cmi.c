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

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  										(720)
#define FRAME_HEIGHT 										(1280)

#define LCM_ID                      								(0x0d)

#define REGFLAG_DELAY             								(0XFE)
#define REGFLAG_END_OF_TABLE      								(0x100)	// END OF REGISTERS MARKER

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

#define SET_RESET_PIN(v)    									(lcm_util.set_reset_pin((v)))

#define UDELAY(n) 										(lcm_util.udelay(n))
#define MDELAY(n) 										(lcm_util.mdelay(n))


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg                                            lcm_util.dsi_read_reg()
#define read_reg_v2(cmd, buffer, buffer_size)				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

 struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};

#if 0
static struct LCM_setting_table lcm_initialization_setting[] = {
	// Set EXTC 
	{0xB9, 3, {0xFF,0x83,0x94}},
	
	// Set MIPI 
	{0xBA, 2, {0x73,0x83}},

	#if 1	//HX5186 Mode 
	// Set Power   HX5186 Mode 
	{0xB1, 15, {0x6C,0x12,0x12,0x34,0x04,0x11,0xF1,0x80,0xFA,0x54,0x23,0x80,0xC0,0xD2,0x58}},

	#else	//External Power mode 
	// Set Power   External Power mode 
	{0xB1, 15, {0x6C,0x12,0x12,0x34,0x04,0x11,0xF1,0x80,0xFA,0x54,0x23,0x80,0xC0,0xD2,0x58}},
	#endif
	
	// Set Display 
	{0xB2, 11, {0x00,0x64,0x0E,0x0D,0x32,0x1C,0x08,0x08,0x1C,0x4D,0x00}},
	
	// Set CYC 
	{0xB4, 12, {0x00,0xFF,0x51,0x5A,0x59,0x5A,0x03,0x5A,0x01,0x60,0x20,0x60}},
	
	// Set VDC 
	{0xBC, 1, {0x07}},
	
	// Set Power Option   HX5186 Mode	
	{0xBF, 3, {0x41,0x0E,0x01}},
	
	// Set Gamma 
	{0xE0, 42, {0x00,0x0E,0x13,0x32,0x37,0x3F,0x20,0x40,0x07,0x0B,0x0D,0x17,0x0E,0x10,0x14,0x12,0x13,0x06,0x10,0x10,0x17,0x00,0x0D,0x14,0x33,0x38,0x3F,0x21,0x3F,0x06,0x0A,0x0C,0x17,0x0D,0x11,0x13,0x12,0x14,0x07,0x11,0x12,0x16}},
	
	// Set GIP 
	{0xD3, 30, {0x00,0x07,0x00,0x40,0x07,0x10,0x00,0x08,0x10,0x08,0x00,0x08,0x54,0x15,0x0E,0x05,0x0E,0x02,0x15,0x06,0x05,0x06,0x47,0x44,0x0A,0x0A,0x4B,0x10,0x07,0x07}},
	
	// Set Forward GIP 
	{0xD5, 44, {0x1A,0x1A,0x1B,0x1B,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x24,0x25,0x18,0x18,0x26,0x27,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x20,0x21,0x18,0x18,0x18,0x18}},
	
	// Set Backward GIP  
	{0xD6, 44, {0x1A,0x1A,0x1B,0x1B,0x0B,0x0A,0x09,0x08,0x07,0x06,
				0x05,0x04,0x03,0x02,0x01,0x00,0x21,0x20,0x58,0x58,
				0x27,0x26,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
				0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x25,0x24,
				0x18,0x18,0x18,0x18}},
	
	// Set Panel 
	{0xCC, 1, {0x01}},
	
	// Set C0 
	{0xC0, 2, {0x30,0x14}},
	
	// Set TCON Option 
	{0xC7, 4, {0x00,0xC0,0x40,0xC0}},
	
	//-----------------------------------------------------
    {0x11,  0,  {0}},
    {REGFLAG_DELAY, 120, {0}},

    {0x29,  0,  {0}},
    {REGFLAG_DELAY, 20, {0}},
};





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

#endif
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
	params->dbi.te_mode 			= LCM_DBI_TE_MODE_DISABLED;
    //params->dbi.te_edge_polarity          = LCM_POLARITY_RISING;

	params->dsi.mode   =SYNC_EVENT_VDO_MODE;

	// DSI
	/* Command mode setting */
	params->dsi.LANE_NUM			= LCM_FOUR_LANE;
	//The following defined the fomat for data coming from LCD engine. 
	params->dsi.data_format.color_order 	= LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   	= LCM_DSI_TRANS_SEQ_MSB_FIRST; 
	params->dsi.data_format.padding     	= LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      	= LCM_DSI_FORMAT_RGB888;
	// Highly depends on LCD driver capability.
	// Not support in MT6573
	params->dsi.packet_size=256;
	// Video mode setting		
	params->dsi.intermediat_buffer_num 	= 2;
	params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
        //params->dsi.word_count=720 * 3;
	params->dsi.vertical_sync_active				= 4;//5
	params->dsi.vertical_backporch					= 12;
	params->dsi.vertical_frontporch					= 15;
	params->dsi.vertical_active_line				= FRAME_HEIGHT; 
	params->dsi.horizontal_sync_active				= 40;//38//15
	params->dsi.horizontal_backporch				= 40;//38//70
	params->dsi.horizontal_frontporch				= 40;//38//65
	//params->dsi.horizontal_blanking_pixel		       		= 60;
	params->dsi.horizontal_active_pixel		       		= FRAME_WIDTH;
	// Bit rate calculation

#if FRAME_WIDTH == 480	
	params->dsi.PLL_CLOCK=210;//254//247
#elif FRAME_WIDTH == 540
	params->dsi.PLL_CLOCK=230;
#elif FRAME_WIDTH == 720
	params->dsi.PLL_CLOCK=218;//256   276
#elif FRAME_WIDTH == 1080
	params->dsi.PLL_CLOCK=410;
#else
	params->dsi.PLL_CLOCK=230;
#endif
          
          params->dsi.esd_check_enable = 1;
          params->dsi.customization_esd_check_enable = 1;
          params->dsi.cont_clock=0; //1;
          params->dsi.lcm_esd_check_table[0].cmd          = 0xd9;
	params->dsi.lcm_esd_check_table[0].count        = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x80;
          /*
          params->dsi.lcm_esd_check_table[0].cmd = 0x9;//09 ,45,d9
          params->dsi.lcm_esd_check_table[0].count = 3;
          params->dsi.lcm_esd_check_table[0].para_list[0] = 0x80;
          params->dsi.lcm_esd_check_table[0].para_list[1] = 0x73;
          params->dsi.lcm_esd_check_table[0].para_list[2] = 0x6;//04/06

          params->dsi.lcm_esd_check_table[1].cmd = 0xd9;
          params->dsi.lcm_esd_check_table[1].count = 1;
          params->dsi.lcm_esd_check_table[1].para_list[0] = 0x80;
          //params->dsi.lcm_esd_check_table[1].para_list[1] = 0x00;
          //params->dsi.lcm_esd_check_table[1].para_list[2] = 0x45;

          params->dsi.lcm_esd_check_table[2].cmd = 0x45;
          params->dsi.lcm_esd_check_table[2].count = 2;
          params->dsi.lcm_esd_check_table[2].para_list[0] = 0x5;
          params->dsi.lcm_esd_check_table[2].para_list[1] = 0x1d;
          */
}

static void lcm_init_register(void)
{
    unsigned int data_array[16];
    MDELAY(180);
    data_array[0] = 0x00043902;
    data_array[1] = 0x9483ffb9;
    dsi_set_cmdq(data_array, 2, 1);

    data_array[0] = 0x00033902;
    data_array[1] = 0x008373ba;
    dsi_set_cmdq(data_array, 2, 1);

    data_array[0] = 0x00103902;
    data_array[1] = 0x12126cb1;
    data_array[2] = 0xf1110434;
    data_array[3] = 0x2354fa80;
    data_array[4] = 0x58d2c080;
    dsi_set_cmdq(data_array, 5, 1);

    data_array[0] = 0x000c3902;
    data_array[1] = 0x0e6400b2;
    data_array[2] = 0x081c320d;
    data_array[3] = 0x004d1c08;
    dsi_set_cmdq(data_array, 4, 1);

    data_array[0] = 0x000d3902;
    data_array[1] = 0x51ff00b4;
    data_array[2] = 0x035a595a;
    data_array[3] = 0x2070015a;
    data_array[4] = 0x00000070;
    dsi_set_cmdq(data_array, 5, 1);

    data_array[0] = 0x00023902;
    data_array[1] = 0x000007bc;
    dsi_set_cmdq(data_array, 2, 1);

    data_array[0] = 0x00043902;
    data_array[1] = 0x010e41bf;
    dsi_set_cmdq(data_array, 2, 1);

    data_array[0] = 0x002b3902;
    data_array[1] = 0x130e00e0;
    data_array[2] = 0x203f3732;
    data_array[3] = 0x0d0b0740;
    data_array[4] = 0x14100e17;
    data_array[5] = 0x10061312;
    data_array[6] = 0x0d001710;
    data_array[7] = 0x3f383314;
    data_array[8] = 0x0a063f21;
    data_array[9] = 0x110d170c;
    data_array[10] = 0x07141213;
    data_array[11] = 0x00161211;
    dsi_set_cmdq(data_array, 12, 1);

    data_array[0] = 0x001f3902;
    data_array[1] = 0x000700d3;
    data_array[2] = 0x00100740;
    data_array[3] = 0x00081008;
    data_array[4] = 0x0e155408;
    data_array[5] = 0x15020e05;
    data_array[6] = 0x47060506;
    data_array[7] = 0x4b0a0a44;
    data_array[8] = 0x00070710;
    dsi_set_cmdq(data_array, 9, 1);

    data_array[0] = 0x002d3902;
    data_array[1] = 0x1b1a1ad5;
    data_array[2] = 0x0201001b;
    data_array[3] = 0x06050403;
    data_array[4] = 0x0a090807;
    data_array[5] = 0x1825240b;
    data_array[6] = 0x18272618;
    data_array[7] = 0x18181818;
    data_array[8] = 0x18181818;
    data_array[9] = 0x18181818;
    data_array[10] = 0x20181818;
    data_array[11] = 0x18181821;
    data_array[12] = 0x00000018;
    dsi_set_cmdq(data_array, 13, 1);

    data_array[0] = 0x002d3902;
    data_array[1] = 0x1b1a1ad6;
    data_array[2] = 0x090a0b1b;
    data_array[3] = 0x05060708;
    data_array[4] = 0x01020304;
    data_array[5] = 0x58202100;
    data_array[6] = 0x18262758;
    data_array[7] = 0x18181818;
    data_array[8] = 0x18181818;
    data_array[9] = 0x18181818;
    data_array[10] = 0x25181818;
    data_array[11] = 0x18181824;
    data_array[12] = 0x00000018;
    dsi_set_cmdq(data_array, 13, 1);

    data_array[0] = 0x00023902;
    data_array[1] = 0x0000bdc6;
    dsi_set_cmdq(data_array, 2, 1);

    data_array[0] = 0x00023902;
    data_array[1] = 0x000002bd;
    dsi_set_cmdq(data_array, 2, 1);

    data_array[0] = 0x000d3902;
    data_array[1] = 0xeeffffd8;
    data_array[2] = 0xffa0fbeb;
    data_array[3] = 0xfbebeeff;
    data_array[4] = 0x000000a0;
    dsi_set_cmdq(data_array, 5, 1);

    data_array[0] = 0x00023902;
    data_array[1] = 0x000009cc;
    dsi_set_cmdq(data_array, 2, 1);

    data_array[0] = 0x00033902;
    data_array[1] = 0x001430c0;
    dsi_set_cmdq(data_array, 2, 1);

    data_array[0] = 0x00053902;
    data_array[1] = 0x40c000c7;
    data_array[2] = 0x000000c0;
    dsi_set_cmdq(data_array, 3, 1);

    data_array[0] = 0x00033902;
    data_array[1] = 0x006767b6;
    dsi_set_cmdq(data_array, 2, 1);

    MDELAY(15);
    data_array[0] = 0x00110500;
    dsi_set_cmdq(data_array, 1, 1);
    MDELAY(120);
    data_array[0] = 0x00290500;
    dsi_set_cmdq(data_array, 1, 1);
    MDELAY(20);
}

static void lcm_init(void)
{
    SET_RESET_PIN(1);
    MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(10);
    SET_RESET_PIN(1);
    MDELAY(120);

	lcm_init_register();
    //push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_suspend(void)
{
    unsigned int data_array[16];
    data_array[0]=0x00280500;
    dsi_set_cmdq(data_array, 1, 1);
    MDELAY(10);
    data_array[0]=0x00100500;
    dsi_set_cmdq(data_array, 1, 1);
    SET_RESET_PIN(1);
    MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(50);
}

static unsigned int lcm_compare_id(void);

static void lcm_resume(void)
{
	lcm_init();
}



	
static unsigned int lcm_compare_id(void)
{
	unsigned int id=0;
	unsigned char buffer[2];
	unsigned int array[16];  

	SET_RESET_PIN(1);
	MDELAY(1);
	SET_RESET_PIN(0);
	MDELAY(1);
	SET_RESET_PIN(1);
	MDELAY(120);//Must over 6 ms

	array[0]=0x00043902;
	array[1]=0x9483FFB9;// page enable
	dsi_set_cmdq(array, 2, 1);
	MDELAY(10);

	array[0]=0x00033902; 
	array[1]=0x008372BA;// page enable //9341
	//array[2]=0x1800A416; 
	dsi_set_cmdq(array, 2, 1); 
	MDELAY(10); 

	array[0] = 0x00023700;// return byte number
	dsi_set_cmdq(array, 1, 1);
	MDELAY(10);

	read_reg_v2(0xdc, buffer, 2);
	id = buffer[0]; 

#ifdef BUILD_LK
	printf("[HX8394D]%s,  id = 0x%x\n", __func__, id);
#else
	printk("[HX8394D]%s,  id = 0x%x\n", __func__, id);
#endif


    return (LCM_ID == id)?1:0;
}

// ---------------------------------------------------------------------------
//  Get LCM Driver Hooks
// ---------------------------------------------------------------------------
LCM_DRIVER hct_hx8394d_dsi_vdo_hd_cmi = 
{
	.name			  = "hct_hx8394d_dsi_vdo_hd_cmi",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,	
	.compare_id     = lcm_compare_id,	
//	.esd_check   = lcm_esd_check,	
//	.esd_recover   = lcm_esd_recover,	
//	.update         = lcm_update,
};

