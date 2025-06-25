#include "sf33rd/Source/Game/Ck_Pass.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Data.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/workuser.h"

s8 PASSIVE_X;

s32 Ck_Passive_Term(PLW *wk) {
    PASSIVE_X = 0;
    Passive_jmp_tbl[((PLW *)wk->wu.target_adrs)->player_number](wk);
    return PASSIVE_X;
}

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

s32 Check_Attack_Direction(PLW *wk, WORK *em) {
    if (wk->wu.xyz[0].disp.pos < em->xyz[0].disp.pos) {
        if (em->xyz[0].disp.pos > em->old_pos[0])
            return 1;
    } else if (em->xyz[0].disp.pos < em->old_pos[0]) {
        return 1;
    }

    return 0;
}

s32 Check_VS_Jump(PLW *wk, PLW *em, s16 Height) {
    if (em->wu.routine_no[1] == 1)
        return 0;

    if (em->wu.sp_tech_id == 33)
        return 0;

    if (Jump_Pass_Timer[wk->wu.id][Area_Number[wk->wu.id]]) {
        Jump_Pass_Timer[wk->wu.id][Area_Number[wk->wu.id]]--;
        return 0;
    }

    if ((em->wu.mvxy.a[1].real.h) < 0 && (em->wu.xyz[1].disp.pos <= Height))
        return 0;

    if (Check_Specific_Term(wk, &em->wu, 0x1003, 14, 20, 26))
        return Counter_Attack[wk->wu.id] = 1;

    if (em->wu.xyz[1].disp.pos == 0)
        return 0;

    if ((em->wu.xyz[1].disp.pos < 32) && (em->wu.mvxy.a[1].real.h > 0))
        return 0;

    if (em->micchaku_flag) {
        VS_Tech[wk->wu.id] = 18;
        return PASSIVE_X = 1;
    }

    if (Check_Specific_Term(wk, &em->wu, 18, 22, 28, 16))
        return 1;

    VS_Tech[wk->wu.id] = 0;
    return 0;
}

s32 Check_Rolling(PLW *wk, WORK *em) {
    if (em->pat_status != 34)
        return 0;

    if (Check_Attack_Direction(wk, em)) {
        VS_Tech[wk->wu.id] = 6;
    } else {
        VS_Tech[wk->wu.id] = 5;
    }

    return PASSIVE_X = 1;
}

s32 Check_Personal_Action(PLW *wk, WORK *em) {
    if (em->routine_no[1] != 4)
        return 0;
    if (em->routine_no[2] != 0x1E)
        return 0;

    VS_Tech[wk->wu.id] = 0x1009;

    return PASSIVE_X = 1;
}

s32 Check_Specific_Term(PLW *wk, WORK *em, s16 VS_Technique, u8 Status_00, u8 Status_01, u8 Status_02) {
    VS_Tech[wk->wu.id] = VS_Technique;

    if (em->pat_status == Status_00)
        return PASSIVE_X = 1;

    if (em->pat_status == Status_01)
        return PASSIVE_X = 1;

    if (em->pat_status == Status_02)
        return PASSIVE_X = 1;

    return 0;
}

s32 Check_Dash(PLW *wk, WORK *em, s16 VS_Technique) {
    if ((em->routine_no[1] == 0) && (em->routine_no[2] == 5) && (em->routine_no[3] != 0)) {
        VS_Tech[wk->wu.id] = VS_Technique;

        return PASSIVE_X = 1;
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Limited_Attack);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Limited_Jump_Attack);
#else
s32 Check_Limited_Jump_Attack(PLW *wk, WORK *em, u8 PL_Status, s8 Status_00) {
    not_implemented(__func__);
}
#endif

s32 Check_Stand(PLW *wk, WORK *em, s16 VS_Technique) {
    if (Attack_Flag[wk->wu.id])
        return 0;

    if (em->routine_no[1] != 0)
        return 0;

    if ((Standing_Timer[wk->wu.id] += 1) < Standing_Master_Timer[wk->wu.id])
        return 0;

    Standing_Master_Timer[wk->wu.id] = Setup_Next_Stand_Timer(wk);
    VS_Tech[wk->wu.id] = VS_Technique;

    return PASSIVE_X = 1;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Setup_Next_Stand_Timer);

s32 Check_VS_Squat(PLW *wk, WORK *em, s16 VS_Technique, u8 Status_00, u8 Status_01) {
    if (Attack_Flag[wk->wu.id])
        return Squat_Timer[wk->wu.id] = 0;

    if (em->routine_no[1] != 0)
        return Squat_Timer[wk->wu.id] = 0;

    if (em->xyz[1].disp.pos)
        return Squat_Timer[wk->wu.id] = 0;

    if (em->pat_status != Status_00 && em->pat_status != Status_01)
        return Squat_Timer[wk->wu.id] = 0;

    if ((Squat_Timer[wk->wu.id] += 1) < Squat_Master_Timer[wk->wu.id])
        return 0;

    Squat_Master_Timer[wk->wu.id] = Setup_Next_Squat_Timer(wk);
    VS_Tech[wk->wu.id] = VS_Technique;

    return PASSIVE_X = 1;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Setup_Next_Squat_Timer);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Thrown);
#else
s32 Check_Thrown(PLW *wk, WORK *em) {
    not_implemented(__func__);
}
#endif

s32 Check_Catch(PLW *wk, WORK *em, s16 VS_Technique) {
    u16 xx;

    if (Demo_Flag == 0)
        return 0;

    if (em->routine_no[1] != 0)
        return 0;

    if (em->xyz[1].disp.pos)
        return 0;

    if (wk->wu.id == 0) {
        xx = p2sw_0;
    } else {
        xx = p1sw_0;
    }

    if (wk->wu.rl_waza) {
        if (!(xx & 4)) {
            return 0;
        }
    } else if (!(xx & 8)) {
        return 0;
    }

    Counter_Attack[wk->wu.id] = 1;
    VS_Tech[wk->wu.id] = VS_Technique;

    return PASSIVE_X = 1;
}

s32 Check_Lie(PLW *wk) {
    WORK *em;
    PLW *enemy;

    em = (WORK *)wk->wu.target_adrs;
    enemy = (PLW *)wk->wu.target_adrs;

    if (Check_Faint(wk, enemy, 2))
        return Select_Passive(wk);

    if (Check_Specific_Term(wk, em, 0, 38, 38, 38))
        return Select_Passive(wk);

    return 0;
}

s32 Check_Faint(PLW *wk, PLW *enemy, s16 VS_Technique) {
    Counter_Attack[wk->wu.id] = 1;
    VS_Tech[wk->wu.id] = VS_Technique;

    if ((enemy->wu.routine_no[1] == 1) && (enemy->wu.routine_no[2] == 25))
        return 1;

    return Counter_Attack[wk->wu.id] = 0;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Ck_Pass", Check_Blow_Off);
#else
s32 Check_Blow_Off(PLW *wk, WORK *em, s16 VS_Technique) {
    not_implemented(__func__);
}
#endif

s32 Check_After_Attack(PLW *wk, WORK *em, s16 VS_Technique) {
    u8 xx;

    if (CP_No[wk->wu.id][0] == 7)
        return 0;

    if (Last_Attack_Counter[wk->wu.id] == Attack_Counter[wk->wu.id])
        return 0;

    if (em->xyz[1].disp.pos)
        return 0;

    if (em->routine_no[1] != 4)
        return 0;

    Last_Attack_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];

    if (!(em->kind_of_waza & 0x20) && !(em->kind_of_waza & 0x30) && !(em->kind_of_waza & 0x28) &&
        !(em->kind_of_waza & 0x38) && !(em->kind_of_waza & 8)) {
        xx = em->kind_of_waza & 6;

        if (xx == 0)
            return 0;

        if (xx == 2)
            return 0;
    }

    VS_Tech[wk->wu.id] = VS_Technique;

    return PASSIVE_X = 1;
}

s32 Check_F_Cross_Chop(PLW *wk, WORK *em, s16 VS_Technique) {
    if (Last_Attack_Counter[wk->wu.id] == Attack_Counter[wk->wu.id])
        return 0;

    if ((em->kind_of_waza) != 4)
        return 0;

    if ((em->pat_status != 0x16) && (em->pat_status != 0x14) && (em->pat_status != 0x1A) && (em->pat_status != 0x1C))
        return 0;

    VS_Tech[wk->wu.id] = VS_Technique;
    Counter_Attack[wk->wu.id] = 1;

    return PASSIVE_X = 1;
}

s32 Check_PL_Unit_AS(PLW *wk) {
    return Passive_AS_tbl[((PLW *)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3d, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, -1, -1))
        return 1;

    return 0;
}

s32 VS_ALEX_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 0x18, 0x17, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x18, 0x16, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x38, 0x25, -1, -1))
        return 1;

    if (Check_Rolling(wk, em))
        return 1;

    return 0;
}

s32 VS_RYU_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 4, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 5, 1, -1))
        return 1;

    return 0;
}

s32 VS_YUN_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x1D, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0x24, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x18, 0x4A, -1, -1))
        return 1;

    return 0;
}

s32 VS_DUDLEY_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xD, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0xB, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xC, -1, 0))
        return 1;

    return 0;
}

s32 VS_NECRO_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xE, 8, 0x3D, -1, -1))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 5, 0x7FFF))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 4, 0x7FFF))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x18, 0x3A, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x3D, 1, -1))
        return 1;

    return 0;
}

s32 VS_IBUKI_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x1C, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0x19, -1, -1))
        return 1;

    return 0;
}

s32 VS_ELENA_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x11, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0xE, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xF, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 2, 0x30, 0x10, -1, -1))
        return 1;

    return 0;
}

s32 VS_ORO_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x27, -1, 0))
        return 1;

    return 0;
}

s32 VS_KEN_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 8, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 6, -1, -1))
        return 1;

    return 0;
}

s32 VS_SEAN_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 8, -1, -1))
        return 1;

    return 0;
}

s32 VS_URIEN_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x41, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, -1, -1))
        return 1;

    return 0;
}

s32 VS_GOUKI_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0x45, -1, -1))
        return 1;

    return 0;
}

s32 VS_CHUN_LI_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_MAKOTO_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xE, 0x18, 0x5F, -1, -1))
        return 1;

    return 0;
}

s32 VS_Q_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x58, 1, -1))
        return 1;

    return 0;
}

s32 VS_NO12_AS(PLW *wk) {
    return 0;
}

s32 VS_REMY_AS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x65, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    return 0;
}

s32 Check_PL_Unit_A(PLW *wk) {
    return Passive_A_tbl[((PLW *)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x3F, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    return 0;
}

s32 VS_ALEX_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 25, 24, 22, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 24, 24, 115, 1, 0))
        return 1;

    if (Check_F_Cross_Chop(wk, em, 15))
        return 1;

    if (Check_Special_Technique(wk, em, 24, 8, 73, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 15, 8, 30, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 15, 40, 72, 1, -1))
        return 1;

    return 0;
}

s32 VS_RYU_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x30, 3, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 5, 1, -1))
        return 1;

    return 0;
}

s32 VS_YUN_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x14, 8, 0x34, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x4A, 1, -1))
        return 1;

    return 0;
}

s32 VS_DUDLEY_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x12, 8, 0x4B, 1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xC, -1, -1))
        return 1;

    return 0;
}

s32 VS_NECRO_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x26, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x28, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x11, 0x18, 0x18, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 0x29, -1, -1))
        return 1;

    return 0;
}

s32 VS_HUGO_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x13, 0x18, 0x3A, 1, -1))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 5, 0x7FFF))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 4, 0x7FFF))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x18, 0x3E, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x38, 0x37, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x3D, 1, -1))
        return 1;

    return 0;
}

s32 VS_IBUKI_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x1A, 1, -1))
        return 1;

    return 0;
}

s32 VS_ELENA_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x12, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 2, 0x30, 0x10, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x13, -1, -1))
        return 1;

    return 0;
}

s32 VS_ORO_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x2C, 1, -1))
        return 1;

    return 0;
}

s32 VS_KEN_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    return 0;
}

s32 VS_SEAN_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x15, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x20, 1, -1))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0, 5, 0x7FFF))
        return 1;

    if (Check_Rolling(wk, em))
        return 1;

    return 0;
}

s32 VS_URIEN_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 8, 8, 0x41, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x3F, 1, -1))
        return 1;

    return 0;
}

s32 VS_GOUKI_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xD, 0x40, 0x2F, 1, -1))
        return 1;

    return 0;
}

s32 VS_CHUN_LI_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0x4E, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x72, 1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x15, 8, 0x4D, 1, -1))
        return 1;

    return 0;
}

s32 VS_MAKOTO_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x5F, 1, -1))
        return 1;

    return 0;
}

s32 VS_Q_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x58, 1, -1))
        return 1;

    return 0;
}

s32 VS_NO12_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x11, 8, 0x69, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x16, 8, 0x6B, 1, -1))
        return 1;

    return 0;
}

s32 VS_REMY_A(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    return 0;
}

s32 Check_PL_Unit_BS(PLW *wk) {
    return Passive_BS_tbl[((PLW *)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, -1, -1))
        return 1;

    return 0;
}

s32 VS_ALEX_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 0x18, 0x17, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x18, 0x16, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x38, 0x25, -1, -1))
        return 1;

    if (Check_Rolling(wk, em))
        return 1;

    return 0;
}

s32 VS_RYU_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x30, 3, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 5, 1, -1))
        return 1;

    return 0;
}

s32 VS_YUN_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x1D, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0x24, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x18, 0x4A, -1, -1))
        return 1;

    return 0;
}

s32 VS_DUDLEY_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xD, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0xB, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xC, -1, -1))
        return 1;

    return 0;
}

s32 VS_NECRO_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 5, 0x7FFF))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 4, 0x7FFF))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x18, 0x3A, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x3D, 1, -1))
        return 1;

    return 0;
}

s32 VS_IBUKI_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x1C, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0x19, -1, -1))
        return 1;

    return 0;
}

s32 VS_ELENA_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x11, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0xE, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xF, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 2, 0x30, 0x10, -1, -1))
        return 1;

    return 0;
}

s32 VS_ORO_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x27, -1, 0))
        return 1;

    return 0;
}

s32 VS_KEN_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 8, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 6, -1, -1))
        return 1;

    return 0;
}

s32 VS_SEAN_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 8, -1, -1))
        return 1;

    return 0;
}

s32 VS_URIEN_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x41, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, -1, -1))
        return 1;

    return 0;
}

s32 VS_GOUKI_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0x45, -1, -1))
        return 1;

    return 0;
}

s32 VS_CHUN_LI_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0x4E, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x4C, -1, 0))
        return 1;

    return 0;
}

s32 VS_MAKOTO_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x5C, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x18, 0x5F, -1, -1))
        return 1;

    return 0;
}

s32 VS_Q_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x58, 1, -1))
        return 1;

    return 0;
}

s32 VS_NO12_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_REMY_BS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x65, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    return 0;
}

s32 Check_PL_Unit_B(PLW *wk) {
    return Passive_B_tbl[((PLW *)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x3F, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    return 0;
}

s32 VS_ALEX_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x16, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x73, 1, 0))
        return 1;

    if (Check_F_Cross_Chop(wk, em, 0xF))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x49, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x1E, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 0x28, 0x48, 1, -1))
        return 1;

    return 0;
}

s32 VS_RYU_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 5, 1, -1))
        return 1;

    return 0;
}

s32 VS_YUN_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x1F, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x14, 8, 0x34, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x4A, 1, -1))
        return 1;

    return 0;
}

s32 VS_DUDLEY_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x12, 8, 0x4B, 1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xC, -1, -1))
        return 1;

    return 0;
}

s32 VS_NECRO_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x26, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x28, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x11, 0x18, 0x18, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 0x29, -1, -1))
        return 1;

    return 0;
}

s32 VS_HUGO_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x18, 0x3A, 1, -1))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 5, 0x7FFF))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 4, 0x7FFF))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x18, 0x3E, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x38, 0x37, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x3D, 1, -1))
        return 1;

    return 0;
}

s32 VS_IBUKI_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x1A, 1, -1))
        return 1;

    return 0;
}

s32 VS_ELENA_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x12, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x13, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 2, 0x30, 0x10, -1, -1))
        return 1;

    return 0;
}

s32 VS_ORO_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x2C, 1, -1))
        return 1;

    return 0;
}

s32 VS_KEN_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, -1))
        return 1;

    return 0;
}

s32 VS_SEAN_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x20, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x15, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x14, 1, -1))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0, 5, 0x7FFF))
        return 1;

    if (Check_Rolling(wk, em))
        return 1;

    return 0;
}

s32 VS_URIEN_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 8, 8, 0x41, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x3F, 1, -1))
        return 1;

    return 0;
}

s32 VS_GOUKI_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 5, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xD, 0x40, 0x2F, 1, -1))
        return 1;

    return 0;
}

s32 VS_CHUN_LI_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0x4E, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x4C, 1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x72, 1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x15, 8, 0x4D, 1, -1))
        return 1;

    return 0;
}

s32 VS_MAKOTO_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x5C, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x5F, 1, -1))
        return 1;

    return 0;
}

s32 VS_Q_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x54, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x15, 8, 0x57, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x58, 1, -1))
        return 1;

    return 0;
}

s32 VS_NO12_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x16, 8, 0x6B, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x11, 8, 0x69, 1, -1))
        return 1;

    return 0;
}

s32 VS_REMY_B(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    return 0;
}

s32 Check_PL_Unit_CS(PLW *wk) {
    return Passive_CS_tbl[((PLW *)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x41, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, -1, -1))
        return 1;

    return 0;
}

s32 VS_ALEX_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 0x18, 0x17, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x18, 0x16, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x38, 0x25, -1, -1))
        return 1;

    return 0;
}

s32 VS_RYU_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x30, 3, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 5, 1, -1))
        return 1;

    return 0;
}

s32 VS_YUN_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x1D, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0x24, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x18, 0x4A, -1, -1))
        return 1;

    return 0;
}

s32 VS_DUDLEY_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xD, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0xB, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xC, -1, -1))
        return 1;

    return 0;
}

s32 VS_NECRO_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 5, 0x7FFF))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 4, 0x7FFF))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x18, 0x3A, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x3D, 1, -1))
        return 1;

    return 0;
}

s32 VS_IBUKI_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0x19, -1, -1))
        return 1;

    return 0;
}

s32 VS_ELENA_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x11, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0xE, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xF, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 2, 0x30, 0x10, -1, -1))
        return 1;

    return 0;
}

s32 VS_ORO_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x27, -1, 0))
        return 1;

    return 0;
}

s32 VS_KEN_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 8, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 6, -1, -1))
        return 1;

    return 0;
}

s32 VS_SEAN_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 8, -1, -1))
        return 1;

    return 0;
}

s32 VS_URIEN_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x41, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, -1, -1))
        return 1;

    return 0;
}

s32 VS_GOUKI_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 1, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x17, 0x20, 0x45, -1, -1))
        return 1;

    return 0;
}

s32 VS_CHUN_LI_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0x4E, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x4C, -1, -1))
        return 1;

    return 0;
}

s32 VS_MAKOTO_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x5C, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x18, 0x5F, -1, -1))
        return 1;

    return 0;
}

s32 VS_Q_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_NO12_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_REMY_CS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x17, 8, 0x65, -1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    return 0;
}

s32 Check_PL_Unit_C(PLW *wk) {
    return Passive_C_tbl[((PLW *)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x3F, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    return 0;
}

s32 VS_ALEX_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x73, 1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x1E, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x49, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 0x28, 0x48, 1, -1))
        return 1;

    if (Check_F_Cross_Chop(wk, em, 0xF))
        return 1;

    return 0;
}

s32 VS_RYU_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 5, 1, -1))
        return 1;

    return 0;
}

s32 VS_YUN_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x1F, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x14, 8, 0x34, 1, -1))
        return 1;

    return 0;
}

s32 VS_DUDLEY_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x12, 8, 0x4B, 1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0xE, 0x20, 0xC, -1, -1))
        return 1;

    return 0;
}

s32 VS_NECRO_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x26, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x28, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x11, 0x18, 0x18, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 0x29, -1, -1))
        return 1;

    return 0;
}

s32 VS_HUGO_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x3D, -1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x18, 0x3A, 1, -1))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 5, 0x7FFF))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0x20, 4, 0x7FFF))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x18, 0x3E, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x13, 0x38, 0x37, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 0x18, 0x3D, 1, -1))
        return 1;

    return 0;
}

s32 VS_IBUKI_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 0x18, 0x1A, 1, -1))
        return 1;

    return 0;
}

s32 VS_ELENA_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x12, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x13, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 2, 0x30, 0x10, -1, -1))
        return 1;

    return 0;
}

s32 VS_ORO_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x2C, 1, -1))
        return 1;

    return 0;
}

s32 VS_KEN_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, -1))
        return 1;

    return 0;
}

s32 VS_SEAN_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x20, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x15, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x14, 1, -1))
        return 1;

    if (Check_Limited_Attack(wk, em, 0x18, 0, 5, 0x7FFF))
        return 1;

    return 0;
}

s32 VS_URIEN_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 8, 8, 0x41, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x40, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x3F, 1, -1))
        return 1;

    return 0;
}

s32 VS_GOUKI_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x18, 8, 2, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x10, 0x20, 4, 1, -1))
        return 1;

    return 0;
}

s32 VS_CHUN_LI_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x4C, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x72, 1, 0))
        return 1;

    if (Check_Special_Technique(wk, em, 0x15, 8, 0x4D, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0x4E, 1, -1))
        return 1;

    return 0;
}

s32 VS_MAKOTO_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x5C, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x19, 0x18, 0x5F, 1, -1))
        return 1;

    return 0;
}

s32 VS_Q_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x18, 8, 0x54, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x15, 8, 0x57, 1, -1))
        return 1;

    return 0;
}

s32 VS_NO12_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0x16, 8, 0x6B, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0x11, 8, 0x69, 1, -1))
        return 1;

    return 0;
}

s32 VS_REMY_C(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 8, 0, 1, -1))
        return 1;

    return 0;
}

s32 Check_PL_Unit_DS(PLW *wk) {
    return Passive_DS_tbl[((PLW *)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_ALEX_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_RYU_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 5, 1, -1))
        return 1;

    return 0;
}

s32 VS_YUN_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_DUDLEY_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_NECRO_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_IBUKI_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_ELENA_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 2, 0x30, 0x10, -1, -1))
        return 1;

    return 0;
}

s32 VS_ORO_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_KEN_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_SEAN_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_URIEN_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_GOUKI_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_CHUN_LI_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_MAKOTO_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_Q_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_NO12_DS(PLW *wk) {
    PLW *em = (PLW *)wk->wu.target_adrs;

    if (Check_VS_Jump(wk, em, 0x20)) {
        VS_Tech[wk->wu.id] = 0xF;
        return 1;
    }

    return 0;
}

s32 VS_REMY_DS(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 Check_PL_Unit_D(PLW *wk) {
    return Passive_D_tbl[((PLW *)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_ALEX_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_RYU_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xB, 0x20, 5, 1, -1))
        return 1;

    return 0;
}

s32 VS_YUN_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_DUDLEY_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_NECRO_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_IBUKI_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_ELENA_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 2, 0x30, 0x10, -1, -1))
        return 1;

    return 0;
}

s32 VS_ORO_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_KEN_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_SEAN_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_URIEN_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 0xC, 8, 0x3F, 1, 0xC))
        return 1;

    return 0;
}

s32 VS_GOUKI_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_CHUN_LI_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_MAKOTO_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_Q_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

s32 VS_NO12_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 0x69, 1, -1))
        return 1;

    if (Check_Special_Technique(wk, em, 0xF, 8, 0x6B, 1, -1))
        return 1;

    return 0;
}

s32 VS_REMY_D(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    return 0;
}

void (*const Passive_jmp_tbl[21])() = { GILL_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs, HUGO_vs,
                                        KEN_vs,  KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs,
                                        KEN_vs,  KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs };

s32 (*const Passive_AS_tbl[20])(PLW *wk) = { VS_GILL_AS,    VS_ALEX_AS,   VS_RYU_AS,   VS_YUN_AS,   VS_DUDLEY_AS,
                                             VS_NECRO_AS,   VS_HUGO_AS,   VS_IBUKI_AS, VS_ELENA_AS, VS_ORO_AS,
                                             VS_YUN_AS,     VS_KEN_AS,    VS_SEAN_AS,  VS_URIEN_AS, VS_GOUKI_AS,
                                             VS_CHUN_LI_AS, VS_MAKOTO_AS, VS_Q_AS,     VS_NO12_AS,  VS_REMY_AS };

s32 (*const Passive_A_tbl[20])(PLW *wk) = { VS_GILL_A,    VS_ALEX_A,   VS_RYU_A,   VS_YUN_A,   VS_DUDLEY_A,
                                            VS_NECRO_A,   VS_HUGO_A,   VS_IBUKI_A, VS_ELENA_A, VS_ORO_A,
                                            VS_YUN_A,     VS_KEN_A,    VS_SEAN_A,  VS_URIEN_A, VS_GOUKI_A,
                                            VS_CHUN_LI_A, VS_MAKOTO_A, VS_Q_A,     VS_NO12_A,  VS_REMY_A };

s32 (*const Passive_BS_tbl[20])(PLW *wk) = { VS_GILL_BS,    VS_ALEX_BS,   VS_RYU_BS,   VS_YUN_BS,   VS_DUDLEY_BS,
                                             VS_NECRO_BS,   VS_HUGO_BS,   VS_IBUKI_BS, VS_ELENA_BS, VS_ORO_BS,
                                             VS_YUN_BS,     VS_KEN_BS,    VS_SEAN_BS,  VS_URIEN_BS, VS_GOUKI_BS,
                                             VS_CHUN_LI_BS, VS_MAKOTO_BS, VS_Q_BS,     VS_NO12_BS,  VS_REMY_BS };

s32 (*const Passive_B_tbl[20])(PLW *wk) = { VS_GILL_B,    VS_ALEX_B,   VS_RYU_B,   VS_YUN_B,   VS_DUDLEY_B,
                                            VS_NECRO_B,   VS_HUGO_B,   VS_IBUKI_B, VS_ELENA_B, VS_ORO_B,
                                            VS_YUN_B,     VS_KEN_B,    VS_SEAN_B,  VS_URIEN_B, VS_GOUKI_B,
                                            VS_CHUN_LI_B, VS_MAKOTO_B, VS_Q_B,     VS_NO12_B,  VS_REMY_B };

s32 (*const Passive_CS_tbl[20])(PLW *wk) = { VS_GILL_CS,    VS_ALEX_CS,   VS_RYU_CS,   VS_YUN_CS,   VS_DUDLEY_CS,
                                             VS_NECRO_CS,   VS_HUGO_CS,   VS_IBUKI_CS, VS_ELENA_CS, VS_ORO_CS,
                                             VS_YUN_CS,     VS_KEN_CS,    VS_SEAN_CS,  VS_URIEN_CS, VS_GOUKI_CS,
                                             VS_CHUN_LI_CS, VS_MAKOTO_CS, VS_Q_CS,     VS_NO12_CS,  VS_REMY_CS };

s32 (*const Passive_C_tbl[20])(PLW *wk) = { VS_GILL_C,    VS_ALEX_C,   VS_RYU_C,   VS_YUN_C,   VS_DUDLEY_C,
                                            VS_NECRO_C,   VS_HUGO_C,   VS_IBUKI_C, VS_ELENA_C, VS_ORO_C,
                                            VS_YUN_C,     VS_KEN_C,    VS_SEAN_C,  VS_URIEN_C, VS_GOUKI_C,
                                            VS_CHUN_LI_C, VS_MAKOTO_C, VS_Q_C,     VS_NO12_C,  VS_REMY_C };

s32 (*const Passive_DS_tbl[20])(PLW *wk) = { VS_GILL_DS,    VS_ALEX_DS,   VS_RYU_DS,   VS_YUN_DS,   VS_DUDLEY_DS,
                                             VS_NECRO_DS,   VS_HUGO_DS,   VS_IBUKI_DS, VS_ELENA_DS, VS_ORO_DS,
                                             VS_YUN_DS,     VS_KEN_DS,    VS_SEAN_DS,  VS_URIEN_DS, VS_GOUKI_DS,
                                             VS_CHUN_LI_DS, VS_MAKOTO_DS, VS_Q_DS,     VS_NO12_DS,  VS_REMY_DS };

s32 (*const Passive_D_tbl[20])(PLW *wk) = { VS_GILL_D,    VS_ALEX_D,   VS_RYU_D,   VS_YUN_D,   VS_DUDLEY_D,
                                            VS_NECRO_D,   VS_HUGO_D,   VS_IBUKI_D, VS_ELENA_D, VS_ORO_D,
                                            VS_YUN_D,     VS_KEN_D,    VS_SEAN_D,  VS_URIEN_D, VS_GOUKI_D,
                                            VS_CHUN_LI_D, VS_MAKOTO_D, VS_Q_D,     VS_NO12_D,  VS_REMY_D };
