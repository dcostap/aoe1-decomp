class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x36];
    unsigned char* relations;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class DiplomacyAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;

    int isNeutral(int player) const;
};

int DiplomacyAIModule::isNeutral(int player) const {
    RGE_Player* pVar1;

    if (((0 < player) && (pVar1 = this->md->player, player <= pVar1->world->player_num)) &&
        (player != pVar1->id) && (pVar1->relations[player] == 1)) {
        return 1;
    }
    return 0;
}
