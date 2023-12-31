/******************************************************************************
 * gpio_init.c - MT6516 Linux GPIO Device Driver
 *
 * Copyright 2008-2009 MediaTek Co.,Ltd.
 *
 * DESCRIPTION:
 *     default GPIO init
 *
 ******************************************************************************/

#include <platform/mt_gpio.h>

#if !defined(MACH_FPGA)
#include <cust_power.h>
#include <cust_gpio_boot.h>
#endif

#include <platform/mt_reg_base.h>

#include <debug.h>
#define GPIO_INIT_DEBUG 1
/*----------------------------------------------------------------------------*/
#define GPIOTAG "[GPIO] "
#define GPIODBG(fmt, arg...)    dprintf(INFO, GPIOTAG "%s: " fmt, __FUNCTION__ ,##arg)
#define GPIOERR(fmt, arg...)    dprintf(INFO, GPIOTAG "%s: " fmt, __FUNCTION__ ,##arg)
#define GPIOVER(fmt, arg...)    dprintf(INFO, GPIOTAG "%s: " fmt, __FUNCTION__ ,##arg)

#define GPIO_WR32(addr, data)   DRV_WriteReg32(addr,data)
#define GPIO_RD32(addr)         DRV_Reg32(addr)

#define ADDR_BIT 0
#define VAL_BIT  1
#define MASK_BIT 2
/*----------------------------------------------------------------------------*/
#if defined(MACH_FPGA)
void mt_gpio_set_default(void)
{
	return;
}

void mt_gpio_set_default_dump(void)
{
    return;
}

#else

#include <platform/gpio_init.h>
#if defined(GPIO_INIT_DEBUG)
//static GPIO_REGS saved;
#endif
#if 0
u32 gpio_init_dir_data[] = {
    ((GPIO0_DIR       <<  0) |(GPIO1_DIR       <<  1) |(GPIO2_DIR       <<  2) |(GPIO3_DIR       <<  3) |
     (GPIO4_DIR       <<  4) |(GPIO5_DIR       <<  5) |(GPIO6_DIR       <<  6) |(GPIO7_DIR       <<  7) |
     (GPIO8_DIR       <<  8) |(GPIO9_DIR       <<  9) |(GPIO10_DIR      << 10) |(GPIO11_DIR      << 11) |
     (GPIO12_DIR      << 12) |(GPIO13_DIR      << 13) |(GPIO14_DIR      << 14) |(GPIO15_DIR      << 15) |
     (GPIO16_DIR      << 16) |(GPIO17_DIR      << 17) |(GPIO18_DIR      << 18) |(GPIO19_DIR      << 19) |
     (GPIO20_DIR      << 20) |(GPIO21_DIR      << 21) |(GPIO22_DIR      << 22) |(GPIO23_DIR      << 23) |
     (GPIO24_DIR      << 24) |(GPIO25_DIR      << 25) |(GPIO26_DIR      << 26) |(GPIO27_DIR      << 27) |
     (GPIO28_DIR      << 28) |(GPIO29_DIR      << 29) |(GPIO30_DIR      << 30) |(GPIO31_DIR      << 31)),

    ((GPIO32_DIR      <<  0) |(GPIO33_DIR      <<  1) |(GPIO34_DIR      <<  2) |(GPIO35_DIR      <<  3) |
     (GPIO36_DIR      <<  4) |(GPIO37_DIR      <<  5) |(GPIO38_DIR      <<  6) |(GPIO39_DIR      <<  7) |
     (GPIO40_DIR      <<  8) |(GPIO41_DIR      <<  9) |(GPIO42_DIR      << 10) |(GPIO43_DIR      << 11) |
     (GPIO44_DIR      << 12) |(GPIO45_DIR      << 13) |(GPIO46_DIR      << 14) |(GPIO47_DIR      << 15)|
     (GPIO48_DIR      << 16) |(GPIO49_DIR      << 17) |(GPIO50_DIR      << 18) |(GPIO51_DIR      << 19) |
     (GPIO52_DIR      <<  20) |(GPIO53_DIR      << 21) |(GPIO54_DIR      << 22) |(GPIO55_DIR      << 23) |
     (GPIO56_DIR      <<  24) |(GPIO57_DIR      <<  25) |(GPIO58_DIR      << 26) |(GPIO59_DIR      << 27) |
     (GPIO60_DIR      << 28) |(GPIO61_DIR      << 29) |(GPIO62_DIR      << 30) |(GPIO63_DIR      << 31)),

    ((GPIO64_DIR      <<  0) |(GPIO65_DIR      <<  1) |(GPIO66_DIR      <<  2) |(GPIO67_DIR      <<  3) |
     (GPIO68_DIR      <<  4) |(GPIO69_DIR      <<  5) |(GPIO70_DIR      <<  6) |(GPIO71_DIR      <<  7) |
     (GPIO72_DIR      <<  8) |(GPIO73_DIR      <<  9) |(GPIO74_DIR      << 10) |(GPIO75_DIR      << 11) |
     (GPIO76_DIR      << 12) |(GPIO77_DIR      << 13) |(GPIO78_DIR      << 14) |(GPIO79_DIR      << 15)|
     (GPIO80_DIR      <<  16) |(GPIO81_DIR      << 17) |(GPIO82_DIR      <<  18) |(GPIO83_DIR    <<  19) |
     (GPIO84_DIR      <<  20) |(GPIO85_DIR      <<  21) |(GPIO86_DIR      <<  22) |(GPIO87_DIR   <<  23) |
     (GPIO88_DIR      <<  24) |(GPIO89_DIR      <<  25) |(GPIO90_DIR      << 26) |(GPIO91_DIR    << 27) |
     (GPIO92_DIR      <<  28) |(GPIO93_DIR      << 29) |(GPIO94_DIR      << 30) |(GPIO95_DIR     << 31)),

    ((GPIO96_DIR      <<  0) |(GPIO97_DIR      <<  1) |(GPIO98_DIR      <<  2) |(GPIO99_DIR      <<  3) |
     (GPIO100_DIR     <<  4) |(GPIO101_DIR     <<  5) |(GPIO102_DIR     <<  6) |(GPIO103_DIR     <<  7) |
     (GPIO104_DIR     <<  8) |(GPIO105_DIR     <<  9) |(GPIO106_DIR     << 10) |(GPIO107_DIR     << 11) |
     (GPIO108_DIR     << 12) |(GPIO109_DIR     << 13) |(GPIO110_DIR     << 14) |(GPIO111_DIR     << 15)|
     (GPIO112_DIR     <<  16) |(GPIO113_DIR     << 17) |(GPIO114_DIR     << 18) |(GPIO115_DIR     << 19) |
     (GPIO116_DIR     <<  20) |(GPIO117_DIR     <<  21) |(GPIO118_DIR     <<  22) |(GPIO119_DIR     <<  23) |
     (GPIO120_DIR     <<  24) |(GPIO121_DIR     <<  25) |(GPIO122_DIR     << 26) |(GPIO123_DIR     << 27) |
     (GPIO124_DIR     << 28) |(GPIO125_DIR     << 29) |(GPIO126_DIR     << 30) |(GPIO127_DIR     << 31)),

    ((GPIO128_DIR     <<  0) |(GPIO129_DIR     <<  1) |(GPIO130_DIR     <<  2) |(GPIO131_DIR     <<  3) |
     (GPIO132_DIR     <<  4) |(GPIO133_DIR     <<  5) |(GPIO134_DIR     <<  6) |(GPIO135_DIR     <<  7) |
     (GPIO136_DIR     <<  8) |(GPIO137_DIR     <<  9) |(GPIO138_DIR     << 10) |(GPIO139_DIR     << 11) |
     (GPIO140_DIR     << 12) |(GPIO141_DIR     << 13) |(GPIO142_DIR     << 14) |(GPIO143_DIR     << 15)|
     (GPIO144_DIR     <<  16) |(GPIO145_DIR     <<  17) |(GPIO146_DIR     <<  18) |(GPIO147_DIR     <<  19) |
     (GPIO148_DIR     <<  20) |(GPIO149_DIR     <<  21) |(GPIO150_DIR     <<  22) |(GPIO151_DIR     <<  23) |
     (GPIO152_DIR     <<  24) |(GPIO153_DIR     <<  25) |(GPIO154_DIR     << 26) |(GPIO155_DIR     << 27) |
     (GPIO156_DIR     << 28) |(GPIO157_DIR     << 29) |(GPIO158_DIR     << 30) |(GPIO159_DIR     << 31)),

	((GPIO160_DIR     <<  0) |(GPIO161_DIR     <<  1) |(GPIO162_DIR     <<  2) |(GPIO163_DIR     <<  3) |
     (GPIO164_DIR     <<  4) |(GPIO165_DIR     <<  5) |(GPIO166_DIR     <<  6) |(GPIO167_DIR     <<  7) |
     (GPIO168_DIR     <<  8) |(GPIO169_DIR     <<  9) |(GPIO170_DIR     << 10) |(GPIO171_DIR     << 11) |
     (GPIO172_DIR     << 12) |(GPIO173_DIR     << 13) |(GPIO174_DIR     << 14) |(GPIO175_DIR     << 15)|
	 (GPIO176_DIR     << 16) |(GPIO177_DIR    <<  17) |(GPIO178_DIR     <<  18) |(GPIO179_DIR   <<  19) |
     (GPIO180_DIR     << 20) |(GPIO181_DIR    <<  21) |(GPIO182_DIR     <<  22) |(GPIO183_DIR   <<  23) |
     (GPIO184_DIR     << 24) |(GPIO185_DIR    <<  25) |(GPIO186_DIR     << 26)  |(GPIO187_DIR   << 27) |
     (GPIO188_DIR     << 28) |(GPIO189_DIR     << 29) |(GPIO190_DIR     << 30)  |(GPIO191_DIR   << 31)),

	((GPIO192_DIR     <<  0) |(GPIO193_DIR     <<  1) |(GPIO194_DIR     <<  2) |(GPIO195_DIR     <<  3) |
     (GPIO196_DIR     <<  4) |(GPIO197_DIR     <<  5) |(GPIO198_DIR     <<  6) |(GPIO199_DIR     <<  7) |
     (GPIO200_DIR     <<  8) |(GPIO201_DIR     <<  9) |(GPIO202_DIR     << 10) |(GPIO203_DIR     << 11) ),

}; /*end of gpio_init_dir_data*/



UINT32 gpio_init_pullen[][2] = {

{
GPIO_BASE+0x0830
,(GPIO13_PULLEN << 0) | (GPIO14_PULLEN << 1)| (GPIO15_PULLEN << 2) | (GPIO16_PULLEN << 3)| (GPIO17_PULLEN << 4) |
(GPIO18_PULLEN << 5) | (GPIO19_PULLEN << 6)| (GPIO20_PULLEN << 7)| (GPIO21_PULLEN << 8) | (GPIO198_PULLEN << 9) |
(GPIO199_PULLEN << 10) | (GPIO200_PULLEN << 11) | (GPIO201_PULLEN << 12) | (GPIO202_PULLEN << 13) | (GPIO203_PULLEN << 14)
},

{
GPIO_BASE+0x0930
,(GPIO42_PULLEN << 0) | (GPIO43_PULLEN << 1)| (GPIO44_PULLEN << 2) | (GPIO45_PULLEN << 3)| (GPIO46_PULLEN << 4) |
(GPIO47_PULLEN << 5) | (GPIO48_PULLEN << 6)| (GPIO49_PULLEN << 7)| (GPIO50_PULLEN << 8) | (GPIO51_PULLEN << 9) |
(GPIO52_PULLEN << 10) | (GPIO53_PULLEN << 11) | (GPIO54_PULLEN << 12) | (GPIO55_PULLEN << 13) | (GPIO56_PULLEN << 14) |
(GPIO57_PULLEN << 15)| (GPIO58_PULLEN << 16) | (GPIO59_PULLEN << 17)| (GPIO60_PULLEN << 18) | (GPIO61_PULLEN << 19)|
(GPIO62_PULLEN << 20)| (GPIO63_PULLEN << 21)| (GPIO64_PULLEN << 22)| (GPIO0_PULLEN << 23)| (GPIO1_PULLEN << 24)|
(GPIO2_PULLEN << 25)| (GPIO3_PULLEN << 26)| (GPIO4_PULLEN << 27)
},

{
GPIO_BASE+0x0A30
,(GPIO65_PULLEN << 0) | (GPIO66_PULLEN << 1)| (GPIO67_PULLEN << 2) | (GPIO68_PULLEN << 3)| (GPIO69_PULLEN << 4) |
(GPIO70_PULLEN << 5) | (GPIO71_PULLEN << 6)| (GPIO72_PULLEN << 7)| (GPIO73_PULLEN << 8) | (GPIO5_PULLEN << 9) |
(GPIO6_PULLEN << 10) | (GPIO7_PULLEN << 11) | (GPIO8_PULLEN << 12) | (GPIO74_PULLEN << 13) | (GPIO75_PULLEN << 14) |
(GPIO76_PULLEN << 15)| (GPIO77_PULLEN << 16) | (GPIO78_PULLEN << 17)| (GPIO79_PULLEN << 18) | (GPIO80_PULLEN << 19)|
(GPIO9_PULLEN << 20)| (GPIO10_PULLEN << 21)| (GPIO11_PULLEN << 22)| (GPIO12_PULLEN << 23)| (GPIO81_PULLEN << 24)|
(GPIO82_PULLEN << 25)| (GPIO83_PULLEN << 26)| (GPIO84_PULLEN << 27)| (GPIO85_PULLEN << 28)|(GPIO86_PULLEN << 29)|
(GPIO87_PULLEN << 30)| (GPIO88_PULLEN << 31)
},

{
GPIO_BASE+0x0A40
,(GPIO89_PULLEN << 0) | (GPIO90_PULLEN << 1)| (GPIO91_PULLEN << 2) | (GPIO92_PULLEN << 3)| (GPIO93_PULLEN << 4) |
(GPIO94_PULLEN << 5) | (GPIO95_PULLEN << 6)| (GPIO96_PULLEN << 7)| (GPIO97_PULLEN << 8) | (GPIO98_PULLEN << 9) |
(GPIO99_PULLEN << 10) | (GPIO100_PULLEN << 11) | (GPIO101_PULLEN << 12) | (GPIO102_PULLEN << 13) | (GPIO103_PULLEN << 14) |
(GPIO104_PULLEN << 15)| (GPIO105_PULLEN << 16) | (GPIO106_PULLEN << 17)| (GPIO107_PULLEN << 18) | (GPIO108_PULLEN << 19)|
(GPIO109_PULLEN << 20)| (GPIO110_PULLEN << 21)| (GPIO111_PULLEN << 22)| (GPIO112_PULLEN << 23)| (GPIO113_PULLEN << 24)|
(GPIO114_PULLEN << 25)
},

{
GPIO_BASE+0x0B30
,(GPIO118_PULLEN << 0) | (GPIO119_PULLEN << 1)| (GPIO120_PULLEN << 2) | (GPIO21_PULLEN << 3)| (GPIO122_PULLEN << 4) |
(GPIO123_PULLEN << 5) | (GPIO124_PULLEN << 6)| (GPIO125_PULLEN << 7)| (GPIO126_PULLEN << 8) | (GPIO127_PULLEN << 9) |
(GPIO128_PULLEN << 10) | (GPIO129_PULLEN << 11) | (GPIO130_PULLEN << 12) | (GPIO131_PULLEN << 13) | (GPIO132_PULLEN << 14) |
(GPIO133_PULLEN << 15)| (GPIO134_PULLEN << 16) | (GPIO135_PULLEN << 17)| (GPIO136_PULLEN << 18) | (GPIO137_PULLEN << 19)|
(GPIO138_PULLEN << 20)| (GPIO139_PULLEN << 21)| (GPIO140_PULLEN << 22)| (GPIO141_PULLEN << 23)| (GPIO142_PULLEN << 24)|
(GPIO143_PULLEN << 25)| (GPIO144_PULLEN << 26)| (GPIO145_PULLEN << 27)| (GPIO146_PULLEN << 28)|(GPIO147_PULLEN << 29)|
(GPIO148_PULLEN << 30)| (GPIO149_PULLEN << 31)
},

{
GPIO_BASE+0x0C30
,(GPIO160_PULLEN << 0) | (GPIO161_PULLEN << 1)| (GPIO162_PULLEN << 2) | (GPIO163_PULLEN << 3)| (GPIO164_PULLEN << 4) |
(GPIO165_PULLEN << 5) | (GPIO166_PULLEN << 6)| (GPIO167_PULLEN << 7)| (GPIO168_PULLEN << 8) | (GPIO169_PULLEN << 9) |
(GPIO170_PULLEN << 10) | (GPIO171_PULLEN << 11)
},

{
GPIO_BASE+0x0D30
,(GPIO172_PULLEN << 0) | (GPIO173_PULLEN << 1)| (GPIO174_PULLEN << 2) | (GPIO175_PULLEN << 3)| (GPIO176_PULLEN << 4) |
(GPIO177_PULLEN << 5) | (GPIO178_PULLEN << 6)| (GPIO179_PULLEN << 7)| (GPIO180_PULLEN << 8) | (GPIO181_PULLEN << 9) |
(GPIO182_PULLEN << 10) | (GPIO183_PULLEN << 11) | (GPIO184_PULLEN << 12) | (GPIO185_PULLEN << 13) | (GPIO186_PULLEN << 14) |
(GPIO187_PULLEN << 15)| (GPIO188_PULLEN << 16) | (GPIO189_PULLEN << 17)

}
};

/////new spec
UINT32 gpio_init_pullsel[][2] = {

{
GPIO_BASE+0x0850
,(GPIO13_PULL << 0) | (GPIO14_PULL << 1)| (GPIO15_PULL << 2) | (GPIO16_PULL << 3)| (GPIO17_PULL << 4) |
(GPIO18_PULL << 5) | (GPIO19_PULL << 6)| (GPIO20_PULL << 7)| (GPIO21_PULL << 8)
},

{
GPIO_BASE+0x0950
,(GPIO42_PULL << 0) | (GPIO43_PULL << 1)| (GPIO44_PULL << 2) | (GPIO_PULL_NA << 3)| (GPIO_PULL_NA << 4) |
(GPIO47_PULL << 5) | (GPIO48_PULL << 6)| (GPIO49_PULL << 7)| (GPIO50_PULL << 8) | (GPIO51_PULL << 9) |
(GPIO52_PULL << 10) | (GPIO53_PULL << 11) | (GPIO54_PULL << 12) | (GPIO55_PULL << 13) | (GPIO56_PULL << 14) |
(GPIO57_PULL << 15)| (GPIO58_PULL << 16) | (GPIO59_PULL << 17)| (GPIO60_PULL << 18) | (GPIO61_PULL << 19)|
(GPIO62_PULL << 20)| (GPIO63_PULL << 21)| (GPIO64_PULL << 22)| (GPIO0_PULL << 23)| (GPIO1_PULL << 24)|
(GPIO2_PULL << 25)| (GPIO3_PULL << 26)| (GPIO4_PULL << 27)
},

{
GPIO_BASE+0x0A50
,(GPIO65_PULL << 0) | (GPIO66_PULL << 1)| (GPIO67_PULL << 2) | (GPIO68_PULL << 3)| (GPIO69_PULL << 4) |
(GPIO70_PULL << 5) | (GPIO71_PULL << 6)| (GPIO72_PULL << 7)| (GPIO73_PULL << 8) | (GPIO5_PULL << 9) |
(GPIO6_PULL << 10) | (GPIO7_PULL << 11) | (GPIO8_PULL << 12) | (GPIO74_PULL << 13) | (GPIO75_PULL << 14) |
(GPIO76_PULL << 15)| (GPIO77_PULL << 16) | (GPIO78_PULL << 17)| (GPIO79_PULL << 18) | (GPIO80_PULL << 19)|
(GPIO9_PULL << 20)| (GPIO10_PULL << 21)| (GPIO11_PULL << 22)| (GPIO12_PULL << 23)| (GPIO_PULL_NA << 24)|
(GPIO_PULL_NA << 25)| (GPIO_PULL_NA << 26)| (GPIO_PULL_NA << 27)| (GPIO_PULL_NA << 28)|(GPIO_PULL_NA << 29)|
(GPIO87_PULL << 30)| (GPIO88_PULL << 31)
},

{
GPIO_BASE+0x0A60
,(GPIO89_PULL << 0) | (GPIO90_PULL << 1)| (GPIO91_PULL << 2) | (GPIO92_PULL << 3)| (GPIO93_PULL << 4) |
(GPIO94_PULL << 5) | (GPIO95_PULL << 6)| (GPIO96_PULL << 7)| (GPIO97_PULL << 8) | (GPIO98_PULL << 9) |
(GPIO99_PULL << 10) | (GPIO100_PULL << 11) | (GPIO101_PULL << 12) | (GPIO102_PULL << 13) | (GPIO103_PULL << 14) |
(GPIO104_PULL << 15)| (GPIO105_PULL << 16) | (GPIO106_PULL << 17)| (GPIO107_PULL << 18) | (GPIO108_PULL << 19)|
(GPIO109_PULL << 20)| (GPIO110_PULL << 21)| (GPIO111_PULL << 22)| (GPIO112_PULL << 23)| (GPIO113_PULL << 24)|
(GPIO114_PULL << 25)
},

{
GPIO_BASE+0x0B50
,(GPIO118_PULL << 0) | (GPIO119_PULL << 1)| (GPIO120_PULL << 2) | (GPIO21_PULL << 3)| (GPIO122_PULL << 4) |
(GPIO123_PULL << 5) | (GPIO124_PULL << 6)| (GPIO125_PULL << 7)| (GPIO126_PULL << 8) | (GPIO127_PULL << 9) |
(GPIO128_PULL << 10) | (GPIO129_PULL << 11) | (GPIO130_PULL << 12) | (GPIO131_PULL << 13) | (GPIO132_PULL << 14) |
(GPIO133_PULL << 15)| (GPIO134_PULL << 16) | (GPIO135_PULL << 17)| (GPIO136_PULL << 18) | (GPIO137_PULL << 19)|
(GPIO138_PULL << 20)| (GPIO139_PULL << 21)| (GPIO140_PULL << 22)| (GPIO141_PULL << 23)| (GPIO142_PULL << 24)|
(GPIO143_PULL << 25)| (GPIO144_PULL << 26)| (GPIO145_PULL << 27)| (GPIO146_PULL << 28)|(GPIO147_PULL << 29)|
(GPIO148_PULL << 30)| (GPIO149_PULL << 31)
},

{
GPIO_BASE+0x0D50
,(GPIO_PULL_NA << 0) | (GPIO_PULL_NA << 1)| (GPIO_PULL_NA << 2) | (GPIO_PULL_NA << 3)| (GPIO_PULL_NA << 4) |
(GPIO_PULL_NA << 5) | (GPIO_PULL_NA << 6)| (GPIO_PULL_NA << 7)| (GPIO_PULL_NA << 8) | (GPIO_PULL_NA << 9) |
(GPIO_PULL_NA << 10) | (GPIO_PULL_NA << 11) | (GPIO184_PULL << 12)| (GPIO185_PULL << 13)| (GPIO186_PULL << 14)|
(GPIO187_PULL << 15)| (GPIO188_PULL << 16)| (GPIO189_PULL << 17)

},

};



u32 gpio_init_dout_data[] = {
    ((GPIO0_DATAOUT       <<  0) |(GPIO1_DATAOUT       <<  1) |(GPIO2_DATAOUT       <<  2) |(GPIO3_DATAOUT       <<  3) |
     (GPIO4_DATAOUT       <<  4) |(GPIO5_DATAOUT       <<  5) |(GPIO6_DATAOUT       <<  6) |(GPIO7_DATAOUT       <<  7) |
     (GPIO8_DATAOUT       <<  8) |(GPIO9_DATAOUT       <<  9) |(GPIO10_DATAOUT      << 10) |(GPIO11_DATAOUT      << 11) |
     (GPIO12_DATAOUT      << 12) |(GPIO13_DATAOUT      << 13) |(GPIO14_DATAOUT      << 14) |(GPIO15_DATAOUT      << 15) |
     (GPIO16_DATAOUT      << 16) |(GPIO17_DATAOUT      << 17) |(GPIO18_DATAOUT      << 18) |(GPIO19_DATAOUT      << 19) |
     (GPIO20_DATAOUT      << 20) |(GPIO21_DATAOUT      << 21) |(GPIO22_DATAOUT      << 22) |(GPIO23_DATAOUT      << 23) |
     (GPIO24_DATAOUT      << 24) |(GPIO25_DATAOUT      << 25) |(GPIO26_DATAOUT      << 26) |(GPIO27_DATAOUT      << 27) |
     (GPIO28_DATAOUT      << 28) |(GPIO29_DATAOUT      << 29) |(GPIO30_DATAOUT      << 30) |(GPIO31_DATAOUT      << 31)),

    ((GPIO32_DATAOUT      <<  0) |(GPIO33_DATAOUT      <<  1) |(GPIO34_DATAOUT      <<  2) |(GPIO35_DATAOUT      <<  3) |
     (GPIO36_DATAOUT      <<  4) |(GPIO37_DATAOUT      <<  5) |(GPIO38_DATAOUT      <<  6) |(GPIO39_DATAOUT      <<  7) |
     (GPIO40_DATAOUT      <<  8) |(GPIO41_DATAOUT      <<  9) |(GPIO42_DATAOUT      << 10) |(GPIO43_DATAOUT      << 11) |
     (GPIO44_DATAOUT      << 12) |(GPIO45_DATAOUT      << 13) |(GPIO46_DATAOUT      << 14) |(GPIO47_DATAOUT      << 15)|
     (GPIO48_DATAOUT      << 16) |(GPIO49_DATAOUT      << 17) |(GPIO50_DATAOUT      << 18) |(GPIO51_DATAOUT      << 19) |
     (GPIO52_DATAOUT      <<  20) |(GPIO53_DATAOUT      << 21) |(GPIO54_DATAOUT      << 22) |(GPIO55_DATAOUT      << 23) |
     (GPIO56_DATAOUT      <<  24) |(GPIO57_DATAOUT      <<  25) |(GPIO58_DATAOUT      << 26) |(GPIO59_DATAOUT      << 27) |
     (GPIO60_DATAOUT      << 28) |(GPIO61_DATAOUT      << 29) |(GPIO62_DATAOUT      << 30) |(GPIO63_DATAOUT      << 31)),

    ((GPIO64_DATAOUT      <<  0) |(GPIO65_DATAOUT      <<  1) |(GPIO66_DATAOUT      <<  2) |(GPIO67_DATAOUT      <<  3) |
     (GPIO68_DATAOUT      <<  4) |(GPIO69_DATAOUT      <<  5) |(GPIO70_DATAOUT      <<  6) |(GPIO71_DATAOUT      <<  7) |
     (GPIO72_DATAOUT      <<  8) |(GPIO73_DATAOUT      <<  9) |(GPIO74_DATAOUT      << 10) |(GPIO75_DATAOUT      << 11) |
     (GPIO76_DATAOUT      << 12) |(GPIO77_DATAOUT      << 13) |(GPIO78_DATAOUT      << 14) |(GPIO79_DATAOUT      << 15)|
     (GPIO80_DATAOUT      <<  16) |(GPIO81_DATAOUT      << 17) |(GPIO82_DATAOUT      <<  18) |(GPIO83_DATAOUT    <<  19) |
     (GPIO84_DATAOUT      <<  20) |(GPIO85_DATAOUT      <<  21) |(GPIO86_DATAOUT      <<  22) |(GPIO87_DATAOUT   <<  23) |
     (GPIO88_DATAOUT      <<  24) |(GPIO89_DATAOUT      <<  25) |(GPIO90_DATAOUT      << 26) |(GPIO91_DATAOUT    << 27) |
     (GPIO92_DATAOUT      <<  28) |(GPIO93_DATAOUT      << 29) |(GPIO94_DATAOUT      << 30) |(GPIO95_DATAOUT     << 31)),

    ((GPIO96_DATAOUT      <<  0) |(GPIO97_DATAOUT      <<  1) |(GPIO98_DATAOUT      <<  2) |(GPIO99_DATAOUT      <<  3) |
     (GPIO100_DATAOUT     <<  4) |(GPIO101_DATAOUT     <<  5) |(GPIO102_DATAOUT     <<  6) |(GPIO103_DATAOUT     <<  7) |
     (GPIO104_DATAOUT     <<  8) |(GPIO105_DATAOUT     <<  9) |(GPIO106_DATAOUT     << 10) |(GPIO107_DATAOUT     << 11) |
     (GPIO108_DATAOUT     << 12) |(GPIO109_DATAOUT     << 13) |(GPIO110_DATAOUT     << 14) |(GPIO111_DATAOUT     << 15)|
     (GPIO112_DATAOUT     <<  16) |(GPIO113_DATAOUT     << 17) |(GPIO114_DATAOUT     << 18) |(GPIO115_DATAOUT     << 19) |
     (GPIO116_DATAOUT     <<  20) |(GPIO117_DATAOUT     <<  21) |(GPIO118_DATAOUT     <<  22) |(GPIO119_DATAOUT     <<  23) |
     (GPIO120_DATAOUT     <<  24) |(GPIO121_DATAOUT     <<  25) |(GPIO122_DATAOUT     << 26) |(GPIO123_DATAOUT     << 27) |
     (GPIO124_DATAOUT     << 28) |(GPIO125_DATAOUT     << 29) |(GPIO126_DATAOUT     << 30) |(GPIO127_DATAOUT     << 31)),

    ((GPIO128_DATAOUT     <<  0) |(GPIO129_DATAOUT     <<  1) |(GPIO130_DATAOUT     <<  2) |(GPIO131_DATAOUT     <<  3) |
     (GPIO132_DATAOUT     <<  4) |(GPIO133_DATAOUT     <<  5) |(GPIO134_DATAOUT     <<  6) |(GPIO135_DATAOUT     <<  7) |
     (GPIO136_DATAOUT     <<  8) |(GPIO137_DATAOUT     <<  9) |(GPIO138_DATAOUT     << 10) |(GPIO139_DATAOUT     << 11) |
     (GPIO140_DATAOUT     << 12) |(GPIO141_DATAOUT     << 13) |(GPIO142_DATAOUT     << 14) |(GPIO143_DATAOUT     << 15)|
     (GPIO144_DATAOUT     <<  16) |(GPIO145_DATAOUT     <<  17) |(GPIO146_DATAOUT     <<  18) |(GPIO147_DATAOUT     <<  19) |
     (GPIO148_DATAOUT     <<  20) |(GPIO149_DATAOUT     <<  21) |(GPIO150_DATAOUT     <<  22) |(GPIO151_DATAOUT     <<  23) |
     (GPIO152_DATAOUT     <<  24) |(GPIO153_DATAOUT     <<  25) |(GPIO154_DATAOUT     << 26) |(GPIO155_DATAOUT     << 27) |
     (GPIO156_DATAOUT     << 28) |(GPIO157_DATAOUT     << 29) |(GPIO158_DATAOUT     << 30) |(GPIO159_DATAOUT     << 31)),

	((GPIO160_DATAOUT     <<  0) |(GPIO161_DATAOUT     <<  1) |(GPIO162_DATAOUT     <<  2) |(GPIO163_DATAOUT     <<  3) |
     (GPIO164_DATAOUT     <<  4) |(GPIO165_DATAOUT     <<  5) |(GPIO166_DATAOUT     <<  6) |(GPIO167_DATAOUT     <<  7) |
     (GPIO168_DATAOUT     <<  8) |(GPIO169_DATAOUT     <<  9) |(GPIO170_DATAOUT     << 10) |(GPIO171_DATAOUT     << 11) |
     (GPIO172_DATAOUT     << 12) |(GPIO173_DATAOUT     << 13) |(GPIO174_DATAOUT     << 14) |(GPIO175_DATAOUT     << 15)|
	 (GPIO176_DATAOUT     <<  16) |(GPIO177_DATAOUT     <<  17) |(GPIO178_DATAOUT     <<  18) |(GPIO179_DATAOUT     <<  19) |
     (GPIO180_DATAOUT     <<  20) |(GPIO181_DATAOUT     <<  21) |(GPIO182_DATAOUT     <<  22) |(GPIO183_DATAOUT     <<  23) |
     (GPIO184_DATAOUT     <<  24) |(GPIO185_DATAOUT     <<  25) |(GPIO186_DATAOUT     << 26) |(GPIO187_DATAOUT     << 27) |
     (GPIO188_DATAOUT     << 28) |(GPIO189_DATAOUT     << 29) |(GPIO190_DATAOUT     << 30) |(GPIO191_DATAOUT     << 31)),

	((GPIO192_DATAOUT     <<  0) |(GPIO193_DATAOUT     <<  1) |(GPIO194_DATAOUT     <<  2) |(GPIO195_DATAOUT     <<  3) |
     (GPIO196_DATAOUT     <<  4) |(GPIO197_DATAOUT     <<  5) |(GPIO198_DATAOUT     <<  6) |(GPIO199_DATAOUT     <<  7) |
     (GPIO200_DATAOUT     <<  8) |(GPIO201_DATAOUT     <<  9) |(GPIO202_DATAOUT     << 10) |(GPIO203_DATAOUT     << 11) ),

}; /*end of gpio_init_dir_data*/


/*----------------------------------------------------------------------------*/
u32 gpio_init_mode_data[] = {
    ((GPIO0_MODE      <<  0) |(GPIO1_MODE      <<  3) |(GPIO2_MODE      <<  6) |(GPIO3_MODE      <<  9) |(GPIO4_MODE     << 12)|
     (GPIO5_MODE      << 16) |(GPIO6_MODE     << 19)  |(GPIO7_MODE      << 22) |(GPIO8_MODE      << 25) |(GPIO9_MODE      << 28)),

    ((GPIO10_MODE     <<  0) |(GPIO11_MODE     <<  3) |(GPIO12_MODE     <<  6) |(GPIO13_MODE     <<  9) |(GPIO14_MODE     << 12)|
     (GPIO15_MODE     <<  16) |(GPIO16_MODE     << 19) |(GPIO17_MODE     << 22) |(GPIO18_MODE     << 25) |(GPIO19_MODE     << 28)),

    ((GPIO20_MODE     <<  0) |(GPIO21_MODE     <<  3) |(GPIO22_MODE     <<  6) |(GPIO23_MODE     <<  9) |(GPIO24_MODE     << 12)|
     (GPIO25_MODE     << 16) |(GPIO26_MODE     << 19) |(GPIO27_MODE     << 22) |(GPIO28_MODE     << 25) |(GPIO29_MODE     << 28)),

    ((GPIO30_MODE     <<  0) |(GPIO31_MODE     <<  3) |(GPIO32_MODE     <<  6) |(GPIO33_MODE     <<  9) |(GPIO34_MODE     << 12)|
     (GPIO35_MODE     << 16) |(GPIO36_MODE     <<  19) |(GPIO37_MODE     << 22) |(GPIO38_MODE     << 25) |(GPIO39_MODE     << 28)),

    ((GPIO40_MODE     <<  0) |(GPIO41_MODE     <<  3) |(GPIO42_MODE     <<  6) |(GPIO43_MODE     <<  9) |(GPIO44_MODE     << 12)|
     (GPIO45_MODE     <<  16) |(GPIO46_MODE     <<  19) |(GPIO47_MODE     <<  22) |(GPIO48_MODE     <<  25) |(GPIO49_MODE     << 28)),

    ((GPIO50_MODE     <<  0) |(GPIO51_MODE     <<  3) |(GPIO52_MODE     <<  6) |(GPIO53_MODE     <<  9) |(GPIO54_MODE     << 12)|
    (GPIO55_MODE     <<  16) |(GPIO56_MODE     <<  19) |(GPIO57_MODE     <<  22) |(GPIO58_MODE     <<  25) |(GPIO59_MODE     << 28)),

    ((GPIO60_MODE     <<  0) |(GPIO61_MODE     <<  3) |(GPIO62_MODE     <<  6) |(GPIO63_MODE     <<  9) |(GPIO64_MODE     << 12)|
     (GPIO65_MODE     <<  16) |(GPIO66_MODE     <<  19) |(GPIO67_MODE     <<  22) |(GPIO68_MODE     <<  25) |(GPIO69_MODE     << 28)),

    ((GPIO70_MODE     <<  0) |(GPIO71_MODE     <<  3) |(GPIO72_MODE     <<  6) |(GPIO73_MODE     <<  9) |(GPIO74_MODE     << 12)|
     (GPIO75_MODE     <<  16) |(GPIO76_MODE     <<  19) |(GPIO77_MODE     <<  22) |(GPIO78_MODE     <<  25) |(GPIO79_MODE     << 28)),

    ((GPIO80_MODE     <<  0) |(GPIO81_MODE     <<  3) |(GPIO82_MODE     <<  6) |(GPIO83_MODE     <<  9) |(GPIO84_MODE     << 12)|
     (GPIO85_MODE     <<  16) |(GPIO86_MODE     <<  19) |(GPIO87_MODE     <<  22) |(GPIO88_MODE     <<  25) |(GPIO89_MODE     << 28)),

    ((GPIO90_MODE     <<  0) |(GPIO91_MODE     <<  3) |(GPIO92_MODE     <<  6) |(GPIO93_MODE     <<  9) |(GPIO94_MODE     << 12)|
     (GPIO95_MODE     <<  16) |(GPIO96_MODE     <<  19) |(GPIO97_MODE     <<  22) |(GPIO98_MODE     <<  25) |(GPIO99_MODE     << 28)),

    ((GPIO100_MODE    <<  0) |(GPIO101_MODE    <<  3) |(GPIO102_MODE    <<  6) |(GPIO103_MODE    <<  9) |(GPIO104_MODE    << 12)|
     (GPIO105_MODE    <<  16) |(GPIO106_MODE    <<  19) |(GPIO107_MODE    <<  22) |(GPIO108_MODE    <<  25) |(GPIO109_MODE    << 28)),

    ((GPIO110_MODE    <<  0) |(GPIO111_MODE    <<  3) |(GPIO112_MODE    <<  6) |(GPIO113_MODE    <<  9) |(GPIO114_MODE    << 12)|
     (GPIO115_MODE    <<  16) |(GPIO116_MODE    <<  19) |(GPIO117_MODE    <<  22) |(GPIO118_MODE    <<  25) |(GPIO119_MODE    << 28)),

    ((GPIO120_MODE    <<  0) |(GPIO121_MODE    <<  3) |(GPIO122_MODE    <<  6) |(GPIO123_MODE    <<  9) |(GPIO124_MODE    << 12)|
     (GPIO125_MODE    <<  16) |(GPIO126_MODE    <<  19) |(GPIO127_MODE    <<  22) |(GPIO128_MODE    <<  25) |(GPIO129_MODE    << 28)),

    ((GPIO130_MODE    <<  0) |(GPIO131_MODE    <<  3) |(GPIO132_MODE    <<  6) |(GPIO133_MODE    <<  9) |(GPIO134_MODE    << 12)|
     (GPIO135_MODE    <<  16) |(GPIO136_MODE    <<  19) |(GPIO137_MODE    <<  22) |(GPIO138_MODE    <<  25) |(GPIO139_MODE    << 28)),

    ((GPIO140_MODE    <<  0) |(GPIO141_MODE    <<  3) |(GPIO142_MODE    <<  6) |(GPIO143_MODE    <<  9) |(GPIO144_MODE    << 12)|
     (GPIO145_MODE    <<  16) |(GPIO146_MODE    <<  19) |(GPIO147_MODE    <<  22) |(GPIO148_MODE    <<  25) |(GPIO149_MODE    << 28)),

    ((GPIO150_MODE    <<  0) |(GPIO151_MODE    <<  3) |(GPIO152_MODE    <<  6) |(GPIO153_MODE    <<  9) |(GPIO154_MODE    << 12)|
     (GPIO155_MODE    <<  16) |(GPIO156_MODE    <<  19) |(GPIO157_MODE    <<  22) |(GPIO158_MODE    <<  25) |(GPIO159_MODE    << 28)),

    ((GPIO160_MODE    <<  0) |(GPIO161_MODE    <<  3) |(GPIO162_MODE    <<  6) |(GPIO163_MODE    <<  9) |(GPIO164_MODE    << 12)|
     (GPIO165_MODE    <<  16) |(GPIO166_MODE    <<  19) |(GPIO167_MODE    <<  22) |(GPIO168_MODE    <<  25) |(GPIO169_MODE    << 28)),

    ((GPIO170_MODE    <<  0) |(GPIO171_MODE    <<  3) |(GPIO172_MODE    <<  6) |(GPIO173_MODE    <<  9) |(GPIO174_MODE    << 12)|
     (GPIO175_MODE    <<  16) |(GPIO176_MODE    <<  19) |(GPIO177_MODE    <<  22) |(GPIO178_MODE    <<  25) |(GPIO179_MODE    << 28)),

    ((GPIO180_MODE    <<  0) |(GPIO181_MODE    <<  3) |(GPIO182_MODE    <<  6) |(GPIO183_MODE    <<  9) |(GPIO184_MODE    << 12)|
     (GPIO185_MODE    <<  16) |(GPIO186_MODE    <<  19) |(GPIO187_MODE    <<  22) |(GPIO188_MODE    <<  25) |(GPIO189_MODE    << 28)),

    ((GPIO190_MODE    <<  0) |(GPIO191_MODE    <<  3) |(GPIO192_MODE    <<  6) |(GPIO193_MODE    <<  9) |(GPIO194_MODE    << 12)|
     (GPIO195_MODE    <<  16) |(GPIO196_MODE    <<  19) |(GPIO197_MODE    <<  22) |(GPIO198_MODE    <<  25) |(GPIO199_MODE    << 28)),

    ((GPIO200_MODE    <<  0) |(GPIO201_MODE    <<  3) |(GPIO202_MODE    <<  6) |(GPIO203_MODE    <<  9) ),

}; /*end of gpio_init_mode_more_data*/


u16 gpio_init_smt_data[][2] = {

	 {GPIO_BASE+0x0810,
	 (GPIO_SMT_GROUP_4  <<  0) |(GPIO_SMT_GROUP_5  <<  1) |(GPIO_SMT_GROUP_42  <<  2) |(GPIO_SMT_GROUP_43  <<  3) |
	 (GPIO_SMT_GROUP_44  <<  4)  },

	 {GPIO_BASE+0x0910,
	 (GPIO_SMT_GROUP_6  <<  0) |(GPIO_SMT_GROUP_7  <<  1) |(GPIO_SMT_GROUP_8  <<  2) |(GPIO_SMT_GROUP_9  <<  3) |
	 (GPIO_SMT_GROUP_10  <<  4) |(GPIO_SMT_GROUP_11  <<  5)|(GPIO_SMT_GROUP_12  <<  6) |(GPIO_SMT_GROUP_13  <<  7)|
	 (GPIO_SMT_GROUP_14  <<  8)|(GPIO_SMT_GROUP_15  <<  9)|(GPIO_SMT_GROUP_1  <<  10)},

	 {GPIO_BASE+0x0A10,
	 (GPIO_SMT_GROUP_16  <<  0) |(GPIO_SMT_GROUP_17  <<  1) |(GPIO_SMT_GROUP_18  <<  2) |(GPIO_SMT_GROUP_2  <<  3) |
	 (GPIO_SMT_GROUP_19  <<  4) |(GPIO_SMT_GROUP_20  <<  5)|(GPIO_SMT_GROUP_3  <<  6) |(GPIO_SMT_GROUP_21  <<  7)|
	 (GPIO_SMT_GROUP_22  <<  8)|(GPIO_SMT_GROUP_23  <<  9)},

	  {GPIO_BASE+0x0B10,
	 (GPIO_SMT_GROUP_24  <<  0) |(GPIO_SMT_GROUP_25  <<  1) |(GPIO_SMT_GROUP_26  <<  2) |(GPIO_SMT_GROUP_27  <<  3) |
	 (GPIO_SMT_GROUP_28  <<  4) |(GPIO_SMT_GROUP_29  <<  5)},

	  {GPIO_BASE+0x0C10,
	 (GPIO_SMT_GROUP_30  <<  0) |(GPIO_SMT_GROUP_31  <<  1) |(GPIO_SMT_GROUP_32  <<  2) |(GPIO_SMT_GROUP_33  <<  3) |
	 (GPIO_SMT_GROUP_34  <<  4) },

	  {GPIO_BASE+0x0D10,
	 (GPIO_SMT_GROUP_35  <<  0) |(GPIO_SMT_GROUP_36  <<  1) |(GPIO_SMT_GROUP_37  <<  2) |(GPIO_SMT_GROUP_38  <<  3) |
	 (GPIO_SMT_GROUP_39  <<  4) |(GPIO_SMT_GROUP_40  <<  5) | (GPIO_SMT_GROUP_41  <<  6)},


}; /*end of gpio_init_smt_more_data*/
#endif
void gpio_dump_reg(void)
{
/*
	u32 idx;
	u32 val;

	GPIO_REGS *pReg = (GPIO_REGS*)(GPIO_BASE);

    for (idx = 0; idx < sizeof(pReg->mode)/sizeof(pReg->mode[0]); idx++) {
		GPIOVER("idx=[%d],mode_reg(%x)=%x \n",idx,&pReg->mode[idx],GPIO_RD32(&pReg->mode[idx]));
		//GPIOVER("mode[%d](rst%x,set%x) \n",idx,&pReg->mode[idx].rst,&pReg->mode[idx].set);
    }
    for (idx = 0; idx < sizeof(pReg->dir)/sizeof(pReg->dir[0]); idx++){
	 	GPIOVER("dir[%d]=%x \n",idx,&pReg->dir[idx]);
		//GPIOVER("dir[%d](rst%x,set%x) \n",idx,&pReg->dir[idx].rst,&pReg->dir[idx].set);
    }
	for (idx = 0; idx < sizeof(pReg->dout)/sizeof(pReg->dout[0]); idx++) {
		GPIOVER("dout[%d]=%x \n",idx,&pReg->dout[idx]);
		//GPIOVER("dout[%d](rst%x,set%x) \n",idx,&pReg->dout[idx].rst,&pReg->dout[idx].set);
    }
	for (idx = 0; idx < sizeof(pReg->din)/sizeof(pReg->din[0]); idx++) {
		GPIOVER("din[%d]=%x \n",idx,&pReg->din[idx]);
		//GPIOVER("din[%d](rst%x,set%x) \n",idx,&pReg->din[idx].rst,&pReg->din[idx].set);
    }
	*/
}
void gpio_dump(void)
{
	int i=0;
	/* int idx=0; */
	/* u32 val=0; */
    GPIOVER("fwq .... gpio dct config ++++++++++++++++++++++++++++\n");
/*
	for (idx = 0; idx < sizeof(gpio_init_dir_data)/(sizeof(UINT32)); idx++){
	    val = gpio_init_dir_data[idx];
		GPIOVER("gpio_init_dir_reg[%d],[0x%x]\n",idx,GPIO_RD32(GPIO_BASE+16*idx));

    }
*/
	for(i=0;i<MAX_GPIO_PIN;i++)
	{
	   //GPIOVER(" \n");
	   printf("g[%d]\n",i);
	   printf("g[%d], mode(%x)\n",i,mt_get_gpio_mode(0x80000000+i));
	   printf("g[%d], dir(%x)\n",i,mt_get_gpio_dir(0x80000000+i));
	   printf("g[%d], pull_en(%x)\n",i,mt_get_gpio_pull_enable(0x80000000+i));
	   printf("g[%d], pull_sel(%x)\n",i,mt_get_gpio_pull_select(0x80000000+i));
	   printf("g[%d], out(%x)\n",i,mt_get_gpio_out(0x80000000+i));
	   printf("g[%d], smt(%x)\n",i,mt_get_gpio_smt(0x80000000+i));
	  // GPIOVER("gpio[%d], ies(%x)\n",i,mt_get_gpio_ies(0x80000000+i));
	  // GPIOVER("gpio[%d], in(%x)\n",i,mt_get_gpio_in(0x80000000+i));


	}

	 GPIOVER("fwq .... gpio dct config ----------------------------\n");
}

void mt_gpio_set_default_dump(void)
{
      gpio_dump();
}

void mt_gpio_set_default_chip(void)
{
    /* u32 idx; */
   /*  u32 val; */


    /* GPIO_REGS *pReg = (GPIO_REGS*)(GPIO_BASE); */



	//GPIOVER("fwq .... gpio.................................. 6735 real ooooo\n");
	#ifdef SIMULATION
	//for debug
	memset(GPIO_BASE,0 ,4096);
	//end
    #endif

	unsigned pin = 0;
	for(pin = 0; pin < MT_GPIO_BASE_MAX; pin++)
	{
		/* set GPIOx_MODE*/
		mt_set_gpio_mode(0x80000000+pin ,gpio_array[pin].mode);

		/* set GPIOx_DIR*/
		mt_set_gpio_dir(0x80000000+pin ,gpio_array[pin].dir);
		//GPIOVER("fwq2..........\n");

		/* set GPIOx_PULLEN*/
		mt_set_gpio_pull_enable(0x80000000+pin ,gpio_array[pin].pullen);
		//GPIOVER("fwq3..........\n");

		/* set GPIOx_PULL*/
		mt_set_gpio_pull_select(0x80000000+pin ,gpio_array[pin].pull);

		/* set GPIOx_DATAOUT*/
		mt_set_gpio_out(0x80000000+pin ,gpio_array[pin].dataout);

		//GPIOVER("fwq5..........\n");
		/* set GPIO0_SMT */
		mt_set_gpio_smt(0x80000000+pin ,gpio_array[pin].smt);


		//GPIOVER("smt1-init %d\n",pin);
	}

	//set kpd driving workaround
	GPIO_WR32(0x10211A70,0x70000600);
	//gpio_dump();

    //GPIOVER("mt_gpio_set_default() done\n");
}
void mt_gpio_set_driving(void)
{
#if 0
    u32 val;
    u32 mask;

    /* [MT6571] for MD BSI request */
    mask = 0x3000;
    val = GPIO_RD32(IO_CFG_T_BASE+0xF0);
    val &= ~(mask);
    val |= (0x0000 & mask);
    GPIO_WR32(IO_CFG_T_BASE+0xF0, val);
    /* [MT6571] end */

    /* [MT6571] for desense request (AUD IO) */
    mask = 0x30;
    val = GPIO_RD32(IO_CFG_L_BASE+0xA0);
    val &= ~(mask);
    val |= (0x00 & mask);
    GPIO_WR32(IO_CFG_L_BASE+0xA0, val);
    /* [MT6571] end */
#endif
}
/*
void mt_gpio_set_power(void)
{
#if 0
    u32 val;

    val = GPIO_RD32(GPIO_BASE+0x510);

    if(((val & 0x100)>>8) == 1){
	GPIO_WR32(IO_CFG_L_BASE+0x48, 0x8000);
    }
    if(((val & 0x200)>>9) == 1){
	GPIO_WR32(IO_CFG_L_BASE+0x48, 0x10000);
    }
#endif
}
*/

void mt_gpio_set_power(u8 mc1_power,u8 mc2_power, u8 sim1_power, u8 sim2_power)
{

	u32 reg=0;
	if (mc1_power == GPIO_VIO28) {

		reg = GPIO_RD32(GPIO_BASE+0x0c28);
		reg |= 0xc30c000;
		GPIO_WR32(GPIO_BASE+0x0c28, reg);

 	}
	else
	{
		reg = GPIO_RD32(GPIO_BASE+0x0c28);
		reg &= ~(0x3ffff<<12);
		GPIO_WR32(GPIO_BASE+0x0c28, reg);
	}
	//MC2
	if (mc2_power == GPIO_VIO28) {

		reg = GPIO_RD32(GPIO_BASE+0x0828);
		reg |= 0xc30c0;
		GPIO_WR32(GPIO_BASE+0x0828, reg);
 	}
	else
	{
		reg = GPIO_RD32(GPIO_BASE+0x0828);
		reg &= ~(0x3ffff<<4);
		GPIO_WR32(GPIO_BASE+0x0828, reg);
	}
	//sim1
	if (sim1_power == GPIO_VIO28) {

		reg = GPIO_RD32(GPIO_BASE+0x0c28);
		reg |= (0x6000);
		GPIO_WR32(GPIO_BASE+0x0c28, reg);
 	}
	else
	{
	    reg = GPIO_RD32(GPIO_BASE+0x0c28);
		reg &= ~(0x3f<<6);
		GPIO_WR32(GPIO_BASE+0x0c28, reg);
	}
    //sim2
	if (sim2_power == GPIO_VIO28) {

		reg = GPIO_RD32(GPIO_BASE+0x0c28);
		reg |= 0x0c;
		GPIO_WR32(GPIO_BASE+0x0c28, reg);
 	}
	else
	{
	    reg = GPIO_RD32(GPIO_BASE+0x0c28);
		reg &= ~(0x3f);
		GPIO_WR32(GPIO_BASE+0x0c28, reg);
	}

}


void mt_gpio_set_avoid_leakage(void)
{
#if 0
#ifdef MTK_EMMC_SUPPORT
    GPIO_WR32(IO_CFG_B_BASE+0x58, 0x220000);
#endif
#endif
}

void mt_gpio_set_default(void)
{
	//mt_gpio_set_avoid_leakage();
	mt_gpio_set_default_chip();
	//mt_gpio_set_driving();
	mt_gpio_set_power(GPIO_DVDD28_MC1,GPIO_DVDD28_MC2,GPIO_DVDD28_SIM1,GPIO_DVDD28_SIM2);
	//mutex_init(&gpio_mutex);
	return;
}
/*----------------------------------------------------------------------------*/
//EXPORT_SYMBOL(mt_gpio_set_default);
/*----------------------------------------------------------------------------*/
#if 0
void mt_gpio_checkpoint_save(void)
{
#if defined(GPIO_INIT_DEBUG)
    GPIO_REGS *pReg = (GPIO_REGS*)(GPIO_BASE);
    GPIO_REGS *cur = &saved;
    int idx;

    memset(cur, 0x00, sizeof(*cur));
    for (idx = 0; idx < sizeof(pReg->dir)/sizeof(pReg->dir[0]); idx++)
        cur->dir[idx].val = GPIO_RD32(&pReg->dir[idx]);
    for (idx = 0; idx < sizeof(pReg->pullen)/sizeof(pReg->pullen[0]); idx++)
        cur->pullen[idx].val = GPIO_RD32(&pReg->pullen[idx]);
    for (idx = 0; idx < sizeof(pReg->pullsel)/sizeof(pReg->pullsel[0]); idx++)
        cur->pullsel[idx].val =GPIO_RD32(&pReg->pullsel[idx]);
/*    for (idx = 0; idx < sizeof(pReg->dinv)/sizeof(pReg->dinv[0]); idx++)
        cur->dinv[idx].val =GPIO_RD32(&pReg->dinv[idx]);*/
    for (idx = 0; idx < sizeof(pReg->dout)/sizeof(pReg->dout[0]); idx++)
        cur->dout[idx].val = GPIO_RD32(&pReg->dout[idx]);
    for (idx = 0; idx < sizeof(pReg->mode)/sizeof(pReg->mode[0]); idx++)
        cur->mode[idx].val = GPIO_RD32(&pReg->mode[idx]);
#endif
}
/*----------------------------------------------------------------------------*/
EXPORT_SYMBOL(mt_gpio_checkpoint_save);
/*----------------------------------------------------------------------------*/
void mt_gpio_dump_diff(GPIO_REGS* pre, GPIO_REGS* cur)
{
#if defined(GPIO_INIT_DEBUG)
    GPIO_REGS *pReg = (GPIO_REGS*)(GPIO_BASE);
    int idx;
    unsigned char* p = (unsigned char*)pre;
    unsigned char* q = (unsigned char*)cur;

    GPIOVER("------ dumping difference between %p and %p ------\n", pre, cur);
    for (idx = 0; idx < sizeof(pReg->dir)/sizeof(pReg->dir[0]); idx++) {
        if (pre->dir[idx].val != cur->dir[idx].val)
            GPIOVER("diff: dir[%2d]    : 0x%08X <=> 0x%08X\n", idx, pre->dir[idx].val, cur->dir[idx].val);
    }
    for (idx = 0; idx < sizeof(pReg->pullen)/sizeof(pReg->pullen[0]); idx++) {
        if (pre->pullen[idx].val != cur->pullen[idx].val)
            GPIOVER("diff: pullen[%2d] : 0x%08X <=> 0x%08X\n", idx, pre->pullen[idx].val, cur->pullen[idx].val);
    }
    for (idx = 0; idx < sizeof(pReg->pullsel)/sizeof(pReg->pullsel[0]); idx++) {
        if (pre->pullsel[idx].val != cur->pullsel[idx].val)
            GPIOVER("diff: pullsel[%2d]: 0x%08X <=> 0x%08X\n", idx, pre->pullsel[idx].val, cur->pullsel[idx].val);
    }
    for (idx = 0; idx < sizeof(pReg->dout)/sizeof(pReg->dout[0]); idx++) {
        if (pre->dout[idx].val != cur->dout[idx].val)
            GPIOVER("diff: dout[%2d]   : 0x%08X <=> 0x%08X\n", idx, pre->dout[idx].val, cur->dout[idx].val);
    }
    for (idx = 0; idx < sizeof(pReg->mode)/sizeof(pReg->mode[0]); idx++) {
        if (pre->mode[idx].val != cur->mode[idx].val)
            GPIOVER("diff: mode[%2d]   : 0x%08X <=> 0x%08X\n", idx, pre->mode[idx].val, cur->mode[idx].val);
    }

    for (idx = 0; idx < sizeof(*pre); idx++) {
        if (p[idx] != q[idx])
            GPIOVER("diff: raw[%2d]: 0x%02X <=> 0x%02X\n", idx, p[idx], q[idx]);
    }
    GPIOVER("memcmp(%p, %p, %d) = %d\n", p, q, sizeof(*pre), memcmp(p, q, sizeof(*pre)));
    GPIOVER("------ dumping difference end --------------------------------\n");
#endif
}
/*----------------------------------------------------------------------------*/
void mt_gpio_checkpoint_compare(void)
{
#if defined(GPIO_INIT_DEBUG)
    GPIO_REGS *pReg = (GPIO_REGS*)(GPIO_BASE);
    GPIO_REGS latest;
    GPIO_REGS *cur = &latest;
    int idx;

    memset(cur, 0x00, sizeof(*cur));
    for (idx = 0; idx < sizeof(pReg->dir)/sizeof(pReg->dir[0]); idx++)
        cur->dir[idx].val = GPIO_RD32(&pReg->dir[idx]);
    for (idx = 0; idx < sizeof(pReg->pullen)/sizeof(pReg->pullen[0]); idx++)
        cur->pullen[idx].val = GPIO_RD32(&pReg->pullen[idx]);
    for (idx = 0; idx < sizeof(pReg->pullsel)/sizeof(pReg->pullsel[0]); idx++)
        cur->pullsel[idx].val =GPIO_RD32(&pReg->pullsel[idx]);
/*    for (idx = 0; idx < sizeof(pReg->dinv)/sizeof(pReg->dinv[0]); idx++)
        cur->dinv[idx].val =GPIO_RD32(&pReg->dinv[idx]);*/
    for (idx = 0; idx < sizeof(pReg->dout)/sizeof(pReg->dout[0]); idx++)
        cur->dout[idx].val = GPIO_RD32(&pReg->dout[idx]);
    for (idx = 0; idx < sizeof(pReg->mode)/sizeof(pReg->mode[0]); idx++)
        cur->mode[idx].val = GPIO_RD32(&pReg->mode[idx]);

    //mt_gpio_dump_diff(&latest, &saved);
    //GPIODBG("memcmp(%p, %p, %d) = %d\n", &latest, &saved, sizeof(GPIO_REGS), memcmp(&latest, &saved, sizeof(GPIO_REGS)));
    if (memcmp(&latest, &saved, sizeof(GPIO_REGS))) {
        GPIODBG("checkpoint compare fail!!\n");
        GPIODBG("dump checkpoint....\n");
        //mt_gpio_dump(&saved);
        GPIODBG("\n\n");
        GPIODBG("dump current state\n");
        //mt_gpio_dump(&latest);
        GPIODBG("\n\n");
        mt_gpio_dump_diff(&saved, &latest);
        //WARN_ON(1);
    } else {
        GPIODBG("checkpoint compare success!!\n");
    }
#endif
}
/*----------------------------------------------------------------------------*/
EXPORT_SYMBOL(mt_gpio_checkpoint_compare);
/*----------------------------------------------------------------------------*/
#endif
#endif
