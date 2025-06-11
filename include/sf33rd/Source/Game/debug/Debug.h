#ifndef DEBUG_H
#define DEBUG_H

#include "structs.h"
#include "types.h"

extern s8 Debug_w[72];
extern s8 Debug_Index;
extern u8 Deley_Debug_No;
extern u8 Deley_Debug_Timer;
extern u8 Deley_Debug_No2;
extern u8 Deley_Debug_Timer2;
extern u8 Debug_Pause;
extern u8 sysFF;
extern u8 sysSLOW;
extern s8 Slow_Timer;
extern u8 check_screen_S;
extern u8 check_screen_L;
extern u8 check_time_S;
extern u8 check_time_L;
extern u32 Rec_Time[2];
extern u32 Record_Timer;
extern s16 time_check[4];
extern u8 time_check_ix;

void Debug_Task(struct _TASK *task_ptr);
void Check_Pos_BG();
s32 Check_Exit_Check();
void Check_Check_Screen();

#endif
