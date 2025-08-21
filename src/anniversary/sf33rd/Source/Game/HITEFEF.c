#include "sf33rd/Source/Game/HITEFEF.h"
#include "common.h"
#include "sf33rd/Source/Game/EFF02.h"
#include "sf33rd/Source/Game/HITCHECK.h"
#include "sf33rd/Source/Game/Pow_Pow.h"

void effect_at_vs_effect_dm(s16 ix2, s16 ix) {
#if defined(TARGET_PS2)
    void cal_hit_mark_pos(WORK * as, WORK * ds, s32 ix2, s32 ix);
    s32 effect_02_init(WORK * wk, s32 dmgp, s32 mkst, s32 dmrl);
#endif

    WORK *as = q_hit_push[ix2];
    WORK *ds = q_hit_push[ix];

    ds->dm_rl = as->rl_flag;
    as->dm_rl = ds->rl_flag;
    cal_hit_mark_pos(as, ds, ix2, ix);

    if (ds->att.dipsw & 2) {
        if (as->att.dipsw & 2) {
            ds->dm_vital = 128;
            as->dm_vital = 128;
        } else {
            ds->dm_vital = 128;
            as->dm_vital = 128;

            if (as->shell_vs_refrect == 0) {
                ((WORK_Other *)as)->dm_refrect = 1;
                ((WORK_Other *)as)->refrected = 1;
                as->att_hit_ok = 1;
            }
        }
    } else if (ds->id == 13) {
        switch (as->work_id) {
        case 4:
            ds->dm_vital = as->vital_new;
            as->dm_vital = ds->vital_new;

            if (ds->dm_vital > ds->vital_new) {
                ds->dm_vital = ds->vital_new;
            }

            if (as->dm_vital > as->vital_new) {
                as->dm_vital = as->vital_new;
            }

            break;

        default:
            break;
        }
    } else if (ds->id == 122 || ds->id == 123) {
        cal_damage_vitality((PLW *)as, (PLW *)ds);
        as->dm_vital = 256;
    } else {
        ds->dm_vital = 256;
    }

    if (ds->xyz[1].disp.pos > 0) {
        as->hf.hit.effect = 2;
    } else {
        as->hf.hit.effect = 1;
    }

    ds->routine_no[1] = 1;
    ds->routine_no[2] = 0;
    as->hit_stop = ds->hit_stop = 6;
    ds->dm_dir = as->dir_atthit;
    ds->dm_kind_of_waza = as->kind_of_waza;

    if (ds->id == 122 || ds->id == 123) {
        effect_02_init(as, 2, 1, ds->dm_rl);
    }

    hit_pattern_extdat_check(as);
}
