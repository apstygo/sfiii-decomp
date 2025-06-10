#ifndef PLS03_H
#define PLS03_H

#include "structs.h"
#include "types.h"

s16 hikusugi_check(WORK *wk);
u16 get_nearing_range(s16 pnum, s16 kos);
s16 get_meoshi_shot(s16 data);
s16 get_meoshi_lever(s16 data);
s16 renbanshot_conpaneshot(s16 *dadr, s16 pow);
s16 datacmd_conpanecmd(s16 dat);

#endif
