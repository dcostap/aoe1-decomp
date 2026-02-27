#include "../include/TribeTacticalAIModule.h"

#include "../include/DiplomacyAIModule.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/ResourceItem.h"
#include "../include/TribeMainDecisionAIModule.h"

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

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x004120A0
ResourceItem::~ResourceItem() {}

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

TribeTacticalAIModule::TribeTacticalAIModule(int param_1, int param_2)
    : TribeTacticalAIModule(nullptr, param_1) {
    // TODO: Part 2 - transliterate full save/load constructor parity from taitacmd.cpp.decomp @ 0x004ED4F0.
    (void)param_2;
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
        // TODO: Part 2 - remove defensive checks once full tactical module wiring parity is in place.
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
    // TODO: Part 2 - reset informationAI.farmsTaskedThisUpdate.numberValue with exact field parity.
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

int TribeTacticalAIModule::save(int param_1) {
    // TODO: Part 2 - transliterate full tactical save parity from taitacmd.cpp.decomp @ 0x004EF4E0.
    (void)param_1;
    return 1;
}

void TribeTacticalAIModule::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    // TODO: Part 2 - transliterate full tactical notify parity from taitacmd.cpp.decomp @ 0x004F62C0.
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    (void)param_6;
}

int TribeTacticalAIModule::doSomething() {
    // TODO: Part 2 - transliterate tactical per-update area scheduler from taitacmd.cpp.decomp @ 0x004F0190.
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
