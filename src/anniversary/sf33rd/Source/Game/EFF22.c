#include "sf33rd/Source/Game/EFF22.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "bin2obj/char_table.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/texcash.h"
#include "sf33rd/Source/Game/workuser.h"

const s16 snow_pos_tbl[12][2] = { { 112, 416 }, { 176, 256 }, { 216, 384 }, { 288, 448 }, { 368, 288 }, { 448, 384 },
                                  { 512, 240 }, { 576, 432 }, { 640, 328 }, { 704, 488 }, { 816, 256 }, { 880, 384 } };

const s32 snow_sp[4][12][4] = { { { 0x200, 0, -0x2000, 0 },
                                  { 0x400, 0, -0x1800, 0 },
                                  { 0x800, 0, -0x2000, 0 },
                                  { -0x200, 0, -0x2200, 0 },
                                  { 0x1200, 0, -0x2000, 0 },
                                  { 0, 0, -0x1C00, 0 },
                                  { -0x800, 0, -0x2100, 0 },
                                  { 0x400, 0, -0x1800, 0 },
                                  { 0x800, 0, -0x1E00, 0 },
                                  { -0x100, 0, -0x2000, 0 },
                                  { -0x400, 0, -0x2400, 0 },
                                  { -0x80, 0, -0x2800, 0 } },
                                {
                                    { 0x100, 0, -0x2100, 0 },
                                    { 0x200, 0, -0x1900, 0 },
                                    { -0x100, 0, -0x2500, 0 },
                                    { 0xC00, 0, -0x2300, 0 },
                                    { 0x1200, 0, -0x2000, 0 },
                                    { 0x1000, 0, -0x1F00, 0 },
                                    { -0x800, 0, -0x2100, 0 },
                                    { 0x1200, 0, -0x2700, 0 },
                                    { 0x200, 0, -0x2000, 0 },
                                    { -0x80, 0, -0x2300, 0 },
                                    { 0x80, 0, -0x1600, 0 },
                                    { -0x200, 0, -0x2900, 0 },
                                },
                                {
                                    { 0x100, 0, -0x1A00, 0 },
                                    { 0x200, 0, -0x2200, 0 },
                                    { 0x400, 0, -0x2600, 0 },
                                    { -0x1000, 0, -0x1200, 0 },
                                    { 0x1200, 0, -0x2000, 0 },
                                    { 0x2000, 0, -0x2000, 0 },
                                    { 0x800, 0, -0x1E00, 0 },
                                    { -0x400, 0, -0x2F00, 0 },
                                    { 0x180, 0, -0x2600, 0 },
                                    { -0x80, 0, -0x2200, 0 },
                                    { 0x100, 0, -0x1A00, 0 },
                                    { 0, 0, -0x2800, 0 },
                                },
                                { { 0x180, 0, -0x1A00, 0 },
                                  { 0, 0, -0x1400, 0 },
                                  { 0x1200, 0, -0x2400, 0 },
                                  { -0x800, 0, -0x2600, 0 },
                                  { 0x1200, 0, -0x2000, 0 },
                                  { -0x1000, 0, -0x1200, 0 },
                                  { 0x800, 0, -0x1E00, 0 },
                                  { 0x100, 0, -0x2200, 0 },
                                  { -0x100, 0, -0x1C00, 0 },
                                  { 0x100, 0, -0x1400, 0 },
                                  { -0x80, 0, -0x1800, 0 },
                                  { 0, 0, -0x2000, 0 } } };

void effect_22_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    const s32 *ptr;

    if (obr_no_disp_check()) {
        return;
    }

    if (compel_dead_check(ewk) != 0) {
        ewk->wu.routine_no[0] = 99;
        ewk->wu.disp_flag = 0;
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, 11);
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = 0;
        /* fallthrough */

    case 1:
        ewk->wu.routine_no[0]++;
        ptr = &snow_sp[ewk->wu.old_rno[0]][ewk->wu.type][0];
        ewk->wu.mvxy.a[0].sp = *ptr++;
        ewk->wu.mvxy.d[0].sp = *ptr++;
        ewk->wu.mvxy.a[1].sp = *ptr++;
        ewk->wu.mvxy.d[1].sp = *ptr++;
        ewk->wu.xyz[0].disp.pos = snow_pos_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = snow_pos_tbl[ewk->wu.type][1];
        ewk->wu.old_rno[0]++;
        ewk->wu.old_rno[0] &= 3;
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            add_x_sub(ewk);
            add_y_sub(ewk);

            if (ewk->wu.xyz[1].disp.pos <= 23) {
                ewk->wu.routine_no[0] = 1;
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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF22", effect_22_init);
#else
s32 effect_22_init() {
    not_implemented(__func__);
}
#endif
