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

#ifndef _SEC_H_
#define _SEC_H_

#include <platform/mt_typedefs.h>
#include <platform/sec_status.h>
#include <sys/types.h>

/* exported functions */
int security_preprocess(void **data, unsigned *size, unsigned offset, int dev_type);
int security_postprocess(int sec_part_index);
int security_init(void **data, unsigned *size, int dev_type, int sec_part_index);
int security_deinit(void);
unsigned int seclib_sec_boot_enabled(unsigned int);
unsigned int AES_decrypt_by_cmnkey(u8 *src_buf, u8 *dst_buf, u32 length);
/*---------------------------------------------------------------------------*/
int install_sig(void *data, unsigned size);
int get_chunk_size(unsigned int *chunk_size);
int get_img_name(unsigned char *img_name, unsigned int len);
/*---------------------------------------------------------------------------*/
/* API for controlling debug ports                                           */
/*---------------------------------------------------------------------------*/
/* flags returned by sec_dbgport_read_hw_config*/
#define DBGPORT_HW_JTAG_DIS     0x0001
#define DBGPORT_SW_JTAG_CON     0x0002
#define DBGPORT_BROM_LOCK_DIS   0x0004
/*---------------------------------------------------------------------------*/
U32 sec_dbgport_read_hw_config(void);
void sec_dbgport_enable(bool bSecDebugEnable);
void sec_dbgport_disable(void);
void sec_dbgport_lock(void);
void sec_dbgport_dump(void);
bool sec_dbgport_test(bool dbg_en, bool sec_dbg_en);
unsigned int AES_decrypt_by_cmnkey(u8 *src_buf, u8 *dst_buf, u32 length);
/*---------------------------------------------------------------------------*/

/*device information*/
#define ATAG_MASP_DATA         0x41000866

#define NUM_SBC_PUBK_HASH           8
#define NUM_CRYPTO_SEED          16
#define NUM_RID 4

struct tag_masp_data {
	unsigned int rom_info_sbc_attr;
	unsigned int rom_info_sdl_attr;
	unsigned int hw_sbcen;
	unsigned int lock_state;
	unsigned int rid[NUM_RID];
	/*rom_info.m_SEC_KEY.crypto_seed*/
	unsigned char crypto_seed[NUM_CRYPTO_SEED];
	unsigned int sbc_pubk_hash[NUM_SBC_PUBK_HASH];
};
#endif /* _SEC_H_ */
