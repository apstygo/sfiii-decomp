#include "sf33rd/Source/Game/EFF86.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

const s16 *eff86_adrs_tbl[1] = { eff86_data_tbl00 };

void effect_86_move(WORK_Other *ewk) {
    void (*eff86_jp_tbl[1])(WORK_Other *) = { eff86_0000 };

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff86_jp_tbl[ewk->wu.routine_no[1]](ewk);
        }

        disp_pos_trans_entry(ewk);
        return;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}

void eff86_0000(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    s16 work;

    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        work = plw[0].wu.position_x + plw[1].wu.position_x;
        work >>= 1;
        ewk->wu.xyz[0].disp.pos = work;
        work = plw[1].wu.position_y + plw[1].wu.position_y;
        work >>= 1;
        ewk->wu.xyz[1].disp.pos = work + 0x5C;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
        }

        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF86", effect_86_init);
#else
s32 effect_86_init(s16 type86) {
    not_implemented(__func__);
}
#endif

const s16 eff86_data_tbl00[7] = { 0x0000, 0x0002, 0x2020, 0x01FF, 0x0038, 0x000A, 0x0012 };
