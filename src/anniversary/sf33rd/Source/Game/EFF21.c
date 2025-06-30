#include "sf33rd/Source/Game/EFF21.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/eff05.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

const s16 *eff21_data_adrs[1] = { eff21_data_tbl_00 };

void effect_21_move(WORK_Other *ewk) {
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
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
        }
        ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[0];
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[0].cal -= (ewk->wu.mvxy.a[0].sp * bg_w.bg2_sp_x2);
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
        ewk->wu.xyz[1].disp.low = 0;
        ewk->wu.xyz[1].cal += (ewk->wu.mvxy.a[1].sp * bg_w.bg2_sp_y);

        if (ewk->wu.old_rno[3]) {
            disp_pos_trans_entry_rs(ewk);
            break;
        }

        disp_pos_trans_entry_s(ewk);
        break;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF21", effect_21_init);
#else
s32 effect_21_init(s16 sync_index) {
    not_implemented(__func__);
}
#endif

const s16 eff21_num[1] = { 3 };

const s32 eff21_sp_tbl[1][2] = { { 0x2000, 0x2000 } };

const s16 eff21_data_tbl_00[27] = { 0x0001, 0x0002, 0x212C, 0x0280, 0x0000, 0x000A, 0x0011, 0x0000, 0x0000,
                                    0x0000, 0x0002, 0x212C, 0x00C0, 0x0000, 0x000A, 0x0012, 0x0000, 0x0000,
                                    0x0001, 0x0002, 0x212C, 0x02E0, 0x0000, 0x000A, 0x0013, 0x0000, 0x0000 };
