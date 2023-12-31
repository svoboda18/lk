LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include

OBJS += \
	$(LOCAL_DIR)/libufdt_sysdeps_vendor.o \
	$(LOCAL_DIR)/ufdt_convert.o \
	$(LOCAL_DIR)/ufdt_node.o \
	$(LOCAL_DIR)/ufdt_overlay.o \
	$(LOCAL_DIR)/ufdt_prop_dict.o
