LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

# partition interface
OBJS += $(LOCAL_DIR)/part_internal_wrapper.o \
	$(LOCAL_DIR)/part_common.o

ifeq ($(MTK_PARTITION_COMMON), yes)
OBJS += $(LOCAL_DIR)/env.o $(LOCAL_DIR)/efi.o
ifeq ($(MTK_POWER_ON_WP),yes)
ifeq ($(MTK_EMMC_SUPPORT),yes)
OBJS +=$(LOCAL_DIR)/partition_wp.o
else ifeq ($(MTK_UFS_SUPPORT),yes)
OBJS +=$(LOCAL_DIR)/partition_wp.o
endif
endif
endif

ifeq ($(MTK_EMMC_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/part_emmc_ufs.o
else ifeq ($(MTK_UFS_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/part_emmc_ufs.o
else
OBJS += $(LOCAL_DIR)/part_nand.o
endif

