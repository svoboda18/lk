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
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/

#include <stdlib.h>
#include <string.h>
#include <arch/arm/mmu.h>
#include <arch/ops.h>
#include <platform/crypto_hw.h>
#include <platform/memory_layout.h>
#include <verified_boot_error.h>
#include <pal_typedefs.h>

uint32_t g_crypto_hw_initialized = 0;
uint32_t g_crypto_hw_disabled = 0;
CRYPTO_HW_SHARE_MEM *g_crypto = (CRYPTO_HW_SHARE_MEM *)LK_SECURE_BOOT_BASE;

extern uint32_t crypto_hw_init(uint32_t share_mem_addr, uint32_t share_mem_len);
extern uint32_t crypto_hw_disable(void);
extern uint32_t sha256atf_init(void);
extern uint32_t sha256atf_process(const uint8_t *in, unsigned long len);
extern uint32_t sha256atf_done(void);

/* crypto hw engine can only be accessed in secure world */
/* share memory address can only be passed into atf once, and associated smc calls will be disabled before leaving LK */
/* note: if multi-thread is enabled, a mutex must be held in a hash calculation session */

static uint32_t crypto_hw_engine_init()
{
	uint32_t ret = 0;

	if (g_crypto_hw_initialized == 1)
		return 0;

	arch_mmu_map(((uint64_t)LK_SECURE_BOOT_BASE) & 0xffffffff,
					(uint32_t)LK_SECURE_BOOT_BASE,
					MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
					LK_SECURE_BOOT_MAX_SIZE);

	ret = crypto_hw_init(LK_SECURE_BOOT_BASE, LK_SECURE_BOOT_MAX_SIZE);
	if (ret)
		return ret;

	g_crypto_hw_initialized = 1;

	return ret;
}

uint32_t crypto_hw_engine_disable()
{
	uint32_t ret = 0;
	if (g_crypto_hw_disabled == 1)
		return 0;

	ret = crypto_hw_disable();
	if (ret)
		return ret;

	g_crypto_hw_disabled = 1;

	return ret;
}

uint32_t sha256hw_init(void)
{
	uint32_t ret = 0;

	ret = crypto_hw_engine_init();
	if (ret)
		return ret;

	ret = sha256atf_init();
	if (ret)
		return ret;

	return ret;
}

uint32_t sha256hw_process(const uint8_t *in, unsigned long len)
{
	uint32_t ret = 0;

	if (in == NULL)
		return ERR_VB_INVALID_ADDR;

	arch_clean_invalidate_cache_range((addr_t)in, len);
	ret = sha256atf_process(in, len);
	if (ret)
		return ret;

	return ret;
}

uint32_t sha256hw_done(uint8_t *hash)
{
	uint32_t ret = 0;

	if (hash == NULL)
		return ERR_VB_INVALID_ADDR;

	memset(hash, 0x0, SHA256_HASH_SIZE);
	/* do not call crypto_hw_engine_deinit here, since it disables ATF crypto SMC permanently */
	arch_clean_invalidate_cache_range((addr_t)LK_SECURE_BOOT_BASE,
										LK_SECURE_BOOT_MAX_SIZE);
	ret = sha256atf_done();
	if (ret)
		return ret;

	memcpy(hash, g_crypto->hash, SHA256_HASH_SIZE);

	return ret;
}

/* padding is not handled currently, and alignment is fixed to 16 bytes */
uint32_t calc_hash_hw(uint8_t *buf, uint32_t buf_sz, uint32_t padding_sz, uint8_t *hash, uint32_t hash_sz)
{
	uint32_t ret = 0;
	uint32_t process_len = 0;

	if (hash_sz < SHA256_HASH_SIZE)
		return ERR_INVALID_HASH_SZ;

	if (padding_sz >= AES_BLK_SIZE)
		return ERR_INVALID_HASH_SZ;

	if ((NULL == hash) || (NULL == buf))
		return ERR_VB_INVALID_ADDR;

	memset(hash, 0x0, SHA256_HASH_SIZE);

	ret = sha256hw_init();
	if (ret) {
		dprintf(CRITICAL, "sha256hw_init fail, ret = 0x%x\n", ret);
		return ret;
	}

	process_len = (buf_sz / AES_BLK_SIZE) * AES_BLK_SIZE;
	ret = sha256hw_process(buf, process_len);
	if (ret) {
		dprintf(CRITICAL, "sha256hw_process fail, ret = 0x%x\n", ret);
		return ret;
	}

	/* note alignment != 0 does not indicate process_len == len */
	if (process_len != buf_sz) {
		memset(g_crypto->last_block, 0x0, AES_BLK_SIZE);
		memcpy(g_crypto->last_block, buf + process_len, buf_sz - process_len);
		arch_clean_invalidate_cache_range((addr_t)LK_SECURE_BOOT_BASE, LK_SECURE_BOOT_MAX_SIZE);
		/* secure world should detect this buffer is in shared memory and avoid mapping again */
		ret = sha256hw_process(g_crypto->last_block, AES_BLK_SIZE);
		if (ret) {
			dprintf(CRITICAL, "sha256hw_process fail, ret = 0x%x\n", ret);
			return ret;
		}
	}

	ret = sha256hw_done(hash);
	if (ret) {
		dprintf(CRITICAL, "sha256hw_done fail, ret = 0x%x\n", ret);
		return ret;
	}

	return ret;
}

