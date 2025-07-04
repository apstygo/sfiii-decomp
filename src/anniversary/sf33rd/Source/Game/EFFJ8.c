#include "sf33rd/Source/Game/EFFJ8.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/eff05.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_J8_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    if (obr_no_disp_check() == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0] += 1;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            break;

        case 1:
            if (compel_dead_check(ewk)) {
                ewk->wu.routine_no[0] += 1;
                ewk->wu.disp_flag = 0;
                break;
            }

            if (!EXE_flag && !Game_pause && !EXE_obroll) {
                dragonfly_move(ewk);
            }

            disp_pos_trans_entry(ewk);
            break;

        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}

void dragonfly_move(WORK_Other *ewk) {
    void (*const dragonfly_move_jp1[8])(WORK_Other *) = { dragonfly_move_0000, dragonfly_move_0001, dragonfly_r_move,
                                                          dragonfly_l_move,    dragonfly_move_0004, dragonfly_move_0005,
                                                          dragonfly_l_move,    dragonfly_r_move };
    dragonfly_move_jp1[ewk->wu.routine_no[1]](ewk);
}

void dragonfly_l_move_0(WORK_Other *ewk) {
    s16 work;
    ewk->wu.rl_flag = 1;
    ewk->wu.xyz[0].disp.pos = (s16)(bg_w.bgw[1].r_limit2 + bg_w.pos_offset + 0x20);
    work = random_16();
    work &= 7;
    ewk->wu.xyz[1].disp.pos = effj8_y_tbl[work];
    ewk->wu.xyz[1].disp.low = 0;
}

void dragonfly_l_move_1(WORK_Other *ewk) {
    char_move(&ewk->wu);
    dragonfly_line_set(ewk, 0);
}

s16 dragonfly_l_move_2(WORK_Other *ewk) {
    char_move(&ewk->wu);
    add_x_sub(ewk);
    add_y_sub(ewk);

    if (!(ewk->wu.xyz[0].disp.pos > bg_w.bgw[1].l_limit2 - bg_w.pos_offset + -0x18)) {
        dragonfly_stop_timer(ewk);
        return 0x63;
    }

    if (ewk->wu.mvxy.a[0].sp < -196607) {
        return 1;
    }

    return 0;
}

s16 dragonfly_l_move_3(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    add_x_sub(ewk);
    add_y_sub(ewk);

    if (!(ewk->wu.xyz[0].disp.pos > bg_w.bgw[1].l_limit2 - bg_w.pos_offset + -0x18)) {
        dragonfly_stop_timer(ewk);
        set_char_move_init(&ewk->wu, 0, 6);
        return 0x63;
    }

    if (ewk->wu.mvxy.a[0].sp >= 0) {
        dragonfly_stop_timer(ewk);
        set_char_move_init(&ewk->wu, 0, 6);
        return 1;
    }

    return 0;
}

s16 dragonfly_l_move_4(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    char_move(&ewk->wu);
    ewk->wu.dir_timer--;

    if (ewk->wu.dir_timer <= 0) {
        set_char_move_init(&ewk->wu, 0, 4);
        return 1;
    }

    return 0;
}

void dragonfly_l_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        dragonfly_l_move_0(ewk);
        /* fallthrough */

    case 1:
        ewk->wu.routine_no[2]++;
        dragonfly_l_move_1(ewk);
        break;

    case 2:
        ewk->wu.routine_no[2] += dragonfly_l_move_2(ewk);
        break;

    case 3:
        ewk->wu.routine_no[2] += dragonfly_l_move_3(ewk);
        break;

    case 4:
        char_move(&ewk->wu);

        if (dragonfly_l_move_4(ewk)) {
            ewk->wu.routine_no[2] = 1;
            break;
        }

        break;

    default:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

void dragonfly_r_move_0(WORK_Other *ewk) {
    s16 work;

    ewk->wu.rl_flag = 0;
    ewk->wu.xyz[0].disp.pos = (s16)(bg_w.bgw[1].l_limit2 - bg_w.pos_offset - 0x20);
    work = random_16();
    work &= 7;
    ewk->wu.xyz[1].disp.pos = effj8_y_tbl[work];
    ewk->wu.xyz[1].disp.low = 0;
}

void dragonfly_r_move_1(WORK_Other *ewk) {
    char_move(&ewk->wu);
    dragonfly_line_set(ewk, 1);
}

s16 dragonfly_r_move_2(WORK_Other *ewk) {
    char_move(&ewk->wu);
    add_x_sub(ewk);
    add_y_sub(ewk);
    if (ewk->wu.xyz[0].disp.pos > bg_w.bgw[1].r_limit2 + bg_w.pos_offset + 0x18) {
        dragonfly_stop_timer(ewk);
        return 0x63;
    }
    if (ewk->wu.mvxy.a[0].sp < 196609) {
        return 1;
    }
    return 0;
}

s16 dragonfly_r_move_3(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    add_x_sub(ewk);
    add_y_sub(ewk);
    if (ewk->wu.xyz[0].disp.pos >= bg_w.bgw[1].r_limit2 + bg_w.pos_offset + 0x18) {
        dragonfly_stop_timer(ewk);
        set_char_move_init(&ewk->wu, 0, 6);
        return 0x63;
    }
    if (ewk->wu.mvxy.a[0].sp <= 0) {
        dragonfly_stop_timer(ewk);
        set_char_move_init(&ewk->wu, 0, 6);
        return 1;
    }
    return 0;
}

s16 dragonfly_r_move_4(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    char_move(&ewk->wu);
    ewk->wu.dir_timer--;

    if (ewk->wu.dir_timer <= 0) {
        set_char_move_init(&ewk->wu, 0, 4);
        return 1;
    }

    return 0;
}

void dragonfly_r_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        dragonfly_r_move_0(ewk);
        /* fallthrough */

    case 1:
        ewk->wu.routine_no[2]++;
        dragonfly_r_move_1(ewk);
        break;

    case 2:
        ewk->wu.routine_no[2] += dragonfly_r_move_2(ewk);
        break;

    case 3:
        ewk->wu.routine_no[2] += dragonfly_r_move_3(ewk);
        break;

    case 4:
        char_move(&ewk->wu);

        if (dragonfly_r_move_4(ewk)) {
            ewk->wu.routine_no[2] = 1;
        }

        break;
    default:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

void dragonfly_move_0000(WORK_Other *ewk) {
    char_move(&ewk->wu);

    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.rl_flag = 1;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].r_limit2 + bg_w.pos_offset + 32;
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[1].disp.pos = 0x6B;
        ewk->wu.xyz[1].disp.low = 0;
        dragonfly_stop_timer(ewk);
        break;

    case 1:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[2]++;
            ewk->wu.dir_timer = 0x96;
            ewk->wu.mvxy.a[0].sp = -0x32C5F;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = -0x1B4E;
            ewk->wu.mvxy.d[1].sp = 0;
        }
        break;

    case 2:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            ewk->wu.xyz[0].disp.pos = 0x200;
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = 0x5B;
            ewk->wu.xyz[1].disp.low = 0;
            break;
        }

        add_x_sub(ewk);
        add_y_sub(ewk);
        break;
    }
}

const s16 effj8_timer_tbl[8] = { 60, 120, 180, 90, 150, 30, 220, 160 };

const s16 effj8_y_tbl[8] = { 128, 80, 96, 160, 176, 112, 144, 168 };

void dragonfly_move_0001(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        char_move(&ewk->wu);
        ewk->wu.routine_no[2]++;
        ewk->wu.rl_flag = 1;
        dragonfly_stop_timer(ewk);
        break;

    case 1:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[2]++;
            break;
        }

        break;

    case 2:
        ewk->wu.routine_no[2]++;
        dragonfly_l_move_1(ewk);
        /* fallthrough */

    case 3:
        ewk->wu.routine_no[2] += dragonfly_l_move_2(ewk);
        break;

    case 4:
        ewk->wu.routine_no[2] += dragonfly_l_move_3(ewk);
        break;

    case 5:
        char_move(&ewk->wu);

        if (dragonfly_l_move_4(ewk)) {
            ewk->wu.routine_no[2] = 2;
            break;
        }

        break;

    default:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

void dragonfly_move_0004(WORK_Other *ewk) {
    char_move(&ewk->wu);

    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.rl_flag = 0;
        dragonfly_stop_timer(ewk);
        break;

    case 1:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[2]++;
            ewk->wu.dir_timer = 0xB4;
            ewk->wu.mvxy.a[0].sp = 0x364FA;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = -0x27D2;
            ewk->wu.mvxy.d[1].sp = 0;
        }

        break;

    case 2:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            ewk->wu.xyz[0].disp.pos = 0x273;
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = 0x5C;
            ewk->wu.xyz[1].disp.low = 0;
            break;
        }

        add_x_sub(ewk);
        add_y_sub(ewk);
        break;
    }
}

void dragonfly_move_0005(WORK_Other *ewk) {
    char_move(&ewk->wu);

    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.rl_flag = 0;
        dragonfly_stop_timer(ewk);
        break;

    case 1:
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[2]++;
            break;
        }
        break;

    case 2:
        ewk->wu.routine_no[2]++;
        dragonfly_r_move_1(ewk);
        break;

    case 3:
        ewk->wu.routine_no[2] += dragonfly_r_move_2(ewk);
        break;

    case 4:
        ewk->wu.routine_no[2] += dragonfly_r_move_3(ewk);
        break;

    case 5:
        char_move(&ewk->wu);

        if (dragonfly_r_move_4(ewk)) {
            ewk->wu.routine_no[2] = 2;
            break;
        }

        break;

    default:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

void dragonfly_stop_timer(WORK_Other *ewk) {
    s16 work = random_16();

    work &= 7;
    ewk->wu.dir_timer = effj8_timer_tbl[work];
}

void dragonfly_line_set(WORK_Other *ewk, s16 dir_type) {
    s16 work = random_16();
    const s32 *sp_ptr;

    work &= 7;
    sp_ptr = &effj8_sp_tbl[work][0];

    if (dir_type) {
        ewk->wu.mvxy.a[0].sp = *sp_ptr++;
        ewk->wu.mvxy.d[0].sp = *sp_ptr++;
    } else {
        ewk->wu.mvxy.a[0].sp = -*sp_ptr++;
        ewk->wu.mvxy.d[0].sp = -*sp_ptr++;
    }

    ewk->wu.xyz[0].disp.low = 0;
    ewk->wu.mvxy.a[1].sp = *sp_ptr++;
    ewk->wu.mvxy.d[1].sp = *sp_ptr++;
}

void dragonfly_move_next(WORK_Other *ewk) {
    ewk->wu.routine_no[1] += 1;
    ewk->wu.routine_no[1] &= 7;
    ewk->wu.routine_no[2] = 0;
    ewk->wu.routine_no[3] = 0;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ8", effect_J8_init);
#else
s32 effect_J8_init() {
    not_implemented(__func__);
}
#endif

const s32 effj8_sp_tbl[8][4] = {
    { 0x00060000, 0xFFFFC000, 0x00004000, 0x00000000 }, { 0x00060000, 0xFFFFB800, 0xFFFFC000, 0x00000000 },
    { 0x00060000, 0xFFFFF000, 0x00004000, 0x00000000 }, { 0x00060000, 0xFFFFE000, 0xFFFFC000, 0x00000000 },
    { 0x00080000, 0xFFFF6000, 0x00004000, 0x00000000 }, { 0x00080000, 0xFFFFE000, 0xFFFFC000, 0x00000000 },
    { 0x00080000, 0xFFFFA000, 0x00004000, 0x00000000 }, { 0x00080000, 0xFFFFC000, 0xFFFFC000, 0x00000000 }
};
