#ifndef HITCHECK_H
#define HITCHECK_H

#include "structs.h"
#include "types.h"

extern const u16 chain_normal_ground_table[];   // size: 0x10, address: 0x521DB0
extern const u16 chain_hidou_nm_ground_table[]; // size: 0x10, address: 0x521DC0
extern const u16 chain_normal_air_table[];      // size: 0x10, address: 0x521DD0
extern const u16 chain_hidou_nm_air_table[];    // size: 0x10, address: 0x521DE0
extern const u8 plpat_rno_filter[];             // size: 0x0, address: 0x521DF0

extern s8 ca_check_flag; // size: 0x1, address: 0x5790F4

void clear_hit_queue();
void hit_check_main_process();
s16 hit_check_subroutine(WORK *wk1, WORK *wk2, const s16 *hd1, s16 *hd2);

#endif
