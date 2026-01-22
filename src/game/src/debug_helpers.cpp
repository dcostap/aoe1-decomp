#include "../include/debug_helpers.h"
#include <timeapi.h>
#include <stdlib.h>

ulong debug_timeGetTime(const char* file, int line) {
    return timeGetTime();
}

void debug_srand(const char* file, int line, unsigned int seed) {
    srand(seed);
}
