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

class TribeMainDecisionAIModule : public MainDecisionAIModule       {
public:
    char _pad_0x4[0x100];
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeMainDecisionAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 02] Offset 0x08 (Override)
    virtual void setLogHistory(int param_1); // Ghidra: setLogHistory

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 12] Offset 0x30 (Override)
    virtual int update(int param_1); // Ghidra: update

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // [Slot 15] Offset 0x3C (Override)
    virtual int save(int param_1); // Ghidra: save

    // [Slot 16] Offset 0x40 (Override)
    virtual int addObject(RGE_Static_Object* param_1); // Ghidra: addObject

    // [Slot 17] Offset 0x44 (Override)
    virtual int removeObject(int param_1); // Ghidra: removeObject

    // [Slot 18] Offset 0x48 (Override)
    virtual int objectGroupThatCanPerformAction(int param_1); // Ghidra: objectGroupThatCanPerformAction

    // [Slot 19] Offset 0x4C (Override)
    virtual int canPerformAction(int param_1, int param_2); // Ghidra: canPerformAction

    // --- Non-Virtual Members ---
    void kick(int param_1);
    void detask(int param_1);
    int isMoveable(int param_1);
    void updateBuildAIWithObjects();
    void tributeNotify(int param_1, int param_2, int param_3);
    void revokeTributeAlliance();
    void setTributeChat();
    int processAICommand(int param_1, int param_2, int param_3, int param_4, int param_5);
    int currentScore(int param_1);
};

static_assert(sizeof(TribeMainDecisionAIModule) == 0x125C8, "TribeMainDecisionAIModule Size Mismatch");
static_assert(offsetof(TribeMainDecisionAIModule, tributeGiven) == 0x125A4, "TribeMainDecisionAIModule Offset Mismatch");

