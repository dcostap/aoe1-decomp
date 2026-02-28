#include "../include/UnitAIModule.h"

#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <new>
#include <string.h>

AIPlayStatus::AIPlayStatus() {
    memset(this->bytes, 0, sizeof(this->bytes));
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413450 (called from UnitAIModule::load)
void AIPlayStatus::load(int fd) {
    rge_read(fd, this->bytes, (int)sizeof(this->bytes));
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413150 (called from UnitAIModule::save)
void AIPlayStatus::save(int fd) {
    rge_write(fd, this->bytes, (int)sizeof(this->bytes));
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00412F00
UnitAIModule::UnitAIModule(RGE_Static_Object* param_1, int param_2) {
    this->objectValue = param_1;
    this->moodValue = -1;
    this->objectCategoryValue = -1;
    this->orderQueueSizeValue = 0;
    this->orderQueueMaxSizeValue = param_2;
    this->orderQueueValue = nullptr;
    this->notifyQueueSizeValue = 0;
    this->notifyQueueMaxSizeValue = param_2;
    this->notifyQueueValue = nullptr;
    this->currentOrderValue = -1;
    this->currentOrderPriorityValue = -1;
    this->currentActionValue = -1;
    this->currentTargetValue = -1;
    this->currentTargetTypeValue = -1;
    this->currentTargetXValue = -1.0f;
    this->currentTargetYValue = -1.0f;
    this->currentTargetZValue = -1.0f;
    this->desiredTargetDistanceValue = 2.0f;
    this->defendTargetValue = -1;
    this->lastOrderValue = -1;
    this->lastActionValue = -1;
    this->lastTargetValue = -1;
    this->lastTargetTypeValue = -1;

    this->attackingUnitsValue.value = nullptr;
    this->attackingUnitsValue.numberValue = 0;
    this->attackingUnitsValue.desiredNumberValue = 0;
    this->attackingUnitsValue.maximumSizeValue = 10;
    this->attackingUnitsValue.value = (int*)::operator new(0x28, std::nothrow);
    if (this->attackingUnitsValue.value != nullptr) {
        memset(this->attackingUnitsValue.value, 0, 0x28);
    }

    memset(this->waypointQueue, 0, sizeof(this->waypointQueue));
    this->waypointQueueSizeValue = 0;
    this->lastUpdateTimeValue = 0;
    this->idleTimerValue = 0;
    this->idleTimeoutValue = 3000;
    this->adjustedIdleTimeoutValue = 3000;
    this->secondaryTimerValue = 0;
    this->lookAroundTimerValue = 0;
    this->lookAroundTimeoutValue = 1000;
    this->defenseBufferValue = 1.0f;
    this->importantObjects = nullptr;
    this->numberImportantObjects = 0;
    this->playStatus = nullptr;
    this->stopAfterTargetKilledValue = '\0';

    if (param_1 != nullptr && param_1->master_obj != nullptr) {
        this->objectCategoryValue = (int)param_1->master_obj->object_group;
        this->defenseBufferValue = param_1->master_obj->los;
    }

    if (this->orderQueueMaxSizeValue > 0) {
        this->orderQueueValue = (OrderEvent*)::operator new((size_t)this->orderQueueMaxSizeValue * sizeof(OrderEvent), std::nothrow);
        if (this->orderQueueValue != nullptr) {
            memset(this->orderQueueValue, 0, (size_t)this->orderQueueMaxSizeValue * sizeof(OrderEvent));
        }
    }

    if (this->notifyQueueMaxSizeValue > 0) {
        this->notifyQueueValue = (NotifyEvent*)::operator new((size_t)this->notifyQueueMaxSizeValue * sizeof(NotifyEvent), std::nothrow);
        if (this->notifyQueueValue != nullptr) {
            memset(this->notifyQueueValue, 0, (size_t)this->notifyQueueMaxSizeValue * sizeof(NotifyEvent));
        }
    }

    this->lastWorldPositionValue.x = -1.0f;
    this->lastWorldPositionValue.y = -1.0f;
    this->lastWorldPositionValue.z = -1.0f;
    this->lastWorldPositionValue.facetToNextWaypoint = 0;

    this->setAdjustedIdleTimeout();
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413090
UnitAIModule::~UnitAIModule() {
    if (this->orderQueueValue != nullptr) {
        ::operator delete(this->orderQueueValue);
        this->orderQueueValue = nullptr;
    }
    if (this->notifyQueueValue != nullptr) {
        ::operator delete(this->notifyQueueValue);
        this->notifyQueueValue = nullptr;
    }
    if (this->importantObjects != nullptr) {
        ::operator delete(this->importantObjects);
        this->importantObjects = nullptr;
    }
    if (this->playStatus != nullptr) {
        delete this->playStatus;
        this->playStatus = nullptr;
    }
    if (this->attackingUnitsValue.value != nullptr) {
        ::operator delete(this->attackingUnitsValue.value);
        this->attackingUnitsValue.value = nullptr;
    }
    this->attackingUnitsValue.numberValue = 0;
    this->attackingUnitsValue.desiredNumberValue = 0;
    this->attackingUnitsValue.maximumSizeValue = 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417770
void UnitAIModule::setAdjustedIdleTimeout() {
    const unsigned long timeout = this->idleTimeoutValue;
    if (timeout <= 1) {
        this->adjustedIdleTimeoutValue = timeout;
        return;
    }
    const unsigned long randomValue = (unsigned long)debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.c", 0xF4C);
    this->adjustedIdleTimeoutValue = (randomValue % (timeout >> 1)) + ((timeout * 3) >> 2);
}

int UnitAIModule::addToOrderQueue(const OrderEvent* param_1, int param_2) {
    (void)param_2;
    if (param_1 == nullptr || this->orderQueueValue == nullptr) {
        return 0;
    }
    if (this->orderQueueSizeValue < 0 || this->orderQueueMaxSizeValue <= 0) {
        return 0;
    }
    if (this->orderQueueSizeValue >= this->orderQueueMaxSizeValue) {
        return 0;
    }
    this->orderQueueValue[this->orderQueueSizeValue] = *param_1;
    this->orderQueueSizeValue = this->orderQueueSizeValue + 1;
    return 1;
}

int UnitAIModule::addToNotifyQueue(const NotifyEvent* param_1) {
    if (param_1 == nullptr || this->notifyQueueValue == nullptr) {
        return 0;
    }
    if (this->notifyQueueSizeValue < 0 || this->notifyQueueMaxSizeValue <= 0) {
        return 0;
    }
    if (this->notifyQueueSizeValue >= this->notifyQueueMaxSizeValue) {
        return 0;
    }
    this->notifyQueueValue[this->notifyQueueSizeValue] = *param_1;
    this->notifyQueueSizeValue = this->notifyQueueSizeValue + 1;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413150
void UnitAIModule::save(int param_1) {
    int fd = param_1;
    rge_write(fd, &this->moodValue, 4);
    rge_write(fd, &this->currentOrderValue, 4);
    rge_write(fd, &this->currentOrderPriorityValue, 4);
    rge_write(fd, &this->currentActionValue, 4);
    rge_write(fd, &this->currentTargetValue, 4);
    rge_write(fd, &this->currentTargetTypeValue, 4);
    rge_write(fd, &this->currentTargetXValue, 4);
    rge_write(fd, &this->currentTargetYValue, 4);
    rge_write(fd, &this->currentTargetZValue, 4);
    rge_write(fd, &this->desiredTargetDistanceValue, 4);
    rge_write(fd, &this->lastActionValue, 4);
    rge_write(fd, &this->lastOrderValue, 4);
    rge_write(fd, &this->lastTargetValue, 4);
    rge_write(fd, &this->lastTargetTypeValue, 4);
    rge_write(fd, &this->lastUpdateTimeValue, 4);
    rge_write(fd, &this->idleTimerValue, 4);
    rge_write(fd, &this->idleTimeoutValue, 4);
    rge_write(fd, &this->adjustedIdleTimeoutValue, 4);
    rge_write(fd, &this->secondaryTimerValue, 4);
    rge_write(fd, &this->lookAroundTimerValue, 4);
    rge_write(fd, &this->lookAroundTimeoutValue, 4);
    rge_write(fd, &this->defendTargetValue, 4);
    rge_write(fd, &this->defenseBufferValue, 4);
    rge_write(fd, &this->lastWorldPositionValue, 0x10);

    rge_write(fd, &this->orderQueueSizeValue, 4);
    for (int i = 0; i < this->orderQueueSizeValue; ++i) {
        rge_write(fd, &this->orderQueueValue[i], (int)sizeof(OrderEvent));
    }

    rge_write(fd, &this->notifyQueueSizeValue, 4);
    for (int i = 0; i < this->notifyQueueSizeValue; ++i) {
        rge_write(fd, &this->notifyQueueValue[i], (int)sizeof(NotifyEvent));
    }

    int numberUnits = this->attackingUnitsValue.numberValue;
    rge_write(fd, &numberUnits, 4);
    for (int i = 0; i < this->attackingUnitsValue.numberValue; ++i) {
        if (this->attackingUnitsValue.value == nullptr || this->attackingUnitsValue.maximumSizeValue <= i) {
            break;
        }
        int unit_id = this->attackingUnitsValue.value[i];
        rge_write(fd, &unit_id, 4);
    }

    int hasPlay = (this->playStatus != nullptr) ? 1 : 0;
    rge_write(fd, &hasPlay, 4);
    if (this->playStatus != nullptr) {
        this->playStatus->save(fd);
    }

    rge_write(fd, &this->stopAfterTargetKilledValue, 1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413450
void UnitAIModule::load(int param_1) {
    int fd = param_1;

    rge_read(fd, &this->moodValue, 4);
    rge_read(fd, &this->currentOrderValue, 4);
    rge_read(fd, &this->currentOrderPriorityValue, 4);
    rge_read(fd, &this->currentActionValue, 4);
    rge_read(fd, &this->currentTargetValue, 4);
    rge_read(fd, &this->currentTargetTypeValue, 4);
    rge_read(fd, &this->currentTargetXValue, 4);
    rge_read(fd, &this->currentTargetYValue, 4);
    rge_read(fd, &this->currentTargetZValue, 4);
    rge_read(fd, &this->desiredTargetDistanceValue, 4);
    rge_read(fd, &this->lastActionValue, 4);
    rge_read(fd, &this->lastOrderValue, 4);
    rge_read(fd, &this->lastTargetValue, 4);
    rge_read(fd, &this->lastTargetTypeValue, 4);
    rge_read(fd, &this->lastUpdateTimeValue, 4);
    rge_read(fd, &this->idleTimerValue, 4);
    rge_read(fd, &this->idleTimeoutValue, 4);
    rge_read(fd, &this->adjustedIdleTimeoutValue, 4);
    rge_read(fd, &this->secondaryTimerValue, 4);

    if (save_game_version < 6.93f) {
        this->lookAroundTimerValue = 0;
        this->lookAroundTimeoutValue = 1000;
    } else {
        rge_read(fd, &this->lookAroundTimerValue, 4);
        rge_read(fd, &this->lookAroundTimeoutValue, 4);
    }

    rge_read(fd, &this->defendTargetValue, 4);
    rge_read(fd, &this->defenseBufferValue, 4);
    rge_read(fd, &this->lastWorldPositionValue, 0x10);

    int numberOrders = 0;
    rge_read(fd, &numberOrders, 4);
    for (int i = 0; i < numberOrders; ++i) {
        OrderEvent evt{};
        rge_read(fd, &evt, (int)sizeof(evt));
        this->addToOrderQueue(&evt, 0);
    }

    int numberNotifies = 0;
    rge_read(fd, &numberNotifies, 4);
    for (int i = 0; i < numberNotifies; ++i) {
        NotifyEvent evt{};
        rge_read(fd, &evt, (int)sizeof(evt));
        this->addToNotifyQueue(&evt);
    }

    int numberUnits = 0;
    rge_read(fd, &numberUnits, 4);
    for (int i = 0; i < numberUnits; ++i) {
        int unit_id = 0;
        rge_read(fd, &unit_id, 4);

        int existing = 0;
        for (int j = 0; j < this->attackingUnitsValue.numberValue; ++j) {
            if (this->attackingUnitsValue.value == nullptr || this->attackingUnitsValue.maximumSizeValue <= j) {
                break;
            }
            if (this->attackingUnitsValue.value[j] == unit_id) {
                existing = 1;
                break;
            }
        }
        if (existing) {
            continue;
        }

        int current_count = this->attackingUnitsValue.numberValue;
        if (this->attackingUnitsValue.maximumSizeValue - 1 < current_count) {
            int new_max = current_count + 1;
            int* new_values = (int*)::operator new((size_t)new_max * sizeof(int), std::nothrow);
            if (new_values != nullptr) {
                for (int j = 0; j < this->attackingUnitsValue.maximumSizeValue; ++j) {
                    if (new_max <= j) break;
                    if (this->attackingUnitsValue.value != nullptr) {
                        new_values[j] = this->attackingUnitsValue.value[j];
                    }
                }
                ::operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = new_values;
                this->attackingUnitsValue.maximumSizeValue = new_max;
            }
        }

        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = unit_id;
        this->attackingUnitsValue.numberValue = this->attackingUnitsValue.numberValue + 1;
    }

    int hasPlayStatus = 0;
    rge_read(fd, &hasPlayStatus, 4);
    if (hasPlayStatus == 1) {
        this->playStatus = new(std::nothrow) AIPlayStatus();
        if (this->playStatus != nullptr) {
            this->playStatus->load(fd);
        }
    }

    if (save_game_version >= 7.02f) {
        rge_read(fd, &this->stopAfterTargetKilledValue, 1);
    }
}

RGE_Player* UnitAIModule::owner() const {
    return (this->objectValue != nullptr) ? this->objectValue->owner : nullptr;
}

RGE_Static_Object* UnitAIModule::object() const {
    return this->objectValue;
}

int UnitAIModule::objectID() const {
    return (this->objectValue != nullptr) ? (int)this->objectValue->id : -1;
}

// TODO: aiuaimod parity pass is still in progress for UnitAIModule decision logic.
int UnitAIModule::order(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10, int param_11) {
    OrderEvent evt{};
    evt.issuer = param_1;
    evt.orderType = param_2;
    evt.priority = param_3;
    evt.target = param_4;
    evt.targetOwner = param_9;
    evt.targetX = param_5;
    evt.targetY = param_6;
    evt.targetZ = param_7;
    evt.range = param_8;
    (void)param_10;
    (void)param_11;
    return this->addToOrderQueue(&evt, 0);
}

// TODO: aiuaimod parity pass is still in progress for UnitAIModule decision logic.
int UnitAIModule::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    NotifyEvent evt{};
    evt.caller = param_1;
    evt.recipient = param_2;
    evt.mType = param_3;
    evt.p1 = param_4;
    evt.p2 = param_5;
    evt.p3 = param_6;
    return this->addToNotifyQueue(&evt);
}

// TODO: aiuaimod parity pass is still in progress for UnitAIModule decision logic.
int UnitAIModule::notifyCommander(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    return this->notify(param_1, param_2, param_3, param_4, param_5, param_6);
}

// TODO: aiuaimod parity pass is still in progress for UnitAIModule decision logic.
int UnitAIModule::notifyCommander(NotifyEvent* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    return this->addToNotifyQueue(param_1);
}

// TODO: aiuaimod parity pass is still in progress for UnitAIModule decision logic.
void UnitAIModule::search() {}

int UnitAIModule::importantWhenDead(int param_1) {
    return this->importantObject(param_1);
}

int UnitAIModule::retryableOrder(int param_1) {
    switch (param_1) {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0xA:
        case 0xB:
        case 0xC:
            return 1;
        default:
            return 0;
    }
}

int UnitAIModule::actionRequiresLiveTarget(int param_1) {
    switch (param_1) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
            return 1;
        default:
            return 0;
    }
}

// TODO: aiuaimod parity pass is still in progress for UnitAIModule target scoring.
int UnitAIModule::bestUnitToAttack(int param_1, int param_2, float* param_3) {
    (void)param_1;
    (void)param_2;
    if (param_3 != nullptr) {
        *param_3 = 999999.0f;
    }
    return -1;
}

int UnitAIModule::mostDangerousEnemy(float* param_1) {
    return this->bestUnitToAttack(1, 0, param_1);
}

int UnitAIModule::weakestEnemy(float* param_1) {
    return this->bestUnitToAttack(2, 0, param_1);
}

int UnitAIModule::closestAttacker(float* param_1) {
    return this->bestUnitToAttack(3, 0, param_1);
}

// TODO: aiuaimod parity pass is still in progress for object selection.
int UnitAIModule::closestObject(int param_1, int param_2, int param_3, int param_4, int* param_5) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    if (param_5 != nullptr) {
        *param_5 = -1;
    }
    return -1;
}

int UnitAIModule::closestResourceObject(int param_1, int* param_2) {
    return this->closestObject(-1, -1, param_1, -1, param_2);
}

// TODO: aiuaimod parity pass is still in progress for exploration heuristics.
int UnitAIModule::closestUndiscoveredTile(int* param_1, int* param_2, int param_3) {
    (void)param_3;
    if (param_1 != nullptr) {
        *param_1 = -1;
    }
    if (param_2 != nullptr) {
        *param_2 = -1;
    }
    return 0;
}

// TODO: aiuaimod parity pass is still in progress for debug logging parity.
void UnitAIModule::logDebug(char* param_1) {
    (void)param_1;
}

int UnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    return param_1 != nullptr;
}

int UnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 0;
}

int UnitAIModule::stopObject(int param_1) {
    this->currentOrderValue = -1;
    this->currentActionValue = -1;
    this->currentTargetValue = -1;
    this->currentTargetTypeValue = -1;
    if (param_1 != 0) {
        this->orderQueueSizeValue = 0;
    }
    return 1;
}

int UnitAIModule::attackObject(int param_1, int param_2) {
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentActionValue = 1;
    return 1;
}

int UnitAIModule::attackRoundupObject(int param_1) {
    return this->attackObject(param_1, 0);
}

int UnitAIModule::huntObject(int param_1, int param_2) {
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentActionValue = 2;
    return 1;
}

int UnitAIModule::gatherObject(int param_1, int param_2) {
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentActionValue = 3;
    return 1;
}

int UnitAIModule::convertObject(int param_1, int param_2) {
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentActionValue = 4;
    return 1;
}

int UnitAIModule::healObject(int param_1, int param_2) {
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentActionValue = 5;
    return 1;
}

int UnitAIModule::repairObject(int param_1, int param_2) {
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentActionValue = 6;
    return 1;
}

int UnitAIModule::buildObject(int param_1, int param_2) {
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentActionValue = 7;
    return 1;
}

int UnitAIModule::tradeWithObject(int param_1, int param_2) {
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentActionValue = 8;
    return 1;
}

int UnitAIModule::explore(int param_1, int param_2, int param_3) {
    this->currentActionValue = 9;
    this->currentTargetValue = -1;
    this->currentTargetTypeValue = param_1;
    this->currentTargetXValue = (float)param_2;
    this->currentTargetYValue = (float)param_3;
    return 1;
}

int UnitAIModule::enterObject(int param_1, int param_2) {
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentActionValue = 10;
    return 1;
}

int UnitAIModule::unload(int param_1, float param_2, float param_3) {
    (void)param_1;
    this->currentActionValue = 11;
    this->currentTargetXValue = param_2;
    this->currentTargetYValue = param_3;
    return 1;
}

int UnitAIModule::transportObject(float param_1, float param_2, float param_3, int param_4) {
    this->currentActionValue = 12;
    this->currentTargetXValue = param_1;
    this->currentTargetYValue = param_2;
    this->currentTargetZValue = param_3;
    this->currentTargetTypeValue = param_4;
    return 1;
}

int UnitAIModule::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) {
    this->currentActionValue = 13;
    this->currentTargetXValue = param_1;
    this->currentTargetYValue = param_2;
    this->currentTargetZValue = param_3;
    this->desiredTargetDistanceValue = param_4;
    this->currentTargetTypeValue = param_5;
    return 1;
}

int UnitAIModule::moveTo(int param_1, float param_2, int param_3) {
    return this->moveTo((float)param_1, param_2, this->currentTargetZValue, this->desiredTargetDistanceValue, param_3);
}

int UnitAIModule::moveTo(int param_1, int param_2) {
    return this->moveTo((float)param_1, (float)param_2, this->currentTargetZValue, this->desiredTargetDistanceValue, this->currentTargetTypeValue);
}

int UnitAIModule::evasiveMoveTo(float param_1, float param_2, float param_3, int param_4) {
    return this->moveTo(param_1, param_2, param_3, 1.0f, param_4);
}

int UnitAIModule::intelligentEvasiveMoveTo(float param_1, float param_2, float param_3, int param_4, int param_5) {
    (void)param_5;
    return this->evasiveMoveTo(param_1, param_2, param_3, param_4);
}

int UnitAIModule::runAwayFromAttackers(int param_1) {
    (void)param_1;
    return 0;
}

int UnitAIModule::followObject(int param_1, float param_2, int param_3) {
    this->currentActionValue = 14;
    this->currentTargetValue = param_1;
    this->desiredTargetDistanceValue = param_2;
    this->currentTargetTypeValue = param_3;
    return 1;
}

int UnitAIModule::defendObject(int param_1, float param_2, int param_3) {
    this->currentActionValue = 15;
    this->currentTargetValue = param_1;
    this->desiredTargetDistanceValue = param_2;
    this->currentTargetTypeValue = param_3;
    this->defendTargetValue = param_1;
    return 1;
}

int UnitAIModule::defendPosition(float param_1, float param_2, float param_3, int param_4) {
    this->currentActionValue = 16;
    this->currentTargetXValue = param_1;
    this->currentTargetYValue = param_2;
    this->currentTargetZValue = param_3;
    this->currentTargetTypeValue = param_4;
    return 1;
}

int UnitAIModule::seekAndDestroy(int param_1, int param_2, int param_3, int param_4) {
    (void)param_2;
    (void)param_3;
    this->currentActionValue = 17;
    this->currentTargetTypeValue = param_1;
    this->currentOrderPriorityValue = param_4;
    return 1;
}

int UnitAIModule::exploreAndDestroy(int param_1, int param_2, int param_3) {
    return this->seekAndDestroy(param_1, param_2, param_3, this->currentOrderPriorityValue);
}

int UnitAIModule::importantObject(int param_1) {
    for (int i = 0; i < this->numberImportantObjects; ++i) {
        if (this->importantObjects != nullptr && this->importantObjects[i] == param_1) {
            return 1;
        }
    }
    return 0;
}

int UnitAIModule::convertToLOSResourceType(int param_1) {
    (void)param_1;
    return -1;
}

int UnitAIModule::canConvert(int param_1) {
    (void)param_1;
    return 0;
}

int UnitAIModule::processOrder(OrderEvent* param_1, int param_2) {
    if (param_1 == nullptr) {
        return 0;
    }

    this->currentOrderValue = param_1->orderType;
    this->currentOrderPriorityValue = param_1->priority;
    this->lastOrderValue = param_1->orderType;
    this->lastTargetValue = param_1->target;
    this->lastTargetTypeValue = param_1->targetOwner;

    switch (param_1->orderType) {
        case 1: return this->stopObject(param_2);
        case 2: return this->attackObject(param_1->target, param_1->targetOwner);
        case 3: return this->attackRoundupObject(param_1->target);
        case 4: return this->huntObject(param_1->target, param_1->targetOwner);
        case 5: return this->gatherObject(param_1->target, param_1->targetOwner);
        case 6: return this->convertObject(param_1->target, param_1->targetOwner);
        case 7: return this->healObject(param_1->target, param_1->targetOwner);
        case 8: return this->repairObject(param_1->target, param_1->targetOwner);
        case 9: return this->buildObject(param_1->target, param_1->targetOwner);
        case 10: return this->tradeWithObject(param_1->target, param_1->targetOwner);
        case 11: return this->explore(param_1->targetOwner, (int)param_1->targetX, (int)param_1->targetY);
        case 12: return this->enterObject(param_1->target, param_1->targetOwner);
        case 13: return this->unload(param_1->target, param_1->targetX, param_1->targetY);
        case 14: return this->transportObject(param_1->targetX, param_1->targetY, param_1->targetZ, param_1->targetOwner);
        case 15: return this->moveTo(param_1->targetX, param_1->targetY, param_1->targetZ, param_1->range, param_1->targetOwner);
        case 16: return this->followObject(param_1->target, param_1->range, param_1->targetOwner);
        case 17: return this->defendObject(param_1->target, param_1->range, param_1->targetOwner);
        case 18: return this->defendPosition(param_1->targetX, param_1->targetY, param_1->targetZ, param_1->targetOwner);
        case 19: return this->seekAndDestroy(param_1->target, param_1->targetOwner, param_2, param_1->priority);
        case 20: return this->exploreAndDestroy(param_1->target, param_1->targetOwner, param_2);
        default: return 0;
    }
}

// TODO: aiuaimod parity pass is still in progress for notify dispatcher behavior.
int UnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    (void)param_2;
    if (param_1 == nullptr) {
        return 0;
    }
    if (param_1->mType == 0x20f) {
        return 2;
    }
    if (param_1->mType == 500 && param_1->p2 < 1) {
        this->notifyQueueSizeValue = 0;
        return 4;
    }
    return 1;
}

void UnitAIModule::processGroupNotify(NotifyEvent* param_1) {
    (void)param_1;
}

int UnitAIModule::processIdle(int param_1) {
    (void)param_1;
    return 5;
}

int UnitAIModule::processMisc() {
    return 0;
}

int UnitAIModule::processRetryableOrder() {
    if (this->orderQueueSizeValue <= 0 || this->orderQueueValue == nullptr) {
        return 0;
    }
    return this->processOrder(&this->orderQueueValue[0], 1);
}

// TODO: decomp transliteration in progress (aiuaimod.cpp.decomp @ 0x00413AB0)
int UnitAIModule::update(unsigned long param_1) {
    if (this->objectValue == nullptr) {
        return 0;
    }

    if (this->notifyQueueSizeValue > 0 && this->notifyQueueValue != nullptr) {
        for (int i = 0; i < this->notifyQueueSizeValue; ++i) {
            const int result = this->processNotify(&this->notifyQueueValue[i], param_1);
            if (result == 4) {
                this->notifyQueueSizeValue = 0;
                break;
            }
            if (result == 3) {
                break;
            }
        }
    }
    this->notifyQueueSizeValue = 0;

    if (this->currentActionValue == -1 && this->orderQueueSizeValue > 0 && this->orderQueueValue != nullptr) {
        for (int i = 0; i < this->orderQueueSizeValue; ++i) {
            if (this->processOrder(&this->orderQueueValue[i], i) == 1) {
                break;
            }
        }
    }

    this->processMisc();
    this->idleTimerValue += param_1;
    this->secondaryTimerValue += param_1;
    this->lookAroundTimerValue += param_1;
    if (this->adjustedIdleTimeoutValue < this->idleTimerValue) {
        this->idleTimerValue = 0;
        this->processIdle(1);
    }

    return 1;
}

// TODO: decomp transliteration in progress (aiuaimod.cpp.decomp @ 0x00414040)
void UnitAIModule::updateGroup(unsigned long param_1) {
    (void)param_1;
}

