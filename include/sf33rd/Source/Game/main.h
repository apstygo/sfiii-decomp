#ifndef MAIN_H
#define MAIN_H

#include "structs.h"
#include "types.h"

#define INIT_TASK_NUM 0
#define ENTRY_TASK_NUM 1
#define RESET_TASK_NUM 2
#define MENU_TASK_NUM 3
#define PAUSE_TASK_NUM 4
#define GAME_TASK_NUM 5
#define SAVER_TASK_NUM 6
#define DEBUG_TASK_NUM 9

extern MPP mpp_w;             // size: 0x4C, address: 0x57A9F0
extern s32 system_init_level; // size: 0x4, address: 0x57AA3C

void AcrMain();
void cpInitTask();
void cpReadyTask(u16 num, void* func_adrs);
void cpExitTask(u16 num);
s32 mppGetFavoritePlayerNumber();

#endif
