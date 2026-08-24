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
//   surfaces aligned all 24 call sites and exact size; current diff is 1066
//   bytes.
// - indexed PLAYER_SCORE references regressed size/shape; restored the natural
//   cursor form.  Stdio context and function-scope icon locals were codegen
//   neutral.  Remaining drift is broad local register/home and cursor layout,
//   beginning with the saved-this stack slot; left in scratch for a later pass.
// - initialized back_color to mirror the target's zeroed color register; this
//   kept size and calls but worsened the prior diff from 1063 to 1078 bytes and did
//   not move the saved-this home, so restored the clean source.
// - structural pass tried declaration/local order, explicit player-count
//   guards, indexed records, and for-loop cursor spelling.  These either
//   emitted the same clean basin or broke size; the target's EDI byte
//   stride and saved-this home remain unresolved.
// - binary low-fps scan checks player_id, not team_id; corrected that guard.
//   A separate low-fps loop counter was codegen-neutral and remains natural.
// - ABI audit: used the committed rge_base_game storage accessor and a typed
//   communication storage accessor.  This removes unresolved global data
//   symbols while preserving direct loads from 0062C574 and 0062C4C0.
// - ABI audit: declared scr_game_score_compare with its C++ function ABI.
//   The qsort relocation names the exact comparator instead of using an
//   address cast.  These audit changes are byte-neutral in the clean basin.
// - sustained pass sa-8efe6dbe-r1: 23 meaningful probes, plus ambient and
//   flag labs.  The clean source is restored below.  It has 1206 bytes, a
//   0x2D4 frame, four saved registers, and all 24 ordered calls.
// - BINARY NOTE: the oracle saves this in [esp+14] and keeps this in EBP.
//   The clean source keeps this in EBX and saves it in [esp+1C].
// - BINARY NOTE: the oracle uses an EDI byte stride for PLAYER_SCORE.  The
//   clean typed cursor uses ESI.  Direct indexed and raw byte-cursor forms
//   grew or weakened the function, so they are not retained.
// - BINARY NOTE: the font choice has two explicit push blocks at lines 4450
//   and 4452.  An explicit source if/else restored the conditional count and
//   many exact blocks, but increased the strict diff to 1074 bytes.
// - LIKELY INTENT: the shipped source initializes the background color and
//   uses an explicit font branch.  That form reached 345 instructions and a
//   1070-byte diff, but its register map remains wrong.
// - Ambient declarations produced one codegen group across 128 samples.
//   Risky flag variants did not improve the default flag result.  No exact
//   source or compiler-context basin was found.
// - Fresh claim sa-a8885e99-r1: positive outer guards, scoped do/while cursors,
//   direct one-based record indexing, receiver aliases, array declaration order,
//   and top-scope cursor declarations were neutral or worse.  The proven raw
//   byte-cursor form reproduced the prior 1065-byte diagnostic result but not
//   the target register basin, so the natural typed cursor remains authoritative.
// - Fresh claim validation: restored clean source is 1206 bytes, frame 0x2D4,
//   four saved registers, 24 ordered calls, and 1066 differing bytes.  The first
//   mismatch remains the saved receiver at +9; no accepted-drift residue is safe.
// - Fresh claim sa-d51a4bbf-r1 context gate: PDB source is scr_game.cpp,
//   lines 4310-4486, and the qualified owner is
//   TRIBE_Screen_Game::reset_score_display.  The executable boundary is
//   0049B080-0049B535.  The next normal unleased sibling after setup_buttons
//   in this PDB order is this target at 0049B080.
// - BINARY NOTE: the target-local six-slot panel surface is required.  It puts
//   set_visible at virtual slot +0x14 and preserves the +0x58C panel array and
//   +0x5B4 world field.  The pinned VC5 direct build then aligns all 24 calls.
// - Fresh claim probes tested receiver aliases, indexed records, declaration
//   order, score-index and packed field-pointer forms.  They did not reach
//   exact output.  The packed forms reached 1065 differing bytes but retained
//   an unsupported opaque cursor shape, so the typed cursor remains clean.
// - Fresh claim validation first hit an unrelated in-flight
//   config/translation_units.json owner conflict at 00543E00.  After that
//   conflict cleared, the authoritative checker confirmed the direct pinned
//   VC5 result: 1206 bytes, 24 ordered calls, and 1066 differing bytes.

#include <stdio.h>
#include "../../include/rge_base_game_global.h"

#if !defined(SCR_GAME_TU_CONTEXT)
extern "C" int sprintf(char*, const char*, ...);
extern "C" void qsort(void*, unsigned int, unsigned int,
                      int (*)(const void*, const void*));

int scr_game_score_compare(const void*, const void*);

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

#define score_format "%s: %d/%d"

static __inline TCommunications_Handler* communications_at_storage()
{
    return *(TCommunications_Handler**)0x0062C4C0;
}
#endif

#if defined(SCR_GAME_TU_CONTEXT)
#define score_format "%s: %d/%d"
static __inline TCommunications_Handler* communications_at_storage()
{
    return comm;
}
#endif

void TRIBE_Screen_Game::reset_score_display()
{
    int i;
    int j;
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
    while (icon_num2 <= rge_base_game_at_storage()->numberPlayers()) {
        int player_id = rge_base_game_at_storage()->playerID(icon_num2);
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
                while (team_player <= rge_base_game_at_storage()->numberPlayers()) {
                    if (team_player != icon_num2) {
                        int player_id2 = rge_base_game_at_storage()->playerID(team_player);
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

    qsort(player_score, rge_base_game_at_storage()->numberPlayers(), sizeof(PLAYER_SCORE),
          scr_game_score_compare);
    low_fps_player = 0;
    if (rge_base_game_at_storage()->multiplayerGame() != 0) {
        int low_fps = 11;
        PLAYER_SCORE* p = player_score;
        for (j = 0; j < 8; ++j, ++p) {
            if (p->player_id != 0 && communications_at_storage()->GetPlayerHumanity(p->comm_id) == 2) {
                unsigned long average = communications_at_storage()->Speed->player_avg_frames_msec[p->comm_id];
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
            sprintf(str + 4, score_format, communications_at_storage()->GetPlayerName(p->comm_id),
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
            } else if (rge_base_game_at_storage()->multiplayerGame() != 0) {
                int humanity = communications_at_storage()->GetPlayerHumanity(p->comm_id);
                if (humanity != 2 && humanity != 4) {
                    dimmed = 1;
                }
            }
            RGE_Font* font = rge_base_game_at_storage()->get_font(dimmed != 0 ? 8 : 11);

            icon1 = 0;
            icon_frame1 = 0;
            icon2 = 0;
            icon_frame2 = 0;
            if (rge_base_game_at_storage()->multiplayerGame() != 0 &&
                communications_at_storage()->GetPlayerHumanity(p->comm_id) == 2) {
                unsigned long latency = communications_at_storage()->Speed->GetPlayerLatency(p->comm_id);
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
