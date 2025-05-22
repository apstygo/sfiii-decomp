#include "sf33rd/Source/Game/PLCNT3.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT3", player_bonus2_process);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT3", Player_control_bonus2);
#else
s32 Player_control_bonus2() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT3", plcnt_b2_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT3", plcnt_b2_die);
