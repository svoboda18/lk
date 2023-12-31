/*
 * Copyright (c) 2013 MediaTek Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <platform/mt_reg_base.h>

#ifndef MTK_QMU_H
#define MTK_QMU_H

#define USB_HW_QMU_BASE 0x86000800
#define USB_HW_QMU_LENGTH  0x500
/// @brief Define DMAQ Register Bass Address
/// @Author_Name:tianhao.fei 4/29/2010
/// @{

#define USB_QMUBASE	USB_BASE + 0x800
#define USB_QISAR       USB_BASE + 0xc00
#define USB_QIMR        USB_BASE + 0xc04

#define USB_HW_QMU_OFF  USB_QMUBASE + 0x0000
#define USB_HW_QUCS_OFF USB_QMUBASE + 0x0300
#define USB_HW_QIRQ_OFF USB_QMUBASE + 0x0400
#define USB_HW_QDBG_OFF USB_QMUBASE + 0x04F0

/// @}
//#define GPD_LEN_ALIGNED (32)  /* Note: ARM should align cache line size */
#define GPD_LEN_ALIGNED (64)  /* > sizeof (TGPD) + sizeof (list_head)*/
// KOBE , modify

#define RXQ_NUM 1
#define TXQ_NUM 1


/// @brief  Define DMAQ Register Offset
/// @Author_Name:tianhao.fei 4/29/2010
/// @{
#define MGC_O_QMU_QCR0  0x0000
#define MGC_O_QMU_QCR2  0x0008
#define MGC_O_QMU_QCR3  0x000C

#define MGC_O_QMU_RQCSR0    0x0010
#define MGC_O_QMU_RQSAR0    0x0014
#define MGC_O_QMU_RQCPR0    0x0018
#define MGC_O_QMU_RQCSR(n) (MGC_O_QMU_RQCSR0+0x0010*((n)-1))
#define MGC_O_QMU_RQSAR(n) (MGC_O_QMU_RQSAR0+0x0010*((n)-1))
#define MGC_O_QMU_RQCPR(n) (MGC_O_QMU_RQCPR0+0x0010*((n)-1))


#define MGC_O_QMU_RQTR_BASE 0x0090
#define MGC_O_QMU_RQTR(n)       (MGC_O_QMU_RQTR_BASE+0x4*((n)-1))
#define MGC_O_QMU_RQLDPR0       0x0100
#define MGC_O_QMU_RQLDPR(n)     (MGC_O_QMU_RQLDPR0+0x4*((n)-1))


#define MGC_O_QMU_TQCSR0    0x0200
#define MGC_O_QMU_TQSAR0    0x0204
#define MGC_O_QMU_TQCPR0    0x0208
#define MGC_O_QMU_TQCSR(n) (MGC_O_QMU_TQCSR0+0x0010*((n)-1))
#define MGC_O_QMU_TQSAR(n) (MGC_O_QMU_TQSAR0+0x0010*((n)-1))
#define MGC_O_QMU_TQCPR(n) (MGC_O_QMU_TQCPR0+0x0010*((n)-1))

#define MGC_O_QMU_QAR       0x0300
#define MGC_O_QUCS_USBGCSR  0x0000
#ifdef MTK_WDMAQ
/*wimax only*/
#define MGC_O_QUCS_TQUSBSC_BASE     0x0080
#define MGC_O_QUCS_TQUSBSC(n)           (MGC_O_QUCS_TQUSBSC_BASE+0x4*((n)-1))
#define MGC_O_QUCS_FW1          0x0004
#define MGC_O_QUCS_FW2          0x0008
/*end*/
#endif
#define MGC_O_QIRQ_QISAR        0x0000
#define MGC_O_QIRQ_QIMR     0x0004
#define MGC_O_QIRQ_QIMCR        0x0008
#define MGC_O_QIRQ_QIMSR        0x000C
#ifdef MTK_WDMAQ
/*wimax only*/
#define MGC_O_QIRQ_QSISAR       0x0010
#define MGC_O_QIRQ_DSIMR        0x0014
#define MGC_O_QIRQ_DSIMCR       0x0018
#define MGC_O_QIRQ_DSIMSR       0x001C
#define MGC_O_QIRQ_DSICR        0x0020
/*end*/
#endif
#define MGC_O_QIRQ_IOCDISR    0x0030
#define MGC_O_QIRQ_TEPEMPR  0x0060
#define MGC_O_QIRQ_TEPEMPMR 0x0064
#define MGC_O_QIRQ_TEPEMPMCR    0x0068
#define MGC_O_QIRQ_TEPEMPMSR    0x006C
#define MGC_O_QIRQ_REPEMPR  0x0070
#define MGC_O_QIRQ_REPEMPMR 0x0074
#define MGC_O_QIRQ_REPEMPMCR    0x0078
#define MGC_O_QIRQ_REPEMPMSR    0x007C

#define MGC_O_QIRQ_RQEIR        0x0090
#define MGC_O_QIRQ_RQEIMR       0x0094
#define MGC_O_QIRQ_RQEIMCR  0x0098
#define MGC_O_QIRQ_RQEIMSR  0x009C
#define MGC_O_QIRQ_REPEIR       0x00A0
#define MGC_O_QIRQ_REPEIMR  0x00A4
#define MGC_O_QIRQ_REPEIMCR 0x00A8
#define MGC_O_QIRQ_REPEIMSR 0x00AC
#define MGC_O_QIRQ_TQEIR        0x00B0
#define MGC_O_QIRQ_TQEIMR       0x00B4
#define MGC_O_QIRQ_TQEIMCR  0x00B8
#define MGC_O_QIRQ_TQEIMSR  0x00BC
#define MGC_O_QIRQ_TEPEIR       0x00C0
#define MGC_O_QIRQ_TEPEIMR  0x00C4
#define MGC_O_QIRQ_TEPEIMCR 0x00C8
#define MGC_O_QIRQ_TEPEIMSR 0x00CC


#define MGC_O_QDBG_DFCR 0x0000
#define MGC_O_QDBG_DFMR 0x0004
/// @}

/// @brief Queue Control value Definition
/// @Author_Name:tianhao.fei 4/29/2010
/// @{
#define DQMU_QUE_START  0x00000001
#define DQMU_QUE_RESUME 0x00000002
#define DQMU_QUE_STOP       0x00000004
#define DQMU_QUE_ACTIVE 0x00008000
/// @}

/// @brief USB QMU Special Control USBGCSR value Definition
/// @Author_Name:tianhao.fei 4/29/2010
/// @{
#define USB_QMU_Tx0_EN          0x00000001
#define USB_QMU_Tx_EN(n)            (USB_QMU_Tx0_EN<<((n)-1))
#if 1 //CC_TEST
#define USB_QMU_Rx0_EN          0x00010000
#else
#define USB_QMU_Rx0_EN          0x00000020
#endif
#define USB_QMU_Rx_EN(n)            (USB_QMU_Rx0_EN<<((n)-1))
#define USB_QMU_HIFEVT_EN           0x00000100
#define USB_QMU_HIFCMD_EN           0x01000000
#define DQMU_SW_RESET       0x00010000
#define DQMU_CS16B_EN       0x80000000
#define DQMU_TQ0CS_EN       0x00010000
#define DQMU_TQCS_EN(n) (DQMU_TQ0CS_EN<<((n)-1))
#define DQMU_RQ0CS_EN       0x00000001
#define DQMU_RQCS_EN(n) (DQMU_RQ0CS_EN<<((n)-1))
#define DQMU_TX0_ZLP        0x01000000
#define DQMU_TX_ZLP(n)      (DQMU_TX0_ZLP<<((n)-1))
#define DQMU_TX0_MULTIPLE   0x00010000
#define DQMU_TX_MULTIPLE(n) (DQMU_TX0_MULTIPLE<<((n)-1))
#ifdef MTK_WDMAQ
#define DQMU_TX_PADDING 0x00000002
#define DQMU_TX_SDUHDR  0x00000001
#endif
#define DQMU_RX0_MULTIPLE   0x00010000
#define DQMU_RX_MULTIPLE(n) (DQMU_RX0_MULTIPLE<<((n)-1))
#ifdef MTK_WDMAQ
#define DQMU_RX_SDUHDR  0x00000001
#endif
#define DQMU_RX0_ZLP        0x01000000
#define DQMU_RX_ZLP(n)      (DQMU_RX0_ZLP<<((n)-1))

#define DQMU_M_TXEP_ERR 0x10000000
#define DQMU_M_TXQ_ERR  0x08000000
#define DQMU_M_RXEP_ERR 0x04000000
#define DQMU_M_RXQ_ERR  0x02000000
#define DQMU_M_RQ_EMPTY 0x00020000
#define DQMU_M_TQ_EMPTY 0x00010000
#define DQMU_M_RX0_EMPTY    0x00000001
#define DQMU_M_RX_EMPTY(n)  (DQMU_M_RX0_EMPTY<<((n)-1))
#define DQMU_M_TX0_EMPTY    0x00000001
#define DQMU_M_TX_EMPTY(n)  (DQMU_M_TX0_EMPTY<<((n)-1))
#define DQMU_M_RX0_DONE 0x00000100
#define DQMU_M_RX_DONE(n)   (DQMU_M_RX0_DONE<<((n)-1))
#define DQMU_M_TX0_DONE 0x00000001
#define DQMU_M_TX_DONE(n)   (DQMU_M_TX0_DONE<<((n)-1))

#define DQMU_M_RX0_ZLP_ERR  0x01000000
#define DQMU_M_RX_ZLP_ERR(n)    (DQMU_M_RX0_ZLP_ERR<<((n)-1))
#ifdef MTK_WDMAQ
#define DQMU_M_RX0_HDR_ERR  0x00010000
#define DQMU_M_RX_HDR_ERR(n)    (DQMU_M_RX0_HDR_ERR<<((n)-1))
#endif
#define DQMU_M_RX0_LEN_ERR  0x00000100
#define DQMU_M_RX_LEN_ERR(n)    (DQMU_M_RX0_LEN_ERR<<((n)-1))
#define DQMU_M_RX0_GPDCS_ERR        0x00000001
#define DQMU_M_RX_GPDCS_ERR(n)  (DQMU_M_RX0_GPDCS_ERR<<((n)-1))

#define DQMU_M_TX0_LEN_ERR  0x00010000
#define DQMU_M_TX_LEN_ERR(n)    (DQMU_M_TX0_LEN_ERR<<((n)-1))
#define DQMU_M_TX0_GPDCS_ERR    0x00000100
#define DQMU_M_TX_GPDCS_ERR(n)  (DQMU_M_TX0_GPDCS_ERR<<((n)-1))
#define DQMU_M_TX0_BDCS_ERR     0x00000001
#define DQMU_M_TX_BDCS_ERR(n)   (DQMU_M_TX0_BDCS_ERR<<((n)-1))

#define DQMU_M_TX0_EP_ERR       0x00000001
#define DQMU_M_TX_EP_ERR(n) (DQMU_M_TX0_EP_ERR<<((n)-1))

#define DQMU_M_RX0_EP_ERR       0x00000001
#define DQMU_M_RX_EP_ERR(n) (DQMU_M_RX0_EP_ERR<<((n)-1))
#define DQMU_M_RQ_DIS_IOC(n)   (0x100<<((n)-1))
/// @}


/**
 * @brief Read a 8-bit register from the core
 * @param _pBase core base address in memory
 * @param _offset offset into the core's register space
 * @return 16-bit datum
 */
#define MGC_ReadQMU8(_offset) \
    DRV_Reg8((USB_HW_QMU_OFF + _offset))

#define MGC_ReadQUCS8(base,_offset) \
    DRV_Reg8((USB_HW_QUCS_OFF + _offset))

#define MGC_ReadQIRQ8(base,_offset) \
    DRV_Reg8((USB_HW_QIRQ_OFF + _offset))

/**
 * @brief Read a 16-bit register from the core
 * @param _pBase core base address in memory
 * @param _offset offset into the core's register space
 * @return 16-bit datum
 */
#define MGC_ReadQMU16(_offset) \
    DRV_Reg((USB_HW_QMU_OFF + _offset))

#define MGC_ReadQUCS16(_offset) \
    DRV_Reg((USB_HW_QUCS_OFF + _offset))

#define MGC_ReadQIRQ16(_offset) \
    DRV_Reg((USB_HW_QIRQ_OFF + _offset))

/**
 * @brief Read a 32-bit register from the core
 * @param _pBase core base address in memory
 * @param _offset offset into the core's register space
 * @return 32-bit datum
 */
#define MGC_ReadQMU32(_offset) \
    DRV_Reg32((USB_HW_QMU_OFF + _offset))

#define MGC_ReadQUCS32(_offset) \
    DRV_Reg32((USB_HW_QUCS_OFF + _offset))

#define MGC_ReadQIRQ32(_offset) \
    DRV_Reg32((USB_HW_QIRQ_OFF + _offset))

/**
 * @briefWrite a 32-bit core register
 * @param _pBase core base address in memory
 * @param _offset offset into the core's register space
 * @param _data 32-bit datum
 */
#define MGC_WriteQMU32(_offset, _data) \
    DRV_WriteReg32((USB_HW_QMU_OFF + _offset), _data)

#define MGC_WriteQUCS32(_offset, _data) \
    DRV_WriteReg32((USB_HW_QUCS_OFF + _offset), _data)

#define MGC_WriteQIRQ32(_offset, _data) \
    DRV_WriteReg32((USB_HW_QIRQ_OFF + _offset), _data)

/**
 * TGPD
 */
typedef struct _TGPD {
	unsigned char   flag;
	unsigned char   chksum;
	unsigned short  DataBufferLen; /*Rx Allow Length*/
	struct _TGPD*   pNext;
	unsigned char*  pBuf;
	unsigned short  bufLen;
	unsigned char   ExtLength;
	unsigned char   ZTepFlag;
} TGPD, *PGPD;

typedef struct {
	TGPD gpd[2];
	kal_uint8 cur_gpd_index;
	TGPD *cur_ptr_gpd;
} gpd_pool;


/**
 * TBD
 */
typedef struct _TBD {
	unsigned char  flag;
	unsigned char  chksum;
	unsigned short  reserved1;
	struct _TBD *pNext;
	unsigned char*  pBuf;
	unsigned short bufLen;
	unsigned char  extLen;
	unsigned char  reserved2;
} TBD, *PBD;
/// @}

#define GPD_BUF_SIZE 65532
#define GPD_BUF_SIZE_ALIGN 64512 /* 63 * 1024 */
#define BD_BUF_SIZE 32768 //set to half of 64K of max size

void qmu_done_interrupt(u32 qmu_val);
void qmu_handler(u32 qmu_val);


struct tgpd {
	u8		flag;
	u8		chksum;
	u16		databuf_len; /*Rx Allow Length*/
	struct tgpd	*pnext;
	u8		*pBuf;
	u16		bufLen;
	u8		ExtLength;
	u8		ZTepFlag;
};

struct tbd {
	u8		flag;
	u8		chksum;
	u16		databuf_len; /* Rx Allow Length */
	struct	tbd	*pnext;
	u8		*pBuf;
	u16		bufLen;
	u8		extLen;
	u8		reserved;
};

struct gpd_range {
	struct tbd	*pnext;
	struct tbd	*pstart;
	struct tbd	*pend;
};

#define AT_GPD_EXT_LEN			256
#define AT_BD_EXT_LEN			256
//#define MAX_GPD_NUM			30 /* we've got problem when gpd is larger */
#define MAX_GPD_NUM			4
//#define MAX_BD_NUM			500
#define MAX_BD_NUM			3
#define STRESS_IOC_TH			8
#define STRESS_GPD_TH			24
#define RANDOM_STOP_DELAY		80
#define STRESS_DATA_LENGTH		1024*64 //1024*16

#define NO_ZLP 				0
#define HW_MODE				1
#define GPD_MODE			2

#define TXZLP				HW_MODE

#define MAX_QMU_EP			1

#define TGPD_FLAGS_HWO			0x01
#define TGPD_IS_FLAGS_HWO(_pd)		(((struct tgpd *)_pd)->flag & TGPD_FLAGS_HWO)
#define TGPD_SET_FLAGS_HWO(_pd)	 	(((struct tgpd *)_pd)->flag |= TGPD_FLAGS_HWO)
#define TGPD_CLR_FLAGS_HWO(_pd)		(((struct tgpd *)_pd)->flag &= (~TGPD_FLAGS_HWO))
#define TGPD_FORMAT_BDP		 	0x02
#define TGPD_IS_FORMAT_BDP(_pd)	 	(((struct tgpd *)_pd)->flag & TGPD_FORMAT_BDP)
#define TGPD_SET_FORMAT_BDP(_pd)	(((struct tgpd *)_pd)->flag |= TGPD_FORMAT_BDP)
#define TGPD_CLR_FORMAT_BDP(_pd)	(((struct tgpd *)_pd)->flag &= (~TGPD_FORMAT_BDP))
#define TGPD_FORMAT_BPS		 	0x04
#define TGPD_IS_FORMAT_BPS(_pd)	 	(((struct tgpd *)_pd)->flag & TGPD_FORMAT_BPS)
#define TGPD_SET_FORMAT_BPS(_pd)	(((struct tgpd *)_pd)->flag |= TGPD_FORMAT_BPS)
#define TGPD_CLR_FORMAT_BPS(_pd)	(((struct tgpd *)_pd)->flag &= (~TGPD_FORMAT_BPS))
#define TGPD_SET_FLAG(_pd, _flag)	((struct tgpd *)_pd)->flag = (((struct tgpd *)_pd)->flag&(~TGPD_FLAGS_HWO))|(_flag)
#define TGPD_GET_FLAG(_pd)	 	(((struct tgpd *)_pd)->flag & TGPD_FLAGS_HWO)
#define TGPD_SET_CHKSUM(_pd, _n)	((struct tgpd *)_pd)->chksum = mu3d_hal_cal_checksum((u8 *)_pd, _n)-1
#define TGPD_SET_CHKSUM_HWO(_pd, _n)	((struct tgpd *)_pd)->chksum = mu3d_hal_cal_checksum((u8 *)_pd, _n)-1
#define TGPD_GET_CHKSUM(_pd)		((struct tgpd *)_pd)->chksum
#define TGPD_SET_FORMAT(_pd, _fmt)	((struct tgpd *)_pd)->flag = (((struct tgpd *)_pd)->flag&(~TGPD_FORMAT_BDP))|(_fmt)
#define TGPD_GET_FORMAT(_pd)		((((struct tgpd *)_pd)->flag & TGPD_FORMAT_BDP)>>1)
#define TGPD_SET_DATABUF_LEN(_pd, _len)	((struct tgpd *)_pd)->databuf_len = _len
#define TGPD_ADD_DATABUF_LEN(_pd, _len)	((struct tgpd *)_pd)->databuf_len += _len
#define TGPD_GET_DATABUF_LEN(_pd)	((struct tgpd *)_pd)->databuf_len
#define TGPD_SET_NEXT(_pd, _next)	((struct tgpd *)_pd)->pnext = (struct tgpd *)_next;
#define TGPD_GET_NEXT(_pd)		(struct tgpd *)((struct tgpd *)_pd)->pnext
#define TGPD_SET_TBD(_pd, _tbd)	 	((struct tgpd *)_pd)->pBuf = (u8 *)_tbd;\
					TGPD_SET_FORMAT_BDP(_pd)
#define TGPD_GET_TBD(_pd)		(struct tbd *)((struct tgpd *)_pd)->pBuf
#define TGPD_SET_DATA(_pd, _data)	((struct tgpd *)_pd)->pBuf = (u8 *)_data
#define TGPD_GET_DATA(_pd)		(u8*)((struct tgpd *)_pd)->pBuf
#define TGPD_SET_BUF_LEN(_pd, _len) 	((struct tgpd *)_pd)->bufLen = _len
#define TGPD_ADD_BUF_LEN(_pd, _len) 	((struct tgpd *)_pd)->bufLen += _len
#define TGPD_GET_BUF_LEN(_pd)		((struct tgpd *)_pd)->bufLen
#define TGPD_SET_EXT_LEN(_pd, _len) 	((struct tgpd *)_pd)->ExtLength = _len
#define TGPD_GET_EXT_LEN(_pd)		((struct tgpd *)_pd)->ExtLength
#define TGPD_SET_EPaddr(_pd, _EP)	((struct tgpd *)_pd)->ZTepFlag =(((struct tgpd *)_pd)->ZTepFlag&0xF0)|(_EP)
#define TGPD_GET_EPaddr(_pd)		((struct tgpd *)_pd)->ZTepFlag & 0x0F
#define TGPD_FORMAT_TGL			0x10
#define TGPD_IS_FORMAT_TGL(_pd)	 	(((struct tgpd *)_pd)->ZTepFlag & TGPD_FORMAT_TGL)
#define TGPD_SET_FORMAT_TGL(_pd)	(((struct tgpd *)_pd)->ZTepFlag |=TGPD_FORMAT_TGL)
#define TGPD_CLR_FORMAT_TGL(_pd)	(((struct tgpd *)_pd)->ZTepFlag &= (~TGPD_FORMAT_TGL))
#define TGPD_FORMAT_ZLP			0x20
#define TGPD_IS_FORMAT_ZLP(_pd)	 	(((struct tgpd *)_pd)->ZTepFlag & TGPD_FORMAT_ZLP)
#define TGPD_SET_FORMAT_ZLP(_pd)	(((struct tgpd *)_pd)->ZTepFlag |=TGPD_FORMAT_ZLP)
#define TGPD_CLR_FORMAT_ZLP(_pd)	(((struct tgpd *)_pd)->ZTepFlag &= (~TGPD_FORMAT_ZLP))
#define TGPD_FORMAT_IOC			0x80
#define TGPD_IS_FORMAT_IOC(_pd)	 	(((struct tgpd *)_pd)->flag & TGPD_FORMAT_IOC)
#define TGPD_SET_FORMAT_IOC(_pd)	(((struct tgpd *)_pd)->flag |=TGPD_FORMAT_IOC)
#define TGPD_CLR_FORMAT_IOC(_pd)	(((struct tgpd *)_pd)->flag &= (~TGPD_FORMAT_IOC))
#define TGPD_SET_TGL(_pd, _TGL)		((struct tgpd *)_pd)->ZTepFlag |=(( _TGL) ? 0x10: 0x00)
#define TGPD_GET_TGL(_pd)		((struct tgpd *)_pd)->ZTepFlag & 0x10 ? 1:0
#define TGPD_SET_ZLP(_pd, _ZLP)		((struct tgpd *)_pd)->ZTepFlag |= ((_ZLP) ? 0x20: 0x00)
#define TGPD_GET_ZLP(_pd)		((struct tgpd *)_pd)->ZTepFlag & 0x20 ? 1:0
#define TGPD_GET_EXT(_pd)		((u8 *)_pd + sizeof(struct tgpd))


#define TBD_FLAGS_EOL			0x01
#define TBD_IS_FLAGS_EOL(_bd)		(((struct tbd *)_bd)->flag & TBD_FLAGS_EOL)
#define TBD_SET_FLAGS_EOL(_bd)		(((struct tbd *)_bd)->flag |= TBD_FLAGS_EOL)
#define TBD_CLR_FLAGS_EOL(_bd)		(((struct tbd *)_bd)->flag &= (~TBD_FLAGS_EOL))
#define TBD_SET_FLAG(_bd, _flag)	((struct tbd *)_bd)->flag = (u8)_flag
#define TBD_GET_FLAG(_bd)		((struct tbd *)_bd)->flag
#define TBD_SET_CHKSUM(_pd, _n)	 	((struct tbd *)_pd)->chksum = mu3d_hal_cal_checksum((u8 *)_pd, _n)
#define TBD_GET_CHKSUM(_pd)		((struct tbd *)_pd)->chksum
#define TBD_SET_DATABUF_LEN(_pd, _len) 	((struct tbd *)_pd)->databuf_len = _len
#define TBD_GET_DATABUF_LEN(_pd)	((struct tbd *)_pd)->databuf_len
#define TBD_SET_NEXT(_bd, _next)	((struct tbd *)_bd)->pnext = (struct tbd *)_next
#define TBD_GET_NEXT(_bd)		(struct tbd *)((struct tbd *)_bd)->pnext
#define TBD_SET_DATA(_bd, _data)	((struct tbd *)_bd)->pBuf = (u8 *)_data
#define TBD_GET_DATA(_bd)		(u8*)((struct tbd *)_bd)->pBuf
#define TBD_SET_BUF_LEN(_bd, _len)	((struct tbd *)_bd)->bufLen = _len
#define TBD_ADD_BUF_LEN(_bd, _len)	((struct tbd *)_bd)->bufLen += _len
#define TBD_GET_BUF_LEN(_bd)		((struct tbd *)_bd)->bufLen
#define TBD_SET_EXT_LEN(_bd, _len)	((struct tbd *)_bd)->extLen = _len
#define TBD_ADD_EXT_LEN(_bd, _len)	((struct tbd *)_bd)->extLen += _len
#define TBD_GET_EXT_LEN(_bd)		((struct tbd *)_bd)->extLen
#define TBD_GET_EXT(_bd)		((u8 *)_bd + sizeof(struct tbd))

u32 gpd_buf_size;
u32 g_dma_buffer_size;
struct tgpd *rx_gpd_head[15];
struct tgpd *tx_gpd_head[15];
struct tgpd *rx_gpd_end[15];
struct tgpd *tx_gpd_end[15];
struct tgpd *rx_gpd_last[15];
struct tgpd *tx_gpd_last[15];
struct gpd_range rx_gpd_list[15] __attribute__((aligned(64)));
struct gpd_range tx_gpd_list[15] __attribute__((aligned(64)));

u32 rx_gpd_offset[15];
u32 tx_gpd_offset[15];

/*
 * declare function
 */
void mu3d_hal_insert_transfer_gpd(int ep_num, u8 dir, u8* buf, u32 count, u8 ishwo, u8 ioc, u8 bps, u8 zlp, u32 max_pkt_size);
void mu3d_hal_resume_qmu(int q_ep_num, u8 dir);
void mu3d_hal_alloc_qmu_mem(void);
void mu3d_hal_init_qmu(void);
void usb_start_qmu(int q_ep_num, u8 dir);
void mu3d_hal_stop_qmu(int q_ep_num, u8 dir);
void mu3d_hal_flush_qmu(int q_ep_num, u8 dir);

#endif
