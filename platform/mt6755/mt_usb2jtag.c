/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2015. All rights reserved.
*
* BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*/

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
	unsigned int ret = 0;
#if defined(PMIC_CHIP_MT6353)
	ret = pmic_set_register_value(PMIC_LDO_VUSB33_EN, 0x01);
#else
	ret |= pmic_set_register_value(MT6351_PMIC_RG_VUSB33_EN, 0x01);
	ret |= pmic_set_register_value(MT6351_PMIC_RG_VA10_EN, 0x01);
	ret |= pmic_set_register_value(MT6351_PMIC_RG_VA10_VOSEL, 0x02);
#endif
	if(ret){
        	dprintf(INFO,"[USB2JTAG] USB2JTAGE Voltage config failed\n");
		ASSERT(0);
	}

	*(unsigned short *)(INFRACFG_AO_BASE + 0xF00) |=0x4000;
	*(unsigned int *) (USB3_SIF2_BASE + 0x818) = 0x00100488;
	*(unsigned int *) (USB3_SIF2_BASE + 0x800) = 0x6F;
	*(unsigned int *) (USB3_SIF2_BASE + 0x808) = 0x0;
	*(unsigned int *) (USB3_SIF2_BASE + 0x820) = 0x0000FF1A;

	dprintf(INFO,"[USB2JTAG] Jade usb2jtag_hw_init done\n");
}


unsigned int get_usb2jtag(void)
{
	unsigned int ap_jtag_status;

	ap_jtag_status = (get_env("usb2jtag") == NULL) ? 0 : atoi(get_env("usb2jtag"));
	dprintf(INFO,"[USB2JTAG] current setting is %d.\n", ap_jtag_status);
	return ap_jtag_status;
}

unsigned int set_usb2jtag(unsigned int en)
{
	char *USB2JTAG = (en == 1) ? "1" : "0";

	dprintf(INFO,"[USB2JTAG] current setting is %d.\n",(get_env("usb2jtag") == NULL) ? 0 : atoi(get_env("usb2jtag")));

	if (set_env("usb2jtag", USB2JTAG) == 0){
	    dprintf(INFO,"[USB2JTAG]set USB2JTAG %s success.\n",USB2JTAG);
	    return 0;
	}
	else{
	    dprintf(INFO,"[USB2JTAG]set USB2JTAG %s fail.\n",USB2JTAG);
	    return 1;
	}

}


void usb2jtag_init(void)
{
	if(get_usb2jtag() == 1){
		usb2jtag_hw_init();
        }
	return;
}


