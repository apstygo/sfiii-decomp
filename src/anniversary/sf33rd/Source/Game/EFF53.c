#include "sf33rd/Source/Game/EFF53.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_53_move(WORK_Other *ewk) {
    s16 work;

    if (obr_no_disp_check() != 0) {
        return;
    }

    if (EXE_flag || Game_pause || !EXE_obroll) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.old_rno[0] = 0x1E;
            ewk->wu.old_rno[1] = 0;
            ewk->wu.disp_flag = 1;
        }

        break;

    case 1:
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.disp_flag ^= 1;
            ewk->wu.old_rno[0] = 0x1E;

            if (!ewk->wu.disp_flag) {
                ewk->wu.old_rno[1]++;

                if (ewk->wu.old_rno[1] >= 6) {
                    ewk->wu.routine_no[0] = 0;
                    work = random_16();
                    work &= 7;
                    ewk->wu.old_rno[2] = eff53_vanish_time[work];
                    ewk->wu.disp_flag = 0;
                }
            }
        }

        break;

    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF53", effect_53_init);
#else
s32 effect_53_init() {
    not_implemented(__func__);
}
#endif

const s16 eff53_vanish_time[8] = { 480, 600, 900, 1440, 480, 1080, 1500, 600 };
