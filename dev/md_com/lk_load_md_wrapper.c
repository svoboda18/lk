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

#include <sys/types.h>
#include <stdint.h>
#ifdef MTK_GPT_SCHEME_SUPPORT
#include <platform/partition.h>
#else
#include <mt_partition.h>
#endif
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>
#include <libfdt.h>

#include "lk_load_md_wrapper.h"


/******************************************************************************
* NOTE: Customers need to implement their own customized_get_rf_id()
*       function. If customized_get_rf_id() is not implemented, the
*       value 0x0F0F0F0F will be used as the default. Each customer can
*       maintain their own implementation of customized_get_rf_id()
*       in a separate source file as long as it can be linked.
******************************************************************************/
static unsigned int get_md_rf_id(void)
{
	unsigned int prop_val = 0x0F0F0F0F;

	if (customized_get_rf_id)
		prop_val = customized_get_rf_id();

	return prop_val;
}


/******************************************************************************
* NOTE: Customers need to implement their own customized_get_model_id()
*       function. If customized_get_model_id() is not implemented, the
*       value 0x0F0F0F0F will be used as the default. Each customer can
*       maintain their own implementation of customized_get_model_id()
*       in a separate source file as long as it can be linked.
******************************************************************************/
static unsigned int get_md_model_id(void)
{
	unsigned int prop_val = 0x0F0F0F0F;

	if (customized_get_model_id)
		prop_val = customized_get_model_id();

	return prop_val;
}


/******************************************************************************
* NOTE: Customers need to implement their own customized_get_RAT_id()
*       function. If customized_get_RAT_id() is not implemented, the
*       value -1 will be used as the default. Each customer can
*       maintain their own implementation of customized_get_RAT_id()
*       in a separate source file as long as it can be linked.
******************************************************************************/
int get_cust_tel_mode_idx(void)
{
	if (customized_get_RAT_id)
		return (int)customized_get_RAT_id();
	else {
		dprintf(CRITICAL, "Using defalut RAT all in one\n");
		return -1;
	}
}


void ccci_create_MD_attr_dt_node(void *fdt)
{
	unsigned int prop_val = 0x0F0F0F0F; /*  no property set */
	int err, offset;
	char compatible[] = "mediatek,md_attr_node";

	offset = fdt_add_subnode(fdt, 0, "md_attr_node");
	if (offset < 0)
		return;

	err = fdt_setprop(fdt, offset, "compatible", compatible, sizeof(compatible));
	if (err)
		return;

	/* For RF ID ++++++++++ */
	prop_val = get_md_rf_id();
	err = fdt_setprop_u32(fdt, offset, "mediatek,md_drdi_rf_set_idx", prop_val);
	if (err)
		return;
	/* For RF ID ---------- */

	/* For model ID ++++++++ */
	prop_val = get_md_model_id();
	err = fdt_setprop_u32(fdt, offset, "mediatek,md_product_name_model_id", prop_val);
	if (err)
		return;
	/* For model ID -------- */

}


int ccci_update_md_opt_to_fdt_firmware(void *fdt)
{
	if (update_md_opt_to_fdt_firmware)
		return update_md_opt_to_fdt_firmware(fdt);

	return 0;
}


void ccci_update_lk_arg_info_to_dt(char *buf, void *fdt, int offset)
{
	char *ptr;

	if (update_lk_arg_info_to_dt) {
		ptr = (char *)update_lk_arg_info_to_dt((unsigned int *)buf, fdt);
		if (fdt_setprop(fdt, offset, "ccci,modem_info_v2", buf, ptr - buf)) {
			assert(0);
			return;
		} else
			dprintf(CRITICAL, "[ccci] create modem arguments info DT OK\n");
	} else
		dprintf(CRITICAL, "[ccci] modem mem arguments info using default\n");
}

void ccci_load_modem_image(void)
{
	if (load_modem_image)
		load_modem_image();
	else
		dprintf(CRITICAL, "[ccci] using default loading method\n");
}
