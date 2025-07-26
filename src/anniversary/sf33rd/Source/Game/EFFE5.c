#include "sf33rd/Source/Game/EFFE5.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", effect_E5_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", setup_illusion_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", check_new_after_image);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", effect_E5_init);
#else
s32 effect_E5_init(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", effect_e7_e8_init_union);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", get_attdata_of_illusion);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", setup_after_images);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", erase_after_images);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", after_image_data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", after_image_color);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE5", illusion_setup_table);
