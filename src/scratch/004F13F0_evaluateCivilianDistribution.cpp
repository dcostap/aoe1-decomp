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
// - Left in scratch: current source is the best natural typed reconstruction. No inline asm or custom flags.

extern "C" double __cdecl ceil(double);

class RGE_Visible_Map {
public:
    float percentExplored();
};

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    int resize(int size);
};

class TribeInformationAIModule {
public:
    int fullyExploredZone(int zone);
    int numberGameIDsOwnedBy(int player, int gameID);
};

class PlayerLike {
public:
    char gap_000[0x38];
    RGE_Visible_Map* visibleMap;
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0xF0];
    PlayerLike* player;
    char gap_0F4[0xCEC - 0xF4];
    TribeInformationAIModule informationAI;
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    ManagedArray_int civilians;
    ManagedArray_int civilianExplorers;
    ManagedArray_int soldiers;
    ManagedArray_int ungroupedSoldiers;
    ManagedArray_int boats;
    ManagedArray_int warBoats;
    ManagedArray_int fishingBoats;
    ManagedArray_int tradeBoats;
    ManagedArray_int transportBoats;
    ManagedArray_int artifacts;
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
    ManagedArray_int playersToAttack;
    ManagedArray_int playersToDefend;
    ManagedArray_int workingArea;
    ManagedArray_int unitsTaskedThisUpdate;
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

void TribeTacticalAIModule::evaluateCivilianDistribution()
{
    int percentExplored;
    int numberItems;
    int desired;
    int gatherers;
    int maxGatherers;
    ManagedArray_int* list;
    int zero;

    percentExplored = (int)(this->md->player->visibleMap->percentExplored() * 100.0f);

    list = &this->playersToAttack;
    if (list->maximumSizeValue - 1 < 0) {
        list->resize(1);
    }
    numberItems = this->md->informationAI.numberGameIDsOwnedBy(-1, *list->value);

    if (this->civilians.numberValue >= 3) {
    list = &this->civilians;
    if (list->maximumSizeValue - 1 < 0) {
        list->resize(1);
    }
    if (this->md->informationAI.fullyExploredZone(*list->value) == 1) {
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
    this->desiredNumberGatherers = gatherers;
    if (this->sn[5] != -1 && gatherers > this->sn[5]) {
        this->desiredNumberGatherers = this->sn[5];
    }
    }
    else {
        desired = 1;
        if (this->civilians.numberValue == 1) {
            this->desiredNumberGatherers = 0;
        }
        else {
            this->desiredNumberGatherers = desired;
            maxGatherers = this->sn[5];
            if (maxGatherers != -1 && desired > maxGatherers) {
                this->desiredNumberGatherers = maxGatherers;
            }
            gatherers = this->desiredNumberGatherers;
            desired = this->civilians.numberValue - gatherers;
            if (this->sn[3] != -1 && desired > this->sn[3]) {
                desired = this->sn[3];
            }
        }
        this->civilianExplorers.desiredNumberValue = desired;
    }

    this->displayCivilianDistribution();
    this->updateGathererDistribution();
}
