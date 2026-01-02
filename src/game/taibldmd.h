#pragma once
#include "../common.h"

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;           // 0x5BC

    TribeBuildAIModule(void* param_1, int param_2);
    TribeBuildAIModule(int param_1, int param_2);
    virtual ~TribeBuildAIModule();
    virtual void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    virtual int loadBuildList(char* param_1, RGE_Player* param_2);
    virtual void initialize();
    virtual void skipNextBuildListItem();
    virtual BuildItem* nextBuildableItem(int param_1);
    virtual int nextBuildListItemCategory();
    virtual int blockingResource();
    virtual int mostNeededResource(ResourceItem* param_1, int param_2);
    virtual int addItem(RGE_Static_Object* param_1, int param_2);
    virtual int addBuiltItem(RGE_Static_Object* param_1, int param_2);
    virtual int removeBuiltItem(int param_1);
    virtual int cancelBuildItem(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7);
    virtual int addTrainedUnit(int param_1, int param_2, int param_3, int param_4);
    virtual int cancelTrainUnit(int param_1, int param_2, int param_3, int param_4);
    virtual int addResearch(int param_1, int param_2, int param_3);
    virtual int cancelResearch(int param_1, int param_2, int param_3, int param_4);
    virtual int isAgeResearch(int param_1);
    virtual int insert(int param_1, int param_2, int param_3);
    virtual int insertResearch(int param_1, int param_2);
    virtual int insertGathererPercentage(int param_1, int param_2, int param_3);
    virtual int numberBuiltOrInProgressItemsOfType(int param_1, int param_2);
    virtual int allBuilt(int param_1, int param_2);
    virtual int readyToResearch(int param_1, int param_2);
    virtual void unskipBuildList(int param_1, int param_2);
    virtual BuildItem* buildItem(int param_1, int param_2, int param_3);
};

static_assert(sizeof(TribeBuildAIModule) == 0x5C0, "TribeBuildAIModule Size Mismatch");
static_assert(offsetof(TribeBuildAIModule, md) == 0x5BC, "TribeBuildAIModule Offset Mismatch");

