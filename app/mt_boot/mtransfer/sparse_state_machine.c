#if (defined(MTK_UFS_SUPPORT) || defined(MTK_EMMC_SUPPORT))
#include <debug.h>

#include "sparse_format.h"
#include "sparse_state_machine.h"
#include "pal_log.h"

typedef unsigned int u32;
typedef unsigned long long u64;
extern u64 emmc_write(u32 part_id, u64 offset, void *data, u64 size);
extern void * memset(void *s, int c, size_t count);
extern void *memcpy(void *dest, const void *src, size_t count);

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

void init_unsparse_status(unsparse_status_t* status, partition_info_struct_t* partition)
{
	memset(status, 0, sizeof(unsparse_status_t));
	set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_SPARSE_HEADER, 0, 0);
	status->partition = partition;
}

void end_write_sparse_data(unsparse_status_t* status)
{
	//for the last package
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
inline uint64 emmc_write_wp(uint32 part_id, uint64 offset, void *data, uint64 size)
{
	return emmc_write(part_id, offset, data, size);
}

static void write_sparse_data_internal(unsparse_status_t* status)
{
	uint32 size = status->byte_to_process;
	uint8 *buf = status->buf;
	uint32 sizeOfX=0;

	int filled_seed = 0;
	uint8* filled_data_cache = 0;
	uint32 filled_data_len= 0 ;
	if (size==0)
	{
		return ;
	}

	switch (status->wait_phase)
	{
	case UNSPARSE_WAIT_SPARSE_HEADER:
		{
			if (size >=sizeof (sparse_header_t))
			{
				memset((void*)&m_unsparse_data, 0x00, sizeof(unsparse_data_t));
				memcpy((void*)&m_unsparse_data.sparse_hdr, buf, sizeof (sparse_header_t));

				// for real sparse header larger than sparse_header_t struct
				// for titan ext4_sparse_header_8byte_align:  sparse_header_t 8byte align, chunk_header_t 8byte align

				size -= m_unsparse_data.sparse_hdr.file_hdr_sz;
				buf+= m_unsparse_data.sparse_hdr.file_hdr_sz;

				m_unsparse_data.unhandle_buf_size = 0;
				m_unsparse_data.chunks_processed = 0;
				set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			}
			break;
		}

	case UNSPARSE_WAIT_CHUNK_HEADER:
		{
			if(m_unsparse_data.chunks_processed >= m_unsparse_data.sparse_hdr.total_chunks)
			{
				set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, 0, buf);
				return;
			}
			if (m_unsparse_data.unhandle_buf_size + size >=( m_unsparse_data.sparse_hdr.chunk_hdr_sz))
			{
				if (m_unsparse_data.unhandle_buf_size > 0) {
					uint32 sizeOfUsedBuf = m_unsparse_data.sparse_hdr.chunk_hdr_sz - m_unsparse_data.unhandle_buf_size;
					memcpy(&m_unsparse_data.chunk_hdr, m_unsparse_data.unhandle_buf, m_unsparse_data.unhandle_buf_size);
					// for real sparse header larger than sparse_header_t struct
					if((m_unsparse_data.sparse_hdr.chunk_hdr_sz>sizeof(chunk_header_t)))
					{
						memcpy( ((uint8*)&m_unsparse_data.chunk_hdr) + m_unsparse_data.unhandle_buf_size, buf, sizeOfUsedBuf-(m_unsparse_data.sparse_hdr.chunk_hdr_sz-sizeof(chunk_header_t)));
					}else{
						memcpy( ((uint8*)&m_unsparse_data.chunk_hdr) + m_unsparse_data.unhandle_buf_size, buf, sizeOfUsedBuf);
					}

					size -= sizeOfUsedBuf;
					buf+= sizeOfUsedBuf;
					m_unsparse_data.unhandle_buf_size = 0;
				}
				else
				{
					// for real sparse header larger than sparse_header_t struct
					memcpy(&m_unsparse_data.chunk_hdr, buf, sizeof(chunk_header_t));
					size -= m_unsparse_data.sparse_hdr.chunk_hdr_sz;
					buf+= m_unsparse_data.sparse_hdr.chunk_hdr_sz;
				}

				m_unsparse_data.chunk_remain_data_size = (uint64)m_unsparse_data.chunk_hdr.chunk_sz*m_unsparse_data.sparse_hdr.blk_sz;
				switch (m_unsparse_data.chunk_hdr.chunk_type)
				{
				case CHUNK_TYPE_RAW:
					{
						set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_DATA, size, buf);
						break;
					}
				case CHUNK_TYPE_DONT_CARE:
					{
						m_unsparse_data.image_address_offset+=m_unsparse_data.chunk_remain_data_size;
						m_unsparse_data.chunk_remain_data_size = 0;
						set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
						break;
					}
				case CHUNK_TYPE_FILL:
					{
						set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_FILL, size, buf);
						break;
					}
				case CHUNK_TYPE_CRC:
					{
						set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_CRC, size, buf);
						break;
					}
				default:
					pal_log_err("@: CHUNK_TYPE_UNKNOWN: 0x%x\n", m_unsparse_data.chunk_hdr.chunk_type);
					status->handle_status = STATUS_UNKNOWN_SPARSE_CHUNK_TYPE;
					return;
				}
				++m_unsparse_data.chunks_processed;
			}
			else
			{
				m_unsparse_data.unhandle_buf_size = size;
				memcpy(m_unsparse_data.unhandle_buf, buf, size);
				size = 0; // force to jump out while loop
				set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			}
			break;
		}
	case UNSPARSE_WAIT_CHUNK_FILL:
		{
			filled_seed = *(int*)buf;
			buf += sizeof(uint32);
			size -= sizeof(uint32);

#define FILLED_DATA_CACHE_SIZE 2*1024*1024
			filled_data_cache = (uint8*)get_global_cache1();;
			memsetint(filled_data_cache, filled_seed, FILLED_DATA_CACHE_SIZE);

			while(true)
			{
				filled_data_len = (m_unsparse_data.chunk_remain_data_size > FILLED_DATA_CACHE_SIZE) ?
FILLED_DATA_CACHE_SIZE : m_unsparse_data.chunk_remain_data_size;
				if(filled_data_len == 0)
				{
					break;
				}
				if (emmc_write_wp(status->partition->part_id, status->partition->base_addr+m_unsparse_data.image_address_offset , filled_data_cache, filled_data_len) != filled_data_len)
				{
					status->handle_status = STATUS_EMMC_ERR;
				}
				//status->handle_status = storage_interface.write(status->image_base_addr+m_unsparse_data.image_address_offset, filled_data_cache, kk, status->arg);
				if (status->handle_status  != STATUS_OK)
				{
					pal_log_err("[UNSPARSE] S_STORAGE_WRITE_FAILED:%d, status=%d, size=%d\n",__LINE__, status->handle_status, status->byte_to_process);
					return;
				}

				m_unsparse_data.image_address_offset += filled_data_len;
				m_unsparse_data.chunk_remain_data_size -= filled_data_len;
			}

			set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			break;
		}
	case UNSPARSE_WAIT_CHUNK_CRC:
		{
			filled_seed = *(uint32*)buf;
			buf += sizeof(uint32);
			size -= sizeof(uint32);
			m_unsparse_data.chunk_remain_data_size = 0;
			set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			break;
		}
	case UNSPARSE_WAIT_CHUNK_DATA:
		{
			if (size >= m_unsparse_data.chunk_remain_data_size)
			{
				if (emmc_write_wp(status->partition->part_id, status->partition->base_addr+m_unsparse_data.image_address_offset , buf,  m_unsparse_data.chunk_remain_data_size) != m_unsparse_data.chunk_remain_data_size)
				{
					status->handle_status = STATUS_EMMC_ERR;
				}
				//status->handle_status = storage_interface.write(status->image_base_addr+m_unsparse_data.image_address_offset, buf,  m_unsparse_data.chunk_remain_data_size, status->arg);
				if (status->handle_status  != STATUS_OK)
				{
					pal_log_err("[UNSPARSE] S_STORAGE_WRITE_FAILED:%d, status=%d, size=%d\n",__LINE__, status->handle_status, status->byte_to_process);
					return;
				}

				buf += m_unsparse_data.chunk_remain_data_size;
				size -= m_unsparse_data.chunk_remain_data_size;
				m_unsparse_data.image_address_offset += m_unsparse_data.chunk_remain_data_size;
				m_unsparse_data.chunk_remain_data_size = 0;
				set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_HEADER, size, buf);
			}
			else
			{   //big trunk, so it need more than 1 package.
				sizeOfX = size;
				if(size &  (STORAGE_BLOCK_SIZE-1)) //not 512 aligned.
				{
					if(size < STORAGE_BLOCK_SIZE) //last fragment in a package. this package must have successive package that contain the identical trunk.
					{
						set_unsparse_status(status, STATUS_SPARSE_INCOMPLETE, UNSPARSE_WAIT_CHUNK_DATA, size, buf);
						break;
					}
					else
					{
						size &= ~(STORAGE_BLOCK_SIZE-1);
					}
				}


				if (emmc_write_wp(status->partition->part_id, status->partition->base_addr+m_unsparse_data.image_address_offset , buf,  size) != size)
				{
					status->handle_status = STATUS_EMMC_ERR;
				}
				// status->handle_status = storage_interface.write(status->image_base_addr+m_unsparse_data.image_address_offset, buf,  size, status->arg);

				if (status->handle_status  != STATUS_OK)
				{
					pal_log_err( "[UNSPARSE] S_STORAGE_WRITE_FAILED:%d, status=%d\n",__LINE__, status->handle_status);
					return;
				}

				m_unsparse_data.image_address_offset += size;
				m_unsparse_data.chunk_remain_data_size -= size;
				buf += size;
				size = sizeOfX & (STORAGE_BLOCK_SIZE-1);   // size = 0 org
				set_unsparse_status(status, STATUS_OK, UNSPARSE_WAIT_CHUNK_DATA, size, buf);
			}
			break;
		}
	default:
		pal_log_info("sparse do nothing.\n");
		break;
	}

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
	size = (uint64)sparse_header->blk_sz * sparse_header->total_blks;

	return size;
}

inline bool support_sparse_image(void)
{
	return true;
}

#endif

