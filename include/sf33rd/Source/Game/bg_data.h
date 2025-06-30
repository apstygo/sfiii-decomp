#ifndef BG_DATA_H
#define BG_DATA_H

#include "structs.h"
#include "types.h"

extern const u8 use_scr[22];              // size: 0x16, address: 0x4E6F50
extern const u8 use_real_scr[22];         // size: 0x16, address: 0x4E6F70
extern const u8 use_family[22];           // size: 0x16, address: 0x4E6F90
extern const u8 rewrite_scr[22];          // size: 0x16, address: 0x4E6FB0
extern const u8 use_scr2[7];              // size: 0x7, address: 0x4E6FC8
extern const u8 stage_bgw_number[22][3];  // size: 0x42, address: 0x4E6FD0
extern const s32 msp[22][3][2];           // size: 0x210, address: 0x4E7020
extern const s32 msp2[7][3][2];           // size: 0xA8, address: 0x4E7230
extern const u16 stage000_map[64];        // size: 0x80, address: 0x4E72E0
extern const u16 stage001_map[64];        // size: 0x80, address: 0x4E7360
extern const u16 stage010_map[64];        // size: 0x80, address: 0x4E73E0
extern const u16 stage020_map[64];        // size: 0x80, address: 0x4E7460
extern const u16 stage021_map[64];        // size: 0x80, address: 0x4E74E0
extern const u16 stage022_map[64];        // size: 0x80, address: 0x4E7560
extern const u16 stage030_map[64];        // size: 0x80, address: 0x4E75E0
extern const u16 stage031_map[64];        // size: 0x80, address: 0x4E7660
extern const u16 stage040_map[64];        // size: 0x80, address: 0x4E76E0
extern const u16 stage050_map[64];        // size: 0x80, address: 0x4E7760
extern const u16 stage051_map[64];        // size: 0x80, address: 0x4E77E0
extern const u16 stage060_map[64];        // size: 0x80, address: 0x4E7860
extern const u16 stage070_map[64];        // size: 0x80, address: 0x4E78E0
extern const u16 stage071_map[64];        // size: 0x80, address: 0x4E7960
extern const u16 stage072_map[64];        // size: 0x80, address: 0x4E79E0
extern const u16 stage080_map[64];        // size: 0x80, address: 0x4E7A60
extern const u16 stage081_map[64];        // size: 0x80, address: 0x4E7AE0
extern const u16 stage090_map[64];        // size: 0x80, address: 0x4E7B60
extern const u16 stage091_map[64];        // size: 0x80, address: 0x4E7BE0
extern const u16 stage100_map[64];        // size: 0x80, address: 0x4E7C60
extern const u16 stage101_map[64];        // size: 0x80, address: 0x4E7CE0
extern const u16 stage110_map[64];        // size: 0x80, address: 0x4E7D60
extern const u16 stage120_map[64];        // size: 0x80, address: 0x4E7DE0
extern const u16 stage121_map[64];        // size: 0x80, address: 0x4E7E60
extern const u16 stage130_map[64];        // size: 0x80, address: 0x4E7EE0
extern const u16 stage131_map[64];        // size: 0x80, address: 0x4E7F60
extern const u16 stage140_map[64];        // size: 0x80, address: 0x4E7FE0
extern const u16 stage141_map[64];        // size: 0x80, address: 0x4E8060
extern const u16 stage142_map[64];        // size: 0x80, address: 0x4E80E0
extern const u16 stage150_map[64];        // size: 0x80, address: 0x4E8160
extern const u16 stage151_map[64];        // size: 0x80, address: 0x4E81E0
extern const u16 stage160_map[64];        // size: 0x80, address: 0x4E8260
extern const u16 stage161_map[64];        // size: 0x80, address: 0x4E82E0
extern const u16 stage180_map[64];        // size: 0x80, address: 0x4E8360
extern const u16 stage181_map[64];        // size: 0x80, address: 0x4E83E0
extern const u16 stage190_map[64];        // size: 0x80, address: 0x4E8460
extern const u16 bonus010_map[64];        // size: 0x80, address: 0x4E84E0
extern const u16 bonus011_map[64];        // size: 0x80, address: 0x4E8560
extern const u16 bonus020_map[64];        // size: 0x80, address: 0x4E85E0
extern const u16 select_map[64];          // size: 0x80, address: 0x4E8660
extern const u16 rank_map[64];            // size: 0x80, address: 0x4E86E0
extern const u16 win_lose_map[64];        // size: 0x80, address: 0x4E8760
extern const u32 bgtex_stage_gbix[22][3]; // size: 0x108, address: 0x4E87E0
extern const u32 bgtex_etc_gbix[7];       // size: 0x1C, address: 0x4E88F0
extern const u32 stage_priority[22];      // size: 0x58, address: 0x4E8910
extern const u32 etc_bg_priority[7];      // size: 0x1C, address: 0x4E8970
extern const u8 stage_opaque[22];         // size: 0x16, address: 0x4E8990
extern const s8 bgrw_on[22][8];           // size: 0xB0, address: 0x4E89B0
extern const u8 rw070[9];                 // size: 0x12, address: 0x4E8A60
extern const s16 rw071[9];                // size: 0x12, address: 0x4E8A80
extern const s16 rw072[9];                // size: 0x12, address: 0x4E8AA0
extern const s16 rw073[9];                // size: 0x12, address: 0x4E8AC0
extern const s16 rw180[21];               // size: 0x2A, address: 0x4E8AE0
extern const s16 rw181[21];               // size: 0x2A, address: 0x4E8B10
extern const s16 rw080[9];                // size: 0x12, address: 0x4E8B40
extern const s16 rw081[9];                // size: 0x12, address: 0x4E8B60
extern const s16 rw082[9];                // size: 0x12, address: 0x4E8B80
extern const s16 rw083[9];                // size: 0x12, address: 0x4E8BA0
extern const s16 rw084[9];                // size: 0x12, address: 0x4E8BC0
extern const s16 rw085[9];                // size: 0x12, address: 0x4E8BE0
extern const s16 rw086[9];                // size: 0x12, address: 0x4E8C00
extern const s16 rw087[9];                // size: 0x12, address: 0x4E8C20
extern const s16 rw032[13];               // size: 0x1A, address: 0x4E8C40
extern const s16 rw033[13];               // size: 0x1A, address: 0x4E8C60
extern const s16 rw034[13];               // size: 0x1A, address: 0x4E8C80
extern const s16 rw035[13];               // size: 0x1A, address: 0x4E8CA0
extern const s16 rw140[5];                // size: 0xA, address: 0x4E8CC0
extern const s16 rw193[9];                // size: 0x12, address: 0x4E8CD0
extern const s16 rw30[113];               // size: 0xE2, address: 0x4E8CF0
extern const u32 rw30col[8];              // size: 0x20, address: 0x4E8DE0
extern const s16 rw31[57];                // size: 0x72, address: 0x4E8E00
extern const u32 rw31col[4];              // size: 0x10, address: 0x4E8E80
extern const s16 rw190[26];               // size: 0x34, address: 0x4E8E90
extern const s16 rw191[11];               // size: 0x16, address: 0x4E8ED0
extern const s16 rw192[11];               // size: 0x16, address: 0x4E8EF0
extern const u32 bgrw_data_tbl[20][3];    // size: 0xF0, address: 0x4E8F10
extern const s32 stage03rw_data_tbl[13];  // size: 0x34, address: 0x4E9000
extern const u8 stage03_flash_tbl[16];    // size: 0x10, address: 0x4E9040
extern const s32 stage19rw_data_tbl[4];   // size: 0x10, address: 0x4E9050
extern const u8 stage19_loop_tbl1[16];    // size: 0x10, address: 0x4E9060
extern const u8 stage19_loop_tbl2[16];    // size: 0x10, address: 0x4E9070
extern const u8 ake_bg_off[20];           // size: 0x14, address: 0x4E9080
extern const s16 limit_tbl3[22][3][4];    // size: 0x210, address: 0x4E90A0
extern const s8 bg_index_tbl[22][3];      // size: 0x42, address: 0x4E92B0
extern const s32 bg_pos_tbl2[7][3][2];    // size: 0xA8, address: 0x4E9300
extern const s8 quake_x_tbl[130];         // size: 0x82, address: 0x4E93B0
extern const s8 quake_y_tbl[130];         // size: 0x82, address: 0x4E9440

extern s16 y_sitei_pos;     // size: 0x2, address: 0x578C20
extern u8 y_sitei_flag;     // size: 0x1, address: 0x578C24
extern u8 c_number;         // size: 0x1, address: 0x578C28
extern u8 c_kakikae;        // size: 0x1, address: 0x578C2C
extern u8 g_number[2];      // size: 0x2, address: 0x578C30
extern u8 g_kakikae[2];     // size: 0x2, address: 0x578C34
extern u8 nosekae;          // size: 0x1, address: 0x578C38
extern u16 *scr_bcm[4];     // size: 0x10, address: 0x578C40
extern s16 scrn_adgjust_y;  // size: 0x2, address: 0x578C50
extern s16 scrn_adgjust_x;  // size: 0x2, address: 0x578C54
extern u16 zoom_add;        // size: 0x2, address: 0x578C58
extern s16 ls_cnt1;         // size: 0x2, address: 0x578C5C
extern s8 bg_app;           // size: 0x1, address: 0x578C60
extern s8 sa_pa_flag;       // size: 0x1, address: 0x578C64
extern s8 aku_flag;         // size: 0x1, address: 0x578C68
extern s8 seraph_flag;      // size: 0x1, address: 0x578C6C
extern s8 akebono_flag;     // size: 0x1, address: 0x578C70
extern MVXY bg_mvxy;        // size: 0x18, address: 0x578C80
extern s16 chase_time_y;    // size: 0x2, address: 0x578C98
extern s16 chase_time_x;    // size: 0x2, address: 0x578C9C
extern s16 chase_y;         // size: 0x2, address: 0x578CA0
extern s16 chase_x;         // size: 0x2, address: 0x578CA4
extern s8 demo_car_flag[2]; // size: 0x2, address: 0x578CA8
extern Ideal_W ideal_w;     // size: 0x8, address: 0x578CB0
extern BGW *bgw_ptr;        // size: 0x4, address: 0x578CB8
extern s8 bg_app_stop;      // size: 0x1, address: 0x578CBC
extern s16 bg_stop;         // size: 0x2, address: 0x578CC0
extern s16 base_y_pos;      // size: 0x2, address: 0x578CC4

#endif
