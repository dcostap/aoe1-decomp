#pragma once
#include "../common.h"

class RGE_Panel_Time : public TPanel {
public:
    void* font;                              // 0xF4
    long game_time;                          // 0xF8
    long last_game_time;                     // 0xFC
    long old_time;                           // 0x100
    long real_time;                          // 0x104

    RGE_Panel_Time(TDrawArea* param_1, TPanel* param_2, void* param_3);
    virtual ~RGE_Panel_Time();
    virtual void draw();
    virtual long handle_idle();
};

static_assert(sizeof(RGE_Panel_Time) == 0x108, "RGE_Panel_Time Size Mismatch");
static_assert(offsetof(RGE_Panel_Time, real_time) == 0x104, "RGE_Panel_Time Offset Mismatch");

