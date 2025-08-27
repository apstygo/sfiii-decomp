#include "sf33rd/Source/Game/EFFC9.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC9", effect_C9_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC9", effect_C9_init);
#else
s32 effect_C9_init(PLW * /* unused */, u8 data) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC9", setup_EJG_index);
#else
void setup_EJG_index() {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC9", efy_data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC9", sel_ejg_ix_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC9", ag_cc_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC9", app_pos_hosei);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC9", judge_gals_kage_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC9", ag_sel_table);
