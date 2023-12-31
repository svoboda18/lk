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

#include <sys/types.h>
#include <stdint.h>
#include <platform/partition.h>
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>
#include <libfdt.h>
#include <platform/mt_gpt.h>
#include <platform/sec_export.h>
#include <debug.h>
#include "ccci_ld_md_core.h"
#include "ccci_ld_md_errno.h"
#include "ccci_ld_md_tel.h"
#ifdef MBLOCK_LIB_SUPPORT
#include <mblock.h>
#endif
#ifdef MTK_AB_OTA_UPDATER
#include "bootctrl.h"
#endif
#include <assert.h>
#include <block_generic_interface.h>
#include <img_info.h>

#define MODULE_NAME "LK_LD_MD"
/***************************************************************************************************
* Quick search pattern:
* 1. Download list
***************************************************************************************************/


/***************************************************************************************************
** Sub sectoin:
**   modem info
***************************************************************************************************/
static modem_info_t s_g_md_ld_status[MAX_MD_NUM];
static int s_g_md_ld_record_num;

static void add_hdr_info(modem_info_t tbl[], modem_info_t *hdr)
{
	tbl[s_g_md_ld_record_num].base_addr = hdr->base_addr;
	tbl[s_g_md_ld_record_num].resv_mem_size = hdr->resv_mem_size;
	tbl[s_g_md_ld_record_num].errno = hdr->errno;
	tbl[s_g_md_ld_record_num].md_id = hdr->md_id;
	tbl[s_g_md_ld_record_num].ver = 0;
	tbl[s_g_md_ld_record_num].md_type = hdr->md_type;
	tbl[s_g_md_ld_record_num].load_size = hdr->load_size;
	tbl[s_g_md_ld_record_num].ro_rw_size = hdr->ro_rw_size;
	s_g_md_ld_record_num++;
}

/***************************************************************************************************
** Sub section:
**   String to unsigned int lib function, pure software code
***************************************************************************************************/
unsigned int str2uint(char *str)
{
	/* max 32bit integer is 4294967296, buf[16] is enough */
	char buf[16];
	int i;
	int num;
	int base = 10;
	int ret_val;
	if (NULL == str)
		return 0;

	i = 0;
	while (i<16) {
		/* Format it */
		if ((str[i] == 'X') || (str[i] == 'x')) {
			buf[i] = 'x';
			if (i != 1)
				return 0; /* not 0[x]XXXXXXXX */
			else if (buf[0] != '0')
				return 0; /* not [0]xXXXXXXXX */
			else
				base = 16;
		} else if ((str[i] >= '0') && (str[i] <= '9'))
			buf[i] = str[i];
		else if ((str[i] >= 'a') && (str[i] <= 'f')) {
			if (base != 16)
				return 0;
			buf[i] = str[i];
		} else if ((str[i] >= 'A') && (str[i] <= 'F')) {
			if (base != 16)
				return 0;
			buf[i] = str[i] - 'A' + 'a';
		} else if (str[i] == 0) {
			buf[i] = 0;
			i++;
			break;
		} else
			return 0;

		i++;
	}

	num = i-1;
	ret_val = 0;
	if (base == 10) {
		for (i=0; i<num; i++)
			ret_val = ret_val*10 + buf[i] - '0';
	} else if (base == 16) {
		for (i=2; i<num; i++) {
			if (buf[i] >= 'a')
				ret_val = ret_val*16 + buf[i] - 'a' + 10;
			else
				ret_val = ret_val*16 + buf[i] - '0';
		}
	}
	return ret_val;
}


static int find_hdr_in_partiton(char *partition_name, char *hdr_name, union mkimg_hdr *p_hdr, unsigned int p_hdr_size)
{
	int load_size;
	int hdr_offset = 0;

	while(1) {
		load_size = (int)ccci_load_raw_data(partition_name, (unsigned char*)p_hdr, hdr_offset, p_hdr_size);
		if ((unsigned int)load_size != p_hdr_size) {
			ALWAYS_LOG("load hdr fail(%d)\n", load_size);
			return -1;
		}
		if (p_hdr->info.magic != MKIMG_MAGIC) {
			ALWAYS_LOG("invalid magic(%x):(%x)ref\n", p_hdr->info.magic, MKIMG_MAGIC);
			return -LD_ERR_PT_P_HDR_MAGIC_MIS_MATCH;
		}
		if (strcmp(p_hdr->info.name, hdr_name) == 0)
			return hdr_offset;

		hdr_offset += p_hdr->info.hdr_sz;
		hdr_offset += ((p_hdr->info.dsz + p_hdr->info.align_sz - 1) & (~(p_hdr->info.align_sz - 1)));
	}
}

static int load_image_by_name(char *partition_list[], char *name,
				unsigned char *mem_addr, unsigned int max_size, unsigned int flags)
{
	int i = 0;
	int hdr_offset;
	union mkimg_hdr *p_hdr;
	int load_size;
	int ret = -1;
	int img_size_with_padding;
	int partiton_idx = 0;

	/* allocate partition header  memory first */
	p_hdr = (union mkimg_hdr *)malloc(sizeof(union mkimg_hdr));
	if (p_hdr==NULL) {
		ALWAYS_LOG("alloc mem for hdr fail\n");
		return -LD_ERR_PT_ALLOC_HDR_MEM_FAIL;
	}

	while (partition_list[i] != NULL) {
		hdr_offset = find_hdr_in_partiton(partition_list[i], name, p_hdr, sizeof(union mkimg_hdr));
		if (hdr_offset < 0) {
			i++;
			continue;
		}
		partiton_idx = i;
		break;
	}

	if (hdr_offset < 0) {
		ALWAYS_LOG("load sub image %s fail\n", name);
		ret = -LD_ERR_GET_COM_CHK_HDR_FAIL;
		goto _Exit;
	}

	LD_DBG_LOG("dump p_hdr info\n");
	LD_DBG_LOG(" p_hdr->info.magic:%x\n", p_hdr->info.magic);
	LD_DBG_LOG(" p_hdr->info.dsz:%x\n", p_hdr->info.dsz);
	LD_DBG_LOG(" p_hdr->info.name:%s\n", p_hdr->info.name);
	LD_DBG_LOG(" p_hdr->info.mode:%x\n", p_hdr->info.mode);
	LD_DBG_LOG(" p_hdr->info.hdr_sz:%x\n", p_hdr->info.hdr_sz);

	if (p_hdr->info.dsz > max_size) {
		ALWAYS_LOG("load sub image %s fail\n", name);
		ret = -LD_ERR_PT_IMG_TOO_LARGE;
		goto _Exit;
	}

	/* Dummy AP no need do verify */
	if ((flags & LD_IMG_NO_VERIFY) == 0) {
		if (ccci_ld_md_sec_ptr_hdr_verify(partition_list[partiton_idx], name) < 0) {
			ret = -LD_ERR_PT_HASH_CHK_FAIL;
			goto _Exit;
		}
	}

	/* load image raw data */
	load_size = (int)ccci_load_raw_data(partition_list[i], mem_addr, hdr_offset + p_hdr->info.hdr_sz,
						p_hdr->info.dsz);
	if ((unsigned int)load_size != p_hdr->info.dsz) {
		ALWAYS_LOG("load sub-image data fail(%d:%d)\n", load_size, p_hdr->info.dsz);
		ret = -LD_ERR_PT_LD_IMG_DATA_FAIL;
		goto _Exit;
	}

	/* Calcualte size that add padding */
	img_size_with_padding = (load_size + p_hdr->info.align_sz - 1) & (~(p_hdr->info.align_sz -1));
	/* Clear padding data to 0 */
	for (i = 0; i < img_size_with_padding - (int)p_hdr->info.dsz; i++)
		mem_addr[p_hdr->info.dsz + i] = 0;

	/* Dummy AP no need do verify */
	if ((flags & LD_IMG_NO_VERIFY) == 0)
		ccci_ld_md_sec_image_verify(partition_list[partiton_idx], name, mem_addr, img_size_with_padding);

	ret = load_size;

_Exit:
	free(p_hdr);
	return ret;
}

static int load_main_image(download_info_t *main_img, unsigned long long limit, unsigned long align,
				unsigned char **base_addr, int *resv_mem_size)
{
	unsigned char *md_mem_base;
	char *partition_list[2];
	int ret, load_size;

	/* reserve memory for modem with max requirement */
	md_mem_base = ccci_request_resv_memory(main_img->max_size, limit, align);
	if (md_mem_base == NULL) {
		ALWAYS_LOG("allocate MD memory fail\n");
		ret = -LD_ERR_PT_ALLOC_MD_MEM_FAIL;
		load_size = ret;
		goto _Exit;
	}

	partition_list[0] = main_img->partition_name;
	partition_list[1] = NULL;
	load_size = load_image_by_name(partition_list, main_img->image_name, md_mem_base, main_img->max_size,
					main_img->ext_flag);
	if (load_size < 0) {
		ret = load_size;
		/* If enter this function, it means we hope modem feature should be support, we should check error */
		/* So, release reserved memory is not neccessary */
		goto _Exit;
	}

	if (load_size < MAIN_IMG_MIN_SIZE) { /* 32kB */
		ALWAYS_LOG("img size abnormal,size(0x%x)\n", load_size);
		ret = -LD_ERR_PT_MAIN_IMG_SIZE_ABNORMAL;
		load_size = ret;
		goto _Exit;
	}

_Exit:
	main_img->img_size = load_size;
	*base_addr = md_mem_base;
	*resv_mem_size = main_img->max_size;
	main_img->mem_addr = md_mem_base;
	main_img->img_size = load_size;
	ret = load_size;
	return ret;
}

static int dsp_img_post_process(download_info_t *dsp_img, int md_id)
{
	modem_info_t dsp_info;
	int ret;

	/*dsp base addr = md base addr + DSP offset*/
	dsp_info.base_addr = (unsigned long long)((unsigned long)dsp_img->mem_addr);
	dsp_info.resv_mem_size = dsp_img->max_size;
	dsp_info.load_size = dsp_img->img_size;
	if (md_id == MD_SYS1)
		dsp_info.md_id = MD1_DSP;
	else {
		ALWAYS_LOG("Not MD1, DSP doesn't need to check\n");
		return 0;
	}

	if (dsp_img->ass_func) {
		ret = verify_main_img_check_header(&dsp_info);
		if (ret < 0)
			ALWAYS_LOG("by pass dsp check header verify(%d)\n", ret);
		else {
			ret = dsp_img->ass_func((void*)&dsp_info, (void*)dsp_img);
			if (ret < 0) {
				ALWAYS_LOG("dsp assistan func process fail:%d\n", ret);
				return ret;
			}
		}
	}
	return 0;
}

/* --- load raw data to DRAM that listed at table --- */
static int ld_img_at_list(download_info_t img_list[], modem_info_t *info, unsigned long long limit, unsigned long align)
{
	int load_size;
	int md_mem_resv_size = 0;
	int md_mem_required_size = 0;
	unsigned char *md_resv_mem_addr = NULL;
	int ret = 0;
	download_info_t *curr;
	download_info_t *md_main_img;
	char *partition_list[3];

	if (img_list == NULL) {
		ALWAYS_LOG("image list is NULL!\n");
		return -LD_ERR_PT_IMG_LIST_NULL;
	}
	/* find main image at list */
	curr = img_list;
	while (curr->img_type != 0) {
		if (curr->img_type == main_img)
			break;
		curr++;
	}
	if (curr->img_type != main_img)
		return -LD_ERR_ASS_FIND_MAIN_INF_FAIL;

	md_main_img = curr;

	/* alloc memory and load main image */
	ret = load_main_image(md_main_img, limit, align, &md_resv_mem_addr, &md_mem_resv_size);
	if (ret < 0)
		goto _MD_Exit;
	/* check header verify and sub image offset and size update */
	info->base_addr = (unsigned long long)((unsigned long)md_resv_mem_addr);
	info->resv_mem_size = md_mem_resv_size;
	info->load_size = ret;
	ret = verify_main_img_check_header(info);

	if (ret < 0) {
		ALWAYS_LOG("md check header verify fail:%d\n", ret);
		goto _MD_Exit;
	}

	if (md_main_img->ass_func) {
		ret = md_main_img->ass_func((void*)info, (void*)img_list);
		if (ret < 0) {
			ALWAYS_LOG("assistan func process fail:%d\n", ret);
			goto _MD_Exit;
		}
	}
	md_mem_required_size = info->resv_mem_size;

	/* load sub image one by one */
	curr = img_list;
	partition_list[0] = md_main_img->partition_name;
	/* partition_list[1] will update later */
	partition_list[2] = NULL;
	while (curr->img_type != 0) {
		/* By pass main image */
		if (curr->img_type == main_img) {
			curr++;
			continue;
		}
		/* By pass ext image that no need to load after query main image setting */
		if ((curr->mem_addr == NULL) || (curr->img_size == 0)) {
			curr++;
			continue;
		}
		partition_list[1] = curr->partition_name;
		load_size = load_image_by_name(partition_list, curr->image_name, curr->mem_addr,
						curr->max_size, curr->ext_flag);

		if ((load_size >= 0) && (load_size > curr->img_size)) {
			ALWAYS_LOG("image size not sync to chk_hdr hdr:[0x%x]<>a:[0x%x]\n",
			           curr->img_size, load_size);
			ret = -LD_ERR_PT_IMG_SIZE_NOT_SYNC_CHK_HDR;
			goto _MD_Exit;
		} else if (load_size < 0) {
			ALWAYS_LOG("load sub image: %s fail with ret info: %s\n",
			           curr->image_name, ld_md_errno_to_str(load_size));
			ret = load_size;
			goto _MD_Exit;
		}

		if (curr->img_type == dsp_img) {
			curr->img_size = load_size;
			ret = dsp_img_post_process(curr, info->md_id);
			if (ret < 0)
				goto _MD_Exit;
		}
		curr++;
	}

	/* Sync cache to make sure all data flash to DRAM to avoid MPU violation */
	arch_sync_cache_range((addr_t)md_resv_mem_addr, (size_t)md_mem_resv_size);
	ALWAYS_LOG("arch_sync_cache_range: addr[%p], size[0x%08x]\n",
		md_resv_mem_addr, md_mem_resv_size);
	info->errno = 0;

	/* Retrieve not used memory if needed*/
	if (md_mem_resv_size != md_mem_required_size)
		ccci_free_not_used_reserved_memory(md_resv_mem_addr, md_mem_resv_size, md_mem_required_size);

	return 0;

_MD_Exit:
	if (md_resv_mem_addr) {
		ALWAYS_LOG("Free reserved memory\n");
		ccci_free_not_used_reserved_memory(md_resv_mem_addr, md_mem_resv_size, 0);
	}

	return ret;
}

/* --- Download list --------------------------------------- */
/* --- This part is used for normal load ------------------- */
static download_info_t md1_download_list[] = {/* for 90, 91 */
	/* img type | partition | image name | max size  | img size | ext_flag         | mem addr | ass func p */
	{main_img,   "md1img",   "md1rom",    0xA000000,   0,         0,                NULL,      ass_func_for_v5_normal_img},
	{dsp_img,    "md1dsp",   "md1dsp",    0x200000,    0,         0,                NULL,      NULL},
	{armv7_img,  "md1arm7",  "md1arm7",   0x200000,    0,         0,                NULL,      NULL},
	{0,          NULL,       NULL,        0,           0,         0,                NULL,      NULL},
};

static download_info_t md1_download_list_v20000[] = {/* for 92, 93 */
	/* img type | partition | image name | max size  | img size | ext_flag         | mem addr | ass func p */
	{main_img,   "md1img",   "md1rom",    0x10000000,   0,         0,                NULL,      ass_func_for_v6_normal_img},
	{dsp_img,    "md1dsp",   "md1dsp",    0x2000000,    0,         0,                NULL,      ass_func_for_dsp_normal_img},
	{armv7_img,  "md1arm7",  "md1arm7",   0x200000,    0,         0,                NULL,      NULL},
	{drdi_img,   "md1img",   "md1drdi",   0x4000000,     0,         0,                NULL,      NULL},
	{0,          NULL,       NULL,        0,           0,         0,                NULL,      NULL},
};

static download_info_t md1_download_list_v40000[] = {/* for r8 modem with v1 */
	/* img type | partition | image name | max size  | img size | ext_flag         | mem addr | ass func p */
	{main_img,   "md1img",   "md1rom",    0x1800000,   0,         0,                NULL,      ass_func_for_v1_r8_normal_img},
	{0,          NULL,       NULL,        0,           0,         0,                NULL,      NULL},
};


static download_info_t md3_download_list[] = {
	/* img type | partition | image name | max size  | img size | ext_flag         | mem addr */
	{main_img,   "md3img",   "md3rom",    0xC00000,    0,         0,                NULL,      ass_func_for_v1_normal_img},
	{0,          NULL,       NULL,        0,           0,         0,                NULL,      NULL},
};

/* --- This part is used for dummy ap load ------------------- */
static download_info_t md1_download_list_v10001[] = {/* for 90,91 */
	/* img type | partition | image name | max size  | img size | ext_flag         | mem addr */
	{main_img,   "md1img",    "md1rom",    0x20000000,  0,         DUMMY_AP_FLAG,    NULL,     ass_func_for_v5_md_only_img},
	{dsp_img,    "md1dsp",    "md1dsp",    0x200000,    0,         DUMMY_AP_FLAG,    NULL,     NULL},
	{armv7_img,  "md1arm7",   "md1arm7",   0x200000,    0,         DUMMY_AP_FLAG,    NULL,     NULL},
	{ramdisk_img,"userdata",  "md1ramdisk",0x2000000,   0,         DUMMY_AP_FLAG,    NULL,     NULL},
	{l1_core_img,"boot" ,     "l1core",    0x1000000,   0,         DUMMY_AP_FLAG,    NULL,     NULL},
	{0,          NULL,        NULL,        0,           0,         0,                NULL,     NULL},
};
static download_info_t md1_download_list_v20001[] = {/* for 92 */
	/* img type | partition | image name | max size  | img size | ext_flag         | mem addr */
	{main_img,   "md1img",    "md1rom",    0x20000000,  0,         DUMMY_AP_FLAG,    NULL,     ass_func_for_v6_md_only_img},
	{dsp_img,    "md1dsp",    "md1dsp",    0x2000000,   0,         DUMMY_AP_FLAG,    NULL,     NULL},
	{armv7_img,  "md1arm7",   "md1arm7",   0x200000,    0,         DUMMY_AP_FLAG,    NULL,     NULL},
	{ramdisk_img,"userdata",  "md1ramdisk",0x2000000,   0,         DUMMY_AP_FLAG,    NULL,     NULL},
	{l1_core_img,"boot" ,     "l1core",    0x1000000,   0,         DUMMY_AP_FLAG,    NULL,     NULL},
	{0,          NULL,        NULL,        0,           0,         0,                NULL,     NULL},
};

static download_info_t md3_download_list_v10001[] = {
	/* img type | partition | image name | max size  | img size | ext_flag         | mem addr */
	{main_img,   "md3img",   "md3rom",    0x10000000,   0,         DUMMY_AP_FLAG,    NULL,      ass_func_for_v1_md_only_img},
	{0,          NULL,       NULL,        0,            0,         0,                NULL,      NULL},
};

static char md1_version[65];
static char md3_version[65];
static int md1_version_rdy, md3_version_rdy;

void load_modem_image(void)
{
	modem_info_t info;
	unsigned long long ro_rw_limit;
	unsigned long long ld_img_ver;
	unsigned long align;
	long long plat_query_ret;
	int err_code = 0;
	int ret;
	unsigned char *smem_addr = NULL;
	int smem_size = 0;
	unsigned int md_load_status_flag = 0;
	int time_lk_md_init = get_timer(0);
	char buf[128];

	memset(md1_version, 0, sizeof(md1_version));
	memset(md3_version, 0, sizeof(md3_version));
	md1_version_rdy = 0;
	md3_version_rdy = 0;

	ccci_ld_md_wrapper_api_init();

	/* --- 1. Get platform configure setting ---*/
	if (ccci_hal_get_ld_md_plat_setting("support_detect") > 0) {
		ALWAYS_LOG("Enter load_modem_image v2.0\n");
	} else {
		ALWAYS_LOG("Using load_modem_image v1.0\n");
		err_code = -LD_ERR_PT_V2_PLAT_NOT_RDY;
		goto _err_exit;
	}
	/* 2. tag info init */
	ret = ccci_lk_tag_info_init((unsigned long long)((unsigned long)smem_addr));
	if (ret < 0) {
		ALWAYS_LOG("allocate tag memory fail\n");
		err_code = -LD_ERR_PT_ALLOC_CMD_BUF_FAIL;
		goto _err_exit;
	}
	/* 3. tel info init */
	ret = ccci_ld_md_tel_init();
	if (ret < 0) {
		err_code = -LD_ERR_PT_ALLOC_CMD_BUF_FAIL;
		goto _err_exit;
	}
	/* 4. security info init */
	ccci_ld_md_sec_init();

	plat_query_ret = ccci_hal_get_ld_md_plat_setting("ro_rw_mem_limit");
	if (plat_query_ret <= 0) {
		ALWAYS_LOG("ro rw mem limit abnormal:%d\n", (int)plat_query_ret);
		err_code = -LD_ERR_PT_ALLOC_RORW_MEM_FAIL;
		goto _err_exit;
	}
	ro_rw_limit = (unsigned long long)plat_query_ret;

	/* 5. Prepare done, begin to load MD one by one */
	if (ccci_get_opt_val("opt_md1_support") > 0) {
		ALWAYS_LOG("-- MD1 --\n");

		plat_query_ret = ccci_hal_get_ld_md_plat_setting("ro_rw_mem_align");

		if (plat_query_ret <= 0) {
			ALWAYS_LOG("align abnormal for ro rw:%d\n", (int)plat_query_ret);
			err_code = -LD_ERR_PT_ALIGN_SETTING_ABNORMAL;
			update_md_err_to_lk_info(MD_SYS1, err_code);
			goto _load_md2;
		}
		align = (unsigned long)plat_query_ret;

		/* Load image */
		memset(&info, 0, sizeof(modem_info_t));
		info.md_id = MD_SYS1;
		ld_img_ver = ccci_hal_get_ld_md_plat_setting("ld_version");
		switch (ld_img_ver) {
			case 0x10001:
				ret = ld_img_at_list(md1_download_list_v10001, &info, ro_rw_limit, align);
				break;
			case 0x10000:
				ret = ld_img_at_list(md1_download_list, &info, ro_rw_limit, align);
				break;
			case 0x20000:
				ret = ld_img_at_list(md1_download_list_v20000, &info, ro_rw_limit, align);
				break;
			case 0x20001:
				ret = ld_img_at_list(md1_download_list_v20001, &info, ro_rw_limit, align);
				break;
			case 0x40000:
				ret = ld_img_at_list(md1_download_list_v40000, &info, ro_rw_limit, align);
				break;
			default:
				ret = ld_img_at_list(md1_download_list, &info, ro_rw_limit, align);
				break;
		}
		if (ret < 0) {
			err_code = -LD_ERR_PT_MD1_LOAD_FAIL;
			update_md_err_to_lk_info(MD_SYS1, ret);
			ALWAYS_LOG("md1 load fail:%d\n", ret);
			goto _load_md2;
		}

		/* Load success */
		update_md_load_flag_to_lk_info(MD_SYS1);
		add_hdr_info(s_g_md_ld_status, &info);
		md_load_status_flag |= (1<<MD_SYS1);
	}
_load_md2:
	/* Do nothong currently */
	goto _load_md3;
_load_md3:
	if (ccci_get_opt_val("opt_md3_support") > 0) {
		ALWAYS_LOG("-- MD3 --\n");

		plat_query_ret = ccci_hal_get_ld_md_plat_setting("ro_rw_mem_align");

		if (plat_query_ret <= 0) {
			ALWAYS_LOG("align abnormal for ro rw:%d\n", (int)plat_query_ret);
			err_code = -LD_ERR_PT_ALIGN_SETTING_ABNORMAL;
			update_md_err_to_lk_info(MD_SYS3, err_code);
			goto _load_end;
		}
		align = (unsigned long)plat_query_ret;

		/* Load image */
		memset(&info, 0, sizeof(modem_info_t));
		info.md_id = MD_SYS3;
		if (ccci_hal_get_ld_md_plat_setting("ld_version") == 0x10001 ||
				ccci_hal_get_ld_md_plat_setting("ld_version") == 0x20001)
			ret = ld_img_at_list(md3_download_list_v10001, &info, ro_rw_limit, align);
		else
			ret = ld_img_at_list(md3_download_list, &info, ro_rw_limit, align);
		if (ret < 0) {
			err_code = -LD_ERR_PT_MD3_LOAD_FAIL;
			update_md_err_to_lk_info(MD_SYS3, ret);
			ALWAYS_LOG("md3 load fail:%d\n", ret);
			goto _load_end;
		}

		/* Load success */
		update_md_load_flag_to_lk_info(MD_SYS3);
		add_hdr_info(s_g_md_ld_status, &info);
		md_load_status_flag |= (1<<MD_SYS3);
	}
_load_end:
	if (s_g_md_ld_record_num == 0)
		goto _err_exit;
	/* 6. smem init: start */
	plat_query_ret = ccci_hal_get_ld_md_plat_setting("share_memory_size");

	if (plat_query_ret <= 0) {
		ALWAYS_LOG("Share memory size abnormal:%d\n", (int)plat_query_ret);
		err_code = -LD_ERR_PT_SMEM_SIZE_ABNORMAL;
		goto _err_exit;
	}
	smem_size = (int)plat_query_ret;

	smem_addr = resv_named_memory("md_smem_ncache", smem_size);
	if (smem_addr == NULL) {
		ALWAYS_LOG("allocate MD share memory fail\n");
		err_code = -LD_ERR_PT_ALLOC_SMEM_FAIL;
		goto _err_exit;
	}
	ccci_hal_apply_hw_remap_for_md_smem(smem_addr, smem_size);
	/* smem init: end */
	/* 7. information settings. */
	/* update hdr_count info */
	if (insert_ccci_tag_inf("hdr_count", (char*)&s_g_md_ld_record_num, sizeof(unsigned int)) < 0)
		ALWAYS_LOG("insert hdr_count fail\n");

	/* update hdr tbl info */
	if (insert_ccci_tag_inf("hdr_tbl_inf", (char*)s_g_md_ld_status,
	                        sizeof(modem_info_t)*s_g_md_ld_record_num) < 0)
		ALWAYS_LOG("insert hdr_tbl_inf fail\n");

	if (insert_ccci_tag_inf("retrieve_num", (char*)&retrieve_info_num, sizeof(int)) < 0)
		ALWAYS_LOG("insert retrieve_num fail\n");

	ret = ccci_hal_apply_platform_setting(md_load_status_flag);
	if (ret < 0) {
		/* free all reserved share memory */
		ALWAYS_LOG("ccci_hal_apply_platform_setting ret %d \n", ret);
		err_code = -LD_ERR_PT_APPLY_PLAT_SETTING_FAIL;
		update_common_err_to_lk_info(err_code);
		goto _err_exit;
	} else if (ret == 0) {
		/* free all reserved share memory */
		ALWAYS_LOG("No MD Image enabled %d \n", ret);
		/* err_code = 0; */
		goto _err_exit;
	} else if (ret < smem_size) {
		/* smem size returned from platform setting API, */
		/* resize share memory to final size */
		ALWAYS_LOG("re-size share memory form %x to %x\n", smem_size, ret);
		ccci_resize_reserve_mem(smem_addr, smem_size, ret);
	}
	extern void load_success_notify(int error_no)__attribute__((weak));
	if (load_success_notify) {
		load_success_notify(err_code);
	}

	goto _OK_and_exit;

_err_exit:
	ccci_free_local_cmd_line_buf();
	update_common_err_to_lk_info(err_code);

_OK_and_exit:

	ccci_ld_md_add_wrapper_api_info();
	ccci_lk_info_ctl_dump();
	ALWAYS_LOG("[PROFILE] ------- load_modem_image init cost %d ms ----\n", (int)get_timer(time_lk_md_init));
	ret = ccci_get_md_version(MD_SYS1, buf, 128);
	ALWAYS_LOG("[MD1 Baseband version] %s(%d)\r\n", buf, ret);
	ret = ccci_get_md_version(MD_SYS3, buf, 128);
	ALWAYS_LOG("[MD3 Baseband version] %s(%d)\r\n", buf, ret);
}

void ccci_update_md_version(int md_id, unsigned char ver[])
{
	if (md_id == MD_SYS1) {
		md1_version_rdy = 1;
		snprintf(md1_version, 65, "%s", ver);
	} else if (md_id == MD_SYS3) {
		md3_version_rdy = 1;
		snprintf(md3_version, 65, "%s", ver);
	}
}

int ccci_get_md_version(int md_id, char buf[], int size)
{
	if ((md_id == MD_SYS1) && md1_version_rdy)
		return snprintf(buf, size, "%s", md1_version);
	else if ((md_id == MD_SYS3) && md3_version_rdy)
		return snprintf(buf, size, "%s", md3_version);

	return -1;
}

static char *errno_str[] = {
	"LD_ERR_NULL_PTR",
	"LD_ERR_GET_COM_CHK_HDR_FAIL",
	"LD_ERR_CHK_HDR_PATTERN",
	"LD_ERR_RESERVE_MEM_NOT_ENOUGH",
	"LD_ERR_ASS_FUNC_ALLOC_MEM_FAIL",
	"LD_ERR_ASS_FUNC_GET_CHK_HDR_FAIL",
	"LD_ERR_ASS_FIND_MAIN_INF_FAIL",
	"LD_ERR_ASS_FIND_DSP_INF_FAIL",
	"LD_ERR_ASS_FIND_ARMV7_INF_FAIL",
	"LD_ERR_ASS_FIND_RAMDISK_INF_FAIL",
	"LD_ERR_ASS_FIND_L1CORE_INF_FAIL",
	"LD_ERR_TAG_BUF_FULL",
	"LD_ERR_PAD_SIZE_LESS_THAN_64K",
	"LD_ERR_PAD_INVALID_INF",
	"LD_ERR_PAD_FREE_INF_ABNORMAL",
	"LD_ERR_PAD_OVER_TWO_REGION",
	"LD_ERR_PAD_MISC",
	"LD_ERR_PAD_REGION_NOT_ENOUGH",
	"LD_ERR_PAD_NO_REGION_RETRIEVE",
	"LD_ERR_OPT_SETTING_INVALID",
	"LD_ERR_OPT_NOT_FOUND",
	"LD_ERR_OPT_CMD_BUF_ALLOC_FAIL",
	"LD_ERR_PT_DEV_NULL",
	"LD_ERR_PT_NOT_FOUND",
	"LD_ERR_PT_READ_RAW_FAIL",
	"LD_ERR_PT_IMG_LIST_NULL",
	"LD_ERR_PT_ALLOC_HDR_MEM_FAIL",
	"LD_ERR_PT_READ_HDR_SIZE_ABNORMAL",
	"LD_ERR_PT_P_HDR_MAGIC_MIS_MATCH",
	"LD_ERR_PT_MAIN_IMG_SIZE_ABNORMAL",
	"LD_ERR_PT_CERT_CHAIN_FAIL",
	"LD_ERR_PT_IMG_TOO_LARGE",
	"LD_ERR_PT_IMG_SIZE_NOT_SYNC_CHK_HDR",
	"LD_ERR_PT_ALLOC_MD_MEM_FAIL",
	"LD_ERR_PT_LD_IMG_DATA_FAIL",
	"LD_ERR_PT_HASH_CHK_FAIL",
	"LD_ERR_PT_V2_PLAT_NOT_RDY",
	"LD_ERR_PT_SMEM_SIZE_ABNORMAL",
	"LD_ERR_PT_LIMIT_SETTING_ABNORMAL",
	"LD_ERR_PT_ALIGN_SETTING_ABNORMAL",
	"LD_ERR_PT_ALLOC_RORW_MEM_FAIL",
	"LD_ERR_PT_ALLOC_SMEM_FAIL",
	"LD_ERR_PT_ALLOC_CMD_BUF_FAIL",
	"LD_ERR_PT_MD1_LOAD_FAIL",
	"LD_ERR_PT_MD3_LOAD_FAIL",
	"LD_ERR_PT_APPLY_PLAT_SETTING_FAIL",
	"LD_ERR_PT_CHK_IMG_NAME_FAIL",
	"LD_ERR_PLAT_INVALID_MD_ID",
	"LD_ERR_PLAT_MPU_REGION_EMPTY",
	"LD_ERR_PLAT_MPU_REGION_TOO_MORE",
	"LD_ERR_PLAT_MPU_REGION_NUM_NOT_SYNC",
	"LD_ERR_PLAT_ABNORMAL_FREE_REGION",
	"LD_ERR_PLAT_ABNORMAL_PAD_ARRAY",
	"LD_ERR_PLAT_NO_MORE_FREE_REGION",
	"LD_ERR_PLAT_MD1_NOT_RDY",
	"LD_ERR_ASS_FIND_DRDI_INF_FAIL"
};
char *ld_md_errno_to_str(int errno)
{
	if (errno < 1)
		return "invalid errno";

	if ((errno-1) < (int)(sizeof(errno_str)/sizeof(char*)))
		return errno_str[errno-1];

	return "errno not found";
}
