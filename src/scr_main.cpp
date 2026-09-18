
#include "../include/scr_main.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/pnl_pic.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/tribegam.h"
#include "../include/scr_cred.h"
#include "../include/scr_sing.h"
#include "../include/scr_mp.h"
#include "../include/scr_sedm.h"
#include "../include/resource_ids.h"
#include <string.h>

TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu()
    : TScreenPanel("Main Menu") {
    RECT rect;
    TPanel* tabList[5];
    char temp_str[512];
    int diff;
    int i;
    this->title1 = 0;
    this->title2 = 0;
    this->circle_p_pic = 0;
    this->ms_title_text = 0;
    this->ms_copy_text1 = 0;
    this->ms_copy_text2 = 0;
    this->warning_text = 0;

    TButtonPanel** clear_button = this->button;
    for (i = 7; i != 0; --i) {
        *clear_button++ = 0;
    }

    if (this->setup(rge_base_game->draw_area, "scr1", 0xC383, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(640, 480);

    long button_width = 178;
    clear_button = this->button;
    for (; button_width < 428; button_width += 50, ++clear_button) {
        if (this->create_button(this, clear_button, "", 0, 170, button_width, 300, 40, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0) == 0) {
            return;
        }
    }

    this->button[0]->set_text(0, STRING_ID_MENU_SINGLE_PLAYER);
    this->button[1]->set_text(0, STRING_ID_MENU_MULTIPLAYER);
    this->button[2]->set_text(0, STRING_ID_MENU_HELP);
    this->button[3]->set_text(0, STRING_ID_MENU_SCENARIO_BUILDER);
    this->button[4]->set_text(0, STRING_ID_MENU_EXIT);

    this->set_ideal_size(this->pnl_wid, this->pnl_hgt);

    long panel_height = this->pnl_hgt - 60;
    this->create_text(this, &this->ms_title_text, STRING_ID_PRODUCT_TITLE, 5, panel_height, this->pnl_wid - 10, 18, RGE_FONT_ARIAL_10_NORMAL_ALT, 1, 0, 0);

    this->get_string(STRING_ID_COPYRIGHT_SEPARATOR, temp_str, 512);
    if (temp_str[0] == 0) {
        TTextPanel** copy1 = &this->ms_copy_text1;
        this->create_text(this, copy1, STRING_ID_COPYRIGHT_PREFIX, 5, panel_height + 18, 50, 18, RGE_FONT_ARIAL_10_NORMAL_ALT, 0, 0, 0);

        if ((*copy1)->get_text_rect(&rect) != 0) {
            this->circle_p_pic = new TPicturePanel;
            if (this->circle_p_pic != 0) {
                this->circle_p_pic->setup(this->render_area, this, rect.right - this->pnl_x + 3, rect.top + 1, 15, 14,
                                          "circlep2", 0xC4E6, 0, 1);

                TTextPanel** copy2 = &this->ms_copy_text2;
                this->create_text(this, copy2, STRING_ID_COPYRIGHT_SUFFIX, this->circle_p_pic->xPosition() - this->pnl_x +
                                  this->circle_p_pic->width(), rect.top, 500, 18, RGE_FONT_ARIAL_10_NORMAL_ALT, 0, 0, 0);

                if ((*copy2)->get_text_rect(&rect) != 0) {
                    diff = (this->pnl_wid - rect.right - 5) / 2;
                    if (diff > 0) {
                        (*copy1)->set_fixed_position((*copy1)->xPosition() + diff, (*copy1)->yPosition(), (*copy1)->width(),
                                                     (*copy1)->height());
                        this->circle_p_pic->set_fixed_position(this->circle_p_pic->xPosition() + diff,
                                                               this->circle_p_pic->yPosition(), this->circle_p_pic->width(), this->circle_p_pic->height());
                        (*copy2)->set_fixed_position((*copy2)->xPosition() + diff, (*copy2)->yPosition(), (*copy2)->width(),
                                                     (*copy2)->height());
                    }
                }
            }
        }
    } else {
        strcpy(temp_str, this->get_string(STRING_ID_COPYRIGHT_PREFIX));
        strcat(temp_str, this->get_string(STRING_ID_COPYRIGHT_SEPARATOR));
        strcat(temp_str, " ");
        strcat(temp_str, this->get_string(STRING_ID_COPYRIGHT_SUFFIX));

        this->create_text(this, &this->ms_copy_text1, temp_str, 5, panel_height + 18, this->pnl_wid - 10, 18, RGE_FONT_ARIAL_10_NORMAL_ALT, 1, 0, 0);
    }

    this->create_text(this, &this->warning_text, STRING_ID_COPYRIGHT_WARNING, 5, panel_height + 36, this->pnl_wid - 10,
                      18, RGE_FONT_ARIAL_10_NORMAL_ALT, 1, 0, 0);

    this->set_ideal_size(640, 480);

    TPanel** tab_dst = tabList;
    TButtonPanel** tab_src = this->button;
    for (i = 5; i != 0; --i) {
        *tab_dst++ = *tab_src++;
    }
    this->set_tab_order(tabList, 5);
    this->set_curr_child(this->button[0]);
}

TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu() {
    this->delete_panel((TPanel**)&this->title1);
    this->delete_panel((TPanel**)&this->title2);
    this->delete_panel((TPanel**)&this->ms_copy_text1);
    this->delete_panel((TPanel**)&this->ms_copy_text2);
    this->delete_panel((TPanel**)&this->warning_text);

    for (int i = 0; i < 7; i++) {
        this->delete_panel((TPanel**)&this->button[i]);
    }

    if (this->circle_p_pic != 0) {
        delete this->circle_p_pic;
    }
    if (this->ms_title_text != 0) {
        delete this->ms_title_text;
    }
}

long TRIBE_Screen_Main_Menu::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

long TRIBE_Screen_Main_Menu::key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    if (ctrl_key != 0) {
        switch (key) {
        case 0x4C:
            {
                if (rge_base_game->gameDeveloperMode() != 0) {
                    if (static_cast<TRIBE_Game*>(rge_base_game)->load_db_files() == 0) {
                        TEasy_Panel::popupOKDialog(STRING_ID_ERROR_LOAD_GAME_DATA, 0, TEASY_POPUP_WIDTH, 100);
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

long TRIBE_Screen_Main_Menu::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    long result;

    if (fromPanel != 0) {
        if (fromPanel->panelName() != 0 && strcmp(fromPanel->panelName(), "Confirm Dialog") == 0 && actionIn == 0) {
            panel_system.destroyPanel("Confirm Dialog");
            WinHelpA(rge_base_game->prog_window, "empires.hlp", 3, actionIn);
            result = 1;
            goto done;
        }

        if (actionIn == 1) {
            if (fromPanel == this->button[0]) {
                if (rge_base_game->save_check_for_cd == 0) {
                    if (rge_base_game->check_for_cd(0) == 0) {
                        this->popupOKDialog(STRING_ID_ERROR_INSERT_CD_SINGLE_PLAYER, 0, TEASY_POPUP_WIDTH, 100);
                        result = 1;
                        goto done;
                    }
                    RGE_Base_Game* game = rge_base_game;
                    game->save_check_for_cd = 1;
                }
                rge_base_game->disable_input();
                new TribeSPMenuScreen;
                panel_system.setCurrentPanel("Single Player Menu", 0);
                panel_system.destroyPanel("Main Menu");
                result = 1;
                goto done;
            }

            if (fromPanel == this->button[1]) {
                rge_base_game->disable_input();
                new TribeMPStartupScreen;
                panel_system.setCurrentPanel("MP Startup Screen", 0);
                panel_system.destroyPanel("Main Menu");
                result = 1;
                goto done;
            }

            if (fromPanel == this->button[2]) {
                this->popupOKDialog(STRING_ID_HELP_NOTICE, "Confirm Dialog", TEASY_POPUP_WIDTH, 100);
                result = 1;
                goto done;
            }

            if (fromPanel == this->button[3]) {
                if (rge_base_game->save_check_for_cd == 0) {
                    if (rge_base_game->check_for_cd(0) == 0) {
                        this->popupOKDialog(STRING_ID_ERROR_INSERT_CD_SCENARIO_BUILDER, 0, TEASY_POPUP_WIDTH, 100);
                        result = 1;
                        goto done;
                    }
                    RGE_Base_Game* game = rge_base_game;
                    game->save_check_for_cd = 1;
                }
                rge_base_game->disable_input();
                new TRIBE_Screen_Sed_Menu;
                panel_system.setCurrentPanel("Scenario Editor Menu", 0);
                panel_system.destroyPanel("Main Menu");
                result = 1;
                goto done;
            }

            if (fromPanel == this->button[4]) {
                rge_base_game->close();
                result = 1;
                goto done;
            }
        }
    }

    result = this->TEasy_Panel::action(fromPanel, actionIn, a1, a2);

done:
    return result;
}

TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error()
    : TScreenPanel("Main Error Screen") {
    this->message = 0;
    this->cancel_button = 0;

    if (this->setup(rge_base_game->draw_area, "scr1", 0xC383, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(640, 480);

    this->create_text(this, &this->message, "", 40, 40, 560, 400, RGE_FONT_COPPERPLATE_12_BOLD_ALT, 1, 1, 1);
    this->create_button(this, &this->cancel_button, STRING_ID_BUTTON_OK, 0, 200, 440, 240, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);

    if (this->create_button(this, &this->close_button, STRING_ID_BUTTON_CLOSE, 0, 0, 0, 0, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0) != 0) {
        this->close_button->set_active(1);
        this->close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4, 4, 17, 17, 17, 17, 0, 0, 0, 0);
    }
}

TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error() {
    this->delete_panel((TPanel**)&this->message);
    this->delete_panel((TPanel**)&this->cancel_button);
}

void TRIBE_Screen_Main_Error::set_text(char* message_in) {
    this->message->set_text(message_in);
}

void TRIBE_Screen_Main_Error::set_text(long message_in) {
    this->message->set_text(message_in);
}

long TRIBE_Screen_Main_Error::action(TPanel* from_panel, long action_in, unsigned long val1, unsigned long val2) {
    TPanel* panel;
    long state;

    panel = from_panel;
    state = action_in;

    if (panel == 0) {
        goto call_parent;
    }

    if (panel == this->cancel_button && state == 1) {
        rge_base_game->close();
        return 1;
    }

    if (panel == this->close_button && state == 1) {
        rge_base_game->close();
        return 1;
    }

call_parent:
    return this->TEasy_Panel::action(panel, state, val1, val2);
}

long TRIBE_Screen_Main_Error::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}
