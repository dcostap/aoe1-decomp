#include "../include/TribeTacticalAIModule.h"

#include "../include/DiplomacyAIModule.h"
#include "../include/BuildAIModule.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/ResourceItem.h"
#include "../include/TribeBuildAIModule.h"
#include "../include/TribeMainDecisionAIModule.h"
#include "../include/TribeResourceAIModule.h"
#include "../include/UnitAIModule.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <cstring>
#include <cstdlib>
#include <new>

static void resetManagedArray(ManagedArray<int>& arr) {
    arr.value = nullptr;
    arr.numberValue = 0;
    arr.desiredNumberValue = 0;
    arr.maximumSizeValue = 0;
}

static void freeManagedArray(ManagedArray<int>& arr) {
    if (arr.value != nullptr) {
        delete[] arr.value;
        arr.value = nullptr;
    }
    arr.numberValue = 0;
    arr.desiredNumberValue = 0;
    arr.maximumSizeValue = 0;
}

static void ensureManagedArrayCapacity(ManagedArray<int>& arr, int requiredCount) {
    if (arr.maximumSizeValue >= requiredCount) {
        return;
    }
    int* newValues = new(std::nothrow) int[requiredCount];
    if (newValues == nullptr) {
        return;
    }
    for (int i = 0; i < arr.maximumSizeValue; ++i) {
        newValues[i] = arr.value[i];
    }
    delete[] arr.value;
    arr.value = newValues;
    arr.maximumSizeValue = requiredCount;
}

static void appendManagedArray(ManagedArray<int>& arr, int value) {
    if (arr.maximumSizeValue <= arr.numberValue) {
        ensureManagedArrayCapacity(arr, arr.numberValue + 1);
    }
    if (arr.maximumSizeValue <= arr.numberValue) {
        return;
    }
    arr.value[arr.numberValue] = value;
    arr.numberValue += 1;
}

static int containsManagedArray(const ManagedArray<int>& arr, int value) {
    for (int i = 0; i < arr.numberValue; ++i) {
        if (arr.maximumSizeValue <= i) {
            break;
        }
        if (arr.value[i] == value) {
            return 1;
        }
    }
    return 0;
}

static void initResourceItemWithCount(ResourceItem& item, int count) {
    item.next = nullptr;
    item.prev = nullptr;
    item.numberValue = count;
    for (int i = 0; i < 8; ++i) {
        if (i < count) {
            item.valueValue[i] = 0;
        } else {
            item.valueValue[i] = -1;
        }
        item.sortedValue[i] = -1;
        item.sortedIndexValue[i] = -1;
    }
}

static void appendManagedArrayUnique(ManagedArray<int>& arr, int value) {
    if (containsManagedArray(arr, value) == 0) {
        appendManagedArray(arr, value);
    }
}

static void readManagedArrayUnique(int fd, ManagedArray<int>& arr) {
    int count = 0;
    rge_read(fd, &count, 4);
    for (int i = 0; i < count; ++i) {
        int value = 0;
        rge_read(fd, &value, 4);
        appendManagedArrayUnique(arr, value);
    }
}

static void writeManagedArray(int fd, ManagedArray<int>& arr) {
    rge_write(fd, &arr.numberValue, 4);
    for (int i = 0; i < arr.numberValue; ++i) {
        if (arr.maximumSizeValue <= i) {
            ensureManagedArrayCapacity(arr, i + 1);
        }
        int value = arr.value[i];
        rge_write(fd, &value, 4);
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED1C0
TribeTacticalAIModule::TribeTacticalAIModule(void* param_1, int param_2)
    : TacticalAIModule(param_1, param_2) {
    this->md = nullptr;
    resetManagedArray(this->civilians);
    resetManagedArray(this->civilianExplorers);
    resetManagedArray(this->soldiers);
    resetManagedArray(this->ungroupedSoldiers);
    resetManagedArray(this->boats);
    resetManagedArray(this->warBoats);
    resetManagedArray(this->fishingBoats);
    resetManagedArray(this->tradeBoats);
    resetManagedArray(this->transportBoats);
    resetManagedArray(this->artifacts);
    this->numberGatherersValue = 0;
    this->desiredNumberGatherersValue = 0;
    this->groupIDValue = 0;
    this->numberGroupsValue = 0;
    this->lastGroupAttackTime = 0;
    this->lastGroupRebalanceTime = 0;
    this->lastAttackResponseTime = 0;
    this->lastBoatAttackResponseTime = 0;
    this->lastScalingUpdateValue = 0;
    this->numberBuildUpdatesSkipped = 0;
    this->randomizedAttackSeparationTime = 0;
    resetManagedArray(this->playersToAttack);
    resetManagedArray(this->playersToDefend);
    resetManagedArray(this->workingArea);
    resetManagedArray(this->unitsTaskedThisUpdate);
    initResourceItemWithCount(this->neededResources, 4);
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
    for (int i = 0; i < 4; ++i) {
        this->actualGathererDistribution[i] = 0;
        this->desiredGathererDistribution[i] = 0;
        this->neededResourceValue[i] = 0;
        this->resourceDifferenceValue[i] = -1;
        this->numberStoragePitsBuilt[i] = 0;
        this->numberGranariesBuilt[i] = 0;
    }
    for (int i = 0; i < 0xE2; ++i) {
        this->sn[i] = -1;
    }
    for (int i = 0; i < 9; ++i) {
        this->hitsByPlayer[i] = 0;
    }
    for (int i = 0; i < 0x32; ++i) {
        this->gatherers[i].id = -1;
        this->gatherers[i].data1 = -1;
        this->gatherers[i].data2 = -1;
        this->gatherers[i].data3 = -1;
        this->gatherers[i].target = -1;
        this->gatherers[i].lastTaskTime = 0;
    }
    this->groups.next = &this->groups;
    this->groups.prev = &this->groups;
    this->placementStateValue.active = 0;
    this->attackStateValue.active = 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED4F0
TribeTacticalAIModule::TribeTacticalAIModule(int param_1, int param_2)
    : TribeTacticalAIModule(nullptr, param_1) {
    struct OldUnitData16 {
        int id;
        int data1;
        int data2;
        int data3;
    };
    struct OldUnitData20 {
        int id;
        int data1;
        int data2;
        int data3;
        int target;
    };

    readManagedArrayUnique(param_2, this->civilians);
    readManagedArrayUnique(param_2, this->civilianExplorers);

    rge_read(param_2, &this->numberGatherersValue, 4);
    rge_read(param_2, &this->desiredNumberGatherersValue, 4);

    if (save_game_version < 7.19f) {
        if (save_game_version < 7.17f) {
            for (int i = 0; i < 50; ++i) {
                OldUnitData16 temp = {};
                rge_read(param_2, &temp, sizeof(OldUnitData16));
                this->gatherers[i].id = temp.id;
                this->gatherers[i].data1 = temp.data1;
                this->gatherers[i].data2 = temp.data2;
                this->gatherers[i].data3 = temp.data3;
                this->gatherers[i].target = -1;
                this->gatherers[i].lastTaskTime = 0;
            }
        } else {
            for (int i = 0; i < 50; ++i) {
                OldUnitData20 temp = {};
                rge_read(param_2, &temp, sizeof(OldUnitData20));
                this->gatherers[i].id = temp.id;
                this->gatherers[i].data1 = temp.data1;
                this->gatherers[i].data2 = temp.data2;
                this->gatherers[i].data3 = temp.data3;
                this->gatherers[i].target = temp.target;
                this->gatherers[i].lastTaskTime = 0;
            }
        }
    } else {
        rge_read(param_2, this->gatherers, 0x4B0);
    }

    readManagedArrayUnique(param_2, this->soldiers);
    if (save_game_version >= 2.3f) {
        readManagedArrayUnique(param_2, this->ungroupedSoldiers);
    }
    readManagedArrayUnique(param_2, this->boats);
    readManagedArrayUnique(param_2, this->warBoats);
    readManagedArrayUnique(param_2, this->fishingBoats);
    readManagedArrayUnique(param_2, this->tradeBoats);
    readManagedArrayUnique(param_2, this->transportBoats);
    if (save_game_version >= 1.4f) {
        readManagedArrayUnique(param_2, this->artifacts);
    }

    int strategicCount = 0;
    rge_read(param_2, &strategicCount, 4);
    for (int i = 0; i < strategicCount; ++i) {
        int value = 0;
        rge_read(param_2, &value, 4);
        if (i < 0xE2) {
            this->sn[i] = value;
        }
    }

    readManagedArrayUnique(param_2, this->playersToAttack);
    readManagedArrayUnique(param_2, this->playersToDefend);
    readManagedArrayUnique(param_2, this->workingArea);
    readManagedArrayUnique(param_2, this->unitsTaskedThisUpdate);

    for (int i = 0; i < 4; ++i) {
        rge_read(param_2, &this->actualGathererDistribution[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_read(param_2, &this->desiredGathererDistribution[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_read(param_2, &this->neededResourceValue[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_read(param_2, &this->resourceDifferenceValue[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_read(param_2, &this->numberStoragePitsBuilt[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_read(param_2, &this->numberGranariesBuilt[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        int value = 0;
        rge_read(param_2, &value, 4);
        this->neededResources.setValue(i, value);
    }

    rge_read(param_2, &this->groupIDValue, 4);
    rge_read(param_2, &this->numberGroupsValue, 4);
    int numberGroups = this->numberGroupsValue;
    for (int i = 0; i < numberGroups; ++i) {
        TacticalAIGroup* newGroup = createGroup(0);
        if (newGroup != nullptr) {
            newGroup->load(param_2);
        }
    }

    rge_read(param_2, &this->lastGroupAttackTime, 4);
    if (save_game_version >= 2.4f) {
        rge_read(param_2, &this->lastGroupRebalanceTime, 4);
    }
    rge_read(param_2, &this->lastAttackResponseTime, 4);
    rge_read(param_2, &this->lastBoatAttackResponseTime, 4);
    rge_read(param_2, &this->lastScalingUpdateValue, 4);
    rge_read(param_2, &this->numberBuildUpdatesSkipped, 4);
    rge_read(param_2, &this->randomizedAttackSeparationTime, 4);
    if (save_game_version >= 2.2f) {
        rge_read(param_2, &this->attackEnabledValue, 4);
    }
    rge_read(param_2, &this->updateArea, 4);
    if (save_game_version >= 6.1f) {
        rge_read(param_2, &this->wonderInProgressValue, 4);
        rge_read(param_2, &this->wonderBuiltValue, 4);
    }
    if (save_game_version < 6.2f) {
        std::memset(&this->placementStateValue, 0, sizeof(PlacementState));
    } else {
        rge_read(param_2, &this->placementStateValue, 0x130);
    }
    this->placementStateValue.active = 0;
    if (save_game_version >= 6.3f) {
        rge_read(param_2, &this->nextCivilianToTaskValue, 4);
    }
    if (save_game_version >= 6.4f) {
        rge_read(param_2, &this->nextIdleSoldierGroupToTaskValue, 4);
        rge_read(param_2, &this->nextActiveSoldierGroupToTaskValue, 4);
    }
    if (save_game_version >= 6.9f) {
        rge_read(param_2, &this->builtFirstStoragePit, 4);
        rge_read(param_2, &this->builtFirstGranary, 4);
    }
    if (save_game_version >= 6.95f) {
        rge_read(param_2, &this->lastBuildTime, 4);
        rge_read(param_2, &this->lastAttackResponseBuildInsertionTime, 4);
        rge_read(param_2, &this->lastCoopTributeDemandTime, 4);
    }
    if (save_game_version >= 7.18f) {
        rge_read(param_2, &this->lastCoopTributeGiftTime, 4);
    }
    if (save_game_version >= 6.96f) {
        rge_read(param_2, &this->zoomingToNextAge, 4);
    }
    if (save_game_version >= 6.98f) {
        rge_read(param_2, &this->lastCoopAttackDemandTime, 4);
    }
    if (save_game_version >= 6.993f) {
        rge_read(param_2, &this->lastUngroupedSoldierTaskTime, 4);
    }
    if (save_game_version < 7.04f) {
        std::memset(&this->attackStateValue, 0, sizeof(AttackState));
    } else {
        rge_read(param_2, &this->attackStateValue, 0x2C);
    }
    this->attackStateValue.active = 0;
    if (save_game_version < 7.15f) {
        std::memset(this->hitsByPlayer, 0, sizeof(this->hitsByPlayer));
    } else {
        rge_read(param_2, this->hitsByPlayer, 0x24);
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EEB40
TribeTacticalAIModule::~TribeTacticalAIModule() {
    removeAllGroups(-1);
    freeManagedArray(this->unitsTaskedThisUpdate);
    freeManagedArray(this->workingArea);
    freeManagedArray(this->playersToDefend);
    freeManagedArray(this->playersToAttack);
    freeManagedArray(this->artifacts);
    freeManagedArray(this->transportBoats);
    freeManagedArray(this->tradeBoats);
    freeManagedArray(this->fishingBoats);
    freeManagedArray(this->warBoats);
    freeManagedArray(this->boats);
    freeManagedArray(this->ungroupedSoldiers);
    freeManagedArray(this->soldiers);
    freeManagedArray(this->civilianExplorers);
    freeManagedArray(this->civilians);
}

int TribeTacticalAIModule::loggingHistory() { return TacticalAIModule::loggingHistory(); }
void TribeTacticalAIModule::setLogHistory(int param_1) { TacticalAIModule::setLogHistory(param_1); }
void TribeTacticalAIModule::toggleLogHistory() { TacticalAIModule::toggleLogHistory(); }
void TribeTacticalAIModule::setHistoryFilename(char* param_1) { TacticalAIModule::setHistoryFilename(param_1); }
int TribeTacticalAIModule::loggingCommonHistory() { return TacticalAIModule::loggingCommonHistory(); }
void TribeTacticalAIModule::setLogCommonHistory(int param_1) { TacticalAIModule::setLogCommonHistory(param_1); }
void TribeTacticalAIModule::toggleLogCommonHistory() { TacticalAIModule::toggleLogCommonHistory(); }
int TribeTacticalAIModule::loadState(char* param_1) { return TacticalAIModule::loadState(param_1); }
int TribeTacticalAIModule::saveState(char* param_1) { return TacticalAIModule::saveState(param_1); }
int TribeTacticalAIModule::gleanState(int param_1) { return TacticalAIModule::gleanState(param_1); }
int TribeTacticalAIModule::processMessage(AIModuleMessage* param_1) { return TacticalAIModule::processMessage(param_1); }
void TribeTacticalAIModule::setCallbackMessage(AIModuleMessage* param_1) { TacticalAIModule::setCallbackMessage(param_1); }
int TribeTacticalAIModule::filterOutMessage(AIModuleMessage* param_1) { return TacticalAIModule::filterOutMessage(param_1); }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EEE40
char* TribeTacticalAIModule::updateAreaName() {
    switch (this->updateArea) {
        case 0: return (char*)"Setup SolGroups";
        case 1: return (char*)"Eval CivDist";
        case 2: return (char*)"Task Civs";
        case 3: return (char*)"Setup BoatGroups";
        case 4: return (char*)"Fill BoatGroups";
        case 5: return (char*)"Task Boats";
        case 6: return (char*)"Fill SolGroups";
        case 7: return (char*)"Task IdleSol";
        case 8: return (char*)"Task ActSol";
        case 9: return (char*)"Playtasking";
        case 10: return (char*)"Task UngrpSol";
        case 11: return (char*)"Research";
        case 12: return (char*)"Train";
        case 13: return (char*)"BldLst Change";
        case 14: return (char*)"Help Build";
        case 15: return (char*)"Repair Bldg";
        case 16: return (char*)"Repair Wall";
        case 17: return (char*)"Build";
        case 18: return (char*)"Open Builds";
        case 19: return (char*)"Open Tasks";
        case 20: return (char*)"Food dropsite";
        case 21: return (char*)"BldLst Insertions";
        default: return (char*)"Invalid";
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EEF40
int TribeTacticalAIModule::update(int param_1) {
    (void)param_1;
    TribeMainDecisionAIModule* pTVar7 = this->md;
    if ((pTVar7 == nullptr) || (pTVar7->player == nullptr) || (pTVar7->player->world == nullptr)) {
        return 0;
    }
    unsigned long worldTime = pTVar7->player->world->world_time;
    if (static_cast<uint>(this->sn[99] * 60000) < worldTime - this->lastScalingUpdateValue) {
        int iVar2 = this->sn[0x1A] + this->sn[0x5E];
        this->sn[0x1A] = iVar2;
        if (iVar2 < 0) {
            this->sn[0x1A] = 0;
        }
        iVar2 = this->sn[0x10] + this->sn[0x5D];
        this->sn[0x10] = iVar2;
        if (iVar2 < 0) {
            this->sn[0x10] = 0;
        }
        iVar2 = this->sn[0x1A];
        if (iVar2 < this->sn[0x10]) {
            this->sn[0x10] = iVar2;
        }
        if (iVar2 < this->sn[0x10]) {
            this->sn[0x1A] = this->sn[0x10];
        }
        iVar2 = this->sn[0x1E] << 1;
        this->sn[0x1E] = iVar2;
        if (iVar2 < 0) {
            this->sn[0x1E] = 0;
        }
        if (this->sn[0x1E] > 100) {
            this->sn[0x1E] = 100;
        }
        iVar2 = this->sn[0x1F] << 1;
        this->sn[0x1F] = iVar2;
        if (iVar2 < 0) {
            this->sn[0x1F] = 0;
        }
        if (this->sn[0x1F] > 100) {
            this->sn[0x1F] = 100;
        }
        iVar2 = this->sn[0x5B] << 1;
        this->sn[0x5B] = iVar2;
        if (iVar2 < 0) {
            this->sn[0x5B] = 0;
        }
        if (this->sn[0x5B] > 100) {
            this->sn[0x5B] = 100;
        }
        this->lastScalingUpdateValue = worldTime;
    }
    this->unitsTaskedThisUpdate.numberValue = 0;
    if (static_cast<uint>(this->sn[0x68]) <= (worldTime / 1000)) {
        enableAttack(2);
    }

    DiplomacyAIModule* diplomacy = reinterpret_cast<DiplomacyAIModule*>(this->md->diplomacyAI);
    int mostHatedPlayer = diplomacy->mostHated(this->sn[0x7C], this->sn[0x80], this->sn[0xBC], this->sn[0xC3]);
    int mostLikedPlayer = diplomacy->mostLiked(this->sn[0x7C], this->sn[0x80]);

    this->playersToAttack.numberValue = 0;
    ensureManagedArrayCapacity(this->playersToAttack, 1);
    appendManagedArray(this->playersToAttack, mostHatedPlayer);

    this->playersToDefend.numberValue = 0;
    ensureManagedArrayCapacity(this->playersToDefend, 1);
    int currentPlayerNumber = this->md->player->id;
    appendManagedArray(this->playersToDefend, currentPlayerNumber);
    if ((mostHatedPlayer != mostLikedPlayer) && (containsManagedArray(this->playersToDefend, mostLikedPlayer) == 0)) {
        appendManagedArray(this->playersToDefend, mostLikedPlayer);
    }

    for (int iVar5 = 1; iVar5 < this->md->player->world->player_num; ++iVar5) {
        if (iVar5 == currentPlayerNumber) {
            continue;
        }
        if (iVar5 == mostHatedPlayer) {
            if ((diplomacy->isEnemy(iVar5) == 0) && (diplomacy->isChangeable(iVar5) != 0) &&
                (diplomacy->stance(iVar5, 0) > 0x4A)) {
                diplomacy->setRelation(iVar5, 3);
            }
        } else if (iVar5 == mostLikedPlayer) {
            if ((diplomacy->isAlly(iVar5) == 0) && (diplomacy->isChangeable(iVar5) != 0) &&
                (diplomacy->stance(iVar5, 2) > 0x4A)) {
                diplomacy->setRelation(iVar5, 0);
            }
        } else {
            if ((this->sn[0x1D] < diplomacy->stance(iVar5, 2)) && (diplomacy->isChangeable(iVar5) != 0)) {
                if (diplomacy->isAlly(iVar5) == 0) {
                    diplomacy->setRelation(iVar5, 0);
                }
            } else if ((diplomacy->isNeutral(iVar5) == 0) && (diplomacy->isChangeable(iVar5) != 0)) {
                diplomacy->setRelation(iVar5, 1);
            }
        }
    }

    doSomething();
    this->unitsTaskedThisUpdate.numberValue = 0;
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EF4D0
void TribeTacticalAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EF4E0
int TribeTacticalAIModule::save(int param_1) {
    writeManagedArray(param_1, this->civilians);
    writeManagedArray(param_1, this->civilianExplorers);
    rge_write(param_1, &this->numberGatherersValue, 4);
    rge_write(param_1, &this->desiredNumberGatherersValue, 4);
    rge_write(param_1, this->gatherers, 0x4B0);
    writeManagedArray(param_1, this->soldiers);
    writeManagedArray(param_1, this->ungroupedSoldiers);
    writeManagedArray(param_1, this->boats);
    writeManagedArray(param_1, this->warBoats);
    writeManagedArray(param_1, this->fishingBoats);
    writeManagedArray(param_1, this->tradeBoats);
    writeManagedArray(param_1, this->transportBoats);
    writeManagedArray(param_1, this->artifacts);

    int strategicCount = 0xE2;
    rge_write(param_1, &strategicCount, 4);
    for (int i = 0; i < strategicCount; ++i) {
        rge_write(param_1, &this->sn[i], 4);
    }

    writeManagedArray(param_1, this->playersToAttack);
    writeManagedArray(param_1, this->playersToDefend);
    writeManagedArray(param_1, this->workingArea);
    writeManagedArray(param_1, this->unitsTaskedThisUpdate);

    for (int i = 0; i < 4; ++i) {
        rge_write(param_1, &this->actualGathererDistribution[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_write(param_1, &this->desiredGathererDistribution[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_write(param_1, &this->neededResourceValue[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_write(param_1, &this->resourceDifferenceValue[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_write(param_1, &this->numberStoragePitsBuilt[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        rge_write(param_1, &this->numberGranariesBuilt[i], 4);
    }
    for (int i = 0; i < 4; ++i) {
        int value = this->neededResources.value(i);
        rge_write(param_1, &value, 4);
    }

    rge_write(param_1, &this->groupIDValue, 4);
    rge_write(param_1, &this->numberGroupsValue, 4);
    for (TacticalAIGroup* current = this->groups.next;
         (current != &this->groups) && (current != nullptr);
         current = current->next) {
        current->save(param_1);
    }

    rge_write(param_1, &this->lastGroupAttackTime, 4);
    rge_write(param_1, &this->lastGroupRebalanceTime, 4);
    rge_write(param_1, &this->lastAttackResponseTime, 4);
    rge_write(param_1, &this->lastBoatAttackResponseTime, 4);
    rge_write(param_1, &this->lastScalingUpdateValue, 4);
    rge_write(param_1, &this->numberBuildUpdatesSkipped, 4);
    rge_write(param_1, &this->randomizedAttackSeparationTime, 4);
    rge_write(param_1, &this->attackEnabledValue, 4);
    rge_write(param_1, &this->updateArea, 4);
    rge_write(param_1, &this->wonderInProgressValue, 4);
    rge_write(param_1, &this->wonderBuiltValue, 4);
    rge_write(param_1, &this->placementStateValue, 0x130);
    rge_write(param_1, &this->nextCivilianToTaskValue, 4);
    rge_write(param_1, &this->nextIdleSoldierGroupToTaskValue, 4);
    rge_write(param_1, &this->nextActiveSoldierGroupToTaskValue, 4);
    rge_write(param_1, &this->builtFirstStoragePit, 4);
    rge_write(param_1, &this->builtFirstGranary, 4);
    rge_write(param_1, &this->lastBuildTime, 4);
    rge_write(param_1, &this->lastAttackResponseBuildInsertionTime, 4);
    rge_write(param_1, &this->lastCoopTributeDemandTime, 4);
    rge_write(param_1, &this->lastCoopTributeGiftTime, 4);
    rge_write(param_1, &this->zoomingToNextAge, 4);
    rge_write(param_1, &this->lastCoopAttackDemandTime, 4);
    rge_write(param_1, &this->lastUngroupedSoldierTaskTime, 4);
    rge_write(param_1, &this->attackStateValue, 0x2C);
    rge_write(param_1, this->hitsByPlayer, 0x24);
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F6100
int TribeTacticalAIModule::numberCivilians() const { return this->civilians.numberValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F6110
int TribeTacticalAIModule::numberCivilianExplorers() const { return this->civilianExplorers.numberValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F6120
int TribeTacticalAIModule::numberGatherers() const { return this->numberGatherersValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F6130
int TribeTacticalAIModule::desiredNumberCivilianExplorers() const { return this->civilianExplorers.desiredNumberValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F6140
int TribeTacticalAIModule::desiredNumberGatherers() const { return this->desiredNumberGatherersValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F6150
int TribeTacticalAIModule::numberSoldiers() const { return this->soldiers.numberValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F6170
int TribeTacticalAIModule::numberBoats() const { return this->boats.numberValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F6160
int TribeTacticalAIModule::numberSoldierExplorers() {
    int count = 0;
    for (TacticalAIGroup* current = this->groups.next;
         (current != &this->groups) && (current != nullptr);
         current = current->next) {
        if (current->type() == 0x66) {
            count += current->numberUnits();
        }
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F0180
void TribeTacticalAIModule::logGroupDebug(int param_1, char* param_2, ...) {
    (void)param_1;
    (void)param_2;
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F0BC0. clearArea transliteration is blocked on missing pathing/task helpers.
int TribeTacticalAIModule::clearArea(int param_1, float param_2, float param_3, float param_4, float param_5) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    return 0;
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F0D70. addObject transliteration is blocked on missing classification/task helpers.
void TribeTacticalAIModule::addObject(RGE_Static_Object* param_1) {
    if ((param_1 != nullptr) && (param_1->master_obj != nullptr) && (param_1->master_obj->object_group == 4)) {
        appendManagedArrayUnique(this->civilians, param_1->id);
    }
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F1090. removeObject transliteration is blocked on missing removeFromTaskLists helper.
void TribeTacticalAIModule::removeObject(int param_1) {
    ManagedArray<int>* arrays[] = {&this->civilians,        &this->civilianExplorers, &this->soldiers,
                                   &this->ungroupedSoldiers, &this->boats,             &this->warBoats,
                                   &this->fishingBoats,      &this->tradeBoats,        &this->transportBoats,
                                   &this->artifacts};
    for (ManagedArray<int>* arr : arrays) {
        for (int i = 0; i < arr->numberValue && i < arr->maximumSizeValue; ++i) {
            if (arr->value[i] != param_1) {
                continue;
            }
            for (int j = i; j + 1 < arr->numberValue && j + 1 < arr->maximumSizeValue; ++j) {
                arr->value[j] = arr->value[j + 1];
            }
            arr->numberValue -= 1;
            break;
        }
    }
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F13F0. evaluateCivilianDistribution transliteration is blocked on missing info-AI helpers.
void TribeTacticalAIModule::evaluateCivilianDistribution() {}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F1600. taskCivilians transliteration is blocked on missing gatherer/task helpers.
int TribeTacticalAIModule::taskCivilians(unsigned long param_1, unsigned long param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F1E10. taskIdleSoldiers transliteration is blocked on missing tactical helper graph.
void TribeTacticalAIModule::taskIdleSoldiers(unsigned long param_1, unsigned long param_2) {
    (void)param_1;
    (void)param_2;
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F21F0. taskActiveSoldiers transliteration is blocked on missing targeting/combat helpers.
void TribeTacticalAIModule::taskActiveSoldiers(unsigned long param_1, unsigned long param_2) {
    (void)param_1;
    (void)param_2;
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F4760. playTaskSoldiers transliteration is blocked on missing playbook/target helpers.
void TribeTacticalAIModule::playTaskSoldiers(unsigned long param_1, unsigned long param_2) {
    (void)param_1;
    (void)param_2;
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F4AA0. taskUngroupedSoldiers transliteration is blocked on missing group creation helpers.
void TribeTacticalAIModule::taskUngroupedSoldiers() {}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F4D90. taskBoats transliteration is blocked on missing transport/attack helpers.
void TribeTacticalAIModule::taskBoats() {}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F57C0. evaluateOpenTasks transliteration is blocked on missing tactical helper graph.
void TribeTacticalAIModule::evaluateOpenTasks() {}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F5FB0. evaluateBuildListInsertions transliteration is blocked on missing TribeBuildAIModule::insert wrapper.
void TribeTacticalAIModule::evaluateBuildListInsertions() {
    // TODO: STUB - requires unresolved md->buildAI wrapper APIs in current headers.
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F6180. Full parity pending.
int TribeTacticalAIModule::neededResource(int param_1) const {
    if ((param_1 >= 0) && (param_1 < 4)) {
        return this->neededResourceValue[param_1];
    }
    return -1;
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F61A0. Full parity pending.
int TribeTacticalAIModule::neededResourceAmount(int param_1) const {
    if ((param_1 >= 0) && (param_1 < 4)) {
        return this->neededResources.value(this->neededResourceValue[param_1]);
    }
    return -1;
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F61D0. Full parity pending.
void TribeTacticalAIModule::detask(int param_1) {
    if (param_1 == -1) {
        return;
    }
    // TODO: STUB - removeFromTaskLists/stopUnit helpers are not transliterated yet.
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F6210. Full parity pending.
int TribeTacticalAIModule::strategicNumber(int param_1) {
    if ((param_1 >= 0) && (param_1 < 0xE2)) {
        return this->sn[param_1];
    }
    return -1;
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F6230. Full parity pending.
void TribeTacticalAIModule::setStrategicNumber(int param_1, int param_2) {
    if ((param_1 < 0) || (param_1 >= 0xE2)) {
        return;
    }
    this->sn[param_1] = param_2;
    if ((param_1 == 0x75) || (param_1 == 0x76) || (param_1 == 0x77) || (param_1 == 0x78) ||
        (param_1 == 0x9C) || (param_1 == 0x9D) || (param_1 == 0x9E) || (param_1 == 0x9F)) {
        if (param_2 < 0) {
            this->sn[param_1] = 0;
        } else if (param_2 > 100) {
            this->sn[param_1] = 100;
        }
    }
    if (param_1 == 0x69) {
        // TODO: STUB - TribeInformationAIModule::setSaveLearnInformation is not declared yet.
    }
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F62C0. Full parity pending.
void TribeTacticalAIModule::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    (void)param_2;
    (void)param_5;
    (void)param_6;
    if ((this->md == nullptr) || (this->md->player == nullptr) || (this->md->player->world == nullptr)) {
        return;
    }

    RGE_Game_World* world = this->md->player->world;
    RGE_Static_Object* callerObject = world->object(param_1);
    if ((param_3 != 0x72) && (param_3 != 0x74) && (callerObject == nullptr)) {
        return;
    }

    if (param_3 == 0x72) {
        // TODO: STUB - artifact capture response branch (artifactToCapture/defender tasking) is not transliterated yet.
        return;
    }
    if (param_3 == 0x74) {
        // TODO: STUB - ruin capture response branch (ruinToCapture/defender tasking) is not transliterated yet.
        return;
    }
    if (param_3 != 0x201) {
        return;
    }

    RGE_Static_Object* targetObj = world->object((int)param_4);
    if ((targetObj == nullptr) || (targetObj->owner == nullptr)) {
        return;
    }
    const int targetOwner = targetObj->owner->id;
    if (targetOwner == this->md->player->id) {
        return;
    }
    if (callerObject == nullptr) {
        return;
    }
    if (targetOwner == 0) {
        if ((this->zoomingToNextAge != 0) && (targetObj->master_obj != nullptr)) {
            const short masterObjectID = targetObj->master_obj->id;
            if ((masterObjectID == 0x7E) || (masterObjectID == 0x59)) {
                return;
            }
        }
        // TODO: STUB - dealWithGAIAAttacker branch is not transliterated yet.
        return;
    }

    UnitAIModule* callerAI = callerObject->unitAIValue;
    if ((callerAI == nullptr) || (callerAI->currentOrderValue != 0x2C1)) {
        if (world->difficultyLevelValue == 3) {
            this->sn[0x68] -= 2;
        } else if (world->difficultyLevelValue == 4) {
            this->sn[0x68] -= 1;
        } else {
            enableAttack(3);
        }
    }
    // TODO: STUB - checkForAttackResponseBuildInsertions is not transliterated yet.

    if ((targetOwner >= 0) && (targetOwner < 9)) {
        this->hitsByPlayer[targetOwner] += 1;
    }

    DiplomacyAIModule* diplomacy = reinterpret_cast<DiplomacyAIModule*>(this->md->diplomacyAI);
    if (targetObj->owner->computerPlayer() == 0) {
        if ((targetOwner >= 0) && (targetOwner < 9) && (this->sn[0xDD] <= this->hitsByPlayer[targetOwner]) &&
            (this->sn[0xD7] == 1)) {
            diplomacy->setChangeable(targetOwner, 1);
            diplomacy->setStance(targetOwner, 0, 100);
            diplomacy->setRelation(targetOwner, 3);
            diplomacy->setChangeable(targetOwner, 0);
        } else {
            diplomacy->changeStance(targetOwner, 2, this->sn[0xB2]);
            diplomacy->changeStance(targetOwner, 0, this->sn[0xB2]);
        }
    } else if (this->md->player->isAlly(targetOwner) == 1) {
        diplomacy->setChangeable(targetOwner, 1);
        diplomacy->setStance(targetOwner, 0, 100);
        diplomacy->setRelation(targetOwner, 3);
        diplomacy->setChangeable(targetOwner, 0);
    }

    if ((this->sn[0x7C] > 0) && (this->sn[0x80] == targetOwner) && (this->sn[0x85] == 1)) {
        // TODO: STUB - revokeTributeAlliance is not declared in current TribeMainDecisionAIModule header.
    }

    if ((this->lastAttackResponseTime != 0) &&
        (((world->world_time - this->lastAttackResponseTime) / 1000) < (unsigned long)this->sn[0x30])) {
        return;
    }

    // TODO: STUB - storeAttackMemory, readyAndIdleGroup, and attacker/defender response tasking are not transliterated yet.
}

// TODO: Source of truth: taitacmd.cpp.decomp @ 0x004F0190. doSomething is partially transliterated; remaining update-area handlers are still pending.
int TribeTacticalAIModule::doSomething() {
    if ((this->md == nullptr) || (this->md->player == nullptr) || (this->md->player->world == nullptr)) {
        return 1;
    }

    if ((this->updateArea < 0) || (this->updateArea > 0x15)) {
        this->updateArea = 0;
    }

    RGE_Game_World* world = this->md->player->world;
    const unsigned long startTime = world->world_time;
    const unsigned long availableTime = world->availableComputerPlayerUpdateTime;

    if (availableTime == 0) {
        return 1;
    }

    while (true) {
        const unsigned long updateAreaStartTime = world->world_time;
        bool incUpdateArea = true;

        switch (this->updateArea) {
            case 0:
                // TODO: STUB - setupSoldierGroups is not transliterated yet.
                break;
            case 1:
                if (this->civilians.numberValue > 0) {
                    if (this->firstNeededResourceUpdateDone == 0) {
                        this->firstNeededResourceUpdateDone = 1;
                        // TODO: STUB - updateNeededResources is not transliterated yet.
                    }
                    evaluateCivilianDistribution();
                }
                break;
            case 2:
                taskCivilians(startTime, availableTime);
                if (this->nextCivilianToTaskValue != -1) {
                    incUpdateArea = false;
                }
                break;
            case 3:
                if (this->boats.numberValue > 0) {
                    // TODO: STUB - setupBoatGroups is not transliterated yet.
                }
                break;
            case 4:
                if (this->boats.numberValue > 0) {
                    // TODO: STUB - fillBoatGroups is not transliterated yet.
                }
                break;
            case 5:
                if (this->boats.numberValue > 0) {
                    taskBoats();
                }
                break;
            case 6:
                if ((this->boats.numberValue > 0) || (this->soldiers.numberValue > 0)) {
                    // TODO: STUB - fillSoldierGroups is not transliterated yet.
                }
                break;
            case 7:
                if ((this->boats.numberValue > 0) || (this->soldiers.numberValue > 0) ||
                    (this->artifacts.numberValue > 0)) {
                    taskIdleSoldiers(startTime, availableTime);
                    if (this->nextIdleSoldierGroupToTaskValue != -1) {
                        incUpdateArea = false;
                    }
                }
                break;
            case 8:
                if ((this->boats.numberValue > 0) || (this->soldiers.numberValue > 0) ||
                    (this->artifacts.numberValue > 0)) {
                    taskActiveSoldiers(startTime, availableTime);
                    if (this->nextActiveSoldierGroupToTaskValue != -1) {
                        incUpdateArea = false;
                    }
                }
                break;
            case 9:
                if (this->soldiers.numberValue > 0) {
                    playTaskSoldiers(startTime, availableTime);
                }
                break;
            case 0xA:
                // TODO: STUB - saveTheTown lookup/tasking flow is not transliterated yet.
                break;
            case 0xB:
                this->numberBuildUpdatesSkipped += 1;
                // TODO: STUB - build-list research tasking is not transliterated yet.
                break;
            case 0xC:
                // TODO: STUB - train tasking flow is not transliterated yet.
                break;
            case 0xD:
                // TODO: STUB - build placement dispatch/updateNeededResources flow is not transliterated yet.
                break;
            case 0xE:
                // TODO: STUB - wonder builder tasking flow is not transliterated yet.
                break;
            case 0xF:
                // TODO: STUB - damaged building repairer tasking flow is not transliterated yet.
                break;
            case 0x10:
                // TODO: STUB - damaged wall repairer tasking flow is not transliterated yet.
                break;
            case 0x11:
                // TODO: STUB - generic builder tasking flow is not transliterated yet.
                break;
            case 0x12:
                // TODO: STUB - placement continuation/taskBuilder integration not transliterated yet.
                if (this->placementStateValue.active == 1) {
                    incUpdateArea = false;
                }
                break;
            case 0x13:
                evaluateOpenTasks();
                break;
            case 0x14:
                // TODO: STUB - dropsite refresh check is not transliterated yet.
                break;
            case 0x15: {
                evaluateBuildListInsertions();
                // TODO: STUB - unskipBuildList is not transliterated yet.
                const unsigned long now = world->world_time;
                this->lastUpdateAreaTimeValue = (int)(now - updateAreaStartTime);
                this->updateAreaAverageTotal += this->lastUpdateAreaTimeValue;
                this->updateAreaAverageCount += 1;
                if (this->updateAreaAverageCount > 0x13) {
                    this->averageUpdateAreaTimeValue = this->updateAreaAverageTotal / this->updateAreaAverageCount;
                    this->updateAreaAverageTotal = 0;
                    this->updateAreaAverageCount = 0;
                }
                this->updateArea = 0;
                world->selectNextComputerPlayer(3);
                return 1;
            }
            default:
                // TODO: STUB - remaining update-area handlers are not transliterated yet.
                break;
        }

        const unsigned long now = world->world_time;
        this->lastUpdateAreaTimeValue = (int)(now - updateAreaStartTime);
        this->updateAreaAverageTotal += this->lastUpdateAreaTimeValue;
        this->updateAreaAverageCount += 1;
        if (this->updateAreaAverageCount > 0x13) {
            this->averageUpdateAreaTimeValue = this->updateAreaAverageTotal / 0x14;
            this->updateAreaAverageTotal = 0;
            this->updateAreaAverageCount = 0;
        }

        if (incUpdateArea) {
            this->updateArea += 1;
            if (this->updateArea > 0x15) {
                this->updateArea = 0;
            }
        }

        if ((now - startTime) >= availableTime) {
            break;
        }
        if (now == updateAreaStartTime) {
            break;
        }
    }

    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00501660
void TribeTacticalAIModule::enableAttack(int param_1) {
    if ((this->attackEnabledValue != 1) && ((this->sn[0x86] == 0) || (this->sn[0x86] == param_1))) {
        this->attackEnabledValue = 1;
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500260
TacticalAIGroup* TribeTacticalAIModule::createGroup(int param_1) {
    TacticalAIGroup* newGroup = new(std::nothrow) TacticalAIGroup();
    if (newGroup == nullptr) {
        return nullptr;
    }
    newGroup->next = &this->groups;
    newGroup->prev = this->groups.prev;
    newGroup->prev->next = newGroup;
    this->groups.prev = newGroup;
    if (param_1 == 1) {
        int newGroupId = this->groupIDValue;
        this->groupIDValue = newGroupId + 1;
        newGroup->setID(newGroupId);
        this->numberGroupsValue += 1;
    }
    return newGroup;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500320
int TribeTacticalAIModule::removeGroup(int param_1) {
    TacticalAIGroup* current = this->groups.next;
    if (current != &this->groups) {
        while (current != nullptr) {
            if (current->id() == param_1) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                this->numberGroupsValue -= 1;
                return 1;
            }
            current = current->next;
            if (current == &this->groups) {
                return 0;
            }
        }
    }
    return 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005003A0
int TribeTacticalAIModule::removeAllGroups(int param_1) {
    TacticalAIGroup* current = this->groups.next;
    if (current != &this->groups) {
        do {
            if (current == nullptr) {
                return 1;
            }
            if ((current->type() == param_1) || (param_1 == -1)) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                TacticalAIGroup* previous = current->prev;
                delete current;
                current = previous;
                this->numberGroupsValue -= 1;
            }
            current = current->next;
        } while (current != &this->groups);
    }
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500420
TacticalAIGroup* TribeTacticalAIModule::group(int param_1, int param_2, int param_3, int param_4) {
    TacticalAIGroup* current = this->groups.next;
    if (current != &this->groups) {
        while (current != nullptr) {
            if (((param_1 == -1) || (current->id() == param_1)) &&
                ((param_2 == -1) || (current->type() == param_2)) &&
                ((param_3 == -1) || (current->action() == param_3)) &&
                ((param_4 == -1) || (current->target() == param_4))) {
                return current;
            }
            current = current->next;
            if (current == &this->groups) {
                return nullptr;
            }
        }
    }
    return nullptr;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005007B0
int TribeTacticalAIModule::addToGroup(int param_1, int param_2) {
    TacticalAIGroup* found = group(param_2, -1, -1, -1);
    if (found == nullptr) {
        return 0;
    }
    return found->addUnit(param_1, this->md);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005007F0
int TribeTacticalAIModule::removeFromGroup(int param_1, int param_2) {
    TacticalAIGroup* found = group(param_2, -1, -1, -1);
    if (found == nullptr) {
        return 0;
    }
    int result = found->removeUnit(param_1, this->md);
    if (found->numberUnits() == 0) {
        removeGroup(param_2);
    }
    return result;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500850
int TribeTacticalAIModule::removeFromGroup(int param_1) {
    TacticalAIGroup* found = groupUnitIsIn(param_1);
    if (found == nullptr) {
        return 0;
    }
    int result = found->removeUnit(param_1, this->md);
    if (found->numberUnits() == 0) {
        removeGroup(found->id());
    }
    return result;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005008A0
TacticalAIGroup* TribeTacticalAIModule::groupUnitIsIn(int param_1) {
    TacticalAIGroup* current = this->groups.next;
    if (current != &this->groups) {
        while (current != nullptr) {
            if (current->containsUnit(param_1) == 1) {
                return current;
            }
            current = current->next;
            if (current == &this->groups) {
                return nullptr;
            }
        }
    }
    return nullptr;
}

TacticalAIGroup* TribeTacticalAIModule::addGroup(int param_1) { return createGroup(param_1); }
TacticalAIGroup* TribeTacticalAIModule::findGroup(int param_1, int param_2, int param_3, int param_4) {
    return group(param_1, param_2, param_3, param_4);
}
TacticalAIGroup* TribeTacticalAIModule::getGroup(int param_1) { return group(param_1, -1, -1, -1); }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F0B62
static void FUN_004f0b62() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F0D4D
static void FUN_004f0d4d() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005018C1
static void FUN_005018c1() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00502451
static void FUN_00502451() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x0050245D
static void FUN_0050245d() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00502464
static void FUN_00502464() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00502470
static void FUN_00502470() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x0050247C
static void FUN_0050247c() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00502488
static void FUN_00502488() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x0050248F
static void FUN_0050248f() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x0050249B
static void FUN_0050249b() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005024A7
static void FUN_005024a7() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005024B3
static void FUN_005024b3() {}
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005025CA
static void FUN_005025ca() {}

static RGE_Game_World* tacticalWorld(TribeTacticalAIModule* module) {
    if ((module == nullptr) || (module->md == nullptr) || (module->md->player == nullptr)) {
        return nullptr;
    }
    return module->md->player->world;
}

static RGE_Static_Object* tacticalObject(TribeTacticalAIModule* module, int objectID) {
    RGE_Game_World* world = tacticalWorld(module);
    if (world == nullptr) {
        return nullptr;
    }
    return world->object(objectID);
}

static int isTaskedThisUpdate(TribeTacticalAIModule* module, int objectID) {
    for (int i = 0; i < module->unitsTaskedThisUpdate.numberValue; ++i) {
        if (i >= module->unitsTaskedThisUpdate.maximumSizeValue) {
            break;
        }
        if (module->unitsTaskedThisUpdate.value[i] == objectID) {
            return 1;
        }
    }
    return 0;
}

static void pushWorkingAreaUnique(TribeTacticalAIModule* module, int objectID) {
    appendManagedArrayUnique(module->workingArea, objectID);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F7350
int TribeTacticalAIModule::numberIdleSoldiers() {
    int count = 0;
    this->workingArea.numberValue = 0;
    for (int i = 0; i < this->soldiers.numberValue; ++i) {
        if (i >= this->soldiers.maximumSizeValue) {
            break;
        }
        const int unitID = this->soldiers.value[i];
        RGE_Static_Object* unitObj = tacticalObject(this, unitID);
        if (unitObj == nullptr) {
            continue;
        }
        UnitAIModule* unitAI = unitObj->unitAI();
        if (unitAI == nullptr) {
            continue;
        }
        if (unitAI->currentAction() == -1) {
            pushWorkingAreaUnique(this, unitID);
            ++count;
        }
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F7590
int TribeTacticalAIModule::numberSoldiersWithPriority(int param_1, int param_2, int param_3) {
    int count = 0;
    if (param_3 == 1) {
        this->workingArea.numberValue = 0;
    }

    for (int i = 0; i < this->soldiers.numberValue; ++i) {
        if (i >= this->soldiers.maximumSizeValue) {
            break;
        }
        const int unitID = this->soldiers.value[i];
        if (isTaskedThisUpdate(this, unitID) != 0) {
            continue;
        }
        RGE_Static_Object* unitObj = tacticalObject(this, unitID);
        if (unitObj == nullptr) {
            continue;
        }
        UnitAIModule* unitAI = unitObj->unitAI();
        if (unitAI == nullptr) {
            continue;
        }

        const int action = unitAI->currentAction();
        const int priority = unitAI->currentOrderPriority();
        int matches = 0;
        if (param_2 < 0) {
            matches = ((action == -1) || (priority < param_1)) ? 1 : 0;
        } else if (param_2 == 0) {
            matches = ((action != -1) && (priority == param_1)) ? 1 : 0;
        } else {
            matches = ((action != -1) && (priority > param_1)) ? 1 : 0;
        }

        if (matches != 0) {
            pushWorkingAreaUnique(this, unitID);
            ++count;
        }
    }

    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F7870
int TribeTacticalAIModule::numberWarshipsWithPriority(int param_1, int param_2) {
    int count = 0;
    this->workingArea.numberValue = 0;

    auto countFromArray = [&](ManagedArray<int>& arr, int restrictToCombatShips) {
        for (int i = 0; i < arr.numberValue; ++i) {
            if (i >= arr.maximumSizeValue) {
                break;
            }
            const int unitID = arr.value[i];
            if (isTaskedThisUpdate(this, unitID) != 0) {
                continue;
            }
            RGE_Static_Object* unitObj = tacticalObject(this, unitID);
            if (unitObj == nullptr) {
                continue;
            }
            if ((restrictToCombatShips != 0) && (unitObj->master_obj != nullptr)) {
                short group = unitObj->master_obj->object_group;
                if ((group != 0x12) && (group != 0x0D)) {
                    continue;
                }
            }
            UnitAIModule* unitAI = unitObj->unitAI();
            if (unitAI == nullptr) {
                continue;
            }
            const int action = unitAI->currentAction();
            const int priority = unitAI->currentOrderPriority();
            int matches = 0;
            if (param_2 < 0) {
                matches = ((action == -1) || (priority < param_1)) ? 1 : 0;
            } else if (param_2 == 0) {
                matches = ((action != -1) && (priority == param_1)) ? 1 : 0;
            } else {
                matches = ((action != -1) && (priority > param_1)) ? 1 : 0;
            }
            if (matches != 0) {
                pushWorkingAreaUnique(this, unitID);
                ++count;
            }
        }
    };

    countFromArray(this->warBoats, 0);
    countFromArray(this->soldiers, 1);
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F7D90
int TribeTacticalAIModule::idleSoldier() {
    for (int i = 0; i < this->soldiers.numberValue; ++i) {
        if (i >= this->soldiers.maximumSizeValue) {
            break;
        }
        RGE_Static_Object* unitObj = tacticalObject(this, this->soldiers.value[i]);
        if (unitObj == nullptr) {
            continue;
        }
        UnitAIModule* unitAI = unitObj->unitAI();
        if ((unitAI != nullptr) && (unitAI->currentAction() == -1)) {
            return unitObj->id;
        }
    }
    return -1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F7E80
int TribeTacticalAIModule::idleCivilian(int param_1) {
    (void)param_1;

    for (int pass = 0; pass < 2; ++pass) {
        for (int i = 0; i < this->civilians.numberValue; ++i) {
            if (i >= this->civilians.maximumSizeValue) {
                break;
            }
            const int unitID = this->civilians.value[i];
            if (isTaskedThisUpdate(this, unitID) != 0) {
                continue;
            }
            RGE_Static_Object* unitObj = tacticalObject(this, unitID);
            if (unitObj == nullptr) {
                continue;
            }
            UnitAIModule* unitAI = unitObj->unitAI();
            if (unitAI == nullptr) {
                continue;
            }
            if (this->isGatherer(unitID) != 0) {
                continue;
            }
            if ((pass == 0) && (containsManagedArray(this->civilianExplorers, unitID) != 0)) {
                continue;
            }
            if ((unitAI->currentAction() == -1) || (unitAI->currentOrder() == -1)) {
                return unitID;
            }
        }
    }

    return -1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F81A0
int TribeTacticalAIModule::idleCivilian(int param_1, XYPoint* param_2, int param_3) {
    int bestID = -1;
    long bestDistanceSq = 0;
    for (int i = 0; i < this->civilians.numberValue; ++i) {
        if (i >= this->civilians.maximumSizeValue) {
            break;
        }
        const int unitID = this->civilians.value[i];
        if (isTaskedThisUpdate(this, unitID) != 0) {
            continue;
        }
        if ((param_1 != 0) && (this->isGatherer(unitID) != 0)) {
            continue;
        }
        RGE_Static_Object* unitObj = tacticalObject(this, unitID);
        if (unitObj == nullptr) {
            continue;
        }
        UnitAIModule* unitAI = unitObj->unitAI();
        if ((unitAI == nullptr) || ((unitAI->currentAction() != -1) && (unitAI->currentOrder() != -1))) {
            continue;
        }

        if (param_2 == nullptr) {
            return unitID;
        }

        const long dx = static_cast<long>(unitObj->world_x) - param_2->x;
        const long dy = static_cast<long>(unitObj->world_y) - param_2->y;
        const long distSq = dx * dx + dy * dy;
        if ((param_3 > 0) && (distSq > static_cast<long>(param_3) * static_cast<long>(param_3))) {
            continue;
        }
        if ((bestID == -1) || (distSq < bestDistanceSq)) {
            bestID = unitID;
            bestDistanceSq = distSq;
        }
    }
    return bestID;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F8570
int TribeTacticalAIModule::civilian(XYPoint* param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    int bestID = -1;
    int bestDistance = 0;
    for (int i = 0; i < this->civilians.numberValue; ++i) {
        if (i >= this->civilians.maximumSizeValue) {
            break;
        }
        const int unitID = this->civilians.value[i];
        if (isTaskedThisUpdate(this, unitID) != 0) {
            continue;
        }

        RGE_Static_Object* unitObj = tacticalObject(this, unitID);
        if (unitObj == nullptr) {
            continue;
        }
        UnitAIModule* unitAI = unitObj->unitAI();
        if (unitAI == nullptr) {
            continue;
        }
        if ((param_6 == 0) && (unitObj->master_obj != nullptr) && (unitObj->master_obj->id == 0x103)) {
            continue;
        }
        const int currentOrder = unitAI->currentOrder();
        if ((currentOrder == param_3) || (currentOrder == param_4) || (currentOrder == param_5)) {
            continue;
        }

        if (param_1 == nullptr) {
            return unitID;
        }

        const int distance = static_cast<int>(unitObj->distance_to_position(static_cast<float>(param_1->x),
                                                                             static_cast<float>(param_1->y),
                                                                             unitObj->world_z));
        if ((bestID == -1) ||
            ((param_2 == 1) && (distance < bestDistance)) ||
            ((param_2 == 0) && (bestDistance < distance))) {
            bestID = unitID;
            bestDistance = distance;
        }
    }

    return bestID;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F87B0
int TribeTacticalAIModule::unit(int param_1, int param_2, int param_3) {
    ManagedArray<int>* source = &this->civilians;
    if (param_1 == 1) {
        source = &this->soldiers;
    } else if (param_1 == 2) {
        source = &this->boats;
    }

    int found = 0;
    for (int i = 0; i < source->numberValue; ++i) {
        if (i >= source->maximumSizeValue) {
            break;
        }
        const int unitID = source->value[i];
        if ((param_3 != 0) && (isTaskedThisUpdate(this, unitID) != 0)) {
            continue;
        }
        if (found == param_2) {
            return unitID;
        }
        ++found;
    }
    return -1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F8BE0
int TribeTacticalAIModule::busyWithAction(int param_1, int param_2) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* unitAI = obj->unitAI();
    if (unitAI == nullptr) {
        return 0;
    }
    return (unitAI->currentAction() == param_2) ? 1 : 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F8C30
void TribeTacticalAIModule::displayCivilianDistribution() {
    this->actualGathererCount(0);
    this->actualGathererCount(1);
    this->actualGathererCount(2);
    this->actualGathererCount(3);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F8C40
void TribeTacticalAIModule::updateNeededResources() {
    for (int i = 0; i < 4; ++i) {
        this->resourceDifferenceValue[i] = this->desiredGathererDistribution[i] - this->actualGathererDistribution[i];
        this->neededResourceValue[i] = (this->resourceDifferenceValue[i] > 0) ? this->resourceDifferenceValue[i] : 0;
        this->neededResources.setValue(i, this->neededResourceValue[i]);
    }
    this->firstNeededResourceUpdateDone = 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F8E20
void TribeTacticalAIModule::updateGathererDistribution() {
    for (int i = 0; i < 4; ++i) {
        this->actualGathererDistribution[i] = 0;
    }
    for (int i = 0; i < this->numberGatherersValue; ++i) {
        if ((i < 0) || (i >= 50)) {
            continue;
        }
        UnitData* data = &this->gatherers[i];
        if (data->id < 0) {
            continue;
        }
        if ((data->data1 >= 0) && (data->data1 < 4)) {
            this->actualGathererDistribution[data->data1] += 1;
        }
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F9380
int TribeTacticalAIModule::stopUnit(int param_1, int param_2) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* unitAI = obj->unitAI();
    if (unitAI == nullptr) {
        return 0;
    }
    return unitAI->stopObject(param_2);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F93D0
int TribeTacticalAIModule::moveUnit(int param_1, float param_2, float param_3, int param_4) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* unitAI = obj->unitAI();
    if (unitAI == nullptr) {
        return 0;
    }
    return unitAI->moveTo(param_2, param_3, 0.0f, 0.0f, param_4);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F9420
int TribeTacticalAIModule::groupGatherUnit(int param_1, int param_2, float param_3, float param_4, float param_5, float param_6, int param_7) {
    (void)param_3;
    (void)param_4;
    (void)param_5;
    (void)param_6;
    TacticalAIGroup* grp = this->group(param_1, -1, -1, -1);
    if (grp == nullptr) {
        return 0;
    }
    int result = 0;
    for (int i = 0; i < grp->numberUnits(); ++i) {
        const int unitID = grp->unit(i);
        if (unitID < 0) {
            continue;
        }
        result += this->taskGatherer(unitID, param_2, param_7, 0, nullptr);
    }
    return result;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F9470
int TribeTacticalAIModule::highLevelTaskExplorer(int param_1, int param_2) {
    return this->taskExplorer(param_1, param_2);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F95B0
int TribeTacticalAIModule::highLevelTaskGatherer(int param_1, unsigned long param_2) {
    return this->taskGatherer(param_1, -1, -1, param_2, nullptr);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F99B0
int TribeTacticalAIModule::taskPlay(int param_1, int* param_2, int param_3, int param_4, int param_5, Waypoint* param_6, int param_7) {
    if ((this->md == nullptr) || (this->md->player == nullptr)) {
        return 0;
    }
    int target = param_5;
    if ((target < 0) && (param_6 != nullptr)) {
        target = -1;
    }
    this->md->player->sendPlayCommand(param_1, param_2, param_3, param_4, target);
    if (param_7 != 0 && param_2 != nullptr) {
        for (int i = 0; i < param_3; ++i) {
            appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_2[i]);
        }
    }
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F9AD0
int TribeTacticalAIModule::taskBuilder(int param_1, BuildItem* param_2, ConstructionItem* param_3, unsigned long param_4) {
    (void)param_3;
    (void)param_4;
    if (param_1 < 0) {
        return 0;
    }
    if (param_2 != nullptr) {
        return this->taskBuilder(param_1, tacticalObject(this, param_2->number()));
    }
    return 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004F9E00
int TribeTacticalAIModule::taskBuilder(int param_1, RGE_Static_Object* param_2) {
    if ((param_2 == nullptr) || (param_1 < 0)) {
        return 0;
    }
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->buildObject(param_2->id, 100);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FA000
int TribeTacticalAIModule::taskRepairer(int param_1, RGE_Static_Object* param_2) {
    if ((param_2 == nullptr) || (param_1 < 0)) {
        return 0;
    }
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->repairObject(param_2->id, 100);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FA170
int TribeTacticalAIModule::taskGatherer(int param_1, int param_2, int param_3, unsigned long param_4, int* param_5) {
    (void)param_3;
    (void)param_4;
    (void)param_5;
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    if (param_2 >= 0) {
        return ai->gatherObject(param_2, 100);
    }
    return ai->stopObject(100);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FA820
int TribeTacticalAIModule::taskExplorer(int param_1, int param_2) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->explore(param_2, 100, 0);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FA940
int TribeTacticalAIModule::taskExplorer(int param_1, float param_2, float param_3) {
    return this->taskExplorer(param_1, param_2, param_3, 100);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FAAA0
int TribeTacticalAIModule::taskExplorer(int param_1, float param_2, float param_3, int param_4) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->moveTo(param_2, param_3, 0.0f, 0.0f, param_4);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FAC90
int TribeTacticalAIModule::taskFollower(int param_1, int param_2, float param_3, int param_4) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->followObject(param_2, param_3, param_4);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FADA0
int TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->defendObject(param_2, param_3, param_4);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FAEB0
int TribeTacticalAIModule::taskWaterExplorer(int param_1) {
    return this->taskExplorer(param_1, 0);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FAFC0
int TribeTacticalAIModule::taskWaterTrader(int param_1, int param_2) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->tradeWithObject(param_2, 100);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FB160
int TribeTacticalAIModule::taskWaterFisher(int param_1, int param_2, float param_3, float param_4) {
    (void)param_3;
    (void)param_4;
    return this->taskGatherer(param_1, param_2, 0, 0, nullptr);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FB2D0
int TribeTacticalAIModule::taskAttacker(int param_1, float param_2, float param_3, int param_4, int param_5, Waypoint* param_6, int param_7, int param_8, int param_9) {
    (void)param_7;
    (void)param_8;
    (void)param_9;
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }

    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    if (param_4 >= 0) {
        return ai->attackObject(param_4, param_5);
    }
    if (param_6 != nullptr) {
        return ai->moveTo(param_6->x, param_6->y, param_6->z, 0.0f, param_5);
    }
    return ai->moveTo(param_2, param_3, 0.0f, 0.0f, param_5);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FB500
int TribeTacticalAIModule::taskDefender(int param_1, int param_2) {
    return this->taskDefender(param_1, param_2, 0.0f, 100);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FB520
int TribeTacticalAIModule::taskDefender(int param_1, float param_2, float param_3) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->defendPosition(param_2, param_3, 0.0f, 100);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FB550
int TribeTacticalAIModule::taskTrain(BuildItem* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    param_1->setInProgress(1);
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FB710
int TribeTacticalAIModule::taskResearch(BuildItem* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    param_1->setInProgress(1);
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FB8D0
int TribeTacticalAIModule::taskToEnter(int param_1, int param_2) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->enterObject(param_2, 100);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FB9E0
int TribeTacticalAIModule::taskTransporter(int param_1, float param_2, float param_3) {
    RGE_Static_Object* obj = tacticalObject(this, param_1);
    if (obj == nullptr) {
        return 0;
    }
    UnitAIModule* ai = obj->unitAI();
    if (ai == nullptr) {
        return 0;
    }
    appendManagedArrayUnique(this->unitsTaskedThisUpdate, param_1);
    return ai->transportObject(param_2, param_3, 0.0f, 100);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FBB30
void TribeTacticalAIModule::removeFromTaskLists(int param_1) {
    auto removeFromArray = [&](ManagedArray<int>& arr) {
        for (int i = 0; i < arr.numberValue; ++i) {
            if (i >= arr.maximumSizeValue) {
                break;
            }
            if (arr.value[i] != param_1) {
                continue;
            }
            for (int j = i; j + 1 < arr.numberValue; ++j) {
                if ((j + 1) >= arr.maximumSizeValue) {
                    break;
                }
                arr.value[j] = arr.value[j + 1];
            }
            arr.numberValue -= 1;
            return;
        }
    };

    removeFromArray(this->workingArea);
    removeFromArray(this->unitsTaskedThisUpdate);
    removeFromArray(this->ungroupedSoldiers);
    removeFromArray(this->soldiers);
    removeFromArray(this->warBoats);
    removeFromArray(this->boats);

    this->removeGatherer(param_1);
    this->removeFromGroup(param_1);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FBC10
int TribeTacticalAIModule::calculatePriority(float param_1) {
    if (param_1 <= 0.0f) {
        return 100;
    }
    int value = 100 - static_cast<int>(param_1);
    if (value < 0) {
        value = 0;
    }
    if (value > 100) {
        value = 100;
    }
    return value;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FBC30
void TribeTacticalAIModule::setupSoldierGroups() {
    if (this->numberGroups(0, -1) == 0 && this->soldiers.numberValue > 0) {
        TacticalAIGroup* grp = this->createGroup(0);
        if (grp != nullptr) {
            grp->setType(0);
            grp->setSubType(0);
            grp->setDesiredNumberUnits(this->soldiers.numberValue);
        }
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FC500
void TribeTacticalAIModule::fillSoldierGroups() {
    TacticalAIGroup* grp = this->group(0, -1, -1, -1);
    if (grp == nullptr) {
        return;
    }
    for (int i = 0; i < this->ungroupedSoldiers.numberValue; ++i) {
        if (i >= this->ungroupedSoldiers.maximumSizeValue) {
            break;
        }
        grp->addUnit(this->ungroupedSoldiers.value[i], this->md);
    }
    this->ungroupedSoldiers.numberValue = 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FD2F0
int TribeTacticalAIModule::numberUngroupedSoldiers() {
    int count = 0;
    this->ungroupedSoldiers.numberValue = 0;
    for (int i = 0; i < this->soldiers.numberValue; ++i) {
        if (i >= this->soldiers.maximumSizeValue) {
            break;
        }
        int unitID = this->soldiers.value[i];
        if (this->groupUnitIsIn(unitID) == nullptr) {
            ++count;
            appendManagedArrayUnique(this->ungroupedSoldiers, unitID);
        }
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FD4F0
int TribeTacticalAIModule::numberExtraGroupedSoldiers() {
    int extra = 0;
    for (TacticalAIGroup* current = this->groups.next;
         (current != nullptr) && (current != &this->groups);
         current = current->next) {
        if (current->type() != 0) {
            continue;
        }
        int over = current->numberUnits() - current->desiredNumberUnits();
        if (over > 0) {
            extra += over;
        }
    }
    return extra;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FD6D0
int TribeTacticalAIModule::numberUngroupedArtifacts() {
    int count = 0;
    for (int i = 0; i < this->artifacts.numberValue; ++i) {
        if (i >= this->artifacts.maximumSizeValue) {
            break;
        }
        if (this->groupUnitIsIn(this->artifacts.value[i]) == nullptr) {
            ++count;
        }
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FD8D0
void TribeTacticalAIModule::displaySoldierGroups() {
    for (TacticalAIGroup* current = this->groups.next;
         (current != nullptr) && (current != &this->groups);
         current = current->next) {
        if (current->type() == 0) {
            (void)current->id();
        }
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FDE00
void TribeTacticalAIModule::setupBoatGroups() {
    if (this->numberGroups(1, -1) == 0 && this->warBoats.numberValue > 0) {
        TacticalAIGroup* grp = this->createGroup(1);
        if (grp != nullptr) {
            grp->setType(1);
            grp->setSubType(0);
            grp->setDesiredNumberUnits(this->warBoats.numberValue);
        }
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FE950
void TribeTacticalAIModule::fillBoatGroups() {
    TacticalAIGroup* grp = this->group(1, -1, -1, -1);
    if (grp == nullptr) {
        return;
    }
    for (int i = 0; i < this->warBoats.numberValue; ++i) {
        if (i >= this->warBoats.maximumSizeValue) {
            break;
        }
        const int unitID = this->warBoats.value[i];
        if (grp->containsUnit(unitID) == 0) {
            grp->addUnit(unitID, this->md);
        }
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FF4E0
int TribeTacticalAIModule::numberUngroupedWarBoats() {
    int count = 0;
    for (int i = 0; i < this->warBoats.numberValue; ++i) {
        if (i >= this->warBoats.maximumSizeValue) {
            break;
        }
        if (this->groupUnitIsIn(this->warBoats.value[i]) == nullptr) {
            ++count;
        }
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FF6E0
int TribeTacticalAIModule::numberExtraGroupedWarBoats() {
    int extra = 0;
    for (TacticalAIGroup* current = this->groups.next;
         (current != nullptr) && (current != &this->groups);
         current = current->next) {
        if (current->type() != 1) {
            continue;
        }
        int over = current->numberUnits() - current->desiredNumberUnits();
        if (over > 0) {
            extra += over;
        }
    }
    return extra;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FF8E0
int TribeTacticalAIModule::numberUngroupedFishingBoats() {
    int count = 0;
    for (int i = 0; i < this->fishingBoats.numberValue; ++i) {
        if (i >= this->fishingBoats.maximumSizeValue) {
            break;
        }
        if (this->groupUnitIsIn(this->fishingBoats.value[i]) == nullptr) {
            ++count;
        }
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FFAE0
int TribeTacticalAIModule::numberUngroupedTradeBoats() {
    int count = 0;
    for (int i = 0; i < this->tradeBoats.numberValue; ++i) {
        if (i >= this->tradeBoats.maximumSizeValue) {
            break;
        }
        if (this->groupUnitIsIn(this->tradeBoats.value[i]) == nullptr) {
            ++count;
        }
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FFCE0
int TribeTacticalAIModule::numberUngroupedTransportBoats() {
    int count = 0;
    for (int i = 0; i < this->transportBoats.numberValue; ++i) {
        if (i >= this->transportBoats.maximumSizeValue) {
            break;
        }
        if (this->groupUnitIsIn(this->transportBoats.value[i]) == nullptr) {
            ++count;
        }
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004FFEE0
void TribeTacticalAIModule::displayBoatGroups() {
    for (TacticalAIGroup* current = this->groups.next;
         (current != nullptr) && (current != &this->groups);
         current = current->next) {
        if (current->type() == 1) {
            (void)current->id();
        }
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005004C0
TacticalAIGroup* TribeTacticalAIModule::bestGroup(int param_1, int param_2, int param_3, XYPoint* param_4, int param_5) {
    (void)param_5;
    TacticalAIGroup* best = nullptr;
    long bestScore = 0;

    for (TacticalAIGroup* current = this->groups.next;
         (current != nullptr) && (current != &this->groups);
         current = current->next) {
        if ((param_1 >= 0) && (current->type() != param_1)) {
            continue;
        }
        if ((param_2 >= 0) && (current->subType() != param_2)) {
            continue;
        }
        if ((param_3 >= 0) && (current->action() != param_3)) {
            continue;
        }

        long score = static_cast<long>(current->priority()) * 1000 + current->numberUnits();
        if (param_4 != nullptr) {
            Waypoint* loc = current->location();
            const long dx = static_cast<long>(loc->x) - param_4->x;
            const long dy = static_cast<long>(loc->y) - param_4->y;
            score -= (dx * dx + dy * dy);
        }

        if ((best == nullptr) || (score > bestScore)) {
            best = current;
            bestScore = score;
        }
    }

    return best;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500670
TacticalAIGroup* TribeTacticalAIModule::readyAndIdleGroup(int param_1, int param_2, XYPoint* param_3) {
    for (TacticalAIGroup* current = this->groups.next;
         (current != nullptr) && (current != &this->groups);
         current = current->next) {
        if ((param_1 >= 0) && (current->type() != param_1)) {
            continue;
        }
        if ((param_2 >= 0) && (current->subType() != param_2)) {
            continue;
        }
        if (current->allUnitsIdle(this->md, 0) == 0) {
            continue;
        }
        if (param_3 != nullptr) {
            Waypoint* loc = current->location();
            if ((static_cast<int>(loc->x) != param_3->x) || (static_cast<int>(loc->y) != param_3->y)) {
                continue;
            }
        }
        return current;
    }
    return nullptr;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005008F0
int TribeTacticalAIModule::numberGroups(int param_1, int param_2) {
    int count = 0;
    for (TacticalAIGroup* current = this->groups.next;
         (current != nullptr) && (current != &this->groups);
         current = current->next) {
        if ((param_1 >= 0) && (current->type() != param_1)) {
            continue;
        }
        if ((param_2 >= 0) && (current->subType() != param_2)) {
            continue;
        }
        ++count;
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500950
int TribeTacticalAIModule::numberUnitsInGroups(int param_1) {
    int count = 0;
    for (TacticalAIGroup* current = this->groups.next;
         (current != nullptr) && (current != &this->groups);
         current = current->next) {
        if ((param_1 >= 0) && (current->type() != param_1)) {
            continue;
        }
        count += current->numberUnits();
    }
    return count;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x005009A0
int TribeTacticalAIModule::numberItemsToAttack() { return this->playersToAttack.numberValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500A30
int TribeTacticalAIModule::itemToCapture() {
    if (this->artifacts.numberValue <= 0 || this->artifacts.maximumSizeValue <= 0) {
        return -1;
    }
    return this->artifacts.value[0];
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500A80
int TribeTacticalAIModule::itemToBringToArea() {
    if (this->workingArea.numberValue <= 0 || this->workingArea.maximumSizeValue <= 0) {
        return -1;
    }
    return this->workingArea.value[0];
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500AD0
int TribeTacticalAIModule::numberItemsToDefend() { return this->playersToDefend.numberValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500AF0
unsigned long TribeTacticalAIModule::attackLimiterTime(int param_1) {
    if (param_1 <= 0) {
        return this->lastGroupAttackTime;
    }
    return this->lastGroupAttackTime + static_cast<unsigned long>(this->randomizedAttackSeparationTime * param_1);
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500B30
void TribeTacticalAIModule::resetAttackSeparationTime() {
    int attackSeparationVariance = this->sn[0x66];
    if (attackSeparationVariance < 1) {
        this->randomizedAttackSeparationTime = this->sn[0x2E];
    } else {
        const int randomValue = debug_rand("C:\\msdev\\work\\age1_x1\\taitacmd.c", 0x2D35);
        this->randomizedAttackSeparationTime =
            (randomValue % attackSeparationVariance) + (this->sn[0x2E] - attackSeparationVariance / 2);
    }
    if (this->randomizedAttackSeparationTime < 0) {
        this->randomizedAttackSeparationTime = 0;
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500BA0
int TribeTacticalAIModule::setGatherLocation(TacticalAIGroup* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    int leaderID = param_1->commander();
    if (leaderID < 0 && param_1->numberUnits() > 0) {
        leaderID = param_1->unit(0);
    }

    RGE_Static_Object* leader = tacticalObject(this, leaderID);
    if (leader == nullptr) {
        return 0;
    }

    param_1->setGatherLocation(leader->world_x, leader->world_y, leader->world_z);
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500CC0
int TribeTacticalAIModule::setAllGroupLocations(TacticalAIGroup* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (this->setGatherLocation(param_1) == 0) {
        return 0;
    }
    Waypoint* gather = param_1->gatherLocation();
    param_1->setLocation(gather->x, gather->y, gather->z);
    param_1->setRetreatLocation(gather->x, gather->y, gather->z);
    param_1->setTargetLocation(gather->x, gather->y, gather->z);
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x00500DE0
void TribeTacticalAIModule::setGroupInfluences(InfluenceMap* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    for (TacticalAIGroup* current = this->groups.next;
         (current != nullptr) && (current != &this->groups);
         current = current->next) {
        const int commanderID = current->commander();
        if (commanderID < 0) {
            continue;
        }
        RGE_Static_Object* commander = tacticalObject(this, commanderID);
        if (commander == nullptr) {
            continue;
        }
        commander->changeInfluenceMap(param_1, 1, current->type(), current->priority());
    }
}

// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501190
int TribeTacticalAIModule::selectBestCommander(TacticalAIGroup* param_1) { (void)param_1; return -1; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501260
int TribeTacticalAIModule::selectBestCommander(ManagedArray<int>* param_1) { (void)param_1; return -1; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501430
int TribeTacticalAIModule::dealWithGAIAAttacker(RGE_Static_Object* param_1, RGE_Static_Object* param_2) { (void)param_1; (void)param_2; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x005015E0
void TribeTacticalAIModule::addWaypoint(int param_1, unsigned char param_2, unsigned char param_3) { (void)param_1; (void)param_2; (void)param_3; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501620
int TribeTacticalAIModule::importantGroupLeader(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501690
int TribeTacticalAIModule::unexploredArea(int param_1, XYPoint* param_2) { (void)param_1; (void)param_2; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x005018F0
UnitData* TribeTacticalAIModule::gatherer(int param_1) { (void)param_1; return nullptr; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501920
UnitData* TribeTacticalAIModule::addGatherer(int param_1) { (void)param_1; return nullptr; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x005019C0
int TribeTacticalAIModule::removeGatherer(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501A80
int TribeTacticalAIModule::isGatherer(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501AB0
int TribeTacticalAIModule::requiredGatherAmount(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501AF0
void TribeTacticalAIModule::trackUnitGather(int param_1, int param_2, int param_3) { (void)param_1; (void)param_2; (void)param_3; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501B50
int TribeTacticalAIModule::deleteUnit(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501B90
int TribeTacticalAIModule::numberAvailableStoragePits(int* param_1, int* param_2, int param_3) { (void)param_1; (void)param_2; (void)param_3; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501C70
int TribeTacticalAIModule::numberAvailableGranaries(int* param_1, int* param_2) { (void)param_1; (void)param_2; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501D20
int TribeTacticalAIModule::initialExplorationSatisfied() { return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00501D70
void TribeTacticalAIModule::checkForBuildInsertion(int param_1, int param_2, int param_3) { (void)param_1; (void)param_2; (void)param_3; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x005020A0
int TribeTacticalAIModule::isFarmer(RGE_Static_Object* param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502100
int TribeTacticalAIModule::numberFarmers() { return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502200
int TribeTacticalAIModule::inAge(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502230
void TribeTacticalAIModule::stuffAvoidancePath(TacticalAIGroup* param_1, Path* param_2) { (void)param_1; (void)param_2; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502310
void TribeTacticalAIModule::checkForAttackResponseBuildInsertions(int param_1) { (void)param_1; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502600
void TribeTacticalAIModule::checkForCoopTributeDemand() {}
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502920
void TribeTacticalAIModule::checkForCoopTributeGift() {}
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502BF0
void TribeTacticalAIModule::checkForASAPAgeResearch() {}
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502D50
void TribeTacticalAIModule::checkForCoopAttack(int param_1, int param_2, int param_3) { (void)param_1; (void)param_2; (void)param_3; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502F30
int TribeTacticalAIModule::processCoopAttack(int param_1, int param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502FC0
int TribeTacticalAIModule::resourceDifference(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00502FF0
int TribeTacticalAIModule::actualGathererCount(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00503020
int TribeTacticalAIModule::actualGathererCountByRealResourceID(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00503040
int TribeTacticalAIModule::desiredGathererCount(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00503070
void TribeTacticalAIModule::taskElephantGatherers(int param_1, int param_2, int param_3) { (void)param_1; (void)param_2; (void)param_3; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x005032E0
void TribeTacticalAIModule::checkTradeBoats() {}
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00503480
int TribeTacticalAIModule::numberGatherersWithTarget(int param_1) { (void)param_1; return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x005034B0
void TribeTacticalAIModule::checkStaleAttackGroups() {}
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00503580
int TribeTacticalAIModule::numberWaterExplorers() { return 0; }
// TODO: STUB - Source of truth: taitacmd.cpp.decomp @ 0x00503600
void TribeTacticalAIModule::saveTheTown(int param_1) { (void)param_1; }

