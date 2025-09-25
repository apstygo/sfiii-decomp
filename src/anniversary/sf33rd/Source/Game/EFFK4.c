#include "sf33rd/Source/Game/EFFK4.h"
#include "bin2obj/char_table.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/workuser.h"

void get_init_position_effK4(WORK *wk);
void get_init_speed_and_timer_effK4(WORK *wk);

const s16 effK4_isp_table[4][4][2] = { { { -512, 768 }, { -768, 768 }, { 512, 768 }, { 768, 768 } },
                                       { { -1024, 1024 }, { -1280, 1024 }, { 1024, 1024 }, { 1280, 1024 } },
                                       { { -1280, 1280 }, { -1792, 1280 }, { 1280, 1280 }, { 1792, 1280 } },
                                       { { -1536, 1536 }, { -2048, 1536 }, { 1536, 1536 }, { 2048, 1536 } } };

const s16 effK4_isp_x_hosei[4][8] = { { 0, 128, 256, 384, -128, -256, -384, -512 },
                                      { 0, 128, 256, 384, -128, -256, -512, -768 },
                                      { 0, 256, 384, 512, -256, -512, -768, -1024 },
                                      { 0, 256, 512, -256, -512, -768, -1024, -1280 } };

const s16 effK4_isp_y_hosei[4][8] = { { 0, 0, 128, 128, 256, 256, 384, -128 },
                                      { 0, 128, 128, 256, 256, 384, 384, -256 },
                                      { 0, 128, 256, 384, 512, -128, -256, -512 },
                                      { 0, 256, 384, 512, 640, -256, -512, -768 } };

const s16 effK4_life_time[4] = { 24, 24, 24, 24 };

const s16 effK4_char_sel_table[4][16] = {
    { 132, 132, 132, 132, 133, 133, 133, 133, 134, 134, 134, 134, 135, 135, 135, 135 },
    { 136, 136, 136, 137, 137, 137, 138, 138, 138, 139, 139, 139, 132, 132, 133, 134 },
    { 140, 140, 132, 132, 136, 136, 141, 141, 141, 142, 142, 142, 143, 143, 143, 137 },
    { 140, 140, 140, 136, 136, 136, 132, 132, 132, 140, 136, 132, 134, 142, 143, 140 }
};

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK4", effect_K4_move);
#else
void effect_K4_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK4", get_init_position_effK4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK4", get_init_speed_and_timer_effK4);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK4", setup_effK4);
#else
void setup_effK4(WORK *wk) {
    not_implemented(__func__);
}
#endif
