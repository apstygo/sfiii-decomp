#include "sf33rd/Source/Game/EFFC5.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC5", effect_C5_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC5", effect_C5_init);
#else
s32 effect_C5_init(PLW *oya, s16 reverse_f) {
    not_implemented(__func__);
}
#endif
