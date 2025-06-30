#include "sf33rd/Source/Game/eff94.h"
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

void effect_94_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    void (*const eff94_move_jp[5])(WORK_Other *) = {
        eff94_0000, eff94_1000, eff94_2000, eff94_3000, eff94_4000,
    };

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff94_move_jp[ewk->wu.routine_no[1]](ewk);
        }

        if (ewk->wu.old_rno[1]) {
            disp_pos_trans_entry_r(ewk);
            break;
        }

        disp_pos_trans_entry(ewk);
        break;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff94_0000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (bg_w.quake_y_index > 3) {
            ewk->wu.routine_no[2]++;
        }
        break;

    case 1:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[2]);
        break;

    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2] = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        }
        break;
    }
}

void eff94_1000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (bg_w.quake_y_index > 3) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[2]);
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            if (ewk->wu.xyz[0].disp.pos >= 0x1C4) {
                ewk->wu.routine_no[2]++;
                set_char_move_init(&ewk->wu, 0, 0x2F);
                ewk->wu.mvxy.a[0].sp = 0x8000;
                ewk->wu.mvxy.a[1].sp = 0;
                ewk->wu.mvxy.d[0].sp = 0;
                ewk->wu.mvxy.d[1].sp = -0x6000;
                break;
            }

            ewk->wu.routine_no[2] = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
            return;
        }

        break;

    case 2:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);

        if (ewk->wu.xyz[1].disp.pos < 0xB) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, 0x30);
            ewk->wu.xyz[0].disp.pos += 2;
            ewk->wu.old_rno[1] = 0;
            break;
        }

        break;

    case 3:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2]++;
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
        }

        break;
    }
}

void eff94_2000(WORK_Other *ewk) {
    void (*const eff94_2000_jp[5])(
        WORK_Other *) = { eff94_2000_0, eff94_2000_1, eff94_2000_2, eff94_2000_3, eff94_2000_4 };
    eff94_2000_jp[ewk->wu.routine_no[2]](ewk);
}

void eff94_2000_0(WORK_Other *ewk) {
    ewk->wu.disp_flag = 0;

    if (bg_w.quake_y_index > 3) {
        ewk->wu.routine_no[2] += 1;

        if (bg_w.quake_y_index >= 0x18) {
            ewk->wu.old_rno[3] = 1;
            return;
        }

        ewk->wu.old_rno[3] = 0;
    }
}

void eff94_2000_1(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    s16 work;

    ewk->wu.routine_no[2] += 1;
    set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
    ewk->wu.disp_flag = 1;
    work = random_16();

    if (eff94_2000_1_tbl[work]) {
        ewk->wu.routine_no[2] = 4;
        ewk->wu.dir_timer = 8;
        return;
    }

    if (work == 7 && ewk->wu.old_rno[3]) {
        effect_94_init(4);
        effect_94_init(4);
        effect_94_init(4);
    }

    work &= 7;
    ewk->wu.xyz[0].disp.pos = eff94_2000_tbl[work];
    ewk->wu.xyz[1].cal = 0x01100000;
    ewk->wu.mvxy.a[1].sp = -0x68000;
    ewk->wu.mvxy.d[1].sp = -0x6000;
}

void eff94_2000_2(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    add_y_sub(ewk);

    if (ewk->wu.xyz[1].disp.pos < 17) {
        ewk->wu.routine_no[2]++;
        ewk->wu.xyz[1].disp.pos = 16;
        set_char_move_init(&ewk->wu, 0, 3);
    }
}

void eff94_2000_3(WORK_Other *ewk) {
    char_move(&ewk->wu);

    if ((ewk->wu.xyz[0].disp.pos <= bg_w.bgw[1].l_limit2 - bg_w.pos_offset) ||
        ewk->wu.xyz[0].disp.pos >= bg_w.bgw[1].r_limit2 + bg_w.pos_offset) {
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 0;
        ewk->wu.dir_timer = 4;
    }
}

void eff94_2000_4(WORK_Other *ewk) {
    ewk->wu.dir_timer--;

    if (ewk->wu.dir_timer <= 0) {
        ewk->wu.routine_no[2] = 0;
    }
}

void eff94_3000(WORK_Other *ewk) {
    void (*const eff94_2000_jp[4])(WORK_Other *) = { eff94_3000_0, eff94_2000_2, eff94_2000_3, eff94_3000_4 };
    eff94_2000_jp[ewk->wu.routine_no[2]](ewk);
}

void eff94_3000_0(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    s16 work;

    ewk->wu.routine_no[2]++;
    set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
    ewk->wu.disp_flag = 1;
    work = random_16();
    work &= 3;
    ewk->wu.xyz[0].disp.pos = *eff94_3000_tbl[work];
    ewk->wu.xyz[1].disp.pos = eff94_3000_tbl[work][1];
    ewk->wu.rl_flag = eff94_3000_tbl[work][2];
    ewk->wu.mvxy.a[1].sp = -0x68000;
    ewk->wu.mvxy.d[1].sp = -0x6000;
}

void eff94_3000_4(WORK_Other *ewk) {
    ewk->wu.routine_no[0] = 0x63;
}

void eff94_4000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (bg_w.quake_y_index > 3) {
            ewk->wu.routine_no[2]++;
        }

        break;

    case 1:
        ewk->wu.routine_no[2] += 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[2]);
        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 9) {
            if (bg_w.quake_y_index > 3) {
                ewk->wu.routine_no[2] = 1;
                break;
            }
        } else if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2] = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        }

        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff94", effect_94_init);
#else
s32 effect_94_init(u8 type94) {
    not_implemented(__func__);
}
#endif

const s16 eff94_data_tbl[5][10] = {
    { 0x0002, 0x212C, 0x0188, 0x0040, 0x000C, 0x0016, 0x0034, 0x0000, 0x0000, 0x0001 },
    { 0x0002, 0x212C, 0x0198, 0x004B, 0x000B, 0x0017, 0x0035, 0x0000, 0x0001, 0x0001 },
    { 0x0002, 0x212C, 0x0280, 0x0010, 0x000A, 0x0009, 0x000A, 0x0000, 0x0004, 0x0001 },
    { 0x0002, 0x212C, 0x0160, 0x0110, 0x000A, 0x0002, 0x0002, 0x0000, 0x0002, 0x0001 },
    { 0x0002, 0x212C, 0x0160, 0x0110, 0x000A, 0x0002, 0x0002, 0x0000, 0x0003, 0x0000 }
};

const s16 eff94_2000_tbl[8] = { 0x0120, 0x0150, 0x0140, 0x0120, 0x0148, 0x0128, 0x0158, 0x0130 };

const s8 eff94_2000_1_tbl[16] = { 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1 };

const s16 eff94_3000_tbl[4][3] = {
    { 0x0148, 0x0130, 0x0000 }, { 0x0120, 0x00F0, 0x0001 }, { 0x0118, 0x0140, 0x0000 }, { 0x0160, 0x0108, 0x0001 }
};
