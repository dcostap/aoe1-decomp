#include "../include/TRIBE_Screen_Main_Menu.h"
#include "../include/TRIBE_Credits_Screen.h"
#include "../include/TTextPanel.h"
#include "../include/TPicturePanel.h"
#include "../include/globals.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/TribeSPMenuScreen.h"
#include "../include/TribeMPStartupScreen.h"
#include "../include/TRIBE_Screen_Sed_Menu.h"
#include "../include/TPanelSystem.h"

#include <string.h>
#include <stdio.h>

namespace {

void menu_disable_input() {
    if (!rge_base_game) return;
    rge_base_game->disable_input();
}

void menu_enable_input() {
    if (!rge_base_game) return;
    rge_base_game->enable_input();
}

void menu_popup_resid(TRIBE_Screen_Main_Menu* owner, int resid) {
    if (owner == nullptr) {
        return;
    }
    owner->popupOKDialog((long)resid, (char*)0, 0x1c2, 100);
}

int menu_cd_gate(TRIBE_Screen_Main_Menu* owner, int error_resid) {
    if (!rge_base_game) return 0;
    if (rge_base_game->save_check_for_cd != 0) return 1;

    const int has_cd = rge_base_game->check_for_cd(0);
    if (has_cd == 0) {
        menu_popup_resid(owner, error_resid);
        return 0;
    }

    rge_base_game->save_check_for_cd = 1;
    return 1;
}

void menu_dispatch_confirm_dialog(TRIBE_Screen_Main_Menu* owner) {
    if (!owner) {
        return;
    }
    owner->popupOKDialog(0x1d4f7, (char*)"Confirm Dialog", 0x1c2, 100);
}

class MainMenuStubScreen : public TScreenPanel {
public:
    MainMenuStubScreen(char* panel_name, char* setup_name, long setup_id, char* title_text)
        : TScreenPanel(panel_name), title(nullptr), back_button(nullptr) {
        // TODO: STUB - Non-original stub screen:
        // TODO: STUB - this exists only to keep UI flow usable until the real screen classes are reimplemented.
        if (!rge_base_game || !rge_base_game->draw_area) {
            this->error_code = 1;
            return;
        }

        // TODO(accuracy): Best-effort: use original setup tuple first, then fallback to main menu panel resources.
        if (!TScreenPanel::setup(rge_base_game->draw_area, setup_name, setup_id, 1)) {
            if (!TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr1", 0xc383, 1)) {
                this->error_code = 1;
                return;
            }
        }

        this->set_ideal_size(0x280, 0x1e0);

        if (!this->create_text((TPanel*)this, &this->title, title_text, 0x14, 0x14, 0x258, 0x1e, 0xb, 1, 1, 0)) {
            this->error_code = 1;
            return;
        }

        if (!this->create_button((TPanel*)this, &this->back_button, 0xfa2, 0, 0x14a, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }

        this->back_button->hotkey = 0x1b;
        this->back_button->hotkey_shift = 0;
        this->curr_child = (TPanel*)this->back_button;
    }

    virtual long handle_idle() override {
        if (rge_base_game && rge_base_game->input_enabled == 0) {
            menu_enable_input();
        }
        return TPanel::handle_idle();
    }

    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) override {
        if ((param_2 == 1) && (param_1 == (TPanel*)this->back_button)) {
            menu_disable_input();

            TRIBE_Screen_Main_Menu* menu = new TRIBE_Screen_Main_Menu();
            if (menu && menu->error_code == 0) {
                panel_system->setCurrentPanel((char*)"Main Menu", 0);
                if (this->panelNameValue != nullptr) {
                    panel_system->destroyPanel(this->panelNameValue);
                }
            } else {
                if (menu) delete menu;
                menu_enable_input();
            }
            return 1;
        }

        return TScreenPanel::action(param_1, param_2, param_3, param_4);
    }

private:
    TTextPanel* title;
    TButtonPanel* back_button;
};

TPanel* create_stub_screen(char* panel_name, char* setup_name, long setup_id, char* title_text) {
    MainMenuStubScreen* screen = new MainMenuStubScreen(panel_name, setup_name, setup_id, title_text);
    if (!screen) return nullptr;
    if (screen->error_code != 0) {
        delete screen;
        return nullptr;
    }
    return (TPanel*)screen;
}

} // namespace

TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu() : TScreenPanel((char*)"Main Menu") {
    this->title1 = nullptr;
    this->title2 = nullptr;
    for (int i = 0; i < 7; ++i) this->button[i] = nullptr;
    this->ms_title_text = nullptr;
    this->ms_copy_text1 = nullptr;
    this->ms_copy_text2 = nullptr;
    this->warning_text = nullptr;
    this->circle_p_pic = nullptr;

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    if (!TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr1", 0xc383, 1)) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1e0);

    int y = 0xb2;
    for (int i = 0; i < 5; ++i) {
        if (!this->create_button((TPanel*)this, &this->button[i], (char*)"", (char*)0, 0xaa, y, 0x12c, 0x28, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }
        y += 0x32;
    }

    if (this->button[0]) this->button[0]->set_text(0, 0x23f2);
    if (this->button[1]) this->button[1]->set_text(0, 0x23f3);
    if (this->button[2]) this->button[2]->set_text(0, 0x23f5);
    if (this->button[3]) this->button[3]->set_text(0, 0x23f6);
    if (this->button[4]) this->button[4]->set_text(0, 0x23f7);

    // Source of truth: `src/game/src/Scr_main.cpp.decomp`.
    // After creating buttons in 640x480 ideal coordinates, the original switches ideal size to the
    // actual panel dimensions before placing bottom text, then restores 640x480 at the end.
    this->set_ideal_size(this->pnl_wid, this->pnl_hgt);

    // Bottom Microsoft / copyright text.
    this->create_text((TPanel*)this, &this->ms_title_text, 0x2419, 0x5, this->ideal_height - 0x3c, this->ideal_width - 0xa, 0x12, 0xa, 1, 0, 0);

    char temp[512];
    temp[0] = '\0';
    this->get_string(0x2424, temp, sizeof(temp));
    if (temp[0] == '\0') {
        // Branch that draws a circle-P picture between two text panels.
        long copy1_top = this->ideal_height - 0x2a;
        this->create_text((TPanel*)this, &this->ms_copy_text1, 0x241b, 0x5, this->ideal_height - 0x2a, 0x32, 0x12, 0xa, 0, 0, 0);
        if (this->ms_copy_text1) {
            tagRECT r;
            if (this->ms_copy_text1->get_text_rect(&r)) {
                copy1_top = r.top;
                this->circle_p_pic = new TPicturePanel();
                if (this->circle_p_pic) {
                    // Source of truth: `Scr_main.cpp.asm` call sequence around `0049e8f9..0049e925`.
                    // The original passes `&rect.top` to get_text_rect. With normal RECT semantics,
                    // the effective values at the setup call are:
                    //   x = (text_rect.right - this->pnl_x) + 3
                    //   y = text_rect.top + 1
                    long circle_x = (r.right - this->pnl_x) + 3;
                    long circle_y = copy1_top + 1;
                    this->circle_p_pic->setup(this->render_area, (TPanel*)this, circle_x, circle_y, 0xf, 0xe, (char*)"circlep2", 0xc4e6, 0, 1);
                }
            }
        }
        if (this->circle_p_pic) {
            long x2 = this->circle_p_pic->xPosition() - this->pnl_x + this->circle_p_pic->width();
            // Source of truth: `Scr_main.cpp.asm` around `0049e92a..0049e96d`:
            // y for ms_copy_text2 is taken from the same `get_text_rect` stack slot
            // that corresponds to `text_rect.top`.
            long y2 = copy1_top;
            this->create_text((TPanel*)this, &this->ms_copy_text2, 0x241c, x2, y2, 500, 0x12, 0xa, 0, 0, 0);

            // Match constructor recentering pass from `Scr_main.cpp.decomp`: shift the 3-part
            // copyright group (`ms_copy_text1`, `circle_p_pic`, `ms_copy_text2`) to center.
            if (this->ms_copy_text2) {
                tagRECT r2;
                if (this->ms_copy_text2->get_text_rect(&r2)) {
                    long shift_x = ((this->ideal_width - r2.right) - 5) / 2;
                    if (shift_x > 0) {
                        if (this->ms_copy_text1) {
                            this->ms_copy_text1->set_rect(
                                this->ms_copy_text1->xPosition() + shift_x,
                                this->ms_copy_text1->yPosition(),
                                this->ms_copy_text1->width(),
                                this->ms_copy_text1->height());
                        }
                        this->circle_p_pic->set_rect(
                            this->circle_p_pic->xPosition() + shift_x,
                            this->circle_p_pic->yPosition(),
                            this->circle_p_pic->width(),
                            this->circle_p_pic->height());
                        this->ms_copy_text2->set_rect(
                            this->ms_copy_text2->xPosition() + shift_x,
                            this->ms_copy_text2->yPosition(),
                            this->ms_copy_text2->width(),
                            this->ms_copy_text2->height());
                    }
                }
            }
        }
    } else {
        // Else branch: build combined string (`0x241b` + `0x2424` + "" + `0x241c`) and center it.
        char combined[512];
        char s1[256];
        char s2[256];
        char s3[256];
        combined[0] = '\0';
        s1[0] = '\0';
        s2[0] = '\0';
        s3[0] = '\0';

        // Use explicit buffers rather than `TPanel::get_string(int)` pointer form (static shared buffer),
        // so concatenation is deterministic and matches original local-buffer construction.
        this->get_string(0x241b, s1, sizeof(s1));
        this->get_string(0x2424, s2, sizeof(s2));
        this->get_string(0x241c, s3, sizeof(s3));
        strncat(combined, s1, sizeof(combined) - strlen(combined) - 1);
        strncat(combined, s2, sizeof(combined) - strlen(combined) - 1);
        strncat(combined, s3, sizeof(combined) - strlen(combined) - 1);
        this->create_text((TPanel*)this, &this->ms_copy_text1, combined, 0x5, this->ideal_height - 0x2a, this->ideal_width - 0xa, 0x12, 0xa, 1, 0, 0);
    }

    // Warning line: `0x2425` ("This program is protected by U.S. and international copyright laws...").
    // Match `Scr_main.cpp.decomp` call shape: x=5, y=ideal_h-0x18, w=ideal_w-10, h=0x12, font=10, center_h=1.
    this->create_text((TPanel*)this, &this->warning_text, 0x2425, 0x5, this->ideal_height - 0x18, this->ideal_width - 0xa, 0x12, 0xa, 1, 0, 0);

    // Restore ideal coordinates to 640x480 and set tab/focus order like original constructor.
    this->set_ideal_size(0x280, 0x1e0);
    TPanel* tab_list[6];
    tab_list[0] = (TPanel*)this;
    for (int i = 0; i < 5; ++i) tab_list[i + 1] = (TPanel*)this->button[i];
    this->set_tab_order(tab_list + 1, 5);

    // TODO(accuracy): Best-effort: set current child to the first button.
    this->curr_child = (TPanel*)this->button[0];
}

TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu() {
    // Source of truth: Scr_main.cpp.decomp
    // Delete all child panels before base destructor runs
    this->delete_panel((TPanel**)&this->title1);
    this->delete_panel((TPanel**)&this->title2);
    for (int i = 0; i < 7; ++i) {
        this->delete_panel((TPanel**)&this->button[i]);
    }
    this->delete_panel((TPanel**)&this->ms_title_text);
    this->delete_panel((TPanel**)&this->ms_copy_text1);
    this->delete_panel((TPanel**)&this->ms_copy_text2);
    this->delete_panel((TPanel**)&this->warning_text);
    this->delete_panel((TPanel**)&this->circle_p_pic);
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TRIBE_Screen_Main_Menu::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Main_Menu::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Main_Menu::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Main_Menu::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Main_Menu::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Main_Menu::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Main_Menu::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Main_Menu::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Main_Menu::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Main_Menu::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Main_Menu::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Main_Menu::draw() { TScreenPanel::draw(); }
void TRIBE_Screen_Main_Menu::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Main_Menu::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Main_Menu::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Main_Menu::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Main_Menu::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Main_Menu::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::handle_idle() {
    // Source of truth: `src/game/src/Scr_main.cpp.decomp` (`handle_idle` @ 0x0049ECD0).
    if (rge_base_game && rge_base_game->input_enabled == 0) {
        menu_enable_input();
    }
    return TPanel::handle_idle();
}
long TRIBE_Screen_Main_Menu::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Main_Menu::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Main_Menu::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Main_Menu::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Main_Menu::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Main_Menu::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    (void)param_2;
    (void)param_3;
    (void)param_5;

    // Source of truth: `src/game/src/Scr_main.cpp.decomp` (`key_down_action` @ 0x0049ED00).
    // Original behavior reacts on key-up transitions (`param_4 != 0`).
    if (param_4 == 0) {
        return 0;
    }

    if ((param_1 == 'C') || (param_1 == 'c')) {
        TRIBE_Credits_Screen* credits = new TRIBE_Credits_Screen();
        if (credits && credits->error_code == 0 && panel_system) {
            panel_system->setCurrentPanel((char*)"Credits Screen", 0);
            panel_system->destroyPanel((char*)"Main Menu");
        } else if (credits) {
            delete credits;
        }
        return 1;
    }

    if (((param_1 == 'L') || (param_1 == 'l')) &&
        rge_base_game &&
        rge_base_game->rge_game_options.gameDeveloperModeValue) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        if (!game->load_db_files()) {
            menu_popup_resid(this, 0x7d7);
        }
        return 1;
    }

    return 0;
}
long TRIBE_Screen_Main_Menu::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }

long TRIBE_Screen_Main_Menu::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Source of truth: `src/game/src/Scr_main.cpp.decomp` (`action` @ 0x0049EE00).
    // NOTE: dialog and target screens are currently stubs; keep TODO markers explicit.
    if (param_1 && param_1->panelNameValue && (_stricmp(param_1->panelNameValue, "Confirm Dialog") == 0) && (param_2 == 0)) {
        if (panel_system) {
            panel_system->destroyPanel((char*)"Confirm Dialog");
        }
        if (rge_base_game && rge_base_game->prog_window) {
            WinHelpA((HWND)rge_base_game->prog_window, "empires.hlp", HELP_FINDER, 0);
        }
        return 1;
    }

    if (param_1 && (param_2 == 1)) {
        if ((TButtonPanel*)param_1 == this->button[0]) {
            if (!menu_cd_gate(this, 0x7d8)) {
                return 1;
            }

            menu_disable_input();
            TribeSPMenuScreen* next = new TribeSPMenuScreen();
            if (next && next->error_code == 0) {
                panel_system->setCurrentPanel((char*)"Single Player Menu", 0);
                panel_system->destroyPanel((char*)"Main Menu");
            } else {
                if (next) {
                    delete next;
                }
                menu_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[1]) {
            menu_disable_input();
            TribeMPStartupScreen* next = new TribeMPStartupScreen();
            if (next && next->error_code == 0) {
                panel_system->setCurrentPanel((char*)"MP Startup Screen", 0);
                panel_system->destroyPanel((char*)"Main Menu");
            } else {
                if (next) {
                    delete next;
                }
                menu_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[2]) {
            menu_dispatch_confirm_dialog(this);
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[3]) {
            if (!menu_cd_gate(this, 0x7da)) {
                return 1;
            }

            menu_disable_input();
            TRIBE_Screen_Sed_Menu* next = new TRIBE_Screen_Sed_Menu();
            if (next && next->error_code == 0) {
                panel_system->setCurrentPanel((char*)"Scenario Editor Menu", 0);
                panel_system->destroyPanel((char*)"Main Menu");
            } else {
                if (next) {
                    delete next;
                }
                menu_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[4]) {
            if (rge_base_game) {
                rge_base_game->close();
            }
            return 1;
        }
    }

    return TScreenPanel::action(param_1, param_2, param_3, param_4);
}

void TRIBE_Screen_Main_Menu::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Main_Menu::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Main_Menu::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Screen_Main_Menu::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Main_Menu::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Main_Menu::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Main_Menu::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Main_Menu::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Main_Menu::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Main_Menu::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Main_Menu::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Main_Menu::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Main_Menu::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Main_Menu::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Main_Menu::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Main_Menu::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Main_Menu::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Main_Menu::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Main_Menu::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Main_Menu::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Main_Menu::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Main_Menu::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Main_Menu::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
