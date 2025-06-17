#ifndef COLOR3RD_H
#define COLOR3RD_H

#include "structs.h"
#include "types.h"

extern u16 ColorRAM[512][64];
extern Col3rd_W col3rd_w;

void q_ldreq_color_data(REQ *curr);
void set_hitmark_color();
void init_color_trans_req();
void palCopyGhostDC(s32 ofs, s32 cnt, void *data);
void palCreateGhost();
void palUpdateGhostDC();
Palette *palGetChunkGhostCP3();
Palette *palGetChunkGhostDC();
void load_any_color(u16 ix, u8 kokey);
void push_color_trans_req(s16 from_col, s16 to_col);

#endif
