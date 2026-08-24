// VA: 00504E10 TribeCivilianUnitAIModule::processNotify
// PDB donor: taiuaimd.cpp lines 800-1237
// Attempt log:
// BINARY NOTE: The original keeps event in EBX, uses indexed bounded list scans,
//   and places the owner-id-zero order arm before the enemy arm.
// The same-TU virtual surfaces and FILE/fprintf declarations preserve the proven calls.
// Probe: reversing the owner branch recovered the original 2478-byte boundary and
//   raised shape from 76.74% to 87.18%; ordering the resource arm raised it to 87.83%.
// Probe H26: one late return label for the four proven guard jumps raised shape to
//   88.57%, matched the 16-return CFG, and reduced positional diff to 2067 bytes.
// Probe H27: actionFile-gated local stop/notify returns restored both 0x3aa/0x3b9
//   log blocks. Calls then matched 78/78, shape reached 88.96%, and diff reached 1820.
// Probe H30: direct ternary closestObject arguments reduced diff to 1594, but added
//   one fprintf and one stopObject call. Reject it for the hard call-count mismatch.
// BINARY NOTE: H27 still emits 74 bytes past the target boundary. Its ordered calls
//   remain -3/+3, with the 0x261 argument setup and one relocated cold tail unresolved.
// unresolved: final clean source is pinned after H27 validation; no exact match.

#include <stdio.h>
typedef unsigned char uchar;
typedef unsigned long ulong;

#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Object_Node;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class RGE_Sprite;
class RGE_Color_Table;
class RGE_Action_Object;
class RGE_Armor_Weapon_Info;
class RGE_Sound;
class RGE_Visible_Map;
class XYZBYTEPoint;
class XYZPoint;
class XYPoint;
class Path;
class ManagedArrayInt;
class OrderEvent;
class AIPlayStatus;

extern FILE* actionFile;
extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);

class NotifyEvent {
public:
    int caller;                         // +0x00
    int recipient;                      // +0x04
    int mType;                          // +0x08
    long p1;                            // +0x0C
    long p2;                            // +0x10
    long p3;                            // +0x14
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    uchar master_type;                  // +0x04
    uchar gap_05[3];                    // +0x05
    char* name;                         // +0x08
    short string_id;                    // +0x0C
    short string_id2;                   // +0x0E
    short id;                            // +0x10
    short copy_id;                      // +0x12
    short object_group;                 // +0x14
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(void*, short, short, uchar);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, uchar);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar);
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
    virtual uchar facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(uchar);
    virtual uchar waitingToMove();
    virtual uchar actionState();
    virtual uchar keepGatheringWhenObjectIsOut(int);
    virtual uchar produceWhenKilledBy(int);
    virtual uchar useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);

    long id;                            // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                  // +0x0C
    char gap_10[0x28];                  // +0x10 .. +0x37
    float world_x;                      // +0x38
    float world_y;                      // +0x3C
    float world_z;                      // +0x40

    float distance_to_object(RGE_Static_Object* other);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, uchar);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual uchar command_make_move(RGE_Static_Object*, float, float);
    virtual uchar command_make_work(RGE_Static_Object*, float, float);
    virtual uchar command_make_do(RGE_Static_Object*, float, float);
    virtual uchar command_stop();
    virtual uchar command_place_object(short, float, float, float);
    virtual uchar command_add_attribute(int, float);
    virtual uchar command_give_attribute(int, int, float);
    virtual uchar command_formation(int);
    virtual uchar command_stand_ground();
    virtual uchar command_create_group(int, int*, int, float);
    virtual uchar command_add_to_group(int, int, float);
    virtual uchar command_remove_from_group(int, int);
    virtual uchar command_destroy_group(int);
    virtual uchar command_resign(int, int);
    virtual uchar command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);

    int computerPlayer();

    int computerPlayerValue;            // +0x04
    char gap_08[0x34];                  // +0x08 .. +0x3B
    RGE_Game_World* world;              // +0x3C
    char gap_40[0x0A];                  // +0x40 .. +0x49
    short id;                            // +0x4A
};

class RGE_Game_World {
public:
    int difficultyLevel();
};

struct AttackingUnits {
    int* value;                         // +0x00
    int numberValue;                    // +0x04
    int desiredNumberValue;             // +0x08
    int maximumSizeValue;               // +0x0C
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(NotifyEvent*);
    virtual int notifyCommander(int, int, int, long, long, long);
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
    virtual int moveTo(float, float, float, float, int);
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
    virtual int processOrder(OrderEvent*, int);
    virtual int processNotify(NotifyEvent*, ulong);
    virtual void processGroupNotify(NotifyEvent*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();

    RGE_Static_Object* objectValue;             // +0x04
    int moodValue;                              // +0x08
    int objectCategoryValue;                    // +0x0C
    int orderQueueSizeValue;                    // +0x10
    int orderQueueMaxSizeValue;                 // +0x14
    OrderEvent* orderQueueValue;                // +0x18
    int notifyQueueSizeValue;                   // +0x1C
    int notifyQueueMaxSizeValue;                // +0x20
    NotifyEvent* notifyQueueValue;              // +0x24
    int currentOrderValue;                      // +0x28
    int currentOrderPriorityValue;              // +0x2C
    int currentActionValue;                     // +0x30
    int currentTargetValue;                     // +0x34
    int currentTargetTypeValue;                 // +0x38
    float currentTargetXValue;                  // +0x3C
    float currentTargetYValue;                  // +0x40
    float currentTargetZValue;                  // +0x44
    float desiredTargetDistanceValue;           // +0x48
    int defendTargetValue;                      // +0x4C
    int lastOrderValue;                         // +0x50
    int lastActionValue;                        // +0x54
    int lastTargetValue;                        // +0x58
    int lastTargetTypeValue;                    // +0x5C
    AttackingUnits attackingUnitsValue;         // +0x60
    char waypointQueue[0x80];                   // +0x70 .. +0xEF
    int waypointQueueSizeValue;                 // +0xF0
    ulong lastUpdateTimeValue;                  // +0xF4
    ulong idleTimerValue;                       // +0xF8
    ulong adjustedIdleTimeoutValue;             // +0xFC
    ulong idleTimeoutValue;                     // +0x100
    ulong secondaryTimerValue;                  // +0x104
    ulong lookAroundTimerValue;                 // +0x108
    ulong lookAroundTimeoutValue;               // +0x10C
    float lastWorldPositionX;                   // +0x110
    float lastWorldPositionY;                   // +0x114
    float lastWorldPositionZ;                   // +0x118
    char gap_11C[4];                            // +0x11C
    float defenseBufferValue;                   // +0x120
    int* importantObjects;                      // +0x124
    int numberImportantObjects;                 // +0x128
    AIPlayStatus* playStatus;                   // +0x12C
    uchar stopAfterTargetKilledValue;           // +0x130

    void removeCurrentTarget();
    RGE_Static_Object* lookupObject(int id);
    void purgeNotifyQueue(ulong flags);
    void askForHelp(int id);
    int addToWaypointQueue(int x, int y);
};

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    int processNotify(NotifyEvent* event, ulong flags);
};
#endif

int TribeCivilianUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType - 0x1f4) {
    case 0x1b:
#ifdef TAIUAIMD_COMPLETE_TU
        if (taiuaimd_world_difficulty(this->objectValue->owner->world) >= 3) {
#else
        if (this->objectValue->owner->world->difficultyLevel() >= 3) {
#endif
            return 2;
        }
        // Intentional fall-through: 0x20f is the high-priority spelling of 0x1f4.
    case 0: {
        if (event->p2 <= 0) {
#ifdef TAIUAIMD_COMPLETE_TU
            taiuaimd_player_notify(this->objectValue->owner,
#else
            this->objectValue->owner->notify(
#endif
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
#ifdef TAIUAIMD_COMPLETE_TU
                taiuaimd_player_notify(this->objectValue->owner,
#else
                this->objectValue->owner->notify(
#endif
                    this->objectValue->id, this->objectValue->id, 0x201,
                    event->caller, 0, 0);
            }
        } else if (this->attackingUnitsValue.numberValue == 0) {
#ifdef TAIUAIMD_COMPLETE_TU
            taiuaimd_player_notify(this->objectValue->owner,
#else
            this->objectValue->owner->notify(
#endif
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
#ifdef TAIUAIMD_COMPLETE_TU
        int state = taiuaimd_object_action_state(this->objectValue);
#else
        int state = this->objectValue->actionState();
#endif

        if (this->currentOrderValue == 0x2c6 && speed > 0.0f) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2bc) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2c9 && state == 0x0c &&
            targetObject != 0 && targetObject->master_obj->object_group == 10 &&
#ifdef TAIUAIMD_COMPLETE_TU
            ((RGE_Static_Object*)(*(long*)((char*)event + 0x0C)))->owner->id == 0) {
#else
            ((RGE_Static_Object*)event->p1)->owner->id == 0) {
#endif
            goto return_two;
        }
        if (this->currentOrderValue == 0x2ce) {
            goto return_two;
        }

#ifdef TAIUAIMD_COMPLETE_TU
        if (((RGE_Static_Object*)(*(long*)((char*)event + 0x0C)))->owner->id == 0) {
#else
        if (((RGE_Static_Object*)event->p1)->owner->id == 0) {
#endif
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
#ifdef TAIUAIMD_COMPLETE_TU
        if (this->currentActionValue == *(long*)((char*)event + 0x0C)) {
#else
        if (this->currentActionValue == event->p1) {
#endif
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
#ifdef TAIUAIMD_COMPLETE_TU
        if (this->currentActionValue == *(long*)((char*)event + 0x0C)) {
#else
        if (this->currentActionValue == event->p1) {
#endif
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
#ifdef TAIUAIMD_COMPLETE_TU
                taiuaimd_object_can_path(this->objectValue, result, 1.0f, 0, 0, -1, -1) == 1 &&
#else
                this->objectValue->canPath(result, 1.0f, 0, 0, -1, -1) == 1 &&
#endif
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
