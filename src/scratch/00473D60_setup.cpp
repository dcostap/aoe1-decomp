// 00473D60 TDialogPanel::setup
// Source: pnl_dlg.cpp lines 87-124
// Size: 211 bytes
//
// BINARY NOTE: This overload uses a byte parameter and calls the inherited
// set_color virtual at vtable offset 0x10 before z-order and modal setup.
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

int TDialogPanel::setup(TDrawArea* draw_area, TPanel* parent, long width, long height,
                        unsigned char color, int panel_type)
{
    int panel_width;
    int panel_height;

    if (parent) {
        panel_width = parent->width();
        panel_height = parent->height();
    } else {
        panel_width = draw_area->Width;
        panel_height = draw_area->Height;
    }

    if (((TEasy_Panel*)this)->setup(draw_area, parent, (char*)0, -1, 0,
                                    panel_width / 2 - width / 2,
                                    panel_height / 2 - height / 2,
                                    width, height, panel_type) == 0) {
        this->error_code = 1;
        return 0;
    }

    this->set_color(color);
    this->set_z_order(1, 0);
    panel_system.setModalPanel((TPanel*)this);

    TPanel* old_parent = this->parent_panel;
    if (old_parent) {
        this->save_parent_child = old_parent->curr_child;
        old_parent->set_curr_child((TPanel*)this);
    }

    return 1;
}
