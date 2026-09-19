// Generated destructor and vtable entries are emitted by the compiler.
#include "../include/taiuaimd.h"
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "../include/game_globals.h"



TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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



int TribeHuntedAnimalUnitAIModule::processNotify(NotifyEvent* nEvent, unsigned long uTime) {
    switch (nEvent->mType) {
    case 0x1F4: {
        if (nEvent->p2 <= 0) {
            this->purgeNotifyQueue(uTime);
            return 4;
        }

        int caller = nEvent->caller;

        int i = 0;
        while (i < this->attackingUnitsValue.numberValue && i < this->attackingUnitsValue.maximumSizeValue) {
            if (this->attackingUnitsValue.value[i] == caller)
                goto done;
            i++;
        }

        if (this->attackingUnitsValue.numberValue > this->attackingUnitsValue.maximumSizeValue - 1) {
            int new_cap = this->attackingUnitsValue.numberValue + 1;
            int* new_arr = new int[new_cap];
            if (new_arr) {
                int j;
                for (j = 0; j < this->attackingUnitsValue.maximumSizeValue && j < new_cap; j++)
                    new_arr[j] = this->attackingUnitsValue.value[j];
                delete[] this->attackingUnitsValue.value;
                this->attackingUnitsValue.value = new_arr;
                this->attackingUnitsValue.maximumSizeValue = new_cap;
            }
        }

        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

        goto done;
    }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(nEvent, uTime);
    }

done:
    this->objectValue->setUnderAttack(1);
    this->runAwayFromAttackers(1);

    return 3;
}




int TribeHuntedAnimalUnitAIModule::processIdle(int doSearch) {
    int targetID;
    RGE_Static_Object* target;
    float evasiveMoveDistance, xDiff, yDiff, distanceDiff, nx, ny;
    targetID = closestObject(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0);

    if (targetID != -1) {
        target = objectValue->owner->world->object(targetID);
        if (target != 0) {
            evasiveMoveDistance = objectValue->maximumSpeed() * g_ai_evasive_distance_scale;
            xDiff = target->world_x - objectValue->world_x;
            yDiff = target->world_y - objectValue->world_y;
            distanceDiff = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
            nx = (float)(-((xDiff / distanceDiff) * evasiveMoveDistance)) + objectValue->world_x;
            ny = (float)(-((yDiff / distanceDiff) * evasiveMoveDistance)) + objectValue->world_y;
            evasiveMoveTo(nx, ny, objectValue->world_z, 1);
            return 6;
        }
    }
    return 5;
}



TribePreditorUnitAIModule::TribePreditorUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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



int TribePreditorUnitAIModule::canAttackUnitAtNeutrality(int oType) { return 1; }

extern FILE* actionFile;  // FILE* at 0x62C4CC
extern int fprintf(void*, const char*, ...);

// String constants at fixed RVAs in .rdata
extern const char str_taiuaimd_path[];    // at 0x588AE8
extern const char str_fmt_stopObject[];   // at 0x57F964

int TribePreditorUnitAIModule::processNotify(NotifyEvent* nEvent, unsigned long uTime) {
    if (nEvent->mType == 0x1FC) {
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
        this->notifyCommander(nEvent);
    }

    return UnitAIModule::processNotify(nEvent, uTime);
}


TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {}



int TribeElephantUnitAIModule::processNotify(NotifyEvent* nEvent, unsigned long uTime) {
    switch (nEvent->mType) {
    case 0x1F4: {
        if (nEvent->p2 <= 0) {
            this->purgeNotifyQueue(uTime);
            return 4;
        }

        int caller = nEvent->caller;
        int i = 0;
        while (i < this->attackingUnitsValue.numberValue && i < this->attackingUnitsValue.maximumSizeValue) {
            if (this->attackingUnitsValue.value[i] == caller)
                goto done;
            i++;
        }

        if (this->attackingUnitsValue.numberValue > this->attackingUnitsValue.maximumSizeValue - 1) {
            int newCapacity = this->attackingUnitsValue.numberValue + 1;
            int* newArray = new int[newCapacity];
            if (newArray) {
                int j;
                for (j = 0; j < this->attackingUnitsValue.maximumSizeValue && j < newCapacity; j++)
                    newArray[j] = this->attackingUnitsValue.value[j];
                delete[] this->attackingUnitsValue.value;
                this->attackingUnitsValue.value = newArray;
                this->attackingUnitsValue.maximumSizeValue = newCapacity;
            }
        }

        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

done:
        this->objectValue->setUnderAttack(1);
        int val = this->closestAttacker(0);
        this->attackObject(val, 0);
        return 3;
    }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(nEvent, uTime);
    }
}


int TribeElephantUnitAIModule::processIdle(int doSearch) { return 5; }



TribeLionUnitAIModule::TribeLionUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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


int TribeLionUnitAIModule::canAttackUnitAtNeutrality(int oType) { return 1; }


extern FILE* actionFile;
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];


int TribeLionUnitAIModule::processNotify(NotifyEvent* nEvent, unsigned long uTime) {
    switch (nEvent->mType) {
    case 0x1FC: {
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
        this->notifyCommander(nEvent);
    }
    break;

    case 0x1FA:
        if (nEvent->p1 != 0x258) {
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

    return UnitAIModule::processNotify(nEvent, uTime);
}

int TribeLionUnitAIModule::processIdle(int doSearch) {
    idleTimeoutValue = 6000;
    setAdjustedIdleTimeout();

    int targetId = closestObject(-1, -1, -1, -1, 0);
    RGE_Static_Object* newTarget = lookupObject(targetId);

    if (targetId == -1 || newTarget == 0) {
        return 5;
    }

    int difficulty = objectValue->owner->world->difficultyLevel();

    float maxReactDistance;
    if (rge_base_game->scenarioGame() == 1 && rge_base_game->singlePlayerGame() == 1 && difficulty >= 3) {
        float factor = (difficulty == 3) ? 0.75f : 0.5f;
        maxReactDistance = factor * objectValue->master_obj->los;
        if (maxReactDistance < 1.0f) {
            maxReactDistance = 1.0f;
        }
    } else {
        maxReactDistance = objectValue->master_obj->los * 2.0f;
    }

    float dist = objectValue->distance_to_object(newTarget);
    if (dist > maxReactDistance) {
        return 5;
    }

    attackObject(targetId, 0);
    return 6;
}


TribeRangedUnitAIModule::TribeRangedUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {}



typedef unsigned long ulong;


int TribeRangedUnitAIModule::processNotify(NotifyEvent* nEvent, ulong uTime) {
    if (nEvent->mType != 0x200) {
        return UnitAIModule::processNotify(nEvent, uTime);
    }

    if (this->currentActionValue == 600) {
        RGE_Game_World* gameWorld = this->objectValue->owner->world;
        RGE_Static_Object* targetObj = gameWorld->object(this->currentTargetValue);

        if (targetObj) {
            float distanceDiff = targetObj->getSpeed();
            if (distanceDiff != 0.0f) {
                this->order(this->objectValue->id, 0x2BC, this->currentTargetValue, -1,
                            this->currentTargetXValue, this->currentTargetYValue,
                            this->currentTargetZValue, this->desiredTargetDistanceValue, 0, 1, this->currentOrderPriorityValue);

                RGE_Static_Object* thisObj = this->objectValue;

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


TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {}


extern float g_ai_evasive_distance_scale;
extern float g_ranged_ai_zero_distance;
extern "C" double __cdecl sqrt(double);


int TribeRangedUnitAIModule2::processNotify(NotifyEvent* nEvent, unsigned long uTime) {
    RGE_Static_Object* target;
    float evasiveMoveDistance;
    float xDiff;
    float yDiff;
    float len;
    if (nEvent->mType != 0x200) {
        return UnitAIModule::processNotify(nEvent, uTime);
    }
    target = 0;
    if (this->currentActionValue != 0x258 ||
        (target = this->objectValue->owner->world->object(this->currentTargetValue)) == 0 ||
        target->getSpeed() == g_ranged_ai_zero_distance)
        return 2;

    this->order(this->objectValue->id, 0x2bc, this->currentTargetValue, -1,
                this->currentTargetXValue, this->currentTargetYValue,
                this->currentTargetZValue, this->desiredTargetDistanceValue, 0, 1, this->currentOrderPriorityValue);

    evasiveMoveDistance = this->objectValue->maximumSpeed() *
                          this->objectValue->rateOfFire() * g_ai_evasive_distance_scale;
    xDiff = target->world_x - this->objectValue->world_x;
    yDiff = target->world_y - this->objectValue->world_y;

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
                    RGE_Static_Object* obj2 = this->objectValue->owner->world->object(this->attackingUnitsValue.value[i]);
                    if (obj2) {
                        xDiff += obj2->world_x - this->objectValue->world_x;
                        yDiff += obj2->world_y - this->objectValue->world_y;
                    }
                }
            ++i;
        }
    }

    len = (float)sqrt(xDiff*xDiff + yDiff*yDiff);
    this->evasiveMoveTo(this->objectValue->world_x + (-(xDiff / len * evasiveMoveDistance)),
                        this->objectValue->world_y + (-(yDiff / len * evasiveMoveDistance)), this->objectValue->world_z, 1);
    return 3;
}




TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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


int TribeCivilianUnitAIModule::importantWhenDead(int objectType) {
    if (objectType == 0x7 || objectType == 0x9 || objectType == 0xA || objectType == 0xF || objectType == 0x8 || objectType == 0x20)
        return 1;
    return 0;
}




int TribeCivilianUnitAIModule::attackObject(int targetID, int unconditional) {
    RGE_Static_Object* obj = objectValue->owner->world->object(targetID);
    if (obj == 0) {
        return 0;
    }

    int group = (int)obj->master_obj->object_group;
    if (group == 9 || group == 10 || group == 15) {
        return this->huntObject(targetID, unconditional);
    }

    return UnitAIModule::attackObject(targetID, unconditional);
}

int TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object* unit) {
    if (!unit) return 0;
    return unit->master_obj->object_group != 1;
}


int TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(int oType) { return 0; }


int TribeCivilianUnitAIModule::retryableOrder(int orderType) {
    if (orderType == 0x2C1 || orderType == 0x2C5 || orderType == 0x2C9)
        return 1;
    return 0;
}


int TribeCivilianUnitAIModule::convertToLOSResourceType(int oType) {
    switch (oType) {
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


int TribeCivilianUnitAIModule::processNotify(NotifyEvent* nEvent, ulong uTime) {
    switch (nEvent->mType) {
    case 0x20f:
        if (this->objectValue->owner->world->difficultyLevel() >= 3)
            return 2;
        // Fall through.

    case 0x1f4: {
        if (nEvent->p2 <= 0) {
            RGE_Static_Object* object = this->objectValue;
            object->owner->notify(object->id, object->id, 0x209, nEvent->caller, 0, 0);
            this->purgeNotifyQueue(uTime);
            return 4;
        }

        RGE_Static_Object* attacker = this->lookupObject(nEvent->caller);
        RGE_Static_Object* target = this->lookupObject(this->currentTargetValue);
        if (attacker == 0)
            return 2;

        if (this->objectValue->owner->computerPlayer() == 1) {
            if (attacker->owner->id != 0 || attacker->id != this->currentTargetValue) {
                RGE_Static_Object* object = this->objectValue;
                object->owner->notify(object->id, object->id, 0x201, nEvent->caller, 0, 0);
            }
        } else if (this->attackingUnitsValue.numberValue == 0) {
            RGE_Static_Object* object = this->objectValue;
            object->owner->notify(object->id, object->id, 0x201, nEvent->caller, 0, 0);
        }

        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == nEvent->caller)
                goto skip_help;
        }
        if (this->objectValue->owner->computerPlayer() == 0 && this->currentTargetValue != nEvent->caller) {
            this->askForHelp(nEvent->caller);
        }

skip_help:
        i = 0;
        int caller = nEvent->caller;
        count = this->attackingUnitsValue.numberValue;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == caller)
                goto caller_recorded;
        }

        if (this->attackingUnitsValue.numberValue > this->attackingUnitsValue.maximumSizeValue - 1) {
            int newMaximum = this->attackingUnitsValue.numberValue + 1;
            int* values = (int*)operator new(newMaximum * sizeof(int));
            if (values != 0) {
                for (i = 0; i < this->attackingUnitsValue.maximumSizeValue && i < newMaximum; ++i) {
                    values[i] = this->attackingUnitsValue.value[i];
                }
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = values;
                this->attackingUnitsValue.maximumSizeValue = newMaximum;
            }
        }
        this->attackingUnitsValue.value[
            this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

caller_recorded:
        this->objectValue->setUnderAttack(1);
        float speed = this->objectValue->getSpeed();
        unsigned char actionState = this->objectValue->actionState();
        int orderValue = this->currentOrderValue;

        if (orderValue == 0x2c6 && speed > 0.0f)
            return 2;
        if (orderValue == 0x2bc)
            return 2;
        if (orderValue == 0x2c9 && actionState == 0x0c && target != 0 && target->master_obj->object_group == 0x0a &&
            attacker->owner->id == 0) {
            return 2;
        }
        if (orderValue == 0x2ce)
            return 2;

        if (attacker->owner->id == 0) {
            if (orderValue != -1) {
                this->order(this->objectValue->id, orderValue, this->currentTargetValue, -1,
                            this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue,
                            this->desiredTargetDistanceValue, 0, 0, this->currentOrderPriorityValue);
                this->currentOrderValue = 0x2bc;
                this->currentOrderPriorityValue = 100;
                this->attackObject(nEvent->caller, 1);
                this->stopAfterTargetKilledValue = 1;
                return 3;
            }
            this->attackObject(nEvent->caller, 1);
            return 3;
        }

        if (this->currentActionValue == 0x262 && speed != 0.0f)
            return 3;

        this->order(this->objectValue->id, orderValue, this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue, 0, 0, this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id = this->objectValue != 0 ? this->objectValue->id : -1;
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x39a);
        }
        this->stopObject(1);
        this->runAwayFromAttackers(1);
        return 3;
    }

    case 0x1fa:
        if (this->currentActionValue != nEvent->p1)
            return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id = this->objectValue != 0 ? this->objectValue->id : -1;
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x3aa);
        }
        this->stopObject(1);
        this->notifyCommander(nEvent);
        return 2;

    case 0x1f9:
        if (this->currentActionValue != nEvent->p1)
            return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id = this->objectValue != 0 ? this->objectValue->id : -1;
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x3b9);
        }
        this->stopObject(1);
        this->notifyCommander(nEvent);
        return 2;

    case 0x1fb:
    case 0x202: {
        int action = this->currentActionValue;
        if (action == 0x265) {
            int targetType = this->currentTargetTypeValue;
            if (targetType == -1)
                targetType = this->lastTargetTypeValue;
            if (targetType == -1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x3d3);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
                return 2;
            }

            int resourceType = this->convertToLOSResourceType(targetType);
            int targetID;
            if (resourceType != -1)
                targetID = this->closestResourceObject(resourceType, 0);
            else
                targetID = this->closestObject(targetType, -1, -1, -1, 0);

            if (targetID != -1) {
                if (this->huntObject(targetID, 1) == 1)
                    return 3;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x3f6);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
            } else if (this->objectValue->owner->computerPlayer() == 1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x40f);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
            }
        } else if (action == 0x261) {
            int targetType = this->currentTargetTypeValue;
            if (targetType == -1)
                targetType = this->lastTargetTypeValue;
            if (targetType == -1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x421);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
                return 2;
            }

            int resourceType = this->convertToLOSResourceType(targetType);
            int targetID;
            if (resourceType != -1) {
                targetID = this->closestResourceObject(resourceType, 0);
            } else if (nEvent->p2 == 0x32) {
                targetID = this->closestObject(targetType, -1, 2, 0x32, 0);
            } else {
                targetID = this->closestObject(targetType, -1, -1, -1, 0);
            }

            if (targetID != -1) {
                if (this->gatherObject(targetID, 1) == 1)
                    return 3;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x446);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
            } else if (this->objectValue->owner->computerPlayer() == 1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x453);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
            } else if (nEvent->p2 == 0x32) {
                RGE_Static_Object* object = this->objectValue;
                float x;
                if (object->world_x > 5.0f)
                    x = object->world_x - 2.5f;
                else
                    x = object->world_x - -2.5f;
                float y;
                if (object->world_y > 5.0f)
                    y = object->world_y - 2.5f;
                else
                    y = object->world_y - -2.5f;
                this->evasiveMoveTo(x, y, object->world_z, 1);
            }
        } else if (action == 0x25a) {
            int targetID = this->closestObject(this->currentTargetTypeValue, 3, 0, -1, 0);
            if (targetID == -1) {
                int type = this->currentTargetTypeValue == 0x1b ? 3 : 0x1b;
                targetID = this->closestObject(type, 3, 0, -1, 0);
            }
            if (targetID != -1 && this->objectValue->canPath(targetID, 1.0f, 0, 0, -1, -1) == 1) {
                if (this->buildObject(targetID, 1) == 1)
                    return 3;
                goto action_finished;
            }

            RGE_Static_Object* target =
                this->lookupObject(this->currentTargetValue);
            if (target == 0 || this->objectValue->distance_to_object(target) > 1.0f) {
                this->moveTo(this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue, 1.0f, 1);
            }
        } else if (action == 0x25d) {
            int tileX;
            int tileY;
            if (this->closestUndiscoveredTile(&tileX, &tileY, 1) == 1) {
                this->addToWaypointQueue(tileX, tileY);
                if (this->explore(tileX, tileY, 1) != 0)
                    return 3;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x4b4);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
            } else {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id = this->objectValue != 0 ? this->objectValue->id : -1;
                    fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x4c3);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
            }
        }

action_finished:
        if (nEvent->mType == 0x202)
            return 2;

        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id = this->objectValue != 0 ? this->objectValue->id : -1;
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x4cc);
        }
        this->stopObject(1);
        this->notifyCommander(nEvent);
        return 2;
    }

    default:
        return UnitAIModule::processNotify(nEvent, uTime);
    }
}


int TribeCivilianUnitAIModule::processIdle(int doSearch) { return 5; }


int TribeCivilianUnitAIModule::processMisc() { return 9; }



TribePriestUnitAIModule::TribePriestUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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



int TribePriestUnitAIModule::attackObject(int targetID, int unconditional) {
    if (this->canConvert(targetID) == 0) {
        if (this->currentOrderValue == -1) {
            if (this->objectValue->owner->computerPlayer() != 0) {
                return this->moveTo(targetID, this->objectValue->weaponRange(), unconditional);
            }
        }
        return 0;
    }
    return this->convertObject(targetID, unconditional);
}


int TribePriestUnitAIModule::retryableOrder(int orderType) {
    if (orderType == 0x2C0 || orderType == 0x2BF)
        return 1;
    return 0;
}


int TribePriestUnitAIModule::canConvert(int targetID) {
    if (this->objectValue->attribute_amount_held >= 100.0f) {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(targetID);
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


int TribePriestUnitAIModule::canAttackUnit(RGE_Static_Object* unit) {
    if (unit != 0) {
        return canConvert(unit->id);
    }
    return 0;
}



int TribePriestUnitAIModule::bestUnitToHeal(int idleHeal, float* allyDistance) {
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
            do {
                if (VisibleUnitList[a - 1][i].object_id != this->objectValue->id) {
                    RGE_Static_Object* unit =
                        this->lookupObject(VisibleUnitList[a - 1][i].object_id);
                    if (unit != 0) {
                        if (unit->master_obj->object_group != 3) {
                            if ((float)(int)unit->master_obj->hp > unit->hp) {
                                if (unit->object_state < 3) {
                                    if (idleHeal != 0 || VisibleUnitList[a - 1][i].distance <= 4) {
                                        if (this->objectValue->owner->id != 0 || VisibleUnitList[a - 1][i].distance <= 2) {
                                            if (this->objectValue->canPath(VisibleUnitList[a - 1][i].object_id,
                                                                           1.0f, 0, 0, -1, -1)) {
                                                float need = (float)(int)unit->master_obj->hp -
                                                    unit->hp / (float)(int)VisibleUnitList[a - 1][i].distance;
                                                if (allyToHealID == -1 || need < allyNeed) {
                                                    allyNeed = need;
                                                    allyToHealID = unit->id;
                                                    if (allyDistance != 0) {
                                                        *allyDistance = (float)(int)VisibleUnitList[a - 1][i].distance;
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


int TribePriestUnitAIModule::bestUnitToConvert(float* distance) {
    this->search();

    int best_id = -1;
    float targetValue = 0.0f;
    int i = 0;

    if (VisibleUnitList_Size[3] > 0) {
        do {
            if (this->objectValue->owner->isEnemy((int)VisibleUnitList[3][i].player) != 0) {
                RGE_Static_Object* found = this->lookupObject(VisibleUnitList[3][i].object_id);

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
                            if (distance != 0)
                                *distance = priority;
                        }
                    }
                }
            }

            i++;
        } while (i < VisibleUnitList_Size[3]);
    }

    return best_id;
}




int TribePriestUnitAIModule::processNotify(NotifyEvent* nEvent, unsigned long uTime) {
    switch (nEvent->mType) {
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
            this->notifyCommander(nEvent);
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
        this->notifyCommander(nEvent);
        return 2;

    case 0x1fc: {
        RGE_Static_Object* obj = this->lookupObject(this->currentTargetValue);
        if (obj != 0) {
            if (this->visibleStatus(this->objectValue->owner->visible, (int)obj->world_x, (int)obj->world_y) == 0x0f) {
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
        this->notifyCommander(nEvent);
        break;
    }
    }

    return UnitAIModule::processNotify(nEvent, uTime);
}



#pragma intrinsic(sqrt)

extern int __cdecl debug_rand(char* file, int line);


int TribePriestUnitAIModule::processIdle(int doSearch) {
    if (this->objectValue->owner->computerPlayer()) {
        if (UnitAIModule::processIdle(1) == 6) {
            return 6;
        }

        int range = VisibleUnitList_Size[3];
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 1708) % (range + 2);
        if (range > 0 && r > range) {
            float allyDistance;
            int action = this->bestUnitToHeal(1, &allyDistance);
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

        if (distanceDiff <= g_ranged_ai_zero_distance) {
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


int TribePriestUnitAIModule::processMisc() {
    if (this->objectValue->owner->computerPlayer() == 1) {
        RGE_Action_Object* object = (RGE_Action_Object*)this->objectValue;

        if (object->attribute_amount_held >= 100.0f) {
            if (object->actions->have_action() != 1 || object->actions->get_action()->state != 7) {
                int target = this->bestUnitToAttack(1, 1, 0);

                if (target != -1 && this->currentTargetValue != target) {
                    if (this->currentOrderValue != -1) {
                        this->order(this->objectValue->id, this->currentOrderValue, this->currentTargetValue, -1,
                                    this->currentTargetXValue, this->currentTargetYValue, this->currentTargetZValue,
                                    this->desiredTargetDistanceValue, 0, 0, this->currentOrderPriorityValue);

                        if (actionFile != 0) {
                            int objectID;
                            if (this->objectValue != 0) {
                                objectID = this->objectValue->id;
                            } else {
                                objectID = -1;
                            }
                            fprintf(actionFile, "#%d call stopObject %s %d\n", objectID,
                                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x6F8);
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




TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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




int TribeTradeShipUnitAIModule::processNotify(NotifyEvent* nEvent, ulong uTime) {
    switch (nEvent->mType) {
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
            int tileX;
            int tileY;
            if (this->closestUndiscoveredTile(&tileX, &tileY, 1) == 1) {
                this->addToWaypointQueue(tileX, tileY);
                if (this->explore(tileX, tileY, 1) == 0) {
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
                    this->notifyCommander(nEvent);
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
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x7a8);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
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
            fprintf(actionFile, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x7b0);
        }
        this->stopObject(1);
        this->notifyCommander(nEvent);
        return 2;

    default:
        return UnitAIModule::processNotify(nEvent, uTime);
    }

    if (nEvent->p2 <= 0) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x209, nEvent->caller, 0, 0);
        this->purgeNotifyQueue(uTime);
        return 4;
    }

    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x201, nEvent->caller, 0, 0);
    }

    int count = this->attackingUnitsValue.numberValue;
    int i = 0;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == nEvent->caller) {
            goto skip_help;
        }
    }
    if (this->objectValue->owner->computerPlayer() == 0 && this->currentTargetValue != nEvent->caller) {
        this->askForHelp(nEvent->caller);
    }

skip_help:
    i = 0;
    int caller = nEvent->caller;
    count = this->attackingUnitsValue.numberValue;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == caller) {
            goto after_add;
        }
    }

    if (this->attackingUnitsValue.numberValue > this->attackingUnitsValue.maximumSizeValue - 1) {
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
    if (this->objectValue->owner->computerPlayer() == 0 && this->currentOrderValue != -1) {
        return 2;
    }
    if (this->currentActionValue != 0x262) {
        this->order(this->objectValue->id, this->currentOrderValue, this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue, 0, 0, this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x761);
        }
        this->stopObject(1);
    }
    this->runAwayFromAttackers(1);
    return 3;
}




int TribeTradeShipUnitAIModule::processIdle(int doSearch) {
    if (this->objectValue->owner->computerPlayer()) {
        int targetId = this->closestObject(-1, -1, -1, -1, 0);
        if (targetId != -1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            if (target != 0) {
                float evasiveMoveDistance = this->objectValue->maximumSpeed() * 7.0f;
                float xDiff = target->world_x - this->objectValue->world_x;
                float yDiff = target->world_y - this->objectValue->world_y;
                float distanceDiff = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                this->evasiveMoveTo((float)(-(xDiff / distanceDiff * evasiveMoveDistance)) + this->objectValue->world_x,
                                    (float)(-(yDiff / distanceDiff * evasiveMoveDistance)) + this->objectValue->world_y,
                                    this->objectValue->world_z, 1);
                return 6;
            }
        }
    }

    return 5;
}




TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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



int TribeTransportShipUnitAIModule::processNotify(NotifyEvent* nEvent, ulong uTime) {
    switch (nEvent->mType) {
    case 0x1f4:
    case 0x20f:
        break;
    default:
        return UnitAIModule::processNotify(nEvent, uTime);
    }

    if (nEvent->p2 <= 0) {
        RGE_Static_Object* o = this->objectValue;
        o->owner->notify(o->id, o->id, 0x209, nEvent->caller, 0, 0);
        this->purgeNotifyQueue(uTime);
        return 4;
    }

    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* o = this->objectValue;
        o->owner->notify(o->id, o->id, 0x201, nEvent->caller, 0, 0);
    }

    int count = this->attackingUnitsValue.numberValue;
    int i = 0;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == nEvent->caller) goto found_for_help;
    }
    if (this->objectValue->owner->computerPlayer() == 0 && this->currentTargetValue != nEvent->caller) {
        this->askForHelp(nEvent->caller);
    }

found_for_help:
    i = 0;
    int caller = nEvent->caller;
    count = this->attackingUnitsValue.numberValue;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == caller) goto already_in_list;
    }

    if (this->attackingUnitsValue.numberValue > this->attackingUnitsValue.maximumSizeValue - 1) {
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




int TribeTransportShipUnitAIModule::processIdle(int doSearch) {
    if (this->objectValue->owner->computerPlayer()) {
        int targetId = closestObject(-1, -1, -1, -1, 0);

        if (targetId != -1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);

            if (target != 0) {
                float evasiveMoveDistance = this->objectValue->maximumSpeed() * 7.0f;

                float xDiff = target->world_x - this->objectValue->world_x;
                float yDiff = target->world_y - this->objectValue->world_y;
                float distanceDiff = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                float move_x = (float)(-((xDiff / distanceDiff) * evasiveMoveDistance)) + this->objectValue->world_x;
                float move_y = (float)(-((yDiff / distanceDiff) * evasiveMoveDistance)) + this->objectValue->world_y;

                evasiveMoveTo(move_x, move_y, this->objectValue->world_z, 1);

                return 6;
            }
        }
    }

    return 5;
}




TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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


int TribeFishingShipUnitAIModule::importantWhenDead(int objectType) {
    if (objectType != 0x1F && objectType != 5) {
        return 0;
    }
    return 1;
}


int TribeFishingShipUnitAIModule::convertToLOSResourceType(int oType) {
    if (oType == 0x1F || oType == 0x5 || oType == 0x21)
        return 2;
    return -1;
}




int TribeFishingShipUnitAIModule::processNotify(NotifyEvent* nEvent, ulong uTime) {
    switch (nEvent->mType) {
    case 0x1f4:
    case 0x20f:
        break;
    default:
        return UnitAIModule::processNotify(nEvent, uTime);
    }

    if (nEvent->p2 <= 0) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x209, nEvent->caller, 0, 0);
        this->purgeNotifyQueue(uTime);
        return 4;
    }

    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x201, nEvent->caller, 0, 0);
    }

    int count = this->attackingUnitsValue.numberValue;
    int i = 0;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == nEvent->caller) goto skip_help;
    }
    if (this->objectValue->owner->computerPlayer() == 0 && this->currentTargetValue != nEvent->caller) {
        this->askForHelp(nEvent->caller);
    }

skip_help:
    i = 0;
    int caller = nEvent->caller;
    count = this->attackingUnitsValue.numberValue;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == caller) goto after_add;
    }

    if (this->attackingUnitsValue.numberValue > this->attackingUnitsValue.maximumSizeValue - 1) {
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
    if (this->objectValue->owner->computerPlayer() == 0 && this->currentOrderValue != -1) {
        return 2;
    }
    if (this->currentActionValue != 0x262) {
        this->order(this->objectValue->id, this->currentOrderValue, this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue, 0, 0, this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0)
                id = this->objectValue->id;
            else
                id = -1;
            fprintf(actionFile, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x8d4);
        }
        this->stopObject(1);
    }
    this->runAwayFromAttackers(1);
    return 3;
}



extern float g_fishing_ship_evasive_distance_scale;


int TribeFishingShipUnitAIModule::processIdle(int doSearch) {
    if (objectValue->owner->computerPlayer()) {
        int targetID = closestObject(-1, -1, -1, -1, 0);

        if (targetID != -1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetID);

            if (target != 0) {
                float evasiveMoveDistance = objectValue->maximumSpeed() * g_fishing_ship_evasive_distance_scale;
                float xDiff = target->world_x - objectValue->world_x;
                float yDiff = target->world_y - objectValue->world_y;
                float distanceDiff = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                evasiveMoveTo((0.0f - ((xDiff / distanceDiff) * evasiveMoveDistance)) + objectValue->world_x,
                              (0.0f - ((yDiff / distanceDiff) * evasiveMoveDistance)) + objectValue->world_y,
                              objectValue->world_z, 1);
                return 6;
            }
        }
    }

    return 5;
}



TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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



int TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object* unit) {
    if (!unit) return 0;
    return unit->master_obj->object_group != 1;
}



int TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int oType) {
    if (oType == 0x3 || oType == 0x1B || oType == 0x4 || oType == 0x15 || oType == 0x2 || oType == 0x14)
        return 0;
    return 1;
}



extern float g_soldier_evasive_distance_threshold;
extern float g_soldier_evasive_coordinate_offset;
extern float g_soldier_random_evasive_offset;
extern float g_soldier_evasive_coordinate_threshold;
extern float g_soldier_evasive_fallback_adjustment;

int TribeSoldierUnitAIModule::processNotify(NotifyEvent* nEvent, ulong uTime) {
    NotifyEvent* event = nEvent;
    float newX;
    float newY;
    RGE_Static_Object* target;
    float evasiveMoveDistance;
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
            this->order(this->objectValue->id, this->currentOrderValue, this->currentTargetValue, -1,
                        this->currentTargetXValue, this->currentTargetYValue,
                        this->currentTargetZValue, this->desiredTargetDistanceValue, 0, 0, this->currentOrderPriorityValue);
        }

        newX =
            (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 2428) % 8) +
            (this->objectValue->world_x - g_soldier_random_evasive_offset);
        if (newX == this->objectValue->world_x) {
            if (newX > g_soldier_evasive_coordinate_threshold)
                newX -= g_soldier_evasive_coordinate_offset;
            else
                newX -= g_soldier_evasive_fallback_adjustment;
        }

        newY =
            (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 2435) % 8) +
            (this->objectValue->world_y - g_soldier_random_evasive_offset);
        if (newY == this->objectValue->world_y) {
            if (newY > g_soldier_evasive_coordinate_threshold)
                newY -= g_soldier_evasive_coordinate_offset;
            else
                newY -= g_soldier_evasive_fallback_adjustment;
        }

        if (this->intelligentEvasiveMoveTo(newX, newY, this->objectValue->world_z, 1, 1) != 1)
            break;
        taskedThisUpdate = 1;
        return 3;
    }

    case 0x200: {
        if (this->objectValue->owner->computerPlayer() != 0 && this->objectValue->weaponRange() >= g_soldier_evasive_distance_threshold &&
            this->objectValue->master_obj->object_group != 0x1A) {
            if (this->currentActionValue == 600) {

            target =
                this->objectValue->owner->world->object(this->currentTargetValue);
            if (target != 0) {

                evasiveMoveDistance = this->objectValue->weaponRange() -
                    this->objectValue->distance_to_object(target);
                if (evasiveMoveDistance >= g_soldier_evasive_distance_threshold) {

                    xDiff = target->world_x - this->objectValue->world_x;
                    yDiff = target->world_y - this->objectValue->world_y;

                    this->order(this->objectValue->id, 700, this->currentTargetValue, -1,
                                this->currentTargetXValue, this->currentTargetYValue,
                                this->currentTargetZValue, this->desiredTargetDistanceValue, 0, 1, this->currentOrderPriorityValue);

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
                        this->objectValue->owner->world->object(this->attackingUnitsValue.value[i]);
                    if (object != 0) {
                        xDiff += object->world_x - this->objectValue->world_x;
                        yDiff += object->world_y - this->objectValue->world_y;
                    }
                }
                ++i;
            }
                    }

                    distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
                    if (this->intelligentEvasiveMoveTo((float)(-((xDiff / distance) * evasiveMoveDistance)) +
                                                       this->objectValue->world_x, (float)(-((yDiff / distance) * evasiveMoveDistance)) +
                                                       this->objectValue->world_y, this->objectValue->world_z, 0, 1) != 1)
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
    return UnitAIModule::processNotify(event, uTime);
return_two:
    return 2;
}





int TribeSoldierUnitAIModule::processIdle(int doSearch) {
    if (doSearch == 1 && this->processRetryableOrder() == 8) {
        return 6;
    }

    if (this->objectValue->owner->id != 0 && (this->objectValue->owner->computerPlayer() != 0 ||
         this->objectValue->master_obj->id != 0x12B)) {
        if (this->currentOrderValue != 0x2D5 || (this->objectValue->master_obj->id != 0x23 &&
             this->objectValue->master_obj->id != 0x24 && this->objectValue->master_obj->id != 0xFA)) {
            int targetID = this->bestUnitToAttack(1, 0, 0);
            if (targetID != -1 && this->attackObject(targetID, 1) == 1) {
                return 6;
            }

            if (this->objectValue->owner->computerPlayer() != 0 && this->objectValue->inGroup() != 1) {
                this->objectValue->owner->world->difficultyLevel();

                if ((rge_base_game->scenarioGame() == 1 && rge_base_game->singlePlayerGame() == 1 &&
                     this->objectValue->owner->strategicNumber(0x8F) == 0) || (rge_base_game->singlePlayerGame() == 1 &&
                     this->objectValue->owner->strategicNumber(0x8F) == 0)) {
                    return 5;
                }

                if (this->currentOrderValue != 0x2BD && this->currentOrderValue != 0x2D5) {
                    int targetID2 = this->closestObject(-1, -1, -1, -1, 0);
                    if (targetID2 != -1) {
                        RGE_Static_Object* target =
                            this->objectValue->owner->world->object(targetID2);
                        if (target != 0) {
                            float evasiveMoveDistance =
                                this->objectValue->maximumSpeed() * g_ai_evasive_distance_scale;
                            float xDiff = target->world_x - this->objectValue->world_x;
                            float yDiff = target->world_y - this->objectValue->world_y;
                            float distanceDiff =
                                sqrt(xDiff * xDiff + yDiff * yDiff);
                            float x =
                                (float)(-((xDiff / distanceDiff) * evasiveMoveDistance)) +
                                this->objectValue->world_x;
                            float y =
                                (float)(-((yDiff / distanceDiff) * evasiveMoveDistance)) +
                                this->objectValue->world_y;
                            this->evasiveMoveTo(x, y, this->objectValue->world_z, 1);
                            return 6;
                        }
                    }
                }
            }
        }
    }

    return 5;
}



TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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


int TribeArtifactUnitAIModule::processNotify(NotifyEvent* nEvent, unsigned long uTime) {
    switch (nEvent->mType) {
    case 0x1fc: {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->currentTargetValue);
        if (obj != 0) {
            if (this->objectValue->owner->visible->get_visible((int)obj->world_x, (int)obj->world_y) == 0x0f)
                return 2;
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0xa9f);
        }
        this->stopObject(1);
        this->notifyCommander(nEvent);
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
                    fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0xaae);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
                return 2;
            }
        }
        if (this->currentOrderValue != -1) return 2;
        if (this->currentActionValue != nEvent->p1) return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0xab7);
        }
        this->stopObject(1);
        this->notifyCommander(nEvent);
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
                    fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0xac6);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
                return 2;
            }
        }
        if (this->currentOrderValue != -1) return 2;
        if (this->currentActionValue != nEvent->p1) return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0xacf);
        }
        this->stopObject(1);
        this->notifyCommander(nEvent);
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
                    fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0xade);
                }
                this->stopObject(1);
                this->notifyCommander(nEvent);
                return 2;
            }
        }
        if (this->currentOrderValue != -1) return 2;
        if (this->currentActionValue != nEvent->p1) return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0xae7);
        }
        this->stopObject(1);
        this->notifyCommander(nEvent);
        return 2;

    case 600: {
        int id = nEvent->caller;
        int i = 0;
        while (i < this->attackingUnitsValue.numberValue && i < this->attackingUnitsValue.maximumSizeValue) {
            if (this->attackingUnitsValue.value[i] == id) goto already;
            ++i;
        }

        if (this->attackingUnitsValue.numberValue > this->attackingUnitsValue.maximumSizeValue - 1) {
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
    case 0x1f6:
    case 0x1f7:
    case 0x1f8:
    case 0x1fd:
    case 0x1fe:
    case 0x1ff:
    case 0x200:
    case 0x202:
    case 0x203:
    case 0x20b:
    case 0x20f:
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
        fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0xb1f);
    }
    this->stopObject(1);
        this->notifyCommander(nEvent);
    return 2;
}


int TribeArtifactUnitAIModule::processIdle(int doSearch) {
    int target_id;
    RGE_Static_Object* target;

    target_id = this->closestObject(-1, -1, -1, -1, 0);
    if ((numberDifferentPlayerObjectsVisible <= 1) && (target_id != -1)) {
        target = this->objectValue->owner->world->object(target_id);
        if (target != 0) {
            if (this->objectValue->owner != target->owner) {
                this->objectValue->change_ownership(target->owner);
                return 6;
            }
        }
    }
    return 5;
}



int TribeArtifactUnitAIModule::processMisc() {
    if (this->processIdle(1) == 6) {
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int object_id;
            if (this->objectValue != 0) {
                object_id = this->objectValue->id;
            } else {
                object_id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", object_id, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0xB60);
        }
        this->stopObject(1);
        this->idleTimerValue = 0;
        return 10;
    }
    return 9;
}




TribeTowerUnitAIModule::TribeTowerUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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


int TribeTowerUnitAIModule::canAttackUnit(RGE_Static_Object* unit) {
    if (unit == 0)
        return 0;
    if (unit->master_obj->object_group == 1)
        return 0;
    if (this->objectValue->object_state < 2)
        return 0;
    return 1;
}


int TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int oType) {
    if (oType == 0x3 || oType == 0x1B || oType == 0x4 || oType == 0x15 || oType == 0x2)
        return 0;
    return 1;
}




TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(RGE_Static_Object* o, int iQS)
    : UnitAIModule(o, iQS) {
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



int TribeBuildingUnitAIModule::processNotify(NotifyEvent* nEvent, ulong uTime) {
    switch (nEvent->mType) {
    case 0x1f4:
        if (nEvent->p2 <= 0) {
            RGE_Static_Object* object = this->objectValue;
            object->owner->notify(object->id, object->id, 0x209, nEvent->caller, 0, 0);
            this->purgeNotifyQueue(uTime);
            return 4;
        }

        if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
            RGE_Static_Object* object = this->objectValue;
            object->owner->notify(object->id, object->id, 0x201, nEvent->caller, 0, 0);
        }

        if (!this->attackingUnitsValue.contains(nEvent->caller) && this->objectValue->owner->computerPlayer() == 0 &&
            this->currentTargetValue != nEvent->caller) {
            this->askForHelp(nEvent->caller);
        }

        if (!this->attackingUnitsValue.contains(nEvent->caller)) {
            int index = this->attackingUnitsValue.numberValue;
            this->attackingUnitsValue[index] = nEvent->caller;
            this->attackingUnitsValue.numberValue++;
        }
        this->objectValue->setUnderAttack(1);
        return 2;

    case 0x258:
        this->attackingUnitsValue.add(nEvent->caller);
        this->objectValue->setUnderAttack(1);
        return 2;

    case 0x2bb:
        if (this->attackingUnitsValue.contains(nEvent->caller)) {
            this->attackingUnitsValue.remove(nEvent->caller);
        }
        return 2;

    default:
        return 2;
    }
}


int TribeBuildingUnitAIModule::processIdle(int doSearch) { return 5; }
