/*
 * Copyright (c) 2015,  ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms,  with or without
 * modification,  are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice,  this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO,  THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR
 * CONSEQUENTIAL DAMAGES (INCLUDING,  BUT NOT LIMITED TO,  PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  DATA,  OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  WHETHER IN
 * CONTRACT,  STRICT LIABILITY,  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <reg.h>
#include <debug.h>
#include <platform/mt_typedefs.h>
#include <platform/sec_devinfo.h>
#include <platform/mt_ildo.h>
#include "mtk_secure_api.h"


#define mmio_write_32(addr, val) DRV_WriteReg32(addr, val)
#define mmio_read_32(addr) DRV_Reg32(addr)

#ifdef CONFIG_ARM64
#define MTK_SIP_LK_ILDO_READ_EFUSE      0xC20003D0
#else
#define MTK_SIP_LK_ILDO_READ_EFUSE      0x820003D0
#endif

/* fixme: correct efuse idx & number of efuse reg*/
#define DEVINFO_IDX_0 50    /* 0x580 */
#define DEVINFO_IDX_1 51    /* 0x580 */
#define DEVINFO_IDX_2 52    /* 0x580 */
#define DEVINFO_IDX_3 53    /* 0x580 */

#define ILDO_EFUSE_CNT 4

static const unsigned int ildo_efuse_idx[ILDO_EFUSE_CNT] = {
	DEVINFO_IDX_0,
	DEVINFO_IDX_1,
	DEVINFO_IDX_2,
	DEVINFO_IDX_3
};

static unsigned int ildo_efuse[ILDO_EFUSE_CNT];

//extern unsigned long mt_secure_call(unsigned long, unsigned long, unsigned long, unsigned long);

int ildo_init(void)
{
	int ret;

	dprintf(CRITICAL, "ildo_init() in lk\n");

#if ILDO_FUNC_ENABLE
	/* fixme: DCM bug workaround */
	/* FCM stall dcm bypass control (use QACTIVE instead of stalldcm active signal) */
	ildo_write_field(0x0C53C89C, 20:13, 0xC0);
	/* bigCPU local stall dcm disable */
	ildo_write_field(0x0C533230, 0:0, 0);
	/* bigCPU local stall dcm disable */
	ildo_write_field(0x0C533A30, 0:0, 0);
	/* set mux for CPU 7 to use ARMPLL_BB */
	DRV_WriteReg32(0x0C53AD00, 0x1);
#endif

	for (int i = 0; i < ILDO_EFUSE_CNT; i++) {
		/* fixme: correct efuse idx & number of efuse reg*/
		/* ildo_efuse[i] = get_devinfo_with_index(ildo_efuse_idx[i]); */
		ildo_efuse[i] = 0;
		dprintf(INFO, "ildo_efuse[%d] = 0x%08X\n", i, ildo_efuse[i]);
		ret = mt_secure_call(MTK_SIP_LK_ILDO_READ_EFUSE, i, ildo_efuse[i], 0, 0);
		if (ret != 0)
			dprintf(CRITICAL, "LK smc call MTK_SIP_LK_ILDO_READ_EFUSE error: id = %d\n", i);
	}

	return 0;
}

