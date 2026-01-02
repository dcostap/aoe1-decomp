#pragma once
#include "../common.h"

class TRIBE_Screen_Sed_Menu : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TButtonPanel* button[4];                 // 0x47C
    TButtonPanel* close_button;              // 0x48C

    TRIBE_Screen_Sed_Menu();
    virtual ~TRIBE_Screen_Sed_Menu();
    virtual long handle_idle();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TRIBE_Screen_Sed_Menu) == 0x490, "TRIBE_Screen_Sed_Menu Size Mismatch");
static_assert(offsetof(TRIBE_Screen_Sed_Menu, close_button) == 0x48C, "TRIBE_Screen_Sed_Menu Offset Mismatch");

