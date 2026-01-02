#pragma once
#include "../common.h"

class BuildAIModule : public AIModule {
public:
    BuildItem buildList;                     // 0xF0
    int buildListLengthValue;                // 0x1A0
    char buildListNameValue[257];            // 0x1A4
    char lastBuildItemRequestedValue[257];   // 0x2A5
    char currentBuildItemRequestedValue[257]; // 0x3A6
    char nextBuildItemRequestedValue[257];   // 0x4A7
    int numberItemsIntoBuildListValue;       // 0x5A8
    ManagedArray<int> typesToIgnore;         // 0x5AC

    BuildAIModule(void* param_1, int param_2);
    BuildAIModule(int param_1, int param_2);
    virtual ~BuildAIModule();
    virtual int save(int param_1);
    virtual void displayBuildList();
    virtual int loadBuildList(char* param_1, RGE_Player* param_2);
    virtual int buildListLength();
    virtual char* buildListName();
    virtual int haveBuildList();
    virtual int insertItem(RGE_Player* param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    virtual int numberItemsBuilt();
    virtual int numberItemsInProgress();
    virtual int numberItemsBuiltOrInProgress();
    virtual int numberItemsIntoBuildList();
    virtual char* lastBuildItemRequested();
    virtual char* currentBuildItemRequested();
    virtual char* nextBuildItemRequested();
    virtual int numberItemsOfType(int param_1, int param_2);
    virtual int numberBuiltItemsOfType(int param_1, int param_2);
    virtual int numberUnbuiltItemsOfType(int param_1, int param_2);
    virtual int numberBuiltOrInProgressItemsOfType(int param_1, int param_2);
    virtual int numberInProgressItemsOfType(int param_1, int param_2);
    virtual void removeOldList();
    virtual BuildItem* anyBuildListItem(int param_1, int param_2, int param_3);
    virtual BuildItem* specificBuildListItem(int param_1);
};

static_assert(sizeof(BuildAIModule) == 0x5BC, "BuildAIModule Size Mismatch");
static_assert(offsetof(BuildAIModule, typesToIgnore) == 0x5AC, "BuildAIModule Offset Mismatch");

