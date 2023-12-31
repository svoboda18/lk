/*****************************************************************************

*****************************************************************************/
#include "lcm_drv.h"

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH 720
#define FRAME_HEIGHT 1280

#define LCM_ID 0x0F

#define REGFLAG_DELAY 0XFE
#define REGFLAG_END_OF_TABLE 0x100 // END OF REGISTERS MARKER

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

#define SET_RESET_PIN(v) (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))

// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------
#define dsi_set_cmdq_V3(para_tbl,size,force_update)         lcm_util.dsi_set_cmdq_V3(para_tbl,size,force_update)
#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)    lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)       lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)                                      lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)                  lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)                                       lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)               lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};

static struct LCM_setting_table lcm_initialization_setting[] = {
    {0xB9, 3, {0xFF, 0x83, 0x94}},
    {0xBA, 6, {0x62, 0x03, 0x68, 0x6B, 0xB2, 0xC0}},
    {0xB1, 10, {0x50, 0x12, 0x72, 0x09, 0x33, 0x54, 0xB1, 0x31, 0x6B, 0x2F}},
    {0xB2, 6, {0x00, 0x80, 0x64, 0x0E, 0x0D, 0x2F}},
    {0xB4, 21, {0x73, 0x74, 0x73, 0x74, 0x73, 0x74, 0x01, 0x0C, 0x86, 0x75, 0x00, 0x3F, 0x73, 0x74, 0x73, 0x74, 0x73, 0x74, 0x01, 0x0C, 0x86}},
    {0xB6, 2, {0x6B, 0x6B}},
    {0xD3, 33, {0x00, 0x00, 0x07, 0x07, 0x40, 0x07, 0x10, 0x00, 0x08, 0x10, 0x08, 0x00, 0x08, 0x54, 0x15, 0x0E, 0x05, 0x0E, 0x02, 0x15, 0x06, 0x05, 0x06, 0x47, 0x44, 0x0A, 0x0A, 0x4B, 0x10, 0x07, 0x07, 0x0E, 0x40}},
    {0xD5, 44, {0x1A, 0x1A, 0x1B, 0x1B, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x24, 0x25, 0x18, 0x18, 0x26, 0x27, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x20, 0x21, 0x18, 0x18, 0x18, 0x18}},
    {0xD6, 44, {0x1A, 0x1A, 0x1B, 0x1B, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x21, 0x20, 0x18, 0x18, 0x27, 0x26, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x25, 0x24, 0x18, 0x18, 0x18, 0x18}},
    {0xE0, 58, {0x00, 0x0D, 0x1B, 0x22, 0x26, 0x2A, 0x2F, 0x2D, 0x5D, 0x6D, 0x7E, 0x7C, 0x87, 0x96, 0x99, 0x9D, 0xA7, 0xAE, 0xA5, 0xB5, 0xBA, 0x57, 0x55, 0x58, 0x5C, 0x5E, 0x64, 0x6B, 0x7F, 0x00, 0x0D, 0x1B, 0x22, 0x26, 0x2A, 0x2F, 0x2D, 0x5D, 0x6D, 0x7E, 0x7C, 0x87, 0x96, 0x99, 0x9D, 0xA7, 0xAE, 0xA5, 0xB5, 0xBA, 0x57, 0x55, 0x58, 0x5C, 0x5E, 0x64, 0x6B, 0x7F}},
    {0xC0, 2, {0x1F, 0x73}},
    {0xCC, 1, {0x0B}},
    {0xD4, 1, {0x02}},
    {0xBD, 1, {0x01}},
    {0xB1, 1, {0x60}},
    {0xBD, 1, {0x00}},
    {0xBD, 1, {0x02}},
    {0xD8, 12, {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}},
    {0xBD, 1, {0x00}},
    {0xBF, 7, {0x40, 0x81, 0x50, 0x00, 0x1A, 0xFC, 0x01}},
    {0x11, 1, {0x00}},
    {REGFLAG_DELAY, 120, {}},
    {0x29, 1, {0x00}},
    {REGFLAG_DELAY, 10, {}},
    {REGFLAG_END_OF_TABLE, 0, {}}
};

static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = {
    // Display off sequence
    {0x28, 1, {0x00}},
    {REGFLAG_DELAY, 10, {}},

    // Sleep Mode On
    {0x10, 1, {0x00}},
    {REGFLAG_DELAY, 150, {}},

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
    params->type   = LCM_TYPE_DSI;
    params->width  = FRAME_WIDTH;
    params->height = FRAME_HEIGHT;

    params->dbi.te_mode = LCM_DBI_TE_MODE_DISABLED;
    params->dsi.mode = SYNC_EVENT_VDO_MODE;

    params->dsi.LANE_NUM = LCM_THREE_LANE;
    params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
    params->dsi.data_format.trans_seq = LCM_DSI_TRANS_SEQ_MSB_FIRST;
    params->dsi.data_format.padding = LCM_DSI_PADDING_ON_LSB;
    params->dsi.data_format.format = LCM_DSI_FORMAT_RGB888;
    params->dsi.packet_size = 256;
    params->dsi.intermediat_buffer_num = 2;
    params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;
    params->dsi.vertical_sync_active = 4;
    params->dsi.vertical_backporch = 12;
    params->dsi.vertical_frontporch = 15;
    params->dsi.vertical_active_line = FRAME_HEIGHT;
    params->dsi.horizontal_sync_active = 10;
    params->dsi.horizontal_backporch = 20;
    params->dsi.horizontal_frontporch = 40;
    params->dsi.horizontal_active_pixel = FRAME_WIDTH;
    params->dsi.cont_clock = 0;
    params->dsi.PLL_CLOCK = 230;
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
    SET_RESET_PIN(1);
    MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(30);
    SET_RESET_PIN(1);
    MDELAY(120);

    push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_resume(void)
{
    lcm_init();
}

static unsigned int lcm_compare_id(void)
{
    unsigned char buffer[2];
    unsigned int array[3];

    SET_RESET_PIN(1);
    MDELAY(1);
    SET_RESET_PIN(0);
    MDELAY(1);
    SET_RESET_PIN(1);
    MDELAY(120);

    array[0] = 0x43902;
    array[1] = 0x9483FFB9;
    dsi_set_cmdq(array, 2, 1);
    MDELAY(10);

    array[0] = 0x73902;
    array[1] = 0x680362BA;
    array[2] = 0xC0B26B;
    dsi_set_cmdq(array, 3, 1);
    MDELAY(10);
    array[0] = 0x23700;
    dsi_set_cmdq(array, 1, 1);
    MDELAY(10);

    read_reg_v2(0xdc, buffer, 2);

    return LCM_ID == buffer[0] ? 1 : 0;
}

// ---------------------------------------------------------------------------
//  Get LCM Driver Hooks
// ---------------------------------------------------------------------------

LCM_DRIVER hct_hx8394f_dsi_vdo_hd_cmi =
{
    .name           = "hct_hx8394f_dsi_vdo_hd_cmi",
    .set_util_funcs = lcm_set_util_funcs,
    .get_params     = lcm_get_params,
    .init           = lcm_init,
    .suspend        = lcm_suspend,
    .resume         = lcm_resume,
    .compare_id     = lcm_compare_id,
};

