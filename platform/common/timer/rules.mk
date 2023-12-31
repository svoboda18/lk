LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

##############################################################################
# Check build type. (End)
##############################################################################

ifeq ($(GPT_VER),1)
OBJS += $(LOCAL_DIR)/mt_gpt_v1.o
endif

ifeq ($(GPT_VER),2)
OBJS += $(LOCAL_DIR)/mt_gpt_v2.o
endif

ifeq ($(GPT_VER),3)
OBJS += $(LOCAL_DIR)/mt_gpt_v3.o
endif

ifeq ($(GPT_VER),4)
OBJS += $(LOCAL_DIR)/mt_gpt_v4.o
endif
