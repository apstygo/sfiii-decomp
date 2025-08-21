#include "sf33rd/Source/Game/eff91.h"
#include "common.h"

const s16 EFF91_Pos_Data[2][3][2] = { { { -88, 95 }, { -94, 71 }, { -88, 47 } },
                                      { { 104, 95 }, { 98, 71 }, { 104, 47 } } };

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff91", effect_91_move);
#else
void effect_91_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff91", effect_91_init);
#else
s32 effect_91_init(s16 master_id, s16 type, s16 target_bg, s16 char_ix, s16 char_ix2, s16 master_player) {
    not_implemented(__func__);
}
#endif
