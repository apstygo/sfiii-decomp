#include "sf33rd/Source/Game/eff97.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff97", effect_97_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff97", effect_97_init);
#else
s32 effect_97_init(PLW* oya) {
    not_implemented(__func__);
}
#endif
