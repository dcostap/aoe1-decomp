#ifndef AOE1_SCR_MP_H
#define AOE1_SCR_MP_H

// PDB source module: C:\msdev\work\age1_x1\scr_mp.cpp.
#include "Pnl_scr.h"

class TTextPanel;
class TEditPanel;
class TButtonPanel;
class TListPanel;
class TScrollBarPanel;

class TribeMPStartupScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* inputTitle;
    TEditPanel* input;
    TTextPanel* connectionTitle;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    TButtonPanel* close_button;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    char zone_exec[255];
    char browser_exec[255];
    unsigned char _pad_end[2];

    virtual ~TribeMPStartupScreen();
    TribeMPStartupScreen();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_idle();
    virtual long handle_user_command(unsigned int, long);

protected:
    void fillList();
};

typedef char scr_mp_startup_screen_size_check[
    (sizeof(TribeMPStartupScreen) == 0x6A0) ? 1 : -1];

#endif
