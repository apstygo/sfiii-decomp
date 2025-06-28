#include "sf33rd/Source/Game/EFF24.h"
#include "common.h"
#include "sf33rd/Source/Game/CALDIR.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_24_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = 0;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff24_quake_sub(ewk);
        }

        if (ewk->wu.old_rno[7]) {
            disp_pos_trans_entry_r(ewk);
            return;
        }

        disp_pos_trans_entry(ewk);
        break;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}

void eff24_quake_sub(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (bg_w.quake_y_index > 0) {
            ewk->wu.routine_no[1]++;
            eff24_sp_data_set(ewk);
            return;
        }

        break;

    case 1:
        add_x_sub(ewk);
        add_y_sub(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            ewk->wu.xyz[1].disp.low = 0;
            eff24_sp_data_set(ewk);
            return;
        }

        break;

    case 2:
        add_x_sub(ewk);
        add_y_sub(ewk);
        ewk->wu.old_rno[5]--;
        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[4];
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            ewk->wu.xyz[1].disp.low = 0;

            if (ewk->wu.type == 0 && ewk->wu.old_rno[1] > 2) {
                ewk->wu.routine_no[1]++;
                dog24_data_set(ewk);
                if (ewk->wu.old_rno[6]) {
                    set_char_move_init(&ewk->wu, 0, 0xE);
                } else {
                    set_char_move_init(&ewk->wu, 0, 0xD);
                }
                ewk->wu.old_rno[6] ^= 1;
                return;
            }

            ewk->wu.routine_no[1] = 0;
            ewk->wu.old_rno[1] = 0;
            ewk->wu.old_rno[0] = 0;
            return;
        }
        break;

    case 3:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        ewk->wu.old_rno[5]--;

        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[1]++;
        case 4:
            char_move(&ewk->wu);
            add_x_sub(ewk);

            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[1] = 0;
                ewk->wu.old_rno[1] = 0;
                ewk->wu.old_rno[0] = 0;
                ewk->wu.old_rno[4] = ewk->wu.xyz[0].disp.pos;
                ewk->wu.xyz[0].disp.low = 0;
                ewk->wu.old_rno[2] = ewk->wu.xyz[1].disp.pos;
                ewk->wu.xyz[1].disp.low = 0;
            }
        }
        break;
    }
}

void dog24_data_set(WORK_Other *ewk) {
    s16 work;

    ewk->wu.old_rno[5] = 0x28;

    if (ewk->wu.old_rno[6]) {
        work = ewk->wu.xyz[0].disp.pos + *(&dog24_x_data[ewk->wu.old_rno[1]]);
    } else {
        work = ewk->wu.xyz[0].disp.pos - *(&dog24_x_data[ewk->wu.old_rno[1]]);
    }

    cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[5], work, ewk->wu.xyz[1].disp.pos, 2, 0);
}

void eff24_sp_data_set(WORK_Other *ewk) {
    s16 work;

    if (ewk->wu.old_rno[0]) {
        ewk->wu.old_rno[5] = 0xC;
        ewk->wu.mvxy.d[0].sp = 0;

        switch (ewk->wu.old_rno[1]) {
        case 0:

        case 1:
            ewk->wu.mvxy.d[1].sp = -0x2000;
            break;

        case 2:

        case 3:
            ewk->wu.mvxy.d[1].sp = -0x4000;
            break;

        default:
            ewk->wu.mvxy.d[1].sp = -0x5000;
            break;
        }

        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[5], ewk->wu.old_rno[4], ewk->wu.old_rno[2]);
    } else {
        ewk->wu.old_rno[1] = eff24_quake_index_tbl[bg_w.quake_y_index];
        ewk->wu.mvxy.a[0].sp = eff24_quake_speed_x_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        ewk->wu.mvxy.d[0].sp = 0;
        work = random_16();

        if (work & 1) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }

        ewk->wu.mvxy.a[1].sp = eff24_quake_speed_y_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        ewk->wu.mvxy.d[1].sp = -0x6000;
    }

    ewk->wu.old_rno[0]++;
    ewk->wu.old_rno[0] &= 1;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF24", effect_24_init);
#else
s32 effect_24_init() {
    not_implemented(__func__);
}
#endif

const s16 eff24_data_tbl[56] = { 0x212C, 0x01E0, 0x0006, 0x000A, 0x000C, 0x0002, 0x0000, 0x012C, 0x00E0, 0x002B,
                                 0x0051, 0x0003, 0x0001, 0x0001, 0x012C, 0x0120, 0x002C, 0x0050, 0x0004, 0x0002,
                                 0x0001, 0x012C, 0x0200, 0x0030, 0x0050, 0x0005, 0x0001, 0x0000, 0x212C, 0x0200,
                                 0x0030, 0x0050, 0x0006, 0x0002, 0x0000, 0x012C, 0x0284, 0x0030, 0x0050, 0x0007,
                                 0x0001, 0x0001, 0x012C, 0x02F0, 0x0030, 0x0051, 0x0008, 0x0003, 0x0001, 0x012C,
                                 0x0320, 0x0020, 0x0050, 0x0009, 0x0003, 0x0001 };

const s16 eff24_quake_index_tbl[111] = { 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 7, 7, 7,
                                         7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
                                         7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
                                         7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
                                         7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 };

const s32 eff24_quake_speed_y_tbl[4][8] = {
    { 0x10000, 0x20000, 0x30000, 0x40000, 0x50000, 0x60000, 0x70000, 0xC0000 },
    { 0x0E000, 0x10000, 0x1C000, 0x24000, 0x30000, 0x48000, 0x60000, 0x80000 },
    { 0x0C000, 0x0E000, 0x10000, 0x18000, 0x20000, 0x30000, 0x48000, 0x60000 },
    { 0x02000, 0x08000, 0x0C000, 0x10000, 0x18000, 0x20000, 0x30000, 0x60000 }
};

const s32 eff24_quake_speed_x_tbl[4][8] = {
    { 0x01200, 0x01200, 0x01400, 0x01400, 0x01000, 0x01200, 0x01200, 0x01400 },
    { 0x01800, 0x01800, 0x01400, 0x01400, 0x01000, 0x01800, 0x01400, 0x01400 },
    { 0x01000, 0x01000, 0x00800, 0x00800, 0x00800, 0x00800, 0x00400, 0x00400 },
    { 0x00400, 0x00400, 0x00800, 0x00800, 0x00400, 0x00400, 0x00400, 0x00400 }
};

const s16 dog24_x_data[8] = { 0, 0, 0, 6, 10, 16, 32, 40 };
