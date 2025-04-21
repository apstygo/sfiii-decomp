#ifndef DEBUG_H
#define DEBUG_H

#include "structs.h"
#include "types.h"

extern u32 Record_Timer;  // size: 0x4, address: 0x57A810
extern u8 check_screen_L; // size: 0x1, address: 0x57A828
extern u8 check_screen_S; // size: 0x1, address: 0x57A82C
extern s8 Slow_Timer;     // size: 0x1, address: 0x57A830
extern u8 sysSLOW;        // size: 0x1, address: 0x57A834
extern u8 sysFF;          // size: 0x1, address: 0x57A838
extern s8 Debug_w[72];    // size: 0x48, address: 0x57A860

void Debug_Task(struct _TASK *task_ptr);
void Check_Pos_BG();
s32 Check_Exit_Check();
void Check_Check_Screen();

#endif
