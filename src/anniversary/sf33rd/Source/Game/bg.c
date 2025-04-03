#include "sf33rd/Source/Game/bg.h"
#include "common.h"
#include "sf33rd/Source/Game/DC_Ghost.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "structs.h"

// sbss
Vertex scrDrawPos[4];
Polygon bgpoly[4];
u8 bg_priority[4];
u16 Screen_Switch;
u16 Screen_Switch_Buffer;
u8 rw_num;
u8 rw_bg_flag[4];
u8 tokusyu_stage;
s32 rw_gbix[13];
s8 stage_flash;
s8 stage_ftimer;
s32 yang_ix_plus;
s8 yang_ix;
s8 yang_timer;
u8 ending_flag;
BackgroundParameters end_prm[8];
u8 gouki_end_gbix[16];
u32 *rw3col_ptr;
u8 bg_disp_off;
s32 bgPalCodeOffset[8];

// bss
BG bg_w;
RW_DATA rw_dat[20];

#if defined(TARGET_PS2)
void Frame_Adgjust(u32 pos_x, u32 pos_y);
#else
void Frame_Adgjust(u16 pos_x, u16 pos_y);
#endif

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

void Zoomf_Init() {
    zoom_add = 64;
    scr_sc = 1.0f;
    sca_x = 0;
    sca_y = 1023;
    scrn_adgjust_x = 0;
    scrn_adgjust_y = 0;
}

void Zoom_Value_Set(u16 zadd) {
    f32 work;
    u16 add;

    if (zadd < 0x40) {
        scr_sc = 64.0f / zadd;
        return;
    }

    if (zadd == 0x40) {
        scr_sc = 1.0f;
        return;
    }

    add = zadd & 0x3F;
    work = 1.0f / (64.0f / add);
    add = zadd & 0xFFC0;
    add >>= 6;
    scr_sc = 1.0f / (add + work);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Frame_Up);
#else
void Frame_Up(u16 x, u16 y, u16 add) {
    if (zoom_add < 2) {
        scr_sc = 64.0f;
        return;
    }

    zoom_add -= add;
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}
#endif

void Frame_Down(u16 x, u16 y, u16 add) {
    if (zoom_add >= 0xFFC0) {
        scr_sc = 0.0009775171f;
        return;
    }

    zoom_add += add;
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Frame_Adgjust);
#else
void Frame_Adgjust(u16 pos_x, u16 pos_y) {
    u16 buff;

    if (zoom_add >= 0x40) {
        buff = zoom_add;
        buff -= 0x40;
        buff *= pos_x;
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = -buff;
    } else {
        buff = 0x40;
        buff -= zoom_add;
        buff *= pos_x;
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = buff;
    }

    if (zoom_add >= 0x40) {
        buff = zoom_add;
        buff -= 0x40;
        buff *= pos_y + 0x15;
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = -buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y += 1;
        }
    } else {
        buff = 0x40;
        buff -= zoom_add;
        buff *= pos_y + 0x15;
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y += 1;
        }
    }
}
#endif

void Scrn_Pos_Init() {
    u8 i;

    for (i = 0; i < 8; i++) {
        bg_pos[i].scr_x.long_pos = 0;
        bg_pos[i].scr_x_buff.long_pos = 0;
        bg_pos[i].scr_y.long_pos = 0;
        bg_pos[i].scr_y_buff.long_pos = 0;
        bg_prm[i].bg_h_shift = 0;
        bg_prm[i].bg_v_shift = 0;
        end_prm[i].bg_h_shift = 0;
        end_prm[i].bg_v_shift = 0;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Scrn_Move_Set);
#else
void Scrn_Move_Set(s8 bgnm, s16 x, s16 y) {
    bg_pos[bgnm].scr_x.word_pos.h = x;
    bg_pos[bgnm].scr_y.word_pos.h = y + 16;
}
#endif

void Family_Init() {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x.long_pos = 0;
        fm_pos[i].scr_y.long_pos = 0;
        fm_pos[i].scr_x_buff.long_pos = 0;
        fm_pos[i].scr_y_buff.long_pos = 0;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Family_Set_R);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Family_Set_W);
#else
void Family_Set_W(s8 fmnm, s16 x, s16 y) {
    fm_pos[fmnm].scr_x.word_pos.h = x;
    fm_pos[fmnm].scr_y.word_pos.h = y;
    fm_pos[fmnm].scr_x_buff.word_pos.h = x;
    fm_pos[fmnm].scr_y_buff.word_pos.h = y;
}
#endif

void Bg_On_R(u16 s_prm) {
    Screen_Switch |= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Bg_On_W(u16 s_prm) {
    Screen_Switch |= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Bg_Off_R(u16 s_prm) {
    s_prm = ~s_prm;
    Screen_Switch &= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Bg_Off_W(u16 s_prm) {
    s_prm = ~s_prm;
    Screen_Switch &= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Scrn_Renew() {
    Screen_Switch_Buffer = Screen_Switch;
}

void Irl_Family() {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x_buff.long_pos = fm_pos[i].scr_x.long_pos;
        fm_pos[i].scr_y_buff.long_pos = fm_pos[i].scr_y.long_pos;
        bg_pos[i].scr_x_buff.long_pos = bg_pos[i].scr_x.long_pos;
        bg_pos[i].scr_y_buff.long_pos = bg_pos[i].scr_y.long_pos;
    }
}

void Irl_Scrn() {
    s8 i;

    for (i = 0; i < 8; i++) {
        bg_prm[i].bg_h_shift = scrn_adgjust_x + bg_pos[i].scr_x_buff.word_pos.h;
        bg_prm[i].bg_h_shift;
        end_prm[i].bg_h_shift = scrn_adgjust_x + fm_pos[i].scr_x_buff.word_pos.h;
        end_prm[i].bg_h_shift;
        bg_prm[i].bg_v_shift = bg_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y;
        bg_prm[i].bg_v_shift;
        end_prm[i].bg_v_shift = fm_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y;
        end_prm[i].bg_v_shift;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Family_Move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Ending_Family_Move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Disp_Switch);
