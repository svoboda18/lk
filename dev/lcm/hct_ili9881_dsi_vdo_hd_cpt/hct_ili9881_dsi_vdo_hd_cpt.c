
/*----------------------------------------------------------------
* Author : Rubén Espínola (ruben1863@github.com)
* Contact : rubenes2003@gmail.com
* Supported device: DOOGEE X5
* Reversed for SaMad SegMane
* Copyright 2019 © Rubén Espínola
 *---------------------------------------------------------------*/

#ifndef BUILD_LK
#include <linux/string.h>
#endif

#include "lcm_drv.h"

#if defined(BUILD_LK)
#else

#include <linux/proc_fs.h>
#endif


// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH                                         (720)
#define FRAME_HEIGHT                                        (1280)

#define LCM_ID                       (0x1283)

#define REGFLAG_DELAY               (0XFE)
#define REGFLAG_END_OF_TABLE        (0x00)


// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v) (lcm_util.set_reset_pin((v)))
#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V3(para_tbl,size,force_update)         lcm_util.dsi_set_cmdq_V3(para_tbl,size,force_update)
#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define read_reg_v2(cmd, buffer, buffer_size)	            lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)
#define write_regs(addr, pdata, byte_nums)	                lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)   lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define wrtie_cmd(cmd)	lcm_util.dsi_write_cmd(cmd)

struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};

static struct LCM_setting_table lcm_initialization_setting[] = {
	{0xFF, 3, {0x98,0x81,0x07}},
	{0x03, 1, {0x20}},
	{0x04, 1, {0x06}},
	{0x05, 1, {0x00}},
	{0x06, 1, {0x01}},
	{0x07, 1, {0x00}},
	{0x08, 1, {0x00}},
	{0x09, 1, {0x00}},
	{0x0A, 1, {0x00}},
	{0x0B, 1, {0x2F}},
	{0x0C, 1, {0x00}},
	{0x0D, 1, {0x00}},
	{0x0E, 1, {0x00}},
	{0x0F, 1, {0x00}},
	{0x10, 1, {0x40}},
	{0x11, 1, {0x02}},
	{0x12, 1, {0x05}},
	{0x13, 1, {0x90}},
	{0x14, 1, {0x02}},
	{0x15, 1, {0x00}},
	{0x16, 1, {0x2F}},
	{0x17, 1, {0x2F}},
	{0x18, 1, {0x00}},
	{0x19, 1, {0x00}},
	{0x1A, 1, {0x00}},
	{0x1B, 1, {0x50}},
	{0x1C, 1, {0x2C}},
	{0x1D, 1, {0x0C}},
	{0x1E, 1, {0x00}},
	{0x1F, 1, {0x87}},
	{0x20, 1, {0x86}},
	{0x21, 1, {0x00}},
	{0x22, 1, {0x00}},
	{0x23, 1, {0xC0}},
	{0x24, 1, {0x30}},
	{0x25, 1, {0x00}},
	{0x26, 1, {0x00}},
	{0x27, 1, {0x03}},
	{0x30, 1, {0x01}},
	{0x31, 1, {0x23}},
	{0x32, 1, {0x45}},
	{0x33, 1, {0x67}},
	{0x34, 1, {0x89}},
	{0x35, 1, {0xAB}},
	{0x36, 1, {0x01}},
	{0x37, 1, {0x23}},
	{0x38, 1, {0x45}},
	{0x39, 1, {0x67}},
	{0x3A, 1, {0x89}},
	{0x3B, 1, {0xAB}},
	{0x3C, 1, {0xCD}},
	{0x3D, 1, {0xEF}},
	{0x50, 1, {0x11}},
	{0x51, 1, {0x06}},
	{0x52, 1, {0x0C}},
	{0x53, 1, {0x0D}},
	{0x54, 1, {0x0E}},
	{0x55, 1, {0x0F}},
	{0x56, 1, {0x02}},
	{0x57, 1, {0x02}},
	{0x58, 1, {0x02}},
	{0x59, 1, {0x02}},
	{0x5A, 1, {0x02}},
	{0x5B, 1, {0x02}},
	{0x5C, 1, {0x02}},
	{0x5D, 1, {0x02}},
	{0x5E, 1, {0x02}},
	{0x5F, 1, {0x02}},
	{0x60, 1, {0x05}},
	{0x61, 1, {0x05}},
	{0x62, 1, {0x05}},
	{0x63, 1, {0x02}},
	{0x64, 1, {0x01}},
	{0x65, 1, {0x00}},
	{0x66, 1, {0x08}},
	{0x67, 1, {0x08}},
	{0x68, 1, {0x0C}},
	{0x69, 1, {0x0D}},
	{0x6A, 1, {0x0E}},
	{0x6B, 1, {0x0F}},
	{0x6C, 1, {0x02}},
	{0x6D, 1, {0x02}},
	{0x6E, 1, {0x02}},
	{0x6F, 1, {0x02}},
	{0x70, 1, {0x02}},
	{0x71, 1, {0x02}},
	{0x72, 1, {0x02}},
	{0x73, 1, {0x02}},
	{0x74, 1, {0x02}},
	{0x75, 1, {0x02}},
	{0x76, 1, {0x05}},
	{0x77, 1, {0x05}},
	{0x78, 1, {0x05}},
	{0x79, 1, {0x02}},
	{0x7A, 1, {0x01}},
	{0x7B, 1, {0x00}},
	{0x7C, 1, {0x06}},
	{0xFF, 3, {0x98,0x81,0x08}},
	{0x76, 1, {0xC4}},
	{0x78, 1, {0x02}},
	{0x74, 1, {0x2F}},
	{0x8E, 1, {0x15}},
	{0x40, 1, {0x01}},
	{0x84, 1, {0x81}},
	{0xE3, 1, {0x75}},
	{0x7D, 1, {0xCB}},
	{0x7E, 1, {0x49}},
	{0x49, 1, {0x10}},
	{0x72, 1, {0x25}},
	{0x32, 1, {0x05}},
	{0x3C, 1, {0x05}},
	{0xA3, 1, {0x40}},
	{0xFF, 3, {0x98,0x81,0x01}},
	{0x22, 1, {0x0A}},
	{0x43, 1, {0x01}},
	{0x31, 1, {0x00}},
	{0x53, 1, {0x80}},
	{0x55, 1, {0x15}},
	{0x50, 1, {0x96}},
	{0x51, 1, {0x96}},
	{0xA0, 1, {0x06}},
	{0xA1, 1, {0x18}},
	{0xA2, 1, {0x24}},
	{0xA3, 1, {0x0D}},
	{0xA4, 1, {0x13}},
	{0xA5, 1, {0x23}},
	{0xA6, 1, {0x16}},
	{0xA7, 1, {0x1A}},
	{0xA8, 1, {0x80}},
	{0xA9, 1, {0x1B}},
	{0xAA, 1, {0x26}},
	{0xAB, 1, {0x87}},
	{0xAC, 1, {0x15}},
	{0xAD, 1, {0x12}},
	{0xAE, 1, {0x4C}},
	{0xAF, 1, {0x28}},
	{0xB0, 1, {0x30}},
	{0xB1, 1, {0x67}},
	{0xB2, 1, {0x71}},
	{0xB3, 1, {0x33}},
	{0xC0, 1, {0x0A}},
	{0xC1, 1, {0x15}},
	{0xC2, 1, {0x20}},
	{0xC3, 1, {0x13}},
	{0xC4, 1, {0x13}},
	{0xC5, 1, {0x24}},
	{0xC6, 1, {0x1C}},
	{0xC7, 1, {0x1B}},
	{0xC8, 1, {0x82}},
	{0xC9, 1, {0x1C}},
	{0xCA, 1, {0x2A}},
	{0xCB, 1, {0x84}},
	{0xCC, 1, {0x24}},
	{0xCD, 1, {0x28}},
	{0xCE, 1, {0x59}},
	{0xCF, 1, {0x24}},
	{0xD0, 1, {0x25}},
	{0xD1, 1, {0x60}},
	{0xD2, 1, {0x73}},
	{0xD3, 1, {0x3F}},
	{0xFF, 3, {0x98,0x81,0x00}},
	{0x36, 1, {0x00}},
	{0x11, 1, {0x00}},
    {REGFLAG_DELAY,120,{}}, 
	{0x29, 1, {0x00}},
    {REGFLAG_DELAY,20,{}}, 
	{REGFLAG_END_OF_TABLE, 0x00, {}}  //Stop cmd is 0x00	
};	

static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = 
{
    {0x28, 1, {0x00}},
    {REGFLAG_DELAY, 20, {}},
    {0x10, 1, {0x00}},
    {REGFLAG_DELAY, 120, {}},
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};

static struct LCM_setting_table lcm_sleep_out_setting[] = 
{
    {0x11, 1, {0x00}},
    {REGFLAG_DELAY, 120, {}},
    {0x29, 1, {0x00}},
    {REGFLAG_DELAY, 20, {}},
    {REGFLAG_END_OF_TABLE, 0x00, {}}
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
	params->dsi.LANE_NUM = 3;
	params->dsi.packet_size = 256;
	params->dsi.vertical_backporch = 18;
	params->dsi.vertical_frontporch = 8;
	params->dsi.horizontal_backporch = 92;
	params->dsi.horizontal_frontporch = 76;
	params->dsi.PLL_CLOCK = 284;
	params->dsi.ssc_disable = 1;
	params->width = 720;
	params->type = 2;
	params->dsi.mode = 2;
	params->dsi.data_format.format = 2;
	params->dsi.intermediat_buffer_num = 2;
	params->dsi.PS = 2;
	params->dsi.vertical_sync_active = 2;
	params->dsi.horizontal_active_pixel = 720;
	params->height = 1280;
	params->dsi.vertical_active_line = 1280;
	params->dbi.te_mode = 0;
	params->dbi.te_edge_polarity = 0;
	params->dsi.data_format.color_order = 0;
	params->dsi.data_format.trans_seq = 0;
	params->dsi.data_format.padding = 0;
	params->dsi.horizontal_sync_active = 60;
	params->dsi.horizontal_blanking_pixel = 60;
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
}


static void lcm_suspend(void)
{
#ifndef BUILD_LK
	push_table(lcm_sleep_in_setting, sizeof(lcm_sleep_in_setting) / sizeof(struct LCM_setting_table), 1);
#endif
}

static void lcm_resume(void)
{
#ifndef BUILD_LK
	push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
    lcm_init();
#endif
}

static unsigned int lcm_compare_id(void)
{
        int array[4];
        char buffer[5];
        char id_high=0;
        char id_midd=0;
        char id_low=0;
        int id=0;

        SET_RESET_PIN(1);
        SET_RESET_PIN(0);
        MDELAY(25);       
        SET_RESET_PIN(1);
        MDELAY(50);      
       
        array[0]=0x00043902;
        array[1]=0x018198FF;
        dsi_set_cmdq(array, 3, 1);
        MDELAY(10);
        array[0]=0x00023700;
        dsi_set_cmdq(array, 1, 1);

    
        read_reg_v2(0x00, buffer,1);
        id_high = buffer[0];
        read_reg_v2(0x01, buffer,1);
        id_midd = buffer[1];
        read_reg_v2(0x02, buffer,1);
        id_low = buffer[2];

	if((0x98 == id_high)&&(0x81 == id_midd))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


// ---------------------------------------------------------------------------
//  Get LCM Driver Hooks
// ---------------------------------------------------------------------------
LCM_DRIVER hct_ili9881_dsi_vdo_hd_cpt = 
{
    .name           = "hct_ili9881_dsi_vdo_hd_cpt",
    .set_util_funcs = lcm_set_util_funcs,
    .get_params     = lcm_get_params,
    .init           = lcm_init,
    .suspend        = lcm_suspend,
    .resume         = lcm_resume,   
    .compare_id     = lcm_compare_id,    
};
