#pragma once
#include "common.h"

class TRIBE_Screen_Sed_Open : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TListPanel* list;                        // 0x47C
    TScrollBarPanel* scrollbar;              // 0x480
    TButtonPanel* okButton;                  // 0x484
    TButtonPanel* cancelButton;              // 0x488
    TButtonPanel* deleteButton;              // 0x48C

    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x4B38A0
    TRIBE_Screen_Sed_Open();
    ~TRIBE_Screen_Sed_Open();
    void fillList();
};

static_assert(sizeof(TRIBE_Screen_Sed_Open) == 0x490, "TRIBE_Screen_Sed_Open Size Mismatch");

