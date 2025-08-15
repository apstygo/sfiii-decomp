#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITEFPL", effect_at_vs_player_dm);
#else
void effect_at_vs_player_dm(s16 ix2, s16 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITEFPL", setup_dm_rl_pldm);
