// Uncomment once effmovejptbl is fully decompiled
// #include "sf33rd/Source/Game/EFFXX.h"
#include "common.h"
#include "sf33rd/Source/Game/EFF00.h"
#include "sf33rd/Source/Game/EFF01.h"
#include "sf33rd/Source/Game/EFF02.h"
#include "sf33rd/Source/Game/EFF03.h"
#include "sf33rd/Source/Game/EFF04.h"
#include "sf33rd/Source/Game/EFF07.h"
#include "sf33rd/Source/Game/EFF09.h"
#include "sf33rd/Source/Game/EFF11.h"
#include "sf33rd/Source/Game/EFF16.h"
#include "sf33rd/Source/Game/EFF19.h"
#include "sf33rd/Source/Game/EFF21.h"
#include "sf33rd/Source/Game/EFF24.h"
#include "sf33rd/Source/Game/EFF25.h"
#include "sf33rd/Source/Game/EFF26.h"
#include "sf33rd/Source/Game/EFF27.h"
#include "sf33rd/Source/Game/EFF28.h"
#include "sf33rd/Source/Game/EFF38.h"
#include "sf33rd/Source/Game/EFF42.h"
#include "sf33rd/Source/Game/EFF48.h"
#include "sf33rd/Source/Game/EFF57.h"
#include "sf33rd/Source/Game/EFF58.h"
#include "sf33rd/Source/Game/EFF61.h"
#include "sf33rd/Source/Game/EFF62.h"
#include "sf33rd/Source/Game/EFF66.h"
#include "sf33rd/Source/Game/EFF69.h"
#include "sf33rd/Source/Game/EFF70.h"
#include "sf33rd/Source/Game/EFFA5.h"
#include "sf33rd/Source/Game/Eff39.h"
#include "sf33rd/Source/Game/Eff52.h"
#include "sf33rd/Source/Game/Eff59.h"
#include "sf33rd/Source/Game/EffD8.h"
#include "sf33rd/Source/Game/EffK6.h"
#include "sf33rd/Source/Game/eff06.h"
#include "sf33rd/Source/Game/eff12.h"
#include "sf33rd/Source/Game/eff36.h"
#include "sf33rd/Source/Game/efff6.h"

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFXX", effmovejptbl);
#else
const void (*effmovejptbl[229])() = {
    effect_00_move, // effect_00_move
    effect_01_move, // effect_01_move
    effect_02_move, // effect_02_move
    effect_03_move, // effect_03_move
    effect_04_move, // effect_04_move
    NULL,           // effect_05_move
    effect_06_move, // effect_06_move
    effect_07_move, // effect_07_move
    NULL,           // effect_08_move
    effect_09_move, // effect_09_move
    NULL,           // effect_10_move
    effect_11_move, // effect_11_move
    effect_12_move, // effect_12_move
    NULL,           // effect_13_move
    NULL,           // effect_14_move
    NULL,           // effect_15_move
    effect_16_move, // effect_16_move
    NULL,           // effect_17_move
    NULL,           // effect_18_move
    effect_19_move, // effect_19_move
    NULL,           // effect_20_move
    effect_21_move, // effect_21_move
    NULL,           // effect_22_move
    NULL,           // effect_23_move
    effect_24_move, // effect_24_move
    effect_25_move, // effect_25_move
    effect_26_move, // effect_26_move
    effect_27_move, // effect_27_move
    effect_28_move, // effect_28_move
    NULL,           // effect_29_move
    NULL,           // effect_30_move
    NULL,           // effect_31_move
    NULL,           // effect_32_move
    NULL,           // effect_33_move
    NULL,           // effect_34_move
    NULL,           // effect_35_move
    effect_36_move, // effect_36_move
    NULL,           // effect_37_move
    effect_38_move, // effect_38_move
    effect_39_move, // effect_39_move
    NULL,           // effect_40_move
    NULL,           // effect_41_move
    effect_42_move, // effect_42_move
    NULL,           // effect_43_move
    NULL,           // effect_44_move
    NULL,           // effect_45_move
    NULL,           // effect_46_move
    NULL,           // effect_47_move
    effect_48_move, // effect_48_move
    NULL,           // effect_49_move
    NULL,           // effect_50_move
    NULL,           // effect_51_move
    effect_52_move, // effect_52_move
    NULL,           // effect_53_move
    NULL,           // effect_54_move
    NULL,           // effect_55_move
    NULL,           // effect_56_move
    effect_57_move, // effect_57_move
    effect_58_move, // effect_58_move
    effect_59_move, // effect_59_move
    NULL,           // effect_60_move
    effect_61_move, // effect_61_move
    effect_62_move, // effect_62_move
    NULL,           // effect_63_move
    NULL,           // effect_64_move
    NULL,           // effect_65_move
    effect_66_move, // effect_66_move
    NULL,           // effect_67_move
    NULL,           // effect_68_move
    effect_69_move, // effect_69_move
    effect_70_move, // effect_70_move
    NULL,           // effect_71_move
    NULL,           // effect_72_move
    NULL,           // effect_73_move
    NULL,           // effect_74_move
    NULL,           // effect_75_move
    NULL,           // effect_76_move
    NULL,           // effect_77_move
    NULL,           // effect_78_move
    NULL,           // effect_79_move
    NULL,           // effect_80_move
    NULL,           // effect_81_move
    NULL,           // effect_82_move
    NULL,           // effect_83_move
    NULL,           // effect_84_move
    NULL,           // effect_85_move
    NULL,           // effect_86_move
    NULL,           // effect_87_move
    NULL,           // effect_dummy_move
    NULL,           // effect_dummy_move
    NULL,           // effect_90_move
    NULL,           // effect_91_move
    NULL,           // effect_92_move
    NULL,           // effect_93_move
    NULL,           // effect_94_move
    NULL,           // effect_95_move
    NULL,           // effect_96_move
    NULL,           // effect_97_move
    NULL,           // effect_98_move
    NULL,           // effect_99_move
    NULL,           // effect_A0_move
    NULL,           // effect_A1_move
    NULL,           // effect_A2_move
    NULL,           // effect_A3_move
    NULL,           // effect_dummy_move
    effect_A5_move, // effect_A5_move
    NULL,           // effect_A6_move
    NULL,           // effect_A7_move
    NULL,           // effect_A8_move
    NULL,           // effect_A9_move
    NULL,           // effect_B0_move
    NULL,           // effect_B1_move
    NULL,           // effect_B2_move
    NULL,           // effect_B3_move
    NULL,           // effect_B4_move
    NULL,           // effect_B5_move
    NULL,           // effect_B6_move
    NULL,           // effect_B7_move
    NULL,           // effect_B8_move
    NULL,           // effect_B9_move
    NULL,           // effect_C0_move
    NULL,           // effect_C1_move
    NULL,           // effect_C2_move
    NULL,           // effect_C3_move
    NULL,           // effect_C4_move
    NULL,           // effect_C5_move
    NULL,           // effect_C6_move
    NULL,           // effect_C7_move
    NULL,           // effect_C8_move
    NULL,           // effect_C9_move
    NULL,           // effect_D0_move
    NULL,           // effect_D1_move
    NULL,           // effect_dummy_move
    NULL,           // effect_D3_move
    NULL,           // effect_D4_move
    NULL,           // effect_D5_move
    NULL,           // effect_D6_move
    NULL,           // effect_D7_move
    effect_D8_move, // effect_D8_move
    NULL,           // effect_D9_move
    NULL,           // effect_E0_move
    NULL,           // effect_E1_move
    NULL,           // effect_E2_move
    NULL,           // effect_E3_move
    NULL,           // effect_E4_move
    NULL,           // effect_E5_move
    NULL,           // effect_E6_move
    NULL,           // effect_E7_move
    NULL,           // effect_E8_move
    NULL,           // effect_E9_move
    NULL,           // effect_F0_move
    NULL,           // effect_dummy_move
    NULL,           // effect_F2_move
    NULL,           // effect_dummy_move
    NULL,           // effect_F4_move
    NULL,           // effect_F5_move
    effect_F6_move, // effect_F6_move
    NULL,           // effect_dummy_move
    NULL,           // effect_F8_move
    NULL,           // effect_F9_move
    NULL,           // effect_G0_move
    NULL,           // effect_dummy_move
    NULL,           // effect_dummy_move
    NULL,           // effect_G3_move
    NULL,           // effect_G4_move
    NULL,           // effect_G5_move
    NULL,           // effect_G6_move
    NULL,           // effect_G7_move
    NULL,           // effect_G8_move
    NULL,           // effect_G9_move
    NULL,           // effect_H0_move
    NULL,           // effect_H1_move
    NULL,           // effect_H2_move
    NULL,           // effect_dummy_move
    NULL,           // effect_dummy_move
    NULL,           // effect_dummy_move
    NULL,           // effect_H6_move
    NULL,           // effect_dummy_move
    NULL,           // effect_dummy_move
    NULL,           // effect_H9_move
    NULL,           // effect_I0_move
    NULL,           // effect_dummy_move
    NULL,           // effect_dummy_move
    NULL,           // effect_I3_move
    NULL,           // effect_I4_move
    NULL,           // effect_dummy_move
    NULL,           // effect_I6_move
    NULL,           // effect_I7_move
    NULL,           // effect_I8_move
    NULL,           // effect_I9_move
    NULL,           // effect_J0_move
    NULL,           // effect_dummy_move
    NULL,           // effect_J2_move
    NULL,           // effect_dummy_move
    NULL,           // effect_J4_move
    NULL,           // effect_dummy_move
    NULL,           // effect_J6_move
    NULL,           // effect_J7_move
    NULL,           // effect_J8_move
    NULL,           // effect_J9_move
    NULL,           // effect_dummy_move
    NULL,           // effect_dummy_move
    NULL,           // effect_K2_move
    NULL,           // effect_K3_move
    NULL,           // effect_K4_move
    NULL,           // effect_K5_move
    effect_K6_move, // effect_K6_move
    NULL,           // effect_K7_move
    NULL,           // effect_K8_move
    NULL,           // effect_K9_move
    NULL,           // effect_L0_move
    NULL,           // effect_L1_move
    NULL,           // effect_L2_move
    NULL,           // effect_L3_move
    NULL,           // effect_L4_move
    NULL,           // effect_L5_move
    NULL,           // effect_L6_move
    NULL,           // effect_L7_move
    NULL,           // effect_L8_move
    NULL,           // effect_L9_move
    NULL,           // effect_M0_move
    NULL,           // effect_M1_move
    NULL,           // effect_M2_move
    NULL,           // effect_M3_move
    NULL,           // effect_dummy_move
    NULL,           // effect_M5_move
    NULL,           // effect_M6_move
    NULL,           // effect_M7_move
    NULL,           // effect_M8_move
};
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFXX", effinitjptbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFXX", effect_dummy_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFXX", effect_dummy_move);
