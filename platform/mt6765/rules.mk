LOCAL_DIR := $(GET_LOCAL_DIR)

ARCH    := arm
ARM_CPU := cortex-a53
CPU     := generic

MMC_SLOT         := 1

PLATFORM_SECURITY_VERSION:=21
DEFINES += PLATFORM_SECURITY_VERSION=$(PLATFORM_SECURITY_VERSION)
MTK_AVB20_SUPPORT:=yes
AVB_SHA256_CRYPTO_HW_SUPPORT:=yes
AVB_PERSIST_VALUE_SUPPORT:=yes
SYSTEM_AS_ROOT = no

# choose one of following value -> 1: disabled/ 2: permissive /3: enforcing
SELINUX_STATUS := 3

LK_MAIN_DTB_BUILT_IN := yes

# set kernel decompress size limit (120)
KERNEL_DECOMPRESS_SIZE := 0x07800000
DEFINES += KERNEL_DECOMPRESS_SIZE=$(KERNEL_DECOMPRESS_SIZE)

# overwrite SELINUX_STATUS value with PRJ_SELINUX_STATUS, if defined. it's by project variable.
ifdef PRJ_SELINUX_STATUS
	SELINUX_STATUS := $(PRJ_SELINUX_STATUS)
endif

ifeq (yes,$(strip $(MTK_BUILD_ROOT)))
SELINUX_STATUS := 2
DEFINES += MTK_BUILD_ROOT
endif

USE_DTB_NO_DWS = yes
MTK_SMC_ID_MGMT = yes

DEVELOP_STAGE ?= SB
# it may be set in ${PROJECT}.mk
ifeq ($(DEVELOP_STAGE), FPGA)
# DEFINES += FPGA_SET_BOOT_ARGUMENT
DEFINES += MACH_FPGA=y
DEFINES += MACH_FPGA_NO_DISPLAY=y
#DEFINES += MSDC_ENABLE_DMA_MODE  # Turn this option OFF when DMA mode is not ready (especially in FPGA early porting).
DEFINES += NO_PMIC
DEFINES += NO_BOOT_MODE_SEL
DEFINES += NO_PLL_TURN_OFF
DEFINES += NO_BAT_INIT
DEFINES += NO_MD_POWER_DOWN
#DEFINES += ENABLE_IO_THREAD
DEFINES += NO_MD_LOAD
DEFINES += NO_DCM
DEFINES += NO_POWER_OFF
DEFINES += NO_WDT
endif
ifeq ($(DEVELOP_STAGE), SB)
DEFINES += MSDC_ENABLE_DMA_MODE  # Turn this option OFF when DMA mode is not ready (especially in FPGA early porting).
#DEFINES += NO_PMIC
#DEFINES += NO_BOOT_MODE_SEL
DEFINES += NO_PLL_TURN_OFF
#DEFINES += NO_BAT_INIT
#DEFINES += NO_MD_POWER_DOWN
#DEFINES += NO_WDT
#DEFINES += NO_DCM
#DEFINES += NO_WDT
#DEFINES += MACH_FPGA_NO_DISPLAY=y
DEFINES += ENABLE_IO_THREAD
endif
CFG_MTK_UART_COMMON := yes
DEFINES += CONFIG_UART_BAUDRATE=921600
DEFINES += CONFIG_UART_FPGA_CLK=12000000
DEFINES += CONFIG_UART_EVB_CLK=26000000
DEFINES += PLATFORM=\"$(PLATFORM)\"

DEFINES += SELINUX_STATUS=$(SELINUX_STATUS)

DEFINES += PERIPH_BLK_BLSP=1
DEFINES += WITH_CPU_EARLY_INIT=0 WITH_CPU_WARM_BOOT=0 \
	   MMC_SLOT=$(MMC_SLOT)

DEFINES += MTK_CAN_FROM_CLUSTER1=1

# provide PMIC full (cold) reset functionality
MTK_PMIC_FULL_RESET := yes
ifeq ($(MTK_PMIC_FULL_RESET), yes)
	DEFINES += MTK_PMIC_FULL_RESET
endif

MTK_3LEVEL_PAGETABLE := yes
ifeq ($(MTK_3LEVEL_PAGETABLE), yes)
	DEFINES += MTK_3LEVEL_PAGETABLE
endif

MBLOCK_LIB_SUPPORT := yes
ifeq ($(MBLOCK_LIB_SUPPORT), yes)
	DEFINES += MBLOCK_LIB_SUPPORT=2
	MBLOCK_LIB_SUPPORT := 2
	MODULES += lib/mblock
	INCLUDES += -I$(LOCAL_DIR)/../../lib/mblock
endif

PLAT_DBG_INFO_LIB_SUPPORT := yes
ifeq ($(PLAT_DBG_INFO_LIB_SUPPORT), yes)
	DEFINES += PLAT_DBG_INFO_LIB_SUPPORT=1
	PLAT_DBG_INFO_LIB_SUPPORT := 1
	MODULES += lib/plat_dbg_info
endif

ifeq ($(MTK_DUAL_DISPLAY_SUPPORT), 2)
CFLAGS += -DMTK_DUAL_DISPLAY_SUPPORT=2
OBJS += $(LOCAL_DIR)/external_display.o
endif

# Android Test Mode Feature
MTK_ATM_SUPPORT := yes

ifneq ($(MTK_PRODUCT_LINE_PLATFORM),)
	DEFINES += MTK_PRODUCT_LINE_PLATFORM=\"$(MTK_PRODUCT_LINE_PLATFORM)\"
endif

ifneq ($(MTK_PLATFORM_REVISED),)
	DEFINES += MTK_PLATFORM_REVISED=\"$(MTK_PLATFORM_REVISED)\"
endif

MTK_SEC_SOCID_SUPPORT := yes

ifeq ($(MTK_SECURITY_SW_SUPPORT), yes)
	DEFINES += MTK_SECURITY_SW_SUPPORT
ifeq ($(MTK_SEC_SOCID_SUPPORT), yes)
	DEFINES += MTK_SEC_SOCID_SUPPORT
endif
endif

ifeq ($(AVB_PERSIST_VALUE_SUPPORT), yes)
	DEFINES += AVB_PERSIST_VALUE_SUPPORT
endif

MTK_OTP_FRAMEWORK_V2 := no

ifeq ($(MTK_SECURITY_ANTI_ROLLBACK), yes)
	DEFINES += MTK_SECURITY_ANTI_ROLLBACK

ifneq ($(MTK_VER_SIMPLE_TEST),)
	DEFINES += MTK_VER_SIMPLE_TEST=$(MTK_VER_SIMPLE_TEST)
endif

ifeq ($(MTK_OTP_FRAMEWORK_V2), yes)
	DEFINES += MTK_OTP_FRAMEWORK_V2
endif
endif

MD_RMA_SUPPORT := yes
ifeq ($(MD_RMA_SUPPORT), yes)
	DEFINES += MD_RMA_SUPPORT
endif

MTK_SECURITY_YELLOW_STATE_SUPPORT := no
ifeq ($(MTK_SECURITY_YELLOW_STATE_SUPPORT), yes)
	DEFINES += MTK_SECURITY_YELLOW_STATE_SUPPORT
endif

ifeq ($(MTK_GOOGLE_TRUSTY_SUPPORT), yes)
DEFINES += MTK_LM_2LEVEL_PAGETABLE_MODE
endif

# choose one of following value -> 0: disabled/1: enable

MTK_POWER_ON_WRITE_PROTECT := 1
ifdef PRJ_MTK_POWER_ON_WRITE_PROTECT
	MTK_POWER_ON_WRITE_PROTECT := $(PRJ_MTK_POWER_ON_WRITE_PROTECT)
endif

ifeq ($(MTK_POWER_ON_WRITE_PROTECT), 1)
DEFINES += MTK_POWER_ON_WRITE_PROTECT=$(MTK_POWER_ON_WRITE_PROTECT)
ifeq ($(MTK_SIM_LOCK_POWER_ON_WRITE_PROTECT), yes)
	DEFINES += MTK_SIM_LOCK_POWER_ON_WRITE_PROTECT
endif
endif

MTK_PERSIST_PARTITION_SUPPORT := 0
ifdef PRJ_MTK_PERSIST_PARTITION_SUPPORT
	MTK_PERSIST_PARTITION_SUPPORT := $(PRJ_MTK_PERSIST_PARTITION_SUPPORT)
endif
ifeq ($(MTK_PERSIST_PARTITION_SUPPORT), 1)
DEFINES += MTK_PERSIST_PARTITION_SUPPORT=$(MTK_PERSIST_PARTITION_SUPPORT)
endif

ifeq ($(MTK_SEC_FASTBOOT_UNLOCK_SUPPORT), yes)
	DEFINES += MTK_SEC_FASTBOOT_UNLOCK_SUPPORT
ifeq ($(MTK_SEC_FASTBOOT_UNLOCK_KEY_SUPPORT), yes)
	DEFINES += MTK_SEC_FASTBOOT_UNLOCK_KEY_SUPPORT
endif
endif

# used for DA tool to enter fastboot via setting RGU bit
MTK_ENTER_FASTBOOT_VIA_RGU := yes
ifeq ($(MTK_ENTER_FASTBOOT_VIA_RGU), yes)
	DEFINES += MTK_ENTER_FASTBOOT_VIA_RGU
endif

ifeq ($(MTK_KERNEL_POWER_OFF_CHARGING),yes)
#Fastboot support off-mode-charge 0/1
#1: charging mode, 0:skip charging mode
DEFINES += MTK_OFF_MODE_CHARGE_SUPPORT
endif

MTK_PMIC_POWER_OFF := yes
ifeq ($(MTK_PMIC_POWER_OFF), yes)
	DEFINES += MTK_PMIC_POWER_OFF
endif

DEFINES += MTK_SMC_K32_SUPPORT

KEDUMP_MINI := yes

ARCH_HAVE_MT_RAMDUMP := yes

# Use it Carefully! Make sure that you know what you are doing!
# This config will force MRDUMP enabled.
ifeq ($(MTK_MRDUMP_ENABLE),)
#MTK_MRDUMP_ENABLE := yes
endif

# Use SRAM to preserve control block
ifneq ($(wildcard $(LOCAL_DIR)/include/platform/mtk_mrdump.h),)
	DEFINES += MTK_MRDUMP_SRAM_CB
endif

DEFINES += $(shell echo $(BOOT_LOGO) | tr a-z A-Z)

MTK_POWER_ON_WP := yes
ifeq ($(MTK_EMMC_SUPPORT),yes)
ifeq ($(MTK_POWER_ON_WP),yes)
        DEFINES += MTK_POWER_ON_WP
endif
ifeq ($(MTK_EMMC_SUPPORT_OTP),yes)
        DEFINES += MTK_EMMC_SUPPORT_OTP
endif
endif
ifeq ($(MTK_UFS_SUPPORT),yes)
ifeq ($(MTK_POWER_ON_WP),yes)
        DEFINES += MTK_POWER_ON_WP
endif
endif

MTK_PARTITION_COMMON := yes
ifeq ($(MTK_PARTITION_COMMON), yes)
DEFINES += MTK_PARTITION_COMMON
endif

MTK_MUSB := yes
ifeq ($(MTK_MUSB), yes)
INCLUDES += -I$(LK_TOP_DIR)/platform/common/mt_musb
OBJS += \
	$(LOCAL_DIR)/mt_musb/mt_musbphy.o
endif

$(info libshowlogo new path ------- $(LOCAL_DIR)/../../lib/libshowlogo)
INCLUDES += -I$(LOCAL_DIR)/include \
            -I$(LOCAL_DIR)/include/platform \
            -I$(LOCAL_DIR)/../../lib/libshowlogo \
            -I$(LK_TOP_DIR)/app/mt_boot/ \
            -I$(LK_TOP_DIR)/platform/common/storage/mmc/inc \
            -Icustom/$(FULL_PROJECT)/lk/include/target \
            -Icustom/$(FULL_PROJECT)/lk/lcm/inc \
            -Icustom/$(FULL_PROJECT)/lk/inc \
            -Icustom/$(FULL_PROJECT)/common \
            -Icustom/$(FULL_PROJECT)/kernel/dct/ \
            -I$(BUILDDIR)/include/dfo \
            -I$(LOCAL_DIR)/../../dev/lcm/inc

INCLUDES += -I$(DRVGEN_OUT)/inc

OBJS += \
	$(LOCAL_DIR)/bitops.o \
	$(LOCAL_DIR)/mt_gpio.o \
	$(LOCAL_DIR)/mt_disp_drv.o \
	$(LOCAL_DIR)/mt_gpio_init.o \
	$(LOCAL_DIR)/mt_i2c.o \
	$(LOCAL_DIR)/mt_latch.o \
	$(LOCAL_DIR)/platform.o \
	$(LOCAL_DIR)/interrupts.o \
	$(LOCAL_DIR)/timer.o \
	$(LOCAL_DIR)/debug.o \
	$(LOCAL_DIR)/mt_debug_dump.o \
	$(LOCAL_DIR)/boot_mode.o \
	$(LOCAL_DIR)/load_image.o \
	$(LOCAL_DIR)/atags.o \
	$(LOCAL_DIR)/partition_setting.o \
	$(LOCAL_DIR)/mt_get_dl_info.o \
	$(LOCAL_DIR)/addr_trans.o \
	$(LOCAL_DIR)/factory.o \
	$(LOCAL_DIR)/mt_gpt.o\
	$(LOCAL_DIR)/mtk_key.o \
	$(LOCAL_DIR)/mt_logo.o\
	$(LOCAL_DIR)/boot_mode_menu.o\
	$(LOCAL_DIR)/mt_pmic_wrap_init.o\
	$(LOCAL_DIR)/msdc_io.o\
	$(LOCAL_DIR)/cust_msdc.o\
	$(LOCAL_DIR)/upmu_common.o\
	$(LOCAL_DIR)/mt_pmic_dlpt.o\
	$(LOCAL_DIR)/mt_pmic.o\
	$(LOCAL_DIR)/mtk_wdt.o\
	$(LOCAL_DIR)/mt_rtc.o\
	$(LOCAL_DIR)/ddp_manager.o\
	$(LOCAL_DIR)/ddp_path.o\
	$(LOCAL_DIR)/ddp_ovl.o\
	$(LOCAL_DIR)/ddp_rdma.o\
	$(LOCAL_DIR)/ddp_misc.o\
	$(LOCAL_DIR)/ddp_info.o\
	$(LOCAL_DIR)/ddp_dither.o\
	$(LOCAL_DIR)/ddp_dump.o\
	$(LOCAL_DIR)/ddp_dsi.o\
	$(LOCAL_DIR)/primary_display.o\
	$(LOCAL_DIR)/disp_lcm.o\
	$(LOCAL_DIR)/ddp_pwm.o\
	$(LOCAL_DIR)/pwm.o \
	$(LOCAL_DIR)/sec_efuse.o\
	$(LOCAL_DIR)/sec_policy.o\
	$(LOCAL_DIR)/mtk_auxadc.o\
	$(LOCAL_DIR)/mt_efuse.o\
	$(LOCAL_DIR)/aee_platform_debug.o\
	$(LOCAL_DIR)/mt_dramc_memtest.o\
	$(LOCAL_DIR)/../common/emi/emi_mpu_v1.o\
	$(LOCAL_DIR)/../common/emi/emi_info_v1.o\
	$(LOCAL_DIR)/pll.o \
	$(LOCAL_DIR)/spm_md_mtcmos.o \
	$(LOCAL_DIR)/md1_off.o \
	$(LOCAL_DIR)/mtk_dcm.o \
	$(LOCAL_DIR)/mtk_dcm_autogen.o \
	$(LOCAL_DIR)/mtk_mcdi.o \
	$(LOCAL_DIR)/crypto_hw.o \
	$(LOCAL_DIR)/oaep.o \
	$(LOCAL_DIR)/rsa_oaep.o \
	$(LOCAL_DIR)/anti_rollback_cust.o

ifeq ($(MTK_AB_OTA_UPDATER),yes)
OBJS += $(LOCAL_DIR)/write_protect_ab.o
else
OBJS += $(LOCAL_DIR)/write_protect.o
endif

ifeq ($(MTK_SMI_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/mtk_smi.o
DEFINES += MTK_SMI_SUPPORT
endif

ifeq ($(MTK_UFS_SUPPORT),yes)
OBJS += \
	$(LOCAL_DIR)/ufs_aio_platform.o
endif

ifeq ($(MTK_TINYSYS_SCP_SUPPORT), yes)
ifeq ($(MTK_MINIMUM_SCP_DRAM_SIZE), yes)
DEFINES += MTK_MINIMUM_SCP_DRAM_SIZE
endif
DEFINES += MTK_TINYSYS_SCP_SUPPORT
OBJS += $(LOCAL_DIR)/mt_scp.o
OBJS += $(LOCAL_DIR)/mt_scp_l1c.o
OBJS += $(LOCAL_DIR)/mt_scp_excep.o
endif

ifeq ($(MTK_TINYSYS_SSPM_SUPPORT), yes)
    OBJS += $(LOCAL_DIR)/mt_sspm.o
    DEFINES += MTK_TINYSYS_SSPM_SUPPORT
endif

ifeq ($(SPM_FW_USE_PARTITION), yes)
DEFINES += SPM_FW_USE_PARTITION
endif

ifeq ($(MTK_SECURITY_SW_SUPPORT), yes)
OBJS +=	$(LOCAL_DIR)/img_auth_stor.o
endif

ifneq ($(MACH_FPGA_LED_SUPPORT), yes)
OBJS += $(LOCAL_DIR)/mt_leds.o
else
DEFINES += MACH_FPGA_LED_SUPPORT
endif


ifneq ($(MTK_EMMC_SUPPORT),yes)
#	OBJS +=$(LOCAL_DIR)/mtk_nand.o
#	OBJS +=$(LOCAL_DIR)/bmt.o
endif

ifeq ($(MTK_USB2JTAG_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/mt_usb2jtag.o
DEFINES += MTK_USB2JTAG_SUPPORT
endif

ifeq ($(MTK_MT8193_SUPPORT),yes)
#OBJS +=$(LOCAL_DIR)/mt8193_init.o
#OBJS +=$(LOCAL_DIR)/mt8193_ckgen.o
#OBJS +=$(LOCAL_DIR)/mt8193_i2c.o
endif

ifeq ($(MTK_KERNEL_POWER_OFF_CHARGING),yes)
OBJS +=$(LOCAL_DIR)/mt_kernel_power_off_charging.o
DEFINES += MTK_KERNEL_POWER_OFF_CHARGING
endif

ifeq ($(MTK_PUMP_EXPRESS_PLUS_SUPPORT),yes)
DEFINES += MTK_PUMP_EXPRESS_PLUS_SUPPORT
endif

ifneq ($(MTK_CHARGER_NEW_ARCH), yes)

ifeq ($(MTK_MT6370_PMU_BLED_SUPPORT),yes)
	OBJS += $(LOCAL_DIR)/mt6370_pmu_bled.o
	DEFINES += MTK_MT6370_PMU_BLED_SUPPORT
endif

	OBJS += $(LOCAL_DIR)/mt_battery.o

ifeq ($(MTK_BQ24261_SUPPORT),yes)
OBJS +=$(LOCAL_DIR)/bq24261.o
else
  ifeq ($(MTK_BQ24196_SUPPORT),yes)
    OBJS +=$(LOCAL_DIR)/bq24196.o
  else
    ifeq ($(MTK_BQ25896_SUPPORT),yes)
      OBJS +=$(LOCAL_DIR)/bq25890.o
      DEFINES += MTK_BQ25896_SUPPORT
      DEFINES += SWCHR_POWER_PATH
    endif
  endif
endif

ifeq ($(MTK_RT9466_SUPPORT),yes)
	OBJS += $(LOCAL_DIR)/rt9466.o
	DEFINES += MTK_RT9466_SUPPORT
	DEFINES += SWCHR_POWER_PATH
endif

ifeq ($(MTK_RT9468_SUPPORT),yes)
	OBJS += $(LOCAL_DIR)/rt9468.o
	DEFINES += MTK_RT9468_SUPPORT
	DEFINES += SWCHR_POWER_PATH
endif

ifeq ($(MTK_MT6370_PMU_CHARGER_SUPPORT),yes)
	OBJS += $(LOCAL_DIR)/mt6370_pmu_charger.o
	DEFINES += MTK_MT6370_PMU_CHARGER_SUPPORT
	DEFINES += SWCHR_POWER_PATH
endif

ifeq ($(MTK_CHARGER_INTERFACE),yes)
	OBJS += $(LOCAL_DIR)/mtk_charger_intf.o
	DEFINES += MTK_CHARGER_INTERFACE
endif

ifeq ($(MTK_NCP1854_SUPPORT),yes)
OBJS +=$(LOCAL_DIR)/ncp1854.o
endif

endif

#DUMMY_AP :=yes
ifeq ($(DUMMY_AP),yes)
OBJS +=$(LOCAL_DIR)/dummy_ap.o
DEFINES += DUMMY_AP_MODE
endif

LK_LD_MD_SUPPORT := yes
ifeq ($(LK_LD_MD_SUPPORT), yes)
	INCLUDES += -I$(LOCAL_DIR)/../common/md
	OBJS +=$(LOCAL_DIR)/ccci_lk_load_img_plat.o
	#DEFINES += LK_OPT_TO_KERNEL_CCCI
	DEFINES += LK_LD_MD_SUPPORT
	DEFINES += ENABLE_PARSING_LK_ENV
ifneq (,$(strip $(MTK_PROTOCOL1_RAT_CONFIG)))
	DEFINES += MTK_PROTOCOL1_RAT_CONFIG="\"$(strip $(MTK_PROTOCOL1_RAT_CONFIG))\""
endif
endif

ifeq ($(MTK_EFUSE_WRITER_SUPPORT), yes)
    DEFINES += MTK_EFUSE_WRITER_SUPPORT
endif

ifdef MTK_MT22_MODE
    DEFINES += MTK_MT22_MODE="\"$(MTK_MT22_MODE)\""
endif

ifdef MTK_HE_MODE
    DEFINES += MTK_HE_MODE="\"$(MTK_HE_MODE)\""
endif

ifeq ($(TRUSTONIC_TEE_SUPPORT),yes)
DEFINES += TRUSTONIC_TEE_SUPPORT
endif

ifeq ($(MTK_GOOGLE_TRUSTY_SUPPORT),yes)
DEFINES += MTK_GOOGLE_TRUSTY_SUPPORT
endif

ifeq ($(MTK_SECURITY_SW_SUPPORT), yes)
ifeq ($(CUSTOM_SEC_AUTH_SUPPORT), yes)
LIBSEC := -L$(LOCAL_DIR)/lib --start-group -lsec
else
LIBSEC := -L$(LOCAL_DIR)/lib --start-group -lsec -lcrypto
endif
LIBSEC_PLAT := -lsecplat -ldevinfo --end-group
else
LIBSEC := -L$(LOCAL_DIR)/lib
LIBSEC_PLAT := -lsecplat -ldevinfo
endif

MTK_GIC_VERSION := v3

ifeq ($(MTK_NO_BIGCORES),yes)
	DEFINES += MTK_NO_BIGCORES
endif

ifeq ($(MTK_USERIMAGES_USE_F2FS), yes)
DEFINES += MTK_USERIMAGES_USE_F2FS
endif

LINKER_SCRIPT += $(BUILDDIR)/system-onesegment.ld

MTK_AEE_PLATFORM_DEBUG_SUPPORT := yes
DEFINES += MTK_AEE_PLATFORM_DEBUG_SUPPORT

ifeq ($(MTK_DM_VERITY_OFF),yes)
DEFINES += MTK_DM_VERITY_OFF
endif

OBJS += $(LOCAL_DIR)/dm_verity_status.o

ifeq ($(MTK_ENABLE_GENIEZONE),yes)
DEFINES += WITH_GZ_RELOAD_MBLOCK_INFO=1
endif

MTK_RC_TO_VENDOR ?= yes

-include $(LOCAL_DIR)/../../../../../../internal/bootloader/lk/rsc/rules.mk
OBJS += $(LOCAL_DIR)/custom_dtb_index.o

ifneq ($(MTK_DYNAMIC_CCB_BUFFER_GEAR_ID),)
DEFINES += MTK_DYNAMIC_CCB_BUFFER_GEAR_ID=$(MTK_DYNAMIC_CCB_BUFFER_GEAR_ID)
endif

ifeq ($(AVB_SHA256_CRYPTO_HW_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/avb_crypto_hw.o
endif

CFG_LOG_STORE_SUPPORT := yes
