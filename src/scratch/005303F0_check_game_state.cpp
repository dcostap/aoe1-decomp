// VA: 005303F0 TRIBE_World::check_game_state
// PDB source: tworld.cpp lines 1151-1371
// Attempt log:
// 1: initial natural reconstruction from Ghidra body, typed local arrays and direct call surfaces.
// 2: corrected world/player offsets, float constants, and direct victory/message call surfaces; call set aligned but body remained structurally broad.
// 3: tried source loop/local-shape reductions and external float constants; no exact basin, frame/size still drift.
// 4: replaced the raw volatile game-state guard with the named game_state field; emitted code was unchanged, so the natural form remains.
// 5: threshold-left and negated-less countdown guards changed FPU order but did not match; kept the period guard form.
// 6: removing the positive array-init guard changed the call prefix and worsened the body; restored it.
// 7-8: local base-game aliases prevented message-call tail merging and aligned all virtual calls, but added code.
// 9: removed the grouping p local and used direct player expressions; frame reached 0x1A4 and team arrays reached original homes.
// 10: removed the outer team-building guard; one loop entry test now matches the original and size dropped to +22 bytes.
// 11: cached player_count across team setup; size reached +11 bytes, but register/block shape worsened.
// 12: kept a local base-game alias for the ruin-start message; all 16 calls now align, with 1668 rebuilt bytes vs 1653 original.
// 13: tested the proven 00577580 global for held == -1 comparisons; kept it because the original has two absolute references.
// 14: tested scoped base-game aliases at each message site and direct player_num bounds; call and block shape improved, but the source was compiler-steering and was rolled back.
// 15: restored the clean cached-player reconstruction; remaining drift is team-array scheduling and the saved this home.
// Main-agent audit replaced raw-address macros with named extern globals. The
// same typed source now emits 1653 bytes with 1494 differing bytes.
// Budget end: left in scratch. Frame is 0x1A4 and all 16 calls align. The
// first mismatch is the saved-this home. Team-array and victory-block
// scheduling remain divergent.

class RGE_Victory_Conditions {
public:
    int get_victory_points();
};

class RGE_Game_World;

extern float DAT_00577578;
extern float DAT_00577580;

class RGE_Player {
public:
    virtual void v00();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory; // +34
    char gap_38[0x12];
    short player_id;                 // +4a
    char gap_4c[0x34];
    unsigned char game_status;      // +80
    char gap_81[0x83];
    unsigned char allied_victory;   // +104

    unsigned char check_victory();
    unsigned char relation(int player_id);
    void win_game_now();
    void loss_if_game_on();
    void victory_if_game_on();
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_108[0x738];
    float ruin_held_time;           // +840
    float artifact_held_time;       // +844
};

class RGE_Scenario {
public:
    unsigned char Get_conquest_victory();
};

class RGE_Game_World {
public:
    virtual void v00();
    char gap_04[0x1d - 4];
    unsigned char game_state;     // +1d
    unsigned char game_end_condition; // +1e
    char gap_1f[0x3c - 0x1f];
    short player_num;             // +3c
    char gap_3e[2];
    TRIBE_Player** players;       // +40
    char gap_44[0x5c - 0x44];
    RGE_Scenario* scenario;       // +5c
    char gap_60[0x7c - 0x60];
    short curr_player;             // +7c
    char gap_7e[0x84 - 0x7e];
    float delta_time;              // +84
    char gap_88[0xa4 - 0x88];
    int campaign;                  // +a4
    int campaign_player;           // +a8
    int campaign_scenario;         // +ac
    char tail_b0[0x104 - 0xb0];

    unsigned char check_game_state();
};

class RGE_Base_Game {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void send_message(int msg, int player, int zero1, int zero2, int zero3);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[4];
    int victory_type;             // +108
    int artifact_count;           // +10c
    int ruin_count;               // +110
    unsigned char countdown_victory; // +114
    char gap_115[3];
    float countdown_clock;        // +118

    unsigned char check_game_state();
};

unsigned char TRIBE_World::check_game_state()
{
    int i;
    int held_time;
    int local_1a0;
    int team_count;
    int local_198;
    int team_size[9];
    int player_team[9];
    TRIBE_Player* team_player[9][9];

    if (this->game_state == 0) {
        if (this->victory_type == 2 && this->countdown_victory != 0 &&
            !(this->countdown_clock < DAT_00577578)) {
            this->countdown_clock = this->countdown_clock - (this->delta_time + this->delta_time);
            if (this->countdown_clock < DAT_00577578) {
                for (i = 0; i < 9; ++i)
                    team_size[i] = -1;
                for (i = 1; i < this->player_num; ++i) {
                    team_size[i] = this->players[i]->victory->get_victory_points();
                    held_time = 1;
                    if (this->players[i]->allied_victory != 0 && this->player_num > 1) {
                        for (local_1a0 = 1; local_1a0 < this->player_num; ++local_1a0) {
                            if (local_1a0 != i &&
                                this->players[i]->relation(local_1a0) == 0 &&
                                this->players[local_1a0]->relation(i) == 0 &&
                                this->players[local_1a0]->allied_victory != 0) {
                                team_size[i] += this->players[local_1a0]->victory->get_victory_points();
                                ++held_time;
                            }
                        }
                    }
                    team_size[i] /= held_time;
                }
                TRIBE_Player* winner = 0;
                int best = -1;
                for (i = 1; i < this->player_num; ++i) {
                    if (best < team_size[i]) {
                        winner = this->players[i];
                        best = team_size[i];
                    }
                }
                if (winner != 0) {
                    winner->win_game_now();
                    this->game_end_condition = 0x67;
                }
            }
        }

        if (this->artifact_count > 0 || this->ruin_count > 0) {
            int player_count = this->player_num;
            if (player_count > 0) {
                for (i = 0; i < player_count; ++i)
                    team_size[i] = 0;
                for (i = 0; i < player_count; ++i)
                    player_team[i] = -1;
            }
            local_198 = 0;
            held_time = 1;
            team_count = 0;
            for (i = 1; i < player_count; ++i) {
                if (player_team[i] == -1) {
                    player_team[i] = local_198;
                    int count = team_size[local_198];
                    team_player[local_198][count] = this->players[i];
                    ++count;
                    team_size[local_198] = count;
                    if (this->players[i]->allied_victory != 0) {
                        local_1a0 = 1;
                        for (; local_1a0 < player_count; ++local_1a0) {
                            if (player_team[local_1a0] == -1 &&
                                this->players[local_1a0]->allied_victory != 0 &&
                                this->players[i]->relation(local_1a0) == 0 &&
                                this->players[local_1a0]->relation(i) == 0) {
                                ++count;
                                player_team[local_1a0] = local_198;
                                team_player[local_198][count - 1] = this->players[local_1a0];
                                team_size[local_198] = count;
                            }
                        }
                    }
                    ++local_198;
                    team_count += 9;
                }
            }

            if (this->artifact_count > 0 && local_198 > 0) {
                for (i = 0; i < local_198; ++i) {
                    int count = team_size[i];
                    int total = 0;
                    for (int j = 0; j < count; ++j)
                        total += (int)team_player[i][j]->artifact_held_time;
                    if (total == this->artifact_count) {
                        TRIBE_Player* p = team_player[i][0];
                        float held = p->artifact_held_time;
                        if (held == DAT_00577580) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->artifact_held_time = 1.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->artifact_held_time = 2000.0f;
                                rge_base_game->send_message(0x72,
                                    p->player_id, 0, 0, 0);
                            }
                        }
                        else if (held >= DAT_00577578 && this->victory_type == 0) {
                            held = held - (this->delta_time + this->delta_time);
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->artifact_held_time = held;
                            if (held < DAT_00577578) {
                                p->win_game_now();
                                this->game_end_condition = 0x65;
                            }
                        }
                    }
                    else {
                        TRIBE_Player* p = team_player[i][0];
                        if (p->artifact_held_time != -1.0f) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->artifact_held_time = 0.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->artifact_held_time = -1.0f;
                                rge_base_game->send_message(0x73,
                                    p->player_id, 0, 0, 0);
                            }
                        }
                    }
                }
            }

            if (this->ruin_count > 0 && local_198 > 0) {
                for (i = 0; i < local_198; ++i) {
                    int count = team_size[i];
                    int total = 0;
                    for (int j = 0; j < count; ++j)
                        total += (int)team_player[i][j]->ruin_held_time;
                    if (total == this->ruin_count) {
                        TRIBE_Player* p = team_player[i][0];
                        float held = p->ruin_held_time;
                        if (held == DAT_00577580) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->ruin_held_time = 1.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->ruin_held_time = 2000.0f;
                                RGE_Base_Game* game = rge_base_game;
                                game->send_message(0x74, p->player_id, 0, 0, 0);
                            }
                        }
                        else if (held >= DAT_00577578 && this->victory_type == 0) {
                            held = held - (this->delta_time + this->delta_time);
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->ruin_held_time = held;
                            if (held < DAT_00577578) {
                                p->win_game_now();
                                this->game_end_condition = 0x66;
                            }
                        }
                    }
                    else {
                        TRIBE_Player* p = team_player[i][0];
                        if (p->ruin_held_time != -1.0f) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->ruin_held_time = 0.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->ruin_held_time = -1.0f;
                                rge_base_game->send_message(0x75, p->player_id, 0, 0, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    return RGE_Game_World::check_game_state();
}
