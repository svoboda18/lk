LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/inc

OBJS += $(LOCAL_DIR)/pal_log.o \
	$(LOCAL_DIR)/pal_timer.o \
	$(LOCAL_DIR)/pal_mutex.o


