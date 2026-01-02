#pragma once
#include "../common.h"

class TribeSelectTribeScreen : public TScreenPanel {
public:
    TPicturePanel* background;               // 0x478
    TTextPanel* title;                       // 0x47C
    TTextPanel* tribeText;                   // 0x480
    TButtonPanel* tribeButton[9];            // 0x484
    TButtonPanel* okButton;                  // 0x4A8
    TButtonPanel* cancelButton;              // 0x4AC
    char** screenText;                       // 0x4B0
    int numLines;                            // 0x4B4

    TribeSelectTribeScreen();
    virtual ~TribeSelectTribeScreen();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void fillTribeText(int param_1);
    virtual char* tribeName(int param_1);
};

static_assert(sizeof(TribeSelectTribeScreen) == 0x4B8, "TribeSelectTribeScreen Size Mismatch");
static_assert(offsetof(TribeSelectTribeScreen, numLines) == 0x4B4, "TribeSelectTribeScreen Offset Mismatch");

