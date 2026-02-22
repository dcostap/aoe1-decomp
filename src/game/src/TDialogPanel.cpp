#include "../include/TDialogPanel.h"

#include "../include/TPanelSystem.h"
#include "../include/TDrawArea.h"
#include "../include/custom_debug.h"

extern TPanelSystem* panel_system;

TDialogPanel::TDialogPanel() : TEasy_Panel(nullptr) {
    // Fully verified. Source of truth: pnl_dlg.cpp.decomp @ 0x00473C10
    this->text_font_id = 0xB;
    this->input_font_id = 0xB;
    this->button_font_id = 0xB;
    this->dlg_wnd = nullptr;
    this->save_parent_child = nullptr;
    this->button_sound_id = 0;
}

TDialogPanel::TDialogPanel(char* name) : TEasy_Panel(name) {
    // Fully verified. Source of truth: pnl_dlg.cpp.decomp @ 0x00473C10
    this->text_font_id = 0xB;
    this->input_font_id = 0xB;
    this->button_font_id = 0xB;
    this->dlg_wnd = nullptr;
    this->save_parent_child = nullptr;
    this->button_sound_id = 0;
}

TDialogPanel::~TDialogPanel() {
    // Fully verified. Source of truth: pnl_dlg.cpp.decomp @ 0x00473E40
    if (panel_system) {
        const int restored = panel_system->restorePreviousModalPanel();
        if (restored == 0) {
            panel_system->setModalPanel(nullptr);
        }
    }

    if (this->parent_panel != nullptr) {
        this->parent_panel->set_redraw(TPanel::RedrawMode::RedrawFull);
        this->parent_panel->set_curr_child(this->save_parent_child);
    }
}

long TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TEasy_Panel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void TDialogPanel::set_rect(tagRECT param_1) { TEasy_Panel::set_rect(param_1); }
void TDialogPanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TEasy_Panel::set_rect(param_1, param_2, param_3, param_4); }
void TDialogPanel::set_color(uchar param_1) { TEasy_Panel::set_color(param_1); }
void TDialogPanel::set_active(int param_1) { TEasy_Panel::set_active(param_1); }
void TDialogPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TEasy_Panel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TDialogPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TEasy_Panel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TDialogPanel::set_redraw(RedrawMode param_1) { TEasy_Panel::set_redraw(param_1); }
void TDialogPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TEasy_Panel::set_overlapped_redraw(param_1, param_2, param_3); }
void TDialogPanel::draw_setup(int param_1) { TEasy_Panel::draw_setup(param_1); }
void TDialogPanel::draw_finish() { TEasy_Panel::draw_finish(); }
void TDialogPanel::draw() { TEasy_Panel::draw(); }
void TDialogPanel::draw_rect(tagRECT* param_1) { TEasy_Panel::draw_rect(param_1); }
void TDialogPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TEasy_Panel::draw_offset(param_1, param_2, param_3); }
void TDialogPanel::draw_rect2(tagRECT* param_1) { TEasy_Panel::draw_rect2(param_1); }
void TDialogPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TEasy_Panel::draw_offset2(param_1, param_2, param_3); }
void TDialogPanel::paint() { TEasy_Panel::paint(); }
long TDialogPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TEasy_Panel::wnd_proc(param_1, param_2, param_3, param_4); }
long TDialogPanel::handle_idle() { return TEasy_Panel::handle_idle(); }
long TDialogPanel::handle_size(long param_1, long param_2) { return TEasy_Panel::handle_size(param_1, param_2); }
long TDialogPanel::handle_paint() { return TEasy_Panel::handle_paint(); }
long TDialogPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TEasy_Panel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TDialogPanel::handle_char(long param_1, short param_2) { return TEasy_Panel::handle_char(param_1, param_2); }
long TDialogPanel::handle_command(uint param_1, long param_2) { return TEasy_Panel::handle_command(param_1, param_2); }
long TDialogPanel::handle_user_command(uint param_1, long param_2) { return TEasy_Panel::handle_user_command(param_1, param_2); }
long TDialogPanel::handle_timer_command(uint param_1, long param_2) { return TEasy_Panel::handle_timer_command(param_1, param_2); }
long TDialogPanel::handle_scroll(long param_1, long param_2) { return TEasy_Panel::handle_scroll(param_1, param_2); }
long TDialogPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TEasy_Panel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TDialogPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TDialogPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TEasy_Panel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TDialogPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TEasy_Panel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TDialogPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TDialogPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TEasy_Panel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TDialogPanel::char_action(long param_1, short param_2) { return TEasy_Panel::char_action(param_1, param_2); }
long TDialogPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TEasy_Panel::action(param_1, param_2, param_3, param_4); }
void TDialogPanel::get_true_render_rect(tagRECT* param_1) { TEasy_Panel::get_true_render_rect(param_1); }
int TDialogPanel::is_inside(long param_1, long param_2) { return TEasy_Panel::is_inside(param_1, param_2); }
void TDialogPanel::set_focus(int param_1) { TEasy_Panel::set_focus(param_1); }
void TDialogPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { TEasy_Panel::set_tab_order(param_1, param_2); }
void TDialogPanel::set_tab_order(TPanel** param_1, short param_2) { TEasy_Panel::set_tab_order(param_1, param_2); }
uchar TDialogPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TEasy_Panel::get_help_info(param_1, param_2, param_3, param_4); }
void TDialogPanel::stop_sound_system() { TEasy_Panel::stop_sound_system(); }
int TDialogPanel::restart_sound_system() { return TEasy_Panel::restart_sound_system(); }
void TDialogPanel::take_snapshot() { TEasy_Panel::take_snapshot(); }
void TDialogPanel::handle_reactivate() { TEasy_Panel::handle_reactivate(); }
void TDialogPanel::draw_background(int param_1) { TEasy_Panel::draw_background(param_1); }
void TDialogPanel::set_ideal_size(long param_1, long param_2) { TEasy_Panel::set_ideal_size(param_1, param_2); }
int TDialogPanel::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TEasy_Panel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TDialogPanel::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TEasy_Panel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TDialogPanel::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    return TEasy_Panel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TDialogPanel::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    return TEasy_Panel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TDialogPanel::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TEasy_Panel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TDialogPanel::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) {
    return TEasy_Panel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TDialogPanel::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TEasy_Panel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TDialogPanel::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) {
    return TEasy_Panel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10);
}
int TDialogPanel::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) {
    return TEasy_Panel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12);
}
int TDialogPanel::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TEasy_Panel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
int TDialogPanel::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) {
    return TEasy_Panel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
int TDialogPanel::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    return TEasy_Panel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TDialogPanel::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TEasy_Panel::create_auto_scrollbar(param_1, param_2, param_3); }
int TDialogPanel::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TEasy_Panel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
int TDialogPanel::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TEasy_Panel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
void TDialogPanel::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TEasy_Panel::position_panel(param_1, param_2, param_3, param_4, param_5); }

int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long wid, long hgt, char* info_file, long info_id, int enable_ime) {
    // Fully verified. Source of truth: pnl_dlg.cpp.decomp @ 0x00473C80
    int parent_w = 0;
    int parent_h = 0;
    if (param_2 == nullptr) {
        parent_w = (param_1 != nullptr) ? (int)param_1->Width : 0;
        parent_h = (param_1 != nullptr) ? (int)param_1->Height : 0;
    } else {
        parent_w = (int)param_2->width();
        parent_h = (int)param_2->height();
        (void)param_2->xPosition();
        (void)param_2->yPosition();
    }

    const long x = (long)(parent_w / 2) - wid / 2;
    const long y = (long)(parent_h / 2) - hgt / 2;
    const long ok = TEasy_Panel::setup(param_1, param_2, info_file, info_id, 0, x, y, wid, hgt, enable_ime);
    if (ok == 0) {
        this->error_code = 1;
        return 0;
    }

    if (this->parent_panel != nullptr) {
        this->save_parent_child = this->parent_panel->curr_child;
        this->parent_panel->set_curr_child(this);
    }

    this->set_z_order('\x01', 0);
    if (panel_system) {
        panel_system->setModalPanel(this);
    }
    return 1;
}

int TDialogPanel::setup(TDrawArea* param_1, TPanel* param_2, long wid, long hgt, uchar color, int enable_ime) {
    // Fully verified. Source of truth: pnl_dlg.cpp.decomp @ 0x00473D60
    int parent_w = 0;
    int parent_h = 0;
    if (param_2 == nullptr) {
        parent_w = (param_1 != nullptr) ? (int)param_1->Width : 0;
        parent_h = (param_1 != nullptr) ? (int)param_1->Height : 0;
    } else {
        parent_w = (int)param_2->width();
        parent_h = (int)param_2->height();
    }

    const long x = (long)(parent_w / 2) - wid / 2;
    const long y = (long)(parent_h / 2) - hgt / 2;
    const long ok = TEasy_Panel::setup(param_1, param_2, (char*)0, -1, 0, x, y, wid, hgt, enable_ime);
    if (ok == 0) {
        this->error_code = 1;
        return 0;
    }

    this->set_color(color);
    this->set_z_order('\x01', 0);
    if (panel_system) {
        panel_system->setModalPanel(this);
    }

    if (this->parent_panel != nullptr) {
        this->save_parent_child = this->parent_panel->curr_child;
        this->parent_panel->set_curr_child(this);
    }
    return 1;
}

