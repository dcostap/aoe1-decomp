#include "../include/TribeAchievementsScreen.h"

#include "../include/Time_Line_Panel.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Scenario.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/TRIBE_Game.h"
#include "../include/TPanelSystem.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TShape.h"
#include "../include/TDrawArea.h"
#include "../include/TTextPanel.h"
#include "../include/TButtonPanel.h"
#include "../include/globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned long ach_player_color_to_rgb(long color_id) {
    // Source of truth: scr_ach.cpp.decomp @ 0x0048D530 (player color mapping)
    switch (color_id) {
    case 0: return 0xC40000;
    case 1: return 200;
    case 2: return 0xEAEA;
    case 3: return 0x215A8C;
    case 4: return 0x80FF;
    case 5: return 0x8000;
    case 6: return 0x808080;
    case 7: return 0x808040;
    default: return 0xFFFFFF;
    }
}

// Source of truth: scr_ach.cpp.decomp @ 0x0048D530
TribeAchievementsScreen::TribeAchievementsScreen(char* /*summary_text*/, int end_game_flag)
    : TScreenPanel((char*)"Achievements Screen") {
    this->end_game_flag = end_game_flag;
    this->current_mode = 0;
    this->size = 0;

    this->title = nullptr;
    this->time = nullptr;
    this->summary_text = nullptr;
    this->win_loss_text = nullptr;
    this->instruction = nullptr;
    this->time_line = nullptr;

    this->okButton = nullptr;
    this->timelineButton = nullptr;
    this->restartButton = nullptr;
    this->aftermathButton = nullptr;
    this->backButton = nullptr;
    this->backButton2 = nullptr;
    this->win_decal = nullptr;
    this->close_button = nullptr;

    this->instruction_bar = nullptr;
    this->win_loss_text_bar = nullptr;
    this->summary_text_bar = nullptr;

    for (int i = 0; i < 7; ++i) this->title_bar[i] = nullptr;
    for (int i = 0; i < 5; ++i) this->achievement_choice[i] = nullptr;
    for (int i = 0; i < 8; ++i) {
        this->player_names[i] = nullptr;
        for (int j = 0; j < 7; ++j) this->statistics[i][j] = nullptr;
    }

    if (rge_base_game == nullptr || rge_base_game->draw_area == nullptr) {
        this->error_code = 1;
        return;
    }

    char info_file[16];
    long info_id = 0xC38D;
    strcpy(info_file, "scr10");

    if (this->end_game_flag != 0) {
        RGE_Player* player = rge_base_game->get_player();
        if (player != nullptr && player->game_status == 1) {
            strcpy(info_file, "scr7");
            info_id = 0xC389;
        } else {
            strcpy(info_file, "scr8");
            info_id = 0xC38A;
        }
    }

    if (this->TScreenPanel::setup(rge_base_game->draw_area, info_file, info_id, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);

    // Time display (%02ld:%02ld:%02ld)
    char time_str[100];
    time_str[0] = '\0';
    long total_seconds = 0;
    if (rge_base_game->world != nullptr) {
        total_seconds = (long)(rge_base_game->world->world_time / 1000);
    }
    long hours = total_seconds / 3600;
    long minutes = (total_seconds / 60) % 60;
    long seconds = total_seconds % 60;
    sprintf(time_str, "%02ld:%02ld:%02ld", hours, minutes, seconds);

    this->create_text((TPanel*)this, &this->time, time_str, 0x1E0, 10, 0x6E, 0x14, 0x0B, 0, 0, 0);
    if (this->time != nullptr) {
        this->time->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);
    }

    // Title: "Achievements"
    this->create_text((TPanel*)this, &this->title, 0x269E, 0, 5, 0x280, 0x1E, 1, 1, 0, 0);

    // Top header text; content is set by set_mode().
    this->create_text((TPanel*)this, &this->summary_text, 0, 10, 0x23, 0x26C, 0x1E, 1, 1, 0, 0);

    // Instruction: "Click a column for more details."
    this->create_text((TPanel*)this, &this->instruction, 0x26DB, 10, 0x19A, 0x26C, 0x14, 0x0B, 1, 0, 0);

    // Optional end-game win/loss message panel + scrollbar.
    if (this->end_game_flag != 0 && rge_base_game->world != nullptr && rge_base_game->world->scenario != nullptr) {
        RGE_Player* player = rge_base_game->get_player();
        long msg_idx = (player != nullptr && player->game_status == 1) ? 2 : 3;
        // Decomp calls `RGE_Scenario::Get_message(2|3)`; these map to win/loss message pointers.
        char* msg = (msg_idx == 2) ? rge_base_game->world->scenario->win_message : rge_base_game->world->scenario->loss_message;
        if (msg != nullptr && msg[0] != '\0') {
            this->create_text((TPanel*)this, &this->win_loss_text, (char*)"", 10, 0x55, 0x26C, 0x14A, 0x0B, 0, 0, 1);
            if (this->win_loss_text != nullptr) {
                this->create_auto_scrollbar(&this->win_loss_text_bar, this->win_loss_text, 0x14);
                this->win_loss_text->set_bevel_info(4, (int)this->bevel_color1, (int)this->bevel_color2, (int)this->bevel_color3,
                                                    (int)this->bevel_color4, (int)this->bevel_color5, (int)this->bevel_color6);
                this->win_loss_text->set_text(msg);
            }
        }
    }

    // Timeline panel (created always; activated by set_mode(6))
    Time_Line_Panel::create_timeline((TPanel*)this, &this->time_line, 10, 0x55, 0x26C, 0x14A, 0x0B, 9, 0x280, 0x1E0);
    if (this->time_line != nullptr) {
        this->time_line->set_bevel_info(3,
                                        (int)this->bevel_color1, (int)this->bevel_color2, (int)this->bevel_color3, (int)this->bevel_color4,
                                        (int)this->bevel_color1, (int)this->bevel_color2);
        this->time_line->set_special_events((char*)"timeline.slp");
    }

    // Close (X) button.
    if (this->create_button((TPanel*)this, &this->close_button, 0x3EA, 0, 0, 0, 0, 0, 0, -1, 0) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->close_button != nullptr) {
        this->close_button->set_active(1);
        this->close_button->set_positioning((PositionMode)9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, nullptr, nullptr, nullptr, nullptr);
    }

    // Column header labels.
    this->create_text((TPanel*)this, &this->title_bar[0], (char*)"", 0x62, 0x97, 0xC8, 0x1E, 0x0B, 0, 0, 0);
    this->create_text((TPanel*)this, &this->title_bar[1], (char*)"", 0x98, 0x83, 0xC8, 0x1E, 0x0B, 0, 0, 0);
    this->create_text((TPanel*)this, &this->title_bar[2], (char*)"", 0xD4, 0x6F, 0x91, 0x1E, 0x0B, 0, 0, 0);
    this->create_text((TPanel*)this, &this->title_bar[3], (char*)"", 0x104, 0x5B, 0xC8, 0x1E, 0x0B, 1, 0, 0);
    this->create_text((TPanel*)this, &this->title_bar[4], (char*)"", 0x16C, 0x6F, 0x91, 0x1E, 0x0B, 0, 0, 0);
    this->create_text((TPanel*)this, &this->title_bar[5], (char*)"", 0x172, 0x83, 0xC8, 0x1E, 0x0B, 0, 0, 0);
    this->create_text((TPanel*)this, &this->title_bar[6], (char*)"", 0x1A8, 0x97, 0xC8, 0x1E, 0x0B, 0, 0, 0);

    if (this->title_bar[4] != nullptr) this->title_bar[4]->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);
    if (this->title_bar[5] != nullptr) this->title_bar[5]->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);
    if (this->title_bar[6] != nullptr) this->title_bar[6]->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);

    // Click targets for mode switching (in Summary mode).
    this->create_text((TPanel*)this, &this->achievement_choice[0], (char*)"", 100, 0x97, 0x82, 0xFA, 0x0B, 0, 0, 0);
    this->create_text((TPanel*)this, &this->achievement_choice[1], (char*)"", 0x9A, 0x83, 0x80, 0x112, 0x0B, 0, 0, 0);
    this->create_text((TPanel*)this, &this->achievement_choice[2], (char*)"", 0xD6, 0x6F, 0x79, 0x121, 0x0B, 0, 0, 0);
    this->create_text((TPanel*)this, &this->achievement_choice[3], (char*)"", 0x11A, 0x5B, 0x9C, 0x135, 0x0B, 0, 0, 0);
    this->create_text((TPanel*)this, &this->achievement_choice[4], (char*)"", 0x184, 0x6F, 0x79, 0x121, 0x0B, 0, 0, 0);

    // Player rows.
    long row_y = 0xAB;
    for (int row = 0; row < 8; ++row) {
        int player_index = row + 1;
        char* player_name = nullptr;
        if (rge_base_game->world != nullptr && player_index < rge_base_game->world->player_num &&
            rge_base_game->world->players[player_index] != nullptr) {
            player_name = rge_base_game->world->players[player_index]->name;
        }
        if (player_name == nullptr) player_name = (char*)"";

        this->create_text((TPanel*)this, &this->player_names[row], player_name, 0x16, row_y, 0x96, 0x1D, 0x0B, 0, 1, 0);
        for (int col = 0; col < 7; ++col) {
            long x = 0;
            switch (col) {
            case 0: x = 0xB2; break;
            case 1: x = 0xE7; break;
            case 2: x = 0x11B; break;
            case 3: x = 0x150; break;
            case 4: x = 0x185; break;
            case 5: x = 0x1BA; break;
            case 6: x = 0x1EE; break;
            default: x = 0; break;
            }
            this->create_text((TPanel*)this, &this->statistics[row][col], (char*)"", x, row_y, 0x33, 0x1D, 0x0B, 1, 1, 0);
        }

        if (rge_base_game->world != nullptr && player_index < rge_base_game->world->player_num) {
            long color_id = ((TRIBE_Game*)rge_base_game)->playerColor(player_index);
            unsigned long rgb = ach_player_color_to_rgb(color_id);

            if (this->player_names[row] != nullptr) this->player_names[row]->set_text_color(rgb, 0);
            for (int col = 0; col < 7; ++col) {
                if (this->statistics[row][col] != nullptr) this->statistics[row][col]->set_text_color(rgb, 0);
            }
        }

        row_y += 0x1E;
    }

    // Bottom buttons.
    long ok_w = 200;
    long ok_x = 0x154;

    if ((this->end_game_flag == 0) || (rge_base_game->singlePlayerGame() == 0)) {
        this->create_button((TPanel*)this, &this->timelineButton, 0x26D8, 0, 100, 0x1B9, 200, 0x1E, 0, 0, 0);
        ok_w = 200;
        ok_x = 0x154;
    } else if (this->win_loss_text == nullptr) {
        this->create_button((TPanel*)this, &this->timelineButton, 0x26D8, 0, 0x14, 0x1B9, 0xB4, 0x1E, 0, 0, 0);
        this->create_button((TPanel*)this, &this->restartButton, 0x269F, 0, 0xE6, 0x1B9, 0xB4, 0x1E, 0, 0, 0);
        ok_w = 0xB4;
        ok_x = 0x1B8;
    } else {
        this->create_button((TPanel*)this, &this->aftermathButton, 0x26B2, 0, 5, 0x1B9, 0x96, 0x1E, 0, 0, 0);
        this->create_button((TPanel*)this, &this->timelineButton, 0x26D8, 0, 0xA5, 0x1B9, 0x96, 0x1E, 0, 0, 0);
        this->create_button((TPanel*)this, &this->restartButton, 0x269F, 0, 0x145, 0x1B9, 0x96, 0x1E, 0, 0, 0);
        ok_w = 0x96;
        ok_x = 0x1E5;
    }

    this->create_button((TPanel*)this, &this->okButton, 0x269C, 0, ok_x, 0x1B9, ok_w, 0x1E, 0, 0, 0);
    this->create_button((TPanel*)this, &this->backButton, 0x26DA, 0, 200, 0x1B9, 0xF0, 0x1E, 0, 0, 0);
    if (this->backButton != nullptr) {
        this->backButton->set_active(0);
        this->backButton->hotkey = 0x1B;
        this->backButton->hotkey_shift = 0;
    }

    this->create_button((TPanel*)this, &this->backButton2, 0x269C, 0, 200, 0x1B9, 0xF0, 0x1E, 0, 0, 0);
    if (this->backButton2 != nullptr) {
        this->backButton2->set_active(0);
        this->backButton2->hotkey = 0x1B;
        this->backButton2->hotkey_shift = 0;
    }

    if (this->okButton != nullptr) {
        this->okButton->hotkey = 0x1B;
        this->okButton->hotkey_shift = 0;
    }

    // Win/loss decal for players with game_status == 1.
    RGE_Player* cur_player = rge_base_game->get_player();
    if (cur_player != nullptr && cur_player->game_status == 1) {
        this->win_decal = new TShape((char*)"viccheck.slp", 0xCB21);
    } else {
        this->win_decal = new TShape((char*)"defcheck.slp", 0xCB22);
    }

    // Tab order (excluding back buttons, which are only used in other modes).
    TPanel* tabList[8];
    short tabCount = 0;
    if (this->aftermathButton != nullptr) tabList[tabCount++] = (TPanel*)this->aftermathButton;
    if (this->timelineButton != nullptr) tabList[tabCount++] = (TPanel*)this->timelineButton;
    if (this->restartButton != nullptr) tabList[tabCount++] = (TPanel*)this->restartButton;
    if (this->okButton != nullptr) tabList[tabCount++] = (TPanel*)this->okButton;
    if (tabCount > 0) {
        this->set_tab_order(tabList, tabCount);
        this->set_curr_child((TPanel*)this->okButton);
    }
    if (this->backButton != nullptr) this->backButton->set_tab_order((TPanel*)nullptr, (TPanel*)nullptr);
    if (this->backButton2 != nullptr) this->backButton2->set_tab_order((TPanel*)nullptr, (TPanel*)nullptr);

    this->set_mode((this->win_loss_text == nullptr) ? 0 : 5);
}

// Source of truth: scr_ach.cpp.decomp @ 0x0048E210
TribeAchievementsScreen::~TribeAchievementsScreen() {
    if (panel_system != nullptr) {
        panel_system->destroyPanel((char*)"YesNoDialog");
    }

    delete this->win_decal;
    this->win_decal = nullptr;

    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->summary_text);
    this->delete_panel((TPanel**)&this->time);
    this->delete_panel((TPanel**)&this->win_loss_text);
    this->delete_panel((TPanel**)&this->instruction);

    this->delete_panel((TPanel**)&this->restartButton);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->backButton);
    this->delete_panel((TPanel**)&this->backButton2);
    this->delete_panel((TPanel**)&this->aftermathButton);
    this->delete_panel((TPanel**)&this->timelineButton);
    this->delete_panel((TPanel**)&this->time_line);

    this->delete_panel((TPanel**)&this->win_loss_text_bar);
    this->delete_panel((TPanel**)&this->summary_text_bar);
    this->delete_panel((TPanel**)&this->instruction_bar);
    this->delete_panel((TPanel**)&this->close_button);

    for (int i = 0; i < 7; ++i) this->delete_panel((TPanel**)&this->title_bar[i]);
    for (int i = 0; i < 5; ++i) this->delete_panel((TPanel**)&this->achievement_choice[i]);
    for (int i = 0; i < 8; ++i) {
        this->delete_panel((TPanel**)&this->player_names[i]);
        for (int j = 0; j < 7; ++j) this->delete_panel((TPanel**)&this->statistics[i][j]);
    }
}

// Source of truth: scr_ach.cpp.decomp @ 0x0048E400
void TribeAchievementsScreen::set_mode(long mode) {
    if (rge_base_game != nullptr) {
        rge_base_game->disable_input();
    }

    if (this->win_loss_text != nullptr) this->win_loss_text->set_active(0);
    if (this->time_line != nullptr) this->time_line->set_active(0);
    if (this->instruction != nullptr) this->instruction->set_active(0);
    if (this->time != nullptr) this->time->set_active(1);

    if (this->restartButton != nullptr) this->restartButton->set_active(0);
    if (this->okButton != nullptr) this->okButton->set_active(0);
    if (this->aftermathButton != nullptr) this->aftermathButton->set_active(0);
    if (this->timelineButton != nullptr) this->timelineButton->set_active(0);
    if (this->backButton != nullptr) this->backButton->set_active(0);
    if (this->backButton2 != nullptr) this->backButton2->set_active(0);

    this->current_mode = (int)mode;
    if (this->backButton != nullptr) this->set_curr_child((TPanel*)this->backButton);

    switch (mode) {
    case 0: { // Summary
        this->size = 7;
        if (this->okButton != nullptr) this->set_curr_child((TPanel*)this->okButton);
        if (this->restartButton != nullptr) this->restartButton->set_active(1);
        if (this->okButton != nullptr) this->okButton->set_active(1);
        if (this->aftermathButton != nullptr) this->aftermathButton->set_active(1);
        if (this->timelineButton != nullptr) this->timelineButton->set_active(1);
        if (this->backButton != nullptr) this->backButton->set_active(1);
        if (this->instruction != nullptr) this->instruction->set_active(1);

        if (this->summary_text != nullptr) this->summary_text->set_text(0x26D9); // "Summary"
        if (this->title_bar[0] != nullptr) this->title_bar[0]->set_text(0x26AC); // Military
        if (this->title_bar[1] != nullptr) this->title_bar[1]->set_text(0x26AD); // Economy
        if (this->title_bar[2] != nullptr) this->title_bar[2]->set_text(0x26AE); // Religion
        if (this->title_bar[3] != nullptr) this->title_bar[3]->set_text(0x26AF); // Technology
        if (this->title_bar[4] != nullptr) this->title_bar[4]->set_text(0x26D6); // Survival
        if (this->title_bar[5] != nullptr) this->title_bar[5]->set_text(0x26D7); // Wonder
        if (this->title_bar[6] != nullptr) this->title_bar[6]->set_text(0x26B1); // Total Score

        if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
            int num = rge_base_game->world->player_num - 1;
            for (int row = 0; row < 8; ++row) {
                if (row >= num) continue;
                RGE_Player* p = rge_base_game->world->players[row + 1];
                if (p == nullptr || p->victory_conditions == nullptr) continue;

                char buf[64];
                itoa((int)p->victory_conditions->get_victory_points_group(0), buf, 10);
                if (this->statistics[row][0]) this->statistics[row][0]->set_text(buf);
                itoa((int)p->victory_conditions->get_victory_points_group(1), buf, 10);
                if (this->statistics[row][1]) this->statistics[row][1]->set_text(buf);
                itoa((int)p->victory_conditions->get_victory_points_group(2), buf, 10);
                if (this->statistics[row][2]) this->statistics[row][2]->set_text(buf);
                itoa((int)p->victory_conditions->get_victory_points_group(3), buf, 10);
                if (this->statistics[row][3]) this->statistics[row][3]->set_text(buf);

                long v = p->victory_conditions->get_victory_points_id(0x16);
                if (this->statistics[row][4]) {
                    if (v < 1) {
                        this->statistics[row][4]->set_text((char*)"");
                    } else {
                        this->statistics[row][4]->set_text((long)0xFA3);
                    }
                }
                v = p->victory_conditions->get_victory_points_id(0x17);
                if (this->statistics[row][5]) {
                    if (v < 1) {
                        this->statistics[row][5]->set_text((char*)"");
                    } else {
                        this->statistics[row][5]->set_text((long)0xFA3);
                    }
                }

                itoa((int)p->victory_conditions->get_victory_points(), buf, 10);
                if (this->statistics[row][6]) this->statistics[row][6]->set_text(buf);
            }
        }
        break;
    }
    case 1: // Military
        this->size = 6;
        if (this->summary_text != nullptr) this->summary_text->set_text(0x26AC);
        if (this->title_bar[0] != nullptr) this->title_bar[0]->set_text(0x26B6); // Kills
        if (this->title_bar[1] != nullptr) this->title_bar[1]->set_text(0x26B7); // Razings
        if (this->title_bar[2] != nullptr) this->title_bar[2]->set_text(0x26B9); // Losses
        if (this->title_bar[3] != nullptr) this->title_bar[3]->set_text(0x26B8); // Kills - Losses
        if (this->title_bar[4] != nullptr) this->title_bar[4]->set_text(0x26BA); // Largest Army
        if (this->title_bar[5] != nullptr) this->title_bar[5]->set_text(0x26B5); // Total Score

        if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
            int num = rge_base_game->world->player_num - 1;
            for (int row = 0; row < 8; ++row) {
                if (row >= num) continue;
                RGE_Player* p = rge_base_game->world->players[row + 1];
                if (p == nullptr || p->victory_conditions == nullptr) continue;

                char buf[64];
                long kills = p->victory_conditions->get_attribute_id(0);
                long razings = p->victory_conditions->get_attribute_id(1);
                long losses = p->victory_conditions->get_attribute_id(2);

                itoa((int)kills, buf, 10);
                if (this->statistics[row][0]) this->statistics[row][0]->set_text(buf);
                itoa((int)razings, buf, 10);
                if (this->statistics[row][1]) this->statistics[row][1]->set_text(buf);
                itoa((int)losses, buf, 10);
                if (this->statistics[row][2]) this->statistics[row][2]->set_text(buf);
                itoa((int)(kills - losses), buf, 10);
                if (this->statistics[row][3]) this->statistics[row][3]->set_text(buf);

                long v = p->victory_conditions->get_victory_points_id(3);
                if (this->statistics[row][4]) {
                    if (v < 1) {
                        this->statistics[row][4]->set_text((char*)"");
                    } else {
                        this->statistics[row][4]->set_text((long)0xFA3);
                    }
                }

                itoa((int)p->victory_conditions->get_victory_points_group(0), buf, 10);
                if (this->statistics[row][5]) this->statistics[row][5]->set_text(buf);
            }
        }
        break;
    case 2: // Economy
        this->size = 7;
        if (this->summary_text != nullptr) this->summary_text->set_text(0x26AD);
        if (this->title_bar[0] != nullptr) this->title_bar[0]->set_text(0x26BE);
        if (this->title_bar[1] != nullptr) this->title_bar[1]->set_text(0x26BF);
        if (this->title_bar[2] != nullptr) this->title_bar[2]->set_text(0x26C0);
        if (this->title_bar[3] != nullptr) this->title_bar[3]->set_text(0x26C1);
        if (this->title_bar[4] != nullptr) this->title_bar[4]->set_text(0x26C2);
        if (this->title_bar[5] != nullptr) this->title_bar[5]->set_text(0x26C3);
        if (this->title_bar[6] != nullptr) this->title_bar[6]->set_text(0x26B5);

        if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
            int num = rge_base_game->world->player_num - 1;
            for (int row = 0; row < 8; ++row) {
                if (row >= num) continue;
                RGE_Player* p = rge_base_game->world->players[row + 1];
                if (p == nullptr || p->victory_conditions == nullptr) continue;

                char buf[64];
                itoa((int)p->victory_conditions->get_attribute_id(4), buf, 10);
                if (this->statistics[row][0]) this->statistics[row][0]->set_text(buf);
                itoa((int)p->victory_conditions->get_attribute_id(5), buf, 10);
                if (this->statistics[row][1]) this->statistics[row][1]->set_text(buf);

                long v = p->victory_conditions->get_victory_points_id(6);
                if (this->statistics[row][2]) {
                    if (v < 1) {
                        this->statistics[row][2]->set_text((char*)"");
                    } else {
                        this->statistics[row][2]->set_text((long)0xFA3);
                    }
                }

                sprintf(buf, "%d%%", (int)p->victory_conditions->get_attribute_id(7));
                if (this->statistics[row][3]) this->statistics[row][3]->set_text(buf);

                v = p->victory_conditions->get_victory_points_id(8);
                if (this->statistics[row][4]) {
                    if (v < 1) {
                        this->statistics[row][4]->set_text((char*)"");
                    } else {
                        this->statistics[row][4]->set_text((long)0xFA3);
                    }
                }

                itoa((int)p->victory_conditions->get_attribute_id(9), buf, 10);
                if (this->statistics[row][5]) this->statistics[row][5]->set_text(buf);
                itoa((int)p->victory_conditions->get_victory_points_group(1), buf, 10);
                if (this->statistics[row][6]) this->statistics[row][6]->set_text(buf);
            }
        }
        break;
    case 3: // Religion
        this->size = 7;
        if (this->summary_text != nullptr) this->summary_text->set_text(0x26AE);
        if (this->title_bar[0] != nullptr) this->title_bar[0]->set_text(0x26C6);
        if (this->title_bar[1] != nullptr) this->title_bar[1]->set_text(0x26C7);
        if (this->title_bar[2] != nullptr) this->title_bar[2]->set_text(0x26C8);
        if (this->title_bar[3] != nullptr) this->title_bar[3]->set_text(0x26C9);
        if (this->title_bar[4] != nullptr) this->title_bar[4]->set_text(0x26CA);
        if (this->title_bar[5] != nullptr) this->title_bar[5]->set_text(0x26DC);
        if (this->title_bar[6] != nullptr) this->title_bar[6]->set_text(0x26B5);

        if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
            int num = rge_base_game->world->player_num - 1;
            for (int row = 0; row < 8; ++row) {
                if (row >= num) continue;
                RGE_Player* p = rge_base_game->world->players[row + 1];
                if (p == nullptr || p->victory_conditions == nullptr) continue;

                char buf[64];
                itoa((int)p->victory_conditions->get_attribute_id(10), buf, 10);
                if (this->statistics[row][0]) this->statistics[row][0]->set_text(buf);

                long v = p->victory_conditions->get_victory_points_id(11);
                if (this->statistics[row][1]) {
                    if (v < 1) {
                        this->statistics[row][1]->set_text((char*)"");
                    } else {
                        this->statistics[row][1]->set_text((long)0xFA3);
                    }
                }

                itoa((int)p->victory_conditions->get_attribute_id(12), buf, 10);
                if (this->statistics[row][2]) this->statistics[row][2]->set_text(buf);
                itoa((int)p->victory_conditions->get_attribute_id(13), buf, 10);
                if (this->statistics[row][3]) this->statistics[row][3]->set_text(buf);
                itoa((int)p->victory_conditions->get_attribute_id(14), buf, 10);
                if (this->statistics[row][4]) this->statistics[row][4]->set_text(buf);

                long a = p->victory_conditions->get_victory_points_id(0x10);
                long b = p->victory_conditions->get_victory_points_id(0x0F);
                itoa((int)(a + b), buf, 10);
                if (this->statistics[row][5]) this->statistics[row][5]->set_text(buf);

                itoa((int)p->victory_conditions->get_victory_points_group(2), buf, 10);
                if (this->statistics[row][6]) this->statistics[row][6]->set_text(buf);
            }
        }
        break;
    case 4: // Technology
        this->size = 5;
        if (this->summary_text != nullptr) this->summary_text->set_text(0x26AF);
        if (this->title_bar[0] != nullptr) this->title_bar[0]->set_text(0x26CE);
        if (this->title_bar[1] != nullptr) this->title_bar[1]->set_text(0x26D1);
        if (this->title_bar[2] != nullptr) this->title_bar[2]->set_text(0x26CF);
        if (this->title_bar[3] != nullptr) this->title_bar[3]->set_text(0x26D0);
        if (this->title_bar[4] != nullptr) this->title_bar[4]->set_text(0x26B5);

        if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
            int num = rge_base_game->world->player_num - 1;
            for (int row = 0; row < 8; ++row) {
                if (row >= num) continue;
                RGE_Player* p = rge_base_game->world->players[row + 1];
                if (p == nullptr || p->victory_conditions == nullptr) continue;

                char buf[64];
                itoa((int)p->victory_conditions->get_attribute_id(0x11), buf, 10);
                if (this->statistics[row][0]) this->statistics[row][0]->set_text(buf);

                long v = p->victory_conditions->get_victory_points_id(0x12);
                if (this->statistics[row][1]) {
                    if (v < 1) {
                        this->statistics[row][1]->set_text((char*)"");
                    } else {
                        this->statistics[row][1]->set_text((long)0xFA3);
                    }
                }

                v = p->victory_conditions->get_victory_points_id(0x13);
                if (this->statistics[row][2]) {
                    if (v < 1) {
                        this->statistics[row][2]->set_text((char*)"");
                    } else {
                        this->statistics[row][2]->set_text((long)0xFA3);
                    }
                }

                v = p->victory_conditions->get_victory_points_id(0x14);
                if (this->statistics[row][3]) {
                    if (v < 1) {
                        this->statistics[row][3]->set_text((char*)"");
                    } else {
                        this->statistics[row][3]->set_text((long)0xFA3);
                    }
                }

                itoa((int)p->victory_conditions->get_victory_points_group(3), buf, 10);
                if (this->statistics[row][4]) this->statistics[row][4]->set_text(buf);
            }
        }
        break;
    case 5: // Aftermath
        this->size = 0;
        if (this->summary_text != nullptr) this->summary_text->set_text(0x26B2);
        if (this->win_loss_text != nullptr) this->win_loss_text->set_active(1);
        if (this->time != nullptr) this->time->set_active(0);
        if (this->backButton != nullptr) this->backButton->set_active(1);
        if (this->backButton2 != nullptr) {
            this->backButton2->set_active(1);
            this->set_curr_child((TPanel*)this->backButton2);
        }
        break;
    case 6: // Timeline
        this->size = 0;
        if (this->time_line != nullptr) this->time_line->set_active(1);
        if (this->summary_text != nullptr) this->summary_text->set_text(0x26D8);
        if (this->time != nullptr) this->time->set_active(1);
        if (this->backButton != nullptr) this->backButton->set_active(1);
        break;
    default:
        break;
    }

    // Table visibility
    int max_rows = 0;
    if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
        max_rows = rge_base_game->world->player_num - 1;
        if (max_rows < 0) max_rows = 0;
        if (max_rows > 8) max_rows = 8;
    }

    if (this->size == 0) {
        for (int row = 0; row < 8; ++row) {
            if (this->player_names[row] != nullptr) this->player_names[row]->set_active(0);
        }
    } else {
        for (int row = 0; row < 8; ++row) {
            int active = (row < max_rows) ? 1 : 0;
            if (this->player_names[row] != nullptr) this->player_names[row]->set_active(active);
        }
    }

    for (int col = 0; col < 7; ++col) {
        if (this->title_bar[col] != nullptr) this->title_bar[col]->set_active((col < this->size) ? 1 : 0);
        for (int row = 0; row < 8; ++row) {
            if (this->statistics[row][col] != nullptr) {
                int active = (this->size != 0) && (row < max_rows) && (col < this->size);
                this->statistics[row][col]->set_active(active ? 1 : 0);
            }
        }
    }
}

// Source of truth: scr_ach.cpp.decomp @ 0x0048F0B0
void TribeAchievementsScreen::draw() {
    TScreenPanel::draw();

    if (this->current_mode < 5 && this->win_decal != nullptr && this->render_area != nullptr) {
        uchar* bits = this->render_area->Lock((char*)"scr_ach::draw", 1);
        if (bits != nullptr) {
            if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
                for (int row = 0; row < 8; ++row) {
                    int player_index = row + 1;
                    if (player_index >= rge_base_game->world->player_num) break;
                    RGE_Player* p = rge_base_game->world->players[player_index];
                    if (p != nullptr && p->game_status == 1 && this->player_names[row] != nullptr) {
                        long y = ((TPanel*)this->player_names[row])->yPosition();
                        long x = ((TPanel*)this->player_names[row])->xPosition();
                        this->win_decal->shape_draw(this->render_area, x - 0x14, y, 0, 0, nullptr);
                    }
                }
            }
            this->render_area->Unlock((char*)"scr_ach::draw");
        }
    }
}

// Source of truth: scr_ach.cpp.decomp @ 0x0048F190
long TribeAchievementsScreen::handle_mouse_down(uchar btn, long x, long y, int p4, int p5) {
    long ret = TEasy_Panel::handle_mouse_down(btn, x, y, p4, p5);
    if (this->current_mode == 0) {
        if (this->achievement_choice[0] != nullptr && this->achievement_choice[0]->is_inside(x, y) != 0) {
            this->set_mode(1);
            return ret;
        }
        if (this->achievement_choice[1] != nullptr && this->achievement_choice[1]->is_inside(x, y) != 0) {
            this->set_mode(2);
            return ret;
        }
        if (this->achievement_choice[2] != nullptr && this->achievement_choice[2]->is_inside(x, y) != 0) {
            this->set_mode(3);
            return ret;
        }
        if (this->achievement_choice[3] != nullptr && this->achievement_choice[3]->is_inside(x, y) != 0) {
            if (this->achievement_choice[4] != nullptr && this->achievement_choice[4]->is_inside(x, y) == 0) {
                this->set_mode(4);
            }
        }
    }
    return ret;
}

// Source of truth: scr_ach.cpp.decomp @ 0x0048F280
long TribeAchievementsScreen::action(TPanel* panel, long action_id, ulong param_3, ulong param_4) {
    if (((TButtonPanel*)panel == this->okButton) && (action_id == 1)) {
        if (this->end_game_flag == 0) {
            if (rge_base_game != nullptr && rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Game Screen", 0);
            }
        } else {
            ((TRIBE_Game*)rge_base_game)->quit_game();
        }
        if (panel_system != nullptr) {
            panel_system->destroyPanel((char*)"Achievements Screen");
        }
        return 1;
    }

    if (((TButtonPanel*)panel == this->restartButton) && (action_id == 1)) {
        ((TRIBE_Game*)rge_base_game)->restart_game();
        return 1;
    }

    if (((TButtonPanel*)panel == this->timelineButton) && (action_id == 1)) {
        this->set_mode(6);
        if (this->restartButton != nullptr) this->restartButton->set_active(0);
        if (this->okButton != nullptr) this->okButton->set_active(0);
        if (this->aftermathButton != nullptr) this->aftermathButton->set_active(0);
        if (this->timelineButton != nullptr) this->timelineButton->set_active(0);
        if (this->backButton != nullptr) this->backButton->set_active(1);
        return 1;
    }

    if (((TButtonPanel*)panel == this->aftermathButton) && (action_id == 1)) {
        this->set_mode(5);
        if (this->restartButton != nullptr) this->restartButton->set_active(0);
        if (this->okButton != nullptr) this->okButton->set_active(0);
        if (this->aftermathButton != nullptr) this->aftermathButton->set_active(0);
        if (this->timelineButton != nullptr) this->timelineButton->set_active(0);
        if (this->backButton != nullptr) this->backButton->set_active(1);
        return 1;
    }

    if ((((TButtonPanel*)panel == this->backButton) || ((TButtonPanel*)panel == this->backButton2)) && (action_id == 1)) {
        this->set_mode(0);
        return 1;
    }

    if (((TButtonPanel*)panel == this->close_button) && (action_id == 1)) {
        if (rge_base_game != nullptr) {
            rge_base_game->close();
        }
        return 1;
    }

    // Yes/No dialog response handling (if present).
    if (panel != nullptr) {
        char* name = panel->panelName();
        if (name != nullptr && strcmp(name, "YesNoDialog") == 0) {
            if (panel_system != nullptr) {
                panel_system->destroyPanel((char*)"YesNoDialog");
            }
            if (action_id != 0) {
                confirmed_close = 0;
                return 1;
            }
            if (rge_base_game != nullptr) {
                rge_base_game->close();
            }
            return 1;
        }
    }

    return TEasy_Panel::action(panel, action_id, param_3, param_4);
}

// Source of truth: scr_ach.cpp.decomp @ 0x0048F500
long TribeAchievementsScreen::handle_idle() {
    if (rge_base_game != nullptr && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

// Source of truth: scr_ach.cpp.decomp @ 0x0048F530
long TribeAchievementsScreen::wnd_proc(void* wnd, uint msg, uint wparam, long lparam) {
    // Fully verified. Source of truth: scr_ach.cpp.asm @ 0x0048F530
    if (msg == 0x10 && confirmed_close == 0) { // WM_CLOSE
        confirmed_close = 1;

        int pm = rge_base_game->prog_mode;
        if (pm == 4 || pm == 5 || pm == 6 || pm == 7) {
            if (IsIconic((HWND)this->render_area->Wnd) == 0) {
                this->popupYesNoDialog(this->get_string(0xc1d), nullptr, 0x1c2, 100);
                return 1;
            }
        }
    }

    return TPanel::wnd_proc(wnd, msg, wparam, lparam);
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TribeAchievementsScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TribeAchievementsScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeAchievementsScreen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TribeAchievementsScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeAchievementsScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeAchievementsScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TribeAchievementsScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TribeAchievementsScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeAchievementsScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TribeAchievementsScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeAchievementsScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeAchievementsScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeAchievementsScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TribeAchievementsScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeAchievementsScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TribeAchievementsScreen::paint() { TScreenPanel::paint(); }
long TribeAchievementsScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeAchievementsScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeAchievementsScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TribeAchievementsScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeAchievementsScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeAchievementsScreen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TribeAchievementsScreen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TribeAchievementsScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeAchievementsScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TribeAchievementsScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TribeAchievementsScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TribeAchievementsScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeAchievementsScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeAchievementsScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeAchievementsScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeAchievementsScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeAchievementsScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeAchievementsScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TribeAchievementsScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeAchievementsScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeAchievementsScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeAchievementsScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeAchievementsScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeAchievementsScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeAchievementsScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeAchievementsScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeAchievementsScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TribeAchievementsScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TribeAchievementsScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeAchievementsScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TribeAchievementsScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeAchievementsScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TribeAchievementsScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeAchievementsScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TribeAchievementsScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

