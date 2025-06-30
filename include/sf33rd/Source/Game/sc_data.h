#ifndef SC_DATA_H
#define SC_DATA_H

#include "types.h"

extern const u8 vmark_tbl[8];
extern const s16 Fade_Pos_tbl[8];
extern const s16 fade_data_tbl[][3];
extern const s8 flash_timer_tbl[2];
extern const u8 flash_color_tbl[4];

typedef const u8 *UV_POS_TBL;
extern const UV_POS_TBL sc_ram_vram_tbl[][2];

#endif
