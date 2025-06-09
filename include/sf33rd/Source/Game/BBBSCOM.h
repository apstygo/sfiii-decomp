#ifndef BBBSCOM_H
#define BBBSCOM_H

#include "types.h"
#include "structs.h"

typedef struct /* @anon24 */ {
    // total size: 0x26
    signed short timer; // offset 0x0, size 0x2
    signed short jmplv; // offset 0x2, size 0x2
    signed short kosuu; // offset 0x4, size 0x2
    signed short bbdat[4][4]; // offset 0x6, size 0x20
} BBBSTable;

extern const s32 bbbs_jump_level[4][2]; // size: 0x20, address: 0x4E58A0
extern const BBBSTable bbbs_level_00[18]; // size: 0x2AC, address: 0x4E58C0
extern const BBBSTable bbbs_level_01[16]; // size: 0x260, address: 0x4E5B70
extern const BBBSTable bbbs_level_02[15]; // size: 0x23A, address: 0x4E5DD0
extern const BBBSTable bbbs_level_03[13]; // size: 0x1EE, address: 0x4E6010
extern const BBBSTable bbbs_level_04[11]; // size: 0x1A2, address: 0x4E6200
extern const BBBSTable bbbs_level_05[18]; // size: 0x2AC, address: 0x4E63B0
extern const BBBSTable bbbs_level_06[16]; // size: 0x260, address: 0x4E6660
extern const BBBSTable bbbs_level_07[17]; // size: 0x286, address: 0x4E68C0
extern const BBBSTable bbbs_level_08[11]; // size: 0x1A2, address: 0x4E6B50
extern const BBBSTable bbbs_level_09[12]; // size: 0x1C8, address: 0x4E6D00

extern const BBBSTable * bbbs_table[2][5]; // size: 0x28, address: 0x5724A0

// u8 bbbs_type; // size: 0x1, address: 0x57A2D4

void bbbs_com_execute(PLW *wk);
void bbbs_com_initialize();
void makeup_bonus_game_level(s16 ix);
s32 set_bonus_game_difficulty(s16 emid);
s32 set_bonus_game_nando(u16 swdat);
s32 katteni_bonus_nando(u16 swdat);

#endif
