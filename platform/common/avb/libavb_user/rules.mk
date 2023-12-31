LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

OBJS += $(LOCAL_DIR)/avb_user_verity.o
OBJS += $(LOCAL_DIR)/avb_user_verification.o

