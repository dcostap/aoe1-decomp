#include "../include/UnitAIModule.h"

#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
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
    this->adjustedIdleTimeoutValue = this->idleTimeoutValue;
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

