#include "sf33rd/Source/Common/MemMan.h"
#include "common.h"

u32 mmInitialNumber;

void mmSystemInitialize() {
    mmInitialNumber = 0;
}

void mmHeapInitialize(_MEMMAN_OBJ *mmobj, u8 *adrs, s32 size, s32 unit, s8 *format) {
    mmobj->oriHead = adrs;
    mmobj->oriSize = size;
    mmobj->ownUnit = unit;
    mmobj->ownNumber = mmInitialNumber++;
    mmobj->memHead = (u8 *)mmRoundUp(mmobj->ownUnit, (u32)adrs);
    mmobj->memSize = mmRoundOff(mmobj->ownUnit, (u32)adrs + size) - (u32)mmobj->memHead;
    mmobj->remainder = mmobj->memSize - (mmobj->ownUnit * 2);
    mmobj->remainderMin = mmobj->remainder;
    mmobj->cell_1st = (struct _MEMMAN_CELL *)mmobj->memHead;
    mmobj->cell_fin = (struct _MEMMAN_CELL *)((u32)&mmobj->memHead[mmobj->memSize] - mmobj->ownUnit);
    mmobj->cell_1st->prev = NULL;
    mmobj->cell_1st->next = mmobj->cell_fin;
    mmobj->cell_1st->size = mmobj->ownUnit;
    mmobj->cell_fin->prev = mmobj->cell_1st;
    mmobj->cell_fin->next = NULL;
    mmobj->cell_fin->size = mmobj->ownUnit;
}

u32 mmRoundUp(s32 unit, u32 num) {
    return ~(unit - 1) & (num + unit - 1);
}

u32 mmRoundOff(s32 unit, u32 num) {
    return num & ~(unit - 1);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmDebWriteTag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmGetRemainder);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmGetRemainderMin);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmAlloc);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmAllocSub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/MemMan", mmFree);
