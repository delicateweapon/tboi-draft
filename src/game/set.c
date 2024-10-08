#include "game.h"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_video.h>
#include <string.h>

void game_sdl_window_set_title(const char *title) {
    char *dest = game->sdl.window.title;
    strcpy(dest, title);
    int result = SDL_SetWindowTitle(game->sdl.window.p, dest);
    if (!result) {
        game_handle_error(GAME_FAILED_ATTRIBUTE_CHANGE, SDL_GetError());
    }
}

void game_sdl_window_set_dimensions(const int width, const int height) {
    game->sdl.window.width = width;
    game->sdl.window.height = height;
    int result = SDL_SetWindowSize(game->sdl.window.p, width, height);
    if (!result) {
        game_handle_error(GAME_FAILED_ATTRIBUTE_CHANGE, SDL_GetError());
    }
}
