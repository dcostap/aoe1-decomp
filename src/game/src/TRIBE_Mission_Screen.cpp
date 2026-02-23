#include "../include/TRIBE_Mission_Screen.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Scenario.h"
#include "../include/TSound_Driver.h"
#include "../include/TDrawArea.h"
#include "../include/TPicture.h"
#include "../include/TRIBE_Game.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "../include/TButtonPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/globals.h"

#include <string.h>

// Fully verified. Source of truth: scr_vc.cpp.decomp @ 0x004B8100
TRIBE_Mission_Screen::TRIBE_Mission_Screen(char* description, unsigned char game_flag, TPicture* mission_picture)
    : TScreenPanel((char*)"Mission Dialog") {
    TButtonPanel** ppTVar1 = this->text_buttons;
    TButtonPanel** ppTVar3 = this->text_buttons + 1;
    char adjusted_name[260];
    char info_file[260];
    unsigned char message_count;

    this->title = nullptr;
    this->ok_button = nullptr;
    this->list = nullptr;
    this->scroll_bar = nullptr;
    this->vc_back_bmp = nullptr;
    this->game_flag = game_flag;
    this->text_buttons[0] = nullptr;
    this->text_buttons[1] = nullptr;
    this->text_buttons[2] = nullptr;

    if (panel_system != nullptr) {
        panel_system->currentPanel();
    }

    strcpy(info_file + 4, (char*)"scr9");
    if (rge_base_game == nullptr || rge_base_game->draw_area == nullptr) {
        this->error_code = 1;
        return;
    }

    if (this->TScreenPanel::setup(rge_base_game->draw_area, info_file + 4, 0xC38C, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    RGE_Scenario* scenario = (rge_base_game->world != nullptr) ? rge_base_game->world->scenario : nullptr;
    char* scenario_name = (scenario != nullptr) ? scenario->Get_scenario_name() : (char*)0;
    if (scenario_name == nullptr || *scenario_name == '\0') {
        char* fallback = this->get_string(0x2655);
        strcpy(adjusted_name + 4, (fallback != nullptr) ? fallback : (char*)"");
    } else {
        strncpy(adjusted_name + 4, scenario_name, 255);
        adjusted_name[259] = '\0';
    }

    this->create_text((TPanel*)this, &this->title, adjusted_name + 4, 10, 0xF, 0x26C, 0x14, 4, 1, 1, 0);
    this->create_text((TPanel*)this, &this->list, (description != nullptr) ? description : (char*)"", 0xF, 0x46, 300, 0x154, 0xB, 0, 0, 1);
    this->create_auto_scrollbar(&this->scroll_bar, this->list, 0x14);

    if (this->use_bevels != 0 && this->list != nullptr) {
        this->list->set_bevel_info(3,
            (int)this->bevel_color1, (int)this->bevel_color2, (int)this->bevel_color3,
            (int)this->bevel_color4, (int)this->bevel_color5, (int)this->bevel_color6);
    }

    this->create_button((TPanel*)this, &this->ok_button, 0xFA1, 0, 200, 0x1B8, 0xF0, 0x1E, 0, 0, 0);
    this->create_button((TPanel*)this, &this->text_buttons[0], 0x2A31, 0, 0x145, 0x13C, 0xB4, 0x1E, 0, -1, 0);
    this->create_button((TPanel*)this, &this->text_buttons[1], 0x2A32, 0, 0x145, 0x15C, 0xB4, 0x1E, 0, -1, 0);
    this->create_button((TPanel*)this, &this->text_buttons[2], 0x2A37, 0, 0x145, 0x17C, 0xB4, 0x1E, 0, -1, 0);

    for (int i = 0; i < 3; ++i) {
        if (this->text_buttons[i] != nullptr) {
            this->text_buttons[i]->set_radio_info(this->text_buttons, 3);
        }
    }

    const long wid = this->width();
    long ok_x;
    long ok_y;
    long ok_w;
    long ok_h;
    if (wid < 0x281) {
        if (this->title != nullptr) this->title->set_fixed_position(3, 0xF, 0x27A, 0x14);
        if (this->list != nullptr) this->list->set_fixed_position(0x14, 0x32, 0x258, 0x73);
        if (*ppTVar1 != nullptr) (*ppTVar1)->set_fixed_position(5, 0x1BD, 0x96, 0x1E);
        if (*ppTVar3 != nullptr) (*ppTVar3)->set_fixed_position(0xA5, 0x1BD, 0x96, 0x1E);
        if (this->text_buttons[2] != nullptr) this->text_buttons[2]->set_fixed_position(0x145, 0x1BD, 0x96, 0x1E);
        ok_x = 0x1E5; ok_y = 0x1BD; ok_w = 0x96; ok_h = 0x1E;
    } else if (wid < 0x321) {
        this->set_ideal_size(800, 0x280);
        if (this->title != nullptr) this->title->set_fixed_position(3, 0xF, 0x31A, 0x14);
        if (this->list != nullptr) this->list->set_fixed_position(0x1E, 0x2D, 0x2E4, 0xE6);
        if (*ppTVar1 != nullptr) (*ppTVar1)->set_fixed_position(5, 0x235, 0xBE, 0x1E);
        if (*ppTVar3 != nullptr) (*ppTVar3)->set_fixed_position(0xCD, 0x235, 0xBE, 0x1E);
        if (this->text_buttons[2] != nullptr) this->text_buttons[2]->set_fixed_position(0x195, 0x235, 0xBE, 0x1E);
        ok_x = 0x25D; ok_y = 0x235; ok_w = 0xBE; ok_h = 0x1E;
    } else {
        this->set_ideal_size(0x400, 0x300);
        if (this->title != nullptr) this->title->set_fixed_position(3, 0xF, 0x3FA, 0x14);
        if (this->list != nullptr) this->list->set_fixed_position(0x28, 0x41, 0x3B0, 0x136);
        if (*ppTVar1 != nullptr) (*ppTVar1)->set_fixed_position(10, 0x2B2, 0xF0, 0x32);
        if (*ppTVar3 != nullptr) (*ppTVar3)->set_fixed_position(0x10A, 0x2B2, 0xF0, 0x32);
        if (this->text_buttons[2] != nullptr) this->text_buttons[2]->set_fixed_position(0x20A, 0x2B2, 0xF0, 0x32);
        ok_x = 0x306; ok_y = 0x2B2; ok_w = 0xF0; ok_h = 0x32;
    }
    if (this->ok_button != nullptr) {
        this->ok_button->set_fixed_position(ok_x, ok_y, ok_w, ok_h);
    }

    message_count = 0;
    char* msg = (scenario != nullptr) ? scenario->Get_message(0) : (char*)0;
    if (msg == nullptr) {
        if (*ppTVar3 != nullptr) (*ppTVar3)->set_active(0);
    } else {
        if (this->list != nullptr) this->list->set_text(msg);
        if (*ppTVar3 != nullptr) (*ppTVar3)->set_radio_button();
        message_count = 1;
    }

    msg = (scenario != nullptr) ? scenario->Get_message(4) : (char*)0;
    if (msg == nullptr) {
        if (*ppTVar1 != nullptr) (*ppTVar1)->set_active(0);
    } else {
        if (message_count == 0) {
            if (this->list != nullptr) this->list->set_text(msg);
            if (*ppTVar1 != nullptr) (*ppTVar1)->set_radio_button();
        }
        message_count++;
    }

    msg = (scenario != nullptr) ? scenario->Get_message(1) : (char*)0;
    if (msg == nullptr) {
        if (this->text_buttons[2] != nullptr) this->text_buttons[2]->set_active(0);
        if (message_count == 0 && this->list != nullptr) {
            this->list->set_active(0);
        }
    } else {
        if (message_count == 0) {
            if (this->list != nullptr) this->list->set_text(msg);
            if (this->text_buttons[2] != nullptr) this->text_buttons[2]->set_radio_button();
        }
        message_count++;
    }

    if (message_count == 1) {
        if (*ppTVar1 != nullptr) (*ppTVar1)->set_active(0);
        if (*ppTVar3 != nullptr) (*ppTVar3)->set_active(0);
        if (this->text_buttons[2] != nullptr) this->text_buttons[2]->set_active(0);
    }

    this->set_curr_child((TPanel*)this->ok_button);
    this->vc_back_bmp = mission_picture;
}

// Fully verified. Source of truth: scr_vc.cpp.decomp @ 0x004B87D0
TRIBE_Mission_Screen::~TRIBE_Mission_Screen() {
    if (this->game_flag == '\0' &&
        rge_base_game != nullptr &&
        rge_base_game->prog_info != nullptr &&
        rge_base_game->prog_info->use_sound != 0 &&
        rge_base_game->sound_system != nullptr) {
        rge_base_game->sound_system->stop_stream();
    }

    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scroll_bar);
    this->delete_panel((TPanel**)&this->ok_button);
    for (int i = 0; i < 3; ++i) {
        this->delete_panel((TPanel**)&this->text_buttons[i]);
    }
}

// Fully verified. Source of truth: scr_vc.cpp.decomp @ 0x004B89A0
long TRIBE_Mission_Screen::action(TPanel* panel, long action_id, ulong param_3, ulong param_4) {
    if (action_id == 1) {
        RGE_Scenario* scenario = (rge_base_game != nullptr && rge_base_game->world != nullptr) ? rge_base_game->world->scenario : nullptr;

        if ((TButtonPanel*)panel == this->text_buttons[0]) {
            if (this->list != nullptr && scenario != nullptr) {
                this->list->set_text(scenario->Get_message(4));
            }
        }
        if ((TButtonPanel*)panel == this->text_buttons[1]) {
            if (this->list != nullptr && scenario != nullptr) {
                this->list->set_text(scenario->Get_message(0));
            }
        }
        if ((TButtonPanel*)panel == this->text_buttons[2]) {
            if (this->list != nullptr && scenario != nullptr) {
                this->list->set_text(scenario->Get_message(1));
            }
        }

        if ((TButtonPanel*)panel == this->ok_button) {
            if (this->game_flag == '\0') {
                if (rge_base_game != nullptr) {
                    ((TRIBE_Game*)rge_base_game)->create_game_screen();
                }
            } else {
                if (panel_system != nullptr) {
                    panel_system->setCurrentPanel((char*)"Game Screen", 0);
                }
                if (rge_base_game != nullptr) {
                    if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                        rge_base_game->set_paused(0, 0);
                    }
                }
            }

            if (panel_system != nullptr) {
                panel_system->destroyPanel((char*)"Mission Dialog");
            }
            return 1;
        }
    }

    return TEasy_Panel::action(panel, action_id, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TRIBE_Mission_Screen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Mission_Screen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Mission_Screen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Mission_Screen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Mission_Screen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Mission_Screen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Mission_Screen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Mission_Screen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Mission_Screen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Mission_Screen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Mission_Screen::draw_finish() { TScreenPanel::draw_finish(); }
// Fully verified. Source of truth: scr_vc.cpp.decomp @ 0x004B88E0
void TRIBE_Mission_Screen::draw() {
    TScreenPanel::draw();

    if (this->vc_back_bmp == nullptr) {
        return;
    }

    this->draw_setup(0);

    if (this->need_redraw == TPanel::RedrawMode::RedrawFull && this->render_area != nullptr) {
        this->render_area->Clear(&this->clip_rect, (int)this->color);
    }

    if (this->render_area != nullptr) {
        uchar* puVar2 = this->render_area->Lock((char*)"scr_vc::draw", 1);
        if (puVar2 != nullptr) {
            const long w = this->width();
            long x;
            long y;

            if (w <= 0x280) {
                x = this->pnl_x + 7;
                y = this->pnl_y + 0xA6;
            } else if (w <= 0x320) {
                x = this->pnl_x + 0x53;
                y = this->pnl_y + 0x118;
            } else {
                x = this->pnl_x + 0xC5;
                y = this->pnl_y + 0x16B;
            }

            this->vc_back_bmp->Draw(this->render_area, x, y, 0, 0);
            this->render_area->Unlock((char*)"scr_vc::draw");
        }
    }

    this->draw_finish();
}
void TRIBE_Mission_Screen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Mission_Screen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Mission_Screen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Mission_Screen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Mission_Screen::paint() { TScreenPanel::paint(); }
long TRIBE_Mission_Screen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_vc.cpp.decomp @ 0x004B88B0
long TRIBE_Mission_Screen::handle_idle() {
    if (rge_base_game != nullptr && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}
long TRIBE_Mission_Screen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Mission_Screen::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Mission_Screen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Mission_Screen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Mission_Screen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Mission_Screen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Mission_Screen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Mission_Screen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Mission_Screen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Mission_Screen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Mission_Screen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Mission_Screen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_vc.cpp.decomp @ 0x004B8AE0
long TRIBE_Mission_Screen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    if (param_4 != 0 && param_1 == 0x56) {
        if (this->game_flag == '\0' &&
            rge_base_game != nullptr &&
            rge_base_game->prog_info != nullptr &&
            rge_base_game->prog_info->use_sound != 0 &&
            rge_base_game->sound_system != nullptr) {
            rge_base_game->sound_system->stream_file((char*)"voice.wav", 0, 0);
        }
        return 1;
    }
    return 0;
}
long TRIBE_Mission_Screen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Mission_Screen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Mission_Screen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Mission_Screen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Mission_Screen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Mission_Screen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Mission_Screen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Mission_Screen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Mission_Screen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Mission_Screen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Mission_Screen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Mission_Screen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Mission_Screen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Mission_Screen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Mission_Screen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Mission_Screen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Mission_Screen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Mission_Screen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Mission_Screen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Mission_Screen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Mission_Screen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Mission_Screen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Mission_Screen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Mission_Screen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

