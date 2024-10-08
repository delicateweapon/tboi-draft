#include "../util/pretty-print.h"
#include "game.h"

#include <stdio.h>

static inline void log(GameResult result, const char *message) {
    switch (result) {
    case GAME_FAILED_INITIALIZATION:
        fprintf(stderr, "Failed to initialize game: ");
        pretty_print_error(BG_BLACK, FG_RED, message);
        fprintf(stderr, "\n");
        pretty_print(BG_BLACK, FG_YELLOW,
                     "Attempting reinitialization of game\n");
        break;
    case GAME_FAILED_ATTRIBUTE_CHANGE:
        fprintf(stderr, "Failed to change game attribute: ");
        pretty_print_error(BG_BLACK, FG_RED, message);
        fprintf(stderr, "\n");
        break;
    default:
        break;
    }
}

void game_handle_error(GameResult result, const char *message) {
    switch (result) {
    case GAME_FAILED_INITIALIZATION:
        log(result, message);
        game_init();
        break;
    case GAME_FAILED_ATTRIBUTE_CHANGE:
        log(result, message);
        // intentional nothin, for now atleast
        break;
    default:
        break;
    }
}
