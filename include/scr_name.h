#ifndef AOE1_SCR_NAME_H
#define AOE1_SCR_NAME_H

// PDB source module: C:/msdev/work/age1_x1/scr_name.cpp.
// This header owns only the two screen types from scr_name.cpp. Shared panel,
// dialog, and screen types come from their canonical owners.
#include "pnl_dlg.h"
#include "Pnl_scr.h"

class TTextPanel;
class TEditPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class TRIBE_Screen_Campaign_Selection;
class TribeSPMenuScreen;

class TRIBE_Screen_Name : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* name_text;
    TListPanel* name_list;
    TScrollBarPanel* name_scrollbar;
    TButtonPanel* new_button;
    TButtonPanel* remove_button;
    TButtonPanel* ok_button;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;
    int started_input;

    TRIBE_Screen_Name();
    virtual ~TRIBE_Screen_Name();
    void init_vars();

protected:
    void get_player_names();
    void setup_tab_order();

public:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_idle();
};

typedef char scr_name_screen_size_check[
    (sizeof(TRIBE_Screen_Name) == 0x4A0) ? 1 : -1];

class TRIBE_Dialog_Name : public TDialogPanel {
public:
    TTextPanel* title;
    TTextPanel* name_text;
    TEditPanel* name_input;
    TButtonPanel* ok_button;
    TButtonPanel* cancel_button;

    TRIBE_Dialog_Name(TScreenPanel*);
    virtual ~TRIBE_Dialog_Name();
    long action(TPanel*, long, unsigned long, unsigned long);
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
};

typedef char scr_name_dialog_size_check[
    (sizeof(TRIBE_Dialog_Name) == 0x4A4) ? 1 : -1];

#endif
