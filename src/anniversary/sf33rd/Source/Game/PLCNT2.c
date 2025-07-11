#include "sf33rd/Source/Game/PLCNT2.h"
#include "common.h"

const s16 bsmr_range_table[3][2][2] = { { { 0x00c0, 0x00c0 }, { 0x00c0, 0x00c0 } },
                                        { { 0x0040, 0x00c0 }, { 0x00e0, 0xff78 } },
                                        { { 0xff90, 0x00e0 }, { 0x00d8, 0x0028 } } };

void plcnt_b_move();
void plcnt_b_die();

void (*const player_bonus_process[3])() = { plcnt_b_init, plcnt_b_move, plcnt_b_die };

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
