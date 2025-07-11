#include "common.h"
#include "structs.h"

void player_mvbs_0000(PLW *wk);
void player_mvbs_1000(PLW *wk);
void player_mvbs_2000(PLW *wk);
void player_mvbs_3000(PLW *wk);
void player_mvbs_4000(PLW *wk);
//
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN2", Player_move_bonus);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN2", player_mvbs_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN2", player_mvbs_1000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN2", plmv_b_1010);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN2", plmv_b_1020);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN2", player_mvbs_2000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN2", player_mvbs_3000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN2", player_mvbs_4000);

// INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN2", plmain_b_lv_00);

void (*const plmain_b_lv_00[5])(PLW *wk) = {
    player_mvbs_0000, player_mvbs_1000, player_mvbs_2000, player_mvbs_3000, player_mvbs_4000
};
