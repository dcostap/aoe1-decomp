#include "../include/RGE_Main_View.h"

#include "../include/TPanel.h"

RGE_Main_View::RGE_Main_View()
    : RGE_View() {
    // Partially verified. Source of truth: vw_main.cpp.decomp @ 0x0053DAB0.
    this->map_view = nullptr;
    this->last_mouse_scroll_time = 0;
    this->mouse_scrolling = 0;
    this->mouse_last_x = -1;
    this->mouse_last_y = -1;
    this->last_key_scroll_time = 0;
    this->key_scrolling = 0;
    this->save_player = nullptr;
}

RGE_Main_View::~RGE_Main_View() {}

long RGE_Main_View::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return RGE_View::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

void RGE_Main_View::set_rect(tagRECT param_1) { RGE_View::set_rect(param_1); }
void RGE_Main_View::set_rect(long param_1, long param_2, long param_3, long param_4) { RGE_View::set_rect(param_1, param_2, param_3, param_4); }

void RGE_Main_View::set_color(uchar param_1) { TPanel::set_color(param_1); }
void RGE_Main_View::set_active(int param_1) { TPanel::set_active(param_1); }
void RGE_Main_View::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void RGE_Main_View::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void RGE_Main_View::set_redraw(RedrawMode param_1) { TPanel::set_redraw(param_1); }
void RGE_Main_View::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void RGE_Main_View::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void RGE_Main_View::draw_finish() { TPanel::draw_finish(); }
void RGE_Main_View::draw() { RGE_View::draw(); }
void RGE_Main_View::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); }
void RGE_Main_View::draw_offset(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset(param_1, param_2, param_3); }
void RGE_Main_View::draw_rect2(tagRECT* param_1) { TPanel::draw_rect2(param_1); }
void RGE_Main_View::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset2(param_1, param_2, param_3); }
void RGE_Main_View::paint() { TPanel::paint(); }
long RGE_Main_View::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TPanel::wnd_proc(param_1, param_2, param_3, param_4); }

long RGE_Main_View::handle_idle() {
    // Partially verified. Source of truth: vw_main.cpp.decomp @ 0x0053DB40.
    return TPanel::handle_idle();
}

long RGE_Main_View::handle_size(long param_1, long param_2) { return TPanel::handle_size(param_1, param_2); }
long RGE_Main_View::handle_paint() { return TPanel::handle_paint(); }
long RGE_Main_View::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Main_View::handle_char(long param_1, short param_2) { return TPanel::handle_char(param_1, param_2); }
long RGE_Main_View::handle_command(uint param_1, long param_2) { return TPanel::handle_command(param_1, param_2); }
long RGE_Main_View::handle_user_command(uint param_1, long param_2) { return TPanel::handle_user_command(param_1, param_2); }
long RGE_Main_View::handle_timer_command(uint param_1, long param_2) { return TPanel::handle_timer_command(param_1, param_2); }
long RGE_Main_View::handle_scroll(long param_1, long param_2) { return TPanel::handle_scroll(param_1, param_2); }
long RGE_Main_View::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Main_View::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long RGE_Main_View::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long RGE_Main_View::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long RGE_Main_View::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long RGE_Main_View::char_action(long param_1, short param_2) { return TPanel::char_action(param_1, param_2); }
long RGE_Main_View::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TPanel::action(param_1, param_2, param_3, param_4); }
void RGE_Main_View::get_true_render_rect(tagRECT* param_1) { TPanel::get_true_render_rect(param_1); }
int RGE_Main_View::is_inside(long param_1, long param_2) { return TPanel::is_inside(param_1, param_2); }
void RGE_Main_View::set_focus(int param_1) { RGE_View::set_focus(param_1); }
void RGE_Main_View::set_tab_order(TPanel* param_1, TPanel* param_2) { TPanel::set_tab_order(param_1, param_2); }
void RGE_Main_View::set_tab_order(TPanel** param_1, short param_2) { TPanel::set_tab_order(param_1, param_2); }
uchar RGE_Main_View::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TPanel::get_help_info(param_1, param_2, param_3, param_4); }
void RGE_Main_View::stop_sound_system() { TPanel::stop_sound_system(); }
int RGE_Main_View::restart_sound_system() { return TPanel::restart_sound_system(); }
void RGE_Main_View::take_snapshot() { TPanel::take_snapshot(); }
void RGE_Main_View::handle_reactivate() { TPanel::handle_reactivate(); }

int RGE_Main_View::pick_through_fog(RGE_Static_Object* param_1) { return RGE_View::pick_through_fog(param_1); }
int RGE_Main_View::pick_weight(RGE_Static_Object* param_1, int param_2) { return RGE_View::pick_weight(param_1, param_2); }
int RGE_Main_View::start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return RGE_View::start_scroll_view(param_1, param_2, param_3, param_4, param_5); }
int RGE_Main_View::handle_scroll_view(long param_1, long param_2) { return RGE_View::handle_scroll_view(param_1, param_2); }
void RGE_Main_View::end_scroll_view() { RGE_View::end_scroll_view(); }
int RGE_Main_View::do_paint(long param_1, long param_2, long param_3, long param_4, int param_5) { return RGE_View::do_paint(param_1, param_2, param_3, param_4, param_5); }
void RGE_Main_View::draw_multi_object_outline() { RGE_View::draw_multi_object_outline(); }

int RGE_Main_View::command_place_object(long param_1, long param_2, int param_3) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    return 0;
}
int RGE_Main_View::command_make_do(long param_1, long param_2, int param_3, short param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}
int RGE_Main_View::command_make_move(long param_1, long param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}
int RGE_Main_View::command_make_work(long param_1, long param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}
int RGE_Main_View::command_place_multi_object(long param_1, long param_2, long param_3, long param_4, int param_5) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    return 0;
}

