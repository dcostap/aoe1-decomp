// VA: 005120F0 TRIBE_Player::~TRIBE_Player
// tplayer.cpp:333-351
// FLAGS: /GX

#include <stdlib.h>

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Player {
public:
    virtual ~RGE_Player();
};

class TRIBE_Player_Tech {
public:
    ~TRIBE_Player_Tech();
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
};

class TRIBE_History_Info {
public:
    ~TRIBE_History_Info();
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_004[0x21C];
    TRIBE_Player_Tech* tech_tree;   // +0x220
    char gap_224[0x14];
    TribeMainDecisionAIModule* playerAI; // +0x238
    char gap_23C[0x600];
    TRIBE_History_Info* history; // +0x83C

    virtual ~TRIBE_Player();
};
#endif

TRIBE_Player::~TRIBE_Player()
{
    if (tech_tree != 0) {
        delete tech_tree;
        tech_tree = 0;
    }

    if (playerAI != 0) {
        delete playerAI;
        playerAI = 0;
    }

    if (history != 0) {
        delete history;
        history = 0;
    }
}
