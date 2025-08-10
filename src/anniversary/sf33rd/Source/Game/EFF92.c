#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF92", effect_92_move);
#else
void effect_92_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF92", effect_92_init);
#else
s32 effect_92_init(s16 PL_id, s16 win_number) {
    not_implemented(__func__);
}
#endif

const u8 Rewrite_Mark_Data[13][2] = { { -1, 2 }, { 0, 2 },  { -1, 2 }, { 0, 2 },  { -1, 2 }, { 0, 2 },  { -1, 2 },
                                      { 0, 2 },  { -1, 2 }, { 0, 2 },  { -1, 2 }, { 0, 3 },  { -1, 99 } };
