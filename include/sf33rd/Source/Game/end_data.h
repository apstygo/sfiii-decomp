#ifndef END_DATA_H
#define END_DATA_H

#include "structs.h"
#include "types.h"

extern const u16 *ending_map_tbl[21][3]; // size: 0xFC, address: 0x46F870

extern const u8 end_use_scr[20];           // size: 0x14, address: 0x51C2C0
extern const u8 end_use_real_scr[20];      // size: 0x14, address: 0x51C2E0
extern const u16 bgtex_ending_file[20];    // size: 0x28, address: 0x51C300
extern const u32 ending_priority[1];       // size: 0x4, address: 0x51C328
extern const u8 ending_opaque[20];         // size: 0x14, address: 0x51C330
extern const u16 ending000_map[128];       // size: 0x100, address: 0x51C350
extern const u16 ending010_map[128];       // size: 0x100, address: 0x51C450
extern const u16 ending020_map[128];       // size: 0x100, address: 0x51C550
extern const u16 ending021_map[128];       // size: 0x100, address: 0x51C650
extern const u16 ending030_map[128];       // size: 0x100, address: 0x51C750
extern const u16 ending040_map[128];       // size: 0x100, address: 0x51C850
extern const u16 ending041_map[128];       // size: 0x100, address: 0x51C950
extern const u16 ending050_map[128];       // size: 0x100, address: 0x51CA50
extern const u16 ending051_map[128];       // size: 0x100, address: 0x51CB50
extern const u16 ending060_map[128];       // size: 0x100, address: 0x51CC50
extern const u16 ending061_map[128];       // size: 0x100, address: 0x51CD50
extern const u16 ending070_map[128];       // size: 0x100, address: 0x51CE50
extern const u16 ending071_map[128];       // size: 0x100, address: 0x51CF50
extern const u16 ending080_map[128];       // size: 0x100, address: 0x51D050
extern const u16 ending090_map[128];       // size: 0x100, address: 0x51D150
extern const u16 ending100_map[128];       // size: 0x100, address: 0x51D250
extern const u16 ending110_map[128];       // size: 0x100, address: 0x51D350
extern const u16 ending111_map[128];       // size: 0x100, address: 0x51D450
extern const u16 ending120_map[128];       // size: 0x100, address: 0x51D550
extern const u16 ending121_map[128];       // size: 0x100, address: 0x51D650
extern const u16 ending130_map[128];       // size: 0x100, address: 0x51D750
extern const u16 ending140_map[128];       // size: 0x100, address: 0x51D850
extern const u16 ending141_map[128];       // size: 0x100, address: 0x51D950
extern const u16 ending142_map[128];       // size: 0x100, address: 0x51DA50
extern const u16 ending150_map[128];       // size: 0x100, address: 0x51DB50
extern const u16 ending160_map[128];       // size: 0x100, address: 0x51DC50
extern const u16 ending161_map[128];       // size: 0x100, address: 0x51DD50
extern const u16 ending170_map[128];       // size: 0x100, address: 0x51DE50
extern const u16 ending180_map[128];       // size: 0x100, address: 0x51DF50
extern const u16 ending190_map[128];       // size: 0x100, address: 0x51E050
extern const u16 ending191_map[128];       // size: 0x100, address: 0x51E150
extern const u32 bgtex_ending_gbix[20][6]; // size: 0x1E0, address: 0x51E250
extern const u8 ending_use_family[20];     // size: 0x14, address: 0x51E430
extern const u8 ending_rewrite_scr[20];    // size: 0x14, address: 0x51E450
extern const s8 edrw_num[20][2];           // size: 0x28, address: 0x51E470
extern const s16 erw020[9];                // size: 0x12, address: 0x51E4A0
extern const s16 erw021[9];                // size: 0x12, address: 0x51E4C0
extern const s16 erw022[9];                // size: 0x12, address: 0x51E4E0
extern const s16 erw023[9];                // size: 0x12, address: 0x51E500
extern const s16 erw024[9];                // size: 0x12, address: 0x51E520
extern const s16 erw025[9];                // size: 0x12, address: 0x51E540
extern const s16 erw026[9];                // size: 0x12, address: 0x51E560
extern const s16 erw027[9];                // size: 0x12, address: 0x51E580
extern const s16 erw028[21];               // size: 0x2A, address: 0x51E5A0
extern const s16 erw029[21];               // size: 0x2A, address: 0x51E5D0
extern const s16 erw02a[21];               // size: 0x2A, address: 0x51E600
extern const s16 erw02b[21];               // size: 0x2A, address: 0x51E630
extern const s16 erw02c[21];               // size: 0x2A, address: 0x51E660
extern const s16 erw02d[21];               // size: 0x2A, address: 0x51E690
extern const s16 erw02e[21];               // size: 0x2A, address: 0x51E6C0
extern const s16 erw02f[21];               // size: 0x2A, address: 0x51E6F0
extern const s16 erw060[9];                // size: 0x12, address: 0x51E720
extern const s16 erw061[9];                // size: 0x12, address: 0x51E740
extern const s16 erw062[9];                // size: 0x12, address: 0x51E760
extern const s16 erw063[9];                // size: 0x12, address: 0x51E780
extern const s16 erw064[9];                // size: 0x12, address: 0x51E7A0
extern const s16 erw065[9];                // size: 0x12, address: 0x51E7C0
extern const s16 erw066[9];                // size: 0x12, address: 0x51E7E0
extern const s16 erw067[9];                // size: 0x12, address: 0x51E800
extern const s16 erw100[9];                // size: 0x12, address: 0x51E820
extern const s16 erw101[9];                // size: 0x12, address: 0x51E840
extern const s16 erw102[9];                // size: 0x12, address: 0x51E860
extern const s16 erw103[9];                // size: 0x12, address: 0x51E880
extern const s16 erw104[9];                // size: 0x12, address: 0x51E8A0
extern const s16 erw105[9];                // size: 0x12, address: 0x51E8C0
extern const s16 erw106[9];                // size: 0x12, address: 0x51E8E0
extern const s16 erw107[9];                // size: 0x12, address: 0x51E900
extern const s16 erw108[11];               // size: 0x16, address: 0x51E920
extern const s16 erw109[11];               // size: 0x16, address: 0x51E940
extern const s16 erw10a[11];               // size: 0x16, address: 0x51E960
extern const s16 erw10b[11];               // size: 0x16, address: 0x51E980
extern const s16 erw10c[11];               // size: 0x16, address: 0x51E9A0
extern const s16 erw10d[11];               // size: 0x16, address: 0x51E9C0
extern const s16 erw10e[11];               // size: 0x16, address: 0x51E9E0
extern const s16 erw10f[11];               // size: 0x16, address: 0x51EA00
extern const s16 gerw00[7];                // size: 0xE, address: 0x51EA18
extern const s16 gerw01[7];                // size: 0xE, address: 0x51EA28
extern const s16 gerw02[7];                // size: 0xE, address: 0x51EA38
extern const s16 gerw03[7];                // size: 0xE, address: 0x51EA48
extern const s16 gerw04[7];                // size: 0xE, address: 0x51EA58
extern const s16 gerw05[7];                // size: 0xE, address: 0x51EA68
extern const s16 gerw06[7];                // size: 0xE, address: 0x51EA78
extern const s16 gerw07[7];                // size: 0xE, address: 0x51EA88
extern const s16 gerw08[7];                // size: 0xE, address: 0x51EA98
extern const s16 gerw09[7];                // size: 0xE, address: 0x51EAA8
extern const s16 gerw0a[7];                // size: 0xE, address: 0x51EAB8
extern const s16 gerw0b[7];                // size: 0xE, address: 0x51EAC8
extern const s16 gerw0c[7];                // size: 0xE, address: 0x51EAD8
extern const s16 gerw0d[7];                // size: 0xE, address: 0x51EAE8
extern const s16 gerw0e[7];                // size: 0xE, address: 0x51EAF8
extern const s16 gerw0f[7];                // size: 0xE, address: 0x51EB08
extern const s16 gerw10[7];                // size: 0xE, address: 0x51EB18
extern const s16 gerw11[7];                // size: 0xE, address: 0x51EB28
extern const s16 gerw12[7];                // size: 0xE, address: 0x51EB38
extern const s16 gerw13[7];                // size: 0xE, address: 0x51EB48
extern const s16 cerw00[2];                // size: 0x4, address: 0x51EB58
extern const s16 cerw01[2];                // size: 0x4, address: 0x51EB60
extern const s16 cerw02[2];                // size: 0x4, address: 0x51EB68
extern const s16 cerw03[2];                // size: 0x4, address: 0x51EB70
extern const s16 cerw04[2];                // size: 0x4, address: 0x51EB78
extern const s16 cerw05[2];                // size: 0x4, address: 0x51EB80
extern const s16 cerw06[2];                // size: 0x4, address: 0x51EB88
extern const s16 cerw07[2];                // size: 0x4, address: 0x51EB90
extern const s16 cerw08[2];                // size: 0x4, address: 0x51EB98
extern const s16 cerw09[2];                // size: 0x4, address: 0x51EBA0
extern const s16 cerw0a[2];                // size: 0x4, address: 0x51EBA8
extern const s16 cerw0b[2];                // size: 0x4, address: 0x51EBB0
extern const s16 cerw0c[2];                // size: 0x4, address: 0x51EBB8
extern const s16 cerw0d[2];                // size: 0x4, address: 0x51EBC0
extern const s16 cerw0e[2];                // size: 0x4, address: 0x51EBC8
extern const s16 cerw0f[2];                // size: 0x4, address: 0x51EBD0
extern const u32 edrw_data_tbl[40][3];     // size: 0x1E0, address: 0x51EBE0
extern const u32 gedrw_data_tbl[20][2];    // size: 0xA0, address: 0x51EDC0
extern const u32 cedrw_data_tbl[16][2];    // size: 0x80, address: 0x51EE60
extern const s32 gouki_end_nosekae[2][16]; // size: 0x80, address: 0x51EEE0
extern const u16 gouki_nosekae_map1[128];  // size: 0x100, address: 0x51EF60
extern const u16 gouki_nosekae_map2[128];  // size: 0x100, address: 0x51F060

extern s8 staff_r_no;      // size: 0x1, address: 0x57900C
extern s8 end_name_cut[2]; // size: 0x2, address: 0x579010
extern s16 end_fade_timer; // size: 0x2, address: 0x579014
extern s8 end_staff_flag;  // size: 0x1, address: 0x579018
extern s8 end_no_cut;      // size: 0x1, address: 0x57901C
extern s8 end_fade_flag;   // size: 0x1, address: 0x579020
extern s8 ending_all_end;  // size: 0x1, address: 0x579024
extern s8 end_etc_flag;    // size: 0x1, address: 0x579028
extern s16 e_line_step;    // size: 0x2, address: 0x57902C
extern END_W end_w;        // size: 0xC, address: 0x579030

#endif // END_DATA_H
