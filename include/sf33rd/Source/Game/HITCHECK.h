#ifndef HITCHECK_H
#define HITCHECK_H

#include "types.h"

extern s8 ca_check_flag; // size: 0x1, address: 0x5790F4

void clear_hit_queue();
void hit_check_main_process();

#endif
