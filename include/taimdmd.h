#ifndef AOE1_TAIMDMD_H
#define AOE1_TAIMDMD_H


#include "aimdmod.h"
#include "aidipmod.h"
#include "aiemomod.h"
#include "aitrdmod.h"
#include "taibldmd.h"
#include "taiconmd.h"
#include "taiinfmd.h"
#include "tairesmd.h"
#include "taistrmd.h"
#include "taitacmd.h"

class TribeMainDecisionAIModule;
class TRIBE_Player;

typedef char taimdmd_information_size[
    (sizeof(TribeInformationAIModule) == 0x10090) ? 1 : -1];
typedef char taimdmd_strategy_size[
    (sizeof(TribeStrategyAIModule) == 0x5F8) ? 1 : -1];

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
    TribeTacticalAIModule tacticalAI;
    TradeAIModule tradeAI;

    TRIBE_Player* aiPlayer;
    int firstUpdate;
    int veryFirstUpdate;
    int updateDelay;
    unsigned long lastDiplomacyUpdateTime;
    unsigned long lastTacticalUpdateTime;
    unsigned long lastTributeChatTime;
    unsigned long tributeChatTimeout;
    int waitingOnTribute;
    int tributeExpirationTimeout;
    int tributeAddressed;
    int tributeAmount;
    int decidedInitialDiplomacy;
    int requiredDiplomacyTributeAmount;
    int tributeGiven[9];

    TribeMainDecisionAIModule(void* pW, int playerID, char* playerName,
                              TRIBE_Player* aiP, char* buildListName,
                              char* cityPlanName, char* ruleSetName);
    TribeMainDecisionAIModule(int playerID, char* playerName,
                              TRIBE_Player* aiP, int infile);
    virtual ~TribeMainDecisionAIModule();
    virtual void setLogHistory(int v);
    virtual int update(int timeLimit);
    virtual int save(int outfile);
    virtual int addObject(RGE_Static_Object* bo);
    virtual int removeObject(int id);
    virtual int objectGroupThatCanPerformAction(int a);
    virtual int canPerformAction(int id, int a);

    void kick(int m);
    int isMoveable(int o);
    void updateBuildAIWithObjects();
    void tributeNotify(int playerID, int resourceID, int amount);
    void revokeTributeAlliance();

protected:
    void setTributeChat();

public:
    int processAICommand(int caller, int mType, int p1, int p2, int p3);
    int currentScore(int playerID);
    void detask(int uID);
};

typedef char taimdmd_tribe_main_size[
    (sizeof(TribeMainDecisionAIModule) == 0x125C8) ? 1 : -1];

#endif  // AOE1_TAIMDMD_H
