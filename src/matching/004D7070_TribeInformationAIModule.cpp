// VA: 004D7070 TribeInformationAIModule::TribeInformationAIModule(int, int)
// PDB: taiinfmd.cpp:241-407
//
// Attempt log:
// - Baseline reconstruction uses the real InformationAIModule base, the five
//   pre-path ManagedArray<int> subobjects, the InfluenceMap member, and the
//   two post-map ManagedArray<int> subobjects.  The parameter-home reuse and
//   inline ManagedArray::add shape are binary-supported by the packet.
// - The class surface deliberately models the canonical module/data layout;
//   compiler pointers and constructor EH state are compiler-generated.
// - md(0) and the two scalar member initializers preserve the original
//   pre-map zeroing and delayed automatic derived-compiler pointer store.
// - The exact control-flow forms are the source-supported do/while resource
//   scans, positive modern-version arms, and nonzero resource allocation arm.
// - Exact under /GX: 3129 bytes, 63 calls, 933 instructions, 0.0000% diff.

#include <string.h>

extern "C" void __cdecl rge_read(int file, void* buffer, int size);

extern float save_game_version;
extern float DAT_00575550;
extern float DAT_00575554;
extern float DAT_00575558;
extern float DAT_0057555c;
extern float DAT_00575560;

void* operator new(unsigned int size);
void operator delete(void* ptr);

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[64];
};

class AIModule {
public:
    virtual ~AIModule();

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

class InformationAIModule : public AIModule {
public:
    InformationAIModule(void* param1, int param2);
    virtual ~InformationAIModule();
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
    ~ManagedArray();

    int add(T val) {
        int i;

        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == val)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int newSize = this->numberValue + 1;
            T* newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= newSize)
                        break;
                    newValue[j] = this->value[j];
                }
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }

        this->value[this->numberValue] = val;
        this->numberValue++;
        return 1;
    }
};

class InfluenceMap {
public:
    virtual ~InfluenceMap();

    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    unsigned char unchangeableLimitValue;
    unsigned char _pad_end[3];

    InfluenceMap(int xSize, int ySize, unsigned char fillValue);
    void load(int file);
};

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char _pad_0[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char _pad_1[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

struct BuildingLot {
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
    unsigned char _pad_end[1];
};

struct AttackMemory {
    int id;
    unsigned char type;
    unsigned char minX;
    unsigned char minY;
    unsigned char maxX;
    unsigned char maxY;
    unsigned char attackingOwner;
    unsigned char targetOwner;
    unsigned char _pad_0[1];
    short kills;
    unsigned char success;
    unsigned char _pad_1[1];
    unsigned long timeStamp;
    int play;
};

struct XYPoint {
    int x;
    int y;
};

struct QuadrantLog {
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};

struct ResourceMemory {
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    unsigned char _pad_0[1];
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

class TribeMainDecisionAIModule;

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray<int> farmsTaskedThisUpdate;
    TribeMainDecisionAIModule* md;
    int mapXSizeValue;
    int mapYSizeValue;
    int lastUpdateRowValue;
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    ManagedArray<int> importantObjects;
    ManagedArray<int> importantUnits;
    ManagedArray<int> importantMiscs;
    ManagedArray<int> itemsToDefend;
    InfluenceMap pathMap;
    ManagedArray<int> playerObjects;
    ManagedArray<int> playerBuildings;
    XYPoint lastWallPosition;
    XYPoint lastWallPosition2;
    int numberGatesValue;
    XYPoint minGatePosition[4];
    XYPoint maxGatePosition[4];
    int maxBuildingLots;
    BuildingLot* buildingLots;
    int maxAttackMemories;
    AttackMemory* attackMemories;
    int saveLearnInformationValue;
    char learnFileName[256];
    unsigned char fullyExploredZoneValue[255];
    unsigned char _pad_407[1];
    QuadrantLog quadrantLog[4][4];
    int** resourceTypesValue;
    int* numberResourceTypesValue;
    ResourceMemory* resources[4];
    int numResources[4];
    int maxResources[4];
    int dropsitesByAge[4][4];
    int closestDropsiteValue[4];
    int closestDropsiteResourceID[4];
    int numberFoundForestTilesValue;
    int playHistory[16000];
    int unitHistory[11];
    char unitHistoryFilename[256];

    TribeInformationAIModule(int param1, int param2);
    virtual ~TribeInformationAIModule();

    void addResourceType(int resourceIndex, int typeValue);
};
#endif

#endif
TribeInformationAIModule::TribeInformationAIModule(int param1, int param2)
    : InformationAIModule(0, param1),
      md(0),
      pathMap(0xfe, 0xfe, 0xff),
      saveLearnInformationValue(0),
      numberFoundForestTilesValue(0)
{
    int tempInt;
    int tempInt_ffffffe8;
    int local_14;
    int resourceIndex;
    int i3;

    strcpy(this->unitHistoryFilename, "learn\\Default.uh");

    this->resourceTypesValue = (int**)operator new(0x10);
    this->numberResourceTypesValue = (int*)operator new(0x10);
    for (int i0 = 0; i0 < 4; i0++) {
        this->numberResourceTypesValue[i0] = 0;
        this->resourceTypesValue[i0] = 0;
    }

    for (int i10 = 0; i10 < 11; i10++) {
        this->unitHistory[i10] = 0;
    }
    memset(this->playHistory, 0, sizeof(this->playHistory));

    for (int i1 = 0; i1 < 4; i1++) {
        this->dropsitesByAge[0][i1] = 0;
        this->dropsitesByAge[1][i1] = 1;
        this->dropsitesByAge[2][i1] = 1;
        this->dropsitesByAge[3][i1] = 1;
    }

    for (int i2 = 0; i2 < 4; i2++) {
        this->closestDropsiteValue[i2] = -1;
        this->closestDropsiteResourceID[i2] = -1;
    }

    resourceIndex = 0;
    do {
        rge_read(param2, &param1, 4);
        i3 = 0;
        if (param1 > 0) {
            do {
                rge_read(param2, &local_14, 4);
                this->addResourceType(resourceIndex, local_14);
                i3++;
            } while (i3 < param1);
        }
        resourceIndex++;
    } while (resourceIndex < 4);

    rge_read(param2, &this->mapXSizeValue, 4);
    rge_read(param2, &this->mapYSizeValue, 4);
    rge_read(param2, &this->lastUpdateRowValue, 4);
    rge_read(param2, &this->maxImportantObjectMemory, 4);
    this->importantObjectMemory = (ObjectMemory*)operator new(
        this->maxImportantObjectMemory * sizeof(ObjectMemory));
    if (this->importantObjectMemory != 0) {
        for (int i4 = 0; i4 < this->maxImportantObjectMemory; i4++) {
            rge_read(param2, this->importantObjectMemory + i4, sizeof(ObjectMemory));
        }

        rge_read(param2, &this->maxBuildingLots, 4);
        this->buildingLots = (BuildingLot*)operator new(
            this->maxBuildingLots * sizeof(BuildingLot));
        if (this->buildingLots != 0) {
            for (int i5 = 0; i5 < this->maxBuildingLots; i5++) {
                rge_read(param2, this->buildingLots + i5, sizeof(BuildingLot));
            }

            rge_read(param2, &this->maxAttackMemories, 4);
            this->attackMemories = (AttackMemory*)operator new(
                this->maxAttackMemories * sizeof(AttackMemory));
            if (this->attackMemories != 0) {
                for (int i6 = 0; i6 < this->maxAttackMemories; i6++) {
                    rge_read(param2, this->attackMemories + i6, sizeof(AttackMemory));
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->importantObjects.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->importantUnits.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->importantMiscs.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->itemsToDefend.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->playerBuildings.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->playerObjects.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                this->pathMap.load(param2);
                rge_read(param2, &this->lastWallPosition, 8);
                rge_read(param2, &this->lastWallPosition2, 8);

                if (!(save_game_version < DAT_00575550)) {
                    rge_read(param2, &this->numberGatesValue, 4);
                } else {
                    rge_read(param2, &this->numberGatesValue, 8);
                }

                for (int i7 = 0; i7 < 4; i7++) {
                    rge_read(param2, &this->minGatePosition[i7], 8);
                    rge_read(param2, &this->maxGatePosition[i7], 8);
                }

                rge_read(param2, &this->saveLearnInformationValue, 4);
                if (!(save_game_version < DAT_00575550)) {
                    rge_read(param2, &tempInt_ffffffe8, 4);
                    rge_read(param2, this->learnFileName, tempInt_ffffffe8);
                    this->learnFileName[tempInt_ffffffe8] = '\0';
                } else {
                    strcpy(this->learnFileName, "");
                }

                rge_read(param2, this->fullyExploredZoneValue, 0xff);
                if (!(save_game_version < DAT_00575554)) {
                    rge_read(param2, this->quadrantLog, 0xc0);
                } else {
                    for (int i8 = 0; i8 < 4; i8++) {
                        for (int j8 = 0; j8 < 4; j8++) {
                            this->quadrantLog[i8][j8].numberExploredTiles = 0;
                            this->quadrantLog[i8][j8].numberAttacksOnUs = 0;
                            this->quadrantLog[i8][j8].numberAttacksByUs = 0;
                        }
                    }
                }

                rge_read(param2, this->maxResources, 0x10);
                rge_read(param2, this->numResources, 0x10);
                for (int i9 = 0; i9 < 4; i9++) {
                    if (this->maxResources[i9] != 0) {
                        this->resources[i9] = (ResourceMemory*)operator new(
                            this->maxResources[i9] * sizeof(ResourceMemory));
                        rge_read(param2, this->resources[i9],
                                 this->maxResources[i9] * sizeof(ResourceMemory));
                    } else {
                        this->resources[i9] = 0;
                    }
                }

                if (!(save_game_version < DAT_00575558)) {
                    rge_read(param2, this->dropsitesByAge, 0x40);
                }
                if (!(save_game_version < DAT_00575558)) {
                    rge_read(param2, this->closestDropsiteValue, 0x10);
                    rge_read(param2, this->closestDropsiteResourceID, 0x10);
                }
                if (!(save_game_version < DAT_0057555c)) {
                    rge_read(param2, &this->numberFoundForestTilesValue, 4);
                }
                if (!(save_game_version < DAT_00575560)) {
                    rge_read(param2, this->playHistory, 64000);
                }
            }
        }
    }
}
