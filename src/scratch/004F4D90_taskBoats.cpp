#ifndef TAITACMD_SHARED_CONTEXT
// 004F4D90 TribeTacticalAIModule::taskBoats
// Source: taitacmd.cpp lines 5570-6037
// Attempt log:
// - baseline reconstruction: restored the period tactical-AI ownership model
//   (md at +0xF0, embedded informationAI at md+0xCEC, groups sentinel at
//   +0x9D4, and the ten ManagedArray<int> buckets) and the two ordered group
//   passes from the binary.  The remaining work is codegen/layout tuning after
//   validating this call/order surface.
// - probe 2 control-flow: inverted the first ready/task arms and used explicit
//   while(1) sentinel exits; this recovered the original loop-top null check.
// - probe 3 behavior: restored the second commander() evaluation before the
//   water fully-explored gate.
// - probe 4 behavior: restored the no-target water fallback to setAction(1).
// - probe 5 control-flow: joined completed not-in-use branches at the outer
//   loop tail instead of falling into action-10/11 checks.
// - probe 6 behavior: kept separate commander() evaluations for trade lookup
//   and the trade fully-explored gate.
// - probe 7 control-flow: sent action-10 target-null and found-reset exits to
//   the outer loop; replaced the found-reset null-object return with next-group.
// - probe 8 behavior: restored task(...,1,0) after a valid water target is
//   installed, as required by the executable's shared task tail.
// - probe 9 diagnostic shared-coordinate tail: a goto with three new float
//   locals raised the frame to 0x6C and was restored; no codegen-only variant
//   is retained.
// - ABI/layout probes: replaced the rejected padded/vf virtual scaffolding with
//   named canonical RGE/AIModule surfaces, corrected AIModule to 0xF0, and
//   declared the XYZPoint canPath overload before the integer overload.
// - behavior probe: removed a repeated water type() test; the outer 0x6B
//   branch already proves the fallback type and the original has no second
//   virtual type call there.
// - layout probe: reused the existing water/trade float slots for a shared
//   target-location tail; this matches the single original setTargetLocation
//   site without the 0x6C frame introduced by new target locals.
// - control-flow probe: found-reset action 8 falls through into later action
//   checks (the original does not jump to next_group after its task call).
// - final control-flow probe: carried busyOK into the canonical shared task
//   tail for default/target/action-11 paths and skipped setAction for unknown
//   first-pass types.  This resolves the task/action/type/target-location call
//   count gaps while keeping frame 0x60.  The best validated source remains in
//   scratch: 2070 differing bytes, 93.21% shape, 97.87% ordered calls, and
//   frame 0x60.  The remaining aggregate gap is one setAction and one setInUse
//   call.  The residual drift is concentrated in local homes and shared tails.
// - probes 1-20: direct setAction arms, positive water-count layout, direct
//   target-location expressions, and branch-local float scopes improved the
//   natural source.  Literal task-tail rewrites, extra found-path gotos, and
//   header context changes were rejected by the checker.
// - BINARY NOTE: the executable has one physical setTargetLocation call site
//   for the resource/trade target setup.  Keep those coordinates as direct
//   arguments so VC5 can share the tail without extra float reloads.
// - LIKELY INTENT: the action-8 found reset is a separate task path.  Its
//   current natural source retains the direct task call while later checks can
//   still run, but the executable uses a shared tail instead.
// - ManagedArray recovery audit, 2026-08-19: this function does not access a
//   tactical ManagedArray field or call one of its methods. The array members
//   only establish later class offsets, which the current 16-byte layout
//   already models. No shared-header migration applies to this target.
// - claim probes, 2026-08-22: routing the action-8 found reset to the shared
//   task tail worsened the result to 2122 bytes; explicit fallback exits were
//   codegen-neutral; bool ready and positive-ready CFG variants worsened to
//   2278 and 2203 bytes. Restored the clean 2070-byte source.
// - final validation, 2026-08-22: 2598 rebuilt bytes, 0x60 frame, 93.21%
//   shape, 97.87% ordered calls, 2070 differing bytes. Result remains
//   MISMATCH. Missing physical calls are one setAction and one setInUse.

#ifndef TAITACMD_SHARED_CONTEXT
struct XYZPoint {
    int x;
    int y;
    int z;
};

struct XYPoint {
    int x;
    int y;
};

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

template<class T> class ManagedArray;

typedef unsigned char uchar;
typedef unsigned long ulong;
typedef int AIModuleID;

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class AIModuleMessage;
class RGE_Game_World;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Object_List;
class RGE_Action_Object;
class RGE_Armor_Weapon_Info;
class RGE_Master_Combat_Object;
class RGE_Sound;
class RGE_Damage_Sprite_Info;
class TDrawArea;
class RGE_Color_Table;
class LOSTBL;
class Path;
class UnitAIModule;
class RGE_Action_List;
class RGE_Action;
class TribeTacticalAIModule;
class TribeMainDecisionAIModule;
class TribeInformationAIModule;
class ObjectMemory;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar, uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long, int, uchar);

    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    unsigned char gap_25[1];
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char gap_2D[3];
    float radius_x;
    float radius_y;
    float radius_z;
    RGE_Sound* selected_sound;
    RGE_Sound* created_sound;
    RGE_Sound* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    unsigned char gap_4F[1];
    short portrait_pict;
    unsigned char available;
    unsigned char gap_53[1];
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fog_flag;
    short terrain;
    unsigned char movement_type;
    unsigned char gap_69[1];
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    unsigned char gap_7E[2];
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
    unsigned char area_effect_object_level;
    unsigned char combat_level;
    unsigned char select_level;
    unsigned char map_draw_level;
    unsigned char unit_level;
    unsigned char map_color;
    unsigned char attack_reaction;
    unsigned char convert_terrain_flag;
    unsigned char damage_sprite_num;
    RGE_Damage_Sprite_Info* damage_sprites;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
    unsigned char recyclable;
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
    unsigned char draw_flag;
    unsigned char draw_color;
    unsigned char gap_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, uchar);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
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
    virtual LOSTBL* get_los_table();
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
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canPath(int, float, float*, int, int, int);
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
    void* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    uchar object_state;
    uchar sleep_flag;
    uchar dopple_flag;
    uchar goto_sleep_flag;
    short attribute_type_held;
    uchar type;
    uchar worker_num;
    void* player_object_node;
    ManagedArrayInt pathingGroupMembers;
    ManagedArrayInt groupMembers;
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    uchar inObstructionMapValue;
    uchar lastInObstructionMapValue;
    uchar underAttackValue;
    uchar gap_87;

    UnitAIModule* unitAI();
    uchar currentZone();
    uchar lookupZone(int, int);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_88[4];
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);

    char gap_8C[0xF4];
};

class RGE_Action {
public:
    char gap_00[0x1C];
    int target2ID;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(void*, RGE_Static_Object*, float, float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();
    virtual void get_action_name(char*);
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, void*, void*);
    virtual ~RGE_Action_List();

    char gap_04[8];
    RGE_Action* get_action();
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    virtual RGE_Action_List* create_action_list();

    char gap_180[4];
    RGE_Action_List* actions;
    char gap_188[0x0C];
    uchar have_action();
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap_04[0x130];

    int currentOrder();
    int currentAction();
};

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
    virtual int filterOutMessage(AIModuleMessage*);

    char gap_04[0xEC];
};

class TacticalAIModule : public AIModule {
public:
    virtual ~TacticalAIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    virtual ~MainDecisionAIModule();
    RGE_Player* player;
    int* objects;
    int number;
    char gap_FC[4];
    int maxSize;

    RGE_Static_Object* object(int);
};

class InformationAIModule : public AIModule {
public:
    virtual ~InformationAIModule();
};

class TribeInformationAIModule : public InformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_0F0[0x10090 - 0x0F0];

    int fullyExploredZone(int objectID);
    int gameIDOfResourceObject(int resourceType, int gathererID,
                               float& outX, float& outY, int& outResourceID,
                               int* exclusions, int exclusionCount);
    ObjectMemory* objectToTradeWith(int commanderID);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char gap_104[0xCEC - 0x104];
    TribeInformationAIModule informationAI;
};

class ObjectMemory {
public:
    int id;
    short type;
    unsigned char pad_06[2];
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
};

struct Waypoint {
    int x;
    int y;
    int z;
    int unk;
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
    ulong consecutiveIdleUnitCountValue;
    int playNumberValue;
    uchar numberAttackWaypointsValue;
    uchar currentAttackWaypointValue;
    uchar pad_1D6[2];
    Waypoint attackWaypoints[15];
    uchar consecutiveGatherAttemptsValue;
    uchar pad_2C9[3];
    int numberObjectsToDestroyValue;
    int objectsToDestroyValue[20];
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;
    ulong lastAttackRoundupTime;
    ulong lastAddedUnitTimeValue;

    int type();
    int action();
    int inUse();
    int numberUnits();
    int desiredNumberUnits();
    int isGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int allUnitsIdle(TribeMainDecisionAIModule*, int);
    int commander();
    int target();
    void setAction(int);
    void setInUse(int);
    void setTarget(int);
    void setTargetType(int);
    void setTargetLocation(float, float, float);
    void setGatherLocation(float, float, float);
    int task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int);
};

class UnitData {
public:
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    unsigned long lastTaskTime;
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArrayInt civilians;
    ManagedArrayInt civilianExplorers;
    ManagedArrayInt soldiers;
    ManagedArrayInt ungroupedSoldiers;
    ManagedArrayInt boats;
    ManagedArrayInt warBoats;
    ManagedArrayInt fishingBoats;
    ManagedArrayInt tradeBoats;
    ManagedArrayInt transportBoats;
    ManagedArrayInt artifacts;
    int sn[226];
    UnitData gatherers[50];
    int numberGatherersValue;
    int desiredNumberGatherersValue;
    TacticalAIGroup groups;
    int groupIDValue;
    int numberGroupsValue;
    unsigned long lastGroupAttackTime;
    unsigned long lastGroupRebalanceTime;
    unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime;
    unsigned long lastScalingUpdateValue;
    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;
    ManagedArrayInt playersToAttack;
    ManagedArrayInt playersToDefend;
    ManagedArrayInt workingArea;
    ManagedArrayInt unitsTaskedThisUpdate;
    int actualGathererDistribution[4];
    int desiredGathererDistribution[4];
    int neededResourceValue[4];
    int resourceDifferenceValue[4];
    char neededResources[0x70];
    int attackEnabledValue;
    int updateArea;
    int firstNeededResourceUpdateDone;
    int numberStoragePitsBuilt[4];
    int numberGranariesBuilt[4];
    int wonderInProgressValue;
    int wonderBuiltValue;
    char placementStateValue[0x130];
    int nextCivilianToTaskValue;
    int nextIdleSoldierGroupToTaskValue;
    int nextActiveSoldierGroupToTaskValue;
    int builtFirstStoragePit;
    int builtFirstGranary;
    unsigned long lastBuildTime;
    unsigned long lastAttackResponseBuildInsertionTime;
    unsigned long lastCoopTributeDemandTime;
    unsigned long lastCoopTributeGiftTime;
    unsigned long lastCoopAttackDemandTime;
    int zoomingToNextAge;
    unsigned long lastUngroupedSoldierTaskTime;
    char attackStateValue[0x2C];
    int hitsByPlayer[9];
    int lastUpdateAreaTimeValue;
    int averageUpdateAreaTimeValue;
    int updateAreaAverageCount;
    int updateAreaAverageTotal;

    int numberWaterExplorers();
    void taskBoats();
};

#endif

void TribeTacticalAIModule::taskBoats()
{
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int busyOK;

    group = this->groups.next;
    sentinel = &this->groups;
    if (group != sentinel) {
        while (1) {
            if (group == 0) {
                break;
            }

            if (group->type() != 100 && group->type() != 101 &&
                group->type() != 102 && group->type() != 103 &&
                group->type() != 104 && group->type() != 105 &&
                (group->action() == 0 || group->action() == 1)) {
                int ready = 1;
                int gathered = group->isGathered(this, this->md);
                int number = group->numberUnits();
                int desired = group->desiredNumberUnits();

                if (number < desired ||
                    (gathered == 0 && group->numberUnits() > 1) ||
                    group->allUnitsIdle(this->md, 1) == 0) {
                    ready = 0;
                }

                if (ready == 0) {
                    if (gathered == 0) {
                        group->task(this, this->md, 9, 1, 0);
                    }
                }
                else {
                    if (group->type() == 0x6B) {
                        group->setAction(10);
                    }
                    else if (group->type() == 0x6C) {
                        group->setAction(11);
                    }
                    else if (group->type() == 0x6A) {
                        group->setAction(1);
                    }
                    else {
                        goto first_pass_next;
                    }
                }
            }

first_pass_next:
            group = group->next;
            if (group == sentinel) {
                break;
            }
        }
    }

    group = this->groups.next;
    if (group != sentinel) {
        while (1) {
            if (group == 0) {
                return;
            }

            if (group->type() != 100 && group->type() != 101 &&
                group->type() != 102 && group->type() != 103 &&
                group->type() != 104 && group->type() != 105 &&
                group->action() != 0 && group->action() != 1) {
                if (group->inUse() == 0) {
                    if (group->type() == 0x6B) {
                        float outputX;
                        float outputY;
                        int commanderID = group->commander();
                        RGE_Static_Object* commander = this->md->object(commanderID);
                        if (commander == 0) {
                            group->setAction(1);
                        }
                        else {
                            int resourceID = -1;
                            int resourceMode = -1;
                            int exclusionCount = 0;
                            int exclusionIndex = 0;
                            int exclusions[5];
                            int pathOK;

                            if (this->numberWaterExplorers() > 0) {
                                if (this->md->informationAI.fullyExploredZone(
                                        group->commander()) == 1) {
                                    do {
                                        outputX = 0.0f;
                                        outputY = 0.0f;
                                        resourceMode = -1;
                                        resourceID = this->md->informationAI.gameIDOfResourceObject(
                                            0, commander->id, outputX, outputY, resourceMode,
                                            exclusions + 1, exclusionCount);

                                        XYZPoint point;
                                        point.x = (int)outputX;
                                        point.y = (int)outputY;
                                        point.z = (int)commander->world_z;

                                        if (resourceMode == -1) {
                                            pathOK = commander->canPath(point, 1.0f,
                                                                         resourceID, 0,
                                                                         1, -1, -1);
                                        }
                                        else {
                                            pathOK = commander->canBidirectionPath(
                                                resourceID, resourceMode, 1.0f, 0,
                                                1, -1, -1);
                                        }

                                        if (pathOK == 0) {
                                            exclusions[exclusionCount] = resourceID;
                                            ++exclusionCount;
                                        }
                                        ++exclusionIndex;
                                    } while (pathOK != 1 && exclusionIndex < 5);
                                }
                            }

                            RGE_Static_Object* object = this->md->object(resourceID);
                            if (resourceID >= 0 && object != 0) {
                                group->setTarget(resourceID);
                                group->setTargetType((int)object->master_obj->id);
                                group->setTargetLocation(object->world_x,
                                                         object->world_y,
                                                         object->world_z);
                                group->setInUse(1);
                                busyOK = 0;
                                goto task_tail;
                            }
                            else {
                                if (this->md->informationAI.fullyExploredZone(
                                        group->commander()) == 1) {
                                    group->setAction(8);
                                    group->task(this, this->md,
                                                group->action(), 1, 0);
                                    group->setInUse(1);
                                }
                                else {
                                    group->setAction(1);
                                }
                            }
                        }
                    }
                    else if (group->type() == 0x6C) {
                        int commanderID = group->commander();
                        RGE_Static_Object* commander = this->md->object(commanderID);
                        float pathDistance;
                        if (commander == 0) {
                            group->setAction(1);
                        }
                        else {
                            ObjectMemory* trade =
                                this->md->informationAI.objectToTradeWith(
                                    group->commander());
                            if (trade == 0) {
                                if (this->md->informationAI.fullyExploredZone(
                                        group->commander()) == 1) {
                                    group->setAction(8);
                                    group->task(this, this->md,
                                                group->action(), 1, (int)trade);
                                    group->setInUse(1);
                                }
                                else {
                                    group->setAction(1);
                                }
                            }
                            else {
                                XYZPoint point;
                                point.x = (int)trade->x;
                                point.y = (int)trade->y;
                                point.z = (int)trade->z;
                                if (commander->canPath(point, 1.0f, trade->id,
                                                       &pathDistance, 1, -1, -1) != 0) {
                                    group->setTarget(trade->id);
                                    group->setTargetType((int)trade->type);
                                    group->setTargetLocation((float)trade->x,
                                                             (float)trade->y,
                                                             (float)trade->z);
                                    group->setInUse(1);
                                    busyOK = 0;
                                    goto task_tail;
                                }
                                else {
                                    group->setAction(1);
                                }
                            }
                        }
                    }
                    else {
                        busyOK = 0;
                        goto task_tail;
                    }
                    goto next_group;

                }
                if (group->action() == 8) {
                    int found = 0;

                    if (group->type() == 0x6C) {
                        if (this->md->informationAI.objectToTradeWith(
                                group->commander()) != 0) {
                            found = 1;
                        }
                    }

                    if (group->type() == 0x6B) {
                        if (this->numberWaterExplorers() > 1) {
                            float pathDistance = 0.0f;
                            float outputX = 0.0f;
                            int outputY = -1;
                            int commanderID = group->commander();
                            int resourceID =
                                this->md->informationAI.gameIDOfResourceObject(
                                    0, commanderID, pathDistance, outputX,
                                    outputY, 0, 0);
                            if (resourceID != -1) {
                                found = 1;
                            }
                        }
                        else {
                            RGE_Static_Object* object =
                                this->md->object(group->commander());
                            if (object != 0 && object->unitAI() != 0 &&
                                object->unitAI()->currentOrder() != 0x2C1) {
                                group->setAction(8);
                                group->task(this, this->md,
                                            group->action(), 1, 0);
                                group->setInUse(1);
                            }
                        }
                    }

                    if (found == 1) {
                        RGE_Static_Object* object =
                            this->md->object(group->commander());
                        if (object == 0) {
                            goto next_group;
                        }
                        group->setInUse(0);
                        group->setAction(1);
                        group->setTarget(-1);
                        group->numberObjectsToDestroyValue = 0;
                        group->setTargetType(-1);
                        group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        group->setGatherLocation(object->world_x,
                                                 object->world_y,
                                                 object->world_z);
                        group->task(this, this->md, group->action(), 1, 0);
                    }
                }

                if (group->action() == 10) {
                    int targetID = group->target();
                    RGE_Static_Object* target = this->md->object(targetID);
                    if (target == 0) {
                        group->setInUse(0);
                        group->setAction(1);
                        group->setTarget(-1);
                        group->setTargetType(-1);
                        group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        group->numberObjectsToDestroyValue = 0;
                        goto next_group;
                    }
                    else {
                        RGE_Static_Object* commander =
                            this->md->object(group->commander());
                        if (commander != 0 && commander->unitAI() != 0 &&
                            commander->unitAI()->currentAction() == -1) {
                            group->setInUse(0);
                            group->setAction(1);
                            group->setTarget(-1);
                            group->numberObjectsToDestroyValue = 0;
                            group->setTargetType(-1);
                            group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            group = group->next;
                        }
                    }
                }

                if (group->action() == 11) {
                    int targetID = group->target();
                    RGE_Static_Object* target = this->md->object(targetID);
                    if (target == 0) {
                        group->setInUse(0);
                        group->setAction(1);
                        group->setTarget(-1);
                        group->numberObjectsToDestroyValue = 0;
                        group->setTargetType(-1);
                        group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                    }
                    else {
                        RGE_Static_Object* commander =
                            this->md->object(group->commander());
                        RGE_Static_Object* actionObject = commander;
                        if (actionObject != 0 && actionObject->unitAI() != 0 &&
                            actionObject->unitAI()->currentAction() == -1) {
                            group->setInUse(0);
                            group->setAction(1);
                            group->setTarget(-1);
                            group->numberObjectsToDestroyValue = 0;
                            group->setTargetType(-1);
                            group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            group = group->next;
                        }
                        else if (actionObject != 0 && actionObject->have_action() != 0) {
                            RGE_Action* action = actionObject->actions->get_action();
                            ObjectMemory* trade =
                                this->md->informationAI.objectToTradeWith(
                                    action->target2ID);
                            if (trade != 0 && trade->id != group->target()) {
                                float pathDistance;
                                XYZPoint point;
                                point.x = (int)trade->x;
                                point.y = (int)trade->y;
                                point.z = (int)trade->z;
                                if (actionObject->canPath(point, 1.0f,
                                                          trade->id,
                                                          &pathDistance, 1,
                                                          -1, -1) == 0) {
                                    group->setAction(1);
                                }
                                else {
                                    group->setTarget(trade->id);
                                    group->setTargetType((int)trade->type);
                                    group->setTargetLocation((float)trade->x,
                                                             (float)trade->y,
                                                             (float)trade->z);
                                    group->setInUse(1);
                                    busyOK = 1;
                                    goto task_tail;
                                }
                            }
                        }
                    }
                }
            }

            goto next_group;
task_tail:
            group->task(this, this->md, group->action(), 1, busyOK);

next_group:
            group = group->next;
            if (group == sentinel) {
                break;
            }
        }
    }
}
#else
void TribeTacticalAIModule::taskBoats() {}
#endif
