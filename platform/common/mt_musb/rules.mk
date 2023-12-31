LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

OBJS += \
	$(LOCAL_DIR)/mt_musb.o \
	$(LOCAL_DIR)/mt_musb_qmu.o
