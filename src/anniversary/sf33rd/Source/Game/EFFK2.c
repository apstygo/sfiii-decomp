#include "sf33rd/Source/Game/EFFK2.h"
#include "bin2obj/char_table.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFF13.h"
#include "sf33rd/Source/Game/EFFC2.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/Se_Data.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/workuser.h"

void disp_effK2(WORK *wk, WORK *mk, HAHEN *hk);
void effK2_parts_move_type_0(WORK_Other *ewk);
void effK2_parts_move_type_1(WORK_Other *ewk, HAHEN *hahen);
void effK2_parts_move_type_2(WORK_Other *ewk);
void effK2_parts_move_type_3(WORK_Other *ewk, HAHEN *hahen);
void effK2_parts_move_type_4(WORK_Other *ewk);
void effK2_parts_move_type_5(WORK_Other *ewk);
void effK2_parts_move_type_6(WORK_Other *ewk);
void effK2_parts_move_type_7(WORK_Other *ewk);
void effK2_parts_move_type_8(WORK_Other *ewk, HAHEN *hahen);
void set_next_next_y(WORK *wk, u8 flag);
s32 effect_K2_init(WORK_Other *wk, u32 *dad);

const DADD hahen_dummy[1] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

const DADD p_05_lv_02[3] = { { 1, 100, -64, 88, -2, -2, 0, 0, 1, 2, 1, 2, 1, 0, 0 },
                             { 6, 132, -60, 86, 0, 0, 17, 1, 44, 0, 0, 0, 1, 0, 0 },
                             { 6, 134, -62, 92, 0, 0, 17, 1, 45, 0, 0, 0, 1, 0, 0 } };

const DADD p_05_lv_03[3] = { { 1, 102, 0, 88, 42, 0, 255, 0, 2, 3, 0, 2, 1, 0, 0 },
                             { 6, 137, -2, 86, 0, 0, 17, 1, 46, 0, 0, 0, 1, 0, 0 },
                             { 6, 133, 2, 90, 0, 0, 17, 1, 47, 0, 0, 0, 1, 0, 0 } };

const DADD p_05_lv_04[4] = { { 8, 104, -88, 32, 2, 2, 17, 0, 3, 3, 1, 2, 1, 0, 0 },
                             { 8, 106, -96, 64, 2, 2, 17, 0, 4, 3, 1, 2, 1, 0, 0 },
                             { 6, 137, -72, 32, 0, 0, 17, 1, 48, 0, 0, 0, 1, 0, 0 },
                             { 6, 141, -80, 64, 0, 0, 17, 1, 49, 0, 0, 0, 1, 0, 0 } };

const DADD p_05_lv_06[8] = {
    { 1, 115, -32, 64, -2, -2, 17, 0, 5, 3, 1, 2, 1, 0, 0 },  { 1, 115, -32, 64, -2, -2, 17, 0, 6, 3, 1, 2, 1, 0, 0 },
    { 1, 116, -32, 64, -2, -2, 17, 0, 7, 3, 1, 2, 1, 0, 0 },  { 1, 115, -32, 64, -2, -2, 17, 0, 8, 3, 1, 2, 1, 0, 0 },
    { 1, 116, -32, 64, -2, -2, 17, 0, 9, 3, 1, 2, 1, 0, 0 },  { 1, 116, -32, 64, -2, -2, 17, 0, 10, 3, 1, 2, 1, 0, 0 },
    { 1, 115, -32, 64, -2, -2, 17, 0, 11, 3, 1, 2, 1, 0, 0 }, { 1, 116, -32, 64, -2, -2, 17, 0, 12, 3, 1, 2, 1, 0, 0 }
};

const DADD p_05_lv_07[3] = { { 8, 107, -32, 64, 2, 2, 17, 0, 13, 3, 1, 2, 1, 0, 0 },
                             { 6, 134, -32, 68, 0, 0, 17, 1, 50, 0, 0, 0, 1, 0, 0 },
                             { 6, 133, -36, 62, 0, 0, 17, 1, 51, 0, 0, 0, 1, 0, 0 } };

const DADD p_05_lv_08[2] = { { 6, 140, -40, 96, 0, 0, 17, 1, 52, 0, 0, 0, 1, 0, 0 },
                             { 6, 139, -36, 88, 0, 0, 17, 1, 53, 0, 0, 0, 1, 0, 0 } };

const DADD p_04_lv_02[2] = { { 6, 134, 64, 36, 0, 0, 17, 1, 54, 0, 0, 0, 1, 0, 0 },
                             { 6, 135, 56, 28, 0, 0, 17, 1, 55, 0, 0, 0, 1, 0, 0 } };

const DADD p_04_lv_03[3] = { { 1, 101, 144, 96, 0, 0, 0, 0, 14, 2, 0, 2, 1, 0, 0 },
                             { 6, 133, 144, 96, 0, 0, 17, 1, 56, 0, 0, 0, 1, 0, 0 },
                             { 6, 135, 144, 96, 0, 0, 17, 1, 57, 0, 0, 0, 1, 0, 0 } };

const DADD p_04_lv_04[3] = { { 8, 103, 64, 32, 2, 2, 17, 0, 15, 3, 1, 2, 1, 0, 0 },
                             { 6, 138, 48, 32, 0, 0, 17, 1, 58, 0, 0, 0, 1, 0, 0 },
                             { 6, 136, 64, 40, 0, 0, 17, 1, 59, 0, 0, 0, 1, 0, 0 } };

const DADD p_04_lv_05[3] = { { 8, 105, 64, 48, 2, 2, 17, 0, 16, 3, 1, 2, 1, 0, -16 },
                             { 6, 136, 48, 56, 0, 0, 17, 1, 60, 0, 0, 0, 1, 0, 0 },
                             { 6, 139, 56, 48, 0, 0, 17, 1, 61, 0, 0, 0, 1, 0, 0 } };

const DADD p_04_lv_06[2] = { { 6, 136, 160, 112, 0, 0, 17, 1, 62, 0, 0, 0, 1, 0, 0 },
                             { 6, 138, 168, 88, 0, 0, 17, 1, 63, 0, 0, 0, 1, 0, 0 } };

const DADD p_04_lv_07[3] = { { 0, 108, 182, 0, -1, -1, 0, 0, 0, 0, 0, 2, 1, 0, 0 },
                             { 6, 142, 192, 96, 0, 0, 17, 1, 64, 0, 0, 0, 1, 0, 0 },
                             { 6, 143, 176, 80, 0, 0, 17, 1, 65, 0, 0, 0, 1, 0, 0 } };

const DADD p_04_lv_08[3] = { { 2, 109, 193, 24, -1, -1, 0, 0, 17, 0, 0, 2, 1, 0, 1 },
                             { 6, 137, 200, 32, 0, 0, 17, 1, 66, 0, 0, 0, 1, 0, 0 },
                             { 6, 138, 192, 64, 0, 0, 17, 1, 67, 0, 0, 0, 1, 0, 0 } };

const DADD p_03_lv_07[2] = { { 6, 142, 16, 80, 0, 0, 17, 1, 79, 0, 0, 0, 1, 0, 0 },
                             { 6, 143, 48, 88, 0, 0, 17, 1, 80, 0, 0, 0, 1, 0, 0 } };

const DADD p_03_lv_08[2] = { { 6, 140, 32, 80, 0, 0, 17, 1, 81, 0, 0, 0, 1, 0, 0 },
                             { 6, 141, 64, 96, 0, 0, 17, 1, 82, 0, 0, 0, 1, 0, 0 } };

const DADD p_00_lv_F0[8] = {
    { 1, 110, 96, -21, 2, 2, 17, 0, 18, 5, 1, 2, 1, 0, 0 },  { 1, 111, 163, 4, -1, -1, 0, 0, 19, 5, 1, 2, 1, 0, 0 },
    { 1, 112, -35, 10, 1, 1, 0, 0, 20, 5, 1, 2, 1, 0, 0 },   { 6, 141, 64, 96, 0, 0, 17, 1, 68, 0, 0, 0, 1, 0, 0 },
    { 6, 142, 80, 128, 0, 0, 17, 1, 69, 0, 0, 0, 1, 0, 0 },  { 6, 140, 112, 112, 0, 0, 17, 1, 70, 0, 0, 0, 1, 0, 0 },
    { 6, 136, -24, 112, 0, 0, 17, 1, 71, 0, 0, 0, 1, 0, 0 }, { 6, 143, -48, 80, 0, 0, 17, 1, 72, 0, 0, 0, 1, 0, 0 }
};

const DADD p_00_lv_F1[6] = {
    { 0, 117, -64, -4, -1, -1, 0, 0, 21, 0, 0, 0, 2, 0, 0 },  { 0, 117, -40, -8, -1, -1, 0, 0, 22, 0, 0, 0, 2, 0, 0 },
    { 0, 117, -16, -10, -1, -1, 0, 0, 23, 0, 0, 0, 2, 0, 0 }, { 0, 117, 8, -9, -1, -1, 0, 0, 24, 0, 0, 0, 2, 0, 0 },
    { 0, 117, 32, -8, -1, -1, 0, 0, 25, 0, 0, 0, 2, 0, 0 },   { 0, 117, 56, -4, -1, -1, 0, 0, 26, 0, 0, 0, 2, 0, 0 }
};

const DADD p_00_lv_F2[4] = { { 0, 117, 112, 4, -1, -1, 0, 0, 27, 0, 0, 0, 2, 0, 0 },
                             { 0, 117, 132, 6, -1, -1, 0, 0, 28, 0, 0, 0, 2, 0, 0 },
                             { 0, 117, 146, 10, -1, -1, 0, 0, 29, 0, 0, 0, 2, 0, 0 },
                             { 0, 117, 160, 14, -1, -1, 0, 0, 30, 0, 0, 0, 2, 0, 0 } };

const DADD p_00_lv_F3[9] = {
    { 0, 117, -80, 8, -1, -1, 0, 0, 31, 0, 0, 0, 2, 0, 0 }, { 0, 117, -62, 4, -1, -1, 0, 0, 32, 0, 0, 0, 2, 0, 0 },
    { 0, 117, -42, 0, -1, -1, 0, 0, 33, 0, 0, 0, 2, 0, 0 }, { 0, 117, -8, -2, -1, -1, 0, 0, 34, 0, 0, 0, 2, 0, 0 },
    { 0, 117, 96, -2, -1, -1, 0, 0, 35, 0, 0, 0, 2, 0, 0 }, { 0, 117, 124, 0, -1, -1, 0, 0, 36, 0, 0, 0, 2, 0, 0 },
    { 0, 117, 148, 4, -1, -1, 0, 0, 37, 0, 0, 0, 2, 0, 0 }, { 0, 117, 168, 10, -1, -1, 0, 0, 38, 0, 0, 0, 2, 0, 0 },
    { 0, 117, 184, 18, -1, -1, 0, 0, 39, 0, 0, 0, 2, 0, 0 }
};

const DADD p_00_lv_F4[3] = { { 0, 130, 64, -20, 2, 1, 17, 0, 0, 0, 0, 0, 1, 0, 0 },
                             { 0, 130, 32, 24, 3, 1, 17, 0, 0, 0, 0, 0, 1, 0, 0 },
                             { 0, 130, 0, 28, -1, 1, 255, 0, 0, 0, 0, 0, 1, 0, 0 } };

const DADD p_00_lv_02[5] = { { 1, 118, 97, 49, 1, 1, 0, 0, 41, 1, 0, 2, 1, 0, 8 },
                             { 1, 131, 72, 48, 1, 1, 0, 0, 42, 1, 0, 2, 1, 0, 10 },
                             { 2, 119, 72, 88, 1, 4, 0, 0, 40, 0, 0, 2, 1, 0, 20 },
                             { 6, 141, 104, 96, 0, 0, 17, 1, 73, 0, 0, 0, 1, 0, 0 },
                             { 6, 142, 40, 88, 0, 0, 17, 1, 74, 0, 0, 0, 1, 0, 0 } };

const DADD p_00_lv_03[4] = { { 2, 120, 8, 80, 2, 2, 17, 0, 43, 1, 1, 2, 1, 0, -10 },
                             { 5, 125, 0, 0, -1, -1, 0, 0, 0, 0, 0, 2, 1, 0, 0 },
                             { 6, 143, 40, 96, 0, 0, 17, 1, 75, 0, 0, 0, 1, 0, 0 },
                             { 6, 141, -32, 88, 0, 0, 17, 1, 76, 0, 0, 0, 1, 0, 0 } };

const DADD p_00_lv_04[5] = { { 0, 121, 89, 75, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
                             { 0, 122, 39, 75, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
                             { 0, 124, 17, -2, -2, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0 },
                             { 6, 136, -64, 64, 0, 0, 17, 1, 77, 0, 0, 0, 1, 0, 0 },
                             { 6, 137, 16, 56, 0, 0, 17, 1, 78, 0, 0, 0, 1, 0, 0 } };

const DADD p_00_lv_05[2] = { { 0, 126, 0, 0, -2, -2, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
                             { 5, 127, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0 } };

const DADD p_00_lv_06[2] = { { 4, 128, 64, -55, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
                             { 7, 144, 64, -7, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 } };

const HAHEN hahen_data[8][8] = { { { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy } },
                                 { { 5, 0, p_00_lv_02 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 2, 1, p_04_lv_02 },
                                   { 3, 0, p_05_lv_02 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy } },
                                 { { 4, 0, p_00_lv_03 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 3, 0, p_04_lv_03 },
                                   { 3, 0, p_05_lv_03 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy } },
                                 { { 5, 0, p_00_lv_04 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 3, 0, p_04_lv_04 },
                                   { 4, 0, p_05_lv_04 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy } },
                                 { { 2, 0, p_00_lv_05 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 3, 0, p_04_lv_05 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy } },
                                 { { 2, 0, p_00_lv_06 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 2, 1, p_04_lv_06 },
                                   { 8, 1, p_05_lv_06 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy } },
                                 { { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 2, 1, p_03_lv_07 },
                                   { 3, 0, p_04_lv_07 },
                                   { 3, 0, p_05_lv_07 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy } },
                                 { { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy },
                                   { 2, 0, p_03_lv_08 },
                                   { 3, 0, p_04_lv_08 },
                                   { 2, 1, p_05_lv_08 },
                                   { 0, 0, hahen_dummy },
                                   { 0, 0, hahen_dummy } } };

const HAHEN ill_hahen_data[5] = {
    { 8, 0, p_00_lv_F0 }, { 6, 0, p_00_lv_F1 }, { 4, 0, p_00_lv_F2 }, { 9, 0, p_00_lv_F3 }, { 3, 0, p_00_lv_F4 }
};

const s16 k2_kidou[83][4] = {
    { 0, 0, 0, 0 },           { 512, 0, 1280, -112 },  { 512, 0, 1536, -112 },   { 1536, 0, 0, -112 },
    { 512, 0, 1536, -112 },   { 256, 0, 1536, -112 },  { 512, 0, 768, -112 },    { 768, 0, 256, -112 },
    { 256, 0, 0, -112 },      { -256, 0, 1280, -112 }, { -512, 0, 1024, -112 },  { -768, 0, 512, -112 },
    { -1024, 0, 0, -112 },    { 768, 0, 1536, -112 },  { -1024, 0, 768, -112 },  { -1792, 0, 0, -112 },
    { -1024, 0, 1280, -112 }, { -64, 0, 512, -112 },   { -2560, 0, 1024, -112 }, { -1792, 0, 1536, -112 },
    { 2048, 0, 1280, -112 },  { 64, 0, 64, 0 },        { 80, 0, 96, 0 },         { 96, 0, 112, 0 },
    { 96, 0, 96, 0 },         { 80, 0, 64, 0 },        { 64, 0, 32, 0 },         { -80, 0, 64, 0 },
    { -80, 0, 80, 0 },        { -64, 0, 96, 0 },       { -64, 0, 96, 0 },        { 320, 0, 32, 0 },
    { 384, 0, 48, 0 },        { 448, 0, 16, 0 },       { 512, 0, 0, 0 },         { -576, 0, -32, 0 },
    { -544, 0, -16, 0 },      { -480, 0, 0, 0 },       { -384, 0, 16, 0 },       { -256, 0, 32, 0 },
    { 512, 0, 2048, -112 },   { -768, 0, 1536, -112 }, { 512, 0, 1280, -112 },   { -768, 0, 1792, -112 },
    { 256, 0, 1024, -96 },    { 128, 0, 1280, -96 },   { 1024, 0, 256, -96 },    { 128, 0, 1024, -96 },
    { 768, 0, 256, -96 },     { 128, 0, 2048, -96 },   { 256, 0, 1536, -96 },    { -128, 0, 1024, -96 },
    { 768, 0, 1792, -96 },    { 1280, 0, 768, -96 },   { -1792, 0, 512, -96 },   { -1024, 0, 0, -96 },
    { -128, 0, 2048, -96 },   { -1024, 0, 512, -96 },  { -2048, 0, 0, -96 },     { -256, 0, 1024, -96 },
    { -512, 0, 2048, -96 },   { -1024, 0, 1536, -96 }, { -512, 0, 1536, -96 },   { -768, 0, 1024, -96 },
    { -1024, 0, 768, -96 },   { -768, 0, 256, -96 },   { -1024, 0, 768, -96 },   { -768, 0, 256, -96 },
    { -512, 0, 2048, -96 },   { -2048, 0, 768, -96 },  { -1280, 0, 1280, -96 },  { 1536, 0, 1024, -96 },
    { 1024, 0, 1792, -96 },   { 768, 0, 1536, -96 },   { -512, 0, 768, -96 },    { 1280, 0, 768, -96 },
    { 256, 0, 2048, -96 },    { 256, 0, 512, -96 },    { -768, 0, 0, -96 },      { 1024, 0, 512, -96 },
    { 512, 0, 1280, -96 },    { 768, 0, 768, -96 },    { 128, 0, 1536, -96 }
};

void (*const effK2_main_process[9])() = { effK2_parts_move_type_0, effK2_parts_move_type_1, effK2_parts_move_type_2,
                                          effK2_parts_move_type_3, effK2_parts_move_type_4, effK2_parts_move_type_5,
                                          effK2_parts_move_type_6, effK2_parts_move_type_7, effK2_parts_move_type_8 };

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effect_K2_move);
#else
void effect_K2_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", disp_effK2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effK2_parts_move_type_0);
#else
void effK2_parts_move_type_0(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effK2_parts_move_type_1);
#else
void effK2_parts_move_type_1(WORK_Other *ewk, HAHEN *hahen) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effK2_parts_move_type_2);
#else
void effK2_parts_move_type_2(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effK2_parts_move_type_3);
#else
void effK2_parts_move_type_3(WORK_Other *ewk, HAHEN *hahen) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effK2_parts_move_type_4);
#else
void effK2_parts_move_type_4(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effK2_parts_move_type_5);
#else
void effK2_parts_move_type_5(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effK2_parts_move_type_6);
#else
void effK2_parts_move_type_6(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effK2_parts_move_type_7);
#else
void effK2_parts_move_type_7(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effK2_parts_move_type_8);
#else
void effK2_parts_move_type_8(WORK_Other *ewk, HAHEN *hahen) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", set_next_next_y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", effect_K2_init);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", setup_effK2);
#else
void setup_effK2(WORK *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", setup_effK2_sync_bomb);
#else
void setup_effK2_sync_bomb(WORK *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFK2", illegal_setup_effK2);
#else
void illegal_setup_effK2(WORK *wk, s16 ix) {
    not_implemented(__func__);
}
#endif
