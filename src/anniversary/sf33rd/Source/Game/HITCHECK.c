#include "sf33rd/Source/Game/HITCHECK.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFF02.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/Grade.h"
#include "sf33rd/Source/Game/HITEFEF.h"
#include "sf33rd/Source/Game/HITEFPL.h"
#include "sf33rd/Source/Game/HITPLEF.h"
#include "sf33rd/Source/Game/HITPLPL.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/PLS01.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/PLS03.h"
#include "sf33rd/Source/Game/PulPul.h"
#include "sf33rd/Source/Game/SysDir.h"
#include "sf33rd/Source/Game/cmb_win.h"
#include "sf33rd/Source/Game/workuser.h"

// bss
HS hs[32];

// sbss
s16 grdb[2][2][2];
s16 grdb2[2][2];
s16 *dmdat_adrs[16];
WORK *q_hit_push[32];
s16 mkm_wk[32];
s16 hpq_in;
s8 ca_check_flag;

void make_red_blocking_time(s16 id, s16 ix, s16 num) {
    switch (ix) {
    case 3:
        grdb[id][0][0] = num - (blok_r_omake[omop_r_block_ix[id]] + 2);
        grdb[id][1][0] = num - (blok_r_omake[omop_r_block_ix[id]] + 3);
        break;

    case 4:
        grdb[id][0][1] = num - (blok_r_omake[omop_r_block_ix[id]] + 2);
        grdb[id][1][1] = num - (blok_r_omake[omop_r_block_ix[id]] + 3);
        break;

    case 5:
        grdb2[id][0] = num - (blok_r_omake[omop_r_block_ix[id]] + 2);
        grdb2[id][1] = num - (blok_r_omake[omop_r_block_ix[id]] + 3);
        break;
    }
}

void hit_check_main_process() {
    aiuchi_flag = 0;

    if (hpq_in > 1) {
        if (ca_check_flag) {
            catch_hit_check();
        }

        attack_hit_check();

        if (set_judge_result()) {
            check_result_extra();
        }
    }

    clear_hit_queue();
}

s16 set_judge_result() {
#if defined(TARGET_PS2)
    void set_caught_status(s32 ix);
    void set_struck_status(s32 ix);
#endif

    s16 i;
    s16 rnum = 0;

    for (i = 0; i < hpq_in; i++) {
        if (hs[i].flag.results & 0x101) {
            rnum = 1;

            if (hs[i].flag.results & 0x100) {
                set_caught_status(i);
            } else {
                set_struck_status(i);
            }
        }
    }

    return rnum;
}

void check_result_extra() {
    WORK_Other *dm1p;
    WORK_Other *dm2p;
    s16 hs1;
    s16 hs2;
    s16 qua;
    s16 p1state;
    s16 p2state;
    s32 assign1;
    s32 assign2;

    assign1 = 0;

    if (plw[0].wu.routine_no[1] == 1 && plw[0].wu.routine_no[3] == 0) {
        assign1 = 1;
    }

    p1state = assign1;

    assign2 = 0;

    if (plw[1].wu.routine_no[1] == 1 && plw[1].wu.routine_no[3] == 0) {
        assign2 = 1;
    }

    p2state = assign2;

    if (p1state & p2state) {
        dm1p = (WORK_Other *)plw[0].wu.dmg_adrs;
        dm2p = (WORK_Other *)plw[1].wu.dmg_adrs;

        switch ((dm1p->wu.work_id == 1) + ((dm2p->wu.work_id == 1) * 2)) {
        case 3:
            aiuchi_flag = 1;

            if ((hs1 = plw[0].wu.dm_stop) < 0) {
                hs1 = -hs1;
            }

            if ((hs2 = plw[1].wu.dm_stop) < 0) {
                hs2 = -hs2;
            }

            qua = plw[0].wu.dm_quake;

            if (qua < plw[1].wu.dm_quake) {
                qua = plw[1].wu.dm_quake;
            }

            if (hs1 > hs2) {
                plw[0].wu.hit_stop = plw[1].wu.hit_stop = hs1;
                plw[0].wu.hit_quake = plw[1].wu.hit_quake = qua;
            } else if (hs2) {
                plw[0].wu.hit_stop = plw[1].wu.hit_stop = hs2;
                plw[0].wu.hit_quake = plw[1].wu.hit_quake = qua;
            }

            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
            plw[0].wu.dm_nodeathattack = plw[1].wu.dm_nodeathattack = 0;
        }

        return;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_caught_status);
#else
void set_caught_status(s16 ix) {
    not_implemented(__func__);
}
#endif

s32 check_pat_status(WORK *wk) {
    if (wk->pat_status >= 14 && wk->pat_status < 31) {
        return 1;
    }

    return 0;
}

s16 check_blocking_flag(PLW *as, PLW *ds) {
    WORK_CP *wp;
    s16 num;

    wp = ds->cp;
    num = (wp->waza_flag[3] + wp->waza_flag[4]) != 0;
    wp = as->cp;
    num += (wp->waza_flag[3] + wp->waza_flag[4] != 0) << 1;
    return num;
}

void setup_catch_atthit(WORK *as, WORK *ds) {
    set_damage_and_piyo((PLW *)as, (PLW *)ds);
    dm_status_copy(as, ds);
    as->hit_stop = ds->dm_stop = 0;
}

void set_catch_hit_mark_pos(WORK *as, WORK *ds) {
    if (as->att.mkh_ix) {
        if (as->rl_flag) {
            as->hit_mark_x = as->xyz[0].disp.pos - hit_mark_hosei_table[as->att.mkh_ix][0];
        } else {
            as->hit_mark_x = as->xyz[0].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][0];
        }

        as->hit_mark_y = as->xyz[1].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][1];
        return;
    }

    cal_hit_mark_position(ds, as, (s16 *)ds->h_cau, (s16 *)as->h_cat);
}

void set_struck_status(s16 ix) {
#if defined(TARGET_PS2)
    void effect_at_vs_effect_dm(s32 ix2, s32 ix);
    void effect_at_vs_player_dm(s32 ix2, s32 ix);
    void player_at_vs_effect_dm(s32 ix2, s32 ix);
    void player_at_vs_player_dm(s32 ix2, s32 ix);
#endif

    WORK *as;
    WORK *ds;
    s16 ix2;

    ix2 = hs[ix].dm_me;

    do {

    } while (ix != hs[ix2].my_hit);

    as = q_hit_push[ix2];
    ds = q_hit_push[ix];
    as->hit_adrs = (u32 *)ds;
    ds->dmg_adrs = (u32 *)as;
    as->hit_work_id = ds->work_id;
    ds->dmg_work_id = as->work_id;

    switch ((as->work_id == 1) + ((ds->work_id == 1) * 2)) {
    case 3:
        player_at_vs_player_dm(ix2, ix);
        break;

    case 2:
        if (hs[ix].flag.results & 0x10 && ix2 == hs[ix].my_hit) {
            as->att_hit_ok = 1;
            break;
        }

        effect_at_vs_player_dm(ix2, ix);
        break;

    case 1:
        player_at_vs_effect_dm(ix2, ix);
        break;

    default:
        effect_at_vs_effect_dm(ix2, ix);
        break;
    }
}

void cal_hit_mark_pos(WORK *as, WORK *ds, s16 ix2, s16 ix) {
    if (as->att.mkh_ix) {
        if (as->rl_flag) {
            as->hit_mark_x = as->xyz[0].disp.pos - hit_mark_hosei_table[as->att.mkh_ix][0];
        } else {
            as->hit_mark_x = as->xyz[0].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][0];
        }

        as->hit_mark_y = as->xyz[1].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][1];
    } else {
        cal_hit_mark_position(ds, as, hs[ix].dh, hs[ix2].ah);
    }

    as->hit_mark_z = as->position_z - 8;
}

const s16 Dsas_dir_table[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", plef_at_vs_player_damage_union);

void dm_reaction_init_set(PLW *as, PLW *ds) {
#if defined(TARGET_PS2)
    s16 change_damage_attribute(PLW * as, u32 atr, u32 ix);
#endif

    ds->wu.routine_no[2] = as->wu.att.reaction;

    if (ds->wu.routine_no[2] == 89 || ds->wu.routine_no[2] == 90) {
        if (ds->running_f == 1 && Dsas_dir_table[as->wu.att.dir]) {
            if (check_work_position(&as->wu, &ds->wu)) {
                if (ds->move_distance > 0) {
                    ds->wu.routine_no[2] = 99;
                }
            } else if (ds->move_distance < 0) {
                ds->wu.routine_no[2] = 99;
            }
        }
    }

    ds->wu.routine_no[2] = change_damage_attribute(as, as->wu.at_attribute, ds->wu.routine_no[2]);
}

void set_guard_status(PLW *as, PLW *ds) {
#if defined(TARGET_PS2)
    s32 effect_02_init(WORK * wk, s32 dmgp, s32 mkst, s32 dmrl);
    void grade_add_guard_success(s32 ix);
#endif

    if (as->wu.att.hs_you == 0 && as->wu.att.hs_me == 0) {
        ds->wu.routine_no[2] = ds->wu.old_rno[2];
    } else {
        ds->wu.routine_no[1] = 1;
        ds->wu.routine_no[3] = 0;

        if (ds->spmv_ng_flag & 0x1000000) {
            effect_02_init(&as->wu, ds->dm_point, 2, ds->wu.dm_rl);
        }

        dm_status_copy(&as->wu, &ds->wu);
        same_dm_stop(&as->wu, &ds->wu);

        if (ds->wu.xyz[1].disp.pos < 0) {
            ds->wu.xyz[1].cal = 0;
        }

        ds->wu.dm_piyo = 0;
        as->wu.cmwk[8]++;
        add_sp_arts_gauge_guard(as);
        ds->wu.dm_arts_point = 0;
        grade_add_guard_success(ds->wu.id);
    }

    hit_pattern_extdat_check(&as->wu);
}

const s8 sel_sp_ch_tbl[12] = { 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 };

const s16 sel_hs_add_tbl[6] = { 4, 3, 2, 1, 0, 0 };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_paring_status);

s32 check_normal_attack(u8 waza) {
    return sel_sp_ch_tbl[waza >> 3] == 0;
}

void hit_pattern_extdat_check(WORK *as) {
    s16 i;

    switch ((as->cg_extdat & 0xC0) + ((as->cg_extdat & 0x3F) != 0)) {
    case 0x80:
        char_move_z(as);
        break;

    case 0x40:
        as->cg_ctr = 1;
        as->cg_extdat = 0;
        break;

    case 0x81:
        setup_comm_abbak(as);
        as->cg_ix = ((as->cg_extdat & 0x3F) - 1) * as->cgd_type - as->cgd_type;
        as->cg_next_ix = 0;
        char_move_z(as);
        break;

    case 0x41:
        as->cg_ctr = 1;
        /* fallthrough */

    case 0x1:
        setup_comm_abbak(as);
        as->cg_ix = ((as->cg_extdat & 0x3F) - 1) * as->cgd_type - as->cgd_type;
        as->cg_next_ix = 0;
        as->cg_extdat = 0;
        break;
    }

    if (as->work_id == 1) {
        if ((((PLW *)as)->spmv_ng_flag2 & 1) && as->cg_cancel & 8 && !(as->kow & 0xF8)) {
            if (as->kow & 6) {
                as->cg_cancel &= 0xF7;
                as->cg_meoshi = 0;
            } else if (as->cg_meoshi & 0x110) {
                as->cg_meoshi &= 0xF99F;
            } else {
                as->cg_cancel &= 0xF7;
                as->cg_meoshi = 0;
            }
        }

        if (!(((PLW *)as)->spmv_ng_flag2 & 8) && as->kow & 0x60) {
            as->cg_cancel |= 0x40;
        }

        if (!(((PLW *)as)->spmv_ng_flag2 & 2) && !(as->kow & 0x60) && as->kow & 0xF8) {
            as->cg_cancel |= 0x60;
        }

        if (!(((PLW *)as)->spmv_ng_flag2 & 4) && !(as->kow & 0xF8)) {
            switch (plpat_rno_filter[as->routine_no[2]]) {
            case 9:
                if (as->routine_no[3] == 1) {
                case 1:
                case 2:
                    as->cg_cancel |= 0x60;
                }
                break;
            }
        }

        if (!(as->kow & 0xF8) && as->routine_no[1] == 4 && as->routine_no[2] < 0x10) {
            switch (plpat_rno_filter[as->routine_no[2]]) {
            case 9:
                if (as->routine_no[3] == 1) {
                case 1:
                    if (!(((PLW *)as)->spmv_ng_flag2 & 0x1000000)) {
                        as->cg_cancel |= 1;
                    }

                    if (!(((PLW *)as)->spmv_ng_flag2 & 0x2000000)) {
                        as->cg_cancel |= 2;
                    }

                    if (!(((PLW *)as)->spmv_ng_flag2 & 0x100000)) {
                        i = 0;

                        if (((PLW *)as)->player_number == 4) {
                            as->cg_meoshi = chain_hidou_nm_ground_table[as->kow & 7];
                            as->cg_cancel |= 8;
                            return;
                        }

                        as->cg_meoshi = i | chain_normal_ground_table[as->kow & 7];
                        as->cg_cancel |= 8;
                        return;
                    }
                }

                break;

            case 2:
                if (!(((PLW *)as)->spmv_ng_flag2 & 0x200000) && !hikusugi_check(as)) {
                    i = 0;

                    if (((PLW *)as)->player_number == 7) {
                        as->cg_meoshi = chain_hidou_nm_air_table[as->kow & 7];
                        as->cg_cancel |= 8;
                        return;
                    }

                    as->cg_meoshi = i | chain_normal_air_table[as->kow & 7];
                    as->cg_cancel |= 8;
                }

                break;
            }
        }
    }
}

s16 check_dm_att_guard(WORK *as, WORK *ds, s16 kom) {
    s16 curr_id;
    s16 rnum;

    rnum = 0;
    ds->kezurare_flag = 0;

    if (as->work_id == 1) {
        curr_id = as->id;
    } else {
        curr_id = ((WORK_Other *)as)->master_id;
    }

    if (!(plw[curr_id].spmv_ng_flag & 0x8000)) {
        as->kezuri_pow = 0;
    }

    if (as->kezuri_pow) {
        if (ds->dm_vital != 0) {
            ds->kezurare_flag = 1;
            ds->dm_vital = ds->dm_vital / (as->kezuri_pow / kom);

            if (ds->dm_vital == 0) {
                ds->dm_vital = 1;
            }

            if (ds->dm_vital > ds->vital_new) {
                if (as->no_death_attack || (plw[curr_id].spmv_ng_flag2 & 0x10000000)) {
                    ds->dm_vital = ds->vital_new;
                } else {
                    ds->dm_guard_success = ds->routine_no[2];
                    rnum = 1;
                }
            }
        }
    } else {
        ds->dm_vital = 0;
    }

    return rnum;
}

s16 check_dm_att_blocking(WORK *as, WORK *ds, s16 dnum) {
    s16 rnum = 0;
    TAMA *tama = (TAMA *)as->my_effadrs;

    ds->kezurare_flag = 0;

    if (as->work_id == 4 && as->id == 13 && tama->kz_blocking != 0 && as->kezuri_pow) {
        if (ds->dm_vital != 0) {
            ds->kezurare_flag = 1;

            if (as->kezuri_pow) {
                ds->dm_vital = ds->dm_vital / as->kezuri_pow;
            } else {
                ds->dm_vital = 0;
            }

            if (ds->dm_vital == 0) {
                ds->dm_vital = 1;
            }

            if (ds->dm_vital > ds->vital_new) {
                if (as->no_death_attack) {
                    ds->dm_vital = ds->vital_new;
                } else {
                    ds->dm_guard_success = dnum;
                    rnum = 1;
                }
            }
        }
    } else {
        ds->dm_vital = 0;
    }

    return rnum;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_damage_and_piyo);
#else
void set_damage_and_piyo(PLW *as, PLW *ds) {
    not_implemented(__func__);
}
#endif

s16 remake_score_index(s16 dmv) {
    s16 i;

    for (i = 0; i < 16; i++) {
        if (dmv < rsix_r_table[i][0]) {
            break;
        }
    }

    return rsix_r_table[i][1];
}

void same_dm_stop(WORK *as, WORK *ds) {
    if (as->work_id == 1 && as->att.dipsw & 1 && (ds->xyz[1].disp.pos > 0 || (ds->vital_new - ds->dm_vital) < -2)) {
        switch ((ds->dm_stop < 0) + ((as->att.hs_me < 0) * 2)) {
        case 1:
            ds->dm_stop = -as->att.hs_me;
            /* fallthrough */

        case 2:
            ds->dm_stop = -as->att.hs_me;
            break;

        default:
            ds->dm_stop = as->att.hs_me;
            break;
        }
    }
}

s32 defense_sky(PLW *as, PLW *ds, s8 gddir) {
#if defined(TARGET_PS2)
    s32 check_normal_attack(s16 waza);
#endif

    s8 just_now;
    s8 attr_att;
    s8 abs;
    s8 ags;

    abs = (ds->spmv_ng_flag & 0x80) == 0;
    ags = (ds->spmv_ng_flag & 0x40) == 0;

    if (ds->dead_flag) {
        ds->guard_flag = 3;
    }

    just_now = 0;

    if (ds->guard_chuu != 0 && ds->guard_chuu < 5) {
        just_now = 1;
        attr_att = check_normal_attack(as->wu.kind_of_waza);
    }

    if (ds->py->flag == 0 && !(ds->guard_flag & 2) && as->wu.att.guard & 4) {
        if (just_now) {
            if (!(ds->spmv_ng_flag & 0x1000) && (ds->cp->waza_flag[5] >= grdb2[ds->wu.id][attr_att] || abs)) {
                blocking_point_count_up(ds);
                as->wu.hf.hit.player = 0x80;
                ds->wu.routine_no[2] = 0x22;

                if (check_dm_att_blocking(&as->wu, &ds->wu, 7)) {
                    return 2;
                }

                return 0;
            }
        } else if (!(ds->spmv_ng_flag & 0x400) && ((ds->cp->waza_flag[5] != 0) || abs)) {
            blocking_point_count_up(ds);
            as->wu.hf.hit.player = 0x80;
            ds->wu.routine_no[2] = 0x22;

            if (check_dm_att_blocking(&as->wu, &ds->wu, 7)) {
                return 2;
            }

            return 0;
        }
    }

    if (!(as->wu.att.guard & 32)) {
        return 2;
    }

    if (ds->guard_flag & 1) {
        return 2;
    }

    if (ds->spmv_ng_flag & 32) {
        return 2;
    }

    if (!ds->auto_guard && !ags) {
        if ((ds->spmv_ng_flag & 0x2000) || !just_now) {
            if (!(ds->saishin_lvdir & gddir)) {
                return 2;
            }
            if (ds->cp->sw_lvbt & 3) {
                return 2;
            }
        }
    }

    as->wu.hf.hit.player = 0x20;
    ds->wu.routine_no[2] = 7;

    if (check_dm_att_guard(&as->wu, &ds->wu, 2)) {
        return 2;
    }

    return 1;
}

void blocking_point_count_up(PLW *wk) {
    wk->kind_of_blocking = 0;

    if (wk->wu.routine_no[1] == 0 && wk->wu.routine_no[2] > 30 && wk->wu.routine_no[2] < 36) {
        wk->kind_of_blocking = 1;
    }

    if (wk->wu.routine_no[1] == 1 && wk->wu.routine_no[2] > 3 && wk->wu.routine_no[2] < 8) {
        wk->kind_of_blocking = 2;
    }

    if (wk->spmv_ng_flag & 0x80) {
        grade_add_blocking(wk);
    }
}

s32 defense_ground(PLW *as, PLW *ds, s8 gddir) {
#if defined(TARGET_PS2)
    s32 check_normal_attack(u32 waza);
#endif

    s8 just_now;
    s8 attr_att;
    s8 abs;
    s8 ags;

    abs = (ds->spmv_ng_flag & 0x80) == 0;
    ags = (ds->spmv_ng_flag & 0x40) == 0;

    if (ds->dead_flag) {
        ds->guard_flag = 3;
    }

    just_now = 0;

    if (ds->guard_chuu != 0 && ds->guard_chuu < 5) {
        just_now = 1;
        attr_att = check_normal_attack(as->wu.kind_of_waza);
    }

    if (ds->py->flag == 0 && !(ds->guard_flag & 2) && as->wu.att.guard & 3) {
        if (as->wu.att.guard & 2) {
            if (just_now) {
                if (!(ds->spmv_ng_flag & 0x1000) && ((ds->cp->waza_flag[3] >= grdb[ds->wu.id][attr_att][0]) || abs)) {
                    blocking_point_count_up(ds);
                    as->wu.hf.hit.player = 64;

                    if (check_attbox_dir(ds) == 0) {
                        ds->wu.routine_no[2] = 31;
                    } else {
                        ds->wu.routine_no[2] = 32;
                    }

                    if (check_dm_att_blocking(&as->wu, &ds->wu, 5)) {
                        return 2;
                    }

                    return 0;
                }
            } else if (!(ds->spmv_ng_flag & 0x100)) {
                if (as->wu.jump_att_flag) {
                    if (!(ds->spmv_ng_flag & 0x800) && (ds->cp->waza_flag[12] != 0 || abs)) {
                        blocking_point_count_up(ds);
                        as->wu.hf.hit.player = 64;

                        if (check_attbox_dir(ds) == 0) {
                            ds->wu.routine_no[2] = 31;
                        } else {
                            ds->wu.routine_no[2] = 32;
                        }

                        if (check_dm_att_blocking(&as->wu, &ds->wu, 5)) {
                            return 2;
                        }

                        return 0;
                    }
                } else if (ds->cp->waza_flag[3] != 0 || abs) {
                    blocking_point_count_up(ds);
                    as->wu.hf.hit.player = 64;

                    if (check_attbox_dir(ds) == 0) {
                        ds->wu.routine_no[2] = 31;
                    } else {
                        ds->wu.routine_no[2] = 32;
                    }

                    if (check_dm_att_blocking(&as->wu, &ds->wu, 5)) {
                        return 2;
                    }

                    return 0;
                }
            }
        }

        if (as->wu.att.guard & 1) {
            if (just_now) {
                if (!(ds->spmv_ng_flag & 0x1000) && (!(ds->cp->waza_flag[4] < grdb[ds->wu.id][attr_att][1]) || abs)) {
                    blocking_point_count_up(ds);
                    as->wu.hf.hit.player = 64;
                    ds->wu.routine_no[2] = 33;

                    if (check_dm_att_blocking(&as->wu, &ds->wu, 6)) {
                        return 2;
                    }

                    return 0;
                }
            } else if (!(ds->spmv_ng_flag & 0x200)) {
                if (as->wu.jump_att_flag) {
                    if (!(ds->spmv_ng_flag & 0x800) && (ds->cp->waza_flag[4] != 0 || abs)) {
                        blocking_point_count_up(ds);
                        as->wu.hf.hit.player = 64;
                        ds->wu.routine_no[2] = 33;

                        if (check_dm_att_blocking(&as->wu, &ds->wu, 6)) {
                            return 2;
                        }

                        return 0;
                    }
                } else if (ds->cp->waza_flag[4] != 0 || abs) {
                    blocking_point_count_up(ds);
                    as->wu.hf.hit.player = 64;
                    ds->wu.routine_no[2] = 33;

                    if (check_dm_att_blocking(&as->wu, &ds->wu, 6)) {
                        return 2;
                    }

                    return 0;
                }
            }
        }
    }

    if (!(as->wu.att.guard & 0x18)) {
        return 2;
    }

    if (ds->guard_flag & 1) {
        return 2;
    }

    if (ds->spmv_ng_flag & 0x10) {
        return 2;
    }

    if (!ds->auto_guard && !ags && (ds->spmv_ng_flag & 0x2000 || !just_now)) {
        if (!(ds->saishin_lvdir & gddir)) {
            return 2;
        }

        if (ds->cp->sw_lvbt & 1) {
            return 2;
        }
    }

    switch (as->wu.att.guard & 0x18) {
    case 8:
        if (!(ds->cp->sw_lvbt & 2) && ags == 0) {
            return 2;
        }

        ds->wu.routine_no[2] = 6;
        break;

    case 16:
        if (ds->cp->sw_lvbt & 2 && ags == 0) {
            return 2;
        }

        ds->wu.routine_no[2] = 5;
        break;

    default:
        if (ds->cp->sw_lvbt & 2) {
            ds->wu.routine_no[2] = 6;
            break;
        }

        ds->wu.routine_no[2] = 5;
        break;
    }

    as->wu.hf.hit.player = 16;

    if (ds->wu.routine_no[2] == 5 && check_attbox_dir(ds) == 0) {
        ds->wu.routine_no[2] = 4;
    }

    if (check_dm_att_guard(&as->wu, &ds->wu, 1)) {
        return 2;
    }

    return 1;
}

void setup_dm_rl(WORK *as, WORK *ds) {
    s16 pw;

    if (as->work_id != 1 || check_ttk_damage_request(as->att.reaction)) {
        ds->dm_rl = as->rl_flag;
        return;
    }

    pw = ds->xyz[0].disp.pos - as->xyz[0].disp.pos;

    switch ((ds->xyz[1].disp.pos > 0) + ((as->xyz[1].disp.pos > 0) * 2)) {
    case 0:
    case 2:
        if (!(as->att.dipsw & 0x60)) {
            ds->dm_rl = as->rl_flag;
            return;
        }

        break;
    }

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

void dm_status_copy(WORK *as, WORK *ds) {
    ds->dm_attlv = as->att.level;
    ds->dm_impact = as->att.impact;
    ds->dm_dir = as->dir_atthit;
    ds->dm_stop = as->att.hs_you;
    ds->dm_quake = as->att.hs_you;
    ds->dm_weight = as->weight_level;
    ds->dm_butt_type = as->att.but_ix;
    ds->dm_zuru = as->att_zuru;
    ds->dm_attribute = as->at_attribute;
    ds->dm_ten_ix = as->at_ten_ix;
    ds->dm_koa = as->at_koa;
    ds->hm_dm_side = as->att.dmg_mark;
    ds->dm_work_id = as->work_id;
    as->hit_stop = as->att.hs_me;
    ds->dm_arts_point = as->add_arts_point;
    ds->dm_kind_of_waza = as->kind_of_waza;
    ds->dm_nodeathattack = as->no_death_attack;
    ds->dm_jump_att_flag = as->jump_att_flag;

    if (ds->dm_quake < 0) {
        ds->dm_quake = -ds->dm_quake;
    }

    if (as->work_id == 1) {
        ds->dm_exdm_ix = ((PLW *)as)->exdm_ix;
        ds->dm_plnum = ((PLW *)as)->player_number;
        pp_pulpara_remake_at_hit(as);
    } else {
        ds->dm_plnum = ((PLW *)((WORK_Other *)as)->my_master)->player_number;
    }

    as->meoshi_hit_flag = 1;
}

void add_combo_work(PLW *as, PLW *ds) {
    s16 *kow;
    s16 *cal;

    if (ds->kezurijini_flag) {
        return;
    }

    ds->kizetsu_kow = ds->cb->new_dm = as->wu.kind_of_waza;
    kow = &ds->cb->kind_of[0][0][0];
    cal = &calc_hit[ds->wu.id][0];
    kow[as->wu.kind_of_waza]++;
    cal[(as->wu.kind_of_waza & 120) / 8]++;
    ds->cb->total++;
    kow = &ds->rp->kind_of[0][0][0];
    kow[as->wu.kind_of_waza]++;
    ds->rp->total++;
}

void nise_combo_work(PLW *as, PLW *ds, s16 num) {
    s16 *kow;
    s16 *cal;
    s16 i;

    for (i = 0; i < num; i++) {
        ds->kizetsu_kow = ds->cb->new_dm = as->wu.kind_of_waza;
        kow = &ds->cb->kind_of[0][0][0];
        cal = &calc_hit[ds->wu.id][0];
        kow[as->wu.kind_of_waza]++;
        cal[(as->wu.kind_of_waza & 120) / 8]++;
        ds->cb->total++;
        kow = &ds->rp->kind_of[0][0][0];
        kow[as->wu.kind_of_waza]++;
        ds->rp->total++;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", cal_combo_waribiki);

void cal_combo_waribiki2(PLW *ds) {
    s16 num;

    if (ds->wu.dm_piyo == 0) {
        return;
    }

    if (ds->cb->total == 0) {
        return;
    }

    num = 32 - (ds->cb->total * 2);

    if (num <= 0) {
        num = 1;
    }

    if (num > 32) {
        num = 32;
    }

    ds->wu.dm_piyo = (ds->wu.dm_piyo * num) / 32;

    if (ds->wu.dm_piyo == 0) {
        ds->wu.dm_piyo = 1;
    }
}

void catch_hit_check() {
    WORK *mad;
    WORK *sad;
    s16 *mh;
    s16 *sh;
    s16 mi;
    s16 si;

    for (mi = 0; mi < hpq_in; mi++) {
        if (hs[mi].flag.results & 0x1000) {
            continue;
        }

        mad = q_hit_push[mi];

        if (mad->work_id != 1) {
            continue;
        }

        if (mad->att_hit_ok == 0) {
            continue;
        }

        mh = &mad->h_cat->cat_box[0];

        if (mh[1] == 0) {
            continue;
        }

        for (si = 0; si < hpq_in; si++) {
            if (si == mi) {
                continue;
            }

            if (hs[si].flag.results & 0x100) {
                continue;
            }

            sad = q_hit_push[si];

            if (sad->work_id != 1) {
                continue;
            }

            sh = &sad->h_cau->cau_box[0];

            if (sh[1] == 0) {
                continue;
            }

            if (!(mad->att.guard & 0x18)) {
                if (!((PLW *)sad)->tsukamarenai_flag) {
                    if (!(mad->att.dipsw & 0x60)) {
                        if ((sad->routine_no[1] == 1) && (sad->routine_no[3] != 0)) {
                            if (sad->routine_no[2] != 0x19) {
                                continue;
                            }
                        }
                    } else if ((sad->routine_no[1] == 1) && (sad->routine_no[3] != 0) && (sad->cg_type != 10)) {
                        if (!dm_oiuchi_catch[sad->routine_no[2]]) {
                            continue;
                        }
                    }
                } else {
                    continue;
                }
            }

            if (hit_check_subroutine(mad, sad, mh, sh)) {
                hs[mi].flag.results |= 0x1000;
                hs[mi].my_hit = (u16)si;
                hs[si].flag.results |= 0x100;
                hs[si].dm_me = (u16)mi;
                mad->att_hit_ok = 0;
                hs[mi].ah = mh;
                hs[si].dh = sh;
                mad->att_hit_ok = 0;
            } else {
                continue;
            }

            break;
        }
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", attack_hit_check);
#else
void attack_hit_check() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", hit_check_subroutine);
#else
s16 hit_check_subroutine(WORK *wk1, WORK *wk2, const s16 *hd1, const s16 *hd2) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", hit_check_x_only);
#else
s32 hit_check_x_only(WORK *wk1, WORK *wk2, s16 *hd1, s16 *hd2) {
    not_implemented(__func__);
}
#endif

void cal_hit_mark_position(WORK *wk1, WORK *wk2, s16 *hd1, s16 *hd2) {
    s16 d0 = *hd1++;
    s16 d1 = *hd1++;
    s16 d2;
    s16 d3;

    if (wk1->rl_flag) {
        d0 = -d0;
        d0 -= d1;
    }

    d0 += wk1->xyz[0].disp.pos;
    d1 += d0;
    d2 = *hd2++;
    d3 = *hd2++;

    if (wk2->rl_flag) {
        d2 = -d2;
        d2 -= d3;
    }

    d2 += wk2->xyz[0].disp.pos;
    d3 += d2;

    if (d0 < d2) {
        d0 = d2;
    }

    if (d1 > d3) {
        d1 = d3;
    }

    wk2->hit_mark_x = (d0 + d1) >> 1;

    d0 = wk1->xyz[1].disp.pos + *hd1++;
    d1 = *hd1 + d0;
    d2 = wk2->xyz[1].disp.pos + *hd2++;
    d3 = *hd2 + d2;

    if (d0 < d2) {
        d0 = d2;
    }

    if (d1 > d3) {
        d1 = d3;
    }

    wk2->hit_mark_y = (d0 + d1) >> 1;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", get_target_att_position);
#else
void get_target_att_position(WORK *wk, s16 *tx, s16 *ty) {
    not_implemented(__func__);
}
#endif

s16 get_att_head_position(WORK *wk) {
    s16 *ta;
    s16 kx;
    s16 tx;
    s16 i;

    tx = wk->xyz[0].disp.pos;

    if (wk->cg_ja.atix == 0) {
        return tx;
    }

    ta = &wk->h_att->att_box[0][0];

    for (i = 0; i < 3; i++) {
        if (*ta) {
            if (wk->rl_flag) {
                kx = tx - *ta;

                if (tx < kx) {
                    tx = kx;
                }

                break;
            } else {
                kx = tx + *ta;

                if (tx > kx) {
                    tx = kx;
                }

                break;
            }
        } else {
            ta += 4;
        }
    }
    return tx;
}

void hit_push_request(WORK *hpr_wk) {
    if (hpq_in < 31 && hpr_wk->cg_hit_ix != 0) {
        q_hit_push[hpq_in++] = hpr_wk;
    }
}

void clear_hit_queue() {
    s16 i;

    hpq_in = 0;

    for (i = 0; i < 32; i++) {
        mkm_wk[i] = 0;
    }

    for (i = 0; i < 32; i++) {
        q_hit_push[i] = 0;
    }

    work_init_zero((s32 *)hs, sizeof(hs));
}

s16 change_damage_attribute(PLW *as, u16 atr, u16 ix) {
    switch (atr) {
    case 1:
        if (as->wu.work_id == 1 && as->player_number == 0 && as->wu.rl_flag) {
            ix = attr_freeze_tbl[ix - 32];
            as->wu.at_attribute = 3;
        } else {
            ix = attr_flame_tbl[ix - 32];
        }
        break;

    case 2:
        ix = attr_thunder_tbl[ix - 32];
        break;

    case 3:
        if (as->wu.work_id == 1 && as->player_number == 0 && as->wu.rl_flag) {
            ix = attr_flame_tbl[ix - 32];
            as->wu.at_attribute = 1;
        } else {
            ix = attr_freeze_tbl[ix - 32];
        }
        break;
    }

    return ix;
}

s16 get_sky_nm_damage(u16 ix) {
    ix -= 32;
    return sky_nm_damage_tbl[ix];
}

s16 get_sky_sp_damage(u16 ix) {
    ix -= 32;
    return sky_sp_damage_tbl[ix];
}

s16 get_kagami_damage(u16 ix) {
    ix -= 32;
    return kagami_damage_tbl[ix];
}

s16 get_grd_hand_damage(u16 ix) {
    ix -= 32;
    return grd_hand_damage_tbl[ix];
}

u8 check_head_damage(s16 ix) {
    ix -= 32;
    return hddm_damage_tbl[ix];
}

u8 check_trunk_damage(s16 ix) {
    ix -= 32;
    return trdm_damage_tbl[ix];
}

u8 check_ttk_damage_request(s16 ix) {
    ix -= 32;
    return ttk_damage_req_tbl[ix];
}

const u16 chain_normal_ground_table[8] = { 0x760, 0x660, 0x640, 0x440, 0x400, 0x0, 0x0, 0x0 };
const u16 chain_hidou_nm_ground_table[8] = { 0x770, 0x770, 0x740, 0x470, 0x600, 0x60, 0x0, 0x0 };
const u16 chain_normal_air_table[8] = { 0x660, 0x660, 0x440, 0x440, 0x0, 0x0, 0x0, 0x0 };
const u16 chain_hidou_nm_air_table[8] = { 0x320, 0x220, 0x640, 0x440, 0x510, 0x110, 0x0, 0x0 };
const u8 plpat_rno_filter[16] = { 1, 9, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const s16 rsix_r_table[17][2] = { { 61, 1 },   { 121, 2 },  { 181, 3 },  { 241, 4 },  { 301, 5 },  { 361, 6 },
                                  { 421, 7 },  { 481, 8 },  { 541, 9 },  { 601, 10 }, { 661, 11 }, { 721, 12 },
                                  { 781, 13 }, { 841, 14 }, { 901, 15 }, { 961, 16 }, { 999, 17 } };

const s16 attr_flame_tbl[83] = { 42,  42,  42,  42,  42,  42,  42,  42,  42,  42,  42,  42,  42,  0,   0,   0,   0,
                                 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   67,  67,
                                 67,  67,  67,  67,  67,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                                 0,   0,   0,   0,   0,   103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103,
                                 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103 };

const s16 attr_thunder_tbl[83] = { 43,  43,  43,  43,  43,  43,  43,  43,  43,  43,  43,  43,  43,  0,   0,   0,   0,
                                   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   68,  68,
                                   68,  68,  68,  68,  68,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                                   0,   0,   0,   0,   0,   104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104,
                                   104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104 };

const s16 attr_freeze_tbl[83] = { 44,  44,  44,  44,  44,  44,  44,  44,  44,  44,  44,  44,  44,  0,   0,   0,   0,
                                  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   69,  69,
                                  69,  69,  69,  69,  69,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                                  0,   0,   0,   0,   0,   105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
                                  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105 };

const s16 sky_nm_damage_tbl[83] = { 88,  88,  88,  88,  88,  88,  88,  97,  98, 88,  103, 104, 105, 0,   0,  0,  0,
                                    0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  88, 97,
                                    98,  103, 104, 105, 98,  0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,  0,
                                    0,   0,   0,   0,   0,   88,  89,  90,  91, 92,  93,  94,  95,  96,  97, 98, 99,
                                    100, 101, 102, 103, 104, 105, 106, 107, 91, 109, 110, 111, 112, 113, 114 };

const s16 sky_sp_damage_tbl[83] = { 91,  91,  91,  95,  91,  91,  96,  97,  98, 91,  103, 104, 105, 0,   0,  0,  0,
                                    0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  91, 97,
                                    98,  103, 104, 105, 98,  0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,  0,
                                    0,   0,   0,   0,   0,   88,  89,  90,  91, 92,  93,  94,  95,  96,  97, 98, 90,
                                    100, 101, 102, 103, 104, 105, 106, 107, 91, 109, 110, 111, 97,  113, 114 };

const s16 kagami_damage_tbl[83] = { 64,  64,  64,  64,  64,  64,  64,  65,  66, 64,  67,  68,  69,  0,   0,  0,  0,
                                    0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  64, 65,
                                    66,  67,  68,  69,  70,  0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,  0,
                                    0,   0,   0,   0,   0,   88,  89,  90,  91, 92,  93,  94,  95,  96,  65, 66, 90,
                                    100, 101, 102, 103, 104, 105, 106, 107, 65, 109, 110, 111, 112, 113, 114 };

const s16 grd_hand_damage_tbl[83] = { 41,  41,  41,  41,  41,  41,  41,  41, 41,  41, 42, 43,  44,  0,   0,  0,  0,
                                      0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,  0,   0,   0,   0,  41, 41,
                                      41,  42,  43,  44,  41,  0,   0,   0,  0,   0,  0,  0,   0,   0,   0,  0,  0,
                                      0,   0,   0,   0,   0,   88,  89,  90, 91,  91, 93, 94,  100, 91,  39, 40, 99,
                                      100, 101, 102, 103, 104, 105, 106, 96, 108, 91, 91, 111, 112, 113, 114 };

const u8 hddm_damage_tbl[83] = { 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const u8 trdm_damage_tbl[83] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const u8 ttk_damage_req_tbl[83] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                    0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                    0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1 };

const u8 parisucc_pts[2][40] = {
    { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 24, 26, 28, 30,  32,  34,  36,  38,
      40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 100, 100, 100, 100 },
    { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
      20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20 }
};

const u8 dm_oiuchi_catch[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1 };
