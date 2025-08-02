#include "sf33rd/Source/Game/Com_Pl.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/Source/Game/CMD_MAIN.h"
#include "sf33rd/Source/Game/Ck_Pass.h"
#include "sf33rd/Source/Game/Com_Data.h"
#include "sf33rd/Source/Game/Com_Sub.h"
// #include "sf33rd/Source/Game/Getup.h"
#include "sf33rd/Source/Game/PLCNT.h"
// #include "sf33rd/Source/Game/PLMAIN.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/cmd_data.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/workuser.h"

const u16 Correct_Lv_Data[16] = { 0, 1, 2, 2, 4, 5, 6, 5, 8, 9, 10, 9, 8, 5, 10, 0 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", literal_204_00504830);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", cpu_algorithm);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", CPU_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Main_Program);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Initialize);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Free);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Before_Follow);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Before_Passive);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Counter_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Hamari);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Guard_VS_Shell);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_No12_Shell_Guard);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Guard_Type);
#else
void Check_Guard_Type(PLW *wk, WORK *em) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Ck_Exit_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Ck_Exit_Guard_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Active);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Follow);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Passive);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_VS_Shell);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_5th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_6th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_7th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_8th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Exit_Damage_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Float);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Float_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Float_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Float_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Flip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_Zero);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Flip_GO);
#else
s32 Check_Flip_GO(PLW *wk, s16 xx) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_4th);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", SetShellFlipLever);
#else
s32 SetShellFlipLever(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Shell_Flip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Flip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Flip_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Caught);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Decide_Exit_Catch);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Rapid_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Caught);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Catch);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Be_Catch);
#else
void Be_Catch(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Wait_Lie);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Command_Attack_SP);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Next_Be_Free);
#else
void Next_Be_Free(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Next_Be_Float);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Clear_Com_Flag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_At_Count);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Shift_Resume_Lv);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Check_Store_Lv);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Store_LR_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Setup_Bullet_Counter);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Pattern_Insurance);

const u8 Rapid_Lever_Data[2] = { 8, 4 };

const u8 Pattern_Insurance_Data[20][4] = {
    { 67, 157, 10, 3 }, { 69, 175, 9, 3 },  { 74, 132, 10, 3 }, { 71, 135, 10, 3 },  { 67, 141, 11, 3 },
    { 66, 101, 10, 3 }, { 63, 146, 10, 3 }, { 75, 213, 11, 3 }, { 70, 213, 10, 3 },  { 100, 131, 10, 3 },
    { 69, 137, 10, 3 }, { 89, 254, 13, 3 }, { 85, 230, 10, 3 }, { 80, 167, 11, 3 },  { 150, 252, 12, 3 },
    { 68, 163, 13, 3 }, { 69, 166, 13, 3 }, { 82, 181, 13, 3 }, { 108, 203, 13, 3 }, { 78, 175, 13, 3 }
};
