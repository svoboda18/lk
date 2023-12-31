LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

ifeq ($(MTK_EMMC_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/plinfo_emmc_ufs.o
else ifeq ($(MTK_UFS_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/plinfo_emmc_ufs.o
#else ifeq ($(MTK_NAND_UBIFS_SUPPORT),yes)
else
OBJS += $(LOCAL_DIR)/plinfo_nand.o
endif # ifeq ($(MTK_EMMC_SUPPORT),yes)

