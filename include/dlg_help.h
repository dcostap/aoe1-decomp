#ifndef AOE1_DLG_HELP_H
#define AOE1_DLG_HELP_H

// This header owns THelpDialog.
#include "pnl_dlg.h"
#include "pnl_btn.h"
#include "pnl_lst.h"
#include "basegame.h"

typedef int (__stdcall *GDI_WinHelpA)(HWND, char*, unsigned int, char*);
extern GDI_WinHelpA _WinHelpA;

class THelpDialog : public TDialogPanel {
public:
    int help_page_id;
    char parent_panel[0x100];
    TTextPanel* title;
    TTextPanel* list;
    TButtonPanel* ok_button;
    TButtonPanel* encyclopedia_button;
    THelpDialog(TEasy_Panel*, char*, long, long, long, long);
    THelpDialog(TEasy_Panel*, char*, char*, long, long, long);
    virtual ~THelpDialog();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
protected:
    void setup_help(TEasy_Panel*, char*, char*, long, long, long);
};

typedef char dlg_help_dialog_size_check[
    (sizeof(THelpDialog) == 0x5A4) ? 1 : -1];

#endif
