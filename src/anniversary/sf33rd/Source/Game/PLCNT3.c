#include "sf33rd/Source/Game/PLCNT3.h"
#include "common.h"
#include "sf33rd/Source/Game/PLCNT2.h"

void plcnt_b2_move();
void plcnt_b2_die();

void (*const player_bonus2_process[3])() = { plcnt_b_init, plcnt_b2_move, plcnt_b2_die };

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT3", Player_control_bonus2);
#else
s32 Player_control_bonus2() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT3", plcnt_b2_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT3", plcnt_b2_die);
