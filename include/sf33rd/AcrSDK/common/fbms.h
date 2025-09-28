#ifndef FBMS_H
#define FBMS_H

#include "structs.h"
#include "types.h"

s32 fmsCalcSpace(FL_FMS* lp);                                               // Range: 0x115D60 -> 0x115D88
s32 fmsInitialize(FL_FMS* lp, void* memory_ptr, s32 memsize, s32 memalign); // Range: 0x115D90 -> 0x115E80
void* fmsAllocMemory(FL_FMS* lp, s32 bytes, s32 heapnum);                   // Range: 0x115E80 -> 0x115F58
s32 fmsGetFrame(FL_FMS* lp, s32 heapnum, FMS_FRAME* frame);                 // Range: 0x115F60 -> 0x115FA8

#endif
