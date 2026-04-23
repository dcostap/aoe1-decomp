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
    char gap_F4[0x50];
    unsigned char changeableTable[10];

    int isChangeable(int player) const;
};

int DiplomacyAIModule::isChangeable(int player) const {
    if (((player > 0) && (player < this->md->player->world->player_num)) && (this->changeableTable[player] == 1)) {
        return 1;
    }
    return 0;
}
