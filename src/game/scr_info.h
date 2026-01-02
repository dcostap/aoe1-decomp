#pragma once
#include "../common.h"

class TRIBE_Screen_Info : public TScreenPanel {
public:
    int auto_close;                          // 0x478
    ulong timer;                             // 0x47C
    ulong last_time;                         // 0x480

    TRIBE_Screen_Info(char* param_1, char* param_2, long param_3, ulong param_4);
    virtual ~TRIBE_Screen_Info();
    virtual long handle_idle();
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void close_screen();
};

static_assert(sizeof(TRIBE_Screen_Info) == 0x484, "TRIBE_Screen_Info Size Mismatch");
static_assert(offsetof(TRIBE_Screen_Info, last_time) == 0x480, "TRIBE_Screen_Info Offset Mismatch");

