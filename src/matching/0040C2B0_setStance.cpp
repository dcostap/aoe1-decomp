// 0040C2B0 DiplomacyAIModule::setStance
// Source: aidipmod.cpp lines 195-240
// Size: 252 bytes
//
// Attempt log:
// Baseline candidate: natural guarded switch with per-table clamps.
// Probe 2: put the changeable (0..100) arm first; original cmp/je targets the
// non-changeable arm while keeping the changeable arm inline.

#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class DiplomacyWorld {
public:
    virtual ~DiplomacyWorld();
    char gap_04[0x38];
    short player_num;
};

class DiplomacyPlayer {
public:
    virtual ~DiplomacyPlayer();
    char gap_04[0x38];
    DiplomacyWorld* world;
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    DiplomacyPlayer* player;
};

class AIModule {
public:
    virtual ~AIModule();
    virtual void dummy1();
    char gap_04[0xEC];
};

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;            // +0xF0
    int dislikeTable[10];                // +0xF4
    int likeTable[10];                   // +0x11C
    unsigned char changeableTable[10];   // +0x144

void setStance(int player, int type, int value);
};
#endif

void DiplomacyAIModule::setStance(int player, int type, int value)
{
    if (player > 0 && player < this->md->player->world->player_num) {
        switch (type) {
        case 0:
            this->dislikeTable[player] = value;
            if (this->changeableTable[player] != 0) {
                if (value < 0) {
                    this->dislikeTable[player] = 0;
                    return;
                }
                if (value > 100) {
                    this->dislikeTable[player] = 100;
                    return;
                }
            } else {
                if (value < 50) {
                    this->dislikeTable[player] = 50;
                    return;
                }
                if (value > 100) {
                    this->dislikeTable[player] = 100;
                }
            }
            break;

        case 2:
            this->likeTable[player] = value;
            if (this->changeableTable[player] != 0) {
                if (value < 0) {
                    this->likeTable[player] = 0;
                    return;
                }
                if (value > 100) {
                    this->likeTable[player] = 100;
                    return;
                }
            } else {
                if (value < 0) {
                    this->likeTable[player] = 0;
                    return;
                }
                if (value > 48) {
                    this->likeTable[player] = 48;
                    return;
                }
            }
            break;
        }
    }
}
