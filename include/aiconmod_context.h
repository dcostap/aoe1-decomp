#ifndef AOE1_AICONMOD_CONTEXT_H
#define AOE1_AICONMOD_CONTEXT_H

// Shared compiler-facing declarations for the original aiconmod.cpp module.
// The PDB source order is recorded by src/aiconmod_tu.cpp.  The class layouts
// below are the reviewed 32-bit surfaces used by the module's owners.

class AIModuleMessage;
class BuildItem;
class ConstructionItem;
class RGE_Player;
class RGE_Game_World;
class RGE_Victory_Conditions;

class AIModuleID {
public:
    virtual ~AIModuleID();

    int id;
    char name[64];
};

class BaseItem {
public:
    virtual ~BaseItem();

    int typeIDValue;              // +0x04
    int gameIDValue;              // +0x08
    int uniqueIDValue;            // +0x0C
    char nameValue[64];           // +0x10
    float xValue;                 // +0x50
    float yValue;                 // +0x54
    float zValue;                 // +0x58
    float xSizeValue;             // +0x5C
    float ySizeValue;             // +0x60
    float zSizeValue;             // +0x64
    int skipValue;                // +0x68

    char* name();
    int typeID() const;
    int gameID() const;
    int uniqueID() const;
    float x() const;
    float y() const;
    float z() const;
    float xSize() const;
    float ySize() const;
    float zSize() const;
    int skip() const;

    void setGameID(int value);
    void setUniqueID(int value);
    void setSkip(int value);
    void setX(float value);
    void setY(float value);
    void setZ(float value);
};

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

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* value);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* value);
    virtual int saveState(char* value);
    virtual int gleanState(int value);
    virtual int processMessage(AIModuleMessage* message);
    virtual int update(int value);
    virtual void setCallbackMessage(AIModuleMessage* message);
    virtual int filterOutMessage(AIModuleMessage* message);

    AIModuleID idValue;            // +0x04
    int playerNumberValue;         // +0x4C
    char playerNameValue[64];      // +0x50
    int runningValue;              // +0x90
    int pausedValue;               // +0x94
    int logHistoryValue;           // +0x98
    int logCommonHistoryValue;     // +0x9C
    void* historyLogFile;          // +0xA0
    char historyLogFilename[64];   // +0xA4
    int intelligenceLevelValue;    // +0xE4
    int priorityValue;             // +0xE8
    int processFrameValue;         // +0xEC

    AIModule(char* name, int id, int player, void* parameter);
    void logCommonHistory(char* format, ...);
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
