#ifndef 	_BULK_DATA_PROCESS_H_
#define 	_BULK_DATA_PROCESS_H_

#include "transfer.h"

typedef struct bulk_cache_ctx
{
	uint8* c_base;             //cache buffer base
	uint32 c_offset;             //cache buffer offset
	uint32 c_size;             //cache buffer size
} bulk_cache_ctx_t;

typedef struct bulk_status
{
	status_t handle_status;
	uint32 byte_to_process;    // byte to be processed in one packet.
	uint64 image_address_offset;
	uint8 *buf;                        // byte buffer of one packet.
	bulk_cache_ctx_t ctx;           //buffer download context
	partition_info_struct_t* partition;
} bulk_status_t;


void init_bulk_process_status(bulk_status_t* status, partition_info_struct_t* partition);
void write_bulk_data(bulk_status_t* status, uint8* data, uint32 length);

//ex functions
void end_write_bulk(bulk_status_t* status);



#endif
