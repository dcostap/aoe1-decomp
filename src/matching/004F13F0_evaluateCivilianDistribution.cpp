// 004F13F0 TribeTacticalAIModule::evaluateCivilianDistribution()
// Source: taitacmd.cpp lines 3202-3308
// Attempt log:
// - Reconstructed ManagedArray<int> as the proven four-int, 0x10-byte type and modeled the owning
//   TribeTacticalAIModule fields through zoomingToNextAge. This fixed the +0xFA4 field and gave the
//   natural typed baseline 530 bytes, with the original call order but duplicated final calls.
// - Kept the visible-map chain, shared ManagedArray pointer local, ceil expression, and zero local;
//   these reproduce the original prologue and main path through the low-count tail.
// - An early-return small-count spelling and a direct one-civilian explorer assignment were tested
//   and rolled back. The former was broad; the latter improved block coverage but kept duplicated calls.
// - Modeled the low-count result as desired=1, a gatherer cap, and one final explorer assignment.
//   This removed the extra display/update calls and recovered all 13 ordered calls, 3 jumps, 2 returns,
//   and 90.97% exact-block coverage. Best current output is 509 effective bytes versus 514, 73 strict
//   differing bytes, with the remaining drift localized to the low-count register and shared-tail shape.
// - A goto-based shared-tail spelling added a stack slot and caused broad drift, so it was rolled back.
//   Reloading gatherers, reversing the sn5 comparison, and naming the sn5 limit produced duplicate codegen.
// - A focused direct explorer-result assignment with a live one-count predicate added two final-call
//   sites and widened the function by 25 bytes, so it was rolled back.
// - A typed low-count field-order spelling assigned explorer and gatherer results in separate arms;
//   it reproduced that earlier 539-byte basin with two extra calls and was rolled back.
// - An initialized shared-tail result restored exact size, CFG, and call parity, but strict drift was
//   75 bytes versus the clean 73-byte source; reordering the sn5 read was codegen-duplicate, so rolled back.
// - A direct low-count field-order rewrite added a second civilian-count test and widened the function
//   to 530 bytes; it was rolled back because the first structural hunk moved to the setup call.
// - A natural typed field assignment in each low-count arm reproduced the 539-byte, two-extra-call
//   basin; it was rolled back because it split the shared call tail.
// - Tried the PDB-shaped low-count order: store explorers before the sn[3] gate and use a common
//   cap tail. This restored 514-byte size and 144 instructions, but VC5 hoisted the sn[3] load
//   before the explorer store and left 75 differing bytes; rolled back.
// - Left in scratch: current source is the best natural typed reconstruction. No inline asm or custom flags.
// - Rechecked this target from the original 514-byte body. Natural low-count field-store variants either
//   duplicated the two final calls or moved the outer tail; the min-style cap and declaration-order probes
//   were codegen duplicates or worse. Restored the pinned source: 509 bytes, 13 ordered calls, 90.97% exact
//   block coverage, and 73 differing bytes. The first structural drift remains at rebuilt +0x178 (004F1568),
//   where VC5 keeps the low-count cap in a different register/lifetime shape. No policy-invalid steering kept.
// - ManagedArray recovery pass, 2026-08-19: both manual element-zero grow/read
//   sequences now use the exact operator[] body. The emitted bytes are equal,
//   but method ownership is canonical and resize remains out of line.
// - Restored the binary-supported low-count local reuse from the decompiler:
//   one result holds 1, sn[5], then sn[3], and the computed explorer demand is
//   stored before its cap. This gives exact 514-byte size, 144 instructions,
//   13 calls, and CFG. The remaining 75 bytes are one localized register map.
// - Exact addObject and removeObject predecessor contexts did not change this
//   target. Register hints, branch-local result scopes, references, and store
//   sequencing were duplicates or worse. No compiler-context shim is retained.
// - Worker audit, 2026-08-22: Ghidra confirms a low-count civilian-count local
//   and one reused result local. Pre-branch count reuse, result-local reuse,
//   branch-local cap declarations, direct member rereads, assignment order,
//   and comma sequencing all emitted the same 514-byte, 75-byte-diff basin.
//   Restore the pinned source. The first unproved register divergence remains
//   the sn[5] load and later civilian-count reload at +0x178.
// - Accepted-drift audit: do not promote. In the low-count path, the executable
//   reloads civilians.numberValue after it updates desiredNumberGatherers. The
//   rebuild reuses the earlier count read. Concurrent count changes can produce
//   a different civilianExplorers result and different later stores.
// - Fresh contextual pass restored the exact same-TU TacticalAIModule virtual
//   inheritance. The emitted body is unchanged. The decompiler-shaped local
//   reuse, stored-field cap comparison, and inline numberCivilians accessor are
//   also codegen duplicates. The observable count-reread blocker remained.
// - Exact finish: use the canonical ManagedArray number and setDesiredNumber
//   inline methods at the low-count publication boundary. This preserves the
//   executable's civilian-count reread and keeps the explorer-demand store
//   before the sn[3] load. Direct field access loses one or both properties.

extern "C" double __cdecl ceil(double);

#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Visible_Map {
public:
    float percentExplored();
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    int resize(int size);

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1)
            this->resize(index + 1);
        return this->value[index];
    }

    const int number() const { return this->numberValue; }
    void setDesiredNumber(int number) { this->desiredNumberValue = number; }
};

class TribeInformationAIModule {
public:
    int fullyExploredZone(int zone);
    int numberGameIDsOwnedBy(int player, int gameID);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_004[0x34];
    RGE_Visible_Map* visible;
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0xF0];
    RGE_Player* player;
    char gap_0F4[0xCEC - 0xF4];
    TribeInformationAIModule informationAI;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_004[0xEC];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;
    int sn[226];
    char gap_51C[0x9CC - 0x51C];
    int numberGatherersValue;
    int desiredNumberGatherers;
    char groups[0x330];
    int groupIDValue;
    int numberGroupsValue;
    unsigned long lastGroupAttackTime;
    unsigned long lastGroupRebalanceTime;
    unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime;
    unsigned long lastScalingUpdateValue;
    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;
    ManagedArray<int> playersToAttack;
    ManagedArray<int> playersToDefend;
    ManagedArray<int> workingArea;
    ManagedArray<int> unitsTaskedThisUpdate;
    int actualGathererDistribution[4];
    int desiredGathererDistribution[4];
    int neededResourceValue[4];
    int resourceDifferenceValue[4];
    char neededResources[0x70];
    int attackEnabledValue;
    int updateArea;
    int firstNeededResourceUpdateDone;
    int numberStoragePitsBuilt[4];
    int numberGranariesBuilt[4];
    int wonderInProgressValue;
    int wonderBuiltValue;
    char placementStateValue[0x130];
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

    void evaluateCivilianDistribution();
    int numberSoldierExplorers();
    void displayCivilianDistribution();
    void updateGathererDistribution();
};
#endif

void TribeTacticalAIModule::evaluateCivilianDistribution()
{
    int percentExplored;
    int numberItems;
    int desired;
    int gatherers;
    ManagedArray<int>* list;
    int zero;

    percentExplored = (int)(this->md->player->visible->percentExplored() * 100.0f);

    list = &this->playersToAttack;
#ifdef TAITACMD_SHARED_CONTEXT
    if (list->maximumSizeValue - 1 < 0)
        list->resize(1);
    numberItems = this->md->informationAI.numberGameIDsOwnedBy(-1,
                                                               list->value[0]);
#else
    numberItems = this->md->informationAI.numberGameIDsOwnedBy(-1, (*list)[0]);
#endif

    if (this->civilians.numberValue >= 3) {
    list = &this->civilians;
#ifdef TAITACMD_SHARED_CONTEXT
    if (list->maximumSizeValue - 1 < 0)
        list->resize(1);
    if (this->md->informationAI.fullyExploredZone(list->value[0]) == 1) {
#else
    if (this->md->informationAI.fullyExploredZone((*list)[0]) == 1) {
#endif
        zero = 0;
        this->civilianExplorers.desiredNumberValue = (int)ceil((float)((double)this->sn[0] * this->civilians.numberValue) * 0.01f);
        desired = this->numberSoldierExplorers();
        if (desired + this->civilianExplorers.desiredNumberValue > this->sn[18]) {
            this->civilianExplorers.desiredNumberValue = this->sn[18] - desired;
        }
        if (this->sn[3] != -1 && this->civilianExplorers.desiredNumberValue > this->sn[3]) {
            this->civilianExplorers.desiredNumberValue = this->sn[3];
        }
    }
    else {
        zero = 0;
        this->civilianExplorers.desiredNumberValue = zero;
    }

    if (percentExplored >= this->sn[32] && numberItems > this->sn[145]) {
        desired = this->sn[35];
        if (this->civilianExplorers.desiredNumberValue > desired) {
            this->civilianExplorers.desiredNumberValue = desired;
        }
    }
    else if (percentExplored >= this->sn[179]) {
        desired = this->civilianExplorers.desiredNumberValue / 2;
        if (desired <= zero) {
            desired = zero;
        }
        this->civilianExplorers.desiredNumberValue = desired;
    }

    if (this->zoomingToNextAge == 1) {
        this->civilianExplorers.desiredNumberValue = zero;
    }

    gatherers = this->civilians.numberValue - this->civilianExplorers.desiredNumberValue;
    this->desiredNumberGatherersValue = gatherers;
    if (this->sn[5] != -1 && gatherers > this->sn[5]) {
        this->desiredNumberGatherersValue = this->sn[5];
    }
    }
    else {
        desired = 1;
        if (this->civilians.numberValue == 1) {
            this->desiredNumberGatherersValue = 0;
        }
        else {
            desired = this->sn[5];
            this->desiredNumberGatherersValue = 1;
            if (desired != -1 && desired < 1) {
                this->desiredNumberGatherersValue = desired;
            }
            // BINARY NOTE: Reread the count before publishing explorer demand.
            gatherers = this->civilians.number() -
                        this->desiredNumberGatherersValue;
            this->civilianExplorers.setDesiredNumber(gatherers);
            desired = this->sn[3];
            if (desired == -1 || gatherers <= desired)
                goto low_count_done;
        }
        this->civilianExplorers.desiredNumberValue = desired;
low_count_done:
        ;
    }

    this->displayCivilianDistribution();
    this->updateGathererDistribution();
}
