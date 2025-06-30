#include "sf33rd/Source/Game/EFF72.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_72_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    WORK_Other *oya;

    if (obr_no_disp_check() == 0) {
        oya = (WORK_Other *)ewk->my_master;

        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            break;

        case 1:
            if (!EXE_flag && !Game_pause) {
                char_move(&ewk->wu);

                if (ewk->wu.cg_type) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.disp_flag = 0;
                }
            }

            disp_pos_trans_entry_r(ewk);
            break;

        default:
        case 2:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF72", effect_72_init);
#else
s32 effect_72_init(WORK_Other *oya, u8 type_id) {
    not_implemented(__func__);
}
#endif
