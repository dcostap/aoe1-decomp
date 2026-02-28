#pragma once
#include "common.h"
#include "BuildAIModule.h"

class ResourceItem;

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeBuildAIModule(void* param_1, int param_2);
    TribeBuildAIModule(int param_1, int param_2);

    // Virtuals (best-effort)
    virtual ~TribeBuildAIModule(); // vt[0] (0x0)
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

    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int addBuiltItem(RGE_Static_Object* param_1, int param_2);
    int cancelBuildItem(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7);
    int addTrainedUnit(int param_1, int param_2, int param_3, int param_4);
    int cancelTrainUnit(int param_1, int param_2, int param_3, int param_4);
    int addResearch(int param_1, int param_2, int param_3);
    int cancelResearch(int param_1, int param_2, int param_3, int param_4);
    void initialize();
    void skipNextBuildListItem();
    BuildItem* nextBuildableItem(int param_1);
    int nextBuildListItemCategory();
    int blockingResource();
    int mostNeededResource(ResourceItem* param_1, int param_2);
    int addItem(RGE_Static_Object* param_1, int param_2);
    int removeBuiltItem(int param_1);
    int isAgeResearch(int param_1);
    int insert(int param_1, int param_2, int param_3);
    int insertResearch(int param_1, int param_2);
    int insertGathererPercentage(int param_1, int param_2, int param_3);
    int allBuilt(int param_1, int param_2);
    int readyToResearch(int param_1, int param_2);
    void unskipBuildList(int param_1, int param_2);
    BuildItem* buildItem(int param_1, int param_2, int param_3);

    TribeMainDecisionAIModule* md;
};
static_assert(sizeof(TribeBuildAIModule) == 0x5C0, "Size mismatch");
