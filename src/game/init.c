#include "game.h"
#include "../util/pretty-print.h"

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdlib.h>

static inline void sdl_init() {
    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    if (!result) {
        game_handle_error(GAME_FAILED_INITIALIZATION, "SDL was not initialized");
    }
}

static inline void sdl_create_window() {
    SDL_Window *temp = SDL_CreateWindow(game->sdl.window.title, game->sdl.window.width, game->sdl.window.height, 0);
    if (temp == NULL) {
        game_handle_error(GAME_FAILED_INITIALIZATION, "SDL window was not created");
        return;
    }
    game->sdl.window.p = temp;
}

static inline void sdl_create_renderer() {
    SDL_Renderer *temp = SDL_CreateRenderer(game->sdl.window.p, NULL);
    if (temp == NULL) {
        game_handle_error(GAME_FAILED_INITIALIZATION, "SDL renderer was not created");
        return;
    }
    game->sdl.renderer.p = temp;
}

void game_init() {
    game = malloc(sizeof(Game));
    if (game == NULL) {
        game_handle_error(GAME_FAILED_INITIALIZATION, "malloc error");
        return;
    }

    game->sdl.window.title = malloc(sizeof(char) * GAME_TITLE_MAX_LENGTH);
    if (game->sdl.window.title == NULL) {
        game_handle_error(GAME_FAILED_INITIALIZATION, "malloc error");
        return;
    }

    game->sdl.window.width = GAME_DEFAULT_WINDOW_WIDTH;
    game->sdl.window.height = GAME_DEFAULT_WINDOW_HEIGHT;

    sdl_init();
    sdl_create_window();
    sdl_create_renderer();

    pretty_print(BG_BLACK, FG_GREEN, "Game successfully initialized\n");
    game->is_initialized = true;
}
