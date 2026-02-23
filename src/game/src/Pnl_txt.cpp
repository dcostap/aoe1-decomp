#include "../include/TScrollTextPanel.h"
#include "../include/TDrawArea.h"
#include "../include/debug_helpers.h"

#include <windows.h>
#include <string.h>

static const char* kScrCredSourcePath = "C:/msdev/work/age1_x1/scr_cred.cpp";

TScrollTextPanel::TScrollTextPanel(TPanel* parent, TDrawArea* area, long x, long y, long w, long h,
                                   int speed_in, void* font_in, long font_wid_in, long font_hgt_in,
                                   char* text) : TTextPanel() {
    // Fully verified. Source of truth: scr_cred.cpp.decomp @ 0x00492E70
    this->speed = speed_in;
    this->scroll = 0;
    this->last_time = 0;
    this->done = 0;

    if (TTextPanel::setup(area, parent, x, y, w, h,
                          font_in, font_wid_in, font_hgt_in,
                          (char*)nullptr, 0, 0, 0, 0, 0, (char*)nullptr) != 0) {
        this->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignCenter);
        this->set_word_wrap(1);
        this->set_text(text);
    }
}

TScrollTextPanel::~TScrollTextPanel() {
    // Fully verified. Source of truth: scr_cred.cpp.decomp @ 0x00492F70
}

long TScrollTextPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TTextPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

void TScrollTextPanel::set_rect(tagRECT param_1) { TTextPanel::set_rect(param_1); }
void TScrollTextPanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TTextPanel::set_rect(param_1, param_2, param_3, param_4); }
void TScrollTextPanel::set_color(uchar param_1) { TTextPanel::set_color(param_1); }
void TScrollTextPanel::set_active(int param_1) { TTextPanel::set_active(param_1); }
void TScrollTextPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TTextPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TScrollTextPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TTextPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TScrollTextPanel::set_redraw(RedrawMode param_1) { TTextPanel::set_redraw(param_1); }
void TScrollTextPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TTextPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TScrollTextPanel::draw_setup(int param_1) { TTextPanel::draw_setup(param_1); }
void TScrollTextPanel::draw_finish() { TTextPanel::draw_finish(); }
void TScrollTextPanel::draw_rect(tagRECT* param_1) { TTextPanel::draw_rect(param_1); }
void TScrollTextPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TTextPanel::draw_offset(param_1, param_2, param_3); }
void TScrollTextPanel::draw_rect2(tagRECT* param_1) { TTextPanel::draw_rect2(param_1); }
void TScrollTextPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TTextPanel::draw_offset2(param_1, param_2, param_3); }
void TScrollTextPanel::paint() { TTextPanel::paint(); }
long TScrollTextPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TTextPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::handle_size(long param_1, long param_2) { return TTextPanel::handle_size(param_1, param_2); }
long TScrollTextPanel::handle_paint() { return TTextPanel::handle_paint(); }
long TScrollTextPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TTextPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TScrollTextPanel::handle_char(long param_1, short param_2) { return TTextPanel::handle_char(param_1, param_2); }
long TScrollTextPanel::handle_command(uint param_1, long param_2) { return TTextPanel::handle_command(param_1, param_2); }
long TScrollTextPanel::handle_user_command(uint param_1, long param_2) { return TTextPanel::handle_user_command(param_1, param_2); }
long TScrollTextPanel::handle_timer_command(uint param_1, long param_2) { return TTextPanel::handle_timer_command(param_1, param_2); }
long TScrollTextPanel::handle_scroll(long param_1, long param_2) { return TTextPanel::handle_scroll(param_1, param_2); }
long TScrollTextPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TTextPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TScrollTextPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TTextPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TScrollTextPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TTextPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TScrollTextPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TScrollTextPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TTextPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TScrollTextPanel::char_action(long param_1, short param_2) { return TTextPanel::char_action(param_1, param_2); }
long TScrollTextPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TTextPanel::action(param_1, param_2, param_3, param_4); }
void TScrollTextPanel::get_true_render_rect(tagRECT* param_1) { TTextPanel::get_true_render_rect(param_1); }
int TScrollTextPanel::is_inside(long param_1, long param_2) { return TTextPanel::is_inside(param_1, param_2); }
void TScrollTextPanel::set_focus(int param_1) { TTextPanel::set_focus(param_1); }
void TScrollTextPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { TTextPanel::set_tab_order(param_1, param_2); }
void TScrollTextPanel::set_tab_order(TPanel** param_1, short param_2) { TTextPanel::set_tab_order(param_1, param_2); }
uchar TScrollTextPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TTextPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TScrollTextPanel::stop_sound_system() { TTextPanel::stop_sound_system(); }
int TScrollTextPanel::restart_sound_system() { return TTextPanel::restart_sound_system(); }
void TScrollTextPanel::take_snapshot() { TTextPanel::take_snapshot(); }
void TScrollTextPanel::handle_reactivate() { TTextPanel::handle_reactivate(); }
void TScrollTextPanel::set_text(char** param_1, short param_2) { TTextPanel::set_text(param_1, param_2); }
void TScrollTextPanel::set_text(long param_1) { TTextPanel::set_text(param_1); }
void TScrollTextPanel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) { TTextPanel::set_bevel_info(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }

void TScrollTextPanel::set_text(char* text) {
    // Fully verified. Source of truth: scr_cred.cpp.decomp @ 0x00492F80
    TTextPanel::set_text(text);
    this->last_time = 0;
    this->scroll = 0;
    this->done = 0;
}

long TScrollTextPanel::handle_idle() {
    // Best-effort transliteration. Source of truth: scr_cred.cpp.decomp @ 0x00492FB0
    const ulong now = debug_timeGetTime(kScrCredSourcePath, 0x1DF);
    if (this->last_time == 0) {
        this->last_time = now;
    } else {
        const float dt = (float)(int)(now - this->last_time) * 0.001f;
        const int delta = (int)(dt * (float)this->speed);
        if (delta > 0) {
            this->scroll += delta;
            this->set_redraw(TPanel::RedrawMode::Redraw);
            this->last_time = now;
        }
    }

    if (this->done != 0 && this->parent_panel) {
        this->parent_panel->action(this, 1, 0, 0);
    }
    return TPanel::handle_idle();
}

void TScrollTextPanel::draw_scrolled_line(void* hdc_void, short /*draw_index*/, short line_index, ulong color1, ulong color2) {
    // Best-effort implementation. Source of truth: scr_cred.cpp.decomp @ 0x00493160
    HDC hdc = (HDC)hdc_void;
    const char* text = this->get_text((long)line_index);
    if (!text || text[0] == '\0') {
        return;
    }

    SIZE sz{};
    GetTextExtentPoint32A(hdc, text, (int)strlen(text), &sz);

    const long x = this->pnl_x + (this->pnl_wid / 2) - (long)sz.cx / 2;
    const long y0 = (this->pnl_y + this->pnl_hgt - this->border_size - this->text_hgt);
    const long y = y0 + (long)line_index * this->text_hgt - (long)this->scroll;

    if (y + this->text_hgt < this->pnl_y) {
        return;
    }
    if (y > this->pnl_y + this->pnl_hgt) {
        return;
    }

    if (this->text_style == TTextPanel::ChiseledStyle) {
        SetTextColor(hdc, (COLORREF)color2);
        TextOutA(hdc, x - 1, y + 1, text, (int)strlen(text));
        SetTextColor(hdc, (COLORREF)color1);
        TextOutA(hdc, x, y, text, (int)strlen(text));
    } else if (this->text_style == TTextPanel::BeveledStyle) {
        SetTextColor(hdc, (COLORREF)color1);
        TextOutA(hdc, x - 1, y + 1, text, (int)strlen(text));
        SetTextColor(hdc, (COLORREF)color2);
        TextOutA(hdc, x, y, text, (int)strlen(text));
    } else {
        SetTextColor(hdc, (COLORREF)color1);
        TextOutA(hdc, x, y, text, (int)strlen(text));
    }

    if (line_index == (short)(this->num_lines - 1) && y + this->text_hgt < this->pnl_y) {
        this->done = 1;
    }
}

void TScrollTextPanel::draw() {
    // Best-effort implementation. Source of truth: scr_cred.cpp.decomp @ 0x00493070
    if (!this->render_area || !this->active || !this->visible) {
        return;
    }

    this->draw_background();
    this->draw_setup(0);
    HDC hdc = (HDC)this->render_area->GetDc((char*)"scr_cred::draw");
    if (hdc) {
        SelectClipRgn(hdc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = SelectObject(hdc, (HGDIOBJ)this->font);
        SetBkMode(hdc, TRANSPARENT);

        for (short i = 0; i < this->num_lines; ++i) {
            this->draw_scrolled_line(hdc, i, i, this->text_color1, this->text_color2);
        }

        SelectObject(hdc, old_font);
        SelectClipRgn(hdc, 0);
        this->render_area->ReleaseDc((char*)"scr_cred::draw");
    }
    this->draw_border();
    this->draw_finish();
}

