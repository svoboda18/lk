#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <bq25601.h>
#include <printf.h>
#include <platform/mt_gpio.h>
#include "mtk_charger_intf.h"

/**********************************************************
  *
  *   [I2C Slave Setting]
  *
  *********************************************************/
#define BQ25601_SLAVE_ADDR_WRITE   0xD6
#define BQ25601_SLAVE_ADDR_READ    0xD7
#define bq25601_SLAVE_ADDR		0x6B
#define PRECC_BATVOL 2800 	//PRECC 2.8V
#define BQ25601_I2C_ID	I2C5
#define GPIO_CHR_CE_PIN	 (GPIO2 | 0x80000000)


struct bq25601_info {
	struct mtk_charger_info mchr_info;
	struct mt_i2c_t i2c;
	int i2c_log_level;
};


int bq25601_dump_register(struct mtk_charger_info *mchr_info);
int bq25601_charging_enable(struct mtk_charger_info *mchr_info, bool enable);
//BSP:add XLEWHLES-25 by ronghe.cheng 20181108 start
int bq25601_reset_watch_dog_timer(struct mtk_charger_info *mchr_info, bool enable);
static struct mtk_charger_ops bq25601_mchr_ops = {
	.dump_register = bq25601_dump_register,
	.enable_charging = bq25601_charging_enable,
};
//BSP:add XLEWHLES-25 by ronghe.cheng 20181108 end
static struct bq25601_info g_bq25601_info = {
	.mchr_info = {
		.name = "primary_charger",
		.alias_name = "bq25601",
		.device_id = -1,
		.mchr_ops = &bq25601_mchr_ops,
	},
	.i2c = {
		.id = I2C1,
		.addr = bq25601_SLAVE_ADDR,
		.mode = ST_MODE,
		.speed = 100,
	},
	.i2c_log_level = INFO,
};
 /**********************************************************
	*
	*	[Global Variable]

  *
  *********************************************************/
kal_uint8 bq25601_reg[bq25601_REG_NUM] = {0};
/**********************************************************
  *
  *   [I2C Function For Read/Write bq25601]
  *
  *********************************************************/
static struct mt_i2c_t bq25601_i2c;

kal_uint32 bq25601_write_byte(kal_uint8 cmd, kal_uint8 writeData)
{
	kal_uint32 ret_code = I2C_OK;
	kal_uint8 write_data[2];
	kal_uint16 len;

	write_data[0]= cmd;
	write_data[1] = writeData;

	bq25601_i2c.id = BQ25601_I2C_ID;
	/* Since i2c will left shift 1 bit, we need to set I2C address to >>1 */
	bq25601_i2c.addr = (BQ25601_SLAVE_ADDR_WRITE >> 1);
	bq25601_i2c.mode = ST_MODE;
	bq25601_i2c.speed = 100;
	len = 2;

	ret_code = i2c_write(&bq25601_i2c, write_data, len);

	if (I2C_OK != ret_code)
		dprintf(INFO, "%s: i2c_write: ret_code: %d\n", __func__, ret_code);

	return ret_code;
}

kal_uint32 bq25601_read_byte(kal_uint8 cmd, kal_uint8 *returnData)
{
	kal_uint32 ret_code = I2C_OK;
	kal_uint16 len;
	*returnData = cmd;

	bq25601_i2c.id = BQ25601_I2C_ID;
	/* Since i2c will left shift 1 bit, we need to set I2C address to >>1 */
	bq25601_i2c.addr = (BQ25601_SLAVE_ADDR_READ >> 1);
	bq25601_i2c.mode = ST_MODE;
	bq25601_i2c.speed = 100;
	len = 1;

	ret_code = i2c_write_read(&bq25601_i2c, returnData, len, len);

	if (I2C_OK != ret_code)
		dprintf(INFO, "%s: i2c_read: ret_code: %d\n", __func__, ret_code);

	return ret_code;
}

/**********************************************************
  *
  *   [Read / Write Function]
  *
  *********************************************************/
kal_uint32 bq25601_read_interface (kal_uint8 RegNum, kal_uint8 *val, kal_uint8 MASK, kal_uint8 SHIFT)
{
	kal_uint8 bq25601_reg = 0;
	kal_uint32 ret = 0;

	dprintf(INFO, "--------------------------------------------------LK\n");

	ret = bq25601_read_byte(RegNum, &bq25601_reg);
	dprintf(INFO, "[bq25601_read_interface] Reg[%x]=0x%x\n", RegNum, bq25601_reg);

	bq25601_reg &= (MASK << SHIFT);
	*val = (bq25601_reg >> SHIFT);

	dprintf(INFO, "[bq25601_read_interface] val=0x%x\n", *val);

	return ret;
}

kal_uint32 bq25601_config_interface (kal_uint8 RegNum, kal_uint8 val, kal_uint8 MASK, kal_uint8 SHIFT)
{
    kal_uint8 bq25601_reg = 0;
    kal_uint32 ret = 0;

    dprintf(INFO, "--------------------------------------------------LK\n");

    ret = bq25601_read_byte(RegNum, &bq25601_reg);

    dprintf(INFO, "[bq25601_config_interface] Reg[%x]=0x%x\n", RegNum, bq25601_reg);

    bq25601_reg &= ~(MASK << SHIFT);
    bq25601_reg |= (val << SHIFT);

    ret = bq25601_write_byte(RegNum, bq25601_reg);

    dprintf(INFO, "[bq25601_config_interface] write Reg[%x]=0x%x\n", RegNum, bq25601_reg);

    // Check
    //bq25601_read_byte(RegNum, &bq25601_reg);
    //dprintf(INFO, "[bq25601_config_interface] Check Reg[%x]=0x%x\n", RegNum, bq25601_reg);

    return ret;
}

/**********************************************************
  *
  *   [Internal Function]
  *
  *********************************************************/
/* CON0---------------------------------------------------- */

void bq25601_set_en_hiz(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON0),
				       (unsigned char) (val),
				       (unsigned char) (CON0_EN_HIZ_MASK),
				       (unsigned char) (CON0_EN_HIZ_SHIFT)
	    );
}

void bq25601_set_iinlim(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON0),
				       (unsigned char) (val),
				       (unsigned char) (CON0_IINLIM_MASK),
				       (unsigned char) (CON0_IINLIM_SHIFT)
	    );
}

void bq25601_set_stat_ctrl(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON0),
				       (unsigned char) (val),
				       (unsigned char) (CON0_STAT_IMON_CTRL_MASK),
				       (unsigned char) (CON0_STAT_IMON_CTRL_SHIFT)
	    );
}

/* CON1---------------------------------------------------- */

void bq25601_set_reg_rst(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON11),
				       (unsigned char) (val),
				       (unsigned char) (CON11_REG_RST_MASK),
				       (unsigned char) (CON11_REG_RST_SHIFT)
	    );
}

void bq25601_set_pfm(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON1),
				       (unsigned char) (val),
				       (unsigned char) (CON1_PFM_MASK),
				       (unsigned char) (CON1_PFM_SHIFT)
	    );
}

void bq25601_set_wdt_rst(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON1),
				       (unsigned char) (val),
				       (unsigned char) (CON1_WDT_RST_MASK),
				       (unsigned char) (CON1_WDT_RST_SHIFT)
	    );
}

void bq25601_set_otg_config(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON1),
				       (unsigned char) (val),
				       (unsigned char) (CON1_OTG_CONFIG_MASK),
				       (unsigned char) (CON1_OTG_CONFIG_SHIFT)
	    );
}


void bq25601_set_chg_config(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON1),
				       (unsigned char) (val),
				       (unsigned char) (CON1_CHG_CONFIG_MASK),
				       (unsigned char) (CON1_CHG_CONFIG_SHIFT)
	    );
}


void bq25601_set_sys_min(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON1),
				       (unsigned char) (val),
				       (unsigned char) (CON1_SYS_MIN_MASK),
				       (unsigned char) (CON1_SYS_MIN_SHIFT)
	    );
}

void bq25601_set_batlowv(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON1),
				       (unsigned char) (val),
				       (unsigned char) (CON1_MIN_VBAT_SEL_MASK),
				       (unsigned char) (CON1_MIN_VBAT_SEL_SHIFT)
	    );
}



/* CON2---------------------------------------------------- */
void bq25601_set_rdson(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON2),
				       (unsigned char) (val),
				       (unsigned char) (CON2_Q1_FULLON_MASK),
				       (unsigned char) (CON2_Q1_FULLON_SHIFT)
	    );
}

void bq25601_set_boost_lim(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON2),
				       (unsigned char) (val),
				       (unsigned char) (CON2_BOOST_LIM_MASK),
				       (unsigned char) (CON2_BOOST_LIM_SHIFT)
	    );
}

void bq25601_set_ichg(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON2),
				       (unsigned char) (val),
				       (unsigned char) (CON2_ICHG_MASK), (unsigned char) (CON2_ICHG_SHIFT)
	    );
}

#if 0 //this function does not exist on bq25601
void bq25601_set_force_20pct(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON2),
				       (unsigned char) (val),
				       (unsigned char) (CON2_FORCE_20PCT_MASK),
				       (unsigned char) (CON2_FORCE_20PCT_SHIFT)
	    );
}
#endif
/* CON3---------------------------------------------------- */

void bq25601_set_iprechg(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON3),
				       (unsigned char) (val),
				       (unsigned char) (CON3_IPRECHG_MASK),
				       (unsigned char) (CON3_IPRECHG_SHIFT)
	    );
}

void bq25601_set_iterm(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON3),
				       (unsigned char) (val),
				       (unsigned char) (CON3_ITERM_MASK), (unsigned char) (CON3_ITERM_SHIFT)
	    );
}

/* CON4---------------------------------------------------- */

void bq25601_set_vreg(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON4),
				       (unsigned char) (val),
				       (unsigned char) (CON4_VREG_MASK), (unsigned char) (CON4_VREG_SHIFT)
	    );
}

void bq25601_set_topoff_timer(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON4),
				       (unsigned char) (val),
				       (unsigned char) (CON4_TOPOFF_TIMER_MASK), (unsigned char) (CON4_TOPOFF_TIMER_SHIFT)
	    );

}


void bq25601_set_vrechg(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON4),
				       (unsigned char) (val),
				       (unsigned char) (CON4_VRECHG_MASK),
				       (unsigned char) (CON4_VRECHG_SHIFT)
	    );
}

/* CON5---------------------------------------------------- */

void bq25601_set_en_term(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON5),
				       (unsigned char) (val),
				       (unsigned char) (CON5_EN_TERM_MASK),
				       (unsigned char) (CON5_EN_TERM_SHIFT)
	    );
}



void bq25601_set_watchdog(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON5),
				       (unsigned char) (val),
				       (unsigned char) (CON5_WATCHDOG_MASK),
				       (unsigned char) (CON5_WATCHDOG_SHIFT)
	    );
}

void bq25601_set_en_timer(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON5),
				       (unsigned char) (val),
				       (unsigned char) (CON5_EN_TIMER_MASK),
				       (unsigned char) (CON5_EN_TIMER_SHIFT)
	    );
}

void bq25601_set_chg_timer(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON5),
				       (unsigned char) (val),
				       (unsigned char) (CON5_CHG_TIMER_MASK),
				       (unsigned char) (CON5_CHG_TIMER_SHIFT)
	    );
}

/* CON6---------------------------------------------------- */

void bq25601_set_treg(unsigned int val)
{
#if 0
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON6),
				       (unsigned char) (val),
				       (unsigned char) (CON6_BOOSTV_MASK), (unsigned char) (CON6_BOOSTV_SHIFT)
	    );
#endif
}

void bq25601_set_vindpm(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON6),
				       (unsigned char) (val),
				       (unsigned char) (CON6_VINDPM_MASK),
				       (unsigned char) (CON6_VINDPM_SHIFT)
	    );
}


void bq25601_set_ovp(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON6),
				       (unsigned char) (val),
				       (unsigned char) (CON6_OVP_MASK),
				       (unsigned char) (CON6_OVP_SHIFT)
	    );

}

void bq25601_set_boostv(unsigned int val)
{

	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON6),
				       (unsigned char) (val),
				       (unsigned char) (CON6_BOOSTV_MASK),
				       (unsigned char) (CON6_BOOSTV_SHIFT)
	    );
}



/* CON7---------------------------------------------------- */

void bq25601_set_tmr2x_en(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON7),
				       (unsigned char) (val),
				       (unsigned char) (CON7_TMR2X_EN_MASK),
				       (unsigned char) (CON7_TMR2X_EN_SHIFT)
	    );
}

void bq25601_set_batfet_disable(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON7),
				       (unsigned char) (val),
				       (unsigned char) (CON7_BATFET_Disable_MASK),
				       (unsigned char) (CON7_BATFET_Disable_SHIFT)
	    );
}


void bq25601_set_batfet_delay(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON7),
				       (unsigned char) (val),
				       (unsigned char) (CON7_BATFET_DLY_MASK),
				       (unsigned char) (CON7_BATFET_DLY_SHIFT)
	    );
}

void bq25601_set_batfet_reset_enable(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON7),
				       (unsigned char) (val),
				       (unsigned char) (CON7_BATFET_RST_EN_MASK),
				       (unsigned char) (CON7_BATFET_RST_EN_SHIFT)
	    );
}


/* CON8---------------------------------------------------- */

unsigned int bq25601_get_system_status(void)
{
	unsigned int ret = 0;
	unsigned char val = 0;

	ret = bq25601_read_interface((unsigned char) (bq25601_CON8),
				     (&val), (unsigned char) (0xFF), (unsigned char) (0x0)
	    );
	return val;
}

unsigned int bq25601_get_vbus_stat(void)
{
	unsigned int ret = 0;
	unsigned char val = 0;

	ret = bq25601_read_interface((unsigned char) (bq25601_CON8),
				     (&val),
				     (unsigned char) (CON8_VBUS_STAT_MASK),
				     (unsigned char) (CON8_VBUS_STAT_SHIFT)
	    );
	return val;
}

unsigned int bq25601_get_chrg_stat(void)
{
	unsigned int ret = 0;
	unsigned char val = 0;

	ret = bq25601_read_interface((unsigned char) (bq25601_CON8),
				     (&val),
				     (unsigned char) (CON8_CHRG_STAT_MASK),
				     (unsigned char) (CON8_CHRG_STAT_SHIFT)
	    );
	return val;
}

unsigned int bq25601_get_vsys_stat(void)
{
	unsigned int ret = 0;
	unsigned char val = 0;

	ret = bq25601_read_interface((unsigned char) (bq25601_CON8),
				     (&val),
				     (unsigned char) (CON8_VSYS_STAT_MASK),
				     (unsigned char) (CON8_VSYS_STAT_SHIFT)
	    );
	return val;
}

unsigned int bq25601_get_pg_stat(void)
{
	unsigned int ret = 0;
	unsigned char val = 0;

	ret = bq25601_read_interface((unsigned char) (bq25601_CON8),
				     (&val),
				     (unsigned char) (CON8_PG_STAT_MASK),
				     (unsigned char) (CON8_PG_STAT_SHIFT)
	    );
	return val;
}


/*CON10----------------------------------------------------------*/

void bq25601_set_int_mask(unsigned int val)
{
	unsigned int ret = 0;

	ret = bq25601_config_interface((unsigned char) (bq25601_CON10),
				       (unsigned char) (val),
				       (unsigned char) (CON10_INT_MASK_MASK),
				       (unsigned char) (CON10_INT_MASK_SHIFT)
	    );
}

/**********************************************************
  *
  *   [Internal Function]
  *
  *********************************************************/
int bq25601_dump_register(struct mtk_charger_info *mchr_info)
{
	unsigned char i = 0;
	dprintf(CRITICAL,"[bq25601] ");
	for (i = 0; i < bq25601_REG_NUM; i++) {
		bq25601_read_byte(i, &bq25601_reg[i]);
		dprintf(CRITICAL,"[0x%x]=0x%x ", i, bq25601_reg[i]);
	}
	dprintf(CRITICAL,"\n");
	return 0;
}



/**********************************************************
  *
  *   [Internal Function]
  *
  *********************************************************/

void bq25601_hw_init(void)
{
	bq25601_set_en_hiz(0x0);
	bq25601_set_vindpm(0x6); //VIN DPM check 4.5V
	bq25601_set_reg_rst(0x0);
	bq25601_set_wdt_rst(0x1); //Kick watchdog
	bq25601_set_sys_min(0x5); //Minimum system voltage 3.5V
	bq25601_set_iprechg(0x7); //Precharge current 480mA
	bq25601_set_iterm(0x2); //Termination current 180mA
	bq25601_set_vreg(0x11); //CV=4.4V
	bq25601_set_batlowv(0x0); //BATLOWV 3.0V
	bq25601_set_vrechg(0x0); //VRECHG 0.1V (4.108V)
	bq25601_set_en_term(0x1); //Enable termination
	bq25601_set_watchdog(0x1); //WDT 40s
	bq25601_set_en_timer(0x0); //Disable charge timer
	bq25601_set_int_mask(0x0); //Disable fault interrupt
}

static CHARGER_TYPE g_chr_type_num = CHARGER_UNKNOWN;
int hw_charging_get_charger_type(void);
extern int g_std_ac_large_current_en;

int bq25601_charging_enable(struct mtk_charger_info *mchr_info, bool enable)
{
	int ichg=0x8;
	int aicr=0x5;

	if(enable){
		hw_charging_get_charger_type();
		if(STANDARD_CHARGER == g_chr_type_num){
			ichg=0x10;//ichg 960mA
			aicr=0xa;//1A
		}else {
			ichg=0x8;//ichg 480mA
			aicr=0x5;//500mA
		}
	}

	if (KAL_TRUE == enable){
		bq25601_set_iinlim(aicr);
		bq25601_set_ichg(ichg);
		bq25601_set_chg_config(0x1); // charger enable
	}else
		bq25601_set_chg_config(0x0);  // charger disable

	dprintf(CRITICAL, "[BATTERY:bq25601] charger enable/disable %d ,ichg=0x%x ,aicr = 0x%x , g_chr_type_num = %d !\r\n", enable,ichg,aicr,g_chr_type_num);
}
//BSP:add XLEWHLES-25 by ronghe.cheng 20181108 start
int bq25601_reset_watch_dog_timer(struct mtk_charger_info *mchr_info, bool enable)
{
	dprintf(CRITICAL, "charging_reset_watch_dog_timer\n");
	bq25601_set_wdt_rst(0x1);	/* Kick watchdog */
	bq25601_set_watchdog(0x3);	/* WDT 160s */
	return 0;
}
//BSP:add XLEWHLES-25 by ronghe.cheng 20181108 end
/***************BC1.2*****************/
extern void Charger_Detect_Init(void);
extern void Charger_Detect_Release(void);
extern void mdelay (unsigned long msec);
extern void pmic_set_register_value(PMU_FLAGS_LIST_ENUM flagname,kal_uint32 val);
extern kal_uint16 pmic_get_register_value(PMU_FLAGS_LIST_ENUM flagname);
static void hw_bc11_init(void)
{
	mdelay(300);
	Charger_Detect_Init();
	//RG_bc11_BIAS_EN=1
	pmic_set_register_value(PMIC_RG_BC11_BIAS_EN, 0x1);//mt6351_upmu_set_rg_bc11_bias_en(0x1);
	//RG_bc11_VSRC_EN[1:0]=00
	pmic_set_register_value(PMIC_RG_BC11_VSRC_EN, 0x0);//mt6351_upmu_set_rg_bc11_vsrc_en(0x0);
	//RG_bc11_VREF_VTH = [1:0]=00
	pmic_set_register_value(PMIC_RG_BC11_VREF_VTH, 0x0);//mt6351_upmu_set_rg_bc11_vref_vth(0x0);
	//RG_bc11_CMP_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x0);//mt6351_upmu_set_rg_bc11_cmp_en(0x0);
	//RG_bc11_IPU_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_IPU_EN, 0x0);//mt6351_upmu_set_rg_bc11_ipu_en(0x0);
	//RG_bc11_IPD_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x0);//mt6351_upmu_set_rg_bc11_ipd_en(0x0);
	//bc11_RST=1
	pmic_set_register_value(PMIC_RG_BC11_RST, 0x1);//mt6351_upmu_set_rg_bc11_rst(0x1);
	//bc11_BB_CTRL=1
	pmic_set_register_value(PMIC_RG_BC11_BB_CTRL, 0x1);//mt6351_upmu_set_rg_bc11_bb_ctrl(0x1);
	
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x1);

	mdelay(50);

}


static U32 hw_bc11_DCD(void)
{
	U32 wChargerAvail = 0;

	//RG_bc11_IPU_EN[1.0] = 10
	pmic_set_register_value(PMIC_RG_BC11_IPU_EN, 0x2);
	//RG_bc11_IPD_EN[1.0] = 01
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x1);//mt6351_upmu_set_rg_bc11_ipd_en(0x1);
	//RG_bc11_VREF_VTH = [1:0]=01
	pmic_set_register_value(PMIC_RG_BC11_VREF_VTH, 0x1);//mt6351_upmu_set_rg_bc11_vref_vth(0x1);
	//RG_bc11_CMP_EN[1.0] = 10
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x2);//mt6351_upmu_set_rg_bc11_cmp_en(0x2);

	mdelay(80);

	wChargerAvail = pmic_get_register_value(PMIC_RGS_BC11_CMP_OUT);//mt6351_upmu_get_rgs_bc11_cmp_out();

	//RG_bc11_IPU_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_IPU_EN, 0x0);//mt6351_upmu_set_rg_bc11_ipu_en(0x0);
	//RG_bc11_IPD_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x0);//mt6351_upmu_set_rg_bc11_ipd_en(0x0);
	//RG_bc11_CMP_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x0);//mt6351_upmu_set_rg_bc11_cmp_en(0x0);
	//RG_bc11_VREF_VTH = [1:0]=00
	pmic_set_register_value(PMIC_RG_BC11_VREF_VTH, 0x0);//mt6351_upmu_set_rg_bc11_vref_vth(0x0);

	return wChargerAvail;
}


static U32 hw_bc11_stepA1(void)
{
	U32 wChargerAvail = 0;

	//RG_bc11_IPD_EN[1.0] = 01
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x1);//mt6351_upmu_set_rg_bc11_ipd_en(0x1);
	//RG_bc11_VREF_VTH = [1:0]=00
	pmic_set_register_value(PMIC_RG_BC11_VREF_VTH, 0x0);//mt6351_upmu_set_rg_bc11_vref_vth(0x0);
	//RG_bc11_CMP_EN[1.0] = 01
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x1);//mt6351_upmu_set_rg_bc11_cmp_en(0x1);

	mdelay(80);

	wChargerAvail = pmic_get_register_value(PMIC_RGS_BC11_CMP_OUT);//mt6351_upmu_get_rgs_bc11_cmp_out();

	//RG_bc11_IPD_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x0);//mt6351_upmu_set_rg_bc11_ipd_en(0x0);
	//RG_bc11_CMP_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x0);//mt6351_upmu_set_rg_bc11_cmp_en(0x0);

	return  wChargerAvail;
}


static U32 hw_bc11_stepA2(void)
{
	U32 wChargerAvail = 0;

	//RG_bc11_VSRC_EN[1.0] = 10
	pmic_set_register_value(PMIC_RG_BC11_VSRC_EN, 0x2);//mt6351_upmu_set_rg_bc11_vsrc_en(0x2);
	//RG_bc11_IPD_EN[1:0] = 01
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x1);//mt6351_upmu_set_rg_bc11_ipd_en(0x1);
	//RG_bc11_VREF_VTH = [1:0]=00
	pmic_set_register_value(PMIC_RG_BC11_VREF_VTH, 0x0);//mt6351_upmu_set_rg_bc11_vref_vth(0x0);
	//RG_bc11_CMP_EN[1.0] = 01
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x1);//mt6351_upmu_set_rg_bc11_cmp_en(0x1);

	mdelay(80);

	wChargerAvail = pmic_get_register_value(PMIC_RGS_BC11_CMP_OUT);//mt6351_upmu_get_rgs_bc11_cmp_out();

	//RG_bc11_VSRC_EN[1:0]=00
	pmic_set_register_value(PMIC_RG_BC11_VSRC_EN, 0x2);//mt6351_upmu_set_rg_bc11_vsrc_en(0x0);
	//RG_bc11_IPD_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x0);//mt6351_upmu_set_rg_bc11_ipd_en(0x0);
	//RG_bc11_CMP_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x0);//mt6351_upmu_set_rg_bc11_cmp_en(0x0);

	return  wChargerAvail;
}


static U32 hw_bc11_stepB2(void)
{
	U32 wChargerAvail = 0;

	//RG_bc11_IPU_EN[1:0]=10
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x2);//mt6351_upmu_set_rg_bc11_ipu_en(0x2);
	//RG_bc11_VREF_VTH = [1:0]=01
	pmic_set_register_value(PMIC_RG_BC11_VREF_VTH, 0x0);//mt6351_upmu_set_rg_bc11_vref_vth(0x1);
	//RG_bc11_CMP_EN[1.0] = 01
	
	pmic_set_register_value(PMIC_RG_BC11_VSRC_EN, 0x1);
	
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x2);//mt6351_upmu_set_rg_bc11_cmp_en(0x1);

	mdelay(80);

	wChargerAvail = pmic_get_register_value(PMIC_RGS_BC11_CMP_OUT);//mt6351_upmu_get_rgs_bc11_cmp_out();

	pmic_set_register_value(PMIC_RG_BC11_VSRC_EN, 0x0);
	//RG_bc11_IPU_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x0);//mt6351_upmu_set_rg_bc11_ipu_en(0x0);
	//RG_bc11_CMP_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x0);//mt6351_upmu_set_rg_bc11_cmp_en(0x0);
	//RG_bc11_VREF_VTH = [1:0]=00
	//pmic_set_register_value(PMIC_RG_BC11_VREF_VTH, 0x0); //mt6351_upmu_set_rg_bc11_vref_vth(0x0);
	if (wChargerAvail == 1) {
	pmic_set_register_value(PMIC_RG_BC11_VSRC_EN, 0x2);
		dprintf(INFO,"charger type: DCP, keep DM voltage source in stepB2\n");
	}

	return  wChargerAvail;
}


static void hw_bc11_done(void)
{
	//RG_bc11_VSRC_EN[1:0]=00
	pmic_set_register_value(PMIC_RG_BC11_VSRC_EN, 0x0);//mt6351_upmu_set_rg_bc11_vsrc_en(0x0);
	//RG_bc11_VREF_VTH = [1:0]=0
	pmic_set_register_value(PMIC_RG_BC11_VREF_VTH, 0x0);//mt6351_upmu_set_rg_bc11_vref_vth(0x0);
	//RG_bc11_CMP_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_CMP_EN, 0x0);//mt6351_upmu_set_rg_bc11_cmp_en(0x0);
	//RG_bc11_IPU_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_IPU_EN, 0x0);//mt6351_upmu_set_rg_bc11_ipu_en(0x0);
	//RG_bc11_IPD_EN[1.0] = 00
	pmic_set_register_value(PMIC_RG_BC11_IPD_EN, 0x0);//mt6351_upmu_set_rg_bc11_ipd_en(0x0);
	//RG_bc11_BIAS_EN=0
	pmic_set_register_value(PMIC_RG_BC11_BIAS_EN, 0x0);//mt6351_upmu_set_rg_bc11_bias_en(0x0);

	Charger_Detect_Release();

}

int hw_charging_get_charger_type(void)
{
	if (CHARGER_UNKNOWN != g_chr_type_num)
		return g_chr_type_num;

	/********* Step initial  ***************/
	hw_bc11_init();

	/********* Step DCD ***************/
	if (1 == hw_bc11_DCD()) {
		/********* Step A1 ***************/
		if (1 == hw_bc11_stepA1()) {
			g_chr_type_num = APPLE_2_1A_CHARGER;
			dprintf(INFO, "step A1 : Apple 2.1A CHARGER!\r\n");
		} else {
			g_chr_type_num = NONSTANDARD_CHARGER;
			dprintf(INFO, "step A1 : Non STANDARD CHARGER!\r\n");
		}
	} else {
		/********* Step A2 ***************/
		if (1 == hw_bc11_stepA2()) {
			/********* Step B2 ***************/
			if (1 == hw_bc11_stepB2()) {
				g_chr_type_num = STANDARD_CHARGER;
				dprintf(INFO, "step B2 : STANDARD CHARGER!\r\n");
			} else {
				g_chr_type_num = CHARGING_HOST;
				dprintf(INFO, "step B2 :  Charging Host!\r\n");
			}
		} else {
			g_chr_type_num = STANDARD_HOST;
			dprintf(INFO, "step A2 : Standard USB Host!\r\n");
		}

	}

	/********* Finally setting *******************************/
	hw_bc11_done();

	return g_chr_type_num;
}
/***************BC1.2*****************/


int bq25601_chg_probe(void)
{
		int ret = 0;
		/* Check primary charger */
		bq25601_hw_init();
		mtk_charger_set_info(&(g_bq25601_info.mchr_info));
		return ret;
}
