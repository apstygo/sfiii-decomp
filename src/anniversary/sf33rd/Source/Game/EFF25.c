#include "sf33rd/Source/Game/EFF25.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/eff05.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

const s16 *scr_obj_data25[1] = { eff25_data_0000 };

void (*eff25_jp_tbl[10])(WORK_Other *ewk) = { eff25_00, eff25_00, eff25_02, eff25_02, eff25_04,
                                              eff25_04, eff25_06, eff25_06, eff25_08, eff25_08 };

void effect_25_move(WORK_Other *ewk) {
    if (compel_dead_check(ewk) != 0) {
        ewk->wu.routine_no[0] = 0x63;
        ewk->wu.disp_flag = 0;
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause) {
            eff25_jp_tbl[ewk->wu.old_rno[2]](ewk);
        }
        disp_pos_trans_entry_rs(ewk);
        break;

    case 1:
    case 2:
    case 3:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        break;

    case 4:
        ewk->wu.routine_no[0]++;
        break;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff25_00(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (*(&eff_hit_flag[ewk->wu.type])) {
            ewk->wu.routine_no[0] = 4;
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            ewk->wu.routine_no[1]++;
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
        }
        /* fallthrough */

    case 3:
        ewk->wu.routine_no[0]++;
        break;
    }
}

void eff25_02(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.disp_flag = 1;
            ewk->wu.routine_no[1] = 4;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[7]);
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 3:
        break;

    case 4:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;
    }
}

void eff25_04(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 4;
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            ewk->wu.routine_no[1]++;
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        ewk->wu.routine_no[0]++;
        break;
    }
}

void eff25_06(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[7]);
            ewk->wu.routine_no[1] = 4;
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type) {
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[3]);
            ewk->wu.routine_no[1]++;
            break;
        }

        break;

    case 3:
        break;

    case 4:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;
    }
}

void eff25_08(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 4;
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            ewk->wu.routine_no[1] += 1;
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        ewk->wu.routine_no[0] += 1;
        break;
    }
}

void eff25_char_set(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    ewk->wu.routine_no[1] += 1;
    ewk->wu.disp_flag = 1;
    set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF25", piece_set);
#else
void piece_set(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF25", effect_25_init);
#else
s32 effect_25_init(s8 num) {
    not_implemented(__func__);
}
#endif

const s16 eff25_data_0000[16] = { 0x0000, 0x0002, 0x012C, 0x00A0, 0x0020, 0x0047, 0x0006, 0x0000,
                                  0x0000, 0x0000, 0x0006, 0x0006, 0x0042, 0x0009, 0x0000, 0xFFFF };
