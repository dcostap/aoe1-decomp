
#include "../include/pnl_dlg.h"

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

int TDialogPanel::setup(TDrawArea* render_area_in, TPanel* parent_in,
                        long wid_in, long hgt_in, char* info_file_name_in,
                        long resource_file_id, int allow_shadow_area_in)
{
    int height;
    int width;

    if (parent_in) {
        width = parent_in->width();
        height = parent_in->height();
        parent_in->xPosition();
        parent_in->yPosition();
    } else {
        width = render_area_in->Width;
        height = render_area_in->Height;
    }

    if (TEasy_Panel::setup(render_area_in, parent_in, info_file_name_in,
                           resource_file_id, 0,
                           width / 2 - wid_in / 2,
                           height / 2 - hgt_in / 2,
                           wid_in, hgt_in, allow_shadow_area_in) == 0) {
        this->error_code = 1;
        return 0;
    }

    if (this->parent_panel) {
        this->save_parent_child = this->parent_panel->curr_child;
        this->parent_panel->set_curr_child(this);
    }

    this->set_z_order(1, 0);
    panel_system.setModalPanel(this);

    return 1;
}

int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3,
                        long param_4, unsigned char param_5, int param_6)
{
    int width;
    int height;

    if (param_2) {
        width = param_2->width();
        height = param_2->height();
    } else {
        width = param_1->Width;
        height = param_1->Height;
    }

    if (TEasy_Panel::setup(param_1, param_2, 0, -1, 0,
                           width / 2 - param_3 / 2,
                           height / 2 - param_4 / 2,
                           param_3, param_4, param_6) == 0) {
        this->error_code = 1;
        return 0;
    }

    this->set_color(param_5);
    this->set_z_order(1, 0);
    panel_system.setModalPanel(this);

    TPanel* parent = this->parent_panel;
    if (parent) {
        this->save_parent_child = parent->curr_child;
        parent->set_curr_child(this);
    }

    return 1;
}

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

void TDialogPanel::set_focus(int focus)
{
    TEasy_Panel::set_focus(focus);
}
