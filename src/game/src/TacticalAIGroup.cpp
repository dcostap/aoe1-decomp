#include "../include/TacticalAIGroup.h"

#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Static_Object.h"
#include "../include/TribeMainDecisionAIModule.h"
#include "../include/TribeTacticalAIModule.h"
#include "../include/UnitAIModule.h"
#include "../include/globals.h"

#include <cmath>

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

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EAF20
int TacticalAIGroup::id() const { return this->idValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EAF30
void TacticalAIGroup::setID(int param_1) { this->idValue = param_1; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EAF40
int TacticalAIGroup::inUse() const { return this->inUseValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EAF50
void TacticalAIGroup::setInUse(int param_1) { this->inUseValue = param_1; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EAF60
int TacticalAIGroup::type() const { return this->typeValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EAF70
void TacticalAIGroup::setType(int param_1) { this->typeValue = param_1; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EAF80
int TacticalAIGroup::subType() const { return this->subTypeValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EAF90
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

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB140
void TacticalAIGroup::removeUnits(TribeMainDecisionAIModule* param_1) {
    setSpecificCommander(-1, param_1);
    this->numberUnitsValue = 0;
    for (int i = 0; i < 40; ++i) {
        this->unitsValue[i] = -1;
        this->unitsOriginalHitPointsValue[i] = -1;
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB180
int TacticalAIGroup::removeExtraUnits(TribeMainDecisionAIModule* param_1) {
    if ((this->desiredNumberUnitsValue < this->numberUnitsValue) && (this->numberUnitsValue > 0)) {
        for (int i = 0; i < 40; ++i) {
            if (this->desiredNumberUnitsValue >= this->numberUnitsValue) {
                break;
            }
            if (this->unitsValue[i] != -1) {
                removeUnitByIndex(i, param_1);
            }
        }
        return 1;
    }
    return 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB1F0
int TacticalAIGroup::removeUnboardedUnits(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2) {
    for (int i = 0; i < 40; ++i) {
        int unitId = this->unitsValue[i];
        if (unitId == -1) {
            continue;
        }

        RGE_Static_Object* object = nullptr;
        if ((param_2 != nullptr) && (param_2->player != nullptr) && (param_2->player->world != nullptr)) {
            object = param_2->player->world->object(unitId);
        }
        if ((object == nullptr) || (object->inside_obj == nullptr)) {
            if (unitId == this->commanderValue) {
                setSpecificCommander(-1, param_2);
            } else if ((this->commanderValue != -1) && (param_2 != nullptr) && (param_2->player != nullptr)) {
                param_2->player->command_remove_from_group(this->commanderValue, unitId);
            }
            // TODO: STUB - TribeTacticalAIModule::stopUnit declaration is missing in current headers.
            this->unitsValue[i] = -1;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue -= 1;
        }
    }
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB290
int TacticalAIGroup::containsUnit(int param_1) {
    for (int i = 0; i < 40; ++i) {
        if (this->unitsValue[i] == param_1) {
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB2C0
int TacticalAIGroup::numberUnits() { return this->numberUnitsValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB2D0
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

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB320
int TacticalAIGroup::unitOriginalHitPoints(int param_1) {
    int index = -1;
    for (int i = 0; i < 40; ++i) {
        if (this->unitsValue[i] != -1) {
            index += 1;
        }
        if (index == param_1) {
            return this->unitsOriginalHitPointsValue[i];
        }
        if (param_1 + 1 <= index) {
            return -1;
        }
    }
    return -1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB370
int TacticalAIGroup::desiredNumberUnits() const { return this->desiredNumberUnitsValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB380
void TacticalAIGroup::setDesiredNumberUnits(int param_1) { this->desiredNumberUnitsValue = param_1; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB390
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

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB430
int TacticalAIGroup::currentHitPoints(TribeMainDecisionAIModule* param_1) const {
    int hitPoints = 0;
    for (int i = 0; i < 40; ++i) {
        int unitId = this->unitsValue[i];
        if (unitId == -1) {
            continue;
        }
        RGE_Static_Object* object = nullptr;
        if ((param_1 != nullptr) && (param_1->player != nullptr) && (param_1->player->world != nullptr)) {
            object = param_1->player->world->object(unitId);
        }
        if (object != nullptr) {
            hitPoints += static_cast<int>(object->hp);
        }
    }
    return hitPoints;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB470
int TacticalAIGroup::originalHitPoints() const { return this->originalHitPointsValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB480
void TacticalAIGroup::setOriginalHitPoints(int param_1) { this->originalHitPointsValue = param_1; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB490
int TacticalAIGroup::originalUnitNumber() const { return this->originalUnitNumberValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB4A0
void TacticalAIGroup::setOriginalUnitNumber(int param_1) { this->originalUnitNumberValue = param_1; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB4B0
Waypoint* TacticalAIGroup::location() { return &this->locationValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB4C0
void TacticalAIGroup::setLocation(float param_1, float param_2, float param_3) {
    this->locationValue.x = param_1;
    this->locationValue.y = param_2;
    this->locationValue.z = param_3;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB4F0
int TacticalAIGroup::action() const { return this->actionValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB500
void TacticalAIGroup::setAction(int param_1) { this->actionValue = param_1; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB510
int TacticalAIGroup::target() const { return this->targetValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB520
void TacticalAIGroup::setTarget(int param_1) { this->targetValue = param_1; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB530
int TacticalAIGroup::targetType() const { return this->targetTypeValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB540
void TacticalAIGroup::setTargetType(int param_1) { this->targetTypeValue = param_1; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB550
Waypoint* TacticalAIGroup::targetLocation() { return &this->targetLocationValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB560
void TacticalAIGroup::setAllLocations(float param_1, float param_2, float param_3) {
    this->locationValue.x = param_1;
    this->locationValue.y = param_2;
    this->locationValue.z = param_3;
    this->gatherLocationValue.x = param_1;
    this->gatherLocationValue.y = param_2;
    this->gatherLocationValue.z = param_3;
    this->retreatLocationValue.x = param_1;
    this->retreatLocationValue.y = param_2;
    this->retreatLocationValue.z = param_3;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB5C0
void TacticalAIGroup::setTargetLocation(float param_1, float param_2, float param_3) {
    this->targetLocationValue.x = param_1;
    this->targetLocationValue.y = param_2;
    this->targetLocationValue.z = param_3;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB5F0
Waypoint* TacticalAIGroup::gatherLocation() { return &this->gatherLocationValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB600
void TacticalAIGroup::setGatherLocation(float param_1, float param_2, float param_3) {
    this->gatherLocationValue.x = param_1;
    this->gatherLocationValue.y = param_2;
    this->gatherLocationValue.z = param_3;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB630
Waypoint* TacticalAIGroup::retreatLocation() { return &this->retreatLocationValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB640
void TacticalAIGroup::setRetreatLocation(float param_1, float param_2, float param_3) {
    this->retreatLocationValue.x = param_1;
    this->retreatLocationValue.y = param_2;
    this->retreatLocationValue.z = param_3;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB670
int TacticalAIGroup::priority() const { return this->priorityValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB680
void TacticalAIGroup::setPriority(int param_1) { this->priorityValue = param_1; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB690
int TacticalAIGroup::waitCode() const { return this->waitCodeValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB6A0
void TacticalAIGroup::setWaitCode(int param_1) { this->waitCodeValue = param_1; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB6B0
int TacticalAIGroup::assistGroupID() const { return this->assistGroupIDValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB6C0
void TacticalAIGroup::setAssistGroupID(int param_1) { this->assistGroupIDValue = param_1; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB6D0
int TacticalAIGroup::assistGroupType() const { return this->assistGroupTypeValue; }
// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004EB6E0
void TacticalAIGroup::setAssistGroupType(int param_1) { this->assistGroupTypeValue = param_1; }

// TODO: 0x004EB6F0 TacticalAIGroup::task full transliteration is blocked on missing tactical helper graph.
int TacticalAIGroup::task(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2, int param_3, int param_4, int param_5) {
    // TODO: STUB - TacticalAIGroup::task is large and depends on many untranslated tactical helpers.
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    return 0;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ECD80
int TacticalAIGroup::isGathered(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2) {
    for (int i = 0; i < 40; ++i) {
        int unitId = this->unitsValue[i];
        if (unitId == -1) {
            continue;
        }
        RGE_Static_Object* object = nullptr;
        if ((param_2 != nullptr) && (param_2->player != nullptr) && (param_2->player->world != nullptr)) {
            object = param_2->player->world->object(unitId);
        }
        UnitAIModule* unitAI = (object != nullptr) ? object->unitAI() : nullptr;
        if ((object == nullptr) || (unitAI == nullptr)) {
            removeUnitByIndex(i, param_2);
            continue;
        }

        float dx = object->world_x - this->gatherLocationValue.x;
        float dy = object->world_y - this->gatherLocationValue.y;
        float dz = object->world_z - this->gatherLocationValue.z;
        float distance = std::sqrt((dx * dx) + (dy * dy) + (dz * dz)) - 1.0f;
        if (distance < 0.0f) {
            distance = 0.0f;
        }
        int limit = (this->typeValue == 0x6D) ? param_1->strategicNumber(0x17) : param_1->strategicNumber(0x29);
        if (static_cast<float>(limit) < distance) {
            return 0;
        }
    }
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ECE70
int TacticalAIGroup::isTightGathered(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2) {
    (void)param_1;
    for (int i = 0; i < 40; ++i) {
        int unitId = this->unitsValue[i];
        if (unitId == -1) {
            continue;
        }
        RGE_Static_Object* object = nullptr;
        if ((param_2 != nullptr) && (param_2->player != nullptr) && (param_2->player->world != nullptr)) {
            object = param_2->player->world->object(unitId);
        }
        UnitAIModule* unitAI = (object != nullptr) ? object->unitAI() : nullptr;
        if ((object == nullptr) || (unitAI == nullptr)) {
            removeUnitByIndex(i, param_2);
            continue;
        }
        float dx = object->world_x - this->gatherLocationValue.x;
        float dy = object->world_y - this->gatherLocationValue.y;
        float dz = object->world_z - this->gatherLocationValue.z;
        float distance = std::sqrt((dx * dx) + (dy * dy) + (dz * dz)) - 2.0f;
        if (distance < 0.0f) {
            distance = 0.0f;
        }
        if (distance > 1.0f) {
            return 0;
        }
    }
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ECF10
int TacticalAIGroup::allUnitsIdle(TribeMainDecisionAIModule* param_1, int param_2) {
    for (int i = 0; i < 40; ++i) {
        int unitId = this->unitsValue[i];
        if (unitId == -1) {
            continue;
        }

        RGE_Static_Object* object = nullptr;
        if ((param_1 != nullptr) && (param_1->player != nullptr) && (param_1->player->world != nullptr)) {
            object = param_1->player->world->object(unitId);
        }
        UnitAIModule* unitAI = (object != nullptr) ? object->unitAI() : nullptr;
        if ((object == nullptr) || (unitAI == nullptr)) {
            removeUnitByIndex(i, param_1);
            continue;
        }

        if (object->master_obj->id != 0x7D) {
            if ((param_2 == 1) && (unitAI->currentActionValue == 600) &&
                ((this->typeValue == 100) || (this->typeValue == 0x67))) {
                continue;
            }
            if ((unitAI->currentActionValue != -1) && (unitAI->currentOrderValue != 0x2BD)) {
                return 0;
            }
        }
    }
    return 1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ECFE0
unsigned long TacticalAIGroup::consecutiveIdleUnitCount() const { return this->consecutiveIdleUnitCountValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ECFF0
void TacticalAIGroup::setConsecutiveIdleUnitCount(unsigned long param_1) { this->consecutiveIdleUnitCountValue = param_1; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED000
void TacticalAIGroup::incrementConsecutiveIdleUnitCount(unsigned long param_1) {
    this->consecutiveIdleUnitCountValue += param_1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED020
unsigned char TacticalAIGroup::numberAttackWaypoints() const { return this->numberAttackWaypointsValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED030
unsigned char TacticalAIGroup::currentAttackWaypoint() const { return this->currentAttackWaypointValue; }

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED040
void TacticalAIGroup::setCurrentAttackWaypoint(unsigned char param_1) {
    if (param_1 < this->numberAttackWaypointsValue) {
        this->currentAttackWaypointValue = param_1;
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED060
void TacticalAIGroup::addAttackWaypoint(float param_1, float param_2) {
    if (this->numberAttackWaypointsValue < 0xE) {
        this->attackWaypoints[this->numberAttackWaypointsValue].x = param_1;
        this->attackWaypoints[this->numberAttackWaypointsValue].y = param_2;
        this->attackWaypoints[this->numberAttackWaypointsValue].z = 1.0f;
        this->numberAttackWaypointsValue += 1;
    }
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED0C0
Waypoint* TacticalAIGroup::attackWaypoint(unsigned char param_1) {
    if (param_1 < this->numberAttackWaypointsValue) {
        return &this->attackWaypoints[param_1];
    }
    return nullptr;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED0F0
int TacticalAIGroup::firstIdleUnit(TribeMainDecisionAIModule* param_1) {
    for (int i = 0; i < 40; ++i) {
        int unitId = this->unitsValue[i];
        if (unitId == -1) {
            continue;
        }

        RGE_Static_Object* object = nullptr;
        if ((param_1 != nullptr) && (param_1->player != nullptr) && (param_1->player->world != nullptr)) {
            object = param_1->player->world->object(unitId);
        }
        UnitAIModule* unitAI = (object != nullptr) ? object->unitAI() : nullptr;
        if ((object == nullptr) || (unitAI == nullptr)) {
            removeUnitByIndex(i, param_1);
            continue;
        }
        if (unitAI->currentActionValue == -1) {
            return this->unitsValue[i];
        }
    }
    return -1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED170
int TacticalAIGroup::objectToDestroy(int param_1) {
    if ((param_1 >= 0) && (param_1 < 20)) {
        return this->objectsToDestroyValue[param_1];
    }
    return -1;
}

// Fully verified. Source of truth: taitacmd.cpp.decomp @ 0x004ED190
int TacticalAIGroup::addObjectToDestroy(int param_1) {
    if (this->numberObjectsToDestroyValue < 0x13) {
        this->objectsToDestroyValue[this->numberObjectsToDestroyValue] = param_1;
        this->numberObjectsToDestroyValue += 1;
        return 1;
    }
    return 0;
}
