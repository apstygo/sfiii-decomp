#include "sf33rd/Source/Game/Pow_Pow.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Pow_Pow", cal_damage_vitality);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Pow_Pow", cal_damage_vitality_eff);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Pow_Pow", Additinal_Score_DM);
#else
void Additinal_Score_DM(WORK_Other *wk, u16 ix) {
    not_implemented(__func__);
}
#endif
