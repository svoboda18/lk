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
#include <reg.h>
#include <debug.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <platform.h>
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/sec_devinfo.h>
#include <env.h>
#include <platform/sec_export.h>
#include <platform/verified_boot.h>
//#include <dfo_boot_default.h>

#ifdef MTK_TINYSYS_SCP_SUPPORT
#include <platform/mt_scp.h>
#endif  // MTK_TINYSYS_SCP_SUPPORT

#ifdef MTK_TINYSYS_SSPM_SUPPORT
#include <platform/mt_sspm.h>       // for platform_fdt_sspm()
#endif

#include <platform/verified_boot.h> // for fill_atag_masp_data()
#include <ctype.h>                  // for tolower()

extern int g_nr_bank;
extern BOOT_ARGUMENT *g_boot_arg;
extern BI_DRAM bi_dram[MAX_NR_BANK];
extern int get_meta_port_id(void);
int target_fdt_dram_memtest(void *fdt);

struct tag_header {
	u32 size;
	u32 tag;
};

#define tag_size(type)  ((sizeof(struct tag_header) + sizeof(struct type)) >> 2)

#define SIZE_1M             (1024 * 1024)
#define SIZE_2M             (2 * SIZE_1M)
#define SIZE_256M           (256 * SIZE_1M)
#define SIZE_512M           (512 * SIZE_1M)

/* The list must start with an ATAG_CORE node */
#define ATAG_CORE   0x54410001
struct tag_core {
	u32 flags;      /* bit 0 = read-only */
	u32 pagesize;
	u32 rootdev;
};

/* it is allowed to have multiple ATAG_MEM nodes */
#define ATAG_MEM  0x54410002
typedef struct {
	uint32_t size;
	uint32_t start_addr;
} mem_info;

#define ATAG_MEM64  0x54420002
typedef struct {
	uint64_t size;
	uint64_t start_addr;
} mem64_info;

#define ATAG_EXT_MEM64  0x54430002
typedef struct {
	uint64_t size;
	uint64_t start_addr;
} ext_mem64_info;

/* command line: \0 terminated string */
#define ATAG_CMDLINE    0x54410009
struct tag_cmdline {
	char    cmdline[1]; /* this is the minimum size */
};

/* describes where the compressed ramdisk image lives (physical address) */
#define ATAG_INITRD2    0x54420005
struct tag_initrd {
	u32 start;  /* physical start address */
	u32 size;   /* size of compressed ramdisk image in bytes */
};

#define ATAG_VIDEOLFB   0x54410008
struct tag_videolfb {
	u64 fb_base;
	u32 islcmfound;
	u32 fps;
	u32 vram;
	char lcmname[1]; /* this is the minimum size */
};

/* boot information */
#define ATAG_BOOT   0x41000802
struct tag_boot {
	u32 bootmode;
};

/*META com port information*/
#define ATAG_META_COM 0x41000803
struct tag_meta_com {
	u32 meta_com_type; /* identify meta via uart or usb */
	u32 meta_com_id;  /* multiple meta need to know com port id */
	u32 meta_uart_port; /* identify meta uart port */
};

/*device information*/
#define ATAG_DEVINFO_DATA_SIZE    200
#define EFUSE_SELF_BLOW_RESULT_IDX  49

#define ATAG_MDINFO_DATA 0x41000806
struct tag_mdinfo_data {
	u8 md_type[4];
};

#define ATAG_VCORE_DVFS_INFO 0x54410007
struct tag_vcore_dvfs_info {
	u32 pllgrpreg_size;
	u32 freqreg_size;
	u32* low_freq_pll_val;
	u32* low_freq_cha_val;
	u32* low_freq_chb_val;
	u32* high_freq_pll_val;
	u32* high_freq_cha_val;
	u32* high_freq_chb_val;
};

#define ATAG_PTP_INFO 0x54410008
struct tag_ptp_info {
	u32 first_volt;
	u32 second_volt;
	u32 third_volt;
	u32 have_550;
};


/* The list ends with an ATAG_NONE node. */
#define ATAG_NONE   0x00000000

unsigned *target_atag_nand_data(unsigned *ptr)
{
	return ptr;
}


unsigned *target_atag_partition_data(unsigned *ptr)
{
	return ptr;
}

unsigned *target_atag_boot(unsigned *ptr)
{
	*ptr++ = tag_size(tag_boot);
	*ptr++ = ATAG_BOOT;
	*ptr++ = g_boot_mode;

	return ptr;
}


extern int imix_r;
unsigned *target_atag_imix_r(unsigned *ptr)
{
//    *ptr++ = tag_size(tag_imix_r);
//    *ptr++ = ATAG_IMIX;
	*ptr++ = imix_r;

	dprintf(CRITICAL, "target_atag_imix_r:%d\n",imix_r);
	return ptr;
}

unsigned *target_atag_devinfo_data(unsigned *ptr)
{
	int i = 0;

#ifdef MTK_EFUSE_WRITER_SUPPORT
	set_devinfo_data(EFUSE_SELF_BLOW_RESULT_IDX, mt_efuse_get());
#endif

	*ptr++ = ATAG_DEVINFO_DATA_SIZE;
	for (i=0; i<ATAG_DEVINFO_DATA_SIZE; i++) {
		*ptr++ = get_devinfo_with_index(i);
	}

	dprintf(INFO, "SSSS:0x%x\n", get_devinfo_with_index(0));
	dprintf(INFO, "SSSS:0x%x\n", get_devinfo_with_index(1));
	dprintf(INFO, "SSSS:0x%x\n", get_devinfo_with_index(2));
	dprintf(INFO, "SSSS:0x%x\n", get_devinfo_with_index(3));
	dprintf(INFO, "SSSS:0x%x\n", get_devinfo_with_index(4));
	dprintf(INFO, "SSSS:0x%x\n", get_devinfo_with_index(20));
	dprintf(INFO, "SSSS:0x%x\n", get_devinfo_with_index(21));
	dprintf(INFO, "SSSS:0x%x\n", get_devinfo_with_index(30));

	return ptr;
}

unsigned *target_atag_masp_data(unsigned *ptr)
{
#ifdef MTK_SECURITY_SW_SUPPORT
	/*tag size*/
	*ptr++ = tag_size(tag_masp_data);
	/*tag name*/
	*ptr++ = ATAG_MASP_DATA;
	ptr = fill_atag_masp_data(ptr);
#endif

	return ptr;
}

unsigned *target_atag_mem(unsigned *ptr)
{
	int i;

	for (i = 0; i < g_nr_bank; i++) {
#ifndef MTK_LM_MODE
		*ptr++ = 4; //tag size
		*ptr++ = ATAG_MEM; //tag name
		*ptr++ = bi_dram[i].size;
		*ptr++ = bi_dram[i].start;
#else
		*ptr++ = 6; //tag size
		*ptr++ = ATAG_MEM64; //tag name
		//*((unsigned long long*)ptr)++ = bi_dram[i].size;
		//*((unsigned long long*)ptr)++ = bi_dram[i].start;
		unsigned long long *ptr64 = (unsigned long long *)ptr;
		*ptr64++ = bi_dram[i].size;
		*ptr64++ = bi_dram[i].start;
		ptr = (unsigned int *)ptr64;
#endif
	}
	return ptr;
}

unsigned *target_atag_meta(unsigned *ptr)
{
	*ptr++ = tag_size(tag_meta_com);
	*ptr++ = ATAG_META_COM;
	*ptr++ = g_boot_arg->meta_com_type;
	*ptr++ = g_boot_arg->meta_com_id;
	*ptr++ = get_meta_port_id();
	dprintf(CRITICAL, "meta com type = %d\n", g_boot_arg->meta_com_type);
	dprintf(CRITICAL, "meta com id = %d\n", g_boot_arg->meta_com_id);
	dprintf(CRITICAL, "meta uart port = %d\n", get_meta_port_id());
	return ptr;
}

/* todo: give lk strtoul and nuke this */
static unsigned hex2unsigned(const char *x)
{
	unsigned n = 0;

	while (*x) {
		switch (*x) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				n = (n << 4) | (*x - '0');
				break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
				n = (n << 4) | (*x - 'a' + 10);
				break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				n = (n << 4) | (*x - 'A' + 10);
				break;
			default:
				return n;
		}
		x++;
	}

	return n;
}
#if 0
#define ATAG_DFO_DATA 0x41000805
unsigned *target_atag_dfo(unsigned *ptr)
{
	int i, j;
	dfo_boot_info *dfo_p;
	char tmp[11];
	unsigned  char *buffer;

	*ptr++ = ((sizeof(struct tag_header) + DFO_BOOT_COUNT * sizeof(dfo_boot_info)) >> 2);
	*ptr++ = ATAG_DFO_DATA;

	memcpy((void *)ptr, (void *)dfo_boot_default, DFO_BOOT_COUNT * sizeof(dfo_boot_info));
	dfo_p = (dfo_boot_info *)ptr;

	ptr += DFO_BOOT_COUNT * sizeof(dfo_boot_info) >> 2;

	buffer = (unsigned char *)get_env("DFO");

	if (buffer != NULL) {

		for (i = 0; i < DFO_BOOT_COUNT; i++) {
			j = 0;
			do {
				dfo_p[i].name[j] = *buffer;
				j++;
			} while (*buffer++ != ',' && j < 31);

			dfo_p[i].name[j-1] = '\0';
			j = 0;

			do {
				tmp[j] = *buffer;
				j++;
			} while (*buffer++ != ',' && j < 10);

			tmp[j] = '\0';

			if ((strncmp("0x", tmp, 2) == 0) || (strncmp("0X", tmp, 2) == 0))
				dfo_p[i].value = hex2unsigned(&tmp[2]);
			else
				dfo_p[i].value = atoi(tmp);
		}

		for (i = 0; i < DFO_BOOT_COUNT; i++)
			dprintf(INFO, "[DFO-%d] NAME:%s, Value:%lu\n",i , dfo_p[i].name, dfo_p[i].value);

	} else
		dprintf(INFO, "No DFO. Use default values.\n");

	return ptr;
}
#endif

unsigned *target_atag_initrd(unsigned *ptr, ulong initrd_start, ulong initrd_size)
{
	*ptr++ = tag_size(tag_initrd);
	*ptr++ = ATAG_INITRD2;
//TMP for bring up testing
//  *ptr++ = CFG_RAMDISK_LOAD_ADDR;
	// *ptr++ = 0x1072F9;

	*ptr++ = initrd_start;
	*ptr++ = initrd_size;
	return ptr;
}

#include <platform/mt_disp_drv.h>
#include <platform/disp_drv.h>
unsigned *target_atag_videolfb(unsigned *ptr, size_t buf_size)
{
	extern unsigned long long fb_addr_pa_k;
	const char   *lcmname = mt_disp_get_lcm_id();
	unsigned int *p       = NULL;
	unsigned long long *phy_p   = (unsigned long long *)ptr;
	*phy_p = fb_addr_pa_k;
	p = (unsigned int*)(phy_p + 1);
	*p++ = DISP_IsLcmFound();
	*p++ = mt_disp_get_lcd_time();
	*p++ = DISP_GetVRamSize();
	strncpy((char *)p, lcmname, (buf_size - 5 * sizeof(unsigned)));
	p += (strlen(lcmname) + 1 + 4) >> 2;

	dprintf(CRITICAL, "videolfb - fb_base    = 0x%llx\n",fb_addr_pa_k);
	dprintf(CRITICAL, "videolfb - islcmfound = %d\n",DISP_IsLcmFound());
	dprintf(CRITICAL, "videolfb - fps        = %d\n", mt_disp_get_lcd_time());
	dprintf(CRITICAL, "videolfb - vram       = %d\n",DISP_GetVRamSize());
	dprintf(CRITICAL, "videolfb - lcmname    = %s\n",lcmname);

	return (unsigned *)p;

}

#if (MTK_DUAL_DISPLAY_SUPPORT == 2)
unsigned *target_atag_ext_videolfb(unsigned *ptr)
{
	extern unsigned long long ext_fb_addr_pa_k;
	const char   *ext_lcmname = mt_ext_disp_get_lcm_id();
	unsigned int *p 	  = NULL;
	unsigned long long *ext_phy_p = (unsigned long long *)ptr;
	unsigned ext_fps = 6000;

	*ext_phy_p = ext_fb_addr_pa_k;
	p = (unsigned int*)(ext_phy_p + 1);
	*p++ = EXT_DISP_IsLcmFound();
	*p++ = ext_fps;
	*p++ = EXT_DISP_GetVRamSize();
	strcpy((char *)p,ext_lcmname);
	p += (strlen(ext_lcmname) + 1 + 4) >> 2;

	dprintf(CRITICAL, "videolfb - ext_fb_base	 = 0x%llx\n",ext_fb_addr_pa_k);
	dprintf(CRITICAL, "videolfb - ext_islcmfound = %d\n",EXT_DISP_IsLcmFound());
	dprintf(CRITICAL, "videolfb - ext_fps		 = %d\n",ext_fps);
	dprintf(CRITICAL, "videolfb - ext_vram		 = %d\n",EXT_DISP_GetVRamSize());
	dprintf(CRITICAL, "videolfb - ext_lcmname	 = %s\n",ext_lcmname);

	return (unsigned *)p;

}
#endif

unsigned *target_atag_mdinfo(unsigned *ptr)
{
	unsigned char *p;
	*ptr++=tag_size(tag_mdinfo_data);
	*ptr++=ATAG_MDINFO_DATA;
	p=(unsigned char *)ptr;
	*p++=g_boot_arg->md_type[0];
	*p++=g_boot_arg->md_type[1];
	*p++=g_boot_arg->md_type[2];
	*p++=g_boot_arg->md_type[3];
	return (unsigned *)p;
}

unsigned *target_atag_isram(unsigned *ptr)
{
	unsigned char *p;
	p=(unsigned char *)ptr;
	memcpy(p, (unsigned char*)&g_boot_arg->non_secure_sram_addr, sizeof(u32));
	p=p+sizeof(u32);
	memcpy(p, (unsigned char*)&g_boot_arg->non_secure_sram_size, sizeof(u32));
	p=p+sizeof(u32);
	dprintf(CRITICAL,"[LK] non_secure_sram (0x%x, 0x%x)\n", g_boot_arg->non_secure_sram_addr, g_boot_arg->non_secure_sram_size);
	return (unsigned *)p;
}

unsigned *target_atag_ptp(unsigned *ptr)
{
	ptp_info_t* ptp_info = &g_boot_arg->ptp_volt_info;
	u32 first_volt = ptp_info->first_volt;
	u32 second_volt = ptp_info->second_volt;
	u32 third_volt = ptp_info->third_volt;
	u32 have_550 = ptp_info->have_550;

	*ptr++=tag_size(tag_ptp_info);
	*ptr++=ATAG_PTP_INFO;

	*ptr++=first_volt;
	*ptr++=second_volt;
	*ptr++=third_volt;
	*ptr++=have_550;

	return ptr;
}

void *target_get_scratch_address(void)
{
	return ((void *)SCRATCH_ADDR);
}


#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>

#define NUM_CLUSTERS  3
#define NUM_CORES_CLUSTER0  4
#define NUM_CORES_CLUSTER1  4
#define NUM_CORES_CLUSTER2  2
#define MAX_CLK_FREQ  2000000000


/*
 * 0000: Qual core
 * 1000: Triple core
 * 1100: Dual core
 * 1110: Single core
 * 1111: All disable
 */
#define DEVINFO_4CPU_QUAL_CORE   0x0
#define DEVINFO_4CPU_TRIPLE_CORE 0x8
#define DEVINFO_4CPU_DUAL_CORE   0xC
#define DEVINFO_4CPU_SINGLE_CORE 0xE
#define DEVINFO_4CPU_ZERO_CORE   0xF

/*
 * 00: Dual core
 * 10: Single core
 * 11: All disable
 */
#define DEVINFO_2CPU_DUAL_CORE   0x0
#define DEVINFO_2CPU_SINGLE_CORE 0x2
#define DEVINFO_2CPU_ZERO_CORE   0x3


struct cpu_dev_info {
	unsigned int cluster0 : 4;
	unsigned int cluster1 : 4;
	unsigned int cluster2 : 2;
	unsigned int reserve  : 22;
};

struct speed_dev_info {
	unsigned int big      : 3;
	unsigned int reserve1 : 1;
	unsigned int small    : 3;
	unsigned int reserve2 : 25;
};

unsigned int dev_info_max_clk_freq(unsigned int cluster_idx)
{
	unsigned int devinfo = get_devinfo_with_index(8);
	struct speed_dev_info *info = (struct speed_dev_info *)&devinfo;
	unsigned int big, max_clk_freq, decrease;

	decrease = 0;

	big = (cluster_idx == 2) ? 1 : 0;

	if (big) {
		/*
		  000:Free
		  001:2.5 GHz
		  010:2.4 GHz
		  011:2.3 GHz
		  100:2.2 GHz
		  101:2.1 GHz
		  110:2.0 GHz
		  111:1.9 GHz
		*/
		max_clk_freq = 2500;

		if (info->big > 0)
			decrease = (info->big - 1) * 100;
	} else {
		/*
		  000:Free
		  001:2.2 GHz
		  010:2.1 GHz
		  011:2.0 GHz
		  100:1.9 GHz
		  111:1.9 GHz
		*/
		max_clk_freq = 2200;

		if (info->small > 0) {
			if (info->small >= 0x4)
				decrease = (0x4 - 1) * 100;
			else
				decrease = (info->small - 1) * 100;
		}
	}

	max_clk_freq -= decrease;
	max_clk_freq *= 1000 * 1000;

	return max_clk_freq;
}

int dev_info_nr_cpu(void)
{
	unsigned int devinfo = get_devinfo_with_index(3);
	unsigned int mp0_disable = ((get_devinfo_with_index(8) >> 7) & 0x1);
	struct cpu_dev_info *info = (struct cpu_dev_info *)&devinfo;
	int cluster[NUM_CLUSTERS];
	int cluster_idx;
	int nr_cpu = 0;

	memset(cluster, 0, sizeof(cluster));

	if (mp0_disable)
		info->cluster0 = DEVINFO_4CPU_ZERO_CORE;

	cluster[0] = info->cluster0;
	cluster[1] = info->cluster1;
	cluster[2] = info->cluster2;

	for (cluster_idx = 0; cluster_idx < (NUM_CLUSTERS - 1); cluster_idx++) {
		switch (cluster[cluster_idx]) {
			case DEVINFO_4CPU_QUAL_CORE:
				nr_cpu += 4;
				break;
			case DEVINFO_4CPU_TRIPLE_CORE:
				nr_cpu += 3;
				break;
			case DEVINFO_4CPU_DUAL_CORE:
				nr_cpu += 2;
				break;
			case DEVINFO_4CPU_SINGLE_CORE:
				nr_cpu += 1;
				break;
			case DEVINFO_4CPU_ZERO_CORE:
				break;
			default:
				nr_cpu += 4;
				break;
		}
	}

	switch (cluster[2]) {
		case DEVINFO_2CPU_DUAL_CORE:
			nr_cpu += 2;
			break;
		case DEVINFO_2CPU_SINGLE_CORE:
			nr_cpu += 1;
			break;
		case DEVINFO_2CPU_ZERO_CORE:
			break;
		default:
			nr_cpu += 2;
			break;
	}

	return nr_cpu;
}

#define PROJ_CODE   0x1a65

int target_fdt_model(void *fdt)
{
	unsigned int segment = get_devinfo_with_index(30) & 0xFF;
	unsigned int cap = get_devinfo_with_index(6);
	unsigned int platform_type = (get_devinfo_with_index(3) >> 27) & 0x1; /* 0: smartphone, 1: tablet */
	/* unsigned int proj_code = get_devinfo_with_index(29) >> 16; */
	int len;
	int nodeoffset;
	const struct fdt_property *prop;
	char *prop_name = "model";
	char *model_name;
	#define CAP_IS_C(_cap) (((_cap>>16)&0x1) == 0x0)
	#define CAP_IS_A(_cap) (((_cap>>18)&0x3) == 0x0)
	#define CAP_IS_B(_cap) (((_cap>>18)&0x3) == 0x2)

	//memo: A->Cat7, B->Cat4, C->6M

	dprintf(CRITICAL, "[LK] segment = 0x%x, 0x%x\n", segment, cap);
	switch(segment){
		case 0x8:
		case 0xF:
			if(CAP_IS_C(cap)) {
				if(CAP_IS_B(cap)) {
					model_name = "MT6762V/CN";
				} else if(CAP_IS_A(cap)) {
					model_name = "MT6762V/CM";
					if (platform_type)
						model_name = "MT8768CB";
				} else {
					model_name = "MT6762M";
				}
			} else {
				if(CAP_IS_B(cap)) {
					model_name = "MT6762V/WN";
				} else if(CAP_IS_A(cap)) {
					model_name = "MT6762V/WM";
					if (platform_type)
						model_name = "MT8768WB";
				} else {
					model_name = "MT6762M";
				}
			}
			break;
		case 0x1:
		case 0x7:
		case 0x19:
			if(CAP_IS_C(cap)) {
				if(CAP_IS_B(cap)) {
					model_name = "MT6762V/CB";
					if (platform_type)
						model_name = "MT8768CE";
				} else if(CAP_IS_A(cap)) {
					model_name = "MT6762V/CA";
					if (platform_type)
						model_name = "MT8768CA";
				} else {
					model_name = "MT6762";
				}
			} else {
				if(CAP_IS_B(cap)) {
					model_name = "MT6762V/WB";
					if (platform_type)
						model_name = "MT8768WE";
				} else if(CAP_IS_A(cap)) {
					model_name = "MT6762V/WA";
					if (platform_type)
						model_name = "MT8768WA";
				} else {
					model_name = "MT6762";
				}
			}
			break;
		case 0x9:
		case 0xff:
			if(CAP_IS_C(cap)) {
				if(CAP_IS_B(cap)) {
					model_name = "MT6762V/CR";
					if (platform_type)
						model_name = "MT8768CD";
				} else if(CAP_IS_A(cap)) {
					model_name = "MT6762V/CS";
				} else {
					model_name = "MT6762R";
				}
			} else {
				if(CAP_IS_B(cap)) {
					model_name = "MT6762V/WR";
					if (platform_type)
						model_name = "MT8768WD";
				} else if(CAP_IS_A(cap)) {
					model_name = "MT6762V/WS";
				} else {
					model_name = "MT6762R";
				}
			}
			break;
		case 0x20:
			if(CAP_IS_C(cap)) {
				if(CAP_IS_B(cap)) {
					model_name = "MT6762V/CD";
				} else {
					model_name = "MT6762D";
				}
			} else {
				if(CAP_IS_B(cap)) {
					model_name = "MT6762V/WD";
				} else {
					model_name = "MT6762D";
				}
			}
			break;
		case 0x4:
		case 0x3:
			if(CAP_IS_C(cap)) {
				if(CAP_IS_B(cap)) {
					model_name = "MT6765V/CB";
				} else if(CAP_IS_A(cap)) {
					model_name = "MT6765V/CA";
					if (platform_type)
						model_name = "MT8768CT";
				} else {
					model_name = "MT6765";
				}
			} else {
				if(CAP_IS_B(cap)) {
					model_name = "MT6765V/WB";
				} else if(CAP_IS_A(cap)) {
					model_name = "MT6765V/WA";
					if (platform_type)
						model_name = "MT8768WT";
				} else {
					model_name = "MT6765";
				}
			}
			break;
		case 0x2:
		case 0x5:
			model_name = "MT6765T";
			break;
		default:
			/* segment not support */
			return -1;
	}

#ifdef MTK_HE_MODE
	switch(segment){
		case 0x8:
		case 0xF:
		case 0x1:
		case 0x7:
		case 0x19:
		case 0x9:
		case 0xff:
		case 0x20:
			model_name = "MT6762G";
			break;
		case 0x4:
		case 0x3:
		case 0x2:
		case 0x5:
			model_name = "MT6765G";
			break;
		default:
			/* segment not support */
			break;
	}
#endif

	nodeoffset = 0;
	prop = fdt_get_property(fdt, nodeoffset, prop_name, &len);

	if (prop) {
		int namestroff;
		//dprintf(INFO, "prop->data=0x%8x\n", (uint32_t *)prop->data);
		fdt_setprop_string(fdt, nodeoffset, prop_name, model_name);
		prop = fdt_get_property(fdt, nodeoffset, prop_name, &len);
		if (prop) {
			namestroff = fdt32_to_cpu(prop->nameoff);
			dprintf(CRITICAL, "%s=%s\n", fdt_string(fdt, namestroff), (char *)prop->data);
		}
	}

	return 0;
}

int target_fdt_cpus(void *fdt)
{
	u32 devinfo;
	int rc, i;
	int nr_cpus;
	int dn, dn_top;
	int dn_cpus[8] = {0};
	const struct fdt_property *dn_property;

	devinfo = get_devinfo_with_index(30) & 0xff;

	switch (devinfo) {
	case 0x8:
	case 0xf:
		/* MT6762M */
		nr_cpus = 4;
		break;
	default:
		/* MT6765, MT6762, MT6765T */
		nr_cpus = 8;
		break;
	}

	if (nr_cpus == 8)
		return 0;

	dn_top = fdt_path_offset(fdt, "/cpus");
	if (dn_top < 0) {
		dprintf(CRITICAL, "%s/%d: %s\n",
			__func__, __LINE__, fdt_strerror(dn_top));
		return -1;
	}

	/* traverse the /cpus to get each cpu node */
	for (dn = fdt_first_subnode(fdt, dn_top), i = 0;
	     dn >= 0;
	     dn = fdt_next_subnode(fdt, dn), i++)
	{
		dn_property = fdt_get_property(fdt, dn, "device_type", NULL);
		if (!dn_property || strcmp(dn_property->data, "cpu"))
			continue;

		dn_cpus[i] = dn;
	}

	/* remove the extra cpu nodes */
	for (i = nr_cpus; i < 8; i++) {
		rc = fdt_nop_node(fdt, dn_cpus[i]);
		if (rc)
			dprintf(CRITICAL, "%s/%d: %s\n",
				__func__, __LINE__, fdt_strerror(rc));
	}

	/*
	 * if it is the 4 cores segments, remove the extra cluster node
	 * and its sub-nodes
	 */
	dn_top = fdt_path_offset(fdt, "/cpus/cpu-map/cluster1");
	if (dn_top < 0) {
		dprintf(CRITICAL, "%s/%d: %s\n",
			__func__, __LINE__, fdt_strerror(dn_top));
		return -1;
	}

	rc = fdt_nop_node(fdt, dn_top);
	if (rc)
		dprintf(CRITICAL, "%s/%d: %s\n",
			__func__, __LINE__, fdt_strerror(rc));

	return 0;
}

int target_fdt_firmware(void *fdt, char *serialno)
{
	int nodeoffset;
	char *name, *value;

	nodeoffset = fdt_path_offset(fdt, "/firmware/android");
	if (nodeoffset < 0) {
		nodeoffset = fdt_path_offset(fdt, "/firmware");
		if (nodeoffset < 0) {
			/* Add subnode "firmware" in root */
			nodeoffset = fdt_add_subnode(fdt, 0, "firmware");
			if (nodeoffset < 0) {
				dprintf(CRITICAL, "Warning: can't add firmware node in device tree\n");
				return -1;
			}
		}

		/* Add subnode "android" in "/firmware" */
		nodeoffset = fdt_add_subnode(fdt, nodeoffset, "android");
		if (nodeoffset < 0) {
			dprintf(CRITICAL, "Warning: can't add firmware/android node in device tree\n");
			return -1;
		}
	}

	/* Add properties in "/firmware/android" */
	name = "compatible";
	value = "android,firmware";
	fdt_setprop_string(fdt, nodeoffset, name, value);

	name = "hardware";
	value = PLATFORM;
#ifdef MTK_PLATFORM_REVISED
	value = MTK_PLATFORM_REVISED;
#endif
#ifdef MTK_PRODUCT_LINE_PLATFORM
	value = MTK_PRODUCT_LINE_PLATFORM;
#endif
	{
		char *tmp_str = value;
		for ( ; *tmp_str; tmp_str++ ) {
			*tmp_str = tolower(*tmp_str);
		}
	}
	fdt_setprop_string(fdt, nodeoffset, name, value);

	name = "serialno";
	value = serialno;
	fdt_setprop_string(fdt, nodeoffset, name, value);
	name = "mode";

	switch (g_boot_mode) {
		case META_BOOT:
		case ADVMETA_BOOT:
			value = "meta";
			break;
#if defined (MTK_KERNEL_POWER_OFF_CHARGING)
		case KERNEL_POWER_OFF_CHARGING_BOOT:
		case LOW_POWER_OFF_CHARGING_BOOT:
			value = "charger";
			break;
#endif
		case FACTORY_BOOT:
		case ATE_FACTORY_BOOT:
			value = "factory";
			break;
		case RECOVERY_BOOT:
			value = "recovery";
			break;
		default:
			value = "normal";
			break;
	}

	fdt_setprop_string(fdt, nodeoffset, name, value);

	return 0;
}


int platform_atag_append(void *fdt)
{
#ifdef MTK_TINYSYS_SCP_SUPPORT
	if(platform_fdt_scp(fdt))
		return 1;
#endif

#ifdef MTK_TINYSYS_SSPM_SUPPORT
	platform_fdt_sspm(fdt);
#endif

	target_fdt_dram_memtest(fdt);

	return 0;
}

#endif //DEVICE_TREE_SUPPORT
