#ifndef MEMFOUND_H
#define MEMFOUND_H

#include "sf33rd/AcrSDK/common/memmgr.h"
#include "structs.h"
#include "types.h"

extern MEM_BLOCK sysmemblock[4096]; // size: 0x10000, address: 0x584C80

void mflInit(void *mem_ptr, s32 memsize, s32 memalign); // Range: 0x115FB0 -> 0x115FFC
u32 mflGetSpace();                                      // Range: 0x116000 -> 0x116024
u32 mflGetFreeSpace();                                  // Range: 0x116030 -> 0x116054
u32 mflRegisterS(s32 len);                              // Range: 0x116060 -> 0x11608C
u32 mflRegister(s32 len);                               // Range: 0x116090 -> 0x1160BC
void *mflTemporaryUse(s32 len);                         // Range: 0x1160C0 -> 0x1160EC
void *mflRetrieve(u32 handle);                          // Range: 0x1160F0 -> 0x11611C
s32 mflRelease(u32 handle);                             // Range: 0x116120 -> 0x11614C
void *mflCompact();                                     // Range: 0x116150 -> 0x116174

#endif
