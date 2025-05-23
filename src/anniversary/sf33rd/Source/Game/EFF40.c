#include "sf33rd/Source/Game/EFF40.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF40", EFF40_Jmp_Tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF40", Pos_Data_40);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF40", effect_40_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF40", EFF40_EXIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF40", EFF40_BACK);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF40", EFF40_ARROW);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF40", effect_40_init);
#else
s32 effect_40_init(s16 id, s16 type, s16 char_ix, s16 sync_bg, s16 master_player, s16 master_priority) {
    not_implemented(__func__);
}
#endif
