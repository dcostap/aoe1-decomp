#include "../include/UnitAIModule.h"

#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Visible_Map.h"
#include "../include/Visible_Resource_Manager.h"
#include "../include/VISIBLE_UNIT_REC.h"
#include "../include/VISIBLE_UNIT_PTR.h"
#include "../include/Visible_Unit_Manager.h"
#include "../include/XYZPoint.h"
#include "../include/AIPlayBook.h"
#include "../include/AIPlay.h"
#include "../include/AIPlayPhase.h"
#include "../include/AIPlayPhaseTrigger.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <new>
#include <string.h>

Visible_Unit_Manager* VisibleUnitManager = nullptr;
VISIBLE_UNIT_REC* VisibleUnitList[5] = {};
int VisibleUnitList_Size[5] = {};
int DAT_0087d7cc[5] = {};
int DAT_0087d7d8[5] = {};
int* DAT_0087d7e4[5] = {};
VISIBLE_UNIT_REC* DAT_0087d7f0[5] = {};
int taskedThisUpdate = 0;
int searchedThisUpdate = 0;
int numberVisibleObjects = 0;
int numberDifferentPlayerObjectsVisible = 0;

int GetVisibleUnits(Visible_Unit_Manager* this_, int param_2, int param_3, int param_4, int param_5, int* param_6, int param_7, int* param_8) {
    if (param_6 == nullptr || param_8 == nullptr || this_ == nullptr) {
        return 0;
    }
    for (int i = 0; i < 5; ++i) {
        VisibleUnitList_Size[i] = 0;
        DAT_0087d7cc[i] = 0;
        DAT_0087d7d8[i] = 0;
    }
    if (param_7 < 1 || param_5 < 0 || param_5 >= this_->Player_Count) {
        return 0;
    }
    if (param_4 > 0x0F) {
        param_4 = 0x0F;
    }
    VISIBLE_UNIT_PTR* playerData = this_->PlayerDataPtrs[param_5];
    if (playerData == nullptr || this_->distanceTable == nullptr) {
        return 0;
    }
    int found = 0;
    for (int i = 0; i < param_7; ++i) {
        const int listIndex = param_6[i];
        VISIBLE_UNIT_REC* unitList = playerData[listIndex].unit_list;
        int used = (int)playerData[listIndex].used;
        for (int j = 0; j < used; ++j) {
            const VISIBLE_UNIT_REC& rec = unitList[j];
            const int dx = abs((int)rec.pos_x - param_2);
            const int dy = abs((int)rec.pos_y - param_3);
            const uchar dist = this_->distanceTable[(dx & 0x0F) + ((dy & 0x0F) * 0x10)];
            if ((int)dist > param_4) {
                continue;
            }
            const int category = param_8[rec.player];
            if (category < 0 || category >= 5) {
                continue;
            }
            const int idx = VisibleUnitList_Size[category];
            if (idx < 0x100) {
                if (VisibleUnitList[category] != nullptr) {
                    VISIBLE_UNIT_REC** out = (VISIBLE_UNIT_REC**)&VisibleUnitList[category];
                    out[idx * 2] = (VISIBLE_UNIT_REC*)(intptr_t)rec.object_id;
                    out[idx * 2 + 1] = (VISIBLE_UNIT_REC*)(intptr_t)(uint)dist;
                }
                VisibleUnitList_Size[category] = idx + 1;
                ++found;
            }
        }
    }
    return found;
}

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

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413810
RGE_Player* UnitAIModule::owner() const {
    return this->objectValue->owner;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413820
RGE_Static_Object* UnitAIModule::object() const {
    return this->objectValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413830
int UnitAIModule::objectID() const {
    return (int)this->objectValue->id;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413840
int UnitAIModule::objectCategory() const {
    return this->objectCategoryValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413850
int UnitAIModule::mood() const {
    return this->moodValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413860
unsigned long UnitAIModule::lastUpdateTime() const {
    return this->lastUpdateTimeValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413870
unsigned long UnitAIModule::idleTimer() const {
    return this->idleTimerValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413880
unsigned long UnitAIModule::idleTimeout() const {
    return this->idleTimeoutValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413890
unsigned long UnitAIModule::secondaryTimer() const {
    return this->secondaryTimerValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004138A0
float UnitAIModule::defenseBuffer() const {
    return this->defenseBufferValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004138C0
void UnitAIModule::setDefenseBuffer(float param_1) {
    this->defenseBufferValue = param_1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004138D0
int UnitAIModule::orderQueueSize() const {
    return this->orderQueueSizeValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004138E0
OrderEvent* UnitAIModule::orderQueueElement(int param_1) const {
    if ((-1 < param_1) && (param_1 < this->orderQueueSizeValue) && (this->orderQueueValue != nullptr)) {
        return this->orderQueueValue + param_1;
    }
    return nullptr;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413910
void UnitAIModule::purgeOrderQueue() {
    this->orderQueueSizeValue = 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413920
int UnitAIModule::currentOrder() const {
    return this->currentOrderValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413930
void UnitAIModule::setCurrentOrder(int param_1) {
    this->lastOrderValue = this->currentOrderValue;
    this->currentOrderValue = param_1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413940
int UnitAIModule::currentOrderPriority() const {
    return this->currentOrderPriorityValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413950
void UnitAIModule::setCurrentOrderPriority(int param_1) {
    this->currentOrderPriorityValue = param_1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413960
int UnitAIModule::currentAction() const {
    return this->currentActionValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413970
void UnitAIModule::setCurrentAction(int param_1) {
    this->lastActionValue = this->currentActionValue;
    this->currentActionValue = param_1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413980
int UnitAIModule::currentTarget() const {
    return this->currentTargetValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413990
int UnitAIModule::currentTargetType() const {
    return this->currentTargetTypeValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004139A0
float UnitAIModule::currentTargetX() const {
    return this->currentTargetXValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004139B0
float UnitAIModule::currentTargetY() const {
    return this->currentTargetYValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004139C0
float UnitAIModule::currentTargetZ() const {
    return this->currentTargetZValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004139D0
int UnitAIModule::lastAction() const {
    return this->lastActionValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004139E0
int UnitAIModule::lastOrder() const {
    return this->lastOrderValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004139F0
int UnitAIModule::lastTarget() const {
    return this->lastTargetValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413A00
int UnitAIModule::lastTargetType() const {
    return this->lastTargetTypeValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413A10
float UnitAIModule::desiredTargetDistance() const {
    return this->desiredTargetDistanceValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413A20
int UnitAIModule::attackingUnitID(int param_1) {
    if ((param_1 < 0) || (this->attackingUnitsValue.numberValue <= param_1)) {
        return -1;
    }
    if ((this->attackingUnitsValue.maximumSizeValue - 1) < param_1) {
        const int newMaximum = param_1 + 1;
        int* newValues = (int*)::operator new((size_t)newMaximum * sizeof(int), std::nothrow);
        if (newValues != nullptr) {
            for (int i = 0; i < this->attackingUnitsValue.maximumSizeValue; ++i) {
                if (newMaximum <= i) {
                    break;
                }
                newValues[i] = this->attackingUnitsValue.value[i];
            }
            ::operator delete(this->attackingUnitsValue.value);
            this->attackingUnitsValue.value = newValues;
            this->attackingUnitsValue.maximumSizeValue = newMaximum;
        }
    }
    return this->attackingUnitsValue.value[param_1];
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413AA0
int UnitAIModule::numberAttackingUnits() const {
    return this->attackingUnitsValue.numberValue;
}

// Source of truth: aiuaimod.cpp.decomp @ 0x00414D12 (decompiler helper/thunk label coverage).
// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00414D40
int UnitAIModule::order(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10, int param_11) {
    if (this->objectValue->object_state < 3) {
        if (param_9 == 0) {
            this->addToOrderQueue(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_10, param_11);
            return 1;
        }
        if (param_10 == 1) {
            this->addToOrderQueue((int)this->objectValue->id, this->currentOrderValue, this->currentTargetValue, -1, this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue, this->desiredTargetDistanceValue, 1, this->currentOrderPriorityValue);
        }
        this->addToOrderQueue(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, 1, param_11);
        if (param_2 != 0x2D9) {
            this->removeCurrentTarget();
            if (actionFile != nullptr) {
                const long objectId = (this->objectValue == nullptr) ? -1 : this->objectValue->id;
                fprintf(actionFile, "%d call stopObject %s %d\n", objectId, "C:\\msdev\\work\\age1_x1\\aiuaimod.c", 0x6F3);
            }
            this->stopObject(1);
        }
        this->purgeNotifyQueue(0);
        this->processOrder(this->orderQueueValue, 0);
    }
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00414E80
int UnitAIModule::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    if (this->objectValue->object_state != 2) {
        return 0;
    }
    if (param_3 == 699) {
        const int maxCount = this->attackingUnitsValue.numberValue;
        int index = 0;
        if (0 < maxCount) {
            while (index < this->attackingUnitsValue.maximumSizeValue) {
                if (this->attackingUnitsValue.value[index] == param_1) {
                    break;
                }
                index = index + 1;
                if (maxCount <= index) {
                    return 0;
                }
            }
        }
    }
    else {
        if ((param_3 == 0x1FB) && (param_4 != this->currentActionValue)) {
            return 0;
        }
    }
    if ((param_3 == 0x1FA) &&
        (((param_4 == 0x262 && (this->currentActionValue != 0x262)) && (this->currentActionValue != 0x268)))) {
        return 1;
    }
    return this->addToNotifyQueue(param_1, param_2, param_3, param_4, param_5, param_6);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00414F70
int UnitAIModule::notifyCommander(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    if (this->objectValue->inGroup() == 1) {
        NotifyEvent nEvent;
        nEvent.recipient = param_1;
        nEvent.mType = param_2;
        nEvent.p1 = param_3;
        nEvent.p2 = param_4;
        nEvent.p3 = param_5;
        const int commanderId = this->objectValue->groupCommanderValue;
        if (this->objectValue->id == commanderId) {
            this->notifyCommander(&nEvent);
        }
        else {
            RGE_Static_Object* commander = this->lookupObject(commanderId);
            if (commander != nullptr) {
                UnitAIModule* commanderAI = commander->unitAI();
                if (commanderAI != nullptr) {
                    commanderAI->notifyCommander(&nEvent);
                }
            }
        }
    }
    this->objectValue->owner->notify(param_1, param_2, param_3, param_4, param_5, param_6);
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00414F40
int UnitAIModule::notifyCommander(NotifyEvent* param_1) {
    return this->notify(param_1->caller, param_1->recipient, param_1->mType, param_1->p1, param_1->p2, param_1->p3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415040
void UnitAIModule::search() {
    if (searchedThisUpdate == 1) {
        return;
    }
    searchedThisUpdate = 1;
    if (this->importantObjects != nullptr) {
        RGE_Static_Object* target = nullptr;
        int searchRange = 0;
        int ownerId = 0;
        int* diplomacy = nullptr;
        const int importantCount = this->numberImportantObjects;
        int* importantObjects = this->importantObjects;
        if ((this->currentOrderValue == 0x2BD) && (this->defendTargetValue != -1)) {
            target = this->lookupObject(this->defendTargetValue);
            if (target != nullptr && target->unitAI() != nullptr) {
                searchRange = (int)target->master_obj->los;
                diplomacy = this->objectValue->owner->unitDiplomacy;
                ownerId = (int)target->owner->id;
                const int tileY = (int)target->world_y;
                const int tileX = (int)target->world_x;
                numberVisibleObjects = GetVisibleUnits(VisibleUnitManager, tileX, tileY, searchRange, ownerId, importantObjects, importantCount, diplomacy);
                return;
            }
        }
        target = this->objectValue;
        searchRange = (int)target->master_obj->los;
        if (target->master_obj->id == 0x76) {
            searchRange = searchRange * 2;
        }
        diplomacy = target->owner->unitDiplomacy;
        ownerId = (int)target->owner->id;
        const int tileY = (int)target->world_y;
        const int tileX = (int)target->world_x;
        numberVisibleObjects = GetVisibleUnits(VisibleUnitManager, tileX, tileY, searchRange, ownerId, importantObjects, importantCount, diplomacy);
        return;
    }
    searchedThisUpdate = 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415120
int UnitAIModule::importantWhenDead(int param_1) {
    if ((param_1 != 7) &&
        (param_1 != 9) &&
        (param_1 != 10) &&
        (param_1 != 0x0F) &&
        (param_1 != 8) &&
        (param_1 != 0x20)) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415150
int UnitAIModule::retryableOrder(int param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415160
int UnitAIModule::actionRequiresLiveTarget(int param_1) {
    if ((this->stopAfterTargetKilledValue != 1) &&
        (param_1 != 600) &&
        (param_1 != 0x259) &&
        (param_1 != 0x25B) &&
        (param_1 != 0x25C) &&
        (param_1 != 0x26A) &&
        (param_1 != 0x264)) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004151B0
int UnitAIModule::bestUnitToAttack(int param_1, int param_2, float* param_3) {
    (void)param_1;
    (void)param_2;
    if (param_3 != nullptr) {
        *param_3 = 999999.0f;
    }
    return -1;
}

int UnitAIModule::mostDangerousEnemy(float* param_1) {
    // Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415A10
    return this->bestUnitToAttack(1, 0, param_1);
}

int UnitAIModule::weakestEnemy(float* param_1) {
    // Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415AD0
    return this->bestUnitToAttack(2, 0, param_1);
}

int UnitAIModule::closestAttacker(float* param_1) {
    // Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415B50
    return this->bestUnitToAttack(3, 0, param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415CA0
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
    // Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415E50
    return this->closestObject(-1, -1, param_1, -1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415F40
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

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004161D0
Waypoint* UnitAIModule::waypoint(int param_1) const {
    (void)param_1;
    return nullptr;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004161E0
int UnitAIModule::waypointQueueSize() const {
    return this->waypointQueueSizeValue;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004161F0
int UnitAIModule::addToWaypointQueue(int param_1, int param_2) {
    if (this->waypointQueueSizeValue > 7) {
        this->waypointQueueSizeValue = 0;
    }
    this->waypointQueue[this->waypointQueueSizeValue].x = (float)param_1;
    this->waypointQueue[this->waypointQueueSizeValue].y = (float)param_2;
    this->waypointQueueSizeValue = this->waypointQueueSizeValue + 1;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416240
int UnitAIModule::inWaypointQueue(int param_1, int param_2) const {
    if (this->waypointQueueSizeValue < 1) {
        return 0;
    }
    for (int i = 0; i < this->waypointQueueSizeValue; ++i) {
        if ((this->waypointQueue[i].x == (float)param_1) && (this->waypointQueue[i].y == (float)param_2)) {
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416290
void UnitAIModule::clearWaypointQueue() {
    this->waypointQueueSizeValue = 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004162A0
int UnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    (void)param_1;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004162B0
int UnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004162C0
int UnitAIModule::stopObject(int param_1) {
    if (actionFile != nullptr) {
        fprintf(actionFile, "t%ld uID=%d sO cOAA %d\n", this->objectValue->owner->world->world_time, this->objectValue->id, param_1);
    }
    this->lastActionValue = this->currentActionValue;
    if ((param_1 == 0) || (this->currentActionValue + 100 == this->currentOrderValue)) {
        const int prevOrder = this->currentOrderValue;
        this->currentOrderValue = -1;
        this->lastOrderValue = prevOrder;
        this->currentOrderPriorityValue = -1;
    }
    this->objectValue->stopAction();
    this->currentActionValue = -1;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416340
int UnitAIModule::attackObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue == -1)) {
        RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
        if (target != nullptr) {
            if (this->canAttackUnit(target) != 0) {
                if (this->objectValue->attack(param_1, param_2) == 1) {
                    this->setCurrentAction(600);
                    this->setCurrentTarget(param_1, target->world_x, target->world_y, target->world_z);
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004163C0
int UnitAIModule::attackRoundupObject(int param_1) {
    if (this->currentTargetValue != param_1) {
        RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
        if (target != nullptr && this->canAttackUnit(target) != 0) {
            if (this->currentActionValue != -1) {
                const float weaponRange = this->objectValue->weaponRange();
                if (this->objectValue->canPath(param_1, weaponRange, nullptr, 0, -1, -1) == 0) {
                    return 0;
                }
            }
            if (this->objectValue->attack(param_1, 1) == 1) {
                this->setCurrentAction(600);
                this->setCurrentTarget(param_1, target->world_x, target->world_y, target->world_z);
                return 1;
            }
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416470
int UnitAIModule::huntObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue != 0x265)) {
        if (actionFile != nullptr) {
            const long objectId = (this->objectValue == nullptr) ? -1 : this->objectValue->id;
            fprintf(actionFile, "%d call stopObject %s %d\n", objectId, "C:\\msdev\\work\\age1_x1\\aiuaimod.c", 0xC48);
        }
        this->stopObject(1);
        if (this->objectValue->hunt(param_1, param_2) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x265);
            if (target == nullptr) {
                this->setCurrentTarget(param_1, -1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(param_1, (int)target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416690
int UnitAIModule::gatherObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue != 0x261)) {
        if (this->objectValue->gather(param_1, param_2) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x261);
            if (target == nullptr) {
                this->setCurrentTarget(param_1, -1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(param_1, (int)target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416550
int UnitAIModule::convertObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue != 0x25C)) {
        if (this->objectValue->convert(param_1, param_2) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x25C);
            if (target == nullptr) {
                this->setCurrentTarget(param_1, -1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(param_1, (int)target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004165F0
int UnitAIModule::healObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue != 0x25B)) {
        if (this->objectValue->heal(param_1, param_2) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x25B);
            if (target == nullptr) {
                this->setCurrentTarget(param_1, -1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(param_1, (int)target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416730
int UnitAIModule::repairObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue != 0x26A)) {
        if (this->objectValue->repair(param_1, param_2) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x26A);
            if (target == nullptr) {
                this->setCurrentTarget(param_1, -1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(param_1, (int)target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004167D0
int UnitAIModule::buildObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue != 0x25A)) {
        if (this->objectValue->build(param_1, param_2) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x25A);
            if (target == nullptr) {
                this->setCurrentTarget(param_1, -1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(param_1, (int)target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416870
int UnitAIModule::tradeWithObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue != 0x267)) {
        if (this->objectValue->trade(param_1, param_2) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x267);
            if (target == nullptr) {
                this->setCurrentTarget(param_1, -1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(param_1, (int)target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416910
int UnitAIModule::explore(int param_1, int param_2, int param_3) {
    if ((param_3 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->explore(param_1, param_2, param_3) == 1) {
            this->setCurrentAction(0x25D);
            this->setCurrentTarget(-1, (float)param_3, (float)param_2, 1.0f);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416980
int UnitAIModule::enterObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->enter(param_1, param_2) == 1) {
            this->setCurrentAction(0x269);
            this->setCurrentTarget(param_1, -1.0f, -1.0f, -1.0f);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416A50
int UnitAIModule::unload(int param_1, float param_2, float param_3) {
    if ((param_1 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->unload(param_1, param_2, param_3, this->objectValue->world_z) == 1) {
            RGE_Static_Object* self = this->objectValue;
            this->setCurrentAction(0x26D);
            if (self == nullptr) {
                this->setCurrentTarget(this->objectValue->id, -1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(this->objectValue->id, (int)self->master_obj->object_group, self->world_x, self->world_y, self->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004169E0
int UnitAIModule::transportObject(float param_1, float param_2, float param_3, int param_4) {
    if ((param_4 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->transport(param_1, param_2, param_3, param_4) == 1) {
            this->setCurrentAction(0x266);
            this->setCurrentTarget(-1, param_1, param_2, param_3);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416AF0
int UnitAIModule::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) {
    if ((param_5 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->moveTo(param_1, param_2, param_3, param_4, param_5) == 1) {
            this->setCurrentAction(0x262);
            this->setCurrentTarget(-1, param_1, param_2, param_3);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416B80
int UnitAIModule::moveTo(int param_1, float param_2, int param_3) {
    if ((param_3 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->moveTo(param_1, param_2, param_3) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x262);
            if (target == nullptr) {
                this->setCurrentTarget(param_1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(param_1, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416C10
int UnitAIModule::moveTo(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->moveTo(param_1, param_2) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x262);
            if (target == nullptr) {
                this->setCurrentTarget(param_1, 0.0f, 0.0f, 0.0f);
                return 1;
            }
            this->setCurrentTarget(param_1, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416C80
int UnitAIModule::evasiveMoveTo(float param_1, float param_2, float param_3, int param_4) {
    return this->moveTo(param_1, param_2, param_3, 1.0f, param_4);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416F30
int UnitAIModule::intelligentEvasiveMoveTo(float param_1, float param_2, float param_3, int param_4, int param_5) {
    (void)param_5;
    return this->evasiveMoveTo(param_1, param_2, param_3, param_4);
}

// Source of truth: aiuaimod.cpp.decomp @ 0x004171CA (decompiler helper/thunk label coverage).
// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004171F0
int UnitAIModule::runAwayFromAttackers(int param_1) {
    if ((param_1 == 0) && (this->currentActionValue != -1)) {
        return 0;
    }
    float xDiff = 0.0f;
    float yDiff = 0.0f;
    for (int i = 0; i < this->attackingUnitsValue.numberValue; ++i) {
        if (i >= this->attackingUnitsValue.maximumSizeValue) {
            break;
        }
        RGE_Static_Object* attacker = this->lookupObject(this->attackingUnitsValue.value[i]);
        if (attacker != nullptr) {
            xDiff += (attacker->world_x - this->objectValue->world_x);
            yDiff += (attacker->world_y - this->objectValue->world_y);
        }
    }
    const float distance = (float)sqrt((xDiff * xDiff) + (yDiff * yDiff));
    if (distance <= 0.0f) {
        return 0;
    }
    const float moveDistance = this->objectValue->maximumSpeed() * 4.0f;
    return this->evasiveMoveTo(
        this->objectValue->world_x - ((xDiff / distance) * moveDistance),
        this->objectValue->world_y - ((yDiff / distance) * moveDistance),
        this->objectValue->world_z,
        1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417360
int UnitAIModule::followObject(int param_1, float param_2, int param_3) {
    if ((param_3 == 0) && (this->currentActionValue != -1)) {
        return 0;
    }
    RGE_Static_Object* target = this->lookupObject(param_1);
    if (target == nullptr) {
        return 0;
    }
    this->setCurrentAction(0x264);
    this->setCurrentTarget(param_1, target->world_x, target->world_y, target->world_z);
    this->desiredTargetDistanceValue = param_2;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004173D0
int UnitAIModule::defendObject(int param_1, float param_2, int param_3) {
    if ((param_3 == 0) && (this->currentActionValue != -1)) {
        return 0;
    }
    RGE_Static_Object* target = this->lookupObject(param_1);
    if (target == nullptr) {
        return 0;
    }
    this->setCurrentAction(0x259);
    this->setCurrentTarget(param_1, target->world_x, target->world_y, target->world_z);
    this->desiredTargetDistanceValue = param_2;
    this->defendTargetValue = param_1;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417440
int UnitAIModule::defendPosition(float param_1, float param_2, float param_3, int param_4) {
    this->currentActionValue = 16;
    this->currentTargetXValue = param_1;
    this->currentTargetYValue = param_2;
    this->currentTargetZValue = param_3;
    this->currentTargetTypeValue = param_4;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004174A0
int UnitAIModule::seekAndDestroy(int param_1, int param_2, int param_3, int param_4) {
    (void)param_2;
    (void)param_3;
    this->currentActionValue = 17;
    this->currentTargetTypeValue = param_1;
    this->currentOrderPriorityValue = param_4;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417510
int UnitAIModule::exploreAndDestroy(int param_1, int param_2, int param_3) {
    return this->seekAndDestroy(param_1, param_2, param_3, this->currentOrderPriorityValue);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417640
int UnitAIModule::importantObject(int param_1) {
    for (int i = 0; i < this->numberImportantObjects; ++i) {
        if (this->importantObjects != nullptr && this->importantObjects[i] == param_1) {
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004177C0
int UnitAIModule::convertToLOSResourceType(int param_1) {
    (void)param_1;
    return -1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004138B0
int UnitAIModule::canConvert(int param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417B50
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

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004180C0
int UnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    // Source of truth: aiuaimod.cpp.decomp @ 0x00418045 (decomp branch label coverage)
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

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419510
void UnitAIModule::processGroupNotify(NotifyEvent* param_1) {
    if (this->playStatus == nullptr || this->objectValue == nullptr || this->objectValue->owner == nullptr || this->objectValue->owner->world == nullptr || this->objectValue->owner->world->playbook == nullptr || param_1 == nullptr || param_1->mType != 500) {
        return;
    }
    AIPlay* play = this->objectValue->owner->world->playbook->play(this->playStatus->playNumberValue);
    if (play == nullptr) {
        return;
    }
    AIPlayPhase* phase = play->phase(this->playStatus->currentPhaseValue);
    if (phase == nullptr) {
        return;
    }
    this->playStatus->savedAttackerValue = param_1->caller;
    for (int i = 0; i < 3; ++i) {
        AIPlayPhaseTrigger* trigger = phase->trigger(i);
        if (trigger == nullptr || trigger->typeValue == 0) {
            continue;
        }
        if ((trigger->typeValue == 5) || ((trigger->typeValue == 4) && (trigger->value1Value == this->playStatus->group(param_1->recipient)))) {
            this->selectNewPlayPhase((unsigned int)trigger->nextPhaseValue, 0);
        }
    }
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004195F0
int UnitAIModule::processIdle(int param_1) {
    if ((param_1 == 1) && (this->currentActionValue == 8)) {
        return 6;
    }
    const int target = this->bestUnitToAttack(1, 0, nullptr);
    if ((target != -1) && (this->attackObject(target, 1) == 1)) {
        return 6;
    }
    return 5;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419650
int UnitAIModule::processMisc() {
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419BC0
int UnitAIModule::processRetryableOrder() {
    if (this->retryableOrder(this->lastOrderValue) == 1) {
        const int target = this->closestObject(this->lastTargetTypeValue, -1, -1, -1, nullptr);
        if (target != -1) {
            if (this->lastOrderValue == 0x2C5) {
                return (this->convertObject(target, 0) == 1) ? 8 : 7;
            }
            if (this->lastOrderValue == 0x2C9) {
                return (this->gatherObject(target, 0) == 1) ? 8 : 7;
            }
        }
    }
    return 7;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00413AB0
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

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00414040
void UnitAIModule::updateGroup(unsigned long param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00414800
int UnitAIModule::selectNewPlayPhase(unsigned int param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417580
void UnitAIModule::removeCurrentTarget() {
    const int prevTargetType = this->currentTargetTypeValue;
    this->lastTargetValue = this->currentTargetValue;
    this->currentTargetValue = -1;
    this->currentTargetTypeValue = -1;
    this->lastTargetTypeValue = prevTargetType;
    this->currentTargetXValue = -1.0f;
    this->currentTargetYValue = -1.0f;
    this->currentTargetZValue = -1.0f;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004175B0
void UnitAIModule::setCurrentTarget(int param_1, float param_2, float param_3, float param_4) {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = param_1;
    this->currentTargetXValue = param_2;
    this->currentTargetYValue = param_3;
    this->currentTargetZValue = param_4;
    RGE_Static_Object* target = this->lookupObject(param_1);
    if (target != nullptr && target->master_obj != nullptr) {
        this->currentTargetTypeValue = (int)target->master_obj->object_group;
    }
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417600
void UnitAIModule::setCurrentTarget(int param_1, int param_2, float param_3, float param_4, float param_5) {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = param_1;
    this->currentTargetTypeValue = param_2;
    this->currentTargetXValue = param_3;
    this->currentTargetYValue = param_4;
    this->currentTargetZValue = param_5;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417680
int UnitAIModule::isEnemyOwner(int param_1) {
    RGE_Player* ownerPlayer = this->objectValue->owner;
    if (ownerPlayer->id == param_1) {
        return 0;
    }
    return (ownerPlayer->relations[param_1] == 3) ? 1 : 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004176B0
int UnitAIModule::isAllyOwner(int param_1) {
    RGE_Player* ownerPlayer = this->objectValue->owner;
    if (ownerPlayer->id == param_1) {
        return 1;
    }
    if ((ownerPlayer->relations[param_1] == 0) && (ownerPlayer->world->players[param_1]->relations[ownerPlayer->id] == 0)) {
        return 1;
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417700
int UnitAIModule::isNeutralOwner(int param_1) {
    RGE_Player* ownerPlayer = this->objectValue->owner;
    if (ownerPlayer->id == param_1) {
        return 0;
    }
    return (ownerPlayer->relations[param_1] == 1) ? 1 : 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417730
unsigned char UnitAIModule::visibleStatus(RGE_Visible_Map* param_1, int param_2, int param_3) {
    (void)param_1;
    RGE_Player* ownerPlayer = this->objectValue->owner;
    const unsigned long tileMask = unified_map_offsets[param_3][param_2];
    if ((ownerPlayer->mutualVisibleMask & tileMask) != 0) {
        return 0x0F;
    }
    return ((ownerPlayer->mutualExploredMask & tileMask) != 0) ? 0x80 : 0x00;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004177B0
void UnitAIModule::setTaskedByPlayer() {
    this->purgeNotifyQueue(0);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004177D0
void UnitAIModule::setPlayStatus(AIPlayStatus* param_1) {
    if (this->playStatus == nullptr) {
        this->playStatus = new(std::nothrow) AIPlayStatus();
    }
    if (this->playStatus != nullptr && param_1 != nullptr) {
        memcpy(this->playStatus, param_1, sizeof(AIPlayStatus));
    }
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417860
void UnitAIModule::lookAround() {
    this->lookAroundTimerValue = 0;
    const int r = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.c", 0xF92);
    this->lookAroundTimeoutValue = (unsigned long)(r % 1000 + 4000);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417920
int UnitAIModule::hasOrderOnQueue(int param_1) {
    for (int i = 0; i < this->orderQueueSizeValue; ++i) {
        if (this->orderQueueValue[i].orderType == param_1) {
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417960
void UnitAIModule::askForHelp(int param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419C30
int UnitAIModule::addToOrderQueue(const OrderEvent* param_1, int param_2) {
    if (param_1 == nullptr) {
        return 0;
    }
    return this->addToOrderQueue(param_1->issuer, param_1->orderType, param_1->target, param_1->targetOwner, param_1->targetX, param_1->targetY, param_1->targetZ, param_1->range, param_2, param_1->priority);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419C70
int UnitAIModule::addToOrderQueue(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10) {
    if (this->orderQueueMaxSizeValue == this->orderQueueSizeValue) {
        const int newMax = this->orderQueueMaxSizeValue << 1;
        OrderEvent* grown = (OrderEvent*)::operator new((size_t)newMax * sizeof(OrderEvent), std::nothrow);
        if (grown == nullptr) {
            return 0;
        }
        if (this->orderQueueValue != nullptr && this->orderQueueSizeValue > 0) {
            memcpy(grown, this->orderQueueValue, (size_t)this->orderQueueSizeValue * sizeof(OrderEvent));
        }
        if (this->orderQueueValue != nullptr) {
            ::operator delete(this->orderQueueValue);
        }
        this->orderQueueValue = grown;
        this->orderQueueMaxSizeValue = newMax;
    }
    if (param_9 != 0 && this->orderQueueSizeValue > 0) {
        memmove(this->orderQueueValue + 1, this->orderQueueValue, (size_t)this->orderQueueSizeValue * sizeof(OrderEvent));
        this->orderQueueValue[0].issuer = param_1;
        this->orderQueueValue[0].orderType = param_2;
        this->orderQueueValue[0].priority = param_10;
        this->orderQueueValue[0].target = param_3;
        this->orderQueueValue[0].targetOwner = param_4;
        this->orderQueueValue[0].targetX = param_5;
        this->orderQueueValue[0].targetY = param_6;
        this->orderQueueValue[0].targetZ = param_7;
        this->orderQueueValue[0].range = param_8;
        ++this->orderQueueSizeValue;
        return 1;
    }
    this->orderQueueValue[this->orderQueueSizeValue].issuer = param_1;
    this->orderQueueValue[this->orderQueueSizeValue].orderType = param_2;
    this->orderQueueValue[this->orderQueueSizeValue].priority = param_10;
    this->orderQueueValue[this->orderQueueSizeValue].target = param_3;
    this->orderQueueValue[this->orderQueueSizeValue].targetOwner = param_4;
    this->orderQueueValue[this->orderQueueSizeValue].targetX = param_5;
    this->orderQueueValue[this->orderQueueSizeValue].targetY = param_6;
    this->orderQueueValue[this->orderQueueSizeValue].targetZ = param_7;
    this->orderQueueValue[this->orderQueueSizeValue].range = param_8;
    ++this->orderQueueSizeValue;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419ED0
int UnitAIModule::addToNotifyQueue(const NotifyEvent* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    return this->addToNotifyQueue(param_1->caller, param_1->recipient, param_1->mType, param_1->p1, param_1->p2, param_1->p3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419F00
int UnitAIModule::addToNotifyQueue(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    if (this->notifyQueueMaxSizeValue == this->notifyQueueSizeValue) {
        const int newMax = this->notifyQueueMaxSizeValue << 1;
        NotifyEvent* grown = (NotifyEvent*)::operator new((size_t)newMax * sizeof(NotifyEvent), std::nothrow);
        if (grown == nullptr) {
            return 0;
        }
        if (this->notifyQueueValue != nullptr && this->notifyQueueSizeValue > 0) {
            memcpy(grown, this->notifyQueueValue, (size_t)this->notifyQueueSizeValue * sizeof(NotifyEvent));
        }
        if (this->notifyQueueValue != nullptr) {
            ::operator delete(this->notifyQueueValue);
        }
        this->notifyQueueValue = grown;
        this->notifyQueueMaxSizeValue = newMax;
    }
    this->notifyQueueValue[this->notifyQueueSizeValue].caller = param_1;
    this->notifyQueueValue[this->notifyQueueSizeValue].recipient = param_2;
    this->notifyQueueValue[this->notifyQueueSizeValue].mType = param_3;
    this->notifyQueueValue[this->notifyQueueSizeValue].p1 = param_4;
    this->notifyQueueValue[this->notifyQueueSizeValue].p2 = param_5;
    this->notifyQueueValue[this->notifyQueueSizeValue].p3 = param_6;
    ++this->notifyQueueSizeValue;
    return 1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x0041A020
void UnitAIModule::purgeNotifyQueue(unsigned long param_1) {
    this->notifyQueueSizeValue = 0;
    this->lastUpdateTimeValue = param_1;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x0041A0D0
RGE_Static_Object* UnitAIModule::lookupObject(int param_1) {
    if (this->objectValue != nullptr && this->objectValue->owner != nullptr && this->objectValue->owner->world != nullptr) {
        return this->objectValue->owner->world->object(param_1);
    }
    return nullptr;
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x0041A100
void UnitAIModule::logDebug(char* param_1) {
    if (param_1 == nullptr) {
        return;
    }
    char textOut[1024];
    va_list args;
    va_start(args, param_1);
    vsnprintf(textOut, sizeof(textOut), param_1, args);
    va_end(args);
}


