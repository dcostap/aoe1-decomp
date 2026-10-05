
#include <string.h>

#include "../include/scr_vc.h"
#include "../include/pnl_lst.h"
#include "../include/pnl_btn.h"
#include "../include/Pnl_scbr.h"
#include "../include/Picture.h"
#include "../include/basegame.h"
#include "../include/tribegam.h"
#include "../include/world.h"
#include "../include/scenario.h"
#include "../include/main.h"
#include "../include/sounddrv.h"
#include "../include/rge_base_game_global.h"
#include "../include/resource_ids.h"

TRIBE_Mission_Screen::TRIBE_Mission_Screen(char* text_in, unsigned char from_game, TPicture* background_bmp) :
    TScreenPanel("Mission Dialog") {
    char adjusted_name[260];
    char info_file[260];
    unsigned char starting_description = 0;

    this->game_flag = from_game;
    this->title = 0;
    this->ok_button = 0;
    this->list = 0;
    this->scroll_bar = 0;
    this->vc_back_bmp = 0;
    memset(this->text_buttons, 0, sizeof(this->text_buttons));

    panel_system.currentPanel();
    strcpy(info_file, "scr9");

    if (!setup(rge_base_game->draw_area, info_file, 0xC38C, 1)) {
        this->error_code = 1;
        return;
    }

    setup_shadow_area(0);
    set_ideal_size(640, 480);

    char* scenario_name = rge_base_game->world->scenario->Get_scenario_name();
    if (scenario_name != 0 && scenario_name[0] != 0) {
        strcpy(adjusted_name, scenario_name);
        // The shipped executable truncates the copied name by four bytes.
        adjusted_name[strlen(scenario_name) - 4] = 0;
    } else {
        strcpy(adjusted_name, get_string(STRING_ID_MISSION_TITLE_INSTRUCTIONS));
    }

    create_text(this, &this->title, adjusted_name, 10, 15, 620, 20, RGE_FONT_COPPERPLATE_12_BOLD_ALT, 1, 1, 0);
    create_text(this, &this->list, text_in, 15, 70, 300, 340, RGE_FONT_STANDARD, 0, 0, 1);
    create_auto_scrollbar(&this->scroll_bar, this->list, 20);

    if (this->use_bevels) {
        this->list->set_bevel_info(
            3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5,
            this->bevel_color6
        );
    }

    create_button(
        this, &this->ok_button, STRING_ID_BUTTON_OK, 0, 200, 440, 240, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0
    );
    create_button(
        this, &this->text_buttons[0], STRING_ID_MISSION_HISTORY, 0, 325, 316, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, -1,
        0
    );
    TButtonPanel** text_button_1 = &this->text_buttons[1];
    create_button(
        this, text_button_1, STRING_ID_MISSION_INSTRUCTIONS, 0, 325, 348, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, -1, 0
    );
    create_button(
        this, &this->text_buttons[2], STRING_ID_MISSION_HINTS, 0, 325, 380, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, -1, 0
    );

    for (int i = 0; i < 3; i++) {
        this->text_buttons[i]->set_radio_info(this->text_buttons, 3);
    }

    if (this->pnl_wid <= 640) {
        this->title->set_fixed_position(3, 15, 634, 20);
        this->list->set_fixed_position(20, 50, 600, 115);
        this->text_buttons[0]->set_fixed_position(5, 445, 150, 30);
        (*text_button_1)->set_fixed_position(165, 445, 150, 30);
        this->text_buttons[2]->set_fixed_position(325, 445, 150, 30);
        this->ok_button->set_fixed_position(485, 445, 150, 30);
    } else if (this->pnl_wid <= 800) {
        set_ideal_size(800, 640);
        this->title->set_fixed_position(3, 15, 794, 20);
        this->list->set_fixed_position(30, 45, 740, 230);
        this->text_buttons[0]->set_fixed_position(5, 565, 190, 30);
        (*text_button_1)->set_fixed_position(205, 565, 190, 30);
        this->text_buttons[2]->set_fixed_position(405, 565, 190, 30);
        this->ok_button->set_fixed_position(605, 565, 190, 30);
    } else {
        set_ideal_size(1024, 768);
        this->title->set_fixed_position(3, 15, 1018, 20);
        this->list->set_fixed_position(40, 65, 944, 310);
        this->text_buttons[0]->set_fixed_position(10, 690, 240, 50);
        (*text_button_1)->set_fixed_position(266, 690, 240, 50);
        this->text_buttons[2]->set_fixed_position(522, 690, 240, 50);
        this->ok_button->set_fixed_position(774, 690, 240, 50);
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
    this->vc_back_bmp = background_bmp;
}

TRIBE_Mission_Screen::~TRIBE_Mission_Screen() {
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

long TRIBE_Mission_Screen::handle_idle() {
    if (!rge_base_game->input_enabled) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

void TRIBE_Mission_Screen::draw() {
    TScreenPanel::draw();

    if (this->vc_back_bmp != 0) {
        this->draw_setup(0);

        if (this->need_redraw == 2) {
            this->render_area->Clear(&this->clip_rect, this->background_color1);
        }

        unsigned char* locked = this->render_area->Lock("scr_vc::draw", 1);
        if (locked != 0) {
            if (this->pnl_wid <= 640) {
                this->vc_back_bmp->Draw(this->render_area, this->pnl_x + 7, this->pnl_y + 166, 0, 0);
            } else if (this->pnl_wid <= 800) {
                this->vc_back_bmp->Draw(this->render_area, this->pnl_x + 83, this->pnl_y + 280, 0, 0);
            } else {
                this->vc_back_bmp->Draw(this->render_area, this->pnl_x + 197, this->pnl_y + 363, 0, 0);
            }
            this->render_area->Unlock("scr_vc::draw");
        }

        this->draw_finish();
    }
}

long TRIBE_Mission_Screen::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    if (actionIn == 1) {
        if (fromPanel == this->text_buttons[0]) {
            this->list->set_text(rge_base_game->world->scenario->Get_message(4));
        }

        if (fromPanel == this->text_buttons[1]) {
            this->list->set_text(rge_base_game->world->scenario->Get_message(0));
        }

        if (fromPanel == this->text_buttons[2]) {
            this->list->set_text(rge_base_game->world->scenario->Get_message(1));
        }

        if (fromPanel == this->ok_button) {
            if (this->game_flag != 0) {
                panel_system.setCurrentPanel("Game Screen", 0);
                if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
            } else {
                static_cast<TRIBE_Game*>(rge_base_game)->create_game_screen();
            }

            panel_system.destroyPanel("Mission Dialog");
            return 1;
        }
    }

    return TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}

long TRIBE_Mission_Screen::key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    if (ctrl_key == 0 || key != 'V') {
        return 0;
    }

    if (this->game_flag == 0 && rge_base_game->prog_info->use_sound != 0 && rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->stream_file("voice.wav", 0, 0);
    }
    return 1;
}
