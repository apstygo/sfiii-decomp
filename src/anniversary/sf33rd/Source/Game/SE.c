#include "sf33rd/Source/Game/SE.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "structs.h"

#define SDEB_SIZE 8

extern SoundPatch sdeb[SDEB_SIZE]; // size: 0x60, address: 0x5797F0

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", BGM_Stage_Data);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", SE_Shock_Data);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Finish_SE_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Stage_BGM);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Sound_SE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", BGM_Request);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", BGM_Request_Code_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", BGM_Stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", SE_All_Off);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Se_Dummy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Se_Shock);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Se_Myself);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Se_Myself_Die);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Se_Let);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Se_Let_SP);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Call_Se);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Se_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Finish_SE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Check_Finish_SE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Get_Position);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Check_Bonus_SE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SE", Store_Sound_Code);

void Disp_Sound_Code() {
    s16 i;

    if (Debug_w[4] == 0) {
        return;
    }

    flPrintColor(0xFFFFFFFF);

    for (i = 0; i < SDEB_SIZE; i++) {
        flPrintL(2, i * 2 + 11, "%3X", sdeb[i].cp3code);
        flPrintL(50, i * 2 + 11, "%2X", sdeb[i].rmc.ptix);
        flPrintL(53, i * 2 + 11, "%2X", sdeb[i].rmc.bank);
        flPrintL(56, i * 2 + 11, "%2X", sdeb[i].rmc.port);
        flPrintL(59, i * 2 + 11, "%3X", sdeb[i].rmc.code);
    }

    flPrintColor(0xFFFFFF8F);
    flPrintL(2, 9, "CODE  KDCM PORT BKCD PRIO VOL  POS  PICH NEXT   PX BK PO CODE");
}
