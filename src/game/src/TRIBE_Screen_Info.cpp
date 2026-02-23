#include "../include/TRIBE_Screen_Info.h"

#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_Screen_Main_Menu.h"
#include "../include/TribeSPMenuScreen.h"
#include "../include/TPanelSystem.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <string.h>

namespace {

static const char kScrInfoFile[] = "C:\\msdev\\work\\age1_x1\\scr_info.cpp";

static const char kRandomMap[] = "RandomMap";
static const char kDeathMatch[] = "DeathMatch";
static const char kLogo1Screen[] = "Logo1Screen";
static const char kLogo2Screen[] = "Logo2Screen";
static const char kScenarioEditorInfo[] = "ScenarioEditorInfo";
static const char kUnitInfo1[] = "UnitInfo1";
static const char kUnitInfo2[] = "UnitInfo2";
static const char kUnitInfo3[] = "UnitInfo3";
static const char kFeaturesInfo[] = "FeaturesInfo";
static const char kTechInfo[] = "TechInfo";
static const char kQuotesInfo[] = "QuotesInfo";

static const char kSinglePlayerMenu[] = "Single Player Menu";
static const char kMainMenu[] = "Main Menu";

static const char kScrLogo2[] = "scrlogo2";
static const char kScrUnit1[] = "scrunit1";
static const char kScrUnit2[] = "scrunit2";
static const char kScrUnit3[] = "scrunit3";
static const char kScrTech[] = "scrtech";
static const char kScrInfQu[] = "scrinfqu";

} // namespace

// Fully verified. Source of truth: scr_info.cpp.asm @ 0x0049D550
TRIBE_Screen_Info::TRIBE_Screen_Info(char* panel_name, char* screen_file, long screen_id, ulong timer_)
    : TScreenPanel(panel_name) {
    this->timer = timer_;
    this->auto_close = (timer_ != 0);
    this->last_time = 0;

    long ok = TScreenPanel::setup(rge_base_game->draw_area, screen_file, screen_id, 0);
    if (ok == 0) {
        this->error_code = 1;
    }
}

// Fully verified. Source of truth: scr_info.cpp.asm @ 0x0049D600
TRIBE_Screen_Info::~TRIBE_Screen_Info() {
}

// Fully verified. Source of truth: scr_info.cpp.asm @ 0x0049D610
long TRIBE_Screen_Info::handle_idle() {
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }

    if (this->auto_close != 0) {
        if (this->last_time == 0) {
            this->last_time = debug_timeGetTime(kScrInfoFile, 0x48);
            return TPanel::handle_idle();
        }

        ulong now = debug_timeGetTime(kScrInfoFile, 0x4b);
        if (this->timer < (now - this->last_time)) {
            this->close_screen();
            return 0;
        }
    }

    return TPanel::handle_idle();
}

// Fully verified. Source of truth: scr_info.cpp.asm @ 0x0049D690
long TRIBE_Screen_Info::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;

    if ((param_1 != 0x12) && (param_1 != 0x11) && (param_1 != 0x10)) {
        this->close_screen();
    }

    return 0;
}

// Fully verified. Source of truth: scr_info.cpp.asm @ 0x0049D6B0
long TRIBE_Screen_Info::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;

    this->close_screen();
    return 0;
}

// Fully verified. Source of truth: scr_info.cpp.asm @ 0x0049D6C0
long TRIBE_Screen_Info::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: scr_info.cpp.asm @ 0x0049D6E0
void TRIBE_Screen_Info::close_screen() {
    char* name = this->panelNameValue;
    if (name == nullptr) {
        name = (char*)"";
    }

    if (strcmp(name, kRandomMap) == 0) {
        rge_base_game->disable_input();
        new TribeSPMenuScreen();
        panel_system->setCurrentPanel((char*)kSinglePlayerMenu, 0);
        panel_system->destroyPanel((char*)kRandomMap);
        return;
    }

    if (strcmp(name, kDeathMatch) == 0) {
        rge_base_game->disable_input();
        new TribeSPMenuScreen();
        panel_system->setCurrentPanel((char*)kSinglePlayerMenu, 0);
        panel_system->destroyPanel((char*)kDeathMatch);
        return;
    }

    if (strcmp(name, kLogo1Screen) == 0) {
        new TRIBE_Screen_Info((char*)kLogo2Screen, (char*)kScrLogo2, 0xc392, 2000);
        panel_system->setCurrentPanel((char*)kLogo2Screen, 0);
        return;
    }

    if (strcmp(name, kLogo2Screen) == 0) {
        int ok = ((TRIBE_Game*)rge_base_game)->start_menu();
        if (ok == 0) {
            rge_base_game->close();
        }
        return;
    }

    if (strcmp(name, kScenarioEditorInfo) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)kUnitInfo1, (char*)kScrUnit1, 0xc394, 0);
        panel_system->setCurrentPanel((char*)kUnitInfo1, 0);
        panel_system->destroyPanel((char*)kScenarioEditorInfo);
        return;
    }

    if (strcmp(name, kUnitInfo1) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)kUnitInfo2, (char*)kScrUnit2, 0xc395, 0);
        panel_system->setCurrentPanel((char*)kUnitInfo2, 0);
        panel_system->destroyPanel((char*)kUnitInfo1);
        return;
    }

    if (strcmp(name, kUnitInfo2) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)kUnitInfo3, (char*)kScrUnit3, 0xc396, 0);
        panel_system->setCurrentPanel((char*)kUnitInfo3, 0);
        panel_system->destroyPanel((char*)kUnitInfo2);
        return;
    }

    if (strcmp(name, kUnitInfo3) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Main_Menu();
        panel_system->setCurrentPanel((char*)kMainMenu, 0);
        panel_system->destroyPanel((char*)kUnitInfo3);
        return;
    }

    if (strcmp(name, kFeaturesInfo) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)kTechInfo, (char*)kScrTech, 0xc393, 0);
        panel_system->setCurrentPanel((char*)kTechInfo, 0);
        panel_system->destroyPanel((char*)kFeaturesInfo);
        return;
    }

    if (strcmp(name, kTechInfo) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)kQuotesInfo, (char*)kScrInfQu, 0xc38f, 0);
        panel_system->setCurrentPanel((char*)kQuotesInfo, 0);
        panel_system->destroyPanel((char*)kTechInfo);
        return;
    }

    rge_base_game->close();
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TRIBE_Screen_Info::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Info::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Info::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Info::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Info::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Info::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Info::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Info::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Info::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Info::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Info::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Info::draw() { TScreenPanel::draw(); }
void TRIBE_Screen_Info::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Info::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Info::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Info::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Info::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Info::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Screen_Info::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Info::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Info::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Info::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Info::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Info::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Info::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Info::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Info::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Info::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Info::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Info::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Screen_Info::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Info::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Info::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Screen_Info::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Info::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Info::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Info::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Info::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Info::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Info::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Info::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Info::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Info::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Info::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Info::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Info::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Info::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Info::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Info::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Info::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Info::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Info::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Info::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Info::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Info::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Info::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Info::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Info::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

