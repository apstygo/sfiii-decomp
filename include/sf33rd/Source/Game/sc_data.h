#ifndef SC_DATA_H
#define SC_DATA_H

#include "structs.h"
#include "types.h"

extern const u8 vmark_tbl[8];
extern const s16 Fade_Pos_tbl[8];
extern const s16 fade_data_tbl[][3];

typedef const u8 *UV_POS_TBL;
extern const UV_POS_TBL sc_ram_vram_tbl[][2];

extern TrainingData2 tr_data[];

#endif
