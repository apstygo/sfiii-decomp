#include "sf33rd/Source/Game/EFF15.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF15", effect_15_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF15", eff15_kemuri);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF15", eff15_koishi);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF15", effect_15_init);
#else
s32 effect_15_init(WORK* wk, u8 data) {
    not_implemented(__func__);
}
#endif
