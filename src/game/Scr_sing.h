#pragma once
#include "../common.h"

class TribeSPMenuScreen : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TButtonPanel* button[7];                 // 0x47C
    TButtonPanel* close_button;              // 0x498

    TribeSPMenuScreen();
    virtual ~TribeSPMenuScreen();
    virtual long handle_idle();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TribeSPMenuScreen) == 0x49C, "TribeSPMenuScreen Size Mismatch");
static_assert(offsetof(TribeSPMenuScreen, close_button) == 0x498, "TribeSPMenuScreen Offset Mismatch");

