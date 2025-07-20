#include "sf33rd/Source/Game/PLPAT.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFG6.h"
#include "sf33rd/Source/Game/Grade.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/PLPNM.h"
#include "sf33rd/Source/Game/PLS00.h"
#include "sf33rd/Source/Game/PLS01.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/PulPul.h"
#include "sf33rd/Source/Game/workuser.h"

s16 ja_nmj_rno_change(WORK *wk);
void Attack_07000(PLW *wk);
void get_cancel_timer(PLW *wk);
void hoken_muriyari_chakuchi(PLW *wk);
void check_ja_nmj_dummy_RTNM(PLW *wk);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPAT", Player_attack);
#else
void Player_attack(PLW *wk) {
    not_implemented(__func__);
}
#endif

void Attack_00000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        setup_lvdir_after_autodir(wk);
        get_cancel_timer(wk);
        set_char_move_init(&wk->wu, 4, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0x14) {
            wk->wu.routine_no[2] = 4;
            wk->wu.cg_type = 0;
            wk->scr_pos_set_flag = 1;
        }

        break;
    }
}

void Attack_01000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    void setup_mvxy_data(WORK * wk, u32 ix);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        setup_lvdir_after_autodir(wk);
        get_cancel_timer(wk);
        set_char_move_init(&wk->wu, 4, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
            break;
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Attack_02000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    void setup_mvxy_data(WORK * wk, u32 ix);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        setup_lvdir_after_autodir(wk);
        get_cancel_timer(wk);
        set_char_move_init(&wk->wu, 4, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
            break;
        }

        break;

    case 2:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        /* fallthrough */

    case 3:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
        }

        break;
    }
}

void Attack_03000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    void Normal_18000_init_unit(PLW * wk, s32 ps);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        get_cancel_timer(wk);
        if ((Bonus_Game_Flag == 0x14 && wk->bs2_on_car) || (wk->wu.xyz[1].disp.pos <= 0)) {
            hoken_muriyari_chakuchi(wk);
            wk->wu.rl_flag = wk->wu.rl_waza;
            setup_lvdir_after_autodir(wk);
            Normal_18000_init_unit(wk, wk->wu.pat_status);
        }

        set_char_move_init(&wk->wu, 4, (s16)((wk->as->char_ix)));
        break;

    case 1:
        if ((wk->wu.mvxy.a[1].sp > 0) && (wk->wu.xyz[1].disp.pos < 0x10)) {
            add_mvxy_speed(&wk->wu);
            cal_mvxy_speed(&wk->wu);
            break;
        }

        wk->wu.routine_no[3] += 1;

    case 2:
        jumping_union_process(&wk->wu, 3);

        if (wk->wu.routine_no[3] != 3) {
            check_ja_nmj_dummy_RTNM(wk);

            if (wk->wu.cg_type == 0x40) {
                if (!(wk->spmv_ng_flag & 0x100000) && ja_nmj_rno_change(&wk->wu)) {
                    wk->wu.routine_no[1] = 0;
                    wk->wu.routine_no[3] = 1;
                }

                wk->wu.cg_type = 0;
                break;
            }
        }

        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

s16 ja_nmj_rno_change(WORK *wk) {
    s16 rnum = 0;

    switch (wk->pat_status) {
    case 20:
        wk->routine_no[2] = 0x15;
        rnum = 1;
        break;

    case 14:
        wk->routine_no[2] = 0x12;
        rnum = 1;
        break;

    case 26:
        wk->routine_no[2] = 0x18;
        rnum = 1;
        break;

    case 22:
        wk->routine_no[2] = 0x16;
        rnum = 1;
        break;

    case 16:
        wk->routine_no[2] = 0x13;
        rnum = 1;
        break;

    case 28:
        wk->routine_no[2] = 0x19;
        rnum = 1;
        break;

    case 24:
        wk->routine_no[2] = 0x17;
        rnum = 1;
        break;

    case 18:
        wk->routine_no[2] = 0x14;
        rnum = 1;
        break;

    case 30:
        wk->routine_no[2] = 0x1A;
        rnum = 1;
        break;
    }

    return rnum;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPAT", check_ja_nmj_dummy_RTNM);
#else
void check_ja_nmj_dummy_RTNM(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPAT", get_cjdR);

void Attack_04000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        setup_lvdir_after_autodir(wk);
        get_cancel_timer(wk);
        set_char_move_init(&wk->wu, 4, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0x14) {
            wk->wu.routine_no[2] = 1;
            wk->wu.cg_type = 0;
            wk->scr_pos_set_flag = 0;
        }

        break;
    }
}

void Attack_05000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    s32 effect_G6_init(WORK * wk, s32 dat);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);

        if (wk->wu.xyz[1].disp.pos > 0) {
            wk->wu.routine_no[3] = 2;
            char_move_wca(&wk->wu);
        } else {
            hoken_muriyari_chakuchi(wk);
            wk->wu.routine_no[3] = 1;
        }

        wk->cancel_timer = 0;
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
            effect_G6_init(&wk->wu, wk->wu.weight_level);
            break;
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Attack_06000(PLW *wk) {
    wk->scr_pos_set_flag = 0;
    Attack_07000(wk);
}

void Attack_07000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        hoken_muriyari_chakuchi(wk);
        get_cancel_timer(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);

        if (wk->wu.cg_type == 0x14) {
            wk->wu.cg_type = 0;
            wk->wu.rl_flag = wk->wu.rl_waza;
            break;
        }

        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0x14) {
            wk->wu.cg_type = 0;
            wk->wu.rl_flag = wk->wu.rl_waza;
        }

        break;
    }
}

void Attack_08000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    void setup_mvxy_data(WORK * wk, u32 ix);
    void add_to_mvxy_data(WORK * wk, u32 ix);
#endif

    s16 ixx;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;

        if (wk->wu.xyz[1].disp.pos <= 0) {
            wk->wu.rl_flag = wk->wu.rl_waza;
            wk->wu.xyz[1].disp.pos = 0;

            ixx = ((wk->wu.pat_status - 20) / 2 & 3) + 9;

            if (ixx > 11) {
                ixx = 10;
            }

            setup_mvxy_data(&wk->wu, ixx);
        }

        get_cancel_timer(wk);
        set_char_move_init(&wk->wu, 4, (s16)((wk->as->char_ix)));
        wk->wu.mvxy.index = wk->as->data_ix;
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
        }

        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
            break;
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);

        if ((wk->wu.routine_no[3] != 3) && (wk->wu.cg_type == 20)) {
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
            break;
        }

        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Attack_09000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    void setup_mvxy_data(WORK * wk, u32 ix);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        hoken_muriyari_chakuchi(wk);
        get_cancel_timer(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->data_ix);

        if (wk->wu.cg_type == 0x14) {
            wk->wu.cg_type = 0;
            wk->wu.rl_flag = wk->wu.rl_waza;
            break;
        }

        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0x14) {
            wk->wu.cg_type = 0;
            wk->wu.rl_flag = wk->wu.rl_waza;
        }

        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
            break;
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Attack_10000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    void setup_mvxy_data(WORK * wk, s32 ix);
    void grade_add_leap_attack(s32 ix);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        wk->cancel_timer = 0;
        wk->wu.dir_timer = 3;

        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3] = 2;
        }

        grade_add_leap_attack(wk->wu.id);
        break;

    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type != 0x14) {
            break;
        }

        wk->wu.routine_no[3] += 1;

    case 2:
        jumping_union_process(&wk->wu, 4);
        if ((wk->wu.routine_no[3] != 4) && wk->wu.hf.hit.player) {
            if ((wk->wu.hf.hit.player & 3) != 0) {
                wk->wu.mvxy.a[0].sp /= 4;
                wk->wu.routine_no[3] = 4;
                break;
            }

            if ((wk->wu.hf.hit.player & 0x30) != 0) {
                wk->wu.mvxy.a[0].sp /= 4;
                wk->wu.mvxy.a[1].sp = 0;
                wk->wu.routine_no[3] = 3;
                break;
            }

            if ((wk->wu.hf.hit.player & 0xC0) != 0) {
                wk->wu.mvxy.a[0].sp /= 2;
                wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
                wk->wu.mvxy.a[1].sp = 0;
                wk->wu.routine_no[3] = 4;
            }
        }

        break;

    case 3:
        if ((wk->wu.dir_timer -= 1) > 0) {
            break;
        }

        wk->wu.routine_no[3] = 4;
        /* fallthrough */

    case 4:
        jumping_union_process(&wk->wu, 5);
        break;

    case 5:
        char_move(&wk->wu);
        break;
    }
}

void Attack_14000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->cat_break_ok_timer = 6;
        setup_lvdir_after_autodir(wk);
        set_char_move_init(&wk->wu, 4, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }

    if (wk->cat_break_ok_timer) {
        wk->cat_break_reserve = 1;
    }
}

void Attack_15000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    void Normal_18000_init_unit(PLW * wk, s32 ps);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;

        if (wk->wu.xyz[1].disp.pos <= 0) {
            wk->wu.rl_flag = wk->wu.rl_waza;
            setup_lvdir_after_autodir(wk);
            wk->wu.xyz[1].disp.pos = 0;
            Normal_18000_init_unit(wk, wk->wu.pat_status);
        }

        wk->cat_break_ok_timer = 6;
        set_char_move_init(&wk->wu, 4, wk->as->char_ix);

        if (wk->cat_break_ok_timer) {
            wk->cat_break_reserve = 1;
            break;
        }

        break;

    case 1:
        if (wk->cat_break_ok_timer) {
            wk->cat_break_reserve = 1;
        }

        if ((wk->wu.mvxy.a[1].sp > 0) && (wk->wu.xyz[1].disp.pos < 0)) {
            add_mvxy_speed(&wk->wu);
            cal_mvxy_speed(&wk->wu);
            break;
        }

        wk->wu.routine_no[3] += 1;

    case 2:
        jumping_union_process(&wk->wu, 3);

        if ((wk->wu.routine_no[3] != 3) && wk->cat_break_ok_timer) {
            wk->cat_break_reserve = 1;
            break;
        }

        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void get_cancel_timer(PLW *wk) {
    if (wk->tc_1st_flag) {
        wk->cancel_timer = 0;
        return;
    }

    if (wk->wu.xyz[1].disp.pos > 0) {
        wk->cancel_timer = 2;
        return;
    }

    wk->cancel_timer = 2;
}

void hoken_muriyari_chakuchi(PLW *wk) {
    if ((Bonus_Game_Flag == 0x14) && wk->bs2_on_car) {
        wk->wu.xyz[1].disp.pos = bs2_floor[2];
        return;
    }

    wk->wu.xyz[1].disp.pos = 0;
}

void (*const plpat_lv_00[16])(PLW *wk) = { Attack_00000, Attack_01000, Attack_02000, Attack_03000,
                                           Attack_04000, Attack_05000, Attack_06000, Attack_07000,
                                           Attack_08000, Attack_09000, Attack_10000, Attack_00000,
                                           Attack_00000, Attack_00000, Attack_14000, Attack_15000 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPAT", plxx_extra_attack_table);

// void (*const plxx_extra_attack_table[])() = {
//     pl00_extra_attack, pl01_extra_attack, pl02_extra_attack, pl03_extra_attack, pl04_extra_attack,
//     pl05_extra_attack, pl06_extra_attack, pl07_extra_attack, pl08_extra_attack, pl09_extra_attack,
//     pl10_extra_attack, pl11_extra_attack, pl12_extra_attack, pl13_extra_attack, pl14_extra_attack,
//     pl16_extra_attack, pl17_extra_attack, pl18_extra_attack, pl19_extra_attack, pl20_extra_attack
// }; // size: 0, address: 5554544

const u8 cjdr_karaburi_type3[8] = { 255, 255, 255, 255, 255, 255, 255, 255 };

const u8 *cjdr_karaburi_table[20] = {
    cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3,
    cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3,
    cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3,
    cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3, cjdr_karaburi_type3
};

const u8 cjdr_hits_type3[8] = { 255, 255, 255, 255, 255, 255, 255, 255 };

const u8 *cjdr_hits_table[20] = {
    cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3,
    cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3,
    cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3,
    cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3, cjdr_hits_type3,
};

const u8 cjdr_blocking_type0[8] = { 16, 7, 18, 9, 20, 11, 20, 11 };
const u8 cjdr_blocking_type1[8] = { 17, 8, 19, 10, 21, 12, 21, 12 };
const u8 cjdr_blocking_type2[8] = { 18, 9, 20, 11, 22, 13, 22, 13 };

const u8 *cjdr_blocking_table[20] = {
    cjdr_blocking_type0, cjdr_blocking_type1, cjdr_blocking_type1, cjdr_blocking_type1, cjdr_blocking_type0,
    cjdr_blocking_type2, cjdr_blocking_type1, cjdr_blocking_type0, cjdr_blocking_type1, cjdr_blocking_type1,
    cjdr_blocking_type1, cjdr_blocking_type0, cjdr_blocking_type1, cjdr_blocking_type2, cjdr_blocking_type0,
    cjdr_blocking_type1, cjdr_blocking_type1, cjdr_blocking_type1, cjdr_blocking_type2, cjdr_blocking_type1
};

const u8 cjdr_defense_type3[8] = { 255, 255, 255, 255, 255, 255, 255, 255 };

const u8 *cjdr_defense_table[20] = { cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3,
                                     cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3,
                                     cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3,
                                     cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3,
                                     cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3, cjdr_defense_type3 };
