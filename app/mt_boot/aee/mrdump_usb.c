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
 * THAT IT IS RECEIVER\'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER\'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER\'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK\'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK\'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
 * applicable license agreements with MediaTek Inc.
 */

#include <dev/mrdump.h>
#include <malloc.h>
#include <printf.h>
#include <platform/mt_gpt.h>
#include <string.h>
#include <sys/types.h>
#include "aee.h"
#include "mrdump_private.h"

/*
 * USB Connectivity
 * Note: for usb transmission
 *   QMU mode : MAX packet length: 63x1024 = 64512 byte. -> GPD_BUF_SIZE_ALIGN
 *   ZLP issue: EXSPACE should not be multiple size of 512 byte.
 */
#define EXSPACE      64256
#define MAX_RSP_SIZE 64
#define CON_TIMEOUT  5000

/* Flow control */
#define USB_RTS      "_RTS"
#define USB_CTS      "_CTS"
#define USB_FIN      "_FIN"
#define USBDONE      "DONE"

/*
 * Need to align 64 bytes to meet cache line length
 * 1. cmd[MAX_RSP_SIZE]
 * 2. data[EXSPACE]
 */
struct mrdump_usb_handle {
	char cmd[MAX_RSP_SIZE];
	uint8_t data[EXSPACE];
	unsigned int zipsize;
	int idx;
};

/* flow control of usb connection */
static bool usb_data_transfer(struct mrdump_usb_handle *handle, int length)
{
	int len;

	/* send RTS */
	memset(handle->cmd, 0, MAX_RSP_SIZE);
	len = snprintf(handle->cmd, MAX_RSP_SIZE, "%s", USB_RTS);
	len = usb_write_with_timeout(handle->cmd, strlen(handle->cmd), CON_TIMEOUT);
	if (len > 0) {

		/* receive CTS */
		memset(handle->cmd, 0, MAX_RSP_SIZE);
		len = usb_read_with_timeout(handle->cmd, MAX_RSP_SIZE, CON_TIMEOUT);
		if ((len == (int)strlen(USB_CTS))&&
		    (!strncmp(handle->cmd, USB_CTS, strlen(USB_CTS)))) {

			/* send DATA */
			len = usb_write_with_timeout(handle->data, length, CON_TIMEOUT);
			if (len > 0) {

				/* get FIN */
				memset(handle->cmd, 0, sizeof(handle->cmd));
				len = usb_read_with_timeout(handle->cmd, sizeof(handle->cmd), CON_TIMEOUT);
				if ((len == (int)strlen(USB_FIN)) &&
				    (!strncmp(handle->cmd, USB_FIN, strlen(USB_FIN)))) {
					return true;
				} else {
					voprintf_error("%s: failed to get FIN.cmd<%p,%d><%x,%x,%x,%x>\n", __func__,
						handle->cmd, len, handle->cmd[0], handle->cmd[1], handle->cmd[2], handle->cmd[3]);
				}

			} else {
				voprintf_error("%s: send DATA error.\n", __func__);
			}
		} else {
			voprintf_error("%s: Not CTS after RTS.cmd<%p,%d><%x,%x,%x,%x>\n", __func__,
				handle->cmd, len, handle->cmd[0], handle->cmd[1], handle->cmd[2], handle->cmd[3]);
		}
	} else {
		voprintf_error("%s: send RTS error.\n", __func__);
	}
	return false;
}

/* store data in pool (EXSPACE) and write when pool is full */
static int do_store_or_write(struct mrdump_usb_handle *handle, uint8_t *buf, uint32_t length)
{
	int total;
	unsigned int leftspace, mylen, reval;


	/* count for leftspace */
	total = EXSPACE;
	leftspace = total - handle->idx;

	/* check length */
	if (length > leftspace) {
		mylen = leftspace;
		reval = length - leftspace;
	} else {
		mylen = length;
		reval = 0;
	}

	/* store */
	while (mylen > 0) {
		handle->data[handle->idx] = *buf;
		handle->idx++;
		buf++;
		mylen--;
	}

	/* write */
	if (handle->idx == total) {
		if (!usb_data_transfer(handle, handle->idx)) {
			voprintf_error("%s: connection failed.(error idx: %d)\n",
			__func__, handle->idx);
			return -1;
		}
		handle->idx = 0;
	}

	return reval;
}

static int usb_write_cb(void *opaque_handle, void *buf, int size)
{
	unsigned int    len, moves;
	int             ret = 0;
	uint8_t         *ptr;

	struct mrdump_usb_handle *handle = opaque_handle;

	handle->zipsize += size;

	/* EOF, write the left Data in handle data buffer... */
	if ((buf == NULL) && (size == 0)) {

		/* MUST: a delay for the last transmission */
		mdelay(10);

		if (!usb_data_transfer(handle, handle->idx)) {
			voprintf_error("%s: connection failed.(error idx: %d)\n",
			__func__, handle->idx);
			return -1;
		}

		/* send "MRDUMP ZLP" */
		memset((void *)handle->data, 0, sizeof(handle->data));
		size = snprintf((char *)handle->data, sizeof(handle->data), "%s_%s",
				MRDUMP_GO_DUMP, USBDONE);
		if (0 > usb_write_with_timeout(handle->data, strlen((char *)handle->data),
					       CON_TIMEOUT)) {
			voprintf_error(" USB Dump: Write MRDUMP ZLP failed.\n");
			return -1;
		}

		return 0;
	}

	/* buf should not be NULL if not EOF */
	if (buf == NULL)
		return -1;

	/* process of Store and write */
	len = size;
	ptr = (uint8_t *)buf;
	while (1) {
		ret = do_store_or_write(handle, ptr, len);
		if (ret < 0) {
			voprintf_error(" USB Dump: store and write failed.\n");
			return -1;
		} else if (ret == 0) {
			break;
		} else {
			moves = len - ret;
			ptr += moves;
			len = ret;
		}
	}

	return size;
}

int mrdump_usb_output(const struct mrdump_control_block *mrdump_cb,
		      const struct kzip_addlist *memlist,
		      const struct kzip_addlist *memlist_cmm)
{
	int i;
	struct kzip_addlist expdb_file[2];
	char *expdb_filename;
	unsigned int expdb_offset, expdb_filesize;
	voprintf_info("Output by USB\n");

	struct mrdump_usb_handle *handle = memalign(64, sizeof(struct mrdump_usb_handle));
	if (handle == NULL) {
		voprintf_error("No enough memory.");
		return -1;
	}
	memset(handle, 0, sizeof(struct mrdump_usb_handle));

	mdelay(100);
	bool ok = true;
	mtk_wdt_restart();
	struct kzip_file *zf = kzip_open(handle, usb_write_cb);
	if (zf != NULL) {
		/* add SYS_COREDUMP */
		if (!kzip_add_file(zf, memlist, "SYS_COREDUMP"))
			ok = false;
		if (ok && !kzip_add_file(zf, memlist_cmm, "kernel.cmm"))
			ok = false;
		if (!ok)
			voprintf_error("failed to generate cmm\n");

		/* add file on expdb */
		for(i = 0; i < IPANIC_NR_SECTIONS; i++) {
			if (kedump_get_data_info(i, &expdb_filename, &expdb_offset, &expdb_filesize) == 0) {
				expdb_file[0].address = expdb_offset;
				expdb_file[0].size = expdb_filesize;
				expdb_file[0].type = EXPDB_FILE;
				expdb_file[1].address = 0;
				expdb_file[1].size = 0;
				expdb_file[1].type = MEM_NO_MAP;
				if (!kzip_add_file(zf, expdb_file, expdb_filename))
					ok = false;
			}
		}

		/* close zipfile */
		kzip_close(zf);
		usb_write_cb(handle, NULL, 0); /* really write the last part */
		zf = NULL;
	} else {
		ok = false;
	}
	free(handle);

	mtk_wdt_restart();
	if (ok) {
		mrdump_status_ok("OUTPUT:%s\nMODE:%s\n", "USB DUMP",
		mrdump_mode2string(mrdump_cb->crash_record.reboot_mode));
	}

	return ok ? 0 : -1;
}
