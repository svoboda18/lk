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

#include <platform/mt_typedefs.h>
#include <platform/errno.h>
#include <platform/partition.h>
#include <platform/boot_mode.h>
#include <platform/mt_gpt.h>
#include <platform/sec_policy.h>
#include <platform/mtk_wdt.h>
#include <platform/verified_boot.h>
#include <block_generic_interface.h>
#include <part_interface.h>
#include <malloc.h>
#include <dev/aee_platform_debug.h>
#include <mtk_mcdi.h>
#include <debug.h>
#include <string.h>
#include <assert.h>
#include <verified_boot_common.h>
#include <arch/ops.h>

#ifdef MTK_AB_OTA_UPDATER
#include <mt_boot.h>
#endif

#define MCUPM_MEM_SIZE   0x00010000  /* 64K */
#define MCUPM_MEM_ALIGN  0x00010000  /* 64K (minimal size for EMI MPU) */
#define MCUPM_MEM_LIMIT  0x78000000

/* mcdi smc call id */
/*Refernce from MTK_SIP_KERNEL_MCUPM_ARGS_AARCH32 */
#define MTK_SIP_KERNEL_MCUPM_ARGS 0x82000233
/* mcdi smc call event id */
#define MCDI_ARGS_MCUPMFW_INIT 0

static u64 mcupmfw_base_addr = 0;

void mcdi_setup_file_info_for_kedump(void)
{
	struct aee_db_file_info *ptr;
	const char filename[] = "SYS_MCDI_DATA";

	ptr = get_file_info();

	if (!ptr)
		return;

	strncpy(ptr[AEE_PLAT_MCDI_DATA].filename, filename, sizeof(filename));
	ptr[AEE_PLAT_MCDI_DATA].filesize = MCDI_SRAM_LENGTH;
}

#ifdef MCUPM_FW_USE_PARTITION
int mcdi_load_mcupm(void)
{
	int ret, fw_size;
#ifdef MTK_SECURITY_SW_SUPPORT
	unsigned int img_auth_required = 0;
	unsigned int policy_entry_idx = 0;
	unsigned int img_vfy_time = 0;
	u32 sec_ret = 0;
#endif
	char part_name[16] = "mcupmfw";

#ifdef MTK_AB_OTA_UPDATER
	get_AB_OTA_name((char *)&part_name, sizeof(part_name));
#endif /* MTK_AB_OTA_UPDATER */

	/* reserved a memory for mcupm fw */
	mcupmfw_base_addr = mblock_reserve_ext(&g_boot_arg->mblock_info, MCUPM_MEM_SIZE,
						MCUPM_MEM_ALIGN, MCUPM_MEM_LIMIT, 0, "MCUPM-reserved");

	dprintf(INFO, "[mcdi] addr=0x%llx size=0x%x\n", mcupmfw_base_addr, MCUPM_MEM_SIZE);

	if (mcupmfw_base_addr == 0)
		goto error;

#ifdef MTK_SECURITY_SW_SUPPORT
	img_vfy_time = get_timer(0);
	policy_entry_idx = get_policy_entry_idx("mcupmfw");
	img_auth_required = get_vfy_policy(policy_entry_idx);
	if (img_auth_required) {
		mtk_wdt_restart();
		sec_ret = sec_img_auth_init("mcupmfw", "mcupmfw", 0);
		if (sec_ret) {
			dprintf(CRITICAL, "mcupmfw cert vfy fail...(0x%x)\n", sec_ret);
			red_state_warning("mcupmfw");
			assert(0);
		}
		dprintf(INFO, "[SBC] mcupmfw cert vfy(%d ms)\n", (unsigned int)get_timer(img_vfy_time));

#ifdef MTK_SECURITY_ANTI_ROLLBACK
		sec_ret = sec_rollback_check(1);
		if (sec_ret) {
			dprintf(CRITICAL, "mcupmfw ver check fail...(0x%x)\n", sec_ret);
			assert(0);
		}
#endif
	}
#endif

	ret = mboot_common_load_part(part_name, "mcupmfw", mcupmfw_base_addr);
	if (ret < 0) {
		dprintf(CRITICAL, "[mcdi] load mcupmfw fail, ret = %d\n", ret);
		goto error;
	}
	fw_size = ret;
	dprintf(INFO, "[mcdi] image size = %d\n", fw_size);

	/* ensure image content coherence in DRAM */
	arch_sync_cache_range((addr_t)mcupmfw_base_addr, MCUPM_MEM_SIZE);

#ifdef MTK_SECURITY_SW_SUPPORT
	if (img_auth_required) {
		mtk_wdt_restart();
		img_vfy_time = get_timer(0);
		sec_ret = sec_img_auth((unsigned char *)(intptr_t)mcupmfw_base_addr, fw_size);
		if (sec_ret) {
			dprintf(CRITICAL, "imag mcupmfw vfy fail...(0x%x)\n", sec_ret);
			assert(0);
		}
		dprintf(INFO, "[SBC] mcupmfw img vfy(%d ms)\n", (unsigned int)get_timer(img_vfy_time));
	} else
		dprintf(CRITICAL, "[SBC] mcupmfw img vfy disabled\n");
#endif

	dprintf(INFO, "[mcdi] before smc call\n");
	mt_secure_call(MTK_SIP_KERNEL_MCUPM_ARGS, MCDI_ARGS_MCUPMFW_INIT, mcupmfw_base_addr, MCUPM_MEM_SIZE);
	dprintf(INFO, "[mcdi] after smc call\n");

	return 0;

error:
	return -1;
}
#endif

