#include "sf33rd/Source/Game/EFFI8.h"
#include "common.h"
#include "sf33rd/Source/Game/CALDIR.h"
#include "sf33rd/Source/Game/CHARID.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/HITCHECK.h"
#include "sf33rd/Source/Game/PLS01.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/Se_Data.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/char_table.h"
#include "sf33rd/Source/Game/workuser.h"

const s16 effI8_hit_box[2][4] = { { -9, 17, -6, 12 }, { -4, 10, 114, 9 } };

const s16 bbbs_emtall[20] = { 84, 76, 68, 58, 76, 64, 92, 60, 56, 52, 58, 68, 68, 84, 68, 64, 58, 88, 58, 76 };

const u16 cbm_table[8][5] = { { 0x3FFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFF00 }, { 0x1FFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFF00 },
                              { 0x0FFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFE00 }, { 0x01FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFC00 },
                              { 0x0003, 0xFFFF, 0xFFFF, 0xFFFF, 0xF800 }, { 0x0001, 0xFFFF, 0xFFFF, 0xFFFF, 0xF000 },
                              { 0x0000, 0x000F, 0xFFFF, 0xFFFF, 0x8000 }, { 0x0000, 0x0000, 0x0FFF, 0xFFFE, 0x0000 } };

void effI8_main_process(WORK_Other *ewk);
void cal_speeds_to_me_effI8(WORK_Other *ewk, PLW *mwk);
void cal_speeds_to_em_effI8(WORK_Other *ewk, PLW *twk);
s32 check_ball_mizushibuki(s16 xx, s16 yy);
s32 effect_I8_init(PLW *wk, s16 top, const s16 *sptr);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", effect_I8_move);
#else
void effect_I8_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", effI8_main_process);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", cal_speeds_to_me_effI8);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", cal_speeds_to_em_effI8);

s32 check_ball_mizushibuki(s16 xx, s16 yy) {
    s16 ix;
    s16 iy;
    u16 ans;

    if (bg_w.stage == 10) {
        return 2;
    }

    if (Bonus_Game_Flag != 21) {
        return 0;
    }

    yy -= 6;

    if (xx >= 689 || xx <= 399) {
        return 0;
    }

    if ((yy >= -7) || (yy < -24)) {
        return 0;
    }

    if ((ix = (xx - 400) / 64) > 4) {
        ix = 4;
    }

    if ((iy = (yy + 24) / 2) > 7) {
        iy = 7;
    }

    ans = cbm_table[iy][ix];

    if ((ix = ((xx - 400) % 64) / 4) > 15) {
        ix = 15;
    }

    if (ans << ix & 0x8000) {
        return 1;
    }

    return 0;
}

s32 effect_I8_init(PLW *wk, s16 top, const s16 *sptr) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xBC;
    ewk->wu.work_id = 2;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.dm_vital = wk->wu.my_col_code;
    ewk->wu.my_mts = 0xE;
    ewk->wu.dir_timer = top;
    ewk->wu.dir_step = sptr[1];
    ewk->wu.dir_old = sptr[2];
    ewk->wu.next_x = sptr[3];
    ewk->my_master = (u32 *)wk;
    ewk->wu.target_adrs = (u32 *)wk->wu.target_adrs;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = 0x1C;
    return 0;
}

void setup_effI8(PLW *wk, const BBBSTable *dadr) {
#if defined(TARGET_PS2)
    s32 effect_I8_init(PLW * wk, s32 top, const s16 *sptr);
#endif

    s16 i;
    s16 ttime = 0;

    for (i = 0; i < dadr->kosuu; i++) {
        ttime += dadr->bbdat[i][0];
        effect_I8_init(wk, ttime, &dadr->bbdat[i][0]);
    }
}
