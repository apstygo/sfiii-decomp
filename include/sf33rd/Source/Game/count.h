#ifndef COUNT_H
#define COUNT_H

#include "structs.h"
#include "types.h"

extern Round_Timer round_timer;

void count_cont_init(u8 type);
void count_cont_main();
void counter_control();
void counter_write(u8 atr);
void bcounter_write();
void counter_flash(s8 Flash_Num);
void bcount_cont_init();
void bcount_cont_main();
void bcounter_control();
s16 bcounter_down(u8 kind);

#endif
