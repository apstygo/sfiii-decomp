#include "sf33rd/Source/Game/EFFC4.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC4", effect_C4_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC4", effect_C4_init);
#else
s32 effect_C4_init(s16 id, s16 letter_type, s16 cursor_index, s16 master_player) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC4", Setup_Letter_C4);
