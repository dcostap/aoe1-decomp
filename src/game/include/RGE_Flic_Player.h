#pragma once
#include "common.h"
#include "FlicHead.h"

struct RGE_Flic_Player {
    RGE_Flic_Player(char* param_1);
    RGE_Flic_Player(int param_1);
    ~RGE_Flic_Player();

    void palette(tagRGBQUAD* param_1);
    long resolution();
    long time_delay();
    short frames();
    void start();
    void reset();
    uchar draw(TDrawArea* param_1, long param_2, long param_3);
    void literal();
    void delta_flc();
    void delta_fli();
    void black();
    void byte_run();

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
