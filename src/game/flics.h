#pragma once
#include "../common.h"

class RGE_Flic_Player {
public:
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
    virtual ~RGE_Flic_Player();
    virtual void palette(tagRGBQUAD* param_1);
    virtual long resolution();
    virtual long time_delay();
    virtual short frames();
    virtual void start();
    virtual void reset();
    virtual uchar draw(TDrawArea* param_1, long param_2, long param_3);
    virtual void literal();
    virtual void delta_flc();
    virtual void delta_fli();
    virtual void black();
    virtual void byte_run();
};

static_assert(sizeof(RGE_Flic_Player) == 0xBC, "RGE_Flic_Player Size Mismatch");
static_assert(offsetof(RGE_Flic_Player, flic_size_y) == 0xB8, "RGE_Flic_Player Offset Mismatch");

