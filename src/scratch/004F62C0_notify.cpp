// 004F62C0 TribeTacticalAIModule::notify
// Source: taitacmd.cpp lines 6388-6886
// Baseline reconstruction: direct-command notification, attack-response state,
// named TacticalAIGroup/Information/Diplomacy ownership, and the complete
// named RGE_Static_Object virtual surface used by the two path tests.
//
// Attempt log:
// - baseline: canonical ownership is md->aiPlayer/world for object lookup,
//   md->informationAI for relic memory, the four named managed arrays, and the
//   embedded TacticalAIGroup sentinel; no vtable padding or raw vptr plumbing.
// - put the 0x72/0x74 relic handler in the cold non-0x201 arm; this moved the
//   main path into the binary's fall-through layout and substantially improved
//   ordered calls.
// - repeated unitAI() calls and direct managed-array reads were restored where
//   the original reloads them; the observed scalar/XYZ canPath overload slots
//   required the named overload declarations in the compiler's slot order.
// - kept the entry object in attackPoint.x, separate from the later targetObj;
//   this matches the packet's stack alias and object ownership flow.
// - replaced boolean civilian/explorer searches with the binary-supported
//   generic/difficulty join structure; the remaining drift is not behavioral.
// - corrected MD member ownership: diplomacyAI is at +0x9DC and
//   informationAI at +0xCEC.  TacticalAIGroup Waypoint fields are 16-byte
//   Waypoints (not 12-byte XYZPoints), restoring players/workingArea and
//   aiPlayer offsets (+0xD28/+0xD48/+0x1256C).
// - best current reconstruction: 4331 rebuilt bytes vs 4235, 77.66% shape,
//   29.67% exact-block coverage, 97.48% ordered-call similarity, frame 0x20
//   vs 0x30.  One __ftol site and three call-site gaps remain; no exact match.
// - managed-array growth loops written as bounded for loops moved the clean
//   source to 4281 bytes, 83.13% shape, and 43.85% exact-block coverage.
// - 22 evidence-led probes covered call-arm structure, array ownership,
//   parameter homes, block placement, and header context. Most were neutral.
// - BINARY NOTE: the original has one extra far-victim coordinate __ftol call
//   before the common coop-attack call. A volatile diagnostic reproduced the
//   119-call surface, but it also changed cleanup and is not retained.
// - remaining structural facts: the original frame is 0x30, its civilian
//   explorer/difficulty blocks are cold at the tail, and the clean source is
//   46 bytes longer with one missing __ftol call.
// - the named callerID alias is part of the best codegen basin; direct
//   parameter spelling tested separately but produced a weaker frontier.
// - duplicated near/far coop-coordinate call blocks were tested from the
//   original line bands.  A full duplicate added three ftol calls; a direct
//   near victory call was folded back to the same missing-ftol result.  The
//   common post-branch call is restored.
// - reusing param_2 as the caller-object home was codegen-neutral and was
//   rejected as opaque source; retain the named callerObject ownership.
// MANAGEDARRAY AUDIT: restored playersToAttack[0] for the index-zero capacity
// check and removed the fake resize(index) method. This emits identical code.
// Growth guards, copies, publication, and field offsets now follow the shared
// template contract.
// BLOCKER: The rebuild frame is 0x1C versus 0x30, is 46 bytes long, and misses
// one far-victim _ftol site. Ordered call gaps and broad CFG drift also remain.

#include <math.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

void* operator_new(unsigned int size);
void operator_delete(void* p);
extern "C" ulong __cdecl debug_timeGetTime(char* file, int line);

struct XYZPoint { int x; int y; int z; };
struct XYPoint { int x; int y; };
struct Waypoint { int x; int y; int z; int unk; };
struct XYZBYTEPoint;
struct Path;
struct RGE_Armor_Weapon_Info;
struct RGE_Action_Object;
struct RGE_Master_Static_Object;
struct RGE_Object_List;
struct RGE_Active_Sprite_List;
struct RGE_Sprite;
struct RGE_Color_Table;
struct TDrawArea;
struct LOSTBL;
struct RGE_Check_List;
struct InfluenceMap;
struct RGE_Tile;
struct RGE_Object_Node;
struct RGE_Master_Player;
struct RGE_Victory_Conditions;
struct RGE_Visible_Map;
struct RGE_Doppleganger_Creator;
struct RGE_Color_Table;
struct Visible_Resource_Manager;
struct RGE_Tile_List;
struct RGE_Sound;
struct TSound_Driver;
struct TCommunications_Handler;
struct RGE_Player_Info;
struct RGE_Scenario;
struct RGE_Game_World;
class UnitAIModule;
class RGE_Static_Object;
class TribeTacticalAIModule;
class TribeMainDecisionAIModule;

// The period utility is an inline managed array.  Its growth path is part of
// the original notify code, rather than a compiler/runtime collection helper.
template <class T>
class ManagedArray {
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
                     i < this->maximumSizeValue && i < new_size; i++)
                    new_value[i] = this->value[i];
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

};

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int data4;
    int data5;
};

class UnitAIModule {
public:
    int currentOrder();
    int currentAction();
    int currentTarget();
    int currentOrderPriority();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int value);
    virtual int isAlly(int value);
    virtual int isNeutral(int value);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int value, int stance);
    virtual void loadAIInformation(char* ai1, char* ai2, char* ai3, int value1, int value2);
    virtual void sendUnitAIOrder(int p1, int p2, int p3, int p4, int p5,
                                 float p6, float p7, float p8, float p9,
                                 int p10, int p11, int p12);
    virtual void processAIOrder(int p1, int p2, int p3, int p4, int p5,
                                float p6, float p7, float p8, float p9,
                                int p10, int p11, int p12);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(RGE_Static_Object* p1, RGE_Static_Object* p2, float p3, float p4);
    virtual void sendAddWaypointCommand(int p1, XYZBYTEPoint* p2, int p3);
    virtual void processAddWaypointCommand(int p1, XYZBYTEPoint* p2, int p3);
    virtual void sendPlayCommand(int p1, int* p2, int p3, int p4, int p5);
    virtual void sendPlayCommand(int p1, int p2, int p3);
    virtual int sendAICommand(int p1, int p2, int p3, int p4, int p5);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int p1, int p2, int p3);
    virtual RGE_Static_Object* make_scenario_obj(float p1, float p2, float p3, short p4, uchar p5, float p6);
    virtual void scenario_save(int file);
    virtual void scenario_load(int file, long* value, float version);
    virtual void scenario_postsave(int file);
    virtual void scenario_postload(int file, long* value, float version);
    virtual void load(int file);
    virtual void add_attribute_num(short value, float amount, uchar flags);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int file);
    virtual void save2(int file);
    virtual void save_info(int file);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long value, float p2, float p3, float p4, int p5);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int value, int* p2, int* p3);
    virtual uchar command_make_move(RGE_Static_Object* object, float x, float y);
    virtual uchar command_make_work(RGE_Static_Object* object, float x, float y);
    virtual uchar command_make_do(RGE_Static_Object* object, float x, float y);
    virtual uchar command_stop();
    virtual uchar command_place_object(short value, float x, float y, float z);
    virtual uchar command_add_attribute(int value, float amount);
    virtual uchar command_give_attribute(int p1, int p2, float p3);
    virtual uchar command_formation(int value);
    virtual uchar command_stand_ground();
    virtual uchar command_create_group(int p1, int* p2, int p3, float p4);
    virtual uchar command_add_to_group(int p1, int p2, float p3);
    virtual uchar command_remove_from_group(int p1, int p2);
    virtual uchar command_destroy_group(int p1);
    virtual uchar command_resign(int p1, int p2);
    virtual uchar command_add_waypoint(float p1, float p2, float p3);
    virtual RGE_Object_Node* addObject(RGE_Static_Object* p1, int p2, int p3);
    virtual void removeObject(RGE_Static_Object* p1, int p2, int p3, RGE_Object_Node* p4);
    virtual void logMessage(char* p1);
    virtual void notify(int p1, int p2, int p3, long p4, long p5, long p6);
    virtual void logStatus(void* p1, int p2);
    virtual void load_victory(int p1, long* p2, uchar p3);
    virtual void new_victory();

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    uchar checksum_created_this_update;
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;
    void* doppleganger_creator;
    char* name;
    uchar type;
    short id;

    int computerPlayer();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    ulong world_time;
    ulong old_world_time;
    ulong world_time_delta;
    float timer;
    ulong old_time;
    float game_speed;
    uchar temp_pause;
    uchar game_state;
    uchar game_end_condition;
    uchar gap_1F;
    char gap_20[0x20];
    RGE_Player** players;

    RGE_Static_Object* object(int id);
    int difficultyLevel();
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
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
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object* = 0);
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
    RGE_Tile* tile;
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
    RGE_Object_Node* player_object_node;
    ManagedArray<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    uchar inObstructionMapValue;
    uchar lastInObstructionMapValue;
    uchar underAttackValue;

    UnitAIModule* unitAI();
    float distance_to_object(RGE_Static_Object* object);
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
    uchar gap_1D6[2];
    Waypoint attackWaypoints[15];
    uchar consecutiveGatherAttemptsValue;
    uchar gap_2C9[3];
    int numberObjectsToDestroyValue;
    int objectsToDestroyValue[20];
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;
    ulong lastAttackRoundupTime;
    ulong lastAddedUnitTimeValue;

    int commander();
    void setTarget(int value);
    void setTargetType(int value);
    void setTargetLocation(float x, float y, float z);
    void setAction(int value);
    int task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int);
};

class ObjectMemory {
public:
    int id;
};

class TribeInformationAIModule {
public:
    ObjectMemory* artifactToCapture(int player);
    ObjectMemory* ruinToCapture(int player);
    int isBoat(RGE_Static_Object* object);
    void storeAttackMemory(uchar kind, uchar y, uchar x, uchar owner,
                           uchar player, short value, uchar value2,
                           ulong time, int object);
};

class DiplomacyAIModule {
public:
    void changeStance(int player, int stance, int amount);
    void setStance(int player, int stance, int amount);
    void setChangeable(int player, uchar value);
    void setRelation(int player, int relation);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int, int);
};

class TacticalAIModule {
public:
    char gap_00[0xF0];
};

struct PlacementState { char bytes[0x130]; };
struct ResourceItem { char bytes[0x70]; };
struct AttackState { char bytes[0x2C]; };

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
    UnitData gatherers[50];
    int numberGatherersValue;
    int desiredNumberGatherersValue;
    TacticalAIGroup groups;
    int groupIDValue;
    int numberGroupsValue;
    ulong lastGroupAttackTime;
    ulong lastGroupRebalanceTime;
    ulong lastAttackResponseTime;
    ulong lastBoatAttackResponseTime;
    ulong lastScalingUpdateValue;
    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;
    ManagedArray<int> playersToAttack;
    ManagedArray<int> playersToDefend;
    ManagedArray<int> workingArea;
    ManagedArray<int> unitsTaskedThisUpdate;
    int actualGathererDistribution[4];
    int desiredGathererDistribution[4];
    int neededResourceValue[4];
    int resourceDifferenceValue[4];
    ResourceItem neededResources;
    int attackEnabledValue;
    int updateArea;
    int firstNeededResourceUpdateDone;
    int numberStoragePitsBuilt[4];
    int numberGranariesBuilt[4];
    int wonderInProgressValue;
    int wonderBuiltValue;
    PlacementState placementStateValue;
    int nextCivilianToTaskValue;
    int nextIdleSoldierGroupToTaskValue;
    int nextActiveSoldierGroupToTaskValue;
    int builtFirstStoragePit;
    int builtFirstGranary;
    ulong lastBuildTime;
    ulong lastAttackResponseBuildInsertionTime;
    ulong lastCoopTributeDemandTime;
    ulong lastCoopTributeGiftTime;
    ulong lastCoopAttackDemandTime;
    int zoomingToNextAge;
    ulong lastUngroupedSoldierTaskTime;
    AttackState attackStateValue;
    int hitsByPlayer[9];
    int lastUpdateAreaTimeValue;
    int averageUpdateAreaTimeValue;
    int updateAreaAverageCount;
    int updateAreaAverageTotal;

    int numberSoldiersWithPriority(int priority, int player, int reset);
    int numberWarshipsWithPriority(int priority, int player);
    ulong attackLimiterTime(int value);
    int checkForAttackResponseBuildInsertions(int player);
    void enableAttack(int value);
    TacticalAIGroup* readyAndIdleGroup(int type, int priority, XYPoint* point);
    int checkForCoopAttack(int player, int x, int y);
    int calculatePriority(float distance);
    int taskDefender(int unit, int target, float distance, int priority);
    int taskAttacker(int unit, float x, float y, int target, int owner,
                     void* waypoint, int p7, int p8, int p9);
    int removeFromGroup(int unit);
    int dealWithGAIAAttacker(RGE_Static_Object* target, RGE_Static_Object* caller);

    void notify(int caller, int recipient, int message, long p1, long p2, long p3);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    RGE_Player* player;
    char gap_F4_9DC[0x9DC - 0xF4];
    DiplomacyAIModule diplomacyAI;
    char gap_9DD_CEC[0xCEC - 0x9DD];
    TribeInformationAIModule informationAI;
    char gap_CED_1146C[0x1146C - 0xCED];
    TribeTacticalAIModule tacticalAI;
    char gap_12478_1256C[0x1256C - 0x12478];
    RGE_Player* aiPlayer;

    void revokeTributeAlliance();
};

void TribeTacticalAIModule::notify(int param_1, int param_2, int param_3,
                                   long param_4, long param_5, long param_6)
{
    int callerID = param_1;
    int numberToRespond;
    RGE_Static_Object* targetObj;
    ulong entryTime;
    RGE_Static_Object* callerObject;
    XYPoint attackPoint;
    XYZPoint point;
    XYZPoint point_fffffff0;
    attackPoint.x = (int)this->md->aiPlayer->world->object(callerID);
    if (param_3 != 0x72 && param_3 != 0x74 && attackPoint.x == 0) {
        return;
    }

    entryTime = debug_timeGetTime((char*)0x5880C0, 0x1904);

    if (param_3 != 0x72 && param_3 != 0x74) {
        if (param_3 != 0x201) return;
    }
    else {
        ObjectMemory* memory;
        int i;
        int count;

        if (param_3 == 0x72) {
            memory = this->md->informationAI.artifactToCapture(-1);
        }
        else {
            memory = this->md->informationAI.ruinToCapture(-1);
        }
        if (memory == 0) {
            return;
        }

        numberToRespond = this->numberSoldiersWithPriority(100, -1, 1);
        if (numberToRespond > 3) numberToRespond = 3;
        count = 0;
        i = 0;
        if (this->workingArea.numberValue < 1) return;
        do {
            if (numberToRespond <= count) return;
            RGE_Static_Object* object = this->md->aiPlayer->world->object(this->workingArea[i]);
            if (object != 0 && object->unitAI() != 0 &&
                object->canPath(memory->id, 2.0f, 0, 1, -1, -1) != 0) {
                if (this->taskDefender(this->workingArea[i], memory->id, 2.0f, 100) == 1) {
                    this->removeFromGroup(this->workingArea[i]);
                    count = count + 1;
                }
            }
            i = i + 1;
            if (this->workingArea.numberValue <= i) return;
        } while (1);
    }

    targetObj = this->md->aiPlayer->world->object(param_4);
    if (targetObj == 0) return;
    if (targetObj->owner->id == this->md->player->id) return;

    callerObject = this->md->aiPlayer->world->object(param_1);
    if (callerObject == 0) return;

    if (targetObj->owner->id == 0 &&
        (this->zoomingToNextAge == 0 ||
         (targetObj->master_obj->id != 0x7E && targetObj->master_obj->id != 0x59)) &&
        this->dealWithGAIAAttacker(targetObj, callerObject) == 1) {
        return;
    }

    if (targetObj->owner->id != 0) {
        int i = 0;
        int explorerCount;
        int difficulty;
        if (0 < this->civilians.numberValue) {
            do {
                if (this->civilians.maximumSizeValue <= i) break;
                if (this->civilians.value[i] == callerID) {
                    explorerCount = this->civilianExplorers.numberValue;
                    i = 0;
                    if (explorerCount < 1) goto notify_difficulty;
                    goto notify_explorer_scan;
                }
                i = i + 1;
            } while (i < this->civilians.numberValue);
        }
        goto notify_generic_unit;

notify_generic_unit:
        if (callerObject->unitAI() != 0 && callerObject->unitAI()->currentOrder() != 0x2C1) {
            difficulty = this->md->player->world->difficultyLevel();
            if (difficulty == 3) {
                this->sn[0x68] -= 2;
            }
            else {
                difficulty = this->md->player->world->difficultyLevel();
                if (difficulty == 4) this->sn[0x68] -= 1;
                else this->enableAttack(3);
            }
        }
        goto notify_after_owner;

notify_explorer_scan:
        do {
            if (this->civilianExplorers.maximumSizeValue <= i) break;
            if (this->civilianExplorers.value[i] == callerID)
                goto notify_generic_unit;
            i = i + 1;
        } while (i < explorerCount);
        goto notify_difficulty;

notify_difficulty:
        difficulty = this->md->player->world->difficultyLevel();
        if (difficulty == 3) {
            this->sn[0x68] -= 2;
        }
        else {
            difficulty = this->md->player->world->difficultyLevel();
            if (difficulty == 4) this->sn[0x68] -= 1;
            else this->enableAttack(3);
        }
    }

notify_after_owner:
    this->checkForAttackResponseBuildInsertions(targetObj->owner->id);
    this->hitsByPlayer[targetObj->owner->id]++;

    if (targetObj->owner->computerPlayer() == 0) {
        if (this->md->player->isAlly(targetObj->owner->id) == 1 &&
            this->sn[0xDD] <= this->hitsByPlayer[targetObj->owner->id] &&
            this->sn[0xD7] == 1) {
            this->md->diplomacyAI.setChangeable(targetObj->owner->id, 1);
            this->md->diplomacyAI.setStance(targetObj->owner->id, 0, 100);
            this->md->diplomacyAI.setRelation(targetObj->owner->id, 3);
            this->md->diplomacyAI.setChangeable(targetObj->owner->id, 0);
        }
        else {
            this->md->diplomacyAI.changeStance(targetObj->owner->id, 2, this->sn[0xB2]);
            this->md->diplomacyAI.changeStance(targetObj->owner->id, 0, this->sn[0xB2]);
        }
    }
    else if (this->md->player->isAlly(targetObj->owner->id) == 1 &&
             this->md->player->world->players[targetObj->owner->id]->isEnemy(this->md->player->id) == 1) {
        this->md->diplomacyAI.setChangeable(targetObj->owner->id, 1);
        this->md->diplomacyAI.setStance(targetObj->owner->id, 0, 100);
        this->md->diplomacyAI.setRelation(targetObj->owner->id, 3);
        this->md->diplomacyAI.setChangeable(targetObj->owner->id, 0);
    }

    if (0 < this->sn[0x7C] && this->sn[0x80] == targetObj->owner->id && this->sn[0x85] == 1) {
        this->md->revokeTributeAlliance();
    }

    this->md->informationAI.storeAttackMemory(
        0,
        (uchar)targetObj->world_y,
        (uchar)targetObj->world_x,
        (uchar)targetObj->owner->id,
        (uchar)this->md->player->id,
        0,
        0,
        this->md->player->world->world_time,
        -1);

    if (this->lastAttackResponseTime != 0 &&
        (this->md->player->world->world_time - this->lastAttackResponseTime) / 1000 <
            this->attackLimiterTime(0x30)) {
        return;
    }

    attackPoint.x = (int)targetObj->world_x;
    attackPoint.y = (int)targetObj->world_y;

    TacticalAIGroup* group;
    if (this->md->informationAI.isBoat(targetObj) == 1) {
        group = this->readyAndIdleGroup(0x67, this->sn[0x14], &attackPoint);
    }
    else {
        group = this->readyAndIdleGroup(100, this->sn[0x14], &attackPoint);
        if (group == 0) {
            group = this->readyAndIdleGroup(0x67, this->sn[0x14], &attackPoint);
        }
    }

    if (group != 0) {
        RGE_Static_Object* commanderObject =
            this->md->aiPlayer->world->object(group->commander());
        if (commanderObject != 0) {
            point.x = (int)targetObj->world_x;
            point.y = (int)targetObj->world_y;
            point.z = (int)targetObj->world_z;
            if (commanderObject->canPath(
                    point, commanderObject->weaponRange(), targetObj->id, 0, 1, -1, -1) == 1) {
                group->setTarget(callerObject->id);
                group->setTargetType(targetObj->master_obj->id);
                group->setTargetLocation(targetObj->world_x, targetObj->world_y, targetObj->world_z);
                group->setAction(2);
                group->task(this, this->md, 2, 1, 0);
                this->lastAttackResponseTime = this->md->player->world->world_time;
                if (this->sn[0x47] != 1) return;
                this->lastGroupAttackTime = this->md->player->world->world_time;
                return;
            }
        }
    }

    RGE_Static_Object* victoryObject = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    int responseDistance = 1000;
    int coopX;
    int coopY;
    if (victoryObject != 0) {
        float dx = victoryObject->world_x - targetObj->world_x;
        float dy = victoryObject->world_y - targetObj->world_y;
        responseDistance = (int)sqrt(dx * dx + dy * dy);
    }

    if (responseDistance < 0x14) {
        int warships = this->numberWarshipsWithPriority(100, -1);
        int soldiers = this->numberSoldiersWithPriority(100, -1, 0);
        numberToRespond = warships + soldiers;
        if (numberToRespond == 0 && this->md->informationAI.isBoat(targetObj) == 0 &&
            this->sn[0xE1] == 1 &&
            this->md->player->world->world_time / 1000 < (ulong)this->sn[0x68]) {
            int i = 0;
            if (0 < this->civilians.numberValue) {
                do {
                    int civilian = this->civilians[i];
                    int j = 0;
                    int found = 0;
                    if (0 < this->workingArea.numberValue) {
                        do {
                            if (this->workingArea.maximumSizeValue <= j) break;
                            if (this->workingArea.value[j] == civilian) {
                                found = 1;
                                break;
                            }
                            j = j + 1;
                        } while (j < this->workingArea.numberValue);
                    }
                    if (found == 0) {
                        this->workingArea[this->workingArea.numberValue] = civilian;
                        this->workingArea.numberValue++;
                    }
                    i = i + 1;
                } while (i < this->civilians.numberValue);
            }
            numberToRespond = this->civilians.numberValue;
        }
        coopY = (int)victoryObject->world_y;
        coopX = (int)victoryObject->world_x;
    }
    else {
        int available;
        if (this->md->informationAI.isBoat(targetObj) == 1) {
            available = this->numberWarshipsWithPriority(this->sn[0x14], -1);
        }
        else {
            available = this->numberWarshipsWithPriority(this->sn[0x14], -1);
            available += this->numberSoldiersWithPriority(this->sn[0x14], -1, 0);
        }
        numberToRespond = (this->sn[0x13] * available) / 100;
        if (victoryObject != 0) {
            coopY = (int)victoryObject->world_y;
            coopX = (int)victoryObject->world_x;
        }
        else {
            coopY = (int)targetObj->world_y;
            coopX = (int)targetObj->world_x;
        }
    }
    this->checkForCoopAttack(targetObj->owner->id, coopX, coopY);

    param_2 = 0;
    param_3 = 0;
    if (0 < this->workingArea.numberValue) {
        while (param_2 < numberToRespond &&
               (param_3 < 2 ||
                debug_timeGetTime((char*)0x5880C0, 0x1A54) - entryTime < 0xB)) {
            RGE_Static_Object* unitObject =
                this->md->aiPlayer->world->object(this->workingArea[param_3]);
            if (unitObject != 0 && unitObject->unitAI() != 0) {
                int action = unitObject->unitAI()->currentAction();
                if (action == 600) {
                    int currentTarget = unitObject->unitAI()->currentTarget();
                    if (currentTarget != -1) {
                        currentTarget = unitObject->unitAI()->currentTarget();
                        if (currentTarget != targetObj->id) {
                            currentTarget = unitObject->unitAI()->currentTarget();
                            RGE_Static_Object* oldTarget =
                                this->md->aiPlayer->world->object(currentTarget);
                            if (oldTarget != 0) {
                                if (this->playersToAttack.maximumSizeValue < 1) {
                                    this->playersToAttack[0];
                                }
                                if (oldTarget->owner->id == this->playersToAttack.value[0]) {
                                    param_2++;
                                    goto notify_next_unit;
                                }
                            }
                        }
                    }
                    goto notify_try_attack;
                }
notify_try_attack:
                if (this->workingArea[param_3] == callerID) {
                    if (unitObject->unitAI()->currentOrderPriority() != 100) {
                        point_fffffff0.x = (int)targetObj->world_x;
                        point_fffffff0.y = (int)targetObj->world_y;
                        point_fffffff0.z = (int)targetObj->world_z;
                        if (unitObject->canPath(
                                point_fffffff0, unitObject->weaponRange(), targetObj->id,
                                0, 1, -1, -1) != 0) {
                            if (this->taskAttacker(this->workingArea[param_3],
                                                   targetObj->world_x, targetObj->world_y,
                                                   targetObj->id, targetObj->owner->id,
                                                   0, 0, -1, 0) == 1) {
                                this->lastAttackResponseTime = this->md->player->world->world_time;
                                if (this->sn[0x47] == 1) {
                                    this->lastGroupAttackTime = this->md->player->world->world_time;
                                }
                                param_2++;
                            }
                        }
                    }
                }
                else {
                    float distance = targetObj->distance_to_object(unitObject);
                    int priority = this->calculatePriority(distance);
                    if (distance < (float)this->sn[0x14]) {
                        int currentPriority = unitObject->unitAI()->currentOrderPriority();
                        if (currentPriority < priority && 0 < priority) {
                            point_fffffff0.x = (int)targetObj->world_x;
                            point_fffffff0.y = (int)targetObj->world_y;
                            point_fffffff0.z = (int)targetObj->world_z;
                            if (unitObject->canPath(
                                    point_fffffff0, unitObject->weaponRange(), targetObj->id,
                                    0, 1, -1, -1) != 0) {
                                if (this->taskAttacker(this->workingArea[param_3],
                                                       targetObj->world_x, targetObj->world_y,
                                                       targetObj->id, targetObj->owner->id,
                                                       0, 0, -1, 0) == 1) {
                                    param_2++;
                                }
                            }
                        }
                    }
                }
            }
notify_next_unit:
            param_3++;
        }
    }
}
