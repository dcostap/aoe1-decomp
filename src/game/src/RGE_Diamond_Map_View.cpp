#include "RGE_Diamond_Map_View.h"

RGE_Diamond_Map_View::~RGE_Diamond_Map_View() {
}

// -----------------------------------------------------------------------------
// Virtual forwarding layer (header redeclares TPanel virtuals)
// -----------------------------------------------------------------------------

long RGE_Diamond_Map_View::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return RGE_Diamond_Map::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void RGE_Diamond_Map_View::set_rect(tagRECT param_1) { RGE_Diamond_Map::set_rect(param_1); }
void RGE_Diamond_Map_View::set_rect(long param_1, long param_2, long param_3, long param_4) { RGE_Diamond_Map::set_rect(param_1, param_2, param_3, param_4); }
void RGE_Diamond_Map_View::set_color(uchar param_1) { RGE_Diamond_Map::set_color(param_1); }
void RGE_Diamond_Map_View::set_active(int param_1) { RGE_Diamond_Map::set_active(param_1); }
void RGE_Diamond_Map_View::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    RGE_Diamond_Map::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void RGE_Diamond_Map_View::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { RGE_Diamond_Map::set_fixed_position(param_1, param_2, param_3, param_4); }
void RGE_Diamond_Map_View::set_redraw(RedrawMode param_1) { RGE_Diamond_Map::set_redraw(param_1); }
void RGE_Diamond_Map_View::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { RGE_Diamond_Map::set_overlapped_redraw(param_1, param_2, param_3); }
void RGE_Diamond_Map_View::draw_setup(int param_1) { RGE_Diamond_Map::draw_setup(param_1); }
void RGE_Diamond_Map_View::draw_finish() { RGE_Diamond_Map::draw_finish(); }
void RGE_Diamond_Map_View::draw() { RGE_Diamond_Map::draw(); }
void RGE_Diamond_Map_View::draw_rect(tagRECT* param_1) { RGE_Diamond_Map::draw_rect(param_1); }
void RGE_Diamond_Map_View::draw_offset(long param_1, long param_2, tagRECT* param_3) { RGE_Diamond_Map::draw_offset(param_1, param_2, param_3); }
void RGE_Diamond_Map_View::draw_rect2(tagRECT* param_1) { RGE_Diamond_Map::draw_rect2(param_1); }
void RGE_Diamond_Map_View::draw_offset2(long param_1, long param_2, tagRECT* param_3) { RGE_Diamond_Map::draw_offset2(param_1, param_2, param_3); }
void RGE_Diamond_Map_View::paint() { RGE_Diamond_Map::paint(); }
long RGE_Diamond_Map_View::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return RGE_Diamond_Map::wnd_proc(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::handle_idle() { return RGE_Diamond_Map::handle_idle(); }
long RGE_Diamond_Map_View::handle_size(long param_1, long param_2) { return RGE_Diamond_Map::handle_size(param_1, param_2); }
long RGE_Diamond_Map_View::handle_paint() { return RGE_Diamond_Map::handle_paint(); }
long RGE_Diamond_Map_View::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return RGE_Diamond_Map::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map_View::handle_char(long param_1, short param_2) { return RGE_Diamond_Map::handle_char(param_1, param_2); }
long RGE_Diamond_Map_View::handle_command(uint param_1, long param_2) { return RGE_Diamond_Map::handle_command(param_1, param_2); }
long RGE_Diamond_Map_View::handle_user_command(uint param_1, long param_2) { return RGE_Diamond_Map::handle_user_command(param_1, param_2); }
long RGE_Diamond_Map_View::handle_timer_command(uint param_1, long param_2) { return RGE_Diamond_Map::handle_timer_command(param_1, param_2); }
long RGE_Diamond_Map_View::handle_scroll(long param_1, long param_2) { return RGE_Diamond_Map::handle_scroll(param_1, param_2); }
long RGE_Diamond_Map_View::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return RGE_Diamond_Map::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map_View::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::handle_mouse_move(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return RGE_Diamond_Map::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map_View::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return RGE_Diamond_Map::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map_View::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_move_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map_View::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return RGE_Diamond_Map::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map_View::char_action(long param_1, short param_2) { return RGE_Diamond_Map::char_action(param_1, param_2); }
long RGE_Diamond_Map_View::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return RGE_Diamond_Map::action(param_1, param_2, param_3, param_4); }
void RGE_Diamond_Map_View::get_true_render_rect(tagRECT* param_1) { RGE_Diamond_Map::get_true_render_rect(param_1); }
int RGE_Diamond_Map_View::is_inside(long param_1, long param_2) { return RGE_Diamond_Map::is_inside(param_1, param_2); }
void RGE_Diamond_Map_View::set_focus(int param_1) { RGE_Diamond_Map::set_focus(param_1); }
void RGE_Diamond_Map_View::set_tab_order(TPanel* param_1, TPanel* param_2) { RGE_Diamond_Map::set_tab_order(param_1, param_2); }
void RGE_Diamond_Map_View::set_tab_order(TPanel** param_1, short param_2) { RGE_Diamond_Map::set_tab_order(param_1, param_2); }
uchar RGE_Diamond_Map_View::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return RGE_Diamond_Map::get_help_info(param_1, param_2, param_3, param_4); }
void RGE_Diamond_Map_View::stop_sound_system() { RGE_Diamond_Map::stop_sound_system(); }
int RGE_Diamond_Map_View::restart_sound_system() { return RGE_Diamond_Map::restart_sound_system(); }
void RGE_Diamond_Map_View::take_snapshot() { RGE_Diamond_Map::take_snapshot(); }
void RGE_Diamond_Map_View::handle_reactivate() { RGE_Diamond_Map::handle_reactivate(); }
void RGE_Diamond_Map_View::draw_selected_area() { RGE_Diamond_Map::draw_selected_area(); }
void RGE_Diamond_Map_View::draw_objects() { RGE_Diamond_Map::draw_objects(); }
void RGE_Diamond_Map_View::draw_visible_object(RGE_Static_Object* param_1, uchar param_2, uchar param_3) { RGE_Diamond_Map::draw_visible_object(param_1, param_2, param_3); }
void RGE_Diamond_Map_View::draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5) { RGE_Diamond_Map::draw_object(param_1, param_2, param_3, param_4, param_5); }
void RGE_Diamond_Map_View::draw_view_rect() { RGE_Diamond_Map::draw_view_rect(); }

int RGE_Diamond_Map_View::command_make_do(long param_1, long param_2) {
    // TODO: STUB: vw_dimap.cpp parity not yet transliterated; needed for link/vtable completeness.
    (void)param_1;
    (void)param_2;
    return 0;
}

int RGE_Diamond_Map_View::command_make_move(long param_1, long param_2) {
    // TODO: STUB: vw_dimap.cpp parity not yet transliterated; needed for link/vtable completeness.
    (void)param_1;
    (void)param_2;
    return 0;
}

int RGE_Diamond_Map_View::command_make_work(long param_1, long param_2) {
    // TODO: STUB: vw_dimap.cpp parity not yet transliterated; needed for link/vtable completeness.
    (void)param_1;
    (void)param_2;
    return 0;
}

