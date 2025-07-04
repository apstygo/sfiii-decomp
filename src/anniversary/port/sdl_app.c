#include "port/sdl_app.h"
#include "common.h"
#include "port/sdk_threads.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Game/main.h"

#include <libgraph.h>

#include <SDL3/SDL.h>

// We can't include cri_mw.h because it leads to conflicts
// with SDL types
int ADXPS2_ExecVint(int mode);

static const char *app_name = "Street Fighter III: 3rd Strike";
static const int display_width = 512;
static const int display_height = 448;
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static const SDL_Color knjsub_palette_colors[4] = {
    { .r = 255, .g = 255, .b = 255, .a = 0 },
    { .r = 255, .g = 255, .b = 255, .a = 0 },
    { .r = 255, .g = 255, .b = 255, .a = 0 },
    { .r = 255, .g = 255, .b = 255, .a = 255 },
};

static SDL_Texture *texture = NULL;
static SDL_Palette *knjsub_palette = NULL;
static int knjsub_palette_count = 0;

int SDLApp_Init() {
    SDL_SetAppMetadata(app_name, "0.1", NULL);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_CreateWindowAndRenderer(app_name, display_width, display_height, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_SetRenderVSync(renderer, 1)) {
        SDL_Log("Couldn't enable VSync: %s", SDL_GetError());
        return 1;
    }

    // Initialize knjsub palette
    knjsub_palette = SDL_CreatePalette(4);
    SDL_SetPaletteColors(knjsub_palette, knjsub_palette_colors, 0, 4);

    return 0;
}

void SDLApp_Quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int SDLApp_PollEvents() {
    SDL_Event event;
    int continue_running = 1;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
            continue_running = 0;
            break;
        }
    }

    return continue_running;
}

void SDLApp_BeginFrame() {
    // const double now = ((double)SDL_GetTicks()) / 1000.0; /* convert from milliseconds to seconds. */
    // /* choose the color for the frame we will draw. The sine wave trick makes it fade between colors smoothly. */
    // const float red = (float)(0.5 + 0.5 * SDL_sin(now));
    // const float green = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
    // const float blue = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));
    // SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT); /* new color, full alpha. */

    const Uint8 a = flPs2State.FrameClearColor >> 24;
    const Uint8 r = (flPs2State.FrameClearColor >> 16) & 0xFF;
    const Uint8 g = (flPs2State.FrameClearColor >> 8) & 0xFF;
    const Uint8 b = flPs2State.FrameClearColor & 0xFF;
    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    /* clear the window to the draw color. */
    SDL_RenderClear(renderer);
}

void SDLApp_CreateKnjsubTexture(int width, int height, void *pixels, int format) {
    if (texture != NULL) {
        SDL_DestroyTexture(texture);
    }

    SDL_Surface *surface = SDL_CreateSurfaceFrom(width, height, SDL_PIXELFORMAT_INDEX4LSB, pixels, width / 2);
    SDL_SetSurfacePalette(surface, knjsub_palette);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);

    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
}

static int adjust_coordinate(int coordinate, bool is_x, bool is_uv) {
    coordinate >>= 4;

    if (!is_uv) {
        const int display_size = is_x ? display_width : display_height;
        coordinate -= (4096 - display_size) / 2;
    }

    return coordinate;
}

static Uint8 scale_color_value(Uint8 value) {
    int temp = value;
    temp *= 2;

    if (temp > 0xFF) {
        temp = 0xFF;
    }

    return (Uint8)temp;
}

void SDLApp_DrawKnjsubTexture(int x0, int y0, int x1, int y1, int u0, int v0, int u1, int v1, unsigned int color) {
    x0 = adjust_coordinate(x0, true, false);
    y0 = adjust_coordinate(y0, false, false);
    x1 = adjust_coordinate(x1, true, false);
    y1 = adjust_coordinate(y1, false, false);
    
    u0 = adjust_coordinate(u0, true, true);
    v0 = adjust_coordinate(v0, false, true);
    u1 = adjust_coordinate(u1, true, true);
    v1 = adjust_coordinate(v1, false, true);

    SDL_FRect src_rect;
    src_rect.x = u0;
    src_rect.y = v0;
    src_rect.w = u1 - u0;
    src_rect.h = v1 - v0;

    SDL_FRect dst_rect;
    dst_rect.x = x0;
    dst_rect.y = y0;
    dst_rect.w = x1 - x0;
    dst_rect.h = y1 - y0;

    const Uint8 r = scale_color_value(color & 0xFF);
    const Uint8 g = scale_color_value((color >> 8) & 0xFF);
    const Uint8 b = scale_color_value((color >> 16) & 0xFF);
    const Uint8 a = scale_color_value(color >> 24);

    SDL_SetTextureColorMod(texture, r, g, b);
    SDL_SetTextureAlphaMod(texture, a);
    SDL_RenderTexture(renderer, texture, &src_rect, &dst_rect);
}

void SDLApp_EndFrame() {
    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);

    begin_interrupt();
    ADXPS2_ExecVint(0);
    end_interrupt();
}
