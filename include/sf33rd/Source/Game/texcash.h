#ifndef TEXCASH_H
#define TEXCASH_H

#include "structs.h"
#include "types.h"

extern TPU *tpu_free;           // size: 0x4, address: 0x579A8C
extern u8 *texcash_melt_buffer; // size: 0x4, address: 0x579A90

void init_texcash_1st();
void init_texcash_2nd(s32 ix);
void init_texcash_before_process();
void texture_cash_update();
void make_texcash_work(s16 ix);
void purge_texcash_work(s16 ix);
void Clear_texcash_work();
s16 get_my_trans_mode(s32 curr);

#endif
