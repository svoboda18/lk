
/*=======================================================================*/
/* HEADER FILES                                                          */
/*=======================================================================*/
#include <debug.h>
#include <env.h>
#include <platform/mt_gpio.h>
#include <cust_gpio_usage.h>
#include <libfdt.h>
#include <upmu_hw.h>

void usb2jtag_hw_init(void)
{
	/* set ap_usb2jtag_en: 0x1000_0700 bit[13] = 1 */
	*(unsigned short *)0x10000700 |= (0x1 << 13);
	/* Set rg_usb_gpio_ctrl: 0x11210821 bit[1] = 1 */
	*(unsigned int *) 0x11210820 |= (0x1 << 9);
	/* clear RG_USB20_BC11_SW_EN: 0x1121081A bit[7] = 0 */
	*(unsigned int *) 0x11210818 |= (0x1 << 23);
	/* Set BGR_EN 0x11210800 bit[0] = 1 */
	*(unsigned int *) 0x11210800 |= (0x1 << 0);

	dprintf(CRITICAL,"[USB2JTAG] mt6735 usb2jtag_hw_init start()\n");
	dprintf(CRITICAL,"[USB2JTAG]&0x%x=0x%x\n",0x10000700,*(unsigned int *)0x10000700);
	dprintf(CRITICAL,"[USB2JTAG]&0x%x=0x%x\n",0x11210820,*(unsigned int *)0x11210820);
	dprintf(CRITICAL,"[USB2JTAG]&0x%x=0x%x\n",0x11210818,*(unsigned int *)0x11210818);
	dprintf(CRITICAL,"[USB2JTAG]&0x%x=0x%x\n",0x11210800,*(unsigned int *)0x11210800);
	dprintf(CRITICAL,"[USB2JTAG] usb2jtag_hw_init() done\n");
}


unsigned int get_usb2jtag(void)
{
	unsigned int ap_jtag_status;

	ap_jtag_status = (get_env("usb2jtag") == NULL) ? 0 : atoi(get_env("usb2jtag"));
	dprintf(CRITICAL,"[USB2JTAG] current setting is %d.\n", ap_jtag_status);
	return ap_jtag_status;
}

unsigned int set_usb2jtag(unsigned int en)
{
	char *USB2JTAG[2] = {"0","1"};

	dprintf(CRITICAL,"[USB2JTAG] current setting is %d.\n",(get_env("usb2jtag") == NULL) ? 0 : atoi(get_env("usb2jtag")));
	if (set_env("usb2jtag", USB2JTAG[en]) == 0) {
		dprintf(CRITICAL,"[USB2JTAG]set USB2JTAG %s success.\n",USB2JTAG[en]);
		return 0;
	} else {
		dprintf(CRITICAL,"[USB2JTAG]set USB2JTAG %s fail.\n",USB2JTAG[en]);
		return 1;
	}
}

void usb2jtag_init(void)
{
	if (get_usb2jtag() == 1)
		usb2jtag_hw_init();
}
