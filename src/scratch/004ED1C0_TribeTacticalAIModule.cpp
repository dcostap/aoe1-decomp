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

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* p);
class TribeMainDecisionAIModule;

class TacticalAIModule { public: virtual ~TacticalAIModule(); char base[0xEC]; TacticalAIModule(void* owner, int player); };
struct ManagedIntArray { int* value; int numberValue; int desiredNumberValue; int maximumSizeValue; };
struct UnitData { int id; int data1; int data2; int data3; int data4; int data5; };
class TacticalAIGroup { public: virtual ~TacticalAIGroup(); TacticalAIGroup* next; TacticalAIGroup* prev; char bytes[0x324]; TacticalAIGroup(); };
class ResourceItem { public: virtual ~ResourceItem(); char bytes[0x6C]; ResourceItem(int count); };
struct PlacementState { char pad_000[0x114]; int active; char pad_118[0x18]; };
struct AttackState { char pad_00[0x28]; int active; };

class __declspec(novtable) TribeTacticalAIModule : public TacticalAIModule {
public:
    void* md; ManagedIntArray civilians; ManagedIntArray civilianExplorers; ManagedIntArray soldiers; ManagedIntArray ungroupedSoldiers;
    ManagedIntArray boats; ManagedIntArray warBoats; ManagedIntArray fishingBoats; ManagedIntArray tradeBoats; ManagedIntArray transportBoats; ManagedIntArray artifacts;
    int sn[226]; UnitData gatherers[50]; int numberGatherersValue; int desiredNumberGatherersValue; char groups[0x330];
    int groupIDValue; int numberGroupsValue; unsigned long lastGroupAttackTime; unsigned long lastGroupRebalanceTime; unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime; unsigned long lastScalingUpdateValue; int numberBuildUpdatesSkipped; int randomizedAttackSeparationTime;
    ManagedIntArray playersToAttack; ManagedIntArray playersToDefend; ManagedIntArray workingArea; ManagedIntArray unitsTaskedThisUpdate;
    int actualGathererDistribution[4]; int desiredGathererDistribution[4]; int neededResourceValue[4]; int resourceDifferenceValue[4]; char neededResources[0x70];
    int attackEnabledValue; int updateArea; int firstNeededResourceUpdateDone; int numberStoragePitsBuilt[4]; int numberGranariesBuilt[4]; int wonderInProgressValue; int wonderBuiltValue;
    PlacementState placementStateValue; int nextCivilianToTaskValue; int nextIdleSoldierGroupToTaskValue; int nextActiveSoldierGroupToTaskValue; int builtFirstStoragePit; int builtFirstGranary;
    unsigned long lastBuildTime; unsigned long lastAttackResponseBuildInsertionTime; unsigned long lastCoopTributeDemandTime; unsigned long lastCoopTributeGiftTime; unsigned long lastCoopAttackDemandTime;
    int zoomingToNextAge; unsigned long lastUngroupedSoldierTaskTime; AttackState attackStateValue; int hitsByPlayer[9]; int lastUpdateAreaTimeValue; int averageUpdateAreaTimeValue; int updateAreaAverageCount; int updateAreaAverageTotal;
    virtual ~TribeTacticalAIModule();
    TribeTacticalAIModule(void* param_1, int param_2);
};

TribeTacticalAIModule::TribeTacticalAIModule(void* param_1, int param_2)
    : TacticalAIModule(param_1, param_2)
{
    TacticalAIGroup* group;
    int* piVar1;
    int iVar2;

    this->md = 0;
    this->civilians.value = 0;
    this->civilians.numberValue = 0;
    this->civilians.desiredNumberValue = 0;
    this->civilians.maximumSizeValue = 0;
    this->civilianExplorers.value = 0;
    this->civilianExplorers.numberValue = 0;
    this->civilianExplorers.desiredNumberValue = 0;
    this->civilianExplorers.maximumSizeValue = 0;
    this->soldiers.value = 0;
    this->soldiers.numberValue = 0;
    this->soldiers.desiredNumberValue = 0;
    this->soldiers.maximumSizeValue = 0;
    this->ungroupedSoldiers.value = 0;
    this->ungroupedSoldiers.numberValue = 0;
    this->ungroupedSoldiers.desiredNumberValue = 0;
    this->ungroupedSoldiers.maximumSizeValue = 0;
    this->boats.value = 0;
    this->boats.numberValue = 0;
    this->boats.desiredNumberValue = 0;
    this->boats.maximumSizeValue = 0;
    this->warBoats.value = 0;
    this->warBoats.numberValue = 0;
    this->warBoats.desiredNumberValue = 0;
    this->warBoats.maximumSizeValue = 0;
    this->fishingBoats.value = 0;
    this->fishingBoats.numberValue = 0;
    this->fishingBoats.desiredNumberValue = 0;
    this->fishingBoats.maximumSizeValue = 0;
    this->tradeBoats.value = 0;
    this->tradeBoats.numberValue = 0;
    this->tradeBoats.desiredNumberValue = 0;
    this->tradeBoats.maximumSizeValue = 0;
    this->transportBoats.value = 0;
    this->transportBoats.numberValue = 0;
    this->transportBoats.desiredNumberValue = 0;
    this->transportBoats.maximumSizeValue = 0;
    this->artifacts.value = 0;
    this->artifacts.numberValue = 0;
    this->artifacts.desiredNumberValue = 0;
    this->artifacts.maximumSizeValue = 0;
    this->numberGatherersValue = 0;
    this->desiredNumberGatherersValue = 0;
    group = (TacticalAIGroup*)this->groups;
    group->TacticalAIGroup::TacticalAIGroup();
    this->groupIDValue = 0;
    this->numberGroupsValue = 0;
    this->lastGroupAttackTime = 0;
    this->lastGroupRebalanceTime = 0;
    this->lastAttackResponseTime = 0;
    this->lastBoatAttackResponseTime = 0;
    this->lastScalingUpdateValue = 0;
    this->numberBuildUpdatesSkipped = 0;
    this->randomizedAttackSeparationTime = 0;
    this->playersToAttack.value = 0;
    this->playersToAttack.numberValue = 0;
    this->playersToAttack.desiredNumberValue = 0;
    this->playersToAttack.maximumSizeValue = 0;
    this->playersToDefend.value = 0;
    this->playersToDefend.numberValue = 0;
    this->playersToDefend.desiredNumberValue = 0;
    this->playersToDefend.maximumSizeValue = 0;
    this->workingArea.value = 0;
    this->workingArea.numberValue = 0;
    this->workingArea.desiredNumberValue = 0;
    this->workingArea.maximumSizeValue = 0;
    this->unitsTaskedThisUpdate.value = 0;
    this->unitsTaskedThisUpdate.numberValue = 0;
    this->unitsTaskedThisUpdate.desiredNumberValue = 0;
    this->unitsTaskedThisUpdate.maximumSizeValue = 0;
    ((ResourceItem*)this->neededResources)->ResourceItem::ResourceItem(4);
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
    *(int*)this = 0x575788;

    piVar1 = this->desiredGathererDistribution;
    iVar2 = 4;
    do {
        piVar1[4] = -1;
        *piVar1 = 0;
        piVar1[-4] = 0;
        piVar1[8] = 0;
        piVar1[0x2b] = 0;
        piVar1[0x2f] = 0;
        piVar1 = piVar1 + 1;
        iVar2 = iVar2 - 1;
    } while (iVar2 != 0);

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
    ((TacticalAIGroup*)this->groups)->next = group;
    ((TacticalAIGroup*)this->groups)->prev = group;
    this->placementStateValue.active = 0;
    this->attackStateValue.active = 0;
}
