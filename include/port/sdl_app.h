#ifndef SDL_APP_H
#define SDL_APP_H

int SDLApp_Init();
void SDLApp_Quit();
int SDLApp_PollEvents();
void SDLApp_BeginFrame();
void SDLApp_EndFrame();

void SDLApp_CreateKnjsubTexture(int width, int height, void *pixels, int format);
void SDLApp_DrawKnjsubTexture(int x0, int y0, int x1, int y1, int u0, int v0, int u1, int v1, unsigned int color);

#endif
