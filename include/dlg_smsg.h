#ifndef AOE1_DLG_SMSG_H
#define AOE1_DLG_SMSG_H

// PDB owner: dlg_smsg.cpp.
// BLOCKER: dlg_smsg.cpp needs canonical call and field normalization.

#include "pnl_dlg.h"
#include "pnl_btn.h"
#include "pnl_edit.h"
#include "pnl_lst.h"
#include "Shape.h"

class TribeSendMessageDialog : public TDialogPanel {
public:
    TTextPanel* title;
    TTextPanel* playerName[8];
    TTextPanel* playerCivilization[8];
    TButtonPanel* checkButton[8];
    TTextPanel* radioTitle[4];
    TButtonPanel* radioButton[4];
    TShape* radioButtonShapes;
    TEditPanel* chatInput;
    TTextPanel* chatTitle;
    TButtonPanel* okButton;
    TButtonPanel* help_button;
    TShape* backgroundPics;
    int commPlayers[8];

    TribeSendMessageDialog(TScreenPanel*);
    virtual ~TribeSendMessageDialog();

protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void draw();
    void checkButtons();
};

class TribeSendQuickMessageDialog : public TDialogPanel {
public:
    enum Mode { AsChat = 0, AsTaunt = 1 };

    TEditPanel* chatInput;
    TTextPanel* chatTitle;
    Mode modeValue;

    TribeSendQuickMessageDialog(TScreenPanel*, Mode);
    virtual ~TribeSendQuickMessageDialog();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
};

typedef char dlg_smsg_message_size[
    (sizeof(TribeSendMessageDialog) == 0x54C) ? 1 : -1];
typedef char dlg_smsg_quick_size[
    (sizeof(TribeSendQuickMessageDialog) == 0x49C) ? 1 : -1];

#endif
