#include "sf33rd/Source/Game/RANKING.h"
#include "common.h"
#include "structs.h"

// bss
RANK_DATA Ranking_Data[20];

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking);
#else
s32 Ranking() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_00);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_00_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_00_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_00_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_00_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_00_5th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_00_6th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_01_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_01_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_01_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_01_5th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Setup_grade);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Setup_Name);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Name_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Setup_Face);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Setup_Score);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Setup_Wins);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Setup_Wins2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Setup_Ranking_Obj);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Setup_Score_Obj);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/RANKING", Ranking_Init);

const ScoreRankingEntry Score_Ranking_Table[20] = { { .name = { 28, 13, 22 },
                                                      .player = 15,
                                                      .score = 100000,
                                                      .cpu_grade = 10,
                                                      .grade = 0,
                                                      .wins = 10,
                                                      .player_color = 0,
                                                      .all_clear = 1 },
                                                    { .name = { 22, 24, 24 },
                                                      .player = 16,
                                                      .score = 90000,
                                                      .cpu_grade = 9,
                                                      .grade = 0,
                                                      .wins = 9,
                                                      .player_color = 1,
                                                      .all_clear = 0 },
                                                    { .name = { 23, 14, 24 },
                                                      .player = 17,
                                                      .score = 80000,
                                                      .cpu_grade = 8,
                                                      .grade = 0,
                                                      .wins = 8,
                                                      .player_color = 2,
                                                      .all_clear = 1 },
                                                    { .name = { 24, 23, 30 },
                                                      .player = 18,
                                                      .score = 70000,
                                                      .cpu_grade = 7,
                                                      .grade = 0,
                                                      .wins = 7,
                                                      .player_color = 3,
                                                      .all_clear = 0 },
                                                    { .name = { 34, 24, 20 },
                                                      .player = 19,
                                                      .score = 60000,
                                                      .cpu_grade = 6,
                                                      .grade = 0,
                                                      .wins = 6,
                                                      .player_color = 4,
                                                      .all_clear = 0 },
                                                    { .name = { 20, 10, 18 },
                                                      .player = 15,
                                                      .score = 100000,
                                                      .cpu_grade = 10,
                                                      .grade = 10,
                                                      .wins = 10,
                                                      .player_color = 0,
                                                      .all_clear = 1 },
                                                    { .name = { 21, 29, 1 },
                                                      .player = 16,
                                                      .score = 90000,
                                                      .cpu_grade = 9,
                                                      .grade = 9,
                                                      .wins = 9,
                                                      .player_color = 1,
                                                      .all_clear = 0 },
                                                    { .name = { 34, 30, 20 },
                                                      .player = 17,
                                                      .score = 80000,
                                                      .cpu_grade = 8,
                                                      .grade = 8,
                                                      .wins = 8,
                                                      .player_color = 2,
                                                      .all_clear = 1 },
                                                    { .name = { 27, 10, 24 },
                                                      .player = 18,
                                                      .score = 70000,
                                                      .cpu_grade = 7,
                                                      .grade = 7,
                                                      .wins = 7,
                                                      .player_color = 3,
                                                      .all_clear = 0 },
                                                    { .name = { 0, 0, 8 },
                                                      .player = 19,
                                                      .score = 60000,
                                                      .cpu_grade = 6,
                                                      .grade = 6,
                                                      .wins = 6,
                                                      .player_color = 4,
                                                      .all_clear = 0 },
                                                    { .name = { 18, 12, 17 },
                                                      .player = 15,
                                                      .score = 100000,
                                                      .cpu_grade = 11,
                                                      .grade = 0,
                                                      .wins = 10,
                                                      .player_color = 0,
                                                      .all_clear = 1 },
                                                    { .name = { 28, 14, 29 },
                                                      .player = 5,
                                                      .score = 90000,
                                                      .cpu_grade = 9,
                                                      .grade = 0,
                                                      .wins = 9,
                                                      .player_color = 1,
                                                      .all_clear = 0 },
                                                    { .name = { 23, 14, 24 },
                                                      .player = 4,
                                                      .score = 80000,
                                                      .cpu_grade = 8,
                                                      .grade = 0,
                                                      .wins = 8,
                                                      .player_color = 2,
                                                      .all_clear = 1 },
                                                    { .name = { 24, 23, 30 },
                                                      .player = 10,
                                                      .score = 70000,
                                                      .cpu_grade = 7,
                                                      .grade = 0,
                                                      .wins = 7,
                                                      .player_color = 3,
                                                      .all_clear = 0 },
                                                    { .name = { 34, 24, 20 },
                                                      .player = 8,
                                                      .score = 60000,
                                                      .cpu_grade = 6,
                                                      .grade = 0,
                                                      .wins = 6,
                                                      .player_color = 4,
                                                      .all_clear = 0 },
                                                    { .name = { 18, 23, 14 },
                                                      .player = 19,
                                                      .score = 100000,
                                                      .cpu_grade = 11,
                                                      .grade = 11,
                                                      .wins = 10,
                                                      .player_color = 0,
                                                      .all_clear = 1 },
                                                    { .name = { 21, 29, 1 },
                                                      .player = 1,
                                                      .score = 90000,
                                                      .cpu_grade = 9,
                                                      .grade = 9,
                                                      .wins = 9,
                                                      .player_color = 1,
                                                      .all_clear = 0 },
                                                    { .name = { 34, 30, 20 },
                                                      .player = 4,
                                                      .score = 80000,
                                                      .cpu_grade = 8,
                                                      .grade = 8,
                                                      .wins = 8,
                                                      .player_color = 2,
                                                      .all_clear = 1 },
                                                    { .name = { 27, 10, 24 },
                                                      .player = 10,
                                                      .score = 70000,
                                                      .cpu_grade = 7,
                                                      .grade = 7,
                                                      .wins = 7,
                                                      .player_color = 3,
                                                      .all_clear = 0 },
                                                    { .name = { 18, 23, 14 },
                                                      .player = 8,
                                                      .score = 60000,
                                                      .cpu_grade = 6,
                                                      .grade = 6,
                                                      .wins = 6,
                                                      .player_color = 4,
                                                      .all_clear = 0 } };
