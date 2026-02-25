#include "../include/TScreenPanel.h"

TScreenPanel::TScreenPanel() : TEasy_Panel() {}

TScreenPanel::TScreenPanel(char* name) : TEasy_Panel(name) {}

TScreenPanel::~TScreenPanel() {}

// Virtual setup (base signature): forward.
long TScreenPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TEasy_Panel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

// Non-virtual overload: `Pnl_scr.cpp.decomp` / `.asm` source of truth.
long TScreenPanel::setup(TDrawArea* param_1, char* param_2, long param_3, int param_4) {
    long ok = TEasy_Panel::setup(param_1, (TPanel*)0, param_2, param_3, 1, 0, 0, 0, 0, param_4);
    return (ok != 0) ? 1 : 0;
}

// Non-virtual overload: used for blank screens in original.
long TScreenPanel::setup(TDrawArea* param_1, char* param_2, long param_3, uchar param_4, int param_5) {
    (void)param_2;
    (void)param_3;
    (void)param_4;
    long ok = TEasy_Panel::setup(param_1, (TPanel*)0, (char*)0, -1, 1, 0, 0, 0, 0, param_5);
    return (ok != 0) ? 1 : 0;
}

void TScreenPanel::set_rect(tagRECT param_1) { TEasy_Panel::set_rect(param_1); }
void TScreenPanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TEasy_Panel::set_rect(param_1, param_2, param_3, param_4); }
void TScreenPanel::set_color(uchar param_1) { TEasy_Panel::set_color(param_1); }
void TScreenPanel::set_active(int param_1) { TEasy_Panel::set_active(param_1); }
void TScreenPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TEasy_Panel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TScreenPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TEasy_Panel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TScreenPanel::set_redraw(RedrawMode param_1) { TEasy_Panel::set_redraw(param_1); }
void TScreenPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TEasy_Panel::set_overlapped_redraw(param_1, param_2, param_3); }
void TScreenPanel::draw_setup(int param_1) { TEasy_Panel::draw_setup(param_1); }
void TScreenPanel::draw_finish() { TEasy_Panel::draw_finish(); }
void TScreenPanel::draw() {
    // Fully verified. Source of truth: pnl_scr.cpp.asm @ 0x0047BB40
    TEasy_Panel::draw();
}
void TScreenPanel::draw_rect(tagRECT* param_1) { TEasy_Panel::draw_rect(param_1); }
void TScreenPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TEasy_Panel::draw_offset(param_1, param_2, param_3); }
void TScreenPanel::draw_rect2(tagRECT* param_1) { TEasy_Panel::draw_rect2(param_1); }
void TScreenPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TEasy_Panel::draw_offset2(param_1, param_2, param_3); }
void TScreenPanel::paint() { TEasy_Panel::paint(); }
long TScreenPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TEasy_Panel::wnd_proc(param_1, param_2, param_3, param_4); }
long TScreenPanel::handle_idle() { return TEasy_Panel::handle_idle(); }
long TScreenPanel::handle_size(long param_1, long param_2) { return TEasy_Panel::handle_size(param_1, param_2); }
long TScreenPanel::handle_paint() { return TEasy_Panel::handle_paint(); }
long TScreenPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TEasy_Panel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TScreenPanel::handle_char(long param_1, short param_2) { return TEasy_Panel::handle_char(param_1, param_2); }
long TScreenPanel::handle_command(uint param_1, long param_2) { return TEasy_Panel::handle_command(param_1, param_2); }
long TScreenPanel::handle_user_command(uint param_1, long param_2) { return TEasy_Panel::handle_user_command(param_1, param_2); }
long TScreenPanel::handle_timer_command(uint param_1, long param_2) { return TEasy_Panel::handle_timer_command(param_1, param_2); }
long TScreenPanel::handle_scroll(long param_1, long param_2) { return TEasy_Panel::handle_scroll(param_1, param_2); }
long TScreenPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TEasy_Panel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TScreenPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TScreenPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TEasy_Panel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TScreenPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TEasy_Panel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TScreenPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TScreenPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TEasy_Panel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TScreenPanel::char_action(long param_1, short param_2) { return TEasy_Panel::char_action(param_1, param_2); }
long TScreenPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TEasy_Panel::action(param_1, param_2, param_3, param_4); }
void TScreenPanel::get_true_render_rect(tagRECT* param_1) { TEasy_Panel::get_true_render_rect(param_1); }
int TScreenPanel::is_inside(long param_1, long param_2) { return TEasy_Panel::is_inside(param_1, param_2); }
void TScreenPanel::set_focus(int param_1) { TEasy_Panel::set_focus(param_1); }
void TScreenPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { TEasy_Panel::set_tab_order(param_1, param_2); }
void TScreenPanel::set_tab_order(TPanel** param_1, short param_2) { TEasy_Panel::set_tab_order(param_1, param_2); }
uchar TScreenPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TEasy_Panel::get_help_info(param_1, param_2, param_3, param_4); }
void TScreenPanel::stop_sound_system() { TEasy_Panel::stop_sound_system(); }
int TScreenPanel::restart_sound_system() { return TEasy_Panel::restart_sound_system(); }
void TScreenPanel::take_snapshot() { TEasy_Panel::take_snapshot(); }
void TScreenPanel::handle_reactivate() { TEasy_Panel::handle_reactivate(); }
void TScreenPanel::draw_background(int param_1) { TEasy_Panel::draw_background(param_1); }
void TScreenPanel::set_ideal_size(long param_1, long param_2) { TEasy_Panel::set_ideal_size(param_1, param_2); }
int TScreenPanel::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TEasy_Panel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TScreenPanel::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TEasy_Panel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TScreenPanel::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TEasy_Panel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TScreenPanel::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TEasy_Panel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TScreenPanel::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TEasy_Panel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TScreenPanel::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TEasy_Panel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TScreenPanel::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TEasy_Panel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TScreenPanel::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TEasy_Panel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TScreenPanel::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TEasy_Panel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TScreenPanel::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TEasy_Panel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TScreenPanel::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TEasy_Panel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TScreenPanel::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TEasy_Panel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TScreenPanel::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TEasy_Panel::create_auto_scrollbar(param_1, param_2, param_3); }
int TScreenPanel::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TEasy_Panel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TScreenPanel::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TEasy_Panel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TScreenPanel::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TEasy_Panel::position_panel(param_1, param_2, param_3, param_4, param_5); }
