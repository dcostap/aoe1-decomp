#include "../include/TMessageDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "../include/RGE_Base_Game.h"
#include "../include/globals.h"

extern TPanelSystem* panel_system;

// Source of truth: dlg_msg.cpp.decomp @ 0x0043FC70
TMessageDialog::TMessageDialog(char* name) : TDialogPanel(name) {
    this->dlg_type = 0;
    this->text = nullptr;
    this->button[0] = nullptr;
    this->button[1] = nullptr;
    this->button[2] = nullptr;
}

// Source of truth: dlg_msg.cpp.decomp @ 0x0043FCD0
TMessageDialog::~TMessageDialog() {
    this->delete_panel((TPanel**)&this->text);
    this->delete_panel((TPanel**)&this->button[0]);
    this->delete_panel((TPanel**)&this->button[1]);
    this->delete_panel((TPanel**)&this->button[2]);
}

// Source of truth: dlg_msg.cpp.decomp @ 0x0043FD50
long TMessageDialog::setup(TPanel* parent, char* info_file, long info_id, long wid, long hgt, uchar dlg_type_in, char* text_in, long btn_wid, long btn_hgt) {
    // Fully verified. Source of truth: dlg_msg.cpp.decomp @ 0x0043FD50
    TDrawArea* draw_area = (parent != nullptr) ? parent->render_area : nullptr;

    this->button[0] = nullptr;
    this->button[1] = nullptr;
    this->button[2] = nullptr;

    if (TDialogPanel::setup(draw_area, parent, wid, hgt, info_file, info_id, 1) == 0) {
        return 0;
    }

    this->dlg_type = dlg_type_in;

    const long panel_w = this->width();
    const long panel_h = this->height();

    if (this->create_text((TPanel*)this, &this->text, text_in, 3, 3, panel_w - 3, (panel_h - btn_hgt) - 6, 0xb, 1, 1, 1) == 0) {
        return 0;
    }

    int num_buttons = 0;
    switch (this->dlg_type) {
    case 0:
        num_buttons = 1;
        break;
    case 1:
    case 2:
    case 3:
        num_buttons = 2;
        break;
    case 4:
        num_buttons = 3;
        break;
    default:
        return 0;
    }

    int spacing = (int)panel_w - (num_buttons * (int)btn_wid);
    if (spacing < 1) {
        spacing = 0;
    } else {
        spacing = spacing / (num_buttons + 1);
    }

    const int btn_y = (int)((panel_h - btn_hgt) - 7);
    int btn_x = spacing;
    for (int i = 0; i < num_buttons; ++i) {
        if (this->create_button((TPanel*)this, &this->button[i], (char*)"", (char*)"", btn_x, btn_y, btn_wid, btn_hgt, 0xb, 0, 0) == 0) {
            return 0;
        }
        btn_x = btn_x + spacing + (int)btn_wid;
    }

    long second_text = 0;
    TButtonPanel* esc_button = nullptr;
    switch (this->dlg_type) {
    case 0: // OK
        this->button[0]->set_text(0, 0xfa1);
        break;
    case 1: // OK / Cancel
        this->button[0]->set_text(0, 0xfa1);
        second_text = 0xfa2;
        esc_button = this->button[1];
        this->button[1]->set_text(0, second_text);
        break;
    case 2: // Yes / No
        this->button[0]->set_text(0, 0xfa3);
        second_text = 0xfa4;
        esc_button = this->button[1];
        this->button[1]->set_text(0, second_text);
        break;
    case 3: // Retry / Abort
        this->button[0]->set_text(0, 0xfa5);
        second_text = 0xfa7;
        esc_button = this->button[1];
        this->button[1]->set_text(0, second_text);
        break;
    case 4: // Yes / No / Cancel
        this->button[0]->set_text(0, 0xfa3);
        this->button[1]->set_text(0, 0xfa4);
        this->button[2]->set_text(0, 0xfa2);
        esc_button = this->button[2];
        break;
    default:
        break;
    }

    if (esc_button != nullptr) {
        esc_button->hotkey = 0x1b;
        esc_button->hotkey_shift = 0;
    }

    this->set_tab_order((TPanel**)this->button, (short)num_buttons);
    this->set_curr_child((TPanel*)this->button[0]);
    return 1;
}

// Source of truth: dlg_msg.cpp.decomp @ 0x0043FFF0
long TMessageDialog::setup(TPanel* parent, char* info_file, long info_id, long wid, long hgt, uchar dlg_type_in, int text_id, long btn_wid, long btn_hgt) {
    char str[256];
    this->get_string(text_id, str, sizeof(str));
    return this->setup(parent, info_file, info_id, wid, hgt, dlg_type_in, str, btn_wid, btn_hgt);
}

// Source of truth: dlg_msg.cpp.decomp @ 0x00440070
long TMessageDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (this->parent_panel != nullptr && param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->button[0]) {
            this->parent_panel->action((TPanel*)this, 0, 0, 0);
            return 1;
        }
        if ((TButtonPanel*)param_1 == this->button[1]) {
            this->parent_panel->action((TPanel*)this, 1, 0, 0);
            return 1;
        }
        if ((TButtonPanel*)param_1 == this->button[2]) {
            this->parent_panel->action((TPanel*)this, 2, 0, 0);
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Source of truth: dlg_msg.cpp.decomp @ 0x00440100
long TMessageDialog::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    return 0;
}

// Source of truth: dlg_msg.cpp.decomp @ 0x00440110
long TMessageDialog::handle_idle() {
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

// --- Forwarding virtuals (TEasy_Panel / TDialogPanel passthrough) ---
long TMessageDialog::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TDialogPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void TMessageDialog::set_rect(tagRECT param_1) { TDialogPanel::set_rect(param_1); }
void TMessageDialog::set_rect(long param_1, long param_2, long param_3, long param_4) { TDialogPanel::set_rect(param_1, param_2, param_3, param_4); }
void TMessageDialog::set_color(uchar param_1) { TDialogPanel::set_color(param_1); }
void TMessageDialog::set_active(int param_1) { TDialogPanel::set_active(param_1); }
void TMessageDialog::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TDialogPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TMessageDialog::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TDialogPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TMessageDialog::set_redraw(RedrawMode param_1) { TDialogPanel::set_redraw(param_1); }
void TMessageDialog::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TDialogPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TMessageDialog::draw_setup(int param_1) { TDialogPanel::draw_setup(param_1); }
void TMessageDialog::draw_finish() { TDialogPanel::draw_finish(); }
void TMessageDialog::draw() { TDialogPanel::draw(); }
void TMessageDialog::draw_rect(tagRECT* param_1) { TDialogPanel::draw_rect(param_1); }
void TMessageDialog::draw_offset(long param_1, long param_2, tagRECT* param_3) { TDialogPanel::draw_offset(param_1, param_2, param_3); }
void TMessageDialog::draw_rect2(tagRECT* param_1) { TDialogPanel::draw_rect2(param_1); }
void TMessageDialog::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TDialogPanel::draw_offset2(param_1, param_2, param_3); }
void TMessageDialog::paint() { TDialogPanel::paint(); }
long TMessageDialog::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TDialogPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TMessageDialog::handle_size(long param_1, long param_2) { return TDialogPanel::handle_size(param_1, param_2); }
long TMessageDialog::handle_paint() { return TDialogPanel::handle_paint(); }
long TMessageDialog::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TDialogPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TMessageDialog::handle_char(long param_1, short param_2) { return TDialogPanel::handle_char(param_1, param_2); }
long TMessageDialog::handle_command(uint param_1, long param_2) { return TDialogPanel::handle_command(param_1, param_2); }
long TMessageDialog::handle_user_command(uint param_1, long param_2) { return TDialogPanel::handle_user_command(param_1, param_2); }
long TMessageDialog::handle_timer_command(uint param_1, long param_2) { return TDialogPanel::handle_timer_command(param_1, param_2); }
long TMessageDialog::handle_scroll(long param_1, long param_2) { return TDialogPanel::handle_scroll(param_1, param_2); }
long TMessageDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TMessageDialog::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TMessageDialog::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TDialogPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TMessageDialog::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TDialogPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TMessageDialog::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TMessageDialog::char_action(long param_1, short param_2) { return TDialogPanel::char_action(param_1, param_2); }
void TMessageDialog::get_true_render_rect(tagRECT* param_1) { TDialogPanel::get_true_render_rect(param_1); }
int TMessageDialog::is_inside(long param_1, long param_2) { return TDialogPanel::is_inside(param_1, param_2); }
void TMessageDialog::set_focus(int param_1) { TDialogPanel::set_focus(param_1); }
void TMessageDialog::set_tab_order(TPanel* param_1, TPanel* param_2) { TDialogPanel::set_tab_order(param_1, param_2); }
void TMessageDialog::set_tab_order(TPanel** param_1, short param_2) { TDialogPanel::set_tab_order(param_1, param_2); }
uchar TMessageDialog::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TDialogPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TMessageDialog::stop_sound_system() { TDialogPanel::stop_sound_system(); }
int TMessageDialog::restart_sound_system() { return TDialogPanel::restart_sound_system(); }
void TMessageDialog::take_snapshot() { TDialogPanel::take_snapshot(); }
void TMessageDialog::handle_reactivate() { TDialogPanel::handle_reactivate(); }
void TMessageDialog::draw_background(int param_1) { TDialogPanel::draw_background(param_1); }
void TMessageDialog::set_ideal_size(long param_1, long param_2) { TDialogPanel::set_ideal_size(param_1, param_2); }
int TMessageDialog::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TDialogPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TMessageDialog::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TDialogPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TMessageDialog::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    return TDialogPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TMessageDialog::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    return TDialogPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TMessageDialog::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TDialogPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TMessageDialog::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) {
    return TDialogPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TMessageDialog::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TDialogPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TMessageDialog::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) {
    return TDialogPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10);
}
int TMessageDialog::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) {
    return TDialogPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12);
}
int TMessageDialog::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TDialogPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
int TMessageDialog::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) {
    return TDialogPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
int TMessageDialog::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    return TDialogPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TMessageDialog::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TDialogPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TMessageDialog::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TDialogPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
int TMessageDialog::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TDialogPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
void TMessageDialog::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TDialogPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
int TMessageDialog::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, uchar param_5, int param_6) { return TDialogPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6); }
int TMessageDialog::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7) { return TDialogPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }

