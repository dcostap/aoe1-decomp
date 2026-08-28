// Authentic complete owner for C:\\msdev\\work\\age1_x1\\Scr_main.cpp.
// Normal owners stay in PDB source order (85, 199, 220, 231, 264, 395,
// 426, 435, 443, 451, 480).

#include "../include/scr_main.h"
#include "../include/scr_cred.h"
#include <string.h>

// VA: 0049E6D0 TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu
// PDB source: Scr_main.cpp lines 85-193.
TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu()
    : TScreenPanel(s_Main_Menu) {
    RECT rect;
    TPanel* tab_list[5];
    char temp_str[0x200];
    int diff;
    int i;
    TButtonPanel** const button_base = this->button;

    this->title1 = 0;
    this->title2 = 0;
    this->circle_p_pic = 0;
    this->ms_title_text = 0;
    this->ms_copy_text1 = 0;
    this->ms_copy_text2 = 0;
    this->warning_text = 0;

    memset(this->button, 0, sizeof(this->button));

    if (this->setup(rge_base_game->draw_area, s_scr1, 0xC383, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);

    TButtonPanel** clear_button = button_base;
    for (long button_width = 0xB2; button_width < 0x1AC;
         button_width += 0x32, ++clear_button) {
        if (this->create_button(this, clear_button, s_empty, 0, 0xAA,
                                button_width, 0x12C, 0x28, 0, 0, 0) == 0) {
            return;
        }
    }

    this->button[0]->set_text(0, 0x23F2);
    this->button[1]->set_text(0, 0x23F3);
    this->button[2]->set_text(0, 0x23F5);
    this->button[3]->set_text(0, 0x23F6);
    this->button[4]->set_text(0, 0x23F7);

    this->set_ideal_size(this->pnl_wid, this->pnl_hgt);

    long panel_height = this->pnl_hgt - 0x3C;
    this->create_text(this, &this->ms_title_text, 0x2419, 5,
                      panel_height, this->pnl_wid - 0x0A,
                      0x12, 10, 1, 0, 0);

    this->get_string(0x2424, temp_str, 0x200);
    if (temp_str[0] == 0) {
        TTextPanel** copy1 = &this->ms_copy_text1;
        this->create_text(this, copy1, 0x241B, 5,
                          panel_height + 0x12, 0x32, 0x12,
                          10, 0, 0, 0);

        if ((*copy1)->get_text_rect(&rect) != 0) {
            this->circle_p_pic = new TPicturePanel;
            if (this->circle_p_pic != 0) {
                this->circle_p_pic->setup(this->render_area, this,
                               rect.right - this->pnl_x + 3,
                               rect.top + 1, 0x0F, 0x0E,
                               s_circlep2, 0xC4E6, 0, 1);

                long x = this->circle_p_pic->xPosition() - this->pnl_x +
                         this->circle_p_pic->width();
                TTextPanel** copy2 = &this->ms_copy_text2;
                this->create_text(this, copy2, 0x241C, x,
                                  rect.top, 0x1F4, 0x12, 10, 0, 0, 0);

                if ((*copy2)->get_text_rect(&rect) != 0) {
                    diff = (this->pnl_wid - rect.right - 5) / 2;
                    if (diff > 0) {
                        (*copy1)->set_fixed_position(
                            (*copy1)->xPosition() + diff,
                            (*copy1)->yPosition(),
                            (*copy1)->width(),
                            (*copy1)->height());
                        this->circle_p_pic->set_fixed_position(
                            this->circle_p_pic->xPosition() + diff,
                            this->circle_p_pic->yPosition(),
                            this->circle_p_pic->width(),
                            this->circle_p_pic->height());
                        (*copy2)->set_fixed_position(
                            (*copy2)->xPosition() + diff,
                            (*copy2)->yPosition(),
                            (*copy2)->width(),
                            (*copy2)->height());
                    }
                }
            }
        }
    } else {
        strcpy(temp_str, this->get_string(0x241B));
        strcat(temp_str, this->get_string(0x2424));
        strcat(temp_str, s_space);
        strcat(temp_str, this->get_string(0x241C));

        this->create_text(this, &this->ms_copy_text1, temp_str, 5,
                          panel_height + 0x12, this->pnl_wid - 0x0A,
                          0x12, 10, 1, 0, 0);
    }

    this->create_text(this, &this->warning_text, 0x2425, 5,
                      panel_height + 0x24, this->pnl_wid - 0x0A,
                      0x12, 10, 1, 0, 0);

    this->set_ideal_size(0x280, 0x1E0);

    TPanel** tab_dst = tab_list;
    TButtonPanel** tab_src = button_base;
    for (i = 5; i != 0; --i) {
        *tab_dst++ = *tab_src++;
    }
    this->set_tab_order(tab_list, 5);
    this->set_curr_child(this->button[0]);
}

// VA: 0049EC00 TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu
// PDB source: Scr_main.cpp lines 199-214.
TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu() {
    this->delete_panel((TPanel**)&this->title1);
    this->delete_panel((TPanel**)&this->title2);
    this->delete_panel((TPanel**)&this->ms_copy_text1);
    this->delete_panel((TPanel**)&this->ms_copy_text2);
    this->delete_panel((TPanel**)&this->warning_text);

    for (int i = 0; i < 7; i++) {
        this->delete_panel((TPanel**)&this->button[i]);
    }

    if (this->circle_p_pic != (TPanel*)0x0) {
        delete this->circle_p_pic;
    }
    if (this->ms_title_text != (TPanel*)0x0) {
        delete this->ms_title_text;
    }
}

// VA: 0049ECD0 TRIBE_Screen_Main_Menu::handle_idle
// PDB source: Scr_main.cpp lines 220-225.
long TRIBE_Screen_Main_Menu::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

// VA: 0049ED00 TRIBE_Screen_Main_Menu::key_down_action
// PDB source: Scr_main.cpp lines 231-258.
long TRIBE_Screen_Main_Menu::key_down_action(long key, short param_2,
                                             int param_3, int param_4,
                                             int param_5) {
    if (param_4 != 0) {
        switch (key) {
        case 0x4C:
            {
                if (rge_base_game->gameDeveloperMode() != 0) {
                    if (rge_base_game->load_db_files() == 0) {
                        TEasy_Panel::popupOKDialog(0x7D7, 0, 0x1C2, 100);
                    }
                }
                return 1;
            }

        case 0x43:
            new TRIBE_Credits_Screen();
            panel_system.setCurrentPanel("Credits Screen", 0);
            panel_system.destroyPanel("Main Menu");
            return 1;
        }
    }
    return 0;
}

// VA: 0049EE00 TRIBE_Screen_Main_Menu::action
// PDB source: Scr_main.cpp lines 264-387.
long TRIBE_Screen_Main_Menu::action(TPanel* panel, long event,
                                    unsigned long p3, unsigned long p4) {
    long result;

    if (panel != 0) {
        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "Confirm Dialog") == 0 &&
            event == 0) {
            panel_system.destroyPanel("Confirm Dialog");
            WinHelpA(rge_base_game->prog_window, "empires.hlp", 3, event);
            result = 1;
            goto done;
        }

        result = 1;
        if (event == 1) {
            if (panel == this->button[0]) {
                if (rge_base_game->save_check_for_cd == 0) {
                    if (rge_base_game->check_for_cd(0) == 0) {
                        this->popupOKDialog(0x7D8, 0, 0x1C2, 100);
                        goto done;
                    }
                    rge_base_game->save_check_for_cd = 1;
                }
                rge_base_game->disable_input();
                new TribeSPMenuScreen;
                panel_system.setCurrentPanel("Single Player Menu", 0);
                panel_system.destroyPanel("Main Menu");
                goto done;
            }

            if (panel == this->button[1]) {
                rge_base_game->disable_input();
                new TribeMPStartupScreen;
                panel_system.setCurrentPanel("MP Startup Screen", 0);
                panel_system.destroyPanel("Main Menu");
                goto done;
            }

            if (panel == this->button[2]) {
                this->popupOKDialog(0x1D4F7, "Confirm Dialog", 0x1C2, 100);
                goto done;
            }

            if (panel == this->button[3]) {
                if (rge_base_game->save_check_for_cd == 0) {
                    if (rge_base_game->check_for_cd(0) == 0) {
                        this->popupOKDialog(0x7DA, 0, 0x1C2, 100);
                        goto done;
                    }
                    rge_base_game->save_check_for_cd = 1;
                }
                rge_base_game->disable_input();
                new TRIBE_Screen_Sed_Menu;
                panel_system.setCurrentPanel("Scenario Editor Menu", 0);
                panel_system.destroyPanel("Main Menu");
                goto done;
            }

            if (panel == this->button[4]) {
                rge_base_game->close();
                goto done;
            }
        }
    }

    result = this->TEasy_Panel::action(panel, event, p3, p4);

done:
    return result;
}

// VA: 0049F0D0 TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error
// PDB source: Scr_main.cpp lines 395-420.
TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error()
    : TScreenPanel("Main Error Screen") {
    this->message = 0;
    this->cancel_button = 0;

    if (this->setup(rge_base_game->draw_area, "scr1", 0xC383, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);

    this->create_text((TPanel*)this, &this->message, "", 0x28, 0x28,
                      0x230, 0x190, 4, 1, 1, 1);
    this->create_button((TPanel*)this, &this->cancel_button, 0xFA1, 0,
                        0xC8, 0x1B8, 0xF0, 0x1E, 0, 0, 0);

    if (this->create_button((TPanel*)this, &this->close_button, 0x3EA, 0,
                            0, 0, 0, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0) != 0) {
        this->close_button->set_active(1);
        this->close_button->set_positioning(TPanel::PositionRightTop,
                                            4, 4, 4, 4, 0x11, 0x11,
                                            0x11, 0x11, 0, 0, 0, 0);
    }
}

// VA: 0049F240 TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error
// PDB source: Scr_main.cpp lines 426-429.
TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error() {
    this->delete_panel((TPanel**)&this->message);
    this->delete_panel((TPanel**)&this->cancel_button);
}

// VA: 0049F2B0 TRIBE_Screen_Main_Error::set_text(char*)
// PDB source: Scr_main.cpp lines 435-437.
void TRIBE_Screen_Main_Error::set_text(char* param) {
    this->message->set_text(param);
}

// VA: 0049F2D0 TRIBE_Screen_Main_Error::set_text(long)
// PDB source: Scr_main.cpp lines 443-445.
void TRIBE_Screen_Main_Error::set_text(long param) {
    this->message->set_text(param);
}

// VA: 0049F2F0 TRIBE_Screen_Main_Error::action
// PDB source: Scr_main.cpp lines 451-474.
long TRIBE_Screen_Main_Error::action(TPanel* param_1, long param_2,
                                     unsigned long param_3,
                                     unsigned long param_4) {
    TPanel* panel;
    long state;

    panel = param_1;
    state = param_2;

    if (panel == 0) {
        goto call_parent;
    }

    if (panel == (TPanel*)this->cancel_button && state == 1) {
        rge_base_game->close();
        return 1;
    }

    if (panel == (TPanel*)this->close_button && state == 1) {
        rge_base_game->close();
        return 1;
    }

call_parent:
    return this->TEasy_Panel::action(panel, state, param_3, param_4);
}

// VA: 0049F340 TRIBE_Screen_Main_Error::handle_idle
// PDB source: Scr_main.cpp lines 480-484.
long TRIBE_Screen_Main_Error::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}
