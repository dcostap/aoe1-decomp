// VA: 0048E400 TribeAchievementsScreen::set_mode (3205 B)
// PDB source: scr_ach.cpp (lines 441-744)
//
// Attempt log:
// - Replaced the unrelated mode shim with the packet-grounded screen-mode
//   setup: common panel reset, switch cases 0-6, per-player statistics, and
//   final active-state updates.
// - Recovered mode-1's six columns and mode-3's attribute-14 column from the
//   ordered original call stream; the canonical ownership remains the named
//   victory-condition/player surface above.
// - The original uses a count-controlled player loop and a row cursor beginning
//   at statistics[0] + 1 (or +2 for mode 2); retained that binary-proven typed
//   layout to preserve the per-player call topology.
// - Positive victory-point predicates reproduce the original yes/empty branch
//   order and align the statistics call stream; remaining drift is prologue/
//   register coloring plus three late call-site placements.

#include <stdio.h>
#include <stdlib.h>

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf_004();
    virtual void vf_008();
    virtual void vf_00C();
    virtual void vf_010();
    virtual void set_active(int active);
    virtual void vf_018();
    virtual void vf_01C();
    virtual void vf_020();
    virtual void vf_024();
    virtual void vf_028();
    virtual void vf_02C();
    virtual void vf_030();
    virtual void vf_034();
    virtual void vf_038();
    virtual void vf_03C();
    virtual void vf_040();
    virtual void vf_044();
    virtual void vf_048();
    virtual void vf_04C();
    virtual void vf_050();
    virtual void vf_054();
    virtual void vf_058();
    virtual void vf_05C();
    virtual void vf_060();
    virtual void vf_064();
    virtual void vf_068();
    virtual void vf_06C();
    virtual void vf_070();
    virtual void vf_074();
    virtual void vf_078();
    virtual void vf_07C();
    virtual void vf_080();
    virtual void vf_084();
    virtual void vf_088();
    virtual void vf_08C();
    virtual void vf_090();
    virtual void vf_094();
    virtual void vf_098();
    virtual void vf_09C();
    virtual void vf_0A0();
    virtual void vf_0A4();
    virtual void vf_0A8();
    virtual void vf_0AC();
    virtual void vf_0B0();
    virtual void vf_0B4();
    virtual void vf_0B8();
    virtual void vf_0BC();
    virtual void vf_0C0();
    virtual void vf_0C4();
    virtual void vf_0C8();
    virtual void vf_0CC();
    virtual void vf_0D0();
    virtual void vf_0D4();
    virtual void vf_0D8();
    virtual void vf_0DC();
    virtual void vf_0E0();
    virtual void set_text(char* text);
    virtual void set_text(long id);

    char gap_04[0xF0];
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
};

class TScreenPanel : public TEasy_Panel {
};

class TTextPanel : public TPanel {
};

class TButtonPanel : public TPanel {
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x14];

    int get_victory_points_group(unsigned char group);
    int get_attribute_id(unsigned char id);
    int get_victory_points_id(unsigned char id);
    int get_victory_points();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions; // +0x34
    char gap_38[0x18];
    float* attributes;                           // +0x50
};

class RGE_Game_World {
public:
    virtual void data_load_world();
    char gap_04[0x38];
    short player_num;                            // +0x3C
    char gap_3E[2];
    RGE_Player** players;                        // +0x40
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    RGE_Game_World* world;                       // +0x3F4

    void disable_input();
};

extern RGE_Base_Game* rge_base_game;

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;                           // +0x478
    int current_mode;                            // +0x47C
    int size;                                    // +0x480
    TTextPanel* title;                           // +0x484
    TTextPanel* summary_text;                    // +0x488
    TTextPanel* instruction;                     // +0x48C
    TTextPanel* win_loss_text;                   // +0x490
    TTextPanel* time;                            // +0x494
    TTextPanel* title_bar[7];                    // +0x498
    TTextPanel* achievement_choice[5];           // +0x4B4
    TTextPanel* statistics[8][7];                // +0x4C8
    TTextPanel* player_names[8];                 // +0x5A8
    TPanel* summary_text_bar;                    // +0x5C8
    TPanel* instruction_bar;                     // +0x5CC
    TPanel* win_loss_text_bar;                   // +0x5D0
    TButtonPanel* okButton;                      // +0x5D4
    TButtonPanel* backButton;                    // +0x5D8
    TButtonPanel* backButton2;                   // +0x5DC
    TButtonPanel* timelineButton;                // +0x5E0
    TButtonPanel* aftermathButton;               // +0x5E4
    TButtonPanel* restartButton;                 // +0x5E8
    TButtonPanel* close_button;                  // +0x5EC
    void* win_decal;                             // +0x5F0
    TPanel* time_line;                            // +0x5F4

    void set_mode(int mode);
};

void TribeAchievementsScreen::set_mode(int mode)
{
    int player_num = (int)rge_base_game->world->player_num - 1;
    char temptxt[50] = {0};

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
            this->backButton->set_active(1);
        }

        this->instruction->set_active(1);
        this->summary_text->set_text((long)0x26D9);
        this->title_bar[0]->set_text((long)0x26AC);
        this->title_bar[1]->set_text((long)0x26AD);
        this->title_bar[2]->set_text((long)0x26AE);
        this->title_bar[3]->set_text((long)0x26AF);
        this->title_bar[4]->set_text((long)0x26D6);
        this->title_bar[5]->set_text((long)0x26D7);
        this->title_bar[6]->set_text((long)0x26B1);

        if (player_num > 0) {
            int player_offset = 4;
            TTextPanel** row = this->statistics[0] + 1;
            int remaining = player_num;
            do {
            RGE_Player* player = *(RGE_Player**)((char*)rge_base_game->world->players + player_offset);
            RGE_Victory_Conditions* victory = player->victory_conditions;

            itoa(victory->get_victory_points_group(0), temptxt, 10);
            row[-1]->set_text(temptxt);
            itoa(victory->get_victory_points_group(1), temptxt, 10);
            row[0]->set_text(temptxt);
            itoa(victory->get_victory_points_group(2), temptxt, 10);
            row[1]->set_text(temptxt);
            itoa(victory->get_victory_points_group(3), temptxt, 10);
            row[2]->set_text(temptxt);

            if (victory->get_victory_points_id(0x16) > 0) {
                row[3]->set_text((long)0xFA3);
            } else {
                row[3]->set_text("");
            }
            if (victory->get_victory_points_id(0x17) > 0) {
                row[4]->set_text((long)0xFA3);
            } else {
                row[4]->set_text("");
            }

            itoa(victory->get_victory_points(), temptxt, 10);
            row[5]->set_text(temptxt);
            player_offset += 4;
            row += 7;
            --remaining;
            } while (remaining != 0);
        }
        break;
    }

    case 1: {
        this->size = 6;
        this->summary_text->set_text((long)0x26AC);
        this->title_bar[0]->set_text((long)0x26B6);
        this->title_bar[1]->set_text((long)0x26B7);
        this->title_bar[2]->set_text((long)0x26B9);
        this->title_bar[3]->set_text((long)0x26B8);
        this->title_bar[4]->set_text((long)0x26BA);
        this->title_bar[5]->set_text((long)0x26B5);

        if (player_num > 0) {
            int player_offset = 4;
            TTextPanel** row = this->statistics[0] + 1;
            int remaining = player_num;
            do {
            RGE_Player* player = *(RGE_Player**)((char*)rge_base_game->world->players + player_offset);
            RGE_Victory_Conditions* victory = player->victory_conditions;

            itoa(victory->get_attribute_id(0), temptxt, 10);
            row[-1]->set_text(temptxt);
            itoa(victory->get_attribute_id(1), temptxt, 10);
            row[0]->set_text(temptxt);
            itoa((long)(player->attributes[19] - player->attributes[11]), temptxt, 10);
            row[1]->set_text(temptxt);

            itoa(victory->get_attribute_id(2), temptxt, 10);
            row[2]->set_text(temptxt);

            if (victory->get_victory_points_id(3) > 0) {
                row[3]->set_text((long)0xFA3);
            } else {
                row[3]->set_text("");
            }

            itoa(victory->get_victory_points_group(0), temptxt, 10);
            row[4]->set_text(temptxt);
            player_offset += 4;
            row += 7;
            --remaining;
            } while (remaining != 0);
        }
        break;
    }

    case 2: {
        this->size = 7;
        this->summary_text->set_text((long)0x26AD);
        this->title_bar[0]->set_text((long)0x26BE);
        this->title_bar[1]->set_text((long)0x26BF);
        this->title_bar[2]->set_text((long)0x26C0);
        this->title_bar[3]->set_text((long)0x26C1);
        this->title_bar[4]->set_text((long)0x26C2);
        this->title_bar[5]->set_text((long)0x26C3);
        this->title_bar[6]->set_text((long)0x26B5);

        if (player_num > 0) {
            int player_offset = 4;
            TTextPanel** row = this->statistics[0] + 2;
            int remaining = player_num;
            do {
            RGE_Player* player = *(RGE_Player**)((char*)rge_base_game->world->players + player_offset);
            RGE_Victory_Conditions* victory = player->victory_conditions;

            itoa(victory->get_attribute_id(4), temptxt, 10);
            row[-2]->set_text(temptxt);
            itoa(victory->get_attribute_id(5), temptxt, 10);
            row[-1]->set_text(temptxt);

            if (victory->get_victory_points_id(6) > 0) {
                row[0]->set_text((long)0xFA3);
            } else {
                row[0]->set_text("");
            }

            sprintf(temptxt, "%d", victory->get_attribute_id(7));
            row[1]->set_text(temptxt);

            if (victory->get_victory_points_id(8) > 0) {
                row[2]->set_text((long)0xFA3);
            } else {
                row[2]->set_text("");
            }

            itoa(victory->get_attribute_id(9), temptxt, 10);
            row[3]->set_text(temptxt);
            itoa(victory->get_victory_points_group(1), temptxt, 10);
            row[4]->set_text(temptxt);
            player_offset += 4;
            row += 7;
            --remaining;
            } while (remaining != 0);
        }
        break;
    }

    case 3: {
        this->size = 7;
        this->summary_text->set_text((long)0x26AE);
        this->title_bar[0]->set_text((long)0x26C6);
        this->title_bar[1]->set_text((long)0x26C7);
        this->title_bar[2]->set_text((long)0x26C8);
        this->title_bar[3]->set_text((long)0x26C9);
        this->title_bar[4]->set_text((long)0x26CA);
        this->title_bar[5]->set_text((long)0x26DC);
        this->title_bar[6]->set_text((long)0x26B5);

        if (player_num > 0) {
            int player_offset = 4;
            TTextPanel** row = this->statistics[0] + 1;
            int remaining = player_num;
            do {
            RGE_Player* player = *(RGE_Player**)((char*)rge_base_game->world->players + player_offset);
            RGE_Victory_Conditions* victory = player->victory_conditions;

            this->time_line->set_active(0);
            itoa(victory->get_attribute_id(10), temptxt, 10);
            row[-1]->set_text(temptxt);

            if (victory->get_victory_points_id(11) > 0) {
                row[0]->set_text((long)0xFA3);
            } else {
                row[0]->set_text("");
            }

            itoa(victory->get_attribute_id(12), temptxt, 10);
            row[1]->set_text(temptxt);
            itoa(victory->get_attribute_id(13), temptxt, 10);
            row[2]->set_text(temptxt);
            itoa(victory->get_attribute_id(14), temptxt, 10);
            row[3]->set_text(temptxt);

            itoa(victory->get_victory_points_id(15) +
                 victory->get_victory_points_id(16), temptxt, 10);
            row[4]->set_text(temptxt);
            itoa(victory->get_victory_points_group(2), temptxt, 10);
            row[5]->set_text(temptxt);
            player_offset += 4;
            row += 7;
            --remaining;
            } while (remaining != 0);
        }
        break;
    }

    case 4: {
        this->size = 5;
        this->summary_text->set_text((long)0x26AF);
        this->title_bar[0]->set_text((long)0x26CE);
        this->title_bar[1]->set_text((long)0x26D1);
        this->title_bar[2]->set_text((long)0x26CF);
        this->title_bar[3]->set_text((long)0x26D0);
        this->title_bar[4]->set_text((long)0x26B5);

        if (player_num > 0) {
            int player_offset = 4;
            TTextPanel** row = this->statistics[0] + 1;
            int remaining = player_num;
            do {
            RGE_Player* player = *(RGE_Player**)((char*)rge_base_game->world->players + player_offset);
            RGE_Victory_Conditions* victory = player->victory_conditions;

            itoa(victory->get_attribute_id(17), temptxt, 10);
            row[-1]->set_text(temptxt);
            if (victory->get_victory_points_id(18) > 0) {
                row[0]->set_text((long)0xFA3);
            } else {
                row[0]->set_text("");
            }
            if (victory->get_victory_points_id(19) > 0) {
                row[1]->set_text((long)0xFA3);
            } else {
                row[1]->set_text("");
            }
            if (victory->get_victory_points_id(20) > 0) {
                row[2]->set_text((long)0xFA3);
            } else {
                row[2]->set_text("");
            }
            itoa(victory->get_victory_points_group(3), temptxt, 10);
            row[3]->set_text(temptxt);
            player_offset += 4;
            row += 7;
            --remaining;
            } while (remaining != 0);
        }
        break;
    }

    case 5:
        this->size = 0;
        this->summary_text->set_text((long)0x26B2);
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

    case 6:
        this->size = 0;
        this->time_line->set_active(0);
        this->summary_text->set_text((long)0x26D8);
        this->time->set_active(1);
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
