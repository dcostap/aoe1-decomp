#ifndef AOE1_AIDIPMOD_H
#define AOE1_AIDIPMOD_H

#include "aimdmod.h"

class DiplomacyAIModule : public AIModule {
public:
    virtual ~DiplomacyAIModule();
    virtual int save(int);
    virtual int update(int);

    DiplomacyAIModule(void*, int);
    DiplomacyAIModule(int, int);
    void setMainDecisionAI(MainDecisionAIModule*);
    int stance(int, int) const;
    void changeStance(int, int, int);
    void setStance(int, int, int);
    int isDisliked(int) const;
    int isAmbivalent(int) const;
    int isLiked(int) const;
    int isChangeable(int) const;
    void setChangeable(int, unsigned char);
    int mostHated(int, int, int, int) const;
    int mostLiked(int, int) const;
    int isEnemy(int) const;
    int isNeutral(int) const;
    int isAlly(int) const;
    int isAlliedWithMe(int) const;
    void setRelation(int, int);

    MainDecisionAIModule* md;
    int dislikeTable[10];
    int likeTable[10];
    unsigned char changeableTable[10];
};

typedef char aidipmod_diplomacy_ai_module_size[
    (sizeof(DiplomacyAIModule) == 0x150) ? 1 : -1];

#endif
