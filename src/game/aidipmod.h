#pragma once
#include "../common.h"

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0
    int dislikeTable[10];                    // 0xF4
    int likeTable[10];                       // 0x11C
    uchar changeableTable[10];               // 0x144

    DiplomacyAIModule(void* param_1, int param_2);
    DiplomacyAIModule(int param_1, int param_2);
    virtual ~DiplomacyAIModule();
    virtual void setMainDecisionAI(MainDecisionAIModule* param_1);
    virtual int update(int param_1);
    virtual int save(int param_1);
    virtual int stance(int param_1, int param_2);
    virtual void changeStance(int param_1, int param_2, int param_3);
    virtual void setStance(int param_1, int param_2, int param_3);
    virtual int isDisliked(int param_1);
    virtual int isAmbivalent(int param_1);
    virtual int isLiked(int param_1);
    virtual int isChangeable(int param_1);
    virtual void setChangeable(int param_1, uchar param_2);
    virtual int mostHated(int param_1, int param_2, int param_3, int param_4);
    virtual int mostLiked(int param_1, int param_2);
    virtual int isEnemy(int param_1);
    virtual int isNeutral(int param_1);
    virtual int isAlly(int param_1);
    virtual int isAlliedWithMe(int param_1);
    virtual void setRelation(int param_1, int param_2);
};

static_assert(sizeof(DiplomacyAIModule) == 0x150, "DiplomacyAIModule Size Mismatch");
static_assert(offsetof(DiplomacyAIModule, changeableTable) == 0x144, "DiplomacyAIModule Offset Mismatch");

