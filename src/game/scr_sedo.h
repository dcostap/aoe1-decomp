#pragma once
#include "../common.h"

class TRIBE_Screen_Sed_Open : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TListPanel* list;                        // 0x47C
    TScrollBarPanel* scrollbar;              // 0x480
    TButtonPanel* okButton;                  // 0x484
    TButtonPanel* cancelButton;              // 0x488
    TButtonPanel* deleteButton;              // 0x48C

    TRIBE_Screen_Sed_Open();
    virtual ~TRIBE_Screen_Sed_Open();
    virtual void fillList();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TRIBE_Screen_Sed_Open) == 0x490, "TRIBE_Screen_Sed_Open Size Mismatch");
static_assert(offsetof(TRIBE_Screen_Sed_Open, deleteButton) == 0x48C, "TRIBE_Screen_Sed_Open Offset Mismatch");

