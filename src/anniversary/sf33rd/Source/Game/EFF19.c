#include "sf33rd/Source/Game/EFF19.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_19_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    if (obr_no_disp_check() == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, 6);
            break;

        case 1:
            if (!EXE_flag && !Game_pause && !EXE_obroll) {
                eff19_quake_sub(ewk);
            }
            disp_pos_trans_entry_r(ewk);
            break;

        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}

void eff19_quake_sub(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    s16 work;
    s8 fall_go;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (bg_w.quake_y_index > 2) {
            work = random_16();

            if (bg_w.quake_y_index < 8) {
                fall_go = effect_19_s_tbl[work];
            } else if (bg_w.quake_y_index > 14) {
                fall_go = effect_19_l_tbl[work];
            } else {
                fall_go = effect_19_m_tbl[work];
            }

            if (fall_go) {
                ewk->wu.routine_no[1]++;
                ewk->wu.routine_no[2] = 0;
                ewk->wu.mvxy.a[1].sp = 0;
                ewk->wu.mvxy.d[1].sp = -0x6000;
                ewk->wu.old_rno[0] = eff19_wait_tbl[work];
                break;
            }

            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.old_rno[0] = 0x3C;
        }

        break;

    case 1:
        if (ewk->wu.routine_no[2]) {
            ewk->wu.old_rno[0]--;

            if (!(ewk->wu.old_rno[0] < 0)) {
                break;
            }

            ewk->wu.routine_no[1] = 0;
            set_char_move_init(&ewk->wu, 0, 6);
            break;
        }

        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        add_y_sub(ewk);

        if (ewk->wu.xyz[1].disp.pos < 0x42) {
            ewk->wu.routine_no[1]++;
            break;
        }

        break;

    case 3:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        break;

    case 4:
        if (!range_x_check(ewk)) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.disp_flag = 1;
            ewk->wu.xyz[1].disp.pos = eff19_data_tbl[(ewk->wu.type * 2) + 1];
            set_char_move_init(&ewk->wu, 0, 6);
        }

        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF19", effect_19_init);
#else
s32 effect_19_init() {
    not_implemented(__func__);
}
#endif

const s16 eff19_data_tbl[14] = { 0x0180, 0x00C0, 0x0100, 0x00C4, 0x01A0, 0x00F0, 0x0148,
                                 0x0120, 0x0178, 0x0100, 0x01C4, 0x00FC, 0x00CE, 0x00D2 };

const s8 eff19_wait_tbl[16] = { 0x06, 0x1E, 0x03, 0x32, 0x14, 0x12, 0x0E, 0x1C,
                                0x00, 0x08, 0x12, 0x04, 0x1E, 0x17, 0x26, 0x04 };

const s8 effect_19_s_tbl[16] = { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 };

const s8 effect_19_m_tbl[16] = { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1 };

const s8 effect_19_l_tbl[16] = { 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1 };
