#pragma once

#define IMPLEMENT_TDIALOGPANEL_FORWARDERS(CLASS, BASE) \
long CLASS::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return BASE::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } \
void CLASS::set_rect(tagRECT param_1) { BASE::set_rect(param_1); } \
void CLASS::set_rect(long param_1, long param_2, long param_3, long param_4) { BASE::set_rect(param_1, param_2, param_3, param_4); } \
void CLASS::set_color(uchar param_1) { BASE::set_color(param_1); } \
void CLASS::set_active(int param_1) { BASE::set_active(param_1); } \
void CLASS::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { BASE::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); } \
void CLASS::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { BASE::set_fixed_position(param_1, param_2, param_3, param_4); } \
void CLASS::set_redraw(RedrawMode param_1) { BASE::set_redraw(param_1); } \
void CLASS::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { BASE::set_overlapped_redraw(param_1, param_2, param_3); } \
void CLASS::draw_setup(int param_1) { BASE::draw_setup(param_1); } \
void CLASS::draw_finish() { BASE::draw_finish(); } \
void CLASS::draw_rect(tagRECT* param_1) { BASE::draw_rect(param_1); } \
void CLASS::draw_offset(long param_1, long param_2, tagRECT* param_3) { BASE::draw_offset(param_1, param_2, param_3); } \
void CLASS::draw_rect2(tagRECT* param_1) { BASE::draw_rect2(param_1); } \
void CLASS::draw_offset2(long param_1, long param_2, tagRECT* param_3) { BASE::draw_offset2(param_1, param_2, param_3); } \
void CLASS::paint() { BASE::paint(); } \
long CLASS::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return BASE::wnd_proc(param_1, param_2, param_3, param_4); } \
long CLASS::handle_idle() { return BASE::handle_idle(); } \
long CLASS::handle_size(long param_1, long param_2) { return BASE::handle_size(param_1, param_2); } \
long CLASS::handle_paint() { return BASE::handle_paint(); } \
long CLASS::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return BASE::handle_key_down(param_1, param_2, param_3, param_4, param_5); } \
long CLASS::handle_char(long param_1, short param_2) { return BASE::handle_char(param_1, param_2); } \
long CLASS::handle_command(uint param_1, long param_2) { return BASE::handle_command(param_1, param_2); } \
long CLASS::handle_user_command(uint param_1, long param_2) { return BASE::handle_user_command(param_1, param_2); } \
long CLASS::handle_timer_command(uint param_1, long param_2) { return BASE::handle_timer_command(param_1, param_2); } \
long CLASS::handle_scroll(long param_1, long param_2) { return BASE::handle_scroll(param_1, param_2); } \
long CLASS::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return BASE::handle_mouse_move(param_1, param_2, param_3, param_4); } \
long CLASS::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return BASE::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); } \
long CLASS::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return BASE::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); } \
long CLASS::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_move_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_left_down_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_left_hold_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_left_move_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_left_up_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_right_down_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_right_hold_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_right_move_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_right_up_action(param_1, param_2, param_3, param_4); } \
long CLASS::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return BASE::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); } \
long CLASS::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return BASE::key_down_action(param_1, param_2, param_3, param_4, param_5); } \
long CLASS::char_action(long param_1, short param_2) { return BASE::char_action(param_1, param_2); } \
void CLASS::get_true_render_rect(tagRECT* param_1) { BASE::get_true_render_rect(param_1); } \
int CLASS::is_inside(long param_1, long param_2) { return BASE::is_inside(param_1, param_2); } \
void CLASS::set_focus(int param_1) { BASE::set_focus(param_1); } \
void CLASS::set_tab_order(TPanel* param_1, TPanel* param_2) { BASE::set_tab_order(param_1, param_2); } \
void CLASS::set_tab_order(TPanel** param_1, short param_2) { BASE::set_tab_order(param_1, param_2); } \
uchar CLASS::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return BASE::get_help_info(param_1, param_2, param_3, param_4); } \
void CLASS::stop_sound_system() { BASE::stop_sound_system(); } \
int CLASS::restart_sound_system() { return BASE::restart_sound_system(); } \
void CLASS::take_snapshot() { BASE::take_snapshot(); } \
void CLASS::handle_reactivate() { BASE::handle_reactivate(); } \
void CLASS::draw_background(int param_1) { BASE::draw_background(param_1); } \
void CLASS::set_ideal_size(long param_1, long param_2) { BASE::set_ideal_size(param_1, param_2); } \
int CLASS::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return BASE::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); } \
int CLASS::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return BASE::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); } \
int CLASS::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return BASE::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); } \
int CLASS::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return BASE::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); } \
int CLASS::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return BASE::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); } \
int CLASS::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return BASE::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); } \
int CLASS::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return BASE::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); } \
int CLASS::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return BASE::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); } \
int CLASS::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return BASE::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); } \
int CLASS::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return BASE::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } \
int CLASS::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return BASE::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } \
int CLASS::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return BASE::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); } \
int CLASS::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return BASE::create_auto_scrollbar(param_1, param_2, param_3); } \
int CLASS::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return BASE::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } \
int CLASS::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return BASE::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } \
void CLASS::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { BASE::position_panel(param_1, param_2, param_3, param_4, param_5); } \
int CLASS::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, uchar param_5, int param_6) { return BASE::setup(param_1, param_2, param_3, param_4, param_5, param_6); } \
int CLASS::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7) { return BASE::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }

