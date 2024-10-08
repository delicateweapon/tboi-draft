#include "game/game.h"

Game *game;

int main(void) {
    game_init();
    game_run();
    game_deinit();
    return 0;
}
