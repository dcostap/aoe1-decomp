#ifndef AOE1_DLG_SMSG_H
#define AOE1_DLG_SMSG_H

// This header owns the two send-message dialog classes. The dialog base comes
// from its canonical owner. Other UI, game, and communication types are used
// through pointers and stay forward-declared here.
#include "pnl_dlg.h"

class TPanel;
class TTextPanel;
class TEditPanel;
class TButtonPanel;
class TShape;
class TScreenPanel;

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

typedef char dlg_smsg_message_size[
    (sizeof(TribeSendMessageDialog) == 0x54C) ? 1 : -1];

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

typedef char dlg_smsg_quick_size[
    (sizeof(TribeSendQuickMessageDialog) == 0x49C) ? 1 : -1];

#endif
