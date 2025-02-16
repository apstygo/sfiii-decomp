#ifndef PULPUL_H
#define PULPUL_H

#include "types.h"

void init_pulpul_work();
void pulpul_stop();
void pulpul_stop2(s32 ix);
void pp_vib_on(s32 id);
void pp_operator_check_flag(u8 fl);
void move_pulpul_work();

#endif
