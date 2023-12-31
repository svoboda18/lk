#ifndef __MT_REG_BASE
#define __MT_REG_BASE

#define BOOTROM_BASE (0x00000000)
#define BOOTSRAM_BASE (0x00100000)
#define IO_PHYS (0x10000000)

#define TOPCKGEN_BASE (0x10000000)

#define INTER_SRAM (0x00100000)

// APB Module top_clock_ctrl
#define TOP_CLOCK_CTRL_BASE (0x10000000)

// APB Module infracfg_ao
#define INFRACFG_AO_BASE (0x10001000)

// APB Module kp
#define KP_BASE (0x10002000)

// APB Module pericfg
#define PERICFG_BASE (0x10003000)

// APB Module gpio
#define GPIO_BASE (0x10005000)

// APB Module sleep
#define SLEEP_BASE (0x10006000)

// APB Module toprgu
#define TOPRGU_BASE (0x10007000)

// APB Module apxgpt
#define APXGPT_BASE (0x10008000)

// APB Module efusec
#define EFUSEC_BASE (0x10009000)

// APB Module sej
#define SEJ_BASE (0x1000A000)

// APB Module ap_cirq_eint
#define APIRQ_BASE (0x1000B000)

// APB Module ccif
#define AP_CCIF0_BASE (0x1000C000)

// APB Module aes_top
#define AES_BASE (0x1000E000)

// APB Module pmic_wrap
#define PWRAP_BASE (0x1000F000)

// APB Module device_apc_ao
#define DEVAPC_AO_BASE (0x10010000)

// APB Module mipi_rx_ana
#define MIPI_RX_ANA_BASE (0x10011800)

// APB Module infra_mbist
#define INFRA_MBIST_BASE (0x10012000)

// APB Module io_cfg_t
#define IO_CFG_T_BASE (0x10014000)

// APB Module io_cfg_b
#define IO_CFG_B_BASE (0x10015000)

// APB Module io_cfg_l
#define IO_CFG_L_BASE (0x10016000)

// APB Module io_cfg_r
#define IO_CFG_R_BASE (0x10017000)

// APB Module apmixedsys
#define APMIXEDSYS_BASE (0x10018000)

// APB Module dbgapb
#define DBGAPB_BASE (0x10100000)

// APB Module mcucfg
#define MCUCFG_BASE (0x10200000)
#define CA7MCUCFG_BASE (0x10200000)

// APB Module infracfg
#define INFRACFG_BASE (0x10201000)

// APB Module sys_cirq
#define SYS_CIRQ_BASE (0x10202000)

// APB Module m4u
#define M4U_BASE (0x10203000)

// APB Module nb_mmu
#define NB_MMU0_BASE (0x10203200)

// APB Module nb_mmu
#define NB_MMU1_BASE (0x10203800)

// APB Module device_apc
#define DEVAPC_BASE (0x10204000)

// APB Module bus_dbg_tracker_cfg
#define BUS_DBG_BASE (0x1020B000)

// APB Module emi
#define EMI_BASE (0x10205000)

// APB Module dramc
#define DRAMC_NAO_BASE (0x10206000)

// APB Module dramc_conf
#define DRAMC0_BASE (0x10207000)

// APB Module ddrphy
#define DDRPHY_BASE (0x10208000)

// APB Module sramrom
#define SRAMROM_BASE (0x10209000)

// APB Module gce
#define GCE_BASE (0x1020A000)

// APB Module cq_dma
#define CQ_DMA_BASE (0x1020AC00)

// APB Module bus
#define DBG_TRACKER_BASE (0x1020B000)

// APB Module trng
#define TRNG_BASE (0x1020C000)

// APB Module ca9
#define CA9_BASE (0x10210000)

// APB Module ap_p_dma
#define AP_DMA_BASE (0x11000000)

// APB Module nfi
#define NFI_BASE (0x11001000)

// APB Module nfiecc
#define NFIECC_BASE (0x11002000)

// APB Module auxadc
#define AUXADC_BASE (0x11003000)

// APB Module fhctl
#define FHCTL_BASE (0x11004000)

// APB Module uart
#define AP_UART0_BASE (0x11005000)

// APB Module uart
#define AP_UART1_BASE (0x11006000)

// APB Module uart
#define AP_UART2_BASE (0x11007000)

// add to fix build error, need to review the address
#define AP_UART3_BASE (0x11007000)

// APB Module pwm
#define PWM_BASE (0x11008000)

// APB Module i2c
#define I2C0_BASE (0x11009000)

// APB Module i2c
#define I2C1_BASE (0x1100A000)

// APB Module i2c
#define I2C2_BASE (0x1100B000)

// APB Module spi
#define SPI1_BASE (0x1100C000)

// APB Module therm_ctrl
#define THERM_CTRL_BASE (0x1100D000)

// APB Module btif
#define BTIF_BASE (0x1100E000)

// APB Module disp_pwm
#define DISP_PWM0_BASE (0x1100F000)

// APB Module usb2
#define USB_BASE (0x11100000)

// APB Module usb
#define USBSIF_BASE (0x11110000)

// APB Module msdc
#define MSDC0_BASE (0x11120000)

// APB Module msdc
#define MSDC1_BASE (0x11130000)

// add to fix build error, need to review the address
#define MSDC2_BASE (0x11130000)
// add to fix build error, need to review the address
#define MSDC3_BASE (0x11130000)

// APB Module AHB_MON_ABORT
#define AHBABT_BASE (0x11150000)

// APB Module mfg_top
#define MFGCFG_BASE (0x13000000)

// APB Module mali
#define MALI_BASE (0x13010000)

// APB Module mali_tb_cmd
#define MALI_TB_BASE (0x1301f000)

// APB Module mmsys_config
#define MMSYS_CONFIG_BASE (0x14000000)

// APB Module mdp_rdma
#define MDP_RDMA_BASE (0x14001000)

// APB Module mdp_rsz
#define MDP_RSZ0_BASE (0x14002000)

// APB Module mdp_rsz
#define MDP_RSZ1_BASE (0x14003000)

// APB Module disp_wdma
#define MDP_WDMA_BASE (0x14004000)

// APB Module mdp_wrot
#define MDP_WROT_BASE (0x14005000)

// APB Module mdp_tdshp
#define MDP_TDSHP_BASE (0x14006000)

// APB Module ovl
#define DISP_OVL0_BASE (0x14007000)

// APB Module ovl
#define DISP_OVL1_BASE (0x14008000)

// APB Module disp_rdma
#define DISP_RDMA0_BASE (0x14009000)

// APB Module disp_rdma
#define DISP_RDMA1_BASE (0x1400a000)

// APB Module disp_wdma
#define DISP_WDMA0_BASE (0x1400b000)

// APB Module disp_color_config
#define DISP_COLOR_BASE (0x1400c000)

// APB Module disp_ccorr
#define DISP_CCORR_BASE (0x1400d000)

// APB Module disp_aal
#define DISP_AAL_BASE (0x1400e000)

// APB Module disp_gamma
#define DISP_GAMMA_BASE (0x1400f000)

// APB Module disp_dither
#define DISP_DITHER_BASE (0x14010000)

// APB Module disp_ufoe_config
#define DISP_UFOE_BASE (0x14011000)

// APB Module dsi
#define DSI0_BASE (0x14012000)

// APB Module disp_dpi
#define DPI0_BASE (0x14013000)

// APB Module disp_mutex
#define MM_MUTEX_BASE (0x14015000)

// APB Module smi_larb
#define SMI_LARB0_BASE (0x14016000)

// APB Module smi
#define SMI_COMMON_BASE (0x14017000)

// APB Module mipi_tx_config
#define MIPI_TX0_BASE (0x14018000)

// APB Module disp_wdma
#define DISP_WDMA1_BASE (0x14038000)

// APB Module cam_all
#define CAM_BASE (0x14010000)

// APB Module seninf_top
#define SENINF_TOP_BASE (0x14012000)

// APB Module seninf
#define SENINF_BASE (0x14012000)

// APB Module csi2
#define CSI2_BASE (0x14012000)

// APB Module ncsi2
#define NCSI2_BASE (0x14012000)

// APB Module seninf_tg
#define SENINF_TG_BASE (0x14012000)

// APB Module scam
#define SCAM_BASE (0x14012000)

// APB Module ccir656
#define CCIR656_BASE (0x14012000)

// APB Module mipi_rx_config
#define MIPI_RX_CONFIG_BASE (0x14013000)
// add to fix build error, need to review the address
#define MIPI_RX_ANA_CSI0_BASE (0x14013000)
// add to fix build error, need to review the address
#define MIPI_RX_ANA_CSI1_BASE (0x14013000)

// APB Module venc
#define VENC_BASE (0x14016000)

// APB Module vdec
#define VDEC_BASE (0x14017000)

#define IMGSYS_BASE (0x15000000)

// APB Module smi_larb
#define SMI_LARB2_BASE (0x15001000)

// APB Module smi_larb
#define SMI_LARB3_BASE (0x15001000)

// APB Module mmu
#define SMI_LARB3_MMU_BASE (0x15001800)

// APB Module smi_larb
#define SMI_LARB4_BASE (0x15002000)

// APB Module fake_eng
#define FAKE_ENG_BASE (0x15002000)

// APB Module mmu
#define SMI_LARB4_MMU_BASE (0x15002800)

// APB Module jpgdec
#define JPGDEC_BASE (0x15009000)

// APB Module vdecsys_config
#define VDEC_GCON_BASE (0x16000000)

// APB Module smi_larb
#define SMI_LARB1_BASE (0x16010000)

// APB Module mmu
#define SMI_LARB1_MMU_BASE (0x16010800)

// APB Module vdtop
#define VDTOP_BASE (0x16020000)

// APB Module vld
#define VLD_BASE (0x16021000)

// APB Module vld_top
#define VLD_TOP_BASE (0x16021800)

// APB Module mc
#define MC_BASE (0x16022000)

// APB Module avc_vld
#define AVC_VLD_BASE (0x16023000)

// APB Module avc_mv
#define AVC_MV_BASE (0x16024000)

// APB Module vdec_pp
#define VDEC_PP_BASE (0x16025000)

// APB Module vp8_vld
#define VP8_VLD_BASE (0x16026800)

// APB Module vp6
#define VP6_BASE (0x16027000)

// APB Module vld2
#define VLD2_BASE (0x16027800)

// APB Module mc_vmmu
#define MC_VMMU_BASE (0x16028000)

// APB Module pp_vmmu
#define PP_VMMU_BASE (0x16029000)

// APB Module n3d_ctl
#define N3D_CTL_BASE (0x15000000)

// APB Module fdvt
#define FDVT_BASE (0x1500B000)

// APB Module audiosys
#define AUDIOSYS_BASE (0x11140000)


#define GIC_DIST_BASE (CA9_BASE + 0x1000)
#define GIC_CPU_BASE  (CA9_BASE + 0x2000)

//#define IOCFG_L_BASE (0x10016000)
//#define IOCFG_B_BASE (0x10015000)
//#define IOCFG_R_BASE (0x10017000)
//#define IOCFG_T_BASE (0x10014000)
#define RTC_BASE (0x8000)
#define COLOR0_BASE (0x1400C000)
#define CCORR_BASE  (0x1400D000)
#define DITHER_BASE (0x14010000)
#define OVL0_BASE (0x1400C000)




/* hardware version register */
#define VER_BASE 0x08000000
#define APHW_CODE           (VER_BASE)
#define APHW_SUBCODE        (VER_BASE + 0x04)
#define APHW_VER            (VER_BASE + 0x08)
#define APSW_VER            (VER_BASE + 0x0C)

////////////////////////////////////////


/* Other define */
#define NON_BOOTABLE                0
#define RAW_BOOT                    1
#define FAT_BOOT                    2

#define CONFIG_STACKSIZE	    (128*1024)	  /* regular stack */

// xuecheng, define this because we use zlib for boot logo compression
#define CONFIG_ZLIB 	1

/*MTK Memory layout configuration*/
#define MAX_NR_BANK    4

#define DRAM_PHY_ADDR   0x80000000

#define RIL_SIZE 0

#define CFG_RAMDISK_LOAD_ADDR           (DRAM_PHY_ADDR + 0x4000000)
#define CFG_BOOTIMG_LOAD_ADDR           (DRAM_PHY_ADDR + 0x8000)
#define CFG_BOOTARGS_ADDR               (DRAM_PHY_ADDR + 0x100)

#define CFG_FACTORY_NAME	"factory.img"
#define HAVE_LK_TEXT_MENU

#ifdef CONFIG_MTK_USB_UNIQUE_SERIAL
#define EFUSE_CTR_BASE		0x10206000	/* IO_PHYS + 0x01019000 */
//#define PDN_CTR			0xC0001020	/* IO_PHYS + 0x00001020 */
#define SERIAL_KEY_HI		(EFUSE_CTR_BASE + 0x0144)
#define SERIAL_KEY_LO		(EFUSE_CTR_BASE + 0x0140)
#endif

//ALPS00427972, implement the analog register formula
//Add here for eFuse, chip version checking -> analog register calibration
#define M_HW_RES3	                    0x10009170
//#define M_HW_RES3_PHY                   IO_PHYS+M_HW_RES3
#define RG_USB20_TERM_VREF_SEL_MASK     0xE000      //0b 1110,0000,0000,0000     15~13
#define RG_USB20_CLKREF_REF_MASK        0x1C00      //0b 0001,1100,0000,0000     12~10
#define RG_USB20_VRT_VREF_SEL_MASK      0x0380      //0b 0000,0011,1000,0000     9~7
//ALPS00427972, implement the analog register formula

#endif








