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

#include <stdio.h>

typedef unsigned char uchar;

template <class T>
class ManagedArrayInt {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size;
                     ++i) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int remove(int valueToRemove) {
        int i = 0;
        int max = this->maximumSizeValue;

        for (; i < max; ++i) {
            if (this->value[i] == valueToRemove) {
                break;
            }
        }

        if (i >= max) {
            return 0;
        }

        --max;
        if (i < max) {
            do {
                this->value[i] = this->value[i + 1];
                ++i;
            } while (i < this->maximumSizeValue - 1);
        }

        int number = this->numberValue - 1;
        this->numberValue = number;
        if (number < 0) {
            this->numberValue = 0;
        }
        return 1;
    }
};

void* operator_new(unsigned int size);
void operator_delete(void* block);

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    unsigned char have_action();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayer();
};

class UnitAIModule;
class RGE_Static_Object;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();

    long id;                                      // +0x04
    void* master_obj;                             // +0x08
    RGE_Player* owner;                            // +0x0C
    char gap_10[0x20];                            // +0x10
    float hitPoints;                              // +0x30
    char gap_34[4];                               // +0x34
    float world_x;                                // +0x38
    float world_y;                                // +0x3C
    float world_z;                                // +0x40
    float attribute_amount_held;                  // +0x44
    unsigned char object_state;                   // +0x48
    char gap_49[7];                               // +0x49
    void* player_object_node;                     // +0x50
    ManagedArrayInt<int> pathingGroupMembers;     // +0x54
    ManagedArrayInt<int> groupMembers;            // +0x64
    UnitAIModule* unitAIValue;                    // +0x74
    int groupCommanderValue;                      // +0x78
    int zoneMapIndex;                              // +0x7C
    float groupRangeValue;                         // +0x80
    char gap_84[0x100];                            // +0x84
    RGE_Action_List* actions;                     // +0x184

    UnitAIModule* unitAI();
    float distance_to_object(RGE_Static_Object* object);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner() const;
    virtual int order(int, int, int, int, float, float, float, float,
                      int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
    virtual void search();
    virtual int importantWhenDead(int);
    virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*);
    virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int stopObject(int);
    virtual int attackObject(int, int);
    virtual int attackRoundupObject(int);
    virtual int huntObject(int, int);
    virtual int gatherObject(int, int);
    virtual int convertObject(int, int);
    virtual int healObject(int, int);
    virtual int repairObject(int, int);
    virtual int buildObject(int, int);
    virtual int tradeWithObject(int, int);
    virtual int explore(int, int, int);
    virtual int enterObject(int, int);
    virtual int unload(int, float, float);
    virtual int transportObject(float, float, float, int);
    virtual int moveTo(int, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(float, float, float, float);
    virtual int evasiveMoveTo(float, float, float, int);
    virtual int intelligentEvasiveMoveTo(float, float, float, int, int);
    virtual int runAwayFromAttackers(int);
    virtual int followObject(int, float, int);
    virtual int defendObject(int, float, int);
    virtual int defendPosition(float, float, float, int);
    virtual int seekAndDestroy(int, int, int, int);
    virtual int exploreAndDestroy(int, int, int);
    virtual int importantObject(int);
    virtual int convertToLOSResourceType(int);
    virtual int canConvert(int);
    virtual int processOrder(void*, int);
    virtual int processNotify(void*, unsigned long);
    virtual void processGroupNotify(void*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);
    virtual int update(unsigned long);

    RGE_Static_Object* objectValue;                // +0x04
    int moodValue;                                 // +0x08
    int objectCategoryValue;                       // +0x0C
    int orderQueueSizeValue;                       // +0x10
    int orderQueueMaxSizeValue;                    // +0x14
    void* orderQueueValue;                         // +0x18
    int notifyQueueSizeValue;                      // +0x1C
    int notifyQueueMaxSizeValue;                   // +0x20
    void* notifyQueueValue;                        // +0x24
    int currentOrderValue;                         // +0x28
    int currentOrderPriorityValue;                 // +0x2C
    int currentActionValue;                        // +0x30
    int currentTargetValue;                        // +0x34
    int currentTargetTypeValue;                    // +0x38
    float currentTargetXValue;                     // +0x3C
    float currentTargetYValue;                     // +0x40
    float currentTargetZValue;                     // +0x44
    float desiredTargetDistanceValue;              // +0x48
    int defendTargetValue;                          // +0x4C
    int lastOrderValue;                             // +0x50
    int lastActionValue;                            // +0x54
    int lastTargetValue;                            // +0x58
    int lastTargetTypeValue;                        // +0x5C
    ManagedArrayInt<int> attackingUnitsValue;      // +0x60
    char waypointGap[0x80];                         // +0x70
    int waypointQueueSizeValue;                    // +0xF0
    unsigned long lastUpdateTimeValue;              // +0xF4
    unsigned long idleTimerValue;                  // +0xF8
    unsigned long adjustedIdleTimeoutValue;        // +0xFC
    unsigned long idleTimeoutValue;                // +0x100
    unsigned long secondaryTimerValue;              // +0x104
    unsigned long lookAroundTimerValue;            // +0x108
    unsigned long lookAroundTimeoutValue;           // +0x10C
    float lastWorldPositionX;                      // +0x110
    float lastWorldPositionY;                      // +0x114
    float lastWorldPositionZ;                      // +0x118
    char gap_11C[4];                               // +0x11C
    float defenseBufferValue;                      // +0x120
    int* importantObjects;                          // +0x124
    int numberImportantObjects;                     // +0x128
    void* playStatus;                               // +0x12C
    unsigned char stopAfterTargetKilledValue;       // +0x130

    RGE_Static_Object* lookupObject(int id);
    void removeCurrentTarget();
    int currentTarget();
    void purgeNotifyQueue(unsigned long time);
    void updateGroup(unsigned long time);
    void lookAround();
};

#define taskedThisUpdate (*(int*)0x592A48)
#define searchedThisUpdate (*(int*)0x592A4C)
#define numberVisibleObjects (*(int*)0x592A50)
#define numberDifferentPlayerObjectsVisible (*(int*)0x592A54)
#define actionFile (*(FILE**)0x62C4CC)
#define actionFormat ((const char*)0x57F964)
#define actionSource ((const char*)0x57F980)

int UnitAIModule::update(unsigned long param_1)
{
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

    int invalidValue = -1;
    if (this->currentTargetValue != invalidValue) {
        RGE_Static_Object* target =
            this->lookupObject(this->currentTargetValue);
        if (target == 0) {
            this->currentTargetValue = invalidValue;
            if (this->currentActionValue == 600) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue == 0) {
                        objectID = invalidValue;
                    } else {
                        objectID = this->objectValue->id;
                    }
                    fprintf(actionFile, actionFormat, objectID,
                            actionSource, 0x306);
                }
                this->stopObject(1);
                this->idleTimerValue = this->idleTimeoutValue;
            }
        } else {
            if (this->objectValue->object_state == 2 && target->object_state > 2) {
                if (this->actionRequiresLiveTarget(this->currentActionValue) == 1) {
                    this->stopAfterTargetKilledValue = 0;
                    if (this->currentActionValue == 600) {
                        int idleResult = this->processIdle(0);
                        int currentOrder = this->currentOrderValue;
                        if (idleResult == 5) {
                            if (currentOrder != 0x2D5) {
                                if (this->moveTo(
                                        this->currentTargetXValue,
                                        this->currentTargetYValue,
                                        this->currentTargetZValue,
                                        this->objectValue->weaponRange()) == 0) {
                                    this->removeCurrentTarget();
                                    if (actionFile != 0) {
                                        long objectID;
                                        if (this->objectValue == 0) {
                                            objectID = invalidValue;
                                        } else {
                                            objectID = this->objectValue->id;
                                        }
                                        fprintf(actionFile, actionFormat,
                                                objectID, actionSource, 0x335);
                                    }
                                    this->stopObject(1);
                                } else {
                                    this->currentOrderValue = -1;
                                    this->lastOrderValue = currentOrder;
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
                            long objectID;
                            if (this->objectValue == 0) {
                                objectID = invalidValue;
                            } else {
                                objectID = this->objectValue->id;
                            }
                            fprintf(actionFile, actionFormat, objectID,
                                    actionSource, 0x356);
                        }
                        this->stopObject(1);
                    }
                }
            }

            if (this->objectValue->owner->computerPlayer() == 1 &&
                this->currentOrderPriorityValue != -1 &&
                this->currentOrderPriorityValue < 100) {
                int distance = (int)(100.0f /
                    this->objectValue->distance_to_object(target));
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
        int i = 0;
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
            } while (i < this->attackingUnitsValue.numberValue);
        }
    }

    this->lastWorldPositionX = this->objectValue->world_x;
    this->lastWorldPositionY = this->objectValue->world_y;
    this->lastWorldPositionZ = this->objectValue->world_z;
    this->idleTimerValue += param_1;
    this->secondaryTimerValue += param_1;
    this->lookAroundTimerValue += param_1;

    if (this->notifyQueueSizeValue > 0) {
        int i = 0;
        int offset = 0;
        do {
            int result = this->processNotify(
                (char*)this->notifyQueueValue + offset, param_1);
            if (result == 4) {
                goto update_error;
            }
            if (result == 3) {
                break;
            }
            ++i;
            offset += 0x18;
        } while (i < this->notifyQueueSizeValue);
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

    if (this->currentActionValue == -1 &&
        this->orderQueueSizeValue > 0) {
        int i = 0;
        int offset = 0;
        do {
            int result = this->processOrder(
                (char*)this->orderQueueValue + offset, i);
            if (result == 1) {
                break;
            }
            ++i;
            offset += 0x24;
        } while (i < this->orderQueueSizeValue);
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
        this->lookAroundTimeoutValue < this->lookAroundTimerValue) {
        this->lookAround();
    }

    return 1;

update_error:
    this->purgeNotifyQueue(param_1);
    return 0;
}

#undef taskedThisUpdate
#undef searchedThisUpdate
#undef numberVisibleObjects
#undef numberDifferentPlayerObjectsVisible
#undef actionFile
#undef actionFormat
#undef actionSource
