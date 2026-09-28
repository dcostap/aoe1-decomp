
#include "../include/scr_ach.h"
#include "../include/program_mode.h"
#include "../include/pnl_btn.h"
#include "../include/Pnl_scbr.h"
#include "../include/Shape.h"
#include "../include/basegame.h"
#include "../include/color.h"
#include "../include/player.h"
#include "../include/resource_ids.h"
#include "../include/rge_base_game_global.h"
#include "../include/scenario.h"
#include "../include/tribegam.h"
#include "../include/victory.h"
#include "../include/world.h"
#include <stdio.h>
#include <string.h>

extern int confirmed_close;

TribeAchievementsScreen::TribeAchievementsScreen(char* titleText, int end_flag)
    : TScreenPanel("Achievements Screen") {
    char layout_file[260];
    char str[100];
    TPanel* tabList[8];
    long seconds;
    long minutes = 0;
    long hours = 0;
    int i;

    this->title = 0;
    this->time = 0;
    this->summary_text = 0;
    this->win_loss_text = 0;
    this->instruction = 0;
    this->time_line = 0;
    this->okButton = 0;
    this->timelineButton = 0;
    this->restartButton = 0;
    this->aftermathButton = 0;
    this->backButton = 0;
    this->backButton2 = 0;
    this->win_decal = 0;
    this->close_button = 0;
    this->instruction_bar = 0;
    this->win_loss_text_bar = 0;
    this->summary_text_bar = 0;
    this->end_game_flag = end_flag;

    for (i = 0; i < 5; ++i) {
        this->achievement_choice[i] = 0;
    }
    for (i = 0; i < 7; ++i) {
        this->title_bar[i] = 0;
    }
    for (i = 0; i < 8; ++i) {
        this->player_names[i] = 0;
        for (int column = 0; column < 7; ++column) {
            this->statistics[i][column] = 0;
        }
    }

    long layout_resource_id;
    if (this->end_game_flag != 0) {
        if (rge_base_game->get_player()->game_status == 1) {
            strcpy(layout_file, "scr7");
            layout_resource_id = BINARY_RESOURCE_ID_ACHIEVEMENTS_END_WIN_LAYOUT;
        } else {
            strcpy(layout_file, "scr8");
            layout_resource_id = BINARY_RESOURCE_ID_ACHIEVEMENTS_END_OTHER_LAYOUT;
        }
    } else {
        strcpy(layout_file, "scr10");
        layout_resource_id = BINARY_RESOURCE_ID_ACHIEVEMENTS_IN_GAME_LAYOUT;
    }

    if (this->setup(rge_base_game->draw_area, layout_file, layout_resource_id, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(640, 480);

    seconds = rge_base_game->world->world_time / 1000;
    if (seconds > 59) {
        minutes = seconds / 60;
        seconds -= minutes * 60;
        if (minutes > 59) {
            hours = minutes / 60;
            minutes -= hours * 60;
        }
    }
    sprintf(str, "%02ld:%02ld:%02ld", hours, minutes, seconds);

    this->create_text(this, &this->time, str, 480, 10, 110, 20, RGE_FONT_STANDARD, 0, 0, 0);
    this->time->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);
    this->create_text(this, &this->title, STRING_ID_ACHIEVEMENTS_TITLE, 0, 5, 640, 30, RGE_FONT_COPPERPLATE_21_BOLD, 1, 0, 0);
    this->create_text(this, &this->summary_text, 0, 10, 35, 620, 30, RGE_FONT_COPPERPLATE_21_BOLD, 1, 0, 0);
    this->create_text(this, &this->instruction, STRING_ID_ACHIEVEMENTS_COLUMN_INSTRUCTION, 10, 410, 620,
                      20, RGE_FONT_STANDARD, 1, 0, 0);

    if (this->end_game_flag != 0) {
        RGE_Player* player = rge_base_game->get_player();
        long message_id;
        if (player->game_status == 1) {
            message_id = 2;
        } else {
            message_id = 3;
        }
        char* message = rge_base_game->world->scenario->Get_message(message_id);
        if (message != 0 && *message != '\0') {
            this->create_text(this, &this->win_loss_text, "", 10, 85, 620, 330, RGE_FONT_STANDARD, 0, 0, 1);
            if (this->win_loss_text != 0) {
                this->create_auto_scrollbar(&this->win_loss_text_bar, this->win_loss_text, 20);
                this->win_loss_text->set_bevel_info(4, this->bevel_color1, this->bevel_color2,
                                                    this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                this->win_loss_text->set_text(message);
            }
        }
    }

    this->time_line->create_timeline(this, &this->time_line, 10, 85, 620, 330, 11, 9, 640, 480);
    this->time_line->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3,
                                    this->bevel_color4, this->bevel_color5, this->bevel_color6);
    this->time_line->set_special_events("timeline.slp");

    if (this->create_button(this, &this->close_button, STRING_ID_BUTTON_CLOSE, 0, 0, 0, 0, 0, -1, -1, 0) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4, 4, 17, 17, 17, 17, 0, 0, 0, 0);

    this->create_text(this, &this->title_bar[0], 0, 98, 151, 200, 30, RGE_FONT_STANDARD, 0, 0, 0);
    this->create_text(this, &this->title_bar[1], 0, 152, 131, 200, 30, RGE_FONT_STANDARD, 0, 0, 0);
    this->create_text(this, &this->title_bar[2], 0, 212, 111, 145, 30, RGE_FONT_STANDARD, 0, 0, 0);
    this->create_text(this, &this->title_bar[3], 0, 260, 91, 200, 30, RGE_FONT_STANDARD, 1, 0, 0);
    this->create_text(this, &this->title_bar[4], 0, 364, 111, 145, 30, RGE_FONT_STANDARD, 0, 0, 0);
    this->create_text(this, &this->title_bar[5], 0, 370, 131, 200, 30, RGE_FONT_STANDARD, 0, 0, 0);
    this->create_text(this, &this->title_bar[6], 0, 424, 151, 200, 30, RGE_FONT_STANDARD, 0, 0, 0);
    this->title_bar[4]->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);
    this->title_bar[5]->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);
    this->title_bar[6]->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);

    this->create_text(this, &this->achievement_choice[0], 0, 100, 151, 130, 250, RGE_FONT_STANDARD, 0, 0, 0);
    this->create_text(this, &this->achievement_choice[1], 0, 154, 131, 128, 274, RGE_FONT_STANDARD, 0, 0, 0);
    this->create_text(this, &this->achievement_choice[2], 0, 214, 111, 121, 289, RGE_FONT_STANDARD, 0, 0, 0);
    this->create_text(this, &this->achievement_choice[3], 0, 282, 91, 156, 309, RGE_FONT_STANDARD, 0, 0, 0);
    this->create_text(this, &this->achievement_choice[4], 0, 388, 111, 121, 289, RGE_FONT_STANDARD, 0, 0, 0);

    int y = 171;
    for (i = 1; i < 9; ++i, y += 30) {
        char* player_name;
        if (i < rge_base_game->world->player_num) {
            player_name = rge_base_game->world->players[i]->name;
        } else {
            player_name = 0;
        }

        this->create_text(this, &this->player_names[i - 1], player_name, 22, y, 150, 29, RGE_FONT_STANDARD, 0, 1, 0);
        this->create_text(this, &this->statistics[i - 1][0], 0, 178, y, 51, 29, RGE_FONT_STANDARD, 1, 1, 0);
        this->create_text(this, &this->statistics[i - 1][1], 0, 231, y, 51, 29, RGE_FONT_STANDARD, 1, 1, 0);
        this->create_text(this, &this->statistics[i - 1][2], 0, 283, y, 51, 29, RGE_FONT_STANDARD, 1, 1, 0);
        this->create_text(this, &this->statistics[i - 1][3], 0, 336, y, 51, 29, RGE_FONT_STANDARD, 1, 1, 0);
        this->create_text(this, &this->statistics[i - 1][4], 0, 389, y, 51, 29, RGE_FONT_STANDARD, 1, 1, 0);
        this->create_text(this, &this->statistics[i - 1][5], 0, 442, y, 51, 29, RGE_FONT_STANDARD, 1, 1, 0);
        this->create_text(this, &this->statistics[i - 1][6], 0, 494, y, 51, 29, RGE_FONT_STANDARD, 1, 1, 0);

        if (i < rge_base_game->world->player_num) {
            RGE_Player* player = rge_base_game->world->players[i];
            unsigned long color;
            switch (player->color_table->id) {
            case 0:
                color = 0xC40000;
                break;
            case 1:
                color = 0xC8;
                break;
            case 2:
                color = 0xEAEA;
                break;
            case 3:
                color = 0x215A8C;
                break;
            case 4:
                color = 0x80FF;
                break;
            case 5:
                color = 0x8000;
                break;
            case 6:
                color = 0x808080;
                break;
            case 7:
                color = 0x808040;
                break;
            default:
                color = 0xFFFFFF;
                break;
            }
            this->player_names[i - 1]->set_text_color(color, 0);
            for (int column = 0; column < 7; ++column) {
                this->statistics[i - 1][column]->set_text_color(color, 0);
            }
        }
    }

    long button_width;
    long ok_x;
    if (this->end_game_flag != 0 && rge_base_game->singlePlayerGame() != 0) {
        if (this->win_loss_text != 0) {
            this->create_button(this, &this->aftermathButton, STRING_ID_ACHIEVEMENTS_AFTERMATH, 0, 5, 441, 150, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);
            this->create_button(this, &this->timelineButton, STRING_ID_ACHIEVEMENTS_TIMELINE, 0, 165, 441, 150, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);
            this->create_button(this, &this->restartButton, STRING_ID_ACHIEVEMENTS_RESTART, 0, 325, 441, 150, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);
            button_width = 150;
            ok_x = 485;
        } else {
            this->create_button(this, &this->timelineButton, STRING_ID_ACHIEVEMENTS_TIMELINE, 0, 20, 441, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);
            this->create_button(this, &this->restartButton, STRING_ID_ACHIEVEMENTS_RESTART, 0, 230, 441, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);
            button_width = 180;
            ok_x = 440;
        }
    } else {
        this->create_button(this, &this->timelineButton, STRING_ID_ACHIEVEMENTS_TIMELINE, 0, 100, 441, 200, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);
        button_width = 200;
        ok_x = 340;
    }
    this->create_button(this, &this->okButton, STRING_ID_ACHIEVEMENTS_CLOSE, 0, ok_x, 441, button_width, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);
    this->create_button(this, &this->backButton, STRING_ID_ACHIEVEMENTS_BACK, 0, 200, 441, 240, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);
    this->backButton->set_active(0);
    this->backButton->hotkey = VK_ESCAPE;
    this->backButton->hotkey_shift = 0;
    this->create_button(this, &this->backButton2, STRING_ID_ACHIEVEMENTS_CLOSE, 0, 200, 441, 240, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0);
    this->backButton2->set_active(0);
    this->backButton2->hotkey = VK_ESCAPE;
    this->backButton2->hotkey_shift = 0;
    this->okButton->hotkey = VK_ESCAPE;
    this->okButton->hotkey_shift = 0;

    if (rge_base_game->get_player()->game_status == 1) {
        this->win_decal = new TShape("viccheck.slp", 0xCB21);
    } else {
        this->win_decal = new TShape("defcheck.slp", 0xCB22);
    }

    int tab_count = 0;
    if (this->aftermathButton != 0) {
        tabList[tab_count++] = this->aftermathButton;
    }
    if (this->timelineButton != 0) {
        tabList[tab_count++] = this->timelineButton;
    }
    if (this->restartButton != 0) {
        tabList[tab_count++] = this->restartButton;
    }
    tabList[tab_count++] = this->okButton;
    this->set_tab_order(tabList, static_cast<short>(tab_count));
    this->set_curr_child(this->okButton);
    this->backButton->set_tab_order(static_cast<TPanel*>(0), static_cast<TPanel*>(0));
    this->backButton2->set_tab_order(static_cast<TPanel*>(0), static_cast<TPanel*>(0));

    this->set_mode(this->win_loss_text != 0 ? 5 : 0);
}

TribeAchievementsScreen::~TribeAchievementsScreen() {
    panel_system.destroyPanel("YesNoDialog");

    if (this->win_decal != 0) {
        delete this->win_decal;
    }

    if (this->title != 0) {
        delete this->title;
    }
    if (this->summary_text != 0) {
        delete this->summary_text;
    }
    if (this->time != 0) {
        delete this->time;
    }
    if (this->win_loss_text != 0) {
        delete this->win_loss_text;
    }
    if (this->instruction != 0) {
        delete this->instruction;
    }
    if (this->restartButton != 0) {
        delete this->restartButton;
    }
    if (this->okButton != 0) {
        delete this->okButton;
    }
    if (this->backButton != 0) {
        delete this->backButton;
    }
    if (this->backButton2 != 0) {
        delete this->backButton2;
    }
    if (this->aftermathButton != 0) {
        delete this->aftermathButton;
    }
    if (this->timelineButton != 0) {
        delete this->timelineButton;
    }
    if (this->time_line != 0) {
        delete this->time_line;
    }
    if (this->win_loss_text_bar != 0) {
        delete this->win_loss_text_bar;
    }
    if (this->summary_text_bar != 0) {
        delete this->summary_text_bar;
    }
    if (this->instruction_bar != 0) {
        delete this->instruction_bar;
    }

    this->delete_panel((TPanel**)&this->close_button);

    for (int column = 0; column < 7; ++column) {
        if (this->title_bar[column] != 0) {
            delete this->title_bar[column];
        }
    }

    for (int choice = 0; choice < 5; ++choice) {
        if (this->achievement_choice[choice] != 0) {
            delete this->achievement_choice[choice];
        }
    }

    for (int player_slot = 0; player_slot < 8; ++player_slot) {
        if (this->player_names[player_slot] != 0) {
            delete this->player_names[player_slot];
        }
        for (int column = 0; column < 7; ++column) {
            if (this->statistics[player_slot][column] != 0) {
                delete this->statistics[player_slot][column];
            }
        }
    }
}

// Mode 6 is emitted before mode 5 in the original handler
// order. Mode 3 reads victory IDs 16 and 15 in that order.
void TribeAchievementsScreen::set_mode(long new_mode) {
    int player_num = static_cast<int>(rge_base_game->world->player_num) - 1;
    char temptxt[50];

    memset(temptxt + 31, 0, sizeof(temptxt) - 31);

    rge_base_game->disable_input();

    if (this->win_loss_text != 0) {
        this->win_loss_text->set_active(0);
    }
    this->current_mode = new_mode;
    this->time_line->set_active(0);
    this->instruction->set_active(0);
    this->time->set_active(1);

    if (this->restartButton != 0) {
        this->restartButton->set_active(0);
    }
    if (this->okButton != 0) {
        this->okButton->set_active(0);
    }
    if (this->aftermathButton != 0) {
        this->aftermathButton->set_active(0);
    }
    if (this->timelineButton != 0) {
        this->timelineButton->set_active(0);
    }
    if (this->backButton != 0) {
        this->backButton->set_active(1);
    }
    if (this->backButton2 != 0) {
        this->backButton2->set_active(0);
    }
    this->set_curr_child(this->backButton);

    switch (new_mode) {
    case 0: {
        this->size = 7;
        this->set_curr_child(this->okButton);

        if (this->restartButton != 0) {
            this->restartButton->set_active(1);
        }
        if (this->okButton != 0) {
            this->okButton->set_active(1);
        }
        if (this->aftermathButton != 0) {
            this->aftermathButton->set_active(1);
        }
        if (this->timelineButton != 0) {
            this->timelineButton->set_active(1);
        }
        if (this->backButton != 0) {
            this->backButton->set_active(0);
        }

        this->instruction->set_active(1);
        this->summary_text->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_SUMMARY));
        this->title_bar[0]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_MILITARY));
        this->title_bar[1]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_ECONOMY));
        this->title_bar[2]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_RELIGION));
        this->title_bar[3]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TECHNOLOGY));
        this->title_bar[4]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_SURVIVAL));
        this->title_bar[5]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_WONDER));
        this->title_bar[6]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TOTAL_SCORE_SUMMARY));

        if (player_num > 0) {
            int player_index = 0;
            int remaining = player_num;
            while (remaining != 0) {
                RGE_Player* player;
                player = rge_base_game->world->players[player_index + 1];

                itoa(player->victory_conditions->get_victory_points_group(0), temptxt, 10);
                this->statistics[player_index][0]->set_text(temptxt);
                itoa(player->victory_conditions->get_victory_points_group(1), temptxt, 10);
                this->statistics[player_index][1]->set_text(temptxt);
                itoa(player->victory_conditions->get_victory_points_group(2), temptxt, 10);
                this->statistics[player_index][2]->set_text(temptxt);
                itoa(player->victory_conditions->get_victory_points_group(3), temptxt, 10);
                this->statistics[player_index][3]->set_text(temptxt);

                if (player->victory_conditions->get_victory_points_id(0x16) > 0) {
                    this->statistics[player_index][4]->set_text(static_cast<long>(STRING_ID_BUTTON_YES));
                } else {
                    this->statistics[player_index][4]->set_text("");
                }
                if (player->victory_conditions->get_victory_points_id(0x17) > 0) {
                    this->statistics[player_index][5]->set_text(static_cast<long>(STRING_ID_BUTTON_YES));
                } else {
                    this->statistics[player_index][5]->set_text("");
                }

                itoa(player->victory_conditions->get_victory_points(), temptxt, 10);
                this->statistics[player_index][6]->set_text(temptxt);
                ++player_index;
                --remaining;
            }
        }
        break;
    }

    case 1: {
        this->size = 6;
        this->summary_text->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_MILITARY));
        this->title_bar[0]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_KILLS));
        this->title_bar[1]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_RAZINGS));
        this->title_bar[2]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_LOSSES));
        this->title_bar[3]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_KILLS_LOSSES));
        this->title_bar[4]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_LARGEST_ARMY));
        this->title_bar[5]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TOTAL_SCORE_CATEGORY));

        if (player_num > 0) {
            int player_index = 0;
            int remaining = player_num;
            while (remaining != 0) {
                RGE_Player* player;
                player = rge_base_game->world->players[player_index + 1];

                itoa(player->victory_conditions->get_attribute_id(0), temptxt, 10);
                this->statistics[player_index][0]->set_text(temptxt);
                itoa(player->victory_conditions->get_attribute_id(1), temptxt, 10);
                this->statistics[player_index][1]->set_text(temptxt);
                itoa(static_cast<long>(player->attributes[19] - player->attributes[11]), temptxt, 10);
                this->statistics[player_index][2]->set_text(temptxt);

                itoa(player->victory_conditions->get_attribute_id(2), temptxt, 10);
                this->statistics[player_index][3]->set_text(temptxt);

                if (player->victory_conditions->get_victory_points_id(3) > 0) {
                    this->statistics[player_index][4]->set_text(static_cast<long>(STRING_ID_BUTTON_YES));
                } else {
                    this->statistics[player_index][4]->set_text("");
                }

                itoa(player->victory_conditions->get_victory_points_group(0), temptxt, 10);
                this->statistics[player_index][5]->set_text(temptxt);
                ++player_index;
                --remaining;
            }
        }
        break;
    }

    case 2: {
        this->size = 7;
        this->summary_text->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_ECONOMY));
        this->title_bar[0]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_GOLD_COLLECTED));
        this->title_bar[1]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_VILLAGER_HIGH));
        this->title_bar[2]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_VILLAGER_BONUS));
        this->title_bar[3]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_EXPLORATION));
        this->title_bar[4]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_MOST_EXPLORED));
        this->title_bar[5]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TRIBUTE_GIVEN));
        this->title_bar[6]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TOTAL_SCORE_CATEGORY));

        if (player_num > 0) {
            int player_index = 0;
            int remaining = player_num;
            while (remaining != 0) {
                RGE_Player* player;
                player = rge_base_game->world->players[player_index + 1];

                itoa(player->victory_conditions->get_attribute_id(4), temptxt, 10);
                this->statistics[player_index][0]->set_text(temptxt);
                itoa(player->victory_conditions->get_attribute_id(5), temptxt, 10);
                this->statistics[player_index][1]->set_text(temptxt);

                if (player->victory_conditions->get_victory_points_id(6) > 0) {
                    this->statistics[player_index][2]->set_text(static_cast<long>(STRING_ID_BUTTON_YES));
                } else {
                    this->statistics[player_index][2]->set_text("");
                }

                sprintf(temptxt, "%d%%", player->victory_conditions->get_attribute_id(7));
                this->statistics[player_index][3]->set_text(temptxt);

                if (player->victory_conditions->get_victory_points_id(8) > 0) {
                    this->statistics[player_index][4]->set_text(static_cast<long>(STRING_ID_BUTTON_YES));
                } else {
                    this->statistics[player_index][4]->set_text("");
                }

                itoa(player->victory_conditions->get_attribute_id(9), temptxt, 10);
                this->statistics[player_index][5]->set_text(temptxt);
                itoa(player->victory_conditions->get_victory_points_group(1), temptxt, 10);
                this->statistics[player_index][6]->set_text(temptxt);
                ++player_index;
                --remaining;
            }
        }
        break;
    }

    case 3: {
        this->size = 7;
        this->summary_text->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_RELIGION));
        this->title_bar[0]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_CONVERSIONS));
        this->title_bar[1]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_MOST_CONVERSIONS));
        this->title_bar[2]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_RUINS));
        this->title_bar[3]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_ARTIFACTS));
        this->title_bar[4]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TEMPLES));
        this->title_bar[5]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_ALL_ARTIFACTS_RUINS));
        this->title_bar[6]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TOTAL_SCORE_CATEGORY));

        if (player_num > 0) {
            int player_index = 0;
            int remaining = player_num;
            while (remaining != 0) {
                RGE_Player* player;
                player = rge_base_game->world->players[player_index + 1];

                this->time_line->set_active(0);
                itoa(player->victory_conditions->get_attribute_id(10), temptxt, 10);
                this->statistics[player_index][0]->set_text(temptxt);

                if (player->victory_conditions->get_victory_points_id(11) > 0) {
                    this->statistics[player_index][1]->set_text(static_cast<long>(STRING_ID_BUTTON_YES));
                } else {
                    this->statistics[player_index][1]->set_text("");
                }

                itoa(player->victory_conditions->get_attribute_id(12), temptxt, 10);
                this->statistics[player_index][2]->set_text(temptxt);
                itoa(player->victory_conditions->get_attribute_id(13), temptxt, 10);
                this->statistics[player_index][3]->set_text(temptxt);
                itoa(player->victory_conditions->get_attribute_id(14), temptxt, 10);
                this->statistics[player_index][4]->set_text(temptxt);

                long victory_points_16 =
                    player->victory_conditions->get_victory_points_id(16);
                long victory_points_15 =
                    player->victory_conditions->get_victory_points_id(15);
                itoa(victory_points_16 + victory_points_15, temptxt, 10);
                this->statistics[player_index][5]->set_text(temptxt);
                itoa(player->victory_conditions->get_victory_points_group(2), temptxt, 10);
                this->statistics[player_index][6]->set_text(temptxt);
                ++player_index;
                --remaining;
            }
        }
        break;
    }

    case 4: {
        this->size = 5;
        this->summary_text->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TECHNOLOGY));
        this->title_bar[0]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TECHNOLOGIES));
        this->title_bar[1]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_MOST_TECHNOLOGIES));
        this->title_bar[2]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_BRONZE_AGE_FIRST));
        this->title_bar[3]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_IRON_AGE_FIRST));
        this->title_bar[4]->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TOTAL_SCORE_CATEGORY));

        if (player_num > 0) {
            int player_index = 0;
            int remaining = player_num;
            while (remaining != 0) {
                RGE_Player* player;
                player = rge_base_game->world->players[player_index + 1];

                itoa(player->victory_conditions->get_attribute_id(17), temptxt, 10);
                this->statistics[player_index][0]->set_text(temptxt);
                if (player->victory_conditions->get_victory_points_id(18) > 0) {
                    this->statistics[player_index][1]->set_text(static_cast<long>(STRING_ID_BUTTON_YES));
                } else {
                    this->statistics[player_index][1]->set_text("");
                }
                if (player->victory_conditions->get_victory_points_id(19) > 0) {
                    this->statistics[player_index][2]->set_text(static_cast<long>(STRING_ID_BUTTON_YES));
                } else {
                    this->statistics[player_index][2]->set_text("");
                }
                if (player->victory_conditions->get_victory_points_id(20) > 0) {
                    this->statistics[player_index][3]->set_text(static_cast<long>(STRING_ID_BUTTON_YES));
                } else {
                    this->statistics[player_index][3]->set_text("");
                }
                itoa(player->victory_conditions->get_victory_points_group(3), temptxt, 10);
                this->statistics[player_index][4]->set_text(temptxt);
                ++player_index;
                --remaining;
            }
        }
        break;
    }

    case 6:
        this->size = 0;
        this->time_line->set_active(1);
        this->summary_text->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_TIMELINE));
        this->time->set_active(1);
        break;

    case 5:
        this->size = 0;
        this->summary_text->set_text(static_cast<long>(STRING_ID_ACHIEVEMENTS_AFTERMATH));
        if (this->win_loss_text != 0) {
            this->win_loss_text->set_active(1);
        }
        this->time->set_active(0);
        if (this->backButton != 0) {
            this->backButton->set_active(0);
        }
        if (this->backButton2 != 0) {
            this->backButton2->set_active(1);
            this->set_curr_child(this->backButton2);
        }
        break;
    }

    if (this->size == 0) {
        for (int i = 0; i < 8; ++i) {
            this->player_names[i]->set_active(0);
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            this->player_names[i]->set_active(i < player_num);
        }
    }

    for (int i = 0; i < 7; ++i) {
        this->title_bar[i]->set_active(i < this->size);
        for (int j = 0; j < player_num; ++j) {
            this->statistics[j][i]->set_active(i < this->size);
        }
    }
}

void TribeAchievementsScreen::draw() {
    TScreenPanel::draw();

    if (this->current_mode < 5) {
        this->draw_setup(0);

        if (this->win_decal != 0 && this->render_area->Lock("scr_ach::draw", 1) != 0) {
            RGE_Game_World* world = rge_base_game->world;
            int count = world->player_num - 1;

            if (count > 0) {
                int remaining;
                int player_index = 0;
                for (remaining = count; remaining != 0; --remaining) {
                    if (world->players[player_index + 1]->game_status == 1) {
                        this->win_decal->shape_draw(this->render_area, this->player_names[player_index]->xPosition() - 20,
                                                    this->player_names[player_index]->yPosition(), 0, 0, 0);
                    }
                    ++player_index;
                }
            }

            this->render_area->Unlock("scr_ach::draw");
        }

        this->draw_finish();
    }
}

long TribeAchievementsScreen::handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key) {
    long result = TEasy_Panel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
    if (current_mode == 0) {
        if (achievement_choice[0]->is_inside(x, y)) {
            set_mode(1);
            return result;
        }
        if (achievement_choice[1]->is_inside(x, y)) {
            set_mode(2);
            return result;
        }
        if (achievement_choice[2]->is_inside(x, y)) {
            set_mode(3);
            return result;
        }
        if (achievement_choice[3]->is_inside(x, y)) {
            if (achievement_choice[4]->is_inside(x, y) == 0) {
                set_mode(4);
            }
        }
    }
    return result;
}

long TribeAchievementsScreen::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    if (fromPanel == this->okButton && actionIn == 1) {
        if (this->end_game_flag != 0) {
            static_cast<TRIBE_Game*>(rge_base_game)->quit_game();
        } else {
            if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            panel_system.setCurrentPanel("Game Screen", 0);
        }
        panel_system.destroyPanel("Achievements Screen");
        return 1;
    }

    if (fromPanel == this->restartButton && actionIn == 1) {
        static_cast<TRIBE_Game*>(rge_base_game)->restart_game();
        return actionIn;
    }

    if (fromPanel == this->timelineButton && actionIn == 1) {
        this->set_mode(6);
        if (this->restartButton != 0) {
            this->restartButton->set_active(0);
        }
        if (this->okButton != 0) {
            this->okButton->set_active(0);
        }
        if (this->aftermathButton != 0) {
            this->aftermathButton->set_active(0);
        }
        if (this->timelineButton != 0) {
            this->timelineButton->set_active(0);
        }
        if (this->backButton != 0) {
            this->backButton->set_active(1);
            return actionIn;
        }
    } else {
        if (fromPanel != this->aftermathButton || actionIn != 1) {
            if ((fromPanel == this->backButton || fromPanel == this->backButton2) && actionIn == 1) {
                this->set_mode(0);
                return actionIn;
            } else if (fromPanel == this->close_button && actionIn == 1) {
                rge_base_game->close();
                return actionIn;
            } else {
                char* panel_name = fromPanel->panelName();
                if (panel_name != 0 && strcmp(fromPanel->panelName(), "YesNoDialog") == 0) {
                    panel_system.destroyPanel("YesNoDialog");
                    if (actionIn == 0) {
                        rge_base_game->close();
                    } else {
                        confirmed_close = 0;
                    }
                    return 1;
                }

                return TEasy_Panel::action(fromPanel, actionIn, a1, a2);
            }
        }

        this->set_mode(5);
        if (this->restartButton != 0) {
            this->restartButton->set_active(0);
        }
        if (this->okButton != 0) {
            this->okButton->set_active(0);
        }
        if (this->aftermathButton != 0) {
            this->aftermathButton->set_active(0);
        }
        if (this->timelineButton != 0) {
            this->timelineButton->set_active(0);
        }
        if (this->backButton != 0) {
            this->backButton->set_active(1);
            return actionIn;
        }
    }

    return 1;
}

long TribeAchievementsScreen::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

long TribeAchievementsScreen::wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    if (msg == WM_CLOSE && confirmed_close == 0) {
        confirmed_close = 1;
        int mode = rge_base_game->prog_mode;
        if (mode == ProgModeGameOver || mode == ProgModeGame ||
            mode == ProgModeGameTempPaused || mode == ProgModeScenarioEditor) {
            if (IsIconic(render_area->Wnd) == 0) {
                popupYesNoDialog(get_string(STRING_ID_CONFIRM_QUIT_GAME), 0, TEASY_POPUP_WIDTH, 100);
                return 1;
            }
        }
    }
    return TPanel::wnd_proc(hwnd, msg, wParam, lParam);
}
