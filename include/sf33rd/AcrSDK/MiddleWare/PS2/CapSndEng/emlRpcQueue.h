#ifndef EFL_RPC_QUEUE_H
#define EFL_RPC_QUEUE_H

#include "structs.h"
#include "types.h"

#define RPCQUEUE_DATA_MAX 64
#define RPCQUEUE_MAX 32

typedef struct {
    // total size: 0x48
    u32 Type;                   // offset 0x0, size 0x4
    u8 Data[RPCQUEUE_DATA_MAX]; // offset 0x4, size 0x40
    u32 Size;                   // offset 0x44, size 0x4
} CSE_RPCQUEUE;

extern CSE_RPCQUEUE RpcQueue[RPCQUEUE_MAX]; // size: 0x900, address: 0x6EA2C0
extern u32 ixTop;                           // size: 0x4, address: 0x57B2B4
extern u32 ixEnd;                           // size: 0x4, address: 0x57B2B0
extern u32 num;                             // size: 0x4, address: 0x57B2AC
extern u32 numVTransReq;                    // size: 0x4, address: 0x57B2A8

s32 mlRpcQueueInit();
s32 mlRpcQueueSetData(u32 type, void *data, u32 size);
u32 mlRpcQueueSend();
u32 mlRpcQueueGetNumVtransReq();

#endif
