#include "../include/TRIBE_Panel_Text_Line.h"

#include "../include/TDrawArea.h"

#include <cstring>
#include <windows.h>

namespace {
const char* const kTpnlTxlDraw = "tpnl_txl::draw";
}

TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line(TDrawArea* param_1, TPanel* param_2, void* param_3) : TPanel() {
    // Fully verified. Source of truth: tpnl_txl.cpp.decomp @ 0x00520D70
    this->font = param_3;
    this->text_type = 0;
    this->text[0] = '\0';
    this->id = 0;
    this->error_code = 0;

    if (this->setup(param_1, param_2, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
    }
}

TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line() {}

long TRIBE_Panel_Text_Line::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_rect(tagRECT param_1) { TPanel::set_rect(param_1); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_rect(long param_1, long param_2, long param_3, long param_4) { TPanel::set_rect(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_color(uchar param_1) { TPanel::set_color(param_1); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_active(int param_1) { TPanel::set_active(param_1); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_redraw(RedrawMode param_1) { TPanel::set_redraw(param_1); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); } // TODO: STUB
void TRIBE_Panel_Text_Line::draw_setup(int param_1) { TPanel::draw_setup(param_1); } // TODO: STUB
void TRIBE_Panel_Text_Line::draw_finish() { TPanel::draw_finish(); } // TODO: STUB
void TRIBE_Panel_Text_Line::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); } // TODO: STUB
void TRIBE_Panel_Text_Line::draw_offset(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset(param_1, param_2, param_3); } // TODO: STUB
void TRIBE_Panel_Text_Line::draw_rect2(tagRECT* param_1) { TPanel::draw_rect2(param_1); } // TODO: STUB
void TRIBE_Panel_Text_Line::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset2(param_1, param_2, param_3); } // TODO: STUB
void TRIBE_Panel_Text_Line::paint() { TPanel::paint(); } // TODO: STUB
long TRIBE_Panel_Text_Line::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TPanel::wnd_proc(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_idle() { return TPanel::handle_idle(); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_size(long param_1, long param_2) { return TPanel::handle_size(param_1, param_2); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_paint() { return TPanel::handle_paint(); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_char(long param_1, short param_2) { return TPanel::handle_char(param_1, param_2); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_command(uint param_1, long param_2) { return TPanel::handle_command(param_1, param_2); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_user_command(uint param_1, long param_2) { return TPanel::handle_user_command(param_1, param_2); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_timer_command(uint param_1, long param_2) { return TPanel::handle_timer_command(param_1, param_2); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_scroll(long param_1, long param_2) { return TPanel::handle_scroll(param_1, param_2); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TPanel::handle_mouse_move(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long TRIBE_Panel_Text_Line::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_move_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long TRIBE_Panel_Text_Line::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long TRIBE_Panel_Text_Line::char_action(long param_1, short param_2) { return TPanel::char_action(param_1, param_2); } // TODO: STUB
long TRIBE_Panel_Text_Line::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TPanel::action(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Panel_Text_Line::get_true_render_rect(tagRECT* param_1) { TPanel::get_true_render_rect(param_1); } // TODO: STUB
int TRIBE_Panel_Text_Line::is_inside(long param_1, long param_2) { return TPanel::is_inside(param_1, param_2); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_focus(int param_1) { TPanel::set_focus(param_1); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_tab_order(TPanel* param_1, TPanel* param_2) { TPanel::set_tab_order(param_1, param_2); } // TODO: STUB
void TRIBE_Panel_Text_Line::set_tab_order(TPanel** param_1, short param_2) { TPanel::set_tab_order(param_1, param_2); } // TODO: STUB
uchar TRIBE_Panel_Text_Line::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TPanel::get_help_info(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Panel_Text_Line::stop_sound_system() { TPanel::stop_sound_system(); } // TODO: STUB
int TRIBE_Panel_Text_Line::restart_sound_system() { return TPanel::restart_sound_system(); } // TODO: STUB
void TRIBE_Panel_Text_Line::take_snapshot() { TPanel::take_snapshot(); } // TODO: STUB
void TRIBE_Panel_Text_Line::handle_reactivate() { TPanel::handle_reactivate(); } // TODO: STUB

void TRIBE_Panel_Text_Line::set_info(uchar param_1, char* param_2, long param_3) {
    // Fully verified. Source of truth: tpnl_txl.cpp.decomp @ 0x00520E30
    if ((param_1 == this->text_type) && (_stricmp(this->text, param_2) == 0) && (param_3 == this->id)) {
        return;
    }

    this->text_type = param_1;
    strcpy(this->text, param_2);
    this->id = param_3;
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Panel_Text_Line::draw() {
    // Fully verified. Source of truth: tpnl_txl.cpp.decomp @ 0x00520ED0
    if (this->render_area == nullptr || this->active == 0 || this->visible == 0) {
        return;
    }

    this->draw_setup(0);

    HDC dc = (HDC)this->render_area->GetDc((char*)kTpnlTxlDraw);
    if (dc != nullptr) {
        HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);
        SetBkMode(dc, 1);
        SetTextColor(dc, 0);
        if (this->text[0] != '\0') {
            TextOutA(dc, this->pnl_x, this->pnl_y, this->text, (int)strlen(this->text));
        }
        SelectObject(dc, old_font);
        this->render_area->ReleaseDc((char*)kTpnlTxlDraw);
    }

    this->draw_finish();
}
