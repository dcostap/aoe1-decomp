#ifndef AOE1_TAIMDMD_H
#define AOE1_TAIMDMD_H

// Canonical declarations for the original taimdmd.cpp source module.
// The embedded module order follows the PDB layout through 0x125C8.

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

    TribeMainDecisionAIModule(void* owner, int player, char* playerName,
                              TRIBE_Player* tribePlayer, char* p5, char* p6,
                              char* p7);
    TribeMainDecisionAIModule(int player, char* playerName,
                              TRIBE_Player* tribePlayer, int file);
    virtual ~TribeMainDecisionAIModule();
    virtual void setLogHistory(int value);
    virtual int update(int value);
    virtual int save(int file);
    virtual int addObject(RGE_Static_Object* object);
    virtual int removeObject(int objectID);
    virtual int objectGroupThatCanPerformAction(int action);
    virtual int canPerformAction(int action, int target);

    void kick(int player);
    int isMoveable(int objectID);
    void updateBuildAIWithObjects();
    void tributeNotify(int player, int notification, int amount);
    void revokeTributeAlliance();

protected:
    void setTributeChat();

public:
    int processAICommand(int player, int command, int value, int amount,
                         int extra);
    int currentScore(int player);
    void detask(int objectID);
};

typedef char taimdmd_tribe_main_size[
    (sizeof(TribeMainDecisionAIModule) == 0x125C8) ? 1 : -1];

#endif  // AOE1_TAIMDMD_H
