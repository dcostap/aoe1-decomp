#ifndef AOE1_AIDIPMOD_H
#define AOE1_AIDIPMOD_H

#include "aimdmod.h"

class DiplomacyAIModule : public AIModule {
public:
    virtual ~DiplomacyAIModule();
    virtual int save(int outfile);
    virtual int update(int timeLimit);

    DiplomacyAIModule(void* pW, int playerID);
    DiplomacyAIModule(int playerID, int infile);
    void setMainDecisionAI(MainDecisionAIModule* m);
    int stance(int playerID, int likeType) const;
    void changeStance(int playerID, int likeType, int delta);
    void setStance(int playerID, int likeType, int value);
    int isDisliked(int playerID) const;
    int isAmbivalent(int playerID) const;
    int isLiked(int playerID) const;
    int isChangeable(int playerID) const;
    void setChangeable(int playerID, unsigned char v);
    int mostHated(int tributeOn, int tributePlayer, int attackWinningPlayer, int attackWinningPlayerFactor) const;
    int mostLiked(int tributeOn, int tributePlayer) const;
    int isEnemy(int playerID) const;
    int isNeutral(int playerID) const;
    int isAlly(int playerID) const;
    int isAlliedWithMe(int playerID) const;
    void setRelation(int playerID, int newRelation);

    MainDecisionAIModule* md;
    int dislikeTable[10];
    int likeTable[10];
    unsigned char changeableTable[10];
};

typedef char aidipmod_diplomacy_ai_module_size[
    (sizeof(DiplomacyAIModule) == 0x150) ? 1 : -1];

#endif
