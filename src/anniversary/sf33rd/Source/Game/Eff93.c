#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", effect_93_move);
#else
void effect_93_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", Eff93_SLIDE_L);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", Eff93_SLIDE_R);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", Eff93_SLIDE_L_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", Eff93_SLIDE_R_OUT);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", Bg_Family_Set_Ex);
#else
void Bg_Family_Set_Ex(s16 xx) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", effect_93_init);
#else
s32 effect_93_init(s8 Move_Type, s16 Time) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", Eff93_Jmp_Tbl);
