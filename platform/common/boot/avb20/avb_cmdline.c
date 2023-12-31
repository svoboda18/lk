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

#include <string.h>

#include <pal_typedefs.h>
#include <pal_log.h>
#include <pal_assert.h>
#include <avb_cmdline.h>
#include <verified_boot_error.h>

#define CMDLINE_TAG "[cmdline]"

#define MAX_ENTRIES  (16)

#define INIT                    (0)
#define IS_KEY                  (1)
#define IS_VALUE                (2)
#define IS_VALUE_IN_QUOTATION   (3)

#define KEY_MATCH     (0)
#define KEY_NOT_MATCH (1)

struct cmdline_entry {
	char key[MAX_KEY_SZ + 1];
	char value[MAX_VALUE_SZ + 1];
};

static struct cmdline_entry g_cmdline_buf[MAX_ENTRIES];
static uint32_t g_cur_cmdline_entry_idx = 0;

static uint32_t is_key_match(char *in, uint32_t in_sz, const char *key)
{
	uint32_t match = KEY_NOT_MATCH;

	if (in == NULL)
		return KEY_NOT_MATCH;

	if (key == NULL)
		return KEY_NOT_MATCH;

	if (strlen(key) != in_sz)
		return KEY_NOT_MATCH;

	if (0 == memcmp(in, key, in_sz))
		match = KEY_MATCH;

	return match;
}

uint32_t avb_get_cmdline(const char *key, char *output, uint32_t output_sz)
{
	uint32_t ret = ERR_AVB_CMDLINE_ENTRY_NOT_FOUND;
	uint32_t i = 0;
	uint32_t value_sz = 0;

	if (key == NULL)
		return ERR_AVB_INVALID_KEY_BUF;

	if (output == NULL)
		return ERR_AVB_INVALID_OUTPUT_BUF;

	for (i = 0; i < MAX_ENTRIES; i++) {
		if (g_cmdline_buf[i].key[0] == '\0')
			break;

		if (KEY_MATCH == is_key_match(g_cmdline_buf[i].key,
					      strlen(g_cmdline_buf[i].key),
					      key)) {
			value_sz = strlen(g_cmdline_buf[i].value);

			if (value_sz == 0) {
				return ERR_AVB_INVALID_VALUE_SZ;
			} else {
				if (output_sz < value_sz + 1)
					return ERR_AVB_INVALID_OUTPUT_BUF;

				memcpy(output, g_cmdline_buf[i].value, value_sz);
				output[value_sz] = '\0';
			}

			return STATUS_OK;
		}
	}

	return ret;
}

/* extract key/value from cmdline and set them into device tree later */
uint32_t avb_extract_from_cmdline(char *in, uint32_t in_sz, const char *key)
{
	uint32_t ret = 0;
	uint32_t i = 0;
	uint32_t j = 0;
	uint32_t cur_state = INIT;
	uint32_t key_off_s = 0;
	uint32_t key_off_e = 0;
	uint32_t key_sz = 0;
	uint32_t val_off_s = 0;
	uint32_t val_off_e = 0;
	uint32_t val_sz = 0;
	uint32_t key_match = KEY_NOT_MATCH;
	uint32_t next_off = 0;

	if (in == NULL)
		return ERR_AVB_INVALID_INPUT_BUF;

	if (key == NULL)
		return ERR_AVB_INVALID_KEY_BUF;

	if ((strlen(key) > in_sz) || (strlen(key) > strlen(in)))
		return ERR_AVB_INVALID_KEY_BUF;

	while (i <= in_sz) {
		if (in[i] == ' ' || i == in_sz) {
			switch (cur_state) {
			case IS_KEY:
				/* end of key is found and there is no
				 * value for this key */
				key_off_e = i - 1;
				key_sz = key_off_e - key_off_s + 1;
				/* check if this is the key we want */
				key_match = is_key_match(in + key_off_s, key_sz, key);
				if (key_match == KEY_MATCH) {
					if (key_sz > MAX_KEY_SZ)
						return ERR_AVB_INVALID_KEY_BUF;
					memcpy(g_cmdline_buf[g_cur_cmdline_entry_idx].key,
					       in + key_off_s,
					       key_sz);
					/* find the first non-space character offset after key_off_e */
					next_off = key_off_e + 1;
					while (next_off < in_sz && in[next_off] == ' ') next_off++;
					for (j = 0; j < in_sz - next_off; j++) {
						in[key_off_s + j] = in[next_off + j];
						in[next_off + j] = '\0';
					}
					in[key_off_s + j] = '\0';
					g_cur_cmdline_entry_idx++;
					return 0;
				}
				cur_state = INIT;
				break;
			case IS_VALUE:
				/* end of value is found */
				val_off_e = i - 1;
				val_sz = val_off_e - val_off_s + 1;
				if (key_match == KEY_MATCH) {
					if (val_sz > MAX_VALUE_SZ)
						return ERR_AVB_INVALID_VALUE_SZ;
					memcpy(g_cmdline_buf[g_cur_cmdline_entry_idx].value,
					       in + val_off_s,
					       val_sz);
					/* find the first non-space character offset after val_off_e */
					next_off = val_off_e + 1;
					while (next_off < in_sz && in[next_off] == ' ') next_off++;
					for (j = 0; j < in_sz - next_off; j++) {
						in[key_off_s + j] = in[next_off + j];
						in[next_off + j] = '\0';
					}
					in[key_off_s + j] = '\0';
					g_cur_cmdline_entry_idx++;
					return 0;
				}
				cur_state = INIT;
				break;
			case INIT:
			case IS_VALUE_IN_QUOTATION:
			/* ignore */
			default:
				break;
			}
		} else if (in[i] == '=') {
			switch (cur_state) {
			case IS_KEY:
				/* end of key is found and there is
				 * value for this key */
				key_off_e = i - 1;
				key_sz = key_off_e - key_off_s + 1;
				/* check if this is the key we want */
				key_match = is_key_match(in + key_off_s, key_sz, key);
				if (key_match == KEY_MATCH) {
					if (key_sz > MAX_KEY_SZ)
						return ERR_AVB_INVALID_VALUE_SZ;
					memcpy(g_cmdline_buf[g_cur_cmdline_entry_idx].key,
					       in + key_off_s,
					       key_sz);
				}
				cur_state = IS_VALUE;
				val_off_s = i + 1;
				break;
			case INIT:
			case IS_VALUE:
			case IS_VALUE_IN_QUOTATION:
			/* ignore */
			default:
				break;
			}
		} else if (in[i] == '\"') {
			if (cur_state == IS_VALUE) {
				val_off_s = i;
				cur_state = IS_VALUE_IN_QUOTATION;
			} else if (cur_state == IS_VALUE_IN_QUOTATION) {
				val_off_e = i;
				val_sz = val_off_e - val_off_s + 1;
				if (key_match == KEY_MATCH) {
					if (val_sz > MAX_VALUE_SZ)
						return ERR_AVB_INVALID_VALUE_SZ;
					memcpy(g_cmdline_buf[g_cur_cmdline_entry_idx].value,
					       in + val_off_s,
					       val_sz);
					/* find the first non-space character offset after key_off_e */
					next_off = val_off_e + 1;
					while (next_off < in_sz && in[next_off] == ' ') next_off++;
					if (next_off != in_sz)
						memcpy(in + key_off_s, in + next_off, in_sz - next_off);
					memset(in + key_off_s + in_sz - next_off,
					       '\0',
					       next_off - key_off_s);
					g_cur_cmdline_entry_idx++;
					return 0;
				}
				cur_state = INIT;
			} else {
				return ERR_AVB_INVALID_CMDLINE_FMT;
			}
		} else {
			switch (cur_state) {
			case INIT:
				ASSERT(g_cur_cmdline_entry_idx < MAX_ENTRIES);
				if (g_cur_cmdline_entry_idx == MAX_ENTRIES) {
					pal_log_err("%s overflow", CMDLINE_TAG);
					return ERR_AVB_CMDLINE_OVERFLOW;
				}

				key_off_s = i;
				cur_state = IS_KEY;

				break;
			case IS_KEY:
			case IS_VALUE:
			case IS_VALUE_IN_QUOTATION:
			/* ignore */
			default:
				break;
			}
		}

		i++;
	}

	return ret;
}

