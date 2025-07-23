#include "sf33rd/Source/Game/EFFK7.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK7", effect_K7_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK7", K7_move_type_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK7", K7_mt0_rebirth_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK7", K7_muriyari_metamor_rebirth);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK7", effect_K7_init);
#else
s32 effect_K7_init(PLW *wk) {
    not_implemented(__func__);
}
#endif
