/******************************************************************************
 * mt_gpio.c - MTKLinux GPIO Device Driver
 *
 * Copyright 2008-2009 MediaTek Co.,Ltd.
 *
 * DESCRIPTION:
 *     This file provid the other drivers GPIO relative functions
 *
 ******************************************************************************/

#include <platform/mt_reg_base.h>
#include <platform/mt_gpio.h>
#include <platform/gpio_cfg.h>
#include <debug.h>
/******************************************************************************
 MACRO Definition
******************************************************************************/
//#define  GIO_SLFTEST
#define GPIO_DEVICE "mt-gpio"
#define VERSION     GPIO_DEVICE
#define GPIO_BRINGUP
/*---------------------------------------------------------------------------*/
#define GPIO_WR32(addr, data)   DRV_WriteReg32(addr,data)
#define GPIO_RD32(addr)         DRV_Reg32(addr)
#define GPIO_SW_SET_BITS(BIT,REG)   GPIO_WR32(REG,GPIO_RD32(REG) | ((unsigned long)(BIT)))
#define GPIO_SET_BITS(BIT,REG)   ((*(volatile u32*)(REG)) = (u32)(BIT))
#define GPIO_CLR_BITS(BIT,REG)   ((*(volatile u32*)(REG)) &= ~((u32)(BIT)))

/*---------------------------------------------------------------------------*/
#define TRUE                   1
#define FALSE                  0
/*---------------------------------------------------------------------------*/
//#define MAX_GPIO_REG_BITS      16
//#define MAX_GPIO_MODE_PER_REG  5
//#define GPIO_MODE_BITS         3
/*---------------------------------------------------------------------------*/
#define GPIOTAG                "[GPIO] "
#define GPIOLOG(fmt, arg...)   dprintf(INFO,GPIOTAG fmt, ##arg)
#define GPIOMSG(fmt, arg...)   dprintf(INFO,fmt, ##arg)
#define GPIOERR(fmt, arg...)   dprintf(INFO,GPIOTAG "%5d: "fmt, __LINE__, ##arg)
#define GPIOFUC(fmt, arg...)   //dprintk(INFO,GPIOTAG "%s\n", __FUNCTION__)
#define GIO_INVALID_OBJ(ptr)   ((ptr) != gpio_obj)
/******************************************************************************
Enumeration/Structure
******************************************************************************/
#if defined(MACH_FPGA)
		S32 mt_set_gpio_dir(u32 pin, u32 dir)			{return RSUCCESS;}
		S32 mt_get_gpio_dir(u32 pin)				{return GPIO_DIR_UNSUPPORTED;}
		S32 mt_set_gpio_pull_enable(u32 pin, u32 enable)	{return RSUCCESS;}
		S32 mt_get_gpio_pull_enable(u32 pin)			{return GPIO_PULL_EN_UNSUPPORTED;}
		S32 mt_set_gpio_pull_select(u32 pin, u32 select)	{return RSUCCESS;}
		S32 mt_get_gpio_pull_select(u32 pin)			{return GPIO_PULL_UNSUPPORTED;}
		S32 mt_set_gpio_smt(u32 pin, u32 enable)		{return RSUCCESS;}
		S32 mt_get_gpio_smt(u32 pin)				{return GPIO_SMT_UNSUPPORTED;}
		S32 mt_set_gpio_ies(u32 pin, u32 enable)		{return RSUCCESS;}
		S32 mt_get_gpio_ies(u32 pin)				{return GPIO_IES_UNSUPPORTED;}
		S32 mt_set_gpio_out(u32 pin, u32 output)		{return RSUCCESS;}
		S32 mt_get_gpio_out(u32 pin)				{return GPIO_OUT_UNSUPPORTED;}
		S32 mt_get_gpio_in(u32 pin) 				{return GPIO_IN_UNSUPPORTED;}
		S32 mt_set_gpio_mode(u32 pin, u32 mode) 		{return RSUCCESS;}
		S32 mt_get_gpio_mode(u32 pin)				{return GPIO_MODE_UNSUPPORTED;}
#else

typedef struct
{
    S32 en_flag;// 1 enable
}GPIO_PUPD_flag;

GPIO_PUPD_flag gpio_pupd_en_flag[MT_GPIO_BASE_MAX] = {{0}};


struct mt_gpio_obj {
    GPIO_REGS       *reg;
};
static struct mt_gpio_obj gpio_dat = {
    .reg  = (GPIO_REGS*)(GPIO_BASE),
};
static struct mt_gpio_obj *gpio_obj = &gpio_dat;
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_dir_chip(u32 pin, u32 dir)
{
#ifndef GPIO_BRINGUP
    u32 pos;
#endif
    u32 bit;
    u32 reg;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    if (dir >= GPIO_DIR_MAX)
        return -ERINVAL;

    //pos = pin / MAX_GPIO_REG_BITS;
    bit = DIR_offset[pin].offset;
#ifdef GPIO_BRINGUP
	reg = GPIO_RD32(DIR_addr[pin].addr);
	if (dir == GPIO_DIR_IN)
		   reg &= (~(1<<bit));
    else
		   reg |= (1 << bit);

	GPIO_WR32(DIR_addr[pin].addr,reg);
#else
    if (dir == GPIO_DIR_IN)
        GPIO_SET_BITS((1L << bit), &obj->reg->dir[pos].rst);
    else
        GPIO_SET_BITS((1L << bit), &obj->reg->dir[pos].set);
#endif
    return RSUCCESS;

}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_dir_chip(u32 pin)
{
    u32 bit;
    u32 reg;
    struct mt_gpio_obj *obj = gpio_obj;

    if (!obj)
        return -ERACCESS;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    bit = DIR_offset[pin].offset;

    reg = GPIO_RD32(DIR_addr[pin].addr);
    return (((reg & (1L << bit)) != 0)? 1: 0);
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_pull_enable_chip(u32 pin, u32 enable)
{
    u32 reg=0;
	u32 bit=0;
    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

#ifdef GPIO_BRINGUP


	if(PULLEN_offset[pin].offset == -1 && pupd_offset[pin].offset==-1){
			return GPIO_PULL_EN_UNSUPPORTED;
	}
	/*
	if(pin>=160 && pin <=165){
		bit = pupd_offset[pin].offset;
		reg = GPIO_RD32(pupd_addr[pin].addr);
		if (enable == GPIO_PULL_DISABLE){
			reg &= ~(0x7 << bit);
		}
		else{
			reg |=(1 << bit);
		}
		GPIO_WR32(pupd_addr[pin].addr, reg);
		return RSUCCESS;

	}
	*/
	if(PULLEN_offset[pin].offset != -1){
		bit = PULLEN_offset[pin].offset;
		reg = GPIO_RD32(PULLEN_addr[pin].addr);
		if (enable == GPIO_PULL_DISABLE)
			reg &= (~(1<<bit));
		else
			reg |= (1 << bit);
		GPIO_WR32(PULLEN_addr[pin].addr, reg);
	}
	else
	{
		bit = pupd_offset[pin].offset;
		reg = GPIO_RD32(pupd_addr[pin].addr);
		if (enable == GPIO_PULL_DISABLE){
			reg &= (~(0x7 << bit)); //0x0 or 0x4 disable
			gpio_pupd_en_flag[pin].en_flag=0;
		}
		else{
			reg |=(1 << bit);
			gpio_pupd_en_flag[pin].en_flag=1;
		}
		GPIO_WR32(pupd_addr[pin].addr, reg);
	}

#else

    if(PULLEN_offset[pin].offset == -1){
	  return GPIO_PULL_EN_UNSUPPORTED;
    }
    else{
    	  if (enable == GPIO_PULL_DISABLE)
		GPIO_SET_BITS((1L << (PULLEN_offset[pin].offset)), PULLEN_addr[pin].addr + 8);
	  else
		GPIO_SET_BITS((1L << (PULLEN_offset[pin].offset)), PULLEN_addr[pin].addr + 4);
    }
#endif
    return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_pull_enable_chip(u32 pin)
{
    unsigned long data;
	u32 bit=0;


    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    if(PULLEN_offset[pin].offset == -1 && pupd_offset[pin].offset==-1){
			return GPIO_PULL_EN_UNSUPPORTED;
	}

    if(PULLEN_offset[pin].offset != -1){
		    bit = PULLEN_offset[pin].offset;
		    data = GPIO_RD32(PULLEN_addr[pin].addr);
	        return (((data & (1L << bit)) != 0)? 1: 0);
    }else{
    		bit = pupd_offset[pin].offset;
		    data = GPIO_RD32(pupd_addr[pin].addr);
		    return (((data & (0x7 << bit)) != 0)? 1: 0);
    }
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_smt_chip(u32 pin, u32 enable)
{
    //unsigned long flags;
    u32 reg=0;
	u32 bit=0;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;
#ifdef GPIO_BRINGUP

	if(SMT_offset[pin].offset == -1){
		return GPIO_SMT_UNSUPPORTED;

	}
	else{
		bit = SMT_offset[pin].offset;
		reg = GPIO_RD32(SMT_addr[pin].addr);
	    if (enable == GPIO_SMT_DISABLE)
		    reg &= (~(1<<bit));
	    else
		    reg |= (1 << bit);
	}
	//printf("SMT addr(%x),value(%x)\n",SMT_addr[pin].addr,GPIO_RD32(SMT_addr[pin].addr));
	GPIO_WR32(SMT_addr[pin].addr, reg);
#else

    if(SMT_offset[pin].offset == -1){
	  return GPIO_SMT_UNSUPPORTED;
    }
    else{
      if (enable == GPIO_SMT_DISABLE)
		GPIO_SET_BITS((1L << (SMT_offset[pin].offset)), SMT_addr[pin].addr + 8);
	  else
		GPIO_SET_BITS((1L << (SMT_offset[pin].offset)), SMT_addr[pin].addr + 4);
    }
#endif
return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_smt_chip(u32 pin)
{
    unsigned long data;
    u32 bit =0;
    bit = SMT_offset[pin].offset;
    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    if(SMT_offset[pin].offset == -1){
	  return GPIO_SMT_UNSUPPORTED;
    }
    else{
	  data = GPIO_RD32(SMT_addr[pin].addr);
      return (((data & (1L << bit)) != 0)? 1: 0);
    }
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_ies_chip(u32 pin, u32 enable)
{
    //unsigned long flags;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    if(IES_offset[pin].offset == -1){
	  return GPIO_IES_UNSUPPORTED;
    }
    else{
      if (enable == GPIO_IES_DISABLE)
		GPIO_SET_BITS((1L << (IES_offset[pin].offset)), IES_addr[pin].addr + 8);
	  else
		GPIO_SET_BITS((1L << (IES_offset[pin].offset)), IES_addr[pin].addr + 4);
    }

    return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_ies_chip(u32 pin)
{
    unsigned long data;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    if(IES_offset[pin].offset == -1){
	  return GPIO_IES_UNSUPPORTED;
    }
    else{
	  data = GPIO_RD32(IES_addr[pin].addr);

          return (((data & (1L << (IES_offset[pin].offset))) != 0)? 1: 0);
    }
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_pull_select_chip(u32 pin, u32 select)
{
    //unsigned long flags;
    u32 reg=0;
    unsigned long bit = 0;
	u32 mask = (1L << 4) - 1;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

#ifdef GPIO_BRINGUP


  	if((PULL_offset[pin].offset == -1) &&(pupd_offset[pin].offset == -1)) {
		return GPIO_PULL_UNSUPPORTED;
	}

	if(pin>=160 && pin <=165){


		if(0==gpio_pupd_en_flag[pin].en_flag){
			return RSUCCESS;
		}

		bit =pupd_offset[pin].offset;//special spec in pupd reg different form pullsel
		reg = GPIO_RD32(pupd_addr[pin].addr);
		if (select == GPIO_PULL_UP)//0x2 pull up
		{
			reg &= (~(mask << bit));
	        reg |= (0x2 << bit);
		}
	    else //0x6 pull down
		{
		    reg &= (~(mask << bit));
	        reg |= (0x6 << bit);
	    }
		//printf("fwq pullset pin=%d,3.............\n",pin);
		GPIO_WR32(pupd_addr[pin].addr, reg);
		return RSUCCESS;

	}

	//printf("fwq pullset pin=%d,select(%d)\n",pin,select);
	if(PULL_offset[pin].offset != -1){

		bit = PULL_offset[pin].offset;
		reg = GPIO_RD32(PULL_addr[pin].addr);
		if (select == GPIO_PULL_DOWN)
		    reg &= (~(1<<bit));
	    else
		    reg |= (1 << bit);
		//printf("fwq pullset pin=%d,2.............\n",pin);
		GPIO_WR32(PULL_addr[pin].addr, reg);
	}
	else {

		if(0==gpio_pupd_en_flag[pin].en_flag){
			return RSUCCESS;
		}
		bit =pupd_offset[pin].offset+2;//special spec in pupd reg different form pullsel
		reg = GPIO_RD32(pupd_addr[pin].addr);
		if (select == GPIO_PULL_UP)
		    reg &= (~(1<<bit));
	    else
		    reg |= (1 << bit);
		//printf("fwq pullset pin=%d,3.............\n",pin);
		GPIO_WR32(pupd_addr[pin].addr, reg);

	}

#else

    if((PULL_offset[pin].offset == -1) ){
	  return GPIO_PULL_UNSUPPORTED;
    }
    else{
	  if (select == GPIO_PULL_DOWN)
		GPIO_SET_BITS((1L << (PULL_offset[pin].offset)), PULL_addr[pin].addr + 8);
	  else
		GPIO_SET_BITS((1L << (PULL_offset[pin].offset)), PULL_addr[pin].addr + 4);
    }
#endif
    return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_pull_select_chip(u32 pin)
{

    unsigned long data;
	unsigned long bit = 0;
	u32 mask = (1L << 4) - 1;

	if(pin>=160 && pin <=165){

	  bit =pupd_offset[pin].offset;
	  data = GPIO_RD32(pupd_addr[pin].addr);
      return (((((data >> bit) & mask)==0x2))? 1: 0);//0x2 pull up
	}

    if((PULL_offset[pin].offset == -1) && (pupd_offset[pin].offset == -1)){
	  return GPIO_PULL_UNSUPPORTED;
    }
    else if(PULL_offset[pin].offset == -1){
	  data = GPIO_RD32(pupd_addr[pin].addr);

      return (((data & (1L << (pupd_offset[pin].offset+2))) != 0)? 0: 1);
    }
    else{
	  data = GPIO_RD32(PULL_addr[pin].addr);
      return (((data & (1L << (PULL_offset[pin].offset))) != 0)? 1: 0);
    }


#if 0
    unsigned long data;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    if((PULL_offset[pin].offset == -1) ){
	  return GPIO_PULL_UNSUPPORTED;
    }
    else{
	  data = GPIO_RD32(PULL_addr[pin].addr);

    	  return (((data & (1L << (PULL_offset[pin].offset))) != 0)? 1: 0);
    }
	#endif
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_out_chip(u32 pin, u32 output)
{
#ifndef GPIO_BRINGUP
    u32 pos;
#endif
    u32 bit;
    u32 reg=0;
    //struct mt_gpio_obj *obj = gpio_obj;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    if (output >= GPIO_OUT_MAX)
        return -ERINVAL;

    bit = DATAOUT_offset[pin].offset;

#ifdef GPIO_BRINGUP
	reg = GPIO_RD32(DATAOUT_addr[pin].addr);
	if (output == GPIO_OUT_ZERO)
		reg &= (~(1<<bit));
	else
		reg |= (1 << bit);

	GPIO_WR32(DATAOUT_addr[pin].addr,reg);

#else

    if (output == GPIO_OUT_ZERO)
        GPIO_SET_BITS((1L << bit), &obj->reg->dout[pos].rst);
    else
        GPIO_SET_BITS((1L << bit), &obj->reg->dout[pos].set);
#endif
    return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_out_chip(u32 pin)
{
    u32 pos;
    u32 bit;
    u32 reg;
    struct mt_gpio_obj *obj = gpio_obj;

    if (!obj)
        return -ERACCESS;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    pos = pin / MAX_GPIO_REG_BITS;
    bit = pin % MAX_GPIO_REG_BITS;

    reg = GPIO_RD32(&obj->reg->dout[pos].val);
    return (((reg & (1L << bit)) != 0)? 1: 0);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_in_chip(u32 pin)
{
    u32 bit;
    u32 reg;
    struct mt_gpio_obj *obj = gpio_obj;

    if (!obj)
        return -ERACCESS;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

	bit = DIN_offset[pin].offset;
    reg = GPIO_RD32(DIN_addr[pin].addr);
    return (((reg & (1L << bit)) != 0)? 1: 0);
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_mode_chip(u32 pin, u32 mode)
{
#ifndef GPIO_BRINGUP
    u32 pos;
#endif
    u32 bit;
    u32 reg;
    u32 mask = (1L << GPIO_MODE_BITS) - 1;
    struct mt_gpio_obj *obj = gpio_obj;

    if (!obj)
        return -ERACCESS;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;

    if (mode >= GPIO_MODE_MAX)
        return -ERINVAL;

	//pos = pin / MAX_GPIO_MODE_PER_REG;
	bit = MODE_offset[pin].offset;

#ifdef GPIO_BRINGUP
    mode = mode & mask;
    //printf("fwq pin=%d,mode=%d, offset=%d\n",pin,mode,bit);

    reg = GPIO_RD32(MODE_addr[pin].addr);
	//printf("fwq pin=%d,beforereg[%x]=%x\n",pin,MODE_addr[pin].addr,reg);

    reg &= (~(mask << bit));
	//printf("fwq pin=%d,clr=%x\n",pin,~(mask << (GPIO_MODE_BITS*bit)));
	reg |= (mode << bit);
	//printf("fwq pin=%d,reg[%x]=%x\n",pin,MODE_addr[pin].addr,reg);

	GPIO_WR32( MODE_addr[pin].addr,reg);
    //printf("fwq pin=%d,moderead=%x\n",pin,GPIO_RD32(MODE_addr[pin].addr));

#else

    reg = ((1L << (GPIO_MODE_BITS*bit)) << 3) | (mode << (GPIO_MODE_BITS*bit));

    GPIO_WR32(&obj->reg->mode[pos]._align1, reg);
#endif
return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_mode_chip(u32 pin)
{

    u32 bit;
    u32 reg;
    u32 mask = (1L << GPIO_MODE_BITS) - 1;
    //struct mt_gpio_obj *obj = gpio_obj;

    if (pin >= MAX_GPIO_PIN)
        return -ERINVAL;


	bit = MODE_offset[pin].offset;
   // printf("fwqread bit=%d,offset=%d",bit,MODE_offset[pin].offset);
	//reg = GPIO_RD32(&obj->reg->mode[pos].val);
	reg = GPIO_RD32(MODE_addr[pin].addr);
   // printf("fwqread  pin=%d,moderead=%x, bit=%d\n",pin,GPIO_RD32(MODE_addr[pin].addr),bit);
	return ((reg >> bit) & mask);
}
/*---------------------------------------------------------------------------*/
void mt_gpio_pin_decrypt(u32 *cipher)
{
	//just for debug, find out who used pin number directly
	if((*cipher & (0x80000000)) == 0){
#ifndef DUMMY_AP
		GPIOERR("GPIO%u HARDCODE warning!!! \n",(unsigned int)*cipher);
		//dump_stack();
		//return;
#endif
	}

	//GPIOERR("Pin magic number is %x\n",*cipher);
	*cipher &= ~(0x80000000);
	return;
}
//set GPIO function in fact
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_dir(u32 pin, u32 dir)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_set_gpio_dir_chip(pin,dir);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_dir(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_get_gpio_dir_chip(pin);
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_pull_enable(u32 pin, u32 enable)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_set_gpio_pull_enable_chip(pin,enable);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_pull_enable(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_get_gpio_pull_enable_chip(pin);
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_pull_select(u32 pin, u32 select)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_set_gpio_pull_select_chip(pin,select);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_pull_select(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_get_gpio_pull_select_chip(pin);
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_smt(u32 pin, u32 enable)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_set_gpio_smt_chip(pin,enable);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_smt(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_get_gpio_smt_chip(pin);
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_ies(u32 pin, u32 enable)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_set_gpio_ies_chip(pin,enable);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_ies(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_get_gpio_ies_chip(pin);
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_out(u32 pin, u32 output)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_set_gpio_out_chip(pin,output);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_out(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_get_gpio_out_chip(pin);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_in(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_get_gpio_in_chip(pin);
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_mode(u32 pin, u32 mode)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_set_gpio_mode_chip(pin,mode);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_mode(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
    return mt_get_gpio_mode_chip(pin);
}
/*****************************************************************************/
/* sysfs operation                                                           */
/*****************************************************************************/
#if 0
void mt_gpio_self_test(void)
{
    int i, val;
    for (i = 0; i < GPIO_MAX; i++)
    {
        S32 res,old;
        GPIOMSG("GPIO-%3d test\n", i);
        /*direction test*/
        old = mt_get_gpio_dir(i);
        if (old == 0 || old == 1) {
            GPIOLOG(" dir old = %d\n", old);
        } else {
            GPIOERR(" test dir fail: %d\n", old);
            break;
        }
        if ((res = mt_set_gpio_dir(i, GPIO_DIR_OUT)) != RSUCCESS) {
            GPIOERR(" set dir out fail: %d\n", res);
            break;
        } else if ((res = mt_get_gpio_dir(i)) != GPIO_DIR_OUT) {
            GPIOERR(" get dir out fail: %d\n", res);
            break;
        } else {
            /*output test*/
            S32 out = mt_get_gpio_out(i);
            if (out != 0 && out != 1) {
                GPIOERR(" get out fail = %d\n", old);
                break;
            }
            for (val = 0; val < GPIO_OUT_MAX; val++) {
                if ((res = mt_set_gpio_out(i,0)) != RSUCCESS) {
                    GPIOERR(" set out[%d] fail: %d\n", val, res);
                    break;
                } else if ((res = mt_get_gpio_out(i)) != 0) {
                    GPIOERR(" get out[%d] fail: %d\n", val, res);
                    break;
                }
            }
            if ((res = mt_set_gpio_out(i,out)) != RSUCCESS)
            {
                GPIOERR(" restore out fail: %d\n", res);
                break;
            }
        }

        if ((res = mt_set_gpio_dir(i, GPIO_DIR_IN)) != RSUCCESS) {
            GPIOERR(" set dir in fail: %d\n", res);
            break;
        } else if ((res = mt_get_gpio_dir(i)) != GPIO_DIR_IN) {
            GPIOERR(" get dir in fail: %d\n", res);
            break;
        } else {
            GPIOLOG(" input data = %d\n", res);
        }

        if ((res = mt_set_gpio_dir(i, old)) != RSUCCESS) {
            GPIOERR(" restore dir fail: %d\n", res);
            break;
        }
        for (val = 0; val < GPIO_PULL_EN_MAX; val++) {
            if ((res = mt_set_gpio_pull_enable(i,val)) != RSUCCESS) {
                GPIOERR(" set pullen[%d] fail: %d\n", val, res);
                break;
            } else if ((res = mt_get_gpio_pull_enable(i)) != val) {
                GPIOERR(" get pullen[%d] fail: %d\n", val, res);
                break;
            }
        }
        if ((res = mt_set_gpio_pull_enable(i, old)) != RSUCCESS) {
            GPIOERR(" restore pullen fail: %d\n", res);
            break;
        }

        /*pull select test*/
        old = mt_get_gpio_pull_select(i);
        if (old == 0 || old == 1)
            GPIOLOG(" pullsel old = %d\n", old);
        else {
            GPIOERR(" pullsel fail: %d\n", old);
            break;
        }
        for (val = 0; val < GPIO_PULL_MAX; val++) {
            if ((res = mt_set_gpio_pull_select(i,val)) != RSUCCESS) {
                GPIOERR(" set pullsel[%d] fail: %d\n", val, res);
                break;
            } else if ((res = mt_get_gpio_pull_select(i)) != val) {
                GPIOERR(" get pullsel[%d] fail: %d\n", val, res);
                break;
            }
        }
        if ((res = mt_set_gpio_pull_select(i, old)) != RSUCCESS)
        {
            GPIOERR(" restore pullsel fail: %d\n", res);
            break;
        }

        /*mode control*/
		old = mt_get_gpio_mode(i);
		if ((old >= GPIO_MODE_00) && (val < GPIO_MODE_MAX)){
			GPIOLOG(" mode old = %d\n", old);
		}
		else{
			GPIOERR(" get mode fail: %d\n", old);
			break;
		}
		for (val = 0; val < GPIO_MODE_MAX; val++) {
			if ((res = mt_set_gpio_mode(i, val)) != RSUCCESS) {
				GPIOERR("set mode[%d] fail: %d\n", val, res);
				break;
			} else if ((res = mt_get_gpio_mode(i)) != val) {
				GPIOERR("get mode[%d] fail: %d\n", val, res);
				break;
			}
		}
		if ((res = mt_set_gpio_mode(i,old)) != RSUCCESS) {
			GPIOERR(" restore mode fail: %d\n", res);
			break;
		}
    }
    GPIOLOG("GPIO test done\n");
}
/*----------------------------------------------------------------------------*/
void mt_gpio_dump(void)
{
    GPIO_REGS *regs = (GPIO_REGS*)(GPIO_BASE);
    int idx;

    GPIOMSG("---# dir #-----------------------------------------------------------------\n");
    for (idx = 0; idx < sizeof(regs->dir)/sizeof(regs->dir[0]); idx++) {
        GPIOMSG("0x%04X ", regs->dir[idx].val);
        if (7 == (idx % 8)) GPIOMSG("\n");
    }
    GPIOMSG("\n---# pullen #--------------------------------------------------------------\n");
    for (idx = 0; idx < sizeof(regs->pullen)/sizeof(regs->pullen[0]); idx++) {
        GPIOMSG("0x%04X ", regs->pullen[idx].val);
        if (7 == (idx % 8)) GPIOMSG("\n");
    }
    GPIOMSG("\n---# pullsel #-------------------------------------------------------------\n");
    for (idx = 0; idx < sizeof(regs->pullsel)/sizeof(regs->pullsel[0]); idx++) {
        GPIOMSG("0x%04X ", regs->pullsel[idx].val);
        if (7 == (idx % 8)) GPIOMSG("\n");
    }
    GPIOMSG("\n---# dout #----------------------------------------------------------------\n");
    for (idx = 0; idx < sizeof(regs->dout)/sizeof(regs->dout[0]); idx++) {
        GPIOMSG("0x%04X ", regs->dout[idx].val);
        if (7 == (idx % 8)) GPIOMSG("\n");
    }
    GPIOMSG("\n---# din  #----------------------------------------------------------------\n");
    for (idx = 0; idx < sizeof(regs->din)/sizeof(regs->din[0]); idx++) {
        GPIOMSG("0x%04X ", regs->din[idx].val);
        if (7 == (idx % 8)) GPIOMSG("\n");
    }
    GPIOMSG("\n---# mode #----------------------------------------------------------------\n");
    for (idx = 0; idx < sizeof(regs->mode)/sizeof(regs->mode[0]); idx++) {
        GPIOMSG("0x%04X ", regs->mode[idx].val);
        if (7 == (idx % 8)) GPIOMSG("\n");
    }
	GPIOMSG("sim0 0x%04X ", regs->sim_ctrl[0].val);
	GPIOMSG("sim1 0x%04X ", regs->sim_ctrl[1].val);
	GPIOMSG("sim2 0x%04X ", regs->sim_ctrl[2].val);
	GPIOMSG("sim3 0x%04X ", regs->sim_ctrl[3].val);

	GPIOMSG("keypad0 0x%04X ", regs->kpad_ctrl[0].val);
	GPIOMSG("keypad1 0x%04X ", regs->kpad_ctrl[1].val);

    GPIOMSG("\n---------------------------------------------------------------------------\n");
}
/*---------------------------------------------------------------------------*/
void mt_gpio_read_pin(GPIO_CFG* cfg, int method)
{
    if (method == 0) {
        GPIO_REGS *cur = (GPIO_REGS*)GPIO_BASE;
        u32 mask = (1L << GPIO_MODE_BITS) - 1;
        int num, bit,idx=cfg->no;
		num = idx / MAX_GPIO_REG_BITS;
		bit = idx % MAX_GPIO_REG_BITS;
		cfg->pullsel= (cur->pullsel[num].val & (1L << bit)) ? (1) : (0);
		cfg->din    = (cur->din[num].val & (1L << bit)) ? (1) : (0);
		cfg->dout   = (cur->dout[num].val & (1L << bit)) ? (1) : (0);
		cfg->pullen = (cur->pullen[num].val & (1L << bit)) ? (1) : (0);
		cfg->dir    = (cur->dir[num].val & (1L << bit)) ? (1) : (0);
		num = idx / MAX_GPIO_MODE_PER_REG;
		bit = idx % MAX_GPIO_MODE_PER_REG;
		cfg->mode   = (cur->mode[num].val >> (GPIO_MODE_BITS*bit)) & mask;
    } else if (method == 1) {
		int idx=cfg->no;
        cfg->pullsel= mt_get_gpio_pull_select(idx);
        cfg->din    = mt_get_gpio_in(idx);
        cfg->dout   = mt_get_gpio_out(idx);
        cfg->pullen = mt_get_gpio_pull_enable(idx);
        cfg->dir    = mt_get_gpio_dir(idx);
        cfg->mode   = mt_get_gpio_mode(idx);
    }
}
/*---------------------------------------------------------------------------*/
void mt_gpio_dump_addr(void)
{
    int idx;
    struct mt_gpio_obj *obj = gpio_obj;
    GPIO_REGS *reg = obj->reg;

    GPIOMSG("# direction\n");
    for (idx = 0; idx < sizeof(reg->dir)/sizeof(reg->dir[0]); idx++)
        GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->dir[idx].val, idx, &reg->dir[idx].set, idx, &reg->dir[idx].rst);
    GPIOMSG("# pull enable\n");
    for (idx = 0; idx < sizeof(reg->pullen)/sizeof(reg->pullen[0]); idx++)
        GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->pullen[idx].val, idx, &reg->pullen[idx].set, idx, &reg->pullen[idx].rst);
    GPIOMSG("# pull select\n");
    for (idx = 0; idx < sizeof(reg->pullsel)/sizeof(reg->pullsel[0]); idx++)
        GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->pullsel[idx].val, idx, &reg->pullsel[idx].set, idx, &reg->pullsel[idx].rst);
    GPIOMSG("# data output\n");
    for (idx = 0; idx < sizeof(reg->dout)/sizeof(reg->dout[0]); idx++)
        GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->dout[idx].val, idx, &reg->dout[idx].set, idx, &reg->dout[idx].rst);
    GPIOMSG("# data input\n");
    for (idx = 0; idx < sizeof(reg->din)/sizeof(reg->din[0]); idx++)
        GPIOMSG("val[%2d] %p\n", idx, &reg->din[idx].val);
    GPIOMSG("# mode\n");
    for (idx = 0; idx < sizeof(reg->mode)/sizeof(reg->mode[0]); idx++)
        GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->mode[idx].val, idx, &reg->mode[idx].set, idx, &reg->mode[idx].rst);
}
#endif
#endif
