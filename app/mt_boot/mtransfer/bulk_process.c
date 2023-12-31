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
#include "transfer.h"
#include "pal_log.h"

#if (defined(MTK_UFS_SUPPORT) || defined(MTK_EMMC_SUPPORT))
extern u64 emmc_write(u32 part_id, u64 offset, void *data, u64 size);

static void write_bulk_internal(bulk_status_t* status);
void init_bulk_process_status(bulk_status_t* status,  partition_info_struct_t* partition)
{
	status->partition = partition;
	status->image_address_offset = 0;
}

void end_write_bulk(bulk_status_t* status)
{
}
static void write_bulk_internal(bulk_status_t* status)
{
	if (emmc_write(status->partition->part_id, status->partition->base_addr+status->image_address_offset , status->buf, status->byte_to_process) != status->byte_to_process)
	{
		status->handle_status = STATUS_EMMC_ERR;
	}

	if (status->handle_status  != STATUS_OK)
	{
		pal_log_err("[BULK] S_STORAGE_WRITE_FAILED:%d, status=%d, size=%d\n",__LINE__, status->handle_status, status->byte_to_process);
		return;
	}

	status->image_address_offset += status->byte_to_process;

	status->byte_to_process = 0;
	return ;
}

void write_bulk_data(bulk_status_t* status, uint8* data, uint32 length)
{
	status->buf = data;
	status->byte_to_process = length;
	do
	{
		write_bulk_internal(status);
		if (status->handle_status != STATUS_OK)
		{
			return;
		}

	} while (status->byte_to_process > 0);

	return;
}

#endif

