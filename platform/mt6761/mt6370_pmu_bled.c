#include <platform/mt_typedefs.h>
#include <platform/mt_i2c.h>
#include <platform/errno.h>
#include <printf.h>
#include <string.h>
#include <libfdt.h>
#include <lk_builtin_dtb.h>

#define MT6370_PMU_BLEN	0xA2
#define MT6370_MASK_PWM 0x80

static struct mt_i2c_t i2c = {
	.id = I2C_APPM,
	.addr = 0x34,
	.mode = HS_MODE,
	.speed = 3400,
	.pushpull = true,
};

struct mt6370_bled_config_t {
	u8 addr;
	u8 val;
};

static struct mt6370_bled_config_t mt6370_bled_settings[8] = {
	{.addr = 0xA1, .val = 0x89},
	{.addr = 0xA2, .val = 0x04},
	{.addr = 0xA3, .val = 0x00},
	{.addr = 0xA4, .val = 0x00},
	{.addr = 0xA5, .val = 0x00},
	{.addr = 0xA6, .val = 0x00},
	{.addr = 0xA7, .val = 0x00},
	{.addr = 0xA0, .val = 0x42}
};

// 6370 default pwm setting, used when dts not found
static struct mt6370_bled_config_t mt6370_bled_settings_default_pwm[8] = {
	{.addr = 0xA1, .val = 0xed},
	{.addr = 0xA2, .val = 0xb4},
	{.addr = 0xA3, .val = 0x30},
	{.addr = 0xA4, .val = 0x07},
	{.addr = 0xA5, .val = 0x3f},
	{.addr = 0xA6, .val = 0x00},
	{.addr = 0xA7, .val = 0x08},
	{.addr = 0xA0, .val = 0x7e}
};

/* ========================= */
/* I2C operations */
/* ========================= */
static int mt6370_i2c_write_byte(struct mt_i2c_t *i2c, u8 cmd, u8 data)
{
	unsigned int ret = I2C_OK;
	unsigned char write_buf[2] = {cmd, data};

	ret = i2c_write(i2c, write_buf, 2);

	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CW[0x%02X] = 0x%02X failed, code = %d\n",
			__func__, cmd, data, ret);
	else
		dprintf(INFO, "%s: I2CW[0x%02X] = 0x%02X\n",
			__func__, cmd, data);

	return ret;
}

static int mt6370_i2c_read_byte(struct mt_i2c_t *i2c, u8 cmd, u8 *data)
{
	int ret = I2C_OK;
	u8 ret_data = cmd;

	ret = i2c_write_read(i2c, &ret_data, 1, 1);

	if (ret != I2C_OK)
		dprintf(CRITICAL, "%s: I2CR[0x%02X] failed, code = %d\n",
			__func__, cmd, ret);
	else {
		dprintf(INFO, "%s: I2CR[0x%02X] = 0x%02X\n",
			__func__, cmd, ret_data);
		*data = ret_data;
	}

	return ret;
}

static int mt6370_i2c_update_bits(struct mt_i2c_t *i2c, u8 cmd,
	u8 mask, u8 data)
{
	int ret = 0;
	u8 reg_data = 0;

	ret = mt6370_i2c_read_byte(i2c, cmd, &reg_data);
	if (ret != I2C_OK)
		return ret;

	reg_data = reg_data & 0xFF;
	reg_data &= ~mask;
	reg_data |= (data & mask);

	return mt6370_i2c_write_byte(i2c, cmd, reg_data);
}

static int mt6370_set_pwm_mode(void)
{
	return mt6370_i2c_update_bits(&i2c, MT6370_PMU_BLEN, MT6370_MASK_PWM, 0x80);
}

static int mt6370_bled_init_setting(void)
{
	int ret = 0;
	unsigned int i;

	for (i = 0; i < sizeof(mt6370_bled_settings) / sizeof(struct mt6370_bled_config_t); i++) {
		ret = mt6370_i2c_write_byte(&i2c, mt6370_bled_settings[i].addr, mt6370_bled_settings[i].val);
		if (ret < 0)
			return ret;
	}

	return ret;
}

/**
 * If the property is not found or the value is not set,
 * return default value 0.
 */
unsigned int mt6370_bled_fdt_getprop_u32(const void *fdt, int nodeoffset,
                                 const char *name)
{
	const void *data = NULL;
	int len = 0;

	data = fdt_getprop(fdt, nodeoffset, name, &len);
	if (len > 0 && data)
		return fdt32_to_cpu(*(unsigned int *)data);
	else
		return 0;
}

static unsigned int mt6370_bled_fdt_getprop_bool(const void *fdt, int nodeoffset,
						const char *name)
{
	const void *data = NULL;
	int len = 0;

	data = fdt_getprop(fdt, nodeoffset, name, &len);
	if (data)
		return true;
	else
		return false;
}

#define MT6370_BLED_EN  (0x40)
#define MT6370_BLED_EXTEN (0x80)
#define MT6370_BLED_CHANENSHFT 2
#define MT6370_BLED_MAPLINEAR (0x02)
#define MT6370_BLED_OVPSHFT (5)
#define MT6370_BLED_OCPSHFT (1)
#define MT6370_BLED_PWMSHIFT (7)
#define MT6370_BLED_PWMDSHFT (5)
#define MT6370_BLED_PWMFSHFT (3)
#define MT6370_BLFLRAMP_SHFT (3)
#define MT6370_BLED_RAMPTSHFT (4)

static void mt6370_bled_parsing_dts(void *fdt)
{
	int offset, sub_offset;
	uint32_t val;

#if defined(USE_DTB_NO_DWS)
	offset = fdt_path_offset(get_lk_overlayed_dtb(), "/mt6370_pmu_dts");
	if (offset < 0)
		goto out;
	sub_offset = fdt_subnode_offset(get_lk_overlayed_dtb(), offset, "bled");
	if (sub_offset < 0)
		goto out;

	val = mt6370_bled_fdt_getprop_bool(get_lk_overlayed_dtb(), sub_offset, "mt,ext_en_pin");
	dprintf(INFO, "[LEDS] mt,ext_en_pin val = %d\n", val);
	if (val) {
		mt6370_bled_settings[7].val &= ~(MT6370_BLED_EN | MT6370_BLED_EXTEN);
		mt6370_bled_settings[7].val |= MT6370_BLED_EXTEN;
	}
	val = mt6370_bled_fdt_getprop_u32(get_lk_overlayed_dtb(), sub_offset, "mt,chan_en");
	dprintf(INFO, "[LEDS] mt,chan_en val = %d\n", val);
	if (val)
		mt6370_bled_settings[7].val |= (val << MT6370_BLED_CHANENSHFT);
	val = mt6370_bled_fdt_getprop_bool(get_lk_overlayed_dtb(), sub_offset, "mt,map_linear");
	dprintf(INFO, "[LEDS] mt,map_linear = %d\n", val);
	if (!val)
		mt6370_bled_settings[7].val &= ~(MT6370_BLED_MAPLINEAR);
	val = mt6370_bled_fdt_getprop_u32(get_lk_overlayed_dtb(), sub_offset, "mt,bl_ovp_level");
	dprintf(INFO, "[LEDS] mt,bl_ovp_level = %d\n", val);
	if (val)
		mt6370_bled_settings[0].val |= (val << MT6370_BLED_OVPSHFT);
	val = mt6370_bled_fdt_getprop_u32(get_lk_overlayed_dtb(), sub_offset, "mt,bl_ocp_level");
	dprintf(INFO, "[LEDS] mt,bl_ocp_level = %d\n", val);
	if (val)
		mt6370_bled_settings[0].val |= (val << MT6370_BLED_OCPSHFT);
	val = mt6370_bled_fdt_getprop_bool(get_lk_overlayed_dtb(), sub_offset, "mt,use_pwm");
	dprintf(INFO, "[LEDS] mt,use_pwm = %d\n", val);
	if (val)
		mt6370_bled_settings[1].val |= (val << MT6370_BLED_PWMSHIFT);
	val = mt6370_bled_fdt_getprop_u32(get_lk_overlayed_dtb(), sub_offset, "mt,pwm_fsample");
	dprintf(INFO, "[LEDS] mt,pwm_fsample = %d\n", val);
	if (val)
		mt6370_bled_settings[1].val |= (val << MT6370_BLED_PWMFSHFT);
	val = mt6370_bled_fdt_getprop_u32(get_lk_overlayed_dtb(), sub_offset, "mt,pwm_deglitch");
	dprintf(INFO, "[LEDS] mt,pwm_deglitch = %d\n", val);
	if (val)
		mt6370_bled_settings[1].val |= (val << MT6370_BLED_PWMDSHFT);
	val = mt6370_bled_fdt_getprop_u32(get_lk_overlayed_dtb(), sub_offset, "mt,bled_ramptime");
	dprintf(INFO, "[LEDS] mt,bled_ramptime = %d\n", val);
	if (val)
		mt6370_bled_settings[2].val |= (val << MT6370_BLED_RAMPTSHFT);
	val = mt6370_bled_fdt_getprop_u32(get_lk_overlayed_dtb(), sub_offset, "mt,bled_flash_ramp");
	dprintf(INFO, "[LEDS] mt,bled_flash_ramp = %d\n", val);
	if (val)
		mt6370_bled_settings[6].val |= (val << MT6370_BLFLRAMP_SHFT);
	val = mt6370_bled_fdt_getprop_u32(get_lk_overlayed_dtb(), sub_offset, "mt,max_bled_brightness");
	dprintf(INFO, "[LEDS] mt,max_bled_brightness = %d\n", val);
	if (val) {
		val = ((u64)val * 255) >> 8;
		mt6370_bled_settings[3].val |= (val & 0x7);
		mt6370_bled_settings[4].val |= ((val >> 3) & 0xff);
	}
	return;
out:
#endif
	memcpy(mt6370_bled_settings, mt6370_bled_settings_default_pwm, sizeof(mt6370_bled_settings));
	dprintf(CRITICAL, "[LEDS] cannot read settings from dts, using default setting\n");
}

static int mt6370_init_bled(void)
{
	unsigned int i;
	int ret = 0;

	dprintf(INFO, "[LEDS]LK: %s\n", __func__);

	mt6370_bled_parsing_dts(get_lk_overlayed_dtb());
	for (i = 0; i < sizeof(mt6370_bled_settings) / sizeof(struct mt6370_bled_config_t); i++) {
		ret = mt6370_i2c_write_byte(&i2c, mt6370_bled_settings[i].addr, mt6370_bled_settings[i].val);
		if (ret < 0)
			return ret;
	}
	return ret;
}

int mt6370_bled_probe(void)
{
	int ret = 0;

	ret = mt6370_init_bled();
	if (ret < 0)
		dprintf(CRITICAL, "%s fail, ret = %d\n", __func__, ret);

	return ret;
}

