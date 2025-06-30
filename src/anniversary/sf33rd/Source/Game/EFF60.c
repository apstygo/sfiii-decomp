#include "sf33rd/Source/Game/EFF60.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/eff05.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

const s16 *flash_obj_data61[3] = { flash_0000, flash_0001, flash_0002 };

void effect_60_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.disp_flag = 1;
        break;

    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            if (ewk->wu.type < 3) {
                ewk->wu.disp_flag = 1;
                char_move(&ewk->wu);
            } else {
                ewk->wu.old_rno[1]--;

                if (ewk->wu.old_rno[1] <= 0) {
                    ewk->wu.disp_flag ^= 1;
                    ewk->wu.old_rno[1] = ewk->wu.old_rno[0];

                    if (ewk->wu.hit_stop) {
                        char_move(&ewk->wu);
                    }
                }
            }
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[0]++;
        break;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF60", effect_60_init);
#else
s32 effect_60_init(s16 type) {
    not_implemented(__func__);
}
#endif

const s16 flash_0000[10] = { 0, 2, 300, 431, 80, 82, 1, 0, 0, 3 };

const s16 flash_0001[10] = { 0, 2, 300, 511, 184, 82, 2, 0, 0, 3 };

const s16 flash_0002[10] = { 0, 2, 300, 431, 64, 83, 2, 0, 0, 2 };
