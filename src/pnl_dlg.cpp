// PDB source module: C:/msdev/work/age1_x1/pnl_dlg.cpp.
// Definitions follow the original source-line and address order.
// The nearby vector-deleting destructor is compiler-generated.

#include "../include/pnl_dlg.h"

// pnl_dlg.cpp:33-34
TDialogPanel::TDialogPanel(char* name)
    : TEasy_Panel(name)
    , dlg_wnd(0)
    , save_parent_child(0)
    , text_font_id(0xB)
    , input_font_id(0xB)
    , button_font_id(0xB)
    , button_sound_id(0)
{
}

// pnl_dlg.cpp:40-81
int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3,
                        long param_4, char* param_5, long param_6, int param_7)
{
    int height;
    int width;

    if (param_2) {
        width = param_2->width();
        height = param_2->height();
        param_2->xPosition();
        param_2->yPosition();
    } else {
        width = param_1->Width;
        height = param_1->Height;
    }

    if (((TEasy_Panel*)this)->setup(param_1, param_2, param_5, param_6, 0,
                                    width / 2 - param_3 / 2,
                                    height / 2 - param_4 / 2,
                                    param_3, param_4, param_7) == 0) {
        this->error_code = 1;
        return 0;
    }

    TPanel* p = this->parent_panel;
    if (p) {
        this->save_parent_child = p->curr_child;
        p->set_curr_child((TPanel*)this);
    }

    ((TPanel*)this)->set_z_order(1, 0);
    panel_system.setModalPanel((TPanel*)this);

    return 1;
}

// pnl_dlg.cpp:87-124
// BINARY NOTE: This overload colors the panel before modal updates.
int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3,
                        long param_4, unsigned char param_5, int param_6)
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

    if (TEasy_Panel::setup(param_1, param_2, (char*)0, -1, 0,
                           width / 2 - param_3 / 2,
                           height / 2 - param_4 / 2,
                           param_3, param_4, param_6) == 0) {
        this->error_code = 1;
        return 0;
    }

    this->set_color(param_5);
    this->set_z_order(1, 0);
    panel_system.setModalPanel(this);

    if (this->parent_panel) {
        this->save_parent_child = this->parent_panel->curr_child;
        this->parent_panel->set_curr_child(this);
    }

    return 1;
}

// pnl_dlg.cpp:130-144
TDialogPanel::~TDialogPanel()
{
    if (panel_system.restorePreviousModalPanel() == 0) {
        panel_system.setModalPanel(0);
    }

    if (this->parent_panel) {
        this->parent_panel->set_redraw(TPanel::RedrawImmediate);
        this->parent_panel->set_curr_child(this->save_parent_child);
    }
}

// pnl_dlg.cpp:150-152
void TDialogPanel::set_focus(int focus)
{
    TEasy_Panel::set_focus(focus);
}
