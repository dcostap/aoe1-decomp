#include "../include/TribeUnitAIModules.h"

#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/VISIBLE_UNIT_REC.h"
#include "../include/globals.h"

#include <cmath>
#include <new>

extern int* DAT_0087d7e4[5];
extern VISIBLE_UNIT_REC* DAT_0087d7f0[5];

namespace {
void initializeImportantObjects(UnitAIModule* module, const int* values, int count) {
    module->numberImportantObjects = count;
    module->importantObjects = new (std::nothrow) int[count];
    if (module->importantObjects == nullptr) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        module->importantObjects[i] = values[i];
    }
}

void setField100(UnitAIModule* module, int value) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(module) + 0x100) = value;
}

void addAttackingUnitIfMissing(UnitAIModule* module, int attackerId) {
    for (int i = 0; i < module->attackingUnitsValue.numberValue; ++i) {
        if (i >= module->attackingUnitsValue.maximumSizeValue) {
            break;
        }
        if (module->attackingUnitsValue.value[i] == attackerId) {
            return;
        }
    }

    const int currentCount = module->attackingUnitsValue.numberValue;
    if (module->attackingUnitsValue.maximumSizeValue - 1 < currentCount) {
        const int newMaximum = currentCount + 1;
        int* newValues = new (std::nothrow) int[newMaximum];
        if (newValues != nullptr) {
            for (int i = 0; i < module->attackingUnitsValue.maximumSizeValue; ++i) {
                newValues[i] = module->attackingUnitsValue.value[i];
            }
            delete[] module->attackingUnitsValue.value;
            module->attackingUnitsValue.value = newValues;
            module->attackingUnitsValue.maximumSizeValue = newMaximum;
        }
    }

    module->attackingUnitsValue.value[module->attackingUnitsValue.numberValue] = attackerId;
    module->attackingUnitsValue.numberValue = module->attackingUnitsValue.numberValue + 1;
}
} // namespace

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00507880
TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 4, 0x1A, 0x18, 6, 0x23, 0x19, 0x11, 0x0C, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x16, 0x14, 2, 0x15, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x13);
    setField100(this, 5000);
    setAdjustedIdleTimeout();
}

TribeArtifactUnitAIModule::~TribeArtifactUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504B60
TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 7, 8, 9, 10, 0x0F, 0x11, 0x12, 0x20, 0x21, 0x1B};
    initializeImportantObjects(this, kImportantObjects, 0x0B);
}

TribeCivilianUnitAIModule::~TribeCivilianUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505820
TribePriestUnitAIModule::TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 0, 4, 0x1A, 0x18, 6, 0x19, 0x11, 10, 0x0C, 0x23, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x11);
}

TribePriestUnitAIModule::~TribePriestUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00503BB0
TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 4, 0x1A, 0x18, 6, 0x19, 0x11, 10, 0x0C, 0x23, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x10);
    setField100(this, 4000);
    setAdjustedIdleTimeout();
}

TribeHuntedAnimalUnitAIModule::~TribeHuntedAnimalUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504170
TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {}

TribeElephantUnitAIModule::~TribeElephantUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005042E0
TribeLionUnitAIModule::TribeLionUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0x1D, 9, 0, 4, 0x1A, 0x18, 6, 0x19, 0x11, 0x0D, 0x0C, 0x23, 0x17, 0x24, 0x1C, 0x12, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x11);
    setField100(this, 6000);
    setAdjustedIdleTimeout();
}

TribeLionUnitAIModule::~TribeLionUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00503F20
TribePreditorUnitAIModule::TribePreditorUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0x1D, 9, 0, 4, 0x1A, 0x18, 6, 0x19, 0x11, 0x0D, 0x0C, 0x23, 0x17, 0x24, 0x1C, 0x12, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x11);
}

TribePreditorUnitAIModule::~TribePreditorUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506B70
TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 0x16, 0x14, 2, 0x15, 5, 0x1F, 0x21};
    initializeImportantObjects(this, kImportantObjects, 8);
}

TribeFishingShipUnitAIModule::~TribeFishingShipUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506240
TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 0x16, 0x14, 2, 0x15};
    initializeImportantObjects(this, kImportantObjects, 5);
}

TribeTradeShipUnitAIModule::~TribeTradeShipUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005067D0
TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 0x16, 0x14, 2, 0x15};
    initializeImportantObjects(this, kImportantObjects, 5);
}

TribeTransportShipUnitAIModule::~TribeTransportShipUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00508170
TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 3, 4, 0x1A, 0x18, 6, 0x23, 0x19, 0x11, 0x0C, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x1B, 0x16, 0x14, 2, 0x15, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x15);
}

TribeBuildingUnitAIModule::~TribeBuildingUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00507F60
TribeTowerUnitAIModule::TribeTowerUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 3, 4, 0x1A, 0x18, 6, 0x23, 0x19, 0x11, 0x0C, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x1B, 0x16, 0x14, 2, 0x15, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x15);
}

TribeTowerUnitAIModule::~TribeTowerUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506FE0
TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 3, 4, 0x1A, 0x18, 6, 0x23, 0x19, 0x11, 0x0C, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x1B, 0x16, 0x14, 2, 0x15, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x15);
    setField100(this, 0x5DC);
    setAdjustedIdleTimeout();
}

TribeSoldierUnitAIModule::~TribeSoldierUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504700
TribeRangedUnitAIModule::TribeRangedUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {}

TribeRangedUnitAIModule::~TribeRangedUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504880
TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {}

TribeRangedUnitAIModule2::~TribeRangedUnitAIModule2() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005040A0
int TribePreditorUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 1;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005040B0
int TribePreditorUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType == 0x1FC) {
        RGE_Static_Object* target = this->lookupObject(this->currentTargetValue);
        if (target != nullptr) {
            const float distance = this->objectValue->distance_to_object(target);
            if (distance <= this->objectValue->weaponRange()) {
                this->attackObject(this->currentTargetValue, 1);
                return 3;
            }
        }

        this->removeCurrentTarget();
        this->stopObject(1);
        this->processGroupNotify(param_1);
    }
    return UnitAIModule::processNotify(param_1, param_2);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00503D30
int TribeHuntedAnimalUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType != 500) {
        if (param_1->mType != 0x20F) {
            return UnitAIModule::processNotify(param_1, param_2);
        }
        return 2;
    }

    if (param_1->p2 < 1) {
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    addAttackingUnitIfMissing(this, param_1->caller);
    this->objectValue->setUnderAttack(1);
    this->runAwayFromAttackers(1);
    return 3;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00503E30
int TribeHuntedAnimalUnitAIModule::processIdle(int param_1) {
    (void)param_1;
    const int targetId = this->closestObject(-1, -1, -1, -1, nullptr);
    if (targetId != -1) {
        RGE_Static_Object* target = this->lookupObject(targetId);
        if (target != nullptr) {
            const float speed = this->objectValue->maximumSpeed();
            const float dx = target->world_x - this->objectValue->world_x;
            const float dy = target->world_y - this->objectValue->world_y;
            const float distance = std::sqrt((dy * dy) + (dx * dx));
            this->defendPosition(((-dx / distance) * (speed * 3.0f)) + this->objectValue->world_x,
                                 ((-dy / distance) * (speed * 3.0f)) + this->objectValue->world_y,
                                 this->objectValue->world_z,
                                 1);
            return 6;
        }
    }

    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005041C0
int TribeElephantUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType != 500) {
        if (param_1->mType != 0x20F) {
            return UnitAIModule::processNotify(param_1, param_2);
        }
        return 2;
    }

    if (param_1->p2 < 1) {
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    addAttackingUnitIfMissing(this, param_1->caller);
    this->objectValue->setUnderAttack(1);
    this->attackObject(this->closestAttacker(nullptr), 0);
    return 3;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005042D0
int TribeElephantUnitAIModule::processIdle(int param_1) {
    (void)param_1;
    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504470
int TribeLionUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 1;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504480
int TribeLionUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType == 0x1FA && param_1->p1 == 600) {
        setField100(this, 25000);
        this->setAdjustedIdleTimeout();
        this->removeCurrentTarget();
        this->stopObject(1);
    } else if (param_1->mType == 0x1FC) {
        RGE_Static_Object* target = this->lookupObject(this->currentTargetValue);
        if (target != nullptr && this->objectValue->distance_to_object(target) <= this->objectValue->weaponRange()) {
            this->attackObject(this->currentTargetValue, 1);
            return 3;
        }
        this->removeCurrentTarget();
        this->stopObject(1);
        this->processGroupNotify(param_1);
        return UnitAIModule::processNotify(param_1, param_2);
    }
    return UnitAIModule::processNotify(param_1, param_2);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504600
int TribeLionUnitAIModule::processIdle(int param_1) {
    (void)param_1;
    setField100(this, 6000);
    this->setAdjustedIdleTimeout();
    const int targetId = this->closestObject(-1, -1, -1, -1, nullptr);
    if (targetId == -1) {
        return 5;
    }
    RGE_Static_Object* target = this->lookupObject(targetId);
    if (target == nullptr) {
        return 5;
    }
    const int difficulty = this->objectValue->owner->world->difficultyLevel();
    float maxReactDistance;
    if (difficulty > 2) {
        maxReactDistance = (difficulty == 3 ? 0.75f : 0.5f) * this->objectValue->master_obj->los;
        if (maxReactDistance < 1.0f) {
            maxReactDistance = 1.0f;
        }
    } else {
        maxReactDistance = this->objectValue->master_obj->los * 2.0f;
    }
    if (maxReactDistance < this->objectValue->distance_to_object(target)) {
        return 5;
    }
    this->attackObject(targetId, 0);
    return 6;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504750
int TribeRangedUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType != 0x200) {
        return UnitAIModule::processNotify(param_1, param_2);
    }
    if (this->currentOrderValue == 600) {
        RGE_Static_Object* target = this->lookupObject(this->currentTargetValue);
        if (target != nullptr && target->weaponRange() != 0.0f) {
            this->order(this->objectValue->id, 700, this->currentOrderPriorityValue, this->currentTargetValue, -1, this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue, 0.0f, 1, this->currentActionValue);
            const float speed = this->objectValue->maximumSpeed();
            const float range = this->objectValue->weaponRange() * speed * 3.0f;
            const float dx = target->world_x - this->objectValue->world_x;
            const float dy = target->world_y - this->objectValue->world_y;
            const float distance = std::sqrt((dy * dy) + (dx * dx));
            this->evasiveMoveTo(((-dx / distance) * range) + this->objectValue->world_x, ((-dy / distance) * range) + this->objectValue->world_y, this->objectValue->world_z, 1);
            return 3;
        }
    }
    return 2;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005048D0
int TribeRangedUnitAIModule2::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType != 0x200) {
        return UnitAIModule::processNotify(param_1, param_2);
    }
    if (this->currentOrderValue != 600) {
        return 2;
    }
    RGE_Static_Object* target = this->lookupObject(this->currentTargetValue);
    if (target == nullptr || target->weaponRange() == 0.0f) {
        return 2;
    }

    this->order(this->objectValue->id, 700, this->currentOrderPriorityValue, this->currentTargetValue, -1, this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue, 0.0f, 1, this->currentActionValue);
    const float speed = this->objectValue->maximumSpeed();
    const float evasiveMoveDistance = this->objectValue->weaponRange() * speed * 3.0f;
    float xDiff = target->world_x - this->objectValue->world_x;
    float yDiff = target->world_y - this->objectValue->world_y;
    for (int i = 0; i < this->attackingUnitsValue.numberValue && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == this->currentTargetValue) {
            continue;
        }
        RGE_Static_Object* attacker = this->lookupObject(this->attackingUnitsValue.value[i]);
        if (attacker != nullptr) {
            xDiff += attacker->world_x - this->objectValue->world_x;
            yDiff += attacker->world_y - this->objectValue->world_y;
        }
    }
    const float distance = std::sqrt((yDiff * yDiff) + (xDiff * xDiff));
    this->evasiveMoveTo(((-xDiff / distance) * evasiveMoveDistance) + this->objectValue->world_x,
                        ((-yDiff / distance) * evasiveMoveDistance) + this->objectValue->world_y,
                        this->objectValue->world_z,
                        1);
    return 3;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004195F0
int TribeRangedUnitAIModule2::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504C90
int TribeCivilianUnitAIModule::importantWhenDead(int param_1) {
    return this->importantObject(param_1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504CC0
int TribeCivilianUnitAIModule::attackObject(int param_1, int param_2) {
    RGE_Static_Object* target = this->lookupObject(param_1);
    if (target == nullptr) {
        return 0;
    }
    const short group = target->master_obj->object_group;
    if (group == 9 || group == 10 || group == 0x0F) {
        return this->huntObject(param_1, param_2);
    }
    return UnitAIModule::attackObject(param_1, param_2);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504D20
int TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    return UnitAIModule::canAttackUnit(param_1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504D40
int TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504D50
int TribeCivilianUnitAIModule::retryableOrder(int param_1) {
    return UnitAIModule::retryableOrder(param_1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504D80
int TribeCivilianUnitAIModule::convertToLOSResourceType(int param_1) {
    switch (param_1) {
        case 7:
            return 1;
        case 5:
        case 0x1F:
        case 0x21:
            return 2;
        case 8:
            return 3;
        case 0x0F:
            return 0;
        case 0x20:
            return 4;
        default:
            return -1;
    }
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504E10
int TribeCivilianUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    // Source of truth: taiuaimd.cpp.decomp @ 0x00504DC6 (decompiler helper/thunk label coverage).
    if (param_1->mType == 500 || param_1->mType == 0x20F) {
        if (param_1->p2 < 1) {
            this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x209, param_1->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }
        if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
            this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x201, param_1->caller, 0, 0);
        }
        addAttackingUnitIfMissing(this, param_1->caller);
        this->objectValue->setUnderAttack(1);
        if (this->currentOrderValue != 700) {
            this->runAwayFromAttackers(1);
        }
        return 3;
    }
    return UnitAIModule::processNotify(param_1, param_2);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505800
int TribeCivilianUnitAIModule::processIdle(int param_1) {
    // Source of truth: taiuaimd.cpp.decomp @ 0x005057BE (decompiler helper/thunk label coverage).
    (void)param_1;
    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505810
int TribeCivilianUnitAIModule::processMisc() {
    return 9;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005059A0
int TribePriestUnitAIModule::attackObject(int param_1, int param_2) {
    (void)param_2;
    if (this->canConvert(param_1) != 0) {
        return this->convertObject(param_1, param_1);
    }
    if (this->currentActionValue == -1 && this->objectValue->owner->computerPlayer() != 0) {
        return this->defendObject(param_1, this->objectValue->weaponRange(), 0);
    }
    return 0;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505A10
int TribePriestUnitAIModule::retryableOrder(int param_1) {
    switch (param_1) {
        case 1:
        case 2:
        case 6:
        case 7:
            return 1;
        default:
            return 0;
    }
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505A30
int TribePriestUnitAIModule::canConvert(int param_1) {
    (void)param_1;
    return 1;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505AE0
int TribePriestUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    return this->canConvert(param_1->id);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505B00
int TribePriestUnitAIModule::bestUnitToHeal(int param_1, float* param_2) {
    int allyToHealID = -1;
    int bestNeedScore = 0;
    int maxLimit = -1;

    int relationshipPasses = 1;
    if (this->objectValue->owner->id == 0) {
        relationshipPasses = 2;
    }

    for (int pass = 1; pass <= relationshipPasses; ++pass) {
        const int listIndex = pass - 1;
        if ((&DAT_0087d7cc)[listIndex] <= 0) {
            continue;
        }

        int* listBase = DAT_0087d7e4[listIndex];
        for (int i = 0; i < (&DAT_0087d7cc)[listIndex]; ++i) {
            const int entryOffset = i * 2;
            const int objectID = listBase[entryOffset];
            const int playerRelation = listBase[entryOffset + 1];
            if (objectID == this->objectValue->id) {
                continue;
            }

            RGE_Static_Object* ally = this->lookupObject(objectID);
            if (ally == nullptr) {
                continue;
            }
            if (ally->master_obj->object_group == 3) {
                continue;
            }
            if (ally->object_state >= 3) {
                continue;
            }
            if (ally->hp >= (float)(int)ally->master_obj->hp) {
                continue;
            }
            if (param_1 == 0 && playerRelation >= 5) {
                continue;
            }
            if (this->objectValue->owner->id == 0 && playerRelation >= 3) {
                continue;
            }

            float weight = (float)playerRelation;
            float needScore = (float)(int)ally->master_obj->hp - (ally->hp / weight);
            if (maxLimit == -1 || needScore < (float)bestNeedScore) {
                maxLimit = ally->id;
                bestNeedScore = (int)needScore;
                if (param_2 != nullptr) {
                    *param_2 = weight;
                }
            }
        }

        allyToHealID = maxLimit;
        if (allyToHealID != -1) {
            return allyToHealID;
        }
    }

    return -1;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505CC0
int TribePriestUnitAIModule::bestUnitToConvert(float* param_1) {
    int bestTargetID = -1;
    int bestScore = 0;
    for (int i = 0; i < (&DAT_0087d7d8)[0]; ++i) {
        const int objectID = DAT_0087d7f0[0][i].object_id;
        const int enemyPlayer = DAT_0087d7f0[0][i].player;
        if (this->objectValue->owner->isEnemy(enemyPlayer) == 0) {
            continue;
        }

        RGE_Static_Object* target = this->lookupObject(objectID);
        if (target == nullptr || target->object_state >= 3) {
            continue;
        }
        if (this->canConvert(target->id) == 0) {
            continue;
        }

        float weight = (float)enemyPlayer;
        if (weight < 1.0f) {
            weight = 1.0f;
        }
        float score = (float)(int)target->master_obj->hp / weight;
        if (bestTargetID == -1 || (float)bestScore < score) {
            bestTargetID = target->id;
            bestScore = (int)score;
            if (param_1 != nullptr) {
                *param_1 = weight;
            }
        }
    }

    return bestTargetID;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505DD0
int TribePriestUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType == 0x1FC) {
        this->removeCurrentTarget();
        this->stopObject(1);
        this->processGroupNotify(param_1);
    } else if (param_1->mType == 0x1F9 || param_1->mType == 0x1FB || param_1->mType == 0x202) {
        if (this->objectValue->owner->computerPlayer() == 0 && this->currentOrderValue == 0x25C) {
            this->removeCurrentTarget();
            this->stopObject(1);
            this->processGroupNotify(param_1);
            return 2;
        }
    }
    return UnitAIModule::processNotify(param_1, param_2);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505FD0
int TribePriestUnitAIModule::processIdle(int param_1) {
    // Source of truth: taiuaimd.cpp.decomp @ 0x00505FA9 (decompiler helper/thunk label coverage).
    (void)param_1;
    if (this->objectValue->owner->computerPlayer() != 0) {
        if (UnitAIModule::processIdle(1) == 6) {
            return 6;
        }
        const int targetId = this->closestObject(-1, 2, -1, -1, nullptr);
        if (targetId != -1) {
            RGE_Static_Object* target = this->lookupObject(targetId);
            if (target != nullptr) {
                const float xDiff = target->world_x - this->objectValue->world_x;
                const float yDiff = target->world_y - this->objectValue->world_y;
                const float distance = std::sqrt((yDiff * yDiff) + (xDiff * xDiff));
                const float pullback = this->objectValue->weaponRange() - distance;
                if (pullback > 0.0f) {
                    this->evasiveMoveTo(((-xDiff / distance) * pullback) + this->objectValue->world_x,
                                        ((-yDiff / distance) * pullback) + this->objectValue->world_y,
                                        this->objectValue->world_z,
                                        1);
                    return 6;
                }
            }
        }
    }
    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506140
int TribePriestUnitAIModule::processMisc() {
    if (this->objectValue->owner->computerPlayer() != 0 && this->objectValue->world_z >= 100.0f) {
        const int targetId = this->bestUnitToAttack(1, 1, nullptr);
        if (targetId != -1 && this->currentTargetValue != targetId) {
            if (this->currentActionValue != -1) {
                this->order(this->objectValue->id, this->currentActionValue, this->currentOrderPriorityValue, this->currentTargetValue, -1, this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue, 0.0f, 0, this->currentActionValue);
                this->stopObject(1);
            }
            if (this->attackObject(targetId, 1) == 1) {
                return 10;
            }
        }
    }
    return 9;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506320
int TribeTradeShipUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType != 500 && param_1->mType != 0x20F) {
        return UnitAIModule::processNotify(param_1, param_2);
    }
    if (param_1->p2 < 1) {
        this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x209, param_1->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }
    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x201, param_1->caller, 0, 0);
    }
    if (this->objectValue->owner->computerPlayer() == 0 && this->currentTargetValue != param_1->caller) {
        this->askForHelp(param_1->caller);
    }
    addAttackingUnitIfMissing(this, param_1->caller);
    this->objectValue->setUnderAttack(1);
    if (!(this->objectValue->owner->computerPlayer() == 0 && this->currentActionValue != -1)) {
        if (this->currentOrderValue != 0x262) {
            this->order(this->objectValue->id, this->currentActionValue, this->currentOrderPriorityValue, this->currentTargetValue, -1, this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue, 0.0f, 0, this->currentActionValue);
            this->stopObject(1);
        }
        this->runAwayFromAttackers(1);
    }
    return 3;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005066D0
int TribeTradeShipUnitAIModule::processIdle(int param_1) {
    (void)param_1;
    if (this->objectValue->owner->computerPlayer() != 0) {
        const int targetId = this->closestObject(-1, -1, -1, -1, nullptr);
        if (targetId != -1) {
            RGE_Static_Object* target = this->lookupObject(targetId);
            if (target != nullptr) {
                const float speed = this->objectValue->maximumSpeed();
                const float dx = target->world_x - this->objectValue->world_x;
                const float dy = target->world_y - this->objectValue->world_y;
                const float distance = std::sqrt((dy * dy) + (dx * dx));
                this->evasiveMoveTo(((-dx / distance) * (speed * 7.0f)) + this->objectValue->world_x,
                                    ((-dy / distance) * (speed * 7.0f)) + this->objectValue->world_y,
                                    this->objectValue->world_z,
                                    1);
                return 6;
            }
        }
    }
    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005068B0
int TribeTransportShipUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType != 500 && param_1->mType != 0x20F) {
        return UnitAIModule::processNotify(param_1, param_2);
    }
    if (param_1->p2 < 1) {
        this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x209, param_1->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }
    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x201, param_1->caller, 0, 0);
    }
    if (this->objectValue->owner->computerPlayer() == 0 && this->currentTargetValue != param_1->caller) {
        this->askForHelp(param_1->caller);
    }
    addAttackingUnitIfMissing(this, param_1->caller);
    this->objectValue->setUnderAttack(1);
    if (this->currentActionValue == -1) {
        this->runAwayFromAttackers(1);
    }
    return 3;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506A70
int TribeTransportShipUnitAIModule::processIdle(int param_1) {
    (void)param_1;
    if (this->objectValue->owner->computerPlayer() != 0) {
        const int targetId = this->closestObject(-1, -1, -1, -1, nullptr);
        if (targetId != -1) {
            RGE_Static_Object* target = this->lookupObject(targetId);
            if (target != nullptr) {
                const float speed = this->objectValue->maximumSpeed();
                const float dx = target->world_x - this->objectValue->world_x;
                const float dy = target->world_y - this->objectValue->world_y;
                const float distance = std::sqrt((dy * dy) + (dx * dx));
                this->evasiveMoveTo(((-dx / distance) * (speed * 7.0f)) + this->objectValue->world_x,
                                    ((-dy / distance) * (speed * 7.0f)) + this->objectValue->world_y,
                                    this->objectValue->world_z,
                                    1);
                return 6;
            }
        }
    }
    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506C70
int TribeFishingShipUnitAIModule::importantWhenDead(int param_1) {
    return this->importantObject(param_1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506C90
int TribeFishingShipUnitAIModule::convertToLOSResourceType(int param_1) {
    if (param_1 == 5 || param_1 == 0x1F || param_1 == 0x21) {
        return 2;
    }
    return -1;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506CC0
int TribeFishingShipUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType != 500 && param_1->mType != 0x20F) {
        return UnitAIModule::processNotify(param_1, param_2);
    }
    if (param_1->p2 < 1) {
        this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x209, param_1->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }
    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x201, param_1->caller, 0, 0);
    }
    if (this->objectValue->owner->computerPlayer() == 0 && this->currentTargetValue != param_1->caller) {
        this->askForHelp(param_1->caller);
    }
    addAttackingUnitIfMissing(this, param_1->caller);
    this->objectValue->setUnderAttack(1);
    if (!(this->objectValue->owner->computerPlayer() == 0 && this->currentActionValue != -1)) {
        if (this->currentOrderValue != 0x262) {
            this->order(this->objectValue->id, this->currentActionValue, this->currentOrderPriorityValue, this->currentTargetValue, -1, this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue, 0.0f, 0, this->currentActionValue);
            this->stopObject(1);
        }
        this->runAwayFromAttackers(1);
    }
    return 3;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506EE0
int TribeFishingShipUnitAIModule::processIdle(int param_1) {
    (void)param_1;
    if (this->objectValue->owner->computerPlayer() != 0) {
        const int targetId = this->closestObject(-1, -1, -1, -1, nullptr);
        if (targetId != -1) {
            RGE_Static_Object* target = this->lookupObject(targetId);
            if (target != nullptr) {
                const float speed = this->objectValue->maximumSpeed();
                const float dx = target->world_x - this->objectValue->world_x;
                const float dy = target->world_y - this->objectValue->world_y;
                const float distance = std::sqrt((dy * dy) + (dx * dx));
                this->evasiveMoveTo(((-dx / distance) * (speed * 7.0f)) + this->objectValue->world_x,
                                    ((-dy / distance) * (speed * 7.0f)) + this->objectValue->world_y,
                                    this->objectValue->world_z,
                                    1);
                return 6;
            }
        }
    }
    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005071A0
int TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    return static_cast<int>(param_1->master_obj->object_group != 1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005071C0
int TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    if (param_1 == 3 || param_1 == 0x1B || param_1 == 4 || param_1 == 0x15 || param_1 == 2 || param_1 == 0x14) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005071F0
int TribeSoldierUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType == 0x200 && this->objectValue->owner->computerPlayer() != 0 && this->objectValue->weaponRange() >= 1.0f && this->objectValue->master_obj->id != 0x1A) {
        if (this->currentOrderValue == 600) {
            RGE_Static_Object* target = this->lookupObject(this->currentTargetValue);
            if (target != nullptr) {
                const float distanceDiff = this->objectValue->weaponRange() - this->objectValue->distance_to_object(target);
                if (distanceDiff >= 1.0f) {
                    this->order(this->objectValue->id, 700, this->currentOrderPriorityValue, this->currentTargetValue, -1, this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue, 0.0f, 1, this->currentActionValue);
                    float xDiff = 0.0f;
                    float yDiff = this->currentTargetZValue;
                    for (int i = 0; i < this->attackingUnitsValue.numberValue && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
                        if (this->attackingUnitsValue.value[i] == this->currentTargetValue) {
                            continue;
                        }
                        RGE_Static_Object* attacker = this->lookupObject(this->attackingUnitsValue.value[i]);
                        if (attacker != nullptr) {
                            xDiff += attacker->world_x - this->objectValue->world_x;
                            yDiff += attacker->world_y - this->objectValue->world_y;
                        }
                    }
                    const float distance = std::sqrt((yDiff * yDiff) + (xDiff * xDiff));
                    if (this->intelligentEvasiveMoveTo(((-xDiff / distance) * this->currentTargetXValue) + this->objectValue->world_x,
                                                       ((-yDiff / distance) * this->currentTargetXValue) + this->objectValue->world_y,
                                                       this->objectValue->world_z,
                                                       0,
                                                       1) == 1) {
                        return 3;
                    }
                    return 2;
                }
            }
        }
        return 2;
    }
    return UnitAIModule::processNotify(param_1, param_2);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00507640
int TribeSoldierUnitAIModule::processIdle(int param_1) {
    if (param_1 == 1 && this->processRetryableOrder() == 8) {
        return 6;
    }
    if (this->bestUnitToAttack(1, 0, nullptr) != -1) {
        if (this->attackObject(this->bestUnitToAttack(1, 0, nullptr), 1) == 1) {
            return 6;
        }
    }
    if (this->objectValue->owner->computerPlayer() != 0 && this->currentActionValue != 0x2BD && this->currentActionValue != 0x2D5) {
        const int targetId = this->closestObject(-1, -1, -1, -1, nullptr);
        if (targetId != -1) {
            RGE_Static_Object* target = this->lookupObject(targetId);
            if (target != nullptr) {
                const float speed = this->objectValue->maximumSpeed();
                const float dx = target->world_x - this->objectValue->world_x;
                const float dy = target->world_y - this->objectValue->world_y;
                const float distance = std::sqrt((dy * dy) + (dx * dx));
                this->evasiveMoveTo(((-dx / distance) * (speed * 3.0f)) + this->objectValue->world_x,
                                    ((-dy / distance) * (speed * 3.0f)) + this->objectValue->world_y,
                                    this->objectValue->world_z,
                                    1);
                return 6;
            }
        }
    }
    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00507A30
int TribeArtifactUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    switch (param_1->mType) {
        case 600:
            addAttackingUnitIfMissing(this, param_1->caller);
            this->objectValue->setUnderAttack(1);
            return 2;
        case 0x1FC: {
            this->removeCurrentTarget();
            break;
        }
        case 0x1F9:
        case 0x1FA:
        case 0x1FB:
            if (this->currentActionValue != -1 && this->currentOrderValue + 100 == this->currentActionValue) {
                this->removeCurrentTarget();
                break;
            }
            if (this->currentOrderValue != param_1->p1) {
                return 2;
            }
            this->removeCurrentTarget();
            break;
        default:
            if (param_1->mType != 500 && param_1->mType != 0x1F6 && param_1->mType != 0x1F7 && param_1->mType != 0x1F8 &&
                param_1->mType != 0x1FD && param_1->mType != 0x1FE && param_1->mType != 0x1FF && param_1->mType != 0x200 &&
                param_1->mType != 0x202 && param_1->mType != 0x203 && param_1->mType != 0x20B && param_1->mType != 0x20F &&
                param_1->mType != 0x259 && param_1->mType != 0x25A && param_1->mType != 0x25B && param_1->mType != 0x25C &&
                param_1->mType != 0x25D && param_1->mType != 0x25E && param_1->mType != 0x25F && param_1->mType != 0x260 &&
                param_1->mType != 0x261 && param_1->mType != 0x262 && param_1->mType != 0x265 && param_1->mType != 0x266 &&
                param_1->mType != 0x267 && param_1->mType != 0x268 && param_1->mType != 0x269 && param_1->mType != 699) {
                this->removeCurrentTarget();
                break;
            }
            return 2;
    }
    this->stopObject(1);
    this->processGroupNotify(param_1);
    (void)param_2;
    return 2;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00507E90
int TribeArtifactUnitAIModule::processIdle(int param_1) {
    (void)param_1;
    const int targetId = this->closestObject(-1, -1, -1, -1, nullptr);
    if (targetId != -1) {
        RGE_Static_Object* target = this->lookupObject(targetId);
        if (target != nullptr && this->objectValue->owner != target->owner) {
            this->objectValue->change_ownership(target->owner);
            return 6;
        }
    }
    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00507EF0
int TribeArtifactUnitAIModule::processMisc() {
    if (this->processIdle(1) == 6) {
        this->removeCurrentTarget();
        this->stopObject(1);
        this->secondaryTimerValue = 0;
        return 10;
    }
    return 9;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00508110
int TribeTowerUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (param_1->master_obj->object_group == 1) {
        return 0;
    }
    return static_cast<int>(this->objectValue->actionState() > 1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00508140
int TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 1;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00508320
int TribeBuildingUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    if (param_1->mType == 699) {
        for (int i = 0; i < this->attackingUnitsValue.numberValue && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == param_1->caller) {
                for (int j = i; j < this->attackingUnitsValue.maximumSizeValue - 1; ++j) {
                    this->attackingUnitsValue.value[j] = this->attackingUnitsValue.value[j + 1];
                }
                this->attackingUnitsValue.numberValue--;
                if (this->attackingUnitsValue.numberValue < 0) {
                    this->attackingUnitsValue.numberValue = 0;
                }
                break;
            }
        }
        return 2;
    }
    if (param_1->mType == 600) {
        addAttackingUnitIfMissing(this, param_1->caller);
        this->objectValue->setUnderAttack(1);
        return 2;
    }
    if (param_1->mType != 500) {
        return 2;
    }
    if (param_1->p2 < 1) {
        this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x209, param_1->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }
    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x201, param_1->caller, 0, 0);
    }
    if (this->objectValue->owner->computerPlayer() == 0 && this->currentTargetValue != param_1->caller) {
        this->askForHelp(param_1->caller);
    }
    addAttackingUnitIfMissing(this, param_1->caller);
    this->objectValue->setUnderAttack(1);
    return 2;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00508660
int TribeBuildingUnitAIModule::processIdle(int param_1) {
    (void)param_1;
    return 5;
}
