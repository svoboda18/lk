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
#include <err.h>
#include <string.h>
#include <stdlib.h>
#include <kernel/thread.h>
#include <kernel/timer.h>
#include <kernel/event.h>
#include <dev/udc.h>
#include <platform/mt_typedefs.h>
#include <platform/mtk_wdt.h>
#include <version.h>
#include <verified_boot_common.h>   // for sec_query_warranty()
#include "sys_commands.h"
#include <block_generic_interface.h>
#include <part_interface.h>
#include <pal_log.h>
#ifdef MTK_AB_OTA_UPDATER
#include <bootctrl.h>
#endif  // MTK_AB_OTA_UPDATER

extern int get_off_mode_charge_status(void);  // FIXME!!! #include <xxx.h>        // for get_off_mode_charge_status()


#include "dl_commands.h"
#include "fastboot.h"
#ifdef MTK_GPT_SCHEME_SUPPORT
#include <platform/partition.h>
#else
#include <mt_partition.h>
#endif
#if defined(MTK_SECURITY_SW_SUPPORT) && defined(MTK_SEC_FASTBOOT_UNLOCK_SUPPORT)
#include "sec_unlock.h"
#endif
#include <platform/boot_mode.h>
#ifdef FASTBOOT_WHOLE_FLASH_SUPPORT
#include "partition_parser.h"
#endif
#define MAX_RSP_SIZE 64
/* MAX_USBFS_BULK_SIZE: if use USB3 QMU GPD mode: cannot exceed 63 * 1024 */
#define MAX_USBFS_BULK_SIZE (16 * 1024)

#define EXPAND(NAME) #NAME
#define TARGET(NAME) EXPAND(NAME)

#define USB_CMD_TIMEOUT 5000

static event_t usb_online;
static event_t txn_done;
static unsigned char buffer[4096] __attribute__((aligned(64)));
static char response[MAX_RSP_SIZE] __attribute__((aligned(64)));
static struct udc_endpoint *in, *out;
static struct udc_request *req;
int txn_status;

void *download_base;
unsigned download_max;
unsigned download_size;
extern int sec_usbdl_enabled (void);
extern void mtk_wdt_disable(void);
extern void mtk_wdt_restart(void);
extern unsigned get_secure_status(void);
extern unsigned get_unlocked_status(void);
unsigned fastboot_state = STATE_OFFLINE;

extern void fastboot_oem_key(const char *arg, void *data, unsigned sz);
extern void fastboot_oem_query_lock_state(const char *arg, void *data, unsigned sz);

timer_t wdt_timer;
struct fastboot_cmd *cmdlist;

extern BOOT_ARGUMENT *g_boot_arg;

extern char sn_buf[];
extern int get_bat_volt(int times);
char battery_voltage[6] = "";
char hw_revision[12] = "";
char erase_blk_size[12] = "";
char logical_blk_size[12] = "";
#define RADIO_VER_LEN 64
char radio_version[RADIO_VER_LEN+1];
int modem_image_loaded = 0;
extern void ccci_load_modem_image(void);
extern int ccci_get_md_version(int md_id, char buf[], int size);

static void req_complete(struct udc_request *req, unsigned actual, int status)
{
	txn_status = status;
	req->length = actual;
	event_signal(&txn_done, 0);
}

void update_device_info()
{
	sprintf(battery_voltage, "%dmV", get_bat_volt(1));
	sprintf(hw_revision, "%x", mt_get_chip_hw_ver());
#ifndef MNTL_SUPPORT
	sprintf(erase_blk_size, "0x%lx", mt_part_get_erasesz());
	sprintf(logical_blk_size, "0x%lx", mt_part_get_blksz());
#endif
}

void update_radio_version()
{
	int len = 0;

#ifdef LK_LD_MD_SUPPORT
	dprintf(INFO, "load modem image in fastboot mode to get radio version\n");
	ccci_load_modem_image();
	modem_image_loaded = 1;
	len = ccci_get_md_version(0, radio_version, RADIO_VER_LEN);
#endif
	if (len <= 0)
		sprintf(radio_version, "N/A");
}

void fastboot_register(const char *prefix, void (*handle)(const char *arg, void *data, unsigned sz),
					   unsigned allowed_when_security_on, unsigned forbidden_when_lock_on)
{
	struct fastboot_cmd *cmd;

	cmd = malloc(sizeof(*cmd));
	if (cmd) {
		cmd->prefix = prefix;
		cmd->prefix_len = strlen(prefix);
		cmd->allowed_when_security_on = allowed_when_security_on;
		cmd->forbidden_when_lock_on = forbidden_when_lock_on;
		cmd->handle = handle;
		cmd->next = cmdlist;
		cmdlist = cmd;
	}
}

struct fastboot_var *varlist;

void fastboot_publish(const char *name, const char *value)
{
	struct fastboot_var *var;
	var = malloc(sizeof(*var));
	if (var) {
		var->name = name;
		var->value = value;
		var->next = varlist;
		varlist = var;
	}
}

void fastboot_update_var(const char *name, const char *value)
{
	struct fastboot_var *var = varlist;

	while (NULL != var) {
		if (!strcmp(name, var->name)) {
			var->value = value;
		}
		var = var->next;
	}

	return;
}

const char *fastboot_get_var(const char *name)
{
	struct fastboot_var *var = varlist;

	while (NULL != var) {
		if (!strcmp(name, var->name)) {
			return var->value;
		}
		var = var->next;
	}

	return "";
}

int usb_read(void *_buf, unsigned len)
{
	int r;
	unsigned xfer;
	unsigned char *buf = _buf;
	int count = 0;

	if (fastboot_state == STATE_ERROR)
		goto oops;

	while (len > 0) {
		xfer = (len > MAX_USBFS_BULK_SIZE) ? MAX_USBFS_BULK_SIZE : len;
		req->buf = buf;
		req->length = xfer;
		req->complete = req_complete;
		r = udc_request_queue(out, req);
		if (r < 0) {
			dprintf(INFO, "usb_read() queue failed\n");
			goto oops;
		}
		event_wait(&txn_done);

		if (txn_status < 0) {
			dprintf(INFO, "usb_read() transaction failed\n");
			goto oops;
		}

		count += req->length;
		buf += req->length;
		len -= req->length;

		/* short transfer? */
		if (req->length != xfer) break;
	}

	return count;

oops:
	fastboot_state = STATE_ERROR;
	return -1;
}

int usb_read_with_timeout(void *_buf, unsigned len, time_t timeout)
{
	int r;
	unsigned xfer;
	unsigned char *buf = _buf;
	int count = 0;
	status_t ret = NO_ERROR;

	if (fastboot_state == STATE_ERROR)
		goto oops;

	while (len > 0) {
		xfer = (len > MAX_USBFS_BULK_SIZE) ? MAX_USBFS_BULK_SIZE : len;
		req->buf = buf;
		req->length = xfer;
		req->complete = req_complete;
		r = udc_request_queue(out, req);
		if (r < 0) {
			dprintf(INFO, "usb_read() queue failed\n");
			goto oops;
		}
		ret = event_wait_timeout(&txn_done, timeout);
		if (ret != NO_ERROR) {
			goto oops;
		}
		if (txn_status < 0) {
			dprintf(INFO, "usb_read() transaction failed\n");
			goto oops;
		}

		count += req->length;
		buf += req->length;
		len -= req->length;

		/* short transfer? */
		if (req->length != xfer) break;
	}

	return count;

oops:
	fastboot_state = STATE_ERROR;
	return -1;
}

int usb_write(void *buf, unsigned len)
{
	int r;

	if (fastboot_state == STATE_ERROR)
		goto oops;

	req->buf = buf;
	req->length = len;
	req->complete = req_complete;
	r = udc_request_queue(in, req);
	if (r < 0) {
		dprintf(INFO, "usb_write() queue failed\n");
		goto oops;
	}
	event_wait(&txn_done);
	if (txn_status < 0) {
		dprintf(INFO, "usb_write() transaction failed\n");
		goto oops;
	}
	return req->length;

oops:
	fastboot_state = STATE_ERROR;
	return -1;
}

int usb_write_with_timeout(void *buf, unsigned len, time_t timeout)
{
	int r;
	status_t ret = NO_ERROR;

	if (fastboot_state == STATE_ERROR)
		goto oops;

	req->buf = buf;
	req->length = len;
	req->complete = req_complete;
	r = udc_request_queue(in, req);
	if (r < 0) {
		dprintf(INFO, "usb_write() queue failed\n");
		goto oops;
	}
	ret = event_wait_timeout(&txn_done, timeout);
	if (ret != NO_ERROR) {
		goto oops;
	}
	if (txn_status < 0) {
		dprintf(INFO, "usb_write() transaction failed\n");
		goto oops;
	}
	return req->length;

oops:
	fastboot_state = STATE_ERROR;
	return -1;
}

void fastboot_ack(const char *code, const char *reason)
{
	if (fastboot_state != STATE_COMMAND)
		return;

	if (reason == 0)
		reason = "";

	memset(response, 0, sizeof(response));

	snprintf(response, MAX_RSP_SIZE, "%s%s", code, reason);
	fastboot_state = STATE_COMPLETE;

	usb_write_with_timeout(response, strlen(response), USB_CMD_TIMEOUT);

}

void fastboot_info(const char *reason)
{
	if (fastboot_state != STATE_COMMAND)
		return;

	if (reason == 0)
		return;

	memset(response, 0, sizeof(response));

	snprintf(response, MAX_RSP_SIZE, "INFO%s", reason);

	usb_write_with_timeout(response, strlen(response), USB_CMD_TIMEOUT);
}

void fastboot_fail(const char *reason)
{
	fastboot_ack("FAIL", reason);
}

void fastboot_okay(const char *info)
{
	fastboot_ack("OKAY", info);
}

static void fastboot_command_loop(void)
{
	struct fastboot_cmd *cmd;
	int r;
	dprintf(ALWAYS,"fastboot: processing commands\n");

again:
	while (fastboot_state != STATE_ERROR) {
		memset(buffer, 0, sizeof(buffer));
		r = usb_read(buffer, MAX_RSP_SIZE);
		if (r < 0) break; //no input command
		buffer[r] = 0;
		dprintf(ALWAYS,"[fastboot: command buf]-[%s]-[len=%d]\n", buffer, r);
		dprintf(ALWAYS,"[fastboot]-[download_base:0x%x]-[download_size:0x%x]\n",(unsigned int)download_base,(unsigned int)download_size);

		/*Pick up matched command and handle it*/
		for (cmd = cmdlist; cmd; cmd = cmd->next) {
			fastboot_state = STATE_COMMAND;
			if (memcmp(buffer, cmd->prefix, cmd->prefix_len)) {
				continue;
			}

			dprintf(ALWAYS,"[Cmd process]-[buf:%s]-[lenBuf:%s]\n", buffer,  buffer + cmd->prefix_len);
#ifdef MTK_SECURITY_SW_SUPPORT
			extern unsigned int seclib_sec_boot_enabled(unsigned int);
			//if security boot enable, check cmd allowed
			if ( !(sec_usbdl_enabled() || seclib_sec_boot_enabled(1)) || cmd->allowed_when_security_on )
				if ((!cmd->forbidden_when_lock_on) || (0 != get_unlocked_status()))
#endif
				{
					cmd->handle((const char*) buffer + cmd->prefix_len, (void*) download_base, download_size);
				}
				if (fastboot_state == STATE_COMMAND) {
#ifdef MTK_SECURITY_SW_SUPPORT
					if ((sec_usbdl_enabled() || seclib_sec_boot_enabled(1)) && !cmd->allowed_when_security_on ) {
						fastboot_fail("not support on security");
					} else if ((cmd->forbidden_when_lock_on) && (0 == get_unlocked_status())) {
						fastboot_fail("not allowed in locked state");
					} else
#endif
					{
						fastboot_fail("unknown reason");
					}
				}
				goto again;
		}
		dprintf(ALWAYS,"[unknown command]*[%s]*\n", buffer);
		fastboot_fail("unknown command");

	}
	fastboot_state = STATE_OFFLINE;
	dprintf(ALWAYS,"fastboot: oops!\n");
}

static int fastboot_handler(void *arg)
{
	for (;;) {
		event_wait(&usb_online);
		fastboot_command_loop();
	}
	return 0;
}

static void fastboot_notify(struct udc_gadget *gadget, unsigned event)
{
	if (event == UDC_EVENT_ONLINE) {
		event_signal(&usb_online, 0);
	} else if (event == UDC_EVENT_OFFLINE) {
		event_unsignal(&usb_online);
	}
}

static struct udc_endpoint *fastboot_endpoints[2];

static struct udc_gadget fastboot_gadget = {
	.notify     = fastboot_notify,
	.ifc_class  = 0xff,
	.ifc_subclass   = 0x42,
	.ifc_protocol   = 0x03,
	.ifc_endpoints  = 2,
	.ifc_string = "fastboot",
	.ept        = fastboot_endpoints,
};

extern void fastboot_oem_register();
void register_partition_var(void)
{
	int i, buf_len, val_buf_len = 20;
	unsigned long long p_size;
	char part_type[] = "partition-type:";
	char part_size[] = "partition-size:";
	char *type_buf;
	char *value_buf;
	char *var_name_buf;
	char *p_name_buf;

	for (i=0; i<PART_MAX_COUNT; i++) {
		p_size = partition_get_size(i);
		if ((long long)p_size == -1)
			continue;
		partition_get_name(i,&p_name_buf);

		partition_get_type(i,&type_buf);

		buf_len = strlen(part_type) + strlen(p_name_buf)+1;
		var_name_buf = malloc(buf_len);
		if (!var_name_buf) {
			pal_log_info("var_name_buf malloc fails. partition:%s len:%d\n", p_name_buf, buf_len);
			continue;
                }
		snprintf(var_name_buf, buf_len, "%s%s", part_type, p_name_buf);
		fastboot_publish(var_name_buf,type_buf);
		//printf("%d %s %s\n",i,var_name_buf,type_buf);

		/*reserved for MTK security*/
		if (!strcmp(type_buf,"ext4")) {
			if (!strcmp(p_name_buf,"userdata")) {
				p_size -= (u64)1*1024*1024;
			}
		}
		value_buf = malloc(val_buf_len);
		if (!value_buf) {
			pal_log_info("value_buf malloc fails. partition:%s len:%d\n", p_name_buf, val_buf_len);
			continue;
		}
		snprintf(value_buf,val_buf_len,"%llx",p_size);

		buf_len = strlen(part_size) + strlen(p_name_buf)+1;
		var_name_buf = malloc(buf_len);
		if (!var_name_buf) {
			pal_log_info("var_name_buf malloc fails. partition:%s len:%d\n", p_name_buf, buf_len);
			continue;
                }
		snprintf(var_name_buf, buf_len, "%s%s", part_size, p_name_buf);
		fastboot_publish(var_name_buf,value_buf);
		//printf("%d %s %s\n",i,var_name_buf,value_buf);
	}
}

/* return value: 1: option is valid, 0: option is invalid */
static unsigned int is_option_valid(unsigned int lower, unsigned int upper, unsigned int option)
{
	if (option < lower)
		return 0;

	if (option > upper)
		return 0;

	return 1;
}

#define NUM_SEC_OPTION (2)
static void register_secure_unlocked_var(void)
{
	static const char str_buf[NUM_SEC_OPTION][4] = {"no","yes"};
	unsigned secure_status = 0; /* default value is "no" */
	unsigned unlocked_status = 1; /* default value is "yes" */
	int warranty = 0; /* default value is "no" */

#ifdef MTK_SECURITY_SW_SUPPORT
	secure_status = get_secure_status();
	/* use default value if result is out or range */
	if (secure_status >= NUM_SEC_OPTION)
		secure_status = 0;

	/* use default value if result is out or range */
	unlocked_status = get_unlocked_status();
	if (unlocked_status >= NUM_SEC_OPTION)
		unlocked_status = 1;

	sec_query_warranty(&warranty);
	if (warranty >= NUM_SEC_OPTION)
		warranty = 0;
#endif

	if (is_option_valid(0, NUM_SEC_OPTION - 1, secure_status))
		fastboot_publish("secure", str_buf[secure_status]);

	if (is_option_valid(0, NUM_SEC_OPTION - 1, unlocked_status))
		fastboot_publish("unlocked", str_buf[unlocked_status]);

	if (is_option_valid(0, NUM_SEC_OPTION - 1, (unsigned int)warranty))
		fastboot_publish("warranty", str_buf[warranty]);

	return;
}

#ifdef MTK_OFF_MODE_CHARGE_SUPPORT
static void register_off_mode_charge_var(void)
{
	//INIT VALUE
	static const char str_buf[2][2] = {"0", "1"};
	unsigned off_mode_status = 0; /* default value is "0" */

	off_mode_status = get_off_mode_charge_status();
	if ((off_mode_status == 0) || (off_mode_status == 1))
		fastboot_publish("off-mode-charge", str_buf[off_mode_status]);
	else
		dprintf(INFO, "off mode charge status is out of boundary\n");
}
#endif


#ifdef MTK_AB_OTA_UPDATER
/******************************************************************************
******************************************************************************/
static char *part_name_array[PART_MAX_COUNT] = {NULL};
static int part_name_index = 0;


/******************************************************************************
******************************************************************************/
static bool is_part_name_processed(char *name)
{
	for (int i = 0; i < PART_MAX_COUNT; i++) {
		if (!part_name_array[i]) {
			return false;
		}
		int len = strlen(name);
		if (!strncmp(part_name_array[i], name, len + 1))
			return true;
		else
			continue;
	}
	return false;
}


/******************************************************************************
******************************************************************************/
static void insert_part_name(char *name)
{
	if (part_name_index >= PART_MAX_COUNT)
		return false;

	part_name_array[part_name_index] = name;
	part_name_index++;

	return true;
}


/******************************************************************************
******************************************************************************/
static void release_part_name(void)
{
	for (int i = 0; i < part_name_index; i++) {
		free(part_name_array[i]);
		part_name_array[i] = NULL;
	}
}


/******************************************************************************
* This function publishes the following variables: "has-slot", "current-slot",
* "slot-count", "slot-successful", "slot-unbootable", and "slot-retry-count".
*
* Note: The "preloader" partition is the only exception that does not have
*       "_a" or "_b" suffix even when it supports A/B systems.
******************************************************************************/
static void publish_ab_variables(void)
{
	char *str_yes = "yes";
	char *str_no = "no";
	char *str_yes_or_no = NULL;
	char *str_slot_count = "2";
	char *str_has_slot = "has-slot:";
	const int has_slot_len = strlen(str_has_slot);
	char *str_successful_a = "slot-successful:a";
	char *str_successful_b = "slot-successful:b";
	char *str_unbootable_a = "slot-unbootable:a";
	char *str_unbootable_b = "slot-unbootable:b";
	char *str_retry_a = "slot-retry-count:a";
	char *str_retry_b = "slot-retry-count:b";
	static char str_retry_count_a[4] = {'\0'};
	static char str_retry_count_b[4] = {'\0'};
	char *str_preloader = "has-slot:preloader";
	char *ab_suffix = NULL;

	for (int i = 0; i < PART_MAX_COUNT; i++) {
		char *part_name;
		int ret = partition_get_name(i, &part_name);
		if (ret < 0)
			break;  // early termination
		int len = has_slot_len + strlen(part_name) + 1;  // include NULL
		char *new_name = malloc(len);
		if (!new_name) {
			release_part_name();
			dprintf(CRITICAL, "%s (L%d) Error: failed to allocate memory!\n",
				__func__, __LINE__);
			return;
		}
		snprintf(new_name, len, "%s%s", str_has_slot, part_name);
		if (new_name[len - 3] == '_') {
			if (new_name[len - 2] == 'a' || new_name[len - 2] == 'b') {
				str_yes_or_no = str_yes;
				new_name[len - 3] = '\0';  // truncate suffix
			}
		} else {
			/* Preloader is the only exception that does not have A/B suffix. */
			if (!strncmp(new_name, str_preloader, strlen(str_preloader))) {
				if (get_suffix() != NULL)
					str_yes_or_no = str_yes;
			} else
				str_yes_or_no = str_no;
		}
		if (!is_part_name_processed(new_name)) {
			insert_part_name(new_name);
			fastboot_publish(new_name, str_yes_or_no);
		}
	}

	/* current-slot */
	ab_suffix = get_suffix();
	if(!strncmp(ab_suffix, "_", 1))  //remove the under line
		ab_suffix = ab_suffix+1;
	fastboot_publish("current-slot", ab_suffix);

	/* slot-count */
	fastboot_publish("slot-count", str_slot_count);

	int result;
	/* slot-successful */
	/* get_bootup_status() returns 1 for successful boot. Otherwise, return 0. */
	result = get_bootup_status("_a");
	if (result)
		str_yes_or_no = str_yes;
	else
		str_yes_or_no = str_no;
	fastboot_publish(str_successful_a, str_yes_or_no);

	result = get_bootup_status("_b");
	if (result)
		str_yes_or_no = str_yes;
	else
		str_yes_or_no = str_no;
	fastboot_publish(str_successful_b, str_yes_or_no);

	/* slot-unbootable */
	/* get_bootable_status() returns -1 for unbootable. Otherwise, return 0. */
	result = get_bootable_status("_a");
	if (result <= 0)
		str_yes_or_no = str_yes;
	else
		str_yes_or_no = str_no;
	fastboot_publish(str_unbootable_a, str_yes_or_no);

	result = get_bootable_status("_b");
	if (result <= 0)
		str_yes_or_no = str_yes;
	else
		str_yes_or_no = str_no;
	fastboot_publish(str_unbootable_b, str_yes_or_no);

	/* slot-retry-count */
	uint8_t retry_count = get_retry_count("_a");
	snprintf(str_retry_count_a, sizeof(str_retry_count_a), "%d", (int)retry_count);
	fastboot_publish(str_retry_a, str_retry_count_a);

	retry_count = get_retry_count("_b");
	snprintf(str_retry_count_b, sizeof(str_retry_count_b), "%d", (int)retry_count);
	fastboot_publish(str_retry_b, str_retry_count_b);

	// release_part_name();  // Do NOT release string here!
}

#else

static void publish_ab_variables(void)
{
	/* slot-count, return 0 for non A/B system */
	fastboot_publish("slot-count", "0");

}

#endif  // MTK_AB_OTA_UPDATER


/******************************************************************************
******************************************************************************/
int fastboot_init(void *base, unsigned size)
{
	thread_t *thr;
	int ret;
	static char dl_max_str[11];  // Take NULL and leading 0x into account. SCRATCH_SIZE must be <= 32-bits

	dprintf(ALWAYS, "fastboot_init()\n");

	download_base = base;
	download_max = SCRATCH_SIZE;
	snprintf(dl_max_str, sizeof(dl_max_str), "0x%X", download_max);

	//mtk_wdt_disable(); /*It will re-enable during continue boot*/
	timer_initialize(&wdt_timer);
	timer_set_periodic(&wdt_timer, 5000, (timer_callback)mtk_wdt_restart, NULL);

	fastboot_register("getvar:", cmd_getvar, TRUE, FALSE);
	fastboot_publish("version", "0.5");
	fastboot_publish("version-preloader", g_boot_arg->pl_version);
	fastboot_publish("version-bootloader", LK_VER_TAG);
	update_radio_version();
	fastboot_publish("version-baseband", (const char *)radio_version);
	publish_ab_variables();
	fastboot_publish("is-userspace", "no");
	fastboot_register("signature", cmd_install_sig, FALSE, TRUE);

#if (defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)) && defined(MTK_SPI_NOR_SUPPORT)
	dprintf(ALWAYS,"Init EMMC device in fastboot mode\n");
	mmc_legacy_init(1);
#endif
	fastboot_register("flash:", cmd_flash_mmc, TRUE, TRUE);
	fastboot_register("erase:", cmd_erase_mmc, TRUE, TRUE);

	fastboot_register("oem printk-ratelimit", cmd_printk_ratelimit, TRUE, FALSE);
	fastboot_register("continue", cmd_continue, FALSE, FALSE);
	fastboot_register("reboot", cmd_reboot, TRUE, FALSE);
	fastboot_register("reboot-bootloader", cmd_reboot_bootloader, TRUE, FALSE);
	fastboot_register("reboot-recovery",cmd_reboot_recovery, TRUE, FALSE);
	fastboot_register("reboot-fastboot",cmd_reboot_fastboot, TRUE, FALSE);

	fastboot_publish("product", PROJECT);
	fastboot_publish("kernel", "lk");
	register_secure_unlocked_var();
#ifdef MTK_OFF_MODE_CHARGE_SUPPORT
	register_off_mode_charge_var();
#endif
	fastboot_publish("serialno", sn_buf);

	register_partition_var();

	update_device_info();
	fastboot_publish("battery-voltage", (const char *) battery_voltage);
	fastboot_publish("battery-soc-ok", "yes");
	fastboot_publish("hw-revision", (const char *) hw_revision);
	fastboot_publish("erase-block-size", erase_blk_size); //temp. hard code for Zion, 512K bytes
	fastboot_publish("logical-block-size", logical_blk_size); //temp. hard code for Zion, 512 bytes
	fastboot_publish("variant", ""); //empty if no variants exist

	/*LXO: Download related command*/
	fastboot_register("download:", cmd_download, TRUE, FALSE);
	fastboot_publish("max-download-size", dl_max_str);
	/*LXO: END!Download related command*/

	fastboot_oem_register();
#if defined(MTK_SECURITY_SW_SUPPORT)
	fastboot_register("oem p2u", cmd_oem_p2u, TRUE, FALSE);
#endif
#ifdef FASTBOOT_DUMP_LOG
	fastboot_register("oem dump_pllk_log", cmd_oem_dump_log, TRUE, FALSE);
#endif
#ifdef MTK_OFF_MODE_CHARGE_SUPPORT
	fastboot_register("oem off-mode-charge",cmd_oem_off_mode_charge,FALSE, FALSE);
#endif
#if defined(MTK_SECURITY_SW_SUPPORT) && defined(MTK_SEC_FASTBOOT_UNLOCK_SUPPORT)
	fastboot_register("oem key",fastboot_oem_key,TRUE, FALSE);
	fastboot_register("oem lks",fastboot_oem_query_lock_state,TRUE, FALSE);
	/* allowed when secure boot and unlocked */
	fastboot_register("boot", cmd_boot, TRUE, TRUE);
	/* command rename */
	fastboot_register("flashing unlock",fastboot_oem_unlock, TRUE, FALSE);
	fastboot_register("flashing lock",fastboot_oem_lock, TRUE, FALSE);
	fastboot_register("flashing get_unlock_ability", fastboot_get_unlock_ability, TRUE, FALSE);
#endif
	fastboot_register("oem get_socid", fastboot_get_socid, TRUE, FALSE);

#ifdef MTK_JTAG_SWITCH_SUPPORT
	/* pin mux switch to ap_jtag */
	fastboot_register("oem ap_jtag",cmd_oem_ap_jtag, TRUE, FALSE);
#endif
#ifdef MTK_TINYSYS_SCP_SUPPORT
	fastboot_register("oem scp_status", cmd_oem_scp_status, TRUE, FALSE);
	fastboot_register("oem scp_log_thru_ap_uart", cmd_oem_scp_log_thru_ap_uart, TRUE, FALSE);
#endif
#ifdef MTK_USB2JTAG_SUPPORT
	fastboot_register("oem usb2jtag", cmd_oem_usb2jtag, TRUE, FALSE);
#endif
#ifdef MTK_MRDUMP_SUPPORT
	fastboot_register("oem mrdump", cmd_oem_mrdump, TRUE, FALSE);
	fastboot_register("oem mrdump-output-set",
			   cmd_oem_mrdump_outdev, TRUE, FALSE);
	fastboot_register("oem mrdump-file-allocate",
			   cmd_oem_mrdump_fallocate, TRUE, FALSE);
	fastboot_register("oem mrdump_chkimg",
			   cmd_oem_mrdump_chkimg, TRUE, FALSE);
#endif
#ifdef MTK_AB_OTA_UPDATER
	fastboot_register("set_active:", cmd_set_active, TRUE, FALSE);
#endif

#ifdef MTK_ULTRA_FLASH
	fastboot_register("oem ultraflash:", cmd_oem_ultra_flash, TRUE, TRUE);
	fastboot_register("oem ultraflash_en", cmd_oem_ultra_flash_en, TRUE, TRUE);
	fastboot_register("ultraflash:", cmd_oem_ultra_flash, TRUE, TRUE);
#endif
	event_init(&usb_online, 0, EVENT_FLAG_AUTOUNSIGNAL);
	event_init(&txn_done, 0, EVENT_FLAG_AUTOUNSIGNAL);

	in = udc_endpoint_alloc(UDC_TYPE_BULK_IN, 512);
	if (!in) {
		ret = -1;
		goto fail_alloc_in;
	}

	out = udc_endpoint_alloc(UDC_TYPE_BULK_OUT, 512);
	if (!out) {
		ret = -2;
		goto fail_alloc_out;
	}

	fastboot_endpoints[0] = in;
	fastboot_endpoints[1] = out;

	req = udc_request_alloc();
	if (!req) {
		ret = -3;
		goto fail_alloc_req;
	}

	if (udc_register_gadget(&fastboot_gadget)) {
		ret = -4;
		goto fail_udc_register;
	}

	thr = thread_create("fastboot", fastboot_handler, 0, DEFAULT_PRIORITY, DEFAULT_STACK_SIZE);
	if (!thr) {
		ret = -1;
		goto fail_alloc_in;
	}
	thread_resume(thr);
	return 0;

fail_udc_register:
	udc_request_free(req);
fail_alloc_req:
	udc_endpoint_free(out);
fail_alloc_out:
	udc_endpoint_free(in);
fail_alloc_in:
	dprintf(CRITICAL, "%s fail: %d\n", __func__, ret);
	ASSERT(0);
	return ret;
}

