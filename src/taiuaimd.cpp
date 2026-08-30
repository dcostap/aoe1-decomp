// Generated destructor and vtable entries are emitted by the compiler.
#include "../include/taiuaimd.h"
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "../include/game_globals.h"



TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x10;
    importantObjects = (int*)operator new(0x40);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 4;
        this->importantObjects[2] = 0x1a;
        this->importantObjects[3] = 0x18;
        this->importantObjects[4] = 6;
        this->importantObjects[5] = 0x19;
        this->importantObjects[6] = 0x11;
        this->importantObjects[7] = 0xa;
        this->importantObjects[8] = 0xc;
        this->importantObjects[9] = 0x23;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1c;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0xd;
        this->importantObjects[15] = 0x27;
    }

    idleTimeoutValue = 0xFA0;
    setAdjustedIdleTimeout();
}



int TribeHuntedAnimalUnitAIModule::processNotify(NotifyEvent* evt, unsigned long param_2)
{
    switch (evt->mType) {
    case 0x1F4:
    {
        if (evt->p2 <= 0) {
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        int caller = evt->caller;

    // Search for existing caller
    int i = 0;
    while (i < this->attackingUnitsValue.numberValue &&
           i < this->attackingUnitsValue.maximumSizeValue) {
        if (this->attackingUnitsValue.value[i] == caller)
            goto done;
        i++;
    }

    // Grow array if count >= capacity
    if (this->attackingUnitsValue.numberValue >
        this->attackingUnitsValue.maximumSizeValue - 1) {
        int new_cap = this->attackingUnitsValue.numberValue + 1;
        int* new_arr = new int[new_cap];
        if (new_arr) {
            int j;
            for (j = 0;
                 j < this->attackingUnitsValue.maximumSizeValue && j < new_cap;
                 j++)
                new_arr[j] = this->attackingUnitsValue.value[j];
            delete[] this->attackingUnitsValue.value;
            this->attackingUnitsValue.value = new_arr;
            this->attackingUnitsValue.maximumSizeValue = new_cap;
        }
    }

        // Add caller to end of list
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

        goto done;
    }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(evt, param_2);
    }

done:
    // Notify sub via vtable+0xEC
    this->objectValue->setUnderAttack(1);

    // Notify self via vtable+0xA4
    this->runAwayFromAttackers(1);

    return 3;
}



extern const float SPEED_3; // 3.0f at [5758B0h]

int TribeHuntedAnimalUnitAIModule::processIdle(int param_1)
{
    int targetID;
    RGE_Static_Object* target;
    float speed, dx, dy, distance, nx, ny;
    targetID = closestObject(
        0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0
    );

    if (targetID != -1) {
        target = objectValue->owner->world->object(targetID);
        if (target != 0) {
            speed = objectValue->maximumSpeed() * SPEED_3;
            dx = target->world_x - objectValue->world_x;
            dy = target->world_y - objectValue->world_y;
            distance = (float)sqrt(dx * dx + dy * dy);
            nx = (float)(-((dx / distance) * speed)) + objectValue->world_x;
            ny = (float)(-((dy / distance) * speed)) + objectValue->world_y;
            evasiveMoveTo(nx, ny, objectValue->world_z, 1);
            return 6;
        }
    }
    return 5;
}



TribePreditorUnitAIModule::TribePreditorUnitAIModule(
    RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x11;
    importantObjects = (int*)operator new(0x44);

    if (importantObjects) {
        importantObjects[0] = 0x1D;
        this->importantObjects[1] = 0x09;
        this->importantObjects[2] = 0x00;
        this->importantObjects[3] = 0x04;
        this->importantObjects[4] = 0x1A;
        this->importantObjects[5] = 0x18;
        this->importantObjects[6] = 0x06;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0D;
        this->importantObjects[10] = 0x0C;
        this->importantObjects[11] = 0x23;
        this->importantObjects[12] = 0x17;
        this->importantObjects[13] = 0x24;
        this->importantObjects[14] = 0x1C;
        this->importantObjects[15] = 0x12;
        this->importantObjects[16] = 0x27;
    }
}



int TribePreditorUnitAIModule::canAttackUnitAtNeutrality(int p0) { return 1; }

//


extern FILE* actionFile;  // FILE* at 0x62C4CC
extern int fprintf(void*, const char*, ...);

// String constants at fixed RVAs in .rdata
extern const char str_taiuaimd_path[];    // at 0x588AE8
extern const char str_fmt_stopObject[];   // at 0x57F964

int TribePreditorUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2) {
    if (event->mType == 0x1FC) {
        RGE_Static_Object* obj =
            this->objectValue->owner->world->object(this->currentTargetValue);

        if (obj != 0) {
            float dist = this->objectValue->distance_to_object(obj);
            if (!(dist > this->objectValue->master_obj->los)) {
                this->attackObject(this->currentTargetValue, 1);
                return 3;
            }
        }

        this->removeCurrentTarget();

        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 250);
        }

        this->stopObject(1);
        this->notifyCommander(event);
    }

    return UnitAIModule::processNotify(event, param_2);
}


TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}



int TribeElephantUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 500:
        if (event->p2 <= 0) {
            this->purgeNotifyQueue(param_2);
            return 4;
        }
        {
            int caller = event->caller;
            int count = this->attackingUnitsValue.numberValue;
            int i = 0;
            if (count > 0) {
                goto loop_check;
                do {
                    if (i >= this->attackingUnitsValue.maximumSizeValue)
                        goto after_loop;
                    if (this->attackingUnitsValue.value[i] == caller)
                        goto found;
                    i++;
loop_check:;
                } while (i < count);
after_loop:;
            }

            if (count >= this->attackingUnitsValue.maximumSizeValue) {
                int newCapacity = count + 1;
                int* newArray = (int*)operator_new(newCapacity * 4);
                if (newArray != 0) {
                    int j = 0;
                    if (count > 0) {
                        while (j < newCapacity && j < count) {
                            newArray[j] = this->attackingUnitsValue.value[j];
                            j++;
                        }
                    }
                    operator_delete(this->attackingUnitsValue.value);
                    this->attackingUnitsValue.value = newArray;
                    this->attackingUnitsValue.maximumSizeValue = newCapacity;
                }
            }
            this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
            this->attackingUnitsValue.numberValue++;
found:
            this->objectValue->setUnderAttack(1);
            int val = this->closestAttacker(0);
            this->attackObject(val, 0);
            return 3;
        }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(event, param_2);
    }
}


int TribeElephantUnitAIModule::processIdle(int p0) { return 5; }



TribeLionUnitAIModule::TribeLionUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x11;
    importantObjects = (int*)operator new(0x44);

    if (importantObjects) {
        importantObjects[0] = 0x1d;
        this->importantObjects[1] = 9;
        this->importantObjects[2] = 0;
        this->importantObjects[3] = 4;
        this->importantObjects[4] = 0x1a;
        this->importantObjects[5] = 0x18;
        this->importantObjects[6] = 6;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0xd;
        this->importantObjects[10] = 0xc;
        this->importantObjects[11] = 0x23;
        this->importantObjects[12] = 0x17;
        this->importantObjects[13] = 0x24;
        this->importantObjects[14] = 0x1c;
        this->importantObjects[15] = 0x12;
        this->importantObjects[16] = 0x27;
    }

    idleTimeoutValue = 0x1770;
    setAdjustedIdleTimeout();
}


int TribeLionUnitAIModule::canAttackUnitAtNeutrality(int p0) { return 1; }


extern FILE* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];


int TribeLionUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 0x1FC:
    {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->currentTargetValue);
        if (obj != 0) {
            float dist = this->objectValue->distance_to_object(obj);
            if (!(dist > this->objectValue->master_obj->los)) {
                this->attackObject(this->currentTargetValue, 1);
                return 3;
            }
        }

        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x1AC);
        }
        this->stopObject(1);
        this->notifyCommander(event);
    }
    break;

    case 0x1FA:
        if (event->p1 != 0x258) {
            break;
        }
        if (rge_base_game->scenarioGame() == 1) {
            if (rge_base_game->singlePlayerGame() == 1) {
                this->idleTimeoutValue =
                    (this->objectValue->owner->world->difficultyLevel() + 3) * 5000;
            } else {
                this->idleTimeoutValue = 25000;
            }
        } else {
            this->idleTimeoutValue = 25000;
        }
        this->setAdjustedIdleTimeout();
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x191);
        }
        this->stopObject(1);
        break;
    }

    return UnitAIModule::processNotify(event, param_2);
}

// TribeLionUnitAIModule::processIdle (00504600)
// __thiscall: ecx=this, 1 stack param, ret 4


int TribeLionUnitAIModule::processIdle(int param_1)
{
    idleTimeoutValue = 6000;
    setAdjustedIdleTimeout();

    int targetId = closestObject(-1, -1, -1, -1, 0);
    RGE_Static_Object* newTarget = lookupObject(targetId);

    if (targetId == -1 || newTarget == 0) {
        return 5;
    }

    int difficulty = objectValue->owner->world->difficultyLevel();

    float los;
    if (rge_base_game->scenarioGame() == 1 && rge_base_game->singlePlayerGame() == 1 && difficulty >= 3) {
        float factor = (difficulty == 3) ? 0.75f : 0.5f;
        los = factor * objectValue->master_obj->los;
        if (los < 1.0f) {
            los = 1.0f;
        }
    } else {
        los = objectValue->master_obj->los * 2.0f;
    }

    float dist = objectValue->distance_to_object(newTarget);
    if (dist > los) {
        return 5;
    }

    attackObject(targetId, 0);
    return 6;
}


TribeRangedUnitAIModule::TribeRangedUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}



typedef unsigned long ulong;


int TribeRangedUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    if (event->mType != 0x200) {
        return UnitAIModule::processNotify(event, param_2);
    }

    if (this->currentActionValue == 600) {
        RGE_Game_World* gameWorld = this->objectValue->owner->world;
        RGE_Static_Object* targetObj = gameWorld->object(this->currentTargetValue);

        if (targetObj) {
            float fVal = targetObj->getSpeed();
            if (fVal != 0.0f) {
                this->order(
                    this->objectValue->id, 0x2BC, this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue,
                    0, 1, this->currentOrderPriorityValue
                );

                RGE_Static_Object* thisObj = this->objectValue;

                // Get speed from obj's vtable[64] (+0x100) then [63] (+0xFC)
                float speed2 = thisObj->rateOfFire();
                float speed1 = thisObj->maximumSpeed();
                float speed = speed1 * speed2 * 3.0f;
                float dx = targetObj->world_x - thisObj->world_x;
                float dy = targetObj->world_y - thisObj->world_y;
                float dist = (float)sqrt(dx * dx + dy * dy);
                float nty = -(dy / dist * speed);
                float resultY = nty + thisObj->world_y;
                float ntx = -(dx / dist * speed);
                float resultX = ntx + thisObj->world_x;

                this->evasiveMoveTo(resultX, resultY, thisObj->world_z, 1);

                return 3;
            }
        }
    }
    return 2;
}


TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}


extern float DAT_005758b0;
extern float DAT_005758c4;
extern "C" double __cdecl sqrt(double);


int TribeRangedUnitAIModule2::processNotify(NotifyEvent* ev, unsigned long flags)
{
    RGE_Static_Object* target;
    float evasiveMoveDistance;
    float dx;
    float dy;
    float len;
    if (ev->mType != 0x200) {
        return UnitAIModule::processNotify(ev, flags);
    }
    target = 0;
    if (this->currentActionValue != 0x258 ||
        (target = this->objectValue->owner->world->object(this->currentTargetValue)) == 0 ||
        target->getSpeed() == DAT_005758c4)
        return 2;

    this->order(this->objectValue->id, 0x2bc, this->currentTargetValue, -1,
                this->currentTargetXValue, this->currentTargetYValue,
                this->currentTargetZValue, this->desiredTargetDistanceValue,
                0, 1, this->currentOrderPriorityValue);

    evasiveMoveDistance = this->objectValue->maximumSpeed() *
                          this->objectValue->rateOfFire() * DAT_005758b0;
    dx = target->world_x - this->objectValue->world_x;
    dy = target->world_y - this->objectValue->world_y;

    if (this->attackingUnitsValue.numberValue > 0) {
        int i = 0;
        while (i < this->attackingUnitsValue.numberValue) {
                if (i > this->attackingUnitsValue.maximumSizeValue - 1) {
                    int newCount = i + 1;
                    int* n = new int[newCount];
                    if (n) {
                        int j = 0;
                        if (this->attackingUnitsValue.maximumSizeValue > 0) {
                            do {
                                if (j < newCount) {
                                    ++j;
                                    n[j-1] = this->attackingUnitsValue.value[j-1];
                                } else {
                                    break;
                                }
                            } while (j < this->attackingUnitsValue.maximumSizeValue);
                        }
                        delete[] this->attackingUnitsValue.value;
                        this->attackingUnitsValue.value = n;
                        this->attackingUnitsValue.maximumSizeValue = newCount;
                    }
                }
                if (this->attackingUnitsValue.value[i] != this->currentTargetValue) {
                    if (i > this->attackingUnitsValue.maximumSizeValue - 1) {
                        int newCount = i + 1;
                        int* n = new int[newCount];
                        if (n) {
                            int j = 0;
                            if (this->attackingUnitsValue.maximumSizeValue > 0) {
                                do {
                                    if (j < newCount) {
                                        ++j;
                                        n[j-1] = this->attackingUnitsValue.value[j-1];
                                    } else {
                                        break;
                                    }
                                } while (j < this->attackingUnitsValue.maximumSizeValue);
                            }
                            delete[] this->attackingUnitsValue.value;
                            this->attackingUnitsValue.value = n;
                            this->attackingUnitsValue.maximumSizeValue = newCount;
                        }
                    }
                    RGE_Static_Object* obj2 = this->objectValue->owner->world->object(
                        this->attackingUnitsValue.value[i]);
                    if (obj2) {
                        dx += obj2->world_x - this->objectValue->world_x;
                        dy += obj2->world_y - this->objectValue->world_y;
                    }
                }
            ++i;
        }
    }

    len = (float)sqrt(dx*dx + dy*dy);
    this->evasiveMoveTo(this->objectValue->world_x + (-(dx / len * evasiveMoveDistance)),
                        this->objectValue->world_y + (-(dy / len * evasiveMoveDistance)),
                        this->objectValue->world_z, 1);
    return 3;
}




TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0xb;
    importantObjects = (int*)operator new(0x2c);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 7;
        this->importantObjects[2] = 8;
        this->importantObjects[3] = 9;
        this->importantObjects[4] = 0xa;
        this->importantObjects[5] = 0xf;
        this->importantObjects[6] = 0x11;
        this->importantObjects[7] = 0x12;
        this->importantObjects[8] = 0x20;
        this->importantObjects[9] = 0x21;
        this->importantObjects[10] = 0x1b;
    }
}


int TribeCivilianUnitAIModule::importantWhenDead(int value) {
    if (value == 0x7 || value == 0x9 || value == 0xA || value == 0xF || value == 0x8 || value == 0x20)
        return 1;
    return 0;
}




int TribeCivilianUnitAIModule::attackObject(int targetId, int param2) {
    RGE_Static_Object* obj = objectValue->owner->world->object(targetId);
    if (obj == 0) {
        return 0;
    }

    int group = (int)obj->master_obj->object_group;
    if (group == 9 || group == 10 || group == 15) {
        return this->huntObject(targetId, param2);
    }

    return UnitAIModule::attackObject(targetId, param2);
}

int TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (!obj) return 0;
    return obj->master_obj->object_group != 1;
}


int TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(int p0) { return 0; }


int TribeCivilianUnitAIModule::retryableOrder(int value) {
    if (value == 0x2C1 || value == 0x2C5 || value == 0x2C9)
        return 1;
    return 0;
}


int TribeCivilianUnitAIModule::convertToLOSResourceType(int value) {
    switch (value) {
    case 7:
        return 1;
    case 0x20:
        return 4;
    case 8:
        return 3;
    case 0xF:
        return 0;
    case 5:
    case 0x1F:
    case 0x21:
        return 2;
    default:
        return -1;
    }
}


typedef unsigned char uchar;
typedef unsigned long ulong;


int TribeCivilianUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType - 0x1f4) {
    case 0x1b:
        if (this->objectValue->owner->world->difficultyLevel() >= 3) {
            return 2;
        }
        // Intentional fall-through: 0x20f is the high-priority spelling of 0x1f4.
    case 0: {
        if (event->p2 <= 0) {
            this->objectValue->owner->notify(
                this->objectValue->id, this->objectValue->id, 0x209,
                event->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        RGE_Static_Object* eventObject = this->lookupObject(event->caller);
        RGE_Static_Object* targetObject = this->lookupObject(this->currentTargetValue);
        if (eventObject == 0) {
            return 2;
        }

        if (this->objectValue->owner->computerPlayer() == 1) {
            if (eventObject->owner->id != 0 || eventObject->id != this->currentTargetValue) {
                this->objectValue->owner->notify(
                    this->objectValue->id, this->objectValue->id, 0x201,
                    event->caller, 0, 0);
            }
        } else if (this->attackingUnitsValue.numberValue == 0) {
            this->objectValue->owner->notify(
                this->objectValue->id, this->objectValue->id, 0x201,
                event->caller, 0, 0);
        }

        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == event->caller) {
                goto found_attacker;
            }
        }

        if (this->objectValue->owner->computerPlayer() == 0 &&
            this->currentTargetValue != event->caller) {
            this->askForHelp(event->caller);
        }

found_attacker:
        i = 0;
        int caller = event->caller;
        count = this->attackingUnitsValue.numberValue;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == caller) {
                goto already_attacking;
            }
        }

        if (this->attackingUnitsValue.numberValue >
            this->attackingUnitsValue.maximumSizeValue - 1) {
            int newMaximum = this->attackingUnitsValue.numberValue + 1;
            int* newValue = (int*)operator new(newMaximum * 4);
            if (newValue != 0) {
                i = 0;
                if (this->attackingUnitsValue.maximumSizeValue > 0) {
                    do {
                        if (i >= newMaximum) {
                            break;
                        }
                        ++i;
                        newValue[i - 1] = this->attackingUnitsValue.value[i - 1];
                    } while (i < this->attackingUnitsValue.maximumSizeValue);
                }
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = newValue;
                this->attackingUnitsValue.maximumSizeValue = newMaximum;
            }
        }
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        ++this->attackingUnitsValue.numberValue;

already_attacking:
        this->objectValue->setUnderAttack(1);
        float speed = this->objectValue->getSpeed();
        int state = this->objectValue->actionState();

        if (this->currentOrderValue == 0x2c6 && speed > 0.0f) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2bc) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2c9 && state == 0x0c &&
            targetObject != 0 && targetObject->master_obj->object_group == 10 &&
            eventObject->owner->id == 0) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2ce) {
            goto return_two;
        }

        if (eventObject->owner->id == 0) {
            if (this->currentOrderValue != -1) {
                this->order(this->objectValue->id, this->currentOrderValue,
                            this->currentTargetValue, -1,
                            this->currentTargetXValue, this->currentTargetYValue,
                            this->currentTargetZValue,
                            this->desiredTargetDistanceValue, 0, 0,
                            this->currentOrderPriorityValue);
                this->currentOrderValue = 0x2bc;
                this->currentOrderPriorityValue = 100;
                this->attackObject(event->caller, 1);
                this->stopAfterTargetKilledValue = 1;
                return 3;
            }
            this->attackObject(event->caller, 1);
            return 3;
        }

        if (this->currentActionValue == 0x262 && speed != 0.0f) {
            return 3;
        }
        this->order(this->objectValue->id, this->currentOrderValue,
                    this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue,
                    this->desiredTargetDistanceValue,
                    0, 0,
                    this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x39a);
        }
        this->stopObject(1);
        this->runAwayFromAttackers(1);
        return 3;
    }

    case 6:
        if (this->currentActionValue == event->p1) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id;
                if (this->objectValue != 0) {
                    id = this->objectValue->id;
                } else {
                    id = -1;
                }
                fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                        "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x3aa);
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        break;

    case 5:
        if (this->currentActionValue == event->p1) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id;
                if (this->objectValue != 0) {
                    id = this->objectValue->id;
                } else {
                    id = -1;
                }
                fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                        "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x3b9);
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        break;

    case 7:
    case 0xe:
        if (this->currentActionValue == 0x265) {
            int type = this->currentTargetTypeValue;
            if (type == -1) {
                type = this->lastTargetTypeValue;
            }
            if (type == -1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x3d3);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }

            int objectType = this->convertToLOSResourceType(type);
            int result;
            if (objectType == -1) {
                result = this->closestObject(type, -1, -1, -1, 0);
            } else {
                result = this->closestResourceObject(objectType, 0);
            }
            if (result != -1) {
                if (this->huntObject(result, 1) == 1) {
                    return 3;
                }
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x3f6);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            } else if (this->objectValue->owner->computerPlayer() == 1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x40f);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            }
        } else if (this->currentActionValue == 0x261) {
            int type = this->currentTargetTypeValue;
            if (type == -1) {
                type = this->lastTargetTypeValue;
            }
            if (type == -1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x421);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
            int objectType = this->convertToLOSResourceType(type);
            int result;
            if (objectType != -1) {
                result = this->closestResourceObject(objectType, 0);
            } else {
                int arg3 = 2;
                int arg4 = 0x32;
                if (event->p2 != 0x32) {
                    arg3 = -1;
                    arg4 = -1;
                }
                result = this->closestObject(type, -1, arg3, arg4, 0);
            }
            if (result != -1) {
                if (this->gatherObject(result, 1) == 1) {
                    return 3;
                }
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x446);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            } else if (this->objectValue->owner->computerPlayer() == 1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x453);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            } else if (event->p2 == 0x32) {
                float x;
                float y;
                if (this->objectValue->world_x <= 5.0f) {
                    x = this->objectValue->world_x - (-2.5f);
                } else {
                    x = this->objectValue->world_x - 2.5f;
                }
                if (this->objectValue->world_y <= 5.0f) {
                    y = this->objectValue->world_y - (-2.5f);
                } else {
                    y = this->objectValue->world_y - 2.5f;
                }
                this->evasiveMoveTo(x, y, this->objectValue->world_z, 1);
            }
        } else if (this->currentActionValue == 0x25a) {
            int result = this->closestObject(this->currentTargetTypeValue, 3, 0, -1, 0);
            if (result == -1) {
                int type = this->currentTargetTypeValue;
                if (type == 0x1b) {
                    type = 3;
                } else {
                    type = 0x1b;
                }
                result = this->closestObject(type, 3, 0, -1, 0);
            }
            if (result != -1 &&
                this->objectValue->canPath(result, 1.0f, 0, 0, -1, -1) == 1 &&
                this->buildObject(result, 1) == 1) {
                return 3;
            }
            RGE_Static_Object* object = this->lookupObject(this->currentTargetValue);
            if (object == 0 || this->objectValue->distance_to_object(object) > 1.0f) {
                this->moveTo(this->currentTargetXValue, this->currentTargetYValue,
                             this->currentTargetZValue, 1.0f, 1);
            }
        } else if (this->currentActionValue == 0x25d) {
            int tileX;
            int tileY;
            if (this->closestUndiscoveredTile(&tileX, &tileY, 1) == 1) {
                this->addToWaypointQueue(tileX, tileY);
                if (this->explore(tileX, tileY, 1) != 0) {
                    return 3;
                }
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x4b4);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            } else {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x4c3);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            }
        }

        if (event->mType == 0x202) {
            return 2;
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x4cc);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        break;

    default:
        return UnitAIModule::processNotify(event, param_2);
    }

return_two:
    return 2;
}


int TribeCivilianUnitAIModule::processIdle(int p0) { return 5; }


int TribeCivilianUnitAIModule::processMisc() { return 9; }



TribePriestUnitAIModule::TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2)
{
    this->numberImportantObjects = 0x11;
    this->importantObjects = (int*)operator new(0x44);

    if (this->importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0;
        this->importantObjects[2] = 4;
        this->importantObjects[3] = 0x1A;
        this->importantObjects[4] = 0x18;
        this->importantObjects[5] = 6;
        this->importantObjects[6] = 0x19;
        this->importantObjects[7] = 0x11;
        this->importantObjects[8] = 0x0A;
        this->importantObjects[9] = 0x0C;
        this->importantObjects[10] = 0x23;
        this->importantObjects[11] = 0x17;
        this->importantObjects[12] = 0x24;
        this->importantObjects[13] = 0x1C;
        this->importantObjects[14] = 0x12;
        this->importantObjects[15] = 0x0D;
        this->importantObjects[16] = 0x27;
    }
}



int TribePriestUnitAIModule::attackObject(int param_1, int param_2) {
    if (this->canConvert(param_1) == 0) {
        if (this->currentOrderValue == -1) {
            if (this->objectValue->owner->computerPlayer() != 0) {
                return this->moveTo(param_1, this->objectValue->weaponRange(), param_2);
            }
        }
        return 0;
    }
    return this->convertObject(param_1, param_2);
}


int TribePriestUnitAIModule::retryableOrder(int value) {
    if (value == 0x2C0 || value == 0x2BF)
        return 1;
    return 0;
}


int TribePriestUnitAIModule::canConvert(int id) {
    if (this->objectValue->attribute_amount_held >= 100.0f) {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(id);
        if (obj) {
            int og = obj->master_obj->object_group;
            short sid = obj->master_obj->id;

            if (sid == 0x6D) return 0;
            if (og == 0x1B) return 0;
            if (sid == 0x9F) return 0;
            if (sid == 0x114) return 0;
            if (sid == 0x9E) return 0;
            if (sid == 0xA3) return 0;
            if (og == 0x1E) return 0;

            if (og == 0x12 && this->objectValue->owner->attributes[0x1B] <= 0.0f) return 0;
            if (og == 3 && this->objectValue->owner->attributes[0x1C] <= 0.0f) return 0;

            return 1;
        }
    }
    return 0;
}


int TribePriestUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (obj != 0) {
        return canConvert(obj->id);
    }
    return 0;
}



int TribePriestUnitAIModule::bestUnitToHeal(int param_1, float* param_2)
{
    this->search();

    int allyToHealID = -1;
    float allyNeed = 0.0f;
    int maxLimit = 2;
    int a;
    int i;
    if (this->objectValue->owner->id == 0) {
        maxLimit = 4;
    }

    a = 1;
    while (a <= maxLimit) {
        i = 0;
        if (VisibleUnitList_Size[a - 1] > 0) {
            VISIBLE_UNIT_REC** listPtr = &VisibleUnitList[a - 1];
            do {
                if ((*listPtr)[i].object_id != this->objectValue->id) {
                    RGE_Static_Object* unit =
                        this->lookupObject((*listPtr)[i].object_id);
                    if (unit != 0) {
                        if (unit->master_obj->object_group != 3) {
                            if ((float)(int)unit->master_obj->hp > unit->hp) {
                                if (unit->object_state < 3) {
                                    if (param_1 != 0 ||
                                        (*listPtr)[i].distance <= 4) {
                                        if (this->objectValue->owner->id != 0 ||
                                            (*listPtr)[i].distance <= 2) {
                                            if (this->objectValue->canPath(
                                                    (*listPtr)[i].object_id,
                                                    1.0f, 0, 0, -1, -1)) {
                                                float need = (float)(int)unit->master_obj->hp -
                                                    unit->hp / (float)(int)(*listPtr)[i].distance;
                                                if (allyToHealID == -1 || need < allyNeed) {
                                                    allyNeed = need;
                                                    allyToHealID = unit->id;
                                                    if (param_2 != 0) {
                                                        *param_2 = (float)(int)(*listPtr)[i].distance;
                                                    }
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
            } while (i < VisibleUnitList_Size[a - 1]);
        }
        if (allyToHealID != -1) {
            return allyToHealID;
        }
        ++a;
    }

    return -1;
}



typedef unsigned char uchar;


int TribePriestUnitAIModule::bestUnitToConvert(float* param_1)
{
    this->search();

    int best_id = -1;
    float targetValue = 0.0f;
    int i = 0;

    if (VisibleUnitList_Size[3] > 0) {
        do {
            if (this->objectValue->owner->isEnemy(
                    (int)VisibleUnitList[3][i].player) != 0) {
                RGE_Static_Object* found = this->lookupObject(
                    VisibleUnitList[3][i].object_id);

                if (found != 0 && found->object_state < 3) {
                    if (this->canConvert(found->id) != 0) {
                        float priority =
                            (float)VisibleUnitList[3][i].distance;
                        if (priority < 1.0f)
                            priority = 1.0f;

                        short hp_short = found->master_obj->hp;
                        float hp_float = (float)hp_short;
                        float score = hp_float / priority;

                        if (best_id == -1 || score > targetValue) {
                            best_id = found->id;
                            targetValue = score;
                            if (param_1 != 0)
                                *param_1 = priority;
                        }
                    }
                }
            }

            i++;
        } while (i < VisibleUnitList_Size[3]);
    }

    return best_id;
}


extern FILE* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];


int TribePriestUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 0x1f9:
    case 0x1fb:
    case 0x202:
        if (this->objectValue->owner->computerPlayer() == 0 && this->currentActionValue == 0x25c) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x63b);
            }
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (this->currentActionValue == 0x25c) {
            int id = this->bestUnitToConvert(0);
            if (id != -1 && this->convertObject(id, 1) == 1) {
                return 3;
            }
        } else if (this->currentActionValue == 0x25b) {
            int id = this->bestUnitToHeal(0, 0);
            if (id != -1 && this->healObject(id, 1) == 1) {
                return 3;
            }
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x675);
            }
        this->stopObject(0);
        this->notifyCommander(event);
        return 2;

    case 0x1fc:
    {
        RGE_Static_Object* obj = this->lookupObject(this->currentTargetValue);
        if (obj != 0) {
            if (this->visibleStatus(this->objectValue->owner->visible,
                                    (int)obj->world_x, (int)obj->world_y) == 0x0f) {
                return 2;
            }
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x68f);
            }
        this->stopObject(1);
        this->notifyCommander(event);
        break;
    }
    }

    return UnitAIModule::processNotify(event, param_2);
}



#pragma intrinsic(sqrt)

extern int __cdecl debug_rand(const char* file, int line);


int TribePriestUnitAIModule::processIdle(int param_1)
{
    if (this->objectValue->owner->computerPlayer()) {
        if (UnitAIModule::processIdle(1) == 6) {
            return 6;
        }

    int range = VisibleUnitList_Size[3];
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x6AC) % (range + 2);
    if (range > 0 && r > range) {
        float local_4;
        int action = this->bestUnitToHeal(1, &local_4);
        if (action != -1) {
            this->healObject(action, 0);
            return 6;
        }
    }

    int targetId = this->closestObject(-1, 2, -1, -1, 0);
    if (targetId == -1) {
        return 5;
    }

    RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
    if (target == 0) {
        return 5;
    }

    float xDiff = target->world_x - this->objectValue->world_x;
    float yDiff = target->world_y - this->objectValue->world_y;
    float dist = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
    float distanceDiff = this->objectValue->weaponRange() - dist;

    if (distanceDiff <= DAT_005758c4) {
        return 5;
    }

    float nx = (float)(-((xDiff / dist) * distanceDiff)) +
               this->objectValue->world_x;
    float ny = (float)(-((yDiff / dist) * distanceDiff)) +
               this->objectValue->world_y;
    this->evasiveMoveTo(nx, ny, this->objectValue->world_z, 1);
    return 6;
    }

    return 5;
}

//



extern FILE* actionFile;

int TribePriestUnitAIModule::processMisc()
{
    if (this->objectValue->owner->computerPlayer() == 1) {
        RGE_Action_Object* object = (RGE_Action_Object*)this->objectValue;

        if (object->attribute_amount_held >= 100.0f) {
            if (object->actions->have_action() != 1 ||
                object->actions->get_action()->state != 7) {
                int target = this->bestUnitToAttack(1, 1, 0);

                if (target != -1 && this->currentTargetValue != target) {
                    if (this->currentOrderValue != -1) {
                        this->order(
                            this->objectValue->id,
                            this->currentOrderValue,
                            this->currentTargetValue,
                            -1,
                            this->currentTargetXValue,
                            this->currentTargetYValue,
                            this->currentTargetZValue,
                            this->desiredTargetDistanceValue,
                            0,
                            0,
                            this->currentOrderPriorityValue);

                        if (actionFile != 0) {
                            int objectID;
                            if (this->objectValue != 0) {
                                objectID = this->objectValue->id;
                            } else {
                                objectID = -1;
                            }
                            fprintf(actionFile,
                                "#%d call stopObject %s %d\n",
                                objectID,
                                "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp",
                                0x6F8);
                        }

                        this->stopObject(1);
                    }

                    if (this->attackObject(target, 1) == 1) {
                        return 10;
                    }
                }
            }
        }
    }

    return 9;
}




TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 5;
    importantObjects = (int*)operator new(0x14);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0x16;
        this->importantObjects[2] = 0x14;
        this->importantObjects[3] = 2;
        this->importantObjects[4] = 0x15;
    }
}




int TribeTradeShipUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType) {
    case 0x1f4:
    case 0x20f:
        break;

    case 0x202:
        if (this->currentActionValue == 0x267) {
            int id = this->closestObject(-1, 0, 2, 0x2d, 0);
            if (id != -1 && this->tradeWithObject(id, 1) == 1) {
                return 6;
            }

            id = this->closestObject(-1, 1, 2, 0x2d, 0);
            if (id != -1 && this->tradeWithObject(id, 1) == 1) {
                return 6;
            }
        } else if (this->currentActionValue == 0x25d) {
            int x;
            int y;
            if (this->closestUndiscoveredTile(&x, &y, 1) == 1) {
                this->addToWaypointQueue(x, y);
                if (this->explore(x, y, 1) == 0) {
                    this->removeCurrentTarget();
                    if (actionFile != 0) {
                        int id;
                        if (this->objectValue != 0) {
                            id = this->objectValue->id;
                        } else {
                            id = -1;
                        }
                        fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                                "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x79c);
                    }
                    this->stopObject(1);
                    this->notifyCommander(event);
                }
            } else {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x7a8);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            }
        }

        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x7b0);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;

    default:
        return UnitAIModule::processNotify(event, param_2);
    }

    if (event->p2 <= 0) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x209, event->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x201, event->caller, 0, 0);
    }

    int count = this->attackingUnitsValue.numberValue;
    int i = 0;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == event->caller) {
            goto skip_help;
        }
    }
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentTargetValue != event->caller) {
        this->askForHelp(event->caller);
    }

skip_help:
    i = 0;
    int caller = event->caller;
    count = this->attackingUnitsValue.numberValue;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == caller) {
            goto after_add;
        }
    }

    if (this->attackingUnitsValue.numberValue >
        this->attackingUnitsValue.maximumSizeValue - 1) {
        int newMax = this->attackingUnitsValue.numberValue + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            for (i = 0; i < this->attackingUnitsValue.maximumSizeValue && i < newMax; ++i) {
                newList[i] = this->attackingUnitsValue.value[i];
            }
            operator delete(this->attackingUnitsValue.value);
            this->attackingUnitsValue.value = newList;
            this->attackingUnitsValue.maximumSizeValue = newMax;
        }
    }
    this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
    this->attackingUnitsValue.numberValue++;

after_add:
    this->objectValue->setUnderAttack(1);
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentOrderValue != -1) {
        return 2;
    }
    if (this->currentActionValue != 0x262) {
        this->order(this->objectValue->id, this->currentOrderValue,
                    this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue,
                    0, 0, this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x761);
        }
        this->stopObject(1);
    }
    this->runAwayFromAttackers(1);
    return 3;
}




int TribeTradeShipUnitAIModule::processIdle(int param_1)
{
    if (this->objectValue->owner->computerPlayer()) {
        int targetId = this->closestObject(-1, -1, -1, -1, 0);
        if (targetId != -1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            if (target != 0) {
                float speed = this->objectValue->maximumSpeed() * 7.0f;
                float xDiff = target->world_x - this->objectValue->world_x;
                float yDiff = target->world_y - this->objectValue->world_y;
                float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                this->evasiveMoveTo(
                    (float)(-(xDiff / distance * speed)) + this->objectValue->world_x,
                    (float)(-(yDiff / distance * speed)) + this->objectValue->world_y,
                    this->objectValue->world_z, 1);
                return 6;
            }
        }
    }

    return 5;
}




TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 5;
    importantObjects = (int*)operator new(0x14);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0x16;
        this->importantObjects[2] = 0x14;
        this->importantObjects[3] = 2;
        this->importantObjects[4] = 0x15;
    }
}



int TribeTransportShipUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType) {
    case 0x1f4:
    case 0x20f:
        break;
    default:
        return UnitAIModule::processNotify(event, param_2);
    }

    if (event->p2 <= 0) {
        RGE_Static_Object* o = this->objectValue;
        o->owner->notify(o->id, o->id, 0x209, event->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    if (this->attackingUnitsValue.numberValue == 0 ||
        this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* o = this->objectValue;
        o->owner->notify(o->id, o->id, 0x201, event->caller, 0, 0);
    }

    int count = this->attackingUnitsValue.numberValue;
    int i = 0;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == event->caller) goto found_for_help;
    }
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentTargetValue != event->caller) {
        this->askForHelp(event->caller);
    }

found_for_help:
    i = 0;
    int caller = event->caller;
    count = this->attackingUnitsValue.numberValue;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == caller) goto already_in_list;
    }

    if (this->attackingUnitsValue.numberValue >
        this->attackingUnitsValue.maximumSizeValue - 1) {
        int newMax = this->attackingUnitsValue.numberValue + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            for (i = 0; i < this->attackingUnitsValue.maximumSizeValue && i < newMax; ++i)
                newList[i] = this->attackingUnitsValue.value[i];
            operator delete(this->attackingUnitsValue.value);
            this->attackingUnitsValue.value = newList;
            this->attackingUnitsValue.maximumSizeValue = newMax;
        }
    }
    this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
    this->attackingUnitsValue.numberValue++;

already_in_list:
    this->objectValue->setUnderAttack(1);
    if (this->currentOrderValue != -1) {
        return 2;
    }

    RGE_Action_Object* obj2 = (RGE_Action_Object*)this->objectValue;
    if (!obj2->actions->have_action() || obj2->actions->get_action()->state == 2) {
        this->runAwayFromAttackers(1);
    }
    return 3;
}




int TribeTransportShipUnitAIModule::processIdle(int param_1)
{
    if (this->objectValue->owner->computerPlayer()) {
        int targetId = closestObject(-1, -1, -1, -1, 0);

        if (targetId != -1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);

            if (target != 0) {
                float speed = this->objectValue->maximumSpeed() * 7.0f;

                float dx = target->world_x - this->objectValue->world_x;
                float dy = target->world_y - this->objectValue->world_y;
                float dist = (float)sqrt(dx * dx + dy * dy);

                float move_x = (float)(-((dx / dist) * speed)) + this->objectValue->world_x;
                float move_y = (float)(-((dy / dist) * speed)) + this->objectValue->world_y;

                evasiveMoveTo(move_x, move_y, this->objectValue->world_z, 1);

                return 6;
            }
        }
    }

    return 5;
}




TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(
    RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 8;
    importantObjects = (int*)operator new(0x20);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0x16;
        this->importantObjects[2] = 0x14;
        this->importantObjects[3] = 2;
        this->importantObjects[4] = 0x15;
        this->importantObjects[5] = 5;
        this->importantObjects[6] = 0x1F;
        this->importantObjects[7] = 0x21;
    }
}


int TribeFishingShipUnitAIModule::importantWhenDead(int value) {
    if (value != 0x1F && value != 5) {
        return 0;
    }
    return 1;
}


int TribeFishingShipUnitAIModule::convertToLOSResourceType(int value) {
    if (value == 0x1F || value == 0x5 || value == 0x21)
        return 2;
    return -1;
}




int TribeFishingShipUnitAIModule::processNotify(NotifyEvent* ev, ulong flags)
{
    switch (ev->mType) {
    case 0x1f4:
    case 0x20f:
        break;
    default:
        return UnitAIModule::processNotify(ev, flags);
    }

    if (ev->p2 <= 0) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x209, ev->caller, 0, 0);
        this->purgeNotifyQueue(flags);
        return 4;
    }

    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x201, ev->caller, 0, 0);
    }

    int count = this->attackingUnitsValue.numberValue;
    int i = 0;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == ev->caller) goto skip_help;
    }
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentTargetValue != ev->caller) {
        this->askForHelp(ev->caller);
    }

skip_help:
    i = 0;
    int caller = ev->caller;
    count = this->attackingUnitsValue.numberValue;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == caller) goto after_add;
    }

    if (this->attackingUnitsValue.numberValue >
        this->attackingUnitsValue.maximumSizeValue - 1) {
        int newMax = this->attackingUnitsValue.numberValue + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            for (i = 0; i < this->attackingUnitsValue.maximumSizeValue && i < newMax; ++i)
                newList[i] = this->attackingUnitsValue.value[i];
            operator delete(this->attackingUnitsValue.value);
            this->attackingUnitsValue.value = newList;
            this->attackingUnitsValue.maximumSizeValue = newMax;
        }
    }
    this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
    this->attackingUnitsValue.numberValue++;

after_add:
    this->objectValue->setUnderAttack(1);
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentOrderValue != -1) {
        return 2;
    }
    if (this->currentActionValue != 0x262) {
        this->order(this->objectValue->id, this->currentOrderValue,
                    this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue,
                    0, 0, this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0)
                id = this->objectValue->id;
            else
                id = -1;
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x8d4);
        }
        this->stopObject(1);
    }
    this->runAwayFromAttackers(1);
    return 3;
}



extern float DAT_005758d8; // 7.0f


int TribeFishingShipUnitAIModule::processIdle(int param_1)
{
    if (objectValue->owner->computerPlayer()) {
        int targetID = closestObject(-1, -1, -1, -1, 0);

        if (targetID != -1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetID);

            if (target != 0) {
                float speed = objectValue->maximumSpeed() * DAT_005758d8;
                float xDiff = target->world_x - objectValue->world_x;
                float yDiff = target->world_y - objectValue->world_y;
                float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                evasiveMoveTo((0.0f - ((xDiff / distance) * speed)) + objectValue->world_x,
                              (0.0f - ((yDiff / distance) * speed)) + objectValue->world_y,
                              objectValue->world_z, 1);
                return 6;
            }
        }
    }

    return 5;
}



TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x15;
    importantObjects = (int*)operator new(0x54);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 3;
        this->importantObjects[2] = 4;
        this->importantObjects[3] = 0x1A;
        this->importantObjects[4] = 0x18;
        this->importantObjects[5] = 6;
        this->importantObjects[6] = 0x23;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0C;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1C;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0x0D;
        this->importantObjects[15] = 0x1B;
        this->importantObjects[16] = 0x16;
        this->importantObjects[17] = 0x14;
        this->importantObjects[18] = 2;
        this->importantObjects[19] = 0x15;
        this->importantObjects[20] = 0x27;
    }

    idleTimeoutValue = 0x5DC;
    setAdjustedIdleTimeout();
}



int TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (!obj) return 0;
    return obj->master_obj->object_group != 1;
}



int TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int value) {
    if (value == 0x3 || value == 0x1B || value == 0x4 || value == 0x15 || value == 0x2 || value == 0x14)
        return 0;
    return 1;
}



extern float DAT_005758bc;
extern float DAT_005758c0;
extern float DAT_005758dc;
extern float DAT_005758e0;
extern float DAT_005758e4;

int TribeSoldierUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2)
{
    NotifyEvent* event = param_1;
    float evasiveMoveDistance;
    float fStack_8;
    RGE_Static_Object* target;
    float distanceLeft;
    float xDiff;
    float yDiff;
    float distance;
    int i;

    switch (event->mType) {
    case 0x20F: {
        if (this->objectValue->owner->computerPlayer() == 0)
            break;

        RGE_Static_Object* attacker =
            this->objectValue->owner->world->object(event->caller);
        if (attacker == 0)
            break;
        short group = attacker->master_obj->id;
        if (group != 0x23 && group != 0x24)
            break;
        if (this->currentActionValue == -1)
            break;

        if (this->currentOrderValue != -1) {
            this->order(
                this->objectValue->id, this->currentOrderValue,
                this->currentTargetValue, -1,
                this->currentTargetXValue, this->currentTargetYValue,
                this->currentTargetZValue, this->desiredTargetDistanceValue,
                0, 0, this->currentOrderPriorityValue);
        }

        evasiveMoveDistance =
            (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x97c) % 8) +
            (this->objectValue->world_x - DAT_005758dc);
        if (evasiveMoveDistance == this->objectValue->world_x) {
            if (evasiveMoveDistance > DAT_005758e0)
                evasiveMoveDistance -= DAT_005758c0;
            else
                evasiveMoveDistance -= DAT_005758e4;
        }

        fStack_8 =
            (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x983) % 8) +
            (this->objectValue->world_y - DAT_005758dc);
        if (fStack_8 == this->objectValue->world_y) {
            if (fStack_8 > DAT_005758e0)
                fStack_8 -= DAT_005758c0;
            else
                fStack_8 -= DAT_005758e4;
        }

        if (this->intelligentEvasiveMoveTo(
                evasiveMoveDistance, fStack_8,
                this->objectValue->world_z, 1, 1) != 1)
            break;
        taskedThisUpdate = 1;
        return 3;
    }

    case 0x200: {
        if (this->objectValue->owner->computerPlayer() != 0 &&
            this->objectValue->weaponRange() >= DAT_005758bc &&
            this->objectValue->master_obj->object_group != 0x1A) {
            if (this->currentActionValue == 600) {

            target =
                this->objectValue->owner->world->object(this->currentTargetValue);
            if (target != 0) {

                distanceLeft = this->objectValue->weaponRange() -
                    this->objectValue->distance_to_object(target);
                if (distanceLeft >= DAT_005758bc) {

                    xDiff = target->world_x - this->objectValue->world_x;
                    yDiff = target->world_y - this->objectValue->world_y;

                    this->order(
                        this->objectValue->id, 700, this->currentTargetValue, -1,
                        this->currentTargetXValue, this->currentTargetYValue,
                        this->currentTargetZValue, this->desiredTargetDistanceValue,
                        0, 1, this->currentOrderPriorityValue);

                    if (this->attackingUnitsValue.numberValue > 0) {
            i = 0;
            while (i < this->attackingUnitsValue.numberValue) {
                if (i > this->attackingUnitsValue.maximumSizeValue - 1) {
                    int newCount = i + 1;
                    int* newValues = new int[newCount];
                    if (newValues != 0) {
                        int j = 0;
                        if (this->attackingUnitsValue.maximumSizeValue > 0) {
                            do {
                                if (j < newCount) {
                                    ++j;
                                    newValues[j - 1] = this->attackingUnitsValue.value[j - 1];
                                } else {
                                    break;
                                }
                            } while (j < this->attackingUnitsValue.maximumSizeValue);
                        }
                        delete[] this->attackingUnitsValue.value;
                        this->attackingUnitsValue.value = newValues;
                        this->attackingUnitsValue.maximumSizeValue = newCount;
                    }
                }
                if (this->attackingUnitsValue.value[i] != this->currentTargetValue) {
                    if (i > this->attackingUnitsValue.maximumSizeValue - 1) {
                        int newCount = i + 1;
                        int* newValues = new int[newCount];
                        if (newValues != 0) {
                            int j = 0;
                            if (this->attackingUnitsValue.maximumSizeValue > 0) {
                                do {
                                    if (j < newCount) {
                                        ++j;
                                        newValues[j - 1] = this->attackingUnitsValue.value[j - 1];
                                    } else {
                                        break;
                                    }
                                } while (j < this->attackingUnitsValue.maximumSizeValue);
                            }
                            delete[] this->attackingUnitsValue.value;
                            this->attackingUnitsValue.value = newValues;
                            this->attackingUnitsValue.maximumSizeValue = newCount;
                        }
                    }
                    RGE_Static_Object* object =
                        this->objectValue->owner->world->object(
                            this->attackingUnitsValue.value[i]);
                    if (object != 0) {
                        xDiff += object->world_x - this->objectValue->world_x;
                        yDiff += object->world_y - this->objectValue->world_y;
                    }
                }
                ++i;
            }
                    }

                    distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
                    if (this->intelligentEvasiveMoveTo(
                                        (float)(-((xDiff / distance) * distanceLeft)) +
                                this->objectValue->world_x,
                                        (float)(-((yDiff / distance) * distanceLeft)) +
                            this->objectValue->world_y,
                        this->objectValue->world_z, 0, 1) != 1)
                        goto return_two;
                    return 3;
                }
            }
        } else {
            goto return_two;
        }
        goto return_base;
    }
    }

    default:
        goto return_base;
    }

return_base:
    return UnitAIModule::processNotify(event, param_2);
return_two:
    return 2;
}



extern const float SPEED_3; // 3.0f at [5758B0h]


int TribeSoldierUnitAIModule::processIdle(int param_1)
{
    if (param_1 == 1 && this->processRetryableOrder() == 8) {
        return 6;
    }

    if (this->objectValue->owner->id != 0 &&
        (this->objectValue->owner->computerPlayer() != 0 ||
         this->objectValue->master_obj->id != 0x12B)) {
        if (this->currentOrderValue != 0x2D5 ||
            (this->objectValue->master_obj->id != 0x23 &&
             this->objectValue->master_obj->id != 0x24 &&
             this->objectValue->master_obj->id != 0xFA)) {
            int targetID = this->bestUnitToAttack(1, 0, 0);
            if (targetID != -1 && this->attackObject(targetID, 1) == 1) {
                return 6;
            }

            if (this->objectValue->owner->computerPlayer() != 0 &&
                this->objectValue->inGroup() != 1) {
                this->objectValue->owner->world->difficultyLevel();

                if ((rge_base_game->scenarioGame() == 1 &&
                     rge_base_game->singlePlayerGame() == 1 &&
                     this->objectValue->owner->strategicNumber(0x8F) == 0) ||
                    (rge_base_game->singlePlayerGame() == 1 &&
                     this->objectValue->owner->strategicNumber(0x8F) == 0)) {
                    return 5;
                }

                if (this->currentOrderValue != 0x2BD &&
                    this->currentOrderValue != 0x2D5) {
                    int targetID2 = this->closestObject(-1, -1, -1, -1, 0);
                    if (targetID2 != -1) {
                        RGE_Static_Object* target =
                            this->objectValue->owner->world->object(targetID2);
                        if (target != 0) {
                            float speed =
                                this->objectValue->maximumSpeed() * SPEED_3;
                            float xDiff = target->world_x - this->objectValue->world_x;
                            float yDiff = target->world_y - this->objectValue->world_y;
                            float distance =
                                sqrt(xDiff * xDiff + yDiff * yDiff);
                            float x =
                                (float)(-((xDiff / distance) * speed)) +
                                this->objectValue->world_x;
                            float y =
                                (float)(-((yDiff / distance) * speed)) +
                                this->objectValue->world_y;
                            this->evasiveMoveTo(
                                x, y, this->objectValue->world_z, 1);
                            return 6;
                        }
                    }
                }
            }
        }
    }

    return 5;
}



TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(
    RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x13;
    importantObjects = (int*)operator new(0x4C);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 4;
        this->importantObjects[2] = 0x1A;
        this->importantObjects[3] = 0x18;
        this->importantObjects[4] = 6;
        this->importantObjects[5] = 0x23;
        this->importantObjects[6] = 0x19;
        this->importantObjects[7] = 0x11;
        this->importantObjects[8] = 0x0C;
        this->importantObjects[9] = 0x17;
        this->importantObjects[10] = 0x24;
        this->importantObjects[11] = 0x1C;
        this->importantObjects[12] = 0x12;
        this->importantObjects[13] = 0x0D;
        this->importantObjects[14] = 0x16;
        this->importantObjects[15] = 0x14;
        this->importantObjects[16] = 2;
        this->importantObjects[17] = 0x15;
        this->importantObjects[18] = 0x27;
    }

    idleTimeoutValue = 0x1388;
    setAdjustedIdleTimeout();
}


extern FILE* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];
int TribeArtifactUnitAIModule::processNotify(NotifyEvent* event, unsigned long flags)
{

    switch (event->mType) {
    case 0x1fc: {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->currentTargetValue);
        if (obj != 0) {
            if (this->objectValue->owner->visible->get_visible(
                    (int)obj->world_x, (int)obj->world_y) == 0x0f)
                return 2;
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                    0xa9f);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;
    }

    case 0x1fa:
        if (this->currentOrderValue != -1) {
            if (this->currentActionValue + 0x64 == this->currentOrderValue) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int objId;
                    if (this->objectValue != 0)
                        objId = this->objectValue->id;
                    else
                        objId = -1;
                    fprintf(actionFile, str_fmt_stopObject, objId,
                            str_taiuaimd_path, 0xaae);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        if (this->currentOrderValue != -1) return 2;
        if (this->currentActionValue != event->p1) return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                    0xab7);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;

    case 0x1f9:
        if (this->currentOrderValue != -1) {
            if (this->currentActionValue + 0x64 == this->currentOrderValue) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int objId;
                    if (this->objectValue != 0)
                        objId = this->objectValue->id;
                    else
                        objId = -1;
                    fprintf(actionFile, str_fmt_stopObject, objId,
                            str_taiuaimd_path, 0xac6);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        if (this->currentOrderValue != -1) return 2;
        if (this->currentActionValue != event->p1) return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                    0xacf);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;

    case 0x1fb:
        if (this->currentOrderValue != -1) {
            if (this->currentActionValue + 0x64 == this->currentOrderValue) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int objId;
                    if (this->objectValue != 0)
                        objId = this->objectValue->id;
                    else
                        objId = -1;
                    fprintf(actionFile, str_fmt_stopObject, objId,
                            str_taiuaimd_path, 0xade);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        if (this->currentOrderValue != -1) return 2;
        if (this->currentActionValue != event->p1) return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                    0xae7);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;

    case 600: {
        int id = event->caller;
        int i = 0;
        while (i < this->attackingUnitsValue.numberValue &&
               i < this->attackingUnitsValue.maximumSizeValue) {
            if (this->attackingUnitsValue.value[i] == id) goto already;
            ++i;
        }

        if (this->attackingUnitsValue.numberValue >
            this->attackingUnitsValue.maximumSizeValue - 1) {
            int newCount = this->attackingUnitsValue.numberValue + 1;
            int* p = (int*)operator new(newCount * 4);
            if (p != 0) {
                for (int j = 0; j < this->attackingUnitsValue.maximumSizeValue && j < newCount; ++j)
                    p[j] = this->attackingUnitsValue.value[j];
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = p;
                this->attackingUnitsValue.maximumSizeValue = newCount;
            }
        }
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = id;
        ++this->attackingUnitsValue.numberValue;
already:
        this->objectValue->setUnderAttack(1);
        return 2;
    }

    case 0x1f4:
    case 0x1f5:
    case 0x1f6:
    case 0x1f7:
    case 0x1f8:
    case 0x1fd:
    case 0x1fe:
    case 0x1ff:
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
    case 0x204:
    case 0x205:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20a:
    case 0x20b:
    case 0x20c:
    case 0x20d:
    case 0x20e:
    case 0x20f:
    case 0x210:
    case 0x211:
    case 0x212:
    case 0x213:
    case 0x214:
    case 0x215:
    case 0x216:
    case 0x217:
    case 0x218:
    case 0x219:
    case 0x21a:
    case 0x21b:
    case 0x21c:
    case 0x21d:
    case 0x21e:
    case 0x21f:
    case 0x220:
    case 0x221:
    case 0x222:
    case 0x223:
    case 0x224:
    case 0x225:
    case 0x226:
    case 0x227:
    case 0x228:
    case 0x229:
    case 0x22a:
    case 0x22b:
    case 0x22c:
    case 0x22d:
    case 0x22e:
    case 0x22f:
    case 0x230:
    case 0x231:
    case 0x232:
    case 0x233:
    case 0x234:
    case 0x235:
    case 0x236:
    case 0x237:
    case 0x238:
    case 0x239:
    case 0x23a:
    case 0x23b:
    case 0x23c:
    case 0x23d:
    case 0x23e:
    case 0x23f:
    case 0x240:
    case 0x241:
    case 0x242:
    case 0x243:
    case 0x244:
    case 0x245:
    case 0x246:
    case 0x247:
    case 0x248:
    case 0x249:
    case 0x24a:
    case 0x24b:
    case 0x24c:
    case 0x24d:
    case 0x24e:
    case 0x24f:
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x253:
    case 0x254:
    case 0x255:
    case 0x256:
    case 0x257:
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
    case 0x263:
    case 0x264:
    case 0x265:
    case 0x266:
    case 0x267:
    case 0x268:
    case 0x269:
    case 0x26a:
    case 0x26b:
    case 0x26c:
    case 0x26d:
    case 0x26e:
    case 0x26f:
    case 0x270:
    case 0x271:
    case 0x272:
    case 0x273:
    case 0x274:
    case 0x275:
    case 0x276:
    case 0x277:
    case 0x278:
    case 0x279:
    case 0x27a:
    case 0x27b:
    case 0x27c:
    case 0x27d:
    case 0x27e:
    case 0x27f:
    case 0x280:
    case 0x281:
    case 0x282:
    case 0x283:
    case 0x284:
    case 0x285:
    case 0x286:
    case 0x287:
    case 0x288:
    case 0x289:
    case 0x28a:
    case 0x28b:
    case 0x28c:
    case 0x28d:
    case 0x28e:
    case 0x28f:
    case 0x290:
    case 0x291:
    case 0x292:
    case 0x293:
    case 0x294:
    case 0x295:
    case 0x296:
    case 0x297:
    case 0x298:
    case 0x299:
    case 0x29a:
    case 0x29b:
    case 0x29c:
    case 0x29d:
    case 0x29e:
    case 0x29f:
    case 0x2a0:
    case 0x2a1:
    case 0x2a2:
    case 0x2a3:
    case 0x2a4:
    case 0x2a5:
    case 0x2a6:
    case 0x2a7:
    case 0x2a8:
    case 0x2a9:
    case 0x2aa:
    case 0x2ab:
    case 0x2ac:
    case 0x2ad:
    case 0x2ae:
    case 0x2af:
    case 0x2b0:
    case 0x2b1:
    case 0x2b2:
    case 0x2b3:
    case 0x2b4:
    case 0x2b5:
    case 0x2b6:
    case 0x2b7:
    case 0x2b8:
    case 0x2b9:
    case 0x2ba:
    case 0x2bb:
        return 2;
    }

    this->removeCurrentTarget();
    if (actionFile != 0) {
        int objId;
        if (this->objectValue != 0)
            objId = this->objectValue->id;
        else
            objId = -1;
        fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                0xb1f);
    }
    this->stopObject(1);
        this->notifyCommander(event);
    return 2;
}


int TribeArtifactUnitAIModule::processIdle(int param_1) {
    int iVar1;
    RGE_Static_Object *pRVar2;

    iVar1 = this->closestObject(-1, -1, -1, -1, 0);
    if ((numberDifferentPlayerObjectsVisible <= 1) && (iVar1 != -1)) {
        pRVar2 = this->objectValue->owner->world->object(iVar1);
        if (pRVar2 != 0) {
            if (this->objectValue->owner != pRVar2->owner) {
                this->objectValue->change_ownership(pRVar2->owner);
                return 6;
            }
        }
    }
    return 5;
}

// protected: virtual int __thiscall TribeArtifactUnitAIModule::processMisc(void)
//


extern FILE* actionFile;


int TribeArtifactUnitAIModule::processMisc()
{
    if (this->processIdle(1) == 6) {
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int value;
            if (this->objectValue != 0) {
                value = this->objectValue->id;
            } else {
                value = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", value, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0xB60);
        }
        this->stopObject(1);
        this->idleTimerValue = 0;
        return 10;
    }
    return 9;
}




TribeTowerUnitAIModule::TribeTowerUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x15;
    importantObjects = (int*)operator new(0x54);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 3;
        this->importantObjects[2] = 4;
        this->importantObjects[3] = 0x1A;
        this->importantObjects[4] = 0x18;
        this->importantObjects[5] = 6;
        this->importantObjects[6] = 0x23;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0C;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1C;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0x0D;
        this->importantObjects[15] = 0x1B;
        this->importantObjects[16] = 0x16;
        this->importantObjects[17] = 0x14;
        this->importantObjects[18] = 2;
        this->importantObjects[19] = 0x15;
        this->importantObjects[20] = 0x27;
    }
}


int TribeTowerUnitAIModule::canAttackUnit(RGE_Static_Object* target) {
    if (target == 0)
        return 0;
    if (target->master_obj->object_group == 1)
        return 0;
    if (this->objectValue->object_state < 2)
        return 0;
    return 1;
}


int TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int value) {
    if (value == 0x3 || value == 0x1B || value == 0x4 || value == 0x15 || value == 0x2)
        return 0;
    return 1;
}




TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x15;
    importantObjects = (int*)operator new(0x54);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 3;
        this->importantObjects[2] = 4;
        this->importantObjects[3] = 0x1A;
        this->importantObjects[4] = 0x18;
        this->importantObjects[5] = 6;
        this->importantObjects[6] = 0x23;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0C;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1C;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0x0D;
        this->importantObjects[15] = 0x1B;
        this->importantObjects[16] = 0x16;
        this->importantObjects[17] = 0x14;
        this->importantObjects[18] = 2;
        this->importantObjects[19] = 0x15;
        this->importantObjects[20] = 0x27;
    }
}



int TribeBuildingUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType - 0x1f4) {
    case 0:
    {
        if (event->p2 <= 0) {
            RGE_Static_Object* obj = this->objectValue;
            obj->owner->notify(obj->id, obj->id, 0x209, event->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        if (this->attackingUnitsValue.numberValue == 0 ||
            this->objectValue->owner->computerPlayer() == 1) {
            RGE_Static_Object* obj = this->objectValue;
            obj->owner->notify(obj->id, obj->id, 0x201, event->caller, 0, 0);
        }

        ManagedArray<int>* array = &this->attackingUnitsValue;
        int count = array->numberValue;
        int i = 0;
        for (; i < count && i < array->maximumSizeValue; ++i) {
            if (array->value[i] == event->caller) goto found_for_help;
        }
        if (this->objectValue->owner->computerPlayer() == 0 &&
            this->currentTargetValue != event->caller) {
            this->askForHelp(event->caller);
        }

found_for_help:
        i = 0;
        int caller = event->caller;
        count = array->numberValue;
        for (; i < count && i < array->maximumSizeValue; ++i) {
            if (array->value[i] == caller) goto already_in_list;
        }

        if (array->numberValue > array->maximumSizeValue - 1) {
            array->resize(array->numberValue + 1);
        }
        array->value[array->numberValue] = caller;
        array->numberValue++;

already_in_list:
        this->objectValue->setUnderAttack(1);
        return 2;
    }

    case 0x17:
        return 2;

    case 0x64:
    {
        int caller = event->caller;
        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == caller) goto changed_258;
        }

        if (this->attackingUnitsValue.numberValue >
            this->attackingUnitsValue.maximumSizeValue - 1) {
            int newMax = this->attackingUnitsValue.numberValue + 1;
            int* newList = (int*)operator new(newMax * 4);
            if (newList != 0) {
                for (i = 0; i < this->attackingUnitsValue.maximumSizeValue && i < newMax; ++i)
                    newList[i] = this->attackingUnitsValue.value[i];
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = newList;
                this->attackingUnitsValue.maximumSizeValue = newMax;
            }
        }
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

changed_258:
        this->objectValue->setUnderAttack(1);
        return 2;
    }

    case 0xc7:
    {
        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == event->caller) goto found_2bb;
        }
        return 2;

found_2bb:
        ManagedArray<int>* array = &this->attackingUnitsValue;
        int max = array->maximumSizeValue;
        int caller = event->caller;
        i = 0;
        if (max > 0) {
            while (i < max) {
                if (array->value[i] == caller)
                    break;
                ++i;
            }
        }
        if (i < max) {
            if (i < max - 1) {
                do {
                    array->value[i] = array->value[i + 1];
                    ++i;
                } while (i < this->attackingUnitsValue.maximumSizeValue - 1);
            }
            array->numberValue--;
            if (array->numberValue < 0)
                array->numberValue = 0;
        }
        return 2;
    }

    default:
        return 2;
    }
}


int TribeBuildingUnitAIModule::processIdle(int p0) { return 5; }
