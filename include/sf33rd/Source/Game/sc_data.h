#ifndef SC_DATA_H
#define SC_DATA_H

#include "structs.h"
#include "types.h"

typedef const u8* UV_POS_TBL;

extern const u8 nwdata_tbl[21][6];
extern const u8 vmark_tbl[8];
extern const u8 smark_pos_tbl[3][2];
extern const u8 smark_kind_tbl[3];
extern const u8 combo_mtbl[7][3];
extern const u8 Player_Name_Pos_TBL[21][2];
extern const u8 Max_Pos_TBL[2][2];
extern const s16 Fade_Pos_tbl[8];
extern const s16 Akaobi_Pos_tbl[8];
extern const u8 Face_Pos_TBL[21][2];
extern const u8 Grade_Pos_TBL[32][2];
extern const s8 flash_timer_tbl[2];
extern const u8 flash_color_tbl[4];
extern const s16 hnc_wipe_tbl1[26][8];
extern const u8 ci_tbl[7][6];
extern const u8 cip_tbl[7];
extern const u8 rankname_pos_tbl[48][2];
extern const u16 sa_color_data_tbl[3];
extern const u8 sa1p_pos[28];
extern const u8 sa2p_pos[28];
extern const u8 bns_pos[110];
extern const u8 sa_uv_pos[29];
extern const u8 bp_uv_pos[111];
extern const u8 bb_uv_pos[111];
extern const u16 sa_ram_vram_col[][2];
extern const UV_POS_TBL sc_ram_vram_tbl[][2];
extern const s16 fade_data_tbl[][3];
extern const u32 bigger_col_tbl[][4];
extern const u16 Training_combo_pos_tbl[];
extern const u16 Training_combo_prio_tbl[];

extern TrainingData2 tr_data[];

#endif
