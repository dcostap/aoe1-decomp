#pragma once
#include "../common.h"

class TribeEndScreen : public TScreenPanel {
public:
    TPicturePanel* background;               // 0x478
    TTextPanel* title;                       // 0x47C
    TTextPanel* text;                        // 0x480
    TButtonPanel* okButton;                  // 0x484

    TribeEndScreen(char* param_1, char** param_2, int param_3);
    virtual ~TribeEndScreen();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TribeEndScreen) == 0x488, "TribeEndScreen Size Mismatch");
static_assert(offsetof(TribeEndScreen, okButton) == 0x484, "TribeEndScreen Offset Mismatch");

