#include "sf33rd/Source/Game/effl8.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effl8", effect_L8_move);
#else
void effect_L8_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effl8", check_new_color_data_L8);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effl8", get_new_color_data_L8);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effl8", save_old_color_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effl8", load_old_color_data);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effl8", effect_L8_init);
#else
s32 effect_L8_init(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effl8", pl17_0_00);
