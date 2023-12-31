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
#include <debug.h>
#ifndef MACH_FPGA_NO_DISPLAY
#include <video.h>
#endif
#define EFUSE_PART_NAME		"efuse"
#define CHK_SIZE			20
#define CHK_THRESHOLD		19

#define EFUSE_NONE			0x00
#define EFUSE_FINE			0xAA
#define EFUSE_BROKEN		0x5A
#define EFUSE_REBLOW		0x55

extern int mboot_recovery_load_raw_part(char *part_name, unsigned long *addr, unsigned int size);


static int mboot_efuse_load_misc(unsigned char *misc_addr, unsigned int size)
{
	int ret;

	dprintf(SPEW, "[%s]: size is %u\n", __func__, size);
	dprintf(SPEW, "[%s]: misc_addr is 0x%p\n", __func__, misc_addr);

	ret = mboot_recovery_load_raw_part(EFUSE_PART_NAME, (unsigned long *) misc_addr, size);

	return ret;
}
#ifdef MTK_EFUSE_WRITER_SUPPORT
unsigned int mt_efuse_get(void)
{
	unsigned char data[CHK_SIZE] = {0};
	unsigned char efuse = EFUSE_NONE;
	char *str = "";
	int ret, i, cnt;

	ret = mboot_efuse_load_misc(data, CHK_SIZE);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: read partition failed\n", __func__);
		goto fail;
	}

	switch (data[0]) {
	case EFUSE_FINE:
	case EFUSE_BROKEN:
	case EFUSE_REBLOW:
		efuse = data[0];
	break;
	}

	if (efuse != EFUSE_NONE) {
		for (i = cnt = 1; i < CHK_SIZE; i++) {
			if (data[i] == efuse)
				cnt++;
		}

		if (cnt >= CHK_THRESHOLD) {
			if (efuse == EFUSE_FINE)
				str = "success";
			else if (efuse == EFUSE_BROKEN)
				str = "broken";
			else if (efuse == EFUSE_REBLOW)
				str = "reblow";

#ifndef MACH_FPGA_NO_DISPLAY
			video_printf("efuse blow: %s\n", str);
#endif
		}
	}

fail:
	return (unsigned int)efuse;
}
#else
unsigned int mt_efuse_get(void)
{
	return 0;
}
#endif
