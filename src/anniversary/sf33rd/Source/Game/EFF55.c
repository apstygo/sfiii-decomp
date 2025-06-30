#include "sf33rd/Source/Game/EFF55.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_55_move(WORK_Other *ewk) {
    if (obr_no_disp_check() == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, 3);
            break;

        case 1:
            if (!EXE_flag && !Game_pause) {
                ewk->wu.xyz[1].cal += 0x3000;

                if (ewk->wu.xyz[1].disp.pos >= 0x80) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.old_rno[0] = 0x12C;
                }
            }

            disp_pos_trans_entry(ewk);
            break;

        case 2:
            if (!EXE_flag && !Game_pause) {
                ewk->wu.old_rno[0]--;

                if (ewk->wu.old_rno[0] < 0) {
                    ewk->wu.routine_no[0]++;
                }
            }

            disp_pos_trans_entry(ewk);
            break;

        case 3:
            if (!EXE_flag && !Game_pause) {
                ewk->wu.xyz[1].cal -= 0x4000;

                if (ewk->wu.xyz[1].disp.pos < 0x61) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.old_rno[0] = 0x1E0;
                }
            }

            disp_pos_trans_entry(ewk);
            break;

        case 4:
            if (!EXE_flag && !Game_pause) {
                ewk->wu.old_rno[0]--;

                if (ewk->wu.old_rno[0] < 0) {
                    ewk->wu.routine_no[0] = 1;
                }
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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF55", effect_55_init);
#else
s32 effect_55_init() {
    not_implemented(__func__);
}
#endif
