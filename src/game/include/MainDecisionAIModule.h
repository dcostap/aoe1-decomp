#pragma once
#include "common.h"

class MainDecisionAIModule {
public:
    // Virtuals (best-effort)
    virtual ~MainDecisionAIModule(); // vt[0] (0x0)
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

    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    RGE_Player* player;
    ManagedArray<int> objects;
};
static_assert(sizeof(MainDecisionAIModule) == 0x104, "Size mismatch");
