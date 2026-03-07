#include "../include/TRIBE_Dialog_Name.h"
#include "../include/TRIBE_Screen_Campaign_Selection.h"
#include "../include/TribeSPMenuScreen.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_Info.h"
#include "../include/TEditPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/globals.h"

#include <string.h>

// TODO: PARITY [MODERATE] - Constructor adds defensive parent/draw-area fallback handling not present in the original unchecked call chain. [decomp: scr_name.cpp.decomp @ 0x004A6D50] [asm: scr_name.cpp.asm @ 0x004A6D50]
TRIBE_Dialog_Name::TRIBE_Dialog_Name(TScreenPanel* parent_screen) : TDialogPanel((char*)"New Name Dialog") {
    // TODO: PARITY [MODERATE] - Original immediately dereferences param_1 for popup/render-area calls; this version guards null parent_screen. [decomp: scr_name.cpp.decomp @ 0x004A6D50] [asm: scr_name.cpp.asm @ 0x004A6D50]
    this->title = nullptr;
    this->name_text = nullptr;
    this->name_input = nullptr;
    this->ok_button = nullptr;
    this->cancel_button = nullptr;

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;

    TDrawArea* area = parent_screen ? parent_screen->render_area : (rge_base_game ? rge_base_game->draw_area : nullptr);
    if (!this->setup(area, (TPanel*)parent_screen, 500, 0xE6, popup_file, popup_id, 1)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_text((TPanel*)this, &this->title, 0x2A03, 0x14, 0x14, 0x1CC, 0x1E, 1, 1, 1, 0)) return;
    if (!this->create_text((TPanel*)this, &this->name_text, 0x2A04, 0x28, 0x55, 0x1A4, 0x14, 4, 0, 1, 0)) return;
    if (!this->create_edit((TPanel*)this, &this->name_input, (char*)"", 0xF, FormatAny, 0x28, 0x6E, 0x1A4, 0x17, 0xB, 1, 1)) return;

    if (!this->create_button((TPanel*)this, &this->ok_button, 0xFA1, 0, 0x3C, 0xB4, 0xB4, 0x1E, 0, 0, 0)) return;
    if (!this->create_button((TPanel*)this, &this->cancel_button, 0xFA2, 0, 0x104, 0xB4, 0xB4, 0x1E, 0, 0, 0)) return;

    this->cancel_button->hotkey = 0x1B;
    this->cancel_button->hotkey_shift = 0;

    TPanel* tabs[3];
    tabs[0] = (TPanel*)this->name_input;
    tabs[1] = (TPanel*)this->ok_button;
    tabs[2] = (TPanel*)this->cancel_button;
    this->set_tab_order(tabs, 3);
    this->set_curr_child((TPanel*)this->name_input);
}

// Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A6F60 [asm: scr_name.cpp.asm @ 0x004A6F60]
TRIBE_Dialog_Name::~TRIBE_Dialog_Name() {
    // Fully verified. Scalar-deleting destructor thunk is covered separately at TRIBE_Dialog_Name.decomp/asm @ 0x004A6F40.
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->name_text);
    this->delete_panel((TPanel**)&this->name_input);
    this->delete_panel((TPanel**)&this->ok_button);
    this->delete_panel((TPanel**)&this->cancel_button);
}

// TODO: PARITY [HIGH] - action() adds defensive null checks and add_panel calls that are absent from the original direct panel-system flow. [decomp: scr_name.cpp.decomp @ 0x004A6FF0] [asm: scr_name.cpp.asm @ 0x004A6FF0]
long TRIBE_Dialog_Name::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // TODO: PARITY [HIGH] - Decomp/asm call panel-system transitions/destroys directly and do not include these panel_system/null guards or extra add_panel calls. [decomp: scr_name.cpp.decomp @ 0x004A6FF0] [asm: scr_name.cpp.asm @ 0x004A6FF0]
    (void)param_3;
    (void)param_4;

    if (param_1) {
        const int ok_pressed = ((TButtonPanel*)param_1 == this->ok_button && param_2 == 1) ||
                               ((TEditPanel*)param_1 == this->name_input && param_2 == 0);
        if (ok_pressed) {
            char* name = this->name_input ? this->name_input->get_text() : (char*)"";
            if (!name || *name == '\0') {
                this->set_curr_child((TPanel*)this->name_input);
                return 1;
            }

            if (rge_base_game && rge_base_game->player_game_info) {
                rge_base_game->player_game_info->add_new_person(name);
            }

            TRIBE_Screen_Campaign_Selection* scr = new TRIBE_Screen_Campaign_Selection();
            if (panel_system) {
                if (scr) panel_system->add_panel((TPanel*)scr);
                panel_system->setCurrentPanel((char*)"Campaign Selection Screen", 0);
                panel_system->destroyPanel((char*)"New Name Dialog");
                panel_system->destroyPanel((char*)"Name Selection Screen");
            }
            return 1;
        }

        const int cancel_pressed = ((TButtonPanel*)param_1 == this->cancel_button && param_2 == 1) ||
                                   ((TEditPanel*)param_1 == this->name_input && param_2 == 1);
        if (cancel_pressed) {
            const int have_name_screen = (panel_system && panel_system->panel((char*)"Name Selection Screen")) ? 1 : 0;
            if (!have_name_screen) {
                TribeSPMenuScreen* menu = new TribeSPMenuScreen();
                if (panel_system && menu) {
                    panel_system->add_panel((TPanel*)menu);
                }
            }

            if (panel_system) {
                panel_system->setCurrentPanel(have_name_screen ? (char*)"Name Selection Screen" : (char*)"Single Player Menu", 0);
                panel_system->destroyPanel((char*)"New Name Dialog");
            }
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A71D0
long TRIBE_Dialog_Name::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    // Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A71D0
    return TPanel::wnd_proc(param_1, param_2, param_3, param_4);
}

// Boilerplate virtual forwards
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00466A90
long TRIBE_Dialog_Name::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TDialogPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00464D70
void TRIBE_Dialog_Name::set_rect(tagRECT param_1) { TDialogPanel::set_rect(param_1); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00464C50
void TRIBE_Dialog_Name::set_rect(long param_1, long param_2, long param_3, long param_4) { TDialogPanel::set_rect(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00464DA0
void TRIBE_Dialog_Name::set_color(uchar param_1) { TDialogPanel::set_color(param_1); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00464DC0
void TRIBE_Dialog_Name::set_active(int param_1) { TDialogPanel::set_active(param_1); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00464E00
void TRIBE_Dialog_Name::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TDialogPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00464EB0
void TRIBE_Dialog_Name::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TDialogPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00464EE0
void TRIBE_Dialog_Name::set_redraw(RedrawMode param_1) { TDialogPanel::set_redraw(param_1); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00464F20
void TRIBE_Dialog_Name::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TDialogPanel::set_overlapped_redraw(param_1, param_2, param_3); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00467560
void TRIBE_Dialog_Name::draw_setup(int param_1) { TDialogPanel::draw_setup(param_1); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465370
void TRIBE_Dialog_Name::draw_finish() { TDialogPanel::draw_finish(); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00467570
void TRIBE_Dialog_Name::draw() { TDialogPanel::draw(); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004651C0
void TRIBE_Dialog_Name::draw_rect(tagRECT* param_1) { TDialogPanel::draw_rect(param_1); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465220
void TRIBE_Dialog_Name::draw_offset(long param_1, long param_2, tagRECT* param_3) { TDialogPanel::draw_offset(param_1, param_2, param_3); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004652C0
void TRIBE_Dialog_Name::draw_rect2(tagRECT* param_1) { TDialogPanel::draw_rect2(param_1); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004652F0
void TRIBE_Dialog_Name::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TDialogPanel::draw_offset2(param_1, param_2, param_3); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004653A0
void TRIBE_Dialog_Name::paint() { TDialogPanel::paint(); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465780
long TRIBE_Dialog_Name::handle_idle() { return TDialogPanel::handle_idle(); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465820
long TRIBE_Dialog_Name::handle_size(long param_1, long param_2) { return TDialogPanel::handle_size(param_1, param_2); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465A70
long TRIBE_Dialog_Name::handle_paint() { return TDialogPanel::handle_paint(); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465B30
long TRIBE_Dialog_Name::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TDialogPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465BE0
long TRIBE_Dialog_Name::handle_char(long param_1, short param_2) { return TDialogPanel::handle_char(param_1, param_2); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465C30
long TRIBE_Dialog_Name::handle_command(uint param_1, long param_2) { return TDialogPanel::handle_command(param_1, param_2); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465C40
long TRIBE_Dialog_Name::handle_user_command(uint param_1, long param_2) { return TDialogPanel::handle_user_command(param_1, param_2); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465C50
long TRIBE_Dialog_Name::handle_timer_command(uint param_1, long param_2) { return TDialogPanel::handle_timer_command(param_1, param_2); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465C60
long TRIBE_Dialog_Name::handle_scroll(long param_1, long param_2) { return TDialogPanel::handle_scroll(param_1, param_2); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x004679A0
long TRIBE_Dialog_Name::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465DC0
long TRIBE_Dialog_Name::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00465F70
long TRIBE_Dialog_Name::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TDialogPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00466060
long TRIBE_Dialog_Name::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TDialogPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437110
long TRIBE_Dialog_Name::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437230
long TRIBE_Dialog_Name::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437240
long TRIBE_Dialog_Name::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437250
long TRIBE_Dialog_Name::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437260
long TRIBE_Dialog_Name::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437270
long TRIBE_Dialog_Name::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437280
long TRIBE_Dialog_Name::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437290
long TRIBE_Dialog_Name::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004372A0
long TRIBE_Dialog_Name::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004372B0
long TRIBE_Dialog_Name::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437490
long TRIBE_Dialog_Name::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TDialogPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004374A0
long TRIBE_Dialog_Name::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TDialogPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004374B0
long TRIBE_Dialog_Name::char_action(long param_1, short param_2) { return TDialogPanel::char_action(param_1, param_2); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004669F0
void TRIBE_Dialog_Name::get_true_render_rect(tagRECT* param_1) { TDialogPanel::get_true_render_rect(param_1); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004662E0
int TRIBE_Dialog_Name::is_inside(long param_1, long param_2) { return TDialogPanel::is_inside(param_1, param_2); }
// Fully verified. Source of truth: pnl_dlg.cpp.decomp @ 0x00473EC0
void TRIBE_Dialog_Name::set_focus(int param_1) { TDialogPanel::set_focus(param_1); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00466650
void TRIBE_Dialog_Name::set_tab_order(TPanel* param_1, TPanel* param_2) { TDialogPanel::set_tab_order(param_1, param_2); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00466600
void TRIBE_Dialog_Name::set_tab_order(TPanel** param_1, short param_2) { TDialogPanel::set_tab_order(param_1, param_2); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004668D0
uchar TRIBE_Dialog_Name::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TDialogPanel::get_help_info(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00466980
void TRIBE_Dialog_Name::stop_sound_system() { TDialogPanel::stop_sound_system(); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004669A0
int TRIBE_Dialog_Name::restart_sound_system() { return TDialogPanel::restart_sound_system(); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x00437610
void TRIBE_Dialog_Name::take_snapshot() { TDialogPanel::take_snapshot(); }
// Fully verified. Source of truth: panel.cpp.decomp @ 0x004669D0
void TRIBE_Dialog_Name::handle_reactivate() { TDialogPanel::handle_reactivate(); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x004675C0
void TRIBE_Dialog_Name::draw_background(int param_1) { TDialogPanel::draw_background(param_1); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00467A50
void TRIBE_Dialog_Name::set_ideal_size(long param_1, long param_2) { TDialogPanel::set_ideal_size(param_1, param_2); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00468490
int TRIBE_Dialog_Name::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TDialogPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00468530
int TRIBE_Dialog_Name::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TDialogPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00468760
int TRIBE_Dialog_Name::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TDialogPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x004689C0
int TRIBE_Dialog_Name::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TDialogPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00468C20
int TRIBE_Dialog_Name::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TDialogPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00468E50
int TRIBE_Dialog_Name::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TDialogPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00468CB0
int TRIBE_Dialog_Name::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TDialogPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00469000
int TRIBE_Dialog_Name::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TDialogPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x004691C0
int TRIBE_Dialog_Name::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TDialogPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00469380
int TRIBE_Dialog_Name::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TDialogPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x004696B0
int TRIBE_Dialog_Name::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TDialogPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00469910
int TRIBE_Dialog_Name::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TDialogPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00469A80
int TRIBE_Dialog_Name::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TDialogPanel::create_auto_scrollbar(param_1, param_2, param_3); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00469AD0
int TRIBE_Dialog_Name::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TDialogPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00469C40
int TRIBE_Dialog_Name::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TDialogPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
// Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00469DB0
void TRIBE_Dialog_Name::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TDialogPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: pnl_dlg.cpp.decomp @ 0x00473D60
int TRIBE_Dialog_Name::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, uchar param_5, int param_6) { return TDialogPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6); }
// Fully verified. Source of truth: pnl_dlg.cpp.decomp @ 0x00473C80
int TRIBE_Dialog_Name::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7) { return TDialogPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }

