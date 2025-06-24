#ifndef CHARSET_H
#define CHARSET_H

#include "structs.h"

void setupCharTableData(WORK *wk, s32 clr, s32 info);
void char_move(WORK *wk);
void check_cm_extended_code(WORK *wk);
void check_cgd_patdat(WORK *wk);
void set_jugde_area(WORK *wk);
void set_new_attnum(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void char_move_z(WORK *wk);

#endif
