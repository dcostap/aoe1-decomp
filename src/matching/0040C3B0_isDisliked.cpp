#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class WorldStub {
public:
    char gap_00[0x3C];
    short player_num;
};

class PlayerStub {
public:
    char gap_00[0x3C];
    WorldStub* world;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    PlayerStub* player;
};

class DiplomacyAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;
    int dislikeTable[10];

int isDisliked(int player) const;
};
#endif

int DiplomacyAIModule::isDisliked(int player) const {
    if (((player > 0) && (player < this->md->player->world->player_num)) && (this->dislikeTable[player] > 0x31)) {
        return 1;
    }
    return 0;
}
