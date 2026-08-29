#ifndef AOE1_PNL_DLG_H
#define AOE1_PNL_DLG_H

// This header owns TDialogPanel. Its base comes from panel_ez.h.
#include "panel_ez.h"

class TDialogPanel : public TEasy_Panel {
public:
    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;

    TDialogPanel(char*);
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea*, TPanel*, long, long, unsigned char, int);
    virtual int setup(TDrawArea*, TPanel*, long, long, char*, long, int);
    virtual void set_focus(int);
};

typedef char pnl_dlg_tdialog_size_check[
    (sizeof(TDialogPanel) == 0x490) ? 1 : -1];

#endif
