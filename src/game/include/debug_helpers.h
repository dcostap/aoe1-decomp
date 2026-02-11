#pragma once
#include "common.h"

void debug_srand(const char* file, int line, unsigned int seed);
int debug_rand(const char* file, int line);
ulong debug_timeGetTime(const char* file, int line);

void write_draw_log(char* msg);
void write_draw_log2(char* msg);
void color_log(int a, int b, int c);
