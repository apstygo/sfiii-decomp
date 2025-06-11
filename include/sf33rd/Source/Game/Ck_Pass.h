#ifndef CK_PASS_H
#define CK_PASS_H

#include "structs.h"
#include "types.h"

s32 Check_Blow_Off(PLW *wk, WORK *em, s16 VS_Technique);
s32 Check_Limited_Jump_Attack(PLW *wk, WORK *em, u8 PL_Status, s8 Status_00);
s32 Check_VS_Squat(PLW *wk, WORK *em, s16 VS_Technique, u8 Status_00, u8 Status_01);
s32 Check_Special_Technique(PLW *wk, WORK *em, s16 VS_Technique, u8 Kind_of_Tech, u8 SP_Tech_ID, s16 Option,
                            s16 Option2);
s32 Check_F_Cross_Chop(PLW *wk, WORK *em, s16 VS_Technique);
s32 Ck_Passive_Term(PLW *wk);
s32 Check_Lie(PLW *wk);
s32 Check_Thrown(PLW *wk, WORK *em);
s32 Check_Attack_Direction(PLW *wk, WORK *em);

#endif
