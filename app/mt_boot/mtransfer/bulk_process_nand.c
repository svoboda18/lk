#include <stdlib.h>
#include <app.h>
#include <debug.h>
#include <arch/arm.h>
#include <dev/udc.h>
#include <string.h>
#include <kernel/thread.h>
#include <kernel/event.h>
#include <arch/ops.h>
#include <target.h>
#include <platform.h>
#include <platform/mt_gpt.h>

#include "bulk_process.h"
#include "pal_log.h"

#if (!defined(MTK_UFS_SUPPORT) && !defined(MTK_EMMC_SUPPORT))
#define NAND_TYPE

#if defined(MTK_MLC_NAND_SUPPORT) || defined(MTK_TLC_NAND_SUPPORT)
extern int nand_write_img(u64 addr, void *data, u32 img_sz,u64 partition_size,int partition_type);
extern int nand_write_img_ex(u64 addr, void *data, u32 length,u64 total_size, u32 *next_offset, u64 partition_start,u64 partition_size, int img_type);
#else
extern int nand_write_img(u32 addr, void *data, u32 img_sz,u32 partition_size,int partition_type);
extern int nand_write_img_ex(u32 addr, void *data, u32 length,u32 total_size, u32 *next_offset, u32 partition_start,u32 partition_size, int img_type);
#endif


#if 0   //fake NAND.
int nand_get_alignment()
{
	return 4*1024*1024;
}
int nand_write_img(u32 addr, void *data, u32 img_sz,u32 partition_size,int partition_type)
{
	return 0;
}
int get_nand_image_type(const char* arg)
{
	return 0;
}
#endif

static void init_cache_context(bulk_status_t* status);
static void write_bulk_internal(bulk_status_t* status, bool flush_end);


void init_bulk_process_status(bulk_status_t* status,  partition_info_struct_t* partition)
{
	status->partition = partition;
	status->image_address_offset = 0;
	init_cache_context(status);
}

extern int nand_get_alignment();
static void adjust_cache_size(struct bulk_cache_ctx* ctx)
{
	uint32 size = nand_get_alignment();

	//ctx->c_base = (uint8*)memalign(128, size);
	ctx->c_base = get_global_cache1();
	ctx->c_size = size;
	ctx->c_offset = 0;
}


static void init_cache_context(bulk_status_t* status)
{
	adjust_cache_size(&status->ctx);
}

void end_write_bulk(bulk_status_t* status)
{
	write_bulk_internal(status, true);
}

extern int get_nand_image_type(const char* arg);
static void write_bulk_internal(bulk_status_t* status, bool flush_end)
{
	uint32 slot_len = status->ctx.c_size - status->ctx.c_offset;

	if(slot_len <= status->byte_to_process || flush_end)
	{
		uint32 actural_size = 0;
		//cache is full.
		if(flush_end)
		{
			memset(status->ctx.c_base + status->ctx.c_offset, 0xFF, status->ctx.c_size - status->ctx.c_offset);
			actural_size = status->ctx.c_offset;
		}
		else
		{
			memcpy(status->ctx.c_base + status->ctx.c_offset, status->buf, slot_len);
			actural_size = status->ctx.c_size;
		}

		if (nand_write_img((u64)(status->partition->base_addr+status->image_address_offset), (char*)status->ctx.c_base,  status->ctx.c_size
			,(u64)status->partition->max_size, get_nand_image_type(status->partition->name)))
		{
			status->handle_status = STATUS_NAND_ERR;
			pal_log_err("[BULK] S_STORAGE_WRITE_FAILED:%d, status=%d, size=%d\n",__LINE__, status->handle_status, status->byte_to_process);
			return;
		}

		status->buf += slot_len;
		status->byte_to_process -= slot_len;
		status->ctx.c_offset = 0;// reset cache.

		status->image_address_offset += status->ctx.c_size;

	}
	else
	{
		//cache is not full.
		memcpy(status->ctx.c_base + status->ctx.c_offset, status->buf, status->byte_to_process);
		status->ctx.c_offset += status->byte_to_process;

		status->byte_to_process = 0;
	}

	return ;
}


void write_bulk_data(bulk_status_t* status, uint8* data, uint32 length)
{
	status->buf = data;
	status->byte_to_process = length;
	do
	{
		write_bulk_internal(status, false);

		if (status->handle_status != STATUS_OK)
		{
			return;
		}

	} while (status->byte_to_process > 0);

	return;
}

#endif

