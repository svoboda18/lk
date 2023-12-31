LOCAL_DIR := $(GET_LOCAL_DIR)

ARCH    := arm
ARM_CPU := cortex-a7
CPU     := generic

MMC_SLOT         := 1

PLATFORM_SECURITY_VERSION:=11
DEFINES += PLATFORM_SECURITY_VERSION=$(PLATFORM_SECURITY_VERSION)
MTK_AVB20_SUPPORT:=yes
AVB_SHA256_CRYPTO_HW_SUPPORT:=no
SYSTEM_AS_ROOT = no

# mtk gpt version
GPT_VER := 1
DEFINES += GPT_VER=$(GPT_VER)

# choose one of following value ->  2: permissive /3: enforcing
SELINUX_STATUS := 3

KERNEL_DECOMPRESS_SIZE := 0x1C00000
DEFINES += KERNEL_DECOMPRESS_SIZE=$(KERNEL_DECOMPRESS_SIZE)

# overwrite SELINUX_STATUS value with PRJ_SELINUX_STATUS, if defined. it's by project variable.
ifdef PRJ_SELINUX_STATUS
	SELINUX_STATUS := $(PRJ_SELINUX_STATUS)
endif

DEFINES += MTK_DTBO_FEATURE

ifeq (yes,$(strip $(MTK_BUILD_ROOT)))
SELINUX_STATUS := 2
DEFINES += MTK_BUILD_ROOT
endif

DEFINES += PLATFORM=\"$(PLATFORM)\"

DEFINES += SELINUX_STATUS=$(SELINUX_STATUS)

DEFINES += PERIPH_BLK_BLSP=1
DEFINES += WITH_CPU_EARLY_INIT=0 WITH_CPU_WARM_BOOT=0 \
	   MMC_SLOT=$(MMC_SLOT)

CFG_DTB_EARLY_LOADER_SUPPORT := yes
ifeq ($(CFG_DTB_EARLY_LOADER_SUPPORT), yes)
	DEFINES += CFG_DTB_EARLY_LOADER_SUPPORT=1
endif

ifeq ($(MTK_SECURITY_SW_SUPPORT), yes)
	DEFINES += MTK_SECURITY_SW_SUPPORT
endif

ifneq ($(wildcard ../../../../../../vendor/mediatek/internal/testmode_enable),)
ifeq ($(MTK_EFUSE_DOWNGRADE), yes)
	DEFINES += MTK_EFUSE_DOWNGRADE
endif
endif

ifeq ($(MTK_SEC_FASTBOOT_UNLOCK_SUPPORT), yes)
	DEFINES += MTK_SEC_FASTBOOT_UNLOCK_SUPPORT
ifeq ($(MTK_SEC_FASTBOOT_UNLOCK_KEY_SUPPORT), yes)
	DEFINES += MTK_SEC_FASTBOOT_UNLOCK_KEY_SUPPORT
endif
endif

ifeq ($(CFG_MEMORY_RESERVED_SMALL_GRANULARITY),yes)
	DEFINES += CFG_MEMORY_RESERVED_SMALL_GRANULARITY=1
endif

ifeq ($(MTK_KERNEL_POWER_OFF_CHARGING),yes)
#Fastboot support off-mode-charge 0/1
#1: charging mode, 0:skip charging mode
DEFINES += MTK_OFF_MODE_CHARGE_SUPPORT
endif

KEDUMP_MINI := yes

ARCH_HAVE_MT_RAMDUMP := no

DEFINES += $(shell echo $(BOOT_LOGO) | tr a-z A-Z)

MTK_EMMC_POWER_ON_WP := no
ifeq ($(MTK_EMMC_SUPPORT),yes)
ifeq ($(MTK_EMMC_POWER_ON_WP),yes)
	DEFINES += MTK_EMMC_POWER_ON_WP
endif
endif

ifdef MTK_CARRIEREXPRESS_PACK
ifneq ($(strip $(MTK_CARRIEREXPRESS_PACK)), no)
    DEFINES += MTK_CARRIEREXPRESS_PACK
ifeq ($(filter OP01, $(subst _, $(space), $(MTK_REGIONAL_OP_PACK))), OP01)
    DEFINES += MTK_CARRIEREXPRESS_PACK_OP01
endif

ifeq ($(filter OP02, $(subst _, $(space), $(MTK_REGIONAL_OP_PACK))), OP02)
    DEFINES += MTK_CARRIEREXPRESS_PACK_OP02
endif

ifeq ($(filter OP09, $(subst _, $(space), $(MTK_REGIONAL_OP_PACK))), OP09)
    DEFINES += MTK_CARRIEREXPRESS_PACK_OP09
endif

ifneq ($(filter NONE, $(subst _, $(space), $(OPTR_SPEC_SEG_DEF))), NONE)
ifeq ($(filter OP01, $(subst _, $(space), $(OPTR_SPEC_SEG_DEF))), OP01)
    GLOBAL_DEVICE_DEFAULT_OPTR := 1
    DEFINES += GLOBAL_DEVICE_DEFAULT_OPTR=$(GLOBAL_DEVICE_DEFAULT_OPTR)
endif

ifeq ($(filter OP02, $(subst _, $(space), $(OPTR_SPEC_SEG_DEF))), OP02)
    GLOBAL_DEVICE_DEFAULT_OPTR := 2
    DEFINES += GLOBAL_DEVICE_DEFAULT_OPTR=$(GLOBAL_DEVICE_DEFAULT_OPTR)
endif

ifeq ($(filter OP09, $(subst _, $(space), $(OPTR_SPEC_SEG_DEF))), OP09)
    GLOBAL_DEVICE_DEFAULT_OPTR := 9
    DEFINES += GLOBAL_DEVICE_DEFAULT_OPTR=$(GLOBAL_DEVICE_DEFAULT_OPTR)
endif
endif

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
	$(LOCAL_DIR)/platform.o \
	$(LOCAL_DIR)/uart.o \
	$(LOCAL_DIR)/interrupts.o \
	$(LOCAL_DIR)/timer.o \
	$(LOCAL_DIR)/debug.o \
	$(LOCAL_DIR)/boot_mode.o \
	$(LOCAL_DIR)/load_image.o \
	$(LOCAL_DIR)/atags.o \
	$(LOCAL_DIR)/partition_setting.o \
	$(LOCAL_DIR)/mt_get_dl_info.o \
	$(LOCAL_DIR)/addr_trans.o \
	$(LOCAL_DIR)/factory.o \
	$(LOCAL_DIR)/mtk_key.o \
	$(LOCAL_DIR)/mt_logo.o\
	$(LOCAL_DIR)/boot_mode_menu.o\
	$(LOCAL_DIR)/mt_pmic_wrap_init.o\
	$(LOCAL_DIR)/mmc_common_inter.o \
	$(LOCAL_DIR)/mmc_core.o\
	$(LOCAL_DIR)/mmc_test.o\
	$(LOCAL_DIR)/msdc.o\
	$(LOCAL_DIR)/msdc_dma.o\
	$(LOCAL_DIR)/msdc_utils.o\
	$(LOCAL_DIR)/msdc_irq.o\
	$(LOCAL_DIR)/upmu_common.o\
	$(LOCAL_DIR)/mt_pmic.o\
	$(LOCAL_DIR)/mt6311.o\
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
	$(LOCAL_DIR)/mtk_auxadc.o\
	$(LOCAL_DIR)/mt_dummy_read.o\
	$(LOCAL_DIR)/mt_efuse.o

ifeq ($(MTK_SECURITY_SW_SUPPORT),yes)
	OBJS += $(LOCAL_DIR)/img_auth_stor.o
endif
ifneq ($(MACH_FPGA_LED_SUPPORT), yes)
	OBJS += $(LOCAL_DIR)/mt_leds.o
endif
# SETTING of USBPHY type
#OBJS += $(LOCAL_DIR)/mt_usbphy_d60802.o
#OBJS += $(LOCAL_DIR)/mt_usbphy_e60802.o

OBJS += $(LOCAL_DIR)/mt_battery.o

ifneq ($(MTK_EMMC_SUPPORT),yes)
#	OBJS +=$(LOCAL_DIR)/mtk_nand.o
#	OBJS +=$(LOCAL_DIR)/bmt.o
endif

ifeq ($(MTK_USB2JTAG_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/mt_usb2jtag.o
DEFINES += MTK_USB2JTAG_SUPPORT
endif

ifeq ($(MTK_MT8193_SUPPORT),yes)
OBJS +=$(LOCAL_DIR)/mt8193_init.o
OBJS +=$(LOCAL_DIR)/mt8193_ckgen.o
OBJS +=$(LOCAL_DIR)/mt8193_i2c.o
endif

ifeq ($(MTK_KERNEL_POWER_OFF_CHARGING),yes)
OBJS +=$(LOCAL_DIR)/mt_kernel_power_off_charging.o
DEFINES += MTK_KERNEL_POWER_OFF_CHARGING
endif

ifeq ($(MTK_PUMP_EXPRESS_SUPPORT),yes)
DEFINES += MTK_PUMP_EXPRESS_SUPPORT
endif

ifeq ($(MTK_BQ24261_SUPPORT),yes)
OBJS +=$(LOCAL_DIR)/bq24261.o
else
    ifeq ($(MTK_BQ24296_SUPPORT),yes)
        OBJS +=$(LOCAL_DIR)/bq24296.o
    else
        ifeq ($(MTK_NCP1854_SUPPORT),yes)
            OBJS +=$(LOCAL_DIR)/ncp1854.o
        endif
    endif
endif

ifeq ($(DUMMY_AP),yes)
OBJS +=$(LOCAL_DIR)/dummy_ap.o
#OBJS +=$(LOCAL_DIR)/spm_md_mtcmos.o
endif

ifeq ($(MTK_EFUSE_WRITER_SUPPORT), yes)
    DEFINES += MTK_EFUSE_WRITER_SUPPORT
endif

ifeq ($(MTK_GOOGLE_TRUSTY_SUPPORT),yes)
DEFINES += MTK_GOOGLE_TRUSTY_SUPPORT
endif

MTK_LOADER_BACKUP ?= yes
ifeq ($(MTK_LOADER_BACKUP),yes)
DEFINES += MTK_LOADER_BACKUP
endif

ifeq ($(MTK_USERIMAGES_USE_F2FS), yes)
DEFINES += MTK_USERIMAGES_USE_F2FS
endif

ifeq ($(MTK_DM_VERITY_OFF),yes)
DEFINES += MTK_DM_VERITY_OFF
endif

OBJS += $(LOCAL_DIR)/dm_verity_status.o

MTK_RC_TO_VENDOR ?= yes

ifeq ($(CUSTOM_SEC_AUTH_SUPPORT), yes)
LIBSEC := -L$(LOCAL_DIR)/lib -lsec
else
LIBSEC := -L$(LOCAL_DIR)/lib -lsec -lcrypto
endif
LIBSEC_PLAT := -lsecplat -ldevinfo

MBLOCK_LIB_SUPPORT := yes
ifeq ($(MBLOCK_LIB_SUPPORT), yes)
    DEFINES += MBLOCK_LIB_SUPPORT=2
    MBLOCK_LIB_SUPPORT := 2
    MODULES += lib/mblock
    INCLUDES += -I$(LOCAL_DIR)/../../lib/mblock
endif

LINKER_SCRIPT += $(BUILDDIR)/system-onesegment.ld
