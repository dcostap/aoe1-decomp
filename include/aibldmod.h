#ifndef AOE1_AIBLDMOD_H
#define AOE1_AIBLDMOD_H

// Canonical declarations for the original aibldmod.cpp source module.
#include "aibitm.h"
#include "aiblditm.h"
#include "aimodule.h"
#include "utmarray.h"

class RGE_Player;
class RGE_Master_Static_Object;

extern "C" void __cdecl rge_read(int file, void* destination, int size);
extern "C" void __cdecl rge_write(int file, void* source, int size);
extern "C" float save_game_version;
extern "C" float version_3_1;
extern "C" float version_2_2;

class BuildAIModule : public AIModule {
public:
    // AIModule supplies slots 0-14: the destructor, the public module
    // operations, and filterOutMessage.  These four methods supply slots
    // 15-18 in the PDB-proven BuildAIModule vtable.
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

// This module uses the proven field prefix of these input records.  The
// complete class declarations belong to their owning source modules.
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_004[4];
    char* name;                         // +0x08
    char gap_00C[0x24];
    float radius_x;                     // +0x30
    float radius_y;                     // +0x34
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_004[0x1E];
    short master_object_num;            // +0x22
    RGE_Master_Static_Object** master_objects; // +0x24
};

typedef char aibldmod_module_size[(sizeof(BuildAIModule) == 0x5BC) ? 1 : -1];

#endif  // AOE1_AIBLDMOD_H
