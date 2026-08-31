
#include "../include/scr_ach.h"
#include "../include/pnl_btn.h"
#include "../include/Pnl_scbr.h"
#include "../include/Shape.h"
#include "../include/basegame.h"
#include "../include/color.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/scenario.h"
#include "../include/tribegam.h"
#include "../include/victory.h"
#include "../include/world.h"
#include <stdio.h>
#include <string.h>

extern int confirmed_close;

TribeAchievementsScreen::TribeAchievementsScreen(char* title_text, int end_game_flag)
    : TScreenPanel("Achievements Screen")
{
    unsigned long color;
    int tab_count;
    TPanel* tabList[8];
    char temptxt[50];
    char str[100];
    char info_file[260];

    memset(temptxt + 31, 0, sizeof(temptxt) - 31);

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
    str[1] = 0;
    this->end_game_flag = end_game_flag;

    this->achievement_choice[0] = 0;
    this->achievement_choice[1] = 0;
    this->achievement_choice[2] = 0;
    this->achievement_choice[3] = 0;
    this->achievement_choice[4] = 0;

    memset(this->title_bar, 0, sizeof(this->title_bar));
    for (int player_slot = 0; player_slot < 8; ++player_slot) {
        this->player_names[player_slot] = 0;
        for (int column = 0; column < 7; ++column) {
            this->statistics[player_slot][column] = 0;
        }
    }

    long info_id;
    if (this->end_game_flag != 0) {
        RGE_Player* player = rge_base_game->get_player();
        if (player->game_status == 1) {
            strcpy(info_file, "scr7");
            info_id = 0xC389;
        } else {
            strcpy(info_file, "scr8");
            info_id = 0xC38A;
        }
    } else {
        strcpy(info_file, "scr10");
        info_id = 0xC38D;
    }
    if (setup(rge_base_game->draw_area, info_file, info_id, 1) == 0) {
        this->error_code = 1;
        return;
    }

    set_ideal_size(0x280, 0x1E0);

    long minutes = 0;
    long hours = 0;
    long seconds = rge_base_game->world->world_time / 1000;
    if (seconds > 0x3B) {
        minutes = seconds / 60;
        seconds -= minutes * 60;
        if (minutes > 0x3B) {
            hours = minutes / 60;
            minutes -= hours * 60;
        }
    }
    sprintf(str, "%02ld:%02ld:%02ld", hours, minutes, seconds);

    create_text(this, &this->time, str + 4, 0x1E0, 10, 0x6E, 0x14, 0x0B, 0, 0, 0);
    this->time->set_alignment(TTextPanel::AlignRight, TTextPanel::AlignTop);
    create_text(this, &this->title, 0x269E, 0, 5, 0x280, 0x1E, 1, 1, 0, 0);
    create_text(this, &this->summary_text, 0, 10, 0x23, 0x26C, 0x1E, 1, 1, 0, 0);
    create_text(this, &this->instruction, 0x26DB, 10, 0x19A, 0x26C, 0x14, 0x0B, 1, 0, 0);

    if (this->end_game_flag != 0) {
        RGE_Player* player = rge_base_game->get_player();
        char* message;
        if (player->game_status == 1) {
            message = rge_base_game->world->scenario->Get_message(2);
        } else {
            message = rge_base_game->world->scenario->Get_message(3);
        }
        if (message != 0 && message[0] != 0) {
            create_text(this, &this->win_loss_text, "", 10, 0x55,
                        0x26C, 0x14A, 0x0B, 0, 0, 1);
            if (this->win_loss_text != 0) {
                create_auto_scrollbar(&this->win_loss_text_bar,
                                      this->win_loss_text, 0x14);
                this->win_loss_text->set_bevel_info(
                    4, bevel_color1, bevel_color2, bevel_color3,
                    bevel_color4, bevel_color5, bevel_color6);
                this->win_loss_text->set_text(message);
            }
        }
    }

    this->time_line->create_timeline(this, &this->time_line, 10, 0x55,
                                     0x26C, 0x14A, 0x0B, 9, 0x280, 0x1E0);
    this->time_line->set_bevel_info(
        3, bevel_color1, bevel_color2, bevel_color3,
        bevel_color4, bevel_color5, bevel_color6);
    this->time_line->set_special_events("timeline.slp");

    if (create_button(this, &this->close_button, 0x3EA, 0, 0, 0, 0, 0, 0, -1, -1) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning(
        TPanel::PositionRightTop, 4, 4, 4, 4, 0x11, 0x11, 0x11,
        0x11, 0, 0, 0, 0);

    create_text(this, this->title_bar, 0, 0x62, 0x97, 200, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 1, 0, 0x98, 0x83, 200, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 2, 0, 0xD4, 0x6F, 0x91, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 3, 0, 0x104, 0x5B, 200, 0x1E, 0x0B, 1, 0, 0);
    create_text(this, this->title_bar + 4, 0, 0x16C, 0x6F, 0x91, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 5, 0, 0x172, 0x83, 200, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 6, 0, 0x1A8, 0x97, 200, 0x1E, 0x0B, 0, 0, 0);
    this->title_bar[4]->set_alignment(TTextPanel::AlignRight,
                                      TTextPanel::AlignTop);
    this->title_bar[5]->set_alignment(TTextPanel::AlignRight,
                                      TTextPanel::AlignTop);
    this->title_bar[6]->set_alignment(TTextPanel::AlignRight,
                                      TTextPanel::AlignTop);

    create_text(this, this->achievement_choice, 0, 100, 0x97, 0x82, 0xFA, 0x0B, 0, 0, 0);
    create_text(this, this->achievement_choice + 1, 0, 0x9A, 0x83, 0x80, 0x112, 0x0B, 0, 0, 0);
    create_text(this, this->achievement_choice + 2, 0, 0xD6, 0x6F, 0x79, 0x121, 0x0B, 0, 0, 0);
    create_text(this, this->achievement_choice + 3, 0, 0x11A, 0x5B, 0x9C, 0x135, 0x0B, 0, 0, 0);
    create_text(this, this->achievement_choice + 4, 0, 0x184, 0x6F, 0x79, 0x121, 0x0B, 0, 0, 0);

    int player_index = 0;
    int y = 0xAB;
    // The shipped loop creates eight player rows.
    do {
        char* name;
        if (player_index + 1 < rge_base_game->world->player_num) {
            RGE_Player* named_player =
                rge_base_game->world->players[player_index + 1];
            name = named_player->name;
        } else {
            name = 0;
        }
        create_text(this, &this->player_names[player_index], name, 0x16, y,
                    0x96, 0x1D,
                    0x0B, 0, 1, 0);
        create_text(this, &this->statistics[player_index][0], 0, 0xB2, y,
                    0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, &this->statistics[player_index][1], 0, 0xE7, y,
                    0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, &this->statistics[player_index][2], 0, 0x11B, y,
                    0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, &this->statistics[player_index][3], 0, 0x150, y,
                    0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, &this->statistics[player_index][4], 0, 0x185, y,
                    0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, &this->statistics[player_index][5], 0, 0x1BA, y,
                    0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, &this->statistics[player_index][6], 0, 0x1EE, y,
                    0x33, 0x1D, 0x0B, 1, 1, 0);

        if (player_index + 1 < rge_base_game->world->player_num) {
            RGE_Player* player =
                rge_base_game->world->players[player_index + 1];
            switch (player->color_table->id) {
            case 0: color = 0xC40000; break;
            case 1: color = 200; break;
            case 2: color = 0xEAEA; break;
            case 3: color = 0x215A8C; break;
            case 4: color = 0x80FF; break;
            case 5: color = 0x8000; break;
            case 6: color = 0x808080; break;
            case 7: color = 0x808040; break;
            default: color = 0xFFFFFF; break;
            }
            this->player_names[player_index]->set_text_color(color, 0);
            for (int column = 0; column < 7; ++column) {
                this->statistics[player_index][column]->set_text_color(color, 0);
            }
        }

        y += 0x1E;
        ++player_index;
    } while (player_index < 8);

    // The shipped layout tests the non-null message arm first.
    if (this->end_game_flag == 0 || rge_base_game->singlePlayerGame() == 0) {
        create_button(this, &this->timelineButton, 0x26D8, 0, 100, 0x1B9,
                      200, 0x1E, 0, 0, 0);
        create_button(this, &this->okButton, 0x269C, 0, 0x154, 0x1B9,
                      200, 0x1E, 0, 0, 0);
    } else if (this->win_loss_text != 0) {
        create_button(this, &this->aftermathButton, 0x26B2, 0, 5, 0x1B9,
                      0x96, 0x1E, 0, 0, 0);
        create_button(this, &this->timelineButton, 0x26D8, 0, 0xA5, 0x1B9,
                      0x96, 0x1E, 0, 0, 0);
        create_button(this, &this->restartButton, 0x269F, 0, 0x145, 0x1B9,
                      0x96, 0x1E, 0, 0, 0);
        create_button(this, &this->okButton, 0x269C, 0, 0x1E5, 0x1B9,
                      0x96, 0x1E, 0, 0, 0);
    } else {
        create_button(this, &this->timelineButton, 0x26D8, 0, 0x14, 0x1B9,
                      0xB4, 0x1E, 0, 0, 0);
        create_button(this, &this->restartButton, 0x269F, 0, 0xE6, 0x1B9,
                      0xB4, 0x1E, 0, 0, 0);
        create_button(this, &this->okButton, 0x269C, 0, 0x1B8, 0x1B9,
                      0xB4, 0x1E, 0, 0, 0);
    }
    create_button(this, &this->backButton, 0x26DA, 0, 200, 0x1B9,
                  0xF0, 0x1E, 0, 0, 0);
    this->backButton->set_active(0);
    this->backButton->hotkey = 0x1B;
    this->backButton->hotkey_shift = 0;

    create_button(this, &this->backButton2, 0x269C, 0, 200, 0x1B9,
                  0xF0, 0x1E, 0, 0, 0);
    this->backButton2->set_active(0);
    this->backButton2->hotkey = 0x1B;
    this->backButton2->hotkey_shift = 0;
    this->okButton->hotkey = 0x1B;
    this->okButton->hotkey_shift = 0;

    RGE_Player* player = rge_base_game->get_player();
    if (player->game_status == 1) {
        this->win_decal = new TShape("viccheck.slp", 0xCB21);
    } else {
        this->win_decal = new TShape("defcheck.slp", 0xCB22);
    }

    tab_count = 0;
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
    set_tab_order(tabList, static_cast<short>(tab_count));
    set_curr_child(this->okButton);
    this->backButton->set_tab_order(static_cast<TPanel*>(0),
                                    static_cast<TPanel*>(0));
    this->backButton2->set_tab_order(static_cast<TPanel*>(0),
                                     static_cast<TPanel*>(0));

    if (this->win_loss_text != 0) {
        set_mode(5);
    } else {
        set_mode(0);
    }
}

TribeAchievementsScreen::~TribeAchievementsScreen()
{
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
// order. Mode 3 calls victory IDs 15 and 16 in that order.
void TribeAchievementsScreen::set_mode(long mode)
{
    int player_num = static_cast<int>(rge_base_game->world->player_num) - 1;
    char temptxt[50];

    memset(temptxt + 31, 0, sizeof(temptxt) - 31);

    rge_base_game->disable_input();

    if (this->win_loss_text != 0) {
        this->win_loss_text->set_active(0);
    }
    this->current_mode = mode;
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

    switch (mode) {
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
        this->summary_text->set_text(static_cast<long>(0x26D9));
        this->title_bar[0]->set_text(static_cast<long>(0x26AC));
        this->title_bar[1]->set_text(static_cast<long>(0x26AD));
        this->title_bar[2]->set_text(static_cast<long>(0x26AE));
        this->title_bar[3]->set_text(static_cast<long>(0x26AF));
        this->title_bar[4]->set_text(static_cast<long>(0x26D6));
        this->title_bar[5]->set_text(static_cast<long>(0x26D7));
        this->title_bar[6]->set_text(static_cast<long>(0x26B1));

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
                    this->statistics[player_index][4]->set_text(
                        static_cast<long>(0xFA3));
                } else {
                    this->statistics[player_index][4]->set_text("");
                }
                if (player->victory_conditions->get_victory_points_id(0x17) > 0) {
                    this->statistics[player_index][5]->set_text(
                        static_cast<long>(0xFA3));
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
        this->summary_text->set_text(static_cast<long>(0x26AC));
        this->title_bar[0]->set_text(static_cast<long>(0x26B6));
        this->title_bar[1]->set_text(static_cast<long>(0x26B7));
        this->title_bar[2]->set_text(static_cast<long>(0x26B9));
        this->title_bar[3]->set_text(static_cast<long>(0x26B8));
        this->title_bar[4]->set_text(static_cast<long>(0x26BA));
        this->title_bar[5]->set_text(static_cast<long>(0x26B5));

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
                itoa(static_cast<long>(
                         player->attributes[19] - player->attributes[11]),
                     temptxt, 10);
                this->statistics[player_index][2]->set_text(temptxt);

                itoa(player->victory_conditions->get_attribute_id(2), temptxt, 10);
                this->statistics[player_index][3]->set_text(temptxt);

                if (player->victory_conditions->get_victory_points_id(3) > 0) {
                    this->statistics[player_index][4]->set_text(
                        static_cast<long>(0xFA3));
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
        this->summary_text->set_text(static_cast<long>(0x26AD));
        this->title_bar[0]->set_text(static_cast<long>(0x26BE));
        this->title_bar[1]->set_text(static_cast<long>(0x26BF));
        this->title_bar[2]->set_text(static_cast<long>(0x26C0));
        this->title_bar[3]->set_text(static_cast<long>(0x26C1));
        this->title_bar[4]->set_text(static_cast<long>(0x26C2));
        this->title_bar[5]->set_text(static_cast<long>(0x26C3));
        this->title_bar[6]->set_text(static_cast<long>(0x26B5));

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
                    this->statistics[player_index][2]->set_text(
                        static_cast<long>(0xFA3));
                } else {
                    this->statistics[player_index][2]->set_text("");
                }

                sprintf(temptxt, "%d", player->victory_conditions->get_attribute_id(7));
                this->statistics[player_index][3]->set_text(temptxt);

                if (player->victory_conditions->get_victory_points_id(8) > 0) {
                    this->statistics[player_index][4]->set_text(
                        static_cast<long>(0xFA3));
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
        this->summary_text->set_text(static_cast<long>(0x26AE));
        this->title_bar[0]->set_text(static_cast<long>(0x26C6));
        this->title_bar[1]->set_text(static_cast<long>(0x26C7));
        this->title_bar[2]->set_text(static_cast<long>(0x26C8));
        this->title_bar[3]->set_text(static_cast<long>(0x26C9));
        this->title_bar[4]->set_text(static_cast<long>(0x26CA));
        this->title_bar[5]->set_text(static_cast<long>(0x26DC));
        this->title_bar[6]->set_text(static_cast<long>(0x26B5));

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
                    this->statistics[player_index][1]->set_text(
                        static_cast<long>(0xFA3));
                } else {
                    this->statistics[player_index][1]->set_text("");
                }

                itoa(player->victory_conditions->get_attribute_id(12), temptxt, 10);
                this->statistics[player_index][2]->set_text(temptxt);
                itoa(player->victory_conditions->get_attribute_id(13), temptxt, 10);
                this->statistics[player_index][3]->set_text(temptxt);
                itoa(player->victory_conditions->get_attribute_id(14), temptxt, 10);
                this->statistics[player_index][4]->set_text(temptxt);

                itoa(player->victory_conditions->get_victory_points_id(15) +
                     player->victory_conditions->get_victory_points_id(16), temptxt, 10);
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
        this->summary_text->set_text(static_cast<long>(0x26AF));
        this->title_bar[0]->set_text(static_cast<long>(0x26CE));
        this->title_bar[1]->set_text(static_cast<long>(0x26D1));
        this->title_bar[2]->set_text(static_cast<long>(0x26CF));
        this->title_bar[3]->set_text(static_cast<long>(0x26D0));
        this->title_bar[4]->set_text(static_cast<long>(0x26B5));

        if (player_num > 0) {
            int player_index = 0;
            int remaining = player_num;
            while (remaining != 0) {
                RGE_Player* player;
                player = rge_base_game->world->players[player_index + 1];

                itoa(player->victory_conditions->get_attribute_id(17), temptxt, 10);
                this->statistics[player_index][0]->set_text(temptxt);
                if (player->victory_conditions->get_victory_points_id(18) > 0) {
                    this->statistics[player_index][1]->set_text(
                        static_cast<long>(0xFA3));
                } else {
                    this->statistics[player_index][1]->set_text("");
                }
                if (player->victory_conditions->get_victory_points_id(19) > 0) {
                    this->statistics[player_index][2]->set_text(
                        static_cast<long>(0xFA3));
                } else {
                    this->statistics[player_index][2]->set_text("");
                }
                if (player->victory_conditions->get_victory_points_id(20) > 0) {
                    this->statistics[player_index][3]->set_text(
                        static_cast<long>(0xFA3));
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
        this->summary_text->set_text(static_cast<long>(0x26D8));
        this->time->set_active(1);
        break;

    case 5:
        this->size = 0;
        this->summary_text->set_text(static_cast<long>(0x26B2));
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

void TribeAchievementsScreen::draw()
{
    TScreenPanel::draw();

    if (this->current_mode < 5) {
        this->draw_setup(0);

        if (this->win_decal != 0 &&
            this->render_area->Lock("scr_ach::draw", 1) != 0) {
            RGE_Game_World* world = rge_base_game->world;
            int count = world->player_num - 1;

            if (count > 0) {
                int remaining;
                int player_index = 0;
                for (remaining = count; remaining != 0; --remaining) {
                    if (world->players[player_index + 1]->game_status == 1) {
                        this->win_decal->shape_draw(
                            this->render_area,
                            this->player_names[player_index]->xPosition() - 0x14,
                            this->player_names[player_index]->yPosition(),
                            0, 0, 0);
                    }
                    ++player_index;
                }
            }

            this->render_area->Unlock("scr_ach::draw");
        }

        this->draw_finish();
    }
}

// long, int, int)
long TribeAchievementsScreen::handle_mouse_down(unsigned char button, long x,
                                                long y, int flags, int area)
{
    long result = TEasy_Panel::handle_mouse_down(button, x, y, flags, area);
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

// unsigned long)
long TribeAchievementsScreen::action(TPanel* panel, long id,
                                     unsigned long param3,
                                     unsigned long param4)
{
    if (panel == this->okButton && id == 1) {
        if (this->end_game_flag != 0) {
            static_cast<TRIBE_Game*>(rge_base_game)->quit_game();
        } else {
            if (rge_base_game->singlePlayerGame() == 1 &&
                rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            panel_system.setCurrentPanel("Game Screen", 0);
        }
        panel_system.destroyPanel("Achievements Screen");
        return 1;
    }

    if (panel == this->restartButton && id == 1) {
        static_cast<TRIBE_Game*>(rge_base_game)->restart_game();
        return id;
    }

    if (panel == this->timelineButton && id == 1) {
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
            return id;
        }
    } else {
        if (panel != this->aftermathButton || id != 1) {
            if ((panel == this->backButton || panel == this->backButton2) &&
                id == 1) {
                this->set_mode(0);
                return id;
            } else if (panel == this->close_button && id == 1) {
                rge_base_game->close();
                return id;
            } else {
                char* panel_name = panel->panelName();
                if (panel_name != 0 &&
                    strcmp(panel->panelName(), "YesNoDialog") == 0) {
                    panel_system.destroyPanel("YesNoDialog");
                    if (id == 0) {
                        rge_base_game->close();
                    } else {
                        confirmed_close = 0;
                    }
                    return 1;
                }

                return TEasy_Panel::action(panel, id, param3, param4);
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
            return id;
        }
    }

    return 1;
}

long TribeAchievementsScreen::handle_idle()
{
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

// unsigned int, long)
long TribeAchievementsScreen::wnd_proc(void* h1, unsigned int msg,
                                       unsigned int w, long l)
{
    if (msg == 0x10 && confirmed_close == 0) {
        confirmed_close = 1;
        int mode = rge_base_game->prog_mode;
        if (mode == 5 || mode == 4 || mode == 6 || mode == 7) {
            if (IsIconic(render_area->Wnd) == 0) {
                popupYesNoDialog(get_string(0xC1D), 0, 0x1C2, 100);
                return 1;
            }
        }
    }
    return TPanel::wnd_proc(h1, msg, w, l);
}
