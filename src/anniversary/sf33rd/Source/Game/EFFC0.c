#include "sf33rd/Source/Game/EFFC0.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC0", effect_C0_move);
#else
void effect_C0_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC0", effect_C0_init);
#else
s32 effect_C0_init(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC0", hok_table_ef);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC0", plhos_data);
