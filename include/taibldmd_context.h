#ifndef AOE1_TAIBLDMD_CONTEXT_H
#define AOE1_TAIBLDMD_CONTEXT_H

// Canonical local declarations for the original taibldmd.cpp source module.
// PDB lines 62-1773 prove one TribeBuildAIModule owner sequence.
// The original EH frames in initialize and nextBuildableItem require /GX.

typedef unsigned char uchar;
typedef unsigned int uint;

extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void* operator new(uint size);
void operator delete(void* ptr);

class AIModuleMessage;
class BuildItem;
class ResourceItem;
class RGE_Player;
class RGE_Static_Object;
class TribeMainDecisionAIModule;

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory() const;
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* filename);
    virtual int loggingCommonHistory() const;
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* filename);
    virtual int saveState(char* filename);
    virtual int gleanState(int value);
    virtual int processMessage(AIModuleMessage* message);
    virtual int update(int value);
    virtual void setCallbackMessage(AIModuleMessage* message);

protected:
    virtual int filterOutMessage(AIModuleMessage* message);

public:
    char gap_004[0xEC];
};

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_004[0x68];

    int typeID() const;
    int skip() const;
    void setSkip(int value);
    char* name();
    int uniqueID() const;
};

class BuildItem : public BaseItem {
public:
    BuildItem* next;                  // +0x6C
    BuildItem* prev;                  // +0x70
    int buildCategoryValue;           // +0x74
    int numberValue;                  // +0x78
    int priorityValue;                // +0x7C
    int progressValue;                // +0x80
    int builtValue;                   // +0x84
    int buildAttemptsValue;           // +0x88
    int buildFromValue;               // +0x8C
    int terrainSetValue;              // +0x90
    int terrainAdjacencyValue[2];     // +0x94
    int placeOnElevationValue;        // +0x9C
    int numberBuildsValue;            // +0xA0
    int buildCapValue;                // +0xA4
    int skipCyclesValue;              // +0xA8
    uchar permanentSkipValue;         // +0xAC
    uchar endPad[3];                  // +0xAD

    virtual ~BuildItem();
    int buildCategory() const;
    int inProgress() const;
    int built() const;
    int buildAttempts() const;
    int buildFrom() const;
    int buildCap();
    int numberBuilds();
    uchar permanentSkip();
    void setInProgress(int value);
    void setBuilt(int value);
    void setBuildAttempts(int value);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    void incrementSkipCycles();
    int skipCycles();
    void setPermanentSkip(uchar value);
};

class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    ResourceItem(int count);
    void setAllValues(int value);
    int value(int index) const;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int add(int item)
    {
        int i;
        T* newValue;
        int newSize;

        for (i = 0; i < numberValue; i++) {
            if (i >= maximumSizeValue) break;
            if (value[i] == item) return 0;
        }
        if (numberValue > maximumSizeValue - 1) {
            newSize = numberValue + 1;
            newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                for (i = 0; i < maximumSizeValue; i++) {
                    if (i >= newSize) break;
                    newValue[i] = value[i];
                }
                operator delete(value);
                value = newValue;
                maximumSizeValue = newSize;
            }
        }
        value[numberValue] = item;
        numberValue = numberValue + 1;
        return 1;
    }
};

class BuildAIModule : public AIModule {
public:
    virtual ~BuildAIModule();
    virtual int save(int value);
    virtual void displayBuildList();
    virtual int loadBuildList(char* filename, RGE_Player* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int flag);

    BuildItem buildList;                         // +0x0F0
    union {
        int buildListLengthValue;
        int buildListLength;
    };                                           // +0x1A0
    char buildListNameValue[0x101];              // +0x1A4
    char lastBuildItemRequestedValue[0x101];     // +0x2A5
    char currentBuildItemRequestedValue[0x101];  // +0x3A6
    char nextBuildItemRequestedValue[0x101];     // +0x4A7
    int numberItemsIntoBuildListValue;           // +0x5A8
    ManagedArray<int> typesToIgnore;             // +0x5AC

    BuildAIModule(void* owner, int player);
    BuildAIModule(int file, int player);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long positionChecksum;
    long actionChecksum;
    uchar checksumCreatedThisUpdate;
    uchar gap_021;
    short masterObjectNum;
    void* masterObjects;
    void* objects;
    void* sleepingObjects;
    void* dopplegangerObjects;
    void* victoryConditions;
    void* visible;
    void* world;
    void* dopplegangerCreator;
    char* name;
    uchar type;
    uchar gap_049;
    short id;
    short attributeNum;
    uchar gap_04E[2];
    float* attributes;
};

class TRIBE_Player : public RGE_Player {
public:
    uchar researchState(int type);
    int researchEverAvailable(int type);
    int researchAvailable(int type);
    int objectAvailable(int type);
    void researchCost(int type, int amount, ResourceItem* item, int flag);
    void objectCost(int type, int amount, ResourceItem* item, int flag);
};

class RGE_Static_Object {};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;              // +0x0F0
    char gap_0F4[0x10];             // through +0x104

    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5,
                              int p6, int p7, int p8, int p9, int p10);
};

class TribeConstructionAIModule {
public:
    char gap_000[0x318];
    int canPlace(BuildItem* item);
};

class TribeResourceAIModule {
public:
    char gap_000[0xF8];
    int resource(int type) const;
    int resourcesAvailable(ResourceItem* item);
    int unavailableResource(ResourceItem* item);
};

class TribeTacticalAIModule {
public:
    char gap_000[0x100C];
    int strategicNumber(int number);
    void enableAttack(int value);
    void setStrategicNumber(int number, int value);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char buildAI[0x5C0];                         // +0x00104
    TribeConstructionAIModule constructionAI;    // +0x006C4
    char gap_009DC[0x103A0];                     // through +0x10D7C
    TribeResourceAIModule resourceAI;            // +0x10D7C
    char gap_10E74[0x5F8];                       // through +0x1146C
    TribeTacticalAIModule tacticalAI;            // +0x1146C
    char gap_12478[0xF4];                        // through +0x1256C
    TRIBE_Player* aiPlayer;                      // +0x1256C
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;               // +0x5BC

    TribeBuildAIModule(void* owner, int player);
    TribeBuildAIModule(int file, int player);
    virtual ~TribeBuildAIModule();
    virtual int loadBuildList(char* filename, RGE_Player* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int flag);

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
};

typedef char taibldmd_build_item_size[(sizeof(BuildItem) == 0xB0) ? 1 : -1];
typedef char taibldmd_resource_item_size[(sizeof(ResourceItem) == 0x70) ? 1 : -1];
typedef char taibldmd_build_module_size[(sizeof(BuildAIModule) == 0x5BC) ? 1 : -1];
typedef char taibldmd_tribe_build_module_size[(sizeof(TribeBuildAIModule) == 0x5C0) ? 1 : -1];

#endif
