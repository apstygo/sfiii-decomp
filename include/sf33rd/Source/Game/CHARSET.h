#ifndef CHARSET_H
#define CHARSET_H

#include "structs.h"

void setupCharTableData(WORK *wk, s32 clr, s32 info);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void char_move(WORK *wk);

#endif
