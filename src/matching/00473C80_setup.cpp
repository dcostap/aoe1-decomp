// TDialogPanel::setup (long signature)
// VA: 00473C80
// PDB: pnl_dlg.cpp:40-81
//
// Attempt log:
// - draft 1: locals width/height → VC5 allocates width=ebp, height=stack (orig: width=ebx, height=ebp)
// - draft 2: void-cast xPosition/yPosition → same register allocation issue
// - draft 3: no locals, inline math in each branch → 84.5% diff, wrong structure (TEasy_Panel::setup called twice)
// - draft 4: restored single-call form, still ~79% diff
// Remaining: VC5 register allocation fundamentally differs from original.
// Left in scratch until TU-context can unlock the right codegen family.

#include "..\..\include\game_globals.h"

class TDrawArea {
public:
    char gap_00[0x18];
    int Width;   // +0x18
    int Height;  // +0x1C
};

class TPanel {
public:
    char gap_00[0x3C];
    int curr_child; // +0x3C

    long width();
    long height();
    long xPosition();
    long yPosition();
    void set_curr_child(TPanel* child);
    void set_z_order(unsigned char z, int order);
};

class TPanelSystem {
public:
    void setModalPanel(TPanel* panel);
};

TPanelSystem panel_system;

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void setTitle(unsigned char);
    char gap_04[0x474];
    int setup(TDrawArea* param_1, TPanel* param_2, char* param_5, long param_6, int zero, long center_x, long center_y, long param_3, long param_4, int param_7);
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap[0x18];
    virtual int setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7);
};

int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7)
{
    int height;
    int width;

    if (param_2) {
        width = param_2->width();
        height = param_2->height();
        (void)param_2->xPosition();
        (void)param_2->yPosition();
    } else {
        width = param_1->Width;
        height = param_1->Height;
    }

    if (((TEasy_Panel*)this)->setup(param_1, param_2, param_5, param_6, 0, width / 2 - param_3 / 2, height / 2 - param_4 / 2, param_3, param_4, param_7) == 0) {
        *(int*)((char*)this + 0xD8) = 1;
        return 0;
    }

    TPanel* p = *(TPanel**)((char*)this + 0x40);
    if (p) {
        *(int*)((char*)this + 0x47C) = p->curr_child;
        p->set_curr_child((TPanel*)this);
    }

    ((TPanel*)this)->set_z_order(1, 0);
    panel_system.setModalPanel((TPanel*)this);

    return 1;
}
