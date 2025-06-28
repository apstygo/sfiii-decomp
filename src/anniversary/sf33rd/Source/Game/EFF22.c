#include "sf33rd/Source/Game/EFF22.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_22_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    const s32 *ptr;

    if (obr_no_disp_check() == 0) {
        if (compel_dead_check(ewk) != 0) {
            ewk->wu.routine_no[0] = 0x63;
            ewk->wu.disp_flag = 0;
            return;
        }

        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.dead_f = 1;
            set_char_move_init(&ewk->wu, 0, 0xB);
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
                if (!(ewk->wu.xyz[1].disp.pos > 23)) {
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
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF22", effect_22_init);
#else
s32 effect_22_init() {
    not_implemented(__func__);
}
#endif

const s16 snow_pos_tbl[12][2] = { { 0x0070, 0x01A0 }, { 0x00B0, 0x0100 }, { 0x00D8, 0x0180 }, { 0x0120, 0x01C0 },
                                  { 0x0170, 0x0120 }, { 0x01C0, 0x0180 }, { 0x0200, 0x00F0 }, { 0x0240, 0x01B0 },
                                  { 0x0280, 0x0148 }, { 0x02C0, 0x01E8 }, { 0x0330, 0x0100 }, { 0x0370, 0x0180 } };

const s32 snow_sp[4][12][4] = { { { 0x00000200, 0x00000000, 0xFFFFE000, 0x00000000 },
                                  { 0x00000400, 0x00000000, 0xFFFFE800, 0x00000000 },
                                  { 0x00000800, 0x00000000, 0xFFFFE000, 0x00000000 },
                                  { 0xFFFFFE00, 0x00000000, 0xFFFFDE00, 0x00000000 },
                                  { 0x00001200, 0x00000000, 0xFFFFE000, 0x00000000 },
                                  { 0x00000000, 0x00000000, 0xFFFFE400, 0x00000000 },
                                  { 0xFFFFF800, 0x00000000, 0xFFFFDF00, 0x00000000 },
                                  { 0x00000400, 0x00000000, 0xFFFFE800, 0x00000000 },
                                  { 0x00000800, 0x00000000, 0xFFFFE200, 0x00000000 },
                                  { 0xFFFFFF00, 0x00000000, 0xFFFFE000, 0x00000000 },
                                  { 0xFFFFFC00, 0x00000000, 0xFFFFDC00, 0x00000000 },
                                  { 0xFFFFFF80, 0x00000000, 0xFFFFD800, 0x00000000 } },
                                {
                                    { 0x00000100, 0x00000000, 0xFFFFDF00, 0x00000000 },
                                    { 0x00000200, 0x00000000, 0xFFFFE700, 0x00000000 },
                                    { 0xFFFFFF00, 0x00000000, 0xFFFFDB00, 0x00000000 },
                                    { 0x00000C00, 0x00000000, 0xFFFFDD00, 0x00000000 },
                                    { 0x00001200, 0x00000000, 0xFFFFE000, 0x00000000 },
                                    { 0x00001000, 0x00000000, 0xFFFFE100, 0x00000000 },
                                    { 0xFFFFF800, 0x00000000, 0xFFFFDF00, 0x00000000 },
                                    { 0x00001200, 0x00000000, 0xFFFFD900, 0x00000000 },
                                    { 0x00000200, 0x00000000, 0xFFFFE000, 0x00000000 },
                                    { 0xFFFFFF80, 0x00000000, 0xFFFFDD00, 0x00000000 },
                                    { 0x00000080, 0x00000000, 0xFFFFEA00, 0x00000000 },
                                    { 0xFFFFFE00, 0x00000000, 0xFFFFD700, 0x00000000 },
                                },
                                {
                                    { 0x00000100, 0x00000000, 0xFFFFE600, 0x00000000 },
                                    { 0x00000200, 0x00000000, 0xFFFFDE00, 0x00000000 },
                                    { 0x00000400, 0x00000000, 0xFFFFDA00, 0x00000000 },
                                    { 0xFFFFF000, 0x00000000, 0xFFFFEE00, 0x00000000 },
                                    { 0x00001200, 0x00000000, 0xFFFFE000, 0x00000000 },
                                    { 0x00002000, 0x00000000, 0xFFFFE000, 0x00000000 },
                                    { 0x00000800, 0x00000000, 0xFFFFE200, 0x00000000 },
                                    { 0xFFFFFC00, 0x00000000, 0xFFFFD100, 0x00000000 },
                                    { 0x00000180, 0x00000000, 0xFFFFDA00, 0x00000000 },
                                    { 0xFFFFFF80, 0x00000000, 0xFFFFDE00, 0x00000000 },
                                    { 0x00000100, 0x00000000, 0xFFFFE600, 0x00000000 },
                                    { 0x00000000, 0x00000000, 0xFFFFD800, 0x00000000 },
                                },
                                { { 0x00000180, 0x00000000, 0xFFFFE600, 0x00000000 },
                                  { 0x00000000, 0x00000000, 0xFFFFEC00, 0x00000000 },
                                  { 0x00001200, 0x00000000, 0xFFFFDC00, 0x00000000 },
                                  { 0xFFFFF800, 0x00000000, 0xFFFFDA00, 0x00000000 },
                                  { 0x00001200, 0x00000000, 0xFFFFE000, 0x00000000 },
                                  { 0xFFFFF000, 0x00000000, 0xFFFFEE00, 0x00000000 },
                                  { 0x00000800, 0x00000000, 0xFFFFE200, 0x00000000 },
                                  { 0x00000100, 0x00000000, 0xFFFFDE00, 0x00000000 },
                                  { 0xFFFFFF00, 0x00000000, 0xFFFFE400, 0x00000000 },
                                  { 0x00000100, 0x00000000, 0xFFFFEC00, 0x00000000 },
                                  { 0xFFFFFF80, 0x00000000, 0xFFFFE800, 0x00000000 },
                                  { 0x00000000, 0x00000000, 0xFFFFE000, 0x00000000 } } };
