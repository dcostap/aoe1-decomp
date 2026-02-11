#include "../include/debug_helpers.h"
#include <timeapi.h>
#include <stdlib.h>

ulong debug_timeGetTime(const char* file, int line) {
    return timeGetTime();
}

void debug_srand(const char* file, int line, unsigned int seed) {
    srand(seed);
}

int debug_rand(const char* file, int line) {
    return rand();
}

void write_draw_log(char* msg) {
    // TODO: stub — original writes to draw log file
}

void write_draw_log2(char* msg) {
    // TODO: stub — original writes to draw log file (safe variant)
}

void color_log(int a, int b, int c) {
    // TODO: stub — original writes color-coded debug log entry
}
