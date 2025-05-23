#include "sf33rd/Source/Game/Eff51.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff51", effect_51_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff51", effect_51_init);
#else
s32 effect_51_init(s16 letter_type, s16 cursor_index, s16 master_player) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff51", Setup_Letter_51);
