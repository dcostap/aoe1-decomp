#include "TRIBE_Diamond_Map_View.h"

#include "TRIBE_Screen_Game.h"
#include "debug_helpers.h"

TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View() {
    // Fully verified. Source of truth: tvw_dmap.cpp.asm @ 0x0052C9E0
    this->last_attack_time = 0;
    this->flash_on = 0;
}

TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View() {
}

// -----------------------------------------------------------------------------
// Virtual forwarding layer (header redeclares TPanel virtuals)
// -----------------------------------------------------------------------------

long TRIBE_Diamond_Map_View::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return RGE_Diamond_Map_View::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void TRIBE_Diamond_Map_View::set_rect(tagRECT param_1) { RGE_Diamond_Map_View::set_rect(param_1); }
void TRIBE_Diamond_Map_View::set_rect(long param_1, long param_2, long param_3, long param_4) { RGE_Diamond_Map_View::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Diamond_Map_View::set_color(uchar param_1) { RGE_Diamond_Map_View::set_color(param_1); }
void TRIBE_Diamond_Map_View::set_active(int param_1) { RGE_Diamond_Map_View::set_active(param_1); }
void TRIBE_Diamond_Map_View::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    RGE_Diamond_Map_View::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TRIBE_Diamond_Map_View::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { RGE_Diamond_Map_View::set_fixed_position(param_1, param_2, param_3, param_4); }

void TRIBE_Diamond_Map_View::set_redraw(RedrawMode param_1) {
    // Fully verified. Source of truth: tvw_dmap.cpp.decomp @ 0x0052CA30
    RGE_Diamond_Map::set_redraw(param_1);

    if ((param_1 != NoRedraw && this->visible != 0) && this->active != 0) {
        ((TRIBE_Screen_Game*)this->parent_panel)->set_map_buttons_redraw(param_1);
    }
}

void TRIBE_Diamond_Map_View::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { RGE_Diamond_Map_View::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Diamond_Map_View::draw_setup(int param_1) { RGE_Diamond_Map_View::draw_setup(param_1); }
void TRIBE_Diamond_Map_View::draw_finish() { RGE_Diamond_Map_View::draw_finish(); }
void TRIBE_Diamond_Map_View::draw() { RGE_Diamond_Map_View::draw(); }
void TRIBE_Diamond_Map_View::draw_rect(tagRECT* param_1) { RGE_Diamond_Map_View::draw_rect(param_1); }
void TRIBE_Diamond_Map_View::draw_offset(long param_1, long param_2, tagRECT* param_3) { RGE_Diamond_Map_View::draw_offset(param_1, param_2, param_3); }
void TRIBE_Diamond_Map_View::draw_rect2(tagRECT* param_1) { RGE_Diamond_Map_View::draw_rect2(param_1); }
void TRIBE_Diamond_Map_View::draw_offset2(long param_1, long param_2, tagRECT* param_3) { RGE_Diamond_Map_View::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Diamond_Map_View::paint() { RGE_Diamond_Map_View::paint(); }
long TRIBE_Diamond_Map_View::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return RGE_Diamond_Map_View::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::handle_idle() { return RGE_Diamond_Map_View::handle_idle(); }
long TRIBE_Diamond_Map_View::handle_size(long param_1, long param_2) { return RGE_Diamond_Map_View::handle_size(param_1, param_2); }
long TRIBE_Diamond_Map_View::handle_paint() { return RGE_Diamond_Map_View::handle_paint(); }
long TRIBE_Diamond_Map_View::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return RGE_Diamond_Map_View::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Diamond_Map_View::handle_char(long param_1, short param_2) { return RGE_Diamond_Map_View::handle_char(param_1, param_2); }
long TRIBE_Diamond_Map_View::handle_command(uint param_1, long param_2) { return RGE_Diamond_Map_View::handle_command(param_1, param_2); }
long TRIBE_Diamond_Map_View::handle_user_command(uint param_1, long param_2) { return RGE_Diamond_Map_View::handle_user_command(param_1, param_2); }
long TRIBE_Diamond_Map_View::handle_timer_command(uint param_1, long param_2) { return RGE_Diamond_Map_View::handle_timer_command(param_1, param_2); }
long TRIBE_Diamond_Map_View::handle_scroll(long param_1, long param_2) { return RGE_Diamond_Map_View::handle_scroll(param_1, param_2); }
long TRIBE_Diamond_Map_View::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return RGE_Diamond_Map_View::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Diamond_Map_View::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return RGE_Diamond_Map_View::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Diamond_Map_View::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return RGE_Diamond_Map_View::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Diamond_Map_View::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return RGE_Diamond_Map_View::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Diamond_Map_View::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return RGE_Diamond_Map_View::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Diamond_Map_View::char_action(long param_1, short param_2) { return RGE_Diamond_Map_View::char_action(param_1, param_2); }
long TRIBE_Diamond_Map_View::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return RGE_Diamond_Map_View::action(param_1, param_2, param_3, param_4); }
void TRIBE_Diamond_Map_View::get_true_render_rect(tagRECT* param_1) { RGE_Diamond_Map_View::get_true_render_rect(param_1); }
int TRIBE_Diamond_Map_View::is_inside(long param_1, long param_2) { return RGE_Diamond_Map_View::is_inside(param_1, param_2); }
void TRIBE_Diamond_Map_View::set_focus(int param_1) { RGE_Diamond_Map_View::set_focus(param_1); }
void TRIBE_Diamond_Map_View::set_tab_order(TPanel* param_1, TPanel* param_2) { RGE_Diamond_Map_View::set_tab_order(param_1, param_2); }
void TRIBE_Diamond_Map_View::set_tab_order(TPanel** param_1, short param_2) { RGE_Diamond_Map_View::set_tab_order(param_1, param_2); }
uchar TRIBE_Diamond_Map_View::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return RGE_Diamond_Map_View::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Diamond_Map_View::stop_sound_system() { RGE_Diamond_Map_View::stop_sound_system(); }
int TRIBE_Diamond_Map_View::restart_sound_system() { return RGE_Diamond_Map_View::restart_sound_system(); }
void TRIBE_Diamond_Map_View::take_snapshot() { RGE_Diamond_Map_View::take_snapshot(); }
void TRIBE_Diamond_Map_View::handle_reactivate() { RGE_Diamond_Map_View::handle_reactivate(); }
void TRIBE_Diamond_Map_View::draw_selected_area() { RGE_Diamond_Map_View::draw_selected_area(); }

void TRIBE_Diamond_Map_View::draw_objects() {
    // Fully verified. Source of truth: tvw_dmap.cpp.decomp @ 0x0052CA60
    ulong now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tvw_dmap.cpp", 0x40);
    if (0x14C < now - this->last_attack_time) {
        this->flash_on = (uint)(this->flash_on == 0);
        this->last_attack_time = now;
    }
    RGE_Diamond_Map::draw_objects();
}

void TRIBE_Diamond_Map_View::draw_visible_object(RGE_Static_Object* param_1, uchar param_2, uchar param_3) { RGE_Diamond_Map_View::draw_visible_object(param_1, param_2, param_3); }

void TRIBE_Diamond_Map_View::draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5) {
    // Fully verified. Source of truth: tvw_dmap.cpp.decomp @ 0x0052CAB0
    if (this->draw_objects_mode == 4) {
        param_3 = (uchar)(((uint)-(this->flash_on != 0) & 0x57U) - 1);
    }
    RGE_Diamond_Map::draw_object(param_1, param_2, param_3, param_4, param_5);
}

void TRIBE_Diamond_Map_View::draw_view_rect() { RGE_Diamond_Map_View::draw_view_rect(); }
int TRIBE_Diamond_Map_View::command_make_do(long param_1, long param_2) { return RGE_Diamond_Map_View::command_make_do(param_1, param_2); }
int TRIBE_Diamond_Map_View::command_make_move(long param_1, long param_2) { return RGE_Diamond_Map_View::command_make_move(param_1, param_2); }
int TRIBE_Diamond_Map_View::command_make_work(long param_1, long param_2) { return RGE_Diamond_Map_View::command_make_work(param_1, param_2); }

