#include "sf33rd/Source/Game/PLPDM.h"
#include "common.h"
#include "sf33rd/Source/Game/CALDIR.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFA7.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/EFFG6.h"
#include "sf33rd/Source/Game/EFFI3.h"
#include "sf33rd/Source/Game/Grade.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/PLPCA.h"
#include "sf33rd/Source/Game/PLS01.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/Pow_Pow.h"
#include "sf33rd/Source/Game/PulPul.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/SysDir.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/sc_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void setup_damage_process_flags(PLW *wk);
void Damage_00000(PLW *wk);
void Damage_01000(PLW *wk);
void Damage_04000(PLW *wk);
void Damage_07000(PLW *wk);
void Damage_12000(PLW *wk);
void Damage_14000(PLW *wk);
void Damage_16000(PLW *wk);
void Damage_17000(PLW *wk);
void Damage_18000(PLW *wk);
void Damage_19000(PLW *wk);
void Damage_20000(PLW *wk);
void Damage_21000(PLW *wk);
void Damage_23000(PLW *wk);
void Damage_24000(PLW *wk);
void Damage_25000(PLW *wk);
void Damage_26000(PLW *wk);
void Damage_27000(PLW *wk);
void Damage_28000(PLW *wk);
void Damage_29000(PLW *wk);
void Damage_30000(PLW *wk);
void Damage_31000(PLW *wk);
void first_flight_union(PLW *wk, s16 num, s16 dv);
void first_TtktV_union(PLW *wk, s16 num, s16 dv);
void buttobi_chakuchi_cg_type_check(PLW *wk);
void buttobi_add_y_check(PLW *wk);
void set_dm_hos_flag_sky(PLW *wk);
void get_sky_dm_timer(PLW *wk);
void get_damage_reaction_data(PLW *wk);
void damage_atemi_setup(PLW *wk, PLW *ek);
void check_bullet_damage(PLW *wk);
void check_dmpat_to_dmpat(PLW * /* unused */);

const s16 dir32_guard_air[32] = { 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4,
                                  4, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 1, 1, 1, 0, 0 };

const s16 ris_data_table[4][4] = { { 0, 19, 23, 27 }, { 0, 15, 18, 21 }, { 0, 12, 14, 16 }, { 0, 8, 10, 18 } };

const s16 dm17_to_nm23_change[20] = {
    37, 50, 56, 103, 46, 42, 64, 78, 57, 48, 100, 45, 51, 47, 69, 65, 79, 55, 46, 51
};

const s16 hok_table[8] = { 1, 2, 3, 3, 4, 4, 5, 5 };

const s16 oki_select_table2[4] = { 13, 12, 12, 13 };

const s16 sky_dm_zuru_table[4][16] = { { 0, 161, 121, 91, 61, 41, 21, 11, 7, 3, 1, 1, 1, 1, 1, 1 },
                                       { 0, 241, 201, 161, 121, 81, 41, 21, 9, 3, 1, 1, 1, 1, 1, 1 },
                                       { 0, 321, 281, 241, 201, 171, 141, 111, 81, 61, 41, 21, 11, 7, 5, 3 },
                                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

const s16 sky_dm_zuru_ix[8] = { 1, 2, 3, 5, 7, 10, 15, 15 };

const s8 tama_select[240] = {
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 3, 3, 3, 3, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const AS dm_reaction_table[115] = {
    { 0, 0, 0 },   { 1, 64, 0 },  { 2, 64, 15 }, { 3, 64, 16 }, { 4, 0, 0 },   { 5, 1, 0 },   { 6, 2, 0 },
    { 7, 3, 0 },   { 8, 4, 17 },  { 9, 5, 17 },  { 10, 6, 18 }, { 11, 7, 0 },  { 2, 71, 19 }, { 3, 72, 20 },
    { 0, 0, 0 },   { 0, 0, 0 },   { 0, 67, 0 },  { 24, 68, 0 }, { 24, 69, 0 }, { 25, 70, 0 }, { 25, 70, 0 },
    { 25, 70, 0 }, { 25, 70, 0 }, { 25, 70, 0 }, { 25, 70, 0 }, { 25, 70, 0 }, { 25, 70, 0 }, { 25, 70, 0 },
    { 25, 70, 0 }, { 25, 70, 0 }, { 25, 70, 0 }, { 25, 70, 0 }, { 12, 8, 0 },  { 12, 12, 0 }, { 12, 16, 0 },
    { 12, 20, 0 }, { 12, 24, 0 }, { 12, 28, 0 }, { 12, 32, 0 }, { 14, 36, 0 }, { 21, 40, 0 }, { 12, 44, 0 },
    { 12, 92, 0 }, { 12, 82, 0 }, { 12, 74, 0 }, { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },
    { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },
    { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },
    { 0, 0, 0 },   { 13, 48, 0 }, { 15, 52, 0 }, { 22, 56, 0 }, { 13, 48, 0 }, { 13, 86, 0 }, { 13, 78, 0 },
    { 27, 60, 0 }, { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },
    { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },
    { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 0, 0, 0 },   { 17, 0, 0 },  { 16, 1, 0 },  { 18, 2, 0 },
    { 18, 8, 0 },  { 18, 3, 0 },  { 19, 4, 0 },  { 19, 5, 0 },  { 18, 6, 0 },  { 18, 7, 0 },  { 20, 9, 0 },
    { 23, 10, 0 }, { 26, 11, 0 }, { 18, 12, 0 }, { 18, 13, 0 }, { 18, 14, 0 }, { 18, 8, 0 },  { 18, 15, 0 },
    { 18, 19, 0 }, { 18, 16, 0 }, { 18, 17, 0 }, { 28, 18, 0 }, { 29, 8, 18 }, { 29, 9, 20 }, { 30, 4, 32 },
    { 18, 33, 0 }, { 18, 34, 0 }, { 31, 17, 0 }
};

const s16 dd_convert[115][4] = {
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 16, 16, 16, 16 },     { 17, 17, 17, 17 },     { 18, 18, 18, 18 },     { 91, 91, 91, 91 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 17, 100, 100, 100 },  { 17, 100, 100, 100 },  { 17, 100, 94, 94 },    { 17, 100, 95, 95 },
    { 17, 36, 36, 36 },     { 17, 91, 91, 91 },     { 17, 96, 96, 96 },     { 17, 39, 39, 39 },
    { 17, 40, 40, 40 },     { 17, 91, 91, 91 },     { 103, 103, 103, 103 }, { 104, 104, 104, 104 },
    { 105, 105, 105, 105 }, { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 18, 91, 91, 91 },     { 18, 65, 65, 65 },     { 18, 66, 66, 66 },     { 103, 103, 103, 103 },
    { 104, 104, 104, 104 }, { 105, 105, 105, 105 }, { 70, 70, 70, 70 },     { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
    { 91, 91, 91, 91 },     { 101, 101, 101, 101 }, { 102, 102, 102, 102 }, { 91, 91, 91, 91 },
    { 92, 92, 92, 92 },     { 93, 93, 93, 93 },     { 94, 94, 94, 94 },     { 95, 95, 95, 95 },
    { 96, 96, 96, 96 },     { 97, 97, 97, 97 },     { 98, 98, 98, 98 },     { 99, 99, 99, 99 },
    { 100, 100, 100, 100 }, { 101, 101, 101, 101 }, { 102, 102, 102, 102 }, { 103, 103, 103, 103 },
    { 104, 104, 104, 104 }, { 105, 105, 105, 105 }, { 106, 106, 106, 106 }, { 107, 107, 107, 107 },
    { 108, 108, 108, 108 }, { 109, 109, 109, 109 }, { 110, 110, 110, 110 }, { 111, 111, 111, 111 },
    { 112, 112, 112, 112 }, { 113, 113, 113, 113 }, { 114, 114, 114, 114 }
};

const u8 guard_kind[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0 };

void (*const plpdm_lv_00[32])(PLW *wk) = {
    Damage_00000, Damage_01000, Damage_01000, Damage_01000, Damage_04000, Damage_04000, Damage_04000, Damage_07000,
    Damage_04000, Damage_04000, Damage_04000, Damage_07000, Damage_12000, Damage_12000, Damage_14000, Damage_14000,
    Damage_16000, Damage_17000, Damage_18000, Damage_19000, Damage_20000, Damage_21000, Damage_21000, Damage_23000,
    Damage_24000, Damage_25000, Damage_26000, Damage_27000, Damage_28000, Damage_29000, Damage_30000, Damage_31000
};

const s8 atsagct[31] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 17, 0, 1, 1, 0, 1, 1 };

const u16 exdm_ix_data[2][20][5] = {
    { { 15, 0, 1, 0, 359 },       { 65535, 12, 1, 0, 1801 }, { 2, 13, 1, 0, 2744 },     { 4, 2, 1, 0, 3865 },
      { 65533, 3, 1, 0, 5253 },   { 65521, 9, 1, 0, 6596 },  { 23, 65530, 1, 0, 7609 }, { 65515, 21, 1, 964, 8690 },
      { 30, 21, 1, 0, 10394 },    { 3, 23, 1, 0, 11911 },    { 4, 2, 1, 0, 13593 },     { 2, 13, 1, 0, 14808 },
      { 2, 13, 1, 0, 15864 },     { 15, 0, 1, 0, 17159 },    { 2, 13, 1, 0, 18424 },    { 65510, 9, 1, 0, 19779 },
      { 65511, 13, 1, 0, 21429 }, { 19, 0, 1, 0, 23300 },    { 4, 0, 1, 0, 25191 },     { 6, 5, 1, 0, 26103 } },
    { { 0, 0, 1, 0, 359 },      { 65535, 14, 1, 0, 1801 }, { 6, 9, 1, 0, 2744 },      { 12, 3, 1, 0, 3865 },
      { 9, 65535, 1, 0, 5253 }, { 65529, 3, 1, 0, 6596 },  { 18, 65518, 1, 0, 7609 }, { 0, 19, 1, 964, 8690 },
      { 40, 21, 1, 0, 10394 },  { 14, 22, 1, 0, 11911 },   { 12, 3, 1, 0, 13593 },    { 6, 9, 1, 0, 14808 },
      { 6, 9, 1, 0, 15864 },    { 0, 0, 1, 0, 17159 },     { 6, 9, 1, 0, 18424 },     { 25, 14, 1, 0, 19875 },
      { 16, 20, 1, 0, 21532 },  { 65530, 0, 1, 0, 23315 }, { 23, 2, 1, 0, 25264 },    { 9, 22, 1, 0, 26103 } }
};

void Player_damage(PLW *wk) {
#if defined(TARGET_PS2)
    void clear_chainex_check(s32 ix);
#endif

    setup_damage_process_flags(wk);

    if (wk->wu.routine_no[3] == 0) {
        get_damage_reaction_data(wk);

        if (wk->wu.dm_koa & 0x980) {
            wk->ukemi_ok_timer = 0;
        } else {
            wk->ukemi_ok_timer = 6;
        }

        wk->uot_cd_ok_flag = 0;
        wk->ukemi_success = 0;
        check_bullet_damage(wk);
        clear_chainex_check(wk->wu.id);
    }

    if (wk->atemi_flag == 9) {
        wk->atemi_flag = 0;
    } else {
        plpdm_lv_00[(wk->wu.routine_no[2])](wk);
    }

    set_hit_stop_hit_quake(&wk->wu);
}

void setup_damage_process_flags(PLW *wk) {
    wk->wu.next_z = wk->wu.my_priority;
    wk->running_f = 0;
    wk->guard_flag = 3;
    wk->guard_chuu = 0;
    wk->tsukami_f = 0;
    wk->tsukamare_f = 0;
    wk->scr_pos_set_flag = 1;
    wk->dm_hos_flag = 0;
    wk->caution_flag = 0;
    wk->sa->saeff_ok = 0;
    wk->sa->saeff_mp = 0;
    wk->cancel_timer = 0;
    wk->hazusenai_flag = 0;
    wk->cat_break_reserve = 0;
    wk->cmd_request = 0;
    wk->hsjp_ok = 0;
    wk->high_jump_flag = 0;
    wk->wu.swallow_no_effect = 0;

    if (wk->wu.routine_no[3]) {
        wk->sa_stop_flag = 0;
    }
}

void Damage_00000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    wk->wu.next_z = 0x1E;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        set_char_move_init(&wk->wu, 1, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
        }

        /* fallthrough */

    case 2:
        break;
    }
}

void Damage_01000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] = 1;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        reset_mvxy_data(&wk->wu);
        set_char_move_init(&wk->wu, 1, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            cal_mvxy_speed(&wk->wu);
        }
        break;

    case 2:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }

        break;

    case 3:
        jumping_union_process(&wk->wu, 4);
        break;

    case 4:
        char_move(&wk->wu);
        break;
    }

    if (wk->wu.cg_type == 0xFF || wk->wu.cg_type == 0x40) {
        wk->guard_flag = 0;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_04000);
#else
void Damage_04000(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_07000);
#else
void Damage_07000(PLW *wk) {
    not_implemented(__func__);
}
#endif

s32 remake_initial_speeds(WORK *wk) {
    s16 ix;
    s16 ix2;
    s32 ay = wk->mvxy.a[1].sp;
    s32 dy = wk->mvxy.d[1].sp;

    if ((wk->xyz[1].disp.pos < 8) && (ay <= 0)) {
        return 1;
    }

    setup_butt_own_data(wk);
    ix = dir32_guard_air[cal_move_dir_forecast(wk, 5)];
    ix2 = ris_data_table[ix][wk->dm_attlv];

    if (wk->dm_attlv) {
        switch (ix) {
        case 0:
            wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * 0x50) / 100;
            wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp * 0x78) / 100;
            cal_initial_speed_y(wk, ris_data_table[0][wk->dm_attlv], wk->xyz[1].disp.pos);
            wk->mvxy.a[1].sp += (ay * 0x3C) / 100;
            break;

        case 1:
            wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * 0x4B) / 100;
            wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp * 0x64) / 100;
            cal_initial_speed_y(wk, ris_data_table[1][wk->dm_attlv], wk->xyz[1].disp.pos);
            wk->mvxy.a[1].sp += (ay * 0x23) / 100;
            break;

        case 2:
            wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * 0x46) / 100;
            wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp * 0x50) / 100;
            cal_initial_speed_y(wk, ris_data_table[2][wk->dm_attlv], wk->xyz[1].disp.pos);
            wk->mvxy.a[1].sp += (ay * 0x14) / 100;
            break;

        case 3:
            wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * 0x50) / 100;
            wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp - 0x8000) - 0x8000;
            wk->mvxy.a[1].sp += (ay * 0xA) / 100;
            break;

        default:
            wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * 0x5A) / 100;
            wk->mvxy.a[1].sp = wk->mvxy.a[1].sp + 0xFFFE0000;
            break;
        }
    } else {
        wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * 0x78) / 100;

        if (ay >= 0) {
            wk->mvxy.a[1].sp = ay;
        } else {
            wk->mvxy.a[1].sp = (ay * 0x3C) / 100;
        }

        wk->mvxy.d[1].sp = dy;
    }

    if ((wk->xyz[1].disp.pos < 0xC) && (cal_move_quantity3(wk, 3) <= 0)) {
        return 1;
    }

    return 0;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_12000);
#else
void Damage_12000(PLW *wk) {
    not_implemented(__func__);
}
#endif

void Damage_14000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK *)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        setup_butt_own_data(&wk->wu);
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    case 2:
        wk->dm_hos_flag = 1;
        first_TtktV_union(wk, 3, 4);
        break;

    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_16000);
#else
void Damage_16000(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_17000);
#else
void Damage_17000(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_18000);
#else
void Damage_18000(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_19000);
#else
void Damage_19000(PLW *wk) {
    not_implemented(__func__);
}
#endif

void Damage_20000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK *)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        setup_butt_own_data(&wk->wu);
        buttobi_add_y_check(wk);
        set_char_move_init(&wk->wu, 6, wk->as->char_ix);
        check_dmpat_to_dmpat(wk);
        get_sky_dm_timer(wk);
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    case 2:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 3, 4);
        break;

    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}

void Damage_21000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK *)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        setup_butt_own_data(&wk->wu);
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    case 2:
        wk->dm_hos_flag = 1;
        first_TtktV_union(wk, 3, 2);
        break;

    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}

void Damage_23000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK *)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        setup_butt_own_data(&wk->wu);
        buttobi_add_y_check(wk);
        set_char_move_init(&wk->wu, 6, wk->as->char_ix);
        check_dmpat_to_dmpat(wk);
        get_sky_dm_timer(wk);
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    case 2:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 3, 2);
        break;

    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_24000);
#else
void Damage_24000(PLW *wk) {
    not_implemented(__func__);
}
#endif

void Damage_25000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
    void grade_add_em_stun(s32 ix);
    void pulpul_request(s32 id, s16 ix);
#endif

    s16 i;
    s16 hok;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 1, wk->as->char_ix);
        wk->py->flag = 0;
        wk->py->time = kizetsu_timer_table[(wk->kizetsu_kow & 0xF8) / 8][(wk->kizetsu_kow & 7) / 2][random_16()];
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        work_init_zero((s32 *)wk->rp, sizeof(ComboType));
        check_em_tk_power_off(wk, (PLW *)wk->wu.target_adrs);
        grade_add_em_stun((wk->wu.id + 1) & 1);
        break;

    case 1:
        if ((pcon_dp_flag != 0) && (wk->py->time > 0x30)) {
            wk->py->time = 0x30;
        }

        wk->py->time -= wk->cp->lgp / 2;

        if (wk->cp->lgp > 13) {
            hok = 5;
        } else {
            hok = hok_table[wk->cp->lgp / 2];
        }

        for (i = 0; i < hok; i++) {
            char_move(&wk->wu);
        }

        setup_kuzureochi(wk);
        break;
    }

    if (wk->wu.cg_se) {
        pulpul_request(wk->wu.id, 0x30);
        wk->wu.cg_se = 0;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_26000);
#else
void Damage_26000(PLW *wk) {
    not_implemented(__func__);
}
#endif

void Damage_27000(PLW *wk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        setup_butt_own_data(&wk->wu);
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;

    case 1:
        wk->wu.routine_no[3] += 1;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    default:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_28000);
#else
void Damage_28000(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_29000);
#else
void Damage_29000(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_30000);
#else
void Damage_30000(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", Damage_31000);
#else
void Damage_31000(PLW *wk) {
    not_implemented(__func__);
}
#endif

void first_flight_union(PLW *wk, s16 num, s16 dv) {
#if defined(TARGET_PS2)
    void jumping_union_process(WORK * wk, s32 num);
#endif

    jumping_union_process(&wk->wu, num);

    if (wk->wu.routine_no[3] == num) {
        wk->wu.mvxy.a[0].sp /= dv;
        wk->wu.mvxy.d[0].sp = wk->wu.mvxy.kop[0] = 0;
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;

        if (wk->ukemi_ok_timer) {
            wk->uot_cd_ok_flag = 1;
        } else {
            wk->uot_cd_ok_flag = 0;
        }

        subtract_cu_vital(wk);
        effect_A7_init(wk);
        buttobi_chakuchi_cg_type_check(wk);

        if (wk->ukemi_ok_timer != 0 && wk->ukemi_success == 0) {
            wk->uot_cd_ok_flag = 1;
        }
    }
}

void first_TtktV_union(PLW *wk, s16 num, s16 dv) {
    char_move(&wk->wu);

    if (wk->wu.cg_type) {
        wk->wu.routine_no[3] = num;
        wk->wu.mvxy.a[0].sp /= dv;
        wk->wu.mvxy.d[0].sp = wk->wu.mvxy.kop[0] = 0;

        if (wk->ukemi_ok_timer) {
            wk->uot_cd_ok_flag = 1;
        } else {
            wk->uot_cd_ok_flag = 0;
        }

        subtract_cu_vital(wk);
        effect_A7_init(wk);
        buttobi_chakuchi_cg_type_check(wk);

        if (wk->ukemi_ok_timer != 0 && wk->ukemi_success == 0) {
            wk->uot_cd_ok_flag = 1;
        }
    } else {
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
    }
}

void buttobi_chakuchi_cg_type_check(PLW *wk) {
#if defined(TARGET_PS2)
    void grade_add_quick_stand(s32 ix);
#endif

    switch (wk->wu.cg_type) {
    case 9:
        break;

    case 1:
        add_mvxy_speed(&wk->wu);
        break;

    case 2:
        if (wk->wu.mvxy.a[0].sp > 0) {
            add_mvxy_speed_direct(&wk->wu, 0x80, 0);
            break;
        }

        if (wk->wu.mvxy.a[0].sp < 0) {
            add_mvxy_speed_direct(&wk->wu, -0x80, 0);
        }

        break;

    case 5:
        if (!(wk->spmv_ng_flag2 & 0x200) && wk->ukemi_success && (wk->dead_flag == 0) && (wk->py->flag == 0) &&
            (wk->wu.vital_new > 0) && (pcon_dp_flag == 0)) {
            wk->wu.routine_no[2] = oki_select_table2[wk->wu.rl_waza + (wk->wu.rl_flag * 2)];
            wk->wu.routine_no[3] = 0;
            add_sp_arts_gauge_ukemi(wk);
            grade_add_quick_stand(wk->wu.id);
        }

        if (wk->wu.mvxy.a[0].sp > 0) {
            add_mvxy_speed_direct(&wk->wu, 0x40, 0);
            break;
        }

        if (wk->wu.mvxy.a[0].sp < 0) {
            add_mvxy_speed_direct(&wk->wu, -0x40, 0);
        }

        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", buttobi_add_y_check);
#else
void buttobi_add_y_check(PLW *wk) {
    not_implemented(__func__);
}
#endif

void setup_smoke_type(PLW *wk) {
#if defined(TARGET_PS2)
    s32 effect_G6_init(WORK * wk, u32 dat);
#endif

    s8 *step_tbl;
    u8 ix;
    s16 i;
    s16 total;

    total = 0;
    step_tbl = wk->dm_step_tbl;

    for (i = 0; i < 32; i++) {
        total += *step_tbl++;
    }

    if (total < 0) {
        total = -total;
    }

    if (total >= 32) {
        ix = 0;

        if (total >= 48) {
            ix = 1 & 0xFF;

            if (total >= 64) {
                ix = 2 & 0xFF;

                if (total >= 80) {
                    ix = 3 & 0xFF;
                }
            }
        }

        effect_G6_init(&wk->wu, ix);
    }
}

void add_dm_step_tbl(PLW *wk, s8 flag) {
    if (flag) {
        if (wk->wu.dm_rl) {
            wk->wu.xyz[0].disp.pos += *wk->dm_step_tbl++;
            return;
        }

        wk->wu.xyz[0].disp.pos -= *wk->dm_step_tbl++;
        return;
    }

    wk->dm_step_tbl += 1;
}

void check_dmpat_to_dmpat(PLW * /* unused */) {}

void set_dm_hos_flag_sky(PLW *wk) {
    s16 disx;
    PLW *twk;

    twk = (PLW *)wk->wu.target_adrs;
    disx = wk->wu.xyz[0].disp.pos - twk->wu.xyz[0].disp.pos;

    if (disx < 0) {
        disx = -disx;
    }

    if (wk->wu.dm_work_id & 8) {
        if (wk->wu.mvxy.a[1].real.h <= 0) {
            if (disx > 0x60) {
                return;
            }
        } else if (disx > 0xA0) {
            return;
        }

        wk->dm_hos_flag = 1;

    } else if (wk->wu.dm_work_id & 1 &&
               (twk->player_number != 0 || twk->wu.now_koc != 5 || twk->wu.char_index != 0x3B)) {
        if (wk->wu.mvxy.a[1].real.h <= 0) {
            if (disx > 0x50) {
                return;
            }
        } else if (disx > 0x80) {
            return;
        }

        wk->dm_hos_flag = 1;
    }
}

void set_dm_hos_flag_grd(PLW *wk) {
    s16 disx;
    PLW *twk;

    twk = (PLW *)wk->wu.target_adrs;
    disx = wk->wu.xyz[0].disp.pos - twk->wu.xyz[0].disp.pos;

    if (disx < 0) {
        disx = -disx;
    }

    if (wk->wu.dm_work_id & 8) {
        if (disx < 0x81) {
            wk->dm_hos_flag = 1;
        }
    } else if (wk->wu.dm_work_id & 1 &&
               (twk->player_number != 0 || twk->wu.now_koc != 5 || twk->wu.char_index != 0x3B)) {
        wk->dm_hos_flag = 1;
    }
}

void get_sky_dm_timer(PLW *wk) {
    if (wk->wu.dm_zuru == 7) {
        wk->zuru_ix_counter = 0;
    } else {
        wk->zuru_ix_counter += sky_dm_zuru_ix[wk->wu.dm_zuru];
    }

    if (wk->zuru_ix_counter > 15) {
        wk->zuru_ix_counter = 15;
    }

    wk->zuru_timer = sky_dm_zuru_table[omop_otedama_ix[(wk->wu.id + 1) & 1]][wk->zuru_ix_counter];
}

void subtract_dm_vital(PLW *wk) {
    if (wk->dead_flag == 0) {
        if (wk->wu.dm_vital && (wk->wu.routine_no[1] != 1 || wk->wu.routine_no[2] > 11 || wk->wu.routine_no[3] != 0)) {
            Additinal_Score_DM((WORK_Other *)wk->wu.dmg_adrs, wk->wu.dm_ten_ix);
        }

        add_sp_arts_gauge_hit_dm(wk);

        if (wk->atemi_flag) {
            wk->dm_vital_backup = wk->wu.dm_vital;
        } else {
            wk->dm_vital_backup = 0;
        }

        wk->dm_vital_use = 0;

        if (omop_vital_ix[wk->wu.id] == 5) {
            wk->wu.dm_vital = 0;
        }

        wk->wu.vital_new -= wk->wu.dm_vital;

        if (wk->wu.dm_guard_success == -1 && wk->wu.vital_old > 0 && wk->wu.vital_new < 0 && wk->wu.vital_new > -3) {
            wk->wu.vital_new = 0;
        }

        if (wk->wu.dm_nodeathattack && wk->wu.vital_new < 0) {
            wk->wu.vital_new = 0;
        }

        if (wk->wu.vital_new < 0) {
            wk->wu.vital_new = -1;
            wk->dead_flag = 1;
            dead_voice_flag = 1;

            if (wk->wu.dm_guard_success != -1) {
                wk->kezurijini_flag = 1;
            }

            if (round_slow_flag == 0) {
                set_conclusion_slow();
                round_slow_flag = 1;
            }
        } else if (wk->py->flag == 0) {
            wk->py->now.quantity.h += wk->wu.dm_piyo;

            if (wk->py->now.quantity.h >= wk->py->genkai) {
                wk->py->now.timer = 0;
                wk->py->flag = 1;
            }
        }
    }

    if (wk->guard_chuu == 0) {
        switch (wk->wu.routine_no[2]) {
        case 1:
        case 2:
        case 3:
        case 0xC:
        case 0xD:
        case 0x13:
        case 0x10:
            break;

        default:
            pp_pulpara_remake_dm_all(&wk->wu);
            break;
        }
    }

    if (Mode_Type == 3 && (Training_ID != wk->wu.id)) {
        Training_Damage_Set(wk->wu.dm_vital, wk->wu.dm_piyo, wk->wu.kezurare_flag);
    }

    wk->wu.dm_vital = 0;
    wk->wu.dm_piyo = 0;
}

void subtract_dm_vital_aiuchi(PLW *wk) {
    if (wk->dead_flag == 0) {
        if (wk->wu.dm_vital && (wk->wu.routine_no[1] != 1 || wk->wu.routine_no[2] > 11 || wk->wu.routine_no[3] != 0)) {
            Additinal_Score_DM((WORK_Other *)wk->wu.dmg_adrs, wk->wu.dm_ten_ix);
        }

        if (wk->atemi_flag) {
            wk->dm_vital_backup = wk->wu.dm_vital;
        } else {
            wk->dm_vital_backup = 0;
        }

        wk->dm_vital_use = 0;

        if (omop_vital_ix[wk->wu.id] == 5) {
            wk->wu.dm_vital = 0;
        }

        wk->wu.vital_new -= wk->wu.dm_vital;

        if (wk->wu.dm_guard_success == -1 && wk->wu.vital_old > 0 && wk->wu.vital_new < 0 && wk->wu.vital_new > -3) {
            wk->wu.vital_new = 0;
        }

        if (wk->wu.dm_nodeathattack && wk->wu.vital_new < 0) {
            wk->wu.vital_new = 0;
        }

        if (wk->wu.vital_new < 0) {
            wk->wu.vital_new = -1;
            wk->dead_flag = 1;
            dead_voice_flag = 1;

            if (wk->wu.dm_guard_success != -1) {
                wk->kezurijini_flag = 1;
            }

            if (round_slow_flag == 0) {
                set_conclusion_slow();
                round_slow_flag = 1;
            }
        } else if (wk->py->flag == 0) {
            wk->py->now.quantity.h += wk->wu.dm_piyo;

            if (wk->py->now.quantity.h >= wk->py->genkai) {
                wk->py->now.timer = 0;
                wk->py->flag = 1;
            }
        }
    }

    pp_pulpara_remake_dm_all(&wk->wu);

    if (Mode_Type == 3 && (Training_ID != wk->wu.id)) {
        Training_Damage_Set(wk->wu.dm_vital, wk->wu.dm_piyo, wk->wu.kezurare_flag);
    }

    wk->wu.dm_vital = 0;
    wk->wu.dm_piyo = 0;
}

void get_damage_reaction_data(PLW *wk) {
    if (wk->atemi_flag == 2) {
        wk->wu.dm_vital = 0;
        damage_atemi_setup(wk, (PLW *)wk->wu.dmg_adrs);
        return;
    }

    subtract_dm_vital(wk);

    if (wk->wu.routine_no[2] == 0x58) {
        wk->wu.routine_no[2] = check_buttobi_type(wk);
    }

    if (wk->py->flag && wk->wu.routine_no[2] == 0x58) {
        wk->wu.routine_no[2] = 0x5B;
    }

    if (!(((PLW *)wk->wu.target_adrs)->spmv_ng_flag & 0x02000000) && wk->wu.routine_no[2] == 0x58) {
        wk->wu.routine_no[2] = 0x5B;
    }

    if (wk->dead_flag) {
        wk->wu.routine_no[2] = dd_convert[wk->wu.routine_no[2]][wk->wu.dm_attlv];
        if (wk->wu.routine_no[2] > 0x13 && wk->wu.routine_no[2] < 0x58 && wk->wu.routine_no[2] != 0x46) {
            wk->wu.routine_no[2] = check_buttobi_type2(wk);
        }
    }

    if (wk->atemi_flag == 1) {
        if (wk->py->flag) {
            wk->atemi_flag = 0;
        } else {
            damage_atemi_setup(wk, (PLW *)wk->wu.dmg_adrs);
            return;
        }
    }

    wk->as = &dm_reaction_table[wk->wu.routine_no[2]];
    wk->wu.routine_no[2] = wk->as->r_no;

    if (wk->wu.dm_stop) {
        if (wk->wu.dm_stop > 0) {
            wk->wu.dm_stop--;
        }

        if (wk->wu.dm_stop < 0) {
            wk->wu.dm_stop++;
        }
    }
}

void damage_atemi_setup(PLW *wk, PLW *ek) {
    wk->wu.routine_no[1] = wk->wu.cmmd.koc;
    wk->wu.routine_no[2] = wk->wu.cmmd.ix;
    wk->wu.routine_no[3] = wk->wu.cmmd.pat;
    char_move_cmms(&wk->wu);
    wk->atemi_flag = 9;
    wk->wu.dm_stop = wk->wu.dm_quake = 0;
    wk->wu.hit_stop = wk->wu.hit_quake = 0;
    ek->wu.dm_stop = ek->wu.dm_quake = 0;
    ek->wu.hit_stop = wk->wu.att.hs_you;
    ek->wu.hit_quake = wk->wu.att.hs_you / 2;
}

s32 setup_kuzureochi(PLW *wk) {
    if (wk->wu.vital_new >= 0) {
        return 0;
    }

    if (pcon_dp_flag && Conclusion_Type != 1 && wk->wu.id == Winner_id) {
        wk->wu.vital_new = 0;
        return 0;
    }

    wk->wu.routine_no[1] = 1;
    wk->wu.routine_no[2] = 0;
    wk->wu.routine_no[3] = 1;
    wk->zuru_timer = 0;
    wk->zuru_ix_counter = 0;
    set_char_move_init(&wk->wu, 1, 0x49);
    wk->wu.dm_stop = wk->wu.hit_stop = 0;
    wk->wu.dm_quake = wk->wu.hit_quake = 0;
    return 1;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPDM", setup_kuuchuu_nmdm);

void get_catch_off_data(PLW *wk, s16 ix) {
    wk->as = &dm_reaction_table[ix];
}

void check_bullet_damage(PLW *wk) {
    WORK *tk = (WORK *)wk->wu.dmg_adrs;

    if (tk->work_id != 1 && tk->id == 0xD && tama_select[tk->type] != 0) {
        wk->bullet_hcnt += tama_select[tk->type];
        wk->bhcnt_timer = 0x320;
    }
}
