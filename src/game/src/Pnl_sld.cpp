#include "../include/TVerticalSliderPanel.h"
#include "../include/THorizontalSliderPanel.h"
#include "../include/TDrawArea.h"

TVerticalSliderPanel::TVerticalSliderPanel() : TScrollBarPanel() {
    // Fully verified. Source of truth: pnl_sld.cpp.decomp @ 0x0047BCE0
    this->drawBox = 1;
    this->spineWidth = 0;
}

TVerticalSliderPanel::~TVerticalSliderPanel() {
    // Fully verified. Source of truth: pnl_sld.cpp.decomp @ 0x0047BD30
}

long TVerticalSliderPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TScrollBarPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

long TVerticalSliderPanel::setup(TDrawArea* area, TPanel* parent, long x, long y, long w, long h,
                                 char* pic1, char* pic4, long arrow_hgt, long list_len, long one_step,
                                 long page_step, int draw_box, int spine_width) {
    // Fully verified. Source of truth: pnl_sld.cpp.decomp @ 0x0047BD40
    this->drawBox = draw_box;
    this->spineWidth = spine_width;
    if (!TScrollBarPanel::setup(area, parent, x, y, w, h, pic1, (char*)nullptr, (char*)nullptr, pic4,
                                0, arrow_hgt, (TPanel*)nullptr, (int)list_len, TScrollBarPanel::Vertical)) {
        return 0;
    }
    this->one_step = one_step;
    this->page_step = page_step;
    return 1;
}

void TVerticalSliderPanel::set_rect(tagRECT param_1) { TScrollBarPanel::set_rect(param_1); }
void TVerticalSliderPanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TScrollBarPanel::set_rect(param_1, param_2, param_3, param_4); }
void TVerticalSliderPanel::set_color(uchar param_1) { TScrollBarPanel::set_color(param_1); }
void TVerticalSliderPanel::set_active(int param_1) { TScrollBarPanel::set_active(param_1); }
void TVerticalSliderPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TScrollBarPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TVerticalSliderPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScrollBarPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TVerticalSliderPanel::set_redraw(RedrawMode param_1) { TScrollBarPanel::set_redraw(param_1); }
void TVerticalSliderPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScrollBarPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TVerticalSliderPanel::draw_setup(int param_1) { TScrollBarPanel::draw_setup(param_1); }
void TVerticalSliderPanel::draw_finish() { TScrollBarPanel::draw_finish(); }
void TVerticalSliderPanel::draw() {
    // Fully verified. Source of truth: pnl_sld.cpp.asm @ 0x0047BDE0
    TScrollBarPanel::draw();
}
void TVerticalSliderPanel::draw_rect(tagRECT* param_1) { TScrollBarPanel::draw_rect(param_1); }
void TVerticalSliderPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScrollBarPanel::draw_offset(param_1, param_2, param_3); }
void TVerticalSliderPanel::draw_rect2(tagRECT* param_1) { TScrollBarPanel::draw_rect2(param_1); }
void TVerticalSliderPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScrollBarPanel::draw_offset2(param_1, param_2, param_3); }
void TVerticalSliderPanel::paint() { TScrollBarPanel::paint(); }
long TVerticalSliderPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScrollBarPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::handle_idle() { return TScrollBarPanel::handle_idle(); }
long TVerticalSliderPanel::handle_size(long param_1, long param_2) { return TScrollBarPanel::handle_size(param_1, param_2); }
long TVerticalSliderPanel::handle_paint() { return TScrollBarPanel::handle_paint(); }
long TVerticalSliderPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScrollBarPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TVerticalSliderPanel::handle_char(long param_1, short param_2) { return TScrollBarPanel::handle_char(param_1, param_2); }
long TVerticalSliderPanel::handle_command(uint param_1, long param_2) { return TScrollBarPanel::handle_command(param_1, param_2); }
long TVerticalSliderPanel::handle_user_command(uint param_1, long param_2) { return TScrollBarPanel::handle_user_command(param_1, param_2); }
long TVerticalSliderPanel::handle_timer_command(uint param_1, long param_2) { return TScrollBarPanel::handle_timer_command(param_1, param_2); }
long TVerticalSliderPanel::handle_scroll(long param_1, long param_2) { return TScrollBarPanel::handle_scroll(param_1, param_2); }
long TVerticalSliderPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScrollBarPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TVerticalSliderPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScrollBarPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TVerticalSliderPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScrollBarPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TVerticalSliderPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TVerticalSliderPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScrollBarPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TVerticalSliderPanel::char_action(long param_1, short param_2) { return TScrollBarPanel::char_action(param_1, param_2); }
long TVerticalSliderPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TScrollBarPanel::action(param_1, param_2, param_3, param_4); }
void TVerticalSliderPanel::get_true_render_rect(tagRECT* param_1) { TScrollBarPanel::get_true_render_rect(param_1); }
int TVerticalSliderPanel::is_inside(long param_1, long param_2) { return TScrollBarPanel::is_inside(param_1, param_2); }
void TVerticalSliderPanel::set_focus(int param_1) { TScrollBarPanel::set_focus(param_1); }
void TVerticalSliderPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { TScrollBarPanel::set_tab_order(param_1, param_2); }
void TVerticalSliderPanel::set_tab_order(TPanel** param_1, short param_2) { TScrollBarPanel::set_tab_order(param_1, param_2); }
uchar TVerticalSliderPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScrollBarPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TVerticalSliderPanel::stop_sound_system() { TScrollBarPanel::stop_sound_system(); }
int TVerticalSliderPanel::restart_sound_system() { return TScrollBarPanel::restart_sound_system(); }
void TVerticalSliderPanel::take_snapshot() { TScrollBarPanel::take_snapshot(); }
void TVerticalSliderPanel::handle_reactivate() { TScrollBarPanel::handle_reactivate(); }

THorizontalSliderPanel::THorizontalSliderPanel() : TVerticalSliderPanel() {
    // Fully verified. Source of truth: pnl_sld.cpp.decomp @ 0x0047BDF0
}

THorizontalSliderPanel::~THorizontalSliderPanel() {
    // Fully verified. Source of truth: pnl_sld.cpp.decomp @ 0x0047BE30
}

long THorizontalSliderPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TVerticalSliderPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

long THorizontalSliderPanel::setup(TDrawArea* area, TPanel* parent, long x, long y, long w, long h,
                                   char* pic1, char* pic4, long arrow_hgt, long list_len, long one_step,
                                   long page_step, int draw_box, int spine_width) {
    // Fully verified. Source of truth: pnl_sld.cpp.decomp @ 0x0047BE40
    this->drawBox = draw_box;
    this->spineWidth = spine_width;
    if (!TScrollBarPanel::setup(area, parent, x, y, w, h, pic1, (char*)nullptr, (char*)nullptr, pic4,
                                0, arrow_hgt, (TPanel*)nullptr, (int)list_len, TScrollBarPanel::Horizontal)) {
        return 0;
    }
    this->one_step = one_step;
    this->page_step = page_step;
    return 1;
}

void THorizontalSliderPanel::set_rect(tagRECT param_1) { TScrollBarPanel::set_rect(param_1); }
void THorizontalSliderPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: pnl_sld.cpp.decomp @ 0x0047BEC0
    TScrollBarPanel::set_rect(param_1, param_2, param_3, param_4);

    const long x = this->pnl_x;
    this->up_rect.left = x;
    this->up_rect.right = x;
    this->down_rect.left = x + this->pnl_wid - 1;
    this->down_rect.right = this->down_rect.left;

    this->tab_min_x = x + 1;
    this->tab_x = x + 1;
    this->tab_max_x = (this->down_rect.left - this->pnl_hgt) + 2;

    this->calc_item_rects();
}
void THorizontalSliderPanel::set_color(uchar param_1) { TScrollBarPanel::set_color(param_1); }
void THorizontalSliderPanel::set_active(int param_1) { TScrollBarPanel::set_active(param_1); }
void THorizontalSliderPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TScrollBarPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void THorizontalSliderPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScrollBarPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void THorizontalSliderPanel::set_redraw(RedrawMode param_1) { TScrollBarPanel::set_redraw(param_1); }
void THorizontalSliderPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScrollBarPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void THorizontalSliderPanel::draw_setup(int param_1) { TScrollBarPanel::draw_setup(param_1); }
void THorizontalSliderPanel::draw_finish() { TScrollBarPanel::draw_finish(); }
void THorizontalSliderPanel::draw() {
    // Fully verified. Source of truth: pnl_sld.cpp.asm @ 0x0047BF30
    TScrollBarPanel::draw();
}
void THorizontalSliderPanel::draw_rect(tagRECT* param_1) { TScrollBarPanel::draw_rect(param_1); }
void THorizontalSliderPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScrollBarPanel::draw_offset(param_1, param_2, param_3); }
void THorizontalSliderPanel::draw_rect2(tagRECT* param_1) { TScrollBarPanel::draw_rect2(param_1); }
void THorizontalSliderPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScrollBarPanel::draw_offset2(param_1, param_2, param_3); }
void THorizontalSliderPanel::paint() { TScrollBarPanel::paint(); }
long THorizontalSliderPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScrollBarPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::handle_idle() { return TScrollBarPanel::handle_idle(); }
long THorizontalSliderPanel::handle_size(long param_1, long param_2) { return TScrollBarPanel::handle_size(param_1, param_2); }
long THorizontalSliderPanel::handle_paint() { return TScrollBarPanel::handle_paint(); }
long THorizontalSliderPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScrollBarPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long THorizontalSliderPanel::handle_char(long param_1, short param_2) { return TScrollBarPanel::handle_char(param_1, param_2); }
long THorizontalSliderPanel::handle_command(uint param_1, long param_2) { return TScrollBarPanel::handle_command(param_1, param_2); }
long THorizontalSliderPanel::handle_user_command(uint param_1, long param_2) { return TScrollBarPanel::handle_user_command(param_1, param_2); }
long THorizontalSliderPanel::handle_timer_command(uint param_1, long param_2) { return TScrollBarPanel::handle_timer_command(param_1, param_2); }
long THorizontalSliderPanel::handle_scroll(long param_1, long param_2) { return TScrollBarPanel::handle_scroll(param_1, param_2); }
long THorizontalSliderPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScrollBarPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long THorizontalSliderPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScrollBarPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long THorizontalSliderPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScrollBarPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long THorizontalSliderPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScrollBarPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long THorizontalSliderPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScrollBarPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long THorizontalSliderPanel::char_action(long param_1, short param_2) { return TScrollBarPanel::char_action(param_1, param_2); }
long THorizontalSliderPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TScrollBarPanel::action(param_1, param_2, param_3, param_4); }
void THorizontalSliderPanel::get_true_render_rect(tagRECT* param_1) { TScrollBarPanel::get_true_render_rect(param_1); }
int THorizontalSliderPanel::is_inside(long param_1, long param_2) { return TScrollBarPanel::is_inside(param_1, param_2); }
void THorizontalSliderPanel::set_focus(int param_1) { TScrollBarPanel::set_focus(param_1); }
void THorizontalSliderPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { TScrollBarPanel::set_tab_order(param_1, param_2); }
void THorizontalSliderPanel::set_tab_order(TPanel** param_1, short param_2) { TScrollBarPanel::set_tab_order(param_1, param_2); }
uchar THorizontalSliderPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScrollBarPanel::get_help_info(param_1, param_2, param_3, param_4); }
void THorizontalSliderPanel::stop_sound_system() { TScrollBarPanel::stop_sound_system(); }
int THorizontalSliderPanel::restart_sound_system() { return TScrollBarPanel::restart_sound_system(); }
void THorizontalSliderPanel::take_snapshot() { TScrollBarPanel::take_snapshot(); }
void THorizontalSliderPanel::handle_reactivate() { TScrollBarPanel::handle_reactivate(); }

