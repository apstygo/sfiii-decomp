#include "sf33rd/Source/Game/Eff43.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff43", effect_43_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff43", effect_43_init);
#else
s32 effect_43_init(s16 Time, s16 Target_BG) {
    not_implemented(__func__);
}
#endif
