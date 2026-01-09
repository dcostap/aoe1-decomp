#pragma once
#include "common.h"

class TribeSPMenuScreen : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TButtonPanel* button[7];                 // 0x47C
    TButtonPanel* close_button;              // 0x498

    virtual long handle_idle();                             // vt0[19]+0x4C=0x4B6C90
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x4B6CC0
    TribeSPMenuScreen();
    ~TribeSPMenuScreen();
};

static_assert(sizeof(TribeSPMenuScreen) == 0x49C, "TribeSPMenuScreen Size Mismatch");

