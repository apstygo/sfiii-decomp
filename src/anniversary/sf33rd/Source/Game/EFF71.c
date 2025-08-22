#include "sf33rd/Source/Game/EFF71.h"
#include "common.h"
#include "sf33rd/Source/Game/EFF72.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_71_move(WORK_Other *ewk) {
    s16 work;

    if (!obr_no_disp_check()) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            if (!EXE_flag && !Game_pause && !EXE_obroll) {
                ewk->wu.old_rno[0]--;
                if (ewk->wu.old_rno[0] <= 0) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.disp_flag = 1;
                    ewk->wu.old_rno[1] = 0;
                    effect_72_init(ewk, 0);
                    effect_72_init(ewk, 1);
                    break;
                }
            }
            break;

        case 1:
            if (!EXE_flag && !Game_pause && !EXE_obroll) {
                ewk->wu.routine_no[0] = 0;
                ewk->wu.old_rno[1] = 0;
                work = random_16();
                work &= 7;
                ewk->wu.old_rno[0] = eff71_time_tbl[work];
                break;
            }
            break;

        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF71", effect_71_init);
#else
s32 effect_71_init() {
    not_implemented(__func__);
}
#endif

const s16 eff71_time_tbl[8] = { 2, 8, 12, 9, 4, 6, 50, 3 };
