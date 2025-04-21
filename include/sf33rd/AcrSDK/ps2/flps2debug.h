#ifndef FLPS2DEBUG_H
#define FLPS2DEBUG_H

#include "structs.h"
#include "types.h"

#define DEBUG_SYS_MEM_SIZE (4096)

extern s32 flDebugSysMem[DEBUG_SYS_MEM_SIZE]; // size: 0x4000, address: 0x6C0DD0
extern u32 flDebugSysMemMotion;               // size: 0x4, address: 0x57AB10
extern u32 flDebugSysMemClay;                 // size: 0x4, address: 0x57AB14
extern u32 flDebugSysMemTexture;              // size: 0x4, address: 0x57AB18
extern u32 flDebugSysMemEtc;                  // size: 0x4, address: 0x57AB1C
extern u32 flDebugSysMemHandleNum;            // size: 0x4, address: 0x57AB20
extern u32 flDebugFlag;                       // size: 0x4, address: 0x57AE8C
extern u32 flDebugStrCtr;                     // size: 0x4, address: 0x57AB60
extern u32 flDebugStrCol;                     // size: 0x4, address: 0x57AB64
extern s32 flDebugStrX;                       // size: 0x4, address: 0x57AB68
extern s32 flDebugStrY;                       // size: 0x4, address: 0x57AB6C
extern u32 flDebugStrHan;                     // size: 0x4, address: 0x57AB70
extern u32 flhDebugStr;                       // size: 0x4, address: 0x57AB74

void flPS2SystemError(s32 error_level, s8 *format, ...);
s32 flSetDebugMode(u32 flag);
void flPS2DebugInit();
void flPS2DebugStrDisp();
s32 flPrintL(s32 posi_x, s32 posi_y, s8 *format, ...);
s32 flPrintColor(u32 col);
void flPS2DispSystemInfo(s32 x, s32 y);

#endif // FLPS2DEBUG_H
