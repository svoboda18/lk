LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)
INCLUDES += -Iplatform/$(PLATFORM)/include/platform
INCLUDES += -Iplatform/common/include

OBJS += $(LOCAL_DIR)/avb_hal.o
ifeq ($(MTK_AB_OTA_UPDATER),yes)
OBJS += $(LOCAL_DIR)/avb_ab_hal.o
endif

DEFINES += AVB_COMPILATION

