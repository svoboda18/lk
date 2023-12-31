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


#define GPIO_163	(0x80000000 | 163)
#define GPIO_164	(0x80000000 | 164)
#define GPIO_HIGH	(1)
#define GPIO_LOW	(0)

/******************************************************************************
* NOTE: This function is for the internal projects of MT6771.
*        -----------------------------------------
*       | GPIO_163    GPIO_164    PCB_ID          |
*       |   Low          Low      SEVB  (MTK0963) |
*       |   Low          High     Phone (MTK0891) |
*       |   High         Low      TBD             |
*       |   High         High     TBD             |
*        -----------------------------------------
*
*       Customers need to implement their own customized_get_odm_mdtbo_index()
*       function.
******************************************************************************/
int customized_get_odm_mdtbo_index(void)
{
	int idx = 0;
	S32 pin163 = mt_get_gpio_in(GPIO_163);
	S32 pin164 = mt_get_gpio_in(GPIO_164);

	dprintf(INFO, "pin163 = %d, pin164 = %d\n", pin163, pin164);

	if (pin163 == GPIO_HIGH) {
		if (pin164 == GPIO_HIGH) {
			// idx = 3;
			dprintf(INFO, "Error: PCB_ID: Unknown, dtb idx = %d\n", idx);
		} else {
			idx = 2;
			dprintf(INFO, "Error: PCB_ID: Unknown, dtb idx = %d\n", idx);
		}
	} else {
		if (pin164 == GPIO_HIGH) {
			idx = 1;
			dprintf(INFO, "PCB_ID: Phone (MTK0891), dtb idx = %d\n", idx);
		} else {
			idx = 0;
			dprintf(INFO, "PCB_ID: SEVB (MTK0963), dtb idx = %d\n", idx);
		}
	}

	return idx;
}

