#include "sf33rd/Source/Game/EFF85.h"
#include "common.h"
#include "sf33rd/Source/Game/CALDIR.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_85_move(WORK_Other *ewk) {
    void (*const eff85_jp_tbl[3])(WORK_Other *) = { eff85_0000, eff85_0100, eff85_0200 };
    eff85_jp_tbl[ewk->wu.routine_no[0]](ewk);
};

void eff85_0000(WORK_Other *ewk) {
    ewk->wu.routine_no[0]++;
    ewk->wu.routine_no[1] = 0;
    ewk->wu.routine_no[2] = 0;
    ewk->wu.rl_flag = 0;
    ewk->wu.old_rno[0] = 0;
}

void eff85_0100(WORK_Other *ewk) {
    void (*const eff85_move_tbl[9])(WORK_Other *) = { eff85_1000,   eff85_common, eff85_3000, eff85_common, eff85_5000,
                                                      eff85_common, eff85_7000,   eff85_8000, eff85_9000 };
    if (!EXE_flag && !Game_pause && !EXE_obroll) {
        eff85_move_tbl[ewk->wu.routine_no[1]](ewk);
    }
    disp_pos_trans_entry(ewk);
}

void eff85_1000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;

        if (ewk->wu.old_rno[0]) {
            set_char_move_init(&ewk->wu, 0, 0x2C);
        } else {
            set_char_move_init(&ewk->wu, 0, 0x1C);
        }

        ewk->wu.old_rno[0]++;
        ewk->wu.old_rno[0] &= 1;
        ewk->wu.xyz[0].cal = 0x01EB0000;
        ewk->wu.xyz[1].cal = 0x2C0000;
        break;

    case 1:
        if (swallow_sprize_check(ewk) != 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                ewk->wu.routine_no[2] = 0;
            }
        }

        break;
    }
}

void eff85_common(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, *(&eff85_char_index_tbl[ewk->wu.routine_no[1]]));
        break;

    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}

void eff85_3000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, 0x1F);
        ewk->wu.dir_timer = 0x22;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x2000;
        cal_initial_speed(&ewk->wu, ewk->wu.dir_timer, 0x190, 0x51);
        break;

    case 1:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.xyz[0].cal = 0x01900000;
            ewk->wu.xyz[1].cal = 0x510000;
            return;
        }

        add_x_sub(ewk);
        add_y_sub(ewk);
        break;
    }
}

void eff85_5000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, *(&eff85_char_index_tbl[ewk->wu.routine_no[1]]));
        break;

    case 1:
        if (swallow_sprize_check(ewk) != 0) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                ewk->wu.routine_no[2] = 0;
            }
        }
        break;
    }
}

void eff85_7000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, 0x22);
        ewk->wu.dir_timer = 0x6E;
        cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, 0x1EB, 0x2C, 2, 0);
        break;

    case 1:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.xyz[0].cal = 0x01EB0000;
            ewk->wu.xyz[1].cal = 0x2C0000;
            return;
        }

        add_x_sub(ewk);
        add_y_sub(ewk);
        break;
    }
}

void eff85_8000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, 0x23);
        break;

    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}

void eff85_9000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;

        if (ewk->wu.cg_flip == 0) {
            ewk->wu.mvxy.a[0].sp = 0xFFFB0000;
            ewk->wu.mvxy.a[1].sp = 0xC000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, 0x2D);
        } else {
            ewk->wu.mvxy.a[0].sp = 0x50000;
            ewk->wu.mvxy.a[1].sp = 0xC000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, 0x2E);
        }
        break;

    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);

        if (ewk->wu.xyz[0].disp.pos >= bg_w.bgw[1].l_limit2 - bg_w.pos_offset &&
            !(ewk->wu.xyz[0].disp.pos > bg_w.bgw[1].r_limit2 + bg_w.pos_offset)) {
            return;
        }

        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 0;
        break;

    case 2:
        if (bg_w.bgw[1].wxy[0].disp.pos > 0x2D0) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}

s32 swallow_sprize_check(WORK_Other *ewk) {
    if (bg_w.quake_y_index > 3) {
        ewk->wu.routine_no[1] = 8;
        ewk->wu.routine_no[2] = 0;
        return 0;
    }
    return 1;
}

void eff85_0200(WORK_Other *ewk) {
    all_cgps_put_back(&ewk->wu);
    push_effect_work(&ewk->wu);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF85", effect_85_init);
#else
s32 effect_85_init() {
    not_implemented(__func__);
}
#endif

const s16 eff85_char_index_tbl[9] = { 0x0000, 0x001E, 0x0000, 0x0020, 0x001D, 0x0021, 0x0000, 0x0000, 0x0000 };
