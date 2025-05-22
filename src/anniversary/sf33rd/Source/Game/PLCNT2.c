#include "sf33rd/Source/Game/PLCNT2.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", bsmr_range_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", player_bonus_process);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", Player_control_bonus);
#else
s32 Player_control_bonus() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", plcnt_b_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", plcnt_b_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", plcnt_b_die);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", footwork_check_bns);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", setup_bs_scrrrl_bs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", setup_bs_scrrrl_bs2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", move_player_work_bonus);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", move_P1_move_P2_bonus);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", move_P2_move_P1_bonus);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT2", check_damage_hosei_bonus);
