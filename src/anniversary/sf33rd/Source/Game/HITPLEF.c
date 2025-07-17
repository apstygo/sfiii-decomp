#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITPLEF", player_at_vs_effect_dm);
#else
void player_at_vs_effect_dm(s16 ix2, s16 ix) {
    not_implemented(__func__);
}
#endif
