#include "sf33rd/Source/Game/Eff93.h"
#include "common.h"
#include "sf33rd/Source/Game/bg.h"

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

void Bg_Family_Set_Ex(s16 xx) {
#if defined(TARGET_PS2)
    void Scrn_Move_Set(s32 bgnm, s32 x, s32 y);
    void Family_Set_W(s32 fmnm, s32 x, s32 y);
#endif

    s16 pos_work_x;
    s16 pos_work_y;

    bg_w.bgw[xx].position_x = bg_w.bgw[xx].xy[0].disp.pos & 0xFFFF;
    pos_work_x = bg_w.bgw[xx].position_x;
    bg_w.bgw[xx].position_y = bg_w.bgw[xx].xy[1].disp.pos & 0xFFFF;
    pos_work_y = bg_w.bgw[xx].position_y;
    Scrn_Move_Set(xx, pos_work_x, pos_work_y);
    pos_work_x = -pos_work_x & 0xFFFF;
    pos_work_y = (0x300 - (pos_work_y & 0xFFFF)) & 0xFFFF;
    Family_Set_W(xx + 1, pos_work_x, pos_work_y);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", effect_93_init);
#else
s32 effect_93_init(s8 Move_Type, s16 Time) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff93", Eff93_Jmp_Tbl);
