#pragma once
#include "../common.h"
#include "taibldmd.h"
#include "aimdmod.h"
#include "aimodule.h"
#include "player.h"
#include "utmarray.h"
#include "aibldmod.h"
#include "aiconmod.h"
#include "aidipmod.h"
#include "aiemomod.h"
#include "aiinfmod.h"
#include "aimdmod.h"
#include "airchmod.h"
#include "airesmod.h"
#include "aistrmod.h"
#include "aitacmod.h"
#include "aitrdmod.h"
#include "aiuaimod.h"
#include "taiconmd.h"
#include "taiinfmd.h"
#include "tairesmd.h"
#include "taistrmd.h"
#include "taitacmd.h"
#include "tplayer.h"

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;              // 0x104
    TribeConstructionAIModule constructionAI; // 0x6C4
    DiplomacyAIModule diplomacyAI;           // 0x9DC
    EmotionalAIModule emotionalAI;           // 0xB2C
    TribeInformationAIModule informationAI;  // 0xCEC
    TribeResourceAIModule resourceAI;        // 0x10D7C
    TribeStrategyAIModule strategyAI;        // 0x10E74
    TribeTacticalAIModule tacticalAI;        // 0x1146C
    TradeAIModule tradeAI;                   // 0x12478
    TRIBE_Player* aiPlayer;                  // 0x1256C
    int firstUpdate;                         // 0x12570
    int veryFirstUpdate;                     // 0x12574
    int updateDelay;                         // 0x12578
    ulong lastDiplomacyUpdateTime;           // 0x1257C
    ulong lastTacticalUpdateTime;            // 0x12580
    ulong lastTributeChatTime;               // 0x12584
    ulong tributeChatTimeout;                // 0x12588
    int waitingOnTribute;                    // 0x1258C
    int tributeExpirationTimeout;            // 0x12590
    int tributeAddressed;                    // 0x12594
    int tributeAmount;                       // 0x12598
    int decidedInitialDiplomacy;             // 0x1259C
    int requiredDiplomacyTributeAmount;      // 0x125A0
    int tributeGiven[9];                     // 0x125A4

    TribeMainDecisionAIModule(void* param_1, int param_2, char* param_3, TRIBE_Player* param_4, char* param_5, char* param_6, char* param_7);
    TribeMainDecisionAIModule(int param_1, char* param_2, TRIBE_Player* param_3, int param_4);
    virtual ~TribeMainDecisionAIModule();
    virtual void setLogHistory(int param_1);
    virtual int update(int param_1);
    virtual int save(int param_1);
    virtual void kick(int param_1);
    virtual int addObject(RGE_Static_Object* param_1);
    virtual int removeObject(int param_1);
    virtual int objectGroupThatCanPerformAction(int param_1);
    virtual int canPerformAction(int param_1, int param_2);
    virtual void detask(int param_1);
    virtual int isMoveable(int param_1);
    virtual void updateBuildAIWithObjects();
    virtual void tributeNotify(int param_1, int param_2, int param_3);
    virtual void revokeTributeAlliance();
    virtual void setTributeChat();
    virtual int processAICommand(int param_1, int param_2, int param_3, int param_4, int param_5);
    virtual int currentScore(int param_1);
};

static_assert(sizeof(TribeMainDecisionAIModule) == 0x125C8, "TribeMainDecisionAIModule Size Mismatch");
static_assert(offsetof(TribeMainDecisionAIModule, tributeGiven) == 0x125A4, "TribeMainDecisionAIModule Offset Mismatch");

