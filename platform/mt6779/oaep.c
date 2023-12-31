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
#include <platform/oaep.h>
#include <platform/rnd.h>
#include <platform/sha256_export.h>
#include <platform/rsa2048_export.h>
#include <pal_typedefs.h>

/* assume hash: sha256, rsa: rsa2048 */
#define MGF1_COUNTER_SZ (4)

#define SEED_SZ    (SHA256_HASH_SZ)
#define DB_SZ      (RSA_MODULUS_SZ - 1 - SHA256_HASH_SZ)

/* used OAEP prefix to avoid name collision */
#define OAEP_MIN(a, b) ((a) < (b) ? (a) : (b))

#define ZERO_HASH 0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14, \
                  0x9a, 0xfb, 0xf4, 0xc8, 0x99, 0x6f, 0xb9, 0x24, \
                  0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c, \
                  0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55

/* for debug purpose */
static void dump_buf(const uint8_t *buf, uint32_t buf_sz)
{
	uint32_t idx = 0;

	if (buf_sz < 4)
		return;

	for (idx = 0; idx <= buf_sz - 4; idx += 4) {
		dprintf(CRITICAL, "[0x%x] 0x%x 0x%x 0x%x 0x%x\n", idx,
			*(buf + idx),
			*(buf + idx + 1),
			*(buf + idx + 2),
			*(buf + idx + 3));
	}

	return;
}

static uint32_t i2osp(uint32_t integer,
			  uint8_t *osp,
			  uint32_t osp_sz)
{
	uint32_t ret = OAEP_OK;
	int idx = 0;

	memset(osp, 0x0, osp_sz);
	if (osp_sz < 1)
		return OAEP_I2OSP_FAIL;

	idx = osp_sz - 1;

	while (integer != 0) {
		osp[idx] = integer % 0x100;
		integer /= 0x100;
		idx--;
		if (idx < 0) {
			ret = OAEP_I2OSP_FAIL;
			break;
		}
	}

	return ret;
}

static uint32_t mgf1(uint8_t *seed,
			 uint32_t seed_sz,
			 uint8_t *mask,
			 uint32_t mask_sz)
{
	uint32_t ret = OAEP_OK;
	uint32_t counter = 0;
	uint32_t num_round = 0;
	uint8_t *input = NULL;
	uint32_t input_sz = 0;
	uint8_t hash[SHA256_HASH_SZ] = {0};

	if (NULL == seed)
		return OAEP_MGF1_INVALID_SEED_BUF;

	if (0 == seed_sz)
		return OAEP_MGF1_INVALID_SEED_BUF_SZ;

	if (NULL == mask)
		return OAEP_MGF1_INVALID_MASK_BUF;

	if (0 == mask_sz)
		return OAEP_MGF1_INVALID_MASK_BUF_SZ;

	input_sz = seed_sz + MGF1_COUNTER_SZ;
	input = (uint8_t *)malloc(input_sz);
	if (NULL == input) {
		ret = OAEP_MGF1_MALLOC_FAIL;
		return ret;
	}

	memcpy(input, seed, seed_sz * sizeof(char));

	num_round = (mask_sz + SHA256_HASH_SZ - 1) / SHA256_HASH_SZ;
	for (counter = 0; counter < num_round; counter++) {
		int hash_ret = 0;
		ret = i2osp(counter, input + seed_sz, MGF1_COUNTER_SZ);
		if (ret)
			goto end;
		hash_ret = sha256(input, input_sz, hash);
		if (hash_ret) {
			ret = OAEP_MGF1_HASH_FAIL;
			goto end;
		}
		memcpy(mask + counter * SHA256_HASH_SZ,
		       hash,
		       OAEP_MIN(mask_sz - counter * SHA256_HASH_SZ, SHA256_HASH_SZ));
	}

end:
	if (NULL != input)
		free(input);

	return ret;
}

uint32_t oaep_encode(uint8_t *msg,
			 uint32_t msg_sz,
			 uint8_t *encoded_msg,
			 uint32_t encoded_msg_sz)
{
	uint32_t ret = OAEP_OK;
	const char zero_hash[SEED_SZ] = {ZERO_HASH};
	uint8_t *const masked_seed = encoded_msg + 1;
	uint8_t *const masked_db   = encoded_msg + 1 + SEED_SZ;
	/* temp data */
	uint8_t seed_mask[SEED_SZ] = {0};
	uint8_t db_mask[DB_SZ] = {0};
	uint32_t idx = 0;

	if (NULL == msg) {
		ret = OAEP_INVALID_MSG_BUF;
		goto end;
	}

	if (0 == msg_sz) {
		ret =  OAEP_INVALID_MSG_BUF_SZ;
		goto end;
	}

	if (NULL == encoded_msg) {
		ret = OAEP_INVALID_EMSG_BUF;
		goto end;
	}

	if (0 == encoded_msg_sz) {
		ret = OAEP_INVALID_EMSG_BUF_SZ;
		goto end;
	}

	if (RSA_MODULUS_SZ != encoded_msg_sz) {
		ret = OAEP_INVALID_EMSG_BUF_SZ;
		goto end;
	}

	if (msg_sz > DB_SZ - SEED_SZ - 1) {
		ret = OAEP_MSG_TOO_LONG;
		goto end;
	}

	memset(encoded_msg, 0x0, encoded_msg_sz);

	/* get seed from random number generator */
	if ((SEED_SZ % sizeof(uint32_t)) != 0) {
		ret = OAEP_INVALID_SEED_SZ;
		goto end;
	}

	for (idx = 0; idx < SEED_SZ; idx += 4) {
		uint32_t rnd_val = 0;
		ret = get_rnd(&rnd_val);
		if (ret)
			goto end;
		memcpy(masked_seed + idx, &rnd_val, sizeof(uint32_t));
	}

	/* store db in masked_db, mask not applied yet */
	memcpy(masked_db, zero_hash, SHA256_HASH_SZ);
	masked_db[DB_SZ - msg_sz - 1] = 0x1;
	memcpy(masked_db + DB_SZ - msg_sz, msg, msg_sz);

	/* create db_mask */
	ret = mgf1(masked_seed, SEED_SZ, db_mask, DB_SZ);
	if (ret)
		goto end;

	/* apply db_mask to create masked_db */
	for (idx = 0; idx < DB_SZ; idx++)
		masked_db[idx] ^= db_mask[idx];

	/* create seed_mask */
	ret = mgf1(masked_db, DB_SZ, seed_mask, SEED_SZ);
	if (ret)
		goto end;

	/* apply seed_mask to create masked_seed */
	for (idx = 0; idx < SEED_SZ; idx++)
		masked_seed[idx] ^= seed_mask[idx];

end:
	if (ret)
		dprintf(CRITICAL, "[oaep] encode fail (0x%x)\n", ret);

	return ret;
}

uint32_t oaep_decode(uint8_t *encoded_msg,
			 uint32_t encoded_msg_sz,
			 uint8_t *msg,
			 uint32_t *msg_sz)
{
	uint32_t ret = OAEP_OK;
	const uint8_t zero_hash[SEED_SZ] = {ZERO_HASH};
	uint8_t *const masked_seed = encoded_msg + 1;
	uint8_t *const masked_db   = encoded_msg + 1 + SEED_SZ;
	/* temp data */
	uint8_t seed_mask[SEED_SZ] = {0};
	uint8_t db_mask[DB_SZ] = {0};
	uint32_t idx = 0;

	if (NULL == msg) {
		ret = OAEP_INVALID_MSG_BUF;
		goto end;
	}

	if (NULL == msg_sz) {
		ret = OAEP_INVALID_MSG_BUF_SZ;
		goto end;
	}

	if (0 == *msg_sz) {
		ret = OAEP_INVALID_MSG_BUF_SZ;
		goto end;
	}

	if (NULL == encoded_msg) {
		ret = OAEP_INVALID_EMSG_BUF;
		goto end;
	}

	if (0 == encoded_msg_sz) {
		ret = OAEP_INVALID_EMSG_BUF_SZ;
		goto end;
	}

	if (RSA_MODULUS_SZ != encoded_msg_sz) {
		ret = OAEP_INVALID_EMSG_BUF_SZ;
		goto end;
	}

	memset(msg, 0x0, *msg_sz);

	/* recover seed_mask */
	ret = mgf1(masked_db, DB_SZ, seed_mask, SEED_SZ);
	if (ret)
		goto end;

	/* recover seed */
	/* after this step, data in masked_seed is actually seed */
	for (idx = 0; idx < SEED_SZ; idx++)
		masked_seed[idx] ^= seed_mask[idx];

	/* recover db_mask */
	ret = mgf1(masked_seed, SEED_SZ, db_mask, DB_SZ);
	if (ret)
		goto end;

	/* recover db */
	/* after this step, data in masked_db is actually db */
	for (idx = 0; idx < DB_SZ; idx++)
		masked_db[idx] ^= db_mask[idx];

	/* check against zero hash */
	if (0 != memcmp(masked_db, zero_hash, SHA256_HASH_SZ)) {
		ret = OAEP_ZERO_HASH_CHK_FAIL;
		dprintf(CRITICAL, "[oaep] zero hash compare fail\n");
		dprintf(CRITICAL, "[oaep] zero hash:\n");
		dump_buf(zero_hash, SHA256_HASH_SZ);

		dprintf(CRITICAL, "[oaep] db:\n");
		dump_buf(masked_db, DB_SZ);

		goto end;
	}

	for (idx = SHA256_HASH_SZ; idx < DB_SZ; idx++) {
		if (masked_db[idx] == 0)
			continue;
		else if (masked_db[idx] == 1)
			break;
		else {
			ret = OAEP_INVALID_FORMAT;
			goto end;
		}
	}

	/* msg starts at idx + 1 */
	if (DB_SZ - idx - 1 > *msg_sz) {
		ret = OAEP_INVALID_MSG_BUF_SZ;
		goto end;
	}

	*msg_sz = DB_SZ - idx - 1;
	memcpy(msg, masked_db + idx + 1, *msg_sz);

end:
	if (ret)
		dprintf(CRITICAL, "[oaep] decode fail (0x%x)\n", ret);

	return ret;

}

