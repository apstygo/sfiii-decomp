#include "port/sdl_app.h"
#include "port/sdk_threads.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Game/main.h"

#include <SDL3/SDL.h>

// We can't include cri_mw.h because it leads to conflicts
// with SDL types
int ADXPS2_ExecVint(int mode);

static const char *app_name = "Street Fighter III: 3rd Strike";
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

int SDLApp_Init() {
    SDL_SetAppMetadata(app_name, "0.1", NULL);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_CreateWindowAndRenderer(app_name, 640, 480, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_SetRenderVSync(renderer, 1)) {
        SDL_Log("Couldn't enable VSync: %s", SDL_GetError());
        return 1;
    }

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

void SDLApp_EndFrame() {
    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);

    begin_interrupt();
    ADXPS2_ExecVint(0);
    end_interrupt();
}
