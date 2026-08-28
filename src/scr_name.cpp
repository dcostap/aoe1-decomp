// PDB source module: C:/msdev/work/age1_x1/scr_name.cpp.
// Definitions follow the original PDB source order.

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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char name_selection_screen[] = "Name Selection Screen";
static char setup_info_file[] = "scr2";

// 004A63D0 TRIBE_Screen_Name (scr_name.cpp:50-96)
TRIBE_Screen_Name::TRIBE_Screen_Name()
    : TScreenPanel(name_selection_screen)
{
    this->init_vars();

    if (!this->TEasy_Panel::setup(rge_base_game->draw_area, 0, setup_info_file,
                                  0xC384, 1, 0, 0, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (!this->create_text(this, &this->title, 0x29FE,
                           0x14, 0x14, 0x258, 0x1E, 1, 1, 0, 0)) {
        return;
    }
    if (!this->create_text(this, &this->name_text, 0x29FF,
                           0x3C, 0x50, 0x8C, 0x14, 4, 0, 0, 0)) {
        return;
    }
    if (!this->create_list(this, &this->name_list,
                           0x3C, 0x64, 0x14A, 0x12C, 0x0B)) {
        return;
    }
    if (!this->create_auto_scrollbar(&this->name_scrollbar,
                                     this->name_list, 0x14)) {
        return;
    }

    this->name_scrollbar->set_help_info(0x765C, -1);

    if (!this->create_button(this, &this->new_button, 0x2A00,
                             0, 0x190, 0x64, 0xB4, 0x1E, 0, 0, 0)) {
        return;
    }
    this->new_button->set_help_info(0x765D, -1);

    if (!this->create_button(this, &this->remove_button, 0x2A01,
                             0, 0x190, 0x8C, 0xB4, 0x1E, 0, 0, 0)) {
        return;
    }
    this->remove_button->set_help_info(0x765E, -1);

    if (!this->create_button(this, &this->ok_button, 0x0FA1,
                             0, 0x46, 0x1B8, 0xF0, 0x1E, 0, 0, 0)) {
        return;
    }
    this->ok_button->set_help_info(0x7531, -1);

    if (!this->create_button(this, &this->cancel_button, 0x0FA2,
                             0, 0x14A, 0x1B8, 0xF0, 0x1E, 0, 0, 0)) {
        return;
    }
    this->cancel_button->set_help_info(0x7532, -1);
    TButtonPanel* cancel = this->cancel_button;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;

    if (!this->create_button(this, &this->close_button, 0x03EA,
                             0, 0, 0, 0, 0, -1, -1, 0)) {
        return;
    }
    this->close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4, 4, 0x11, 0x11,
                                        0x11, 0x11, 0, 0, 0, 0);
    this->setup_tab_order();
    this->get_player_names();
    this->started_input = 0;
}

// 004A66E0 TRIBE_Screen_Name::~TRIBE_Screen_Name (scr_name.cpp:102-114)
TRIBE_Screen_Name::~TRIBE_Screen_Name()
{
    panel_system.setCurrentPanel("New Name Dialog", 0);

    delete this->title;
    delete this->name_text;
    delete this->name_list;
    delete this->name_scrollbar;
    delete this->new_button;
    delete this->remove_button;
    delete this->ok_button;
    delete this->cancel_button;
    delete this->close_button;
}

// 004A67C0 init_vars (scr_name.cpp:120-130)
void TRIBE_Screen_Name::init_vars()
{
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

// 004A6800 TRIBE_Screen_Name::get_player_names (scr_name.cpp:136-163)
void TRIBE_Screen_Name::get_player_names()
{
    this->name_list->empty_list();

    RGE_Game_Info* info = rge_base_game->player_game_info;
    char** players = 0;
    long current_player;

    long count = info->get_people_list(&players, current_player);

    if (count != 0) {
        this->name_list->sorted = 1;

        {
            int i;
            for (i = 0; i < count; i++) {
                this->name_list->append_line(players[i], i);
            }
        }

        this->name_list->set_line(this->name_list->get_line(current_player));

        {
            int i;
            for (i = 0; i < count; i++) {
                free(players[i]);
            }
        }
        free(players);
    }
}

// 004A68C0 TRIBE_Screen_Name::setup_tab_order (scr_name.cpp:169-197)
void TRIBE_Screen_Name::setup_tab_order()
{
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

// 004A6980 TRIBE_Screen_Name::handle_idle (scr_name.cpp:204-219)
long TRIBE_Screen_Name::handle_idle()
{
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

// 004A69B0 TRIBE_Screen_Name::action (scr_name.cpp:225-322)
long TRIBE_Screen_Name::action(TPanel* panel, long event, unsigned long p3,
                               unsigned long p4)
{
    long line;
    char str[256];

    if (panel != 0) {
        if (panel == this->ok_button && event == 1) {
            line = this->name_list->get_line();
            if (line == -1) {
                return event;
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

        if (panel == this->cancel_button && event == 1) {
            rge_base_game->disable_input();
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel("Single Player Menu", 0);
            panel_system.destroyPanel("Name Selection Screen");
            return 1;
        }

        if (panel == this->close_button) {
            rge_base_game->close();
            return 1;
        }

        if (panel == this->name_list && event == 3) {
            this->action(this->ok_button, 1, 0, 0);
            return 1;
        }

        if (panel == this->new_button && event == 1) {
            new TRIBE_Dialog_Name(this);
            panel_system.setCurrentPanel("New Name Dialog", 0);
            return 1;
        }

        if (panel == this->remove_button && event == 1) {
            if (this->name_list->get_line() != -1) {
                sprintf(str, this->get_string(0x2A02),
                        this->name_list->get_text());
                this->popupYesNoDialog(str, 0, 0x1C2, 100);
                return event;
            }
            return 1;
        } else {
            if (panel->panelName() != 0 &&
                strcmp(panel->panelName(), "New Name Dialog") == 0) {
                if (event == 1) {
                    this->get_player_names();
                }
                panel_system.setCurrentPanel("Name Selection Screen", 0);
                panel_system.destroyPanel("New Name Dialog");
                this->setup_tab_order();
                return 1;
            }

            if (panel->panelName() != 0 &&
                strcmp(panel->panelName(), "YesNoDialog") == 0) {
                if (event == 0) {
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

    return this->TEasy_Panel::action(panel, event, p3, p4);
}

// 004A6D50 TRIBE_Dialog_Name::TRIBE_Dialog_Name (scr_name.cpp:329-361)
// BINARY NOTE: The original uses the three-word, address-taken tab window.
// Its first home remains unused by the source logic but is kept for the
// shipped stack and register schedule.
TRIBE_Dialog_Name::TRIBE_Dialog_Name(TScreenPanel* screen)
    : TDialogPanel("New Name Dialog")
{
    TPanel* tab_list[3];
    this->title = 0;
    this->name_text = 0;
    this->name_input = 0;
    this->ok_button = 0;
    this->cancel_button = 0;

    if (!this->setup(screen->renderArea(), screen, 0x1f4, 0xe6,
                     screen->get_popup_info_file(), screen->get_popup_info_id(),
                     1))
        return;
    if (!this->create_text(this, &this->title, 0x2a03,
                           0x14, 0x14, 0x1cc, 0x1e, 1, 1, 1, 0))
        return;
    if (!this->create_text(this, &this->name_text, 0x2a04,
                           0x28, 0x55, 0x1a4, 0x14, 4, 0, 1, 0))
        return;
    if (!this->create_edit(this, &this->name_input, "", 0x0f,
                           TEditPanel::FormatText, 0x28, 0x6e, 0x1a4,
                           0x17, 0x0b, 1, 1))
        return;
    if (!this->create_button(this, &this->ok_button, 0x0fa1,
                             0, 0x3c, 0x0b4, 0x0b4, 0x1e, 0, 0, 0))
        return;
    if (!this->create_button(this, &this->cancel_button, 0x0fa2,
                             0, 0x104, 0x0b4, 0x0b4, 0x1e, 0, 0, 0))
        return;

    this->cancel_button->hotkey = 0x1b;
    this->cancel_button->hotkey_shift = 0;
    tab_list[1] = this->name_input;
    tab_list[2] = this->ok_button;
    this->set_tab_order(&tab_list[1], 3);
    this->set_curr_child(this->name_input);
}

// 004A6F60 TRIBE_Dialog_Name::~TRIBE_Dialog_Name (scr_name.cpp:367-373)
TRIBE_Dialog_Name::~TRIBE_Dialog_Name()
{
    delete this->title;
    delete this->name_text;
    delete this->name_input;
    delete this->ok_button;
    delete this->cancel_button;
}

// 004A6FF0 TRIBE_Dialog_Name::action (scr_name.cpp:379-423)
long TRIBE_Dialog_Name::action(TPanel* panel, long p2, unsigned long p3,
                               unsigned long p4)
{
    if (panel != 0) {
        if ((panel == this->ok_button && p2 == 1) ||
            (panel == this->name_input && p2 == 0)) {
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

        if ((panel == this->cancel_button && p2 == 1) ||
            (panel == this->name_input && p2 == 1)) {
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

    return this->TEasy_Panel::action(panel, p2, p3, p4);
}

// 004A71D0 TRIBE_Dialog_Name::wnd_proc (scr_name.cpp:429-440)
long TRIBE_Dialog_Name::wnd_proc(void* param1, unsigned int param2,
                                 unsigned int param3, long param4)
{
    return TPanel::wnd_proc(param1, param2, param3, param4);
}
