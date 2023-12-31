LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

##############################################################################
# Check build type. (End)
##############################################################################

ifeq ($(MTK_EMMC_SUPPORT),yes)
ifneq ($(filter MTK_NEW_COMBO_EMMC_SUPPORT, $(strip $(DEFINES))),)
OBJS += $(LOCAL_DIR)/combo_emmc_ufs_generic_inter.o
else
OBJS += $(LOCAL_DIR)/emmc_generic_inter.o
endif
else ifeq ($(MTK_UFS_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/combo_emmc_ufs_generic_inter.o
#else ifeq ($(MTK_NAND_UBIFS_SUPPORT),yes)
else
OBJS += $(LOCAL_DIR)/nand_generic_inter.o
endif # ifeq ($(MTK_EMMC_SUPPORT),yes)

