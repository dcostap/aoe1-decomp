// 004ED1C0 TribeTacticalAIModule::TribeTacticalAIModule(void*,int)
// Source: taitacmd.cpp lines 1736-1773
// Ghidra-body compileable baseline for the non-loading constructor; kept close
// to the related 004ED4F0 load-constructor surface.
// FLAGS: /GX for the original EH-framed constructor.
// Attempt log:
// - 2026-05-04: copied the Ghidra heuristic body and adjusted the local type
//   surface to compile.  PlacementState/AttackState use the real active offsets
//   (+0x114/+0x28), matching type dumps and the original +0xF60/+0xFD4 stores.
// - A volatile local EH-state probe emitted the state stores but still no FS:[0]
//   registration prefix, leaving the .text section shorter than the original;
//   rolled back so check_function can compare the raw-body baseline.
// - A volatile pointer makes the six-store distribution loop match the original
//   compact loop, but with the EH prefix still missing the section is too short
//   for check_function extraction; keep the comparable non-volatile baseline.
// - Current comparable baseline: compiles, 68.93% positional / 29.41% edit;
//   most remaining structural gap is the missing VC5 C++ EH registration prefix.
// - 2026-08-11: ABI/layout evidence confirms TacticalAIModule inheritance and
//   virtual destructor surfaces for the module, Group, and ResourceItem.  A
//   novtable-derived typed base restores the original FS:[0] EH prefix,
//   base-constructor call, and 0x100C layout; raw group/resource storage is
//   retained because the oracle places their explicit constructor calls after
//   the preceding scalar zeroing rather than at automatic member-init entry.
// - 2026-08-11: a volatile distribution cursor reaches the exact 782-byte
//   size and compact six-store loop, but changes the prologue/register basin;
//   removed from the living source as codegen-only evidence.  The remaining
//   mismatch is structural ordering/state placement around the group call and
//   the later distribution loop.
// - 2026-08-13: tested typed group/resource members with ordered initializer
//   lifetimes.  VC5 moved both calls into member initialization and removed
//   many zero stores, producing 505-510 bytes and worse CFG shape; rolled back.
// - 2026-08-13: tested placement construction in raw storage with compiler
//   vptr emission.  VC5 emitted the derived vptr at entry and produced 849
//   bytes; rolled back because the original stores its vptr after resource
//   setup.
// - 2026-08-13: corrected +0xD88 to the proven resourceMapping field and used
//   a natural indexed initialization for mapping, distributions, differences,
//   and build counts.  VC5 now emits the compact six-store loop and 782 bytes;
//   keep this readable source.  The remaining structural gap is the early
//   Group receiver LEA and delayed EH-state store near the first field zero.
// - 2026-08-17: revisited the first hunk with 20 distinct probes.  Direct,
//   scoped, reordered, reference, split, and late group-pointer forms did not
//   change the 782-byte code.  Moving the group call earlier reduced the byte
//   diff to 649, but changed the call and store order, so it is not valid.
//   Explicit vptr layouts, a typed group-link prefix, standard headers, and
//   base novtable context did not change the baseline.  Removing derived
//   novtable emitted an early vptr store and was rejected.  The clean baseline
//   remains 692 bytes different, with three ordered calls and exact size.
// Previous baseline blocker: the executable sets EH state zero immediately
// after the base call and state 0x0A before the group constructor. The raw
// reconstruction delayed the zero state until that call and moved the
// ResourceItem argument before five member stores.
// - 2026-08-22: modeled all ManagedIntArray fields as nontrivial members with
//   zeroing constructors and a real delete-and-zero destructor. Modeled the
//   inline group and resource objects as typed members. An ordered initializer
//   list now covers every member through neededResources(4), matching the
//   original EH transitions, zero-store order, and late constructor calls.
//   The exact check is 782/782 bytes, 3/3 calls, and 100% block coverage.
// - Exact-finish reversion: removing the ManagedIntArray destructor changed
//   the result to 639 differing bytes. Replacing the natural destructor body
//   with an empty body stayed exact, so the cleanup body is codegen-neutral in
//   this target. Kept the real delete-and-zero body for canonical semantics.
// - Exact-finish reversion: changing operator_delete to the canonical C++
//   global operator delete stayed exact and is retained.
// - Exact-finish context reductions: removing the unused operator_new
//   declaration and the unused TribeMainDecisionAIModule forward declaration
//   both stayed exact. Neither declaration is retained.
// - Main review rejected the exact variant because it used __declspec(novtable)
//   plus a raw vptr store. The natural virtual class emits the same 782-byte
//   body with 33 scheduling bytes different. Keep normal compiler ownership.
// - Accepted-drift audit: do not promote the natural virtual-class result. The
//   executable writes the derived vptr after the scalar stores through +0x1008.
//   The rebuild writes it after ResourceItem construction and before those
//   stores. This changes vptr publication and member-store fault order.

void __cdecl operator delete(void* p);
class TacticalAIModule { public: virtual ~TacticalAIModule(); char base[0xEC]; TacticalAIModule(void* owner, int player); };
struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    ManagedIntArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}
    ~ManagedIntArray() {
        if (this->value != 0) {
            operator delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }
};
struct UnitData { int id; int data1; int data2; int data3; int data4; int data5; };
class TacticalAIGroup { public: virtual ~TacticalAIGroup(); TacticalAIGroup* next; TacticalAIGroup* prev; char bytes[0x324]; TacticalAIGroup(); };
class ResourceItem { public: virtual ~ResourceItem(); char bytes[0x6C]; ResourceItem(int count); };
struct PlacementState { char pad_000[0x114]; int active; char pad_118[0x18]; };
struct AttackState { char pad_00[0x28]; int active; };

class TribeTacticalAIModule : public TacticalAIModule {
public:
    void* md; ManagedIntArray civilians; ManagedIntArray civilianExplorers; ManagedIntArray soldiers; ManagedIntArray ungroupedSoldiers;
    ManagedIntArray boats; ManagedIntArray warBoats; ManagedIntArray fishingBoats; ManagedIntArray tradeBoats; ManagedIntArray transportBoats; ManagedIntArray artifacts;
    int sn[226]; UnitData gatherers[50]; int numberGatherersValue; int desiredNumberGatherersValue; TacticalAIGroup groups;
    int groupIDValue; int numberGroupsValue; unsigned long lastGroupAttackTime; unsigned long lastGroupRebalanceTime; unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime; unsigned long lastScalingUpdateValue; int numberBuildUpdatesSkipped; int randomizedAttackSeparationTime;
    ManagedIntArray playersToAttack; ManagedIntArray playersToDefend; ManagedIntArray workingArea; ManagedIntArray unitsTaskedThisUpdate;
    int actualGathererDistribution[4]; int desiredGathererDistribution[4]; int resourceMappingValue[4]; int resourceDifferenceValue[4]; ResourceItem neededResources;
    int attackEnabledValue; int updateArea; int firstNeededResourceUpdateDone; int numberStoragePitsBuilt[4]; int numberGranariesBuilt[4]; int wonderInProgressValue; int wonderBuiltValue;
    PlacementState placementStateValue; int nextCivilianToTaskValue; int nextIdleSoldierGroupToTaskValue; int nextActiveSoldierGroupToTaskValue; int builtFirstStoragePit; int builtFirstGranary;
    unsigned long lastBuildTime; unsigned long lastAttackResponseBuildInsertionTime; unsigned long lastCoopTributeDemandTime; unsigned long lastCoopTributeGiftTime; unsigned long lastCoopAttackDemandTime;
    int zoomingToNextAge; unsigned long lastUngroupedSoldierTaskTime; AttackState attackStateValue; int hitsByPlayer[9]; int lastUpdateAreaTimeValue; int averageUpdateAreaTimeValue; int updateAreaAverageCount; int updateAreaAverageTotal;
    virtual ~TribeTacticalAIModule();
    TribeTacticalAIModule(void* param_1, int param_2);
};

TribeTacticalAIModule::TribeTacticalAIModule(void* param_1, int param_2)
    : TacticalAIModule(param_1, param_2),
      md(0),
      civilians(),
      civilianExplorers(),
      soldiers(),
      ungroupedSoldiers(),
      boats(),
      warBoats(),
      fishingBoats(),
      tradeBoats(),
      transportBoats(),
      artifacts(),
      numberGatherersValue(0),
      desiredNumberGatherersValue(0),
      groups(),
      groupIDValue(0),
      numberGroupsValue(0),
      lastGroupAttackTime(0),
      lastGroupRebalanceTime(0),
      lastAttackResponseTime(0),
      lastBoatAttackResponseTime(0),
      lastScalingUpdateValue(0),
      numberBuildUpdatesSkipped(0),
      randomizedAttackSeparationTime(0),
      playersToAttack(),
      playersToDefend(),
      workingArea(),
      unitsTaskedThisUpdate(),
      neededResources(4)
{
    int* piVar1;
    int iVar2;

    this->attackEnabledValue = 0;
    this->updateArea = 0;
    this->firstNeededResourceUpdateDone = 0;
    this->wonderInProgressValue = 0;
    this->wonderBuiltValue = 0;
    this->nextCivilianToTaskValue = -1;
    this->nextIdleSoldierGroupToTaskValue = -1;
    this->nextActiveSoldierGroupToTaskValue = -1;
    this->builtFirstStoragePit = 0;
    this->builtFirstGranary = 0;
    this->lastBuildTime = 0;
    this->lastAttackResponseBuildInsertionTime = 0;
    this->lastCoopTributeDemandTime = 0;
    this->lastCoopTributeGiftTime = 0;
    this->lastCoopAttackDemandTime = 0;
    this->zoomingToNextAge = 0;
    this->lastUngroupedSoldierTaskTime = 0;
    this->lastUpdateAreaTimeValue = -1;
    this->averageUpdateAreaTimeValue = -1;
    this->updateAreaAverageCount = 0;
    this->updateAreaAverageTotal = 0;
    for (iVar2 = 0; iVar2 != 4; iVar2 = iVar2 + 1) {
        this->resourceMappingValue[iVar2] = -1;
        this->desiredGathererDistribution[iVar2] = 0;
        this->actualGathererDistribution[iVar2] = 0;
        this->resourceDifferenceValue[iVar2] = 0;
        this->numberStoragePitsBuilt[iVar2] = 0;
        this->numberGranariesBuilt[iVar2] = 0;
    }

    piVar1 = this->sn;
    for (iVar2 = 0xe2; iVar2 != 0; iVar2 = iVar2 - 1) {
        *piVar1 = -1;
        piVar1 = piVar1 + 1;
    }
    piVar1 = this->hitsByPlayer;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 - 1) {
        *piVar1 = 0;
        piVar1 = piVar1 + 1;
    }
    piVar1 = &this->gatherers[0].data1;
    iVar2 = 0x32;
    do {
        ((UnitData*)(piVar1 - 1))->id = -1;
        *piVar1 = -1;
        piVar1[1] = -1;
        piVar1[2] = -1;
        piVar1[3] = -1;
        piVar1 = piVar1 + 6;
        iVar2 = iVar2 - 1;
    } while (iVar2 != 0);
    this->groups.next = &this->groups;
    this->groups.prev = &this->groups;
    this->placementStateValue.active = 0;
    this->attackStateValue.active = 0;
}
