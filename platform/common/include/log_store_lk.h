/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#ifndef __LOG_STORE_LK_H__
#define __LOG_STORE_LK_H__

#include <stdio.h>
#include <string.h>
#include "ram_console.h"

typedef unsigned int u32;
#ifndef u8
typedef unsigned char u8;
#endif

#ifdef LK_LOG_LEVEL_SUPPORT
#define LOG_LEVEL_MASK (0xABC0)
#endif

#define SRAM_HEADER_SIG (0xabcd1234)
#define DRAM_HEADER_SIG (0x5678ef90)
#define LOG_STORE_SIG (0xcdab3412)
#define LOG_EMMC_SIG (0x785690ef)

#define MAX_DRAM_COUNT  2

#define LOG_STORE_SIZE 0x40000  /* DRAM buff 256KB */
#define LOG_STORE_SIZE_MIRROR 0x40000  /* mirror DRAM buff 256KB */
#define KEDUMP_ENABLE 0xecab1e
#define KEDUMP_DISABLE 0xd15ab1e

/*  log flag */
#define BUFF_VALIE      0x01
#define CAN_FREE        0x02
#define NEED_SAVE_TO_EMMC   0x04
#define RING_BUFF       0x08
/* ring buf, if buf_full, buf_point is the start of the buf, else buf_point is the buf end, other buf is not used */
#define BUFF_FULL       0x10    /* buf is full */
#define ARRAY_BUFF      0X20    /* array buf type, buf_point is the used buf end */
#define BUFF_ALLOC_ERROR    0X40
#define BUFF_ERROR      0x80
#define BUFF_NOT_READY  0x100
#define BUFF_READY      0x200

#define RATELIMIT_DISABLE 0X44495341 // acsii-DISA
#define RATELIMIT_ENABLE 0X454E454E // acsii-ENEN

enum {
	UART_LOG = 0x00,
	LOG_LEVEL = 0X01,
	PRINTK_RATELIMIT = 0X02,
	KEDUMP_CTL = 0x03,
} EMMC_STORE_TYPE;

/* total 32 bytes <= u32(4 bytes) * 8 = 32 bytes */
struct pl_lk_log {
	u32 sig;            // default 0xabcd1234
	u32 buff_size;      // total buf size
	u32 off_pl;         // pl offset, sizeof(struct pl_lk_log)
	u32 sz_pl;          // preloader size
	u32 pl_flag;        // pl log flag
	u32 off_lk;         // lk offset, sizeof((struct pl_lk_log) + sz_pl
	u32 sz_lk;          // lk log size
	u32 lk_flag;        // lk log flag
};

/* total 40 bytes <= u32(4 bytes) * 10 = 40 bytes */
struct dram_buf_header {
	u32 sig;
	u32 flag;
	u32 buf_addr;
	u32 buf_size;
	u32 buf_offsize;
	u32 buf_point;
	u32 klog_addr;
	u32 klog_size;
	u32 atf_log_addr;
	u32 atf_log_len;
};

/* total 256 bytes */
struct sram_log_header {
	u32 sig;
	u32 reboot_count;
	u32 save_to_emmc;
	struct dram_buf_header dram_buf;        // 40 bytes
	struct pl_lk_log dram_curlog_header;    // 32 bytes
	u32 gz_log_addr;
	u32 gz_log_len;
	u32 reserve[41];                        // reserve 41 * 4 char size(164 bytes)
};

/* emmc last block struct */
struct log_emmc_header {
	u32 sig;
	u32 offset;
	u32 uart_flag;
	u32 reserve[10];
};

#ifdef LOG_STORE_SUPPORT
extern bool log_store_enable;
void set_uart_log_flag(bool enable);
void set_printk_ratelimit(bool enable);
void read_ratelimit_config(void);
int read_kedump_config(void);
#ifdef LK_LOG_LEVEL_SUPPORT
void set_lk_log_level(int level);
#endif
void lk_log_store(char c);
u32 mirror_buf_addr_get(void);
u32 mirror_buf_pl_lk_log_size_get(void);
u32 current_buf_addr_get(void);
u32 current_lk_buf_addr_get(void);
u32 current_buf_pl_lk_log_size_get(void);
void save_pllk_log(void);

#else /* no log store feature set function null*/

inline void set_uart_log_flag(bool enable){}
inline void set_printk_ratelimit(bool enable){}
inline void read_ratelimit_config(void){}
inline int read_kedump_config(void)
{
	return 1;
}
#ifdef LK_LOG_LEVEL_SUPPORT
inline void set_lk_log_level(int level){}
#endif
inline void lk_log_store(char c){}
inline u32 mirror_buf_addr_get(void){return 0;}
inline u32 mirror_buf_pl_lk_log_size_get(void){return 0;}
inline u32 current_buf_addr_get(void){return 0;}
inline u32 current_lk_buf_addr_get(void){return 0;}
inline u32 current_buf_pl_lk_log_size_get(void){return 0;}
inline void save_pllk_log(void){}
#endif
#endif

