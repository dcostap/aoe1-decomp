#ifndef AOE1_DLG_HELP_H
#define AOE1_DLG_HELP_H

// This header owns THelpDialog.
#include "pnl_dlg.h"
#include "pnl_btn.h"
#include "pnl_lst.h"
#include "basegame.h"

class THelpDialog : public TDialogPanel {
  public:
    int help_page_id;
    char parent_panel[0x100];
    TTextPanel* title;
    TTextPanel* list;
    TButtonPanel* ok_button;
    TButtonPanel* encyclopedia_button;
    THelpDialog(
        TEasy_Panel* parentPanel, char* in_parent_panel, long help_string_id, long in_help_page_id, long x, long y
    );
    THelpDialog(
        TEasy_Panel* parentPanel, char* in_parent_panel, char* in_help_string, long in_help_page_id, long x, long y
    );
    virtual ~THelpDialog();
    virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
    virtual long handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key);

  protected:
    void setup_help(
        TEasy_Panel* parentPanel, char* in_parent_panel, char* help_string, long in_help_page_id, long mouse_x,
        long mouse_y
    );
};

typedef char dlg_help_dialog_size_check[(sizeof(THelpDialog) == 0x5A4) ? 1 : -1];

#endif
