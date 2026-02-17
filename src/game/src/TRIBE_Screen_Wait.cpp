#include "../include/TRIBE_Screen_Wait.h"

#include "../include/RGE_Base_Game.h"
#include "../include/TTextPanel.h"
#include "../include/TButtonPanel.h"
#include "../include/globals.h"

// Source of truth: scr_mps.cpp.decomp @ 0x004A5610, 0x004A6050, 0x004A60E0, 0x004A6100, 0x004A6120, 0x004A6170.
TRIBE_Screen_Wait::TRIBE_Screen_Wait()
    : TScreenPanel((char*)"Multiplayer Wait Screen") {
    this->message = nullptr;
    this->cancel_button = nullptr;
    this->close_button = nullptr;
    this->scenarioName = nullptr;
    for (int i = 0; i < 20; ++i) {
        this->settingText[i] = nullptr;
    }

    if (rge_base_game == nullptr || this->TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr3", 0xc385, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1e0);

    this->create_text((TPanel*)this, &this->message, (char*)"", 0x14, 0x28, 0x17c, 400, 4, 1, 1, 1);

    if (this->create_button((TPanel*)this, &this->close_button, 0x3ea, 0, 0, 0, 0, 0, -1, -1, 0) == 0) {
        this->error_code = 1;
        return;
    }

    if (this->create_text((TPanel*)this, &this->scenarioName, (char*)"", 0x1a4, 0x54, 0xdc, 0x44, 0xb, 0, 0, 1) == 0) {
        this->error_code = 1;
        return;
    }

    int y = 0x53;
    for (int i = 0; i < 20; ++i) {
        if (this->create_text((TPanel*)this, &this->settingText[i], (char*)"", 0x1a4, y, 0xdc, 0x14, 0xb, 0, 0, 0) == 0) {
            this->error_code = 1;
            return;
        }
        y += 0x18;
    }

    for (int i = 0; i < 20; ++i) {
        if (this->settingText[i] != nullptr) {
            this->settingText[i]->set_active(0);
        }
    }
}

TRIBE_Screen_Wait::~TRIBE_Screen_Wait() {
    this->delete_panel((TPanel**)&this->message);
    this->delete_panel((TPanel**)&this->close_button);
    this->delete_panel((TPanel**)&this->scenarioName);
    for (int i = 0; i < 20; ++i) {
        this->delete_panel((TPanel**)&this->settingText[i]);
    }
}

void TRIBE_Screen_Wait::set_text(char* text) {
    if (this->message != nullptr) {
        this->message->set_text(text);
    }
}

void TRIBE_Screen_Wait::set_text(long text_id) {
    if (this->message != nullptr) {
        this->message->set_text(text_id);
    }
}

long TRIBE_Screen_Wait::action(TPanel* panel, long action_id, ulong param_3, ulong param_4) {
    if (panel != nullptr && panel == this->close_button && action_id == 1) {
        if (rge_base_game != nullptr) {
            rge_base_game->close();
        }
        return 1;
    }
    return TEasy_Panel::action(panel, action_id, param_3, param_4);
}

long TRIBE_Screen_Wait::handle_idle() {
    if (rge_base_game != nullptr && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TRIBE_Screen_Wait::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Wait::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Wait::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Wait::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Wait::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Wait::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Wait::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Wait::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Wait::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Wait::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Wait::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Wait::draw() { TScreenPanel::draw(); }
void TRIBE_Screen_Wait::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Wait::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Wait::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Wait::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Wait::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Wait::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Screen_Wait::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Wait::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Wait::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Wait::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Wait::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Wait::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Wait::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Wait::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Wait::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Wait::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Wait::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Wait::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Wait::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Screen_Wait::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Wait::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Wait::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Screen_Wait::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Wait::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Wait::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Wait::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Wait::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Wait::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Wait::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Wait::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Wait::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Wait::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Wait::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Wait::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Wait::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Wait::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Wait::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Wait::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Wait::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Wait::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Wait::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Wait::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Wait::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Wait::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Wait::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Wait::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Wait::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
