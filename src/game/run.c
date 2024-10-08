#include "../util/pretty-print.h"
#include "game.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>

#define KEY_LOG(key) pretty_print(BG_BLACK, FG_MAGENTA, "Key %c pressed\n", key)

#define render_full_screen(r, g, b, a)                                         \
    SDL_SetRenderDrawColor(renderer, r, g, b, a);                              \
    SDL_RenderClear(renderer);                                                 \
    SDL_RenderPresent(renderer)

static inline void handle_key_down(SDL_KeyboardEvent key) {
    SDL_Renderer *renderer = game->sdl.renderer.p;
    switch (key.scancode) {
    case SDL_SCANCODE_Q:
        KEY_LOG('Q');
        game->is_running = false;
        break;
    case SDL_SCANCODE_R:
        KEY_LOG('R');
        render_full_screen(255, 20, 90, 255);
        break;
    case SDL_SCANCODE_G:
        KEY_LOG('G');
        render_full_screen(20, 255, 90, 255);
        break;
    default:
        break;
    }
}

static inline void handle_event(SDL_Event *event) {
    switch (event->type) {
    case SDL_EVENT_QUIT:
        game->is_running = false;
        break;
    case SDL_EVENT_KEY_DOWN:
        handle_key_down(event->key);
        break;
    default:
        break;
    }
}

void game_run() {
    if (!game->is_initialized) {
        game_init();
    }

    SDL_Event event;
    game->is_running = true;

    while (game->is_running) {
        while (SDL_PollEvent(&event)) {
            handle_event(&event);
        }
    }
}
