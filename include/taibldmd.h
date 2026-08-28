#ifndef AOE1_TAIBLDMD_H
#define AOE1_TAIBLDMD_H

// Canonical declarations for the original taibldmd.cpp source module.
// BuildAIModule owns the complete base through offset 0x5BC.

#include "aibldmod.h"
#include "airesitm.h"

class RGE_Static_Object;
class TribeMainDecisionAIModule;
class ConstructionItem;

class TribeBuildAIModule : public BuildAIModule {
public:
    // PDB: the only TribeBuildAIModule data member is the main-decision
    // pointer at +0x5BC.
    TribeMainDecisionAIModule* md;

    TribeBuildAIModule(void* owner, int player);
    TribeBuildAIModule(int file, int player);
    virtual ~TribeBuildAIModule();
    virtual int loadBuildList(char* filename, RGE_Player* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int category);

    void setMainDecisionAI(TribeMainDecisionAIModule* value);
    void initialize();
    void skipNextBuildListItem();
    BuildItem* nextBuildableItem(int category);
    int nextBuildListItemCategory();
    int blockingResource();
    int mostNeededResource(ResourceItem& item, int maxCount);
    int isAgeResearch(int type);
    int insert(int type, int count, int index);
    int insertResearch(int research, int index);
    int insertGathererPercentage(int index, int percentage, int bronzeAgeIndex);
    int addItem(RGE_Static_Object* object, int flag);
    int addBuiltItem(RGE_Static_Object* object, int id);
    int removeBuiltItem(int id);
    int cancelBuildItem(int action, int objectID, int objectTypeID,
                        float x, float y, int uniqueBuildID, int taskID);
    int addTrainedUnit(int param1, int param2, int param3, int param4);
    int cancelTrainUnit(int param1, int param2, int param3, int param4);
    int addResearch(int param1, int param2, int param3);
    int cancelResearch(int param1, int param2, int param3, int param4);
    int readyToResearch(int param1, int param2);
    void unskipBuildList(int limit67, int limit44);
    BuildItem* buildItem(int type, int category1, int category2);
    int allBuilt(int param1, int param2);
};

typedef char taibldmd_tribe_build_size[
    (sizeof(TribeBuildAIModule) == 0x5C0) ? 1 : -1];

#endif  // AOE1_TAIBLDMD_H
