#pragma once
#include "common.h"

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

    virtual long handle_idle();                             // vt0[19]+0x4C=0x491A80
    virtual long handle_user_command(uint param_1, long param_2); // vt0[25]+0x64=0x491B20
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x491E20
    TribeJoinScreen();
    ~TribeJoinScreen();
    void fillList();
};

static_assert(sizeof(TribeJoinScreen) == 0x4B0, "TribeJoinScreen Size Mismatch");

class TribeMPCreateDialog : public TDialogPanel {
public:
    TTextPanel* title;                       // 0x490
    TTextPanel* input_title;                 // 0x494
    TEditPanel* inputGamename;               // 0x498
    TButtonPanel* okButton;                  // 0x49C
    TButtonPanel* cancelButton;              // 0x4A0

    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x4923C0
    TribeMPCreateDialog(TPanel* param_1);
    ~TribeMPCreateDialog();
};

static_assert(sizeof(TribeMPCreateDialog) == 0x4A4, "TribeMPCreateDialog Size Mismatch");

