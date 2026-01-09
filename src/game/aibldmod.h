#pragma once
#include "common.h"

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

    virtual int save(int param_1);                          // vt0[15]+0x3C=0x408DF0
    virtual void displayBuildList();                        // vt0[16]+0x40=0x4092F0
    virtual int loadBuildList(char* param_1, RGE_Player* param_2); // vt0[17]+0x44=0x409430
    virtual int numberBuiltOrInProgressItemsOfType(int param_1, int param_2); // vt0[18]+0x48=0x409DB0
    BuildAIModule(void* param_1, int param_2);
    BuildAIModule(int param_1, int param_2);
    ~BuildAIModule();
    int buildListLength();
    char* buildListName();
    int haveBuildList();
    int insertItem(RGE_Player* param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    int numberItemsBuilt();
    int numberItemsInProgress();
    int numberItemsBuiltOrInProgress();
    int numberItemsIntoBuildList();
    char* lastBuildItemRequested();
    char* currentBuildItemRequested();
    char* nextBuildItemRequested();
    int numberItemsOfType(int param_1, int param_2);
    int numberBuiltItemsOfType(int param_1, int param_2);
    int numberUnbuiltItemsOfType(int param_1, int param_2);
    int numberInProgressItemsOfType(int param_1, int param_2);
    void removeOldList();
    BuildItem* anyBuildListItem(int param_1, int param_2, int param_3);
    BuildItem* specificBuildListItem(int param_1);
};

static_assert(sizeof(BuildAIModule) == 0x5BC, "BuildAIModule Size Mismatch");

