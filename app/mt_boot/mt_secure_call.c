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
#include <sys/types.h>
#include "mtk_secure_api.h"
#define LOCAL_REG_SET_DECLARE \
	register size_t reg0 __asm__("r0") = function_id; \
	register size_t reg1 __asm__("r1") = arg0; \
	register size_t reg2 __asm__("r2") = arg1; \
	register size_t reg3 __asm__("r3") = arg2; \
	register size_t reg4 __asm__("r4") = arg3; \
	size_t ret

size_t mt_secure_call_all(size_t function_id,
	size_t arg0, size_t arg1, size_t arg2,
	size_t arg3, size_t *r1, size_t *r2, size_t *r3)
{
	LOCAL_REG_SET_DECLARE;

	__asm__ volatile ("smc #0x0\n" : "+r"(reg0),
		"+r"(reg1), "+r"(reg2), "+r"(reg3), "+r"(reg4));
	ret = reg0;
	if (r1 != NULL)
		*r1 = reg1;
	if (r2 != NULL)
		*r2 = reg2;
	if (r3 != NULL)
		*r3 = reg3;
	return ret;
}

void jumparch64_smc(size_t addr, size_t arg1, size_t arg2, size_t arg3)
{
	mt_secure_call(MTK_SIP_KERNEL_BOOT, addr, arg1, arg2, arg3);
}

unsigned int get_rnd(unsigned int *rnd)
{
	return mt_secure_call_all(MTK_SIP_LK_GET_RND, 0, 0, 0, 0, (size_t *) rnd, 0, 0);
}

unsigned int md_reg_write_smc(size_t arg0, size_t arg1, size_t arg2, size_t arg3)
{
	return mt_secure_call(MTK_SIP_LK_MD_REG_WRITE, arg0, arg1, arg2, arg3);
}

unsigned int crypto_hw_init(unsigned int share_mem_addr, unsigned int share_mem_len)
{
	return mt_secure_call(MTK_SIP_LK_CRYPTO_HW_ENGINE_INIT, share_mem_addr, share_mem_len, 0, 0);
}

unsigned int crypto_hw_disable(void)
{
	return mt_secure_call(MTK_SIP_LK_CRYPTO_HW_ENGINE_DISABLE, 0, 0, 0, 0);
}

unsigned int sha256atf_init(void)
{
	return mt_secure_call(MTK_SIP_LK_CRYPTO_SHA256_INIT, 0, 0, 0, 0);
}

unsigned int sha256atf_process(const unsigned char *in, unsigned long len)
{
	return mt_secure_call(MTK_SIP_LK_CRYPTO_SHA256_PROCESS, (size_t)in, len, 0, 0);
}

unsigned int sha256atf_done(void)
{
	return mt_secure_call(MTK_SIP_LK_CRYPTO_SHA256_DONE, 0, 0, 0, 0);
}

int32_t rpmb_init(void)
{
	return mt_secure_call(MTK_SIP_LK_RPMB_INIT, 0, 0, 0, 0);
}

int32_t rpmb_uninit(void)
{
	return mt_secure_call(MTK_SIP_LK_RPMB_UNINIT, 0, 0, 0, 0);
}

int32_t rpmb_hmac(uint32_t pattern, uint32_t size)
{
	return mt_secure_call(MTK_SIP_LK_RPMB_HMAC, pattern, size, 0, 0);
}
