#include <debug.h>
#include "sparse_format.h"
#include "sparse_state_machine.h"
#include "transfer.h"
#include "pal_log.h"

#if (!defined(MTK_UFS_SUPPORT) && !defined(MTK_EMMC_SUPPORT))

#include <platform/mtk_nand.h>
#if defined(MTK_MLC_NAND_SUPPORT) || defined(MTK_TLC_NAND_SUPPORT)
extern int nand_write_img(u64 addr, void *data, u32 img_sz,u64 partition_size,int partition_type);
extern int nand_write_img_ex(u64 addr, void *data, u32 length,u64 total_size, u32 *next_offset, u64 partition_start,u64 partition_size, int img_type);
#else
extern int nand_write_img(u32 addr, void *data, u32 img_sz,u32 partition_size,int partition_type);
extern int nand_write_img_ex(u32 addr, void *data, u32 length,u32 total_size, u32 *next_offset, u32 partition_start,u32 partition_size, int img_type);
#endif


//only engine data structure.
static unsparse_data_t m_unsparse_data;

static void write_sparse_data_internal(unsparse_status_t* status);

static void set_unsparse_status( unsparse_status_t* status,
								status_t handle_status,
								unsparse_phase_t wait_phase,
								uint32 size,
								uint8 *buf	)
{
	status->handle_status = handle_status;
	status->wait_phase = wait_phase;
	status->byte_to_process = size;
	status->buf = buf;
}
static void init_cache_context(unsparse_status_t* status);
void init_unsparse_status(unsparse_status_t* status, partition_info_struct_t* partition)
{
	memset(status, 0, sizeof(unsparse_status_t));
	set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_SPARSE_HEADER, 0, 0);
	status->partition = partition;
	init_cache_context(status);
}

extern int nand_get_alignment();
static void adjust_cache_size(struct cache_ctx* ctx)
{
	uint32 size = nand_get_alignment();

	ctx->c_base = get_global_cache1();
	ctx->c_size = size;
	ctx->c_offset = 0;
}

static void init_cache_context(unsparse_status_t* status)
{
	adjust_cache_size(&status->ctx);
}

extern int get_nand_image_type(const char* arg);

void end_write_sparse_data(unsparse_status_t* status)
{
	status->wait_phase = UNSPARSE_WAIT_CHUNK_NOT_CARE;
	m_unsparse_data.chunk_remain_data_size = status->ctx.c_size - status->ctx.c_offset;
	write_sparse_data_internal(status);
}
static void memsetint(void* p, int i, int len)
{
	int idx=0;
	int count = len>>2;
	int* buf = (int*)p;
	while(idx < count)
	{
		buf[idx++] = i;
	}
}

#define LOGDBG(...)
static void write_sparse_data_internal(unsparse_status_t* status)
{
	uint32 size = status->byte_to_process;
	uint8 *buf = status->buf;
	int filled_seed = 0;
	LOGDBG("+++++++++++++++++++++++++++\n");
	LOGDBG("         slot base:[0x%x]\n", status->ctx.c_base);
	switch (status->wait_phase)
	{
	case UNSPARSE_WAIT_SPARSE_HEADER:
		{
			LOGDBG("+ SPARSE_HEADER\n");
			if (size >=sizeof (sparse_header_t))
			{
				memset((void*)&m_unsparse_data, 0x00, sizeof(unsparse_data_t));
				memcpy((void*)&m_unsparse_data.sparse_hdr, buf, sizeof (sparse_header_t));

				size -= sizeof (sparse_header_t);
				buf+= sizeof (sparse_header_t);
				m_unsparse_data.unhandle_buf_size = 0;
				set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			}
			LOGDBG("- SPARSE_HEADER\n");
			break;
		}

	case UNSPARSE_WAIT_CHUNK_HEADER:
		{
			LOGDBG("+ CHUNK_HEADER\n");
			if (m_unsparse_data.unhandle_buf_size + size >= m_unsparse_data.sparse_hdr.chunk_hdr_sz)
			{
				if (m_unsparse_data.unhandle_buf_size > 0)
				{
					uint32 sizeOfUsedBuf = m_unsparse_data.sparse_hdr.chunk_hdr_sz - m_unsparse_data.unhandle_buf_size;
					memcpy(&m_unsparse_data.chunk_hdr, m_unsparse_data.unhandle_buf, m_unsparse_data.unhandle_buf_size);
					memcpy( ((uint8*)&m_unsparse_data.chunk_hdr) + m_unsparse_data.unhandle_buf_size, buf, sizeOfUsedBuf);

					size -= sizeOfUsedBuf;
					buf+= sizeOfUsedBuf;
					m_unsparse_data.unhandle_buf_size = 0;
				}
				else
				{
					memcpy(&m_unsparse_data.chunk_hdr, buf, m_unsparse_data.sparse_hdr.chunk_hdr_sz);
					size -= m_unsparse_data.sparse_hdr.chunk_hdr_sz;
					buf+= m_unsparse_data.sparse_hdr.chunk_hdr_sz;
				}

				m_unsparse_data.chunk_remain_data_size = (uint64)m_unsparse_data.chunk_hdr.chunk_sz*m_unsparse_data.sparse_hdr.blk_sz;
				LOGDBG("       INFO: chunk size:[0x%llx]\n", m_unsparse_data.chunk_remain_data_size);
				switch (m_unsparse_data.chunk_hdr.chunk_type)
				{
				case CHUNK_TYPE_RAW:
					{
						LOGDBG("                RAW\n");
						set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_DATA, size, buf);
						break;
					}
				case CHUNK_TYPE_DONT_CARE:
					{
						LOGDBG("                DONT_CARE\n");
						set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_NOT_CARE, size, buf);
						break;
					}
				case CHUNK_TYPE_FILL:
					{
						LOGDBG("                FILL\n");
						set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_FILL, size, buf);
						break;
					}
				case CHUNK_TYPE_CRC:
					{
						LOGDBG("                CRC\n");
						set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_CRC, size, buf);
						break;
					}
				default:
					LOGI("@: CHUNK_TYPE_UNKNOWN: 0x%x\n", m_unsparse_data.chunk_hdr.chunk_type);
					status->handle_status = STATUS_UNKNOWN_SPARSE_CHUNK_TYPE;
					return;
				}
			}
			else
			{
				LOGDBG("                HEADER SPLIT\n");
				// LOGI("????: CHUNK_HEADER splitted.\n");
				m_unsparse_data.unhandle_buf_size = size;
				memcpy(m_unsparse_data.unhandle_buf, buf, size);
				size = 0; // force to jump out while loop
				set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			}
			LOGDBG("- CHUNK_HEADER\n");
			break;
		}
	case UNSPARSE_WAIT_CHUNK_FILL:
		{
			LOGDBG("+ CHUNK_FILL\n");
			filled_seed = *(int*)buf;
			buf += sizeof(uint32);
			size -= sizeof(uint32);
			while(m_unsparse_data.chunk_remain_data_size != 0)
			{
				uint32 slot_len = status->ctx.c_size - status->ctx.c_offset;

				if(m_unsparse_data.chunk_remain_data_size >= slot_len)
				{
					//cache is full, so write it.
					memsetint(status->ctx.c_base + status->ctx.c_offset, filled_seed, slot_len);
					if (nand_write_img((u64)(status->partition->base_addr+m_unsparse_data.image_address_offset), (char*)status->ctx.c_base,  status->ctx.c_size
						,(u64)status->partition->max_size, get_nand_image_type(status->partition->name)))
					{
						status->handle_status = STATUS_NAND_ERR;
					}

					if (status->handle_status  != STATUS_OK)
					{
						LOGDBG("[UNSPARSE] S_STORAGE_WRITE_FAILED:%d, status=%d, size=%d\n",__LINE__, status->handle_status, status->byte_to_process);
						return;
					}

					status->ctx.c_offset = 0;// reset cache.
					m_unsparse_data.chunk_remain_data_size -= slot_len;

					m_unsparse_data.image_address_offset += status->ctx.c_size;

				}
				else
				{
					//fill the space with 0xFF.
					memsetint(status->ctx.c_base + status->ctx.c_offset, filled_seed, m_unsparse_data.chunk_remain_data_size);
					status->ctx.c_offset += m_unsparse_data.chunk_remain_data_size;
					m_unsparse_data.chunk_remain_data_size = 0;
				}
			}

			set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			LOGDBG("- CHUNK_FILL\n");
			break;
		}
	case UNSPARSE_WAIT_CHUNK_CRC:
		{
			LOGDBG("+ CHUNK_CRC\n");
			filled_seed = *(uint32*)buf;
			buf += sizeof(uint32);
			size -= sizeof(uint32);
			m_unsparse_data.chunk_remain_data_size = 0;
			set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			LOGDBG("- CHUNK_CRC\n");
			break;
		}
	case UNSPARSE_WAIT_CHUNK_NOT_CARE:
		{
			LOGDBG("+ CHUNK_NOT_CARE\n");
			LOGDBG("         INFO: chunk remain size:[0x%llx]\n", m_unsparse_data.chunk_remain_data_size);
			while(m_unsparse_data.chunk_remain_data_size != 0)
			{
				uint32 slot_len = status->ctx.c_size - status->ctx.c_offset;
				LOGDBG("         INFO: slot len:[0x%x]\n", slot_len);
				if(m_unsparse_data.chunk_remain_data_size >= slot_len)
				{
					//cache is full, so write it.
					if(status->ctx.c_offset != 0)
					{
						LOGDBG("         Write at offset:[0x%llx]\n", m_unsparse_data.image_address_offset);
						memset(status->ctx.c_base + status->ctx.c_offset, 0xFF, slot_len);
						if (nand_write_img((u64)(status->partition->base_addr+m_unsparse_data.image_address_offset), (char*)status->ctx.c_base,  status->ctx.c_size
							,(u64)status->partition->max_size, get_nand_image_type(status->partition->name)))
						{
							status->handle_status = STATUS_NAND_ERR;
						}

						if (status->handle_status  != STATUS_OK)
						{
							pal_log_err("[UNSPARSE] S_STORAGE_WRITE_FAILED:%d, status=%d, size=%d\n",__LINE__, status->handle_status, status->byte_to_process);
							return;
						}
					}
					else
					{
						//cache is empty, do nothing to prevent from writing void data.
					}
					status->ctx.c_offset = 0;// reset cache.
					m_unsparse_data.chunk_remain_data_size -= slot_len;

					m_unsparse_data.image_address_offset += status->ctx.c_size;
				}
				else
				{
					//fill the space with 0xFF.
					LOGDBG("         Set 0xff:[0x%llx]\n", m_unsparse_data.chunk_remain_data_size);
					memset(status->ctx.c_base + status->ctx.c_offset, 0xFF, m_unsparse_data.chunk_remain_data_size);
					status->ctx.c_offset += m_unsparse_data.chunk_remain_data_size;

					m_unsparse_data.chunk_remain_data_size = 0;
				}
			}
			set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			LOGDBG("- CHUNK_NOT_CARE\n");
			break;
		}
	case UNSPARSE_WAIT_CHUNK_DATA:
		{
			LOGDBG("+ CHUNK_DATA\n");
			uint64 this_process_len = 0;
			if(size >= m_unsparse_data.chunk_remain_data_size)
			{
				this_process_len = m_unsparse_data.chunk_remain_data_size;
			}
			else
			{
				this_process_len = size;
			}

			uint32 slot_len = status->ctx.c_size - status->ctx.c_offset;
			LOGDBG("               data left [0x%x], slot[0x%x], chunk remain [0x%llx]\n", size, slot_len, m_unsparse_data.chunk_remain_data_size);

			if(slot_len <= this_process_len)
			{
				LOGDBG("               Write at [0x%llx]\n", m_unsparse_data.image_address_offset);
				//cache is full.
				memcpy(status->ctx.c_base + status->ctx.c_offset, buf, slot_len);

				if (nand_write_img((u64)(status->partition->base_addr+m_unsparse_data.image_address_offset), (char*)status->ctx.c_base,  status->ctx.c_size
					,(u64)status->partition->max_size,get_nand_image_type(status->partition->name)))
				{
					status->handle_status = STATUS_NAND_ERR;
				}
				if (status->handle_status  != STATUS_OK)
				{
					LOGDBG("[UNSPARSE] S_STORAGE_WRITE_FAILED:%d, status=%d, size=%d\n",__LINE__, status->handle_status, status->byte_to_process);
					return;
				}

				buf += slot_len;
				size -= slot_len;
				m_unsparse_data.image_address_offset += status->ctx.c_size;

				m_unsparse_data.chunk_remain_data_size -= slot_len;
				status->ctx.c_offset = 0;// reset cache.

			}
			else
			{
				LOGDBG("                copy to slot[0x%x] OF data[0x%x]\n",slot_len, this_process_len);
				//cache is not full.
				memcpy(status->ctx.c_base + status->ctx.c_offset, buf, this_process_len);
				status->ctx.c_offset += this_process_len;

				buf += this_process_len;
				size -= this_process_len;

				m_unsparse_data.chunk_remain_data_size -= this_process_len;
				LOGDBG("                copy to slot end\n");
			}
			if(m_unsparse_data.chunk_remain_data_size == 0)
			{
				set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			}
			else
			{
				set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_DATA, size, buf);
			}
			LOGDBG("- CHUNK_DATA\n");
			break;
		}

	default:
		pal_log_info("sparse image do nothing.\n");
		break;
	}
	LOGDBG("---------------------------------\n");
	return ;
}

void write_sparse_data(unsparse_status_t* status, uint8* data, uint32 length)
{
	status->buf = data;
	status->byte_to_process = length;
	do
	{
		write_sparse_data_internal(status);

		if (status->handle_status != STATUS_OK)
		{
			return;
		}

	} while (status->byte_to_process > 0);
	return;
}

inline bool is_sparse_image(uint8* data, uint32 length)
{
	sparse_header_t *sparse_header = (sparse_header_t *) data;
	return (sparse_header->magic == SPARSE_HEADER_MAGIC) ;
}

inline uint64 unspared_size(uint8* data)
{
	uint64 size = 0;
	sparse_header_t *sparse_header = (sparse_header_t *) data;
	size = sparse_header->blk_sz * sparse_header->total_blks;

	return size;
}

inline bool support_sparse_image(void)
{
	return true;
}

#endif

