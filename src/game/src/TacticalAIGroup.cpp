#include "../include/TacticalAIGroup.h"

#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/TribeMainDecisionAIModule.h"
#include "../include/globals.h"

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EA860
TacticalAIGroup::TacticalAIGroup() {
    this->idValue = -1;
    this->inUseValue = 0;
    this->typeValue = -1;
    this->subTypeValue = -1;
    this->numberUnitsValue = 0;
    this->desiredNumberUnitsValue = 0;
    this->commanderValue = -1;
    this->originalHitPointsValue = -1;
    this->originalUnitNumberValue = -1;
    this->actionValue = 0;
    this->targetValue = -1;
    this->targetTypeValue = -1;
    this->priorityValue = 0;
    this->waitCodeValue = -1;
    this->assistGroupIDValue = -1;
    this->assistGroupTypeValue = -1;
    this->consecutiveIdleUnitCountValue = 0;
    this->playNumberValue = -1;
    this->numberAttackWaypointsValue = 0;
    this->currentAttackWaypointValue = 0;
    this->consecutiveGatherAttemptsValue = 0;
    this->numberObjectsToDestroyValue = 0;
    this->objectsToDestroyOwnerValue = -1;
    this->objectsToDestroyCommanderZoneValue = -1;
    this->lastAttackRoundupTime = 0;
    this->lastAddedUnitTimeValue = 0;
    this->setTargetLocation(-1.0f, -1.0f, -1.0f);
    this->setGatherLocation(-1.0f, -1.0f, -1.0f);
    this->setRetreatLocation(-1.0f, -1.0f, -1.0f);
    this->setLocation(-1.0f, -1.0f, -1.0f);
    for (int i = 0; i < 40; ++i) {
        this->unitsValue[i] = -1;
        this->unitsOriginalHitPointsValue[i] = -1;
    }
    for (int i = 0; i < 20; ++i) {
        this->objectsToDestroyValue[i] = -1;
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EA9B0
TacticalAIGroup::~TacticalAIGroup() {}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EA9C0
int TacticalAIGroup::load(int param_1) {
    rge_read(param_1, &this->idValue, 4);
    rge_read(param_1, &this->inUseValue, 4);
    for (int i = 0; i < 40; ++i) {
        rge_read(param_1, &this->unitsValue[i], 4);
        rge_read(param_1, &this->unitsOriginalHitPointsValue[i], 4);
    }
    rge_read(param_1, &this->numberUnitsValue, 4);
    rge_read(param_1, &this->desiredNumberUnitsValue, 4);
    rge_read(param_1, &this->commanderValue, 4);
    rge_read(param_1, &this->originalHitPointsValue, 4);
    rge_read(param_1, &this->originalUnitNumberValue, 4);
    rge_read(param_1, &this->locationValue, 0x10);
    rge_read(param_1, &this->actionValue, 4);
    rge_read(param_1, &this->targetValue, 4);
    rge_read(param_1, &this->targetTypeValue, 4);
    rge_read(param_1, &this->targetLocationValue, 0x10);
    rge_read(param_1, &this->gatherLocationValue, 0x10);
    rge_read(param_1, &this->retreatLocationValue, 0x10);
    rge_read(param_1, &this->priorityValue, 4);
    rge_read(param_1, &this->waitCodeValue, 4);
    rge_read(param_1, &this->assistGroupIDValue, 4);
    rge_read(param_1, &this->assistGroupTypeValue, 4);
    rge_read(param_1, &this->typeValue, 4);
    rge_read(param_1, &this->subTypeValue, 4);
    rge_read(param_1, &this->consecutiveIdleUnitCountValue, 4);
    rge_read(param_1, &this->numberAttackWaypointsValue, 1);
    rge_read(param_1, &this->currentAttackWaypointValue, 1);
    rge_read(param_1, this->attackWaypoints, 0xF0);
    rge_read(param_1, &this->playNumberValue, 4);
    if (save_game_version < 6.94f) {
        this->consecutiveGatherAttemptsValue = 0;
    } else {
        rge_read(param_1, &this->consecutiveGatherAttemptsValue, 1);
    }
    if (save_game_version >= 7.13f) {
        rge_read(param_1, &this->numberObjectsToDestroyValue, 4);
        rge_read(param_1, this->objectsToDestroyValue, 0x50);
        rge_read(param_1, &this->objectsToDestroyOwnerValue, 4);
        rge_read(param_1, &this->objectsToDestroyCommanderZoneValue, 4);
    }
    if (save_game_version >= 7.14f) {
        rge_read(param_1, &this->lastAttackRoundupTime, 4);
    }
    if (save_game_version >= 7.2f) {
        rge_read(param_1, &this->lastAddedUnitTimeValue, 4);
    }
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EACA0
int TacticalAIGroup::save(int param_1) {
    rge_write(param_1, &this->idValue, 4);
    rge_write(param_1, &this->inUseValue, 4);
    for (int i = 0; i < 40; ++i) {
        rge_write(param_1, &this->unitsValue[i], 4);
        rge_write(param_1, &this->unitsOriginalHitPointsValue[i], 4);
    }
    rge_write(param_1, &this->numberUnitsValue, 4);
    rge_write(param_1, &this->desiredNumberUnitsValue, 4);
    rge_write(param_1, &this->commanderValue, 4);
    rge_write(param_1, &this->originalHitPointsValue, 4);
    rge_write(param_1, &this->originalUnitNumberValue, 4);
    rge_write(param_1, &this->locationValue, 0x10);
    rge_write(param_1, &this->actionValue, 4);
    rge_write(param_1, &this->targetValue, 4);
    rge_write(param_1, &this->targetTypeValue, 4);
    rge_write(param_1, &this->targetLocationValue, 0x10);
    rge_write(param_1, &this->gatherLocationValue, 0x10);
    rge_write(param_1, &this->retreatLocationValue, 0x10);
    rge_write(param_1, &this->priorityValue, 4);
    rge_write(param_1, &this->waitCodeValue, 4);
    rge_write(param_1, &this->assistGroupIDValue, 4);
    rge_write(param_1, &this->assistGroupTypeValue, 4);
    rge_write(param_1, &this->typeValue, 4);
    rge_write(param_1, &this->subTypeValue, 4);
    rge_write(param_1, &this->consecutiveIdleUnitCountValue, 4);
    rge_write(param_1, &this->numberAttackWaypointsValue, 1);
    rge_write(param_1, &this->currentAttackWaypointValue, 1);
    rge_write(param_1, this->attackWaypoints, 0xF0);
    rge_write(param_1, &this->playNumberValue, 4);
    rge_write(param_1, &this->consecutiveGatherAttemptsValue, 1);
    rge_write(param_1, &this->numberObjectsToDestroyValue, 4);
    rge_write(param_1, this->objectsToDestroyValue, 0x50);
    rge_write(param_1, &this->objectsToDestroyOwnerValue, 4);
    rge_write(param_1, &this->objectsToDestroyCommanderZoneValue, 4);
    rge_write(param_1, &this->lastAttackRoundupTime, 4);
    rge_write(param_1, &this->lastAddedUnitTimeValue, 4);
    return 1;
}

int TacticalAIGroup::id() const { return this->idValue; }
void TacticalAIGroup::setID(int param_1) { this->idValue = param_1; }
int TacticalAIGroup::inUse() const { return this->inUseValue; }
void TacticalAIGroup::setInUse(int param_1) { this->inUseValue = param_1; }
int TacticalAIGroup::type() const { return this->typeValue; }
void TacticalAIGroup::setType(int param_1) { this->typeValue = param_1; }
int TacticalAIGroup::subType() const { return this->subTypeValue; }
void TacticalAIGroup::setSubType(int param_1) { this->subTypeValue = param_1; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EAFA0
int TacticalAIGroup::addUnit(int param_1, TribeMainDecisionAIModule* param_2) {
    for (int i = 0; i < 40; ++i) {
        if (this->unitsValue[i] == -1) {
            this->unitsValue[i] = param_1;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue += 1;
            if (this->commanderValue != -1) {
                param_2->player->command_add_to_group(this->commanderValue, param_1, 4.0f);
            }
            if ((param_2 != nullptr) && (param_2->player != nullptr) && (param_2->player->world != nullptr)) {
                this->lastAddedUnitTimeValue = param_2->player->world->world_time;
            }
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB030
int TacticalAIGroup::removeUnit(int param_1, TribeMainDecisionAIModule* param_2) {
    for (int i = 0; i < 40; ++i) {
        if (this->unitsValue[i] == param_1) {
            if (param_1 == this->commanderValue) {
                setSpecificCommander(-1, param_2);
            } else if (this->commanderValue != -1) {
                param_2->player->command_remove_from_group(this->commanderValue, param_1);
            }
            this->unitsValue[i] = -1;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue -= 1;
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB0C0
int TacticalAIGroup::removeUnitByIndex(int param_1, TribeMainDecisionAIModule* param_2) {
    if ((param_1 < 0) || (param_1 >= 40)) {
        return 0;
    }
    if (this->unitsValue[param_1] == this->commanderValue) {
        setSpecificCommander(-1, param_2);
    } else if (this->commanderValue != -1) {
        param_2->player->command_remove_from_group(this->commanderValue, this->unitsValue[param_1]);
    }
    this->unitsValue[param_1] = -1;
    this->unitsOriginalHitPointsValue[param_1] = -1;
    this->numberUnitsValue -= 1;
    return 1;
}

void TacticalAIGroup::removeUnits(TribeMainDecisionAIModule* param_1) {
    setSpecificCommander(-1, param_1);
    this->numberUnitsValue = 0;
    for (int i = 0; i < 40; ++i) {
        this->unitsValue[i] = -1;
        this->unitsOriginalHitPointsValue[i] = -1;
    }
}

int TacticalAIGroup::containsUnit(int param_1) {
    for (int i = 0; i < 40; ++i) {
        if (this->unitsValue[i] == param_1) {
            return 1;
        }
    }
    return 0;
}

int TacticalAIGroup::numberUnits() { return this->numberUnitsValue; }

int TacticalAIGroup::unit(int param_1) {
    int index = -1;
    for (int i = 0; i < 40; ++i) {
        if (this->unitsValue[i] != -1) {
            index += 1;
        }
        if (index == param_1) {
            return this->unitsValue[i];
        }
        if (param_1 + 1 <= index) {
            return -1;
        }
    }
    return -1;
}

int TacticalAIGroup::desiredNumberUnits() const { return this->desiredNumberUnitsValue; }
void TacticalAIGroup::setDesiredNumberUnits(int param_1) { this->desiredNumberUnitsValue = param_1; }
int TacticalAIGroup::commander() const { return this->commanderValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB3A0
void TacticalAIGroup::setSpecificCommander(int param_1, TribeMainDecisionAIModule* param_2) {
    int temp[40];
    if (this->commanderValue != -1) {
        param_2->player->command_destroy_group(this->commanderValue);
    }
    this->commanderValue = param_1;
    if (param_1 != -1) {
        int numberUnits = 0;
        int* outUnits = temp + 1;
        for (int i = 0; i < 40; ++i) {
            int unitID = this->unitsValue[i];
            *outUnits = unitID;
            if (unitID != -1) {
                numberUnits += 1;
                outUnits += 1;
            }
        }
        param_2->player->command_create_group(param_1, temp + 1, numberUnits, 4.0f);
    }
}

void TacticalAIGroup::setLocation(float param_1, float param_2, float param_3) {
    this->locationValue.x = param_1;
    this->locationValue.y = param_2;
    this->locationValue.z = param_3;
}

int TacticalAIGroup::action() const { return this->actionValue; }
void TacticalAIGroup::setAction(int param_1) { this->actionValue = param_1; }
int TacticalAIGroup::target() const { return this->targetValue; }
void TacticalAIGroup::setTarget(int param_1) { this->targetValue = param_1; }
int TacticalAIGroup::targetType() const { return this->targetTypeValue; }
void TacticalAIGroup::setTargetType(int param_1) { this->targetTypeValue = param_1; }
Waypoint* TacticalAIGroup::targetLocation() { return &this->targetLocationValue; }

void TacticalAIGroup::setTargetLocation(float param_1, float param_2, float param_3) {
    this->targetLocationValue.x = param_1;
    this->targetLocationValue.y = param_2;
    this->targetLocationValue.z = param_3;
}

Waypoint* TacticalAIGroup::gatherLocation() { return &this->gatherLocationValue; }

void TacticalAIGroup::setGatherLocation(float param_1, float param_2, float param_3) {
    this->gatherLocationValue.x = param_1;
    this->gatherLocationValue.y = param_2;
    this->gatherLocationValue.z = param_3;
}

Waypoint* TacticalAIGroup::retreatLocation() { return &this->retreatLocationValue; }

void TacticalAIGroup::setRetreatLocation(float param_1, float param_2, float param_3) {
    this->retreatLocationValue.x = param_1;
    this->retreatLocationValue.y = param_2;
    this->retreatLocationValue.z = param_3;
}

int TacticalAIGroup::assistGroupID() const { return this->assistGroupIDValue; }
void TacticalAIGroup::setAssistGroupID(int param_1) { this->assistGroupIDValue = param_1; }
int TacticalAIGroup::assistGroupType() const { return this->assistGroupTypeValue; }
void TacticalAIGroup::setAssistGroupType(int param_1) { this->assistGroupTypeValue = param_1; }

int TacticalAIGroup::objectToDestroy(int param_1) {
    if ((param_1 >= 0) && (param_1 < 20)) {
        return this->objectsToDestroyValue[param_1];
    }
    return -1;
}

int TacticalAIGroup::addObjectToDestroy(int param_1) {
    if (this->numberObjectsToDestroyValue < 0x13) {
        this->objectsToDestroyValue[this->numberObjectsToDestroyValue] = param_1;
        this->numberObjectsToDestroyValue += 1;
        return 1;
    }
    return 0;
}
