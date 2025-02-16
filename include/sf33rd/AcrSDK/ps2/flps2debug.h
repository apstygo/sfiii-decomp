#ifndef FLPS2DEBUG_H
#define FLPS2DEBUG_H

#include "types.h"

extern s32 flDebugSysMem[4096];    // size: 0x4000, address: 0x6C0DD0
extern u32 flDebugSysMemMotion;    // size: 0x4, address: 0x57AB10
extern u32 flDebugSysMemClay;      // size: 0x4, address: 0x57AB14
extern u32 flDebugSysMemTexture;   // size: 0x4, address: 0x57AB18
extern u32 flDebugSysMemEtc;       // size: 0x4, address: 0x57AB1C
extern u32 flDebugSysMemHandleNum; // size: 0x4, address: 0x57AB20

void flPS2SystemError(s32 error_level, s8 *format);
s32 flSetDebugMode(u32 flag);
void flPS2DebugInit();
void flPS2DebugStrDisp();
s32 flPrintL(s32 posi_x, s32 posi_y, s8 *format, ...);
s32 flPrintColor(u32 col);
void flPS2DispSystemInfo(s32 x, s32 y);

#endif // FLPS2DEBUG_H
