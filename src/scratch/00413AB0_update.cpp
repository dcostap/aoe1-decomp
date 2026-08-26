// VA: 00413AB0 UnitAIModule::update (1372 bytes)
// aiuaimod.cpp:612-1069
// Typed period-plausible reconstruction of the main AI update tick.
//
// Attempt log:
// - Replaced the old raw-offset placeholder with the observed UnitAIModule,
//   RGE_Static_Object, action-list, and ManagedArray ownership surfaces.
// - Baseline follows the oracle's target cleanup, attacking-unit validation,
//   notify/order queue passes, idle timeout, and look-around tail.
// - Reordered the overloaded moveTo declarations so the four-float target
//   retry reaches vslot +0x90; inlined the object range expression and fixed
//   the priority formula to 100.0f / distance, capped at 99.
// - Modeled the two ManagedArray growth/removal paths and the out-of-line
//   notify error purge. Ten bounded hypotheses are now exhausted; the typed
//   reconstruction has the oracle's 37 behavior-backed call operations (the
//   two queue callbacks are still classified as extra virtual slots after
//   hoisting), 1473 bytes vs the oracle's 1372, and 1325 positional diff bytes.
// Main-agent source audit: named the observed Static_Object virtual methods
// (weaponRange, underAttack, setUnderAttack, setWaitingToMove, and
// waitingToMove) and replaced the remaining numeric slot labels through the
// proven +0x130 surface. Current post-audit check is 1469 bytes, 39 calls,
// and 76.66% shape; the queue-callback topology remains unresolved.
// Shard B pass: direct purge-and-return on notify result 4 is the natural
// oracle-supported form and improved the best diff from 1325 to 1314 bytes.
// Pointer-to-virtual-member callbacks emitted direct thunks and four extra
// calls, so they were rolled back. A raw vtable callback kept the same call
// map but changed cleanup and worsened the shape, so it was also rolled back.
// Shard B narrow control probe: processNotify and processOrder are unconditional
// callback loops whose bounds test supplies the empty-queue behavior. Removing
// the two source preconditions aligned all 37 ordered calls and raised shape
// similarity to 84.85%; the remaining drift is not a call-order gap.
//
// Follow-up probes:
// - The reviewed extern FILE* actionFile declaration reduced the natural source
//   to the exact 1372-byte boundary. Positive objectValue guards and one shared
//   target log/stop tail remain binary-supported in this basin.
// - Reversing the final look-around comparison to timer > timeout recovered the
//   original load order and raised shape to 90.89%; the source still has 458
//   instructions versus 461 and 1173 strict diff bytes.
// - A for-loop scan improved raw diff to 1114 bytes but moved the operator[]
//   growth block to a cold suffix. It was rolled back because the oracle keeps
//   that block before the lookup path. Volatility, register hints, explicit
//   labels, and alternate remove forms were also tested and discarded.
// - Direct currentOrder reloads removed an artificial live temporary and
//   reduced the strict diff to 1038 bytes. Binary evidence then fixed
//   weaponRange(1), the 100.0f data symbol, and a named distance float.
// - Two direct action-log calls tail-merge to the oracle's immediate 0x335 and
//   0x356 pushes. The invalid-attacker remove path breaks to the timer tail;
//   it does not retest the attacking-unit loop.
// - Current reduced check: 1372 bytes, 37 calls, 463 versus 461 instructions,
//   97.62% shape, 88.29% exact-block coverage, and 256 strict diff bytes.
//   BINARY NOTE: the first remaining block is +03A2. The oracle adds the
//   secondary and look-around timers, tests notify size, then stores all three
//   timers. The current source stores idle first and clears the offset register
//   before that test. Do not retain a metric-only scheduling workaround.
// - Accepted-drift audit: do not promote. The executable reads notifyQueueSize
//   before publishing the updated idle timer. The rebuild publishes idle first.
//   The executable also writes currentOrderPriority to a stack home before later
//   helper calls; the rebuild omits that helper-visible stack publication.
// - Specialist audit: moving offset initialization into the positive notify
//   guard changed the CFG and grew the body to 1417 bytes. Expanded timer
//   assignments, an idle-timer local, split order-loop declarations, and an
//   unused current-order local either duplicated the clean output or were
//   optimized away. Retain the clean natural source while this blocker remains.
// - Authentic-context pass: the complete PDB prefix through this owner now
//   compiles from canonical owner includes. Every exact anchor stays exact.
//   The accepted save drift and this owner's bytes also stay unchanged.
//   The prefix uses /O2 /Oy /GX, as required by three exact early owners.
//   Thus, missing prefix context does not cause the timer publication drift.
//   Extending the prefix through 00414800 also leaves this body unchanged.
// - The canonical declaration also restores the PDB-qualified nonvirtual
//   `?update@UnitAIModule@@QAEHK@Z` owner. The prior virtual declaration had
//   the same code bytes but the wrong owning symbol.
// - The later five-argument moveTo owner proves the canonical virtual ABI.
//   This call uses a binary-proven four-argument beta view at the same slot.
// - Typed notify and order indexing is required. VC5 derives the 0x18 and 0x24
//   byte induction variables after each initial bound test. This recovers the
//   executable's timer publication order and both queue-loop stack lifetimes.
// - Current reduced check: 1372 bytes, 37 aligned calls, 463 instructions,
//   98.27% shape, 95.23% exact-block coverage, and 226 strict diff bytes.
//   BLOCKER: the executable publishes currentOrder to the incoming parameter
//   home before the post-queue state guard. Natural tail locals and parameter
//   assignments are removed by VC5. The rebuild therefore stays seven bytes
//   short at +0467 and speculates one later currentAction read.

#include <stdio.h>

#include "../../include/aiuaimod_context.h"

#define taskedThisUpdate (*(int*)0x592A48)
#define searchedThisUpdate (*(int*)0x592A4C)
#define numberVisibleObjects (*(int*)0x592A50)
#define numberDifferentPlayerObjectsVisible (*(int*)0x592A54)
extern FILE* actionFile;
extern float DAT_0056ebc0;
#define actionFormat ((const char*)0x57F964)
#define actionSource ((const char*)0x57F980)

int UnitAIModule::update(unsigned long param_1)
{
    RGE_Static_Object* target;
    int i;
    int haveGameAction;

    if (2 < this->objectValue->object_state) {
        return 1;
    }

    taskedThisUpdate = 0;
    searchedThisUpdate = 0;
    numberVisibleObjects = 0;
    numberDifferentPlayerObjectsVisible = 0;

    haveGameAction = this->objectValue->actions->have_action();
    if (haveGameAction == 0 && this->objectValue->waitingToMove() == 1) {
        this->objectValue->setWaitingToMove(0);
    }

    i = -1;
    if (this->currentTargetValue != i) {
        target = this->lookupObject(this->currentTargetValue);
        if (target == 0) {
            this->currentTargetValue = i;
            if (this->currentActionValue == 600) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = i;
                    }
                    fprintf(actionFile, actionFormat, objectID,
                            actionSource, 0x306);
                }
                this->stopObject(1);
                this->idleTimerValue = this->idleTimeoutValue;
            }
        } else {
            long targetLogObjectID;
            if (this->objectValue->object_state == 2 && target->object_state > 2) {
                if (this->actionRequiresLiveTarget(this->currentActionValue) == 1) {
                    this->stopAfterTargetKilledValue = 0;
                    if (this->currentActionValue == 600) {
                        int idleResult = this->processIdle(0);
                        if (idleResult == 5) {
                            if (this->currentOrderValue != 0x2D5) {
                                if (this->moveTo(this->currentTargetXValue,
                                                 this->currentTargetYValue,
                                                 this->currentTargetZValue,
                                                 this->objectValue->weaponRange(),
                                                 0) == 0) {
                                    this->removeCurrentTarget();
                                    if (actionFile != 0) {
                                        if (this->objectValue != 0) {
                                            targetLogObjectID = this->objectValue->id;
                                        } else {
                                            targetLogObjectID = i;
                                        }
                                        fprintf(actionFile, actionFormat,
                                                targetLogObjectID,
                                                actionSource, 0x335);
                                    }
                                    this->stopObject(1);
                                } else {
                                    this->lastOrderValue = this->currentOrderValue;
                                    this->currentOrderValue = i;
                                    this->currentOrderPriorityValue = i;
                                }
                            }
                        } else if (this->currentOrderValue != 0x2D5) {
                            this->lastOrderValue = this->currentOrderValue;
                            this->currentOrderValue = i;
                            this->currentOrderPriorityValue = i;
                        }
                    } else {
                        this->removeCurrentTarget();
                        if (actionFile != 0) {
                            if (this->objectValue != 0) {
                                targetLogObjectID = this->objectValue->id;
                            } else {
                                targetLogObjectID = i;
                            }
                            fprintf(actionFile, actionFormat, targetLogObjectID,
                                    actionSource, 0x356);
                        }
                        this->stopObject(1);
                    }
                }
            }
            if (this->objectValue->owner->computerPlayer() == 1 &&
                this->currentOrderPriorityValue != i &&
                this->currentOrderPriorityValue < 100) {
                float distanceValue =
                    this->objectValue->distance_to_object(target);
                int distance = (int)(DAT_0056ebc0 / distanceValue);
                if (distance > 99) {
                    distance = 99;
                }
                this->currentOrderPriorityValue = distance;
            }
        }
    }

    if (this->attackingUnitsValue.numberValue == 0 &&
        this->objectValue->underAttack() != 0) {
        this->objectValue->setUnderAttack(0);
    } else {
        i = 0;
        if (this->attackingUnitsValue.numberValue > 0) {
            do {
                RGE_Static_Object* attacker =
                    this->lookupObject(this->attackingUnitsValue[i]);
                if (attacker != 0 && attacker->unitAI() != 0 &&
                    attacker->object_state <= 2 &&
                    attacker->unitAI()->currentTarget() == this->objectValue->id) {
                    ++i;
                    continue;
                }

                this->attackingUnitsValue.remove(
                    this->attackingUnitsValue[i]);
                break;
            } while (i < this->attackingUnitsValue.numberValue);
        }
    }

    this->lastWorldPositionX = this->objectValue->world_x;
    this->lastWorldPositionY = this->objectValue->world_y;
    this->lastWorldPositionZ = this->objectValue->world_z;
    this->idleTimerValue += param_1;
    this->secondaryTimerValue += param_1;
    this->lookAroundTimerValue += param_1;

    {
        int i = 0;
        while (i < this->notifyQueueSizeValue) {
            int result = this->processNotify(
                &this->notifyQueueValue[i], param_1);
            if (result == 4) {
                this->purgeNotifyQueue(param_1);
                return 0;
            }
            if (result == 3) {
                break;
            }
            ++i;
        }
    }

    this->purgeNotifyQueue(param_1);

    if (haveGameAction == 0) {
        switch (this->currentActionValue) {
        case 600:
        case 0x261:
        case 0x262:
        case 0x265:
        case 0x26B:
        case 0x26C:
            this->currentActionValue = -1;
            break;
        default:
            break;
        }
    }

    if (2 < this->objectValue->object_state) {
        return 0;
    }

    if (this->objectValue->groupCommanderValue == this->objectValue->id) {
        this->updateGroup(param_1);
    }

    if (this->currentActionValue == -1) {
        int i = 0;
        while (i < this->orderQueueSizeValue) {
            int result = this->processOrder(
                &this->orderQueueValue[i], i);
            if (result == 1) {
                break;
            }
            ++i;
        }
    }

    this->processMisc();

    if (this->idleTimerValue > this->adjustedIdleTimeoutValue) {
        if (this->currentActionValue == -1) {
            if (this->currentTargetValue == -1) {
                this->idleTimerValue = 0;
                this->processIdle(1);
                goto update_tail;
            }
        }
    } else if (this->currentActionValue == -1 &&
               this->currentTargetValue == -1) {
        goto update_tail;
    }

    this->idleTimerValue = 0;

update_tail:
    if (this->objectValue->owner->computerPlayer() == 1 &&
        this->lookAroundTimerValue > this->lookAroundTimeoutValue) {
        this->lookAround();
    }

    return 1;
}

#undef taskedThisUpdate
#undef searchedThisUpdate
#undef numberVisibleObjects
#undef numberDifferentPlayerObjectsVisible
#undef actionFormat
#undef actionSource
