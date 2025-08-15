#include "sf33rd/Source/Game/EFFC2.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARID.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/workuser.h"

const BS2 bs2_data_table[8] = { { 0, 70, 400, 8492, 30, 66 }, { 0, 60, 0, 8492, 29, 65 },
                                { 0, 50, 0, 8492, 29, 65 },   { 0, 0, 300, 8492, 28, 64 },
                                { 0, 40, 500, 8492, 27, 63 }, { 0, 30, 500, 8492, 27, 63 },
                                { 0, 20, 0, 8492, 26, 62 },   { 0, 10, 0, 8492, 26, 62 } };

const s16 dm_copy_to_master[8] = { 0, 4, 4, 2, 4, 4, 4, 4 };

const s16 ix_exchange[8] = { 0, 4, 5, 3, 4, 5, 4, 5 };

const s16 sel_dm_quake[4][8] = { { 80, 80, 80, 80, 80, 80, 80, 80 },
                                 { 82, 82, 82, 82, 82, 82, 82, 82 },
                                 { 84, 84, 84, 84, 84, 84, 84, 84 },
                                 { 84, 84, 84, 84, 84, 84, 84, 84 } };

const s16 pbl_select[8][8] = { { 90, 70, 50, 30, 20, 10, 0, 0 }, { 80, 70, 50, 30, 20, 10, 0, 0 },
                               { 80, 70, 50, 30, 20, 10, 0, 0 }, { 90, 80, 70, 50, 30, 10, 0, 0 },
                               { 80, 70, 50, 30, 20, 10, 0, 0 }, { 80, 70, 50, 30, 20, 10, 0, 0 },
                               { 80, 70, 50, 30, 20, 10, 0, 0 }, { 80, 70, 50, 30, 20, 10, 0, 0 } };

const s16 pbs_table[8][8] = { { 8, 9, 10, 18, 11, 12, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 },
                              { 0, 0, 0, 0, 0, 0, 0, 0 },     { 6, 7, 8, 9, 10, 10, 10, 20 },
                              { 6, 6, 7, 7, 8, 9, 18, 19 },   { 6, 6, 7, 7, 8, 9, 18, 19 },
                              { 0, 0, 0, 0, 0, 0, 0, 0 },     { 0, 0, 0, 0, 0, 0, 0, 0 } };

const s16 shizumi_guai[13][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 },       { -2, 0, 0, 0, 0, 0, 0, 0 },
                                  { -3, 0, 0, -2, -2, -2, -2, -2 }, { -3, 0, 0, -3, -3, -3, -3, -3 },
                                  { -2, 0, 0, -3, -3, -3, -3, -3 }, { -2, 0, 0, -2, -2, -2, -2, -2 },
                                  { -1, 0, 0, -2, -2, -2, -2, -2 }, { 0, 0, 0, -1, -1, -1, -1, -1 },
                                  { 0, 0, 0, -2, -2, -2, -2, -2 },  { 0, 0, 0, 1, 1, 1, 1, 1 },
                                  { 0, 0, 0, 2, 2, 2, 2, 2 },       { 0, 0, 0, -1, -1, -1, -1, -1 },
                                  { 0, 0, 0, -2, -2, -2, -2, -2 } };

const s16 shindou_guai[7][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 },      { 0, 0, 0, 1, 1, 1, 1, 1 },
                                 { 0, 0, 0, 2, 2, 2, 2, 2 },      { 0, 0, 0, 3, 3, 3, 3, 3 },
                                 { 0, 0, 0, -1, -1, -1, -1, -1 }, { 0, 0, 0, -2, -2, -2, -2, -2 },
                                 { 0, 0, 0, -3, -3, -3, -3, -3 } };

const s16 c2_last_bomb[4][4] = {
    { 1024, 0, 1024, -112 }, { 896, 0, 1280, -112 }, { 768, 0, 1536, -112 }, { 640, 0, 1792, -112 }
};

void effc2_parts_work_chain_check(s16 flag);
void copy_rno(WORK *wk);
void player_hosei_data(WORK_Other *ewk, s16 flag, s16 f2);
void setup_prio_ix(WORK_Other *c2wk);
void set_parts_priority(WORK *wk);
void setup_parts_break(WORK *wk);
s32 check_parts_break_level(WORK *wk);
void send_to_shizumi_guai(WORK *wk);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", effect_C2_move);
#else
void effect_C2_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

void effC2_main_process_first(WORK_Other *ewk, PLW *twk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    void player_hosei_data(WORK_Other * ewk, s32 flag, s16 f2);
    void effc2_parts_work_chain_check(s32 flag);
#endif

    if (EXE_flag == 0 && Game_pause == 0) {
        switch (ewk->wu.direction + (twk->bs2_on_car * 2)) {
        case 0:
            if (ewk->wu.routine_no[1] != 1 && ewk->wu.routine_no[2] != 0) {
                ewk->wu.routine_no[2] = 0;
                ewk->wu.routine_no[3] = 2;
            }

            break;

        case 3:
            if (ewk->wu.routine_no[1] != 1 && ewk->wu.routine_no[2] != 1) {
                ewk->wu.routine_no[2] = 1;
                ewk->wu.routine_no[3] = 2;
            }

            break;

        case 1:
            if (ewk->wu.routine_no[1] != 1 || ewk->wu.routine_no[2] != 0) {
                ewk->wu.routine_no[1] = 0;
                ewk->wu.routine_no[2] = 0;
                ewk->wu.routine_no[3] = 0;
            }

            break;

        case 2:
            if (ewk->wu.routine_no[1] != 1 || ewk->wu.routine_no[2] != 0) {
                ewk->wu.routine_no[1] = 0;
                ewk->wu.routine_no[2] = 1;
                ewk->wu.routine_no[3] = 0;
            }

            break;
        }

        ewk->wu.old_pos[0] = ewk->wu.old_pos[1] = 0;

        switch (ewk->wu.routine_no[1]) {
        case 0:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                switch (ewk->wu.routine_no[3]) {
                case 0:
                    ewk->wu.routine_no[3]++;
                    set_char_move_init(&ewk->wu, 0, 76);
                    break;

                case 1:
                    char_move(&ewk->wu);

                    if (ewk->wu.cg_type != 0xFF) {
                        break;
                    }

                    ewk->wu.routine_no[3]++;
                    /* fallthrough */

                default:
                    ewk->wu.cg_type = 0;
                    ewk->wu.cg_number = 9;
                    break;
                }

                break;

            default:
                switch (ewk->wu.routine_no[3]) {
                case 0:
                    ewk->wu.routine_no[3]++;
                    set_char_move_init(&ewk->wu, 0, 77);
                    break;

                case 1:
                    char_move(&ewk->wu);

                    if (ewk->wu.cg_type != 0xFF) {
                        break;
                    }

                    ewk->wu.routine_no[3]++;
                    /* fallthrough */

                default:
                    ewk->wu.cg_type = 0;
                    ewk->wu.cg_number = 18;
                    break;
                }
            }

            ewk->wu.old_pos[0] = ewk->wu.cg_type;
            ewk->wu.cg_type = 0;
            break;

        case 1:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                ewk->wu.shell_ix[0] -= ewk->wu.dm_vital;
                ewk->wu.dm_vital = 0;

                if (twk->bs2_on_car) {
                    ewk->wu.hit_stop = 0;
                } else {
                    ewk->wu.hit_stop = ewk->wu.dm_stop / 2;
                }

                ewk->wu.routine_no[2] = 1;
                set_char_move_init(&ewk->wu,
                                   0,
                                   (twk->bs2_on_car * 6) +
                                       ((ewk->wu.dm_rl == 0) + sel_dm_quake[ewk->wu.dm_attlv][ewk->wu.rl_waza]));

                if (ewk->wu.shell_ix[0] < 0) {
                    ewk->wu.dir_old = 1;
                    ewk->wu.dir_timer = 1;
                    ewk->wu.routine_no[1] = 0;
                    ewk->wu.routine_no[2] = 9;
                    break;
                }

                check_parts_break_level(&ewk->wu);
                /* fallthrough */

            case 1:
                if (--ewk->wu.hit_stop <= 0) {
                    char_move(&ewk->wu);

                    if (ewk->wu.cg_type == 0xFF) {
                        ewk->wu.routine_no[1] = 0;
                        ewk->wu.routine_no[2] = 0;
                        ewk->wu.cg_type = 0;
                    }
                }

                break;
            }

            ewk->wu.old_pos[1] = ewk->wu.cg_type;
            ewk->wu.cg_type = 0;
            break;
        }
    }

    player_hosei_data(ewk, ewk->wu.dir_timer, 1);
    setup_parts_break(&ewk->wu);
    setup_prio_ix(ewk);
    send_to_shizumi_guai(&ewk->wu);
    ewk->wu.direction = twk->bs2_on_car;
    copy_rno(&ewk->wu);

    if (!ewk->wu.dir_timer) {
        effc2_parts_work_chain_check(ewk->wu.vital_new);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", effc2_parts_work_chain_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", effC2_main_process_second);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", c2_last_char_and_mvxy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", c2_last_dir_select);

void setup_demojump(PLW *twk, s16 ix) {
    switch (ix) {
    case 0:
        if (twk->wu.xyz[1].disp.pos > 3) {
            twk->wu.routine_no[1] = 0;
            twk->wu.routine_no[2] = 56;
            twk->wu.routine_no[3] = 0;
        }

        break;

    case 1:
        if (twk->bs2_on_car) {
            twk->wu.routine_no[1] = 0;
            twk->wu.routine_no[2] = 58;
            twk->wu.routine_no[3] = 0;
        }

        break;

    case 2:
        if ((twk->wu.pat_status >= 14 && twk->wu.pat_status) <= 30 || twk->bs2_on_car) {
            twk->wu.routine_no[1] = 0;
            twk->wu.routine_no[2] = 56;
            twk->wu.routine_no[3] = 0;
        }

        break;
    }

    if (twk->wu.hit_stop) {
        twk->wu.hit_stop /= 2;

        if (twk->wu.hit_stop == 0) {
            twk->wu.hit_stop = 1;
        }
    }
}

s32 check_effc2_p2_rno(WORK *wk) {
    WORK *c2wk = (WORK *)wk->my_effadrs;

    if (c2wk->dir_timer == 0) {
        return 0;
    }

    if (c2wk->routine_no[1] != 0 || c2wk->routine_no[2] != 10) {
        return 0;
    }

    return 1;
}

void copy_rno(WORK *wk) {
    wk->old_rno[0] = wk->routine_no[0];
    wk->old_rno[1] = wk->routine_no[1];
    wk->old_rno[2] = wk->routine_no[2];
    wk->old_rno[3] = wk->routine_no[3];
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", player_hosei_data);

void set_c2_quake(WORK *wk) {
    if (!wk->hit_stop) {
        return;
    }

    if (wk->hit_stop & 1) {
        wk->next_x = -1;
    }

    if (wk->hit_stop > 6) {
        wk->next_x *= 2;
    }

    if (wk->dm_rl) {
        wk->next_x = -wk->next_x;
    }
}

void get_bs2_parts_data(WORK *wk) {
    const BS2 *bs2 = &bs2_data_table[wk->type];

    wk->work_id = 2;
    wk->dir_timer = bs2->dir_timer;
    wk->dir_step = bs2->chix;
    wk->my_col_code = bs2->color;
    wk->xyz[0].disp.pos = 448;
    wk->xyz[1].disp.pos = 0;
    wk->my_priority = bs2->prio_low;
    wk->vital_old = 0;
    wk->dmcal_m = 1;
    wk->dmcal_d = 2;
    wk->dm_vital = 0;
    wk->dir_atthit = -1;
    wk->vs_id = -1;
    set_parts_priority(wk);
}

void setup_prio_ix(WORK_Other *c2wk) {
    PLW *mwk = (PLW *)c2wk->my_master;
    PLW *twk = (PLW *)mwk->wu.target_adrs;

    c2wk->wu.vital_new = 0;

    if (twk->bs2_on_car || twk->bs2_over_car2 || mwk->wu.xyz[0].disp.pos < twk->wu.xyz[0].disp.pos) {
        c2wk->wu.vital_new = 1;
    }
}

void set_parts_priority(WORK *wk) {
    const BS2 *bs2 = &bs2_data_table[wk->type];
    WORK *c2wk = (WORK *)wk->my_effadrs;

    if (c2wk->vital_new) {
        wk->my_priority = bs2->prio_low;
    } else {
        wk->my_priority = bs2->prio_hi;
    }

    wk->position_z = wk->my_priority;
}

void setup_vital_bonus2(WORK *wk) {
    s16 i;

    for (i = 0; i < 8; i++) {
        wk->shell_ix[i] = bs2_data_table[i].vital;
        wk->cmwk[i] = 0;
    }
}

void c3_new_damage(WORK *wk) {
    WORK *c2wk;
    s16 ix;
    s16 brlv;

    if (Time_Over) {
        wk->dm_vital = 0;
    }

    c2wk = (WORK *)wk->my_effadrs;
    c2wk->routine_no[1] = 1;
    c2wk->routine_no[2] = 0;
    c2wk->dm_attlv = wk->dm_attlv;
    c2wk->dm_rl = wk->dm_rl;
    c2wk->dm_dir = wk->dm_dir;
    c2wk->dm_stop = wk->dm_stop;
    c2wk->rl_waza = wk->type;

    if (c2wk->dm_stop < 0) {
        c2wk->dm_stop = -c2wk->dm_stop;
    }

    wk->dm_vital = (wk->dm_vital * wk->dmcal_m) / wk->dmcal_d;
    ix = ix_exchange[wk->type];
    brlv = dm_copy_to_master[wk->type];
    c2wk->shell_ix[ix] -= wk->dm_vital;

    if (c2wk->shell_ix[ix] <= 0) {
        c2wk->dm_vital += wk->dm_vital;
        c2wk->shell_ix[ix] = 0;
    } else if (c2wk->cmwk[ix] >= brlv) {
        c2wk->dm_vital += wk->dm_vital / 2;
    }

    wk->dm_vital = 0;
    bs2_current_damage = wk->type;
}

s16 c3_hit_disp_check(u8 ix) {
    return bs2_data_table[ix].vital;
}

s16 bs2_sync_bomb(WORK *wk) {
    return ((WORK *)wk->my_effadrs)->dir_old;
}

void bs2_get_parts_break(WORK *wk) {
    wk->scr_mv_x = ((WORK *)wk->my_effadrs)->cg_number;
    wk->scr_mv_y = ((WORK *)wk->my_effadrs)->cmwk[wk->type];
}

void setup_parts_break(WORK *wk) {
    s32 vint;
    s16 i;
    s16 j;
    s16 ix;

    for (i = 0; i < 8; i++) {
        ix = ix_exchange[i];
        vint = bs2_data_table[ix].vital;

        for (j = 0; j < 7; j++) {
            if (wk->shell_ix[ix] > (vint * pbl_select[ix][j]) / 100) {
                break;
            }
        }

        wk->cmwk[i] = j;
    }
}

void setup_parts_break2(WORK *wk) {
    s32 vint = wk->original_vitality;
    s16 j;

    for (j = 0; j < 7; j++) {
        if (wk->shell_ix[0] > (vint * pbl_select[0][j]) / 100) {
            break;
        }
    }

    wk->cmwk[0] = j;
}

void bs2_status_disp(s32 /* unused */) {
    if (Usage == 7) {
        return;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", check_parts_break_level);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC2", bs2_score_add_next);

void set_1st_Bonus_Game_result(WORK *wk) {
    s16 i;
    s16 num = 0;

    for (i = 1; i < 8; i++) {
        num += wk->cmwk[i];
    }

    if (num == 49) {
        Bonus_Game_result = 1;
    }
}

void set_bs2_floor(WORK_Other *wk) {
#if defined(TARGET_PS2)
    void player_hosei_data(WORK_Other * ewk, s32 flag, s16 f2);
#endif

    PLW *em = (PLW *)((WORK *)wk->my_master)->target_adrs;
    s16 *dad;

    player_hosei_data(wk, wk->wu.dir_timer, 1);
    dad = wk->wu.hosei_adrs[wk->wu.cg_ja.hoix].hos_box;
    bs2_floor[0] = wk->wu.xyz[0].disp.pos + dad[0];
    bs2_floor[1] = wk->wu.xyz[0].disp.pos + dad[0] + dad[1];
    bs2_floor[2] = dad[2] + dad[3];
    dad = wk->wu.hosei_adrs[wk->wu.cg_ja.hoix + 1].hos_box;
    bs2_hosei[0] = wk->wu.xyz[0].disp.pos + dad[0];
    bs2_hosei[1] = wk->wu.xyz[0].disp.pos + dad[0] + dad[1];
    bs2_hosei[2] = dad[2] + dad[3];
}

void get_shizumi_guai(WORK *wk) {
    wk->next_x = shindou_guai[((WORK *)wk->my_effadrs)->old_pos[1]][wk->type];
    wk->next_y = shizumi_guai[((WORK *)wk->my_effadrs)->old_pos[0]][wk->type];
}

void send_to_shizumi_guai(WORK *wk) {
    ((WORK *)wk->target_adrs)->next_y = shizumi_guai[((WORK *)wk->my_effadrs)->old_pos[0]][0];
}

s32 effect_C2_init(WORK *wk, u8 data) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x7A;
    ewk->wu.type = data;
    ewk->wu.my_mts = 5;
    ewk->my_master = (u32 *)wk;
    ewk->wu.target_adrs = (u32 *)wk->target_adrs;
    ewk->master_player = ((PLW *)wk)->player_number;
    ewk->master_id = wk->id;
    ewk->master_work_id = wk->work_id;
    wk->my_effadrs = (u32 *)ewk;
    ewk->wu.my_effadrs = (u32 *)ewk;
    effect_C2_move(ewk);
    return 0;
}
