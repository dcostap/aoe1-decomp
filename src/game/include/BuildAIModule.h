#pragma once
#include "common.h"

class BuildAIModule {
public:
    // Virtuals (best-effort)
    virtual ~BuildAIModule(); // vt[0] (0x0)
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
    virtual void displayBuildList(); // vt[16] (0x40)
    virtual int loadBuildList(char* param_1, RGE_Player* param_2); // vt[17] (0x44)
    virtual int numberBuiltOrInProgressItemsOfType(int param_1, int param_2); // vt[18] (0x48)

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
    BuildItem buildList;
    int buildListLengthValue;
    char buildListNameValue[257];
    char lastBuildItemRequestedValue[257];
    char currentBuildItemRequestedValue[257];
    char nextBuildItemRequestedValue[257];
    int numberItemsIntoBuildListValue;
    ManagedArray<int> typesToIgnore;
};
static_assert(sizeof(BuildAIModule) == 0x5BC, "Size mismatch");
