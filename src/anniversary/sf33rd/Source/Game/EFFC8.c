#include "sf33rd/Source/Game/EFFC8.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC8", effc8_data_tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC8", effect_C8_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC8", effect_C8_init);
#else
s32 effect_C8_init(PLW *wk) {
    not_implemented(__func__);
}
#endif
