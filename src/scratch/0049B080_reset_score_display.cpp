// VA: 0049B080 TRIBE_Screen_Game::reset_score_display
// PDB source: scr_game.cpp
// Attempt log:
// - baseline was a broad decompiler-shaped reconstruction with the right frame
//   but the wrong owner/type and helper surfaces.
// - rebuilt the source around the period PLAYER_SCORE, TRIBE_World,
//   RGE_Player, communications, font, and message-panel ownership.  The
//   score records are filled through a cursor, grouped by allied relations,
//   then sorted and rendered through the eight named score panels.
// - replacing the fake get_active/player_status/progress/score_value helpers
//   with the proven base-game, communications, font, latency, and message
//   surfaces aligned all 24 call sites and exact size; best diff is 1063 bytes.
// - indexed PLAYER_SCORE references regressed size/shape; restored the natural
//   cursor form.  Stdio context and function-scope icon locals were codegen
//   neutral.  Remaining drift is broad local register/home and cursor layout,
//   beginning with the saved-this stack slot; left in scratch for a later pass.

#include <stdio.h>

extern "C" int sprintf(char*, const char*, ...);
extern "C" void qsort(void*, unsigned int, unsigned int,
                      int (*)(const void*, const void*));

struct RGE_Color_Table {
    char gap_00[0x26];
    short id;
};

class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    char gap_04[0x18];
    long total_points;
    long get_victory_points();
};

class RGE_Player {
public:
    void* vtable_ptr;
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x48];
    unsigned char game_status;
    unsigned char resigned;
    char gap_82[2];
    unsigned char* relations;
    char gap_88[0x7C];
    unsigned char allied_victory;
    unsigned char master_player_id;
    char gap_106[2];
    RGE_Color_Table* color_table;

    unsigned char relation(long player_id);
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x38];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0xC0];
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[0x18];
    unsigned char score_displayed;
};

class RGE_Font {
public:
    void* font;
    long font_wid;
    long font_hgt;
};

class RGE_Communications_Speed {
public:
    char gap_00[0x1BC];
    unsigned long player_avg_frames_msec[10];
    unsigned long GetPlayerLatency(unsigned int player);
};

class TCommunications_Handler {
public:
    char gap_00[0x14D4];
    RGE_Communications_Speed* Speed;

    int GetPlayerHumanity(unsigned int player);
    char* GetPlayerName(unsigned int player);
};

class RGE_Base_Game {
public:
    int numberPlayers();
    int playerID(int player);
    int multiplayerGame();
    RGE_Font* get_font(int font_id);
};

class TPanel {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void set_visible(int visible);
    char gap_04[0xF0];
};

class TMessagePanel : public TPanel {
public:
    void show_message2(int message_type, char* text,
                       unsigned long font_color1, unsigned long font_color2,
                       void* font, long font_wid, long font_hgt,
                       void* icon1, int icon_frame1,
                       void* icon2, int icon_frame2);
};

class TShape {
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x354];
    TShape* button_pics;
    char gap_44C[0x2C];
};

class TScreenPanel : public TEasy_Panel {
};

struct PLAYER_SCORE {
    int comm_id;
    int player_id;
    int team_id;
    long player_score;
    long team_score;
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x114];
    TMessagePanel* score_panel[8];
    char gap_5AC[8];
    TRIBE_World* world;

    void reset_score_display();
};

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#define comm (*(TCommunications_Handler**)0x0062C4C0)
#define score_compare ((int (*)(const void*, const void*))0x0049B000)
#define score_format ((const char*)0x00586510)

void TRIBE_Screen_Game::reset_score_display()
{
    int i;
    int local_2d4;
    int team;
    int icon_num2;
    int low_fps_player;
    TShape* icon1;
    int icon_frame1;
    TShape* icon2;
    int icon_frame2;
    PLAYER_SCORE player_score[9];
    char str[512];

    for (i = 0; i < 9; ++i) {
        player_score[i].comm_id = 0;
        player_score[i].player_id = 0;
        player_score[i].team_id = 0;
        player_score[i].player_score = 0;
        player_score[i].team_score = 0;
    }

    i = 0;
    icon_num2 = 1;
    PLAYER_SCORE* score = player_score;
    while (icon_num2 <= rge_base_game->numberPlayers()) {
        int player_id = rge_base_game->playerID(icon_num2);
        if (player_id != 0 && player_id < this->world->player_num) {
            if (score->team_id == 0) {
                ++i;
                score->team_id = i;
            }
            score->comm_id = icon_num2;
            score->player_id = player_id;
            score->player_score =
                this->world->players[player_id]->victory_conditions->get_victory_points();
            score->team_score = score->player_score;
            local_2d4 = 1;

            if (this->world->players[player_id]->allied_victory != 0) {
                int team_player = 1;
                PLAYER_SCORE* team_score = player_score;
                while (team_player <= rge_base_game->numberPlayers()) {
                    if (team_player != icon_num2) {
                        int player_id2 = rge_base_game->playerID(team_player);
                        if (player_id2 != 0 && player_id2 < this->world->player_num &&
                            this->world->players[player_id]->relation(player_id2) == 0 &&
                            this->world->players[player_id2]->relation(player_id) == 0 &&
                            this->world->players[player_id2]->allied_victory != 0) {
                            if (team_score->team_id == 0) {
                                team_score->team_id = score->team_id;
                            }
                            score->team_score +=
                                this->world->players[player_id2]->victory_conditions->get_victory_points();
                            ++local_2d4;
                        }
                    }
                    ++team_player;
                    ++team_score;
                }
            }
            score->team_score /= local_2d4;
        }
        ++icon_num2;
        ++score;
    }

    qsort(player_score, rge_base_game->numberPlayers(), sizeof(PLAYER_SCORE),
          score_compare);
    low_fps_player = 0;
    if (rge_base_game->multiplayerGame() != 0) {
        int low_fps = 11;
        PLAYER_SCORE* p = player_score;
        for (i = 0; i < 8; ++i, ++p) {
            if (p->team_id != 0 && comm->GetPlayerHumanity(p->comm_id) == 2) {
                unsigned long average = comm->Speed->player_avg_frames_msec[p->comm_id];
                int frame_rate;
                if (average > 999) {
                    frame_rate = 1;
                } else if (average < 10) {
                    frame_rate = 100;
                } else {
                    frame_rate = 1000 / average;
                }
                if (frame_rate < low_fps) {
                    low_fps_player = p->comm_id;
                    low_fps = frame_rate;
                }
            }
        }
    }

    PLAYER_SCORE* p = player_score;
    TMessagePanel** panel = this->score_panel;
    icon_num2 = 0;
    for (; icon_num2 < 8; ++icon_num2, ++p, ++panel) {
        if (*panel == 0) {
            return;
        }
        if (p->player_id == 0) {
            (*panel)->set_visible(0);
        } else {
            sprintf(str + 4, score_format, comm->GetPlayerName(p->comm_id),
                    p->player_score, p->team_score);

            RGE_Player* player = this->world->players[p->player_id];
            int font_color;
            int back_color;
            switch (player->color_table->id) {
            case 0:
                font_color = 0xFF0000;
                back_color = 0xB3B3B3;
                break;
            case 1: font_color = 0x2139C6; break;
            case 2: font_color = 0xFFFF; break;
            case 3: font_color = 0x4F73A3; break;
            case 4: font_color = 0x0F77F3; break;
            case 5: font_color = 0xC700; break;
            case 6: font_color = 0x7B90A2; break;
            case 7: font_color = 0xADAD00; break;
            default: font_color = 0xFFFFFF; break;
            }

            int dimmed = 0;
            if (player->game_status == 2) {
                dimmed = 1;
            } else if (rge_base_game->multiplayerGame() != 0) {
                int humanity = comm->GetPlayerHumanity(p->comm_id);
                if (humanity != 2 && humanity != 4) {
                    dimmed = 1;
                }
            }
            RGE_Font* font = rge_base_game->get_font(dimmed != 0 ? 8 : 11);

            icon1 = 0;
            icon_frame1 = 0;
            icon2 = 0;
            icon_frame2 = 0;
            if (rge_base_game->multiplayerGame() != 0 &&
                comm->GetPlayerHumanity(p->comm_id) == 2) {
                unsigned long latency = comm->Speed->GetPlayerLatency(p->comm_id);
                if (p->comm_id == low_fps_player) {
                    icon2 = this->button_pics;
                    icon_frame2 = 17;
                }
                if (latency >= 300) {
                    icon1 = this->button_pics;
                    icon_frame1 = 20;
                    if (latency <= 1000) {
                        icon_frame1 = 19;
                    }
                }
            }

            (*panel)->show_message2(5, str + 4, font_color, back_color,
                                    font->font, font->font_wid, font->font_hgt,
                                    icon1, icon_frame1, icon2, icon_frame2);
        }
    }
}
