#ifndef SDL_GAME_RENDERER_H
#define SDL_GAME_RENDERER_H

#include <SDL3/SDL.h>

typedef struct SDLGameRenderer_Vertex {
    struct {
        float x;
        float y;
        float z;
        float w;
    } coord;
    unsigned int color;
    struct {
        float s;
        float t;
    } tex_coord;
} SDLGameRenderer_Vertex;

extern SDL_Texture *cps3_canvas;

void SDLGameRenderer_Init(SDL_Renderer *renderer);
void SDLGameRenderer_BeginFrame();
void SDLGameRenderer_RenderFrame();
void SDLGameRenderer_EndFrame();

void SDLGameRenderer_CreateTexture(unsigned int th);
void SDLGameRenderer_DestroyTexture(unsigned int texture_handle);
void SDLGameRenderer_CreatePalette(unsigned int ph);
void SDLGameRenderer_DestroyPalette(unsigned int palette_handle);
void SDLGameRenderer_SetTexture(unsigned int th);
void SDLGameRenderer_DrawTexturedQuad(SDLGameRenderer_Vertex *vertices);
void SDLGameRenderer_DrawSolidQuad(SDLGameRenderer_Vertex *vertices);

#endif
