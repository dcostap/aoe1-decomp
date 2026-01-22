#include "../include/TPanel.h"
#include <string.h>

TPanel::~TPanel() {}
long TPanel::setup(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) { return 0; }
void TPanel::set_rect(tagRECT param_1) {}
void TPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {}
void TPanel::set_color(uchar param_1) {}
void TPanel::set_active(int param_1) {}
void TPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {}
void TPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {}
void TPanel::set_redraw(RedrawMode param_1) {}
void TPanel::set_overlapped_redraw(RedrawMode param_1) {}
void TPanel::draw_setup(int param_1) {}
void TPanel::draw_finish() {}
void TPanel::draw() {}
void TPanel::draw_rect(tagRECT* param_1) {}
void TPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) {}
void TPanel::draw_rect2(tagRECT* param_1) {}
void TPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) {}
void TPanel::paint() {}
long TPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return 0; }
long TPanel::handle_idle() { return 0; }
long TPanel::handle_size(long param_1, long param_2) { return 0; }
long TPanel::handle_paint() { return 0; }
long TPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TPanel::handle_char(long param_1, short param_2) { return 0; }
long TPanel::handle_command(uint param_1, long param_2) { return 0; }
long TPanel::handle_user_command(uint param_1, long param_2) { return 0; }
long TPanel::handle_timer_command(uint param_1, long param_2) { return 0; }
long TPanel::handle_scroll(long param_1, long param_2) { return 0; }
long TPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TPanel::char_action(long param_1, short param_2) { return 0; }
long TPanel::action(long param_1, ulong param_2, ulong param_3) { return 0; }
void TPanel::get_true_render_rect(tagRECT* param_1) {}
int TPanel::is_inside(long param_1, long param_2) { return 0; }
void TPanel::set_focus(int param_1) {}
void TPanel::set_tab_order() {}
void TPanel::set_tab_order(TPanel** param_1, short param_2) {}
uchar TPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return 0; }
void TPanel::stop_sound_system() {}
int TPanel::restart_sound_system() { return 1; }
void TPanel::take_snapshot() {}
void TPanel::handle_reactivate() {}
