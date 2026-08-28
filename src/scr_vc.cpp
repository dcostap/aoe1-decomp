// PDB source module: C:\\msdev\\work\\age1_x1\\scr_vc.cpp.
// Definitions follow the original source order.

#include <string.h>

#include "../include/scr_vc.h"
#include "../include/pnl_lst.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_scbr.h"
#include "../include/Picture.h"
#include "../include/basegame.h"
#include "../include/tribegam.h"
#include "../include/world.h"
#include "../include/scenario.h"
#include "../include/main.h"
#include "../include/sounddrv.h"
#include "../include/rge_base_game_global.h"

// VA: 004B8100 TRIBE_Mission_Screen::TRIBE_Mission_Screen
// PDB: scr_vc.cpp:45-194
TRIBE_Mission_Screen::TRIBE_Mission_Screen(char* info_file,
                                           unsigned char game_flag,
                                           TPicture* vc_back_bmp)
    : TScreenPanel("Mission Dialog")
{
    char adjusted_name[260];
    char setup_file[260];
    unsigned char starting_description = 0;

    this->game_flag = game_flag;
    this->title = 0;
    this->ok_button = 0;
    this->list = 0;
    this->scroll_bar = 0;
    this->vc_back_bmp = 0;
    memset(this->text_buttons, 0, sizeof(this->text_buttons));

    panel_system.currentPanel();
    strcpy(setup_file, "scr9");

    if (!setup(rge_base_game->draw_area, setup_file, 0xC38C, 1)) {
        this->error_code = 1;
        return;
    }

    setup_shadow_area(0);
    set_ideal_size(0x280, 0x1E0);

    char* scenario_name = rge_base_game->world->scenario->Get_scenario_name();
    if (scenario_name != 0 && scenario_name[0] != 0) {
        strcpy(adjusted_name, scenario_name);
        // The shipped executable truncates the copied name by four bytes.
        adjusted_name[strlen(scenario_name) - 4] = 0;
    } else {
        strcpy(adjusted_name, get_string(0x2655));
    }

    create_text(this, &this->title, adjusted_name, 10, 0xF, 0x26C,
                0x14, 4, 1, 1, 0);
    create_text(this, &this->list, info_file, 0xF, 0x46, 0x12C,
                0x154, 0xB, 0, 0, 1);
    create_auto_scrollbar(&this->scroll_bar, this->list, 0x14);

    if (this->use_bevels) {
        this->list->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                                   this->bevel_color3, this->bevel_color4,
                                   this->bevel_color5, this->bevel_color6);
    }

    create_button(this, &this->ok_button, 0xFA1, 0, 0xC8, 0x1B8,
                  0xF0, 0x1E, 0, 0, 0);
    create_button(this, &this->text_buttons[0], 0x2A31, 0, 0x145,
                  0x13C, 0xB4, 0x1E, 0, -1, 0);
    TButtonPanel** text_button_1 = &this->text_buttons[1];
    create_button(this, text_button_1, 0x2A32, 0, 0x145, 0x15C,
                  0xB4, 0x1E, 0, -1, 0);
    create_button(this, &this->text_buttons[2], 0x2A37, 0, 0x145,
                  0x17C, 0xB4, 0x1E, 0, -1, 0);

    for (int i = 0; i < 3; i++) {
        this->text_buttons[i]->set_radio_info(this->text_buttons, 3);
    }

    if (this->pnl_wid <= 0x280) {
        this->title->set_fixed_position(3, 0xF, 0x27A, 0x14);
        this->list->set_fixed_position(0x14, 0x32, 0x258, 0x73);
        this->text_buttons[0]->set_fixed_position(5, 0x1BD, 0x96, 0x1E);
        (*text_button_1)->set_fixed_position(0xA5, 0x1BD, 0x96, 0x1E);
        this->text_buttons[2]->set_fixed_position(0x145, 0x1BD, 0x96, 0x1E);
        this->ok_button->set_fixed_position(0x1E5, 0x1BD, 0x96, 0x1E);
    } else if (this->pnl_wid <= 0x320) {
        set_ideal_size(0x320, 0x280);
        this->title->set_fixed_position(3, 0xF, 0x31A, 0x14);
        this->list->set_fixed_position(0x1E, 0x2D, 0x2E4, 0xE6);
        this->text_buttons[0]->set_fixed_position(5, 0x235, 0xBE, 0x1E);
        (*text_button_1)->set_fixed_position(0xCD, 0x235, 0xBE, 0x1E);
        this->text_buttons[2]->set_fixed_position(0x195, 0x235, 0xBE, 0x1E);
        this->ok_button->set_fixed_position(0x25D, 0x235, 0xBE, 0x1E);
    } else {
        set_ideal_size(0x400, 0x300);
        this->title->set_fixed_position(3, 0xF, 0x3FA, 0x14);
        this->list->set_fixed_position(0x28, 0x41, 0x3B0, 0x136);
        this->text_buttons[0]->set_fixed_position(10, 0x2B2, 0xF0, 0x32);
        (*text_button_1)->set_fixed_position(0x10A, 0x2B2, 0xF0, 0x32);
        this->text_buttons[2]->set_fixed_position(0x20A, 0x2B2, 0xF0, 0x32);
        this->ok_button->set_fixed_position(0x306, 0x2B2, 0xF0, 0x32);
    }

    if (rge_base_game->world->scenario->Get_message(0) != 0) {
        this->list->set_text(rge_base_game->world->scenario->Get_message(0));
        (*text_button_1)->set_radio_button();
        starting_description = 1;
    } else {
        (*text_button_1)->set_active(0);
    }

    if (rge_base_game->world->scenario->Get_message(4) != 0) {
        if (!starting_description) {
            this->list->set_text(rge_base_game->world->scenario->Get_message(4));
            this->text_buttons[0]->set_radio_button();
        }
        starting_description++;
    } else {
        this->text_buttons[0]->set_active(0);
    }

    if (rge_base_game->world->scenario->Get_message(1) != 0) {
        if (!starting_description) {
            this->list->set_text(rge_base_game->world->scenario->Get_message(1));
            this->text_buttons[2]->set_radio_button();
        }
        starting_description++;
    } else {
        this->text_buttons[2]->set_active(0);
        if (!starting_description) {
            this->list->set_active(0);
        }
    }

    if (starting_description == 1) {
        this->text_buttons[0]->set_active(0);
        this->text_buttons[1]->set_active(0);
        this->text_buttons[2]->set_active(0);
    }

    set_curr_child(this->ok_button);
    this->vc_back_bmp = vc_back_bmp;
}

// VA: 004B87D0 TRIBE_Mission_Screen::~TRIBE_Mission_Screen
// PDB: scr_vc.cpp:200-219
TRIBE_Mission_Screen::~TRIBE_Mission_Screen()
{
    if (this->game_flag == 0) {
        RGE_Base_Game* game = rge_base_game;
        if (game->prog_info->use_sound != 0 && game->sound_system != 0) {
            game->sound_system->stop_stream();
        }
    }

    delete this->title;
    delete this->list;
    delete this->scroll_bar;
    delete this->ok_button;

    for (int i = 0; i < 3; i++) {
        delete this->text_buttons[i];
    }
}

// VA: 004B88B0 TRIBE_Mission_Screen::handle_idle
// PDB: scr_vc.cpp:225-230
long TRIBE_Mission_Screen::handle_idle()
{
    if (!rge_base_game->input_enabled) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

// VA: 004B88E0 TRIBE_Mission_Screen::draw
// PDB: scr_vc.cpp:236-260
void TRIBE_Mission_Screen::draw()
{
    TScreenPanel::draw();

    if (this->vc_back_bmp != 0) {
        this->draw_setup(0);

        if (this->need_redraw == 2) {
            this->render_area->Clear(&this->clip_rect, this->background_color1);
        }

        unsigned char* locked = this->render_area->Lock((char*)"scr_vc::draw", 1);
        if (locked != 0) {
            if (this->pnl_wid <= 0x280) {
                this->vc_back_bmp->Draw(this->render_area,
                                        this->pnl_x + 7,
                                        this->pnl_y + 0xA6, 0, 0);
            } else if (this->pnl_wid <= 0x320) {
                this->vc_back_bmp->Draw(this->render_area,
                                        this->pnl_x + 0x53,
                                        this->pnl_y + 0x118, 0, 0);
            } else {
                this->vc_back_bmp->Draw(this->render_area,
                                        this->pnl_x + 0xC5,
                                        this->pnl_y + 0x16B, 0, 0);
            }
            this->render_area->Unlock((char*)"scr_vc::draw");
        }

        this->draw_finish();
    }
}

// VA: 004B89A0 TRIBE_Mission_Screen::action
// PDB: scr_vc.cpp:266-293
long TRIBE_Mission_Screen::action(TPanel* sender, long actionType,
                                  unsigned long param3,
                                  unsigned long param4)
{
    if (actionType == 1) {
        if (sender == this->text_buttons[0]) {
            this->list->set_text(rge_base_game->world->scenario->Get_message(4));
        }

        if (sender == this->text_buttons[1]) {
            this->list->set_text(rge_base_game->world->scenario->Get_message(0));
        }

        if (sender == this->text_buttons[2]) {
            this->list->set_text(rge_base_game->world->scenario->Get_message(1));
        }

        if (sender == this->ok_button) {
            if (this->game_flag != 0) {
                panel_system.setCurrentPanel((char*)"Game Screen", 0);
                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
            } else {
                ((TRIBE_Game*)rge_base_game)->create_game_screen();
            }

            panel_system.destroyPanel((char*)"Mission Dialog");
            return 1;
        }
    }

    return TEasy_Panel::action(sender, actionType, param3, param4);
}

// VA: 004B8AE0 TRIBE_Mission_Screen::key_down_action
// PDB: scr_vc.cpp:299-307
long TRIBE_Mission_Screen::key_down_action(long param_1, short param_2,
                                           int param_3, int param_4,
                                           int param_5)
{
    if (param_4 == 0 || param_1 != 0x56) {
        return 0;
    }

    if (this->game_flag == 0 && rge_base_game->prog_info->use_sound != 0 &&
        rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->stream_file((char*)"voice.wav", 0, 0);
    }
    return 1;
}
