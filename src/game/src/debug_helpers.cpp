#include "../include/debug_helpers.h"
#include "../include/globals.h"
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
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041B620
    if (draw_log != nullptr) {
        fprintf(draw_log, "%s", msg);
        fflush(draw_log);
    }
}

void write_draw_log2(char* msg) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041B650
    if (draw_log != nullptr) {
        fprintf(draw_log, "%s", msg);
        fclose(draw_log);
        draw_log = fopen(draw_log_name, "a+");
    }
}

void color_log(int a, int b, int c) {
    // TODO: stub — original writes color-coded debug log entry
}
