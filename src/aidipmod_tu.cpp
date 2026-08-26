// Authentic aidipmod.cpp owner wrapper in PDB source order.
//
// PDB module: C:\\msdev\\work\\age1_x1\\aidipmod.cpp
// Owner line bands: 26, 40, 52, 58, 65, 98, 110, 144, 195, 245,
// 257, 266, 277, 287, 296, 338, 367, 383, 399, 418, and 432.
//
// The AIModule, player, and world surfaces come from the reviewed aiconmod
// context.  Owner files keep standalone declarations when built alone and
// suppress them for this wrapper.
// Candidate accounting: 18 exact, 3 observed (1 match, 2 mismatches),
// 1 compiler-generated match, and 0 blocked entries.
#include "../include/aiconmod_context.h"

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
};

class RGE_Victory_Conditions {
public:
    int get_victory_points();
};

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;         // +0xF0
    int dislikeTable[10];              // +0xF4
    int likeTable[10];                 // +0x11C
    unsigned char changeableTable[10]; // +0x144

    virtual ~DiplomacyAIModule();
    virtual int save(int file);
    virtual int update(int value);

    DiplomacyAIModule(void* param, int value);
    DiplomacyAIModule(int value, int file);
    void setMainDecisionAI(MainDecisionAIModule* value);
    int stance(int player_id, int type) const;
    void changeStance(int player, int type, int value);
    void setStance(int player, int type, int value);
    int isDisliked(int player) const;
    int isAmbivalent(int player) const;
    int isLiked(int player) const;
    int isChangeable(int player) const;
    void setChangeable(int index, unsigned char value);
    int mostHated(int param1, int param2, int param3, int param4) const;
    int mostLiked(int param1, int param2) const;
    int isEnemy(int player) const;
    int isNeutral(int player) const;
    int isAlly(int player) const;
    int isAlliedWithMe(int player) const;
    void setRelation(int player_id, int stance);
};

#define AOE1_AIDIPMOD_TU_CONTEXT 1
#include "matching/0040BEC0_DiplomacyAIModule.cpp"
#include "matching/0040BF40_DiplomacyAIModule.cpp"
#include "matching/0040BFF0_DiplomacyAIModule.cpp"
#include "matching/0040C000_setMainDecisionAI.cpp"
#include "matching/0040C010_update.cpp"
#include "matching/0040C0A0_save.cpp"
#include "matching/0040C100_stance.cpp"
#include "matching/0040C190_changeStance.cpp"
#include "matching/0040C2B0_setStance.cpp"
#include "matching/0040C3B0_isDisliked.cpp"
#include "matching/0040C3F0_isAmbivalent.cpp"
#include "matching/0040C420_isLiked.cpp"
#include "matching/0040C460_isChangeable.cpp"
#include "matching/0040C4A0_setChangeable.cpp"
#include "matching/0040C4D0_mostHated.cpp"
#include "accepted_drift/0040C5B0_mostLiked.cpp"
#include "matching/0040C660_isEnemy.cpp"
#include "matching/0040C6A0_isNeutral.cpp"
#include "matching/0040C6E0_isAlly.cpp"
#include "matching/0040C730_isAlliedWithMe.cpp"
#include "matching/0040C780_setRelation.cpp"
#undef AOE1_AIDIPMOD_TU_CONTEXT
