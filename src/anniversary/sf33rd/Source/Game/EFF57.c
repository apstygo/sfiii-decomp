#include "sf33rd/Source/Game/EFF57.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF57", EFF57_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF57", effect_57_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF57", EFF57_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF57", EFF57_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF57", EFF57_CHAR_CHANGE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF57", EFF57_WALL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF57", EFF57_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF57", EFF57_KILL);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF57", effect_57_init);
#else
s32 effect_57_init(s16 dir_old, s16 ID, s16 Target_BG, s16 char_ix, s16 option) {
    not_implemented(__func__);
}
#endif
