// 004EEB40 TribeTacticalAIModule::~TribeTacticalAIModule
// Source: taitacmd.cpp lines 2032-2034
// Baseline: typed class/member reconstruction from the binary-backed layout.
// The destructor body removes all groups; the remaining cleanup is the normal
// reverse-order destruction of the nontrivial members and base class.
//
// Attempt log:
// - Replaced the raw offset/helper scaffold with the period-typed class surface
//   and natural member destruction order. First baseline check pending.
// - Typed all members from the binary-backed 0x100C layout. The first check
//   had 14 unresolved ManagedArray destructor calls and was 419 bytes short.
// - Kept civilians as the out-of-line ManagedArray<int> member at 00408D20;
//   modeled the other 13 identical four-word records with an inline
//   storage-record destructor so VC5 emits the observed scalar delete/zero
//   sequence and EH-state stores. This moved to exact size/CFG/call shape.
// - Changed operator delete to the period C++ global declaration; this
//   restored the 13 EH-state stores and reduced the remaining drift to one
//   relocation identity (4 bytes).
// - Added the decorated 00408D20 ManagedArray<int> identity to
//   config/original_symbol_overrides.txt; the rebuilt function is now exact.
// - Same-template inline destruction for all 14 members emitted one extra
//   cleanup block (788 bytes); volatile qualification was a codegen duplicate.
//   Restored the typed exact candidate. The storage-record distinction is
//   retained only because the executable proves the one out-of-line call and
//   the 13 inlined scalar cleanups.

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

void __cdecl operator delete(void*);

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ~ManagedArray();
};

template <class T>
class ManagedArrayStorage {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ~ManagedArrayStorage()
    {
        if (this->value != 0) {
            operator delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[0x32C];
};

class ResourceItem {
public:
    virtual ~ResourceItem();
    char gap_04[0x6C];
};

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    unsigned long lastTaskTime;
};

struct PlacementState {
    char bytes[0x130];
};

struct AttackState {
    char bytes[0x2C];
};

class TribeMainDecisionAIModule;

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArrayStorage<int> civilianExplorers;
    ManagedArrayStorage<int> soldiers;
    ManagedArrayStorage<int> ungroupedSoldiers;
    ManagedArrayStorage<int> boats;
    ManagedArrayStorage<int> warBoats;
    ManagedArrayStorage<int> fishingBoats;
    ManagedArrayStorage<int> tradeBoats;
    ManagedArrayStorage<int> transportBoats;
    ManagedArrayStorage<int> artifacts;
    int sn[226];
    UnitData gatherers[50];
    int numberGatherersValue;
    int desiredNumberGatherersValue;
    TacticalAIGroup groups;
    int groupIDValue;
    int numberGroupsValue;
    unsigned long lastGroupAttackTime;
    unsigned long lastGroupRebalanceTime;
    unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime;
    unsigned long lastScalingUpdateValue;
    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;
    ManagedArrayStorage<int> playersToAttack;
    ManagedArrayStorage<int> playersToDefend;
    ManagedArrayStorage<int> workingArea;
    ManagedArrayStorage<int> unitsTaskedThisUpdate;
    int actualGathererDistribution[4];
    int desiredGathererDistribution[4];
    int neededResourceValue[4];
    int resourceDifferenceValue[4];
    ResourceItem neededResources;
    int attackEnabledValue;
    int updateArea;
    int firstNeededResourceUpdateDone;
    int numberStoragePitsBuilt[4];
    int numberGranariesBuilt[4];
    int wonderInProgressValue;
    int wonderBuiltValue;
    PlacementState placementStateValue;
    int nextCivilianToTaskValue;
    int nextIdleSoldierGroupToTaskValue;
    int nextActiveSoldierGroupToTaskValue;
    int builtFirstStoragePit;
    int builtFirstGranary;
    unsigned long lastBuildTime;
    unsigned long lastAttackResponseBuildInsertionTime;
    unsigned long lastCoopTributeDemandTime;
    unsigned long lastCoopTributeGiftTime;
    unsigned long lastCoopAttackDemandTime;
    int zoomingToNextAge;
    unsigned long lastUngroupedSoldierTaskTime;
    AttackState attackStateValue;
    int hitsByPlayer[9];
    int lastUpdateAreaTimeValue;
    int averageUpdateAreaTimeValue;
    int updateAreaAverageCount;
    int updateAreaAverageTotal;

    int removeAllGroups(int);
    virtual ~TribeTacticalAIModule();
};
#endif

TribeTacticalAIModule::~TribeTacticalAIModule()
{
    this->removeAllGroups(-1);
}
