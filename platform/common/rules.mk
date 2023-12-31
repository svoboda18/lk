LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

##############################################################################
# Check build type. (Begin)
##############################################################################
# For backward compatibility, USER_BUILD is also defined on userdebug build.
##############################################################################
ifneq ($(filter user, $(TARGET_BUILD_VARIANT)),)
DEFINES += USER_BUILD USER_LOAD
else ifneq ($(filter userdebug, $(TARGET_BUILD_VARIANT)),)
DEFINES += USERDEBUG_BUILD USER_BUILD
else ifneq ($(filter eng, $(TARGET_BUILD_VARIANT)),)
DEFINES += ENG_BUILD
else
DEFINES += USER_BUILD   # If none of the keywords is found, define USER_BUILD.
endif
##############################################################################
# Check build type. (End)
##############################################################################

ifeq ($(PLATFORM_FASTBOOT_EMPTY_STORAGE), yes)
DEFINES += PLATFORM_FASTBOOT_EMPTY_STORAGE
endif

# for fastboot to update partition table (fastboot flash gpt PGPT)
ifneq ($(wildcard $(LOCAL_DIR)/../../../../../../../../keystone-tools),)
DEFINES += MTK_GPT_UPDATE_SUPPORT
endif

ifeq ($(MTK_RC_TO_VENDOR), yes)
DEFINES += MTK_RC_TO_VENDOR
endif

ifeq ($(strip $(MICROTRUST_TEE_LITE_SUPPORT)),yes)
  ifneq (,$(filter mt6570 mt6580,$(PLATFORM)))
    DEFINES += CFG_MICROTRUST_TEE_LITE_SUPPORT
    OBJS += $(LOCAL_DIR)/RoT/avb_RoT_teei.o
  endif
endif #MICROTRUST_TEE_LITE_SUPPORT

# RoT for ARMv8
ifneq ($(strip $(MTK_SECURITY_SW_SUPPORT)),no)
ifeq (,$(filter mt6570 mt6580,$(PLATFORM)))
ifeq ($(MTK_AVB20_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/RoT/avb_RoT.o
else #MTK_AVB20_SUPPORT
OBJS += $(LOCAL_DIR)/RoT/RoT.o
endif #MTK_AVB20_SUPPORT
endif
endif


ifeq ($(MTK_ATM_SUPPORT), yes)
DEFINES += MTK_ATM_SUPPORT
endif
OBJS += $(LOCAL_DIR)/atm.o

OBJS += $(LOCAL_DIR)/sec_wrapper.o
OBJS += $(LOCAL_DIR)/profiling.o
OBJS += $(LOCAL_DIR)/meta.o
OBJS += $(LOCAL_DIR)/recovery.o
OBJS += $(LOCAL_DIR)/fpga_boot_argument.o
OBJS += $(LOCAL_DIR)/error.o

ifeq ($(CFG_MTK_UART_COMMON),yes)
MODULES += $(LOCAL_DIR)/uart
endif
MODULES += $(LOCAL_DIR)/loader
MODULES += $(LOCAL_DIR)/storage
MODULES += $(LOCAL_DIR)/timer
MODULES += $(LOCAL_DIR)/partition
MODULES += $(LOCAL_DIR)/plinfo

ifeq ($(MTK_AB_OTA_UPDATER),yes)
#RECOVERY_AS_BOOT is always enabled with MTK_AB_OTA_UPDATER (BOARD_USES_RECOVERY_AS_BOOT)
DEFINES += MTK_AB_OTA_UPDATER
DEFINES += RECOVERY_AS_BOOT
ifeq ($(MTK_BOOTCTRL_VERSION),1.0)
MTK_BOOTCTRL_VERSION = 1.0
DEFINES += MTK_BOOTCTRL_VERSION
else
MTK_BOOTCTRL_VERSION = 2.0
DEFINES += MTK_BOOTCTRL_VERSION
endif
MODULES += $(LOCAL_DIR)/bootctrl
endif

ifeq ($(MTK_SSUSB), yes)
MODULES += $(LOCAL_DIR)/mt_ssusb
endif

ifeq ($(MTK_MUSB), yes)
MODULES += $(LOCAL_DIR)/mt_musb
endif

ifneq ($(SYSTEM_AS_ROOT),no)
DEFINES += SYSTEM_AS_ROOT
endif

ifeq ($(LK_LD_MD_SUPPORT), yes)
MODULES += $(LOCAL_DIR)/md
endif

ifeq ($(MTK_CHARGER_NEW_ARCH), yes)
MODULES += $(LOCAL_DIR)/power
endif

# aee platform debug
ifeq ($(MTK_AEE_PLATFORM_DEBUG_SUPPORT),yes)
MODULES += $(LOCAL_DIR)/aee_platform_debug
MODULES += $(LOCAL_DIR)/spm
endif

ifeq ($(MTK_AVB20_SUPPORT),yes)
MODULES += $(LOCAL_DIR)/avb
DEFINES += MTK_AVB20_SUPPORT
endif

MODULES += $(LOCAL_DIR)/atf
MODULES += $(LOCAL_DIR)/boot

ifeq ($(MTK_RECOVERY_RAMDISK_SPLIT),yes)
DEFINES += MTK_RECOVERY_RAMDISK_SPLIT
MODULES += lib/ramdisk_merge
OBJS += $(LOCAL_DIR)/ramdisk/load_ramdisk.o
OBJS += $(LOCAL_DIR)/ramdisk/load_vfy_ramdisk.o
# Must bind with ram split to avoid misuse ramdisk in boot
ifeq ($(RECOVERY_AS_BOOT),yes)
DEFINES += RECOVERY_AS_BOOT
endif
endif

ifeq (yes,$(strip $(MTK_BUILD_ENHANCE_MENU)))
DEFINES += MTK_BUILD_ENHANCE_MENU
endif

# log_store platform debug
ifeq ($(CFG_LOG_STORE_SUPPORT),yes)
MODULES += $(LOCAL_DIR)/log_store
DEFINES += LOG_STORE_SUPPORT
ifneq ($(wildcard $(LOCAL_DIR)/../../../../../../internal/mtklog_enable),)
DEFINES += UART_SWITCH_SUPPORT
endif
DEFINES += FASTBOOT_DUMP_LOG
endif

ifeq ($(DUMP_CODE_SECTION), yes)
DEFINES += DUMP_CODE_SECTION
endif

ifeq ($(LK_MAIN_DTB_BUILT_IN),yes)
MODULES += $(LOCAL_DIR)/lk_main_dtb_loader
DEFINES += LK_MAIN_DTB_BUILT_IN
endif
