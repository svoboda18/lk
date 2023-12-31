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
#ifndef __CCCI_LD_MD_CORE_H__
#define __CCCI_LD_MD_CORE_H__

//#define LD_IMG_DUMP_LOG_EN
#include "ccci_ld_md_log_cfg.h"
#include <verified_boot_common.h>

/* Log part */
#define ALWAYS_LOG(fmt, args...) do {dprintf(ALWAYS, fmt, ##args);} while (0)
#define DBG_LOG(fmt, args...) do {dprintf(INFO, fmt, ##args);} while (0)

/* Switch log */
#ifdef TAG_DEBUG_LOG_EN
#define TAG_DBG_LOG(fmt, args...) do {dprintf(ALWAYS, fmt, ##args);} while (0)
#else
#define TAG_DBG_LOG(fmt, args...)
#endif
#ifdef PADDING_MEM_DEBUG_LOG_EN
#define PADDING_LOG(fmt, args...) do {dprintf(ALWAYS, fmt, ##args);} while (0)
#else
#define PADDING_LOG(fmt, args...)
#endif
#ifdef LD_IMG_DUMP_LOG_EN
#define LD_DBG_LOG(fmt, args...) do {dprintf(ALWAYS, fmt, ##args);} while (0)
#else
#define LD_DBG_LOG(fmt, args...)
#endif
#ifdef MPU_DBG_LOG_EN
#define MPU_DBG_LOG(fmt, args...) do {dprintf(INFO, fmt, ##args);} while (0)
#else
#define MPU_DBG_LOG(fmt, args...)
#endif
#ifdef ENABLE_DT_DBG_LOG
#define DT_DBG_LOG(fmt, args...) do {dprintf(INFO, fmt, ##args);} while (0)
#else
#define DT_DBG_LOG(fmt, args...)
#endif


/***************************************************************************************************
** Core Global variable and macro defination part
***************************************************************************************************/

#define MAX_MD_NUM      4
#define MAX_PADDING_NUM_V5_HDR  3
#define MAX_PADDING_NUM_V6_HDR  8

#define MAIN_IMG_MIN_SIZE   0x8000
#define DSP_IMG_MAX_SIZE    0x1800000
#define MPU_64K_ALIGN_MASK  (~(0x10000-1))
#define MPU_64K_VALUE       (0x10000)
#define MEM_4K_ALIGN_MASK   (~(0x1000-1))
#define MEM_4K_VALUE        (0x1000)

enum {
	MD_SYS1 = 0,
	MD_SYS2,
	MD_SYS3,
	MD_SYS4,
	MD1_DSP,
};

/***************************************************************************************************
** Sub sectoin:
**   modem info
***************************************************************************************************/
typedef struct _modem_info {
	unsigned long long base_addr;
	unsigned int resv_mem_size;
	char md_id;
	char errno;
	char md_type;
	char ver;
	int load_size;/*ROM + Check header*/
	int ro_rw_size;
} modem_info_t;

extern int retrieve_info_num;

/***************************************************************************************************
** Sub section:
**   modem/dsp check header
***************************************************************************************************/
struct md_check_header_comm {
	unsigned char check_header[12];  /* magic number is "CHECK_HEADER"*/
	unsigned int  header_verno;   /* header structure version number */
	unsigned int  product_ver;     /* 0x0:invalid; 0x1:debug version; 0x2:release version */
	unsigned int  image_type;       /* 0x0:invalid; 0x1:2G modem; 0x2: 3G modem */
	unsigned char platform[16];   /* MT6573_S01 or MT6573_S02 */
	unsigned char build_time[64];   /* build time string */
	unsigned char build_ver[64];     /* project version, ex:11A_MD.W11.28 */

	unsigned char bind_sys_id;     /* bind to md sys id, MD SYS1: 1, MD SYS2: 2 */
	unsigned char ext_attr;       /* no shrink: 0, shrink: 1*/
	unsigned char reserved[2];     /* for reserved */

	unsigned int  mem_size;       /* md ROM/RAM image size requested by md */
	unsigned int  md_img_size;     /* md image size, exclude head size*/
} __attribute__((packed));

struct md_check_header_v1 {
	struct md_check_header_comm common; /* common part */
	unsigned int  ap_md_smem_size;     /* share memory size */
	unsigned int  size;           /* the size of this structure */
} __attribute__((packed));

struct md_check_header_v3 {
	struct md_check_header_comm common; /* common part */
	unsigned int  rpc_sec_mem_addr;  /* RPC secure memory address */

	unsigned int  dsp_img_offset;
	unsigned int  dsp_img_size;
	unsigned char reserved2[88];

	unsigned int  size;           /* the size of this structure */
} __attribute__((packed));

typedef struct _md_regin_info {
	unsigned int region_offset;
	unsigned int region_size;
} md_regin_info;

struct md_check_header_v4 {
	struct md_check_header_comm common; /* common part */
	unsigned int  rpc_sec_mem_addr;  /* RPC secure memory address */

	unsigned int  dsp_img_offset;
	unsigned int  dsp_img_size;

	unsigned int  region_num;    /* total region number */
	md_regin_info region_info[8];    /* max support 8 regions */
	unsigned int  domain_attr[4];    /* max support 4 domain settings, each region has 4 control bits*/

	unsigned char reserved2[4];

	unsigned int  size;           /* the size of this structure */
} __attribute__((packed));

typedef struct _free_padding_block {
	unsigned int start_offset;
	unsigned int length;
} free_padding_block_t;

struct md_check_header_v5 {
	struct md_check_header_comm common; /* common part */
	unsigned int  rpc_sec_mem_addr;  /* RPC secure memory address */

	unsigned int  dsp_img_offset;
	unsigned int  dsp_img_size;

	unsigned int  region_num;    /* total region number */
	md_regin_info region_info[8];    /* max support 8 regions */
	unsigned int  domain_attr[4];    /* max support 4 domain settings, each region has 4 control bits*/

	unsigned int  arm7_img_offset;
	unsigned int  arm7_img_size;

	free_padding_block_t padding_blk[MAX_PADDING_NUM_V5_HDR]; /* should be 3 */
	unsigned int  ap_md_smem_size;
	unsigned int  md_to_md_smem_size;

	unsigned int  ramdisk_offset;
	unsigned int  ramdisk_size;

	unsigned char reserved_1[16];

	unsigned int  size; /* the size of this structure */
};

struct md_check_header_v6 {
	struct md_check_header_comm common; /* common part */
	unsigned int  rpc_sec_mem_addr;  /* RPC secure memory address */

	unsigned int  dsp_img_offset;
	unsigned int  dsp_img_size;

	unsigned int  region_num;    /* total region number */
	md_regin_info region_info[8];    /* max support 8 regions */
	unsigned int  domain_attr[4];    /* max support 4 domain settings, each region has 4 control bits*/

	unsigned int  arm7_img_offset;
	unsigned int  arm7_img_size;

	free_padding_block_t padding_blk[MAX_PADDING_NUM_V6_HDR]; /* should be 8 */

	unsigned int  ap_md_smem_size;
	unsigned int  md_to_md_smem_size;

	unsigned int ramdisk_offset;
	unsigned int ramdisk_size;

	unsigned int drdi_offset;	/* For load sub image */
	unsigned int drdi_size;		/* For load sub image */
	unsigned int drdi_rt_offset;	/* For runtime position */
	unsigned int drdi_rt_size;	/* For runtime position */

	unsigned int amms_pos_size;     /*For amms pos*/
	unsigned int consys_size;
	unsigned int udc_support;	/* 1:support 0:not support */

	unsigned char reserved_1[116];

	unsigned int  size; /* the size of this structure */
};

struct image_section_desc {
	unsigned int offset;
	unsigned int size;
	unsigned int mpu_attr;
	unsigned int ext_flag;
	unsigned int relate_idx;
};

/* dsp check header */
struct dsp_check_header {
	unsigned char check_header[8];
	unsigned char file_info_H[12];
	unsigned char unknown[52];
	unsigned char chip_id[16];
	unsigned char dsp_info[48];
};

/***************************************************************************************************
** Sub section:
**   padding memory for v5 check hdr
***************************************************************************************************/
/* This function only support 3 cases
**   case 0: |======|======| ==> |++====|======|
**   case 1: |======|======| ==> |==++==|======|
**   case 2: |======|======| ==> |====++|======|
**   case 4: |======|======| ==> |=====+|+=====| NOT suppose this case !!!!
*/
#define VALID_PADDING       (1<<0)
#define NEED_MPU_MORE       (1<<1)
#define NEED_REMOVE         (1<<2)
#define MD_ALL_RANGE        (1<<3)
#define MD_DRDI_REGION      (1<<4)

#define LOGIC_BINDING_IDX_START 0x1000

struct padding_tag {
	free_padding_block_t padding_mem;
	int status;
};

/***************************************************************************************************
** Sub section:
**   Telephony operation parsing and prepare part
***************************************************************************************************/
struct opt_cfg {
	char *name;
	int val;
};

/* 0 | 0 | Lf | Lt | W | C | T | G */
#define MD_CAP_KEY		(0x5A<<24)
#define MD_CAP_GSM		(1<<0)
#define MD_CAP_TDS_CDMA		(1<<1)
#define MD_CAP_CDMA2000		(1<<2)
#define MD_CAP_WCDMA		(1<<3)
#define MD_CAP_TDD_LTE		(1<<4)
#define MD_CAP_FDD_LTE		(1<<5)
#define MD_CAP_NR		(1<<6)
#define MD_CAP_MASK		(MD_CAP_GSM|MD_CAP_TDS_CDMA|MD_CAP_WCDMA|MD_CAP_TDD_LTE|MD_CAP_FDD_LTE|MD_CAP_CDMA2000|MD_CAP_NR)


typedef enum {
	RAT_VER_DEFAULT = 0,
	RAT_VER_R8,
	RAT_VER_90,
	RAT_VER_91_92,
	RAT_VER_93,
} lk_md_generation_t;

/***************************************************************************************************
** Sub section
**   image loading part for each image list
**   NOTE: this structure has a duplicate one at platform code
***************************************************************************************************/
#define LD_IMG_NO_VERIFY    (1<<0)
#define DUMMY_AP_FLAG       LD_IMG_NO_VERIFY

typedef int (*ld_md_assistant_t)(void *load_info, void *data);

typedef struct _download_info {
	int img_type;   /* Main image, or plug-in image */
	char    *partition_name;
	char    *image_name;
	int max_size;
	int img_size;
	int ext_flag;
	unsigned char *mem_addr;
	ld_md_assistant_t ass_func;
} download_info_t;

enum {
	main_img = 1,
	dsp_img,
	armv7_img,
	ramdisk_img,
	l1_core_img,
	drdi_img,
	max_img_num
};

/* This function is used by common and platform code to use */
unsigned int str2uint(char *str);


/*************************************************************************/
/* Sub module exported API                                               */
/*************************************************************************/
/* ---  Tag info --- */
int insert_ccci_tag_inf(char *name, char *data, unsigned int size);
int ccci_lk_tag_info_init(unsigned long long base_addr);
void ccci_lk_info_ctl_dump(void);
void update_md_err_to_lk_info(int md_id, int error);
int get_md_err_from_lk_info(int md_id);
void update_md_load_flag_to_lk_info(int md_id);
void update_common_err_to_lk_info(int error);
void ccci_lk_info_re_cfg(unsigned long long base_addr, unsigned int size);
/* ---  assistance --- */
int verify_main_img_check_header(modem_info_t *info);
int ass_func_for_v5_normal_img(void *load_info, void *data);
int ass_func_for_v6_normal_img(void *load_info, void *data);
int ass_func_for_v1_normal_img(void *load_info, void *data);
int ass_func_for_v1_r8_normal_img(void *load_info, void *data);
int ass_func_for_dsp_normal_img(void *load_info, void *data);
int ass_func_for_v5_md_only_img(void *load_info, void *data);
int ass_func_for_v6_md_only_img(void *load_info, void *data);
int ass_func_for_v1_md_only_img(void *load_info, void *data);
/* ---  padding memory --- */
int retrieve_free_padding_mem_v5_hdr(modem_info_t *info,
                                     struct image_section_desc mem_tbl[], void *hdr, int mpu_num);
int retrieve_free_padding_mem_v6_hdr(modem_info_t *info,
                                     struct image_section_desc mem_tbl[], void *hdr, int mpu_num);
void log_retrieve_info(unsigned char *addr, int size);
/* ---  errno string --- */
char *ld_md_errno_to_str(int errno);

/* --- md version api --- */
void ccci_update_md_version(int md_id, unsigned char ver[]);
int ccci_get_md_version(int md_id, char buf[], int size);

/* --- wrapper api --- */
void *ccci_request_resv_memory(unsigned int mem_size, unsigned long long limit, unsigned long align);
void *ccci_request_mem(unsigned int mem_size, unsigned long long limit, unsigned long align);
void *ccci_request_named_mem(char *name, unsigned int mem_size, unsigned long long limit, unsigned long align);
void *resv_named_memory(char name[], unsigned int size);
int ccci_retrieve_mem(unsigned char *addr, int size);
int ccci_load_raw_data(char *part_name, unsigned char *mem_addr, unsigned int offset, int size);
int ccci_resize_reserve_mem(unsigned char *addr, int old_size, int new_size);
int ccci_free_not_used_reserved_memory(unsigned char *md_start_addr, int reserved, int required);
void ccci_ld_md_wrapper_api_init(void);
void ccci_ld_md_add_wrapper_api_info(void);

/* --- sec api --- */
void ccci_ld_md_sec_init(void);
int ccci_ld_md_sec_ptr_hdr_verify(char *partition_name, char *image_name);
void ccci_ld_md_sec_image_verify(char *partition_name, char *image_name, unsigned char *mem_addr, int size);


/* API that implemented by other module */
extern int mblock_create(mblock_info_t *mblock_info, dram_info_t *orig_dram_info, u64 addr, u64 size);
extern void arch_sync_cache_range(addr_t start, size_t len);
extern char *get_env(char *name);
extern char *get_ro_env(char *name)__attribute__((weak));
extern int set_env(char *name, char *value);

/***************************************************************************************************
****************************************************************************************************
** Sub section:
**   Export API from platform, for reasons the following, weak key word added.
**    1. in order to make code compatible;
**    2. avoid build error that some old platform does not support
****************************************************************************************************
***************************************************************************************************/
extern int plat_dt_reserve_mem_size_fixup(void *fdt)__attribute__((weak));
extern long long plat_ccci_get_ld_md_plat_setting(char cfg_name[])__attribute__((weak));
extern int plat_get_padding_mpu_num(void)__attribute__((weak));
extern int plat_apply_hw_remap_for_md_ro_rw(void*)__attribute__((weak));
extern int plat_apply_hw_remap_for_md_smem(void* addr, int size)__attribute__((weak));
extern int plat_send_mpu_info_to_platorm(void*, void*)__attribute__((weak));
extern int plat_apply_platform_setting(int)__attribute__((weak));
extern void plat_post_hdr_info(void* hdr, int ver, int id)__attribute__((weak));
extern int get_mem_limit_and_align(char key[], unsigned long long *limit, unsigned long *align);

/* HAL API */
long long ccci_hal_get_ld_md_plat_setting(char cfg_name[]);
int  ccci_hal_get_mpu_num_for_padding_mem(void);
int  ccci_hal_apply_hw_remap_for_md_ro_rw(void *md_info);
int  ccci_hal_apply_hw_remap_for_md_smem(void *addr, int size);
int  ccci_hal_send_mpu_info_to_platorm(void *md_info, void *mem_info);
int  ccci_hal_apply_platform_setting(int load_flag);
void ccci_hal_post_hdr_info(void *hdr, int ver, int id);

#endif
