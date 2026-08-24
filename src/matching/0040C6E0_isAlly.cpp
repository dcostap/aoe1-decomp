#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0xA];
    short id;
    char gap_4C[0x38];
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

    int isAlly(int param_1) const;
};
#endif

int DiplomacyAIModule::isAlly(int param_1) const {
    if (param_1 == this->md->player->id) {
        return 1;
    }

    if (param_1 > 0 && param_1 <= this->md->player->world->player_num
        && this->md->player->relations[param_1] == 0) {
        return 1;
    }

    return 0;
}
