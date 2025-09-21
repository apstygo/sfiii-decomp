#include "sf33rd/Source/Game/EFFA7.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFF02.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/PulPul.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/Se_Data.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/char_table.h"
#include "sf33rd/Source/Game/workuser.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFA7", effect_A7_move);

s32 effect_A7_init(PLW *wk) {
    WORK_Other *ewk;
    PLW *twk;
    s16 ix;

    if (wk->wu.work_id != 1) {
        return -1;
    }

    if ((ix = pull_effect_work(2)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    twk = (PLW *)wk->wu.target_adrs;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 107;
    ewk->wu.work_id = 64;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.kohm = wk->wu.hm_dm_side;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_mr_flag = 0;
    ewk->wu.xyz[0].disp.pos = ewk->wu.position_x = wk->wu.xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = ewk->wu.position_y = wk->wu.xyz[1].disp.pos;
    ewk->wu.xyz[2].disp.pos = 26;
    ewk->my_master = (u32 *)wk->wu.target_adrs;
    ewk->master_id = twk->wu.id;
    ewk->master_work_id = twk->wu.work_id;
    ewk->wu.target_adrs = (u32 *)wk;
    ewk->wu.my_col_code = twk->wu.my_col_code + 1;
    ewk->master_player = ewk->wu.dir_timer = twk->player_number;
    ewk->wu.blink_timing = ewk->master_id;
    return 0;
}
