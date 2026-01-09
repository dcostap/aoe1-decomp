#pragma once
#include "common.h"

class TRIBE_Screen_Info : public TScreenPanel {
public:
    int auto_close;                          // 0x478
    ulong timer;                             // 0x47C
    ulong last_time;                         // 0x480

    virtual long handle_idle();                             // vt0[19]+0x4C=0x49D610
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[33]+0x84=0x49D6B0
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x49D690
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x49D6C0
    TRIBE_Screen_Info(char* param_1, char* param_2, long param_3, ulong param_4);
    ~TRIBE_Screen_Info();
    void close_screen();
};

static_assert(sizeof(TRIBE_Screen_Info) == 0x484, "TRIBE_Screen_Info Size Mismatch");

