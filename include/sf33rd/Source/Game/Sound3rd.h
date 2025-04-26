#ifndef SOUND3RD_H
#define SOUND3RD_H

#include "types.h"

extern s16 bgm_level; // size: 0x2, address: 0x5798D0
extern s16 se_level;  // size: 0x2, address: 0x5798D4

void Init_sound_system();
s32 sndCheckVTransStatus(s32 type);
void sndInitialLoad();
void checkAdxFileLoaded();
void Exit_sound_system();
void Init_bgm_work();
void sound_all_off();

#ifndef SET_SE_VOLUME_DEFINED
#define SET_SE_VOLUME_DEFINED
void setSeVolume(u8 /* unused */);
#endif

void setupSoundMode();
void BGM_Server();
void setupAlwaysSeamlessFlag(s16 flag);
s32 adx_now_playend();
s32 bgmSkipCheck(s32 code);
void SsAllNoteOff();
void SsRequest(u16 ReqNumber);
void SsRequest_CC(u16 num);
void Standby_BGM(u16 num);
void Go_BGM();
void SsBgmFadeOut(u16 time);
void SsBgmHalfVolume(s16 flag);
void SE_cursor_move();
void SE_selected();
void SE_dir_cursor_move();
void SE_dir_selected();
void SsBgmControl(s8 /* unused */, s8 VOLUME);
void SsRequestPan(u16 reqNum, s16 start, s32 /* unused */, s32 /* unused */, s32 /* unused */);

#endif
