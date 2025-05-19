#include "common.h"

// sbss
s8 Debug_w[72];
s8 Debug_Index;
u8 Deley_Debug_No;
u8 Deley_Debug_Timer;
u8 Deley_Debug_No2;
u8 Deley_Debug_Timer2;
u8 Debug_Pause;
u8 sysFF;
u8 sysSLOW;
s8 Slow_Timer;
u8 check_screen_S;
u8 check_screen_L;
u8 check_time_S;
u8 check_time_L;
u32 Rec_Time[2];
u32 Record_Timer;
s16 time_check[4];
u8 time_check_ix;

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_Task);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_1st);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_247_00558C90);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_2nd);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_279_00558CA0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_280_00558CA8);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_Menu_Disp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_Move_Sub);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_Deley_Time);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_Menu_Lever);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_Deley_Time2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Debug_Menu_Shot);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_407_00558CC8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_408_00558CD0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_409_00558CE0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_410_00558CE8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_411_00558CF0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_412_00558CF8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_413_00558D00);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_414_00558D08);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_415_00558D10);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_416_00558D18);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_417_00558D20);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_418_00558D28);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Check_Check_Screen);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Disp_Lever);

// Used in functions below
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_445_00558D30);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Check_Pos_OBJ);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Check_Pos_OBJ2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_475_00558D38);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_476_00558D48);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Check_Pos_BG);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Check_Exit_Check);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_498_00558D50);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_499_00558D60);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Disp_Rec_Time);

// Also used in Disp_Free_work
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_517_00558D68);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", literal_530_00558D70);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Disp_Mode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Disp_Free_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/debug/Debug", Disp_Random);

s8 *cpu_data[16] = { "", "FR", "AC", "BF", "FW", "BP", "PS", "GD", "SH", "SG", "DM", "FL", "FP", "CT", "WL", "CH" };
