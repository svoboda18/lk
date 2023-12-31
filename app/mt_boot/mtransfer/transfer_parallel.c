
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

#include "dl_commands.h"

#include "sparse_format.h"
#include "transfer.h"
#include "sparse_state_machine.h"
#include "bulk_process.h"

#if defined MTK_ULTRA_FLASH

#define TIME_STAMP gpt4_tick2time_ms(gpt4_get_current_tick())


#define CACHE_PADDING_SIZE 	STORAGE_BLOCK_SIZE
#define SYSOB_CACHE_PAGE   2*1024*1024U
#define SYSOB_BIG_CACHE   2*1024*1024U
#define SIGNAL_RESCHEDULE 0  //true; active. 0 passive.

/***********************************************************************************
*                  DOWNLOAD ENGINE
***********************************************************************************/
typedef enum engine_op_part
{
	EOP_DATA_PROVIDER,
	EOP_DATA_CONSUMER,
}engine_part_e;

typedef struct cache
{
	uint8* padding_buf;
	uint8* cache_buf;
	uint32 padding_length;  //sparse image boundary problem.
	uint32 content_length;  //if this is 0, indicate this the last package.
	event_t content_available;
	event_t cache_available;
}cache_t;


typedef struct engine_context
{
	uint8* cache_base;
	cache_t dual_cache[2];
	uint32 flipIdxR;     //receive buffer shift
	uint32 flipIdxW;    //write buffer shift
	event_t thrR_end_ev; // recieve thread exit sync.
	event_t thrW_end_ev; // write thread exit sync.
	status_t status_usb ; // if something is wrong, should exit.
	status_t status_storage ; // if something is wrong, should exit.
}engine_context_t;


static engine_context_t* ctx;

#define ALIGN_SZ (64)

#define MM_BASE get_available_ram_base()
#define MM_1ST_16M (((uint8*)get_available_ram_base())+3*SYSOB_BIG_CACHE)

extern uint8* get_global_cache1()
{
	return MM_1ST_16M;
}

void init_engine_context(engine_context_t* tx)
{
	/*dual cache pattern:     | PADDING1 | CACHE1 || PADDING2 | CACHE2 |*/
	uint32 CACHE_PAGE_SIZE = SYSOB_CACHE_PAGE;
	//uint32 DCACHE_SIZE  = (2*CACHE_PAGE_SIZE+2*CACHE_PADDING_SIZE);

	tx->cache_base = (uint8*)get_available_ram_base();

	tx->dual_cache[0].padding_buf = tx->cache_base;
	tx->dual_cache[0].cache_buf = tx->cache_base+CACHE_PADDING_SIZE;
	tx->dual_cache[1].padding_buf = tx->cache_base+CACHE_PADDING_SIZE+CACHE_PAGE_SIZE;
	tx->dual_cache[1].cache_buf = tx->cache_base+CACHE_PADDING_SIZE+CACHE_PAGE_SIZE+CACHE_PADDING_SIZE;

	tx->dual_cache[0].padding_length = tx->dual_cache[1].padding_length = 0;

	event_init(&tx->dual_cache[0].content_available, 0, EVENT_FLAG_AUTOUNSIGNAL);//no data in cache
	event_init(&tx->dual_cache[1].content_available, 0, EVENT_FLAG_AUTOUNSIGNAL);//no data in cache

	event_init(&tx->dual_cache[0].cache_available, 1, EVENT_FLAG_AUTOUNSIGNAL);    //can receive from usb
	event_init(&tx->dual_cache[1].cache_available, 1, EVENT_FLAG_AUTOUNSIGNAL);    //can receive from usb

	event_init(&tx->thrR_end_ev, 0, EVENT_FLAG_AUTOUNSIGNAL);//do not end.
	event_init(&tx->thrW_end_ev, 0, EVENT_FLAG_AUTOUNSIGNAL);//do not end.
	tx->status_usb = STATUS_OK;
	tx->status_storage = STATUS_OK;
	tx->flipIdxR = tx->flipIdxW = 0;

}

inline uint32 cache_shift(uint32 pre)
{
	return pre ^ 0x01;
}

void stop_engine(engine_context_t * tx, engine_part_e part)
{
	if(part == EOP_DATA_CONSUMER)
	{
		event_signal(&tx->dual_cache[0].cache_available, SIGNAL_RESCHEDULE);
		event_signal(&tx->dual_cache[1].cache_available, SIGNAL_RESCHEDULE);
		event_signal(&tx->thrR_end_ev, SIGNAL_RESCHEDULE);
	}
	else if(part == EOP_DATA_PROVIDER)
	{
		event_signal(&tx->dual_cache[0].content_available, SIGNAL_RESCHEDULE);
		event_signal(&tx->dual_cache[1].content_available, SIGNAL_RESCHEDULE);
		event_signal(&tx->thrW_end_ev, SIGNAL_RESCHEDULE);
	}
}

void destroy_engine(engine_context_t* tx)
{
	event_destroy(&tx->dual_cache[0].cache_available);
	event_destroy(&tx->dual_cache[1].cache_available);
	event_destroy(&tx->dual_cache[0].content_available);
	event_destroy(&tx->dual_cache[1].content_available);
	event_destroy(&tx->thrR_end_ev);
	event_destroy(&tx->thrW_end_ev);

	tx->cache_base = 0;
}
/***********************************************************************************
*                  DOWNLOAD
***********************************************************************************/

static download_data_context_t* write_data_ctx = 0;

status_t write_data(uint8* data, uint32 length)
{
	int next_flip = 0;
	static unsparse_status_t unsparse_status; //sparse image parsing used.
	static bulk_status_t bulk_status; //bulk image parsing used.
	static bool is_sparse = false;
	uint64 total_image_length = 0;//if sparse image, it should be size after unsparsed.


	if(data == 0)
	{
		return STATUS_INVALID_PARAMETERS;
	}

	if(write_data_ctx->first_run)
	{
		is_sparse = is_sparse_image(data, length);
		total_image_length = write_data_ctx->length_to_write;

		if(is_sparse)
		{
			init_unsparse_status(&(unsparse_status),  write_data_ctx->part_info);
			total_image_length = unspared_size(data);
		}
		else
		{
			init_bulk_process_status(&(bulk_status),  write_data_ctx->part_info);
			total_image_length = write_data_ctx->length_to_write;
		}

		if (total_image_length> write_data_ctx->part_info->max_size)
		{
			LOGE( "size too large, space small. image length[0x%llx], partition max size[0x%llx]\n",
				total_image_length,  write_data_ctx->part_info->max_size);
			return STATUS_TOO_LARGE;
		}
		//The first run flag will be reset later after erase_before_download finished.
		write_data_ctx->first_run = 0;
	}

	if (is_sparse)
	{
		next_flip = cache_shift(ctx->flipIdxR);

		if(length != 0)
		{
			write_sparse_data(&unsparse_status, data, length);
			if (unsparse_status.handle_status == STATUS_SPARSE_INCOMPLETE)
			{
				memcpy(ctx->dual_cache[next_flip].padding_buf +(CACHE_PADDING_SIZE-unsparse_status.byte_to_process)
					, unsparse_status.buf
					, unsparse_status.byte_to_process);
				ctx->dual_cache[next_flip].padding_length = unsparse_status.byte_to_process;
				unsparse_status.handle_status = STATUS_OK;
			}
			else if (unsparse_status.handle_status== STATUS_OK)
			{
				ctx->dual_cache[next_flip].padding_length = 0;
			}
		}
		else
		{
			//the last package.
			end_write_sparse_data(&unsparse_status);
		}
	}
	else
	{
		if (length != 0)
		{
			write_bulk_data(&bulk_status, data, length);
		}
		else
		{//the last package.
			end_write_bulk(&bulk_status);
		}
	}
	return unsparse_status.handle_status;

}


int write_storage_proc(void *arg)
{
	uint8* data = 0;
	uint32 data_len = 0;

	//LOGI("\nin write_storage_proc\n");

	for (;;)
	{
		event_wait(&(ctx->dual_cache[ctx->flipIdxR].content_available));

		if(FAIL(ctx->status_usb))
		{
			goto exit;
		}

		//if has something to write
		data = (uint8*)(ctx->dual_cache[ctx->flipIdxR].cache_buf);
		data_len = ctx->dual_cache[ctx->flipIdxR].content_length;

		data -= ctx->dual_cache[ctx->flipIdxR].padding_length;
		data_len += ctx->dual_cache[ctx->flipIdxR].padding_length;
		ctx->status_storage = write_data(data, data_len);

		if(ctx->status_storage != STATUS_OK)
		{
			//error
			LOGE("write data failed. handle_status(%d)\n", ctx->status_storage);
			goto exit;
		}

		//last package, should return;
		if (ctx->dual_cache[ctx->flipIdxR].content_length == 0)
		{
			break;
		}
		event_signal(&ctx->dual_cache[ctx->flipIdxR].cache_available, SIGNAL_RESCHEDULE); //make this cache writeable again.

		ctx->flipIdxR = cache_shift(ctx->flipIdxR); //change next buffer.
	}

exit:
	stop_engine(ctx, EOP_DATA_CONSUMER);
	thread_exit(0);
	//never arrive here.
	return 0;
}

extern int usb_read(void *_buf, unsigned len);
void read_usb_proc(uint64 data_length)
{
	uint64 bytes_already_read = 0;
	uint64 bytes_to_read = 0;
	uint32 CACHE_PAGE_SIZE = SYSOB_CACHE_PAGE;
	uint32 TOTAL_CACHE_PAGE_SIZE = SYSOB_BIG_CACHE;

	while (bytes_already_read  < data_length)
	{
		event_wait(&(ctx->dual_cache[ctx->flipIdxW].cache_available));

		ctx->dual_cache[ctx->flipIdxW].content_length = 0;
		uint32 cache_offset = 0;
		while((cache_offset < TOTAL_CACHE_PAGE_SIZE) && (bytes_already_read  < data_length))
		{
			bytes_to_read = data_length - bytes_already_read;
			bytes_to_read = bytes_to_read >= CACHE_PAGE_SIZE ? CACHE_PAGE_SIZE : bytes_to_read;

			//LOGI("$$ Read usb length 0x%llx, buf addr at 0x%x\n", bytes_to_read, ctx->dual_cache[ctx->flipIdxW].cache_buf+cache_offset);
			int r = usb_read(ctx->dual_cache[ctx->flipIdxW].cache_buf+cache_offset, (unsigned int)bytes_to_read);
			if ((r < 0) || ((unsigned int) r != (unsigned int)bytes_to_read))
			{
				ctx->status_usb = STATUS_USB_ERR;
				LOGE("Read usb error. code 0x%x\n", ctx->status_usb);
				goto exit;
			}

			ctx->dual_cache[ctx->flipIdxW].content_length += bytes_to_read;
			bytes_already_read += bytes_to_read;
			cache_offset += bytes_to_read;

			if(FAIL(ctx->status_usb) || FAIL(ctx->status_storage))
			{
				// storage write error.
				goto exit;
			}
			display_progress("\rFlash: ", bytes_already_read, write_data_ctx->length_to_write);
		}

		event_signal(&ctx->dual_cache[ctx->flipIdxW].content_available, SIGNAL_RESCHEDULE);
		ctx->flipIdxW = cache_shift(ctx->flipIdxW); //change next buffer.
	}

	//last package.
	//must wait for this can write again. wait for storage write finish.
	event_wait(&(ctx->dual_cache[ctx->flipIdxW].cache_available));
	//notify finish info to storage write thread with zero length packet.
	ctx->dual_cache[ctx->flipIdxW].content_length = 0;
	event_signal(&ctx->dual_cache[ctx->flipIdxW].content_available, SIGNAL_RESCHEDULE);

exit:
	stop_engine(ctx, EOP_DATA_PROVIDER);
	return;
}


status_t download_data(uint64 data_length, partition_info_struct_t* part_info)//Big image and parallel transfer.
{
	thread_t *thr;
	download_data_context_t data_ctx;
	engine_context_t engine_ctx;

#ifdef DUMP_SPEED
	uint32 time_start = 0;
	uint32 time_end = 0;
#endif

	write_data_ctx = &data_ctx;
	ctx = &engine_ctx;
	init_engine_context(ctx);
	init_download_data_context(write_data_ctx, data_length, part_info);

#ifdef DUMP_SPEED
	time_start = TIME_STAMP;
#endif
	thr = thread_create("write_storage_proc", write_storage_proc, 0, HIGHEST_PRIORITY, 16*1024);
	if (!thr)
	{
		LOGE("create write_storage_proc thread failed.");
		return STATUS_THREAD;
	}
	thread_resume(thr);
	read_usb_proc(data_length);

	//wait for thread end.
	event_wait(&ctx->thrR_end_ev);
	event_wait(&ctx->thrW_end_ev);

#ifdef DUMP_SPEED
	time_end = TIME_STAMP;
#endif

	destroy_engine(ctx);

	LOGI("Process download_data Finish.\n");

	return FAIL(ctx->status_storage) ? ctx->status_storage : ctx->status_usb;
}



#endif

