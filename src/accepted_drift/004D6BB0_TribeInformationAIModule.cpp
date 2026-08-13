// 004D6BB0 TribeInformationAIModule::TribeInformationAIModule
// FLAGS: config/flags/004D6BB0_TribeInformationAIModule.rsp (/GX for original constructor EH frame)
// Attempt log:
// 1: raw-offset constructor reconstruction from packet; model base ctor, InfluenceMap ctor, operator new allocations and fill loops.
// 2: added /GX and <string.h>; reached same 1182-byte size after forcing repeated member-pointer reloads in allocation fill loops.
// 3: first mismatch remains early EH/member-constructor shape: original stores EH state [esp+1C]=0 after base ctor, later state 5 before InfluenceMap ctor and state 8 before first operator new; raw placement-new emits a null check and no EH state stores.
// 4: likely needs a real typed class layout with scalar member initializers before an InfluenceMap member at +0x158 so VC5 emits constructor-unwind state transitions naturally; current raw-offset version is not accepted_drift (broad shifted diff, wrong EH bookkeeping/control around member ctor).
// 5: Replaced the raw placement-new/vptr scaffold with the canonical AIModule/InformationAIModule/InfluenceMap class surface and a real pathMap member initializer; retained local raw fields only where ownership is not yet fully reconstructed.
// 6: Added the real pre-path ManagedArray/scalar member sequence and initializer-list ownership; default constructors now emit the observed +0xF0/+0x118 zeroing before pathMap, while the remaining tail stays local pending proof.
// 7: Added the canonical post-path fields and moved max-building/max-attack/save/forest values to their declared initialization sites, eliminating duplicate player-array and scalar stores.
// 8: Mirrored the exact same-TU donor's typed unitHistory loop plus playHistory memset; this preserves LEA-before-count and REP fill scheduling rather than raw memset offset order.
// 9: Replaced raw dropsite pointer walks with the donor's typed dropsitesByAge/closestDropsite loops, preserving the proven row/column ownership and original store schedule.
// 10: Changed important/building/attack allocation fills to positive pointer guards with nested do/while loops, removing compiler-generated duplicate max==0 tests seen in the original's single-guard CFG.
// 11: Kept one ordinary initialized fill local for the three dropsite rows to test whether the original EDX=1 survives the preceding history REP fill; source remains semantically named and typed.
// 12: Reused one ordinary loop counter across the sequential history/dropsite fills, matching the decompiler's shared iVar11 lifetime instead of separate block-local counters.
// 13: Spelled the fixed play-history clear as a typed first-element memset with the proven 0xFA00 byte size; this tests intrinsic argument scheduling without raw frame/address plumbing.
// 14: Replaced the play-history memset with a typed countdown fill; the first paired LEA/count hunk now matches and the first mismatch moved to the allocation guard at +0x232.
// 15: Scoped the important-memory offset inside its positive guard; this moved the max comparison before offset zeroing and recovered the original guard block.
// 16: Replaced the building-lot and attack-memory raw fills with canonical typed fields; both allocation loops now match their original blocks and call layout.
// 17: Replaced the final raw resource-array walk with named resources/maxResources/numResources fields; this removed the extra 13-byte tail and left 27 localized bytes.
// 18: Reconstructed ObjectMemory ownership and initialized its named fields; all but two resource-fill bytes and the final intrinsic ordering now match.
// 19: Replaced the resourceTypes raw walk with named resourceTypes/numberResourceTypes arrays; current drift is 12 bytes in the final fixed-zone memset scheduling.
// Main-agent audit: retained the canonical InformationAIModule/InfluenceMap
// inheritance and named member layout. The remaining narrow I/P/B accesses
// cover fields whose ownership/layout is not yet stable; the exact-size
// constructor still has one late REP-fill ordering gap and remains scratch.
// ACCEPTED_DRIFT: main-agent adjudication confirmed the only remaining bytes
// move the non-faulting LEA of fullyExploredZoneValue across MOV ECX and XOR
// EAX before REP STOS. The effective address, fill count, value, writes, and
// flags at REP STOS are identical. Calls, CFG, size, frame, and all later
// instructions match.

#include <string.h>

typedef unsigned char uchar;

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

void* __cdecl operator new(unsigned int size);
inline void* operator new(unsigned int, void* p) { return p; }

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
    InformationAIModule(void* p, int v);
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
};

struct XYPoint { int x; int y; };
struct QuadrantLog { int numberExploredTiles; int numberAttacksOnUs; int numberAttacksByUs; };
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
    void* resources[4];
    int numResources[4];
    int maxResources[4];
    int dropsitesByAge[4][4];
    int closestDropsiteValue[4];
    int closestDropsiteResourceID[4];
    int numberFoundForestTilesValue;
    int playHistory[16000];
    int unitHistory[11];
    char unitHistoryFilename[256];
    TribeInformationAIModule(void* p, int v);
    virtual ~TribeInformationAIModule();
};

#define I(off) (*(int*)((char*)this + (off)))
#define S(off) (*(short*)((char*)this + (off)))
#define B(off) (*(uchar*)((char*)this + (off)))
#define P(off) (*(void**)((char*)this + (off)))

TribeInformationAIModule::TribeInformationAIModule(void* p, int v)
    : InformationAIModule(p, v),
      md(0),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      lastUpdateRowValue(0),
      maxImportantObjectMemory(500),
      pathMap(0xfe, 0xfe, 0xff),
      maxBuildingLots(200),
      maxAttackMemories(25),
      saveLearnInformationValue(0),
      numberFoundForestTilesValue(0)
{
    int z = 0;
    int one = 1;
    int i;
    strcpy((char*)this + 0xFF90, (const char*)0x5878BC);

    P(0x4C8) = operator new(0x10);
    P(0x4CC) = operator new(0x10);
    for (i = 0; i < 4; i++) {
        this->numberResourceTypesValue[i] = 0;
        this->resourceTypesValue[i] = 0;
    }

    for (i = 0; i < 11; i++) {
        this->unitHistory[i] = 0;
    }
    int* playHistory = this->playHistory;
    for (int remaining = 16000; remaining != 0; --remaining) {
        *playHistory = 0;
        ++playHistory;
    }

    for (i = 0; i < 4; i++) {
        this->dropsitesByAge[0][i] = 0;
        this->dropsitesByAge[1][i] = one;
        this->dropsitesByAge[2][i] = one;
        this->dropsitesByAge[3][i] = one;
    }
    for (i = 0; i < 4; i++) {
        this->closestDropsiteValue[i] = -1;
        this->closestDropsiteResourceID[i] = -1;
    }

    this->importantObjectMemory = (ObjectMemory*)operator new(
        this->maxImportantObjectMemory * sizeof(ObjectMemory));
    if (P(0x114) != 0) {
        int k = 0;
        if (this->maxImportantObjectMemory > 0) {
            do {
                this->importantObjectMemory[k].id = -1;
                this->importantObjectMemory[k].type = -1;
                this->importantObjectMemory[k].group = -1;
                this->importantObjectMemory[k].x = 0;
                this->importantObjectMemory[k].y = 0;
                this->importantObjectMemory[k].z = 0;
                this->importantObjectMemory[k].owner = 0;
                this->importantObjectMemory[k].hitPoints = 0;
                this->importantObjectMemory[k].attackAttempts = 0;
                this->importantObjectMemory[k].kills = 0;
                this->importantObjectMemory[k].damageCapability = 0;
                this->importantObjectMemory[k].rateOfFire = 0;
                this->importantObjectMemory[k].range = 0;
                k++;
            } while (k < this->maxImportantObjectMemory);
        }
    }

    P(0x1F8) = operator new(I(0x1F4) * 8);
    if (P(0x1F8) != 0) {
        int k = 0;
        if (this->maxBuildingLots > 0) {
            do {
                this->buildingLots[k].typeID = -1;
                this->buildingLots[k].x = 0;
                this->buildingLots[k].y = 0;
                this->buildingLots[k].status = 0;
                k++;
            } while (k < this->maxBuildingLots);
        }
    }

    P(0x200) = operator new(I(0x1FC) * 0x18);
    if (P(0x200) != 0) {
        int off = 0;
        int k = 0;
        if (this->maxAttackMemories > 0) {
            do {
                this->attackMemories[k].id = -1;
                this->attackMemories[k].id = -1;
                this->attackMemories[k].minX = 0;
                this->attackMemories[k].minY = 0;
                this->attackMemories[k].maxX = 0;
                this->attackMemories[k].maxY = 0;
                this->attackMemories[k].attackingOwner = 0xff;
                this->attackMemories[k].targetOwner = 0xff;
                this->attackMemories[k].kills = 0;
                this->attackMemories[k].success = 0;
                this->attackMemories[k].play = -1;
                k++;
            } while (k < this->maxAttackMemories);
        }
    }

    I(0x1A0)=-1; I(0x1A4)=-1; I(0x1A8)=-1; I(0x1AC)=-1; I(0x1B0)=-1;
    int* c=(int*)((char*)this+0x1B8);
    for (int k=0;k<4;k++, c+=2) { c[-1]=-1; c[0]=-1; c[7]=-1; c[8]=-1; }

    memset(this->fullyExploredZoneValue, 0, sizeof(this->fullyExploredZoneValue));

    int* d=(int*)((char*)this+0x410);
    for (int y=0;y<4;y++) {
        for (int x=0;x<4;x++, d+=3) { d[-2]=0; d[-1]=0; d[0]=0; }
    }

    for (k = 0; k < 4; k++) {
        this->resources[k] = 0;
        this->maxResources[k] = 0;
        this->numResources[k] = 0;
    }
}
