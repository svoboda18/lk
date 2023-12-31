#ifndef __M_TRANSFER_H
#define __M_TRANSFER_H

#define MAX_PARTITION_NAME_LEN 32


#define ROUND_TO_PAGE(x,y) (((x) + (y)) & (~(y)))
#define PARTITION_NAME_SIZE  MAX_PARTITION_NAME_LEN
#define MAX_EXT_SIG_LEN (2*1024*1024)

#define STATUS_OK 0
#define STATUS_INVALID_PARAMETERS 	(-100)
#define STATUS_TOO_LARGE 			(-101)
#define STATUS_USB_ERR 				(-102)
#define STATUS_EMMC_ERR 			(-103)
#define STATUS_NAND_ERR 			(-104)
#define STATUS_THREAD 				(-105)
#define STATUS_UNKNOWN_SPARSE_CHUNK_TYPE 	(-106)

#define STATUS_SPARSE_INCOMPLETE  (100)
#define FAIL(code) 		(((status_t)(code)) < 0)

typedef  unsigned char uint8;
typedef  unsigned int uint32;
typedef  unsigned long long uint64;

#define LOGI _dprintf
#define LOGE _dprintf



typedef struct partition_info_struct
{
	uint8  name[PARTITION_NAME_SIZE];
	uint64 base_addr;
	uint64 max_size;
	int part_id;
}partition_info_struct_t;


typedef struct download_data_context {
	bool first_run;
	uint64 bytes_written;
	uint64 length_to_write;
	partition_info_struct_t *part_info;
} download_data_context_t;


static inline void init_download_data_context(download_data_context_t* data_ctx, uint64 data_length, partition_info_struct_t* part_info)
{
	data_ctx->first_run = 1;
	data_ctx->bytes_written = 0;
	data_ctx->length_to_write = data_length;
	data_ctx->part_info = part_info;
}

status_t download_data(uint64 data_length, partition_info_struct_t* part_info);
uint8* get_global_cache1();

#endif


