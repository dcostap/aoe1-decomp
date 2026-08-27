#ifndef AOE1_AICONMOD_H
#define AOE1_AICONMOD_H

// Reviewed compiler-facing declarations for aiconmod.cpp and aidipmod.cpp.
// BaseItem and AIModule are owned by their canonical headers.  The player and
// world declarations below remain narrow local views proven by the PDB users.

#include "aibitm.h"
#include "aimodule.h"

class BuildItem;
class ConstructionItem;
class RGE_Player;
class RGE_Game_World;
class RGE_Victory_Conditions;

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;       // +0x6C
    ConstructionItem* prev;       // +0x70
    int inProgressValue;          // +0x74
    int builtValue;               // +0x78
    int buildAttemptsValue;       // +0x7C

    ConstructionItem();
    ConstructionItem(float x, float y, float z,
                     float xSize, float ySize, float zSize,
                     int typeID, char* name);
    virtual ~ConstructionItem();

    int inProgress();
    int built();
    int buildAttempts();
    void setInProgress(int value);
    void setBuilt(int value);
    void setBuildAttempts(int value);
    void decrementBuildAttempts();
    void incrementBuildAttempts();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;
    char gap_3E[0x2];
    RGE_Player** players;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);

    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x4];
    RGE_Game_World* world;
    char gap_40[0xA];
    short id;
    char gap_4C[0x34];
    unsigned char game_status;
    char gap_81[0x3];
    unsigned char* relations;
};

class ConstructionAIModule : public AIModule {
public:
    enum PlacementResult {
        PlacementOk = 0
    };

    virtual ~ConstructionAIModule();
    virtual int save(int file);
    virtual int loadConstructionPlan(char* name, int mapX, int mapY,
                                     float xReference, float yReference,
                                     float zReference);
    virtual ConstructionItem* placeStructure(BuildItem* item);
    virtual void setBuilt(ConstructionItem* item, int built);
    virtual int unplaceStructure(ConstructionItem* item, int decrement);
    virtual int unplaceStructure(float x, float y, int decrement);
    virtual void decrementBuildAttempts(float x, float y, int count);
    virtual void incrementBuildAttempts(float x, float y, int count);

    int numberConstructionLotsValue;             // +0xF0
    ConstructionItem constructionLots;           // +0xF4
    int numberRandomConstructionLotsValue;       // +0x174
    ConstructionItem randomConstructionLots;     // +0x178
    char constructionPlanNameValue[257];        // +0x1F8
    unsigned char padding_2F9[3];                // +0x2F9
    float xReferencePointValue;                  // +0x2FC
    float yReferencePointValue;                  // +0x300
    float zReferencePointValue;                  // +0x304
    int mapXSizeValue;                            // +0x308
    int mapYSizeValue;                            // +0x30C
    PlacementResult lastPlacementReturnCodeValue; // +0x310

    ConstructionAIModule(void* parameter, int player);
    ConstructionAIModule(int player, int file);

    char* constructionPlanName();
    void setReferencePoint(int mapX, int mapY, float xReference,
                           float yReference, float zReference);
    float xReferencePoint();
    float yReferencePoint();
    PlacementResult lastPlacementReturnCode();
    ConstructionItem* lot(float x, float y);
    ConstructionItem* randomLot(float x, float y);

protected:
    void removeOldLots();
};

int __cdecl operator==(const ConstructionItem& left,
                       const ConstructionItem& right);

typedef char aiconmod_aimodule_size[(sizeof(AIModule) == 0xF0) ? 1 : -1];
typedef char aiconmod_base_item_size[(sizeof(BaseItem) == 0x6C) ? 1 : -1];
typedef char aiconmod_construction_item_size[(sizeof(ConstructionItem) == 0x80) ? 1 : -1];
typedef char aiconmod_module_size[(sizeof(ConstructionAIModule) == 0x314) ? 1 : -1];

#endif
