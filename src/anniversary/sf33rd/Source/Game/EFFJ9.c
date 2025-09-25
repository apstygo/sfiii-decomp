#include "sf33rd/Source/Game/EFFJ9.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARID.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFF00.h"
#include "sf33rd/Source/Game/EFFC2.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/aboutspr.h"

void effJ9_trans(WORK *wk);
s16 get_c2_quake(WORK *c2wk);

const s16 c2quake_table[19] = { 0, 3, 3, 2, 2, 1, 1, 1, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, 0 };

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ9", effect_J9_move);
#else
void effect_J9_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ9", effJ9_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ9", get_c2_quake);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ9", effect_J9_init);
#else
s32 effect_J9_init(WORK_Other *wk, u8 data) {
    not_implemented(__func__);
}
#endif
