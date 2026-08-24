// 0040C4D0 DiplomacyAIModule::mostHated
// Source: aidipmod.cpp lines 296-333
// Size: 222 bytes
//
// Attempt log:
// (fresh claim sa-0ea2a8b5-r1; cluster: aidipmod.cpp sibling of mostLiked/update/isAlly)

#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class RGE_Victory_Conditions {
public:
    int get_victory_points();
};

class RGE_Player;
class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x2];
    RGE_Player** players;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class DiplomacyAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;          // +0xF0
    int dislikeTable[10];              // +0xF4
    int likeTable[10];                 // +0x11C
    unsigned char changeableTable[10]; // +0x144

int mostHated(int param1, int param2, int param3, int param4) const;
    int isAlly(int id) const;
};

class RGE_Player {
public:
    char gap_00[0x34];
    RGE_Victory_Conditions* victory_conditions;  // +0x34
    char gap_38[0x4];
    RGE_Game_World* world;   // +0x3C
    char gap_40[0xA];
    short id;                // +0x4A
    char gap_4C[0x34];
    unsigned char game_status;  // +0x80
};
#endif

int DiplomacyAIModule::mostHated(int param1, int param2, int param3, int param4) const
{
    int result = -1;
    int highest = -1;
    for (int i = 1; i < this->md->player->world->player_num; ++i) {
        if (i != this->md->player->id
            && this->md->player->world->players[i]->game_status != 2
            && (param1 <= 0 || param2 != i || !isAlly(i))) {
            int vp = this->md->player->world->players[i]->victory_conditions->get_victory_points();
            int value = this->dislikeTable[i];
            if (param4 > 1) {
                if (param3 == 1) {
                    value += vp / param4;
                } else {
                    value -= vp / param4;
                }
            }
            if (value > highest) {
                result = i;
                highest = value;
            }
        }
    }
    return result;
}
