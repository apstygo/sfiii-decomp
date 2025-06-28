#include "sf33rd/Source/Game/eff05.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/bg_sub.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/texcash.h"

u32 *char_add[22] = { (u32 *)0x484FF0, (u32 *)0x488AD8, (u32 *)0x487060, (u32 *)0x4865B0, (u32 *)0x47E548,
                      (u32 *)0x488570, (u32 *)0x486258, (u32 *)0x486AE8, (u32 *)0x488850, (u32 *)0x47A740,
                      (u32 *)0x4865B0, (u32 *)0x488AD8, (u32 *)0x47A740, (u32 *)0x488550, (u32 *)0x487908,
                      (u32 *)0x47AB58, (u32 *)0x487B40, (u32 *)0x488AD8, (u32 *)0x488570, (u32 *)0x485360,
                      (u32 *)0x47A0E0, (u32 *)0x47A0E0 };

const s16 *scr_obj_data[22] = { stg_dum_data_tbl, stg0100_data_tbl, stg_dum_data_tbl, stg_dum_data_tbl,
                                stg_dum_data_tbl, stg0500_data_tbl, stg0600_data_tbl, stg0700_data_tbl,
                                stg0800_data_tbl, stg0900_data_tbl, stg0A00_data_tbl, stg0100_data_tbl,
                                stg0c00_data_tbl, stg0d00_data_tbl, stg0e00_data_tbl, stg1000_data_tbl,
                                stg1100_data_tbl, stg_dum_data_tbl, stg1300_data_tbl, stg1400_data_tbl,
                                stg1500_data_tbl, stg1600_data_tbl };

void effect_05_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    if (obr_no_disp_check() == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            break;

        case 1:
            if (compel_dead_check(ewk) != 0) {
                ewk->wu.routine_no[0]++;
                return;
            }
            disp_pos_trans_entry_s(ewk);
            break;

        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}

s32 effect_05_init() {
#if defined(TARGET_PS2)
    s16 get_my_trans_mode(s32 curr);
#endif
    WORK_Other *ewk;
    s16 ix;
    s16 lp_cnt;
    s16 i;
    const s16 *data_ptr;

    lp_cnt = scr_obj_num[bg_w.bg_index];
    if (lp_cnt == 0) {
        return 0;
    }

    data_ptr = scr_obj_data[bg_w.bg_index];

    i = 0;
    while (i < lp_cnt) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)((u8 *)&frw + ix * 0x700);

        ewk->wu.be_flag = 1;
        ewk->wu.id = 5;
        ewk->wu.work_id = 0x10;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        ewk->wu.type = i;
        ewk->wu.dead_f = *data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;

        suzi_offset_set(ewk);

        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

        i++;
    }

    return 0;
}

const s16 scr_obj_num[22] = { 0, 2, 0, 0, 0, 2, 1, 0, 3, 1, 0, 1, 1, 1, 1, 2, 2, 0, 2, 4, 1, 4 };

const s16 stg_dum_data_tbl[1] = { 0x0000 };

const s16 stg0100_data_tbl[16] = { 0x0000, 0x0001, 0x012C, 0x0238, 0x0030, 0x0056, 0x0000, 0x0000,
                                   0x0000, 0x0002, 0x212C, 0x0210, 0x002F, 0x0044, 0x0013, 0x0000 };

const s16 stg0A00_data_tbl[8] = { 0x0000, 0x0003, 0x012C, 0x0200, 0x0010, 0x0058, 0x000A, 0x0000 };

const s16 stg0500_data_tbl[32] = { 0x0000, 0x0003, 0x012C, 0x0200, 0x0000, 0x0058, 0x0009, 0x0000,
                                   0x0000, 0x0003, 0x212C, 0x0230, 0x0000, 0x0058, 0x000A, 0x0000,
                                   0x0000, 0x0002, 0x012C, 0x0200, 0x0000, 0x0054, 0x0003, 0x0000,
                                   0x0000, 0x0002, 0x012C, 0x0200, 0x0000, 0x0054, 0x0004, 0x0000 };

const s16 stg1300_data_tbl[32] = { 0x0000, 0x0003, 0x012C, 0x0200, 0x0000, 0x0058, 0x0015, 0x0000,
                                   0x0000, 0x0003, 0x212C, 0x0230, 0x0000, 0x0058, 0x0016, 0x0000,
                                   0x0000, 0x0002, 0x012C, 0x0200, 0x0000, 0x0054, 0x000F, 0x0000,
                                   0x0000, 0x0002, 0x012C, 0x0200, 0x0000, 0x0054, 0x0010, 0x0000 };

const s16 stg0600_data_tbl[8] = { 0x0000, 0x0001, 0x212C, 0x01FF, 0x0060, 0x0058, 0x000B, 0x0000 };

const s16 stg0700_data_tbl[32] = { 0x0000, 0x0003, 0x212C, 0x01F8, 0x0030, 0x005E, 0x0004, 0x0000,
                                   0x0000, 0x0003, 0x212C, 0x01F8, 0x0070, 0x005E, 0x0008, 0x0000,
                                   0x0000, 0x0002, 0x212C, 0x01D0, 0x0100, 0x0054, 0x0007, 0x0000,
                                   0x0000, 0x0002, 0x212C, 0x0200, 0x0160, 0x0054, 0x0008, 0x0000 };

const s16 stg0800_data_tbl[48] = { 0x0000, 0x0002, 0x212C, 0x01F0, 0x0030, 0x0055, 0x0001, 0x0000, 0x0000, 0x0007,
                                   0x212C, 0x0200, 0x002B, 0x0058, 0x000C, 0x0000, 0x0000, 0x0007, 0x212C, 0x0200,
                                   0x002B, 0x0058, 0x000D, 0x0000, 0x0000, 0x0002, 0x212C, 0x0270, 0x0078, 0x0056,
                                   0x0007, 0x0000, 0x0000, 0x0003, 0x212C, 0x0200, 0x0048, 0x005A, 0x0001, 0x0000,
                                   0x0000, 0x0003, 0x212C, 0x0200, 0x0048, 0x005A, 0x0002, 0x0000 };

const s16 stg0900_data_tbl[8] = { 0x0000, 0x0006, 0x212C, 0x0160, 0x0010, 0x000A, 0x0005, 0x0000 };

const s16 stg0c00_data_tbl[8] = { 0x0000, 0x0006, 0x212C, 0x0160, 0x0010, 0x000A, 0x0005, 0x0000 };

const s16 stg0d00_data_tbl[8] = { 0x0000, 0x0003, 0x012C, 0x0200, 0x0020, 0x0058, 0x0000, 0x0000 };

const s16 stg0e00_data_tbl[24] = { 0x0000, 0x0003, 0x012C, 0x0200, 0x0058, 0x0062, 0x0007, 0x0000,
                                   0x0000, 0x0002, 0x012C, 0x0240, 0x0040, 0x0054, 0x0005, 0x0000,
                                   0x0000, 0x0002, 0x012C, 0x0230, 0x00D0, 0x0054, 0x0006, 0x0000 };

const s16 stg1000_data_tbl[16] = { 0x0000, 0x0003, 0x212C, 0x0200, 0x0050, 0x0056, 0x0000, 0x0000,
                                   0x0000, 0x0002, 0x212C, 0x01E0, 0x0010, 0x000C, 0x0002, 0x0000 };

const s16 stg1100_data_tbl[16] = { 0x0000, 0x0001, 0x212C, 0x0200, 0x00B0, 0x005A, 0x0002, 0x0000,
                                   0x0000, 0x0001, 0x212C, 0x0200, 0x00F0, 0x005A, 0x0003, 0x0000 };

const s16 stg1400_data_tbl[32] = { 0x0000, 0x0002, 0x212C, 0x01F8, 0x000B, 0x000A, 0x0000, 0x0000,
                                   0x0000, 0x0001, 0x212C, 0x01F0, 0x0040, 0x0056, 0x0001, 0x0000,
                                   0x0000, 0x0003, 0x012C, 0x01F0, 0x0090, 0x0058, 0x0003, 0x0000,
                                   0x0000, 0x0003, 0x012C, 0x0200, 0x0140, 0x0053, 0x0005, 0x0000 };

const s16 stg1500_data_tbl[8] = { 0x0000, 0x0002, 0x012C, 0x01BD, 0x0030, 0x000A, 0x0000, 0x0000 };

const s16 stg1600_data_tbl[32] = { 0x0000, 0x0002, 0x012C, 0x0270, 0x0000, 0x000A, 0x0002, 0x0000,
                                   0x0000, 0x0002, 0x212C, 0x01FF, 0x0000, 0x000C, 0x0003, 0x0000,
                                   0x0000, 0x0002, 0x012C, 0x01FF, 0x0000, 0x0050, 0x0004, 0x0000,
                                   0x0000, 0x0002, 0x012C, 0x0260, 0x0030, 0x004D, 0x000B, 0x0000 };
