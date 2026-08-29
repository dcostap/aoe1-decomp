#ifndef AOE1_SCR_CJ_H
#define AOE1_SCR_CJ_H

// This header owns the join screen and create-game dialog. Shared screen and
// dialog bases come from their canonical owners.
#include "pnl_dlg.h"
#include "Pnl_scr.h"
#include "game_globals.h"

class TCommunications_Handler;
class TCommunications_Sessions;
class TribeMPSetupScreen;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class TEditPanel;
class TRegistry;
class TDebuggingLog;

extern TCommunications_Sessions* Sess;

class TribeJoinScreen : public TScreenPanel {
protected:
    int startedSession;
    int listFilled;
    TTextPanel* title;
    TTextPanel* listTitle;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* joinButton;
    TButtonPanel* createButton;
    TButtonPanel* cancelButton;
    TButtonPanel* refreshButton;
    TButtonPanel* close_button;
    int game_count;
    int waitingToStart;
    unsigned long joinTime;

public:
    TribeJoinScreen();
    virtual ~TribeJoinScreen();
    virtual long handle_idle();
    virtual long handle_user_command(unsigned int, long);
    virtual long action(TPanel*, long, unsigned long, unsigned long);

protected:
    void fillList();
};

typedef char scr_cj_join_screen_size_check[
    (sizeof(TribeJoinScreen) == 0x4B0) ? 1 : -1];

class TribeMPCreateDialog : public TDialogPanel {
protected:
    TTextPanel* title;
    TTextPanel* input_title;
    TEditPanel* inputGamename;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;

public:
    virtual ~TribeMPCreateDialog();
    TribeMPCreateDialog(TPanel* parent);

protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

typedef char scr_cj_create_dialog_size_check[
    (sizeof(TribeMPCreateDialog) == 0x4A4) ? 1 : -1];

#endif
