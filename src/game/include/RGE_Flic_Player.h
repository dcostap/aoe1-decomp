#pragma once
#include "common.h"

struct RGE_Flic_Player {
    uchar* flic_buffer;
    int flic_handle;
    FlicHead flichead;
    TDrawArea* drawarea;
    long drawarea_width;
    long flic_width;
    uchar* window_buffer;
    uchar* save_buffer;
    char* chunk;
    long x1;
    long y1;
    long x2;
    long y2;
    long flic_size_x;
    long flic_size_y;
};
static_assert(sizeof(RGE_Flic_Player) == 0xBC, "Size mismatch");
