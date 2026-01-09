#pragma once
#include "common.h"

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;           // 0x5BC

    virtual int loadBuildList(char* param_1, RGE_Player* param_2); // vt0[17]+0x44=0x4D3B20
    virtual int numberBuiltOrInProgressItemsOfType(int param_1, int param_2); // vt0[18]+0x48=0x4D5BB0
    TribeBuildAIModule(void* param_1, int param_2);
    TribeBuildAIModule(int param_1, int param_2);
    ~TribeBuildAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    void initialize();
    void skipNextBuildListItem();
    BuildItem* nextBuildableItem(int param_1);
    int nextBuildListItemCategory();
    int blockingResource();
    int mostNeededResource(ResourceItem* param_1, int param_2);
    int addItem(RGE_Static_Object* param_1, int param_2);
    int addBuiltItem(RGE_Static_Object* param_1, int param_2);
    int removeBuiltItem(int param_1);
    int cancelBuildItem(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7);
    int addTrainedUnit(int param_1, int param_2, int param_3, int param_4);
    int cancelTrainUnit(int param_1, int param_2, int param_3, int param_4);
    int addResearch(int param_1, int param_2, int param_3);
    int cancelResearch(int param_1, int param_2, int param_3, int param_4);
    int isAgeResearch(int param_1);
    int insert(int param_1, int param_2, int param_3);
    int insertResearch(int param_1, int param_2);
    int insertGathererPercentage(int param_1, int param_2, int param_3);
    int allBuilt(int param_1, int param_2);
    int readyToResearch(int param_1, int param_2);
    void unskipBuildList(int param_1, int param_2);
    BuildItem* buildItem(int param_1, int param_2, int param_3);
};

static_assert(sizeof(TribeBuildAIModule) == 0x5C0, "TribeBuildAIModule Size Mismatch");

