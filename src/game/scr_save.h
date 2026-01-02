#pragma once
#include "../common.h"

class TribeSaveGameScreen : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TEditPanel* input;                       // 0x47C
    TListPanel* list;                        // 0x480
    TScrollBarPanel* scrollbar;              // 0x484
    TButtonPanel* okButton;                  // 0x488
    TButtonPanel* cancelButton;              // 0x48C
    TButtonPanel* deleteButton;              // 0x490
    char fileName[260];                      // 0x494
    char fileNameNoExt[260];                 // 0x598
    Mode modeValue;                          // 0x69C
    int quit_after_save;                     // 0x6A0

    TribeSaveGameScreen(Mode param_1, char* param_2, int param_3);
    virtual ~TribeSaveGameScreen();
    virtual void fillList();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void save_for_scenario_editor();
};

static_assert(sizeof(TribeSaveGameScreen) == 0x6A4, "TribeSaveGameScreen Size Mismatch");
static_assert(offsetof(TribeSaveGameScreen, quit_after_save) == 0x6A0, "TribeSaveGameScreen Offset Mismatch");

