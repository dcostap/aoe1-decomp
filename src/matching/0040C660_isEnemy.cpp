class PlayerWorld {
public:
    char gap_00[0x3C];
    short player_num;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    PlayerWorld* world;
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

    int isEnemy(int player);
};

int DiplomacyAIModule::isEnemy(int player) {
    if (player > 0) {
        RGE_Player* pRVar1 = this->md->player;
        if (player <= pRVar1->world->player_num) {
            if (player != pRVar1->id) {
                if (pRVar1->relations[player] == 3) {
                    return 1;
                }
            }
        }
    }

    return 0;
}
