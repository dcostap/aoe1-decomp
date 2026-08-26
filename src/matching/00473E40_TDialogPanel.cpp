// 00473E40 TDialogPanel::~TDialogPanel
// Source: pnl_dlg.cpp lines 130-144
// Size: 128 bytes
//
// BINARY NOTE: The shipped destructor restores the modal panel, asks the
// parent to redraw with mode 2, restores the saved child, and then destroys
// the TEasy_Panel base. The /GX flag is part of this function's source context.
//
// CONTEXT GATE:
// - PROVED PDB module: C:\\msdev\\work\\age1_x1\\pnl_dlg.cpp.
// - PROVED source band: lines 130-144; order is after short setup.
// - PROVED class owner: TDialogPanel.
// - PROVED address sequence: 00473C10, 00473C80, 00473D60, 00473E40,
//   00473EC0.
// - PROVED exact anchors: constructor 00473C10, long setup 00473C80, and
//   set_focus 00473EC0 match in the grouped candidate TU.
// - PROVED exact source change: direct parent member use removes the extra
//   saved register and preserves the original boundary.
//
// Attempt log:
// - Grouped baseline: MISMATCH, 97 bytes, two boundary escapes.
// - Exact transition: replace the parent local with direct parent member
//   expressions. Grouped result became MATCH, 0.0000%, with no escapes or
//   relocation target mismatches.
// - Walkback: restoring the parent local returned MISMATCH, 97 bytes, and two
//   boundary escapes. The direct form is required.
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

    if (this->parent_panel) {
        this->parent_panel->set_redraw(2);
        this->parent_panel->set_curr_child(this->save_parent_child);
    }

}
