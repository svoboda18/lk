/******************************************************************************
 * mt_leds.c
 *
 * Copyright 2010 MediaTek Co.,Ltd.
 *
 * DESCRIPTION:
 *
 ******************************************************************************/
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>

#include <platform/mt_pwm.h>
#include <platform/mt_gpio.h>
#include <platform/mt_leds.h>

#include <platform/mt_pmic.h>
#include <platform/upmu_common.h>
#include <platform/upmu_hw.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/mt_gpt.h>

extern void mt_pwm_disable(U32 pwm_no, BOOL pmic_pad);
extern int strcmp(const char *cs, const char *ct);

/****************************************************************************
 * DEBUG MACROS
 ***************************************************************************/
int debug_enable = 1;
#define LEDS_DEBUG(format, args...) do{ \
		if(debug_enable) \
		{\
			dprintf(CRITICAL,format,##args);\
		}\
	}while(0)
#define LEDS_INFO LEDS_DEBUG
/****************************************************************************
 * structures
 ***************************************************************************/
static int g_lastlevel[MT65XX_LED_TYPE_TOTAL] = {-1, -1, -1, -1, -1, -1, -1};
int backlight_PWM_div = CLK_DIV1;

// Use Old Mode of PWM to suppoort 256 backlight level
#define BACKLIGHT_LEVEL_PWM_256_SUPPORT 256
extern unsigned int Cust_GetBacklightLevelSupport_byPWM(void);

/****************************************************************************
 * function prototypes
 ***************************************************************************/

/* internal functions */
static int brightness_set_pwm(int pwm_num, enum led_brightness level,struct PWM_config *config_data);
static int led_set_pwm(int pwm_num, enum led_brightness level);
static int brightness_set_pmic(enum mt65xx_led_pmic pmic_type, enum led_brightness level);
//static int brightness_set_gpio(int gpio_num, enum led_brightness level);
static int mt65xx_led_set_cust(struct cust_mt65xx_led *cust, int level);
/****************************************************************************
 * global variables
 ***************************************************************************/
static unsigned int limit = 255;

/****************************************************************************
 * global variables
 ***************************************************************************/

/****************************************************************************
 * internal functions
 ***************************************************************************/
static int brightness_mapto64(int level)
{
        if (level < 30)
                return (level >> 1) + 7;
        else if (level <= 120)
                return (level >> 2) + 14;
        else if (level <= 160)
                return level / 5 + 20;
        else
                return (level >> 3) + 33;
}
unsigned int brightness_mapping(unsigned int level)
{
	unsigned int mapped_level;

	mapped_level = level;

	return mapped_level;
}

static int brightness_set_pwm(int pwm_num, enum led_brightness level,struct PWM_config *config_data)
{
	struct pwm_spec_config pwm_setting;
	unsigned int BacklightLevelSupport = Cust_GetBacklightLevelSupport_byPWM();
	pwm_setting.pwm_no = pwm_num;
	if (BacklightLevelSupport == BACKLIGHT_LEVEL_PWM_256_SUPPORT)
		pwm_setting.mode = PWM_MODE_OLD;
	else
		pwm_setting.mode = PWM_MODE_FIFO; // New mode fifo and periodical mode

	pwm_setting.pmic_pad = config_data->pmic_pad;
	if(config_data->div)
	{
		pwm_setting.clk_div = config_data->div;
		backlight_PWM_div = config_data->div;
	}
	else
		pwm_setting.clk_div = CLK_DIV1;

	if(BacklightLevelSupport== BACKLIGHT_LEVEL_PWM_256_SUPPORT)
	{
		if(config_data->clock_source)
		{
			pwm_setting.clk_src = PWM_CLK_OLD_MODE_BLOCK;
		}
		else
		{
			pwm_setting.clk_src = PWM_CLK_OLD_MODE_32K; // actually. it's block/1625 = 26M/1625 = 16KHz @ MT6571
		}

		pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.IDLE_VALUE = 0;
		pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.GUARD_VALUE = 0;
		pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.GDURATION = 0;
		pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.WAVE_NUM = 0;
		pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.DATA_WIDTH = 255; // 256 level
		pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.THRESH = level;

		LEDS_DEBUG("[LEDS][%d] LK: backlight_set_pwm:duty is %d/%d\n", BacklightLevelSupport, level, pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.DATA_WIDTH);
		LEDS_DEBUG("[LEDS][%d] LK: backlight_set_pwm:clk_src/div is %d%d\n", BacklightLevelSupport, pwm_setting.clk_src, pwm_setting.clk_div);
		if(level >0 && level < 256)
		{
			pwm_set_spec_config(&pwm_setting);
			LEDS_DEBUG("[LEDS][%d] LK: backlight_set_pwm: old mode: thres/data_width is %d/%d\n", BacklightLevelSupport, pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.THRESH, pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.DATA_WIDTH);
		}
		else
		{
			LEDS_DEBUG("[LEDS][%d] LK: Error level in backlight\n", BacklightLevelSupport);
			mt_pwm_disable(pwm_setting.pwm_no, config_data->pmic_pad);
		}
		return 0;

	}
	else
	{
		if(config_data->clock_source)
		{
			pwm_setting.clk_src = PWM_CLK_NEW_MODE_BLOCK;
		}
		else
		{
			pwm_setting.clk_src = PWM_CLK_NEW_MODE_BLOCK_DIV_BY_1625;
		}

		if(config_data->High_duration && config_data->low_duration)
		{
			pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.HDURATION = config_data->High_duration;
			pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.LDURATION = pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.HDURATION;
		}
		else
		{
			pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.HDURATION = 4;
			pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.LDURATION = 4;
		}

		pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.IDLE_VALUE = 0;
		pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.GUARD_VALUE = 0;
		pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.STOP_BITPOS_VALUE = 31;
		pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.GDURATION = (pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.HDURATION + 1) * 32 - 1;
		pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.WAVE_NUM = 0;

		LEDS_DEBUG("[LEDS] LK: backlight_set_pwm:duty is %d\n", level);
		LEDS_DEBUG("[LEDS] LK: backlight_set_pwm:clk_src/div/high/low is %d%d%d%d\n", pwm_setting.clk_src, pwm_setting.clk_div, pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.HDURATION, pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.LDURATION);

		if(level > 0 && level <= 32)
		{
			pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.GUARD_VALUE = 0;
			pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.SEND_DATA0 = (1 << level) - 1;
			pwm_set_spec_config(&pwm_setting);
		}else if(level > 32 && level <= 64)
		{
			pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.GUARD_VALUE = 1;
			level -= 32;
			pwm_setting.pwm_mode.PWM_MODE_FIFO_REGS.SEND_DATA0 = (1 << level) - 1 ;
			pwm_set_spec_config(&pwm_setting);
		}else
		{
			LEDS_DEBUG("[LEDS] LK: Error level in backlight\n");
			mt_pwm_disable(pwm_setting.pwm_no, config_data->pmic_pad);
		}

		return 0;
	}
}

static int led_set_pwm(int pwm_num, enum led_brightness level)
{
	struct pwm_spec_config pwm_setting;
	pwm_setting.pwm_no = pwm_num;
	pwm_setting.clk_div = CLK_DIV1;

	pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.DATA_WIDTH = 50;

	// We won't choose 32K to be the clock src of old mode because of system performance.
	// The setting here will be clock src = 26MHz, CLKSEL = 26M/1625 (i.e. 16K)
	pwm_setting.clk_src = PWM_CLK_OLD_MODE_32K;

	if(level)
	{
		pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.THRESH = 15;
	}else
	{
		pwm_setting.pwm_mode.PWM_MODE_OLD_REGS.THRESH = 0;
	}
	LEDS_INFO("[LEDS]LK: brightness_set_pwm: level=%d, clk=%d \n\r", level, pwm_setting.clk_src);
	pwm_set_spec_config(&pwm_setting);

	return 0;
}

#define PMIC_BACKLIGHT_LEVEL    80
static int brightness_set_pmic(enum mt65xx_led_pmic pmic_type, enum led_brightness level)
{
	int tmp_level = level;
	//static bool backlight_init_flag[4] = {false, false, false, false};
	static bool backlight_init_flag = false;
	//static bool led_init_flag[4] = {false, false, false, false};
	//static bool first_time = true;

	static unsigned char duty_mapping[PMIC_BACKLIGHT_LEVEL] = {
                0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,
                12,     13,     14,     15,     16,     17,     18,     19,     20,     21,     22,     23,
                24,     25,     26,     27,     28,     29,     30,     31,     16,     17,     18,     19,
                20,     21,     22,     23,     24,     25,     26,     27,     28,     29,     30,     31,
                21,     22,     23,     24,     25,     26,     27,     28,     29,     30,     31,     24,
                25,     26,     27,     28,     29,     30,     31,     25,     26,     27,     28,     29,
                30,     31,     26,     27,     28,     29,     30,     31,
    	};
    	static unsigned char current_mapping[PMIC_BACKLIGHT_LEVEL] = {
                0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
                0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,
                0,      0,      0,      0,      0,      0,      0,      0,      1,      1,      1,      1,
                1,      1,      1,      1,      1,      1,      1,      1,      1,      1,      1,      1,
                2,      2,      2,      2,      2,      2,      2,      2,      2,      2,      2,      3,
                3,      3,      3,      3,      3,      3,      3,      4,      4,      4,      4,      4,
                4,      4,      5,      5,      5,      5,      5,      5,
    	};

	LEDS_INFO("[LEDS]LK: PMIC Type: %d, Level: %d\n", pmic_type, level);

	if (pmic_type == MT65XX_LED_PMIC_LCD_ISINK)
	{
		if(backlight_init_flag == false)
		{
			pmic_set_register_value(PMIC_RG_DRV_2M_CK_PDN,0x0); // Disable power down
			// For backlight: Current: 24mA, PWM frequency: 20K, Duty: 20~100, Soft start: off, Phase shift: on
			// ISINK0
			pmic_set_register_value(PMIC_RG_ISINK0_CK_PDN,0x0); // Disable power down
			pmic_set_register_value(PMIC_RG_ISINK0_CK_SEL,0x1); // Freq = 1Mhz for Backlight
			pmic_set_register_value(PMIC_ISINK_CH0_MODE,ISINK_PWM_MODE);
			pmic_set_register_value(PMIC_ISINK_CH0_STEP,ISINK_5); // 24mA
			pmic_set_register_value(PMIC_ISINK_SFSTR0_EN,0x0); // Disable soft start
			pmic_set_register_value(PMIC_RG_ISINK0_DOUBLE_EN,0x1); // Enable double current
			pmic_set_register_value(PMIC_ISINK_PHASE_DLY_TC,0x0); // TC = 0.5us
			pmic_set_register_value(PMIC_ISINK_PHASE0_DLY_EN,0x1); // Enable phase delay
			pmic_set_register_value(PMIC_ISINK_CHOP0_EN,0x1); // Enable CHOP clk
			// ISINK1
			pmic_set_register_value(PMIC_RG_ISINK1_CK_PDN,0x0); // Disable power down
			pmic_set_register_value(PMIC_RG_ISINK1_CK_SEL,0x1); // Freq = 1Mhz for Backlight
			pmic_set_register_value(PMIC_ISINK_CH1_MODE,ISINK_PWM_MODE);
			pmic_set_register_value(PMIC_ISINK_CH1_STEP,ISINK_3); // 24mA
			pmic_set_register_value(PMIC_ISINK_SFSTR1_EN,0x0); // Disable soft start
			pmic_set_register_value(PMIC_RG_ISINK1_DOUBLE_EN,0x1); // Enable double current
			pmic_set_register_value(PMIC_ISINK_PHASE1_DLY_EN,0x1); // Enable phase delay
			pmic_set_register_value(PMIC_ISINK_CHOP1_EN,0x1); // Enable CHOP clk
			// ISINK2
			pmic_set_register_value(PMIC_RG_ISINK2_CK_PDN,0x0); // Disable power down
			pmic_set_register_value(PMIC_RG_ISINK2_CK_SEL,0x1); // Freq = 1Mhz for Backlight
			pmic_set_register_value(PMIC_ISINK_CH2_MODE,ISINK_PWM_MODE);
			pmic_set_register_value(PMIC_ISINK_CH2_STEP,ISINK_3); // 24mA
			pmic_set_register_value(PMIC_ISINK_SFSTR2_EN,0x0); // Disable soft start
			pmic_set_register_value(PMIC_RG_ISINK2_DOUBLE_EN,0x1); // Enable double current
			pmic_set_register_value(PMIC_ISINK_PHASE2_DLY_EN,0x1); // Enable phase delay
			pmic_set_register_value(PMIC_ISINK_CHOP2_EN,0x1); // Enable CHOP clk
			// ISINK3
			pmic_set_register_value(PMIC_RG_ISINK3_CK_PDN,0x0); // Disable power down
			pmic_set_register_value(PMIC_RG_ISINK3_CK_SEL,0x1); // Freq = 1Mhz for Backlight
			pmic_set_register_value(PMIC_ISINK_CH3_MODE,ISINK_PWM_MODE);
			pmic_set_register_value(PMIC_ISINK_CH3_STEP,ISINK_3); // 24mA
			pmic_set_register_value(PMIC_ISINK_SFSTR3_EN,0x0); // Disable soft start
			pmic_set_register_value(PMIC_RG_ISINK3_DOUBLE_EN,0x1); // Enable double current
			pmic_set_register_value(PMIC_ISINK_PHASE3_DLY_EN,0x1); // Enable phase delay
			pmic_set_register_value(PMIC_ISINK_CHOP3_EN,0x1); // Enable CHOP clk
			backlight_init_flag = true;
		}

		if (level)
		{
			level = brightness_mapping(tmp_level);
			if(level == ERROR_BL_LEVEL)
				level = limit;
			if(level == limit)
			{
				level = PMIC_BACKLIGHT_LEVEL;
			}
			else
			{
				level =((level * PMIC_BACKLIGHT_LEVEL) / limit) + 1;
			}
			LEDS_INFO("[LEDS]LK: Level Mapping = %d \n", level);
			LEDS_INFO("[LEDS]LK: ISINK DIM Duty = %d \n", duty_mapping[level-1]);
			LEDS_INFO("[LEDS]LK: ISINK Current = %d \n", current_mapping[level-1]);
			pmic_set_register_value(PMIC_ISINK_DIM0_DUTY,duty_mapping[level-1]);
			pmic_set_register_value(PMIC_ISINK_DIM1_DUTY,duty_mapping[level-1]);
			pmic_set_register_value(PMIC_ISINK_DIM2_DUTY,duty_mapping[level-1]);
			pmic_set_register_value(PMIC_ISINK_DIM3_DUTY,duty_mapping[level-1]);
			pmic_set_register_value(PMIC_ISINK_CH0_STEP,current_mapping[level-1]);
			pmic_set_register_value(PMIC_ISINK_CH1_STEP,current_mapping[level-1]);
			pmic_set_register_value(PMIC_ISINK_CH2_STEP,current_mapping[level-1]);
			pmic_set_register_value(PMIC_ISINK_CH3_STEP,current_mapping[level-1]);
			pmic_set_register_value(PMIC_ISINK_DIM0_FSEL,ISINK_2M_20KHZ); // 20Khz
			pmic_set_register_value(PMIC_ISINK_DIM1_FSEL,ISINK_2M_20KHZ); // 20Khz
			pmic_set_register_value(PMIC_ISINK_DIM2_FSEL,ISINK_2M_20KHZ); // 20Khz
			pmic_set_register_value(PMIC_ISINK_DIM3_FSEL,ISINK_2M_20KHZ); // 20Khz
			pmic_set_register_value(PMIC_ISINK_CH0_EN,0x1); // Turn on ISINK Channel 0
			pmic_set_register_value(PMIC_ISINK_CH1_EN,0x1); // Turn on ISINK Channel 1
			pmic_set_register_value(PMIC_ISINK_CH2_EN,0x1); // Turn on ISINK Channel 2
			pmic_set_register_value(PMIC_ISINK_CH3_EN,0x1); // Turn on ISINK Channel 3
		}
		else
		{
			pmic_set_register_value(PMIC_ISINK_CH0_EN,0x0); // Turn off ISINK Channel 0
			pmic_set_register_value(PMIC_ISINK_CH1_EN,0x0); // Turn off ISINK Channel 1
			pmic_set_register_value(PMIC_ISINK_CH2_EN,0x0); // Turn off ISINK Channel 2
			pmic_set_register_value(PMIC_ISINK_CH3_EN,0x0); // Turn off ISINK Channel 3
		}

		return 0;
	}
	else if(pmic_type == MT65XX_LED_PMIC_NLED_ISINK0)
	{
		pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down
		pmic_set_register_value(PMIC_RG_ISINK0_CK_PDN,0);
		pmic_set_register_value(PMIC_RG_ISINK0_CK_SEL,0);
		pmic_set_register_value(PMIC_ISINK_CH0_MODE,ISINK_PWM_MODE);
		pmic_set_register_value(PMIC_ISINK_CH0_STEP,ISINK_3);//16mA
		pmic_set_register_value(PMIC_ISINK_DIM0_DUTY,15);
		pmic_set_register_value(PMIC_ISINK_DIM0_FSEL,ISINK_1KHZ);//1KHz
		if (level)
		{
			pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down
			pmic_set_register_value(PMIC_ISINK_CH0_EN,0x1); // Turn on ISINK Channel 0
		}
		else
		{
			pmic_set_register_value(PMIC_ISINK_CH0_EN,0x0); // Turn off ISINK Channel 0
		}
		return 0;
	}
	else if(pmic_type == MT65XX_LED_PMIC_NLED_ISINK1)
	{
		pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down
		pmic_set_register_value(PMIC_RG_ISINK1_CK_PDN,0);
		pmic_set_register_value(PMIC_RG_ISINK1_CK_SEL,0);
		pmic_set_register_value(PMIC_ISINK_CH1_MODE,ISINK_PWM_MODE);
		pmic_set_register_value(PMIC_ISINK_CH1_STEP,ISINK_3);//16mA
		pmic_set_register_value(PMIC_ISINK_DIM1_DUTY,15);
		pmic_set_register_value(PMIC_ISINK_DIM1_FSEL,ISINK_1KHZ);//1KHz
		if (level)
		{
			pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down
			pmic_set_register_value(PMIC_ISINK_CH1_EN,0x1); // Turn on ISINK Channel 0
		}
		else
		{
			pmic_set_register_value(PMIC_ISINK_CH1_EN,0x0); // Turn off ISINK Channel 0
		}
		return 0;
	}
	else if(pmic_type == MT65XX_LED_PMIC_NLED_ISINK2)
	{
		pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down
		pmic_set_register_value(PMIC_RG_ISINK2_CK_PDN,0);
		pmic_set_register_value(PMIC_RG_ISINK2_CK_SEL,0);
		pmic_set_register_value(PMIC_ISINK_CH2_MODE,ISINK_PWM_MODE);
		pmic_set_register_value(PMIC_ISINK_CH2_STEP,ISINK_3);//16mA
		pmic_set_register_value(PMIC_ISINK_DIM2_DUTY,15);
		pmic_set_register_value(PMIC_ISINK_DIM2_FSEL,ISINK_1KHZ);//1KHz
		if (level)
		{
			pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down
			pmic_set_register_value(PMIC_ISINK_CH2_EN,0x1); // Turn on ISINK Channel 0
		}
		else
		{
			pmic_set_register_value(PMIC_ISINK_CH2_EN,0x0); // Turn off ISINK Channel 0
		}
		return 0;
	}
	else if(pmic_type == MT65XX_LED_PMIC_NLED_ISINK3)
	{
		pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down
		pmic_set_register_value(PMIC_RG_ISINK3_CK_PDN,0);
		pmic_set_register_value(PMIC_RG_ISINK3_CK_SEL,0);
		pmic_set_register_value(PMIC_ISINK_CH3_MODE,ISINK_PWM_MODE);
		pmic_set_register_value(PMIC_ISINK_CH3_STEP,ISINK_3);//16mA
		pmic_set_register_value(PMIC_ISINK_DIM3_DUTY,15);
		pmic_set_register_value(PMIC_ISINK_DIM3_FSEL,ISINK_1KHZ);//1KHz
		if (level)
		{
			pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down
			pmic_set_register_value(PMIC_ISINK_CH3_EN,0x1); // Turn on ISINK Channel 0
		}
		else
		{
			pmic_set_register_value(PMIC_ISINK_CH3_EN,0x0); // Turn off ISINK Channel 0
		}
		return 0;
	}

	return -1;
}

static int mt65xx_led_set_cust(struct cust_mt65xx_led *cust, int level)
{
	unsigned int BacklightLevelSupport = Cust_GetBacklightLevelSupport_byPWM();
	if (level > LED_FULL)
		level = LED_FULL;
	else if (level < 0)
		level = 0;

	switch (cust->mode) {
		case MT65XX_LED_MODE_PWM:
			if(level == 0)
			{
				//LEDS_INFO("[LEDS]LK: mt65xx_leds_set_cust: enter mt_pwm_disable()\n");
				mt_pwm_disable(cust->data, cust->config_data.pmic_pad);
				return 1;
			}
			if(strcmp(cust->name,"lcd-backlight") == 0)
			{
				if (BacklightLevelSupport == BACKLIGHT_LEVEL_PWM_256_SUPPORT)
					level = brightness_mapping(level);
				else
					level = brightness_mapto64(level);
			    return brightness_set_pwm(cust->data, level,&cust->config_data);
			}
			else
			{
				return led_set_pwm(cust->data, level);
			}

		case MT65XX_LED_MODE_GPIO:
			return ((cust_brightness_set)(cust->data))(level);
		case MT65XX_LED_MODE_PMIC:
			return brightness_set_pmic(cust->data, level);
		case MT65XX_LED_MODE_CUST_LCM:
			return ((cust_brightness_set)(cust->data))(level);
		case MT65XX_LED_MODE_CUST_BLS_PWM:
			return ((cust_brightness_set)(cust->data))(level);
		case MT65XX_LED_MODE_NONE:
		default:
			break;
	}
	return -1;
}

/****************************************************************************
 * external functions
 ***************************************************************************/
int mt65xx_leds_brightness_set(enum mt65xx_led_type type, enum led_brightness level)
{
	struct cust_mt65xx_led *cust_led_list = get_cust_led_list();

	if (type >= MT65XX_LED_TYPE_TOTAL)
		return -1;

	if (level > LED_FULL)
		level = LED_FULL;
//	else if (level < 0)  //level cannot < 0
//		level = 0;

	if (g_lastlevel[type] != (int)level) {
		g_lastlevel[type] = level;
		dprintf(CRITICAL,"[LEDS]LK: %s level is %d \n\r", cust_led_list[type].name, level);
		return mt65xx_led_set_cust(&cust_led_list[type], level);
	}
	else {
		return -1;
	}

}

void leds_battery_full_charging(void)
{
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_RED, LED_OFF);
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_GREEN, LED_FULL);
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_BLUE, LED_OFF);
}

void leds_battery_low_charging(void)
{
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_RED, LED_FULL);
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_GREEN, LED_OFF);
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_BLUE, LED_OFF);
}

void leds_battery_medium_charging(void)
{
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_RED, LED_FULL);
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_GREEN, LED_OFF);
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_BLUE, LED_OFF);
}

void leds_init(void)
{
	LEDS_INFO("[LEDS]LK: leds_init: mt65xx_backlight_off \n\r");
	mt65xx_backlight_off();
}

void leds_deinit(void)
{
	LEDS_INFO("[LEDS]LK: leds_deinit: LEDS off \n\r");
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_RED, LED_OFF);
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_GREEN, LED_OFF);
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_BLUE, LED_OFF);
}

void mt65xx_backlight_on(void)
{
	enum led_brightness backlight_level = get_cust_led_default_level();
	LEDS_INFO("[LEDS]LK: mt65xx_backlight_on:level =  %d\n\r",backlight_level);
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_LCD, backlight_level);
}

void mt65xx_backlight_off(void)
{
	LEDS_INFO("[LEDS]LK: mt65xx_backlight_off \n\r");
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_LCD, LED_OFF);
}

