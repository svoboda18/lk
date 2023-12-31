LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

OBJS += $(LOCAL_DIR)/img_info.o
OBJS += $(LOCAL_DIR)/loader.o
OBJS += $(LOCAL_DIR)/loader_util_weak.o

