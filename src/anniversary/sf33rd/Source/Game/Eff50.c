#include "sf33rd/Source/Game/Eff50.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff50", effect_50_move);
#else
void effect_50_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff50", effect_50_init);
#else
s32 effect_50_init(s16 PL_id, s16 Direction, s16 dm_vital) {
    not_implemented(__func__);
}
#endif
