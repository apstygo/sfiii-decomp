#ifndef KNJSUB_H
#define KNJSUB_H

#include "types.h"

void KnjFlush();
void KnjInit(u32 type, u32 adrs, u32 disp_max, u32 top_dbp);
void KnjLocate(s32 x, s32 y);
void KnjPuts(const s8 *str);
void KnjSetRgb(u32 color);
void KnjSetColor(u32 color);
void KnjSetAlpha(u32 alpha);
void KnjSetSize(s32 dispw, s32 disph);
void KnjPrintf(const s8 *fmt, ...);
s32 KnjStrLen(const s8 *str);
void KnjFinish();

#endif
