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
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <bootimg.h>
#include <platform/errno.h>
#include <platform/verified_boot.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>
#include <platform/mt_gpt.h>
#include <platform/sec_status.h>
#include <platform/mtk_key.h>
#include <target/cust_key.h>
#include <part_interface.h>
// #include <block_generic_interface.h>    // for mt_part_get_device()
#include <storage_api.h>
#include <target.h>                     // for target_get_scratch_address()
#include <verified_boot_common.h>
#include <boot_opt.h>
#include <odm_mdtbo.h>

#define MODULE_NAME "LK_BOOT"

// From proinfo which is defined in PC side META tool spmeta.h.
#define PARTITION_SIZE (64 + 40 + 6 + 6)

//*********
//* Notice : it's kernel start addr (and not include any debug header)
unsigned int g_kmem_off = 0;

//*********
//* Notice : it's rootfs start addr (and not include any debug header)
unsigned int g_rmem_off = 0;

unsigned int g_bimg_sz = 0;
unsigned int g_rcimg_sz = 0;
int g_kimg_sz = 0;
int g_rimg_sz = 0;

#define DTBO_IMG_ALIGN_SZ (16)

extern struct bootimg_hdr *g_boot_hdr;
extern bool cmdline_append(const char *append_string);
extern void mtk_wdt_restart(void);

#define BigtoLittle32(A) ((( (uint32)(A) & 0xff000000) >> 24) | \
			  (( (uint32)(A) & 0x00ff0000) >> 8)  | \
			  (( (uint32)(A) & 0x0000ff00) << 8)  | \
			  (( (uint32)(A) & 0x000000ff) << 24))

int verified_boot_flow(char *part_name, char *target)
{
	int ret = 0;
	unsigned int img_vfy_time = 0;
	int lock_state = 0;

	/* if MTK_SECURITY_SW_SUPPORT is not defined, boot state is always green */
#ifdef MTK_SECURITY_SW_SUPPORT
	/* please refer to the following website for verified boot flow */
	/* http://source.android.com/devices/tech/security/verifiedboot/verified-boot.html */
	ret = sec_query_device_lock(&lock_state);
	if (ret) {
		g_boot_state = BOOT_STATE_RED;
		goto _end;
	}

	if (DEVICE_STATE_LOCKED == lock_state) {
		if (g_boot_state == BOOT_STATE_GREEN)
			goto _end;

		sec_clear_pubk();
		g_boot_state = BOOT_STATE_GREEN;
		img_vfy_time = get_timer(0);

		ret = android_verified_boot(part_name, target);
		if (0 == ret)
			g_boot_state = BOOT_STATE_GREEN;
		else if (ERR_NOT_OEM_KEY == ret)
			g_boot_state = BOOT_STATE_YELLOW;
		else {
			g_boot_state = BOOT_STATE_RED;
			sec_clear_pubk();
		}
		dprintf(INFO, "[SBC] img vfy(%d ms)\n", (unsigned int)get_timer(img_vfy_time));
	} else if (DEVICE_STATE_UNLOCKED == lock_state)
		g_boot_state = BOOT_STATE_ORANGE;

	else   /* unknown lock state*/
		g_boot_state = BOOT_STATE_RED;
#endif //MTK_SECURITY_SW_SUPPORT

_end:
	ret = print_boot_state();
	if (ret)
		return ret;

	if (target == NULL)
		ret = show_warning("UNKNOWN");
	else
		ret = show_warning(target);
	if (ret)
		return ret;

	ret = set_boot_state_to_cmdline();
	if (ret)
		return ret;

	return ret;
}

static int mboot_common_load_part_info(char *part_name,
				       part_hdr_t *part_hdr)
{
	long len;
	// part_t *part;

	//***************
	//* read partition header
	//*
	len = partition_read(part_name, 0, (uchar *)part_hdr, sizeof(part_hdr_t));

	if (len < 0) {
		dprintf(CRITICAL, "[%s] %s partition read error. LINE: %d\n", MODULE_NAME,
			part_name, __LINE__);
		return -1;
	}

	dprintf(CRITICAL, "\n=========================================\n");
	dprintf(CRITICAL, "[%s] %s magic number : 0x%x\n", MODULE_NAME, part_name,
		part_hdr->info.magic);
	part_hdr->info.name[31] = '\0'; //append end char
	dprintf(CRITICAL, "[%s] %s name         : %s\n", MODULE_NAME, part_name,
		part_hdr->info.name);
	dprintf(CRITICAL, "[%s] %s size         : %d\n", MODULE_NAME, part_name,
		part_hdr->info.dsize);
	dprintf(CRITICAL, "=========================================\n");

	//***************
	//* check partition magic
	//*
	if (part_hdr->info.magic != PART_MAGIC) {
		dprintf(CRITICAL, "[%s] %s partition magic error\n", MODULE_NAME, part_name);
		return -1;
	}

	//***************
	//* check partition name
	//*
	if (strncasecmp(part_hdr->info.name, part_name, sizeof(part_hdr->info.name))) {
		dprintf(CRITICAL, "[%s] %s partition name error\n", MODULE_NAME, part_name);
		return -1;
	}

	//***************
	//* check partition data size
	//*
	if (part_hdr->info.dsize > partition_get_size_by_name(part_name)) {
		dprintf(CRITICAL, "[%s] %s partition size error\n", MODULE_NAME, part_name);
		return -1;
	}

	return 0;
}


/**********************************************************
 * Routine: mboot_common_load_part
 *
 * Description: common function for loading image from nand flash
 *              this function is called by
 *                  (1) 'mboot_common_load_logo' to display logo
 *
 **********************************************************/
int mboot_common_load_part(char *part_name, unsigned long addr)
{
	long len;
	part_hdr_t *part_hdr;

	part_hdr = (part_hdr_t *)malloc(sizeof(part_hdr_t));

	if (!part_hdr)
		return -ENOMEM;

	len = mboot_common_load_part_info(part_name, part_hdr);
	if (len < 0) {
		len = -EINVAL;
		goto exit;
	}


	//****************
	//* read image data
	//*
	dprintf(INFO, "read the data of %s\n", part_name);

	len = partition_read(part_name, sizeof(part_hdr_t), (uchar *)addr,
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
int mboot_common_load_logo(unsigned long logo_addr, char *filename)
{
	int ret;
#if (CONFIG_COMMANDS & CFG_CMD_FAT)
	long len;
#endif

#if (CONFIG_COMMANDS & CFG_CMD_FAT)
	len = file_fat_read(filename, (unsigned char *)logo_addr, 0);

	if (len > 0)
		return (int)len;
#endif

	ret = mboot_common_load_part("logo", logo_addr);

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
		dprintf(CRITICAL, "[%s] %s partition magic not match\n", MODULE_NAME,
			part_name);
		return -1;
	}

	//***************
	//* check partition name
	//*
	if (strncasecmp(part_hdr->info.name, part_name, sizeof(part_hdr->info.name))) {
		dprintf(CRITICAL, "[%s] %s partition name not match\n", MODULE_NAME, part_name);
		return -1;
	}

	dprintf(CRITICAL, "\n=========================================\n");
	dprintf(CRITICAL, "[%s] %s magic number : 0x%x\n", MODULE_NAME, part_name,
		part_hdr->info.magic);
	dprintf(CRITICAL, "[%s] %s size         : 0x%x\n", MODULE_NAME, part_name,
		part_hdr->info.dsize);
	dprintf(CRITICAL, "=========================================\n");

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
static int mboot_android_check_bootimg_hdr( char *part_name,
		struct bootimg_hdr *boot_hdr)
{
	long len;
	int ret = 0;
	u64 addr;
	//**********************************
	// TODO : fix pg_sz assignment
	//**********************************
	unsigned int pg_sz = 2 * 1024;

	addr = partition_get_offset_by_name(part_name);

	//***************
	//* read partition header
	//*

	dprintf(CRITICAL, "part page addr is 0x%llx\n", addr);

	len = partition_read(part_name, 0, (uchar *) boot_hdr, sizeof(struct bootimg_hdr));

	if (len < 0) {
		dprintf(CRITICAL, "[%s] %s boot image header read error. LINE: %d\n",
			MODULE_NAME, part_name, __LINE__);
		return -1;
	}

	dprintf(CRITICAL,
		"\n============================================================\n");
	dprintf(CRITICAL, "[%s] Android Partition Name                : %s\n",
		MODULE_NAME, part_name);
	dprintf(CRITICAL, "[%s] Android Boot IMG Hdr - OS Version     : 0x%08X\n",
		MODULE_NAME, boot_hdr->os_version);
	dprintf(CRITICAL, "[%s] Android Boot IMG Hdr - Kernel Size    : 0x%08X\n",
		MODULE_NAME, boot_hdr->kernel_sz);
	dprintf(CRITICAL, "[%s] Android Boot IMG Hdr - Kernel Address : 0x%08X\n",
		MODULE_NAME, boot_hdr->kernel_addr);
	dprintf(CRITICAL, "[%s] Android Boot IMG Hdr - Rootfs Size    : 0x%08X\n",
		MODULE_NAME, boot_hdr->ramdisk_sz);
	dprintf(CRITICAL, "[%s] Android Boot IMG Hdr - Rootfs Address : 0x%08X\n",
		MODULE_NAME, boot_hdr->ramdisk_addr);
	dprintf(CRITICAL, "[%s] Android Boot IMG Hdr - Tags Address   : 0x%08X\n",
		MODULE_NAME, boot_hdr->tags_addr);
	dprintf(CRITICAL, "[%s] Android Boot IMG Hdr - Page Size      : 0x%08X\n",
		MODULE_NAME, boot_hdr->page_sz);
	dprintf(CRITICAL, "[%s] Android Boot IMG Hdr - Command Line   : %s\n",
		MODULE_NAME, boot_hdr->cmdline);
	dprintf(CRITICAL,
		"============================================================\n");

	//***************
	//* check partition magic
	//*
	if (strncmp((char const *)boot_hdr->magic, BOOTIMG_MAGIC, BOOTIMG_MAGIC_SZ) != 0) {
		dprintf(CRITICAL, "[%s] boot image header magic error\n", MODULE_NAME);
		return -1;
	}

	pg_sz = boot_hdr->page_sz;

	//***************
	//* follow bootimg.h to calculate the location of rootfs
	//*
	if (len != -1) {
		unsigned int k_pg_cnt = 0;
		unsigned int r_pg_cnt = 0;
		unsigned int dtbo_pg_cnt = 0;
		unsigned int dt_pg_cnt = 0;
		if (g_is_64bit_kernel)
			g_kmem_off = (unsigned int)target_get_scratch_address();

		else
			g_kmem_off = boot_hdr->kernel_addr;

		k_pg_cnt = (boot_hdr->kernel_sz + (pg_sz - 1)) / pg_sz;
		r_pg_cnt = (boot_hdr->ramdisk_sz + (pg_sz - 1)) / pg_sz;
		if (boot_hdr->header_version >= BOOT_HEADER_VERSION_ONE)
			dtbo_pg_cnt = (boot_hdr->recovery_dtbo_size + (pg_sz - 1)) / pg_sz;

		if (boot_hdr->header_version >= BOOT_HEADER_VERSION_TWO)
			dt_pg_cnt = (boot_hdr->dtb_size + (pg_sz - 1)) / pg_sz;

		dprintf(INFO, " > page count of kernel image = %d\n", k_pg_cnt);
		g_rmem_off = g_kmem_off + k_pg_cnt * pg_sz;

		dprintf(INFO, " > kernel mem offset = 0x%x\n", g_kmem_off);
		dprintf(INFO, " > rootfs mem offset = 0x%x\n", g_rmem_off);


		//***************
		//* specify boot image size
		//*
		g_bimg_sz = (k_pg_cnt + r_pg_cnt + dtbo_pg_cnt + dt_pg_cnt + 1) * pg_sz;

		dprintf(INFO, " > boot image size = 0x%x\n", g_bimg_sz);

		ret = verified_boot_flow("boot", "/boot");
		if (ret) {
			len = -1;
			return len;
		}
	}

	return len;
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

	//**********************************
	// TODO : fix pg_sz assignment
	//**********************************
	unsigned int pg_sz = 2 * 1024;

	//***************
	//* read partition header
	//*
	len = partition_read(part_name, 0, (uchar *) boot_hdr, sizeof(struct bootimg_hdr));

	if (len < 0) {
		dprintf(CRITICAL, "[%s] %s Recovery image header read error. LINE: %d\n",
			MODULE_NAME, part_name, __LINE__);
		return -1;
	}

	dprintf(CRITICAL,
		"\n============================================================\n");
	dprintf(CRITICAL, "[%s] Android Recovery IMG Hdr - Magic          : 0x%08X\n",
		MODULE_NAME, boot_hdr->magic);
	dprintf(CRITICAL, "[%s] Android Recovery IMG Hdr - OS Version     : 0x%08X\n",
		MODULE_NAME, boot_hdr->os_version);
	dprintf(CRITICAL, "[%s] Android Recovery IMG Hdr - Kernel Size    : 0x%08X\n",
		MODULE_NAME, boot_hdr->kernel_sz);
	dprintf(CRITICAL, "[%s] Android Recovery IMG Hdr - Kernel Address : 0x%08X\n",
		MODULE_NAME, boot_hdr->kernel_addr);
	dprintf(CRITICAL, "[%s] Android Recovery IMG Hdr - Rootfs Size    : 0x%08X\n",
		MODULE_NAME, boot_hdr->ramdisk_sz);
	dprintf(CRITICAL, "[%s] Android Recovery IMG Hdr - Rootfs Address : 0x%08X\n",
		MODULE_NAME, boot_hdr->ramdisk_addr);
	dprintf(CRITICAL, "[%s] Android Recovery IMG Hdr - Tags Address   : 0x%08X\n",
		MODULE_NAME, boot_hdr->tags_addr);
	dprintf(CRITICAL, "[%s] Android Recovery IMG Hdr - Page Size      : 0x%08X\n",
		MODULE_NAME, boot_hdr->page_sz);
	dprintf(CRITICAL, "[%s] Android Recovery IMG Hdr - Command Line   : %s\n",
		MODULE_NAME, boot_hdr->cmdline);
	dprintf(CRITICAL,
		"============================================================\n");

	//***************
	//* check partition magic
	//*
	if (strncmp((char const *)boot_hdr->magic, BOOTIMG_MAGIC, BOOTIMG_MAGIC_SZ) != 0) {
		dprintf(CRITICAL, "[%s] Recovery image header magic error\n", MODULE_NAME);
		return -1;
	}

	pg_sz = boot_hdr->page_sz;

	//***************
	//* follow bootimg.h to calculate the location of rootfs
	//*
	if (len != -1) {
		unsigned int k_pg_cnt = 0;
		unsigned int r_pg_cnt = 0;
		unsigned int dtbo_pg_cnt = 0;
		unsigned int dt_pg_cnt = 0;
		if (g_is_64bit_kernel)
			g_kmem_off = (unsigned int)target_get_scratch_address();
		else
			g_kmem_off = boot_hdr->kernel_addr;

		k_pg_cnt = (boot_hdr->kernel_sz + (pg_sz - 1)) / pg_sz;
		r_pg_cnt = (boot_hdr->ramdisk_sz + (pg_sz - 1)) / pg_sz;
		if (boot_hdr->header_version >= BOOT_HEADER_VERSION_ONE)
			dtbo_pg_cnt = (boot_hdr->recovery_dtbo_size + (pg_sz - 1)) / pg_sz;

		if (boot_hdr->header_version >= BOOT_HEADER_VERSION_TWO)
			dt_pg_cnt = (boot_hdr->dtb_size+ (pg_sz - 1)) / pg_sz;

		dprintf(INFO, " > page count of kernel image = %d\n", k_pg_cnt);
		g_rmem_off = g_kmem_off + k_pg_cnt * pg_sz;

		dprintf(INFO, " > kernel mem offset = 0x%x\n", g_kmem_off);
		dprintf(INFO, " > rootfs mem offset = 0x%x\n", g_rmem_off);


		//***************
		//* specify boot image size
		//*
		//g_rcimg_sz = part->start_sect * BLK_SIZE;
		g_rcimg_sz = (k_pg_cnt + r_pg_cnt + dtbo_pg_cnt + dt_pg_cnt + 1) * pg_sz;

		dprintf(INFO, " > Recovery image size = 0x%x\n", g_rcimg_sz);

		ret = verified_boot_flow("recovery", "/recovery");
		if (ret) {
			len = -1;
			return len;
		}
	}

	return len;
}

/**********************************************************
 * Routine: mboot_android_load_bootimg_hdr
 *
 * Description: this is the entry function to handle boot image header
 *
 **********************************************************/
int mboot_android_load_bootimg_hdr(char *part_name, unsigned long addr)
{
	long len;
	struct bootimg_hdr *boot_hdr;


	boot_hdr = (struct bootimg_hdr *)malloc(sizeof(struct bootimg_hdr));
	if (!boot_hdr) {
		dprintf(CRITICAL, "mboot_android_load_bootimg_hdr, boot_hdr = NULL\n");
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
int mboot_android_load_recoveryimg_hdr(char *part_name, unsigned long addr)
{
	long len;
	struct bootimg_hdr *boot_hdr;


	boot_hdr = (struct bootimg_hdr *)malloc(sizeof(struct bootimg_hdr));
	if (!boot_hdr) {
		dprintf(CRITICAL, "mboot_android_load_bootimg_hdr, boot_hdr = NULL\n");
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
int mboot_android_load_bootimg(char *part_name, unsigned long addr)
{
	long len;
	unsigned long long start_addr;
	//***************
	//* not to include unused header
	//*
	start_addr = partition_get_offset_by_name(part_name) + g_boot_hdr->page_sz;

	/*
	 * check mkimg header
	 */
	dprintf(INFO, "check mkimg header\n");

	len = partition_read(part_name, g_boot_hdr->page_sz, (uchar *)addr,
			     MKIMG_HEADER_SZ);
	if (len < 0) {
		dprintf(CRITICAL, "[%s] %s partition read error. LINE: %d\n", MODULE_NAME,
			part_name, __LINE__);
		return -EIO;
	}

	// check kernel header
	g_kimg_sz = mboot_android_check_img_info(PART_KERNEL, (part_hdr_t *)addr);
	if (g_kimg_sz == -1)
		dprintf(INFO, "no mkimg header in kernel image\n");

	else {
		dprintf(INFO, "mkimg header exist in kernel image\n");
		addr  = addr - MKIMG_HEADER_SZ;
		g_rmem_off = g_rmem_off - MKIMG_HEADER_SZ;
	}

	//***************
	//* read image data
	//*
	dprintf(INFO, "\nread the data of %s (size = 0x%x)\n", part_name, g_bimg_sz);
	dprintf(INFO, " > from - 0x%016llx (skip boot img hdr)\n", start_addr);
	dprintf(INFO, " > to   - 0x%x (starts with kernel img hdr)\n",
		(unsigned int)addr);

	len = partition_read(part_name, g_boot_hdr->page_sz, (uchar *)addr,
			     (size_t)g_bimg_sz);

	// check ramdisk/rootfs header
	g_rimg_sz = mboot_android_check_img_info(PART_ROOTFS, (part_hdr_t *)g_rmem_off);
	if (g_rimg_sz == -1) {
		dprintf(INFO, "no mkimg header in ramdisk image\n");
		g_rimg_sz = g_boot_hdr->ramdisk_sz;
	} else {
		dprintf(INFO, "mkimg header exist in ramdisk image\n");
		g_rmem_off = g_rmem_off + MKIMG_HEADER_SZ;
	}

	if (len < 0)
		len = -EIO;

	return len;
}

/**********************************************************
 * Routine: mboot_android_load_recoveryimg
 *
 * Description: main function to load Android Recovery Image
 *
 **********************************************************/
int mboot_android_load_recoveryimg(char *part_name, unsigned long addr)
{
	long len;
	unsigned long long start_addr;
	//***************
	//* not to include unused header
	//*
	start_addr = partition_get_offset_by_name(part_name) + g_boot_hdr->page_sz;

	/*
	 * check mkimg header
	 */
	dprintf(INFO, "check mkimg header\n");
	len = partition_read(part_name, g_boot_hdr->page_sz, (uchar *)addr,
			     MKIMG_HEADER_SZ);
	if (len < 0) {
		dprintf(CRITICAL, "[%s] %s partition read error. LINE: %d\n", MODULE_NAME,
			part_name, __LINE__);
		return -EIO;
	}

	// check kernel header
	g_kimg_sz = mboot_android_check_img_info(PART_KERNEL, (part_hdr_t *)addr);
	if (g_kimg_sz == -1)
		dprintf(INFO, "no mkimg header in kernel image\n");

	else {
		dprintf(INFO, "mkimg header exist in kernel image\n");
		addr  = addr - MKIMG_HEADER_SZ;
		g_rmem_off = g_rmem_off - MKIMG_HEADER_SZ;
	}

	//***************
	//* read image data
	//*
	dprintf(INFO, "\nread the data of %s (size = 0x%x)\n", part_name, g_rcimg_sz);
	dprintf(INFO, " > from - 0x%016llx (skip recovery img hdr)\n", start_addr);
	dprintf(INFO, " > to   - 0x%x (starts with kernel img hdr)\n",
		(unsigned int)addr);

	len = partition_read(part_name, g_boot_hdr->page_sz, (uchar *)addr,
			     (size_t)g_rcimg_sz);

	// check ramdisk/rootfs header
	g_rimg_sz = mboot_android_check_img_info("recovery", (part_hdr_t *)g_rmem_off);
	if (g_rimg_sz == -1) {
		dprintf(INFO, "no mkimg header in recovery image\n");
		g_rimg_sz = g_boot_hdr->ramdisk_sz;
	} else {
		dprintf(INFO, "mkimg header exist in recovery image\n");
		g_rmem_off = g_rmem_off + MKIMG_HEADER_SZ;
	}

	if (len < 0)
		len = -EIO;

	return len;
}

/**********************************************************
 * Routine: mboot_recovery_load_raw_part
 *
 * Description: load raw data for recovery mode support
 *
 **********************************************************/
int mboot_recovery_load_raw_part(char *part_name, unsigned long *addr,
				 unsigned int size)
{
	long len;
	unsigned long begin;

	begin = get_timer(0);

#ifdef NON_ZERO_OFFSET_PROINFO_FORMAT
	if (strcmp(part_name, "proinfo") == 0)
		len = partition_read(part_name, PARTITION_SIZE, (uchar*)addr, (size_t)size);
	else
#endif  // NON_ZERO_OFFSET_PROINFO_FORMAT
		len = partition_read(part_name, 0, (uchar *)addr, (size_t)size);
	if (len < 0) {
		len = -EIO;
		goto exit;
	}

	dprintf(CRITICAL, "[%s] Load '%s' partition to 0x%08lX (%d bytes in %ld ms)\n",
		MODULE_NAME, part_name, (unsigned long)addr, size, get_timer(begin));

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
int mboot_recovery_load_raw_part_offset(char *part_name, unsigned long *addr,
					unsigned long offset, unsigned int size)
{
	long len;
	unsigned long begin;
	int blksz = storage_get_blksz();

	begin = get_timer(0);

#ifdef NON_ZERO_OFFSET_PROINFO_FORMAT
	if (strcmp(part_name, "proinfo") == 0)
		len = partition_read(part_name, PARTITION_SIZE, (uchar*)addr, (size_t)size);
	else
#endif  // NON_ZERO_OFFSET_PROINFO_FORMAT
       len = partition_read(part_name, ROUNDUP(offset, blksz), (uchar *)addr, ROUNDUP(size, blksz));

	if (len < 0) {
		len = -EIO;
		goto exit;
	}

	dprintf(INFO, "[%s] Load '%s' partition to 0x%08lX (%d bytes in %ld ms)\n",
		MODULE_NAME, part_name, (unsigned long)addr, size, get_timer(begin));

exit:
	return len;
}

/**********************************************************
 * Routine: mboot_recovery_load_misc
 *
 * Description: load recovery command
 *
 **********************************************************/
int mboot_recovery_load_misc(unsigned long *misc_addr, unsigned int size)
{
	int ret;

	dprintf(INFO, "[mboot_recovery_load_misc]: size is %u\n", size);
	dprintf(INFO, "[mboot_recovery_load_misc]: misc_addr is 0x%x\n",
		(unsigned int)misc_addr);

	ret = mboot_recovery_load_raw_part("para", misc_addr, size);

	if (ret < 0)
		return ret;

	return ret;
}

/**********************************************************
 * Routine: mboot_get_dtbo_img_size
 *
 * Description: Get img size from dtbo header
 The size include both image and header and the size is align to 16 bytes.
 *
 **********************************************************/
unsigned int mboot_get_dtbo_img_size(char *part_name, unsigned int *size)
{
	unsigned int ret = 0 ;
	long len = 0;
	struct dt_table_header dtboimg_hdr;

	if (part_name == NULL)
		return -ENOENT;

	if (size == NULL)
		return -ENOENT;

	*size = 0;

	len = partition_read(part_name, (off_t)0, (uchar *)&dtboimg_hdr,
			     sizeof(struct dt_table_header));

	if (len < 0) {
		dprintf(CRITICAL, "[%s] partition %s not found, LINE: %d\n", MODULE_NAME,
							part_name, __LINE__);
		return -ENOENT;
	}

	*size = BigtoLittle32(dtboimg_hdr.total_size);

	dprintf(CRITICAL,
		"\n============================================================\n");
	dprintf(CRITICAL, "[%s] Partition Name\t\t\t: %s\n", MODULE_NAME, part_name);
	dprintf(CRITICAL, "[%s] Header Magic\t\t\t: %x\n", MODULE_NAME, dtboimg_hdr.magic);
	dprintf(CRITICAL, "[%s] IMG size\t\t\t\t: %x\n", MODULE_NAME, *size);
	dprintf(CRITICAL,
		"============================================================\n");

	*size = ROUNDUP((*size), DTBO_IMG_ALIGN_SZ);
	dprintf(CRITICAL, "[%s] IMG align size\t\t\t: %x\n", MODULE_NAME, *size);

	return ret;
}

/**********************************************************
 * Routine: mboot_get_inhouse_img_size
 *
 * Description: Get img size from mkimage header (LK,Logo)
 The size include both image and header and the size is align to 4k.
 *
 **********************************************************/
unsigned int mboot_get_inhouse_img_size(char *part_name, unsigned int *size)
{
	int ret = 0;
	long len = 0;
	part_hdr_t mkimage_hdr;
	unsigned page_sz = 0x1000;

	*size = 0;

	dprintf(CRITICAL, "Get inhouse img size from mkimage header\n");

	/*Read mkimage header*/
	len = partition_read(part_name, (off_t)0, (uchar *)&mkimage_hdr,
			     (size_t)sizeof(part_hdr_t));
	if (len < 0) {
		dprintf(CRITICAL, "[%s] %s partition read error. LINE: %d\n", MODULE_NAME,
			part_name, __LINE__);
		return -EIO;
	}

	dprintf(CRITICAL,
		"\n============================================================\n");
	dprintf(CRITICAL, "[%s] INHOUSE Partition Name             : %s\n", MODULE_NAME,
		part_name);
	dprintf(CRITICAL, "[%s] INHOUSE IMG HDR - Magic            : %x\n", MODULE_NAME,
		mkimage_hdr.info.magic);
	dprintf(CRITICAL, "[%s] INHOUSE IMG size                    : %x\n",
		MODULE_NAME, mkimage_hdr.info.dsize);
	dprintf(CRITICAL, "[%s] INHOUSE IMG HDR size                : %x\n",
		MODULE_NAME, sizeof(part_hdr_t));
	dprintf(CRITICAL,
		"============================================================\n");

	*size = (((mkimage_hdr.info.dsize + sizeof(part_hdr_t)  + page_sz - 1) /
		  page_sz) * page_sz);
	dprintf(CRITICAL, "[%s] INHOUSE IMG size           : %x\n", MODULE_NAME, *size);

	return ret;

}

unsigned int mboot_get_bootimg_size(char *part_name, unsigned int *size)
{
	int ret = 0;
	long len = 0;
	struct bootimg_hdr boot_hdr;
	/* use starting 16 bytes to get boot sig size */
	/* actual boot signature size is much bigger */
#define BOOT_SIG_HDR_SZ 16
	unsigned char boot_sig_hdr[BOOT_SIG_HDR_SZ] = {0};
	unsigned boot_sig_size = 0;
	unsigned page_sz =
		0x800; /* used to cache page size in boot image hdr, default 2KB */

	*size = 0;

	len = partition_read(part_name, (off_t)0, (uchar *)&boot_hdr,
			     sizeof(struct bootimg_hdr));
	if (len < 0) {
		dprintf(CRITICAL, "[%s] %s boot image header read error. LINE: %d\n",
			MODULE_NAME, part_name, __LINE__);
		return -1;
	}

	boot_hdr.magic[7] = '\0';
	dprintf(CRITICAL,
		"\n============================================================\n");
	dprintf(CRITICAL, "[%s] Android Partition Name             : %s\n", MODULE_NAME,
		part_name);
	dprintf(CRITICAL, "[%s] Android IMG Hdr - Magic            : %s\n", MODULE_NAME,
		boot_hdr.magic);
	dprintf(CRITICAL, "[%s] Android IMG Hdr - Kernel Size      : 0x%08X\n",
		MODULE_NAME, boot_hdr.kernel_sz);
	dprintf(CRITICAL, "[%s] Android IMG Hdr - Kernel Address   : 0x%08X\n",
		MODULE_NAME, boot_hdr.kernel_addr);
	dprintf(CRITICAL, "[%s] Android IMG Hdr - Rootfs Size      : 0x%08X\n",
		MODULE_NAME, boot_hdr.ramdisk_sz);
	dprintf(CRITICAL, "[%s] Android IMG Hdr - Rootfs Address   : 0x%08X\n",
		MODULE_NAME, boot_hdr.ramdisk_addr);
	dprintf(CRITICAL, "[%s] Android IMG Hdr - Tags Address     : 0x%08X\n",
		MODULE_NAME, boot_hdr.tags_addr);
	dprintf(CRITICAL, "[%s] Android IMG Hdr - Page Size        : 0x%08X\n",
		MODULE_NAME, boot_hdr.page_sz);
	dprintf(CRITICAL, "[%s] Android IMG Hdr - Command Line     : %s\n", MODULE_NAME,
		boot_hdr.cmdline);
	dprintf(CRITICAL,
		"============================================================\n");

	page_sz = boot_hdr.page_sz;
	*size +=  page_sz; /* boot header size is 1 page*/
	*size += (((boot_hdr.kernel_sz + page_sz - 1) / page_sz) * page_sz);
	*size += (((boot_hdr.ramdisk_sz + page_sz - 1) / page_sz) * page_sz);
	*size += (((boot_hdr.second_sz + page_sz - 1) / page_sz) * page_sz);
	if (boot_hdr.header_version >= BOOT_HEADER_VERSION_ONE)
		*size += (((boot_hdr.recovery_dtbo_size + page_sz - 1) / page_sz) * page_sz);
	if (boot_hdr.header_version >= BOOT_HEADER_VERSION_TWO)
		*size += (((boot_hdr.dtb_size + page_sz - 1) / page_sz) * page_sz);

	/* try to get boot siganture size if it exists */
	len = partition_read(part_name, (off_t)(*size), (uchar *)&boot_sig_hdr,
			     (size_t)BOOT_SIG_HDR_SZ);
	if (len < 0) {
		dprintf(CRITICAL, "[%s] %s boot sig header read error. LINE: %d\n", MODULE_NAME,
			part_name, __LINE__);
		return -1;
	}

	/* in case boot image is signed by boot signer */
#define ASN_ID_SEQUENCE  0x30
	if (boot_sig_hdr[0] == ASN_ID_SEQUENCE) {
		/* boot signature exists */
		unsigned len = 0;
		unsigned len_size = 0;
		if (boot_sig_hdr[1] & 0x80) {
			/* multi-byte length field */
			unsigned int i = 0;
			len_size = 1 + (boot_sig_hdr[1] & 0x7f);
			for (i = 0; i < len_size - 1; i++)
				len = (len << 8) | boot_sig_hdr[2 + i];
		} else {
			/* single-byte length field */
			len_size = 1;
			len = boot_sig_hdr[1];
		}

		boot_sig_size = 1 + len_size + len;
	}
	*size += (((boot_sig_size + page_sz - 1) / page_sz) * page_sz);

	return ret;
}

unsigned int mboot_get_img_size(char *part_name, unsigned int *size)
{
	int ret = 0;
	struct bootimg_hdr *boot_hdr = NULL;
	struct dt_table_header *dtboimg_hdr = NULL;
	uint8_t hdr[sizeof(struct bootimg_hdr)] = {0};
	*size = 0;

	long len = partition_read(part_name, (off_t)0, hdr,
				  sizeof(struct bootimg_hdr));
	if (len < 0) {
		dprintf(CRITICAL, "[%s] Error reading %s! LINE: %d\n", MODULE_NAME, part_name,
			__LINE__);
		return -1;
	}

	boot_hdr = (struct bootimg_hdr *)hdr;
	dtboimg_hdr = (struct dt_table_header *)hdr;

	if (!memcmp(boot_hdr->magic, BOOTIMG_MAGIC, BOOTIMG_MAGIC_SZ))
		return mboot_get_bootimg_size(part_name, size);
	else if (dtboimg_hdr->magic == BigtoLittle32(DT_TABLE_MAGIC))
		return mboot_get_dtbo_img_size(part_name, size);
	else
		return mboot_get_inhouse_img_size(part_name, size);

	return ret;
}

