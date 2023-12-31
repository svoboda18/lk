LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

##############################################################################
# Check build type. (End)
##############################################################################
MODULES += $(LOCAL_DIR)/blkdev
MODULES += $(LOCAL_DIR)/intf
ifeq ($(strip $(MTK_UFS_SUPPORT)),yes)
MODULES += $(LOCAL_DIR)/ufs
endif

ifeq ($(strip $(MTK_EMMC_SUPPORT)),yes)
ifeq ($(strip $(MTK_MMC_COMBO_DRV)),yes)
MODULES += $(LOCAL_DIR)/mmc
endif
endif

ifeq ($(strip $(MNTL_SUPPORT)),yes)
ifeq ($(strip $(MTK_MMC_COMBO_DRV)),yes)
MODULES += $(LOCAL_DIR)/mmc
endif
endif
