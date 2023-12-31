/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2016. All rights reserved.
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

#include <stdint.h>
#include <string.h>
#include <debug.h>
#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#endif
#include <mt_gpio.h>
#include "cust_gpio_usage.h"

int platform_fdt_sspm(void *fdt)
{
#ifdef DEVICE_TREE_SUPPORT
	int nodeoffset;
	char *ret;
#ifdef USER_BUILD
	int len;
	uint32_t datalen;
	uint64_t *data;
	const struct fdt_property *prop;
	uint64_t ss, dbg_ss;
#endif

	nodeoffset = fdt_path_offset(fdt, "/reserved-memory/reserve-memory-sspm_share");

	if (nodeoffset >= 0) {
		ret = "okay";

		dprintf(CRITICAL, "SSPM: set reserved mem status=%s\n", ret);

		fdt_setprop(fdt, nodeoffset, "status", ret, strlen(ret));

#ifdef USER_BUILD
		prop = fdt_get_property(fdt, nodeoffset, "debug-only", &len);

		if (prop) {
			data = (uint64_t *)prop->data;
			dbg_ss = fdt64_to_cpu(*data);

			if (dbg_ss > 0) {
				prop = fdt_get_property(fdt, nodeoffset, "size", &len);

				if (prop) {

					data = (uint64_t *)prop->data;
					datalen = fdt32_to_cpu(prop->len);
					ss = fdt64_to_cpu(*data);

					ss -= dbg_ss;

					dprintf(DEBUG, "resize=0x%llx, len=0x%x\n", ss, datalen);

					ss = cpu_to_fdt64(ss);

					fdt_setprop_inplace(fdt, nodeoffset, "size", &ss, datalen);
				}
			} else {
				dprintf(CRITICAL, "SSPM: There are no reserved mem for debug purpose\n");
			}
		}
#endif

#ifdef MTK_TINYSYS_SSPM_GPIO_SUPPORT
		// TODO: set gpio mode

#endif

	} else {
		dprintf(CRITICAL, "SSPM: no reserved mem found, skip\n");
	}
#endif /* DEVICE_TREE_SUPPORT */

	return 0;
}
