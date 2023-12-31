#ifndef _DDP_RDMA_API_H_
#define _DDP_RDMA_API_H_
#include "ddp_info.h"

#define RDMA_INSTANCES  2
#define RDMA_MAX_WIDTH  4095
#define RDMA_MAX_HEIGHT 4095

enum RDMA_OUTPUT_FORMAT {
    RDMA_OUTPUT_FORMAT_ARGB   = 0,
    RDMA_OUTPUT_FORMAT_YUV444 = 1,
};

enum RDMA_MODE {
    RDMA_MODE_DIRECT_LINK = 0,
    RDMA_MODE_MEMORY      = 1,
};

// start module
int RDMAStart(DISP_MODULE_ENUM module,void * handle);

// stop module
int RDMAStop(DISP_MODULE_ENUM module,void * handle);

// reset module
int RDMAReset(DISP_MODULE_ENUM module,void * handle);

// configu module
int RDMAConfig(DISP_MODULE_ENUM module,
                    enum RDMA_MODE mode,
                    unsigned address, 
                    DpColorFormat inFormat,
                    unsigned pitch,
                    unsigned width, 
                    unsigned height, 
                    unsigned ufoe_enable,
                    void * handle); // ourput setting

int RDMAWait(DISP_MODULE_ENUM module,void * handle);

void RDMASetTargetLine(DISP_MODULE_ENUM module, unsigned int line,void * handle);

void RDMADump(DISP_MODULE_ENUM module);

#endif
