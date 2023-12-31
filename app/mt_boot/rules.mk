LOCAL_DIR := $(GET_LOCAL_DIR)

MT_BOOT_OBJ_DIR := $(BOOTLOADER_OUT)/build-$(PROJECT)/app/mt_boot

ifeq ($(CUSTOM_SEC_CRYPTO_SUPPORT), yes)
	OBJS += \
		$(TO_ROOT)../../../mediatek/custom/common/security/fastboot/cust_auth.o
endif

ifeq ($(strip $(MTK_EMMC_SUPPORT)),yes)
	FASTBOOT_PARALLEL_DOWNLOAD :=yes
endif

OBJS += \
	$(LOCAL_DIR)/mt_boot.o \
	$(LOCAL_DIR)/odm_mdtbo.o \
	$(LOCAL_DIR)/decompressor.o\
	$(LOCAL_DIR)/fastboot.o \
	$(LOCAL_DIR)/iothread.o \
	$(LOCAL_DIR)/sec_hrid.o \
	$(LOCAL_DIR)/sec_socid.o \
	$(LOCAL_DIR)/sys_commands.o \
	$(LOCAL_DIR)/aee/mrdump_dummy.o \
	$(LOCAL_DIR)/blockheader.o \
	$(LOCAL_DIR)/bootargs.o \
	$(LOCAL_DIR)/fdt_op.o

ifeq ($(FASTBOOT_PARALLEL_DOWNLOAD),yes)
OBJS += \
	$(LOCAL_DIR)/mtransfer/bulk_process.o \
	$(LOCAL_DIR)/mtransfer/sparse_state_machine.o \
	$(LOCAL_DIR)/mtransfer/transfer_parallel.o
DEFINES += MTK_ULTRA_FLASH
INCLUDES += -I$(LOCAL_DIR)/mtransfer
ifeq ($(MTK_TLC_NAND_SUPPORT),yes)
OBJS += \
	$(LOCAL_DIR)/mtransfer/bulk_process_nand.o \
	$(LOCAL_DIR)/mtransfer/sparse_state_machine_nand.o
endif
endif

# DCONFIG
ifeq ($(ARCH_HAVE_DCONFIG),yes)
DEFINES += MTK_DCONFIG_SUPPORT
endif

# MRDUMP setting sanity check
ifneq ($(ARCH_HAVE_MT_RAMDUMP),yes)
ifneq ($(ARCH_HAVE_MT_RAMDUMP),no)
ifneq ($(ARCH_HAVE_MT_RAMDUMP),)
$(error Unknown ARCH_HAVE_MT_RAMDUMP setting.)
endif
endif
endif

ifneq ($(MTK_MRDUMP_ENABLE),dconfig)
ifneq ($(MTK_MRDUMP_ENABLE),yes)
ifneq ($(MTK_MRDUMP_ENABLE),no)
ifneq ($(MTK_MRDUMP_ENABLE),)
$(error Unknown MTK_MRDUMP_ENABLE setting.)
endif
endif
endif
endif

# MRDUMP setting check
build_mt_ramdump := no

# user(default disable MRDUMP)
ifeq ($(TARGET_BUILD_VARIANT),user)
ifeq ($(MTK_MRDUMP_ENABLE),yes)
build_mt_ramdump := yes
endif
ifeq ($(MTK_MRDUMP_ENABLE),dconfig)
build_mt_ramdump := dconfig
endif
endif

# eng(default enable MRDUMP)
ifeq ($(TARGET_BUILD_VARIANT),eng)
build_mt_ramdump := yes
ifeq ($(MTK_MRDUMP_ENABLE),no)
build_mt_ramdump := no
endif
endif

# userdebug(default enable MRDUMP)
ifeq ($(TARGET_BUILD_VARIANT),userdebug)
build_mt_ramdump := yes
ifeq ($(MTK_MRDUMP_ENABLE),no)
build_mt_ramdump := no
endif
endif

ifneq ($(build_mt_ramdump),no)
# MRDUMP depend on AEE/MINI
ifneq ($(KEDUMP_MINI),yes)
$(info Disable mrdump support - AEE/mini disabled)
build_mt_ramdump := no
endif
# MRDUMP show build warning if ARCH_HAVE_MT_RAMDUMP = no, and MTK_MRDUMP_ENABLE = yes
ifeq ($(ARCH_HAVE_MT_RAMDUMP),no)
$(info Disable mrdump support - architecture no support)
build_mt_ramdump := no
endif
# MRDUMP doesn't support MLC NAND
ifeq ($(MTK_MLC_NAND_SUPPORT),yes)
$(info Disable mrdump support - mlc nand)
build_mt_ramdump := no
endif
endif

ifneq ($(build_mt_ramdump),no)

ifeq ($(build_mt_ramdump),dconfig)
DEFINES += MTK_MRDUMP_SUPPORT=2
else
DEFINES += MTK_MRDUMP_SUPPORT=1
endif

ifeq ($(strip $(MTK_MRDUMP_PARTITION_ENABLE)),yes)
DEFINES += MRDUMP_PARTITION_ENABLE
endif

ifeq ($(strip $(MTK_MRDUMP_PARTITION_ENABLE)),debug)
ifneq ($(TARGET_BUILD_VARIANT),user)
DEFINES += MRDUMP_PARTITION_ENABLE
endif
endif

OBJS += \
	$(LOCAL_DIR)/aee/aee.o \
	$(LOCAL_DIR)/aee/mrdump_datafs.o \
	$(LOCAL_DIR)/aee/mrdump_dbgscript.o \
	$(LOCAL_DIR)/aee/mrdump_dconfig.o \
	$(LOCAL_DIR)/aee/mrdump_elf.o \
	$(LOCAL_DIR)/aee/mrdump_mpart.o \
	$(LOCAL_DIR)/aee/mrdump_null.o \
	$(LOCAL_DIR)/aee/mrdump_rsvmem.o \
	$(LOCAL_DIR)/aee/mrdump_sddev.o \
	$(LOCAL_DIR)/aee/mrdump_usb.o \
	$(LOCAL_DIR)/aee/mrdump_zip.o

endif

ifeq ($(KEDUMP_MINI), yes)
OBJS += $(LOCAL_DIR)/aee/KEDump.o \
	$(LOCAL_DIR)/aee/armmmu_translate.o \
	$(LOCAL_DIR)/aee/platform_debug.o \
	$(LOCAL_DIR)/aee/reboot_record.o \
	$(LOCAL_DIR)/aee/mrdump_setup.o
endif

OBJS += \
	$(LOCAL_DIR)/aee/ram_console.o

SECRO_TYPE := GMP
OBJS += \
$(LOCAL_DIR)/dl_commands.o

ifeq ($(MTK_SECURITY_SW_SUPPORT), yes)
ifeq ($(MTK_SEC_FASTBOOT_UNLOCK_SUPPORT), yes)
	OBJS += $(LOCAL_DIR)/sec_unlock.o
endif
endif

ifeq ($(MTK_SMC_ID_MGMT), yes)
DEFINES += MTK_SMC_ID_MGMT
OBJS += $(LOCAL_DIR)/mt_secure_call.o
endif

ifeq ($(MTK_DIS_ATF_RAM_DUMP), yes)
DEFINES += MTK_DIS_ATF_RAM_DUMP
endif

ifeq ($(BUILD_SEC_LIB),yes)
#directories
CRYPTO_DIR  := $(LOCAL_DIR)/crypto
SEC_DIR   := $(LOCAL_DIR)/sec
SEC_PLAT_DIR   := $(LOCAL_DIR)/platform
EXPORT_INC_DIR   := $(LOCAL_DIR)/export_inc
#source files te built
CRYPTO_LOCAL_OBJS := $(patsubst $(CRYPTO_DIR)/%.c,$(CRYPTO_DIR)/%.o,$(wildcard $(CRYPTO_DIR)/*.c))
SEC_LOCAL_OBJS  := $(patsubst $(SEC_DIR)/%.c,$(SEC_DIR)/%.o,$(wildcard $(SEC_DIR)/*.c))
SEC_PLAT_LOCAL_OBJS  := $(patsubst $(SEC_PLAT_DIR)/%.c,$(SEC_PLAT_DIR)/%.o,$(wildcard $(SEC_PLAT_DIR)/*.c))
#objet files to be archived(referenced by make/build.mk)
CRYPTO_OBJS := $(patsubst $(CRYPTO_DIR)/%.c,$(MT_BOOT_OBJ_DIR)/crypto/%.o,$(wildcard $(CRYPTO_DIR)/*.c))
SEC_OBJS  := $(patsubst $(SEC_DIR)/%.c,$(MT_BOOT_OBJ_DIR)/sec/%.o,$(wildcard $(SEC_DIR)/*.c))
SEC_PLAT_OBJS  := $(patsubst $(SEC_PLAT_DIR)/%.c,$(MT_BOOT_OBJ_DIR)/platform/%.o,$(wildcard $(SEC_PLAT_DIR)/*.c))
#include path and object file list for building
INCLUDES += -I$(CRYPTO_DIR)/inc -I$(SEC_DIR)/inc -I$(SEC_PLAT_DIR) -I$(EXPORT_INC_DIR)
OBJS += $(CRYPTO_LOCAL_OBJS) $(SEC_LOCAL_OBJS) $(SEC_PLAT_LOCAL_OBJS)
endif

ifeq ($(BUILD_DEVINFO_LIB),yes)
DEVINFO_DIR   := $(LOCAL_DIR)/devinfo
DEVINFO_LOCAL_OBJS  := $(patsubst $(DEVINFO_DIR)/%.c,$(DEVINFO_DIR)/%.o,$(wildcard $(DEVINFO_DIR)/*.c))
DEVINFO_OBJS  := $(patsubst $(DEVINFO_DIR)/%.c,$(MT_BOOT_OBJ_DIR)/devinfo/%.o,$(wildcard $(DEVINFO_DIR)/*.c))
INCLUDES += -I$(DEVINFO_DIR)
OBJS += $(DEVINFO_LOCAL_OBJS)
endif

ifeq ($(BUILD_HW_CRYPTO_LIB),yes)
HW_CRYPTO_DIR  := $(LOCAL_DIR)/hw_crypto
INCLUDES += -I$(HW_CRYPTO_DIR)/inc
HW_CRYPTO_LOCAL_OBJS := $(patsubst $(HW_CRYPTO_DIR)/%.c,$(HW_CRYPTO_DIR)/%.o,$(wildcard $(HW_CRYPTO_DIR)/*.c))
HW_CRYPTO_OBJS := $(patsubst $(HW_CRYPTO_DIR)/%.c,$(MT_BOOT_OBJ_DIR)/hw_crypto/%.o,$(wildcard $(HW_CRYPTO_DIR)/*.c))
OBJS += $(HW_CRYPTO_LOCAL_OBJS)
endif

ifeq ($(MTK_AB_OTA_UPDATER),yes)
INCLUDES += -I$(LK_TOP_DIR)/platform/common/bootctrl/$(MTK_BOOTCTRL_VERSION)
endif

INCLUDES += -I$(LK_TOP_DIR)/platform/common/RoT

INCLUDES += -Iplatform/$(PLATFORM)/include/platform

INCLUDES += -I$(LK_TOP_DIR)/dev/md_com

ifeq ($(strip $(MTK_EMMC_SUPPORT)),yes)
ifeq ($(strip $(MTK_MMC_COMBO_DRV)),yes)
INCLUDES += -I$(LK_TOP_DIR)/platform/common/storage/mmc/inc
else
INCLUDES += -I$(LK_TOP_DIR)/platform/$(PLATFORM)/include
endif
endif

ifeq ($(strip $(MNTL_SUPPORT)),yes)
ifeq ($(strip $(MTK_MMC_COMBO_DRV)),yes)
INCLUDES += -I$(LK_TOP_DIR)/platform/common/storage/mmc/inc
else
INCLUDES += -I$(LK_TOP_DIR)/platform/$(PLATFORM)/include
endif
endif
