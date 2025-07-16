#ifndef SYSDIR_H
#define SYSDIR_H

#include "structs.h"
#include "types.h"

extern const s16 sa_gauge_omake[4]; // size: 0x8, address: 0x5549A0

extern s16 omop_cockpit;        // size: 0x2, address: 0x5799D8
extern s16 omop_sa_gauge_ix[2]; // size: 0x4, address: 0x579A10
extern s16 omop_round_timer;
extern s16 omop_vt_bar_disp[2];
extern s16 omop_st_bar_disp[2];
extern s16 omop_b_block_ix[2];

extern const s16 blok_b_omake[4];

void init_omop();
u32 sag_ikinari_max();
void get_extra_option_parameter(_EXTRA_OPTION *omop_extra);
void get_system_direction_parameter(DirData *sysdir_data);

#endif
