// 0040C190 DiplomacyAIModule::changeStance
// Source: aidipmod.cpp lines 144-189
// Size: 283 bytes
//
// Attempt log:
// Probe 1: 80/283B — structural probe, too short
//   ChangeStance is more complex than simple clamp (has player chain, weighted calc)
// Baseline candidate: natural guarded switch with in-place table adjustments and clamps.

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

void changeStance(int player, int type, int value);
};
#endif

void DiplomacyAIModule::changeStance(int player, int type, int value)
{
    if (player > 0 && player < this->md->player->world->player_num) {
        switch (type) {
        case 0:
            this->dislikeTable[player] += value;
            if (this->changeableTable[player] != 0) {
                if (this->dislikeTable[player] < 0) {
                    this->dislikeTable[player] = 0;
                    return;
                }
                if (this->dislikeTable[player] > 100) {
                    this->dislikeTable[player] = 100;
                    return;
                }
            } else {
                if (this->dislikeTable[player] < 50) {
                    this->dislikeTable[player] = 50;
                    return;
                }
                if (this->dislikeTable[player] > 100) {
                    this->dislikeTable[player] = 100;
                }
            }
            break;

        case 2:
            this->likeTable[player] += value;
            if (this->changeableTable[player] != 0) {
                if (this->likeTable[player] < 0) {
                    this->likeTable[player] = 0;
                    return;
                }
                if (this->likeTable[player] > 100) {
                    this->likeTable[player] = 100;
                    return;
                }
            } else {
                if (this->likeTable[player] < 0) {
                    this->likeTable[player] = 0;
                    return;
                }
                if (this->likeTable[player] > 48) {
                    this->likeTable[player] = 48;
                    return;
                }
            }
            break;
        }
    }
}
