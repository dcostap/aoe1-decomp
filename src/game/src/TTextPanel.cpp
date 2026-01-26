#include "../include/TTextPanel.h"

// Constructor
TTextPanel::TTextPanel() : TPanel("Text") {}

// Destructor
TTextPanel::~TTextPanel() {}

// Virtual Implementations
long TTextPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return 1; }
void TTextPanel::set_rect(tagRECT param_1) {}
void TTextPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {}
void TTextPanel::set_color(uchar param_1) {}
void TTextPanel::set_active(int param_1) {}
void TTextPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {}
void TTextPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {}
void TTextPanel::set_redraw(RedrawMode param_1) {}
void TTextPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) {}
void TTextPanel::draw_setup(int param_1) {}
void TTextPanel::draw_finish() {}
void TTextPanel::draw() {}
void TTextPanel::draw_rect(tagRECT* param_1) {}
void TTextPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) {}
void TTextPanel::draw_rect2(tagRECT* param_1) {}
void TTextPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) {}
void TTextPanel::paint() {}
long TTextPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return 0; }
long TTextPanel::handle_idle() { return 0; }
long TTextPanel::handle_size(long param_1, long param_2) { return 0; }
long TTextPanel::handle_paint() { return 0; }
long TTextPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TTextPanel::handle_char(long param_1, short param_2) { return 0; }
long TTextPanel::handle_command(uint param_1, long param_2) { return 0; }
long TTextPanel::handle_user_command(uint param_1, long param_2) { return 0; }
long TTextPanel::handle_timer_command(uint param_1, long param_2) { return 0; }
long TTextPanel::handle_scroll(long param_1, long param_2) { return 0; }
long TTextPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TTextPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TTextPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TTextPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TTextPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TTextPanel::char_action(long param_1, short param_2) { return 0; }
long TTextPanel::action(long param_1, ulong param_2, ulong param_3) { return 0; }
void TTextPanel::get_true_render_rect(tagRECT* param_1) {}
int TTextPanel::is_inside(long param_1, long param_2) { return 0; }
void TTextPanel::set_focus(int param_1) {}
void TTextPanel::set_tab_order(TPanel* param_1, TPanel* param_2) {}
void TTextPanel::set_tab_order(TPanel** param_1, short param_2) {}
uchar TTextPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return 0; }
void TTextPanel::stop_sound_system() {}
int TTextPanel::restart_sound_system() { return 1; }
void TTextPanel::take_snapshot() {}
void TTextPanel::handle_reactivate() {}
void TTextPanel::set_text(char** param_1, short param_2) {}
void TTextPanel::set_text(long param_1) {}
void TTextPanel::set_text(char* param_1) {}
void TTextPanel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {}
