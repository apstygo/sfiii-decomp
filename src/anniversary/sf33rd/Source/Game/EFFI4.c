#include "sf33rd/Source/Game/EFFI4.h"
#include "common.h"
#include "sf33rd/Source/Game/CALDIR.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_I4_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    if (obr_no_disp_check() == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);

            if (eff_hit_flag[1]) {
                ewk->wu.routine_no[0] = 2;
                break;
            }

            break;

        case 1:
            if (!EXE_flag && !Game_pause && !EXE_obroll) {
                effect_i4_hit_sub(ewk);
            }
            /* fallthrough */

        case 2:
            disp_pos_trans_entry_r(ewk);
            break;

        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}

void effect_i4_hit_sub(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_check2(ewk, 0, 2)) {
            set_char_move_init(&ewk->wu, 0, 0x19);
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.routine_no[3] = 0;
            break;
        }

        if (eff_hit_check2(ewk, 0, 0)) {
            set_char_move_init(&ewk->wu, 0, 0x18);
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.routine_no[3] = 0;
        }

        break;

    case 1:
        if (ewk->wu.routine_no[2]) {
            effi4_up_to_down(ewk);
            break;
        }

        effi4_down_to_up(ewk);
        break;
    }
}

void effi4_down_to_up(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[3]) {
    case 0:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.type = 2;

            if (eff_hit_check2(ewk, 0, 2)) {
                ewk->wu.routine_no[3]++;
                break;
            }

            if (ewk->wu.cg_type == 0xFF) {
                eff_hit_flag[1] = 0;
                ewk->wu.routine_no[1] = 0;
                ewk->wu.type = 1;
                break;
            }
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[3]++;
            set_char_move_init(&ewk->wu, 0, 0x1A);
            break;
        }

        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] = 0x63;
            ewk->wu.routine_no[0] = 2;
        }

        break;
    }
}

void effi4_up_to_down(WORK_Other *ewk) {
    char_move(&ewk->wu);
    if (ewk->wu.cg_type == 0xFF) {
        ewk->wu.routine_no[1] = 0x63;
        ewk->wu.routine_no[0] = 2;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI4", effect_I4_init);
#else
s32 effect_I4_init() {
    not_implemented(__func__);
}
#endif
