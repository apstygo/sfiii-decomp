#include "sf33rd/Source/Common/MemMan.h"
#include "common.h"

u32 mmInitialNumber;

void mmSystemInitialize() {
    mmInitialNumber = 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmHeapInitialize);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmRoundUp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmRoundOff);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmDebWriteTag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmGetRemainder);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmGetRemainderMin);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmAlloc);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmAllocSub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmFree);
