#ifndef SYSDIR_H
#define SYSDIR_H

#include "types.h"

extern const s16 sa_gauge_omake[4]; // size: 0x8, address: 0x5549A0

extern s16 omop_cockpit; // size: 0x2, address: 0x5799D8
extern s16 omop_sa_gauge_ix[2]; // size: 0x4, address: 0x579A10

void init_omop();
u32 sag_ikinari_max();

#endif
