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

#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>
#include <video.h>
#include <platform/partition.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <platform/verified_boot.h>
#include <platform/sec_policy.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>
#include <platform/mt_gpt.h>
#include <platform/sec_status.h>
#include <platform/sec_export.h>
#include <platform/mtk_key.h>
#include <target/cust_key.h>
#include <bootimg.h>
#include <part_interface.h>
#include <part_status.h>
#include <verified_boot_common.h>
#include <block_generic_interface.h>    // for mt_part_get_device()
#include <target.h>                     // for target_get_scratch_address()
#include <boot_opt.h>
#include <storage_api.h>
#include <pal_typedefs.h>
#include <pal_log.h>

#define MODULE_NAME "LK_BOOT"
#define BOOTIMG_DEF_PGSIZE  (2 * 1024)

#define UART_EARLY_CONSOLE_LEN 128

//*********
//* Notice : it's kernel start addr (and not include any debug header)
uint32_t g_kmem_off = 0;

//*********
//* Notice : it's rootfs start addr (and not include any debug header)
uint32_t g_rmem_off = 0;

uint32_t g_pg_sz = BOOTIMG_DEF_PGSIZE;
uint32_t g_bimg_sz = 0;
uint32_t g_rcimg_sz = 0;
uint32_t g_fcimg_sz = 0;
int g_kimg_sz = 0;
int g_rimg_sz = 0;
extern BOOT_ARGUMENT *g_boot_arg;
extern struct bootimg_hdr *g_boot_hdr;
extern bool cmdline_append(const char *append_string);
extern void mtk_wdt_restart(void);

/* the only possible boot state change here is green->red */
int verified_boot_init(char *part_name, char *img_name)
{
	int ret = 0;

#ifdef MTK_SECURITY_SW_SUPPORT
	uint32_t policy_entry_idx = 0;
	uint32_t img_auth_required = 0;
	uint32_t img_vfy_time = 0;
	uint32_t bypass_ver_check = 0;
#endif

	g_boot_state = BOOT_STATE_GREEN;

#ifdef MTK_SECURITY_SW_SUPPORT
	/* please refer to the following website for verified boot flow */
	/* http://source.android.com/devices/tech/security/verifiedboot/verified-boot.html */

	img_vfy_time = get_timer(0);
	policy_entry_idx = get_policy_entry_idx(part_name);
	img_auth_required = get_vfy_policy(policy_entry_idx);
	if (img_auth_required) {
		mtk_wdt_restart();
#ifdef MTK_SECURITY_OEM_WITH_DMCERT_ONLY_SUPPORT
		ret = (int)sec_img_auth_init(part_name, img_name, BYPASS_CERT_CHAIN_VERIFY);
#else
		ret = (int)sec_img_auth_init(part_name, img_name, 0);
#endif

#ifdef MTK_SECURITY_YELLOW_STATE_SUPPORT
		if (ERR_RETRY_WITH_VERIFIED_BOOT == ret) {
			ret = 0;
			bypass_ver_check = 1;
		}
#endif

		pal_log_info("[SBC] boot cert vfy(%d ms)\n",
			(uint32_t)get_timer(img_vfy_time));

		if (ret) {
			g_boot_state = BOOT_STATE_RED;
			ret = -1;
			goto end;
		}

		if (bypass_ver_check == 0) {
#ifdef MTK_SECURITY_ANTI_ROLLBACK
#ifdef MTK_SECURITY_OEM_WITH_DMCERT_ONLY_SUPPORT
			pal_log_info("[SBC] DMCERT: No anti-rollback support\n");
#else
			ret = sec_rollback_check(1);
			if (ret) {
				g_boot_state = BOOT_STATE_RED;
				ret = -1;
				goto end;
			}
#endif
#endif
		}
	} else
		pal_log_info("[SBC] (%s, %s) cert vfy disabled\n", part_name, img_name);
#endif

end:
	ret = print_boot_state();
	if (ret)
		return ret;

	if (img_name == NULL)
		ret = show_warning("UNKNOWN");
	else
		ret = show_warning(img_name);
	if (ret)
		return ret;

	return ret;
}

int verified_boot_flow(char *img_name, uint32_t img_addr, uint32_t img_sz)
{
	int ret = 0;
#ifdef MTK_SECURITY_SW_SUPPORT
	uint32_t policy_entry_idx = 0;
	uint32_t img_auth_required = 0;
	uint32_t img_vfy_time = 0;
	int lock_state = 0;
#endif

	if (g_boot_state == BOOT_STATE_RED)
		goto end;

	g_boot_state = BOOT_STATE_GREEN;

	/* loading boot image without verifying boot image header first would not
	   become a security hole since initial load address is not specified by
	   boot image header, boot image is loaded to an address specified by lk,
	   and kernel and ramdisk will be relocated later after boot image
	   verification is done. Need to consider whether boot image size will be
	   too big so it overlaps with other important region. */

	/* if MTK_SECURITY_SW_SUPPORT is not defined, boot state is always green */

#ifdef MTK_SECURITY_SW_SUPPORT
	/* please refer to the following website for verified boot flow */
	/* http://source.android.com/devices/tech/security/verifiedboot/verified-boot.html */
	ret = sec_query_device_lock(&lock_state);
	if (ret) {
		g_boot_state = BOOT_STATE_RED;
		goto end;
	}

	if (DEVICE_STATE_LOCKED == lock_state) {
		img_vfy_time = get_timer(0);
		policy_entry_idx = get_policy_entry_idx("boot");
		img_auth_required = get_vfy_policy(policy_entry_idx);
		if (img_auth_required) {
			mtk_wdt_restart();
			img_vfy_time = get_timer(0);
#ifdef MTK_SECURITY_OEM_WITH_DMCERT_ONLY_SUPPORT
			ret = sec_img_auth_custom(img_addr, img_sz);
			if (ret)
				g_boot_state = BOOT_STATE_RED;
			else {
				ret = sec_oemkey_compare();
				if (ret)
					g_boot_state = BOOT_STATE_YELLOW;
				else
					g_boot_state = BOOT_STATE_GREEN;
			}
#else
			ret = (int)sec_img_auth((uint8_t *)img_addr, img_sz);
			if (ret) {
				/* show public key on LCM and requires user confirmation to proceed */
				ret = sec_img_auth_custom((uint8_t *)img_addr, img_sz);
				if (0 == ret)
					g_boot_state = BOOT_STATE_YELLOW;
				else
					g_boot_state = BOOT_STATE_RED;
			}
#endif
			pal_log_info("[SBC] img vfy(%d ms)\n", (uint32_t)get_timer(img_vfy_time));
		} else
			pal_log_err("[SBC] img vfy disabled\n");
	} else if (DEVICE_STATE_UNLOCKED == lock_state)
		g_boot_state = BOOT_STATE_ORANGE;
	else  /* unknown lock state*/
		g_boot_state = BOOT_STATE_RED;
#endif //MTK_SECURITY_SW_SUPPORT

end:
	ret = print_boot_state();
	if (ret)
		return ret;

	if (img_name == NULL)
		ret = show_warning("UNKNOWN");
	else
		ret = show_warning(img_name);
	if (ret)
		return ret;

	ret = set_boot_state_to_cmdline();
	if (ret)
		return ret;

	return ret;
}

static int mboot_common_load_part_info(char *part_name,
				       char *img_name, part_hdr_t *part_hdr, uint64_t *img_start_addr)
{
	long len;
	u64 offset, part_size;

	if (partition_exists(part_name) == PART_NOT_EXIST)
		return -ENOENT;

	part_size = partition_get_size_by_name(part_name);

	offset = 0;

	//***************
	//* read partition header
	//*
	while (1) {

		len = partition_read(part_name, offset, (uchar *)part_hdr, sizeof(part_hdr_t));

		if (len < 0) {
			pal_log_err("[%s] %s partition read error. LINE: %d\n", MODULE_NAME,
				part_name, __LINE__);
			break;
		}

		pal_log_err("\n=========================================\n");
		pal_log_err("[%s] %s magic number : 0x%x\n", MODULE_NAME, part_name,
			part_hdr->info.magic);
		part_hdr->info.name[31] = '\0'; //append end char
		pal_log_err("[%s] %s name         : %s\n", MODULE_NAME, part_name,
			part_hdr->info.name);
		pal_log_err("[%s] %s size         : %d\n", MODULE_NAME, part_name,
			part_hdr->info.dsize);
		pal_log_err("=========================================\n");

		//***************
		//* check partition magic
		//*
		if (part_hdr->info.magic != PART_MAGIC) {
			pal_log_err("[%s] %s partition magic error\n", MODULE_NAME, part_name);
			len = -1;
			break;
		}

		offset += sizeof(part_hdr_t);

		//***************
		//* check partition data size
		//*
		if ((offset + part_hdr->info.dsize) > part_size) {
			pal_log_err("[%s] %s partition size error 0x%llx, 0x%llx\n", MODULE_NAME,
				part_name, offset + part_hdr->info.dsize, part_size);
			len = -1;
			break;
		}

		//***************
		//* check image name
		//*
		if (!strncasecmp(part_hdr->info.name, img_name, sizeof(part_hdr->info.name))) {
			pal_log_info("[%s] %s image name found\n", MODULE_NAME, img_name);
			break;
		}

		//***************
		//* find next image
		//* image with new layout will align to a specific size
		//*
		if (part_hdr->info.ext_magic == PART_EXT_MAGIC)
			offset += ROUNDUP(part_hdr->info.dsize, part_hdr->info.align_size);
		else
			offset += part_hdr->info.dsize;
	}

	if (len > 0)
		*img_start_addr = offset;

	return len;
}


/**********************************************************
 * Routine: mboot_common_load_part
 *
 * Description: common function for loading image from nand flash
 *              this function is called by
 *                  (1) 'mboot_common_load_logo' to display logo
 *
 **********************************************************/
int mboot_common_load_part(char *part_name, char *img_name, uint32_t addr)
{
	long len;
	uint64_t start_addr = 0;
	part_hdr_t *part_hdr;

	if (partition_exists(part_name) == PART_NOT_EXIST)
		return -ENOENT;

	part_hdr = (part_hdr_t *)malloc(sizeof(part_hdr_t));

	if (!part_hdr)
		return -ENOMEM;

	len = mboot_common_load_part_info(part_name, img_name, part_hdr,
					  &start_addr);
	if (len < 0) {
		len = -EINVAL;
		goto exit;
	}

	//****************
	//* read image data
	//*
	pal_log_info("read the data of %s\n", part_name);

	len = partition_read(part_name, start_addr, (uchar *)addr,
			     (size_t)part_hdr->info.dsize);

	if (len < 0) {
		len = -EIO;
		goto exit;
	}

exit:
	if (part_hdr)
		free(part_hdr);

	return len;
}

/**********************************************************
 * Routine: mboot_common_load_logo
 *
 * Description: function to load logo to display
 *
 **********************************************************/
int mboot_common_load_logo(uint32_t logo_addr, char *filename)
{
	int ret;
#if (CONFIG_COMMANDS & CFG_CMD_FAT)
	long len;
#endif

#if (CONFIG_COMMANDS & CFG_CMD_FAT)
	len = file_fat_read(filename, (uint8_t *)logo_addr, 0);

	if (len > 0)
		return (int)len;
#endif

	ret = mboot_common_load_part("logo", "logo", logo_addr);

	return ret;
}

/**********************************************************
 * Routine: mboot_android_check_img_info
 *
 * Description: this function is called to
 *              (1) check the header of kernel / rootfs
 *
 * Notice : this function will be called by 'mboot_android_check_bootimg_hdr'
 *
 **********************************************************/
int mboot_android_check_img_info(char *part_name, part_hdr_t *part_hdr)
{
	//***************
	//* check partition magic
	//*
	if (part_hdr->info.magic != PART_MAGIC) {
		pal_log_err("[%s] %s partition magic not match\n", MODULE_NAME,
			part_name);
		return -1;
	}

	//***************
	//* check partition name
	//*
	if (strncasecmp(part_hdr->info.name, part_name, sizeof(part_hdr->info.name))) {
		pal_log_err("[%s] %s partition name not match\n", MODULE_NAME, part_name);
		return -1;
	}

	pal_log_err("\n=========================================\n");
	pal_log_err("[%s] %s magic number : 0x%x\n", MODULE_NAME, part_name,
		part_hdr->info.magic);
	pal_log_err("[%s] %s size         : 0x%x\n", MODULE_NAME, part_name,
		part_hdr->info.dsize);
	pal_log_err("=========================================\n");

	//***************
	//* return the image size
	//*
	return part_hdr->info.dsize;
}

/**********************************************************
 * Routine: mboot_android_check_bootimg_hdr
 *
 * Description: this function is called to
 *              (1) 'read' the header of boot image from nand flash
 *              (2) 'parse' the header of boot image to obtain
 *                  - (a) kernel image size
 *                  - (b) rootfs image size
 *                  - (c) rootfs offset
 *
 * Notice : this function must be read first when doing nand / msdc boot
 *
 **********************************************************/
static int mboot_android_check_bootimg_hdr(char *part_name,
		struct bootimg_hdr *boot_hdr)
{
	long len;
	int ret = 0;
	u64 addr;
	uint32_t k_pg_cnt = 0;
	uint32_t r_pg_cnt = 0;
	uint32_t dtbo_pg_cnt = 0;
	uint32_t dt_pg_cnt = 0;
	uint32_t pg_sz;

	if (partition_exists(part_name) == PART_NOT_EXIST)
		return -1;

	addr = partition_get_offset_by_name(part_name);

	//***************
	//* read partition header
	//*

	pal_log_err("part page addr is 0x%llx\n", addr);

	len = partition_read(part_name, 0, (uchar *) boot_hdr,
			     sizeof(struct bootimg_hdr));

	if (len < 0) {
		pal_log_err("[%s] %s boot image header read error. LINE: %d\n",
			MODULE_NAME, part_name, __LINE__);
		return -1;
	}

	pal_log_err("\n============================================================\n");
	pal_log_err("[%s] Android Partition Name                : %s\n",
		MODULE_NAME, part_name);
	pal_log_err("[%s] Android Boot IMG Hdr - Kernel Size    : 0x%08X\n",
		MODULE_NAME, boot_hdr->kernel_sz);
	pal_log_err("[%s] Android Boot IMG Hdr - Kernel Address : 0x%08X\n",
		MODULE_NAME, boot_hdr->kernel_addr);
	pal_log_err("[%s] Android Boot IMG Hdr - Rootfs Size    : 0x%08X\n",
		MODULE_NAME, boot_hdr->ramdisk_sz);
	pal_log_err("[%s] Android Boot IMG Hdr - Rootfs Address : 0x%08X\n",
		MODULE_NAME, boot_hdr->ramdisk_addr);
	pal_log_err("[%s] Android Boot IMG Hdr - Tags Address   : 0x%08X\n",
		MODULE_NAME, boot_hdr->tags_addr);
	pal_log_err("[%s] Android Boot IMG Hdr - Page Size      : 0x%08X\n",
		MODULE_NAME, boot_hdr->page_sz);
	pal_log_err("[%s] Android Boot IMG Hdr - Command Line   : %s\n",
		MODULE_NAME, boot_hdr->cmdline);
	pal_log_err("\n============================================================\n");

	//***************
	//* check partition magic
	//*
	if (strncmp((char const *)boot_hdr->magic, BOOTIMG_MAGIC,
		    BOOTIMG_MAGIC_SZ) != 0) {
		pal_log_err("[%s] boot image header magic error\n", MODULE_NAME);
		return -1;
	}

	pg_sz = boot_hdr->page_sz;
	g_pg_sz = boot_hdr->page_sz;

	//***************
	//* follow bootimg.h to calculate the location of rootfs
	//*
	if (len != -1) {
		if (g_is_64bit_kernel)
			g_kmem_off = (uint32_t)target_get_scratch_address();
		else
			g_kmem_off = boot_hdr->kernel_addr;

		k_pg_cnt = (boot_hdr->kernel_sz + (pg_sz - 1)) / pg_sz;

		r_pg_cnt = (boot_hdr->ramdisk_sz + (pg_sz - 1)) / pg_sz;

		if (boot_hdr->header_version >= BOOT_HEADER_VERSION_ONE)
			dtbo_pg_cnt = (boot_hdr->recovery_dtbo_size + (pg_sz - 1)) / pg_sz;

		if (boot_hdr->header_version >= BOOT_HEADER_VERSION_TWO)
			dt_pg_cnt = (boot_hdr->dtb_size + (pg_sz - 1)) / pg_sz;

		pal_log_info(" > page count of kernel image = %d\n", k_pg_cnt);
		g_rmem_off = g_kmem_off + k_pg_cnt * pg_sz;

		pal_log_info(" > kernel mem offset = 0x%x\n", g_kmem_off);
		pal_log_info(" > rootfs mem offset = 0x%x\n", g_rmem_off);


		//***************
		//* specify boot image size
		//*
		g_bimg_sz = (k_pg_cnt + r_pg_cnt + dtbo_pg_cnt + dt_pg_cnt + 1) * pg_sz;

		pal_log_info(" > boot image size = 0x%x\n", g_bimg_sz);
	}

	ret = verified_boot_init("boot", "boot");
	if (ret)
		return ret;

	return 0;
}

/**********************************************************
 * Routine: mboot_android_check_recoveryimg_hdr
 *
 * Description: this function is called to
 *              (1) 'read' the header of boot image from nand flash
 *              (2) 'parse' the header of boot image to obtain
 *                  - (a) kernel image size
 *                  - (b) rootfs image size
 *                  - (c) rootfs offset
 *
 * Notice : this function must be read first when doing nand / msdc boot
 *
 **********************************************************/
static int mboot_android_check_recoveryimg_hdr(char *part_name,
		struct bootimg_hdr *boot_hdr)
{
	int ret = 0;
	long len;
	uint32_t k_pg_cnt = 0;
	uint32_t r_pg_cnt = 0;
	uint32_t dtbo_pg_cnt = 0;
	uint32_t dt_pg_cnt = 0;
	uint32_t pg_sz;


	if (partition_exists(part_name) == PART_NOT_EXIST)
		return -1;

	//***************
	//* read partition header
	//*
	len = partition_read(part_name, 0, (uchar *) boot_hdr,
			     sizeof(struct bootimg_hdr));

	if (len < 0) {
		pal_log_err("[%s] %s Recovery image header read error. LINE: %d\n",
			MODULE_NAME, part_name, __LINE__);
		return -1;
	}

	pal_log_err("\n============================================================\n");
	pal_log_err("[%s] Android Recovery IMG Hdr - Kernel Size    : 0x%08X\n",
		MODULE_NAME, boot_hdr->kernel_sz);
	pal_log_err("[%s] Android Recovery IMG Hdr - Kernel Address : 0x%08X\n",
		MODULE_NAME, boot_hdr->kernel_addr);
	pal_log_err("[%s] Android Recovery IMG Hdr - Rootfs Size    : 0x%08X\n",
		MODULE_NAME, boot_hdr->ramdisk_sz);
	pal_log_err("[%s] Android Recovery IMG Hdr - Rootfs Address : 0x%08X\n",
		MODULE_NAME, boot_hdr->ramdisk_addr);
	pal_log_err("[%s] Android Recovery IMG Hdr - Tags Address   : 0x%08X\n",
		MODULE_NAME, boot_hdr->tags_addr);
	pal_log_err("[%s] Android Recovery IMG Hdr - Page Size      : 0x%08X\n",
		MODULE_NAME, boot_hdr->page_sz);
	pal_log_err("[%s] Android Recovery IMG Hdr - Command Line   : %s\n",
		MODULE_NAME, boot_hdr->cmdline);
	pal_log_err("\n============================================================\n");

	//***************
	//* check partition magic
	//*
	if (strncmp((char const *)boot_hdr->magic, BOOTIMG_MAGIC,
		    BOOTIMG_MAGIC_SZ) != 0) {
		pal_log_err("[%s] Recovery image header magic error\n", MODULE_NAME);
		return -1;
	}

	pg_sz = boot_hdr->page_sz;
	g_pg_sz = boot_hdr->page_sz;

	//***************
	//* follow bootimg.h to calculate the location of rootfs
	//*
	if (len != -1) {
		if (g_is_64bit_kernel)
			g_kmem_off = (uint32_t)target_get_scratch_address();
		else
			g_kmem_off =  boot_hdr->kernel_addr;

		k_pg_cnt = (boot_hdr->kernel_sz + (pg_sz - 1)) / pg_sz;

		r_pg_cnt = (boot_hdr->ramdisk_sz + (pg_sz - 1)) / pg_sz;

		if (boot_hdr->header_version >= BOOT_HEADER_VERSION_ONE)
			dtbo_pg_cnt = (boot_hdr->recovery_dtbo_size + (pg_sz - 1)) / pg_sz;

		if (boot_hdr->header_version >= BOOT_HEADER_VERSION_TWO)
			dt_pg_cnt = (boot_hdr->dtb_size+ (pg_sz - 1)) / pg_sz;

		pal_log_info(" > page count of kernel image = %d\n", k_pg_cnt);
		g_rmem_off = g_kmem_off + k_pg_cnt * pg_sz;

		pal_log_info(" > kernel mem offset = 0x%x\n", g_kmem_off);
		pal_log_info(" > rootfs mem offset = 0x%x\n", g_rmem_off);

		//***************
		//* specify boot image size
		//*
		//g_rcimg_sz = part->start_sect * dev->blkdev->blksz;
		g_rcimg_sz = (k_pg_cnt + r_pg_cnt + dtbo_pg_cnt + dt_pg_cnt + 1) * pg_sz;

		pal_log_info(" > Recovery image size = 0x%x\n", g_rcimg_sz);
	}

	ret = verified_boot_init("recovery", "recovery");
	if (ret)
		return ret;

	return 0;
}

/**********************************************************
 * Routine: mboot_android_load_bootimg_hdr
 *
 * Description: this is the entry function to handle boot image header
 *
 **********************************************************/
int mboot_android_load_bootimg_hdr(char *part_name, uint32_t addr)
{
	long len;
	struct bootimg_hdr *boot_hdr;

	if (partition_exists(part_name) == PART_NOT_EXIST) {
		pal_log_err("mboot_android_load_bootimg_hdr (%s), part = NULL\n",
			part_name);
		return -ENOENT;
	}

	boot_hdr = (struct bootimg_hdr *)malloc(sizeof(struct bootimg_hdr));
	if (!boot_hdr) {
		pal_log_err("mboot_android_load_bootimg_hdr, boot_hdr = NULL\n");
		return -ENOMEM;
	}

	g_boot_hdr = boot_hdr;

	len = mboot_android_check_bootimg_hdr(part_name, boot_hdr);
	platform_parse_bootopt(boot_hdr->cmdline);

	return len;
}

/**********************************************************
 * Routine: mboot_android_load_recoveryimg_hdr
 *
 * Description: this is the entry function to handle Recovery image header
 *
 **********************************************************/
int mboot_android_load_recoveryimg_hdr(char *part_name, uint32_t addr)
{
	long len;
	struct bootimg_hdr *boot_hdr;

	if (partition_exists(part_name) == PART_NOT_EXIST) {
		pal_log_err("mboot_android_load_recoveryimg_hdr (%s), part = NULL\n",
			part_name);
		return -ENOENT;
	}

	boot_hdr = (struct bootimg_hdr *)malloc(sizeof(struct bootimg_hdr));
	if (!boot_hdr) {
		pal_log_err("mboot_android_load_bootimg_hdr, boot_hdr = NULL\n");
		return -ENOMEM;
	}

	g_boot_hdr = boot_hdr;

	len = mboot_android_check_recoveryimg_hdr(part_name, boot_hdr);

	return len;
}

/**********************************************************
 * Routine: mboot_android_load_bootimg
 *
 * Description: main function to load Android Boot Image
 *
 **********************************************************/
int mboot_android_load_bootimg(char *part_name, uint32_t addr)
{
	int ret = 0;
	long len;
	uint64_t start_addr;

	if (partition_exists(part_name) == PART_NOT_EXIST) {
		pal_log_err("mboot_android_load_bootimg , part = NULL\n");
		return -ENOENT;
	}

	//***************
	//* not to include unused header
	//*
	start_addr = partition_get_offset_by_name(part_name);

	/*
	 * check mkimg header
	 */
	pal_log_info("check mkimg header\n");

	len = partition_read(part_name, g_boot_hdr->page_sz, (uchar *)addr,
			     MKIMG_HEADER_SZ);
	if (len < 0) {
		pal_log_err("[%s] %s partition read error. LINE: %d\n", MODULE_NAME,
			part_name, __LINE__);
		return -EIO;
	}

	// check kernel header
	g_kimg_sz = mboot_android_check_img_info(PART_KERNEL, (part_hdr_t *)addr);
	if (g_kimg_sz == -1)
		pal_log_info("no mkimg header in kernel image\n");

	else {
		pal_log_info("mkimg header exist in kernel image\n");
		addr  = addr - MKIMG_HEADER_SZ;
		g_rmem_off = g_rmem_off - MKIMG_HEADER_SZ;
	}

	//***************
	//* read image data
	//*
	pal_log_info("read the data of %s (size = 0x%x)\n", part_name, g_bimg_sz);
	pal_log_info(" > from - 0x%016llx (skip boot img hdr)\n", start_addr);
	pal_log_info(" > to   - 0x%x (starts with kernel img hdr)\n",
		(uint32_t)addr);

	len = partition_read(part_name, g_boot_hdr->page_sz, (uchar *)addr,
			     (size_t)g_bimg_sz);

	// check ramdisk/rootfs header
	g_rimg_sz = mboot_android_check_img_info(PART_ROOTFS, (part_hdr_t *)g_rmem_off);
	if (g_rimg_sz == -1) {
		pal_log_info("no mkimg header in ramdisk image\n");
		g_rimg_sz = g_boot_hdr->ramdisk_sz;
	} else {
		pal_log_info("mkimg header exist in ramdisk image\n");
		g_rmem_off = g_rmem_off + MKIMG_HEADER_SZ;
	}

	if (len < 0) {
		len = -EIO;
		return len;
	}

	ret = verified_boot_flow("boot", addr, g_bimg_sz - g_pg_sz);
	if (ret)
		len = -EIO;

	return len;
}

/**********************************************************
 * Routine: mboot_android_load_recoveryimg
 *
 * Description: main function to load Android Recovery Image
 *
 **********************************************************/
int mboot_android_load_recoveryimg(char *part_name, uint32_t addr)
{
	int ret = 0;
	long len;
	uint64_t start_addr;

	if (partition_exists(part_name) == PART_NOT_EXIST) {
		pal_log_err("mboot_android_load_bootimg , part = NULL\n");
		return -ENOENT;
	}

	//***************
	//* not to include unused header
	//*
	start_addr = partition_get_offset_by_name(part_name);

	/*
	 * check mkimg header
	 */
	pal_log_info("check mkimg header\n");
	len = partition_read(part_name, g_boot_hdr->page_sz, (uchar *)addr,
			     MKIMG_HEADER_SZ);
	if (len < 0) {
		pal_log_err("[%s] %s partition read error. LINE: %d\n", MODULE_NAME,
			part_name, __LINE__);
		return -EIO;
	}

	// check kernel header
	g_kimg_sz = mboot_android_check_img_info(PART_KERNEL, (part_hdr_t *)addr);
	if (g_kimg_sz == -1)
		pal_log_info("no mkimg header in kernel image\n");

	else {
		pal_log_info("mkimg header exist in kernel image\n");
		addr  = addr - MKIMG_HEADER_SZ;
		g_rmem_off = g_rmem_off - MKIMG_HEADER_SZ;
	}

	//***************
	//* read image data
	//*
	pal_log_info("\nread the data of %s (size = 0x%x)\n", part_name, g_rcimg_sz);
	pal_log_info(" > from - 0x%016llx (skip recovery img hdr)\n", start_addr);
	pal_log_info(" > to   - 0x%x (starts with kernel img hdr)\n",
		(uint32_t)addr);

	len = partition_read(part_name, g_boot_hdr->page_sz, (uchar *)addr,
			     (size_t)g_rcimg_sz);

	// check ramdisk/rootfs header
	g_rimg_sz = mboot_android_check_img_info("recovery", (part_hdr_t *)g_rmem_off);
	if (g_rimg_sz == -1) {
		pal_log_info("no mkimg header in recovery image\n");
		g_rimg_sz = g_boot_hdr->ramdisk_sz;
	} else {
		pal_log_info("mkimg header exist in recovery image\n");
		g_rmem_off = g_rmem_off + MKIMG_HEADER_SZ;
	}

	if (len < 0) {
		len = -EIO;
		return len;
	}

	ret = verified_boot_flow("recovery", addr, g_rcimg_sz - g_pg_sz);
	if (ret)
		len = -EIO;

	return len;
}

/**********************************************************
 * Routine: mboot_recovery_load_raw_part
 *
 * Description: load raw data for recovery mode support
 *
 **********************************************************/
int mboot_recovery_load_raw_part(char *part_name, uint32_t *addr,
				 uint32_t size)
{
	long len;
	uint32_t begin;

	if (partition_exists(part_name) == PART_NOT_EXIST)
		return -ENOENT;

	begin = get_timer(0);

	len = partition_read(part_name, 0, (uchar *)addr, (size_t)size);
	if (len < 0) {
		len = -EIO;
		goto exit;
	}

	pal_log_err("[%s] Load '%s' partition to 0x%08x (%d bytes in %ld ms)\n",
		MODULE_NAME, part_name, (uint32_t)addr, size, get_timer(begin));

exit:
	return len;
}

/**********************************************************
 * Routine: mboot_recovery_load_raw_part_offset
 *
 * Description: load partition raw data with offset
 *
 * offset and size must page alignemnt
 **********************************************************/
int mboot_recovery_load_raw_part_offset(char *part_name, uint32_t *addr,
					uint32_t offset, uint32_t size)
{
	long len;
	uint32_t begin;

	begin = get_timer(0);

	len = partition_read(part_name, ROUNDUP(offset, storage_get_blksz()),
			     (uchar *)addr, (size_t)ROUNDUP(size, storage_get_blksz()));

	if (len < 0) {
		len = -EIO;
		goto exit;
	}

	pal_log_info("[%s] Load '%s' partition to 0x%08x (%d bytes in %ld ms)\n",
		MODULE_NAME, part_name, (uint32_t)addr, size, get_timer(begin));

exit:
	return len;
}

/**********************************************************
 * Routine: mboot_recovery_load_misc
 *
 * Description: load recovery command
 *
 **********************************************************/
int mboot_recovery_load_misc(uint32_t *misc_addr, uint32_t size)
{
	int ret;

	pal_log_info("[mboot_recovery_load_misc]: size is %u\n", size);
	pal_log_info("[mboot_recovery_load_misc]: misc_addr is 0x%x\n",
		(uint32_t)misc_addr);

	ret = mboot_recovery_load_raw_part("para", misc_addr, size);

	if (ret < 0)
		return ret;

	return ret;
}

uint32_t mboot_get_img_size(char *part_name, uint32_t *size)
{
	int ret = 0;
	long len = 0;
	struct bootimg_hdr boot_hdr;
	uint16_t page_sz;

	*size = 0;

	if (partition_exists(part_name) == PART_NOT_EXIST) {
		pal_log_err("mboot_android_load_img_hdr (%s), part = NULL\n", part_name);
		return -ENOENT;
	}

	len = partition_read(part_name, (off_t)0, (uchar *)&boot_hdr,
			     sizeof(struct bootimg_hdr));

	if (len < 0) {
		pal_log_err("[%s] %s boot image header read error. LINE: %d\n",
			MODULE_NAME, part_name, __LINE__);
		return -1;
	}

	boot_hdr.magic[7] = '\0';
	pal_log_err("\n============================================================\n");
	pal_log_err("[%s] Android Partition Name             : %s\n", MODULE_NAME,
		part_name);
	pal_log_err("[%s] Android IMG Hdr - Magic            : %s\n", MODULE_NAME,
		boot_hdr.magic);
	pal_log_err("[%s] Android IMG Hdr - Kernel Size      : 0x%08X\n",
		MODULE_NAME, boot_hdr.kernel_sz);
	pal_log_err("[%s] Android IMG Hdr - Kernel Address   : 0x%08X\n",
		MODULE_NAME, boot_hdr.kernel_addr);
	pal_log_err("[%s] Android IMG Hdr - Rootfs Size      : 0x%08X\n",
		MODULE_NAME, boot_hdr.ramdisk_sz);
	pal_log_err("[%s] Android IMG Hdr - Rootfs Address   : 0x%08X\n",
		MODULE_NAME, boot_hdr.ramdisk_addr);
	pal_log_err("[%s] Android IMG Hdr - Tags Address     : 0x%08X\n",
		MODULE_NAME, boot_hdr.tags_addr);
	pal_log_err("[%s] Android IMG Hdr - Page Size        : 0x%08X\n",
		MODULE_NAME, boot_hdr.page_sz);
	pal_log_err("[%s] Android IMG Hdr - Command Line     : %s\n", MODULE_NAME,
		boot_hdr.cmdline);
	pal_log_err("\n============================================================\n");

	page_sz = boot_hdr.page_sz;
	*size +=  page_sz; /* boot header size is 1 page*/
	*size += (((boot_hdr.kernel_sz + page_sz - 1) / page_sz) * page_sz);
	*size += (((boot_hdr.ramdisk_sz + page_sz - 1) / page_sz) * page_sz);
	*size += (((boot_hdr.second_sz + page_sz - 1) / page_sz) * page_sz);
	if (boot_hdr.header_version >= BOOT_HEADER_VERSION_ONE)
		*size += (((boot_hdr.recovery_dtbo_size + page_sz - 1) / page_sz) * page_sz);
	if (boot_hdr.header_version >= BOOT_HEADER_VERSION_TWO)
		*size += (((boot_hdr.dtb_size + page_sz - 1) / page_sz) * page_sz);

	return ret;
}

