#include "../util/pretty-print.h"
#include "game.h"

#include <SDL3/SDL_init.h>
#include <stdlib.h>

void game_deinit() {
    if (game->sdl.window.p) {
        SDL_DestroyWindow(game->sdl.window.p);
    }

    if (game->sdl.renderer.p) {
        SDL_DestroyRenderer(game->sdl.renderer.p);
    }

    SDL_Quit();
    free(game);
    pretty_print(BG_BLACK, FG_GREEN, "Game successfully deinitialized\n");
}
