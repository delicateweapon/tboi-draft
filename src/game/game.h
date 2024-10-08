#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    // Errors
    GAME_FAILED_INITIALIZATION,
    GAME_FAILED_ATTRIBUTE_CHANGE,

    // Not Errors
    GAME_CONTINUE,
    GAME_QUIT,
} GameResult;

bool game_result_is_error(GameResult result);
void game_handle_error(GameResult result, const char *message);

#define GAME_TITLE_MAX_LENGTH (1 << 7)
#define GAME_DEFAULT_WINDOW_WIDTH 800
#define GAME_DEFAULT_WINDOW_HEIGHT 500

typedef struct {
    struct {
        struct {
            SDL_Window *p;
            int window_flags;
            char *title;
            int width;
            int height;
        } window;
        struct {
            SDL_Renderer *p;
        } renderer;
    } sdl;

    bool is_initialized;
    bool is_running;
} Game;

extern Game *game;

void game_init();
void game_run();
void game_deinit();

void game_sdl_window_set_title(const char *title);
void game_sdl_window_set_dimensions(const int width, const int height);
