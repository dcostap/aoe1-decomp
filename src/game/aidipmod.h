#pragma once
#include "common.h"

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0
    int dislikeTable[10];                    // 0xF4
    int likeTable[10];                       // 0x11C
    uchar changeableTable[10];               // 0x144

    virtual int update(int param_1);                        // vt0[12]+0x30=0x40C010
    virtual int save(int param_1);                          // vt0[15]+0x3C=0x40C0A0
    DiplomacyAIModule(void* param_1, int param_2);
    DiplomacyAIModule(int param_1, int param_2);
    ~DiplomacyAIModule();
    void setMainDecisionAI(MainDecisionAIModule* param_1);
    int stance(int param_1, int param_2);
    void changeStance(int param_1, int param_2, int param_3);
    void setStance(int param_1, int param_2, int param_3);
    int isDisliked(int param_1);
    int isAmbivalent(int param_1);
    int isLiked(int param_1);
    int isChangeable(int param_1);
    void setChangeable(int param_1, uchar param_2);
    int mostHated(int param_1, int param_2, int param_3, int param_4);
    int mostLiked(int param_1, int param_2);
    int isEnemy(int param_1);
    int isNeutral(int param_1);
    int isAlly(int param_1);
    int isAlliedWithMe(int param_1);
    void setRelation(int param_1, int param_2);
};

static_assert(sizeof(DiplomacyAIModule) == 0x150, "DiplomacyAIModule Size Mismatch");

