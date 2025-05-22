#include "sf33rd/Source/Game/sel_pl.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Cursor_Y_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Arts_Y_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Repeat_Time_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Repeat_Time_Data_Wife);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Select_Player);
#else
s16 Select_Player() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Switch_Work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Cont_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Check_Use_Gill);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Cont_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Cont_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Cont_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_Face_ID);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_1st_Play_Type);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_Face_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_Select_Status);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_Aborigine);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_Cursor_Y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Initialize_BG);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_BG_General);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_FACE_BG);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_Face_X);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_Face_Y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Face_Control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Face_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Face_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Face_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Face_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Move_Face_BG);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", OBJ_Control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", OBJ_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", OBJ_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", OBJ_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_EFF69);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Go_Away_Red_Lines);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Player_Select_Control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", PL_Sel_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", PL_Sel_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", PL_Sel_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", PL_Sel_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", PL_Sel_5th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_Plates);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Deley_Shot_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_5th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_6th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Disposal_Of_Diagonal);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Sub_CR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Sub_CL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Sub_CU);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_PL_Sub_CD);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Auto_Repeat_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Auto_Repeat_Sub_Wife);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Sel_Arts_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Check_Exit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Exit_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Exit_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Exit_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Exit_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Exit_5th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Exit_6th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Exit_7th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_Control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_Vital_Select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_Vital_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_Stage_Select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Handicap_Stage_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Correct_Control_Time);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Check_Boss);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sel_pl", Setup_Battle_Country);
