#include "sf33rd/Source/Game/EFFK5.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", effect_K5_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", K5_main_process);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", get_okuri_time);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", K5_decode_new_hit_index);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", decode_mvsw);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", get_table_adrs_K5);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", init_K5_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", get_master_table_address);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", K5_init_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", K5_init_data_copy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", K5_init_data_copy2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", get_cal_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", k5_add_sub);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", effect_K5_init);
#else
s32 effect_K5_init(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", lookup_index);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK5", k5_exc_check);
