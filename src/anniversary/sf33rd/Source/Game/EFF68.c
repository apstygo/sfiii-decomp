#include "sf33rd/Source/Game/EFF68.h"
#include "common.h"
#include "sf33rd/Source/Game/CALDIR.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_68_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        disp_pos_trans_entry(ewk);
        break;

    case 1:
        if (!EXE_flag && !Game_pause && ((ewk->wu.routine_no[4]--), (ewk->wu.routine_no[4]) < 1)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.routine_no[4] = 0x32;
            cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[2], ewk->wu.old_rno[3], 1, 1);
            ewk->wu.char_index = ewk->wu.routine_no[6];
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }

        disp_pos_trans_entry(ewk);
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[4]--;
            if (ewk->wu.routine_no[4] < 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.routine_no[4] = 0x32;
                cal_delta_speed(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[4], ewk->wu.old_rno[5], 2, 2);
                ewk->wu.char_index = ewk->wu.routine_no[6];
                set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            }
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        disp_pos_trans_entry(ewk);
        break;

    case 3:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[4]--;
            if (ewk->wu.routine_no[4] < 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.routine_no[4] = 0x28;
                cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[6], ewk->wu.old_rno[7], 1, 1);
            }
            add_x_sub(ewk);
            add_y_sub(ewk);
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry(ewk);
        break;

    case 4:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[4]--;

            if (ewk->wu.routine_no[4] < 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.routine_no[4] = 0x3C;
                cal_delta_speed(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[0], ewk->wu.old_rno[1], 2, 2);
                ewk->wu.char_index = ewk->wu.routine_no[5];
                set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            }

            add_x_sub(ewk);
            add_y_sub(ewk);
            char_move(&ewk->wu);
        }

        disp_pos_trans_entry(ewk);
        break;

    case 5:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[4]--;
            if (ewk->wu.routine_no[4] < 1) {
                ewk->wu.routine_no[0] = 2;
                ewk->wu.routine_no[4] = 0x32;
                cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[2], ewk->wu.old_rno[3], 1, 1);
                ewk->wu.char_index = ewk->wu.routine_no[6];
                set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            }
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        disp_pos_trans_entry(ewk);
        break;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF68", effect_68_init);
#else
s32 effect_68_init() {
    not_implemented(__func__);
}
#endif

const s16 eff68_data_tbl[52] = { 0x002, 0x1B0, 0x0C0, 0x1F8, 0x0B4, 0x240, 0x0AC, 0x20A, 0x0A0, 0x008, 0x009,
                                 0x049, 0x000, 0x002, 0x250, 0x0D0, 0x298, 0x0C4, 0x2E0, 0x0BC, 0x2AA, 0x0B0,
                                 0x008, 0x009, 0x049, 0x014, 0x003, 0x2E0, 0x0A0, 0x328, 0x094, 0x370, 0x08C,
                                 0x33A, 0x080, 0x00A, 0x00B, 0x053, 0x032, 0x003, 0x270, 0x0C0, 0x2B8, 0x0B4,
                                 0x300, 0x0AC, 0x2CA, 0x0A0, 0x00A, 0x00B, 0x053, 0x028 };
