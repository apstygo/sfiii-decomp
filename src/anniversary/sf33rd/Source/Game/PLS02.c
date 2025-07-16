#include "sf33rd/Source/Game/PLS02.h"
#include "common.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/SysDir.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/workuser.h"
#include "structs.h"

u8 _add_arts_gauge[20][16][4] = { { { 0, 0, 0, 3 },
                                    { 0, 1, 2, 3 },
                                    { 0, 0, 0, 3 },
                                    { 0, 0, 0, 3 },
                                    { 2, 2, 4, 3 },
                                    { 2, 1, 3, 3 },
                                    { 0, 0, 0, 3 },
                                    { 3, 4, 5, 3 },
                                    { 3, 3, 4, 3 },
                                    { 0, 0, 0, 3 },
                                    { 3, 1, 6, 3 },
                                    { 3, 5, 8, 3 },
                                    { 3, 6, 7, 3 },
                                    { 0, 0, 7, 3 },
                                    { 0, 0, 0, 3 },
                                    { 0, 0, 0, 3 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 3, 7, 4 },
                                    { 2, 1, 6, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 5, 12, 4 },
                                    { 3, 3, 10, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 1, 8, 4 },
                                    { 3, 8, 13, 4 },
                                    { 3, 6, 11, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 1, 1, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 2, 2, 13, 4 },
                                    { 0, 1, 2, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 3, 7, 4 },
                                    { 2, 2, 6, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 5, 13, 4 },
                                    { 3, 4, 11, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 4, 10, 4 },
                                    { 3, 9, 14, 4 },
                                    { 3, 7, 12, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 3, 6, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 3, 8, 12, 4 },
                                    { 0, 3, 9, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 1, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 2, 3, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 5, 9, 4 },
                                    { 2, 3, 8, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 7, 15, 4 },
                                    { 3, 5, 13, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 8, 16, 4 },
                                    { 3, 10, 22, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 1, 1, 4, 4 },
                                    { 1, 2, 7, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 2, 2, 6, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 3, 6, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 1, 5, 9, 4 },
                                    { 1, 3, 8, 4 },
                                    { 1, 2, 4, 4 },
                                    { 2, 7, 15, 4 },
                                    { 2, 5, 13, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 1, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 3, 7, 4 },
                                    { 2, 2, 6, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 5, 13, 4 },
                                    { 3, 4, 11, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 4, 10, 4 },
                                    { 3, 9, 14, 4 },
                                    { 3, 7, 12, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 3, 6, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 1, 1, 7, 4 },
                                    { 0, 0, 0, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 3, 6, 4 } },
                                  { { 0, 0, 0, 3 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 1, 1, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 2, 9, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 1, 1, 7, 4 },
                                    { 0, 1, 2, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 2, 3, 7, 4 },
                                    { 3, 5, 13, 4 },
                                    { 2, 3, 7, 4 },
                                    { 0, 0, 2, 4 },
                                    { 3, 7, 12, 4 },
                                    { 3, 8, 13, 4 },
                                    { 3, 9, 14, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 10, 15, 4 },
                                    { 0, 0, 7, 4 },
                                    { 3, 7, 10, 4 },
                                    { 0, 2, 3, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 1, 1, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 2, 6, 4 },
                                    { 3, 4, 10, 4 },
                                    { 3, 8, 13, 4 },
                                    { 3, 10, 15, 4 },
                                    { 0, 0, 7, 4 },
                                    { 3, 8, 14, 4 },
                                    { 0, 1, 2, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 2, 3, 7, 4 },
                                    { 3, 5, 13, 4 },
                                    { 2, 3, 7, 4 },
                                    { 0, 0, 2, 4 },
                                    { 3, 7, 12, 4 },
                                    { 3, 8, 13, 4 },
                                    { 3, 9, 14, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 10, 15, 4 },
                                    { 3, 10, 15, 4 },
                                    { 0, 0, 7, 4 },
                                    { 3, 7, 10, 4 },
                                    { 0, 2, 3, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 0, 0, 4 },
                                    { 1, 2, 4, 4 },
                                    { 3, 8, 13, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 0, 0, 1, 4 } },
                                  { { 0, 0, 0, 4 },
                                    { 0, 1, 2, 4 },
                                    { 0, 1, 1, 4 },
                                    { 0, 0, 0, 4 },
                                    { 2, 4, 8, 4 },
                                    { 2, 2, 7, 4 },
                                    { 0, 0, 0, 4 },
                                    { 3, 6, 14, 4 },
                                    { 3, 4, 12, 4 },
                                    { 0, 2, 6, 4 },
                                    { 0, 1, 1, 4 },
                                    { 3, 8, 12, 4 },
                                    { 3, 8, 13, 4 },
                                    { 0, 0, 7, 4 },
                                    { 2, 2, 13, 4 },
                                    { 0, 1, 2, 4 } } };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", asagh_zuru);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", sel_hosei_tbl_ix);

const s16 satse[20] = { 32, 32, 28, 24, 32, 36, 40, 24, 28, 28, 24, 28, 28, 32, 30, 28, 28, 24, 36, 24 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_32);

const s16 random_tbl_16[64] = { 3,  8, 6,  9, 14, 13, 9,  5, 10, 14, 1,  7, 4,  15, 2,  0, 12, 15, 5, 13, 6,  3,
                                11, 8, 0,  3, 11, 10, 1,  7, 11, 4,  5,  4, 13, 2,  11, 9, 7,  10, 1, 6,  12, 9,
                                14, 0, 15, 2, 13, 1,  15, 8, 0,  6,  14, 3, 12, 8,  4,  5, 10, 2,  7, 12 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_32_ex);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_16_ex);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_32_com);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_16_com);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_32_ex_com);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_16_ex_com);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_16_bg);

const s16 dir16_rl_conv[16] = { 0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_to_mvxy_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_move_data_easy);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_mvxy_data);
#else
void setup_mvxy_data(WORK *wk, u16 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_butt_own_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", read_adrs_store_mvxy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_weight_point);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", cal_mvxy_speed);
#else
void cal_mvxy_speed(WORK *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_mvxy_speed);
#else
void add_mvxy_speed(WORK *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_mvxy_speed_exp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_mvxy_speed_no_use_rl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_mvxy_speed_direct);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", reset_mvxy_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", remake_mvxy_PoSB);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", remake_mvxy_PoGR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_body_touch);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", meri_case_switch);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_body_touch2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_be_car_object);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", hoseishitemo_eenka);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_sel_hosei_tbl_ix);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_work_position_bonus);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", set_field_hosei_flag);
#else
s32 set_field_hosei_flag(PLW *pl, s16 pos, s16 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_work_position);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_32);

s32 random_16() {
    Random_ix16 += 1;

    if (Debug_w[0x3B] == 0xE0) {
        Random_ix16 = 0;
    }

    Random_ix16 &= 0x3F;
    return random_tbl_16[Random_ix16];
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_32_ex);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_16_ex);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_32_com);
#else
s32 random_32_com() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_16_com);
#else
s32 random_16_com() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_32_ex_com);
#else
s32 random_32_ex_com() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_16_ex_com);
#else
s32 random_16_ex_com() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_16_bg);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_guard_direction);

s16 cal_attdir(WORK *wk) {
    s16 resdir = wk->att.dir;

    if (wk->rl_flag) {
        resdir = dir16_rl_conv[resdir];
    }

    return resdir;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", cal_attdir_flip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_kind_of_head_dm);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_kind_of_trunk_dm);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_vitality);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", cal_dm_vital_gauge_hosei);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", set_hit_stop_hit_quake);

void add_sp_arts_gauge_init(PLW *wk) {
#if defined(TARGET_PS2)
    void add_super_arts_gauge(SA_WORK * wk, s32 ix, s32 asag, u16 mf);
#endif

    PLW *mwk;
    s16 asag;

    if (wk->wu.work_id != 1) {
        mwk = (PLW *)wk->cp;

        if ((mwk->wu.work_id == 1) && !(mwk->spmv_ng_flag2 & 0x20000000)) {
            asag = _add_arts_gauge[mwk->player_number][wk->wu.add_arts_point][0];
            add_super_arts_gauge(mwk->sa, mwk->wu.id, asag, mwk->metamorphose);
        }
    } else if (!(wk->spmv_ng_flag2 & 0x20000000)) {
        asag = _add_arts_gauge[wk->player_number][wk->wu.add_arts_point][0];
        add_super_arts_gauge(wk->sa, wk->wu.id, asag, wk->metamorphose);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_hit_dm);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", cal_sa_gauge_waribiki);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_paring);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_tokushu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_ukemi);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_nagenuke);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_maxbit);

#if defined(TARGET_PS2)
void add_super_arts_gauge(SA_WORK *wk, s16 ix, s16 asag, u8 mf) {
    if (!test_flag && !mf) {
        if ((wk->mp == -1) || (wk->ok == -1) || (wk->ex == -1)) {
            return;
        }

        if (!pcon_dp_flag && !Bonus_Game_Flag && (sa_gauge_omake[omop_sa_gauge_ix[ix]] != 0) && (asag > 0) &&
            (wk->store != wk->store_max)) {
            asag = asag * 0x78 / 100;

            if (save_w[Present_Mode].Battle_Number[Play_Type] == 0) {
                asag = asag * 0x96 / 100;
            }

            asag = asag * sa_gauge_omake[omop_sa_gauge_ix[ix]] / 32;

            if (asag == 0) {
                asag = 1;
            }

            wk->gauge.s.h += asag;
            wk->gauge.s.l = -1;

            if (wk->gauge.s.h > wk->gauge_len) {
                wk->store += 1;

                if (wk->store < wk->store_max) {
                    wk->gauge.s.h -= wk->gauge_len;
                } else {
                    wk->store = wk->store_max;
                    wk->gauge.i = 0;
                }

                sa_gauge_flash[ix] |= 1;
            }
        }
    }
}
#else
void add_super_arts_gauge(SA_WORK *wk, s16 ix, s16 asag, u8 mf) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_buttobi_type);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_buttobi_type2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_saishin_lvdir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_lvdir_after_autodir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dead_voice_request);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dead_voice_request2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dir16_hddm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dir16_trdm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", konjyou_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", apagt_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dir32_skydm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dir32_grddm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", convert_saishin_lvdir);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dead_voice_table);
