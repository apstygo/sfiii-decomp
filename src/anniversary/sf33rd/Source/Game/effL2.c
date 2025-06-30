#include "sf33rd/Source/Game/effL2.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_L2_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        effl2_dir_check(ewk);
        set_char_move_init2(&ewk->wu, 0, 0, 1, 0);
        break;

    case 1:
        if (Allow_a_battle_f == 0 && Conclusion_Flag == 1 && *C_No >= 2) {
            if (!(Complete_Victory == 0) && Conclusion_Flag) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 0;

                if (Winner_id != ewk->master_id) {
                    set_char_move_init(&ewk->wu, 0, 2);
                } else {
                    set_char_move_init(&ewk->wu, 0, 1);
                }
            }
        } else if (!EXE_flag && !Game_pause) {
            effl2_dir_check(ewk);
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (Exec_Wipe) {
            ewk->wu.old_rno[0] = 1;
        }

        if (ewk->wu.old_rno[0] && !Exec_Wipe) {
            ewk->wu.routine_no[0] = 0;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void effl2_dir_check(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init2(WORK * wk, s16 koc, s32 index, s32 ip, s16 scf);
#endif
    s16 work = (plw[ewk->master_id].wu.xyz[0].disp.pos);

    work >>= 6;
    work &= 15;

    if (ewk->wu.direction != effl2_dir_tbl[ewk->master_id][work]) {
        ewk->wu.direction = effl2_dir_tbl[ewk->master_id][work];
        set_char_move_init2(&ewk->wu, 0, 0, ewk->wu.direction + 1, 0);
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effL2", effect_L2_init);
#else
s32 effect_L2_init() {
    not_implemented(__func__);
}
#endif

const s8 effl2_dir_tbl[2][16] = { { 0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 3 } };
