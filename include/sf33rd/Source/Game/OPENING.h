#ifndef OPENING_H
#define OPENING_H

#include "types.h"

extern s16 title_tex_flag; // size: 0x2, address: 0x579464
extern s16 op_timer0;      // size: 0x2, address: 0x579468

void TITLE_Init();
s16 TITLE_Move(u16 type);
s16 opening_demo();

#endif // OPENING_H
