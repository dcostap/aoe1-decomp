// 00531240 TRIBE_World::fill_in_score
// PDB source: tworld.cpp:1610-1637
//
// Baseline reconstruction: choose the highest victory score among human
// players (slots 1 through player_num - 1), copy the selected player's
// display data, then count mutually unrelated other players.
// Main-agent audit restored polymorphic player/world ownership at the proven
// offsets; emitted code remains exact.

#include <string.h>

#ifndef TWORLD_PHASE2_CONTEXT
class RGE_Victory_Conditions {
public:
    int get_victory_points_group(unsigned char group);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory;
    char gap_38[0x0c];
    char* name;
    char gap_48[0x0c];
    unsigned char civ;

    int computerPlayer();
    unsigned char relation(long player);
};

struct TRIBE_Zone_High_Score_Info {
    long score;
    unsigned char civ;
    char player_name[0x10];
    unsigned char num_allies;
};

class TRIBE_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x38];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;

    void fill_in_score(TRIBE_Zone_High_Score_Info& info, long group);
};
#endif

void TRIBE_World::fill_in_score(TRIBE_Zone_High_Score_Info& info, long group)
{
    int player = 1;
    long high_score = 0;
    int hi_player = 1;

    if (1 < this->player_num) {
        do {
            if (this->players[player]->computerPlayer() == 0) {
                if (this->players[player]->victory->get_victory_points_group((unsigned char)group) > high_score) {
                    high_score = this->players[player]->victory->get_victory_points_group((unsigned char)group);
                    hi_player = player;
                }
            }
            player++;
        } while (player < this->player_num);
    }

    info.score = high_score;
    info.civ = this->players[hi_player]->civ;
    strcpy(info.player_name, this->players[hi_player]->name);

    long count = 0;
    player = 1;
    if (1 < this->player_num) {
        do {
            if ((player != hi_player) &&
                (this->players[player]->relation(hi_player) == 0) &&
                (this->players[hi_player]->relation(player) == 0)) {
                count++;
            }
            player++;
        } while (player < this->player_num);
    }
    info.num_allies = (unsigned char)count;
}
