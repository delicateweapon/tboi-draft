#include "pretty-print.h"

#include <stdio.h>
#include <stdarg.h>

static const char* color_codes[] = {
    "\033[0m",        // RESET
    "\033[30m",      // FG_BLACK
    "\033[31m",      // FG_RED
    "\033[32m",      // FG_GREEN
    "\033[33m",      // FG_YELLOW
    "\033[34m",      // FG_BLUE
    "\033[35m",      // FG_MAGENTA
    "\033[36m",      // FG_CYAN
    "\033[37m",      // FG_WHITE
    "\033[90m",      // FG_BRIGHT_BLACK
    "\033[91m",      // FG_BRIGHT_RED
    "\033[92m",      // FG_BRIGHT_GREEN
    "\033[93m",      // FG_BRIGHT_YELLOW
    "\033[94m",      // FG_BRIGHT_BLUE
    "\033[95m",      // FG_BRIGHT_MAGENTA
    "\033[96m",      // FG_BRIGHT_CYAN
    "\033[97m",      // FG_BRIGHT_WHITE
    "\033[40m",      // BG_BLACK
    "\033[41m",      // BG_RED
    "\033[42m",      // BG_GREEN
    "\033[43m",      // BG_YELLOW
    "\033[44m",      // BG_BLUE
    "\033[45m",      // BG_MAGENTA
    "\033[46m",      // BG_CYAN
    "\033[47m",      // BG_WHITE
    "\033[100m",     // BG_BRIGHT_BLACK
    "\033[101m",     // BG_BRIGHT_RED
    "\033[102m",     // BG_BRIGHT_GREEN
    "\033[103m",     // BG_BRIGHT_YELLOW
    "\033[104m",     // BG_BRIGHT_BLUE
    "\033[105m",     // BG_BRIGHT_MAGENTA
    "\033[106m",     // BG_BRIGHT_CYAN
    "\033[107m"      // BG_BRIGHT_WHITE
};


void pretty_print(AsciiColor bg, AsciiColor fg, const char *message, ...) {
    va_list args;
    va_start(args, message);
    fprintf(stdout, "%s%s", color_codes[bg], color_codes[fg]);
    vfprintf(stdout, message, args);
    fprintf(stdout, "%s", color_codes[0]);
    va_end(args);
}
void pretty_print_error(AsciiColor bg, AsciiColor fg, const char *message, ...) {
    va_list args;
    va_start(args, message);
    fprintf(stderr, "%s%s", color_codes[bg], color_codes[fg]);
    vfprintf(stderr, message, args);
    fprintf(stderr, "%s", color_codes[0]);
    va_end(args);
}
