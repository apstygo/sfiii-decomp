#ifndef SDL_GAME_RENDERER_H
#define SDL_GAME_RENDERER_H

#include <SDL3/SDL.h>

typedef struct SDLGameRenderer_Vec3 {
    float x;
    float y;
    float z;
} SDLGameRenderer_Vec3;

typedef struct SDLGameRenderer_TexCoord {
    float s;
    float t;
} SDLGameRenderer_TexCoord;

typedef struct SDLGameRenderer_Vertex {
    struct {
        float x;
        float y;
        float z;
        float w;
    } coord;
    unsigned int color;
    SDLGameRenderer_TexCoord tex_coord;
} SDLGameRenderer_Vertex;

typedef struct SDLGameRenderer_Sprite {
    SDLGameRenderer_Vec3 v[4];
    SDLGameRenderer_TexCoord t[4];
    unsigned int tex_code;
} SDLGameRenderer_Sprite;

typedef struct SDLGameRenderer_Sprite2 {
    SDLGameRenderer_Vec3 v[2];
    SDLGameRenderer_TexCoord t[2];
    unsigned int vertex_color;
    unsigned int tex_code;
    unsigned int id;
} SDLGameRenderer_Sprite2;

extern SDL_Texture* cps3_canvas;

void SDLGameRenderer_Init(SDL_Renderer* renderer);
void SDLGameRenderer_BeginFrame();
void SDLGameRenderer_RenderFrame();
void SDLGameRenderer_EndFrame();

void SDLGameRenderer_CreateTexture(unsigned int th);
void SDLGameRenderer_DestroyTexture(unsigned int texture_handle);
void SDLGameRenderer_UnlockTexture(unsigned int th);
void SDLGameRenderer_CreatePalette(unsigned int ph);
void SDLGameRenderer_DestroyPalette(unsigned int palette_handle);
void SDLGameRenderer_UnlockPalette(unsigned int ph);
void SDLGameRenderer_SetTexture(unsigned int th);
void SDLGameRenderer_DrawTexturedQuad(const SDLGameRenderer_Vertex* vertices);
void SDLGameRenderer_DrawSolidQuad(const SDLGameRenderer_Vertex* vertices);
void SDLGameRenderer_DrawSprite(const SDLGameRenderer_Sprite* sprite, unsigned int color);
void SDLGameRenderer_DrawSprite2(const SDLGameRenderer_Sprite2* sprite2);

int SDLGameRenderer_GetRenderTaskCount();

#endif
