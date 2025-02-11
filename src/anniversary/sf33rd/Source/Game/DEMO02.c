#include "common.h"
#include "unknown.h"

void Demo00();
void Demo01();

s32 Play_Demo() {
    void (*main_jmp_tbl[2])() = { Demo00, Demo01 };

    Next_Demo = 0;
    main_jmp_tbl[D_No[0]]();
    return Next_Demo;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Demo00);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Demo01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Setup_Demo_PL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Setup_Demo_Arts);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Setup_Demo_Stage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Setup_Select_Demo_PL);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Demo_PL_Play_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Arts_Rnd_Demo_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Demo_Stage_Play_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Demo_PL_Data);
