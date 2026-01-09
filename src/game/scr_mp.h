#pragma once
#include "common.h"

class TribeMPStartupScreen : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TTextPanel* inputTitle;                  // 0x47C
    TEditPanel* input;                       // 0x480
    TTextPanel* connectionTitle;             // 0x484
    TButtonPanel* okButton;                  // 0x488
    TButtonPanel* cancelButton;              // 0x48C
    TButtonPanel* help_button;               // 0x490
    TButtonPanel* close_button;              // 0x494
    TListPanel* list;                        // 0x498
    TScrollBarPanel* scrollbar;              // 0x49C
    char zone_exec[255];                     // 0x4A0
    char browser_exec[255];                  // 0x59F

    virtual long handle_idle();                             // vt0[19]+0x4C=0x49F9A0
    virtual long handle_user_command(uint param_1, long param_2); // vt0[25]+0x64=0x4A00A0
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x49F9D0
    TribeMPStartupScreen();
    ~TribeMPStartupScreen();
    void fillList();
};

static_assert(sizeof(TribeMPStartupScreen) == 0x6A0, "TribeMPStartupScreen Size Mismatch");

