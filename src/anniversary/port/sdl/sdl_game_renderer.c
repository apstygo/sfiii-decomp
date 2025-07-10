#include "port/sdl/sdl_game_renderer.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2etc.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"

#include <libgraph.h>

#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#define RENDER_TASK_MAX 1024

typedef struct RenderTask {
    SDL_Texture *texture;
    SDL_Vertex vertices[4];
    float z;
} RenderTask;

SDL_Texture *cps3_canvas = NULL;

static const int cps3_width = 384;
static const int cps3_height = 224;

static SDL_Renderer *_renderer = NULL;
static SDL_Surface *surfaces[FL_TEXTURE_MAX] = { NULL };
static SDL_Palette *palettes[FL_PALETTE_MAX] = { NULL };
static SDL_Texture *textures[FL_PALETTE_MAX] = { NULL };
static int texture_count = 0;
static RenderTask render_tasks[RENDER_TASK_MAX] = { 0 };
static int render_task_count = 0;

// Debugging

static int texture_index = 0;

static void save_texture(const SDL_Surface *surface, const SDL_Palette *palette) {
    if (palette->ncolors != 16) {
        return;
    }

    char filename[128];
    sprintf(filename, "textures/%d.tga", texture_index);

    const Uint8 *pixels = surface->pixels;
    const int width = surface->w;
    const int height = surface->h;

    FILE *f = fopen(filename, "wb");

    if (!f) {
        return;
    }

    uint8_t header[18] = { 0 };
    header[2] = 2; // uncompressed RGB
    header[12] = width & 0xFF;
    header[13] = (width >> 8) & 0xFF;
    header[14] = height & 0xFF;
    header[15] = (height >> 8) & 0xFF;
    header[16] = 32;   // bits per pixel
    header[17] = 0x20; // top-left origin

    fwrite(header, 1, 18, f);

    // Write pixels in BGRA format
    for (int i = 0; i < width * height; ++i) {
        Uint8 index = pixels[i];

        if (i & 1) {
            index >>= 4;
        } else {
            index &= 0xF;
        }

        const SDL_Color *color = &palette->colors[index];
        const Uint8 bgr[] = { color->b, color->g, color->r, color->a };
        fwrite(bgr, 1, 4, f);
    }

    fclose(f);
    texture_index += 1;
}

// Textures

static void push_texture(SDL_Texture *texture) {
    textures[texture_count] = texture;
    texture_count += 1;
}

static SDL_Texture *get_texture() {
    if (texture_count == 0) {
        fatal_error("No textures to get");
    }

    return textures[texture_count - 1];
}

static void destroy_textures() {
    for (int i = 0; i < texture_count; i++) {
        SDL_DestroyTexture(textures[i]);
        textures[i] = NULL;
    }

    texture_count = 0;
}

static void push_render_task(RenderTask *task) {
    memcpy(&render_tasks[render_task_count], task, sizeof(RenderTask));
    render_task_count += 1;
}

static void clear_render_tasks() {
    SDL_zeroa(render_tasks);
    render_task_count = 0;
}

static int compare_render_tasks(const RenderTask *a, const RenderTask *b) {
    if (a->z < b->z) {
        return -1;
    } else if (a->z > b->z) {
        return 1;
    } else {
        return 0;
    }
}

// Colors

#define clut_shuf(x) (((x) & ~0x18) | ((((x) & 0x08) << 1) | (((x) & 0x10) >> 1)))

static void read_rgba32_color(Uint32 pixel, SDL_Color *color) {
    color->r = pixel & 0xFF;
    color->g = (pixel >> 8) & 0xFF;
    color->b = (pixel >> 16) & 0xFF;
    color->a = (pixel >> 24) & 0xFF;
}

static void read_rgba32_fcolor(Uint32 pixel, SDL_FColor *fcolor) {
    SDL_Color color;

    read_rgba32_color(pixel, &color);
    fcolor->r = (float)color.r / 255;
    fcolor->g = (float)color.g / 255;
    fcolor->b = (float)color.b / 255;
    fcolor->a = (float)color.a / 255;
}

static void read_rgba16_color(Uint16 pixel, SDL_Color *color) {
    color->r = (pixel & 0x1F) * 255 / 31;
    color->g = ((pixel >> 5) & 0x1F) * 255 / 31;
    color->b = ((pixel >> 10) & 0x1F) * 255 / 31;
    color->a = (pixel & 0x8000) ? 255 : 0;
}

static void read_color(void *pixels, int index, size_t color_size, SDL_Color *color) {
    switch (color_size) {
    case 2: {
        const Uint16 *rgba16_colors = (Uint16 *)pixels;
        read_rgba16_color(rgba16_colors[index], color);
        break;
    }

    case 4: {
        const Uint32 *rgba32_colors = (Uint32 *)pixels;
        read_rgba32_color(rgba32_colors[index], color);
        break;
    }
    }
}

// Lifecycle

void SDLGameRenderer_Init(SDL_Renderer *renderer) {
    _renderer = renderer;
    cps3_canvas =
        SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, cps3_width, cps3_height);
    SDL_SetTextureScaleMode(cps3_canvas, SDL_SCALEMODE_NEAREST);
}

void SDLGameRenderer_BeginFrame() {
    // Clear canvas
    const Uint8 r = (flPs2State.FrameClearColor >> 16) & 0xFF;
    const Uint8 g = (flPs2State.FrameClearColor >> 8) & 0xFF;
    const Uint8 b = flPs2State.FrameClearColor & 0xFF;
    const Uint8 a = flPs2State.FrameClearColor >> 24;
    SDL_SetRenderDrawColor(_renderer, r, g, b, a);
    SDL_SetRenderTarget(_renderer, cps3_canvas);
    SDL_RenderClear(_renderer);
}

void SDLGameRenderer_RenderFrame() {
    SDL_SetRenderTarget(_renderer, cps3_canvas);
    qsort(render_tasks, render_task_count, sizeof(RenderTask), compare_render_tasks);

    for (int i = 0; i < render_task_count; i++) {
        const RenderTask *task = &render_tasks[i];
        const int indices[] = { 0, 1, 2, 1, 2, 3 };
        SDL_RenderGeometry(_renderer, task->texture, task->vertices, 4, indices, 6);
    }
}

void SDLGameRenderer_EndFrame() {
    destroy_textures();
    clear_render_tasks();
}

void SDLGameRenderer_CreateTexture(unsigned int th) {
    const int texture_index = LO_16_BITS(th) - 1;
    const FLTexture *fl_texture = &flTexture[texture_index];
    const void *pixels = flPS2GetSystemBuffAdrs(fl_texture->mem_handle);
    SDL_PixelFormat pixel_format = SDL_PIXELFORMAT_UNKNOWN;
    int pitch = 0;

    if (surfaces[texture_index] != NULL) {
        fatal_error("Overwriting an existing texture");
    }

    switch (fl_texture->format) {
    case SCE_GS_PSMT8:
        pixel_format = SDL_PIXELFORMAT_INDEX8;
        pitch = fl_texture->width;
        break;

    case SCE_GS_PSMT4:
        pixel_format = SDL_PIXELFORMAT_INDEX4LSB;
        pitch = fl_texture->width / 2;
        break;

    default:
        fatal_error("Unhandled pixel format: %d", fl_texture->format);
        break;
    }

    const SDL_Surface *surface =
        SDL_CreateSurfaceFrom(fl_texture->width, fl_texture->height, pixel_format, pixels, pitch);
    surfaces[texture_index] = surface;
}

void SDLGameRenderer_DestroyTexture(unsigned int texture_handle) {
    const int texture_index = texture_handle - 1;

    SDL_DestroySurface(surfaces[texture_index]);
    surfaces[texture_index] = NULL;
}

void SDLGameRenderer_CreatePalette(unsigned int ph) {
    const int palette_index = HI_16_BITS(ph) - 1;
    const FLTexture *fl_palette = &flPalette[palette_index];
    const void *pixels = flPS2GetSystemBuffAdrs(fl_palette->mem_handle);
    const int color_count = fl_palette->width * fl_palette->height;
    SDL_Color colors[256];
    size_t color_size = 0;

    if (palettes[palette_index] != NULL) {
        fatal_error("Overwriting an existing palette");
    }

    switch (fl_palette->format) {
    case SCE_GS_PSMCT32:
        color_size = 4;
        break;

    case SCE_GS_PSMCT16:
        color_size = 2;
        break;

    default:
        fatal_error("Unhandled pixel format: %d", fl_palette->format);
        break;
    }

    switch (color_count) {
    case 16:
        for (int i = 0; i < 16; i++) {
            read_color(pixels, i, color_size, &colors[i]);
        }

        break;

    case 256:
        for (int i = 0; i < 256; i++) {
            const int color_index = clut_shuf(i);
            read_color(pixels, color_index, color_size, &colors[i]);
        }

        break;

    default:
        fatal_error("Unhandled palette dimensions: %dx%d", fl_palette->width, fl_palette->height);
        break;
    }

    SDL_Palette *palette = SDL_CreatePalette(color_count);
    SDL_SetPaletteColors(palette, colors, 0, color_count);
    palettes[palette_index] = palette;
}

void SDLGameRenderer_DestroyPalette(unsigned int palette_handle) {
    const int palette_index = palette_handle - 1;

    SDL_DestroyPalette(palettes[palette_index]);
    palettes[palette_index] = NULL;
}

void SDLGameRenderer_SetTexture(unsigned int th) {
    const SDL_Surface *surface = surfaces[LO_16_BITS(th) - 1];
    const SDL_Palette *palette = palettes[HI_16_BITS(th) - 1];

    // Uncomment this to save textures into textures folder
    // save_texture(surface, palette);

    SDL_SetSurfacePalette(surface, palette);
    const SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    push_texture(texture);
}

static void draw_quad(SDLGameRenderer_Vertex *vertices, bool textured) {
    RenderTask task;
    task.texture = textured ? get_texture() : NULL;
    task.z = vertices[0].coord.z;

    SDL_zeroa(task.vertices);

    for (int i = 0; i < 4; i++) {
        task.vertices[i].position.x = vertices[i].coord.x;
        task.vertices[i].position.y = vertices[i].coord.y;

        if (textured) {
            task.vertices[i].tex_coord.x = vertices[i].tex_coord.s;
            task.vertices[i].tex_coord.y = vertices[i].tex_coord.t;
        }

        read_rgba32_fcolor(vertices[i].color, &task.vertices[i].color);
    }

    push_render_task(&task);
}

void SDLGameRenderer_DrawTexturedQuad(SDLGameRenderer_Vertex *vertices) {
    draw_quad(vertices, true);
}

void SDLGameRenderer_DrawSolidQuad(SDLGameRenderer_Vertex *vertices) {
    draw_quad(vertices, false);
}
