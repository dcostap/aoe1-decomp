#pragma once
#include "common.h"
#include "MainDecisionAIModule.h"

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeMainDecisionAIModule(void* param_1, int player_number, char* player_name, TRIBE_Player* player, char* ai1, char* ai2, char* ai3);
    TribeMainDecisionAIModule(int player_number, char* player_name, TRIBE_Player* player, int fd);

    // Virtuals (best-effort)
    virtual ~TribeMainDecisionAIModule(); // vt[0] (0x0)
    virtual int loggingHistory(); // vt[1] (0x4)
    virtual void setLogHistory(int param_1); // vt[2] (0x8)
    virtual void toggleLogHistory(); // vt[3] (0xC)
    virtual void setHistoryFilename(char* param_1); // vt[4] (0x10)
    virtual int loggingCommonHistory(); // vt[5] (0x14)
    virtual void setLogCommonHistory(int param_1); // vt[6] (0x18)
    virtual void toggleLogCommonHistory(); // vt[7] (0x1C)
    virtual int loadState(char* param_1); // vt[8] (0x20)
    virtual int saveState(char* param_1); // vt[9] (0x24)
    virtual int gleanState(int param_1); // vt[10] (0x28)
    virtual int processMessage(AIModuleMessage* param_1); // vt[11] (0x2C)
    virtual int update(int param_1); // vt[12] (0x30)
    virtual void setCallbackMessage(AIModuleMessage* param_1); // vt[13] (0x34)
    virtual int filterOutMessage(AIModuleMessage* param_1); // vt[14] (0x38)
    virtual int save(int param_1); // vt[15] (0x3C)
    virtual int addObject(RGE_Static_Object* param_1); // vt[16] (0x40)
    virtual int removeObject(int param_1); // vt[17] (0x44)
    virtual int objectGroupThatCanPerformAction(int param_1); // vt[18] (0x48)
    virtual int canPerformAction(int param_1, int param_2); // vt[19] (0x4C)

    // Opaque storage: these embedded AI modules are not transliterated yet, but must exist at the
    // correct offsets for `TribeMainDecisionAIModule` layout/vtable parity.
    alignas(4) unsigned char buildAI[0x5C0];
    alignas(4) unsigned char constructionAI[0x318];
    alignas(4) unsigned char diplomacyAI[0x150];
    alignas(4) unsigned char emotionalAI[0x1C0];
    alignas(4) unsigned char informationAI[0x10090];
    alignas(4) unsigned char resourceAI[0xF8];
    alignas(4) unsigned char strategyAI[0x5F8];
    alignas(4) unsigned char tacticalAI[0x100C];
    alignas(4) unsigned char tradeAI[0xF4];
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
};
static_assert(sizeof(TribeMainDecisionAIModule) == 0x125C8, "Size mismatch");
