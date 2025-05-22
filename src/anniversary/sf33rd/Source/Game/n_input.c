#include "sf33rd/Source/Game/n_input.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", slang_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", name_code_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", ne_color_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", rank_stage_tbl);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", Name_Input);
#else
s16 Name_Input(s16 pl_id) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", Name_Scs_Input_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", Name_Scs_Input_comm);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", Name_Input_wait);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", Name_Scs_Input_end);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", Name_Scs_Finish);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", Name_Input_sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", auto_n_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", name_slang_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", define_name_input);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", ranking_state_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", ranking_name_entry);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", name_work_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", rank_display_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", Scs_char_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", Scs_move_sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", current_sc_move2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", start_cut_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", all_name_display);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/n_input", all_flash_display);
