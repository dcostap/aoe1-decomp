#include "../include/aiuaimod.h"
#include "../include/game_globals.h"
#include "../include/rge_base_game_global.h"
#include "../include/act_obj.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char str_aiuaimod_path[] = "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp";
extern const char str_fmt_stopObject[] = "#%d call stopObject %s %d\n";

// aiuaimod.cpp

// The shipped constructor uses a real polymorphic UnitAIModule surface.
// The managed attacking-unit array is a normal member.


UnitAIModule::UnitAIModule(RGE_Static_Object* o, int iQS)
    : objectValue(o),
      moodValue(-1),
      objectCategoryValue(-1),
      orderQueueSizeValue(0),
      orderQueueMaxSizeValue(iQS),
      notifyQueueSizeValue(0),
      notifyQueueMaxSizeValue(iQS),
      currentOrderValue(-1),
      currentOrderPriorityValue(-1),
      currentActionValue(-1),
      currentTargetValue(-1),
      currentTargetTypeValue(-1),
      currentTargetXValue(-1.0f),
      currentTargetYValue(-1.0f),
      currentTargetZValue(-1.0f),
      desiredTargetDistanceValue(2.0f),
      defendTargetValue(-1),
      lastOrderValue(-1),
      lastActionValue(-1),
      lastTargetValue(-1),
      lastTargetTypeValue(-1),
      attackingUnitsValue(10),
      waypointQueueSizeValue(0),
      lastUpdateTimeValue(0),
      idleTimerValue(0),
      idleTimeoutValue(3000),
      secondaryTimerValue(0),
      lookAroundTimerValue(0),
      lookAroundTimeoutValue(1000),
      defenseBufferValue(1.0f),
      importantObjects(0),
      numberImportantObjects(0),
      playStatus(0),
      stopAfterTargetKilledValue(0) {

    if (o != 0) {
        objectCategoryValue = o->master_obj->object_group;
        defenseBufferValue = o->master_obj->los;
    }

    orderQueueValue = (OrderEvent*)operator new(orderQueueMaxSizeValue * 0x24);
    notifyQueueValue = (NotifyEvent*)operator new(notifyQueueMaxSizeValue * 0x18);

    lastWorldPositionValue.x = -1.0f;
    lastWorldPositionValue.y = -1.0f;
    lastWorldPositionValue.z = -1.0f;

    setAdjustedIdleTimeout();
}

// aiuaimod.cpp


UnitAIModule::~UnitAIModule() {
    if (orderQueueValue) {
        delete orderQueueValue;
        orderQueueValue = 0;
    }
    if (notifyQueueValue) {
        delete notifyQueueValue;
        notifyQueueValue = 0;
    }
    if (importantObjects) {
        delete importantObjects;
        importantObjects = 0;
    }
    if (playStatus) {
        delete playStatus;
        playStatus = 0;
    }
}



void __cdecl rge_write(int fd, void* data, int size);

void UnitAIModule::save(int outfile) {
    int i;
    int tempInt;
    int num;
    int* ptr;
    int cnt;
    int* newArr;
    int j;

    rge_write(outfile, &moodValue, 4);
    rge_write(outfile, &currentOrderValue, 4);
    rge_write(outfile, &currentOrderPriorityValue, 4);
    rge_write(outfile, &currentActionValue, 4);
    rge_write(outfile, &currentTargetValue, 4);
    rge_write(outfile, &currentTargetTypeValue, 4);
    rge_write(outfile, &currentTargetXValue, 4);
    rge_write(outfile, &currentTargetYValue, 4);
    rge_write(outfile, &currentTargetZValue, 4);
    rge_write(outfile, &desiredTargetDistanceValue, 4);
    rge_write(outfile, &lastActionValue, 4);
    rge_write(outfile, &lastOrderValue, 4);
    rge_write(outfile, &lastTargetValue, 4);
    rge_write(outfile, &lastTargetTypeValue, 4);
    rge_write(outfile, &lastUpdateTimeValue, 4);
    rge_write(outfile, &idleTimerValue, 4);
    rge_write(outfile, &idleTimeoutValue, 4);
    rge_write(outfile, &adjustedIdleTimeoutValue, 4);
    rge_write(outfile, &secondaryTimerValue, 4);
    rge_write(outfile, &lookAroundTimerValue, 4);
    rge_write(outfile, &lookAroundTimeoutValue, 4);
    rge_write(outfile, &defendTargetValue, 4);
    rge_write(outfile, &defenseBufferValue, 4);
    rge_write(outfile, &lastWorldPositionValue, 16);

    rge_write(outfile, &orderQueueSizeValue, 4);
    for (i = 0; i < orderQueueSizeValue; i++) {
        rge_write(outfile, &orderQueueValue[i], sizeof(OrderEvent));
    }

    rge_write(outfile, &notifyQueueSizeValue, 4);
    for (i = 0; i < notifyQueueSizeValue; i++) {
        rge_write(outfile, &notifyQueueValue[i], sizeof(NotifyEvent));
    }

    tempInt = attackingUnitsValue.numberValue;
    rge_write(outfile, &tempInt, 4);
    {
        int i_attack;
        for (i_attack = 0; i_attack < attackingUnitsValue.numberValue; i_attack++) {
            if (attackingUnitsValue.maximumSizeValue - 1 < i_attack) {
                int* newArr = (int*)::operator new(i_attack * 4 + 4);
                if (newArr) {
                    int j;
                    for (j = 0; j < attackingUnitsValue.maximumSizeValue; j++) {
                        if (i_attack + 1 <= j) break;
                        newArr[j] = attackingUnitsValue.value[j];
                    }
                    ::operator delete(attackingUnitsValue.value);
                    attackingUnitsValue.value = newArr;
                    attackingUnitsValue.maximumSizeValue = i_attack + 1;
                }
            }
            tempInt = attackingUnitsValue.value[i_attack];
            rge_write(outfile, &tempInt, 4);
        }
    }

    if (playStatus == 0) {
        tempInt = 0;
        rge_write(outfile, &tempInt, 4);
    } else {
        tempInt = 1;
        rge_write(outfile, &tempInt, 4);
        playStatus->save(outfile);
    }

    rge_write(outfile, &stopAfterTargetKilledValue, 1);
}

void __cdecl rge_read(int fd, void* data, int size);

void UnitAIModule::load(int infile) {
    int numberOrders;
    int i;
    int queue_index;
    int numberUnits;
    int unit_count;
    int attacking_unit_id;
    int tempInt;
    int j;
    union LoadEvent {
        OrderEvent order;
        NotifyEvent notify;
    } tempEvent;
    int hasPlayStatus;

    rge_read(infile, &moodValue, 4);
    rge_read(infile, &currentOrderValue, 4);
    rge_read(infile, &currentOrderPriorityValue, 4);
    rge_read(infile, &currentActionValue, 4);
    rge_read(infile, &currentTargetValue, 4);
    rge_read(infile, &currentTargetTypeValue, 4);
    rge_read(infile, &currentTargetXValue, 4);
    rge_read(infile, &currentTargetYValue, 4);
    rge_read(infile, &currentTargetZValue, 4);
    rge_read(infile, &desiredTargetDistanceValue, 4);
    rge_read(infile, &lastActionValue, 4);
    rge_read(infile, &lastOrderValue, 4);
    rge_read(infile, &lastTargetValue, 4);
    rge_read(infile, &lastTargetTypeValue, 4);
    rge_read(infile, &lastUpdateTimeValue, 4);
    rge_read(infile, &idleTimerValue, 4);
    rge_read(infile, &idleTimeoutValue, 4);
    rge_read(infile, &adjustedIdleTimeoutValue, 4);
    rge_read(infile, &secondaryTimerValue, 4);

    if (save_game_version >= 6.93f) {
        rge_read(infile, &lookAroundTimerValue, 4);
        rge_read(infile, &lookAroundTimeoutValue, 4);
    } else {
        lookAroundTimerValue = 0;
        lookAroundTimeoutValue = 1000;
    }

    rge_read(infile, &defendTargetValue, 4);
    rge_read(infile, &defenseBufferValue, 4);
    rge_read(infile, &lastWorldPositionValue, 16);

    // Read order queue
    rge_read(infile, &numberOrders, 4);
    queue_index = 0;
    if (numberOrders > 0) {
        do {
            rge_read(infile, &tempEvent, 36);
            addToOrderQueue((OrderEvent*)&tempEvent, 0);
            ++queue_index;
        } while (queue_index < numberOrders);
    }

    // Read notify queue
    rge_read(infile, &i, 4);
    queue_index = 0;
    if (i > 0) {
        do {
            rge_read(infile, &tempEvent.notify, sizeof(tempEvent.notify));
            addToNotifyQueue(&tempEvent.notify);
            ++queue_index;
        } while (queue_index < i);
    }

    // Read attacking units
    rge_read(infile, &unit_count, 4);
    numberUnits = 0;
    if (unit_count > 0) {
        do {
            rge_read(infile, &attacking_unit_id, 4);
            tempInt = attacking_unit_id;
            for (j = 0; j < attackingUnitsValue.numberValue; j++) {
                if (j >= attackingUnitsValue.maximumSizeValue) break;
                if (attackingUnitsValue.value[j] == attacking_unit_id)
                    goto attacking_unit_already_present;
            }

            if (attackingUnitsValue.numberValue > attackingUnitsValue.maximumSizeValue - 1) {
                int newSize = attackingUnitsValue.numberValue + 1;
                int* newArr = (int*)::operator new(newSize * 4);
                if (newArr != 0) {
                    j = 0;
                    for (j = 0; j < attackingUnitsValue.maximumSizeValue; j++) {
                        if (j >= newSize) break;
                        newArr[j] = attackingUnitsValue.value[j];
                    }
                    ::operator delete(attackingUnitsValue.value);
                    attackingUnitsValue.value = newArr;
                    attackingUnitsValue.maximumSizeValue = newSize;
                }
            }
            attackingUnitsValue.value[attackingUnitsValue.numberValue] = tempInt;
            attackingUnitsValue.numberValue = attackingUnitsValue.numberValue + 1;

attacking_unit_already_present:
            numberUnits = numberUnits + 1;
        } while (numberUnits < unit_count);
    }

    // Read playStatus
    rge_read(infile, &hasPlayStatus, 4);
    if (hasPlayStatus == 1) {
        playStatus = new AIPlayStatus();
        playStatus->load(infile);
    }

    // stopAfterTargetKilled added in version 7.02
    if (save_game_version >= 7.02f) {
        rge_read(infile, &stopAfterTargetKilledValue, 1);
    }
}


RGE_Player* UnitAIModule::owner() const {
    return this->objectValue->owner;
}


RGE_Static_Object* UnitAIModule::object() const {
    return this->objectValue;
}


int UnitAIModule::objectID() const {
    return this->objectValue->id;
}


int UnitAIModule::objectCategory() const {
    return this->objectCategoryValue;
}


int UnitAIModule::mood() const {
    return this->moodValue;
}


unsigned long UnitAIModule::lastUpdateTime() const {
    return this->lastUpdateTimeValue;
}


unsigned long UnitAIModule::idleTimer() const {
    return this->idleTimerValue;
}


unsigned long UnitAIModule::idleTimeout() const {
    return this->idleTimeoutValue;
}


unsigned long UnitAIModule::secondaryTimer() const {
    return this->secondaryTimerValue;
}


float UnitAIModule::defenseBuffer() const {
    return this->defenseBufferValue;
}


void UnitAIModule::setDefenseBuffer(float v) {
    this->defenseBufferValue = v;
}


int UnitAIModule::orderQueueSize() const {
    return this->orderQueueSizeValue;
}


OrderEvent* UnitAIModule::orderQueueElement(int v) const {
    if (v >= 0 && v < this->orderQueueSizeValue && this->orderQueueValue != 0) {
        return this->orderQueueValue + v;
    }
    return 0;
}


void UnitAIModule::purgeOrderQueue() {
    this->orderQueueSizeValue = 0;
}


int UnitAIModule::currentOrder() const {
    return this->currentOrderValue;
}


void UnitAIModule::setCurrentOrder(int v) {
    this->lastOrderValue = this->currentOrderValue;
    this->currentOrderValue = v;
}


int UnitAIModule::currentOrderPriority() const {
    return this->currentOrderPriorityValue;
}


void UnitAIModule::setCurrentOrderPriority(int v) {
    this->currentOrderPriorityValue = v;
}


int UnitAIModule::currentAction() const {
    return this->currentActionValue;
}


void UnitAIModule::setCurrentAction(int v) {
    this->lastActionValue = this->currentActionValue;
    this->currentActionValue = v;
}


int UnitAIModule::currentTarget() const {
    return this->currentTargetValue;
}


int UnitAIModule::currentTargetType() const {
    return this->currentTargetTypeValue;
}


float UnitAIModule::currentTargetX() const {
    return this->currentTargetXValue;
}


float UnitAIModule::currentTargetY() const {
    return this->currentTargetYValue;
}


float UnitAIModule::currentTargetZ() const {
    return this->currentTargetZValue;
}


int UnitAIModule::lastAction() const {
    return this->lastActionValue;
}


int UnitAIModule::lastOrder() const {
    return this->lastOrderValue;
}


int UnitAIModule::lastTarget() const {
    return this->lastTargetValue;
}


int UnitAIModule::lastTargetType() const {
    return this->lastTargetTypeValue;
}


float UnitAIModule::desiredTargetDistance() const {
    return this->desiredTargetDistanceValue;
}



int UnitAIModule::attackingUnitID(int v) {
    if (v < 0 || v >= this->attackingUnitsValue.numberValue) {
        return -1;
    }
    if (v > this->attackingUnitsValue.maximumSizeValue - 1) {
        int newMax = v + 1;
        int* newValues = (int*)::operator new(newMax * 4);
        if (newValues != 0) {
            int oldMax = this->attackingUnitsValue.maximumSizeValue;
            int i = 0;
            if (oldMax > 0) {
                do {
                    if (i < newMax) {
                        i++;
                        int value = this->attackingUnitsValue.value[i - 1];
                        newValues[i - 1] = value;
                        oldMax = this->attackingUnitsValue.maximumSizeValue;
                    } else {
                        break;
                    }
                } while (i < oldMax);
            }
            ::operator delete(this->attackingUnitsValue.value);
            this->attackingUnitsValue.value = newValues;
            this->attackingUnitsValue.maximumSizeValue = newMax;
        }
    }
    return this->attackingUnitsValue.value[v];
}


int UnitAIModule::numberAttackingUnits() const {
    return this->attackingUnitsValue.numberValue;
}


int UnitAIModule::update(unsigned long uTime) {
    int haveGameAction;

    if (this->objectValue->object_state > 2) {
        return 1;
    }

    taskedThisUpdate = 0;
    searchedThisUpdate = 0;
    numberVisibleObjects = 0;
    numberDifferentPlayerObjectsVisible = 0;

    haveGameAction = ((RGE_Action_Object*)this->objectValue)
                         ->actions->have_action();
    if (haveGameAction == 0 && this->objectValue->waitingToMove() == 1) {
        this->objectValue->setWaitingToMove(0);
    }

    if (this->currentTargetValue != -1) {
        RGE_Static_Object* target =
            this->lookupObject(this->currentTargetValue);

        if (target == 0) {
            this->currentTargetValue = -1;
            if (this->currentActionValue == 0x258) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int objectID = this->objectValue != 0
                                       ? this->objectValue->id
                                       : -1;
                    fprintf(actionFile, str_fmt_stopObject, objectID, str_aiuaimod_path, 0x306);
                }
                this->stopObject(1);
                this->idleTimerValue = this->idleTimeoutValue;
            }
        } else {
            if (this->objectValue->object_state == 2 && target->object_state > 2 &&
                this->actionRequiresLiveTarget(this->currentActionValue) == 1) {
                this->stopAfterTargetKilledValue = 0;
                if (this->currentActionValue == 0x258) {
                    int idleResult = this->processIdle(0);
                    int currentOrder = this->currentOrderValue;
                    if (idleResult == 5) {
                        if (currentOrder != 0x2D5) {
                            if (this->moveTo(this->currentTargetXValue, this->currentTargetYValue,
                                             this->currentTargetZValue, this->objectValue->weaponRange(), 1) == 0) {
                                this->removeCurrentTarget();
                                if (actionFile != 0) {
                                    int objectID = this->objectValue != 0
                                                       ? this->objectValue->id
                                                       : -1;
                                    fprintf(actionFile, str_fmt_stopObject, objectID, str_aiuaimod_path, 0x335);
                                }
                                this->stopObject(1);
                            } else {
                                int currentOrderAfterMove =
                                    this->currentOrderValue;
                                this->currentOrderValue = -1;
                                this->lastOrderValue = currentOrderAfterMove;
                                this->currentOrderPriorityValue = -1;
                            }
                        }
                    } else if (currentOrder != 0x2D5) {
                        this->lastOrderValue = currentOrder;
                        this->currentOrderValue = -1;
                        this->currentOrderPriorityValue = -1;
                    }
                } else {
                    this->removeCurrentTarget();
                    if (actionFile != 0) {
                        int objectID = this->objectValue != 0
                                           ? this->objectValue->id
                                           : -1;
                        fprintf(actionFile, str_fmt_stopObject, objectID, str_aiuaimod_path, 0x356);
                    }
                    this->stopObject(1);
                }
            }

            if (this->objectValue->owner->computerPlayer() == 1 && this->currentOrderPriorityValue != -1 &&
                this->currentOrderPriorityValue < 100) {
                int priority = (int)(g_unit_ai_distance_priority_scale / this->objectValue->distance_to_object(target));
                if (priority > 99) {
                    priority = 99;
                }
                this->currentOrderPriorityValue = priority;
            }
        }
    }

    if (this->attackingUnitsValue.numberValue == 0 && this->objectValue->underAttack() != 0) {
        this->objectValue->setUnderAttack(0);
    } else {
        int i = 0;
        while (i < this->attackingUnitsValue.numberValue) {
            RGE_Static_Object* attacker =
                this->lookupObject(this->attackingUnitsValue[i]);
            if (attacker == 0 || attacker->unitAI() == 0 || attacker->object_state > 2 ||
                attacker->unitAI()->currentTarget() != this->objectValue->id) {
                this->attackingUnitsValue.remove(this->attackingUnitsValue[i]);
                break;
            }
            ++i;
        }
    }

    this->lastWorldPositionValue.x = this->objectValue->world_x;
    this->lastWorldPositionValue.y = this->objectValue->world_y;
    this->lastWorldPositionValue.z = this->objectValue->world_z;
    this->idleTimerValue += uTime;
    this->secondaryTimerValue += uTime;
    this->lookAroundTimerValue += uTime;

    int i = 0;
    while (i < this->notifyQueueSizeValue) {
        int result = this->processNotify(&this->notifyQueueValue[i], uTime);
        if (result == 4) {
            this->purgeNotifyQueue(uTime);
            return 0;
        }
        if (result == 3) {
            break;
        }
        ++i;
    }
    this->purgeNotifyQueue(uTime);

    if (haveGameAction == 0) {
        switch (this->currentActionValue) {
        case 0x258:
        case 0x261:
        case 0x262:
        case 0x265:
        case 0x26B:
        case 0x26C:
            this->currentActionValue = -1;
            break;
        }
    }

    if (this->objectValue->object_state > 2) {
        return 0;
    }

    if (this->objectValue->groupCommanderValue == this->objectValue->id) {
        this->updateGroup(uTime);
    }

    if (this->currentActionValue == -1) {
        int orderIndex = 0;
        while (orderIndex < this->orderQueueSizeValue) {
            if (this->processOrder(&this->orderQueueValue[orderIndex], orderIndex) == 1) {
                break;
            }
            ++orderIndex;
        }
    }

    this->processMisc();

    if (this->idleTimerValue > this->adjustedIdleTimeoutValue) {
        if (this->currentActionValue == -1 && this->currentTargetValue == -1) {
            this->idleTimerValue = 0;
            this->processIdle(1);
        } else {
            this->idleTimerValue = 0;
        }
    } else if (this->currentActionValue != -1 || this->currentTargetValue != -1) {
        this->idleTimerValue = 0;
    }

    if (this->objectValue->owner->computerPlayer() == 1 && this->lookAroundTimerValue > this->lookAroundTimeoutValue) {
        this->lookAround();
    }

    return 1;
}



void UnitAIModule::updateGroup(unsigned long uTime) {
    AIPlay* play;
    RGE_Static_Object* target;
    RGE_Static_Object* member;
    AIPlayPhase* phase;
    AIPlayPhaseTrigger* trigger;
    int i;

    if (this->playStatus == 0) {
        return;
    }

    play = this->objectValue->owner->world->playbook->play(this->playStatus->playNumberValue);
    if (play == 0) {
        return;
    }

    target = this->lookupObject(this->playStatus->targetValue);
    if (target == 0) {
        int newTarget = this->bestUnitToAttack(1, 0, 0);

        i = 0;
        if (this->objectValue->groupMembers.numberValue > 0) {
            do {
                if (newTarget != -1) {
                    break;
                }

                if (this->objectValue->groupMembers[i] != this->objectValue->id) {
                    member = this->lookupObject(this->objectValue->groupMembers[i]);
                    if (member != 0 && member->unitAI() != 0) {
                        newTarget = member->unitAI()->bestUnitToAttack(1, 0, 0);
                    }
                }
                ++i;
            } while (i < this->objectValue->groupMembers.numberValue);
        }

        if (newTarget == -1) {
            operator delete(this->playStatus);
            this->playStatus = 0;
            return;
        }

        this->playStatus->targetValue = newTarget;
        this->selectNewPlayPhase(this->playStatus->currentPhaseValue, 0);
        target = this->lookupObject(newTarget);
    }

    if (this->playStatus->currentPhaseValue == 0xFD) {
        int totalHitPoints[5];
        int groupList[50];
        int groupCount;
        int a;

        for (i = 0; i < 5; ++i) {
            totalHitPoints[i] = 0;
        }

        groupCount = 0;
        a = 0;
        if (this->objectValue->groupMembers.numberValue > 0) {
            do {
                member = this->lookupObject(this->objectValue->groupMembers[a]);
                if (member != 0) {
                    groupList[groupCount] = member->id;
                    ++groupCount;

                    i = 0;
                    if (this->objectValue->numberUserDefinedWaypoints() > 0) {
                        do {
                            member->addUserDefinedWaypoint(this->objectValue->userDefinedWaypoint(i), 1);
                            ++i;
                        } while (i < this->objectValue->numberUserDefinedWaypoints());
                    }
                }
                ++a;
            } while (a < this->objectValue->groupMembers.numberValue);
        }

        this->playStatus->lastPhaseChangeTimeValue =
            this->objectValue->owner->world->world_time;
        play->fillGroups(this->playStatus, groupList, groupCount, this->objectValue->owner->world);

        for (i = 0; i < groupCount; ++i) {
            member = this->lookupObject(groupList[i]);
            totalHitPoints[this->playStatus->group(groupList[i])] +=
                (int)member->hp;
        }

        for (i = 0; i < 5; ++i) {
            this->playStatus->setOriginalHitPoints(i, totalHitPoints[i]);
        }

        this->selectNewPlayPhase(0, 0);
        return;
    }

    phase = play->phase(this->playStatus->currentPhaseValue);
    if (phase == 0) {
        return;
    }

    i = 0;
    do {
        int triggerSatisfied = 0;

        trigger = phase->trigger(i);
        if (trigger != 0 && trigger->type() != 0) {
            switch (trigger->type()) {
            case AIPlayPhaseTrigger::GatherTrigger: {
                int group = 0;
                triggerSatisfied = 1;

                do {
                    int commandIndex;
                    AIPlayPhaseCommand* command;
                    int groupingIndex;

                    if (triggerSatisfied == 0) {
                        break;
                    }

                    commandIndex = play->groupGivenCommandOnPhase(group, AIPlayPhaseCommand::MoveCommand,
                                                                  this->playStatus->currentPhaseValue);
                    if (commandIndex != -1) {
                        command = phase->command(commandIndex);
                        groupingIndex = 0;
                        do {
                            AIPlayStatus::GroupingStruct* grouping;

                            if (triggerSatisfied == 0) {
                                break;
                            }

                            grouping = &this->playStatus->groupings[groupingIndex];
                            if (grouping->groupID == group) {
                                member = this->lookupObject(grouping->id);
                                if (member != 0) {
                                    float gatherDistance =
                                        member->distance_to_position((float)command->value1() + target->world_x,
                                                                     (float)command->value2() + target->world_y,
                                                                     (float)command->value2() + target->world_z);
                                    if (gatherDistance > (float)trigger->value1()) {
                                        triggerSatisfied = 0;
                                    }
                                }
                            }
                            ++groupingIndex;
                        } while (groupingIndex < 50);
                    }
                    ++group;
                } while (group < 5);
                break;
            }

            case AIPlayPhaseTrigger::DeathTrigger: {
                int numberInGroup = 0;
                int deadCount = 0;
                int groupingIndex = 0;

                do {
                    AIPlayStatus::GroupingStruct* grouping =
                        &this->playStatus->groupings[groupingIndex];
                    if (grouping->groupID == trigger->value1()) {
                        ++numberInGroup;
                        member = this->lookupObject(grouping->id);
                        if (member == 0 || member->object_state > 2) {
                            ++deadCount;
                        }
                    }
                    ++groupingIndex;
                } while (groupingIndex < 50);

                if (numberInGroup == 0 || trigger->value2() <= deadCount * 100 / numberInGroup) {
                    triggerSatisfied = 1;
                }
                break;
            }

            case AIPlayPhaseTrigger::HealthLostTrigger: {
                int currentHitPoints = 0;
                int groupingIndex = 0;

                do {
                    AIPlayStatus::GroupingStruct* grouping =
                        &this->playStatus->groupings[groupingIndex];
                    if (grouping->groupID == trigger->value1()) {
                        member = this->lookupObject(grouping->id);
                        if (member != 0) {
                            currentHitPoints += (int)member->hp;
                        }
                    }
                    ++groupingIndex;
                } while (groupingIndex < 50);

                if (trigger->value2() <= (this->playStatus->originalHitPoints(trigger->value1()) - currentHitPoints) * 100 /
                    this->playStatus->originalHitPoints(trigger->value1())) {
                    triggerSatisfied = 1;
                }
                break;
            }

            case AIPlayPhaseTrigger::DeathOfGroupTrigger: {
                int groupingIndex = 0;
                triggerSatisfied = 1;

                do {
                    AIPlayStatus::GroupingStruct* grouping;

                    if (triggerSatisfied == 0) {
                        break;
                    }

                    grouping = &this->playStatus->groupings[groupingIndex];
                    if (grouping->groupID == trigger->value1()) {
                        member = this->lookupObject(grouping->id);
                        if (member != 0 && member->object_state == 2) {
                            triggerSatisfied = 0;
                        }
                    }
                    ++groupingIndex;
                } while (groupingIndex < 50);
                break;
            }

            case AIPlayPhaseTrigger::HealOfGroupTrigger: {
                int groupingIndex = 0;
                triggerSatisfied = 1;

                do {
                    AIPlayStatus::GroupingStruct* grouping;

                    if (triggerSatisfied == 0) {
                        break;
                    }

                    grouping = &this->playStatus->groupings[groupingIndex];
                    if (grouping->groupID == trigger->value1()) {
                        member = this->lookupObject(grouping->id);
                        if (member != 0) {
                            int hitPoints = (int)member->hp;
                            if (hitPoints < member->master_obj->hp) {
                                triggerSatisfied = 0;
                            }
                        }
                    }
                    ++groupingIndex;
                } while (groupingIndex < 50);
                break;
            }

            case AIPlayPhaseTrigger::ImmediateTrigger:
                triggerSatisfied = 1;
                break;

            case AIPlayPhaseTrigger::TimeTrigger:
                if (trigger->value1() < (int)(this->objectValue->owner->world->world_time -
                                              this->playStatus->lastPhaseChangeTimeValue) / 1000) {
                    triggerSatisfied = 1;
                }
                break;

            default:
                break;
            }

            if (triggerSatisfied == 1 && this->selectNewPlayPhase(trigger->nextPhase(), 0) == 1) {
                return;
            }
        }

        ++i;
    } while (i < 3);

    this->selectNewPlayPhase(this->playStatus->currentPhaseValue, 1);
}

// aiuaimod.cpp
//
int UnitAIModule::selectNewPlayPhase(int newPhase, int pickup) {
    RGE_Static_Object* target;
    AIPlay* play;
    AIPlayPhase* phase;
    int i;

    if (this->playStatus == 0)
        return 0;

    play = this->objectValue->owner->world->playbook->play(this->playStatus->playNumberValue);
    if (play == 0)
        return 0;

    if (newPhase == 0xFE) {
        operator delete(this->playStatus);
        this->playStatus = 0;
        return 1;
    }

    phase = play->phase(newPhase);
    if (phase == 0)
        return 0;

    target = this->lookupObject(this->playStatus->targetValue);
    if (target == 0)
        return 0;

    this->playStatus->currentPhaseValue = (unsigned char)newPhase;
    i = 0;
    do {
        AIPlayPhaseCommand* command = phase->command(i);
        if (command != 0 && command->type() != 0) {
            if ((command->type() == AIPlayPhaseCommand::ResetHitPointsCommand ||
                 command->type() == AIPlayPhaseCommand::ResetAliveCountCommand) && pickup == 0) {
                if (command->type() == AIPlayPhaseCommand::ResetHitPointsCommand) {
                    this->playStatus->resetHitPoints(command->group(), this->objectValue->owner->world);
                } else {
                    this->playStatus->removeDeadUnits(command->group(), this->objectValue->owner->world);
                }
            } else {
                int a = 0;
                if (this->objectValue->groupMembers.numberValue > 0) {
                    do {
                        RGE_Static_Object* member = this->lookupObject(this->objectValue->groupMembers[a]);
                        if (member != 0 && member->unitAI() != 0 &&
                            this->playStatus->group(member->id) == command->group() &&
                            (pickup != 1 || member->unitAI()->currentAction() == -1)) {
                            switch (command->type()) {
                            case AIPlayPhaseCommand::MoveCommand: {
                                int distance = (int)member->distance_to_position((float)command->value1() + target->world_x,
                                                                                 (float)command->value2() + target->world_y, (float)command->value3() + target->world_z);
                                if (distance > play->gatherTolerance(command->group(),
                                                                     this->playStatus->currentPhaseValue)) {
                                    member->unitAI()->order(this->objectValue->id, 0x2C6, -1, -1,
                                                            (float)command->value1() + target->world_x,
                                                            (float)command->value2() + target->world_y,
                                                            (float)command->value3() + target->world_z, 1.0f, 1, 0, 100);
                                }
                                break;
                            }

                            case AIPlayPhaseCommand::AttackCommand:
                                member->unitAI()->order(this->objectValue->id, 700, target->id,
                                                        target->owner->id, -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 100);
                                break;

                            case AIPlayPhaseCommand::AttackSavedTargetCommand: {
                                int targetID =
                                    this->playStatus->savedAttackerValue;
                                member->unitAI()->order(this->objectValue->id, 700, targetID, -1,
                                                        -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 100);
                                break;
                            }

                            case AIPlayPhaseCommand::RetreatCommand:
                                member->unitAI()->order(this->objectValue->id, 0x2C6, -1, -1,
                                                        (float)this->playStatus->originalPointValue.xValue,
                                                        (float)this->playStatus->originalPointValue.yValue,
                                                        (float)this->playStatus->originalPointValue.zValue, 1.0f, 1, 0, 100);
                                break;

                            case AIPlayPhaseCommand::HealCommand: {
                                int targetID = -1;
                                int groupingIndex = 0;
                                do {
                                    AIPlayStatus::GroupingStruct* grouping =
                                        &this->playStatus->groupings[groupingIndex];
                                    if (grouping->groupID == command->value1()) {
                                        RGE_Static_Object* healTarget =
                                            this->lookupObject(grouping->id);
                                        if (healTarget != 0) {
                                            RGE_Master_Static_Object* volatile master =
                                                healTarget->master_obj;
                                            if ((int)healTarget->hp + 1 < master->hp) {
                                                targetID = healTarget->id;
                                                break;
                                            }
                                        }
                                    }
                                    ++groupingIndex;
                                } while (groupingIndex < 50);

                                if (targetID != -1) {
                                    member->unitAI()->order(this->objectValue->id, 0x2BF, targetID, -1,
                                                            -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 100);
                                }
                                break;
                            }

                            case AIPlayPhaseCommand::WaitCommand:
                                member->unitAI()->order(this->objectValue->id, 0x2D8, -1, -1,
                                                        (float)command->value1() + target->world_x, (float)command->value2() + target->world_y,
                                                        (float)command->value3() + target->world_z, 1.0f, 1, 0, 100);
                                break;
                            }
                        }

                        ++a;
                    } while (a < this->objectValue->groupMembers.numberValue);
                }
            }
        }

        ++i;
    } while (i < 5);

    return 1;
}
int UnitAIModule::order(int issuer, int orderType, int target, int targetOwner,
                        float targetX, float targetY, float targetZ, float range,
                        int immediate, int inFront, int priority) {
    if (this->objectValue->object_state <= 2) {
        if (immediate == 0) {
            this->addToOrderQueue(issuer, orderType, target, targetOwner, targetX, targetY, targetZ, range, inFront,
                                  priority);
            return 1;
        }

        if (inFront == 1) {
            this->addToOrderQueue(this->objectValue->id, this->currentOrderValue, this->currentTargetValue, -1,
                                  this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue,
                                  this->desiredTargetDistanceValue, 1, this->currentOrderPriorityValue);
        }

        this->addToOrderQueue(issuer, orderType, target, targetOwner, targetX, targetY, targetZ, range, 1, priority);

        if (orderType != 0x2D9) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id;
                if (this->objectValue != 0)
                    id = this->objectValue->id;
                else
                    id = -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x6F3);
            }
            this->stopObject(1);
        }

        this->purgeNotifyQueue(0);
        this->processOrder(this->orderQueueValue, 0);
    }
    return 1;
}

// aiuaimod.cpp
// The public notify owner uses the canonical event and queue surface.


int UnitAIModule::notify(int callerID, int recipientID, int mType, long p1,
                         long p2, long p3) {
    if (objectValue->object_state != 2)
        return 0;

    int msg = mType;
    int target = callerID;

    if (msg == 0x2BB) {
        int n = attackingUnitsValue.numberValue;
        int i = 0;
        if (n <= 0)
            goto fail2;
        int max = attackingUnitsValue.maximumSizeValue;
        while (1) {
            if (i >= max)
                goto fail2;
            if (attackingUnitsValue.value[i] == target)
                goto found;
            ++i;
            if (i < n)
                continue;
            return 0;
        }
    } else {
found:
        if ((msg != 0x1FB) || (p1 == currentActionValue)) {
            if ((msg == 0x1FA) && (p1 == 0x262) && (currentActionValue != 0x262) && (currentActionValue != 0x268))
                return 1;
            return addToNotifyQueue(callerID, recipientID, mType, p1, p2, p3);
        }
    }
fail2:
    return 0;
}


int UnitAIModule::notifyCommander(NotifyEvent* nEvent) {
    return this->notifyCommander(nEvent->caller, nEvent->recipient, nEvent->mType, nEvent->p1, nEvent->p2, nEvent->p3);
}

// aiuaimod.cpp
int UnitAIModule::notifyCommander(int callerID, int recipientID, int mType,
                                  long p1, long p2, long p3) {
    NotifyEvent nEvent;

    if (this->objectValue->inGroup() == 1) {
        nEvent.caller = callerID;
        nEvent.recipient = recipientID;
        nEvent.mType = mType;
        nEvent.p1 = p1;
        nEvent.p2 = p2;
        nEvent.p3 = p3;

        RGE_Static_Object* obj = this->objectValue;
        int commander = obj->groupCommanderValue;
        if (obj->id == commander) {
            this->processGroupNotify(&nEvent);
        } else {
            RGE_Static_Object* commanderObject = this->lookupObject(commander);
            if (commanderObject != 0) {
                if (commanderObject->unitAI() != 0) {
                    commanderObject->unitAI()->processGroupNotify(&nEvent);
                }
            }
        }
    }

    this->objectValue->owner->notify(callerID, recipientID, mType, p1, p2, p3);
    return 1;
}

// aiuaimod.cpp
// Direct typed visible-unit calls preserve the original call order.

void UnitAIModule::search() {
    RGE_Static_Object* obj;
    RGE_Master_Static_Object* master;
    int range;

    if (searchedThisUpdate == 1)
        return;

    searchedThisUpdate = 1;
    if (this->importantObjects == 0)
        return;

    if (this->currentOrderValue == 0x2BD && this->defendTargetValue != -1) {
        obj = this->lookupObject(this->defendTargetValue);
        if (obj != 0) {
            if (obj->unitAI() != 0) {
                numberVisibleObjects = VisibleUnitManager->GetVisibleUnits((int)obj->world_x, (int)obj->world_y,
                                                                           (int)obj->master_obj->los, obj->owner->id, this->importantObjects, this->numberImportantObjects,
                                                                           this->objectValue->owner->unitDiplomacy);
                return;
            }
        }
    }

    obj = this->objectValue;
    master = obj->master_obj;
    range = (int)master->los;
    if (master->id == 0x76)
        range += range;

    numberVisibleObjects = VisibleUnitManager->GetVisibleUnits((int)obj->world_x, (int)obj->world_y, range, obj->owner->id,
                                                               this->importantObjects, this->numberImportantObjects, obj->owner->unitDiplomacy);
}


int UnitAIModule::importantWhenDead(int objectType) {
    if (objectType == 0x7 || objectType == 0x9 || objectType == 0xA || objectType == 0xF || objectType == 0x8 || objectType == 0x20)
        return 1;
    return 0;
}


int UnitAIModule::retryableOrder(int orderType) {
    return 0;
}



int UnitAIModule::actionRequiresLiveTarget(int aID) {
    if (this->stopAfterTargetKilledValue != 1) {
        if (aID != 0x258 && aID != 0x259 && aID != 0x25B && aID != 0x25C && aID != 0x26A && aID != 0x264) {
            return 0;
        }
    }

    return 1;
}

// aiuaimod.cpp
// `UnitAIModule::update` is a separate owner at 00413AB0-0041400B.

int UnitAIModule::bestUnitToAttack(int allowWallAttacks, int quickCheck,
                                   float* threatSlot) {
    float numberMovingTargets;
    int numberDamagingUnits;
    int largestThreatIsBuilding;
    int currentTargetIsBuilding;
    int i;
    int j;
    RGE_Game_World* world;
    int difficulty;
    int maxReactDistance;
    int modifier;
    int numberNonCurrentTargets;
    int currentTargetIsWall;
    int numberObjectsInRange;
    int closestEnemyDistance;
    float enemyDistance;
    int closestEnemyID;
    int baseDamage;

    this->search();
    difficulty = this->objectValue->owner->world->difficultyLevel();

    if (((rge_base_game->scenarioGame() == 1) && (rge_base_game->singlePlayerGame() == 1) &&
         (difficulty >= 3) && (this->objectValue->owner->id != 1)) || ((rge_base_game->singlePlayerGame() == 1) &&
         (difficulty >= 3) && (this->objectValue->owner->type == 3) &&
         ((this->objectValue->owner->strategicNumber(0xDB) != 100) ||
          (this->objectValue->owner->strategicNumber(0xDA) != 100)))) {
        if (this->objectValue->owner->id > 1) {
            if (difficulty == 3) {
                maxReactDistance = this->objectValue->owner->strategicNumber(0xDB);
            } else {
                maxReactDistance = this->objectValue->owner->strategicNumber(0xDA);
            }
        } else {
            maxReactDistance = difficulty == 3 ? 75 : 50;
        }
        modifier = (int)((float)maxReactDistance * this->objectValue->master_obj->los * g_unit_ai_reaction_distance_scale);
        if (modifier < 1) {
            modifier = 1;
        }
    } else {
        modifier = ((int)this->objectValue->master_obj->los) * 2;
    }

    numberNonCurrentTargets = -1;
    numberMovingTargets = 0;
    currentTargetIsBuilding = 0;
    world = this->objectValue->owner->world;
    numberObjectsInRange = 0;

    if (this->currentTargetValue != -1) {
        RGE_Static_Object* target =
            this->lookupObject(this->currentTargetValue);
        if (target != 0 && target->master_obj->object_group == 0x1B) {
            numberObjectsInRange = 1;
        }
    }

    numberDamagingUnits = 0;
    largestThreatIsBuilding = 0;
    currentTargetIsWall = 0;
    enemyDistance = 100000.0f;
    closestEnemyDistance = 0;
    closestEnemyID = -1;

    for (i = 4; i >= 2; --i) {
        j = 0;
        if (VisibleUnitList_Size[i] > 0) {
            do {
                RGE_Static_Object* target =
                    world->object(VisibleUnitList[i][j].object_id);
                if (target != 0 && target->object_state <= 2 && this->objectValue->owner->isAlly(target->owner->id) != 1 &&
                    target->inside_obj == 0 && ((allowWallAttacks != 0 && numberObjectsInRange != 0) ||
                     target->master_obj->object_group != 0x1B) && ((target->master_obj->object_group != 3 ||
                      target->hp > g_unit_ai_map_boundary_adjustment || (this->objectValue->master_obj->id != 0x23 &&
                       this->objectValue->master_obj->id != 0x24))) && this->canAttackUnit(target) != 0 && (i != 3 ||
                     this->canAttackUnitAtNeutrality(target->master_obj->object_group) != 0)) {
                    float distance =
                        this->objectValue->distance_to_object(target);
                    if (this->objectValue->minimumWeaponRange() <= distance && modifier >= VisibleUnitList[i][j].distance) {
                        if (target->id != this->currentTargetValue) {
                            ++currentTargetIsWall;
                        }
                        if (target->master_obj->object_group != 3) {
                            ++numberDamagingUnits;
                        }
                        if (target->damageCapability() > g_unit_ai_zero_float) {
                            ++largestThreatIsBuilding;
                        }
                        if (target->master_obj->object_group != 3) {
                            if (distance < this->objectValue->weaponRange() - g_unit_ai_weapon_range_adjustment) {
                                ++closestEnemyDistance;
                            }
                            if (distance < enemyDistance) {
                                enemyDistance = distance;
                                closestEnemyID = target->id;
                            }
                        }
                    }
                }
                ++j;
            } while (j < VisibleUnitList_Size[i]);
        }
    }

    if (this->currentTargetValue != -1 && quickCheck == 0 && this->currentActionValue == 600) {
        RGE_Static_Object* target =
            this->lookupObject(this->currentTargetValue);
        if (target != 0) {
            int x = (int)target->world_x;
            int y = (int)target->world_y;
            unsigned char visible = this->visibleStatus(this->objectValue->owner->visible, x, y);
            if (currentTargetIsWall != 0) {
                if (visible != 0x0F) {
                    goto skipCurrentTarget;
                }
                if (this->objectValue->inAttackRange(target) != 1 && this->objectValue->canPath(this->currentTargetValue,
                                                                                                this->objectValue->weaponRange(), 0, 0, -1, -1) != 1) {
                    goto skipCurrentTarget;
                }
            }
            target = world->object(this->currentTargetValue);
            if (target != 0 && target->object_state == 2 && this->objectValue->owner->isAlly(target->owner->id) == 0) {
                if (target->master_obj->id == 0x114) {
                    return target->id;
                }
                numberNonCurrentTargets = this->currentTargetValue;
                numberMovingTargets = target->damageCapability() * g_unit_ai_damage_capability_scale;
                baseDamage =
                    target->master_obj->calc_base_damage_ability((RGE_Master_Combat_Object*)this->objectValue->master_obj);
                numberMovingTargets =
                    (float)baseDamage * g_unit_ai_distance_priority_scale + numberMovingTargets;
                float hitPoints = target->hp;
                if (hitPoints > g_unit_ai_zero_float) {
                    numberMovingTargets /= hitPoints;
                }
                float distance = target->distance_to_object(this->objectValue);
                if (numberDamagingUnits < 2) {
                    if (distance != g_unit_ai_zero_float) {
                        numberMovingTargets /= distance;
                    }
                } else if (distance != g_unit_ai_zero_float) {
                    numberMovingTargets /=
                        (float)numberDamagingUnits * distance * g_unit_ai_multi_attacker_distance_scale;
                }
                if (target->master_obj->object_group != 3) {
                    ++numberDamagingUnits;
                    currentTargetIsBuilding = 0;
                } else {
                    currentTargetIsBuilding = 1;
                }
                if (target->damageCapability() > g_unit_ai_zero_float) {
                    ++largestThreatIsBuilding;
                }
            }
        }
    }

skipCurrentTarget:
    if (numberDamagingUnits > 1) {
        RGE_Static_Object* target = world->object(closestEnemyID);
        if (target != 0) {
            if (this->objectValue->inAttackRange(target) == 1) {
                return closestEnemyID;
            }
            if (this->objectValue->canPath(closestEnemyID, this->objectValue->weaponRange(), 0, 0, -1, -1) == 1) {
                return closestEnemyID;
            }
        }
    }

    for (i = 4; i >= 2; --i) {
        j = 0;
        if (VisibleUnitList_Size[i] > 0) {
            do {
                RGE_Static_Object* target =
                    world->object(VisibleUnitList[i][j].object_id);
                if (target != 0 && target->object_state <= 2 && this->objectValue->owner->isAlly(target->owner->id) != 1 &&
                    target->inside_obj == 0 && ((allowWallAttacks != 0 && numberObjectsInRange != 0) ||
                     target->master_obj->object_group != 0x1B) && ((target->master_obj->object_group != 3 ||
                      target->hp > g_unit_ai_map_boundary_adjustment || (this->objectValue->master_obj->id != 0x23 &&
                       this->objectValue->master_obj->id != 0x24))) && this->canAttackUnit(target) != 0 && (i != 3 ||
                     this->canAttackUnitAtNeutrality(target->master_obj->object_group) != 0)) {
                    float distance = this->objectValue->distance_to_object(target);
                    if (this->objectValue->minimumWeaponRange() <= distance && modifier >= VisibleUnitList[i][j].distance &&
                        (quickCheck != 1 || this->objectValue->inAttackRange(target) != 0)) {
                        if (quickCheck == 0 && this->objectValue->inAttackRange(target) == 0 &&
                            this->objectValue->canPath(VisibleUnitList[i][j].object_id,
                                                       this->objectValue->weaponRange(), 0, 0, -1, -1) == 0) {
                            goto skipTarget;
                        }
                        float threat = target->damageCapability() * g_unit_ai_damage_capability_scale;
                        if (largestThreatIsBuilding <= 0 || threat != g_unit_ai_zero_float) {
                            float score =
                                (float)target->master_obj->calc_base_damage_ability(
                                    (RGE_Master_Combat_Object*)this->objectValue->master_obj) * g_unit_ai_distance_priority_scale +
                                threat;
                            float hitPoints = target->hp;
                            if (hitPoints > g_unit_ai_zero_float) {
                                score /= hitPoints;
                            }
                            if (VisibleUnitList[i][j].distance != 0) {
                                score /= (float)VisibleUnitList[i][j].distance;
                            }
                            if (numberDamagingUnits > 1) {
                                int distanceValue =
                                    VisibleUnitList[i][j].distance;
                                score /= (float)(distanceValue * distanceValue * distanceValue);
                            }
                            int group = target->master_obj->object_group;
                            if (numberNonCurrentTargets == -1 || (currentTargetIsBuilding != 0 || group != 3)) {
                                if (numberNonCurrentTargets == -1 || ((currentTargetIsBuilding == 1 && group != 3) ||
                                     (float)score > (float)numberMovingTargets)) {
                                    numberNonCurrentTargets =
                                        VisibleUnitList[i][j].object_id;
                                    currentTargetIsBuilding = (group == 3);
                                    numberMovingTargets = score;
                                }
                            }
                        }
                    }
                }

skipTarget:
                ++j;
            } while (j < VisibleUnitList_Size[i]);
        }
    }

    return numberNonCurrentTargets;
}

// aiuaimod.cpp


int UnitAIModule::mostDangerousEnemy(float* threatSlot) {
    search();

    int best = -1;
    float largestThreat = 0.0f;
    int i = 0;
    if (VisibleUnitList_Size[4] > 0) {
        do {
            RGE_Static_Object* obj = lookupObject(VisibleUnitList[4][i].object_id);
            if (obj) {
                float f = objectValue->calculateDamage(((RGE_Master_Combat_Object*)obj->master_obj)->weapon_num,
                                                       ((RGE_Master_Combat_Object*)obj->master_obj)->weapon,
                                                       objectValue->calc_attack_modifier(obj), obj->owner, obj);
                if (best == -1 || f > largestThreat) {
                    largestThreat = f;
                    best = VisibleUnitList[4][i].object_id;
                }
            }
            i++;
        } while (i < VisibleUnitList_Size[4]);
    }

    if (threatSlot) {
        *threatSlot = largestThreat;
    }
    return best;
}



int UnitAIModule::weakestEnemy(float* threatSlot) {
    this->search();
    int bestId = -1;
    float smallestHP = 0.0f;
    int i = 0;
    if (VisibleUnitList_Size[4] > 0) {
        do {
            int id = VisibleUnitList[4][i].object_id;
            RGE_Static_Object* obj = this->lookupObject(id);
            if (obj != 0) {
                if (bestId == -1 || obj->hp < smallestHP) {
                    smallestHP = obj->hp;
                    bestId = VisibleUnitList[4][i].object_id;
                }
            }
            i++;
        } while (i < VisibleUnitList_Size[4]);
    }
    if (threatSlot != 0) {
        *threatSlot = smallestHP;
    }
    return bestId;
}

// The source uses the canonical managed array and object fields.


int UnitAIModule::closestAttacker(float* threatSlot) {
    int largestThreatID;
    float largestThreat;
    int i;
    float attackThreat;

    largestThreatID = -1;
    largestThreat = 0.0f;
    i = 0;

    if (this->attackingUnitsValue.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->objectValue->owner->world->object(this->attackingUnitsValue[i]);
            if (object != 0) {
                attackThreat = this->objectValue->distance_to_object(object);
                if (largestThreatID == -1 || attackThreat < largestThreat) {
                    largestThreatID = this->attackingUnitsValue[i];
                    largestThreat = attackThreat;
                }
            }
            ++i;
        } while (i < this->attackingUnitsValue.numberValue);
    }

    if (threatSlot != 0)
        *threatSlot = largestThreat;
    return largestThreatID;
}

// The source scans the canonical visible-unit result arrays.


int UnitAIModule::closestObject(int objectGroup, int desiredRelation,
                                int objectState, int objectType,
                                int* threatSlot) {
    int objectsOfPlayer[9];
    this->search();

    int i;
    for (i = 0; i < 9; ++i)
        objectsOfPlayer[i] = 0;

    int closestObjectID = -1;
    float closestDistance = -1.0f;

    int category;
    for (category = 0; category <= 4; ++category) {
        i = 0;
        if (VisibleUnitList_Size[category] > 0) {
            do {
                objectsOfPlayer[VisibleUnitList[category][i].player] = 1;
                if (this->objectValue->id != VisibleUnitList[category][i].object_id) {
                    RGE_Static_Object* object =
                        this->objectValue->owner->world->object(VisibleUnitList[category][i].object_id);
                    if (object != 0 && object->object_state < 7) {
                        if ((desiredRelation != 0 || category == 2 || category == 1) &&
                            (desiredRelation != 2 || category == 4) && (desiredRelation != 3 || category == 1) &&
                            (desiredRelation != 1 || category == 3) && (objectGroup == -1 ||
                             object->master_obj->object_group == objectGroup) &&
                            (objectType == -1 || object->master_obj->id == objectType) &&
                            (objectState == -1 || object->object_state == objectState)) {
                            if (closestObjectID == -1 || (float)VisibleUnitList[category][i].distance < closestDistance) {
                                closestObjectID = VisibleUnitList[category][i].object_id;
                                closestDistance = (float)VisibleUnitList[category][i].distance;
                            }
                        }
                    }
                }
                ++i;
            } while (i < VisibleUnitList_Size[category]);
        }
    }

    numberDifferentPlayerObjectsVisible = 0;
    for (i = 1; i < 9; ++i) {
        if (objectsOfPlayer[i] == 1)
            ++numberDifferentPlayerObjectsVisible;
    }

    if (threatSlot != 0)
        *threatSlot = (int)closestDistance;
    return closestObjectID;
}

int UnitAIModule::closestResourceObject(int resourceType, int* dSlot) {
    int excludeList[100];
    int* nextExclude = excludeList;
    for (int i = 0; i < 100; ++i) {
        excludeList[i] = 0x80000000;
    }

    int excludeCount = 0;
    VISIBLE_RESOURCE_REC* resource;
    while (excludeCount < 100) {
        resource = this->objectValue->owner->VR_List->Get_Closest_Resource((int)this->objectValue->world_x,
                                                                           (int)this->objectValue->world_y, this->objectValue->currentZone(), resourceType, excludeList, excludeCount);
        if (resource == 0) {
            return -1;
        }

        if ((float)resource->distance > this->objectValue->master_obj->los - g_unit_ai_resource_los_adjustment) {
            return -1;
        }

        if (this->objectValue->canPath(resource->object_id, 1.0f, 0, 0, -1, -1) == 1) {
            break;
        }

        ++excludeCount;
        *nextExclude++ = resource->object_id;
    }

    if (dSlot != 0) {
        *dSlot = resource->distance;
    }
    return resource->object_id;
}


int UnitAIModule::closestUndiscoveredTile(int* tX, int* tY,
                                          int checkWaypointQueue) {
    RGE_Static_Object* object;
    RGE_Visible_Map* vMap;
    RGE_Map* map;
    unsigned char currentZone;
    int bestDistance;
    int currX;
    int currY;
    int searchRadius;
    int lowX;
    int highX;
    int highY;
    int lowY;
    int x;
    int y;
    int distance;

    if (this->currentOrderValue == 0x2C1) {
        if (this->currentTargetXValue != -1.0f) {
            if (this->currentTargetYValue != -1.0f) {
                return 0;
            }
        }
    }

    object = this->objectValue;
    bestDistance = -1;
    currX = (int)object->world_x;
    currY = (int)object->world_y;
    searchRadius = (int)object->master_obj->los + 3;
    lowX = (int)(object->world_x - (float)searchRadius);
    highX = (int)(object->world_x + (float)searchRadius);
    lowY = (int)(object->world_y - (float)searchRadius);
    highY = (int)(object->world_y + (float)searchRadius);
    map = object->owner->world->map;
    vMap = object->owner->visible;

    if (lowX < 0) {
        lowX = 0;
    }
    if (highX > map->map_width - 1) {
        highX = map->map_width - 1;
    }
    if (lowY < 0) {
        lowY = 0;
    }
    if (highY > map->map_height - 1) {
        highY = map->map_height - 1;
    }

    // Original 0041601F points to the .cpp path at 0057F980.
    const int randSelect = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 2862) % 3;
    currentZone = this->objectValue->currentZone();

    for (y = lowY; y <= highY; ++y) {
        for (x = lowX; x <= highX; ++x) {
            if (this->visibleStatus(vMap, x, y) == 0) {
                if (currentZone == this->objectValue->lookupZone(x, y)) {
                    if (this->objectValue->passableTile((float)x, (float)y, 0) != 0) {
                        if ((checkWaypointQueue == 0) || (this->inWaypointQueue(x, y) == 0)) {
                            distance = (x - currX) * (x - currX) + (y - currY) * (y - currY);
                            if (this->currentTargetXValue != -1.0f) {
                                distance =
                                    (x - (int)this->currentTargetXValue) * (x - (int)this->currentTargetXValue) +
                                    distance +
                                    (y - (int)this->currentTargetYValue) * (y - (int)this->currentTargetYValue);
                            }
                            if ((bestDistance == -1) || (bestDistance + randSelect > distance)) {
                                bestDistance = distance;
                                *tX = x;
                                *tY = y;
                            }
                        }
                    }
                }
            }
        }
    }
    if (bestDistance != -1) {
        XYZPoint point;

        object = this->objectValue;
        point.x = *tX;
        point.y = *tY;
        point.z = (int)object->world_z;
        return object->canPath(point, object->master_obj->los - 1.0f, -1, (float*)&tX, 0, -1, -1);
    }

    return 0;
}


Waypoint* UnitAIModule::waypoint(int i) const {
    return 0;
}


int UnitAIModule::waypointQueueSize() const {
    return this->waypointQueueSizeValue;
}


int UnitAIModule::addToWaypointQueue(int x, int y) {
    if (this->waypointQueueSizeValue >= 8) {
        this->waypointQueueSizeValue = 0;
    }
    this->waypointQueue[this->waypointQueueSizeValue].x = (float)x;
    this->waypointQueue[this->waypointQueueSizeValue].y = (float)y;
    this->waypointQueueSizeValue = this->waypointQueueSizeValue + 1;
    return 1;
}



int UnitAIModule::inWaypointQueue(int x, int y) const {
    int i = 0;
    if (waypointQueueSizeValue > 0) {
        float fx = (float)x;
        while (1) {
            if (waypointQueue[i].x == fx) {
                if ((float)y == waypointQueue[i].y) goto found;
            }
            i++;
            if (i < waypointQueueSizeValue) continue;
            return 0;
        }
found:
        return 1;
    }
    return 0;
}


void UnitAIModule::clearWaypointQueue() {
    this->waypointQueueSizeValue = 0;
}


int UnitAIModule::canAttackUnit(RGE_Static_Object* target) {
    return 1;
}


int UnitAIModule::canAttackUnitAtNeutrality(int uID) {
    return 1;
}

// aiuaimod.cpp
int UnitAIModule::stopObject(int checkOrderAndAction) {
    if (actionFile != 0) {
        fprintf(actionFile, "t%ld, U#%d sO, cOAA=%d.\n", objectValue->owner->world->world_time, objectValue->id,
                checkOrderAndAction);
    }

    lastActionValue = currentActionValue;
    if (checkOrderAndAction == 0 || currentActionValue + 100 == currentOrderValue) {
        lastOrderValue = currentOrderValue;
        currentOrderValue = -1;
        currentOrderPriorityValue = -1;
    }

    objectValue->stopAction();
    currentActionValue = -1;
    return 1;
}


int UnitAIModule::attackObject(int targetID, int unconditional) {
    if (unconditional != 0 || this->currentActionValue == -1) {
        RGE_Static_Object* target =
            this->objectValue->owner->world->object(targetID);
        if (target != 0) {
            if (this->canAttackUnit(target)) {
                if (this->objectValue->attack(targetID, unconditional) == 1) {
                    this->setCurrentAction(0x258);
                    this->setCurrentTarget(targetID, target->world_x, target->world_y, target->world_z);
                    return 1;
                }
            }
        }
    }
    return 0;
}

// aiuaimod.cpp

int UnitAIModule::attackRoundupObject(int targetID) {
    if (this->currentTargetValue != targetID) {
        RGE_Static_Object* target =
            this->objectValue->owner->world->object(targetID);
        if (target != 0) {
            if (this->canAttackUnit(target)) {
                if (this->currentActionValue != -1) {
                    if (!this->objectValue->canPath(targetID, this->objectValue->weaponRange(), 0, 0, -1, -1)) {
                        return 0;
                    }
                }
                if (this->objectValue->attack(targetID, 1) == 1) {
                    this->setCurrentAction(0x258);
                    this->setCurrentTarget(targetID, target->world_x, target->world_y, target->world_z);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int UnitAIModule::huntObject(int targetID, int unconditional) {
    if (unconditional != 0 || this->currentActionValue != 0x265) {
        if (actionFile != 0) {
            long object_id;
            if (this->objectValue != 0) {
                object_id = this->objectValue->id;
            } else {
                object_id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", object_id, "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xC48);
        }

        this->stopObject(1);
        if (this->objectValue->hunt(targetID, unconditional) == 1) {
            RGE_Static_Object* target =
                this->objectValue->owner->world->object(targetID);
            this->setCurrentAction(0x265);

            if (target == 0) {
                this->setCurrentTarget(targetID, -1, 0, 0, 0);
            } else {
                this->setCurrentTarget(targetID, (int)target->master_obj->object_group, target->world_x, target->world_y,
                                       target->world_z);
            }
            return 1;
        }
    }
    return 0;
}

int UnitAIModule::convertObject(int targetID, int unconditional) {
    if (unconditional != 0 || currentActionValue != 0x25C) {
        int result = objectValue->convert(targetID, unconditional);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetID);

            setCurrentAction(0x25C);

            if (target == 0) {
                setCurrentTarget(targetID, -1, 0, 0, 0);
            } else {
                short group = target->master_obj->object_group;
                setCurrentTarget(targetID, group, target->world_x, target->world_y, target->world_z);
            }
            return 1;
        }
    }
    return 0;
}

// UnitAIModule::healObject — action wrapper


int UnitAIModule::healObject(int targetID, int unconditional) {
    if (unconditional || this->currentActionValue != 0x25B) {
        RGE_Static_Object* unit = this->objectValue;
        if (unit->heal(targetID, unconditional) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetID);
            this->setCurrentAction(0x25B);
            if (target == 0) {
                this->setCurrentTarget(targetID, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetID, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// Fully typed approach


int UnitAIModule::gatherObject(int targetID, int unconditional) {
    if (unconditional != 0 || currentActionValue != 0x261) {
        int result = objectValue->gather(targetID, unconditional);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetID);

            setCurrentAction(0x261);

            if (target == 0) {
                setCurrentTarget(targetID, -1, 0, 0, 0);
            } else {
                short group = target->master_obj->object_group;
                setCurrentTarget(targetID, group, target->world_x, target->world_y, target->world_z);
            }
            return 1;
        }
    }
    return 0;
}

// UnitAIModule::healObject — action wrapper


int UnitAIModule::repairObject(int targetID, int unconditional) {
    if (unconditional || this->currentActionValue != 0x26A) {
        RGE_Static_Object* unit = this->objectValue;
        if (unit->repair(targetID, unconditional) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetID);
            this->setCurrentAction(0x26A);
            if (target == 0) {
                this->setCurrentTarget(targetID, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetID, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

int UnitAIModule::buildObject(int targetID, int unconditional) {
    if (unconditional != 0 || currentActionValue != 0x25A) {
        int result = objectValue->build(targetID, unconditional);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetID);

            setCurrentAction(0x25A);

            if (target == 0) {
                setCurrentTarget(targetID, -1, 0, 0, 0);
            } else {
                short group = target->master_obj->object_group;
                setCurrentTarget(targetID, group, target->world_x, target->world_y, target->world_z);
            }
            return 1;
        }
    }
    return 0;
}

int UnitAIModule::tradeWithObject(int targetID, int unconditional) {
    if (unconditional != 0 || this->currentActionValue != 0x267) {
        int r = this->objectValue->trade(targetID, unconditional);
        if (r == 1) {
            RGE_Static_Object* target =
                this->objectValue->owner->world->object(targetID);

            this->setCurrentAction(0x267);

            if (!target) {
                this->setCurrentTarget(targetID, -1, 0, 0, 0);
            } else {
                int grp = target->master_obj->object_group;
                this->setCurrentTarget(targetID, grp, target->world_x, target->world_y, target->world_z);
            }

            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}



int UnitAIModule::explore(int tX, int tY, int unconditional) {
    if (unconditional != 0 || this->currentActionValue == -1) {
        if (this->objectValue->explore(tX, tY, unconditional) == 1) {
            this->setCurrentAction(0x25D);
            this->setCurrentTarget(-1, (float)tX, (float)tY, 1.0f);
            return 1;
        }
    }
    return 0;
}


int UnitAIModule::enterObject(int targetID, int unconditional) {
    if ((unconditional != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->enter(targetID, unconditional) == 1) {
            this->setCurrentAction(0x269);
            this->setCurrentTarget(targetID, -1.0f, -1.0f, -1.0f);
            return 1;
        }
    }
    return 0;
}


int UnitAIModule::transportObject(float tX, float tY, float tZ, int unconditional) {
    if ((unconditional != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->transport(tX, tY, tZ, unconditional) == 1) {
            this->setCurrentAction(0x266);
            this->setCurrentTarget(-1, tX, tY, tZ);
            return 1;
        }
    }
    return 0;
}

// aiuaimod.cpp lines 3364-3381


int UnitAIModule::unload(int unconditional, float x, float y) {
    if (unconditional || this->currentActionValue == -1) {
        RGE_Static_Object* obj = this->objectValue;
        if (obj->unload(unconditional, x, y, obj->world_z) == 1) {
            RGE_Static_Object* target = this->objectValue;
            this->setCurrentAction(0x26D);
            if (target == 0) {
                this->setCurrentTarget(this->objectValue->id, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(this->objectValue->id, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// aiuaimod.cpp lines 3386-3404
int UnitAIModule::moveTo(int targetID, int unconditional) {
    if (unconditional || this->currentActionValue == -1) {
        if (this->objectValue->moveTo(targetID, unconditional) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetID);
            this->setCurrentAction(0x262);
            if (target == 0) {
                this->setCurrentTarget(targetID, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetID, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// aiuaimod.cpp lines 3410-3428
int UnitAIModule::moveTo(int targetID, float minimumRange, int unconditional) {
    if (unconditional || this->currentActionValue == -1) {
        if (this->objectValue->moveTo(targetID, minimumRange, unconditional) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetID);
            this->setCurrentAction(0x262);
            if (target == 0) {
                this->setCurrentTarget(targetID, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetID, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}


int UnitAIModule::moveTo(float targetX, float targetY, float targetZ,
                         float range, int unconditional) {
    int result;

    if (unconditional != 0 || this->currentActionValue == -1) {
        result = this->objectValue->moveTo(targetX, targetY, targetZ, range, unconditional);
        if (result == 1) {
            this->setCurrentAction(0x262);
            this->setCurrentTarget(-1, targetX, targetY, targetZ);
            return 1;
        }
    }
    return 0;
}

// aiuaimod.cpp lines 3453-3514.
int UnitAIModule::evasiveMoveTo(float targetX, float targetY, float targetZ,
                                int unconditional) {
    if (unconditional != 0 || this->currentActionValue == -1) {
        if (targetX < g_unit_ai_zero_float) {
            targetX = 0.0f;
        } else {
            if (targetX >= (float)this->objectValue->owner->world->map->map_width) {
                targetX = (float)this->objectValue->owner->world->map->map_width - g_unit_ai_map_boundary_adjustment;
            }
        }

        if (targetY < g_unit_ai_zero_float) {
            targetY = 0.0f;
        } else {
            if (targetY >= (float)this->objectValue->owner->world->map->map_height) {
                targetY = (float)this->objectValue->owner->world->map->map_height - g_unit_ai_map_boundary_adjustment;
            }
        }

        int i = 0;
        while (i < 5) {
            if (this->objectValue->passableTile(targetX, targetY, 0) == 1) {
                break;
            }

            if (debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 3487) % 2) {
                targetX += (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 3488) % 4);
            } else {
                targetX -= (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 3490) % 4);
            }

            if (debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 3491) % 2) {
                targetY += (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 3492) % 4);
            } else {
                targetY -= (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 3494) % 4);
            }

            if (targetX < g_unit_ai_zero_float) {
                targetX = 0.0f;
            } else {
                if (targetX >= (float)this->objectValue->owner->world->map->map_width) {
                    targetX = (float)this->objectValue->owner->world->map->map_width - g_unit_ai_map_boundary_adjustment;
                }
            }

            if (targetY < g_unit_ai_zero_float) {
                targetY = 0.0f;
            } else {
                if (targetY >= (float)this->objectValue->owner->world->map->map_height) {
                    targetY = (float)this->objectValue->owner->world->map->map_height - g_unit_ai_map_boundary_adjustment;
                }
            }
            ++i;
        }

        if (this->objectValue->moveTo(targetX, targetY, targetZ, 0.0f, unconditional) == 1) {
            this->setCurrentAction(0x262);
            this->setCurrentTarget(-1, targetX, targetY, targetZ);
            return 1;
        }
    }
    return 0;
}

int UnitAIModule::intelligentEvasiveMoveTo(
    float targetX, float targetY, float targetZ, int goCloser, int unconditional) {
    if (unconditional == 0 && this->currentActionValue != -1) {
        return 0;
    }

    if (targetX < g_unit_ai_zero_float) {
        targetX = 0.0f;
    } else if (targetX >= (float)this->objectValue->owner->world->map->map_width) {
        targetX = (float)this->objectValue->owner->world->map->map_width - g_unit_ai_map_boundary_adjustment;
    }

    if (targetY < g_unit_ai_zero_float) {
        targetY = 0.0f;
    } else if (targetY >= (float)this->objectValue->owner->world->map->map_height) {
        targetY = (float)this->objectValue->owner->world->map->map_height - g_unit_ai_map_boundary_adjustment;
    }

    XYZPoint point;
    point.x = (int)targetX;
    point.y = (int)targetY;
    point.z = (int)this->objectValue->world_z;

    if (this->objectValue->canPath(point, 1.0f, -1, 0, 0, -1, -1) == 0) {
        float baseDistance = this->objectValue->distance_to_position(targetX, targetY, this->objectValue->world_z);
        int facet = -1;

        while (1) {
            ++facet;
            if (facet > 7) {
                return 0;
            }

            switch (facet) {
            case 0:
                point.x -= 2;
                // Fall through.
            case 7:
                point.y -= 2;
                break;
            case 1:
            case 2:
                point.x += 2;
                break;
            case 3:
            case 4:
                point.y += 2;
                break;
            case 5:
            case 6:
                point.x -= 2;
                break;
            }

            if (point.x < 0) {
                point.x = 0;
            } else if (point.x >= this->objectValue->owner->world->map->map_width) {
                point.x = this->objectValue->owner->world->map->map_width - 1;
            }

            if (point.y < 0) {
                point.y = 0;
            } else if (point.y >= this->objectValue->owner->world->map->map_height) {
                point.y = this->objectValue->owner->world->map->map_height - 1;
            }

            if (goCloser == 0 &&
                this->objectValue->distance_to_position((float)point.x - g_unit_ai_half_coordinate_adjustment, (float)point.y - g_unit_ai_half_coordinate_adjustment,
                                                        this->objectValue->world_z) < baseDistance) {
                ++facet;
                continue;
            }

            if (this->objectValue->canPath(point, 1.0f, -1, 0, 0, -1, -1) == 1) {
                break;
            }
        }
    }

    if (this->objectValue->moveTo((float)point.x - g_unit_ai_half_coordinate_adjustment, (float)point.y - g_unit_ai_half_coordinate_adjustment,
                                  targetZ, 0.5f, unconditional) == 1) {
        this->setCurrentAction(0x262);
        this->setCurrentTarget(-1, targetX, targetY, targetZ);
        return 1;
    }
    return 0;
}

#pragma intrinsic(sqrt)

int UnitAIModule::runAwayFromAttackers(int unconditional) {
    if (unconditional == 0 && this->currentActionValue != -1)
        return 0;

    int i;
    float xDiff;
    float yDiff;

    xDiff = 0.0f;
    yDiff = 0.0f;
    i = 0;

    if (this->attackingUnitsValue.numberValue > 0) {
        do {
            RGE_Static_Object* attacker =
                this->objectValue->owner->world->object(this->attackingUnitsValue[i]);
            if (attacker != 0) {
                xDiff += attacker->world_x - this->objectValue->world_x;
                yDiff += attacker->world_y - this->objectValue->world_y;
            }
            ++i;
        } while (i < this->attackingUnitsValue.numberValue);
    }

    float evasiveMoveDistance = this->objectValue->maximumSpeed() * 4.0f;
    float distanceDiff = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

    return this->evasiveMoveTo((float)(-((xDiff / distanceDiff) * evasiveMoveDistance)) + this->objectValue->world_x,
                               (float)(-((yDiff / distanceDiff) * evasiveMoveDistance)) + this->objectValue->world_y, this->objectValue->world_z,
                               1);
}

// UnitAIModule::followObject(int targetID, float desiredDistance, int unconditional)
// Size: 108 bytes


int UnitAIModule::followObject(int targetID, float desiredDistance,
                               int unconditional) {
    if (unconditional == 0 && this->currentActionValue != -1) {
        return 0;
    }

    RGE_Static_Object* target = this->objectValue->owner->world->object(targetID);
    if (target == 0) {
        return 0;
    }

    this->setCurrentAction(0x264);
    this->setCurrentTarget(targetID, target->world_x, target->world_y, target->world_z);
    this->desiredTargetDistanceValue = desiredDistance;
    return 1;
}

// target: VA 004173D0 UnitAIModule::defendObject(int,float,int)
// sibling of followObject; keep the early currentAction gate, world lookup, action/target calls, and final field stores


int UnitAIModule::defendObject(int targetID, float desiredDistance,
                               int unconditional) {
    RGE_Static_Object* target;

    if (unconditional == 0 && this->currentActionValue != -1) {
        return 0;
    }

    target = this->objectValue->owner->world->object(targetID);
    if (target == 0) {
        return 0;
    }

    this->setCurrentAction(0x259);
    this->setCurrentTarget(targetID, target->world_x, target->world_y, target->world_z);
    this->defendTargetValue = targetID;
    this->desiredTargetDistanceValue = desiredDistance;
    return 1;
}

// defendPosition: aiuaimod.cpp lines 3733-3747
// __thiscall, virtual (but we don't rely on virtual here)
int UnitAIModule::defendPosition(float targetX, float targetY,
                                 float desiredDistance, int unconditional) {
    if (unconditional == 0 && this->currentActionValue != -1) {
        return 0;
    }

    // setCurrentAction(0x259)
    this->setCurrentAction(0x259);

    // setCurrentTarget(-1, x, y, this->objectValue->world_z)
    this->setCurrentTarget(-1, targetX, targetY, this->objectValue->world_z);

    // this->defendTargetValue = -1;
    this->defendTargetValue = -1;

    // this->desiredTargetDistanceValue = distance;
    this->desiredTargetDistanceValue = desiredDistance;

    return 1;
}


int UnitAIModule::seekAndDestroy(int targetID, int tX, int tY,
                                 int unconditional) {
    if ((unconditional != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->attack(targetID, unconditional) == 1) {
            this->setCurrentAction(0x26E);
            this->setCurrentTarget(targetID, (float)tX, (float)tY, 1.0f);
            return 1;
        }
    }
    return 0;
}



int UnitAIModule::exploreAndDestroy(int tX, int tY, int unconditional) {
    if ((unconditional != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->explore(tX, tY, unconditional) == 1) {
            this->setCurrentAction(0x26F);
            this->setCurrentTarget(-1, (float)tX, (float)tY, 1.0f);
            return 1;
        }
    }
    return 0;
}


void UnitAIModule::removeCurrentTarget() {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = -1;
    this->currentTargetTypeValue = -1;
    this->currentTargetXValue = -1.0f;
    this->currentTargetYValue = -1.0f;
    this->currentTargetZValue = -1.0f;
}


void UnitAIModule::setCurrentTarget(int o, float x, float y, float z) {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = o;
    this->currentTargetXValue = x;
    this->currentTargetYValue = y;
    this->currentTargetZValue = z;

    RGE_Static_Object* object = this->objectValue->owner->world->object(o);
    if (object != 0) {
        this->currentTargetTypeValue = object->master_obj->object_group;
    }
}


void UnitAIModule::setCurrentTarget(int o, int t, float x, float y, float z) {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = o;
    this->currentTargetTypeValue = t;
    this->currentTargetXValue = x;
    this->currentTargetYValue = y;
    this->currentTargetZValue = z;
}


int UnitAIModule::importantObject(int unitType) {
    int i = 0;
    int count = this->numberImportantObjects;

    if (count <= 0) {
        return 0;
    }

    while (i < count) {
        if (this->importantObjects[i] == unitType) {
            return 1;
        }
        i++;
    }

    return 0;
}


int UnitAIModule::isEnemyOwner(int oID) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == oID) {
        return 0;
    }
    return owner->relations[oID] == 3;
}

// compact ally-owner check first


int UnitAIModule::isAllyOwner(int oID) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == oID) {
        return 1;
    }
    if (owner->relations[oID] == 0 && owner->world->players[oID]->relations[owner->id] == 0) {
        return 1;
    }
    return 0;
}


int UnitAIModule::isNeutralOwner(int oID) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == oID) {
        return 0;
    }
    return owner->relations[oID] == 1;
}

// __thiscall with 3 params: RGE_Visible_Map* vMap, int x, int y
// ret 0Ch = 3 params cleaned.
// Similar to get_visible but accessed via this->objectValue->owner instead of direct player.
// The map offset table is the canonical view provider.

unsigned char UnitAIModule::visibleStatus(class RGE_Visible_Map* vMap, int x,
                                          int y) {
    unsigned long cell = unified_map_offsets[y][x];
    RGE_Player* owner = this->objectValue->owner;
    if ((owner->mutualVisibleMask & cell) != 0) return 0x0F;
    if ((cell & owner->mutualExploredMask) != 0) return 0x80;
    return 0;
}

int debug_rand(char* file, int line);


void UnitAIModule::setAdjustedIdleTimeout(void) {
    unsigned int idleTimeout = this->idleTimeoutValue;
    unsigned int value = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 3916);

    this->adjustedIdleTimeoutValue = value % (idleTimeout >> 1) + ((idleTimeout * 3) >> 2);
}


void UnitAIModule::setTaskedByPlayer() {
    this->purgeNotifyQueue(0);
}


int UnitAIModule::convertToLOSResourceType(int type) {
    return -1;
}

// UnitAIModule::setPlayStatus
// Natural play-status setter.

void UnitAIModule::setPlayStatus(AIPlayStatus* ps) {
    if (playStatus == 0) {
        playStatus = new AIPlayStatus();
    }
    if (playStatus != 0 && ps != 0) {
        playStatus->copy(ps);
    }
}

// The method scans the two terminal visible-unit buckets.


int __cdecl debug_rand(char* file, int line);

void UnitAIModule::lookAround() {
    RGE_Game_World* world;
    int ownerID;

    this->search();

    int obj_id = this->objectValue->id;
    RGE_Player* owner = this->objectValue->owner;
    ownerID = owner->id;
    world = owner->world;

    for (int category = 4; category > 2; --category) {
        for (int j = 0; j < VisibleUnitList_Size[category]; ++j) {
            VISIBLE_UNIT_REC* entries = VisibleUnitList[category];
            RGE_Static_Object* obj = world->object(entries[j].object_id);
            if (obj != 0 && obj->object_state <= 2) {
                this->objectValue->owner->notify(obj_id, ownerID, 0x20D, obj->id, 0, 0);
            }
        }
    }

    this->lookAroundTimerValue = 0;
    this->lookAroundTimeoutValue =
        debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 3986) % 1000 + 4000;
}

// Searches an array of OrderEvent structs (stride 0x24) for a matching order type.
// Returns 1 if found, 0 if not.
int UnitAIModule::hasOrderOnQueue(int orderNumber) {
    int count = this->orderQueueSizeValue;
    int index = 0;
    if (count <= 0) return 0;

    while (index < count) {
        if ((this->orderQueueValue + index)->orderType == orderNumber) return 1;
        index++;
    }
    return 0;
}

// The source scans the two canonical visible-unit result buckets.


void UnitAIModule::askForHelp(int unitToAttack) {
    RGE_Static_Object* callerObject = this->lookupObject(unitToAttack);
    if (callerObject != 0) {
        this->search();

        int category = 0;
        do {
            int i = 0;
            if (VisibleUnitList_Size[category + 1] > 0) {
                do {
                    if (this->objectValue->id != VisibleUnitList[category + 1][i].object_id) {
                        RGE_Static_Object* object =
                            this->lookupObject(VisibleUnitList[category + 1][i].object_id);
                        if (object != 0 && object->unitAI() != 0) {
                            RGE_Player* owner = object->owner;
                            if (owner != 0 && object->object_state <= 2) {
                                short group = object->master_obj->object_group;
                                if (group != 1 && group != 3 && group != 4 && group != 0x15 && group != 0x12 &&
                                    group != 0x14 && group != 0x1b) {
                                    short ownerId = this->objectValue->owner->id;
                                    if (owner->id == ownerId || owner->isAlly(ownerId)) {
                                        if (this->objectValue->distance_to_object(object) <= 3.0f) {
                                            if (object->unitAI()->currentAction() == -1) {
                                                if (object->unitAI()->currentOrder() == -1) {
                                                    if (object->unitAI()->orderQueueSize() <= 0) {
                                                        UnitAIModule* targetAI = object->unitAI();
                                                        targetAI->order(object->owner->id, 0x2bc, unitToAttack,
                                                                        callerObject->owner->id, callerObject->world_x,
                                                                        callerObject->world_y, callerObject->world_y,
                                                                        object->weaponRange(), 1, 0, 0x32);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    ++i;
                } while (i < VisibleUnitList_Size[category + 1]);
            }
            ++category;
        } while (category <= 1);
    }
}



int UnitAIModule::processOrder(OrderEvent* oEvent, int orderNumber) {
    int result = 0;
    switch (oEvent->orderType) {
    case 0x2d6: {
        result = 1;
        AIPlay* play = this->objectValue->owner->world->playbook->play(oEvent->targetOwner);
        if (play == 0) {
            result = 0;
            break;
        }

        if (this->playStatus != 0)
            operator delete(this->playStatus);

        this->playStatus = new AIPlayStatus();
        if (this->playStatus == 0) {
            result = 0;
            break;
        }

        this->playStatus->playNumberValue = oEvent->targetOwner;
        this->playStatus->targetValue = oEvent->target;
        if (oEvent->targetX != -1.0f) {
            int z;
            int y;
            int x;
            z = (int)oEvent->targetZ;
            y = (int)oEvent->targetY;
            x = (int)oEvent->targetX;
            AIPlayStatus* status = this->playStatus;
            status->originalPointValue.xValue = x;
            status->originalPointValue.yValue = y;
            status->originalPointValue.zValue = z;
        } else {
            int z;
            int y;
            int x;
            z = (int)this->objectValue->world_z;
            y = (int)this->objectValue->world_y;
            x = (int)this->objectValue->world_x;
            AIPlayStatus* status = this->playStatus;
            status->originalPointValue.xValue = x;
            status->originalPointValue.yValue = y;
            status->originalPointValue.zValue = z;
        }
        break;
    }

    case 0x2d7:
        if (this->playStatus != 0) {
            operator delete(this->playStatus);
            this->playStatus = 0;
        }
        result = 1;
        break;

    case 0x2c2:
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0)
                id = this->objectValue->id;
            else
                id = -1;
            fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x105d);
            this->stopObject(1);
            result = 1;
            break;
        }
        goto stop_without_log;

    case 0x2c6:
        result = this->moveTo(oEvent->targetX, oEvent->targetY, oEvent->targetZ, oEvent->range, 1);
        break;

    case 0x2bc:
        result = this->attackObject(oEvent->target, 1);
        break;

    case 0x2d9:
        result = this->attackRoundupObject(oEvent->target);
        break;

    case 0x2bd:
        if (oEvent->target == -1) {
            result = this->defendPosition(oEvent->targetX, oEvent->targetY, oEvent->range, 1);
        } else {
            result = this->defendObject(oEvent->target, oEvent->range, 1);
        }
        break;

    case 0x2ce:
        result = this->repairObject(oEvent->target, 1);
        break;

    case 0x2d1:
        result = this->unload(1, oEvent->targetX, oEvent->targetY);
        break;

    case 0x2d2:
        result = this->seekAndDestroy(oEvent->target, (int)oEvent->targetX, (int)oEvent->targetY, 1);
        break;

    case 0x2d3:
        result = this->exploreAndDestroy((int)oEvent->targetX, (int)oEvent->targetY, 1);
        break;

    case 0x2c1:
        result = this->explore((int)oEvent->targetX, (int)oEvent->targetY, 1);
        break;

    case 0x2be:
        result = this->buildObject(oEvent->target, 1);
        break;

    case 0x2d4:
        result = this->moveTo(oEvent->targetX, oEvent->targetY, oEvent->targetZ, oEvent->range, 1);
        break;

    case 0x2c8:
        result = this->followObject(oEvent->target, oEvent->range, 1);
        break;

    case 0x2cd:
        result = this->enterObject(oEvent->target, 1);
        break;

    case 0x2ca:
        result = this->transportObject(oEvent->targetX, oEvent->targetY, oEvent->targetZ, 1);
        break;

    case 0x2d5:
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0)
                id = this->objectValue->id;
            else
                id = -1;
            fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x10e9);
        }

    stop_without_log:
        this->stopObject(1);
        result = 1;
        break;

    case 0x2bf:
        result = this->healObject(oEvent->target, 1);
        break;

    case 0x2c0:
        result = this->convertObject(oEvent->target, 1);
        break;

    case 0x2d8:
        result = 1;
        this->currentActionValue = 0x274;
        this->currentOrderValue = 0x2d8;
        break;

    case 0x2c5:
        result = this->gatherObject(oEvent->target, 1);
        break;

    case 0x2c9:
        result = this->huntObject(oEvent->target, 1);
        break;

    default:
        break;

    }

    if (result == 1) {
        int orderType = oEvent->orderType;
        if (orderType == 0x2c2) {
            this->currentOrderValue = -1;
            this->currentOrderPriorityValue = -1;
        } else {
            if (orderType == 0x2d9) {
                this->currentOrderValue = 700;
            } else if (orderType == 700 && this->objectValue->master_obj->id == 0x7d) {
                this->currentOrderValue = -1;
                this->currentTargetValue = -1;
            } else {
                this->currentOrderValue = orderType;
            }
            this->currentOrderPriorityValue = oEvent->priority;
        }
    }

    if (orderNumber >= 0 && orderNumber < this->orderQueueSizeValue && this->orderQueueValue != 0) {
        if (orderNumber < this->orderQueueSizeValue - 1) {
            do {
                this->orderQueueValue[orderNumber].issuer =
                    this->orderQueueValue[orderNumber + 1].issuer;
                this->orderQueueValue[orderNumber].orderType =
                    this->orderQueueValue[orderNumber + 1].orderType;
                this->orderQueueValue[orderNumber].priority =
                    this->orderQueueValue[orderNumber + 1].priority;
                this->orderQueueValue[orderNumber].target =
                    this->orderQueueValue[orderNumber + 1].target;
                this->orderQueueValue[orderNumber].targetOwner =
                    this->orderQueueValue[orderNumber + 1].targetOwner;
                this->orderQueueValue[orderNumber].targetX =
                    this->orderQueueValue[orderNumber + 1].targetX;
                this->orderQueueValue[orderNumber].targetY =
                    this->orderQueueValue[orderNumber + 1].targetY;
                this->orderQueueValue[orderNumber].targetZ =
                    this->orderQueueValue[orderNumber + 1].targetZ;
                ++orderNumber;
            } while (orderNumber < this->orderQueueSizeValue - 1);
        }
        --this->orderQueueSizeValue;
    }

    return result == 1;
}


typedef unsigned long ulong;

int UnitAIModule::processNotify(NotifyEvent* nEvent, ulong uTime) {
    switch (nEvent->mType) {
    case 500:
    case 0x20f:
        this->notifyCommander(nEvent);

        if (nEvent->p2 < 1) {
            this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x209, nEvent->caller, 0, 0);
            this->purgeNotifyQueue(uTime);
            return 4;
        }

        if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
            this->objectValue->owner->notify(this->objectValue->id, this->objectValue->id, 0x201, nEvent->caller, 0, 0);
        }

        {
            int i = 0;
            while (i < this->attackingUnitsValue.numberValue && i < this->attackingUnitsValue.maximumSizeValue) {
                if (this->attackingUnitsValue.value[i] == nEvent->caller) {
                    goto caller_recorded;
                }
                ++i;
            }

            if (this->objectValue->owner->computerPlayer() == 0 && this->currentTargetValue != nEvent->caller) {
                this->askForHelp(nEvent->caller);
            }
        }

caller_recorded:
        {
            int caller = nEvent->caller;
            int i = 0;
            while (i < this->attackingUnitsValue.numberValue && i < this->attackingUnitsValue.maximumSizeValue) {
                if (this->attackingUnitsValue.value[i] == caller) {
                    goto attacker_recorded;
                }
                ++i;
            }

            if (this->attackingUnitsValue.maximumSizeValue - 1 < this->attackingUnitsValue.numberValue) {
                int newSize = this->attackingUnitsValue.numberValue + 1;
                int* newValues =
                    (int*)::operator new(newSize * sizeof(int));
                if (newValues != 0) {
                    int j = 0;
                    while (j < this->attackingUnitsValue.maximumSizeValue && j < newSize) {
                        newValues[j] = this->attackingUnitsValue.value[j];
                        ++j;
                    }
                    ::operator delete(this->attackingUnitsValue.value);
                    this->attackingUnitsValue.value = newValues;
                    this->attackingUnitsValue.maximumSizeValue = newSize;
                }
            }

            this->attackingUnitsValue.value[
                this->attackingUnitsValue.numberValue] = caller;
            ++this->attackingUnitsValue.numberValue;
        }

attacker_recorded:
        this->objectValue->setUnderAttack(1);

        if (this->currentOrderValue != 0x2d5 && this->currentOrderValue != -1 &&
            this->objectValue->owner->computerPlayer() == 0) {
            return 2;
        }
        if (this->currentOrderValue == 0x2d5) {
            return 2;
        }

        {
            RGE_Static_Object* attacker = this->lookupObject(nEvent->caller);
            if (attacker == 0) {
                return 2;
            }
            if (attacker->owner->id == this->objectValue->owner->id) {
                return 2;
            }

            if (this->currentActionValue == 0x25b && this->runAwayFromAttackers(1) == 1) {
                return 3;
            }

            RGE_Static_Object* target = 0;
            if (this->currentTargetValue != -1) {
                target = this->lookupObject(this->currentTargetValue);
            }

            if (target != 0) {
                short group = target->master_obj->object_group;
                if ((group == 3 || group == 0x1b) && target->master_obj->id != 0x4f && target->master_obj->id != 0xc7 &&
                    target->master_obj->id != 0x45 && this->objectValue->owner->computerPlayer() == 0) {
                    if (this->canAttackUnit(attacker) != 1) {
                        this->runAwayFromAttackers(1);
                        return 3;
                    }
                    if (this->objectValue->inAttackRange(attacker) != 1 &&
                        this->objectValue->canPath(nEvent->caller, this->objectValue->weaponRange(), 0, 0, -1, -1) != 1) {
                        this->runAwayFromAttackers(1);
                        return 3;
                    }

                    this->attackObject(nEvent->caller, 1);
                    return 3;
                }

                if (this->objectValue->owner->computerPlayer() != 1) {
                    return 2;
                }
                if (target->master_obj->id == 0x114) {
                    return 2;
                }

                float currentTargetDC = target->damageCapability();
                float ownDamage = 0.0f;
                if (currentTargetDC != g_unit_ai_zero_float) {
                    ownDamage = this->objectValue->damageCapability(target);
                }

                if (this->canAttackUnit(attacker) == 1 && ownDamage == g_unit_ai_zero_float) {
                    if (this->objectValue->inAttackRange(attacker) != 1 &&
                        this->objectValue->canPath(nEvent->caller, this->objectValue->weaponRange(), 0, 0, -1, -1) != 1) {
                        goto compare_attacker;
                    }
                    this->attackObject(nEvent->caller, 1);
                }

compare_attacker:
                float killTimeTarget =
                    target->damageCapability(this->objectValue);
                if (killTimeTarget > g_unit_ai_zero_float) {
                    killTimeTarget = target->hp / killTimeTarget;
                } else {
                    killTimeTarget = 25000.0f;
                }

                float killTimeAttacker =
                    attacker->damageCapability(this->objectValue);
                if (killTimeAttacker > g_unit_ai_zero_float) {
                    killTimeAttacker = attacker->hp / killTimeAttacker;
                } else {
                    killTimeAttacker = 25000.0f;
                }

                if (this->canAttackUnit(attacker) != 1 || !(killTimeAttacker < killTimeTarget)) {
                    return 2;
                }
                if (this->objectValue->inAttackRange(attacker) != 1 &&
                    this->objectValue->canPath(nEvent->caller, this->objectValue->weaponRange(), 0, 0, -1, -1) != 1) {
                    return 2;
                }
                this->attackObject(nEvent->caller, 1);
                return 2;
            }

            if (this->canAttackUnit(attacker) == 1) {
                if (this->objectValue->inAttackRange(attacker) != 1 &&
                    this->objectValue->canPath(nEvent->caller, this->objectValue->weaponRange(), 0, 0, -1, -1) != 1) {
                    goto no_target_fallback;
                }
                if (this->attackObject(nEvent->caller, 1) != 1) {
                    return 3;
                }
                if (this->currentOrderValue != 0x2bc) {
                    this->currentOrderValue = -1;
                }
                return 3;
            }

no_target_fallback:
            if (this->currentActionValue != 0x262) {
                this->runAwayFromAttackers(1);
            }
            return 3;
        }

    // The original byte map routes mType 0x1fa to the block at 00418737.
    case 0x1fa:
        if (this->currentOrderValue == 0x2bc && nEvent->p1 == 0x258) {
            if (this->processIdle(0) != 5) {
                return 2;
            }

            if (this->currentOrderValue == 0x2d5 || this->objectValue->owner->computerPlayer() == 0) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x128b);
                }
                this->stopObject(0);
                return 2;
            }

            if (this->moveTo(this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue,
                             this->desiredTargetDistanceValue - g_unit_ai_desired_distance_adjustment, 1) != 0) {
                int oldOrder = this->currentOrderValue;
                this->currentOrderValue = -1;
                this->currentOrderPriorityValue = -1;
                this->lastOrderValue = oldOrder;
                return 2;
            }

            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x129b);
            }
            this->stopObject(0);
            return 2;
        }

        if (this->currentOrderValue != -1 && this->currentOrderValue == this->currentActionValue + 100) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x12af);
            }
            this->stopObject(1);
            return 2;
        }
        if (this->currentOrderValue == -1 && this->currentActionValue == nEvent->p1) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x12b7);
            }
            this->stopObject(1);
            return 2;
        }
        if (this->currentOrderValue == 0x2d4 && nEvent->p1 == 0x262) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x12c0);
            }
            this->stopObject(0);
            return 2;
        }
        if (this->currentOrderValue == 0x2bd && nEvent->p1 == 0x262) {
            this->setCurrentAction(-1);
            return 2;
        }
        if (this->currentOrderValue == 0x2d5 && nEvent->p1 == 0x258) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x12cd);
            }
            this->stopObject(1);
            return 2;
        }
        return 2;

    // The original byte map routes mType 0x1f9 to the block at 00418A26.
    case 0x1f9:
        if (this->currentOrderValue == 0x2bc && nEvent->p1 == 0x258) {
            if (this->processIdle(0) != 5) {
                return 2;
            }

            if (this->currentOrderValue == 0x2d5 || this->objectValue->owner->computerPlayer() == 0) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x12e9);
                }
                this->stopObject(1);
                return 2;
            }

            if (this->moveTo(this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue,
                             this->desiredTargetDistanceValue - g_unit_ai_desired_distance_adjustment, 1) != 0) {
                int oldOrder = this->currentOrderValue;
                this->currentOrderValue = -1;
                this->currentOrderPriorityValue = -1;
                this->lastOrderValue = oldOrder;
                return 2;
            }

            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x12f3);
            }
            this->stopObject(1);
            return 2;
        }

        if (this->currentOrderValue != -1 && this->currentOrderValue == this->currentActionValue + 100) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x1304);
            }
            this->stopObject(1);
            this->notifyCommander(nEvent);
            return 2;
        }
        if (this->currentOrderValue == -1 && this->currentActionValue == nEvent->p1) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x130d);
            }
            this->stopObject(1);
            this->notifyCommander(nEvent);
            return 2;
        }
        if (this->currentOrderValue == 0x2d4 && nEvent->p1 == 0x262) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x1317);
            }
            this->stopObject(0);
            this->notifyCommander(nEvent);
            return 2;
        }
        if (this->currentOrderValue == 0x2bd && nEvent->p1 == 0x262) {
            this->setCurrentAction(-1);
            return 2;
        }
        if (this->currentOrderValue == 0x2d5 && nEvent->p1 == 0x258) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x1325);
            }
            this->stopObject(1);
            return 2;
        }
        return 2;

    case 0x1fb:
        if (this->currentOrderValue == 0x2bc && nEvent->p1 == 0x258) {
            if (this->processIdle(0) != 5) {
                return 2;
            }

            if (this->currentOrderValue == 0x2d5 || this->objectValue->owner->computerPlayer() == 0) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x1341);
                }
                this->stopObject(1);
                return 2;
            }

            if (this->moveTo(this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue,
                             this->desiredTargetDistanceValue - g_unit_ai_desired_distance_adjustment, 1) != 0) {
                int oldOrder = this->currentOrderValue;
                this->currentOrderValue = -1;
                this->currentOrderPriorityValue = -1;
                this->lastOrderValue = oldOrder;
                return 2;
            }

            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x134b);
            }
            this->stopObject(1);
            return 2;
        }

        if (this->currentOrderValue != -1 && this->currentOrderValue == this->currentActionValue + 100) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x135c);
            }
            this->stopObject(1);
            this->notifyCommander(nEvent);
            return 2;
        }
        if (this->currentOrderValue == -1 && this->currentActionValue == nEvent->p1) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x1365);
            }
            this->stopObject(1);
            this->notifyCommander(nEvent);
            return 2;
        }
        if (this->currentOrderValue == 0x2d4 && nEvent->p1 == 0x262) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x136f);
            }
            this->stopObject(0);
            this->notifyCommander(nEvent);
            return 2;
        }
        if (this->currentOrderValue == 0x2bd && nEvent->p1 == 0x262) {
            this->setCurrentAction(-1);
            return 2;
        }
        if (this->currentOrderValue == 0x2d5 && nEvent->p1 == 0x258) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x137d);
            }
            this->stopObject(1);
            return 2;
        }
        return 2;

    case 0x1fc:
        {
            RGE_Static_Object* target =
                this->lookupObject(this->currentTargetValue);
            if (target != 0) {
                int tileY = (int)target->world_y;
                int tileX = (int)target->world_x;
                unsigned char visible = this->visibleStatus(this->objectValue->owner->visible, tileX, tileY);
                if (target->owner->id != 0 && visible != 0x0f) {
                    float lastTargetZValue = this->currentTargetZValue;
                    float lastTargetXValue = this->currentTargetXValue;
                    float lastTargetYValue = this->currentTargetYValue;
                    int newTarget = this->bestUnitToAttack(1, 0, 0);
                    if (newTarget != -1 && newTarget != this->currentTargetValue && this->attackObject(newTarget, 1) == 1) {
                        this->currentOrderValue = -1;
                        return 3;
                    }

                    if (this->objectValue->owner->computerPlayer() == 0 &&
                        this->moveTo(lastTargetXValue, lastTargetYValue, lastTargetZValue, 0, 1) == 1) {
                        int oldOrder = this->currentOrderValue;
                        this->currentOrderValue = -1;
                        this->lastOrderValue = oldOrder;
                        this->currentOrderPriorityValue = -1;
                        return 3;
                    }
                } else {
                    return 2;
                }
            }

            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x1269);
            }
            this->stopObject(1);
            this->notifyCommander(nEvent);
            return 2;
        }

    case 0x1fe:
        this->objectValue->stopAction();
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id = this->objectValue != 0 ? this->objectValue->id : -1;
            fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x13f9);
        }
        this->stopObject(1);
        return 2;

    case 0x202:
        {
            int action = this->currentActionValue;
            if (action == 0x25d || action == 0x26f) {
                int x;
                int y;
                if (this->closestUndiscoveredTile(&x, &y, 1) == 1) {
                    this->addToWaypointQueue(x, y);
                    if (this->explore(x, y, 1) == 0) {
                        this->removeCurrentTarget();
                        if (actionFile != 0) {
                            int id = this->objectValue != 0 ? this->objectValue->id : -1;
                            fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x1396);
                        }
                        this->stopObject(1);
                        this->notifyCommander(nEvent);
                    }
                    this->currentActionValue = action;
                    return 3;
                }

                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x13a6);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
                return 2;
            }

            if (action != 0x261) {
                return 2;
            }

            int targetType = this->currentTargetTypeValue;
            if (targetType == -1) {
                targetType = this->lastTargetTypeValue;
            }

            int resourceType = this->convertToLOSResourceType(targetType);
            int targetID;
            if (resourceType == -1) {
                targetID = this->closestObject(targetType, -1, -1, -1, 0);
            } else {
                targetID = this->closestResourceObject(resourceType, 0);
            }

            if (targetID == -1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x13da);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
                return 2;
            }

            if (this->gatherObject(targetID, 1) == 1) {
                return 3;
            }

            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id = this->objectValue != 0 ? this->objectValue->id : -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x13ce);
            }
            this->stopObject(1);
            this->notifyCommander(nEvent);
            return 2;
        }

    case 0x20b:
        this->objectValue->stopAction();
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id = this->objectValue != 0 ? this->objectValue->id : -1;
            fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x13e7);
        }
        this->stopObject(1);
        this->purgeNotifyQueue(uTime);
        this->orderQueueSizeValue = 0;
        {
            RGE_Static_Object* commander =
                this->lookupObject(this->objectValue->groupCommanderValue);
            if (commander == 0) {
                return 2;
            }
            commander->commanderRemoveFromGroup(this->objectValue->id);
        }
        return 2;

    case 600:
        {
            int caller = nEvent->caller;
            int i = 0;
            while (i < this->attackingUnitsValue.numberValue && i < this->attackingUnitsValue.maximumSizeValue) {
                if (this->attackingUnitsValue.value[i] == caller) {
                    goto already_attacking;
                }
                ++i;
            }

            if (this->attackingUnitsValue.maximumSizeValue - 1 < this->attackingUnitsValue.numberValue) {
                int newSize = this->attackingUnitsValue.numberValue + 1;
                int* newValues =
                    (int*)::operator new(newSize * sizeof(int));
                if (newValues != 0) {
                    int j = 0;
                    while (j < this->attackingUnitsValue.maximumSizeValue && j < newSize) {
                        newValues[j] = this->attackingUnitsValue.value[j];
                        ++j;
                    }
                    ::operator delete(this->attackingUnitsValue.value);
                    this->attackingUnitsValue.value = newValues;
                    this->attackingUnitsValue.maximumSizeValue = newSize;
                }
            }

            this->attackingUnitsValue.value[
                this->attackingUnitsValue.numberValue] = caller;
            ++this->attackingUnitsValue.numberValue;
        }

already_attacking:
        this->objectValue->setUnderAttack(1);
        return 2;

    case 699:
        {
            int count = this->attackingUnitsValue.numberValue;
            int i = 0;
            while (i < count && i < this->attackingUnitsValue.maximumSizeValue) {
                if (this->attackingUnitsValue.value[i] == nEvent->caller) {
                    goto remove_attacker;
                }
                ++i;
            }
            return 2;

remove_attacker:
            count = this->attackingUnitsValue.maximumSizeValue;
            i = 0;
            while (i < count) {
                if (this->attackingUnitsValue.value[i] == nEvent->caller) {
                    break;
                }
                ++i;
            }
            if (i >= count) {
                return 2;
            }
            if (i < count - 1) {
                do {
                    this->attackingUnitsValue.value[i] =
                        this->attackingUnitsValue.value[i + 1];
                    ++i;
                } while (i < count - 1);
            }
            --this->attackingUnitsValue.numberValue;
            if (this->attackingUnitsValue.numberValue < 0) {
                this->attackingUnitsValue.numberValue = 0;
            }
            return 2;
        }

    case 0x1f6:
    case 0x1f7:
    case 0x1f8:
    case 0x1fd:
    case 0x1ff:
    case 0x200:
    case 0x203:
    case 0x259:
    case 0x25a:
    case 0x25b:
    case 0x25c:
    case 0x25d:
    case 0x25e:
    case 0x25f:
    case 0x260:
    case 0x261:
    case 0x262:
    case 0x265:
    case 0x266:
    case 0x267:
    case 0x268:
    case 0x269:
        return 2;

    default:
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id = this->objectValue != 0 ? this->objectValue->id : -1;
            fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x1439);
        }
        this->stopObject(1);
        this->notifyCommander(nEvent);
        return 2;
    }
}

// aiuaimod.cpp lines 5191-5250
// Body boundary: 00419510-004195E0; padding starts at 004195E1.
// This is the first normal aiuaimod.cpp sibling after processNotify, which ends at 004193F3.
// The source uses the canonical play and phase providers.


void UnitAIModule::processGroupNotify(NotifyEvent* nEvent) {
    AIPlay* play;
    AIPlayPhase* phase;

    if (this->playStatus != 0 &&
        (play = this->objectValue->owner->world->playbook->play(this->playStatus->playNumberValue)) != 0 &&
        (phase = play->phase(this->playStatus->currentPhaseValue)) != 0 && nEvent->mType == 500) {
        this->playStatus->savedAttackerValue = nEvent->caller;
        int i = 0;
        do {
            AIPlayPhaseTrigger* trigger = phase->trigger(i);
            if (trigger != 0 && trigger->type() != 0) {
                if (trigger->type() == 5) {
                    this->selectNewPlayPhase(trigger->nextPhase(), 0);
                } else if (trigger->type() == 4) {
                    int value1 = trigger->value1();
                    if (value1 == this->playStatus->group(nEvent->recipient)) {
                        this->selectNewPlayPhase(trigger->nextPhase(), 0);
                    }
                }
            }
            ++i;
        } while (i < 3);
    }
}

// Body boundary: 004195F0-00419642; processGroupNotify ends at 004195E0.
// In the complete wrapper, the canonical class supplies get_type, find_unit,
// and do_stuff as direct helpers. A shared ABI repair is required before this
// owner can match in the complete TU.


int UnitAIModule::processIdle(int doSearch) {
    if (doSearch == 1 && this->processRetryableOrder() == 8)
        return 6;

    int idx = this->bestUnitToAttack(1, 0, 0);
    if (idx != -1) {
        if (this->attackObject(idx, 1) == 1)
            return 6;
    }

    return 5;
}


int UnitAIModule::processMisc() {
    int invalidValue = -1;
    int order;

    if (this->currentOrderValue != invalidValue) {
        order = this->currentOrderValue;
    } else {
        if (this->currentActionValue != invalidValue) {
            order = this->currentActionValue;
            order += 100;
        } else {
            order = invalidValue;
        }
    }

    switch (order) {
    case 700: {
        if (taskedThisUpdate != 1 && this->objectValue->owner->computerPlayer() != 0 &&
            this->objectValue->can_attack() != 0) {
            RGE_Static_Object* oldTarget =
                this->lookupObject(this->currentTargetValue);
            if (oldTarget == 0 || oldTarget->master_obj->id != 0x114) {
                int candidateID = this->bestUnitToAttack(0, 0, 0);
                RGE_Static_Object* candidate = this->lookupObject(candidateID);
                if (candidateID != invalidValue && candidate != 0 && candidateID != this->currentTargetValue) {
                    short group = candidate->master_obj->object_group;
                    if (group == 3 || group == 0x1B) {
                        if (candidate->master_obj->id == 0x114) {
                            this->order(this->objectValue->id, 700, candidateID, candidate->owner->id,
                                        candidate->world_x, candidate->world_y, candidate->world_z,
                                        this->objectValue->weaponRange(), 1, 0, this->currentOrderPriorityValue);
                        }
                    } else if (oldTarget == 0 || oldTarget->master_obj->object_group == 3 ||
                               oldTarget->master_obj->object_group == 0x1B) {
                        this->order(this->objectValue->id, 700, candidateID, candidate->owner->id,
                                    candidate->world_x, candidate->world_y, candidate->world_z, this->objectValue->weaponRange(),
                                    1, 0, this->currentOrderPriorityValue);
                        return 9;
                    }
                }
            }
        }
        break;
    }

    case 0x2BD: {
        RGE_Static_Object* target = 0;

        if (this->defendTargetValue != invalidValue) {
            target = this->lookupObject(this->defendTargetValue);
            if (target == 0) {
                this->defendTargetValue = invalidValue;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = invalidValue;
                    }
                    fprintf(actionFile, str_fmt_stopObject, objectID, str_aiuaimod_path, 0x15C0);
                }
                this->stopObject(1);
                this->currentOrderValue = invalidValue;
                return 9;
            }

            if (this->currentTargetXValue == -1.0f) {
                this->currentTargetXValue = target->world_x;
                this->currentTargetYValue = target->world_y;
            }

            if (target->object_state > 2 && target->owner->id != 0) {
                this->defendTargetValue = invalidValue;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = invalidValue;
                    }
                    fprintf(actionFile, str_fmt_stopObject, objectID, str_aiuaimod_path, 0x15D9);
                }
                this->stopObject(1);
                this->currentOrderValue = invalidValue;
                return 9;
            }
        }

        if (this->currentActionValue != 600 && (this->currentActionValue != 0x262 ||
             this->objectValue->currentTargetID() != this->defendTargetValue)) {
            float distance;
            if (this->defendTargetValue != invalidValue) {
                this->currentTargetXValue = target->world_x;
                this->currentTargetYValue = target->world_y;
                this->currentTargetZValue = target->world_z;
                distance = this->objectValue->distance_to_object(target);
            } else {
                distance = this->objectValue->distance_to_position(this->currentTargetXValue, this->currentTargetYValue,
                                                                   this->objectValue->world_z);
            }

            if (distance > this->desiredTargetDistanceValue - (-1.0f)) {
                if (this->defendTargetValue != invalidValue) {
                    if (this->objectValue->canPath(this->defendTargetValue, this->desiredTargetDistanceValue,
                                                   0, 0, invalidValue, invalidValue) == 1) {
                        this->moveTo(this->defendTargetValue, this->desiredTargetDistanceValue, 1);
                        return 10;
                    }
                } else {
                    int x = (int)this->currentTargetXValue;
                    int y = (int)this->currentTargetYValue;
                    XYZPoint point = { x, y, invalidValue };
                    if (this->objectValue->canPath(point, this->desiredTargetDistanceValue, invalidValue, 0, 0,
                                                   invalidValue, invalidValue) == 1) {
                        this->moveTo(this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue,
                                     this->desiredTargetDistanceValue, 1);
                        return 10;
                    }
                }
                return 10;
            }

            if (target != 0 && target->unitAI() != 0) {
                UnitAIModule* targetAI = target->unitAI();
                int attacker = targetAI->closestAttacker(0);
                if (attacker != invalidValue) {
                    this->attackObject(attacker, 1);
                    return 10;
                }
                if (this->processIdle(0) == 6) {
                    return 10;
                }
            }
        }
        break;
    }

    case 0x2C8: {
        RGE_Static_Object* target = 0;
        if (this->currentTargetValue != invalidValue) {
            target = this->lookupObject(this->currentTargetValue);
            if (target == 0 || target->object_state > 2) {
                this->defendTargetValue = invalidValue;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = invalidValue;
                    }
                    fprintf(actionFile, str_fmt_stopObject, objectID, str_aiuaimod_path, 0x1582);
                }
                this->stopObject(1);
                this->currentOrderValue = invalidValue;
                return 9;
            }
        }

        float xDiff;
        float yDiff;
        if (target != 0) {
            xDiff = target->world_x - this->currentTargetXValue;
        } else {
            xDiff = -10.0f;
        }
        if (target != 0) {
            yDiff = target->world_y - this->currentTargetYValue;
        } else {
            yDiff = -10.0f;
        }

        if (xDiff < g_unit_ai_coordinate_lower_bound || xDiff > g_unit_ai_coordinate_upper_bound || yDiff < g_unit_ai_coordinate_lower_bound || yDiff > g_unit_ai_coordinate_upper_bound) {
            float distance;
            if (this->currentTargetValue != invalidValue) {
                this->currentTargetXValue = target->world_x;
                this->currentTargetYValue = target->world_y;
                this->currentTargetZValue = target->world_z;
                distance = this->objectValue->distance_to_object(target);
            } else {
                distance = this->objectValue->distance_to_position(this->currentTargetXValue, this->currentTargetYValue,
                                                                   this->objectValue->world_z);
            }

            if (distance > this->desiredTargetDistanceValue) {
                if (this->currentTargetValue != invalidValue) {
                    this->moveTo(this->currentTargetValue, this->desiredTargetDistanceValue, 1);
                    return 10;
                } else {
                    this->moveTo(this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue,
                                 this->desiredTargetDistanceValue, 1);
                    return 10;
                }
            }
        }
        break;
    }

    default:
        break;
    }

    return 9;
}



int UnitAIModule::processRetryableOrder() {
    int result;

    result = this->retryableOrder(this->lastOrderValue);
    if (result == 1) {
        result = this->closestObject(this->lastTargetTypeValue, -1, -1, -1, 0);
        if (result != -1) {
            switch (this->lastOrderValue) {
            case 0x2C5:
                result = this->gatherObject(result, 0);
                return (result == 1) ? 8 : 7;
            case 0x2C9:
                result = this->huntObject(result, 0);
                return (result == 1) ? 8 : 7;
            default:
                return 7;
            }
        }
    }
    return 7;
}

// (?addToOrderQueue@UnitAIModule@@IAEHPAUOrderEvent@@H@Z), aiuaimod.cpp:5751-5755.
// Body boundary: 00419C30-00419C63; 00419C70 is the next sibling.
//
// The protected wrapper forwards all event fields to its sibling overload.


int UnitAIModule::addToOrderQueue(OrderEvent* oEvent, int inFront) {
    return this->addToOrderQueue(oEvent->issuer, oEvent->orderType, oEvent->target, oEvent->targetOwner,
                                 oEvent->targetX, oEvent->targetY, oEvent->targetZ, oEvent->range,
                                 inFront, oEvent->priority);
}

// (?addToOrderQueue@UnitAIModule@@IAEHHHHHMMMMHH@Z), aiuaimod.cpp:5762-5826.
// aiuaimod.cpp
// The protected overload owns the binary queue insertion sequence.


int UnitAIModule::addToOrderQueue(int issuer, int orderType, int target,
                                  int targetOwner, float targetX, float targetY,
                                  float targetZ, float range, int inFront,
                                  int priority) {
    if (this->orderQueueMaxSizeValue == this->orderQueueSizeValue) {
        OrderEvent* newQueue =
            (OrderEvent*)operator new(this->orderQueueMaxSizeValue * 0x48);
        if (newQueue == 0) {
            return 0;
        }

        int i = 0;
        if (this->orderQueueSizeValue > 0) {
            do {
                newQueue[i].issuer = this->orderQueueValue[i].issuer;
                newQueue[i].orderType = this->orderQueueValue[i].orderType;
                newQueue[i].priority = this->orderQueueValue[i].priority;
                newQueue[i].target = this->orderQueueValue[i].target;
                newQueue[i].targetOwner = this->orderQueueValue[i].targetOwner;
                newQueue[i].targetX = this->orderQueueValue[i].targetX;
                newQueue[i].targetY = this->orderQueueValue[i].targetY;
                newQueue[i].targetZ = this->orderQueueValue[i].targetZ;
                newQueue[i].range = this->orderQueueValue[i].range;
                ++i;
            } while (i < this->orderQueueSizeValue);
        }

        if (this->orderQueueValue != 0) {
            operator delete(this->orderQueueValue);
        }
        this->orderQueueValue = newQueue;
        this->orderQueueMaxSizeValue = this->orderQueueMaxSizeValue * 2;
    }

    if ((inFront != 0) && (this->orderQueueSizeValue != 0)) {
        int i = 0;
        if (this->orderQueueSizeValue > 0) {
            do {
                this->orderQueueValue[i + 1].issuer =
                    this->orderQueueValue[i].issuer;
                this->orderQueueValue[i + 1].orderType =
                    this->orderQueueValue[i].orderType;
                this->orderQueueValue[i + 1].priority =
                    this->orderQueueValue[i].priority;
                this->orderQueueValue[i + 1].target =
                    this->orderQueueValue[i].target;
                this->orderQueueValue[i + 1].targetOwner =
                    this->orderQueueValue[i].targetOwner;
                this->orderQueueValue[i + 1].targetX =
                    this->orderQueueValue[i].targetX;
                this->orderQueueValue[i + 1].targetY =
                    this->orderQueueValue[i].targetY;
                this->orderQueueValue[i + 1].targetZ =
                    this->orderQueueValue[i].targetZ;
                this->orderQueueValue[i + 1].range =
                    this->orderQueueValue[i].range;
                ++i;
            } while (i < this->orderQueueSizeValue);
        }

        this->orderQueueValue->issuer = issuer;
        this->orderQueueValue->orderType = orderType;
        this->orderQueueValue->priority = priority;
        this->orderQueueValue->target = target;
        this->orderQueueValue->targetOwner = targetOwner;
        this->orderQueueValue->targetX = targetX;
        this->orderQueueValue->targetY = targetY;
        this->orderQueueValue->targetZ = targetZ;
        this->orderQueueValue->range = range;
        this->orderQueueSizeValue = this->orderQueueSizeValue + 1;
        return 1;
    }

    this->orderQueueValue[this->orderQueueSizeValue].issuer = issuer;
    this->orderQueueValue[this->orderQueueSizeValue].orderType = orderType;
    this->orderQueueValue[this->orderQueueSizeValue].priority = priority;
    this->orderQueueValue[this->orderQueueSizeValue].target = target;
    this->orderQueueValue[this->orderQueueSizeValue].targetOwner = targetOwner;
    this->orderQueueValue[this->orderQueueSizeValue].targetX = targetX;
    this->orderQueueValue[this->orderQueueSizeValue].targetY = targetY;
    this->orderQueueValue[this->orderQueueSizeValue].targetZ = targetZ;
    this->orderQueueValue[this->orderQueueSizeValue].range = range;
    this->orderQueueSizeValue = this->orderQueueSizeValue + 1;
    return 1;
}

// (?addToNotifyQueue@UnitAIModule@@IAEHPAUNotifyEvent@@@Z), aiuaimod.cpp:5831-5834.
// the wrapper reads all six event fields before its direct call.
// Direct target: protected ?addToNotifyQueue@UnitAIModule@@IAEHHHHJJJ@Z at 00419F00.
// The callee uses ret 18h, while this wrapper uses ret 4 for its event pointer.


int UnitAIModule::addToNotifyQueue(NotifyEvent* nEvent) {
    return this->addToNotifyQueue(nEvent->caller, nEvent->recipient, nEvent->mType, nEvent->p1, nEvent->p2, nEvent->p3);
}

// aiuaimod.cpp
// int, long, long, long), aiuaimod.cpp:5840-5868.
// Symbol: ?addToNotifyQueue@UnitAIModule@@IAEHHHHJJJ@Z.
// Body boundary: 00419F00-0041A016; 00419ED0 is the preceding sibling.
// The protected overload owns the notify queue insertion sequence.


int UnitAIModule::addToNotifyQueue(int callerID, int recipientID, int mType,
                                   long p1, long p2, long p3) {
    if (this->notifyQueueMaxSizeValue == this->notifyQueueSizeValue) {
        NotifyEvent* newQueue =
            (NotifyEvent*)operator new(this->notifyQueueMaxSizeValue * 0x30);
        if (newQueue == 0) {
            return 0;
        }

        int i = 0;
        if (this->notifyQueueSizeValue > 0) {
            do {
                newQueue[i].caller = this->notifyQueueValue[i].caller;
                newQueue[i].recipient = this->notifyQueueValue[i].recipient;
                newQueue[i].mType = this->notifyQueueValue[i].mType;
                newQueue[i].p1 = this->notifyQueueValue[i].p1;
                newQueue[i].p2 = this->notifyQueueValue[i].p2;
                newQueue[i].p3 = this->notifyQueueValue[i].p3;
                ++i;
            } while (i < this->notifyQueueSizeValue);
        }

        if (this->notifyQueueValue != 0) {
            operator delete(this->notifyQueueValue);
        }
        this->notifyQueueValue = newQueue;
        this->notifyQueueMaxSizeValue = this->notifyQueueMaxSizeValue * 2;
    }

    this->notifyQueueValue[this->notifyQueueSizeValue].caller = callerID;
    this->notifyQueueValue[this->notifyQueueSizeValue].recipient = recipientID;
    this->notifyQueueValue[this->notifyQueueSizeValue].mType = mType;
    this->notifyQueueValue[this->notifyQueueSizeValue].p1 = p1;
    this->notifyQueueValue[this->notifyQueueSizeValue].p2 = p2;
    this->notifyQueueValue[this->notifyQueueSizeValue].p3 = p3;
    this->notifyQueueSizeValue = this->notifyQueueSizeValue + 1;
    return 1;
}

// Symbol: ?purgeNotifyQueue@UnitAIModule@@QAEXK@Z.
// Body boundary: 0041A020-0041A0C5; padding starts at 0041A0C6.
// The preceding 00419F00 helper is protected and has symbol
// ?addToNotifyQueue@UnitAIModule@@IAEHHHHJJJ@Z. Do not merge these ABIs.
// The source scans typed notify records and clears the queue after the scan.



void UnitAIModule::purgeNotifyQueue(unsigned long uTime) {
    int i = 0;
    int count = this->notifyQueueSizeValue;
    if (count > 0) {
        for (; i < count; ++i) {
            NotifyEvent* event = &this->notifyQueueValue[i];
            if (event->mType == 0x1FA) {
                int action = event->p1;
                if (action != 0x262 || this->currentActionValue == action || this->currentActionValue == 0x268) {
                    if (this->currentOrderValue == -1 && this->currentActionValue == action) {
                        this->removeCurrentTarget();
                        FILE* f = actionFile;
                        if (f != 0) {
                            int id;
                            if (this->objectValue != 0) {
                                id = this->objectValue->id;
                            } else {
                                id = -1;
                            }
                            fprintf(f, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0x170E);
                        }
                        this->stopObject(1);
                        break;
                    }
                }
            }
        }
    }
    this->notifyQueueSizeValue = 0;
    this->lastUpdateTimeValue = uTime;
}


RGE_Static_Object* UnitAIModule::lookupObject(int id) {
    if (this->objectValue && this->objectValue->owner && this->objectValue->owner->world) {
        return this->objectValue->owner->world->object(id);
    }
    return 0;
}

// at aiuaimod.cpp lines 5932-5942. Its body ends at 0041A14E; the next bytes
// are padding. Keep the preceding 0041A020 purgeNotifyQueue owner separate.
void UnitAIModule::logDebug(char* textIn, ...) {
    char textOut[1024];
    if (this->objectValue != 0) {
        // The variadic receiver uses caller cleanup. Keep the
        vsprintf(textOut, textIn, (char*)&textIn + 4);
        this->objectValue->logDebug(textOut);
    }
}
