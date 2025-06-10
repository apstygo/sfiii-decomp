#include "sf33rd/Source/Game/Ck_Pass.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Ck_Passive_Term);
#else
s32 Ck_Passive_Term(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", KEN_vs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", HUGO_vs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", GILL_vs);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Special_Technique);
#else
s32 Check_Special_Technique(PLW *wk, WORK *em, s16 VS_Technique, u8 Kind_of_Tech, u8 SP_Tech_ID, s16 Option,
                            s16 Option2) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Attack_Direction);
#else
s32 Check_Attack_Direction(PLW *wk, WORK *em) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_VS_Jump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Rolling);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Personal_Action);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Specific_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Dash);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Limited_Attack);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Limited_Jump_Attack);
#else
s32 Check_Limited_Jump_Attack(PLW *wk, WORK *em, u8 PL_Status, s8 Status_00) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Stand);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Setup_Next_Stand_Timer);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_VS_Squat);
#else
s32 Check_VS_Squat(PLW *wk, WORK *em, s16 VS_Technique, u8 Status_00, u8 Status_01) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Setup_Next_Squat_Timer);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Thrown);
#else
s32 Check_Thrown(PLW *wk, WORK *em) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Catch);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Lie);
#else
s32 Check_Lie(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Faint);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Blow_Off);
#else
s32 Check_Blow_Off(PLW *wk, WORK *em, s16 VS_Technique) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_After_Attack);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_F_Cross_Chop);
#else
s32 Check_F_Cross_Chop(PLW *wk, WORK *em, s16 VS_Technique) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_PL_Unit_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GILL_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ALEX_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_RYU_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_YUN_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_DUDLEY_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NECRO_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_HUGO_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_IBUKI_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ELENA_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ORO_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_KEN_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_SEAN_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_URIEN_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GOUKI_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_CHUN_LI_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_MAKOTO_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_Q_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NO12_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_REMY_AS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_PL_Unit_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GILL_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ALEX_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_RYU_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_YUN_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_DUDLEY_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NECRO_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_HUGO_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_IBUKI_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ELENA_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ORO_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_KEN_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_SEAN_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_URIEN_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GOUKI_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_CHUN_LI_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_MAKOTO_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_Q_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NO12_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_REMY_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_PL_Unit_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GILL_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ALEX_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_RYU_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_YUN_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_DUDLEY_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NECRO_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_HUGO_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_IBUKI_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ELENA_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ORO_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_KEN_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_SEAN_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_URIEN_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GOUKI_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_CHUN_LI_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_MAKOTO_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_Q_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NO12_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_REMY_BS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_PL_Unit_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GILL_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ALEX_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_RYU_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_YUN_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_DUDLEY_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NECRO_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_HUGO_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_IBUKI_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ELENA_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ORO_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_KEN_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_SEAN_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_URIEN_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GOUKI_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_CHUN_LI_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_MAKOTO_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_Q_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NO12_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_REMY_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_PL_Unit_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GILL_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ALEX_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_RYU_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_YUN_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_DUDLEY_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NECRO_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_HUGO_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_IBUKI_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ELENA_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ORO_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_KEN_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_SEAN_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_URIEN_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GOUKI_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_CHUN_LI_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_MAKOTO_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_Q_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NO12_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_REMY_CS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_PL_Unit_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GILL_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ALEX_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_RYU_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_YUN_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_DUDLEY_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NECRO_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_HUGO_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_IBUKI_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ELENA_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ORO_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_KEN_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_SEAN_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_URIEN_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GOUKI_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_CHUN_LI_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_MAKOTO_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_Q_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NO12_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_REMY_C);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_PL_Unit_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GILL_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ALEX_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_RYU_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_YUN_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_DUDLEY_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NECRO_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_IBUKI_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_HUGO_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ELENA_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ORO_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_KEN_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_SEAN_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_URIEN_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GOUKI_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_CHUN_LI_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_MAKOTO_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_Q_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NO12_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_REMY_DS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_PL_Unit_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GILL_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ALEX_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_RYU_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_YUN_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_DUDLEY_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NECRO_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_HUGO_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_IBUKI_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ELENA_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_ORO_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_KEN_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_SEAN_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_URIEN_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_GOUKI_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_CHUN_LI_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_MAKOTO_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_Q_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_NO12_D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", VS_REMY_D);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Passive_jmp_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Passive_AS_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Passive_A_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Passive_BS_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Passive_B_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Passive_CS_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Passive_C_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Passive_DS_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Passive_D_tbl);
