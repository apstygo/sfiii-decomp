#include "sf33rd/Source/Game/HITEFPL.h"
#include "common.h"
#include "sf33rd/Source/Game/HITCHECK.h"
#include "sf33rd/Source/Game/SysDir.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITEFPL", effect_at_vs_player_dm);
#else
void effect_at_vs_player_dm(s16 ix2, s16 ix) {
    not_implemented(__func__);
}
#endif

void setup_dm_rl_pldm(WORK *as, WORK *ds) {
    s16 pw;

    ds->dm_rl = as->rl_flag;

    if (ds->xyz[1].disp.pos <= 0) {
        return;
    }

    if (!(as->att.dipsw & 2)) {
        return;
    }

    pw = ds->xyz[0].disp.pos - as->xyz[0].disp.pos;

    if (pw) {
        if (pw > 0) {
            ds->dm_rl = 1;
            return;
        }

        ds->dm_rl = 0;
        return;
    }

    ds->dm_rl = as->rl_flag;
}
