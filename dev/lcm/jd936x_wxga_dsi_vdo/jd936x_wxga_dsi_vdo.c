/*
* Copyright (c) 2019 MediaTek Inc.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files
* (the "Software"), to deal in the Software without restriction,
* including without limitation the rights to use, copy, modify, merge,
* publish, distribute, sublicense, and/or sell copies of the Software,
* and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifdef BUILD_LK
#include <string.h>
#include <platform/mt_gpio.h>
#include <platform/mt_pmic.h>
#include <platform/sync_write.h>
#else
#include <linux/string.h>
#include <linux/wait.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/of_gpio.h>
#include <asm-generic/gpio.h>

#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>

#ifdef CONFIG_OF
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#endif

#endif
#include "lcm_drv.h"

#ifdef GPIO_LCM_RST
#define GPIO_LCD_RST          GPIO_LCM_RST
#else
#define GPIO_LCD_RST          (0xFFFFFFFF)
#endif

#ifdef GPIO_LCD_ENP
#define GPIO_LCD_PWR_ENP      GPIO_LCD_ENP
#else
#define GPIO_LCD_PWR_ENP      (0xFFFFFFFF)
#endif

#ifdef GPIO_LCD_ENN
#define GPIO_LCD_PWR_ENN      GPIO_LCD_ENN
#else
#define GPIO_LCD_PWR_ENN      (0xFFFFFFFF)
#endif


/* --------------------------------------------------------------- */
/*  Local Constants */
/* --------------------------------------------------------------- */
#define FRAME_WIDTH		(800)
#define FRAME_HEIGHT		(1280)

#define REGFLAG_DELAY		0xFE
#define REGFLAG_END_OF_TABLE	0x00

/* --------------------------------------------------------------- */
/*  Local Variables */
/* --------------------------------------------------------------- */
extern void mdelay(unsigned long msec);

static LCM_UTIL_FUNCS lcm_util = {
	.set_reset_pin = NULL,
	.udelay = NULL,
	.mdelay = NULL,
};

#define SET_RESET_PIN(v)		(lcm_util.set_reset_pin((v)))

#define UDELAY(n)				(lcm_util.udelay(n))
#define MDELAY(n)				(lcm_util.mdelay(n))

/* --------------------------------------------------------------- */
/* Local Functions */
/* --------------------------------------------------------------- */
#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) \
		 (lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update))
#define dsi_set_cmdq(pdata, queue_size, force_update) \
		 (lcm_util.dsi_set_cmdq(pdata, queue_size, force_update))
#define wrtie_cmd(cmd) \
		 (lcm_util.dsi_write_cmd(cmd))
#define write_regs(addr, pdata, byte_nums) \
		 (lcm_util.dsi_write_regs(addr, pdata, byte_nums))
#define read_reg \
		 (lcm_util.dsi_read_reg())
#define read_reg_v2(cmd, buffer, buffer_size) \
		 (lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size))

static void lcm_set_gpio_output(unsigned int GPIO, unsigned int output)
{
	if (GPIO == 0xFFFFFFFF) {
		printf("[LK/LCM] GPIO not defined\n");
		return;
	}

	mt_set_gpio_mode(GPIO, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO, (output > 0) ? GPIO_OUT_ONE : GPIO_OUT_ZERO);
}

static void init_karnak_fiti_kd_lcm(void)
{
	unsigned int data_array[64];

	data_array[0] = 0x00E01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x93E11500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x65E21500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xF8E31500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x03801500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x01E01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00001500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x6E011500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00031500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x82041500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00171500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xD7181500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x01191500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x001A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xD71B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x011C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x791F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2D201500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2D211500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0F221500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x09371500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x04381500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00391500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x013A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x703C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xFF3D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xFF3E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x7F3F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x06401500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xA0411500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x1E431500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0D441500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x28451500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x044B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0F551500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x01561500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xA8571500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0A581500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2A591500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x375A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x195B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x785D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x5B5E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x4A5F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x3D601500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x39611500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x29621500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2E631500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x17641500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2F651500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2D661500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2C671500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x45681500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x32691500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x406A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x396B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2C6C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x226D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0E6E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x026F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x78701500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x5B711500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x4A721500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x3D731500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x39741500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x29751500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2E761500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x17771500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2F781500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2D791500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2C7A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x457B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x327C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x407D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x397E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2C7F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x22801500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0E811500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x02821500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x02E01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x40001500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x44011500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x46021500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x48031500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x4A041500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x4C051500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x4E061500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x57071500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x77081500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55091500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x500A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x550B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x550C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x550D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x550E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x550F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55101500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55111500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55121500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x52131500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55141500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55151500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x41161500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x45171500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x47181500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x49191500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x4B1A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x4D1B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x4F1C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x571D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x771E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x551F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x51201500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55211500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55221500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55231500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55241500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55251500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55261500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55271500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x55281500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x53291500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x552A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x552B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x112C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0F2D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0D2E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0B2F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x09301500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x07311500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x05321500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x17331500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x17341500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15351500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x01361500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15371500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15381500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15391500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x153A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x153B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x153C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x153D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x153E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x133F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15401500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15411500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x10421500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0E431500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0C441500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0A451500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x08461500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x06471500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x04481500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x17491500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x174A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x154B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x004C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x154D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x154E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x154F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15501500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15511500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15521500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15531500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15541500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x12551500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15561500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x15571500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x40581500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00591500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x005A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x105B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x065C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x405D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x005E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x005F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x40601500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x03611500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x04621500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x60631500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x60641500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x75651500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0C661500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xB4671500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x08681500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x60691500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x606A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x106B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x006C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x046D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x006E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x886F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00701500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00711500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x06721500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x7B731500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00741500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xBC751500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00761500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x0D771500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2C781500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00791500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x007A1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x007B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x007C1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x037D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x7B7E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x04E01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x003F1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0xFF411500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x032D1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x10091500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x480E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x48271500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2B2B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x442E1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x05E01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x72121500;
	dsi_set_cmdq(data_array, 1, 1);

	/* Page3 */
	data_array[0] = 0x03E01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x059B1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x20AF1500;
	dsi_set_cmdq(data_array, 1, 1);

	/*Page0 enable CABC*/
	data_array[0] = 0x00E01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x2C531500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00E01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x02E61500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x02E71500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00111500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(120);
	data_array[0] = 0x00291500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(5);
	data_array[0] = 0x00351500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x04EC1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x03E01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x81A91500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x4FAC1500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x33A01500;
	dsi_set_cmdq(data_array, 1, 1);
	data_array[0] = 0x00E01500;
	dsi_set_cmdq(data_array, 1, 1);
}


/* --------------------------------------------------------------- */
/*  LCM Driver Implementations */
/* --------------------------------------------------------------- */
static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_fiti_kd_params(LCM_PARAMS *params)
{
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type   = LCM_TYPE_DSI;

	params->width  = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

	params->dsi.mode   = SYNC_EVENT_VDO_MODE;

	params->dsi.LANE_NUM				= LCM_FOUR_LANE;
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

	params->dsi.packet_size = 256;

	params->dsi.intermediat_buffer_num = 0;

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active		= 4;
	params->dsi.vertical_backporch			= 10;
	params->dsi.vertical_frontporch			= 30;
	params->dsi.vertical_active_line		= FRAME_HEIGHT;

	params->dsi.horizontal_sync_active		= 20;
	params->dsi.horizontal_backporch		= 43;
	params->dsi.horizontal_frontporch		= 43;
	params->dsi.horizontal_active_pixel		= FRAME_WIDTH;

	params->dsi.PLL_CLOCK = 234;
	params->dsi.clk_lp_per_line_enable = 1;

	params->dsi.ssc_disable = 1;
	params->dsi.cont_clock= 0;
	params->dsi.DA_HS_EXIT = 1;
	params->dsi.CLK_ZERO = 16;
	params->dsi.HS_ZERO = 9;
	params->dsi.HS_TRAIL = 5;
	params->dsi.CLK_TRAIL = 5;
	params->dsi.CLK_HS_POST = 8;
	params->dsi.CLK_HS_EXIT = 6;

	params->dsi.TA_GO = 8;
	params->dsi.TA_GET = 10;

	params->physical_width = 108;
	params->physical_height = 172;
}

static void lcm_init_power(void)
{
	printf("[LK/LCM] %s enter\n", __func__);

	pmic_vsim1_enable(true, 1800);
	lcm_set_gpio_output(GPIO_LCD_PWR_ENP, GPIO_OUT_ONE);
	MDELAY(1);
	lcm_set_gpio_output(GPIO_LCD_PWR_ENN, GPIO_OUT_ONE);
	MDELAY(10);

	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(10);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);
	MDELAY(2);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(5);
}

static void lcm_init(void)
{
	printf("[LK/LCM]xxxxxxx %s enter\n", __func__);

	init_karnak_fiti_kd_lcm(); /*FITI KD panel*/
}

LCM_DRIVER jd9366_wxga_dsi_vdo_fiti_kd_lcm_drv = {
	.name			= "jd9366_wxga_dsi_vdo_fiti_kd",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_fiti_kd_params,
	.init_power		= lcm_init_power,
	.init           = lcm_init,
};
