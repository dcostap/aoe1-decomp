#ifndef AOE1_AIBLDMOD_H
#define AOE1_AIBLDMOD_H

#include "aibitm.h"
#include "aiblditm.h"
#include "aimodule.h"
#include "m_s_obj.h"
#include "player.h"
#include "utmarray.h"
#include "stat_obj.h"

extern "C" void __cdecl rge_read(int file, void* destination, int size);
extern "C" void __cdecl rge_write(int file, void* source, int size);
extern "C" float save_game_version;
extern "C" float version_3_1;
extern "C" float version_2_2;

class BuildAIModule : public AIModule {
public:
    // AIModule supplies slots 0-14: the destructor, the public module
    // operations, and filterOutMessage.  These four methods supply slots
    virtual ~BuildAIModule();
    virtual int save(int file);
    virtual void displayBuildList();
    virtual int loadBuildList(char* filename, RGE_Player* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int category);

    BuildItem buildList;                         // +0x0F0
    int buildListLengthValue;                    // +0x1A0
    char buildListNameValue[0x101];              // +0x1A4
    char lastBuildItemRequestedValue[0x101];     // +0x2A5
    char currentBuildItemRequestedValue[0x101];  // +0x3A6
    char nextBuildItemRequestedValue[0x101];     // +0x4A7
    int numberItemsIntoBuildListValue;           // +0x5A8
    ManagedArray<int> typesToIgnore;             // +0x5AC

    BuildAIModule(void* owner, int player);
    BuildAIModule(int file, int player);

    int buildListLength() const;
    char* buildListName();
    int haveBuildList() const;
    int insertItem(RGE_Player* player, int objectType, int count,
                   int itemType, int p5, int buildCap, int index);
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
    BuildItem* anyBuildListItem(int type, int mode, int state);
    BuildItem* specificBuildListItem(int uniqueID);
};

typedef char aibldmod_module_size[(sizeof(BuildAIModule) == 0x5BC) ? 1 : -1];

#endif  // AOE1_AIBLDMOD_H
