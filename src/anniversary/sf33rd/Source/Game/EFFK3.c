#include "sf33rd/Source/Game/EFFK3.h"
#include "bin2obj/char_table.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/workuser.h"

void set_init_posspeed_effK3(WORK *wk);
s32 effect_K3_init(WORK_Other *ewk);

const s16 numof_effK3[4] = { 2, 4, 6, 6 };

const s16 effK3_isp_table[4][4][2] = { { { -512, 768 }, { -1024, 512 }, { 512, 768 }, { 1024, 512 } },
                                       { { -1024, 1280 }, { -1536, 896 }, { 1024, 1280 }, { 1536, 896 } },
                                       { { -1536, 1792 }, { -2048, 1280 }, { 1536, 1792 }, { 2048, 1280 } },
                                       { { -2048, 2304 }, { -2560, 1664 }, { 2048, 2304 }, { 2560, 1664 } } };

const s16 effK3_isp_x_hosei[4][8] = { { 0, 128, 256, 384, 0, -128, -256, -384 },
                                      { 0, 128, 256, 384, -128, -384, -512, -640 },
                                      { 0, 256, 384, 512, -256, -512, -768, -1024 },
                                      { 0, 256, 512, 768, -256, -512, -768, -1024 } };

const s16 effK3_isp_y_hosei[4][8] = { { 0, 128, 256, 384, 512, 0, -128, -256 },
                                      { 0, 128, 256, 384, 512, 0, -128, -256 },
                                      { 0, 128, 128, 256, 256, 384, 384, -256 },
                                      { 0, 256, 512, 0, -256, -512, 384, -384 } };

const s16 effK3_life_time[4] = { 24, 20, 16, 12 };

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK3", effect_K3_move);
#else
void effect_K3_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK3", set_init_posspeed_effK3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK3", effect_K3_init);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK3", setup_effK3);
#else
s32 setup_effK3(WORK *wk) {
    not_implemented(__func__);
}
#endif
