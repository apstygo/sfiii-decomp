#ifndef COLOR3RD_H
#define COLOR3RD_H

#include "structs.h"
#include "types.h"

void q_ldreq_color_data(REQ *curr);                // Range: 0x19D800 -> 0x19DD7C
void set_hitmark_color();                          // Range: 0x19DE70 -> 0x19E010
void init_color_trans_req();                       // Range: 0x19F600 -> 0x19F694
void palCopyGhostDC(s32 ofs, s32 cnt, void *data); // Range: 0x19F700 -> 0x19F7C0
void palCreateGhost();                             // Range: 0x19F8D0 -> 0x19FB50
void palUpdateGhostDC();                           // Range: 0x19FB70 -> 0x19FC6C

#endif
