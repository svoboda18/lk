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
*/


/******************************************************************************
******************************************************************************/
#include <fpga_boot_argument.h>
#include <debug.h>


/******************************************************************************
******************************************************************************/
#ifdef FPGA_PRINT_BOOT_ARGUMENT
static BOOT_ARGUMENT ba;  // Copy "boot argument" for FPGA environment only.
#endif  // FPGA_PRINT_BOOT_ARGUMENT


/******************************************************************************
******************************************************************************/
void fpga_copy_boot_argument(BOOT_ARGUMENT *boot_arg)
{
#ifdef FPGA_PRINT_BOOT_ARGUMENT
	memcpy(&ba, boot_arg, sizeof(ba));
#endif  // FPGA_PRINT_BOOT_ARGUMENT
}


/******************************************************************************
******************************************************************************/
void fpga_print_boot_argument(void)
{
#ifdef FPGA_PRINT_BOOT_ARGUMENT
	int i, elements;

	mtk_wdt_restart();
	// mdelay(10);
	dprintf(CRITICAL, "==============================================\n");
	dprintf(CRITICAL, "=    Beginning of printing boot arguement    =\n");
	dprintf(CRITICAL, "==============================================\n");

	dprintf(CRITICAL, "maggic_number = 0x%08x\n", ba.maggic_number);
	dprintf(CRITICAL, "boot_mode = 0x%08x\n", ba.boot_mode);
	dprintf(CRITICAL, "e_flag = 0x%08x\n", ba.e_flag);

	// mdelay(1);
	dprintf(CRITICAL, "log_port = 0x%08x\n", ba.log_port);
	dprintf(CRITICAL, "log_baudrate = 0x%08x\n", ba.log_baudrate);
	dprintf(CRITICAL, "log_enable = 0x%02x\n", ba.log_enable);
	dprintf(CRITICAL, "log_dynamic_switch = 0x%08x\n", ba.log_dynamic_switch);

	dprintf(CRITICAL, "part_num = 0x%02x\n", ba.part_num);
	// dprintf(CRITICAL, "reserved[0] = 0x%02x\n", ba.reserved[0]);
	// dprintf(CRITICAL, "reserved[1] = 0x%02x\n", ba.reserved[1]);

	// mdelay(1);
	dprintf(CRITICAL, "dram_rank_num = 0x%08x\n", ba.dram_rank_num);
	elements = sizeof(ba.dram_rank_size) / sizeof(ba.dram_rank_size[0]);
	elements = (elements > ba.dram_rank_num) ? ba.dram_rank_num : elements;
	for (i = 0; i < elements; i++)
	{
		dprintf(CRITICAL, "dram_rank_size[%d] = 0x%08x_%08x\n", i,
			(unsigned int)(ba.dram_rank_size[i] >> 32),
			(unsigned int)(ba.dram_rank_size[i] & 0xFFFFFFFF));
	}

	/* Print mblock_info */
	// mdelay(1);
	mblock_info_t *p_minfo = &ba.mblock_info;
	dprintf(CRITICAL, "mblock_info.mblock_num = 0x%08x\n", p_minfo->mblock_num);
	elements = sizeof(p_minfo->mblock) / sizeof(p_minfo->mblock[0]);
	elements = (elements > p_minfo->mblock_num) ? p_minfo->mblock_num : elements;
	for (i = 0; i < elements; i++)
	{
		dprintf(CRITICAL, "mblock_info.mblock[%d].start = 0x%08x_%08x\n", i,
			(unsigned int)(p_minfo->mblock[i].start >> 32),
			(unsigned int)(p_minfo->mblock[i].start & 0xFFFFFFFF));
		dprintf(CRITICAL, "mblock_info.mblock[%d].size = 0x%08x_%08x\n", i,
			(unsigned int)(p_minfo->mblock[i].size >> 32),
			(unsigned int)(p_minfo->mblock[i].size & 0xFFFFFFFF));
		dprintf(CRITICAL, "mblock_info.mblock[%d].rank = 0x%08x\n", i,
			p_minfo->mblock[i].rank);
		mtk_wdt_restart();
	}
	dprintf(CRITICAL, "mblock_info.mblock_magic = 0x%08x\n", p_minfo->mblock_magic);
	dprintf(CRITICAL, "mblock_info.mblock_version = 0x%08x\n", p_minfo->mblock_version);
	dprintf(CRITICAL, "mblock_info.reserved_num = 0x%08x\n", p_minfo->reserved_num);
	elements = sizeof(p_minfo->reserved) / sizeof(p_minfo->reserved[0]);
	elements = (elements > p_minfo->reserved_num) ? p_minfo->reserved_num : elements;
	for (i = 0; i < elements; i++)
	{
		dprintf(CRITICAL, "mblock_info.reserved[%d].start = 0x%08x_%08x\n", i,
			(unsigned int)(p_minfo->reserved[i].start >> 32),
			(unsigned int)(p_minfo->reserved[i].start & 0xFFFFFFFF));
		dprintf(CRITICAL, "mblock_info.reserved[%d].size = 0x%08x_%08x\n", i,
			(unsigned int)(p_minfo->reserved[i].size >> 32),
			(unsigned int)(p_minfo->reserved[i].size & 0xFFFFFFFF));
		dprintf(CRITICAL, "mblock_info.reserved[%d].mapping = 0x%08x\n", i,
			p_minfo->reserved[i].mapping);
		dprintf(CRITICAL, "mblock_info.reserved[%d].name:\n");
		hexdump(p_minfo->reserved[i].name, sizeof(p_minfo->reserved[i].name));
	}

	/* Print dram info */
	// mdelay(1);
	dram_info_t *p_dram = &ba.orig_dram_info;
	dprintf(CRITICAL, "orig_dram_info.rank_num = 0x%08x\n", p_dram->rank_num);
	elements = sizeof(p_dram->rank_info) / sizeof(p_dram->rank_info[0]);
	elements = (elements > p_dram->rank_num) ? p_dram->rank_num : elements;
	for (i = 0; i < elements; i++)
	{
		dprintf(CRITICAL, "orig_dram_info.rank_info[%d].start = 0x%08x_%08x\n", i,
			(unsigned int)(p_dram->rank_info[i].start >> 32),
			(unsigned int)(p_dram->rank_info[i].start & 0xFFFFFFFF));
		dprintf(CRITICAL, "orig_dram_info.rank_info[%d].size = 0x%08x_%08x\n", i,
			(unsigned int)(p_dram->rank_info[i].size >> 32),
			(unsigned int)(p_dram->rank_info[i].size & 0xFFFFFFFF));
		// mdelay(1);
	}

	dprintf(CRITICAL, "lca_reserved_mem.start = 0x%08x_%08x\n",
		(unsigned int)(ba.lca_reserved_mem.start >> 32),
		(unsigned int)(ba.lca_reserved_mem.start & 0xFFFFFFFF));
	dprintf(CRITICAL, "lca_reserved_mem.size = 0x%08x_%08x\n",
		(unsigned int)(ba.lca_reserved_mem.size >> 32),
		(unsigned int)(ba.lca_reserved_mem.size & 0xFFFFFFFF));

	dprintf(CRITICAL, "tee_reserved_mem.start = 0x%08x_%08x\n",
		(unsigned int)(ba.tee_reserved_mem.start >> 32),
		(unsigned int)(ba.tee_reserved_mem.start & 0xFFFFFFFF));
	dprintf(CRITICAL, "tee_reserved_mem.size = 0x%08x_%08x\n",
		(unsigned int)(ba.tee_reserved_mem.size >> 32),
		(unsigned int)(ba.tee_reserved_mem.size & 0xFFFFFFFF));

	// mdelay(1);
	dprintf(CRITICAL, "boot_reason = 0x%08x\n", ba.boot_reason);
	dprintf(CRITICAL, "meta_com_type = 0x%08x\n", ba.meta_com_type);
	dprintf(CRITICAL, "meta_com_id = 0x%08x\n", ba.meta_com_id);
	dprintf(CRITICAL, "boot_time = 0x%08x\n", ba.boot_time);

	/* Print da_info */
	// mdelay(1);
	dprintf(CRITICAL, "da_info.addr = 0x%08x\n", ba.da_info.addr);
	dprintf(CRITICAL, "da_info.arg1 = 0x%08x\n", ba.da_info.arg1);
	dprintf(CRITICAL, "da_info.arg2 = 0x%08x\n", ba.da_info.arg2);
	dprintf(CRITICAL, "da_info.len = 0x%08x\n", ba.da_info.len);
	dprintf(CRITICAL, "da_info.sig_len = 0x%08x\n", ba.da_info.sig_len);

	// mdelay(1);
	dprintf(CRITICAL, "sec_limit.magic_num = 0x%08x\n", ba.sec_limit.magic_num);
	dprintf(CRITICAL, "sec_limit.forbid_mode = 0x%08x\n", ba.sec_limit.forbid_mode);
	dprintf(CRITICAL, "part_info = 0x%08x\n", ba.part_info);

	elements = sizeof(ba.md_type) / sizeof(ba.md_type[0]);
	dprintf(CRITICAL, "md_type[%d]:\n", elements);
	hexdump(ba.md_type, elements);

	// mdelay(1);
	dprintf(CRITICAL, "ddr_reserve_enable = 0x%08x\n", ba.ddr_reserve_enable);
	dprintf(CRITICAL, "ddr_reserve_success = 0x%08x\n", ba.ddr_reserve_success);
	dprintf(CRITICAL, "ddr_reserve_ready = 0x%08x\n", ba.ddr_reserve_ready);

	/* Print ptp_volt_info */
	// mdelay(1);
	dprintf(CRITICAL, "ptp_volt_info.first_volt = 0x%08x\n", ba.ptp_volt_info.first_volt);
	dprintf(CRITICAL, "ptp_volt_info.second_volt = 0x%08x\n", ba.ptp_volt_info.second_volt);
	dprintf(CRITICAL, "ptp_volt_info.third_volt = 0x%08x\n", ba.ptp_volt_info.third_volt);
	dprintf(CRITICAL, "ptp_volt_info.have_550 = 0x%08x\n", ba.ptp_volt_info.have_550);

	dprintf(CRITICAL, "dram_buf_size = 0x%08x\n", ba.dram_buf_size);

	/* Print emi info */
	// mdelay(1);
	emi_info_t *p_emi = &ba.emi_info;
	dprintf(CRITICAL, "emi_info.dram_type = 0x%08x\n", p_emi->dram_type);
	dprintf(CRITICAL, "emi_info.ch_num = 0x%08x\n", p_emi->ch_num);
	dprintf(CRITICAL, "emi_info.rk_num = 0x%08x\n", p_emi->rk_num);
	elements = sizeof(p_emi->rank_size) / sizeof(p_emi->rank_size[0]);
	for (i = 0; i < elements; i++)
	{
		dprintf(CRITICAL, "emi_info.rank_size[%d] = 0x%08x_%08x\n", i,
			(unsigned int)(p_emi->rank_size[i] >> 32),
			(unsigned int)(p_emi->rank_size[i] & 0xFFFFFFFF));
		// mdelay(1);
	}

	dprintf(CRITICAL, "meta_uart_port = 0x%08x\n", ba.meta_uart_port);
	dprintf(CRITICAL, "smc_boot_opt = 0x%08x\n", ba.smc_boot_opt);
	dprintf(CRITICAL, "lk_boot_opt = 0x%08x\n", ba.lk_boot_opt);
	dprintf(CRITICAL, "kernel_boot_opt = 0x%08x\n", ba.kernel_boot_opt);
	dprintf(CRITICAL, "non_secure_sram_addr = 0x%08x\n", ba.non_secure_sram_addr);
	dprintf(CRITICAL, "non_secure_sram_size = 0x%08x\n", ba.non_secure_sram_size);

	elements = sizeof(ba.pl_version) / sizeof(ba.pl_version[0]);
	dprintf(CRITICAL, "pl_version[%d]:\n", elements);
	hexdump(ba.pl_version, elements);

	// mdelay(1);
	dprintf(CRITICAL, "pl_imgver_status = 0x%08x\n", ba.pl_imgver_status);
	dprintf(CRITICAL, "max_cpus = 0x%08x\n", ba.max_cpus);
	dprintf(CRITICAL, "boot_voltage = 0x%08x\n", ba.boot_voltage);
	dprintf(CRITICAL, "shutdown_time = 0x%08x\n", ba.shutdown_time);

	// mdelay(1);
	dprintf(CRITICAL, "==============================================\n");
	dprintf(CRITICAL, "=       End of printing boot arguement       =\n");
	dprintf(CRITICAL, "==============================================\n");
	mtk_wdt_restart();
#endif  // FPGA_PRINT_BOOT_ARGUMENT
}


/******************************************************************************
******************************************************************************/
void fpga_set_boot_argument(BOOT_ARGUMENT *pba)
{
#ifdef FPGA_SET_BOOT_ARGUMENT
	memset((void*)pba, 0, sizeof(*pba));

	pba->maggic_number = 0x504c504c;
	// pba->boot_mode = 0;
	// pba->e_flag = 0;
	pba->log_port = 0x11003000;
	pba->log_baudrate = 0x000e1000;  /* 0xe1000: 921600 */
	pba->log_enable = 1;
	pba->log_dynamic_switch = 1;

	pba->part_num = 2;
	// pba->reserved[0] = 0;
	// pba->reserved[1] = 0;
	pba->dram_rank_num = 2;
	pba->dram_rank_size[0] = 0x10000000ULL;
	pba->dram_rank_size[1] = 0x10000000ULL;
	// pba->dram_rank_size[2] = 0ULL;
	// pba->dram_rank_size[3] = 0ULL;

	/* Set mblock_info */
	pba->mblock_info.mblock_num = 2;
	pba->mblock_info.mblock[0].start = 0x40000000ULL;
	pba->mblock_info.mblock[0].size = 0x10000000ULL;
	pba->mblock_info.mblock[0].rank = 0ULL;
	pba->mblock_info.mblock[1].start = 0x50000000ULL;
	pba->mblock_info.mblock[1].size = 0x0fe00000ULL;
	pba->mblock_info.mblock[1].rank = 1ULL;
	pba->mblock_info.mblock_magic = MBLOCK_MAGIC;
	pba->mblock_info.mblock_version = MBLOCK_VERSION;
	pba->mblock_info.reserved_num = 0;

	/* Set dram info */
	pba->orig_dram_info.rank_num = 2;
	pba->orig_dram_info.rank_info[0].start = 0x40000000ULL;
	pba->orig_dram_info.rank_info[0].size = 0x10000000ULL;
	pba->orig_dram_info.rank_info[1].start = 0x50000000ULL;
	pba->orig_dram_info.rank_info[1].size = 0x10000000ULL;

	// pba->lca_reserved_mem.start = 0;
	// pba->lca_reserved_mem.size = 0;

	pba->tee_reserved_mem.start = 0x5fe00000ULL;
	pba->tee_reserved_mem.size = 0x00200000ULL;

	// pba->boot_reason = 0;
	// pba->meta_com_type = META_UNKNOWN_COM;
	// pba->meta_com_id = 0;
	// pba->boot_time = 0;

	/* Set da_info */
	// pba->da_info.addr = 0;
	// pba->da_info.arg1 = 0;
	// pba->da_info.arg2 = 0;
	// pba->da_info.len = 0;
	// pba->da_info.sig_len = 0;

	// pba->sec_limit.magic_num = 0;
	// pba->sec_limit.forbid_mode = F_FACTORY_MODE;

	pba->part_info = 0x40079a84;  // Needed???

	// pba->md_type[0] = 0;
	// pba->md_type[1] = 0;
	// pba->md_type[2] = 0;
	// pba->md_type[3] = 0;

	// pba->ddr_reserve_enable = 0;
	// pba->ddr_reserve_success = 0;
	// pba->ddr_reserve_ready = 0;

	/* Set ptp_volt_info */
	// pba->ptp_volt_info.first_volt = 0;
	// pba->ptp_volt_info.second_volt = 0;
	// pba->ptp_volt_info.third_volt = 0;
	// pba->ptp_volt_info.have_550 = 0;

	pba->dram_buf_size = 0x00199880;  // Needed???

	/* Set emi info */
	// pba->emi_info.dram_type = 0;
	// pba->emi_info.ch_num = 0;
	// pba->emi_info.rk_num = 0;
	// pba->emi_info.rank_size[0] = 0ULL;
	// pba->emi_info.rank_size[1] = 0ULL;

	pba->meta_uart_port = 0x11003000;  // Needed???
	// pba->smc_boot_opt = 0;
	pba->lk_boot_opt = 3;  // Needed???
	// pba->kernel_boot_opt = 0;
	pba->non_secure_sram_addr = 0x0012c000;  // Needed???
	pba->non_secure_sram_size = 0x00004000;  // Needed???

	// pba->pl_version[0] = '\0';
	// pba->pl_version[1] = '\0';
	// pba->pl_version[2] = '\0';
	// pba->pl_version[3] = '\0';
	// pba->pl_version[4] = '\0';
	// pba->pl_version[5] = '\0';
	// pba->pl_version[6] = '\0';
	// pba->pl_version[7] = '\0';

	// pba->pl_imgver_status = 0;
	// pba->max_cpus = 1;  // Needed???
	// pba->boot_voltage = 0;
	// pba->shutdown_time = 0;
#endif  // FPGA_SET_BOOT_ARGUMENT
}

