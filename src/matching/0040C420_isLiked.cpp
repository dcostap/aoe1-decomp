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
    char gap_F4[0x28];
    int likeTable[10];

    int isLiked(int player) const;
};

int DiplomacyAIModule::isLiked(int player) const {
    if (((player > 0) && (player < this->md->player->world->player_num)) && (this->likeTable[player] > 0x31)) {
        return 1;
    }
    return 0;
}
