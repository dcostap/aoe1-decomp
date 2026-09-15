#ifndef AOE1_TAIBLDMD_H
#define AOE1_TAIBLDMD_H

// BuildAIModule owns the complete base through offset 0x5BC.

#include "aibldmod.h"
#include "airesitm.h"

class RGE_Static_Object;
class TribeMainDecisionAIModule;
class ConstructionItem;

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeBuildAIModule(void* pW, int pID);
    TribeBuildAIModule(int pID, int infile);
    virtual ~TribeBuildAIModule();
    virtual int loadBuildList(char* lName, RGE_Player* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int category);

    void setMainDecisionAI(TribeMainDecisionAIModule* m);
    void initialize();
    void skipNextBuildListItem();
    BuildItem* nextBuildableItem(int category);
    int nextBuildListItemCategory();
    int blockingResource();
    int mostNeededResource(ResourceItem& itemCost, int countNum);
    int isAgeResearch(int rID);
    int insert(int typeID, int buildCap, int insertionPoint);
    int insertResearch(int typeID, int insertionPoint);
    int insertGathererPercentage(int rType, int percentage, int insertionPoint);
    int addItem(RGE_Static_Object* newItem, int gameStarted);
    int addBuiltItem(RGE_Static_Object* newItem, int buildID);
    int removeBuiltItem(int id);
    int cancelBuildItem(int reason, int blockerID, int blockerType, float x, float y, int uniqueID, int builderID);
    int addTrainedUnit(int uType, int location, int uniqueID, int gameID);
    int cancelTrainUnit(int reason, int uType, int location, int uniqueID);
    int addResearch(int uType, int location, int uniqueID);
    int cancelResearch(int reason, int rType, int location, int uniqueID);
    int readyToResearch(int id, int ageResearch);
    void unskipBuildList(int builtSP, int builtG);
    BuildItem* buildItem(int typeID, int category1, int category2);
    int allBuilt(int category1, int category2);

protected:
    // pointer at +0x5BC.
    TribeMainDecisionAIModule* md;
};

typedef char taibldmd_tribe_build_size[
    (sizeof(TribeBuildAIModule) == 0x5C0) ? 1 : -1];

#endif  // AOE1_TAIBLDMD_H
