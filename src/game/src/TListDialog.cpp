#include "../include/TListDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TListPanel.h"
#include "../include/TPanel.h"
#include "../include/TTextPanel.h"

TListDialog::TListDialog() : TDialogPanel() {
    // Fully verified. Source of truth: dlg_list.cpp.decomp @ 0x0043EE70
    this->list_id = -1;
    this->title = nullptr;
    this->list = nullptr;
    this->scroll_bar = nullptr;
    this->ok_btn = nullptr;
    this->cancel_btn = nullptr;
    this->list_name = nullptr;
}

TListDialog::TListDialog(char* name) : TDialogPanel(name) {
    // Fully verified. Source of truth: dlg_list.cpp.decomp @ 0x0043EE70
    this->list_id = -1;
    this->title = nullptr;
    this->list = nullptr;
    this->scroll_bar = nullptr;
    this->ok_btn = nullptr;
    this->cancel_btn = nullptr;
    this->list_name = nullptr;
}

TListDialog::~TListDialog() {
    // Fully verified. Source of truth: dlg_list.cpp.decomp @ 0x0043EEE0
    if (this->title != nullptr) {
        delete this->title;
        this->title = nullptr;
    }
    if (this->list != nullptr) {
        delete this->list;
        this->list = nullptr;
    }
    if (this->scroll_bar != nullptr) {
        delete this->scroll_bar;
        this->scroll_bar = nullptr;
    }
    if (this->ok_btn != nullptr) {
        delete this->ok_btn;
        this->ok_btn = nullptr;
    }
    if (this->cancel_btn != nullptr) {
        delete this->cancel_btn;
        this->cancel_btn = nullptr;
    }
}

long TListDialog::setup(TPanel* parent, char* info_file, long info_id, long wid, long hgt, long title_x, long title_y, long title_w, long title_h, char* title_text, long list_x, long list_y, long list_w, long list_h, char** list_text, short list_size, short list_line, long ok_x, long btn_w, long btn_y, long cancel_x, long btn_h) {
    // Fully verified. Source of truth: dlg_list.cpp.decomp @ 0x0043EF80
    TDrawArea* draw_area = (parent != nullptr) ? parent->render_area : nullptr;
    const int ok = TDialogPanel::setup(draw_area, parent, wid, hgt, info_file, info_id, 1);
    if (ok == 0) {
        return 0;
    }

    if ((title_text != nullptr) && (*title_text != '\0')) {
        const int ok_title = this->create_text((TPanel*)this, &this->title, title_text, title_x, title_y, title_w, title_h, 4, 1, 1, 1);
        if (ok_title == 0) {
            return 0;
        }
    }

    const int ok_list = this->create_list((TPanel*)this, &this->list, list_x, list_y, list_w, list_h, 0xB);
    if (ok_list == 0) {
        return 0;
    }

    const int ok_scroll = this->create_auto_scrollbar(&this->scroll_bar, (TTextPanel*)this->list, 0x14);
    if (ok_scroll == 0) {
        return 0;
    }

    if (list_text != nullptr) {
        this->list->set_text(list_text, list_size);
    }

    this->list_id = list_line;
    this->list->scroll_cur_line('\x01', list_line, 1);

    const int ok_ok = this->create_button((TPanel*)this, &this->ok_btn, 0xFA1, 0, ok_x, btn_y, btn_w, btn_h, 0, 0, 0);
    if (ok_ok == 0) {
        return 0;
    }

    const int ok_cancel = this->create_button((TPanel*)this, &this->cancel_btn, 0xFA2, 0, cancel_x, btn_y, btn_w, btn_h, 0, 0, 0);
    if (ok_cancel == 0) {
        return 0;
    }

    this->cancel_btn->hotkey = 0x1B;
    this->cancel_btn->hotkey_shift = 0;
    this->set_curr_child((TPanel*)this->list);
    return 1;
}

long TListDialog::setup(TPanel* parent, char* info_file, long info_id, long wid, long hgt, long title_x, long title_y, long title_w, long title_h, int title_resid, long list_x, long list_y, long list_w, long list_h, char** list_text, short list_size, short list_line, long ok_x, long btn_w, long btn_y, long cancel_x, long btn_h) {
    // Fully verified. Source of truth: dlg_list.cpp.decomp @ 0x0043F130
    char str[256];
    this->get_string(title_resid, str + 4, 0x100);
    return this->setup(parent, info_file, info_id, wid, hgt, title_x, title_y, title_w, title_h, str + 4, list_x, list_y, list_w, list_h, list_text, list_size, list_line, ok_x, btn_w, btn_y, cancel_x, btn_h);
}

// ---- Virtual forwarders (keep vtable shape stable, behavior in base) ----
long TListDialog::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TDialogPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void TListDialog::set_rect(tagRECT param_1) { TDialogPanel::set_rect(param_1); }
void TListDialog::set_rect(long param_1, long param_2, long param_3, long param_4) { TDialogPanel::set_rect(param_1, param_2, param_3, param_4); }
void TListDialog::set_color(uchar param_1) { TDialogPanel::set_color(param_1); }
void TListDialog::set_active(int param_1) { TDialogPanel::set_active(param_1); }
void TListDialog::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TDialogPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TListDialog::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TDialogPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TListDialog::set_redraw(RedrawMode param_1) { TDialogPanel::set_redraw(param_1); }
void TListDialog::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TDialogPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TListDialog::draw_setup(int param_1) { TDialogPanel::draw_setup(param_1); }
void TListDialog::draw_finish() { TDialogPanel::draw_finish(); }
void TListDialog::draw() { TDialogPanel::draw(); }
void TListDialog::draw_rect(tagRECT* param_1) { TDialogPanel::draw_rect(param_1); }
void TListDialog::draw_offset(long param_1, long param_2, tagRECT* param_3) { TDialogPanel::draw_offset(param_1, param_2, param_3); }
void TListDialog::draw_rect2(tagRECT* param_1) { TDialogPanel::draw_rect2(param_1); }
void TListDialog::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TDialogPanel::draw_offset2(param_1, param_2, param_3); }
void TListDialog::paint() { TDialogPanel::paint(); }
long TListDialog::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TDialogPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TListDialog::handle_idle() { return TDialogPanel::handle_idle(); }
long TListDialog::handle_size(long param_1, long param_2) { return TDialogPanel::handle_size(param_1, param_2); }
long TListDialog::handle_paint() { return TDialogPanel::handle_paint(); }
long TListDialog::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TDialogPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TListDialog::handle_char(long param_1, short param_2) { return TDialogPanel::handle_char(param_1, param_2); }
long TListDialog::handle_command(uint param_1, long param_2) { return TDialogPanel::handle_command(param_1, param_2); }
long TListDialog::handle_user_command(uint param_1, long param_2) { return TDialogPanel::handle_user_command(param_1, param_2); }
long TListDialog::handle_timer_command(uint param_1, long param_2) { return TDialogPanel::handle_timer_command(param_1, param_2); }
long TListDialog::handle_scroll(long param_1, long param_2) { return TDialogPanel::handle_scroll(param_1, param_2); }
long TListDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TListDialog::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TListDialog::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TDialogPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TListDialog::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TDialogPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TListDialog::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TListDialog::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }

long TListDialog::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: dlg_list.cpp.decomp @ 0x0043F210
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    return 0;
}

long TListDialog::char_action(long param_1, short param_2) { return TDialogPanel::char_action(param_1, param_2); }

long TListDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Fully verified. Source of truth: dlg_list.cpp.decomp @ 0x0043F220
    if (param_1 != nullptr) {
        if ((TButtonPanel*)param_1 == this->ok_btn) {
            if (param_2 == 1) {
                const int line = this->list->currentLineNumber();
                this->list_id = (short)line;
                this->list_name = this->list->currentLine();
                if (this->parent_panel != nullptr) {
                    this->parent_panel->action((TPanel*)this, 1, 0, 0);
                }
                return 1;
            }
        } else if ((TButtonPanel*)param_1 == this->cancel_btn) {
            if (param_2 == 1) {
                if (this->parent_panel != nullptr) {
                    this->parent_panel->action((TPanel*)this, 2, 0, 0);
                }
                return 1;
            }
        } else if (((TListPanel*)param_1 == this->list) && (param_2 == 3)) {
            const int line = this->list->currentLineNumber();
            this->list_id = (short)line;
            this->list_name = this->list->currentLine();
            if (this->parent_panel != nullptr) {
                this->parent_panel->action((TPanel*)this, 1, 0, 0);
            }
            return 1;
        }
    }
    return TDialogPanel::action(param_1, param_2, param_3, param_4);
}

void TListDialog::get_true_render_rect(tagRECT* param_1) { TDialogPanel::get_true_render_rect(param_1); }
int TListDialog::is_inside(long param_1, long param_2) { return TDialogPanel::is_inside(param_1, param_2); }
void TListDialog::set_focus(int param_1) { TDialogPanel::set_focus(param_1); }
void TListDialog::set_tab_order(TPanel* param_1, TPanel* param_2) { TDialogPanel::set_tab_order(param_1, param_2); }
void TListDialog::set_tab_order(TPanel** param_1, short param_2) { TDialogPanel::set_tab_order(param_1, param_2); }
uchar TListDialog::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TDialogPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TListDialog::stop_sound_system() { TDialogPanel::stop_sound_system(); }
int TListDialog::restart_sound_system() { return TDialogPanel::restart_sound_system(); }
void TListDialog::take_snapshot() { TDialogPanel::take_snapshot(); }
void TListDialog::handle_reactivate() { TDialogPanel::handle_reactivate(); }
void TListDialog::draw_background(int param_1) { TDialogPanel::draw_background(param_1); }
void TListDialog::set_ideal_size(long param_1, long param_2) { TDialogPanel::set_ideal_size(param_1, param_2); }
int TListDialog::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TDialogPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TListDialog::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TDialogPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int TListDialog::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TDialogPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TListDialog::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TDialogPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TListDialog::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TDialogPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TListDialog::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TDialogPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TListDialog::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TDialogPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TListDialog::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TDialogPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TListDialog::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TDialogPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TListDialog::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TDialogPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TListDialog::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TDialogPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TListDialog::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TDialogPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TListDialog::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TDialogPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TListDialog::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TDialogPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TListDialog::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TDialogPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TListDialog::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TDialogPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
int TListDialog::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, uchar param_5, int param_6) { return TDialogPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6); }
int TListDialog::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7) { return TDialogPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }

short TListDialog::get_list_id() {
    // Fully verified. Source of truth: dlg_list.cpp.decomp @ 0x0043F320
    return this->list_id;
}

char* TListDialog::get_list_name() {
    // Fully verified. Source of truth: dlg_list.cpp.decomp @ 0x0043F330
    return this->list_name;
}

