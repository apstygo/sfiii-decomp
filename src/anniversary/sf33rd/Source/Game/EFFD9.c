#include "sf33rd/Source/Game/EFFD9.h"
#include "common.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/workuser.h"

const s16 coltbl_000_1P[10] = { 1, 8192, 2, 8193, 1, 8195, 2, 8193, 0, 0 };
const s16 coltbl_000_2P[10] = { 1, 8208, 2, 8209, 1, 8211, 2, 8209, 0, 0 };

const s16 coltbl_001_1P[6] = { 2, 8192, 2, 8194, 0, 0 };
const s16 coltbl_001_2P[6] = { 2, 8208, 2, 8210, 0, 0 };

const s16 coltbl_002_1P[4] = { 999, 8195, 0, 0 };
const s16 coltbl_002_2P[4] = { 999, 8211, 0, 0 };

const s16 coltbl_003_1P[6] = { 2, 8192, 2, 8193, 0, 0 };
const s16 coltbl_003_2P[6] = { 2, 8208, 2, 8209, 0, 0 };

const s16 coltbl_004_1P[6] = { 2, 8192, 2, 8196, 0, 0 };
const s16 coltbl_004_2P[6] = { 2, 8208, 2, 8212, 0, 0 };

const s16 coltbl_005_1P[6] = { 1, 8694, 2, 8192, 0, 0 };
const s16 coltbl_005_2P[6] = { 1, 8698, 2, 8208, 0, 0 };

const s16 coltbl_006_1P[6] = { 99, 8198, 99, 8198, 0, 0 };
const s16 coltbl_006_2P[6] = { 99, 8214, 99, 8214, 0, 0 };

const s16 coltbl_007_1P[10] = { 1, 8195, 2, 8192, 1, 8195, 2, 8192, 0, 0 };
const s16 coltbl_007_2P[10] = { 1, 8211, 2, 8208, 1, 8211, 2, 8208, 0, 0 };

const s16 coltbl_008_1P[8] = { 2, 8192, 2, 8193, 2, 8193, 0, 0 };
const s16 coltbl_008_2P[8] = { 2, 8208, 2, 8209, 2, 8209, 0, 0 };

const s16 coltbl_009_1P[4] = { 52, 8197, 0, 0 };
const s16 coltbl_009_2P[4] = { 52, 8213, 0, 0 };

const s16 coltbl_010_1P[4] = { 999, 8197, 0, 0 };
const s16 coltbl_010_2P[4] = { 999, 8213, 0, 0 };

const ColorTableIndex color_table_index[11] = {
    { 8, 0, coltbl_000_1P, coltbl_000_2P },   { 7, 24, coltbl_003_1P, coltbl_003_2P },
    { 7, 30, coltbl_001_1P, coltbl_001_2P },  { 5, 0, coltbl_002_1P, coltbl_002_2P },
    { 7, 18, coltbl_004_1P, coltbl_004_2P },  { 18, 24, coltbl_005_1P, coltbl_005_2P },
    { 17, 24, coltbl_006_1P, coltbl_006_2P }, { 2, 10, coltbl_007_1P, coltbl_007_2P },
    { 8, 0, coltbl_008_1P, coltbl_008_2P },   { 19, 52, coltbl_009_1P, coltbl_009_2P },
    { 17, 24, coltbl_010_1P, coltbl_010_2P }
};

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD9", effect_D9_move);

s32 effect_D9_init(PLW *wk, u8 data) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(6)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 139;
    ewk->wu.work_id = 16;
    ewk->wu.direction = data;
    ewk->wu.dir_old = wk->wu.dm_count_up;
    ewk->wu.dm_attribute = wk->wu.dm_attribute;
    ewk->wu.type = wk->wu.pat_status;
    ewk->wu.total_paring = wk->wu.kind_of_waza;
    ewk->my_master = (u32 *)wk;
    ewk->master_id = wk->wu.id;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_player = wk->player_number;
    return 0;
}
