#ifndef AOE1_AIUAIMOD_CONTEXT_H
#define AOE1_AIUAIMOD_CONTEXT_H

// Shared declarations for the PDB aiuaimod.cpp source module.
// PDB and exact owners prove the 0x134-byte UnitAIModule layout.

typedef unsigned char uchar;

struct OrderEvent {
    int issuer;
    int orderType;
    int priority;
    int target;
    int targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
};

struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    long p1;
    long p2;
    long p3;
};

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char padding[3];
};

struct XYZPoint {
    int x;
    int y;
    int z;
};

struct VisibleUnitEntry {
    int object_id;
    unsigned char distance;
    unsigned char owner;
    unsigned char gap_06[2];
};

template <class T>
class ManagedArrayInt {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArrayInt(int maxSize) {
        value = 0;
        numberValue = 0;
        desiredNumberValue = 0;
        maximumSizeValue = maxSize;
        value = new T[maxSize];
    }

    ~ManagedArrayInt() {
        if (value) {
            delete value;
            value = 0;
        }
        numberValue = 0;
        desiredNumberValue = 0;
        maximumSizeValue = 0;
    }

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

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int newSize);

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            T* newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < newSize;
                     i++) {
                    newValue[i] = this->value[i];
                }
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
    }
};

void* operator_new(unsigned int size);
void operator_delete(void* block);

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    unsigned char have_action();
};

class RGE_Game_World;
class RGE_Map;
class UnitAIModule;
class RGE_Static_Object;
class RGE_Player;
class AIPlay;
class AIPlayPhase;
class AIPlayStatus;
class RGE_Object_Node;
class Visible_Unit_Manager;
class Visible_Resource_Manager;
class RGE_Master_Combat_Object;
struct XYZBYTEPoint;

class AIPlayBook {
public:
    AIPlay* play(int playNumber);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    int world_time;
    char gap_08[0x20];
    RGE_Map* map;
    char gap_2C[0x14];
    RGE_Player** players;
    char gap_44[0x5C];
    AIPlayBook* playbook;

    RGE_Static_Object* object(int);
    int difficultyLevel();
};

class RGE_Map {
public:
    char gap_00[0x08];
    int map_width;
    int map_height;
};

class RGE_Base_Game {
public:
    int scenarioGame();
    int singlePlayerGame();
};

struct AIPlayGrouping {
    int id;
    unsigned char groupValue;
    unsigned char typeValue;
    char gap_06[2];
};

class AIPlayPhaseTrigger {
public:
    unsigned char typeValue;
    char gap_01[3];
    int value1Value;
    int value2Value;
    unsigned char phaseValue;
    unsigned char nextPhaseValue;
    char gap_0E[2];
    int randomnessValue;
};

class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    char gap_02[2];
    int value1Value;
    int value2Value;
    int value3Value;
};

class AIPlayPhase {
public:
    AIPlayPhaseTrigger* trigger(int index);
    AIPlayPhaseCommand* command(int index);
};

class AIPlay {
public:
    AIPlayPhase* phase(int phaseNumber);
    int groupGivenCommandOnPhase(int group, int commandType, int phaseNumber);
    int fillGroups(AIPlayStatus* status, int* groupList, int groupCount,
                   RGE_Game_World* world);
    int gatherTolerance(int group, int phaseNumber);
};

class AIPlayStatus {
public:
    AIPlayGrouping groupings[50];
    int playNumberValue;
    int targetValue;
    int originalPointX;
    int originalPointY;
    int originalPointZ;
    char gap_1A4[0x14];
    unsigned char currentPhaseValue;
    char gap_1B9[3];
    int savedAttackerValue;
    int lastPhaseChangeTimeValue;
    char pad_1C4[4];

    AIPlayStatus();
    void copy(AIPlayStatus*);
    void load(int fd);
    void save(int fd);
    unsigned char group(int id);
    int originalHitPoints(int groupNumber);
    void setOriginalHitPoints(int groupNumber, int value);
    void resetHitPoints(int groupNumber, RGE_Game_World* world);
    void removeDeadUnits(int groupNumber, RGE_Game_World* world);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, RGE_Game_World*,
                                    unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    char gap_04[0x0C];
    short id;
    short gap_12;
    union {
        short object_category;
        short object_group;
    };
    char gap_16[0x10];
    union {
        short maximumHitPoints;
        short hp;
    };
    union {
        float defense_buffer;
        float range;
        float los;
        float field_28;
    };
    char gap_2C[4];
    union {
        float hitPoints;
        float radius_x;
    };

};

class Visible_Unit_Manager {
public:
    int GetVisibleUnits(int, int, int, int, int*, int, int*);
};

struct VISIBLE_RESOURCE_REC {
    int object_id;
    unsigned char distance;
    unsigned char zone;
    unsigned char pos_x;
    unsigned char pos_y;
};

class Visible_Resource_Manager {
public:
    VISIBLE_RESOURCE_REC* Get_Closest_Resource(int, int, int, int, int*, int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*,
                               float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                 unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);

    char gap_04[0x34];
    class RGE_Visible_Map* visible;
    RGE_Game_World* world;
    char gap_40[0x08];
    unsigned char type;
    char gap_49;
    short id;
    short attribute_num;
    char gap_4E[0x36];
    unsigned char* relations;
    int unitDiplomacy[16];
    char gap_C8[0x08];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
    char gap_D8[0x38];
    Visible_Resource_Manager* VR_List;

    int computerPlayer();
};

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
    virtual unsigned char heal(float);
    virtual int heal(int, int);
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
    // VC5 reverses these overload entries. The no-argument method is +0x108.
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object*);
#if defined(AOE1_AIUAIMOD_PROCESS_NOTIFY_CONTEXT) || defined(AOE1_AIUAIMOD_COMPLETE_TU)
    virtual float weaponRange();
#if defined(AOE1_AIUAIMOD_COMPLETE_TU)
    virtual float weaponRange(int);
#endif
#else
    virtual float weaponRange(int);
#endif
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(int, int);
    virtual int attack(float, float, float, int);
    virtual int moveTo(int, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(float, float, float, float, int);
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
    virtual int vpad_190();
    // VC5 reverses these overload entries. The integer form stays at +0x194.
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
#if defined(AOE1_AIUAIMOD_PROCESS_NOTIFY_CONTEXT) || defined(AOE1_AIUAIMOD_COMPLETE_TU)
    virtual int canPath(int, float, float*, int, int, int);
#if defined(AOE1_AIUAIMOD_COMPLETE_TU)
    virtual int canPath(int, float);
#endif
#else
    virtual int canPath(int, float);
#endif
    virtual int vpad_19C();
    virtual int vpad_1A0();
    virtual int vpad_1A4();
    virtual int vpad_1A8();
    virtual int vpad_1AC();
    virtual int vpad_1B0();
    virtual int vpad_1B4();
    virtual int groupUnitCommand(int index, int mode);
    virtual int groupUnitCallback(int value);
    virtual int vpad_1C0();
    virtual int vpad_1C4();
    virtual int groupUnitCount();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x10];
    RGE_Static_Object* inside_obj;
    char gap_24[0x0C];
    float hitPoints;
    char gap_34[4];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    char gap_49[7];
    void* player_object_node;
    ManagedArrayInt<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    char gap_84[0x100];
    RGE_Action_List* actions;

    UnitAIModule* unitAI();
    int inGroup();
    unsigned char currentZone();
    unsigned char lookupZone(int, int);
    float distance_to_object(RGE_Static_Object* object);
    float distance_to_position(float x, float y, float z);
#if defined(AOE1_AIUAIMOD_PROCESS_NOTIFY_CONTEXT) || defined(AOE1_AIUAIMOD_COMPLETE_TU)
    int commanderRemoveFromGroup(int objectID);
#endif
};

class __declspec(novtable) UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner() const;
    virtual int order(int, int, int, int, float, float, float, float,
                      int, int, int);
    virtual int notify(int, int, int, long, long, long);
    // VC5 reverses these overload entries. This order emits the six-argument
    // method at +0x18 and the event method at +0x1C.
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
    virtual void logDebug(char*, ...);
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
protected:
    virtual int processOrder(OrderEvent*, int);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual void processGroupNotify(NotifyEvent*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);
#if defined(AOE1_AIUAIMOD_COMPLETE_TU)
    int get_type();
    int find_unit(int, int, int);
    int do_stuff(int, int);
    int call28(int);
    int call40(int, int, int, int, int);
    int call64(int, int);
    int call68(int, int);
#endif

public:
    RGE_Static_Object* objectValue;
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    OrderEvent* orderQueueValue;
    int notifyQueueSizeValue;
    int notifyQueueMaxSizeValue;
    NotifyEvent* notifyQueueValue;
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
    ManagedArrayInt<int> attackingUnitsValue;
    Waypoint waypointQueue[8];
    int waypointQueueSizeValue;
    unsigned long lastUpdateTimeValue;
    unsigned long idleTimerValue;
    unsigned long adjustedIdleTimeoutValue;
    unsigned long idleTimeoutValue;
    unsigned long secondaryTimerValue;
    unsigned long lookAroundTimerValue;
    unsigned long lookAroundTimeoutValue;
    float lastWorldPositionX;
    float lastWorldPositionY;
    float lastWorldPositionZ;
    char gap_11C[4];
    float defenseBufferValue;
    int* importantObjects;
    int numberImportantObjects;
    AIPlayStatus* playStatus;
    unsigned char stopAfterTargetKilledValue;
    unsigned char pad_131[3];

    UnitAIModule(RGE_Static_Object*, int);
    void setAdjustedIdleTimeout();
    RGE_Static_Object* object() const;
    int objectID() const;
    int objectCategory() const;
    int mood() const;
    unsigned long lastUpdateTime() const;
    unsigned long idleTimer() const;
    unsigned long idleTimeout() const;
    unsigned long secondaryTimer() const;
    float defenseBuffer() const;
    void setDefenseBuffer(float);
    int orderQueueSize() const;
    OrderEvent* orderQueueElement(int) const;
    void purgeOrderQueue();
    int addToOrderQueue(OrderEvent*, int);
    int addToOrderQueue(int, int, int, int, float, float, float, float,
                        int, int);
    int addToNotifyQueue(NotifyEvent*);
    int addToNotifyQueue(int, int, int, long, long, long);
    int currentOrder() const;
    void setCurrentOrder(int);
    int currentOrderPriority() const;
    void setCurrentOrderPriority(int);
    int currentAction() const;
    void setCurrentAction(int);
    void setCurrentTarget(int, float, float, float);
    void setCurrentTarget(int, int, float, float, float);
    int currentTarget() const;
    int currentTargetType() const;
    float currentTargetX() const;
    float currentTargetY() const;
    float currentTargetZ() const;
    int lastAction() const;
    int lastOrder() const;
    int lastTarget() const;
    int lastTargetType() const;
    float desiredTargetDistance() const;
    int attackingUnitID(int);
    int numberAttackingUnits() const;
    int update(unsigned long);
    RGE_Static_Object* lookupObject(int);
    unsigned char visibleStatus(RGE_Visible_Map*, int, int);
    void removeCurrentTarget();
    void purgeNotifyQueue(unsigned long);
    void updateGroup(unsigned long);
    int selectNewPlayPhase(int phase, int parameter);
    Waypoint* waypoint(int) const;
    int waypointQueueSize() const;
    int addToWaypointQueue(int, int);
    int inWaypointQueue(int, int) const;
    void clearWaypointQueue();
    int isEnemyOwner(int);
    int isAllyOwner(int);
    int isNeutralOwner(int);
    void setTaskedByPlayer();
    void setPlayStatus(AIPlayStatus*);
    int hasOrderOnQueue(int);
    void askForHelp(int);
    void lookAround();
};

typedef char verify_aiuaimod_UnitAIModule_size[
    sizeof(UnitAIModule) == 0x134 ? 1 : -1];
typedef char verify_aiuaimod_OrderEvent_size[
    sizeof(OrderEvent) == 0x24 ? 1 : -1];
typedef char verify_aiuaimod_NotifyEvent_size[
    sizeof(NotifyEvent) == 0x18 ? 1 : -1];

#endif
