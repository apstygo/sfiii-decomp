#include "sf33rd/Source/Game/PLS00.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/Com_Pl.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/PLPDM.h"
#include "sf33rd/Source/Game/PLS01.h"
#include "sf33rd/Source/Game/PLS03.h"

void nm_01000(PLW *wk);
void nm_09000(PLW *wk);
void nm_18000(PLW *wk);

void jumping_cg_type_check(PLW *wk);
void nm_27_cg_type_check(PLW *wk);
s32 check_cg_cancel_data(PLW *wk);

const s8 lvdir_conv[4];

void (*const process_ndcca[5])(PLW *wk);
void (*const plpnm_xxxxx[59])(PLW *wk);
void (*const plpdm_xxxxx[32])(PLW *wk);

void check_lever_data(PLW *wk) {
    if (wk->wu.routine_no[0] == 4) {
        process_ndcca[wk->wu.routine_no[1]](wk);
    }
}

void process_normal(PLW *wk) {
    plpnm_xxxxx[wk->wu.routine_no[2]](wk);
}

void TO_nm_01000(WORK *wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 1;
    wk->routine_no[3] = 0;
    wk->cg_type = 0;
    nm_01000((PLW *)wk);
}

void TO_nm_36000(WORK *wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 36;
    wk->routine_no[3] = 0;
    wk->cg_type = 0;
    nm_01000((PLW *)wk);
}

void TO_nm_09000(WORK *wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 9;
    wk->routine_no[3] = 0;
    wk->cg_type = 0;
    nm_09000((PLW *)wk);
}

void TO_nm_37000(WORK *wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 37;
    wk->routine_no[3] = 0;
    wk->cg_type = 0;
    nm_09000((PLW *)wk);
}

void TO_nm_38000(WORK *wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 38;
    wk->routine_no[3] = 1;
    wk->cg_type = 0;
}

void TO_nm_18000_01(WORK *wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 18;
    wk->routine_no[3] = 1;
    wk->cg_type = 0;
    nm_18000((PLW *)wk);
}

void nm_00000(PLW * /* unused */) {}

void nm_01000(PLW *wk) {
    if (!setup_kuzureochi(wk) && !check_ashimoto(wk) && !check_full_gauge_attack(wk, 0) &&
        !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) && !check_special_attack(wk) &&
        !check_chouhatsu(wk) && !check_catch_attack(wk) && !check_leap_attack(wk) && !check_nm_attack(wk) &&
        !check_cg_cancel_data(wk) && !check_turn_to_back(wk) && !check_F_R_dash(wk) && !check_jump_ready(wk) &&
        !check_bend_myself(wk) && !check_defense_lever(wk)) {
        check_F_R_walk(wk);
    }
}

void nm_02000(PLW *wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_01000(&wk->wu);
        return;
    }

    if (wk->wu.cg_type == 0x40) {
        TO_nm_36000(&wk->wu);
        return;
    }

    if (!check_ashimoto(wk) && !check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) &&
        !check_super_arts_attack(wk) && !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
        !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) && !check_F_R_dash(wk) &&
        !check_jump_ready(wk) && !check_bend_myself(wk) && !check_defense_lever(wk)) {
        check_F_R_walk(wk);
    }
}

void nm_03000(PLW *wk) {
    if (!check_ashimoto(wk) && !check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) &&
        !check_super_arts_attack(wk) && !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
        !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) && !check_turn_to_back(wk) &&
        !check_F_R_dash(wk) && !check_jump_ready(wk) && !check_bend_myself(wk)) {
        if (check_walking_lv_dir(wk)) {
            wk->wu.routine_no[2] = 0x27;
            wk->wu.routine_no[3] = 0;
            wk->wu.cg_type = 0;
        }

        check_defense_lever(wk);
    }
}

void nm_05000(PLW *wk) {
    if (check_ashimoto_ex(wk) == 0) {
        jumping_cg_type_check(wk);
    }
}

void nm_07000(PLW *wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_01000(&wk->wu);
        return;
    }

    if (!check_ashimoto(wk) && !check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) &&
        !check_super_arts_attack(wk) && !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
        !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) && !check_turn_to_back(wk) &&
        !check_F_R_dash(wk) && !check_jump_ready(wk) && !check_defense_lever(wk) && !check_F_R_walk(wk)) {
        check_bend_myself(wk);
    }
}

void nm_08000(PLW *wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_09000(&wk->wu);
        return;
    }

    if (wk->wu.cg_type == 0x40) {
        TO_nm_37000(&wk->wu);
        return;
    }

    if (!check_ashimoto(wk) && !check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) &&
        !check_super_arts_attack(wk) && !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
        !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) && !check_turn_to_back(wk) &&
        !check_F_R_dash(wk) && !check_jump_ready(wk) && !check_defense_lever(wk)) {
        check_stand_up(wk);
    }
}

void nm_09000(PLW *wk) {
    if (!setup_kuzureochi(wk) && !check_ashimoto(wk) && !check_full_gauge_attack(wk, 0) &&
        !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) && !check_special_attack(wk) &&
        !check_chouhatsu(wk) && !check_catch_attack(wk) && !check_leap_attack(wk) && !check_nm_attack(wk) &&
        !check_cg_cancel_data(wk) && !check_turn_to_back(wk) && !check_F_R_dash(wk) && !check_jump_ready(wk) &&
        !check_stand_up(wk)) {
        check_defense_lever(wk);
    }
}

void nm_10000(PLW *wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_09000(&wk->wu);
        return;
    }

    if (!check_ashimoto(wk) && !check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) &&
        !check_super_arts_attack(wk) && !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
        !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) && !check_F_R_dash(wk) &&
        !check_jump_ready(wk) && !check_defense_lever(wk)) {
        check_stand_up(wk);
    }
}

void nm_16000(PLW *wk) {
    set_new_jpdir(wk);

    if (wk->wu.routine_no[3] != 0) {
        switch (wk->wu.cg_type) {
        case 0xFF:
            check_jump_rl_dir(wk);
            switch (wk->jpdir) {
            case 1:
                wk->wu.routine_no[2] = 0x15;
                break;

            case 2:
                wk->wu.routine_no[2] = 0x17;
                break;

            default:
                wk->wu.routine_no[2] = 0x16;
                break;
            }

            wk->wu.routine_no[3] = 0;
            break;

        case 0x1:
            break;
        }

        if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
            !check_special_attack(wk) && !check_chouhatsu(wk)) {
            check_leap_attack(wk);
        }
    }
}

void nm_17000(PLW *wk) {
    set_new_jpdir(wk);

    if (wk->wu.routine_no[3] != 0) {
        if (wk->wu.cg_type == 0xFF) {
            check_jump_rl_dir(wk);
            switch (wk->jpdir) {
            case 1:
                wk->wu.routine_no[2] = 0x18;
                break;

            case 2:
                wk->wu.routine_no[2] = 0x1A;
                break;

            default:
                wk->wu.routine_no[2] = 0x19;
                break;
            }

            wk->wu.routine_no[3] = 0;
            return;
        }

        if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk)) {
            if ((wk->spmv_ng_flag & 0x800000) || !wk->high_jump_flag) {
                if (!check_special_attack(wk)) {
                    check_chouhatsu(wk);
                }
            }
        }
    }
}

void check_jump_rl_dir(PLW *wk) {
    if (check_rl_flag(&wk->wu) == 0) {
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->cp->lever_dir = lvdir_conv[wk->cp->lever_dir];
        wk->jpdir = lvdir_conv[wk->jpdir];
    }
}

void set_new_jpdir(PLW *wk) {
    if ((wk->cp->sw_lvbt & 1) && wk->cp->lever_dir) {
        wk->jpdir = wk->cp->lever_dir;
    }
}

void nm_18000(PLW *wk) {
    if (wk->wu.routine_no[3] >= 2 || wk->wu.xyz[1].disp.pos <= 0 ||
        (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
         !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) && !check_nm_attack(wk) &&
         !check_cg_cancel_data(wk) && !check_sankaku_tobi(wk) && !check_air_jump(wk))) {
        jumping_cg_type_check(wk);
    }
}

void jumping_cg_type_check(PLW *wk) {
#if defined(TARGET_PS2)
    void clear_chainex_check(s32 ix);
#endif

    if (wk->wu.pat_status < 32) {
        switch (wk->wu.cg_type) {
        case 0xFF:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);
            TO_nm_01000(&wk->wu);
            break;

        case 0x2:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);

            if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
                !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
                !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) && check_jump_ready(wk)) {
                return;
            }

            break;

        case 0x7:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);

            if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
                !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
                !check_leap_attack(wk) && !check_nm_attack(wk) && check_cg_cancel_data(wk)) {
                return;
            }

            break;
        case 0x3:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);

            if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
                !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
                !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) &&
                !check_turn_to_back(wk) && !check_F_R_dash(wk) && !check_jump_ready(wk) && !check_bend_myself(wk)) {
                check_F_R_walk(wk);
                break;
            }

            break;

        case 0x40:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);

            if (wk->wu.pat_status < 0xE) {
                TO_nm_36000(&wk->wu);
                break;
            }

            TO_nm_38000(&wk->wu);
            break;
        }
    } else {
        switch (wk->wu.cg_type) {
        case 0xFF:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);
            TO_nm_09000(&wk->wu);
            break;

        case 0x2:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);

            if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
                !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
                !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) && check_jump_ready(wk)) {
                return;
            }

            break;

        case 0x7:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);

            if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
                !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
                !check_leap_attack(wk) && !check_nm_attack(wk) && check_cg_cancel_data(wk)) {
                return;
            }

            break;

        case 0x3:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);

            if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
                !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
                !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) &&
                !check_turn_to_back(wk) && !check_F_R_dash(wk) && !check_jump_ready(wk) && check_stand_up(wk)) {
                return;
            }

            break;

        case 0x40:
            wk->guard_flag = 0;
            clear_chainex_check(wk->wu.id);
            TO_nm_37000(&wk->wu);
            break;
        }
    }
}

void jumping_guard_type_check(PLW *wk) {
    switch (wk->wu.cg_type) {
    case 0xFF:
    case 0x40:
    case 2:
    case 3:
    case 7:
        wk->guard_flag = 0;
    }
}

void nm_27000(PLW *wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_01000(&wk->wu);
        return;
    }

    if (!check_ashimoto(wk) && !check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) &&
        !check_super_arts_attack(wk) && !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
        !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) && !check_turn_to_back(wk) &&
        !check_F_R_dash(wk) && !check_jump_ready(wk) &&
        ((wk->cp->lever_dir == 2) || (!check_bend_myself(wk) && !check_F_R_walk(wk)))) {
        nm_27_cg_type_check(wk);
    }
}

void nm_27_cg_type_check(PLW *wk) {
    if (wk->wu.routine_no[3] != 0 && wk->sa_stop_flag != 1) {
        switch (wk->wu.cg_type) {
        case 0x1:
            check_defense_kind(wk);
            break;

        case 0x2:
            if ((check_em_catt(wk) != 0) && check_defense_kind(wk) == 0) {
                wk->wu.cg_ix -= wk->wu.cgd_type;
                char_move_z(&wk->wu);
            }

            break;

        case 0x40:
            if (wk->wu.routine_no[2] == 0x1D) {
                wk->wu.routine_no[2] = 0x25;
            } else {
                wk->wu.routine_no[2] = 0x24;
            }

            wk->wu.routine_no[3] = 0;
            wk->wu.cg_type = 0;
            break;
        }
    }
}

void nm_29000(PLW *wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_09000(&wk->wu);
        return;
    }

    if (!check_ashimoto(wk) && !check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) &&
        !check_super_arts_attack(wk) && !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
        !check_leap_attack(wk) && !check_nm_attack(wk) && !check_cg_cancel_data(wk) && !check_turn_to_back(wk) &&
        !check_F_R_dash(wk) && !check_jump_ready(wk)) {
        if (wk->cp->lever_dir == 2 || !check_stand_up(wk)) {
            nm_27_cg_type_check(wk);
        }
    }
}

void nm_31000(PLW *wk) {
    if (wk->wu.routine_no[3] != 0) {
        switch (wk->wu.cg_type) {
        case 0x0:
            if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
                !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) &&
                !check_leap_attack(wk) && check_nm_attack(wk)) {
                return;
            }

            break;

        case 0x40:
            if (wk->wu.pat_status < 0x20) {
                TO_nm_36000(&wk->wu);
                break;
            }

            TO_nm_37000(&wk->wu);
            break;

        case 0xFF:
            if (wk->wu.pat_status < 0x20) {
                TO_nm_01000(&wk->wu);
                break;
            }

            TO_nm_09000(&wk->wu);
            break;
        }
    }
}

void nm_34000(PLW *wk) {
    if (wk->wu.routine_no[3] != 0) {
        switch (wk->wu.cg_type) {
        case 0xFF:
        case 0x40:
            TO_nm_18000_01(&wk->wu);
            break;

        default:
            if (wk->wu.routine_no[3] >= 3) {
                if (wk->wu.pat_status < 0x20) {
                    TO_nm_36000(&wk->wu);
                    return;
                }

                TO_nm_37000(&wk->wu);
            }

            break;
        }
    }
}

void nm_36000(PLW *wk) {
    if (wk->wu.cg_type == 0xFF) {
        if (wk->wu.now_koc == 0 && wk->wu.char_index == 0) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 1;
        } else {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
        }
    } else if (wk->player_number == 8 && wk->wu.now_koc == 0 && wk->wu.char_index == 0x24) {
        exset_char_move_init(&wk->wu, 0, 0);
        wk->wu.routine_no[2] = 1;
        wk->wu.routine_no[3] = 1;
    }

    nm_01000(wk);
}

void nm_37000(PLW *wk) {
    if (wk->wu.cg_type == 0xFF) {
        wk->wu.routine_no[2] = 9;
        wk->wu.routine_no[3] = 0;
    }

    nm_09000(wk);
}

void nm_38000(PLW *wk) {
    if (wk->wu.routine_no[3] >= 2 || wk->wu.xyz[1].disp.pos <= 0 ||
        (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
         !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) && !check_nm_attack(wk) &&
         !check_cg_cancel_data(wk) && !check_sankaku_tobi(wk) && !check_air_jump(wk))) {
        jumping_cg_type_check(wk);
    }
}

void nm_39000(PLW *wk) {
    if (wk->wu.cg_type == 0xFF) {
        if (wk->wu.now_koc == 0 && wk->wu.char_index == 0) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 1;
        } else {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
        }
    }

    nm_01000(wk);
}

void nm_40000(PLW *wk) {
    if (wk->wu.routine_no[3] && wk->wu.cg_type == 0xFF) {
        wk->wu.routine_no[3] = 9;
    }
}

void nm_42000(PLW *wk) {
    if (wk->wu.routine_no[3] > 3) {
        jumping_cg_type_check(wk);
    }
}

void nm_45000(PLW *wk) {
    if (wk->wu.routine_no[3] != 3 ||
        (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk) &&
         !check_special_attack(wk) && !check_chouhatsu(wk) && !check_catch_attack(wk) && !check_nm_attack(wk) &&
         !check_cg_cancel_data(wk))) {
        switch (wk->wu.cg_type) {
        case 0x40:
            if (wk->wu.pat_status < 32) {
                TO_nm_36000(&wk->wu);
                break;
            }

            TO_nm_37000(&wk->wu);
            break;

        case 0xFF:
            if (wk->wu.pat_status < 32) {
                TO_nm_01000(&wk->wu);
                break;
            }

            TO_nm_09000(&wk->wu);
            break;

        default:
            jumping_cg_type_check(wk);
            break;
        }
    }
}

void nm_47000(PLW *wk) {
    if (wk->wu.routine_no[3] > 3) {
        jumping_cg_type_check(wk);
    }
}

void nm_48000(PLW *wk) {
    jumping_cg_type_check(wk);
}

void nm_49000(PLW *wk) {
    jumping_cg_type_check(wk);
}

void nm_51000(PLW * /* unused */) {}

void nm_52000(PLW *wk) {
    if (!check_full_gauge_attack(wk, 0) && !check_full_gauge_attack2(wk, 0) && !check_super_arts_attack(wk)) {
        check_special_attack(wk);
    }
}

void nm_55000(PLW *wk) {
    if (wk->wu.routine_no[3] > 1) {
        jumping_cg_type_check(wk);
    }
}

void nm_57000(PLW *wk) {
    if (wk->wu.routine_no[3] > 2) {
        jumping_cg_type_check(wk);
    }
}

void process_damage(PLW *wk) {
    s32 csw;

    if (wk->wu.routine_no[3] == 0) {
        if (!(wk->spmv_ng_flag & 0x1000000)) {
            csw = 0;

            switch (wk->wu.routine_no[2]) {
            case 4:
                wk->wu.routine_no[1] = 0;
                wk->wu.routine_no[2] = 0x1F;
                csw = 1;
                break;

            case 5:
                wk->wu.routine_no[1] = 0;
                wk->wu.routine_no[2] = 0x20;
                csw = 1;
                break;

            case 6:
                wk->wu.routine_no[1] = 0;
                wk->wu.routine_no[2] = 0x21;
                csw = 1;
                break;

            case 7:
                wk->wu.routine_no[1] = 0;
                wk->wu.routine_no[2] = 0x22;
                csw = 1;
                break;
            }

            if (csw) {
                if (wk->wu.operator == 0) {
                    Next_Be_Free(wk);
                }

                if (wk->wu.dm_stop < 0) {
                    if (wk->wu.dm_stop > -4) {
                        wk->wu.dm_stop = -4;
                    }
                } else if (wk->wu.dm_stop < 4) {
                    wk->wu.dm_stop = 4;
                }
            }
        }

        return;
    }

    plpdm_xxxxx[wk->wu.routine_no[2]](wk);
}

void dm_00000(PLW *wk) {
    if ((wk->wu.routine_no[2] == 0) && (wk->wu.routine_no[3] == 2)) {
        if (check_sa_type_rebirth(wk) != 0) {
            wk->py->flag = 0;
            execute_super_arts(wk);
            return;
        }

        wk->wu.routine_no[3]++;
    }
}

void dm_04000(PLW *wk) {
    switch (wk->wu.cg_type) {
    case 0x9:
        if (wk->py->flag == 0) {
            // do nothing
        }

        break;

    case 0x40:
        if (setup_kuzureochi(wk) == 0) {
            if (wk->py->flag == 0) {
                wk->tsukamarenai_flag = 7;

                if (wk->wu.pat_status < 0x20) {
                    TO_nm_36000(&wk->wu);
                    break;
                }

                TO_nm_37000(&wk->wu);
                break;
            }

            wk->wu.routine_no[2] = 0x13;
            wk->wu.routine_no[3] = 0;
            break;
        }

        break;

    case 0xFF:
        if (setup_kuzureochi(wk) == 0) {
            if (wk->py->flag == 0) {
                wk->tsukamarenai_flag = 7;

                if (wk->wu.pat_status < 0x20) {
                    TO_nm_01000(&wk->wu);
                    break;
                }

                TO_nm_09000(&wk->wu);
                break;
            }

            wk->wu.routine_no[2] = 0x13;
            wk->wu.routine_no[3] = 0;
        }

        break;
    }
}

void dm_08000(PLW *wk) {
    switch (wk->wu.cg_type) {
    case 0xFF:
        wk->tsukamarenai_flag = 7;
        TO_nm_01000(&wk->wu);
        break;

    case 0x40:
        wk->tsukamarenai_flag = 7;
        TO_nm_36000(&wk->wu);
        break;
    }
}

void dm_17000(PLW *wk) {
    if (wk->wu.routine_no[3] == 3) {
        wk->wu.routine_no[1] = 0;
        wk->wu.routine_no[2] = 23;
        wk->wu.routine_no[3] = 2;
        jumping_cg_type_check(wk);
    }
}

void dm_18000(PLW *wk) {
    switch (wk->wu.cg_type) {
    case 0xFF:
        if (wk->wu.vital_new < 0 && (check_sa_type_rebirth(wk) != 0)) {
            wk->py->flag = 0;
            execute_super_arts(wk);
            break;
        }

        if (wk->dead_flag) {
            wk->wu.routine_no[2] = 0x10;
        } else {
            wk->wu.routine_no[2] = 1;
        }

        wk->wu.routine_no[3] = 0;
        wk->wu.cg_type = 0;
        break;

    case 0x40:
        if (wk->py->flag == 0) {
            wk->tsukamarenai_flag = 7;
            TO_nm_36000(&wk->wu);
            break;
        }

        wk->wu.routine_no[2] = 0x13;
        wk->wu.routine_no[3] = 0;
        break;
    }
}

void dm_25000(PLW *wk) {
    if (wk->sa_stop_flag != 1) {
        if ((wk->py->time -= 1) <= 0) {
            TO_nm_36000(&wk->wu);
            set_char_move_init(&wk->wu, 0, 0x2F);
        }
    }
}

void process_catch(PLW *wk) {
    if (wk->wu.routine_no[3] != 0) {
        switch (wk->wu.cg_type) {
        case 0x40:
            if (wk->wu.pat_status < 32) {
                TO_nm_36000(&wk->wu);
                break;
            }

            TO_nm_37000(&wk->wu);
            break;

        case 0xFF:
            if (wk->wu.pat_status < 32) {
                TO_nm_01000(&wk->wu);
                break;
            }

            TO_nm_09000(&wk->wu);
            break;
        }
    }
}

void process_caught(PLW * /* unused */) {}

void process_attack(PLW *wk) {
    if (wk->wu.routine_no[3]) {
        if (check_ashimoto_ex(wk)) {
            return;
        }

        if (wk->cancel_timer && wk->wu.hit_stop == 0) {
            wk->cancel_timer -= 1;
        }

        if (wk->cancel_timer) {
            if (check_full_gauge_attack(wk, 0)) {
                return;
            }

            if (check_full_gauge_attack2(wk, 0)) {
                return;
            }

            if (check_super_arts_attack(wk)) {
                return;
            }

            if (check_special_attack(wk)) {
                return;
            }

            if (check_chouhatsu(wk)) {
                return;
            }

            if (check_catch_attack(wk)) {
                return;
            }

            if (check_leap_attack(wk)) {
                return;
            }
        }

        if (wk->wu.routine_no[2] < 16 && check_full_gauge_attack(wk, 1)) {
            wk->wu.cg_cancel &= 0;
            return;
        }

        if (wk->wu.routine_no[2] == 3 && check_sankaku_tobi(wk)) {
            return;
        }
    }

    if (!check_cg_cancel_data(wk) && wk->wu.routine_no[3] != 0) {
        if (wk->wu.xyz[1].disp.pos == 0 || wk->bs2_on_car != 0) {
            jumping_cg_type_check(wk);
        }
    }
}

s32 check_cg_cancel_data(PLW *wk) {
    if (wk->wu.cg_cancel == 0) {
        return 0;
    }

    if (wk->wu.meoshi_hit_flag != 0) {
        if (wk->spmv_ng_flag2 & 0x40) {
            if (wk->wu.routine_no[1] == 4) {
                switch (wk->player_number) {
                case 7:
                    if (wk->wu.routine_no[2] != 0x19 && !(wk->wu.kind_of_waza & 0xF8)) {
                        wk->wu.cg_cancel &= 0x9F;
                    }

                    break;

                case 18:
                    if (wk->wu.routine_no[2] != 0x11 && !(wk->wu.kind_of_waza & 0xF8)) {
                        wk->wu.cg_cancel &= 0x9F;
                    }

                    break;

                default:
                    if (!(wk->wu.kind_of_waza & 0xF8)) {
                        wk->wu.cg_cancel &= 0x9F;
                    }

                    break;
                }
            } else if (!(wk->wu.kind_of_waza & 0xF8)) {
                wk->wu.cg_cancel &= 0x9F;
            }
        }

        if ((wk->spmv_ng_flag2 & 0x80) && (wk->wu.kind_of_waza & 0xF8)) {
            wk->wu.cg_cancel &= 0xBF;
        }

        if (wk->wu.cg_cancel & 0x40) {
            if (check_full_gauge_attack(wk, 0) != 0) {
                wk->wu.cg_cancel &= 0;
                return 1;
            }

            if ((wk->player_number != 0xE) && (check_full_gauge_attack2(wk, 0) != 0)) {
                wk->wu.cg_cancel &= 0;
                return 1;
            }

            if (check_super_arts_attack(wk)) {
                wk->wu.cg_cancel &= 0;
                return 1;
            }
        }

        if (wk->wu.cg_cancel & 0x20) {
            if (check_special_attack(wk) != 0) {
                return 1;
            }

            if (check_chouhatsu(wk) != 0) {
                return 1;
            }
        }
    }

    if ((wk->wu.cg_cancel & 16) && (check_renda_cancel(wk) != 0)) {
        return 1;
    }

    if ((wk->wu.cg_cancel & 8) && (check_meoshi_cancel(wk) != 0)) {
        return 1;
    }

    if ((wk->wu.cg_cancel & 4) && ((wk->cp->sw_now & 0x770) != ((wk->current_attack))) && (check_nm_attack(wk) != 0)) {
        return 1;
    }

    if (wk->wu.meoshi_hit_flag == 0) {
        return 0;
    }

    if ((wk->wu.cg_cancel & 2) && (check_F_R_dash(wk))) {
        return 1;
    }

    if ((wk->wu.cg_cancel & 1) && !(wk->spmv_ng_flag & 0x400000) && (check_hijump_only(wk) != 0)) {
        wk->high_jump_flag = 1;
        return 1;
    }

    return 0;
}

const s8 lvdir_conv[4] = { 0, 2, 1, 0 };

void (*const process_ndcca[5])(PLW *wk) = {
    process_normal, process_damage, process_catch, process_caught, process_attack
};

void (*const plpnm_xxxxx[59])(PLW *wk) = {
    nm_00000, nm_01000, nm_02000, nm_03000, nm_03000, nm_05000, nm_05000, nm_07000, nm_08000, nm_09000,
    nm_10000, nm_03000, nm_03000, nm_03000, nm_03000, nm_03000, nm_16000, nm_17000, nm_18000, nm_18000,
    nm_18000, nm_18000, nm_18000, nm_18000, nm_18000, nm_18000, nm_18000, nm_27000, nm_27000, nm_29000,
    nm_27000, nm_31000, nm_31000, nm_31000, nm_34000, nm_34000, nm_36000, nm_37000, nm_38000, nm_39000,
    nm_40000, nm_40000, nm_42000, nm_42000, nm_42000, nm_45000, nm_45000, nm_47000, nm_48000, nm_49000,
    nm_49000, nm_51000, nm_52000, nm_52000, nm_51000, nm_55000, nm_55000, nm_57000, nm_55000
};

void (*const plpdm_xxxxx[32])(PLW *wk) = { dm_00000, dm_04000, dm_04000, dm_04000, dm_04000, dm_04000, dm_04000,
                                           dm_04000, dm_08000, dm_08000, dm_08000, dm_08000, dm_04000, dm_04000,
                                           dm_18000, dm_18000, dm_04000, dm_17000, dm_18000, dm_18000, dm_18000,
                                           dm_18000, dm_18000, dm_18000, dm_00000, dm_25000, dm_18000, dm_18000,
                                           dm_18000, dm_18000, dm_18000, dm_18000 };
