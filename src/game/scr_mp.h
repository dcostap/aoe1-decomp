#pragma once
#include "../common.h"

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

    TribeMPStartupScreen();
    virtual ~TribeMPStartupScreen();
    virtual long handle_idle();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void fillList();
    virtual long handle_user_command(uint param_1, long param_2);
};

static_assert(sizeof(TribeMPStartupScreen) == 0x6A0, "TribeMPStartupScreen Size Mismatch");
static_assert(offsetof(TribeMPStartupScreen, browser_exec) == 0x59F, "TribeMPStartupScreen Offset Mismatch");

