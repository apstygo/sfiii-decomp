#include "common.h"
#include "structs.h"

void Normal_00000(PLW *wk);
void Normal_01000(PLW *wk);
void Normal_02000(PLW *wk);
void Normal_03000(PLW *wk);
void Normal_04000(PLW *wk);
void Normal_05000(PLW *wk);
void nm_05_0000(PLW *wk);
void nm_05_0100(PLW *wk);
void Normal_06000(PLW *wk);
void nm_06_0000(PLW *wk);
void nm_06_0100(PLW *wk);
void nm_06_0200(PLW *wk);
void Normal_07000(PLW *wk);
void Normal_08000(PLW *wk);
void Normal_09000(PLW *wk);
void Normal_10000(PLW *wk);
void Normal_16000(PLW *wk);
void Normal_17000(PLW *wk);
void Normal_18000(PLW *wk);
void Normal_27000(PLW *wk);
void Normal_31000(PLW *wk);
void Normal_35000(PLW *wk);
void Normal_36000(PLW *wk);
void Normal_37000(PLW *wk);
void Normal_38000(PLW *wk);
void Normal_39000(PLW *wk);
void Normal_40000(PLW *wk);
void Normal_41000(PLW *wk);
void Normal_42000(PLW *wk);
void Normal_47000(PLW *wk);
void Normal_48000(PLW *wk);
void Normal_50000(PLW *wk);
void Normal_51000(PLW *wk);
void Normal_52000(PLW *wk);
void Normal_53000(PLW *wk);
void Normal_54000(PLW *wk);
void Normal_55000(PLW *wk);
void Normal_56000(PLW *wk);
void Normal_57000(PLW *wk);
void Normal_58000(PLW *wk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Player_normal);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", setup_normal_process_flags);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_00000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_01000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_02000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_03000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_04000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_05000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_05_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_05_0100);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_06000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_06_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_06_0100);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_06_0200);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_07000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_08000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_09000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_10000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_16000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_17000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_18000);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_18000_init_unit);
#else
void Normal_18000_init_unit(PLW *wk, u8 ps) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_27000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_31000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_35000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_36000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_37000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_38000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_39000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_40000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_41000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_42000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_47000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_48000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_50000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_51000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_52000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_53000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_54000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_55000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", make_nm55_init_sp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_56000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm56_char_select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_57000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm57_dir_select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_58000);

const s16 nmPB_data[5][3] = { { 38, 23, 1 }, { 39, 23, 1 }, { 40, 24, 1 }, { 41, 25, 0 }, { 42, 25, 0 } };
const s16 nmCE_data[4][3] = { { 43, 26, 1 }, { 44, 27, 1 }, { 45, 28, 0 }, { 46, 29, 0 } };

void (*const plpnm_lv_00[59])(PLW *wk) = {
    Normal_00000, Normal_01000, Normal_02000, Normal_03000, Normal_04000, Normal_05000, Normal_06000, Normal_07000,
    Normal_08000, Normal_09000, Normal_10000, Normal_03000, Normal_04000, Normal_03000, Normal_03000, Normal_03000,
    Normal_16000, Normal_17000, Normal_18000, Normal_18000, Normal_18000, Normal_18000, Normal_18000, Normal_18000,
    Normal_18000, Normal_18000, Normal_18000, Normal_27000, Normal_27000, Normal_27000, Normal_27000, Normal_31000,
    Normal_31000, Normal_31000, Normal_35000, Normal_35000, Normal_36000, Normal_37000, Normal_38000, Normal_39000,
    Normal_40000, Normal_41000, Normal_42000, Normal_42000, Normal_42000, Normal_42000, Normal_42000, Normal_47000,
    Normal_48000, Normal_47000, Normal_50000, Normal_51000, Normal_52000, Normal_53000, Normal_54000, Normal_55000,
    Normal_56000, Normal_57000, Normal_58000
};

void (*const normal_05[])(PLW *wk) = { nm_05_0000, nm_05_0000, nm_05_0100, nm_05_0000, nm_05_0000,
                                       nm_05_0000, nm_05_0000, nm_05_0000, nm_05_0100, nm_05_0000,
                                       nm_05_0000, nm_05_0100, nm_05_0100, nm_05_0000, nm_05_0100,
                                       nm_05_0000, nm_05_0100, nm_05_0000, nm_05_0000, nm_05_0000 };

void (*const normal_06[])(PLW *wk) = { nm_06_0100, nm_06_0100, nm_06_0200, nm_06_0000, nm_06_0100,
                                       nm_06_0100, nm_06_0100, nm_06_0100, nm_06_0000, nm_06_0100,
                                       nm_06_0000, nm_06_0200, nm_06_0200, nm_06_0100, nm_06_0200,
                                       nm_06_0000, nm_06_0200, nm_06_0100, nm_06_0100, nm_06_0100 };

const u16 jpdat_tbl[9][2] = { { 17, 6 },  { 18, 7 },  { 19, 8 },  { 14, 9 }, { 15, 10 },
                              { 16, 11 }, { 20, 12 }, { 21, 13 }, { 22, 14 } };
