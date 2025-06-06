#ifndef EFL_SIF_RPC_H
#define EFL_SIF_RPC_H

#include "structs.h"
#include "types.h"

#include <sifrpc.h>

extern struct _sif_client_data ScdComm; // size: 0x28, address: 0x57B220
extern struct _sif_client_data ScdStat; // size: 0x28, address: 0x57B1F0
extern struct _sif_client_data ScdThMon; // size: 0x28, address: 0x57B1C0
extern struct _sif_client_data * pScd; // size: 0x4, address: 0x57B1B0
extern void * pSendBuf; // size: 0x4, address: 0x57B1AC
extern void * pRecvBuf; // size: 0x4, address: 0x57B1A8
extern u32 SendBufSize; // size: 0x4, address: 0x57B1A4
extern u32 RecvBufSize; // size: 0x4, address: 0x57B1A0
extern CSE_RPCBUFF RpcBuff; // size: 0xC0, address: 0x6EA140
#if defined(TARGET_PS2)
extern u8 ThMonSendBuf[16] __attribute__((section(".bss"))); // size: 0x10, address: 0x6EA100
#else
extern u8 ThMonSendBuf[16];
#endif
extern u8 ThMonRecvBuf[1024]; // size: 0x400, address: 0x6E9D00

s32 flSifRpcInit();
void * flSifRpcSend(u32 CmdType, void * pData, u32 DataSize);

#endif
