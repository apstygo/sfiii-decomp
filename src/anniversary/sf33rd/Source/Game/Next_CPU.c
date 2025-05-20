#include "sf33rd/Source/Game/Next_CPU.h"
#include "common.h"

// sbss
u8 SEL_CPU_X;
s16 Start_X;

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU);
#else
s16 Next_CPU() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU_4th_0_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU_4th_1_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU_4th_2_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU_5th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Check_EM_Speech);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_CPU_6th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Wait_Load_Complete);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Wait_Load_Complete2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Wait_Load_Complete3);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", After_Bonus);
#else
s32 After_Bonus() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", After_Bonus_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", After_Bonus_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Select_CPU_First);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Select_CPU_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Select_CPU_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", NC_Cut_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Select_CPU_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Select_CPU_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_Bonus_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_Bonus_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_Bonus_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_Bonus_End);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_Q);
#else
s16 Next_Q() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_Q_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_Q_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Next_Q_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Sel_CPU_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Setup_EM_List);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Setup_Next_Fighter);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Arts_Rnd_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Setup_Com_Arts);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Setup_Com_Color);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Setup_PL_Color);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Setup_Regular_OBJ);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Regular_OBJ_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Setup_History_OBJ);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Setup_VS_OBJ);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Check_Bonus_Stage);
#else
s8 Check_Bonus_Stage() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Check_Bonus_Type);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Setup_Next_Stage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Check_Auto_Cut);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Next_CPU", Auto_Cut_Sub);
