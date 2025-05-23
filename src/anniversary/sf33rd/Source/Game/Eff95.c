#include "sf33rd/Source/Game/Eff95.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff95", eff95_data_tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff95", effect_95_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff95", effect_95_init);
#else
s32 effect_95_init(s16 vital_new) {
    not_implemented(__func__);
}
#endif
