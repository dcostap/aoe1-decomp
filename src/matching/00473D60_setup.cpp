// 00473D60 TDialogPanel::setup
// Source: pnl_dlg.cpp lines 87-124
// Size: 211 bytes
//
// Attempt log:
// Probe 1: quick try

#include "..\..\include\game_globals.h"

class TPanel {
public:
    char _gap_04[0x3C];
    int child_panel;
    char _gap_44[0x10];
    virtual ~TPanel();
    void set_curr_child(TPanel* child);
    void set_z_order(int p1, int p2);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_54[0x424];
    TEasy_Panel(char* param);
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    int dlg_wnd;           // +0x478
    int save_parent_child; // +0x47C
    int text_font_id;      // +0x480
    int input_font_id;     // +0x484
    int button_font_id;    // +0x488
    int button_sound_id;   // +0x48C

    TDialogPanel(char* param);
    virtual ~TDialogPanel();
    virtual int setup(void* p1, TPanel* p2, int p3, int p4, int p5, int p6);
};

// panel_system extern
extern struct TPanelSystem {
    char _gap_00[4];
    void setModalPanel(TPanel* panel);
} panel_system;

int TDialogPanel::setup(void* draw_area, TPanel* parent, int p3, int p4, int p5, int p6)
{
    int w, h;
    if (parent) {
        w = parent->width();
        h = parent->height();
    } else {
        w = *(int*)((char*)draw_area + 0x18);  // draw_area->Width
        h = *(int*)((char*)draw_area + 0x1C);  // draw_area->Height
    }

    int cx = w / 2 - p3 / 2;
    int cy = h / 2 - p4 / 2;

    int result = ((TEasy_Panel*)this)->setup(draw_area, parent, (char*)0, -1, 0, cx, cy, p3, p4, p6);
    if (result == 0) {
        *(int*)((char*)this + 0xD8) = 1;
        return 0;
    }

    // Virtual call at slot 0x10 with p5 as arg
    ((void (*)(int))(*(void***)this)[4])(p5);

    this->set_z_order(1, 0);
    panel_system.setModalPanel((TPanel*)this);

    if (this->child_panel) {
        this->save_parent_child = *(int*)(this->child_panel + 0x3C);
        ((TPanel*)this->child_panel)->set_curr_child((TPanel*)this);
    }

    return 1;
}
