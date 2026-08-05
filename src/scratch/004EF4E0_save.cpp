// VA: 004EF4E0 TribeTacticalAIModule::save
// PDB: taitacmd.cpp:2276-2426
//
// Canonical serialization order recovered from the executable:
// four resize-backed task arrays, scalar/gatherer data, six legacy arrays
// with their inline grow-on-read bodies, the fixed strategic-number table,
// four more grow-on-read arrays, distributions/resource values, the group
// sentinel list, and the remaining tactical state.
//
// Attempt log:
// - Baseline: named binary-proven tactical fields/arrays and ordered writes;
//   3347B, 94/94 calls, 0x8 frame, 91.13% shape.
// - Scoped loop/grow locals alone were codegen-neutral; a named `newMax` on
//   the first manual grow removed the artificial frame and improved size.
// - Guarded ManagedArray aliases for the four resize-backed arrays recovered
//   the original shared array-base accesses.
// - Reused the matched ManagedArray donor's `newMax` plus bounded `for` copy
//   form across all ten manual growth blocks. Current: 3230B, 94/94 calls,
//   0x0 frame, 99.41% shape, 822 positional bytes / 187 edit bytes.
// - Remaining first mismatch is the fixed `sn[226]` count loop: the source
//   initializes its write pointer before the count test, while original asm
//   tests the count before `lea [this+194h]`. A later unitsTasked growth tail
//   is one byte short and changes the final scalar-call alignment. Budget
//   exhausted; leave this readable period-plausible reconstruction in scratch.

void __cdecl rge_write(int file, void* data, int size);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class TacticalAIModule : public AIModule {
};

class TribeMainDecisionAIModule;

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int new_size);
};

struct UnitData {
    int data[6];
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    char data[0x324];

    int save(int file);
};

class ResourceItem {
public:
    char data[0x70];

    int value(int index);
};

struct PlacementState {
    char data[0x130];
};

struct AttackState {
    char data[0x2C];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
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
    ManagedArray_int playersToAttack;
    ManagedArray_int playersToDefend;
    ManagedArray_int workingArea;
    ManagedArray_int unitsTaskedThisUpdate;
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

    virtual int save(int file);
};

int TribeTacticalAIModule::save(int file)
{
    int tempInt;

    {
    int i;
    tempInt = this->civilians.numberValue;
    rge_write(file, &tempInt, 4);
    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray_int& arr = this->civilians;
        do {
            if (i > arr.maximumSizeValue - 1) {
                arr.resize(i + 1);
            }
            tempInt = arr.value[i];
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < this->civilians.numberValue);
    }
    }

    {
    int i;
    tempInt = this->civilianExplorers.numberValue;
    rge_write(file, &tempInt, 4);
    i = 0;
    if (this->civilianExplorers.numberValue > 0) {
        ManagedArray_int& arr = this->civilianExplorers;
        do {
            if (i > arr.maximumSizeValue - 1) {
                arr.resize(i + 1);
            }
            tempInt = arr.value[i];
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < this->civilianExplorers.numberValue);
    }
    }

    rge_write(file, &this->numberGatherersValue, 4);
    rge_write(file, &this->desiredNumberGatherersValue, 4);
    rge_write(file, this->gatherers, 0x4B0);

    {
    int i;
    tempInt = this->soldiers.numberValue;
    rge_write(file, &tempInt, 4);
    i = 0;
    if (this->soldiers.numberValue > 0) {
        ManagedArray_int& arr = this->soldiers;
        do {
            if (i > arr.maximumSizeValue - 1) {
                arr.resize(i + 1);
            }
            tempInt = arr.value[i];
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < this->soldiers.numberValue);
    }
    }

    {
    int i;
    tempInt = this->ungroupedSoldiers.numberValue;
    rge_write(file, &tempInt, 4);
    i = 0;
    if (this->ungroupedSoldiers.numberValue > 0) {
        ManagedArray_int& arr = this->ungroupedSoldiers;
        do {
            if (i > arr.maximumSizeValue - 1) {
                arr.resize(i + 1);
            }
            tempInt = arr.value[i];
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < this->ungroupedSoldiers.numberValue);
    }
    }

    {
    int k;
    tempInt = this->boats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->boats.numberValue > 0) {
        do {
            if (k > this->boats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->boats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->boats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->boats.value);
                    this->boats.value = newValue;
                    this->boats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->boats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->boats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->warBoats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->warBoats.numberValue > 0) {
        do {
            if (k > this->warBoats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->warBoats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->warBoats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->warBoats.value);
                    this->warBoats.value = newValue;
                    this->warBoats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->warBoats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->warBoats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->fishingBoats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->fishingBoats.numberValue > 0) {
        do {
            if (k > this->fishingBoats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->fishingBoats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->fishingBoats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->fishingBoats.value);
                    this->fishingBoats.value = newValue;
                    this->fishingBoats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->fishingBoats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->fishingBoats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->tradeBoats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->tradeBoats.numberValue > 0) {
        do {
            if (k > this->tradeBoats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->tradeBoats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->tradeBoats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->tradeBoats.value);
                    this->tradeBoats.value = newValue;
                    this->tradeBoats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->tradeBoats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->tradeBoats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->transportBoats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->transportBoats.numberValue > 0) {
        do {
            if (k > this->transportBoats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->transportBoats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->transportBoats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->transportBoats.value);
                    this->transportBoats.value = newValue;
                    this->transportBoats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->transportBoats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->transportBoats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->artifacts.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->artifacts.numberValue > 0) {
        do {
            if (k > this->artifacts.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->artifacts.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->artifacts.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->artifacts.value);
                    this->artifacts.value = newValue;
                    this->artifacts.maximumSizeValue = newMax;
                }
            }
            tempInt = this->artifacts.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->artifacts.numberValue);
    }
    }

    int* writePtr;
    int writeCount;
    {
    tempInt = 0xE2;
    rge_write(file, &tempInt, 4);
    writePtr = this->sn;
    writeCount = 0;
    if (writeCount < tempInt) {
        do {
            rge_write(file, writePtr, 4);
            writeCount++;
            writePtr++;
        } while (writeCount < tempInt);
    }
    }

    {
    int k;
    tempInt = this->playersToAttack.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->playersToAttack.numberValue > 0) {
        do {
            if (k > this->playersToAttack.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->playersToAttack.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->playersToAttack.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->playersToAttack.value);
                    this->playersToAttack.value = newValue;
                    this->playersToAttack.maximumSizeValue = newMax;
                }
            }
            tempInt = this->playersToAttack.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->playersToAttack.numberValue);
    }
    }

    {
    int k;
    tempInt = this->playersToDefend.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->playersToDefend.numberValue > 0) {
        do {
            if (k > this->playersToDefend.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->playersToDefend.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->playersToDefend.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->playersToDefend.value);
                    this->playersToDefend.value = newValue;
                    this->playersToDefend.maximumSizeValue = newMax;
                }
            }
            tempInt = this->playersToDefend.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->playersToDefend.numberValue);
    }
    }

    {
    int k;
    tempInt = this->workingArea.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->workingArea.numberValue > 0) {
        do {
            if (k > this->workingArea.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->workingArea.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->workingArea.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->workingArea.value);
                    this->workingArea.value = newValue;
                    this->workingArea.maximumSizeValue = newMax;
                }
            }
            tempInt = this->workingArea.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->workingArea.numberValue);
    }
    }

    {
    int k;
    tempInt = this->unitsTaskedThisUpdate.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->unitsTaskedThisUpdate.numberValue > 0) {
        do {
            if (k > this->unitsTaskedThisUpdate.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->unitsTaskedThisUpdate.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->unitsTaskedThisUpdate.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->unitsTaskedThisUpdate.value);
                    this->unitsTaskedThisUpdate.value = newValue;
                    this->unitsTaskedThisUpdate.maximumSizeValue = newMax;
                }
            }
            tempInt = this->unitsTaskedThisUpdate.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->unitsTaskedThisUpdate.numberValue);
    }
    }

    writePtr = this->actualGathererDistribution;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->desiredGathererDistribution;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->neededResourceValue;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->resourceDifferenceValue;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->numberStoragePitsBuilt;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->numberGranariesBuilt;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    {
    int i;
    i = 0;
    do {
        tempInt = this->neededResources.value(i);
        rge_write(file, &tempInt, 4);
        i++;
    } while (i < 4);
    }

    rge_write(file, &this->groupIDValue, 4);
    rge_write(file, &this->numberGroupsValue, 4);

    TacticalAIGroup* group;
    group = this->groups.next;
    while (group != &this->groups && group != 0) {
        group->save(file);
        group = group->next;
    }

    rge_write(file, &this->lastGroupAttackTime, 4);
    rge_write(file, &this->lastGroupRebalanceTime, 4);
    rge_write(file, &this->lastAttackResponseTime, 4);
    rge_write(file, &this->lastBoatAttackResponseTime, 4);
    rge_write(file, &this->lastScalingUpdateValue, 4);
    rge_write(file, &this->numberBuildUpdatesSkipped, 4);
    rge_write(file, &this->randomizedAttackSeparationTime, 4);
    rge_write(file, &this->attackEnabledValue, 4);
    rge_write(file, &this->updateArea, 4);
    rge_write(file, &this->wonderInProgressValue, 4);
    rge_write(file, &this->wonderBuiltValue, 4);
    rge_write(file, &this->placementStateValue, 0x130);
    rge_write(file, &this->nextCivilianToTaskValue, 4);
    rge_write(file, &this->nextIdleSoldierGroupToTaskValue, 4);
    rge_write(file, &this->nextActiveSoldierGroupToTaskValue, 4);
    rge_write(file, &this->builtFirstStoragePit, 4);
    rge_write(file, &this->builtFirstGranary, 4);
    rge_write(file, &this->lastBuildTime, 4);
    rge_write(file, &this->lastAttackResponseBuildInsertionTime, 4);
    rge_write(file, &this->lastCoopTributeDemandTime, 4);
    rge_write(file, &this->lastCoopTributeGiftTime, 4);
    rge_write(file, &this->lastCoopAttackDemandTime, 4);
    rge_write(file, &this->zoomingToNextAge, 4);
    rge_write(file, &this->lastUngroupedSoldierTaskTime, 4);
    rge_write(file, &this->attackStateValue, 0x2C);
    rge_write(file, this->hitsByPlayer, 0x24);

    return 1;
}
