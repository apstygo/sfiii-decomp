#include "sf33rd/Source/Game/CHARID.h"
#include "common.h"

// bss
CharInitData char_init_data[23];

// sbss
UNK_Data *parabora_own_table[20];

const CharInitData2 char_init_data2[23] = {
    { 0x0000, 0x0000, 0x0000, 0x0000 }, { 0x4200, 0x2000, 0x0026, 0x0002 }, { 0x4200, 0x2000, 0x0032, 0x0002 },
    { 0x4200, 0x2000, 0x0034, 0x0002 }, { 0x4200, 0x2000, 0x002a, 0x0002 }, { 0x4200, 0x2000, 0x0030, 0x0002 },
    { 0x4200, 0x2000, 0x0036, 0x0002 }, { 0x4200, 0x2000, 0x0038, 0x0002 }, { 0x4200, 0x2000, 0x0028, 0x0002 },
    { 0x4200, 0x2000, 0x002e, 0x0002 }, { 0x4200, 0x2000, 0x002c, 0x0002 }, { 0x4200, 0x2000, 0x001c, 0x0002 },
    { 0x4200, 0x2000, 0x0026, 0x0002 }, { 0x4200, 0x2000, 0x0030, 0x0002 }, { 0x4200, 0x2000, 0x0030, 0x0002 },
    { 0x4200, 0x2000, 0x0036, 0x0002 }, { 0x4200, 0x2000, 0x0030, 0x0002 }, { 0x4200, 0x2000, 0x001c, 0x0002 },
    { 0x4200, 0x2000, 0x0032, 0x0002 }, { 0x4200, 0x2000, 0x0032, 0x0002 }, { 0x4200, 0x2000, 0x0036, 0x0002 },
    { 0x4200, 0x2000, 0x0038, 0x0002 }, { 0x4200, 0x2000, 0x0028, 0x0002 }
};

const CharInitData char_init_data_ex[2] = {
    { (u32 *)0x00491560,    (u32 *)0x00000000,   (u32 *)0x00000000,   (u32 *)0x00000000,   (u32 *)0x00000000,
      (u32 *)0x00000000,    (u32 *)0x00000000,   (u32 *)0x00000000,   (u32 *)0x00000000,   (u32 *)0x00000000,
      (s16 *)0x0049b5c8,    (s16 *)0x0049b5ec,   (u32 *)0x00000000,   (UNK_8 *)0x00000000, (UNK_9 *)0x00000000,
      (UNK_10 *)0x00000000, (UNK_0 *)0x004a1f48, (UNK_1 *)0x004a2cc8, (UNK_2 *)0x004a3a48, (UNK_3 *)0x004a5450,
      (UNK_4 *)0x004a5458,  (UNK_5 *)0x004a3c50, (UNK_6 *)0x004a3a68, (UNK_7 *)0x0049af28, (UNK_Data *)0x00000000 },
    { (u32 *)0x0049bd28,    (u32 *)0x00000000,   (u32 *)0x00000000,   (u32 *)0x00000000,   (u32 *)0x00000000,
      (u32 *)0x00000000,    (u32 *)0x00000000,   (u32 *)0x00000000,   (u32 *)0x00000000,   (u32 *)0x00000000,
      (s16 *)0x0049b5c8,    (s16 *)0x0049b5ec,   (u32 *)0x00000000,   (UNK_8 *)0x00000000, (UNK_9 *)0x00000000,
      (UNK_10 *)0x00000000, (UNK_0 *)0x004a1f48, (UNK_1 *)0x004a2cc8, (UNK_2 *)0x004a3a48, (UNK_3 *)0x004a5450,
      (UNK_4 *)0x004a5458,  (UNK_5 *)0x004a3c50, (UNK_6 *)0x004a3a68, (UNK_7 *)0x0049af28, (UNK_Data *)0x00000000 }
};

void set_char_base_data(WORK *wk) {
    CharInitData *cdat;
    const CharInitData2 *cdat2;

    cdat = &char_init_data[wk->charset_id];
    cdat2 = &char_init_data2[wk->charset_id];
    wk->char_table[0] = cdat->nmca;
    wk->char_table[1] = cdat->dmca;
    wk->char_table[6] = cdat->btca;
    wk->char_table[2] = cdat->caca;
    wk->char_table[3] = cdat->cuca;
    wk->char_table[4] = cdat->atca;
    wk->char_table[5] = cdat->saca;
    wk->char_table[7] = cdat->exca;
    wk->char_table[8] = cdat->cbca;
    wk->char_table[9] = cdat->yuca;
    wk->step_xy_table = cdat->stxy;
    wk->move_xy_table = cdat->mvxy;
    wk->se_random_table = cdat->sernd;
    wk->overlap_char_tbl = cdat->ovct;
    wk->olc_ix_table = cdat->ovix;
    wk->rival_catch_tbl = cdat->rict;
    wk->hit_ix_table = cdat->hiit;
    wk->body_adrs = cdat->boda;
    wk->hand_adrs = cdat->hana;
    wk->catch_adrs = cdat->cata;
    wk->caught_adrs = cdat->caua;
    wk->attack_adrs = cdat->atta;
    wk->hosei_adrs = cdat->hosa;
    wk->att_ix_table = cdat->atit;
    wk->my_col_mode = cdat2->my_cm;
    wk->my_col_code = cdat2->my_cc;
    wk->my_priority = cdat2->my_pr;
    wk->my_family = cdat2->my_fm;
    wk->position_z = wk->my_priority;
}

void copy_char_base_data() {
    char_init_data[11] = char_init_data_ex[0];
    char_init_data[17] = char_init_data_ex[1];
}
