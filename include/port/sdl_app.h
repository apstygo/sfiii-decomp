#ifndef SDL_APP_H
#define SDL_APP_H

typedef void (*SDLApp_VSyncCallback)();

int SDLApp_Init();
void SDLApp_Quit();
int SDLApp_PollEvents();
void SDLApp_Render();
void SDLApp_SetVSyncCallback(SDLApp_VSyncCallback callback);

#endif
