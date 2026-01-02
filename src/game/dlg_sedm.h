#pragma once
#include "../common.h"

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TRIBE_Screen_Sed* scenario_editor;       // 0x490
    TTextPanel* title;                       // 0x494
    TButtonPanel* buttons[7];                // 0x498

    TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* param_1);
    virtual ~TRIBE_Dialog_Sed_Menu();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TRIBE_Dialog_Sed_Menu) == 0x4B4, "TRIBE_Dialog_Sed_Menu Size Mismatch");
static_assert(offsetof(TRIBE_Dialog_Sed_Menu, buttons) == 0x498, "TRIBE_Dialog_Sed_Menu Offset Mismatch");

