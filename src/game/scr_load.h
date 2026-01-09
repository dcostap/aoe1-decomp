#pragma once
#include "common.h"

class TribeLoadSavedGameScreen : public TScreenPanel {
public:
    TTextPanel* screenTitle;                 // 0x478
    TTextPanel* listTitle;                   // 0x47C
    TListPanel* list;                        // 0x480
    TScrollBarPanel* scrollbar;              // 0x484
    TButtonPanel* okButton;                  // 0x488
    TButtonPanel* cancelButton;              // 0x48C
    TButtonPanel* deleteButton;              // 0x490

    virtual long handle_idle();                             // vt0[19]+0x4C=0x49E2B0
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x49E2E0
    TribeLoadSavedGameScreen();
    ~TribeLoadSavedGameScreen();
    void fillList();
};

static_assert(sizeof(TribeLoadSavedGameScreen) == 0x494, "TribeLoadSavedGameScreen Size Mismatch");

