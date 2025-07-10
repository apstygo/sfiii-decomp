#ifndef SC_SUB_H
#define SC_SUB_H

#include "types.h"

void Scrscreen_Init();
void Sa_frame_Write();
void Sa_frame_Clear();
void SSPutStr(u16 x, u16 y, u8 atr, s8 *str);
void SSPutStr2(u16 x, u16 y, u8 atr, s8 *str);
void SSPutStr_Bigger(u16 x, u16 y, u8 atr, s8 *str, f32 sc, u8 gr, u16 priority);
s32 SSPutStrPro(u16 flag, u16 x, u16 y, u8 atr, u32 vtxcol, s8 *str);
void scfont_sqput(u16 x, u16 y, u8 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority);
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
void Akaobi();
void scfont_put(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy, u16 priority);
void combo_message_set(u8 pl, u8 kind, u8 x, u8 num, u8 hi, u8 low);
void combo_pts_set(u8 pl, u8 x, u8 num, s8 *pts, s8 digit);
void vital_put(u8 Pl_Num, s8 atr, s16 vital, u8 kind, u16 priority);
void silver_vital_put(u8 Pl_Num);
void vital_base_put(u8 Pl_Num);
void stun_gauge_waku_write(s16 p1len, s16 p2len);
void stun_put(u8 Pl_Num, u8 stun);
void stun_base_put(u8 Pl_Num, s16 len);
void stun_mark_write(u8 Pl_Num, s16 Len);

#endif
