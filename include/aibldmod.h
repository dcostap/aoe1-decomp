#ifndef AOE1_AIBLDMOD_H
#define AOE1_AIBLDMOD_H

// Canonical declarations for the original aibldmod.cpp source module.

typedef unsigned char uchar;
typedef unsigned int uint;

class RGE_Player;
class RGE_Master_Static_Object;

extern "C" void __cdecl rge_read(int file, void* destination, int size);
extern "C" void __cdecl rge_write(int file, void* source, int size);
extern "C" void __cdecl logCommonHistory(void* self, const char* format, ...);
extern "C" char* strcpy(char* destination, const char* source);
extern "C" float save_game_version;
extern "C" float version_3_1;
extern "C" float version_2_2;

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* value);

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_004[0x68];

    int typeID() const;
    int number() const;
    int priority() const;
    int gameID() const;
    int uniqueID() const;
    char* name();
    float x() const;
    float y() const;
    float z() const;
    float xSize() const;
    float ySize() const;
    float zSize() const;
    int skip() const;

    void setTypeID(int value);
    void setGameID(int value);
    void setUniqueID(int value);
    void setName(char* value);
    void setX(float value);
    void setY(float value);
    void setZ(float value);
    void setXSize(float value);
    void setYSize(float value);
    void setZSize(float value);
    void setSkip(int value);
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

    BuildItem();
    BuildItem(int type, int object, int sequence, int number, int priority,
              int buildFrom, char* name, float xSize, float ySize,
              float zSize, int terrainSet, int adjacent0, int adjacent1,
              int placeOnElevation);
    BuildItem(BuildItem* source);
    BuildItem(const BuildItem& source);
    virtual ~BuildItem();

    int buildCategory() const;
    int number() const;
    int priority() const;
    int inProgress() const;
    int built() const;
    int buildAttempts() const;
    int buildFrom() const;
    int terrainSet() const;
    int terrainAdjacency(int index) const;
    int placeOnElevation() const;
    int numberBuilds() const;
    int buildCap() const;
    int skipCycles() const;
    uchar permanentSkip() const;

    void setInProgress(int value);
    void setBuilt(int value);
    void setBuildAttempts(int value);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    void setNumberBuilds(int value);
    void incrementNumberBuilds();
    void setBuildCap(int value);
    void setSkipCycles(int value);
    void incrementSkipCycles();
    void setPermanentSkip(uchar value);
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    ~ManagedArray() {
        if (value != 0) {
            delete value;
            value = 0;
        }
        numberValue = 0;
        desiredNumberValue = 0;
        maximumSizeValue = 0;
    }

    int add(int item) {
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

class AIModule {
public:
    virtual ~AIModule();
    AIModule();
    AIModule(char* name, int id, int player, void* owner);

    char gap_004[0xEC];

    void __cdecl logCommonHistory(char* format, ...);
};

class BuildAIModule : public AIModule {
public:
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

// The display source uses these original local type names.  Removing them
// changes VC5's loadBuildList local allocation in the complete module.
typedef BaseItem BaseItem2;
typedef BuildItem BuildItem2;
typedef AIModule AIModule2;
typedef BuildAIModule BuildAIModule2;

typedef char aibldmod_build_item_size[(sizeof(BuildItem) == 0xB0) ? 1 : -1];
typedef char aibldmod_module_size[(sizeof(BuildAIModule) == 0x5BC) ? 1 : -1];

#endif  // AOE1_AIBLDMOD_H
