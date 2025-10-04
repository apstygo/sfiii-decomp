#ifndef SDL_SOUND_H
#define SDL_SOUND_H

void SDLSound_ProcessTracks();

void SDLSound_Init();
void SDLSound_Exit();
void SDLSound_Stop();
int SDLSound_IsPaused();
void SDLSound_Pause(int pause);
void SDLSound_StartSeamless();
void SDLSound_StartMem(void* buf);
int SDLSound_GetNumFiles();
void SDLSound_EntryAfs(int file_id);
void SDLSound_StartAfs(int file_id);
void SDLSound_ResetEntry();
void SDLSound_SetOutVol(int volume);
int SDLSound_GetStat();

#endif
