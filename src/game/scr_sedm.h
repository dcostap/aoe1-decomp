#pragma once
#include "common.h"

class TRIBE_Screen_Sed_Menu : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TButtonPanel* button[4];                 // 0x47C
    TButtonPanel* close_button;              // 0x48C

    virtual long handle_idle();                             // vt0[19]+0x4C=0x4B31A0
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x4B31D0
    TRIBE_Screen_Sed_Menu();
    ~TRIBE_Screen_Sed_Menu();
};

static_assert(sizeof(TRIBE_Screen_Sed_Menu) == 0x490, "TRIBE_Screen_Sed_Menu Size Mismatch");

