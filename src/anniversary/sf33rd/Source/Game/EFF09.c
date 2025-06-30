#include "sf33rd/Source/Game/EFF09.h"
#include "common.h"

void (*eff09_tbl[28])(WORK_Other *ewk) = { eff09_0000,  eff09_1000,  eff09_2000,  eff09_3000,  eff09_4000,  eff09_5000,
                                           eff09_6000,  eff09_7000,  eff09_8000,  eff09_9000,  eff09_10000, eff09_11000,
                                           eff09_12000, eff09_13000, eff09_14000, eff09_15000, eff09_16000, eff09_17000,
                                           eff09_18000, eff09_19000, eff09_20000, eff09_21000, eff09_22000, eff09_23000,
                                           eff09_24000, eff09_25000, eff09_26000, eff09_27000 };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", effect_09_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_0000);
#else
void eff09_0000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_1000);
#else
void eff09_1000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_2000);
#else
void eff09_2000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", sean_ball_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", ball_bound_set);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_3000);
#else
void eff09_3000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_4000);
#else
void eff09_4000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_5000);
#else
void eff09_5000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_6000);
#else
void eff09_6000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_7000);
#else
void eff09_7000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_8000);
#else
void eff09_8000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_9000);
#else
void eff09_9000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_10000);
#else
void eff09_10000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_11000);
#else
void eff09_11000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_12000);
#else
void eff09_12000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_13000);
#else
void eff09_13000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_14000);
#else
void eff09_14000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_15000);
#else
void eff09_15000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_16000);
#else
void eff09_16000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_17000);
#else
void eff09_17000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_18000);
#else
void eff09_18000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_19000);
#else
void eff09_19000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_20000);
#else
void eff09_20000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_21000);
#else
void eff09_21000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_22000);
#else
void eff09_22000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_23000);
#else
void eff09_23000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_24000);
#else
void eff09_24000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_25000);
#else
void eff09_25000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_26000);
#else
void eff09_26000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", jijii_win_tama_sub);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", eff09_27000);
#else
void eff09_27000(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", effect_09_init);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF09", effect_09_init2);
#else
s32 effect_09_init2(WORK *wk, u8 data) {
    not_implemented(__func__);
}
#endif

const s16 eff09_data[2][9] = { { 0x0000, 0x0002, 0x212C, 0x0340, 0x00C0, 0x000A, 0x0000, 0x0001, 0x0000 },
                               { 0x0013, 0x0002, 0x212C, 0x0210, 0x006C, 0x004E, 0x0001, 0x0000, 0x0000 } };

const s16 eff09_data2[43][8] = { { 0x0001, 0x0000, 0x0000, 0x0004, 0x0001, 0x0019, 0x0001, 0x0000 },
                                 { 0x0002, 0x0000, 0xFFDE, 0x0099, 0xFFF6, 0x001A, 0x0001, 0x0000 },
                                 { 0x0003, 0x0006, 0x0030, 0x00F0, 0xFFFF, 0x0063, 0x0001, 0x0000 },
                                 { 0x0004, 0x0000, 0x0030, 0xFFFC, 0xFFF6, 0x001C, 0x0001, 0x0000 },
                                 { 0x0005, 0x0000, 0x000A, 0x0060, 0xFFEC, 0x002E, 0x0001, 0x0000 },
                                 { 0x0006, 0x0000, 0x0000, 0x0000, 0xFFEC, 0x002F, 0x0001, 0x0000 },
                                 { 0x0007, 0x0000, 0x0000, 0x0050, 0xFFF6, 0x002B, 0x0001, 0x0000 },
                                 { 0x0000, 0x0000, 0xFFDA, 0x0054, 0xFFFE, 0x0029, 0x0001, 0x0000 },
                                 { 0x0008, 0x0000, 0x0000, 0x0000, 0xFFFE, 0x0037, 0x0001, 0x0000 },
                                 { 0x0008, 0x0000, 0x0000, 0x0000, 0xFFFE, 0x0038, 0x0001, 0x0000 },
                                 { 0x0009, 0x0000, 0x0000, 0x0000, 0xFFF4, 0x0047, 0x0001, 0x0000 },
                                 { 0x0009, 0x0000, 0x0000, 0x0000, 0xFFF4, 0x0048, 0x0001, 0x0000 },
                                 { 0x000A, 0x0000, 0x0000, 0x0000, 0xFFF4, 0x0049, 0x0001, 0x0000 },
                                 { 0x000B, 0x0000, 0x0030, 0xFFF6, 0xFFF6, 0x001C, 0x0001, 0x0000 },
                                 { 0x000C, 0x0000, 0x0000, 0x004A, 0x0002, 0x004B, 0x0001, 0x0000 },
                                 { 0x000D, 0x0000, 0xFFFC, 0x009A, 0xFFFE, 0x0050, 0x0001, 0x0000 },
                                 { 0x000D, 0x0000, 0xFFE0, 0x0070, 0xFFFE, 0x0051, 0x0001, 0x0000 },
                                 { 0x000D, 0x0000, 0x0010, 0x007A, 0xFFFE, 0x0052, 0x0001, 0x0000 },
                                 { 0x000E, 0x001A, 0x002D, 0x0000, 0xFFF0, 0x0054, 0x0001, 0x0000 },
                                 { 0x000E, 0x001A, 0x000C, 0x0000, 0xFFF0, 0x0054, 0x0001, 0x0000 },
                                 { 0x000F, 0x0000, 0xFFEE, 0x003E, 0xFFFE, 0x0055, 0x0001, 0x0000 },
                                 { 0x0011, 0x0000, 0xFFE0, 0x0048, 0xFFFE, 0x0055, 0x0001, 0x0000 },
                                 { 0x0010, 0x0000, 0x0000, 0x0000, 0xFFF4, 0x0057, 0x0001, 0x0000 },
                                 { 0x0012, 0x0000, 0x0000, 0x0000, 0x0001, 0x0060, 0x0001, 0x0000 },
                                 { 0x0014, 0x0000, 0x00A0, 0x002D, 0x000A, 0x0014, 0x0001, 0x0000 },
                                 { 0x0014, 0x0000, 0x00C0, 0x002D, 0x000A, 0x0015, 0x0001, 0x0000 },
                                 { 0x0014, 0x0000, 0x00D0, 0x002D, 0x000A, 0x0016, 0x0001, 0x0000 },
                                 { 0x0014, 0x0000, 0x00B0, 0x002D, 0x000A, 0x0017, 0x0001, 0x0000 },
                                 { 0x0005, 0x0000, 0x001E, 0x0003, 0x0002, 0x0030, 0x0001, 0x0000 },
                                 { 0x0015, 0x0000, 0xFFE8, 0x0088, 0xFFFE, 0x0033, 0x0001, 0x0000 },
                                 { 0x0015, 0x0000, 0xFFE8, 0x0088, 0xFFFE, 0x0033, 0x0001, 0x0000 },
                                 { 0x0000, 0x001A, 0x0022, 0x002A, 0xFFFE, 0x003C, 0x0001, 0x0000 },
                                 { 0x0016, 0x0000, 0x0000, 0x0000, 0xFFFE, 0x003D, 0x0001, 0x0000 },
                                 { 0x0017, 0x0000, 0x0048, 0xFFFB, 0x0002, 0x003F, 0x0001, 0x0000 },
                                 { 0x0018, 0x0000, 0xFFA0, 0x0008, 0x0004, 0x0061, 0x0001, 0x0000 },
                                 { 0x0018, 0x0000, 0x0050, 0x0004, 0x0003, 0x0062, 0x0001, 0x0000 },
                                 { 0x0019, 0x0000, 0x0044, 0x0028, 0x0001, 0x001A, 0x0001, 0x0000 },
                                 { 0x0019, 0x0000, 0x002A, 0x0033, 0x0001, 0x001A, 0x0001, 0x0000 },
                                 { 0x0018, 0x0000, 0xFE50, 0x0004, 0x0003, 0x0062, 0x0001, 0x0000 },
                                 { 0x0018, 0x0000, 0xFF40, 0x0008, 0x0004, 0x0058, 0x0001, 0x0000 },
                                 { 0x0018, 0x0000, 0xFED0, 0x0008, 0x0004, 0x0061, 0x0001, 0x0000 },
                                 { 0x001A, 0x0006, 0x0000, 0x0000, 0x0001, 0x0065, 0x0001, 0x0000 },
                                 { 0x001B, 0x0000, 0x0000, 0x0010, 0xFFF6, 0x006B, 0x0001, 0x0000 } };

const s32 eff09_2000_data[2][4] = { { 0xFFFF0000, 0x00050000, 0xFFFFF000, 0xFFFFA000 },
                                    { 0xFFFB0000, 0x00060000, 0xFFFFF400, 0xFFFFA000 } };

const s32 eff09_add_tbl0[2][2] = { { 0x00000800, 0xFFFFF800 }, { 0x00000800, 0xFFFFF000 } };

const s32 eff09_add_tbl1[2][2] = { { 0xFFFFF800, 0x00000800 }, { 0xFFFFEE00, 0x00001000 } };

const s32 eff09_add_tbl2[2][2] = { { 0xFFFFF800, 0x00000800 }, { 0xFFFFF000, 0x00001200 } };

const s16 sean_ball_hit[4] = { 0xFFF0, 0x0020, 0xFFF5, 0x0016 };

const s32 eff09_13_tbl[3][4] = { { 0x00000000, 0x00001000, 0x00030000, 0x00000000 },
                                 { 0x00048000, 0x00001000, 0x00028000, 0x00000000 },
                                 { 0xFFFB8000, 0xFFFFF000, 0x00028000, 0x00000000 } };

const s32 eff09_19000_tbl[3][4] = { { 0x00030000, 0x00000000, 0x00010000, 0xFFFFA000 },
                                    { 0x00020000, 0x00000000, 0x00048000, 0xFFFFA000 },
                                    { 0x00018000, 0x00000000, 0x00030000, 0xFFFFA000 } };
