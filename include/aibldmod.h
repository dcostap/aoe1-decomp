#ifndef AOE1_AIBLDMOD_H
#define AOE1_AIBLDMOD_H

#include "aibitm.h"
#include "aiblditm.h"
#include "aimodule.h"
#include "m_s_obj.h"
#include "player.h"
#include "rge_fio.h"
#include "utmarray.h"
#include "stat_obj.h"

extern float save_game_version;

class BuildAIModule : public AIModule {
  public:
    // AIModule supplies slots 0-14. These four methods supply slots 15-18.
    virtual ~BuildAIModule();
    virtual int save(int outfile);
    virtual void displayBuildList();
    virtual int loadBuildList(char* lName, RGE_Player* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int category);

    BuildItem buildList;                        // +0x0F0
    int buildListLengthValue;                   // +0x1A0
    char buildListNameValue[0x101];             // +0x1A4
    char lastBuildItemRequestedValue[0x101];    // +0x2A5
    char currentBuildItemRequestedValue[0x101]; // +0x3A6
    char nextBuildItemRequestedValue[0x101];    // +0x4A7
    int numberItemsIntoBuildListValue;          // +0x5A8
    ManagedArray<int> typesToIgnore;            // +0x5AC

    BuildAIModule(void* pW, int playerID);
    BuildAIModule(int playerID, int infile);

    int buildListLength() const;
    char* buildListName();
    int haveBuildList() const;
    int insertItem(
        RGE_Player* player, int typeID, int quantity, int buildCategory, int buildFrom, int buildCap,
        int insertAfterItemNumber
    );
    int numberItemsBuilt() const;
    int numberItemsInProgress() const;
    int numberItemsBuiltOrInProgress() const;
    int numberItemsIntoBuildList() const;
    char* lastBuildItemRequested() const;
    char* currentBuildItemRequested() const;
    char* nextBuildItemRequested() const;
    int numberItemsOfType(int type, int category);
    int numberBuiltItemsOfType(int type, int category);
    int numberUnbuiltItemsOfType(int type, int category);
    int numberInProgressItemsOfType(int type, int category);

  protected:
    void removeOldList();
    BuildItem* anyBuildListItem(int id, int checkBuilt, int buildStatus);
    BuildItem* specificBuildListItem(int id);
};

typedef char aibldmod_module_size[(sizeof(BuildAIModule) == 0x5BC) ? 1 : -1];

#endif // AOE1_AIBLDMOD_H
