#include "game.h"
#include "../util/pretty-print.h"

#include <SDL3/SDL_events.h>

static inline void handle_key_down(SDL_KeyboardEvent key) {
    switch (key.scancode) {
    case SDL_SCANCODE_Q:
        game->is_running = false;
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
