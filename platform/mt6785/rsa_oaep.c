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

#include <debug.h>
#include <malloc.h>
#include <string.h>
#include <platform/mt_typedefs.h>
#include <platform/oaep.h>
#include <platform/rsa2048_export.h>
#include <platform/rsa_oaep.h>

/* for debug */
#define DUMMY_OAEP (0)
#define DMMMY_RSA  (0)

/* encrypt with public key */
unsigned int rsa_oaep_encrypt(unsigned char *msg,
			      unsigned long msg_sz,
			      unsigned char *key_e,
			      unsigned long key_e_sz,
			      unsigned char *key_n,
			      unsigned long key_n_sz,
			      unsigned char *emsg,
			      unsigned long *emsg_sz)
{
	unsigned int ret = RSA_OAEP_OK;
	int rsa_ret = 0;
	unsigned char tmp_sig[RSA_MODULUS_SZ];
	unsigned long sig_sz = RSA_MODULUS_SZ;

	if (NULL == msg) {
		ret = RSA_OAEP_INVALID_MSG_BUF;
		goto end;
	}

	if (0 == msg_sz) {
		ret = RSA_OAEP_INVALID_MSG_BUF_SZ;
		goto end;
	}

	if (NULL == key_e) {
		ret = RSA_OAEP_INVALID_KEY_E_BUF;
		goto end;
	}

	if (0 == key_e_sz) {
		ret = RSA_OAEP_INVALID_KEY_E_BUF_SZ;
		goto end;
	}

	if (NULL == key_n) {
		ret = RSA_OAEP_INVALID_KEY_N_BUF;
		goto end;
	}

	if (0 == key_n_sz) {
		ret = RSA_OAEP_INVALID_KEY_N_BUF_SZ;
		goto end;
	}

	if (NULL == emsg) {
		ret = RSA_OAEP_INVALID_EMSG_BUF;
		goto end;
	}

	if (NULL == emsg_sz) {
		ret = RSA_OAEP_INVALID_EMSG_BUF_SZ;
		goto end;
	}

	if (0 == *emsg_sz) {
		ret = RSA_OAEP_INVALID_EMSG_BUF_SZ;
		goto end;
	}

#if DUMMY_OAEP
	memset(tmp_sig, 0x0, sig_sz);
	memcpy(tmp_sig, msg, msg_sz);
#else
	ret = oaep_encode(msg, msg_sz, tmp_sig, RSA_MODULUS_SZ);
	if (ret)
		goto end;
#endif

#if DMMMY_RSA
	memset(emsg, 0x0, sig_sz);
	memcpy(emsg, tmp_sig, sig_sz);
#else

	rsa_ret = rsa_exptmod(tmp_sig, sig_sz,
			      emsg, emsg_sz,
			      key_e, key_e_sz,
			      key_n, key_n_sz);
	if (rsa_ret) {
		dprintf(CRITICAL, "[rsa_oeap] rsa_exptmod fail (0x%x)\n", rsa_ret);
		ret = RSA_OAEP_EXPTMOD_FAIL;
		goto end;
	}

#endif

end:
	if (ret)
		dprintf(CRITICAL, "[rsa_oeap] encrypt fail (0x%x)\n", ret);

	return ret;
}

/* decrypt with private key */
unsigned int rsa_oaep_decrypt(unsigned char *emsg,
			      unsigned long emsg_sz,
			      unsigned char *key_d,
			      unsigned long key_d_sz,
			      unsigned char *key_n,
			      unsigned long key_n_sz,
			      unsigned char *msg,
			      unsigned long *msg_sz)
{
	unsigned int ret = RSA_OAEP_OK;
	int rsa_ret = 0;
	unsigned char tmp_sig[RSA_MODULUS_SZ];
	unsigned long sig_sz = RSA_MODULUS_SZ;
	unsigned int final_msg_sz = 0;

	if (NULL == emsg) {
		ret = RSA_OAEP_INVALID_EMSG_BUF;
		goto end;
	}

	if (0 == emsg_sz) {
		ret = RSA_OAEP_INVALID_EMSG_BUF_SZ;
		goto end;
	}

	if (NULL == key_d) {
		ret = RSA_OAEP_INVALID_KEY_D_BUF;
		goto end;
	}

	if (0 == key_d_sz) {
		ret = RSA_OAEP_INVALID_KEY_D_BUF_SZ;
		goto end;
	}

	if (NULL == key_n) {
		ret = RSA_OAEP_INVALID_KEY_N_BUF;
		goto end;
	}

	if (0 == key_n_sz) {
		ret = RSA_OAEP_INVALID_KEY_N_BUF_SZ;
		goto end;
	}

	if (NULL == msg) {
		ret = RSA_OAEP_INVALID_MSG_BUF;
		goto end;
	}

	if (NULL == msg_sz) {
		ret = RSA_OAEP_INVALID_MSG_SZ_BUF;
		goto end;
	}
	final_msg_sz = *msg_sz;

#if DMMMY_RSA
	memset(tmp_sig, 0x0, sig_sz);
	memcpy(tmp_sig, emsg, emsg_sz);
#else
	rsa_ret = rsa_exptmod(emsg, emsg_sz,
			      tmp_sig, &sig_sz,
			      key_d, key_d_sz,
			      key_n, key_n_sz);
	if (rsa_ret) {
		dprintf(CRITICAL, "[rsa_oeap] rsa_exptmod fail (0x%x)\n", rsa_ret);
		ret = RSA_OAEP_EXPTMOD_FAIL;
		goto end;
	}
#endif

#if DUMMY_OAEP
	memset(msg, 0x0, *msg_sz);
	memcpy(msg, tmp_sig, *msg_sz);
#else
	ret = oaep_decode(tmp_sig, sig_sz, msg, &final_msg_sz);
	if (ret)
		goto end;
#endif

	*msg_sz = final_msg_sz;
end:
	if (ret)
		dprintf(CRITICAL, "[rsa_oeap] decrypt fail (0x%x)\n", ret);

	return ret;
}

