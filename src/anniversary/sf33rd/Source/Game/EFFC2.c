#include "sf33rd/Source/Game/EFFC2.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", effect_C2_move);
#else
void effect_C2_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", effC2_main_process_first);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", effc2_parts_work_chain_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", effC2_main_process_second);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", c2_last_char_and_mvxy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", c2_last_dir_select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", setup_demojump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", check_effc2_p2_rno);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", copy_rno);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", player_hosei_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", set_c2_quake);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", get_bs2_parts_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", setup_prio_ix);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", set_parts_priority);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", setup_vital_bonus2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", c3_new_damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", c3_hit_disp_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", bs2_sync_bomb);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", bs2_get_parts_break);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", setup_parts_break);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", setup_parts_break2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", bs2_status_disp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", check_parts_break_level);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", bs2_score_add_next);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", set_1st_Bonus_Game_result);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", set_bs2_floor);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", get_shizumi_guai);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", send_to_shizumi_guai);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", effect_C2_init);
#else
s32 effect_C2_init(WORK *wk, u8 data) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", bs2_data_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", dm_copy_to_master);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", ix_exchange);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", sel_dm_quake);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", pbl_select);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", pbs_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", shizumi_guai);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", shindou_guai);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", c2_last_bomb);
