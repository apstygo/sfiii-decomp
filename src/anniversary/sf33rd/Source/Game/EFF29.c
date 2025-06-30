#include "sf33rd/Source/Game/EFF29.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_29_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    s16 work;

    if (obr_no_disp_check() == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            if (!EXE_flag && !Game_pause && !EXE_obroll) {
                ewk->wu.old_rno[0]--;

                if (ewk->wu.old_rno[0] <= 0) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.disp_flag = 1;
                    set_char_move_init(&ewk->wu, 0, 0);
                    break;
                }
            }

            break;

        case 1:
            if (!EXE_flag && !Game_pause && !EXE_obroll) {
                char_move(&ewk->wu);

                if (ewk->wu.cg_type) {
                    ewk->wu.routine_no[0] = 0;
                    ewk->wu.disp_flag = 0;
                    work = random_16();
                    work &= 7;
                    ewk->wu.old_rno[0] = eff29_vanish_time[work];
                }
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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF29", effect_29_init);
#else
s32 effect_29_init() {
    not_implemented(__func__);
}
#endif

const s16 eff29_vanish_time[8] = { 0x01E0, 0x0258, 0x012C, 0x00F0, 0x00C8, 0x0154, 0x01F4, 0x0168 };
