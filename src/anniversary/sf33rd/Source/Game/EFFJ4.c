#include "sf33rd/Source/Game/EFFJ4.h"
#include "common.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "sf33rd/Source/Game/workuser.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ4", effect_J4_move);
#else
void effect_J4_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

s32 effect_J4_init(u8 data2) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 194;
    ewk->wu.dir_timer = data2;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 8;

    if (data2 != 0xFF) {
        ewk->wu.type = 1;
    }

    ewk->wu.my_col_code = 1;
    ewk->wu.my_clear_level = 144;
    return 0;
}

s32 setup_sa_shadow(u8 /* unused */, u8 data) {
#if defined(TARGET_PS2)
    s32 effect_J4_init(u32 data2);
#endif

    if (test_flag) {
        return -1;
    }

    return effect_J4_init(data);
}
