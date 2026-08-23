// VA: 004180C0 UnitAIModule::processNotify (4916 bytes)
// PDB owner: aiuaimod.cpp, lines 4423-5186.
//
// Recovery notes:
// - The PDB gives one body at 004180C0-004193F3.
// - The authentic UnitAIModule type is 0x134 bytes.
// - Exact donor 00506320 proves both attacking-unit scans and array growth.
// - Source case order is 508, 506, 505, 507, 514, 523, 510, 600, 699.
// - Four nested weaponRange and canPath ladders restore all 148 calls.
// - BINARY NOTE: every attack and path call rereads event->caller.
// - This differs from attacker->id when the event or object graph changes.
// - BINARY NOTE: zero target damage stores zero currentTargetDC.
// - Nonzero target damage calls objectValue->damageCapability(target).
// - The 505 and 507 arms share one chained order-publication tail.
// - The 506 arm keeps a distinct direct order-publication tail.
// - Direct cleanup tails preserve all stop and commander notifications.
// - PDB locals name currentTargetDC, both kill times, three target coordinates,
//   tileY, and tileX. Their proven homes overlap parameters and scoped locals.
// - The authentic context removes five register-only byte differences.
// - Current best has exact size, frame, CFG, 148 calls, and 12 byte differences.
// - Residual drift is one move argument register map and two publication stores.
// - Tested aliases, accessors, literal forms, condition forms, and local scopes.
// - Those forms duplicated this basin or changed valid behavior and layout.
// - Needed evidence is the original 4757 call spelling or fuller header context.

#include <stdio.h>
typedef unsigned long ulong;
extern FILE* actionFile;
extern float DAT_0056ebc8;
extern float DAT_0056ebf4;
#define AOE1_AIUAIMOD_PROCESS_NOTIFY_CONTEXT
#include "../../include/aiuaimod_context.h"
#undef AOE1_AIUAIMOD_PROCESS_NOTIFY_CONTEXT


#define LOG_STOP(lineNumber) \
    do { \
        if (actionFile != 0) { \
            long objectID; \
            if (this->objectValue != 0) { \
                objectID = this->objectValue->id; \
            } else { \
                objectID = -1; \
            } \
            fprintf(actionFile, "#%d call stopObject %s %d\n", objectID, \
                    "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", (lineNumber)); \
        } \
    } while (0)

int UnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    float targetX;

    switch (event->mType) {
    case 500:
    case 527: {
        this->notifyCommander(event);

        if (event->p2 <= 0) {
            RGE_Static_Object* object = this->objectValue;
            object->owner->notify(object->id, object->id, 0x209,
                                  event->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        if (this->attackingUnitsValue.numberValue == 0 ||
            this->objectValue->owner->computerPlayer() == 1) {
            RGE_Static_Object* object = this->objectValue;
            object->owner->notify(object->id, object->id, 0x201,
                                  event->caller, 0, 0);
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
            int newMaximum = this->attackingUnitsValue.numberValue + 1;
            int* newValue = (int*)operator new(newMaximum * 4);
            if (newValue != 0) {
                for (i = 0;
                     i < this->attackingUnitsValue.maximumSizeValue &&
                     i < newMaximum;
                     ++i) {
                    newValue[i] = this->attackingUnitsValue.value[i];
                }
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = newValue;
                this->attackingUnitsValue.maximumSizeValue = newMaximum;
            }
        }
        this->attackingUnitsValue.value[
            this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

    after_add:
        this->objectValue->setUnderAttack(1);
        if (this->currentOrderValue != 0x2D5 &&
            this->currentOrderValue != -1 &&
            this->objectValue->owner->computerPlayer() == 0) {
            return 2;
        }
        if (this->currentOrderValue == 0x2D5) {
            return 2;
        }

        RGE_Static_Object* attacker = this->lookupObject(event->caller);
        if (attacker == 0) {
            return 2;
        }
        if (attacker->owner->id == this->objectValue->owner->id) {
            return 2;
        }
        if (this->currentActionValue == 0x25B &&
            this->runAwayFromAttackers(1) == 1) {
            return 3;
        }

        RGE_Static_Object* target = 0;
        if (this->currentTargetValue != -1) {
            target = this->lookupObject(this->currentTargetValue);
        }

        if (target == 0) {
            if (this->canAttackUnit(attacker) == 1) {
                if (this->objectValue->inAttackRange(attacker) != 1) {
                    if (this->objectValue->canPath(
                            event->caller,
                            this->objectValue->weaponRange(),
                            0, 0, -1, -1) != 1) {
                        goto no_target_failed;
                    }
                }
                if (this->attackObject(event->caller, 1) == 1 &&
                    this->currentOrderValue != 0x2BC) {
                    this->currentOrderValue = -1;
                    return 3;
                }
            } else {
            no_target_failed:
                if (this->currentActionValue != 0x262) {
                    this->runAwayFromAttackers(1);
                    return 3;
                }
            }
            return 3;
        }

        short objectGroup = target->master_obj->object_group;
        if ((objectGroup == 3 || objectGroup == 0x1B) &&
            target->master_obj->id != 0x4F &&
            target->master_obj->id != 199 &&
            target->master_obj->id != 0x45 &&
            this->objectValue->owner->computerPlayer() == 0) {
            if (this->canAttackUnit(attacker) == 1) {
                if (this->objectValue->inAttackRange(attacker) == 1 ||
                    this->objectValue->canPath(
                        event->caller, this->objectValue->weaponRange(),
                        0, 0, -1, -1) == 1) {
                    this->attackObject(event->caller, 1);
                    return 3;
                }
            }
            this->runAwayFromAttackers(1);
            return 3;
        }

        if (this->objectValue->owner->computerPlayer() != 1) {
            return 2;
        }
        if (target->master_obj->id == 0x114) {
            return 2;
        }

        float targetDamage = target->damageCapability();
        float objectDamage;
        if (targetDamage == DAT_0056ebc8) {
            objectDamage = 0.0f;
        } else {
            objectDamage = this->objectValue->damageCapability(target);
        }

        if (this->canAttackUnit(attacker) == 1 &&
            objectDamage == DAT_0056ebc8) {
            if (this->objectValue->inAttackRange(attacker) != 1) {
                if (this->objectValue->canPath(
                        event->caller,
                        this->objectValue->weaponRange(),
                        0, 0, -1, -1) != 1) {
                    goto compare_capability;
                }
            }
            this->attackObject(event->caller, 1);
        }

    compare_capability:
        float targetCapability = target->damageCapability(this->objectValue);
        float targetRatio;
        if (targetCapability > DAT_0056ebc8) {
            targetRatio = target->hitPoints / targetCapability;
        } else {
            targetRatio = 25000.0f;
        }

        float attackerCapability = attacker->damageCapability(this->objectValue);
        float attackerRatio;
        if (attackerCapability > DAT_0056ebc8) {
            attackerRatio = attacker->hitPoints / attackerCapability;
        } else {
            attackerRatio = 25000.0f;
        }

        if (this->canAttackUnit(attacker) != 1 ||
            attackerRatio >= targetRatio) {
            return 2;
        }
        if (this->objectValue->inAttackRange(attacker) != 1) {
            if (this->objectValue->canPath(
                    event->caller,
                    this->objectValue->weaponRange(),
                    0, 0, -1, -1) != 1) {
                return 2;
            }
        }
        this->attackObject(event->caller, 1);
        return 2;
    }

    case 508: {
        RGE_Static_Object* target = this->lookupObject(this->currentTargetValue);
        if (target != 0) {
            uchar visible = this->visibleStatus(
                this->objectValue->owner->visible,
                (int)target->world_x, (int)target->world_y);
            if (target->owner->id == 0) {
                return 2;
            }
            if (visible == 0x0F) {
                return 2;
            }

            targetX = this->currentTargetXValue;
            float targetY = this->currentTargetYValue;
            float targetZ = this->currentTargetZValue;
            int candidate = this->bestUnitToAttack(1, 0, 0);
            if (candidate != -1 &&
                candidate != this->currentTargetValue &&
                this->attackObject(candidate, 1) == 1) {
                this->currentOrderValue = -1;
                return 3;
            }
            if (this->objectValue->owner->computerPlayer() == 0 &&
                this->moveTo(targetX, targetY, targetZ, 0, 1) == 1) {
                int oldOrder = this->currentOrderValue;
                this->currentOrderValue = -1;
                this->lastOrderValue = oldOrder;
                this->currentOrderPriorityValue = -1;
                return 3;
            }
        }
        this->removeCurrentTarget();
        LOG_STOP(0x1269);
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;
    }

    case 506: {
        int order = this->currentOrderValue;
        if (order == 700 && event->p1 == 600) {
            if (this->processIdle(0) != 5) {
                return 2;
            }
            if (this->currentOrderValue == 0x2D5 ||
                this->objectValue->owner->computerPlayer() == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x128B);
                this->stopObject(0);
                return 2;
            }
            if (this->moveTo(this->currentTargetXValue,
                             this->currentTargetYValue,
                             this->currentTargetZValue,
                             this->desiredTargetDistanceValue - DAT_0056ebf4,
                             1) == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x129B);
                this->stopObject(0);
                return 2;
            }
            this->lastOrderValue = this->currentOrderValue;
            this->currentOrderValue = -1;
            this->currentOrderPriorityValue = -1;
            return 2;
        }
        if (order != -1 && this->currentActionValue + 100 == order) {
            this->removeCurrentTarget();
            LOG_STOP(0x12AF);
            this->stopObject(1);
            return 2;
        }
        if (order == -1 && this->currentActionValue == event->p1) {
            this->removeCurrentTarget();
            LOG_STOP(0x12B7);
            this->stopObject(1);
            return 2;
        }
        if (order == 0x2D4 && event->p1 == 0x262) {
            this->removeCurrentTarget();
            LOG_STOP(0x12C0);
            this->stopObject(0);
            return 2;
        }
        if (order == 0x2BD && event->p1 == 0x262) {
            this->setCurrentAction(-1);
            return 2;
        }
        if (order != 0x2D5 || event->p1 != 600) {
            return 2;
        }
        this->removeCurrentTarget();
        LOG_STOP(0x12CD);
        this->stopObject(1);
        return 2;
    }

    case 505: {
        int order = this->currentOrderValue;
        if (order == 700 && event->p1 == 600) {
            if (this->processIdle(0) != 5) {
                return 2;
            }
            if (this->currentOrderValue == 0x2D5 ||
                this->objectValue->owner->computerPlayer() == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x12E9);
                this->stopObject(1);
                return 2;
            }
            if (this->moveTo(this->currentTargetXValue,
                             this->currentTargetYValue,
                             this->currentTargetZValue,
                             this->desiredTargetDistanceValue - DAT_0056ebf4,
                             1) == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x12F3);
                this->stopObject(1);
                return 2;
            }
            this->lastOrderValue = this->currentOrderValue;
            this->currentOrderValue = this->currentOrderPriorityValue = -1;
            return 2;
        }
        if (order != -1 && this->currentActionValue + 100 == order) {
            this->removeCurrentTarget();
            LOG_STOP(0x1304);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (order == -1 && this->currentActionValue == event->p1) {
            this->removeCurrentTarget();
            LOG_STOP(0x130D);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (order == 0x2D4 && event->p1 == 0x262) {
            this->removeCurrentTarget();
            LOG_STOP(0x1317);
            this->stopObject(0);
            this->notifyCommander(event);
            return 2;
        }
        if (order == 0x2BD && event->p1 == 0x262) {
            this->setCurrentAction(-1);
            return 2;
        }
        if (order != 0x2D5 || event->p1 != 600) {
            return 2;
        }
        this->removeCurrentTarget();
        LOG_STOP(0x1325);
        this->stopObject(1);
        return 2;
    }

    case 507: {
        int order = this->currentOrderValue;
        if (order == 700 && event->p1 == 600) {
            if (this->processIdle(0) != 5) {
                return 2;
            }
            if (this->currentOrderValue == 0x2D5 ||
                this->objectValue->owner->computerPlayer() == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x1341);
                this->stopObject(1);
                return 2;
            }
            if (this->moveTo(this->currentTargetXValue,
                             this->currentTargetYValue,
                             this->currentTargetZValue,
                             this->desiredTargetDistanceValue - DAT_0056ebf4,
                             1) == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x134B);
                this->stopObject(1);
                return 2;
            }
            this->lastOrderValue = this->currentOrderValue;
            this->currentOrderValue = this->currentOrderPriorityValue = -1;
            return 2;
        }
        if (order != -1 && this->currentActionValue + 100 == order) {
            this->removeCurrentTarget();
            LOG_STOP(0x135C);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (order == -1 && this->currentActionValue == event->p1) {
            this->removeCurrentTarget();
            LOG_STOP(0x1365);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (order == 0x2D4 && event->p1 == 0x262) {
            this->removeCurrentTarget();
            LOG_STOP(0x136F);
            this->stopObject(0);
            this->notifyCommander(event);
            return 2;
        }
        if (order == 0x2BD && event->p1 == 0x262) {
            this->setCurrentAction(-1);
            return 2;
        }
        if (order != 0x2D5 || event->p1 != 600) {
            return 2;
        }
        this->removeCurrentTarget();
        LOG_STOP(0x137D);
        this->stopObject(1);
        return 2;
    }

    case 514: {
        int action = this->currentActionValue;
        if (action == 0x25D || action == 0x26F) {
            int x;
            int y;
            if (this->closestUndiscoveredTile(&x, &y, 1) == 1) {
                this->addToWaypointQueue(x, y);
                if (this->explore(x, y, 1) == 0) {
                    this->removeCurrentTarget();
                    LOG_STOP(0x1396);
                    this->stopObject(1);
                    this->notifyCommander(event);
                }
                this->currentActionValue = action;
                return 3;
            }
            this->removeCurrentTarget();
            LOG_STOP(0x13A6);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        } else {
            if (action != 0x261) {
                return 2;
            }
            int resourceType = this->currentTargetTypeValue;
            if (resourceType == -1) {
                resourceType = this->lastTargetTypeValue;
            }
            int losType = this->convertToLOSResourceType(resourceType);
            int targetID;
            if (losType != -1) {
                targetID = this->closestResourceObject(losType, 0);
            } else {
                targetID = this->closestObject(resourceType, -1, -1, -1, 0);
            }
            if (targetID != -1) {
                if (this->gatherObject(targetID, 1) == 1) {
                    return 3;
                }
                this->removeCurrentTarget();
                LOG_STOP(0x13CE);
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            } else {
                this->removeCurrentTarget();
                LOG_STOP(0x13DA);
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
    }

    case 523: {
        this->objectValue->stopAction();
        this->removeCurrentTarget();
        LOG_STOP(0x13E7);
        this->stopObject(1);
        this->purgeNotifyQueue(param_2);
        this->orderQueueSizeValue = 0;
        RGE_Static_Object* commander =
            this->lookupObject(this->objectValue->groupCommanderValue);
        if (commander != 0) {
            commander->commanderRemoveFromGroup(this->objectValue->id);
        }
        return 2;
    }

    case 510:
        this->objectValue->stopAction();
        this->removeCurrentTarget();
        LOG_STOP(0x13F9);
        this->stopObject(1);
        return 2;

    case 600: {
        int count = this->attackingUnitsValue.numberValue;
        int caller = event->caller;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == caller) {
                goto attacker_added;
            }
        }
        if (this->attackingUnitsValue.numberValue >
            this->attackingUnitsValue.maximumSizeValue - 1) {
            int newMaximum = this->attackingUnitsValue.numberValue + 1;
            int* newValue = (int*)operator new(newMaximum * 4);
            if (newValue != 0) {
                for (i = 0;
                     i < this->attackingUnitsValue.maximumSizeValue &&
                     i < newMaximum;
                     ++i) {
                    newValue[i] = this->attackingUnitsValue.value[i];
                }
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = newValue;
                this->attackingUnitsValue.maximumSizeValue = newMaximum;
            }
        }
        this->attackingUnitsValue.value[
            this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

    attacker_added:
        this->objectValue->setUnderAttack(1);
        return 2;
    }

    case 699: {
        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == event->caller) {
                this->attackingUnitsValue.remove(event->caller);
                return 2;
            }
        }
        return 2;
    }

    default:
        this->removeCurrentTarget();
        LOG_STOP(0x1439);
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;
    }
}

#undef LOG_STOP
