#pragma once
#include "../common.h"

class TribeLoadSavedGameScreen : public TScreenPanel {
public:
    TTextPanel* screenTitle;                 // 0x478
    TTextPanel* listTitle;                   // 0x47C
    TListPanel* list;                        // 0x480
    TScrollBarPanel* scrollbar;              // 0x484
    TButtonPanel* okButton;                  // 0x488
    TButtonPanel* cancelButton;              // 0x48C
    TButtonPanel* deleteButton;              // 0x490

    TribeLoadSavedGameScreen();
    virtual ~TribeLoadSavedGameScreen();
    virtual void fillList();
    virtual long handle_idle();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TribeLoadSavedGameScreen) == 0x494, "TribeLoadSavedGameScreen Size Mismatch");
static_assert(offsetof(TribeLoadSavedGameScreen, deleteButton) == 0x490, "TribeLoadSavedGameScreen Offset Mismatch");

