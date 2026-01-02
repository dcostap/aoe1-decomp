#pragma once
#include "../common.h"

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;                      // 0x478
    int listFilled;                          // 0x47C
    TTextPanel* title;                       // 0x480
    TTextPanel* listTitle;                   // 0x484
    TListPanel* list;                        // 0x488
    TScrollBarPanel* scrollbar;              // 0x48C
    TButtonPanel* joinButton;                // 0x490
    TButtonPanel* createButton;              // 0x494
    TButtonPanel* cancelButton;              // 0x498
    TButtonPanel* refreshButton;             // 0x49C
    TButtonPanel* close_button;              // 0x4A0
    int game_count;                          // 0x4A4
    int waitingToStart;                      // 0x4A8
    ulong joinTime;                          // 0x4AC

    TribeJoinScreen();
    virtual ~TribeJoinScreen();
    virtual long handle_idle();
    virtual long handle_user_command(uint param_1, long param_2);
    virtual void fillList();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TribeJoinScreen) == 0x4B0, "TribeJoinScreen Size Mismatch");
static_assert(offsetof(TribeJoinScreen, joinTime) == 0x4AC, "TribeJoinScreen Offset Mismatch");

class TribeMPCreateDialog : public TDialogPanel {
public:
    TTextPanel* title;                       // 0x490
    TTextPanel* input_title;                 // 0x494
    TEditPanel* inputGamename;               // 0x498
    TButtonPanel* okButton;                  // 0x49C
    TButtonPanel* cancelButton;              // 0x4A0

    TribeMPCreateDialog(TPanel* param_1);
    virtual ~TribeMPCreateDialog();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TribeMPCreateDialog) == 0x4A4, "TribeMPCreateDialog Size Mismatch");
static_assert(offsetof(TribeMPCreateDialog, cancelButton) == 0x4A0, "TribeMPCreateDialog Offset Mismatch");

