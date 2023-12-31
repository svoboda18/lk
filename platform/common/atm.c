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

#include <string.h>
#include <stdlib.h>
#include <platform/partition.h>
#include <partition_wp.h>
#include <printf.h>
#include "part_interface.h"

/* ------------------------------------------- */
/* Add to disable EMMC power on protect for ATM*/
/* ------------------------------------------- */
#define OFFSET (350)
#define KEY1 (12345678)
#define KEY2 (23131123)
#define VALID_FLAG (1)

static int scramble(int plainText, int key)
{
	return plainText ^ key;
}

static int descramble(int cipherText, int key)
{
	return cipherText ^ key;
}

bool get_atm_enable_status(void)
{
	bool atm_enable_flag = false;

#if defined (MTK_ATM_SUPPORT)
	long len;
	int flag = 0, tmp = 0;
	char part_name[] = "proinfo";
	unsigned char *b_buf = NULL, *s_buf = NULL;
	const int flag_len = 8;

	s_buf = (unsigned char *)malloc((OFFSET + flag_len) * sizeof(unsigned char));
	if (s_buf)
		memset(s_buf, 0, OFFSET + flag_len);
	else
		goto exit;

	b_buf = (unsigned char *)malloc(flag_len * sizeof(unsigned char));
	if (b_buf)
		memset(b_buf, 0, flag_len);
	else
		goto exit;

	len = partition_read(part_name, (off_t)0, s_buf, (size_t)(OFFSET + flag_len));

	if (len < 0) {
		len = -EIO;
		goto exit;
	}

	for (; tmp < flag_len; tmp++)
		b_buf[tmp] = s_buf[OFFSET + tmp];

	dprintf(INFO, "get atoi(b_buf) = %d\n", atoi((const char*)b_buf));
	flag = descramble(atoi((const char*)b_buf), KEY2) - KEY1;
	dprintf(INFO, "get flag = %d\n", flag);

	if (flag == VALID_FLAG) {
		atm_enable_flag = true;
		dprintf(ALWAYS, "[ATM] enable flag = %d! \n", atm_enable_flag);
	}

exit:
	if (s_buf) {
		free(s_buf);
		s_buf = NULL;
	}
	if (b_buf) {
		free(b_buf);
		b_buf = NULL;
	}
#endif

	return atm_enable_flag;

}
