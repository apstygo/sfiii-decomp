#include "sf33rd/Source/Game/EFF75.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFF57.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/char_table.h"
#include "sf33rd/Source/Game/texcash.h"
#include "sf33rd/Source/Game/workuser.h"

void EFF75_WAIT(WORK_Other *ewk);
void EFF75_SLIDE_IN(WORK_Other * /* unused */);
void EFF75_CHAR_CHANGE(WORK_Other *ewk);
void EFF75_SUDDENLY(WORK_Other *ewk);

void (*const EFF75_Jmp_Tbl[5])() = { EFF75_WAIT, EFF75_SLIDE_IN, EFF75_CHAR_CHANGE, EFF75_SUDDENLY, EFF57_KILL };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", effect_75_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", EFF75_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", EFF75_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", EFF75_CHAR_CHANGE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", EFF75_SUDDENLY);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", effect_75_init);
#else
s32 effect_75_init(s16 dir_old, s16 ID, s16 Target_BG) {
    not_implemented(__func__);
}
#endif
