#ifndef COM_SUB_H
#define COM_SUB_H

#include "structs.h"
#include "types.h"

void Normal_Attack(PLW *wk, s16 Reaction, u16 Lever_Data);
void End_Pattern(PLW *wk);
void Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);

#endif
