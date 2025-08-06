#include "sf33rd/Source/Game/EFF69.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF69", effect_69_move);
#else
void effect_69_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF69", EFF69_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF69", EFF69_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF69", EFF69_SLIDE_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF69", EFF69_SUDDENLY);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF69", effect_69_init);
#else
s32 effect_69_init(s16 dir_old) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF69", Setup_Clear_OBJ);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF69", EFF69_Jmp_Tbl);
