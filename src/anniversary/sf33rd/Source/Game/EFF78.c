#include "sf33rd/Source/Game/EFF78.h"
#include "common.h"
#include "sf33rd/Source/Game/CALDIR.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_78_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll && crow_fuss_check(ewk)) {
            char_move(&ewk->wu);
        }

        disp_pos_trans_entry(ewk);
        break;

    case 2:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            crow_fuss_move(ewk);
        }

        disp_pos_trans_entry(ewk);
        break;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 crow_fuss_check(WORK_Other *ewk) {
    s16 work;

    if (bg_w.quake_y_index > 3) {
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.direction = 0;

        work = plw[0].wu.xyz[0].disp.pos + plw[1].wu.xyz[0].disp.pos;
        work >>= 1;
        work = ewk->wu.xyz[0].disp.pos - work;

        if (work > 64) {
            ewk->wu.direction = 2;
        } else if (work < -64) {
            ewk->wu.direction = 1;
        }

        return 0;
    }
    return 1;
}

const s16 eff78_data_tbl[4] = { 0x1A0, 0x047, 0x390, 0x040 };

const s16 crow_char_tbl[3][3] = { { 8, 0, 64 }, { 18, -16, 64 }, { 13, 16, 64 } };

void crow_fuss_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch ((ewk->wu.routine_no[1])) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[0] = crow_char_tbl[ewk->wu.direction][0];
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, (ewk->wu.old_rno[0]) + 1);
            ewk->wu.dir_timer = 0x1C;
            ewk->wu.old_rno[1] = ewk->wu.xyz[0].disp.pos + crow_char_tbl[ewk->wu.direction][1];
            ewk->wu.old_rno[2] = ewk->wu.xyz[1].disp.pos + crow_char_tbl[ewk->wu.direction][2];
            cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.old_rno[1], ewk->wu.old_rno[2], 2, 2);
        }

        break;

    case 2:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer < 1) {
            ewk->wu.routine_no[1]++;
            ewk->wu.dir_timer = 4;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 2);
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }

        break;

    case 3:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer < 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 4:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 3);
            ewk->wu.dir_timer = 0x30;
            ewk->wu.old_rno[1] = eff78_data_tbl[ewk->wu.type << 1];
            ewk->wu.old_rno[2] = eff78_data_tbl[(ewk->wu.type << 1) + 1];
            cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.old_rno[1], ewk->wu.old_rno[2] + 4, 0, 0);
        }

        break;

    case 5:
        ewk->wu.dir_timer--;
        add_x_sub(ewk);
        add_y_sub(ewk);
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 2) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 6:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer < 1) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[1];
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 4);
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }

        break;

    case 7:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0] = 1;
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF78", effect_78_init);
#else
s32 effect_78_init() {
    not_implemented(__func__);
}
#endif
