#ifndef BG_H
#define BG_H

#include "structs.h"
#include "types.h"

extern s32 bgPalCodeOffset[8];          // size: 0x20, address: 0x578AA0
extern u16 Screen_Switch_Buffer;        // size: 0x2, address: 0x578B60
extern u16 Screen_Switch;               // size: 0x2, address: 0x578B64

extern BG bg_w; // size: 0x428, address: 0x595830

void Bg_TexInit();
void Pause_Family_On();
void Bg_Off_R(u16 s_prm);
void Bg_Off_W(u16 s_prm);
void Scrn_Renew();
void Irl_Family();
void Irl_Scrn();
void Frame_Down(u16 x, u16 y, u16 add);
void Zoom_Value_Set(u16 zadd);
void scr_calc(u8 bgnm);
void Family_Init();
void Scrn_Pos_Init();
void Zoomf_Init();

#if defined(TARGET_PS2)
void Frame_Up(u16 x, u16 y, s32 add);
void Scrn_Move_Set(s32 bgnm, s32 x, s32 y);
void Family_Set_W(s32 fmnm, s32 x, s32 y);
// void Bg_On_R(u32 s_prm);
// void Bg_On_W(s32 s_prm);
#else
void Frame_Up(u16 x, u16 y, u16 add);
void Scrn_Move_Set(s8 bgnm, s16 x, s16 y);
void Family_Set_W(s8 fmnm, s16 x, s16 y);
void Bg_On_R(u16 s_prm);
void Bg_On_W(u16 s_prm);
#endif

#endif
