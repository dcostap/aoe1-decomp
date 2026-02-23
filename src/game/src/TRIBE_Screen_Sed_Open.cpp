#include "../include/TRIBE_Screen_Sed_Open.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Prog_Info.h"
#include "../include/TButtonPanel.h"
#include "../include/TListPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TTextPanel.h"
#include "../include/TRIBE_Game.h"
#include "../include/globals.h"

#include <io.h>
#include <stdio.h>
#include <string.h>

static char kScenarioEditorOpenName[] = "Scenario Editor Open";
static char kScenarioEditorScreenName[] = "Scenario Editor Screen";
static char kScenarioEditorMenuName[] = "Scenario Editor Menu";
static char kCancelDialogName[] = "Cancel Dialog";

static void fillList(TRIBE_Screen_Sed_Open* this_) {
    // Decomp-first transliteration (simplified). Source of truth: scr_sedo.cpp.decomp @ 0x004B3740
    if (!this_ || !this_->list || !rge_base_game || !rge_base_game->prog_info) return;

    this_->list->empty_list();
    this_->list->handle_mouse_input = 1;

    _finddata_t fileInfo;
    char pattern[260];

    sprintf(pattern, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    long find_h = _findfirst(pattern, &fileInfo);
    if (find_h != -1) {
        do {
            // Strip ".scn" before appending (matches original open list behavior).
            char base[260];
            strncpy(base, fileInfo.name, sizeof(base) - 1);
            base[sizeof(base) - 1] = '\0';
            char* dot = strrchr(base, '.');
            if (dot) *dot = '\0';
            this_->list->append_line(base, 0);
        } while (_findnext(find_h, &fileInfo) == 0);
        _findclose(find_h);
    }

    sprintf(pattern, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    find_h = _findfirst(pattern, &fileInfo);
    if (find_h != -1) {
        do {
            char base[260];
            strncpy(base, fileInfo.name, sizeof(base) - 1);
            base[sizeof(base) - 1] = '\0';
            char* dot = strrchr(base, '.');
            if (dot) *dot = '\0';
            this_->list->append_line(base, 0);
        } while (_findnext(find_h, &fileInfo) == 0);
        _findclose(find_h);
    }

    // Disable OK/Delete if the list is empty.
    const char* cur = this_->list->currentLine();
    const int empty = (cur == nullptr || *cur == '\0') ? 1 : 0;
    if (this_->okButton) this_->okButton->disabled = empty;
    if (this_->deleteButton) this_->deleteButton->disabled = empty;
}

TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open()
    // Source of truth: scr_sedo.cpp.decomp @ 0x004B33D0
    : TScreenPanel(kScenarioEditorOpenName) {
    this->title = nullptr;
    this->list = nullptr;
    this->scrollbar = nullptr;
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->deleteButton = nullptr;

    if (!rge_base_game || !rge_base_game->draw_area || !panel_system) {
        this->error_code = 1;
        return;
    }

    // In the original, the open screen reuses the current panel's info file/id for consistent background.
    char info_file[260];
    info_file[0] = '\0';
    long info_id = -1;

    TPanel* from_panel = panel_system->currentPanel();
    if (from_panel != nullptr) {
        // Best-effort: these helpers exist on TEasy_Panel / TScreenPanel derived panels.
        TEasy_Panel* easy = (TEasy_Panel*)from_panel;
        char* src = easy->get_info_file();
        if (src) {
            strncpy(info_file, src, sizeof(info_file) - 1);
            info_file[sizeof(info_file) - 1] = '\0';
        }
        info_id = easy->get_info_id();
    }

    if (this->TScreenPanel::setup(rge_base_game->draw_area, info_file[0] ? info_file : (char*)0, info_id, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    // "Select Scenario"
    if (this->create_text((TPanel*)this, &this->title, 0x24cd, 0x14, 0x14, 600, 0x1e, 1, 1, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->create_list((TPanel*)this, &this->list, 0x14, 0x46, 600, 0x154, 0xb) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->create_auto_scrollbar(&this->scrollbar, (TTextPanel*)this->list, 0x14) == 0) {
        this->error_code = 1;
        return;
    }

    // OK / Delete / Cancel
    if (this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x1e, 0x1b8, 0xb4, 0x1e, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->create_button((TPanel*)this, &this->deleteButton, 0x24c9, 0, 0xe6, 0x1b8, 0xb4, 0x1e, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x1ae, 0x1b8, 0xb4, 0x1e, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    if (this->cancelButton) {
        this->cancelButton->hotkey = 0x1b;
        this->cancelButton->hotkey_shift = 0;
    }
    if (this->deleteButton) {
        this->deleteButton->hotkey = 0x2e;
        this->deleteButton->hotkey_shift = 0;
    }

    fillList(this);

    this->set_curr_child((TPanel*)this->list);
    TPanel* tabList[4];
    tabList[0] = (TPanel*)this->list;
    tabList[1] = (TPanel*)this->okButton;
    tabList[2] = (TPanel*)this->deleteButton;
    tabList[3] = (TPanel*)this->cancelButton;
    this->set_tab_order(tabList, 4);
}

TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open() {
    // Source of truth: scr_sedo.cpp.decomp @ 0x004B36A0
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}

long TRIBE_Screen_Sed_Open::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // TODO: STUB (partial): scr_sedo.cpp.decomp @ 0x004B38A0
    (void)param_3;
    (void)param_4;

    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->cancelButton) {
            if (panel_system) {
                if (panel_system->panel(kScenarioEditorScreenName) != nullptr) {
                    panel_system->setCurrentPanel(kScenarioEditorScreenName, 0);
                } else if (panel_system->panel(kScenarioEditorMenuName) != nullptr) {
                    panel_system->setCurrentPanel(kScenarioEditorMenuName, 0);
                }
                panel_system->destroyPanel(kScenarioEditorOpenName);
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->okButton) {
            const char* name = (this->list != nullptr) ? this->list->currentLine() : nullptr;
            if (name != nullptr && *name != '\0' && rge_base_game && rge_base_game->prog_info) {
                // Prefer .scn, fallback to .scx (matches original).
                char path[260];
                sprintf(path, "%s%s.scn", rge_base_game->prog_info->scenario_dir, name);
                const int have_scn = (_access(path, 0) == 0) ? 1 : 0;
                if (!have_scn) {
                    sprintf(path, "%s%s.scx", rge_base_game->prog_info->scenario_dir, name);
                    if (_access(path, 0) != 0) {
                        this->popupOKDialog(0x24cf, (char*)0, 0x1c2, 100); // "Cannot load that scenario."
                        return 1;
                    }
                    sprintf(path, "%s.scx", name);
                } else {
                    sprintf(path, "%s.scn", name);
                }

                (void)((TRIBE_Game*)rge_base_game)->start_scenario_editor(path, 0);
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->deleteButton) {
            const char* name = (this->list != nullptr) ? this->list->currentLine() : nullptr;
            if (name != nullptr && *name != '\0' && rge_base_game && rge_base_game->prog_info) {
                char fmt[256];
                char text[556];
                this->get_string(0x24ca, fmt, sizeof(fmt)); // "Are you sure you want to delete the file \n'%s'?"
                sprintf(text, fmt, name);
                this->popupYesNoDialog(text, kCancelDialogName, 0x1c2, 100);
            }
            return 1;
        }
    }

    if ((TListPanel*)param_1 == this->list && param_2 == 3) {
        return this->action((TPanel*)this->okButton, 1, 0, 0);
    }

    const char* panel_name = (param_1 != nullptr) ? param_1->panelName() : nullptr;
    if (panel_name != nullptr && strcmp(panel_name, kCancelDialogName) == 0) {
        if (param_2 == 0) {
            const char* name = (this->list != nullptr) ? this->list->currentLine() : nullptr;
            if (name != nullptr && *name != '\0' && rge_base_game && rge_base_game->prog_info) {
                char path[260];
                sprintf(path, "%s%s.scn", rge_base_game->prog_info->scenario_dir, name);
                (void)_unlink(path);
                sprintf(path, "%s%s.scx", rge_base_game->prog_info->scenario_dir, name);
                (void)_unlink(path);
                fillList(this);
            }
        }
        if (panel_system) panel_system->destroyPanel(kCancelDialogName);
        return 1;
    }

    return TScreenPanel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TRIBE_Screen_Sed_Open::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Sed_Open::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Sed_Open::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed_Open::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Sed_Open::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Sed_Open::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Sed_Open::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed_Open::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Sed_Open::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Sed_Open::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Sed_Open::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Sed_Open::draw() { TScreenPanel::draw(); }
void TRIBE_Screen_Sed_Open::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Sed_Open::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Sed_Open::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Sed_Open::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Sed_Open::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Sed_Open::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::handle_idle() { return TScreenPanel::handle_idle(); }
long TRIBE_Screen_Sed_Open::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Sed_Open::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Screen_Sed_Open::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Sed_Open::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Sed_Open::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Screen_Sed_Open::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Sed_Open::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Sed_Open::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed_Open::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Sed_Open::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Sed_Open::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Sed_Open::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Sed_Open::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Sed_Open::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Sed_Open::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed_Open::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed_Open::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Sed_Open::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Sed_Open::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Sed_Open::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Sed_Open::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed_Open::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Sed_Open::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Sed_Open::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Sed_Open::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

