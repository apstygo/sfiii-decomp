#ifndef FLPS2DEBUG_H
#define FLPS2DEBUG_H

#include "structs.h"
#include "types.h"

f64 flGetSystemTime();
void flPS2SystemError(s32 error_level, s8 *format, ...);
s32 flSetDebugMode(u32 flag);
void flPS2DebugInit();
void flPS2DebugStrDisp();
s32 flPrintL(s32 posi_x, s32 posi_y, const s8 *format, ...);
s32 flPrintColor(u32 col);
void flPS2DispSystemInfo(s32 x, s32 y);

#endif // FLPS2DEBUG_H
