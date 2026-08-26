// VA: 004DCF10 TribeInformationAIModule::objectToAttackByGroup
// PDB source: taiinfmd.cpp lines 3771-4247
//
// Baseline reconstruction: the module owns ObjectMemory records, while the
// group owns only the transient destroy list.  The candidate scan is resumed
// through AttackState::iterationIndex/phase; path obstruction lists are local
// ManagedArray<int> values and are folded into the group's destroy list.
//
// Attempt log:
// - baseline candidate pending: period-plausible typed reconstruction with the
//   observed group/object/path/score call order; no compiler steering or asm.
// - probe 2: named the ID-path dispatch table surface separately from the point-path
//   overload and restored the observed default path argument (vslot +0x194).
// - probe 3: kept separate coordinate conversions for zone, visibility, and
//   score distance; added the observed visibility gate and unit scan.
// - probe 4: shared the fallback and best-target objectToDestroy/objectMemory
//   tail through the current destroy index; ordered calls became exact.
// - probe 5: reused the destroy-loop index; no useful frame improvement.
// - probe 6: restored canonical canPath naming without emitted-code movement.
// - probe 7: propagated ObjectMemory::owner to the group destroy metadata;
//   this also recovered the original 0x54 frame and much deeper alignment.
// - probe 8: tested an explicit long-lived this alias; rolled back (frame and
//   code shape worsened).
// - probe 9: converged early returns and timeout paths through one result/
//   cleanup epilogue, matching the original single-return CFG family.
// - probe 10: reused the function-level wonder/result slot; size is exact,
//   calls and boundary are exact, but bytes remain nonexact.
// - probe 15: moved result-slot zeroing to the binary-observed pre-isBoat
//   point; positional diff improved by one byte, but shape and resync drift
//   worsened, so restored the clean source.
// - probes 16-20: tested local declaration order, loop forms, shared versus
//   block-local ManagedArray objects, POD lifetime, and standard headers.
//   None produced a better clean codegen basin. The block-local arrays keep
//   the original nine operator_delete call sites.
// - probes 21-28: restored the md-player visibility receiver and the
//   DAT_00575564 distance threshold from assembly. Reusing the scan index and
//   moving targetDistance to function scope changed little; no exact result.
// - probe 31: one function-scope wallObjects object removed two required
//   operator_delete sites and worsened the frame. Block-local arrays remain.
// - probe 33: a direct invalid-commander return added cleanup exits and made
//   the function 148 bytes larger. The shared zero-return tail remains.
// - probe 35: a named kills factor added a stack slot and worsened the frame.
// - probe 37: sequential score accumulation in 0x50, 0x4D, 0xB8 order reduced
//   the positional diff by one byte and improved shape and resynchronization.
// - probes 38-39: commanderZone reorder was codegen-neutral; function-scope
//   score factors were one byte worse. Both use the smaller natural form.
// - probe 41: one timeKillRatio local preserves hp/damage-before-time order
//   and improved shape without changing size or calls. Probe 42 was a codegen
//   duplicate after promoting that local to function scope.

// BINARY NOTE: visibility uses this module's md->player map, not the target
// owner's map. The executable loads md->player before visible.
// BINARY NOTE: the distance clamp reads DAT_00575564. Keep the symbol rather
// than replacing it with an equal literal.

#include "../../include/game_globals.h"
#include <math.h>

void* operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Tile;
class RGE_Armor_Weapon_Info;
class RGE_Action_Object;
class RGE_Color_Table;
class TDrawArea;
class LOSTBL;
class Path;
class XYZPoint;
class XYZBYTEPoint;
class XYPoint;
class RGE_Visible_Map;
class UnitAIModule;
class AIModuleMessage;
class NotifyEvent;
class OrderEvent;
class AIPlayStatus;
class RGE_Zone_Map;
class InfluenceMap;
class TribeMainDecisionAIModule;
class TribeTacticalAIModule;
class TacticalAIGroup;

#endif
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char _pad_0[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
};

class Waypoint {
public:
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char _pad_end[3];
};

// This is the period ManagedArray<int> surface used by the original local
// obstruction lists.  Its inline indexer is intentionally the ordinary
// resizing implementation, not a hand-written dispatch table/offset scaffold.
template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {
    }

    ~ManagedArray() {
        if (this->value != 0) {
            operator delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_data = (T*)operator new(new_size * sizeof(T));
            if (new_data != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_data[i] = this->value[i];
                }
                operator delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class ObjectMemory {
public:
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char _pad_0[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char _pad_1[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

class AttackState {
public:
    int bestTargetID;
    float bestTargetValue;
    int bestTargetMemoryIndex;
    int iterationIndex;
    int attackGroupID;
    int playID;
    unsigned char phase;
    unsigned char _pad_0[3];
    int bestNonWallTargetID;
    float bestNonWallTargetValue;
    int bestNonWallTargetMemoryIndex;
    int active;
};

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[64];
};

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* value);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* value);
    virtual int saveState(char* value);
    virtual int gleanState(int value);
    virtual int processMessage(AIModuleMessage* value);
    virtual int update(int value);
    virtual void setCallbackMessage(AIModuleMessage* value);
    virtual int filterOutMessage(AIModuleMessage* value);

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

class InformationAIModule : public AIModule {
public:
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int x, int y);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char _pad_0;
    long sound_update_index;
    long sprite_update_index;
    void* map;
    short sound_num;
    unsigned char _pad_1[2];
    void* sounds;
    short sprite_num;
    unsigned char _pad_2[2];
    void* sprites;
    short player_num;
    unsigned char _pad_3[2];
    RGE_Player** players;
    unsigned char _gap_44[0xF8 - 0x48];
    unsigned long availableComputerPlayerUpdateTime;
    int currentUpdateComputerPlayer;
    int difficultyLevelValue;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char value);
    virtual void do_resign();
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual int aiStatus();
    virtual int isEnemy(int playerID);
    virtual int isAlly(int playerID);
    virtual int isNeutral(int playerID);
    virtual int isAllNeutral(int playerID);

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char _pad_0;
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char _pad_1;
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object* = 0);
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
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
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
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
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
    virtual int canPath(int, float, float* = 0, int = 1, int = -1, int = -1);
    virtual int canPathAtPoint(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    RGE_Object_Node* player_object_node;
    ManagedArray<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char _pad_end;

    UnitAIModule* unitAI();
    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();

    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;
    int originalHitPointsValue;
    int originalUnitNumberValue;
    Waypoint locationValue;
    int actionValue;
    int targetValue;
    int targetTypeValue;
    Waypoint targetLocationValue;
    Waypoint gatherLocationValue;
    Waypoint retreatLocationValue;
    int priorityValue;
    int waitCodeValue;
    int assistGroupIDValue;
    int assistGroupTypeValue;
    unsigned long consecutiveIdleUnitCountValue;
    int playNumberValue;
    unsigned char numberAttackWaypointsValue;
    unsigned char currentAttackWaypointValue;
    unsigned char _pad_0[2];
    Waypoint attackWaypoints[15];
    unsigned char consecutiveGatherAttemptsValue;
    unsigned char _pad_1[3];
    int numberObjectsToDestroyValue;
    int objectsToDestroyValue[20];
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;
    unsigned long lastAttackRoundupTime;
    unsigned long lastAddedUnitTimeValue;

    int commander() const;
    int objectToDestroy(int index);
    int addObjectToDestroy(int index);
    int numberUnits();
    int unit(int index);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int attackObject(int, int);
    virtual int attackRoundupObject(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int buildObject(int, int);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int canConvert(int);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual int convertObject(int, int);
    virtual int convertToLOSResourceType(int);
    virtual int defendObject(int, float, int);
    virtual int defendPosition(float, float, float, int);
    virtual int enterObject(int, int);
    virtual int evasiveMoveTo(float, float, float, int);
    virtual int explore(int, int, int);
    virtual int exploreAndDestroy(int, int, int);
    virtual int followObject(int, float, int);
    virtual int gatherObject(int, int);
    virtual int healObject(int, int);
    virtual int huntObject(int, int);
    virtual int importantObject(int);
    virtual int importantWhenDead(int);
    virtual int intelligentEvasiveMoveTo(float, float, float, int, int);
    virtual void logDebug(char*);
    virtual int mostDangerousEnemy(float*);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(NotifyEvent*);
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual void processGroupNotify(NotifyEvent*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processOrder(OrderEvent*, int);
    virtual int processRetryableOrder();
    virtual int repairObject(int, int);
    virtual int retryableOrder(int);
    virtual int runAwayFromAttackers(int);
    virtual void search();
    virtual int seekAndDestroy(int, int = 0, int = 0, int = 0);
    virtual int stopObject(int);
    virtual int tradeWithObject(int, int);
    virtual int transportObject(float, float, float, int);
    virtual int unload(int, float, float);
    virtual int update(unsigned long);
    virtual void updateGroup(unsigned long);
    virtual int weakestEnemy(float*);

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
    ManagedArray<int> attackingUnitsValue;
    Waypoint waypointQueue[8];
    int waypointQueueSizeValue;
    unsigned long lastUpdateTimeValue;
    unsigned long idleTimerValue;
    unsigned long adjustedIdleTimeoutValue;
    unsigned long idleTimeoutValue;
    unsigned long secondaryTimerValue;
    unsigned long lookAroundTimerValue;
    unsigned long lookAroundTimeoutValue;
    Waypoint lastWorldPositionValue;
    float defenseBufferValue;
    int* importantObjects;
    int numberImportantObjects;
    AIPlayStatus* playStatus;
    unsigned char stopAfterTargetKilledValue;
    unsigned char _pad_end[3];

    int currentTarget();
};

class TacticalAIModule : public AIModule {
public:
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;
    int sn[226];
    unsigned char _rest[0x100C - 0x51C - 0x388];

    int strategicNumber(int number);
};

class MainDecisionAIModule : public AIModule {
public:
    virtual ~MainDecisionAIModule();
    RGE_Player* player;
    ManagedArray<int> objects;
    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    unsigned char _beforeTacticalAI[0x1146C - 0x104];
    TribeTacticalAIModule tacticalAI;
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray<int> farmsTaskedThisUpdate;
    TribeMainDecisionAIModule* md;
    int mapXSizeValue;
    int mapYSizeValue;
    int lastUpdateRowValue;
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    ManagedArray<int> importantObjects;
    ManagedArray<int> importantUnits;
    ManagedArray<int> importantMiscs;
    ManagedArray<int> itemsToDefend;
    unsigned char _pathMap[0x28];

    int isBoat(RGE_Static_Object* object);
    ObjectMemory* wonderToAttack(int type);
    ObjectMemory* objectMemory(int id);
    int addImportantObject(int id);
    int isUnitBuilding(RGE_Static_Object* object);
    float damageInflictedPerSecond(TacticalAIGroup* group, RGE_Static_Object* object);
    float timeToBeKilled(TacticalAIGroup* group, RGE_Static_Object* object);

    ObjectMemory* objectToAttackByGroup(int owner, TacticalAIGroup* group, AttackState& state, unsigned long currentTime);
};
#endif

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" int __cdecl debug_rand(const char* file, int line);
extern float DAT_00575564;

#endif

#endif
ObjectMemory* TribeInformationAIModule::objectToAttackByGroup(
    int owner, TacticalAIGroup* group, AttackState& stateRef, unsigned long currentTime)
{
    AttackState* state = &stateRef;
    ObjectMemory* wonder = 0;
    unsigned char commanderZone;
    RGE_Static_Object* commanderObject = this->md->object(group->commander());
    int commanderIsBoat = 0;
    float targetDistance;
    int commanderIsPriest = 0;
    int destroyIndex = 0;

    if (commanderObject == 0 || commanderObject->unitAI() == 0) {
        state->active = 0;
        goto done;
    }

    commanderZone = commanderObject->currentZone();
    if (commanderObject->master_obj->object_group == 0x12) {
        commanderIsPriest = 1;
    }
    if (this->isBoat(commanderObject) == 1) {
        commanderIsBoat = 1;
    }

    if (state->active == 0 &&
        group->objectsToDestroyOwnerValue == owner &&
        group->numberObjectsToDestroyValue > 0 &&
        group->objectsToDestroyCommanderZoneValue == (int)commanderZone) {
        int objectID = group->objectToDestroy(group->numberObjectsToDestroyValue - 1);
        RGE_Static_Object* object = this->md->object(objectID);

        if (object != 0 &&
            this->md->player->isEnemy(object->owner->id) == 1 &&
            object->object_state <= 2 &&
            commanderObject->canPath(
                group->objectToDestroy(group->numberObjectsToDestroyValue - 1),
                commanderObject->weaponRange()) == 1) {
            objectID = group->objectToDestroy(group->numberObjectsToDestroyValue - 1);
            group->numberObjectsToDestroyValue = 0;
            group->addObjectToDestroy(objectID);
            wonder = this->objectMemory(objectID);
            goto done;
        }
    }

    if (group->numberObjectsToDestroyValue - 1 > 0) {
        for (destroyIndex = 0;
             destroyIndex < group->numberObjectsToDestroyValue - 1;
             ++destroyIndex) {
            RGE_Static_Object* object = this->md->object(group->objectToDestroy(destroyIndex));
            if (object != 0 &&
                this->md->player->isEnemy(object->owner->id) == 1 &&
                object->object_state <= 2 &&
                commanderObject->canPath(
                    group->objectToDestroy(destroyIndex), commanderObject->weaponRange()) == 1) {
                
                goto selected_destroy_object;
            }
        }
    }

    if (state->active == 0) {
        wonder = this->wonderToAttack(-1);
        if (wonder != 0) {
            unsigned char wonderZone = commanderObject->lookupZone((int)wonder->x, (int)wonder->y);
            if (wonderZone != commanderZone && commanderIsBoat == 0) {
                goto done;
            }
            if (commanderObject->canPath(wonder->id, commanderObject->weaponRange()) == 1) {
                group->numberObjectsToDestroyValue = 0;
                group->addObjectToDestroy(wonder->id);
                group->objectsToDestroyOwnerValue = wonder->owner;
                group->objectsToDestroyCommanderZoneValue = (int)commanderZone;
                goto done;
            }

            ManagedArray<int> wallObjects;
            if (commanderObject->canPathWithObstructions(
                    wonder->id, commanderObject->weaponRange(), 0, 1, owner, 0x1B,
                    &wallObjects) == 1) {
                group->numberObjectsToDestroyValue = 0;
                for (int i = 0; i < wallObjects.numberValue; ++i) {
                    if (this->md->object(wallObjects[i]) != 0) {
                        this->addImportantObject(wallObjects[i]);
                        group->addObjectToDestroy(wallObjects[i]);
                    }
                }
                group->addObjectToDestroy(wonder->id);
                group->objectsToDestroyCommanderZoneValue = (int)commanderZone;
                group->objectsToDestroyOwnerValue = wonder->owner;
                goto done;
            }
        }

        state->bestTargetID = -1;
        state->bestTargetValue = -1.0f;
        state->bestTargetMemoryIndex = -1;
        state->iterationIndex = 0;
        state->attackGroupID = -1;
        state->playID = -1;
        state->phase = 0;
        state->bestNonWallTargetID = -1;
        state->bestNonWallTargetValue = -1.0f;
        state->bestNonWallTargetMemoryIndex = -1;
        state->active = 1;
    }

    destroyIndex = state->iterationIndex;
    for (; destroyIndex < this->maxImportantObjectMemory; ++destroyIndex) {
        ObjectMemory* memory = this->importantObjectMemory + destroyIndex;

        if (destroyIndex > state->iterationIndex) {
            if (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0xF5A) - currentTime >=
                this->md->player->world->availableComputerPlayerUpdateTime) {
                state->iterationIndex = destroyIndex;
                goto done;
            }
        }

        if (memory->owner != owner) {
            continue;
        }

        RGE_Static_Object* target = this->md->object(memory->id);
        if (target == 0 || target->object_state > 2 || target->hp == DAT_00575580) {
            continue;
        }

        if (commanderIsBoat == 0 && this->isBoat(target) == 1) {
            continue;
        }

        int targetX = (int)target->world_x;
        int targetY = (int)target->world_y;
        unsigned char targetZone = commanderObject->lookupZone(targetX, targetY);

        if (commanderIsBoat == 0 && memory->type == 0x2D && targetZone != commanderZone) {
            continue;
        }
        if (state->phase == 0 && memory->group == 0x1B) {
            continue;
        }
        if (state->phase == 1 && memory->group != 0x1B) {
            continue;
        }

        int visibleDX = (int)memory->x - (int)target->world_x;
        if (visibleDX < 0) {
            visibleDX = -visibleDX;
        }
        int visibleDY = (int)memory->y - (int)target->world_y;
        if (visibleDY < 0) {
            visibleDY = -visibleDY;
        }
        if ((visibleDX > 5 || visibleDY > 5) &&
            this->md->player->visible->get_visible(targetX, targetY) != 0x0F) {
            continue;
        }

        if (commanderIsPriest != 0 &&
            commanderObject->unitAI()->seekAndDestroy(memory->id) == 0) {
            continue;
        }

        float damage = this->damageInflictedPerSecond(group, target);
        float killTimeRatio = target->hp / damage;
        float killTime = this->timeToBeKilled(group, target);
        if (damage == DAT_00575580) {
            continue;
        }
        if (killTime == DAT_00575580) {
            continue;
        }
        killTimeRatio = killTime / killTimeRatio;

        int dx = (int)memory->x - (int)target->world_x;
        if (dx < 0) {
            dx = -dx;
        }
        int dy = (int)memory->y - (int)target->world_y;
        if (dy < 0) {
            dy = -dy;
        }
        targetDistance = (float)sqrt((double)(dx * dx + dy * dy));
        if (targetDistance < DAT_00575564) {
            targetDistance = 1.0f;
        }

        float randomFactor = 0.0f;
        if (this->md->tacticalAI.strategicNumber(0x53) > 0) {
            randomFactor = (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0xFD5) %
                this->md->tacticalAI.strategicNumber(0x53));
        }

        float attackAttemptFactor =
            (float)this->md->tacticalAI.strategicNumber(0x59) * memory->attackAttempts;
        float sameZoneFactor = 0.0f;
        if (targetZone == commanderZone) {
            sameZoneFactor = (float)this->md->tacticalAI.strategicNumber(0x7A);
        }

        float currentTargetFactor = 0.0f;
        if (this->md->tacticalAI.strategicNumber(0xB9) > 0) {
            int currentTargetCount = 0;
            if (group->numberUnits() > 0) {
                int unitIndex = 0;
                do {
                    RGE_Static_Object* unit =
                        this->md->object(group->unit(unitIndex));
                    if (unit != 0 && unit->unitAI() != 0 &&
                        unit->unitAI()->currentTarget() == memory->id) {
                        ++currentTargetCount;
                    }
                    ++unitIndex;
                } while (unitIndex < group->numberUnits());
            }
            currentTargetFactor =
                (float)this->md->tacticalAI.strategicNumber(0xB9) * currentTargetCount;
        }

        float nonWallFactor = 0.0f;
        if (state->phase == 1 && state->bestNonWallTargetID != -1) {
            ObjectMemory* previous =
                this->importantObjectMemory + state->bestNonWallTargetMemoryIndex;
            int previousDX = (int)memory->x - (int)previous->x;
            int previousDY = (int)memory->y - (int)previous->y;
            float previousDistance =
                (float)sqrt((double)(previousDX * previousDX + previousDY * previousDY));
            if (previousDistance < 1.0f) {
                nonWallFactor = 1000.0f;
            } else {
                nonWallFactor = DAT_0057558c / previousDistance;
            }
        }

        if (this->isUnitBuilding(target) == 1) {
            if (target->master_obj->id == 0x6D || target->master_obj->id == 0x2D) {
                nonWallFactor -= DAT_00575594;
            } else {
                nonWallFactor -= DAT_00575590;
            }
        }

        float score =
            (float)this->md->tacticalAI.strategicNumber(0x50) * memory->kills;
        score +=
            (float)this->md->tacticalAI.strategicNumber(0x4D) / targetDistance;
        score +=
            (float)this->md->tacticalAI.strategicNumber(0xB8) * killTimeRatio;
        score += nonWallFactor + currentTargetFactor + attackAttemptFactor +
            sameZoneFactor + randomFactor;

        if (state->bestTargetID != -1 && score <= state->bestTargetValue) {
            continue;
        }

        if (state->phase == 0 && target->maximumSpeed() == DAT_00575580) {
            state->bestNonWallTargetID = memory->id;
            state->bestNonWallTargetMemoryIndex = destroyIndex;
            state->bestNonWallTargetValue = score;
        }

        int obstructionGroup = state->phase == 0 ? 0x1B : -1;
        ManagedArray<int> wallObjects;
        if (targetZone == commanderZone &&
            commanderObject->canPath(memory->id, commanderObject->weaponRange()) != 1 &&
            commanderObject->canPathWithObstructions(
                memory->id, commanderObject->weaponRange(), 0, 1, owner,
                obstructionGroup, &wallObjects) != 1) {
            continue;
        }

        group->numberObjectsToDestroyValue = 0;
        for (int i = 0; i < wallObjects.numberValue; ++i) {
            if (this->md->object(wallObjects[i]) != 0) {
                this->addImportantObject(wallObjects[i]);
                group->addObjectToDestroy(wallObjects[i]);
            }
        }
        group->addObjectToDestroy(memory->id);
        group->objectsToDestroyCommanderZoneValue = (int)commanderZone;
        group->objectsToDestroyOwnerValue = memory->owner;
        state->bestTargetID = memory->id;
        state->bestTargetMemoryIndex = destroyIndex;
        state->bestTargetValue = score;
    }

    if (state->bestTargetID != -1) {
        ++(this->importantObjectMemory[state->bestTargetMemoryIndex].attackAttempts);
        state->active = 0;
        destroyIndex = 0;
        goto selected_destroy_object;
    }

    if (state->phase == 0) {
        state->phase = 1;
        state->iterationIndex = 0;
    } else {
        state->active = 0;
    }
    goto done;

selected_destroy_object:
    wonder = this->objectMemory(group->objectToDestroy(destroyIndex));

done:
    return wonder;
}
