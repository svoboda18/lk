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

#ifndef _MTK_SECURE_API_H_
#define _MTK_SECURE_API_H_

#include <plat_smc_id_table.h>

/* Error Code */
#define SIP_SVC_E_SUCCESS               0
#define SIP_SVC_E_NOT_SUPPORTED         -1
#define SIP_SVC_E_INVALID_PARAMS        -2
#define SIP_SVC_E_INVALID_Range         -3
#define SIP_SVC_E_PERMISSION_DENY       -4

size_t mt_secure_call_all(size_t function_id,
	size_t arg0, size_t arg1, size_t arg2,
	size_t arg3, size_t *r1, size_t *r2, size_t *r3);

#define mt_secure_call(_fun_id, _arg0, _arg1, _arg2, _arg3) \
	mt_secure_call_all(_fun_id, _arg0, _arg1, _arg2, _arg3, 0, 0, 0)
#define mt_secure_call_ret1(_fun_id, _arg0, _arg1, _arg2, _arg3) \
	mt_secure_call_all(_fun_id, _arg0, _arg1, _arg2, _arg3, 0, 0, 0)
#define mt_secure_call_ret2(_fun_id, _arg0, _arg1, _arg2, _arg3, _r1) \
	mt_secure_call_all(_fun_id, _arg0, _arg1, _arg2, _arg3, _r1, 0, 0)
#define mt_secure_call_ret3(_fun_id, _arg0, _arg1, _arg2, _arg3, _r1, _r2) \
	mt_secure_call_all(_fun_id, _arg0, _arg1, _arg2, _arg3, _r1, _r2, 0)
#define mt_secure_call_ret4(_fun_id, _arg0,\
	_arg1, _arg2, _arg3, _r1, _r2, _r3) \
	mt_secure_call_all(_fun_id, _arg0, _arg1, _arg2, _arg3, _r1, _r2, _r3)

void jumparch64_smc(size_t addr, size_t arg1, size_t arg2, size_t arg3);
unsigned int get_rnd(unsigned int *rnd);
unsigned int md_reg_write_smc(size_t arg0, size_t arg1, size_t arg2, size_t arg3);
unsigned int crypto_hw_init(unsigned int share_mem_addr, unsigned int share_mem_len);
unsigned int crypto_hw_disable(void);
unsigned int sha256atf_init(void);
unsigned int sha256atf_process(const unsigned char *in, unsigned long len);
unsigned int sha256atf_done(void);
int32_t rpmb_init(void);
int32_t rpmb_uninit(void);
int32_t rpmb_hmac(uint32_t pattern, uint32_t size);

#endif				/* _MTK_SECURE_API_H_ */
