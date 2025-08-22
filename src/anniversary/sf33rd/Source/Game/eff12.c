#include "sf33rd/Source/Game/eff12.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/eff05.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

const s16 *scr_obj_data12[6] = { eff12_data_tbl0, eff12_data_tbl1, eff12_data_tbl2,
                                 eff12_data_tbl3, eff12_data_tbl4, eff12_data_tbl5 };

void effect_12_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    if (obr_no_disp_check() == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            break;

        case 1:
            if (compel_dead_check(ewk)) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
                break;
            }

            if (!EXE_flag && !Game_pause) {
                char_move(&ewk->wu);
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
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff12", effect_12_init);
#else
s32 effect_12_init(s16 type) {
    not_implemented(__func__);
}
#endif

const s16 scr_obj_num12[6] = { 0x0001, 0x0001, 0x0002, 0x0003, 0x0003, 0x0002 };

const s16 eff12_data_tbl0[8] = { 0x0000, 0x0001, 0x012C, 0x0200, 0x0080, 0x0056, 0x0008, 0x0000 };

const s16 eff12_data_tbl1[8] = { 0x0000, 0x0002, 0x212C, 0x01FF, 0x0038, 0x0050, 0x0002, 0x0000 };

const s16 eff12_data_tbl2[16] = { 0x0000, 0x0002, 0x212C, 0x022F, 0x0040, 0x0048, 0x0002, 0x0000,
                                  0x0000, 0x0002, 0x212C, 0x01CF, 0x0070, 0x0048, 0x0004, 0x0000 };

const s16 eff12_data_tbl3[24] = { 0x0000, 0x0001, 0x012C, 0x01F0, 0x0040, 0x0056, 0x0002, 0x0000,
                                  0x0000, 0x0002, 0x212C, 0x025F, 0x0060, 0x0053, 0x0008, 0x0000,
                                  0x0000, 0x0002, 0x212C, 0x025F, 0x0060, 0x0053, 0x001A, 0x0000 };

const s16 eff12_data_tbl4[24] = { 0x0000, 0x0002, 0x012C, 0x01FF, 0x0000, 0x000B, 0x0005, 0x0000,
                                  0x0000, 0x0002, 0x212C, 0x0230, 0x00A8, 0x004F, 0x0009, 0x0000,
                                  0x0000, 0x0002, 0x012C, 0x0200, 0x0000, 0x004C, 0x000A, 0x0000 };

const s16 eff12_data_tbl5[16] = { 0x0000, 0x0002, 0x212C, 0x023F, 0x0050, 0x004A, 0x0014, 0x0000,
                                  0x0000, 0x0002, 0x212C, 0x01D0, 0x0040, 0x0048, 0x0013, 0x0000 };
