// VA: 004D7CB0 TribeInformationAIModule::~TribeInformationAIModule
// PDB source: taiinfmd.cpp:412-564
// Attempt log:
// - Replaced the old raw-offset/helper scaffold with the canonical class
//   ownership from the constructor, generated type surface, and same-TU save
//   donor.  The destructor owns five ManagedArray<int> members, one
//   InfluenceMap, the object-memory records, and four resource arrays.
// - The original uses /GX and inline ManagedArray cleanup.  The save block
//   keeps its natural record loops and ManagedArray::operator[] growth form.
// - Independent byte-offset counters for the second attack/object scans
//   restored the original 1472-byte boundary and all 38 ordered calls.
// - Moving offset initialization inside each positive-count guard restored
//   the original late EDI zeroing and 97.66% exact-block coverage.
// - Repeating the typed record address for the predicate and write matched
//   every instruction and left only two ModRM operand-order bytes at the
//   important-object scan.  A base local, narrow record alias, and int-width
//   id probe were rolled back or retained only when they produced no change.

extern "C" int rge_open(char*, int, int);
extern "C" void rge_write(int, void*, int);
extern "C" int rge_close(int);

void* operator new(unsigned int size);
void operator delete(void* ptr);

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

    ~ManagedArray() {
        if (this->value != 0) {
            operator delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            T* newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                int i;
                for (i = 0; i < this->maximumSizeValue; i++) {
                    if (i >= newSize)
                        break;
                    newValue[i] = this->value[i];
                }
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
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

struct XYPoint {
    int x;
    int y;
};

struct QuadrantLog {
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};

class TRIBE_World {
public:
    char gap_000[0x11d];
    unsigned char controllingComputerPlayer;
};

class RGE_Player {
public:
    char gap_000[0x3c];
    TRIBE_World* world;
    char gap_040[0xa];
    short id;
};

class MainDecisionAIModule {
public:
    char gap_000[0xf0];
    RGE_Player* player;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

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

    virtual ~TribeInformationAIModule();
};

TribeInformationAIModule::~TribeInformationAIModule()
{
    int count;
    int tempInt;
    int outFile;
    int local_14;
    int i;
    int index;
    int offset;

    for (i = 0; i < 4; i++) {
        operator delete(this->resourceTypesValue[i]);
    }
    operator delete(this->resourceTypesValue);
    operator delete(this->numberResourceTypesValue);

    if (this->saveLearnInformationValue == 1) {
        int file = rge_open(this->learnFileName, 0x8301, 0x180);
        local_14 = file;
        if (file != -1) {
            rge_write(file, &this->mapXSizeValue, 4);
            rge_write(file, &this->mapYSizeValue, 4);

            count = 0;
            if (this->maxAttackMemories > 0) {
                AttackMemory* memory = this->attackMemories;
                int remaining = this->maxAttackMemories;
                do {
                    if (memory->id != -1)
                        count++;
                    memory++;
                    remaining--;
                } while (remaining != 0);
            }
            rge_write(file, &count, 4);

            index = 0;
            if (this->maxAttackMemories > 0) {
                offset = 0;
                do {
                    if (((AttackMemory*)((char*)this->attackMemories + offset))->id != -1)
                        rge_write(file,
                                  (AttackMemory*)((char*)this->attackMemories + offset),
                                  0x18);
                    index++;
                    offset += sizeof(AttackMemory);
                } while (index < this->maxAttackMemories);
            }

            count = 0;
            if (this->maxImportantObjectMemory > 0) {
                ObjectMemory* memory = this->importantObjectMemory;
                int remaining = this->maxImportantObjectMemory;
                do {
                    if (memory->id != -1 && memory->type == 0x6d)
                        count++;
                    memory++;
                    remaining--;
                } while (remaining != 0);
            }
            rge_write(file, &count, 4);

            index = 0;
            if (this->maxImportantObjectMemory > 0) {
                offset = 0;
                do {
                    if (((ObjectMemory*)(offset + (char*)this->importantObjectMemory))->id != -1 &&
                        ((ObjectMemory*)(offset + (char*)this->importantObjectMemory))->type == 0x6d)
                        rge_write(file,
                                  (ObjectMemory*)(offset + (char*)this->importantObjectMemory),
                                  0x24);
                    index++;
                    offset += sizeof(ObjectMemory);
                } while (index < this->maxImportantObjectMemory);
            }

            for (i = 0; i < 4; i++) {
                rge_write(file, &this->maxResources[i], 4);
                rge_write(file, &this->numResources[i], 4);
                if (this->maxResources[i] != 0)
                    rge_write(file, this->resources[i],
                              this->maxResources[i] * sizeof(ResourceMemory));
            }

            outFile = this->importantMiscs.numberValue;
            rge_write(file, &outFile, 4);
            for (i = 0; i < this->importantMiscs.numberValue; i++) {
                outFile = this->importantMiscs[i];
                rge_write(file, &outFile, 4);
            }

            outFile = this->itemsToDefend.numberValue;
            rge_write(file, &outFile, 4);
            for (i = 0; i < this->itemsToDefend.numberValue; i++) {
                outFile = this->itemsToDefend[i];
                rge_write(file, &outFile, 4);
            }
            rge_close(file);
        }
    }

    unsigned char currentPlayer = this->md->player->world->controllingComputerPlayer;
    if ((currentPlayer == this->md->player->id || currentPlayer == 0xff) &&
        (local_14 = rge_open(this->unitHistoryFilename, 0x8301, 0x180),
         local_14 != -1)) {
        rge_write(local_14, this->unitHistory, 0x2c);
        rge_close(local_14);
    }

    if (this->importantObjectMemory != 0)
        operator delete(this->importantObjectMemory);
    if (this->buildingLots != 0)
        operator delete(this->buildingLots);
    if (this->attackMemories != 0)
        operator delete(this->attackMemories);

    for (i = 0; i < 4; i++) {
        if (this->resources[i] != 0) {
            operator delete(this->resources[i]);
            this->resources[i] = 0;
        }
    }
}
