#include <platform/mt_typedefs.h>
#include <platform/mt_i2c.h>
#include <platform/errno.h>
#include <printf.h>
#include <string.h>

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

int mt6370_bled_probe(void)
{
	int ret = 0;

	ret = mt6370_bled_init_setting();
	if (ret < 0)
		dprintf(CRITICAL, "%s fail, ret = %d\n", __func__, ret);

	return ret;
}

