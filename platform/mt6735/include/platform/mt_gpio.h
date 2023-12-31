#ifndef _MT_GPIO_H_
#define _MT_GPIO_H_

#include <kernel/mutex.h>
#include <debug.h>
#include <platform/mt_typedefs.h>
#if (!defined(MACH_FPGA))
#include <cust_gpio_usage.h>
#endif
#include <platform/gpio_const.h>

mutex_t gpio_mutex;

/*----------------------------------------------------------------------------*/
//  Error Code No.
#define RSUCCESS	0
#define ERACCESS	1
#define ERINVAL		2
#define ERWRAPPER	3
/*----------------------------------------------------------------------------*/
#ifndef s32
	#define s32 signed int
#endif
#ifndef s64
	#define s64 signed long long
#endif
/*----------------------------------------------------------------------------*/
         
#define MAX_GPIO_PIN    (MT_GPIO_BASE_MAX)
/******************************************************************************
* Enumeration for GPIO pin
******************************************************************************/
/* GPIO MODE CONTROL VALUE*/
typedef enum {
    GPIO_MODE_UNSUPPORTED = -1,
    GPIO_MODE_GPIO  = 0,
    GPIO_MODE_00    = 0,
    GPIO_MODE_01    = 1,
    GPIO_MODE_02    = 2,
    GPIO_MODE_03    = 3,
    GPIO_MODE_04    = 4,
    GPIO_MODE_05    = 5,
    GPIO_MODE_06    = 6,
    GPIO_MODE_07    = 7,

    GPIO_MODE_MAX,
    GPIO_MODE_DEFAULT = GPIO_MODE_01,
} GPIO_MODE;
/*----------------------------------------------------------------------------*/
/* GPIO DIRECTION */
typedef enum {
    GPIO_DIR_UNSUPPORTED = -1,
    GPIO_DIR_IN     = 0,
    GPIO_DIR_OUT    = 1,

    GPIO_DIR_MAX,
    GPIO_DIR_DEFAULT = GPIO_DIR_IN,
} GPIO_DIR;
/*----------------------------------------------------------------------------*/
/* GPIO PULL ENABLE*/
typedef enum {
    GPIO_PULL_EN_UNSUPPORTED = -1,
    GPIO_PULL_DISABLE = 0,
    GPIO_PULL_ENABLE  = 1,

    GPIO_PULL_EN_MAX,
    GPIO_PULL_EN_DEFAULT = GPIO_PULL_ENABLE,
} GPIO_PULL_EN;
/*----------------------------------------------------------------------------*/
/* GPIO SMT*/
typedef enum {
    GPIO_SMT_UNSUPPORTED = -1,
    GPIO_SMT_DISABLE = 0,
    GPIO_SMT_ENABLE  = 1,

    GPIO_SMT_MAX,
    GPIO_SMT_DEFAULT = GPIO_SMT_ENABLE,
} GPIO_SMT;
/*----------------------------------------------------------------------------*/
/* GPIO IES*/
typedef enum {
    GPIO_IES_UNSUPPORTED = -1,
    GPIO_IES_DISABLE = 0,
    GPIO_IES_ENABLE  = 1,

    GPIO_IES_MAX,
    GPIO_IES_DEFAULT = GPIO_IES_ENABLE,
} GPIO_IES;
/*----------------------------------------------------------------------------*/
/* GPIO PULL-UP/PULL-DOWN*/
typedef enum {
    GPIO_PULL_UNSUPPORTED = -1,
    GPIO_PULL_DOWN  = 0,
    GPIO_PULL_UP    = 1,

    GPIO_PULL_MAX,
    GPIO_PULL_DEFAULT = GPIO_PULL_DOWN
} GPIO_PULL;
/*----------------------------------------------------------------------------*/
/* GPIO OUTPUT */
typedef enum {
    GPIO_OUT_UNSUPPORTED = -1,
    GPIO_OUT_ZERO = 0,
    GPIO_OUT_ONE  = 1,

    GPIO_OUT_MAX,
    GPIO_OUT_DEFAULT = GPIO_OUT_ZERO,
    GPIO_DATA_OUT_DEFAULT = GPIO_OUT_ZERO,  /*compatible with DCT*/
} GPIO_OUT;
/*----------------------------------------------------------------------------*/
/* GPIO INPUT */
typedef enum {
    GPIO_IN_UNSUPPORTED = -1,
    GPIO_IN_ZERO = 0,
    GPIO_IN_ONE  = 1,

    GPIO_IN_MAX,
} GPIO_IN;
/*----------------------------------------------------------------------------*/
/* GPIO POWER*/
typedef enum {
    GPIO_VIO28 = 0,
    GPIO_VIO18 = 1,
    GPIO_GPIO_VIO18 = 2,
    GPIO_MSDC_VMC = 3,
    GPIO_VIO_MAX,
} GPIO_POWER;
/*----------------------------------------------------------------------------*/
typedef struct {
    unsigned int val;
    unsigned int set;
    unsigned int rst;
    unsigned int _align1;
} VAL_REGS;
/*----------------------------------------------------------------------------*/
typedef struct {
    VAL_REGS    dir[7];            /*0x0000 ~ 0x006F: 112 bytes*/
    unsigned char       rsv00[144];  /*0x00E0 ~ 0x00FF: 	32 bytes*/
    VAL_REGS    dout[7];           /*0x0400 ~ 0x04DF: 224 bytes*/
    unsigned char       rsv04[144];  /*0x04B0 ~ 0x04FF: 	32 bytes*/
    VAL_REGS    din[7];            /*0x0500 ~ 0x05DF: 224 bytes*/
    unsigned char       rsv05[144];	/*0x05E0 ~ 0x05FF: 	32 bytes*/
    VAL_REGS    mode[21];           /*0x0600 ~ 0x08AF: 688 bytes*/  

} GPIO_REGS;
/*----------------------------------------------------------------------------*/
typedef struct {
    unsigned int no     : 16;
    unsigned int mode   : 3;
    unsigned int pullsel: 1;
    unsigned int din    : 1;
    unsigned int dout   : 1;
    unsigned int pullen : 1;
    unsigned int dir    : 1;
    unsigned int dinv   : 1;
    unsigned int _align : 7;
} GPIO_CFG;
/******************************************************************************
* GPIO Driver interface
******************************************************************************/
/*direction*/
S32 mt_set_gpio_dir(u32 pin, u32 dir);
S32 mt_get_gpio_dir(u32 pin);

/*pull enable*/
S32 mt_set_gpio_pull_enable(u32 pin, u32 enable);
S32 mt_get_gpio_pull_enable(u32 pin);
/*pull select*/
S32 mt_set_gpio_pull_select(u32 pin, u32 select);
S32 mt_get_gpio_pull_select(u32 pin);

/*schmitt trigger*/
S32 mt_set_gpio_smt(u32 pin, u32 enable);
S32 mt_get_gpio_smt(u32 pin);

/*IES*/
S32 mt_set_gpio_ies(u32 pin, u32 enable);
S32 mt_get_gpio_ies(u32 pin);

/*data inversion*/
//S32 mt_set_gpio_inversion(u32 pin, u32 enable);
//S32 mt_get_gpio_inversion(u32 pin);

/*input/output*/
S32 mt_set_gpio_out(u32 pin, u32 output);
S32 mt_get_gpio_out(u32 pin);
S32 mt_get_gpio_in(u32 pin);

/*mode control*/
S32 mt_set_gpio_mode(u32 pin, u32 mode);
S32 mt_get_gpio_mode(u32 pin);

/*misc functions for protect GPIO*/
//void mt_gpio_unlock_init(int all);
void mt_gpio_set_default(void);
void mt_gpio_dump(void);
void mt_gpio_load(GPIO_REGS *regs);
void mt_gpio_checkpoint_save(void);
void mt_gpio_checkpoint_compare(void);
void mt_gpio_set_default_dump(void);

#endif //_MT_GPIO_H_
