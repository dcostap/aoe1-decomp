#pragma once
#include "common.h"

enum Mode : unsigned int {
    AsChat = 0,
    AsComment = 1,
};

class TribeSendMessageDialog : public TDialogPanel {
public:
    TTextPanel* title;                       // 0x490
    TTextPanel* playerName[8];               // 0x494
    TTextPanel* playerCivilization[8];       // 0x4B4
    TButtonPanel* checkButton[8];            // 0x4D4
    TTextPanel* radioTitle[4];               // 0x4F4
    TButtonPanel* radioButton[4];            // 0x504
    TShape* radioButtonShapes;               // 0x514
    TEditPanel* chatInput;                   // 0x518
    TTextPanel* chatTitle;                   // 0x51C
    TButtonPanel* okButton;                  // 0x520
    TButtonPanel* help_button;               // 0x524
    TShape* backgroundPics;                  // 0x528
    int commPlayers[8];                      // 0x52C

    virtual void draw();                                    // vt0[12]+0x30=0x441460
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x440F20
    TribeSendMessageDialog(TScreenPanel* param_1);
    ~TribeSendMessageDialog();
    void checkButtons();
};

static_assert(sizeof(TribeSendMessageDialog) == 0x54C, "TribeSendMessageDialog Size Mismatch");

class TribeSendQuickMessageDialog : public TDialogPanel {
public:
    TEditPanel* chatInput;                   // 0x490
    TTextPanel* chatTitle;                   // 0x494
    Mode modeValue;                          // 0x498

    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[28]+0x70=0x441840
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x4416C0
    TribeSendQuickMessageDialog(TScreenPanel* param_1, Mode param_2);
    ~TribeSendQuickMessageDialog();
};

static_assert(sizeof(TribeSendQuickMessageDialog) == 0x49C, "TribeSendQuickMessageDialog Size Mismatch");

