/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2017. All rights reserved.
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

#include <odm_mdtbo.h>                  // for customized_get_odm_mdtbo_index()
#include <platform/mt_gpio.h>		// for mt_get_gpio_in()


#define GPIO_111	(0x80000000 | 111)
#define GPIO_175	(0x80000000 | 175)
#define GPIO_HIGH	(1)
#define GPIO_LOW	(0)

/******************************************************************************
* NOTE: This function is for the internal projects of MT6771.
*        -----------------------------------------
*       | GPIO_111    GPIO_175    PCB_ID          |
*       |   Low          Low      EVB   (MTK0754) |
*       |   Low          High     Phone (MTK0719) |
*       |   High         Low      Phone (MTK0966) |
*       |   High         High     TBD             |
*        -----------------------------------------
*
*       Customers need to implement their own customized_get_odm_mdtbo_index()
*       function.
******************************************************************************/
int customized_get_odm_mdtbo_index(void)
{
	int idx = 0;
	S32 pin111 = mt_get_gpio_in(GPIO_111);
	S32 pin175 = mt_get_gpio_in(GPIO_175);

	dprintf(INFO, "pin111 = %d, pin175 = %d\n", pin111, pin175);

	if (pin111 == GPIO_HIGH) {
		if (pin175 == GPIO_HIGH) {
			// idx = 3;
			dprintf(INFO, "Error: PCB_ID: Unknown, dtb idx = %d\n", idx);
		} else {
			idx = 2;
			dprintf(INFO, "PCB_ID: Phone (MTK0966), dtb idx = %d\n", idx);
		}
	} else {
		if (pin175 == GPIO_HIGH) {
			idx = 1;
			dprintf(INFO, "PCB_ID: Phone (MTK0719), dtb idx = %d\n", idx);
		} else {
			idx = 0;
			dprintf(INFO, "PCB_ID: EVB (MTK0754), dtb idx = %d\n", idx);
		}
	}

	return idx;
}

