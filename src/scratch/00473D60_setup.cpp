// 00473D60 TDialogPanel::setup
// Source: pnl_dlg.cpp lines 87-124
// Size: 211 bytes
//
// BINARY NOTE: This overload uses a byte parameter and calls the inherited
// set_color virtual at vtable offset 0x10 before z-order and modal setup.
//
// CONTEXT GATE:
// - PROVED PDB module: C:\\msdev\\work\\age1_x1\\pnl_dlg.cpp.
// - PROVED source band: lines 87-124; order is after the long setup overload.
// - PROVED class owner: TDialogPanel.
// - PROVED address sequence: 00473C10, 00473C80, 00473D60, 00473E40,
//   00473EC0.
// - PROVED exact anchors: constructor 00473C10, long setup 00473C80, and
//   set_focus 00473EC0 match in the grouped candidate TU.
// - LIKELY source shape: two size locals, one base setup call, then modal and
//   parent-child updates.
// - UNKNOWN: the short setup's original local and register allocation shape.
//
// Attempt log:
// - Grouped baseline: anchors MATCH; short setup MISMATCH, 196 bytes.
// - Tested declaration order, local aliases, branch polarity, named centers,
//   result local, and call spelling. None recovered the missing prologue and
//   register allocation. Restored the natural source after each test.
#ifndef PNL_DLG_TU_CONTEXT
#include "..\..\include\game_globals.h"

class TDrawArea {
public:
    char gap_00[0x18];
    long Width;
    long Height;
};

class TPanel {
public:
    char gap_00[0x3C];
    TPanel* curr_child;
    TPanel* parent_panel;
    long width();
    long height();
    void set_curr_child(TPanel*);
    void set_z_order(char, int);
    virtual void set_color(unsigned char);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long, long, int);
};

class TDialogPanel : public TEasy_Panel {
public:
    int error_code;
    int gap_DC[0x27];
    TPanel* save_parent_child;
    virtual int setup(TDrawArea*, TPanel*, long, long, unsigned char, int);
};

class TPanelSystem {
public:
    void setModalPanel(TPanel*);
};

extern TPanelSystem panel_system;
#endif

int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4,
                        unsigned char param_5, int param_6)
{
    int height;
    int width;

    if (param_2) {
        width = param_2->width();
        height = param_2->height();
    } else {
        width = param_1->Width;
        height = param_1->Height;
    }

    if (((TEasy_Panel*)this)->setup(param_1, param_2, (char*)0, -1, 0,
                                    width / 2 - param_3 / 2,
                                    height / 2 - param_4 / 2,
                                    param_3, param_4, param_6) == 0) {
        this->error_code = 1;
        return 0;
    }

    this->set_color(param_5);
    this->set_z_order(1, 0);
    panel_system.setModalPanel((TPanel*)this);

    if (this->parent_panel) {
        this->save_parent_child = this->parent_panel->curr_child;
        this->parent_panel->set_curr_child((TPanel*)this);
    }

    return 1;
}
