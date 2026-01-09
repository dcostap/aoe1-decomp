#pragma once
#include "common.h"

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TRIBE_Screen_Sed* scenario_editor;       // 0x490
    TTextPanel* title;                       // 0x494
    TButtonPanel* buttons[7];                // 0x498

    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x440400
    TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* param_1);
    ~TRIBE_Dialog_Sed_Menu();
};

static_assert(sizeof(TRIBE_Dialog_Sed_Menu) == 0x4B4, "TRIBE_Dialog_Sed_Menu Size Mismatch");

