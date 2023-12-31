/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <bootargs.h>
#include <errno.h>
#include <string.h>
#include <pal_log.h>
#include <kernel/thread.h>
#include <video.h>
#include <libfdt.h>

#define CMDLINE_OVERFLOW_STR	"[ERROR] CMDLINE overflow"

static char g_cmdline[CMDLINE_LEN];
static uint8_t bootargs_inited;
static char *cmdline_tail = g_cmdline;
static char *cmdline_end = g_cmdline + CMDLINE_LEN;

/* define sensitive parameters to be cleared */
static const char *cmdline_clear_list[] = {
	"androidboot.serialno=",
	NULL
};

static inline void validate_cmdline_boundary(const char *tail, const char *end)
{
	if (tail >= end) {
		pal_log_err(CMDLINE_OVERFLOW_STR"\n");
		video_printf(CMDLINE_OVERFLOW_STR" \n");
		panic(CMDLINE_OVERFLOW_STR);
	}
}
void bootargs_init(void *fdt)
{
#ifdef DEVICE_TREE_SUPPORT
	int offset;
	int len;
	const void *fdt_bootargs = NULL;
	const void *fdt_bootargs_ext = NULL;
	char *temp_ptr = NULL;
	uint32_t g_cmdline_strlen;

	assert(fdt);
	enter_critical_section();
	if (bootargs_inited == 1) {
		pal_log_err("bootargs has been initialized\n");
		goto exit;
	}
	if (fdt == 0) {
		pal_log_err("Device Tree is not inited!\n");
		panic("fdt is NULL");
	}
	/* g_cmdline is filled with parameters before bootargs_init is called */
	if (g_cmdline[0] != 0x0) {
		g_cmdline_strlen = strlen(g_cmdline);
		temp_ptr = (char *)malloc(g_cmdline_strlen + 1);
		assert(temp_ptr);
		snprintf(temp_ptr, (g_cmdline_strlen + 1), "%s", g_cmdline);
	}
	/* Reset cmdline_tail */
	cmdline_tail = g_cmdline;
	offset = fdt_path_offset(fdt, "/chosen");
	fdt_bootargs = fdt_getprop(fdt, offset,
			"bootargs", &len);
	assert(fdt_bootargs);
	cmdline_tail += snprintf(cmdline_tail, CMDLINE_LEN, "%s", (char *)fdt_bootargs);
	/*
	 * According to DeviceTreeOverlayGuide.pdf, bootloader should
	 * concatenate bootargs in main dtb with bootargs_ext in dtbo.
	 */
	fdt_bootargs_ext = fdt_getprop(fdt, offset,
			"bootargs_ext", &len);
	if (fdt_bootargs_ext != NULL) {
		if (*(char *)fdt_bootargs_ext != 0)
			cmdline_tail += snprintf(cmdline_tail, cmdline_end - cmdline_tail, " %s", (char *)fdt_bootargs_ext);
	}
	if (temp_ptr != 0)
		cmdline_tail += snprintf(cmdline_tail, cmdline_end - cmdline_tail, "%s", temp_ptr);

	bootargs_inited = 1;
exit:
	if (temp_ptr)
		free(temp_ptr);
	exit_critical_section();
#else
	UNUSED(fdt);
#endif /* DEVICE_TREE_SUPPORT */
}

char *cmdline_get(void)
{
	return g_cmdline;
}

void cmdline_print(void)
{
	int i;
	int temp_cmd_len = CMDLINE_LEN / 16;
	int cmd_len = 0;
	char *temp_cmdline = NULL;
#ifdef USER_LOAD
	bool ret;

	ret = cmdline_clear_string();
	if (!ret)
		pal_log_err("cmdline clear not ok\n");
#endif

	cmd_len = strlen(g_cmdline);
	pal_log_err("g_cmdline size: %d\n", cmd_len);

	temp_cmdline = (char *)malloc(temp_cmd_len);
	if (!temp_cmdline) {
		pal_log_err("temp_cmdline malloc fail\n");
		goto exit;
	}

	enter_critical_section();

	for (i = 0; i < (cmd_len / (temp_cmd_len - 1)) + 1; i++) {
		strncpy(temp_cmdline, &g_cmdline[(temp_cmd_len - 1) * i], (temp_cmd_len - 1));
		temp_cmdline[temp_cmd_len - 1] = '\0';
		if (i == 0)
			pal_log_err("cmdline: %s\n", temp_cmdline);
		else
			pal_log_err("       : %s\n", temp_cmdline);
	}

	exit_critical_section();

exit:
	if (temp_cmdline)
		free(temp_cmdline);
}

bool cmdline_append(const char *append_string)
{
	unsigned int append_string_len;

	enter_critical_section();
	append_string_len = strlen(append_string);
	validate_cmdline_boundary((cmdline_tail + append_string_len + 1), cmdline_end);
	*cmdline_tail++ = ' ';
	strncat(cmdline_tail, append_string, cmdline_end - cmdline_tail);
	cmdline_tail += append_string_len;
	exit_critical_section();
	return true;
}

bool cmdline_overwrite(const char *overwrite_string)
{
	int cmd_len;
	cmd_len = strlen(overwrite_string);
	if (cmd_len > CMDLINE_LEN - 1) {
		pal_log_err(CMDLINE_OVERFLOW_STR"\n");
		panic(CMDLINE_OVERFLOW_STR);
		return false;
	}
	enter_critical_section();
	strncpy(g_cmdline, overwrite_string, CMDLINE_LEN - 1);
	exit_critical_section();
	return true;
}

bool cmdline_clear_string(void)
{
	int i = 0;
	char *ptr = NULL;

	/* search parameters from cmdline */
	for (i = 0; cmdline_clear_list[i] != NULL ; i++) {
		size_t str_len = 0;

		ptr = strstr(g_cmdline, cmdline_clear_list[i]);
		if (ptr == NULL || ptr > cmdline_end) {
			pal_log_err("[cmdline clear] extract %s fails\n", cmdline_clear_list[i]);
			return false;
		}

		/* search 1st "space" character after key match ptr */
		while (*(char *)(ptr+str_len) != ' ' && (ptr + str_len) < cmdline_end) str_len++;

		pal_log_err("[cmdline clear] clear str size=%d\n", str_len);
		memset(ptr, 0x78, str_len); //clear as xxxx
		memcpy(ptr, cmdline_clear_list[i], strlen(cmdline_clear_list[i]));
	}

	return true;
}
