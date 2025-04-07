#ifndef CHARSET_H
#define CHARSET_H

#include "structs.h"

void setupCharTableData(WORK *wk, s32 clr, s32 info);
void char_move(WORK *wk);
void check_cm_extended_code(WORK *wk);
void check_cgd_patdat(WORK *wk);
void set_jugde_area(WORK *wk);
void set_new_attnum(WORK *wk);

#ifndef CHARSET_IMPL
void set_char_move_init2(WORK *wk, s16 koc, s32 index, s32 ip, s16 scf);
#endif

#endif
