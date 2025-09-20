#include "sf33rd/Source/Game/Eff76.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFF57.h"
#include "sf33rd/Source/Game/EFFA6.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/Grade.h"
#include "sf33rd/Source/Game/RANKING.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/Sel_Data.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "sf33rd/Source/Game/char_table.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/texcash.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_76_move(WORK_Other *ewk);
void EFF76_WAIT(WORK_Other *ewk);
void EFF76_WAIT_BREAK_INTO(WORK_Other *ewk);
void EFF76_SLIDE_IN(WORK_Other *ewk);
void EFF76_SLIDE_OUT(WORK_Other * /* unused */);
void EFF76_SUDDENLY(WORK_Other *ewk);
void EFF76_BEFORE(WORK_Other *ewk);
void EFF76_SHIFT(WORK_Other *ewk);

void (*const EFF76_Jmp_Tbl[8])() = { EFF76_WAIT, EFF76_SLIDE_IN, EFF76_SLIDE_OUT,       EFF76_SUDDENLY,
                                     EFF57_KILL, EFF76_SHIFT,    EFF76_WAIT_BREAK_INTO, EFF76_BEFORE };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", effect_76_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_WAIT_BREAK_INTO);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_SLIDE_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_BEFORE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_SHIFT);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", effect_76_init);
#else
s32 effect_76_init(s16 dir_old) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Pos_76);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Char_76);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Check_Range_Out);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Color_76);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Color_L1);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", chkNameAkuma);
#else
s32 chkNameAkuma(s32 plnum, s32 rnum) {
    not_implemented(__func__);
}
#endif
