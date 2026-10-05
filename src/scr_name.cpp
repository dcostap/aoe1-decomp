
#include "../include/scr_name.h"
#include "../include/scr_cams.h"
#include "../include/scr_sing.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/pnl_edit.h"
#include "../include/gameinfo.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/resource_ids.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char name_selection_screen[] = "Name Selection Screen";
static char setup_info_file[] = "scr2";

TRIBE_Screen_Name::TRIBE_Screen_Name() : TScreenPanel(name_selection_screen) {
    this->init_vars();

    if (!this->TEasy_Panel::setup(rge_base_game->draw_area, 0, setup_info_file, 0xC384, 1, 0, 0, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(640, 480);

    if (!this->create_text(
            this, &this->title, STRING_ID_SELECT_PLAYER_TITLE, 20, 20, 600, 30, RGE_FONT_COPPERPLATE_21_BOLD, 1, 0, 0
        )) {
        return;
    }
    if (!this->create_text(
            this, &this->name_text, STRING_ID_PLAYER_NAME_LABEL, 60, 80, 140, 20, RGE_FONT_COPPERPLATE_12_BOLD_ALT, 0,
            0, 0
        )) {
        return;
    }
    if (!this->create_list(this, &this->name_list, 60, 100, 330, 300, RGE_FONT_STANDARD)) {
        return;
    }
    if (!this->create_auto_scrollbar(&this->name_scrollbar, this->name_list, 20)) {
        return;
    }

    this->name_scrollbar->set_help_info(STRING_ID_HELP_PLAYER_NAME_LIST, -1);

    if (!this->create_button(
            this, &this->new_button, STRING_ID_BUTTON_NEW_PLAYER, 0, 400, 100, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0,
            0
        )) {
        return;
    }
    this->new_button->set_help_info(STRING_ID_HELP_ADD_PLAYER_NAME, -1);

    if (!this->create_button(
            this, &this->remove_button, STRING_ID_BUTTON_REMOVE_PLAYER, 0, 400, 140, 180, 30,
            RGE_FONT_COPPERPLATE_12_BOLD, 0, 0
        )) {
        return;
    }
    this->remove_button->set_help_info(STRING_ID_HELP_REMOVE_PLAYER_NAME, -1);

    if (!this->create_button(
            this, &this->ok_button, STRING_ID_BUTTON_OK, 0, 70, 440, 240, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0
        )) {
        return;
    }
    this->ok_button->set_help_info(STRING_ID_HELP_OK, -1);

    if (!this->create_button(
            this, &this->cancel_button, STRING_ID_BUTTON_CANCEL, 0, 330, 440, 240, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0,
            0
        )) {
        return;
    }
    this->cancel_button->set_help_info(STRING_ID_HELP_CANCEL, -1);
    TButtonPanel* cancel = this->cancel_button;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;

    if (!this->create_button(this, &this->close_button, STRING_ID_BUTTON_CLOSE, 0, 0, 0, 0, 0, -1, -1, 0)) {
        return;
    }
    this->close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4, 4, 17, 17, 17, 17, 0, 0, 0, 0);
    this->setup_tab_order();
    this->get_player_names();
    this->started_input = 0;
}

TRIBE_Screen_Name::~TRIBE_Screen_Name() {
    panel_system.setCurrentPanel("New Name Dialog", 0);

    this->delete_panel((TPanel**) &this->title);
    this->delete_panel((TPanel**) &this->name_text);
    this->delete_panel((TPanel**) &this->name_list);
    this->delete_panel((TPanel**) &this->name_scrollbar);
    this->delete_panel((TPanel**) &this->new_button);
    this->delete_panel((TPanel**) &this->remove_button);
    this->delete_panel((TPanel**) &this->ok_button);
    this->delete_panel((TPanel**) &this->cancel_button);
    this->delete_panel((TPanel**) &this->close_button);
}

void TRIBE_Screen_Name::init_vars() {
    this->title = 0;
    this->name_text = 0;
    this->name_list = 0;
    this->name_scrollbar = 0;
    this->new_button = 0;
    this->remove_button = 0;
    this->ok_button = 0;
    this->cancel_button = 0;
    this->close_button = 0;
}

void TRIBE_Screen_Name::get_player_names() {
    this->name_list->empty_list();

    RGE_Game_Info* info = rge_base_game->player_game_info;
    char** players = 0;
    long curr_player;

    long count = info->get_people_list(&players, curr_player);

    if (count != 0) {
        this->name_list->sorted = 1;

        {
            int i;
            for (i = 0; i < count; i++) {
                this->name_list->append_line(players[i], i);
            }
        }

        this->name_list->set_line(this->name_list->get_line(curr_player));

        {
            int i;
            for (i = 0; i < count; i++) {
                free(players[i]);
            }
        }
        free(players);
    }
}

void TRIBE_Screen_Name::setup_tab_order() {
    int disabled = 0;
    if (this->name_list->numberLines() == 0) {
        disabled = 1;
    }

    this->remove_button->set_disabled(disabled);
    this->ok_button->set_disabled(disabled);

    TPanel* tab_list[5];
    tab_list[0] = this->name_list;
    tab_list[1] = this->new_button;

    int count = 2;
    if (disabled == 0) {
        tab_list[2] = this->remove_button;
        tab_list[3] = this->ok_button;
        count = 4;
    }

    tab_list[count] = this->cancel_button;
    count++;
    this->set_tab_order(tab_list, count);

    if (this->name_list->numberLines() == 0) {
        this->set_curr_child(this->new_button);
    } else {
        this->set_curr_child(this->name_list);
    }
}

long TRIBE_Screen_Name::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

long TRIBE_Screen_Name::action(
    TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2
) {
    long line;
    char str[256];

    if (from_panel != 0) {
        if (from_panel == this->ok_button && action_in == 1) {
            line = this->name_list->get_line();
            if (line == -1) {
                return action_in;
            } else {
                rge_base_game->disable_input();
                RGE_Game_Info* info = rge_base_game->player_game_info;
                info->set_current_person(this->name_list->get_id());
                new TRIBE_Screen_Campaign_Selection;
                panel_system.setCurrentPanel("Campaign Selection Screen", 0);
                panel_system.destroyPanel("Name Selection Screen");
            }
            return 1;
        }

        if (from_panel == this->cancel_button && action_in == 1) {
            rge_base_game->disable_input();
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel("Single Player Menu", 0);
            panel_system.destroyPanel("Name Selection Screen");
            return 1;
        }

        if (from_panel == this->close_button) {
            rge_base_game->close();
            return 1;
        }

        if (from_panel == this->name_list && action_in == 3) {
            this->action(this->ok_button, 1, 0, 0);
            return 1;
        }

        if (from_panel == this->new_button && action_in == 1) {
            new TRIBE_Dialog_Name(this);
            panel_system.setCurrentPanel("New Name Dialog", 0);
            return 1;
        }

        if (from_panel == this->remove_button && action_in == 1) {
            if (this->name_list->get_line() != -1) {
                sprintf(str, this->get_string(STRING_ID_CONFIRM_REMOVE_PLAYER), this->name_list->get_text());
                this->popupYesNoDialog(str, 0, TEASY_POPUP_WIDTH, 100);
                return action_in;
            }
            return 1;
        } else {
            if (from_panel->panelName() != 0 && strcmp(from_panel->panelName(), "New Name Dialog") == 0) {
                if (action_in == 1) {
                    this->get_player_names();
                }
                panel_system.setCurrentPanel("Name Selection Screen", 0);
                panel_system.destroyPanel("New Name Dialog");
                this->setup_tab_order();
                return 1;
            }

            if (from_panel->panelName() != 0 && strcmp(from_panel->panelName(), "YesNoDialog") == 0) {
                if (action_in == 0) {
                    line = this->name_list->get_line();
                    if (line != -1) {
                        RGE_Game_Info* info = rge_base_game->player_game_info;
                        info->remove_player(this->name_list->get_id(line));
                        this->get_player_names();
                    }
                }
                panel_system.destroyPanel("YesNoDialog");
                this->setup_tab_order();
                return 1;
            }
        }
    }

    return this->TEasy_Panel::action(from_panel, action_in, action_val1, action_val2);
}

TRIBE_Dialog_Name::TRIBE_Dialog_Name(TScreenPanel* parent_panel_in) : TDialogPanel("New Name Dialog") {
    this->title = 0;
    this->name_text = 0;
    this->name_input = 0;
    this->ok_button = 0;
    this->cancel_button = 0;

    if (!this->setup(
            parent_panel_in->renderArea(), parent_panel_in, 0x1f4, 0xe6, parent_panel_in->get_popup_info_file(),
            parent_panel_in->get_popup_info_id(), 1
        ))
        return;
    if (!this->create_text(
            this, &this->title, STRING_ID_NAME_DIALOG_TITLE, 20, 20, 460, 30, RGE_FONT_COPPERPLATE_21_BOLD, 1, 1, 0
        ))
        return;
    if (!this->create_text(
            this, &this->name_text, STRING_ID_NEW_PLAYER_NAME_LABEL, 40, 85, 420, 20, RGE_FONT_COPPERPLATE_12_BOLD_ALT,
            0, 1, 0
        ))
        return;
    if (!this->create_edit(
            this, &this->name_input, "", 0x0f, TEditPanel::FormatText, 40, 110, 420, 23, RGE_FONT_STANDARD, 1, 1
        ))
        return;
    if (!this->create_button(
            this, &this->ok_button, STRING_ID_BUTTON_OK, 0, 60, 180, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0
        ))
        return;
    if (!this->create_button(
            this, &this->cancel_button, STRING_ID_BUTTON_CANCEL, 0, 260, 180, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0,
            0
        ))
        return;

    TButtonPanel* cancel = this->cancel_button;
    cancel->hotkey = 0x1b;
    cancel->hotkey_shift = 0;
    TPanel* tab_list[3];
    tab_list[0] = this->name_input;
    tab_list[1] = this->ok_button;
    tab_list[2] = this->cancel_button;
    this->set_tab_order(tab_list, 3);
    this->set_curr_child(this->name_input);
}

TRIBE_Dialog_Name::~TRIBE_Dialog_Name() {
    this->delete_panel((TPanel**) &this->title);
    this->delete_panel((TPanel**) &this->name_text);
    this->delete_panel((TPanel**) &this->name_input);
    this->delete_panel((TPanel**) &this->ok_button);
    this->delete_panel((TPanel**) &this->cancel_button);
}

long TRIBE_Dialog_Name::action(
    TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2
) {
    if (from_panel != 0) {
        if ((from_panel == this->ok_button && action_in == 1) || (from_panel == this->name_input && action_in == 0)) {
            if (this->name_input->get_text()[0] == 0) {
                this->set_curr_child(this->name_input);
                return 1;
            }
            RGE_Game_Info* info = rge_base_game->player_game_info;
            info->add_new_person(this->name_input->get_text());
            new TRIBE_Screen_Campaign_Selection;
            panel_system.setCurrentPanel("Campaign Selection Screen", 0);
            panel_system.destroyPanel("New Name Dialog");
            panel_system.destroyPanel("Name Selection Screen");
            return 1;
        }

        if ((from_panel == this->cancel_button && action_in == 1)
            || (from_panel == this->name_input && action_in == 1)) {
            if (panel_system.panel("Name Selection Screen") != 0) {
                panel_system.setCurrentPanel("Name Selection Screen", 0);
            } else {
                new TribeSPMenuScreen;
                panel_system.setCurrentPanel("Single Player Menu", 0);
            }
            panel_system.destroyPanel("New Name Dialog");
            return 1;
        }
    }

    return this->TEasy_Panel::action(from_panel, action_in, action_val1, action_val2);
}

long TRIBE_Dialog_Name::wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    return TPanel::wnd_proc(hwnd, msg, wParam, lParam);
}
