LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

OBJS += $(LOCAL_DIR)/avb_chain_partition_descriptor.o
OBJS += $(LOCAL_DIR)/avb_crc32.o
OBJS += $(LOCAL_DIR)/avb_crypto.o
OBJS += $(LOCAL_DIR)/avb_cmdline.o
OBJS += $(LOCAL_DIR)/avb_descriptor.o
OBJS += $(LOCAL_DIR)/avb_footer.o
OBJS += $(LOCAL_DIR)/avb_hash_descriptor.o
OBJS += $(LOCAL_DIR)/avb_hashtree_descriptor.o
OBJS += $(LOCAL_DIR)/avb_kernel_cmdline_descriptor.o
OBJS += $(LOCAL_DIR)/avb_property_descriptor.o
OBJS += $(LOCAL_DIR)/avb_rsa.o
ifneq ($(AVB_SHA256_CRYPTO_HW_SUPPORT),yes)
OBJS += $(LOCAL_DIR)/avb_sha256.o
endif
OBJS += $(LOCAL_DIR)/avb_sha512.o
OBJS += $(LOCAL_DIR)/avb_slot_verify.o
OBJS += $(LOCAL_DIR)/avb_sysdeps_posix.o
OBJS += $(LOCAL_DIR)/avb_util.o
OBJS += $(LOCAL_DIR)/avb_vbmeta_image.o
OBJS += $(LOCAL_DIR)/avb_version.o
DEFINES += AVB_COMPILATION

