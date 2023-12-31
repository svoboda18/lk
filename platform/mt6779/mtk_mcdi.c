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

#include <string.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <dev/aee_platform_debug.h>
#include "mtk_secure_api.h"
#include <mtk_mcdi.h>

#ifdef CPC_MODE

static void mcdi_get_cpc_info(void)
{
	memcpy((void *)mcdi_sram_cpc_info, (const void *)cpc_wdt_latch_regs, CPC_LATCH_SIZE);

	/* Dump SPMC INFO */
	DRV_WriteReg32(MCDI_SRAM_REG(0x7A0), DRV_Reg32(MCUCFG_REG(0xA748)) & 0x03FF0000);
	DRV_WriteReg32(MCDI_SRAM_REG(0x7A4), DRV_Reg32(MCUCFG_REG(0xA718)) & 0x00FFFFFF);
	DRV_WriteReg32(MCDI_SRAM_REG(0x7A8), DRV_Reg32(MCUCFG_REG(0x0214)) & 0x000003FF);
	DRV_WriteReg32(MCDI_SRAM_REG(0x7AC), DRV_Reg32(MCUCFG_REG(0x0A14)) & 0x000003FF);
	DRV_WriteReg32(MCDI_SRAM_REG(0x7B0), DRV_Reg32(MCUCFG_REG(0x1214)) & 0x000003FF);
	DRV_WriteReg32(MCDI_SRAM_REG(0x7B4), DRV_Reg32(MCUCFG_REG(0x1A14)) & 0x000003FF);
	DRV_WriteReg32(MCDI_SRAM_REG(0x7B8), DRV_Reg32(MCUCFG_REG(0x2214)) & 0x000003FF);
	DRV_WriteReg32(MCDI_SRAM_REG(0x7BC), DRV_Reg32(MCUCFG_REG(0x2A14)) & 0x000003FF);

	mt_secure_call(MTK_SIP_KERNEL_MCDI_ARGS, MCDI_SMC_EVENT_DUMP_TRACE_DATA, 0, 0, 0);
}

#else

static void mcdi_get_cpc_info(void) {}

#endif

void mcdi_setup_file_info_for_kedump(void)
{
	struct aee_db_file_info *ptr;
	const char filename[] = "SYS_MCDI_DATA";
	int max_size = sizeof(ptr[AEE_PLAT_MCDI_DATA].filename) - 1;

	ptr = get_file_info();

	if (!ptr)
		return;

	strncpy(ptr[AEE_PLAT_MCDI_DATA].filename,
			filename,
			max_size);
	ptr[AEE_PLAT_MCDI_DATA].filename[max_size] = '\0';

	ptr[AEE_PLAT_MCDI_DATA].filesize = MCDI_SRAM_LENGTH;

	mcdi_get_cpc_info();
}

