#ifndef STRUCTS_H
#define STRUCTS_H

#include "types.h"
#include <libdma.h>
#include <libgraph.h>

typedef struct {
    // total size: 0x18
    f32 x0; // offset 0x0, size 0x4
    f32 y0; // offset 0x4, size 0x4
    f32 x1; // offset 0x8, size 0x4
    f32 y1; // offset 0xC, size 0x4
    f32 ne; // offset 0x10, size 0x4
    f32 fa; // offset 0x14, size 0x4
} VPRM;

typedef struct {
    // total size: 0x8
    u8 *pFrame;  // offset 0x0, size 0x4
    s32 heapnum; // offset 0x4, size 0x4
} FMS_FRAME;

typedef struct {
    // total size: 0x4C
    FMS_FRAME fmsFrame;    // offset 0x0, size 0x8
    u8 *ramcntBuff;        // offset 0x8, size 0x4
    VPRM vprm;             // offset 0xC, size 0x18
    s8 ds_h[2];            // offset 0x24, size 0x2
    s8 ds_v[2];            // offset 0x26, size 0x2
    s8 sysStop;            // offset 0x28, size 0x1
    s8 initTrainingData;   // offset 0x29, size 0x1
    s8 inGame;             // offset 0x2A, size 0x1
    s8 ctrDemo;            // offset 0x2B, size 0x1
    s8 language;           // offset 0x2C, size 0x1
    s8 langload;           // offset 0x2D, size 0x1
    s8 cutAnalogStickData; // offset 0x2E, size 0x1
    s8 useAnalogStickData; // offset 0x2F, size 0x1
    s8 pal50Hz;            // offset 0x30, size 0x1
    u32 hanFbTex;          // offset 0x34, size 0x4
    u8 useChar[20];        // offset 0x38, size 0x14
} MPP;

typedef struct {
    // total size: 0xC
    s16 x;   // offset 0x0, size 0x2
    s16 y;   // offset 0x2, size 0x2
    s16 pow; // offset 0x4, size 0x2
    s16 ang; // offset 0x6, size 0x2
    f32 rad; // offset 0x8, size 0x4
} PAD_STICK;

typedef struct {
    // total size: 0x6C
    struct {
        // total size: 0x34
        u8 state;           // offset 0x0, size 0x1
        u8 anstate;         // offset 0x1, size 0x1
        u16 kind;           // offset 0x2, size 0x2
        u32 sw;             // offset 0x4, size 0x4
        u32 sw_old;         // offset 0x8, size 0x4
        u32 sw_new;         // offset 0xC, size 0x4
        u32 sw_off;         // offset 0x10, size 0x4
        u32 sw_chg;         // offset 0x14, size 0x4
        u32 sw_repeat;      // offset 0x18, size 0x4
        PAD_STICK stick[2]; // offset 0x1C, size 0x18
    } data[2];              // offset 0x0, size 0x68
    u16 sw[2];              // offset 0x68, size 0x4
} IO;

struct _TASK {
    // total size: 0x14
    void (*func_adrs)();     // offset 0x0, size 0x4
    void (*callback_adrs)(); // offset 0x4, size 0x4
    u8 r_no[4];              // offset 0x8, size 0x4
    u16 condition;           // offset 0xC, size 0x2
    s16 timer;               // offset 0xE, size 0x2
    u8 free[4];              // offset 0x10, size 0x4
};

typedef struct {
    // total size: 0xD08
    s32 x16;            // offset 0x0, size 0x4
    s32 x32;            // offset 0x4, size 0x4
    u16 x16_used[1024]; // offset 0x8, size 0x800
    u16 x32_used[640];  // offset 0x808, size 0x500
} TPU;

struct _disp {
    // total size: 0xC
    u16 size_x; // offset 0x0, size 0x2
    u16 size_y; // offset 0x2, size 0x2
    u16 now;    // offset 0x4, size 0x2
    u16 new;    // offset 0x6, size 0x2
    s32 cable;  // offset 0x8, size 0x4
};

struct _SYSTEM_W {
    // total size: 0x1C
    struct _disp disp; // offset 0x0, size 0xC
    s32 pause;         // offset 0xC, size 0x4
    s32 gd_error;      // offset 0x10, size 0x4
    s32 reset;         // offset 0x14, size 0x4
    u8 sound_mode;     // offset 0x18, size 0x1
    u8 screen_mode;    // offset 0x19, size 0x1
    u8 bgm_type;       // offset 0x1A, size 0x1
    u8 dummy;          // offset 0x1B, size 0x1
};

typedef struct {
    // total size: 0x10
    u16 boix; // offset 0x0, size 0x2
    u16 bhix; // offset 0x2, size 0x2
    u16 haix; // offset 0x4, size 0x2
    union /* @anon10 */ {
        u16 full; // offset 0x0, size 0x2
        struct /* @anon12 */ {
            // total size: 0x2
            u8 bx; // offset 0x0, size 0x1
            u8 mv; // offset 0x1, size 0x1
        } half;    // offset 0x0, size 0x2
    } mf;          // offset 0x6, size 0x2
    u16 caix;      // offset 0x8, size 0x2
    u16 cuix;      // offset 0xA, size 0x2
    u16 atix;      // offset 0xC, size 0x2
    u16 hoix;      // offset 0xE, size 0x2
} UNK_0;

typedef struct {
    // total size: 0x20
    s16 body_dm[4][4]; // offset 0x0, size 0x20
} UNK_1;

typedef struct {
    // total size: 0x20
    s16 hand_dm[4][4]; // offset 0x0, size 0x20
} UNK_2;

typedef struct {
    // total size: 0x8
    s16 cat_box[4]; // offset 0x0, size 0x8
} UNK_3;

typedef struct {
    // total size: 0x8
    s16 cau_box[4]; // offset 0x0, size 0x8
} UNK_4;

typedef struct {
    // total size: 0x20
    s16 att_box[4][4]; // offset 0x0, size 0x20
} UNK_5;

typedef struct {
    // total size: 0x8
    s16 hos_box[4]; // offset 0x0, size 0x8
} UNK_6;

typedef struct {
    // total size: 0x10
    u8 reaction; // offset 0x0, size 0x1
    u8 level;    // offset 0x1, size 0x1
    u8 mkh_ix;   // offset 0x2, size 0x1
    u8 but_ix;   // offset 0x3, size 0x1
    u8 dipsw;    // offset 0x4, size 0x1
    u8 guard;    // offset 0x5, size 0x1
    u8 dir;      // offset 0x6, size 0x1
    u8 free;     // offset 0x7, size 0x1
    u8 pow;      // offset 0x8, size 0x1
    u8 impact;   // offset 0x9, size 0x1
    u8 piyo;     // offset 0xA, size 0x1
    u8 ng_type;  // offset 0xB, size 0x1
    s8 hs_me;    // offset 0xC, size 0x1
    s8 hs_you;   // offset 0xD, size 0x1
    u8 hit_mark; // offset 0xE, size 0x1
    u8 dmg_mark; // offset 0xF, size 0x1
} UNK_7;

typedef struct {
    // total size: 0x10
    s16 parts_hos_x; // offset 0x0, size 0x2
    s16 parts_hos_y; // offset 0x2, size 0x2
    u8 parts_colmd;  // offset 0x4, size 0x1
    u8 parts_colcd;  // offset 0x5, size 0x1
    u8 parts_prio;   // offset 0x6, size 0x1
    u8 parts_flip;   // offset 0x7, size 0x1
    u8 parts_timer;  // offset 0x8, size 0x1
    u8 parts_disp;   // offset 0x9, size 0x1
    s16 parts_mts;   // offset 0xA, size 0x2
    u16 parts_nix;   // offset 0xC, size 0x2
    u16 parts_char;  // offset 0xE, size 0x2
} UNK_8;

typedef struct {
    // total size: 0x8
    s16 olc_ix[4]; // offset 0x0, size 0x8
} UNK_9;

typedef struct {
    // total size: 0x8
    s16 catch_hos_x; // offset 0x0, size 0x2
    s16 catch_hos_y; // offset 0x2, size 0x2
    u8 catch_prio;   // offset 0x4, size 0x1
    u8 catch_flip;   // offset 0x5, size 0x1
    s16 catch_nix;   // offset 0x6, size 0x2
} UNK_10;

typedef struct {
    // total size: 0x8
    u16 code; // offset 0x0, size 0x2
    s16 koc;  // offset 0x2, size 0x2
    s16 ix;   // offset 0x4, size 0x2
    s16 pat;  // offset 0x6, size 0x2
} UNK11;

typedef union {
    s32 sp; // offset 0x0, size 0x4
    struct /* @anon17 */ {
        // total size: 0x4
        s16 l; // offset 0x0, size 0x2
        s16 h; // offset 0x2, size 0x2
    } real;    // offset 0x0, size 0x4
} UNK_13;

typedef struct {
    // total size: 0x18
    UNK_13 a[2]; // offset 0x0, size 0x8
    UNK_13 d[2]; // offset 0x8, size 0x8
    s16 kop[2];  // offset 0x10, size 0x4
    u16 index;   // offset 0x14, size 0x2
} MVXY;

typedef union {
    s32 cal; // offset 0x0, size 0x4
    struct {
        // total size: 0x4
        s16 low; // offset 0x0, size 0x2
        s16 pos; // offset 0x2, size 0x2
    } disp;      // offset 0x0, size 0x4
} XY;

typedef struct {
    // total size: 0x388
    s8 be_flag;              // offset 0x0, size 0x1
    s8 disp_flag;            // offset 0x1, size 0x1
    u8 blink_timing;         // offset 0x2, size 0x1
    u8 operator;             // offset 0x3, size 0x1
    u8 type;                 // offset 0x4, size 0x1
    u8 charset_id;           // offset 0x5, size 0x1
    s16 work_id;             // offset 0x6, size 0x2
    s16 id;                  // offset 0x8, size 0x2
    s8 rl_flag;              // offset 0xA, size 0x1
    s8 rl_waza;              // offset 0xB, size 0x1
    u32 *target_adrs;        // offset 0xC, size 0x4
    u32 *hit_adrs;           // offset 0x10, size 0x4
    u32 *dmg_adrs;           // offset 0x14, size 0x4
    s16 before;              // offset 0x18, size 0x2
    s16 myself;              // offset 0x1A, size 0x2
    s16 behind;              // offset 0x1C, size 0x2
    s16 listix;              // offset 0x1E, size 0x2
    s16 dead_f;              // offset 0x20, size 0x2
    s16 timing;              // offset 0x22, size 0x2
    s16 routine_no[8];       // offset 0x24, size 0x10
    s16 old_rno[8];          // offset 0x34, size 0x10
    s16 hit_stop;            // offset 0x44, size 0x2
    s16 hit_quake;           // offset 0x46, size 0x2
    s8 cgromtype;            // offset 0x48, size 0x1
    u8 kage_flag;            // offset 0x49, size 0x1
    s16 kage_hx;             // offset 0x4A, size 0x2
    s16 kage_hy;             // offset 0x4C, size 0x2
    s16 kage_prio;           // offset 0x4E, size 0x2
    s16 kage_width;          // offset 0x50, size 0x2
    s16 kage_char;           // offset 0x52, size 0x2
    s16 position_x;          // offset 0x54, size 0x2
    s16 position_y;          // offset 0x56, size 0x2
    s16 position_z;          // offset 0x58, size 0x2
    s16 next_x;              // offset 0x5A, size 0x2
    s16 next_y;              // offset 0x5C, size 0x2
    s16 next_z;              // offset 0x5E, size 0x2
    s16 scr_mv_x;            // offset 0x60, size 0x2
    s16 scr_mv_y;            // offset 0x62, size 0x2
    XY xyz[3];               // offset 0x64, size 0xC
    s16 old_pos[3];          // offset 0x70, size 0x6
    s16 sync_suzi;           // offset 0x76, size 0x2
    u16 *suzi_offset;        // offset 0x78, size 0x4
    MVXY mvxy;               // offset 0x7C, size 0x18
    s16 direction;           // offset 0x94, size 0x2
    s16 dir_old;             // offset 0x96, size 0x2
    s16 dir_step;            // offset 0x98, size 0x2
    s16 dir_timer;           // offset 0x9A, size 0x2
    s16 vitality;            // offset 0x9C, size 0x2
    s16 vital_new;           // offset 0x9E, size 0x2
    s16 vital_old;           // offset 0xA0, size 0x2
    s16 dm_vital;            // offset 0xA2, size 0x2
    s16 dmcal_m;             // offset 0xA4, size 0x2
    s16 dmcal_d;             // offset 0xA6, size 0x2
    s8 weight_level;         // offset 0xA8, size 0x1
    UNK11 cmoa;              // offset 0xAA, size 0x8
    UNK11 cmsw;              // offset 0xB2, size 0x8
    UNK11 cmlp;              // offset 0xBA, size 0x8
    UNK11 cml2;              // offset 0xC2, size 0x8
    UNK11 cmja;              // offset 0xCA, size 0x8
    UNK11 cmj2;              // offset 0xD2, size 0x8
    UNK11 cmj3;              // offset 0xDA, size 0x8
    UNK11 cmj4;              // offset 0xE2, size 0x8
    UNK11 cmj5;              // offset 0xEA, size 0x8
    UNK11 cmj6;              // offset 0xF2, size 0x8
    UNK11 cmj7;              // offset 0xFA, size 0x8
    UNK11 cmms;              // offset 0x102, size 0x8
    UNK11 cmmd;              // offset 0x10A, size 0x8
    UNK11 cmyd;              // offset 0x112, size 0x8
    UNK11 cmcf;              // offset 0x11A, size 0x8
    UNK11 cmcr;              // offset 0x122, size 0x8
    UNK11 cmbk;              // offset 0x12A, size 0x8
    UNK11 cmb2;              // offset 0x132, size 0x8
    UNK11 cmb3;              // offset 0x13A, size 0x8
    UNK11 cmhs;              // offset 0x142, size 0x8
    UNK11 cmr0;              // offset 0x14A, size 0x8
    UNK11 cmr1;              // offset 0x152, size 0x8
    UNK11 cmr2;              // offset 0x15A, size 0x8
    UNK11 cmr3;              // offset 0x162, size 0x8
    s16 cmwk[32];            // offset 0x16A, size 0x40
    u32 *char_table[12];     // offset 0x1AC, size 0x30
    u32 *se_random_table;    // offset 0x1DC, size 0x4
    s16 *step_xy_table;      // offset 0x1E0, size 0x4
    s16 *move_xy_table;      // offset 0x1E4, size 0x4
    UNK_8 *overlap_char_tbl; // offset 0x1E8, size 0x4
    UNK_9 *olc_ix_table;     // offset 0x1EC, size 0x4
    UNK_9 cg_olc;            // offset 0x1F0, size 0x8
    UNK_10 *rival_catch_tbl; // offset 0x1F8, size 0x4
    UNK_10 *curr_rca;        // offset 0x1FC, size 0x4
    u32 *set_char_ad;        // offset 0x200, size 0x4
    s16 cg_ix;               // offset 0x204, size 0x2
    s16 now_koc;             // offset 0x206, size 0x2
    s16 char_index;          // offset 0x208, size 0x2
    s16 current_colcd;       // offset 0x20A, size 0x2
    s16 cgd_type;            // offset 0x20C, size 0x2
    u8 pat_status;           // offset 0x20E, size 0x1
    u8 kind_of_waza;         // offset 0x20F, size 0x1
    u8 hit_range;            // offset 0x210, size 0x1
    u8 total_paring;         // offset 0x211, size 0x1
    u8 total_att_set;        // offset 0x212, size 0x1
    u8 sp_tech_id;           // offset 0x213, size 0x1
    u8 cg_type;              // offset 0x214, size 0x1
    u8 cg_ctr;               // offset 0x215, size 0x1
    u16 cg_se;               // offset 0x216, size 0x2
    u16 cg_olc_ix;           // offset 0x218, size 0x2
    u16 cg_number;           // offset 0x21A, size 0x2
    u16 cg_hit_ix;           // offset 0x21C, size 0x2
    s16 cg_att_ix;           // offset 0x21E, size 0x2
    u8 cg_extdat;            // offset 0x220, size 0x1
    u8 cg_cancel;            // offset 0x221, size 0x1
    u8 cg_effect;            // offset 0x222, size 0x1
    u8 cg_eftype;            // offset 0x223, size 0x1
    u16 cg_zoom;             // offset 0x224, size 0x2
    u16 cg_rival;            // offset 0x226, size 0x2
    u16 cg_add_xy;           // offset 0x228, size 0x2
    u8 cg_next_ix;           // offset 0x22A, size 0x1
    u8 cg_status;            // offset 0x22B, size 0x1
    s16 cg_wca_ix;           // offset 0x22C, size 0x2
    s16 cg_jphos;            // offset 0x22E, size 0x2
    u16 cg_meoshi;           // offset 0x230, size 0x2
    u8 cg_prio;              // offset 0x232, size 0x1
    u8 cg_flip;              // offset 0x233, size 0x1
    u16 old_cgnum;           // offset 0x234, size 0x2
    s16 floor;               // offset 0x236, size 0x2
    u16 ccoff;               // offset 0x238, size 0x2
    s16 colcd;               // offset 0x23A, size 0x2
    s16 my_col_mode;         // offset 0x23C, size 0x2
    s16 my_col_code;         // offset 0x23E, size 0x2
    s16 my_priority;         // offset 0x240, size 0x2
    s16 my_family;           // offset 0x242, size 0x2
    s16 my_ext_pri;          // offset 0x244, size 0x2
    s16 my_bright_type;      // offset 0x246, size 0x2
    s16 my_bright_level;     // offset 0x248, size 0x2
    s16 my_clear_level;      // offset 0x24A, size 0x2
    s16 my_mts;              // offset 0x24C, size 0x2
    s16 my_mr_flag;          // offset 0x24E, size 0x2
    struct /* @anon47 */ {
        // total size: 0x4
        struct /* @anon48 */ {
            // total size: 0x4
            s16 x;     // offset 0x0, size 0x2
            s16 y;     // offset 0x2, size 0x2
        } size;        // offset 0x0, size 0x4
    } my_mr;           // offset 0x250, size 0x4
    s16 my_trans_mode; // offset 0x254, size 0x2
    s16 my_roll_flag;  // offset 0x256, size 0x2
    struct /* @anon52 */ {
        // total size: 0x8
        s16 now;           // offset 0x0, size 0x2
        s16 add;           // offset 0x2, size 0x2
        s16 free;          // offset 0x4, size 0x2
        s16 old;           // offset 0x6, size 0x2
    } my_roll;             // offset 0x258, size 0x8
    s16 waku_work_index;   // offset 0x260, size 0x2
    s16 olc_work_ix[4];    // offset 0x262, size 0x8
    UNK_0 *hit_ix_table;   // offset 0x26C, size 0x4
    UNK_0 cg_ja;           // offset 0x270, size 0x10
    UNK_1 *body_adrs;      // offset 0x280, size 0x4
    UNK_1 *h_bod;          // offset 0x284, size 0x4
    UNK_2 *hand_adrs;      // offset 0x288, size 0x4
    UNK_2 *h_han;          // offset 0x28C, size 0x4
    UNK_2 *dumm_adrs;      // offset 0x290, size 0x4
    UNK_2 *h_dumm;         // offset 0x294, size 0x4
    UNK_3 *catch_adrs;     // offset 0x298, size 0x4
    UNK_3 *h_cat;          // offset 0x29C, size 0x4
    UNK_4 *caught_adrs;    // offset 0x2A0, size 0x4
    UNK_4 *h_cau;          // offset 0x2A4, size 0x4
    UNK_5 *attack_adrs;    // offset 0x2A8, size 0x4
    UNK_5 *h_att;          // offset 0x2AC, size 0x4
    UNK_5 *h_eat;          // offset 0x2B0, size 0x4
    UNK_6 *hosei_adrs;     // offset 0x2B4, size 0x4
    UNK_6 *h_hos;          // offset 0x2B8, size 0x4
    UNK_7 *att_ix_table;   // offset 0x2BC, size 0x4
    UNK_7 att;             // offset 0x2C0, size 0x10
    u16 zu_flag;           // offset 0x2D0, size 0x2
    u16 at_attribute;      // offset 0x2D2, size 0x2
    s16 kezuri_pow;        // offset 0x2D4, size 0x2
    u16 add_arts_point;    // offset 0x2D6, size 0x2
    u16 buttobi_type;      // offset 0x2D8, size 0x2
    u16 att_zuru;          // offset 0x2DA, size 0x2
    u16 at_ten_ix;         // offset 0x2DC, size 0x2
    s16 dir_atthit;        // offset 0x2DE, size 0x2
    s16 vs_id;             // offset 0x2E0, size 0x2
    u8 att_hit_ok;         // offset 0x2E2, size 0x1
    u8 meoshi_hit_flag;    // offset 0x2E3, size 0x1
    u16 at_koa;            // offset 0x2E4, size 0x2
    u8 paring_attack_flag; // offset 0x2E6, size 0x1
    s8 no_death_attack;    // offset 0x2E7, size 0x1
    u8 jump_att_flag;      // offset 0x2E8, size 0x1
    s8 shell_vs_refrect;   // offset 0x2E9, size 0x1
    s16 renew_attack;      // offset 0x2EA, size 0x2
    u16 attack_num;        // offset 0x2EC, size 0x2
    u16 uketa_att[4];      // offset 0x2EE, size 0x8
    union /* @anon16 */ {
        struct /* @anon18 */ {
            // total size: 0x2
            u8 player;     // offset 0x0, size 0x1
            u8 effect;     // offset 0x1, size 0x1
        } hit;             // offset 0x0, size 0x2
        u16 hit_flag;      // offset 0x0, size 0x2
    } hf;                  // offset 0x2F6, size 0x2
    s16 hit_mark_x;        // offset 0x2F8, size 0x2
    s16 hit_mark_y;        // offset 0x2FA, size 0x2
    s16 hit_mark_z;        // offset 0x2FC, size 0x2
    s16 kohm;              // offset 0x2FE, size 0x2
    u8 dm_fushin;          // offset 0x300, size 0x1
    s8 dm_weight;          // offset 0x301, size 0x1
    u16 dm_butt_type;      // offset 0x302, size 0x2
    u16 dm_zuru;           // offset 0x304, size 0x2
    u16 dm_attribute;      // offset 0x306, size 0x2
    s16 dm_guard_success;  // offset 0x308, size 0x2
    s16 dm_plnum;          // offset 0x30A, size 0x2
    s16 dm_attlv;          // offset 0x30C, size 0x2
    s16 dm_dir;            // offset 0x30E, size 0x2
    s8 dm_rl;              // offset 0x310, size 0x1
    u8 dm_impact;          // offset 0x311, size 0x1
    s16 dm_stop;           // offset 0x312, size 0x2
    s16 dm_quake;          // offset 0x314, size 0x2
    u16 dm_piyo;           // offset 0x316, size 0x2
    u16 dm_ten_ix;         // offset 0x318, size 0x2
    u16 dm_koa;            // offset 0x31A, size 0x2
    s16 dm_work_id;        // offset 0x31C, size 0x2
    u16 dm_arts_point;     // offset 0x31E, size 0x2
    u8 dm_jump_att_flag;   // offset 0x320, size 0x1
    u8 dm_free;            // offset 0x321, size 0x1
    s16 dm_count_up;       // offset 0x322, size 0x2
    s8 dm_nodeathattack;   // offset 0x324, size 0x1
    u8 dm_exdm_ix;         // offset 0x325, size 0x1
    u8 dm_dip;             // offset 0x326, size 0x1
    u8 dm_kind_of_waza;    // offset 0x327, size 0x1
    s16 attpow;            // offset 0x328, size 0x2
    s16 defpow;            // offset 0x32A, size 0x2
    u32 *my_effadrs;       // offset 0x32C, size 0x4
    s16 shell_ix[8];       // offset 0x330, size 0x10
    s16 hm_dm_side;        // offset 0x340, size 0x2
    s16 extra_col;         // offset 0x342, size 0x2
    s16 extra_col_2;       // offset 0x344, size 0x2
    s16 original_vitality; // offset 0x346, size 0x2
    u8 hit_work_id;        // offset 0x348, size 0x1
    u8 dmg_work_id;        // offset 0x349, size 0x1
    s8 K5_init_flag;       // offset 0x34A, size 0x1
    s8 K5_exec_ok;         // offset 0x34B, size 0x1
    u8 kow;                // offset 0x34C, size 0x1
    u8 swallow_no_effect;  // offset 0x34D, size 0x1
    s16 E3_work_index;     // offset 0x34E, size 0x2
    s16 E4_work_index;     // offset 0x350, size 0x2
    u8 kezurare_flag;      // offset 0x352, size 0x1
    u8 wrd_free[53];       // offset 0x353, size 0x35
} WORK;

typedef struct {
    // total size: 0x2C
    s16 kind_of_arts; // offset 0x0, size 0x2
    u8 nmsa_g_ix;     // offset 0x2, size 0x1
    u8 exsa_g_ix;     // offset 0x3, size 0x1
    u8 exs2_g_ix;     // offset 0x4, size 0x1
    u8 nmsa_a_ix;     // offset 0x5, size 0x1
    u8 exsa_a_ix;     // offset 0x6, size 0x1
    u8 exs2_a_ix;     // offset 0x7, size 0x1
    s8 gauge_type;    // offset 0x8, size 0x1
    s8 mp;            // offset 0x9, size 0x1
    s8 ok;            // offset 0xA, size 0x1
    s8 ex;            // offset 0xB, size 0x1
    s8 ba;            // offset 0xC, size 0x1
    s8 dtm_mul;       // offset 0xD, size 0x1
    s8 mp_rno;        // offset 0xE, size 0x1
    s8 mp_rno2;       // offset 0xF, size 0x1
    s8 sa_rno;        // offset 0x10, size 0x1
    s8 sa_rno2;       // offset 0x11, size 0x1
    s8 ex_rno;        // offset 0x12, size 0x1
    s8 gt2;           // offset 0x13, size 0x1
    s8 saeff_ok;      // offset 0x14, size 0x1
    s8 saeff_mp;      // offset 0x15, size 0x1
    s16 gauge_len;    // offset 0x16, size 0x2
    union {
        s32 i; // offset 0x0, size 0x4
        struct {
            // total size: 0x4
            s16 l;   // offset 0x0, size 0x2
            s16 h;   // offset 0x2, size 0x2
        } s;         // offset 0x0, size 0x4
    } gauge;         // offset 0x18, size 0x4
    s32 dtm;         // offset 0x1C, size 0x4
    s16 store_max;   // offset 0x20, size 0x2
    s16 store;       // offset 0x22, size 0x2
    s16 id_arts;     // offset 0x24, size 0x2
    u8 ex4th_full;   // offset 0x26, size 0x1
    u8 ex4th_exec;   // offset 0x27, size 0x1
    s16 total_gauge; // offset 0x28, size 0x2
    s16 bacckup_g_h; // offset 0x2A, size 0x2
} SA_WORK;

typedef struct {
    // total size: 0x46C
    WORK wu; // offset 0x0, size 0x388
    struct /* @anon65 */ {
        // total size: 0x406
        u16 sw_lvbt;       // offset 0x0, size 0x2
        u16 sw_new;        // offset 0x2, size 0x2
        u16 sw_old;        // offset 0x4, size 0x2
        u16 sw_now;        // offset 0x6, size 0x2
        u16 sw_off;        // offset 0x8, size 0x2
        u16 sw_chg;        // offset 0xA, size 0x2
        u16 old_now;       // offset 0xC, size 0x2
        s16 lgp;           // offset 0xE, size 0x2
        u8 ca14;           // offset 0x10, size 0x1
        u8 ca25;           // offset 0x11, size 0x1
        u8 ca36;           // offset 0x12, size 0x1
        u8 calf;           // offset 0x13, size 0x1
        u8 calr;           // offset 0x14, size 0x1
        u8 lever_dir;      // offset 0x15, size 0x1
        s16 waza_flag[56]; // offset 0x16, size 0x70
        s16 reset[56];     // offset 0x86, size 0x70
        u8 waza_r[56][4];  // offset 0xF6, size 0xE0
        u16 btix[56];      // offset 0x1D6, size 0x70
        u16 exdt[56][4];   // offset 0x246, size 0x1C0
    } *cp;                 // offset 0x388, size 0x4
    u32 spmv_ng_flag;      // offset 0x38C, size 0x4
    u32 spmv_ng_flag2;     // offset 0x390, size 0x4
    s16 player_number;     // offset 0x394, size 0x2
    s16 zuru_timer;        // offset 0x396, size 0x2
    u16 zuru_ix_counter;   // offset 0x398, size 0x2
    u8 zuru_flag;          // offset 0x39A, size 0x1
    s8 tsukamarenai_flag;  // offset 0x39B, size 0x1
    u8 kizetsu_kow;        // offset 0x39C, size 0x1
    u8 micchaku_flag;      // offset 0x39D, size 0x1
    u8 hos_fi_flag;        // offset 0x39E, size 0x1
    u8 hos_em_flag;        // offset 0x39F, size 0x1
    s16 tsukami_num;       // offset 0x3A0, size 0x2
    s8 tsukami_f;          // offset 0x3A2, size 0x1
    s8 tsukamare_f;        // offset 0x3A3, size 0x1
    s8 kind_of_catch;      // offset 0x3A4, size 0x1
    u8 old_gdflag;         // offset 0x3A5, size 0x1
    u8 guard_flag;         // offset 0x3A6, size 0x1
    u8 guard_chuu;         // offset 0x3A7, size 0x1
    s16 dm_ix;             // offset 0x3A8, size 0x2
    s16 hosei_amari;       // offset 0x3AA, size 0x2
    s8 dm_hos_flag;        // offset 0x3AC, size 0x1
    u8 dm_point;           // offset 0x3AD, size 0x1
    s16 muriyari_ugoku;    // offset 0x3AE, size 0x2
    s8 scr_pos_set_flag;   // offset 0x3B0, size 0x1
    s8 hoshi_flag;         // offset 0x3B1, size 0x1
    s8 the_same_players;   // offset 0x3B2, size 0x1
    s8 *dm_step_tbl;       // offset 0x3B4, size 0x4
    s8 running_f;          // offset 0x3B8, size 0x1
    s8 cancel_timer;       // offset 0x3B9, size 0x1
    s8 jpdir;              // offset 0x3BA, size 0x1
    s8 jptim;              // offset 0x3BB, size 0x1
    s16 current_attack;    // offset 0x3BC, size 0x2
    struct /* @anon17 */ {
        // total size: 0x6
        s16 r_no;    // offset 0x0, size 0x2
        s16 char_ix; // offset 0x2, size 0x2
        s16 data_ix; // offset 0x4, size 0x2
    } *as;           // offset 0x3C0, size 0x4
    SA_WORK *sa;     // offset 0x3C4, size 0x4
    struct /* @anon27 */ {
        // total size: 0xA8
        s16 total;             // offset 0x0, size 0x2
        s16 new_dm;            // offset 0x2, size 0x2
        s16 req_f;             // offset 0x4, size 0x2
        s16 old_r;             // offset 0x6, size 0x2
        s16 kind_of[10][4][2]; // offset 0x8, size 0xA0
    } *cb;                     // offset 0x3C8, size 0x4
    struct /* @anon28 */ {
        // total size: 0x14
        s8 flag;    // offset 0x0, size 0x1
        s16 genkai; // offset 0x2, size 0x2
        s16 time;   // offset 0x4, size 0x2
        union /* @anon40 */ {
            s32 timer; // offset 0x0, size 0x4
            struct /* @anon41 */ {
                // total size: 0x4
                s16 l;    // offset 0x0, size 0x2
                s16 h;    // offset 0x2, size 0x2
            } quantity;   // offset 0x0, size 0x4
        } now;            // offset 0x8, size 0x4
        s32 recover;      // offset 0xC, size 0x4
        s16 store;        // offset 0x10, size 0x2
        s16 again;        // offset 0x12, size 0x2
    } *py;                // offset 0x3CC, size 0x4
    s8 wkey_flag;         // offset 0x3D0, size 0x1
    s8 dead_flag;         // offset 0x3D1, size 0x1
    s16 ukemi_ok_timer;   // offset 0x3D2, size 0x2
    s16 backup_ok_timer;  // offset 0x3D4, size 0x2
    s8 uot_cd_ok_flag;    // offset 0x3D6, size 0x1
    s8 ukemi_success;     // offset 0x3D7, size 0x1
    s16 old_pos_data[8];  // offset 0x3D8, size 0x10
    s16 move_distance;    // offset 0x3E8, size 0x2
    s16 move_power;       // offset 0x3EA, size 0x2
    s16 sa_stop_sai;      // offset 0x3EC, size 0x2
    u8 saishin_lvdir;     // offset 0x3EE, size 0x1
    u8 sa_stop_lvdir;     // offset 0x3EF, size 0x1
    u8 sa_stop_flag;      // offset 0x3F0, size 0x1
    u8 kezurijini_flag;   // offset 0x3F1, size 0x1
    WORK *illusion_work;  // offset 0x3F4, size 0x4
    s16 image_setup_flag; // offset 0x3F8, size 0x2
    s16 image_data_index; // offset 0x3FA, size 0x2
    u8 caution_flag;      // offset 0x3FC, size 0x1
    u8 tc_1st_flag;       // offset 0x3FD, size 0x1
    struct /* @anon27 */ {
        // total size: 0xA8
        s16 total;             // offset 0x0, size 0x2
        s16 new_dm;            // offset 0x2, size 0x2
        s16 req_f;             // offset 0x4, size 0x2
        s16 old_r;             // offset 0x6, size 0x2
        s16 kind_of[10][4][2]; // offset 0x8, size 0xA0
    } *rp;                     // offset 0x400, size 0x4
    s16 bullet_hcnt;           // offset 0x404, size 0x2
    s16 bhcnt_timer;           // offset 0x406, size 0x2
    s8 cat_break_ok_timer;     // offset 0x408, size 0x1
    s8 cat_break_reserve;      // offset 0x409, size 0x1
    s8 hazusenai_flag;         // offset 0x40A, size 0x1
    s8 hurimukenai_flag;       // offset 0x40B, size 0x1
    u8 tk_success;             // offset 0x40C, size 0x1
    u8 resurrection_resv;      // offset 0x40D, size 0x1
    s16 tk_dageki;             // offset 0x40E, size 0x2
    s16 tk_nage;               // offset 0x410, size 0x2
    s16 tk_kizetsu;            // offset 0x412, size 0x2
    s16 tk_konjyou;            // offset 0x414, size 0x2
    s16 utk_dageki;            // offset 0x416, size 0x2
    s16 utk_nage;              // offset 0x418, size 0x2
    s16 utk_kizetsu;           // offset 0x41A, size 0x2
    u8 atemi_flag;             // offset 0x41C, size 0x1
    u8 atemi_point;            // offset 0x41D, size 0x1
    s16 dm_vital_backup;       // offset 0x41E, size 0x2
    u8 dm_refrect;             // offset 0x420, size 0x1
    u8 dm_vital_use;           // offset 0x421, size 0x1
    u8 exdm_ix;                // offset 0x422, size 0x1
    u8 meoshi_jump_flag;       // offset 0x423, size 0x1
    s16 cmd_request;           // offset 0x424, size 0x2
    s16 rl_save;               // offset 0x426, size 0x2
    u8 zettai_muteki_flag;     // offset 0x428, size 0x1
    u8 do_not_move;            // offset 0x429, size 0x1
    u16 just_sa_stop_timer;    // offset 0x42A, size 0x2
    s16 total_att_hit_ok;      // offset 0x42C, size 0x2
    u8 sa_healing;             // offset 0x42E, size 0x1
    u8 auto_guard;             // offset 0x42F, size 0x1
    u8 hsjp_ok;                // offset 0x430, size 0x1
    u8 high_jump_flag;         // offset 0x431, size 0x1
    s16 att_plus;              // offset 0x432, size 0x2
    s16 def_plus;              // offset 0x434, size 0x2
    s8 bs2_on_car;             // offset 0x436, size 0x1
    s8 bs2_area_car;           // offset 0x437, size 0x1
    s8 bs2_over_car;           // offset 0x438, size 0x1
    s8 bs2_area_car2;          // offset 0x439, size 0x1
    s8 bs2_over_car2;          // offset 0x43A, size 0x1
    u8 micchaku_wall_time;     // offset 0x43B, size 0x1
    u8 extra_jump;             // offset 0x43C, size 0x1
    u8 air_jump_ok_time;       // offset 0x43D, size 0x1
    s16 waku_ram_index;        // offset 0x43E, size 0x2
    u16 permited_koa;          // offset 0x440, size 0x2
    u8 ja_nmj_rno;             // offset 0x442, size 0x1
    u8 ja_nmj_cnt;             // offset 0x443, size 0x1
    u8 kind_of_blocking;       // offset 0x444, size 0x1
    u8 metamorphose;           // offset 0x445, size 0x1
    s16 metamor_index;         // offset 0x446, size 0x2
    u8 metamor_over;           // offset 0x448, size 0x1
    u8 gill_ccch_go;           // offset 0x449, size 0x1
    u8 renew_attchar;          // offset 0x44A, size 0x1
    s16 omop_vital_timer;      // offset 0x44C, size 0x2
    s16 sfwing_pos;            // offset 0x44E, size 0x2
    u8 init_E3_flag;           // offset 0x450, size 0x1
    u8 init_E4_flag;           // offset 0x451, size 0x1
    u16 pl09_dat_index;        // offset 0x452, size 0x2
    s16 reserv_add_y;          // offset 0x454, size 0x2
    u8 pt_free[20];            // offset 0x456, size 0x14
} PLW;

typedef struct {
    WORK wu;             // offset 0x0, size 0x388
    u32 *my_master;      // offset 0x388, size 0x4
    s16 master_work_id;  // offset 0x38C, size 0x2
    s16 master_id;       // offset 0x38E, size 0x2
    s16 master_player;   // offset 0x390, size 0x2
    s16 master_priority; // offset 0x392, size 0x2
    u8 dm_refrect;       // offset 0x394, size 0x1
    u8 refrected;        // offset 0x395, size 0x1
    s16 free;            // offset 0x396, size 0x2
    u32 master_ng_flag;  // offset 0x398, size 0x4
    u32 master_ng_flag2; // offset 0x39C, size 0x4
    u8 et_free[30];      // offset 0x3A0, size 0x1E
} WORK_Other;

typedef struct {
    // total size: 0x470
    u32 VideoMode;              // offset 0x0, size 0x4
    u32 InterlaceMode;          // offset 0x4, size 0x4
    u32 DisplayMode;            // offset 0x8, size 0x4
    s32 DispWidth;              // offset 0xC, size 0x4
    s32 DispHeight;             // offset 0x10, size 0x4
    u32 MAGH;                   // offset 0x14, size 0x4
    u32 FrameBitDepth;          // offset 0x18, size 0x4
    u32 FrameBuffForm;          // offset 0x1C, size 0x4
    u32 FrameBuffPageX;         // offset 0x20, size 0x4
    u32 FrameBuffPageY;         // offset 0x24, size 0x4
    u32 FrameBuffAdrs0;         // offset 0x28, size 0x4
    u32 FrameBuffAdrs1;         // offset 0x2C, size 0x4
    u32 ZBuffBitDepth;          // offset 0x30, size 0x4
    u32 ZBuffForm;              // offset 0x34, size 0x4
    u32 ZBuffPageX;             // offset 0x38, size 0x4
    u32 ZBuffPageY;             // offset 0x3C, size 0x4
    u32 ZBuffAdrs;              // offset 0x40, size 0x4
    f32 ZBuffMax;               // offset 0x44, size 0x4
    u32 TextureStartAdrs;       // offset 0x48, size 0x4
    s32 Oddeven;                // offset 0x4C, size 0x4
    s32 Dbi;                    // offset 0x50, size 0x4
    s32 FrameCount;             // offset 0x54, size 0x4
    s32 FrameCountNext;         // offset 0x58, size 0x4
    s32 Irq_count;              // offset 0x5C, size 0x4
    s32 Db_change_enable;       // offset 0x60, size 0x4
    s8 pad64[0xC];              // offset 0x64, size 0xC
    sceGsDBuffDc Db;            // offset 0x70, size 0x330
    u32 FrameClearColor;        // offset 0x3A0, size 0x4
    s32 D2dOffsetX;             // offset 0x3A4, size 0x4
    s32 D2dOffsetY;             // offset 0x3A8, size 0x4
    s32 ScreenOffsetX;          // offset 0x3AC, size 0x4
    s32 ScreenOffsetY;          // offset 0x3B0, size 0x4
    s32 ScreenDispX;            // offset 0x3B4, size 0x4
    s32 ScreenDispY;            // offset 0x3B8, size 0x4
    s32 ScreenAdjustX;          // offset 0x3BC, size 0x4
    s32 ScreenAdjustY;          // offset 0x3C0, size 0x4
    sceDmaChan *DmaChan[10];    // offset 0x3C4, size 0x28
    s32 NowVu1Code;             // offset 0x3EC, size 0x4
    s32 NowVu1Size;             // offset 0x3F0, size 0x4
    s32 DrawDisable;            // offset 0x3F4, size 0x4
    u32 system_memory_start;    // offset 0x3F8, size 0x4
    s32 system_memory_size;     // offset 0x3FC, size 0x4
    u32 SystemStatus;           // offset 0x400, size 0x4
    s32 SystemIndex;            // offset 0x404, size 0x4
    u32 SystemTmpBuffStartAdrs; // offset 0x408, size 0x4
    u32 SystemTmpBuffEndAdrs;   // offset 0x40C, size 0x4
    u32 SystemTmpBuffNow;       // offset 0x410, size 0x4
    u32 SystemTmpBuffHandle[2]; // offset 0x414, size 0x8
    u64 RenderTESTStatus1;      // offset 0x420, size 0x4
    u64 RenderTESTStatus2;      // offset 0x428, size 0x4
    u64 RenderZBUFStatus1;      // offset 0x430, size 0x4
    u64 RenderZBUFStatus2;      // offset 0x438, size 0x4
    u64 RenderSCISSORStatus1;   // offset 0x440, size 0x4
    s32 RenderSCISSORValue1[4]; // offset 0x448, size 0x10
    u64 RenderSCISSORStatus2;   // offset 0x458, size 0x4
    s32 RenderSCISSORValue2[4]; // offset 0x460, size 0x10
} FLPS2State;

typedef struct {
    // total size: 0x3C
    u32 channel_id;             // offset 0x0, size 0x4
    u32 queue_size;             // offset 0x4, size 0x4
    s32 handleID;               // offset 0x8, size 0x4
    u32 dma_queue_handle[2];    // offset 0xC, size 0x8
    u32 queue_ctr[2];           // offset 0x14, size 0x8
    u32 queue_ptr0[2];          // offset 0x1C, size 0x8
    u32 queue_ptr1[2];          // offset 0x24, size 0x8
    u32 now_adrs;               // offset 0x2C, size 0x4
    u32 dma_normal_mode_status; // offset 0x30, size 0x4
    u32 old_queue_data;         // offset 0x34, size 0x4
    u32 old_endtag;             // offset 0x38, size 0x4
} FLPS2VIF1Control;

typedef union {
    __int128 I128;  // offset 0x0, size 0x10
    s64 I64[2];     // offset 0x0, size 0x10
    s32 I32[4];     // offset 0x0, size 0x10
    s16 I16[8];     // offset 0x0, size 0x10
    s8 I8[16];      // offset 0x0, size 0x10
    __int128 UI128; // offset 0x0, size 0x10
    u64 UI64[2];    // offset 0x0, size 0x10
    u32 UI32[4];    // offset 0x0, size 0x10
    u16 UI16[8];    // offset 0x0, size 0x10
    u8 UI8[16];     // offset 0x0, size 0x10
    f32 F32[4];     // offset 0x0, size 0x10
    f64 F64[2];     // offset 0x0, size 0x10
} QWORD;

typedef struct {
    // total size: 0xA0
    QWORD dmatag;     // offset 0x0, size 0x10
    QWORD giftag;     // offset 0x10, size 0x10
    QWORD frame_1;    // offset 0x20, size 0x10
    QWORD frame_2;    // offset 0x30, size 0x10
    QWORD zbuf_1;     // offset 0x40, size 0x10
    QWORD zbuf_2;     // offset 0x50, size 0x10
    QWORD xyoffset_1; // offset 0x60, size 0x10
    QWORD xyoffset_2; // offset 0x70, size 0x10
    QWORD dthe;       // offset 0x80, size 0x10
    QWORD colclamp;   // offset 0x90, size 0x10
} FLPS2DB;

typedef struct {
    // total size: 0x140
    QWORD dmatag;         // offset 0x0, size 0x10
    QWORD giftag;         // offset 0x10, size 0x10
    QWORD clr_fba;        // offset 0x20, size 0x10
    QWORD clr_scissor;    // offset 0x30, size 0x10
    QWORD clr_test;       // offset 0x40, size 0x10
    QWORD clr_prim;       // offset 0x50, size 0x10
    QWORD clr_rgbaq;      // offset 0x60, size 0x10
    QWORD clr_xyz2_0;     // offset 0x70, size 0x10
    QWORD clr_xyz2_1;     // offset 0x80, size 0x10
    QWORD acr_scissor_1;  // offset 0x90, size 0x10
    QWORD acr_scissor_2;  // offset 0xA0, size 0x10
    QWORD acr_test_1;     // offset 0xB0, size 0x10
    QWORD acr_test_2;     // offset 0xC0, size 0x10
    QWORD acr_zbuf_1;     // offset 0xD0, size 0x10
    QWORD acr_zbuf_2;     // offset 0xE0, size 0x10
    QWORD acr_fba_1;      // offset 0xF0, size 0x10
    QWORD acr_fba_2;      // offset 0x100, size 0x10
    QWORD acr_pabe;       // offset 0x110, size 0x10
    QWORD acr_prmodecont; // offset 0x120, size 0x10
    QWORD acr_dimx;       // offset 0x130, size 0x10
} FLPS2DrawStart;

enum _FLSETRENDERSTATE {
    FLRENDER_CULL = 0,
    FLRENDER_LIGHTING = 1,
    FLRENDER_SPECULAR = 2,
    FLRENDER_WRAP = 3,
    FLRENDER_TEXSTAGE0 = 4,
    FLRENDER_TEXSTAGE1 = 5,
    FLRENDER_TEXSTAGE2 = 6,
    FLRENDER_TEXSTAGE3 = 7,
    FLRENDER_TEXOPE0 = 8,
    FLRENDER_TEXOPE1 = 9,
    FLRENDER_TEXOPE2 = 10,
    FLRENDER_TEXOPE3 = 11,
    FLRENDER_SCISSOR = 12,
    FLRENDER_BLENDOPE = 13,
    FLRENDER_AMBIENT = 14,
    FLRENDER_FOGCOLOR = 15,
    FLRENDER_FOGSTART = 16,
    FLRENDER_FOGEND = 17,
    FLRENDER_FOGENABLE = 18,
    FLRENDER_FLIP = 19,
    FLRENDER_BACKCOLOR = 20,
    FLRENDER_MATERIAL = 21,
    FLRENDER_VIEW = 22,
    FLRENDER_PROJ = 23,
    FLRENDER_VIEWPORT = 24,
    FLRENDER_UVSCRMATRIX = 25,
    FLRENDER_WORLD0 = 26,
    FLRENDER_WORLD1 = 27,
    FLRENDER_WORLD2 = 28,
    FLRENDER_WORLD3 = 29,
    FLRENDER_WORLD4 = 30,
    FLRENDER_WORLD5 = 31,
    FLRENDER_WORLD6 = 32,
    FLRENDER_WORLD7 = 33,
    FLRENDER_WORLD8 = 34,
    FLRENDER_WORLD9 = 35,
    FLRENDER_WORLD10 = 36,
    FLRENDER_WORLD11 = 37,
    FLRENDER_WORLD12 = 38,
    FLRENDER_WORLD13 = 39,
    FLRENDER_WORLD14 = 40,
    FLRENDER_WORLD15 = 41,
    FLRENDER_WORLD16 = 42,
    FLRENDER_WORLD17 = 43,
    FLRENDER_WORLD18 = 44,
    FLRENDER_WORLD19 = 45,
    FLRENDER_WORLD20 = 46,
    FLRENDER_WORLD21 = 47,
    FLRENDER_WORLD22 = 48,
    FLRENDER_WORLD23 = 49,
    FLRENDER_WORLD24 = 50,
    FLRENDER_WORLD25 = 51,
    FLRENDER_WORLD26 = 52,
    FLRENDER_WORLD27 = 53,
    FLRENDER_WORLD28 = 54,
    FLRENDER_WORLD29 = 55,
    FLRENDER_WORLD30 = 56,
    FLRENDER_WORLD31 = 57,
    FLRENDER_MATERIAL0 = 58,
    FLRENDER_MATERIAL1 = 59,
    FLRENDER_MATERIAL2 = 60,
    FLRENDER_MATERIAL3 = 61,
    FLRENDER_MATERIAL4 = 62,
    FLRENDER_MATERIAL5 = 63,
    FLRENDER_MATERIAL6 = 64,
    FLRENDER_MATERIAL7 = 65,
    FLRENDER_MATERIAL8 = 66,
    FLRENDER_MATERIAL9 = 67,
    FLRENDER_MATERIAL10 = 68,
    FLRENDER_MATERIAL11 = 69,
    FLRENDER_MATERIAL12 = 70,
    FLRENDER_MATERIAL13 = 71,
    FLRENDER_MATERIAL14 = 72,
    FLRENDER_MATERIAL15 = 73,
    FLRENDER_MATERIAL16 = 74,
    FLRENDER_MATERIAL17 = 75,
    FLRENDER_MATERIAL18 = 76,
    FLRENDER_MATERIAL19 = 77,
    FLRENDER_MATERIAL20 = 78,
    FLRENDER_MATERIAL21 = 79,
    FLRENDER_MATERIAL22 = 80,
    FLRENDER_MATERIAL23 = 81,
    FLRENDER_MATERIAL24 = 82,
    FLRENDER_MATERIAL25 = 83,
    FLRENDER_MATERIAL26 = 84,
    FLRENDER_MATERIAL27 = 85,
    FLRENDER_MATERIAL28 = 86,
    FLRENDER_MATERIAL29 = 87,
    FLRENDER_MATERIAL30 = 88,
    FLRENDER_MATERIAL31 = 89,
    FLRENDER_LIGHT0 = 90,
    FLRENDER_LIGHT1 = 91,
    FLRENDER_LIGHT2 = 92,
    FLRENDER_SHADER = 93,
    FLRENDER_ALPHABLENDMODE = 94,
    FLRENDER_ALPHATEST = 95,
    FLRENDER_ALPHAREF = 96,
    FLRENDER_ALPHABLENDENABLE = 97,
    FLRENDER_UVSCROLL = 98,
    FLRENDER_TEXTUREFILTER = 99,
    FLRENDER_TEXTUREADDRESSING = 100,
    FLRENDER_RENDERTARGET = 101,
    FLRENDER_FADECOLORENABLE = 102,
    FLRENDER_FADECOLOR = 103,
    FLRENDER_MIPMAPBIAS = 104,
    FLRENDER_MIPMAPARG1 = 105,
    FLRENDER_MIPMAPARG2 = 106,
    FLRENDER_MIPMAPFILTER = 107,
    FLRENDER_ZWRITE = 108,
    FLRENDER_ZOPE = 109,
};

struct _MEMMAN_CELL {
    // total size: 0xC
    struct _MEMMAN_CELL *prev; // offset 0x0, size 0x4
    struct _MEMMAN_CELL *next; // offset 0x4, size 0x4
    s32 size;                  // offset 0x8, size 0x4
};

typedef struct {
    // total size: 0x2C
    u8 *memHead;                   // offset 0x0, size 0x4
    s32 memSize;                   // offset 0x4, size 0x4
    u32 ownNumber;                 // offset 0x8, size 0x4
    s32 ownUnit;                   // offset 0xC, size 0x4
    s32 remainder;                 // offset 0x10, size 0x4
    s32 remainderMin;              // offset 0x14, size 0x4
    struct _MEMMAN_CELL *cell_1st; // offset 0x18, size 0x4
    struct _MEMMAN_CELL *cell_fin; // offset 0x1C, size 0x4
    u8 *oriHead;                   // offset 0x20, size 0x4
    s32 oriSize;                   // offset 0x24, size 0x4
    s32 debIndex;                  // offset 0x28, size 0x4
} _MEMMAN_OBJ;

typedef struct {
    // total size: 0x90
    s8 be_flag;        // offset 0x0, size 0x1
    s8 disp_flag;      // offset 0x1, size 0x1
    s16 fam_no;        // offset 0x2, size 0x2
    s16 r_no_0;        // offset 0x4, size 0x2
    s16 r_no_1;        // offset 0x6, size 0x2
    s16 r_no_2;        // offset 0x8, size 0x2
    s16 position_x;    // offset 0xA, size 0x2
    s16 position_y;    // offset 0xC, size 0x2
    s32 speed_x;       // offset 0x10, size 0x4
    s32 speed_y;       // offset 0x14, size 0x4
    XY xy[2];          // offset 0x18, size 0x8
    XY wxy[2];         // offset 0x20, size 0x8
    u16 *bg_address;   // offset 0x28, size 0x4
    u16 *suzi_adrs;    // offset 0x2C, size 0x4
    s16 old_pos_x;     // offset 0x30, size 0x2
    s32 zuubun;        // offset 0x34, size 0x4
    s16 no_suzi_line;  // offset 0x38, size 0x2
    u16 *start_suzi;   // offset 0x3C, size 0x4
    s16 u_line;        // offset 0x40, size 0x2
    s16 d_line;        // offset 0x42, size 0x2
    s16 bg_adrs_c_no;  // offset 0x44, size 0x2
    s16 suzi_c_no;     // offset 0x46, size 0x2
    s16 pos_x_work;    // offset 0x48, size 0x2
    s16 pos_y_work;    // offset 0x4A, size 0x2
    s8 rewrite_flag;   // offset 0x4C, size 0x1
    s8 suzi_base_flag; // offset 0x4D, size 0x1
    XY hos_xy[2];      // offset 0x50, size 0x8
    XY chase_xy[2];    // offset 0x58, size 0x8
    s16 free;          // offset 0x60, size 0x2
    s16 frame_deff;    // offset 0x62, size 0x2
    s16 r_limit;       // offset 0x64, size 0x2
    s16 r_limit2;      // offset 0x66, size 0x2
    s16 l_limit;       // offset 0x68, size 0x2
    s16 l_limit2;      // offset 0x6A, size 0x2
    s16 y_limit;       // offset 0x6C, size 0x2
    s16 y_limit2;      // offset 0x6E, size 0x2
    u16 *suzi_adrs2;   // offset 0x70, size 0x4
    u16 *start_suzi2;  // offset 0x74, size 0x4
    s16 suzi_c_no2;    // offset 0x78, size 0x2
    s32 max_x_limit;   // offset 0x7C, size 0x4
    s16 *deff_rl;      // offset 0x80, size 0x4
    s16 *deff_plus;    // offset 0x84, size 0x4
    s16 *deff_minus;   // offset 0x88, size 0x4
    s16 abs_x;         // offset 0x8C, size 0x2
    s16 abs_y;         // offset 0x8E, size 0x2
} BGW;

typedef struct {
    // total size: 0x428
    s8 bg_routine;     // offset 0x0, size 0x1
    s8 bg_r_1;         // offset 0x1, size 0x1
    s8 bg_r_2;         // offset 0x2, size 0x1
    s8 stage;          // offset 0x3, size 0x1
    s8 area;           // offset 0x4, size 0x1
    s8 compel_flag;    // offset 0x5, size 0x1
    s32 scroll_cg_adr; // offset 0x8, size 0x4
    s32 ake_cg_adr;    // offset 0xC, size 0x4
    u8 scno;           // offset 0x10, size 0x1
    u8 scrno;          // offset 0x11, size 0x1
    s16 bg2_sp_x;      // offset 0x12, size 0x2
    s16 bg2_sp_y;      // offset 0x14, size 0x2
    s16 scr_stop;      // offset 0x16, size 0x2
    s8 frame_flag;     // offset 0x18, size 0x1
    s8 chase_flag;     // offset 0x19, size 0x1
    s8 old_chase_flag; // offset 0x1A, size 0x1
    s8 old_frame_flag; // offset 0x1B, size 0x1
    s16 pos_offset;    // offset 0x1C, size 0x2
    s16 quake_x_index; // offset 0x1E, size 0x2
    s16 quake_y_index; // offset 0x20, size 0x2
    s16 bg_f_x;        // offset 0x22, size 0x2
    s16 bg_f_y;        // offset 0x24, size 0x2
    s16 bg2_sp_x2;     // offset 0x26, size 0x2
    s16 bg2_sp_y2;     // offset 0x28, size 0x2
    s16 frame_deff;    // offset 0x2A, size 0x2
    s16 center_x;      // offset 0x2C, size 0x2
    s16 center_y;      // offset 0x2E, size 0x2
    s16 bg_index;      // offset 0x30, size 0x2
    s8 frame_vol;      // offset 0x32, size 0x1
    s16 max_x;         // offset 0x34, size 0x2
    u8 bg_opaque;      // offset 0x36, size 0x1
    BGW bgw[7];        // offset 0x38, size 0x3F0
} BG;

typedef struct {
    // total size: 0x18
    u8 *memoryblock;   // offset 0x0, size 0x4
    u8 *baseandcap[2]; // offset 0x4, size 0x8
    u8 *frame[2];      // offset 0xC, size 0x8
    s32 align;         // offset 0x14, size 0x4
} FL_FMS;

typedef union {
    u32 etc; // offset 0x0, size 0x4
    struct /* @anon1 */ {
        // total size: 0x4
        u8 vib;  // offset 0x0, size 0x1
        u8 etc0; // offset 0x1, size 0x1
        u8 etc1; // offset 0x2, size 0x1
        u8 etc2; // offset 0x3, size 0x1
    } gc;        // offset 0x0, size 0x4
    struct /* @anon4 */ {
        // total size: 0x4
        u8 port; // offset 0x0, size 0x1
        u8 slot; // offset 0x1, size 0x1
        u8 vib;  // offset 0x2, size 0x1
        u8 etc;  // offset 0x3, size 0x1
    } ps;        // offset 0x0, size 0x4
    struct /* @anon6 */ {
        // total size: 0x4
        u8 socket1; // offset 0x0, size 0x1
        u8 socket2; // offset 0x1, size 0x1
        u16 etc;    // offset 0x2, size 0x2
    } dc;           // offset 0x0, size 0x4
    struct /* @anon8 */ {
        // total size: 0x4
        void *handle; // offset 0x0, size 0x4
    } xbox;           // offset 0x0, size 0x4
} PAD_CONN;

typedef struct {
    // total size: 0x10
    u8 pow[16]; // offset 0x0, size 0x10
} PAD_ANSHOT;

typedef struct {
    // total size: 0x88
    u8 state;           // offset 0x0, size 0x1
    u8 anstate;         // offset 0x1, size 0x1
    u16 kind;           // offset 0x2, size 0x2
    PAD_CONN conn;      // offset 0x4, size 0x4
    u32 sw;             // offset 0x8, size 0x4
    u32 sw_old;         // offset 0xC, size 0x4
    u32 sw_new;         // offset 0x10, size 0x4
    u32 sw_off;         // offset 0x14, size 0x4
    u32 sw_chg;         // offset 0x18, size 0x4
    PAD_ANSHOT anshot;  // offset 0x1C, size 0x10
    PAD_STICK stick[2]; // offset 0x2C, size 0x18
    u32 sw_repeat;      // offset 0x44, size 0x4
    union /* @anon9 */ {
        u16 work; // offset 0x0, size 0x2
        struct /* @anon10 */ {
            // total size: 0x2
            u8 press; // offset 0x0, size 0x1
            u8 sw_up; // offset 0x1, size 0x1
        } ctr;        // offset 0x0, size 0x2
    } rpsw[32];       // offset 0x48, size 0x40
} FLPAD;

typedef struct {
    // total size: 0x34
    u8 state;           // offset 0x0, size 0x1
    u8 anstate;         // offset 0x1, size 0x1
    u16 kind;           // offset 0x2, size 0x2
    PAD_CONN conn;      // offset 0x4, size 0x4
    u32 sw;             // offset 0x8, size 0x4
    PAD_ANSHOT anshot;  // offset 0xC, size 0x10
    PAD_STICK stick[2]; // offset 0x1C, size 0x18
} TARPAD;

typedef struct {
    // total size: 0x2C
    u8 conf_sw[32]; // offset 0x0, size 0x20
    u8 flip_lever;  // offset 0x20, size 0x1
    u8 flip_ast1;   // offset 0x21, size 0x1
    u8 flip_ast2;   // offset 0x22, size 0x1
    u8 free;        // offset 0x23, size 0x1
    s16 abut_on;    // offset 0x24, size 0x2
    s16 ast1_on;    // offset 0x26, size 0x2
    s16 ast2_on;    // offset 0x28, size 0x2
    u16 free2;      // offset 0x2A, size 0x2
} FLPAD_CONFIG;

typedef struct {
    // total size: 0x8
    s16 abut_on; // offset 0x0, size 0x2
    s16 ast1_on; // offset 0x2, size 0x2
    s16 ast2_on; // offset 0x4, size 0x2
    u16 free;    // offset 0x6, size 0x2
} PS2PAD_CONFIG;

typedef union {
    u8 pad_buffer[32]; // offset 0x0, size 0x20
    struct {
        // total size: 0x20
        u8 ng;   // offset 0x0, size 0x1
        u8 kind; // offset 0x1, size 0x1
        u16 sw;  // offset 0x2, size 0x2
        union {
            struct /* @anon7 */ {
                // total size: 0x4
                s16 x; // offset 0x0, size 0x2
                s16 y; // offset 0x2, size 0x2
            } gun;     // offset 0x0, size 0x4
            struct {
                // total size: 0x4
                u8 r_ax; // offset 0x0, size 0x1
                u8 r_ay; // offset 0x1, size 0x1
                u8 l_ax; // offset 0x2, size 0x1
                u8 l_ay; // offset 0x3, size 0x1
            } stick;     // offset 0x0, size 0x4
        } pos;           // offset 0x4, size 0x4
        u8 depth[12];    // offset 0x8, size 0xC
        u8 free[12];     // offset 0x14, size 0xC
    } ix;                // offset 0x0, size 0x20
} PS2PAD_STATE;

typedef struct {
    // total size: 0xC
    u8 order;    // offset 0x0, size 0x1
    u8 kind_req; // offset 0x1, size 0x1
    u8 kind_cnt; // offset 0x2, size 0x1
    u8 request;  // offset 0x3, size 0x1
    u8 contents; // offset 0x4, size 0x1
    u8 timer;    // offset 0x5, size 0x1
    s16 pos_x;   // offset 0x6, size 0x2
    s16 pos_y;   // offset 0x8, size 0x2
    s16 pos_z;   // offset 0xA, size 0x2
} MessageData;

typedef struct {
    // total size: 0x48
    s8 contents[10][7]; // offset 0x0, size 0x46
    u16 sum;            // offset 0x46, size 0x2
} SystemDir;

typedef struct {
    // total size: 0xC
    u8 Shot[8];   // offset 0x0, size 0x8
    u8 Vibration; // offset 0x8, size 0x1
    u8 free[3];   // offset 0x9, size 0x3
} _PAD_INFOR;

typedef struct {
    // total size: 0x20
    s8 contents[4][8]; // offset 0x0, size 0x20
} _EXTRA_OPTION;

typedef struct {
    // total size: 0x14
    u8 name[3];      // offset 0x0, size 0x3
    u16 player;      // offset 0x4, size 0x2
    u32 score;       // offset 0x8, size 0x4
    s8 cpu_grade;    // offset 0xC, size 0x1
    s8 grade;        // offset 0xD, size 0x1
    u16 wins;        // offset 0xE, size 0x2
    u8 player_color; // offset 0x10, size 0x1
    u8 all_clear;    // offset 0x11, size 0x1
} RANK_DATA;

struct _SAVE_W {
    // total size: 0x208
    _PAD_INFOR Pad_Infor[2];    // offset 0x0, size 0x18
    u8 Difficulty;              // offset 0x18, size 0x1
    s8 Time_Limit;              // offset 0x19, size 0x1
    u8 Battle_Number[2];        // offset 0x1A, size 0x2
    u8 Damage_Level;            // offset 0x1C, size 0x1
    u8 Handicap;                // offset 0x1D, size 0x1
    u8 Partner_Type[2];         // offset 0x1E, size 0x2
    s8 Adjust_X;                // offset 0x20, size 0x1
    s8 Adjust_Y;                // offset 0x21, size 0x1
    u8 Screen_Size;             // offset 0x22, size 0x1
    u8 Screen_Mode;             // offset 0x23, size 0x1
    u8 GuardCheck;              // offset 0x24, size 0x1
    u8 Auto_Save;               // offset 0x25, size 0x1
    u8 AnalogStick;             // offset 0x26, size 0x1
    u8 BgmType;                 // offset 0x27, size 0x1
    u8 SoundMode;               // offset 0x28, size 0x1
    u8 BGM_Level;               // offset 0x29, size 0x1
    u8 SE_Level;                // offset 0x2A, size 0x1
    u8 Extra_Option;            // offset 0x2B, size 0x1
    u8 PL_Color[2][20];         // offset 0x2C, size 0x28
    _EXTRA_OPTION extra_option; // offset 0x54, size 0x20
    RANK_DATA Ranking[20];      // offset 0x74, size 0x190
    u32 sum;                    // offset 0x204, size 0x4
};

typedef struct {
    // total size: 0x8
    u8 ***msgAdr; // offset 0x0, size 0x4
    s8 *msgNum;   // offset 0x4, size 0x4
} MessageTable;

struct _player_infor {
    // total size: 0x4
    u8 my_char;     // offset 0x0, size 0x1
    s8 sa;          // offset 0x1, size 0x1
    s8 color;       // offset 0x2, size 0x1
    s8 player_type; // offset 0x3, size 0x1
};

struct _REP_GAME_INFOR {
    // total size: 0x24
    struct _player_infor player_infor[2]; // offset 0x0, size 0x8
    s8 stage;                             // offset 0x8, size 0x1
    s8 Direction_Working;                 // offset 0x9, size 0x1
    s8 Vital_Handicap[2];                 // offset 0xA, size 0x2
    s16 Random_ix16;                      // offset 0xC, size 0x2
    s16 Random_ix32;                      // offset 0xE, size 0x2
    s16 Random_ix16_ex;                   // offset 0x10, size 0x2
    s16 Random_ix32_ex;                   // offset 0x12, size 0x2
    s8 *fname;                            // offset 0x14, size 0x4
    u8 winner;                            // offset 0x18, size 0x1
    u8 play_type;                         // offset 0x19, size 0x1
    u16 players_timer;                    // offset 0x1A, size 0x2
    s16 old_mes_no2;                      // offset 0x1C, size 0x2
    s16 old_mes_no3;                      // offset 0x1E, size 0x2
    s16 old_mes_no_pl;                    // offset 0x20, size 0x2
    s16 mes_already;                      // offset 0x22, size 0x2
};

struct _MINI_SAVE_W {
    // total size: 0x3C
    _PAD_INFOR Pad_Infor[2];    // offset 0x0, size 0x18
    s8 Time_Limit;              // offset 0x18, size 0x1
    u8 Battle_Number[2];        // offset 0x19, size 0x2
    u8 Damage_Level;            // offset 0x1B, size 0x1
    _EXTRA_OPTION extra_option; // offset 0x1C, size 0x20
};

typedef struct {
    // total size: 0x48
    u8 Handle_1P[18];   // offset 0x0, size 0x12
    u8 Id_1P[8];        // offset 0x12, size 0x8
    u8 Handle_2P[18];   // offset 0x1A, size 0x12
    u8 Id_2P[8];        // offset 0x2C, size 0x8
    u8 Serial_No[6];    // offset 0x34, size 0x6
    u8 Battle_Code[14]; // offset 0x3A, size 0xE
} _NET_INFOR;

typedef struct {
    // total size: 0x7448
    u8 header[640];                    // offset 0x0, size 0x280
    u8 sega_reserve[64];               // offset 0x280, size 0x40
    s16 Control_Time_Buff;             // offset 0x2C0, size 0x2
    u8 Difficulty;                     // offset 0x2C2, size 0x1
    u8 Monitor_Type;                   // offset 0x2C3, size 0x1
    u8 free_free[4];                   // offset 0x2C4, size 0x4
    struct _REP_GAME_INFOR game_infor; // offset 0x2C8, size 0x24
    struct _MINI_SAVE_W mini_save_w;   // offset 0x2EC, size 0x3C
    SystemDir system_dir;              // offset 0x328, size 0x48
    _NET_INFOR net_infor;              // offset 0x370, size 0x48
    struct {
        // total size: 0x7078
        u16 key_buff[2][7198]; // offset 0x0, size 0x7078
    } io_unit;                 // offset 0x3B8, size 0x7078
    u8 lag[14];                // offset 0x7430, size 0xE
    u32 sum;                   // offset 0x7440, size 0x4
    u8 champion;               // offset 0x7444, size 0x1
    u8 full_data;              // offset 0x7445, size 0x1
    u8 free;                   // offset 0x7446, size 0x1
    u8 extra_free;             // offset 0x7447, size 0x1
} _REPLAY_W;

struct _VM_W {
    // total size: 0x6C
    u8 r_no[4];     // offset 0x0, size 0x4
    u8 r_sub[4];    // offset 0x4, size 0x4
    s32 Timer;      // offset 0x8, size 0x4
    s32 FreeMem[2]; // offset 0xC, size 0x8
    s8 Format[2];   // offset 0x14, size 0x2
    s8 Find[2];     // offset 0x16, size 0x2
    s8 Connect[2];  // offset 0x18, size 0x2
    s8 CheckDrive;  // offset 0x1A, size 0x1
    s8 AutoDrive;   // offset 0x1B, size 0x1
    s8 Drive;       // offset 0x1C, size 0x1
    s8 Access;      // offset 0x1D, size 0x1
    s8 Request;     // offset 0x1E, size 0x1
    s8 AutoLoaded;  // offset 0x1F, size 0x1
    struct {
        // total size: 0x8
        u16 year;      // offset 0x0, size 0x2
        u8 month;      // offset 0x2, size 0x1
        u8 day;        // offset 0x3, size 0x1
        u8 hour;       // offset 0x4, size 0x1
        u8 minute;     // offset 0x5, size 0x1
        u8 second;     // offset 0x6, size 0x1
        u8 dayofweek;  // offset 0x7, size 0x1
    } curTime[2];      // offset 0x20, size 0x10
    s32 curSize[2];    // offset 0x30, size 0x8
    s16 memKey;        // offset 0x38, size 0x2
    u8 *memAdr;        // offset 0x3C, size 0x4
    s32 nowResult;     // offset 0x40, size 0x4
    s32 nowNumber;     // offset 0x44, size 0x4
    s32 polResult;     // offset 0x48, size 0x4
    s32 polNumber;     // offset 0x4C, size 0x4
    u8 File_Type;      // offset 0x50, size 0x1
    u8 *File_Name;     // offset 0x54, size 0x4
    u32 Save_Size;     // offset 0x58, size 0x4
    u16 Block_Size;    // offset 0x5C, size 0x2
    u8 Icon_Type;      // offset 0x5E, size 0x1
    u8 Comment_Type;   // offset 0x5F, size 0x1
    u8 Target_Number;  // offset 0x60, size 0x1
    u8 Number;         // offset 0x61, size 0x1
    u8 Counter;        // offset 0x62, size 0x1
    u8 Save_Type;      // offset 0x63, size 0x1
    s8 New_File;       // offset 0x64, size 0x1
    s8 Header_Counter; // offset 0x65, size 0x1
    s8 padding[3];     // offset 0x66, size 0x3
};

typedef struct {
    // total size: 0x34
    u8 ok_dev; // offset 0x0, size 0x1
    u8 id;     // offset 0x1, size 0x1
    u8 opck;   // offset 0x2, size 0x1
    u8 psix;   // offset 0x3, size 0x1
    s16 vital; // offset 0x4, size 0x2
    u8 inStop; // offset 0x6, size 0x1
    u8 free;   // offset 0x7, size 0x1
    u32 port;  // offset 0x8, size 0x4
    struct /* @anon4 */ {
        // total size: 0x14
        u8 ppnew;   // offset 0x0, size 0x1
        u8 free;    // offset 0x1, size 0x1
        s16 data;   // offset 0x2, size 0x2
        s16 rno[4]; // offset 0x4, size 0x8
        s16 life;   // offset 0xC, size 0x2
        s16 exix;   // offset 0xE, size 0x2
        struct /* @anon14 */ {
            // total size: 0x4
            s16 ix;    // offset 0x0, size 0x2
            s16 timer; // offset 0x2, size 0x2
        } *padr;       // offset 0x10, size 0x4
    } p[2];            // offset 0xC, size 0x28
} PPWORK;

typedef struct {
    // total size: 0x8
    s16 x; // offset 0x0, size 0x2
    s16 y; // offset 0x2, size 0x2
    u32 c; // offset 0x4, size 0x4
} Pixel;

typedef struct {
    // total size: 0xC
    f32 x; // offset 0x0, size 0x4
    f32 y; // offset 0x4, size 0x4
    f32 z; // offset 0x8, size 0x4
} Vec3;

typedef struct {
    // total size: 0x10
    f32 x; // offset 0x0, size 0x4
    f32 y; // offset 0x4, size 0x4
    f32 z; // offset 0x8, size 0x4
    f32 w; // offset 0xC, size 0x4
} Vec4;

typedef struct {
    // total size: 0x8
    s16 x1; // offset 0x0, size 0x2
    s16 y1; // offset 0x2, size 0x2
    s16 x2; // offset 0x4, size 0x2
    s16 y2; // offset 0x6, size 0x2
} Rect;

typedef struct {
    // total size: 0x40
    f32 _11; // offset 0x0, size 0x4
    f32 _12; // offset 0x4, size 0x4
    f32 _13; // offset 0x8, size 0x4
    f32 _14; // offset 0xC, size 0x4
    f32 _21; // offset 0x10, size 0x4
    f32 _22; // offset 0x14, size 0x4
    f32 _23; // offset 0x18, size 0x4
    f32 _24; // offset 0x1C, size 0x4
    f32 _31; // offset 0x20, size 0x4
    f32 _32; // offset 0x24, size 0x4
    f32 _33; // offset 0x28, size 0x4
    f32 _34; // offset 0x2C, size 0x4
    f32 _41; // offset 0x30, size 0x4
    f32 _42; // offset 0x34, size 0x4
    f32 _43; // offset 0x38, size 0x4
    f32 _44; // offset 0x3C, size 0x4
} Matrix;

typedef union {
    f32 f[16];   // offset 0x0, size 0x40
    f32 a[4][4]; // offset 0x0, size 0x40
    Matrix m;    // offset 0x0, size 0x40
} MTX;

typedef struct {
    // total size: 0xC
    s8 ok;             // offset 0x0, size 0x1
    s8 type;           // offset 0x1, size 0x1
    s16 key;           // offset 0x2, size 0x2
    u32 texture_table; // offset 0x4, size 0x4
    u32 trans_table;   // offset 0x8, size 0x4
} TEX_GRP_LD;

typedef struct {
    // total size: 0x28
    u8 be;           // offset 0x0, size 0x1
    u8 type;         // offset 0x1, size 0x1
    s16 id;          // offset 0x2, size 0x2
    u8 rno;          // offset 0x4, size 0x1
    u8 retry;        // offset 0x5, size 0x1
    u8 ix;           // offset 0x6, size 0x1
    u8 frre;         // offset 0x7, size 0x1
    s16 key;         // offset 0x8, size 0x2
    u8 kokey;        // offset 0xA, size 0x1
    u8 group;        // offset 0xB, size 0x1
    u8 *result;      // offset 0xC, size 0x4
    s32 size;        // offset 0x10, size 0x4
    s32 sect;        // offset 0x14, size 0x4
    u16 fnum;        // offset 0x18, size 0x2
    u8 free[2];      // offset 0x1A, size 0x2
    TEX_GRP_LD *lds; // offset 0x1C, size 0x4
    struct {
        // total size: 0x8
        u32 number; // offset 0x0, size 0x4
        u32 size;   // offset 0x4, size 0x4
    } info;         // offset 0x20, size 0x8
} REQ;

struct _cursor_infor {
    // total size: 0x2
    u8 first_x; // offset 0x0, size 0x1
    u8 first_y; // offset 0x1, size 0x1
};

typedef struct {
    // total size: 0x18
    u8 ok[20];                            // offset 0x0, size 0x14
    struct _cursor_infor cursor_infor[2]; // offset 0x14, size 0x4
} Permission;

typedef struct {
    // total size: 0x30
    s16 data[4][6]; // offset 0x0, size 0x30
} UNK_Data;

typedef struct {
    // total size: 0x64
    u32 *nmca;      // offset 0x0, size 0x4
    u32 *dmca;      // offset 0x4, size 0x4
    u32 *btca;      // offset 0x8, size 0x4
    u32 *caca;      // offset 0xC, size 0x4
    u32 *cuca;      // offset 0x10, size 0x4
    u32 *atca;      // offset 0x14, size 0x4
    u32 *saca;      // offset 0x18, size 0x4
    u32 *exca;      // offset 0x1C, size 0x4
    u32 *cbca;      // offset 0x20, size 0x4
    u32 *yuca;      // offset 0x24, size 0x4
    s16 *stxy;      // offset 0x28, size 0x4
    s16 *mvxy;      // offset 0x2C, size 0x4
    u32 *sernd;     // offset 0x30, size 0x4
    UNK_8 *ovct;    // offset 0x34, size 0x4
    UNK_9 *ovix;    // offset 0x38, size 0x4
    UNK_10 *rict;   // offset 0x3C, size 0x4
    UNK_0 *hiit;    // offset 0x40, size 0x4
    UNK_1 *boda;    // offset 0x44, size 0x4
    UNK_2 *hana;    // offset 0x48, size 0x4
    UNK_3 *cata;    // offset 0x4C, size 0x4
    UNK_4 *caua;    // offset 0x50, size 0x4
    UNK_5 *atta;    // offset 0x54, size 0x4
    UNK_6 *hosa;    // offset 0x58, size 0x4
    UNK_7 *atit;    // offset 0x5C, size 0x4
    UNK_Data *prot; // offset 0x60, size 0x4
} CharInitData;

typedef struct {
    // total size: 0xC
    u32 adr;        // offset 0x0, size 0x4
    u32 size;       // offset 0x4, size 0x4
    u8 search_type; // offset 0x8, size 0x1
    u8 group_num;   // offset 0x9, size 0x1
    u8 type;        // offset 0xA, size 0x1
    u8 use;         // offset 0xB, size 0x1
} RCKeyWork;

typedef struct {
    // total size: 0x32
    s8 type;         // offset 0x0, size 0x1
    s8 form;         // offset 0x1, size 0x1
    s8 end_flag[4];  // offset 0x2, size 0x4
    s8 dmm;          // offset 0x6, size 0x1
    s16 id;          // offset 0x8, size 0x2
    s16 r_no_0;      // offset 0xA, size 0x2
    s16 r_no_1;      // offset 0xC, size 0x2
    u8 rank_in;      // offset 0xE, size 0x1
    s16 rank_status; // offset 0x10, size 0x2
    s16 rank;        // offset 0x12, size 0x2
    s16 status;      // offset 0x14, size 0x2
    s16 index;       // offset 0x16, size 0x2
    s16 timer;       // offset 0x18, size 0x2
    s16 code[4];     // offset 0x1A, size 0x8
    s16 old_code[4]; // offset 0x22, size 0x8
    s16 count1[2];   // offset 0x2A, size 0x4
    s8 count2[2];    // offset 0x2E, size 0x2
    s16 wait_cnt;    // offset 0x30, size 0x2
} NAME_WK;

typedef struct {
    // total size: 0x4
    s8 code[4]; // offset 0x0, size 0x4
} UNK_14;

typedef struct {
    // total size: 0x14
    s8 be;        // offset 0x0, size 0x1
    u8 c_mode;    // offset 0x1, size 0x1
    u16 total;    // offset 0x2, size 0x2
    u16 *handle;  // offset 0x4, size 0x4
    s32 ixNum1st; // offset 0x8, size 0x4
    u8 *srcAdrs;  // offset 0xC, size 0x4
    u32 srcSize;  // offset 0x10, size 0x4
} Palette;

typedef union {
    u32 b32;    // offset 0x0, size 0x4
    u16 b16[2]; // offset 0x0, size 0x4
    u8 b8[4];   // offset 0x0, size 0x4
} TextureHandle;

typedef struct {
    // total size: 0x20
    s8 be;                 // offset 0x0, size 0x1
    u8 flags;              // offset 0x1, size 0x1
    s16 arCnt;             // offset 0x2, size 0x2
    s16 arInit;            // offset 0x4, size 0x2
    u16 total;             // offset 0x6, size 0x2
    TextureHandle *handle; // offset 0x8, size 0x4
    s32 ixNum1st;          // offset 0xC, size 0x4
    u16 textures;          // offset 0x10, size 0x2
    u16 accnum;            // offset 0x12, size 0x2
    u32 *offset;           // offset 0x14, size 0x4
    u8 *srcAdrs;           // offset 0x18, size 0x4
    u32 srcSize;           // offset 0x1C, size 0x4
} Texture;

typedef struct {
    // total size: 0x8
    Texture *tex; // offset 0x0, size 0x4
    Palette *pal; // offset 0x4, size 0x4
} PPGDataList;

typedef struct {
    // total size: 0x10
    u32 magic;     // offset 0x0, size 0x4
    u32 fileSize;  // offset 0x4, size 0x4
    u8 width;      // offset 0x8, size 0x1
    u8 height;     // offset 0x9, size 0x1
    u8 compress;   // offset 0xA, size 0x1
    u8 pixel;      // offset 0xB, size 0x1
    u16 formARGB;  // offset 0xC, size 0x2
    u16 transNums; // offset 0xE, size 0x2
} PPGFileHeader;

typedef struct {
    // total size: 0x10
    u32 magic;    // offset 0x0, size 0x4
    u32 fileSize; // offset 0x4, size 0x4
    u16 id;       // offset 0x8, size 0x2
    u8 compress;  // offset 0xA, size 0x1
    u8 free;      // offset 0xB, size 0x1
    u32 expSize;  // offset 0xC, size 0x4
} PPXFileHeader;

typedef struct {
    // total size: 0x10
    u32 magic;    // offset 0x0, size 0x4
    u32 fileSize; // offset 0x4, size 0x4
    u16 free;     // offset 0x8, size 0x2
    u8 compress;  // offset 0xA, size 0x1
    u8 c_mode;    // offset 0xB, size 0x1
    u16 formARGB; // offset 0xC, size 0x2
    u16 palettes; // offset 0xE, size 0x2
} PPLFileHeader;

typedef struct {
    // total size: 0x18
    f32 x;   // offset 0x0, size 0x4
    f32 y;   // offset 0x4, size 0x4
    f32 z;   // offset 0x8, size 0x4
    f32 u;   // offset 0xC, size 0x4
    f32 v;   // offset 0x10, size 0x4
    u32 col; // offset 0x14, size 0x4
} Polygon;

typedef struct {
    // total size: 0x14
    f32 x; // offset 0x0, size 0x4
    f32 y; // offset 0x4, size 0x4
    f32 z; // offset 0x8, size 0x4
    f32 s; // offset 0xC, size 0x4
    f32 t; // offset 0x10, size 0x4
} Vertex;

typedef struct {
    // total size: 0x30
    Vec3 v[4]; // offset 0x0, size 0x30
} Quad;

typedef struct {
    // total size: 0x8
    f32 s; // offset 0x0, size 0x4
    f32 t; // offset 0x4, size 0x4
} TexCoord;

typedef struct {
    // total size: 0x54
    Vec3 v[4];     // offset 0x0, size 0x30
    TexCoord t[4]; // offset 0x30, size 0x20
    u32 texCode;   // offset 0x50, size 0x4
} Sprite;

typedef struct {
    // total size: 0x34
    Vec3 v[2];     // offset 0x0, size 0x18
    TexCoord t[2]; // offset 0x18, size 0x10
    u32 vtxColor;  // offset 0x28, size 0x4
    u32 texCode;   // offset 0x2C, size 0x4
    u32 id;        // offset 0x30, size 0x4
} Sprite2;

typedef struct {
    // total size: 0x8
    f32 x; // offset 0x0, size 0x4
    f32 y; // offset 0x4, size 0x4
} PAL_CURSOR_P;

typedef union {
    u32 color; // offset 0x0, size 0x4
    struct {
        // total size: 0x4
        s16 u; // offset 0x0, size 0x2
        s16 v; // offset 0x2, size 0x2
    } tex;     // offset 0x0, size 0x4
    struct {
        // total size: 0x4
        u8 b; // offset 0x0, size 0x1
        u8 g; // offset 0x1, size 0x1
        u8 r; // offset 0x2, size 0x1
        u8 a; // offset 0x3, size 0x1
    } argb;   // offset 0x0, size 0x4
} PAL_CURSOR_COL;

typedef struct {
    // total size: 0x30
    PAL_CURSOR_P pal_cursor_p[4];     // offset 0x0, size 0x20
    PAL_CURSOR_COL pal_cursor_col[4]; // offset 0x20, size 0x10
} PAL_CURSOR_TBL;

typedef struct {
    // total size: 0x10
    PAL_CURSOR_P *p;     // offset 0x0, size 0x4
    PAL_CURSOR_COL *col; // offset 0x4, size 0x4
    PAL_CURSOR_COL *tex; // offset 0x8, size 0x4
    u32 num;             // offset 0xC, size 0x4
} PAL_CURSOR;

typedef union {
    s32 full; // offset 0x0, size 0x4
    struct {
        // total size: 0x4
        u8 B; // offset 0x0, size 0x1
        u8 G; // offset 0x1, size 0x1
        u8 R; // offset 0x2, size 0x1
        u8 A; // offset 0x3, size 0x1
    } rgb;    // offset 0x0, size 0x4
} OPTW_Color;

typedef struct {
    // total size: 0x20
    u32 g_no;       // offset 0x0, size 0x4
    u16 hv;         // offset 0x4, size 0x2
    s16 off_x;      // offset 0x6, size 0x2
    s16 off_y;      // offset 0x8, size 0x2
    f32 zx;         // offset 0xC, size 0x4
    f32 zy;         // offset 0x10, size 0x4
    s32 prio;       // offset 0x14, size 0x4
    s32 trans;      // offset 0x18, size 0x4
    OPTW_Color col; // offset 0x1C, size 0x4
} OPTW;

typedef struct {
    // total size: 0x10
    u32 g_no;       // offset 0x0, size 0x4
    s32 trans;      // offset 0x4, size 0x4
    u16 hv;         // offset 0x8, size 0x2
    s16 ok;         // offset 0xA, size 0x2
    OPTW_Color col; // offset 0xC, size 0x4
} OPTW_Small;

typedef struct {
    // total size: 0x10C
    s8 r_no_0;            // offset 0x0, size 0x1
    s8 r_no_1;            // offset 0x1, size 0x1
    s8 dir;               // offset 0x2, size 0x1
    s8 ctr;               // offset 0x3, size 0x1
    s16 bg_no;            // offset 0x4, size 0x2
    u16 blk_no;           // offset 0x6, size 0x2
    s32 prio;             // offset 0x8, size 0x4
    OPTW_Small map[4][4]; // offset 0xC, size 0x100
} OPBW;

typedef struct {
    // total size: 0x330
    s8 r_no_0;     // offset 0x0, size 0x1
    s8 r_no_1;     // offset 0x1, size 0x1
    s8 r_no_2;     // offset 0x2, size 0x1
    s8 old_rno;    // offset 0x3, size 0x1
    s16 index;     // offset 0x4, size 0x2
    s16 mv_ctr;    // offset 0x6, size 0x2
    s16 free_work; // offset 0x8, size 0x2
    s16 dummy;     // offset 0xA, size 0x2
    OPBW bgw[3];   // offset 0xC, size 0x324
} OP_W;

typedef struct {
    // total size: 0xD08
    s32 x16;            // offset 0x0, size 0x4
    s32 x32;            // offset 0x4, size 0x4
    u16 x16_free[1024]; // offset 0x8, size 0x800
    u16 x32_free[640];  // offset 0x808, size 0x500
} TexturePoolFree;

typedef struct {
    // total size: 0xD08
    s32 x16;            // offset 0x0, size 0x4
    s32 x32;            // offset 0x4, size 0x4
    u16 x16_used[1024]; // offset 0x8, size 0x800
    u16 x32_used[640];  // offset 0x808, size 0x500
} TexturePoolUsed;

typedef struct {
    // total size: 0xD0
    u16 x16_map[4][16]; // offset 0x0, size 0x80
    u8 x32_map[10][8];  // offset 0x80, size 0x50
} PatternMap;

typedef union {
    u32 code; // offset 0x0, size 0x4
    struct {
        // total size: 0x4
        u16 offset; // offset 0x0, size 0x2
        u16 group;  // offset 0x2, size 0x2
    } parts;        // offset 0x0, size 0x4
} PatternCode;

typedef struct {
    // total size: 0x8
    s16 time;       // offset 0x0, size 0x2
    s16 state;      // offset 0x2, size 0x2
    PatternCode cs; // offset 0x4, size 0x4
} PatternState;

typedef struct {
    // total size: 0xDC
    s16 curr_disp;  // offset 0x0, size 0x2
    s16 time;       // offset 0x2, size 0x2
    PatternCode cg; // offset 0x4, size 0x4
    s16 x16;        // offset 0x8, size 0x2
    s16 x32;        // offset 0xA, size 0x2
    PatternMap map; // offset 0xC, size 0xD0
} PatternInstance;

typedef struct {
    // total size: 0x3804
    s16 kazu;                 // offset 0x0, size 0x2
    PatternInstance *adr[64]; // offset 0x4, size 0x100
    PatternInstance patt[64]; // offset 0x104, size 0x3700
} PatternCollection;

typedef struct {
    // total size: 0x64
    s32 mltnum16;            // offset 0x0, size 0x4
    s32 mltnum32;            // offset 0x4, size 0x4
    s32 mltnum;              // offset 0x8, size 0x4
    s32 mltgidx16;           // offset 0xC, size 0x4
    s32 mltgidx32;           // offset 0x10, size 0x4
    s32 mltcshtime16;        // offset 0x14, size 0x4
    s32 mltcshtime32;        // offset 0x18, size 0x4
    PatternState *mltcsh16;  // offset 0x1C, size 0x4
    PatternState *mltcsh32;  // offset 0x20, size 0x4
    u8 *mltbuf;              // offset 0x24, size 0x4
    Texture tex;             // offset 0x28, size 0x20
    PPGDataList texList;     // offset 0x48, size 0x8
    u32 attribute;           // offset 0x50, size 0x4
    PatternCollection *cpat; // offset 0x54, size 0x4
    TexturePoolFree *tpf;    // offset 0x58, size 0x4
    TexturePoolUsed *tpu;    // offset 0x5C, size 0x4
    u8 id;                   // offset 0x60, size 0x1
    u8 ext;                  // offset 0x61, size 0x1
    s16 mode;                // offset 0x62, size 0x2
} MultiTexture;

typedef struct {
    // total size: 0x4
    u16 bg_h_shift; // offset 0x0, size 0x2
    u16 bg_v_shift; // offset 0x2, size 0x2
} BackgroundParameters;

union POS_FLOAT {
    s32 long_pos; // offset 0x0, size 0x4
    struct {
        // total size: 0x4
        s16 l;  // offset 0x0, size 0x2
        s16 h;  // offset 0x2, size 0x2
    } word_pos; // offset 0x0, size 0x4
};

typedef struct {
    // total size: 0x10
    union POS_FLOAT scr_x;      // offset 0x0, size 0x4
    union POS_FLOAT scr_x_buff; // offset 0x4, size 0x4
    union POS_FLOAT scr_y;      // offset 0x8, size 0x4
    union POS_FLOAT scr_y_buff; // offset 0xC, size 0x4
} BG_POS;

typedef struct {
    // total size: 0x10
    union POS_FLOAT family_x;      // offset 0x0, size 0x4
    union POS_FLOAT family_x_buff; // offset 0x4, size 0x4
    union POS_FLOAT family_y;      // offset 0x8, size 0x4
    union POS_FLOAT family_y_buff; // offset 0xC, size 0x4
} FM_POS;

typedef struct {
    // total size: 0x14
    u8 bg_num;    // offset 0x0, size 0x1
    s16 *rwd_ptr; // offset 0x4, size 0x4
    s16 *brw_ptr; // offset 0x8, size 0x4
    s16 rw_cnt;   // offset 0xC, size 0x2
    s16 rwgbix;   // offset 0xE, size 0x2
    s16 gbix;     // offset 0x10, size 0x2
} RW_DATA;

typedef struct {
    // total size: 0x18
    u8 state;      // offset 0x0, size 0x1
    u8 phase;      // offset 0x1, size 0x1
    u8 port;       // offset 0x2, size 0x1
    u8 slot;       // offset 0x3, size 0x1
    u8 kind;       // offset 0x4, size 0x1
    u8 vib;        // offset 0x5, size 0x1
    u8 socket_id;  // offset 0x6, size 0x1
    u8 pad_id;     // offset 0x7, size 0x1
    u64 *buff;     // offset 0x8, size 0x4, supposed to be __int128*
    u32 bprofile;  // offset 0xC, size 0x4
    u32 vprofile;  // offset 0x10, size 0x4
    u32 vib_timer; // offset 0x14, size 0x4
} PS2Slot;

#endif
