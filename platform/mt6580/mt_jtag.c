
/*=======================================================================*/
/* HEADER FILES                                                          */
/*=======================================================================*/
#include <debug.h>
#include <env.h>
#include <platform/mt_gpio.h>
#include <cust_gpio_usage.h>
#include <libfdt.h>
void set_JTAG_GPIO(void)
{
	//switch MSDC GPIO to JTAG
	mt_set_gpio_mode(GPIO_MSDC1_CLK, GPIO_MSDC1_CLK_M_JTMS);
	mt_set_gpio_mode(GPIO_MSDC1_DAT2, GPIO_MSDC1_DAT2_M_JTDI);
	mt_set_gpio_mode(GPIO_MSDC1_DAT0, GPIO_MSDC1_DAT0_M_JTCK);
	mt_set_gpio_mode(GPIO_MSDC1_DAT3, GPIO_MSDC1_DAT3_M_JTDO);
}

unsigned int get_ap_jtag(void)
{
	unsigned int ap_jtag_status;

	ap_jtag_status = (get_env("apjtag") == NULL) ? 0 : atoi(get_env("apjtag"));
	dprintf(CRITICAL,"[APJTAG] current setting is %d.\n", ap_jtag_status);
	return ap_jtag_status;
}

unsigned int set_ap_jtag(unsigned int en)
{
	char *AP_JTAG[2] = {"0","1"};

	dprintf(CRITICAL,"[APJTAG] current setting is %d.\n",(get_env("apjtag") == NULL) ? 0 : atoi(get_env("apjtag")));
	if (set_env("apjtag", AP_JTAG[en]) == 0) {
		dprintf(CRITICAL,"[APJTAG]set AP JTAG %s success.\n",AP_JTAG[en]);
		set_JTAG_GPIO();
		return 0;
	} else {
		dprintf(CRITICAL,"[APJTAG]set AP JTAG %s fail.\n",AP_JTAG[en]);
		return 1;
	}

}

int target_fdt_jtag(void *fdt)
{
	int msdc_offset, msdc_node, last_node = -1;
	int len;
	const struct fdt_property *prop;
	const char *msdc_node_name[] = {
		"/mtk-msdc",
		"/mtk-msdc.0"
	};

	if (get_ap_jtag()) {
		/* to enable AP JTAG, remove MSDC1 node from DTB*/
		for (len = 0; len < (sizeof(msdc_node_name) / sizeof(*msdc_node_name)); len++) {
			msdc_offset = fdt_path_offset(fdt, msdc_node_name[len]);
			if (msdc_offset >= 0)
				break;
		}
		if (msdc_offset < 0) {
			dprintf(CRITICAL, "couldn't find /mtk-msdc\n");
			return msdc_offset;
		}

		for (msdc_node = fdt_first_subnode(fdt, msdc_offset); msdc_node >= 0;
		        msdc_node = ((last_node >= 0) ? fdt_next_subnode(fdt, last_node) : fdt_first_subnode(fdt, msdc_offset))) {
			prop = fdt_get_property(fdt, msdc_node, "compatible", &len);
			if ((!prop) || (len < 15) || (strcmp(prop->data, "mediatek,MSDC1"))) {
				last_node = msdc_node;
				continue;
			}
			fdt_del_node(fdt, msdc_node);
			dprintf(CRITICAL, "delete node mediatek,MSDC1\n");
		}
		//set JTAG GPIO
		set_JTAG_GPIO();
	}

	return 0;

}

