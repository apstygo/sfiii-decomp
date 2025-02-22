#ifndef MEMMAN_H
#define MEMMAN_H

#include "structs.h"
#include "types.h"

void mmSystemInitialize();
void mmHeapInitialize(_MEMMAN_OBJ *mmobj, u8 *adrs, s32 size, s32 unit, s8 *format);
u32 mmRoundUp(s32 unit, u32 num);
u32 mmRoundOff(s32 unit, u32 num);
void mmDebWriteTag(s8 * /* unused */);
s32 mmGetRemainder(_MEMMAN_OBJ *mmobj);
s32 mmGetRemainderMin(_MEMMAN_OBJ *mmobj);
u8 *mmAlloc(_MEMMAN_OBJ *mmobj, s32 size, s32 flag);
struct _MEMMAN_CELL *mmAllocSub(_MEMMAN_OBJ *mmobj, s32 size, s32 flag);
void mmFree(_MEMMAN_OBJ *mmobj, u8 *adrs);

#endif
