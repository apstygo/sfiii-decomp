#include "sf33rd/Source/Game/bg.h"
#include "common.h"
#include "sf33rd/Source/Game/DC_Ghost.h"
#include "sf33rd/Source/Game/WORK_SYS.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_TexInit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Kakikae_Set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Ed_Kakikae_Set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Close);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Texture_Load_EX);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Texture_Load2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Texture_Load_Ending);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", literal_380_004E6EC8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", literal_423_004E6ED8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", literal_424_004E6EF0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", literal_502_004E6F20);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", scr_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", bgRWWorkUpdate);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", bgDrawOneScreen);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", bgDrawOneChip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", bgAkebonoDraw);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", ppgCalScrPosition);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", scr_trans_sub2);

void scr_calc(u8 bgnm) {
    njUnitMatrix(NULL);
    njScale(NULL, Frame_Zoom_X, Frame_Zoom_Y, 1.0f);
    njScale(NULL, scr_sc, scr_sc, 1.0f);
    njTranslate(NULL, 0.0f, 224.0f, 0.0f);
    njScale(NULL, 1.0f, -1.0f, 1.0f);
    njTranslate(NULL, (s16)-bg_prm[bgnm].bg_h_shift, (s16)-bg_prm[bgnm].bg_v_shift, 0.0f);
    njGetMatrix(&BgMATRIX[bgnm + 1]);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", scr_calc2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Pause_Family_On);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Zoomf_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Zoom_Value_Set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Frame_Up);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Frame_Down);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Frame_Adgjust);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Scrn_Pos_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Scrn_Move_Set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Family_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Family_Set_R);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Family_Set_W);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_On_R);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_On_W);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Off_R);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Off_W);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Scrn_Renew);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Irl_Family);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Irl_Scrn);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Family_Move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Ending_Family_Move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Disp_Switch);
