#ifndef AOE1_AIDIPMOD_TU_CONTEXT
struct DiplomacyWorld {
    char gap_00[0x3C];
    short player_num;
};

struct DiplomacyPlayer {
    char gap_00[0x3C];
    DiplomacyWorld* world;
};

struct DiplomacyMD {
    char gap_00[0xF0];
    DiplomacyPlayer* player;
};

class DiplomacyAIModule {
public:
    char gap_00[0xF0];
    DiplomacyMD* md;
    char gap_F4[0x50];
    unsigned char changeableTable[256];

void setChangeable(int index, unsigned char value);
};
#endif

void DiplomacyAIModule::setChangeable(int index, unsigned char value) {
    if (index > 0 && index < this->md->player->world->player_num) {
        this->changeableTable[index] = value;
    }
}
