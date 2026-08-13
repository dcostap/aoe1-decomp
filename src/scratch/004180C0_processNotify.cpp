// VA: 004180C0 UnitAIModule::processNotify (4916 bytes)
// aiuaimod.cpp:4423-5186
//
// Attempt log:
// - Replaced the range-only placeholder with typed NotifyEvent and local ABI
//   surfaces for UnitAIModule, RGE_Static_Object, and RGE_Player.
// - Baseline captured the attack list, target, path, stop, logging, and queue
//   cases from the original switch and call map.
// - Split the three ordered stop-notification cases. This improved the size,
//   CFG, call alignment, and positional diff.
// - Materialized target coordinates as a liveness probe. It moved the diff
//   farther and was rolled back.
// - Added the binary-supported no-op path for unused in-range notifications.
// - Explicit switch arms for unused types 502-698 did not preserve the
//   original shared return layout; the diff worsened and the probe was rolled
//   back.
// - A narrower explicit arm set for 602-698 also worsened the same basin and
//   was rolled back. The binary labels confirm shared jump-table targets, but
//   source case spelling is not the remaining structural fix.
// Left in scratch: structural call-site and frame drift remain broad.

#if 0
#include "../../include/unit_ai_module.h"

int UnitAIModule::processNotify(void* notifyEvent)
{
    int mType = *(int*)((char*)notifyEvent + 8);  // NotifyEvent.mType at +0x08
    int dispatchKey = mType - 500;
    
    if (dispatchKey < 0 || dispatchKey > 199) {
        return 0; // Unhandled
    }
    
    switch (dispatchKey) {
    case 0: // mType == 500: Attack notification
        // Complex logic:
        // - Get caller from notifyEvent
        // - Add to attackingUnits list
        // - Check team, check current target
        // - Return 2/3/4 based on state
        // Falls through to default
        break;
        
    case 1: // mType == 501
        return 0;
        
    case 2: // mType == 502
        return 0;
        
    case 26: // mType == 526 (0x20E): Under attack
        // Under attack notification
        // - Get caller 
        // - Call lookUpObject(caller)
        // - Check if valid target
        // - If no defendTarget: set defendTarget, stop current action
        // - Add to attackingUnits
        break;
        
    default:
        return 0;
    }
    
    return 0;
}
#endif

// Canonical binary-supported reconstruction. The old range-only sketch above
// stays disabled as a record of the initial placeholder.

typedef unsigned char uchar;
typedef unsigned long ulong;

struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    long p1;
    long p2;
    long p3;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
};

class RGE_Player;

#define OBJECT_PAD(n) virtual void objectPad##n();
class RGE_Static_Object {
public:
    OBJECT_PAD(0) OBJECT_PAD(1) OBJECT_PAD(2) OBJECT_PAD(3)
    OBJECT_PAD(4) OBJECT_PAD(5) OBJECT_PAD(6) OBJECT_PAD(7)
    OBJECT_PAD(8) OBJECT_PAD(9) OBJECT_PAD(10) OBJECT_PAD(11)
    OBJECT_PAD(12) OBJECT_PAD(13) OBJECT_PAD(14) OBJECT_PAD(15)
    OBJECT_PAD(16) OBJECT_PAD(17) OBJECT_PAD(18) OBJECT_PAD(19)
    OBJECT_PAD(20) OBJECT_PAD(21) OBJECT_PAD(22) OBJECT_PAD(23)
    OBJECT_PAD(24) OBJECT_PAD(25) OBJECT_PAD(26) OBJECT_PAD(27)
    OBJECT_PAD(28) OBJECT_PAD(29) OBJECT_PAD(30) OBJECT_PAD(31)
    OBJECT_PAD(32) OBJECT_PAD(33) OBJECT_PAD(34) OBJECT_PAD(35)
    OBJECT_PAD(36) OBJECT_PAD(37) OBJECT_PAD(38) OBJECT_PAD(39)
    OBJECT_PAD(40) OBJECT_PAD(41) OBJECT_PAD(42) OBJECT_PAD(43)
    OBJECT_PAD(44) OBJECT_PAD(45) OBJECT_PAD(46) OBJECT_PAD(47)
    OBJECT_PAD(48) OBJECT_PAD(49) OBJECT_PAD(50) OBJECT_PAD(51)
    OBJECT_PAD(52) OBJECT_PAD(53) OBJECT_PAD(54) OBJECT_PAD(55)
    OBJECT_PAD(56)
    virtual int inAttackRange(RGE_Static_Object* object);
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar value);
    OBJECT_PAD(60) OBJECT_PAD(61) OBJECT_PAD(62) OBJECT_PAD(63)
    OBJECT_PAD(64)
    virtual float damageCapability(RGE_Static_Object* object);
    virtual float damageCapability();
    // This call has four integer arguments at the observed +0x10C slot.
    virtual float weaponRange(int, int, int, int);
    OBJECT_PAD(68) OBJECT_PAD(69) OBJECT_PAD(70) OBJECT_PAD(71)
    OBJECT_PAD(72) OBJECT_PAD(73) OBJECT_PAD(74) OBJECT_PAD(75)
    OBJECT_PAD(76) OBJECT_PAD(77) OBJECT_PAD(78) OBJECT_PAD(79)
    OBJECT_PAD(80) OBJECT_PAD(81) OBJECT_PAD(82) OBJECT_PAD(83)
    OBJECT_PAD(84) OBJECT_PAD(85) OBJECT_PAD(86) OBJECT_PAD(87)
    OBJECT_PAD(88) OBJECT_PAD(89) OBJECT_PAD(90) OBJECT_PAD(91)
    OBJECT_PAD(92) OBJECT_PAD(93) OBJECT_PAD(94) OBJECT_PAD(95)
    OBJECT_PAD(96) OBJECT_PAD(97) OBJECT_PAD(98)
    virtual int stopAction();
    OBJECT_PAD(100)
    virtual int canPath(int, float, float*, int, int, int);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    int commanderRemoveFromGroup(int objectId);
};
#undef OBJECT_PAD

#define PLAYER_PAD(n) virtual void playerPad##n();
class RGE_Player {
public:
    PLAYER_PAD(0) PLAYER_PAD(1) PLAYER_PAD(2) PLAYER_PAD(3)
    PLAYER_PAD(4) PLAYER_PAD(5) PLAYER_PAD(6) PLAYER_PAD(7)
    PLAYER_PAD(8) PLAYER_PAD(9) PLAYER_PAD(10) PLAYER_PAD(11)
    PLAYER_PAD(12) PLAYER_PAD(13) PLAYER_PAD(14) PLAYER_PAD(15)
    PLAYER_PAD(16) PLAYER_PAD(17) PLAYER_PAD(18) PLAYER_PAD(19)
    PLAYER_PAD(20) PLAYER_PAD(21) PLAYER_PAD(22) PLAYER_PAD(23)
    PLAYER_PAD(24) PLAYER_PAD(25) PLAYER_PAD(26) PLAYER_PAD(27)
    PLAYER_PAD(28) PLAYER_PAD(29) PLAYER_PAD(30) PLAYER_PAD(31)
    PLAYER_PAD(32) PLAYER_PAD(33) PLAYER_PAD(34) PLAYER_PAD(35)
    PLAYER_PAD(36) PLAYER_PAD(37) PLAYER_PAD(38) PLAYER_PAD(39)
    PLAYER_PAD(40) PLAYER_PAD(41) PLAYER_PAD(42) PLAYER_PAD(43)
    PLAYER_PAD(44) PLAYER_PAD(45) PLAYER_PAD(46) PLAYER_PAD(47)
    PLAYER_PAD(48) PLAYER_PAD(49) PLAYER_PAD(50) PLAYER_PAD(51)
    PLAYER_PAD(52) PLAYER_PAD(53) PLAYER_PAD(54) PLAYER_PAD(55)
    PLAYER_PAD(56) PLAYER_PAD(57)
    virtual void notify(int, int, int, long, long, long);

    int computerPlayer();
    char gap_04[0x34];
    void* visibleMap;
    void* world;
    short id;
};
#undef PLAYER_PAD

struct AttackingUnits {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

#define UNIT_PAD(n) virtual int unitPad##n();
class UnitAIModule {
public:
    virtual ~UnitAIModule();
    UNIT_PAD(1) UNIT_PAD(2) UNIT_PAD(3) UNIT_PAD(4)
    UNIT_PAD(5) UNIT_PAD(6)
    virtual int notifyCommander(NotifyEvent* event);
    UNIT_PAD(8) UNIT_PAD(9) UNIT_PAD(10) UNIT_PAD(11)
    virtual int bestUnitToAttack(int, int, float*);
    UNIT_PAD(13) UNIT_PAD(14) UNIT_PAD(15)
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    UNIT_PAD(19)
    virtual int canAttackUnit(RGE_Static_Object*);
    UNIT_PAD(21)
    virtual int stopObject(int);
    virtual int attackObject(int, int);
    UNIT_PAD(24) UNIT_PAD(25)
    virtual int gatherObject(int, int);
    UNIT_PAD(27) UNIT_PAD(28) UNIT_PAD(29) UNIT_PAD(30) UNIT_PAD(31)
    virtual int explore(int, int, int);
    UNIT_PAD(33) UNIT_PAD(34) UNIT_PAD(35)
    virtual int moveTo(float, float, float, float, int);
    UNIT_PAD(37) UNIT_PAD(38) UNIT_PAD(39) UNIT_PAD(40)
    virtual int runAwayFromAttackers(int);
    UNIT_PAD(42) UNIT_PAD(43) UNIT_PAD(44) UNIT_PAD(45)
    UNIT_PAD(46) UNIT_PAD(47)
    virtual int convertToLOSResourceType(int);
    UNIT_PAD(49) UNIT_PAD(50) UNIT_PAD(51) UNIT_PAD(52)
    virtual int processIdle(int);
    virtual int processNotify(NotifyEvent*, ulong);

    RGE_Static_Object* objectValue;
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    void* orderQueueValue;
    int notifyQueueSizeValue;
    int notifyQueueMaxSizeValue;
    void* notifyQueueValue;
    int currentOrderValue;
    int currentOrderPriorityValue;
    int currentActionValue;
    int currentTargetValue;
    int currentTargetTypeValue;
    float currentTargetXValue;
    float currentTargetYValue;
    float currentTargetZValue;
    float desiredTargetDistanceValue;
    int defendTargetValue;
    int lastOrderValue;
    int lastActionValue;
    int lastTargetValue;
    int lastTargetTypeValue;
    AttackingUnits attackingUnitsValue;
    char waypointGap[0x80];
    int waypointQueueSizeValue;
    ulong lastUpdateTimeValue;
    ulong idleTimerValue;
    ulong adjustedIdleTimeoutValue;
    ulong idleTimeoutValue;
    ulong secondaryTimerValue;
    ulong lookAroundTimerValue;
    ulong lookAroundTimeoutValue;
    float lastWorldPositionX;
    float lastWorldPositionY;
    float lastWorldPositionZ;
    char gap_11C[4];
    float defenseBufferValue;
    int* importantObjects;
    int numberImportantObjects;
    void* playStatus;
    uchar stopAfterTargetKilledValue;

    RGE_Static_Object* lookupObject(int id);
    void purgeNotifyQueue(ulong flags);
    void askForHelp(int id);
    int addToWaypointQueue(int x, int y);
    uchar visibleStatus(void* map, int x, int y);
    void removeCurrentTarget();
    void setCurrentAction(int value);
};
#undef UNIT_PAD

extern "C" {
    extern void* actionFile;
    extern const char str_fmt_stopObject[];
    extern const char str_aiuaimod_path[];
    int fprintf(void*, const char*, ...);
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* block);
}

#define LOG_STOP(line) do { \
    if (actionFile != 0) { \
        int stopObjectId = -1; \
        if (this->objectValue != 0) stopObjectId = this->objectValue->id; \
        fprintf(actionFile, str_fmt_stopObject, stopObjectId, str_aiuaimod_path, (line)); \
    } \
} while (0)

#define ADD_ATTACKER(attackerId) do { \
    int attackerCount = this->attackingUnitsValue.numberValue; \
    if (this->attackingUnitsValue.maximumSizeValue - 1 < attackerCount) { \
        int newSize = attackerCount + 1; \
        int* newValue = (int*)operator_new(newSize * 4); \
        if (newValue != 0) { \
            int copyIndex = 0; \
            if (this->attackingUnitsValue.maximumSizeValue > 0) { \
                do { \
                    if (newSize <= copyIndex) break; \
                    newValue[copyIndex] = this->attackingUnitsValue.value[copyIndex]; \
                    ++copyIndex; \
                } while (copyIndex < this->attackingUnitsValue.maximumSizeValue); \
            } \
            operator_delete(this->attackingUnitsValue.value); \
            this->attackingUnitsValue.value = newValue; \
            this->attackingUnitsValue.maximumSizeValue = newSize; \
        } \
    } \
    this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = (attackerId); \
    this->attackingUnitsValue.numberValue = this->attackingUnitsValue.numberValue + 1; \
} while (0)

#define REMOVE_ATTACKER(attackerId) do { \
    int removeCount = this->attackingUnitsValue.numberValue; \
    int removeIndex = 0; \
    if (removeCount > 0) { \
        while (removeIndex < this->attackingUnitsValue.maximumSizeValue) { \
            if (this->attackingUnitsValue.value[removeIndex] == (attackerId)) break; \
            ++removeIndex; \
            if (removeCount <= removeIndex) break; \
        } \
    } \
    if (removeIndex < removeCount && removeIndex < this->attackingUnitsValue.maximumSizeValue) { \
        if (removeIndex < this->attackingUnitsValue.maximumSizeValue - 1) { \
            do { \
                this->attackingUnitsValue.value[removeIndex] = \
                    this->attackingUnitsValue.value[removeIndex + 1]; \
                ++removeIndex; \
            } while (removeIndex < this->attackingUnitsValue.maximumSizeValue - 1); \
        } \
        removeCount = this->attackingUnitsValue.numberValue - 1; \
        this->attackingUnitsValue.numberValue = removeCount; \
        if (removeCount < 0) this->attackingUnitsValue.numberValue = 0; \
    } \
} while (0)

#define PROCESS_ORDER_NOTIFY(stopFlag, lineA, lineB, lineC, lineD, lineE, lineF) do { \
    int order = this->currentOrderValue; \
    if (order == 700 && event->p1 == 600) { \
        if (this->processIdle(0) != 5) return 2; \
        if (this->currentOrderValue == 0x2D5 || \
            this->objectValue->owner->computerPlayer() == 0) { \
            this->removeCurrentTarget(); \
            LOG_STOP(lineA); \
            this->stopObject(stopFlag); \
            return 2; \
        } \
        if (this->moveTo(this->currentTargetXValue, this->currentTargetYValue, \
                         this->currentTargetZValue, \
                         this->desiredTargetDistanceValue + 2.0f, 1) != 0) { \
            int oldOrder = this->currentOrderValue; \
            this->currentOrderValue = -1; \
            this->currentOrderPriorityValue = -1; \
            this->lastOrderValue = oldOrder; \
            return 2; \
        } \
        this->removeCurrentTarget(); \
        LOG_STOP(lineB); \
        this->stopObject(stopFlag); \
        return 2; \
    } \
    if (order == -1) { \
        if (this->currentActionValue == event->p1) { \
            this->removeCurrentTarget(); \
            LOG_STOP(lineC); \
            this->stopObject(stopFlag); \
            return 2; \
        } \
    } else if (this->currentActionValue + 100 == order) { \
        if (this->currentActionValue == event->p1) { \
            this->removeCurrentTarget(); \
            LOG_STOP(lineD); \
            this->stopObject(stopFlag); \
            return 2; \
        } \
    } \
    if (order == 0x2D4 && event->p1 == 0x262) { \
        this->removeCurrentTarget(); \
        LOG_STOP(lineE); \
        this->stopObject(0); \
        this->notifyCommander(event); \
        return 2; \
    } \
    if (order == 0x2BD && event->p1 == 0x262) { \
        this->setCurrentAction(-1); \
        return 2; \
    } \
    if (order != 0x2D5 || event->p1 != 600) return 2; \
    this->removeCurrentTarget(); \
    LOG_STOP(lineF); \
    this->stopObject(1); \
    return 2; \
} while (0)

int UnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType) {
    case 500:
    case 527:
        this->notifyCommander(event);

        if (event->p2 < 1) {
            this->objectValue->owner->notify(this->objectValue->id,
                                             this->objectValue->id, 0x209,
                                             event->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        if (this->attackingUnitsValue.numberValue == 0 ||
            this->objectValue->owner->computerPlayer() == 1) {
            this->objectValue->owner->notify(this->objectValue->id,
                                             this->objectValue->id, 0x201,
                                             event->caller, 0, 0);
        }

        {
            int i = 0;
            int count = this->attackingUnitsValue.numberValue;
            int found = 0;
            if (count > 0) {
                do {
                    if (this->attackingUnitsValue.maximumSizeValue <= i) break;
                    if (this->attackingUnitsValue.value[i] == event->caller) {
                        found = 1;
                        break;
                    }
                    ++i;
                } while (i < count);
            }
            if (found == 0 && this->objectValue->owner->computerPlayer() == 0 &&
                this->currentTargetValue != event->caller) {
                this->askForHelp(event->caller);
            }
        }

        {
            int i = 0;
            int count = this->attackingUnitsValue.numberValue;
            int found = 0;
            if (count > 0) {
                do {
                    if (this->attackingUnitsValue.maximumSizeValue <= i) break;
                    if (this->attackingUnitsValue.value[i] == event->caller) {
                        found = 1;
                        break;
                    }
                    ++i;
                } while (i < count);
            }
            if (found == 0) ADD_ATTACKER(event->caller);
        }

        this->objectValue->setUnderAttack(1);
        if (this->currentOrderValue != 0x2D5 && this->currentOrderValue != -1 &&
            this->objectValue->owner->computerPlayer() == 0) {
            return 2;
        }
        if (this->currentOrderValue == 0x2D5) return 2;

        {
            RGE_Static_Object* attacker = this->lookupObject(event->caller);
            if (attacker == 0) return 2;
            if (attacker->owner->id == this->objectValue->owner->id) return 2;

            if (this->currentActionValue == 0x25B &&
                this->runAwayFromAttackers(1) == 1) {
                return 3;
            }

            RGE_Static_Object* target = 0;
            if (this->currentTargetValue != -1) {
                target = this->lookupObject(this->currentTargetValue);
            }

            if (target != 0) {
                short group = target->master_obj->object_group;
                short masterId = target->master_obj->id;
                if ((group == 3 || group == 0x1B) &&
                    masterId != 0x4F && masterId != 199 && masterId != 0x45 &&
                    this->objectValue->owner->computerPlayer() == 0) {
                    if (this->canAttackUnit(attacker) != 1) {
                        if (this->currentActionValue != 0x262) {
                            this->runAwayFromAttackers(1);
                        }
                        return 3;
                    }
                    if (this->objectValue->inAttackRange(attacker) != 1) {
                        float pathDistance = this->objectValue->weaponRange(0, 0, -1, -1);
                        if (this->objectValue->canPath((int)attacker, pathDistance,
                                                       0, -1, -1, -1) != 1) {
                            if (this->currentActionValue != 0x262) {
                                this->runAwayFromAttackers(1);
                            }
                            return 3;
                        }
                    }
                    if (this->attackObject(attacker->id, 1) == 1 &&
                        this->currentOrderValue != 0x2BC) {
                        this->currentOrderValue = -1;
                        return 3;
                    }
                } else {
                    if (this->objectValue->owner->computerPlayer() == 0) return 2;
                    if (target->master_obj->id == 0x114) return 2;

                    float targetHealth = target->damageCapability(this->objectValue);
                    float healthRatio = 0x46C35000;
                    if (targetHealth > 0.0f) {
                        healthRatio = target->damageCapability() / targetHealth;
                    }
                    if (this->objectValue->damageCapability(target) != 1.0f) {
                        return 2;
                    }
                    if (event->p2 <= healthRatio) return 2;
                    if (this->objectValue->inAttackRange(target) != 1) {
                        float pathDistance = this->objectValue->weaponRange(0, 0, -1, -1);
                        if (this->objectValue->canPath((int)target, pathDistance,
                                                       0, -1, -1, -1) != 1) {
                            return 2;
                        }
                    }
                    this->attackObject(attacker->id, 1);
                    return 2;
                }
            } else {
                if (this->canAttackUnit(attacker) == 1 &&
                    this->objectValue->inAttackRange(attacker) == 1) {
                    if (this->attackObject(attacker->id, 1) == 1 &&
                        this->currentOrderValue != 700) {
                        this->currentOrderValue = -1;
                        return 3;
                    }
                } else if (this->currentActionValue != 0x262) {
                    this->runAwayFromAttackers(1);
                }
                return 3;
            }
        }
        return 3;

    case 505:
        PROCESS_ORDER_NOTIFY(1, 0x12E9, 0x12F3, 0x130D, 0x1304, 0x1317, 0x1325);
    case 506:
        PROCESS_ORDER_NOTIFY(0, 0x128B, 0x129B, 0x12B7, 0x12AF, 0x12C0, 0x12CD);
    case 507:
        PROCESS_ORDER_NOTIFY(1, 0x1341, 0x134B, 0x1365, 0x135C, 0x136F, 0x137D);

    case 508:
        {
            RGE_Static_Object* target = this->lookupObject(this->currentTargetValue);
            if (target != 0) {
                int targetY = (int)target->world_y;
                int targetX = (int)target->world_x;
                uchar visible = this->visibleStatus(this->objectValue->owner->visibleMap,
                                                     targetX, targetY);
                if (target->owner->id != 0 && visible != 0x0F) {
                    float targetZ = this->currentTargetZValue;
                    int candidate = this->bestUnitToAttack(1, 0, 0);
                    if (candidate != -1 && candidate != this->currentTargetValue &&
                        this->attackObject(candidate, 1) == 1) {
                        this->currentOrderValue = -1;
                        return 3;
                    }
                    if (this->objectValue->owner->computerPlayer() == 0 &&
                        this->moveTo(this->currentTargetXValue,
                                     this->currentTargetYValue, targetZ, 0, 1) == 1) {
                        int oldOrder = this->currentOrderValue;
                        this->currentOrderValue = -1;
                        this->lastOrderValue = oldOrder;
                        this->currentOrderPriorityValue = -1;
                        return 3;
                    }
                }
            }
            this->removeCurrentTarget();
            LOG_STOP(0x1269);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }

    case 510:
        this->objectValue->stopAction();
        this->removeCurrentTarget();
        LOG_STOP(0x13F9);
        this->stopObject(1);
        return 2;

    case 514:
        {
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
            } else {
                if (action != 0x261) return 2;
                int resource = this->currentTargetTypeValue;
                if (resource == -1) resource = this->lastTargetTypeValue;
                int targetId = this->convertToLOSResourceType(resource);
                if (targetId == -1) {
                    targetId = this->closestObject(resource, -1, -1, -1, 0);
                } else {
                    targetId = this->closestResourceObject(targetId, 0);
                }
                if (targetId == -1) {
                    this->removeCurrentTarget();
                    LOG_STOP(0x13DA);
                    this->stopObject(1);
                    this->notifyCommander(event);
                    return 2;
                }
                if (this->gatherObject(targetId, 1) == 1) return 3;
                this->removeCurrentTarget();
                LOG_STOP(0x13CE);
            }
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }

    case 523:
        this->objectValue->stopAction();
        this->removeCurrentTarget();
        LOG_STOP(0x13E7);
        this->stopObject(1);
        this->purgeNotifyQueue(param_2);
        this->orderQueueSizeValue = 0;
        {
            RGE_Static_Object* commander =
                this->lookupObject(*(int*)((char*)this->objectValue + 0x78));
            if (commander != 0) {
                commander->commanderRemoveFromGroup(this->objectValue->id);
            }
        }
        return 2;

    case 600:
        {
            int i = 0;
            int count = this->attackingUnitsValue.numberValue;
            int found = 0;
            if (count > 0) {
                do {
                    if (this->attackingUnitsValue.maximumSizeValue <= i) break;
                    if (this->attackingUnitsValue.value[i] == event->caller) {
                        found = 1;
                        break;
                    }
                    ++i;
                } while (i < count);
            }
            if (found == 0) ADD_ATTACKER(event->caller);
        }
        this->objectValue->setUnderAttack(1);
        return 2;

    case 699:
        REMOVE_ATTACKER(event->caller);
        return 2;

    default:
        // The jump table routes the unused in-range notifications to the
        // ordinary return block. Only the out-of-range and 501 paths stop.
        if (event->mType >= 502 && event->mType <= 698) return 2;
        this->removeCurrentTarget();
        LOG_STOP(0x1439);
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;
    }
}

#undef REMOVE_ATTACKER
#undef ADD_ATTACKER
#undef LOG_STOP
