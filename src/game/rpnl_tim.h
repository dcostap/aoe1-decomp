#pragma once
#include "common.h"

class RGE_Panel_Time : public TPanel {
public:
    void* font;                              // 0xF4
    long game_time;                          // 0xF8
    long last_game_time;                     // 0xFC
    long old_time;                           // 0x100
    long real_time;                          // 0x104

    virtual void draw();                                    // vt0[12]+0x30=0x48A740
    virtual long handle_idle();                             // vt0[19]+0x4C=0x48AA70
    RGE_Panel_Time(TDrawArea* param_1, TPanel* param_2, void* param_3);
    ~RGE_Panel_Time();
};

static_assert(sizeof(RGE_Panel_Time) == 0x108, "RGE_Panel_Time Size Mismatch");

