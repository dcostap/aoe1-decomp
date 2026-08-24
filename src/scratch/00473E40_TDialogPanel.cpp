// 00473E40 TDialogPanel::~TDialogPanel
// Source: pnl_dlg.cpp lines 130-144
// Size: 128 bytes
//
// BINARY NOTE: The shipped destructor restores the modal panel, asks the
// parent to redraw with mode 2, restores the saved child, and then destroys
// the TEasy_Panel base. The /GX flag is part of this function's source context.
#ifndef PNL_DLG_TU_CONTEXT
#include "..\..\include\game_globals.h"

class TPanel {
public:
    char gap_00[0x3C];
    TPanel* curr_child;
    TPanel* parent_panel;
    virtual void set_redraw(int);
    void set_curr_child(TPanel*);
};

class TPanelSystem {
public:
    int restorePreviousModalPanel();
    void setModalPanel(TPanel*);
};

extern TPanelSystem panel_system;

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[4];
    TPanel* save_parent_child;
    char gap_480[0x10];
    virtual ~TDialogPanel();
};
#endif

TDialogPanel::~TDialogPanel()
{
    if (panel_system.restorePreviousModalPanel() == 0) {
        panel_system.setModalPanel(0);
    }

    TPanel* parent = this->parent_panel;
    if (parent) {
        parent->set_redraw(2);
        parent->set_curr_child(this->save_parent_child);
    }

}
