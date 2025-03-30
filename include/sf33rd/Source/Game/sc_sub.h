#ifndef SC_SUB_H
#define SC_SUB_H

#include "types.h"

void Scrscreen_Init();
void Sa_frame_Write();
void SSPutStr(u16 x, u16 y, u8 atr, s8 *str);
void SSPutStr2(u16 x, u16 y, u8 atr, s8 *str);
void FadeInit();
s32 FadeOut(u8 type, u8 step, u8 priority);
s32 FadeIn(u8 type, u8 step, u8 priority);
void ToneDown(u8 tone, u8 priority);
void player_name();
void player_face_init();
void player_face();
void dispButtonImage2(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix);
void fade_cont_init();
void fade_cont_main();

#endif
