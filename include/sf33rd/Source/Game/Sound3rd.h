#ifndef SOUND3RD_H
#define SOUND3RD_H

#include "types.h"

void Init_sound_system();
s32 sndCheckVTransStatus(s32 type);
void sndInitialLoad();
void checkAdxFileLoaded();
void Exit_sound_system();
void Init_bgm_work();
void sound_all_off();
void setSeVolume(u8 /* unused */);
void setupSoundMode();
void BGM_Server();
void setupAlwaysSeamlessFlag(s16 flag);
s32 adx_now_playend();
s32 bgmSkipCheck(s32 code);
void SsAllNoteOff();
void SsRequest(u16 ReqNumber);
void Standby_BGM(s16 num);
void Go_BGM();
void SsBgmFadeOut(u16 time);
void SsBgmHalfVolume(s16 flag);
void SE_cursor_move();
void SE_selected();
void SE_dir_cursor_move();
void SE_dir_selected();

#endif
