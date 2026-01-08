#pragma once
#include "../common.h"

class RGE_Flic_Player       {
public:
    uchar* flic_buffer;                      // 0x0
    int flic_handle;                         // 0x4
    FlicHead flichead;                       // 0x8
    TDrawArea* drawarea;                     // 0x8C
    long drawarea_width;                     // 0x90
    long flic_width;                         // 0x94
    uchar* window_buffer;                    // 0x98
    uchar* save_buffer;                      // 0x9C
    char* chunk;                             // 0xA0
    long x1;                                 // 0xA4
    long y1;                                 // 0xA8
    long x2;                                 // 0xAC
    long y2;                                 // 0xB0
    long flic_size_x;                        // 0xB4
    long flic_size_y;                        // 0xB8

    RGE_Flic_Player(char* param_1);
    RGE_Flic_Player(int param_1);

    // --- Non-Virtual Destructor ---
    ~RGE_Flic_Player() noexcept(false);
    // --- Non-Virtual Members ---
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
};

static_assert(sizeof(RGE_Flic_Player) == 0xBC, "RGE_Flic_Player Size Mismatch");
static_assert(offsetof(RGE_Flic_Player, flic_size_y) == 0xB8, "RGE_Flic_Player Offset Mismatch");

